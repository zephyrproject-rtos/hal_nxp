/*
** ###################################################################
**     Version:             rev. 0.1, 2021-02-26
**     Build:               b230919
**
**     Abstract:
**         Chip specific module features.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2023 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2021-02-26)
**         Initial version.
**
** ###################################################################
*/

#ifndef _MC56F84567_FEATURES_H_
#define _MC56F84567_FEATURES_H_

/* SOC module features */

/* @brief AOI availability on the SoC. */
#define FSL_FEATURE_SOC_AOI_COUNT (1)
/* @brief CADC availability on the SoC. */
#define FSL_FEATURE_SOC_CADC_COUNT (1)
/* @brief CMP availability on the SoC. */
#define FSL_FEATURE_SOC_CMP_COUNT (4)
/* @brief COP availability on the SoC. */
#define FSL_FEATURE_SOC_COP_COUNT (1)
/* @brief CRC availability on the SoC. */
#define FSL_FEATURE_SOC_CRC_COUNT (1)
/* @brief DMA availability on the SoC. */
#define FSL_FEATURE_SOC_DMA_COUNT (1)
/* @brief EWM availability on the SoC. */
#define FSL_FEATURE_SOC_EWM_COUNT (1)
/* @brief FLEXCAN availability on the SoC. */
#define FSL_FEATURE_SOC_FLEXCAN_COUNT (1)
/* @brief FMC availability on the SoC. */
#define FSL_FEATURE_SOC_FMC_COUNT (1)
/* @brief FTFL availability on the SoC. */
#define FSL_FEATURE_SOC_FTFL_COUNT (1)
/* @brief GPIO availability on the SoC. */
#define FSL_FEATURE_SOC_GPIO_COUNT (7)
/* @brief I2C availability on the SoC. */
#define FSL_FEATURE_SOC_I2C_COUNT (2)
/* @brief INTC availability on the SoC. */
#define FSL_FEATURE_SOC_INTC_COUNT (1)
/* @brief MCM availability on the SoC. */
#define FSL_FEATURE_SOC_MCM_COUNT (1)
/* @brief OCCS availability on the SoC. */
#define FSL_FEATURE_SOC_OCCS_COUNT (1)
/* @brief PDB availability on the SoC. */
#define FSL_FEATURE_SOC_PDB_COUNT (2)
/* @brief PIT availability on the SoC. */
#define FSL_FEATURE_SOC_PIT_COUNT (2)
/* @brief PMC availability on the SoC. */
#define FSL_FEATURE_SOC_PMC_COUNT (1)
/* @brief PWM availability on the SoC. */
#define FSL_FEATURE_SOC_PWM_COUNT (2)
/* @brief QSCI availability on the SoC. */
#define FSL_FEATURE_SOC_QSCI_COUNT (3)
/* @brief QSPI availability on the SoC. */
#define FSL_FEATURE_SOC_QSPI_COUNT (3)
/* @brief SIM availability on the SoC. */
#define FSL_FEATURE_SOC_SIM_COUNT (1)
/* @brief TMR availability on the SoC. */
#define FSL_FEATURE_SOC_TMR_COUNT (2)
/* @brief XBARA availability on the SoC. */
#define FSL_FEATURE_SOC_XBARA_COUNT (1)
/* @brief XBARB availability on the SoC. */
#define FSL_FEATURE_SOC_XBARB_COUNT (1)

/* CADC module features */

/* @brief register RSLT2 count. */
#define FSL_FEATURE_CADC_RSLT2_COUNT (0)
/* @brief No auto standby (register bit PWR[ASB]). */
#define FSL_FEATURE_CADC_NO_AUTO_STANDBY (0)
/* @brief No speedmode bit (register bits PWR2[SPEEDA]). */
#define FSL_FEATURE_CADC_NO_SPEEDMODE_BIT (0)
/* @brief No sample window (register bit CTRL3[SCNT0]). */
#define FSL_FEATURE_CADC_NO_SAMPLE_WINDOW (0)
/* @brief Has unipolar differential mode (register bit CTRL3[UPDEN_L]). */
#define FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE (0)
/* @brief Has expansion mux for additional channels. */
#define FSL_FEATURE_CADC_HAS_EXP_MUX_AUX (0)
/* @brief Has mux selection bitfields in expansion MUX control registers */
#define FSL_FEATURE_CADC_HAS_EXP_MUX_SEL (0)

