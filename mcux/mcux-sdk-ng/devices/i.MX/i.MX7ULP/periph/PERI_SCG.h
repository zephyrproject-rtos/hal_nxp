/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SCG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SCG.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SCG
 *
 * CMSIS Peripheral Access Layer for SCG
 */

#if !defined(PERI_SCG_H_)
#define PERI_SCG_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
   -- SCG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCG_Peripheral_Access_Layer SCG Peripheral Access Layer
 * @{
 */

/** SCG - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __I  uint32_t CSR;                               /**< Clock Status Register, offset: 0x10 */
  __IO uint32_t RCCR;                              /**< Run Clock Control Register, offset: 0x14 */
  __IO uint32_t VCCR;                              /**< VLPR Clock Control Register, offset: 0x18 */
  __IO uint32_t HCCR;                              /**< HSRUN Clock Control Register, offset: 0x1C */
  __IO uint32_t CLKOUTCNFG;                        /**< SCG CLKOUT Configuration Register, offset: 0x20 */
       uint8_t RESERVED_1[12];
  __IO uint32_t DDRCCR;                            /**< DDR Clock Control Register, offset: 0x30, available only on: SCG1 (missing on SCG0) */
       uint8_t RESERVED_2[12];
  __IO uint32_t NICCCR;                            /**< NIC Clock Control Register, offset: 0x40, available only on: SCG1 (missing on SCG0) */
  __I  uint32_t NICCSR;                            /**< NIC Clock Status Register, offset: 0x44, available only on: SCG1 (missing on SCG0) */
       uint8_t RESERVED_3[184];
  __IO uint32_t SOSCCSR;                           /**< System OSC Control Status Register, offset: 0x100 */
  __IO uint32_t SOSCDIV;                           /**< System OSC Divide Register, offset: 0x104 */
  __IO uint32_t SOSCCFG;                           /**< System Oscillator Configuration Register, offset: 0x108, available only on: SCG0 (missing on SCG1) */
       uint8_t RESERVED_4[244];
  __IO uint32_t SIRCCSR;                           /**< Slow IRC Control Status Register, offset: 0x200 */
  __IO uint32_t SIRCDIV;                           /**< Slow IRC Divide Register, offset: 0x204 */
  __IO uint32_t SIRCCFG;                           /**< Slow IRC Configuration Register, offset: 0x208, available only on: SCG0 (missing on SCG1) */
       uint8_t RESERVED_5[244];
  __IO uint32_t FIRCCSR;                           /**< Fast IRC Control Status Register, offset: 0x300 */
  __IO uint32_t FIRCDIV;                           /**< Fast IRC Divide Register, offset: 0x304 */
  __IO uint32_t FIRCCFG;                           /**< Fast IRC Configuration Register, offset: 0x308, available only on: SCG0 (missing on SCG1) */
  __IO uint32_t FIRCTCFG;                          /**< Fast IRC Trim Configuration Register, offset: 0x30C, available only on: SCG0 (missing on SCG1) */
       uint8_t RESERVED_6[8];
  __IO uint32_t FIRCSTAT;                          /**< Fast IRC Status Register, offset: 0x318, available only on: SCG0 (missing on SCG1) */
       uint8_t RESERVED_7[228];
  __IO uint32_t ROSCCSR;                           /**< RTC OSC Control Status Register, offset: 0x400, available only on: SCG0 (missing on SCG1) */
       uint8_t RESERVED_8[252];
  __IO uint32_t APLLCSR;                           /**< Auxiliary PLL Control Status Register, offset: 0x500 */
  __IO uint32_t APLLDIV;                           /**< Auxiliary PLL Divide Register, offset: 0x504 */
  __IO uint32_t APLLCFG;                           /**< Auxiliary PLL Configuration Register, offset: 0x508 */
  __IO uint32_t APLLPFD;                           /**< Auxiliary PLL PFD Register, offset: 0x50C */
  __IO uint32_t APLLNUM;                           /**< Auxiliary PLL Numerator Register, offset: 0x510 */
  __IO uint32_t APLLDENOM;                         /**< Auxiliary PLL Denominator Register, offset: 0x514 */
  __IO uint32_t APLLSS;                            /**< Auxiliary PLL Spread Spectrum Register, offset: 0x518 */
       uint8_t RESERVED_9[220];
  __IO uint32_t APLLLOCK_CNFG;                     /**< Auxiliary PLL LOCK Configuration Register, offset: 0x5F8 */
       uint8_t RESERVED_10[4];
  __IO uint32_t SPLLCSR;                           /**< System PLL Control Status Register, offset: 0x600 */
  __IO uint32_t SPLLDIV;                           /**< System PLL Divide Register, offset: 0x604 */
  __IO uint32_t SPLLCFG;                           /**< System PLL Configuration Register, offset: 0x608 */
  __IO uint32_t SPLLPFD;                           /**< System PLL PFD Register, offset: 0x60C */
  __IO uint32_t SPLLNUM;                           /**< System PLL Numerator Register, offset: 0x610, available only on: SCG1 (missing on SCG0) */
  __IO uint32_t SPLLDENOM;                         /**< System PLL Denominator Register, offset: 0x614, available only on: SCG1 (missing on SCG0) */
  __IO uint32_t SPLLSS;                            /**< System PLL Spread Spectrum Register, offset: 0x618, available only on: SCG1 (missing on SCG0) */
       uint8_t RESERVED_11[220];
  __IO uint32_t SPLLLOCK_CNFG;                     /**< System PLL LOCK Configuration Register, offset: 0x6F8 */
} SCG_Type;

/* ----------------------------------------------------------------------------
   -- SCG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SCG_Register_Masks SCG Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define SCG_VERID_VERSION_MASK                   (0xFFFFFFFFU)
#define SCG_VERID_VERSION_SHIFT                  (0U)
/*! VERSION - SCG Version Number */
#define SCG_VERID_VERSION(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_VERID_VERSION_SHIFT)) & SCG_VERID_VERSION_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define SCG_PARAM_CLKPRES_MASK                   (0xFFU)
#define SCG_PARAM_CLKPRES_SHIFT                  (0U)
/*! CLKPRES - Clock Present
 *  0b00000000-0b00000001..Reserved
 *  0bx1xxxxxx..System PLL (SPLL) is present.
 *  0bxx1xxxxx..Auxiliary PLL (APLL) is present.
 *  0bxxx1xxxx..RTC OSC (ROSC) is present.
 *  0bxxxx1xxx..Fast IRC (FIRC) is present.
 *  0bxxxxx1xx..Slow IRC (SIRC) is present.
 *  0bxxxxxx1x..System OSC (SOSC) is present.
 */
#define SCG_PARAM_CLKPRES(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_CLKPRES_SHIFT)) & SCG_PARAM_CLKPRES_MASK)

#define SCG_PARAM_DIVPRES_MASK                   (0xF8000000U)
#define SCG_PARAM_DIVPRES_SHIFT                  (27U)
/*! DIVPRES - Divider Present
 *  0b1xxxx..System DIVCORE is present.
 *  0bx1xxx..System DIVPLAT is present.
 *  0bxxx1x..System DIVBUS is present.
 *  0bxxxx1..System DIVSLOW is present.
 */
#define SCG_PARAM_DIVPRES(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_DIVPRES_SHIFT)) & SCG_PARAM_DIVPRES_MASK)
/*! @} */

/*! @name CSR - Clock Status Register */
/*! @{ */

#define SCG_CSR_DIVSLOW_MASK                     (0xFU)
#define SCG_CSR_DIVSLOW_SHIFT                    (0U)
/*! DIVSLOW - Slow Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_CSR_DIVSLOW(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_CSR_DIVSLOW_SHIFT)) & SCG_CSR_DIVSLOW_MASK)

#define SCG_CSR_DIVBUS_MASK                      (0xF0U)
#define SCG_CSR_DIVBUS_SHIFT                     (4U)
/*! DIVBUS - Bus Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_CSR_DIVBUS(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_CSR_DIVBUS_SHIFT)) & SCG_CSR_DIVBUS_MASK)

#define SCG_CSR_DIVPLAT_MASK                     (0xF000U)
#define SCG_CSR_DIVPLAT_SHIFT                    (12U)
/*! DIVPLAT - Platform Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Reserved
 *  0b0010..Reserved
 *  0b0011..Reserved
 *  0b0100..Reserved
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define SCG_CSR_DIVPLAT(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_CSR_DIVPLAT_SHIFT)) & SCG_CSR_DIVPLAT_MASK)

#define SCG_CSR_DIVCORE_MASK                     (0xF0000U)
#define SCG_CSR_DIVCORE_SHIFT                    (16U)
/*! DIVCORE - Core Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_CSR_DIVCORE(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_CSR_DIVCORE_SHIFT)) & SCG_CSR_DIVCORE_MASK)

#define SCG_CSR_SCS_MASK                         (0xF000000U)
#define SCG_CSR_SCS_SHIFT                        (24U)
/*! SCS - System Clock Source
 *  0b0000..Reserved
 *  0b0001..System OSC (SOSC_CLK)
 *  0b0010..Slow IRC (SIRC_CLK)
 *  0b0011..Fast IRC (FIRC_CLK)
 *  0b0100..RTC OSC (ROSC_CLK)
 *  0b0101..Auxiliary PLL (APLL_CLK)
 *  0b0110..System PLL (SPLL_CLK)
 *  0b0111..Reserved
 */
#define SCG_CSR_SCS(x)                           (((uint32_t)(((uint32_t)(x)) << SCG_CSR_SCS_SHIFT)) & SCG_CSR_SCS_MASK)
/*! @} */

/*! @name RCCR - Run Clock Control Register */
/*! @{ */

