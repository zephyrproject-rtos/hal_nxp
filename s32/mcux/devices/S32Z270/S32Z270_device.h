/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _S32Z270_DEVICE_H_
#define _S32Z270_DEVICE_H_

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
        uint8_t RESERVED_2[20];
        __IO uint32_t IMASK4;               /**< Interrupt Masks 4, offset: 0x68 */
        __IO uint32_t IMASK3;               /**< Interrupt Masks 3, offset: 0x6C */
        __IO uint32_t IFLAG4;               /**< Interrupt Flags 4, offset: 0x70 */
        __IO uint32_t IFLAG3;               /**< Interrupt Flags 3, offset: 0x74 */
        uint8_t RESERVED_3[8];
        struct
        {                                   /* offset: 0x80, array step: 0x10 */
            __IO uint32_t CS;               /**< Message Buffer 0 CS Register..Message Buffer 127 CS Register, array offset: 0x80, array step: 0x10 */
            __IO uint32_t ID;               /**< Message Buffer 0 ID Register..Message Buffer 127 ID Register, array offset: 0x84, array step: 0x10 */
            __IO uint32_t WORD0;            /**< Message Buffer 0 WORD0 Register..Message Buffer 127 WORD0 Register, array offset: 0x88, array step: 0x10 */
            __IO uint32_t WORD1;            /**< Message Buffer 0 WORD1 Register..Message Buffer 127 WORD1 Register, array offset: 0x8C, array step: 0x10 */
        } MB[128];
        __IO uint32_t RXIMR[128];            /**< Rx Individual Mask Registers, array offset: 0x880, array step: 0x4 */
        uint8_t RESERVED_4[96];
        __IO uint32_t MECR;                 /**< Memory Error Control Register, offset: 0xAE0 */
        __IO uint32_t ERRIAR;               /**< Error Injection Address Register, offset: 0xAE4 */
        __IO uint32_t ERRIDPR;              /**< Error Injection Data Pattern Register, offset: 0xAE8 */
        __IO uint32_t ERRIPPR;              /**< Error Injection Parity Pattern Register, offset: 0xAEC */
        __I  uint32_t RERRAR;               /**< Error Report Address Register, offset: 0xAF0 */
        __I  uint32_t RERRDR;               /**< Error Report Data Register, offset: 0xAF4 */
        __I  uint32_t RERRSYNR;             /**< Error Report Syndrome Register, offset: 0xAF8 */
        __IO uint32_t ERRSR;                /**< Error Status Register, offset: 0xAFC */
        uint8_t RESERVED_5[240];
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
        uint8_t RESERVED_6[24];
        __IO uint32_t HR_TIME_STAMP[128];    /**< High Resolution Time Stamp, array offset: 0xC30, array step: 0x4 */
        uint8_t RESERVED_7[8656];
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

#define CAN_MCR_MAXMB_MASK  FLEXCAN_MCR_MAXMB_MASK
#define CAN_MCR_MAXMB_SHIFT FLEXCAN_MCR_MAXMB_SHIFT

#define CAN_MCR_MAXMB(x)   FLEXCAN_MCR_MAXMB(x)

#define CAN_MCR_IDAM_MASK  FLEXCAN_MCR_IDAM_MASK
#define CAN_MCR_IDAM_SHIFT FLEXCAN_MCR_IDAM_SHIFT

#define CAN_MCR_IDAM(x) FLEXCAN_MCR_IDAM(x)

#define CAN_MCR_FDEN_MASK  FLEXCAN_MCR_FDEN_MASK
#define CAN_MCR_FDEN_SHIFT FLEXCAN_MCR_FDEN_SHIFT

#define CAN_MCR_FDEN(x) FLEXCAN_MCR_FDEN(x)

#define CAN_MCR_AEN_MASK  FLEXCAN_MCR_AEN_MASK
#define CAN_MCR_AEN_SHIFT FLEXCAN_MCR_AEN_SHIFT

#define CAN_MCR_AEN(x) FLEXCAN_MCR_AEN(x)

#define CAN_MCR_LPRIOEN_MASK  FLEXCAN_MCR_LPRIOEN_MASK
#define CAN_MCR_LPRIOEN_SHIFT FLEXCAN_MCR_LPRIOEN_SHIFT

#define CAN_MCR_LPRIOEN(x) FLEXCAN_MCR_LPRIOEN(x)

#define CAN_MCR_DMA_MASK  FLEXCAN_MCR_DMA_MASK
#define CAN_MCR_DMA_SHIFT FLEXCAN_MCR_DMA_SHIFT

#define CAN_MCR_DMA(x) FLEXCAN_MCR_DMA(x)

#define CAN_MCR_IRMQ_MASK  FLEXCAN_MCR_IRMQ_MASK
#define CAN_MCR_IRMQ_SHIFT FLEXCAN_MCR_IRMQ_SHIFT

#define CAN_MCR_IRMQ(x) FLEXCAN_MCR_IRMQ(x)

#define CAN_MCR_SRXDIS_MASK  FLEXCAN_MCR_SRXDIS_MASK
#define CAN_MCR_SRXDIS_SHIFT FLEXCAN_MCR_SRXDIS_SHIFT

#define CAN_MCR_SRXDIS(x) FLEXCAN_MCR_SRXDIS(x)

#define CAN_MCR_LPMACK_MASK  FLEXCAN_MCR_LPMACK_MASK
#define CAN_MCR_LPMACK_SHIFT FLEXCAN_MCR_LPMACK_SHIFT

#define CAN_MCR_LPMACK(x) FLEXCAN_MCR_LPMACK(x)

#define CAN_MCR_WRNEN_MASK  FLEXCAN_MCR_WRNEN_MASK
#define CAN_MCR_WRNEN_SHIFT FLEXCAN_MCR_WRNEN_SHIFT

#define CAN_MCR_WRNEN(x) FLEXCAN_MCR_WRNEN(x)

#define CAN_MCR_FRZACK_MASK  FLEXCAN_MCR_FRZACK_MASK
#define CAN_MCR_FRZACK_SHIFT FLEXCAN_MCR_FRZACK_SHIFT

#define CAN_MCR_FRZACK(x) FLEXCAN_MCR_FRZACK(x)

#define CAN_MCR_SOFTRST_MASK  FLEXCAN_MCR_SOFTRST_MASK
#define CAN_MCR_SOFTRST_SHIFT FLEXCAN_MCR_SOFTRST_SHIFT

#define CAN_MCR_SOFTRST(x) FLEXCAN_MCR_SOFTRST(x)

#define CAN_MCR_NOTRDY_MASK  FLEXCAN_MCR_NOTRDY_MASK
#define CAN_MCR_NOTRDY_SHIFT FLEXCAN_MCR_NOTRDY_SHIFT

#define CAN_MCR_NOTRDY(x) FLEXCAN_MCR_NOTRDY(x)

#define CAN_MCR_HALT_MASK  FLEXCAN_MCR_HALT_MASK
#define CAN_MCR_HALT_SHIFT FLEXCAN_MCR_HALT_SHIFT

#define CAN_MCR_HALT(x) FLEXCAN_MCR_HALT(x)

#define CAN_MCR_RFEN_MASK  FLEXCAN_MCR_RFEN_MASK
#define CAN_MCR_RFEN_SHIFT FLEXCAN_MCR_RFEN_SHIFT

#define CAN_MCR_RFEN(x) FLEXCAN_MCR_RFEN(x)

#define CAN_MCR_FRZ_MASK  FLEXCAN_MCR_FRZ_MASK
#define CAN_MCR_FRZ_SHIFT FLEXCAN_MCR_FRZ_SHIFT

#define CAN_MCR_FRZ(x) FLEXCAN_MCR_FRZ(x)

#define CAN_MCR_MDIS_MASK  FLEXCAN_MCR_MDIS_MASK
#define CAN_MCR_MDIS_SHIFT FLEXCAN_MCR_MDIS_SHIFT

#define CAN_MCR_MDIS(x) FLEXCAN_MCR_MDIS(x)
/*! @} */

/*! @name CTRL1 - Control 1 Register */
/*! @{ */

#define CAN_CTRL1_PROPSEG_MASK  FLEXCAN_CTRL1_PROPSEG_MASK
#define CAN_CTRL1_PROPSEG_SHIFT FLEXCAN_CTRL1_PROPSEG_SHIFT

#define CAN_CTRL1_PROPSEG(x) FLEXCAN_CTRL1_PROPSEG(x)

#define CAN_CTRL1_LOM_MASK  FLEXCAN_CTRL1_LOM_MASK
#define CAN_CTRL1_LOM_SHIFT FLEXCAN_CTRL1_LOM_SHIFT

#define CAN_CTRL1_LOM(x) FLEXCAN_CTRL1_LOM(x)

#define CAN_CTRL1_LBUF_MASK  FLEXCAN_CTRL1_LBUF_MASK
#define CAN_CTRL1_LBUF_SHIFT FLEXCAN_CTRL1_LBUF_SHIFT

#define CAN_CTRL1_LBUF(x) FLEXCAN_CTRL1_LBUF(x)

