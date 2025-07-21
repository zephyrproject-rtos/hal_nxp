/*
** ###################################################################
**     Version:             rev. 1.0, 2025-02-21
**     Build:               b250610
**
**     Abstract:
**         Chip specific module features.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-02-21)
**         Generated based on Rev1 Draft RM.
**
** ###################################################################
*/

#ifndef _MCXE245_FEATURES_H_
#define _MCXE245_FEATURES_H_

/* SOC module features */

/* @brief ACMP availability on the SoC. */
#define FSL_FEATURE_SOC_ACMP_COUNT (1)
/* @brief ADC12 availability on the SoC. */
#define FSL_FEATURE_SOC_ADC12_COUNT (2)
/* @brief AIPS availability on the SoC. */
#define FSL_FEATURE_SOC_AIPS_COUNT (1)
/* @brief AXBS availability on the SoC. */
#define FSL_FEATURE_SOC_AXBS_COUNT (1)
/* @brief CRC availability on the SoC. */
#define FSL_FEATURE_SOC_CRC_COUNT (1)
/* @brief DMAMUX availability on the SoC. */
#define FSL_FEATURE_SOC_DMAMUX_COUNT (1)
/* @brief EDMA availability on the SoC. */
#define FSL_FEATURE_SOC_EDMA_COUNT (1)
/* @brief EIM availability on the SoC. */
#define FSL_FEATURE_SOC_EIM_COUNT (1)
/* @brief ELA_CSEC availability on the SoC. */
#define FSL_FEATURE_SOC_ELA_CSEC_COUNT (1)
/* @brief EWM availability on the SoC. */
#define FSL_FEATURE_SOC_EWM_COUNT (1)
/* @brief FLASH availability on the SoC. */
#define FSL_FEATURE_SOC_FLASH_COUNT (1)
/* @brief FLEXCAN availability on the SoC. */
#define FSL_FEATURE_SOC_FLEXCAN_COUNT (3)
/* @brief FLEXIO availability on the SoC. */
#define FSL_FEATURE_SOC_FLEXIO_COUNT (1)
/* @brief FTM availability on the SoC. */
#define FSL_FEATURE_SOC_FTM_COUNT (4)
/* @brief GPIO availability on the SoC. */
#define FSL_FEATURE_SOC_GPIO_COUNT (5)
/* @brief LMEM availability on the SoC. */
#define FSL_FEATURE_SOC_LMEM_COUNT (1)
/* @brief LPI2C availability on the SoC. */
#define FSL_FEATURE_SOC_LPI2C_COUNT (1)
/* @brief LPIT availability on the SoC. */
#define FSL_FEATURE_SOC_LPIT_COUNT (1)
/* @brief LPSPI availability on the SoC. */
#define FSL_FEATURE_SOC_LPSPI_COUNT (3)
/* @brief LPTMR availability on the SoC. */
#define FSL_FEATURE_SOC_LPTMR_COUNT (1)
/* @brief LPUART availability on the SoC. */
#define FSL_FEATURE_SOC_LPUART_COUNT (3)
/* @brief MCM availability on the SoC. */
#define FSL_FEATURE_SOC_MCM_COUNT (1)
/* @brief MSCM availability on the SoC. */
#define FSL_FEATURE_SOC_MSCM_COUNT (1)
/* @brief PCC availability on the SoC. */
#define FSL_FEATURE_SOC_PCC_COUNT (1)
/* @brief PDB availability on the SoC. */
#define FSL_FEATURE_SOC_PDB_COUNT (2)
/* @brief PMC availability on the SoC. */
#define FSL_FEATURE_SOC_PMC_COUNT (1)
/* @brief PORT availability on the SoC. */
#define FSL_FEATURE_SOC_PORT_COUNT (5)
/* @brief RCM availability on the SoC. */
#define FSL_FEATURE_SOC_RCM_COUNT (1)
/* @brief RTC availability on the SoC. */
#define FSL_FEATURE_SOC_RTC_COUNT (1)
/* @brief SCG availability on the SoC. */
#define FSL_FEATURE_SOC_SCG_COUNT (1)
/* @brief SIM availability on the SoC. */
#define FSL_FEATURE_SOC_SIM_COUNT (1)
/* @brief SMC availability on the SoC. */
#define FSL_FEATURE_SOC_SMC_COUNT (1)
/* @brief TRGMUX availability on the SoC. */
#define FSL_FEATURE_SOC_TRGMUX_COUNT (1)
/* @brief WDOG availability on the SoC. */
#define FSL_FEATURE_SOC_WDOG_COUNT (1)
/* @brief CMP availability on the SoC. */
#define FSL_FEATURE_SOC_CMP_COUNT (1)

/* ADC12 module features */

/* @brief Has DMA support (bit SC2[DMAEN]. */
#define FSL_FEATURE_ADC12_HAS_DMA_SUPPORT (1)
/* @brief Conversion control count (related to number of registers SC1n and Rn). */
#define FSL_FEATURE_ADC12_CONVERSION_CONTROL_COUNT (16)

/* FLEXCAN module features */

/* @brief Message buffer size */
#define FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(x) \
    (((x) == CAN0) ? (32) : \
    (((x) == CAN1) ? (16) : \
    (((x) == CAN2) ? (16) : (-1))))
/* @brief Has doze mode support (register bit field MCR[DOZE]). */
#define FSL_FEATURE_FLEXCAN_HAS_DOZE_MODE_SUPPORT (0)
/* @brief Insatnce has doze mode support (register bit field MCR[DOZE]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_DOZE_MODE_SUPPORTn(x) (0)
/* @brief Has a glitch filter on the receive pin (register bit field MCR[WAKSRC]). */
#define FSL_FEATURE_FLEXCAN_HAS_GLITCH_FILTER (0)
/* @brief Has extended interrupt mask and flag register (register IMASK2, IFLAG2). */
#define FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER (0)
/* @brief Instance has extended bit timing register (register CBT). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_EXTENDED_TIMING_REGISTERn(x) (1)
/* @brief Has a receive FIFO DMA feature (register bit field MCR[DMA]). */
#define FSL_FEATURE_FLEXCAN_HAS_RX_FIFO_DMA (1)
/* @brief Instance has a receive FIFO DMA feature (register bit field MCR[DMA]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_RX_FIFO_DMAn(x) (1)
/* @brief Remove CAN Engine Clock Source Selection from unsupported part. */
#define FSL_FEATURE_FLEXCAN_SUPPORT_ENGINE_CLK_SEL_REMOVE (0)
/* @brief Instance remove CAN Engine Clock Source Selection from unsupported part. */
#define FSL_FEATURE_FLEXCAN_INSTANCE_SUPPORT_ENGINE_CLK_SEL_REMOVEn(x) (0)
/* @brief Is affected by errata with ID 5641 (Module does not transmit a message that is enabled to be transmitted at a specific moment during the arbitration process). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641 (0)
/* @brief Is affected by errata with ID 5829 (FlexCAN: FlexCAN does not transmit a message that is enabled to be transmitted in a specific moment during the arbitration process). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829 (0)
/* @brief Is affected by errata with ID 6032 (FlexCAN: A frame with wrong ID or payload is transmitted into the CAN bus when the Message Buffer under transmission is either aborted or deactivated while the CAN bus is in the Bus Idle state). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_6032 (0)
/* @brief Is affected by errata with ID 9595 (FlexCAN: Corrupt frame possible if the Freeze Mode or the Low-Power Mode are entered during a Bus-Off state). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_9595 (0)
/* @brief Has CAN with Flexible Data rate (CAN FD) protocol. */
#define FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE (1)
/* @brief CAN instance support Flexible Data rate (CAN FD) protocol. */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_FLEXIBLE_DATA_RATEn(x) \
    (((x) == CAN0) ? (1) : \
    (((x) == CAN1) ? (0) : \
    (((x) == CAN2) ? (0) : (-1))))
/* @brief Has memory error control (register MECR). */
#define FSL_FEATURE_FLEXCAN_HAS_MEMORY_ERROR_CONTROL (0)
/* @brief Has enhanced bit timing register (register EPRS, ENCBT, EDCBT and ETDC). */
#define FSL_FEATURE_FLEXCAN_HAS_ENHANCED_BIT_TIMING_REG (0)
/* @brief Has Pretended Networking mode support. */
#define FSL_FEATURE_FLEXCAN_HAS_PN_MODE (1)
/* @brief Has Enhanced Rx FIFO. */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_ENHANCED_RX_FIFOn(x) (0)
/* @brief Does not support Supervisor Mode (bitfield MCR[SUPV]. */
#define FSL_FEATURE_FLEXCAN_HAS_NO_SUPV_SUPPORT (0)
/* @brief Has more than 64 MBs. */
#define FSL_FEATURE_FLEXCAN_HAS_MORE_THAN_64_MB (0)
/* @brief Does not support self wake feature(bitfield MCR[SLFWAK]) */
#define FSL_FEATURE_FLEXCAN_HAS_NO_SLFWAK_SUPPORT (1)
/* @brief Has external time tick source (bitfield CTRL2[TIMER_SRC]). */
#define FSL_FEATURE_FLEXCAN_HAS_EXTERNAL_TIME_TICK (1)
/* @brief Instance has external time tick source (register bit field CTRL2[TIMER_SRC]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_EXTERNAL_TIME_TICKn(x) \
    (((x) == CAN0) ? (1) : \
    (((x) == CAN1) ? (0) : \
    (((x) == CAN2) ? (0) : (-1))))
/* @brief Has Time Stamp Capture Point(bitfield CTRL2[TSTAMPCAP]). */
#define FSL_FEATURE_FLEXCAN_HAS_HIGH_RESOLUTION_TIMESTAMP (0)
/* @brief The max amount of Message Buffer IRQ entry for CAN instances. */
#define FSL_FEATURE_FLEXCAN_MB_IRQ_COUNT (2)
/* @brief Instance has Pretended Networking option (register bit field MCR[PNET_EN]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_PN_MODEn(x) \
    (((x) == CAN0) ? (1) : \
    (((x) == CAN1) ? (0) : \
    (((x) == CAN2) ? (0) : (-1))))
/* @brief FlexCAN maximum data rate. */
#define FSL_FEATURE_FLEXCAN_MAX_CANFD_BITRATE (8000000)
/* @brief Support payload endianness selection (bitfield CTRL2[PES]). */
#define FSL_FEATURE_FLEXCAN_HAS_ENDIANNESS_SELECTION (0)
/* @brief Enter Freeze mode before entering Disable and Stop mode. */
#define FSL_FEATURE_FLEXCAN_ENTER_FREEZE_MODE (1)
/* @brief Is affected by errata with ID 8341 (FlexCAN: Entering Freeze Mode or Low Power Mode from Normal Mode can cause the FlexCAN module to stop operating). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_8341 (1)

/* ACMP module features */

/* @brief Has CMP_C3. */
#define FSL_FEATURE_ACMP_HAS_C3_REG (0)
/* @brief Has C0 LINKEN Bit */
#define FSL_FEATURE_ACMP_HAS_C0_LINKEN_BIT (0)
/* @brief Has C0 OFFSET Bit */
#define FSL_FEATURE_ACMP_HAS_C0_OFFSET_BIT (1)
/* @brief Has C0 HYSTCTR Bit */
#define FSL_FEATURE_ACMP_HAS_C0_HYSTCTR_BIT (1)
/* @brief Has C1 INPSEL Bit */
#define FSL_FEATURE_ACMP_HAS_C1_INPSEL_BIT (1)
/* @brief Has C1 INNSEL Bit */
#define FSL_FEATURE_ACMP_HAS_C1_INNSEL_BIT (1)
/* @brief Has C1 DACOE Bit */
#define FSL_FEATURE_ACMP_HAS_C1_DACOE_BIT (0)
/* @brief Has C1 DMODE Bit */
#define FSL_FEATURE_ACMP_HAS_C1_DMODE_BIT (0)
/* @brief Has C2 RRE Bit */
#define FSL_FEATURE_ACMP_HAS_C2_RRE_BIT (1)
/* @brief Has C3 RDIVE Bit */
#define FSL_FEATURE_ACMP_HAS_C3_RDIVE_BIT (0)
/* @brief If support round-robin mode */
#define FSL_FEATURE_ACMP_HAS_NO_ROUNDROBIN_MODE (0)
/* @brief If support 3v domain */
#define FSL_FEATURE_ACMP_HAS_NO_3V_DOMAIN (1)
/* @brief If support window mode */
#define FSL_FEATURE_ACMP_HAS_NO_WINDOW_MODE (0)
/* @brief If support filter mode */
#define FSL_FEATURE_ACMP_HAS_NO_FILTER_MODE (0)
/* @brief Has No C0 SE Bit */
#define FSL_FEATURE_ACMP_HAS_NO_C0_SE_BIT (0)

