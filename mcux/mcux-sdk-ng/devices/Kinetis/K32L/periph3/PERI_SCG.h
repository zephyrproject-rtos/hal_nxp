/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
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
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SCG.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SCG
 *
 * CMSIS Peripheral Access Layer for SCG
 */

#if !defined(PERI_SCG_H_)
#define PERI_SCG_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
       uint8_t RESERVED_1[476];
  __IO uint32_t SIRCCSR;                           /**< Slow IRC Control Status Register, offset: 0x200 */
  __IO uint32_t SIRCDIV;                           /**< Slow IRC Divide Register, offset: 0x204 */
  __IO uint32_t SIRCCFG;                           /**< Slow IRC Configuration Register, offset: 0x208 */
       uint8_t RESERVED_2[244];
  __IO uint32_t FIRCCSR;                           /**< Fast IRC Control Status Register, offset: 0x300 */
  __IO uint32_t FIRCDIV;                           /**< Fast IRC Divide Register, offset: 0x304 */
  __IO uint32_t FIRCCFG;                           /**< Fast IRC Configuration Register, offset: 0x308 */
  __IO uint32_t FIRCTCFG;                          /**< Fast IRC Trim Configuration Register, offset: 0x30C */
       uint8_t RESERVED_3[8];
  __IO uint32_t FIRCSTAT;                          /**< Fast IRC Status Register, offset: 0x318 */
       uint8_t RESERVED_4[228];
  __IO uint32_t ROSCCSR;                           /**< RTC OSC Control Status Register, offset: 0x400 */
       uint8_t RESERVED_5[252];
  __IO uint32_t LPFLLCSR;                          /**< Low Power FLL Control Status Register, offset: 0x500 */
  __IO uint32_t LPFLLDIV;                          /**< Low Power FLL Divide Register, offset: 0x504 */
  __IO uint32_t LPFLLCFG;                          /**< Low Power FLL Configuration Register, offset: 0x508 */
  __IO uint32_t LPFLLTCFG;                         /**< Low Power FLL Trim Configuration Register, offset: 0x50C */
       uint8_t RESERVED_6[4];
  __IO uint32_t LPFLLSTAT;                         /**< Low Power FLL Status Register, offset: 0x514 */
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
 *  0bxx1xxxxx..Low Power FLL (LPFLL) is present.
 *  0bxxx1xxxx..RTC OSC (ROSC) is present.
 *  0bxxxx1xxx..Fast IRC (FIRC) is present.
 *  0bxxxxx1xx..Slow IRC (SIRC) is present.
 *  0bxxxxxx1x..Reserved.
 */
#define SCG_PARAM_CLKPRES(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_PARAM_CLKPRES_SHIFT)) & SCG_PARAM_CLKPRES_MASK)

#define SCG_PARAM_DIVPRES_MASK                   (0xF8000000U)
#define SCG_PARAM_DIVPRES_SHIFT                  (27U)
/*! DIVPRES - Divider Present
 *  0b1xxxx..System DIVCORE is present.
 *  0bxx1xx..System DIVEXT is present.
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
 *  0b0000..Reserved
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

#define SCG_CSR_DIVEXT_MASK                      (0xF00U)
#define SCG_CSR_DIVEXT_SHIFT                     (8U)
/*! DIVEXT - External Clock Divide Ratio
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
#define SCG_CSR_DIVEXT(x)                        (((uint32_t)(((uint32_t)(x)) << SCG_CSR_DIVEXT_SHIFT)) & SCG_CSR_DIVEXT_MASK)

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
 *  0b0001..Reserved
 *  0b0010..Slow IRC (SIRC_CLK)
 *  0b0011..Fast IRC (FIRC_CLK)
 *  0b0100..RTC OSC (ROSC_CLK)
 *  0b0101..Low Power FLL (LPFLL_CLK)
 *  0b0110..Reserved
 *  0b0111..Reserved
 */
#define SCG_CSR_SCS(x)                           (((uint32_t)(((uint32_t)(x)) << SCG_CSR_SCS_SHIFT)) & SCG_CSR_SCS_MASK)
/*! @} */