#define SCG_RCCR_DIVSLOW_MASK                    (0xFU)
#define SCG_RCCR_DIVSLOW_SHIFT                   (0U)
/*! DIVSLOW - Slow Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_RCCR_DIVSLOW(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_DIVSLOW_SHIFT)) & SCG_RCCR_DIVSLOW_MASK)

#define SCG_RCCR_DIVBUS_MASK                     (0xF0U)
#define SCG_RCCR_DIVBUS_SHIFT                    (4U)
/*! DIVBUS - Bus Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_RCCR_DIVBUS(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_DIVBUS_SHIFT)) & SCG_RCCR_DIVBUS_MASK)

#define SCG_RCCR_DIVPLAT_MASK                    (0xF000U)
#define SCG_RCCR_DIVPLAT_SHIFT                   (12U)
/*! DIVPLAT - Platform Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Reserved
 *  0b0010..Reserved
 *  0b0011..Reserved
 *  0b0100..Reserved
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define SCG_RCCR_DIVPLAT(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_DIVPLAT_SHIFT)) & SCG_RCCR_DIVPLAT_MASK)

#define SCG_RCCR_DIVCORE_MASK                    (0xF0000U)
#define SCG_RCCR_DIVCORE_SHIFT                   (16U)
/*! DIVCORE - Core Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_RCCR_DIVCORE(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_DIVCORE_SHIFT)) & SCG_RCCR_DIVCORE_MASK)

#define SCG_RCCR_SCS_MASK                        (0x7000000U)
#define SCG_RCCR_SCS_SHIFT                       (24U)
/*! SCS - System Clock Source
 *  0b000..Reserved
 *  0b001..System OSC (SOSC_CLK)
 *  0b010..Slow IRC (SIRC_CLK)
 *  0b011..Fast IRC (FIRC_CLK)
 *  0b100..RTC OSC (ROSC_CLK)
 *  0b101..Auxiliary PLL (APLL_CLK)
 *  0b110..System PLL (SPLL_CLK)
 *  0b111..Reserved
 */
#define SCG_RCCR_SCS(x)                          (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_SCS_SHIFT)) & SCG_RCCR_SCS_MASK)
/*! @} */

/*! @name VCCR - VLPR Clock Control Register */
/*! @{ */

#define SCG_VCCR_DIVSLOW_MASK                    (0xFU)
#define SCG_VCCR_DIVSLOW_SHIFT                   (0U)
/*! DIVSLOW - Slow Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_VCCR_DIVSLOW(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_VCCR_DIVSLOW_SHIFT)) & SCG_VCCR_DIVSLOW_MASK)

#define SCG_VCCR_DIVBUS_MASK                     (0xF0U)
#define SCG_VCCR_DIVBUS_SHIFT                    (4U)
/*! DIVBUS - Bus Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_VCCR_DIVBUS(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_VCCR_DIVBUS_SHIFT)) & SCG_VCCR_DIVBUS_MASK)

#define SCG_VCCR_DIVPLAT_MASK                    (0xF000U)
#define SCG_VCCR_DIVPLAT_SHIFT                   (12U)
/*! DIVPLAT - Platform Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Reserved
 *  0b0010..Reserved
 *  0b0011..Reserved
 *  0b0100..Reserved
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define SCG_VCCR_DIVPLAT(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_VCCR_DIVPLAT_SHIFT)) & SCG_VCCR_DIVPLAT_MASK)

#define SCG_VCCR_DIVCORE_MASK                    (0xF0000U)
#define SCG_VCCR_DIVCORE_SHIFT                   (16U)
/*! DIVCORE - Core Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_VCCR_DIVCORE(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_VCCR_DIVCORE_SHIFT)) & SCG_VCCR_DIVCORE_MASK)

#define SCG_VCCR_SCS_MASK                        (0xF000000U)
#define SCG_VCCR_SCS_SHIFT                       (24U)
/*! SCS - System Clock Source
 *  0b0000..Reserved
 *  0b0001..System OSC (SOSC_CLK)
 *  0b0010..Slow IRC (SIRC_CLK)
 *  0b0011..Fast IRC (FIRC_CLK)
 *  0b0100..RTC OSC (ROSC_CLK)
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..Reserved
 */
#define SCG_VCCR_SCS(x)                          (((uint32_t)(((uint32_t)(x)) << SCG_VCCR_SCS_SHIFT)) & SCG_VCCR_SCS_MASK)
/*! @} */

/*! @name HCCR - HSRUN Clock Control Register */
/*! @{ */

#define SCG_HCCR_DIVSLOW_MASK                    (0xFU)
#define SCG_HCCR_DIVSLOW_SHIFT                   (0U)
/*! DIVSLOW - Slow Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_HCCR_DIVSLOW(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_HCCR_DIVSLOW_SHIFT)) & SCG_HCCR_DIVSLOW_MASK)

#define SCG_HCCR_DIVBUS_MASK                     (0xF0U)
#define SCG_HCCR_DIVBUS_SHIFT                    (4U)
/*! DIVBUS - Bus Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_HCCR_DIVBUS(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_HCCR_DIVBUS_SHIFT)) & SCG_HCCR_DIVBUS_MASK)

#define SCG_HCCR_DIVPLAT_MASK                    (0xF000U)
#define SCG_HCCR_DIVPLAT_SHIFT                   (12U)
/*! DIVPLAT - Platform Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Reserved
 *  0b0010..Reserved
 *  0b0011..Reserved
 *  0b0100..Reserved
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1010..Reserved
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define SCG_HCCR_DIVPLAT(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_HCCR_DIVPLAT_SHIFT)) & SCG_HCCR_DIVPLAT_MASK)

#define SCG_HCCR_DIVCORE_MASK                    (0xF0000U)
#define SCG_HCCR_DIVCORE_SHIFT                   (16U)
/*! DIVCORE - Core Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_HCCR_DIVCORE(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_HCCR_DIVCORE_SHIFT)) & SCG_HCCR_DIVCORE_MASK)

#define SCG_HCCR_SCS_MASK                        (0xF000000U)
#define SCG_HCCR_SCS_SHIFT                       (24U)
/*! SCS - System Clock Source
 *  0b0000..Reserved
 *  0b0001..System OSC (SOSC_CLK)
 *  0b0010..Slow IRC (SIRC_CLK)
 *  0b0011..Fast IRC (FIRC_CLK)
 *  0b0100..RTC OSC (ROSC_CLK)
 *  0b0101..Auxiliary PLL (APLL_CLK)
 *  0b0110..System PLL (SPLL_CLK)
 *  0b0111..Reserved
 */
#define SCG_HCCR_SCS(x)                          (((uint32_t)(((uint32_t)(x)) << SCG_HCCR_SCS_SHIFT)) & SCG_HCCR_SCS_MASK)
/*! @} */

/*! @name CLKOUTCNFG - SCG CLKOUT Configuration Register */
/*! @{ */

#define SCG_CLKOUTCNFG_CLKOUTSEL_MASK            (0xF000000U)
#define SCG_CLKOUTCNFG_CLKOUTSEL_SHIFT           (24U)
/*! CLKOUTSEL - SCG Clkout Select
 *  0b0000..SCG SLOW Clock
 *  0b0001..System OSC (SOSC_CLK)
 *  0b0010..Slow IRC (SIRC_CLK)
 *  0b0011..Fast IRC (FIRC_CLK)
 *  0b0100..RTC OSC (ROSC_CLK)
 *  0b0101..Auxiliary PLL (APLL_CLK)
 *  0b0110..System PLL (SPLL_CLK)
 *  0b0111..Reserved
 *  0b1111..Reserved
 */
#define SCG_CLKOUTCNFG_CLKOUTSEL(x)              (((uint32_t)(((uint32_t)(x)) << SCG_CLKOUTCNFG_CLKOUTSEL_SHIFT)) & SCG_CLKOUTCNFG_CLKOUTSEL_MASK)
/*! @} */

/*! @name DDRCCR - DDR Clock Control Register */
/*! @{ */

#define SCG_DDRCCR_DDRDIV_MASK                   (0x7U)
#define SCG_DDRCCR_DDRDIV_SHIFT                  (0U)
/*! DDRDIV - DDR Divider
 *  0b000..Output disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_DDRCCR_DDRDIV(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_DDRCCR_DDRDIV_SHIFT)) & SCG_DDRCCR_DDRDIV_MASK)

#define SCG_DDRCCR_DDRCS_MASK                    (0x3000000U)
#define SCG_DDRCCR_DDRCS_SHIFT                   (24U)
/*! DDRCS - DDR Clock Source
 *  0b00..APLL PLLS Clock
 *  0b01..RESERVED. Software should write 0 to this bit to maintain compatibility.
 *  0b10..RESERVED
 *  0b11..RESERVED
 */
#define SCG_DDRCCR_DDRCS(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_DDRCCR_DDRCS_SHIFT)) & SCG_DDRCCR_DDRCS_MASK)
/*! @} */

/*! @name NICCCR - NIC Clock Control Register */
/*! @{ */

#define SCG_NICCCR_NIC1_DIVBUS_MASK              (0xF0U)
#define SCG_NICCCR_NIC1_DIVBUS_SHIFT             (4U)
/*! NIC1_DIVBUS - NIC1 Bus Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_NICCCR_NIC1_DIVBUS(x)                (((uint32_t)(((uint32_t)(x)) << SCG_NICCCR_NIC1_DIVBUS_SHIFT)) & SCG_NICCCR_NIC1_DIVBUS_MASK)

#define SCG_NICCCR_NIC1_DIVEXT_MASK              (0xF00U)
#define SCG_NICCCR_NIC1_DIVEXT_SHIFT             (8U)
/*! NIC1_DIVEXT - NIC1 External Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_NICCCR_NIC1_DIVEXT(x)                (((uint32_t)(((uint32_t)(x)) << SCG_NICCCR_NIC1_DIVEXT_SHIFT)) & SCG_NICCCR_NIC1_DIVEXT_MASK)

#define SCG_NICCCR_NIC1_DIV_MASK                 (0xF0000U)
#define SCG_NICCCR_NIC1_DIV_SHIFT                (16U)
/*! NIC1_DIV - NIC1 Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_NICCCR_NIC1_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_NICCCR_NIC1_DIV_SHIFT)) & SCG_NICCCR_NIC1_DIV_MASK)

#define SCG_NICCCR_GPU_DIV_MASK                  (0xF00000U)
#define SCG_NICCCR_GPU_DIV_SHIFT                 (20U)
/*! GPU_DIV - GPU Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_NICCCR_GPU_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_NICCCR_GPU_DIV_SHIFT)) & SCG_NICCCR_GPU_DIV_MASK)

#define SCG_NICCCR_NIC0_DIV_MASK                 (0xF000000U)
#define SCG_NICCCR_NIC0_DIV_SHIFT                (24U)
/*! NIC0_DIV - NIC0 Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_NICCCR_NIC0_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_NICCCR_NIC0_DIV_SHIFT)) & SCG_NICCCR_NIC0_DIV_MASK)

#define SCG_NICCCR_NICCS_MASK                    (0x30000000U)
#define SCG_NICCCR_NICCS_SHIFT                   (28U)
/*! NICCS - NIC Clock Source
 *  0b00..Fast IRC
 *  0b01..DDR Clock
 *  0b10..NIC External PLL
 *  0b11..RESERVED
 */
