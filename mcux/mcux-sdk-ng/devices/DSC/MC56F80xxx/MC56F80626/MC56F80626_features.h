/*
** ###################################################################
**     Version:             rev. 0.1, 2022-01-28
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
**     - rev. 0.1 (2022-01-28)
**         Initial version.
**
** ###################################################################
*/

#ifndef _MC56F80626_FEATURES_H_
#define _MC56F80626_FEATURES_H_

/* SOC module features */

/* @brief CADC availability on the SoC. */
#define FSL_FEATURE_SOC_CADC_COUNT (1)
/* @brief CMP availability on the SoC. */
#define FSL_FEATURE_SOC_CMP_COUNT (3)
/* @brief COP availability on the SoC. */
#define FSL_FEATURE_SOC_COP_COUNT (1)
/* @brief CRC availability on the SoC. */
#define FSL_FEATURE_SOC_CRC_COUNT (1)
/* @brief DMAMUX availability on the SoC. */
#define FSL_FEATURE_SOC_DMAMUX_COUNT (1)
/* @brief EDMA availability on the SoC. */
#define FSL_FEATURE_SOC_EDMA_COUNT (1)
/* @brief EVTG availability on the SoC. */
#define FSL_FEATURE_SOC_EVTG_COUNT (1)
/* @brief EWM availability on the SoC. */
#define FSL_FEATURE_SOC_EWM_COUNT (1)
/* @brief FMC availability on the SoC. */
#define FSL_FEATURE_SOC_FMC_COUNT (1)
/* @brief FTFA availability on the SoC. */
#define FSL_FEATURE_SOC_FTFA_COUNT (1)
/* @brief GPIO availability on the SoC. */
#define FSL_FEATURE_SOC_GPIO_COUNT (6)
/* @brief INTC availability on the SoC. */
#define FSL_FEATURE_SOC_INTC_COUNT (1)
/* @brief LPI2C availability on the SoC. */
#define FSL_FEATURE_SOC_LPI2C_COUNT (1)
/* @brief MCM availability on the SoC. */
#define FSL_FEATURE_SOC_MCM_COUNT (1)
/* @brief OCCS availability on the SoC. */
#define FSL_FEATURE_SOC_OCCS_COUNT (1)
/* @brief OPAMP availability on the SoC. */
#define FSL_FEATURE_SOC_OPAMP_COUNT (2)
/* @brief PIT availability on the SoC. */
#define FSL_FEATURE_SOC_PIT_COUNT (2)
/* @brief PMC availability on the SoC. */
#define FSL_FEATURE_SOC_PMC_COUNT (1)
/* @brief PWM availability on the SoC. */
#define FSL_FEATURE_SOC_PWM_COUNT (1)
/* @brief QSCI availability on the SoC. */
#define FSL_FEATURE_SOC_QSCI_COUNT (2)
/* @brief QSPI availability on the SoC. */
#define FSL_FEATURE_SOC_QSPI_COUNT (1)
/* @brief SIM availability on the SoC. */
#define FSL_FEATURE_SOC_SIM_COUNT (1)
/* @brief TMR availability on the SoC. */
#define FSL_FEATURE_SOC_TMR_COUNT (1)
/* @brief XBARA availability on the SoC. */
#define FSL_FEATURE_SOC_XBARA_COUNT (1)

/* CADC module features */

/* @brief register RSLT2 count. */
#define FSL_FEATURE_CADC_RSLT2_COUNT (4)
/* @brief No auto standby (register bit PWR[ASB]). */
#define FSL_FEATURE_CADC_NO_AUTO_STANDBY (1)
/* @brief No speedmode bit (register bits PWR2[SPEEDA]). */
#define FSL_FEATURE_CADC_NO_SPEEDMODE_BIT (1)
/* @brief No sample window (register bit CTRL3[SCNT0]). */
#define FSL_FEATURE_CADC_NO_SAMPLE_WINDOW (1)
/* @brief Has unipolar differential mode (register bit CTRL3[UPDEN_L]). */
#define FSL_FEATURE_CADC_HAS_UNIPOLAR_DIFFERENTIAL_MODE (1)
/* @brief Has expansion mux for additional channels. */
#define FSL_FEATURE_CADC_HAS_EXP_MUX_AUX (1)
/* @brief Has mux selection bitfields in expansion MUX control registers */
#define FSL_FEATURE_CADC_HAS_EXP_MUX_SEL (1)

