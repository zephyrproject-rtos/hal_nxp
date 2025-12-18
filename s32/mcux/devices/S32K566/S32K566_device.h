/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _S32K566_DEVICE_H_
#define _S32K566_DEVICE_H_              _S32K566_DEVICE_H_

/* ----------------------------------------------------------------------------
   -- CAN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Peripheral_Access_Layer CAN Peripheral Access Layer
 * @{
 */


/** FLEXCAN - Size of Registers Arrays */
#define CAN_RXIMR_COUNT                 FLEXCAN_RXIMR_COUNT
#define CAN_HR_TIME_STAMP_COUNT         FLEXCAN_HR_TIME_STAMP_COUNT
#define CAN_ERFFEL_COUNT                FLEXCAN_ERFFEL_COUNT

/** FLEXCAN - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration, offset: 0x0 */
  __IO uint32_t CTRL1;                             /**< Control 1, offset: 0x4 */
  __IO uint32_t TIMER;                             /**< Free-Running Timer, offset: 0x8 */
  uint8_t RESERVED_0[4];
  __IO uint32_t RXMGMASK;                          /**< RX Message Buffers Global Mask, offset: 0x10 */
  __IO uint32_t RX14MASK;                          /**< Receive 14 Mask, offset: 0x14 */
  __IO uint32_t RX15MASK;                          /**< Receive 15 Mask, offset: 0x18 */
  __IO uint32_t ECR;                               /**< Error Counter, offset: 0x1C */
  __IO uint32_t ESR1;                              /**< Error and Status 1, offset: 0x20 */
  __IO uint32_t IMASK2;                            /**< Interrupt Masks 2, offset: 0x24 */
  __IO uint32_t IMASK1;                            /**< Interrupt Masks 1, offset: 0x28 */
  __IO uint32_t IFLAG2;                            /**< Interrupt Flags 2, offset: 0x2C */
  __IO uint32_t IFLAG1;                            /**< Interrupt Flags 1, offset: 0x30 */
  __IO uint32_t CTRL2;                             /**< Control 2, offset: 0x34 */
  __I  uint32_t ESR2;                              /**< Error and Status 2, offset: 0x38 */
  uint8_t RESERVED_1[8];
  __I  uint32_t CRCR;                              /**< Cyclic Redundancy Check, offset: 0x44 */
  __IO uint32_t RXFGMASK;                          /**< Legacy RX FIFO Global Mask, offset: 0x48 */
  __I  uint32_t RXFIR;                             /**< Legacy RX FIFO Information, offset: 0x4C */
  __IO uint32_t CBT;                               /**< CAN Bit Timing, offset: 0x50 */
  uint8_t RESERVED_2[24];
  __IO uint32_t IMASK3;                            /**< Interrupt Masks 3, offset: 0x6C */
  uint8_t RESERVED_3[4];
  __IO uint32_t IFLAG3;                            /**< Interrupt Flags 3, offset: 0x74 */
  __I  uint32_t ET;                                /**< External Timer, offset: 0x78 */
  __IO uint32_t FLTCONF_IE;                        /**< Fault Confinement Interrupt Enable, offset: 0x7C */
  struct
   {                                               /* offset: 0x80, array step: 0x10 */
      __IO uint32_t CS;                            /**< Message Buffer 0 CS Register..Message Buffer 96 CS Register, array offset: 0x80, array step: 0x10 */
      __IO uint32_t ID;                            /**< Message Buffer 0 ID Register..Message Buffer 96 ID Register, array offset: 0x84, array step: 0x10 */
      __IO uint32_t WORD0;                         /**< Message Buffer 0 WORD0 Register..Message Buffer 96 WORD0 Register, array offset: 0x88, array step: 0x10 */
      __IO uint32_t WORD1;                         /**< Message Buffer 0 WORD1 Register..Message Buffer 96 WORD1 Register, array offset: 0x8C, array step: 0x10 */
   } MB[96];
  uint8_t RESERVED_4[512];
  __IO uint32_t RXIMR[FLEXCAN_RXIMR_COUNT];        /**< Receive Individual Mask, array offset: 0x880, array step: 0x4 */
  uint8_t RESERVED_5[224];
  __IO uint32_t MECR;                              /**< Memory Error Control, offset: 0xAE0 */
  __IO uint32_t ERRIAR;                            /**< Error Injection Address, offset: 0xAE4 */
  __IO uint32_t ERRIDPR;                           /**< Error Injection Data Pattern, offset: 0xAE8 */
  __IO uint32_t ERRIPPR;                           /**< Error Injection Parity Pattern, offset: 0xAEC */
  __I  uint32_t RERRAR;                            /**< Error Report Address, offset: 0xAF0 */
  __I  uint32_t RERRDR;                            /**< Error Report Data, offset: 0xAF4 */
  __I  uint32_t RERRSYNR;                          /**< Error Report Syndrome, offset: 0xAF8 */
  __IO uint32_t ERRSR;                             /**< Error Status, offset: 0xAFC */
  uint8_t RESERVED_6[240];
  __IO uint32_t EPRS;                              /**< Enhanced CAN Bit Timing Prescalers, offset: 0xBF0 */
  __IO uint32_t ENCBT;                             /**< Enhanced Nominal CAN Bit Timing, offset: 0xBF4 */
  __IO uint32_t EDCBT;                             /**< Enhanced Data Phase CAN Bit Timing, offset: 0xBF8 */
  __IO uint32_t ETDC;                              /**< Enhanced Transceiver Delay Compensation, offset: 0xBFC */
  __IO uint32_t FDCTRL;                            /**< CAN FD Control, offset: 0xC00 */
  __IO uint32_t FDCBT;                             /**< CAN FD Bit Timing, offset: 0xC04 */
  __I  uint32_t FDCRC;                             /**< CAN FD CRC, offset: 0xC08 */
  __IO uint32_t ERFCR;                             /**< Enhanced RX FIFO Control, offset: 0xC0C */
  __IO uint32_t ERFIER;                            /**< Enhanced RX FIFO Interrupt Enable, offset: 0xC10 */
  __IO uint32_t ERFSR;                             /**< Enhanced RX FIFO Status, offset: 0xC14 */
  uint8_t RESERVED_7[24];
  __IO uint32_t HR_TIME_STAMP[FLEXCAN_HR_TIME_STAMP_COUNT]; /**< High-Resolution Timestamp, array offset: 0xC30, array step: 0x4 */
  uint8_t RESERVED_8[8784];
  __IO uint32_t ERFFEL[FLEXCAN_ERFFEL_COUNT];      /**< Enhanced RX FIFO Filter Element, array offset: 0x3000, array step: 0x4 */
} CAN_Type;


/* ----------------------------------------------------------------------------
   -- FLEXCAN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXCAN_Register_Masks FLEXCAN Register Masks
 * @{
 */

/*! @name MCR - Module Configuration */
/*! @{ */

#define CAN_MCR_MAXMB_MASK              FLEXCAN_MCR_MAXMB_MASK
#define CAN_MCR_MAXMB_SHIFT             FLEXCAN_MCR_MAXMB_SHIFT
#define CAN_MCR_MAXMB_WIDTH             FLEXCAN_MCR_MAXMB_WIDTH
#define CAN_MCR_MAXMB(x)                FLEXCAN_MCR_MAXMB(x)

#define CAN_MCR_TPOE_MASK               FLEXCAN_MCR_TPOE_MASK
#define CAN_MCR_TPOE_SHIFT              FLEXCAN_MCR_TPOE_SHIFT
#define CAN_MCR_TPOE_WIDTH              FLEXCAN_MCR_TPOE_WIDTH
#define CAN_MCR_TPOE(x)                 FLEXCAN_MCR_TPOE(x)

#define CAN_MCR_IDAM_MASK               FLEXCAN_MCR_IDAM_MASK
#define CAN_MCR_IDAM_SHIFT              FLEXCAN_MCR_IDAM_SHIFT
#define CAN_MCR_IDAM_WIDTH              FLEXCAN_MCR_IDAM_WIDTH
#define CAN_MCR_IDAM(x)                 FLEXCAN_MCR_IDAM(x)

#define CAN_MCR_TPOV_MASK               FLEXCAN_MCR_TPOV_MASK
#define CAN_MCR_TPOV_SHIFT              FLEXCAN_MCR_TPOV_SHIFT
#define CAN_MCR_TPOV_WIDTH              FLEXCAN_MCR_TPOV_WIDTH
#define CAN_MCR_TPOV(x)                 FLEXCAN_MCR_TPOV(x)

#define CAN_MCR_FDEN_MASK               FLEXCAN_MCR_FDEN_MASK
#define CAN_MCR_FDEN_SHIFT              FLEXCAN_MCR_FDEN_SHIFT
#define CAN_MCR_FDEN_WIDTH              FLEXCAN_MCR_FDEN_WIDTH
#define CAN_MCR_FDEN(x)                 FLEXCAN_MCR_FDEN(x)

#define CAN_MCR_AEN_MASK                FLEXCAN_MCR_AEN_MASK
#define CAN_MCR_AEN_SHIFT               FLEXCAN_MCR_AEN_SHIFT
#define CAN_MCR_AEN_WIDTH               FLEXCAN_MCR_AEN_WIDTH
#define CAN_MCR_AEN(x)                  FLEXCAN_MCR_AEN(x)

#define CAN_MCR_LPRIOEN_MASK            FLEXCAN_MCR_LPRIOEN_MASK
#define CAN_MCR_LPRIOEN_SHIFT           FLEXCAN_MCR_LPRIOEN_SHIFT
#define CAN_MCR_LPRIOEN_WIDTH           FLEXCAN_MCR_LPRIOEN_WIDTH
#define CAN_MCR_LPRIOEN(x)              FLEXCAN_MCR_LPRIOEN(x)

#define CAN_MCR_DMA_MASK                FLEXCAN_MCR_DMA_MASK
#define CAN_MCR_DMA_SHIFT               FLEXCAN_MCR_DMA_SHIFT
#define CAN_MCR_DMA_WIDTH               FLEXCAN_MCR_DMA_WIDTH
#define CAN_MCR_DMA(x)                  FLEXCAN_MCR_DMA(x)

#define CAN_MCR_IRMQ_MASK               FLEXCAN_MCR_IRMQ_MASK
#define CAN_MCR_IRMQ_SHIFT              FLEXCAN_MCR_IRMQ_SHIFT
#define CAN_MCR_IRMQ_WIDTH              FLEXCAN_MCR_IRMQ_WIDTH
#define CAN_MCR_IRMQ(x)                 FLEXCAN_MCR_IRMQ(x)

#define CAN_MCR_SRXDIS_MASK             FLEXCAN_MCR_SRXDIS_MASK
#define CAN_MCR_SRXDIS_SHIFT            FLEXCAN_MCR_SRXDIS_SHIFT
#define CAN_MCR_SRXDIS_WIDTH            FLEXCAN_MCR_SRXDIS_WIDTH
#define CAN_MCR_SRXDIS(x)               FLEXCAN_MCR_SRXDIS(x)

#define CAN_MCR_LPMACK_MASK             FLEXCAN_MCR_LPMACK_MASK
#define CAN_MCR_LPMACK_SHIFT            FLEXCAN_MCR_LPMACK_SHIFT
#define CAN_MCR_LPMACK_WIDTH            FLEXCAN_MCR_LPMACK_WIDTH
#define CAN_MCR_LPMACK(x)               FLEXCAN_MCR_LPMACK(x)

#define CAN_MCR_WRNEN_MASK              FLEXCAN_MCR_WRNEN_MASK
#define CAN_MCR_WRNEN_SHIFT             FLEXCAN_MCR_WRNEN_SHIFT
#define CAN_MCR_WRNEN_WIDTH             FLEXCAN_MCR_WRNEN_WIDTH
#define CAN_MCR_WRNEN(x)                FLEXCAN_MCR_WRNEN(x)

#define CAN_MCR_SUPV_MASK               FLEXCAN_MCR_SUPV_MASK
#define CAN_MCR_SUPV_SHIFT              FLEXCAN_MCR_SUPV_SHIFT
#define CAN_MCR_SUPV_WIDTH              FLEXCAN_MCR_SUPV_WIDTH
#define CAN_MCR_SUPV(x)                 FLEXCAN_MCR_SUPV(x)

#define CAN_MCR_FRZACK_MASK             FLEXCAN_MCR_FRZACK_MASK
#define CAN_MCR_FRZACK_SHIFT            FLEXCAN_MCR_FRZACK_SHIFT
#define CAN_MCR_FRZACK_WIDTH            FLEXCAN_MCR_FRZACK_WIDTH
#define CAN_MCR_FRZACK(x)               FLEXCAN_MCR_FRZACK(x)

#define CAN_MCR_SOFTRST_MASK            FLEXCAN_MCR_SOFTRST_MASK
#define CAN_MCR_SOFTRST_SHIFT           FLEXCAN_MCR_SOFTRST_SHIFT
#define CAN_MCR_SOFTRST_WIDTH           FLEXCAN_MCR_SOFTRST_WIDTH
#define CAN_MCR_SOFTRST(x)              FLEXCAN_MCR_SOFTRST(x)

#define CAN_MCR_NOTRDY_MASK             FLEXCAN_MCR_NOTRDY_MASK
#define CAN_MCR_NOTRDY_SHIFT            FLEXCAN_MCR_NOTRDY_SHIFT
#define CAN_MCR_NOTRDY_WIDTH            FLEXCAN_MCR_NOTRDY_WIDTH
#define CAN_MCR_NOTRDY(x)               FLEXCAN_MCR_NOTRDY(x)

#define CAN_MCR_HALT_MASK               FLEXCAN_MCR_HALT_MASK
#define CAN_MCR_HALT_SHIFT              FLEXCAN_MCR_HALT_SHIFT
#define CAN_MCR_HALT_WIDTH              FLEXCAN_MCR_HALT_WIDTH
#define CAN_MCR_HALT(x)                 FLEXCAN_MCR_HALT(x)

#define CAN_MCR_RFEN_MASK               FLEXCAN_MCR_RFEN_MASK
#define CAN_MCR_RFEN_SHIFT              FLEXCAN_MCR_RFEN_SHIFT
#define CAN_MCR_RFEN_WIDTH              FLEXCAN_MCR_RFEN_WIDTH
#define CAN_MCR_RFEN(x)                 FLEXCAN_MCR_RFEN(x)

#define CAN_MCR_FRZ_MASK                FLEXCAN_MCR_FRZ_MASK
#define CAN_MCR_FRZ_SHIFT               FLEXCAN_MCR_FRZ_SHIFT
#define CAN_MCR_FRZ_WIDTH               FLEXCAN_MCR_FRZ_WIDTH
#define CAN_MCR_FRZ(x)                  FLEXCAN_MCR_FRZ(x)

#define CAN_MCR_MDIS_MASK               FLEXCAN_MCR_MDIS_MASK
#define CAN_MCR_MDIS_SHIFT              FLEXCAN_MCR_MDIS_SHIFT
#define CAN_MCR_MDIS_WIDTH              FLEXCAN_MCR_MDIS_WIDTH
#define CAN_MCR_MDIS(x)                 FLEXCAN_MCR_MDIS(x)
/*! @} */

/*! @name CTRL1 - Control 1 */
/*! @{ */

#define CAN_CTRL1_PROPSEG_MASK          FLEXCAN_CTRL1_PROPSEG_MASK
#define CAN_CTRL1_PROPSEG_SHIFT         FLEXCAN_CTRL1_PROPSEG_SHIFT
#define CAN_CTRL1_PROPSEG_WIDTH         FLEXCAN_CTRL1_PROPSEG_WIDTH
#define CAN_CTRL1_PROPSEG(x)            FLEXCAN_CTRL1_PROPSEG(x)

#define CAN_CTRL1_LOM_MASK              FLEXCAN_CTRL1_LOM_MASK
#define CAN_CTRL1_LOM_SHIFT             FLEXCAN_CTRL1_LOM_SHIFT
#define CAN_CTRL1_LOM_WIDTH             FLEXCAN_CTRL1_LOM_WIDTH
#define CAN_CTRL1_LOM(x)                FLEXCAN_CTRL1_LOM(x)

#define CAN_CTRL1_LBUF_MASK             FLEXCAN_CTRL1_LBUF_MASK
#define CAN_CTRL1_LBUF_SHIFT            FLEXCAN_CTRL1_LBUF_SHIFT
#define CAN_CTRL1_LBUF_WIDTH            FLEXCAN_CTRL1_LBUF_WIDTH
#define CAN_CTRL1_LBUF(x)               FLEXCAN_CTRL1_LBUF(x)

#define CAN_CTRL1_TSYN_MASK             FLEXCAN_CTRL1_TSYN_MASK
#define CAN_CTRL1_TSYN_SHIFT            FLEXCAN_CTRL1_TSYN_SHIFT
#define CAN_CTRL1_TSYN_WIDTH            FLEXCAN_CTRL1_TSYN_WIDTH
#define CAN_CTRL1_TSYN(x)               FLEXCAN_CTRL1_TSYN(x)

#define CAN_CTRL1_BOFFREC_MASK          FLEXCAN_CTRL1_BOFFREC_MASK
#define CAN_CTRL1_BOFFREC_SHIFT         FLEXCAN_CTRL1_BOFFREC_SHIFT
#define CAN_CTRL1_BOFFREC_WIDTH         FLEXCAN_CTRL1_BOFFREC_WIDTH
#define CAN_CTRL1_BOFFREC(x)            FLEXCAN_CTRL1_BOFFREC(x)

#define CAN_CTRL1_SMP_MASK              FLEXCAN_CTRL1_SMP_MASK
#define CAN_CTRL1_SMP_SHIFT             FLEXCAN_CTRL1_SMP_SHIFT
#define CAN_CTRL1_SMP_WIDTH             FLEXCAN_CTRL1_SMP_WIDTH
#define CAN_CTRL1_SMP(x)                FLEXCAN_CTRL1_SMP(x)

#define CAN_CTRL1_ROM_MASK              FLEXCAN_CTRL1_ROM_MASK
#define CAN_CTRL1_ROM_SHIFT             FLEXCAN_CTRL1_ROM_SHIFT
#define CAN_CTRL1_ROM_WIDTH             FLEXCAN_CTRL1_ROM_WIDTH
#define CAN_CTRL1_ROM(x)                FLEXCAN_CTRL1_ROM(x)

#define CAN_CTRL1_RWRNMSK_MASK          FLEXCAN_CTRL1_RWRNMSK_MASK
#define CAN_CTRL1_RWRNMSK_SHIFT         FLEXCAN_CTRL1_RWRNMSK_SHIFT
#define CAN_CTRL1_RWRNMSK_WIDTH         FLEXCAN_CTRL1_RWRNMSK_WIDTH
#define CAN_CTRL1_RWRNMSK(x)            FLEXCAN_CTRL1_RWRNMSK(x)

#define CAN_CTRL1_TWRNMSK_MASK          FLEXCAN_CTRL1_TWRNMSK_MASK
#define CAN_CTRL1_TWRNMSK_SHIFT         FLEXCAN_CTRL1_TWRNMSK_SHIFT
#define CAN_CTRL1_TWRNMSK_WIDTH         FLEXCAN_CTRL1_TWRNMSK_WIDTH
#define CAN_CTRL1_TWRNMSK(x)            FLEXCAN_CTRL1_TWRNMSK(x)

#define CAN_CTRL1_LPB_MASK              FLEXCAN_CTRL1_LPB_MASK
#define CAN_CTRL1_LPB_SHIFT             FLEXCAN_CTRL1_LPB_SHIFT
#define CAN_CTRL1_LPB_WIDTH             FLEXCAN_CTRL1_LPB_WIDTH
#define CAN_CTRL1_LPB(x)                FLEXCAN_CTRL1_LPB(x)

#define CAN_CTRL1_ERRMSK_MASK           FLEXCAN_CTRL1_ERRMSK_MASK
#define CAN_CTRL1_ERRMSK_SHIFT          FLEXCAN_CTRL1_ERRMSK_SHIFT
#define CAN_CTRL1_ERRMSK_WIDTH          FLEXCAN_CTRL1_ERRMSK_WIDTH
#define CAN_CTRL1_ERRMSK(x)             FLEXCAN_CTRL1_ERRMSK(x)

#define CAN_CTRL1_BOFFMSK_MASK          FLEXCAN_CTRL1_BOFFMSK_MASK
#define CAN_CTRL1_BOFFMSK_SHIFT         FLEXCAN_CTRL1_BOFFMSK_SHIFT
#define CAN_CTRL1_BOFFMSK_WIDTH         FLEXCAN_CTRL1_BOFFMSK_WIDTH
#define CAN_CTRL1_BOFFMSK(x)            FLEXCAN_CTRL1_BOFFMSK(x)

#define CAN_CTRL1_PSEG2_MASK            FLEXCAN_CTRL1_PSEG2_MASK
#define CAN_CTRL1_PSEG2_SHIFT           FLEXCAN_CTRL1_PSEG2_SHIFT
#define CAN_CTRL1_PSEG2_WIDTH           FLEXCAN_CTRL1_PSEG2_WIDTH
#define CAN_CTRL1_PSEG2(x)              FLEXCAN_CTRL1_PSEG2(x)

#define CAN_CTRL1_PSEG1_MASK            FLEXCAN_CTRL1_PSEG1_MASK
#define CAN_CTRL1_PSEG1_SHIFT           FLEXCAN_CTRL1_PSEG1_SHIFT
#define CAN_CTRL1_PSEG1_WIDTH           FLEXCAN_CTRL1_PSEG1_WIDTH
#define CAN_CTRL1_PSEG1(x)              FLEXCAN_CTRL1_PSEG1(x)

#define CAN_CTRL1_RJW_MASK              FLEXCAN_CTRL1_RJW_MASK
#define CAN_CTRL1_RJW_SHIFT             FLEXCAN_CTRL1_RJW_SHIFT
#define CAN_CTRL1_RJW_WIDTH             FLEXCAN_CTRL1_RJW_WIDTH
#define CAN_CTRL1_RJW(x)                FLEXCAN_CTRL1_RJW(x)

#define CAN_CTRL1_PRESDIV_MASK          FLEXCAN_CTRL1_PRESDIV_MASK
#define CAN_CTRL1_PRESDIV_SHIFT         FLEXCAN_CTRL1_PRESDIV_SHIFT
#define CAN_CTRL1_PRESDIV_WIDTH         FLEXCAN_CTRL1_PRESDIV_WIDTH
#define CAN_CTRL1_PRESDIV(x)            FLEXCAN_CTRL1_PRESDIV(x)
/*! @} */

/*! @name TIMER - Free-Running Timer */
/*! @{ */

#define CAN_TIMER_TIMER_MASK            FLEXCAN_TIMER_TIMER_MASK
#define CAN_TIMER_TIMER_SHIFT           FLEXCAN_TIMER_TIMER_SHIFT
#define CAN_TIMER_TIMER_WIDTH           FLEXCAN_TIMER_TIMER_WIDTH
#define CAN_TIMER_TIMER(x)              FLEXCAN_TIMER_TIMER(x)
/*! @} */

/*! @name RXMGMASK - RX Message Buffers Global Mask */
/*! @{ */

#define CAN_RXMGMASK_MG_MASK            FLEXCAN_RXMGMASK_MG_MASK
#define CAN_RXMGMASK_MG_SHIFT           FLEXCAN_RXMGMASK_MG_SHIFT
#define CAN_RXMGMASK_MG_WIDTH           FLEXCAN_RXMGMASK_MG_WIDTH
#define CAN_RXMGMASK_MG(x)              FLEXCAN_RXMGMASK_MG(x)
/*! @} */

/*! @name RX14MASK - Receive 14 Mask */
/*! @{ */

#define CAN_RX14MASK_RX14M_MASK         FLEXCAN_RX14MASK_RX14M_MASK
#define CAN_RX14MASK_RX14M_SHIFT        FLEXCAN_RX14MASK_RX14M_SHIFT
#define CAN_RX14MASK_RX14M_WIDTH        FLEXCAN_RX14MASK_RX14M_WIDTH
#define CAN_RX14MASK_RX14M(x)           FLEXCAN_RX14MASK_RX14M(x)
/*! @} */

/*! @name RX15MASK - Receive 15 Mask */
/*! @{ */

#define CAN_RX15MASK_RX15M_MASK         FLEXCAN_RX15MASK_RX15M_MASK
#define CAN_RX15MASK_RX15M_SHIFT        FLEXCAN_RX15MASK_RX15M_SHIFT
#define CAN_RX15MASK_RX15M_WIDTH        FLEXCAN_RX15MASK_RX15M_WIDTH
#define CAN_RX15MASK_RX15M(x)           FLEXCAN_RX15MASK_RX15M(x)
/*! @} */

/*! @name ECR - Error Counter */
/*! @{ */

#define CAN_ECR_TXERRCNT_MASK           FLEXCAN_ECR_TXERRCNT_MASK
#define CAN_ECR_TXERRCNT_SHIFT          FLEXCAN_ECR_TXERRCNT_SHIFT
#define CAN_ECR_TXERRCNT_WIDTH          FLEXCAN_ECR_TXERRCNT_WIDTH
#define CAN_ECR_TXERRCNT(x)             FLEXCAN_ECR_TXERRCNT(x)

#define CAN_ECR_RXERRCNT_MASK           FLEXCAN_ECR_RXERRCNT_MASK
#define CAN_ECR_RXERRCNT_SHIFT          FLEXCAN_ECR_RXERRCNT_SHIFT
#define CAN_ECR_RXERRCNT_WIDTH          FLEXCAN_ECR_RXERRCNT_WIDTH
#define CAN_ECR_RXERRCNT(x)             FLEXCAN_ECR_RXERRCNT(x)

#define CAN_ECR_TXERRCNT_FAST_MASK      FLEXCAN_ECR_TXERRCNT_FAST_MASK
#define CAN_ECR_TXERRCNT_FAST_SHIFT     FLEXCAN_ECR_TXERRCNT_FAST_SHIFT
#define CAN_ECR_TXERRCNT_FAST_WIDTH     FLEXCAN_ECR_TXERRCNT_FAST_WIDTH
#define CAN_ECR_TXERRCNT_FAST(x)        FLEXCAN_ECR_TXERRCNT_FAST(x)

#define CAN_ECR_RXERRCNT_FAST_MASK      FLEXCAN_ECR_RXERRCNT_FAST_MASK
#define CAN_ECR_RXERRCNT_FAST_SHIFT     FLEXCAN_ECR_RXERRCNT_FAST_SHIFT
#define CAN_ECR_RXERRCNT_FAST_WIDTH     FLEXCAN_ECR_RXERRCNT_FAST_WIDTH
#define CAN_ECR_RXERRCNT_FAST(x)        FLEXCAN_ECR_RXERRCNT_FAST(x)
/*! @} */

/*! @name ESR1 - Error and Status 1 */
/*! @{ */