#define CAN_CTRL1_TSYN_MASK  FLEXCAN_CTRL1_TSYN_MASK
#define CAN_CTRL1_TSYN_SHIFT FLEXCAN_CTRL1_TSYN_SHIFT

#define CAN_CTRL1_TSYN(x) FLEXCAN_CTRL1_TSYN(x)

#define CAN_CTRL1_BOFFREC_MASK  FLEXCAN_CTRL1_BOFFREC_MASK
#define CAN_CTRL1_BOFFREC_SHIFT FLEXCAN_CTRL1_BOFFREC_SHIFT

#define CAN_CTRL1_BOFFREC(x) FLEXCAN_CTRL1_BOFFREC(x)

#define CAN_CTRL1_SMP_MASK  FLEXCAN_CTRL1_SMP_MASK
#define CAN_CTRL1_SMP_SHIFT FLEXCAN_CTRL1_SMP_SHIFT

#define CAN_CTRL1_SMP(x) FLEXCAN_CTRL1_SMP(x)

#define CAN_CTRL1_RWRNMSK_MASK  FLEXCAN_CTRL1_RWRNMSK_MASK
#define CAN_CTRL1_RWRNMSK_SHIFT FLEXCAN_CTRL1_RWRNMSK_SHIFT

#define CAN_CTRL1_RWRNMSK(x) FLEXCAN_CTRL1_RWRNMSK(x)

#define CAN_CTRL1_TWRNMSK_MASK  FLEXCAN_CTRL1_TWRNMSK_MASK
#define CAN_CTRL1_TWRNMSK_SHIFT FLEXCAN_CTRL1_TWRNMSK_SHIFT

#define CAN_CTRL1_TWRNMSK(x) FLEXCAN_CTRL1_TWRNMSK(x)

#define CAN_CTRL1_LPB_MASK  FLEXCAN_CTRL1_LPB_MASK
#define CAN_CTRL1_LPB_SHIFT FLEXCAN_CTRL1_LPB_SHIFT

#define CAN_CTRL1_LPB(x) FLEXCAN_CTRL1_LPB(x)

#define CAN_CTRL1_ERRMSK_MASK  FLEXCAN_CTRL1_ERRMSK_MASK
#define CAN_CTRL1_ERRMSK_SHIFT FLEXCAN_CTRL1_ERRMSK_SHIFT

#define CAN_CTRL1_ERRMSK(x) FLEXCAN_CTRL1_ERRMSK(x)

#define CAN_CTRL1_BOFFMSK_MASK  FLEXCAN_CTRL1_BOFFMSK_MASK
#define CAN_CTRL1_BOFFMSK_SHIFT FLEXCAN_CTRL1_BOFFMSK_SHIFT

#define CAN_CTRL1_BOFFMSK(x) FLEXCAN_CTRL1_BOFFMSK(x)

#define CAN_CTRL1_PSEG2_MASK  FLEXCAN_CTRL1_PSEG2_MASK
#define CAN_CTRL1_PSEG2_SHIFT FLEXCAN_CTRL1_PSEG2_SHIFT

#define CAN_CTRL1_PSEG2(x) FLEXCAN_CTRL1_PSEG2(x)

#define CAN_CTRL1_PSEG1_MASK  FLEXCAN_CTRL1_PSEG1_MASK
#define CAN_CTRL1_PSEG1_SHIFT FLEXCAN_CTRL1_PSEG1_SHIFT

#define CAN_CTRL1_PSEG1(x) FLEXCAN_CTRL1_PSEG1(x)

#define CAN_CTRL1_RJW_MASK  FLEXCAN_CTRL1_RJW_MASK
#define CAN_CTRL1_RJW_SHIFT FLEXCAN_CTRL1_RJW_SHIFT

#define CAN_CTRL1_RJW(x) FLEXCAN_CTRL1_RJW(x)

#define CAN_CTRL1_PRESDIV_MASK  FLEXCAN_CTRL1_PRESDIV_MASK
#define CAN_CTRL1_PRESDIV_SHIFT FLEXCAN_CTRL1_PRESDIV_SHIFT

#define CAN_CTRL1_PRESDIV(x) FLEXCAN_CTRL1_PRESDIV(x)
/*! @} */

/*! @name TIMER - Free Running Timer */
/*! @{ */

#define CAN_TIMER_TIMER_MASK  FLEXCAN_TIMER_TIMER_MASK
#define CAN_TIMER_TIMER_SHIFT FLEXCAN_TIMER_TIMER_SHIFT

#define CAN_TIMER_TIMER(x) FLEXCAN_TIMER_TIMER(x)
/*! @} */

/*! @name RXMGMASK - Rx Mailboxes Global Mask Register */
/*! @{ */

#define CAN_RXMGMASK_MG_MASK  FLEXCAN_RXMGMASK_MG_MASK
#define CAN_RXMGMASK_MG_SHIFT FLEXCAN_RXMGMASK_MG_SHIFT

#define CAN_RXMGMASK_MG(x) FLEXCAN_RXMGMASK_MG(x)
/*! @} */

/*! @name RX14MASK - Rx 14 Mask Register */
/*! @{ */

#define CAN_RX14MASK_RX14M_MASK  FLEXCAN_RX14MASK_RX14M_MASK
#define CAN_RX14MASK_RX14M_SHIFT FLEXCAN_RX14MASK_RX14M_SHIFT

#define CAN_RX14MASK_RX14M(x) FLEXCAN_RX14MASK_RX14M(x)
/*! @} */

/*! @name RX15MASK - Rx 15 Mask Register */
/*! @{ */

#define CAN_RX15MASK_RX15M_MASK  FLEXCAN_RX15MASK_RX15M_MASK
#define CAN_RX15MASK_RX15M_SHIFT FLEXCAN_RX15MASK_RX15M_SHIFT

#define CAN_RX15MASK_RX15M(x) FLEXCAN_RX15MASK_RX15M(x)
/*! @} */

/*! @name ECR - Error Counter */
/*! @{ */

#define CAN_ECR_TXERRCNT_MASK  FLEXCAN_ECR_TXERRCNT_MASK
#define CAN_ECR_TXERRCNT_SHIFT FLEXCAN_ECR_TXERRCNT_SHIFT

#define CAN_ECR_TXERRCNT(x) FLEXCAN_ECR_TXERRCNT(x)

#define CAN_ECR_RXERRCNT_MASK  FLEXCAN_ECR_RXERRCNT_MASK
#define CAN_ECR_RXERRCNT_SHIFT FLEXCAN_ECR_RXERRCNT_SHIFT

#define CAN_ECR_RXERRCNT(x) FLEXCAN_ECR_RXERRCNT(x)

#define CAN_ECR_TXERRCNT_FAST_MASK  FLEXCAN_ECR_TXERRCNT_FAST_MASK
#define CAN_ECR_TXERRCNT_FAST_SHIFT FLEXCAN_ECR_TXERRCNT_FAST_SHIFT

#define CAN_ECR_TXERRCNT_FAST(x) FLEXCAN_ECR_TXERRCNT_FAST(x)

#define CAN_ECR_RXERRCNT_FAST_MASK  FLEXCAN_ECR_RXERRCNT_FAST_MASK
#define CAN_ECR_RXERRCNT_FAST_SHIFT FLEXCAN_ECR_RXERRCNT_FAST_SHIFT

#define CAN_ECR_RXERRCNT_FAST(x) FLEXCAN_ECR_RXERRCNT_FAST(x)
/*! @} */

/*! @name ESR1 - Error and Status 1 Register */
/*! @{ */

#define CAN_ESR1_ERRINT_MASK  FLEXCAN_ESR1_ERRINT_MASK
#define CAN_ESR1_ERRINT_SHIFT FLEXCAN_ESR1_ERRINT_SHIFT

#define CAN_ESR1_ERRINT(x) FLEXCAN_ESR1_ERRINT(x)

#define CAN_ESR1_BOFFINT_MASK  FLEXCAN_ESR1_BOFFINT_MASK
#define CAN_ESR1_BOFFINT_SHIFT FLEXCAN_ESR1_BOFFINT_SHIFT

#define CAN_ESR1_BOFFINT(x) FLEXCAN_ESR1_BOFFINT(x)

#define CAN_ESR1_RX_MASK  FLEXCAN_ESR1_RX_MASK
#define CAN_ESR1_RX_SHIFT FLEXCAN_ESR1_RX_SHIFT

#define CAN_ESR1_RX(x) FLEXCAN_ESR1_RX(x)

#define CAN_ESR1_FLTCONF_MASK  FLEXCAN_ESR1_FLTCONF_MASK
#define CAN_ESR1_FLTCONF_SHIFT FLEXCAN_ESR1_FLTCONF_SHIFT

#define CAN_ESR1_FLTCONF(x) FLEXCAN_ESR1_FLTCONF(x)

#define CAN_ESR1_TX_MASK  FLEXCAN_ESR1_TX_MASK
#define CAN_ESR1_TX_SHIFT FLEXCAN_ESR1_TX_SHIFT

#define CAN_ESR1_TX(x) FLEXCAN_ESR1_TX(x)