/* CMP module features */

/* @brief Has Trigger mode in CMP (register bit field CR1[TRIGM]). */
#define FSL_FEATURE_CMP_HAS_TRIGGER_MODE (0)
/* @brief Has Window mode in CMP (register bit field CR1[WE]). */
#define FSL_FEATURE_CMP_HAS_WINDOW_MODE (1)
/* @brief Has External sample supported in CMP (register bit field CR1[SE]). */
#define FSL_FEATURE_CMP_HAS_EXTERNAL_SAMPLE_SUPPORT (1)
/* @brief Has DMA support in CMP (register bit field SCR[DMAEN]). */
#define FSL_FEATURE_CMP_HAS_DMA (1)
/* @brief Has Pass Through mode in CMP (register bit field MUXCR[PSTM]). */
#define FSL_FEATURE_CMP_HAS_PASS_THROUGH_MODE (0)
/* @brief Has DAC Test function in CMP (register DACTEST). */
#define FSL_FEATURE_CMP_HAS_DAC_TEST (0)
/* @brief Has COUTA out of window is zero enable. */
#define FSL_FEATURE_CMP_HAS_COWZ_BIT_FIELD (1)
/* @brief Use 16 bit registers. */
#define FSL_FEATURE_CMP_USE_16BIT_REG (1)

/* COP module features */

/* @brief If COP has WINDOW register */
#define FSL_FEATURE_COP_HAS_WINDOW_REGISTER (1)

/* CRC module features */

/* @brief If CRC has CRC register */
#define FSL_FEATURE_CRC_HAS_CRC_REGISTER (0)
/* @brief CRC16 type of the peripheral. */
#define FSL_FEATURE_CRC_CRC16_TYPE (0)

/* EDMA module features */

/* @brief Number of DMA channels (related to number of registers TCD, DCHPRI, bit fields ERQ[ERQn], EEI[EEIn], INT[INTn], ERR[ERRn], HRS[HRSn] and bit field widths ES[ERRCHN], CEEI[CEEI], SEEI[SEEI], CERQ[CERQ], SERQ[SERQ], CDNE[CDNE], SSRT[SSRT], CERR[CERR], CINT[CINT], TCDn_CITER_ELINKYES[LINKCH], TCDn_CSR[MAJORLINKCH], TCDn_BITER_ELINKYES[LINKCH]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL (4)
/* @brief Total number of DMA channels on all modules. */
#define FSL_FEATURE_EDMA_DMAMUX_CHANNELS (4)
/* @brief Number of DMA channel groups (register bit fields CR[ERGA], CR[GRPnPRI], ES[GPE], DCHPRIn[GRPPRI]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_CHANNEL_GROUP_COUNT (1)
/* @brief Has DMA_Error interrupt vector. */
#define FSL_FEATURE_EDMA_HAS_ERROR_IRQ (1)
/* @brief Number of DMA channels with asynchronous request capability (register EARS). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_ASYNCHRO_REQUEST_CHANNEL_COUNT (4)
/* @brief Channel IRQ entry shared offset. */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL_IRQ_ENTRY_SHARED_OFFSET (0)
/* @brief If 8 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_8_BYTES_TRANSFER (0)
/* @brief If 16 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_16_BYTES_TRANSFER (1)
/* @brief If 32 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_32_BYTES_TRANSFER (0)

/* DMAMUX module features */