#define CAN_ESR1_ERRINT_MASK            FLEXCAN_ESR1_ERRINT_MASK
#define CAN_ESR1_ERRINT_SHIFT           FLEXCAN_ESR1_ERRINT_SHIFT
#define CAN_ESR1_ERRINT_WIDTH           FLEXCAN_ESR1_ERRINT_WIDTH
#define CAN_ESR1_ERRINT(x)              FLEXCAN_ESR1_ERRINT(x)

#define CAN_ESR1_BOFFINT_MASK           FLEXCAN_ESR1_BOFFINT_MASK
#define CAN_ESR1_BOFFINT_SHIFT          FLEXCAN_ESR1_BOFFINT_SHIFT
#define CAN_ESR1_BOFFINT_WIDTH          FLEXCAN_ESR1_BOFFINT_WIDTH
#define CAN_ESR1_BOFFINT(x)             FLEXCAN_ESR1_BOFFINT(x)

#define CAN_ESR1_RX_MASK                FLEXCAN_ESR1_RX_MASK
#define CAN_ESR1_RX_SHIFT               FLEXCAN_ESR1_RX_SHIFT
#define CAN_ESR1_RX_WIDTH               FLEXCAN_ESR1_RX_WIDTH
#define CAN_ESR1_RX(x)                  FLEXCAN_ESR1_RX(x)

#define CAN_ESR1_FLTCONF_MASK           FLEXCAN_ESR1_FLTCONF_MASK
#define CAN_ESR1_FLTCONF_SHIFT          FLEXCAN_ESR1_FLTCONF_SHIFT
#define CAN_ESR1_FLTCONF_WIDTH          FLEXCAN_ESR1_FLTCONF_WIDTH
#define CAN_ESR1_FLTCONF(x)             FLEXCAN_ESR1_FLTCONF(x)

#define CAN_ESR1_TX_MASK                FLEXCAN_ESR1_TX_MASK
#define CAN_ESR1_TX_SHIFT               FLEXCAN_ESR1_TX_SHIFT
#define CAN_ESR1_TX_WIDTH               FLEXCAN_ESR1_TX_WIDTH
#define CAN_ESR1_TX(x)                  FLEXCAN_ESR1_TX(x)

#define CAN_ESR1_IDLE_MASK              FLEXCAN_ESR1_IDLE_MASK
#define CAN_ESR1_IDLE_SHIFT             FLEXCAN_ESR1_IDLE_SHIFT
#define CAN_ESR1_IDLE_WIDTH             FLEXCAN_ESR1_IDLE_WIDTH
#define CAN_ESR1_IDLE(x)                FLEXCAN_ESR1_IDLE(x)

#define CAN_ESR1_RXWRN_MASK             FLEXCAN_ESR1_RXWRN_MASK
#define CAN_ESR1_RXWRN_SHIFT            FLEXCAN_ESR1_RXWRN_SHIFT
#define CAN_ESR1_RXWRN_WIDTH            FLEXCAN_ESR1_RXWRN_WIDTH
#define CAN_ESR1_RXWRN(x)               FLEXCAN_ESR1_RXWRN(x)

#define CAN_ESR1_TXWRN_MASK             FLEXCAN_ESR1_TXWRN_MASK
#define CAN_ESR1_TXWRN_SHIFT            FLEXCAN_ESR1_TXWRN_SHIFT
#define CAN_ESR1_TXWRN_WIDTH            FLEXCAN_ESR1_TXWRN_WIDTH
#define CAN_ESR1_TXWRN(x)               FLEXCAN_ESR1_TXWRN(x)

#define CAN_ESR1_STFERR_MASK            FLEXCAN_ESR1_STFERR_MASK
#define CAN_ESR1_STFERR_SHIFT           FLEXCAN_ESR1_STFERR_SHIFT
#define CAN_ESR1_STFERR_WIDTH           FLEXCAN_ESR1_STFERR_WIDTH
#define CAN_ESR1_STFERR(x)              FLEXCAN_ESR1_STFERR(x)

#define CAN_ESR1_FRMERR_MASK            FLEXCAN_ESR1_FRMERR_MASK
#define CAN_ESR1_FRMERR_SHIFT           FLEXCAN_ESR1_FRMERR_SHIFT
#define CAN_ESR1_FRMERR_WIDTH           FLEXCAN_ESR1_FRMERR_WIDTH
#define CAN_ESR1_FRMERR(x)              FLEXCAN_ESR1_FRMERR(x)

#define CAN_ESR1_CRCERR_MASK            FLEXCAN_ESR1_CRCERR_MASK
#define CAN_ESR1_CRCERR_SHIFT           FLEXCAN_ESR1_CRCERR_SHIFT
#define CAN_ESR1_CRCERR_WIDTH           FLEXCAN_ESR1_CRCERR_WIDTH
#define CAN_ESR1_CRCERR(x)              FLEXCAN_ESR1_CRCERR(x)

#define CAN_ESR1_ACKERR_MASK            FLEXCAN_ESR1_ACKERR_MASK
#define CAN_ESR1_ACKERR_SHIFT           FLEXCAN_ESR1_ACKERR_SHIFT
#define CAN_ESR1_ACKERR_WIDTH           FLEXCAN_ESR1_ACKERR_WIDTH
#define CAN_ESR1_ACKERR(x)              FLEXCAN_ESR1_ACKERR(x)

#define CAN_ESR1_BIT0ERR_MASK           FLEXCAN_ESR1_BIT0ERR_MASK
#define CAN_ESR1_BIT0ERR_SHIFT          FLEXCAN_ESR1_BIT0ERR_SHIFT
#define CAN_ESR1_BIT0ERR_WIDTH          FLEXCAN_ESR1_BIT0ERR_WIDTH
#define CAN_ESR1_BIT0ERR(x)             FLEXCAN_ESR1_BIT0ERR(x)

#define CAN_ESR1_BIT1ERR_MASK           FLEXCAN_ESR1_BIT1ERR_MASK
#define CAN_ESR1_BIT1ERR_SHIFT          FLEXCAN_ESR1_BIT1ERR_SHIFT
#define CAN_ESR1_BIT1ERR_WIDTH          FLEXCAN_ESR1_BIT1ERR_WIDTH
#define CAN_ESR1_BIT1ERR(x)             FLEXCAN_ESR1_BIT1ERR(x)

#define CAN_ESR1_RWRNINT_MASK           FLEXCAN_ESR1_RWRNINT_MASK
#define CAN_ESR1_RWRNINT_SHIFT          FLEXCAN_ESR1_RWRNINT_SHIFT
#define CAN_ESR1_RWRNINT_WIDTH          FLEXCAN_ESR1_RWRNINT_WIDTH
#define CAN_ESR1_RWRNINT(x)             FLEXCAN_ESR1_RWRNINT(x)

#define CAN_ESR1_TWRNINT_MASK           FLEXCAN_ESR1_TWRNINT_MASK
#define CAN_ESR1_TWRNINT_SHIFT          FLEXCAN_ESR1_TWRNINT_SHIFT
#define CAN_ESR1_TWRNINT_WIDTH          FLEXCAN_ESR1_TWRNINT_WIDTH
#define CAN_ESR1_TWRNINT(x)             FLEXCAN_ESR1_TWRNINT(x)

#define CAN_ESR1_SYNCH_MASK             FLEXCAN_ESR1_SYNCH_MASK
#define CAN_ESR1_SYNCH_SHIFT            FLEXCAN_ESR1_SYNCH_SHIFT
#define CAN_ESR1_SYNCH_WIDTH            FLEXCAN_ESR1_SYNCH_WIDTH
#define CAN_ESR1_SYNCH(x)               FLEXCAN_ESR1_SYNCH(x)

#define CAN_ESR1_BOFFDONEINT_MASK       FLEXCAN_ESR1_BOFFDONEINT_MASK
#define CAN_ESR1_BOFFDONEINT_SHIFT      FLEXCAN_ESR1_BOFFDONEINT_SHIFT
#define CAN_ESR1_BOFFDONEINT_WIDTH      FLEXCAN_ESR1_BOFFDONEINT_WIDTH
#define CAN_ESR1_BOFFDONEINT(x)         FLEXCAN_ESR1_BOFFDONEINT(x)

#define CAN_ESR1_ERRINT_FAST_MASK       FLEXCAN_ESR1_ERRINT_FAST_MASK
#define CAN_ESR1_ERRINT_FAST_SHIFT      FLEXCAN_ESR1_ERRINT_FAST_SHIFT
#define CAN_ESR1_ERRINT_FAST_WIDTH      FLEXCAN_ESR1_ERRINT_FAST_WIDTH
#define CAN_ESR1_ERRINT_FAST(x)         FLEXCAN_ESR1_ERRINT_FAST(x)

#define CAN_ESR1_ERROVR_MASK            FLEXCAN_ESR1_ERROVR_MASK
#define CAN_ESR1_ERROVR_SHIFT           FLEXCAN_ESR1_ERROVR_SHIFT
#define CAN_ESR1_ERROVR_WIDTH           FLEXCAN_ESR1_ERROVR_WIDTH
#define CAN_ESR1_ERROVR(x)              FLEXCAN_ESR1_ERROVR(x)

#define CAN_ESR1_ATP_MASK               FLEXCAN_ESR1_ATP_MASK
#define CAN_ESR1_ATP_SHIFT              FLEXCAN_ESR1_ATP_SHIFT
#define CAN_ESR1_ATP_WIDTH              FLEXCAN_ESR1_ATP_WIDTH
#define CAN_ESR1_ATP(x)                 FLEXCAN_ESR1_ATP(x)

#define CAN_ESR1_PTA_MASK               FLEXCAN_ESR1_PTA_MASK
#define CAN_ESR1_PTA_SHIFT              FLEXCAN_ESR1_PTA_SHIFT
#define CAN_ESR1_PTA_WIDTH              FLEXCAN_ESR1_PTA_WIDTH
#define CAN_ESR1_PTA(x)                 FLEXCAN_ESR1_PTA(x)

#define CAN_ESR1_STFERR_FAST_MASK       FLEXCAN_ESR1_STFERR_FAST_MASK
#define CAN_ESR1_STFERR_FAST_SHIFT      FLEXCAN_ESR1_STFERR_FAST_SHIFT
#define CAN_ESR1_STFERR_FAST_WIDTH      FLEXCAN_ESR1_STFERR_FAST_WIDTH
#define CAN_ESR1_STFERR_FAST(x)         FLEXCAN_ESR1_STFERR_FAST(x)

#define CAN_ESR1_FRMERR_FAST_MASK       FLEXCAN_ESR1_FRMERR_FAST_MASK
#define CAN_ESR1_FRMERR_FAST_SHIFT      FLEXCAN_ESR1_FRMERR_FAST_SHIFT
#define CAN_ESR1_FRMERR_FAST_WIDTH      FLEXCAN_ESR1_FRMERR_FAST_WIDTH
#define CAN_ESR1_FRMERR_FAST(x)         FLEXCAN_ESR1_FRMERR_FAST(x)

#define CAN_ESR1_CRCERR_FAST_MASK       FLEXCAN_ESR1_CRCERR_FAST_MASK
#define CAN_ESR1_CRCERR_FAST_SHIFT      FLEXCAN_ESR1_CRCERR_FAST_SHIFT
#define CAN_ESR1_CRCERR_FAST_WIDTH      FLEXCAN_ESR1_CRCERR_FAST_WIDTH
#define CAN_ESR1_CRCERR_FAST(x)         FLEXCAN_ESR1_CRCERR_FAST(x)

#define CAN_ESR1_BIT0ERR_FAST_MASK      FLEXCAN_ESR1_BIT0ERR_FAST_MASK
#define CAN_ESR1_BIT0ERR_FAST_SHIFT     FLEXCAN_ESR1_BIT0ERR_FAST_SHIFT
#define CAN_ESR1_BIT0ERR_FAST_WIDTH     FLEXCAN_ESR1_BIT0ERR_FAST_WIDTH
#define CAN_ESR1_BIT0ERR_FAST(x)        FLEXCAN_ESR1_BIT0ERR_FAST(x)

#define CAN_ESR1_BIT1ERR_FAST_MASK      FLEXCAN_ESR1_BIT1ERR_FAST_MASK
#define CAN_ESR1_BIT1ERR_FAST_SHIFT     FLEXCAN_ESR1_BIT1ERR_FAST_SHIFT
#define CAN_ESR1_BIT1ERR_FAST_WIDTH     FLEXCAN_ESR1_BIT1ERR_FAST_WIDTH
#define CAN_ESR1_BIT1ERR_FAST(x)        FLEXCAN_ESR1_BIT1ERR_FAST(x)
/*! @} */

/*! @name IMASK2 - Interrupt Masks 2 */
/*! @{ */

#define CAN_IMASK2_BUF63TO32M_MASK      FLEXCAN_IMASK2_BUF63TO32M_MASK
#define CAN_IMASK2_BUF63TO32M_SHIFT     FLEXCAN_IMASK2_BUF63TO32M_SHIFT
#define CAN_IMASK2_BUF63TO32M_WIDTH     FLEXCAN_IMASK2_BUF63TO32M_WIDTH
#define CAN_IMASK2_BUF63TO32M(x)        FLEXCAN_IMASK2_BUF63TO32M(x)
/*! @} */

/*! @name IMASK1 - Interrupt Masks 1 */
/*! @{ */

#define CAN_IMASK1_BUF31TO0M_MASK       FLEXCAN_IMASK1_BUF31TO0M_MASK
#define CAN_IMASK1_BUF31TO0M_SHIFT      FLEXCAN_IMASK1_BUF31TO0M_SHIFT
#define CAN_IMASK1_BUF31TO0M_WIDTH      FLEXCAN_IMASK1_BUF31TO0M_WIDTH
#define CAN_IMASK1_BUF31TO0M(x)         FLEXCAN_IMASK1_BUF31TO0M(x)
/*! @} */

/*! @name IFLAG2 - Interrupt Flags 2 */
/*! @{ */

#define CAN_IFLAG2_BUF63TO32I_MASK      FLEXCAN_IFLAG2_BUF63TO32I_MASK
#define CAN_IFLAG2_BUF63TO32I_SHIFT     FLEXCAN_IFLAG2_BUF63TO32I_SHIFT
#define CAN_IFLAG2_BUF63TO32I_WIDTH     FLEXCAN_IFLAG2_BUF63TO32I_WIDTH
#define CAN_IFLAG2_BUF63TO32I(x)        FLEXCAN_IFLAG2_BUF63TO32I(x)
/*! @} */

/*! @name IFLAG1 - Interrupt Flags 1 */
/*! @{ */

#define CAN_IFLAG1_BUF0I_MASK           FLEXCAN_IFLAG1_BUF0I_MASK
#define CAN_IFLAG1_BUF0I_SHIFT          FLEXCAN_IFLAG1_BUF0I_SHIFT
#define CAN_IFLAG1_BUF0I_WIDTH          FLEXCAN_IFLAG1_BUF0I_WIDTH
#define CAN_IFLAG1_BUF0I(x)             FLEXCAN_IFLAG1_BUF0I(x)

#define CAN_IFLAG1_BUF4TO1I_MASK        FLEXCAN_IFLAG1_BUF4TO1I_MASK
#define CAN_IFLAG1_BUF4TO1I_SHIFT       FLEXCAN_IFLAG1_BUF4TO1I_SHIFT
#define CAN_IFLAG1_BUF4TO1I_WIDTH       FLEXCAN_IFLAG1_BUF4TO1I_WIDTH
#define CAN_IFLAG1_BUF4TO1I(x)          FLEXCAN_IFLAG1_BUF4TO1I(x)

#define CAN_IFLAG1_BUF5I_MASK           FLEXCAN_IFLAG1_BUF5I_MASK
#define CAN_IFLAG1_BUF5I_SHIFT          FLEXCAN_IFLAG1_BUF5I_SHIFT
#define CAN_IFLAG1_BUF5I_WIDTH          FLEXCAN_IFLAG1_BUF5I_WIDTH
#define CAN_IFLAG1_BUF5I(x)             FLEXCAN_IFLAG1_BUF5I(x)

#define CAN_IFLAG1_BUF6I_MASK           FLEXCAN_IFLAG1_BUF6I_MASK
#define CAN_IFLAG1_BUF6I_SHIFT          FLEXCAN_IFLAG1_BUF6I_SHIFT
#define CAN_IFLAG1_BUF6I_WIDTH          FLEXCAN_IFLAG1_BUF6I_WIDTH
#define CAN_IFLAG1_BUF6I(x)             FLEXCAN_IFLAG1_BUF6I(x)

#define CAN_IFLAG1_BUF7I_MASK           FLEXCAN_IFLAG1_BUF7I_MASK
#define CAN_IFLAG1_BUF7I_SHIFT          FLEXCAN_IFLAG1_BUF7I_SHIFT
#define CAN_IFLAG1_BUF7I_WIDTH          FLEXCAN_IFLAG1_BUF7I_WIDTH
#define CAN_IFLAG1_BUF7I(x)             FLEXCAN_IFLAG1_BUF7I(x)

#define CAN_IFLAG1_BUF31TO8I_MASK       FLEXCAN_IFLAG1_BUF31TO8I_MASK
#define CAN_IFLAG1_BUF31TO8I_SHIFT      FLEXCAN_IFLAG1_BUF31TO8I_SHIFT
#define CAN_IFLAG1_BUF31TO8I_WIDTH      FLEXCAN_IFLAG1_BUF31TO8I_WIDTH
#define CAN_IFLAG1_BUF31TO8I(x)         FLEXCAN_IFLAG1_BUF31TO8I(x)
/*! @} */

/*! @name CTRL2 - Control 2 */
/*! @{ */

#define CAN_CTRL2_PES_MASK              FLEXCAN_CTRL2_PES_MASK
#define CAN_CTRL2_PES_SHIFT             FLEXCAN_CTRL2_PES_SHIFT
#define CAN_CTRL2_PES_WIDTH             FLEXCAN_CTRL2_PES_WIDTH
#define CAN_CTRL2_PES(x)                FLEXCAN_CTRL2_PES(x)

#define CAN_CTRL2_ASD_MASK              FLEXCAN_CTRL2_ASD_MASK
#define CAN_CTRL2_ASD_SHIFT             FLEXCAN_CTRL2_ASD_SHIFT
#define CAN_CTRL2_ASD_WIDTH             FLEXCAN_CTRL2_ASD_WIDTH
#define CAN_CTRL2_ASD(x)                FLEXCAN_CTRL2_ASD(x)

#define CAN_CTRL2_RETRY_MASK            FLEXCAN_CTRL2_RETRY_MASK
#define CAN_CTRL2_RETRY_SHIFT           FLEXCAN_CTRL2_RETRY_SHIFT
#define CAN_CTRL2_RETRY_WIDTH           FLEXCAN_CTRL2_RETRY_WIDTH
#define CAN_CTRL2_RETRY(x)              FLEXCAN_CTRL2_RETRY(x)

#define CAN_CTRL2_TSTAMPCAP_MASK        FLEXCAN_CTRL2_TSTAMPCAP_MASK
#define CAN_CTRL2_TSTAMPCAP_SHIFT       FLEXCAN_CTRL2_TSTAMPCAP_SHIFT
#define CAN_CTRL2_TSTAMPCAP_WIDTH       FLEXCAN_CTRL2_TSTAMPCAP_WIDTH
#define CAN_CTRL2_TSTAMPCAP(x)          FLEXCAN_CTRL2_TSTAMPCAP(x)

#define CAN_CTRL2_MBTSBASE_MASK         FLEXCAN_CTRL2_MBTSBASE_MASK
#define CAN_CTRL2_MBTSBASE_SHIFT        FLEXCAN_CTRL2_MBTSBASE_SHIFT
#define CAN_CTRL2_MBTSBASE_WIDTH        FLEXCAN_CTRL2_MBTSBASE_WIDTH
#define CAN_CTRL2_MBTSBASE(x)           FLEXCAN_CTRL2_MBTSBASE(x)

#define CAN_CTRL2_FLT_RXN_MASK          FLEXCAN_CTRL2_FLT_RXN_MASK
#define CAN_CTRL2_FLT_RXN_SHIFT         FLEXCAN_CTRL2_FLT_RXN_SHIFT
#define CAN_CTRL2_FLT_RXN_WIDTH         FLEXCAN_CTRL2_FLT_RXN_WIDTH
#define CAN_CTRL2_FLT_RXN(x)            FLEXCAN_CTRL2_FLT_RXN(x)

#define CAN_CTRL2_EDFLTDIS_MASK         FLEXCAN_CTRL2_EDFLTDIS_MASK
#define CAN_CTRL2_EDFLTDIS_SHIFT        FLEXCAN_CTRL2_EDFLTDIS_SHIFT
#define CAN_CTRL2_EDFLTDIS_WIDTH        FLEXCAN_CTRL2_EDFLTDIS_WIDTH
#define CAN_CTRL2_EDFLTDIS(x)           FLEXCAN_CTRL2_EDFLTDIS(x)

#define CAN_CTRL2_ISOCANFDEN_MASK       FLEXCAN_CTRL2_ISOCANFDEN_MASK
#define CAN_CTRL2_ISOCANFDEN_SHIFT      FLEXCAN_CTRL2_ISOCANFDEN_SHIFT
#define CAN_CTRL2_ISOCANFDEN_WIDTH      FLEXCAN_CTRL2_ISOCANFDEN_WIDTH
#define CAN_CTRL2_ISOCANFDEN(x)         FLEXCAN_CTRL2_ISOCANFDEN(x)

#define CAN_CTRL2_BTE_MASK              FLEXCAN_CTRL2_BTE_MASK
#define CAN_CTRL2_BTE_SHIFT             FLEXCAN_CTRL2_BTE_SHIFT
#define CAN_CTRL2_BTE_WIDTH             FLEXCAN_CTRL2_BTE_WIDTH
#define CAN_CTRL2_BTE(x)                FLEXCAN_CTRL2_BTE(x)

#define CAN_CTRL2_PREXCEN_MASK          FLEXCAN_CTRL2_PREXCEN_MASK
#define CAN_CTRL2_PREXCEN_SHIFT         FLEXCAN_CTRL2_PREXCEN_SHIFT
#define CAN_CTRL2_PREXCEN_WIDTH         FLEXCAN_CTRL2_PREXCEN_WIDTH
#define CAN_CTRL2_PREXCEN(x)            FLEXCAN_CTRL2_PREXCEN(x)

#define CAN_CTRL2_TIMER_SRC_MASK        FLEXCAN_CTRL2_TIMER_SRC_MASK
#define CAN_CTRL2_TIMER_SRC_SHIFT       FLEXCAN_CTRL2_TIMER_SRC_SHIFT
#define CAN_CTRL2_TIMER_SRC_WIDTH       FLEXCAN_CTRL2_TIMER_SRC_WIDTH
#define CAN_CTRL2_TIMER_SRC(x)          FLEXCAN_CTRL2_TIMER_SRC(x)

#define CAN_CTRL2_EACEN_MASK            FLEXCAN_CTRL2_EACEN_MASK
#define CAN_CTRL2_EACEN_SHIFT           FLEXCAN_CTRL2_EACEN_SHIFT
#define CAN_CTRL2_EACEN_WIDTH           FLEXCAN_CTRL2_EACEN_WIDTH
#define CAN_CTRL2_EACEN(x)              FLEXCAN_CTRL2_EACEN(x)

#define CAN_CTRL2_RRS_MASK              FLEXCAN_CTRL2_RRS_MASK
#define CAN_CTRL2_RRS_SHIFT             FLEXCAN_CTRL2_RRS_SHIFT
#define CAN_CTRL2_RRS_WIDTH             FLEXCAN_CTRL2_RRS_WIDTH
#define CAN_CTRL2_RRS(x)                FLEXCAN_CTRL2_RRS(x)

#define CAN_CTRL2_MRP_MASK              FLEXCAN_CTRL2_MRP_MASK
#define CAN_CTRL2_MRP_SHIFT             FLEXCAN_CTRL2_MRP_SHIFT
#define CAN_CTRL2_MRP_WIDTH             FLEXCAN_CTRL2_MRP_WIDTH
#define CAN_CTRL2_MRP(x)                FLEXCAN_CTRL2_MRP(x)

#define CAN_CTRL2_TASD_MASK             FLEXCAN_CTRL2_TASD_MASK
#define CAN_CTRL2_TASD_SHIFT            FLEXCAN_CTRL2_TASD_SHIFT
#define CAN_CTRL2_TASD_WIDTH            FLEXCAN_CTRL2_TASD_WIDTH
#define CAN_CTRL2_TASD(x)               FLEXCAN_CTRL2_TASD(x)

#define CAN_CTRL2_RFFN_MASK             FLEXCAN_CTRL2_RFFN_MASK
#define CAN_CTRL2_RFFN_SHIFT            FLEXCAN_CTRL2_RFFN_SHIFT
#define CAN_CTRL2_RFFN_WIDTH            FLEXCAN_CTRL2_RFFN_WIDTH
#define CAN_CTRL2_RFFN(x)               FLEXCAN_CTRL2_RFFN(x)

#define CAN_CTRL2_WRMFRZ_MASK           FLEXCAN_CTRL2_WRMFRZ_MASK
#define CAN_CTRL2_WRMFRZ_SHIFT          FLEXCAN_CTRL2_WRMFRZ_SHIFT
#define CAN_CTRL2_WRMFRZ_WIDTH          FLEXCAN_CTRL2_WRMFRZ_WIDTH
#define CAN_CTRL2_WRMFRZ(x)             FLEXCAN_CTRL2_WRMFRZ(x)

#define CAN_CTRL2_ECRWRE_MASK           FLEXCAN_CTRL2_ECRWRE_MASK
#define CAN_CTRL2_ECRWRE_SHIFT          FLEXCAN_CTRL2_ECRWRE_SHIFT
#define CAN_CTRL2_ECRWRE_WIDTH          FLEXCAN_CTRL2_ECRWRE_WIDTH
#define CAN_CTRL2_ECRWRE(x)             FLEXCAN_CTRL2_ECRWRE(x)

#define CAN_CTRL2_BOFFDONEMSK_MASK      FLEXCAN_CTRL2_BOFFDONEMSK_MASK
#define CAN_CTRL2_BOFFDONEMSK_SHIFT     FLEXCAN_CTRL2_BOFFDONEMSK_SHIFT
#define CAN_CTRL2_BOFFDONEMSK_WIDTH     FLEXCAN_CTRL2_BOFFDONEMSK_WIDTH
#define CAN_CTRL2_BOFFDONEMSK(x)        FLEXCAN_CTRL2_BOFFDONEMSK(x)

