/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CAU3
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
 * @file PERI_CAU3.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CAU3
 *
 * CMSIS Peripheral Access Layer for CAU3
 */

#if !defined(PERI_CAU3_H_)
#define PERI_CAU3_H_                             /**< Symbol preventing repeated inclusion */

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
   -- CAU3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAU3_Peripheral_Access_Layer CAU3 Peripheral Access Layer
 * @{
 */

/** CAU3 - Size of Registers Arrays */
#define CAU3_CC_R_COUNT                           30u
#define CAU3_PKA0_COUNT                           32u
#define CAU3_PKA1_COUNT                           32u
#define CAU3_PKA2_COUNT                           32u
#define CAU3_PKA3_COUNT                           32u
#define CAU3_PKB0_COUNT                           32u
#define CAU3_PKB1_COUNT                           32u
#define CAU3_PKB2_COUNT                           32u
#define CAU3_PKB3_COUNT                           32u
#define CAU3_PKN0_COUNT                           32u
#define CAU3_PKN1_COUNT                           32u
#define CAU3_PKN2_COUNT                           32u
#define CAU3_PKN3_COUNT                           32u
#define CAU3_PKEX_I_COUNT                         128u

/** CAU3 - Register Layout Typedef */
typedef struct {
  __I  uint32_t PCT;                               /**< Processor Core Type, offset: 0x0 */
  __I  uint32_t MCFG;                              /**< Memory Configuration, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t CR;                                /**< Control Register, offset: 0x10 */
  __IO uint32_t SR;                                /**< Status Register, offset: 0x14 */
       uint8_t RESERVED_1[8];
  __IO uint32_t DBGCSR;                            /**< Debug Control/Status Register, offset: 0x20 */
  __IO uint32_t DBGPBR;                            /**< Debug PC Breakpoint Register, offset: 0x24 */
       uint8_t RESERVED_2[8];
  __IO uint32_t DBGMCMD;                           /**< Debug Memory Command Register, offset: 0x30 */
  __IO uint32_t DBGMADR;                           /**< Debug Memory Address Register, offset: 0x34 */
  __IO uint32_t DBGMDR;                            /**< Debug Memory Data Register, offset: 0x38 */
       uint8_t RESERVED_3[180];
  __IO uint32_t SEMA4;                             /**< Semaphore Register, offset: 0xF0 */
  __I  uint32_t SMOWNR;                            /**< Semaphore Ownership Register, offset: 0xF4 */
       uint8_t RESERVED_4[4];
  __IO uint32_t ARR;                               /**< Address Remap Register, offset: 0xFC */
       uint8_t RESERVED_5[128];
  __IO uint32_t CC_R[CAU3_CC_R_COUNT];             /**< CryptoCore General Purpose Registers, array offset: 0x180, array step: 0x4 */
  __IO uint32_t CC_R30;                            /**< General Purpose R30, offset: 0x1F8 */
  __IO uint32_t CC_R31;                            /**< General Purpose R31, offset: 0x1FC */
  __IO uint32_t CC_PC;                             /**< Program Counter, offset: 0x200 */
  __O  uint32_t CC_CMD;                            /**< Start Command Register, offset: 0x204 */
  __I  uint32_t CC_CF;                             /**< Condition Flag, offset: 0x208 */
       uint8_t RESERVED_6[500];
  __IO uint32_t MDPK;                              /**< Mode Register (PublicKey), offset: 0x400 */
       uint8_t RESERVED_7[44];
  __O  uint32_t COM;                               /**< Command Register, offset: 0x430 */
  __IO uint32_t CTL;                               /**< Control Register, offset: 0x434 */
       uint8_t RESERVED_8[8];
  __O  uint32_t CW;                                /**< Clear Written Register, offset: 0x440 */
       uint8_t RESERVED_9[4];
  __IO uint32_t STA;                               /**< Status Register, offset: 0x448 */
  __I  uint32_t ESTA;                              /**< Error Status Register, offset: 0x44C */
       uint8_t RESERVED_10[48];
  __IO uint32_t PKASZ;                             /**< PKHA A Size Register, offset: 0x480 */
       uint8_t RESERVED_11[4];
  __IO uint32_t PKBSZ;                             /**< PKHA B Size Register, offset: 0x488 */
       uint8_t RESERVED_12[4];
  __IO uint32_t PKNSZ;                             /**< PKHA N Size Register, offset: 0x490 */
       uint8_t RESERVED_13[4];
  __IO uint32_t PKESZ;                             /**< PKHA E Size Register, offset: 0x498 */
       uint8_t RESERVED_14[84];
  __I  uint32_t PKHA_VID1;                         /**< PKHA Revision ID 1, offset: 0x4F0 */
  __I  uint32_t PKHA_VID2;                         /**< PKHA Revision ID 2, offset: 0x4F4 */
  __I  uint32_t CHA_VID;                           /**< CHA Revision ID, offset: 0x4F8 */
       uint8_t RESERVED_15[260];
  __IO uint32_t PKHA_CCR;                          /**< PKHA Clock Control Register, offset: 0x600 */
  __I  uint32_t GSR;                               /**< Global Status Register, offset: 0x604 */
  __IO uint32_t CKLFSR;                            /**< Clock Linear Feedback Shift Register, offset: 0x608 */
       uint8_t RESERVED_16[500];
  __IO uint32_t PKA0[CAU3_PKA0_COUNT];             /**< PKHA A0 Register, array offset: 0x800, array step: 0x4 */
  __IO uint32_t PKA1[CAU3_PKA1_COUNT];             /**< PKHA A1 Register, array offset: 0x880, array step: 0x4 */
  __IO uint32_t PKA2[CAU3_PKA2_COUNT];             /**< PKHA A2 Register, array offset: 0x900, array step: 0x4 */
  __IO uint32_t PKA3[CAU3_PKA3_COUNT];             /**< PKHA A3 Register, array offset: 0x980, array step: 0x4 */
  __IO uint32_t PKB0[CAU3_PKB0_COUNT];             /**< PKHA B0 Register, array offset: 0xA00, array step: 0x4 */
  __IO uint32_t PKB1[CAU3_PKB1_COUNT];             /**< PKHA B1 Register, array offset: 0xA80, array step: 0x4 */
  __IO uint32_t PKB2[CAU3_PKB2_COUNT];             /**< PKHA B2 Register, array offset: 0xB00, array step: 0x4 */
  __IO uint32_t PKB3[CAU3_PKB3_COUNT];             /**< PKHA B3 Register, array offset: 0xB80, array step: 0x4 */
  __IO uint32_t PKN0[CAU3_PKN0_COUNT];             /**< PKHA N0 Register, array offset: 0xC00, array step: 0x4 */
  __IO uint32_t PKN1[CAU3_PKN1_COUNT];             /**< PKHA N1 Register, array offset: 0xC80, array step: 0x4 */
  __IO uint32_t PKN2[CAU3_PKN2_COUNT];             /**< PKHA N2 Register, array offset: 0xD00, array step: 0x4 */
  __IO uint32_t PKN3[CAU3_PKN3_COUNT];             /**< PKHA N3 Register, array offset: 0xD80, array step: 0x4 */
  __O  uint32_t PKE[CAU3_PKEX_I_COUNT];            /**< PKHA E Register, array offset: 0xE00, array step: 0x4 */
} CAU3_Type;

/* ----------------------------------------------------------------------------
   -- CAU3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAU3_Register_Masks CAU3 Register Masks
 * @{
 */

/*! @name PCT - Processor Core Type */
/*! @{ */

#define CAU3_PCT_Y_MASK                          (0xFU)
#define CAU3_PCT_Y_SHIFT                         (0U)
/*! Y - Minor version number
 *  0b0000..Minor version number
 */
#define CAU3_PCT_Y(x)                            (((uint32_t)(((uint32_t)(x)) << CAU3_PCT_Y_SHIFT)) & CAU3_PCT_Y_MASK)

#define CAU3_PCT_X_MASK                          (0xF0U)
#define CAU3_PCT_X_SHIFT                         (4U)
/*! X - Major version number
 *  0b0000..Major version number
 */
#define CAU3_PCT_X(x)                            (((uint32_t)(((uint32_t)(x)) << CAU3_PCT_X_SHIFT)) & CAU3_PCT_X_MASK)

#define CAU3_PCT_ID_MASK                         (0xFFFFFF00U)
#define CAU3_PCT_ID_SHIFT                        (8U)
/*! ID - Module ID number
 *  0b010010110100000101100000..ID number for basic configuration
 *  0b010010110100000101100001..ID number for PKHA configuration
 */
#define CAU3_PCT_ID(x)                           (((uint32_t)(((uint32_t)(x)) << CAU3_PCT_ID_SHIFT)) & CAU3_PCT_ID_MASK)
/*! @} */

/*! @name MCFG - Memory Configuration */
/*! @{ */

#define CAU3_MCFG_DRAM_SZ_MASK                   (0xF00U)
#define CAU3_MCFG_DRAM_SZ_SHIFT                  (8U)
/*! DRAM_SZ - Data RAM Size
 *  0b0000..No memory module
 *  0b0100..2K bytes
 *  0b0101..3K bytes
 *  0b0110..4K bytes
 *  0b0111..6K bytes
 *  0b1000..8K bytes
 *  0b1001..12K bytes
 *  0b1010..16K bytes
 *  0b1011..24K bytes
 *  0b1100..32K bytes
 *  0b1101..48K bytes
 *  0b1110..64K bytes
 *  0b1111..96K bytes
 */
#define CAU3_MCFG_DRAM_SZ(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_MCFG_DRAM_SZ_SHIFT)) & CAU3_MCFG_DRAM_SZ_MASK)

#define CAU3_MCFG_IROM_SZ_MASK                   (0xF0000U)
#define CAU3_MCFG_IROM_SZ_SHIFT                  (16U)
/*! IROM_SZ - Instruction ROM Size
 *  0b0000..No memory module
 *  0b0100..2K bytes
 *  0b0101..3K bytes
 *  0b0110..4K bytes
 *  0b0111..6K bytes
 *  0b1000..8K bytes
 *  0b1001..12K bytes
 *  0b1010..16K bytes
 *  0b1011..24K bytes
 *  0b1100..32K bytes
 *  0b1101..48K bytes
 *  0b1110..64K bytes
 *  0b1111..96K bytes
 */
#define CAU3_MCFG_IROM_SZ(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_MCFG_IROM_SZ_SHIFT)) & CAU3_MCFG_IROM_SZ_MASK)

#define CAU3_MCFG_IRAM_SZ_MASK                   (0xF000000U)
#define CAU3_MCFG_IRAM_SZ_SHIFT                  (24U)
/*! IRAM_SZ - Instruction RAM Size
 *  0b0000..No memory module
 *  0b0100..2K bytes
 *  0b0101..3K bytes
 *  0b0110..4K bytes
 *  0b0111..6K bytes
 *  0b1000..8K bytes
 *  0b1001..12K bytes
 *  0b1010..16K bytes
 *  0b1011..24K bytes
 *  0b1100..32K bytes
 *  0b1101..48K bytes
 *  0b1110..64K bytes
 *  0b1111..96K bytes
 */
#define CAU3_MCFG_IRAM_SZ(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_MCFG_IRAM_SZ_SHIFT)) & CAU3_MCFG_IRAM_SZ_MASK)
/*! @} */

/*! @name CR - Control Register */
/*! @{ */

#define CAU3_CR_TCSEIE_MASK                      (0x1U)
#define CAU3_CR_TCSEIE_SHIFT                     (0U)
/*! TCSEIE - Task completion with software error interrupt enable
 *  0b0..Disables task completion with software error to generate an interrupt request
 *  0b1..Enables task completion with software error to generate an interrupt request
 */
#define CAU3_CR_TCSEIE(x)                        (((uint32_t)(((uint32_t)(x)) << CAU3_CR_TCSEIE_SHIFT)) & CAU3_CR_TCSEIE_MASK)

#define CAU3_CR_ILLIE_MASK                       (0x2U)
#define CAU3_CR_ILLIE_SHIFT                      (1U)
/*! ILLIE - Illegal Instruction Interrupt Enable
 *  0b0..Illegal instruction interrupt requests are disabled
 *  0b1..illegal Instruction interrupt requests are enabled
 */
#define CAU3_CR_ILLIE(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_CR_ILLIE_SHIFT)) & CAU3_CR_ILLIE_MASK)

#define CAU3_CR_ASREIE_MASK                      (0x8U)
#define CAU3_CR_ASREIE_SHIFT                     (3U)
/*! ASREIE - AHB Slave Response Error Interrupt Enable
 *  0b0..AHB slave response error interruption is not enabled
 *  0b1..AHB slave response error interruption is enabled
 */
#define CAU3_CR_ASREIE(x)                        (((uint32_t)(((uint32_t)(x)) << CAU3_CR_ASREIE_SHIFT)) & CAU3_CR_ASREIE_MASK)

#define CAU3_CR_IIADIE_MASK                      (0x10U)
#define CAU3_CR_IIADIE_SHIFT                     (4U)
/*! IIADIE - IMEM Illegal Address Interrupt Enable
 *  0b0..IMEM illegal address interruption is not enabled
 *  0b1..IMEM illegal address interruption is enabled
 */
#define CAU3_CR_IIADIE(x)                        (((uint32_t)(((uint32_t)(x)) << CAU3_CR_IIADIE_SHIFT)) & CAU3_CR_IIADIE_MASK)

#define CAU3_CR_DIADIE_MASK                      (0x20U)
#define CAU3_CR_DIADIE_SHIFT                     (5U)
/*! DIADIE - DMEM Illegal Address Interrupt Enable
 *  0b0..DMEM illegal address interruption is not enabled
 *  0b1..DMEM illegal address interruption is enabled
 */
#define CAU3_CR_DIADIE(x)                        (((uint32_t)(((uint32_t)(x)) << CAU3_CR_DIADIE_SHIFT)) & CAU3_CR_DIADIE_MASK)

#define CAU3_CR_SVIE_MASK                        (0x40U)
#define CAU3_CR_SVIE_SHIFT                       (6U)
/*! SVIE - Security Violation Interrupt Enable
 *  0b0..Security violation interruption is not enabled
 *  0b1..Security violation interruption is enabled
 */
#define CAU3_CR_SVIE(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_CR_SVIE_SHIFT)) & CAU3_CR_SVIE_MASK)

#define CAU3_CR_TCIE_MASK                        (0x80U)
#define CAU3_CR_TCIE_SHIFT                       (7U)
/*! TCIE - Task completion with no error interrupt enable
 *  0b0..Disables task completion with no error to generate an interrupt request
 *  0b1..Enables task completion with no error to generate an interrupt request
 */
#define CAU3_CR_TCIE(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_CR_TCIE_SHIFT)) & CAU3_CR_TCIE_MASK)

#define CAU3_CR_RSTSM4_MASK                      (0x3000U)
#define CAU3_CR_RSTSM4_SHIFT                     (12U)
/*! RSTSM4 - Reset Semaphore
 *  0b00..Idle state
 *  0b01..Wait for second write
 *  0b10..Clears semaphore if previous state was "01"
 *  0b11..Reserved
 */
#define CAU3_CR_RSTSM4(x)                        (((uint32_t)(((uint32_t)(x)) << CAU3_CR_RSTSM4_SHIFT)) & CAU3_CR_RSTSM4_MASK)

#define CAU3_CR_MRST_MASK                        (0x8000U)
#define CAU3_CR_MRST_SHIFT                       (15U)
/*! MRST - Module Reset
 *  0b0..no action
 *  0b1..reset
 */
#define CAU3_CR_MRST(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_CR_MRST_SHIFT)) & CAU3_CR_MRST_MASK)

#define CAU3_CR_FSV_MASK                         (0x10000U)
#define CAU3_CR_FSV_SHIFT                        (16U)
/*! FSV - Force Security Violation Test
 *  0b0..no violation is forced
 *  0b1..force security violation
 */
#define CAU3_CR_FSV(x)                           (((uint32_t)(((uint32_t)(x)) << CAU3_CR_FSV_SHIFT)) & CAU3_CR_FSV_MASK)

#define CAU3_CR_DTCCFG_MASK                      (0x7000000U)
#define CAU3_CR_DTCCFG_SHIFT                     (24U)
/*! DTCCFG - Default Task Completion Configuration
 *  0b000..no explicit action
 *  0b001..Issue an Interrupt Request
 *  0b010..Assert Event Completion Signal
 *  0b100..Issue a DMA request
 */
#define CAU3_CR_DTCCFG(x)                        (((uint32_t)(((uint32_t)(x)) << CAU3_CR_DTCCFG_SHIFT)) & CAU3_CR_DTCCFG_MASK)

#define CAU3_CR_DSHFI_MASK                       (0x10000000U)
#define CAU3_CR_DSHFI_SHIFT                      (28U)
/*! DSHFI - Disable Secure Hash Function Instructions
 *  0b0..Secure Hash Functions are enabled
 *  0b1..Secure Hash Functions are disabled
 */
#define CAU3_CR_DSHFI(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_CR_DSHFI_SHIFT)) & CAU3_CR_DSHFI_MASK)

#define CAU3_CR_DDESI_MASK                       (0x20000000U)
#define CAU3_CR_DDESI_SHIFT                      (29U)
/*! DDESI - Disable DES Instructions
 *  0b0..DES instructions are enabled
 *  0b1..DES instructions are disabled
 */
#define CAU3_CR_DDESI(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_CR_DDESI_SHIFT)) & CAU3_CR_DDESI_MASK)

#define CAU3_CR_DAESI_MASK                       (0x40000000U)
#define CAU3_CR_DAESI_SHIFT                      (30U)
/*! DAESI - Disable AES Instructions
 *  0b0..AES instructions are enabled
 *  0b1..AES instructions are disabled
 */
#define CAU3_CR_DAESI(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_CR_DAESI_SHIFT)) & CAU3_CR_DAESI_MASK)

#define CAU3_CR_MDIS_MASK                        (0x80000000U)
#define CAU3_CR_MDIS_SHIFT                       (31U)
/*! MDIS - Module Disable
 *  0b0..CAU3 exits from low power mode
 *  0b1..CAU3 enters low power mode
 */
#define CAU3_CR_MDIS(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_CR_MDIS_SHIFT)) & CAU3_CR_MDIS_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define CAU3_SR_TCSEIRQ_MASK                     (0x1U)
#define CAU3_SR_TCSEIRQ_SHIFT                    (0U)
/*! TCSEIRQ - Task completion with software error interrupt request
 *  0b0..Task not finished or finished with no software error
 *  0b1..Task execution finished with software error
 */
#define CAU3_SR_TCSEIRQ(x)                       (((uint32_t)(((uint32_t)(x)) << CAU3_SR_TCSEIRQ_SHIFT)) & CAU3_SR_TCSEIRQ_MASK)

#define CAU3_SR_ILLIRQ_MASK                      (0x2U)
#define CAU3_SR_ILLIRQ_SHIFT                     (1U)
/*! ILLIRQ - Illegal instruction interrupt request
 *  0b0..no error
 *  0b1..illegal instruction detected
 */
#define CAU3_SR_ILLIRQ(x)                        (((uint32_t)(((uint32_t)(x)) << CAU3_SR_ILLIRQ_SHIFT)) & CAU3_SR_ILLIRQ_MASK)

#define CAU3_SR_ASREIRQ_MASK                     (0x8U)
#define CAU3_SR_ASREIRQ_SHIFT                    (3U)
/*! ASREIRQ - AHB slave response error interrupt Request
 *  0b0..no error
 *  0b1..AHB slave response error detected
 */
#define CAU3_SR_ASREIRQ(x)                       (((uint32_t)(((uint32_t)(x)) << CAU3_SR_ASREIRQ_SHIFT)) & CAU3_SR_ASREIRQ_MASK)

#define CAU3_SR_IIADIRQ_MASK                     (0x10U)
#define CAU3_SR_IIADIRQ_SHIFT                    (4U)
/*! IIADIRQ - IMEM Illegal address interrupt request
 *  0b0..no error
 *  0b1..illegal IMEM address detected
 */
#define CAU3_SR_IIADIRQ(x)                       (((uint32_t)(((uint32_t)(x)) << CAU3_SR_IIADIRQ_SHIFT)) & CAU3_SR_IIADIRQ_MASK)

#define CAU3_SR_DIADIRQ_MASK                     (0x20U)
#define CAU3_SR_DIADIRQ_SHIFT                    (5U)
/*! DIADIRQ - DMEM illegal access interrupt request
 *  0b0..no illegal address
 *  0b1..illegal address
 */
#define CAU3_SR_DIADIRQ(x)                       (((uint32_t)(((uint32_t)(x)) << CAU3_SR_DIADIRQ_SHIFT)) & CAU3_SR_DIADIRQ_MASK)

#define CAU3_SR_SVIRQ_MASK                       (0x40U)
#define CAU3_SR_SVIRQ_SHIFT                      (6U)
/*! SVIRQ - Security violation interrupt request
 *  0b0..No security violation
 *  0b1..Security violation
 */
#define CAU3_SR_SVIRQ(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_SR_SVIRQ_SHIFT)) & CAU3_SR_SVIRQ_MASK)

#define CAU3_SR_TCIRQ_MASK                       (0x80U)
#define CAU3_SR_TCIRQ_SHIFT                      (7U)
/*! TCIRQ - Task completion with no error interrupt request
 *  0b0..Task not finished or finished with error
 *  0b1..Task execution finished with no error
 */
#define CAU3_SR_TCIRQ(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_SR_TCIRQ_SHIFT)) & CAU3_SR_TCIRQ_MASK)

#define CAU3_SR_TKCS_MASK                        (0xF00U)
#define CAU3_SR_TKCS_SHIFT                       (8U)
/*! TKCS - Task completion status
 *  0b0000..Initialization RUN
 *  0b0001..Running
 *  0b0010..Debug Halted
 *  0b1001..Stop - Error Free
 *  0b1010..Stop - Error
 *  0b1110..Stop - Security Violation, assert security violation output signal and set SVIRQ
 *  0b1111..Stop - Security Violation and set SVIRQ
 */
#define CAU3_SR_TKCS(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_SR_TKCS_SHIFT)) & CAU3_SR_TKCS_MASK)

#define CAU3_SR_SVF_MASK                         (0x10000U)
#define CAU3_SR_SVF_SHIFT                        (16U)
/*! SVF - Security violation flag
 *  0b0..SoC security violation is not asserted
 *  0b1..SoC security violation was asserted
 */
#define CAU3_SR_SVF(x)                           (((uint32_t)(((uint32_t)(x)) << CAU3_SR_SVF_SHIFT)) & CAU3_SR_SVF_MASK)

#define CAU3_SR_DBG_MASK                         (0x20000U)
#define CAU3_SR_DBG_SHIFT                        (17U)
/*! DBG - Debug mode
 *  0b0..CAU3 is not in debug mode
 *  0b1..CAU3 is in debug mode
 */
#define CAU3_SR_DBG(x)                           (((uint32_t)(((uint32_t)(x)) << CAU3_SR_DBG_SHIFT)) & CAU3_SR_DBG_MASK)

#define CAU3_SR_TCCFG_MASK                       (0x7000000U)
#define CAU3_SR_TCCFG_SHIFT                      (24U)
/*! TCCFG - Task completion configuration
 *  0b000..No action
 *  0b001..Assert an interrupt request
 *  0b010..Assert the Event Completion Signal
 *  0b100..Issue a DMA request
 */
#define CAU3_SR_TCCFG(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_SR_TCCFG_SHIFT)) & CAU3_SR_TCCFG_MASK)

#define CAU3_SR_MDISF_MASK                       (0x80000000U)
#define CAU3_SR_MDISF_SHIFT                      (31U)
/*! MDISF - Module disable flag
 *  0b0..CCore is not in low power mode
 *  0b1..CCore is in low power mode
 */
#define CAU3_SR_MDISF(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_SR_MDISF_SHIFT)) & CAU3_SR_MDISF_MASK)
/*! @} */

/*! @name DBGCSR - Debug Control/Status Register */
/*! @{ */

#define CAU3_DBGCSR_DDBG_MASK                    (0x1U)
#define CAU3_DBGCSR_DDBG_SHIFT                   (0U)
/*! DDBG - Debug Disable
 *  0b0..debug is enabled
 *  0b1..debug is disabled
 */
#define CAU3_DBGCSR_DDBG(x)                      (((uint32_t)(((uint32_t)(x)) << CAU3_DBGCSR_DDBG_SHIFT)) & CAU3_DBGCSR_DDBG_MASK)

#define CAU3_DBGCSR_DDBGMC_MASK                  (0x2U)
#define CAU3_DBGCSR_DDBGMC_SHIFT                 (1U)
/*! DDBGMC - Disable Debug Memory Commands
 *  0b0..IPS access to IMEM and DMEM are enabled
 *  0b1..IPS access to IMEM and DMEM are disabled
 */
#define CAU3_DBGCSR_DDBGMC(x)                    (((uint32_t)(((uint32_t)(x)) << CAU3_DBGCSR_DDBGMC_SHIFT)) & CAU3_DBGCSR_DDBGMC_MASK)

#define CAU3_DBGCSR_PBREN_MASK                   (0x10U)
#define CAU3_DBGCSR_PBREN_SHIFT                  (4U)
/*! PBREN - PC Breakpoint Register Enable
 *  0b0..PC breakpoint register (DBGPBR) is disabled
 *  0b1..PC breakpoint register (DBGPBR) is enabled
 */
#define CAU3_DBGCSR_PBREN(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_DBGCSR_PBREN_SHIFT)) & CAU3_DBGCSR_PBREN_MASK)

#define CAU3_DBGCSR_SIM_MASK                     (0x20U)
#define CAU3_DBGCSR_SIM_SHIFT                    (5U)
/*! SIM - Single Instruction Mode
 *  0b0..Single instruction mode is disabled
 *  0b1..Single instruction mode is enabled
 */
#define CAU3_DBGCSR_SIM(x)                       (((uint32_t)(((uint32_t)(x)) << CAU3_DBGCSR_SIM_SHIFT)) & CAU3_DBGCSR_SIM_MASK)

#define CAU3_DBGCSR_FRCH_MASK                    (0x100U)
#define CAU3_DBGCSR_FRCH_SHIFT                   (8U)
/*! FRCH - Force Debug Halt
 *  0b0..Halt state not forced
 *  0b1..Force halt state
 */
#define CAU3_DBGCSR_FRCH(x)                      (((uint32_t)(((uint32_t)(x)) << CAU3_DBGCSR_FRCH_SHIFT)) & CAU3_DBGCSR_FRCH_MASK)

#define CAU3_DBGCSR_DBGGO_MASK                   (0x1000U)
#define CAU3_DBGCSR_DBGGO_SHIFT                  (12U)
/*! DBGGO - Debug Go
 *  0b0..No action
 *  0b1..Resume program execution
 */
#define CAU3_DBGCSR_DBGGO(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_DBGCSR_DBGGO_SHIFT)) & CAU3_DBGCSR_DBGGO_MASK)

#define CAU3_DBGCSR_PCBHF_MASK                   (0x10000U)
#define CAU3_DBGCSR_PCBHF_SHIFT                  (16U)
/*! PCBHF - CryptoCore is Halted due to Hardware Breakpoint
 *  0b0..CryptoCore is not halted due to a hardware breakpoint
 *  0b1..CryptoCore is halted due to a hardware breakpoint
 */
#define CAU3_DBGCSR_PCBHF(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_DBGCSR_PCBHF_SHIFT)) & CAU3_DBGCSR_PCBHF_MASK)

#define CAU3_DBGCSR_SIMHF_MASK                   (0x20000U)
#define CAU3_DBGCSR_SIMHF_SHIFT                  (17U)
/*! SIMHF - CryptoCore is Halted due to Single Instruction Step
 *  0b0..CryptoCore is not in a single step halt
 *  0b1..CryptoCore is in a single step halt
 */
#define CAU3_DBGCSR_SIMHF(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_DBGCSR_SIMHF_SHIFT)) & CAU3_DBGCSR_SIMHF_MASK)

#define CAU3_DBGCSR_HLTIF_MASK                   (0x40000U)
#define CAU3_DBGCSR_HLTIF_SHIFT                  (18U)
/*! HLTIF - CryptoCore is Halted due to HALT Instruction
 *  0b0..CryptoCore is not in software breakpoint
 *  0b1..CryptoCore is in software breakpoint
 */
#define CAU3_DBGCSR_HLTIF(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_DBGCSR_HLTIF_SHIFT)) & CAU3_DBGCSR_HLTIF_MASK)

#define CAU3_DBGCSR_CSTPF_MASK                   (0x40000000U)
#define CAU3_DBGCSR_CSTPF_SHIFT                  (30U)
/*! CSTPF - CryptoCore is Stopped Status Flag
 *  0b0..CryptoCore is not stopped
 *  0b1..CryptoCore is stopped
 */
#define CAU3_DBGCSR_CSTPF(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_DBGCSR_CSTPF_SHIFT)) & CAU3_DBGCSR_CSTPF_MASK)

#define CAU3_DBGCSR_CHLTF_MASK                   (0x80000000U)
#define CAU3_DBGCSR_CHLTF_SHIFT                  (31U)
/*! CHLTF - CryptoCore is Halted Status Flag
 *  0b0..CryptoCore is not halted
 *  0b1..CryptoCore is halted
 */
#define CAU3_DBGCSR_CHLTF(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_DBGCSR_CHLTF_SHIFT)) & CAU3_DBGCSR_CHLTF_MASK)
/*! @} */

/*! @name DBGPBR - Debug PC Breakpoint Register */
/*! @{ */

#define CAU3_DBGPBR_PCBKPT_MASK                  (0xFFFFCU)
#define CAU3_DBGPBR_PCBKPT_SHIFT                 (2U)
/*! PCBKPT - PC Breakpoint */
#define CAU3_DBGPBR_PCBKPT(x)                    (((uint32_t)(((uint32_t)(x)) << CAU3_DBGPBR_PCBKPT_SHIFT)) & CAU3_DBGPBR_PCBKPT_MASK)
/*! @} */

/*! @name DBGMCMD - Debug Memory Command Register */
/*! @{ */

#define CAU3_DBGMCMD_DM_MASK                     (0x1000000U)
#define CAU3_DBGMCMD_DM_SHIFT                    (24U)
/*! DM - Instruction/Data Memory Selection
 *  0b0..IMEM is selected
 *  0b1..DMEM is selected
 */
#define CAU3_DBGMCMD_DM(x)                       (((uint32_t)(((uint32_t)(x)) << CAU3_DBGMCMD_DM_SHIFT)) & CAU3_DBGMCMD_DM_MASK)

#define CAU3_DBGMCMD_IA_MASK                     (0x4000000U)
#define CAU3_DBGMCMD_IA_SHIFT                    (26U)
/*! IA - Increment Address
 *  0b0..Address is not incremented
 *  0b1..Address is incremented after the access
 */
#define CAU3_DBGMCMD_IA(x)                       (((uint32_t)(((uint32_t)(x)) << CAU3_DBGMCMD_IA_SHIFT)) & CAU3_DBGMCMD_IA_MASK)

#define CAU3_DBGMCMD_Rb_1_MASK                   (0x8000000U)
#define CAU3_DBGMCMD_Rb_1_SHIFT                  (27U)
#define CAU3_DBGMCMD_Rb_1(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_DBGMCMD_Rb_1_SHIFT)) & CAU3_DBGMCMD_Rb_1_MASK)

#define CAU3_DBGMCMD_BV_MASK                     (0x10000000U)
#define CAU3_DBGMCMD_BV_SHIFT                    (28U)
/*! BV - Byte Reversal Control
 *  0b0..DMEM bytes are not reversed
 *  0b1..DMEM bytes are reversed
 */
#define CAU3_DBGMCMD_BV(x)                       (((uint32_t)(((uint32_t)(x)) << CAU3_DBGMCMD_BV_SHIFT)) & CAU3_DBGMCMD_BV_MASK)

#define CAU3_DBGMCMD_R_0_MASK                    (0x40000000U)
#define CAU3_DBGMCMD_R_0_SHIFT                   (30U)
#define CAU3_DBGMCMD_R_0(x)                      (((uint32_t)(((uint32_t)(x)) << CAU3_DBGMCMD_R_0_SHIFT)) & CAU3_DBGMCMD_R_0_MASK)

#define CAU3_DBGMCMD_R_1_MASK                    (0x80000000U)
#define CAU3_DBGMCMD_R_1_SHIFT                   (31U)
#define CAU3_DBGMCMD_R_1(x)                      (((uint32_t)(((uint32_t)(x)) << CAU3_DBGMCMD_R_1_SHIFT)) & CAU3_DBGMCMD_R_1_MASK)
/*! @} */

/*! @name DBGMADR - Debug Memory Address Register */
/*! @{ */

#define CAU3_DBGMADR_DMADDR_MASK                 (0xFFFFFFFCU)
#define CAU3_DBGMADR_DMADDR_SHIFT                (2U)
/*! DMADDR - Debug Memory Address */
#define CAU3_DBGMADR_DMADDR(x)                   (((uint32_t)(((uint32_t)(x)) << CAU3_DBGMADR_DMADDR_SHIFT)) & CAU3_DBGMADR_DMADDR_MASK)
/*! @} */

/*! @name DBGMDR - Debug Memory Data Register */
/*! @{ */

#define CAU3_DBGMDR_DMDATA_MASK                  (0xFFFFFFFFU)
#define CAU3_DBGMDR_DMDATA_SHIFT                 (0U)
/*! DMDATA - Debug Memory Data */
#define CAU3_DBGMDR_DMDATA(x)                    (((uint32_t)(((uint32_t)(x)) << CAU3_DBGMDR_DMDATA_SHIFT)) & CAU3_DBGMDR_DMDATA_MASK)
/*! @} */

/*! @name SEMA4 - Semaphore Register */
/*! @{ */

#define CAU3_SEMA4_DID_MASK                      (0xFU)
#define CAU3_SEMA4_DID_SHIFT                     (0U)
/*! DID - Domain ID of Locked Semaphore Owner */
#define CAU3_SEMA4_DID(x)                        (((uint32_t)(((uint32_t)(x)) << CAU3_SEMA4_DID_SHIFT)) & CAU3_SEMA4_DID_MASK)

#define CAU3_SEMA4_PR_MASK                       (0x40U)
#define CAU3_SEMA4_PR_SHIFT                      (6U)
/*! PR - Privilege Attribute of Locked Semaphore Owner
 *  0b0..If semaphore is locked, then owner is operating in user mode
 *  0b1..If semaphore is locked, then owner is operating in privileged mode
 */
#define CAU3_SEMA4_PR(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_SEMA4_PR_SHIFT)) & CAU3_SEMA4_PR_MASK)

#define CAU3_SEMA4_NS_MASK                       (0x80U)
#define CAU3_SEMA4_NS_SHIFT                      (7U)
/*! NS - Non Secure Attribute of the Locked Semaphore Owner
 *  0b0..If semaphore is locked, owner is operating in secure mode
 *  0b1..If semaphore is locked, owner is operating in nonsecure mode
 */
#define CAU3_SEMA4_NS(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_SEMA4_NS_SHIFT)) & CAU3_SEMA4_NS_MASK)

#define CAU3_SEMA4_MSTRN_MASK                    (0x3F00U)
#define CAU3_SEMA4_MSTRN_SHIFT                   (8U)
/*! MSTRN - Master Number of Locked Semaphore Owner */
#define CAU3_SEMA4_MSTRN(x)                      (((uint32_t)(((uint32_t)(x)) << CAU3_SEMA4_MSTRN_SHIFT)) & CAU3_SEMA4_MSTRN_MASK)

#define CAU3_SEMA4_LK_MASK                       (0x80000000U)
#define CAU3_SEMA4_LK_SHIFT                      (31U)
/*! LK - Semaphore Lock and Release Control
 *  0b0..Semaphore release
 *  0b1..Semaphore lock
 */
#define CAU3_SEMA4_LK(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_SEMA4_LK_SHIFT)) & CAU3_SEMA4_LK_MASK)
/*! @} */

/*! @name SMOWNR - Semaphore Ownership Register */
/*! @{ */

#define CAU3_SMOWNR_LOCK_MASK                    (0x1U)
#define CAU3_SMOWNR_LOCK_SHIFT                   (0U)
/*! LOCK - Semaphore Locked
 *  0b0..Semaphore not locked
 *  0b1..Semaphore locked
 */
#define CAU3_SMOWNR_LOCK(x)                      (((uint32_t)(((uint32_t)(x)) << CAU3_SMOWNR_LOCK_SHIFT)) & CAU3_SMOWNR_LOCK_MASK)

#define CAU3_SMOWNR_NOWNER_MASK                  (0x80000000U)
#define CAU3_SMOWNR_NOWNER_SHIFT                 (31U)
/*! NOWNER - Semaphore Ownership
 *  0b0..The host making the current read access is the semaphore owner
 *  0b1..The host making the current read access is NOT the semaphore owner
 */
#define CAU3_SMOWNR_NOWNER(x)                    (((uint32_t)(((uint32_t)(x)) << CAU3_SMOWNR_NOWNER_SHIFT)) & CAU3_SMOWNR_NOWNER_MASK)
/*! @} */

/*! @name ARR - Address Remap Register */
/*! @{ */

#define CAU3_ARR_ARRL_MASK                       (0xFFFFFFFFU)
#define CAU3_ARR_ARRL_SHIFT                      (0U)
/*! ARRL - Address Remap Register List */
#define CAU3_ARR_ARRL(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_ARR_ARRL_SHIFT)) & CAU3_ARR_ARRL_MASK)
/*! @} */

/*! @name CC_R - CryptoCore General Purpose Registers */
/*! @{ */

#define CAU3_CC_R_R_MASK                         (0xFFFFFFFFU)
#define CAU3_CC_R_R_SHIFT                        (0U)
/*! R - CryptoCore general purpose register R */
#define CAU3_CC_R_R(x)                           (((uint32_t)(((uint32_t)(x)) << CAU3_CC_R_R_SHIFT)) & CAU3_CC_R_R_MASK)
/*! @} */

/*! @name CC_R30 - General Purpose R30 */
/*! @{ */

#define CAU3_CC_R30_SP_MASK                      (0xFFFFFFFFU)
#define CAU3_CC_R30_SP_SHIFT                     (0U)
/*! SP - Stack Pointer */
#define CAU3_CC_R30_SP(x)                        (((uint32_t)(((uint32_t)(x)) << CAU3_CC_R30_SP_SHIFT)) & CAU3_CC_R30_SP_MASK)
/*! @} */

/*! @name CC_R31 - General Purpose R31 */
/*! @{ */

#define CAU3_CC_R31_LR_MASK                      (0xFFFFFFFFU)
#define CAU3_CC_R31_LR_SHIFT                     (0U)
/*! LR - Link */
#define CAU3_CC_R31_LR(x)                        (((uint32_t)(((uint32_t)(x)) << CAU3_CC_R31_LR_SHIFT)) & CAU3_CC_R31_LR_MASK)
/*! @} */

/*! @name CC_PC - Program Counter */
/*! @{ */

#define CAU3_CC_PC_PC_MASK                       (0xFFFFFU)
#define CAU3_CC_PC_PC_SHIFT                      (0U)
/*! PC - Program Counter */
#define CAU3_CC_PC_PC(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_CC_PC_PC_SHIFT)) & CAU3_CC_PC_PC_MASK)
/*! @} */

/*! @name CC_CMD - Start Command Register */
/*! @{ */

#define CAU3_CC_CMD_CMD_MASK                     (0x70000U)
#define CAU3_CC_CMD_CMD_SHIFT                    (16U)
/*! CMD - Command
 *  0b000..Use CR[DTCCFG] for task completion configuration
 *  0b001..Issue an interrupt request
 *  0b010..Assert Event Completion Signal
 *  0b100..Issue a DMA request
 */
#define CAU3_CC_CMD_CMD(x)                       (((uint32_t)(((uint32_t)(x)) << CAU3_CC_CMD_CMD_SHIFT)) & CAU3_CC_CMD_CMD_MASK)
/*! @} */

/*! @name CC_CF - Condition Flag */
/*! @{ */

#define CAU3_CC_CF_C_MASK                        (0x1U)
#define CAU3_CC_CF_C_SHIFT                       (0U)
/*! C - Carry flag */
#define CAU3_CC_CF_C(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_CC_CF_C_SHIFT)) & CAU3_CC_CF_C_MASK)

#define CAU3_CC_CF_V_MASK                        (0x2U)
#define CAU3_CC_CF_V_SHIFT                       (1U)
/*! V - Overflow flag */
#define CAU3_CC_CF_V(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_CC_CF_V_SHIFT)) & CAU3_CC_CF_V_MASK)

#define CAU3_CC_CF_Z_MASK                        (0x4U)
#define CAU3_CC_CF_Z_SHIFT                       (2U)
/*! Z - Zero flag */
#define CAU3_CC_CF_Z(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_CC_CF_Z_SHIFT)) & CAU3_CC_CF_Z_MASK)

#define CAU3_CC_CF_N_MASK                        (0x8U)
#define CAU3_CC_CF_N_SHIFT                       (3U)
/*! N - Negative flag */
#define CAU3_CC_CF_N(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_CC_CF_N_SHIFT)) & CAU3_CC_CF_N_MASK)
/*! @} */

/*! @name MDPK - Mode Register (PublicKey) */
/*! @{ */

#define CAU3_MDPK_PKHA_MODE_LS_MASK              (0xFFFU)
#define CAU3_MDPK_PKHA_MODE_LS_SHIFT             (0U)
/*! PKHA_MODE_LS - PKHA_MODE least significant 12 bits */
#define CAU3_MDPK_PKHA_MODE_LS(x)                (((uint32_t)(((uint32_t)(x)) << CAU3_MDPK_PKHA_MODE_LS_SHIFT)) & CAU3_MDPK_PKHA_MODE_LS_MASK)

#define CAU3_MDPK_PKHA_MODE_MS_MASK              (0xF0000U)
#define CAU3_MDPK_PKHA_MODE_MS_SHIFT             (16U)
/*! PKHA_MODE_MS - PKHA_MODE most-significant 4 bits */
#define CAU3_MDPK_PKHA_MODE_MS(x)                (((uint32_t)(((uint32_t)(x)) << CAU3_MDPK_PKHA_MODE_MS_SHIFT)) & CAU3_MDPK_PKHA_MODE_MS_MASK)

#define CAU3_MDPK_ALG_MASK                       (0xF00000U)
#define CAU3_MDPK_ALG_SHIFT                      (20U)
/*! ALG - Algorithm
 *  0b1000..PKHA
 */
#define CAU3_MDPK_ALG(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_MDPK_ALG_SHIFT)) & CAU3_MDPK_ALG_MASK)
/*! @} */

/*! @name COM - Command Register */
/*! @{ */

#define CAU3_COM_ALL_MASK                        (0x1U)
#define CAU3_COM_ALL_SHIFT                       (0U)
/*! ALL - Reset All Internal Logic
 *  0b0..Do Not Reset
 *  0b1..Reset PKHA engine and registers
 */
#define CAU3_COM_ALL(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_COM_ALL_SHIFT)) & CAU3_COM_ALL_MASK)

#define CAU3_COM_PK_MASK                         (0x40U)
#define CAU3_COM_PK_SHIFT                        (6U)
/*! PK - Reset PKHA
 *  0b0..Do Not Reset
 *  0b1..Reset Public Key Hardware Accelerator
 */
#define CAU3_COM_PK(x)                           (((uint32_t)(((uint32_t)(x)) << CAU3_COM_PK_SHIFT)) & CAU3_COM_PK_MASK)
/*! @} */

/*! @name CTL - Control Register */
/*! @{ */

#define CAU3_CTL_IM_MASK                         (0x1U)
#define CAU3_CTL_IM_SHIFT                        (0U)
/*! IM - Interrupt Mask
 *  0b0..Interrupt not masked.
 *  0b1..Interrupt masked
 */
#define CAU3_CTL_IM(x)                           (((uint32_t)(((uint32_t)(x)) << CAU3_CTL_IM_SHIFT)) & CAU3_CTL_IM_MASK)

#define CAU3_CTL_PDE_MASK                        (0x10U)
#define CAU3_CTL_PDE_SHIFT                       (4U)
/*! PDE - PKHA Register DMA Enable
 *  0b0..DMA Request and Done signals disabled for the PKHA Registers.
 *  0b1..DMA Request and Done signals enabled for the PKHA Registers.
 */
#define CAU3_CTL_PDE(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_CTL_PDE_SHIFT)) & CAU3_CTL_PDE_MASK)
/*! @} */

/*! @name CW - Clear Written Register */
/*! @{ */

#define CAU3_CW_CM_MASK                          (0x1U)
#define CAU3_CW_CM_SHIFT                         (0U)
/*! CM - Clear the Mode Register */
#define CAU3_CW_CM(x)                            (((uint32_t)(((uint32_t)(x)) << CAU3_CW_CM_SHIFT)) & CAU3_CW_CM_MASK)

#define CAU3_CW_CPKA_MASK                        (0x1000U)
#define CAU3_CW_CPKA_SHIFT                       (12U)
/*! CPKA - Clear the PKHA A Size Register */
#define CAU3_CW_CPKA(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_CW_CPKA_SHIFT)) & CAU3_CW_CPKA_MASK)

#define CAU3_CW_CPKB_MASK                        (0x2000U)
#define CAU3_CW_CPKB_SHIFT                       (13U)
/*! CPKB - Clear the PKHA B Size Register */
#define CAU3_CW_CPKB(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_CW_CPKB_SHIFT)) & CAU3_CW_CPKB_MASK)

#define CAU3_CW_CPKN_MASK                        (0x4000U)
#define CAU3_CW_CPKN_SHIFT                       (14U)
/*! CPKN - Clear the PKHA N Size Register */
#define CAU3_CW_CPKN(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_CW_CPKN_SHIFT)) & CAU3_CW_CPKN_MASK)

#define CAU3_CW_CPKE_MASK                        (0x8000U)
#define CAU3_CW_CPKE_SHIFT                       (15U)
/*! CPKE - Clear the PKHA E Size Register */
#define CAU3_CW_CPKE(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_CW_CPKE_SHIFT)) & CAU3_CW_CPKE_MASK)
/*! @} */

/*! @name STA - Status Register */
/*! @{ */

#define CAU3_STA_PB_MASK                         (0x40U)
#define CAU3_STA_PB_SHIFT                        (6U)
/*! PB - PKHA Busy
 *  0b0..PKHA Idle
 *  0b1..PKHA Busy.
 */
#define CAU3_STA_PB(x)                           (((uint32_t)(((uint32_t)(x)) << CAU3_STA_PB_SHIFT)) & CAU3_STA_PB_MASK)

#define CAU3_STA_DI_MASK                         (0x10000U)
#define CAU3_STA_DI_SHIFT                        (16U)
/*! DI - Done Interrupt */
#define CAU3_STA_DI(x)                           (((uint32_t)(((uint32_t)(x)) << CAU3_STA_DI_SHIFT)) & CAU3_STA_DI_MASK)

#define CAU3_STA_EI_MASK                         (0x100000U)
#define CAU3_STA_EI_SHIFT                        (20U)
/*! EI - Error Interrupt
 *  0b0..Not Error.
 *  0b1..Error Interrupt.
 */
#define CAU3_STA_EI(x)                           (((uint32_t)(((uint32_t)(x)) << CAU3_STA_EI_SHIFT)) & CAU3_STA_EI_MASK)

#define CAU3_STA_PKP_MASK                        (0x10000000U)
#define CAU3_STA_PKP_SHIFT                       (28U)
/*! PKP - Public Key is Prime */
#define CAU3_STA_PKP(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_STA_PKP_SHIFT)) & CAU3_STA_PKP_MASK)

#define CAU3_STA_PKO_MASK                        (0x20000000U)
#define CAU3_STA_PKO_SHIFT                       (29U)
/*! PKO - Public Key Operation is One */
#define CAU3_STA_PKO(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_STA_PKO_SHIFT)) & CAU3_STA_PKO_MASK)

#define CAU3_STA_PKZ_MASK                        (0x40000000U)
#define CAU3_STA_PKZ_SHIFT                       (30U)
/*! PKZ - Public Key Operation is Zero */
#define CAU3_STA_PKZ(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_STA_PKZ_SHIFT)) & CAU3_STA_PKZ_MASK)
/*! @} */

/*! @name ESTA - Error Status Register */
/*! @{ */

#define CAU3_ESTA_ERRID1_MASK                    (0xFU)
#define CAU3_ESTA_ERRID1_SHIFT                   (0U)
/*! ERRID1 - Error ID 1
 *  0b0001..Mode Error
 *  0b0010..PKHA N Register Size Error
 *  0b0011..PKHA E Register Size Error
 *  0b0100..PKHA A Register Size Error
 *  0b0101..PKHA B Register Size Error
 *  0b0110..PKHA C input (as contained in the PKHA B0 quadrant) is Zero
 *  0b0111..PKHA Divide by Zero Error
 *  0b1000..PKHA Modulus Even Error
 *  0b1111..Invalid Crypto Engine Selected
 */
#define CAU3_ESTA_ERRID1(x)                      (((uint32_t)(((uint32_t)(x)) << CAU3_ESTA_ERRID1_SHIFT)) & CAU3_ESTA_ERRID1_MASK)

#define CAU3_ESTA_CL1_MASK                       (0xF00U)
#define CAU3_ESTA_CL1_SHIFT                      (8U)
/*! CL1 - algorithms
 *  0b0000..General Error
 *  0b1000..Public Key
 */
#define CAU3_ESTA_CL1(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_ESTA_CL1_SHIFT)) & CAU3_ESTA_CL1_MASK)
/*! @} */

/*! @name PKASZ - PKHA A Size Register */
/*! @{ */

#define CAU3_PKASZ_PKASZ_MASK                    (0x1FFU)
#define CAU3_PKASZ_PKASZ_SHIFT                   (0U)
/*! PKASZ - PKHA A Size */
#define CAU3_PKASZ_PKASZ(x)                      (((uint32_t)(((uint32_t)(x)) << CAU3_PKASZ_PKASZ_SHIFT)) & CAU3_PKASZ_PKASZ_MASK)
/*! @} */

/*! @name PKBSZ - PKHA B Size Register */
/*! @{ */

#define CAU3_PKBSZ_PKBSZ_MASK                    (0x1FFU)
#define CAU3_PKBSZ_PKBSZ_SHIFT                   (0U)
/*! PKBSZ - PKHA B Size */
#define CAU3_PKBSZ_PKBSZ(x)                      (((uint32_t)(((uint32_t)(x)) << CAU3_PKBSZ_PKBSZ_SHIFT)) & CAU3_PKBSZ_PKBSZ_MASK)
/*! @} */

/*! @name PKNSZ - PKHA N Size Register */
/*! @{ */

#define CAU3_PKNSZ_PKNSZ_MASK                    (0x1FFU)
#define CAU3_PKNSZ_PKNSZ_SHIFT                   (0U)
/*! PKNSZ - PKHA N Size */
#define CAU3_PKNSZ_PKNSZ(x)                      (((uint32_t)(((uint32_t)(x)) << CAU3_PKNSZ_PKNSZ_SHIFT)) & CAU3_PKNSZ_PKNSZ_MASK)
/*! @} */

/*! @name PKESZ - PKHA E Size Register */
/*! @{ */

#define CAU3_PKESZ_PKESZ_MASK                    (0x1FFU)
#define CAU3_PKESZ_PKESZ_SHIFT                   (0U)
/*! PKESZ - PKHA E Size */
#define CAU3_PKESZ_PKESZ(x)                      (((uint32_t)(((uint32_t)(x)) << CAU3_PKESZ_PKESZ_SHIFT)) & CAU3_PKESZ_PKESZ_MASK)
/*! @} */

/*! @name PKHA_VID1 - PKHA Revision ID 1 */
/*! @{ */

#define CAU3_PKHA_VID1_MIN_REV_MASK              (0xFFU)
#define CAU3_PKHA_VID1_MIN_REV_SHIFT             (0U)
/*! MIN_REV - Minor Revision Number */
#define CAU3_PKHA_VID1_MIN_REV(x)                (((uint32_t)(((uint32_t)(x)) << CAU3_PKHA_VID1_MIN_REV_SHIFT)) & CAU3_PKHA_VID1_MIN_REV_MASK)

#define CAU3_PKHA_VID1_MAJ_REV_MASK              (0xFF00U)
#define CAU3_PKHA_VID1_MAJ_REV_SHIFT             (8U)
/*! MAJ_REV - Major Revision Number */
#define CAU3_PKHA_VID1_MAJ_REV(x)                (((uint32_t)(((uint32_t)(x)) << CAU3_PKHA_VID1_MAJ_REV_SHIFT)) & CAU3_PKHA_VID1_MAJ_REV_MASK)

#define CAU3_PKHA_VID1_IP_ID_MASK                (0xFFFF0000U)
#define CAU3_PKHA_VID1_IP_ID_SHIFT               (16U)
/*! IP_ID - Hardware Revision ID */
#define CAU3_PKHA_VID1_IP_ID(x)                  (((uint32_t)(((uint32_t)(x)) << CAU3_PKHA_VID1_IP_ID_SHIFT)) & CAU3_PKHA_VID1_IP_ID_MASK)
/*! @} */

/*! @name PKHA_VID2 - PKHA Revision ID 2 */
/*! @{ */

#define CAU3_PKHA_VID2_ECO_REV_MASK              (0xFFU)
#define CAU3_PKHA_VID2_ECO_REV_SHIFT             (0U)
/*! ECO_REV - ECO Revision Number */
#define CAU3_PKHA_VID2_ECO_REV(x)                (((uint32_t)(((uint32_t)(x)) << CAU3_PKHA_VID2_ECO_REV_SHIFT)) & CAU3_PKHA_VID2_ECO_REV_MASK)

#define CAU3_PKHA_VID2_ARCH_ERA_MASK             (0xFF00U)
#define CAU3_PKHA_VID2_ARCH_ERA_SHIFT            (8U)
/*! ARCH_ERA - Architecture ERA */
#define CAU3_PKHA_VID2_ARCH_ERA(x)               (((uint32_t)(((uint32_t)(x)) << CAU3_PKHA_VID2_ARCH_ERA_SHIFT)) & CAU3_PKHA_VID2_ARCH_ERA_MASK)
/*! @} */

/*! @name CHA_VID - CHA Revision ID */
/*! @{ */

#define CAU3_CHA_VID_PKHAREV_MASK                (0xF0000U)
#define CAU3_CHA_VID_PKHAREV_SHIFT               (16U)
/*! PKHAREV - PK Revision NUmber */
#define CAU3_CHA_VID_PKHAREV(x)                  (((uint32_t)(((uint32_t)(x)) << CAU3_CHA_VID_PKHAREV_SHIFT)) & CAU3_CHA_VID_PKHAREV_MASK)

#define CAU3_CHA_VID_PKHAVID_MASK                (0xF00000U)
#define CAU3_CHA_VID_PKHAVID_SHIFT               (20U)
/*! PKHAVID - PK Version ID */
#define CAU3_CHA_VID_PKHAVID(x)                  (((uint32_t)(((uint32_t)(x)) << CAU3_CHA_VID_PKHAVID_SHIFT)) & CAU3_CHA_VID_PKHAVID_MASK)
/*! @} */

/*! @name PKHA_CCR - PKHA Clock Control Register */
/*! @{ */

#define CAU3_PKHA_CCR_CKTHRT_MASK                (0x7U)
#define CAU3_PKHA_CCR_CKTHRT_SHIFT               (0U)
/*! CKTHRT - Clock Throttle selection
 *  0b000..PKHA clock division rate is 8/8 - full speed
 *  0b001..PKHA clock division rate is 1/8
 *  0b010..PKHA clock division rate is 2/8
 *  0b011..PKHA clock division rate is 3/8
 *  0b100..PKHA clock division rate is 4/8
 *  0b101..PKHA clock division rate is 5/8
 *  0b110..PKHA clock division rate is 6/8
 *  0b111..PKHA clock division rate is 7/8
 */
#define CAU3_PKHA_CCR_CKTHRT(x)                  (((uint32_t)(((uint32_t)(x)) << CAU3_PKHA_CCR_CKTHRT_SHIFT)) & CAU3_PKHA_CCR_CKTHRT_MASK)

#define CAU3_PKHA_CCR_LK_MASK                    (0x1000000U)
#define CAU3_PKHA_CCR_LK_SHIFT                   (24U)
/*! LK - Register Lock
 *  0b0..Register is unlocked
 *  0b1..Register is locked
 */
#define CAU3_PKHA_CCR_LK(x)                      (((uint32_t)(((uint32_t)(x)) << CAU3_PKHA_CCR_LK_SHIFT)) & CAU3_PKHA_CCR_LK_MASK)

#define CAU3_PKHA_CCR_ELFR_MASK                  (0x20000000U)
#define CAU3_PKHA_CCR_ELFR_SHIFT                 (29U)
/*! ELFR - Enable Linear Feedback Shift Register
 *  0b0..LFSR is only enabled if ECT = 1 and ECJ = 1
 *  0b1..LFSR is enabled independently of ECT and ECJ
 */
#define CAU3_PKHA_CCR_ELFR(x)                    (((uint32_t)(((uint32_t)(x)) << CAU3_PKHA_CCR_ELFR_SHIFT)) & CAU3_PKHA_CCR_ELFR_MASK)

#define CAU3_PKHA_CCR_ECJ_MASK                   (0x40000000U)
#define CAU3_PKHA_CCR_ECJ_SHIFT                  (30U)
/*! ECJ - Enable Clock Jitter
 *  0b0..Clock Jitter is disabled
 *  0b1..Clock jitter is enabled
 */
#define CAU3_PKHA_CCR_ECJ(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_PKHA_CCR_ECJ_SHIFT)) & CAU3_PKHA_CCR_ECJ_MASK)

#define CAU3_PKHA_CCR_ECT_MASK                   (0x80000000U)
#define CAU3_PKHA_CCR_ECT_SHIFT                  (31U)
/*! ECT - Enable Clock Throttle
 *  0b0..PKHA clock throttle disabled meaning that PKHA is operatiing at full speed
 *  0b1..PKHA clock throttle enabled
 */
#define CAU3_PKHA_CCR_ECT(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_PKHA_CCR_ECT_SHIFT)) & CAU3_PKHA_CCR_ECT_MASK)
/*! @} */

/*! @name GSR - Global Status Register */
/*! @{ */

#define CAU3_GSR_CDI_MASK                        (0x400U)
#define CAU3_GSR_CDI_SHIFT                       (10U)
/*! CDI - CAU3 Done Interrupt occurred
 *  0b0..CAU3 Done Interrupt did not occur
 *  0b1..CAU3 Done Interrupt occurred
 */
#define CAU3_GSR_CDI(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_GSR_CDI_SHIFT)) & CAU3_GSR_CDI_MASK)

#define CAU3_GSR_CEI_MASK                        (0x4000U)
#define CAU3_GSR_CEI_SHIFT                       (14U)
/*! CEI - CAU3 Error Interrupt
 *  0b0..CAU3 Error Interrupt did not occur
 *  0b1..CAU3 Error Interrupt occurred
 */
#define CAU3_GSR_CEI(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_GSR_CEI_SHIFT)) & CAU3_GSR_CEI_MASK)

#define CAU3_GSR_PEI_MASK                        (0x8000U)
#define CAU3_GSR_PEI_SHIFT                       (15U)
/*! PEI - PKHA Done or Error Interrupt
 *  0b0..PKHA interrupt did not occur
 *  0b1..PKHA interrupt had occurred
 */
#define CAU3_GSR_PEI(x)                          (((uint32_t)(((uint32_t)(x)) << CAU3_GSR_PEI_SHIFT)) & CAU3_GSR_PEI_MASK)

#define CAU3_GSR_PBSY_MASK                       (0x80000000U)
#define CAU3_GSR_PBSY_SHIFT                      (31U)
/*! PBSY - PKHA Busy
 *  0b0..PKHA not busy
 *  0b1..PKHA busy
 */
#define CAU3_GSR_PBSY(x)                         (((uint32_t)(((uint32_t)(x)) << CAU3_GSR_PBSY_SHIFT)) & CAU3_GSR_PBSY_MASK)
/*! @} */

/*! @name CKLFSR - Clock Linear Feedback Shift Register */
/*! @{ */

#define CAU3_CKLFSR_LFSR_MASK                    (0xFFFFFFFFU)
#define CAU3_CKLFSR_LFSR_SHIFT                   (0U)
/*! LFSR - Linear Feedback Shift Register */
#define CAU3_CKLFSR_LFSR(x)                      (((uint32_t)(((uint32_t)(x)) << CAU3_CKLFSR_LFSR_SHIFT)) & CAU3_CKLFSR_LFSR_MASK)
/*! @} */

/*! @name PKA0 - PKHA A0 Register */
/*! @{ */

#define CAU3_PKA0_PKHA_A0_MASK                   (0xFFFFFFFFU)
#define CAU3_PKA0_PKHA_A0_SHIFT                  (0U)
/*! PKHA_A0 - A0 VALUE */
#define CAU3_PKA0_PKHA_A0(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_PKA0_PKHA_A0_SHIFT)) & CAU3_PKA0_PKHA_A0_MASK)
/*! @} */

/*! @name PKA1 - PKHA A1 Register */
/*! @{ */

#define CAU3_PKA1_PKHA_A1_MASK                   (0xFFFFFFFFU)
#define CAU3_PKA1_PKHA_A1_SHIFT                  (0U)
/*! PKHA_A1 - A1 VALUE */
#define CAU3_PKA1_PKHA_A1(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_PKA1_PKHA_A1_SHIFT)) & CAU3_PKA1_PKHA_A1_MASK)
/*! @} */

/*! @name PKA2 - PKHA A2 Register */
/*! @{ */

#define CAU3_PKA2_PKHA_A2_MASK                   (0xFFFFFFFFU)
#define CAU3_PKA2_PKHA_A2_SHIFT                  (0U)
/*! PKHA_A2 - A2 VALUE */
#define CAU3_PKA2_PKHA_A2(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_PKA2_PKHA_A2_SHIFT)) & CAU3_PKA2_PKHA_A2_MASK)
/*! @} */

/*! @name PKA3 - PKHA A3 Register */
/*! @{ */

#define CAU3_PKA3_PKHA_A3_MASK                   (0xFFFFFFFFU)
#define CAU3_PKA3_PKHA_A3_SHIFT                  (0U)
/*! PKHA_A3 - A3 VALUE */
#define CAU3_PKA3_PKHA_A3(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_PKA3_PKHA_A3_SHIFT)) & CAU3_PKA3_PKHA_A3_MASK)
/*! @} */

/*! @name PKB0 - PKHA B0 Register */
/*! @{ */

#define CAU3_PKB0_PKHA_B0_MASK                   (0xFFFFFFFFU)
#define CAU3_PKB0_PKHA_B0_SHIFT                  (0U)
/*! PKHA_B0 - B0 VALUE */
#define CAU3_PKB0_PKHA_B0(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_PKB0_PKHA_B0_SHIFT)) & CAU3_PKB0_PKHA_B0_MASK)
/*! @} */

/*! @name PKB1 - PKHA B1 Register */
/*! @{ */

#define CAU3_PKB1_PKHA_B1_MASK                   (0xFFFFFFFFU)
#define CAU3_PKB1_PKHA_B1_SHIFT                  (0U)
/*! PKHA_B1 - B1 VALUE */
#define CAU3_PKB1_PKHA_B1(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_PKB1_PKHA_B1_SHIFT)) & CAU3_PKB1_PKHA_B1_MASK)
/*! @} */

/*! @name PKB2 - PKHA B2 Register */
/*! @{ */

#define CAU3_PKB2_PKHA_B2_MASK                   (0xFFFFFFFFU)
#define CAU3_PKB2_PKHA_B2_SHIFT                  (0U)
/*! PKHA_B2 - B2 VALUE */
#define CAU3_PKB2_PKHA_B2(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_PKB2_PKHA_B2_SHIFT)) & CAU3_PKB2_PKHA_B2_MASK)
/*! @} */

/*! @name PKB3 - PKHA B3 Register */
/*! @{ */

#define CAU3_PKB3_PKHA_B3_MASK                   (0xFFFFFFFFU)
#define CAU3_PKB3_PKHA_B3_SHIFT                  (0U)
/*! PKHA_B3 - B3 VALUE */
#define CAU3_PKB3_PKHA_B3(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_PKB3_PKHA_B3_SHIFT)) & CAU3_PKB3_PKHA_B3_MASK)
/*! @} */

/*! @name PKN0 - PKHA N0 Register */
/*! @{ */

#define CAU3_PKN0_PKHA_N0_MASK                   (0xFFFFFFFFU)
#define CAU3_PKN0_PKHA_N0_SHIFT                  (0U)
/*! PKHA_N0 - N0 VALUE */
#define CAU3_PKN0_PKHA_N0(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_PKN0_PKHA_N0_SHIFT)) & CAU3_PKN0_PKHA_N0_MASK)
/*! @} */

/*! @name PKN1 - PKHA N1 Register */
/*! @{ */

#define CAU3_PKN1_PKHA_N1_MASK                   (0xFFFFFFFFU)
#define CAU3_PKN1_PKHA_N1_SHIFT                  (0U)
/*! PKHA_N1 - N1 VALUE */
#define CAU3_PKN1_PKHA_N1(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_PKN1_PKHA_N1_SHIFT)) & CAU3_PKN1_PKHA_N1_MASK)
/*! @} */

/*! @name PKN2 - PKHA N2 Register */
/*! @{ */

#define CAU3_PKN2_PKHA_N2_MASK                   (0xFFFFFFFFU)
#define CAU3_PKN2_PKHA_N2_SHIFT                  (0U)
/*! PKHA_N2 - N2 VALUE */
#define CAU3_PKN2_PKHA_N2(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_PKN2_PKHA_N2_SHIFT)) & CAU3_PKN2_PKHA_N2_MASK)
/*! @} */

/*! @name PKN3 - PKHA N3 Register */
/*! @{ */

#define CAU3_PKN3_PKHA_N3_MASK                   (0xFFFFFFFFU)
#define CAU3_PKN3_PKHA_N3_SHIFT                  (0U)
/*! PKHA_N3 - N3 VALUE */
#define CAU3_PKN3_PKHA_N3(x)                     (((uint32_t)(((uint32_t)(x)) << CAU3_PKN3_PKHA_N3_SHIFT)) & CAU3_PKN3_PKHA_N3_MASK)
/*! @} */

/*! @name PKE - PKHA E Register */
/*! @{ */

#define CAU3_PKE_PKHA_E_MASK                     (0xFFFFFFFFU)
#define CAU3_PKE_PKHA_E_SHIFT                    (0U)
/*! PKHA_E - E VALUE */
#define CAU3_PKE_PKHA_E(x)                       (((uint32_t)(((uint32_t)(x)) << CAU3_PKE_PKHA_E_SHIFT)) & CAU3_PKE_PKHA_E_MASK)
/*! @} */

/* The count of CAU3_PKE */
#define CAU3_PKE_COUNT                           (128U)


/*!
 * @}
 */ /* end of group CAU3_Register_Masks */


/*!
 * @}
 */ /* end of group CAU3_Peripheral_Access_Layer */


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


#endif  /* PERI_CAU3_H_ */