/* FLEXCAN module features */

/* @brief Message buffer size */
#define FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(x) (16)
/* @brief Has doze mode support (register bit field MCR[DOZE]). */
#define FSL_FEATURE_FLEXCAN_HAS_DOZE_MODE_SUPPORT (1)
/* @brief Insatnce has doze mode support (register bit field MCR[DOZE]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_DOZE_MODE_SUPPORTn(x) (1)
/* @brief Has a glitch filter on the receive pin (register bit field MCR[WAKSRC]). */
#define FSL_FEATURE_FLEXCAN_HAS_GLITCH_FILTER (1)
/* @brief Has extended interrupt mask and flag register (register IMASK2, IFLAG2). */
#define FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER (0)
/* @brief Instance has extended bit timing register (register CBT). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_EXTENDED_TIMING_REGISTERn(x) (0)
/* @brief Has a receive FIFO DMA feature (register bit field MCR[DMA]). */
#define FSL_FEATURE_FLEXCAN_HAS_RX_FIFO_DMA (0)
/* @brief Instance has a receive FIFO DMA feature (register bit field MCR[DMA]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_RX_FIFO_DMAn(x) (0)
/* @brief Remove CAN Engine Clock Source Selection from unsupported part. */
#define FSL_FEATURE_FLEXCAN_SUPPORT_ENGINE_CLK_SEL_REMOVE (0)
/* @brief Instance remove CAN Engine Clock Source Selection from unsupported part. */
#define FSL_FEATURE_FLEXCAN_INSTANCE_SUPPORT_ENGINE_CLK_SEL_REMOVEn(x) (0)
/* @brief Is affected by errata with ID 5641 (Module does not transmit a message that is enabled to be transmitted at a specific moment during the arbitration process). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641 (0)
/* @brief Is affected by errata with ID 5829 (FlexCAN: FlexCAN does not transmit a message that is enabled to be transmitted in a specific moment during the arbitration process). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829 (1)
/* @brief Is affected by errata with ID 6032 (FlexCAN: A frame with wrong ID or payload is transmitted into the CAN bus when the Message Buffer under transmission is either aborted or deactivated while the CAN bus is in the Bus Idle state). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_6032 (1)
/* @brief Is affected by errata with ID 9595 (FlexCAN: Corrupt frame possible if the Freeze Mode or the Low-Power Mode are entered during a Bus-Off state). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_9595 (0)
/* @brief Has CAN with Flexible Data rate (CAN FD) protocol. */
#define FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE (0)
/* @brief CAN instance support Flexible Data rate (CAN FD) protocol. */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_FLEXIBLE_DATA_RATEn(x) (0)
/* @brief Has extra MB interrupt or common one. */
#define FSL_FEATURE_FLEXCAN_HAS_EXTRA_MB_INT (1)
/* @brief Has memory error control (register MECR). */
#define FSL_FEATURE_FLEXCAN_HAS_MEMORY_ERROR_CONTROL (0)

/* CMP module features */

/* @brief Has Trigger mode in CMP (register bit field CR1[TRIGM]). */
#define FSL_FEATURE_CMP_HAS_TRIGGER_MODE (0)
/* @brief Has Window mode in CMP (register bit field CR1[WE]). */
#define FSL_FEATURE_CMP_HAS_WINDOW_MODE (1)
/* @brief Has External sample supported in CMP (register bit field CR1[SE]). */
#define FSL_FEATURE_CMP_HAS_EXTERNAL_SAMPLE_SUPPORT (1)
/* @brief Has DMA support in CMP (register bit field SCR[DMAEN]). */
#define FSL_FEATURE_CMP_HAS_DMA (0)
/* @brief Has Pass Through mode in CMP (register bit field MUXCR[PSTM]). */
#define FSL_FEATURE_CMP_HAS_PASS_THROUGH_MODE (0)
/* @brief Has DAC Test function in CMP (register DACTEST). */
#define FSL_FEATURE_CMP_HAS_DAC_TEST (0)
/* @brief Has COUTA out of window is zero enable. */
#define FSL_FEATURE_CMP_HAS_COWZ_BIT_FIELD (0)
/* @brief Use 16 bit registers. */
#define FSL_FEATURE_CMP_USE_16BIT_REG (1)