#define CAN_CTRL2_ERRMSK_FAST_MASK      FLEXCAN_CTRL2_ERRMSK_FAST_MASK
#define CAN_CTRL2_ERRMSK_FAST_SHIFT     FLEXCAN_CTRL2_ERRMSK_FAST_SHIFT
#define CAN_CTRL2_ERRMSK_FAST_WIDTH     FLEXCAN_CTRL2_ERRMSK_FAST_WIDTH
#define CAN_CTRL2_ERRMSK_FAST(x)        FLEXCAN_CTRL2_ERRMSK_FAST(x)
/*! @} */

/*! @name ESR2 - Error and Status 2 */
/*! @{ */

#define CAN_ESR2_RX_PIN_ST_MASK         FLEXCAN_ESR2_RX_PIN_ST_MASK
#define CAN_ESR2_RX_PIN_ST_SHIFT        FLEXCAN_ESR2_RX_PIN_ST_SHIFT
#define CAN_ESR2_RX_PIN_ST_WIDTH        FLEXCAN_ESR2_RX_PIN_ST_WIDTH
#define CAN_ESR2_RX_PIN_ST(x)           FLEXCAN_ESR2_RX_PIN_ST(x)

#define CAN_ESR2_IMB_MASK               FLEXCAN_ESR2_IMB_MASK
#define CAN_ESR2_IMB_SHIFT              FLEXCAN_ESR2_IMB_SHIFT
#define CAN_ESR2_IMB_WIDTH              FLEXCAN_ESR2_IMB_WIDTH
#define CAN_ESR2_IMB(x)                 FLEXCAN_ESR2_IMB(x)

#define CAN_ESR2_VPS_MASK               FLEXCAN_ESR2_VPS_MASK
#define CAN_ESR2_VPS_SHIFT              FLEXCAN_ESR2_VPS_SHIFT
#define CAN_ESR2_VPS_WIDTH              FLEXCAN_ESR2_VPS_WIDTH
#define CAN_ESR2_VPS(x)                 FLEXCAN_ESR2_VPS(x)

#define CAN_ESR2_LPTM_MASK              FLEXCAN_ESR2_LPTM_MASK
#define CAN_ESR2_LPTM_SHIFT             FLEXCAN_ESR2_LPTM_SHIFT
#define CAN_ESR2_LPTM_WIDTH             FLEXCAN_ESR2_LPTM_WIDTH
#define CAN_ESR2_LPTM(x)                FLEXCAN_ESR2_LPTM(x)
/*! @} */

/*! @name CRCR - Cyclic Redundancy Check */
/*! @{ */

#define CAN_CRCR_TXCRC_MASK             FLEXCAN_CRCR_TXCRC_MASK
#define CAN_CRCR_TXCRC_SHIFT            FLEXCAN_CRCR_TXCRC_SHIFT
#define CAN_CRCR_TXCRC_WIDTH            FLEXCAN_CRCR_TXCRC_WIDTH
#define CAN_CRCR_TXCRC(x)               FLEXCAN_CRCR_TXCRC(x)

#define CAN_CRCR_MBCRC_MASK             FLEXCAN_CRCR_MBCRC_MASK
#define CAN_CRCR_MBCRC_SHIFT            FLEXCAN_CRCR_MBCRC_SHIFT
#define CAN_CRCR_MBCRC_WIDTH            FLEXCAN_CRCR_MBCRC_WIDTH
#define CAN_CRCR_MBCRC(x)               FLEXCAN_CRCR_MBCRC(x)
/*! @} */

/*! @name RXFGMASK - Legacy RX FIFO Global Mask */
/*! @{ */

#define CAN_RXFGMASK_FGM_MASK           FLEXCAN_RXFGMASK_FGM_MASK
#define CAN_RXFGMASK_FGM_SHIFT          FLEXCAN_RXFGMASK_FGM_SHIFT
#define CAN_RXFGMASK_FGM_WIDTH          FLEXCAN_RXFGMASK_FGM_WIDTH
#define CAN_RXFGMASK_FGM(x)             FLEXCAN_RXFGMASK_FGM(x)
/*! @} */

/*! @name RXFIR - Legacy RX FIFO Information */
/*! @{ */

#define CAN_RXFIR_IDHIT_MASK            FLEXCAN_RXFIR_IDHIT_MASK
#define CAN_RXFIR_IDHIT_SHIFT           FLEXCAN_RXFIR_IDHIT_SHIFT
#define CAN_RXFIR_IDHIT_WIDTH           FLEXCAN_RXFIR_IDHIT_WIDTH
#define CAN_RXFIR_IDHIT(x)              FLEXCAN_RXFIR_IDHIT(x)
/*! @} */

/*! @name CBT - CAN Bit Timing */
/*! @{ */

#define CAN_CBT_EPSEG2_MASK             FLEXCAN_CBT_EPSEG2_MASK
#define CAN_CBT_EPSEG2_SHIFT            FLEXCAN_CBT_EPSEG2_SHIFT
#define CAN_CBT_EPSEG2_WIDTH            FLEXCAN_CBT_EPSEG2_WIDTH
#define CAN_CBT_EPSEG2(x)               FLEXCAN_CBT_EPSEG2(x)

#define CAN_CBT_EPSEG1_MASK             FLEXCAN_CBT_EPSEG1_MASK
#define CAN_CBT_EPSEG1_SHIFT            FLEXCAN_CBT_EPSEG1_SHIFT
#define CAN_CBT_EPSEG1_WIDTH            FLEXCAN_CBT_EPSEG1_WIDTH
#define CAN_CBT_EPSEG1(x)               FLEXCAN_CBT_EPSEG1(x)

#define CAN_CBT_EPROPSEG_MASK           FLEXCAN_CBT_EPROPSEG_MASK
#define CAN_CBT_EPROPSEG_SHIFT          FLEXCAN_CBT_EPROPSEG_SHIFT
#define CAN_CBT_EPROPSEG_WIDTH          FLEXCAN_CBT_EPROPSEG_WIDTH
#define CAN_CBT_EPROPSEG(x)             FLEXCAN_CBT_EPROPSEG(x)

#define CAN_CBT_ERJW_MASK               FLEXCAN_CBT_ERJW_MASK
#define CAN_CBT_ERJW_SHIFT              FLEXCAN_CBT_ERJW_SHIFT
#define CAN_CBT_ERJW_WIDTH              FLEXCAN_CBT_ERJW_WIDTH
#define CAN_CBT_ERJW(x)                 FLEXCAN_CBT_ERJW(x)

#define CAN_CBT_EPRESDIV_MASK           FLEXCAN_CBT_EPRESDIV_MASK
#define CAN_CBT_EPRESDIV_SHIFT          FLEXCAN_CBT_EPRESDIV_SHIFT
#define CAN_CBT_EPRESDIV_WIDTH          FLEXCAN_CBT_EPRESDIV_WIDTH
#define CAN_CBT_EPRESDIV(x)             FLEXCAN_CBT_EPRESDIV(x)

#define CAN_CBT_BTF_MASK                FLEXCAN_CBT_BTF_MASK
#define CAN_CBT_BTF_SHIFT               FLEXCAN_CBT_BTF_SHIFT
#define CAN_CBT_BTF_WIDTH               FLEXCAN_CBT_BTF_WIDTH
#define CAN_CBT_BTF(x)                  FLEXCAN_CBT_BTF(x)
/*! @} */

/*! @name IMASK3 - Interrupt Masks 3 */
/*! @{ */

#define CAN_IMASK3_BUF95TO64M_MASK      FLEXCAN_IMASK3_BUF95TO64M_MASK
#define CAN_IMASK3_BUF95TO64M_SHIFT     FLEXCAN_IMASK3_BUF95TO64M_SHIFT
#define CAN_IMASK3_BUF95TO64M_WIDTH     FLEXCAN_IMASK3_BUF95TO64M_WIDTH
#define CAN_IMASK3_BUF95TO64M(x)        FLEXCAN_IMASK3_BUF95TO64M(x)
/*! @} */

/*! @name IFLAG3 - Interrupt Flags 3 */
/*! @{ */

#define CAN_IFLAG3_BUF95TO64_MASK       FLEXCAN_IFLAG3_BUF95TO64_MASK
#define CAN_IFLAG3_BUF95TO64_SHIFT      FLEXCAN_IFLAG3_BUF95TO64_SHIFT
#define CAN_IFLAG3_BUF95TO64_WIDTH      FLEXCAN_IFLAG3_BUF95TO64_WIDTH
#define CAN_IFLAG3_BUF95TO64(x)         FLEXCAN_IFLAG3_BUF95TO64(x)
/*! @} */

/*! @name ET - External Timer */
/*! @{ */

#define CAN_ET_TIMER_MASK               FLEXCAN_ET_TIMER_MASK
#define CAN_ET_TIMER_SHIFT              FLEXCAN_ET_TIMER_SHIFT
#define CAN_ET_TIMER_WIDTH              FLEXCAN_ET_TIMER_WIDTH
#define CAN_ET_TIMER(x)                 FLEXCAN_ET_TIMER(x)
/*! @} */

/*! @name FLTCONF_IE - Fault Confinement Interrupt Enable */
/*! @{ */

#define CAN_FLTCONF_IE_ATP_IE_MASK      FLEXCAN_FLTCONF_IE_ATP_IE_MASK
#define CAN_FLTCONF_IE_ATP_IE_SHIFT     FLEXCAN_FLTCONF_IE_ATP_IE_SHIFT
#define CAN_FLTCONF_IE_ATP_IE_WIDTH     FLEXCAN_FLTCONF_IE_ATP_IE_WIDTH
#define CAN_FLTCONF_IE_ATP_IE(x)        FLEXCAN_FLTCONF_IE_ATP_IE(x)

#define CAN_FLTCONF_IE_PTA_IE_MASK      FLEXCAN_FLTCONF_IE_PTA_IE_MASK
#define CAN_FLTCONF_IE_PTA_IE_SHIFT     FLEXCAN_FLTCONF_IE_PTA_IE_SHIFT
#define CAN_FLTCONF_IE_PTA_IE_WIDTH     FLEXCAN_FLTCONF_IE_PTA_IE_WIDTH
#define CAN_FLTCONF_IE_PTA_IE(x)        FLEXCAN_FLTCONF_IE_PTA_IE(x)
/*! @} */

/*! @name RXIMR - Receive Individual Mask */
/*! @{ */

#define CAN_RXIMR_MI_MASK               FLEXCAN_RXIMR_MI_MASK
#define CAN_RXIMR_MI_SHIFT              FLEXCAN_RXIMR_MI_SHIFT
#define CAN_RXIMR_MI_WIDTH              FLEXCAN_RXIMR_MI_WIDTH
#define CAN_RXIMR_MI(x)                 FLEXCAN_RXIMR_MI(x)
/*! @} */

/*! @name MECR - Memory Error Control */
/*! @{ */

#define CAN_MECR_NCEFAFRZ_MASK          FLEXCAN_MECR_NCEFAFRZ_MASK
#define CAN_MECR_NCEFAFRZ_SHIFT         FLEXCAN_MECR_NCEFAFRZ_SHIFT
#define CAN_MECR_NCEFAFRZ_WIDTH         FLEXCAN_MECR_NCEFAFRZ_WIDTH
#define CAN_MECR_NCEFAFRZ(x)            FLEXCAN_MECR_NCEFAFRZ(x)

#define CAN_MECR_ECCDIS_MASK            FLEXCAN_MECR_ECCDIS_MASK
#define CAN_MECR_ECCDIS_SHIFT           FLEXCAN_MECR_ECCDIS_SHIFT
#define CAN_MECR_ECCDIS_WIDTH           FLEXCAN_MECR_ECCDIS_WIDTH
#define CAN_MECR_ECCDIS(x)              FLEXCAN_MECR_ECCDIS(x)

#define CAN_MECR_RERRDIS_MASK           FLEXCAN_MECR_RERRDIS_MASK
#define CAN_MECR_RERRDIS_SHIFT          FLEXCAN_MECR_RERRDIS_SHIFT
#define CAN_MECR_RERRDIS_WIDTH          FLEXCAN_MECR_RERRDIS_WIDTH
#define CAN_MECR_RERRDIS(x)             FLEXCAN_MECR_RERRDIS(x)

#define CAN_MECR_EXTERRIE_MASK          FLEXCAN_MECR_EXTERRIE_MASK
#define CAN_MECR_EXTERRIE_SHIFT         FLEXCAN_MECR_EXTERRIE_SHIFT
#define CAN_MECR_EXTERRIE_WIDTH         FLEXCAN_MECR_EXTERRIE_WIDTH
#define CAN_MECR_EXTERRIE(x)            FLEXCAN_MECR_EXTERRIE(x)

#define CAN_MECR_FAERRIE_MASK           FLEXCAN_MECR_FAERRIE_MASK
#define CAN_MECR_FAERRIE_SHIFT          FLEXCAN_MECR_FAERRIE_SHIFT
#define CAN_MECR_FAERRIE_WIDTH          FLEXCAN_MECR_FAERRIE_WIDTH
#define CAN_MECR_FAERRIE(x)             FLEXCAN_MECR_FAERRIE(x)

#define CAN_MECR_HAERRIE_MASK           FLEXCAN_MECR_HAERRIE_MASK
#define CAN_MECR_HAERRIE_SHIFT          FLEXCAN_MECR_HAERRIE_SHIFT
#define CAN_MECR_HAERRIE_WIDTH          FLEXCAN_MECR_HAERRIE_WIDTH
#define CAN_MECR_HAERRIE(x)             FLEXCAN_MECR_HAERRIE(x)

#define CAN_MECR_ECRWRDIS_MASK          FLEXCAN_MECR_ECRWRDIS_MASK
#define CAN_MECR_ECRWRDIS_SHIFT         FLEXCAN_MECR_ECRWRDIS_SHIFT
#define CAN_MECR_ECRWRDIS_WIDTH         FLEXCAN_MECR_ECRWRDIS_WIDTH
#define CAN_MECR_ECRWRDIS(x)            FLEXCAN_MECR_ECRWRDIS(x)
/*! @} */

/*! @name ERRIAR - Error Injection Address */
/*! @{ */

#define CAN_ERRIAR_INJADDR_L_MASK       FLEXCAN_ERRIAR_INJADDR_L_MASK
#define CAN_ERRIAR_INJADDR_L_SHIFT      FLEXCAN_ERRIAR_INJADDR_L_SHIFT
#define CAN_ERRIAR_INJADDR_L_WIDTH      FLEXCAN_ERRIAR_INJADDR_L_WIDTH
#define CAN_ERRIAR_INJADDR_L(x)         FLEXCAN_ERRIAR_INJADDR_L(x)

#define CAN_ERRIAR_INJADDR_H_MASK       FLEXCAN_ERRIAR_INJADDR_H_MASK
#define CAN_ERRIAR_INJADDR_H_SHIFT      FLEXCAN_ERRIAR_INJADDR_H_SHIFT
#define CAN_ERRIAR_INJADDR_H_WIDTH      FLEXCAN_ERRIAR_INJADDR_H_WIDTH
#define CAN_ERRIAR_INJADDR_H(x)         FLEXCAN_ERRIAR_INJADDR_H(x)
/*! @} */

/*! @name ERRIDPR - Error Injection Data Pattern */
/*! @{ */

#define CAN_ERRIDPR_DFLIP_MASK          FLEXCAN_ERRIDPR_DFLIP_MASK
#define CAN_ERRIDPR_DFLIP_SHIFT         FLEXCAN_ERRIDPR_DFLIP_SHIFT
#define CAN_ERRIDPR_DFLIP_WIDTH         FLEXCAN_ERRIDPR_DFLIP_WIDTH
#define CAN_ERRIDPR_DFLIP(x)            FLEXCAN_ERRIDPR_DFLIP(x)
/*! @} */

/*! @name ERRIPPR - Error Injection Parity Pattern */
/*! @{ */

#define CAN_ERRIPPR_PFLIP0_MASK         FLEXCAN_ERRIPPR_PFLIP0_MASK
#define CAN_ERRIPPR_PFLIP0_SHIFT        FLEXCAN_ERRIPPR_PFLIP0_SHIFT
#define CAN_ERRIPPR_PFLIP0_WIDTH        FLEXCAN_ERRIPPR_PFLIP0_WIDTH
#define CAN_ERRIPPR_PFLIP0(x)           FLEXCAN_ERRIPPR_PFLIP0(x)

#define CAN_ERRIPPR_PFLIP1_MASK         FLEXCAN_ERRIPPR_PFLIP1_MASK
#define CAN_ERRIPPR_PFLIP1_SHIFT        FLEXCAN_ERRIPPR_PFLIP1_SHIFT
#define CAN_ERRIPPR_PFLIP1_WIDTH        FLEXCAN_ERRIPPR_PFLIP1_WIDTH
#define CAN_ERRIPPR_PFLIP1(x)           FLEXCAN_ERRIPPR_PFLIP1(x)

#define CAN_ERRIPPR_PFLIP2_MASK         FLEXCAN_ERRIPPR_PFLIP2_MASK
#define CAN_ERRIPPR_PFLIP2_SHIFT        FLEXCAN_ERRIPPR_PFLIP2_SHIFT
#define CAN_ERRIPPR_PFLIP2_WIDTH        FLEXCAN_ERRIPPR_PFLIP2_WIDTH
#define CAN_ERRIPPR_PFLIP2(x)           FLEXCAN_ERRIPPR_PFLIP2(x)

#define CAN_ERRIPPR_PFLIP3_MASK         FLEXCAN_ERRIPPR_PFLIP3_MASK
#define CAN_ERRIPPR_PFLIP3_SHIFT        FLEXCAN_ERRIPPR_PFLIP3_SHIFT
#define CAN_ERRIPPR_PFLIP3_WIDTH        FLEXCAN_ERRIPPR_PFLIP3_WIDTH
#define CAN_ERRIPPR_PFLIP3(x)           FLEXCAN_ERRIPPR_PFLIP3(x)
/*! @} */

/*! @name RERRAR - Error Report Address */
/*! @{ */

#define CAN_RERRAR_ERRADDR_MASK         FLEXCAN_RERRAR_ERRADDR_MASK
#define CAN_RERRAR_ERRADDR_SHIFT        FLEXCAN_RERRAR_ERRADDR_SHIFT
#define CAN_RERRAR_ERRADDR_WIDTH        FLEXCAN_RERRAR_ERRADDR_WIDTH
#define CAN_RERRAR_ERRADDR(x)           FLEXCAN_RERRAR_ERRADDR(x)

#define CAN_RERRAR_SAID_MASK            FLEXCAN_RERRAR_SAID_MASK
#define CAN_RERRAR_SAID_SHIFT           FLEXCAN_RERRAR_SAID_SHIFT
#define CAN_RERRAR_SAID_WIDTH           FLEXCAN_RERRAR_SAID_WIDTH
#define CAN_RERRAR_SAID(x)              FLEXCAN_RERRAR_SAID(x)

#define CAN_RERRAR_NCE_MASK             FLEXCAN_RERRAR_NCE_MASK
#define CAN_RERRAR_NCE_SHIFT            FLEXCAN_RERRAR_NCE_SHIFT
#define CAN_RERRAR_NCE_WIDTH            FLEXCAN_RERRAR_NCE_WIDTH
#define CAN_RERRAR_NCE(x)               FLEXCAN_RERRAR_NCE(x)
/*! @} */

/*! @name RERRDR - Error Report Data */
/*! @{ */

#define CAN_RERRDR_RDATA_MASK           FLEXCAN_RERRDR_RDATA_MASK
#define CAN_RERRDR_RDATA_SHIFT          FLEXCAN_RERRDR_RDATA_SHIFT
#define CAN_RERRDR_RDATA_WIDTH          FLEXCAN_RERRDR_RDATA_WIDTH
#define CAN_RERRDR_RDATA(x)             FLEXCAN_RERRDR_RDATA(x)
/*! @} */

/*! @name RERRSYNR - Error Report Syndrome */
/*! @{ */

#define CAN_RERRSYNR_SYND0_MASK         FLEXCAN_RERRSYNR_SYND0_MASK
#define CAN_RERRSYNR_SYND0_SHIFT        FLEXCAN_RERRSYNR_SYND0_SHIFT
#define CAN_RERRSYNR_SYND0_WIDTH        FLEXCAN_RERRSYNR_SYND0_WIDTH
#define CAN_RERRSYNR_SYND0(x)           FLEXCAN_RERRSYNR_SYND0(x)

#define CAN_RERRSYNR_BE0_MASK           FLEXCAN_RERRSYNR_BE0_MASK
#define CAN_RERRSYNR_BE0_SHIFT          FLEXCAN_RERRSYNR_BE0_SHIFT
#define CAN_RERRSYNR_BE0_WIDTH          FLEXCAN_RERRSYNR_BE0_WIDTH
#define CAN_RERRSYNR_BE0(x)             FLEXCAN_RERRSYNR_BE0(x)

#define CAN_RERRSYNR_SYND1_MASK         FLEXCAN_RERRSYNR_SYND1_MASK
#define CAN_RERRSYNR_SYND1_SHIFT        FLEXCAN_RERRSYNR_SYND1_SHIFT
#define CAN_RERRSYNR_SYND1_WIDTH        FLEXCAN_RERRSYNR_SYND1_WIDTH
#define CAN_RERRSYNR_SYND1(x)           FLEXCAN_RERRSYNR_SYND1(x)

#define CAN_RERRSYNR_BE1_MASK           FLEXCAN_RERRSYNR_BE1_MASK
#define CAN_RERRSYNR_BE1_SHIFT          FLEXCAN_RERRSYNR_BE1_SHIFT
#define CAN_RERRSYNR_BE1_WIDTH          FLEXCAN_RERRSYNR_BE1_WIDTH
#define CAN_RERRSYNR_BE1(x)             FLEXCAN_RERRSYNR_BE1(x)

#define CAN_RERRSYNR_SYND2_MASK         FLEXCAN_RERRSYNR_SYND2_MASK
#define CAN_RERRSYNR_SYND2_SHIFT        FLEXCAN_RERRSYNR_SYND2_SHIFT
#define CAN_RERRSYNR_SYND2_WIDTH        FLEXCAN_RERRSYNR_SYND2_WIDTH
#define CAN_RERRSYNR_SYND2(x)           FLEXCAN_RERRSYNR_SYND2(x)

#define CAN_RERRSYNR_BE2_MASK           FLEXCAN_RERRSYNR_BE2_MASK
#define CAN_RERRSYNR_BE2_SHIFT          FLEXCAN_RERRSYNR_BE2_SHIFT
#define CAN_RERRSYNR_BE2_WIDTH          FLEXCAN_RERRSYNR_BE2_WIDTH
#define CAN_RERRSYNR_BE2(x)             FLEXCAN_RERRSYNR_BE2(x)

#define CAN_RERRSYNR_SYND3_MASK         FLEXCAN_RERRSYNR_SYND3_MASK
#define CAN_RERRSYNR_SYND3_SHIFT        FLEXCAN_RERRSYNR_SYND3_SHIFT
#define CAN_RERRSYNR_SYND3_WIDTH        FLEXCAN_RERRSYNR_SYND3_WIDTH
#define CAN_RERRSYNR_SYND3(x)           FLEXCAN_RERRSYNR_SYND3(x)

#define CAN_RERRSYNR_BE3_MASK           FLEXCAN_RERRSYNR_BE3_MASK
#define CAN_RERRSYNR_BE3_SHIFT          FLEXCAN_RERRSYNR_BE3_SHIFT
#define CAN_RERRSYNR_BE3_WIDTH          FLEXCAN_RERRSYNR_BE3_WIDTH
#define CAN_RERRSYNR_BE3(x)             FLEXCAN_RERRSYNR_BE3(x)
/*! @} */

/*! @name ERRSR - Error Status */
/*! @{ */

#define CAN_ERRSR_CEIOF_MASK            FLEXCAN_ERRSR_CEIOF_MASK
#define CAN_ERRSR_CEIOF_SHIFT           FLEXCAN_ERRSR_CEIOF_SHIFT
#define CAN_ERRSR_CEIOF_WIDTH           FLEXCAN_ERRSR_CEIOF_WIDTH
#define CAN_ERRSR_CEIOF(x)              FLEXCAN_ERRSR_CEIOF(x)

#define CAN_ERRSR_FANCEIOF_MASK         FLEXCAN_ERRSR_FANCEIOF_MASK
#define CAN_ERRSR_FANCEIOF_SHIFT        FLEXCAN_ERRSR_FANCEIOF_SHIFT
#define CAN_ERRSR_FANCEIOF_WIDTH        FLEXCAN_ERRSR_FANCEIOF_WIDTH
#define CAN_ERRSR_FANCEIOF(x)           FLEXCAN_ERRSR_FANCEIOF(x)

#define CAN_ERRSR_HANCEIOF_MASK         FLEXCAN_ERRSR_HANCEIOF_MASK
#define CAN_ERRSR_HANCEIOF_SHIFT        FLEXCAN_ERRSR_HANCEIOF_SHIFT
#define CAN_ERRSR_HANCEIOF_WIDTH        FLEXCAN_ERRSR_HANCEIOF_WIDTH
#define CAN_ERRSR_HANCEIOF(x)           FLEXCAN_ERRSR_HANCEIOF(x)

#define CAN_ERRSR_CEIF_MASK             FLEXCAN_ERRSR_CEIF_MASK
#define CAN_ERRSR_CEIF_SHIFT            FLEXCAN_ERRSR_CEIF_SHIFT
#define CAN_ERRSR_CEIF_WIDTH            FLEXCAN_ERRSR_CEIF_WIDTH
#define CAN_ERRSR_CEIF(x)               FLEXCAN_ERRSR_CEIF(x)

#define CAN_ERRSR_FANCEIF_MASK          FLEXCAN_ERRSR_FANCEIF_MASK
#define CAN_ERRSR_FANCEIF_SHIFT         FLEXCAN_ERRSR_FANCEIF_SHIFT
#define CAN_ERRSR_FANCEIF_WIDTH         FLEXCAN_ERRSR_FANCEIF_WIDTH
#define CAN_ERRSR_FANCEIF(x)            FLEXCAN_ERRSR_FANCEIF(x)

#define CAN_ERRSR_HANCEIF_MASK          FLEXCAN_ERRSR_HANCEIF_MASK
#define CAN_ERRSR_HANCEIF_SHIFT         FLEXCAN_ERRSR_HANCEIF_SHIFT
#define CAN_ERRSR_HANCEIF_WIDTH         FLEXCAN_ERRSR_HANCEIF_WIDTH
#define CAN_ERRSR_HANCEIF(x)            FLEXCAN_ERRSR_HANCEIF(x)
/*! @} */

/*! @name EPRS - Enhanced CAN Bit Timing Prescalers */
/*! @{ */

#define CAN_EPRS_ENPRESDIV_MASK         FLEXCAN_EPRS_ENPRESDIV_MASK
#define CAN_EPRS_ENPRESDIV_SHIFT        FLEXCAN_EPRS_ENPRESDIV_SHIFT
#define CAN_EPRS_ENPRESDIV_WIDTH        FLEXCAN_EPRS_ENPRESDIV_WIDTH
#define CAN_EPRS_ENPRESDIV(x)           FLEXCAN_EPRS_ENPRESDIV(x)

