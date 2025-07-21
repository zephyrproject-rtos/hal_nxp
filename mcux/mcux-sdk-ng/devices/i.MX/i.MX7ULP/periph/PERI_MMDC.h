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
**         CMSIS Peripheral Access Layer for MMDC
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
 * @file PERI_MMDC.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MMDC
 *
 * CMSIS Peripheral Access Layer for MMDC
 */

#if !defined(PERI_MMDC_H_)
#define PERI_MMDC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- MMDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MMDC_Peripheral_Access_Layer MMDC Peripheral Access Layer
 * @{
 */

/** MMDC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MDCTL;                             /**< MMDC Core Control Register, offset: 0x0 */
  __IO uint32_t MDPDC;                             /**< MMDC Core Power Down Control Register, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t MDCFG0;                            /**< MMDC Core Timing Configuration Register 0, offset: 0xC */
  __IO uint32_t MDCFG1;                            /**< MMDC Core Timing Configuration Register 1, offset: 0x10 */
  __IO uint32_t MDCFG2;                            /**< MMDC Core Timing Configuration Register 2, offset: 0x14 */
  __IO uint32_t MDMISC;                            /**< MMDC Core Miscellaneous Register, offset: 0x18 */
  __IO uint32_t MDSCR;                             /**< MMDC Core Special Command Register, offset: 0x1C */
  __IO uint32_t MDREF;                             /**< MMDC Core Refresh Control Register, offset: 0x20 */
       uint8_t RESERVED_1[8];
  __IO uint32_t MDRWD;                             /**< MMDC Core Read/Write Command Delay Register, offset: 0x2C */
  __IO uint32_t MDOR;                              /**< MMDC Core Out of Reset Delays Register, offset: 0x30 */
  __I  uint32_t MDMRR;                             /**< MMDC Core MRR Data Register, offset: 0x34 */
  __IO uint32_t MDCFG3LP;                          /**< MMDC Core Timing Configuration Register 3, offset: 0x38 */
  __IO uint32_t MDMR4;                             /**< MMDC Core MR4 Derating Register, offset: 0x3C */
  __IO uint32_t MDASP;                             /**< MMDC Core Address Space Partition Register, offset: 0x40 */
       uint8_t RESERVED_2[956];
  __IO uint32_t MAARCR;                            /**< MMDC Core AXI Reordering Control Register, offset: 0x400 */
  __IO uint32_t MAPSR;                             /**< MMDC Core Power Saving Control and Status Register, offset: 0x404 */
  __IO uint32_t MAEXIDR0;                          /**< MMDC Core Exclusive ID Monitor Register0, offset: 0x408 */
  __IO uint32_t MAEXIDR1;                          /**< MMDC Core Exclusive ID Monitor Register1, offset: 0x40C */
  __IO uint32_t MADPCR0;                           /**< MMDC Core Debug and Profiling Control Register 0, offset: 0x410 */
  __IO uint32_t MADPCR1;                           /**< MMDC Core Debug and Profiling Control Register 1, offset: 0x414 */
  __I  uint32_t MADPSR0;                           /**< MMDC Core Debug and Profiling Status Register 0, offset: 0x418 */
  __I  uint32_t MADPSR1;                           /**< MMDC Core Debug and Profiling Status Register 1, offset: 0x41C */
  __I  uint32_t MADPSR2;                           /**< MMDC Core Debug and Profiling Status Register 2, offset: 0x420 */
  __I  uint32_t MADPSR3;                           /**< MMDC Core Debug and Profiling Status Register 3, offset: 0x424 */
  __I  uint32_t MADPSR4;                           /**< MMDC Core Debug and Profiling Status Register 4, offset: 0x428 */
  __I  uint32_t MADPSR5;                           /**< MMDC Core Debug and Profiling Status Register 5, offset: 0x42C */
  __I  uint32_t MASBS0;                            /**< MMDC Core Step By Step Address Register, offset: 0x430 */
  __I  uint32_t MASBS1;                            /**< MMDC Core Step By Step Address Attributes Register, offset: 0x434 */
       uint8_t RESERVED_3[8];
  __IO uint32_t MAGENP;                            /**< MMDC Core General Purpose Register, offset: 0x440 */
       uint8_t RESERVED_4[956];
  __IO uint32_t MPZQHWCTRL;                        /**< MMDC PHY ZQ HW control register, offset: 0x800 */
  __IO uint32_t MPZQSWCTRL;                        /**< MMDC PHY ZQ SW control register, offset: 0x804 */
       uint8_t RESERVED_5[20];
  __IO uint32_t MPRDDQBY0DL;                       /**< MMDC PHY Read DQ Byte0 Delay Register, offset: 0x81C */
  __IO uint32_t MPRDDQBY1DL;                       /**< MMDC PHY Read DQ Byte1 Delay Register, offset: 0x820 */
  __IO uint32_t MPRDDQBY2DL;                       /**< MMDC PHY Read DQ Byte2 Delay Register, offset: 0x824 */
  __IO uint32_t MPRDDQBY3DL;                       /**< MMDC PHY Read DQ Byte3 Delay Register, offset: 0x828 */
       uint8_t RESERVED_6[16];
  __IO uint32_t MPDGCTRL0;                         /**< MMDC PHY Read DQS Gating Control Register 0, offset: 0x83C */
       uint8_t RESERVED_7[8];
  __IO uint32_t MPRDDLCTL;                         /**< MMDC PHY Read delay-lines Configuration Register, offset: 0x848 */
  __I  uint32_t MPRDDLST;                          /**< MMDC PHY Read delay-lines Status Register, offset: 0x84C */
  __IO uint32_t MPWRDLCTL;                         /**< MMDC PHY Write delay-lines Configuration Register, offset: 0x850 */
  __I  uint32_t MPWRDLST;                          /**< MMDC PHY Write delay-lines Status Register, offset: 0x854 */
       uint8_t RESERVED_8[4];
  __IO uint32_t MPZQLP2CTL;                        /**< MMDC ZQ LPDDR2 HW Control Register, offset: 0x85C */
  __IO uint32_t MPRDDLHWCTL;                       /**< MMDC PHY Read Delay HW Calibration Control Register, offset: 0x860 */
  __IO uint32_t MPWRDLHWCTL;                       /**< MMDC PHY Write Delay HW Calibration Control Register, offset: 0x864 */
  __I  uint32_t MPRDDLHWST0;                       /**< MMDC PHY Read Delay HW Calibration Status Register 0, offset: 0x868 */
  __I  uint32_t MPRDDLHWST1;                       /**< MMDC PHY Read Delay HW Calibration Status Register 1, offset: 0x86C */
  __I  uint32_t MPWRDLHWST0;                       /**< MMDC PHY Write Delay HW Calibration Status Register 0, offset: 0x870 */
  __I  uint32_t MPWRDLHWST1;                       /**< MMDC PHY Write Delay HW Calibration Status Register 1, offset: 0x874 */
       uint8_t RESERVED_9[20];
  __IO uint32_t MPPDCMPR1;                         /**< MMDC PHY Pre-defined Compare Register 1, offset: 0x88C */
  __IO uint32_t MPPDCMPR2;                         /**< MMDC PHY Pre-defined Compare and CA delay-line Configuration Register, offset: 0x890 */
  __IO uint32_t MPSWDAR0;                          /**< MMDC PHY SW Dummy Access Register, offset: 0x894 */
  __I  uint32_t MPSWDRDR0;                         /**< MMDC PHY SW Dummy Read Data Register 0, offset: 0x898 */
  __I  uint32_t MPSWDRDR1;                         /**< MMDC PHY SW Dummy Read Data Register 1, offset: 0x89C */
  __I  uint32_t MPSWDRDR2;                         /**< MMDC PHY SW Dummy Read Data Register 2, offset: 0x8A0 */
  __I  uint32_t MPSWDRDR3;                         /**< MMDC PHY SW Dummy Read Data Register 3, offset: 0x8A4 */
  __I  uint32_t MPSWDRDR4;                         /**< MMDC PHY SW Dummy Read Data Register 4, offset: 0x8A8 */
  __I  uint32_t MPSWDRDR5;                         /**< MMDC PHY SW Dummy Read Data Register 5, offset: 0x8AC */
  __I  uint32_t MPSWDRDR6;                         /**< MMDC PHY SW Dummy Read Data Register 6, offset: 0x8B0 */
  __I  uint32_t MPSWDRDR7;                         /**< MMDC PHY SW Dummy Read Data Register 7, offset: 0x8B4 */
  __IO uint32_t MPMUR0;                            /**< MMDC PHY Measure Unit Register, offset: 0x8B8 */
       uint8_t RESERVED_10[4];
  __IO uint32_t MPDCCR;                            /**< MMDC Duty Cycle Control Register, offset: 0x8C0 */
} MMDC_Type;

/* ----------------------------------------------------------------------------
   -- MMDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MMDC_Register_Masks MMDC Register Masks
 * @{
 */

/*! @name MDCTL - MMDC Core Control Register */
/*! @{ */

#define MMDC_MDCTL_DSIZ_MASK                     (0x30000U)
#define MMDC_MDCTL_DSIZ_SHIFT                    (16U)
/*! DSIZ
 *  0b00..16-bit data bus
 *  0b01..32-bit data bus
 *  0b10-0b11..Reserved
 */
#define MMDC_MDCTL_DSIZ(x)                       (((uint32_t)(((uint32_t)(x)) << MMDC_MDCTL_DSIZ_SHIFT)) & MMDC_MDCTL_DSIZ_MASK)

#define MMDC_MDCTL_BL_MASK                       (0x80000U)
#define MMDC_MDCTL_BL_SHIFT                      (19U)
/*! BL
 *  0b0..Burst Length 4 is used
 *  0b1..Burst Length 8 is used
 */
#define MMDC_MDCTL_BL(x)                         (((uint32_t)(((uint32_t)(x)) << MMDC_MDCTL_BL_SHIFT)) & MMDC_MDCTL_BL_MASK)

#define MMDC_MDCTL_COL_MASK                      (0x700000U)
#define MMDC_MDCTL_COL_SHIFT                     (20U)
/*! COL
 *  0b000..9 bits column
 *  0b001..10 bits column
 *  0b010..11 bits column
 *  0b011..8 bits column
 *  0b100..12 bits column
 */
#define MMDC_MDCTL_COL(x)                        (((uint32_t)(((uint32_t)(x)) << MMDC_MDCTL_COL_SHIFT)) & MMDC_MDCTL_COL_MASK)

#define MMDC_MDCTL_ROW_MASK                      (0x7000000U)
#define MMDC_MDCTL_ROW_SHIFT                     (24U)
/*! ROW
 *  0b000..11 bits Row
 *  0b001..12 bits Row
 *  0b010..13 bits Row
 *  0b011..14 bits Row
 *  0b100..15 bits Row
 *  0b101..16 bits Row
 */
#define MMDC_MDCTL_ROW(x)                        (((uint32_t)(((uint32_t)(x)) << MMDC_MDCTL_ROW_SHIFT)) & MMDC_MDCTL_ROW_MASK)

#define MMDC_MDCTL_SDE_1_MASK                    (0x40000000U)
#define MMDC_MDCTL_SDE_1_SHIFT                   (30U)
/*! SDE_1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MMDC_MDCTL_SDE_1(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MDCTL_SDE_1_SHIFT)) & MMDC_MDCTL_SDE_1_MASK)

#define MMDC_MDCTL_SDE_0_MASK                    (0x80000000U)
#define MMDC_MDCTL_SDE_0_SHIFT                   (31U)
/*! SDE_0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MMDC_MDCTL_SDE_0(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MDCTL_SDE_0_SHIFT)) & MMDC_MDCTL_SDE_0_MASK)
/*! @} */

/*! @name MDPDC - MMDC Core Power Down Control Register */
/*! @{ */

#define MMDC_MDPDC_tCKSRE_MASK                   (0x7U)
#define MMDC_MDPDC_tCKSRE_SHIFT                  (0U)
/*! tCKSRE
 *  0b000..0 cycle
 *  0b001..1 cycles
 *  0b110..6 cycles
 *  0b111..7 cycles
 */
#define MMDC_MDPDC_tCKSRE(x)                     (((uint32_t)(((uint32_t)(x)) << MMDC_MDPDC_tCKSRE_SHIFT)) & MMDC_MDPDC_tCKSRE_MASK)

#define MMDC_MDPDC_tCKSRX_MASK                   (0x38U)
#define MMDC_MDPDC_tCKSRX_SHIFT                  (3U)
/*! tCKSRX
 *  0b000..0 cycle
 *  0b001..1 cycles
 *  0b110..6 cycles
 *  0b111..7 cycles
 */
#define MMDC_MDPDC_tCKSRX(x)                     (((uint32_t)(((uint32_t)(x)) << MMDC_MDPDC_tCKSRX_SHIFT)) & MMDC_MDPDC_tCKSRX_MASK)

#define MMDC_MDPDC_BOTH_CS_PD_MASK               (0x40U)
#define MMDC_MDPDC_BOTH_CS_PD_SHIFT              (6U)
/*! BOTH_CS_PD
 *  0b0..Each chip select can enter power down independently according to its configuration.
 *  0b1..Chip selects can enter power down only if the amount of idle cycles of both chip selects was obtained.
 */
#define MMDC_MDPDC_BOTH_CS_PD(x)                 (((uint32_t)(((uint32_t)(x)) << MMDC_MDPDC_BOTH_CS_PD_SHIFT)) & MMDC_MDPDC_BOTH_CS_PD_MASK)

#define MMDC_MDPDC_SLOW_PD_MASK                  (0x80U)
#define MMDC_MDPDC_SLOW_PD_SHIFT                 (7U)
/*! SLOW_PD
 *  0b0..Fast mode.
 *  0b1..Slow mode.
 */
#define MMDC_MDPDC_SLOW_PD(x)                    (((uint32_t)(((uint32_t)(x)) << MMDC_MDPDC_SLOW_PD_SHIFT)) & MMDC_MDPDC_SLOW_PD_MASK)

#define MMDC_MDPDC_PWDT_0_MASK                   (0xF00U)
#define MMDC_MDPDC_PWDT_0_SHIFT                  (8U)
#define MMDC_MDPDC_PWDT_0(x)                     (((uint32_t)(((uint32_t)(x)) << MMDC_MDPDC_PWDT_0_SHIFT)) & MMDC_MDPDC_PWDT_0_MASK)

#define MMDC_MDPDC_PWDT_1_MASK                   (0xF000U)
#define MMDC_MDPDC_PWDT_1_SHIFT                  (12U)
#define MMDC_MDPDC_PWDT_1(x)                     (((uint32_t)(((uint32_t)(x)) << MMDC_MDPDC_PWDT_1_SHIFT)) & MMDC_MDPDC_PWDT_1_MASK)

#define MMDC_MDPDC_tCKE_MASK                     (0x70000U)
#define MMDC_MDPDC_tCKE_SHIFT                    (16U)
/*! tCKE
 *  0b000..1 cycle
 *  0b001..2 cycles
 *  0b110..7 cycles
 *  0b111..8 cycles
 */
#define MMDC_MDPDC_tCKE(x)                       (((uint32_t)(((uint32_t)(x)) << MMDC_MDPDC_tCKE_SHIFT)) & MMDC_MDPDC_tCKE_MASK)

#define MMDC_MDPDC_PRCT_0_MASK                   (0x7000000U)
#define MMDC_MDPDC_PRCT_0_SHIFT                  (24U)
#define MMDC_MDPDC_PRCT_0(x)                     (((uint32_t)(((uint32_t)(x)) << MMDC_MDPDC_PRCT_0_SHIFT)) & MMDC_MDPDC_PRCT_0_MASK)

#define MMDC_MDPDC_PRCT_1_MASK                   (0x70000000U)
#define MMDC_MDPDC_PRCT_1_SHIFT                  (28U)
#define MMDC_MDPDC_PRCT_1(x)                     (((uint32_t)(((uint32_t)(x)) << MMDC_MDPDC_PRCT_1_SHIFT)) & MMDC_MDPDC_PRCT_1_MASK)
/*! @} */

/*! @name MDCFG0 - MMDC Core Timing Configuration Register 0 */
/*! @{ */

#define MMDC_MDCFG0_tCL_MASK                     (0xFU)
#define MMDC_MDCFG0_tCL_SHIFT                    (0U)
/*! tCL
 *  0b0000..3 cycles
 *  0b0001..4 cycles
 *  0b0010..5 cycles
 *  0b0011..6 cycles
 *  0b0100..7 cycles
 *  0b0101..8 cycles
 *  0b0110..9 cycles
 *  0b0111..10 cycles
 *  0b1000..11 cycles
 *  0b1001..- 0xF Reserved
 */
#define MMDC_MDCFG0_tCL(x)                       (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG0_tCL_SHIFT)) & MMDC_MDCFG0_tCL_MASK)

#define MMDC_MDCFG0_tFAW_MASK                    (0x1F0U)
#define MMDC_MDCFG0_tFAW_SHIFT                   (4U)
/*! tFAW
 *  0b00000..1 clock
 *  0b00001..2 clocks
 *  0b00010..3 clocks
 *  0b11110..31 clocks
 *  0b11111..32 clocks
 */
#define MMDC_MDCFG0_tFAW(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG0_tFAW_SHIFT)) & MMDC_MDCFG0_tFAW_MASK)

#define MMDC_MDCFG0_tXPDLL_MASK                  (0x1E00U)
#define MMDC_MDCFG0_tXPDLL_SHIFT                 (9U)
/*! tXPDLL
 *  0b0000..1 clock
 *  0b0001..2 clocks
 *  0b0010..3 clocks
 *  0b1110..15 clocks
 *  0b1111..16 clocks
 */
#define MMDC_MDCFG0_tXPDLL(x)                    (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG0_tXPDLL_SHIFT)) & MMDC_MDCFG0_tXPDLL_MASK)

#define MMDC_MDCFG0_tXP_MASK                     (0xE000U)
#define MMDC_MDCFG0_tXP_SHIFT                    (13U)
/*! tXP
 *  0b000..1 cycle
 *  0b001..2 cycles
 *  0b110..7 cycles
 *  0b111..8 cycles
 */
#define MMDC_MDCFG0_tXP(x)                       (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG0_tXP_SHIFT)) & MMDC_MDCFG0_tXP_MASK)

#define MMDC_MDCFG0_tXS_MASK                     (0xFF0000U)
#define MMDC_MDCFG0_tXS_SHIFT                    (16U)
/*! tXS
 *  0b00000000..- 0x15 reserved
 *  0b00010110..23 clocks
 *  0b00010111..24 clocks
 *  0b11111110..255 clocks
 *  0b11111111..256 clocks
 */
#define MMDC_MDCFG0_tXS(x)                       (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG0_tXS_SHIFT)) & MMDC_MDCFG0_tXS_MASK)

#define MMDC_MDCFG0_tRFC_MASK                    (0xFF000000U)
#define MMDC_MDCFG0_tRFC_SHIFT                   (24U)
/*! tRFC
 *  0b00000000..1 clock
 *  0b00000001..2 clocks
 *  0b00000010..3 clocks
 *  0b11111110..255 clocks
 *  0b11111111..256 clocks
 */
#define MMDC_MDCFG0_tRFC(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG0_tRFC_SHIFT)) & MMDC_MDCFG0_tRFC_MASK)
/*! @} */

/*! @name MDCFG1 - MMDC Core Timing Configuration Register 1 */
/*! @{ */

#define MMDC_MDCFG1_tCWL_MASK                    (0x7U)
#define MMDC_MDCFG1_tCWL_SHIFT                   (0U)
/*! tCWL
 *  0b000..1 cycles (LPDDR2/LPDDR3)
 *  0b001..2 cycles (LPDDR2/LPDDR3)
 *  0b010..3 cycles (LPDDR2/LPDDR3)
 *  0b011..4 cycles (LPDDR2/LPDDR3)
 *  0b100..5 cycles (LPDDR2/LPDDR3)
 *  0b101..6 cycles (LPDDR2/LPDDR3)
 *  0b110..7 cycles (LPDDR2/LPDDR3)
 *  0b111..Reserved
 */
#define MMDC_MDCFG1_tCWL(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG1_tCWL_SHIFT)) & MMDC_MDCFG1_tCWL_MASK)

