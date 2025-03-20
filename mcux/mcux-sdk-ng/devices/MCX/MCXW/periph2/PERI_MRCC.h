/*
** ###################################################################
**     Processors:          MCXW716AMFPA
**                          MCXW716AMFTA
**                          MCXW716CMFPA
**                          MCXW716CMFTA
**
**     Version:             rev. 1.0, 2024-03-21
**     Build:               b240705
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MRCC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-21)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file MRCC.h
 * @version 1.0
 * @date 2024-03-21
 * @brief CMSIS Peripheral Access Layer for MRCC
 *
 * CMSIS Peripheral Access Layer for MRCC
 */

#if !defined(MRCC_H_)
#define MRCC_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW716AMFPA) || defined(CPU_MCXW716AMFTA))
#include "MCXW716A_COMMON.h"
#elif (defined(CPU_MCXW716CMFPA) || defined(CPU_MCXW716CMFTA))
#include "MCXW716C_COMMON.h"
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
   -- MRCC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRCC_Peripheral_Access_Layer MRCC Peripheral Access Layer
 * @{
 */

/** MRCC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[76];
  __IO uint32_t MRCC_EWM0;                         /**< EWM0 Reset and Clock Control, offset: 0x4C */
       uint8_t RESERVED_1[12];
  __IO uint32_t MRCC_SYSPM0;                       /**< SYSPM0 Reset and Clock Control, offset: 0x5C */
       uint8_t RESERVED_2[8];
  __IO uint32_t MRCC_WDOG0;                        /**< WDOG0 Reset and Clock Control, offset: 0x68 */
  __IO uint32_t MRCC_WDOG1;                        /**< WDOG1 Reset and Clock Control, offset: 0x6C */
       uint8_t RESERVED_3[4];
  __IO uint32_t MRCC_SFA0;                         /**< SFA0 Reset and Clock Control, offset: 0x74 */
       uint8_t RESERVED_4[20];
  __IO uint32_t MRCC_CRC0;                         /**< CRC0 Reset and Clock Control, offset: 0x8C */
  __IO uint32_t MRCC_SECSUBSYS;                    /**< ELE Reset and Clock Control, offset: 0x90 */
       uint8_t RESERVED_5[40];
  __IO uint32_t MRCC_LPIT0;                        /**< LPIT0 Reset and Clock Control, offset: 0xBC */
  __IO uint32_t MRCC_TSTMR0;                       /**< TSTMR0 Reset and Clock Control, offset: 0xC0 */
  __IO uint32_t MRCC_TPM0;                         /**< TPM0 Reset and Clock Control, offset: 0xC4 */
  __IO uint32_t MRCC_TPM1;                         /**< TPM1 Reset and Clock Control, offset: 0xC8 */
  __IO uint32_t MRCC_LPI2C0;                       /**< LPI2C0 Reset and Clock Control, offset: 0xCC */
  __IO uint32_t MRCC_LPI2C1;                       /**< LPI2C1 Reset and Clock Control, offset: 0xD0 */
  __IO uint32_t MRCC_I3C0;                         /**< I3C0 Reset and Clock Control, offset: 0xD4 */
  __IO uint32_t MRCC_LPSPI0;                       /**< LPSPI0 Reset and Clock Control, offset: 0xD8 */
  __IO uint32_t MRCC_LPSPI1;                       /**< LPSPI1 Reset and Clock Control, offset: 0xDC */
  __IO uint32_t MRCC_LPUART0;                      /**< LPUART0 Reset and Clock Control, offset: 0xE0 */
  __IO uint32_t MRCC_LPUART1;                      /**< LPUART1 Reset and Clock Control, offset: 0xE4 */
  __IO uint32_t MRCC_FLEXIO0;                      /**< FLEXIO0 Reset and Clock Control, offset: 0xE8 */
  __IO uint32_t MRCC_CAN0;                         /**< CAN0 Reset and Clock Control, offset: 0xEC */
       uint8_t RESERVED_6[12];
  __IO uint32_t MRCC_SEMA0;                        /**< SEMA42 Reset and Clock Control, offset: 0xFC */
       uint8_t RESERVED_7[4];
  __IO uint32_t MRCC_DATA_STREAM_2P4;              /**< DSB Reset and Clock Control, offset: 0x104 */
  __IO uint32_t MRCC_PORTA;                        /**< PORTA Reset and Clock Control, offset: 0x108 */
  __IO uint32_t MRCC_PORTB;                        /**< PORTB Reset and Clock Control, offset: 0x10C */
  __IO uint32_t MRCC_PORTC;                        /**< PORTC Reset and Clock Control, offset: 0x110 */
       uint8_t RESERVED_8[8];
  __IO uint32_t MRCC_LPADC0;                       /**< ADC0 Reset and Clock Control, offset: 0x11C */
  __IO uint32_t MRCC_LPCMP0;                       /**< LPCMP0 Reset and Clock Control, offset: 0x120 */
  __IO uint32_t MRCC_LPCMP1;                       /**< LPCMP1 Reset and Clock Control, offset: 0x124 */
  __IO uint32_t MRCC_VREF0;                        /**< VREF0 Reset and Clock Control, offset: 0x128 */
       uint8_t RESERVED_9[728];
  __IO uint32_t MRCC_GPIOA;                        /**< GPIOA Reset and Clock Control, offset: 0x404 */
  __IO uint32_t MRCC_GPIOB;                        /**< GPIOB Reset and Clock Control, offset: 0x408 */
  __IO uint32_t MRCC_GPIOC;                        /**< GPIOC Reset and Clock Control, offset: 0x40C */
  __IO uint32_t MRCC_DMA0;                         /**< DMA0 Reset and Clock Control, offset: 0x410 */
  __IO uint32_t MRCC_PFLEXNVM;                     /**< FMC-NPX Reset and Clock Control, offset: 0x414 */
       uint8_t RESERVED_10[4];
  __IO uint32_t MRCC_SRAM0;                        /**< CTCM Reset and Clock Control, offset: 0x41C */
  __IO uint32_t MRCC_SRAM1;                        /**< STCM0 Reset and Clock Control, offset: 0x420 */
  __IO uint32_t MRCC_SRAM2;                        /**< STCM1 Reset and Clock Control, offset: 0x424 */
  __IO uint32_t MRCC_SRAM3;                        /**< STCM2 Reset and Clock Control, offset: 0x428 */
} MRCC_Type;

