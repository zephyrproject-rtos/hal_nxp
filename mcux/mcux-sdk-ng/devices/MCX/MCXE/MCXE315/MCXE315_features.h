/*
** ###################################################################
**     Version:             rev. 1.0, 2024-11-18
**     Build:               b250520
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
**     - rev. 1.0 (2024-11-18)
**
**
** ###################################################################
*/

#ifndef _MCXE315_FEATURES_H_
#define _MCXE315_FEATURES_H_

/* SOC module features */

/* @brief ADC availability on the SoC. */
#define FSL_FEATURE_SOC_ADC_COUNT (2)
/* @brief AIPS availability on the SoC. */
#define FSL_FEATURE_SOC_AIPS_COUNT (2)
/* @brief CRC availability on the SoC. */
#define FSL_FEATURE_SOC_CRC_COUNT (1)
/* @brief DMAMUX availability on the SoC. */
#define FSL_FEATURE_SOC_DMAMUX_COUNT (2)
/* @brief EDMA availability on the SoC. */
#define FSL_FEATURE_SOC_EDMA_COUNT (1)
/* @brief EIM availability on the SoC. */
#define FSL_FEATURE_SOC_EIM_COUNT (1)
/* @brief EMIOS availability on the SoC. */
#define FSL_FEATURE_SOC_EMIOS_COUNT (2)
/* @brief FLEXCAN availability on the SoC. */
#define FSL_FEATURE_SOC_FLEXCAN_COUNT (3)
/* @brief FLEXIO availability on the SoC. */
#define FSL_FEATURE_SOC_FLEXIO_COUNT (1)
/* @brief LPCMP availability on the SoC. */
#define FSL_FEATURE_SOC_LPCMP_COUNT (1)
/* @brief LPI2C availability on the SoC. */
#define FSL_FEATURE_SOC_LPI2C_COUNT (2)
/* @brief LPSPI availability on the SoC. */
#define FSL_FEATURE_SOC_LPSPI_COUNT (4)
/* @brief LPUART availability on the SoC. */
#define FSL_FEATURE_SOC_LPUART_COUNT (4)
/* @brief MCM availability on the SoC. */
#define FSL_FEATURE_SOC_MCM_COUNT (1)
/* @brief MSCM availability on the SoC. */
#define FSL_FEATURE_SOC_MSCM_COUNT (1)
/* @brief MU availability on the SoC. */
#define FSL_FEATURE_SOC_MU_COUNT (2)
/* @brief PIT availability on the SoC. */
#define FSL_FEATURE_SOC_PIT_COUNT (2)
/* @brief PMC availability on the SoC. */
#define FSL_FEATURE_SOC_PMC_COUNT (1)
/* @brief RTC availability on the SoC. */
#define FSL_FEATURE_SOC_RTC_COUNT (1)
/* @brief STM availability on the SoC. */
#define FSL_FEATURE_SOC_STM_COUNT (1)
/* @brief TRGMUX availability on the SoC. */
#define FSL_FEATURE_SOC_TRGMUX_COUNT (1)
/* @brief WKPU availability on the SoC. */
#define FSL_FEATURE_SOC_WKPU_COUNT (1)
/* @brief XRDC availability on the SoC. */
#define FSL_FEATURE_SOC_XRDC_COUNT (1)

/* ADC module features */

/* @brief Channel group counts of ADC. */
#define FSL_FEATURE_ADC_CHANNEL_GROUPS_COUNT (3)
/* @brief Threshold counts of ADC. */
#define FSL_FEATURE_ADC_THRESHOLDS_COUNT (4)
/* @brief Self-test threshold counts of ADC. */
#define FSL_FEATURE_ADC_SELF_TEST_THRESHOLDS_COUNT (5)
/* @brief Has register bit fields MCR[ADCLKSE]. */
#define FSL_FEATURE_ADC_HAS_MCR_ADCLKSE (0)
/* @brief Has register bit fields MCR[XSTRTEN]. */
#define FSL_FEATURE_ADC_HAS_MCR_XSTRTEN (1)
/* @brief Has BCTU mode. */
#define FSL_FEATURE_ADC_HAS_BCTUMODE (1)
/* @brief Has register bit fields MCR[ADCLKSEL]. */
#define FSL_FEATURE_ADC_HAS_MCR_ADCLKSEL (1)
/* @brief Has register bit fields MCR[AVGS]. */
#define FSL_FEATURE_ADC_HAS_MCR_AVGS (1)
/* @brief Has register CALSTAT. */
#define FSL_FEATURE_ADC_HAS_CALSTAT (0)
/* @brief Has register USROFSGN. */
#define FSL_FEATURE_ADC_HAS_USROFSGN (0)
/* @brief Has register STDR2. */
#define FSL_FEATURE_ADC_HAS_STDR2 (0)
/* @brief Has register CALBISTREG. */
#define FSL_FEATURE_ADC_HAS_CALBISTREG (1)
/* @brief Has register DSDR. */
#define FSL_FEATURE_ADC_HAS_DSDR (1)
/* @brief Has register OFSGNUSR. */
#define FSL_FEATURE_ADC_HAS_OFSGNUSR (1)
/* @brief Has register AMSIO. */
#define FSL_FEATURE_ADC_HAS_AMSIO (1)
/* @brief Has register CAL2. */
#define FSL_FEATURE_ADC_HAS_CAL2 (1)
/* @brief Has external trigger or not. */
#define FSL_FEATURE_ADC_HAS_EXTERNAL_TRIGGER (1)
/* @brief Supports Group3.  */
#define FSL_FEATURE_ADC_INSTANCE_SUPPORT_GROUP3n(x) (1)