#define MMDC_MDCFG1_tMRD_MASK                    (0x1E0U)
#define MMDC_MDCFG1_tMRD_SHIFT                   (5U)
/*! tMRD
 *  0b0000..1 clock
 *  0b0001..2 clocks
 *  0b0010..3 clocks
 *  0b1110..15 clocks
 *  0b1111..16 clocks
 */
#define MMDC_MDCFG1_tMRD(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG1_tMRD_SHIFT)) & MMDC_MDCFG1_tMRD_MASK)

#define MMDC_MDCFG1_tWR_MASK                     (0xE00U)
#define MMDC_MDCFG1_tWR_SHIFT                    (9U)
/*! tWR
 *  0b000..1cycle
 *  0b001..2cycles
 *  0b010..3cycles
 *  0b011..4cycles
 *  0b100..5cycles
 *  0b101..6cycles
 *  0b110..7cycles
 *  0b111..8 cycles
 */
#define MMDC_MDCFG1_tWR(x)                       (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG1_tWR_SHIFT)) & MMDC_MDCFG1_tWR_MASK)

#define MMDC_MDCFG1_tRPA_MASK                    (0x8000U)
#define MMDC_MDCFG1_tRPA_SHIFT                   (15U)
/*! tRPA
 *  0b0..Will be equal to: tRP.
 *  0b1..Will be equal to: tRP+1.
 */
#define MMDC_MDCFG1_tRPA(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG1_tRPA_SHIFT)) & MMDC_MDCFG1_tRPA_MASK)

#define MMDC_MDCFG1_tRAS_MASK                    (0x1F0000U)
#define MMDC_MDCFG1_tRAS_SHIFT                   (16U)
/*! tRAS
 *  0b00000..1 clock
 *  0b00001..2 clocks
 *  0b00010..3 clocks
 *  0b11110..31 clocks
 *  0b11111..Reserved
 */
#define MMDC_MDCFG1_tRAS(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG1_tRAS_SHIFT)) & MMDC_MDCFG1_tRAS_MASK)

#define MMDC_MDCFG1_tRC_MASK                     (0x3E00000U)
#define MMDC_MDCFG1_tRC_SHIFT                    (21U)
/*! tRC
 *  0b00000..1 clock
 *  0b00001..2 clocks
 *  0b00010..3 clocks
 *  0b11110..31 clocks
 *  0b11111..32 clocks
 */
#define MMDC_MDCFG1_tRC(x)                       (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG1_tRC_SHIFT)) & MMDC_MDCFG1_tRC_MASK)

#define MMDC_MDCFG1_tRP_MASK                     (0x1C000000U)
#define MMDC_MDCFG1_tRP_SHIFT                    (26U)
/*! tRP
 *  0b000..1 clock
 *  0b001..2 clocks
 *  0b010..3 clocks
 *  0b011..4 clocks
 *  0b100..5 clocks
 *  0b101..6 clocks
 *  0b110..7 clocks
 *  0b111..8 clocks
 */
#define MMDC_MDCFG1_tRP(x)                       (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG1_tRP_SHIFT)) & MMDC_MDCFG1_tRP_MASK)

#define MMDC_MDCFG1_tRCD_MASK                    (0xE0000000U)
#define MMDC_MDCFG1_tRCD_SHIFT                   (29U)
/*! tRCD
 *  0b000..1 clock
 *  0b001..2 clocks
 *  0b010..3 clocks
 *  0b011..4 clocks
 *  0b100..5 clocks
 *  0b101..6 clocks
 *  0b110..7 clocks
 *  0b111..8 clocks
 */
#define MMDC_MDCFG1_tRCD(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG1_tRCD_SHIFT)) & MMDC_MDCFG1_tRCD_MASK)
/*! @} */

/*! @name MDCFG2 - MMDC Core Timing Configuration Register 2 */
/*! @{ */

#define MMDC_MDCFG2_tRRD_MASK                    (0x7U)
#define MMDC_MDCFG2_tRRD_SHIFT                   (0U)
/*! tRRD
 *  0b000..1cycle
 *  0b001..2cycles
 *  0b010..3cycles
 *  0b011..4cycles
 *  0b100..5cycles
 *  0b101..6cycles
 *  0b110..7cycles
 *  0b111..Reserved
 */
#define MMDC_MDCFG2_tRRD(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG2_tRRD_SHIFT)) & MMDC_MDCFG2_tRRD_MASK)

#define MMDC_MDCFG2_tWTR_MASK                    (0x38U)
#define MMDC_MDCFG2_tWTR_SHIFT                   (3U)
/*! tWTR
 *  0b000..1cycle
 *  0b001..2cycles
 *  0b010..3cycles
 *  0b011..4cycles
 *  0b100..5cycles
 *  0b101..6cycles
 *  0b110..7cycles
 *  0b111..8 cycles
 */
#define MMDC_MDCFG2_tWTR(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG2_tWTR_SHIFT)) & MMDC_MDCFG2_tWTR_MASK)

#define MMDC_MDCFG2_tRTP_MASK                    (0x1C0U)
#define MMDC_MDCFG2_tRTP_SHIFT                   (6U)
/*! tRTP
 *  0b000..1cycle
 *  0b001..2cycles
 *  0b010..3cycles
 *  0b011..4cycles
 *  0b100..5cycles
 *  0b101..6cycles
 *  0b110..7cycles
 *  0b111..8 cycles
 */
#define MMDC_MDCFG2_tRTP(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG2_tRTP_SHIFT)) & MMDC_MDCFG2_tRTP_MASK)

#define MMDC_MDCFG2_tDLLK_MASK                   (0x1FF0000U)
#define MMDC_MDCFG2_tDLLK_SHIFT                  (16U)
/*! tDLLK
 *  0b000000000..1 cycle.
 *  0b000000001..2 cycles.
 *  0b000000010..3 cycles.
 *  0b011000111..200 cycles
 *  0b111111110..511 cycles.
 *  0b111111111..512 cycles
 */
#define MMDC_MDCFG2_tDLLK(x)                     (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG2_tDLLK_SHIFT)) & MMDC_MDCFG2_tDLLK_MASK)
/*! @} */

/*! @name MDMISC - MMDC Core Miscellaneous Register */
/*! @{ */

#define MMDC_MDMISC_RST_MASK                     (0x2U)
#define MMDC_MDMISC_RST_SHIFT                    (1U)
/*! RST
 *  0b0..Do nothing.
 *  0b1..Assert reset to the MMDC.
 */
#define MMDC_MDMISC_RST(x)                       (((uint32_t)(((uint32_t)(x)) << MMDC_MDMISC_RST_SHIFT)) & MMDC_MDMISC_RST_MASK)

#define MMDC_MDMISC_DDR_TYPE_MASK                (0x18U)
#define MMDC_MDMISC_DDR_TYPE_SHIFT               (3U)
/*! DDR_TYPE
 *  0b00..Reserved
 *  0b01..LPDDR2 device is used.
 *  0b10..Reserved
 *  0b11..LPDDR3 device is used.
 */
#define MMDC_MDMISC_DDR_TYPE(x)                  (((uint32_t)(((uint32_t)(x)) << MMDC_MDMISC_DDR_TYPE_SHIFT)) & MMDC_MDMISC_DDR_TYPE_MASK)

#define MMDC_MDMISC_DDR_4_BANK_MASK              (0x20U)
#define MMDC_MDMISC_DDR_4_BANK_SHIFT             (5U)
/*! DDR_4_BANK
 *  0b0..8 banks device is being used. (Default)
 *  0b1..4 banks device is being used
 */
#define MMDC_MDMISC_DDR_4_BANK(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MDMISC_DDR_4_BANK_SHIFT)) & MMDC_MDMISC_DDR_4_BANK_MASK)

#define MMDC_MDMISC_RALAT_MASK                   (0x1C0U)
#define MMDC_MDMISC_RALAT_SHIFT                  (6U)
/*! RALAT
 *  0b000..no additional latency.
 *  0b001..1 cycle additional latency.
 *  0b010..2 cycles additional latency.
 *  0b011..3 cycles additional latency.
 *  0b100..4 cycles additional latency.
 *  0b101..5 cycles additional latency.
 *  0b110..6 cycles additional latency.
 *  0b111..7 cycles additional latency.
 */
#define MMDC_MDMISC_RALAT(x)                     (((uint32_t)(((uint32_t)(x)) << MMDC_MDMISC_RALAT_SHIFT)) & MMDC_MDMISC_RALAT_MASK)

#define MMDC_MDMISC_MIF3_MODE_MASK               (0x600U)
#define MMDC_MDMISC_MIF3_MODE_SHIFT              (9U)
/*! MIF3_MODE
 *  0b00..Disable prediction.
 *  0b01..Enable prediction based on : Valid access on first pipe line stage.
 *  0b10..Enable prediction based on: Valid access on first pipe line stage, Valid access on axi bus.
 *  0b11..Enable prediction based on: Valid access on first pipe line stage, Valid access on axi bus, Next miss access from access queue.
 */
#define MMDC_MDMISC_MIF3_MODE(x)                 (((uint32_t)(((uint32_t)(x)) << MMDC_MDMISC_MIF3_MODE_SHIFT)) & MMDC_MDMISC_MIF3_MODE_MASK)

#define MMDC_MDMISC_LPDDR2_S2_MASK               (0x800U)
#define MMDC_MDMISC_LPDDR2_S2_SHIFT              (11U)
/*! LPDDR2_S2
 *  0b0..LPDDR2-S4 device is used.
 *  0b1..LPDDR2-S2 device is used.
 */
#define MMDC_MDMISC_LPDDR2_S2(x)                 (((uint32_t)(((uint32_t)(x)) << MMDC_MDMISC_LPDDR2_S2_SHIFT)) & MMDC_MDMISC_LPDDR2_S2_MASK)

#define MMDC_MDMISC_BI_ON_MASK                   (0x1000U)
#define MMDC_MDMISC_BI_ON_SHIFT                  (12U)
/*! BI_ON
 *  0b0..Banks are not interleaved, and address will be decoded as bank-row-column
 *  0b1..Banks are interleaved, and address will be decoded as row-bank-column
 */
#define MMDC_MDMISC_BI_ON(x)                     (((uint32_t)(((uint32_t)(x)) << MMDC_MDMISC_BI_ON_SHIFT)) & MMDC_MDMISC_BI_ON_MASK)

#define MMDC_MDMISC_WALAT_MASK                   (0x30000U)
#define MMDC_MDMISC_WALAT_SHIFT                  (16U)
/*! WALAT
 *  0b00..No additional latency required.
 *  0b01..1 cycle additional delay
 *  0b10..2 cycles additional delay
 *  0b11..3 cycles additional delay
 */
#define MMDC_MDMISC_WALAT(x)                     (((uint32_t)(((uint32_t)(x)) << MMDC_MDMISC_WALAT_SHIFT)) & MMDC_MDMISC_WALAT_MASK)

#define MMDC_MDMISC_LHD_MASK                     (0x40000U)
#define MMDC_MDMISC_LHD_SHIFT                    (18U)
/*! LHD
 *  0b0..Latency hiding on.
 *  0b1..Latency hiding disable.
 */
#define MMDC_MDMISC_LHD(x)                       (((uint32_t)(((uint32_t)(x)) << MMDC_MDMISC_LHD_SHIFT)) & MMDC_MDMISC_LHD_MASK)

#define MMDC_MDMISC_CALIB_PER_CS_MASK            (0x100000U)
#define MMDC_MDMISC_CALIB_PER_CS_SHIFT           (20U)
/*! CALIB_PER_CS
 *  0b0..Calibration is targeted to CS0
 *  0b1..Calibration is targeted to CS1
 */
#define MMDC_MDMISC_CALIB_PER_CS(x)              (((uint32_t)(((uint32_t)(x)) << MMDC_MDMISC_CALIB_PER_CS_SHIFT)) & MMDC_MDMISC_CALIB_PER_CS_MASK)

#define MMDC_MDMISC_CK1_GATING_MASK              (0x200000U)
#define MMDC_MDMISC_CK1_GATING_SHIFT             (21U)
/*! CK1_GATING
 *  0b0..MMDC drives two clocks toward the DDR memory
 *  0b1..MMDC drives only one clock toward the DDR memory (CK0)
 */
#define MMDC_MDMISC_CK1_GATING(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MDMISC_CK1_GATING_SHIFT)) & MMDC_MDMISC_CK1_GATING_MASK)

#define MMDC_MDMISC_CS1_RDY_MASK                 (0x40000000U)
#define MMDC_MDMISC_CS1_RDY_SHIFT                (30U)
/*! CS1_RDY
 *  0b0..Device in wake-up period.
 *  0b1..Device is ready for initialization.
 */
#define MMDC_MDMISC_CS1_RDY(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MDMISC_CS1_RDY_SHIFT)) & MMDC_MDMISC_CS1_RDY_MASK)

#define MMDC_MDMISC_CS0_RDY_MASK                 (0x80000000U)
#define MMDC_MDMISC_CS0_RDY_SHIFT                (31U)
/*! CS0_RDY
 *  0b0..Device in wake-up period.
 *  0b1..Device is ready for initialization.
 */
#define MMDC_MDMISC_CS0_RDY(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MDMISC_CS0_RDY_SHIFT)) & MMDC_MDMISC_CS0_RDY_MASK)
/*! @} */

/*! @name MDSCR - MMDC Core Special Command Register */
/*! @{ */

#define MMDC_MDSCR_CMD_BA_MASK                   (0x7U)
#define MMDC_MDSCR_CMD_BA_SHIFT                  (0U)
/*! CMD_BA
 *  0b000..bank address 0
 *  0b001..bank address 1
 *  0b010..bank address 2
 *  0b111..bank address 7
 */
#define MMDC_MDSCR_CMD_BA(x)                     (((uint32_t)(((uint32_t)(x)) << MMDC_MDSCR_CMD_BA_SHIFT)) & MMDC_MDSCR_CMD_BA_MASK)

#define MMDC_MDSCR_CMD_CS_MASK                   (0x8U)
#define MMDC_MDSCR_CMD_CS_SHIFT                  (3U)
/*! CMD_CS
 *  0b0..to Chip-select 0
 *  0b1..to Chip-select 1
 */
#define MMDC_MDSCR_CMD_CS(x)                     (((uint32_t)(((uint32_t)(x)) << MMDC_MDSCR_CMD_CS_SHIFT)) & MMDC_MDSCR_CMD_CS_MASK)

#define MMDC_MDSCR_CMD_MASK                      (0x70U)
#define MMDC_MDSCR_CMD_SHIFT                     (4U)
/*! CMD
 *  0b000..Normal operation
 *  0b001..Precharge all, command is sent independently of bank status (set correct CMD_CS). Will be issued even
 *         if banks are closed. Primarily used for initialization sequence purposes. Not to be used during run-time
 *         operation.
 *  0b010..Auto-Refresh Command (set correct CMD_CS).
 *  0b011..Load Mode Register Command (LPDDR2/LPDDR3, set correct CMD_CS, MR_OP, MR_ADDR)
 *  0b100..ZQ calibration
 *  0b101..Precharge all, only if banks open (set correct CMD_CS).
 *  0b110..MRR command (LPDDR2/LPDDR3, set correct CMD_CS, MR_ADDR)
 *  0b111..Reserved
 */
#define MMDC_MDSCR_CMD(x)                        (((uint32_t)(((uint32_t)(x)) << MMDC_MDSCR_CMD_SHIFT)) & MMDC_MDSCR_CMD_MASK)

#define MMDC_MDSCR_MRR_READ_DATA_VALID_MASK      (0x400U)
#define MMDC_MDSCR_MRR_READ_DATA_VALID_SHIFT     (10U)
/*! MRR_READ_DATA_VALID
 *  0b0..Cleared upon the assertion of MRR command
 *  0b1..Set after MRR data is valid and stored at MDMRR register.
 */
#define MMDC_MDSCR_MRR_READ_DATA_VALID(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MDSCR_MRR_READ_DATA_VALID_SHIFT)) & MMDC_MDSCR_MRR_READ_DATA_VALID_MASK)

#define MMDC_MDSCR_CON_ACK_MASK                  (0x4000U)
#define MMDC_MDSCR_CON_ACK_SHIFT                 (14U)
/*! CON_ACK
 *  0b0..Configuration of MMDC registers is forbidden.
 *  0b1..Configuration of MMDC registers is permitted.
 */
#define MMDC_MDSCR_CON_ACK(x)                    (((uint32_t)(((uint32_t)(x)) << MMDC_MDSCR_CON_ACK_SHIFT)) & MMDC_MDSCR_CON_ACK_MASK)

#define MMDC_MDSCR_CON_REQ_MASK                  (0x8000U)
#define MMDC_MDSCR_CON_REQ_SHIFT                 (15U)
/*! CON_REQ
 *  0b0..No request to configure MMDC.
 *  0b1..A request to configure MMDC is valid
 */
#define MMDC_MDSCR_CON_REQ(x)                    (((uint32_t)(((uint32_t)(x)) << MMDC_MDSCR_CON_REQ_SHIFT)) & MMDC_MDSCR_CON_REQ_MASK)

#define MMDC_MDSCR_CMD_ADDR_LSB_MR_ADDR_MASK     (0xFF0000U)
#define MMDC_MDSCR_CMD_ADDR_LSB_MR_ADDR_SHIFT    (16U)
#define MMDC_MDSCR_CMD_ADDR_LSB_MR_ADDR(x)       (((uint32_t)(((uint32_t)(x)) << MMDC_MDSCR_CMD_ADDR_LSB_MR_ADDR_SHIFT)) & MMDC_MDSCR_CMD_ADDR_LSB_MR_ADDR_MASK)

#define MMDC_MDSCR_CMD_ADDR_MSB_MR_OP_MASK       (0xFF000000U)
#define MMDC_MDSCR_CMD_ADDR_MSB_MR_OP_SHIFT      (24U)
#define MMDC_MDSCR_CMD_ADDR_MSB_MR_OP(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MDSCR_CMD_ADDR_MSB_MR_OP_SHIFT)) & MMDC_MDSCR_CMD_ADDR_MSB_MR_OP_MASK)
/*! @} */

/*! @name MDREF - MMDC Core Refresh Control Register */
/*! @{ */

#define MMDC_MDREF_START_REF_MASK                (0x1U)
#define MMDC_MDREF_START_REF_SHIFT               (0U)
/*! START_REF
 *  0b0..Do nothing.
 *  0b1..Start a refresh cycle.
 */
#define MMDC_MDREF_START_REF(x)                  (((uint32_t)(((uint32_t)(x)) << MMDC_MDREF_START_REF_SHIFT)) & MMDC_MDREF_START_REF_MASK)

#define MMDC_MDREF_REFR_MASK                     (0x3800U)
#define MMDC_MDREF_REFR_SHIFT                    (11U)
/*! REFR
 *  0b000..1 refresh
 *  0b001..2 refreshes
 *  0b010..3 refreshes
 *  0b011..4 refreshes
 *  0b100..5 refreshes
 *  0b101..6 refreshes
 *  0b110..7 refreshes
 *  0b111..8 refreshes
 */
#define MMDC_MDREF_REFR(x)                       (((uint32_t)(((uint32_t)(x)) << MMDC_MDREF_REFR_SHIFT)) & MMDC_MDREF_REFR_MASK)

#define MMDC_MDREF_REF_SEL_MASK                  (0xC000U)
#define MMDC_MDREF_REF_SEL_SHIFT                 (14U)
/*! REF_SEL
 *  0b00..Periodic refresh cycles will be triggered in frequency of 64KHz.
 *  0b01..Periodic refresh cycles will be triggered in frequency of 32KHz.
 *  0b10..Periodic refresh cycles will be triggered every amount of cycles that are configured in REF_CNT field.
 *  0b11..No refresh cycles will be triggered.
 */
#define MMDC_MDREF_REF_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << MMDC_MDREF_REF_SEL_SHIFT)) & MMDC_MDREF_REF_SEL_MASK)

#define MMDC_MDREF_REF_CNT_MASK                  (0xFFFF0000U)
#define MMDC_MDREF_REF_CNT_SHIFT                 (16U)
/*! REF_CNT
 *  0b0000000000000000..Reserved.
 *  0b0000000000000001..1 cycle.
 *  0b1111111111111110..65534 cycles.
 *  0b1111111111111111..65535 cycles.
 */
#define MMDC_MDREF_REF_CNT(x)                    (((uint32_t)(((uint32_t)(x)) << MMDC_MDREF_REF_CNT_SHIFT)) & MMDC_MDREF_REF_CNT_MASK)
/*! @} */

