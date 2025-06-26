/** @file mlan_sdio_defs.h
 *
 *  @brief This file contains definitions for SDIO interface.
 *
 *  Copyright 2022-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */
/****************************************************
Change log:
****************************************************/

#ifndef _MLAN_SDIO_DEFS_H
#define _MLAN_SDIO_DEFS_H

#include <wifi_config_default.h>

/** Block mode */
#define BLOCK_MODE 1
/** Fixed address mode */
#define FIXED_ADDRESS 0

/* Host Control Registers */
/** Host Control Registers : Host to Card Event */
#define HOST_TO_CARD_EVENT_REG 0x00
/** Host Control Registers : Host terminates Command 53 */
#define HOST_TERM_CMD53 (0x1U << 2)
/** Host Control Registers : Host without Command 53 finish host */
#define HOST_WO_CMD53_FINISH_HOST (0x1U << 2)
/** Host Control Registers : Host power up */
#define HOST_POWER_UP (0x1U << 1)
/** Host Control Registers : Host power down */
#define HOST_POWER_DOWN (0x1U << 0)

#if defined(SD8801)
/** Host Control Registers : Host interrupt RSR */
#define HOST_INT_RSR_REG  0x01
#define HOST_INT_RSR_MASK 0x3F
/** Host Control Registers : Host interrupt mask */
#define HOST_INT_MASK_REG 0x02
#elif defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177) || defined(IW610)
/** Host Control Registers : Host interrupt RSR */
#define HOST_INT_RSR_REG  0x04
#define HOST_INT_RSR_MASK 0xFF
/** Host Control Registers : Host interrupt mask */
#define HOST_INT_MASK_REG 0x08
#endif

/** Host Control Registers : Upload host interrupt RSR */
#define UP_LD_HOST_INT_RSR (0x1U)
/** Host Control Registers : Upload host interrupt mask */
#define UP_LD_HOST_INT_MASK (0x1U)
/** Host Control Registers : Download host interrupt mask */
#define DN_LD_HOST_INT_MASK (0x2U)

#if defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177) || defined(IW610)
/** Host Control Registers : Cmd port upload interrupt mask */
#define CMD_PORT_UPLD_INT_MASK (0x1U << 6)
/** Host Control Registers : Cmd port download interrupt mask */
#define CMD_PORT_DNLD_INT_MASK (0x1U << 7)
/** Enable Host interrupt mask */
#define HIM_ENABLE (UP_LD_HOST_INT_MASK | DN_LD_HOST_INT_MASK | CMD_PORT_UPLD_INT_MASK | CMD_PORT_DNLD_INT_MASK)
#elif defined(SD8801)
/** Enable Host interrupt mask */
#define HIM_ENABLE (UP_LD_HOST_INT_MASK | DN_LD_HOST_INT_MASK)
#endif

/** Disable Host interrupt mask */
#define HIM_DISABLE 0xff

#if defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177) || defined(IW610)
/** Host Control Registers : Host interrupt status */
#define HOST_INT_STATUS_REG 0x0C
/** Host Control Registers : Upload command port host interrupt status */
#define UP_LD_CMD_PORT_HOST_INT_STATUS (0x40U)
/** Host Control Registers : Download command port host interrupt status */
#define DN_LD_CMD_PORT_HOST_INT_STATUS (0x80U)
#elif defined(SD8801)
#define HOST_INT_STATUS_REG 0x03
#endif

/** Host Control Registers : Upload host interrupt status */
#define UP_LD_HOST_INT_STATUS (0x1U)
/** Host Control Registers : Download host interrupt status */
#define DN_LD_HOST_INT_STATUS (0x2U)

#define WLAN_VALUE1 0x80002080U
/** Port for registers */
#define REG_PORT 0U

#if defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177) || defined(IW610)
/** Port for memory */
#define MEM_PORT 0x10000
/** LSB of read bitmap */
#define RD_BITMAP_L 0x10
/** MSB of read bitmap */
#define RD_BITMAP_U 0x11
/** LSB of read bitmap second word */
#define RD_BITMAP_1L 0x12
/** MSB of read bitmap second word */
#define RD_BITMAP_1U 0x13
/** LSB of write bitmap */
#define WR_BITMAP_L 0x14
/** MSB of write bitmap */
#define WR_BITMAP_U 0x15
/** LSB of write bitmap second word */
#define WR_BITMAP_1L 0x16
/** MSB of write bitmap second word */
#define WR_BITMAP_1U 0x17
/** LSB of read length for port 0 */
#define RD_LEN_P0_L 0x18
/** MSB of read length for port 0 */
#define RD_LEN_P0_U 0x19
#elif defined(SD8801)
/** LSB of read bitmap */
#define RD_BITMAP_L 0x04
/** MSB of read bitmap */
#define RD_BITMAP_U 0x05
/** LSB of write bitmap */
#define WR_BITMAP_L 0x06
/** MSB of write bitmap */
#define WR_BITMAP_U 0x07
/** LSB of read length for port 0 */
#define RD_LEN_P0_L 0x08
/** MSB of read length for port 0 */
#define RD_LEN_P0_U 0x09
#endif