/* BCTU module features */

/* @brief ADC Result Data register count */
#define FSL_FEATURE_BCTU_ADCDR_COUNT (2)

/* SCB module features */

/* @brief L1 ICACHE line size in byte. */
#define FSL_FEATURE_L1ICACHE_LINESIZE_BYTE (32)
/* @brief L1 DCACHE line size in byte. */
#define FSL_FEATURE_L1DCACHE_LINESIZE_BYTE (32)

/* CMU_FC module features */

/* No feature definitions */

/* CMU_FM module features */

/* No feature definitions */

/* CRC module features */

/* @brief Has data register with name CRC */
#define FSL_FEATURE_CRC_HAS_CRC_REG (0)

/* DCM_GPR module features */

/* @brief Has bit DCMRWF1[VDD_HV_B_VLT_DVDR_EN]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWF1_VDD_HV_B_VLT_DVDR_EN (0)
/* @brief Has bit DCMRWF1[VDD_1_5_VLT_DVDR_EN]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWF1_VDD_1_5_VLT_DVDR_EN (0)
/* @brief Has bit DCMRWF2[SIRC_TRIM_BYP_STDBY_EXT]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT (0)
/* @brief Has bit DCMRWF2[PMC_TRIM_RGM_DCF__BYP_STDBY_EXT]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWF2_PMC_TRIM_RGM_DCF__BYP_STDBY_EXT (0)
/* @brief Has bit DCMRWD6[EMIOS2_DBG_DIS_CM7_0]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_EMIOS2_DBG_DIS_CM7_0 (0)
/* @brief Has bit DCMRWD6[SWT1_DBG_DIS_CM7_0]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_SWT1_DBG_DIS_CM7_0 (0)
/* @brief Has bit DCMRWD6[STM1_DBG_DIS_CM7_0]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_STM1_DBG_DIS_CM7_0 (0)
/* @brief Has bit DCMRWD6[PIT2_DBG_DIS_CM7_0]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_PIT2_DBG_DIS_CM7_0 (0)
/* @brief Has bit DCMRWD6[LPSPI4_DBG_DIS_CM7_0]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_LPSPI4_DBG_DIS_CM7_0 (0)
/* @brief Has bit DCMRWD6[LPSPI5_DBG_DIS_CM7_0]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_LPSPI5_DBG_DIS_CM7_0 (0)
/* @brief Has bit DCMRWD6[FLEXCAN3_DBG_DIS_CM7_0]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_FLEXCAN3_DBG_DIS_CM7_0 (0)
/* @brief Has bit DCMRWD6[FLEXCAN4_DBG_DIS_CM7_0]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_FLEXCAN4_DBG_DIS_CM7_0 (0)
/* @brief Has bit DCMRWD6[FLEXCAN5_DBG_DIS_CM7_0]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_FLEXCAN5_DBG_DIS_CM7_0 (0)
/* @brief Has bit DCMRWD6[SAI0_DBG_DIS_CM7_0]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_SAI0_DBG_DIS_CM7_0 (0)
/* @brief Has bit DCMRWD6[SAI1_DBG_DIS_CM7_0]. */
#define FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_SAI1_DBG_DIS_CM7_0 (0)

/* DMAMUX module features */

/* @brief Number of DMA channels (related to number of register CHCFGn). */
#define FSL_FEATURE_DMAMUX_MODULE_CHANNEL (8)
/* @brief Total number of DMA channels on all modules. */
#define FSL_FEATURE_DMAMUX_DMAMUX_CHANNELS (16)
/* @brief Has the periodic trigger capability for the triggered DMA channel (register bit CHCFG0[TRIG]). */
#define FSL_FEATURE_DMAMUX_HAS_TRIG (1)
/* @brief Has DMA Channel Always ON function (register bit CHCFG0[A_ON]). */
#define FSL_FEATURE_DMAMUX_HAS_A_ON (0)
/* @brief Register CHCFGn width. */
#define FSL_FEATURE_DMAMUX_CHCFG_REGISTER_WIDTH (8)
/* @brief Register CHCFGn sorted in order 3, 2 ,1 ,0 ,7 ,6 ,5 ,4 ... */
#define FSL_FEATURE_DMAMUX_CHANNEL_NEEDS_ENDIAN_CONVERT (1)