/*! @name MDRWD - MMDC Core Read/Write Command Delay Register */
/*! @{ */

#define MMDC_MDRWD_RTR_DIFF_MASK                 (0x7U)
#define MMDC_MDRWD_RTR_DIFF_SHIFT                (0U)
/*! RTR_DIFF
 *  0b000..0 cycle
 *  0b001..1 cycle
 *  0b010..2 cycles (Default)
 *  0b011..3 cycles
 *  0b100..4 cycles
 *  0b101..5 cycles
 *  0b110..6 cycles
 *  0b111..7 cycles
 */
#define MMDC_MDRWD_RTR_DIFF(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MDRWD_RTR_DIFF_SHIFT)) & MMDC_MDRWD_RTR_DIFF_MASK)

#define MMDC_MDRWD_RTW_DIFF_MASK                 (0x38U)
#define MMDC_MDRWD_RTW_DIFF_SHIFT                (3U)
/*! RTW_DIFF
 *  0b000..0 cycle
 *  0b001..1 cycle
 *  0b010..2 cycles (Default)
 *  0b011..3 cycles
 *  0b100..4 cycles
 *  0b101..5 cycles
 *  0b110..6 cycles
 *  0b111..7 cycles
 */
#define MMDC_MDRWD_RTW_DIFF(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MDRWD_RTW_DIFF_SHIFT)) & MMDC_MDRWD_RTW_DIFF_MASK)

#define MMDC_MDRWD_WTW_DIFF_MASK                 (0x1C0U)
#define MMDC_MDRWD_WTW_DIFF_SHIFT                (6U)
/*! WTW_DIFF
 *  0b000..0 cycle
 *  0b001..1 cycle
 *  0b010..2 cycles
 *  0b011..3 cycles (Default)
 *  0b100..4 cycles
 *  0b101..5 cycles
 *  0b110..6 cycles
 *  0b111..7 cycles
 */
#define MMDC_MDRWD_WTW_DIFF(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MDRWD_WTW_DIFF_SHIFT)) & MMDC_MDRWD_WTW_DIFF_MASK)

#define MMDC_MDRWD_WTR_DIFF_MASK                 (0xE00U)
#define MMDC_MDRWD_WTR_DIFF_SHIFT                (9U)
/*! WTR_DIFF
 *  0b000..0 cycle
 *  0b001..1 cycle
 *  0b010..2 cycles
 *  0b011..3 cycles (Default)
 *  0b100..4 cycles
 *  0b101..5 cycles
 *  0b110..6 cycles
 *  0b111..7 cycles
 */
#define MMDC_MDRWD_WTR_DIFF(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MDRWD_WTR_DIFF_SHIFT)) & MMDC_MDRWD_WTR_DIFF_MASK)

#define MMDC_MDRWD_RTW_SAME_MASK                 (0x7000U)
#define MMDC_MDRWD_RTW_SAME_SHIFT                (12U)
/*! RTW_SAME
 *  0b000..0 cycle
 *  0b001..1 cycle
 *  0b010..2 cycles (Default)
 *  0b011..3 cycles
 *  0b100..4 cycles
 *  0b101..5 cycles
 *  0b110..6 cycles
 *  0b111..7 cycles
 */
#define MMDC_MDRWD_RTW_SAME(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MDRWD_RTW_SAME_SHIFT)) & MMDC_MDRWD_RTW_SAME_MASK)

#define MMDC_MDRWD_tDAI_MASK                     (0x1FFF0000U)
#define MMDC_MDRWD_tDAI_SHIFT                    (16U)
/*! tDAI
 *  0b0000000000000..1 cycle
 *  0b0111110011111..4000 cycles (Default, JEDEC value for LPDDR2, gives 10us at 400MHz clock).
 *  0b1111111111111..8192 cycles
 */
#define MMDC_MDRWD_tDAI(x)                       (((uint32_t)(((uint32_t)(x)) << MMDC_MDRWD_tDAI_SHIFT)) & MMDC_MDRWD_tDAI_MASK)
/*! @} */

/*! @name MDOR - MMDC Core Out of Reset Delays Register */
/*! @{ */

#define MMDC_MDOR_RST_to_CKE_MASK                (0x3FU)
#define MMDC_MDOR_RST_to_CKE_SHIFT               (0U)
/*! RST_to_CKE
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..Reserved
 *  0b000011..1 cycles
 *  0b010000..14 cycles (JEDEC value for LPDDR2) - total of 200 us
 *  0b100011..33 cycles - total of 500 us
 *  0b111110..60 cycles
 *  0b111111..61 cycles
 */
#define MMDC_MDOR_RST_to_CKE(x)                  (((uint32_t)(((uint32_t)(x)) << MMDC_MDOR_RST_to_CKE_SHIFT)) & MMDC_MDOR_RST_to_CKE_MASK)

#define MMDC_MDOR_SDE_to_RST_MASK                (0x3F00U)
#define MMDC_MDOR_SDE_to_RST_SHIFT               (8U)
/*! SDE_to_RST
 *  0b000000..Reserved
 *  0b000001..Reserved
 *  0b000010..Reserved
 *  0b000011..1 cycles
 *  0b000100..2 cycles
 *  0b010000..14 cycles - total of 200 us
 *  0b111110..60 cycles
 *  0b111111..61 cycles
 */
#define MMDC_MDOR_SDE_to_RST(x)                  (((uint32_t)(((uint32_t)(x)) << MMDC_MDOR_SDE_to_RST_SHIFT)) & MMDC_MDOR_SDE_to_RST_MASK)

#define MMDC_MDOR_tXPR_MASK                      (0xFF0000U)
#define MMDC_MDOR_tXPR_SHIFT                     (16U)
/*! tXPR
 *  0b00000000..Reserved
 *  0b00000001..2 cycles
 *  0b00000010..3 cycles
 *  0b11111110..255 cycles
 *  0b11111111..256 cycles
 */
#define MMDC_MDOR_tXPR(x)                        (((uint32_t)(((uint32_t)(x)) << MMDC_MDOR_tXPR_SHIFT)) & MMDC_MDOR_tXPR_MASK)
/*! @} */

/*! @name MDMRR - MMDC Core MRR Data Register */
/*! @{ */

#define MMDC_MDMRR_MRR_READ_DATA0_MASK           (0xFFU)
#define MMDC_MDMRR_MRR_READ_DATA0_SHIFT          (0U)
#define MMDC_MDMRR_MRR_READ_DATA0(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MDMRR_MRR_READ_DATA0_SHIFT)) & MMDC_MDMRR_MRR_READ_DATA0_MASK)

#define MMDC_MDMRR_MRR_READ_DATA1_MASK           (0xFF00U)
#define MMDC_MDMRR_MRR_READ_DATA1_SHIFT          (8U)
#define MMDC_MDMRR_MRR_READ_DATA1(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MDMRR_MRR_READ_DATA1_SHIFT)) & MMDC_MDMRR_MRR_READ_DATA1_MASK)

#define MMDC_MDMRR_MRR_READ_DATA2_MASK           (0xFF0000U)
#define MMDC_MDMRR_MRR_READ_DATA2_SHIFT          (16U)
#define MMDC_MDMRR_MRR_READ_DATA2(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MDMRR_MRR_READ_DATA2_SHIFT)) & MMDC_MDMRR_MRR_READ_DATA2_MASK)

#define MMDC_MDMRR_MRR_READ_DATA3_MASK           (0xFF000000U)
#define MMDC_MDMRR_MRR_READ_DATA3_SHIFT          (24U)
#define MMDC_MDMRR_MRR_READ_DATA3(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MDMRR_MRR_READ_DATA3_SHIFT)) & MMDC_MDMRR_MRR_READ_DATA3_MASK)
/*! @} */

/*! @name MDCFG3LP - MMDC Core Timing Configuration Register 3 */
/*! @{ */

#define MMDC_MDCFG3LP_tRPab_LP_MASK              (0xFU)
#define MMDC_MDCFG3LP_tRPab_LP_SHIFT             (0U)
/*! tRPab_LP
 *  0b0000..1 clock
 *  0b0001..2 clocks
 *  0b0010..3 clocks
 *  0b1110..15 clocks
 *  0b1111..Reserved
 */
#define MMDC_MDCFG3LP_tRPab_LP(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG3LP_tRPab_LP_SHIFT)) & MMDC_MDCFG3LP_tRPab_LP_MASK)

#define MMDC_MDCFG3LP_tRPpb_LP_MASK              (0xF0U)
#define MMDC_MDCFG3LP_tRPpb_LP_SHIFT             (4U)
/*! tRPpb_LP
 *  0b0000..1 clock
 *  0b0001..2 clocks
 *  0b0010..3 clocks
 *  0b1110..15 clocks
 *  0b1111..Reserved
 */
#define MMDC_MDCFG3LP_tRPpb_LP(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG3LP_tRPpb_LP_SHIFT)) & MMDC_MDCFG3LP_tRPpb_LP_MASK)

#define MMDC_MDCFG3LP_tRCD_LP_MASK               (0xF00U)
#define MMDC_MDCFG3LP_tRCD_LP_SHIFT              (8U)
/*! tRCD_LP
 *  0b0000..1 clock
 *  0b0001..2 clocks
 *  0b0010..3 clocks
 *  0b1110..15 clocks
 *  0b1111..Reserved
 */
#define MMDC_MDCFG3LP_tRCD_LP(x)                 (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG3LP_tRCD_LP_SHIFT)) & MMDC_MDCFG3LP_tRCD_LP_MASK)

#define MMDC_MDCFG3LP_RC_LP_MASK                 (0x3F0000U)
#define MMDC_MDCFG3LP_RC_LP_SHIFT                (16U)
/*! RC_LP
 *  0b000000..1 clock
 *  0b000001..2 clocks
 *  0b000010..3 clocks
 *  0b111110..63 clocks
 *  0b111111..Reserved
 */
#define MMDC_MDCFG3LP_RC_LP(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MDCFG3LP_RC_LP_SHIFT)) & MMDC_MDCFG3LP_RC_LP_MASK)
/*! @} */

/*! @name MDMR4 - MMDC Core MR4 Derating Register */
/*! @{ */

#define MMDC_MDMR4_UPDATE_DE_REQ_MASK            (0x1U)
#define MMDC_MDMR4_UPDATE_DE_REQ_SHIFT           (0U)
/*! UPDATE_DE_REQ
 *  0b0..Do nothing.
 *  0b1..Request to update the following values: tRRD, tRCD, tRP, tRC, tRAS and refresh related fields(MDREF register): REF_CNT, REF_SEL, REFR
 */
#define MMDC_MDMR4_UPDATE_DE_REQ(x)              (((uint32_t)(((uint32_t)(x)) << MMDC_MDMR4_UPDATE_DE_REQ_SHIFT)) & MMDC_MDMR4_UPDATE_DE_REQ_MASK)

#define MMDC_MDMR4_UPDATE_DE_ACK_MASK            (0x2U)
#define MMDC_MDMR4_UPDATE_DE_ACK_SHIFT           (1U)
#define MMDC_MDMR4_UPDATE_DE_ACK(x)              (((uint32_t)(((uint32_t)(x)) << MMDC_MDMR4_UPDATE_DE_ACK_SHIFT)) & MMDC_MDMR4_UPDATE_DE_ACK_MASK)

#define MMDC_MDMR4_tRCD_DE_MASK                  (0x10U)
#define MMDC_MDMR4_tRCD_DE_SHIFT                 (4U)
/*! tRCD_DE
 *  0b0..Original tRCD is used.
 *  0b1..tRCD is derated in 1 cycle.
 */
#define MMDC_MDMR4_tRCD_DE(x)                    (((uint32_t)(((uint32_t)(x)) << MMDC_MDMR4_tRCD_DE_SHIFT)) & MMDC_MDMR4_tRCD_DE_MASK)

#define MMDC_MDMR4_tRC_DE_MASK                   (0x20U)
#define MMDC_MDMR4_tRC_DE_SHIFT                  (5U)
/*! tRC_DE
 *  0b0..Original tRC is used.
 *  0b1..tRC is derated in 1 cycle.
 */
#define MMDC_MDMR4_tRC_DE(x)                     (((uint32_t)(((uint32_t)(x)) << MMDC_MDMR4_tRC_DE_SHIFT)) & MMDC_MDMR4_tRC_DE_MASK)

#define MMDC_MDMR4_tRAS_DE_MASK                  (0x40U)
#define MMDC_MDMR4_tRAS_DE_SHIFT                 (6U)
/*! tRAS_DE
 *  0b0..Original tRAS is used.
 *  0b1..tRAS is derated in 1 cycle.
 */
#define MMDC_MDMR4_tRAS_DE(x)                    (((uint32_t)(((uint32_t)(x)) << MMDC_MDMR4_tRAS_DE_SHIFT)) & MMDC_MDMR4_tRAS_DE_MASK)

#define MMDC_MDMR4_tRP_DE_MASK                   (0x80U)
#define MMDC_MDMR4_tRP_DE_SHIFT                  (7U)
/*! tRP_DE
 *  0b0..Original tRP is used.
 *  0b1..tRP is derated in 1 cycle.
 */
#define MMDC_MDMR4_tRP_DE(x)                     (((uint32_t)(((uint32_t)(x)) << MMDC_MDMR4_tRP_DE_SHIFT)) & MMDC_MDMR4_tRP_DE_MASK)

#define MMDC_MDMR4_tRRD_DE_MASK                  (0x100U)
#define MMDC_MDMR4_tRRD_DE_SHIFT                 (8U)
/*! tRRD_DE
 *  0b0..Original tRRD is used.
 *  0b1..tRRD is derated in 1 cycle.
 */
#define MMDC_MDMR4_tRRD_DE(x)                    (((uint32_t)(((uint32_t)(x)) << MMDC_MDMR4_tRRD_DE_SHIFT)) & MMDC_MDMR4_tRRD_DE_MASK)
/*! @} */

/*! @name MDASP - MMDC Core Address Space Partition Register */
/*! @{ */

#define MMDC_MDASP_CS0_END_MASK                  (0x7FU)
#define MMDC_MDASP_CS0_END_SHIFT                 (0U)
#define MMDC_MDASP_CS0_END(x)                    (((uint32_t)(((uint32_t)(x)) << MMDC_MDASP_CS0_END_SHIFT)) & MMDC_MDASP_CS0_END_MASK)
/*! @} */

/*! @name MAARCR - MMDC Core AXI Reordering Control Register */
/*! @{ */

#define MMDC_MAARCR_ARCR_GUARD_MASK              (0xFU)
#define MMDC_MAARCR_ARCR_GUARD_SHIFT             (0U)
/*! ARCR_GUARD
 *  0b0000..15 (default)
 *  0b0001..16
 *  0b1111..30
 */
#define MMDC_MAARCR_ARCR_GUARD(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MAARCR_ARCR_GUARD_SHIFT)) & MMDC_MAARCR_ARCR_GUARD_MASK)

#define MMDC_MAARCR_ARCR_DYN_MAX_MASK            (0xF0U)
#define MMDC_MAARCR_ARCR_DYN_MAX_SHIFT           (4U)
/*! ARCR_DYN_MAX
 *  0b0000..0
 *  0b0001..1
 *  0b1111..15 (default)
 */
#define MMDC_MAARCR_ARCR_DYN_MAX(x)              (((uint32_t)(((uint32_t)(x)) << MMDC_MAARCR_ARCR_DYN_MAX_SHIFT)) & MMDC_MAARCR_ARCR_DYN_MAX_MASK)

#define MMDC_MAARCR_ARCR_DYN_JMP_MASK            (0xF00U)
#define MMDC_MAARCR_ARCR_DYN_JMP_SHIFT           (8U)
#define MMDC_MAARCR_ARCR_DYN_JMP(x)              (((uint32_t)(((uint32_t)(x)) << MMDC_MAARCR_ARCR_DYN_JMP_SHIFT)) & MMDC_MAARCR_ARCR_DYN_JMP_MASK)

#define MMDC_MAARCR_ARCR_ACC_HIT_MASK            (0x70000U)
#define MMDC_MAARCR_ARCR_ACC_HIT_SHIFT           (16U)
#define MMDC_MAARCR_ARCR_ACC_HIT(x)              (((uint32_t)(((uint32_t)(x)) << MMDC_MAARCR_ARCR_ACC_HIT_SHIFT)) & MMDC_MAARCR_ARCR_ACC_HIT_MASK)

#define MMDC_MAARCR_ARCR_PAG_HIT_MASK            (0x700000U)
#define MMDC_MAARCR_ARCR_PAG_HIT_SHIFT           (20U)
#define MMDC_MAARCR_ARCR_PAG_HIT(x)              (((uint32_t)(((uint32_t)(x)) << MMDC_MAARCR_ARCR_PAG_HIT_SHIFT)) & MMDC_MAARCR_ARCR_PAG_HIT_MASK)

#define MMDC_MAARCR_ARCR_RCH_EN_MASK             (0x1000000U)
#define MMDC_MAARCR_ARCR_RCH_EN_SHIFT            (24U)
/*! ARCR_RCH_EN
 *  0b0..normal prioritization, no bypassing
 *  0b1..accesses with QoS=='F' bypass the arbitration
 */
#define MMDC_MAARCR_ARCR_RCH_EN(x)               (((uint32_t)(((uint32_t)(x)) << MMDC_MAARCR_ARCR_RCH_EN_SHIFT)) & MMDC_MAARCR_ARCR_RCH_EN_MASK)

#define MMDC_MAARCR_ARCR_EXC_ERR_EN_MASK         (0x10000000U)
#define MMDC_MAARCR_ARCR_EXC_ERR_EN_SHIFT        (28U)
/*! ARCR_EXC_ERR_EN
 *  0b0..violation of AXI exclusive rules (6.2.4) result in OKAY response (rresp/bresp=2'b00)
 *  0b1..violation of AXI exclusive rules (6.2.4) result in SLAVE Error response (rresp/bresp=2'b10)
 */
#define MMDC_MAARCR_ARCR_EXC_ERR_EN(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MAARCR_ARCR_EXC_ERR_EN_SHIFT)) & MMDC_MAARCR_ARCR_EXC_ERR_EN_MASK)

#define MMDC_MAARCR_ARCR_SEC_ERR_EN_MASK         (0x40000000U)
#define MMDC_MAARCR_ARCR_SEC_ERR_EN_SHIFT        (30U)
/*! ARCR_SEC_ERR_EN
 *  0b0..security violation results in OKAY response (rresp/bresp=2'b00)
 *  0b1..security violation results in SLAVE Error response (rresp/bresp=2'b10)
 */
#define MMDC_MAARCR_ARCR_SEC_ERR_EN(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MAARCR_ARCR_SEC_ERR_EN_SHIFT)) & MMDC_MAARCR_ARCR_SEC_ERR_EN_MASK)

#define MMDC_MAARCR_ARCR_SEC_ERR_LOCK_MASK       (0x80000000U)
#define MMDC_MAARCR_ARCR_SEC_ERR_LOCK_SHIFT      (31U)
/*! ARCR_SEC_ERR_LOCK
 *  0b0..ARCR_SEC_ERR_EN is unlocked, so can be updated any moment
 *  0b1..ARCR_SEC_ERR_EN is locked, so it can't be updated
 */
#define MMDC_MAARCR_ARCR_SEC_ERR_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MAARCR_ARCR_SEC_ERR_LOCK_SHIFT)) & MMDC_MAARCR_ARCR_SEC_ERR_LOCK_MASK)
/*! @} */

/*! @name MAPSR - MMDC Core Power Saving Control and Status Register */
/*! @{ */

#define MMDC_MAPSR_PSD_MASK                      (0x1U)
#define MMDC_MAPSR_PSD_SHIFT                     (0U)
/*! PSD
 *  0b0..power saving enabled
 *  0b1..power saving disabled (default)
 */
#define MMDC_MAPSR_PSD(x)                        (((uint32_t)(((uint32_t)(x)) << MMDC_MAPSR_PSD_SHIFT)) & MMDC_MAPSR_PSD_MASK)

#define MMDC_MAPSR_PSS_MASK                      (0x10U)
#define MMDC_MAPSR_PSS_SHIFT                     (4U)
/*! PSS
 *  0b0..not in power saving mode
 *  0b1..power saving mode
 */
#define MMDC_MAPSR_PSS(x)                        (((uint32_t)(((uint32_t)(x)) << MMDC_MAPSR_PSS_SHIFT)) & MMDC_MAPSR_PSS_MASK)