/* ----------------------------------------------------------------------------
   -- MRCC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRCC_Register_Masks MRCC Register Masks
 * @{
 */

/*! @name MRCC_EWM0 - EWM0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_EWM0_CC_MASK                   (0x3U)
#define MRCC_MRCC_EWM0_CC_SHIFT                  (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_EWM0_CC(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EWM0_CC_SHIFT)) & MRCC_MRCC_EWM0_CC_MASK)

#define MRCC_MRCC_EWM0_RSTB_MASK                 (0x40000000U)
#define MRCC_MRCC_EWM0_RSTB_SHIFT                (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_EWM0_RSTB(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EWM0_RSTB_SHIFT)) & MRCC_MRCC_EWM0_RSTB_MASK)

#define MRCC_MRCC_EWM0_PR_MASK                   (0x80000000U)
#define MRCC_MRCC_EWM0_PR_SHIFT                  (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_EWM0_PR(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_EWM0_PR_SHIFT)) & MRCC_MRCC_EWM0_PR_MASK)
/*! @} */

/*! @name MRCC_SYSPM0 - SYSPM0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_SYSPM0_CC_MASK                 (0x3U)
#define MRCC_MRCC_SYSPM0_CC_SHIFT                (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_SYSPM0_CC(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SYSPM0_CC_SHIFT)) & MRCC_MRCC_SYSPM0_CC_MASK)
/*! @} */

/*! @name MRCC_WDOG0 - WDOG0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_WDOG0_CC_MASK                  (0x3U)
#define MRCC_MRCC_WDOG0_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_WDOG0_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDOG0_CC_SHIFT)) & MRCC_MRCC_WDOG0_CC_MASK)
/*! @} */

/*! @name MRCC_WDOG1 - WDOG1 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_WDOG1_CC_MASK                  (0x3U)
#define MRCC_MRCC_WDOG1_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_WDOG1_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WDOG1_CC_SHIFT)) & MRCC_MRCC_WDOG1_CC_MASK)
/*! @} */

/*! @name MRCC_SFA0 - SFA0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_SFA0_CC_MASK                   (0x3U)
#define MRCC_MRCC_SFA0_CC_SHIFT                  (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_SFA0_CC(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SFA0_CC_SHIFT)) & MRCC_MRCC_SFA0_CC_MASK)

#define MRCC_MRCC_SFA0_RSTB_MASK                 (0x40000000U)
#define MRCC_MRCC_SFA0_RSTB_SHIFT                (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_SFA0_RSTB(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SFA0_RSTB_SHIFT)) & MRCC_MRCC_SFA0_RSTB_MASK)

#define MRCC_MRCC_SFA0_PR_MASK                   (0x80000000U)
#define MRCC_MRCC_SFA0_PR_SHIFT                  (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_SFA0_PR(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SFA0_PR_SHIFT)) & MRCC_MRCC_SFA0_PR_MASK)
/*! @} */

/*! @name MRCC_CRC0 - CRC0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_CRC0_CC_MASK                   (0x3U)
#define MRCC_MRCC_CRC0_CC_SHIFT                  (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_CRC0_CC(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CRC0_CC_SHIFT)) & MRCC_MRCC_CRC0_CC_MASK)

#define MRCC_MRCC_CRC0_RSTB_MASK                 (0x40000000U)
#define MRCC_MRCC_CRC0_RSTB_SHIFT                (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_CRC0_RSTB(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CRC0_RSTB_SHIFT)) & MRCC_MRCC_CRC0_RSTB_MASK)

#define MRCC_MRCC_CRC0_PR_MASK                   (0x80000000U)
#define MRCC_MRCC_CRC0_PR_SHIFT                  (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_CRC0_PR(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CRC0_PR_SHIFT)) & MRCC_MRCC_CRC0_PR_MASK)
/*! @} */

/*! @name MRCC_SECSUBSYS - ELE Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_SECSUBSYS_CC_MASK              (0x3U)
#define MRCC_MRCC_SECSUBSYS_CC_SHIFT             (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_SECSUBSYS_CC(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SECSUBSYS_CC_SHIFT)) & MRCC_MRCC_SECSUBSYS_CC_MASK)

#define MRCC_MRCC_SECSUBSYS_RSTB_MASK            (0x40000000U)
#define MRCC_MRCC_SECSUBSYS_RSTB_SHIFT           (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_SECSUBSYS_RSTB(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SECSUBSYS_RSTB_SHIFT)) & MRCC_MRCC_SECSUBSYS_RSTB_MASK)

#define MRCC_MRCC_SECSUBSYS_PR_MASK              (0x80000000U)
#define MRCC_MRCC_SECSUBSYS_PR_SHIFT             (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_SECSUBSYS_PR(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SECSUBSYS_PR_SHIFT)) & MRCC_MRCC_SECSUBSYS_PR_MASK)
/*! @} */

/*! @name MRCC_LPIT0 - LPIT0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_LPIT0_CC_MASK                  (0x3U)
#define MRCC_MRCC_LPIT0_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_LPIT0_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPIT0_CC_SHIFT)) & MRCC_MRCC_LPIT0_CC_MASK)

#define MRCC_MRCC_LPIT0_MUX_MASK                 (0x70U)
#define MRCC_MRCC_LPIT0_MUX_SHIFT                (4U)
/*! MUX - Functional Clock Mux Select
 *  0b100..SOSC-CLK
 *  0b011..FRO-192M
 *  0b010..FRO-6M
 *  0b000..The clock is off
 */
#define MRCC_MRCC_LPIT0_MUX(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPIT0_MUX_SHIFT)) & MRCC_MRCC_LPIT0_MUX_MASK)

