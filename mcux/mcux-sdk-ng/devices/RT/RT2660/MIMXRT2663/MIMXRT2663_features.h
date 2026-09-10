/*
** ###################################################################
**     Version:             rev. 1.0, 2024-11-13
**     Build:               b260818
**
**     Abstract:
**         Chip specific module features.
**
**     Copyright 2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-13)
**         Initial version.
**
** ###################################################################
*/

#ifndef _MIMXRT2663_FEATURES_H_
#define _MIMXRT2663_FEATURES_H_

/* SOC module features */

/* @brief ACMP availability on the SoC. */
#define FSL_FEATURE_SOC_ACMP_COUNT (4)
/* @brief ASRC availability on the SoC. */
#define FSL_FEATURE_SOC_ASRC_COUNT (1)
/* @brief AXBS availability on the SoC. */
#define FSL_FEATURE_SOC_AXBS_COUNT (1)
/* @brief CCM availability on the SoC. */
#define FSL_FEATURE_SOC_CCM_COUNT (7)
/* @brief CRC availability on the SoC. */
#define FSL_FEATURE_SOC_CRC_COUNT (1)
/* @brief CSI availability on the SoC. */
#define FSL_FEATURE_SOC_CSI_COUNT (1)
/* @brief EDMA availability on the SoC. */
#define FSL_FEATURE_SOC_EDMA_COUNT (4)
/* @brief ENET availability on the SoC. */
#define FSL_FEATURE_SOC_ENET_COUNT (1)
/* @brief ENET_QOS availability on the SoC. */
#define FSL_FEATURE_SOC_ENET_QOS_COUNT (1)
/* @brief EQDC availability on the SoC. */
#define FSL_FEATURE_SOC_EQDC_COUNT (4)
/* @brief EVTG availability on the SoC. */
#define FSL_FEATURE_SOC_EVTG_COUNT (4)
/* @brief EWM availability on the SoC. */
#define FSL_FEATURE_SOC_EWM_COUNT (1)
/* @brief FLEXCAN availability on the SoC. */
#define FSL_FEATURE_SOC_FLEXCAN_COUNT (3)
/* @brief FLEXIO availability on the SoC. */
#define FSL_FEATURE_SOC_FLEXIO_COUNT (3)
/* @brief FREQME availability on the SoC. */
#define FSL_FEATURE_SOC_FREQME_COUNT (7)
/* @brief GPIO availability on the SoC. */
#define FSL_FEATURE_SOC_GPIO_COUNT (7)
/* @brief I3C availability on the SoC. */
#define FSL_FEATURE_SOC_I3C_COUNT (2)
/* @brief I2S availability on the SoC. */
#define FSL_FEATURE_SOC_I2S_COUNT (3)
/* @brief INPUTMUX availability on the SoC. */
#define FSL_FEATURE_SOC_INPUTMUX_COUNT (7)
/* @brief IOMUXC availability on the SoC. */
#define FSL_FEATURE_SOC_IOMUXC_COUNT (3)
/* @brief ISI availability on the SoC. */
#define FSL_FEATURE_SOC_ISI_COUNT (1)
/* @brief LLC availability on the SoC. */
#define FSL_FEATURE_SOC_LLC_COUNT (1)
/* @brief LPADC availability on the SoC. */
#define FSL_FEATURE_SOC_LPADC_COUNT (2)
/* @brief LPDAC availability on the SoC. */
#define FSL_FEATURE_SOC_LPDAC_COUNT (1)
/* @brief LPI2C availability on the SoC. */
#define FSL_FEATURE_SOC_LPI2C_COUNT (4)
/* @brief LPIT availability on the SoC. */
#define FSL_FEATURE_SOC_LPIT_COUNT (2)
/* @brief LPSPI availability on the SoC. */
#define FSL_FEATURE_SOC_LPSPI_COUNT (6)
/* @brief LPTMR availability on the SoC. */
#define FSL_FEATURE_SOC_LPTMR_COUNT (3)
/* @brief LPUART availability on the SoC. */
#define FSL_FEATURE_SOC_LPUART_COUNT (8)
/* @brief MCM availability on the SoC. */
#define FSL_FEATURE_SOC_MCM_COUNT (1)
/* @brief MIPI_DSI availability on the SoC. */
#define FSL_FEATURE_SOC_MIPI_DSI_COUNT (1)
/* @brief PDM availability on the SoC. */
#define FSL_FEATURE_SOC_PDM_COUNT (2)
/* @brief PMU availability on the SoC. */
#define FSL_FEATURE_SOC_PMU_COUNT (1)
/* @brief PWM availability on the SoC. */
#define FSL_FEATURE_SOC_PWM_COUNT (4)
/* @brief ROMC availability on the SoC. */
#define FSL_FEATURE_SOC_ROMC_COUNT (1)
/* @brief RTC availability on the SoC. */
#define FSL_FEATURE_SOC_RTC_COUNT (1)
/* @brief SINC availability on the SoC. */
#define FSL_FEATURE_SOC_SINC_COUNT (2)
/* @brief STM availability on the SoC. */
#define FSL_FEATURE_SOC_STM_COUNT (1)
/* @brief TENBASET_PHY availability on the SoC. */
#define FSL_FEATURE_SOC_TENBASET_PHY_COUNT (2)
/* @brief TMR availability on the SoC. */
#define FSL_FEATURE_SOC_TMR_COUNT (4)
/* @brief TPM availability on the SoC. */
#define FSL_FEATURE_SOC_TPM_COUNT (8)
/* @brief USB availability on the SoC. */
#define FSL_FEATURE_SOC_USB_COUNT (1)
/* @brief USBHS availability on the SoC. */
#define FSL_FEATURE_SOC_USBHS_COUNT (1)
/* @brief USBHSDCD availability on the SoC. */
#define FSL_FEATURE_SOC_USBHSDCD_COUNT (1)
/* @brief USBNC availability on the SoC. */
#define FSL_FEATURE_SOC_USBNC_COUNT (1)
/* @brief USBPHY availability on the SoC. */
#define FSL_FEATURE_SOC_USBPHY_COUNT (1)
/* @brief USDHC availability on the SoC. */
#define FSL_FEATURE_SOC_USDHC_COUNT (2)
/* @brief XBAR_DSC availability on the SoC. */
#define FSL_FEATURE_SOC_XBAR_DSC_COUNT (5)

/* ASRC module features */

/* @brief Register name is ASRPM or ASRPMn */
#define FSL_FEATURE_ASRC_PARAMETER_REGISTER_NAME_ASRPM (1)

/* EDMA module features */

/* @brief Number of DMA channels (related to number of registers TCD, DCHPRI, bit fields ERQ[ERQn], EEI[EEIn], INT[INTn], ERR[ERRn], HRS[HRSn] and bit field widths ES[ERRCHN], CEEI[CEEI], SEEI[SEEI], CERQ[CERQ], SERQ[SERQ], CDNE[CDNE], SSRT[SSRT], CERR[CERR], CINT[CINT], TCDn_CITER_ELINKYES[LINKCH], TCDn_CSR[MAJORLINKCH], TCDn_BITER_ELINKYES[LINKCH]). (Valid only for eDMA modules.) Note: This feature value is not the same on all EDMA instances. */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL (32)
/* @brief If 8 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_8_BYTES_TRANSFER (1)
/* @brief Number of DMA channel groups (register bit fields CR[ERGA], CR[GRPnPRI], ES[GPE], DCHPRIn[GRPPRI]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_CHANNEL_GROUP_COUNT (1)
/* @brief If 16 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_16_BYTES_TRANSFER (1)
/* @brief Number of channel for each EDMA instance, (only defined for soc with different channel numbers for difference instance) */
#define FSL_FEATURE_EDMA_INSTANCE_CHANNELn(x) \
    (((x) == MAIN__EDMA5) ? (16) : \
    (((x) == MAIN__EDMA3) ? (32) : \
    (((x) == WAKE__EDMA3) ? (8) : \
    (((x) == AUDIO__EDMA3) ? (8) : (-1)))))