#define MMDC_MAPSR_RIS_MASK                      (0x20U)
#define MMDC_MAPSR_RIS_SHIFT                     (5U)
/*! RIS
 *  0b0..not idle
 *  0b1..idle
 */
#define MMDC_MAPSR_RIS(x)                        (((uint32_t)(((uint32_t)(x)) << MMDC_MAPSR_RIS_SHIFT)) & MMDC_MAPSR_RIS_MASK)

#define MMDC_MAPSR_WIS_MASK                      (0x40U)
#define MMDC_MAPSR_WIS_SHIFT                     (6U)
/*! WIS
 *  0b0..not idle
 *  0b1..idle
 */
#define MMDC_MAPSR_WIS(x)                        (((uint32_t)(((uint32_t)(x)) << MMDC_MAPSR_WIS_SHIFT)) & MMDC_MAPSR_WIS_MASK)

#define MMDC_MAPSR_PST_MASK                      (0xFF00U)
#define MMDC_MAPSR_PST_SHIFT                     (8U)
/*! PST
 *  0b00000000..Reserved - this value is forbidden.
 *  0b00000001..timer is configured to 64 clock cycles.
 *  0b00000010..timer is configured to 128 clock cycles.
 *  0b00010000..(Default)- 1024 clock cycles.
 *  0b11111111..timer clock is configured to 16320 clock cycles.
 */
#define MMDC_MAPSR_PST(x)                        (((uint32_t)(((uint32_t)(x)) << MMDC_MAPSR_PST_SHIFT)) & MMDC_MAPSR_PST_MASK)

#define MMDC_MAPSR_LPMD_MASK                     (0x100000U)
#define MMDC_MAPSR_LPMD_SHIFT                    (20U)
/*! LPMD
 *  0b0..no lpmd request
 *  0b1..lpmd request
 */
#define MMDC_MAPSR_LPMD(x)                       (((uint32_t)(((uint32_t)(x)) << MMDC_MAPSR_LPMD_SHIFT)) & MMDC_MAPSR_LPMD_MASK)

#define MMDC_MAPSR_DVFS_MASK                     (0x200000U)
#define MMDC_MAPSR_DVFS_SHIFT                    (21U)
/*! DVFS
 *  0b0..no DVFS/Self-Refresh entry request
 *  0b1..DVFS/Self-Refresh entry request
 */
#define MMDC_MAPSR_DVFS(x)                       (((uint32_t)(((uint32_t)(x)) << MMDC_MAPSR_DVFS_SHIFT)) & MMDC_MAPSR_DVFS_MASK)

#define MMDC_MAPSR_LPACK_MASK                    (0x1000000U)
#define MMDC_MAPSR_LPACK_SHIFT                   (24U)
#define MMDC_MAPSR_LPACK(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MAPSR_LPACK_SHIFT)) & MMDC_MAPSR_LPACK_MASK)

#define MMDC_MAPSR_DVACK_MASK                    (0x2000000U)
#define MMDC_MAPSR_DVACK_SHIFT                   (25U)
#define MMDC_MAPSR_DVACK(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MAPSR_DVACK_SHIFT)) & MMDC_MAPSR_DVACK_MASK)
/*! @} */

/*! @name MAEXIDR0 - MMDC Core Exclusive ID Monitor Register0 */
/*! @{ */

#define MMDC_MAEXIDR0_EXC_ID_MONITOR0_MASK       (0xFFFFU)
#define MMDC_MAEXIDR0_EXC_ID_MONITOR0_SHIFT      (0U)
#define MMDC_MAEXIDR0_EXC_ID_MONITOR0(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MAEXIDR0_EXC_ID_MONITOR0_SHIFT)) & MMDC_MAEXIDR0_EXC_ID_MONITOR0_MASK)

#define MMDC_MAEXIDR0_EXC_ID_MONITOR1_MASK       (0xFFFF0000U)
#define MMDC_MAEXIDR0_EXC_ID_MONITOR1_SHIFT      (16U)
#define MMDC_MAEXIDR0_EXC_ID_MONITOR1(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MAEXIDR0_EXC_ID_MONITOR1_SHIFT)) & MMDC_MAEXIDR0_EXC_ID_MONITOR1_MASK)
/*! @} */

/*! @name MAEXIDR1 - MMDC Core Exclusive ID Monitor Register1 */
/*! @{ */

#define MMDC_MAEXIDR1_EXC_ID_MONITOR2_MASK       (0xFFFFU)
#define MMDC_MAEXIDR1_EXC_ID_MONITOR2_SHIFT      (0U)
#define MMDC_MAEXIDR1_EXC_ID_MONITOR2(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MAEXIDR1_EXC_ID_MONITOR2_SHIFT)) & MMDC_MAEXIDR1_EXC_ID_MONITOR2_MASK)

#define MMDC_MAEXIDR1_EXC_ID_MONITOR3_MASK       (0xFFFF0000U)
#define MMDC_MAEXIDR1_EXC_ID_MONITOR3_SHIFT      (16U)
#define MMDC_MAEXIDR1_EXC_ID_MONITOR3(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MAEXIDR1_EXC_ID_MONITOR3_SHIFT)) & MMDC_MAEXIDR1_EXC_ID_MONITOR3_MASK)
/*! @} */

/*! @name MADPCR0 - MMDC Core Debug and Profiling Control Register 0 */
/*! @{ */

#define MMDC_MADPCR0_DBG_EN_MASK                 (0x1U)
#define MMDC_MADPCR0_DBG_EN_SHIFT                (0U)
/*! DBG_EN
 *  0b0..disable (default)
 *  0b1..enable
 */
#define MMDC_MADPCR0_DBG_EN(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MADPCR0_DBG_EN_SHIFT)) & MMDC_MADPCR0_DBG_EN_MASK)

#define MMDC_MADPCR0_DBG_RST_MASK                (0x2U)
#define MMDC_MADPCR0_DBG_RST_SHIFT               (1U)
/*! DBG_RST
 *  0b0..no reset
 *  0b1..reset
 */
#define MMDC_MADPCR0_DBG_RST(x)                  (((uint32_t)(((uint32_t)(x)) << MMDC_MADPCR0_DBG_RST_SHIFT)) & MMDC_MADPCR0_DBG_RST_MASK)

#define MMDC_MADPCR0_PRF_FRZ_MASK                (0x4U)
#define MMDC_MADPCR0_PRF_FRZ_SHIFT               (2U)
/*! PRF_FRZ
 *  0b0..profiling counters are not frozen
 *  0b1..profiling counters are frozen
 */
#define MMDC_MADPCR0_PRF_FRZ(x)                  (((uint32_t)(((uint32_t)(x)) << MMDC_MADPCR0_PRF_FRZ_SHIFT)) & MMDC_MADPCR0_PRF_FRZ_MASK)

#define MMDC_MADPCR0_CYC_OVF_MASK                (0x8U)
#define MMDC_MADPCR0_CYC_OVF_SHIFT               (3U)
/*! CYC_OVF
 *  0b0..no overflow
 *  0b1..overflow
 */
#define MMDC_MADPCR0_CYC_OVF(x)                  (((uint32_t)(((uint32_t)(x)) << MMDC_MADPCR0_CYC_OVF_SHIFT)) & MMDC_MADPCR0_CYC_OVF_MASK)

#define MMDC_MADPCR0_SBS_EN_MASK                 (0x100U)
#define MMDC_MADPCR0_SBS_EN_SHIFT                (8U)
/*! SBS_EN
 *  0b0..disable
 *  0b1..enable
 */
#define MMDC_MADPCR0_SBS_EN(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MADPCR0_SBS_EN_SHIFT)) & MMDC_MADPCR0_SBS_EN_MASK)

#define MMDC_MADPCR0_SBS_MASK                    (0x200U)
#define MMDC_MADPCR0_SBS_SHIFT                   (9U)
/*! SBS
 *  0b0..No access will be launched toward the DDR
 *  0b1..Launch AXI pending access toward the DDR
 */
#define MMDC_MADPCR0_SBS(x)                      (((uint32_t)(((uint32_t)(x)) << MMDC_MADPCR0_SBS_SHIFT)) & MMDC_MADPCR0_SBS_MASK)
/*! @} */

/*! @name MADPCR1 - MMDC Core Debug and Profiling Control Register 1 */
/*! @{ */

#define MMDC_MADPCR1_PRF_AXI_ID_MASK             (0xFFFFU)
#define MMDC_MADPCR1_PRF_AXI_ID_SHIFT            (0U)
#define MMDC_MADPCR1_PRF_AXI_ID(x)               (((uint32_t)(((uint32_t)(x)) << MMDC_MADPCR1_PRF_AXI_ID_SHIFT)) & MMDC_MADPCR1_PRF_AXI_ID_MASK)

#define MMDC_MADPCR1_PRF_AXI_IDMASK_MASK         (0xFFFF0000U)
#define MMDC_MADPCR1_PRF_AXI_IDMASK_SHIFT        (16U)
/*! PRF_AXI_IDMASK
 *  0b0000000000000000..AXI ID specific bit is ignored (don't care)
 *  0b0000000000000001..AXI ID specific bit is chosen for profiling
 */
#define MMDC_MADPCR1_PRF_AXI_IDMASK(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MADPCR1_PRF_AXI_IDMASK_SHIFT)) & MMDC_MADPCR1_PRF_AXI_IDMASK_MASK)
/*! @} */

/*! @name MADPSR0 - MMDC Core Debug and Profiling Status Register 0 */
/*! @{ */

#define MMDC_MADPSR0_CYC_COUNT_MASK              (0xFFFFFFFFU)
#define MMDC_MADPSR0_CYC_COUNT_SHIFT             (0U)
#define MMDC_MADPSR0_CYC_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MADPSR0_CYC_COUNT_SHIFT)) & MMDC_MADPSR0_CYC_COUNT_MASK)
/*! @} */

/*! @name MADPSR1 - MMDC Core Debug and Profiling Status Register 1 */
/*! @{ */

#define MMDC_MADPSR1_BUSY_COUNT_MASK             (0xFFFFFFFFU)
#define MMDC_MADPSR1_BUSY_COUNT_SHIFT            (0U)
#define MMDC_MADPSR1_BUSY_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << MMDC_MADPSR1_BUSY_COUNT_SHIFT)) & MMDC_MADPSR1_BUSY_COUNT_MASK)
/*! @} */

/*! @name MADPSR2 - MMDC Core Debug and Profiling Status Register 2 */
/*! @{ */

#define MMDC_MADPSR2_RD_ACC_COUNT_MASK           (0xFFFFFFFFU)
#define MMDC_MADPSR2_RD_ACC_COUNT_SHIFT          (0U)
#define MMDC_MADPSR2_RD_ACC_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MADPSR2_RD_ACC_COUNT_SHIFT)) & MMDC_MADPSR2_RD_ACC_COUNT_MASK)
/*! @} */

/*! @name MADPSR3 - MMDC Core Debug and Profiling Status Register 3 */
/*! @{ */

#define MMDC_MADPSR3_WR_ACC_COUNT_MASK           (0xFFFFFFFFU)
#define MMDC_MADPSR3_WR_ACC_COUNT_SHIFT          (0U)
#define MMDC_MADPSR3_WR_ACC_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MADPSR3_WR_ACC_COUNT_SHIFT)) & MMDC_MADPSR3_WR_ACC_COUNT_MASK)
/*! @} */

/*! @name MADPSR4 - MMDC Core Debug and Profiling Status Register 4 */
/*! @{ */

#define MMDC_MADPSR4_RD_BYTES_COUNT_MASK         (0xFFFFFFFFU)
#define MMDC_MADPSR4_RD_BYTES_COUNT_SHIFT        (0U)
#define MMDC_MADPSR4_RD_BYTES_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MADPSR4_RD_BYTES_COUNT_SHIFT)) & MMDC_MADPSR4_RD_BYTES_COUNT_MASK)
/*! @} */

/*! @name MADPSR5 - MMDC Core Debug and Profiling Status Register 5 */
/*! @{ */

#define MMDC_MADPSR5_WR_BYTES_COUNT_MASK         (0xFFFFFFFFU)
#define MMDC_MADPSR5_WR_BYTES_COUNT_SHIFT        (0U)
#define MMDC_MADPSR5_WR_BYTES_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MADPSR5_WR_BYTES_COUNT_SHIFT)) & MMDC_MADPSR5_WR_BYTES_COUNT_MASK)
/*! @} */

/*! @name MASBS0 - MMDC Core Step By Step Address Register */
/*! @{ */

#define MMDC_MASBS0_SBS_ADDR_MASK                (0xFFFFFFFFU)
#define MMDC_MASBS0_SBS_ADDR_SHIFT               (0U)
#define MMDC_MASBS0_SBS_ADDR(x)                  (((uint32_t)(((uint32_t)(x)) << MMDC_MASBS0_SBS_ADDR_SHIFT)) & MMDC_MASBS0_SBS_ADDR_MASK)
/*! @} */

/*! @name MASBS1 - MMDC Core Step By Step Address Attributes Register */
/*! @{ */

#define MMDC_MASBS1_SBS_VLD_MASK                 (0x1U)
#define MMDC_MASBS1_SBS_VLD_SHIFT                (0U)
/*! SBS_VLD
 *  0b0..not valid
 *  0b1..valid
 */
#define MMDC_MASBS1_SBS_VLD(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MASBS1_SBS_VLD_SHIFT)) & MMDC_MASBS1_SBS_VLD_MASK)

#define MMDC_MASBS1_SBS_TYPE_MASK                (0x2U)
#define MMDC_MASBS1_SBS_TYPE_SHIFT               (1U)
/*! SBS_TYPE
 *  0b0..write
 *  0b1..read
 */
#define MMDC_MASBS1_SBS_TYPE(x)                  (((uint32_t)(((uint32_t)(x)) << MMDC_MASBS1_SBS_TYPE_SHIFT)) & MMDC_MASBS1_SBS_TYPE_MASK)

#define MMDC_MASBS1_SBS_LOCK_MASK                (0xCU)
#define MMDC_MASBS1_SBS_LOCK_SHIFT               (2U)
#define MMDC_MASBS1_SBS_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << MMDC_MASBS1_SBS_LOCK_SHIFT)) & MMDC_MASBS1_SBS_LOCK_MASK)

#define MMDC_MASBS1_SBS_PROT_MASK                (0x70U)
#define MMDC_MASBS1_SBS_PROT_SHIFT               (4U)
#define MMDC_MASBS1_SBS_PROT(x)                  (((uint32_t)(((uint32_t)(x)) << MMDC_MASBS1_SBS_PROT_SHIFT)) & MMDC_MASBS1_SBS_PROT_MASK)

#define MMDC_MASBS1_SBS_SIZE_MASK                (0x380U)
#define MMDC_MASBS1_SBS_SIZE_SHIFT               (7U)
/*! SBS_SIZE
 *  0b000..8 bits
 *  0b001..16 bits
 *  0b010..32 bits
 *  0b011..64 bits
 *  0b100..128bits
 *  0b101-0b111..Reserved
 */
#define MMDC_MASBS1_SBS_SIZE(x)                  (((uint32_t)(((uint32_t)(x)) << MMDC_MASBS1_SBS_SIZE_SHIFT)) & MMDC_MASBS1_SBS_SIZE_MASK)

#define MMDC_MASBS1_SBS_BURST_MASK               (0xC00U)
#define MMDC_MASBS1_SBS_BURST_SHIFT              (10U)
/*! SBS_BURST
 *  0b00..FIXED
 *  0b01..INCR burst
 *  0b10..WRAP burst
 *  0b11..reserved
 */
#define MMDC_MASBS1_SBS_BURST(x)                 (((uint32_t)(((uint32_t)(x)) << MMDC_MASBS1_SBS_BURST_SHIFT)) & MMDC_MASBS1_SBS_BURST_MASK)

#define MMDC_MASBS1_SBS_BUFF_MASK                (0x1000U)
#define MMDC_MASBS1_SBS_BUFF_SHIFT               (12U)
#define MMDC_MASBS1_SBS_BUFF(x)                  (((uint32_t)(((uint32_t)(x)) << MMDC_MASBS1_SBS_BUFF_SHIFT)) & MMDC_MASBS1_SBS_BUFF_MASK)

#define MMDC_MASBS1_SBS_LEN_MASK                 (0xE000U)
#define MMDC_MASBS1_SBS_LEN_SHIFT                (13U)
/*! SBS_LEN
 *  0b000..burst of length 1
 *  0b001..burst of length 2
 *  0b111..burst of length 8
 */
#define MMDC_MASBS1_SBS_LEN(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MASBS1_SBS_LEN_SHIFT)) & MMDC_MASBS1_SBS_LEN_MASK)

#define MMDC_MASBS1_SBS_AXI_ID_MASK              (0xFFFF0000U)
#define MMDC_MASBS1_SBS_AXI_ID_SHIFT             (16U)
#define MMDC_MASBS1_SBS_AXI_ID(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MASBS1_SBS_AXI_ID_SHIFT)) & MMDC_MASBS1_SBS_AXI_ID_MASK)
/*! @} */

/*! @name MAGENP - MMDC Core General Purpose Register */
/*! @{ */

#define MMDC_MAGENP_GP31_GP0_MASK                (0xFFFFFFFFU)
#define MMDC_MAGENP_GP31_GP0_SHIFT               (0U)
#define MMDC_MAGENP_GP31_GP0(x)                  (((uint32_t)(((uint32_t)(x)) << MMDC_MAGENP_GP31_GP0_SHIFT)) & MMDC_MAGENP_GP31_GP0_MASK)
/*! @} */

/*! @name MPZQHWCTRL - MMDC PHY ZQ HW control register */
/*! @{ */

#define MMDC_MPZQHWCTRL_ZQ_MODE_MASK             (0x3U)
#define MMDC_MPZQHWCTRL_ZQ_MODE_SHIFT            (0U)
/*! ZQ_MODE
 *  0b00..No ZQ calibration is issued. (Default)
 *  0b01..ZQ calibration is issued to i.MX ZQ calibration pad together with ZQ long command to the external DDR device only when exiting self refresh.
 *  0b10..ZQ calibration command long/short is issued only to the external DDR device periodically and when exiting self refresh
 *  0b11..ZQ calibration is issued to i.MX ZQ calibration pad together with ZQ calibration command long/short to
 *        the external DDR device periodically and when exiting self refresh
 */
#define MMDC_MPZQHWCTRL_ZQ_MODE(x)               (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQHWCTRL_ZQ_MODE_SHIFT)) & MMDC_MPZQHWCTRL_ZQ_MODE_MASK)

#define MMDC_MPZQHWCTRL_ZQ_HW_PER_MASK           (0x3CU)
#define MMDC_MPZQHWCTRL_ZQ_HW_PER_SHIFT          (2U)
/*! ZQ_HW_PER
 *  0b0000..ZQ calibration is performed every 1 ms.
 *  0b0001..ZQ calibration is performed every 2 ms.
 *  0b0010..ZQ calibration is performed every 4 ms.
 *  0b1010..ZQ calibration is performed every 1 sec.
 *  0b1110..ZQ calibration is performed every 16 sec.
 *  0b1111..ZQ calibration is performed every 32 sec.
 */
#define MMDC_MPZQHWCTRL_ZQ_HW_PER(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQHWCTRL_ZQ_HW_PER_SHIFT)) & MMDC_MPZQHWCTRL_ZQ_HW_PER_MASK)

#define MMDC_MPZQHWCTRL_ZQ_HW_PU_RES_MASK        (0x7C0U)
#define MMDC_MPZQHWCTRL_ZQ_HW_PU_RES_SHIFT       (6U)
/*! ZQ_HW_PU_RES
 *  0b00000..Min. resistance.
 *  0b11111..Max. resistance.
 */
#define MMDC_MPZQHWCTRL_ZQ_HW_PU_RES(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQHWCTRL_ZQ_HW_PU_RES_SHIFT)) & MMDC_MPZQHWCTRL_ZQ_HW_PU_RES_MASK)

#define MMDC_MPZQHWCTRL_ZQ_HW_PD_RES_MASK        (0xF800U)
#define MMDC_MPZQHWCTRL_ZQ_HW_PD_RES_SHIFT       (11U)
/*! ZQ_HW_PD_RES
 *  0b00000..Max. resistance.
 *  0b11111..Min. resistance.
 */