/* EDMA module features */

/* @brief Number of DMA channels (related to number of registers TCD, DCHPRI, bit fields ERQ[ERQn], EEI[EEIn], INT[INTn], ERR[ERRn], HRS[HRSn] and bit field widths ES[ERRCHN], CEEI[CEEI], SEEI[SEEI], CERQ[CERQ], SERQ[SERQ], CDNE[CDNE], SSRT[SSRT], CERR[CERR], CINT[CINT], TCDn_CITER_ELINKYES[LINKCH], TCDn_CSR[MAJORLINKCH], TCDn_BITER_ELINKYES[LINKCH]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL (12)
/* @brief If 8 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_8_BYTES_TRANSFER (1)
/* @brief Number of DMA channel groups (register bit fields CR[ERGA], CR[GRPnPRI], ES[GPE], DCHPRIn[GRPPRI]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_CHANNEL_GROUP_COUNT (1)
/* @brief If 16 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_16_BYTES_TRANSFER (1)
/* @brief Has DMA_Error interrupt vector. */
#define FSL_FEATURE_EDMA_HAS_ERROR_IRQ (1)
/* @brief If 64 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_64_BYTES_TRANSFER (1)
/* @brief Has register access permission. */
#define FSL_FEATURE_HAVE_DMA_CONTROL_REGISTER_ACCESS_PERMISSION (0)
/* @brief If 128 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_128_BYTES_TRANSFER (0)
/* @brief If channel clock controlled independently */
#define FSL_FEATURE_EDMA_CHANNEL_HAS_OWN_CLOCK_GATE (1)
/* @brief If 128 bytes transfer supported. */
#define FSL_FEATURE_EDMA_INSTANCE_SUPPORT_128_BYTES_TRANSFERn(x) (1)
/* @brief Number of channel for each EDMA instance, (only defined for soc with different channel numbers for difference instance) */
#define FSL_FEATURE_EDMA_INSTANCE_CHANNELn(x) (12)
/* @brief Has register CH_CSR. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_CONFIG (1)
/* @brief Has no register bit fields MP_CSR[EBW]. */
#define FSL_FEATURE_EDMA_HAS_NO_MP_CSR_EBW (1)
/* @brief Has channel mux */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_MUX (0)
/* @brief If dma has common clock gate */
#define FSL_FEATURE_EDMA_HAS_COMMON_CLOCK_GATE (0)
/* @brief Instance has channel mux */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_MUXn(x) (0)
/* @brief If dma channel IRQ support parameter */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL_IRQ_ENTRY_SUPPORT_PARAMETER (0)
/* @brief Has register CH_SBR. */
#define FSL_FEATURE_EDMA_HAS_SBR (1)
/* @brief NBYTES must be multiple of 8 when using scatter gather. */
#define FSL_FEATURE_EDMA_HAS_ERRATA_51327 (0)
/* @brief Has no register bit fields CH_SBR[ATTR]. */
#define FSL_FEATURE_EDMA_HAS_NO_CH_SBR_ATTR (0)
/* @brief NBYTES must be multiple of 8 when using scatter gather. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_ERRATA_51327n(x) (0)
/* @brief Has register bit field CH_CSR[SWAP]. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_SWAP_SIZE (0)
/* @brief Has register bit fields MP_CSR[GMRC]. */
#define FSL_FEATURE_EDMA_HAS_GLOBAL_MASTER_ID_REPLICATION (1)
/* @brief Instance has register bit field CH_CSR[SWAP]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_SWAP_SIZEn(x) (0)
/* @brief Whether has prot register. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_PROT_REGISTERn(x) (0)
/* @brief Has register bit field CH_SBR[INSTR]. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_ACCESS_TYPE (0)
/* @brief Whether has MP channel mux. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_MP_CHANNEL_MUXn(x) (0)
/* @brief Instance has register bit field CH_SBR[INSTR]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_ACCESS_TYPEn(x) (0)
/* @brief Whether has SOC level request enable control. */
#define FSL_FEATURE_EDMA_HAS_SOC_REQUEST_ENABLE (0)
/* @brief Has register bit fields CH_MATTR[WCACHE], CH_MATTR[RCACHE]. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_MEMORY_ATTRIBUTE (0)
/* @brief Instance has register CH_MATTR. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_MEMORY_ATTRIBUTEn(x) (0)
/* @brief Has register bit field CH_CSR[SIGNEXT]. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_SIGN_EXTENSION (0)
/* @brief Instance Has register bit field CH_CSR[SIGNEXT]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_SIGN_EXTENSIONn(x) (0)
/* @brief Has register bit field TCD_CSR[BWC]. */
#define FSL_FEATURE_EDMA_HAS_BANDWIDTH (1)
/* @brief Instance has register bit field TCD_CSR[BWC]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_BANDWIDTHn(x) (1)
/* @brief Has register bit fields TCD_CSR[TMC]. */
#define FSL_FEATURE_EDMA_HAS_TRANSFER_MODE (0)
/* @brief Instance has register bit fields TCD_CSR[TMC]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_TRANSFER_MODEn(x) (0)
/* @brief Has no register bit fields CH_SBR[SEC]. */
#define FSL_FEATURE_EDMA_HAS_NO_CH_SBR_SEC (1)
/* @brief edma5 has different tcd type. */
#define FSL_FEATURE_EDMA_TCD_TYPEn(x) (0)
/* @brief Number of DMA channels with asynchronous request capability. */
#define FSL_FEATURE_EDMA_ASYNCHRO_REQUEST_CHANNEL_COUNT (12)