/*! @name RCCR - Run Clock Control Register */
/*! @{ */

#define SCG_RCCR_DIVSLOW_MASK                    (0xFU)
#define SCG_RCCR_DIVSLOW_SHIFT                   (0U)
/*! DIVSLOW - Slow Clock Divide Ratio
 *  0b0000..Reserved
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

#define SCG_RCCR_DIVEXT_MASK                     (0xF00U)
#define SCG_RCCR_DIVEXT_SHIFT                    (8U)
/*! DIVEXT - External Clock Divide Ratio
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
#define SCG_RCCR_DIVEXT(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_DIVEXT_SHIFT)) & SCG_RCCR_DIVEXT_MASK)

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
 *  0b001..Reserved
 *  0b010..Slow IRC (SIRC_CLK)
 *  0b011..Fast IRC (FIRC_CLK)
 *  0b100..RTC OSC (ROSC_CLK)
 *  0b101..Low Power FLL (LPFLL_CLK)
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define SCG_RCCR_SCS(x)                          (((uint32_t)(((uint32_t)(x)) << SCG_RCCR_SCS_SHIFT)) & SCG_RCCR_SCS_MASK)
/*! @} */

/*! @name VCCR - VLPR Clock Control Register */
/*! @{ */

#define SCG_VCCR_DIVSLOW_MASK                    (0xFU)
#define SCG_VCCR_DIVSLOW_SHIFT                   (0U)
/*! DIVSLOW - Slow Clock Divide Ratio
 *  0b0000..Reserved
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

#define SCG_VCCR_DIVEXT_MASK                     (0xF00U)
#define SCG_VCCR_DIVEXT_SHIFT                    (8U)
/*! DIVEXT - External Clock Divide Ratio
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
#define SCG_VCCR_DIVEXT(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_VCCR_DIVEXT_SHIFT)) & SCG_VCCR_DIVEXT_MASK)

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
 *  0b0001..Reserved
 *  0b0010..Slow IRC (SIRC_CLK)
 *  0b0011..Reserved
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
 *  0b0000..Reserved
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

#define SCG_HCCR_DIVEXT_MASK                     (0xF00U)
#define SCG_HCCR_DIVEXT_SHIFT                    (8U)
/*! DIVEXT - External Clock Divide Ratio
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
#define SCG_HCCR_DIVEXT(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_HCCR_DIVEXT_SHIFT)) & SCG_HCCR_DIVEXT_MASK)

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
 *  0b0001..Reserved
 *  0b0010..Slow IRC (SIRC_CLK)
 *  0b0011..Fast IRC (FIRC_CLK)
 *  0b0100..RTC OSC (ROSC_CLK)
 *  0b0101..Low Power FLL (LPFLL_CLK)
 *  0b0110..Reserved
 *  0b0111..Reserved
 */
#define SCG_HCCR_SCS(x)                          (((uint32_t)(((uint32_t)(x)) << SCG_HCCR_SCS_SHIFT)) & SCG_HCCR_SCS_MASK)
/*! @} */

/*! @name CLKOUTCNFG - SCG CLKOUT Configuration Register */
/*! @{ */

#define SCG_CLKOUTCNFG_CLKOUTSEL_MASK            (0xF000000U)
#define SCG_CLKOUTCNFG_CLKOUTSEL_SHIFT           (24U)
/*! CLKOUTSEL - SCG Clkout Select
 *  0b0000..SCG EXTERNAL Clock
 *  0b0001..Reserved
 *  0b0010..Slow IRC (SIRC_CLK)
 *  0b0011..Fast IRC (FIRC_CLK)
 *  0b0100..RTC OSC (ROSC_CLK)
 *  0b0101..Low Power FLL (LPFLL_CLK)
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1111..Reserved
 */