#define CAN_ESR1_IDLE_MASK  FLEXCAN_ESR1_IDLE_MASK
#define CAN_ESR1_IDLE_SHIFT FLEXCAN_ESR1_IDLE_SHIFT

#define CAN_ESR1_IDLE(x) FLEXCAN_ESR1_IDLE(x)

#define CAN_ESR1_RXWRN_MASK  FLEXCAN_ESR1_RXWRN_MASK
#define CAN_ESR1_RXWRN_SHIFT FLEXCAN_ESR1_RXWRN_SHIFT

#define CAN_ESR1_RXWRN(x) FLEXCAN_ESR1_RXWRN(x)

#define CAN_ESR1_TXWRN_MASK  FLEXCAN_ESR1_TXWRN_MASK
#define CAN_ESR1_TXWRN_SHIFT FLEXCAN_ESR1_TXWRN_SHIFT

#define CAN_ESR1_TXWRN(x) FLEXCAN_ESR1_TXWRN(x)

#define CAN_ESR1_STFERR_MASK  FLEXCAN_ESR1_STFERR_MASK
#define CAN_ESR1_STFERR_SHIFT FLEXCAN_ESR1_STFERR_SHIFT

#define CAN_ESR1_STFERR(x) FLEXCAN_ESR1_STFERR(x)

#define CAN_ESR1_FRMERR_MASK  FLEXCAN_ESR1_FRMERR_MASK
#define CAN_ESR1_FRMERR_SHIFT FLEXCAN_ESR1_FRMERR_SHIFT

#define CAN_ESR1_FRMERR(x) FLEXCAN_ESR1_FRMERR(x)

#define CAN_ESR1_CRCERR_MASK  FLEXCAN_ESR1_CRCERR_MASK
#define CAN_ESR1_CRCERR_SHIFT FLEXCAN_ESR1_CRCERR_SHIFT

#define CAN_ESR1_CRCERR(x) FLEXCAN_ESR1_CRCERR(x)

#define CAN_ESR1_ACKERR_MASK  FLEXCAN_ESR1_ACKERR_MASK
#define CAN_ESR1_ACKERR_SHIFT FLEXCAN_ESR1_ACKERR_SHIFT

#define CAN_ESR1_ACKERR(x) FLEXCAN_ESR1_ACKERR(x)

#define CAN_ESR1_BIT0ERR_MASK  FLEXCAN_ESR1_BIT0ERR_MASK
#define CAN_ESR1_BIT0ERR_SHIFT FLEXCAN_ESR1_BIT0ERR_SHIFT

#define CAN_ESR1_BIT0ERR(x) FLEXCAN_ESR1_BIT0ERR(x)

#define CAN_ESR1_BIT1ERR_MASK  FLEXCAN_ESR1_BIT1ERR_MASK
#define CAN_ESR1_BIT1ERR_SHIFT FLEXCAN_ESR1_BIT1ERR_SHIFT

#define CAN_ESR1_BIT1ERR(x) FLEXCAN_ESR1_BIT1ERR(x)

#define CAN_ESR1_RWRNINT_MASK  FLEXCAN_ESR1_RWRNINT_MASK
#define CAN_ESR1_RWRNINT_SHIFT FLEXCAN_ESR1_RWRNINT_SHIFT

#define CAN_ESR1_RWRNINT(x) FLEXCAN_ESR1_RWRNINT(x)

#define CAN_ESR1_TWRNINT_MASK  FLEXCAN_ESR1_TWRNINT_MASK
#define CAN_ESR1_TWRNINT_SHIFT FLEXCAN_ESR1_TWRNINT_SHIFT

#define CAN_ESR1_TWRNINT(x) FLEXCAN_ESR1_TWRNINT(x)

#define CAN_ESR1_SYNCH_MASK  FLEXCAN_ESR1_SYNCH_MASK
#define CAN_ESR1_SYNCH_SHIFT FLEXCAN_ESR1_SYNCH_SHIFT

#define CAN_ESR1_SYNCH(x) FLEXCAN_ESR1_SYNCH(x)

#define CAN_ESR1_BOFFDONEINT_MASK  FLEXCAN_ESR1_BOFFDONEINT_MASK
#define CAN_ESR1_BOFFDONEINT_SHIFT FLEXCAN_ESR1_BOFFDONEINT_SHIFT

#define CAN_ESR1_BOFFDONEINT(x) FLEXCAN_ESR1_BOFFDONEINT(x)

#define CAN_ESR1_ERRINT_FAST_MASK  FLEXCAN_ESR1_ERRINT_FAST_MASK
#define CAN_ESR1_ERRINT_FAST_SHIFT FLEXCAN_ESR1_ERRINT_FAST_SHIFT

#define CAN_ESR1_ERRINT_FAST(x) FLEXCAN_ESR1_ERRINT_FAST(x)

#define CAN_ESR1_ERROVR_MASK  FLEXCAN_ESR1_ERROVR_MASK
#define CAN_ESR1_ERROVR_SHIFT FLEXCAN_ESR1_ERROVR_SHIFT

#define CAN_ESR1_ERROVR(x) FLEXCAN_ESR1_ERROVR(x)

#define CAN_ESR1_STFERR_FAST_MASK  FLEXCAN_ESR1_STFERR_FAST_MASK
#define CAN_ESR1_STFERR_FAST_SHIFT FLEXCAN_ESR1_STFERR_FAST_SHIFT

#define CAN_ESR1_STFERR_FAST(x) FLEXCAN_ESR1_STFERR_FAST(x)

#define CAN_ESR1_FRMERR_FAST_MASK  FLEXCAN_ESR1_FRMERR_FAST_MASK
#define CAN_ESR1_FRMERR_FAST_SHIFT FLEXCAN_ESR1_FRMERR_FAST_SHIFT

#define CAN_ESR1_FRMERR_FAST(x) FLEXCAN_ESR1_FRMERR_FAST(x)

#define CAN_ESR1_CRCERR_FAST_MASK  FLEXCAN_ESR1_CRCERR_FAST_MASK
#define CAN_ESR1_CRCERR_FAST_SHIFT FLEXCAN_ESR1_CRCERR_FAST_SHIFT

#define CAN_ESR1_CRCERR_FAST(x) FLEXCAN_ESR1_CRCERR_FAST(x)

#define CAN_ESR1_BIT0ERR_FAST_MASK  FLEXCAN_ESR1_BIT0ERR_FAST_MASK
#define CAN_ESR1_BIT0ERR_FAST_SHIFT FLEXCAN_ESR1_BIT0ERR_FAST_SHIFT

#define CAN_ESR1_BIT0ERR_FAST(x) FLEXCAN_ESR1_BIT0ERR_FAST(x)

#define CAN_ESR1_BIT1ERR_FAST_MASK  FLEXCAN_ESR1_BIT1ERR_FAST_MASK
#define CAN_ESR1_BIT1ERR_FAST_SHIFT FLEXCAN_ESR1_BIT1ERR_FAST_SHIFT

#define CAN_ESR1_BIT1ERR_FAST(x) FLEXCAN_ESR1_BIT1ERR_FAST(x)
/*! @} */

/*! @name IMASK2 - Interrupt Masks 2 Register */
/*! @{ */

#define CAN_IMASK2_BUF63TO32M_MASK  FLEXCAN_IMASK2_BUF63TO32M_MASK
#define CAN_IMASK2_BUF63TO32M_SHIFT FLEXCAN_IMASK2_BUF63TO32M_SHIFT

#define CAN_IMASK2_BUF63TO32M(x) FLEXCAN_IMASK2_BUF63TO32M(x)
/*! @} */

/*! @name IMASK1 - Interrupt Masks 1 Register */
/*! @{ */

#define CAN_IMASK1_BUF31TO0M_MASK  FLEXCAN_IMASK1_BUF31TO0M_MASK
#define CAN_IMASK1_BUF31TO0M_SHIFT FLEXCAN_IMASK1_BUF31TO0M_SHIFT

#define CAN_IMASK1_BUF31TO0M(x) FLEXCAN_IMASK1_BUF31TO0M(x)
/*! @} */

/*! @name IFLAG2 - Interrupt Flags 2 Register */
/*! @{ */

#define CAN_IFLAG2_BUF63TO32I_MASK  FLEXCAN_IFLAG2_BUF63TO32I_MASK
#define CAN_IFLAG2_BUF63TO32I_SHIFT FLEXCAN_IFLAG2_BUF63TO32I_SHIFT

#define CAN_IFLAG2_BUF63TO32I(x) FLEXCAN_IFLAG2_BUF63TO32I(x)
/*! @} */

/*! @name IFLAG1 - Interrupt Flags 1 Register */
/*! @{ */

#define CAN_IFLAG1_BUF0I_MASK  FLEXCAN_IFLAG1_BUF0I_MASK
#define CAN_IFLAG1_BUF0I_SHIFT FLEXCAN_IFLAG1_BUF0I_SHIFT

#define CAN_IFLAG1_BUF0I(x) FLEXCAN_IFLAG1_BUF0I(x)