#define MMDC_MPZQHWCTRL_ZQ_HW_PD_RES(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQHWCTRL_ZQ_HW_PD_RES_SHIFT)) & MMDC_MPZQHWCTRL_ZQ_HW_PD_RES_MASK)

#define MMDC_MPZQHWCTRL_ZQ_HW_FOR_MASK           (0x10000U)
#define MMDC_MPZQHWCTRL_ZQ_HW_FOR_SHIFT          (16U)
#define MMDC_MPZQHWCTRL_ZQ_HW_FOR(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQHWCTRL_ZQ_HW_FOR_SHIFT)) & MMDC_MPZQHWCTRL_ZQ_HW_FOR_MASK)

#define MMDC_MPZQHWCTRL_TZQ_INIT_MASK            (0xE0000U)
#define MMDC_MPZQHWCTRL_TZQ_INIT_SHIFT           (17U)
/*! TZQ_INIT
 *  0b000..Reserved
 *  0b001..Reserved
 *  0b010..128 cycles
 *  0b011..256 cycles
 *  0b100..512 cycles - Default
 *  0b101..1024 cycles
 */
#define MMDC_MPZQHWCTRL_TZQ_INIT(x)              (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQHWCTRL_TZQ_INIT_SHIFT)) & MMDC_MPZQHWCTRL_TZQ_INIT_MASK)

#define MMDC_MPZQHWCTRL_TZQ_OPER_MASK            (0x700000U)
#define MMDC_MPZQHWCTRL_TZQ_OPER_SHIFT           (20U)
/*! TZQ_OPER
 *  0b000..Reserved
 *  0b001..Reserved
 *  0b010..128 cycles
 *  0b011..256 cycles - Default
 *  0b100..512 cycles
 *  0b101..1024 cycles
 */
#define MMDC_MPZQHWCTRL_TZQ_OPER(x)              (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQHWCTRL_TZQ_OPER_SHIFT)) & MMDC_MPZQHWCTRL_TZQ_OPER_MASK)

#define MMDC_MPZQHWCTRL_TZQ_CS_MASK              (0x3800000U)
#define MMDC_MPZQHWCTRL_TZQ_CS_SHIFT             (23U)
/*! TZQ_CS
 *  0b000..Reserved
 *  0b001..Reserved
 *  0b010..128 cycles (Default)
 *  0b011..256 cycles
 *  0b100..512 cycles
 *  0b101..1024 cycles
 */
#define MMDC_MPZQHWCTRL_TZQ_CS(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQHWCTRL_TZQ_CS_SHIFT)) & MMDC_MPZQHWCTRL_TZQ_CS_MASK)

#define MMDC_MPZQHWCTRL_ZQ_PARA_EN_MASK          (0x4000000U)
#define MMDC_MPZQHWCTRL_ZQ_PARA_EN_SHIFT         (26U)
/*! ZQ_PARA_EN
 *  0b0..Device ZQ calibration is done in serial (CS0 first and then CS1).
 *  0b1..ZQ calibration of both CS is done in parallel
 */
#define MMDC_MPZQHWCTRL_ZQ_PARA_EN(x)            (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQHWCTRL_ZQ_PARA_EN_SHIFT)) & MMDC_MPZQHWCTRL_ZQ_PARA_EN_MASK)

#define MMDC_MPZQHWCTRL_ZQ_EARLY_COMPARATOR_EN_TIMER_MASK (0xF8000000U)
#define MMDC_MPZQHWCTRL_ZQ_EARLY_COMPARATOR_EN_TIMER_SHIFT (27U)
/*! ZQ_EARLY_COMPARATOR_EN_TIMER
 *  0b00000..- 0x6 Reserved
 *  0b00111..8 cycles
 *  0b10100..21 cycles (Default)
 *  0b11110..31 cycles
 *  0b11111..32 cycles
 */
#define MMDC_MPZQHWCTRL_ZQ_EARLY_COMPARATOR_EN_TIMER(x) (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQHWCTRL_ZQ_EARLY_COMPARATOR_EN_TIMER_SHIFT)) & MMDC_MPZQHWCTRL_ZQ_EARLY_COMPARATOR_EN_TIMER_MASK)
/*! @} */

/*! @name MPZQSWCTRL - MMDC PHY ZQ SW control register */
/*! @{ */

#define MMDC_MPZQSWCTRL_ZQ_SW_FOR_MASK           (0x1U)
#define MMDC_MPZQSWCTRL_ZQ_SW_FOR_SHIFT          (0U)
#define MMDC_MPZQSWCTRL_ZQ_SW_FOR(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQSWCTRL_ZQ_SW_FOR_SHIFT)) & MMDC_MPZQSWCTRL_ZQ_SW_FOR_MASK)

#define MMDC_MPZQSWCTRL_ZQ_SW_RES_MASK           (0x2U)
#define MMDC_MPZQSWCTRL_ZQ_SW_RES_SHIFT          (1U)
/*! ZQ_SW_RES
 *  0b0..Current ZQ calibration voltage is less than VDD/2.
 *  0b1..Current ZQ calibration voltage is more than VDD/2
 */
#define MMDC_MPZQSWCTRL_ZQ_SW_RES(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQSWCTRL_ZQ_SW_RES_SHIFT)) & MMDC_MPZQSWCTRL_ZQ_SW_RES_MASK)

#define MMDC_MPZQSWCTRL_ZQ_SW_PU_VAL_MASK        (0x7CU)
#define MMDC_MPZQSWCTRL_ZQ_SW_PU_VAL_SHIFT       (2U)
/*! ZQ_SW_PU_VAL
 *  0b00000..Min. resistance.
 *  0b11111..Max. resistance.
 */
#define MMDC_MPZQSWCTRL_ZQ_SW_PU_VAL(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQSWCTRL_ZQ_SW_PU_VAL_SHIFT)) & MMDC_MPZQSWCTRL_ZQ_SW_PU_VAL_MASK)

#define MMDC_MPZQSWCTRL_ZQ_SW_PD_VAL_MASK        (0xF80U)
#define MMDC_MPZQSWCTRL_ZQ_SW_PD_VAL_SHIFT       (7U)
/*! ZQ_SW_PD_VAL
 *  0b00000..Max. resistance.
 *  0b11111..Min. resistance.
 */
#define MMDC_MPZQSWCTRL_ZQ_SW_PD_VAL(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQSWCTRL_ZQ_SW_PD_VAL_SHIFT)) & MMDC_MPZQSWCTRL_ZQ_SW_PD_VAL_MASK)

#define MMDC_MPZQSWCTRL_ZQ_SW_PD_MASK            (0x1000U)
#define MMDC_MPZQSWCTRL_ZQ_SW_PD_SHIFT           (12U)
/*! ZQ_SW_PD
 *  0b0..PU resistor calibration
 *  0b1..PD resistor calibration
 */
#define MMDC_MPZQSWCTRL_ZQ_SW_PD(x)              (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQSWCTRL_ZQ_SW_PD_SHIFT)) & MMDC_MPZQSWCTRL_ZQ_SW_PD_MASK)

#define MMDC_MPZQSWCTRL_USE_ZQ_SW_VAL_MASK       (0x2000U)
#define MMDC_MPZQSWCTRL_USE_ZQ_SW_VAL_SHIFT      (13U)
/*! USE_ZQ_SW_VAL
 *  0b0..Fields ZQ_HW_PD_VAL & ZQ_HW_PU_VAL will be driven to I/O pads resistor controls.
 *  0b1..Fields ZQ_SW_PD_VAL & ZQ_SW_PU_VAL will be driven to I/O pads resistor controls.
 */
#define MMDC_MPZQSWCTRL_USE_ZQ_SW_VAL(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQSWCTRL_USE_ZQ_SW_VAL_SHIFT)) & MMDC_MPZQSWCTRL_USE_ZQ_SW_VAL_MASK)

#define MMDC_MPZQSWCTRL_ZQ_CMP_OUT_SMP_MASK      (0x30000U)
#define MMDC_MPZQSWCTRL_ZQ_CMP_OUT_SMP_SHIFT     (16U)
/*! ZQ_CMP_OUT_SMP
 *  0b00..7 cycles
 *  0b01..15 cycles
 *  0b10..23 cycles
 *  0b11..31 cycles
 */
#define MMDC_MPZQSWCTRL_ZQ_CMP_OUT_SMP(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQSWCTRL_ZQ_CMP_OUT_SMP_SHIFT)) & MMDC_MPZQSWCTRL_ZQ_CMP_OUT_SMP_MASK)
/*! @} */

/*! @name MPRDDQBY0DL - MMDC PHY Read DQ Byte0 Delay Register */
/*! @{ */

#define MMDC_MPRDDQBY0DL_rd_dq0_del_MASK         (0x7U)
#define MMDC_MPRDDQBY0DL_rd_dq0_del_SHIFT        (0U)
/*! rd_dq0_del
 *  0b000..No change in dq0 delay
 *  0b001..Add dq0 delay of 1 delay unit
 *  0b010..Add dq0 delay of 2 delay units.
 *  0b011..Add dq0 delay of 3 delay units.
 *  0b100..Add dq0 delay of 4 delay units.
 *  0b101..Add dq0 delay of 5 delay units.
 *  0b110..Add dq0 delay of 6 delay units.
 *  0b111..Add dq0 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY0DL_rd_dq0_del(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY0DL_rd_dq0_del_SHIFT)) & MMDC_MPRDDQBY0DL_rd_dq0_del_MASK)

#define MMDC_MPRDDQBY0DL_rd_dq1_del_MASK         (0x70U)
#define MMDC_MPRDDQBY0DL_rd_dq1_del_SHIFT        (4U)
/*! rd_dq1_del
 *  0b000..No change in dq1 delay
 *  0b001..Add dq1 delay of 1 delay unit
 *  0b010..Add dq1 delay of 2 delay units.
 *  0b011..Add dq1 delay of 3 delay units.
 *  0b100..Add dq1 delay of 4 delay units.
 *  0b101..Add dq1 delay of 5 delay units.
 *  0b110..Add dq1 delay of 6 delay units.
 *  0b111..Add dq1 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY0DL_rd_dq1_del(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY0DL_rd_dq1_del_SHIFT)) & MMDC_MPRDDQBY0DL_rd_dq1_del_MASK)

#define MMDC_MPRDDQBY0DL_rd_dq2_del_MASK         (0x700U)
#define MMDC_MPRDDQBY0DL_rd_dq2_del_SHIFT        (8U)
/*! rd_dq2_del
 *  0b000..No change in dq2 delay
 *  0b001..Add dq2 delay of 1 delay unit
 *  0b010..Add dq2 delay of 2 delay units.
 *  0b011..Add dq2 delay of 3 delay units.
 *  0b100..Add dq2 delay of 4 delay units.
 *  0b101..Add dq2 delay of 5 delay units.
 *  0b110..Add dq2 delay of 6 delay units.
 *  0b111..Add dq2 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY0DL_rd_dq2_del(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY0DL_rd_dq2_del_SHIFT)) & MMDC_MPRDDQBY0DL_rd_dq2_del_MASK)

#define MMDC_MPRDDQBY0DL_rd_dq3_del_MASK         (0x7000U)
#define MMDC_MPRDDQBY0DL_rd_dq3_del_SHIFT        (12U)
/*! rd_dq3_del
 *  0b000..No change in dq3 delay
 *  0b001..Add dq3 delay of 1 delay unit
 *  0b010..Add dq3 delay of 2 delay units.
 *  0b011..Add dq3 delay of 3 delay units.
 *  0b100..Add dq3 delay of 4 delay units.
 *  0b101..Add dq3 delay of 5 delay units.
 *  0b110..Add dq3 delay of 6 delay units.
 *  0b111..Add dq3 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY0DL_rd_dq3_del(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY0DL_rd_dq3_del_SHIFT)) & MMDC_MPRDDQBY0DL_rd_dq3_del_MASK)

#define MMDC_MPRDDQBY0DL_rd_dq4_del_MASK         (0x70000U)
#define MMDC_MPRDDQBY0DL_rd_dq4_del_SHIFT        (16U)
/*! rd_dq4_del
 *  0b000..No change in dq4 delay
 *  0b001..Add dq4 delay of 1 delay unit
 *  0b010..Add dq4 delay of 2 delay units.
 *  0b011..Add dq4 delay of 3 delay units.
 *  0b100..Add dq4 delay of 4 delay units.
 *  0b101..Add dq4 delay of 5 delay units.
 *  0b110..Add dq4 delay of 6 delay units.
 *  0b111..Add dq4 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY0DL_rd_dq4_del(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY0DL_rd_dq4_del_SHIFT)) & MMDC_MPRDDQBY0DL_rd_dq4_del_MASK)

#define MMDC_MPRDDQBY0DL_rd_dq5_del_MASK         (0x700000U)
#define MMDC_MPRDDQBY0DL_rd_dq5_del_SHIFT        (20U)
/*! rd_dq5_del
 *  0b000..No change in dq5 delay
 *  0b001..Add dq5 delay of 1 delay unit
 *  0b010..Add dq5 delay of 2 delay units.
 *  0b011..Add dq5 delay of 3 delay units.
 *  0b100..Add dq5 delay of 4 delay units.
 *  0b101..Add dq5 delay of 5 delay units.
 *  0b110..Add dq5 delay of 6 delay units.
 *  0b111..Add dq5 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY0DL_rd_dq5_del(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY0DL_rd_dq5_del_SHIFT)) & MMDC_MPRDDQBY0DL_rd_dq5_del_MASK)

#define MMDC_MPRDDQBY0DL_rd_dq6_del_MASK         (0x7000000U)
#define MMDC_MPRDDQBY0DL_rd_dq6_del_SHIFT        (24U)
/*! rd_dq6_del
 *  0b000..No change in dq6 delay
 *  0b001..Add dq6 delay of 1 delay unit
 *  0b010..Add dq6 delay of 2 delay units.
 *  0b011..Add dq6 delay of 3 delay units.
 *  0b100..Add dq6 delay of 4 delay units.
 *  0b101..Add dq6 delay of 5 delay units.
 *  0b110..Add dq6 delay of 6 delay units.
 *  0b111..Add dq6 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY0DL_rd_dq6_del(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY0DL_rd_dq6_del_SHIFT)) & MMDC_MPRDDQBY0DL_rd_dq6_del_MASK)

#define MMDC_MPRDDQBY0DL_rd_dq7_del_MASK         (0x70000000U)
#define MMDC_MPRDDQBY0DL_rd_dq7_del_SHIFT        (28U)
/*! rd_dq7_del
 *  0b000..No change in dq7 delay
 *  0b001..Add dq7 delay of 1 delay unit
 *  0b010..Add dq7 delay of 2 delay units.
 *  0b011..Add dq7 delay of 3 delay units.
 *  0b100..Add dq7 delay of 4 delay units.
 *  0b101..Add dq7 delay of 5 delay units.
 *  0b110..Add dq7 delay of 6 delay units.
 *  0b111..Add dq7 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY0DL_rd_dq7_del(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY0DL_rd_dq7_del_SHIFT)) & MMDC_MPRDDQBY0DL_rd_dq7_del_MASK)
/*! @} */

/*! @name MPRDDQBY1DL - MMDC PHY Read DQ Byte1 Delay Register */
/*! @{ */

#define MMDC_MPRDDQBY1DL_rd_dq8_del_MASK         (0x7U)
#define MMDC_MPRDDQBY1DL_rd_dq8_del_SHIFT        (0U)
/*! rd_dq8_del
 *  0b000..No change in dq8 delay
 *  0b001..Add dq8 delay of 1 delay unit
 *  0b010..Add dq8 delay of 2 delay units.
 *  0b011..Add dq8 delay of 3 delay units.
 *  0b100..Add dq8 delay of 4 delay units.
 *  0b101..Add dq8 delay of 5 delay units.
 *  0b110..Add dq8 delay of 6 delay units.
 *  0b111..Add dq8 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY1DL_rd_dq8_del(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY1DL_rd_dq8_del_SHIFT)) & MMDC_MPRDDQBY1DL_rd_dq8_del_MASK)

#define MMDC_MPRDDQBY1DL_rd_dq9_del_MASK         (0x70U)
#define MMDC_MPRDDQBY1DL_rd_dq9_del_SHIFT        (4U)
/*! rd_dq9_del
 *  0b000..No change in dq9 delay
 *  0b001..Add dq9 delay of 1 delay unit
 *  0b010..Add dq9 delay of 2 delay units.
 *  0b011..Add dq9 delay of 3 delay units.
 *  0b100..Add dq9 delay of 4 delay units.
 *  0b101..Add dq9 delay of 5 delay units.
 *  0b110..Add dq9 delay of 6 delay units.
 *  0b111..Add dq9 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY1DL_rd_dq9_del(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY1DL_rd_dq9_del_SHIFT)) & MMDC_MPRDDQBY1DL_rd_dq9_del_MASK)

#define MMDC_MPRDDQBY1DL_rd_dq10_del_MASK        (0x700U)
#define MMDC_MPRDDQBY1DL_rd_dq10_del_SHIFT       (8U)
/*! rd_dq10_del
 *  0b000..No change in dq10 delay
 *  0b001..Add dq10 delay of 1 delay unit
 *  0b010..Add dq10 delay of 2 delay units.
 *  0b011..Add dq10 delay of 3 delay units.
 *  0b100..Add dq10 delay of 4 delay units.
 *  0b101..Add dq10 delay of 5 delay unit
 *  0b110..Add dq10 delay of 6 delay units.
 *  0b111..Add dq10 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY1DL_rd_dq10_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY1DL_rd_dq10_del_SHIFT)) & MMDC_MPRDDQBY1DL_rd_dq10_del_MASK)

#define MMDC_MPRDDQBY1DL_rd_dq11_del_MASK        (0x7000U)
#define MMDC_MPRDDQBY1DL_rd_dq11_del_SHIFT       (12U)
/*! rd_dq11_del
 *  0b000..No change in dq11 delay
 *  0b001..Add dq11 delay of 1 delay unit
 *  0b010..Add dq11 delay of 2 delay units.
 *  0b011..Add dq11 delay of 3 delay units.
 *  0b100..Add dq11 delay of 4 delay units.
 *  0b101..Add dq11 delay of 5 delay units.
 *  0b110..Add dq11 delay of 6 delay units.
 *  0b111..Add dq11 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY1DL_rd_dq11_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY1DL_rd_dq11_del_SHIFT)) & MMDC_MPRDDQBY1DL_rd_dq11_del_MASK)

#define MMDC_MPRDDQBY1DL_rd_dq12_del_MASK        (0x70000U)
#define MMDC_MPRDDQBY1DL_rd_dq12_del_SHIFT       (16U)
/*! rd_dq12_del
 *  0b000..No change in dq12 delay
 *  0b001..Add dq12 delay of 1 delay unit
 *  0b010..Add dq12 delay of 2 delay units.
 *  0b011..Add dq12 delay of 3 delay units.
 *  0b100..Add dq12 delay of 4 delay units.
 *  0b101..Add dq12 delay of 5 delay units.
 *  0b110..Add dq12 delay of 6 delay units.
 *  0b111..Add dq12 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY1DL_rd_dq12_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY1DL_rd_dq12_del_SHIFT)) & MMDC_MPRDDQBY1DL_rd_dq12_del_MASK)

#define MMDC_MPRDDQBY1DL_rd_dq13_del_MASK        (0x700000U)
#define MMDC_MPRDDQBY1DL_rd_dq13_del_SHIFT       (20U)
/*! rd_dq13_del
 *  0b000..No change in dq13 delay
 *  0b001..Add dq13 delay of 1 delay unit
 *  0b010..Add dq13 delay of 2 delay units.
 *  0b011..Add dq13 delay of 3 delay units.
 *  0b100..Add dq13 delay of 4 delay units.
 *  0b101..Add dq13 delay of 5 delay units.
 *  0b110..Add dq13 delay of 6 delay units.
 *  0b111..Add dq13 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY1DL_rd_dq13_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY1DL_rd_dq13_del_SHIFT)) & MMDC_MPRDDQBY1DL_rd_dq13_del_MASK)

#define MMDC_MPRDDQBY1DL_rd_dq14_del_MASK        (0x7000000U)
#define MMDC_MPRDDQBY1DL_rd_dq14_del_SHIFT       (24U)
/*! rd_dq14_del
 *  0b000..No change in dq14 delay
 *  0b001..Add dq14 delay of 1 delay unit
 *  0b010..Add dq14 delay of 2 delay units.
 *  0b011..Add dq14 delay of 3 delay units.
 *  0b100..Add dq14 delay of 4 delay units.
 *  0b101..Add dq14 delay of 5 delay units.
 *  0b110..Add dq14 delay of 6 delay units.
 *  0b111..Add dq14 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY1DL_rd_dq14_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY1DL_rd_dq14_del_SHIFT)) & MMDC_MPRDDQBY1DL_rd_dq14_del_MASK)

#define MMDC_MPRDDQBY1DL_rd_dq15_del_MASK        (0x70000000U)
#define MMDC_MPRDDQBY1DL_rd_dq15_del_SHIFT       (28U)
/*! rd_dq15_del
 *  0b000..No change in dq15 delay
 *  0b001..Add dq15 delay of 1 delay unit
 *  0b010..Add dq15 delay of 2 delay units.
 *  0b011..Add dq15 delay of 3 delay units.
 *  0b100..Add dq15 delay of 4 delay units.
 *  0b101..Add dq15 delay of 5 delay units.
 *  0b110..Add dq15 delay of 6 delay units.
 *  0b111..Add dq15 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY1DL_rd_dq15_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY1DL_rd_dq15_del_SHIFT)) & MMDC_MPRDDQBY1DL_rd_dq15_del_MASK)
/*! @} */

