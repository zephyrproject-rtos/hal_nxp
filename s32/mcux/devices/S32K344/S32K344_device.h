/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _S32K344_DEVICE_H_
#define _S32K344_DEVICE_H_

/* ----------------------------------------------------------------------------
   -- CAN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Peripheral_Access_Layer CAN Peripheral Access Layer
 * @{
 */

/** CAN - Register Layout Typedef */
typedef struct {
        __IO uint32_t MCR;                  /**< Module Configuration Register, offset: 0x0 */
        __IO uint32_t CTRL1;                /**< Control 1 Register, offset: 0x4 */
        __IO uint32_t TIMER;                /**< Free Running Timer, offset: 0x8 */
        uint8_t RESERVED_0[4];
        __IO uint32_t RXMGMASK;             /**< Rx Mailboxes Global Mask Register, offset: 0x10 */
        __IO uint32_t RX14MASK;             /**< Rx 14 Mask Register, offset: 0x14 */
        __IO uint32_t RX15MASK;             /**< Rx 15 Mask Register, offset: 0x18 */
        __IO uint32_t ECR;                  /**< Error Counter, offset: 0x1C */
        __IO uint32_t ESR1;                 /**< Error and Status 1 Register, offset: 0x20 */
        __IO uint32_t IMASK2;               /**< Interrupt Masks 2 Register, offset: 0x24 */
        __IO uint32_t IMASK1;               /**< Interrupt Masks 1 Register, offset: 0x28 */
        __IO uint32_t IFLAG2;               /**< Interrupt Flags 2 Register, offset: 0x2C */
        __IO uint32_t IFLAG1;               /**< Interrupt Flags 1 Register, offset: 0x30 */
        __IO uint32_t CTRL2;                /**< Control 2 Register, offset: 0x34 */
        __I  uint32_t ESR2;                 /**< Error and Status 2 Register, offset: 0x38 */
        uint8_t RESERVED_1[8];
        __I  uint32_t CRCR;                 /**< CRC Register, offset: 0x44 */
        __IO uint32_t RXFGMASK;             /**< Legacy Rx FIFO Global Mask Register..Rx FIFO Global Mask Register, offset: 0x48 */
        __I  uint32_t RXFIR;                /**< Legacy Rx FIFO Information Register..Rx FIFO Information Register, offset: 0x4C */
        __IO uint32_t CBT;                  /**< CAN Bit Timing Register, offset: 0x50 */
        uint8_t RESERVED_2[24];
        __IO uint32_t IMASK3;               /**< Interrupt Masks 3 Register, offset: 0x6C */
        uint8_t RESERVED_3[4];
        __IO uint32_t IFLAG3;               /**< Interrupt Flags 3 Register, offset: 0x74 */
        uint8_t RESERVED_4[8];
        union
        {
        struct
        {                                   /* offset: 0x80, array step: 0x10 */
                __IO uint32_t CS;           /**< Message Buffer 0 CS Register..Message Buffer 95 CS Register, array offset: 0x80, array step: 0x10 */
                __IO uint32_t ID;           /**< Message Buffer 0 ID Register..Message Buffer 95 ID Register, array offset: 0x84, array step: 0x10 */
                __IO uint32_t WORD[2];      /**< Message Buffer 0 WORD_8B Register..Message Buffer 95 WORD_8B Register, array offset: 0x88, array step: index*0x10, index2*0x4 */
        } MB_8B[96];
        struct
        {                                   /* offset: 0x80, array step: 0x18 */
                __IO uint32_t CS;           /**< Message Buffer 0 CS Register..Message Buffer 62 CS Register, array offset: 0x80, array step: 0x18 */
                __IO uint32_t ID;           /**< Message Buffer 0 ID Register..Message Buffer 62 ID Register, array offset: 0x84, array step: 0x18 */
                __IO uint32_t WORD[4];      /**< Message Buffer 0 WORD_16B Register..Message Buffer 62 WORD_16B Register, array offset: 0x88, array step: index*0x18, index2*0x4 */
        } MB_16B[63];
        struct
        {                                   /* offset: 0x80, array step: 0x28 */
                __IO uint32_t CS;           /**< Message Buffer 0 CS Register..Message Buffer 35 CS Register, array offset: 0x80, array step: 0x28 */
                __IO uint32_t ID;           /**< Message Buffer 0 ID Register..Message Buffer 35 ID Register, array offset: 0x84, array step: 0x28 */
                __IO uint32_t WORD[8];      /**< Message Buffer 0 WORD_32B Register..Message Buffer 35 WORD_32B Register, array offset: 0x88, array step: index*0x28, index2*0x4 */
        } MB_32B[36];
        struct
        {                                   /* offset: 0x80, array step: 0x48 */
                __IO uint32_t CS;           /**< Message Buffer 0 CS Register..Message Buffer 20 CS Register, array offset: 0x80, array step: 0x48 */
                __IO uint32_t ID;           /**< Message Buffer 0 ID Register..Message Buffer 20 ID Register, array offset: 0x84, array step: 0x48 */
                __IO uint32_t WORD[16];     /**< Message Buffer 0 WORD_64B Register..Message Buffer 20 WORD_64B Register, array offset: 0x88, array step: index*0x48, index2*0x4 */
        } MB_64B[21];
        struct
        {                                   /* offset: 0x80, array step: 0x10 */
                __IO uint32_t CS;           /**< Message Buffer 0 CS Register..Message Buffer 95 CS Register, array offset: 0x80, array step: 0x10 */
                __IO uint32_t ID;           /**< Message Buffer 0 ID Register..Message Buffer 95 ID Register, array offset: 0x84, array step: 0x10 */
                __IO uint32_t WORD0;        /**< Message Buffer 0 WORD0 Register..Message Buffer 95 WORD0 Register, array offset: 0x88, array step: 0x10 */
                __IO uint32_t WORD1;        /**< Message Buffer 0 WORD1 Register..Message Buffer 95 WORD1 Register, array offset: 0x8C, array step: 0x10 */
        } MB[96];
        };
        uint8_t RESERVED_5[512];
        __IO uint32_t RXIMR[96];            /**< Rx Individual Mask Registers, array offset: 0x880, array step: 0x4 */
        uint8_t RESERVED_6[224];
        __IO uint32_t MECR;                 /**< Memory Error Control Register, offset: 0xAE0 */
        __IO uint32_t ERRIAR;               /**< Error Injection Address Register, offset: 0xAE4 */
        __IO uint32_t ERRIDPR;              /**< Error Injection Data Pattern Register, offset: 0xAE8 */
        __IO uint32_t ERRIPPR;              /**< Error Injection Parity Pattern Register, offset: 0xAEC */
        __I  uint32_t RERRAR;               /**< Error Report Address Register, offset: 0xAF0 */
        __I  uint32_t RERRDR;               /**< Error Report Data Register, offset: 0xAF4 */
        __I  uint32_t RERRSYNR;             /**< Error Report Syndrome Register, offset: 0xAF8 */
        __IO uint32_t ERRSR;                /**< Error Status Register, offset: 0xAFC */
        uint8_t RESERVED_7[240];
        __IO uint32_t EPRS;                 /**< Enhanced CAN Bit Timing Prescalers, offset: 0xBF0 */
        __IO uint32_t ENCBT;                /**< Enhanced Nominal CAN Bit Timing, offset: 0xBF4 */
        __IO uint32_t EDCBT;                /**< Enhanced Data Phase CAN bit Timing, offset: 0xBF8 */
        __IO uint32_t ETDC;                 /**< Enhanced Transceiver Delay Compensation, offset: 0xBFC */
        __IO uint32_t FDCTRL;               /**< CAN FD Control Register, offset: 0xC00 */
        __IO uint32_t FDCBT;                /**< CAN FD Bit Timing Register, offset: 0xC04 */
        __I  uint32_t FDCRC;                /**< CAN FD CRC Register, offset: 0xC08 */
        __IO uint32_t ERFCR;                /**< Enhanced Rx FIFO Control Register, offset: 0xC0C */
        __IO uint32_t ERFIER;               /**< Enhanced Rx FIFO Interrupt Enable Register, offset: 0xC10 */
        __IO uint32_t ERFSR;                /**< Enhanced Rx FIFO Status Register, offset: 0xC14 */
        uint8_t RESERVED_8[24];
        __IO uint32_t HR_TIME_STAMP[96];    /**< High Resolution Time Stamp, array offset: 0xC30, array step: 0x4 */
        uint8_t RESERVED_9[8784];
        __IO uint32_t ERFFEL[128];          /**< Enhanced Rx FIFO Filter Element, array offset: 0x3000, array step: 0x4 */
} CAN_Type;

/* ----------------------------------------------------------------------------
   -- CAN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Register_Masks CAN Register Masks
 * @{
 */

/*! @name MCR - Module Configuration Register */
/*! @{ */

#define CAN_MCR_MAXMB_MASK  (0x7FU)
#define CAN_MCR_MAXMB_SHIFT (0U)
/*! MAXMB - Number Of The Last Message Buffer
 */
#define CAN_MCR_MAXMB(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_MAXMB_SHIFT)) & CAN_MCR_MAXMB_MASK)

#define CAN_MCR_IDAM_MASK  (0x300U)
#define CAN_MCR_IDAM_SHIFT (8U)
/*! IDAM - ID Acceptance Mode
 *  0b00..Format A: One full ID (standard and extended) per ID filter table element.
 *  0b01..Format B: Two full standard IDs or two partial 14-bit (standard and extended) IDs per ID filter table element.
 *  0b10..Format C: Four partial 8-bit standard IDs per ID filter table element.
 *  0b11..Format D: All frames rejected.
 */
#define CAN_MCR_IDAM(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_IDAM_SHIFT)) & CAN_MCR_IDAM_MASK)

#define CAN_MCR_FDEN_MASK  (0x800U)
#define CAN_MCR_FDEN_SHIFT (11U)
/*! FDEN - CAN FD operation enable
 *  0b1..CAN FD is enabled. FlexCAN is able to receive and transmit messages in both CAN FD and CAN 2.0 formats.
 *  0b0..CAN FD is disabled. FlexCAN is able to receive and transmit messages in CAN 2.0 format.
 */
#define CAN_MCR_FDEN(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_FDEN_SHIFT)) & CAN_MCR_FDEN_MASK)

#define CAN_MCR_AEN_MASK  (0x1000U)
#define CAN_MCR_AEN_SHIFT (12U)
/*! AEN - Abort Enable
 *  0b0..Abort disabled.
 *  0b1..Abort enabled.
 */
#define CAN_MCR_AEN(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_AEN_SHIFT)) & CAN_MCR_AEN_MASK)

#define CAN_MCR_LPRIOEN_MASK  (0x2000U)
#define CAN_MCR_LPRIOEN_SHIFT (13U)
/*! LPRIOEN - Local Priority Enable
 *  0b0..Local Priority disabled.
 *  0b1..Local Priority enabled.
 */
#define CAN_MCR_LPRIOEN(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_LPRIOEN_SHIFT)) & CAN_MCR_LPRIOEN_MASK)

#define CAN_MCR_DMA_MASK  (0x8000U)
#define CAN_MCR_DMA_SHIFT (15U)
/*! DMA - DMA Enable
 *  0b0..DMA feature for Legacy RX FIFO or Enhanced Rx FIFO disabled.
 *  0b1..DMA feature for Legacy RX FIFO or Enhanced Rx FIFO enabled.
 */
#define CAN_MCR_DMA(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_DMA_SHIFT)) & CAN_MCR_DMA_MASK)

#define CAN_MCR_IRMQ_MASK  (0x10000U)
#define CAN_MCR_IRMQ_SHIFT (16U)
/*! IRMQ - Individual Rx Masking And Queue Enable
 *  0b0..Individual Rx masking and queue feature are disabled. For backward compatibility with legacy
 *       applications, the reading of C/S word locks the MB even if it is EMPTY.
 *  0b1..Individual Rx masking and queue feature are enabled.
 */
#define CAN_MCR_IRMQ(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_IRMQ_SHIFT)) & CAN_MCR_IRMQ_MASK)

#define CAN_MCR_SRXDIS_MASK  (0x20000U)
#define CAN_MCR_SRXDIS_SHIFT (17U)
/*! SRXDIS - Self Reception Disable
 *  0b0..Self-reception enabled.
 *  0b1..Self-reception disabled.
 */
#define CAN_MCR_SRXDIS(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_SRXDIS_SHIFT)) & CAN_MCR_SRXDIS_MASK)

#define CAN_MCR_DOZE_MASK  (0x40000U)
#define CAN_MCR_DOZE_SHIFT (18U)
/*! DOZE - Doze Mode Enable
 *  0b0..FlexCAN is not enabled to enter low-power mode when Doze mode is requested.
 *  0b1..FlexCAN is enabled to enter low-power mode when Doze mode is requested.
 */
#define CAN_MCR_DOZE(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_DOZE_SHIFT)) & CAN_MCR_DOZE_MASK)

#define CAN_MCR_WAKSRC_MASK  (0x80000U)
#define CAN_MCR_WAKSRC_SHIFT (19U)
/*! WAKSRC - Wake Up Source
 *  0b0..FlexCAN uses the unfiltered Rx input to detect recessive to dominant edges on the CAN bus.
 *  0b1..FlexCAN uses the filtered Rx input to detect recessive to dominant edges on the CAN bus.
 */
#define CAN_MCR_WAKSRC(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_WAKSRC_SHIFT)) & CAN_MCR_WAKSRC_MASK)

#define CAN_MCR_LPMACK_MASK  (0x100000U)
#define CAN_MCR_LPMACK_SHIFT (20U)
/*! LPMACK - Low-Power Mode Acknowledge
 *  0b0..FlexCAN is not in a low-power mode.
 *  0b1..FlexCAN is in a low-power mode.
 */
#define CAN_MCR_LPMACK(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_LPMACK_SHIFT)) & CAN_MCR_LPMACK_MASK)

#define CAN_MCR_WRNEN_MASK  (0x200000U)
#define CAN_MCR_WRNEN_SHIFT (21U)
/*! WRNEN - Warning Interrupt Enable
 *  0b0..TWRNINT and RWRNINT bits are zero, independent of the values in the error counters.
 *  0b1..TWRNINT and RWRNINT bits are set when the respective error counter transitions from less than 96 to greater
 * than or equal to 96.
 */
#define CAN_MCR_WRNEN(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_WRNEN_SHIFT)) & CAN_MCR_WRNEN_MASK)

#define CAN_MCR_SLFWAK_MASK  (0x400000U)
#define CAN_MCR_SLFWAK_SHIFT (22U)
/*! SLFWAK - Self Wake Up
 *  0b0..FlexCAN Self Wake Up feature is disabled.
 *  0b1..FlexCAN Self Wake Up feature is enabled.
 */
#define CAN_MCR_SLFWAK(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_SLFWAK_SHIFT)) & CAN_MCR_SLFWAK_MASK)

#define CAN_MCR_SUPV_MASK  (0x800000U)
#define CAN_MCR_SUPV_SHIFT (23U)
/*! SUPV - Supervisor Mode
 *  0b0..FlexCAN is in User mode. Affected registers allow both Supervisor and Unrestricted accesses
 * (ips_supervisor_access signal is ignored). 0b1..FlexCAN is in Supervisor mode. Affected registers allow only
 * Supervisor access. Unrestricted access (ips_supervisor_access negated) behaves as though the access was done to an
 * unimplemented register location (ips_xfr_error asserted in the SkyBlue Interface).
 */
#define CAN_MCR_SUPV(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_SUPV_SHIFT)) & CAN_MCR_SUPV_MASK)

#define CAN_MCR_FRZACK_MASK  (0x1000000U)
#define CAN_MCR_FRZACK_SHIFT (24U)
/*! FRZACK - Freeze Mode Acknowledge
 *  0b0..FlexCAN not in Freeze mode, prescaler running.
 *  0b1..FlexCAN in Freeze mode, prescaler stopped.
 */
#define CAN_MCR_FRZACK(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_FRZACK_SHIFT)) & CAN_MCR_FRZACK_MASK)

#define CAN_MCR_SOFTRST_MASK  (0x2000000U)
#define CAN_MCR_SOFTRST_SHIFT (25U)
/*! SOFTRST - Soft Reset
 *  0b0..No reset request.
 *  0b1..Resets the registers affected by soft reset.
 */
#define CAN_MCR_SOFTRST(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_SOFTRST_SHIFT)) & CAN_MCR_SOFTRST_MASK)

#define CAN_MCR_WAKMSK_MASK  (0x4000000U)
#define CAN_MCR_WAKMSK_SHIFT (26U)
/*! WAKMSK - Wake Up Interrupt Mask
 *  0b0..Wake Up interrupt is disabled.
 *  0b1..Wake Up interrupt is enabled.
 */
#define CAN_MCR_WAKMSK(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_WAKMSK_SHIFT)) & CAN_MCR_WAKMSK_MASK)

#define CAN_MCR_NOTRDY_MASK  (0x8000000U)
#define CAN_MCR_NOTRDY_SHIFT (27U)
/*! NOTRDY - FlexCAN Not Ready
 *  0b0..FlexCAN module is either in Normal mode, Listen-Only mode, or Loop-Back mode.
 *  0b1..FlexCAN module is either in Disable mode, Doze mode, Stop mode, or Freeze mode.
 */
#define CAN_MCR_NOTRDY(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_NOTRDY_SHIFT)) & CAN_MCR_NOTRDY_MASK)

#define CAN_MCR_HALT_MASK  (0x10000000U)
#define CAN_MCR_HALT_SHIFT (28U)
/*! HALT - Halt FlexCAN
 *  0b0..No Freeze mode request.
 *  0b1..Enters Freeze mode if the FRZ bit is asserted.
 */
#define CAN_MCR_HALT(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_HALT_SHIFT)) & CAN_MCR_HALT_MASK)

#define CAN_MCR_RFEN_MASK  (0x20000000U)
#define CAN_MCR_RFEN_SHIFT (29U)
/*! RFEN - Legacy Rx FIFO Enable
 *  0b0..Legacy Rx FIFO not enabled.
 *  0b1..Legacy Rx FIFO enabled.
 */
#define CAN_MCR_RFEN(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_RFEN_SHIFT)) & CAN_MCR_RFEN_MASK)

#define CAN_MCR_FRZ_MASK  (0x40000000U)
#define CAN_MCR_FRZ_SHIFT (30U)
/*! FRZ - Freeze Enable
 *  0b0..Not enabled to enter Freeze mode.
 *  0b1..Enabled to enter Freeze mode.
 */
#define CAN_MCR_FRZ(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_FRZ_SHIFT)) & CAN_MCR_FRZ_MASK)

#define CAN_MCR_MDIS_MASK  (0x80000000U)
#define CAN_MCR_MDIS_SHIFT (31U)
/*! MDIS - Module Disable
 *  0b0..Enable the FlexCAN module.
 *  0b1..Disable the FlexCAN module.
 */
#define CAN_MCR_MDIS(x) (((uint32_t)(((uint32_t)(x)) << CAN_MCR_MDIS_SHIFT)) & CAN_MCR_MDIS_MASK)
/*! @} */

/*! @name CTRL1 - Control 1 Register */
/*! @{ */

#define CAN_CTRL1_PROPSEG_MASK  (0x7U)
#define CAN_CTRL1_PROPSEG_SHIFT (0U)
/*! PROPSEG - Propagation Segment
 */
#define CAN_CTRL1_PROPSEG(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_PROPSEG_SHIFT)) & CAN_CTRL1_PROPSEG_MASK)

#define CAN_CTRL1_LOM_MASK  (0x8U)
#define CAN_CTRL1_LOM_SHIFT (3U)
/*! LOM - Listen-Only Mode
 *  0b0..Listen-Only mode is deactivated.
 *  0b1..FlexCAN module operates in Listen-Only mode.
 */
#define CAN_CTRL1_LOM(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_LOM_SHIFT)) & CAN_CTRL1_LOM_MASK)