/* @brief Has DMA_Error interrupt vector. */
#define FSL_FEATURE_EDMA_HAS_ERROR_IRQ (1)
/* @brief If 64 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_64_BYTES_TRANSFER (1)
/* @brief Has register bit fields MP_CSR[GMRC]. Note: This feature value is not the same on all EDMA instances. */
#define FSL_FEATURE_EDMA_HAS_GLOBAL_MASTER_ID_REPLICATION (1)
/* @brief If channel clock controlled independently */
#define FSL_FEATURE_EDMA_CHANNEL_HAS_OWN_CLOCK_GATE (1)
/* @brief If 128 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_128_BYTES_TRANSFER (1)
/* @brief Has register bit fields CR[CLM]. */
#define FSL_FEATURE_EDMA_HAS_CONTINUOUS_LINK_MODE (0)
/* @brief If 128 bytes transfer supported. */
#define FSL_FEATURE_EDMA_INSTANCE_SUPPORT_128_BYTES_TRANSFERn(x) (1)
/* @brief NBYTES must be multiple of 8 when using scatter gather. */
#define FSL_FEATURE_EDMA_HAS_ERRATA_51327 (0)
/* @brief Has no register bit fields MP_CSR[EBW]. */
#define FSL_FEATURE_EDMA_HAS_NO_MP_CSR_EBW (1)
/* @brief Has register CH_CSR. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_CONFIG (1)
/* @brief NBYTES must be multiple of 8 when using scatter gather. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_ERRATA_51327n(x) (0)
/* @brief If dma has common clock gate */
#define FSL_FEATURE_EDMA_HAS_COMMON_CLOCK_GATE (0)
/* @brief Has channel mux */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_MUX (1)
/* @brief whether has prot register */
#define FSL_FEATURE_EDMA_HAS_PROT_REGISTER (0)
/* @brief Has register CH_SBR. */
#define FSL_FEATURE_EDMA_HAS_SBR (1)
/* @brief If dma channel IRQ support parameter */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL_IRQ_ENTRY_SUPPORT_PARAMETER (0)
/* @brief Instance has channel mux */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_MUXn(x) (1)
/* @brief Whether instance has prot register. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_PROT_REGISTERn(x) (0)
/* @brief Has no register bit fields CH_SBR[ATTR]. Note: This feature value is not the same on all EDMA instances. */
#define FSL_FEATURE_EDMA_HAS_NO_CH_SBR_ATTR (1)
/* @brief Whether has MP channel mux */
#define FSL_FEATURE_EDMA_HAS_MP_CHANNEL_MUX (1)
/* @brief Has register bit field CH_CSR[SWAP]. Note: This feature value is not the same on all EDMA instances. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_SWAP_SIZE (1)
/* @brief Whether instance has MP channel mux. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_MP_CHANNEL_MUXn(x) \
    (((x) == MAIN__EDMA5) ? (1) : \
    (((x) == MAIN__EDMA3) ? (0) : \
    (((x) == WAKE__EDMA3) ? (0) : \
    (((x) == AUDIO__EDMA3) ? (0) : (-1)))))
/* @brief Instance has register bit field CH_CSR[SWAP]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_SWAP_SIZEn(x) \
    (((x) == MAIN__EDMA5) ? (1) : \
    (((x) == MAIN__EDMA3) ? (0) : \
    (((x) == WAKE__EDMA3) ? (0) : \
    (((x) == AUDIO__EDMA3) ? (0) : (-1)))))
/* @brief Has register bit field CH_SBR[INSTR]. Note: This feature value is not the same on all EDMA instances. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_ACCESS_TYPE (1)
/* @brief Instance has register bit field CH_SBR[INSTR]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_ACCESS_TYPEn(x) \
    (((x) == MAIN__EDMA5) ? (1) : \
    (((x) == MAIN__EDMA3) ? (0) : \
    (((x) == WAKE__EDMA3) ? (0) : \
    (((x) == AUDIO__EDMA3) ? (0) : (-1)))))
/* @brief Has register bit fields CH_MATTR[WCACHE], CH_MATTR[RCACHE]. Note: This feature value is not the same on all EDMA instances. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_MEMORY_ATTRIBUTE (1)
/* @brief Instance has register CH_MATTR. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_MEMORY_ATTRIBUTEn(x) \
    (((x) == MAIN__EDMA5) ? (1) : \
    (((x) == MAIN__EDMA3) ? (0) : \
    (((x) == WAKE__EDMA3) ? (0) : \
    (((x) == AUDIO__EDMA3) ? (0) : (-1)))))
/* @brief Has register bit field CH_CSR[SIGNEXT]. Note: This feature value is not the same on all EDMA instances. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_SIGN_EXTENSION (1)
/* @brief Instance Has register bit field CH_CSR[SIGNEXT]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_SIGN_EXTENSIONn(x) \
    (((x) == MAIN__EDMA5) ? (1) : \
    (((x) == MAIN__EDMA3) ? (0) : \
    (((x) == WAKE__EDMA3) ? (0) : \
    (((x) == AUDIO__EDMA3) ? (0) : (-1)))))
/* @brief Instance has register bit field TCD_CSR[BWC]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_BANDWIDTHn(x) \
    (((x) == MAIN__EDMA5) ? (0) : \
    (((x) == MAIN__EDMA3) ? (1) : \
    (((x) == WAKE__EDMA3) ? (1) : \
    (((x) == AUDIO__EDMA3) ? (1) : (-1)))))
/* @brief Has register bit fields TCD_CSR[TMC]. Note: This feature value is not the same on all EDMA instances. */
#define FSL_FEATURE_EDMA_HAS_TRANSFER_MODE (1)
/* @brief Has register bit field TCD_CSR[BWC]. */
#define FSL_FEATURE_EDMA_HAS_BANDWIDTH (1)
/* @brief Instance has register bit fields TCD_CSR[TMC]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_TRANSFER_MODEn(x) \
    (((x) == MAIN__EDMA5) ? (1) : \
    (((x) == MAIN__EDMA3) ? (0) : \
    (((x) == WAKE__EDMA3) ? (0) : \
    (((x) == AUDIO__EDMA3) ? (0) : (-1)))))
/* @brief edma5 has different tcd type. */
#define FSL_FEATURE_EDMA_TCD_TYPEn(x) \
    (((x) == MAIN__EDMA5) ? (1) : \
    (((x) == MAIN__EDMA3) ? (0) : \
    (((x) == WAKE__EDMA3) ? (0) : \
    (((x) == AUDIO__EDMA3) ? (0) : (-1)))))
/* @brief Has no register bit fields CH_SBR[SEC]. */
#define FSL_FEATURE_EDMA_HAS_NO_CH_SBR_SEC (1)
/* @brief Number of DMA channels with asynchronous request capability. Note: This feature value is not the same on all EDMA instances. */
#define FSL_FEATURE_EDMA_ASYNCHRO_REQUEST_CHANNEL_COUNT (32)

/* FREQME module features */

/* @brief FREQME instance support REF and TAR register. */
#define FSL_FEATURE_FREQME_HAS_CLOCK_SOURCE_SELECT (0)
/* @brief FREQME frequency calculation formula. 0: CTRL_R[RESULT] - 2; 1: CTRL_R[RESULT] + 1. */
#define FSL_FEATURE_FREQME_RESULT_CALCULATION_MODE (1)

/* PDM module features */

/* @brief PDM FIFO offset */
#define FSL_FEATURE_PDM_FIFO_OFFSET (4)
/* @brief PDM Channel Number Note: This feature value is not the same on all PDM instances. */
#define FSL_FEATURE_PDM_CHANNEL_NUM (6)
/* @brief PDM FIFO WIDTH Size */
#define FSL_FEATURE_PDM_FIFO_WIDTH (4)
/* @brief PDM FIFO DEPTH Size */
#define FSL_FEATURE_PDM_FIFO_DEPTH (16)
/* @brief PDM has RANGE_CTRL register */
#define FSL_FEATURE_PDM_HAS_RANGE_CTRL (1)
/* @brief PDM Has Low Frequency */
#define FSL_FEATURE_PDM_HAS_STATUS_LOW_FREQ (1)
/* @brief CLKDIV factor in Medium, High and Low Quality modes */
#define FSL_FEATURE_PDM_HIGH_QUALITY_CLKDIV_FACTOR (93)
/* @brief CLKDIV factor in Very Low Quality modes */
#define FSL_FEATURE_PDM_VERY_LOW_QUALITY_CLKDIV_FACTOR (43)
/* @brief PDM Has No VADEF Bitfield In PDM VAD0_STAT Register */
#define FSL_FEATURE_PDM_HAS_NO_VADEF (1)
/* @brief PDM has no minimum clkdiv. */
#define FSL_FEATURE_PDM_HAS_NO_MINIMUM_CLKDIV (0)
/* @brief PDM Has no FIR_RDY Bitfield In PDM STAT Register */
#define FSL_FEATURE_PDM_HAS_NO_FIR_RDY (0)
/* @brief PDM Has no DOZEN Bitfield In PDM CTRL_1 Register */
#define FSL_FEATURE_PDM_HAS_NO_DOZEN (0)
/* @brief PDM Has DEC_BYPASS Bitfield In PDM CTRL_2 Register */
#define FSL_FEATURE_PDM_HAS_DECIMATION_FILTER_BYPASS (1)
/* @brief PDM Has DC_OUT_CTRL. */
#define FSL_FEATURE_PDM_HAS_DC_OUT_CTRL (0)
/* @brief PDM Has Fixed DC CTRL VALUE. */
#define FSL_FEATURE_PDM_DC_CTRL_VALUE_FIXED (0)
/* @brief PDM Has no independent error IRQ. */
#define FSL_FEATURE_PDM_HAS_NO_INDEPENDENT_ERROR_IRQ (0)
/* @brief PDM has no hardware Voice Activity Detector */
#define FSL_FEATURE_PDM_HAS_NO_HWVAD (0)

/* SAI module features */