/* CRC module features */

/* @brief If CRC has CRC register */
#define FSL_FEATURE_CRC_HAS_CRC_REGISTER (0)
/* @brief CRC16 type of the peripheral. */
#define FSL_FEATURE_CRC_CRC16_TYPE (0)

/* EDMA module features */

/* @brief Number of DMA channels (related to number of registers TCD, DCHPRI, bit fields ERQ[ERQn], EEI[EEIn], INT[INTn], ERR[ERRn], HRS[HRSn] and bit field widths ES[ERRCHN], CEEI[CEEI], SEEI[SEEI], CERQ[CERQ], SERQ[SERQ], CDNE[CDNE], SSRT[SSRT], CERR[CERR], CINT[CINT], TCDn_CITER_ELINKYES[LINKCH], TCDn_CSR[MAJORLINKCH], TCDn_BITER_ELINKYES[LINKCH]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL (16)
/* @brief Total number of DMA channels on all modules. */
#define FSL_FEATURE_EDMA_DMAMUX_CHANNELS (16)
/* @brief Number of DMA channel groups (register bit fields CR[ERGA], CR[GRPnPRI], ES[GPE], DCHPRIn[GRPPRI]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_CHANNEL_GROUP_COUNT (1)
/* @brief Has DMA_Error interrupt vector. */
#define FSL_FEATURE_EDMA_HAS_ERROR_IRQ (1)
/* @brief Number of DMA channels with asynchronous request capability (register EARS). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_ASYNCHRO_REQUEST_CHANNEL_COUNT (16)
/* @brief Channel IRQ entry shared offset. */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL_IRQ_ENTRY_SHARED_OFFSET (0)
/* @brief If 8 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_8_BYTES_TRANSFER (0)
/* @brief If 16 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_16_BYTES_TRANSFER (1)
/* @brief If 32 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_32_BYTES_TRANSFER (1)

/* DMAMUX module features */

/* @brief Number of DMA channels (related to number of register CHCFGn). */
#define FSL_FEATURE_DMAMUX_MODULE_CHANNEL (16)
/* @brief Total number of DMA channels on all modules. */
#define FSL_FEATURE_DMAMUX_DMAMUX_CHANNELS (16)
/* @brief Has the periodic trigger capability for the triggered DMA channel (register bit CHCFG0[TRIG]). */
#define FSL_FEATURE_DMAMUX_HAS_TRIG (1)
/* @brief Has DMA Channel Always ON function (register bit CHCFG0[A_ON]). */
#define FSL_FEATURE_DMAMUX_HAS_A_ON (0)
/* @brief Register CHCFGn width. */
#define FSL_FEATURE_DMAMUX_CHCFG_REGISTER_WIDTH (8)
/* @brief Register CHCFGn sorted in order 3, 2 ,1 ,0 ,7 ,6 ,5 ,4 ... */
#define FSL_FEATURE_DMAMUX_CHANNEL_NEEDS_ENDIAN_CONVERT (0)

/* ELA_CSEC module features */

/* @brief CSE_PRAM offset of the page length parameter used by the following commands: CMD_ENC_ECB, CMD_ENC_CBC, CMD_DEC_ECB, CMD_DEC_CBC, CMD_MP_COMPRESS */
#define FSL_FEATURE_ELA_CSEC_PAGE_LENGTH_OFFSET (0xEU)
/* @brief CSE_PRAM offset of the message length parameter used by the following commands: CMD_GENERATE_MAC, CMD_VERIFY_MAC (both copy and pointer methods) */
#define FSL_FEATURE_ELA_CSEC_MESSAGE_LENGTH_OFFSET (0xCU)
/* @brief CSE_PRAM offset of the MAC length parameter used by the following commands: CMD_VERIFY_MAC (both copy and pointer methods) */
#define FSL_FEATURE_ELA_CSEC_MAC_LENGTH_OFFSET (0x8U)
/* @brief CSE_PRAM offset of the boot size parameter used by the following commands: CMD_BOOT_DEFINE */
#define FSL_FEATURE_ELA_CSEC_BOOT_SIZE_OFFSET (0x1CU)
/* @brief CSE_PRAM offset of the boot flavor parameter used by the following commands: CMD_BOOT_DEFINE */
#define FSL_FEATURE_ELA_CSEC_BOOT_FLAVOR_OFFSET (0x1BU)
/* @brief CSE_PRAM offset of the Flash start address parameter used by the following commands: CMD_GENERATE_MAC, CMD_VERIFY_MAC (pointer method) */
#define FSL_FEATURE_ELA_CSEC_FLASH_START_ADDRESS_OFFSET (0x10U)
/* @brief CSE_PRAM offset of the verification status parameter used by the following commands: CMD_VERIFY_MAC (both copy and pointer methods) */
#define FSL_FEATURE_ELA_CSEC_VERIFICATION_STATUS_OFFSET (0x14U)
/* @brief CSE_PRAM offset of the error bits field contained by all commands */
#define FSL_FEATURE_ELA_CSEC_ERROR_BITS_OFFSET (0x4U)
/* @brief CSE_PRAM offset of the SREG parameter used by the following commands: CMD_GET_ID */
#define FSL_FEATURE_ELA_CSEC_SREG_OFFSET (0x2FU)
/* @brief Macro that enables the use of FTFM flash module on a platform */
#define FSL_FEATURE_ELA_CSEC_HAS_FTFM_MODULE (0U)
/* @brief CSE_PRAM offset of page 0 */
#define FSL_FEATURE_ELA_CSEC_PAGE_0_OFFSET (0x0U)
/* @brief CSE_PRAM offset of page 1 */
#define FSL_FEATURE_ELA_CSEC_PAGE_1_OFFSET (0x10U)
/* @brief CSE_PRAM offset of page 2 */
#define FSL_FEATURE_ELA_CSEC_PAGE_2_OFFSET (0x20U)
/* @brief CSE_PRAM offset of page 3 */
#define FSL_FEATURE_ELA_CSEC_PAGE_3_OFFSET (0x30U)
/* @brief CSE_PRAM offset of page 4 */
#define FSL_FEATURE_ELA_CSEC_PAGE_4_OFFSET (0x40U)
/* @brief CSE_PRAM offset of page 5 */
#define FSL_FEATURE_ELA_CSEC_PAGE_5_OFFSET (0x50U)
/* @brief CSE_PRAM offset of page 6 */
#define FSL_FEATURE_ELA_CSEC_PAGE_6_OFFSET (0x60U)
/* @brief CSE_PRAM offset of page 7 */
#define FSL_FEATURE_ELA_CSEC_PAGE_7_OFFSET (0x70U)

/* EWM module features */

/* @brief Has clock select (register CLKCTRL). */
#define FSL_FEATURE_EWM_HAS_CLOCK_SELECT (0)
/* @brief Has clock prescaler (register CLKPRESCALER). */
#define FSL_FEATURE_EWM_HAS_PRESCALER (1)

/* FLEXIO module features */

/* @brief Has DOZEN bit(CTRL[DOZEN]) */
#define FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT (1)
/* @brief FLEXIO support reset from RSTCTL */
#define FSL_FEATURE_FLEXIO_HAS_RESET (0)
/* @brief Has Shifter Status Register (FLEXIO_SHIFTSTAT) */
#define FSL_FEATURE_FLEXIO_HAS_SHIFTER_STATUS (1)
/* @brief Has Pin Data Input Register (FLEXIO_PIN) */
#define FSL_FEATURE_FLEXIO_HAS_PIN_STATUS (1)
/* @brief Has Shifter Buffer N Nibble Byte Swapped Register (FLEXIO_SHIFTBUFNBSn) */
#define FSL_FEATURE_FLEXIO_HAS_SHFT_BUFFER_NIBBLE_BYTE_SWAP (0)
/* @brief Has Shifter Buffer N Half Word Swapped Register (FLEXIO_SHIFTBUFHWSn) */
#define FSL_FEATURE_FLEXIO_HAS_SHFT_BUFFER_HALF_WORD_SWAP (0)
/* @brief Has Shifter Buffer N Nibble Swapped Register (FLEXIO_SHIFTBUFNISn) */
#define FSL_FEATURE_FLEXIO_HAS_SHFT_BUFFER_NIBBLE_SWAP (0)
/* @brief Supports Shifter State Mode (FLEXIO_SHIFTCTLn[SMOD]) */
#define FSL_FEATURE_FLEXIO_HAS_STATE_MODE (0)
/* @brief Supports Shifter Logic Mode (FLEXIO_SHIFTCTLn[SMOD]) */
#define FSL_FEATURE_FLEXIO_HAS_LOGIC_MODE (0)
/* @brief Supports paralle width (FLEXIO_SHIFTCFGn[PWIDTH]) */
#define FSL_FEATURE_FLEXIO_HAS_PARALLEL_WIDTH (0)
/* @brief Reset value of the FLEXIO_VERID register */
#define FSL_FEATURE_FLEXIO_VERID_RESET_VALUE (0x1010000)
/* @brief Reset value of the FLEXIO_PARAM register */
#define FSL_FEATURE_FLEXIO_PARAM_RESET_VALUE (0x4080404)
/* @brief Flexio DMA request base channel */
#define FSL_FEATURE_FLEXIO_DMA_REQUEST_BASE_CHANNEL (0)
/* @brief Represent the bit width of the TIMDCE field (FLEXIO_TIMCFGLn[TIMDEC]) */
#define FSL_FEATURE_FLEXIO_TIMCFG_TIMDCE_FIELD_WIDTH (2)
/* @brief Has pin input output related registers */
#define FSL_FEATURE_FLEXIO_HAS_PIN_REGISTER (0)

/* FLASH module features */