#define SCG_CLKOUTCNFG_CLKOUTSEL(x)              (((uint32_t)(((uint32_t)(x)) << SCG_CLKOUTCNFG_CLKOUTSEL_SHIFT)) & SCG_CLKOUTCNFG_CLKOUTSEL_MASK)
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
 *  0b0..Slow IRC low range clock (2 MHz)
 *  0b1..Slow IRC high range clock (8 MHz )
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

#define SCG_FIRCCSR_FIRCREGOFF_MASK              (0x8U)
#define SCG_FIRCCSR_FIRCREGOFF_SHIFT             (3U)
/*! FIRCREGOFF - Fast IRC Regulator Enable
 *  0b0..Fast IRC Regulator is enabled.
 *  0b1..Fast IRC Regulator is disabled.
 */
#define SCG_FIRCCSR_FIRCREGOFF(x)                (((uint32_t)(((uint32_t)(x)) << SCG_FIRCCSR_FIRCREGOFF_SHIFT)) & SCG_FIRCCSR_FIRCREGOFF_MASK)

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
 *  0b10..Reserved
 *  0b11..RTC OSC (32.768 kHz)
 */
#define SCG_FIRCTCFG_TRIMSRC(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_FIRCTCFG_TRIMSRC_SHIFT)) & SCG_FIRCTCFG_TRIMSRC_MASK)
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

/*! @name LPFLLCSR - Low Power FLL Control Status Register */
/*! @{ */

#define SCG_LPFLLCSR_LPFLLEN_MASK                (0x1U)
#define SCG_LPFLLCSR_LPFLLEN_SHIFT               (0U)
/*! LPFLLEN - LPFLL Enable
 *  0b0..LPFLL is disabled
 *  0b1..LPFLL is enabled
 */
#define SCG_LPFLLCSR_LPFLLEN(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLCSR_LPFLLEN_SHIFT)) & SCG_LPFLLCSR_LPFLLEN_MASK)

#define SCG_LPFLLCSR_LPFLLSTEN_MASK              (0x2U)
#define SCG_LPFLLCSR_LPFLLSTEN_SHIFT             (1U)
/*! LPFLLSTEN - LPFLL Stop Enable
 *  0b0..LPFLL is disabled in Stop modes.
 *  0b1..LPFLL is enabled in Stop modes
 */
#define SCG_LPFLLCSR_LPFLLSTEN(x)                (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLCSR_LPFLLSTEN_SHIFT)) & SCG_LPFLLCSR_LPFLLSTEN_MASK)

#define SCG_LPFLLCSR_LPFLLTREN_MASK              (0x100U)
#define SCG_LPFLLCSR_LPFLLTREN_SHIFT             (8U)
/*! LPFLLTREN - LPFLL Trim Enable
 *  0b0..Disable trimming LPFLL to an reference clock source
 *  0b1..Enable trimming LPFLL to an reference clock source
 */
#define SCG_LPFLLCSR_LPFLLTREN(x)                (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLCSR_LPFLLTREN_SHIFT)) & SCG_LPFLLCSR_LPFLLTREN_MASK)

#define SCG_LPFLLCSR_LPFLLTRUP_MASK              (0x200U)
#define SCG_LPFLLCSR_LPFLLTRUP_SHIFT             (9U)
/*! LPFLLTRUP - LPFLL Trim Update
 *  0b0..Disable LPFLL trimming updates. LPFLL frequency determined by AUTOTRIM written value.
 *  0b1..Enable LPFLL trimming updates. LPFLL frequency determined by reference clock multiplication
 */
#define SCG_LPFLLCSR_LPFLLTRUP(x)                (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLCSR_LPFLLTRUP_SHIFT)) & SCG_LPFLLCSR_LPFLLTRUP_MASK)

#define SCG_LPFLLCSR_LPFLLTRMLOCK_MASK           (0x400U)
#define SCG_LPFLLCSR_LPFLLTRMLOCK_SHIFT          (10U)
/*! LPFLLTRMLOCK - LPFLL Trim LOCK
 *  0b0..LPFLL not locked
 *  0b1..LPFLL trimmed and locked
 */