#define CAN_IFLAG1_BUF4TO1I_MASK  FLEXCAN_IFLAG1_BUF4TO1I_MASK
#define CAN_IFLAG1_BUF4TO1I_SHIFT FLEXCAN_IFLAG1_BUF4TO1I_SHIFT

#define CAN_IFLAG1_BUF4TO1I(x) FLEXCAN_IFLAG1_BUF4TO1I(x)

#define CAN_IFLAG1_BUF5I_MASK  FLEXCAN_IFLAG1_BUF4TO1I_MASK
#define CAN_IFLAG1_BUF5I_SHIFT FLEXCAN_IFLAG1_BUF4TO1I_SHIFT

#define CAN_IFLAG1_BUF5I(x) FLEXCAN_IFLAG1_BUF5I(x)

#define CAN_IFLAG1_BUF6I_MASK  FLEXCAN_IFLAG1_BUF5I_MASK
#define CAN_IFLAG1_BUF6I_SHIFT FLEXCAN_IFLAG1_BUF5I_SHIFT

#define CAN_IFLAG1_BUF6I(x) FLEXCAN_IFLAG1_BUF6I(x)

#define CAN_IFLAG1_BUF7I_MASK  FLEXCAN_IFLAG1_BUF6I_MASK
#define CAN_IFLAG1_BUF7I_SHIFT FLEXCAN_IFLAG1_BUF6I_SHIFT

#define CAN_IFLAG1_BUF7I(x) FLEXCAN_IFLAG1_BUF7I(x)

#define CAN_IFLAG1_BUF31TO8I_MASK  FLEXCAN_IFLAG1_BUF31TO8I_MASK
#define CAN_IFLAG1_BUF31TO8I_SHIFT FLEXCAN_IFLAG1_BUF31TO8I_SHIFT

#define CAN_IFLAG1_BUF31TO8I(x) FLEXCAN_IFLAG1_BUF31TO8I(x)
/*! @} */

/*! @name CTRL2 - Control 2 Register */
/*! @{ */

#define CAN_CTRL2_TSTAMPCAP_MASK  FLEXCAN_CTRL2_TSTAMPCAP_MASK
#define CAN_CTRL2_TSTAMPCAP_SHIFT FLEXCAN_CTRL2_TSTAMPCAP_SHIFT

#define CAN_CTRL2_TSTAMPCAP(x) FLEXCAN_CTRL2_TSTAMPCAP(x)

#define CAN_CTRL2_MBTSBASE_MASK  FLEXCAN_CTRL2_MBTSBASE_MASK
#define CAN_CTRL2_MBTSBASE_SHIFT FLEXCAN_CTRL2_MBTSBASE_SHIFT

#define CAN_CTRL2_MBTSBASE(x) FLEXCAN_CTRL2_MBTSBASE(x)

#define CAN_CTRL2_EDFLTDIS_MASK  FLEXCAN_CTRL2_EDFLTDIS_MASK
#define CAN_CTRL2_EDFLTDIS_SHIFT FLEXCAN_CTRL2_EDFLTDIS_SHIFT

#define CAN_CTRL2_EDFLTDIS(x) FLEXCAN_CTRL2_EDFLTDIS(x)

#define CAN_CTRL2_ISOCANFDEN_MASK  FLEXCAN_CTRL2_ISOCANFDEN_MASK
#define CAN_CTRL2_ISOCANFDEN_SHIFT FLEXCAN_CTRL2_ISOCANFDEN_SHIFT

#define CAN_CTRL2_ISOCANFDEN(x) FLEXCAN_CTRL2_ISOCANFDEN(x)

#define CAN_CTRL2_BTE_MASK  FLEXCAN_CTRL2_BTE_MASK
#define CAN_CTRL2_BTE_SHIFT FLEXCAN_CTRL2_BTE_SHIFT

#define CAN_CTRL2_BTE(x) FLEXCAN_CTRL2_BTE(x)

#define CAN_CTRL2_PREXCEN_MASK  FLEXCAN_CTRL2_PREXCEN_MASK
#define CAN_CTRL2_PREXCEN_SHIFT FLEXCAN_CTRL2_PREXCEN_SHIFT

#define CAN_CTRL2_PREXCEN(x) FLEXCAN_CTRL2_PREXCEN(x)

#define CAN_CTRL2_TIMER_SRC_MASK  FLEXCAN_CTRL2_TIMER_SRC_MASK
#define CAN_CTRL2_TIMER_SRC_SHIFT FLEXCAN_CTRL2_TIMER_SRC_SHIFT

#define CAN_CTRL2_TIMER_SRC(x) FLEXCAN_CTRL2_TIMER_SRC(x)

#define CAN_CTRL2_EACEN_MASK  FLEXCAN_CTRL2_EACEN_MASK
#define CAN_CTRL2_EACEN_SHIFT FLEXCAN_CTRL2_EACEN_SHIFT

#define CAN_CTRL2_EACEN(x) FLEXCAN_CTRL2_EACEN(x)

#define CAN_CTRL2_RRS_MASK  FLEXCAN_CTRL2_RRS_MASK
#define CAN_CTRL2_RRS_SHIFT FLEXCAN_CTRL2_RRS_SHIFT

#define CAN_CTRL2_RRS(x) FLEXCAN_CTRL2_RRS(x)

#define CAN_CTRL2_MRP_MASK  FLEXCAN_CTRL2_MRP_MASK
#define CAN_CTRL2_MRP_SHIFT FLEXCAN_CTRL2_MRP_SHIFT

#define CAN_CTRL2_MRP(x) FLEXCAN_CTRL2_MRP(x)

#define CAN_CTRL2_TASD_MASK  FLEXCAN_CTRL2_TASD_MASK
#define CAN_CTRL2_TASD_SHIFT FLEXCAN_CTRL2_TASD_SHIFT

#define CAN_CTRL2_TASD(x) FLEXCAN_CTRL2_TASD(x)

#define CAN_CTRL2_RFFN_MASK  FLEXCAN_CTRL2_RFFN_MASK
#define CAN_CTRL2_RFFN_SHIFT FLEXCAN_CTRL2_RFFN_SHIFT

#define CAN_CTRL2_RFFN(x) FLEXCAN_CTRL2_RFFN(x)

#define CAN_CTRL2_WRMFRZ_MASK  FLEXCAN_CTRL2_WRMFRZ_MASK
#define CAN_CTRL2_WRMFRZ_SHIFT FLEXCAN_CTRL2_WRMFRZ_SHIFT

#define CAN_CTRL2_WRMFRZ(x) FLEXCAN_CTRL2_WRMFRZ(x)

#define CAN_CTRL2_ECRWRE_MASK  FLEXCAN_CTRL2_ECRWRE_MASK
#define CAN_CTRL2_ECRWRE_SHIFT FLEXCAN_CTRL2_ECRWRE_SHIFT

#define CAN_CTRL2_ECRWRE(x) FLEXCAN_CTRL2_ECRWRE(x)

#define CAN_CTRL2_BOFFDONEMSK_MASK  FLEXCAN_CTRL2_BOFFDONEMSK_MASK
#define CAN_CTRL2_BOFFDONEMSK_SHIFT FLEXCAN_CTRL2_BOFFDONEMSK_SHIFT

#define CAN_CTRL2_BOFFDONEMSK(x) FLEXCAN_CTRL2_BOFFDONEMSK(x)

#define CAN_CTRL2_ERRMSK_FAST_MASK  FLEXCAN_CTRL2_ERRMSK_FAST_MASK
#define CAN_CTRL2_ERRMSK_FAST_SHIFT FLEXCAN_CTRL2_ERRMSK_FAST_SHIFT

#define CAN_CTRL2_ERRMSK_FAST(x) FLEXCAN_CTRL2_ERRMSK_FAST(x)
/*! @} */

/*! @name ESR2 - Error and Status 2 Register */
/*! @{ */

#define CAN_ESR2_IMB_MASK  FLEXCAN_ESR2_IMB_MASK
#define CAN_ESR2_IMB_SHIFT FLEXCAN_ESR2_IMB_SHIFT

#define CAN_ESR2_IMB(x) FLEXCAN_ESR2_IMB(x)

#define CAN_ESR2_VPS_MASK  FLEXCAN_ESR2_VPS_MASK
#define CAN_ESR2_VPS_SHIFT FLEXCAN_ESR2_VPS_SHIFT

#define CAN_ESR2_VPS(x) FLEXCAN_ESR2_VPS(x)

#define CAN_ESR2_LPTM_MASK  FLEXCAN_ESR2_LPTM_MASK
#define CAN_ESR2_LPTM_SHIFT FLEXCAN_ESR2_LPTM_SHIFT
/*! LPTM - Lowest Priority Tx Mailbox
 */
#define CAN_ESR2_LPTM(x) FLEXCAN_ESR2_LPTM(x)
/*! @} */

/*! @name CRCR - CRC Register */
/*! @{ */

#define CAN_CRCR_TXCRC_MASK  FLEXCAN_CRCR_TXCRC_MASK
#define CAN_CRCR_TXCRC_SHIFT FLEXCAN_CRCR_TXCRC_SHIFT