#define MRCC_MRCC_LPIT0_DIV_MASK                 (0xF00U)
#define MRCC_MRCC_LPIT0_DIV_SHIFT                (8U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPIT0_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPIT0_DIV_SHIFT)) & MRCC_MRCC_LPIT0_DIV_MASK)

#define MRCC_MRCC_LPIT0_RSTB_MASK                (0x40000000U)
#define MRCC_MRCC_LPIT0_RSTB_SHIFT               (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPIT0_RSTB(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPIT0_RSTB_SHIFT)) & MRCC_MRCC_LPIT0_RSTB_MASK)

#define MRCC_MRCC_LPIT0_PR_MASK                  (0x80000000U)
#define MRCC_MRCC_LPIT0_PR_SHIFT                 (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPIT0_PR(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPIT0_PR_SHIFT)) & MRCC_MRCC_LPIT0_PR_MASK)
/*! @} */

/*! @name MRCC_TSTMR0 - TSTMR0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_TSTMR0_CC_MASK                 (0x3U)
#define MRCC_MRCC_TSTMR0_CC_SHIFT                (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_TSTMR0_CC(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TSTMR0_CC_SHIFT)) & MRCC_MRCC_TSTMR0_CC_MASK)
/*! @} */

/*! @name MRCC_TPM0 - TPM0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_TPM0_CC_MASK                   (0x3U)
#define MRCC_MRCC_TPM0_CC_SHIFT                  (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_TPM0_CC(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM0_CC_SHIFT)) & MRCC_MRCC_TPM0_CC_MASK)

#define MRCC_MRCC_TPM0_MUX_MASK                  (0x70U)
#define MRCC_MRCC_TPM0_MUX_SHIFT                 (4U)
/*! MUX - Functional Clock Mux Select
 *  0b101..32K-CLK
 *  0b100..SOSC-CLK
 *  0b011..FRO-192M
 *  0b010..FRO-6M
 *  0b000..The clock is off
 */
#define MRCC_MRCC_TPM0_MUX(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM0_MUX_SHIFT)) & MRCC_MRCC_TPM0_MUX_MASK)

#define MRCC_MRCC_TPM0_DIV_MASK                  (0xF00U)
#define MRCC_MRCC_TPM0_DIV_SHIFT                 (8U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_TPM0_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM0_DIV_SHIFT)) & MRCC_MRCC_TPM0_DIV_MASK)

#define MRCC_MRCC_TPM0_RSTB_MASK                 (0x40000000U)
#define MRCC_MRCC_TPM0_RSTB_SHIFT                (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_TPM0_RSTB(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM0_RSTB_SHIFT)) & MRCC_MRCC_TPM0_RSTB_MASK)

#define MRCC_MRCC_TPM0_PR_MASK                   (0x80000000U)
#define MRCC_MRCC_TPM0_PR_SHIFT                  (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_TPM0_PR(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM0_PR_SHIFT)) & MRCC_MRCC_TPM0_PR_MASK)
/*! @} */

/*! @name MRCC_TPM1 - TPM1 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_TPM1_CC_MASK                   (0x3U)
#define MRCC_MRCC_TPM1_CC_SHIFT                  (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_TPM1_CC(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM1_CC_SHIFT)) & MRCC_MRCC_TPM1_CC_MASK)

#define MRCC_MRCC_TPM1_MUX_MASK                  (0x70U)
#define MRCC_MRCC_TPM1_MUX_SHIFT                 (4U)
/*! MUX - Functional Clock Mux Select
 *  0b101..32K-CLK
 *  0b100..SOSC-CLK
 *  0b011..FRO-192M
 *  0b010..FRO-6M
 *  0b000..The clock is off
 */
#define MRCC_MRCC_TPM1_MUX(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM1_MUX_SHIFT)) & MRCC_MRCC_TPM1_MUX_MASK)

#define MRCC_MRCC_TPM1_DIV_MASK                  (0xF00U)
#define MRCC_MRCC_TPM1_DIV_SHIFT                 (8U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_TPM1_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM1_DIV_SHIFT)) & MRCC_MRCC_TPM1_DIV_MASK)

#define MRCC_MRCC_TPM1_RSTB_MASK                 (0x40000000U)
#define MRCC_MRCC_TPM1_RSTB_SHIFT                (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_TPM1_RSTB(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM1_RSTB_SHIFT)) & MRCC_MRCC_TPM1_RSTB_MASK)

#define MRCC_MRCC_TPM1_PR_MASK                   (0x80000000U)
#define MRCC_MRCC_TPM1_PR_SHIFT                  (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_TPM1_PR(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_TPM1_PR_SHIFT)) & MRCC_MRCC_TPM1_PR_MASK)
/*! @} */

/*! @name MRCC_LPI2C0 - LPI2C0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_LPI2C0_CC_MASK                 (0x3U)
#define MRCC_MRCC_LPI2C0_CC_SHIFT                (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_LPI2C0_CC(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CC_SHIFT)) & MRCC_MRCC_LPI2C0_CC_MASK)

#define MRCC_MRCC_LPI2C0_MUX_MASK                (0x70U)
#define MRCC_MRCC_LPI2C0_MUX_SHIFT               (4U)
/*! MUX - Functional Clock Mux Select
 *  0b100..SOSC-CLK
 *  0b011..FRO-192M
 *  0b010..FRO-6M
 *  0b000..The clock is off
 */
#define MRCC_MRCC_LPI2C0_MUX(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_MUX_SHIFT)) & MRCC_MRCC_LPI2C0_MUX_MASK)

#define MRCC_MRCC_LPI2C0_DIV_MASK                (0xF00U)
#define MRCC_MRCC_LPI2C0_DIV_SHIFT               (8U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPI2C0_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_DIV_SHIFT)) & MRCC_MRCC_LPI2C0_DIV_MASK)

#define MRCC_MRCC_LPI2C0_RSTB_MASK               (0x40000000U)
#define MRCC_MRCC_LPI2C0_RSTB_SHIFT              (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPI2C0_RSTB(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_RSTB_SHIFT)) & MRCC_MRCC_LPI2C0_RSTB_MASK)