/*! @name MPRDDQBY2DL - MMDC PHY Read DQ Byte2 Delay Register */
/*! @{ */

#define MMDC_MPRDDQBY2DL_rd_dq16_del_MASK        (0x7U)
#define MMDC_MPRDDQBY2DL_rd_dq16_del_SHIFT       (0U)
/*! rd_dq16_del
 *  0b000..No change in dq16 delay
 *  0b001..Add dq16 delay of 1 delay unit
 *  0b010..Add dq16 delay of 2 delay units.
 *  0b011..Add dq16 delay of 3 delay units.
 *  0b100..Add dq16 delay of 4 delay units.
 *  0b101..Add dq16 delay of 5 delay units.
 *  0b110..Add dq16 delay of 6 delay units.
 *  0b111..Add dq16 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY2DL_rd_dq16_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY2DL_rd_dq16_del_SHIFT)) & MMDC_MPRDDQBY2DL_rd_dq16_del_MASK)

#define MMDC_MPRDDQBY2DL_rd_dq17_del_MASK        (0x70U)
#define MMDC_MPRDDQBY2DL_rd_dq17_del_SHIFT       (4U)
/*! rd_dq17_del
 *  0b000..No change in dq17 delay
 *  0b001..Add dq17 delay of 1 delay unit
 *  0b010..Add dq17 delay of 2 delay units.
 *  0b011..Add dq17 delay of 3 delay units.
 *  0b100..Add dq17 delay of 4 delay units.
 *  0b101..Add dq17 delay of 5 delay units.
 *  0b110..Add dq17 delay of 6 delay units.
 *  0b111..Add dq17 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY2DL_rd_dq17_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY2DL_rd_dq17_del_SHIFT)) & MMDC_MPRDDQBY2DL_rd_dq17_del_MASK)

#define MMDC_MPRDDQBY2DL_rd_dq18_del_MASK        (0x700U)
#define MMDC_MPRDDQBY2DL_rd_dq18_del_SHIFT       (8U)
/*! rd_dq18_del
 *  0b000..No change in dq18 delay
 *  0b001..Add dq18 delay of 1 delay unit
 *  0b010..Add dq18 delay of 2 delay units.
 *  0b011..Add dq18 delay of 3 delay units.
 *  0b100..Add dq18 delay of 4 delay units.
 *  0b101..Add dq18 delay of 5 delay units.
 *  0b110..Add dq18 delay of 6 delay units.
 *  0b111..Add dq18 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY2DL_rd_dq18_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY2DL_rd_dq18_del_SHIFT)) & MMDC_MPRDDQBY2DL_rd_dq18_del_MASK)

#define MMDC_MPRDDQBY2DL_rd_dq19_del_MASK        (0x7000U)
#define MMDC_MPRDDQBY2DL_rd_dq19_del_SHIFT       (12U)
/*! rd_dq19_del
 *  0b000..No change in dq19 delay
 *  0b001..Add dq19 delay of 1 delay unit
 *  0b010..Add dq19 delay of 2 delay units.
 *  0b011..Add dq19 delay of 3 delay units.
 *  0b100..Add dq19 delay of 4 delay units.
 *  0b101..Add dq19 delay of 5 delay units.
 *  0b110..Add dq19 delay of 6 delay units.
 *  0b111..Add dq19 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY2DL_rd_dq19_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY2DL_rd_dq19_del_SHIFT)) & MMDC_MPRDDQBY2DL_rd_dq19_del_MASK)

#define MMDC_MPRDDQBY2DL_rd_dq20_del_MASK        (0x70000U)
#define MMDC_MPRDDQBY2DL_rd_dq20_del_SHIFT       (16U)
/*! rd_dq20_del
 *  0b000..No change in dq20 delay
 *  0b001..Add dq20 delay of 1 delay unit
 *  0b010..Add dq20 delay of 2 delay units.
 *  0b011..Add dq20 delay of 3 delay units.
 *  0b100..Add dq20 delay of 4 delay units.
 *  0b101..Add dq20 delay of 5 delay units.
 *  0b110..Add dq20 delay of 6 delay units.
 *  0b111..Add dq20 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY2DL_rd_dq20_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY2DL_rd_dq20_del_SHIFT)) & MMDC_MPRDDQBY2DL_rd_dq20_del_MASK)

#define MMDC_MPRDDQBY2DL_rd_dq21_del_MASK        (0x700000U)
#define MMDC_MPRDDQBY2DL_rd_dq21_del_SHIFT       (20U)
/*! rd_dq21_del
 *  0b000..No change in dq21 delay
 *  0b001..Add dq21 delay of 1 delay unit
 *  0b010..Add dq21 delay of 2 delay units.
 *  0b011..Add dq21 delay of 3 delay units.
 *  0b100..Add dq21 delay of 4 delay units.
 *  0b101..Add dq21 delay of 5 delay units.
 *  0b110..Add dq21 delay of 6 delay units.
 *  0b111..Add dq21 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY2DL_rd_dq21_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY2DL_rd_dq21_del_SHIFT)) & MMDC_MPRDDQBY2DL_rd_dq21_del_MASK)

#define MMDC_MPRDDQBY2DL_rd_dq22_del_MASK        (0x7000000U)
#define MMDC_MPRDDQBY2DL_rd_dq22_del_SHIFT       (24U)
/*! rd_dq22_del
 *  0b000..No change in dq22 delay
 *  0b001..Add dq22 delay of 1 delay unit
 *  0b010..Add dq22 delay of 2 delay units.
 *  0b011..Add dq22 delay of 3 delay units.
 *  0b100..Add dq22 delay of 4 delay units.
 *  0b101..Add dq22 delay of 5 delay units.
 *  0b110..Add dq22 delay of 6 delay units.
 *  0b111..Add dq22 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY2DL_rd_dq22_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY2DL_rd_dq22_del_SHIFT)) & MMDC_MPRDDQBY2DL_rd_dq22_del_MASK)

#define MMDC_MPRDDQBY2DL_rd_dq23_del_MASK        (0x70000000U)
#define MMDC_MPRDDQBY2DL_rd_dq23_del_SHIFT       (28U)
/*! rd_dq23_del
 *  0b000..No change in dq23 delay
 *  0b001..Add dq23 delay of 1 delay unit
 *  0b010..Add dq23 delay of 2 delay units.
 *  0b011..Add dq23 delay of 3 delay units.
 *  0b100..Add dq23 delay of 4 delay units.
 *  0b101..Add dq23 delay of 5 delay units.
 *  0b110..Add dq23 delay of 6 delay units.
 *  0b111..Add dq23 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY2DL_rd_dq23_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY2DL_rd_dq23_del_SHIFT)) & MMDC_MPRDDQBY2DL_rd_dq23_del_MASK)
/*! @} */

/*! @name MPRDDQBY3DL - MMDC PHY Read DQ Byte3 Delay Register */
/*! @{ */

#define MMDC_MPRDDQBY3DL_rd_dq24_del_MASK        (0x7U)
#define MMDC_MPRDDQBY3DL_rd_dq24_del_SHIFT       (0U)
/*! rd_dq24_del
 *  0b000..No change in dq24 delay
 *  0b001..Add dq24 delay of 1 delay unit
 *  0b010..Add dq24 delay of 2 delay units.
 *  0b011..Add dq24 delay of 3 delay units.
 *  0b100..Add dq24 delay of 4 delay units.
 *  0b101..Add dq24 delay of 5 delay units.
 *  0b110..Add dq24 delay of 6 delay units.
 *  0b111..Add dq24 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY3DL_rd_dq24_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY3DL_rd_dq24_del_SHIFT)) & MMDC_MPRDDQBY3DL_rd_dq24_del_MASK)

#define MMDC_MPRDDQBY3DL_rd_dq25_del_MASK        (0x70U)
#define MMDC_MPRDDQBY3DL_rd_dq25_del_SHIFT       (4U)
/*! rd_dq25_del
 *  0b000..No change in dq25 delay
 *  0b001..Add dq25 delay of 1 delay unit
 *  0b010..Add dq25 delay of 2 delay units.
 *  0b011..Add dq25 delay of 3 delay units.
 *  0b100..Add dq25 delay of 4 delay units.
 *  0b101..Add dq25 delay of 5 delay units.
 *  0b110..Add dq25 delay of 6 delay units.
 *  0b111..Add dq25 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY3DL_rd_dq25_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY3DL_rd_dq25_del_SHIFT)) & MMDC_MPRDDQBY3DL_rd_dq25_del_MASK)

#define MMDC_MPRDDQBY3DL_rd_dq26_del_MASK        (0x700U)
#define MMDC_MPRDDQBY3DL_rd_dq26_del_SHIFT       (8U)
/*! rd_dq26_del
 *  0b000..No change in dq26 delay
 *  0b001..Add dq26 delay of 1 delay unit
 *  0b010..Add dq26 delay of 2 delay units.
 *  0b011..Add dq26 delay of 3 delay units.
 *  0b100..Add dq26 delay of 4 delay units.
 *  0b101..Add dq26 delay of 5 delay units.
 *  0b110..Add dq26 delay of 6 delay units.
 *  0b111..Add dq26 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY3DL_rd_dq26_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY3DL_rd_dq26_del_SHIFT)) & MMDC_MPRDDQBY3DL_rd_dq26_del_MASK)

#define MMDC_MPRDDQBY3DL_rd_dq27_del_MASK        (0x7000U)
#define MMDC_MPRDDQBY3DL_rd_dq27_del_SHIFT       (12U)
/*! rd_dq27_del
 *  0b000..No change in dq27 delay
 *  0b001..Add dq27 delay of 1 delay unit
 *  0b010..Add dq27 delay of 2 delay units.
 *  0b011..Add dq27 delay of 3 delay units.
 *  0b100..Add dq27 delay of 4 delay units.
 *  0b101..Add dq27 delay of 5 delay units.
 *  0b110..Add dq27 delay of 6 delay units.
 *  0b111..Add dq27 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY3DL_rd_dq27_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY3DL_rd_dq27_del_SHIFT)) & MMDC_MPRDDQBY3DL_rd_dq27_del_MASK)

#define MMDC_MPRDDQBY3DL_rd_dq28_del_MASK        (0x70000U)
#define MMDC_MPRDDQBY3DL_rd_dq28_del_SHIFT       (16U)
/*! rd_dq28_del
 *  0b000..No change in dq28 delay
 *  0b001..Add dq28 delay of 1 delay unit
 *  0b010..Add dq28 delay of 2 delay units.
 *  0b011..Add dq28 delay of 3 delay units.
 *  0b100..Add dq28 delay of 4 delay units.
 *  0b101..Add dq28 delay of 5 delay units.
 *  0b110..Add dq28 delay of 6 delay units.
 *  0b111..Add dq28 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY3DL_rd_dq28_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY3DL_rd_dq28_del_SHIFT)) & MMDC_MPRDDQBY3DL_rd_dq28_del_MASK)

#define MMDC_MPRDDQBY3DL_rd_dq29_del_MASK        (0x700000U)
#define MMDC_MPRDDQBY3DL_rd_dq29_del_SHIFT       (20U)
/*! rd_dq29_del
 *  0b000..No change in dq29 delay
 *  0b001..Add dq29 delay of 1 delay unit
 *  0b010..Add dq29 delay of 2 delay units.
 *  0b011..Add dq29 delay of 3 delay units.
 *  0b100..Add dq29 delay of 4 delay units.
 *  0b101..Add dq29 delay of 5 delay units.
 *  0b110..Add dq29 delay of 6 delay units.
 *  0b111..Add dq29 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY3DL_rd_dq29_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY3DL_rd_dq29_del_SHIFT)) & MMDC_MPRDDQBY3DL_rd_dq29_del_MASK)

#define MMDC_MPRDDQBY3DL_rd_dq30_del_MASK        (0x7000000U)
#define MMDC_MPRDDQBY3DL_rd_dq30_del_SHIFT       (24U)
/*! rd_dq30_del
 *  0b000..No change in dq30 delay
 *  0b001..Add dq30 delay of 1 delay unit
 *  0b010..Add dq30 delay of 2 delay units.
 *  0b011..Add dq30 delay of 3 delay units.
 *  0b100..Add dq30 delay of 4 delay units.
 *  0b101..Add dq30 delay of 5 delay units.
 *  0b110..Add dq30 delay of 6 delay units.
 *  0b111..Add dq30 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY3DL_rd_dq30_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY3DL_rd_dq30_del_SHIFT)) & MMDC_MPRDDQBY3DL_rd_dq30_del_MASK)

#define MMDC_MPRDDQBY3DL_rd_dq31_del_MASK        (0x70000000U)
#define MMDC_MPRDDQBY3DL_rd_dq31_del_SHIFT       (28U)
/*! rd_dq31_del
 *  0b000..No change in dq31 delay
 *  0b001..Add dq31 delay of 1 delay unit
 *  0b010..Add dq31 delay of 2 delay units.
 *  0b011..Add dq31 delay of 3 delay units.
 *  0b100..Add dq31 delay of 4 delay units.
 *  0b101..Add dq31 delay of 5 delay units.
 *  0b110..Add dq31 delay of 6 delay units.
 *  0b111..Add dq31 delay of 7 delay units.
 */
#define MMDC_MPRDDQBY3DL_rd_dq31_del(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDQBY3DL_rd_dq31_del_SHIFT)) & MMDC_MPRDDQBY3DL_rd_dq31_del_MASK)
/*! @} */

/*! @name MPDGCTRL0 - MMDC PHY Read DQS Gating Control Register 0 */
/*! @{ */

#define MMDC_MPDGCTRL0_RST_RD_FIFO_MASK          (0x80000000U)
#define MMDC_MPDGCTRL0_RST_RD_FIFO_SHIFT         (31U)
#define MMDC_MPDGCTRL0_RST_RD_FIFO(x)            (((uint32_t)(((uint32_t)(x)) << MMDC_MPDGCTRL0_RST_RD_FIFO_SHIFT)) & MMDC_MPDGCTRL0_RST_RD_FIFO_MASK)
/*! @} */

/*! @name MPRDDLCTL - MMDC PHY Read delay-lines Configuration Register */
/*! @{ */

#define MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET0_MASK    (0x7FU)
#define MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET0_SHIFT   (0U)
#define MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET0(x)      (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET0_SHIFT)) & MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET0_MASK)

#define MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET1_MASK    (0x7F00U)
#define MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET1_SHIFT   (8U)
#define MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET1(x)      (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET1_SHIFT)) & MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET1_MASK)

#define MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET2_MASK    (0x7F0000U)
#define MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET2_SHIFT   (16U)
#define MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET2(x)      (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET2_SHIFT)) & MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET2_MASK)

#define MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET3_MASK    (0x7F000000U)
#define MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET3_SHIFT   (24U)
#define MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET3(x)      (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET3_SHIFT)) & MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET3_MASK)
/*! @} */

/*! @name MPRDDLST - MMDC PHY Read delay-lines Status Register */
/*! @{ */

#define MMDC_MPRDDLST_RD_DL_UNIT_NUM0_MASK       (0x7FU)
#define MMDC_MPRDDLST_RD_DL_UNIT_NUM0_SHIFT      (0U)
#define MMDC_MPRDDLST_RD_DL_UNIT_NUM0(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLST_RD_DL_UNIT_NUM0_SHIFT)) & MMDC_MPRDDLST_RD_DL_UNIT_NUM0_MASK)

#define MMDC_MPRDDLST_RD_DL_UNIT_NUM1_MASK       (0x7F00U)
#define MMDC_MPRDDLST_RD_DL_UNIT_NUM1_SHIFT      (8U)
#define MMDC_MPRDDLST_RD_DL_UNIT_NUM1(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLST_RD_DL_UNIT_NUM1_SHIFT)) & MMDC_MPRDDLST_RD_DL_UNIT_NUM1_MASK)

#define MMDC_MPRDDLST_RD_DL_UNIT_NUM2_MASK       (0x7F0000U)
#define MMDC_MPRDDLST_RD_DL_UNIT_NUM2_SHIFT      (16U)
#define MMDC_MPRDDLST_RD_DL_UNIT_NUM2(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLST_RD_DL_UNIT_NUM2_SHIFT)) & MMDC_MPRDDLST_RD_DL_UNIT_NUM2_MASK)

#define MMDC_MPRDDLST_RD_DL_UNIT_NUM3_MASK       (0x7F000000U)
#define MMDC_MPRDDLST_RD_DL_UNIT_NUM3_SHIFT      (24U)
#define MMDC_MPRDDLST_RD_DL_UNIT_NUM3(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLST_RD_DL_UNIT_NUM3_SHIFT)) & MMDC_MPRDDLST_RD_DL_UNIT_NUM3_MASK)
/*! @} */

/*! @name MPWRDLCTL - MMDC PHY Write delay-lines Configuration Register */
/*! @{ */

#define MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET0_MASK    (0x7FU)
#define MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET0_SHIFT   (0U)
#define MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET0(x)      (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET0_SHIFT)) & MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET0_MASK)

#define MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET1_MASK    (0x7F00U)
#define MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET1_SHIFT   (8U)
#define MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET1(x)      (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET1_SHIFT)) & MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET1_MASK)

#define MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET2_MASK    (0x7F0000U)
#define MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET2_SHIFT   (16U)
#define MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET2(x)      (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET2_SHIFT)) & MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET2_MASK)

#define MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET3_MASK    (0x7F000000U)
#define MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET3_SHIFT   (24U)
#define MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET3(x)      (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET3_SHIFT)) & MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET3_MASK)
/*! @} */

/*! @name MPWRDLST - MMDC PHY Write delay-lines Status Register */
/*! @{ */

#define MMDC_MPWRDLST_WR_DL_UNIT_NUM0_MASK       (0x7FU)
#define MMDC_MPWRDLST_WR_DL_UNIT_NUM0_SHIFT      (0U)
#define MMDC_MPWRDLST_WR_DL_UNIT_NUM0(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLST_WR_DL_UNIT_NUM0_SHIFT)) & MMDC_MPWRDLST_WR_DL_UNIT_NUM0_MASK)

#define MMDC_MPWRDLST_WR_DL_UNIT_NUM1_MASK       (0x7F00U)
#define MMDC_MPWRDLST_WR_DL_UNIT_NUM1_SHIFT      (8U)
#define MMDC_MPWRDLST_WR_DL_UNIT_NUM1(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLST_WR_DL_UNIT_NUM1_SHIFT)) & MMDC_MPWRDLST_WR_DL_UNIT_NUM1_MASK)

#define MMDC_MPWRDLST_WR_DL_UNIT_NUM2_MASK       (0x7F0000U)
#define MMDC_MPWRDLST_WR_DL_UNIT_NUM2_SHIFT      (16U)
#define MMDC_MPWRDLST_WR_DL_UNIT_NUM2(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLST_WR_DL_UNIT_NUM2_SHIFT)) & MMDC_MPWRDLST_WR_DL_UNIT_NUM2_MASK)