#define CAN_CRCR_TXCRC(x) FLEXCAN_CRCR_TXCRC(x)

#define CAN_CRCR_MBCRC_MASK  FLEXCAN_CRCR_MBCRC_MASK
#define CAN_CRCR_MBCRC_SHIFT FLEXCAN_CRCR_MBCRC_SHIFT

#define CAN_CRCR_MBCRC(x) FLEXCAN_CRCR_MBCRC(x)
/*! @} */

/*! @name RXFGMASK - Legacy Rx FIFO Global Mask Register */
/*! @{ */

#define CAN_RXFGMASK_FGM_MASK  FLEXCAN_RXFGMASK_FGM_MASK
#define CAN_RXFGMASK_FGM_SHIFT FLEXCAN_RXFGMASK_FGM_SHIFT

#define CAN_RXFGMASK_FGM(x) FLEXCAN_RXFGMASK_FGM(x)
/*! @} */

/*! @name RXFIR - Legacy Rx FIFO Information Register */
/*! @{ */

#define CAN_RXFIR_IDHIT_MASK  FLEXCAN_RXFIR_IDHIT_MASK
#define CAN_RXFIR_IDHIT_SHIFT FLEXCAN_RXFIR_IDHIT_SHIFT

#define CAN_RXFIR_IDHIT(x) FLEXCAN_RXFIR_IDHIT(x)
/*! @} */

/*! @name CBT - CAN Bit Timing Register */
/*! @{ */

#define CAN_CBT_EPSEG2_MASK  FLEXCAN_CBT_EPSEG2_MASK
#define CAN_CBT_EPSEG2_SHIFT FLEXCAN_CBT_EPSEG2_SHIFT

#define CAN_CBT_EPSEG2(x) FLEXCAN_CBT_EPSEG2(x)

#define CAN_CBT_EPSEG1_MASK  FLEXCAN_CBT_EPSEG1_MASK
#define CAN_CBT_EPSEG1_SHIFT FLEXCAN_CBT_EPSEG1_SHIFT

#define CAN_CBT_EPSEG1(x) FLEXCAN_CBT_EPSEG1(x)

#define CAN_CBT_EPROPSEG_MASK  FLEXCAN_CBT_EPROPSEG_MASK
#define CAN_CBT_EPROPSEG_SHIFT FLEXCAN_CBT_EPROPSEG_SHIFT

#define CAN_CBT_EPROPSEG(x) FLEXCAN_CBT_EPROPSEG(x)

#define CAN_CBT_ERJW_MASK  FLEXCAN_CBT_ERJW_MASK
#define CAN_CBT_ERJW_SHIFT FLEXCAN_CBT_ERJW_SHIFT

#define CAN_CBT_ERJW(x) FLEXCAN_CBT_ERJW(x)

#define CAN_CBT_EPRESDIV_MASK  FLEXCAN_CBT_EPRESDIV_MASK
#define CAN_CBT_EPRESDIV_SHIFT FLEXCAN_CBT_EPRESDIV_SHIFT

#define CAN_CBT_EPRESDIV(x) FLEXCAN_CBT_EPRESDIV(x)

#define CAN_CBT_BTF_MASK  FLEXCAN_CBT_BTF_MASK
#define CAN_CBT_BTF_SHIFT FLEXCAN_CBT_BTF_SHIFT

#define CAN_CBT_BTF(x) FLEXCAN_CBT_BTF(x)
/*! @} */

/*! @name IMASK3 - Interrupt Masks 3 Register */
/*! @{ */

#define CAN_IMASK3_BUF95TO64M_MASK  FLEXCAN_IMASK3_BUF95TO64M_MASK
#define CAN_IMASK3_BUF95TO64M_SHIFT FLEXCAN_IMASK3_BUF95TO64M_SHIFT

#define CAN_IMASK3_BUF95TO64M(x) FLEXCAN_IMASK3_BUF95TO64M(x)
/*! @} */

/*! @name IFLAG3 - Interrupt Flags 3 Register */
/*! @{ */

#define CAN_IFLAG3_BUF95TO64_MASK  FLEXCAN_IFLAG3_BUF95TO64_MASK
#define CAN_IFLAG3_BUF95TO64_SHIFT FLEXCAN_IFLAG3_BUF95TO64_SHIFT

/*! @name IMASK4 - Interrupt Masks 4 Register */
/*! @{ */

#define CAN_IMASK4_BUF127TO96M_MASK  FLEXCAN_IMASK4_BUF127TO96M_MASK
#define CAN_IMASK4_BUF127TO96M_SHIFT FLEXCAN_IMASK4_BUF127TO96M_SHIFT

#define CAN_IMASK4_BUF127TO96M(x) FLEXCAN_IMASK4_BUF127TO96M(x)
/*! @} */

/*! @name IFLAG4 - Interrupt Flags 4 Register */
/*! @{ */

#define CAN_IFLAG4_BUF127TO96_MASK  FLEXCAN_IFLAG4_BUF127TO96_MASK
#define CAN_IFLAG4_BUF127TO96_SHIFT FLEXCAN_IFLAG4_BUF127TO96_SHIFT

#define CAN_IFLAG4_BUF127TO96M(x) FLEXCAN_IFLAG4_BUF127TO96M(x)
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

#define CAN_RXIMR_MI_MASK  FLEXCAN_RXIMR_MI_MASK
#define CAN_RXIMR_MI_SHIFT FLEXCAN_RXIMR_MI_SHIFT

#define CAN_RXIMR_MI(x) FLEXCAN_RXIMR_MI(x)

/* The count of CAN_RXIMR */
#define CAN_RXIMR_COUNT (128U)

/*! @name MECR - Memory Error Control Register */
/*! @{ */

#define CAN_MECR_NCEFAFRZ_MASK  FLEXCAN_MECR_NCEFAFRZ_MASK
#define CAN_MECR_NCEFAFRZ_SHIFT FLEXCAN_MECR_NCEFAFRZ_SHIFT

#define CAN_MECR_NCEFAFRZ(x) FLEXCAN_MECR_NCEFAFRZ(x)

#define CAN_MECR_ECCDIS_MASK  FLEXCAN_MECR_ECCDIS_MASK
#define CAN_MECR_ECCDIS_SHIFT FLEXCAN_MECR_ECCDIS_SHIFT

#define CAN_MECR_ECCDIS(x) FLEXCAN_MECR_ECCDIS(x)

#define CAN_MECR_RERRDIS_MASK  FLEXCAN_MECR_RERRDIS_MASK
#define CAN_MECR_RERRDIS_SHIFT FLEXCAN_MECR_RERRDIS_SHIFT

#define CAN_MECR_RERRDIS(x) FLEXCAN_MECR_RERRDIS(x)

#define CAN_MECR_EXTERRIE_MASK  FLEXCAN_MECR_EXTERRIE_MASK
#define CAN_MECR_EXTERRIE_SHIFT FLEXCAN_MECR_EXTERRIE_SHIFT

#define CAN_MECR_EXTERRIE(x) FLEXCAN_MECR_EXTERRIE(x)

#define CAN_MECR_FAERRIE_MASK  FLEXCAN_MECR_FAERRIE_MASK
#define CAN_MECR_FAERRIE_SHIFT FLEXCAN_MECR_FAERRIE_SHIFT

#define CAN_MECR_FAERRIE(x) FLEXCAN_MECR_FAERRIE(x)

#define CAN_MECR_HAERRIE_MASK  FLEXCAN_MECR_HAERRIE_MASK
#define CAN_MECR_HAERRIE_SHIFT FLEXCAN_MECR_HAERRIE_SHIFT

#define CAN_MECR_HAERRIE(x) FLEXCAN_MECR_HAERRIE(x)

#define CAN_MECR_ECRWRDIS_MASK  FLEXCAN_MECR_ECRWRDIS_MASK
#define CAN_MECR_ECRWRDIS_SHIFT FLEXCAN_MECR_ECRWRDIS_SHIFT

#define CAN_MECR_ECRWRDIS(x) FLEXCAN_MECR_ECRWRDIS(x)
/*! @} */

/*! @name ERRIAR - Error Injection Address Register */
/*! @{ */

#define CAN_ERRIAR_INJADDR_L_MASK  FLEXCAN_ERRIAR_INJADDR_L_MASK
#define CAN_ERRIAR_INJADDR_L_SHIFT FLEXCAN_ERRIAR_INJADDR_L_SHIFT

#define CAN_ERRIAR_INJADDR_L(x) FLEXCAN_ERRIAR_INJADDR_L(x)

#define CAN_ERRIAR_INJADDR_H_MASK  FLEXCAN_ERRIAR_INJADDR_H_MASK
#define CAN_ERRIAR_INJADDR_H_SHIFT FLEXCAN_ERRIAR_INJADDR_H_SHIFT

#define CAN_ERRIAR_INJADDR_H(x) FLEXCAN_ERRIAR_INJADDR_H(x)
/*! @} */

/*! @name ERRIDPR - Error Injection Data Pattern Register */
/*! @{ */

#define CAN_ERRIDPR_DFLIP_MASK  FLEXCAN_ERRIDPR_DFLIP_MASK
#define CAN_ERRIDPR_DFLIP_SHIFT FLEXCAN_ERRIDPR_DFLIP_SHIFT