#if defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177) || defined(IW610)
/* Card Control Registers : Command port read length 0 */
#define CMD_RD_LEN_0 0xC0
/* Card Control Registers : Command port read length 1 */
#define CMD_RD_LEN_1 0xC1
/* Card Control Registers : Command port read length 2 (reserved)  */
#define CMD_RD_LEN_2 0xC2
/* Card Control Registers : Command port read length 3  */
#define CMD_RD_LEN_3 0xC3
/* Card Control Registers : Command port configuration 0 */
#define CMD_CONFIG_0       0xC4
#define CMD_PORT_RD_LEN_EN (0x1U << 2)
/* Card Control Registers : Command port configuration 1 */
#define CMD_CONFIG_1 0xC5
/* Card Control Registers : cmd port auto enable */
#define CMD_PORT_AUTO_EN (0x1U << 0)
/* Card Control Registers : Command port configuration 2 (reserved) */
#define CMD_CONFIG_2 0xC6
/* Card Control Registers : Command port configuration 3 (reserved) */
#define CMD_CONFIG_3 0xC7

/* Command port */
#define CMD_PORT_SLCT 0x8000U
/** Data port mask */
#define DATA_PORT_MASK 0xffffffffU
#endif /* SD8987 SD8997 SD9097 SD9098 SD9177 IW610*/

#if defined(SD8801)
/** Ctrl port */
#define CTRL_PORT 0
/** Ctrl port mask */
#define CTRL_PORT_MASK 0x0001
/** Data port mask */
#define DATA_PORT_MASK 0xfffe
#endif /* SD8801 */
/** Ctrl port mask */
// #define CTRL_PORT_MASK			0x00000001
/** Data port mask */
// #define DATA_PORT_MASK			0xfffffffe
/** Misc. Config Register : Auto Re-enable interrupts */
#define AUTO_RE_ENABLE_INT (0x1U << 4)

#if defined(SD8801)
/** Host Control Registers : Host transfer status */
#define HOST_RESTART_REG 0x28
#elif defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177) || defined(IW610)
/** Host Control Registers : Host transfer status */
#define HOST_RESTART_REG 0x58
#endif

/** Host Control Registers : Download CRC error */
#define DN_LD_CRC_ERR (0x1U << 2)
/** Host Control Registers : Upload restart */
#define UP_LD_RESTART (0x1U << 1)
/** Host Control Registers : Download restart */
#define DN_LD_RESTART (0x1U << 0)

/* Card Control Registers */
#if defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177) || defined(IW610)
/** Card Control Registers : Card to host event */
#define CARD_TO_HOST_EVENT_REG 0x5C
/** Card Control Registers : Command port upload ready */
#define UP_LD_CP_RDY (0x1U << 6)
/** Card Control Registers : Command port download ready */
#define DN_LD_CP_RDY (0x1U << 7)
#endif /* SD8987 SD8997 SD9097 SD9098 IW610*/

#if defined(SD8801)
/** Card Control Registers : Card to host event */
#define CARD_TO_HOST_EVENT_REG 0x30
#endif /* SD8801 */

/** Card Control Registers : Card I/O ready */
#define CARD_IO_READY (0x1U << 3)
/** Card Control Registers : CIS card ready */
#define CIS_CARD_RDY (0x1U << 2)
/** Card Control Registers : Upload card ready */
#define UP_LD_CARD_RDY (0x1U << 1)
/** Card Control Registers : Download card ready */
#define DN_LD_CARD_RDY (0x1U << 0)

#if defined(SD8801)
/** Card Control Registers : Host interrupt mask register */
#define HOST_INTERRUPT_MASK_REG 0x34
#elif defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177) || defined(IW610)
/** Card Control Registers : Host interrupt mask register */
#define HOST_INTERRUPT_MASK_REG 0x60
#endif

/** Card Control Registers : Host power interrupt mask */
#define HOST_POWER_INT_MASK (0x1U << 3)
/** Card Control Registers : Abort card interrupt mask */
#define ABORT_CARD_INT_MASK (0x1U << 2)
/** Card Control Registers : Upload card interrupt mask */
#define UP_LD_CARD_INT_MASK (0x1U << 1)
/** Card Control Registers : Download card interrupt mask */
#define DN_LD_CARD_INT_MASK (0x1U << 0)