/* FLASH_C40 module features */

/* @brief Code flash block size. */
#define FSL_FEATURE_FLASH_C40_BLOCK_SIZE_CODE (0x00080000)
/* @brief Data flash block size. */
#define FSL_FEATURE_FLASH_C40_BLOCK_SIZE_DATA (0x00010000)
/* @brief Code flash block count. */
#define FSL_FEATURE_FLASH_C40_BLOCK_COUNT_CODE (1)

/* FLEXCAN module features */

/* @brief Message buffer size */
#define FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(x) (64)
/* @brief Has doze mode support (register bit field MCR[DOZE]). */
#define FSL_FEATURE_FLEXCAN_HAS_DOZE_MODE_SUPPORT (0)
/* @brief Insatnce has doze mode support (register bit field MCR[DOZE]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_DOZE_MODE_SUPPORTn(x) (0)
/* @brief Has a glitch filter on the receive pin (register bit field MCR[WAKSRC]). */
#define FSL_FEATURE_FLEXCAN_HAS_GLITCH_FILTER (0)
/* @brief Has extended interrupt mask and flag register (register IMASK2, IFLAG2). */
#define FSL_FEATURE_FLEXCAN_HAS_EXTENDED_FLAG_REGISTER (1)
/* @brief Instance has extended bit timing register (register CBT). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_EXTENDED_TIMING_REGISTERn(x) (1)
/* @brief Has a receive FIFO DMA feature (register bit field MCR[DMA]). */
#define FSL_FEATURE_FLEXCAN_HAS_RX_FIFO_DMA (1)
/* @brief Instance has a receive FIFO DMA feature (register bit field MCR[DMA]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_RX_FIFO_DMAn(x) (1)
/* @brief Remove CAN Engine Clock Source Selection from unsupported part. */
#define FSL_FEATURE_FLEXCAN_SUPPORT_ENGINE_CLK_SEL_REMOVE (1)
/* @brief Instance remove CAN Engine Clock Source Selection from unsupported part. */
#define FSL_FEATURE_FLEXCAN_INSTANCE_SUPPORT_ENGINE_CLK_SEL_REMOVEn(x) (1)
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
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_ENHANCED_RX_FIFOn(x) \
    (((x) == FLEXCAN_1) ? (0) : \
    (((x) == FLEXCAN_2) ? (0) : \
    (((x) == FLEXCAN_0) ? (1) : (-1))))
/* @brief Does not support Supervisor Mode (bitfield MCR[SUPV]. */
#define FSL_FEATURE_FLEXCAN_HAS_NO_SUPV_SUPPORT (0)
/* @brief Enhanced Rx FIFO size (Indicates how many CAN FD messages can be stored). */
#define FSL_FEATURE_FLEXCAN_HAS_ENHANCED_RX_FIFO_SIZE (20)
/* @brief Has more than 64 MBs. */
#define FSL_FEATURE_FLEXCAN_HAS_MORE_THAN_64_MB (1)
/* @brief The number of enhanced Rx FIFO filter element registers. */
#define FSL_FEATURE_FLEXCAN_HAS_ENHANCED_RX_FIFO_FILTER_MAX_NUMBER (128)
/* @brief Does not support self wake feature(bitfield MCR[SLFWAK]) */
#define FSL_FEATURE_FLEXCAN_HAS_NO_SLFWAK_SUPPORT (1)
/* @brief Has external time tick source (bitfield CTRL2[TIMER_SRC]). */
#define FSL_FEATURE_FLEXCAN_HAS_EXTERNAL_TIME_TICK (1)
/* @brief Instance has external time tick source (register bit field CTRL2[TIMER_SRC]). */
#define FSL_FEATURE_FLEXCAN_INSTANCE_HAS_EXTERNAL_TIME_TICKn(x) (1)
/* @brief Has Time Stamp Capture Point(bitfield CTRL2[TSTAMPCAP]). */
#define FSL_FEATURE_FLEXCAN_HAS_HIGH_RESOLUTION_TIMESTAMP (1)
/* @brief The max amount of Message Buffer IRQ entry for CAN instances. */
#define FSL_FEATURE_FLEXCAN_MB_IRQ_COUNT (3)
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