/* COP module features */

/* @brief If COP has WINDOW register */
#define FSL_FEATURE_COP_HAS_WINDOW_REGISTER (0)

/* CRC module features */

/* @brief If CRC has CRC register */
#define FSL_FEATURE_CRC_HAS_CRC_REGISTER (1)
/* @brief CRC16 type of the peripheral. */
#define FSL_FEATURE_CRC_CRC16_TYPE (0)

/* DMA module features */

/* @brief Number of DMA channels. */
#define FSL_FEATURE_DMA_MODULE_CHANNEL (4)
/* @brief Total number of DMA channels on all modules. */
#define FSL_FEATURE_DMA_DMAMUX_CHANNELS (0)

/* EWM module features */

/* @brief Has clock select (register CLKCTRL). */
#define FSL_FEATURE_EWM_HAS_CLOCK_SELECT (1)
/* @brief Has clock prescaler (register CLKPRESCALER). */
#define FSL_FEATURE_EWM_HAS_PRESCALER (1)

/* FTFL module features */

/* @brief Is of type FTFL. */
#define FSL_FEATURE_FTFL_TYPE (1)
/* @brief Has flags indicating the status of the FlexRAM (register bits FCNFG[EEERDY], FCNFG[RAMRDY] and FCNFG[PFLSH]). */
#define FSL_FEATURE_FTFL_HAS_FLEX_RAM_FLAGS (1)
/* @brief Has program flash swapping status flag (register bit FCNFG[SWAP]). */
#define FSL_FEATURE_FTFL_HAS_PFLASH_SWAPPING_STATUS_FLAG (0)
/* @brief Has EEPROM region protection (register FEPROT). */
#define FSL_FEATURE_FTFL_HAS_EEROM_REGION_PROTECTION (1)
/* @brief Has data flash region protection (register FDPROT). */
#define FSL_FEATURE_FTFL_HAS_DATA_FLASH_REGION_PROTECTION (1)
/* @brief Has flash access control (registers XACCHn, SACCHn, where n is a number, FACSS and FACSN). */
#define FSL_FEATURE_FTFL_HAS_ACCESS_CONTROL (0)
/* @brief Has flash cache control in FMC module. */
#define FSL_FEATURE_FTFL_HAS_FMC_FLASH_CACHE_CONTROLS (0)
/* @brief Has flash cache control in MCM module. */
#define FSL_FEATURE_FTFL_HAS_MCM_FLASH_CACHE_CONTROLS (1)
/* @brief Has flash cache control in MSCM module. */
#define FSL_FEATURE_FTFL_HAS_MSCM_FLASH_CACHE_CONTROLS (0)
/* @brief Has prefetch speculation control in flash. */
#define FSL_FEATURE_FTFL_HAS_PREFETCH_SPECULATION_CONTROL_IN_FLASH (1)
/* @brief P-Flash flash size coding rule version, value 0 for K1 and K2, value 1 for K3. */
#define FSL_FEATURE_FTFL_SIZE_ENCODING_RULE_VERSION (0)
/* @brief P-Flash start address. */
#define FSL_FEATURE_FTFL_PFLASH_START_ADDRESS (0x00000000)
/* @brief P-Flash block count. */
#define FSL_FEATURE_FTFL_PFLASH_BLOCK_COUNT (1)
/* @brief P-Flash block size. */
#define FSL_FEATURE_FTFL_PFLASH_BLOCK_SIZE (131072UL)
/* @brief P-Flash sector size. */
#define FSL_FEATURE_FTFL_PFLASH_BLOCK_SECTOR_SIZE (2048U)
/* @brief P-Flash write unit size. */
#define FSL_FEATURE_FTFL_PFLASH_BLOCK_WRITE_UNIT_SIZE (4)
/* @brief P-Flash data path width. */
#define FSL_FEATURE_FTFL_PFLASH_BLOCK_DATA_PATH_WIDTH (4)
/* @brief P-Flash block swap feature. */
#define FSL_FEATURE_FTFL_HAS_PFLASH_BLOCK_SWAP (0)
/* @brief P-Flash protection region count. */
#define FSL_FEATURE_FTFL_PFLASH_PROTECTION_REGION_COUNT (32)
/* @brief Has FlexNVM memory. */
#define FSL_FEATURE_FTFL_HAS_FLEX_NVM (0)
/* @brief FlexNVM start address. (Valid only if FlexNVM is available.) */
#define FSL_FEATURE_FTFL_FLEX_NVM_START_ADDRESS (0x00000000UL)
/* @brief FlexNVM block count. */
#define FSL_FEATURE_FTFL_FLEX_NVM_BLOCK_COUNT (0)
/* @brief FlexNVM block size. */
#define FSL_FEATURE_FTFL_FLEX_NVM_BLOCK_SIZE (0)
/* @brief FlexNVM sector size. */
#define FSL_FEATURE_FTFL_FLEX_NVM_BLOCK_SECTOR_SIZE (0)
/* @brief FlexNVM write unit size. */
#define FSL_FEATURE_FTFL_FLEX_NVM_BLOCK_WRITE_UNIT_SIZE (0)
/* @brief FlexNVM data path width. */
#define FSL_FEATURE_FTFL_FLEX_BLOCK_DATA_PATH_WIDTH (0)
/* @brief Has FlexRAM memory. */
#define FSL_FEATURE_FTFL_HAS_FLEX_RAM (1)
/* @brief FlexRAM start address. (Valid only if FlexRAM is available.) */
#define FSL_FEATURE_FTFL_FLEX_RAM_START_ADDRESS (0x14000000UL)
/* @brief FlexRAM size. */
#define FSL_FEATURE_FTFL_FLEX_RAM_SIZE (2048)
/* @brief Has 0x00 Read 1s Block command. */
#define FSL_FEATURE_FTFL_HAS_READ_1S_BLOCK_CMD (0)
/* @brief Has 0x01 Read 1s Section command. */
#define FSL_FEATURE_FTFL_HAS_READ_1S_SECTION_CMD (1)
/* @brief Has 0x02 Program Check command. */
#define FSL_FEATURE_FTFL_HAS_PROGRAM_CHECK_CMD (1)
/* @brief Has 0x03 Read Resource command. */
#define FSL_FEATURE_FTFL_HAS_READ_RESOURCE_CMD (1)
/* @brief Has 0x06 Program Longword command. */
#define FSL_FEATURE_FTFL_HAS_PROGRAM_LONGWORD_CMD (1)
/* @brief Has 0x07 Program Phrase command. */
#define FSL_FEATURE_FTFL_HAS_PROGRAM_PHRASE_CMD (0)
/* @brief Has 0x08 Erase Flash Block command. */
#define FSL_FEATURE_FTFL_HAS_ERASE_FLASH_BLOCK_CMD (0)
/* @brief Has 0x09 Erase Flash Sector command. */
#define FSL_FEATURE_FTFL_HAS_ERASE_FLASH_SECTOR_CMD (1)
/* @brief Has 0x0B Program Section command. */
#define FSL_FEATURE_FTFL_HAS_PROGRAM_SECTION_CMD (1)
/* @brief Has 0x40 Read 1s All Blocks command. */
#define FSL_FEATURE_FTFL_HAS_READ_1S_ALL_BLOCKS_CMD (1)
/* @brief Has 0x41 Read Once command. */
#define FSL_FEATURE_FTFL_HAS_READ_ONCE_CMD (1)
/* @brief Has 0x43 Program Once command. */
#define FSL_FEATURE_FTFL_HAS_PROGRAM_ONCE_CMD (1)
/* @brief Has 0x44 Erase All Blocks command. */
#define FSL_FEATURE_FTFL_HAS_ERASE_ALL_BLOCKS_CMD (1)
/* @brief Has 0x45 Verify Backdoor Access Key command. */
#define FSL_FEATURE_FTFL_HAS_VERIFY_BACKDOOR_ACCESS_KEY_CMD (1)
/* @brief Has 0x46 Swap Control command. */
#define FSL_FEATURE_FTFL_HAS_SWAP_CONTROL_CMD (1)
/* @brief Has 0x49 Erase All Blocks Unsecure command. */
#define FSL_FEATURE_FTFL_HAS_ERASE_ALL_BLOCKS_UNSECURE_CMD (0)
/* @brief Has 0x4A Read 1s All Execute-only Segments command. */
#define FSL_FEATURE_FTFL_HAS_READ_1S_ALL_EXECUTE_ONLY_SEGMENTS_CMD (0)
/* @brief Has 0x4B Erase All Execute-only Segments command. */
#define FSL_FEATURE_FTFL_HAS_ERASE_ALL_EXECUTE_ONLY_SEGMENTS_CMD (0)
/* @brief Has 0x80 Program Partition command. */
#define FSL_FEATURE_FTFL_HAS_PROGRAM_PARTITION_CMD (0)
/* @brief Has 0x81 Set FlexRAM Function command. */
#define FSL_FEATURE_FTFL_HAS_SET_FLEXRAM_FUNCTION_CMD (0)
/* @brief P-Flash Erase/Read 1st all block command address alignment. */
#define FSL_FEATURE_FTFL_PFLASH_BLOCK_CMD_ADDRESS_ALIGMENT (4)
/* @brief P-Flash Erase sector command address alignment. */
#define FSL_FEATURE_FTFL_PFLASH_SECTOR_CMD_ADDRESS_ALIGMENT (4)
/* @brief P-Flash Rrogram/Verify section command address alignment. */
#define FSL_FEATURE_FTFL_PFLASH_SECTION_CMD_ADDRESS_ALIGMENT (8)
/* @brief P-Flash Read resource command address alignment. */
#define FSL_FEATURE_FTFL_PFLASH_RESOURCE_CMD_ADDRESS_ALIGMENT (4)
/* @brief P-Flash Program check command address alignment. */
#define FSL_FEATURE_FTFL_PFLASH_CHECK_CMD_ADDRESS_ALIGMENT (4)
/* @brief P-Flash swap control command address alignment. */
#define FSL_FEATURE_FTFL_PFLASH_SWAP_CONTROL_CMD_ADDRESS_ALIGMENT (0)