#define CAN_ERRIDPR_DFLIP(x) FLEXCAN_ERRIDPR_DFLIP(x)
/*! @} */

/*! @name ERRIPPR - Error Injection Parity Pattern Register */
/*! @{ */

#define CAN_ERRIPPR_PFLIP0_MASK  FLEXCAN_ERRIPPR_PFLIP0_MASK
#define CAN_ERRIPPR_PFLIP0_SHIFT FLEXCAN_ERRIPPR_PFLIP0_SHIFT

#define CAN_ERRIPPR_PFLIP0(x) FLEXCAN_ERRIPPR_PFLIP0(x)

#define CAN_ERRIPPR_PFLIP1_MASK  FLEXCAN_ERRIPPR_PFLIP1_MASK
#define CAN_ERRIPPR_PFLIP1_SHIFT FLEXCAN_ERRIPPR_PFLIP1_SHIFT

#define CAN_ERRIPPR_PFLIP1(x) FLEXCAN_ERRIPPR_PFLIP1(x)

#define CAN_ERRIPPR_PFLIP2_MASK  FLEXCAN_ERRIPPR_PFLIP2_MASK
#define CAN_ERRIPPR_PFLIP2_SHIFT FLEXCAN_ERRIPPR_PFLIP2_SHIFT

#define CAN_ERRIPPR_PFLIP2(x) FLEXCAN_ERRIPPR_PFLIP2(x)

#define CAN_ERRIPPR_PFLIP3_MASK  FLEXCAN_ERRIPPR_PFLIP3_MASK
#define CAN_ERRIPPR_PFLIP3_SHIFT FLEXCAN_ERRIPPR_PFLIP3_SHIFT

#define CAN_ERRIPPR_PFLIP3(x) FLEXCAN_ERRIPPR_PFLIP3(x)
/*! @} */

/*! @name RERRAR - Error Report Address Register */
/*! @{ */

#define CAN_RERRAR_ERRADDR_MASK  FLEXCAN_RERRAR_ERRADDR_MASK
#define CAN_RERRAR_ERRADDR_SHIFT FLEXCAN_RERRAR_ERRADDR_SHIFT

#define CAN_RERRAR_ERRADDR(x) FLEXCAN_RERRAR_ERRADDR(x)

#define CAN_RERRAR_SAID_MASK  FLEXCAN_RERRAR_SAID_MASK
#define CAN_RERRAR_SAID_SHIFT FLEXCAN_RERRAR_SAID_SHIFT

#define CAN_RERRAR_SAID(x) FLEXCAN_RERRAR_SAID(x)

#define CAN_RERRAR_NCE_MASK  FLEXCAN_RERRAR_NCE_MASK
#define CAN_RERRAR_NCE_SHIFT FLEXCAN_RERRAR_NCE_SHIFT

#define CAN_RERRAR_NCE(x) FLEXCAN_RERRAR_NCE(x)
/*! @} */

/*! @name RERRDR - Error Report Data Register */
/*! @{ */

#define CAN_RERRDR_RDATA_MASK  FLEXCAN_RERRDR_RDATA_MASK
#define CAN_RERRDR_RDATA_SHIFT FLEXCAN_RERRDR_RDATA_SHIFT

#define CAN_RERRDR_RDATA(x) FLEXCAN_RERRDR_RDATA(x)
/*! @} */

/*! @name RERRSYNR - Error Report Syndrome Register */
/*! @{ */

#define CAN_RERRSYNR_SYND0_MASK  FLEXCAN_RERRSYNR_SYND0_MASK
#define CAN_RERRSYNR_SYND0_SHIFT FLEXCAN_RERRSYNR_SYND0_SHIFT

#define CAN_RERRSYNR_SYND0(x) FLEXCAN_RERRSYNR_SYND0(x)

#define CAN_RERRSYNR_BE0_MASK  FLEXCAN_RERRSYNR_BE0_MASK
#define CAN_RERRSYNR_BE0_SHIFT FLEXCAN_RERRSYNR_BE0_SHIFT

#define CAN_RERRSYNR_BE0(x) FLEXCAN_RERRSYNR_BE0(x)

#define CAN_RERRSYNR_SYND1_MASK  FLEXCAN_RERRSYNR_SYND1_MASK
#define CAN_RERRSYNR_SYND1_SHIFT FLEXCAN_RERRSYNR_SYND1_SHIFT

#define CAN_RERRSYNR_SYND1(x) FLEXCAN_RERRSYNR_SYND1(x)

#define CAN_RERRSYNR_BE1_MASK  FLEXCAN_RERRSYNR_BE1_MASK
#define CAN_RERRSYNR_BE1_SHIFT FLEXCAN_RERRSYNR_BE1_SHIFT

#define CAN_RERRSYNR_BE1(x) FLEXCAN_RERRSYNR_BE1(x)

#define CAN_RERRSYNR_SYND2_MASK  FLEXCAN_RERRSYNR_SYND2_MASK
#define CAN_RERRSYNR_SYND2_SHIFT FLEXCAN_RERRSYNR_SYND2_SHIFT

#define CAN_RERRSYNR_SYND2(x) FLEXCAN_RERRSYNR_SYND2(x)

#define CAN_RERRSYNR_BE2_MASK  FLEXCAN_RERRSYNR_BE2_MASK
#define CAN_RERRSYNR_BE2_SHIFT FLEXCAN_RERRSYNR_BE2_SHIFT

#define CAN_RERRSYNR_BE2(x) FLEXCAN_RERRSYNR_BE2(x)

#define CAN_RERRSYNR_SYND3_MASK  FLEXCAN_RERRSYNR_SYND3_MASK
#define CAN_RERRSYNR_SYND3_SHIFT FLEXCAN_RERRSYNR_SYND3_SHIFT

#define CAN_RERRSYNR_SYND3(x) FLEXCAN_RERRSYNR_SYND3(x)

#define CAN_RERRSYNR_BE3_MASK  FLEXCAN_RERRSYNR_BE3_MASK
#define CAN_RERRSYNR_BE3_SHIFT FLEXCAN_RERRSYNR_BE3_SHIFT

#define CAN_RERRSYNR_BE3(x) FLEXCAN_RERRSYNR_BE3(x)
/*! @} */

/*! @name ERRSR - Error Status Register */
/*! @{ */

#define CAN_ERRSR_CEIOF_MASK  FLEXCAN_ERRSR_CEIOF_MASK
#define CAN_ERRSR_CEIOF_SHIFT FLEXCAN_ERRSR_CEIOF_SHIFT

#define CAN_ERRSR_CEIOF(x) FLEXCAN_ERRSR_CEIOF(x)

#define CAN_ERRSR_FANCEIOF_MASK  FLEXCAN_ERRSR_FANCEIOF_MASK
#define CAN_ERRSR_FANCEIOF_SHIFT FLEXCAN_ERRSR_FANCEIOF_SHIFT

#define CAN_ERRSR_FANCEIOF(x) FLEXCAN_ERRSR_FANCEIOF(x)

#define CAN_ERRSR_HANCEIOF_MASK  FLEXCAN_ERRSR_HANCEIOF_MASK
#define CAN_ERRSR_HANCEIOF_SHIFT FLEXCAN_ERRSR_HANCEIOF_SHIFT

#define CAN_ERRSR_HANCEIOF(x) FLEXCAN_ERRSR_HANCEIOF(x)

#define CAN_ERRSR_CEIF_MASK  FLEXCAN_ERRSR_CEIF_MASK
#define CAN_ERRSR_CEIF_SHIFT FLEXCAN_ERRSR_CEIF_SHIFT

#define CAN_ERRSR_CEIF(x) FLEXCAN_ERRSR_CEIF(x)

#define CAN_ERRSR_FANCEIF_MASK  FLEXCAN_ERRSR_FANCEIF_MASK
#define CAN_ERRSR_FANCEIF_SHIFT FLEXCAN_ERRSR_FANCEIF_SHIFT

#define CAN_ERRSR_FANCEIF(x) FLEXCAN_ERRSR_FANCEIF(x)

#define CAN_ERRSR_HANCEIF_MASK  FLEXCAN_ERRSR_HANCEIF_MASK
#define CAN_ERRSR_HANCEIF_SHIFT FLEXCAN_ERRSR_HANCEIF_SHIFT

#define CAN_ERRSR_HANCEIF(x) FLEXCAN_ERRSR_HANCEIF(x)
/*! @} */

/*! @name EPRS - Enhanced CAN Bit Timing Prescalers */
/*! @{ */

#define CAN_EPRS_ENPRESDIV_MASK  FLEXCAN_EPRS_ENPRESDIV_MASK
#define CAN_EPRS_ENPRESDIV_SHIFT FLEXCAN_EPRS_ENPRESDIV_SHIFT

#define CAN_EPRS_ENPRESDIV(x) FLEXCAN_EPRS_ENPRESDIV(x)