#define CAN_CTRL1_LBUF_MASK  (0x10U)
#define CAN_CTRL1_LBUF_SHIFT (4U)
/*! LBUF - Lowest Buffer Transmitted First
 *  0b0..Buffer with highest priority is transmitted first.
 *  0b1..Lowest number buffer is transmitted first.
 */
#define CAN_CTRL1_LBUF(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_LBUF_SHIFT)) & CAN_CTRL1_LBUF_MASK)

#define CAN_CTRL1_TSYN_MASK  (0x20U)
#define CAN_CTRL1_TSYN_SHIFT (5U)
/*! TSYN - Timer Sync
 *  0b0..Timer sync feature disabled
 *  0b1..Timer sync feature enabled
 */
#define CAN_CTRL1_TSYN(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_TSYN_SHIFT)) & CAN_CTRL1_TSYN_MASK)

#define CAN_CTRL1_BOFFREC_MASK  (0x40U)
#define CAN_CTRL1_BOFFREC_SHIFT (6U)
/*! BOFFREC - Bus Off Recovery
 *  0b0..Automatic recovering from Bus Off state enabled.
 *  0b1..Automatic recovering from Bus Off state disabled.
 */
#define CAN_CTRL1_BOFFREC(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_BOFFREC_SHIFT)) & CAN_CTRL1_BOFFREC_MASK)

#define CAN_CTRL1_SMP_MASK  (0x80U)
#define CAN_CTRL1_SMP_SHIFT (7U)
/*! SMP - CAN Bit Sampling
 *  0b0..Just one sample is used to determine the bit value.
 *  0b1..Three samples are used to determine the value of the received bit: the regular one (sample point) and two
 *       preceding samples; a majority rule is used.
 */
#define CAN_CTRL1_SMP(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_SMP_SHIFT)) & CAN_CTRL1_SMP_MASK)

#define CAN_CTRL1_RWRNMSK_MASK  (0x400U)
#define CAN_CTRL1_RWRNMSK_SHIFT (10U)
/*! RWRNMSK - Rx Warning Interrupt Mask
 *  0b0..Rx Warning interrupt disabled.
 *  0b1..Rx Warning interrupt enabled.
 */
#define CAN_CTRL1_RWRNMSK(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_RWRNMSK_SHIFT)) & CAN_CTRL1_RWRNMSK_MASK)

#define CAN_CTRL1_TWRNMSK_MASK  (0x800U)
#define CAN_CTRL1_TWRNMSK_SHIFT (11U)
/*! TWRNMSK - Tx Warning Interrupt Mask
 *  0b0..Tx Warning interrupt disabled.
 *  0b1..Tx Warning interrupt enabled.
 */
#define CAN_CTRL1_TWRNMSK(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_TWRNMSK_SHIFT)) & CAN_CTRL1_TWRNMSK_MASK)

#define CAN_CTRL1_LPB_MASK  (0x1000U)
#define CAN_CTRL1_LPB_SHIFT (12U)
/*! LPB - Loop Back Mode
 *  0b0..Loop Back disabled.
 *  0b1..Loop Back enabled.
 */
#define CAN_CTRL1_LPB(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_LPB_SHIFT)) & CAN_CTRL1_LPB_MASK)

#define CAN_CTRL1_ERRMSK_MASK  (0x4000U)
#define CAN_CTRL1_ERRMSK_SHIFT (14U)
/*! ERRMSK - Error Interrupt Mask
 *  0b0..Error interrupt disabled.
 *  0b1..Error interrupt enabled.
 */
#define CAN_CTRL1_ERRMSK(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_ERRMSK_SHIFT)) & CAN_CTRL1_ERRMSK_MASK)

#define CAN_CTRL1_BOFFMSK_MASK  (0x8000U)
#define CAN_CTRL1_BOFFMSK_SHIFT (15U)
/*! BOFFMSK - Bus Off Interrupt Mask
 *  0b0..Bus Off interrupt disabled.
 *  0b1..Bus Off interrupt enabled.
 */
#define CAN_CTRL1_BOFFMSK(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_BOFFMSK_SHIFT)) & CAN_CTRL1_BOFFMSK_MASK)

#define CAN_CTRL1_PSEG2_MASK  (0x70000U)
#define CAN_CTRL1_PSEG2_SHIFT (16U)
/*! PSEG2 - Phase Segment 2
 */
#define CAN_CTRL1_PSEG2(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_PSEG2_SHIFT)) & CAN_CTRL1_PSEG2_MASK)

#define CAN_CTRL1_PSEG1_MASK  (0x380000U)
#define CAN_CTRL1_PSEG1_SHIFT (19U)
/*! PSEG1 - Phase Segment 1
 */
#define CAN_CTRL1_PSEG1(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_PSEG1_SHIFT)) & CAN_CTRL1_PSEG1_MASK)

#define CAN_CTRL1_RJW_MASK  (0xC00000U)
#define CAN_CTRL1_RJW_SHIFT (22U)
/*! RJW - Resync Jump Width
 */
#define CAN_CTRL1_RJW(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_RJW_SHIFT)) & CAN_CTRL1_RJW_MASK)

#define CAN_CTRL1_PRESDIV_MASK  (0xFF000000U)
#define CAN_CTRL1_PRESDIV_SHIFT (24U)
/*! PRESDIV - Prescaler Division Factor
 */
#define CAN_CTRL1_PRESDIV(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_PRESDIV_SHIFT)) & CAN_CTRL1_PRESDIV_MASK)
/*! @} */

/*! @name TIMER - Free Running Timer */
/*! @{ */

#define CAN_TIMER_TIMER_MASK  (0xFFFFU)
#define CAN_TIMER_TIMER_SHIFT (0U)
/*! TIMER - Timer Value
 */
#define CAN_TIMER_TIMER(x) (((uint32_t)(((uint32_t)(x)) << CAN_TIMER_TIMER_SHIFT)) & CAN_TIMER_TIMER_MASK)
/*! @} */

/*! @name RXMGMASK - Rx Mailboxes Global Mask Register */
/*! @{ */

#define CAN_RXMGMASK_MG_MASK  (0xFFFFFFFFU)
#define CAN_RXMGMASK_MG_SHIFT (0U)
/*! MG - Rx Mailboxes Global Mask Bits
 */
#define CAN_RXMGMASK_MG(x) (((uint32_t)(((uint32_t)(x)) << CAN_RXMGMASK_MG_SHIFT)) & CAN_RXMGMASK_MG_MASK)
/*! @} */

/*! @name RX14MASK - Rx 14 Mask Register */
/*! @{ */

#define CAN_RX14MASK_RX14M_MASK  (0xFFFFFFFFU)
#define CAN_RX14MASK_RX14M_SHIFT (0U)
/*! RX14M - Rx Buffer 14 Mask Bits
 */
#define CAN_RX14MASK_RX14M(x) (((uint32_t)(((uint32_t)(x)) << CAN_RX14MASK_RX14M_SHIFT)) & CAN_RX14MASK_RX14M_MASK)
/*! @} */

/*! @name RX15MASK - Rx 15 Mask Register */
/*! @{ */

#define CAN_RX15MASK_RX15M_MASK  (0xFFFFFFFFU)
#define CAN_RX15MASK_RX15M_SHIFT (0U)
/*! RX15M - Rx Buffer 15 Mask Bits
 */
#define CAN_RX15MASK_RX15M(x) (((uint32_t)(((uint32_t)(x)) << CAN_RX15MASK_RX15M_SHIFT)) & CAN_RX15MASK_RX15M_MASK)
/*! @} */

/*! @name ECR - Error Counter */
/*! @{ */

#define CAN_ECR_TXERRCNT_MASK  (0xFFU)
#define CAN_ECR_TXERRCNT_SHIFT (0U)
/*! TXERRCNT - Transmit Error Counter
 */
#define CAN_ECR_TXERRCNT(x) (((uint32_t)(((uint32_t)(x)) << CAN_ECR_TXERRCNT_SHIFT)) & CAN_ECR_TXERRCNT_MASK)

#define CAN_ECR_RXERRCNT_MASK  (0xFF00U)
#define CAN_ECR_RXERRCNT_SHIFT (8U)
/*! RXERRCNT - Receive Error Counter
 */
#define CAN_ECR_RXERRCNT(x) (((uint32_t)(((uint32_t)(x)) << CAN_ECR_RXERRCNT_SHIFT)) & CAN_ECR_RXERRCNT_MASK)

#define CAN_ECR_TXERRCNT_FAST_MASK  (0xFF0000U)
#define CAN_ECR_TXERRCNT_FAST_SHIFT (16U)
/*! TXERRCNT_FAST - Transmit Error Counter for fast bits
 */
#define CAN_ECR_TXERRCNT_FAST(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_ECR_TXERRCNT_FAST_SHIFT)) & CAN_ECR_TXERRCNT_FAST_MASK)

#define CAN_ECR_RXERRCNT_FAST_MASK  (0xFF000000U)
#define CAN_ECR_RXERRCNT_FAST_SHIFT (24U)
/*! RXERRCNT_FAST - Receive Error Counter for fast bits
 */
#define CAN_ECR_RXERRCNT_FAST(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_ECR_RXERRCNT_FAST_SHIFT)) & CAN_ECR_RXERRCNT_FAST_MASK)
/*! @} */

/*! @name ESR1 - Error and Status 1 Register */
/*! @{ */

#define CAN_ESR1_WAKINT_MASK  (0x1U)
#define CAN_ESR1_WAKINT_SHIFT (0U)
/*! WAKINT - Wake-Up Interrupt
 *  0b0..No such occurrence.
 *  0b1..Indicates a recessive to dominant transition was received on the CAN bus.
 */
#define CAN_ESR1_WAKINT(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_WAKINT_SHIFT)) & CAN_ESR1_WAKINT_MASK)

#define CAN_ESR1_ERRINT_MASK  (0x2U)
#define CAN_ESR1_ERRINT_SHIFT (1U)
/*! ERRINT - Error Interrupt
 *  0b0..No such occurrence.
 *  0b1..Indicates setting of any error bit in the Error and Status register.
 */
#define CAN_ESR1_ERRINT(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_ERRINT_SHIFT)) & CAN_ESR1_ERRINT_MASK)

#define CAN_ESR1_BOFFINT_MASK  (0x4U)
#define CAN_ESR1_BOFFINT_SHIFT (2U)
/*! BOFFINT - Bus Off Interrupt
 *  0b0..No such occurrence.
 *  0b1..FlexCAN module entered Bus Off state.
 */
#define CAN_ESR1_BOFFINT(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_BOFFINT_SHIFT)) & CAN_ESR1_BOFFINT_MASK)

#define CAN_ESR1_RX_MASK  (0x8U)
#define CAN_ESR1_RX_SHIFT (3U)
/*! RX - FlexCAN In Reception
 *  0b0..FlexCAN is not receiving a message.
 *  0b1..FlexCAN is receiving a message.
 */
#define CAN_ESR1_RX(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_RX_SHIFT)) & CAN_ESR1_RX_MASK)

#define CAN_ESR1_FLTCONF_MASK  (0x30U)
#define CAN_ESR1_FLTCONF_SHIFT (4U)
/*! FLTCONF - Fault Confinement State
 *  0b00..Error Active
 *  0b01..Error Passive
 *  0b1x..Bus Off
 */
#define CAN_ESR1_FLTCONF(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_FLTCONF_SHIFT)) & CAN_ESR1_FLTCONF_MASK)

#define CAN_ESR1_TX_MASK  (0x40U)
#define CAN_ESR1_TX_SHIFT (6U)
/*! TX - FlexCAN In Transmission
 *  0b0..FlexCAN is not transmitting a message.
 *  0b1..FlexCAN is transmitting a message.
 */
#define CAN_ESR1_TX(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_TX_SHIFT)) & CAN_ESR1_TX_MASK)

#define CAN_ESR1_IDLE_MASK  (0x80U)
#define CAN_ESR1_IDLE_SHIFT (7U)
/*! IDLE - IDLE
 *  0b0..No such occurrence.
 *  0b1..CAN bus is now IDLE.
 */
#define CAN_ESR1_IDLE(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_IDLE_SHIFT)) & CAN_ESR1_IDLE_MASK)

#define CAN_ESR1_RXWRN_MASK  (0x100U)
#define CAN_ESR1_RXWRN_SHIFT (8U)
/*! RXWRN - Rx Error Warning
 *  0b0..No such occurrence.
 *  0b1..RXERRCNT is greater than or equal to 96.
 */
#define CAN_ESR1_RXWRN(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_RXWRN_SHIFT)) & CAN_ESR1_RXWRN_MASK)

#define CAN_ESR1_TXWRN_MASK  (0x200U)
#define CAN_ESR1_TXWRN_SHIFT (9U)
/*! TXWRN - TX Error Warning
 *  0b0..No such occurrence.
 *  0b1..TXERRCNT is greater than or equal to 96.
 */
#define CAN_ESR1_TXWRN(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_TXWRN_SHIFT)) & CAN_ESR1_TXWRN_MASK)

#define CAN_ESR1_STFERR_MASK  (0x400U)
#define CAN_ESR1_STFERR_SHIFT (10U)
/*! STFERR - Stuffing Error
 *  0b0..No such occurrence.
 *  0b1..A stuffing error occurred since last read of this register.
 */
#define CAN_ESR1_STFERR(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_STFERR_SHIFT)) & CAN_ESR1_STFERR_MASK)

#define CAN_ESR1_FRMERR_MASK  (0x800U)
#define CAN_ESR1_FRMERR_SHIFT (11U)
/*! FRMERR - Form Error
 *  0b0..No such occurrence.
 *  0b1..A Form Error occurred since last read of this register.
 */
#define CAN_ESR1_FRMERR(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_FRMERR_SHIFT)) & CAN_ESR1_FRMERR_MASK)

#define CAN_ESR1_CRCERR_MASK  (0x1000U)
#define CAN_ESR1_CRCERR_SHIFT (12U)
/*! CRCERR - Cyclic Redundancy Check Error
 *  0b0..No such occurrence.
 *  0b1..A CRC error occurred since last read of this register.
 */
#define CAN_ESR1_CRCERR(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_CRCERR_SHIFT)) & CAN_ESR1_CRCERR_MASK)

#define CAN_ESR1_ACKERR_MASK  (0x2000U)
#define CAN_ESR1_ACKERR_SHIFT (13U)
/*! ACKERR - Acknowledge Error
 *  0b0..No such occurrence.
 *  0b1..An ACK error occurred since last read of this register.
 */
#define CAN_ESR1_ACKERR(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_ACKERR_SHIFT)) & CAN_ESR1_ACKERR_MASK)

#define CAN_ESR1_BIT0ERR_MASK  (0x4000U)
#define CAN_ESR1_BIT0ERR_SHIFT (14U)
/*! BIT0ERR - Bit0 Error
 *  0b0..No such occurrence.
 *  0b1..At least one bit sent as dominant is received as recessive.
 */
#define CAN_ESR1_BIT0ERR(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_BIT0ERR_SHIFT)) & CAN_ESR1_BIT0ERR_MASK)

#define CAN_ESR1_BIT1ERR_MASK  (0x8000U)
#define CAN_ESR1_BIT1ERR_SHIFT (15U)
/*! BIT1ERR - Bit1 Error
 *  0b0..No such occurrence.
 *  0b1..At least one bit sent as recessive is received as dominant.
 */
#define CAN_ESR1_BIT1ERR(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_BIT1ERR_SHIFT)) & CAN_ESR1_BIT1ERR_MASK)

#define CAN_ESR1_RWRNINT_MASK  (0x10000U)
#define CAN_ESR1_RWRNINT_SHIFT (16U)
/*! RWRNINT - Rx Warning Interrupt Flag
 *  0b0..No such occurrence.
 *  0b1..The Rx error counter transitioned from less than 96 to greater than or equal to 96.
 */
#define CAN_ESR1_RWRNINT(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_RWRNINT_SHIFT)) & CAN_ESR1_RWRNINT_MASK)

#define CAN_ESR1_TWRNINT_MASK  (0x20000U)
#define CAN_ESR1_TWRNINT_SHIFT (17U)
/*! TWRNINT - Tx Warning Interrupt Flag
 *  0b0..No such occurrence.
 *  0b1..The Tx error counter transitioned from less than 96 to greater than or equal to 96.
 */
#define CAN_ESR1_TWRNINT(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_TWRNINT_SHIFT)) & CAN_ESR1_TWRNINT_MASK)

#define CAN_ESR1_SYNCH_MASK  (0x40000U)
#define CAN_ESR1_SYNCH_SHIFT (18U)
/*! SYNCH - CAN Synchronization Status
 *  0b0..FlexCAN is not synchronized to the CAN bus.
 *  0b1..FlexCAN is synchronized to the CAN bus.
 */
#define CAN_ESR1_SYNCH(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_SYNCH_SHIFT)) & CAN_ESR1_SYNCH_MASK)

#define CAN_ESR1_BOFFDONEINT_MASK  (0x80000U)
#define CAN_ESR1_BOFFDONEINT_SHIFT (19U)
/*! BOFFDONEINT - Bus Off Done Interrupt
 *  0b0..No such occurrence.
 *  0b1..FlexCAN module has completed Bus Off process.
 */
#define CAN_ESR1_BOFFDONEINT(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_BOFFDONEINT_SHIFT)) & CAN_ESR1_BOFFDONEINT_MASK)

#define CAN_ESR1_ERRINT_FAST_MASK  (0x100000U)
#define CAN_ESR1_ERRINT_FAST_SHIFT (20U)
/*! ERRINT_FAST - Error interrupt for errors detected in Data Phase of CAN FD frames with BRS bit set
 *  0b0..No such occurrence.
 *  0b1..Indicates setting of any error bit detected in the data phase of CAN FD frames with the BRS bit set.
 */
#define CAN_ESR1_ERRINT_FAST(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_ERRINT_FAST_SHIFT)) & CAN_ESR1_ERRINT_FAST_MASK)

#define CAN_ESR1_ERROVR_MASK  (0x200000U)
#define CAN_ESR1_ERROVR_SHIFT (21U)
/*! ERROVR - Error Overrun
 *  0b0..Overrun has not occurred.
 *  0b1..Overrun has occurred.
 */
#define CAN_ESR1_ERROVR(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_ERROVR_SHIFT)) & CAN_ESR1_ERROVR_MASK)

#define CAN_ESR1_STFERR_FAST_MASK  (0x4000000U)
#define CAN_ESR1_STFERR_FAST_SHIFT (26U)
/*! STFERR_FAST - Stuffing Error in the Data Phase of CAN FD frames with the BRS bit set
 *  0b0..No such occurrence.
 *  0b1..A stuffing error occurred since last read of this register.
 */
#define CAN_ESR1_STFERR_FAST(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_STFERR_FAST_SHIFT)) & CAN_ESR1_STFERR_FAST_MASK)

#define CAN_ESR1_FRMERR_FAST_MASK  (0x8000000U)
#define CAN_ESR1_FRMERR_FAST_SHIFT (27U)
/*! FRMERR_FAST - Form Error in the Data Phase of CAN FD frames with the BRS bit set
 *  0b0..No such occurrence.
 *  0b1..A form error occurred since last read of this register.
 */
#define CAN_ESR1_FRMERR_FAST(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_FRMERR_FAST_SHIFT)) & CAN_ESR1_FRMERR_FAST_MASK)

#define CAN_ESR1_CRCERR_FAST_MASK  (0x10000000U)
#define CAN_ESR1_CRCERR_FAST_SHIFT (28U)
/*! CRCERR_FAST - Cyclic Redundancy Check Error in the CRC field of CAN FD frames with the BRS bit set
 *  0b0..No such occurrence.
 *  0b1..A CRC error occurred since last read of this register.
 */
#define CAN_ESR1_CRCERR_FAST(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_CRCERR_FAST_SHIFT)) & CAN_ESR1_CRCERR_FAST_MASK)

#define CAN_ESR1_BIT0ERR_FAST_MASK  (0x40000000U)
#define CAN_ESR1_BIT0ERR_FAST_SHIFT (30U)
/*! BIT0ERR_FAST - Bit0 Error in the Data Phase of CAN FD frames with the BRS bit set
 *  0b0..No such occurrence.
 *  0b1..At least one bit sent as dominant is received as recessive.
 */