#define MRCC_MRCC_LPI2C0_PR_MASK                 (0x80000000U)
#define MRCC_MRCC_LPI2C0_PR_SHIFT                (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPI2C0_PR(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_PR_SHIFT)) & MRCC_MRCC_LPI2C0_PR_MASK)
/*! @} */

/*! @name MRCC_LPI2C1 - LPI2C1 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_LPI2C1_CC_MASK                 (0x3U)
#define MRCC_MRCC_LPI2C1_CC_SHIFT                (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_LPI2C1_CC(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CC_SHIFT)) & MRCC_MRCC_LPI2C1_CC_MASK)

#define MRCC_MRCC_LPI2C1_MUX_MASK                (0x70U)
#define MRCC_MRCC_LPI2C1_MUX_SHIFT               (4U)
/*! MUX - Functional Clock Mux Select
 *  0b100..SOSC-CLK
 *  0b011..FRO-192M
 *  0b010..FRO-6M
 *  0b000..The clock is off
 */
#define MRCC_MRCC_LPI2C1_MUX(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_MUX_SHIFT)) & MRCC_MRCC_LPI2C1_MUX_MASK)

#define MRCC_MRCC_LPI2C1_DIV_MASK                (0xF00U)
#define MRCC_MRCC_LPI2C1_DIV_SHIFT               (8U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPI2C1_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_DIV_SHIFT)) & MRCC_MRCC_LPI2C1_DIV_MASK)

#define MRCC_MRCC_LPI2C1_RSTB_MASK               (0x40000000U)
#define MRCC_MRCC_LPI2C1_RSTB_SHIFT              (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPI2C1_RSTB(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_RSTB_SHIFT)) & MRCC_MRCC_LPI2C1_RSTB_MASK)

#define MRCC_MRCC_LPI2C1_PR_MASK                 (0x80000000U)
#define MRCC_MRCC_LPI2C1_PR_SHIFT                (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPI2C1_PR(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_PR_SHIFT)) & MRCC_MRCC_LPI2C1_PR_MASK)
/*! @} */

/*! @name MRCC_I3C0 - I3C0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_I3C0_CC_MASK                   (0x3U)
#define MRCC_MRCC_I3C0_CC_SHIFT                  (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_I3C0_CC(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_CC_SHIFT)) & MRCC_MRCC_I3C0_CC_MASK)

#define MRCC_MRCC_I3C0_MUX_MASK                  (0x70U)
#define MRCC_MRCC_I3C0_MUX_SHIFT                 (4U)
/*! MUX - Functional Clock Mux Select
 *  0b100..SOSC-CLK
 *  0b011..FRO-192M
 *  0b010..FRO-6M
 *  0b000..The clock is off
 */
#define MRCC_MRCC_I3C0_MUX(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_MUX_SHIFT)) & MRCC_MRCC_I3C0_MUX_MASK)

#define MRCC_MRCC_I3C0_DIV_MASK                  (0xF00U)
#define MRCC_MRCC_I3C0_DIV_SHIFT                 (8U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_I3C0_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_DIV_SHIFT)) & MRCC_MRCC_I3C0_DIV_MASK)

#define MRCC_MRCC_I3C0_RSTB_MASK                 (0x40000000U)
#define MRCC_MRCC_I3C0_RSTB_SHIFT                (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_I3C0_RSTB(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_RSTB_SHIFT)) & MRCC_MRCC_I3C0_RSTB_MASK)

#define MRCC_MRCC_I3C0_PR_MASK                   (0x80000000U)
#define MRCC_MRCC_I3C0_PR_SHIFT                  (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_I3C0_PR(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_PR_SHIFT)) & MRCC_MRCC_I3C0_PR_MASK)
/*! @} */

/*! @name MRCC_LPSPI0 - LPSPI0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_LPSPI0_CC_MASK                 (0x3U)
#define MRCC_MRCC_LPSPI0_CC_SHIFT                (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_LPSPI0_CC(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CC_SHIFT)) & MRCC_MRCC_LPSPI0_CC_MASK)

#define MRCC_MRCC_LPSPI0_MUX_MASK                (0x70U)
#define MRCC_MRCC_LPSPI0_MUX_SHIFT               (4U)
/*! MUX - Functional Clock Mux Select
 *  0b100..SOSC-CLK
 *  0b011..FRO-192M
 *  0b010..FRO-6M
 *  0b000..The clock is off
 */
#define MRCC_MRCC_LPSPI0_MUX(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_MUX_SHIFT)) & MRCC_MRCC_LPSPI0_MUX_MASK)

#define MRCC_MRCC_LPSPI0_DIV_MASK                (0xF00U)
#define MRCC_MRCC_LPSPI0_DIV_SHIFT               (8U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPSPI0_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_DIV_SHIFT)) & MRCC_MRCC_LPSPI0_DIV_MASK)

#define MRCC_MRCC_LPSPI0_RSTB_MASK               (0x40000000U)
#define MRCC_MRCC_LPSPI0_RSTB_SHIFT              (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPSPI0_RSTB(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_RSTB_SHIFT)) & MRCC_MRCC_LPSPI0_RSTB_MASK)

#define MRCC_MRCC_LPSPI0_PR_MASK                 (0x80000000U)
#define MRCC_MRCC_LPSPI0_PR_SHIFT                (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPSPI0_PR(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_PR_SHIFT)) & MRCC_MRCC_LPSPI0_PR_MASK)
/*! @} */

/*! @name MRCC_LPSPI1 - LPSPI1 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_LPSPI1_CC_MASK                 (0x3U)
#define MRCC_MRCC_LPSPI1_CC_SHIFT                (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_LPSPI1_CC(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CC_SHIFT)) & MRCC_MRCC_LPSPI1_CC_MASK)

#define MRCC_MRCC_LPSPI1_MUX_MASK                (0x70U)
#define MRCC_MRCC_LPSPI1_MUX_SHIFT               (4U)
/*! MUX - Functional Clock Mux Select
 *  0b100..SOSC-CLK
 *  0b011..FRO-192M
 *  0b010..FRO-6M
 *  0b000..The clock is off
 */