#define SCG_NICCCR_NICCS(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_NICCCR_NICCS_SHIFT)) & SCG_NICCCR_NICCS_MASK)
/*! @} */

/*! @name NICCSR - NIC Clock Status Register */
/*! @{ */

#define SCG_NICCSR_NIC1_DIVBUS_MASK              (0xF0U)
#define SCG_NICCSR_NIC1_DIVBUS_SHIFT             (4U)
/*! NIC1_DIVBUS - NIC1 Bus Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_NICCSR_NIC1_DIVBUS(x)                (((uint32_t)(((uint32_t)(x)) << SCG_NICCSR_NIC1_DIVBUS_SHIFT)) & SCG_NICCSR_NIC1_DIVBUS_MASK)

#define SCG_NICCSR_NIC1_DIVEXT_MASK              (0xF00U)
#define SCG_NICCSR_NIC1_DIVEXT_SHIFT             (8U)
/*! NIC1_DIVEXT - NIC1 External Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_NICCSR_NIC1_DIVEXT(x)                (((uint32_t)(((uint32_t)(x)) << SCG_NICCSR_NIC1_DIVEXT_SHIFT)) & SCG_NICCSR_NIC1_DIVEXT_MASK)

#define SCG_NICCSR_NIC1_DIV_MASK                 (0xF0000U)
#define SCG_NICCSR_NIC1_DIV_SHIFT                (16U)
/*! NIC1_DIV - NIC1 Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_NICCSR_NIC1_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_NICCSR_NIC1_DIV_SHIFT)) & SCG_NICCSR_NIC1_DIV_MASK)

#define SCG_NICCSR_GPU_DIV_MASK                  (0xF00000U)
#define SCG_NICCSR_GPU_DIV_SHIFT                 (20U)
/*! GPU_DIV - GPU Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_NICCSR_GPU_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_NICCSR_GPU_DIV_SHIFT)) & SCG_NICCSR_GPU_DIV_MASK)

#define SCG_NICCSR_NIC0_DIV_MASK                 (0xF000000U)
#define SCG_NICCSR_NIC0_DIV_SHIFT                (24U)
/*! NIC0_DIV - NIC0 Clock Divide Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_NICCSR_NIC0_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_NICCSR_NIC0_DIV_SHIFT)) & SCG_NICCSR_NIC0_DIV_MASK)

#define SCG_NICCSR_NICCS_MASK                    (0x30000000U)
#define SCG_NICCSR_NICCS_SHIFT                   (28U)
/*! NICCS - NIC Clock Source
 *  0b00..Fast IRC
 *  0b01..DDR Clock
 *  0b10..NIC External PLL
 *  0b11..Reserved
 */
#define SCG_NICCSR_NICCS(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_NICCSR_NICCS_SHIFT)) & SCG_NICCSR_NICCS_MASK)
/*! @} */

/*! @name SOSCCSR - System OSC Control Status Register */
/*! @{ */

#define SCG_SOSCCSR_SOSCEN_MASK                  (0x1U)
#define SCG_SOSCCSR_SOSCEN_SHIFT                 (0U)
/*! SOSCEN - System OSC Enable
 *  0b0..System OSC is disabled
 *  0b1..System OSC is enabled
 */
#define SCG_SOSCCSR_SOSCEN(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCEN_SHIFT)) & SCG_SOSCCSR_SOSCEN_MASK)

#define SCG_SOSCCSR_SOSCSTEN_MASK                (0x2U)
#define SCG_SOSCCSR_SOSCSTEN_SHIFT               (1U)
/*! SOSCSTEN - System OSC Stop Enable
 *  0b0..System OSC is disabled in Stop modes
 *  0b1..System OSC is enabled in Stop modes if SOSCEN=1. In VLLS0, system oscillator is disabled even if
 *       SOSCSTEN=1 and SOSCEN=1. When selected as the reference clock to the System PLL and if the System PLL is enabled
 *       in STOP mode, the SOSC will stay enabled even if SOSCSTEN=0.
 */
#define SCG_SOSCCSR_SOSCSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCSTEN_SHIFT)) & SCG_SOSCCSR_SOSCSTEN_MASK)

#define SCG_SOSCCSR_SOSCLPEN_MASK                (0x4U)
#define SCG_SOSCCSR_SOSCLPEN_SHIFT               (2U)
/*! SOSCLPEN - System OSC Low Power Enable
 *  0b0..System OSC is disabled in VLP modes
 *  0b1..System OSC is enabled in VLP modes
 */
#define SCG_SOSCCSR_SOSCLPEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCLPEN_SHIFT)) & SCG_SOSCCSR_SOSCLPEN_MASK)

#define SCG_SOSCCSR_SOSCCM_MASK                  (0x10000U)
#define SCG_SOSCCSR_SOSCCM_SHIFT                 (16U)
/*! SOSCCM - System OSC Clock Monitor Enable
 *  0b0..System OSC Clock Monitor is disabled
 *  0b1..System OSC Clock Monitor is enabled
 */
#define SCG_SOSCCSR_SOSCCM(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCCM_SHIFT)) & SCG_SOSCCSR_SOSCCM_MASK)

#define SCG_SOSCCSR_SOSCCMRE_MASK                (0x20000U)
#define SCG_SOSCCSR_SOSCCMRE_SHIFT               (17U)
/*! SOSCCMRE - System OSC Clock Monitor Reset Enable
 *  0b0..Clock Monitor generates interrupt when error detected
 *  0b1..Clock Monitor generates reset when error detected
 */
#define SCG_SOSCCSR_SOSCCMRE(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCCMRE_SHIFT)) & SCG_SOSCCSR_SOSCCMRE_MASK)

#define SCG_SOSCCSR_LK_MASK                      (0x800000U)
#define SCG_SOSCCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register
 *  0b0..This Control Status Register can be written.
 *  0b1..This Control Status Register cannot be written.
 */
#define SCG_SOSCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_LK_SHIFT)) & SCG_SOSCCSR_LK_MASK)

#define SCG_SOSCCSR_SOSCVLD_MASK                 (0x1000000U)
#define SCG_SOSCCSR_SOSCVLD_SHIFT                (24U)
/*! SOSCVLD - System OSC Valid
 *  0b0..System OSC is not enabled or clock is not valid
 *  0b1..System OSC is enabled and output clock is valid
 */
#define SCG_SOSCCSR_SOSCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCVLD_SHIFT)) & SCG_SOSCCSR_SOSCVLD_MASK)

#define SCG_SOSCCSR_SOSCSEL_MASK                 (0x2000000U)
#define SCG_SOSCCSR_SOSCSEL_SHIFT                (25U)
/*! SOSCSEL - System OSC Selected
 *  0b0..System OSC is not the system clock source
 *  0b1..System OSC is the system clock source
 */
#define SCG_SOSCCSR_SOSCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCSEL_SHIFT)) & SCG_SOSCCSR_SOSCSEL_MASK)

#define SCG_SOSCCSR_SOSCERR_MASK                 (0x4000000U)
#define SCG_SOSCCSR_SOSCERR_SHIFT                (26U)
/*! SOSCERR - System OSC Clock Error
 *  0b0..System OSC Clock Monitor is disabled or has not detected an error
 *  0b1..System OSC Clock Monitor is enabled and detected an error
 */
#define SCG_SOSCCSR_SOSCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCSR_SOSCERR_SHIFT)) & SCG_SOSCCSR_SOSCERR_MASK)
/*! @} */

/*! @name SOSCDIV - System OSC Divide Register */
/*! @{ */

#define SCG_SOSCDIV_SOSCDIV1_MASK                (0x7U)
#define SCG_SOSCDIV_SOSCDIV1_SHIFT               (0U)
/*! SOSCDIV1 - System OSC Clock Divide 1
 *  0b000..Output disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_SOSCDIV_SOSCDIV1(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SOSCDIV_SOSCDIV1_SHIFT)) & SCG_SOSCDIV_SOSCDIV1_MASK)

#define SCG_SOSCDIV_SOSCDIV2_MASK                (0x700U)
#define SCG_SOSCDIV_SOSCDIV2_SHIFT               (8U)
/*! SOSCDIV2 - System OSC Clock Divide 2
 *  0b000..Output disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_SOSCDIV_SOSCDIV2(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SOSCDIV_SOSCDIV2_SHIFT)) & SCG_SOSCDIV_SOSCDIV2_MASK)

#define SCG_SOSCDIV_SOSCDIV3_MASK                (0x70000U)
#define SCG_SOSCDIV_SOSCDIV3_SHIFT               (16U)
/*! SOSCDIV3 - System OSC Clock Divide 3
 *  0b000..Output disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_SOSCDIV_SOSCDIV3(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SOSCDIV_SOSCDIV3_SHIFT)) & SCG_SOSCDIV_SOSCDIV3_MASK)
/*! @} */

/*! @name SOSCCFG - System Oscillator Configuration Register */
/*! @{ */

#define SCG_SOSCCFG_EREFS_MASK                   (0x4U)
#define SCG_SOSCCFG_EREFS_SHIFT                  (2U)
/*! EREFS - External Reference Select
 *  0b0..External reference clock selected
 *  0b1..Internal crystal oscillator of OSC requested. In VLLS0, the internal oscillator of OSC is disabled even if SOSCEN=1 and SOSCSTEN=1.
 */
#define SCG_SOSCCFG_EREFS(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCFG_EREFS_SHIFT)) & SCG_SOSCCFG_EREFS_MASK)

#define SCG_SOSCCFG_HGO_MASK                     (0x8U)
#define SCG_SOSCCFG_HGO_SHIFT                    (3U)
/*! HGO - High Gain Oscillator Select
 *  0b0..Configure crystal oscillator for low-power operation
 *  0b1..Configure crystal oscillator for high-gain operation
 */