/* @brief Receive/transmit FIFO size in item count (register bit fields TCSR[FRDE], TCSR[FRIE], TCSR[FRF], TCR1[TFW], RCSR[FRDE], RCSR[FRIE], RCSR[FRF], RCR1[RFW], registers TFRn, RFRn). */
#define FSL_FEATURE_SAI_FIFO_COUNTn(x) (16)
/* @brief Receive/transmit channel number (register bit fields TCR3[TCE], RCR3[RCE], registers TDRn and RDRn). */
#define FSL_FEATURE_SAI_CHANNEL_COUNTn(x) \
    (((x) == AUDIO__SAI_0) ? (4) : \
    (((x) == AUDIO__SAI_1) ? (2) : \
    (((x) == AUDIO__SAI_2) ? (2) : (-1))))
/* @brief Maximum words per frame (register bit fields TCR3[WDFL], TCR4[FRSZ], TMR[TWM], RCR3[WDFL], RCR4[FRSZ], RMR[RWM]). */
#define FSL_FEATURE_SAI_MAX_WORDS_PER_FRAME (32)
/* @brief Has support of combining multiple data channel FIFOs into single channel FIFO (register bit fields TCR3[CFR], TCR4[FCOMB], TFR0[WCP], TFR1[WCP], RCR3[CFR], RCR4[FCOMB], RFR0[RCP], RFR1[RCP]). */
#define FSL_FEATURE_SAI_HAS_FIFO_COMBINE_MODE (1)
/* @brief Has packing of 8-bit and 16-bit data into each 32-bit FIFO word (register bit fields TCR4[FPACK], RCR4[FPACK]). */
#define FSL_FEATURE_SAI_HAS_FIFO_PACKING (1)
/* @brief Configures when the SAI will continue transmitting after a FIFO error has been detected (register bit fields TCR4[FCONT], RCR4[FCONT]). */
#define FSL_FEATURE_SAI_HAS_FIFO_FUNCTION_AFTER_ERROR (1)
/* @brief Configures if the frame sync is generated internally, a frame sync is only generated when the FIFO warning flag is clear or continuously (register bit fields TCR4[ONDEM], RCR4[ONDEM]). */
#define FSL_FEATURE_SAI_HAS_ON_DEMAND_MODE (1)
/* @brief Simplified bit clock source and asynchronous/synchronous mode selection (register bit fields TCR2[CLKMODE], RCR2[CLKMODE]), in comparison with the exclusively implemented TCR2[SYNC,BCS,BCI,MSEL], RCR2[SYNC,BCS,BCI,MSEL]. */
#define FSL_FEATURE_SAI_HAS_CLOCKING_MODE (0)
/* @brief Has register for configuration of the MCLK divide ratio (register bit fields MDR[FRACT], MDR[DIVIDE]). */
#define FSL_FEATURE_SAI_HAS_MCLKDIV_REGISTER (0)
/* @brief Interrupt source number */
#define FSL_FEATURE_SAI_INT_SOURCE_NUM (1)
/* @brief Has register of MCR. */
#define FSL_FEATURE_SAI_HAS_MCR (1)
/* @brief Has bit field MICS of the MCR register. */
#define FSL_FEATURE_SAI_HAS_NO_MCR_MICS (1)
/* @brief Has register of MDR */
#define FSL_FEATURE_SAI_HAS_MDR (0)
/* @brief Has support the BCLK bypass mode when BCLK = MCLK. */
#define FSL_FEATURE_SAI_HAS_BCLK_BYPASS (1)
/* @brief Has DIV bit fields of MCR register (register bit fields MCR[DIV]). */
#define FSL_FEATURE_SAI_HAS_MCR_MCLK_POST_DIV (1)
/* @brief Support Channel Mode (register bit fields TCR4[CHMOD]). */
#define FSL_FEATURE_SAI_HAS_CHANNEL_MODE (1)
/* @brief SAI has FIFO in this soc (register bit fields TCR1[TFW]. */
#define FSL_FEATURE_SAI_HAS_FIFO (1)
/* @brief Support synchronous with another SAI. */
#define FSL_FEATURE_SAI_HAS_SYNC_WITH_ANOTHER_SAI (0)
/* @brief Has Bit Clock Swap option (register bit fields RCR2[BCS]) */
#define FSL_FEATURE_SAI_HAS_BIT_CLOCK_SWAP (1)
/* @brief SAI5 and SAI6 share one irq number. */
#define FSL_FEATURE_SAI_SAI5_SAI6_SHARE_IRQ (0)

/* TRDC module features */

/* @brief Process master count. */
#define FSL_FEATURE_TRDC_PROCESSOR_MASTER_COUNT (2)
/* @brief TRDC instance has PID configuration or not. */
#define FSL_FEATURE_TRDC_INSTANCE_HAS_PID_CONFIGURATIONn(x) (0)
/* @brief TRDC domain number (reset value of HWCFG0[NDID]). */
#define FSL_FEATURE_TRDC_DOMAIN_COUNT (4)
/* @brief TRDC instance has MBC. */
#define FSL_FEATURE_TRDC_HAS_MBC (1)
/* @brief TRDC instance has MRC. Note: This feature value is not the same on all TRDC instances. */
#define FSL_FEATURE_TRDC_HAS_MRC (1)
/* @brief TRDC instance has TRDC_CR. */
#define FSL_FEATURE_TRDC_HAS_GENERAL_CONFIG (1)
/* @brief TRDC instance has MDA_Wx_y_DFMT. */
#define FSL_FEATURE_TRDC_HAS_DOMAIN_ASSIGNMENT (1)
/* @brief TRDC instance has TRDC_FDID. */
#define FSL_FEATURE_TRDC_HAS_DOMAIN_ERROR (1)
/* @brief TRDC instance has TRDC_FLW_CTL. */
#define FSL_FEATURE_TRDC_HAS_FLW (1)
/* @brief TRDC DERRLOC.MBCINST uses flat one-bit-per-MBC-instance encoding (bit N = MBC[N]). Other devices use 4-bits-per-MBC encoding (bit 4i+j = MBC[i] SLV[j]). */
#define FSL_FEATURE_TRDC_DERRLOC_MBCINST_FLAT_ENCODING (0)

/* XBAR_DSC module features */

/* @brief The width of registers of XBAR */
#define FSL_FEATURE_XBAR_DSC_REG_WIDTH (32)
/* @brief Whether support register write protect CTRL[WP] or SEL[WP] */
#define FSL_FEATURE_XBAR_DSC_HAS_REG_WP (1)

/* CACHE module features */

/* @brief L1 ICACHE line size in byte. */
#define FSL_FEATURE_L1ICACHE_LINESIZE_BYTE (32)
/* @brief L1 DCACHE line size in byte. */
#define FSL_FEATURE_L1DCACHE_LINESIZE_BYTE (32)

/* LLC module features */

/* @brief Number of ways in each LLC instance. */
#define FSL_FEATURE_LLC_WAY_COUNT (8)
/* @brief Number of sets in each LLC instance. */
#define FSL_FEATURE_LLC_SET_COUNT (256)
/* @brief Number of way partition register sets in each LLC instance. */
#define FSL_FEATURE_LLC_WAY_PARTITION_COUNT (8)

/* ENET module features */

/* @brief Support Interrupt Coalesce */
#define FSL_FEATURE_ENET_HAS_INTERRUPT_COALESCE (1)
/* @brief Queue Size. */
#define FSL_FEATURE_ENET_QUEUE (3)
/* @brief Has AVB Support. */
#define FSL_FEATURE_ENET_HAS_AVB (1)
/* @brief Has Timer Pulse Width control. */
#define FSL_FEATURE_ENET_HAS_TIMER_PWCONTROL (0)
/* @brief Has Extend MDIO Support. */
#define FSL_FEATURE_ENET_HAS_EXTEND_MDIO (1)
/* @brief Has Additional 1588 Timer Channel Interrupt. */
#define FSL_FEATURE_ENET_HAS_ADD_1588_TIMER_CHN_INT (1)
/* @brief Support Interrupt Coalesce for each instance */
#define FSL_FEATURE_ENET_INSTANCE_HAS_INTERRUPT_COALESCEn(x) (1)
/* @brief Queue Size for each instance. */
#define FSL_FEATURE_ENET_INSTANCE_QUEUEn(x) (3)
/* @brief Has AVB Support for each instance. */
#define FSL_FEATURE_ENET_INSTANCE_HAS_AVBn(x) (1)
/* @brief Has Timer Pulse Width control for each instance. */
#define FSL_FEATURE_ENET_INSTANCE_HAS_TIMER_PWCONTROLn(x) (0)
/* @brief Has Extend MDIO Support for each instance. */
#define FSL_FEATURE_ENET_INSTANCE_HAS_EXTEND_MDIOn(x) (1)
/* @brief Has Additional 1588 Timer Channel Interrupt for each instance. */
#define FSL_FEATURE_ENET_INSTANCE_HAS_ADD_1588_TIMER_CHN_INTn(x) (1)
/* @brief Has threshold for the number of frames in the receive FIFO (register bit field RSEM[STAT_SECTION_EMPTY]). */
#define FSL_FEATURE_ENET_HAS_RECEIVE_STATUS_THRESHOLD (1)
/* @brief Has transfer clock delay (register bit field ECR[TXC_DLY]). */
#define FSL_FEATURE_ENET_HAS_RGMII_TXC_DELAY (1)
/* @brief Has receive clock delay (register bit field ECR[RXC_DLY]). */
#define FSL_FEATURE_ENET_HAS_RGMII_RXC_DELAY (1)
/* @brief PTP Timestamp CAPTURE bit always returns 0 when the capture is not over. */
#define FSL_FEATURE_ENET_TIMESTAMP_CAPTURE_BIT_INVALID (0)
/* @brief ENET Has Extra Clock Gate (RW610). */
#define FSL_FEATURE_ENET_HAS_EXTRA_CLOCK_GATE (0)