#define MRCC_MRCC_LPSPI1_MUX(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_MUX_SHIFT)) & MRCC_MRCC_LPSPI1_MUX_MASK)

#define MRCC_MRCC_LPSPI1_DIV_MASK                (0xF00U)
#define MRCC_MRCC_LPSPI1_DIV_SHIFT               (8U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPSPI1_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_DIV_SHIFT)) & MRCC_MRCC_LPSPI1_DIV_MASK)

#define MRCC_MRCC_LPSPI1_RSTB_MASK               (0x40000000U)
#define MRCC_MRCC_LPSPI1_RSTB_SHIFT              (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPSPI1_RSTB(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_RSTB_SHIFT)) & MRCC_MRCC_LPSPI1_RSTB_MASK)

#define MRCC_MRCC_LPSPI1_PR_MASK                 (0x80000000U)
#define MRCC_MRCC_LPSPI1_PR_SHIFT                (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPSPI1_PR(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_PR_SHIFT)) & MRCC_MRCC_LPSPI1_PR_MASK)
/*! @} */

/*! @name MRCC_LPUART0 - LPUART0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_LPUART0_CC_MASK                (0x3U)
#define MRCC_MRCC_LPUART0_CC_SHIFT               (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_LPUART0_CC(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CC_SHIFT)) & MRCC_MRCC_LPUART0_CC_MASK)

#define MRCC_MRCC_LPUART0_MUX_MASK               (0x70U)
#define MRCC_MRCC_LPUART0_MUX_SHIFT              (4U)
/*! MUX - Functional Clock Mux Select
 *  0b101..32K-CLK
 *  0b100..SOSC-CLK
 *  0b011..FRO-192M
 *  0b010..FRO-6M
 *  0b000..The clock is off
 */
#define MRCC_MRCC_LPUART0_MUX(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_MUX_SHIFT)) & MRCC_MRCC_LPUART0_MUX_MASK)

#define MRCC_MRCC_LPUART0_DIV_MASK               (0xF00U)
#define MRCC_MRCC_LPUART0_DIV_SHIFT              (8U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPUART0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_DIV_SHIFT)) & MRCC_MRCC_LPUART0_DIV_MASK)

#define MRCC_MRCC_LPUART0_RSTB_MASK              (0x40000000U)
#define MRCC_MRCC_LPUART0_RSTB_SHIFT             (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPUART0_RSTB(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_RSTB_SHIFT)) & MRCC_MRCC_LPUART0_RSTB_MASK)

#define MRCC_MRCC_LPUART0_PR_MASK                (0x80000000U)
#define MRCC_MRCC_LPUART0_PR_SHIFT               (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPUART0_PR(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_PR_SHIFT)) & MRCC_MRCC_LPUART0_PR_MASK)
/*! @} */

/*! @name MRCC_LPUART1 - LPUART1 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_LPUART1_CC_MASK                (0x3U)
#define MRCC_MRCC_LPUART1_CC_SHIFT               (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_LPUART1_CC(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CC_SHIFT)) & MRCC_MRCC_LPUART1_CC_MASK)

#define MRCC_MRCC_LPUART1_MUX_MASK               (0x70U)
#define MRCC_MRCC_LPUART1_MUX_SHIFT              (4U)
/*! MUX - Functional Clock Mux Select
 *  0b101..32K-CLK
 *  0b100..SOSC-CLK
 *  0b011..FRO-192M
 *  0b010..FRO-6M
 *  0b000..The clock is off
 */
#define MRCC_MRCC_LPUART1_MUX(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_MUX_SHIFT)) & MRCC_MRCC_LPUART1_MUX_MASK)

#define MRCC_MRCC_LPUART1_DIV_MASK               (0xF00U)
#define MRCC_MRCC_LPUART1_DIV_SHIFT              (8U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPUART1_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_DIV_SHIFT)) & MRCC_MRCC_LPUART1_DIV_MASK)

#define MRCC_MRCC_LPUART1_RSTB_MASK              (0x40000000U)
#define MRCC_MRCC_LPUART1_RSTB_SHIFT             (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPUART1_RSTB(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_RSTB_SHIFT)) & MRCC_MRCC_LPUART1_RSTB_MASK)

#define MRCC_MRCC_LPUART1_PR_MASK                (0x80000000U)
#define MRCC_MRCC_LPUART1_PR_SHIFT               (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPUART1_PR(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_PR_SHIFT)) & MRCC_MRCC_LPUART1_PR_MASK)
/*! @} */

/*! @name MRCC_FLEXIO0 - FLEXIO0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_FLEXIO0_CC_MASK                (0x3U)
#define MRCC_MRCC_FLEXIO0_CC_SHIFT               (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_FLEXIO0_CC(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_CC_SHIFT)) & MRCC_MRCC_FLEXIO0_CC_MASK)

#define MRCC_MRCC_FLEXIO0_MUX_MASK               (0x70U)
#define MRCC_MRCC_FLEXIO0_MUX_SHIFT              (4U)
/*! MUX - Functional Clock Mux Select
 *  0b100..SOSC-CLK
 *  0b011..FRO-192M
 *  0b010..FRO-6M
 *  0b000..The clock is off
 */
#define MRCC_MRCC_FLEXIO0_MUX(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_MUX_SHIFT)) & MRCC_MRCC_FLEXIO0_MUX_MASK)

#define MRCC_MRCC_FLEXIO0_DIV_MASK               (0xF00U)
#define MRCC_MRCC_FLEXIO0_DIV_SHIFT              (8U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_FLEXIO0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_DIV_SHIFT)) & MRCC_MRCC_FLEXIO0_DIV_MASK)

#define MRCC_MRCC_FLEXIO0_RSTB_MASK              (0x40000000U)
#define MRCC_MRCC_FLEXIO0_RSTB_SHIFT             (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_FLEXIO0_RSTB(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_RSTB_SHIFT)) & MRCC_MRCC_FLEXIO0_RSTB_MASK)