/* @brief Is of type FTFA. */
#define FSL_FEATURE_FLASH_IS_FTFA (0)
/* @brief Is of type FTFE. */
#define FSL_FEATURE_FLASH_IS_FTFE (0)
/* @brief Is of type FTFL. */
#define FSL_FEATURE_FLASH_IS_FTFL (0)
/* @brief Is of type FTFC. */
#define FSL_FEATURE_FLASH_IS_FTFC (1)
/* @brief Has flags indicating the status of the FlexRAM (register bits FCNFG[EEERDY], FCNFG[RAMRDY] and FCNFG[PFLSH]). */
#define FSL_FEATURE_FLASH_HAS_FLEX_RAM_FLAGS (1)
/* @brief Has program flash swapping status flag (register bit FCNFG[SWAP]). */
#define FSL_FEATURE_FLASH_HAS_PFLASH_SWAPPING_STATUS_FLAG (0)
/* @brief Has EEPROM region protection (register FEPROT). */
#define FSL_FEATURE_FLASH_HAS_EEROM_REGION_PROTECTION (1)
/* @brief Has data flash region protection (register FDPROT). */
#define FSL_FEATURE_FLASH_HAS_DATA_FLASH_REGION_PROTECTION (1)
/* @brief Has flash access control (registers XACCHn, SACCHn, where n is a number, FACSS and FACSN). */
#define FSL_FEATURE_FLASH_HAS_ACCESS_CONTROL (0)
/* @brief Has flash cache control in FMC module. */
#define FSL_FEATURE_FLASH_HAS_FMC_FLASH_CACHE_CONTROLS (0)
/* @brief Has flash cache control in MCM module. */
#define FSL_FEATURE_FLASH_HAS_MCM_FLASH_CACHE_CONTROLS (0)
/* @brief Has flash cache control in MSCM module. */
#define FSL_FEATURE_FLASH_HAS_MSCM_FLASH_CACHE_CONTROLS (1)
/* @brief Has prefetch speculation control in flash, such as kv5x. */
#define FSL_FEATURE_FLASH_PREFETCH_SPECULATION_CONTROL_IN_FLASH (0)
/* @brief P-Flash flash size coding rule version, value 0 for K1 and K2, value 1 for others. */
#define FSL_FEATURE_FLASH_SIZE_ENCODING_RULE_VERSION (1)
/* @brief P-Flash start address. */
#define FSL_FEATURE_FLASH_PFLASH_START_ADDRESS (0x00000000)
/* @brief P-Flash block count. */
#define FSL_FEATURE_FLASH_PFLASH_BLOCK_COUNT (1)
/* @brief P-Flash block size. */
#define FSL_FEATURE_FLASH_PFLASH_BLOCK_SIZE (524288)
/* @brief P-Flash sector size. */
#define FSL_FEATURE_FLASH_PFLASH_BLOCK_SECTOR_SIZE (4096)
/* @brief P-Flash write unit size. */
#define FSL_FEATURE_FLASH_PFLASH_BLOCK_WRITE_UNIT_SIZE (8)
/* @brief P-Flash data path width. */
#define FSL_FEATURE_FLASH_PFLASH_BLOCK_DATA_PATH_WIDTH (8)
/* @brief P-Flash block swap feature. */
#define FSL_FEATURE_FLASH_HAS_PFLASH_BLOCK_SWAP (0)
/* @brief P-Flash protection region count. */
#define FSL_FEATURE_FLASH_PFLASH_PROTECTION_REGION_COUNT (32)
/* @brief Flash memory count. */
#define FSL_FEATURE_FLASH_MEMORY_COUNT (1)
/* @brief Has FlexNVM memory. */
#define FSL_FEATURE_FLASH_HAS_FLEX_NVM (1)
/* @brief Has FlexNVM alias. */
#define FSL_FEATURE_FLASH_HAS_FLEX_NVM_ALIAS (0)
/* @brief FlexNVM start address. (Valid only if FlexNVM is available.) */
#define FSL_FEATURE_FLASH_FLEX_NVM_START_ADDRESS (0x10000000)
/* @brief FlexNVM alias start address. (Valid only if FlexNVM alias is available.) */
#define FSL_FEATURE_FLASH_FLEX_NVM_ALIAS_START_ADDRESS (0x00000000)
/* @brief FlexNVM block count. */
#define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_COUNT (1)
/* @brief FlexNVM block size. */
#define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_SIZE (65536)
/* @brief FlexNVM sector size. */
#define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_SECTOR_SIZE (2048)
/* @brief FlexNVM write unit size. */
#define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_WRITE_UNIT_SIZE (8)
/* @brief FlexNVM data path width. */
#define FSL_FEATURE_FLASH_FLEX_BLOCK_DATA_PATH_WIDTH (16)
/* @brief Has FlexRAM memory. */
#define FSL_FEATURE_FLASH_HAS_FLEX_RAM (1)
/* @brief FlexRAM start address. (Valid only if FlexRAM is available.) */
#define FSL_FEATURE_FLASH_FLEX_RAM_START_ADDRESS (0x14000000)
/* @brief FlexRAM size. */
#define FSL_FEATURE_FLASH_FLEX_RAM_SIZE (4096)
/* @brief Has 0x00 Read 1s Block command. */
#define FSL_FEATURE_FLASH_HAS_READ_1S_BLOCK_CMD (0)
/* @brief Has 0x01 Read 1s Section command. */
#define FSL_FEATURE_FLASH_HAS_READ_1S_SECTION_CMD (1)
/* @brief Has 0x02 Program Check command. */
#define FSL_FEATURE_FLASH_HAS_PROGRAM_CHECK_CMD (1)
/* @brief Has 0x03 Read Resource command. */
#define FSL_FEATURE_FLASH_HAS_READ_RESOURCE_CMD (0)
/* @brief Has 0x06 Program Longword command. */
#define FSL_FEATURE_FLASH_HAS_PROGRAM_LONGWORD_CMD (0)
/* @brief Has 0x07 Program Phrase command. */
#define FSL_FEATURE_FLASH_HAS_PROGRAM_PHRASE_CMD (1)
/* @brief Has 0x08 Erase Flash Block command. */
#define FSL_FEATURE_FLASH_HAS_ERASE_FLASH_BLOCK_CMD (0)
/* @brief Has 0x09 Erase Flash Sector command. */
#define FSL_FEATURE_FLASH_HAS_ERASE_FLASH_SECTOR_CMD (1)
/* @brief Has 0x0B Program Section command. */
#define FSL_FEATURE_FLASH_HAS_PROGRAM_SECTION_CMD (1)
/* @brief Has 0x0C Generate CRC signature for selected program flash sectors. */
#define FSL_FEATURE_FLASH_HAS_GENERATE_CRC_CMD (0)
/* @brief Has 0x40 Read 1s All Blocks command. */
#define FSL_FEATURE_FLASH_HAS_READ_1S_ALL_BLOCKS_CMD (1)
/* @brief Has 0x41 Read Once command. */
#define FSL_FEATURE_FLASH_HAS_READ_ONCE_CMD (1)
/* @brief Has 0x43 Program Once command. */
#define FSL_FEATURE_FLASH_HAS_PROGRAM_ONCE_CMD (1)
/* @brief Has 0x44 Erase All Blocks command. */
#define FSL_FEATURE_FLASH_HAS_ERASE_ALL_BLOCKS_CMD (1)
/* @brief Has 0x45 Verify Backdoor Access Key command. */
#define FSL_FEATURE_FLASH_HAS_VERIFY_BACKDOOR_ACCESS_KEY_CMD (1)
/* @brief Has 0x46 Swap Control command. */
#define FSL_FEATURE_FLASH_HAS_SWAP_CONTROL_CMD (0)
/* @brief Has 0x49 Erase All Blocks Unsecure command. */
#define FSL_FEATURE_FLASH_HAS_ERASE_ALL_BLOCKS_UNSECURE_CMD (1)
/* @brief Has 0x4A Read 1s All Execute-only Segments command. */
#define FSL_FEATURE_FLASH_HAS_READ_1S_ALL_EXECUTE_ONLY_SEGMENTS_CMD (0)
/* @brief Has 0x4B Erase All Execute-only Segments command. */
#define FSL_FEATURE_FLASH_HAS_ERASE_ALL_EXECUTE_ONLY_SEGMENTS_CMD (0)
/* @brief Has 0x80 Program Partition command. */
#define FSL_FEATURE_FLASH_HAS_PROGRAM_PARTITION_CMD (1)
/* @brief Has 0x81 Set FlexRAM Function command. */
#define FSL_FEATURE_FLASH_HAS_SET_FLEXRAM_FUNCTION_CMD (1)
/* @brief P-Flash Erase/Read 1st all block command address alignment. */
#define FSL_FEATURE_FLASH_PFLASH_BLOCK_CMD_ADDRESS_ALIGMENT (16)
/* @brief P-Flash Erase sector command address alignment. */
#define FSL_FEATURE_FLASH_PFLASH_SECTOR_CMD_ADDRESS_ALIGMENT (8)
/* @brief P-Flash Erase sector command address alignment. */
#define FSL_FEATURE_FLASH_PFLASH_1_SECTOR_CMD_ADDRESS_ALIGMENT (0)
/* @brief P-Flash Program/Verify section command address alignment. */
#define FSL_FEATURE_FLASH_PFLASH_SECTION_CMD_ADDRESS_ALIGMENT (8)
/* @brief P-Flash Program/Verify section command address alignment. */
#define FSL_FEATURE_FLASH_PFLASH_1_SECTION_CMD_ADDRESS_ALIGMENT (0)
/* @brief P-Flash Read resource command address alignment. */
#define FSL_FEATURE_FLASH_PFLASH_RESOURCE_CMD_ADDRESS_ALIGMENT (8)
/* @brief P-Flash Program check command address alignment. */
#define FSL_FEATURE_FLASH_PFLASH_CHECK_CMD_ADDRESS_ALIGMENT (4)
/* @brief P-Flash Program check command address alignment. */
#define FSL_FEATURE_FLASH_PFLASH_SWAP_CONTROL_CMD_ADDRESS_ALIGMENT (0)
/* @brief FlexNVM Erase/Read 1st all block command address alignment. */
#define FSL_FEATURE_FLASH_FLEX_NVM_BLOCK_CMD_ADDRESS_ALIGMENT (16)
/* @brief FlexNVM Erase sector command address alignment. */
#define FSL_FEATURE_FLASH_FLEX_NVM_SECTOR_CMD_ADDRESS_ALIGMENT (16)
/* @brief FlexNVM Rrogram/Verify section command address alignment. */
#define FSL_FEATURE_FLASH_FLEX_NVM_SECTION_CMD_ADDRESS_ALIGMENT (16)
/* @brief FlexNVM Read resource command address alignment. */
#define FSL_FEATURE_FLASH_FLEX_NVM_RESOURCE_CMD_ADDRESS_ALIGMENT (8)
/* @brief FlexNVM Program check command address alignment. */
#define FSL_FEATURE_FLASH_FLEX_NVM_CHECK_CMD_ADDRESS_ALIGMENT (4)
/* @brief FlexNVM partition code 0000 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0000 (0x00080000U)
/* @brief FlexNVM partition code 0001 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0001 (0xFFFFFFFFU)
/* @brief FlexNVM partition code 0010 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0010 (0xFFFFFFFFU)
/* @brief FlexNVM partition code 0011 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0011 (0xFFFFFFFFU)
/* @brief FlexNVM partition code 0100 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0100 (0x00070000U)
/* @brief FlexNVM partition code 0101 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0101 (0xFFFFFFFFU)
/* @brief FlexNVM partition code 0110 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0110 (0xFFFFFFFFU)
/* @brief FlexNVM partition code 0111 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_0111 (0xFFFFFFFFU)
/* @brief FlexNVM partition code 1000 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1000 (0xFFFFFFFFU)
/* @brief FlexNVM partition code 1001 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1001 (0xFFFFFFFFU)
/* @brief FlexNVM partition code 1010 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1010 (0xFFFFFFFFU)
/* @brief FlexNVM partition code 1011 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1011 (0xFFFFFFFFU)
/* @brief FlexNVM partition code 1100 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1100 (0xFFFFFFFFU)
/* @brief FlexNVM partition code 1101 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1101 (0xFFFFFFFFU)
/* @brief FlexNVM partition code 1110 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1110 (0xFFFFFFFFU)
/* @brief FlexNVM partition code 1111 mapping to data flash size in bytes (0xFFFFFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_DFLASH_SIZE_FOR_DEPART_1111 (0x00080000U)
/* @brief Emulated eeprom size code 0000 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0000 (0x0000U)
/* @brief Emulated eeprom size code 0001 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0001 (0xFFFFU)
/* @brief Emulated eeprom size code 0010 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0010 (0x1000U)
/* @brief Emulated eeprom size code 0011 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0011 (0xFFFFU)
/* @brief Emulated eeprom size code 0100 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0100 (0xFFFFU)
/* @brief Emulated eeprom size code 0101 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0101 (0xFFFFU)
/* @brief Emulated eeprom size code 0110 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0110 (0xFFFFU)
/* @brief Emulated eeprom size code 0111 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_0111 (0xFFFFU)
/* @brief Emulated eeprom size code 1000 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1000 (0xFFFFU)
/* @brief Emulated eeprom size code 1001 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1001 (0xFFFFU)
/* @brief Emulated eeprom size code 1010 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1010 (0xFFFFU)
/* @brief Emulated eeprom size code 1011 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1011 (0xFFFFU)
/* @brief Emulated eeprom size code 1100 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1100 (0xFFFFU)
/* @brief Emulated eeprom size code 1101 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1101 (0xFFFFU)
/* @brief Emulated eeprom size code 1110 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1110 (0xFFFFU)
/* @brief Emulated eeprom size code 1111 mapping to emulated eeprom size in bytes (0xFFFF = reserved). */
#define FSL_FEATURE_FLASH_FLEX_NVM_EEPROM_SIZE_FOR_EEESIZE_1111 (0x0000U)