#define CAN_EPRS_EDPRESDIV_MASK         FLEXCAN_EPRS_EDPRESDIV_MASK
#define CAN_EPRS_EDPRESDIV_SHIFT        FLEXCAN_EPRS_EDPRESDIV_SHIFT
#define CAN_EPRS_EDPRESDIV_WIDTH        FLEXCAN_EPRS_EDPRESDIV_WIDTH
#define CAN_EPRS_EDPRESDIV(x)           FLEXCAN_EPRS_EDPRESDIV(x)
/*! @} */

/*! @name ENCBT - Enhanced Nominal CAN Bit Timing */
/*! @{ */

#define CAN_ENCBT_NTSEG1_MASK           FLEXCAN_ENCBT_NTSEG1_MASK
#define CAN_ENCBT_NTSEG1_SHIFT          FLEXCAN_ENCBT_NTSEG1_SHIFT
#define CAN_ENCBT_NTSEG1_WIDTH          FLEXCAN_ENCBT_NTSEG1_WIDTH
#define CAN_ENCBT_NTSEG1(x)             FLEXCAN_ENCBT_NTSEG1(x)

#define CAN_ENCBT_NTSEG2_MASK           FLEXCAN_ENCBT_NTSEG2_MASK
#define CAN_ENCBT_NTSEG2_SHIFT          FLEXCAN_ENCBT_NTSEG2_SHIFT
#define CAN_ENCBT_NTSEG2_WIDTH          FLEXCAN_ENCBT_NTSEG2_WIDTH
#define CAN_ENCBT_NTSEG2(x)             FLEXCAN_ENCBT_NTSEG2(x)

#define CAN_ENCBT_NRJW_MASK             FLEXCAN_ENCBT_NRJW_MASK
#define CAN_ENCBT_NRJW_SHIFT            FLEXCAN_ENCBT_NRJW_SHIFT
#define CAN_ENCBT_NRJW_WIDTH            FLEXCAN_ENCBT_NRJW_WIDTH
#define CAN_ENCBT_NRJW(x)               FLEXCAN_ENCBT_NRJW(x)
/*! @} */

/*! @name EDCBT - Enhanced Data Phase CAN Bit Timing */
/*! @{ */

#define CAN_EDCBT_DTSEG1_MASK           FLEXCAN_EDCBT_DTSEG1_MASK
#define CAN_EDCBT_DTSEG1_SHIFT          FLEXCAN_EDCBT_DTSEG1_SHIFT
#define CAN_EDCBT_DTSEG1_WIDTH          FLEXCAN_EDCBT_DTSEG1_WIDTH
#define CAN_EDCBT_DTSEG1(x)             FLEXCAN_EDCBT_DTSEG1(x)

#define CAN_EDCBT_DTSEG2_MASK           FLEXCAN_EDCBT_DTSEG2_MASK
#define CAN_EDCBT_DTSEG2_SHIFT          FLEXCAN_EDCBT_DTSEG2_SHIFT
#define CAN_EDCBT_DTSEG2_WIDTH          FLEXCAN_EDCBT_DTSEG2_WIDTH
#define CAN_EDCBT_DTSEG2(x)             FLEXCAN_EDCBT_DTSEG2(x)

#define CAN_EDCBT_DRJW_MASK             FLEXCAN_EDCBT_DRJW_MASK
#define CAN_EDCBT_DRJW_SHIFT            FLEXCAN_EDCBT_DRJW_SHIFT
#define CAN_EDCBT_DRJW_WIDTH            FLEXCAN_EDCBT_DRJW_WIDTH
#define CAN_EDCBT_DRJW(x)               FLEXCAN_EDCBT_DRJW(x)
/*! @} */

/*! @name ETDC - Enhanced Transceiver Delay Compensation */
/*! @{ */

#define CAN_ETDC_ETDCVAL_MASK           FLEXCAN_ETDC_ETDCVAL_MASK
#define CAN_ETDC_ETDCVAL_SHIFT          FLEXCAN_ETDC_ETDCVAL_SHIFT
#define CAN_ETDC_ETDCVAL_WIDTH          FLEXCAN_ETDC_ETDCVAL_WIDTH
#define CAN_ETDC_ETDCVAL(x)             FLEXCAN_ETDC_ETDCVAL(x)

#define CAN_ETDC_ETDCFAIL_MASK          FLEXCAN_ETDC_ETDCFAIL_MASK
#define CAN_ETDC_ETDCFAIL_SHIFT         FLEXCAN_ETDC_ETDCFAIL_SHIFT
#define CAN_ETDC_ETDCFAIL_WIDTH         FLEXCAN_ETDC_ETDCFAIL_WIDTH
#define CAN_ETDC_ETDCFAIL(x)            FLEXCAN_ETDC_ETDCFAIL(x)

#define CAN_ETDC_ETDCOFF_MASK           FLEXCAN_ETDC_ETDCOFF_MASK
#define CAN_ETDC_ETDCOFF_SHIFT          FLEXCAN_ETDC_ETDCOFF_SHIFT
#define CAN_ETDC_ETDCOFF_WIDTH          FLEXCAN_ETDC_ETDCOFF_WIDTH
#define CAN_ETDC_ETDCOFF(x)             FLEXCAN_ETDC_ETDCOFF(x)

#define CAN_ETDC_TDMDIS_MASK            FLEXCAN_ETDC_TDMDIS_MASK
#define CAN_ETDC_TDMDIS_SHIFT           FLEXCAN_ETDC_TDMDIS_SHIFT
#define CAN_ETDC_TDMDIS_WIDTH           FLEXCAN_ETDC_TDMDIS_WIDTH
#define CAN_ETDC_TDMDIS(x)              FLEXCAN_ETDC_TDMDIS(x)

#define CAN_ETDC_ETDCEN_MASK            FLEXCAN_ETDC_ETDCEN_MASK
#define CAN_ETDC_ETDCEN_SHIFT           FLEXCAN_ETDC_ETDCEN_SHIFT
#define CAN_ETDC_ETDCEN_WIDTH           FLEXCAN_ETDC_ETDCEN_WIDTH
#define CAN_ETDC_ETDCEN(x)              FLEXCAN_ETDC_ETDCEN(x)
/*! @} */

/*! @name FDCTRL - CAN FD Control */
/*! @{ */

#define CAN_FDCTRL_TDCVAL_MASK          FLEXCAN_FDCTRL_TDCVAL_MASK
#define CAN_FDCTRL_TDCVAL_SHIFT         FLEXCAN_FDCTRL_TDCVAL_SHIFT
#define CAN_FDCTRL_TDCVAL_WIDTH         FLEXCAN_FDCTRL_TDCVAL_WIDTH
#define CAN_FDCTRL_TDCVAL(x)            FLEXCAN_FDCTRL_TDCVAL(x)

#define CAN_FDCTRL_TDCOFF_MASK          FLEXCAN_FDCTRL_TDCOFF_MASK
#define CAN_FDCTRL_TDCOFF_SHIFT         FLEXCAN_FDCTRL_TDCOFF_SHIFT
#define CAN_FDCTRL_TDCOFF_WIDTH         FLEXCAN_FDCTRL_TDCOFF_WIDTH
#define CAN_FDCTRL_TDCOFF(x)            FLEXCAN_FDCTRL_TDCOFF(x)

#define CAN_FDCTRL_TDCFAIL_MASK         FLEXCAN_FDCTRL_TDCFAIL_MASK
#define CAN_FDCTRL_TDCFAIL_SHIFT        FLEXCAN_FDCTRL_TDCFAIL_SHIFT
#define CAN_FDCTRL_TDCFAIL_WIDTH        FLEXCAN_FDCTRL_TDCFAIL_WIDTH
#define CAN_FDCTRL_TDCFAIL(x)           FLEXCAN_FDCTRL_TDCFAIL(x)

#define CAN_FDCTRL_TDCEN_MASK           FLEXCAN_FDCTRL_TDCEN_MASK
#define CAN_FDCTRL_TDCEN_SHIFT          FLEXCAN_FDCTRL_TDCEN_SHIFT
#define CAN_FDCTRL_TDCEN_WIDTH          FLEXCAN_FDCTRL_TDCEN_WIDTH
#define CAN_FDCTRL_TDCEN(x)             FLEXCAN_FDCTRL_TDCEN(x)

#define CAN_FDCTRL_MBDSR0_MASK          FLEXCAN_FDCTRL_MBDSR0_MASK
#define CAN_FDCTRL_MBDSR0_SHIFT         FLEXCAN_FDCTRL_MBDSR0_SHIFT
#define CAN_FDCTRL_MBDSR0_WIDTH         FLEXCAN_FDCTRL_MBDSR0_WIDTH
#define CAN_FDCTRL_MBDSR0(x)            FLEXCAN_FDCTRL_MBDSR0(x)

#define CAN_FDCTRL_MBDSR1_MASK          FLEXCAN_FDCTRL_MBDSR1_MASK
#define CAN_FDCTRL_MBDSR1_SHIFT         FLEXCAN_FDCTRL_MBDSR1_SHIFT
#define CAN_FDCTRL_MBDSR1_WIDTH         FLEXCAN_FDCTRL_MBDSR1_WIDTH
#define CAN_FDCTRL_MBDSR1(x)            FLEXCAN_FDCTRL_MBDSR1(x)

#define CAN_FDCTRL_MBDSR2_MASK          FLEXCAN_FDCTRL_MBDSR2_MASK
#define CAN_FDCTRL_MBDSR2_SHIFT         FLEXCAN_FDCTRL_MBDSR2_SHIFT
#define CAN_FDCTRL_MBDSR2_WIDTH         FLEXCAN_FDCTRL_MBDSR2_WIDTH
#define CAN_FDCTRL_MBDSR2(x)            FLEXCAN_FDCTRL_MBDSR2(x)

#define CAN_FDCTRL_FDRATE_MASK          FLEXCAN_FDCTRL_FDRATE_MASK
#define CAN_FDCTRL_FDRATE_SHIFT         FLEXCAN_FDCTRL_FDRATE_SHIFT
#define CAN_FDCTRL_FDRATE_WIDTH         FLEXCAN_FDCTRL_FDRATE_WIDTH
#define CAN_FDCTRL_FDRATE(x)            FLEXCAN_FDCTRL_FDRATE(x)
/*! @} */

/*! @name FDCBT - CAN FD Bit Timing */
/*! @{ */

#define CAN_FDCBT_FPSEG2_MASK           FLEXCAN_FDCBT_FPSEG2_MASK
#define CAN_FDCBT_FPSEG2_SHIFT          FLEXCAN_FDCBT_FPSEG2_SHIFT
#define CAN_FDCBT_FPSEG2_WIDTH          FLEXCAN_FDCBT_FPSEG2_WIDTH
#define CAN_FDCBT_FPSEG2(x)             FLEXCAN_FDCBT_FPSEG2(x)

#define CAN_FDCBT_FPSEG1_MASK           FLEXCAN_FDCBT_FPSEG1_MASK
#define CAN_FDCBT_FPSEG1_SHIFT          FLEXCAN_FDCBT_FPSEG1_SHIFT
#define CAN_FDCBT_FPSEG1_WIDTH          FLEXCAN_FDCBT_FPSEG1_WIDTH
#define CAN_FDCBT_FPSEG1(x)             FLEXCAN_FDCBT_FPSEG1(x)

#define CAN_FDCBT_FPROPSEG_MASK         FLEXCAN_FDCBT_FPROPSEG_MASK
#define CAN_FDCBT_FPROPSEG_SHIFT        FLEXCAN_FDCBT_FPROPSEG_SHIFT
#define CAN_FDCBT_FPROPSEG_WIDTH        FLEXCAN_FDCBT_FPROPSEG_WIDTH
#define CAN_FDCBT_FPROPSEG(x)           FLEXCAN_FDCBT_FPROPSEG(x)

#define CAN_FDCBT_FRJW_MASK             FLEXCAN_FDCBT_FRJW_MASK
#define CAN_FDCBT_FRJW_SHIFT            FLEXCAN_FDCBT_FRJW_SHIFT
#define CAN_FDCBT_FRJW_WIDTH            FLEXCAN_FDCBT_FRJW_WIDTH
#define CAN_FDCBT_FRJW(x)               FLEXCAN_FDCBT_FRJW(x)

#define CAN_FDCBT_FPRESDIV_MASK         FLEXCAN_FDCBT_FPRESDIV_MASK
#define CAN_FDCBT_FPRESDIV_SHIFT        FLEXCAN_FDCBT_FPRESDIV_SHIFT
#define CAN_FDCBT_FPRESDIV_WIDTH        FLEXCAN_FDCBT_FPRESDIV_WIDTH
#define CAN_FDCBT_FPRESDIV(x)           FLEXCAN_FDCBT_FPRESDIV(x)
/*! @} */

/*! @name FDCRC - CAN FD CRC */
/*! @{ */

#define CAN_FDCRC_FD_TXCRC_MASK         FLEXCAN_FDCRC_FD_TXCRC_MASK
#define CAN_FDCRC_FD_TXCRC_SHIFT        FLEXCAN_FDCRC_FD_TXCRC_SHIFT
#define CAN_FDCRC_FD_TXCRC_WIDTH        FLEXCAN_FDCRC_FD_TXCRC_WIDTH
#define CAN_FDCRC_FD_TXCRC(x)           FLEXCAN_FDCRC_FD_TXCRC(x)

#define CAN_FDCRC_FD_MBCRC_MASK         FLEXCAN_FDCRC_FD_MBCRC_MASK
#define CAN_FDCRC_FD_MBCRC_SHIFT        FLEXCAN_FDCRC_FD_MBCRC_SHIFT
#define CAN_FDCRC_FD_MBCRC_WIDTH        FLEXCAN_FDCRC_FD_MBCRC_WIDTH
#define CAN_FDCRC_FD_MBCRC(x)           FLEXCAN_FDCRC_FD_MBCRC(x)
/*! @} */

/*! @name ERFCR - Enhanced RX FIFO Control */
/*! @{ */

#define CAN_ERFCR_ERFWM_MASK            FLEXCAN_ERFCR_ERFWM_MASK
#define CAN_ERFCR_ERFWM_SHIFT           FLEXCAN_ERFCR_ERFWM_SHIFT
#define CAN_ERFCR_ERFWM_WIDTH           FLEXCAN_ERFCR_ERFWM_WIDTH
#define CAN_ERFCR_ERFWM(x)              FLEXCAN_ERFCR_ERFWM(x)

#define CAN_ERFCR_NFE_MASK              FLEXCAN_ERFCR_NFE_MASK
#define CAN_ERFCR_NFE_SHIFT             FLEXCAN_ERFCR_NFE_SHIFT
#define CAN_ERFCR_NFE_WIDTH             FLEXCAN_ERFCR_NFE_WIDTH
#define CAN_ERFCR_NFE(x)                FLEXCAN_ERFCR_NFE(x)

#define CAN_ERFCR_NEXIF_MASK            FLEXCAN_ERFCR_NEXIF_MASK
#define CAN_ERFCR_NEXIF_SHIFT           FLEXCAN_ERFCR_NEXIF_SHIFT
#define CAN_ERFCR_NEXIF_WIDTH           FLEXCAN_ERFCR_NEXIF_WIDTH
#define CAN_ERFCR_NEXIF(x)              FLEXCAN_ERFCR_NEXIF(x)

#define CAN_ERFCR_DMALW_MASK            FLEXCAN_ERFCR_DMALW_MASK
#define CAN_ERFCR_DMALW_SHIFT           FLEXCAN_ERFCR_DMALW_SHIFT
#define CAN_ERFCR_DMALW_WIDTH           FLEXCAN_ERFCR_DMALW_WIDTH
#define CAN_ERFCR_DMALW(x)              FLEXCAN_ERFCR_DMALW(x)

#define CAN_ERFCR_ERFEN_MASK            FLEXCAN_ERFCR_ERFEN_MASK
#define CAN_ERFCR_ERFEN_SHIFT           FLEXCAN_ERFCR_ERFEN_SHIFT
#define CAN_ERFCR_ERFEN_WIDTH           FLEXCAN_ERFCR_ERFEN_WIDTH
#define CAN_ERFCR_ERFEN(x)              FLEXCAN_ERFCR_ERFEN(x)
/*! @} */

/*! @name ERFIER - Enhanced RX FIFO Interrupt Enable */
/*! @{ */

#define CAN_ERFIER_ERFDAIE_MASK         FLEXCAN_ERFIER_ERFDAIE_MASK
#define CAN_ERFIER_ERFDAIE_SHIFT        FLEXCAN_ERFIER_ERFDAIE_SHIFT
#define CAN_ERFIER_ERFDAIE_WIDTH        FLEXCAN_ERFIER_ERFDAIE_WIDTH
#define CAN_ERFIER_ERFDAIE(x)           FLEXCAN_ERFIER_ERFDAIE(x)

#define CAN_ERFIER_ERFWMIIE_MASK        FLEXCAN_ERFIER_ERFWMIIE_MASK
#define CAN_ERFIER_ERFWMIIE_SHIFT       FLEXCAN_ERFIER_ERFWMIIE_SHIFT
#define CAN_ERFIER_ERFWMIIE_WIDTH       FLEXCAN_ERFIER_ERFWMIIE_WIDTH
#define CAN_ERFIER_ERFWMIIE(x)          FLEXCAN_ERFIER_ERFWMIIE(x)

#define CAN_ERFIER_ERFOVFIE_MASK        FLEXCAN_ERFIER_ERFOVFIE_MASK
#define CAN_ERFIER_ERFOVFIE_SHIFT       FLEXCAN_ERFIER_ERFOVFIE_SHIFT
#define CAN_ERFIER_ERFOVFIE_WIDTH       FLEXCAN_ERFIER_ERFOVFIE_WIDTH
#define CAN_ERFIER_ERFOVFIE(x)          FLEXCAN_ERFIER_ERFOVFIE(x)

#define CAN_ERFIER_ERFUFWIE_MASK        FLEXCAN_ERFIER_ERFUFWIE_MASK
#define CAN_ERFIER_ERFUFWIE_SHIFT       FLEXCAN_ERFIER_ERFUFWIE_SHIFT
#define CAN_ERFIER_ERFUFWIE_WIDTH       FLEXCAN_ERFIER_ERFUFWIE_WIDTH
#define CAN_ERFIER_ERFUFWIE(x)          FLEXCAN_ERFIER_ERFUFWIE(x)
/*! @} */

/*! @name ERFSR - Enhanced RX FIFO Status */
/*! @{ */

#define CAN_ERFSR_ERFEL_MASK            FLEXCAN_ERFSR_ERFEL_MASK
#define CAN_ERFSR_ERFEL_SHIFT           FLEXCAN_ERFSR_ERFEL_SHIFT
#define CAN_ERFSR_ERFEL_WIDTH           FLEXCAN_ERFSR_ERFEL_WIDTH
#define CAN_ERFSR_ERFEL(x)              FLEXCAN_ERFSR_ERFEL(x)

#define CAN_ERFSR_ERFF_MASK             FLEXCAN_ERFSR_ERFF_MASK
#define CAN_ERFSR_ERFF_SHIFT            FLEXCAN_ERFSR_ERFF_SHIFT
#define CAN_ERFSR_ERFF_WIDTH            FLEXCAN_ERFSR_ERFF_WIDTH
#define CAN_ERFSR_ERFF(x)               FLEXCAN_ERFSR_ERFF(x)

#define CAN_ERFSR_ERFE_MASK             FLEXCAN_ERFSR_ERFE_MASK
#define CAN_ERFSR_ERFE_SHIFT            FLEXCAN_ERFSR_ERFE_SHIFT
#define CAN_ERFSR_ERFE_WIDTH            FLEXCAN_ERFSR_ERFE_WIDTH
#define CAN_ERFSR_ERFE(x)               FLEXCAN_ERFSR_ERFE(x)

#define CAN_ERFSR_ERFCLR_MASK           FLEXCAN_ERFSR_ERFCLR_MASK
#define CAN_ERFSR_ERFCLR_SHIFT          FLEXCAN_ERFSR_ERFCLR_SHIFT
#define CAN_ERFSR_ERFCLR_WIDTH          FLEXCAN_ERFSR_ERFCLR_WIDTH
#define CAN_ERFSR_ERFCLR(x)             FLEXCAN_ERFSR_ERFCLR(x)

#define CAN_ERFSR_ERFDA_MASK            FLEXCAN_ERFSR_ERFDA_MASK
#define CAN_ERFSR_ERFDA_SHIFT           FLEXCAN_ERFSR_ERFDA_SHIFT
#define CAN_ERFSR_ERFDA_WIDTH           FLEXCAN_ERFSR_ERFDA_WIDTH
#define CAN_ERFSR_ERFDA(x)              FLEXCAN_ERFSR_ERFDA(x)

#define CAN_ERFSR_ERFWMI_MASK           FLEXCAN_ERFSR_ERFWMI_MASK
#define CAN_ERFSR_ERFWMI_SHIFT          FLEXCAN_ERFSR_ERFWMI_SHIFT
#define CAN_ERFSR_ERFWMI_WIDTH          FLEXCAN_ERFSR_ERFWMI_WIDTH
#define CAN_ERFSR_ERFWMI(x)             FLEXCAN_ERFSR_ERFWMI(x)

#define CAN_ERFSR_ERFOVF_MASK           FLEXCAN_ERFSR_ERFOVF_MASK
#define CAN_ERFSR_ERFOVF_SHIFT          FLEXCAN_ERFSR_ERFOVF_SHIFT
#define CAN_ERFSR_ERFOVF_WIDTH          FLEXCAN_ERFSR_ERFOVF_WIDTH
#define CAN_ERFSR_ERFOVF(x)             FLEXCAN_ERFSR_ERFOVF(x)

#define CAN_ERFSR_ERFUFW_MASK           FLEXCAN_ERFSR_ERFUFW_MASK
#define CAN_ERFSR_ERFUFW_SHIFT          FLEXCAN_ERFSR_ERFUFW_SHIFT
#define CAN_ERFSR_ERFUFW_WIDTH          FLEXCAN_ERFSR_ERFUFW_WIDTH
#define CAN_ERFSR_ERFUFW(x)             FLEXCAN_ERFSR_ERFUFW(x)
/*! @} */

/*! @name HR_TIME_STAMP - High-Resolution Timestamp */
/*! @{ */

#define CAN_HR_TIME_STAMP_TS_MASK       FLEXCAN_HR_TIME_STAMP_TS_MASK
#define CAN_HR_TIME_STAMP_TS_SHIFT      FLEXCAN_HR_TIME_STAMP_TS_SHIFT
#define CAN_HR_TIME_STAMP_TS_WIDTH      FLEXCAN_HR_TIME_STAMP_TS_WIDTH
#define CAN_HR_TIME_STAMP_TS(x)         FLEXCAN_HR_TIME_STAMP_TS(x)
/*! @} */

/*! @name ERFFEL - Enhanced RX FIFO Filter Element */
/*! @{ */

#define CAN_ERFFEL_FEL_MASK             FLEXCAN_ERFFEL_FEL_MASK
#define CAN_ERFFEL_FEL_SHIFT            FLEXCAN_ERFFEL_FEL_SHIFT
#define CAN_ERFFEL_FEL_WIDTH            FLEXCAN_ERFFEL_FEL_WIDTH
#define CAN_ERFFEL_FEL(x)               FLEXCAN_ERFFEL_FEL(x)
/*! @} */


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


/* The count of CAN_WORD1 */
#define CAN_WORD1_COUNT (96U)

/*!
 * @}
 */ /* end of group FLEXCAN_Register_Masks */

/*!
 * @}
 */ /* end of group FLEXCAN_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Register Layout Typedef */
typedef struct
{
  __IO uint32_t MP_CSR;                               /**< Management Page Control, offset: 0x0 */
  __I uint32_t MP_ES;                                /**< Management Page Error Status, offset: 0x4 */
  __I uint32_t MP_INT;                               /**< Management Page Interrupt Request Status, offset: 0x8 */
  __I uint32_t MP_HRS;                               /**< Management Page Hardware Request Status, offset: 0xC */
      uint8_t RESERVED_0[240];
  __IO uint32_t CH_GRPRI[12];                      /**< Channel Arbitration Group, array offset: 0x100, array step: 0x4 */
      uint8_t RESERVED_1[16080];
  struct
  {
      __IO uint32_t CH_CSR;                           /**< Channel Control and Status, offset: 0x0 */
      __IO uint32_t CH_ES;                            /**< Channel Error Status, offset: 0x4 */
      __IO uint32_t CH_INT;                           /**< Channel Interrupt Status, offset: 0x8 */
      __IO uint32_t CH_SBR;                           /**< Channel System Bus, offset: 0xC */
      __IO uint32_t CH_PRI;                           /**< Channel Priority, offset: 0x10 */
      uint8_t RESERVED_0[12];
      __IO uint32_t TCD_SADDR;                        /**< TCD Source Address, offset: 0x20 */
      __IO uint16_t TCD_SOFF;                         /**< TCD Signed Source Address Offset, offset: 0x24 */
      __IO uint16_t TCD_ATTR;                         /**< TCD Transfer Attributes, offset: 0x26 */
      union {                                          /* offset: 0x28 */
         __IO uint32_t TCD_NBYTES_MLOFFNO;               /**< TCD Transfer Size Without Minor Loop Offsets, offset: 0x28 */
         __IO uint32_t TCD_NBYTES_MLOFFYES;              /**< TCD Transfer Size with Minor Loop Offsets, offset: 0x28 */
      };
      __IO uint32_t TCD_SLAST_SDA;                    /**< TCD Last Source Address Adjustment / Store DADDR Address, offset: 0x2C */
      __IO uint32_t TCD_DADDR;                        /**< TCD Destination Address, offset: 0x30 */
      __IO uint16_t TCD_DOFF;                         /**< TCD Signed Destination Address Offset, offset: 0x34 */
      union {                                          /* offset: 0x36 */
         __IO uint16_t TCD_CITER_ELINKNO;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x36 */
         __IO uint16_t TCD_CITER_ELINKYES;               /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x36 */
      };
      __IO uint32_t TCD_DLAST_SGA;                    /**< TCD Last Destination Address Adjustment / Scatter Gather Address, offset: 0x38 */
      __IO uint16_t TCD_CSR;                          /**< TCD Control and Status, offset: 0x3C */
      union {                                          /* offset: 0x3E */
         __IO uint16_t TCD_BITER_ELINKNO;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), offset: 0x3E */
         __IO uint16_t TCD_BITER_ELINKYES;               /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), offset: 0x3E */
      };
      uint8_t RESERVED_1[16320];
  } CH[12];
} DMA_Type;