#define MRCC_MRCC_FLEXIO0_PR_MASK                (0x80000000U)
#define MRCC_MRCC_FLEXIO0_PR_SHIFT               (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_FLEXIO0_PR(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_PR_SHIFT)) & MRCC_MRCC_FLEXIO0_PR_MASK)
/*! @} */

/*! @name MRCC_CAN0 - CAN0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_CAN0_CC_MASK                   (0x3U)
#define MRCC_MRCC_CAN0_CC_SHIFT                  (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_CAN0_CC(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CAN0_CC_SHIFT)) & MRCC_MRCC_CAN0_CC_MASK)

#define MRCC_MRCC_CAN0_MUX_MASK                  (0x70U)
#define MRCC_MRCC_CAN0_MUX_SHIFT                 (4U)
/*! MUX - Functional Clock Mux Select
 *  0b100..SOSC-CLK
 *  0b011..FRO-192M
 *  0b000..The clock is off
 */
#define MRCC_MRCC_CAN0_MUX(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CAN0_MUX_SHIFT)) & MRCC_MRCC_CAN0_MUX_MASK)

#define MRCC_MRCC_CAN0_DIV_MASK                  (0xF00U)
#define MRCC_MRCC_CAN0_DIV_SHIFT                 (8U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CAN0_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CAN0_DIV_SHIFT)) & MRCC_MRCC_CAN0_DIV_MASK)

#define MRCC_MRCC_CAN0_RSTB_MASK                 (0x40000000U)
#define MRCC_MRCC_CAN0_RSTB_SHIFT                (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_CAN0_RSTB(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CAN0_RSTB_SHIFT)) & MRCC_MRCC_CAN0_RSTB_MASK)

#define MRCC_MRCC_CAN0_PR_MASK                   (0x80000000U)
#define MRCC_MRCC_CAN0_PR_SHIFT                  (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_CAN0_PR(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CAN0_PR_SHIFT)) & MRCC_MRCC_CAN0_PR_MASK)
/*! @} */

/*! @name MRCC_SEMA0 - SEMA42 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_SEMA0_CC_MASK                  (0x3U)
#define MRCC_MRCC_SEMA0_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_SEMA0_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SEMA0_CC_SHIFT)) & MRCC_MRCC_SEMA0_CC_MASK)

#define MRCC_MRCC_SEMA0_RSTB_MASK                (0x40000000U)
#define MRCC_MRCC_SEMA0_RSTB_SHIFT               (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_SEMA0_RSTB(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SEMA0_RSTB_SHIFT)) & MRCC_MRCC_SEMA0_RSTB_MASK)

#define MRCC_MRCC_SEMA0_PR_MASK                  (0x80000000U)
#define MRCC_MRCC_SEMA0_PR_SHIFT                 (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_SEMA0_PR(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SEMA0_PR_SHIFT)) & MRCC_MRCC_SEMA0_PR_MASK)
/*! @} */

/*! @name MRCC_DATA_STREAM_2P4 - DSB Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_DATA_STREAM_2P4_CC_MASK        (0x3U)
#define MRCC_MRCC_DATA_STREAM_2P4_CC_SHIFT       (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_DATA_STREAM_2P4_CC(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DATA_STREAM_2P4_CC_SHIFT)) & MRCC_MRCC_DATA_STREAM_2P4_CC_MASK)

#define MRCC_MRCC_DATA_STREAM_2P4_RSTB_MASK      (0x40000000U)
#define MRCC_MRCC_DATA_STREAM_2P4_RSTB_SHIFT     (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_DATA_STREAM_2P4_RSTB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DATA_STREAM_2P4_RSTB_SHIFT)) & MRCC_MRCC_DATA_STREAM_2P4_RSTB_MASK)

#define MRCC_MRCC_DATA_STREAM_2P4_PR_MASK        (0x80000000U)
#define MRCC_MRCC_DATA_STREAM_2P4_PR_SHIFT       (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_DATA_STREAM_2P4_PR(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DATA_STREAM_2P4_PR_SHIFT)) & MRCC_MRCC_DATA_STREAM_2P4_PR_MASK)
/*! @} */

/*! @name MRCC_PORTA - PORTA Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_PORTA_CC_MASK                  (0x3U)
#define MRCC_MRCC_PORTA_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_PORTA_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTA_CC_SHIFT)) & MRCC_MRCC_PORTA_CC_MASK)

#define MRCC_MRCC_PORTA_RSTB_MASK                (0x40000000U)
#define MRCC_MRCC_PORTA_RSTB_SHIFT               (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_PORTA_RSTB(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTA_RSTB_SHIFT)) & MRCC_MRCC_PORTA_RSTB_MASK)

#define MRCC_MRCC_PORTA_PR_MASK                  (0x80000000U)
#define MRCC_MRCC_PORTA_PR_SHIFT                 (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_PORTA_PR(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTA_PR_SHIFT)) & MRCC_MRCC_PORTA_PR_MASK)
/*! @} */

/*! @name MRCC_PORTB - PORTB Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_PORTB_CC_MASK                  (0x3U)
#define MRCC_MRCC_PORTB_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_PORTB_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTB_CC_SHIFT)) & MRCC_MRCC_PORTB_CC_MASK)

#define MRCC_MRCC_PORTB_RSTB_MASK                (0x40000000U)
#define MRCC_MRCC_PORTB_RSTB_SHIFT               (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_PORTB_RSTB(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTB_RSTB_SHIFT)) & MRCC_MRCC_PORTB_RSTB_MASK)

#define MRCC_MRCC_PORTB_PR_MASK                  (0x80000000U)
#define MRCC_MRCC_PORTB_PR_SHIFT                 (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_PORTB_PR(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTB_PR_SHIFT)) & MRCC_MRCC_PORTB_PR_MASK)
/*! @} */