/* FTM module features */

/* @brief Number of channels. */
#define FSL_FEATURE_FTM_CHANNEL_COUNTn(x) (8)
/* @brief Has counter reset by the selected input capture event (register bits C0SC[ICRST], C1SC[ICRST], ...). */
#define FSL_FEATURE_FTM_HAS_COUNTER_RESET_BY_CAPTURE_EVENT (1)
/* @brief Has extended deadtime value. */
#define FSL_FEATURE_FTM_HAS_EXTENDED_DEADTIME_VALUE (1)
/* @brief Enable pwm output for the module. */
#define FSL_FEATURE_FTM_HAS_ENABLE_PWM_OUTPUT (1)
/* @brief Has half-cycle reload for the module. */
#define FSL_FEATURE_FTM_HAS_HALFCYCLE_RELOAD (1)
/* @brief Has reload interrupt. */
#define FSL_FEATURE_FTM_HAS_RELOAD_INTERRUPT (1)
/* @brief Has reload initialization trigger. */
#define FSL_FEATURE_FTM_HAS_RELOAD_INITIALIZATION_TRIGGER (1)
/* @brief Has DMA support, bitfield CnSC[DMA]. */
#define FSL_FEATURE_FTM_HAS_DMA_SUPPORT (1)
/* @brief If channel 6 is used to generate channel trigger, bitfield EXTTRIG[CH6TRIG]. */
#define FSL_FEATURE_FTM_HAS_CHANNEL6_TRIGGER (1)
/* @brief If channel 7 is used to generate channel trigger, bitfield EXTTRIG[CH7TRIG]. */
#define FSL_FEATURE_FTM_HAS_CHANNEL7_TRIGGER (1)
/* @brief If instance has only TPM function. */
#define FSL_FEATURE_FTM_IS_TPM_ONLY_INSTANCEn(x) (0)
/* @brief Has frequency of the reload opportunities, bitfield CONF[LDFQ]. */
#define FSL_FEATURE_FTM_HAS_CONF_LDFQ_BIT (1)
/* @brief Has filter prescaler. */
#define FSL_FEATURE_FTM_HAS_FILTER_PRESCALER (1)
/* @brief Has fault output state configurable. */
#define FSL_FEATURE_FTM_HAS_FAULT_OUTPUT_STATE (1)
/* @brief Has paired deadtime. */
#define FSL_FEATURE_FTM_HAS_PAIRED_DEADTIME (1)
/* @brief Has PWM dithering. */
#define FSL_FEATURE_FTM_HAS_DITHERING (0)
/* @brief FTM instance has PWM dithering. */
#define FSL_FEATURE_FTM_INSTANCE_HAS_DITHERINGn(x) (0)
/* @brief Has trigger mode control. */
#define FSL_FEATURE_FTM_HAS_TRIGGER_MODE (1)
/* @brief Has modified combine mode. */
#define FSL_FEATURE_FTM_HAS_MODIFIED_COMBINE_PWM (1)
/* @brief Has configurable channel input state. */
#define FSL_FEATURE_FTM_HAS_CONF_CHIS_BIT (1)
/* @brief Has configurable channel output value. */
#define FSL_FEATURE_FTM_HAS_CONF_CHOV_BIT (1)
/* @brief FTM instance has Quadrature Decoder with input filter. */
#define FSL_FEATURE_FTM_INSTANCE_HAS_QUAD_DECODEn(x) \
    (((x) == FTM3) ? (0) : \
    (((x) == FTM0) ? (0) : \
    (((x) == FTM1) ? (1) : \
    (((x) == FTM2) ? (1) : (-1)))))
/* @brief FTM instance fault input number. */
#define FSL_FEATURE_FTM_INSTANCE_FAULT_INPUT_NUMBERn(x) (4)
/* @brief Is affected by errata with ID 010856 (FTM: Safe state is not removed from channel outputs after fault condition ends if SWOCTRL is being used to control the pin). */
#define FSL_FEATURE_FTM_HAS_ERRATA_010856 (1)

/* GPIO module features */

/* @brief Has GPIO attribute checker register (GACR). */
#define FSL_FEATURE_GPIO_HAS_ATTRIBUTE_CHECKER (0)
/* @brief Has GPIO version ID register (VERID). */
#define FSL_FEATURE_GPIO_HAS_VERSION_INFO_REGISTER (0)
/* @brief Has secure/non-secure access protection registers (LOCK, PCNS, PCNP, ICNS, ICNP). */
#define FSL_FEATURE_GPIO_HAS_SECURE_PRIVILEGE_CONTROL (0)
/* @brief Has GPIO port input disable register (PIDR). */
#define FSL_FEATURE_GPIO_HAS_PORT_INPUT_CONTROL (1)
/* @brief Has GPIO interrupt/DMA request/trigger output selection. */
#define FSL_FEATURE_GPIO_HAS_INTERRUPT_CHANNEL_SELECT (0)

/* LMEM module features */

/* @brief Has process identifier support. */
#define FSL_FEATURE_LMEM_HAS_SYSTEMBUS_CACHE (0)
/* @brief Support instruction cache demote. */
#define FSL_FEATURE_LMEM_SUPPORT_ICACHE_DEMOTE_REMOVE (0)
/* @brief Has no NONCACHEABLE section. */
#define FSL_FEATURE_HAS_NO_NONCACHEABLE_SECTION (0)
/* @brief Has Enable Write Buffer bit (register bit PCCCR[ENWRBUF]). */
#define FSL_FEATURE_LMEM_HAS_ENWRBUF_BIT_CONFIG_SUPPORT (0)
/* @brief L1 ICACHE line size in byte. */
#define FSL_FEATURE_L1ICACHE_LINESIZE_BYTE (16)
/* @brief L1 DCACHE line size in byte. */
#define FSL_FEATURE_L1DCACHE_LINESIZE_BYTE (16)

/* LPI2C module features */

/* @brief Has separate DMA RX and TX requests. */
#define FSL_FEATURE_LPI2C_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FSL_FEATURE_LPI2C_FIFO_SIZEn(x) (4)
/* @brief Has dedicated interrupt for master and slave. */
#define FSL_FEATURE_LPI2C_HAS_ROLE_SPLIT_IRQ (1)

/* LPIT module features */

/* @brief Number of channels (related to number of registers LDVALn, CVALn, TCTRLn, TFLGn). */
#define FSL_FEATURE_LPIT_TIMER_COUNT (4)
/* @brief Has lifetime timer (related to existence of registers LTMR64L and LTMR64H). */
#define FSL_FEATURE_LPIT_HAS_LIFETIME_TIMER (0)
/* @brief Has shared interrupt handler (has not individual interrupt handler for each channel). */
#define FSL_FEATURE_LPIT_HAS_SHARED_IRQ_HANDLER (1)

/* LPSPI module features */

/* @brief Capacity (number of entries) of the transmit/receive FIFO. */
#define FSL_FEATURE_LPSPI_FIFO_SIZEn(x) (4)
/* @brief Has separate DMA RX and TX requests. */
#define FSL_FEATURE_LPSPI_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
/* @brief Has CCR1 (related to existence of registers CCR1). */
#define FSL_FEATURE_LPSPI_HAS_CCR1 (0)
/* @brief Has no PCSCFG bit in CFGR1 register. */
#define FSL_FEATURE_LPSPI_HAS_NO_PCSCFG (0)
/* @brief Has no WIDTH bits in TCR register. */
#define FSL_FEATURE_LPSPI_HAS_NO_MULTI_WIDTH (0)
/* @brief Has ERRATA051472. */
#define FSL_FEATURE_LPSPI_HAS_ERRATA_051472 (1)

/* LPTMR module features */

/* @brief Has shared interrupt handler with another LPTMR module. */
#define FSL_FEATURE_LPTMR_HAS_SHARED_IRQ_HANDLER (0)
/* @brief Whether LPTMR counter is 32 bits width. */
#define FSL_FEATURE_LPTMR_CNR_WIDTH_IS_32B (0)
/* @brief Has timer DMA request enable (register bit CSR[TDRE]). */
#define FSL_FEATURE_LPTMR_HAS_CSR_TDRE (1)
/* @brief Do not has prescaler clock source 0. */
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_0_SUPPORT (0)
/* @brief Do not has prescaler clock source 1. */
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_1_SUPPORT (0)
/* @brief Do not has prescaler clock source 2. */
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_2_SUPPORT (0)
/* @brief Do not has prescaler clock source 3. */
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_3_SUPPORT (0)

/* LPUART module features */

/* @brief Has receive FIFO overflow detection (bit field CFIFO[RXOFE]). */
#define FSL_FEATURE_LPUART_HAS_IRQ_EXTENDED_FUNCTIONS (0)
/* @brief Has low power features (can be enabled in wait mode via register bit C1[DOZEEN] or CTRL[DOZEEN] if the registers are 32-bit wide). */
#define FSL_FEATURE_LPUART_HAS_LOW_POWER_UART_SUPPORT (1)
/* @brief Has extended data register ED (or extra flags in the DATA register if the registers are 32-bit wide). */
#define FSL_FEATURE_LPUART_HAS_EXTENDED_DATA_REGISTER_FLAGS (1)
/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FSL_FEATURE_LPUART_HAS_FIFO (1)
/* @brief Has 32-bit register MODIR */
#define FSL_FEATURE_LPUART_HAS_MODIR (1)
/* @brief Hardware flow control (RTS, CTS) is supported. */
#define FSL_FEATURE_LPUART_HAS_MODEM_SUPPORT (1)
/* @brief Infrared (modulation) is supported. */
#define FSL_FEATURE_LPUART_HAS_IR_SUPPORT (1)
/* @brief 2 bits long stop bit is available. */
#define FSL_FEATURE_LPUART_HAS_STOP_BIT_CONFIG_SUPPORT (1)
/* @brief If 10-bit mode is supported. */
#define FSL_FEATURE_LPUART_HAS_10BIT_DATA_SUPPORT (1)
/* @brief If 7-bit mode is supported. */
#define FSL_FEATURE_LPUART_HAS_7BIT_DATA_SUPPORT (1)
/* @brief Baud rate fine adjustment is available. */
#define FSL_FEATURE_LPUART_HAS_BAUD_RATE_FINE_ADJUST_SUPPORT (0)
/* @brief Baud rate oversampling is available (has bit fields C4[OSR], C5[BOTHEDGE], C5[RESYNCDIS] or BAUD[OSR], BAUD[BOTHEDGE], BAUD[RESYNCDIS] if the registers are 32-bit wide). */
#define FSL_FEATURE_LPUART_HAS_BAUD_RATE_OVER_SAMPLING_SUPPORT (1)
/* @brief Baud rate oversampling is available. */
#define FSL_FEATURE_LPUART_HAS_RX_RESYNC_SUPPORT (1)
/* @brief Baud rate oversampling is available. */
#define FSL_FEATURE_LPUART_HAS_BOTH_EDGE_SAMPLING_SUPPORT (1)
/* @brief Peripheral type. */
#define FSL_FEATURE_LPUART_IS_SCI (1)
/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FSL_FEATURE_LPUART_FIFO_SIZEn(x) (4)
/* @brief Supports two match addresses to filter incoming frames. */
#define FSL_FEATURE_LPUART_HAS_ADDRESS_MATCHING (1)
/* @brief Has transmitter/receiver DMA enable bits C5[TDMAE]/C5[RDMAE] (or BAUD[TDMAE]/BAUD[RDMAE] if the registers are 32-bit wide). */
#define FSL_FEATURE_LPUART_HAS_DMA_ENABLE (1)
/* @brief Has transmitter/receiver DMA select bits C4[TDMAS]/C4[RDMAS], resp. C5[TDMAS]/C5[RDMAS] if IS_SCI = 0. */
#define FSL_FEATURE_LPUART_HAS_DMA_SELECT (0)
/* @brief Data character bit order selection is supported (bit field S2[MSBF] or STAT[MSBF] if the registers are 32-bit wide). */
#define FSL_FEATURE_LPUART_HAS_BIT_ORDER_SELECT (1)
/* @brief Has smart card (ISO7816 protocol) support and no improved smart card support. */
#define FSL_FEATURE_LPUART_HAS_SMART_CARD_SUPPORT (0)
/* @brief Has improved smart card (ISO7816 protocol) support. */
#define FSL_FEATURE_LPUART_HAS_IMPROVED_SMART_CARD_SUPPORT (0)
/* @brief Has local operation network (CEA709.1-B protocol) support. */
#define FSL_FEATURE_LPUART_HAS_LOCAL_OPERATION_NETWORK_SUPPORT (0)
/* @brief Has 32-bit registers (BAUD, STAT, CTRL, DATA, MATCH, MODIR) instead of 8-bit (BDH, BDL, C1, S1, D, etc.). */
#define FSL_FEATURE_LPUART_HAS_32BIT_REGISTERS (1)
/* @brief Lin break detect available (has bit BAUD[LBKDIE]). */
#define FSL_FEATURE_LPUART_HAS_LIN_BREAK_DETECT (1)
/* @brief UART stops in Wait mode available (has bit C1[UARTSWAI]). */
#define FSL_FEATURE_LPUART_HAS_WAIT_MODE_OPERATION (0)
/* @brief Has separate DMA RX and TX requests. */
#define FSL_FEATURE_LPUART_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
/* @brief Has separate RX and TX interrupts. */
#define FSL_FEATURE_LPUART_HAS_SEPARATE_RX_TX_IRQ (0)
/* @brief Has LPAURT_PARAM. */
#define FSL_FEATURE_LPUART_HAS_PARAM (1)
/* @brief Has LPUART_VERID. */
#define FSL_FEATURE_LPUART_HAS_VERID (1)
/* @brief Has LPUART_GLOBAL. */
#define FSL_FEATURE_LPUART_HAS_GLOBAL (1)
/* @brief Has LPUART_PINCFG. */
#define FSL_FEATURE_LPUART_HAS_PINCFG (1)
/* @brief Belong to LPFLEXCOMM */
#define FSL_FEATURE_LPUART_IS_LPFLEXCOMM (0)
/* @brief Has register MODEM Control. */
#define FSL_FEATURE_LPUART_HAS_MCR (0)
/* @brief Has register Half Duplex Control. */
#define FSL_FEATURE_LPUART_HAS_HDCR (0)
/* @brief Has register Timeout. */
#define FSL_FEATURE_LPUART_HAS_TIMEOUT (0)
/* @brief UART support swap TX and RX (has bit CTRL[SWAP]). */
#define FSL_FEATURE_LPUART_HAS_CTRL_SWAP (0)