/* ----------------------------------------------------------------------------
   -- LPE_EDMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPE_EDMA_Register_Masks LPE_EDMA Register Masks
 * @{
 */

/*! @name CSR - Management Page Control */
/*! @{ */

#define DMA_MP_CSR_EDBG_MASK                       LPE_EDMA_MP_CSR_EDBG_MASK
#define DMA_MP_CSR_EDBG_SHIFT                      LPE_EDMA_MP_CSR_EDBG_SHIFT
#define DMA_MP_CSR_EDBG_WIDTH                      LPE_EDMA_MP_CSR_EDBG_WIDTH
#define DMA_MP_CSR_EDBG(x)                         LPE_EDMA_MP_CSR_EDBG(x)

#define DMA_MP_CSR_ERCA_MASK                       LPE_EDMA_MP_CSR_ERCA_MASK
#define DMA_MP_CSR_ERCA_SHIFT                      LPE_EDMA_MP_CSR_ERCA_SHIFT
#define DMA_MP_CSR_ERCA_WIDTH                      LPE_EDMA_MP_CSR_ERCA_WIDTH
#define DMA_MP_CSR_ERCA(x)                         LPE_EDMA_MP_CSR_ERCA(x)

#define DMA_MP_CSR_HAE_MASK                        LPE_EDMA_MP_CSR_HAE_MASK
#define DMA_MP_CSR_HAE_SHIFT                       LPE_EDMA_MP_CSR_HAE_SHIFT
#define DMA_MP_CSR_HAE_WIDTH                       LPE_EDMA_MP_CSR_HAE_WIDTH
#define DMA_MP_CSR_HAE(x)                          LPE_EDMA_MP_CSR_HAE(x)

#define DMA_MP_CSR_HALT_MASK                       LPE_EDMA_MP_CSR_HALT_MASK
#define DMA_MP_CSR_HALT_SHIFT                      LPE_EDMA_MP_CSR_HALT_SHIFT
#define DMA_MP_CSR_HALT_WIDTH                      LPE_EDMA_MP_CSR_HALT_WIDTH
#define DMA_MP_CSR_HALT(x)                         LPE_EDMA_MP_CSR_HALT(x)

#define DMA_MP_CSR_GCLC_MASK                       LPE_EDMA_MP_CSR_GCLC_MASK
#define DMA_MP_CSR_GCLC_SHIFT                      LPE_EDMA_MP_CSR_GCLC_SHIFT
#define DMA_MP_CSR_GCLC_WIDTH                      LPE_EDMA_MP_CSR_GCLC_WIDTH
#define DMA_MP_CSR_GCLC(x)                         LPE_EDMA_MP_CSR_GCLC(x)

#define DMA_MP_CSR_GMRC_MASK                       LPE_EDMA_MP_CSR_GMRC_MASK
#define DMA_MP_CSR_GMRC_SHIFT                      LPE_EDMA_MP_CSR_GMRC_SHIFT
#define DMA_MP_CSR_GMRC_WIDTH                      LPE_EDMA_MP_CSR_GMRC_WIDTH
#define DMA_MP_CSR_GMRC(x)                         LPE_EDMA_MP_CSR_GMRC(x)

#define DMA_MP_CSR_ECX_MASK                        LPE_EDMA_MP_CSR_ECX_MASK
#define DMA_MP_CSR_ECX_SHIFT                       LPE_EDMA_MP_CSR_ECX_SHIFT
#define DMA_MP_CSR_ECX_WIDTH                       LPE_EDMA_MP_CSR_ECX_WIDTH
#define DMA_MP_CSR_ECX(x)                          LPE_EDMA_MP_CSR_ECX(x)

#define DMA_MP_CSR_CX_MASK                         LPE_EDMA_MP_CSR_CX_MASK
#define DMA_MP_CSR_CX_SHIFT                        LPE_EDMA_MP_CSR_CX_SHIFT
#define DMA_MP_CSR_CX_WIDTH                        LPE_EDMA_MP_CSR_CX_WIDTH
#define DMA_MP_CSR_CX(x)                           LPE_EDMA_MP_CSR_CX(x)

#define DMA_MP_CSR_ACTIVE_ID_MASK                  LPE_EDMA_MP_CSR_ACTIVE_ID_MASK
#define DMA_MP_CSR_ACTIVE_ID_SHIFT                 LPE_EDMA_MP_CSR_ACTIVE_ID_SHIFT
#define DMA_MP_CSR_ACTIVE_ID_WIDTH                 LPE_EDMA_MP_CSR_ACTIVE_ID_WIDTH
#define DMA_MP_CSR_ACTIVE_ID(x)                    LPE_EDMA_MP_CSR_ACTIVE_ID(x)

#define DMA_MP_CSR_ACTIVE_MASK                     LPE_EDMA_MP_CSR_ACTIVE_MASK
#define DMA_MP_CSR_ACTIVE_SHIFT                    LPE_EDMA_MP_CSR_ACTIVE_SHIFT
#define DMA_MP_CSR_ACTIVE_WIDTH                    LPE_EDMA_MP_CSR_ACTIVE_WIDTH
#define DMA_MP_CSR_ACTIVE(x)                       LPE_EDMA_MP_CSR_ACTIVE(x)

#define DMA_MP_CSR_EBW_MASK                        LPE_EDMA_TCD_CH0_CSR_EBW_MASK
#define DMA_MP_CSR_EBW_SHIFT                       LPE_EDMA_TCD_CH0_CSR_EBW_SHIFT
#define DMA_MP_CSR_EBW_WIDTH                       LPE_EDMA_TCD_CH0_CSR_EBW_WIDTH
#define DMA_MP_CSR_EBW(x)                          LPE_EDMA_TCD_CH0_CSR_EBW(x)

/*! @} */

/*! @name ES - Management Page Error Status */
/*! @{ */

#define DMA_MP_ES_DBE_MASK                         LPE_EDMA_MP_ES_DBE_MASK
#define DMA_MP_ES_DBE_SHIFT                        LPE_EDMA_MP_ES_DBE_SHIFT
#define DMA_MP_ES_DBE_WIDTH                        LPE_EDMA_MP_ES_DBE_WIDTH
#define DMA_MP_ES_DBE(x)                           LPE_EDMA_MP_ES_DBE(x)

#define DMA_MP_ES_SBE_MASK                         LPE_EDMA_MP_ES_SBE_MASK
#define DMA_MP_ES_SBE_SHIFT                        LPE_EDMA_MP_ES_SBE_SHIFT
#define DMA_MP_ES_SBE_WIDTH                        LPE_EDMA_MP_ES_SBE_WIDTH
#define DMA_MP_ES_SBE(x)                           LPE_EDMA_MP_ES_SBE(x)

#define DMA_MP_ES_SGE_MASK                         LPE_EDMA_MP_ES_SGE_MASK
#define DMA_MP_ES_SGE_SHIFT                        LPE_EDMA_MP_ES_SGE_SHIFT
#define DMA_MP_ES_SGE_WIDTH                        LPE_EDMA_MP_ES_SGE_WIDTH
#define DMA_MP_ES_SGE(x)                           LPE_EDMA_MP_ES_SGE(x)

#define DMA_MP_ES_NCE_MASK                         LPE_EDMA_MP_ES_NCE_MASK
#define DMA_MP_ES_NCE_SHIFT                        LPE_EDMA_MP_ES_NCE_SHIFT
#define DMA_MP_ES_NCE_WIDTH                        LPE_EDMA_MP_ES_NCE_WIDTH
#define DMA_MP_ES_NCE(x)                           LPE_EDMA_MP_ES_NCE(x)

#define DMA_MP_ES_DOE_MASK                         LPE_EDMA_MP_ES_DOE_MASK
#define DMA_MP_ES_DOE_SHIFT                        LPE_EDMA_MP_ES_DOE_SHIFT
#define DMA_MP_ES_DOE_WIDTH                        LPE_EDMA_MP_ES_DOE_WIDTH
#define DMA_MP_ES_DOE(x)                           LPE_EDMA_MP_ES_DOE(x)

#define DMA_MP_ES_DAE_MASK                         LPE_EDMA_MP_ES_DAE_MASK
#define DMA_MP_ES_DAE_SHIFT                        LPE_EDMA_MP_ES_DAE_SHIFT
#define DMA_MP_ES_DAE_WIDTH                        LPE_EDMA_MP_ES_DAE_WIDTH
#define DMA_MP_ES_DAE(x)                           LPE_EDMA_MP_ES_DAE(x)

#define DMA_MP_ES_SOE_MASK                         LPE_EDMA_MP_ES_SOE_MASK
#define DMA_MP_ES_SOE_SHIFT                        LPE_EDMA_MP_ES_SOE_SHIFT
#define DMA_MP_ES_SOE_WIDTH                        LPE_EDMA_MP_ES_SOE_WIDTH
#define DMA_MP_ES_SOE(x)                           LPE_EDMA_MP_ES_SOE(x)

#define DMA_MP_ES_SAE_MASK                         LPE_EDMA_MP_ES_SAE_MASK
#define DMA_MP_ES_SAE_SHIFT                        LPE_EDMA_MP_ES_SAE_SHIFT
#define DMA_MP_ES_SAE_WIDTH                        LPE_EDMA_MP_ES_SAE_WIDTH
#define DMA_MP_ES_SAE(x)                           LPE_EDMA_MP_ES_SAE(x)

#define DMA_MP_ES_ECX_MASK                         LPE_EDMA_MP_ES_ECX_MASK
#define DMA_MP_ES_ECX_SHIFT                        LPE_EDMA_MP_ES_ECX_SHIFT
#define DMA_MP_ES_ECX_WIDTH                        LPE_EDMA_MP_ES_ECX_WIDTH
#define DMA_MP_ES_ECX(x)                           LPE_EDMA_MP_ES_ECX(x)

#define DMA_MP_ES_UCE_MASK                         LPE_EDMA_MP_ES_UCE_MASK
#define DMA_MP_ES_UCE_SHIFT                        LPE_EDMA_MP_ES_UCE_SHIFT
#define DMA_MP_ES_UCE_WIDTH                        LPE_EDMA_MP_ES_UCE_WIDTH
#define DMA_MP_ES_UCE(x)                           LPE_EDMA_MP_ES_UCE(x)

#define DMA_MP_ES_ERRCHN_MASK                      LPE_EDMA_MP_ES_ERRCHN_MASK
#define DMA_MP_ES_ERRCHN_SHIFT                     LPE_EDMA_MP_ES_ERRCHN_SHIFT
#define DMA_MP_ES_ERRCHN_WIDTH                     LPE_EDMA_MP_ES_ERRCHN_WIDTH
#define DMA_MP_ES_ERRCHN(x)                        LPE_EDMA_MP_ES_ERRCHN(x)

#define DMA_MP_ES_VLD_MASK                         LPE_EDMA_MP_ES_VLD_MASK
#define DMA_MP_ES_VLD_SHIFT                        LPE_EDMA_MP_ES_VLD_SHIFT
#define DMA_MP_ES_VLD_WIDTH                        LPE_EDMA_MP_ES_VLD_WIDTH
#define DMA_MP_ES_VLD(x)                           LPE_EDMA_MP_ES_VLD(x)
/*! @} */

/*! @name INT - Management Page Interrupt Request Status */
/*! @{ */

#define DMA_MP_INT_INT_MASK                        LPE_EDMA_MP_INT_INT_MASK
#define DMA_MP_INT_INT_SHIFT                       LPE_EDMA_MP_INT_INT_SHIFT
#define DMA_MP_INT_INT_WIDTH                       LPE_EDMA_MP_INT_INT_WIDTH
#define DMA_MP_INT_INT(x)                          LPE_EDMA_MP_INT_INT(x)
/*! @} */

/*! @name HRS - Management Page Hardware Request Status */
/*! @{ */

#define DMA_MP_HRS_HRS_MASK                        LPE_EDMA_MP_HRS_HRS_MASK
#define DMA_MP_HRS_HRS_SHIFT                       LPE_EDMA_MP_HRS_HRS_SHIFT
#define DMA_MP_HRS_HRS_WIDTH                       LPE_EDMA_MP_HRS_HRS_WIDTH
#define DMA_MP_HRS_HRS(x)                          LPE_EDMA_MP_HRS_HRS(x)
/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group */
/*! @{ */

#define DMA_CH_GRPRI_GRPRI_MASK                    LPE_EDMA_MP_CH_GRPRI_GRPRI_MASK
#define DMA_CH_GRPRI_GRPRI_SHIFT                   LPE_EDMA_MP_CH_GRPRI_GRPRI_SHIFT
#define DMA_CH_GRPRI_GRPRI_WIDTH                   LPE_EDMA_MP_CH_GRPRI_GRPRI_WIDTH
#define DMA_CH_GRPRI_GRPRI(x)                      LPE_EDMA_MP_CH_GRPRI_GRPRI(x)
/*! @} */

/*!
 * @}
 */ /* end of group LPE_EDMA_Register_Masks */

/* ----------------------------------------------------------------------------
   -- LPE_EDMA_TCD_TCD0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPE_EDMA_TCD_TCD0_Register_Masks LPE_EDMA_TCD_TCD0 Register Masks
 * @{
 */

/*! @name CH_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH_CSR_ERQ_MASK                        LPE_EDMA_TCD_CH0_CSR_ERQ_MASK
#define DMA_CH_CSR_ERQ_SHIFT                       LPE_EDMA_TCD_CH0_CSR_ERQ_SHIFT
#define DMA_CH_CSR_ERQ_WIDTH                       LPE_EDMA_TCD_CH0_CSR_ERQ_WIDTH
#define DMA_CH_CSR_ERQ(x)                          LPE_EDMA_TCD_CH0_CSR_ERQ(x)

#define DMA_CH_CSR_EARQ_MASK                       LPE_EDMA_TCD_CH0_CSR_EARQ_MASK
#define DMA_CH_CSR_EARQ_SHIFT                      LPE_EDMA_TCD_CH0_CSR_EARQ_SHIFT
#define DMA_CH_CSR_EARQ_WIDTH                      LPE_EDMA_TCD_CH0_CSR_EARQ_WIDTH
#define DMA_CH_CSR_EARQ(x)                         LPE_EDMA_TCD_CH0_CSR_EARQ(x)

#define DMA_CH_CSR_EEI_MASK                        LPE_EDMA_TCD_CH0_CSR_EEI_MASK
#define DMA_CH_CSR_EEI_SHIFT                       LPE_EDMA_TCD_CH0_CSR_EEI_SHIFT
#define DMA_CH_CSR_EEI_WIDTH                       LPE_EDMA_TCD_CH0_CSR_EEI_WIDTH
#define DMA_CH_CSR_EEI(x)                          LPE_EDMA_TCD_CH0_CSR_EEI(x)

#define DMA_CH_CSR_EBW_MASK                        LPE_EDMA_TCD_CH0_CSR_EBW_MASK
#define DMA_CH_CSR_EBW_SHIFT                       LPE_EDMA_TCD_CH0_CSR_EBW_SHIFT
#define DMA_CH_CSR_EBW_WIDTH                       LPE_EDMA_TCD_CH0_CSR_EBW_WIDTH
#define DMA_CH_CSR_EBW(x)                          LPE_EDMA_TCD_CH0_CSR_EBW(x)

#define DMA_CH_CSR_DONE_MASK                       LPE_EDMA_TCD_CH0_CSR_DONE_MASK
#define DMA_CH_CSR_DONE_SHIFT                      LPE_EDMA_TCD_CH0_CSR_DONE_SHIFT
#define DMA_CH_CSR_DONE_WIDTH                      LPE_EDMA_TCD_CH0_CSR_DONE_WIDTH
#define DMA_CH_CSR_DONE(x)                         LPE_EDMA_TCD_CH0_CSR_DONE(x)

#define DMA_CH_CSR_ACTIVE_MASK                     LPE_EDMA_TCD_CH0_CSR_ACTIVE_MASK
#define DMA_CH_CSR_ACTIVE_SHIFT                    LPE_EDMA_TCD_CH0_CSR_ACTIVE_SHIFT
#define DMA_CH_CSR_ACTIVE_WIDTH                    LPE_EDMA_TCD_CH0_CSR_ACTIVE_WIDTH
#define DMA_CH_CSR_ACTIVE(x)                       LPE_EDMA_TCD_CH0_CSR_ACTIVE(x)
/*! @} */

/*! @name CH_ES - Channel Error Status */
/*! @{ */

#define DMA_CH_ES_DBE_MASK                         LPE_EDMA_TCD_CH0_ES_DBE_MASK
#define DMA_CH_ES_DBE_SHIFT                        LPE_EDMA_TCD_CH0_ES_DBE_SHIFT
#define DMA_CH_ES_DBE_WIDTH                        LPE_EDMA_TCD_CH0_ES_DBE_WIDTH
#define DMA_CH_ES_DBE(x)                           LPE_EDMA_TCD_CH0_ES_DBE(x)

#define DMA_CH_ES_SBE_MASK                         LPE_EDMA_TCD_CH0_ES_SBE_MASK
#define DMA_CH_ES_SBE_SHIFT                        LPE_EDMA_TCD_CH0_ES_SBE_SHIFT
#define DMA_CH_ES_SBE_WIDTH                        LPE_EDMA_TCD_CH0_ES_SBE_WIDTH
#define DMA_CH_ES_SBE(x)                           LPE_EDMA_TCD_CH0_ES_SBE(x)

#define DMA_CH_ES_SGE_MASK                         LPE_EDMA_TCD_CH0_ES_SGE_MASK
#define DMA_CH_ES_SGE_SHIFT                        LPE_EDMA_TCD_CH0_ES_SGE_SHIFT
#define DMA_CH_ES_SGE_WIDTH                        LPE_EDMA_TCD_CH0_ES_SGE_WIDTH
#define DMA_CH_ES_SGE(x)                           LPE_EDMA_TCD_CH0_ES_SGE(x)

#define DMA_CH_ES_NCE_MASK                         LPE_EDMA_TCD_CH0_ES_NCE_MASK
#define DMA_CH_ES_NCE_SHIFT                        LPE_EDMA_TCD_CH0_ES_NCE_SHIFT
#define DMA_CH_ES_NCE_WIDTH                        LPE_EDMA_TCD_CH0_ES_NCE_WIDTH
#define DMA_CH_ES_NCE(x)                           LPE_EDMA_TCD_CH0_ES_NCE(x)

#define DMA_CH_ES_DOE_MASK                         LPE_EDMA_TCD_CH0_ES_DOE_MASK
#define DMA_CH_ES_DOE_SHIFT                        LPE_EDMA_TCD_CH0_ES_DOE_SHIFT
#define DMA_CH_ES_DOE_WIDTH                        LPE_EDMA_TCD_CH0_ES_DOE_WIDTH
#define DMA_CH_ES_DOE(x)                           LPE_EDMA_TCD_CH0_ES_DOE(x)

#define DMA_CH_ES_DAE_MASK                         LPE_EDMA_TCD_CH0_ES_DAE_MASK
#define DMA_CH_ES_DAE_SHIFT                        LPE_EDMA_TCD_CH0_ES_DAE_SHIFT
#define DMA_CH_ES_DAE_WIDTH                        LPE_EDMA_TCD_CH0_ES_DAE_WIDTH
#define DMA_CH_ES_DAE(x)                           LPE_EDMA_TCD_CH0_ES_DAE(x)

#define DMA_CH_ES_SOE_MASK                         LPE_EDMA_TCD_CH0_ES_SOE_MASK
#define DMA_CH_ES_SOE_SHIFT                        LPE_EDMA_TCD_CH0_ES_SOE_SHIFT
#define DMA_CH_ES_SOE_WIDTH                        LPE_EDMA_TCD_CH0_ES_SOE_WIDTH
#define DMA_CH_ES_SOE(x)                           LPE_EDMA_TCD_CH0_ES_SOE(x)

#define DMA_CH_ES_SAE_MASK                         LPE_EDMA_TCD_CH0_ES_SAE_MASK
#define DMA_CH_ES_SAE_SHIFT                        LPE_EDMA_TCD_CH0_ES_SAE_SHIFT
#define DMA_CH_ES_SAE_WIDTH                        LPE_EDMA_TCD_CH0_ES_SAE_WIDTH
#define DMA_CH_ES_SAE(x)                           LPE_EDMA_TCD_CH0_ES_SAE(x)

#define DMA_CH_ES_ERR_MASK                         LPE_EDMA_TCD_CH0_ES_ERR_MASK
#define DMA_CH_ES_ERR_SHIFT                        LPE_EDMA_TCD_CH0_ES_ERR_SHIFT
#define DMA_CH_ES_ERR_WIDTH                        LPE_EDMA_TCD_CH0_ES_ERR_WIDTH
#define DMA_CH_ES_ERR(x)                           LPE_EDMA_TCD_CH0_ES_ERR(x)
/*! @} */

/*! @name CH_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH_INT_INT_MASK                        LPE_EDMA_TCD_CH0_INT_INT_MASK
#define DMA_CH_INT_INT_SHIFT                       LPE_EDMA_TCD_CH0_INT_INT_SHIFT
#define DMA_CH_INT_INT_WIDTH                       LPE_EDMA_TCD_CH0_INT_INT_WIDTH
#define DMA_CH_INT_INT(x)                          LPE_EDMA_TCD_CH0_INT_INT(x)
/*! @} */

/*! @name CH_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH_SBR_MID_MASK                        LPE_EDMA_TCD_CH0_SBR_MID_MASK
#define DMA_CH_SBR_MID_SHIFT                       LPE_EDMA_TCD_CH0_SBR_MID_SHIFT
#define DMA_CH_SBR_MID_WIDTH                       LPE_EDMA_TCD_CH0_SBR_MID_WIDTH
#define DMA_CH_SBR_MID(x)                          LPE_EDMA_TCD_CH0_SBR_MID(x)

#define DMA_CH_SBR_PAL_MASK                        LPE_EDMA_TCD_CH0_SBR_PAL_MASK
#define DMA_CH_SBR_PAL_SHIFT                       LPE_EDMA_TCD_CH0_SBR_PAL_SHIFT
#define DMA_CH_SBR_PAL_WIDTH                       LPE_EDMA_TCD_CH0_SBR_PAL_WIDTH
#define DMA_CH_SBR_PAL(x)                          LPE_EDMA_TCD_CH0_SBR_PAL(x)

#define DMA_CH_SBR_EMI_WIDTH                       LPE_EDMA_TCD_CH0_SBR_EMI_WIDTH
#define DMA_CH_SBR_EMI(x)                          LPE_EDMA_TCD_CH0_SBR_EMI(x)

#define DMA_CH_SBR_ATTR_MASK                       LPE_EDMA_TCD_CH0_SBR_ATTR_MASK
#define DMA_CH_SBR_ATTR_SHIFT                      LPE_EDMA_TCD_CH0_SBR_ATTR_SHIFT
#define DMA_CH_SBR_ATTR_WIDTH                      LPE_EDMA_TCD_CH0_SBR_ATTR_WIDTH
#define DMA_CH_SBR_ATTR(x)                         LPE_EDMA_TCD_CH0_SBR_ATTR(x)
/*! @} */

/*! @name CH_PRI - Channel Priority */
/*! @{ */

#define DMA_CH_PRI_APL_MASK                        LPE_EDMA_TCD_CH0_PRI_APL_MASK
#define DMA_CH_PRI_APL_SHIFT                       LPE_EDMA_TCD_CH0_PRI_APL_SHIFT
#define DMA_CH_PRI_APL_WIDTH                       LPE_EDMA_TCD_CH0_PRI_APL_WIDTH
#define DMA_CH_PRI_APL(x)                          LPE_EDMA_TCD_CH0_PRI_APL(x)

#define DMA_CH_PRI_DPA_MASK                        LPE_EDMA_TCD_CH0_PRI_DPA_MASK
#define DMA_CH_PRI_DPA_SHIFT                       LPE_EDMA_TCD_CH0_PRI_DPA_SHIFT
#define DMA_CH_PRI_DPA_WIDTH                       LPE_EDMA_TCD_CH0_PRI_DPA_WIDTH
#define DMA_CH_PRI_DPA(x)                          LPE_EDMA_TCD_CH0_PRI_DPA(x)

#define DMA_CH_PRI_ECP_MASK                        LPE_EDMA_TCD_CH0_PRI_ECP_MASK
#define DMA_CH_PRI_ECP_SHIFT                       LPE_EDMA_TCD_CH0_PRI_ECP_SHIFT
#define DMA_CH_PRI_ECP_WIDTH                       LPE_EDMA_TCD_CH0_PRI_ECP_WIDTH
#define DMA_CH_PRI_ECP(x)                          LPE_EDMA_TCD_CH0_PRI_ECP(x)
/*! @} */

/*! @name SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD_SADDR_SADDR_MASK                   LPE_EDMA_TCD_TCD0_SADDR_SADDR_MASK
#define DMA_TCD_SADDR_SADDR_SHIFT                  LPE_EDMA_TCD_TCD0_SADDR_SADDR_SHIFT
#define DMA_TCD_SADDR_SADDR_WIDTH                  LPE_EDMA_TCD_TCD0_SADDR_SADDR_WIDTH
#define DMA_TCD_SADDR_SADDR(x)                     LPE_EDMA_TCD_TCD0_SADDR_SADDR(x)
/*! @} */

/*! @name SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD_SOFF_SOFF_MASK                     LPE_EDMA_TCD_TCD0_SOFF_SOFF_MASK
#define DMA_TCD_SOFF_SOFF_SHIFT                    LPE_EDMA_TCD_TCD0_SOFF_SOFF_SHIFT
#define DMA_TCD_SOFF_SOFF_WIDTH                    LPE_EDMA_TCD_TCD0_SOFF_SOFF_WIDTH
#define DMA_TCD_SOFF_SOFF(x)                       LPE_EDMA_TCD_TCD0_SOFF_SOFF(x)
/*! @} */