/*! @name MRCC_PORTC - PORTC Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_PORTC_CC_MASK                  (0x3U)
#define MRCC_MRCC_PORTC_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_PORTC_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTC_CC_SHIFT)) & MRCC_MRCC_PORTC_CC_MASK)

#define MRCC_MRCC_PORTC_RSTB_MASK                (0x40000000U)
#define MRCC_MRCC_PORTC_RSTB_SHIFT               (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_PORTC_RSTB(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTC_RSTB_SHIFT)) & MRCC_MRCC_PORTC_RSTB_MASK)

#define MRCC_MRCC_PORTC_PR_MASK                  (0x80000000U)
#define MRCC_MRCC_PORTC_PR_SHIFT                 (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_PORTC_PR(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PORTC_PR_SHIFT)) & MRCC_MRCC_PORTC_PR_MASK)
/*! @} */

/*! @name MRCC_LPADC0 - ADC0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_LPADC0_CC_MASK                 (0x3U)
#define MRCC_MRCC_LPADC0_CC_SHIFT                (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_LPADC0_CC(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPADC0_CC_SHIFT)) & MRCC_MRCC_LPADC0_CC_MASK)

#define MRCC_MRCC_LPADC0_MUX_MASK                (0x70U)
#define MRCC_MRCC_LPADC0_MUX_SHIFT               (4U)
/*! MUX - Functional Clock Mux Select
 *  0b100..SOSC-CLK
 *  0b011..FRO-192M
 *  0b010..FRO-6M
 *  0b000..The clock is off
 */
#define MRCC_MRCC_LPADC0_MUX(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPADC0_MUX_SHIFT)) & MRCC_MRCC_LPADC0_MUX_MASK)

#define MRCC_MRCC_LPADC0_DIV_MASK                (0xF00U)
#define MRCC_MRCC_LPADC0_DIV_SHIFT               (8U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPADC0_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPADC0_DIV_SHIFT)) & MRCC_MRCC_LPADC0_DIV_MASK)

#define MRCC_MRCC_LPADC0_RSTB_MASK               (0x40000000U)
#define MRCC_MRCC_LPADC0_RSTB_SHIFT              (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPADC0_RSTB(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPADC0_RSTB_SHIFT)) & MRCC_MRCC_LPADC0_RSTB_MASK)

#define MRCC_MRCC_LPADC0_PR_MASK                 (0x80000000U)
#define MRCC_MRCC_LPADC0_PR_SHIFT                (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPADC0_PR(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPADC0_PR_SHIFT)) & MRCC_MRCC_LPADC0_PR_MASK)
/*! @} */

/*! @name MRCC_LPCMP0 - LPCMP0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_LPCMP0_CC_MASK                 (0x3U)
#define MRCC_MRCC_LPCMP0_CC_SHIFT                (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_LPCMP0_CC(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPCMP0_CC_SHIFT)) & MRCC_MRCC_LPCMP0_CC_MASK)

#define MRCC_MRCC_LPCMP0_RSTB_MASK               (0x40000000U)
#define MRCC_MRCC_LPCMP0_RSTB_SHIFT              (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPCMP0_RSTB(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPCMP0_RSTB_SHIFT)) & MRCC_MRCC_LPCMP0_RSTB_MASK)

#define MRCC_MRCC_LPCMP0_PR_MASK                 (0x80000000U)
#define MRCC_MRCC_LPCMP0_PR_SHIFT                (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPCMP0_PR(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPCMP0_PR_SHIFT)) & MRCC_MRCC_LPCMP0_PR_MASK)
/*! @} */

/*! @name MRCC_LPCMP1 - LPCMP1 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_LPCMP1_CC_MASK                 (0x3U)
#define MRCC_MRCC_LPCMP1_CC_SHIFT                (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_LPCMP1_CC(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPCMP1_CC_SHIFT)) & MRCC_MRCC_LPCMP1_CC_MASK)

#define MRCC_MRCC_LPCMP1_RSTB_MASK               (0x40000000U)
#define MRCC_MRCC_LPCMP1_RSTB_SHIFT              (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_LPCMP1_RSTB(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPCMP1_RSTB_SHIFT)) & MRCC_MRCC_LPCMP1_RSTB_MASK)

#define MRCC_MRCC_LPCMP1_PR_MASK                 (0x80000000U)
#define MRCC_MRCC_LPCMP1_PR_SHIFT                (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_LPCMP1_PR(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPCMP1_PR_SHIFT)) & MRCC_MRCC_LPCMP1_PR_MASK)
/*! @} */

/*! @name MRCC_VREF0 - VREF0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_VREF0_CC_MASK                  (0x3U)
#define MRCC_MRCC_VREF0_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_VREF0_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_VREF0_CC_SHIFT)) & MRCC_MRCC_VREF0_CC_MASK)

#define MRCC_MRCC_VREF0_RSTB_MASK                (0x40000000U)
#define MRCC_MRCC_VREF0_RSTB_SHIFT               (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_VREF0_RSTB(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_VREF0_RSTB_SHIFT)) & MRCC_MRCC_VREF0_RSTB_MASK)

#define MRCC_MRCC_VREF0_PR_MASK                  (0x80000000U)
#define MRCC_MRCC_VREF0_PR_SHIFT                 (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_VREF0_PR(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_VREF0_PR_SHIFT)) & MRCC_MRCC_VREF0_PR_MASK)
/*! @} */

/*! @name MRCC_GPIOA - GPIOA Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_GPIOA_CC_MASK                  (0x3U)
#define MRCC_MRCC_GPIOA_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_GPIOA_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOA_CC_SHIFT)) & MRCC_MRCC_GPIOA_CC_MASK)

#define MRCC_MRCC_GPIOA_RSTB_MASK                (0x40000000U)
#define MRCC_MRCC_GPIOA_RSTB_SHIFT               (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_GPIOA_RSTB(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOA_RSTB_SHIFT)) & MRCC_MRCC_GPIOA_RSTB_MASK)

#define MRCC_MRCC_GPIOA_PR_MASK                  (0x80000000U)
#define MRCC_MRCC_GPIOA_PR_SHIFT                 (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_GPIOA_PR(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOA_PR_SHIFT)) & MRCC_MRCC_GPIOA_PR_MASK)
/*! @} */