#define SCG_SOSCCFG_HGO(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_SOSCCFG_HGO_SHIFT)) & SCG_SOSCCFG_HGO_MASK)
/*! @} */

/*! @name SIRCCSR - Slow IRC Control Status Register */
/*! @{ */

#define SCG_SIRCCSR_SIRCEN_MASK                  (0x1U)
#define SCG_SIRCCSR_SIRCEN_SHIFT                 (0U)
/*! SIRCEN - Slow IRC Enable
 *  0b0..Slow IRC is disabled
 *  0b1..Slow IRC is enabled
 */
#define SCG_SIRCCSR_SIRCEN(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCEN_SHIFT)) & SCG_SIRCCSR_SIRCEN_MASK)

#define SCG_SIRCCSR_SIRCSTEN_MASK                (0x2U)
#define SCG_SIRCCSR_SIRCSTEN_SHIFT               (1U)
/*! SIRCSTEN - Slow IRC Stop Enable
 *  0b0..Slow IRC is disabled in Stop modes
 *  0b1..Slow IRC is enabled in Stop modes
 */
#define SCG_SIRCCSR_SIRCSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCSTEN_SHIFT)) & SCG_SIRCCSR_SIRCSTEN_MASK)

#define SCG_SIRCCSR_SIRCLPEN_MASK                (0x4U)
#define SCG_SIRCCSR_SIRCLPEN_SHIFT               (2U)
/*! SIRCLPEN - Slow IRC Low Power Enable
 *  0b0..Slow IRC is disabled in VLP modes
 *  0b1..Slow IRC is enabled in VLP modes
 */
#define SCG_SIRCCSR_SIRCLPEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCLPEN_SHIFT)) & SCG_SIRCCSR_SIRCLPEN_MASK)

#define SCG_SIRCCSR_LPOPO_MASK                   (0x10U)
#define SCG_SIRCCSR_LPOPO_SHIFT                  (4U)
/*! LPOPO - LPO Power Option
 *  0b0..LPO clock is enabled in LLS/VLLSx
 *  0b1..LPO clock is disabled in LLS/VLLSx
 */
#define SCG_SIRCCSR_LPOPO(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_LPOPO_SHIFT)) & SCG_SIRCCSR_LPOPO_MASK)

#define SCG_SIRCCSR_LK_MASK                      (0x800000U)
#define SCG_SIRCCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register
 *  0b0..Control Status Register can be written.
 *  0b1..Control Status Register cannot be written.
 */
#define SCG_SIRCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_LK_SHIFT)) & SCG_SIRCCSR_LK_MASK)

#define SCG_SIRCCSR_SIRCVLD_MASK                 (0x1000000U)
#define SCG_SIRCCSR_SIRCVLD_SHIFT                (24U)
/*! SIRCVLD - Slow IRC Valid
 *  0b0..Slow IRC is not enabled or clock is not valid
 *  0b1..Slow IRC is enabled and output clock is valid
 */
#define SCG_SIRCCSR_SIRCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCVLD_SHIFT)) & SCG_SIRCCSR_SIRCVLD_MASK)

#define SCG_SIRCCSR_SIRCSEL_MASK                 (0x2000000U)
#define SCG_SIRCCSR_SIRCSEL_SHIFT                (25U)
/*! SIRCSEL - Slow IRC Selected
 *  0b0..Slow IRC is not the system clock source
 *  0b1..Slow IRC is the system clock source
 */
#define SCG_SIRCCSR_SIRCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCSR_SIRCSEL_SHIFT)) & SCG_SIRCCSR_SIRCSEL_MASK)
/*! @} */

/*! @name SIRCDIV - Slow IRC Divide Register */
/*! @{ */

#define SCG_SIRCDIV_SIRCDIV1_MASK                (0x7U)
#define SCG_SIRCDIV_SIRCDIV1_SHIFT               (0U)
/*! SIRCDIV1 - Slow IRC Clock Divide 1
 *  0b000..Output disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_SIRCDIV_SIRCDIV1(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCDIV_SIRCDIV1_SHIFT)) & SCG_SIRCDIV_SIRCDIV1_MASK)

#define SCG_SIRCDIV_SIRCDIV2_MASK                (0x700U)
#define SCG_SIRCDIV_SIRCDIV2_SHIFT               (8U)
/*! SIRCDIV2 - Slow IRC Clock Divide 2
 *  0b000..Output disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_SIRCDIV_SIRCDIV2(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCDIV_SIRCDIV2_SHIFT)) & SCG_SIRCDIV_SIRCDIV2_MASK)

#define SCG_SIRCDIV_SIRCDIV3_MASK                (0x70000U)
#define SCG_SIRCDIV_SIRCDIV3_SHIFT               (16U)
/*! SIRCDIV3 - Slow IRC Clock Divider 3
 *  0b000..Output disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_SIRCDIV_SIRCDIV3(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SIRCDIV_SIRCDIV3_SHIFT)) & SCG_SIRCDIV_SIRCDIV3_MASK)
/*! @} */

/*! @name SIRCCFG - Slow IRC Configuration Register */
/*! @{ */

#define SCG_SIRCCFG_RANGE_MASK                   (0x1U)
#define SCG_SIRCCFG_RANGE_SHIFT                  (0U)
/*! RANGE - Frequency Range
 *  0b0..Slow IRC low range clock ( 4MHz)
 *  0b1..Slow IRC high range clock ( 16 MHz)
 */
#define SCG_SIRCCFG_RANGE(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SIRCCFG_RANGE_SHIFT)) & SCG_SIRCCFG_RANGE_MASK)
/*! @} */

/*! @name FIRCCSR - Fast IRC Control Status Register */
/*! @{ */

#define SCG_FIRCCSR_FIRCEN_MASK                  (0x1U)
#define SCG_FIRCCSR_FIRCEN_SHIFT                 (0U)
/*! FIRCEN - Fast IRC Enable
 *  0b0..Fast IRC is disabled
 *  0b1..Fast IRC is enabled
 */
#define SCG_FIRCCSR_FIRCEN(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCEN_SHIFT)) & SCG_FIRCCSR_FIRCEN_MASK)

#define SCG_FIRCCSR_FIRCSTEN_MASK                (0x2U)
#define SCG_FIRCCSR_FIRCSTEN_SHIFT               (1U)
/*! FIRCSTEN - Fast IRC Stop Enable
 *  0b0..Fast IRC is disabled in Stop modes.
 *  0b1..Fast IRC is enabled in Stop modes
 */
#define SCG_FIRCCSR_FIRCSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCSTEN_SHIFT)) & SCG_FIRCCSR_FIRCSTEN_MASK)

#define SCG_FIRCCSR_FIRCLPEN_MASK                (0x4U)
#define SCG_FIRCCSR_FIRCLPEN_SHIFT               (2U)
/*! FIRCLPEN - Fast IRC Low Power Enable
 *  0b0..Fast IRC is disabled in VLP modes
 *  0b1..Fast IRC is enabled in VLP modes
 */
#define SCG_FIRCCSR_FIRCLPEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCLPEN_SHIFT)) & SCG_FIRCCSR_FIRCLPEN_MASK)

#define SCG_FIRCCSR_FIRCTREN_MASK                (0x100U)
#define SCG_FIRCCSR_FIRCTREN_SHIFT               (8U)
/*! FIRCTREN - Fast IRC Trim Enable
 *  0b0..Disable trimming Fast IRC to an external clock source
 *  0b1..Enable trimming Fast IRC to an external clock source
 */
#define SCG_FIRCCSR_FIRCTREN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCTREN_SHIFT)) & SCG_FIRCCSR_FIRCTREN_MASK)

#define SCG_FIRCCSR_FIRCTRUP_MASK                (0x200U)
#define SCG_FIRCCSR_FIRCTRUP_SHIFT               (9U)
/*! FIRCTRUP - Fast IRC Trim Update
 *  0b0..Disable Fast IRC trimming updates
 *  0b1..Enable Fast IRC trimming updates
 */
#define SCG_FIRCCSR_FIRCTRUP(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCTRUP_SHIFT)) & SCG_FIRCCSR_FIRCTRUP_MASK)

#define SCG_FIRCCSR_POSTDIV_MASK                 (0x3000U)
#define SCG_FIRCCSR_POSTDIV_SHIFT                (12U)
/*! POSTDIV - Fast IRC Divider
 *  0b00..Divide by 1
 *  0b01..Divide by 2
 *  0b10..Divide by 3
 *  0b11..Divide by 4
 */
#define SCG_FIRCCSR_POSTDIV(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_POSTDIV_SHIFT)) & SCG_FIRCCSR_POSTDIV_MASK)

#define SCG_FIRCCSR_LK_MASK                      (0x800000U)
#define SCG_FIRCCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register
 *  0b0..Control Status Register can be written.
 *  0b1..Control Status Register cannot be written.
 */
#define SCG_FIRCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_LK_SHIFT)) & SCG_FIRCCSR_LK_MASK)

#define SCG_FIRCCSR_FIRCVLD_MASK                 (0x1000000U)
#define SCG_FIRCCSR_FIRCVLD_SHIFT                (24U)
/*! FIRCVLD - Fast IRC Valid status
 *  0b0..Fast IRC is not enabled or clock is not valid.
 *  0b1..Fast IRC is enabled and output clock is valid. The clock is valid after there is an output clock from the FIRC analog.
 */
#define SCG_FIRCCSR_FIRCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCVLD_SHIFT)) & SCG_FIRCCSR_FIRCVLD_MASK)

#define SCG_FIRCCSR_FIRCSEL_MASK                 (0x2000000U)
#define SCG_FIRCCSR_FIRCSEL_SHIFT                (25U)
/*! FIRCSEL - Fast IRC Selected status
 *  0b0..Fast IRC is not the system clock source
 *  0b1..Fast IRC is the system clock source
 */
#define SCG_FIRCCSR_FIRCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCSEL_SHIFT)) & SCG_FIRCCSR_FIRCSEL_MASK)