/* MSCM module features */

/* @brief Number of configuration information for processors. */
#define FSL_FEATURE_MSCM_HAS_CP_COUNT (1)
/* @brief Has data cache. */
#define FSL_FEATURE_MSCM_HAS_DATACACHE (0)

/* PDB module features */

/* @brief Has DAC support. */
#define FSL_FEATURE_PDB_HAS_DAC (0)
/* @brief Has shared interrupt handler (has not individual interrupt handler for each channel). */
#define FSL_FEATURE_PDB_HAS_SHARED_IRQ_HANDLER (0)
/* @brief PDB channel number). */
#define FSL_FEATURE_PDB_CHANNEL_COUNT (2)
/* @brief Channel pre-trigger nunmber (related to number of registers CHmDLYn). */
#define FSL_FEATURE_PDB_CHANNEL_PRE_TRIGGER_COUNT (8)
/* @brief DAC interval trigger number). */
#define FSL_FEATURE_PDB_DAC_INTERVAL_TRIGGER_COUNT (0)
/* @brief Pulse out number). */
#define FSL_FEATURE_PDB_PULSE_OUT_COUNT (1)

/* PMC module features */

/* @brief Has Bandgap Enable In VLPx Operation support. */
#define FSL_FEATURE_PMC_HAS_BGEN (0)
/* @brief Has Bandgap Buffer Enable. */
#define FSL_FEATURE_PMC_HAS_BGBE (0)
/* @brief Has Bandgap Buffer Drive Select. */
#define FSL_FEATURE_PMC_HAS_BGBDS (0)
/* @brief Has Low-Voltage Detect Voltage Select support. */
#define FSL_FEATURE_PMC_HAS_LVDV (0)
/* @brief Has Low-Voltage Warning Voltage Select support. */
#define FSL_FEATURE_PMC_HAS_LVWV (0)
/* @brief Has LPO. */
#define FSL_FEATURE_PMC_HAS_LPO (1)
/* @brief Has VLPx option PMC_REGSC[VLPO]. */
#define FSL_FEATURE_PMC_HAS_VLPO (0)
/* @brief Has acknowledge isolation support. */
#define FSL_FEATURE_PMC_HAS_ACKISO (0)
/* @brief Has Regulator In Full Performance Mode Status Bit PMC_REGSC[REGFPM]. */
#define FSL_FEATURE_PMC_HAS_REGFPM (1)
/* @brief Has Regulator In Run Regulation Status Bit PMC_REGSC[REGONS]. */
#define FSL_FEATURE_PMC_HAS_REGONS (0)
/* @brief Has PMC_HVDSC1. */
#define FSL_FEATURE_PMC_HAS_HVDSC1 (0)
/* @brief Has PMC_PARAM. */
#define FSL_FEATURE_PMC_HAS_PARAM (0)
/* @brief Has PMC_VERID. */
#define FSL_FEATURE_PMC_HAS_VERID (0)

/* PORT module features */

/* @brief Has control lock (register bit PCR[LK]). */
#define FSL_FEATURE_PORT_HAS_PIN_CONTROL_LOCK (1)
/* @brief Has open drain control (register bit PCR[ODE]). */
#define FSL_FEATURE_PORT_HAS_OPEN_DRAIN (0)
/* @brief Has digital filter (registers DFER, DFCR and DFWR). */
#define FSL_FEATURE_PORT_HAS_DIGITAL_FILTER (1)
/* @brief Has DMA request (register bit field PCR[IRQC] values). */
#define FSL_FEATURE_PORT_HAS_DMA_REQUEST (1)
/* @brief Has pull resistor selection available. */
#define FSL_FEATURE_PORT_HAS_PULL_SELECTION (1)
/* @brief Has pull resistor enable (register bit PCR[PE]). */
#define FSL_FEATURE_PORT_HAS_PULL_ENABLE (1)
/* @brief Has slew rate control (register bit PCR[SRE]). */
#define FSL_FEATURE_PORT_HAS_SLEW_RATE (0)
/* @brief Has passive filter (register bit field PCR[PFE]). */
#define FSL_FEATURE_PORT_HAS_PASSIVE_FILTER (1)
/* @brief Has drive strength control (register bit PCR[DSE]). */
#define FSL_FEATURE_PORT_HAS_DRIVE_STRENGTH (1)
/* @brief Has separate drive strength register (HDRVE). */
#define FSL_FEATURE_PORT_HAS_DRIVE_STRENGTH_REGISTER (0)
/* @brief Has glitch filter (register IOFLT). */
#define FSL_FEATURE_PORT_HAS_GLITCH_FILTER (0)
/* @brief Defines width of PCR[MUX] field. */
#define FSL_FEATURE_PORT_PCR_MUX_WIDTH (3)
/* @brief Has dedicated interrupt vector. */
#define FSL_FEATURE_PORT_HAS_INTERRUPT_VECTOR (1)
/* @brief Has multiple pin IRQ configuration (register GICLR and GICHR). */
#define FSL_FEATURE_PORT_HAS_MULTIPLE_IRQ_CONFIG (1)
/* @brief Defines whether PCR[IRQC] bit-field has flag states. */
#define FSL_FEATURE_PORT_HAS_IRQC_FLAG (0)
/* @brief Defines whether PCR[IRQC] bit-field has trigger states. */
#define FSL_FEATURE_PORT_HAS_IRQC_TRIGGER (0)

/* RCM module features */

/* @brief Has Loss-of-Lock Reset support. */
#define FSL_FEATURE_RCM_HAS_LOL (1)
/* @brief Has Loss-of-Clock Reset support. */
#define FSL_FEATURE_RCM_HAS_LOC (1)
/* @brief Has JTAG generated Reset support. */
#define FSL_FEATURE_RCM_HAS_JTAG (1)
/* @brief Has EzPort generated Reset support. */
#define FSL_FEATURE_RCM_HAS_EZPORT (0)
/* @brief Has bit-field indicating EZP_MS_B pin state during last reset. */
#define FSL_FEATURE_RCM_HAS_EZPMS (0)
/* @brief Has boot ROM configuration, MR[BOOTROM], FM[FORCEROM] */
#define FSL_FEATURE_RCM_HAS_BOOTROM (0)
/* @brief Has sticky system reset status register RCM_SSRS0 and RCM_SSRS1. */
#define FSL_FEATURE_RCM_HAS_SSRS (1)
/* @brief Has RCM_VERID. */
#define FSL_FEATURE_RCM_HAS_VERID (1)
/* @brief Has RCM_PARAM. */
#define FSL_FEATURE_RCM_HAS_PARAM (1)
/* @brief Has Reset Interrupt Enable Register RCM_SRIE. */
#define FSL_FEATURE_RCM_HAS_SRIE (1)
/* @brief RCM register bit width. */
#define FSL_FEATURE_RCM_REG_WIDTH (32)
/* @brief Has Core 1 generated  Reset support RCM_SRS[CORE1] */
#define FSL_FEATURE_RCM_HAS_CORE1 (0)
/* @brief Has MDM-AP system reset support RCM_SRS[MDM_AP] */
#define FSL_FEATURE_RCM_HAS_MDM_AP (1)
/* @brief Has wakeup reset feature. Register bit SRS[WAKEUP]. */
#define FSL_FEATURE_RCM_HAS_WAKEUP (0)

/* RTC module features */

/* @brief Has wakeup pin. */
#define FSL_FEATURE_RTC_HAS_WAKEUP_PIN (0)
/* @brief Has wakeup pin selection (bit field CR[WPS]). */
#define FSL_FEATURE_RTC_HAS_WAKEUP_PIN_SELECTION (0)
/* @brief Has low power features (registers MER, MCLR and MCHR). */
#define FSL_FEATURE_RTC_HAS_MONOTONIC (0)
/* @brief Has read/write access control (registers WAR and RAR). */
#define FSL_FEATURE_RTC_HAS_ACCESS_CONTROL (0)
/* @brief Has security features (registers TTSR, MER, MCLR and MCHR). */
#define FSL_FEATURE_RTC_HAS_SECURITY (0)
/* @brief Has RTC_CLKIN available. */
#define FSL_FEATURE_RTC_HAS_RTC_CLKIN (0)
/* @brief Has prescaler adjust for LPO. */
#define FSL_FEATURE_RTC_HAS_LPO_ADJUST (1)
/* @brief Has Clock Pin Enable field. */
#define FSL_FEATURE_RTC_HAS_CPE (1)
/* @brief Has Timer Seconds Interrupt Configuration field. */
#define FSL_FEATURE_RTC_HAS_TSIC (1)
/* @brief Has OSC capacitor setting RTC_CR[SC2P ~ SC16P] */
#define FSL_FEATURE_RTC_HAS_OSC_SCXP (0)
/* @brief Has Tamper Interrupt Register (register TIR). */
#define FSL_FEATURE_RTC_HAS_TIR (0)
/* @brief Has Tamper Pin Interrupt Enable (bitfield TIR[TPIE]). */
#define FSL_FEATURE_RTC_HAS_TIR_TPIE (0)
/* @brief Has Security Interrupt Enable (bitfield TIR[SIE]). */
#define FSL_FEATURE_RTC_HAS_TIR_SIE (0)
/* @brief Has Loss of Clock Interrupt Enable (bitfield TIR[LCIE]). */
#define FSL_FEATURE_RTC_HAS_TIR_LCIE (0)
/* @brief Has Tamper Interrupt Detect Flag (bitfield SR[TIDF]). */
#define FSL_FEATURE_RTC_HAS_SR_TIDF (0)
/* @brief Has Tamper Detect Register (register TDR). */
#define FSL_FEATURE_RTC_HAS_TDR (0)
/* @brief Has Tamper Pin Flag (bitfield TDR[TPF]). */
#define FSL_FEATURE_RTC_HAS_TDR_TPF (0)
/* @brief Has Security Tamper Flag (bitfield TDR[STF]). */
#define FSL_FEATURE_RTC_HAS_TDR_STF (0)
/* @brief Has Loss of Clock Tamper Flag (bitfield TDR[LCTF]). */
#define FSL_FEATURE_RTC_HAS_TDR_LCTF (0)
/* @brief Has Tamper Time Seconds Register (register TTSR). */
#define FSL_FEATURE_RTC_HAS_TTSR (0)
/* @brief Has Pin Configuration Register (register PCR). */
#define FSL_FEATURE_RTC_HAS_PCR (0)
/* @brief Has Oscillator Enable(bitfield CR[OSCE]). */
#define FSL_FEATURE_RTC_HAS_NO_CR_OSCE (1)
/* @brief Is affected by errata with ID 010716 (RTC: Timer Alarm Flag can assert erroneously). */
#define FSL_FEATURE_RTC_HAS_ERRATA_010716 (1)