/* FLEXIO module features */

/* @brief Has DOZEN bit(CTRL[DOZEN]) */
#define FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT (0)
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
#define FSL_FEATURE_FLEXIO_PARAM_RESET_VALUE (0x4100808)
/* @brief Flexio DMA request base channel */
#define FSL_FEATURE_FLEXIO_DMA_REQUEST_BASE_CHANNEL (0)
/* @brief Represent the bit width of the TIMDCE field (FLEXIO_TIMCFGLn[TIMDEC]) */
#define FSL_FEATURE_FLEXIO_TIMCFG_TIMDCE_FIELD_WIDTH (3)
/* @brief Has pin input output related registers */
#define FSL_FEATURE_FLEXIO_HAS_PIN_REGISTER (1)

/* INTM module features */

/* @brief Up to 4 programmable interrupt monitors */
#define FSL_FEATURE_INTM_MONITOR_COUNT (4)

/* LCU module features */

/* No feature definitions */

/* LPCMP module features */

/* @brief Has CCR1 FUNC_CLK_SEL bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CCR1_FUNC_CLK_SEL (0)
/* @brief Has IER RRF_IE bitfield. */
#define FSL_FEATURE_LPCMP_HAS_IER_RRF_IE (1)
/* @brief Has CSR RRF bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CSR_RRF (1)
/* @brief Has Round Robin mode (related to existence of registers RRCR0). */
#define FSL_FEATURE_LPCMP_HAS_ROUNDROBIN_MODE (1)
/* @brief Has window mode (related to existence of CCR1.WINDOW_CLS). */
#define FSL_FEATURE_LPCMP_HAS_WINDOW_CONTROL (1)
/* @brief Has no CCR0 CMP_STOP_EN bitfield. */
#define FSL_FEATURE_LPCMP_HAS_NO_CCR0_CMP_STOP_EN (0)
/* @brief Has RRCR0 RR_CLK_SEL bitfield. */
#define FSL_FEATURE_LPCMP_HAS_RRCR0_RR_CLK_SEL (0)
/* @brief Has RRCR0 RR_TRG_SEL bitfield. */
#define FSL_FEATURE_LPCMP_HAS_RRCR0_RR_TRG_SEL (0)
/* @brief Has RRCR0 RR_SAMPLE_CNT bitfield. */
#define FSL_FEATURE_LPCMP_HAS_RRCR0_RR_SAMPLE_CNT (0)
/* @brief Has RRCR0 RR_SAMPLE_THRESHOLD bitfield. */
#define FSL_FEATURE_LPCMP_HAS_RRCR0_RR_SAMPLE_THRESHOLD (0)
/* @brief Has CCR2 INPSEL bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CCR2_INPSEL (1)
/* @brief Has CCR2 INMSEL bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CCR2_INMSEL (1)
/* @brief Has CCR2 CMP_NPMD bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CCR2_CMP_NPMD (0)
/* @brief Has DCR DAC_HPMD bitfield. */
#define FSL_FEATURE_LPCMP_HAS_DCR_DAC_HPMD (0)
/* @brief Has CCR0 LINKEN bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CCR0_LINKEN (1)
/* @brief Has RRCR2 register. */
#define FSL_FEATURE_LPCMP_HAS_RRCR2 (0)
/* @brief Has CCR0 CMP_STOP_EN bitfield. */
#define FSL_FEATURE_LPCMP_HAS_CCR0_CMP_STOP_EN (1)

/* LPI2C module features */

/* @brief Has separate DMA RX and TX requests. */
#define FSL_FEATURE_LPI2C_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FSL_FEATURE_LPI2C_FIFO_SIZEn(x) (4)
/* @brief Has dedicated interrupt for master and slave. */
#define FSL_FEATURE_LPI2C_HAS_ROLE_SPLIT_IRQ (0)

/* LPSPI module features */