#define CAN_ESR1_BIT0ERR_FAST(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_BIT0ERR_FAST_SHIFT)) & CAN_ESR1_BIT0ERR_FAST_MASK)

#define CAN_ESR1_BIT1ERR_FAST_MASK  (0x80000000U)
#define CAN_ESR1_BIT1ERR_FAST_SHIFT (31U)
/*! BIT1ERR_FAST - Bit1 Error in the Data Phase of CAN FD frames with the BRS bit set
 *  0b0..No such occurrence.
 *  0b1..At least one bit sent as recessive is received as dominant.
 */
#define CAN_ESR1_BIT1ERR_FAST(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_BIT1ERR_FAST_SHIFT)) & CAN_ESR1_BIT1ERR_FAST_MASK)
/*! @} */

/*! @name IMASK2 - Interrupt Masks 2 Register */
/*! @{ */

#define CAN_IMASK2_BUF63TO32M_MASK  (0xFFFFFFFFU)
#define CAN_IMASK2_BUF63TO32M_SHIFT (0U)
/*! BUF63TO32M - Buffer MBi Mask
 */
#define CAN_IMASK2_BUF63TO32M(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_IMASK2_BUF63TO32M_SHIFT)) & CAN_IMASK2_BUF63TO32M_MASK)
/*! @} */

/*! @name IMASK1 - Interrupt Masks 1 Register */
/*! @{ */

#define CAN_IMASK1_BUF31TO0M_MASK  (0xFFFFFFFFU)
#define CAN_IMASK1_BUF31TO0M_SHIFT (0U)
/*! BUF31TO0M - Buffer MBi Mask
 */
#define CAN_IMASK1_BUF31TO0M(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_IMASK1_BUF31TO0M_SHIFT)) & CAN_IMASK1_BUF31TO0M_MASK)
/*! @} */

/*! @name IFLAG2 - Interrupt Flags 2 Register */
/*! @{ */

#define CAN_IFLAG2_BUF63TO32I_MASK  (0xFFFFFFFFU)
#define CAN_IFLAG2_BUF63TO32I_SHIFT (0U)
/*! BUF63TO32I - Buffer MBi Interrupt
 */
#define CAN_IFLAG2_BUF63TO32I(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG2_BUF63TO32I_SHIFT)) & CAN_IFLAG2_BUF63TO32I_MASK)
/*! @} */

/*! @name IFLAG1 - Interrupt Flags 1 Register */
/*! @{ */

#define CAN_IFLAG1_BUF0I_MASK  (0x1U)
#define CAN_IFLAG1_BUF0I_SHIFT (0U)
/*! BUF0I - Buffer MB0 Interrupt Or Clear Legacy FIFO bit
 *  0b0..The corresponding buffer has no occurrence of successfully completed transmission or reception when
 * MCR[RFEN]=0. 0b1..The corresponding buffer has successfully completed transmission or reception when MCR[RFEN]=0.
 */
#define CAN_IFLAG1_BUF0I(x) (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF0I_SHIFT)) & CAN_IFLAG1_BUF0I_MASK)

#define CAN_IFLAG1_BUF4TO1I_MASK  (0x1EU)
#define CAN_IFLAG1_BUF4TO1I_SHIFT (1U)
/*! BUF4TO1I - Buffer MBi Interrupt Or Reserved
 */
#define CAN_IFLAG1_BUF4TO1I(x) (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF4TO1I_SHIFT)) & CAN_IFLAG1_BUF4TO1I_MASK)

#define CAN_IFLAG1_BUF5I_MASK  (0x20U)
#define CAN_IFLAG1_BUF5I_SHIFT (5U)
/*! BUF5I - Buffer MB5 Interrupt Or Frames available in Legacy Rx FIFO
 *  0b0..No occurrence of MB5 completing transmission/reception when MCR[RFEN]=0, or of frame(s) available in the Legacy
 * FIFO, when MCR[RFEN]=1 0b1..MB5 completed transmission/reception when MCR[RFEN]=0, or frame(s) available in the
 * Legacy Rx FIFO when MCR[RFEN]=1. It generates a DMA request in case of MCR[RFEN] and MCR[DMA] are enabled.
 */
#define CAN_IFLAG1_BUF5I(x) (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF5I_SHIFT)) & CAN_IFLAG1_BUF5I_MASK)

#define CAN_IFLAG1_BUF6I_MASK  (0x40U)
#define CAN_IFLAG1_BUF6I_SHIFT (6U)
/*! BUF6I - Buffer MB6 Interrupt Or Legacy Rx FIFO Warning
 *  0b0..No occurrence of MB6 completing transmission/reception when MCR[RFEN]=0, or of Legacy Rx FIFO almost full when
 * MCR[RFEN]=1 0b1..MB6 completed transmission/reception when MCR[RFEN]=0, or Legacy Rx FIFO almost full when
 * MCR[RFEN]=1
 */
#define CAN_IFLAG1_BUF6I(x) (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF6I_SHIFT)) & CAN_IFLAG1_BUF6I_MASK)

#define CAN_IFLAG1_BUF7I_MASK  (0x80U)
#define CAN_IFLAG1_BUF7I_SHIFT (7U)
/*! BUF7I - Buffer MB7 Interrupt Or Legacy Rx FIFO Overflow
 *  0b0..No occurrence of MB7 completing transmission/reception when MCR[RFEN]=0, or of Legacy Rx FIFO overflow when
 * MCR[RFEN]=1 0b1..MB7 completed transmission/reception when MCR[RFEN]=0, or Legacy Rx FIFO overflow when MCR[RFEN]=1
 */
#define CAN_IFLAG1_BUF7I(x) (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF7I_SHIFT)) & CAN_IFLAG1_BUF7I_MASK)

#define CAN_IFLAG1_BUF31TO8I_MASK  (0xFFFFFF00U)
#define CAN_IFLAG1_BUF31TO8I_SHIFT (8U)
/*! BUF31TO8I - Buffer MBi Interrupt
 */
#define CAN_IFLAG1_BUF31TO8I(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF31TO8I_SHIFT)) & CAN_IFLAG1_BUF31TO8I_MASK)
/*! @} */

/*! @name CTRL2 - Control 2 Register */
/*! @{ */

#define CAN_CTRL2_TSTAMPCAP_MASK  (0xC0U)
#define CAN_CTRL2_TSTAMPCAP_SHIFT (6U)
/*! TSTAMPCAP - Time Stamp Capture Point
 *  0b00..The high resolution time stamp capture is disabled
 *  0b01..The high resolution time stamp is captured in the end of the CAN frame
 *  0b10..The high resolution time stamp is captured in the start of the CAN frame
 *  0b11..The high resolution time stamp is captured in the start of frame for classical CAN frames and in res bit for
 * CAN FD frames
 */
#define CAN_CTRL2_TSTAMPCAP(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_TSTAMPCAP_SHIFT)) & CAN_CTRL2_TSTAMPCAP_MASK)

#define CAN_CTRL2_MBTSBASE_MASK  (0x300U)
#define CAN_CTRL2_MBTSBASE_SHIFT (8U)
/*! MBTSBASE - Message Buffer Time Stamp Base
 *  0b00..Message buffer time stamp base is TIMER
 *  0b01..Message buffer time stamp base is lower 16 bits of high resolution timer
 *  0b10..Message buffer time stamp base is upper 16 bits of high resolution timer
 *  0b11..Reserved
 */
#define CAN_CTRL2_MBTSBASE(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_MBTSBASE_SHIFT)) & CAN_CTRL2_MBTSBASE_MASK)

#define CAN_CTRL2_EDFLTDIS_MASK  (0x800U)
#define CAN_CTRL2_EDFLTDIS_SHIFT (11U)
/*! EDFLTDIS - Edge Filter Disable
 *  0b0..Edge filter is enabled
 *  0b1..Edge filter is disabled
 */
#define CAN_CTRL2_EDFLTDIS(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_EDFLTDIS_SHIFT)) & CAN_CTRL2_EDFLTDIS_MASK)

#define CAN_CTRL2_ISOCANFDEN_MASK  (0x1000U)
#define CAN_CTRL2_ISOCANFDEN_SHIFT (12U)
/*! ISOCANFDEN - ISO CAN FD Enable
 *  0b0..FlexCAN operates using the non-ISO CAN FD protocol.
 *  0b1..FlexCAN operates using the ISO CAN FD protocol (ISO 11898-1).
 */
#define CAN_CTRL2_ISOCANFDEN(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_ISOCANFDEN_SHIFT)) & CAN_CTRL2_ISOCANFDEN_MASK)

#define CAN_CTRL2_BTE_MASK  (0x2000U)
#define CAN_CTRL2_BTE_SHIFT (13U)
/*! BTE - Bit Timing Expansion enable
 *  0b0..CAN Bit timing expansion is disabled.
 *  0b1..CAN bit timing expansion is enabled.
 */
#define CAN_CTRL2_BTE(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_BTE_SHIFT)) & CAN_CTRL2_BTE_MASK)

#define CAN_CTRL2_PREXCEN_MASK  (0x4000U)
#define CAN_CTRL2_PREXCEN_SHIFT (14U)
/*! PREXCEN - Protocol Exception Enable
 *  0b0..Protocol exception is disabled.
 *  0b1..Protocol exception is enabled.
 */
#define CAN_CTRL2_PREXCEN(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_PREXCEN_SHIFT)) & CAN_CTRL2_PREXCEN_MASK)

#define CAN_CTRL2_TIMER_SRC_MASK  (0x8000U)
#define CAN_CTRL2_TIMER_SRC_SHIFT (15U)
/*! TIMER_SRC - Timer Source
 *  0b0..The free running timer is clocked by the CAN bit clock, which defines the baud rate on the CAN bus.
 *  0b1..The free running timer is clocked by an external time tick. The period can be either adjusted to be equal
 *       to the baud rate on the CAN bus, or a different value as required. See the device-specific section for
 *       details about the external time tick.
 */
#define CAN_CTRL2_TIMER_SRC(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_TIMER_SRC_SHIFT)) & CAN_CTRL2_TIMER_SRC_MASK)

#define CAN_CTRL2_EACEN_MASK  (0x10000U)
#define CAN_CTRL2_EACEN_SHIFT (16U)
/*! EACEN - Entire Frame Arbitration Field Comparison Enable For Rx Mailboxes
 *  0b0..Rx mailbox filter's IDE bit is always compared and RTR is never compared despite mask bits.
 *  0b1..Enables the comparison of both Rx mailbox filter's IDE and RTR bit with their corresponding bits within
 *       the incoming frame. Mask bits do apply.
 */
#define CAN_CTRL2_EACEN(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_EACEN_SHIFT)) & CAN_CTRL2_EACEN_MASK)

#define CAN_CTRL2_RRS_MASK  (0x20000U)
#define CAN_CTRL2_RRS_SHIFT (17U)
/*! RRS - Remote Request Storing
 *  0b0..Remote response frame is generated.
 *  0b1..Remote request frame is stored.
 */
#define CAN_CTRL2_RRS(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_RRS_SHIFT)) & CAN_CTRL2_RRS_MASK)

#define CAN_CTRL2_MRP_MASK  (0x40000U)
#define CAN_CTRL2_MRP_SHIFT (18U)
/*! MRP - Mailboxes Reception Priority
 *  0b0..Matching starts from Legacy Rx FIFO or Enhanced Rx FIFO and continues on mailboxes.
 *  0b1..Matching starts from mailboxes and continues on Legacy Rx FIFO or Enhanced Rx FIFO.
 */
#define CAN_CTRL2_MRP(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_MRP_SHIFT)) & CAN_CTRL2_MRP_MASK)

#define CAN_CTRL2_TASD_MASK  (0xF80000U)
#define CAN_CTRL2_TASD_SHIFT (19U)
/*! TASD - Tx Arbitration Start Delay
 */
#define CAN_CTRL2_TASD(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_TASD_SHIFT)) & CAN_CTRL2_TASD_MASK)

#define CAN_CTRL2_RFFN_MASK  (0xF000000U)
#define CAN_CTRL2_RFFN_SHIFT (24U)
/*! RFFN - Number Of Legacy Rx FIFO Filters
 */
#define CAN_CTRL2_RFFN(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_RFFN_SHIFT)) & CAN_CTRL2_RFFN_MASK)

#define CAN_CTRL2_WRMFRZ_MASK  (0x10000000U)
#define CAN_CTRL2_WRMFRZ_SHIFT (28U)
/*! WRMFRZ - Write-Access To Memory In Freeze Mode
 *  0b0..Maintain the write access restrictions.
 *  0b1..Enable unrestricted write access to FlexCAN memory.
 */
#define CAN_CTRL2_WRMFRZ(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_WRMFRZ_SHIFT)) & CAN_CTRL2_WRMFRZ_MASK)

#define CAN_CTRL2_ECRWRE_MASK  (0x20000000U)
#define CAN_CTRL2_ECRWRE_SHIFT (29U)
/*! ECRWRE - Error-correction Configuration Register Write Enable
 *  0b0..Disable update.
 *  0b1..Enable update.
 */
#define CAN_CTRL2_ECRWRE(x) (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_ECRWRE_SHIFT)) & CAN_CTRL2_ECRWRE_MASK)

#define CAN_CTRL2_BOFFDONEMSK_MASK  (0x40000000U)
#define CAN_CTRL2_BOFFDONEMSK_SHIFT (30U)
/*! BOFFDONEMSK - Bus Off Done Interrupt Mask
 *  0b0..Bus off done interrupt disabled.
 *  0b1..Bus off done interrupt enabled.
 */
#define CAN_CTRL2_BOFFDONEMSK(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_BOFFDONEMSK_SHIFT)) & CAN_CTRL2_BOFFDONEMSK_MASK)

#define CAN_CTRL2_ERRMSK_FAST_MASK  (0x80000000U)
#define CAN_CTRL2_ERRMSK_FAST_SHIFT (31U)
/*! ERRMSK_FAST - Error Interrupt Mask for errors detected in the data phase of fast CAN FD frames
 *  0b0..ERRINT_FAST error interrupt disabled.
 *  0b1..ERRINT_FAST error interrupt enabled.
 */
#define CAN_CTRL2_ERRMSK_FAST(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_ERRMSK_FAST_SHIFT)) & CAN_CTRL2_ERRMSK_FAST_MASK)
/*! @} */

/*! @name ESR2 - Error and Status 2 Register */
/*! @{ */

#define CAN_ESR2_IMB_MASK  (0x2000U)
#define CAN_ESR2_IMB_SHIFT (13U)
/*! IMB - Inactive Mailbox
 *  0b0..If ESR2[VPS] is asserted, the ESR2[LPTM] is not an inactive mailbox.
 *  0b1..If ESR2[VPS] is asserted, there is at least one inactive mailbox. LPTM content is the number of the first one.
 */
#define CAN_ESR2_IMB(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR2_IMB_SHIFT)) & CAN_ESR2_IMB_MASK)

#define CAN_ESR2_VPS_MASK  (0x4000U)
#define CAN_ESR2_VPS_SHIFT (14U)
/*! VPS - Valid Priority Status
 *  0b0..Contents of IMB and LPTM are invalid.
 *  0b1..Contents of IMB and LPTM are valid.
 */
#define CAN_ESR2_VPS(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR2_VPS_SHIFT)) & CAN_ESR2_VPS_MASK)

#define CAN_ESR2_LPTM_MASK  (0x7F0000U)
#define CAN_ESR2_LPTM_SHIFT (16U)
/*! LPTM - Lowest Priority Tx Mailbox
 */
#define CAN_ESR2_LPTM(x) (((uint32_t)(((uint32_t)(x)) << CAN_ESR2_LPTM_SHIFT)) & CAN_ESR2_LPTM_MASK)
/*! @} */

/*! @name CRCR - CRC Register */
/*! @{ */

#define CAN_CRCR_TXCRC_MASK  (0x7FFFU)
#define CAN_CRCR_TXCRC_SHIFT (0U)
/*! TXCRC - Transmitted CRC value
 */
#define CAN_CRCR_TXCRC(x) (((uint32_t)(((uint32_t)(x)) << CAN_CRCR_TXCRC_SHIFT)) & CAN_CRCR_TXCRC_MASK)

#define CAN_CRCR_MBCRC_MASK  (0x7F0000U)
#define CAN_CRCR_MBCRC_SHIFT (16U)
/*! MBCRC - CRC Mailbox
 */
#define CAN_CRCR_MBCRC(x) (((uint32_t)(((uint32_t)(x)) << CAN_CRCR_MBCRC_SHIFT)) & CAN_CRCR_MBCRC_MASK)
/*! @} */

/*! @name RXFGMASK - Legacy Rx FIFO Global Mask Register */
/*! @{ */

#define CAN_RXFGMASK_FGM_MASK  (0xFFFFFFFFU)
#define CAN_RXFGMASK_FGM_SHIFT (0U)
/*! FGM - Legacy Rx FIFO Global Mask Bits
 */
#define CAN_RXFGMASK_FGM(x) (((uint32_t)(((uint32_t)(x)) << CAN_RXFGMASK_FGM_SHIFT)) & CAN_RXFGMASK_FGM_MASK)
/*! @} */

/*! @name RXFIR - Legacy Rx FIFO Information Register */
/*! @{ */

#define CAN_RXFIR_IDHIT_MASK  (0x1FFU)
#define CAN_RXFIR_IDHIT_SHIFT (0U)
/*! IDHIT - Identifier Acceptance Filter Hit Indicator
 */
#define CAN_RXFIR_IDHIT(x) (((uint32_t)(((uint32_t)(x)) << CAN_RXFIR_IDHIT_SHIFT)) & CAN_RXFIR_IDHIT_MASK)
/*! @} */

/*! @name CBT - CAN Bit Timing Register */
/*! @{ */

#define CAN_CBT_EPSEG2_MASK  (0x1FU)
#define CAN_CBT_EPSEG2_SHIFT (0U)
/*! EPSEG2 - Extended Phase Segment 2
 */
#define CAN_CBT_EPSEG2(x) (((uint32_t)(((uint32_t)(x)) << CAN_CBT_EPSEG2_SHIFT)) & CAN_CBT_EPSEG2_MASK)

#define CAN_CBT_EPSEG1_MASK  (0x3E0U)
#define CAN_CBT_EPSEG1_SHIFT (5U)
/*! EPSEG1 - Extended Phase Segment 1
 */
#define CAN_CBT_EPSEG1(x) (((uint32_t)(((uint32_t)(x)) << CAN_CBT_EPSEG1_SHIFT)) & CAN_CBT_EPSEG1_MASK)

#define CAN_CBT_EPROPSEG_MASK  (0xFC00U)
#define CAN_CBT_EPROPSEG_SHIFT (10U)
/*! EPROPSEG - Extended Propagation Segment
 */
#define CAN_CBT_EPROPSEG(x) (((uint32_t)(((uint32_t)(x)) << CAN_CBT_EPROPSEG_SHIFT)) & CAN_CBT_EPROPSEG_MASK)

#define CAN_CBT_ERJW_MASK  (0x1F0000U)
#define CAN_CBT_ERJW_SHIFT (16U)
/*! ERJW - Extended Resync Jump Width
 */
#define CAN_CBT_ERJW(x) (((uint32_t)(((uint32_t)(x)) << CAN_CBT_ERJW_SHIFT)) & CAN_CBT_ERJW_MASK)

#define CAN_CBT_EPRESDIV_MASK  (0x7FE00000U)
#define CAN_CBT_EPRESDIV_SHIFT (21U)
/*! EPRESDIV - Extended Prescaler Division Factor
 */
#define CAN_CBT_EPRESDIV(x) (((uint32_t)(((uint32_t)(x)) << CAN_CBT_EPRESDIV_SHIFT)) & CAN_CBT_EPRESDIV_MASK)

