/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _S32K566_FEATURES_H_
#define _S32K566_FEATURES_H_

#include <zephyr/autoconf.h>

/* SOC module features */

/* @brief LPUART availability on the SoC, including the LPE. */
#define FSL_FEATURE_SOC_LPUART_COUNT (22)
/* @brief FTM availability on the SoC. */
#define FSL_FEATURE_SOC_FTM_COUNT (1)
/* @brief LPI2C availability on the SoC. */
#define FSL_FEATURE_SOC_LPI2C_COUNT (5)

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
/* LPI2C module features */
/* @brief Has separate DMA RX and TX requests. */
#define FSL_FEATURE_LPI2C_HAS_SEPARATE_DMA_RX_TX_REQn(x) (1)
/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FSL_FEATURE_LPI2C_FIFO_SIZEn(x) (4)

/* FLEXCAN module features */

/* @brief Message buffer size */
#define FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(x) (96)
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
#define FSL_FEATURE_FLEXCAN_SUPPORT_ENGINE_CLK_SEL_REMOVE (0)
/* @brief Instance remove CAN Engine Clock Source Selection from unsupported part. */
#define FSL_FEATURE_FLEXCAN_INSTANCE_SUPPORT_ENGINE_CLK_SEL_REMOVEn(x) (0)
/* @brief Is affected by errata with ID 5641 (Module does not transmit a message that is enabled
 * to be transmitted at a specific moment during the arbitration process). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_5641 (0)
/* @brief Is affected by errata with ID 5829 (FlexCAN: FlexCAN does not transmit a message that
 * is enabled to be transmitted in a specific moment during the arbitration process). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_5829 (0)
/* @brief Is affected by errata with ID 6032 (FlexCAN: A frame with wrong ID or payload is
 * transmitted into the CAN bus when the Message Buffer under transmission is either aborted
 * or deactivated while the CAN bus is in the Bus Idle state). */
#define FSL_FEATURE_FLEXCAN_HAS_ERRATA_6032 (0)
/* @brief Is affected by errata with ID 9595 (FlexCAN: Corrupt frame possible if the Freeze Mode
 * or the Low-Power Mode are entered during a Bus-Off state). */
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
#define FSL_FEATURE_FLEXCAN_INIT_MEMORY_SIZE_1 (0xA5F)
/* @brief Init memory base 2 */
#define FSL_FEATURE_FLEXCAN_INIT_MEMORY_BASE_2 (0xC20)
/* @brief Init memory size 2 */
#define FSL_FEATURE_FLEXCAN_INIT_MEMORY_SIZE_2 (0x25DF)
/* @brief Has enhanced bit timing register (register EPRS, ENCBT, EDCBT and ETDC). */
#define FSL_FEATURE_FLEXCAN_HAS_ENHANCED_BIT_TIMING_REG (0)
/* @brief Has Pretended Networking mode support. */
#define FSL_FEATURE_FLEXCAN_HAS_PN_MODE (0)
/* @brief Has Enhanced Rx FIFO. */
#define FSL_FEATURE_FLEXCAN_HAS_ENHANCED_RX_FIFO (0)
/* @brief Does not support Supervisor Mode (bitfield MCR[SUPV]. */
#define FSL_FEATURE_FLEXCAN_HAS_NO_SUPV_SUPPORT (0)
/* @brief Does not support Wake Up interrupt (bitfield MCR[WAKMSK]. */
#define FSL_FEATURE_FLEXCAN_HAS_NO_WAKMSK_SUPPORT (1)
/* @brief Does not support Self Wake Up (bitfield MCR[SLFWAK]. */
#define FSL_FEATURE_FLEXCAN_HAS_NO_SLFWAK_SUPPORT (1)
/* @brief Does not support Wake Up Source (bitfield MCR[WAKSRC]. */
#define FSL_FEATURE_FLEXCAN_HAS_NO_WAKSRC_SUPPORT (1)
/* @brief Does not support Memory Error Control (bitfield MECR[HANCEI]. */
#define FSL_FEATURE_FLEXCAN_HAS_NO_HANCEI_SUPPORT (1)
/* @brief Does not support Memory Error Control (bitfield MECR[FANCEI]. */
#define FSL_FEATURE_FLEXCAN_HAS_NO_FANCEI_SUPPORT (1)
/* @brief Does not support Memory Error Control (bitfield MECR[CEI]. */
#define FSL_FEATURE_FLEXCAN_HAS_NO_CEI_SUPPORT (1)

/* PIT module features */
/* @brief Has timer enable control. */
#define FSL_FEATURE_PIT_HAS_MDIS (1)
/* @brief Number of channels (related to number of registers LDVALn, CVALn, TCTRLn, TFLGn). */
#define FSL_FEATURE_PIT_TIMER_COUNT (1)
/* @brief Has lifetime timer (related to existence of registers LTMR64L and LTMR64H). */
#define FSL_FEATURE_PIT_HAS_LIFETIME_TIMER (1)
/* @brief Has chain mode (related to existence of register bit field TCTRLn[CHN]). */
#define FSL_FEATURE_PIT_HAS_CHAIN_MODE (1)