#define MMDC_MPWRDLST_WR_DL_UNIT_NUM3_MASK       (0x7F000000U)
#define MMDC_MPWRDLST_WR_DL_UNIT_NUM3_SHIFT      (24U)
#define MMDC_MPWRDLST_WR_DL_UNIT_NUM3(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLST_WR_DL_UNIT_NUM3_SHIFT)) & MMDC_MPWRDLST_WR_DL_UNIT_NUM3_MASK)
/*! @} */

/*! @name MPZQLP2CTL - MMDC ZQ LPDDR2 HW Control Register */
/*! @{ */

#define MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQINIT_MASK    (0x1FFU)
#define MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQINIT_SHIFT   (0U)
/*! ZQ_LP2_HW_ZQINIT
 *  0b000000000-0b000110110..Reserved
 *  0b000110111..112 cycles
 *  0b000111000..114 cycles
 *  0b100001001..532 cycles (Default. This may need to be adjusted to achieve the correct timing depending on the DDR clock frequency.)
 *  0b111111110..1022 cycles
 *  0b111111111..1024 cycles
 */
#define MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQINIT(x)      (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQINIT_SHIFT)) & MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQINIT_MASK)

#define MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCL_MASK      (0xFF0000U)
#define MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCL_SHIFT     (16U)
/*! ZQ_LP2_HW_ZQCL
 *  0b00000000-0b00110110..Reserved
 *  0b00110111..112 cycles
 *  0b00111000..114 cycles
 *  0b01011111..192 cycles (Default. This may need to be adjusted to achieve the correct timing depending on the DDR clock frequency.)
 *  0b11111110..510 cycles
 *  0b11111111..512 cycles
 */
#define MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCL(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCL_SHIFT)) & MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCL_MASK)

#define MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCS_MASK      (0x7F000000U)
#define MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCS_SHIFT     (24U)
/*! ZQ_LP2_HW_ZQCS
 *  0b0000000-0b0011010..Reserved
 *  0b0011011..112 cycles (default)
 *  0b0011100..116 cycles
 *  0b1111110..508 cycles
 *  0b1111111..512 cycles
 */
#define MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCS(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCS_SHIFT)) & MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCS_MASK)
/*! @} */

/*! @name MPRDDLHWCTL - MMDC PHY Read Delay HW Calibration Control Register */
/*! @{ */

#define MMDC_MPRDDLHWCTL_HW_RD_DL_ERR0_MASK      (0x1U)
#define MMDC_MPRDDLHWCTL_HW_RD_DL_ERR0_SHIFT     (0U)
/*! HW_RD_DL_ERR0
 *  0b0..No error was found in read delay-line 0 during the automatic (HW) read calibration process of read delay-line 0.
 *  0b1..An error was found in read delay-line 0 during the automatic (HW) read calibration process of read delay-line 0.
 */
#define MMDC_MPRDDLHWCTL_HW_RD_DL_ERR0(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLHWCTL_HW_RD_DL_ERR0_SHIFT)) & MMDC_MPRDDLHWCTL_HW_RD_DL_ERR0_MASK)

#define MMDC_MPRDDLHWCTL_HW_RD_DL_ERR1_MASK      (0x2U)
#define MMDC_MPRDDLHWCTL_HW_RD_DL_ERR1_SHIFT     (1U)
/*! HW_RD_DL_ERR1
 *  0b0..No error was found in read delay-line 1 during the automatic (HW) read calibration process of read delay-line 1.
 *  0b1..An error was found in read delay-line 1 during the automatic (HW) read calibration process of read delay-line 1.
 */
#define MMDC_MPRDDLHWCTL_HW_RD_DL_ERR1(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLHWCTL_HW_RD_DL_ERR1_SHIFT)) & MMDC_MPRDDLHWCTL_HW_RD_DL_ERR1_MASK)

#define MMDC_MPRDDLHWCTL_HW_RD_DL_ERR2_MASK      (0x4U)
#define MMDC_MPRDDLHWCTL_HW_RD_DL_ERR2_SHIFT     (2U)
/*! HW_RD_DL_ERR2
 *  0b0..No error was found in read delay-line 2 during the automatic (HW) read calibration process of read delay-line 2.
 *  0b1..An error was found in read delay-line 2 during the automatic (HW) read calibration process of read delay-line 2.
 */
#define MMDC_MPRDDLHWCTL_HW_RD_DL_ERR2(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLHWCTL_HW_RD_DL_ERR2_SHIFT)) & MMDC_MPRDDLHWCTL_HW_RD_DL_ERR2_MASK)

#define MMDC_MPRDDLHWCTL_HW_RD_DL_ERR3_MASK      (0x8U)
#define MMDC_MPRDDLHWCTL_HW_RD_DL_ERR3_SHIFT     (3U)
/*! HW_RD_DL_ERR3
 *  0b0..No error was found in read delay-line 3 during the automatic (HW) read calibration process of read delay-line 3.
 *  0b1..An error was found in read delay-line 3 during the automatic (HW) read calibration process of read delay-line 3.
 */
#define MMDC_MPRDDLHWCTL_HW_RD_DL_ERR3(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLHWCTL_HW_RD_DL_ERR3_SHIFT)) & MMDC_MPRDDLHWCTL_HW_RD_DL_ERR3_MASK)

#define MMDC_MPRDDLHWCTL_HW_RD_DL_EN_MASK        (0x10U)
#define MMDC_MPRDDLHWCTL_HW_RD_DL_EN_SHIFT       (4U)
#define MMDC_MPRDDLHWCTL_HW_RD_DL_EN(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLHWCTL_HW_RD_DL_EN_SHIFT)) & MMDC_MPRDDLHWCTL_HW_RD_DL_EN_MASK)

#define MMDC_MPRDDLHWCTL_HW_RD_DL_CMP_CYC_MASK   (0x20U)
#define MMDC_MPRDDLHWCTL_HW_RD_DL_CMP_CYC_SHIFT  (5U)
#define MMDC_MPRDDLHWCTL_HW_RD_DL_CMP_CYC(x)     (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLHWCTL_HW_RD_DL_CMP_CYC_SHIFT)) & MMDC_MPRDDLHWCTL_HW_RD_DL_CMP_CYC_MASK)
/*! @} */

/*! @name MPWRDLHWCTL - MMDC PHY Write Delay HW Calibration Control Register */
/*! @{ */

#define MMDC_MPWRDLHWCTL_HW_WR_DL_ERR0_MASK      (0x1U)
#define MMDC_MPWRDLHWCTL_HW_WR_DL_ERR0_SHIFT     (0U)
/*! HW_WR_DL_ERR0
 *  0b0..No error was found during the automatic (HW) write calibration process of write delay-line 0.
 *  0b1..An error was found during the automatic (HW) write calibration process of write delay-line 0.
 */
#define MMDC_MPWRDLHWCTL_HW_WR_DL_ERR0(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLHWCTL_HW_WR_DL_ERR0_SHIFT)) & MMDC_MPWRDLHWCTL_HW_WR_DL_ERR0_MASK)

#define MMDC_MPWRDLHWCTL_HW_WR_DL_ERR1_MASK      (0x2U)
#define MMDC_MPWRDLHWCTL_HW_WR_DL_ERR1_SHIFT     (1U)
/*! HW_WR_DL_ERR1
 *  0b0..No error was found during the automatic (HW) write calibration process of write delay-line 1.
 *  0b1..An error was found during the automatic (HW) write calibration process of write delay-line 1.
 */
#define MMDC_MPWRDLHWCTL_HW_WR_DL_ERR1(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLHWCTL_HW_WR_DL_ERR1_SHIFT)) & MMDC_MPWRDLHWCTL_HW_WR_DL_ERR1_MASK)

#define MMDC_MPWRDLHWCTL_HW_WR_DL_ERR2_MASK      (0x4U)
#define MMDC_MPWRDLHWCTL_HW_WR_DL_ERR2_SHIFT     (2U)
/*! HW_WR_DL_ERR2
 *  0b0..No error was found during the automatic (HW) write calibration process of write delay-line 2.
 *  0b1..An error was found during the automatic (HW) write calibration process of write delay-line 2.
 */
#define MMDC_MPWRDLHWCTL_HW_WR_DL_ERR2(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLHWCTL_HW_WR_DL_ERR2_SHIFT)) & MMDC_MPWRDLHWCTL_HW_WR_DL_ERR2_MASK)

#define MMDC_MPWRDLHWCTL_HW_WR_DL_ERR3_MASK      (0x8U)
#define MMDC_MPWRDLHWCTL_HW_WR_DL_ERR3_SHIFT     (3U)
/*! HW_WR_DL_ERR3
 *  0b0..No error was found during the automatic (HW) write calibration process of write delay-line 3.
 *  0b1..An error was found during the automatic (HW) write calibration process of write delay-line 3.
 */
#define MMDC_MPWRDLHWCTL_HW_WR_DL_ERR3(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLHWCTL_HW_WR_DL_ERR3_SHIFT)) & MMDC_MPWRDLHWCTL_HW_WR_DL_ERR3_MASK)

#define MMDC_MPWRDLHWCTL_HW_WR_DL_EN_MASK        (0x10U)
#define MMDC_MPWRDLHWCTL_HW_WR_DL_EN_SHIFT       (4U)
#define MMDC_MPWRDLHWCTL_HW_WR_DL_EN(x)          (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLHWCTL_HW_WR_DL_EN_SHIFT)) & MMDC_MPWRDLHWCTL_HW_WR_DL_EN_MASK)

#define MMDC_MPWRDLHWCTL_HW_WR_DL_CMP_CYC_MASK   (0x20U)
#define MMDC_MPWRDLHWCTL_HW_WR_DL_CMP_CYC_SHIFT  (5U)
#define MMDC_MPWRDLHWCTL_HW_WR_DL_CMP_CYC(x)     (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLHWCTL_HW_WR_DL_CMP_CYC_SHIFT)) & MMDC_MPWRDLHWCTL_HW_WR_DL_CMP_CYC_MASK)
/*! @} */

/*! @name MPRDDLHWST0 - MMDC PHY Read Delay HW Calibration Status Register 0 */
/*! @{ */

#define MMDC_MPRDDLHWST0_HW_RD_DL_LOW0_MASK      (0x7FU)
#define MMDC_MPRDDLHWST0_HW_RD_DL_LOW0_SHIFT     (0U)
#define MMDC_MPRDDLHWST0_HW_RD_DL_LOW0(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLHWST0_HW_RD_DL_LOW0_SHIFT)) & MMDC_MPRDDLHWST0_HW_RD_DL_LOW0_MASK)

#define MMDC_MPRDDLHWST0_HW_RD_DL_UP0_MASK       (0x7F00U)
#define MMDC_MPRDDLHWST0_HW_RD_DL_UP0_SHIFT      (8U)
#define MMDC_MPRDDLHWST0_HW_RD_DL_UP0(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLHWST0_HW_RD_DL_UP0_SHIFT)) & MMDC_MPRDDLHWST0_HW_RD_DL_UP0_MASK)

#define MMDC_MPRDDLHWST0_HW_RD_DL_LOW1_MASK      (0x7F0000U)
#define MMDC_MPRDDLHWST0_HW_RD_DL_LOW1_SHIFT     (16U)
#define MMDC_MPRDDLHWST0_HW_RD_DL_LOW1(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLHWST0_HW_RD_DL_LOW1_SHIFT)) & MMDC_MPRDDLHWST0_HW_RD_DL_LOW1_MASK)

#define MMDC_MPRDDLHWST0_HW_RD_DL_UP1_MASK       (0x7F000000U)
#define MMDC_MPRDDLHWST0_HW_RD_DL_UP1_SHIFT      (24U)
#define MMDC_MPRDDLHWST0_HW_RD_DL_UP1(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLHWST0_HW_RD_DL_UP1_SHIFT)) & MMDC_MPRDDLHWST0_HW_RD_DL_UP1_MASK)
/*! @} */

/*! @name MPRDDLHWST1 - MMDC PHY Read Delay HW Calibration Status Register 1 */
/*! @{ */

#define MMDC_MPRDDLHWST1_HW_RD_DL_LOW2_MASK      (0x7FU)
#define MMDC_MPRDDLHWST1_HW_RD_DL_LOW2_SHIFT     (0U)
#define MMDC_MPRDDLHWST1_HW_RD_DL_LOW2(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLHWST1_HW_RD_DL_LOW2_SHIFT)) & MMDC_MPRDDLHWST1_HW_RD_DL_LOW2_MASK)

#define MMDC_MPRDDLHWST1_HW_RD_DL_UP2_MASK       (0x7F00U)
#define MMDC_MPRDDLHWST1_HW_RD_DL_UP2_SHIFT      (8U)
#define MMDC_MPRDDLHWST1_HW_RD_DL_UP2(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLHWST1_HW_RD_DL_UP2_SHIFT)) & MMDC_MPRDDLHWST1_HW_RD_DL_UP2_MASK)

#define MMDC_MPRDDLHWST1_HW_RD_DL_LOW3_MASK      (0x7F0000U)
#define MMDC_MPRDDLHWST1_HW_RD_DL_LOW3_SHIFT     (16U)
#define MMDC_MPRDDLHWST1_HW_RD_DL_LOW3(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLHWST1_HW_RD_DL_LOW3_SHIFT)) & MMDC_MPRDDLHWST1_HW_RD_DL_LOW3_MASK)

#define MMDC_MPRDDLHWST1_HW_RD_DL_UP3_MASK       (0x7F000000U)
#define MMDC_MPRDDLHWST1_HW_RD_DL_UP3_SHIFT      (24U)
#define MMDC_MPRDDLHWST1_HW_RD_DL_UP3(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPRDDLHWST1_HW_RD_DL_UP3_SHIFT)) & MMDC_MPRDDLHWST1_HW_RD_DL_UP3_MASK)
/*! @} */

/*! @name MPWRDLHWST0 - MMDC PHY Write Delay HW Calibration Status Register 0 */
/*! @{ */

#define MMDC_MPWRDLHWST0_HW_WR_DL_LOW0_MASK      (0x7FU)
#define MMDC_MPWRDLHWST0_HW_WR_DL_LOW0_SHIFT     (0U)
#define MMDC_MPWRDLHWST0_HW_WR_DL_LOW0(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLHWST0_HW_WR_DL_LOW0_SHIFT)) & MMDC_MPWRDLHWST0_HW_WR_DL_LOW0_MASK)

#define MMDC_MPWRDLHWST0_HW_WR_DL_UP0_MASK       (0x7F00U)
#define MMDC_MPWRDLHWST0_HW_WR_DL_UP0_SHIFT      (8U)
#define MMDC_MPWRDLHWST0_HW_WR_DL_UP0(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLHWST0_HW_WR_DL_UP0_SHIFT)) & MMDC_MPWRDLHWST0_HW_WR_DL_UP0_MASK)

#define MMDC_MPWRDLHWST0_HW_WR_DL_LOW1_MASK      (0x7F0000U)
#define MMDC_MPWRDLHWST0_HW_WR_DL_LOW1_SHIFT     (16U)
#define MMDC_MPWRDLHWST0_HW_WR_DL_LOW1(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLHWST0_HW_WR_DL_LOW1_SHIFT)) & MMDC_MPWRDLHWST0_HW_WR_DL_LOW1_MASK)

#define MMDC_MPWRDLHWST0_HW_WR_DL_UP1_MASK       (0x7F000000U)
#define MMDC_MPWRDLHWST0_HW_WR_DL_UP1_SHIFT      (24U)
#define MMDC_MPWRDLHWST0_HW_WR_DL_UP1(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLHWST0_HW_WR_DL_UP1_SHIFT)) & MMDC_MPWRDLHWST0_HW_WR_DL_UP1_MASK)
/*! @} */

/*! @name MPWRDLHWST1 - MMDC PHY Write Delay HW Calibration Status Register 1 */
/*! @{ */

#define MMDC_MPWRDLHWST1_HW_WR_DL_LOW2_MASK      (0x7FU)
#define MMDC_MPWRDLHWST1_HW_WR_DL_LOW2_SHIFT     (0U)
#define MMDC_MPWRDLHWST1_HW_WR_DL_LOW2(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLHWST1_HW_WR_DL_LOW2_SHIFT)) & MMDC_MPWRDLHWST1_HW_WR_DL_LOW2_MASK)

#define MMDC_MPWRDLHWST1_HW_WR_DL_UP2_MASK       (0x7F00U)
#define MMDC_MPWRDLHWST1_HW_WR_DL_UP2_SHIFT      (8U)
#define MMDC_MPWRDLHWST1_HW_WR_DL_UP2(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLHWST1_HW_WR_DL_UP2_SHIFT)) & MMDC_MPWRDLHWST1_HW_WR_DL_UP2_MASK)

#define MMDC_MPWRDLHWST1_HW_WR_DL_LOW3_MASK      (0x7F0000U)
#define MMDC_MPWRDLHWST1_HW_WR_DL_LOW3_SHIFT     (16U)
#define MMDC_MPWRDLHWST1_HW_WR_DL_LOW3(x)        (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLHWST1_HW_WR_DL_LOW3_SHIFT)) & MMDC_MPWRDLHWST1_HW_WR_DL_LOW3_MASK)

#define MMDC_MPWRDLHWST1_HW_WR_DL_UP3_MASK       (0x7F000000U)
#define MMDC_MPWRDLHWST1_HW_WR_DL_UP3_SHIFT      (24U)
#define MMDC_MPWRDLHWST1_HW_WR_DL_UP3(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPWRDLHWST1_HW_WR_DL_UP3_SHIFT)) & MMDC_MPWRDLHWST1_HW_WR_DL_UP3_MASK)
/*! @} */

/*! @name MPPDCMPR1 - MMDC PHY Pre-defined Compare Register 1 */
/*! @{ */

#define MMDC_MPPDCMPR1_PDV1_MASK                 (0xFFFFU)
#define MMDC_MPPDCMPR1_PDV1_SHIFT                (0U)
#define MMDC_MPPDCMPR1_PDV1(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MPPDCMPR1_PDV1_SHIFT)) & MMDC_MPPDCMPR1_PDV1_MASK)

#define MMDC_MPPDCMPR1_PDV2_MASK                 (0xFFFF0000U)
#define MMDC_MPPDCMPR1_PDV2_SHIFT                (16U)
#define MMDC_MPPDCMPR1_PDV2(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MPPDCMPR1_PDV2_SHIFT)) & MMDC_MPPDCMPR1_PDV2_MASK)
/*! @} */

/*! @name MPPDCMPR2 - MMDC PHY Pre-defined Compare and CA delay-line Configuration Register */
/*! @{ */

#define MMDC_MPPDCMPR2_MPR_CMP_MASK              (0x1U)
#define MMDC_MPPDCMPR2_MPR_CMP_SHIFT             (0U)
#define MMDC_MPPDCMPR2_MPR_CMP(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MPPDCMPR2_MPR_CMP_SHIFT)) & MMDC_MPPDCMPR2_MPR_CMP_MASK)

#define MMDC_MPPDCMPR2_MPR_FULL_CMP_MASK         (0x2U)
#define MMDC_MPPDCMPR2_MPR_FULL_CMP_SHIFT        (1U)
#define MMDC_MPPDCMPR2_MPR_FULL_CMP(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPPDCMPR2_MPR_FULL_CMP_SHIFT)) & MMDC_MPPDCMPR2_MPR_FULL_CMP_MASK)

#define MMDC_MPPDCMPR2_READ_LEVEL_PATTERN_MASK   (0x4U)
#define MMDC_MPPDCMPR2_READ_LEVEL_PATTERN_SHIFT  (2U)
/*! READ_LEVEL_PATTERN
 *  0b0..Compare with read pattern 1010
 *  0b1..Compare with read pattern 0011 (Used only in LPDDR2/LPDDR3 mode)
 */
#define MMDC_MPPDCMPR2_READ_LEVEL_PATTERN(x)     (((uint32_t)(((uint32_t)(x)) << MMDC_MPPDCMPR2_READ_LEVEL_PATTERN_SHIFT)) & MMDC_MPPDCMPR2_READ_LEVEL_PATTERN_MASK)

#define MMDC_MPPDCMPR2_ZQ_OFFSET_EN_MASK         (0x8U)
#define MMDC_MPPDCMPR2_ZQ_OFFSET_EN_SHIFT        (3U)
/*! ZQ_OFFSET_EN - ZQ Offset Enable
 *  0b0..Hardware ZQ offset disabled
 *  0b1..Hardware ZQ offset enabled
 */