/* SCG module features */

/* @brief Has platform clock divider SCG_CSR[DIVPLAT]. */
#define FSL_FEATURE_SCG_HAS_DIVPLAT (0)
/* @brief Has bus clock divider SCG_CSR[DIVBUS]. */
#define FSL_FEATURE_SCG_HAS_DIVBUS (1)
/* @brief Has external clock divide ratio SCG_CSR[DIVEXT]. */
#define FSL_FEATURE_SCG_HAS_DIVEXT (0)
/* @brief Has OSC capacitor setting SOSCCFG[SC2P ~ SC16P]. */
#define FSL_FEATURE_SCG_HAS_OSC_SCXP (0)
/* @brief Has OSC freq range SOSCCFG[RANGE]. */
#define FSL_FEATURE_SCG_HAS_SOSC_RANGE (1)
/* @brief Has SOSCCSR[SOSCERCLKEN]. */
#define FSL_FEATURE_SCG_HAS_OSC_ERCLK (0)
/* @brief Has CLKOUT configure register SCG_CLKOUTCNFG. */
#define FSL_FEATURE_SCG_HAS_CLKOUTCNFG (1)
/* @brief Has SCG_SOSCDIV[SOSCDIV1]. */
#define FSL_FEATURE_SCG_HAS_SOSCDIV1 (1)
/* @brief Has SCG_SOSCDIV[SOSCDIV3]. */
#define FSL_FEATURE_SCG_HAS_SOSCDIV3 (0)
/* @brief Has SCG_SIRCDIV[SIRCDIV1]. */
#define FSL_FEATURE_SCG_HAS_SIRCDIV1 (1)
/* @brief Has SCG_SIRCDIV[SIRCDIV3]. */
#define FSL_FEATURE_SCG_HAS_SIRCDIV3 (0)
/* @brief Has SCG_SIRCCSR[LPOPO]. */
#define FSL_FEATURE_SCG_HAS_SIRC_LPOPO (0)
/* @brief Has SCG_FIRCDIV[FIRCDIV1]. */
#define FSL_FEATURE_SCG_HAS_FIRCDIV1 (1)
/* @brief Has SCG_FIRCDIV[FIRCDIV3]. */
#define FSL_FEATURE_SCG_HAS_FIRCDIV3 (0)
/* @brief Has SCG_FIRCCSR[FIRCLPEN]. */
#define FSL_FEATURE_SCG_HAS_FIRCLPEN (0)
/* @brief Has SCG_FIRCCSR[FIRCREGOFF]. */
#define FSL_FEATURE_SCG_HAS_FIRCREGOFF (1)
/* @brief Has SCG_SPLLDIV[SPLLDIV1]. */
#define FSL_FEATURE_SCG_HAS_SPLLDIV1 (1)
/* @brief Has SCG_SPLLDIV[SPLLDIV3]. */
#define FSL_FEATURE_SCG_HAS_SPLLDIV3 (0)
/* @brief Has SCG_SPLLCFG[PLLPOSTDIV1]. */
#define FSL_FEATURE_SCG_HAS_SPLLPOSTDIV1 (0)
/* @brief Has SCG_SPLLCFG[PLLPOSTDIV2]. */
#define FSL_FEATURE_SCG_HAS_SPLLPOSTDIV2 (0)
/* @brief Has SCG_SPLLCFG[PLLS]. */
#define FSL_FEATURE_SCG_HAS_SPLL_PLLS (0)
/* @brief Has SCG_SPLLCFG[BYPASS]. */
#define FSL_FEATURE_SCG_HAS_SPLL_BYPASS (0)
/* @brief Has SCG_SPLLCFG[PFDSEL]. */
#define FSL_FEATURE_SCG_HAS_SPLL_PFDSEL (0)
/* @brief Has SCG_SPLLCSR[SPLLCM]. */
#define FSL_FEATURE_SCG_HAS_SPLL_MONITOR (1)
/* @brief Has SCG_LPFLLDIV[FLLDIV1]. */
#define FSL_FEATURE_SCG_HAS_FLLDIV1 (0)
/* @brief Has SCG_LPFLLDIV[FLLDIV3]. */
#define FSL_FEATURE_SCG_HAS_FLLDIV3 (0)
/* @brief Has low power FLL, SCG_LPFLLCSR. */
#define FSL_FEATURE_SCG_HAS_LPFLL (0)
/* @brief Has low power FLL stop enable. */
#define FSL_FEATURE_SCG_HAS_LPFLLSTEN (0)
/* @brief Has system PLL, SCG_SPLLCSR. */
#define FSL_FEATURE_SCG_HAS_SPLL (1)
/* @brief Has system PLL PFD, SCG_SPLLPFD. */
#define FSL_FEATURE_SCG_HAS_SPLLPFD (0)
/* @brief Has auxiliary PLL, SCG_APLLCSR. */
#define FSL_FEATURE_SCG_HAS_APLL (0)
/* @brief Has RTC OSC control, SCG_ROSCCSR. */
#define FSL_FEATURE_SCG_HAS_ROSC (0)
/* @brief Has RTC OSC clock source. */
#define FSL_FEATURE_SCG_HAS_ROSC_SYS_CLK_SRC (0)
/* @brief Has RTC OSC clock out select. */
#define FSL_FEATURE_SCG_HAS_ROSC_CLKOUT (0)
/* @brief Has SIRC clock out select. */
#define FSL_FEATURE_SCG_HAS_EXT_CLKOUT (0)
/* @brief Has FIRC trim source USB0 Start of Frame. */
#define FSL_FEATURE_SCG_HAS_FIRC_TRIMSRC_USB0 (0)
/* @brief Has FIRC trim source USB1 Start of Frame. */
#define FSL_FEATURE_SCG_HAS_FIRC_TRIMSRC_USB1 (0)
/* @brief Has FIRC trim source system OSC. */
#define FSL_FEATURE_SCG_HAS_FIRC_TRIMSRC_SOSC (1)
/* @brief Has FIRC trim source RTC OSC. */
#define FSL_FEATURE_SCG_HAS_FIRC_TRIMSRC_RTCOSC (0)

/* SIM module features */