/* ENET_QOS module features */

/* @brief ENET QOS Queue Tx checksum offload support bit map. */
#define FSL_FEATURE_ENET_QOS_TX_OFFLOAD_QUEUE_SUPPORT_BITMAP (0x0)

/* USBHS module features */

/* @brief EHCI module instance count */
#define FSL_FEATURE_USBHS_EHCI_COUNT (1)
/* @brief Number of endpoints supported */
#define FSL_FEATURE_USBHS_ENDPT_COUNT (8)
/* @brief If the USB controller support eUSB PHY */
#define FSL_FEATURE_USBHS_SUPPORT_EUSBn(x) (0)

/* USB module features */

/* @brief KHCI module instance count */
#define FSL_FEATURE_USB_KHCI_COUNT (1)
/* @brief HOST mode enabled */
#define FSL_FEATURE_USB_KHCI_HOST_ENABLED (1)
/* @brief OTG mode enabled */
#define FSL_FEATURE_USB_KHCI_OTG_ENABLED (1)
/* @brief Size of the USB dedicated RAM */
#define FSL_FEATURE_USB_KHCI_USB_RAM (0)
/* @brief Has KEEP_ALIVE_CTRL register */
#define FSL_FEATURE_USB_KHCI_KEEP_ALIVE_ENABLED (0)
/* @brief Has the Dynamic SOF threshold compare support */
#define FSL_FEATURE_USB_KHCI_DYNAMIC_SOF_THRESHOLD_COMPARE_ENABLED (1)
/* @brief Has the VBUS detect support */
#define FSL_FEATURE_USB_KHCI_VBUS_DETECT_ENABLED (1)
/* @brief Has the IRC48M module clock support */
#define FSL_FEATURE_USB_KHCI_IRC48M_MODULE_CLOCK_ENABLED (1)
/* @brief Number of endpoints supported */
#define FSL_FEATURE_USB_ENDPT_COUNT (16)
/* @brief Has STALL_IL/OL_DIS registers */
#define FSL_FEATURE_USB_KHCI_HAS_STALL_LOW (1)
/* @brief Has STALL_IH/OH_DIS registers */
#define FSL_FEATURE_USB_KHCI_HAS_STALL_HIGH (1)

/* USBPHY module features */

/* @brief USBPHY contain DCD analog module */
#define FSL_FEATURE_USBPHY_HAS_DCD_ANALOG (1)
/* @brief USBPHY has register TRIM_OVERRIDE_EN */
#define FSL_FEATURE_USBPHY_HAS_TRIM_OVERRIDE_EN (1)
/* @brief USBPHY is 28FDSOI */
#define FSL_FEATURE_USBPHY_28FDSOI (1)

/* USDHC module features */

/* @brief Has external DMA support (VEND_SPEC[EXT_DMA_EN]) */
#define FSL_FEATURE_USDHC_HAS_EXT_DMA (0)
/* @brief Has HS400 mode (MIX_CTRL[HS400_MODE]) */
#define FSL_FEATURE_USDHC_HAS_HS400_MODE (1)
/* @brief Has SDR50 support (HOST_CTRL_CAP[SDR50_SUPPORT]) */
#define FSL_FEATURE_USDHC_HAS_SDR50_MODE (1)
/* @brief Has SDR104 support (HOST_CTRL_CAP[SDR104_SUPPORT]) */
#define FSL_FEATURE_USDHC_HAS_SDR104_MODE (1)
/* @brief USDHC has reset control */
#define FSL_FEATURE_USDHC_HAS_RESET (0)
/* @brief USDHC has no bitfield WTMK_LVL[WR_BRST_LEN] and WTMK_LVL[RD_BRST_LEN] */
#define FSL_FEATURE_USDHC_HAS_NO_RW_BURST_LEN (1)
/* @brief If USDHC instance support 8 bit width */
#define FSL_FEATURE_USDHC_INSTANCE_SUPPORT_8_BIT_WIDTHn(x) (0)
/* @brief If USDHC instance support HS400 mode */
#define FSL_FEATURE_USDHC_INSTANCE_SUPPORT_HS400_MODEn(x) (1)
/* @brief If USDHC instance support 1v8 signal */
#define FSL_FEATURE_USDHC_INSTANCE_SUPPORT_1V8_SIGNALn(x) (1)
/* @brief Has no retuning time counter (HOST_CTRL_CAP[TIME_COUNT_RETURNING]) */
#define FSL_FEATURE_USDHC_REGISTER_HOST_CTRL_CAP_HAS_NO_RETUNING_TIME_COUNTER (1)
/* @brief Has no VSELECT bit in VEND_SPEC register */
#define FSL_FEATURE_USDHC_HAS_NO_VOLTAGE_SELECT (0)
/* @brief Has no VS18 bit in HOST_CTRL_CAP register */
#define FSL_FEATURE_USDHC_HAS_NO_VS18 (0)

/* LPADC module features */