#define CAN_EPRS_EDPRESDIV_MASK  FLEXCAN_EPRS_EDPRESDIV_MASK
#define CAN_EPRS_EDPRESDIV_SHIFT FLEXCAN_EPRS_EDPRESDIV_SHIFT

#define CAN_EPRS_EDPRESDIV(x) FLEXCAN_EPRS_EDPRESDIV(x)
/*! @} */

/*! @name ENCBT - Enhanced Nominal CAN Bit Timing */
/*! @{ */

#define CAN_ENCBT_NTSEG1_MASK  FLEXCAN_ENCBT_NTSEG1_MASK
#define CAN_ENCBT_NTSEG1_SHIFT FLEXCAN_ENCBT_NTSEG1_SHIFT

#define CAN_ENCBT_NTSEG1(x) FLEXCAN_ENCBT_NTSEG1(x)

#define CAN_ENCBT_NTSEG2_MASK  FLEXCAN_ENCBT_NTSEG2_MASK
#define CAN_ENCBT_NTSEG2_SHIFT FLEXCAN_ENCBT_NTSEG2_SHIFT

#define CAN_ENCBT_NTSEG2(x) FLEXCAN_ENCBT_NTSEG2(x)

#define CAN_ENCBT_NRJW_MASK  FLEXCAN_ENCBT_NRJW_MASK
#define CAN_ENCBT_NRJW_SHIFT FLEXCAN_ENCBT_NRJW_SHIFT

#define CAN_ENCBT_NRJW(x) FLEXCAN_ENCBT_NRJW(x)
/*! @} */

/*! @name EDCBT - Enhanced Data Phase CAN bit Timing */
/*! @{ */

#define CAN_EDCBT_DTSEG1_MASK  FLEXCAN_EDCBT_DTSEG1_MASK
#define CAN_EDCBT_DTSEG1_SHIFT FLEXCAN_EDCBT_DTSEG1_SHIFT

#define CAN_EDCBT_DTSEG1(x) FLEXCAN_EDCBT_DTSEG1(x)

#define CAN_EDCBT_DTSEG2_MASK  FLEXCAN_EDCBT_DTSEG2_MASK
#define CAN_EDCBT_DTSEG2_SHIFT FLEXCAN_EDCBT_DTSEG2_SHIFT

#define CAN_EDCBT_DTSEG2(x) FLEXCAN_EDCBT_DTSEG2(x)

#define CAN_EDCBT_DRJW_MASK  FLEXCAN_EDCBT_DRJW_MASK
#define CAN_EDCBT_DRJW_SHIFT FLEXCAN_EDCBT_DRJW_SHIFT

#define CAN_EDCBT_DRJW(x) FLEXCAN_EDCBT_DRJW(x)
/*! @} */

/*! @name ETDC - Enhanced Transceiver Delay Compensation */
/*! @{ */

#define CAN_ETDC_ETDCVAL_MASK  FLEXCAN_ETDC_ETDCVAL_MASK
#define CAN_ETDC_ETDCVAL_SHIFT FLEXCAN_ETDC_ETDCVAL_SHIFT

#define CAN_ETDC_ETDCVAL(x) FLEXCAN_ETDC_ETDCVAL(x)

#define CAN_ETDC_ETDCFAIL_MASK  FLEXCAN_ETDC_ETDCFAIL_MASK
#define CAN_ETDC_ETDCFAIL_SHIFT FLEXCAN_ETDC_ETDCFAIL_SHIFT

#define CAN_ETDC_ETDCFAIL(x) FLEXCAN_ETDC_ETDCFAIL(x)

#define CAN_ETDC_ETDCOFF_MASK  FLEXCAN_ETDC_ETDCOFF_MASK
#define CAN_ETDC_ETDCOFF_SHIFT FLEXCAN_ETDC_ETDCOFF_SHIFT

#define CAN_ETDC_ETDCOFF(x) FLEXCAN_ETDC_ETDCOFF(x)

#define CAN_ETDC_TDMDIS_MASK  FLEXCAN_ETDC_TDMDIS_MASK
#define CAN_ETDC_TDMDIS_SHIFT FLEXCAN_ETDC_TDMDIS_SHIFT

#define CAN_ETDC_TDMDIS(x) FLEXCAN_ETDC_TDMDIS(x)

#define CAN_ETDC_ETDCEN_MASK  FLEXCAN_ETDC_ETDCEN_MASK
#define CAN_ETDC_ETDCEN_SHIFT FLEXCAN_ETDC_ETDCEN_SHIFT

#define CAN_ETDC_ETDCEN(x) FLEXCAN_ETDC_ETDCEN(x)
/*! @} */

/*! @name FDCTRL - CAN FD Control Register */
/*! @{ */

#define CAN_FDCTRL_TDCVAL_MASK  FLEXCAN_FDCTRL_TDCVAL_MASK
#define CAN_FDCTRL_TDCVAL_SHIFT FLEXCAN_FDCTRL_TDCVAL_SHIFT

#define CAN_FDCTRL_TDCVAL(x) FLEXCAN_FDCTRL_TDCVAL(x)

#define CAN_FDCTRL_TDCOFF_MASK  FLEXCAN_FDCTRL_TDCOFF_MASK
#define CAN_FDCTRL_TDCOFF_SHIFT FLEXCAN_FDCTRL_TDCOFF_SHIFT

#define CAN_FDCTRL_TDCOFF(x) FLEXCAN_FDCTRL_TDCOFF(x)

#define CAN_FDCTRL_TDCFAIL_MASK  FLEXCAN_FDCTRL_TDCFAIL_MASK
#define CAN_FDCTRL_TDCFAIL_SHIFT FLEXCAN_FDCTRL_TDCFAIL_SHIFT

#define CAN_FDCTRL_TDCFAIL(x) FLEXCAN_FDCTRL_TDCFAIL(x)

#define CAN_FDCTRL_TDCEN_MASK  FLEXCAN_FDCTRL_TDCEN_MASK
#define CAN_FDCTRL_TDCEN_SHIFT FLEXCAN_FDCTRL_TDCEN_SHIFT

#define CAN_FDCTRL_TDCEN(x) FLEXCAN_FDCTRL_TDCEN(x)

#define CAN_FDCTRL_MBDSR0_MASK  FLEXCAN_FDCTRL_MBDSR0_MASK
#define CAN_FDCTRL_MBDSR0_SHIFT FLEXCAN_FDCTRL_MBDSR0_SHIFT

#define CAN_FDCTRL_MBDSR0(x) FLEXCAN_FDCTRL_MBDSR0(x)

#define CAN_FDCTRL_MBDSR1_MASK  FLEXCAN_FDCTRL_MBDSR1_MASK
#define CAN_FDCTRL_MBDSR1_SHIFT FLEXCAN_FDCTRL_MBDSR1_SHIFT

#define CAN_FDCTRL_MBDSR1(x) FLEXCAN_FDCTRL_MBDSR1(x)

#define CAN_FDCTRL_MBDSR2_MASK  FLEXCAN_FDCTRL_MBDSR2_MASK
#define CAN_FDCTRL_MBDSR2_SHIFT FLEXCAN_FDCTRL_MBDSR2_SHIFT

#define CAN_FDCTRL_MBDSR2(x) FLEXCAN_FDCTRL_MBDSR2(x)

#define CAN_FDCTRL_MBDSR3_MASK  FLEXCAN_FDCTRL_MBDSR3_MASK
#define CAN_FDCTRL_MBDSR3_SHIFT FLEXCAN_FDCTRL_MBDSR3_SHIFT

#define CAN_FDCTRL_MBDSR3(x) FLEXCAN_FDCTRL_MBDSR3(x)

#define CAN_FDCTRL_FDRATE_MASK  FLEXCAN_FDCTRL_FDRATE_MASK
#define CAN_FDCTRL_FDRATE_SHIFT FLEXCAN_FDCTRL_FDRATE_SHIFT

#define CAN_FDCTRL_FDRATE(x) FLEXCAN_FDCTRL_FDRATE(x)
/*! @} */

/*! @name FDCBT - CAN FD Bit Timing Register */
/*! @{ */

#define CAN_FDCBT_FPSEG2_MASK  FLEXCAN_FDCBT_FPSEG2_MASK
#define CAN_FDCBT_FPSEG2_SHIFT FLEXCAN_FDCBT_FPSEG2_SHIFT

#define CAN_FDCBT_FPSEG2(x) FLEXCAN_FDCBT_FPSEG2(x)

#define CAN_FDCBT_FPSEG1_MASK  FLEXCAN_FDCBT_FPSEG1_MASK
#define CAN_FDCBT_FPSEG1_SHIFT FLEXCAN_FDCBT_FPSEG1_SHIFT

#define CAN_FDCBT_FPSEG1(x) FLEXCAN_FDCBT_FPSEG1(x)

#define CAN_FDCBT_FPROPSEG_MASK  FLEXCAN_FDCBT_FPROPSEG_MASK
#define CAN_FDCBT_FPROPSEG_SHIFT FLEXCAN_FDCBT_FPROPSEG_SHIFT

#define CAN_FDCBT_FPROPSEG(x) FLEXCAN_FDCBT_FPROPSEG(x)