/* @brief Capacity (number of entries) of the transmit/receive FIFO. */
#define FSL_FEATURE_LPSPI_FIFO_SIZEn(x) (4)
/* @brief Has separate DMA RX and TX requests. */
#define FSL_FEATURE_LPSPI_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
/* @brief Has CCR1 (related to existence of registers CCR1). */
#define FSL_FEATURE_LPSPI_HAS_CCR1 (1)
/* @brief Has no PCSCFG bit in CFGR1 register. */
#define FSL_FEATURE_LPSPI_HAS_NO_PCSCFG (0)
/* @brief Has no WIDTH bits in TCR register. */
#define FSL_FEATURE_LPSPI_HAS_NO_MULTI_WIDTH (0)

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
#define FSL_FEATURE_LPUART_FIFO_SIZEn(x) \
    (((x) == LPUART_0) ? (16) : \
    (((x) == LPUART_1) ? (16) : \
    (((x) == LPUART_2) ? (4) : \
    (((x) == LPUART_3) ? (4) : (-1)))))
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
#define FSL_FEATURE_LPUART_HAS_CTRL_SWAP (0)

/* MCM module features */

/* @brief Has cache parity error ISCR[CPEE]. */
#define FSL_FEATURE_MCM_HAS_CACHE_PARITY_ERROR (0)
/* @brief Has cache write buffer error ISCR[CWBEE]. */
#define FSL_FEATURE_MCM_HAS_CACHE_WRITE_BUFFER_ERROR (0)
/* @brief LMD lock. LMDR2[RO]. */
#define FSL_FEATURE_MCM_HAS_LMD_RO (0)
/* @brief MCM has PC Parity. LMDR2[PCPME] or LMDR2[PCPFE]. */
#define FSL_FEATURE_MCM_HAS_PC_PARITY (0)
/* @brief Has buffer fault, register FATR, FDR, FADR. */
#define FSL_FEATURE_MCM_HAS_BUFFER_FAULT (0)
/* @brief Has register CPCR2. */
#define FSL_FEATURE_MCM_HAS_CPCR2 (0)
/* @brief Has LMEM fault, register LMFAR, LMFDLR, LMFDHR, LMFATR. */
#define FSL_FEATURE_MCM_HAS_LMEM_FAULT (0)
/* @brief  MCM has LMEM control, register LMPECR, LMPEIR. */
#define FSL_FEATURE_MCM_HAS_LMEM_PARITY (0)

/* MC_CGM module features */

/* @brief Has Mux0 Divider 5 */
#define FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV (0)
/* @brief Has MUX_1 Registers */
#define FSL_FEATURE_MC_CGM_HAS_MUX_1 (1)
/* @brief Has MUX_2 Registers */
#define FSL_FEATURE_MC_CGM_HAS_MUX_2 (0)
/* @brief Has MUX_4 Registers */
#define FSL_FEATURE_MC_CGM_HAS_MUX_4 (0)
/* @brief Has MUX_7 Registers */
#define FSL_FEATURE_MC_CGM_HAS_MUX_7 (0)
/* @brief Has MUX_8 Registers */
#define FSL_FEATURE_MC_CGM_HAS_MUX_8 (0)
/* @brief Has MUX_9 Registers */
#define FSL_FEATURE_MC_CGM_HAS_MUX_9 (0)
/* @brief Has MUX_10 Registers */
#define FSL_FEATURE_MC_CGM_HAS_MUX_10 (0)
/* @brief Has SXOSC module */
#define FSL_FEATURE_MC_CGM_HAS_SXOSC (0)

/* MC_ME module features */

/* @brief Has Partition 2 process configuration Registers */
#define FSL_FEATURE_MC_ME_HAS_PRTN2 (0)

/* MC_RGM module features */

/* No feature definitions */

/* MEMORY module features */

/* @brief Memory map has offset between subsystems. */
#define FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET (1)

/* MSCM module features */

/* @brief Number of configuration information for processors. */
#define FSL_FEATURE_MSCM_HAS_CP_COUNT (1)
/* @brief Has data cache. */
#define FSL_FEATURE_MSCM_HAS_DATACACHE (0)

/* MU module features */