#define CAN_CBT_BTF_MASK  (0x80000000U)
#define CAN_CBT_BTF_SHIFT (31U)
/*! BTF - Bit Timing Format Enable
 *  0b0..Extended bit time definitions disabled.
 *  0b1..Extended bit time definitions enabled.
 */
#define CAN_CBT_BTF(x) (((uint32_t)(((uint32_t)(x)) << CAN_CBT_BTF_SHIFT)) & CAN_CBT_BTF_MASK)
/*! @} */

/*! @name IMASK3 - Interrupt Masks 3 Register */
/*! @{ */

#define CAN_IMASK3_BUF95TO64M_MASK  (0xFFFFFFFFU)
#define CAN_IMASK3_BUF95TO64M_SHIFT (0U)
/*! BUF95TO64M - Buffer MBi Mask
 */
#define CAN_IMASK3_BUF95TO64M(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_IMASK3_BUF95TO64M_SHIFT)) & CAN_IMASK3_BUF95TO64M_MASK)
/*! @} */

/*! @name IFLAG3 - Interrupt Flags 3 Register */
/*! @{ */

#define CAN_IFLAG3_BUF95TO64_MASK  (0xFFFFFFFFU)
#define CAN_IFLAG3_BUF95TO64_SHIFT (0U)
/*! BUF95TO64 - Buffer MBi Interrupt
 */
#define CAN_IFLAG3_BUF95TO64(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG3_BUF95TO64_SHIFT)) & CAN_IFLAG3_BUF95TO64_MASK)
/*! @} */

/* The count of CAN_CS */
#define CAN_CS_COUNT_MB8B (96U)

/* The count of CAN_ID */
#define CAN_ID_COUNT_MB8B (96U)

/* The count of CAN_WORD */
#define CAN_WORD_COUNT_MB8B (96U)

/* The count of CAN_WORD */
#define CAN_WORD_COUNT_MB8B2 (2U)

/* The count of CAN_CS */
#define CAN_CS_COUNT_MB16B (63U)

/* The count of CAN_ID */
#define CAN_ID_COUNT_MB16B (63U)

/* The count of CAN_WORD */
#define CAN_WORD_COUNT_MB16B (63U)

/* The count of CAN_WORD */
#define CAN_WORD_COUNT_MB16B2 (4U)

/* The count of CAN_CS */
#define CAN_CS_COUNT_MB32B (36U)

/* The count of CAN_ID */
#define CAN_ID_COUNT_MB32B (36U)

/* The count of CAN_WORD */
#define CAN_WORD_COUNT_MB32B (36U)

/* The count of CAN_WORD */
#define CAN_WORD_COUNT_MB32B2 (8U)

/*! @name CS - Message Buffer 0 CS Register..Message Buffer 20 CS Register */
/*! @{ */

#define CAN_CS_TIME_STAMP_MASK  (0xFFFFU)
#define CAN_CS_TIME_STAMP_SHIFT (0U)
/*! TIME_STAMP - Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running
 *    Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field
 *    appears on the CAN bus.
 */
#define CAN_CS_TIME_STAMP(x) (((uint32_t)(((uint32_t)(x)) << CAN_CS_TIME_STAMP_SHIFT)) & CAN_CS_TIME_STAMP_MASK)

#define CAN_CS_DLC_MASK  (0xF0000U)
#define CAN_CS_DLC_SHIFT (16U)
/*! DLC - Length of the data to be stored/transmitted.
 */
#define CAN_CS_DLC(x) (((uint32_t)(((uint32_t)(x)) << CAN_CS_DLC_SHIFT)) & CAN_CS_DLC_MASK)

#define CAN_CS_RTR_MASK  (0x100000U)
#define CAN_CS_RTR_SHIFT (20U)
/*! RTR - Remote Transmission Request. One/zero for remote/data frame.
 */
#define CAN_CS_RTR(x) (((uint32_t)(((uint32_t)(x)) << CAN_CS_RTR_SHIFT)) & CAN_CS_RTR_MASK)

#define CAN_CS_IDE_MASK  (0x200000U)
#define CAN_CS_IDE_SHIFT (21U)
/*! IDE - ID Extended. One/zero for extended/standard format frame.
 */
#define CAN_CS_IDE(x) (((uint32_t)(((uint32_t)(x)) << CAN_CS_IDE_SHIFT)) & CAN_CS_IDE_MASK)

#define CAN_CS_SRR_MASK  (0x400000U)
#define CAN_CS_SRR_SHIFT (22U)
/*! SRR - Substitute Remote Request. Contains a fixed recessive bit.
 */
#define CAN_CS_SRR(x) (((uint32_t)(((uint32_t)(x)) << CAN_CS_SRR_SHIFT)) & CAN_CS_SRR_MASK)

#define CAN_CS_CODE_MASK  (0xF000000U)
#define CAN_CS_CODE_SHIFT (24U)
/*! CODE - Message Buffer Code. This 4-bit field can be accessed (read or write) by the CPU and by
 *    the FlexCAN module itself, as part of the message buffer matching and arbitration process.
 */
#define CAN_CS_CODE(x) (((uint32_t)(((uint32_t)(x)) << CAN_CS_CODE_SHIFT)) & CAN_CS_CODE_MASK)

#define CAN_CS_ESI_MASK  (0x20000000U)
#define CAN_CS_ESI_SHIFT (29U)
/*! ESI - Error State Indicator. This bit indicates if the transmitting node is error active or error passive.
 */
#define CAN_CS_ESI(x) (((uint32_t)(((uint32_t)(x)) << CAN_CS_ESI_SHIFT)) & CAN_CS_ESI_MASK)

#define CAN_CS_BRS_MASK  (0x40000000U)
#define CAN_CS_BRS_SHIFT (30U)
/*! BRS - Bit Rate Switch. This bit defines whether the bit rate is switched inside a CAN FD format frame.
 */
#define CAN_CS_BRS(x) (((uint32_t)(((uint32_t)(x)) << CAN_CS_BRS_SHIFT)) & CAN_CS_BRS_MASK)

#define CAN_CS_EDL_MASK  (0x80000000U)
#define CAN_CS_EDL_SHIFT (31U)
/*! EDL - Extended Data Length. This bit distinguishes between CAN format and CAN FD format frames.
 *    The EDL bit must not be set for Message Buffers configured to RANSWER with code field 0b1010.
 */
#define CAN_CS_EDL(x) (((uint32_t)(((uint32_t)(x)) << CAN_CS_EDL_SHIFT)) & CAN_CS_EDL_MASK)
/*! @} */

/* The count of CAN_CS */
#define CAN_CS_COUNT_MB64B (21U)

/*! @name ID - Message Buffer 0 ID Register..Message Buffer 20 ID Register */
/*! @{ */

#define CAN_ID_EXT_MASK  (0x3FFFFU)
#define CAN_ID_EXT_SHIFT (0U)
/*! EXT - Contains extended (LOW word) identifier of message buffer.
 */
#define CAN_ID_EXT(x) (((uint32_t)(((uint32_t)(x)) << CAN_ID_EXT_SHIFT)) & CAN_ID_EXT_MASK)

#define CAN_ID_STD_MASK  (0x1FFC0000U)
#define CAN_ID_STD_SHIFT (18U)
/*! STD - Contains standard/extended (HIGH word) identifier of message buffer.
 */
#define CAN_ID_STD(x) (((uint32_t)(((uint32_t)(x)) << CAN_ID_STD_SHIFT)) & CAN_ID_STD_MASK)

#define CAN_ID_PRIO_MASK  (0xE0000000U)
#define CAN_ID_PRIO_SHIFT (29U)
/*! PRIO - Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only
 *    makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular
 *    ID to define the transmission priority.
 */
#define CAN_ID_PRIO(x) (((uint32_t)(((uint32_t)(x)) << CAN_ID_PRIO_SHIFT)) & CAN_ID_PRIO_MASK)
/*! @} */

/* The count of CAN_ID */
#define CAN_ID_COUNT_MB64B (21U)

/*! @name WORD - Message Buffer 0 WORD_64B Register..Message Buffer 20 WORD_64B Register */
/*! @{ */

#define CAN_WORD_DATA_BYTE_3_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_3_SHIFT (0U)
/*! DATA_BYTE_3 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_3(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_3_SHIFT)) & CAN_WORD_DATA_BYTE_3_MASK)

#define CAN_WORD_DATA_BYTE_7_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_7_SHIFT (0U)
/*! DATA_BYTE_7 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_7(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_7_SHIFT)) & CAN_WORD_DATA_BYTE_7_MASK)

#define CAN_WORD_DATA_BYTE_11_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_11_SHIFT (0U)
/*! DATA_BYTE_11 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_11(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_11_SHIFT)) & CAN_WORD_DATA_BYTE_11_MASK)

#define CAN_WORD_DATA_BYTE_15_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_15_SHIFT (0U)
/*! DATA_BYTE_15 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_15(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_15_SHIFT)) & CAN_WORD_DATA_BYTE_15_MASK)

#define CAN_WORD_DATA_BYTE_19_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_19_SHIFT (0U)
/*! DATA_BYTE_19 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_19(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_19_SHIFT)) & CAN_WORD_DATA_BYTE_19_MASK)

#define CAN_WORD_DATA_BYTE_23_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_23_SHIFT (0U)
/*! DATA_BYTE_23 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_23(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_23_SHIFT)) & CAN_WORD_DATA_BYTE_23_MASK)

#define CAN_WORD_DATA_BYTE_27_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_27_SHIFT (0U)
/*! DATA_BYTE_27 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_27(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_27_SHIFT)) & CAN_WORD_DATA_BYTE_27_MASK)

#define CAN_WORD_DATA_BYTE_31_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_31_SHIFT (0U)
/*! DATA_BYTE_31 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_31(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_31_SHIFT)) & CAN_WORD_DATA_BYTE_31_MASK)

#define CAN_WORD_DATA_BYTE_35_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_35_SHIFT (0U)
/*! DATA_BYTE_35 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_35(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_35_SHIFT)) & CAN_WORD_DATA_BYTE_35_MASK)

#define CAN_WORD_DATA_BYTE_39_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_39_SHIFT (0U)
/*! DATA_BYTE_39 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_39(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_39_SHIFT)) & CAN_WORD_DATA_BYTE_39_MASK)

#define CAN_WORD_DATA_BYTE_43_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_43_SHIFT (0U)
/*! DATA_BYTE_43 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_43(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_43_SHIFT)) & CAN_WORD_DATA_BYTE_43_MASK)

#define CAN_WORD_DATA_BYTE_47_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_47_SHIFT (0U)
/*! DATA_BYTE_47 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_47(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_47_SHIFT)) & CAN_WORD_DATA_BYTE_47_MASK)

#define CAN_WORD_DATA_BYTE_51_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_51_SHIFT (0U)
/*! DATA_BYTE_51 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_51(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_51_SHIFT)) & CAN_WORD_DATA_BYTE_51_MASK)

#define CAN_WORD_DATA_BYTE_55_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_55_SHIFT (0U)
/*! DATA_BYTE_55 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_55(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_55_SHIFT)) & CAN_WORD_DATA_BYTE_55_MASK)

#define CAN_WORD_DATA_BYTE_59_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_59_SHIFT (0U)
/*! DATA_BYTE_59 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_59(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_59_SHIFT)) & CAN_WORD_DATA_BYTE_59_MASK)

#define CAN_WORD_DATA_BYTE_63_MASK  (0xFFU)
#define CAN_WORD_DATA_BYTE_63_SHIFT (0U)
/*! DATA_BYTE_63 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_63(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_63_SHIFT)) & CAN_WORD_DATA_BYTE_63_MASK)

#define CAN_WORD_DATA_BYTE_2_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_2_SHIFT (8U)
/*! DATA_BYTE_2 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_2(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_2_SHIFT)) & CAN_WORD_DATA_BYTE_2_MASK)

#define CAN_WORD_DATA_BYTE_6_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_6_SHIFT (8U)
/*! DATA_BYTE_6 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_6(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_6_SHIFT)) & CAN_WORD_DATA_BYTE_6_MASK)

#define CAN_WORD_DATA_BYTE_10_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_10_SHIFT (8U)
/*! DATA_BYTE_10 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_10(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_10_SHIFT)) & CAN_WORD_DATA_BYTE_10_MASK)

#define CAN_WORD_DATA_BYTE_14_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_14_SHIFT (8U)
/*! DATA_BYTE_14 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_14(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_14_SHIFT)) & CAN_WORD_DATA_BYTE_14_MASK)

#define CAN_WORD_DATA_BYTE_18_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_18_SHIFT (8U)
/*! DATA_BYTE_18 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_18(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_18_SHIFT)) & CAN_WORD_DATA_BYTE_18_MASK)

#define CAN_WORD_DATA_BYTE_22_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_22_SHIFT (8U)
/*! DATA_BYTE_22 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_22(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_22_SHIFT)) & CAN_WORD_DATA_BYTE_22_MASK)

#define CAN_WORD_DATA_BYTE_26_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_26_SHIFT (8U)
/*! DATA_BYTE_26 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_26(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_26_SHIFT)) & CAN_WORD_DATA_BYTE_26_MASK)

#define CAN_WORD_DATA_BYTE_30_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_30_SHIFT (8U)
/*! DATA_BYTE_30 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_30(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_30_SHIFT)) & CAN_WORD_DATA_BYTE_30_MASK)

#define CAN_WORD_DATA_BYTE_34_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_34_SHIFT (8U)
/*! DATA_BYTE_34 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_34(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_34_SHIFT)) & CAN_WORD_DATA_BYTE_34_MASK)

#define CAN_WORD_DATA_BYTE_38_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_38_SHIFT (8U)
/*! DATA_BYTE_38 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_38(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_38_SHIFT)) & CAN_WORD_DATA_BYTE_38_MASK)

#define CAN_WORD_DATA_BYTE_42_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_42_SHIFT (8U)
/*! DATA_BYTE_42 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_42(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_42_SHIFT)) & CAN_WORD_DATA_BYTE_42_MASK)

#define CAN_WORD_DATA_BYTE_46_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_46_SHIFT (8U)
/*! DATA_BYTE_46 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_46(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_46_SHIFT)) & CAN_WORD_DATA_BYTE_46_MASK)

#define CAN_WORD_DATA_BYTE_50_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_50_SHIFT (8U)
/*! DATA_BYTE_50 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_50(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_50_SHIFT)) & CAN_WORD_DATA_BYTE_50_MASK)

#define CAN_WORD_DATA_BYTE_54_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_54_SHIFT (8U)
/*! DATA_BYTE_54 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_54(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_54_SHIFT)) & CAN_WORD_DATA_BYTE_54_MASK)

#define CAN_WORD_DATA_BYTE_58_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_58_SHIFT (8U)
/*! DATA_BYTE_58 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_58(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_58_SHIFT)) & CAN_WORD_DATA_BYTE_58_MASK)

#define CAN_WORD_DATA_BYTE_62_MASK  (0xFF00U)
#define CAN_WORD_DATA_BYTE_62_SHIFT (8U)
/*! DATA_BYTE_62 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_62(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_62_SHIFT)) & CAN_WORD_DATA_BYTE_62_MASK)

#define CAN_WORD_DATA_BYTE_1_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_1_SHIFT (16U)
/*! DATA_BYTE_1 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_1(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_1_SHIFT)) & CAN_WORD_DATA_BYTE_1_MASK)

#define CAN_WORD_DATA_BYTE_5_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_5_SHIFT (16U)
/*! DATA_BYTE_5 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_5(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_5_SHIFT)) & CAN_WORD_DATA_BYTE_5_MASK)

#define CAN_WORD_DATA_BYTE_9_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_9_SHIFT (16U)
/*! DATA_BYTE_9 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_9(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_9_SHIFT)) & CAN_WORD_DATA_BYTE_9_MASK)

#define CAN_WORD_DATA_BYTE_13_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_13_SHIFT (16U)
/*! DATA_BYTE_13 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_13(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_13_SHIFT)) & CAN_WORD_DATA_BYTE_13_MASK)

#define CAN_WORD_DATA_BYTE_17_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_17_SHIFT (16U)
/*! DATA_BYTE_17 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_17(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_17_SHIFT)) & CAN_WORD_DATA_BYTE_17_MASK)

#define CAN_WORD_DATA_BYTE_21_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_21_SHIFT (16U)
/*! DATA_BYTE_21 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_21(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_21_SHIFT)) & CAN_WORD_DATA_BYTE_21_MASK)

#define CAN_WORD_DATA_BYTE_25_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_25_SHIFT (16U)
/*! DATA_BYTE_25 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_25(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_25_SHIFT)) & CAN_WORD_DATA_BYTE_25_MASK)

#define CAN_WORD_DATA_BYTE_29_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_29_SHIFT (16U)
/*! DATA_BYTE_29 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_29(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_29_SHIFT)) & CAN_WORD_DATA_BYTE_29_MASK)

#define CAN_WORD_DATA_BYTE_33_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_33_SHIFT (16U)
/*! DATA_BYTE_33 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_33(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_33_SHIFT)) & CAN_WORD_DATA_BYTE_33_MASK)

#define CAN_WORD_DATA_BYTE_37_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_37_SHIFT (16U)
/*! DATA_BYTE_37 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_37(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_37_SHIFT)) & CAN_WORD_DATA_BYTE_37_MASK)

#define CAN_WORD_DATA_BYTE_41_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_41_SHIFT (16U)
/*! DATA_BYTE_41 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_41(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_41_SHIFT)) & CAN_WORD_DATA_BYTE_41_MASK)

#define CAN_WORD_DATA_BYTE_45_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_45_SHIFT (16U)
/*! DATA_BYTE_45 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_45(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_45_SHIFT)) & CAN_WORD_DATA_BYTE_45_MASK)

#define CAN_WORD_DATA_BYTE_49_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_49_SHIFT (16U)
/*! DATA_BYTE_49 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_49(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_49_SHIFT)) & CAN_WORD_DATA_BYTE_49_MASK)

#define CAN_WORD_DATA_BYTE_53_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_53_SHIFT (16U)
/*! DATA_BYTE_53 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_53(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_53_SHIFT)) & CAN_WORD_DATA_BYTE_53_MASK)

#define CAN_WORD_DATA_BYTE_57_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_57_SHIFT (16U)
/*! DATA_BYTE_57 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_57(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_57_SHIFT)) & CAN_WORD_DATA_BYTE_57_MASK)

#define CAN_WORD_DATA_BYTE_61_MASK  (0xFF0000U)
#define CAN_WORD_DATA_BYTE_61_SHIFT (16U)
/*! DATA_BYTE_61 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_61(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_61_SHIFT)) & CAN_WORD_DATA_BYTE_61_MASK)

#define CAN_WORD_DATA_BYTE_0_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_0_SHIFT (24U)
/*! DATA_BYTE_0 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_0(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_0_SHIFT)) & CAN_WORD_DATA_BYTE_0_MASK)

#define CAN_WORD_DATA_BYTE_4_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_4_SHIFT (24U)
/*! DATA_BYTE_4 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_4(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_4_SHIFT)) & CAN_WORD_DATA_BYTE_4_MASK)

#define CAN_WORD_DATA_BYTE_8_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_8_SHIFT (24U)
/*! DATA_BYTE_8 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_8(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_8_SHIFT)) & CAN_WORD_DATA_BYTE_8_MASK)

#define CAN_WORD_DATA_BYTE_12_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_12_SHIFT (24U)
/*! DATA_BYTE_12 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_12(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_12_SHIFT)) & CAN_WORD_DATA_BYTE_12_MASK)

#define CAN_WORD_DATA_BYTE_16_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_16_SHIFT (24U)
/*! DATA_BYTE_16 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_16(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_16_SHIFT)) & CAN_WORD_DATA_BYTE_16_MASK)

#define CAN_WORD_DATA_BYTE_20_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_20_SHIFT (24U)
/*! DATA_BYTE_20 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_20(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_20_SHIFT)) & CAN_WORD_DATA_BYTE_20_MASK)

#define CAN_WORD_DATA_BYTE_24_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_24_SHIFT (24U)
/*! DATA_BYTE_24 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_24(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_24_SHIFT)) & CAN_WORD_DATA_BYTE_24_MASK)

#define CAN_WORD_DATA_BYTE_28_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_28_SHIFT (24U)
/*! DATA_BYTE_28 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_28(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_28_SHIFT)) & CAN_WORD_DATA_BYTE_28_MASK)

#define CAN_WORD_DATA_BYTE_32_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_32_SHIFT (24U)
/*! DATA_BYTE_32 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_32(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_32_SHIFT)) & CAN_WORD_DATA_BYTE_32_MASK)

#define CAN_WORD_DATA_BYTE_36_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_36_SHIFT (24U)
/*! DATA_BYTE_36 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_36(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_36_SHIFT)) & CAN_WORD_DATA_BYTE_36_MASK)

#define CAN_WORD_DATA_BYTE_40_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_40_SHIFT (24U)
/*! DATA_BYTE_40 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_40(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_40_SHIFT)) & CAN_WORD_DATA_BYTE_40_MASK)

#define CAN_WORD_DATA_BYTE_44_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_44_SHIFT (24U)
/*! DATA_BYTE_44 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_44(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_44_SHIFT)) & CAN_WORD_DATA_BYTE_44_MASK)

#define CAN_WORD_DATA_BYTE_48_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_48_SHIFT (24U)
/*! DATA_BYTE_48 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_48(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_48_SHIFT)) & CAN_WORD_DATA_BYTE_48_MASK)

#define CAN_WORD_DATA_BYTE_52_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_52_SHIFT (24U)
/*! DATA_BYTE_52 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_52(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_52_SHIFT)) & CAN_WORD_DATA_BYTE_52_MASK)

#define CAN_WORD_DATA_BYTE_56_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_56_SHIFT (24U)
/*! DATA_BYTE_56 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_56(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_56_SHIFT)) & CAN_WORD_DATA_BYTE_56_MASK)

#define CAN_WORD_DATA_BYTE_60_MASK  (0xFF000000U)
#define CAN_WORD_DATA_BYTE_60_SHIFT (24U)
/*! DATA_BYTE_60 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD_DATA_BYTE_60(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD_DATA_BYTE_60_SHIFT)) & CAN_WORD_DATA_BYTE_60_MASK)
/*! @} */