#if defined(SD8801)
/** Card Control Registers : Card interrupt status register */
#define CARD_INTERRUPT_STATUS_REG 0x38
#elif defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177) || defined(IW610)
/** Card Control Registers : Card interrupt status register */
#define CARD_INTERRUPT_STATUS_REG 0x64
#endif

/** Card Control Registers : Power up interrupt */
#define POWER_UP_INT (0x1U << 4)
/** Card Control Registers : Power down interrupt */
#define POWER_DOWN_INT (0x1U << 3)

#if defined(SD8801)
/** Card Control Registers : Card interrupt RSR register */
#define CARD_INTERRUPT_RSR_REG 0x3c
#elif defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177) || defined(IW610)
/** Card Control Registers : Card interrupt RSR register */
#define CARD_INTERRUPT_RSR_REG 0x68
#endif

/** Card Control Registers : Power up RSR */
#define POWER_UP_RSR (0x1U << 4)
/** Card Control Registers : Power down RSR */
#define POWER_DOWN_RSR (0x1U << 3)

#if defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177) || defined(IW610)
/** Card Control Registers : SQ Read base address 0 register */
#define READ_BASE_0_REG 0xf8
/** Card Control Registers : SQ Read base address 1 register */
#define READ_BASE_1_REG 0xf9
/** Enable GPIO-1 as a duplicated signal of interrupt as appear of SDIO_DAT1*/
#define ENABLE_GPIO_1_INT_MODE 0x88
/** Scratch reg 3 2  :     Configure GPIO-1 INT*/
#define SCRATCH_REG_32 0xEE
#elif defined(SD8801)
/** Card Control Registers : SQ Read base address 0 register */
#define READ_BASE_0_REG 0x40
/** Card Control Registers : SQ Read base address 1 register */
#define READ_BASE_1_REG 0x41
#endif

#if defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177) || defined(IW610)
/** Card Control Registers : Card revision register */
#define CARD_REVISION_REG 0xC8

/** Firmware status 0 register (SCRATCH0_0) */
#define CARD_FW_STATUS0_REG 0xe8
/** Firmware status 1 register (SCRATCH0_1) */
#define CARD_FW_STATUS1_REG 0xe9
/** Rx length register (SCRATCH0_2) */
#define CARD_RX_LEN_REG 0xea
/** Rx unit register (SCRATCH0_3) */
#define CARD_RX_UNIT_REG 0xeb

#if (CONFIG_WIFI_IND_DNLD)
#if defined(SD8978) || defined(SD8987) || defined(SD9177) || defined(IW610)
/** Firmware reset register */
#define CARD_FW_RESET_REG 0xEE
/** Firmware reset val */
#define CARD_FW_RESET_VAL 0x99
#endif
#endif

/** Card Control Registers : Card OCR 0 register */
#define CARD_OCR_0_REG 0xD4
/** Card Control Registers : Card OCR 1 register */
#define CARD_OCR_1_REG 0xD5
/** Card Control Registers : Card OCR 3 register */
#define CARD_OCR_3_REG 0xD6
/** Card Control Registers : Card config register */
#define CARD_CONFIG_REG 0xD7
/** Card Control Registers : Miscellaneous Configuration Register */
#define CARD_MISC_CFG_REG 0xD8

/** Card Control Registers : sdio new mode register 1 */
#define CARD_CONFIG_2_1_REG 0xD9
/** Card Control Registers : cmd53 new mode */
#define CMD53_NEW_MODE (0x1U << 0)
/** Card Control Registers : cmd53 tx len format 1 (0x10) */
#define CMD53_TX_LEN_FORMAT_1 (0x1U << 4)
/** Card Control Registers : cmd53 tx len format 2 (0x20)*/
#define CMD53_TX_LEN_FORMAT_2 (0x1U << 5)
/** Card Control Registers : cmd53 rx len format 1 (0x40) */
#define CMD53_RX_LEN_FORMAT_1 (0x1U << 6)
/** Card Control Registers : cmd53 rx len format 2 (0x80)*/
#define CMD53_RX_LEN_FORMAT_2 (0x1U << 7)

/** Card Control Registers : sdio new mode register 2 */
#define CARD_CONFIG_2_2_REG 0xDA
/** Card Control Registers : test data out (0x01) */
#define TEST_DATA_OUT_1 (0x1U << 0)
/** Card Control Registers : test data out (0x02) */
#define TEST_DATA_OUT_2 (0x1U << 1)
/** Card Control Registers : test data out (0x04) */
#define TEST_DATA_OUT_3 (0x1U << 2)
/** Card Control Registers : test data out (0x08) */
#define TEST_DATA_OUT_4 (0x1U << 3)
/** Card Control Registers : test cmd out (0x10) */
#define TEST_CMD_OUT (0x1U << 4)