/* @brief Number of DMA channels (related to number of register CHCFGn). */
#define FSL_FEATURE_DMAMUX_MODULE_CHANNEL (4)
/* @brief Total number of DMA channels on all modules. */
#define FSL_FEATURE_DMAMUX_DMAMUX_CHANNELS (4)
/* @brief Has the periodic trigger capability for the triggered DMA channel (register bit CHCFG0[TRIG]). */
#define FSL_FEATURE_DMAMUX_HAS_TRIG (0)
/* @brief Has DMA Channel Always ON function (register bit CHCFG0[A_ON]). */
#define FSL_FEATURE_DMAMUX_HAS_A_ON (0)
/* @brief Register CHCFGn width. */
#define FSL_FEATURE_DMAMUX_CHCFG_REGISTER_WIDTH (8)

/* EWM module features */

/* @brief Has clock select (register CLKCTRL). */
#define FSL_FEATURE_EWM_HAS_CLOCK_SELECT (1)
/* @brief Has clock prescaler (register CLKPRESCALER). */
#define FSL_FEATURE_EWM_HAS_PRESCALER (1)

/* FTFA module features */

/* @brief Is of type FTFA. */
#define FSL_FEATURE_FTFA_TYPE (1)
/* @brief Has flags indicating the status of the FlexRAM (register bits FCNFG[EEERDY], FCNFG[RAMRDY] and FCNFG[PFLSH]). */
#define FSL_FEATURE_FTFA_HAS_FLEX_RAM_FLAGS (0)
/* @brief Has program flash swapping status flag (register bit FCNFG[SWAP]). */
#define FSL_FEATURE_FTFA_HAS_PFLASH_SWAPPING_STATUS_FLAG (0)
/* @brief Has EEPROM region protection (register FEPROT). */
#define FSL_FEATURE_FTFA_HAS_EEROM_REGION_PROTECTION (0)
/* @brief Has data flash region protection (register FDPROT). */
#define FSL_FEATURE_FTFA_HAS_DATA_FLASH_REGION_PROTECTION (0)
/* @brief Has flash access control (registers XACCHn, SACCHn, where n is a number, FACSS and FACSN). */
#define FSL_FEATURE_FTFA_HAS_ACCESS_CONTROL (0)
/* @brief Has flash cache control in FMC module. */
#define FSL_FEATURE_FTFA_HAS_FMC_FLASH_CACHE_CONTROLS (0)
/* @brief Has flash cache control in MCM module. */
#define FSL_FEATURE_FTFA_HAS_MCM_FLASH_CACHE_CONTROLS (1)
/* @brief Has flash cache control in MSCM module. */
#define FSL_FEATURE_FTFA_HAS_MSCM_FLASH_CACHE_CONTROLS (0)
/* @brief Has prefetch speculation control in flash. */
#define FSL_FEATURE_FTFA_HAS_PREFETCH_SPECULATION_CONTROL_IN_FLASH (0)
/* @brief P-Flash flash size coding rule version, value 0 for K1 and K2, value 1 for K3. */
#define FSL_FEATURE_FTFA_SIZE_ENCODING_RULE_VERSION (0)
/* @brief P-Flash start address. */
#define FSL_FEATURE_FTFA_PFLASH_START_ADDRESS (0x00000000)
/* @brief P-Flash block count. */
#define FSL_FEATURE_FTFA_PFLASH_BLOCK_COUNT (1)
/* @brief P-Flash block size. */
#define FSL_FEATURE_FTFA_PFLASH_BLOCK_SIZE (32768UL)
/* @brief P-Flash sector size. */
#define FSL_FEATURE_FTFA_PFLASH_BLOCK_SECTOR_SIZE (1024U)
/* @brief P-Flash write unit size. */
#define FSL_FEATURE_FTFA_PFLASH_BLOCK_WRITE_UNIT_SIZE (4)
/* @brief P-Flash data path width. */
#define FSL_FEATURE_FTFA_PFLASH_BLOCK_DATA_PATH_WIDTH (8)
/* @brief P-Flash block swap feature. */
#define FSL_FEATURE_FTFA_HAS_PFLASH_BLOCK_SWAP (0)
/* @brief P-Flash protection region count. */
#define FSL_FEATURE_FTFA_PFLASH_PROTECTION_REGION_COUNT (32)
/* @brief Has FlexNVM memory. */
#define FSL_FEATURE_FTFA_HAS_FLEX_NVM (0)
/* @brief FlexNVM start address. (Valid only if FlexNVM is available.) */
#define FSL_FEATURE_FTFA_FLEX_NVM_START_ADDRESS (0x00000000UL)
/* @brief FlexNVM block count. */
#define FSL_FEATURE_FTFA_FLEX_NVM_BLOCK_COUNT (0)
/* @brief FlexNVM block size. */
#define FSL_FEATURE_FTFA_FLEX_NVM_BLOCK_SIZE (0)
/* @brief FlexNVM sector size. */
#define FSL_FEATURE_FTFA_FLEX_NVM_BLOCK_SECTOR_SIZE (0)
/* @brief FlexNVM write unit size. */
#define FSL_FEATURE_FTFA_FLEX_NVM_BLOCK_WRITE_UNIT_SIZE (0)
/* @brief FlexNVM data path width. */
#define FSL_FEATURE_FTFA_FLEX_BLOCK_DATA_PATH_WIDTH (0)
/* @brief Has FlexRAM memory. */
#define FSL_FEATURE_FTFA_HAS_FLEX_RAM (0)
/* @brief FlexRAM start address. (Valid only if FlexRAM is available.) */
#define FSL_FEATURE_FTFA_FLEX_RAM_START_ADDRESS (0x00000000)
/* @brief FlexRAM size. */
#define FSL_FEATURE_FTFA_FLEX_RAM_SIZE (0)
/* @brief Has 0x00 Read 1s Block command. */
#define FSL_FEATURE_FTFA_HAS_READ_1S_BLOCK_CMD (1)
/* @brief Has 0x01 Read 1s Section command. */
#define FSL_FEATURE_FTFA_HAS_READ_1S_SECTION_CMD (1)
/* @brief Has 0x02 Program Check command. */
#define FSL_FEATURE_FTFA_HAS_PROGRAM_CHECK_CMD (1)
/* @brief Has 0x03 Read Resource command. */
#define FSL_FEATURE_FTFA_HAS_READ_RESOURCE_CMD (1)
/* @brief Has 0x06 Program Longword command. */
#define FSL_FEATURE_FTFA_HAS_PROGRAM_LONGWORD_CMD (1)
/* @brief Has 0x07 Program Phrase command. */
#define FSL_FEATURE_FTFA_HAS_PROGRAM_PHRASE_CMD (0)
/* @brief Has 0x08 Erase Flash Block command. */
#define FSL_FEATURE_FTFA_HAS_ERASE_FLASH_BLOCK_CMD (1)
/* @brief Has 0x09 Erase Flash Sector command. */
#define FSL_FEATURE_FTFA_HAS_ERASE_FLASH_SECTOR_CMD (1)
/* @brief Has 0x0B Program Section command. */
#define FSL_FEATURE_FTFA_HAS_PROGRAM_SECTION_CMD (0)
/* @brief Has 0x40 Read 1s All Blocks command. */
#define FSL_FEATURE_FTFA_HAS_READ_1S_ALL_BLOCKS_CMD (1)
/* @brief Has 0x41 Read Once command. */
#define FSL_FEATURE_FTFA_HAS_READ_ONCE_CMD (1)
/* @brief Has 0x43 Program Once command. */
#define FSL_FEATURE_FTFA_HAS_PROGRAM_ONCE_CMD (1)
/* @brief Has 0x44 Erase All Blocks command. */
#define FSL_FEATURE_FTFA_HAS_ERASE_ALL_BLOCKS_CMD (1)
/* @brief Has 0x45 Verify Backdoor Access Key command. */
#define FSL_FEATURE_FTFA_HAS_VERIFY_BACKDOOR_ACCESS_KEY_CMD (1)
/* @brief Has 0x46 Swap Control command. */
#define FSL_FEATURE_FTFA_HAS_SWAP_CONTROL_CMD (0)
/* @brief Has 0x49 Erase All Blocks Unsecure command. */
#define FSL_FEATURE_FTFA_HAS_ERASE_ALL_BLOCKS_UNSECURE_CMD (0)
/* @brief Has 0x4A Read 1s All Execute-only Segments command. */
#define FSL_FEATURE_FTFA_HAS_READ_1S_ALL_EXECUTE_ONLY_SEGMENTS_CMD (1)
/* @brief Has 0x4B Erase All Execute-only Segments command. */
#define FSL_FEATURE_FTFA_HAS_ERASE_ALL_EXECUTE_ONLY_SEGMENTS_CMD (1)
/* @brief Has 0x80 Program Partition command. */
#define FSL_FEATURE_FTFA_HAS_PROGRAM_PARTITION_CMD (0)
/* @brief Has 0x81 Set FlexRAM Function command. */
#define FSL_FEATURE_FTFA_HAS_SET_FLEXRAM_FUNCTION_CMD (0)
/* @brief P-Flash Erase/Read 1st all block command address alignment. */
#define FSL_FEATURE_FTFA_PFLASH_BLOCK_CMD_ADDRESS_ALIGMENT (4)
/* @brief P-Flash Erase sector command address alignment. */
#define FSL_FEATURE_FTFA_PFLASH_SECTOR_CMD_ADDRESS_ALIGMENT (8)
/* @brief P-Flash Rrogram/Verify section command address alignment. */
#define FSL_FEATURE_FTFA_PFLASH_SECTION_CMD_ADDRESS_ALIGMENT (8)
/* @brief P-Flash Read resource command address alignment. */
#define FSL_FEATURE_FTFA_PFLASH_RESOURCE_CMD_ADDRESS_ALIGMENT (4)
/* @brief P-Flash Program check command address alignment. */
#define FSL_FEATURE_FTFA_PFLASH_CHECK_CMD_ADDRESS_ALIGMENT (4)
/* @brief P-Flash swap control command address alignment. */
#define FSL_FEATURE_FTFA_PFLASH_SWAP_CONTROL_CMD_ADDRESS_ALIGMENT (0)