/* The count of CAN_WORD */
#define CAN_WORD_COUNT_MB64B (21U)

/* The count of CAN_WORD */
#define CAN_WORD_COUNT_MB64B2 (16U)

/* The count of CAN_CS */
#define CAN_CS_COUNT (96U)

/* The count of CAN_ID */
#define CAN_ID_COUNT (96U)

/*! @name WORD0 - Message Buffer 0 WORD0 Register..Message Buffer 95 WORD0 Register */
/*! @{ */

#define CAN_WORD0_DATA_BYTE_3_MASK  (0xFFU)
#define CAN_WORD0_DATA_BYTE_3_SHIFT (0U)
/*! DATA_BYTE_3 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD0_DATA_BYTE_3(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD0_DATA_BYTE_3_SHIFT)) & CAN_WORD0_DATA_BYTE_3_MASK)

#define CAN_WORD0_DATA_BYTE_2_MASK  (0xFF00U)
#define CAN_WORD0_DATA_BYTE_2_SHIFT (8U)
/*! DATA_BYTE_2 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD0_DATA_BYTE_2(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD0_DATA_BYTE_2_SHIFT)) & CAN_WORD0_DATA_BYTE_2_MASK)

#define CAN_WORD0_DATA_BYTE_1_MASK  (0xFF0000U)
#define CAN_WORD0_DATA_BYTE_1_SHIFT (16U)
/*! DATA_BYTE_1 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD0_DATA_BYTE_1(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD0_DATA_BYTE_1_SHIFT)) & CAN_WORD0_DATA_BYTE_1_MASK)

#define CAN_WORD0_DATA_BYTE_0_MASK  (0xFF000000U)
#define CAN_WORD0_DATA_BYTE_0_SHIFT (24U)
/*! DATA_BYTE_0 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD0_DATA_BYTE_0(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD0_DATA_BYTE_0_SHIFT)) & CAN_WORD0_DATA_BYTE_0_MASK)
/*! @} */

/* The count of CAN_WORD0 */
#define CAN_WORD0_COUNT (96U)

/*! @name WORD1 - Message Buffer 0 WORD1 Register..Message Buffer 95 WORD1 Register */
/*! @{ */

#define CAN_WORD1_DATA_BYTE_7_MASK  (0xFFU)
#define CAN_WORD1_DATA_BYTE_7_SHIFT (0U)
/*! DATA_BYTE_7 - Data byte 0 of Rx/Tx frame.
 */
#define CAN_WORD1_DATA_BYTE_7(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD1_DATA_BYTE_7_SHIFT)) & CAN_WORD1_DATA_BYTE_7_MASK)

#define CAN_WORD1_DATA_BYTE_6_MASK  (0xFF00U)
#define CAN_WORD1_DATA_BYTE_6_SHIFT (8U)
/*! DATA_BYTE_6 - Data byte 1 of Rx/Tx frame.
 */
#define CAN_WORD1_DATA_BYTE_6(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD1_DATA_BYTE_6_SHIFT)) & CAN_WORD1_DATA_BYTE_6_MASK)

#define CAN_WORD1_DATA_BYTE_5_MASK  (0xFF0000U)
#define CAN_WORD1_DATA_BYTE_5_SHIFT (16U)
/*! DATA_BYTE_5 - Data byte 2 of Rx/Tx frame.
 */
#define CAN_WORD1_DATA_BYTE_5(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD1_DATA_BYTE_5_SHIFT)) & CAN_WORD1_DATA_BYTE_5_MASK)

#define CAN_WORD1_DATA_BYTE_4_MASK  (0xFF000000U)
#define CAN_WORD1_DATA_BYTE_4_SHIFT (24U)
/*! DATA_BYTE_4 - Data byte 3 of Rx/Tx frame.
 */
#define CAN_WORD1_DATA_BYTE_4(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_WORD1_DATA_BYTE_4_SHIFT)) & CAN_WORD1_DATA_BYTE_4_MASK)
/*! @} */

/* The count of CAN_WORD1 */
#define CAN_WORD1_COUNT (96U)

/*! @name RXIMR - Rx Individual Mask Registers */
/*! @{ */

#define CAN_RXIMR_MI_MASK  (0xFFFFFFFFU)
#define CAN_RXIMR_MI_SHIFT (0U)
/*! MI - Individual Mask Bits
 */
#define CAN_RXIMR_MI(x) (((uint32_t)(((uint32_t)(x)) << CAN_RXIMR_MI_SHIFT)) & CAN_RXIMR_MI_MASK)
/*! @} */

/* The count of CAN_RXIMR */
#define CAN_RXIMR_COUNT (96U)

/*! @name MECR - Memory Error Control Register */
/*! @{ */

#define CAN_MECR_NCEFAFRZ_MASK  (0x80U)
#define CAN_MECR_NCEFAFRZ_SHIFT (7U)
/*! NCEFAFRZ - Non-Correctable Errors In FlexCAN Access Put Device In Freeze Mode
 *  0b0..Keep normal operation.
 *  0b1..Put FlexCAN in Freeze mode (see section "Freeze mode").
 */
#define CAN_MECR_NCEFAFRZ(x) (((uint32_t)(((uint32_t)(x)) << CAN_MECR_NCEFAFRZ_SHIFT)) & CAN_MECR_NCEFAFRZ_MASK)

#define CAN_MECR_ECCDIS_MASK  (0x100U)
#define CAN_MECR_ECCDIS_SHIFT (8U)
/*! ECCDIS - Error Correction Disable
 *  0b0..Enable memory error correction.
 *  0b1..Disable memory error correction.
 */
#define CAN_MECR_ECCDIS(x) (((uint32_t)(((uint32_t)(x)) << CAN_MECR_ECCDIS_SHIFT)) & CAN_MECR_ECCDIS_MASK)

#define CAN_MECR_RERRDIS_MASK  (0x200U)
#define CAN_MECR_RERRDIS_SHIFT (9U)
/*! RERRDIS - Error Report Disable
 *  0b0..Enable updates of the error report registers.
 *  0b1..Disable updates of the error report registers.
 */
#define CAN_MECR_RERRDIS(x) (((uint32_t)(((uint32_t)(x)) << CAN_MECR_RERRDIS_SHIFT)) & CAN_MECR_RERRDIS_MASK)

#define CAN_MECR_EXTERRIE_MASK  (0x2000U)
#define CAN_MECR_EXTERRIE_SHIFT (13U)
/*! EXTERRIE - Extended Error Injection Enable
 *  0b0..Error injection is applied only to the 32-bit word.
 *  0b1..Error injection is applied to the 64-bit word.
 */
#define CAN_MECR_EXTERRIE(x) (((uint32_t)(((uint32_t)(x)) << CAN_MECR_EXTERRIE_SHIFT)) & CAN_MECR_EXTERRIE_MASK)

#define CAN_MECR_FAERRIE_MASK  (0x4000U)
#define CAN_MECR_FAERRIE_SHIFT (14U)
/*! FAERRIE - FlexCAN Access Error Injection Enable
 *  0b0..Injection is disabled.
 *  0b1..Injection is enabled.
 */
#define CAN_MECR_FAERRIE(x) (((uint32_t)(((uint32_t)(x)) << CAN_MECR_FAERRIE_SHIFT)) & CAN_MECR_FAERRIE_MASK)

#define CAN_MECR_HAERRIE_MASK  (0x8000U)
#define CAN_MECR_HAERRIE_SHIFT (15U)
/*! HAERRIE - Host Access Error Injection Enable
 *  0b0..Injection is disabled.
 *  0b1..Injection is enabled.
 */
#define CAN_MECR_HAERRIE(x) (((uint32_t)(((uint32_t)(x)) << CAN_MECR_HAERRIE_SHIFT)) & CAN_MECR_HAERRIE_MASK)

#define CAN_MECR_CEI_MSK_MASK  (0x10000U)
#define CAN_MECR_CEI_MSK_SHIFT (16U)
/*! CEI_MSK - Correctable Errors Interrupt Mask
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define CAN_MECR_CEI_MSK(x) (((uint32_t)(((uint32_t)(x)) << CAN_MECR_CEI_MSK_SHIFT)) & CAN_MECR_CEI_MSK_MASK)

#define CAN_MECR_FANCEI_MSK_MASK  (0x40000U)
#define CAN_MECR_FANCEI_MSK_SHIFT (18U)
/*! FANCEI_MSK - FlexCAN Access With Non-Correctable Errors Interrupt Mask
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define CAN_MECR_FANCEI_MSK(x) (((uint32_t)(((uint32_t)(x)) << CAN_MECR_FANCEI_MSK_SHIFT)) & CAN_MECR_FANCEI_MSK_MASK)

#define CAN_MECR_HANCEI_MSK_MASK  (0x80000U)
#define CAN_MECR_HANCEI_MSK_SHIFT (19U)
/*! HANCEI_MSK - Host Access With Non-Correctable Errors Interrupt Mask
 *  0b0..Interrupt is disabled.
 *  0b1..Interrupt is enabled.
 */
#define CAN_MECR_HANCEI_MSK(x) (((uint32_t)(((uint32_t)(x)) << CAN_MECR_HANCEI_MSK_SHIFT)) & CAN_MECR_HANCEI_MSK_MASK)

#define CAN_MECR_ECRWRDIS_MASK  (0x80000000U)
#define CAN_MECR_ECRWRDIS_SHIFT (31U)
/*! ECRWRDIS - Error Configuration Register Write Disable
 *  0b0..Write is enabled.
 *  0b1..Write is disabled.
 */
#define CAN_MECR_ECRWRDIS(x) (((uint32_t)(((uint32_t)(x)) << CAN_MECR_ECRWRDIS_SHIFT)) & CAN_MECR_ECRWRDIS_MASK)
/*! @} */

/*! @name ERRIAR - Error Injection Address Register */
/*! @{ */

#define CAN_ERRIAR_INJADDR_L_MASK  (0x3U)
#define CAN_ERRIAR_INJADDR_L_SHIFT (0U)
/*! INJADDR_L - Error Injection Address Low
 */
#define CAN_ERRIAR_INJADDR_L(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_ERRIAR_INJADDR_L_SHIFT)) & CAN_ERRIAR_INJADDR_L_MASK)

#define CAN_ERRIAR_INJADDR_H_MASK  (0x3FFCU)
#define CAN_ERRIAR_INJADDR_H_SHIFT (2U)
/*! INJADDR_H - Error Injection Address High
 */
#define CAN_ERRIAR_INJADDR_H(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_ERRIAR_INJADDR_H_SHIFT)) & CAN_ERRIAR_INJADDR_H_MASK)
/*! @} */

/*! @name ERRIDPR - Error Injection Data Pattern Register */
/*! @{ */

#define CAN_ERRIDPR_DFLIP_MASK  (0xFFFFFFFFU)
#define CAN_ERRIDPR_DFLIP_SHIFT (0U)
/*! DFLIP - Data flip pattern
 */
#define CAN_ERRIDPR_DFLIP(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERRIDPR_DFLIP_SHIFT)) & CAN_ERRIDPR_DFLIP_MASK)
/*! @} */

/*! @name ERRIPPR - Error Injection Parity Pattern Register */
/*! @{ */

#define CAN_ERRIPPR_PFLIP0_MASK  (0x1FU)
#define CAN_ERRIPPR_PFLIP0_SHIFT (0U)
/*! PFLIP0 - Parity Flip Pattern For Byte 0 (Least Significant)
 */
#define CAN_ERRIPPR_PFLIP0(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERRIPPR_PFLIP0_SHIFT)) & CAN_ERRIPPR_PFLIP0_MASK)

#define CAN_ERRIPPR_PFLIP1_MASK  (0x1F00U)
#define CAN_ERRIPPR_PFLIP1_SHIFT (8U)
/*! PFLIP1 - Parity Flip Pattern For Byte 1
 */
#define CAN_ERRIPPR_PFLIP1(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERRIPPR_PFLIP1_SHIFT)) & CAN_ERRIPPR_PFLIP1_MASK)

#define CAN_ERRIPPR_PFLIP2_MASK  (0x1F0000U)
#define CAN_ERRIPPR_PFLIP2_SHIFT (16U)
/*! PFLIP2 - Parity Flip Pattern For Byte 2
 */
#define CAN_ERRIPPR_PFLIP2(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERRIPPR_PFLIP2_SHIFT)) & CAN_ERRIPPR_PFLIP2_MASK)

#define CAN_ERRIPPR_PFLIP3_MASK  (0x1F000000U)
#define CAN_ERRIPPR_PFLIP3_SHIFT (24U)
/*! PFLIP3 - Parity Flip Pattern For Byte 3 (most significant)
 */
#define CAN_ERRIPPR_PFLIP3(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERRIPPR_PFLIP3_SHIFT)) & CAN_ERRIPPR_PFLIP3_MASK)
/*! @} */

/*! @name RERRAR - Error Report Address Register */
/*! @{ */

#define CAN_RERRAR_ERRADDR_MASK  (0x3FFFU)
#define CAN_RERRAR_ERRADDR_SHIFT (0U)
/*! ERRADDR - Address Where Error Detected
 */
#define CAN_RERRAR_ERRADDR(x) (((uint32_t)(((uint32_t)(x)) << CAN_RERRAR_ERRADDR_SHIFT)) & CAN_RERRAR_ERRADDR_MASK)

#define CAN_RERRAR_SAID_MASK  (0x70000U)
#define CAN_RERRAR_SAID_SHIFT (16U)
/*! SAID - SAID
 */
#define CAN_RERRAR_SAID(x) (((uint32_t)(((uint32_t)(x)) << CAN_RERRAR_SAID_SHIFT)) & CAN_RERRAR_SAID_MASK)

#define CAN_RERRAR_NCE_MASK  (0x1000000U)
#define CAN_RERRAR_NCE_SHIFT (24U)
/*! NCE - Non-Correctable Error
 *  0b0..Reporting a correctable error
 *  0b1..Reporting a non-correctable error
 */
#define CAN_RERRAR_NCE(x) (((uint32_t)(((uint32_t)(x)) << CAN_RERRAR_NCE_SHIFT)) & CAN_RERRAR_NCE_MASK)
/*! @} */

/*! @name RERRDR - Error Report Data Register */
/*! @{ */

#define CAN_RERRDR_RDATA_MASK  (0xFFFFFFFFU)
#define CAN_RERRDR_RDATA_SHIFT (0U)
/*! RDATA - Raw data word read from memory with error
 */
#define CAN_RERRDR_RDATA(x) (((uint32_t)(((uint32_t)(x)) << CAN_RERRDR_RDATA_SHIFT)) & CAN_RERRDR_RDATA_MASK)
/*! @} */

/*! @name RERRSYNR - Error Report Syndrome Register */
/*! @{ */

#define CAN_RERRSYNR_SYND0_MASK  (0x1FU)
#define CAN_RERRSYNR_SYND0_SHIFT (0U)
/*! SYND0 - Error Syndrome For Byte 0 (least significant)
 */
#define CAN_RERRSYNR_SYND0(x) (((uint32_t)(((uint32_t)(x)) << CAN_RERRSYNR_SYND0_SHIFT)) & CAN_RERRSYNR_SYND0_MASK)

#define CAN_RERRSYNR_BE0_MASK  (0x80U)
#define CAN_RERRSYNR_BE0_SHIFT (7U)
/*! BE0 - Byte Enabled For Byte 0 (least significant)
 *  0b0..The byte was not read.
 *  0b1..The byte was read.
 */
#define CAN_RERRSYNR_BE0(x) (((uint32_t)(((uint32_t)(x)) << CAN_RERRSYNR_BE0_SHIFT)) & CAN_RERRSYNR_BE0_MASK)

#define CAN_RERRSYNR_SYND1_MASK  (0x1F00U)
#define CAN_RERRSYNR_SYND1_SHIFT (8U)
/*! SYND1 - Error Syndrome for Byte 1
 */
#define CAN_RERRSYNR_SYND1(x) (((uint32_t)(((uint32_t)(x)) << CAN_RERRSYNR_SYND1_SHIFT)) & CAN_RERRSYNR_SYND1_MASK)

#define CAN_RERRSYNR_BE1_MASK  (0x8000U)
#define CAN_RERRSYNR_BE1_SHIFT (15U)
/*! BE1 - Byte Enabled For Byte 1
 *  0b0..The byte was not read.
 *  0b1..The byte was read.
 */
#define CAN_RERRSYNR_BE1(x) (((uint32_t)(((uint32_t)(x)) << CAN_RERRSYNR_BE1_SHIFT)) & CAN_RERRSYNR_BE1_MASK)

#define CAN_RERRSYNR_SYND2_MASK  (0x1F0000U)
#define CAN_RERRSYNR_SYND2_SHIFT (16U)
/*! SYND2 - Error Syndrome For Byte 2
 */
#define CAN_RERRSYNR_SYND2(x) (((uint32_t)(((uint32_t)(x)) << CAN_RERRSYNR_SYND2_SHIFT)) & CAN_RERRSYNR_SYND2_MASK)

#define CAN_RERRSYNR_BE2_MASK  (0x800000U)
#define CAN_RERRSYNR_BE2_SHIFT (23U)
/*! BE2 - Byte Enabled For Byte 2
 *  0b0..The byte was not read.
 *  0b1..The byte was read.
 */
#define CAN_RERRSYNR_BE2(x) (((uint32_t)(((uint32_t)(x)) << CAN_RERRSYNR_BE2_SHIFT)) & CAN_RERRSYNR_BE2_MASK)

#define CAN_RERRSYNR_SYND3_MASK  (0x1F000000U)
#define CAN_RERRSYNR_SYND3_SHIFT (24U)
/*! SYND3 - Error Syndrome For Byte 3 (most significant)
 */
#define CAN_RERRSYNR_SYND3(x) (((uint32_t)(((uint32_t)(x)) << CAN_RERRSYNR_SYND3_SHIFT)) & CAN_RERRSYNR_SYND3_MASK)