/*! @name ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD_ATTR_DSIZE_MASK                    LPE_EDMA_TCD_TCD0_ATTR_DSIZE_MASK
#define DMA_TCD_ATTR_DSIZE_SHIFT                   LPE_EDMA_TCD_TCD0_ATTR_DSIZE_SHIFT
#define DMA_TCD_ATTR_DSIZE_WIDTH                   LPE_EDMA_TCD_TCD0_ATTR_DSIZE_WIDTH
#define DMA_TCD_ATTR_DSIZE(x)                      LPE_EDMA_TCD_TCD0_ATTR_DSIZE(x)

#define DMA_TCD_ATTR_DMOD_MASK                     LPE_EDMA_TCD_TCD0_ATTR_DMOD_MASK
#define DMA_TCD_ATTR_DMOD_SHIFT                    LPE_EDMA_TCD_TCD0_ATTR_DMOD_SHIFT
#define DMA_TCD_ATTR_DMOD_WIDTH                    LPE_EDMA_TCD_TCD0_ATTR_DMOD_WIDTH
#define DMA_TCD_ATTR_DMOD(x)                       LPE_EDMA_TCD_TCD0_ATTR_DMOD(x)

#define DMA_TCD_ATTR_SSIZE_MASK                    LPE_EDMA_TCD_TCD0_ATTR_SSIZE_MASK
#define DMA_TCD_ATTR_SSIZE_SHIFT                   LPE_EDMA_TCD_TCD0_ATTR_SSIZE_SHIFT
#define DMA_TCD_ATTR_SSIZE_WIDTH                   LPE_EDMA_TCD_TCD0_ATTR_SSIZE_WIDTH
#define DMA_TCD_ATTR_SSIZE(x)                      LPE_EDMA_TCD_TCD0_ATTR_SSIZE(x)

#define DMA_TCD_ATTR_SMOD_MASK                     LPE_EDMA_TCD_TCD0_ATTR_SMOD_MASK
#define DMA_TCD_ATTR_SMOD_SHIFT                    LPE_EDMA_TCD_TCD0_ATTR_SMOD_SHIFT
#define DMA_TCD_ATTR_SMOD_WIDTH                    LPE_EDMA_TCD_TCD0_ATTR_SMOD_WIDTH
#define DMA_TCD_ATTR_SMOD(x)                       LPE_EDMA_TCD_TCD0_ATTR_SMOD(x)
/*! @} */

/*! @name NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD_NBYTES_MLOFFNO_NBYTES_MASK         LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_MASK
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT        LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_SHIFT
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES_WIDTH        LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_WIDTH
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES(x)           LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_NBYTES(x)

#define DMA_TCD_NBYTES_MLOFFNO_DMLOE_MASK          LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_MASK
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT         LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_SHIFT
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE_WIDTH         LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_WIDTH
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE(x)            LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_DMLOE(x)

#define DMA_TCD_NBYTES_MLOFFNO_SMLOE_MASK          LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_MASK
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT         LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_SHIFT
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE_WIDTH         LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_WIDTH
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE(x)            LPE_EDMA_TCD_TCD0_NBYTES_MLOFFNO_SMLOE(x)
/*! @} */

/*! @name NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD_NBYTES_MLOFFYES_NBYTES_MASK        LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_MASK
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT       LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_SHIFT
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES_WIDTH       LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_WIDTH
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES(x)          LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_NBYTES(x)

#define DMA_TCD_NBYTES_MLOFFYES_MLOFF_MASK         LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_MASK
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT        LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_SHIFT
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF_WIDTH        LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_WIDTH
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF(x)           LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_MLOFF(x)

#define DMA_TCD_NBYTES_MLOFFYES_DMLOE_MASK         LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_MASK
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT        LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_SHIFT
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE_WIDTH        LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_WIDTH
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE(x)           LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_DMLOE(x)

#define DMA_TCD_NBYTES_MLOFFYES_SMLOE_MASK         LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_MASK
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT        LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_SHIFT
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE_WIDTH        LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_WIDTH
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE(x)           LPE_EDMA_TCD_TCD0_NBYTES_MLOFFYES_SMLOE(x)
/*! @} */

/*! @name SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD_SLAST_SDA_SLAST_SDA_MASK           LPE_EDMA_TCD_TCD0_SLAST_SDA_SLAST_SDA_MASK
#define DMA_TCD_SLAST_SDA_SLAST_SDA_SHIFT          LPE_EDMA_TCD_TCD0_SLAST_SDA_SLAST_SDA_SHIFT
#define DMA_TCD_SLAST_SDA_SLAST_SDA_WIDTH          LPE_EDMA_TCD_TCD0_SLAST_SDA_SLAST_SDA_WIDTH
#define DMA_TCD_SLAST_SDA_SLAST_SDA(x)             LPE_EDMA_TCD_TCD0_SLAST_SDA_SLAST_SDA(x)
/*! @} */

/*! @name DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD_DADDR_DADDR_MASK                   LPE_EDMA_TCD_TCD0_DADDR_DADDR_MASK
#define DMA_TCD_DADDR_DADDR_SHIFT                  LPE_EDMA_TCD_TCD0_DADDR_DADDR_SHIFT
#define DMA_TCD_DADDR_DADDR_WIDTH                  LPE_EDMA_TCD_TCD0_DADDR_DADDR_WIDTH
#define DMA_TCD_DADDR_DADDR(x)                     LPE_EDMA_TCD_TCD0_DADDR_DADDR(x)
/*! @} */

/*! @name DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD_DOFF_DOFF_MASK                     LPE_EDMA_TCD_TCD0_DOFF_DOFF_MASK
#define DMA_TCD_DOFF_DOFF_SHIFT                    LPE_EDMA_TCD_TCD0_DOFF_DOFF_SHIFT
#define DMA_TCD_DOFF_DOFF_WIDTH                    LPE_EDMA_TCD_TCD0_DOFF_DOFF_WIDTH
#define DMA_TCD_DOFF_DOFF(x)                       LPE_EDMA_TCD_TCD0_DOFF_DOFF(x)
/*! @} */

/*! @name CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD_CITER_ELINKNO_CITER_MASK           LPE_EDMA_TCD_TCD0_CITER_ELINKNO_CITER_MASK
#define DMA_TCD_CITER_ELINKNO_CITER_SHIFT          LPE_EDMA_TCD_TCD0_CITER_ELINKNO_CITER_SHIFT
#define DMA_TCD_CITER_ELINKNO_CITER_WIDTH          LPE_EDMA_TCD_TCD0_CITER_ELINKNO_CITER_WIDTH
#define DMA_TCD_CITER_ELINKNO_CITER(x)             LPE_EDMA_TCD_TCD0_CITER_ELINKNO_CITER(x)

#define DMA_TCD_CITER_ELINKNO_ELINK_MASK           LPE_EDMA_TCD_TCD0_CITER_ELINKNO_ELINK_MASK
#define DMA_TCD_CITER_ELINKNO_ELINK_SHIFT          LPE_EDMA_TCD_TCD0_CITER_ELINKNO_ELINK_SHIFT
#define DMA_TCD_CITER_ELINKNO_ELINK_WIDTH          LPE_EDMA_TCD_TCD0_CITER_ELINKNO_ELINK_WIDTH
#define DMA_TCD_CITER_ELINKNO_ELINK(x)             LPE_EDMA_TCD_TCD0_CITER_ELINKNO_ELINK(x)
/*! @} */

/*! @name CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD_CITER_ELINKYES_CITER_MASK          LPE_EDMA_TCD_TCD0_CITER_ELINKYES_CITER_MASK
#define DMA_TCD_CITER_ELINKYES_CITER_SHIFT         LPE_EDMA_TCD_TCD0_CITER_ELINKYES_CITER_SHIFT
#define DMA_TCD_CITER_ELINKYES_CITER_WIDTH         LPE_EDMA_TCD_TCD0_CITER_ELINKYES_CITER_WIDTH
#define DMA_TCD_CITER_ELINKYES_CITER(x)            LPE_EDMA_TCD_TCD0_CITER_ELINKYES_CITER(x)

#define DMA_TCD_CITER_ELINKYES_LINKCH_MASK         LPE_EDMA_TCD_TCD0_CITER_ELINKYES_LINKCH_MASK
#define DMA_TCD_CITER_ELINKYES_LINKCH_SHIFT        LPE_EDMA_TCD_TCD0_CITER_ELINKYES_LINKCH_SHIFT
#define DMA_TCD_CITER_ELINKYES_LINKCH_WIDTH        LPE_EDMA_TCD_TCD0_CITER_ELINKYES_LINKCH_WIDTH
#define DMA_TCD_CITER_ELINKYES_LINKCH(x)           LPE_EDMA_TCD_TCD0_CITER_ELINKYES_LINKCH(x)

#define DMA_TCD_CITER_ELINKYES_ELINK_MASK          LPE_EDMA_TCD_TCD0_CITER_ELINKYES_ELINK_MASK
#define DMA_TCD_CITER_ELINKYES_ELINK_SHIFT         LPE_EDMA_TCD_TCD0_CITER_ELINKYES_ELINK_SHIFT
#define DMA_TCD_CITER_ELINKYES_ELINK_WIDTH         LPE_EDMA_TCD_TCD0_CITER_ELINKYES_ELINK_WIDTH
#define DMA_TCD_CITER_ELINKYES_ELINK(x)            LPE_EDMA_TCD_TCD0_CITER_ELINKYES_ELINK(x)
/*! @} */

/*! @name DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD_DLAST_SGA_DLAST_SGA_MASK           LPE_EDMA_TCD_TCD0_DLAST_SGA_DLAST_SGA_MASK
#define DMA_TCD_DLAST_SGA_DLAST_SGA_SHIFT          LPE_EDMA_TCD_TCD0_DLAST_SGA_DLAST_SGA_SHIFT
#define DMA_TCD_DLAST_SGA_DLAST_SGA_WIDTH          LPE_EDMA_TCD_TCD0_DLAST_SGA_DLAST_SGA_WIDTH
#define DMA_TCD_DLAST_SGA_DLAST_SGA(x)             LPE_EDMA_TCD_TCD0_DLAST_SGA_DLAST_SGA(x)
/*! @} */

/*! @name CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD_CSR_START_MASK                     LPE_EDMA_TCD_TCD0_CSR_START_MASK
#define DMA_TCD_CSR_START_SHIFT                    LPE_EDMA_TCD_TCD0_CSR_START_SHIFT
#define DMA_TCD_CSR_START_WIDTH                    LPE_EDMA_TCD_TCD0_CSR_START_WIDTH
#define DMA_TCD_CSR_START(x)                       LPE_EDMA_TCD_TCD0_CSR_START(x)

#define DMA_TCD_CSR_INTMAJOR_MASK                  LPE_EDMA_TCD_TCD0_CSR_INTMAJOR_MASK
#define DMA_TCD_CSR_INTMAJOR_SHIFT                 LPE_EDMA_TCD_TCD0_CSR_INTMAJOR_SHIFT
#define DMA_TCD_CSR_INTMAJOR_WIDTH                 LPE_EDMA_TCD_TCD0_CSR_INTMAJOR_WIDTH
#define DMA_TCD_CSR_INTMAJOR(x)                    LPE_EDMA_TCD_TCD0_CSR_INTMAJOR(x)

#define DMA_TCD_CSR_INTHALF_MASK                   LPE_EDMA_TCD_TCD0_CSR_INTHALF_MASK
#define DMA_TCD_CSR_INTHALF_SHIFT                  LPE_EDMA_TCD_TCD0_CSR_INTHALF_SHIFT
#define DMA_TCD_CSR_INTHALF_WIDTH                  LPE_EDMA_TCD_TCD0_CSR_INTHALF_WIDTH
#define DMA_TCD_CSR_INTHALF(x)                     LPE_EDMA_TCD_TCD0_CSR_INTHALF(x)

#define DMA_TCD_CSR_DREQ_MASK                      LPE_EDMA_TCD_TCD0_CSR_DREQ_MASK
#define DMA_TCD_CSR_DREQ_SHIFT                     LPE_EDMA_TCD_TCD0_CSR_DREQ_SHIFT
#define DMA_TCD_CSR_DREQ_WIDTH                     LPE_EDMA_TCD_TCD0_CSR_DREQ_WIDTH
#define DMA_TCD_CSR_DREQ(x)                        LPE_EDMA_TCD_TCD0_CSR_DREQ(x)

#define DMA_TCD_CSR_ESG_MASK                       LPE_EDMA_TCD_TCD0_CSR_ESG_MASK
#define DMA_TCD_CSR_ESG_SHIFT                      LPE_EDMA_TCD_TCD0_CSR_ESG_SHIFT
#define DMA_TCD_CSR_ESG_WIDTH                      LPE_EDMA_TCD_TCD0_CSR_ESG_WIDTH
#define DMA_TCD_CSR_ESG(x)                         LPE_EDMA_TCD_TCD0_CSR_ESG(x)

#define DMA_TCD_CSR_MAJORELINK_MASK                LPE_EDMA_TCD_TCD0_CSR_MAJORELINK_MASK
#define DMA_TCD_CSR_MAJORELINK_SHIFT               LPE_EDMA_TCD_TCD0_CSR_MAJORELINK_SHIFT
#define DMA_TCD_CSR_MAJORELINK_WIDTH               LPE_EDMA_TCD_TCD0_CSR_MAJORELINK_WIDTH
#define DMA_TCD_CSR_MAJORELINK(x)                  LPE_EDMA_TCD_TCD0_CSR_MAJORELINK(x)

#define DMA_TCD_CSR_ESDA_MASK                      LPE_EDMA_TCD_TCD0_CSR_ESDA_MASK
#define DMA_TCD_CSR_ESDA_SHIFT                     LPE_EDMA_TCD_TCD0_CSR_ESDA_SHIFT
#define DMA_TCD_CSR_ESDA_WIDTH                     LPE_EDMA_TCD_TCD0_CSR_ESDA_WIDTH
#define DMA_TCD_CSR_ESDA(x)                        LPE_EDMA_TCD_TCD0_CSR_ESDA(x)

#define DMA_TCD_CSR_MAJORLINKCH_MASK               LPE_EDMA_TCD_TCD0_CSR_MAJORLINKCH_MASK
#define DMA_TCD_CSR_MAJORLINKCH_SHIFT              LPE_EDMA_TCD_TCD0_CSR_MAJORLINKCH_SHIFT
#define DMA_TCD_CSR_MAJORLINKCH_WIDTH              LPE_EDMA_TCD_TCD0_CSR_MAJORLINKCH_WIDTH
#define DMA_TCD_CSR_MAJORLINKCH(x)                 LPE_EDMA_TCD_TCD0_CSR_MAJORLINKCH(x)

#define DMA_TCD_CSR_BWC_MASK                       LPE_EDMA_TCD_TCD0_CSR_BWC_MASK
#define DMA_TCD_CSR_BWC_SHIFT                      LPE_EDMA_TCD_TCD0_CSR_BWC_SHIFT
#define DMA_TCD_CSR_BWC_WIDTH                      LPE_EDMA_TCD_TCD0_CSR_BWC_WIDTH
#define DMA_TCD_CSR_BWC(x)                         LPE_EDMA_TCD_TCD0_CSR_BWC(x)
/*! @} */

/*! @name BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD_BITER_ELINKNO_BITER_MASK           LPE_EDMA_TCD_TCD0_BITER_ELINKNO_BITER_MASK
#define DMA_TCD_BITER_ELINKNO_BITER_SHIFT          LPE_EDMA_TCD_TCD0_BITER_ELINKNO_BITER_SHIFT
#define DMA_TCD_BITER_ELINKNO_BITER_WIDTH          LPE_EDMA_TCD_TCD0_BITER_ELINKNO_BITER_WIDTH
#define DMA_TCD_BITER_ELINKNO_BITER(x)             LPE_EDMA_TCD_TCD0_BITER_ELINKNO_BITER(x)

#define DMA_TCD_BITER_ELINKNO_ELINK_MASK           LPE_EDMA_TCD_TCD0_BITER_ELINKNO_ELINK_MASK
#define DMA_TCD_BITER_ELINKNO_ELINK_SHIFT          LPE_EDMA_TCD_TCD0_BITER_ELINKNO_ELINK_SHIFT
#define DMA_TCD_BITER_ELINKNO_ELINK_WIDTH          LPE_EDMA_TCD_TCD0_BITER_ELINKNO_ELINK_WIDTH
#define DMA_TCD_BITER_ELINKNO_ELINK(x)             LPE_EDMA_TCD_TCD0_BITER_ELINKNO_ELINK(x)
/*! @} */

/*! @name BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD_BITER_ELINKYES_BITER_MASK          LPE_EDMA_TCD_TCD0_BITER_ELINKYES_BITER_MASK
#define DMA_TCD_BITER_ELINKYES_BITER_SHIFT         LPE_EDMA_TCD_TCD0_BITER_ELINKYES_BITER_SHIFT
#define DMA_TCD_BITER_ELINKYES_BITER_WIDTH         LPE_EDMA_TCD_TCD0_BITER_ELINKYES_BITER_WIDTH
#define DMA_TCD_BITER_ELINKYES_BITER(x)            LPE_EDMA_TCD_TCD0_BITER_ELINKYES_BITER(x)

#define DMA_TCD_BITER_ELINKYES_LINKCH_MASK         LPE_EDMA_TCD_TCD0_BITER_ELINKYES_LINKCH_MASK
#define DMA_TCD_BITER_ELINKYES_LINKCH_SHIFT        LPE_EDMA_TCD_TCD0_BITER_ELINKYES_LINKCH_SHIFT
#define DMA_TCD_BITER_ELINKYES_LINKCH_WIDTH        LPE_EDMA_TCD_TCD0_BITER_ELINKYES_LINKCH_WIDTH
#define DMA_TCD_BITER_ELINKYES_LINKCH(x)           LPE_EDMA_TCD_TCD0_BITER_ELINKYES_LINKCH(x)

#define DMA_TCD_BITER_ELINKYES_ELINK_MASK          LPE_EDMA_TCD_TCD0_BITER_ELINKYES_ELINK_MASK
#define DMA_TCD_BITER_ELINKYES_ELINK_SHIFT         LPE_EDMA_TCD_TCD0_BITER_ELINKYES_ELINK_SHIFT
#define DMA_TCD_BITER_ELINKYES_ELINK_WIDTH         LPE_EDMA_TCD_TCD0_BITER_ELINKYES_ELINK_WIDTH
#define DMA_TCD_BITER_ELINKYES_ELINK(x)            LPE_EDMA_TCD_TCD0_BITER_ELINKYES_ELINK(x)
/*! @} */

/** DMA5 - Register Layout Typedef */
typedef struct {
  __IO uint32_t MP_CSR;                            /**< Management Page Control, offset: 0x0 */
  __I  uint32_t MP_ES;                             /**< Management Page Error Status, offset: 0x4 */
  __I  uint32_t MP_INT_LOW;                        /**< Management Page Interrupt Request Status, offset: 0x8 */
  uint8_t RESERVED_0[4];
  __I  uint32_t MP_HRS_LOW;                        /**< Hardware Request Status, offset: 0x10 */
  uint8_t RESERVED_1[12];
  __IO uint32_t MP_STOPCH;                         /**< Stop Channel, offset: 0x20 */
  uint8_t RESERVED_2[12];
  __I  uint32_t MP_SSR_LOW;                        /**< Stop Status, offset: 0x30 */
  uint8_t RESERVED_3[204];
  __IO uint32_t CH_GRPRI[32];                      /**< Channel Arbitration Group, array offset: 0x100, array step: 0x4 */
  uint8_t RESERVED_4[640];
  __IO uint32_t CH_PROT[32];                       /**< Channel Protection, array offset: 0x400, array step: 0x4 */
  uint8_t RESERVED_5[15232];
  struct {                                         /* offset: 0x10000, array step: 0x8000 */
    __IO uint32_t CH_CSR;                            /**< Channel Control and Status, array offset: 0x0, array step: 0x2000 */
    __IO uint32_t CH_ES;                             /**< Channel Error Status, array offset: 0x4, array step: 0x2000 */
    __IO uint32_t CH_INT;                            /**< Channel Interrupt Status, array offset: 0x8, array step: 0x2000 */
    __I  uint32_t CH_SBR;                            /**< Channel System Bus, array offset: 0xC, array step: 0x2000 */
    __IO uint32_t CH_PRI;                            /**< Channel Priority, array offset: 0x10, array step: 0x2000 */
    uint8_t RESERVED_0[4];
    __IO uint32_t CH_MATTR;                          /**< Memory Attributes, array offset: 0x18, array step: 0x2000 */
    uint8_t RESERVED_1[4];
    __IO uint32_t SADDR;                             /**< TCD Source Address, array offset: 0x20, array step: 0x2000 */
    __IO uint32_t SADDR_HIGH;                        /**< TCD Source Address, array offset: 0x24, array step: 0x2000 */
    __IO uint16_t SOFF;                              /**< TCD Signed Source Address Offset, array offset: 0x28, array step: 0x2000 */
    __IO uint16_t ATTR;                              /**< TCD Transfer Attributes, array offset: 0x2A, array step: 0x2000 */
    union {                                          /* offset: 0x2C, array step: 0x2000 */
      __IO uint32_t NBYTES_MLOFFNO;                    /**< TCD Transfer Size Without Minor Loop Offsets, array offset: 0x2C, array step: 0x2000 */
      __IO uint32_t NBYTES_MLOFFYES;                   /**< TCD Transfer Size with Minor Loop Offsets, array offset: 0x2C, array step: 0x2000 */
    };
    __IO uint32_t SLAST_SDA;                         /**< TCD Last Source Address Adjustment and Store DADDR Address, array offset: 0x30, array step: 0x2000 */
    __IO uint32_t SLAST_SDA_HIGH;                    /**< TCD Last Source Address Adjustment and Store DADDR Address, array offset: 0x34, array step: 0x2000 */
    __IO uint32_t DADDR;                             /**< TCD Destination Address, array offset: 0x38, array step: 0x2000 */
    __IO uint32_t DADDR_HIGH;                        /**< TCD Destination Address, array offset: 0x3C, array step: 0x2000 */
    __IO uint32_t DLAST_SGA;                         /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, array offset: 0x40, array step: 0x2000 */
    __IO uint32_t DLAST_SGA_HIGH;                    /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, array offset: 0x44, array step: 0x2000 */
    __IO uint16_t DOFF;                              /**< TCD Signed Destination Address Offset, array offset: 0x48, array step: 0x2000 */
    union {                                          /* offset: 0x4A, array step: 0x2000 */
      __IO uint16_t CITER_ELINKNO;                     /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x4A, array step: 0x2000 */
      __IO uint16_t CITER_ELINKYES;                    /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x4A, array step: 0x2000 */
    };
    __IO uint16_t CSR;                               /**< TCD Control and Status, array offset: 0x4C, array step: 0x2000 */
    union {                                          /* offset: 0x4E, array step: 0x2000 */
      __IO uint16_t BITER_ELINKNO;                     /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x4E, array step: 0x2000 */
      __IO uint16_t BITER_ELINKYES;                    /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x4E, array step: 0x2000 */
    };
    uint8_t RESERVED_2[8112];
  } TCD[32];
} DMA5_Type;

/* ----------------------------------------------------------------------------
   -- spp_dma5_MP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup spp_dma5_MP_Register_Masks spp_dma5_MP Register Masks
 * @{
 */

/*! @name MP_CSR - Management Page Control */
/*! @{ */

#define DMA5_MP_CSR_EDBG_MASK                      spp_dma5_MP_MP_CSR_EDBG_MASK
#define DMA5_MP_CSR_EDBG_SHIFT                     spp_dma5_MP_MP_CSR_EDBG_SHIFT
#define DMA5_MP_CSR_EDBG_WIDTH                     spp_dma5_MP_MP_CSR_EDBG_WIDTH
#define DMA5_MP_CSR_EDBG(x)                        spp_dma5_MP_MP_CSR_EDBG(x)

#define DMA5_MP_CSR_ERCA_MASK                      spp_dma5_MP_MP_CSR_ERCA_MASK
#define DMA5_MP_CSR_ERCA_SHIFT                     spp_dma5_MP_MP_CSR_ERCA_SHIFT
#define DMA5_MP_CSR_ERCA_WIDTH                     spp_dma5_MP_MP_CSR_ERCA_WIDTH
#define DMA5_MP_CSR_ERCA(x)                        spp_dma5_MP_MP_CSR_ERCA(x)

#define DMA5_MP_CSR_GCPC_MASK                      spp_dma5_MP_MP_CSR_GCPC_MASK
#define DMA5_MP_CSR_GCPC_SHIFT                     spp_dma5_MP_MP_CSR_GCPC_SHIFT
#define DMA5_MP_CSR_GCPC_WIDTH                     spp_dma5_MP_MP_CSR_GCPC_WIDTH
#define DMA5_MP_CSR_GCPC(x)                        spp_dma5_MP_MP_CSR_GCPC(x)

#define DMA5_MP_CSR_HAE_MASK                       spp_dma5_MP_MP_CSR_HAE_MASK
#define DMA5_MP_CSR_HAE_SHIFT                      spp_dma5_MP_MP_CSR_HAE_SHIFT
#define DMA5_MP_CSR_HAE_WIDTH                      spp_dma5_MP_MP_CSR_HAE_WIDTH
#define DMA5_MP_CSR_HAE(x)                         spp_dma5_MP_MP_CSR_HAE(x)

#define DMA5_MP_CSR_HALT_MASK                      spp_dma5_MP_MP_CSR_HALT_MASK
#define DMA5_MP_CSR_HALT_SHIFT                     spp_dma5_MP_MP_CSR_HALT_SHIFT
#define DMA5_MP_CSR_HALT_WIDTH                     spp_dma5_MP_MP_CSR_HALT_WIDTH
#define DMA5_MP_CSR_HALT(x)                        spp_dma5_MP_MP_CSR_HALT(x)

#define DMA5_MP_CSR_GCLC_MASK                      spp_dma5_MP_MP_CSR_GCLC_MASK
#define DMA5_MP_CSR_GCLC_SHIFT                     spp_dma5_MP_MP_CSR_GCLC_SHIFT
#define DMA5_MP_CSR_GCLC_WIDTH                     spp_dma5_MP_MP_CSR_GCLC_WIDTH
#define DMA5_MP_CSR_GCLC(x)                        spp_dma5_MP_MP_CSR_GCLC(x)

#define DMA5_MP_CSR_GMRC_MASK                      spp_dma5_MP_MP_CSR_GMRC_MASK
#define DMA5_MP_CSR_GMRC_SHIFT                     spp_dma5_MP_MP_CSR_GMRC_SHIFT
#define DMA5_MP_CSR_GMRC_WIDTH                     spp_dma5_MP_MP_CSR_GMRC_WIDTH
#define DMA5_MP_CSR_GMRC(x)                        spp_dma5_MP_MP_CSR_GMRC(x)

#define DMA5_MP_CSR_VER_MASK                       spp_dma5_MP_MP_CSR_VER_MASK
#define DMA5_MP_CSR_VER_SHIFT                      spp_dma5_MP_MP_CSR_VER_SHIFT
#define DMA5_MP_CSR_VER_WIDTH                      spp_dma5_MP_MP_CSR_VER_WIDTH
#define DMA5_MP_CSR_VER(x)                         spp_dma5_MP_MP_CSR_VER(x)

#define DMA5_MP_CSR_ACTIVE_ID_MASK                 spp_dma5_MP_MP_CSR_ACTIVE_ID_MASK
#define DMA5_MP_CSR_ACTIVE_ID_SHIFT                spp_dma5_MP_MP_CSR_ACTIVE_ID_SHIFT
#define DMA5_MP_CSR_ACTIVE_ID_WIDTH                spp_dma5_MP_MP_CSR_ACTIVE_ID_WIDTH
#define DMA5_MP_CSR_ACTIVE_ID(x)                   spp_dma5_MP_MP_CSR_ACTIVE_ID(x)