/* I2C module features */

/* @brief Has System Management Bus support (registers SMB, A2, SLTL and SLTH). */
#define FSL_FEATURE_I2C_HAS_SMBUS (1)
/* @brief Has DMA support (register bit C1[DMAEN]). */
#define FSL_FEATURE_I2C_HAS_DMA_SUPPORT (1)
/* @brief Has I2C bus start and stop detection (register bits FLT[SSIE], FLT[STARTF] and FLT[STOPF]). */
#define FSL_FEATURE_I2C_HAS_START_STOP_DETECT (1)
/* @brief Has I2C bus stop hold off (register bit FLT[SHEN]). */
#define FSL_FEATURE_I2C_HAS_STOP_HOLD_OFF (1)
/* @brief Has slave baud rate control (register bit C2[SBRC]). */
#define FSL_FEATURE_I2C_NO_SBRC (0)
/* @brief Maximum width of the glitch filter in number of bus clocks. */
#define FSL_FEATURE_I2C_MAX_GLITCH_FILTER_WIDTH (7)
/* @brief Has control of the drive capability of the I2C pins. */
#define FSL_FEATURE_I2C_HAS_HIGH_DRIVE_SELECTION (1)

/* MCM module features */

/* @brief If MCM has UBROMBAR register. */
#define FSL_FEATURE_MCM_HAS_UBROMBAR_REGISTER (0)
/* @brief If MCM CFISR register has CFEDL bit field. */
#define FSL_FEATURE_MCM_CFISR_HAS_CFEDL_BIT_FIELD (0)
/* @brief If MCM CPCR register has FCCCLR bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_FCCCLR_BIT_FIELD (0)
/* @brief If MCM CPCR register has FCDCDIS bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_FCDCDIS_BIT_FIELD (0)
/* @brief If MCM CPCR register has FCICDIS bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_FCICDIS_BIT_FIELD (0)
/* @brief If MCM CPCR register has FCCDIS bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_FCCDIS_BIT_FIELD (0)
/* @brief If MCM CPCR register has FCDSPDIS bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_FCDSPDIS_BIT_FIELD (0)
/* @brief If MCM CPCR register has FCSPDIS bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_FCSPDIS_BIT_FIELD (0)
/* @brief If MCM CPCR register has FCSDIS bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_FCSDIS_BIT_FIELD (0)
/* @brief If MCM CPCR register has XBARARB bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_XBARARB_BIT_FIELD (1)

/* PIT module features */