/* @brief FIFO availability on the SoC. */
#define FSL_FEATURE_LPADC_FIFO_COUNT (2)
/* @brief Does not support two simultanious single ended conversions (bitfield TCTRL[FIFO_SEL_B]). */
#define FSL_FEATURE_LPADC_HAS_NO_TCTRL_FIFO_SEL_B (0)
/* @brief Has subsequent trigger priority (bitfield CFG[TPRICTRL]). */
#define FSL_FEATURE_LPADC_HAS_CFG_SUBSEQUENT_PRIORITY (1)
/* @brief Has differential mode (bitfield CMDLn[DIFF]). */
#define FSL_FEATURE_LPADC_HAS_CMDL_DIFF (0)
/* @brief Has channel scale (bitfield CMDLn[CSCALE]). */
#define FSL_FEATURE_LPADC_HAS_CMDL_CSCALE (1)
/* @brief Has conversion type select (bitfield CMDLn[CTYPE]). */
#define FSL_FEATURE_LPADC_HAS_CMDL_CTYPE (1)
/* @brief Has conversion resolution select  (bitfield CMDLn[MODE]). */
#define FSL_FEATURE_LPADC_HAS_CMDL_MODE (1)
/* @brief Has Wait for trigger assertion before execution (bitfield CMDHn[WAIT_TRIG]). */
#define FSL_FEATURE_LPADC_HAS_CMDH_WAIT_TRIG (1)
/* @brief Has offset calibration (bitfield CTRL[CALOFS]). */
#define FSL_FEATURE_LPADC_HAS_CTRL_CALOFS (1)
/* @brief Has gain calibration (bitfield CTRL[CAL_REQ]). */
#define FSL_FEATURE_LPADC_HAS_CTRL_CAL_REQ (1)
/* @brief Has calibration average (bitfield CTRL[CAL_AVGS]). */
#define FSL_FEATURE_LPADC_HAS_CTRL_CAL_AVGS (1)
/* @brief Has internal clock (bitfield CFG[ADCKEN]). */
#define FSL_FEATURE_LPADC_HAS_CFG_ADCKEN (0)
/* @brief Enable support for low voltage reference on option 1 reference (bitfield CFG[VREF1RNG]). */
#define FSL_FEATURE_LPADC_HAS_CFG_VREF1RNG (0)
/* @brief Has calibration (bitfield CFG[CALOFS]). */
#define FSL_FEATURE_LPADC_HAS_CFG_CALOFS (0)
/* @brief Has offset trim (register OFSTRIM). */
#define FSL_FEATURE_LPADC_HAS_OFSTRIM (0)
/* @brief Has power select (bitfield CFG[PWRSEL]). */
#define FSL_FEATURE_LPADC_HAS_CFG_PWRSEL (0)
/* @brief Has alternate channel B scale (bitfield CMDLn[ALTB_CSCALE]). */
#define FSL_FEATURE_LPADC_HAS_CMDL_ALTB_CSCALE (1)
/* @brief Has alternate channel B select enable (bitfield CMDLn[ALTBEN]). */
#define FSL_FEATURE_LPADC_HAS_CMDL_ALTBEN (1)
/* @brief Has alternate channel input (bitfield CMDLn[ALTB_ADCH]). */
#define FSL_FEATURE_LPADC_HAS_CMDL_ALTB_ADCH (1)
/* @brief Has offset calibration mode (bitfield CTRL[CALOFSMODE]). */
#define FSL_FEATURE_LPADC_HAS_CTRL_CALOFSMODE (1)
/* @brief Conversion averaged bitfiled width. */
#define FSL_FEATURE_LPADC_CONVERSIONS_AVERAGED_BITFIELD_WIDTH (4)
/* @brief Enable hardware trigger command selection */
#define FSL_FEATURE_LPADC_HAS_TCTRL_CMD_SEL (0)
/* @brief OFSTRIM availability on the SoC. */
#define FSL_FEATURE_LPADC_OFSTRIM_COUNT (0)
/* @brief Has Trigger status register. */
#define FSL_FEATURE_LPADC_HAS_TSTAT (1)
/* @brief Has B side channels. */
#define FSL_FEATURE_LPADC_HAS_B_SIDE_CHANNELS (1)
/* @brief Indicate whether the LPADC STAT register has trigger exception interrupt function (bitfield STAT[TEXC_INT]). */
#define FSL_FEATURE_LPADC_HAS_STAT_TEXC_INT (1)
/* @brief Indicate whether the LPADC STAT register has trigger completion interrupt function (bitfield STAT[TCOMP_INT]). */
#define FSL_FEATURE_LPADC_HAS_STAT_TCOMP_INT (1)
/* @brief Indicate whether the LPADC STAT register has calibration ready function (bitfield STAT[CAL_RDY]). */
#define FSL_FEATURE_LPADC_HAS_STAT_CAL_RDY (1)
/* @brief Indicate whether the LPADC STAT register has ADC active function (bitfield STAT[ADC_ACTIVE]). */
#define FSL_FEATURE_LPADC_HAS_STAT_ADC_ACTIVE (1)
/* @brief Indicate whether the LPADC IE register has trigger exception interrupt enable function (bitfield IE[TEXC_IE]). */
#define FSL_FEATURE_LPADC_HAS_IE_TEXC_IE (1)
/* @brief Indicate whether the LPADC IE register has trigger completion interrupt enable function (bitfield IE[TCOMP_IE]). */
#define FSL_FEATURE_LPADC_HAS_IE_TCOMP_IE (1)
/* @brief Indicate whether the LPADC CFG register has trigger resume/restart enable function (bitfield CFG[TRES]). */
#define FSL_FEATURE_LPADC_HAS_CFG_TRES (1)
/* @brief Indicate whether the LPADC CFG register has trigger command resume/restart enable function (bitfield CFG[TCMDRES]). */
#define FSL_FEATURE_LPADC_HAS_CFG_TCMDRES (1)
/* @brief Indicate whether the LPADC CFG register has high priority trigger exception disable function (bitfield CFG[HPT_EXDI]). */
#define FSL_FEATURE_LPADC_HAS_CFG_HPT_EXDI (1)
/* @brief Indicate LPADC CFG register TPRICTRL bitfield width. */
#define FSL_FEATURE_LPADC_CFG_TPRICTRL_BITFIELD_WIDTH (2)
/* @brief Has compare function enable (bitfield CMDHn[CMPEN]). */
#define FSL_FEATURE_LPADC_HAS_CMDH_CMPEN (1)
/* @brief Has High Speed Mode Trim Request (bitfield CTRL[CALHS]). */
#define FSL_FEATURE_LPADC_HAS_CTRL_CALHS (0)
/* @brief Has Justified Left Enable (bitfield CFG2[JLEFT]). */
#define FSL_FEATURE_LPADC_HAS_CFG2_JLEFT (1)
/* @brief Trigger Control Count. */
#define FSL_FEATURE_LPADC_TCTRL_COUNT (8)
/* @brief Buffer size of temperature sensor (CMDHa[LOOP] value to be set in process of calculate the temperature). */
#define FSL_FEATURE_LPADC_TEMP_SENS_BUFFER_SIZE (2U)
/* @brief Temperature sensor parameter A (slope). */
#define FSL_FEATURE_LPADC_TEMP_PARAMETER_SLOP (8585.66)
/* @brief Temperature sensor parameter B (offset). */
#define FSL_FEATURE_LPADC_TEMP_PARAMETER_OFFSET (308.64)
/* @brief Temperature sensor parameter ALPHA (Alpha). */
#define FSL_FEATURE_LPADC_TEMP_PARAMETER_ALPHA (11.2)

/* CRC module features */

/* @brief Has data register with name CRC */
#define FSL_FEATURE_CRC_HAS_CRC_REG (0)

/* LPDAC module features */

/* @brief FIFO size. */
#define FSL_FEATURE_LPDAC_FIFO_SIZE (16)
/* @brief Has OPAMP as buffer, speed control signal (bitfield GCR[BUF_SPD_CTRL]). */
#define FSL_FEATURE_LPDAC_HAS_GCR_BUF_SPD_CTRL (1)
/* @brief Buffer Enable(bitfield GCR[BUF_EN]). */
#define FSL_FEATURE_LPDAC_HAS_GCR_BUF_EN (1)
/* @brief Has internal reference current options. */
#define FSL_FEATURE_LPDAC_HAS_INTERNAL_REFERENCE_CURRENT (1)
/* @brief Support Period trigger mode DAC (bitfield IER[PTGCOCO_IE]). */
#define FSL_FEATURE_LPDAC_HAS_PERIODIC_TRIGGER_MODE (1)
/* @brief Optional Enable(bitfield GCR[DAC_OPTION_EN]). */
#define FSL_FEATURE_LPDAC_HAS_GCR_DAC_OPTION_EN (1)
/* @brief Has no Internal PTAT Current Reference Select (bitfield GCR[IREF_PTAT_EXT_SEL]). */
#define FSL_FEATURE_LPDAC_HAS_GCR_IREF_PTAT_EXT_SEL (0)
/* @brief Internal Current Select (bitfield GCR[IREF_INT_SEL]). */
#define FSL_FEATURE_LPDAC_HAS_GCR_IREF_INT_SEL (1)
/* @brief Internal Current Trim Register (bitfield GCR[IREF_INT_TRIM]). */
#define FSL_FEATURE_LPDAC_HAS_GCR_IREF_INT_TRIM (1)

/* EQDC module features */

/* @brief Is affected by errata with ID 051383 (Quadrature decoder CTRL[DMAEN] bit can not be cleared by SW). */
#define FSL_FEATURE_EQDC_HAS_ERRATA_051383 (1)
/* @brief If EQDC CTRL2 register has EMIP bit field. */
#define FSL_FEATURE_EQDC_CTRL2_HAS_EMIP_BIT_FIELD (0)
/* @brief If has compare interrupt. */
#define FSL_FEATURE_EQDC_HAS_NO_COMPARE_INTERRUPT (1)

/* EVTG module features */

/* @brief OPAMP support force bypass */
#define FSL_FEATURE_EVTG_HAS_FORCE_BYPASS_FLIPFLOP (0)

/* FLEXCAN module features */

/* @brief Message buffer size */
#define FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(x) (96)
/* @brief Has doze mode support (register bit field MCR[DOZE]). */
#define FSL_FEATURE_FLEXCAN_HAS_DOZE_MODE_SUPPORT (0)
/* @brief Insatnce has doze mode support (register bit field MCR[DOZE]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_DOZE_MODE_SUPPORTn(x) (0)
/* @brief Has a glitch filter on the receive pin (register bit field MCR[WAKSRC]). */
#define FSL_FEATURE_FLEXCAN_HAS_GLITCH_FILTER (1)
/* @brief Has extended interrupt mask and flag register (register IMASK2, IFLAG2). */
#define FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER (1)
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
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_FLEXIBLE_DATA_RATEn(x) (1)
/* @brief Has memory error control (register MECR). */
#define FSL_FEATURE_FLEXCAN_HAS_MEMORY_ERROR_CONTROL (1)
/* @brief Init memory base 1 */
#define FSL_FEATURE_FLEXCAN_INIT_MEMORY_BASE_1 (0x80)
/* @brief Init memory size 1 */
#define FSL_FEATURE_FLEXCAN_INIT_MEMORY_SIZE_1 (0xA60)
/* @brief Init memory base 2 */
#define FSL_FEATURE_FLEXCAN_INIT_MEMORY_BASE_2 (0xF28)
/* @brief Init memory size 2 */
#define FSL_FEATURE_FLEXCAN_INIT_MEMORY_SIZE_2 (0xD8)
/* @brief Has enhanced bit timing register (register EPRS, ENCBT, EDCBT and ETDC). */
#define FSL_FEATURE_FLEXCAN_HAS_ENHANCED_BIT_TIMING_REG (1)
/* @brief Has Pretended Networking mode support. */
#define FSL_FEATURE_FLEXCAN_HAS_PN_MODE (0)
/* @brief Has Enhanced Rx FIFO. */
#define FSL_FEATURE_FLEXCAN_HAS_ENHANCED_RX_FIFO (1)
/* @brief Has Enhanced Rx FIFO. */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_ENHANCED_RX_FIFOn(x) (1)
/* @brief Enhanced Rx FIFO size (Indicates how many CAN FD messages can be stored). */
#define FSL_FEATURE_FLEXCAN_HAS_ENHANCED_RX_FIFO_SIZE (12)
/* @brief The number of enhanced Rx FIFO filter element registers. */
#define FSL_FEATURE_FLEXCAN_HAS_ENHANCED_RX_FIFO_FILTER_MAX_NUMBER (128)
/* @brief Does not support Supervisor Mode (bitfield MCR[SUPV]. */
#define FSL_FEATURE_FLEXCAN_HAS_NO_SUPV_SUPPORT (0)
/* @brief Has more than 64 MBs. */
#define FSL_FEATURE_FLEXCAN_HAS_MORE_THAN_64_MB (0)
/* @brief Does not support self wake feature(bitfield MCR[SLFWAK]) */
#define FSL_FEATURE_FLEXCAN_HAS_NO_SLFWAK_SUPPORT (0)
/* @brief Has external time tick source (bitfield CTRL2[TIMER_SRC]). */
#define FSL_FEATURE_FLEXCAN_HAS_EXTERNAL_TIME_TICK (1)
/* @brief Instance has external time tick source (register bit field CTRL2[TIMER_SRC]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_EXTERNAL_TIME_TICKn(x) (1)
/* @brief Has Time Stamp Capture Point(bitfield CTRL2[TSTAMPCAP]). */
#define FSL_FEATURE_FLEXCAN_HAS_HIGH_RESOLUTION_TIMESTAMP (1)
/* @brief Instance has Pretended Networking option (register bit field MCR[PNET_EN]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_PN_MODEn(x) (0)
/* @brief FlexCAN maximum data rate. */
#define FSL_FEATURE_FLEXCAN_MAX_CANFD_BITRATE (8000000)
/* @brief Support payload endianness selection (bitfield CTRL2[PES]). */
#define FSL_FEATURE_FLEXCAN_HAS_ENDIANNESS_SELECTION (0)
/* @brief Enter Freeze mode before entering Disable and Stop mode. */
#define FSL_FEATURE_FLEXCAN_ENTER_FREEZE_MODE (0)
/* @brief Is affected by errata with ID 8341 (FlexCAN: Entering Freeze Mode or Low Power Mode from Normal Mode can cause the FlexCAN module to stop operating). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_8341 (0)
/* @brief Is affected by errata with ID 050443 (FlexCAN: : Receive Message Buffers may have its CODE Field corrupted if the Receive FIFO function is used in Classical CAN mode). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_050443 (0)
/* @brief Support memory error interrupt (bitfield MECR[CEI_MSK]). */
#define FSL_FEATURE_FLEXCAN_HAS_MEMORY_ERROR_INTERRUPT (1)