#define CAN_RERRSYNR_BE3_MASK  (0x80000000U)
#define CAN_RERRSYNR_BE3_SHIFT (31U)
/*! BE3 - Byte Enabled For Byte 3 (most significant)
 *  0b0..The byte was not read.
 *  0b1..The byte was read.
 */
#define CAN_RERRSYNR_BE3(x) (((uint32_t)(((uint32_t)(x)) << CAN_RERRSYNR_BE3_SHIFT)) & CAN_RERRSYNR_BE3_MASK)
/*! @} */

/*! @name ERRSR - Error Status Register */
/*! @{ */

#define CAN_ERRSR_CEIOF_MASK  (0x1U)
#define CAN_ERRSR_CEIOF_SHIFT (0U)
/*! CEIOF - Correctable Error Interrupt Overrun Flag
 *  0b0..No overrun on correctable errors
 *  0b1..Overrun on correctable errors
 */
#define CAN_ERRSR_CEIOF(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERRSR_CEIOF_SHIFT)) & CAN_ERRSR_CEIOF_MASK)

#define CAN_ERRSR_FANCEIOF_MASK  (0x4U)
#define CAN_ERRSR_FANCEIOF_SHIFT (2U)
/*! FANCEIOF - FlexCAN Access With Non-Correctable Error Interrupt Overrun Flag
 *  0b0..No overrun on non-correctable errors in FlexCAN access
 *  0b1..Overrun on non-correctable errors in FlexCAN access
 */
#define CAN_ERRSR_FANCEIOF(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERRSR_FANCEIOF_SHIFT)) & CAN_ERRSR_FANCEIOF_MASK)

#define CAN_ERRSR_HANCEIOF_MASK  (0x8U)
#define CAN_ERRSR_HANCEIOF_SHIFT (3U)
/*! HANCEIOF - Host Access With Non-Correctable Error Interrupt Overrun Flag
 *  0b0..No overrun on non-correctable errors in host access
 *  0b1..Overrun on non-correctable errors in host access
 */
#define CAN_ERRSR_HANCEIOF(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERRSR_HANCEIOF_SHIFT)) & CAN_ERRSR_HANCEIOF_MASK)

#define CAN_ERRSR_CEIF_MASK  (0x10000U)
#define CAN_ERRSR_CEIF_SHIFT (16U)
/*! CEIF - Correctable Error Interrupt Flag
 *  0b0..No correctable errors were detected so far.
 *  0b1..A correctable error was detected.
 */
#define CAN_ERRSR_CEIF(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERRSR_CEIF_SHIFT)) & CAN_ERRSR_CEIF_MASK)

#define CAN_ERRSR_FANCEIF_MASK  (0x40000U)
#define CAN_ERRSR_FANCEIF_SHIFT (18U)
/*! FANCEIF - FlexCAN Access With Non-Correctable Error Interrupt Flag
 *  0b0..No non-correctable errors were detected in FlexCAN accesses so far.
 *  0b1..A non-correctable error was detected in a FlexCAN access.
 */
#define CAN_ERRSR_FANCEIF(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERRSR_FANCEIF_SHIFT)) & CAN_ERRSR_FANCEIF_MASK)

#define CAN_ERRSR_HANCEIF_MASK  (0x80000U)
#define CAN_ERRSR_HANCEIF_SHIFT (19U)
/*! HANCEIF - Host Access With Non-Correctable Error Interrupt Flag
 *  0b0..No non-correctable errors were detected in host accesses so far.
 *  0b1..A non-correctable error was detected in a host access.
 */
#define CAN_ERRSR_HANCEIF(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERRSR_HANCEIF_SHIFT)) & CAN_ERRSR_HANCEIF_MASK)
/*! @} */

/*! @name EPRS - Enhanced CAN Bit Timing Prescalers */
/*! @{ */

#define CAN_EPRS_ENPRESDIV_MASK  (0x3FFU)
#define CAN_EPRS_ENPRESDIV_SHIFT (0U)
/*! ENPRESDIV - Extended Nominal Prescaler Division Factor
 */
#define CAN_EPRS_ENPRESDIV(x) (((uint32_t)(((uint32_t)(x)) << CAN_EPRS_ENPRESDIV_SHIFT)) & CAN_EPRS_ENPRESDIV_MASK)

#define CAN_EPRS_EDPRESDIV_MASK  (0x3FF0000U)
#define CAN_EPRS_EDPRESDIV_SHIFT (16U)
/*! EDPRESDIV - Extended Data Phase Prescaler Division Factor
 */
#define CAN_EPRS_EDPRESDIV(x) (((uint32_t)(((uint32_t)(x)) << CAN_EPRS_EDPRESDIV_SHIFT)) & CAN_EPRS_EDPRESDIV_MASK)
/*! @} */

/*! @name ENCBT - Enhanced Nominal CAN Bit Timing */
/*! @{ */

#define CAN_ENCBT_NTSEG1_MASK  (0xFFU)
#define CAN_ENCBT_NTSEG1_SHIFT (0U)
/*! NTSEG1 - Nominal Time Segment 1
 */
#define CAN_ENCBT_NTSEG1(x) (((uint32_t)(((uint32_t)(x)) << CAN_ENCBT_NTSEG1_SHIFT)) & CAN_ENCBT_NTSEG1_MASK)

#define CAN_ENCBT_NTSEG2_MASK  (0x7F000U)
#define CAN_ENCBT_NTSEG2_SHIFT (12U)
/*! NTSEG2 - Nominal Time Segment 2
 */
#define CAN_ENCBT_NTSEG2(x) (((uint32_t)(((uint32_t)(x)) << CAN_ENCBT_NTSEG2_SHIFT)) & CAN_ENCBT_NTSEG2_MASK)

#define CAN_ENCBT_NRJW_MASK  (0x1FC00000U)
#define CAN_ENCBT_NRJW_SHIFT (22U)
/*! NRJW - Nominal Resynchronization Jump Width
 */
#define CAN_ENCBT_NRJW(x) (((uint32_t)(((uint32_t)(x)) << CAN_ENCBT_NRJW_SHIFT)) & CAN_ENCBT_NRJW_MASK)
/*! @} */

/*! @name EDCBT - Enhanced Data Phase CAN bit Timing */
/*! @{ */

#define CAN_EDCBT_DTSEG1_MASK  (0x1FU)
#define CAN_EDCBT_DTSEG1_SHIFT (0U)
/*! DTSEG1 - Data Phase Segment 1
 */
#define CAN_EDCBT_DTSEG1(x) (((uint32_t)(((uint32_t)(x)) << CAN_EDCBT_DTSEG1_SHIFT)) & CAN_EDCBT_DTSEG1_MASK)

#define CAN_EDCBT_DTSEG2_MASK  (0xF000U)
#define CAN_EDCBT_DTSEG2_SHIFT (12U)
/*! DTSEG2 - Data Phase Time Segment 2
 */
#define CAN_EDCBT_DTSEG2(x) (((uint32_t)(((uint32_t)(x)) << CAN_EDCBT_DTSEG2_SHIFT)) & CAN_EDCBT_DTSEG2_MASK)

#define CAN_EDCBT_DRJW_MASK  (0x3C00000U)
#define CAN_EDCBT_DRJW_SHIFT (22U)
/*! DRJW - Data Phase Resynchronization Jump Width
 */
#define CAN_EDCBT_DRJW(x) (((uint32_t)(((uint32_t)(x)) << CAN_EDCBT_DRJW_SHIFT)) & CAN_EDCBT_DRJW_MASK)
/*! @} */

/*! @name ETDC - Enhanced Transceiver Delay Compensation */
/*! @{ */

#define CAN_ETDC_ETDCVAL_MASK  (0xFFU)
#define CAN_ETDC_ETDCVAL_SHIFT (0U)
/*! ETDCVAL - Enhanced Transceiver Delay Compensation Value
 */
#define CAN_ETDC_ETDCVAL(x) (((uint32_t)(((uint32_t)(x)) << CAN_ETDC_ETDCVAL_SHIFT)) & CAN_ETDC_ETDCVAL_MASK)

#define CAN_ETDC_ETDCFAIL_MASK  (0x8000U)
#define CAN_ETDC_ETDCFAIL_SHIFT (15U)
/*! ETDCFAIL - Transceiver Delay Compensation Fail
 *  0b0..Measured loop delay is in range.
 *  0b1..Measured loop delay is out of range.
 */
#define CAN_ETDC_ETDCFAIL(x) (((uint32_t)(((uint32_t)(x)) << CAN_ETDC_ETDCFAIL_SHIFT)) & CAN_ETDC_ETDCFAIL_MASK)

#define CAN_ETDC_ETDCOFF_MASK  (0x7F0000U)
#define CAN_ETDC_ETDCOFF_SHIFT (16U)
/*! ETDCOFF - Enhanced Transceiver Delay Compensation Offset
 */
#define CAN_ETDC_ETDCOFF(x) (((uint32_t)(((uint32_t)(x)) << CAN_ETDC_ETDCOFF_SHIFT)) & CAN_ETDC_ETDCOFF_MASK)

#define CAN_ETDC_TDMDIS_MASK  (0x40000000U)
#define CAN_ETDC_TDMDIS_SHIFT (30U)
/*! TDMDIS - Transceiver Delay Measurement Disable
 *  0b0..TDC measurement is enabled
 *  0b1..TDC measurement is disabled
 */
#define CAN_ETDC_TDMDIS(x) (((uint32_t)(((uint32_t)(x)) << CAN_ETDC_TDMDIS_SHIFT)) & CAN_ETDC_TDMDIS_MASK)

#define CAN_ETDC_ETDCEN_MASK  (0x80000000U)
#define CAN_ETDC_ETDCEN_SHIFT (31U)
/*! ETDCEN - Transceiver Delay Compensation Enable
 *  0b0..TDC is disabled
 *  0b1..TDC is enabled
 */
#define CAN_ETDC_ETDCEN(x) (((uint32_t)(((uint32_t)(x)) << CAN_ETDC_ETDCEN_SHIFT)) & CAN_ETDC_ETDCEN_MASK)
/*! @} */

/*! @name FDCTRL - CAN FD Control Register */
/*! @{ */

#define CAN_FDCTRL_TDCVAL_MASK  (0x3FU)
#define CAN_FDCTRL_TDCVAL_SHIFT (0U)
/*! TDCVAL - Transceiver Delay Compensation Value
 */
#define CAN_FDCTRL_TDCVAL(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCTRL_TDCVAL_SHIFT)) & CAN_FDCTRL_TDCVAL_MASK)

#define CAN_FDCTRL_TDCOFF_MASK  (0x1F00U)
#define CAN_FDCTRL_TDCOFF_SHIFT (8U)
/*! TDCOFF - Transceiver Delay Compensation Offset
 */
#define CAN_FDCTRL_TDCOFF(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCTRL_TDCOFF_SHIFT)) & CAN_FDCTRL_TDCOFF_MASK)

#define CAN_FDCTRL_TDCFAIL_MASK  (0x4000U)
#define CAN_FDCTRL_TDCFAIL_SHIFT (14U)
/*! TDCFAIL - Transceiver Delay Compensation Fail
 *  0b0..Measured loop delay is in range.
 *  0b1..Measured loop delay is out of range.
 */
#define CAN_FDCTRL_TDCFAIL(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCTRL_TDCFAIL_SHIFT)) & CAN_FDCTRL_TDCFAIL_MASK)

#define CAN_FDCTRL_TDCEN_MASK  (0x8000U)
#define CAN_FDCTRL_TDCEN_SHIFT (15U)
/*! TDCEN - Transceiver Delay Compensation Enable
 *  0b0..TDC is disabled
 *  0b1..TDC is enabled
 */
#define CAN_FDCTRL_TDCEN(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCTRL_TDCEN_SHIFT)) & CAN_FDCTRL_TDCEN_MASK)

#define CAN_FDCTRL_MBDSR0_MASK  (0x30000U)
#define CAN_FDCTRL_MBDSR0_SHIFT (16U)
/*! MBDSR0 - Message Buffer Data Size for Region 0
 *  0b00..Selects 8 bytes per message buffer.
 *  0b01..Selects 16 bytes per message buffer.
 *  0b10..Selects 32 bytes per message buffer.
 *  0b11..Selects 64 bytes per message buffer.
 */
#define CAN_FDCTRL_MBDSR0(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCTRL_MBDSR0_SHIFT)) & CAN_FDCTRL_MBDSR0_MASK)

#define CAN_FDCTRL_MBDSR1_MASK  (0x180000U)
#define CAN_FDCTRL_MBDSR1_SHIFT (19U)
/*! MBDSR1 - Message Buffer Data Size for Region 1
 *  0b00..Selects 8 bytes per message buffer.
 *  0b01..Selects 16 bytes per message buffer.
 *  0b10..Selects 32 bytes per message buffer.
 *  0b11..Selects 64 bytes per message buffer.
 */
#define CAN_FDCTRL_MBDSR1(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCTRL_MBDSR1_SHIFT)) & CAN_FDCTRL_MBDSR1_MASK)

#define CAN_FDCTRL_MBDSR2_MASK  (0xC00000U)
#define CAN_FDCTRL_MBDSR2_SHIFT (22U)
/*! MBDSR2 - Message Buffer Data Size for Region 2
 *  0b00..Selects 8 bytes per message buffer.
 *  0b01..Selects 16 bytes per message buffer.
 *  0b10..Selects 32 bytes per message buffer.
 *  0b11..Selects 64 bytes per message buffer.
 */
#define CAN_FDCTRL_MBDSR2(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCTRL_MBDSR2_SHIFT)) & CAN_FDCTRL_MBDSR2_MASK)

#define CAN_FDCTRL_FDRATE_MASK  (0x80000000U)
#define CAN_FDCTRL_FDRATE_SHIFT (31U)
/*! FDRATE - Bit Rate Switch Enable
 *  0b0..Transmit a frame in nominal rate. The BRS bit in the Tx MB has no effect.
 *  0b1..Transmit a frame with bit rate switching if the BRS bit in the Tx MB is recessive.
 */
#define CAN_FDCTRL_FDRATE(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCTRL_FDRATE_SHIFT)) & CAN_FDCTRL_FDRATE_MASK)
/*! @} */

/*! @name FDCBT - CAN FD Bit Timing Register */
/*! @{ */

#define CAN_FDCBT_FPSEG2_MASK  (0x7U)
#define CAN_FDCBT_FPSEG2_SHIFT (0U)
/*! FPSEG2 - Fast Phase Segment 2
 */
#define CAN_FDCBT_FPSEG2(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCBT_FPSEG2_SHIFT)) & CAN_FDCBT_FPSEG2_MASK)

#define CAN_FDCBT_FPSEG1_MASK  (0xE0U)
#define CAN_FDCBT_FPSEG1_SHIFT (5U)
/*! FPSEG1 - Fast Phase Segment 1
 */
#define CAN_FDCBT_FPSEG1(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCBT_FPSEG1_SHIFT)) & CAN_FDCBT_FPSEG1_MASK)

#define CAN_FDCBT_FPROPSEG_MASK  (0x7C00U)
#define CAN_FDCBT_FPROPSEG_SHIFT (10U)
/*! FPROPSEG - Fast Propagation Segment
 */
#define CAN_FDCBT_FPROPSEG(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCBT_FPROPSEG_SHIFT)) & CAN_FDCBT_FPROPSEG_MASK)

#define CAN_FDCBT_FRJW_MASK  (0x70000U)
#define CAN_FDCBT_FRJW_SHIFT (16U)
/*! FRJW - Fast Resync Jump Width
 */
#define CAN_FDCBT_FRJW(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCBT_FRJW_SHIFT)) & CAN_FDCBT_FRJW_MASK)

#define CAN_FDCBT_FPRESDIV_MASK  (0x3FF00000U)
#define CAN_FDCBT_FPRESDIV_SHIFT (20U)
/*! FPRESDIV - Fast Prescaler Division Factor
 */
#define CAN_FDCBT_FPRESDIV(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCBT_FPRESDIV_SHIFT)) & CAN_FDCBT_FPRESDIV_MASK)
/*! @} */

/*! @name FDCRC - CAN FD CRC Register */
/*! @{ */

#define CAN_FDCRC_FD_TXCRC_MASK  (0x1FFFFFU)
#define CAN_FDCRC_FD_TXCRC_SHIFT (0U)
/*! FD_TXCRC - Extended Transmitted CRC value
 */
#define CAN_FDCRC_FD_TXCRC(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCRC_FD_TXCRC_SHIFT)) & CAN_FDCRC_FD_TXCRC_MASK)

#define CAN_FDCRC_FD_MBCRC_MASK  (0x7F000000U)
#define CAN_FDCRC_FD_MBCRC_SHIFT (24U)
/*! FD_MBCRC - CRC Mailbox Number for FD_TXCRC
 */
#define CAN_FDCRC_FD_MBCRC(x) (((uint32_t)(((uint32_t)(x)) << CAN_FDCRC_FD_MBCRC_SHIFT)) & CAN_FDCRC_FD_MBCRC_MASK)
/*! @} */

/*! @name ERFCR - Enhanced Rx FIFO Control Register */
/*! @{ */

#define CAN_ERFCR_ERFWM_MASK  (0x1FU)
#define CAN_ERFCR_ERFWM_SHIFT (0U)
/*! ERFWM - Enhanced Rx FIFO Watermark
 */
#define CAN_ERFCR_ERFWM(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFCR_ERFWM_SHIFT)) & CAN_ERFCR_ERFWM_MASK)

#define CAN_ERFCR_NFE_MASK  (0x3F00U)
#define CAN_ERFCR_NFE_SHIFT (8U)
/*! NFE - Number of Enhanced Rx FIFO Filter Elements
 */
#define CAN_ERFCR_NFE(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFCR_NFE_SHIFT)) & CAN_ERFCR_NFE_MASK)

#define CAN_ERFCR_NEXIF_MASK  (0x7F0000U)
#define CAN_ERFCR_NEXIF_SHIFT (16U)
/*! NEXIF - Number of Extended ID Filter Elements
 */
#define CAN_ERFCR_NEXIF(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFCR_NEXIF_SHIFT)) & CAN_ERFCR_NEXIF_MASK)

#define CAN_ERFCR_DMALW_MASK  (0x7C000000U)
#define CAN_ERFCR_DMALW_SHIFT (26U)
/*! DMALW - DMA Last Word
 */
#define CAN_ERFCR_DMALW(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFCR_DMALW_SHIFT)) & CAN_ERFCR_DMALW_MASK)

#define CAN_ERFCR_ERFEN_MASK  (0x80000000U)
#define CAN_ERFCR_ERFEN_SHIFT (31U)
/*! ERFEN - Enhanced Rx FIFO enable
 *  0b0..Enhanced Rx FIFO is disabled
 *  0b1..Enhanced Rx FIFO is enabled
 */
#define CAN_ERFCR_ERFEN(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFCR_ERFEN_SHIFT)) & CAN_ERFCR_ERFEN_MASK)
/*! @} */

/*! @name ERFIER - Enhanced Rx FIFO Interrupt Enable Register */
/*! @{ */

#define CAN_ERFIER_ERFDAIE_MASK  (0x10000000U)
#define CAN_ERFIER_ERFDAIE_SHIFT (28U)
/*! ERFDAIE - Enhanced Rx FIFO Data Available Interrupt Enable
 *  0b0..Enhanced Rx FIFO Data Available interrupt is disabled
 *  0b1..Enhanced Rx FIFO Data Available interrupt is enabled
 */
#define CAN_ERFIER_ERFDAIE(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFIER_ERFDAIE_SHIFT)) & CAN_ERFIER_ERFDAIE_MASK)

#define CAN_ERFIER_ERFWMIIE_MASK  (0x20000000U)
#define CAN_ERFIER_ERFWMIIE_SHIFT (29U)
/*! ERFWMIIE - Enhanced Rx FIFO Watermark Indication Interrupt Enable
 *  0b0..Enhanced Rx FIFO Watermark interrupt is disabled
 *  0b1..Enhanced Rx FIFO Watermark interrupt is enabled
 */