/* EDMA module features */
/* @brief EDMA availability on the SoC. */
#define FSL_FEATURE_SOC_EDMA_COUNT (2)
/* @brief DMAMUX availability on the SoC. */
#define FSL_FEATURE_SOC_DMAMUX_COUNT (3)
/* @brief Number of DMA channels (related to number of registers TCD, DCHPRI, bit fields ERQ[ERQn], EEI[EEIn], INT[INTn], ERR[ERRn], HRS[HRSn] and bit field widths ES[ERRCHN], CEEI[CEEI], SEEI[SEEI], CERQ[CERQ], SERQ[SERQ], CDNE[CDNE], SSRT[SSRT], CERR[CERR], CINT[CINT], TCDn_CITER_ELINKYES[LINKCH], TCDn_CSR[MAJORLINKCH], TCDn_BITER_ELINKYES[LINKCH]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL (32)
/* @brief If 8 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_8_BYTES_TRANSFER (1)
/* @brief Number of channel for each EDMA instance, (only defined for soc with different channel numbers for difference instance) */
#define FSL_FEATURE_EDMA_INSTANCE_CHANNELn(x)  (32)
/* @brief Has register CH_CSR. */
/* @brief If 16 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_16_BYTES_TRANSFER (1)
/* @brief Number of DMA channel groups (register bit fields CR[ERGA], CR[GRPnPRI], ES[GPE], DCHPRIn[GRPPRI]). (Valid only for eDMA modules.) */
#define FSL_FEATURE_EDMA_CHANNEL_GROUP_COUNT (0)
/* @brief Has register bit fields MP_CSR[GMRC]. */
#define FSL_FEATURE_EDMA_HAS_GLOBAL_MASTER_ID_REPLICATION (1)
/* @brief If 64 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_64_BYTES_TRANSFER (1)
/* @brief Has DMA_Error interrupt vector. */
#define FSL_FEATURE_EDMA_HAS_ERROR_IRQ (1)
/* @brief Has register bit fields CR[CLM]. */
#define FSL_FEATURE_EDMA_HAS_CONTINUOUS_LINK_MODE (0)
/* @brief If 128 bytes transfer supported. */
#define FSL_FEATURE_EDMA_SUPPORT_128_BYTES_TRANSFER (0)
/* @brief Has register access permission. */
#define FSL_FEATURE_HAVE_DMA_CONTROL_REGISTER_ACCESS_PERMISSION (1)
/* @brief NBYTES must be multiple of 8 when using scatter gather. */
#define FSL_FEATURE_EDMA_HAS_ERRATA_51327 (0)
/* @brief If 128 bytes transfer supported. */
#define FSL_FEATURE_EDMA_INSTANCE_SUPPORT_128_BYTES_TRANSFERn(x) (0)
/* @brief If channel clock controlled independently */
#define FSL_FEATURE_EDMA_CHANNEL_HAS_OWN_CLOCK_GATE (1)
/* @brief NBYTES must be multiple of 8 when using scatter gather. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_ERRATA_51327n(x) (0)
/* @brief Has register CH_CSR. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_CONFIG (1)
/* @brief Has channel mux */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_MUX (0)
/* @brief Has no register bit fields MP_CSR[EBW]. */
#define FSL_FEATURE_EDMA_HAS_NO_MP_CSR_EBW (0)
/* @brief Instance has channel mux */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_MUXn(x) (0)
/* @brief If dma has common clock gate */
#define FSL_FEATURE_EDMA_HAS_COMMON_CLOCK_GATE (0)
/* @brief Has register CH_SBR. */
#define FSL_FEATURE_EDMA_HAS_SBR (1)
/* @brief If dma channel IRQ support parameter */
#define FSL_FEATURE_EDMA_MODULE_CHANNEL_IRQ_ENTRY_SUPPORT_PARAMETER (0)
/* @brief Has no register bit fields CH_SBR[ATTR]. */
#define FSL_FEATURE_EDMA_HAS_NO_CH_SBR_ATTR (1)
/* @brief Has register bit field CH_CSR[SWAP]. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_SWAP_SIZE (0)
/* @brief Instance has register bit field CH_CSR[SWAP]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_SWAP_SIZEn(x) (0)
/* @brief Has register bit field CH_SBR[INSTR]. */
#define FSL_FEATURE_EDMA_HAS_CHANNEL_ACCESS_TYPE (0)
/* @brief Whether has prot register. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_PROT_REGISTERn(x) (0)
/* @brief Instance has register bit field CH_SBR[INSTR]. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_CHANNEL_ACCESS_TYPEn(x) (0)
/* @brief Whether has MP channel mux. */
#define FSL_FEATURE_EDMA_INSTANCE_HAS_MP_CHANNEL_MUXn(x) (0)
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
/* @brief edma5 has different tcd type. */
#define FSL_FEATURE_EDMA_TCD_TYPEn(x)  (1)
/* @brief Has no register bit fields CH_SBR[SEC]. */
#define FSL_FEATURE_EDMA_HAS_NO_CH_SBR_SEC (1)

/* DMAMUX module features */
/* @brief Number of DMA channels (related to number of register CHCFGn). */
#define FSL_FEATURE_DMAMUX_MODULE_CHANNEL (16)
/* @brief Has the periodic trigger capability for the triggered DMA channel (register bit CHCFG0[TRIG]). */
#define FSL_FEATURE_DMAMUX_HAS_TRIG (1)
/* @brief Register CHCFGn width. */
#define FSL_FEATURE_DMAMUX_CHCFG_REGISTER_WIDTH (8)
/* @brief Has DMA Channel Always ON function */
#define FSL_FEATURE_DMAMUX_HAS_A_ON (1)

#endif /* _S32K566_FEATURES_H_ */