/* FLEXIO module features */

/* @brief FLEXIO support reset from RSTCTL */
#define FSL_FEATURE_FLEXIO_HAS_RESET (0)
/* @brief Has Shifter Status Register (FLEXIO_SHIFTSTAT) */
#define FSL_FEATURE_FLEXIO_HAS_SHIFTER_STATUS (1)
/* @brief Has Pin Data Input Register (FLEXIO_PIN) */
#define FSL_FEATURE_FLEXIO_HAS_PIN_STATUS (1)
/* @brief Has Shifter Buffer N Nibble Byte Swapped Register (FLEXIO_SHIFTBUFNBSn) */
#define FSL_FEATURE_FLEXIO_HAS_SHFT_BUFFER_NIBBLE_BYTE_SWAP (1)
/* @brief Has Shifter Buffer N Half Word Swapped Register (FLEXIO_SHIFTBUFHWSn) */
#define FSL_FEATURE_FLEXIO_HAS_SHFT_BUFFER_HALF_WORD_SWAP (1)
/* @brief Has Shifter Buffer N Nibble Swapped Register (FLEXIO_SHIFTBUFNISn) */
#define FSL_FEATURE_FLEXIO_HAS_SHFT_BUFFER_NIBBLE_SWAP (1)
/* @brief Supports Shifter State Mode (FLEXIO_SHIFTCTLn[SMOD]) */
#define FSL_FEATURE_FLEXIO_HAS_STATE_MODE (1)
/* @brief Supports Shifter Logic Mode (FLEXIO_SHIFTCTLn[SMOD]) */
#define FSL_FEATURE_FLEXIO_HAS_LOGIC_MODE (1)
/* @brief Supports paralle width (FLEXIO_SHIFTCFGn[PWIDTH]) */
#define FSL_FEATURE_FLEXIO_HAS_PARALLEL_WIDTH (1)
/* @brief Reset value of the FLEXIO_VERID register */
#define FSL_FEATURE_FLEXIO_VERID_RESET_VALUE (0x2010003)
/* @brief Reset value of the FLEXIO_PARAM register */
#define FSL_FEATURE_FLEXIO_PARAM_RESET_VALUE (0x4201010)
/* @brief Flexio DMA request base channel */
#define FSL_FEATURE_FLEXIO_DMA_REQUEST_BASE_CHANNEL (0)
/* @brief Represent the bit width of the TIMDCE field (FLEXIO_TIMCFGLn[TIMDEC]) */
#define FSL_FEATURE_FLEXIO_TIMCFG_TIMDCE_FIELD_WIDTH (3)
/* @brief Has pin input output related registers */
#define FSL_FEATURE_FLEXIO_HAS_PIN_REGISTER (1)
/* @brief Has DOZEN bit(CTRL[DOZEN]) */
#define FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT (1)

/* PWM module features */

/* @brief If (e)FlexPWM has module A channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELA (1)
/* @brief If (e)FlexPWM has module B channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELB (1)
/* @brief If (e)FlexPWM has module X channels (outputs). */
#define FSL_FEATURE_PWM_HAS_CHANNELX (1)
/* @brief If (e)FlexPWM has fractional feature. */
#define FSL_FEATURE_PWM_HAS_FRACTIONAL (1)
/* @brief If (e)FlexPWM has mux trigger source select bit field. */
#define FSL_FEATURE_PWM_HAS_MUX_TRIGGER_SOURCE_SEL (1)
/* @brief Number of submodules in each (e)FlexPWM module. */
#define FSL_FEATURE_PWM_SUBMODULE_COUNT (4)
/* @brief Number of fault channel in each (e)FlexPWM module. */
#define FSL_FEATURE_PWM_FAULT_CH_COUNT (2)
/* @brief (e)FlexPWM has no WAITEN Bitfield In CTRL2 Register. */
#define FSL_FEATURE_PWM_HAS_NO_WAITEN (0)
/* @brief If (e)FlexPWM has phase delay feature. */
#define FSL_FEATURE_PWM_HAS_PHASE_DELAY (1)
/* @brief If (e)FlexPWM has input filter capture feature. */
#define FSL_FEATURE_PWM_HAS_INPUT_FILTER_CAPTURE (1)
/* @brief If (e)FlexPWM has module capture functionality on A channels (inputs). */
#define FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELA (1)
/* @brief If (e)FlexPWM has module capture functionality on B channels (inputs). */
#define FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELB (1)
/* @brief If (e)FlexPWM has module capture functionality on X channels (inputs). */
#define FSL_FEATURE_PWM_HAS_CAPTURE_ON_CHANNELX (1)
/* @brief Is affected by errata with ID 51989. */
#define FSL_FEATURE_PWM_HAS_ERRATA_51989 (0)
/* @brief If (e)FlexPWM MASK register has UPDATE_MASK bit field. */
#define FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD (1)
/* @brief If (e)FlexPWM MCTRL2 register has STRETCH_CNT_PRSC bit field. */
#define FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD (1)
/* @brief If (e)FlexPWM MCTRL2 register has WRPROT bit field. */
#define FSL_FEATURE_PWM_MCTRL2_HAS_WRPROT_BITFIELD (0)

/* GPIO module features */

/* @brief Has GPIO attribute checker register (GACR). */
#define FSL_FEATURE_GPIO_HAS_ATTRIBUTE_CHECKER (0)
/* @brief GPIO registers width */
#define FSL_FEATURE_GPIO_REGISTERS_WIDTH (32)
/* @brief Has GPIO version ID register (VERID). */
#define FSL_FEATURE_GPIO_HAS_VERSION_INFO_REGISTER (1)
/* @brief Has secure/non-secure access protection registers (LOCK, PCNS, PCNP, ICNS, ICNP). */
#define FSL_FEATURE_GPIO_HAS_SECURE_PRIVILEGE_CONTROL (1)
/* @brief Has GPIO port input disable register (PIDR). */
#define FSL_FEATURE_GPIO_HAS_PORT_INPUT_CONTROL (1)
/* @brief Has GPIO interrupt/DMA request/trigger output selection. */
#define FSL_FEATURE_GPIO_HAS_INTERRUPT_CHANNEL_SELECT (1)

/* I3C module features */