/* @brief If PIT use 32bit counter */
#define FSL_FEATURE_PIT_32BIT_COUNTER (0)
/* @brief If PIT CTRL register has PRESET_POLARITY bit field */
#define FSL_FEATURE_PIT_CTRL_HAS_PRESET_POLARITY_BIT (0)
/* @brief If PIT has FILT register */
#define FSL_FEATURE_PIT_HAS_FILT (0)
/* @brief If PIT has CTRL2 register */
#define FSL_FEATURE_PIT_HAS_CTRL2 (0)

/* PMC module features */

/* @brief If PMC has TRIM register. */
#define FSL_FEATURE_PMC_HAS_TRIM_REGISTER (0)

/* PWM module features */

/* @brief If (e)FlexPWM has module A channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELA (1)
/* @brief If (e)FlexPWM has module B channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELB (1)
/* @brief If (e)FlexPWM has module X channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELX (1)
/* @brief If (e)FlexPWM has capture control A register */
#define FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER (1)
/* @brief If (e)FlexPWM has capture control B register */
#define FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER (1)
/* @brief If (e)FlexPWM has fractional feature. */
#define FSL_FEATURE_PWM_HAS_FRACTIONAL (0)
/* @brief If (e)FlexPWM has microedge feature. */
#define FSL_FEATURE_PWM_HAS_MICROEDGE (0)
/* @brief If (e)FlexPWM has mux trigger source select bit field. */
#define FSL_FEATURE_PWM_HAS_MUX_TRIGGER_SOURCE_SEL (1)
/* @brief Number of submodules in each (e)FlexPWM module. */
#define FSL_FEATURE_PWM_SUBMODULE_COUNT (4)
/* @brief Number of fault channel in each (e)FlexPWM module. */
#define FSL_FEATURE_PWM_FAULT_CH_COUNT (2)
/* @brief If (e)FlexPWM has phase delay register. */
#define FSL_FEATURE_PWM_HAS_PHASEDLY_REGISTER (0)
/* @brief If (e)FlexPWM CTRL register has COMPMODE bit field. */
#define FSL_FEATURE_PWM_CTRL_HAS_COMPMODE_BITFIELD (0)
/* @brief If (e)FlexPWM CTRL register has SPLIT bit field. */
#define FSL_FEATURE_PWM_CTRL_HAS_SPLIT_BITFIELD (0)
/* @brief If (e)FlexPWM TCTRL register has TRGFRQ bit field. */
#define FSL_FEATURE_PWM_TCTRL_HAS_TRGFRQ_BITFIELD (0)
/* @brief If (e)FlexPWM MASK register has UPDATE_MASK bit field. */
#define FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD (0)
/* @brief If (e)FlexPWM MCTRL2 register has STRETCH_CNT_PRSC bit field. */
#define FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD (0)
/* @brief If (e)FlexPWM MCTRL2 register has WRPROT bit field. */
#define FSL_FEATURE_PWM_MCTRL2_HAS_WRPROT_BITFIELD (0)
/* @brief If (e)FlexPWM has FCTRL2 register. */
#define FSL_FEATURE_PWM_HAS_FCTRL2_REGISTER (0)
/* @brief Bitwidth of DTCNTx in (e)FlexPWM module. */
#define FSL_FEATURE_PWM_NUM_BITWIDTH_DTCNT (11)
/* @brief If (e)FlexPWM has Capture Input Filter Register */
#define FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER (0)