#define SCG_FIRCCSR_FIRCERR_MASK                 (0x4000000U)
#define SCG_FIRCCSR_FIRCERR_SHIFT                (26U)
/*! FIRCERR - Fast IRC Clock Error
 *  0b0..Error not detected with the Fast IRC trimming.
 *  0b1..Error detected with the Fast IRC trimming.
 */
#define SCG_FIRCCSR_FIRCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCERR_SHIFT)) & SCG_FIRCCSR_FIRCERR_MASK)
/*! @} */

/*! @name FIRCDIV - Fast IRC Divide Register */
/*! @{ */

#define SCG_FIRCDIV_FIRCDIV1_MASK                (0x7U)
#define SCG_FIRCDIV_FIRCDIV1_SHIFT               (0U)
/*! FIRCDIV1 - Fast IRC Clock Divide 1
 *  0b000..Output disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_FIRCDIV_FIRCDIV1(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCDIV_FIRCDIV1_SHIFT)) & SCG_FIRCDIV_FIRCDIV1_MASK)

#define SCG_FIRCDIV_FIRCDIV2_MASK                (0x700U)
#define SCG_FIRCDIV_FIRCDIV2_SHIFT               (8U)
/*! FIRCDIV2 - Fast IRC Clock Divide 2
 *  0b000..Output disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_FIRCDIV_FIRCDIV2(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCDIV_FIRCDIV2_SHIFT)) & SCG_FIRCDIV_FIRCDIV2_MASK)

#define SCG_FIRCDIV_FIRCDIV3_MASK                (0x70000U)
#define SCG_FIRCDIV_FIRCDIV3_SHIFT               (16U)
/*! FIRCDIV3 - Fast IRC Clock Divider 3
 *  0b000..Clock disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_FIRCDIV_FIRCDIV3(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCDIV_FIRCDIV3_SHIFT)) & SCG_FIRCDIV_FIRCDIV3_MASK)
/*! @} */

/*! @name FIRCCFG - Fast IRC Configuration Register */
/*! @{ */

#define SCG_FIRCCFG_RANGE_MASK                   (0x3U)
#define SCG_FIRCCFG_RANGE_SHIFT                  (0U)
/*! RANGE - Frequency Range
 *  0b00..Fast IRC is trimmed to 48 MHz
 *  0b01..Fast IRC is trimmed to 52 MHz
 *  0b10..Fast IRC is trimmed to 56 MHz
 *  0b11..Fast IRC is trimmed to 60 MHz
 */
#define SCG_FIRCCFG_RANGE(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCFG_RANGE_SHIFT)) & SCG_FIRCCFG_RANGE_MASK)
/*! @} */

/*! @name FIRCTCFG - Fast IRC Trim Configuration Register */
/*! @{ */

#define SCG_FIRCTCFG_TRIMSRC_MASK                (0x3U)
#define SCG_FIRCTCFG_TRIMSRC_SHIFT               (0U)
/*! TRIMSRC - Trim Source
 *  0b00..Reserved
 *  0b01..Reserved
 *  0b10..System OSC. This option requires that SOSC be divided using the TRIMDIV field to get a frequency slower than 32kHz.
 *  0b11..RTC OSC (32.768 kHz)
 */
#define SCG_FIRCTCFG_TRIMSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTCFG_TRIMSRC_SHIFT)) & SCG_FIRCTCFG_TRIMSRC_MASK)

#define SCG_FIRCTCFG_TRIMDIV_MASK                (0x700U)
#define SCG_FIRCTCFG_TRIMDIV_SHIFT               (8U)
/*! TRIMDIV - Fast IRC Trim Predivide
 *  0b000..Divide by 1
 *  0b001..Divide by 128
 *  0b010..Divide by 256
 *  0b011..Divide by 512
 *  0b100..Divide by 1024
 *  0b101..Divide by 2048
 *  0b110..Reserved. Writing this value will result in Divide by 1.
 *  0b111..Reserved. Writing this value will result in a Divide by 1.
 */
#define SCG_FIRCTCFG_TRIMDIV(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTCFG_TRIMDIV_SHIFT)) & SCG_FIRCTCFG_TRIMDIV_MASK)
/*! @} */

/*! @name FIRCSTAT - Fast IRC Status Register */
/*! @{ */

#define SCG_FIRCSTAT_TRIMFINE_MASK               (0x7FU)
#define SCG_FIRCSTAT_TRIMFINE_SHIFT              (0U)
/*! TRIMFINE - Trim Fine */
#define SCG_FIRCSTAT_TRIMFINE(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCSTAT_TRIMFINE_SHIFT)) & SCG_FIRCSTAT_TRIMFINE_MASK)

#define SCG_FIRCSTAT_TRIMCOAR_MASK               (0x3F00U)
#define SCG_FIRCSTAT_TRIMCOAR_SHIFT              (8U)
/*! TRIMCOAR - Trim Coarse */
#define SCG_FIRCSTAT_TRIMCOAR(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_FIRCSTAT_TRIMCOAR_SHIFT)) & SCG_FIRCSTAT_TRIMCOAR_MASK)
/*! @} */

/*! @name ROSCCSR - RTC OSC Control Status Register */
/*! @{ */

#define SCG_ROSCCSR_ROSCCM_MASK                  (0x10000U)
#define SCG_ROSCCSR_ROSCCM_SHIFT                 (16U)
/*! ROSCCM - RTC OSC Clock Monitor
 *  0b0..RTC OSC Clock Monitor is disabled
 *  0b1..RTC OSC Clock Monitor is enabled
 */
#define SCG_ROSCCSR_ROSCCM(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCCM_SHIFT)) & SCG_ROSCCSR_ROSCCM_MASK)

#define SCG_ROSCCSR_ROSCCMRE_MASK                (0x20000U)
#define SCG_ROSCCSR_ROSCCMRE_SHIFT               (17U)
/*! ROSCCMRE - RTC OSC Clock Monitor Reset Enable
 *  0b0..Clock Monitor generates interrupt when error detected
 *  0b1..Clock Monitor generates reset when error detected
 */
#define SCG_ROSCCSR_ROSCCMRE(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCCMRE_SHIFT)) & SCG_ROSCCSR_ROSCCMRE_MASK)

#define SCG_ROSCCSR_LK_MASK                      (0x800000U)
#define SCG_ROSCCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register
 *  0b0..Control Status Register can be written.
 *  0b1..Control Status Register cannot be written.
 */
#define SCG_ROSCCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_LK_SHIFT)) & SCG_ROSCCSR_LK_MASK)

#define SCG_ROSCCSR_ROSCVLD_MASK                 (0x1000000U)
#define SCG_ROSCCSR_ROSCVLD_SHIFT                (24U)
/*! ROSCVLD - RTC OSC Valid
 *  0b0..RTC OSC is not enabled or clock is not valid
 *  0b1..RTC OSC is enabled and output clock is valid
 */
#define SCG_ROSCCSR_ROSCVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCVLD_SHIFT)) & SCG_ROSCCSR_ROSCVLD_MASK)

#define SCG_ROSCCSR_ROSCSEL_MASK                 (0x2000000U)
#define SCG_ROSCCSR_ROSCSEL_SHIFT                (25U)
/*! ROSCSEL - RTC OSC Selected
 *  0b0..RTC OSC is not the system clock source
 *  0b1..RTC OSC is the system clock source
 */
#define SCG_ROSCCSR_ROSCSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCSEL_SHIFT)) & SCG_ROSCCSR_ROSCSEL_MASK)

#define SCG_ROSCCSR_ROSCERR_MASK                 (0x4000000U)
#define SCG_ROSCCSR_ROSCERR_SHIFT                (26U)
/*! ROSCERR - RTC OSC Clock Error
 *  0b0..RTC OSC Clock Monitor is disabled or has not detected an error
 *  0b1..RTC OSC Clock Monitor is enabled and detected an RTC loss of clock error
 */
#define SCG_ROSCCSR_ROSCERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_ROSCCSR_ROSCERR_SHIFT)) & SCG_ROSCCSR_ROSCERR_MASK)
/*! @} */

/*! @name APLLCSR - Auxiliary PLL Control Status Register */
/*! @{ */

#define SCG_APLLCSR_APLLEN_MASK                  (0x1U)
#define SCG_APLLCSR_APLLEN_SHIFT                 (0U)
/*! APLLEN - Auxiliary PLL (APLL) Enable
 *  0b0..APLL is disabled
 *  0b1..APLL is enabled
 */
#define SCG_APLLCSR_APLLEN(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_APLLEN_SHIFT)) & SCG_APLLCSR_APLLEN_MASK)

#define SCG_APLLCSR_APLLSTEN_MASK                (0x2U)
#define SCG_APLLCSR_APLLSTEN_SHIFT               (1U)
/*! APLLSTEN - APLL Stop Enable
 *  0b0..APLL is disabled in Stop modes
 *  0b1..APLL is enabled in Stop modes
 */
#define SCG_APLLCSR_APLLSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_APLLSTEN_SHIFT)) & SCG_APLLCSR_APLLSTEN_MASK)

#define SCG_APLLCSR_LK_MASK                      (0x800000U)
#define SCG_APLLCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register
 *  0b0..Control Status Register can be written.
 *  0b1..Control Status Register cannot be written.
 */
#define SCG_APLLCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_LK_SHIFT)) & SCG_APLLCSR_LK_MASK)

#define SCG_APLLCSR_APLLVLD_MASK                 (0x1000000U)
#define SCG_APLLCSR_APLLVLD_SHIFT                (24U)
/*! APLLVLD - APLL Valid
 *  0b0..APLL is not enabled or clock is not valid
 *  0b1..APLL is enabled and output clock is valid
 */
#define SCG_APLLCSR_APLLVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_APLLVLD_SHIFT)) & SCG_APLLCSR_APLLVLD_MASK)

#define SCG_APLLCSR_APLLSEL_MASK                 (0x2000000U)
#define SCG_APLLCSR_APLLSEL_SHIFT                (25U)
/*! APLLSEL - APLL Selected
 *  0b0..APLL is not the system clock source
 *  0b1..APLL is the system clock source
 */
#define SCG_APLLCSR_APLLSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_APLLCSR_APLLSEL_SHIFT)) & SCG_APLLCSR_APLLSEL_MASK)
/*! @} */

/*! @name APLLDIV - Auxiliary PLL Divide Register */
/*! @{ */