#define DMA5_MP_CSR_ACTIVE_MASK                    spp_dma5_MP_MP_CSR_ACTIVE_MASK
#define DMA5_MP_CSR_ACTIVE_SHIFT                   spp_dma5_MP_MP_CSR_ACTIVE_SHIFT
#define DMA5_MP_CSR_ACTIVE_WIDTH                   spp_dma5_MP_MP_CSR_ACTIVE_WIDTH
#define DMA5_MP_CSR_ACTIVE(x)                      spp_dma5_MP_MP_CSR_ACTIVE(x)
/*! @} */

/*! @name MP_ES - Management Page Error Status */
/*! @{ */

#define DMA5_MP_ES_DBE_MASK                        spp_dma5_MP_MP_ES_DBE_MASK
#define DMA5_MP_ES_DBE_SHIFT                       spp_dma5_MP_MP_ES_DBE_SHIFT
#define DMA5_MP_ES_DBE_WIDTH                       spp_dma5_MP_MP_ES_DBE_WIDTH
#define DMA5_MP_ES_DBE(x)                          spp_dma5_MP_MP_ES_DBE(x)

#define DMA5_MP_ES_SBE_MASK                        spp_dma5_MP_MP_ES_SBE_MASK
#define DMA5_MP_ES_SBE_SHIFT                       spp_dma5_MP_MP_ES_SBE_SHIFT
#define DMA5_MP_ES_SBE_WIDTH                       spp_dma5_MP_MP_ES_SBE_WIDTH
#define DMA5_MP_ES_SBE(x)                          spp_dma5_MP_MP_ES_SBE(x)

#define DMA5_MP_ES_SGE_MASK                        spp_dma5_MP_MP_ES_SGE_MASK
#define DMA5_MP_ES_SGE_SHIFT                       spp_dma5_MP_MP_ES_SGE_SHIFT
#define DMA5_MP_ES_SGE_WIDTH                       spp_dma5_MP_MP_ES_SGE_WIDTH
#define DMA5_MP_ES_SGE(x)                          spp_dma5_MP_MP_ES_SGE(x)

#define DMA5_MP_ES_NCE_MASK                        spp_dma5_MP_MP_ES_NCE_MASK
#define DMA5_MP_ES_NCE_SHIFT                       spp_dma5_MP_MP_ES_NCE_SHIFT
#define DMA5_MP_ES_NCE_WIDTH                       spp_dma5_MP_MP_ES_NCE_WIDTH
#define DMA5_MP_ES_NCE(x)                          spp_dma5_MP_MP_ES_NCE(x)

#define DMA5_MP_ES_DOE_MASK                        spp_dma5_MP_MP_ES_DOE_MASK
#define DMA5_MP_ES_DOE_SHIFT                       spp_dma5_MP_MP_ES_DOE_SHIFT
#define DMA5_MP_ES_DOE_WIDTH                       spp_dma5_MP_MP_ES_DOE_WIDTH
#define DMA5_MP_ES_DOE(x)                          spp_dma5_MP_MP_ES_DOE(x)

#define DMA5_MP_ES_DAE_MASK                        spp_dma5_MP_MP_ES_DAE_MASK
#define DMA5_MP_ES_DAE_SHIFT                       spp_dma5_MP_MP_ES_DAE_SHIFT
#define DMA5_MP_ES_DAE_WIDTH                       spp_dma5_MP_MP_ES_DAE_WIDTH
#define DMA5_MP_ES_DAE(x)                          spp_dma5_MP_MP_ES_DAE(x)

#define DMA5_MP_ES_SOE_MASK                        spp_dma5_MP_MP_ES_SOE_MASK
#define DMA5_MP_ES_SOE_SHIFT                       spp_dma5_MP_MP_ES_SOE_SHIFT
#define DMA5_MP_ES_SOE_WIDTH                       spp_dma5_MP_MP_ES_SOE_WIDTH
#define DMA5_MP_ES_SOE(x)                          spp_dma5_MP_MP_ES_SOE(x)

#define DMA5_MP_ES_SAE_MASK                        spp_dma5_MP_MP_ES_SAE_MASK
#define DMA5_MP_ES_SAE_SHIFT                       spp_dma5_MP_MP_ES_SAE_SHIFT
#define DMA5_MP_ES_SAE_WIDTH                       spp_dma5_MP_MP_ES_SAE_WIDTH
#define DMA5_MP_ES_SAE(x)                          spp_dma5_MP_MP_ES_SAE(x)

#define DMA5_MP_ES_ECX_MASK                        spp_dma5_MP_MP_ES_ECX_MASK
#define DMA5_MP_ES_ECX_SHIFT                       spp_dma5_MP_MP_ES_ECX_SHIFT
#define DMA5_MP_ES_ECX_WIDTH                       spp_dma5_MP_MP_ES_ECX_WIDTH
#define DMA5_MP_ES_ECX(x)                          spp_dma5_MP_MP_ES_ECX(x)

#define DMA5_MP_ES_UCE_MASK                        spp_dma5_MP_MP_ES_UCE_MASK
#define DMA5_MP_ES_UCE_SHIFT                       spp_dma5_MP_MP_ES_UCE_SHIFT
#define DMA5_MP_ES_UCE_WIDTH                       spp_dma5_MP_MP_ES_UCE_WIDTH
#define DMA5_MP_ES_UCE(x)                          spp_dma5_MP_MP_ES_UCE(x)

#define DMA5_MP_ES_ERRCHN_MASK                     spp_dma5_MP_MP_ES_ERRCHN_MASK
#define DMA5_MP_ES_ERRCHN_SHIFT                    spp_dma5_MP_MP_ES_ERRCHN_SHIFT
#define DMA5_MP_ES_ERRCHN_WIDTH                    spp_dma5_MP_MP_ES_ERRCHN_WIDTH
#define DMA5_MP_ES_ERRCHN(x)                       spp_dma5_MP_MP_ES_ERRCHN(x)

#define DMA5_MP_ES_VLD_MASK                        spp_dma5_MP_MP_ES_VLD_MASK
#define DMA5_MP_ES_VLD_SHIFT                       spp_dma5_MP_MP_ES_VLD_SHIFT
#define DMA5_MP_ES_VLD_WIDTH                       spp_dma5_MP_MP_ES_VLD_WIDTH
#define DMA5_MP_ES_VLD(x)                          spp_dma5_MP_MP_ES_VLD(x)

/*! @} */

/*! @name MP_INT_LOW - Management Page Interrupt Request Status */
/*! @{ */

#define DMA5_MP_INT_LOW_INT_MASK                   spp_dma5_MP_MP_INT_LOW_INT_MASK
#define DMA5_MP_INT_LOW_INT_SHIFT                  spp_dma5_MP_MP_INT_LOW_INT_SHIFT
#define DMA5_MP_INT_LOW_INT_WIDTH                  spp_dma5_MP_MP_INT_LOW_INT_WIDTH
#define DMA5_MP_INT_LOW_INT(x)                     spp_dma5_MP_MP_INT_LOW_INT(x)

/*! @} */

/*! @name MP_HRS_LOW - Hardware Request Status */
/*! @{ */

#define DMA5_MP_HRS_LOW_HRS_MASK                   spp_dma5_MP_MP_HRS_LOW_HRS_MASK
#define DMA5_MP_HRS_LOW_HRS_SHIFT                  spp_dma5_MP_MP_HRS_LOW_HRS_SHIFT
#define DMA5_MP_HRS_LOW_HRS_WIDTH                  spp_dma5_MP_MP_HRS_LOW_HRS_WIDTH
#define DMA5_MP_HRS_LOW_HRS(x)                     spp_dma5_MP_MP_HRS_LOW_HRS(x)

/*! @} */

/*! @name MP_INT_HIGH - Management Page Interrupt Request Status */
/*! @{ */

// #define DMA5_MP_INT_HIGH_INT_MASK                  spp_dma5_MP_MP_INT_HIGH_INT_MASK
// #define DMA5_MP_INT_HIGH_INT_SHIFT                 spp_dma5_MP_MP_INT_HIGH_INT_SHIFT
// #define DMA5_MP_INT_HIGH_INT_WIDTH                 spp_dma5_MP_MP_INT_HIGH_INT_WIDTH
// #define DMA5_MP_INT_HIGH_INT(x)                    spp_dma5_MP_MP_INT_HIGH_INT(x)

/*! @} */

/*! @name MP_HRS_HIGH - Hardware Request Status */
/*! @{ */

// #define DMA5_MP_HRS_HIGH_HRS_MASK                  spp_dma5_MP_MP_HRS_HIGH_HRS_MASK
// #define DMA5_MP_HRS_HIGH_HRS_SHIFT                 spp_dma5_MP_MP_HRS_HIGH_HRS_SHIFT
// #define DMA5_MP_HRS_HIGH_HRS_WIDTH                 spp_dma5_MP_MP_HRS_HIGH_HRS_WIDTH
// #define DMA5_MP_HRS_HIGH_HRS(x)                    spp_dma5_MP_MP_HRS_HIGH_HRS(x)

/*! @} */

/*! @name MP_STOPCH - Stop Channel */
/*! @{ */

#define DMA5_MP_STOPCH_STOPCH_MASK                 spp_dma5_MP_MP_STOPCH_STOPCH_MASK
#define DMA5_MP_STOPCH_STOPCH_SHIFT                spp_dma5_MP_MP_STOPCH_STOPCH_SHIFT
#define DMA5_MP_STOPCH_STOPCH_WIDTH                spp_dma5_MP_MP_STOPCH_STOPCH_WIDTH
#define DMA5_MP_STOPCH_STOPCH(x)                   spp_dma5_MP_MP_STOPCH_STOPCH(x)

#define DMA5_MP_STOPCH_ERR_MASK                    spp_dma5_MP_MP_STOPCH_ERR_MASK
#define DMA5_MP_STOPCH_ERR_SHIFT                   spp_dma5_MP_MP_STOPCH_ERR_SHIFT
#define DMA5_MP_STOPCH_ERR_WIDTH                   spp_dma5_MP_MP_STOPCH_ERR_WIDTH
#define DMA5_MP_STOPCH_ERR(x)                      spp_dma5_MP_MP_STOPCH_ERR(x)

/*! @} */

/*! @name MP_SSR_LOW - Stop Status */
/*! @{ */

#define DMA5_MP_SSR_LOW_CSS_MASK                   spp_dma5_MP_MP_SSR_LOW_CSS_MASK
#define DMA5_MP_SSR_LOW_CSS_SHIFT                  spp_dma5_MP_MP_SSR_LOW_CSS_SHIFT
#define DMA5_MP_SSR_LOW_CSS_WIDTH                  spp_dma5_MP_MP_SSR_LOW_CSS_WIDTH
#define DMA5_MP_SSR_LOW_CSS(x)                     spp_dma5_MP_MP_SSR_LOW_CSS(x)

/*! @} */

/*! @name MP_SSR_HIGH - Stop Status */
/*! @{ */

#define DMA5_MP_SSR_HIGH_CSS_MASK                  spp_dma5_MP_MP_SSR_HIGH_CSS_MASK
#define DMA5_MP_SSR_HIGH_CSS_SHIFT                 spp_dma5_MP_MP_SSR_HIGH_CSS_SHIFT
#define DMA5_MP_SSR_HIGH_CSS_WIDTH                 spp_dma5_MP_MP_SSR_HIGH_CSS_WIDTH
#define DMA5_MP_SSR_HIGH_CSS(x)                    spp_dma5_MP_MP_SSR_HIGH_CSS(x)

/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group */
/*! @{ */

#define DMA5_CH_GRPRI_GRPRI_MASK                   spp_dma5_MP_CH_GRPRI_GRPRI_MASK
#define DMA5_CH_GRPRI_GRPRI_SHIFT                  spp_dma5_MP_CH_GRPRI_GRPRI_SHIFT
#define DMA5_CH_GRPRI_GRPRI_WIDTH                  spp_dma5_MP_CH_GRPRI_GRPRI_WIDTH
#define DMA5_CH_GRPRI_GRPRI(x)                     spp_dma5_MP_CH_GRPRI_GRPRI(x)

/*! @} */

/*! @name CH_PROT - Channel Protection */
/*! @{ */

#define DMA5_CH_PROT_MID_MASK                      spp_dma5_MP_CH_PROT_MID_MASK
#define DMA5_CH_PROT_MID_SHIFT                     spp_dma5_MP_CH_PROT_MID_SHIFT
#define DMA5_CH_PROT_MID_WIDTH                     spp_dma5_MP_CH_PROT_MID_WIDTH
#define DMA5_CH_PROT_MID(x)                        spp_dma5_MP_CH_PROT_MID(x)

#define DMA5_CH_PROT_INSTR_MASK                    spp_dma5_MP_CH_PROT_INSTR_MASK
#define DMA5_CH_PROT_INSTR_SHIFT                   spp_dma5_MP_CH_PROT_INSTR_SHIFT
#define DMA5_CH_PROT_INSTR_WIDTH                   spp_dma5_MP_CH_PROT_INSTR_WIDTH
#define DMA5_CH_PROT_INSTR(x)                      spp_dma5_MP_CH_PROT_INSTR(x)

#define DMA5_CH_PROT_SEC_MASK                      spp_dma5_MP_CH_PROT_SEC_MASK
#define DMA5_CH_PROT_SEC_SHIFT                     spp_dma5_MP_CH_PROT_SEC_SHIFT
#define DMA5_CH_PROT_SEC_WIDTH                     spp_dma5_MP_CH_PROT_SEC_WIDTH
#define DMA5_CH_PROT_SEC(x)                        spp_dma5_MP_CH_PROT_SEC(x)

#define DMA5_CH_PROT_PAL_MASK                      spp_dma5_MP_CH_PROT_PAL_MASK
#define DMA5_CH_PROT_PAL_SHIFT                     spp_dma5_MP_CH_PROT_PAL_SHIFT
#define DMA5_CH_PROT_PAL_WIDTH                     spp_dma5_MP_CH_PROT_PAL_WIDTH
#define DMA5_CH_PROT_PAL(x)                        spp_dma5_MP_CH_PROT_PAL(x)

#define DMA5_CH_PROT_EMI_MASK                      spp_dma5_MP_CH_PROT_EMI_MASK
#define DMA5_CH_PROT_EMI_SHIFT                     spp_dma5_MP_CH_PROT_EMI_SHIFT
#define DMA5_CH_PROT_EMI_WIDTH                     spp_dma5_MP_CH_PROT_EMI_WIDTH
#define DMA5_CH_PROT_EMI(x)                        spp_dma5_MP_CH_PROT_EMI(x)
/*! @} */

/*!
 * @}
 */ /* end of group spp_dma5_MP_Register_Masks */

/*!
 * @}
 */ /* end of group spp_dma5_MP_Peripheral_Access_Layer */


/*! @name CH_CSR - Channel Control and Status */
/*! @{ */

#define DMA5_CH_CSR_ERQ_MASK                       spp_dma5_TCD_CH0_CSR_ERQ_MASK
#define DMA5_CH_CSR_ERQ_SHIFT                      spp_dma5_TCD_CH0_CSR_ERQ_SHIFT
#define DMA5_CH_CSR_ERQ_WIDTH                      spp_dma5_TCD_CH0_CSR_ERQ_WIDTH
#define DMA5_CH_CSR_ERQ(x)                         spp_dma5_TCD_CH0_CSR_ERQ(x)

#define DMA5_CH_CSR_EARQ_MASK                      spp_dma5_TCD_CH0_CSR_EARQ_MASK
#define DMA5_CH_CSR_EARQ_SHIFT                     spp_dma5_TCD_CH0_CSR_EARQ_SHIFT
#define DMA5_CH_CSR_EARQ_WIDTH                     spp_dma5_TCD_CH0_CSR_EARQ_WIDTH
#define DMA5_CH_CSR_EARQ(x)                        spp_dma5_TCD_CH0_CSR_EARQ(x)

#define DMA5_CH_CSR_EEI_MASK                       spp_dma5_TCD_CH0_CSR_EEI_MASK
#define DMA5_CH_CSR_EEI_SHIFT                      spp_dma5_TCD_CH0_CSR_EEI_SHIFT
#define DMA5_CH_CSR_EEI_WIDTH                      spp_dma5_TCD_CH0_CSR_EEI_WIDTH
#define DMA5_CH_CSR_EEI(x)                         spp_dma5_TCD_CH0_CSR_EEI(x)

#define DMA5_CH_CSR_CX_MASK                        spp_dma5_TCD_CH0_CSR_CX_MASK
#define DMA5_CH_CSR_CX_SHIFT                       spp_dma5_TCD_CH0_CSR_CX_SHIFT
#define DMA5_CH_CSR_CX_WIDTH                       spp_dma5_TCD_CH0_CSR_CX_WIDTH
#define DMA5_CH_CSR_CX(x)                          spp_dma5_TCD_CH0_CSR_CX(x)

#define DMA5_CH_CSR_ECX_MASK                       spp_dma5_TCD_CH0_CSR_ECX_MASK
#define DMA5_CH_CSR_ECX_SHIFT                      spp_dma5_TCD_CH0_CSR_ECX_SHIFT
#define DMA5_CH_CSR_ECX_WIDTH                      spp_dma5_TCD_CH0_CSR_ECX_WIDTH
#define DMA5_CH_CSR_ECX(x)                         spp_dma5_TCD_CH0_CSR_ECX(x)

#define DMA5_CH_CSR_SWAP_MASK                      spp_dma5_TCD_CH0_CSR_SWAP_MASK
#define DMA5_CH_CSR_SWAP_SHIFT                     spp_dma5_TCD_CH0_CSR_SWAP_SHIFT
#define DMA5_CH_CSR_SWAP_WIDTH                     spp_dma5_TCD_CH0_CSR_SWAP_WIDTH
#define DMA5_CH_CSR_SWAP(x)                        spp_dma5_TCD_CH0_CSR_SWAP(x)

#define DMA5_CH_CSR_SIGNEXT_MASK                   spp_dma5_TCD_CH0_CSR_SIGNEXT_MASK
#define DMA5_CH_CSR_SIGNEXT_SHIFT                  spp_dma5_TCD_CH0_CSR_SIGNEXT_SHIFT
#define DMA5_CH_CSR_SIGNEXT_WIDTH                  spp_dma5_TCD_CH0_CSR_SIGNEXT_WIDTH
#define DMA5_CH_CSR_SIGNEXT(x)                     spp_dma5_TCD_CH0_CSR_SIGNEXT(x)

#define DMA5_CH_CSR_DONE_MASK                      spp_dma5_TCD_CH0_CSR_DONE_MASK
#define DMA5_CH_CSR_DONE_SHIFT                     spp_dma5_TCD_CH0_CSR_DONE_SHIFT
#define DMA5_CH_CSR_DONE_WIDTH                     spp_dma5_TCD_CH0_CSR_DONE_WIDTH
#define DMA5_CH_CSR_DONE(x)                        spp_dma5_TCD_CH0_CSR_DONE(x)

#define DMA5_CH_CSR_ACTIVE_MASK                    spp_dma5_TCD_CH0_CSR_ACTIVE_MASK
#define DMA5_CH_CSR_ACTIVE_SHIFT                   spp_dma5_TCD_CH0_CSR_ACTIVE_SHIFT
#define DMA5_CH_CSR_ACTIVE_WIDTH                   spp_dma5_TCD_CH0_CSR_ACTIVE_WIDTH
#define DMA5_CH_CSR_ACTIVE(x)                      spp_dma5_TCD_CH0_CSR_ACTIVE(x)

/*! @} */

/*! @name CH_ES - Channel Error Status */
/*! @{ */

#define DMA5_CH_ES_DBE_MASK                        spp_dma5_TCD_CH0_ES_DBE_MASK
#define DMA5_CH_ES_DBE_SHIFT                       spp_dma5_TCD_CH0_ES_DBE_SHIFT
#define DMA5_CH_ES_DBE_WIDTH                       spp_dma5_TCD_CH0_ES_DBE_WIDTH
#define DMA5_CH_ES_DBE(x)                          spp_dma5_TCD_CH0_ES_DBE(x)

#define DMA5_CH_ES_SBE_MASK                        spp_dma5_TCD_CH0_ES_SBE_MASK
#define DMA5_CH_ES_SBE_SHIFT                       spp_dma5_TCD_CH0_ES_SBE_SHIFT
#define DMA5_CH_ES_SBE_WIDTH                       spp_dma5_TCD_CH0_ES_SBE_WIDTH
#define DMA5_CH_ES_SBE(x)                          spp_dma5_TCD_CH0_ES_SBE(x)

#define DMA5_CH_ES_SGE_MASK                        spp_dma5_TCD_CH0_ES_SGE_MASK
#define DMA5_CH_ES_SGE_SHIFT                       spp_dma5_TCD_CH0_ES_SGE_SHIFT
#define DMA5_CH_ES_SGE_WIDTH                       spp_dma5_TCD_CH0_ES_SGE_WIDTH
#define DMA5_CH_ES_SGE(x)                          spp_dma5_TCD_CH0_ES_SGE(x)

#define DMA5_CH_ES_NCE_MASK                        spp_dma5_TCD_CH0_ES_NCE_MASK
#define DMA5_CH_ES_NCE_SHIFT                       spp_dma5_TCD_CH0_ES_NCE_SHIFT
#define DMA5_CH_ES_NCE_WIDTH                       spp_dma5_TCD_CH0_ES_NCE_WIDTH
#define DMA5_CH_ES_NCE(x)                          spp_dma5_TCD_CH0_ES_NCE(x)

#define DMA5_CH_ES_DOE_MASK                        spp_dma5_TCD_CH0_ES_DOE_MASK
#define DMA5_CH_ES_DOE_SHIFT                       spp_dma5_TCD_CH0_ES_DOE_SHIFT
#define DMA5_CH_ES_DOE_WIDTH                       spp_dma5_TCD_CH0_ES_DOE_WIDTH
#define DMA5_CH_ES_DOE(x)                          spp_dma5_TCD_CH0_ES_DOE(x)

#define DMA5_CH_ES_DAE_MASK                        spp_dma5_TCD_CH0_ES_DAE_MASK
#define DMA5_CH_ES_DAE_SHIFT                       spp_dma5_TCD_CH0_ES_DAE_SHIFT
#define DMA5_CH_ES_DAE_WIDTH                       spp_dma5_TCD_CH0_ES_DAE_WIDTH
#define DMA5_CH_ES_DAE(x)                          spp_dma5_TCD_CH0_ES_DAE(x)

#define DMA5_CH_ES_SOE_MASK                        spp_dma5_TCD_CH0_ES_SOE_MASK
#define DMA5_CH_ES_SOE_SHIFT                       spp_dma5_TCD_CH0_ES_SOE_SHIFT
#define DMA5_CH_ES_SOE_WIDTH                       spp_dma5_TCD_CH0_ES_SOE_WIDTH
#define DMA5_CH_ES_SOE(x)                          spp_dma5_TCD_CH0_ES_SOE(x)

#define DMA5_CH_ES_SAE_MASK                        spp_dma5_TCD_CH0_ES_SAE_MASK
#define DMA5_CH_ES_SAE_SHIFT                       spp_dma5_TCD_CH0_ES_SAE_SHIFT
#define DMA5_CH_ES_SAE_WIDTH                       spp_dma5_TCD_CH0_ES_SAE_WIDTH
#define DMA5_CH_ES_SAE(x)                          spp_dma5_TCD_CH0_ES_SAE(x)

#define DMA5_CH_ES_ECX_MASK                        spp_dma5_TCD_CH0_ES_ECX_MASK
#define DMA5_CH_ES_ECX_SHIFT                       spp_dma5_TCD_CH0_ES_ECX_SHIFT
#define DMA5_CH_ES_ECX_WIDTH                       spp_dma5_TCD_CH0_ES_ECX_WIDTH
#define DMA5_CH_ES_ECX(x)                          spp_dma5_TCD_CH0_ES_ECX(x)

#define DMA5_CH_ES_UCE_MASK                        spp_dma5_TCD_CH0_ES_UCE_MASK
#define DMA5_CH_ES_UCE_SHIFT                       spp_dma5_TCD_CH0_ES_UCE_SHIFT
#define DMA5_CH_ES_UCE_WIDTH                       spp_dma5_TCD_CH0_ES_UCE_WIDTH
#define DMA5_CH_ES_UCE(x)                          spp_dma5_TCD_CH0_ES_UCE(x)

#define DMA5_CH_ES_ERR_MASK                        spp_dma5_TCD_CH0_ES_ERR_MASK
#define DMA5_CH_ES_ERR_SHIFT                       spp_dma5_TCD_CH0_ES_ERR_SHIFT
#define DMA5_CH_ES_ERR_WIDTH                       spp_dma5_TCD_CH0_ES_ERR_WIDTH
#define DMA5_CH_ES_ERR(x)                          spp_dma5_TCD_CH0_ES_ERR(x)

/*! @} */

/*! @name CH_INT - Channel Interrupt Status */
/*! @{ */

#define DMA5_CH_INT_INT_MASK                       spp_dma5_TCD_CH0_INT_INT_MASK
#define DMA5_CH_INT_INT_SHIFT                      spp_dma5_TCD_CH0_INT_INT_SHIFT
#define DMA5_CH_INT_INT_WIDTH                      spp_dma5_TCD_CH0_INT_INT_WIDTH
#define DMA5_CH_INT_INT(x)                         spp_dma5_TCD_CH0_INT_INT(x)

/*! @} */

/*! @name CH_SBR - Channel System Bus */
/*! @{ */

#define DMA5_CH_SBR_MID_MASK                       spp_dma5_TCD_CH0_SBR_MID_MASK
#define DMA5_CH_SBR_MID_SHIFT                      spp_dma5_TCD_CH0_SBR_MID_SHIFT
#define DMA5_CH_SBR_MID_WIDTH                      spp_dma5_TCD_CH0_SBR_MID_WIDTH
#define DMA5_CH_SBR_MID(x)                         spp_dma5_TCD_CH0_SBR_MID(x)

#define DMA5_CH_SBR_INSTR_MASK                     spp_dma5_TCD_CH0_SBR_INSTR_MASK
#define DMA5_CH_SBR_INSTR_SHIFT                    spp_dma5_TCD_CH0_SBR_INSTR_SHIFT
#define DMA5_CH_SBR_INSTR_WIDTH                    spp_dma5_TCD_CH0_SBR_INSTR_WIDTH
#define DMA5_CH_SBR_INSTR(x)                       spp_dma5_TCD_CH0_SBR_INSTR(x)

#define DMA5_CH_SBR_PAL_MASK                       spp_dma5_TCD_CH0_SBR_PAL_MASK
#define DMA5_CH_SBR_PAL_SHIFT                      spp_dma5_TCD_CH0_SBR_PAL_SHIFT
#define DMA5_CH_SBR_PAL_WIDTH                      spp_dma5_TCD_CH0_SBR_PAL_WIDTH
#define DMA5_CH_SBR_PAL(x)                         spp_dma5_TCD_CH0_SBR_PAL(x)