/* @brief MU side for current core */
#define FSL_FEATURE_MU_SIDE_B (1)
/* @brief MU supports reset assert interrupt. CIER0[RAIE] or CR[RAIE] or BCR[RAIE]. */
#define FSL_FEATURE_MU_HAS_RESET_ASSERT_INT (0)
/* @brief MU supports reset de-assert interrupt. CR[RDIE] or BCR[RDIE]. */
#define FSL_FEATURE_MU_HAS_RESET_DEASSERT_INT (0)
/* @brief MU does not support core status. Register CSSR0 or CSR0. */
#define FSL_FEATURE_MU_NO_CORE_STATUS (1)
/* @brief MU does not support NMI. Register bit CCR0[NMI]. */
#define FSL_FEATURE_MU_NO_NMI (1)
/* @brief MU does not support core event pending. Register bit SR[CEP]. */
#define FSL_FEATURE_MU_NO_CEP (1)
/* @brief MU supports Power-Down mode entry interrupt. CIER0[PDIE] */
#define FSL_FEATURE_MU_HAS_PD_INT (0)
/* @brief MU supports STOP mode entry interrupt. CIER0[STOPIE] */
#define FSL_FEATURE_MU_HAS_STOP_INT (0)
/* @brief MU supports WAIT mode entry interrupt. CIER0[WAITIE] */
#define FSL_FEATURE_MU_HAS_WAIT_INT (0)
/* @brief MU supports HALT mode entry interrupt. CIER0[HALTIE] */
#define FSL_FEATURE_MU_HAS_HALT_INT (0)
/* @brief MU supports RUN mode entry interrupt. CIER0[RUNIE] */
#define FSL_FEATURE_MU_HAS_RUN_INT (0)
/* @brief MU supports hardware reset interrupt. CSSR0[HRIP] or CSR0[HRIP]. */
#define FSL_FEATURE_MU_HAS_SR_HRIP (0)
/* @brief MU supports reset interrupt. Register bit SR[MURIP]. */
#define FSL_FEATURE_MU_HAS_SR_MURIP (1)
/* @brief MU does not support enable clock of the other core, CR[CLKE] or CCR[CLKE]. */
#define FSL_FEATURE_MU_NO_CLKE (1)
/* @brief MU has bit CCR0[RSTH]. */
#define FSL_FEATURE_MU_HAS_RSTH (0)
/* @brief MU has bit CCR0[RSTH] by instance. */
#define FSL_FEATURE_MU_HAS_RSTH_BY_INSTANCEn(x) (0)
/* @brief MU has bit CCR0[BOOT]. */
#define FSL_FEATURE_MU_HAS_BOOT (0)
/* @brief MU has bit CCR0[BOOT] by instance. */
#define FSL_FEATURE_MU_HAS_BOOT_BY_INSTANCEn(x) (0)
/* @brief MU supports MU reset, CR[MUR]. */
#define FSL_FEATURE_MU_HAS_MUR (1)
/* @brief MU supports hardware reset, CR[HR] or CCR0[HR]. */
#define FSL_FEATURE_MU_HAS_HR (0)
/* @brief MU supports hardware reset by instance */
#define FSL_FEATURE_MU_HAS_HR_BY_INSTANCEn(x) (0)
/* @brief The number of general purpose interrupts supported by MU. */
#define FSL_FEATURE_MU_GPI_COUNT (4)

/* NVIC module features */

/* @brief Lowest interrupt request number. */
#define FSL_FEATURE_INTERRUPT_IRQ_MIN (-14)
/* @brief Highest interrupt request number. */
#define FSL_FEATURE_INTERRUPT_IRQ_MAX (207)

/* PIT module features */

/* @brief Has Real Time Interrupt. */
#define FSL_FEATURE_PIT_HAS_RTI (1)
/* @brief Number of channels (related to number of registers LDVALn, CVALn, TCTRLn, TFLGn). */
#define FSL_FEATURE_PIT_TIMER_COUNT (4)
/* @brief Has lifetime timer (related to existence of registers LTMR64L and LTMR64H). */
#define FSL_FEATURE_PIT_HAS_LIFETIME_TIMER (1)
/* @brief Has chain mode (related to existence of register bit field TCTRLn[CHN]). */
#define FSL_FEATURE_PIT_HAS_CHAIN_MODE (1)
/* @brief Has shared interrupt handler (has not individual interrupt handler for each channel). */
#define FSL_FEATURE_PIT_HAS_SHARED_IRQ_HANDLER (1)
/* @brief Has timer enable control. */
#define FSL_FEATURE_PIT_HAS_MDIS (1)

/* PMC module features */

/* @brief Has 1.5v supply input (register bit fields LVSC[LVD15S], LVSC[LVD15F]). */
#define FSL_FEATURE_PMC_HAS_15V_SUPPLY (0)
/* @brief Has last mile regulator (register bit fields CONFIG[LMSTAT], CONFIG[LMAUTOEN], CONFIG[LMBCTLEN], CONFIG[LMEN]). */
#define FSL_FEATURE_PMC_HAS_LAST_MILE_REGULATOR (0)
/* @brief Has VDD_HV_B power supply input (register bit fields LVSC[HVDBF], LVSC[HVDBS], LVSC[LVRBF], LVSC[LVRBLPF], CONFIG[LVRBLPEN]). */
#define FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY (0)

/* RTC module features */

/* No feature definitions */

/* SIUL2 module features */

