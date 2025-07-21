/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FLEXSPI_SLV
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FLEXSPI_SLV.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FLEXSPI_SLV
 *
 * CMSIS Peripheral Access Layer for FLEXSPI_SLV
 */

#if !defined(PERI_FLEXSPI_SLV_H_)
#define PERI_FLEXSPI_SLV_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- FLEXSPI_SLV Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXSPI_SLV_Peripheral_Access_Layer FLEXSPI_SLV Peripheral Access Layer
 * @{
 */

/** FLEXSPI_SLV - Size of Registers Arrays */
#define FLEXSPI_SLV_READ_COMMAND_COUNT            2u
#define FLEXSPI_SLV_WRITE_COMMAND_COUNT           2u
#define FLEXSPI_SLV_CMD_RANGE_COUNT               2u
#define FLEXSPI_SLV_SPIMAILB_COUNT                9u

/** FLEXSPI_SLV - Register Layout Typedef */
typedef struct {
  __IO uint32_t MODULE_CONTROL;                    /**< Module Control, offset: 0x0 */
  __IO uint32_t READ_COMMAND_CONTROL;              /**< Read Command Control, offset: 0x4 */
  __IO uint32_t READ_REGISTER_COMMAND0;            /**< Read Register Command Setting, offset: 0x8 */
  __IO uint32_t READ_COMMAND[FLEXSPI_SLV_READ_COMMAND_COUNT]; /**< Read Command 1 setting..Read Command 2 setting, array offset: 0xC, array step: 0x4 */
  __IO uint32_t WRITE_COMMAND_CONTROL;             /**< Write Command Control, offset: 0x14 */
  __IO uint32_t WRITE_REGISTER_COMMAND0;           /**< Write Register Command 0 Setting, offset: 0x18 */
  __IO uint32_t WRITE_COMMAND[FLEXSPI_SLV_WRITE_COMMAND_COUNT]; /**< Write Command 1 Setting..Write Command 2 Setting, array offset: 0x1C, array step: 0x4 */
  __IO uint32_t RW_COMMAND_BASE;                   /**< Read Write Command Address Base, offset: 0x24 */
  __IO uint32_t CMD_RANGE[FLEXSPI_SLV_CMD_RANGE_COUNT]; /**< Command Suit 1 Range..Command Suit 2 Range, array offset: 0x28, array step: 0x4 */
  __I  uint32_t MODULE_STATUS;                     /**< Module Status, offset: 0x30 */
  __IO uint32_t MODULE_INT;                        /**< SPI FLR interrupt, offset: 0x34 */
  __IO uint32_t MODULE_INTEN;                      /**< SPI FLR Interrupt Enable, offset: 0x38 */
  __IO uint32_t SPI_MAIL_CTRL;                     /**< SPI Mailbox control, offset: 0x3C */
  __I  uint32_t SPIMAIL[FLEXSPI_SLV_SPIMAILB_COUNT]; /**< SPI Mail Interrupt, array offset: 0x40, array step: 0x4 */
} FLEXSPI_SLV_Type;

/* ----------------------------------------------------------------------------
   -- FLEXSPI_SLV Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXSPI_SLV_Register_Masks FLEXSPI_SLV Register Masks
 * @{
 */

/*! @name MODULE_CONTROL - Module Control */
/*! @{ */

#define FLEXSPI_SLV_MODULE_CONTROL_SWRESET_MASK  (0x1U)
#define FLEXSPI_SLV_MODULE_CONTROL_SWRESET_SHIFT (0U)
/*! SWRESET - Software Reset
 *  0b0..Finished
 *  0b1..Initiate
 */
#define FLEXSPI_SLV_MODULE_CONTROL_SWRESET(x)    (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_CONTROL_SWRESET_SHIFT)) & FLEXSPI_SLV_MODULE_CONTROL_SWRESET_MASK)

#define FLEXSPI_SLV_MODULE_CONTROL_IOMODE_MASK   (0x6U)
#define FLEXSPI_SLV_MODULE_CONTROL_IOMODE_SHIFT  (1U)
/*! IOMODE - SPI IO Mode Control
 *  0b00..SDR*4
 *  0b01..SDR*8
 *  0b10..DDR*4
 *  0b11..DDR*8
 */
#define FLEXSPI_SLV_MODULE_CONTROL_IOMODE(x)     (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_CONTROL_IOMODE_SHIFT)) & FLEXSPI_SLV_MODULE_CONTROL_IOMODE_MASK)

#define FLEXSPI_SLV_MODULE_CONTROL_DQSSTOP_MASK  (0x8U)
#define FLEXSPI_SLV_MODULE_CONTROL_DQSSTOP_SHIFT (3U)
/*! DQSSTOP - DQS Stop Feature
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_SLV_MODULE_CONTROL_DQSSTOP(x)    (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_CONTROL_DQSSTOP_SHIFT)) & FLEXSPI_SLV_MODULE_CONTROL_DQSSTOP_MASK)

#define FLEXSPI_SLV_MODULE_CONTROL_CSMASK_MASK   (0x10U)
#define FLEXSPI_SLV_MODULE_CONTROL_CSMASK_SHIFT  (4U)
/*! CSMASK - Chip Select Mask
 *  0b0..Not masked
 *  0b1..Masked
 */
#define FLEXSPI_SLV_MODULE_CONTROL_CSMASK(x)     (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_CONTROL_CSMASK_SHIFT)) & FLEXSPI_SLV_MODULE_CONTROL_CSMASK_MASK)

#define FLEXSPI_SLV_MODULE_CONTROL_BLKREAD_MASK  (0x20U)
#define FLEXSPI_SLV_MODULE_CONTROL_BLKREAD_SHIFT (5U)
/*! BLKREAD - Block Read
 *  0b0..Allowed
 *  0b1..Blocked
 */
#define FLEXSPI_SLV_MODULE_CONTROL_BLKREAD(x)    (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_CONTROL_BLKREAD_SHIFT)) & FLEXSPI_SLV_MODULE_CONTROL_BLKREAD_MASK)

#define FLEXSPI_SLV_MODULE_CONTROL_BLKWRITE_MASK (0x40U)
#define FLEXSPI_SLV_MODULE_CONTROL_BLKWRITE_SHIFT (6U)
/*! BLKWRITE - Block Write
 *  0b0..Allowed
 *  0b1..Blocked
 */
#define FLEXSPI_SLV_MODULE_CONTROL_BLKWRITE(x)   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_CONTROL_BLKWRITE_SHIFT)) & FLEXSPI_SLV_MODULE_CONTROL_BLKWRITE_MASK)

#define FLEXSPI_SLV_MODULE_CONTROL_BLKNXTWR_MASK (0x80U)
#define FLEXSPI_SLV_MODULE_CONTROL_BLKNXTWR_SHIFT (7U)
/*! BLKNXTWR - Block Next Write Command
 *  0b0..Allowed
 *  0b1..Blocked
 */
#define FLEXSPI_SLV_MODULE_CONTROL_BLKNXTWR(x)   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_CONTROL_BLKNXTWR_SHIFT)) & FLEXSPI_SLV_MODULE_CONTROL_BLKNXTWR_MASK)

#define FLEXSPI_SLV_MODULE_CONTROL_BLKNXTRD_MASK (0x100U)
#define FLEXSPI_SLV_MODULE_CONTROL_BLKNXTRD_SHIFT (8U)
/*! BLKNXTRD - Block Next Read
 *  0b0..Allowed
 *  0b1..Blocked
 */
#define FLEXSPI_SLV_MODULE_CONTROL_BLKNXTRD(x)   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_CONTROL_BLKNXTRD_SHIFT)) & FLEXSPI_SLV_MODULE_CONTROL_BLKNXTRD_MASK)

#define FLEXSPI_SLV_MODULE_CONTROL_ALLOWONEWR_MASK (0x200U)
#define FLEXSPI_SLV_MODULE_CONTROL_ALLOWONEWR_SHIFT (9U)
/*! ALLOWONEWR - Allow One More Write
 *  0b0..Not allowed
 *  0b1..Allowed
 */
#define FLEXSPI_SLV_MODULE_CONTROL_ALLOWONEWR(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_CONTROL_ALLOWONEWR_SHIFT)) & FLEXSPI_SLV_MODULE_CONTROL_ALLOWONEWR_MASK)

#define FLEXSPI_SLV_MODULE_CONTROL_ALLOWONERD_MASK (0x400U)
#define FLEXSPI_SLV_MODULE_CONTROL_ALLOWONERD_SHIFT (10U)
/*! ALLOWONERD - Allow One More Read
 *  0b0..Not allowed
 *  0b1..Allowed
 */
#define FLEXSPI_SLV_MODULE_CONTROL_ALLOWONERD(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_CONTROL_ALLOWONERD_SHIFT)) & FLEXSPI_SLV_MODULE_CONTROL_ALLOWONERD_MASK)

#define FLEXSPI_SLV_MODULE_CONTROL_CMDRANGEBASEUPDATE_MASK (0x800U)
#define FLEXSPI_SLV_MODULE_CONTROL_CMDRANGEBASEUPDATE_SHIFT (11U)
/*! CMDRANGEBASEUPDATE - AXI Command Range Base Update
 *  0b0..Not updated
 *  0b1..Updated
 */
#define FLEXSPI_SLV_MODULE_CONTROL_CMDRANGEBASEUPDATE(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_CONTROL_CMDRANGEBASEUPDATE_SHIFT)) & FLEXSPI_SLV_MODULE_CONTROL_CMDRANGEBASEUPDATE_MASK)
/*! @} */

/*! @name READ_COMMAND_CONTROL - Read Command Control */
/*! @{ */

#define FLEXSPI_SLV_READ_COMMAND_CONTROL_RDFETCHSIZE_MASK (0x3U)
#define FLEXSPI_SLV_READ_COMMAND_CONTROL_RDFETCHSIZE_SHIFT (0U)
/*! RDFETCHSIZE - Read Fetch Size
 *  0b00..256 bytes
 *  0b01..512 bytes
 *  0b10..1 KB
 *  0b11..2 KB
 */
#define FLEXSPI_SLV_READ_COMMAND_CONTROL_RDFETCHSIZE(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_READ_COMMAND_CONTROL_RDFETCHSIZE_SHIFT)) & FLEXSPI_SLV_READ_COMMAND_CONTROL_RDFETCHSIZE_MASK)

#define FLEXSPI_SLV_READ_COMMAND_CONTROL_RDWM_MASK (0xFCU)
#define FLEXSPI_SLV_READ_COMMAND_CONTROL_RDWM_SHIFT (2U)
/*! RDWM - Read Watermark Level */
#define FLEXSPI_SLV_READ_COMMAND_CONTROL_RDWM(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_READ_COMMAND_CONTROL_RDWM_SHIFT)) & FLEXSPI_SLV_READ_COMMAND_CONTROL_RDWM_MASK)

#define FLEXSPI_SLV_READ_COMMAND_CONTROL_RDOT_MASK (0x100U)
#define FLEXSPI_SLV_READ_COMMAND_CONTROL_RDOT_SHIFT (8U)
/*! RDOT - Read Outstanding
 *  0b0..Send requests after previous leaders finish
 *  0b1..Send requests outstandingly
 */
#define FLEXSPI_SLV_READ_COMMAND_CONTROL_RDOT(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_READ_COMMAND_CONTROL_RDOT_SHIFT)) & FLEXSPI_SLV_READ_COMMAND_CONTROL_RDOT_MASK)

#define FLEXSPI_SLV_READ_COMMAND_CONTROL_WMEN_MASK (0x200U)
#define FLEXSPI_SLV_READ_COMMAND_CONTROL_WMEN_SHIFT (9U)
/*! WMEN - Read Water Mark Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_SLV_READ_COMMAND_CONTROL_WMEN(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_READ_COMMAND_CONTROL_WMEN_SHIFT)) & FLEXSPI_SLV_READ_COMMAND_CONTROL_WMEN_MASK)
/*! @} */

/*! @name READ_REGISTER_COMMAND0 - Read Register Command Setting */
/*! @{ */

#define FLEXSPI_SLV_READ_REGISTER_COMMAND0_DUMMYCYCLES_MASK (0xFFFFU)
#define FLEXSPI_SLV_READ_REGISTER_COMMAND0_DUMMYCYCLES_SHIFT (0U)
/*! DUMMYCYCLES - Read Register Dummy Cycles */
#define FLEXSPI_SLV_READ_REGISTER_COMMAND0_DUMMYCYCLES(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_READ_REGISTER_COMMAND0_DUMMYCYCLES_SHIFT)) & FLEXSPI_SLV_READ_REGISTER_COMMAND0_DUMMYCYCLES_MASK)

#define FLEXSPI_SLV_READ_REGISTER_COMMAND0_COMMANDSET_MASK (0xFFFF0000U)
#define FLEXSPI_SLV_READ_REGISTER_COMMAND0_COMMANDSET_SHIFT (16U)
/*! COMMANDSET - Read Register Command Setting */
#define FLEXSPI_SLV_READ_REGISTER_COMMAND0_COMMANDSET(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_READ_REGISTER_COMMAND0_COMMANDSET_SHIFT)) & FLEXSPI_SLV_READ_REGISTER_COMMAND0_COMMANDSET_MASK)
/*! @} */

/*! @name READ_COMMAND - Read Command 1 setting..Read Command 2 setting */
/*! @{ */

#define FLEXSPI_SLV_READ_COMMAND_DUMMYCYCLES_MASK (0xFFFFU)
#define FLEXSPI_SLV_READ_COMMAND_DUMMYCYCLES_SHIFT (0U)
/*! DUMMYCYCLES - Read Command 2 Dummy Cycles */
#define FLEXSPI_SLV_READ_COMMAND_DUMMYCYCLES(x)  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_READ_COMMAND_DUMMYCYCLES_SHIFT)) & FLEXSPI_SLV_READ_COMMAND_DUMMYCYCLES_MASK)

#define FLEXSPI_SLV_READ_COMMAND_COMMANDSET_MASK (0xFFFF0000U)
#define FLEXSPI_SLV_READ_COMMAND_COMMANDSET_SHIFT (16U)
/*! COMMANDSET - Read Command 2 Setting */
#define FLEXSPI_SLV_READ_COMMAND_COMMANDSET(x)   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_READ_COMMAND_COMMANDSET_SHIFT)) & FLEXSPI_SLV_READ_COMMAND_COMMANDSET_MASK)
/*! @} */

/*! @name WRITE_COMMAND_CONTROL - Write Command Control */
/*! @{ */

#define FLEXSPI_SLV_WRITE_COMMAND_CONTROL_WRWM_MASK (0x3U)
#define FLEXSPI_SLV_WRITE_COMMAND_CONTROL_WRWM_SHIFT (0U)
/*! WRWM - Write Watermark
 *  0b00..32 bytes
 *  0b01..64 bytes
 *  0b10..128 bytes
 *  0b11..256 bytes
 */
#define FLEXSPI_SLV_WRITE_COMMAND_CONTROL_WRWM(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_WRITE_COMMAND_CONTROL_WRWM_SHIFT)) & FLEXSPI_SLV_WRITE_COMMAND_CONTROL_WRWM_MASK)
/*! @} */

/*! @name WRITE_REGISTER_COMMAND0 - Write Register Command 0 Setting */
/*! @{ */

#define FLEXSPI_SLV_WRITE_REGISTER_COMMAND0_COMMANDSET_MASK (0xFFFF0000U)
#define FLEXSPI_SLV_WRITE_REGISTER_COMMAND0_COMMANDSET_SHIFT (16U)
/*! COMMANDSET - Write Register Command Setting */
#define FLEXSPI_SLV_WRITE_REGISTER_COMMAND0_COMMANDSET(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_WRITE_REGISTER_COMMAND0_COMMANDSET_SHIFT)) & FLEXSPI_SLV_WRITE_REGISTER_COMMAND0_COMMANDSET_MASK)
/*! @} */

/*! @name WRITE_COMMAND - Write Command 1 Setting..Write Command 2 Setting */
/*! @{ */

#define FLEXSPI_SLV_WRITE_COMMAND_COMMANDSET_MASK (0xFFFF0000U)
#define FLEXSPI_SLV_WRITE_COMMAND_COMMANDSET_SHIFT (16U)
/*! COMMANDSET - Write Command 2 Setting */
#define FLEXSPI_SLV_WRITE_COMMAND_COMMANDSET(x)  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_WRITE_COMMAND_COMMANDSET_SHIFT)) & FLEXSPI_SLV_WRITE_COMMAND_COMMANDSET_MASK)
/*! @} */

/*! @name RW_COMMAND_BASE - Read Write Command Address Base */
/*! @{ */

#define FLEXSPI_SLV_RW_COMMAND_BASE_ADDRBASE1_MASK (0xFFFFU)
#define FLEXSPI_SLV_RW_COMMAND_BASE_ADDRBASE1_SHIFT (0U)
/*! ADDRBASE1 - Address Base 1 */
#define FLEXSPI_SLV_RW_COMMAND_BASE_ADDRBASE1(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_RW_COMMAND_BASE_ADDRBASE1_SHIFT)) & FLEXSPI_SLV_RW_COMMAND_BASE_ADDRBASE1_MASK)

#define FLEXSPI_SLV_RW_COMMAND_BASE_ADDRBASE2_MASK (0xFFFF0000U)
#define FLEXSPI_SLV_RW_COMMAND_BASE_ADDRBASE2_SHIFT (16U)
/*! ADDRBASE2 - Address Base 2 */
#define FLEXSPI_SLV_RW_COMMAND_BASE_ADDRBASE2(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_RW_COMMAND_BASE_ADDRBASE2_SHIFT)) & FLEXSPI_SLV_RW_COMMAND_BASE_ADDRBASE2_MASK)
/*! @} */

/*! @name CMD_RANGE - Command Suit 1 Range..Command Suit 2 Range */
/*! @{ */

#define FLEXSPI_SLV_CMD_RANGE_RANGE_MASK         (0xFFFFFC00U)
#define FLEXSPI_SLV_CMD_RANGE_RANGE_SHIFT        (10U)
/*! RANGE - Memory Range */
#define FLEXSPI_SLV_CMD_RANGE_RANGE(x)           (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_CMD_RANGE_RANGE_SHIFT)) & FLEXSPI_SLV_CMD_RANGE_RANGE_MASK)
/*! @} */

/*! @name MODULE_STATUS - Module Status */
/*! @{ */

#define FLEXSPI_SLV_MODULE_STATUS_WIP_MASK       (0x1U)
#define FLEXSPI_SLV_MODULE_STATUS_WIP_SHIFT      (0U)
/*! WIP - Write in Progress
 *  0b0..Not busy
 *  0b1..Busy
 */
#define FLEXSPI_SLV_MODULE_STATUS_WIP(x)         (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_STATUS_WIP_SHIFT)) & FLEXSPI_SLV_MODULE_STATUS_WIP_MASK)

#define FLEXSPI_SLV_MODULE_STATUS_AXIREADIDLE_MASK (0x2U)
#define FLEXSPI_SLV_MODULE_STATUS_AXIREADIDLE_SHIFT (1U)
/*! AXIREADIDLE - AXI Read Leader Idle
 *  0b0..Busy
 *  0b1..Idle
 */
#define FLEXSPI_SLV_MODULE_STATUS_AXIREADIDLE(x) (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_STATUS_AXIREADIDLE_SHIFT)) & FLEXSPI_SLV_MODULE_STATUS_AXIREADIDLE_MASK)

#define FLEXSPI_SLV_MODULE_STATUS_REGRWIDLE_MASK (0x4U)
#define FLEXSPI_SLV_MODULE_STATUS_REGRWIDLE_SHIFT (2U)
/*! REGRWIDLE - Register Read Write Idle
 *  0b0..Busy
 *  0b1..Idle
 */
#define FLEXSPI_SLV_MODULE_STATUS_REGRWIDLE(x)   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_STATUS_REGRWIDLE_SHIFT)) & FLEXSPI_SLV_MODULE_STATUS_REGRWIDLE_MASK)

#define FLEXSPI_SLV_MODULE_STATUS_SEQIDLE_MASK   (0x8U)
#define FLEXSPI_SLV_MODULE_STATUS_SEQIDLE_SHIFT  (3U)
/*! SEQIDLE - SEQ Controller Idle
 *  0b0..Busy
 *  0b1..Idle
 */
#define FLEXSPI_SLV_MODULE_STATUS_SEQIDLE(x)     (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_STATUS_SEQIDLE_SHIFT)) & FLEXSPI_SLV_MODULE_STATUS_SEQIDLE_MASK)

#define FLEXSPI_SLV_MODULE_STATUS_RDOFR_MASK     (0xF0U)
#define FLEXSPI_SLV_MODULE_STATUS_RDOFR_SHIFT    (4U)
/*! RDOFR - Read Out-of-Range Counter */
#define FLEXSPI_SLV_MODULE_STATUS_RDOFR(x)       (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_STATUS_RDOFR_SHIFT)) & FLEXSPI_SLV_MODULE_STATUS_RDOFR_MASK)

#define FLEXSPI_SLV_MODULE_STATUS_WROFR_MASK     (0xF00U)
#define FLEXSPI_SLV_MODULE_STATUS_WROFR_SHIFT    (8U)
/*! WROFR - Write Out-of-Range Counter */
#define FLEXSPI_SLV_MODULE_STATUS_WROFR(x)       (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_STATUS_WROFR_SHIFT)) & FLEXSPI_SLV_MODULE_STATUS_WROFR_MASK)

#define FLEXSPI_SLV_MODULE_STATUS_ALLOWAXIRD_MASK (0x1000U)
#define FLEXSPI_SLV_MODULE_STATUS_ALLOWAXIRD_SHIFT (12U)
/*! ALLOWAXIRD - Allow AXI Read Access
 *  0b0..Denied
 *  0b1..Allowed
 */
#define FLEXSPI_SLV_MODULE_STATUS_ALLOWAXIRD(x)  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_STATUS_ALLOWAXIRD_SHIFT)) & FLEXSPI_SLV_MODULE_STATUS_ALLOWAXIRD_MASK)

#define FLEXSPI_SLV_MODULE_STATUS_ALLOWAXIWR_MASK (0x2000U)
#define FLEXSPI_SLV_MODULE_STATUS_ALLOWAXIWR_SHIFT (13U)
/*! ALLOWAXIWR - Allow AXI Write Access
 *  0b0..Denied
 *  0b1..Allowed
 */
#define FLEXSPI_SLV_MODULE_STATUS_ALLOWAXIWR(x)  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_STATUS_ALLOWAXIWR_SHIFT)) & FLEXSPI_SLV_MODULE_STATUS_ALLOWAXIWR_MASK)
/*! @} */

/*! @name MODULE_INT - SPI FLR interrupt */
/*! @{ */

#define FLEXSPI_SLV_MODULE_INT_WOF_MASK          (0x1U)
#define FLEXSPI_SLV_MODULE_INT_WOF_SHIFT         (0U)
/*! WOF - Write Overflow Interrupt
 *  0b0..Did not occur
 *  0b1..Occurred
 */
#define FLEXSPI_SLV_MODULE_INT_WOF(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_INT_WOF_SHIFT)) & FLEXSPI_SLV_MODULE_INT_WOF_MASK)

#define FLEXSPI_SLV_MODULE_INT_RUF_MASK          (0x2U)
#define FLEXSPI_SLV_MODULE_INT_RUF_SHIFT         (1U)
/*! RUF - Read Underflow
 *  0b0..Did not occur
 *  0b1..Occurred
 */
#define FLEXSPI_SLV_MODULE_INT_RUF(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_INT_RUF_SHIFT)) & FLEXSPI_SLV_MODULE_INT_RUF_MASK)

#define FLEXSPI_SLV_MODULE_INT_ERRCMD_MASK       (0x4U)
#define FLEXSPI_SLV_MODULE_INT_ERRCMD_SHIFT      (2U)
/*! ERRCMD - Error Command
 *  0b0..Not received
 *  0b1..Received
 */
#define FLEXSPI_SLV_MODULE_INT_ERRCMD(x)         (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_INT_ERRCMD_SHIFT)) & FLEXSPI_SLV_MODULE_INT_ERRCMD_MASK)
/*! @} */

/*! @name MODULE_INTEN - SPI FLR Interrupt Enable */
/*! @{ */

#define FLEXSPI_SLV_MODULE_INTEN_WOFEN_MASK      (0x1U)
#define FLEXSPI_SLV_MODULE_INTEN_WOFEN_SHIFT     (0U)
/*! WOFEN - Write Overflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_SLV_MODULE_INTEN_WOFEN(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_INTEN_WOFEN_SHIFT)) & FLEXSPI_SLV_MODULE_INTEN_WOFEN_MASK)

#define FLEXSPI_SLV_MODULE_INTEN_RUFEN_MASK      (0x2U)
#define FLEXSPI_SLV_MODULE_INTEN_RUFEN_SHIFT     (1U)
/*! RUFEN - Read Underflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_SLV_MODULE_INTEN_RUFEN(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_INTEN_RUFEN_SHIFT)) & FLEXSPI_SLV_MODULE_INTEN_RUFEN_MASK)

#define FLEXSPI_SLV_MODULE_INTEN_ERRCMDEN_MASK   (0x4U)
#define FLEXSPI_SLV_MODULE_INTEN_ERRCMDEN_SHIFT  (2U)
/*! ERRCMDEN - Error Command Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_SLV_MODULE_INTEN_ERRCMDEN(x)     (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_MODULE_INTEN_ERRCMDEN_SHIFT)) & FLEXSPI_SLV_MODULE_INTEN_ERRCMDEN_MASK)
/*! @} */

/*! @name SPI_MAIL_CTRL - SPI Mailbox control */
/*! @{ */

#define FLEXSPI_SLV_SPI_MAIL_CTRL_CLRINT_MASK    (0x1U)
#define FLEXSPI_SLV_SPI_MAIL_CTRL_CLRINT_SHIFT   (0U)
/*! CLRINT - Clear Interrupt
 *  0b0..Do not clear
 *  0b1..Clear
 */
#define FLEXSPI_SLV_SPI_MAIL_CTRL_CLRINT(x)      (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_SPI_MAIL_CTRL_CLRINT_SHIFT)) & FLEXSPI_SLV_SPI_MAIL_CTRL_CLRINT_MASK)

#define FLEXSPI_SLV_SPI_MAIL_CTRL_SPIINTEN_MASK  (0x2U)
#define FLEXSPI_SLV_SPI_MAIL_CTRL_SPIINTEN_SHIFT (1U)
/*! SPIINTEN - SPI Leader Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLEXSPI_SLV_SPI_MAIL_CTRL_SPIINTEN(x)    (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_SPI_MAIL_CTRL_SPIINTEN_SHIFT)) & FLEXSPI_SLV_SPI_MAIL_CTRL_SPIINTEN_MASK)
/*! @} */

/*! @name SPIMAIL - SPI Mail Interrupt */
/*! @{ */

#define FLEXSPI_SLV_SPIMAIL_MAILn_MASK           (0xFFFFFFFFU)
#define FLEXSPI_SLV_SPIMAIL_MAILn_SHIFT          (0U)
#define FLEXSPI_SLV_SPIMAIL_MAILn(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_SLV_SPIMAIL_MAILn_SHIFT)) & FLEXSPI_SLV_SPIMAIL_MAILn_MASK)
/*! @} */

/* The count of FLEXSPI_SLV_SPIMAIL */
#define FLEXSPI_SLV_SPIMAIL_COUNT                (9U)


/*!
 * @}
 */ /* end of group FLEXSPI_SLV_Register_Masks */


/*!
 * @}
 */ /* end of group FLEXSPI_SLV_Peripheral_Access_Layer */


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


#endif  /* PERI_FLEXSPI_SLV_H_ */