#define SCG_LPFLLCSR_LPFLLTRMLOCK(x)             (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLCSR_LPFLLTRMLOCK_SHIFT)) & SCG_LPFLLCSR_LPFLLTRMLOCK_MASK)

#define SCG_LPFLLCSR_LPFLLCM_MASK                (0x10000U)
#define SCG_LPFLLCSR_LPFLLCM_SHIFT               (16U)
/*! LPFLLCM - LPFLL Clock Monitor
 *  0b0..LPFLL Clock Monitor is disabled
 *  0b1..LPFLL Clock Monitor is enabled
 */
#define SCG_LPFLLCSR_LPFLLCM(x)                  (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLCSR_LPFLLCM_SHIFT)) & SCG_LPFLLCSR_LPFLLCM_MASK)

#define SCG_LPFLLCSR_LPFLLCMRE_MASK              (0x20000U)
#define SCG_LPFLLCSR_LPFLLCMRE_SHIFT             (17U)
/*! LPFLLCMRE - LPFLL Clock Monitor Reset Enable
 *  0b0..Clock Monitor generates interrupt when error detected
 *  0b1..Clock Monitor generates reset when error detected
 */
#define SCG_LPFLLCSR_LPFLLCMRE(x)                (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLCSR_LPFLLCMRE_SHIFT)) & SCG_LPFLLCSR_LPFLLCMRE_MASK)

#define SCG_LPFLLCSR_LK_MASK                     (0x800000U)
#define SCG_LPFLLCSR_LK_SHIFT                    (23U)
/*! LK - Lock Register
 *  0b0..Control Status Register can be written.
 *  0b1..Control Status Register cannot be written.
 */
#define SCG_LPFLLCSR_LK(x)                       (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLCSR_LK_SHIFT)) & SCG_LPFLLCSR_LK_MASK)

#define SCG_LPFLLCSR_LPFLLVLD_MASK               (0x1000000U)
#define SCG_LPFLLCSR_LPFLLVLD_SHIFT              (24U)
/*! LPFLLVLD - LPFLL Valid
 *  0b0..LPFLL is not enabled or clock is not valid.
 *  0b1..LPFLL is enabled and output clock is valid.
 */
#define SCG_LPFLLCSR_LPFLLVLD(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLCSR_LPFLLVLD_SHIFT)) & SCG_LPFLLCSR_LPFLLVLD_MASK)

#define SCG_LPFLLCSR_LPFLLSEL_MASK               (0x2000000U)
#define SCG_LPFLLCSR_LPFLLSEL_SHIFT              (25U)
/*! LPFLLSEL - LPFLL Selected
 *  0b0..LPFLL is not the system clock source
 *  0b1..LPFLL is the system clock source
 */
#define SCG_LPFLLCSR_LPFLLSEL(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLCSR_LPFLLSEL_SHIFT)) & SCG_LPFLLCSR_LPFLLSEL_MASK)

#define SCG_LPFLLCSR_LPFLLERR_MASK               (0x4000000U)
#define SCG_LPFLLCSR_LPFLLERR_SHIFT              (26U)
/*! LPFLLERR - LPFLL Clock Error
 *  0b0..Error not detected with the LPFLL trimming.
 *  0b1..Error detected with the LPFLL trimming.
 */
#define SCG_LPFLLCSR_LPFLLERR(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLCSR_LPFLLERR_SHIFT)) & SCG_LPFLLCSR_LPFLLERR_MASK)
/*! @} */

/*! @name LPFLLDIV - Low Power FLL Divide Register */
/*! @{ */