#define SCG_APLLDIV_APLLDIV1_MASK                (0x7U)
#define SCG_APLLDIV_APLLDIV1_SHIFT               (0U)
/*! APLLDIV1 - Auxiliary PLL Clock Divide 1
 *  0b000..Clock disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_APLLDIV_APLLDIV1(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_APLLDIV_APLLDIV1_SHIFT)) & SCG_APLLDIV_APLLDIV1_MASK)

#define SCG_APLLDIV_APLLDIV2_MASK                (0x700U)
#define SCG_APLLDIV_APLLDIV2_SHIFT               (8U)
/*! APLLDIV2 - Auxiliary PLL Clock Divide 2
 *  0b000..Clock disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_APLLDIV_APLLDIV2(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_APLLDIV_APLLDIV2_SHIFT)) & SCG_APLLDIV_APLLDIV2_MASK)

#define SCG_APLLDIV_APLLDIV3_MASK                (0x70000U)
#define SCG_APLLDIV_APLLDIV3_SHIFT               (16U)
/*! APLLDIV3 - Auxiliary PLL Clock Divide 3
 *  0b000..Clock disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_APLLDIV_APLLDIV3(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_APLLDIV_APLLDIV3_SHIFT)) & SCG_APLLDIV_APLLDIV3_MASK)
/*! @} */

/*! @name APLLCFG - Auxiliary PLL Configuration Register */
/*! @{ */

#define SCG_APLLCFG_SOURCE_MASK                  (0x1U)
#define SCG_APLLCFG_SOURCE_SHIFT                 (0U)
/*! SOURCE - Clock Source
 *  0b0..System OSC
 *  0b1..Reserved
 */
#define SCG_APLLCFG_SOURCE(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_APLLCFG_SOURCE_SHIFT)) & SCG_APLLCFG_SOURCE_MASK)

#define SCG_APLLCFG_PLLS_MASK                    (0x2U)
#define SCG_APLLCFG_PLLS_SHIFT                   (1U)
/*! PLLS - PLL Select
 *  0b0..APLL clock selected.
 *  0b1..APLL PFD output clock selected
 */
#define SCG_APLLCFG_PLLS(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_APLLCFG_PLLS_SHIFT)) & SCG_APLLCFG_PLLS_MASK)

#define SCG_APLLCFG_PREDIV_MASK                  (0x700U)
#define SCG_APLLCFG_PREDIV_SHIFT                 (8U)
/*! PREDIV - PLL Reference Clock Divider */
#define SCG_APLLCFG_PREDIV(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_APLLCFG_PREDIV_SHIFT)) & SCG_APLLCFG_PREDIV_MASK)

#define SCG_APLLCFG_PFDSEL_MASK                  (0xC000U)
#define SCG_APLLCFG_PFDSEL_SHIFT                 (14U)
/*! PFDSEL - PFD Clock Select
 *  0b00..PFD0 output clock selected.
 *  0b01..PFD1 output clock selected.
 *  0b10..PFD2 output clock selected.
 *  0b11..PFD3 output clock selected.
 */
#define SCG_APLLCFG_PFDSEL(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_APLLCFG_PFDSEL_SHIFT)) & SCG_APLLCFG_PFDSEL_MASK)

#define SCG_APLLCFG_MULT_MASK                    (0x7F0000U)
#define SCG_APLLCFG_MULT_SHIFT                   (16U)
/*! MULT - Auxiliary PLL Multiplier */
#define SCG_APLLCFG_MULT(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_APLLCFG_MULT_SHIFT)) & SCG_APLLCFG_MULT_MASK)

#define SCG_APLLCFG_PLLPOSTDIV1_MASK             (0xF000000U)
#define SCG_APLLCFG_PLLPOSTDIV1_SHIFT            (24U)
/*! PLLPOSTDIV1 - Auxiliary PLL Post Clock Divide1 Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_APLLCFG_PLLPOSTDIV1(x)               (((uint32_t)(((uint32_t)(x)) << SCG_APLLCFG_PLLPOSTDIV1_SHIFT)) & SCG_APLLCFG_PLLPOSTDIV1_MASK)

#define SCG_APLLCFG_PLLPOSTDIV2_MASK             (0xF0000000U)
#define SCG_APLLCFG_PLLPOSTDIV2_SHIFT            (28U)
/*! PLLPOSTDIV2 - Auxiliary PLL Post Clock Divide2 Ratio
 *  0b0000..Divide-by-1
 *  0b0001..Divide-by-2
 *  0b0010..Divide-by-3
 *  0b0011..Divide-by-4
 *  0b0100..Divide-by-5
 *  0b0101..Divide-by-6
 *  0b0110..Divide-by-7
 *  0b0111..Divide-by-8
 *  0b1000..Divide-by-9
 *  0b1001..Divide-by-10
 *  0b1010..Divide-by-11
 *  0b1011..Divide-by-12
 *  0b1100..Divide-by-13
 *  0b1101..Divide-by-14
 *  0b1110..Divide-by-15
 *  0b1111..Divide-by-16
 */
#define SCG_APLLCFG_PLLPOSTDIV2(x)               (((uint32_t)(((uint32_t)(x)) << SCG_APLLCFG_PLLPOSTDIV2_SHIFT)) & SCG_APLLCFG_PLLPOSTDIV2_MASK)
/*! @} */

/*! @name APLLPFD - Auxiliary PLL PFD Register */
/*! @{ */

#define SCG_APLLPFD_PFD0_MASK                    (0x3FU)
#define SCG_APLLPFD_PFD0_SHIFT                   (0U)
/*! PFD0 - PLL Fractional Divider 0 */
#define SCG_APLLPFD_PFD0(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_APLLPFD_PFD0_SHIFT)) & SCG_APLLPFD_PFD0_MASK)

#define SCG_APLLPFD_PFD0_VALID_MASK              (0x40U)
#define SCG_APLLPFD_PFD0_VALID_SHIFT             (6U)
/*! PFD0_VALID - PFD0_VALID */
#define SCG_APLLPFD_PFD0_VALID(x)                (((uint32_t)(((uint32_t)(x)) << SCG_APLLPFD_PFD0_VALID_SHIFT)) & SCG_APLLPFD_PFD0_VALID_MASK)

#define SCG_APLLPFD_PFD0_CLKGATE_MASK            (0x80U)
#define SCG_APLLPFD_PFD0_CLKGATE_SHIFT           (7U)
/*! PFD0_CLKGATE - PFD0_CLKGATE
 *  0b0..PFD0 clock is not gated.
 *  0b1..PFD0 clock is gated.
 */
#define SCG_APLLPFD_PFD0_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << SCG_APLLPFD_PFD0_CLKGATE_SHIFT)) & SCG_APLLPFD_PFD0_CLKGATE_MASK)

#define SCG_APLLPFD_PFD1_MASK                    (0x3F00U)
#define SCG_APLLPFD_PFD1_SHIFT                   (8U)
/*! PFD1 - PLL Fractional Divider 1 */
#define SCG_APLLPFD_PFD1(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_APLLPFD_PFD1_SHIFT)) & SCG_APLLPFD_PFD1_MASK)

#define SCG_APLLPFD_PFD1_VALID_MASK              (0x4000U)
#define SCG_APLLPFD_PFD1_VALID_SHIFT             (14U)
/*! PFD1_VALID - PFD1_VALID */
#define SCG_APLLPFD_PFD1_VALID(x)                (((uint32_t)(((uint32_t)(x)) << SCG_APLLPFD_PFD1_VALID_SHIFT)) & SCG_APLLPFD_PFD1_VALID_MASK)

#define SCG_APLLPFD_PFD1_CLKGATE_MASK            (0x8000U)
#define SCG_APLLPFD_PFD1_CLKGATE_SHIFT           (15U)
/*! PFD1_CLKGATE - PFD1_CLKGATE
 *  0b0..PFD1 clock is not gated.
 *  0b1..PFD1 clock is gated.
 */
#define SCG_APLLPFD_PFD1_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << SCG_APLLPFD_PFD1_CLKGATE_SHIFT)) & SCG_APLLPFD_PFD1_CLKGATE_MASK)

#define SCG_APLLPFD_PFD2_MASK                    (0x3F0000U)
#define SCG_APLLPFD_PFD2_SHIFT                   (16U)
/*! PFD2 - PLL Fractional Divider 2 */
#define SCG_APLLPFD_PFD2(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_APLLPFD_PFD2_SHIFT)) & SCG_APLLPFD_PFD2_MASK)

#define SCG_APLLPFD_PFD2_VALID_MASK              (0x400000U)
#define SCG_APLLPFD_PFD2_VALID_SHIFT             (22U)
/*! PFD2_VALID - PFD2_VALID */
#define SCG_APLLPFD_PFD2_VALID(x)                (((uint32_t)(((uint32_t)(x)) << SCG_APLLPFD_PFD2_VALID_SHIFT)) & SCG_APLLPFD_PFD2_VALID_MASK)

#define SCG_APLLPFD_PFD2_CLKGATE_MASK            (0x800000U)
#define SCG_APLLPFD_PFD2_CLKGATE_SHIFT           (23U)
/*! PFD2_CLKGATE - PFD2_CLKGATE
 *  0b0..PFD2 clock is not gated.
 *  0b1..PFD2 clock is gated.
 */
#define SCG_APLLPFD_PFD2_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << SCG_APLLPFD_PFD2_CLKGATE_SHIFT)) & SCG_APLLPFD_PFD2_CLKGATE_MASK)

#define SCG_APLLPFD_PFD3_MASK                    (0x3F000000U)
#define SCG_APLLPFD_PFD3_SHIFT                   (24U)
/*! PFD3 - PLL Fractional Divider 3 */
#define SCG_APLLPFD_PFD3(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_APLLPFD_PFD3_SHIFT)) & SCG_APLLPFD_PFD3_MASK)

#define SCG_APLLPFD_PFD3_VALID_MASK              (0x40000000U)
#define SCG_APLLPFD_PFD3_VALID_SHIFT             (30U)
/*! PFD3_VALID - PFD3_VALID */
#define SCG_APLLPFD_PFD3_VALID(x)                (((uint32_t)(((uint32_t)(x)) << SCG_APLLPFD_PFD3_VALID_SHIFT)) & SCG_APLLPFD_PFD3_VALID_MASK)