/* @brief Has USB FS divider. */
#define FSL_FEATURE_SIM_USBFS_USE_SPECIAL_DIVIDER (0)
/* @brief Is PLL clock divided by 2 before MCG PLL/FLL clock selection. */
#define FSL_FEATURE_SIM_PLLCLK_USE_SPECIAL_DIVIDER (0)
/* @brief Has RAM size specification (register bit field SOPT1[RAMSIZE]). */
#define FSL_FEATURE_SIM_OPT_HAS_RAMSIZE (0)
/* @brief Has 32k oscillator clock output (register bit SOPT1[OSC32KOUT]). */
#define FSL_FEATURE_SIM_OPT_HAS_OSC32K_OUT (0)
/* @brief Has 32k oscillator clock selection (register bit field SOPT1[OSC32KSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_OSC32K_SELECTION (0)
/* @brief 32k oscillator clock selection width (width of register bit field SOPT1[OSC32KSEL]). */
#define FSL_FEATURE_SIM_OPT_OSC32K_SELECTION_WIDTH (0)
/* @brief Has RTC clock output selection (register bit SOPT2[RTCCLKOUTSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_RTC_CLOCK_OUT_SELECTION (0)
/* @brief Has USB voltage regulator (register bits SOPT1[USBVSTBY], SOPT1[USBSSTBY], SOPT1[USBREGEN], SOPT1CFG[URWE], SOPT1CFG[UVSWE], SOPT1CFG[USSWE]). */
#define FSL_FEATURE_SIM_OPT_HAS_USB_VOLTAGE_REGULATOR (0)
/* @brief USB has integrated PHY (register bits USBPHYCTL[USBVREGSEL], USBPHYCTL[USBVREGPD], USBPHYCTL[USB3VOUTTRG], USBPHYCTL[USBDISILIM], SOPT2[USBSLSRC], SOPT2[USBREGEN]). */
#define FSL_FEATURE_SIM_OPT_HAS_USB_PHY (0)
/* @brief Has PTD7 pad drive strength control (register bit SOPT2[PTD7PAD]). */
#define FSL_FEATURE_SIM_OPT_HAS_PTD7PAD (0)
/* @brief Has FlexBus security level selection (register bit SOPT2[FBSL]). */
#define FSL_FEATURE_SIM_OPT_HAS_FBSL (0)
/* @brief Has number of FlexBus hold cycle before FlexBus can release bus (register bit SOPT6[PCR]). */
#define FSL_FEATURE_SIM_OPT_HAS_PCR (0)
/* @brief Has number of NFC hold cycle in case of FlexBus request (register bit SOPT6[MCC]). */
#define FSL_FEATURE_SIM_OPT_HAS_MCC (0)
/* @brief Has UART open drain enable (register bits UARTnODE, where n is a number, in register SOPT5). */
#define FSL_FEATURE_SIM_OPT_HAS_ODE (0)
/* @brief Number of LPUART modules (number of register bits LPUARTn, where n is a number, in register SCGC5). */
#define FSL_FEATURE_SIM_OPT_LPUART_COUNT (0)
/* @brief Number of UART modules (number of register bits UARTn, where n is a number, in register SCGC4). */
#define FSL_FEATURE_SIM_OPT_UART_COUNT (0)
/* @brief Has UART0 open drain enable (register bit SOPT5[UART0ODE]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART0_ODE (0)
/* @brief Has UART1 open drain enable (register bit SOPT5[UART1ODE]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART1_ODE (0)
/* @brief Has UART2 open drain enable (register bit SOPT5[UART2ODE]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART2_ODE (0)
/* @brief Has LPUART0 open drain enable (register bit SOPT5[LPUART0ODE]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART0_ODE (0)
/* @brief Has LPUART1 open drain enable (register bit SOPT5[LPUART1ODE]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART1_ODE (0)
/* @brief Has CMT/UART pad drive strength control (register bit SOPT2[CMTUARTPAD]). */
#define FSL_FEATURE_SIM_OPT_HAS_CMTUARTPAD (0)
/* @brief Has LPUART0 transmit data source selection (register bit SOPT5[LPUART0TXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART0_TX_SRC (0)
/* @brief Has LPUART0 receive data source selection (register bit SOPT5[LPUART0RXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART0_RX_SRC (0)
/* @brief Has LPUART1 transmit data source selection (register bit SOPT5[LPUART1TXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART1_TX_SRC (0)
/* @brief Has LPUART1 receive data source selection (register bit SOPT5[LPUART1RXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART1_RX_SRC (0)
/* @brief Has UART0 transmit data source selection (register bit SOPT5[UART0TXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART0_TX_SRC (0)
/* @brief UART0 transmit data source selection width (width of register bit SOPT5[UART0TXSRC]). */
#define FSL_FEATURE_SIM_OPT_UART0_TX_SRC_WIDTH (0)
/* @brief Has UART0 receive data source selection (register bit SOPT5[UART0RXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART0_RX_SRC (0)
/* @brief UART0 receive data source selection width (width of register bit SOPT5[UART0RXSRC]). */
#define FSL_FEATURE_SIM_OPT_UART0_RX_SRC_WIDTH (0)
/* @brief Has UART1 transmit data source selection (register bit SOPT5[UART1TXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART1_TX_SRC (0)
/* @brief Has UART1 receive data source selection (register bit SOPT5[UART1RXSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART1_RX_SRC (0)
/* @brief UART1 receive data source selection width (width of register bit SOPT5[UART1RXSRC]). */
#define FSL_FEATURE_SIM_OPT_UART1_RX_SRC_WIDTH (0)
/* @brief Has FTM module(s) configuration. */
#define FSL_FEATURE_SIM_OPT_HAS_FTM (0)
/* @brief Number of FTM modules. */
#define FSL_FEATURE_SIM_OPT_FTM_COUNT (4)
/* @brief Number of FTM triggers with selectable source. */
#define FSL_FEATURE_SIM_OPT_FTM_TRIGGER_COUNT (0)
/* @brief Has FTM0 triggers source selection (register bits SOPT4[FTM0TRGnSRC], where n is a number). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM0_TRIGGER (0)
/* @brief Has FTM3 triggers source selection (register bits SOPT4[FTM3TRGnSRC], where n is a number). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM3_TRIGGER (0)
/* @brief Has FTM1 channel 0 input capture source selection (register bit SOPT4[FTM1CH0SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM1_CHANNELS (0)
/* @brief Has FTM2 channel 0 input capture source selection (register bit SOPT4[FTM2CH0SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM2_CHANNELS (0)
/* @brief Has FTM3 channel 0 input capture source selection (register bit SOPT4[FTM3CH0SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM3_CHANNELS (0)
/* @brief Has FTM2 channel 1 input capture source selection (register bit SOPT4[FTM2CH1SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM2_CHANNEL1 (0)
/* @brief Number of configurable FTM0 fault detection input (number of register bits SOPT4[FTM0FLTn], where n is a number starting from zero). */
#define FSL_FEATURE_SIM_OPT_FTM0_FAULT_COUNT (0)
/* @brief Number of configurable FTM1 fault detection input (number of register bits SOPT4[FTM1FLTn], where n is a number starting from zero). */
#define FSL_FEATURE_SIM_OPT_FTM1_FAULT_COUNT (0)
/* @brief Number of configurable FTM2 fault detection input (number of register bits SOPT4[FTM2FLTn], where n is a number starting from zero). */
#define FSL_FEATURE_SIM_OPT_FTM2_FAULT_COUNT (0)
/* @brief Number of configurable FTM3 fault detection input (number of register bits SOPT4[FTM3FLTn], where n is a number starting from zero). */
#define FSL_FEATURE_SIM_OPT_FTM3_FAULT_COUNT (0)
/* @brief Has FTM hardware trigger 0 software synchronization (register bit SOPT8[FTMnSYNCBIT], where n is a module instance index). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM_TRIGGER_SYNC (0)
/* @brief Has FTM channels output source selection (register bit SOPT8[FTMxOCHnSRC], where x is a module instance index and n is a channel index). */
#define FSL_FEATURE_SIM_OPT_HAS_FTM_CHANNELS_OUTPUT_SRC (0)
/* @brief Has TPM module(s) configuration. */
#define FSL_FEATURE_SIM_OPT_HAS_TPM (0)
/* @brief The highest TPM module index. */
#define FSL_FEATURE_SIM_OPT_MAX_TPM_INDEX (0)
/* @brief Has TPM module with index 0. */
#define FSL_FEATURE_SIM_OPT_HAS_TPM0 (0)
/* @brief Has TPM0 clock selection (register bit field SOPT4[TPM0CLKSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_TPM0_CLK_SEL (0)
/* @brief Is TPM channels configuration in the SOPT4 (not SOPT9) register (register bits TPMnCH0SRC, TPMnCLKSEL, where n is a module instance index). */
#define FSL_FEATURE_SIM_OPT_HAS_TPM_CHANNELS_CONFIG_IN_SOPT4_REG (0)
/* @brief Has TPM1 channel 0 input capture source selection (register bit field SOPT4[TPM1CH0SRC] or SOPT9[TPM1CH0SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_TPM1_CH0_SRC_SELECTION (0)
/* @brief Has TPM1 clock selection (register bit field SOPT4[TPM1CLKSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_TPM1_CLK_SEL (0)
/* @brief TPM1 channel 0 input capture source selection width (width of register bit field SOPT4[TPM1CH0SRC] or SOPT9[TPM1CH0SRC]). */
#define FSL_FEATURE_SIM_OPT_TPM1_CH0_SRC_SELECTION_WIDTH (0)
/* @brief Has TPM2 channel 0 input capture source selection (register bit field SOPT4[TPM2CH0SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_TPM2_CH0_SRC_SELECTION (0)
/* @brief Has TPM2 clock selection (register bit field SOPT4[TPM2CLKSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_TPM2_CLK_SEL (0)
/* @brief Has PLL/FLL clock selection (register bit field SOPT2[PLLFLLSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_PLL_FLL_SELECTION (0)
/* @brief PLL/FLL clock selection width (width of register bit field SOPT2[PLLFLLSEL]). */
#define FSL_FEATURE_SIM_OPT_PLL_FLL_SELECTION_WIDTH (0)
/* @brief Has NFC clock source selection (register bit SOPT2[NFCSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_NFCSRC (0)
/* @brief Has eSDHC clock source selection (register bit SOPT2[ESDHCSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_ESDHCSRC (0)
/* @brief Has SDHC clock source selection (register bit SOPT2[SDHCSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_SDHCSRC (0)
/* @brief Has LCDC clock source selection (register bits SOPT2[LCDCSRC], SOPT2[LCDC_CLKSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_LCDCSRC (0)
/* @brief Has ENET timestamp clock source selection (register bit SOPT2[TIMESRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_TIMESRC (0)
/* @brief Has ENET RMII clock source selection (register bit SOPT2[RMIISRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_RMIISRC (0)
/* @brief Has USB clock source selection (register bit SOPT2[USBSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_USBSRC (0)
/* @brief Has USB FS clock source selection (register bit SOPT2[USBFSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_USBFSRC (0)
/* @brief Has USB HS clock source selection (register bit SOPT2[USBHSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_USBHSRC (0)
/* @brief Has LPUART clock source selection (register bit SOPT2[LPUARTSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUARTSRC (0)
/* @brief Has LPUART0 clock source selection (register bit SOPT2[LPUART0SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART0SRC (0)
/* @brief Has LPUART1 clock source selection (register bit SOPT2[LPUART1SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_LPUART1SRC (0)
/* @brief Has FLEXIOSRC clock source selection (register bit SOPT2[FLEXIOSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_FLEXIOSRC (0)
/* @brief Has UART0 clock source selection (register bit SOPT2[UART0SRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_UART0SRC (0)
/* @brief Has TPM clock source selection (register bit SOPT2[TPMSRC]). */
#define FSL_FEATURE_SIM_OPT_HAS_TPMSRC (0)
/* @brief Has debug trace clock selection (register bit SOPT2[TRACECLKSEL]). */
#define FSL_FEATURE_SIM_OPT_HAS_TRACE_CLKSEL (0)
/* @brief Number of ADC modules (register bits SOPT7[ADCnTRGSEL], SOPT7[ADCnPRETRGSEL], SOPT7[ADCnALTTRGSEL], where n is a module instance index). */
#define FSL_FEATURE_SIM_OPT_ADC_COUNT (0)
/* @brief ADC module has alternate trigger (register bit SOPT7[ADC0ALTTRGEN]). */
#define FSL_FEATURE_SIM_OPT_ADC_HAS_ALTERNATE_TRIGGER (0)
/* @brief ADC0 alternate trigger enable width (width of bit field ADC0ALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_ADC0ALTTRGEN_WIDTH (0)
/* @brief ADC1 alternate trigger enable width (width of bit field ADC1ALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_ADC1ALTTRGEN_WIDTH (0)
/* @brief ADC2 alternate trigger enable width (width of bit field ADC2ALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_ADC2ALTTRGEN_WIDTH (0)
/* @brief ADC3 alternate trigger enable width (width of bit field ADC3ALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_ADC3ALTTRGEN_WIDTH (0)
/* @brief HSADC0 converter A alternate trigger enable width (width of bit field HSADC0AALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_HSADC0AALTTRGEN_WIDTH (0)
/* @brief HSADC1 converter A alternate trigger enable width (width of bit field HSADC1AALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_HSADC1AALTTRGEN_WIDTH (0)
/* @brief ADC converter A alternate trigger enable width (width of bit field ADCAALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_ADCAALTTRGEN_WIDTH (0)
/* @brief HSADC0 converter B alternate trigger enable width (width of bit field HSADC0BALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_HSADC0BALTTRGEN_WIDTH (0)
/* @brief HSADC1 converter B alternate trigger enable width (width of bit field HSADC1BALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_HSADC1BALTTRGEN_WIDTH (0)
/* @brief ADC converter B alternate trigger enable width (width of bit field ADCBALTTRGEN of register SOPT7). */
#define FSL_FEATURE_SIM_OPT_ADCBALTTRGEN_WIDTH (0)
/* @brief Has clock 2 output divider (register bit field CLKDIV1[OUTDIV2]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_OUTDIV2 (0)
/* @brief Has clock 3 output divider (register bit field CLKDIV1[OUTDIV3]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_OUTDIV3 (0)
/* @brief Has clock 4 output divider (register bit field CLKDIV1[OUTDIV4]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_OUTDIV4 (0)
/* @brief Clock 4 output divider width (width of register bit field CLKDIV1[OUTDIV4]). */
#define FSL_FEATURE_SIM_DIVIDER_OUTDIV4_WIDTH (0)
/* @brief Has clock 5 output divider (register bit field CLKDIV1[OUTDIV5]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_OUTDIV5 (0)
/* @brief Has USB clock divider (register bit field CLKDIV2[USBDIV] and CLKDIV2[USBFRAC]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_USBDIV (0)
/* @brief Has USB FS clock divider (register bit field CLKDIV2[USBFSDIV] and CLKDIV2[USBFSFRAC]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_USBFSDIV (0)
/* @brief Has USB HS clock divider (register bit field CLKDIV2[USBHSDIV] and CLKDIV2[USBHSFRAC]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_USBHSDIV (0)
/* @brief Has PLL/FLL clock divider (register bit field CLKDIV3[PLLFLLDIV] and CLKDIV3[PLLFLLFRAC]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_PLLFLLDIV (0)
/* @brief Has LCDC clock divider (register bit field CLKDIV3[LCDCDIV] and CLKDIV3[LCDCFRAC]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_LCDCDIV (0)
/* @brief Has trace clock divider (register bit field CLKDIV4[TRACEDIV] and CLKDIV4[TRACEFRAC]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_TRACEDIV (1)
/* @brief Has NFC clock divider (register bit field CLKDIV4[NFCDIV] and CLKDIV4[NFCFRAC]). */
#define FSL_FEATURE_SIM_DIVIDER_HAS_NFCDIV (0)
/* @brief Has Kinetis family ID (register bit field SDID[FAMILYID]). */
#define FSL_FEATURE_SIM_SDID_HAS_FAMILYID (0)
/* @brief Has Kinetis family ID (register bit field SDID[FAMID]). */
#define FSL_FEATURE_SIM_SDID_HAS_FAMID (0)
/* @brief Has Kinetis sub-family ID (register bit field SDID[SUBFAMID]). */
#define FSL_FEATURE_SIM_SDID_HAS_SUBFAMID (0)
/* @brief Has Kinetis series ID (register bit field SDID[SERIESID]). */
#define FSL_FEATURE_SIM_SDID_HAS_SERIESID (0)
/* @brief Has device die ID (register bit field SDID[DIEID]). */
#define FSL_FEATURE_SIM_SDID_HAS_DIEID (0)
/* @brief Has system SRAM size specifier (register bit field SDID[SRAMSIZE]). */
#define FSL_FEATURE_SIM_SDID_HAS_SRAMSIZE (0)
/* @brief Has flash mode (register bit FCFG1[FLASHDOZE]). */
#define FSL_FEATURE_SIM_FCFG_HAS_FLASHDOZE (0)
/* @brief Has flash disable (register bit FCFG1[FLASHDIS]). */
#define FSL_FEATURE_SIM_FCFG_HAS_FLASHDIS (0)
/* @brief Has FTFE disable (register bit FCFG1[FTFDIS]). */
#define FSL_FEATURE_SIM_FCFG_HAS_FTFDIS (0)
/* @brief Has FlexNVM size specifier (register bit field FCFG1[NVMSIZE]). */
#define FSL_FEATURE_SIM_FCFG_HAS_NVMSIZE (0)
/* @brief Has EEPROM size specifier (register bit field FCFG1[EESIZE]). */
#define FSL_FEATURE_SIM_FCFG_HAS_EESIZE (0)
/* @brief Has FlexNVM partition (register bit field FCFG1[DEPART]). */
#define FSL_FEATURE_SIM_FCFG_HAS_DEPART (1)
/* @brief Has flash for core0(CM4) (register bit field FCFG1[CORE0_PFSIZE]). */
#define FSL_FEATURE_SIM_FCFG_HAS_CORE0_PFSIZE (0)
/* @brief Has flash for core1(CM0) (register bit field FCFG1[CORE1_PFSIZE]). */
#define FSL_FEATURE_SIM_FCFG_HAS_CORE1_PFSIZE (0)
/* @brief Has sram for core0(CM4) (register bit field FCFG1[CORE0_SRAMSIZE]). */
#define FSL_FEATURE_SIM_FCFG_HAS_CORE0_SRAMSIZE (0)
/* @brief Has sram for core1(CM0) (register bit field FCFG1[CORE1_SRAMSIZE]). */
#define FSL_FEATURE_SIM_FCFG_HAS_CORE1_SRAMSIZE (0)
/* @brief Maximum flash address block 0 address specifier (register bit field FCFG2[MAXADDR0]). */
#define FSL_FEATURE_SIM_FCFG_HAS_MAXADDR0 (0)
/* @brief Maximum flash address block 1 address specifier (register bit field FCFG2[MAXADDR1]). */
#define FSL_FEATURE_SIM_FCFG_HAS_MAXADDR1 (0)
/* @brief Maximum flash address block 0 or 1 address specifier (register bit field FCFG2[MAXADDR01]). */
#define FSL_FEATURE_SIM_FCFG_HAS_MAXADDR01 (0)
/* @brief Maximum flash address block 2 or 3 address specifier (register bit field FCFG2[MAXADDR23]). */
#define FSL_FEATURE_SIM_FCFG_HAS_MAXADDR23 (0)
/* @brief Has program flash availability specifier (register bit FCFG2[PFLSH]). */
#define FSL_FEATURE_SIM_FCFG_HAS_PFLSH (0)
/* @brief Has program flash swapping (register bit FCFG2[SWAPPFLSH]). */
#define FSL_FEATURE_SIM_FCFG_HAS_PFLSH_SWAP (0)
/* @brief Has miscellanious control register (register MCR). */
#define FSL_FEATURE_SIM_HAS_MISC_CONTROLS (0)
/* @brief Has COP watchdog (registers COPC and SRVCOP). */
#define FSL_FEATURE_SIM_HAS_COP_WATCHDOG (0)
/* @brief Has COP watchdog stop (register bits COPC[COPSTPEN], COPC[COPDBGEN] and COPC[COPCLKSEL]). */
#define FSL_FEATURE_SIM_HAS_COP_STOP (0)
/* @brief Has LLWU clock gate bit (e.g SIM_SCGC4). */
#define FSL_FEATURE_SIM_HAS_SCGC_LLWU (0)
/* @brief Has MISCCTRL reg. */
#define FSL_FEATURE_SIM_HAS_MISCCTRL (0)
/* @brief Has LTCEN bit (e.g SIM_MISCCTRL). */
#define FSL_FEATURE_SIM_HAS_MISCCTRL_LTCEN (0)
/* @brief Has DMAINTSEL0 bit (e.g SIM_MISCCTRL). */
#define FSL_FEATURE_SIM_HAS_MISCCTRL_DMAINTSEL0 (0)
/* @brief Has DMAINTSEL1 bit (e.g SIM_MISCCTRL). */
#define FSL_FEATURE_SIM_HAS_MISCCTRL_DMAINTSEL1 (0)
/* @brief Has DMAINTSEL2 bit (e.g SIM_MISCCTRL). */
#define FSL_FEATURE_SIM_HAS_MISCCTRL_DMAINTSEL2 (0)
/* @brief Has DMAINTSEL3 bit (e.g SIM_MISCCTRL). */
#define FSL_FEATURE_SIM_HAS_MISCCTRL_DMAINTSEL3 (0)
/* @brief Has SECKEY0 reg. */
#define FSL_FEATURE_SIM_HAS_SECKEY0 (0)
/* @brief Has SECKEY bit (e.g SIM_SECKEY0). */
#define FSL_FEATURE_SIM_HAS_SECKEY0_SECKEY (0)
/* @brief Has SECKEY1 reg. */
#define FSL_FEATURE_SIM_HAS_SECKEY1 (0)
/* @brief Has SECKEY bit (e.g SIM_SECKEY1). */
#define FSL_FEATURE_SIM_HAS_SECKEY1_SECKEY (0)
/* @brief Has SECKEY2 reg. */
#define FSL_FEATURE_SIM_HAS_SECKEY2 (0)
/* @brief Has SECKEY bit (e.g SIM_SECKEY2). */
#define FSL_FEATURE_SIM_HAS_SECKEY2_SECKEY (0)
/* @brief Has SECKEY3 reg. */
#define FSL_FEATURE_SIM_HAS_SECKEY3 (0)
/* @brief Has SECKEY bit (e.g SIM_SECKEY3). */
#define FSL_FEATURE_SIM_HAS_SECKEY3_SECKEY (0)
/* @brief Has no SDID reg. */
#define FSL_FEATURE_SIM_HAS_NO_SDID (0)
/* @brief Has no UID reg. */
#define FSL_FEATURE_SIM_HAS_NO_UID (0)
/* @brief Has RFADDRL and RFADDRH registers. */
#define FSL_FEATURE_SIM_HAS_RF_MAC_ADDR (0)
/* @brief Has SYSTICK_CLK_EN bit in SIM_MISC2 register. */
#define FSL_FEATURE_SIM_MISC2_HAS_SYSTICK_CLK_EN (0)
/* @brief Has UIDH registers. */
#define FSL_FEATURE_SIM_HAS_UIDH (1)
/* @brief Has UIDM registers. */
#define FSL_FEATURE_SIM_HAS_UIDM (0)
/* @brief Supports software trigger (MISCTRL1[SW_TRG]). */
#define FSL_FEATURE_SIM_HAS_SW_TRG (1)