#define SCG_LPFLLDIV_LPFLLDIV1_MASK              (0x7U)
#define SCG_LPFLLDIV_LPFLLDIV1_SHIFT             (0U)
/*! LPFLLDIV1 - LPFLL Clock Divide 1
 *  0b000..Output disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_LPFLLDIV_LPFLLDIV1(x)                (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLDIV_LPFLLDIV1_SHIFT)) & SCG_LPFLLDIV_LPFLLDIV1_MASK)

#define SCG_LPFLLDIV_LPFLLDIV2_MASK              (0x700U)
#define SCG_LPFLLDIV_LPFLLDIV2_SHIFT             (8U)
/*! LPFLLDIV2 - LPFLL Clock Divide 2
 *  0b000..Output disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_LPFLLDIV_LPFLLDIV2(x)                (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLDIV_LPFLLDIV2_SHIFT)) & SCG_LPFLLDIV_LPFLLDIV2_MASK)

#define SCG_LPFLLDIV_LPFLLDIV3_MASK              (0x70000U)
#define SCG_LPFLLDIV_LPFLLDIV3_SHIFT             (16U)
/*! LPFLLDIV3 - LPFLL Clock Divide 3
 *  0b000..Clock disabled
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 4
 *  0b100..Divide by 8
 *  0b101..Divide by 16
 *  0b110..Divide by 32
 *  0b111..Divide by 64
 */
#define SCG_LPFLLDIV_LPFLLDIV3(x)                (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLDIV_LPFLLDIV3_SHIFT)) & SCG_LPFLLDIV_LPFLLDIV3_MASK)
/*! @} */

/*! @name LPFLLCFG - Low Power FLL Configuration Register */
/*! @{ */

#define SCG_LPFLLCFG_FSEL_MASK                   (0x3U)
#define SCG_LPFLLCFG_FSEL_SHIFT                  (0U)
/*! FSEL - Frequency Select
 *  0b00..LPFLL is trimmed to 48 MHz.
 *  0b01..LPFLL is trimmed to 72 MHz.
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define SCG_LPFLLCFG_FSEL(x)                     (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLCFG_FSEL_SHIFT)) & SCG_LPFLLCFG_FSEL_MASK)
/*! @} */

/*! @name LPFLLTCFG - Low Power FLL Trim Configuration Register */
/*! @{ */

#define SCG_LPFLLTCFG_TRIMSRC_MASK               (0x3U)
#define SCG_LPFLLTCFG_TRIMSRC_SHIFT              (0U)
/*! TRIMSRC - Trim Source
 *  0b00..SIRC
 *  0b01..FIRC
 *  0b10..Reserved
 *  0b11..RTC OSC
 */
#define SCG_LPFLLTCFG_TRIMSRC(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLTCFG_TRIMSRC_SHIFT)) & SCG_LPFLLTCFG_TRIMSRC_MASK)

#define SCG_LPFLLTCFG_TRIMDIV_MASK               (0x1F00U)
#define SCG_LPFLLTCFG_TRIMDIV_SHIFT              (8U)
/*! TRIMDIV - LPFLL Trim Predivide */
#define SCG_LPFLLTCFG_TRIMDIV(x)                 (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLTCFG_TRIMDIV_SHIFT)) & SCG_LPFLLTCFG_TRIMDIV_MASK)

#define SCG_LPFLLTCFG_LOCKW2LSB_MASK             (0x10000U)
#define SCG_LPFLLTCFG_LOCKW2LSB_SHIFT            (16U)
/*! LOCKW2LSB - Lock LPFLL with 2 LSBS
 *  0b0..LPFLL locks within 1LSB (0.4%)
 *  0b1..LPFLL locks within 2LSB (0.8%)
 */
#define SCG_LPFLLTCFG_LOCKW2LSB(x)               (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLTCFG_LOCKW2LSB_SHIFT)) & SCG_LPFLLTCFG_LOCKW2LSB_MASK)
/*! @} */

/*! @name LPFLLSTAT - Low Power FLL Status Register */
/*! @{ */

#define SCG_LPFLLSTAT_AUTOTRIM_MASK              (0xFFU)
#define SCG_LPFLLSTAT_AUTOTRIM_SHIFT             (0U)
/*! AUTOTRIM - Auto Tune Trim Status */
#define SCG_LPFLLSTAT_AUTOTRIM(x)                (((uint32_t)(((uint32_t)(x)) << SCG_LPFLLSTAT_AUTOTRIM_SHIFT)) & SCG_LPFLLSTAT_AUTOTRIM_MASK)
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