#define CAN_ERFIER_ERFWMIIE(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFIER_ERFWMIIE_SHIFT)) & CAN_ERFIER_ERFWMIIE_MASK)

#define CAN_ERFIER_ERFOVFIE_MASK  (0x40000000U)
#define CAN_ERFIER_ERFOVFIE_SHIFT (30U)
/*! ERFOVFIE - Enhanced Rx FIFO Overflow Interrupt Enable
 *  0b0..Enhanced Rx FIFO Overflow is disabled
 *  0b1..Enhanced Rx FIFO Overflow is enabled
 */
#define CAN_ERFIER_ERFOVFIE(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFIER_ERFOVFIE_SHIFT)) & CAN_ERFIER_ERFOVFIE_MASK)

#define CAN_ERFIER_ERFUFWIE_MASK  (0x80000000U)
#define CAN_ERFIER_ERFUFWIE_SHIFT (31U)
/*! ERFUFWIE - Enhanced Rx FIFO Underflow Interrupt Enable
 *  0b0..Enhanced Rx FIFO Underflow interrupt is disabled
 *  0b1..Enhanced Rx FIFO Underflow interrupt is enabled
 */
#define CAN_ERFIER_ERFUFWIE(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFIER_ERFUFWIE_SHIFT)) & CAN_ERFIER_ERFUFWIE_MASK)
/*! @} */

/*! @name ERFSR - Enhanced Rx FIFO Status Register */
/*! @{ */

#define CAN_ERFSR_ERFEL_MASK  (0x3FU)
#define CAN_ERFSR_ERFEL_SHIFT (0U)
/*! ERFEL - Enhanced Rx FIFO Elements
 */
#define CAN_ERFSR_ERFEL(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFSR_ERFEL_SHIFT)) & CAN_ERFSR_ERFEL_MASK)

#define CAN_ERFSR_ERFF_MASK  (0x10000U)
#define CAN_ERFSR_ERFF_SHIFT (16U)
/*! ERFF - Enhanced Rx FIFO full
 *  0b0..Enhanced Rx FIFO is not full
 *  0b1..Enhanced Rx FIFO is full
 */
#define CAN_ERFSR_ERFF(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFSR_ERFF_SHIFT)) & CAN_ERFSR_ERFF_MASK)

#define CAN_ERFSR_ERFE_MASK  (0x20000U)
#define CAN_ERFSR_ERFE_SHIFT (17U)
/*! ERFE - Enhanced Rx FIFO empty
 *  0b0..Enhanced Rx FIFO is not empty
 *  0b1..Enhanced Rx FIFO is empty
 */
#define CAN_ERFSR_ERFE(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFSR_ERFE_SHIFT)) & CAN_ERFSR_ERFE_MASK)

#define CAN_ERFSR_ERFCLR_MASK  (0x8000000U)
#define CAN_ERFSR_ERFCLR_SHIFT (27U)
/*! ERFCLR - Enhanced Rx FIFO Clear
 *  0b0..No effect
 *  0b1..Clear Enhanced Rx FIFO content
 */
#define CAN_ERFSR_ERFCLR(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFSR_ERFCLR_SHIFT)) & CAN_ERFSR_ERFCLR_MASK)

#define CAN_ERFSR_ERFDA_MASK  (0x10000000U)
#define CAN_ERFSR_ERFDA_SHIFT (28U)
/*! ERFDA - Enhanced Rx FIFO Data Available
 *  0b0..No such occurrence
 *  0b1..There is at least one message stored in Enhanced Rx FIFO
 */
#define CAN_ERFSR_ERFDA(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFSR_ERFDA_SHIFT)) & CAN_ERFSR_ERFDA_MASK)

#define CAN_ERFSR_ERFWMI_MASK  (0x20000000U)
#define CAN_ERFSR_ERFWMI_SHIFT (29U)
/*! ERFWMI - Enhanced Rx FIFO Watermark Indication
 *  0b0..No such occurrence
 *  0b1..The number of messages in FIFO is greater than the watermark
 */
#define CAN_ERFSR_ERFWMI(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFSR_ERFWMI_SHIFT)) & CAN_ERFSR_ERFWMI_MASK)

#define CAN_ERFSR_ERFOVF_MASK  (0x40000000U)
#define CAN_ERFSR_ERFOVF_SHIFT (30U)
/*! ERFOVF - Enhanced Rx FIFO Overflow
 *  0b0..No such occurrence
 *  0b1..Enhanced Rx FIFO overflow
 */
#define CAN_ERFSR_ERFOVF(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFSR_ERFOVF_SHIFT)) & CAN_ERFSR_ERFOVF_MASK)

#define CAN_ERFSR_ERFUFW_MASK  (0x80000000U)
#define CAN_ERFSR_ERFUFW_SHIFT (31U)
/*! ERFUFW - Enhanced Rx FIFO Underflow
 *  0b0..No such occurrence
 *  0b1..Enhanced Rx FIFO underflow
 */
#define CAN_ERFSR_ERFUFW(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFSR_ERFUFW_SHIFT)) & CAN_ERFSR_ERFUFW_MASK)
/*! @} */

/*! @name HR_TIME_STAMP - High Resolution Time Stamp */
/*! @{ */

#define CAN_HR_TIME_STAMP_TS_MASK  (0xFFFFFFFFU)
#define CAN_HR_TIME_STAMP_TS_SHIFT (0U)
/*! TS - High Resolution Time Stamp
 */
#define CAN_HR_TIME_STAMP_TS(x) \
    (((uint32_t)(((uint32_t)(x)) << CAN_HR_TIME_STAMP_TS_SHIFT)) & CAN_HR_TIME_STAMP_TS_MASK)
/*! @} */

/* The count of CAN_HR_TIME_STAMP */
#define CAN_HR_TIME_STAMP_COUNT (96U)

/*! @name ERFFEL - Enhanced Rx FIFO Filter Element */
/*! @{ */

#define CAN_ERFFEL_FEL_MASK  (0xFFFFFFFFU)
#define CAN_ERFFEL_FEL_SHIFT (0U)
/*! FEL - Filter Element Bits
 */
#define CAN_ERFFEL_FEL(x) (((uint32_t)(((uint32_t)(x)) << CAN_ERFFEL_FEL_SHIFT)) & CAN_ERFFEL_FEL_MASK)
/*! @} */

/* The count of CAN_ERFFEL */
#define CAN_ERFFEL_COUNT (128U)

/* ----------------------------------------------------------------------------
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/** DMA - Register Layout Typedef */
typedef struct
{
    __IO uint32_t MP_CSR; /**< Management Page Control, offset: 0x0 */
    __I uint32_t MP_ES;   /**< Management Page Error Status, offset: 0x4 */
    __I uint32_t MP_INT;  /**< Management Page Interrupt Request Status, offset: 0x8 */
    __I uint32_t MP_HRS;  /**< Management Page Hardware Request Status, offset: 0xC */
    uint8_t RESERVED_0[240];
    __IO uint32_t CH_GRPRI[32]; /**< Channel Arbitration Group, array offset: 0x100, array step: 0x4 */
    uint8_t RESERVED_1[16000];
    struct
    {                         /* offset: 0x4000, array step: 0x10000 */
        __IO uint32_t CH_CSR; /**< Channel Control and Status, array offset: 0x10000, array step: 0x10000 */
        __IO uint32_t CH_ES;  /**< Channel Error Status, array offset: 0x10004, array step: 0x10000 */
        __IO uint32_t CH_INT; /**< Channel Interrupt Status, array offset: 0x10008, array step: 0x10000 */
        __IO uint32_t CH_SBR; /**< Channel System Bus, array offset: 0x1000C, array step: 0x10000 */
        __IO uint32_t CH_PRI; /**< Channel Priority, array offset: 0x10010, array step: 0x10000 */
        uint8_t RESERVED_0[12];
        __IO uint32_t TCD_SADDR; /**< TCD Source Address, array offset: 0x10020, array step: 0x10000 */
        __IO uint16_t TCD_SOFF;  /**< TCD Signed Source Address Offset, array offset: 0x10024, array step: 0x10000 */
        __IO uint16_t TCD_ATTR;  /**< TCD Transfer Attributes, array offset: 0x10026, array step: 0x10000 */
        union
        {                                      /* offset: 0x10028, array step: 0x10000 */
            __IO uint32_t TCD_NBYTES_MLOFFNO;  /**< TCD Transfer Size Without Minor Loop Offsets, array offset: 0x10028,
                                                  array step: 0x10000 */
            __IO uint32_t TCD_NBYTES_MLOFFYES; /**< TCD Transfer Size with Minor Loop Offsets, array offset: 0x10028,
                                                  array step: 0x10000 */
        };
        __IO uint32_t TCD_SLAST_SDA; /**< TCD Last Source Address Adjustment / Store DADDR Address, array offset:
                                        0x1002C, array step: 0x10000 */
        __IO uint32_t TCD_DADDR;     /**< TCD Destination Address, array offset: 0x10030, array step: 0x10000 */
        __IO uint16_t TCD_DOFF; /**< TCD Signed Destination Address Offset, array offset: 0x10034, array step: 0x10000 */
        union
        {                                     /* offset: 0x10036, array step: 0x10000 */
            __IO uint16_t TCD_CITER_ELINKNO;  /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled),
                                                 array offset: 0x10036, array step: 0x10000 */
            __IO uint16_t TCD_CITER_ELINKYES; /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled),
                                                 array offset: 0x10036, array step: 0x10000 */
        };
        __IO uint32_t TCD_DLAST_SGA; /**< TCD Last Destination Address Adjustment / Scatter Gather Address, array
                                        offset: 0x10038, array step: 0x10000 */
        __IO uint16_t TCD_CSR;       /**< TCD Control and Status, array offset: 0x1003C, array step: 0x10000 */
        union
        {                                     /* offset: 0x1003E, array step: 0x10000 */
            __IO uint16_t TCD_BITER_ELINKNO;  /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled),
                                                 array offset: 0x1003E, array step: 0x10000 */
            __IO uint16_t TCD_BITER_ELINKYES; /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled),
                                                 array offset: 0x1003E, array step: 0x10000 */
        };
        uint8_t RESERVED_1[16320];
    } CH[148]; /* Channels from 12 -> 127 are offset channels */
} DMA_Type;

#define DMA_MP_CSR_EDBG_MASK                eDMA_CSR_EDBG_MASK
#define DMA_MP_CSR_EDBG_SHIFT               eDMA_CSR_EDBG_SHIFT

#define DMA_MP_CSR_EDBG(x)                  eDMA_CSR_EDBG(x)

#define DMA_MP_CSR_ERCA_MASK                eDMA_CSR_ERCA_MASK
#define DMA_MP_CSR_ERCA_SHIFT               eDMA_CSR_ERCA_SHIFT
#define DMA_MP_CSR_ERCA(x)                  eDMA_CSR_ERCA(x)

#define DMA_MP_CSR_HAE_MASK                 eDMA_CSR_HAE_MASK
#define DMA_MP_CSR_HAE_SHIFT                eDMA_CSR_HAE_SHIFT
#define DMA_MP_CSR_HAE(x)                   eDMA_CSR_HAE(x)

#define DMA_MP_CSR_HALT_MASK                eDMA_CSR_HALT_MASK
#define DMA_MP_CSR_HALT_SHIFT               eDMA_CSR_HALT_SHIFT
#define DMA_MP_CSR_HALT(x)                  eDMA_CSR_HALT(x)

#define DMA_MP_CSR_GCLC_MASK                eDMA_CSR_GCLC_MASK
#define DMA_MP_CSR_GCLC_SHIFT               eDMA_CSR_GCLC_SHIFT
#define DMA_MP_CSR_GCLC(x)                  eDMA_CSR_GCLC(x)

#define DMA_MP_CSR_GMRC_MASK                eDMA_CSR_GMRC_MASK
#define DMA_MP_CSR_GMRC_SHIFT               eDMA_CSR_GMRC_SHIFT
#define DMA_MP_CSR_GMRC(x)                  eDMA_CSR_GMRC(x)

#define DMA_MP_CSR_ECX_MASK                 eDMA_CSR_ECX_MASK
#define DMA_MP_CSR_ECX_SHIFT                eDMA_CSR_ECX_SHIFT
#define DMA_MP_CSR_ECX(x)                   eDMA_CSR_ECX(x)

#define DMA_MP_CSR_CX_MASK                  eDMA_CSR_CX_MASK
#define DMA_MP_CSR_CX_SHIFT                 eDMA_CSR_CX_SHIFT
#define DMA_MP_CSR_CX(x)                    eDMA_CSR_CX(x)

#define DMA_MP_CSR_ACTIVE_ID_MASK           eDMA_CSR_ACTIVE_ID_MASK
#define DMA_MP_CSR_ACTIVE_ID_SHIFT          eDMA_CSR_ACTIVE_ID_SHIFT
#define DMA_MP_CSR_ACTIVE_ID(x)             eDMA_CSR_ACTIVE_ID(x)

#define DMA_MP_CSR_ACTIVE_MASK              eDMA_CSR_ACTIVE_MASK
#define DMA_MP_CSR_ACTIVE_SHIFT             eDMA_CSR_ACTIVE_SHIFT
#define DMA_MP_CSR_ACTIVE(x)                eDMA_CSR_ACTIVE(x)
/*! @} */

/*! @name MP_ES - Management Page Error Status */
/*! @{ */

#define DMA_MP_ES_DBE_MASK                  eDMA_ES_DBE_MASK
#define DMA_MP_ES_DBE_SHIFT                 eDMA_ES_DBE_SHIFT
#define DMA_MP_ES_DBE(x)                    eDMA_ES_DBE(x)

#define DMA_MP_ES_SBE_MASK                  eDMA_ES_SBE_MASK
#define DMA_MP_ES_SBE_SHIFT                 eDMA_ES_SBE_SHIFT
#define DMA_MP_ES_SBE(x)                    eDMA_ES_SBE(x)

#define DMA_MP_ES_SGE_MASK                  eDMA_ES_SGE_MASK
#define DMA_MP_ES_SGE_SHIFT                 eDMA_ES_SGE_SHIFT
#define DMA_MP_ES_SGE(x)                    eDMA_ES_SGE(x)

#define DMA_MP_ES_NCE_MASK                  eDMA_ES_NCE_MASK
#define DMA_MP_ES_NCE_SHIFT                 eDMA_ES_NCE_SHIFT
#define DMA_MP_ES_NCE(x)                    eDMA_ES_NCE(x)

#define DMA_MP_ES_DOE_MASK                  eDMA_ES_DOE_MASK
#define DMA_MP_ES_DOE_SHIFT                 eDMA_ES_DOE_SHIFT
#define DMA_MP_ES_DOE(x)                    eDMA_ES_DOE(x)

#define DMA_MP_ES_DAE_MASK                  eDMA_ES_DAE_MASK
#define DMA_MP_ES_DAE_SHIFT                 eDMA_ES_DAE_SHIFT
#define DMA_MP_ES_DAE(x)                    eDMA_ES_DAE(x)

#define DMA_MP_ES_SOE_MASK                  eDMA_ES_SOE_MASK
#define DMA_MP_ES_SOE_SHIFT                 eDMA_ES_SOE_SHIFT
#define DMA_MP_ES_SOE(x)                    eDMA_ES_SOE(x)

#define DMA_MP_ES_SAE_MASK                  eDMA_ES_SAE_MASK
#define DMA_MP_ES_SAE_SHIFT                 eDMA_ES_SAE_SHIFT
#define DMA_MP_ES_SAE(x)                    eDMA_ES_SAE(x)

#define DMA_MP_ES_ECX_MASK                  eDMA_ES_ECX_MASK
#define DMA_MP_ES_ECX_SHIFT                 eDMA_ES_ECX_SHIFT
#define DMA_MP_ES_ECX(x)                    eDMA_ES_ECX(x)

#define DMA_MP_ES_ERRCHN_MASK               eDMA_ES_ERRCHN_MASK
#define DMA_MP_ES_ERRCHN_SHIFT              eDMA_ES_ERRCHN_SHIFT
#define DMA_MP_ES_ERRCHN(x)                 eDMA_ES_ERRCHN(x)

#define DMA_MP_ES_VLD_MASK                  eDMA_ES_VLD_MASK
#define DMA_MP_ES_VLD_SHIFT                 eDMA_ES_VLD_SHIFT
#define DMA_MP_ES_VLD(x)                    eDMA_ES_VLD(x)

/*! @} */

/*! @name MP_INT - Management Page Interrupt Request Status */
/*! @{ */

#define DMA_MP_INT_INT_MASK                 eDMA_INT_INT_MASK
#define DMA_MP_INT_INT_SHIFT                eDMA_INT_INT_SHIFT
#define DMA_MP_INT_INT(x)                   eDMA_INT_INT(x)

/*! @} */

/*! @name MP_HRS - Management Page Hardware Request Status */
/*! @{ */

#define DMA_MP_HRS_HRS_MASK                 eDMA_HRS_HRS_MASK
#define DMA_MP_HRS_HRS_SHIFT                eDMA_HRS_HRS_SHIFT
#define DMA_MP_HRS_HRS(x)                   eDMA_HRS_HRS(x)
/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group */
/*! @{ */

#define DMA_CH_GRPRI_GRPRI_MASK             eDMA_CH_GRPRI_GRPRI_MASK
#define DMA_CH_GRPRI_GRPRI_SHIFT            eDMA_CH_GRPRI_GRPRI_SHIFT
#define DMA_CH_GRPRI_GRPRI(x)               eDMA_CH_GRPRI_GRPRI(x)
/*! @} */

/*! @name CH_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH_CSR_ERQ_MASK                 DMA_TCD_CH0_CSR_ERQ_MASK
#define DMA_CH_CSR_ERQ_SHIFT                DMA_TCD_CH0_CSR_ERQ_SHIFT
#define DMA_CH_CSR_ERQ(x)                   DMA_TCD_CH0_CSR_ERQ(x)

#define DMA_CH_CSR_EARQ_MASK                DMA_TCD_CH0_CSR_EARQ_MASK
#define DMA_CH_CSR_EARQ_SHIFT               DMA_TCD_CH0_CSR_EARQ_SHIFT
#define DMA_CH_CSR_EARQ(x)                  DMA_TCD_CH0_CSR_EARQ(x)

#define DMA_CH_CSR_EEI_MASK                 DMA_TCD_CH0_CSR_EEI_MASK
#define DMA_CH_CSR_EEI_SHIFT                DMA_TCD_CH0_CSR_EEI_SHIFT
#define DMA_CH_CSR_EEI(x)                   DMA_TCD_CH0_CSR_EEI(x)

#define DMA_CH_CSR_EBW_MASK                 DMA_TCD_CH0_CSR_EBW_MASK
#define DMA_CH_CSR_EBW_SHIFT                DMA_TCD_CH0_CSR_EBW_SHIFT
#define DMA_CH_CSR_EBW(x)                   DMA_TCD_CH0_CSR_EBW(x)

#define DMA_CH_CSR_DONE_MASK                DMA_TCD_CH0_CSR_DONE_MASK
#define DMA_CH_CSR_DONE_SHIFT               DMA_TCD_CH0_CSR_DONE_SHIFT
#define DMA_CH_CSR_DONE(x)                  DMA_TCD_CH0_CSR_DONE(x)

#define DMA_CH_CSR_ACTIVE_MASK              DMA_TCD_CH0_CSR_ACTIVE_MASK
#define DMA_CH_CSR_ACTIVE_SHIFT             DMA_TCD_CH0_CSR_ACTIVE_SHIFT
#define DMA_CH_CSR_ACTIVE(x)                DMA_TCD_CH0_CSR_ACTIVE(x)
/*! @} */

/*! @name CH_ES - Channel Error Status */
/*! @{ */

#define DMA_CH_ES_DBE_MASK                  DMA_TCD_CH0_ES_DBE_MASK
#define DMA_CH_ES_DBE_SHIFT                 DMA_TCD_CH0_ES_DBE_SHIFT
#define DMA_CH_ES_DBE(x)                    DMA_TCD_CH0_ES_DBE(x)