/* LPI2C module features */

/* @brief Has separate DMA RX and TX requests. */
#define FSL_FEATURE_LPI2C_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FSL_FEATURE_LPI2C_FIFO_SIZEn(x) (4)

/* MCM module features */

/* @brief If MCM has UBROMBAR register. */
#define FSL_FEATURE_MCM_HAS_UBROMBAR_REGISTER (1)
/* @brief If MCM CFISR register has CFEDL bit field. */
#define FSL_FEATURE_MCM_CFISR_HAS_CFEDL_BIT_FIELD (1)
/* @brief If MCM CPCR register has FCCCLR bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_FCCCLR_BIT_FIELD (1)
/* @brief If MCM CPCR register has FCDCDIS bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_FCDCDIS_BIT_FIELD (1)
/* @brief If MCM CPCR register has FCICDIS bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_FCICDIS_BIT_FIELD (1)
/* @brief If MCM CPCR register has FCCDIS bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_FCCDIS_BIT_FIELD (1)
/* @brief If MCM CPCR register has FCDSPDIS bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_FCDSPDIS_BIT_FIELD (1)
/* @brief If MCM CPCR register has FCSPDIS bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_FCSPDIS_BIT_FIELD (1)
/* @brief If MCM CPCR register has FCSDIS bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_FCSDIS_BIT_FIELD (1)
/* @brief If MCM CPCR register has XBARARB bit field. */
#define FSL_FEATURE_MCM_CPCR_HAS_XBARARB_BIT_FIELD (1)