/* No feature definitions */

/* STM module features */

/* No feature definitions */

/* SWT module features */

/* @brief Has ERRATA_052226. */
#define FSL_FEATURE_SWT_HAS_ERRATA_052226 (1)

/* SysTick module features */

/* @brief Systick has external reference clock. */
#define FSL_FEATURE_SYSTICK_HAS_EXT_REF (0)
/* @brief Systick external reference clock is core clock divided by this value. */
#define FSL_FEATURE_SYSTICK_EXT_REF_CORE_DIV (0)

/* TEMPSENSE module features */

/* No feature definitions */

/* TRGMUX module features */

/* No feature definitions */

/* VIRT_WRAPPER module features */

/* No feature definitions */

/* WKPU module features */

/* No feature definitions */

/* XRDC module features */

/* @brief Does not have global valid (register bit CR[GVLD]). */
#define FSL_FEATURE_XRDC_HAS_NO_CR_GVLD (0)
/* @brief Has domain ID of faulted access (register bit FDID[FDID]). */
#define FSL_FEATURE_XRDC_HAS_FDID (0)
/* @brief Has special 4-state model option (register bit PID[SP4SM]). */
#define FSL_FEATURE_XRDC_PID_SP4SM (0)
/* @brief Does not have logical partition identifier (register bit MDA_W[LPID]). */
#define FSL_FEATURE_XRDC_NO_MDA_LPID (1)
/* @brief Does not have logical partition enable option (register bit MDA_W[LPE]). */
#define FSL_FEATURE_XRDC_NO_MDA_LPE (1)
/* @brief Does not have peripheral semaphore enable option (register bit PDAC_W0[SE]). */
#define FSL_FEATURE_XRDC_NO_PDAC_SE (0)
/* @brief Does not have peripheral semaphore number (register bit PDAC_W0[SNUM]). */
#define FSL_FEATURE_XRDC_NO_PDAC_SNUM (0)
/* @brief Has peripheral excessive access lock owner (register bit PDAC_W0[EALO]). */
#define FSL_FEATURE_XRDC_HAS_PDAC_EALO (0)
/* @brief Has peripheral excessive access lock option (register bit PDAC_W1[EAL]). */
#define FSL_FEATURE_XRDC_HAS_PDAC_EAL (0)
/* @brief Has memory region end address (register bit MRGD_W1[ENDADDR]). */
#define FSL_FEATURE_XRDC_HAS_MRGD_ENDADDR (1)
/* @brief Does not have memory region semaphore enable option (register bit MRGD_W2[SE]). */
#define FSL_FEATURE_XRDC_NO_MRGD_SE (0)
/* @brief Does not have memory region semaphore number (register bit MRGD_W2[SNUM]). */
#define FSL_FEATURE_XRDC_NO_MRGD_SNUM (0)
/* @brief Does not domain x access control policy option (register bit MRGD_W2[DxACP]). */
#define FSL_FEATURE_XRDC_NO_MRGD_DXACP (0)
/* @brief Does not have region size configuration (register bit MRGD_W2[SZ]). */
#define FSL_FEATURE_XRDC_NO_MRGD_SZ (1)
/* @brief Does not have subregion disable option (register bit MRGD_W2[SRD]). */
#define FSL_FEATURE_XRDC_NO_MRGD_SRD (1)
/* @brief Has memory region excessive access lock owner (register bit MRGD_W2[EALO]). */
#define FSL_FEATURE_XRDC_HAS_MRGD_EALO (0)
/* @brief Has domain x access policy select option (register bit MRGD_W2[DxSEL]). */
#define FSL_FEATURE_XRDC_HAS_MRGD_DXSEL (0)
/* @brief Has memory region excessive access lock option (register bit MRGD_W3[EAL]). */
#define FSL_FEATURE_XRDC_HAS_MRGD_EAL (0)
/* @brief Does not have lock option in MRGD_W3 register (register bit MRGD_W3[LK2]). */
#define FSL_FEATURE_XRDC_NO_MRGD_W3_LK2 (0)
/* @brief Does not have valid option in MRGD_W3 register (register bit MRGD_W3[VLD]). */
#define FSL_FEATURE_XRDC_NO_MRGD_W3_VLD (0)
/* @brief Has code region indicator select option (register bit MRGD_W3[CR]). */
#define FSL_FEATURE_XRDC_HAS_MRGD_CR (0)
/* @brief XRDC domain number (reset value of HWCFG0[NDID] plus 1). */
#define FSL_FEATURE_XRDC_DOMAIN_COUNT (2)
/* @brief XRDC has ERRATA_050593. */
#define FSL_FEATURE_XRDC_HAS_ERRATA_050593 (1)

#endif /* _MCXE315_FEATURES_H_ */