#define DMA_CH_ES_SBE_MASK                  DMA_TCD_CH0_ES_SBE_MASK
#define DMA_CH_ES_SBE_SHIFT                 DMA_TCD_CH0_ES_SBE_SHIFT
#define DMA_CH_ES_SBE(x)                    DMA_TCD_CH0_ES_SBE(x)

#define DMA_CH_ES_SGE_MASK                  DMA_TCD_CH0_ES_SGE_MASK
#define DMA_CH_ES_SGE_SHIFT                 DMA_TCD_CH0_ES_SGE_SHIFT
#define DMA_CH_ES_SGE(x)                    DMA_TCD_CH0_ES_SGE(x)

#define DMA_CH_ES_NCE_MASK                  DMA_TCD_CH0_ES_NCE_MASK
#define DMA_CH_ES_NCE_SHIFT                 DMA_TCD_CH0_ES_NCE_SHIFT
#define DMA_CH_ES_NCE(x)                    DMA_TCD_CH0_ES_NCE(x)

#define DMA_CH_ES_DOE_MASK                  DMA_TCD_CH0_ES_DOE_MASK
#define DMA_CH_ES_DOE_SHIFT                 DMA_TCD_CH0_ES_DOE_SHIFT
#define DMA_CH_ES_DOE(x)                    DMA_TCD_CH0_ES_DOE(x)

#define DMA_CH_ES_DAE_MASK                  DMA_TCD_CH0_ES_DAE_MASK
#define DMA_CH_ES_DAE_SHIFT                 DMA_TCD_CH0_ES_DAE_SHIFT
#define DMA_CH_ES_DAE(x)                    DMA_TCD_CH0_ES_DAE(x)

#define DMA_CH_ES_SOE_MASK                  DMA_TCD_CH0_ES_SOE_MASK
#define DMA_CH_ES_SOE_SHIFT                 DMA_TCD_CH0_ES_SOE_SHIFT
#define DMA_CH_ES_SOE(x)                    DMA_TCD_CH0_ES_SOE(x)

#define DMA_CH_ES_SAE_MASK                  DMA_TCD_CH0_ES_SAE_MASK
#define DMA_CH_ES_SAE_SHIFT                 DMA_TCD_CH0_ES_SAE_SHIFT
#define DMA_CH_ES_SAE(x)                    DMA_TCD_CH0_ES_SAE(x)

#define DMA_CH_ES_ERR_MASK                  DMA_TCD_CH0_ES_ERR_MASK
#define DMA_CH_ES_ERR_SHIFT                 DMA_TCD_CH0_ES_ERR_SHIFT
#define DMA_CH_ES_ERR(x)                    DMA_TCD_CH0_ES_ERR(x)
/*! @} */

/*! @name CH_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH_INT_INT_MASK                 DMA_TCD_CH0_INT_INT_MASK
#define DMA_CH_INT_INT_SHIFT                DMA_TCD_CH0_INT_INT_SHIFT
#define DMA_CH_INT_INT(x)                   DMA_TCD_CH0_INT_INT(x)
/*! @} */

/*! @name CH_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH_SBR_MID_MASK                 DMA_TCD_CH0_SBR_MID_MASK
#define DMA_CH_SBR_MID_SHIFT                DMA_TCD_CH0_SBR_MID_SHIFT
#define DMA_CH_SBR_MID(x)                   DMA_TCD_CH0_SBR_MID(x)

#define DMA_CH_SBR_PAL_MASK                 DMA_TCD_CH0_SBR_PAL_MASK
#define DMA_CH_SBR_PAL_SHIFT                DMA_TCD_CH0_SBR_PAL_SHIFT
#define DMA_CH_SBR_PAL(x)                   DMA_TCD_CH0_SBR_PAL(x)

#define DMA_CH_SBR_EMI_MASK                 DMA_TCD_CH0_SBR_EMI_MASK
#define DMA_CH_SBR_EMI_SHIFT                DMA_TCD_CH0_SBR_EMI_SHIFT
#define DMA_CH_SBR_EMI(x)                   DMA_TCD_CH0_SBR_EMI(x)

#define DMA_CH_SBR_ATTR_MASK                DMA_TCD_CH0_SBR_ATTR_MASK
#define DMA_CH_SBR_ATTR_SHIFT               DMA_TCD_CH0_SBR_ATTR_SHIFT
#define DMA_CH_SBR_ATTR(x)                  DMA_TCD_CH0_SBR_ATTR(x)
/*! @} */

/*! @name CH_PRI - Channel Priority */
/*! @{ */

#define DMA_CH_PRI_APL_MASK                 DMA_TCD_CH0_PRI_APL_MASK
#define DMA_CH_PRI_APL_SHIFT                DMA_TCD_CH0_PRI_APL_SHIFT
#define DMA_CH_PRI_APL(x)                   DMA_TCD_CH0_PRI_APL(x)

#define DMA_CH_PRI_DPA_MASK                 DMA_TCD_CH0_PRI_DPA_MASK
#define DMA_CH_PRI_DPA_SHIFT                DMA_TCD_CH0_PRI_DPA_SHIFT
#define DMA_CH_PRI_DPA(x)                   DMA_TCD_CH0_PRI_DPA(x)

#define DMA_CH_PRI_ECP_MASK                 DMA_TCD_CH0_PRI_ECP_MASK
#define DMA_CH_PRI_ECP_SHIFT                DMA_TCD_CH0_PRI_ECP_SHIFT
#define DMA_CH_PRI_ECP(x)                   DMA_TCD_CH0_PRI_ECP(x)
/*! @} */

/*! @name TCD_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD_SADDR_SADDR_MASK            DMA_TCD_TCD0_SADDR_SADDR_MASK
#define DMA_TCD_SADDR_SADDR_SHIFT           DMA_TCD_TCD0_SADDR_SADDR_SHIFT
#define DMA_TCD_SADDR_SADDR(x)              DMA_TCD_TCD0_SADDR_SADDR(x)
/*! @} */

/*! @name TCD_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD_SOFF_SOFF_MASK              DMA_TCD_TCD0_SOFF_SOFF_MASK
#define DMA_TCD_SOFF_SOFF_SHIFT             DMA_TCD_TCD0_SOFF_SOFF_SHIFT
#define DMA_TCD_SOFF_SOFF(x)                DMA_TCD_TCD0_SOFF_SOFF(x)
/*! @} */

/*! @name TCD_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD_ATTR_DSIZE_MASK             DMA_TCD_TCD0_ATTR_DSIZE_MASK
#define DMA_TCD_ATTR_DSIZE_SHIFT            DMA_TCD_TCD0_ATTR_DSIZE_SHIFT
#define DMA_TCD_ATTR_DSIZE(x)               DMA_TCD_TCD0_ATTR_DSIZE(x)

#define DMA_TCD_ATTR_DMOD_MASK              DMA_TCD_TCD0_ATTR_DMOD_MASK
#define DMA_TCD_ATTR_DMOD_SHIFT             DMA_TCD_TCD0_ATTR_DMOD_SHIFT
#define DMA_TCD_ATTR_DMOD(x)                DMA_TCD_TCD0_ATTR_DMOD(x)

#define DMA_TCD_ATTR_SSIZE_MASK             DMA_TCD_TCD0_ATTR_SSIZE_MASK
#define DMA_TCD_ATTR_SSIZE_SHIFT            DMA_TCD_TCD0_ATTR_SSIZE_SHIFT
#define DMA_TCD_ATTR_SSIZE(x)               DMA_TCD_TCD0_ATTR_SSIZE(x)

#define DMA_TCD_ATTR_SMOD_MASK              DMA_TCD_TCD0_ATTR_SMOD_MASK
#define DMA_TCD_ATTR_SMOD_SHIFT             DMA_TCD_TCD0_ATTR_SMOD_SHIFT
#define DMA_TCD_ATTR_SMOD(x)                DMA_TCD_TCD0_ATTR_SMOD(x)
/*! @} */

/*! @name TCD_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD_NBYTES_MLOFFNO_NBYTES_MASK  DMA_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_MASK
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT DMA_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_SHIFT
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES(x)    DMA_TCD_TCD0_NBYTES_MLOFFNO_NBYTES(x)

#define DMA_TCD_NBYTES_MLOFFNO_DMLOE_MASK   DMA_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_MASK
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT  DMA_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_SHIFT
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE(x)     DMA_TCD_TCD0_NBYTES_MLOFFNO_DMLOE(x)

#define DMA_TCD_NBYTES_MLOFFNO_SMLOE_MASK   DMA_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_MASK
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT  DMA_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_SHIFT
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE(x)     DMA_TCD_TCD0_NBYTES_MLOFFNO_SMLOE(x)
/*! @} */

/*! @name TCD_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD_NBYTES_MLOFFYES_NBYTES_MASK  DMA_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_MASK
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT DMA_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_SHIFT
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES(x)    DMA_TCD_TCD0_NBYTES_MLOFFYES_NBYTES(x)

#define DMA_TCD_NBYTES_MLOFFYES_MLOFF_MASK  DMA_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_MASK
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT DMA_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_SHIFT
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF(x)    DMA_TCD_TCD0_NBYTES_MLOFFYES_MLOFF(x)

#define DMA_TCD_NBYTES_MLOFFYES_DMLOE_MASK  DMA_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_MASK
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT DMA_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_SHIFT
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE(x)    DMA_TCD_TCD0_NBYTES_MLOFFYES_DMLOE(x)

#define DMA_TCD_NBYTES_MLOFFYES_SMLOE_MASK  DMA_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_MASK
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT DMA_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_SHIFT
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE(x)    DMA_TCD_TCD0_NBYTES_MLOFFYES_SMLOE(x)
/*! @} */

/*! @name TCD_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD_SLAST_SDA_SLAST_SDA_MASK    DMA_TCD_TCD0_SLAST_SDA_SLAST_SDA_MASK
#define DMA_TCD_SLAST_SDA_SLAST_SDA_SHIFT   DMA_TCD_TCD0_SLAST_SDA_SLAST_SDA_SHIFT
#define DMA_TCD_SLAST_SDA_SLAST_SDA(x)      DMA_TCD_TCD0_SLAST_SDA_SLAST_SDA(x)
/*! @} */

/*! @name TCD_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD_DADDR_DADDR_MASK            DMA_TCD_TCD0_DADDR_DADDR_MASK
#define DMA_TCD_DADDR_DADDR_SHIFT           DMA_TCD_TCD0_DADDR_DADDR_SHIFT
#define DMA_TCD_DADDR_DADDR(x)              DMA_TCD_TCD0_DADDR_DADDR(x)
/*! @} */

/*! @name TCD_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD_DOFF_DOFF_MASK              DMA_TCD_TCD0_DOFF_DOFF_MASK
#define DMA_TCD_DOFF_DOFF_SHIFT             DMA_TCD_TCD0_DOFF_DOFF_SHIFT
#define DMA_TCD_DOFF_DOFF(x)                DMA_TCD_TCD0_DOFF_DOFF(x)
/*! @} */

/*! @name TCD_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD_CITER_ELINKNO_CITER_MASK    DMA_TCD_TCD0_CITER_ELINKNO_CITER_MASK
#define DMA_TCD_CITER_ELINKNO_CITER_SHIFT   DMA_TCD_TCD0_CITER_ELINKNO_CITER_SHIFT
#define DMA_TCD_CITER_ELINKNO_CITER(x)      DMA_TCD_TCD0_CITER_ELINKNO_CITER(x)

#define DMA_TCD_CITER_ELINKNO_ELINK_MASK    DMA_TCD_TCD0_CITER_ELINKNO_ELINK_MASK
#define DMA_TCD_CITER_ELINKNO_ELINK_SHIFT   DMA_TCD_TCD0_CITER_ELINKNO_ELINK_SHIFT
#define DMA_TCD_CITER_ELINKNO_ELINK(x)      DMA_TCD_TCD0_CITER_ELINKNO_ELINK(x)
/*! @} */

/*! @name TCD_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD_CITER_ELINKYES_CITER_MASK  DMA_TCD_TCD0_CITER_ELINKYES_CITER_MASK
#define DMA_TCD_CITER_ELINKYES_CITER_SHIFT DMA_TCD_TCD0_CITER_ELINKYES_CITER_SHIFT
#define DMA_TCD_CITER_ELINKYES_CITER(x)    DMA_TCD_TCD0_CITER_ELINKYES_CITER(x)

#define DMA_TCD_CITER_ELINKYES_LINKCH_MASK  DMA_TCD_TCD0_CITER_ELINKYES_LINKCH_MASK
#define DMA_TCD_CITER_ELINKYES_LINKCH_SHIFT DMA_TCD_TCD0_CITER_ELINKYES_LINKCH_SHIFT
#define DMA_TCD_CITER_ELINKYES_LINKCH(x)    DMA_TCD_TCD0_CITER_ELINKYES_LINKCH(x)

#define DMA_TCD_CITER_ELINKYES_ELINK_MASK  DMA_TCD_TCD0_CITER_ELINKYES_ELINK_MASK
#define DMA_TCD_CITER_ELINKYES_ELINK_SHIFT DMA_TCD_TCD0_CITER_ELINKYES_ELINK_SHIFT
#define DMA_TCD_CITER_ELINKYES_ELINK(x)    DMA_TCD_TCD0_CITER_ELINKYES_ELINK(x)
/*! @} */

/*! @name TCD_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD_DLAST_SGA_DLAST_SGA_MASK  DMA_TCD_TCD0_DLAST_SGA_DLAST_SGA_MASK
#define DMA_TCD_DLAST_SGA_DLAST_SGA_SHIFT DMA_TCD_TCD0_DLAST_SGA_DLAST_SGA_SHIFT
#define DMA_TCD_DLAST_SGA_DLAST_SGA(x)    DMA_TCD_TCD0_DLAST_SGA_DLAST_SGA(x)
/*! @} */

/*! @name TCD_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD_CSR_START_MASK            DMA_TCD_TCD0_CSR_START_MASK
#define DMA_TCD_CSR_START_SHIFT           DMA_TCD_TCD0_CSR_START_SHIFT
#define DMA_TCD_CSR_START(x)              DMA_TCD_TCD0_CSR_START(x)

#define DMA_TCD_CSR_INTMAJOR_MASK         DMA_TCD_TCD0_CSR_INTMAJOR_MASK
#define DMA_TCD_CSR_INTMAJOR_SHIFT        DMA_TCD_TCD0_CSR_INTMAJOR_SHIFT
#define DMA_TCD_CSR_INTMAJOR(x)           DMA_TCD_TCD0_CSR_INTMAJOR(x)

#define DMA_TCD_CSR_INTHALF_MASK          DMA_TCD_TCD0_CSR_INTHALF_MASK
#define DMA_TCD_CSR_INTHALF_SHIFT         DMA_TCD_TCD0_CSR_INTHALF_SHIFT
#define DMA_TCD_CSR_INTHALF(x)            DMA_TCD_TCD0_CSR_INTHALF(x)

#define DMA_TCD_CSR_DREQ_MASK             DMA_TCD_TCD0_CSR_DREQ_MASK
#define DMA_TCD_CSR_DREQ_SHIFT            DMA_TCD_TCD0_CSR_DREQ_SHIFT
#define DMA_TCD_CSR_DREQ(x)               DMA_TCD_TCD0_CSR_DREQ(x)

#define DMA_TCD_CSR_ESG_MASK              DMA_TCD_TCD0_CSR_ESG_MASK
#define DMA_TCD_CSR_ESG_SHIFT             DMA_TCD_TCD0_CSR_ESG_SHIFT
#define DMA_TCD_CSR_ESG(x)                DMA_TCD_TCD0_CSR_ESG(x)

#define DMA_TCD_CSR_MAJORELINK_MASK       DMA_TCD_TCD0_CSR_MAJORELINK_MASK
#define DMA_TCD_CSR_MAJORELINK_SHIFT      DMA_TCD_TCD0_CSR_MAJORELINK_SHIFT
#define DMA_TCD_CSR_MAJORELINK(x)         DMA_TCD_TCD0_CSR_MAJORELINK(x)

#define DMA_TCD_CSR_EEOP_MASK             DMA_TCD_TCD0_CSR_EEOP_MASK
#define DMA_TCD_CSR_EEOP_SHIFT            DMA_TCD_TCD0_CSR_EEOP_SHIFT
#define DMA_TCD_CSR_EEOP(x)               DMA_TCD_TCD0_CSR_EEOP(x)

#define DMA_TCD_CSR_ESDA_MASK             DMA_TCD_TCD0_CSR_ESDA_MASK
#define DMA_TCD_CSR_ESDA_SHIFT            DMA_TCD_TCD0_CSR_ESDA_SHIFT
#define DMA_TCD_CSR_ESDA(x)               DMA_TCD_TCD0_CSR_ESDA(x)

#define DMA_TCD_CSR_MAJORLINKCH_MASK      DMA_TCD_TCD0_CSR_MAJORLINKCH_MASK
#define DMA_TCD_CSR_MAJORLINKCH_SHIFT     DMA_TCD_TCD0_CSR_MAJORLINKCH_SHIFT
#define DMA_TCD_CSR_MAJORLINKCH(x)        DMA_TCD_TCD0_CSR_MAJORLINKCH(x)

#define DMA_TCD_CSR_BWC_MASK              DMA_TCD_TCD0_CSR_BWC_MASK
#define DMA_TCD_CSR_BWC_SHIFT             DMA_TCD_TCD0_CSR_BWC_SHIFT
#define DMA_TCD_CSR_BWC(x)                DMA_TCD_TCD0_CSR_BWC(x)
/*! @} */

/*! @name TCD_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD_BITER_ELINKNO_BITER_MASK  DMA_TCD_TCD0_BITER_ELINKNO_BITER_MASK
#define DMA_TCD_BITER_ELINKNO_BITER_SHIFT DMA_TCD_TCD0_BITER_ELINKNO_BITER_SHIFT
#define DMA_TCD_BITER_ELINKNO_BITER(x)    DMA_TCD_TCD0_BITER_ELINKNO_BITER(x)

#define DMA_TCD_BITER_ELINKNO_ELINK_MASK  DMA_TCD_TCD0_BITER_ELINKNO_ELINK_MASK
#define DMA_TCD_BITER_ELINKNO_ELINK_SHIFT DMA_TCD_TCD0_BITER_ELINKNO_ELINK_SHIFT
#define DMA_TCD_BITER_ELINKNO_ELINK(x)    DMA_TCD_TCD0_BITER_ELINKNO_ELINK(x)
/*! @} */

/*! @name TCD_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD_BITER_ELINKYES_BITER_MASK  DMA_TCD_TCD0_BITER_ELINKYES_BITER_MASK
#define DMA_TCD_BITER_ELINKYES_BITER_SHIFT DMA_TCD_TCD0_BITER_ELINKYES_BITER_SHIFT
#define DMA_TCD_BITER_ELINKYES_BITER(x)    DMA_TCD_TCD0_BITER_ELINKYES_BITER(x)

#define DMA_TCD_BITER_ELINKYES_LINKCH_MASK  DMA_TCD_TCD0_BITER_ELINKYES_LINKCH_MASK
#define DMA_TCD_BITER_ELINKYES_LINKCH_SHIFT DMA_TCD_TCD0_BITER_ELINKYES_LINKCH_SHIFT
#define DMA_TCD_BITER_ELINKYES_LINKCH(x)    DMA_TCD_TCD0_BITER_ELINKYES_LINKCH(x)

#define DMA_TCD_BITER_ELINKYES_ELINK_MASK   DMA_TCD_TCD0_BITER_ELINKYES_ELINK_MASK
#define DMA_TCD_BITER_ELINKYES_ELINK_SHIFT  DMA_TCD_TCD0_BITER_ELINKYES_ELINK_SHIFT
#define DMA_TCD_BITER_ELINKYES_ELINK(x)     DMA_TCD_TCD0_BITER_ELINKYES_ELINK(x)
/*! @} */

#endif /* _S32K344_DEVICE_H_ */