/* PIT module features */

/* @brief If PIT use 32bit counter */
#define FSL_FEATURE_PIT_32BIT_COUNTER (1)
/* @brief If PIT CTRL register has PRESET_POLARITY bit field */
#define FSL_FEATURE_PIT_CTRL_HAS_PRESET_POLARITY_BIT (1)
/* @brief If PIT has FILT register */
#define FSL_FEATURE_PIT_HAS_FILT (1)
/* @brief If PIT has CTRL2 register */
#define FSL_FEATURE_PIT_HAS_CTRL2 (1)

/* PMC module features */

/* @brief If PMC has TRIM register. */
#define FSL_FEATURE_PMC_HAS_TRIM_REGISTER (1)

/* PWM module features */

/* @brief If (e)FlexPWM has module A channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELA (1)
/* @brief If (e)FlexPWM has module B channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELB (1)
/* @brief If (e)FlexPWM has module X channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELX (1)
/* @brief If (e)FlexPWM has capture control A register */
#define FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER (0)
/* @brief If (e)FlexPWM has capture control B register */
#define FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER (0)
/* @brief If (e)FlexPWM has fractional feature. */
#define FSL_FEATURE_PWM_HAS_FRACTIONAL (1)
/* @brief If (e)FlexPWM has microedge feature. */
#define FSL_FEATURE_PWM_HAS_MICROEDGE (0)
/* @brief If (e)FlexPWM has mux trigger source select bit field. */
#define FSL_FEATURE_PWM_HAS_MUX_TRIGGER_SOURCE_SEL (0)
/* @brief Number of submodules in each (e)FlexPWM module. */
#define FSL_FEATURE_PWM_SUBMODULE_COUNT (4)
/* @brief Number of fault channel in each (e)FlexPWM module. */
#define FSL_FEATURE_PWM_FAULT_CH_COUNT (2)
/* @brief If (e)FlexPWM has phase delay register. */
#define FSL_FEATURE_PWM_HAS_PHASEDLY_REGISTER (1)
/* @brief If (e)FlexPWM CTRL register has COMPMODE bit field. */
#define FSL_FEATURE_PWM_CTRL_HAS_COMPMODE_BITFIELD (1)
/* @brief If (e)FlexPWM CTRL register has SPLIT bit field. */
#define FSL_FEATURE_PWM_CTRL_HAS_SPLIT_BITFIELD (1)
/* @brief If (e)FlexPWM TCTRL register has TRGFRQ bit field. */
#define FSL_FEATURE_PWM_TCTRL_HAS_TRGFRQ_BITFIELD (1)
/* @brief If (e)FlexPWM MASK register has UPDATE_MASK bit field. */
#define FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD (1)
/* @brief If (e)FlexPWM MCTRL2 register has STRETCH_CNT_PRSC bit field. */
#define FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD (0)
/* @brief If (e)FlexPWM MCTRL2 register has WRPROT bit field. */
#define FSL_FEATURE_PWM_MCTRL2_HAS_WRPROT_BITFIELD (1)
/* @brief If (e)FlexPWM has FCTRL2 register. */
#define FSL_FEATURE_PWM_HAS_FCTRL2_REGISTER (1)
/* @brief Bitwidth of DTCNTx in (e)FlexPWM module. */
#define FSL_FEATURE_PWM_NUM_BITWIDTH_DTCNT (16)
/* @brief If (e)FlexPWM has Capture Input Filter Register */
#define FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER (0)