/* QDC module features */

/* @brief If QDC CTRL2 register has SABIE bit field. */
#define FSL_FEATURE_QDC_CTRL2_HAS_SABIE_BIT_FIELD (0)
/* @brief If QDC CTRL2 register has SABIRQ bit field. */
#define FSL_FEATURE_QDC_CTRL2_HAS_SABIRQ_BIT_FIELD (0)
/* @brief If QDC CTRL2 register has INITPOS bit field. */
#define FSL_FEATURE_QDC_CTRL2_HAS_INITPOS_BIT_FIELD (0)
/* @brief If QDC has CTRL3 register. */
#define FSL_FEATURE_QDC_HAS_CTRL3_REGISTER (0)
/* @brief If QDC has LCOMP1 register. */
#define FSL_FEATURE_QDC_HAS_LCOMP1_REGISTER (0)
/* @brief If QDC has UCOMP1 register. */
#define FSL_FEATURE_QDC_HAS_UCOMP1_REGISTER (0)
/* @brief If QDC has LASTEDGE register. */
#define FSL_FEATURE_QDC_HAS_LASTEDGE_REGISTER (0)
/* @brief If QDC has LASTEDGEH register. */
#define FSL_FEATURE_QDC_HAS_LASTEDGEH_REGISTER (0)
/* @brief If QDC has POSDPER register. */
#define FSL_FEATURE_QDC_HAS_POSDPER_REGISTER (0)
/* @brief If QDC has POSDPERBFR register. */
#define FSL_FEATURE_QDC_HAS_POSDPERBFR_REGISTER (0)
/* @brief If QDC has POSDPERH register. */
#define FSL_FEATURE_QDC_HAS_POSDPERH_REGISTER (0)
/* @brief If QDC CTRL register has CMPIE bit field. */
#define FSL_FEATURE_QDC_CTRL_HAS_CMPIE_BIT_FIELD (1)
/* @brief If QDC CTRL3 register has CMP1IE bit field. */
#define FSL_FEATURE_QDC_CTRL3_HAS_CMP1IE_BIT_FIELD (0)
/* @brief If QDC CTRL2 register has EMIP bit field. */
#define FSL_FEATURE_QDC_CTRL2_HAS_EMIP_BIT_FIELD (0)
/* @brief If QDC FILT register has FILT_PRSC bit field. */
#define FSL_FEATURE_QDC_FILT_HAS_FILT_PRSC_BIT_FIELD (0)