/** Card Control Registers : sdio new mode register 3 */
#define CARD_CONFIG_2_3_REG 0xDB
/** Card Control Registers : test data enable (0x01) */
#define TEST_DATA_EN_1 (0x1U << 0)
/** Card Control Registers : test data enable (0x02) */
#define TEST_DATA_EN_2 (0x1U << 1)
/** Card Control Registers : test data enable (0x04) */
#define TEST_DATA_EN_3 (0x1U << 2)
/** Card Control Registers : test data enable (0x08) */
#define TEST_DATA_EN_4 (0x1U << 3)
/** Card Control Registers : test cmd enable (0x10) */
#define TEST_CMD_EN (0x1U << 4)
/** Card Control Registers : test mode (0x20) */
#define TEST_MODE (0x1U << 5)
#elif defined(SD8801)
/** Card Control Registers : Card revision register */
#define CARD_REVISION_REG   0x5c

/** Firmware status 0 register (SCRATCH0_0) */
#define CARD_FW_STATUS0_REG 0x60
/** Firmware status 1 register (SCRATCH0_1) */
#define CARD_FW_STATUS1_REG 0x61
/** Rx length register (SCRATCH0_2) */
#define CARD_RX_LEN_REG     0x62
/** Rx unit register (SCRATCH0_3) */
#define CARD_RX_UNIT_REG    0x63

#if (CONFIG_WIFI_IND_DNLD)
/** Firmware reset register */
#define CARD_FW_RESET_REG 0x64
/** Firmware reset register */
#define CARD_FW_RESET_VAL 0x00
#endif

/** Card Control Registers : Card OCR 0 register */
#define CARD_OCR_0_REG    0x68
/** Card Control Registers : Card OCR 1 register */
#define CARD_OCR_1_REG    0x69
/** Card Control Registers : Card OCR 3 register */
#define CARD_OCR_3_REG    0x6A
/** Card Control Registers : Card config register */
#define CARD_CONFIG_REG   0x6B
/** Card Control Registers : Miscellaneous Configuration Register */
#define CARD_MISC_CFG_REG 0x6C
#endif

#if defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177) || defined(IW610)
/** Card Control Registers : Debug 0 register */
#define DEBUG_0_REG 0xDC
/** Card Control Registers : SD test BUS 0 */
#define SD_TESTBUS0 (0x1U)
/** Card Control Registers : Debug 1 register */
#define DEBUG_1_REG 0xDD
/** Card Control Registers : SD test BUS 1 */
#define SD_TESTBUS1 (0x1U)
/** Card Control Registers : Debug 2 register */
#define DEBUG_2_REG 0xDE
/** Card Control Registers : SD test BUS 2 */
#define SD_TESTBUS2 (0x1U)
/** Card Control Registers : Debug 3 register */
#define DEBUG_3_REG 0xDF
/** Card Control Registers : SD test BUS 3 */
#define SD_TESTBUS3 (0x1U)

/** Host Control Registers : I/O port 0 */
#define IO_PORT_0_REG 0xE4
/** Host Control Registers : I/O port 1 */
#define IO_PORT_1_REG 0xE5
/** Host Control Registers : I/O port 2 */
#define IO_PORT_2_REG 0xE6
#elif defined(SD8801)
/** Card Control Registers : Debug 0 register */
#define DEBUG_0_REG   0x70
/** Card Control Registers : SD test BUS 0 */
#define SD_TESTBUS0   (0x1U)
/** Card Control Registers : Debug 1 register */
#define DEBUG_1_REG   0x71
/** Card Control Registers : SD test BUS 1 */
#define SD_TESTBUS1   (0x1U)
/** Card Control Registers : Debug 2 register */
#define DEBUG_2_REG   0x72
/** Card Control Registers : SD test BUS 2 */
#define SD_TESTBUS2   (0x1U)
/** Card Control Registers : Debug 3 register */
#define DEBUG_3_REG   0x73
/** Card Control Registers : SD test BUS 3 */
#define SD_TESTBUS3   (0x1U)

/** Host Control Registers : I/O port 0 */
#define IO_PORT_0_REG 0x78
/** Host Control Registers : I/O port 1 */
#define IO_PORT_1_REG 0x79
/** Host Control Registers : I/O port 2 */
#define IO_PORT_2_REG 0x7A
#endif

#endif /* _MLAN_SDIO_DEFS_H */