/*! @name MRCC_GPIOB - GPIOB Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_GPIOB_CC_MASK                  (0x3U)
#define MRCC_MRCC_GPIOB_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_GPIOB_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOB_CC_SHIFT)) & MRCC_MRCC_GPIOB_CC_MASK)

#define MRCC_MRCC_GPIOB_RSTB_MASK                (0x40000000U)
#define MRCC_MRCC_GPIOB_RSTB_SHIFT               (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_GPIOB_RSTB(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOB_RSTB_SHIFT)) & MRCC_MRCC_GPIOB_RSTB_MASK)

#define MRCC_MRCC_GPIOB_PR_MASK                  (0x80000000U)
#define MRCC_MRCC_GPIOB_PR_SHIFT                 (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_GPIOB_PR(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOB_PR_SHIFT)) & MRCC_MRCC_GPIOB_PR_MASK)
/*! @} */

/*! @name MRCC_GPIOC - GPIOC Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_GPIOC_CC_MASK                  (0x3U)
#define MRCC_MRCC_GPIOC_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_GPIOC_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOC_CC_SHIFT)) & MRCC_MRCC_GPIOC_CC_MASK)

#define MRCC_MRCC_GPIOC_RSTB_MASK                (0x40000000U)
#define MRCC_MRCC_GPIOC_RSTB_SHIFT               (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_GPIOC_RSTB(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOC_RSTB_SHIFT)) & MRCC_MRCC_GPIOC_RSTB_MASK)

#define MRCC_MRCC_GPIOC_PR_MASK                  (0x80000000U)
#define MRCC_MRCC_GPIOC_PR_SHIFT                 (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_GPIOC_PR(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GPIOC_PR_SHIFT)) & MRCC_MRCC_GPIOC_PR_MASK)
/*! @} */

/*! @name MRCC_DMA0 - DMA0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_DMA0_CC_MASK                   (0x3U)
#define MRCC_MRCC_DMA0_CC_SHIFT                  (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_DMA0_CC(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DMA0_CC_SHIFT)) & MRCC_MRCC_DMA0_CC_MASK)

#define MRCC_MRCC_DMA0_RSTB_MASK                 (0x40000000U)
#define MRCC_MRCC_DMA0_RSTB_SHIFT                (30U)
/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define MRCC_MRCC_DMA0_RSTB(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DMA0_RSTB_SHIFT)) & MRCC_MRCC_DMA0_RSTB_MASK)

#define MRCC_MRCC_DMA0_PR_MASK                   (0x80000000U)
#define MRCC_MRCC_DMA0_PR_SHIFT                  (31U)
/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define MRCC_MRCC_DMA0_PR(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DMA0_PR_SHIFT)) & MRCC_MRCC_DMA0_PR_MASK)
/*! @} */

/*! @name MRCC_PFLEXNVM - FMC-NPX Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_PFLEXNVM_CC_MASK               (0x3U)
#define MRCC_MRCC_PFLEXNVM_CC_SHIFT              (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Reserved
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_PFLEXNVM_CC(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_PFLEXNVM_CC_SHIFT)) & MRCC_MRCC_PFLEXNVM_CC_MASK)
/*! @} */

/*! @name MRCC_SRAM0 - CTCM Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_SRAM0_CC_MASK                  (0x3U)
#define MRCC_MRCC_SRAM0_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_SRAM0_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SRAM0_CC_SHIFT)) & MRCC_MRCC_SRAM0_CC_MASK)
/*! @} */

/*! @name MRCC_SRAM1 - STCM0 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_SRAM1_CC_MASK                  (0x3U)
#define MRCC_MRCC_SRAM1_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_SRAM1_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SRAM1_CC_SHIFT)) & MRCC_MRCC_SRAM1_CC_MASK)
/*! @} */

/*! @name MRCC_SRAM2 - STCM1 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_SRAM2_CC_MASK                  (0x3U)
#define MRCC_MRCC_SRAM2_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_SRAM2_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SRAM2_CC_SHIFT)) & MRCC_MRCC_SRAM2_CC_MASK)
/*! @} */

/*! @name MRCC_SRAM3 - STCM2 Reset and Clock Control */
/*! @{ */

#define MRCC_MRCC_SRAM3_CC_MASK                  (0x3U)
#define MRCC_MRCC_SRAM3_CC_SHIFT                 (0U)
/*! CC - Clock Configuration
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module is idle.
 */
#define MRCC_MRCC_SRAM3_CC(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SRAM3_CC_SHIFT)) & MRCC_MRCC_SRAM3_CC_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MRCC_Register_Masks */

/* Backward compatibility */
#define MRCC_CC_MASK                              (0x3U)
#define MRCC_CC_SHIFT                             (0U)
#define MRCC_CC(x)                                (((uint32_t)(((uint32_t)(x)) << MRCC_CC_SHIFT))  & MRCC_CC_MASK)
#define MRCC_MUX_MASK                             (0x70U)
#define MRCC_MUX_SHIFT                            (4U)
#define MRCC_MUX(x)                               (((uint32_t)(((uint32_t)(x)) << MRCC_MUX_SHIFT))  & MRCC_MUX_MASK)
#define MRCC_DIV_MASK                             (0xF00U)
#define MRCC_DIV_SHIFT                            (8U)
#define MRCC_DIV(x)                               (((uint32_t)(((uint32_t)(x)) << MRCC_DIV_SHIFT))  & MRCC_DIV_MASK)
#define MRCC_RSTB_MASK                            (0x40000000U)
#define MRCC_RSTB_SHIFT                           (30U)
#define MRCC_RSTB(x)                              (((uint32_t)(((uint32_t)(x)) << MRCC_RSTB_SHIFT)) & MRCC_RSTB_MASK)
#define MRCC_PR_MASK                              (0x80000000U)
#define MRCC_PR_SHIFT                             (31U)
#define MRCC_PR(x)                                (((uint32_t)(((uint32_t)(x)) << MRCC_PR_SHIFT))  & MRCC_PR_MASK)


/*!
 * @}
 */ /* end of group MRCC_Peripheral_Access_Layer */


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


#endif  /* MRCC_H_ */