/* QSCI module features */

/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FSL_FEATURE_QSCI_FIFO_SIZEn(x) (4)
/* @brief Has Rx Idle Interrupt (register bit field CTRL2[RIIE]). */
#define FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT (0)

/* SADC module features */

/* @brief Has Programmable Gain Amplifier (PGA) in ADC (register PGA). */
#define FSL_FEATURE_SADC_HAS_PGA (0)
/* @brief Has PGA chopping control in ADC (bit PGA[PGACHPb] or PGA[PGACHP]). */
#define FSL_FEATURE_SADC_HAS_PGA_CHOPPING (0)
/* @brief Has PGA offset measurement mode in ADC (bit PGA[PGAOFSM]). */
#define FSL_FEATURE_SADC_HAS_PGA_OFFSET_MEASUREMENT (0)
/* @brief Has DMA support (bit SC2[DMAEN] or SC4[DMAEN]). */
#define FSL_FEATURE_SADC_HAS_DMA (1)
/* @brief Has differential mode (bitfield SC1x[DIFF]). */
#define FSL_FEATURE_SADC_HAS_DIFF_MODE (0)
/* @brief Has FIFO (bit SC4[AFDEP]). */
#define FSL_FEATURE_SADC_HAS_FIFO (0)
/* @brief FIFO size if available (bitfield SC4[AFDEP]). */
#define FSL_FEATURE_SADC_FIFO_SIZE (0)
/* @brief Has channel set a/b multiplexor (bitfield CFG2[MUXSEL]). */
#define FSL_FEATURE_SADC_HAS_MUX_SELECT (0)
/* @brief Has HW trigger masking (bitfield SC5[HTRGMASKE]. */
#define FSL_FEATURE_SADC_HAS_HW_TRIGGER_MASK (0)
/* @brief Has calibration feature (bit SC3[CAL] and registers CLPx, CLMx). */
#define FSL_FEATURE_SADC_HAS_CALIBRATION (1)
/* @brief Has HW averaging (bit SC3[AVGE]). */
#define FSL_FEATURE_SADC_HAS_HW_AVERAGE (1)
/* @brief Has offset correction (register OFS). */
#define FSL_FEATURE_SADC_HAS_OFFSET_CORRECTION (1)
/* @brief Maximum ADC resolution. */
#define FSL_FEATURE_SADC_MAX_RESOLUTION (16)
/* @brief Number of SC1x and Rx register pairs (conversion control and result registers). */
#define FSL_FEATURE_SADC_CONVERSION_CONTROL_COUNT (1)
/* @brief Has reference from PMC Bandgap voltage. */
#define FSL_FEATURE_SADC_HAS_VREF_BANDGAP (1)