#define MMDC_MPPDCMPR2_ZQ_OFFSET_EN(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPPDCMPR2_ZQ_OFFSET_EN_SHIFT)) & MMDC_MPPDCMPR2_ZQ_OFFSET_EN_MASK)

#define MMDC_MPPDCMPR2_ZQ_PD_OFFSET_MASK         (0xF0U)
#define MMDC_MPPDCMPR2_ZQ_PD_OFFSET_SHIFT        (4U)
/*! ZQ_PD_OFFSET
 *  0b0000..-0
 *  0b0001..-1
 *  0b0010..-2
 *  0b0011..-3
 *  0b0100..-4
 *  0b0101..-5
 *  0b0110..-6
 *  0b0111..-7
 *  0b1000..Offset is subtracted from ZQ_HW_PD_RES field
 *  0b1001..Offset is subtracted from ZQ_HW_PD_RES field
 *  0b1010..Offset is subtracted from ZQ_HW_PD_RES field
 *  0b1011..Offset is subtracted from ZQ_HW_PD_RES field
 *  0b1100..Offset is subtracted from ZQ_HW_PD_RES field
 *  0b1101..Offset is subtracted from ZQ_HW_PD_RES field
 *  0b1110..Offset is subtracted from ZQ_HW_PD_RES field
 *  0b1111..Offset is subtracted from ZQ_HW_PD_RES field
 */
#define MMDC_MPPDCMPR2_ZQ_PD_OFFSET(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPPDCMPR2_ZQ_PD_OFFSET_SHIFT)) & MMDC_MPPDCMPR2_ZQ_PD_OFFSET_MASK)

#define MMDC_MPPDCMPR2_ZQ_PU_OFFSET_MASK         (0xF00U)
#define MMDC_MPPDCMPR2_ZQ_PU_OFFSET_SHIFT        (8U)
/*! ZQ_PU_OFFSET
 *  0b0000..-0
 *  0b0001..-1
 *  0b0010..-2
 *  0b0011..-3
 *  0b0100..-4
 *  0b0101..-5
 *  0b0110..-6
 *  0b0111..-7
 *  0b1000..Offset is subtracted from ZQ_HW_PU_RES field
 *  0b1001..Offset is subtracted from ZQ_HW_PU_RES field
 *  0b1010..Offset is subtracted from ZQ_HW_PU_RES field
 *  0b1011..Offset is subtracted from ZQ_HW_PU_RES field
 *  0b1100..Offset is subtracted from ZQ_HW_PU_RES field
 *  0b1101..Offset is subtracted from ZQ_HW_PU_RES field
 *  0b1110..Offset is subtracted from ZQ_HW_PU_RES field
 *  0b1111..Offset is subtracted from ZQ_HW_PU_RES field
 */
#define MMDC_MPPDCMPR2_ZQ_PU_OFFSET(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPPDCMPR2_ZQ_PU_OFFSET_SHIFT)) & MMDC_MPPDCMPR2_ZQ_PU_OFFSET_MASK)

#define MMDC_MPPDCMPR2_CA_DL_ABS_OFFSET_MASK     (0x7F0000U)
#define MMDC_MPPDCMPR2_CA_DL_ABS_OFFSET_SHIFT    (16U)
#define MMDC_MPPDCMPR2_CA_DL_ABS_OFFSET(x)       (((uint32_t)(((uint32_t)(x)) << MMDC_MPPDCMPR2_CA_DL_ABS_OFFSET_SHIFT)) & MMDC_MPPDCMPR2_CA_DL_ABS_OFFSET_MASK)

#define MMDC_MPPDCMPR2_PHY_CA_DL_UNIT_MASK       (0x7F000000U)
#define MMDC_MPPDCMPR2_PHY_CA_DL_UNIT_SHIFT      (24U)
#define MMDC_MPPDCMPR2_PHY_CA_DL_UNIT(x)         (((uint32_t)(((uint32_t)(x)) << MMDC_MPPDCMPR2_PHY_CA_DL_UNIT_SHIFT)) & MMDC_MPPDCMPR2_PHY_CA_DL_UNIT_MASK)
/*! @} */

/*! @name MPSWDAR0 - MMDC PHY SW Dummy Access Register */
/*! @{ */

#define MMDC_MPSWDAR0_SW_DUMMY_WR_MASK           (0x1U)
#define MMDC_MPSWDAR0_SW_DUMMY_WR_SHIFT          (0U)
#define MMDC_MPSWDAR0_SW_DUMMY_WR(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MPSWDAR0_SW_DUMMY_WR_SHIFT)) & MMDC_MPSWDAR0_SW_DUMMY_WR_MASK)

#define MMDC_MPSWDAR0_SW_DUMMY_RD_MASK           (0x2U)
#define MMDC_MPSWDAR0_SW_DUMMY_RD_SHIFT          (1U)
#define MMDC_MPSWDAR0_SW_DUMMY_RD(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MPSWDAR0_SW_DUMMY_RD_SHIFT)) & MMDC_MPSWDAR0_SW_DUMMY_RD_MASK)

#define MMDC_MPSWDAR0_SW_DUM_CMP0_MASK           (0x4U)
#define MMDC_MPSWDAR0_SW_DUM_CMP0_SHIFT          (2U)
/*! SW_DUM_CMP0
 *  0b0..Dummy read fail
 *  0b1..Dummy read pass
 */
#define MMDC_MPSWDAR0_SW_DUM_CMP0(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MPSWDAR0_SW_DUM_CMP0_SHIFT)) & MMDC_MPSWDAR0_SW_DUM_CMP0_MASK)

#define MMDC_MPSWDAR0_SW_DUM_CMP1_MASK           (0x8U)
#define MMDC_MPSWDAR0_SW_DUM_CMP1_SHIFT          (3U)
/*! SW_DUM_CMP1
 *  0b0..Dummy read fail
 *  0b1..Dummy read pass
 */
#define MMDC_MPSWDAR0_SW_DUM_CMP1(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MPSWDAR0_SW_DUM_CMP1_SHIFT)) & MMDC_MPSWDAR0_SW_DUM_CMP1_MASK)

#define MMDC_MPSWDAR0_SW_DUM_CMP2_MASK           (0x10U)
#define MMDC_MPSWDAR0_SW_DUM_CMP2_SHIFT          (4U)
/*! SW_DUM_CMP2
 *  0b0..Dummy read fail
 *  0b1..Dummy read pass
 */
#define MMDC_MPSWDAR0_SW_DUM_CMP2(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MPSWDAR0_SW_DUM_CMP2_SHIFT)) & MMDC_MPSWDAR0_SW_DUM_CMP2_MASK)

#define MMDC_MPSWDAR0_SW_DUM_CMP3_MASK           (0x20U)
#define MMDC_MPSWDAR0_SW_DUM_CMP3_SHIFT          (5U)
/*! SW_DUM_CMP3
 *  0b0..Dummy read fail
 *  0b1..Dummy read pass
 */
#define MMDC_MPSWDAR0_SW_DUM_CMP3(x)             (((uint32_t)(((uint32_t)(x)) << MMDC_MPSWDAR0_SW_DUM_CMP3_SHIFT)) & MMDC_MPSWDAR0_SW_DUM_CMP3_MASK)
/*! @} */

/*! @name MPSWDRDR0 - MMDC PHY SW Dummy Read Data Register 0 */
/*! @{ */

#define MMDC_MPSWDRDR0_DUM_RD0_MASK              (0xFFFFFFFFU)
#define MMDC_MPSWDRDR0_DUM_RD0_SHIFT             (0U)
#define MMDC_MPSWDRDR0_DUM_RD0(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MPSWDRDR0_DUM_RD0_SHIFT)) & MMDC_MPSWDRDR0_DUM_RD0_MASK)
/*! @} */

/*! @name MPSWDRDR1 - MMDC PHY SW Dummy Read Data Register 1 */
/*! @{ */

#define MMDC_MPSWDRDR1_DUM_RD1_MASK              (0xFFFFFFFFU)
#define MMDC_MPSWDRDR1_DUM_RD1_SHIFT             (0U)
#define MMDC_MPSWDRDR1_DUM_RD1(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MPSWDRDR1_DUM_RD1_SHIFT)) & MMDC_MPSWDRDR1_DUM_RD1_MASK)
/*! @} */

/*! @name MPSWDRDR2 - MMDC PHY SW Dummy Read Data Register 2 */
/*! @{ */

#define MMDC_MPSWDRDR2_DUM_RD2_MASK              (0xFFFFFFFFU)
#define MMDC_MPSWDRDR2_DUM_RD2_SHIFT             (0U)
#define MMDC_MPSWDRDR2_DUM_RD2(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MPSWDRDR2_DUM_RD2_SHIFT)) & MMDC_MPSWDRDR2_DUM_RD2_MASK)
/*! @} */

/*! @name MPSWDRDR3 - MMDC PHY SW Dummy Read Data Register 3 */
/*! @{ */

#define MMDC_MPSWDRDR3_DUM_RD3_MASK              (0xFFFFFFFFU)
#define MMDC_MPSWDRDR3_DUM_RD3_SHIFT             (0U)
#define MMDC_MPSWDRDR3_DUM_RD3(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MPSWDRDR3_DUM_RD3_SHIFT)) & MMDC_MPSWDRDR3_DUM_RD3_MASK)
/*! @} */

/*! @name MPSWDRDR4 - MMDC PHY SW Dummy Read Data Register 4 */
/*! @{ */

#define MMDC_MPSWDRDR4_DUM_RD4_MASK              (0xFFFFFFFFU)
#define MMDC_MPSWDRDR4_DUM_RD4_SHIFT             (0U)
#define MMDC_MPSWDRDR4_DUM_RD4(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MPSWDRDR4_DUM_RD4_SHIFT)) & MMDC_MPSWDRDR4_DUM_RD4_MASK)
/*! @} */

/*! @name MPSWDRDR5 - MMDC PHY SW Dummy Read Data Register 5 */
/*! @{ */

#define MMDC_MPSWDRDR5_DUM_RD5_MASK              (0xFFFFFFFFU)
#define MMDC_MPSWDRDR5_DUM_RD5_SHIFT             (0U)
#define MMDC_MPSWDRDR5_DUM_RD5(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MPSWDRDR5_DUM_RD5_SHIFT)) & MMDC_MPSWDRDR5_DUM_RD5_MASK)
/*! @} */

/*! @name MPSWDRDR6 - MMDC PHY SW Dummy Read Data Register 6 */
/*! @{ */

#define MMDC_MPSWDRDR6_DUM_RD6_MASK              (0xFFFFFFFFU)
#define MMDC_MPSWDRDR6_DUM_RD6_SHIFT             (0U)
#define MMDC_MPSWDRDR6_DUM_RD6(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MPSWDRDR6_DUM_RD6_SHIFT)) & MMDC_MPSWDRDR6_DUM_RD6_MASK)
/*! @} */

/*! @name MPSWDRDR7 - MMDC PHY SW Dummy Read Data Register 7 */
/*! @{ */

#define MMDC_MPSWDRDR7_DUM_RD7_MASK              (0xFFFFFFFFU)
#define MMDC_MPSWDRDR7_DUM_RD7_SHIFT             (0U)
#define MMDC_MPSWDRDR7_DUM_RD7(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MPSWDRDR7_DUM_RD7_SHIFT)) & MMDC_MPSWDRDR7_DUM_RD7_MASK)
/*! @} */

/*! @name MPMUR0 - MMDC PHY Measure Unit Register */
/*! @{ */

#define MMDC_MPMUR0_MU_BYP_VAL_MASK              (0x3FFU)
#define MMDC_MPMUR0_MU_BYP_VAL_SHIFT             (0U)
#define MMDC_MPMUR0_MU_BYP_VAL(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MPMUR0_MU_BYP_VAL_SHIFT)) & MMDC_MPMUR0_MU_BYP_VAL_MASK)

#define MMDC_MPMUR0_MU_BYP_EN_MASK               (0x400U)
#define MMDC_MPMUR0_MU_BYP_EN_SHIFT              (10U)
/*! MU_BYP_EN
 *  0b0..The delay-lines use delay units as indicated at MU_UNIT_DEL_NUM.
 *  0b1..The delay-lines use delay units as indicated at MU_BYPASS_VAL.
 */
#define MMDC_MPMUR0_MU_BYP_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MMDC_MPMUR0_MU_BYP_EN_SHIFT)) & MMDC_MPMUR0_MU_BYP_EN_MASK)

#define MMDC_MPMUR0_FRC_MSR_MASK                 (0x800U)
#define MMDC_MPMUR0_FRC_MSR_SHIFT                (11U)
/*! FRC_MSR
 *  0b0..No measurement is performed
 *  0b1..Perform measurement process
 */
#define MMDC_MPMUR0_FRC_MSR(x)                   (((uint32_t)(((uint32_t)(x)) << MMDC_MPMUR0_FRC_MSR_SHIFT)) & MMDC_MPMUR0_FRC_MSR_MASK)

#define MMDC_MPMUR0_MU_UNIT_DEL_NUM_MASK         (0x3FF0000U)
#define MMDC_MPMUR0_MU_UNIT_DEL_NUM_SHIFT        (16U)
#define MMDC_MPMUR0_MU_UNIT_DEL_NUM(x)           (((uint32_t)(((uint32_t)(x)) << MMDC_MPMUR0_MU_UNIT_DEL_NUM_SHIFT)) & MMDC_MPMUR0_MU_UNIT_DEL_NUM_MASK)
/*! @} */

/*! @name MPDCCR - MMDC Duty Cycle Control Register */
/*! @{ */

#define MMDC_MPDCCR_WR_DQS0_FT_DCC_MASK          (0x7U)
#define MMDC_MPDCCR_WR_DQS0_FT_DCC_SHIFT         (0U)
/*! WR_DQS0_FT_DCC
 *  0b001..51.5% low 48.5% high
 *  0b010..50% duty cycle (default)
 *  0b100..48.5% low 51.5% high
 */
#define MMDC_MPDCCR_WR_DQS0_FT_DCC(x)            (((uint32_t)(((uint32_t)(x)) << MMDC_MPDCCR_WR_DQS0_FT_DCC_SHIFT)) & MMDC_MPDCCR_WR_DQS0_FT_DCC_MASK)

#define MMDC_MPDCCR_WR_DQS1_FT_DCC_MASK          (0x38U)
#define MMDC_MPDCCR_WR_DQS1_FT_DCC_SHIFT         (3U)
/*! WR_DQS1_FT_DCC
 *  0b001..51.5% low 48.5% high
 *  0b010..50% duty cycle (default)
 *  0b100..48.5% low 51.5% high
 */
#define MMDC_MPDCCR_WR_DQS1_FT_DCC(x)            (((uint32_t)(((uint32_t)(x)) << MMDC_MPDCCR_WR_DQS1_FT_DCC_SHIFT)) & MMDC_MPDCCR_WR_DQS1_FT_DCC_MASK)

#define MMDC_MPDCCR_WR_DQS2_FT_DCC_MASK          (0x1C0U)
#define MMDC_MPDCCR_WR_DQS2_FT_DCC_SHIFT         (6U)
/*! WR_DQS2_FT_DCC
 *  0b001..51.5% low 48.5% high
 *  0b010..50% duty cycle (default)
 *  0b100..48.5% low 51.5% high
 */
#define MMDC_MPDCCR_WR_DQS2_FT_DCC(x)            (((uint32_t)(((uint32_t)(x)) << MMDC_MPDCCR_WR_DQS2_FT_DCC_SHIFT)) & MMDC_MPDCCR_WR_DQS2_FT_DCC_MASK)

#define MMDC_MPDCCR_WR_DQS3_FT_DCC_MASK          (0xE00U)
#define MMDC_MPDCCR_WR_DQS3_FT_DCC_SHIFT         (9U)
/*! WR_DQS3_FT_DCC
 *  0b001..51.5% low 48.5% high
 *  0b010..50% duty cycle (default)
 *  0b100..48.5% low 51.5% high
 */
#define MMDC_MPDCCR_WR_DQS3_FT_DCC(x)            (((uint32_t)(((uint32_t)(x)) << MMDC_MPDCCR_WR_DQS3_FT_DCC_SHIFT)) & MMDC_MPDCCR_WR_DQS3_FT_DCC_MASK)

#define MMDC_MPDCCR_CK_FT0_DCC_MASK              (0x7000U)
#define MMDC_MPDCCR_CK_FT0_DCC_SHIFT             (12U)
/*! CK_FT0_DCC
 *  0b001..48.5% low 51.5% high
 *  0b010..50% duty cycle (default)
 *  0b100..51.5% low 48.5% high
 */
#define MMDC_MPDCCR_CK_FT0_DCC(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MPDCCR_CK_FT0_DCC_SHIFT)) & MMDC_MPDCCR_CK_FT0_DCC_MASK)

#define MMDC_MPDCCR_CK_FT1_DCC_MASK              (0x70000U)
#define MMDC_MPDCCR_CK_FT1_DCC_SHIFT             (16U)
/*! CK_FT1_DCC
 *  0b001..48.5% low 51.5% high
 *  0b010..50% duty cycle (default)
 *  0b100..51.5% low 48.5% high
 */
#define MMDC_MPDCCR_CK_FT1_DCC(x)                (((uint32_t)(((uint32_t)(x)) << MMDC_MPDCCR_CK_FT1_DCC_SHIFT)) & MMDC_MPDCCR_CK_FT1_DCC_MASK)

#define MMDC_MPDCCR_RD_DQS0_FT_DCC_MASK          (0x380000U)
#define MMDC_MPDCCR_RD_DQS0_FT_DCC_SHIFT         (19U)
/*! RD_DQS0_FT_DCC
 *  0b001..51.5% low 48.5% high
 *  0b010..50% duty cycle (default)
 *  0b100..48.5% low 51.5% high
 */
#define MMDC_MPDCCR_RD_DQS0_FT_DCC(x)            (((uint32_t)(((uint32_t)(x)) << MMDC_MPDCCR_RD_DQS0_FT_DCC_SHIFT)) & MMDC_MPDCCR_RD_DQS0_FT_DCC_MASK)

#define MMDC_MPDCCR_RD_DQS1_FT_DCC_MASK          (0x1C00000U)
#define MMDC_MPDCCR_RD_DQS1_FT_DCC_SHIFT         (22U)
/*! RD_DQS1_FT_DCC
 *  0b001..51.5% low 48.5% high
 *  0b010..50% duty cycle (default)
 *  0b100..48.5% low 51.5% high
 */
#define MMDC_MPDCCR_RD_DQS1_FT_DCC(x)            (((uint32_t)(((uint32_t)(x)) << MMDC_MPDCCR_RD_DQS1_FT_DCC_SHIFT)) & MMDC_MPDCCR_RD_DQS1_FT_DCC_MASK)

#define MMDC_MPDCCR_RD_DQS2_FT_DCC_MASK          (0xE000000U)
#define MMDC_MPDCCR_RD_DQS2_FT_DCC_SHIFT         (25U)
/*! RD_DQS2_FT_DCC
 *  0b001..51.5% low 48.5% high
 *  0b010..50% duty cycle (default)
 *  0b100..48.5% low 51.5% high
 */
#define MMDC_MPDCCR_RD_DQS2_FT_DCC(x)            (((uint32_t)(((uint32_t)(x)) << MMDC_MPDCCR_RD_DQS2_FT_DCC_SHIFT)) & MMDC_MPDCCR_RD_DQS2_FT_DCC_MASK)

#define MMDC_MPDCCR_RD_DQS3_FT_DCC_MASK          (0x70000000U)
#define MMDC_MPDCCR_RD_DQS3_FT_DCC_SHIFT         (28U)
/*! RD_DQS3_FT_DCC
 *  0b001..51.5% low 48.5% high
 *  0b010..50% duty cycle (default)
 *  0b100..48.5% low 51.5% high
 */
#define MMDC_MPDCCR_RD_DQS3_FT_DCC(x)            (((uint32_t)(((uint32_t)(x)) << MMDC_MPDCCR_RD_DQS3_FT_DCC_SHIFT)) & MMDC_MPDCCR_RD_DQS3_FT_DCC_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MMDC_Register_Masks */


/*!
 * @}
 */ /* end of group MMDC_Peripheral_Access_Layer */


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


#endif  /* PERI_MMDC_H_ */