#define CAN_FDCBT_FRJW_MASK  FLEXCAN_FDCBT_FRJW_MASK
#define CAN_FDCBT_FRJW_SHIFT FLEXCAN_FDCBT_FRJW_SHIFT

#define CAN_FDCBT_FRJW(x) FLEXCAN_FDCBT_FRJW(x)

#define CAN_FDCBT_FPRESDIV_MASK  FLEXCAN_FDCBT_FPRESDIV_MASK
#define CAN_FDCBT_FPRESDIV_SHIFT FLEXCAN_FDCBT_FPRESDIV_SHIFT

#define CAN_FDCBT_FPRESDIV(x) FLEXCAN_FDCBT_FPRESDIV(x)
/*! @} */

/*! @name FDCRC - CAN FD CRC Register */
/*! @{ */

#define CAN_FDCRC_FD_TXCRC_MASK  FLEXCAN_FDCRC_FD_TXCRC_MASK
#define CAN_FDCRC_FD_TXCRC_SHIFT FLEXCAN_FDCRC_FD_TXCRC_SHIFT

#define CAN_FDCRC_FD_TXCRC(x) FLEXCAN_FDCRC_FD_TXCRC(x)

#define CAN_FDCRC_FD_MBCRC_MASK  FLEXCAN_FDCRC_FD_MBCRC_MASK
#define CAN_FDCRC_FD_MBCRC_SHIFT FLEXCAN_FDCRC_FD_MBCRC_SHIFT

#define CAN_FDCRC_FD_MBCRC(x) FLEXCAN_FDCRC_FD_MBCRC(x)
/*! @} */

/*! @name ERFCR - Enhanced Rx FIFO Control Register */
/*! @{ */

#define CAN_ERFCR_ERFWM_MASK  FLEXCAN_ERFCR_ERFWM_MASK
#define CAN_ERFCR_ERFWM_SHIFT FLEXCAN_ERFCR_ERFWM_SHIFT

#define CAN_ERFCR_ERFWM(x) FLEXCAN_ERFCR_ERFWM(x)

#define CAN_ERFCR_NFE_MASK  FLEXCAN_ERFCR_NFE_MASK
#define CAN_ERFCR_NFE_SHIFT FLEXCAN_ERFCR_NFE_SHIFT

#define CAN_ERFCR_NFE(x) FLEXCAN_ERFCR_NFE(x)

#define CAN_ERFCR_NEXIF_MASK  FLEXCAN_ERFCR_NEXIF_MASK
#define CAN_ERFCR_NEXIF_SHIFT FLEXCAN_ERFCR_NEXIF_SHIFT

#define CAN_ERFCR_NEXIF(x) FLEXCAN_ERFCR_NEXIF(x)

#define CAN_ERFCR_DMALW_MASK  FLEXCAN_ERFCR_DMALW_MASK
#define CAN_ERFCR_DMALW_SHIFT FLEXCAN_ERFCR_DMALW_SHIFT

#define CAN_ERFCR_DMALW(x) FLEXCAN_ERFCR_DMALW(x)

#define CAN_ERFCR_ERFEN_MASK  FLEXCAN_ERFCR_ERFEN_MASK
#define CAN_ERFCR_ERFEN_SHIFT FLEXCAN_ERFCR_ERFEN_SHIFT

#define CAN_ERFCR_ERFEN(x) FLEXCAN_ERFCR_ERFEN(x)
/*! @} */

/*! @name ERFIER - Enhanced Rx FIFO Interrupt Enable Register */
/*! @{ */

#define CAN_ERFIER_ERFDAIE_MASK  FLEXCAN_ERFIER_ERFDAIE_MASK
#define CAN_ERFIER_ERFDAIE_SHIFT FLEXCAN_ERFIER_ERFDAIE_SHIFT

#define CAN_ERFIER_ERFDAIE(x) FLEXCAN_ERFIER_ERFDAIE(x)

#define CAN_ERFIER_ERFWMIIE_MASK  FLEXCAN_ERFIER_ERFWMIIE_MASK
#define CAN_ERFIER_ERFWMIIE_SHIFT FLEXCAN_ERFIER_ERFWMIIE_SHIFT

#define CAN_ERFIER_ERFWMIIE(x) FLEXCAN_ERFIER_ERFWMIIE(x)

#define CAN_ERFIER_ERFOVFIE_MASK  FLEXCAN_ERFIER_ERFOVFIE_MASK
#define CAN_ERFIER_ERFOVFIE_SHIFT FLEXCAN_ERFIER_ERFOVFIE_SHIFT

#define CAN_ERFIER_ERFOVFIE(x) FLEXCAN_ERFIER_ERFOVFIE(x)

#define CAN_ERFIER_ERFUFWIE_MASK  FLEXCAN_ERFIER_ERFUFWIE_MASK
#define CAN_ERFIER_ERFUFWIE_SHIFT FLEXCAN_ERFIER_ERFUFWIE_SHIFT

#define CAN_ERFIER_ERFUFWIE(x) FLEXCAN_ERFIER_ERFUFWIE(x)
/*! @} */

/*! @name ERFSR - Enhanced Rx FIFO Status Register */
/*! @{ */

#define CAN_ERFSR_ERFEL_MASK  FLEXCAN_ERFSR_ERFEL_MASK
#define CAN_ERFSR_ERFEL_SHIFT FLEXCAN_ERFSR_ERFEL_SHIFT

#define CAN_ERFSR_ERFEL(x) FLEXCAN_ERFSR_ERFEL(x)

#define CAN_ERFSR_ERFF_MASK  FLEXCAN_ERFSR_ERFF_MASK
#define CAN_ERFSR_ERFF_SHIFT FLEXCAN_ERFSR_ERFF_SHIFT

#define CAN_ERFSR_ERFF(x) FLEXCAN_ERFSR_ERFF(x)

#define CAN_ERFSR_ERFE_MASK  FLEXCAN_ERFSR_ERFE_MASK
#define CAN_ERFSR_ERFE_SHIFT FLEXCAN_ERFSR_ERFE_SHIFT

#define CAN_ERFSR_ERFE(x) FLEXCAN_ERFSR_ERFE(x)

#define CAN_ERFSR_ERFCLR_MASK  FLEXCAN_ERFSR_ERFCLR_MASK
#define CAN_ERFSR_ERFCLR_SHIFT FLEXCAN_ERFSR_ERFCLR_SHIFT

#define CAN_ERFSR_ERFCLR(x) FLEXCAN_ERFSR_ERFCLR(x)

#define CAN_ERFSR_ERFDA_MASK  FLEXCAN_ERFSR_ERFDA_MASK
#define CAN_ERFSR_ERFDA_SHIFT FLEXCAN_ERFSR_ERFDA_SHIFT

#define CAN_ERFSR_ERFDA(x) FLEXCAN_ERFSR_ERFDA(x)

#define CAN_ERFSR_ERFWMI_MASK  FLEXCAN_ERFSR_ERFWMI_MASK
#define CAN_ERFSR_ERFWMI_SHIFT FLEXCAN_ERFSR_ERFWMI_SHIFT

#define CAN_ERFSR_ERFWMI(x) FLEXCAN_ERFSR_ERFWMI(x)

#define CAN_ERFSR_ERFOVF_MASK  FLEXCAN_ERFSR_ERFOVF_MASK
#define CAN_ERFSR_ERFOVF_SHIFT FLEXCAN_ERFSR_ERFOVF_SHIFT

#define CAN_ERFSR_ERFOVF(x) FLEXCAN_ERFSR_ERFOVF(x)

#define CAN_ERFSR_ERFUFW_MASK  FLEXCAN_ERFSR_ERFUFW_MASK
#define CAN_ERFSR_ERFUFW_SHIFT FLEXCAN_ERFSR_ERFUFW_SHIFT

#define CAN_ERFSR_ERFUFW(x) FLEXCAN_ERFSR_ERFUFW(x)
/*! @} */

/*! @name HR_TIME_STAMP - High Resolution Time Stamp */
/*! @{ */

#define CAN_HR_TIME_STAMP_TS_MASK  FLEXCAN_HR_TIME_STAMP_TS_MASK
#define CAN_HR_TIME_STAMP_TS_SHIFT FLEXCAN_HR_TIME_STAMP_TS_SHIFT

#define CAN_HR_TIME_STAMP_TS(x) FLEXCAN_HR_TIME_STAMP_TS(x)
/*! @} */

/* The count of CAN_HR_TIME_STAMP */
#define CAN_HR_TIME_STAMP_COUNT (128U)

/*! @name ERFFEL - Enhanced Rx FIFO Filter Element */
/*! @{ */

#define CAN_ERFFEL_FEL_MASK  FLEXCAN_ERFFEL_FEL_MASK
#define CAN_ERFFEL_FEL_SHIFT FLEXCAN_ERFFEL_FEL_SHIFT

#define CAN_ERFFEL_FEL(x) FLEX_CAN_ERFFEL_FEL(x)
/*! @} */

/* The count of CAN_ERFFEL */
#define CAN_ERFFEL_COUNT (128U)

#endif /* _S32Z270_DEVICE_H_ */