/* QSCI module features */

/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FSL_FEATURE_QSCI_FIFO_SIZEn(x) (4)
/* @brief Has Rx Idle Interrupt (register bit field CTRL2[RIIE]). */
#define FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT (1)

/* SIM module features */

/* @brief If SIM has GPSAL register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSAL (1)
/* @brief If SIM has GPSAH register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSAH (0)
/* @brief If SIM has GPSBL register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSBL (1)
/* @brief If SIM has GPSBH register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSBH (0)
/* @brief If SIM has GPSCL register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSCL (1)
/* @brief If SIM has GPSCH register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSCH (1)
/* @brief If SIM has GPSDL register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSDL (0)
/* @brief If SIM has GPSDH register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSDH (0)
/* @brief If SIM has GPSEL register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSEL (1)
/* @brief If SIM has GPSEH register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSEH (0)
/* @brief If SIM has GPSFL register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSFL (1)
/* @brief If SIM has GPSFH register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSFH (1)
/* @brief If SIM has GPSGL register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSGL (0)
/* @brief If SIM has GPSGH register */
#define FSL_FEATURE_SIM_PINMUX_HAS_GPSGH (0)
/* @brief If SIM has NVMOPT6_LOW register */
#define FSL_FEATURE_SIM_HAS_NVMOPT6_LOW_REGISTER (0)
/* @brief If SIM has PWM_SEL register */
#define FSL_FEATURE_SIM_HAS_PWM_SEL_REGISTER (0)
/* @brief If SIM RSTAT register has BOOT_MODE_STATUS bit field */
#define FSL_FEATURE_SIM_RSTAT_HAS_BOOT_MODE_STATUS_BIT_FIELD (0)
/* @brief If SIM RSTAT register has COP_WIN bit field */
#define FSL_FEATURE_SIM_RSTAT_HAS_COP_WIN_BIT_FIELD (1)
/* @brief If SIM MISC0 register has SCTRL_REORDER bit field */
#define FSL_FEATURE_SIM_MISC0_HAS_SCTRL_REORDER_BIT_FIELD (1)
/* @brief If SIM MISC0 register has MODE_STAT bit field */
#define FSL_FEATURE_SIM_MISC0_HAS_MODE_STAT_BIT_FIELD (1)
/* @brief If SIM MISC0 register has LPI2C0_TRIG_SEL bit field */
#define FSL_FEATURE_SIM_MISC0_HAS_LPI2C0_TRIG_SEL_BIT_FIELD (1)
/* @brief If SIM MISC0 register has LPI2C1_TRIG_SEL bit field */
#define FSL_FEATURE_SIM_MISC0_HAS_LPI2C1_TRIG_SEL_BIT_FIELD (0)
/* @brief If SIM has IPSN register */
#define FSL_FEATURE_SIM_HAS_IPSN_REGISTER (0)
/* @brief If SIM has ADC_TMR_SEL register */
#define FSL_FEATURE_SIM_HAS_ADC_TMR_SEL_REGISTER (1)
/* @brief If SIM has NVMOPT2H register */
#define FSL_FEATURE_SIM_HAS_NVMOPT2H_REGISTER (0)
/* @brief If SIM has NVMOPT2L register */
#define FSL_FEATURE_SIM_HAS_NVMOPT2L_REGISTER (0)
/* @brief If SIM NVMOPT2L register has ROSC_32K_FTRIM bit field */
#define FSL_FEATURE_SIM_HAS_NVMOPT2L_ROSC_32K (0)
/* @brief If SIM has NVMOPT3H register */
#define FSL_FEATURE_SIM_HAS_NVMOPT3H_REGISTER (0)
/* @brief If SIM has BOOT_MODE_OVERRIDE register */
#define FSL_FEATURE_SIM_HAS_BOOT_MODE_OVERRIDE_REGISTER (0)

/* XBARA module features */

/* @brief Number of interrupt requests. */
#define FSL_FEATURE_XBARA_INTERRUPT_COUNT (4)

#endif /* _MC56F80626_FEATURES_H_ */