/* SIM module features */

/* @brief If SIM has GPSAL register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSAL (1)
/* @brief If SIM has GPSAH register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSAH (0)
/* @brief If SIM has GPSBL register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSBL (0)
/* @brief If SIM has GPSBH register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSBH (1)
/* @brief If SIM has GPSCL register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSCL (1)
/* @brief If SIM has GPSCH register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSCH (1)
/* @brief If SIM has GPSDL register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSDL (1)
/* @brief If SIM has GPSDH register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSDH (0)
/* @brief If SIM has GPSEL register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSEL (1)
/* @brief If SIM has GPSEH register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSEH (1)
/* @brief If SIM has GPSFL register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSFL (1)
/* @brief If SIM has GPSFH register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSFH (1)
/* @brief If SIM has GPSGL register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSGL (1)
/* @brief If SIM has GPSGH register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSGH (1)
/* @brief If SIM has NVMOPT6_LOW register */
#define FSL_FEATURE_SIM_HAS_NVMOPT6_LOW_REGISTER (0)
/* @brief If SIM has PWM_SEL register */
#define FSL_FEATURE_SIM_HAS_PWM_SEL_REGISTER (0)
/* @brief If SIM RSTAT register has BOOT_MODE_STATUS bit field */
#define FSL_FEATURE_SIM_RSTAT_HAS_BOOT_MODE_STATUS_BIT_FIELD (0)
/* @brief If SIM RSTAT register has COP_WIN bit field */
#define FSL_FEATURE_SIM_RSTAT_HAS_COP_WIN_BIT_FIELD (0)
/* @brief If SIM MISC0 register has SCTRL_REORDER bit field */
#define FSL_FEATURE_SIM_MISC0_HAS_SCTRL_REORDER_BIT_FIELD (0)
/* @brief If SIM MISC0 register has MODE_STAT bit field */
#define FSL_FEATURE_SIM_MISC0_HAS_MODE_STAT_BIT_FIELD (0)
/* @brief If SIM MISC0 register has LPI2C0_TRIG_SEL bit field */
#define FSL_FEATURE_SIM_MISC0_HAS_LPI2C0_TRIG_SEL_BIT_FIELD (0)
/* @brief If SIM MISC0 register has LPI2C1_TRIG_SEL bit field */
#define FSL_FEATURE_SIM_MISC0_HAS_LPI2C1_TRIG_SEL_BIT_FIELD (0)
/* @brief If SIM has IPSN register */
#define FSL_FEATURE_SIM_HAS_IPSN_REGISTER (0)
/* @brief If SIM has ADC_TMR_SEL register */
#define FSL_FEATURE_SIM_HAS_ADC_TMR_SEL_REGISTER (0)
/* @brief If SIM has NVMOPT2H register */
#define FSL_FEATURE_SIM_HAS_NVMOPT2H_REGISTER (1)
/* @brief If SIM has NVMOPT2L register */
#define FSL_FEATURE_SIM_HAS_NVMOPT2L_REGISTER (1)
/* @brief If SIM NVMOPT2L register has ROSC_32K_FTRIM bit field */
#define FSL_FEATURE_SIM_HAS_NVMOPT2L_ROSC_32K (1)
/* @brief If SIM has NVMOPT3H register */
#define FSL_FEATURE_SIM_HAS_NVMOPT3H_REGISTER (1)
/* @brief If SIM has BOOT_MODE_OVERRIDE register */
#define FSL_FEATURE_SIM_HAS_BOOT_MODE_OVERRIDE_REGISTER (0)

/* XBARA module features */

/* @brief Number of dma/interrupt requests. */
#define FSL_FEATURE_XBARA_INTERRUPT_COUNT (4)

#endif /* _MC56F84567_FEATURES_H_ */