/* @brief Has TERM bitfile in MERRWARN register. */
#define FSL_FEATURE_I3C_HAS_NO_MERRWARN_TERM (0)
/* @brief SOC has no reset driver. */
#define FSL_FEATURE_I3C_HAS_NO_RESET (1)
/* @brief Use fixed BAMATCH count, do not provide editable BAMATCH. */
#define FSL_FEATURE_I3C_HAS_NO_SCONFIG_BAMATCH (1)
/* @brief Register SCONFIG do not have IDRAND bitfield. */
#define FSL_FEATURE_I3C_HAS_NO_SCONFIG_IDRAND (1)
/* @brief Register SCONFIG has HDROK bitfield. */
#define FSL_FEATURE_I3C_HAS_HDROK (1)
/* @brief Has ERRATA_051617. */
#define FSL_FEATURE_I3C_HAS_ERRATA_051617 (0)
/* @brief SOC does not support slave IBI/MR/HJ */
#define FSL_FEATURE_I3C_HAS_NO_SLAVE_IBI_MR_HJ (0)
/* @brief Has ERRATA_052086. */
#define FSL_FEATURE_I3C_HAS_ERRATA_052086 (0)
/* @brief Has ERRATA_052123. */
#define FSL_FEATURE_I3C_HAS_ERRATA_052123 (0)
/* @brief Has IBI bytes. */
#define FSL_FEATURE_I3C_HAS_IBI_PAYLOAD_SIZE_OPTIONAL_BYTE (0)
/* @brief Has SCL delay after START. */
#define FSL_FEATURE_I3C_HAS_START_SCL_DELAY (0)
/* @brief Has no the master write data register for DMA. */
#define FSL_FEATURE_I3C_HAS_NO_MASTER_DMA_WDATA_REG (0)

/* LPI2C module features */

/* @brief Has separate DMA RX and TX requests. */
#define FSL_FEATURE_LPI2C_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FSL_FEATURE_LPI2C_FIFO_SIZEn(x) (8)
/* @brief Has dedicated interrupt for master and slave. */
#define FSL_FEATURE_LPI2C_HAS_ROLE_SPLIT_IRQ (0)
/* @brief Belong to LPFLEXCOMM */
#define FSL_FEATURE_LPI2C_IS_LPFLEXCOMM (0)

/* LPIT module features */

/* @brief Number of channels (related to number of registers LDVALn, CVALn, TCTRLn, TFLGn). */
#define FSL_FEATURE_LPIT_TIMER_COUNT (4)
/* @brief Has lifetime timer (related to existence of registers LTMR64L and LTMR64H). */
#define FSL_FEATURE_LPIT_HAS_LIFETIME_TIMER (0)
/* @brief Has shared interrupt handler (has not individual interrupt handler for each channel). */
#define FSL_FEATURE_LPIT_HAS_SHARED_IRQ_HANDLER (1)

/* LPSPI module features */

/* @brief Capacity (number of entries) of the transmit/receive FIFO. */
#define FSL_FEATURE_LPSPI_FIFO_SIZEn(x) (16)
/* @brief Has separate DMA RX and TX requests. */
#define FSL_FEATURE_LPSPI_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
/* @brief Has CCR1 (related to existence of registers CCR1). */
#define FSL_FEATURE_LPSPI_HAS_CCR1 (1)
/* @brief Has no PCSCFG bit in CFGR1 register. */
#define FSL_FEATURE_LPSPI_HAS_NO_PCSCFG (0)
/* @brief Has no WIDTH bits in TCR register. */
#define FSL_FEATURE_LPSPI_HAS_NO_MULTI_WIDTH (0)
/* @brief Belong to LPFLEXCOMM */
#define FSL_FEATURE_LPSPI_IS_LPFLEXCOMM (0)

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
#define FSL_FEATURE_LPUART_HAS_MCR (1)
/* @brief Has register Half Duplex Control. */
#define FSL_FEATURE_LPUART_HAS_HDCR (1)
/* @brief Has register Timeout. */
#define FSL_FEATURE_LPUART_HAS_TIMEOUT (1)
/* @brief UART support swap TX and RX (has bit CTRL[SWAP]). */
#define FSL_FEATURE_LPUART_HAS_CTRL_SWAP (1)
/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FSL_FEATURE_LPUART_FIFO_SIZEn(x) (16)
/* @brief UART support receive rts configuration (has bit MODIR[RTSWATER]). */
#define FSL_FEATURE_LPUART_HAS_MODIR_RTSWATER (1)

/* TMR module features */

/* @brief Has 32-bit width register. */
#define FSL_FEATURE_TMR_HAS_32BIT_REGISTER (1)

/* SINC module features */

/* @brief SINC channel count. */
#define FSL_FEATURE_SINC_CHANNEL_COUNT (4)
/* @brief SINC CACFR register has bitfield ADMASEL. */
#define FSL_FEATURE_SINC_CACFR_HAS_ADMASEL (0)
/* @brief SINC CACFR register has no bitfield PTMUX. */
#define FSL_FEATURE_SINC_CACFR_HAS_NO_PTMUX (0)

/* TPM module features */

/* @brief Number of channels. */
#define FSL_FEATURE_TPM_CHANNEL_COUNTn(x) (6)
/* @brief Has counter reset by the selected input capture event (register bits C0SC[ICRST], C1SC[ICRST], ...). */
#define FSL_FEATURE_TPM_HAS_COUNTER_RESET_BY_CAPTURE_EVENT (0)
/* @brief Has TPM_PARAM. */
#define FSL_FEATURE_TPM_HAS_PARAM (1)
/* @brief Has TPM_VERID. */
#define FSL_FEATURE_TPM_HAS_VERID (1)
/* @brief Has TPM_GLOBAL. */
#define FSL_FEATURE_TPM_HAS_GLOBAL (1)
/* @brief Has TPM_TRIG. */
#define FSL_FEATURE_TPM_HAS_TRIG (1)
/* @brief Whether TRIG register has effect. */
#define FSL_FEATURE_TPM_TRIG_HAS_EFFECTn(x) (0)
/* @brief Has counter pause on trigger. */
#define FSL_FEATURE_TPM_HAS_PAUSE_COUNTER_ON_TRIGGER (1)
/* @brief Has external trigger selection. */
#define FSL_FEATURE_TPM_HAS_EXTERNAL_TRIGGER_SELECTION (1)
/* @brief Has TPM_COMBINE register. */
#define FSL_FEATURE_TPM_HAS_COMBINE (0)
/* @brief Whether COMBINE register has effect. */
#define FSL_FEATURE_TPM_COMBINE_HAS_EFFECTn(x) (1)
/* @brief Has TPM_POL. */
#define FSL_FEATURE_TPM_HAS_POL (1)
/* @brief Whether POL register has effect. */
#define FSL_FEATURE_TPM_POL_HAS_EFFECTn(x) (0)
/* @brief Has TPM_FILTER register. */
#define FSL_FEATURE_TPM_HAS_FILTER (0)
/* @brief Whether FILTER register has effect. */
#define FSL_FEATURE_TPM_FILTER_HAS_EFFECTn(x) (1)
/* @brief Has TPM_QDCTRL register. */
#define FSL_FEATURE_TPM_HAS_QDCTRL (0)
/* @brief Whether QDCTRL register has effect. */
#define FSL_FEATURE_TPM_QDCTRL_HAS_EFFECTn(x) (1)
/* @brief Has pause level select. */
#define FSL_FEATURE_TPM_HAS_PAUSE_LEVEL_SELECT (0)
/* @brief Whether 32 bits counter has effect. */
#define FSL_FEATURE_TPM_HAS_32BIT_COUNTERn(x) (1)
/* @brief Has global time base enable. */
#define FSL_FEATURE_TPM_HAS_GLOBAL_TIME_BASE_EN (0)
/* @brief Has global time base sync. */
#define FSL_FEATURE_TPM_HAS_GLOBAL_TIME_BASE_SYNC (1)
/* @brief Is affected by errata with ID 050050 (Incorrect duty output when EPWM mode is set to PS=0 during write 1 to CnV register). */
#define FSL_FEATURE_TPM_HAS_ERRATA_050050 (0)
/* @brief Has no CPWMS field in SC register (bitfield SC[CPWMS]). */
#define FSL_FEATURE_TPM_HAS_NO_SC_CPWMS (1)

/* TRGSYNC module features */

/* @brief Number of channels. */
#define FSL_FEATURE_TRGSYNC_CHANNEL_COUNTn(x) \
    (((x) == HSP__TRGSYNC_0) ? (8) : \
    (((x) == HSP__TRGSYNC_1) ? (8) : \
    (((x) == WAKE__TRGSYNC) ? (4) : (-1))))

/* XSPI module features */

/* @brief XSPI has IPEDERR flag */
#define FSL_FEATURE_XSPI_HAS_FR_IPEDERRn(x) (1)
/* @brief XSPI has BFGENCR ALIGN bit */
#define FSL_FEATURE_XSPI_HAS_BFGENCR_ALIGNn(x) (1)
/* @brief XSPI has X16 mode */
#define FSL_FEATURE_XSPI_HAS_X16_MODEn(x) \
    (((x) == MAIN__XSPI_0) ? (0) : \
    (((x) == MAIN__XSPI_1) ? (1) : (-1)))