#define DMA5_CH_SBR_EMI_MASK                       spp_dma5_TCD_CH0_SBR_EMI_MASK
#define DMA5_CH_SBR_EMI_SHIFT                      spp_dma5_TCD_CH0_SBR_EMI_SHIFT
#define DMA5_CH_SBR_EMI_WIDTH                      spp_dma5_TCD_CH0_SBR_EMI_WIDTH
#define DMA5_CH_SBR_EMI(x)                         spp_dma5_TCD_CH0_SBR_EMI(x)

/*! @} */

/*! @name CH_PRI - Channel Priority */
/*! @{ */

#define DMA5_CH_PRI_APL_MASK                       spp_dma5_TCD_CH0_PRI_APL_MASK
#define DMA5_CH_PRI_APL_SHIFT                      spp_dma5_TCD_CH0_PRI_APL_SHIFT
#define DMA5_CH_PRI_APL_WIDTH                      spp_dma5_TCD_CH0_PRI_APL_WIDTH
#define DMA5_CH_PRI_APL(x)                         spp_dma5_TCD_CH0_PRI_APL(x)

#define DMA5_CH_PRI_DPA_MASK                       spp_dma5_TCD_CH0_PRI_DPA_MASK
#define DMA5_CH_PRI_DPA_SHIFT                      spp_dma5_TCD_CH0_PRI_DPA_SHIFT
#define DMA5_CH_PRI_DPA_WIDTH                      spp_dma5_TCD_CH0_PRI_DPA_WIDTH
#define DMA5_CH_PRI_DPA(x)                         spp_dma5_TCD_CH0_PRI_DPA(x)

#define DMA5_CH_PRI_ECP_MASK                       spp_dma5_TCD_CH0_PRI_ECP_MASK
#define DMA5_CH_PRI_ECP_SHIFT                      spp_dma5_TCD_CH0_PRI_ECP_SHIFT
#define DMA5_CH_PRI_ECP_WIDTH                      spp_dma5_TCD_CH0_PRI_ECP_WIDTH
#define DMA5_CH_PRI_ECP(x)                         spp_dma5_TCD_CH0_PRI_ECP(x)

/*! @} */

/*! @name CH_MATTR - Memory Attributes */
/*! @{ */

#define DMA5_CH_MATTR_RCACHE_MASK                  spp_dma5_TCD_CH0_MATTR_RCACHE_MASK
#define DMA5_CH_MATTR_RCACHE_SHIFT                 spp_dma5_TCD_CH0_MATTR_RCACHE_SHIFT
#define DMA5_CH_MATTR_RCACHE_WIDTH                 spp_dma5_TCD_CH0_MATTR_RCACHE_WIDTH
#define DMA5_CH_MATTR_RCACHE(x)                    spp_dma5_TCD_CH0_MATTR_RCACHE(x)

#define DMA5_CH_MATTR_WCACHE_MASK                  spp_dma5_TCD_CH0_MATTR_WCACHE_MASK
#define DMA5_CH_MATTR_WCACHE_SHIFT                 spp_dma5_TCD_CH0_MATTR_WCACHE_SHIFT
#define DMA5_CH_MATTR_WCACHE_WIDTH                 spp_dma5_TCD_CH0_MATTR_WCACHE_WIDTH
#define DMA5_CH_MATTR_WCACHE(x)                    spp_dma5_TCD_CH0_MATTR_WCACHE(x)

/*! @} */

/*! @name SADDR - TCD Source Address */
/*! @{ */

#define DMA5_SADDR_SADDR_MASK                      spp_dma5_TCD_TCD0_SADDR_SADDR_MASK
#define DMA5_SADDR_SADDR_SHIFT                     spp_dma5_TCD_TCD0_SADDR_SADDR_SHIFT
#define DMA5_SADDR_SADDR_WIDTH                     spp_dma5_TCD_TCD0_SADDR_SADDR_WIDTH
#define DMA5_SADDR_SADDR(x)                        spp_dma5_TCD_TCD0_SADDR_SADDR(x)

/*! @} */

/*! @name SADDR_HIGH - TCD Source Address */
/*! @{ */

#define DMA5_SADDR_HIGH_SADDR_MASK                 spp_dma5_TCD_TCD0_SADDR_HIGH_SADDR_MASK
#define DMA5_SADDR_HIGH_SADDR_SHIFT                spp_dma5_TCD_TCD0_SADDR_HIGH_SADDR_SHIFT
#define DMA5_SADDR_HIGH_SADDR_WIDTH                spp_dma5_TCD_TCD0_SADDR_HIGH_SADDR_WIDTH
#define DMA5_SADDR_HIGH_SADDR(x)                   spp_dma5_TCD_TCD0_SADDR_HIGH_SADDR(x)

/*! @} */

/*! @name SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA5_SOFF_SOFF_MASK                        spp_dma5_TCD_TCD0_SOFF_SOFF_MASK
#define DMA5_SOFF_SOFF_SHIFT                       spp_dma5_TCD_TCD0_SOFF_SOFF_SHIFT
#define DMA5_SOFF_SOFF_WIDTH                       spp_dma5_TCD_TCD0_SOFF_SOFF_WIDTH
#define DMA5_SOFF_SOFF(x)                          spp_dma5_TCD_TCD0_SOFF_SOFF(x)

/*! @name ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA5_ATTR_DSIZE_MASK                       spp_dma5_TCD_TCD0_ATTR_DSIZE_MASK
#define DMA5_ATTR_DSIZE_SHIFT                      spp_dma5_TCD_TCD0_ATTR_DSIZE_SHIFT
#define DMA5_ATTR_DSIZE_WIDTH                      spp_dma5_TCD_TCD0_ATTR_DSIZE_WIDTH
#define DMA5_ATTR_DSIZE(x)                         spp_dma5_TCD_TCD0_ATTR_DSIZE(x)

#define DMA5_ATTR_DMOD_MASK                        spp_dma5_TCD_TCD0_ATTR_DMOD_MASK
#define DMA5_ATTR_DMOD_SHIFT                       spp_dma5_TCD_TCD0_ATTR_DMOD_SHIFT
#define DMA5_ATTR_DMOD_WIDTH                       spp_dma5_TCD_TCD0_ATTR_DMOD_WIDTH
#define DMA5_ATTR_DMOD(x)                          spp_dma5_TCD_TCD0_ATTR_DMOD(x)

#define DMA5_ATTR_SSIZE_MASK                       spp_dma5_TCD_TCD0_ATTR_SSIZE_MASK
#define DMA5_ATTR_SSIZE_SHIFT                      spp_dma5_TCD_TCD0_ATTR_SSIZE_SHIFT
#define DMA5_ATTR_SSIZE_WIDTH                      spp_dma5_TCD_TCD0_ATTR_SSIZE_WIDTH
#define DMA5_ATTR_SSIZE(x)                         spp_dma5_TCD_TCD0_ATTR_SSIZE(x)

#define DMA5_ATTR_SMOD_MASK                        spp_dma5_TCD_TCD0_ATTR_SMOD_MASK
#define DMA5_ATTR_SMOD_SHIFT                       spp_dma5_TCD_TCD0_ATTR_SMOD_SHIFT
#define DMA5_ATTR_SMOD_WIDTH                       spp_dma5_TCD_TCD0_ATTR_SMOD_WIDTH
#define DMA5_ATTR_SMOD(x)                          spp_dma5_TCD_TCD0_ATTR_SMOD(x)
/*! @} */

/*! @name NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA5_NBYTES_MLOFFNO_NBYTES_MASK            spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_MASK
#define DMA5_NBYTES_MLOFFNO_NBYTES_SHIFT           spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_SHIFT
#define DMA5_NBYTES_MLOFFNO_NBYTES_WIDTH           spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_NBYTES_WIDTH
#define DMA5_NBYTES_MLOFFNO_NBYTES(x)              spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_NBYTES(x)

#define DMA5_NBYTES_MLOFFNO_DMLOE_MASK             spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_MASK
#define DMA5_NBYTES_MLOFFNO_DMLOE_SHIFT            spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_SHIFT
#define DMA5_NBYTES_MLOFFNO_DMLOE_WIDTH            spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_DMLOE_WIDTH
#define DMA5_NBYTES_MLOFFNO_DMLOE(x)               spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_DMLOE(x)

#define DMA5_NBYTES_MLOFFNO_SMLOE_MASK             spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_MASK
#define DMA5_NBYTES_MLOFFNO_SMLOE_SHIFT            spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_SHIFT
#define DMA5_NBYTES_MLOFFNO_SMLOE_WIDTH            spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_SMLOE_WIDTH
#define DMA5_NBYTES_MLOFFNO_SMLOE(x)               spp_dma5_TCD_TCD0_NBYTES_MLOFFNO_SMLOE(x)
/*! @} */

/*! @name NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA5_NBYTES_MLOFFYES_NBYTES_MASK           spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_MASK
#define DMA5_NBYTES_MLOFFYES_NBYTES_SHIFT          spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_SHIFT
#define DMA5_NBYTES_MLOFFYES_NBYTES_WIDTH          spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_NBYTES_WIDTH
#define DMA5_NBYTES_MLOFFYES_NBYTES(x)             spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_NBYTES(x)

#define DMA5_NBYTES_MLOFFYES_MLOFF_MASK            spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_MASK
#define DMA5_NBYTES_MLOFFYES_MLOFF_SHIFT           spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_SHIFT
#define DMA5_NBYTES_MLOFFYES_MLOFF_WIDTH           spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_MLOFF_WIDTH
#define DMA5_NBYTES_MLOFFYES_MLOFF(x)              spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_MLOFF(x)

#define DMA5_NBYTES_MLOFFYES_DMLOE_MASK            spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_MASK
#define DMA5_NBYTES_MLOFFYES_DMLOE_SHIFT           spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_SHIFT
#define DMA5_NBYTES_MLOFFYES_DMLOE_WIDTH           spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_DMLOE_WIDTH
#define DMA5_NBYTES_MLOFFYES_DMLOE(x)              spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_DMLOE(x)

#define DMA5_NBYTES_MLOFFYES_SMLOE_MASK            spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_MASK
#define DMA5_NBYTES_MLOFFYES_SMLOE_SHIFT           spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_SHIFT
#define DMA5_NBYTES_MLOFFYES_SMLOE_WIDTH           spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_SMLOE_WIDTH
#define DMA5_NBYTES_MLOFFYES_SMLOE(x)              spp_dma5_TCD_TCD0_NBYTES_MLOFFYES_SMLOE(x)
/*! @} */

/*! @name SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define DMA5_SLAST_SDA_SLAST_SDA_MASK              spp_dma5_TCD_TCD0_SLAST_SDA_SLAST_SDA_MASK
#define DMA5_SLAST_SDA_SLAST_SDA_SHIFT             spp_dma5_TCD_TCD0_SLAST_SDA_SLAST_SDA_SHIFT
#define DMA5_SLAST_SDA_SLAST_SDA_WIDTH             spp_dma5_TCD_TCD0_SLAST_SDA_SLAST_SDA_WIDTH
#define DMA5_SLAST_SDA_SLAST_SDA(x)                spp_dma5_TCD_TCD0_SLAST_SDA_SLAST_SDA(x)
/*! @} */

/*! @name SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define DMA5_SLAST_SDA_HIGH_SLAST_SDA_MASK         spp_dma5_TCD_TCD0_SLAST_SDA_HIGH_SLAST_SDA_MASK
#define DMA5_SLAST_SDA_HIGH_SLAST_SDA_SHIFT        spp_dma5_TCD_TCD0_SLAST_SDA_HIGH_SLAST_SDA_SHIFT
#define DMA5_SLAST_SDA_HIGH_SLAST_SDA_WIDTH        spp_dma5_TCD_TCD0_SLAST_SDA_HIGH_SLAST_SDA_WIDTH
#define DMA5_SLAST_SDA_HIGH_SLAST_SDA(x)           spp_dma5_TCD_TCD0_SLAST_SDA_HIGH_SLAST_SDA(x)
/*! @} */

/*! @name DADDR - TCD Destination Address */
/*! @{ */

#define DMA5_DADDR_DADDR_MASK                      spp_dma5_TCD_TCD0_DADDR_DADDR_MASK
#define DMA5_DADDR_DADDR_SHIFT                     spp_dma5_TCD_TCD0_DADDR_DADDR_SHIFT
#define DMA5_DADDR_DADDR_WIDTH                     spp_dma5_TCD_TCD0_DADDR_DADDR_WIDTH
#define DMA5_DADDR_DADDR(x)                        spp_dma5_TCD_TCD0_DADDR_DADDR(x)
/*! @} */

/*! @name DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define DMA5_DADDR_HIGH_DADDR_MASK                 spp_dma5_TCD_TCD0_DADDR_HIGH_DADDR_MASK
#define DMA5_DADDR_HIGH_DADDR_SHIFT                spp_dma5_TCD_TCD0_DADDR_HIGH_DADDR_SHIFT
#define DMA5_DADDR_HIGH_DADDR_WIDTH                spp_dma5_TCD_TCD0_DADDR_HIGH_DADDR_WIDTH
#define DMA5_DADDR_HIGH_DADDR(x)                   spp_dma5_TCD_TCD0_DADDR_HIGH_DADDR(x)
/*! @} */

/*! @name DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define DMA5_DLAST_SGA_DLAST_SGA_MASK              spp_dma5_TCD_TCD0_DLAST_SGA_DLAST_SGA_MASK
#define DMA5_DLAST_SGA_DLAST_SGA_SHIFT             spp_dma5_TCD_TCD0_DLAST_SGA_DLAST_SGA_SHIFT
#define DMA5_DLAST_SGA_DLAST_SGA_WIDTH             spp_dma5_TCD_TCD0_DLAST_SGA_DLAST_SGA_WIDTH
#define DMA5_DLAST_SGA_DLAST_SGA(x)                spp_dma5_TCD_TCD0_DLAST_SGA_DLAST_SGA(x)
/*! @} */

/*! @name DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define DMA5_DLAST_SGA_HIGH_DLAST_SGA_MASK         spp_dma5_TCD_TCD0_DLAST_SGA_HIGH_DLAST_SGA_MASK
#define DMA5_DLAST_SGA_HIGH_DLAST_SGA_SHIFT        spp_dma5_TCD_TCD0_DLAST_SGA_HIGH_DLAST_SGA_SHIFT
#define DMA5_DLAST_SGA_HIGH_DLAST_SGA_WIDTH        spp_dma5_TCD_TCD0_DLAST_SGA_HIGH_DLAST_SGA_WIDTH
#define DMA5_DLAST_SGA_HIGH_DLAST_SGA(x)           spp_dma5_TCD_TCD0_DLAST_SGA_HIGH_DLAST_SGA(x)
/*! @} */

/*! @name DOFF - TCD Signed Destination Address Offset */
/*! @{ */
#define DMA5_DOFF_DOFF_MASK                        spp_dma5_TCD_TCD0_DOFF_DOFF_MASK
#define DMA5_DOFF_DOFF_SHIFT                       spp_dma5_TCD_TCD0_DOFF_DOFF_SHIFT
#define DMA5_DOFF_DOFF_WIDTH                       spp_dma5_TCD_TCD0_DOFF_DOFF_WIDTH
#define DMA5_DOFF_DOFF(x)                          spp_dma5_TCD_TCD0_DOFF_DOFF(x)
/*! @} */

/*! @name CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA5_CITER_ELINKNO_CITER_MASK              spp_dma5_TCD_TCD0_CITER_ELINKNO_CITER_MASK
#define DMA5_CITER_ELINKNO_CITER_SHIFT             spp_dma5_TCD_TCD0_CITER_ELINKNO_CITER_SHIFT
#define DMA5_CITER_ELINKNO_CITER_WIDTH             spp_dma5_TCD_TCD0_CITER_ELINKNO_CITER_WIDTH
#define DMA5_CITER_ELINKNO_CITER(x)                spp_dma5_TCD_TCD0_CITER_ELINKNO_CITER(x)

#define DMA5_CITER_ELINKNO_ELINK_MASK              spp_dma5_TCD_TCD0_CITER_ELINKNO_ELINK_MASK
#define DMA5_CITER_ELINKNO_ELINK_SHIFT             spp_dma5_TCD_TCD0_CITER_ELINKNO_ELINK_SHIFT
#define DMA5_CITER_ELINKNO_ELINK_WIDTH             spp_dma5_TCD_TCD0_CITER_ELINKNO_ELINK_WIDTH
#define DMA5_CITER_ELINKNO_ELINK(x)                spp_dma5_TCD_TCD0_CITER_ELINKNO_ELINK(x)
/*! @} */

/*! @name CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA5_CITER_ELINKYES_CITER_MASK             spp_dma5_TCD_TCD0_CITER_ELINKYES_CITER_MASK
#define DMA5_CITER_ELINKYES_CITER_SHIFT            spp_dma5_TCD_TCD0_CITER_ELINKYES_CITER_SHIFT
#define DMA5_CITER_ELINKYES_CITER_WIDTH            spp_dma5_TCD_TCD0_CITER_ELINKYES_CITER_WIDTH
#define DMA5_CITER_ELINKYES_CITER(x)               spp_dma5_TCD_TCD0_CITER_ELINKYES_CITER(x)

#define DMA5_CITER_ELINKYES_LINKCH_MASK            spp_dma5_TCD_TCD0_CITER_ELINKYES_LINKCH_MASK
#define DMA5_CITER_ELINKYES_LINKCH_SHIFT           spp_dma5_TCD_TCD0_CITER_ELINKYES_LINKCH_SHIFT
#define DMA5_CITER_ELINKYES_LINKCH_WIDTH           spp_dma5_TCD_TCD0_CITER_ELINKYES_LINKCH_WIDTH
#define DMA5_CITER_ELINKYES_LINKCH(x)              spp_dma5_TCD_TCD0_CITER_ELINKYES_LINKCH(x)

#define DMA5_CITER_ELINKYES_ELINK_MASK             spp_dma5_TCD_TCD0_CITER_ELINKYES_ELINK_MASK
#define DMA5_CITER_ELINKYES_ELINK_SHIFT            spp_dma5_TCD_TCD0_CITER_ELINKYES_ELINK_SHIFT
#define DMA5_CITER_ELINKYES_ELINK_WIDTH            spp_dma5_TCD_TCD0_CITER_ELINKYES_ELINK_WIDTH
#define DMA5_CITER_ELINKYES_ELINK(x)               spp_dma5_TCD_TCD0_CITER_ELINKYES_ELINK(x)
/*! @} */

/*! @name CSR - TCD Control and Status */
/*! @{ */

#define DMA5_CSR_START_MASK                        spp_dma5_TCD_TCD0_CSR_START_MASK
#define DMA5_CSR_START_SHIFT                       spp_dma5_TCD_TCD0_CSR_START_SHIFT
#define DMA5_CSR_START_WIDTH                       spp_dma5_TCD_TCD0_CSR_START_WIDTH
#define DMA5_CSR_START(x)                          spp_dma5_TCD_TCD0_CSR_START(x)

#define DMA5_CSR_INTMAJOR_MASK                     spp_dma5_TCD_TCD0_CSR_INTMAJOR_MASK
#define DMA5_CSR_INTMAJOR_SHIFT                    spp_dma5_TCD_TCD0_CSR_INTMAJOR_SHIFT
#define DMA5_CSR_INTMAJOR_WIDTH                    spp_dma5_TCD_TCD0_CSR_INTMAJOR_WIDTH
#define DMA5_CSR_INTMAJOR(x)                       spp_dma5_TCD_TCD0_CSR_INTMAJOR(x)

#define DMA5_CSR_INTHALF_MASK                      spp_dma5_TCD_TCD0_CSR_INTHALF_MASK
#define DMA5_CSR_INTHALF_SHIFT                     spp_dma5_TCD_TCD0_CSR_INTHALF_SHIFT
#define DMA5_CSR_INTHALF_WIDTH                     spp_dma5_TCD_TCD0_CSR_INTHALF_WIDTH
#define DMA5_CSR_INTHALF(x)                        spp_dma5_TCD_TCD0_CSR_INTHALF(x)

#define DMA5_CSR_DREQ_MASK                         spp_dma5_TCD_TCD0_CSR_DREQ_MASK
#define DMA5_CSR_DREQ_SHIFT                        spp_dma5_TCD_TCD0_CSR_DREQ_SHIFT
#define DMA5_CSR_DREQ_WIDTH                        spp_dma5_TCD_TCD0_CSR_DREQ_WIDTH
#define DMA5_CSR_DREQ(x)                           spp_dma5_TCD_TCD0_CSR_DREQ(x)

#define DMA5_CSR_ESG_MASK                          spp_dma5_TCD_TCD0_CSR_ESG_MASK
#define DMA5_CSR_ESG_SHIFT                         spp_dma5_TCD_TCD0_CSR_ESG_SHIFT
#define DMA5_CSR_ESG_WIDTH                         spp_dma5_TCD_TCD0_CSR_ESG_WIDTH
#define DMA5_CSR_ESG(x)                            spp_dma5_TCD_TCD0_CSR_ESG(x)

#define DMA5_CSR_MAJORELINK_MASK                   spp_dma5_TCD_TCD0_CSR_MAJORELINK_MASK
#define DMA5_CSR_MAJORELINK_SHIFT                  spp_dma5_TCD_TCD0_CSR_MAJORELINK_SHIFT
#define DMA5_CSR_MAJORELINK_WIDTH                  spp_dma5_TCD_TCD0_CSR_MAJORELINK_WIDTH
#define DMA5_CSR_MAJORELINK(x)                     spp_dma5_TCD_TCD0_CSR_MAJORELINK(x)

#define DMA5_CSR_ESDA_MASK                         spp_dma5_TCD_TCD0_CSR_ESDA_MASK
#define DMA5_CSR_ESDA_SHIFT                        spp_dma5_TCD_TCD0_CSR_ESDA_SHIFT
#define DMA5_CSR_ESDA_WIDTH                        spp_dma5_TCD_TCD0_CSR_ESDA_WIDTH
#define DMA5_CSR_ESDA(x)                           spp_dma5_TCD_TCD0_CSR_ESDA(x)

#define DMA5_CSR_MAJORLINKCH_MASK                  spp_dma5_TCD_TCD0_CSR_MAJORLINKCH_MASK
#define DMA5_CSR_MAJORLINKCH_SHIFT                 spp_dma5_TCD_TCD0_CSR_MAJORLINKCH_SHIFT
#define DMA5_CSR_MAJORLINKCH_WIDTH                 spp_dma5_TCD_TCD0_CSR_MAJORLINKCH_WIDTH
#define DMA5_CSR_MAJORLINKCH(x)                    spp_dma5_TCD_TCD0_CSR_MAJORLINKCH(x)

#define DMA5_CSR_TMC_MASK                          spp_dma5_TCD_TCD0_CSR_TMC_MASK
#define DMA5_CSR_TMC_SHIFT                         spp_dma5_TCD_TCD0_CSR_TMC_SHIFT
#define DMA5_CSR_TMC_WIDTH                         spp_dma5_TCD_TCD0_CSR_TMC_WIDTH
#define DMA5_CSR_TMC(x)                            spp_dma5_TCD_TCD0_CSR_TMC(x)
/*! @} */

/*! @name BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA5_BITER_ELINKNO_BITER_MASK              spp_dma5_TCD_TCD0_BITER_ELINKNO_BITER_MASK
#define DMA5_BITER_ELINKNO_BITER_SHIFT             spp_dma5_TCD_TCD0_BITER_ELINKNO_BITER_SHIFT
#define DMA5_BITER_ELINKNO_BITER_WIDTH             spp_dma5_TCD_TCD0_BITER_ELINKNO_BITER_WIDTH
#define DMA5_BITER_ELINKNO_BITER(x)                spp_dma5_TCD_TCD0_BITER_ELINKNO_BITER(x)

#define DMA5_BITER_ELINKNO_ELINK_MASK              spp_dma5_TCD_TCD0_BITER_ELINKNO_ELINK_MASK
#define DMA5_BITER_ELINKNO_ELINK_SHIFT             spp_dma5_TCD_TCD0_BITER_ELINKNO_ELINK_SHIFT
#define DMA5_BITER_ELINKNO_ELINK_WIDTH             spp_dma5_TCD_TCD0_BITER_ELINKNO_ELINK_WIDTH
#define DMA5_BITER_ELINKNO_ELINK(x)                spp_dma5_TCD_TCD0_BITER_ELINKNO_ELINK(x)
/*! @} */

/*! @name BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA5_BITER_ELINKYES_BITER_MASK             spp_dma5_TCD_TCD0_BITER_ELINKYES_BITER_MASK
#define DMA5_BITER_ELINKYES_BITER_SHIFT            spp_dma5_TCD_TCD0_BITER_ELINKYES_BITER_SHIFT
#define DMA5_BITER_ELINKYES_BITER_WIDTH            spp_dma5_TCD_TCD0_BITER_ELINKYES_BITER_WIDTH
#define DMA5_BITER_ELINKYES_BITER(x)               spp_dma5_TCD_TCD0_BITER_ELINKYES_BITER(x)

#define DMA5_BITER_ELINKYES_LINKCH_MASK            spp_dma5_TCD_TCD0_BITER_ELINKYES_LINKCH_MASK
#define DMA5_BITER_ELINKYES_LINKCH_SHIFT           spp_dma5_TCD_TCD0_BITER_ELINKYES_LINKCH_SHIFT
#define DMA5_BITER_ELINKYES_LINKCH_WIDTH           spp_dma5_TCD_TCD0_BITER_ELINKYES_LINKCH_WIDTH
#define DMA5_BITER_ELINKYES_LINKCH(x)              spp_dma5_TCD_TCD0_BITER_ELINKYES_LINKCH(x)

#define DMA5_BITER_ELINKYES_ELINK_MASK             spp_dma5_TCD_TCD0_BITER_ELINKYES_ELINK_MASK
#define DMA5_BITER_ELINKYES_ELINK_SHIFT            spp_dma5_TCD_TCD0_BITER_ELINKYES_ELINK_SHIFT
#define DMA5_BITER_ELINKYES_ELINK_WIDTH            spp_dma5_TCD_TCD0_BITER_ELINKYES_ELINK_WIDTH
#define DMA5_BITER_ELINKYES_ELINK(x)               spp_dma5_TCD_TCD0_BITER_ELINKYES_ELINK(x)
/*! @} */

/*!
 * @}
 */ /* end of group spp_dma5_TCD_Register_Masks */

/*!
 * @}
 */ /* end of group spp_dma5_TCD_Peripheral_Access_Layer */

#endif /* _S32K566_DEVICE_H_ */