#define SCG_APLLPFD_PFD3_CLKGATE_MASK            (0x80000000U)
#define SCG_APLLPFD_PFD3_CLKGATE_SHIFT           (31U)
/*! PFD3_CLKGATE - PFD3_CLKGATE
 *  0b0..PFD3 clock is not gated.
 *  0b1..PFD3 clock is gated.
 */
#define SCG_APLLPFD_PFD3_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << SCG_APLLPFD_PFD3_CLKGATE_SHIFT)) & SCG_APLLPFD_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name APLLNUM - Auxiliary PLL Numerator Register */
/*! @{ */

#define SCG_APLLNUM_NUM_MASK                     (0x3FFFFFFFU)
#define SCG_APLLNUM_NUM_SHIFT                    (0U)
/*! NUM - 30-bit numerator of the Auxiliary PLL Fractional-Loop divider */
#define SCG_APLLNUM_NUM(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_APLLNUM_NUM_SHIFT)) & SCG_APLLNUM_NUM_MASK)
/*! @} */

/*! @name APLLDENOM - Auxiliary PLL Denominator Register */
/*! @{ */

#define SCG_APLLDENOM_DENOM_MASK                 (0x3FFFFFFFU)
#define SCG_APLLDENOM_DENOM_SHIFT                (0U)
/*! DENOM - 30-bit denominator of the Auxiliary PLL Fractional-Loop divider */
#define SCG_APLLDENOM_DENOM(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_APLLDENOM_DENOM_SHIFT)) & SCG_APLLDENOM_DENOM_MASK)
/*! @} */

/*! @name APLLSS - Auxiliary PLL Spread Spectrum Register */
/*! @{ */

#define SCG_APLLSS_STEP_MASK                     (0x7FFFU)
#define SCG_APLLSS_STEP_SHIFT                    (0U)
/*! STEP - STOP and STEP together control the modulation depth (maximum frequency change) and
 *    modulation frequency. Modulation Depth = (STOP/DENOM)*Fref where DENOM is the DENOM field value in
 *    DENOM register. Modulation Frequency = (STEP/(2*STOP))*Fref, where Fref = 24Mhz.
 */
#define SCG_APLLSS_STEP(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_APLLSS_STEP_SHIFT)) & SCG_APLLSS_STEP_MASK)

#define SCG_APLLSS_ENABLE_MASK                   (0x8000U)
#define SCG_APLLSS_ENABLE_SHIFT                  (15U)
/*! ENABLE - Enables the spread spectrum modulation.
 *  0b0..Spectrum modulation is disabled
 *  0b1..Spectrum modulation is enabled
 */
#define SCG_APLLSS_ENABLE(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_APLLSS_ENABLE_SHIFT)) & SCG_APLLSS_ENABLE_MASK)

#define SCG_APLLSS_STOP_MASK                     (0xFFFF0000U)
#define SCG_APLLSS_STOP_SHIFT                    (16U)
/*! STOP - STOP and STEP together control the modulation depth (maximum frequency change) and
 *    modulation depth. Modulation Depth = (STOP/DENOM)*Fref where DENOM is the DENOM field value in DENOM
 *    register. Modulation Frequency = (STEP/(2*STOP))*Fref, where Fref = 24Mhz.
 */
#define SCG_APLLSS_STOP(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_APLLSS_STOP_SHIFT)) & SCG_APLLSS_STOP_MASK)
/*! @} */

/*! @name APLLLOCK_CNFG - Auxiliary PLL LOCK Configuration Register */
/*! @{ */

#define SCG_APLLLOCK_CNFG_LOCK_TIME_MASK         (0xFFFFU)
#define SCG_APLLLOCK_CNFG_LOCK_TIME_SHIFT        (0U)
/*! LOCK_TIME - Configures the number of reference clocks to count before APLL is considered locked and valid. */
#define SCG_APLLLOCK_CNFG_LOCK_TIME(x)           (((uint32_t)(((uint32_t)(x)) << SCG_APLLLOCK_CNFG_LOCK_TIME_SHIFT)) & SCG_APLLLOCK_CNFG_LOCK_TIME_MASK)
/*! @} */

/*! @name SPLLCSR - System PLL Control Status Register */
/*! @{ */

#define SCG_SPLLCSR_SPLLEN_MASK                  (0x1U)
#define SCG_SPLLCSR_SPLLEN_SHIFT                 (0U)
/*! SPLLEN - System PLL Enable
 *  0b0..System PLL is disabled
 *  0b1..System PLL is enabled
 */
#define SCG_SPLLCSR_SPLLEN(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLLEN_SHIFT)) & SCG_SPLLCSR_SPLLEN_MASK)

#define SCG_SPLLCSR_SPLLSTEN_MASK                (0x2U)
#define SCG_SPLLCSR_SPLLSTEN_SHIFT               (1U)
/*! SPLLSTEN - System PLL Stop Enable
 *  0b0..System PLL is disabled in Stop modes
 *  0b1..System PLL is enabled in Stop modes
 */
#define SCG_SPLLCSR_SPLLSTEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLLSTEN_SHIFT)) & SCG_SPLLCSR_SPLLSTEN_MASK)

#define SCG_SPLLCSR_LK_MASK                      (0x800000U)
#define SCG_SPLLCSR_LK_SHIFT                     (23U)
/*! LK - Lock Register
 *  0b0..Control Status Register can be written.
 *  0b1..Control Status Register cannot be written.
 */
#define SCG_SPLLCSR_LK(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_LK_SHIFT)) & SCG_SPLLCSR_LK_MASK)

#define SCG_SPLLCSR_SPLLVLD_MASK                 (0x1000000U)
#define SCG_SPLLCSR_SPLLVLD_SHIFT                (24U)
/*! SPLLVLD - System PLL Valid
 *  0b0..System PLL is not enabled or clock is not valid
 *  0b1..System PLL is enabled and output clock is valid
 */
#define SCG_SPLLCSR_SPLLVLD(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLLVLD_SHIFT)) & SCG_SPLLCSR_SPLLVLD_MASK)

#define SCG_SPLLCSR_SPLLSEL_MASK                 (0x2000000U)
#define SCG_SPLLCSR_SPLLSEL_SHIFT                (25U)
/*! SPLLSEL - System PLL Selected
 *  0b0..System PLL is not the system clock source
 *  0b1..System PLL is the system clock source
 */
#define SCG_SPLLCSR_SPLLSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLLSEL_SHIFT)) & SCG_SPLLCSR_SPLLSEL_MASK)

#define SCG_SPLLCSR_SPLLERR_MASK                 (0x4000000U)
#define SCG_SPLLCSR_SPLLERR_SHIFT                (26U)
/*! SPLLERR - System PLL Clock Error
 *  0b0..System PLL Clock Monitor is disabled or has not detected an error
 *  0b1..System PLL Clock Monitor is enabled and detected an error. System PLL Clock Error flag will not set when
 *       System OSC is selected as its source and SOSCERR has set.
 */
#define SCG_SPLLCSR_SPLLERR(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCSR_SPLLERR_SHIFT)) & SCG_SPLLCSR_SPLLERR_MASK)
/*! @} */

/*! @name SPLLDIV - System PLL Divide Register */
/*! @{ */

#define SCG_SPLLDIV_SPLLDIV1_MASK                (0x7U)
#define SCG_SPLLDIV_SPLLDIV1_SHIFT               (0U)
/*! SPLLDIV1 - System PLL Clock Divide 1
 *  0b000..Clock disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_SPLLDIV_SPLLDIV1(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SPLLDIV_SPLLDIV1_SHIFT)) & SCG_SPLLDIV_SPLLDIV1_MASK)

#define SCG_SPLLDIV_SPLLDIV2_MASK                (0x700U)
#define SCG_SPLLDIV_SPLLDIV2_SHIFT               (8U)
/*! SPLLDIV2 - System PLL Clock Divide 2
 *  0b000..Clock disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_SPLLDIV_SPLLDIV2(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SPLLDIV_SPLLDIV2_SHIFT)) & SCG_SPLLDIV_SPLLDIV2_MASK)

#define SCG_SPLLDIV_SPLLDIV3_MASK                (0x70000U)
#define SCG_SPLLDIV_SPLLDIV3_SHIFT               (16U)
/*! SPLLDIV3 - System PLL Clock Divide 3
 *  0b000..Clock disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_SPLLDIV_SPLLDIV3(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_SPLLDIV_SPLLDIV3_SHIFT)) & SCG_SPLLDIV_SPLLDIV3_MASK)
/*! @} */

/*! @name SPLLCFG - System PLL Configuration Register */
/*! @{ */

#define SCG_SPLLCFG_SOURCE_MASK                  (0x1U)
#define SCG_SPLLCFG_SOURCE_SHIFT                 (0U)
/*! SOURCE - Clock Source
 *  0b0..System OSC (SOSC)
 *  0b1..Reserved
 */
#define SCG_SPLLCFG_SOURCE(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCFG_SOURCE_SHIFT)) & SCG_SPLLCFG_SOURCE_MASK)

#define SCG_SPLLCFG_PLLS_MASK                    (0x2U)
#define SCG_SPLLCFG_PLLS_SHIFT                   (1U)
/*! PLLS - PLL Select
 *  0b0..SPLL output clocks selected
 *  0b1..SPLL PFD output clock selected.
 */
#define SCG_SPLLCFG_PLLS(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCFG_PLLS_SHIFT)) & SCG_SPLLCFG_PLLS_MASK)

#define SCG_SPLLCFG_PREDIV_MASK                  (0x700U)
#define SCG_SPLLCFG_PREDIV_SHIFT                 (8U)
/*! PREDIV - PLL Reference Clock Divider */
#define SCG_SPLLCFG_PREDIV(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCFG_PREDIV_SHIFT)) & SCG_SPLLCFG_PREDIV_MASK)

#define SCG_SPLLCFG_PFDSEL_MASK                  (0xC000U)
#define SCG_SPLLCFG_PFDSEL_SHIFT                 (14U)
/*! PFDSEL - PFD Clock Select
 *  0b00..PFD0 output clock selected.
 *  0b01..PFD1 output clock selected.
 *  0b10..PFD2 output clock selected.
 *  0b11..PFD3 output clock selected.
 */