/* @brief Delay Elements in DDR Delay Tap */
#define FSL_FEATURE_XSPI_DLL_REF_VALUE_DDR_DELAY_TAP_NUM (4U)
/* @brief Delay Elements in SDR Delay Tap */
#define FSL_FEATURE_XSPI_DLL_REF_VALUE_SDR_DELAY_TAP_NUM (7U)
/* @brief Delay Elements in bypass offset */
#define FSL_FEATURE_XSPI_DLL_REF_VALUE_BYPASS_OFFSET_DELAY_ELEMENT_COUNT (0U)
/* @brief Bypass delay element coarse */
#define FSL_FEATURE_XSPI_DLL_REF_VALUE_BYPASS_DELAY_ELEMENT_COARSE (7U)
/* @brief Bypass delay element fine */
#define FSL_FEATURE_XSPI_DLL_REF_VALUE_BYPASS_DELAY_ELEMENT_FINE (0U)
/* @brief Autoupdate frequency threshold */
#define FSL_FEATURE_XSPI_DLL_REF_VALUE_AUTOUPDATE_FREQ_THRESHOLD (130000000UL)
/* @brief Reference counts of autoupdate */
#define FSL_FEATURE_XSPI_DLL_REF_VALUE_AUTOUPDATE_REF_COUNTER (2U)
/* @brief autoupdate resolution */
#define FSL_FEATURE_XSPI_DLL_REF_VALUE_AUTOUPDATE_RES (4U)
/* @brief Delay Elements in autoupdate_t_div16 offset */
#define FSL_FEATURE_XSPI_DLL_REF_VALUE_AUTOUPDATE_T_DIV16_OFFSET_DELAY_ELEMENT_COUNT (0U)
/* @brief Delay Elements in autoupdate offset */
#define FSL_FEATURE_XSPI_DLL_REF_VALUE_AUTOUPDATE_OFFSET_DELAY_ELEMENT_COUNT (0U)
/* @brief XSPI has DQS Latency Enable */
#define FSL_FEATURE_XSPI_HAS_DQS_LAT_EN (0)
/* @brief XSPI has END_CFG - Byte Order */
#define FSL_FEATURE_XSPI_HAS_END_CFG (0)
/* @brief XSPI has Doze Enable */
#define FSL_FEATURE_XSPI_HAS_DOZE_MODE (0)
/* @brief XSPI has Write Terminate Enable */
#define FSL_FEATURE_XSPI_HAS_WRTER_EN_BIT (1)
/* @brief Multi IRQ count for one instance */
#define FSL_FEATURE_XSPI_MULTI_IRQ_COUNT (0U)
/* @brief XSPI has DDR Mode Enable */
#define FSL_FEATURE_XSPI_HAS_DDR (1)
/* @brief XSPI has Environment Module Configuration */
#define FSL_FEATURE_XSPI_HAS_EENV (0)

/* DCIF module features */

/* @brief GAMMA INDEX MAX. */
#define FSL_FEATURE_DCIF_GAMMA_INDEX_MAX (256)
/* @brief CLUT INDEX MAX. */
#define FSL_FEATURE_DCIF_CLUT_INDEX_MAX (256)
/* @brief GAMMA RAM OFFSET. */
#define FSL_FEATURE_DCIF_GAMMA_RAM_OFFSET (0x01400UL)
/* @brief CULT RAM OFFSET. */
#define FSL_FEATURE_DCIF_CLUT_RAM_OFFSET (0x01000UL)

/* MEMORY module features */

/* @brief Memory map has offset between subsystems. */
#define FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET (1)

/* MQS module features */

/* No feature definitions */

/* LPTMR module features */

/* @brief Has shared interrupt handler with another LPTMR module. */
#define FSL_FEATURE_LPTMR_HAS_SHARED_IRQ_HANDLER (0)
/* @brief Whether LPTMR counter is 32 bits width. */
#define FSL_FEATURE_LPTMR_CNR_WIDTH_IS_32B (1)
/* @brief Has timer DMA request enable (register bit CSR[TDRE]). */
#define FSL_FEATURE_LPTMR_HAS_CSR_TDRE (1)
/* @brief Do not has prescaler clock source 0. */
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_0_SUPPORT (0)
/* @brief Do not has prescaler clock source 1. */
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_1_SUPPORT (1)
/* @brief Do not has prescaler clock source 2. */
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_2_SUPPORT (0)
/* @brief Do not has prescaler clock source 3. */
#define FSL_FEATURE_LPTMR_HAS_NO_PRESCALER_CLOCK_SOURCE_3_SUPPORT (1)

/* RTC module features */

/* @brief Has Tamper Direction Register support. */
#define FSL_FEATURE_RTC_HAS_TAMPER_DIRECTION (0)
/* @brief Has Tamper Queue Status and Control Register support. */
#define FSL_FEATURE_RTC_HAS_TAMPER_QUEUE (0)
/* @brief Has RTC Tamper 23 Filter Configuration Register support. */
#define FSL_FEATURE_RTC_HAS_FILTER23_CFG (0)
/* @brief Has WAKEUP_MODE bitfile in CTRL2 register. */
#define FSL_FEATURE_RTC_HAS_NO_CTRL2_WAKEUP_MODE (1)
/* @brief Has CLK_SEL bitfile in CTRL register. */
#define FSL_FEATURE_RTC_HAS_CLOCK_SELECT (0)
/* @brief Has CLKO_DIS bitfile in CTRL register. */
#define FSL_FEATURE_RTC_HAS_CLOCK_OUTPUT_DISABLE (0)
/* @brief Has No Tamper in RTC. */
#define FSL_FEATURE_RTC_HAS_NO_TAMPER_FEATURE (1)
/* @brief Has CPU_LOW_VOLT bitfile in STATUS register. */
#define FSL_FEATURE_RTC_HAS_NO_CPU_LOW_VOLT_FLAG (1)
/* @brief Has RST_SRC bitfile in STATUS register. */
#define FSL_FEATURE_RTC_HAS_NO_RST_SRC_FLAG (1)
/* @brief Has GP_DATA_REG register. */
#define FSL_FEATURE_RTC_HAS_NO_GP_DATA_REG (1)
/* @brief Has TIMER_STB_MASK bitfile in CTRL register. */
#define FSL_FEATURE_RTC_HAS_NO_TIMER_STB_MASK (1)
/* @brief Has RTC Tamper 45 Filter Configuration Register support */
#define FSL_FEATURE_RTC_HAS_FILTER45_CFG (0)
/* @brief Has RTC Tamper 67 Filter Configuration Register support */
#define FSL_FEATURE_RTC_HAS_FILTER67_CFG (0)
/* @brief Has RTC Minutes Count Down Timer Register support */
#define FSL_FEATURE_RTC_HAS_MINUTES_TIMER_FEATURE (0)
/* @brief Has RTC BCD mode support */
#define FSL_FEATURE_RTC_HAS_BCD_MODE (0)

/* ACMP module features */

/* @brief Has CMP_C3. */
#define FSL_FEATURE_ACMP_HAS_C3_REG (1)
/* @brief Has C0 LINKEN Bit */
#define FSL_FEATURE_ACMP_HAS_C0_LINKEN_BIT (1)
/* @brief Has C0 OFFSET Bit */
#define FSL_FEATURE_ACMP_HAS_C0_OFFSET_BIT (0)
/* @brief Has C1 INPSEL Bit */
#define FSL_FEATURE_ACMP_HAS_C1_INPSEL_BIT (0)
/* @brief Has C1 INNSEL Bit */
#define FSL_FEATURE_ACMP_HAS_C1_INNSEL_BIT (0)
/* @brief Has C1 DACOE Bit */
#define FSL_FEATURE_ACMP_HAS_C1_DACOE_BIT (0)
/* @brief Has C1 DMODE Bit */
#define FSL_FEATURE_ACMP_HAS_C1_DMODE_BIT (1)
/* @brief Has C2 RRE Bit */
#define FSL_FEATURE_ACMP_HAS_C2_RRE_BIT (0)
/* @brief Has C0 HYSTCTR Bit */
#define FSL_FEATURE_ACMP_HAS_C0_HYSTCTR_BIT (1)
/* @brief If support round-robin mode */
#define FSL_FEATURE_ACMP_HAS_NO_ROUNDROBIN_MODE (0)
/* @brief If support 3v domain */
#define FSL_FEATURE_ACMP_HAS_NO_3V_DOMAIN (0)
/* @brief If support window mode */
#define FSL_FEATURE_ACMP_HAS_NO_WINDOW_MODE (0)
/* @brief If support filter mode */
#define FSL_FEATURE_ACMP_HAS_NO_FILTER_MODE (0)
/* @brief Has No C0 SE Bit */
#define FSL_FEATURE_ACMP_HAS_NO_C0_SE_BIT (0)
/* @brief Has C3 RDIVE Bit */
#define FSL_FEATURE_ACMP_HAS_C3_RDIVE_BIT (0)
/* @brief Has C3 PCHCTEN Bit */
#define FSL_FEATURE_ACMP_HAS_CONTINUOUS_MODE (0)

/* EWM module features */

/* @brief Has clock select (register CLKCTRL). */
#define FSL_FEATURE_EWM_HAS_CLOCK_SELECT (0)
/* @brief Has clock prescaler (register CLKPRESCALER). */
#define FSL_FEATURE_EWM_HAS_PRESCALER (1)

/* SWT module features */

/* @brief Has ERRATA_052226. */
#define FSL_FEATURE_SWT_HAS_ERRATA_052226 (0)

#endif /* _MIMXRT2663_FEATURES_H_ */