/* SMC module features */

/* @brief Has partial stop option (register bit STOPCTRL[PSTOPO]). */
#define FSL_FEATURE_SMC_HAS_PSTOPO (1)
/* @brief Has LPO power option (register bit STOPCTRL[LPOPO]). */
#define FSL_FEATURE_SMC_HAS_LPOPO (0)
/* @brief Has POR power option (register bit STOPCTRL[PORPO] or VLLSCTRL[PORPO]). */
#define FSL_FEATURE_SMC_HAS_PORPO (0)
/* @brief Has low power wakeup on interrupt (register bit PMCTRL[LPWUI]). */
#define FSL_FEATURE_SMC_HAS_LPWUI (0)
/* @brief Has LLS or VLLS mode control (register bit STOPCTRL[LLSM]). */
#define FSL_FEATURE_SMC_HAS_LLS_SUBMODE (0)
/* @brief Has VLLS mode control (register bit VLLSCTRL[VLLSM]). */
#define FSL_FEATURE_SMC_USE_VLLSCTRL_REG (0)
/* @brief Has VLLS mode control (register bit STOPCTRL[VLLSM]). */
#define FSL_FEATURE_SMC_USE_STOPCTRL_VLLSM (0)
/* @brief Has RAM partition 2 power option (register bit STOPCTRL[RAM2PO]). */
#define FSL_FEATURE_SMC_HAS_RAM2_POWER_OPTION (0)
/* @brief Has high speed run mode (register bit PMPROT[AHSRUN]). */
#define FSL_FEATURE_SMC_HAS_HIGH_SPEED_RUN_MODE (1)
/* @brief Has low leakage stop mode (register bit PMPROT[ALLS]). */
#define FSL_FEATURE_SMC_HAS_LOW_LEAKAGE_STOP_MODE (0)
/* @brief Has very low leakage stop mode (register bit PMPROT[AVLLS]). */
#define FSL_FEATURE_SMC_HAS_VERY_LOW_LEAKAGE_STOP_MODE (0)
/* @brief Has stop submode. */
#define FSL_FEATURE_SMC_HAS_SUB_STOP_MODE (0)
/* @brief Has stop submode 0(state VLLS0 of register bit STOPCTRL[VLLSM]). */
#define FSL_FEATURE_SMC_HAS_STOP_SUBMODE0 (0)
/* @brief Has stop submode 2(state VLLS2 of register bit STOPCTRL[VLLSM]). */
#define FSL_FEATURE_SMC_HAS_STOP_SUBMODE2 (0)
/* @brief Has SMC_PARAM. */
#define FSL_FEATURE_SMC_HAS_PARAM (1)
/* @brief Has SMC_VERID. */
#define FSL_FEATURE_SMC_HAS_VERID (1)
/* @brief Has stop abort flag (register bit PMCTRL[STOPA]). */
#define FSL_FEATURE_SMC_HAS_PMCTRL_STOPA (1)
/* @brief Has tamper reset (register bit SRS[TAMPER]). */
#define FSL_FEATURE_SMC_HAS_SRS_TAMPER (0)
/* @brief Has security violation reset (register bit SRS[SECVIO]). */
#define FSL_FEATURE_SMC_HAS_SRS_SECVIO (0)
/* @brief Width of SMC registers. */
#define FSL_FEATURE_SMC_REG_WIDTH (32)
/* @brief Is affected by errata with ID 011063 (SMC: An asynchronous wakeup event during VLPS mode entry may result in possible system hang scenario). */
#define FSL_FEATURE_SMC_HAS_ERRATA_011063 (1)

/* SYSMPU module features */

/* @brief Specifies number of descriptors available. */
#define FSL_FEATURE_SYSMPU_DESCRIPTOR_COUNT (8)
/* @brief Has process identifier support. */
#define FSL_FEATURE_SYSMPU_HAS_PROCESS_IDENTIFIER (1)
/* @brief Total number of MPU slave. */
#define FSL_FEATURE_SYSMPU_SLAVE_COUNT (4)
/* @brief Total number of MPU master. */
#define FSL_FEATURE_SYSMPU_MASTER_COUNT (4)

/* SysTick module features */

/* @brief Systick has external reference clock. */
#define FSL_FEATURE_SYSTICK_HAS_EXT_REF (0)
/* @brief Systick external reference clock is core clock divided by this value. */
#define FSL_FEATURE_SYSTICK_EXT_REF_CORE_DIV (0)

/* TRGMUX module features */

/* No feature definitions */

/* WDOG module features */

/* @brief Watchdog is available. */
#define FSL_FEATURE_WDOG_HAS_WATCHDOG (1)
/* @brief WDOG_CNT can be 32-bit written. */
#define FSL_FEATURE_WDOG_HAS_32BIT_ACCESS (1)

#endif /* _MCXE245_FEATURES_H_ */