#define SCG_SPLLCFG_PFDSEL(x)                    (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCFG_PFDSEL_SHIFT)) & SCG_SPLLCFG_PFDSEL_MASK)

#define SCG_SPLLCFG_MULT_MASK                    (0x7F0000U)  /* Merged from fields with different position or width, of widths (3, 7), largest definition used */
#define SCG_SPLLCFG_MULT_SHIFT                   (16U)
/*! MULT - System PLL Multiplier
 *  0b000..Reserved
 *  0b001..MULT = 15
 *  0b010..MULT = 16
 *  0b011..MULT = 20
 *  0b100..MULT = 22
 *  0b101..MULT = 25
 *  0b110..MULT = 30
 *  0b111..Reserved
 */
#define SCG_SPLLCFG_MULT(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_SPLLCFG_MULT_SHIFT)) & SCG_SPLLCFG_MULT_MASK)  /* Merged from fields with different position or width, of widths (3, 7), largest definition used */
/*! @} */

/*! @name SPLLPFD - System PLL PFD Register */
/*! @{ */

#define SCG_SPLLPFD_PFD0_MASK                    (0x3FU)
#define SCG_SPLLPFD_PFD0_SHIFT                   (0U)
/*! PFD0 - PLL Fractional Divider 0 */
#define SCG_SPLLPFD_PFD0(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPFD_PFD0_SHIFT)) & SCG_SPLLPFD_PFD0_MASK)

#define SCG_SPLLPFD_PFD0_VALID_MASK              (0x40U)
#define SCG_SPLLPFD_PFD0_VALID_SHIFT             (6U)
/*! PFD0_VALID - PFD0_VALID */
#define SCG_SPLLPFD_PFD0_VALID(x)                (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPFD_PFD0_VALID_SHIFT)) & SCG_SPLLPFD_PFD0_VALID_MASK)

#define SCG_SPLLPFD_PFD0_CLKGATE_MASK            (0x80U)
#define SCG_SPLLPFD_PFD0_CLKGATE_SHIFT           (7U)
/*! PFD0_CLKGATE - PFD0_CLKGATE
 *  0b0..PFD0 clock is not gated.
 *  0b1..PFD0 clock is gated.
 */
#define SCG_SPLLPFD_PFD0_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPFD_PFD0_CLKGATE_SHIFT)) & SCG_SPLLPFD_PFD0_CLKGATE_MASK)

#define SCG_SPLLPFD_PFD1_MASK                    (0x3F00U)
#define SCG_SPLLPFD_PFD1_SHIFT                   (8U)
/*! PFD1 - PLL Fractional Divider 5 */
#define SCG_SPLLPFD_PFD1(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPFD_PFD1_SHIFT)) & SCG_SPLLPFD_PFD1_MASK)

#define SCG_SPLLPFD_PFD1_VALID_MASK              (0x4000U)
#define SCG_SPLLPFD_PFD1_VALID_SHIFT             (14U)
/*! PFD1_VALID - PFD1_VALID */
#define SCG_SPLLPFD_PFD1_VALID(x)                (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPFD_PFD1_VALID_SHIFT)) & SCG_SPLLPFD_PFD1_VALID_MASK)

#define SCG_SPLLPFD_PFD1_CLKGATE_MASK            (0x8000U)
#define SCG_SPLLPFD_PFD1_CLKGATE_SHIFT           (15U)
/*! PFD1_CLKGATE - PFD1_CLKGATE
 *  0b0..PFD1 clock is not gated.
 *  0b1..PFD1 clock is gated.
 */
#define SCG_SPLLPFD_PFD1_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPFD_PFD1_CLKGATE_SHIFT)) & SCG_SPLLPFD_PFD1_CLKGATE_MASK)

#define SCG_SPLLPFD_PFD2_MASK                    (0x3F0000U)
#define SCG_SPLLPFD_PFD2_SHIFT                   (16U)
/*! PFD2 - PLL Fractional Divider 2 */
#define SCG_SPLLPFD_PFD2(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPFD_PFD2_SHIFT)) & SCG_SPLLPFD_PFD2_MASK)

#define SCG_SPLLPFD_PFD2_VALID_MASK              (0x400000U)
#define SCG_SPLLPFD_PFD2_VALID_SHIFT             (22U)
/*! PFD2_VALID - PFD2_VALID */
#define SCG_SPLLPFD_PFD2_VALID(x)                (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPFD_PFD2_VALID_SHIFT)) & SCG_SPLLPFD_PFD2_VALID_MASK)

#define SCG_SPLLPFD_PFD2_CLKGATE_MASK            (0x800000U)
#define SCG_SPLLPFD_PFD2_CLKGATE_SHIFT           (23U)
/*! PFD2_CLKGATE - PFD2_CLKGATE
 *  0b0..PFD2 clock is not gated.
 *  0b1..PFD2 clock is gated.
 */
#define SCG_SPLLPFD_PFD2_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPFD_PFD2_CLKGATE_SHIFT)) & SCG_SPLLPFD_PFD2_CLKGATE_MASK)

#define SCG_SPLLPFD_PFD3_MASK                    (0x3F000000U)
#define SCG_SPLLPFD_PFD3_SHIFT                   (24U)
/*! PFD3 - PLL Fractional Divider 3 */
#define SCG_SPLLPFD_PFD3(x)                      (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPFD_PFD3_SHIFT)) & SCG_SPLLPFD_PFD3_MASK)

#define SCG_SPLLPFD_PFD3_VALID_MASK              (0x40000000U)
#define SCG_SPLLPFD_PFD3_VALID_SHIFT             (30U)
/*! PFD3_VALID - PFD3_VALID */
#define SCG_SPLLPFD_PFD3_VALID(x)                (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPFD_PFD3_VALID_SHIFT)) & SCG_SPLLPFD_PFD3_VALID_MASK)

#define SCG_SPLLPFD_PFD3_CLKGATE_MASK            (0x80000000U)
#define SCG_SPLLPFD_PFD3_CLKGATE_SHIFT           (31U)
/*! PFD3_CLKGATE - PFD3_CLKGATE
 *  0b0..PFD3 clock is not gated.
 *  0b1..PFD3 clock is gated.
 */
#define SCG_SPLLPFD_PFD3_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << SCG_SPLLPFD_PFD3_CLKGATE_SHIFT)) & SCG_SPLLPFD_PFD3_CLKGATE_MASK)
/*! @} */

/*! @name SPLLNUM - System PLL Numerator Register */
/*! @{ */

#define SCG_SPLLNUM_NUM_MASK                     (0x3FFFFFFFU)
#define SCG_SPLLNUM_NUM_SHIFT                    (0U)
/*! NUM - 30-bit numerator of the System PLL Fractional-Loop divider */
#define SCG_SPLLNUM_NUM(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_SPLLNUM_NUM_SHIFT)) & SCG_SPLLNUM_NUM_MASK)
/*! @} */

/*! @name SPLLDENOM - System PLL Denominator Register */
/*! @{ */

#define SCG_SPLLDENOM_DENOM_MASK                 (0x3FFFFFFFU)
#define SCG_SPLLDENOM_DENOM_SHIFT                (0U)
/*! DENOM - 30-bit denominator of the System PLL Fractional-Loop divider */
#define SCG_SPLLDENOM_DENOM(x)                   (((uint32_t)(((uint32_t)(x)) << SCG_SPLLDENOM_DENOM_SHIFT)) & SCG_SPLLDENOM_DENOM_MASK)
/*! @} */

/*! @name SPLLSS - System PLL Spread Spectrum Register */
/*! @{ */

#define SCG_SPLLSS_STEP_MASK                     (0x7FFFU)
#define SCG_SPLLSS_STEP_SHIFT                    (0U)
/*! STEP - STOP and STEP together control the modulation depth (maximum frequency change) and
 *    Modulation Depth. Modulation Depth = (STOP/DENOM)*Fref where DENOM is the DENOM field value in DENOM
 *    register. Modulation Frequency = (STEP/(2*STOP))*Fref, where Fref = 24Mhz.
 */
#define SCG_SPLLSS_STEP(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSS_STEP_SHIFT)) & SCG_SPLLSS_STEP_MASK)

#define SCG_SPLLSS_ENABLE_MASK                   (0x8000U)
#define SCG_SPLLSS_ENABLE_SHIFT                  (15U)
/*! ENABLE - Spread Spectrum Modulation Enable
 *  0b0..Spectrum modulation is disabled
 *  0b1..Spectrum modulation is enabled
 */
#define SCG_SPLLSS_ENABLE(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSS_ENABLE_SHIFT)) & SCG_SPLLSS_ENABLE_MASK)

#define SCG_SPLLSS_STOP_MASK                     (0xFFFF0000U)
#define SCG_SPLLSS_STOP_SHIFT                    (16U)
/*! STOP - STOP and STEP together control the modulation depth (maximum frequency change) and
 *    Modulation Depth. Modulation Depth = (STOP/DENOM)*Fref where DENOM is the DENOM field value in DENOM
 *    register. Modulation Frequency = (STEP/(2*STOP))*Fref, where Fref = 24Mhz.
 */
#define SCG_SPLLSS_STOP(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_SPLLSS_STOP_SHIFT)) & SCG_SPLLSS_STOP_MASK)
/*! @} */

/*! @name SPLLLOCK_CNFG - System PLL LOCK Configuration Register */
/*! @{ */

#define SCG_SPLLLOCK_CNFG_LOCK_TIME_MASK         (0xFFFFU)
#define SCG_SPLLLOCK_CNFG_LOCK_TIME_SHIFT        (0U)
/*! LOCK_TIME - Configures the number of reference clocks to count before SPLL is considered locked and valid. */
#define SCG_SPLLLOCK_CNFG_LOCK_TIME(x)           (((uint32_t)(((uint32_t)(x)) << SCG_SPLLLOCK_CNFG_LOCK_TIME_SHIFT)) & SCG_SPLLLOCK_CNFG_LOCK_TIME_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SCG_Register_Masks */


/*!
 * @}
 */ /* end of group SCG_Peripheral_Access_Layer */


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


#endif  /* PERI_SCG_H_ */

