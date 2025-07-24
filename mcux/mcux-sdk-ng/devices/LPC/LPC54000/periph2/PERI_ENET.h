/*
** ###################################################################
**     Processors:          LPC54018J2MET180
**                          LPC54018J4MET180
**                          LPC54S018J2MET180
**                          LPC54S018J4MET180
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ENET
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ENET.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ENET
 *
 * CMSIS Peripheral Access Layer for ENET
 */

#if !defined(PERI_ENET_H_)
#define PERI_ENET_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54018J2MET180) || defined(CPU_LPC54018J4MET180))
#include "LPC54018M_COMMON.h"
#elif (defined(CPU_LPC54S018J2MET180) || defined(CPU_LPC54S018J4MET180))
#include "LPC54S018M_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ENET Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_Peripheral_Access_Layer ENET Peripheral Access Layer
 * @{
 */

/** ENET - Size of Registers Arrays */
#define ENET_MAC_TX_FLOW_CTRL_Q_COUNT             2u
#define ENET_MAC_RXQ_CTRL_COUNT                   3u
#define ENET_MAC_HW_FEAT_COUNT                    3u
#define ENET_MTL_QUEUE_COUNT                      2u
#define ENET_DMA_CH_COUNT                         2u

/** ENET - Register Layout Typedef */
typedef struct {
  __IO uint32_t MAC_CONFIG;                        /**< MAC configuration register, offset: 0x0 */
  __IO uint32_t MAC_EXT_CONFIG;                    /**< offset: 0x4 */
  __IO uint32_t MAC_FRAME_FILTER;                  /**< MAC frame filter register, offset: 0x8 */
  __IO uint32_t MAC_WD_TIMEROUT;                   /**< MAC watchdog Timeout register, offset: 0xC */
       uint8_t RESERVED_0[64];
  __IO uint32_t MAC_VLAN_TAG;                      /**< MAC vlan tag register, offset: 0x50 */
       uint8_t RESERVED_1[28];
  __IO uint32_t MAC_TX_FLOW_CTRL_Q[ENET_MAC_TX_FLOW_CTRL_Q_COUNT]; /**< Transmit flow control register, array offset: 0x70, array step: 0x4 */
       uint8_t RESERVED_2[24];
  __IO uint32_t MAC_RX_FLOW_CTRL;                  /**< Receive flow control register, offset: 0x90 */
       uint8_t RESERVED_3[4];
  __IO uint32_t MAC_TXQ_PRIO_MAP;                  /**< offset: 0x98 */
       uint8_t RESERVED_4[4];
  __IO uint32_t MAC_RXQ_CTRL[ENET_MAC_RXQ_CTRL_COUNT]; /**< Receive Queue Control 0 register 0x0000, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_5[4];
  __I  uint32_t MAC_INTR_STAT;                     /**< Interrupt status register 0x0000, offset: 0xB0 */
  __IO uint32_t MAC_INTR_EN;                       /**< Interrupt enable register 0x0000, offset: 0xB4 */
  __I  uint32_t MAC_RXTX_STAT;                     /**< Receive Transmit Status register, offset: 0xB8 */
       uint8_t RESERVED_6[4];
  __IO uint32_t MAC_PMT_CRTL_STAT;                 /**< offset: 0xC0 */
  __IO uint32_t MAC_RWAKE_FRFLT;                   /**< Remote wake-up frame filter, offset: 0xC4 */
       uint8_t RESERVED_7[8];
  __IO uint32_t MAC_LPI_CTRL_STAT;                 /**< LPI Control and Status Register, offset: 0xD0 */
  __IO uint32_t MAC_LPI_TIMER_CTRL;                /**< LPI Timers Control register, offset: 0xD4 */
  __IO uint32_t MAC_LPI_ENTR_TIMR;                 /**< LPI entry Timer register, offset: 0xD8 */
  __IO uint32_t MAC_1US_TIC_COUNTR;                /**< offset: 0xDC */
       uint8_t RESERVED_8[48];
  __I  uint32_t MAC_VERSION;                       /**< MAC version register, offset: 0x110 */
  __I  uint32_t MAC_DBG;                           /**< MAC debug register, offset: 0x114 */
       uint8_t RESERVED_9[4];
  __I  uint32_t MAC_HW_FEAT[ENET_MAC_HW_FEAT_COUNT]; /**< MAC hardware feature register 0x0201, array offset: 0x11C, array step: 0x4 */
       uint8_t RESERVED_10[216];
  __IO uint32_t MAC_MDIO_ADDR;                     /**< MIDO address Register, offset: 0x200 */
  __IO uint32_t MAC_MDIO_DATA;                     /**< MDIO Data register, offset: 0x204 */
       uint8_t RESERVED_11[248];
  __IO uint32_t MAC_ADDR_HIGH;                     /**< MAC address0 high register, offset: 0x300 */
  __IO uint32_t MAC_ADDR_LOW;                      /**< MAC address0 low register, offset: 0x304 */
       uint8_t RESERVED_12[2040];
  __IO uint32_t MAC_TIMESTAMP_CTRL;                /**< Time stamp control register, offset: 0xB00 */
  __IO uint32_t MAC_SUB_SCND_INCR;                 /**< Sub-second increment register, offset: 0xB04 */
  __I  uint32_t MAC_SYS_TIME_SCND;                 /**< System time seconds register, offset: 0xB08 */
  __I  uint32_t MAC_SYS_TIME_NSCND;                /**< System time nanoseconds register, offset: 0xB0C */
  __IO uint32_t MAC_SYS_TIME_SCND_UPD;             /**< offset: 0xB10 */
  __IO uint32_t MAC_SYS_TIME_NSCND_UPD;            /**< offset: 0xB14 */
  __IO uint32_t MAC_SYS_TIMESTMP_ADDEND;           /**< Time stamp addend register, offset: 0xB18 */
  __IO uint32_t MAC_SYS_TIME_HWORD_SCND;           /**< offset: 0xB1C */
  __I  uint32_t MAC_SYS_TIMESTMP_STAT;             /**< Time stamp status register, offset: 0xB20 */
       uint8_t RESERVED_13[12];
  __I  uint32_t MAC_TX_TIMESTAMP_STATUS_NANOSECONDS; /**< Tx timestamp status nanoseconds, offset: 0xB30 */
  __I  uint32_t MAC_TX_TIMESTAMP_STATUS_SECONDS;   /**< Tx timestamp status seconds, offset: 0xB34 */
       uint8_t RESERVED_14[32];
  __IO uint32_t MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND; /**< Timestamp ingress correction, offset: 0xB58 */
  __IO uint32_t MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND; /**< Timestamp egress correction, offset: 0xB5C */
       uint8_t RESERVED_15[160];
  __IO uint32_t MTL_OP_MODE;                       /**< MTL Operation Mode Register, offset: 0xC00 */
       uint8_t RESERVED_16[28];
  __I  uint32_t MTL_INTR_STAT;                     /**< MTL Interrupt Status register, offset: 0xC20 */
       uint8_t RESERVED_17[12];
  __IO uint32_t MTL_RXQ_DMA_MAP;                   /**< MTL Receive Queue and DMA Channel Mapping register, offset: 0xC30 */
       uint8_t RESERVED_18[204];
  struct {                                         /* offset: 0xD00, array step: 0x40 */
    __IO uint32_t MTL_TXQX_OP_MODE;                  /**< MTL TxQx Operation Mode register, array offset: 0xD00, array step: 0x40 */
    __I  uint32_t MTL_TXQX_UNDRFLW;                  /**< MTL TxQx Underflow register, array offset: 0xD04, array step: 0x40 */
    __I  uint32_t MTL_TXQX_DBG;                      /**< MTL TxQx Debug register, array offset: 0xD08, array step: 0x40 */
         uint8_t RESERVED_0[4];
    __IO uint32_t MTL_TXQX_ETS_CTRL;                 /**< MTL TxQx ETS control register, only TxQ1 support, array offset: 0xD10, array step: 0x40 */
    __I  uint32_t MTL_TXQX_ETS_STAT;                 /**< MTL TxQx ETS Status register, array offset: 0xD14, array step: 0x40 */
    __IO uint32_t MTL_TXQX_QNTM_WGHT;                /**< array offset: 0xD18, array step: 0x40 */
    __IO uint32_t MTL_TXQX_SNDSLP_CRDT;              /**< MTL TxQx SendSlopCredit register, only TxQ1 support, array offset: 0xD1C, array step: 0x40 */
    __IO uint32_t MTL_TXQX_HI_CRDT;                  /**< MTL TxQx hiCredit register, only TxQ1 support, array offset: 0xD20, array step: 0x40 */
    __IO uint32_t MTL_TXQX_LO_CRDT;                  /**< MTL TxQx loCredit register, only TxQ1 support, array offset: 0xD24, array step: 0x40 */
         uint8_t RESERVED_1[4];
    __IO uint32_t MTL_TXQX_INTCTRL_STAT;             /**< array offset: 0xD2C, array step: 0x40 */
    __IO uint32_t MTL_RXQX_OP_MODE;                  /**< MTL RxQx Operation Mode register, array offset: 0xD30, array step: 0x40 */
    __I  uint32_t MTL_RXQX_MISSPKT_OVRFLW_CNT;       /**< MTL RxQx Missed Packet Overflow Counter register, array offset: 0xD34, array step: 0x40 */
    __I  uint32_t MTL_RXQX_DBG;                      /**< MTL RxQx Debug register, array offset: 0xD38, array step: 0x40 */
    __IO uint32_t MTL_RXQX_CTRL;                     /**< MTL RxQx Control register, array offset: 0xD3C, array step: 0x40 */
  } MTL_QUEUE[ENET_MTL_QUEUE_COUNT];
       uint8_t RESERVED_19[640];
  __IO uint32_t DMA_MODE;                          /**< DMA mode register, offset: 0x1000 */
  __IO uint32_t DMA_SYSBUS_MODE;                   /**< DMA System Bus mode, offset: 0x1004 */
  __IO uint32_t DMA_INTR_STAT;                     /**< DMA Interrupt status, offset: 0x1008 */
  __I  uint32_t DMA_DBG_STAT;                      /**< DMA Debug Status, offset: 0x100C */
       uint8_t RESERVED_20[240];
  struct {                                         /* offset: 0x1100, array step: 0x80 */
    __IO uint32_t DMA_CHX_CTRL;                      /**< DMA Channelx Control, array offset: 0x1100, array step: 0x80 */
    __IO uint32_t DMA_CHX_TX_CTRL;                   /**< DMA Channelx Transmit Control, array offset: 0x1104, array step: 0x80 */
    __IO uint32_t DMA_CHX_RX_CTRL;                   /**< DMA Channelx Receive Control, array offset: 0x1108, array step: 0x80 */
         uint8_t RESERVED_0[8];
    __IO uint32_t DMA_CHX_TXDESC_LIST_ADDR;          /**< array offset: 0x1114, array step: 0x80 */
         uint8_t RESERVED_1[4];
    __IO uint32_t DMA_CHX_RXDESC_LIST_ADDR;          /**< array offset: 0x111C, array step: 0x80 */
    __IO uint32_t DMA_CHX_TXDESC_TAIL_PTR;           /**< array offset: 0x1120, array step: 0x80 */
         uint8_t RESERVED_2[4];
    __IO uint32_t DMA_CHX_RXDESC_TAIL_PTR;           /**< array offset: 0x1128, array step: 0x80 */
    __IO uint32_t DMA_CHX_TXDESC_RING_LENGTH;        /**< array offset: 0x112C, array step: 0x80 */
    __IO uint32_t DMA_CHX_RXDESC_RING_LENGTH;        /**< Channelx Rx descriptor Ring Length, array offset: 0x1130, array step: 0x80 */
    __IO uint32_t DMA_CHX_INT_EN;                    /**< Channelx Interrupt Enable, array offset: 0x1134, array step: 0x80 */
    __IO uint32_t DMA_CHX_RX_INT_WDTIMER;            /**< Receive Interrupt Watchdog Timer, array offset: 0x1138, array step: 0x80 */
    __IO uint32_t DMA_CHX_SLOT_FUNC_CTRL_STAT;       /**< Slot Function Control and Status, array offset: 0x113C, array step: 0x80 */
         uint8_t RESERVED_3[4];
    __I  uint32_t DMA_CHX_CUR_HST_TXDESC;            /**< Channelx Current Host Transmit descriptor, array offset: 0x1144, array step: 0x80 */
         uint8_t RESERVED_4[4];
    __I  uint32_t DMA_CHX_CUR_HST_RXDESC;            /**< array offset: 0x114C, array step: 0x80 */
         uint8_t RESERVED_5[4];
    __I  uint32_t DMA_CHX_CUR_HST_TXBUF;             /**< array offset: 0x1154, array step: 0x80 */
         uint8_t RESERVED_6[4];
    __I  uint32_t DMA_CHX_CUR_HST_RXBUF;             /**< Channelx Current Application Receive Buffer Address, array offset: 0x115C, array step: 0x80 */
    __IO uint32_t DMA_CHX_STAT;                      /**< Channelx DMA status register, array offset: 0x1160, array step: 0x80 */
         uint8_t RESERVED_7[8];
    __IO uint32_t DMA_CHX_MISS_FRAME_CNT;            /**< Channelx missed frame count., array offset: 0x116C, array step: 0x80 */
         uint8_t RESERVED_8[16];
  } DMA_CH[ENET_DMA_CH_COUNT];
} ENET_Type;

/* ----------------------------------------------------------------------------
   -- ENET Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_Register_Masks ENET Register Masks
 * @{
 */

/*! @name MAC_CONFIG - MAC configuration register */
/*! @{ */

#define ENET_MAC_CONFIG_RE_MASK                  (0x1U)
#define ENET_MAC_CONFIG_RE_SHIFT                 (0U)
/*! RE - Receiver Enable When this bit is set, the receiver state machine of the MAC is enabled for
 *    receiving frames from the MII.
 */
#define ENET_MAC_CONFIG_RE(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_RE_SHIFT)) & ENET_MAC_CONFIG_RE_MASK)

#define ENET_MAC_CONFIG_TE_MASK                  (0x2U)
#define ENET_MAC_CONFIG_TE_SHIFT                 (1U)
/*! TE - Transmitter Enable When this bit is set, the transmit state machine of the MAC is enabled for transmission on the MII. */
#define ENET_MAC_CONFIG_TE(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_TE_SHIFT)) & ENET_MAC_CONFIG_TE_MASK)

#define ENET_MAC_CONFIG_PRELEN_MASK              (0xCU)
#define ENET_MAC_CONFIG_PRELEN_SHIFT             (2U)
/*! PRELEN - Preamble Length for Transmit packets These bits control the number of preamble bytes
 *    that are added to the beginning of every Tx packet.
 */
#define ENET_MAC_CONFIG_PRELEN(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_PRELEN_SHIFT)) & ENET_MAC_CONFIG_PRELEN_MASK)

#define ENET_MAC_CONFIG_DC_MASK                  (0x10U)
#define ENET_MAC_CONFIG_DC_SHIFT                 (4U)
/*! DC - Deferral Check When this bit is set, the deferral check function is enabled in the MAC. */
#define ENET_MAC_CONFIG_DC(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_DC_SHIFT)) & ENET_MAC_CONFIG_DC_MASK)

#define ENET_MAC_CONFIG_BL_MASK                  (0x60U)
#define ENET_MAC_CONFIG_BL_SHIFT                 (5U)
/*! BL - Back-Off Limit The Back-Off limit determines the random integer number (r) of slot time
 *    delays (4,096 bit times for 1000 Mbps and 512 bit times for 10/100 Mbps) the MAC waits before
 *    rescheduling a transmission attempt during retries after a collision.
 */
#define ENET_MAC_CONFIG_BL(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_BL_SHIFT)) & ENET_MAC_CONFIG_BL_MASK)

#define ENET_MAC_CONFIG_DR_MASK                  (0x100U)
#define ENET_MAC_CONFIG_DR_SHIFT                 (8U)
/*! DR - Disable Retry When this bit is set, the MAC will attempt only one transmission. */
#define ENET_MAC_CONFIG_DR(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_DR_SHIFT)) & ENET_MAC_CONFIG_DR_MASK)

#define ENET_MAC_CONFIG_DCRS_MASK                (0x200U)
#define ENET_MAC_CONFIG_DCRS_SHIFT               (9U)
/*! DCRS - Disable Carrier Sense During Transmission When this bit is set, the MAC transmitter
 *    ignores the MII CRS signal during packet transmission in the half-duplex mode.
 */
#define ENET_MAC_CONFIG_DCRS(x)                  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_DCRS_SHIFT)) & ENET_MAC_CONFIG_DCRS_MASK)

#define ENET_MAC_CONFIG_DO_MASK                  (0x400U)
#define ENET_MAC_CONFIG_DO_SHIFT                 (10U)
/*! DO - Disable Receive Own When this bit is set, the MAC disables the reception of frames when the
 *    gmii_txen_o is asserted in Half-Duplex mode.
 */
#define ENET_MAC_CONFIG_DO(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_DO_SHIFT)) & ENET_MAC_CONFIG_DO_MASK)

#define ENET_MAC_CONFIG_ECRSFD_MASK              (0x800U)
#define ENET_MAC_CONFIG_ECRSFD_SHIFT             (11U)
/*! ECRSFD - Enable Carrier Sense Before Transmission in Full-Duplex Mode When this bit is set, the
 *    MAC transmitter checks the CRS signal before packet transmission in the full-duplex mode.
 */
#define ENET_MAC_CONFIG_ECRSFD(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_ECRSFD_SHIFT)) & ENET_MAC_CONFIG_ECRSFD_MASK)

#define ENET_MAC_CONFIG_LM_MASK                  (0x1000U)
#define ENET_MAC_CONFIG_LM_SHIFT                 (12U)
/*! LM - Loopback Mode When this bit is set, the MAC operates in loopback mode at MII. */
#define ENET_MAC_CONFIG_LM(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_LM_SHIFT)) & ENET_MAC_CONFIG_LM_MASK)

#define ENET_MAC_CONFIG_DM_MASK                  (0x2000U)
#define ENET_MAC_CONFIG_DM_SHIFT                 (13U)
/*! DM - Duplex Mode When this bit is set, the MAC operates in a Full-Duplex mode where it can
 *    transmit and receive simultaneously.
 */
#define ENET_MAC_CONFIG_DM(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_DM_SHIFT)) & ENET_MAC_CONFIG_DM_MASK)

#define ENET_MAC_CONFIG_FES_MASK                 (0x4000U)
#define ENET_MAC_CONFIG_FES_SHIFT                (14U)
/*! FES - Speed Indicates the speed in Fast Ethernet (MII) mode: This bit is reserved (RO) by
 *    default and is enabled only when RMII/SMII is enabled during configuration.
 */
#define ENET_MAC_CONFIG_FES(x)                   (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_FES_SHIFT)) & ENET_MAC_CONFIG_FES_MASK)

#define ENET_MAC_CONFIG_PS_MASK                  (0x8000U)
#define ENET_MAC_CONFIG_PS_SHIFT                 (15U)
/*! PS - Portselect. */
#define ENET_MAC_CONFIG_PS(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_PS_SHIFT)) & ENET_MAC_CONFIG_PS_MASK)

#define ENET_MAC_CONFIG_JE_MASK                  (0x10000U)
#define ENET_MAC_CONFIG_JE_SHIFT                 (16U)
/*! JE - Jumbo Frame Enable When this bit is set, MAC allows Jumbo frames of 9,018 bytes (9,022
 *    bytes for tagged frames) without reporting a giant frame error in the receive frame status.
 */
#define ENET_MAC_CONFIG_JE(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_JE_SHIFT)) & ENET_MAC_CONFIG_JE_MASK)

#define ENET_MAC_CONFIG_JD_MASK                  (0x20000U)
#define ENET_MAC_CONFIG_JD_SHIFT                 (17U)
/*! JD - Jabber Disable When this bit is set, the MAC disables the jabber timer on the transmitter,
 *    and can transfer frames of up to 16,384 bytes.
 */
#define ENET_MAC_CONFIG_JD(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_JD_SHIFT)) & ENET_MAC_CONFIG_JD_MASK)

#define ENET_MAC_CONFIG_BE_MASK                  (0x40000U)
#define ENET_MAC_CONFIG_BE_SHIFT                 (18U)
/*! BE - Packet Burst Enable When this bit is set, the MAC allows packet bursting during
 *    transmission in the MII half-duplex mode.
 */
#define ENET_MAC_CONFIG_BE(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_BE_SHIFT)) & ENET_MAC_CONFIG_BE_MASK)

#define ENET_MAC_CONFIG_WD_MASK                  (0x80000U)
#define ENET_MAC_CONFIG_WD_SHIFT                 (19U)
/*! WD - Watchdog Disable When this bit is set, the MAC disables the watchdog timer on the receiver,
 *    and can receive frames of up to 16,384 bytes.
 */
#define ENET_MAC_CONFIG_WD(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_WD_SHIFT)) & ENET_MAC_CONFIG_WD_MASK)

#define ENET_MAC_CONFIG_ACS_MASK                 (0x100000U)
#define ENET_MAC_CONFIG_ACS_SHIFT                (20U)
/*! ACS - Automatic Pad or CRC Stripping When this bit is set, the MAC strips the Pad or FCS field
 *    on the incoming packets only if the value of the length field is less than 1,536 bytes.
 */
#define ENET_MAC_CONFIG_ACS(x)                   (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_ACS_SHIFT)) & ENET_MAC_CONFIG_ACS_MASK)

#define ENET_MAC_CONFIG_CST_MASK                 (0x200000U)
#define ENET_MAC_CONFIG_CST_SHIFT                (21U)
/*! CST - CRC stripping for Type packets When this bit is set, the last four bytes (FCS) of all
 *    packets of Ether type (type field greater than 1,536) are stripped and dropped before forwarding
 *    the packet to the application.
 */
#define ENET_MAC_CONFIG_CST(x)                   (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_CST_SHIFT)) & ENET_MAC_CONFIG_CST_MASK)

#define ENET_MAC_CONFIG_S2KP_MASK                (0x400000U)
#define ENET_MAC_CONFIG_S2KP_SHIFT               (22U)
/*! S2KP - IEEE 802. */
#define ENET_MAC_CONFIG_S2KP(x)                  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_S2KP_SHIFT)) & ENET_MAC_CONFIG_S2KP_MASK)

#define ENET_MAC_CONFIG_GPSLCE_MASK              (0x800000U)
#define ENET_MAC_CONFIG_GPSLCE_SHIFT             (23U)
/*! GPSLCE - Giant Packet Size Limit Control Enable When this bit is set, the MAC considers the
 *    value in GPSL field in MAC Ext Configuration register to declare a received packet as Giant packet.
 */
#define ENET_MAC_CONFIG_GPSLCE(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_GPSLCE_SHIFT)) & ENET_MAC_CONFIG_GPSLCE_MASK)

#define ENET_MAC_CONFIG_IPG_MASK                 (0x7000000U)
#define ENET_MAC_CONFIG_IPG_SHIFT                (24U)
/*! IPG - Inter-Packet Gap These bits control the minimum IPG between packets during transmission. */
#define ENET_MAC_CONFIG_IPG(x)                   (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_IPG_SHIFT)) & ENET_MAC_CONFIG_IPG_MASK)

#define ENET_MAC_CONFIG_IPC_MASK                 (0x8000000U)
#define ENET_MAC_CONFIG_IPC_SHIFT                (27U)
/*! IPC - Checksum Offload When set, this bit enables the IPv4 header checksum checking and IPv4 or
 *    IPv6 TCP, UDP, or ICMP payload checksum checking.
 */
#define ENET_MAC_CONFIG_IPC(x)                   (((uint32_t)(((uint32_t)(x)) << ENET_MAC_CONFIG_IPC_SHIFT)) & ENET_MAC_CONFIG_IPC_MASK)
/*! @} */

/*! @name MAC_EXT_CONFIG -  */
/*! @{ */

#define ENET_MAC_EXT_CONFIG_GPSL_MASK            (0x3FFFU)
#define ENET_MAC_EXT_CONFIG_GPSL_SHIFT           (0U)
/*! GPSL - Giant Packet Size Limit If the received packet size is greater than the value programmed
 *    in this field in units of bytes, the MAC declares the received packet as Giant packet.
 */
#define ENET_MAC_EXT_CONFIG_GPSL(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_EXT_CONFIG_GPSL_SHIFT)) & ENET_MAC_EXT_CONFIG_GPSL_MASK)

#define ENET_MAC_EXT_CONFIG_DCRCC_MASK           (0x10000U)
#define ENET_MAC_EXT_CONFIG_DCRCC_SHIFT          (16U)
/*! DCRCC - Disable CRC Checking for Received Packets When this bit is set, the MAC receiver does
 *    not check the CRC field in the received packets.
 */
#define ENET_MAC_EXT_CONFIG_DCRCC(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_EXT_CONFIG_DCRCC_SHIFT)) & ENET_MAC_EXT_CONFIG_DCRCC_MASK)

#define ENET_MAC_EXT_CONFIG_SPEN_MASK            (0x20000U)
#define ENET_MAC_EXT_CONFIG_SPEN_SHIFT           (17U)
/*! SPEN - Slow Protocol Detection Enable When this bit is set, MAC processes the Slow Protocol
 *    packets (Ether Type 0x8809) and provides the Rx status.
 */
#define ENET_MAC_EXT_CONFIG_SPEN(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_EXT_CONFIG_SPEN_SHIFT)) & ENET_MAC_EXT_CONFIG_SPEN_MASK)

#define ENET_MAC_EXT_CONFIG_USP_MASK             (0x40000U)
#define ENET_MAC_EXT_CONFIG_USP_SHIFT            (18U)
/*! USP - Unicast Slow Protocol Packet Detect When this bit is set, the MAC detects the Slow
 *    Protocol packets with unicast address of the station specified in the MAC Address High Table 747 and
 *    MAC Address Low Table 748 registers.
 */
#define ENET_MAC_EXT_CONFIG_USP(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_EXT_CONFIG_USP_SHIFT)) & ENET_MAC_EXT_CONFIG_USP_MASK)
/*! @} */

/*! @name MAC_FRAME_FILTER - MAC frame filter register */
/*! @{ */

#define ENET_MAC_FRAME_FILTER_PR_MASK            (0x1U)
#define ENET_MAC_FRAME_FILTER_PR_SHIFT           (0U)
/*! PR - Promiscuous Mode When this bit is set, the Address Filter module passes all incoming frames
 *    regardless of its destination or source address.
 */
#define ENET_MAC_FRAME_FILTER_PR(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_FRAME_FILTER_PR_SHIFT)) & ENET_MAC_FRAME_FILTER_PR_MASK)

#define ENET_MAC_FRAME_FILTER_DAIF_MASK          (0x8U)
#define ENET_MAC_FRAME_FILTER_DAIF_SHIFT         (3U)
/*! DAIF - DA Inverse Filtering When this bit is set, the Address Check block operates in inverse
 *    filtering mode for the DA address comparison for both unicast and multicast frames.
 */
#define ENET_MAC_FRAME_FILTER_DAIF(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_FRAME_FILTER_DAIF_SHIFT)) & ENET_MAC_FRAME_FILTER_DAIF_MASK)

#define ENET_MAC_FRAME_FILTER_PM_MASK            (0x10U)
#define ENET_MAC_FRAME_FILTER_PM_SHIFT           (4U)
/*! PM - Pass All Multicast When set, this bit indicates that all received frames with a multicast
 *    destination address (first bit in the destination address field is '1') are passed.
 */
#define ENET_MAC_FRAME_FILTER_PM(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_FRAME_FILTER_PM_SHIFT)) & ENET_MAC_FRAME_FILTER_PM_MASK)

#define ENET_MAC_FRAME_FILTER_DBF_MASK           (0x20U)
#define ENET_MAC_FRAME_FILTER_DBF_SHIFT          (5U)
/*! DBF - Disable Broadcast Frames When this bit is set, the AFM module filters all incoming broadcast frames. */
#define ENET_MAC_FRAME_FILTER_DBF(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_FRAME_FILTER_DBF_SHIFT)) & ENET_MAC_FRAME_FILTER_DBF_MASK)

#define ENET_MAC_FRAME_FILTER_PCF_MASK           (0xC0U)
#define ENET_MAC_FRAME_FILTER_PCF_SHIFT          (6U)
/*! PCF - Pass Control Frames These bits control the forwarding of all control frames (including
 *    unicast and multicast PAUSE frames).
 */
#define ENET_MAC_FRAME_FILTER_PCF(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_FRAME_FILTER_PCF_SHIFT)) & ENET_MAC_FRAME_FILTER_PCF_MASK)

#define ENET_MAC_FRAME_FILTER_SAIF_MASK          (0x100U)
#define ENET_MAC_FRAME_FILTER_SAIF_SHIFT         (8U)
/*! SAIF - SA Inverse Filtering When this bit is set, the Address Check block operates in the
 *    inverse filtering mode for SA address comparison.
 */
#define ENET_MAC_FRAME_FILTER_SAIF(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_FRAME_FILTER_SAIF_SHIFT)) & ENET_MAC_FRAME_FILTER_SAIF_MASK)

#define ENET_MAC_FRAME_FILTER_SAF_MASK           (0x200U)
#define ENET_MAC_FRAME_FILTER_SAF_SHIFT          (9U)
/*! SAF - Source Address Filter Enable When this bit is set, the MAC compares the SA field of the
 *    received packets with the values programmed in the enabled SA registers.
 */
#define ENET_MAC_FRAME_FILTER_SAF(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_FRAME_FILTER_SAF_SHIFT)) & ENET_MAC_FRAME_FILTER_SAF_MASK)

#define ENET_MAC_FRAME_FILTER_RA_MASK            (0x80000000U)
#define ENET_MAC_FRAME_FILTER_RA_SHIFT           (31U)
/*! RA - Receive all When this bit is set, the MAC Receiver module passes to the Application all
 *    frames received irrespective of whether they pass the address filter.
 */
#define ENET_MAC_FRAME_FILTER_RA(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_FRAME_FILTER_RA_SHIFT)) & ENET_MAC_FRAME_FILTER_RA_MASK)
/*! @} */

/*! @name MAC_WD_TIMEROUT - MAC watchdog Timeout register */
/*! @{ */

#define ENET_MAC_WD_TIMEROUT_WTO_MASK            (0xFU)
#define ENET_MAC_WD_TIMEROUT_WTO_SHIFT           (0U)
/*! WTO - Watchdog Timeout When the PWE bit is set and the WD bit of the MAC Configuration register
 *    Table 722 is reset, this field is used as watchdog timeout for a received packet.
 */
#define ENET_MAC_WD_TIMEROUT_WTO(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_WD_TIMEROUT_WTO_SHIFT)) & ENET_MAC_WD_TIMEROUT_WTO_MASK)

#define ENET_MAC_WD_TIMEROUT_PWE_MASK            (0x100U)
#define ENET_MAC_WD_TIMEROUT_PWE_SHIFT           (8U)
/*! PWE - Programmable Watchdog Enable When this bit is set and the WD bit of the MAC Configuration
 *    register Table 722 is reset, the WTO field is used as watchdog timeout for a received packet.
 */
#define ENET_MAC_WD_TIMEROUT_PWE(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_WD_TIMEROUT_PWE_SHIFT)) & ENET_MAC_WD_TIMEROUT_PWE_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG - MAC vlan tag register */
/*! @{ */

#define ENET_MAC_VLAN_TAG_VL_MASK                (0xFFFFU)
#define ENET_MAC_VLAN_TAG_VL_SHIFT               (0U)
/*! VL - VLAN Tag Identifier for Receive Packets. */
#define ENET_MAC_VLAN_TAG_VL(x)                  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_VL_SHIFT)) & ENET_MAC_VLAN_TAG_VL_MASK)

#define ENET_MAC_VLAN_TAG_ETV_MASK               (0x10000U)
#define ENET_MAC_VLAN_TAG_ETV_SHIFT              (16U)
/*! ETV - Enable 12-Bit VLAN Tag Comparison. */
#define ENET_MAC_VLAN_TAG_ETV(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_ETV_SHIFT)) & ENET_MAC_VLAN_TAG_ETV_MASK)

#define ENET_MAC_VLAN_TAG_VTIM_MASK              (0x20000U)
#define ENET_MAC_VLAN_TAG_VTIM_SHIFT             (17U)
/*! VTIM - VLAN Tag Inverse Match Enable. */
#define ENET_MAC_VLAN_TAG_VTIM(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_VTIM_SHIFT)) & ENET_MAC_VLAN_TAG_VTIM_MASK)

#define ENET_MAC_VLAN_TAG_ESVL_MASK              (0x40000U)
#define ENET_MAC_VLAN_TAG_ESVL_SHIFT             (18U)
/*! ESVL - Enable S-VLAN. */
#define ENET_MAC_VLAN_TAG_ESVL(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_ESVL_SHIFT)) & ENET_MAC_VLAN_TAG_ESVL_MASK)

#define ENET_MAC_VLAN_TAG_ERSVLM_MASK            (0x80000U)
#define ENET_MAC_VLAN_TAG_ERSVLM_SHIFT           (19U)
/*! ERSVLM - Enable Receive S-VLAN Match. */
#define ENET_MAC_VLAN_TAG_ERSVLM(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_ERSVLM_SHIFT)) & ENET_MAC_VLAN_TAG_ERSVLM_MASK)

#define ENET_MAC_VLAN_TAG_DOVLTC_MASK            (0x100000U)
#define ENET_MAC_VLAN_TAG_DOVLTC_SHIFT           (20U)
/*! DOVLTC - Disable VLAN Type Check. */
#define ENET_MAC_VLAN_TAG_DOVLTC(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_DOVLTC_SHIFT)) & ENET_MAC_VLAN_TAG_DOVLTC_MASK)

#define ENET_MAC_VLAN_TAG_EVLS_MASK              (0x600000U)
#define ENET_MAC_VLAN_TAG_EVLS_SHIFT             (21U)
/*! EVLS - Enable VLAN Tag Stripping on Receive. */
#define ENET_MAC_VLAN_TAG_EVLS(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_EVLS_SHIFT)) & ENET_MAC_VLAN_TAG_EVLS_MASK)

#define ENET_MAC_VLAN_TAG_EVLRXS_MASK            (0x1000000U)
#define ENET_MAC_VLAN_TAG_EVLRXS_SHIFT           (24U)
/*! EVLRXS - Enable VLAN Tag in Rx status. */
#define ENET_MAC_VLAN_TAG_EVLRXS(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_EVLRXS_SHIFT)) & ENET_MAC_VLAN_TAG_EVLRXS_MASK)

#define ENET_MAC_VLAN_TAG_VTHM_MASK              (0x2000000U)
#define ENET_MAC_VLAN_TAG_VTHM_SHIFT             (25U)
/*! VTHM - Disable VLAN Type Check. */
#define ENET_MAC_VLAN_TAG_VTHM(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_VTHM_SHIFT)) & ENET_MAC_VLAN_TAG_VTHM_MASK)

#define ENET_MAC_VLAN_TAG_EDVLP_MASK             (0x4000000U)
#define ENET_MAC_VLAN_TAG_EDVLP_SHIFT            (26U)
/*! EDVLP - Enable Double VLAN Processing. */
#define ENET_MAC_VLAN_TAG_EDVLP(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_EDVLP_SHIFT)) & ENET_MAC_VLAN_TAG_EDVLP_MASK)

#define ENET_MAC_VLAN_TAG_ERIVLT_MASK            (0x8000000U)
#define ENET_MAC_VLAN_TAG_ERIVLT_SHIFT           (27U)
/*! ERIVLT - Enable Inner VLAN Tag. */
#define ENET_MAC_VLAN_TAG_ERIVLT(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_ERIVLT_SHIFT)) & ENET_MAC_VLAN_TAG_ERIVLT_MASK)

#define ENET_MAC_VLAN_TAG_EIVLS_MASK             (0x30000000U)
#define ENET_MAC_VLAN_TAG_EIVLS_SHIFT            (28U)
/*! EIVLS - Enable Inner VLAN Tag Stripping on Receive. */
#define ENET_MAC_VLAN_TAG_EIVLS(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_EIVLS_SHIFT)) & ENET_MAC_VLAN_TAG_EIVLS_MASK)

#define ENET_MAC_VLAN_TAG_EIVLRXS_MASK           (0x80000000U)
#define ENET_MAC_VLAN_TAG_EIVLRXS_SHIFT          (31U)
/*! EIVLRXS - Enable Inner VLAN Tag in Rx Status. */
#define ENET_MAC_VLAN_TAG_EIVLRXS(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VLAN_TAG_EIVLRXS_SHIFT)) & ENET_MAC_VLAN_TAG_EIVLRXS_MASK)
/*! @} */

/*! @name MAC_TX_FLOW_CTRL_Q - Transmit flow control register */
/*! @{ */

#define ENET_MAC_TX_FLOW_CTRL_Q_FCB_MASK         (0x1U)
#define ENET_MAC_TX_FLOW_CTRL_Q_FCB_SHIFT        (0U)
/*! FCB - Flow Control Busy/Backpressure Activate This register field can be read by the application
 *    (Read), can be set to 1 by the application with a register write of 1 (Write Set), and is
 *    cleared to 0 by the core (Self Clear).
 */
#define ENET_MAC_TX_FLOW_CTRL_Q_FCB(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_FLOW_CTRL_Q_FCB_SHIFT)) & ENET_MAC_TX_FLOW_CTRL_Q_FCB_MASK)

#define ENET_MAC_TX_FLOW_CTRL_Q_TFE_MASK         (0x2U)
#define ENET_MAC_TX_FLOW_CTRL_Q_TFE_SHIFT        (1U)
/*! TFE - Transmit Flow Control Enable In Full-Duplex mode, when this bit is set, the MAC enables
 *    the flow control operation to transmit Pause frames.
 */
#define ENET_MAC_TX_FLOW_CTRL_Q_TFE(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_FLOW_CTRL_Q_TFE_SHIFT)) & ENET_MAC_TX_FLOW_CTRL_Q_TFE_MASK)

#define ENET_MAC_TX_FLOW_CTRL_Q_PLT_MASK         (0x70U)
#define ENET_MAC_TX_FLOW_CTRL_Q_PLT_SHIFT        (4U)
/*! PLT - Pause Low Threshold This field configures the threshold of the PAUSE timer at which the
 *    input flow control signal is checked for automatic retransmission of PAUSE Frame.
 */
#define ENET_MAC_TX_FLOW_CTRL_Q_PLT(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_FLOW_CTRL_Q_PLT_SHIFT)) & ENET_MAC_TX_FLOW_CTRL_Q_PLT_MASK)

#define ENET_MAC_TX_FLOW_CTRL_Q_DZPQ_MASK        (0x80U)
#define ENET_MAC_TX_FLOW_CTRL_Q_DZPQ_SHIFT       (7U)
/*! DZPQ - Disable Zero-Quanta Pause When set, this bit disables the automatic generation of
 *    Zero-Quanta Pause Control frames on the deassertion of the flow-control signal from the FIFO layer.
 */
#define ENET_MAC_TX_FLOW_CTRL_Q_DZPQ(x)          (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_FLOW_CTRL_Q_DZPQ_SHIFT)) & ENET_MAC_TX_FLOW_CTRL_Q_DZPQ_MASK)

#define ENET_MAC_TX_FLOW_CTRL_Q_PT_MASK          (0xFFFF0000U)
#define ENET_MAC_TX_FLOW_CTRL_Q_PT_SHIFT         (16U)
/*! PT - Pause time This field holds the value to be used in the Pause Time field in the transmit control frame. */
#define ENET_MAC_TX_FLOW_CTRL_Q_PT(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_FLOW_CTRL_Q_PT_SHIFT)) & ENET_MAC_TX_FLOW_CTRL_Q_PT_MASK)
/*! @} */

/*! @name MAC_RX_FLOW_CTRL - Receive flow control register */
/*! @{ */

#define ENET_MAC_RX_FLOW_CTRL_RFE_MASK           (0x1U)
#define ENET_MAC_RX_FLOW_CTRL_RFE_SHIFT          (0U)
/*! RFE - Receive Flow Control Enable When this bit is set and the MAC is operating in full-duplex
 *    mode, the MAC decodes the received Pause packet and disables its transmitter for a specified
 *    (Pause) time.
 */
#define ENET_MAC_RX_FLOW_CTRL_RFE(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RX_FLOW_CTRL_RFE_SHIFT)) & ENET_MAC_RX_FLOW_CTRL_RFE_MASK)

#define ENET_MAC_RX_FLOW_CTRL_UP_MASK            (0x2U)
#define ENET_MAC_RX_FLOW_CTRL_UP_SHIFT           (1U)
/*! UP - Unicast Pause Packet Detect A pause packet is processed when it has the unique multicast
 *    address specified in the IEEE 802.
 */
#define ENET_MAC_RX_FLOW_CTRL_UP(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RX_FLOW_CTRL_UP_SHIFT)) & ENET_MAC_RX_FLOW_CTRL_UP_MASK)
/*! @} */

/*! @name MAC_TXQ_PRIO_MAP -  */
/*! @{ */

#define ENET_MAC_TXQ_PRIO_MAP_PSTQ0_MASK         (0xFFU)
#define ENET_MAC_TXQ_PRIO_MAP_PSTQ0_SHIFT        (0U)
/*! PSTQ0 - Priorities Selected in Transmit Queue 0 This field holds the priorities assigned to Tx Queue 0 by the software. */
#define ENET_MAC_TXQ_PRIO_MAP_PSTQ0(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TXQ_PRIO_MAP_PSTQ0_SHIFT)) & ENET_MAC_TXQ_PRIO_MAP_PSTQ0_MASK)

#define ENET_MAC_TXQ_PRIO_MAP_PSTQ1_MASK         (0xFF00U)
#define ENET_MAC_TXQ_PRIO_MAP_PSTQ1_SHIFT        (8U)
/*! PSTQ1 - Priorities Selected in Transmit Queue 1 This bit is similar to the PSTQ0 bit. */
#define ENET_MAC_TXQ_PRIO_MAP_PSTQ1(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TXQ_PRIO_MAP_PSTQ1_SHIFT)) & ENET_MAC_TXQ_PRIO_MAP_PSTQ1_MASK)
/*! @} */

/*! @name MAC_RXQ_CTRL - Receive Queue Control 0 register 0x0000 */
/*! @{ */

#define ENET_MAC_RXQ_CTRL_AVCPQ_MASK             (0x7U)
#define ENET_MAC_RXQ_CTRL_AVCPQ_SHIFT            (0U)
/*! AVCPQ - AV Untagged Control Packets Queue. */
#define ENET_MAC_RXQ_CTRL_AVCPQ(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_AVCPQ_SHIFT)) & ENET_MAC_RXQ_CTRL_AVCPQ_MASK)

#define ENET_MAC_RXQ_CTRL_PSRQ0_MASK             (0xFFU)
#define ENET_MAC_RXQ_CTRL_PSRQ0_SHIFT            (0U)
/*! PSRQ0 - Priorities Selected in the Receive Queue 0. */
#define ENET_MAC_RXQ_CTRL_PSRQ0(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_PSRQ0_SHIFT)) & ENET_MAC_RXQ_CTRL_PSRQ0_MASK)

#define ENET_MAC_RXQ_CTRL_RXQ0EN_MASK            (0x3U)
#define ENET_MAC_RXQ_CTRL_RXQ0EN_SHIFT           (0U)
/*! RXQ0EN - Receive Queue 0 Enable. */
#define ENET_MAC_RXQ_CTRL_RXQ0EN(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_RXQ0EN_SHIFT)) & ENET_MAC_RXQ_CTRL_RXQ0EN_MASK)

#define ENET_MAC_RXQ_CTRL_RXQ1EN_MASK            (0xCU)
#define ENET_MAC_RXQ_CTRL_RXQ1EN_SHIFT           (2U)
/*! RXQ1EN - Receive Queue 1 Enable. */
#define ENET_MAC_RXQ_CTRL_RXQ1EN(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_RXQ1EN_SHIFT)) & ENET_MAC_RXQ_CTRL_RXQ1EN_MASK)

#define ENET_MAC_RXQ_CTRL_AVPTPQ_MASK            (0x70U)
#define ENET_MAC_RXQ_CTRL_AVPTPQ_SHIFT           (4U)
/*! AVPTPQ - AV PTP Packets Queue. */
#define ENET_MAC_RXQ_CTRL_AVPTPQ(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_AVPTPQ_SHIFT)) & ENET_MAC_RXQ_CTRL_AVPTPQ_MASK)

#define ENET_MAC_RXQ_CTRL_PSRQ1_MASK             (0xFF00U)
#define ENET_MAC_RXQ_CTRL_PSRQ1_SHIFT            (8U)
/*! PSRQ1 - Priorities Selected in the Receive Queue 1. */
#define ENET_MAC_RXQ_CTRL_PSRQ1(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_PSRQ1_SHIFT)) & ENET_MAC_RXQ_CTRL_PSRQ1_MASK)

#define ENET_MAC_RXQ_CTRL_UPQ_MASK               (0x7000U)
#define ENET_MAC_RXQ_CTRL_UPQ_SHIFT              (12U)
/*! UPQ - Untagged Packet Queue. */
#define ENET_MAC_RXQ_CTRL_UPQ(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_UPQ_SHIFT)) & ENET_MAC_RXQ_CTRL_UPQ_MASK)

#define ENET_MAC_RXQ_CTRL_MCBCQ_MASK             (0x70000U)
#define ENET_MAC_RXQ_CTRL_MCBCQ_SHIFT            (16U)
/*! MCBCQ - Multicast and Broadcast Queue. */
#define ENET_MAC_RXQ_CTRL_MCBCQ(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_MCBCQ_SHIFT)) & ENET_MAC_RXQ_CTRL_MCBCQ_MASK)

#define ENET_MAC_RXQ_CTRL_PSRQ2_MASK             (0xFF0000U)
#define ENET_MAC_RXQ_CTRL_PSRQ2_SHIFT            (16U)
/*! PSRQ2 - Priorities Selected in the Receive Queue 2. */
#define ENET_MAC_RXQ_CTRL_PSRQ2(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_PSRQ2_SHIFT)) & ENET_MAC_RXQ_CTRL_PSRQ2_MASK)

#define ENET_MAC_RXQ_CTRL_MCBCQEN_MASK           (0x100000U)
#define ENET_MAC_RXQ_CTRL_MCBCQEN_SHIFT          (20U)
/*! MCBCQEN - Multicast and Broadcast Queue Enable. */
#define ENET_MAC_RXQ_CTRL_MCBCQEN(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_MCBCQEN_SHIFT)) & ENET_MAC_RXQ_CTRL_MCBCQEN_MASK)

#define ENET_MAC_RXQ_CTRL_PSRQ3_MASK             (0xFF000000U)
#define ENET_MAC_RXQ_CTRL_PSRQ3_SHIFT            (24U)
/*! PSRQ3 - Priorities Selected in the Receive Queue 3. */
#define ENET_MAC_RXQ_CTRL_PSRQ3(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXQ_CTRL_PSRQ3_SHIFT)) & ENET_MAC_RXQ_CTRL_PSRQ3_MASK)
/*! @} */

/*! @name MAC_INTR_STAT - Interrupt status register 0x0000 */
/*! @{ */

#define ENET_MAC_INTR_STAT_PHYIS_MASK            (0x8U)
#define ENET_MAC_INTR_STAT_PHYIS_SHIFT           (3U)
/*! PHYIS - PHY Interrupt. */
#define ENET_MAC_INTR_STAT_PHYIS(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTR_STAT_PHYIS_SHIFT)) & ENET_MAC_INTR_STAT_PHYIS_MASK)

#define ENET_MAC_INTR_STAT_PMTIS_MASK            (0x10U)
#define ENET_MAC_INTR_STAT_PMTIS_SHIFT           (4U)
/*! PMTIS - PMT Interrupt Status. */
#define ENET_MAC_INTR_STAT_PMTIS(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTR_STAT_PMTIS_SHIFT)) & ENET_MAC_INTR_STAT_PMTIS_MASK)

#define ENET_MAC_INTR_STAT_LPIIS_MASK            (0x20U)
#define ENET_MAC_INTR_STAT_LPIIS_SHIFT           (5U)
/*! LPIIS - LPI Interrupt Status. */
#define ENET_MAC_INTR_STAT_LPIIS(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTR_STAT_LPIIS_SHIFT)) & ENET_MAC_INTR_STAT_LPIIS_MASK)

#define ENET_MAC_INTR_STAT_TSIS_MASK             (0x1000U)
#define ENET_MAC_INTR_STAT_TSIS_SHIFT            (12U)
/*! TSIS - Timestamp interrupt status. */
#define ENET_MAC_INTR_STAT_TSIS(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTR_STAT_TSIS_SHIFT)) & ENET_MAC_INTR_STAT_TSIS_MASK)

#define ENET_MAC_INTR_STAT_TXSTSIS_MASK          (0x2000U)
#define ENET_MAC_INTR_STAT_TXSTSIS_SHIFT         (13U)
/*! TXSTSIS - Transmit Status Interrupt. */
#define ENET_MAC_INTR_STAT_TXSTSIS(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTR_STAT_TXSTSIS_SHIFT)) & ENET_MAC_INTR_STAT_TXSTSIS_MASK)

#define ENET_MAC_INTR_STAT_RXSTSIS_MASK          (0x4000U)
#define ENET_MAC_INTR_STAT_RXSTSIS_SHIFT         (14U)
/*! RXSTSIS - Receive Status Interrupt. */
#define ENET_MAC_INTR_STAT_RXSTSIS(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTR_STAT_RXSTSIS_SHIFT)) & ENET_MAC_INTR_STAT_RXSTSIS_MASK)
/*! @} */

/*! @name MAC_INTR_EN - Interrupt enable register 0x0000 */
/*! @{ */

#define ENET_MAC_INTR_EN_PHYIE_MASK              (0x8U)
#define ENET_MAC_INTR_EN_PHYIE_SHIFT             (3U)
/*! PHYIE - PHY Interrupt Enable. */
#define ENET_MAC_INTR_EN_PHYIE(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTR_EN_PHYIE_SHIFT)) & ENET_MAC_INTR_EN_PHYIE_MASK)

#define ENET_MAC_INTR_EN_PMTIE_MASK              (0x10U)
#define ENET_MAC_INTR_EN_PMTIE_SHIFT             (4U)
/*! PMTIE - PMT Interrupt Enable. */
#define ENET_MAC_INTR_EN_PMTIE(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTR_EN_PMTIE_SHIFT)) & ENET_MAC_INTR_EN_PMTIE_MASK)

#define ENET_MAC_INTR_EN_LPIIE_MASK              (0x20U)
#define ENET_MAC_INTR_EN_LPIIE_SHIFT             (5U)
/*! LPIIE - LPI Interrupt Enable. */
#define ENET_MAC_INTR_EN_LPIIE(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTR_EN_LPIIE_SHIFT)) & ENET_MAC_INTR_EN_LPIIE_MASK)

#define ENET_MAC_INTR_EN_TSIE_MASK               (0x1000U)
#define ENET_MAC_INTR_EN_TSIE_SHIFT              (12U)
/*! TSIE - Timestamp Interrupt Enable. */
#define ENET_MAC_INTR_EN_TSIE(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTR_EN_TSIE_SHIFT)) & ENET_MAC_INTR_EN_TSIE_MASK)

#define ENET_MAC_INTR_EN_TXSTSIE_MASK            (0x2000U)
#define ENET_MAC_INTR_EN_TXSTSIE_SHIFT           (13U)
/*! TXSTSIE - Transmit Status Interrupt Enable. */
#define ENET_MAC_INTR_EN_TXSTSIE(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTR_EN_TXSTSIE_SHIFT)) & ENET_MAC_INTR_EN_TXSTSIE_MASK)

#define ENET_MAC_INTR_EN_RXSTSIS_MASK            (0x4000U)
#define ENET_MAC_INTR_EN_RXSTSIS_SHIFT           (14U)
/*! RXSTSIS - Receive Status Interrupt Enable. */
#define ENET_MAC_INTR_EN_RXSTSIS(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_INTR_EN_RXSTSIS_SHIFT)) & ENET_MAC_INTR_EN_RXSTSIS_MASK)
/*! @} */

/*! @name MAC_RXTX_STAT - Receive Transmit Status register */
/*! @{ */

#define ENET_MAC_RXTX_STAT_TJT_MASK              (0x1U)
#define ENET_MAC_RXTX_STAT_TJT_SHIFT             (0U)
/*! TJT - PHY Interrupt Enable When this bit is set, it enables the assertion of the interrupt
 *    signal because of the setting of PHYIS bit in MAC Interrupt Status register Table 731.
 */
#define ENET_MAC_RXTX_STAT_TJT(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXTX_STAT_TJT_SHIFT)) & ENET_MAC_RXTX_STAT_TJT_MASK)

#define ENET_MAC_RXTX_STAT_NCARR_MASK            (0x2U)
#define ENET_MAC_RXTX_STAT_NCARR_SHIFT           (1U)
/*! NCARR - No Carrier When the DTXSTS bit is set in the MTL Operation Mode register Table 758, this
 *    bit indicates that the carrier signal from the PHY is not present at the end of preamble
 *    transmission.
 */
#define ENET_MAC_RXTX_STAT_NCARR(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXTX_STAT_NCARR_SHIFT)) & ENET_MAC_RXTX_STAT_NCARR_MASK)

#define ENET_MAC_RXTX_STAT_LCARR_MASK            (0x4U)
#define ENET_MAC_RXTX_STAT_LCARR_SHIFT           (2U)
/*! LCARR - Loss of Carrier When the DTXSTS bit is set in the MTL Operation Mode register Table 758,
 *    this bit indicates that the loss of carrier occurred during packet transmission, that is, the
 *    PHY Carrier signal was inactive for one or more transmission clock periods during packet
 *    transmission.
 */
#define ENET_MAC_RXTX_STAT_LCARR(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXTX_STAT_LCARR_SHIFT)) & ENET_MAC_RXTX_STAT_LCARR_MASK)

#define ENET_MAC_RXTX_STAT_EXDEF_MASK            (0x8U)
#define ENET_MAC_RXTX_STAT_EXDEF_SHIFT           (3U)
/*! EXDEF - Excessive Deferral When the DTXSTS bit is set in the MTL Operation Mode register Table
 *    758 and the DC bit is set in the MAC Configuration register Table 758, this bit indicates that
 *    the transmission ended because of excessive deferral of over 24,288 bit times (155,680 when
 *    Jumbo packet is enabled).
 */
#define ENET_MAC_RXTX_STAT_EXDEF(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXTX_STAT_EXDEF_SHIFT)) & ENET_MAC_RXTX_STAT_EXDEF_MASK)

#define ENET_MAC_RXTX_STAT_LCOL_MASK             (0x10U)
#define ENET_MAC_RXTX_STAT_LCOL_SHIFT            (4U)
/*! LCOL - Late Collision When the DTXSTS bit is set in the MTL Operation Mode register Table 758,
 *    this bit indicates that the packet transmission aborted because a collision occurred after the
 *    collision window (64 bytes including Preamble in MII mode).
 */
#define ENET_MAC_RXTX_STAT_LCOL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXTX_STAT_LCOL_SHIFT)) & ENET_MAC_RXTX_STAT_LCOL_MASK)

#define ENET_MAC_RXTX_STAT_EXCOL_MASK            (0x20U)
#define ENET_MAC_RXTX_STAT_EXCOL_SHIFT           (5U)
/*! EXCOL - Excessive Collisions When the DTXSTS bit is set in the MTL Operation Mode register Table
 *    758, this bit indicates that the transmission aborted after 16 successive collisions while
 *    attempting to transmit the current packet.
 */
#define ENET_MAC_RXTX_STAT_EXCOL(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXTX_STAT_EXCOL_SHIFT)) & ENET_MAC_RXTX_STAT_EXCOL_MASK)

#define ENET_MAC_RXTX_STAT_RWT_MASK              (0x100U)
#define ENET_MAC_RXTX_STAT_RWT_SHIFT             (8U)
/*! RWT - Receive Watchdog Timeout This bit is set when a packet with length greater than 2,048
 *    bytes is received (10,240 bytes when Jumbo Packet mode is enabled) and the WD bit is reset in the
 *    MAC Configuration register Table 722.
 */
#define ENET_MAC_RXTX_STAT_RWT(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RXTX_STAT_RWT_SHIFT)) & ENET_MAC_RXTX_STAT_RWT_MASK)
/*! @} */

/*! @name MAC_PMT_CRTL_STAT -  */
/*! @{ */

#define ENET_MAC_PMT_CRTL_STAT_PWRDWN_MASK       (0x1U)
#define ENET_MAC_PMT_CRTL_STAT_PWRDWN_SHIFT      (0U)
/*! PWRDWN - Transmit LPI Entry When this bit is set, it indicates that the MAC Transmitter has
 *    entered the LPI state because of the setting of the LPIEN bit.
 */
#define ENET_MAC_PMT_CRTL_STAT_PWRDWN(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CRTL_STAT_PWRDWN_SHIFT)) & ENET_MAC_PMT_CRTL_STAT_PWRDWN_MASK)

#define ENET_MAC_PMT_CRTL_STAT_MGKPKTEN_MASK     (0x2U)
#define ENET_MAC_PMT_CRTL_STAT_MGKPKTEN_SHIFT    (1U)
/*! MGKPKTEN - Magic Packet Enable. */
#define ENET_MAC_PMT_CRTL_STAT_MGKPKTEN(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CRTL_STAT_MGKPKTEN_SHIFT)) & ENET_MAC_PMT_CRTL_STAT_MGKPKTEN_MASK)

#define ENET_MAC_PMT_CRTL_STAT_RWKPKTEN_MASK     (0x4U)
#define ENET_MAC_PMT_CRTL_STAT_RWKPKTEN_SHIFT    (2U)
/*! RWKPKTEN - Remote Wake-Up Packet Enable When this bit is set, a power management event is
 *    generated when the MAC receives a remote wake-up packet.
 */
#define ENET_MAC_PMT_CRTL_STAT_RWKPKTEN(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CRTL_STAT_RWKPKTEN_SHIFT)) & ENET_MAC_PMT_CRTL_STAT_RWKPKTEN_MASK)

#define ENET_MAC_PMT_CRTL_STAT_MGKPRCVD_MASK     (0x20U)
#define ENET_MAC_PMT_CRTL_STAT_MGKPRCVD_SHIFT    (5U)
/*! MGKPRCVD - Magic Packet Received. */
#define ENET_MAC_PMT_CRTL_STAT_MGKPRCVD(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CRTL_STAT_MGKPRCVD_SHIFT)) & ENET_MAC_PMT_CRTL_STAT_MGKPRCVD_MASK)

#define ENET_MAC_PMT_CRTL_STAT_RWKPRCVD_MASK     (0x40U)
#define ENET_MAC_PMT_CRTL_STAT_RWKPRCVD_SHIFT    (6U)
/*! RWKPRCVD - Remote Wake-Up Packet Received. */
#define ENET_MAC_PMT_CRTL_STAT_RWKPRCVD(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CRTL_STAT_RWKPRCVD_SHIFT)) & ENET_MAC_PMT_CRTL_STAT_RWKPRCVD_MASK)

#define ENET_MAC_PMT_CRTL_STAT_GLBLUCAST_MASK    (0x200U)
#define ENET_MAC_PMT_CRTL_STAT_GLBLUCAST_SHIFT   (9U)
/*! GLBLUCAST - Global Unicast When this bit set, any unicast packet filtered by the MAC (DAF)
 *    address recognition is detected as a remote wake-up packet.
 */
#define ENET_MAC_PMT_CRTL_STAT_GLBLUCAST(x)      (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CRTL_STAT_GLBLUCAST_SHIFT)) & ENET_MAC_PMT_CRTL_STAT_GLBLUCAST_MASK)

#define ENET_MAC_PMT_CRTL_STAT_RWKPFE_MASK       (0x400U)
#define ENET_MAC_PMT_CRTL_STAT_RWKPFE_SHIFT      (10U)
/*! RWKPFE - Remote Wake-up Packet Forwarding Enable When this bit is set along with RWKPKTEN, the
 *    MAC receiver drops all received frames until it receives the expected wake-up frame.
 */
#define ENET_MAC_PMT_CRTL_STAT_RWKPFE(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CRTL_STAT_RWKPFE_SHIFT)) & ENET_MAC_PMT_CRTL_STAT_RWKPFE_MASK)

#define ENET_MAC_PMT_CRTL_STAT_RWKPTR_MASK       (0x1F000000U)
#define ENET_MAC_PMT_CRTL_STAT_RWKPTR_SHIFT      (24U)
/*! RWKPTR - Remote Wake-up FIFO Pointer This field gives the current value (0 to 7) of the Remote
 *    Wake-up Packet Filter register pointer.
 */
#define ENET_MAC_PMT_CRTL_STAT_RWKPTR(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CRTL_STAT_RWKPTR_SHIFT)) & ENET_MAC_PMT_CRTL_STAT_RWKPTR_MASK)

#define ENET_MAC_PMT_CRTL_STAT_RWKFILTRST_MASK   (0x80000000U)
#define ENET_MAC_PMT_CRTL_STAT_RWKFILTRST_SHIFT  (31U)
/*! RWKFILTRST - Remote Wake-Up Packet Filter Register Pointer Reset When this bit is set, the
 *    remote wake-up packet filter register pointer is reset to 3'b000.
 */
#define ENET_MAC_PMT_CRTL_STAT_RWKFILTRST(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_PMT_CRTL_STAT_RWKFILTRST_SHIFT)) & ENET_MAC_PMT_CRTL_STAT_RWKFILTRST_MASK)
/*! @} */

/*! @name MAC_RWAKE_FRFLT - Remote wake-up frame filter */
/*! @{ */

#define ENET_MAC_RWAKE_FRFLT_ADDR_MASK           (0xFFFFFFFFU)
#define ENET_MAC_RWAKE_FRFLT_ADDR_SHIFT          (0U)
/*! ADDR - WKUPFMFILTER address. */
#define ENET_MAC_RWAKE_FRFLT_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_RWAKE_FRFLT_ADDR_SHIFT)) & ENET_MAC_RWAKE_FRFLT_ADDR_MASK)
/*! @} */

/*! @name MAC_LPI_CTRL_STAT - LPI Control and Status Register */
/*! @{ */

#define ENET_MAC_LPI_CTRL_STAT_TLPIEN_MASK       (0x1U)
#define ENET_MAC_LPI_CTRL_STAT_TLPIEN_SHIFT      (0U)
/*! TLPIEN - Transmit LPI Entry When this bit is set, it indicates that the MAC Transmitter has
 *    entered the LPI state because of the setting of the LPIEN bit.
 */
#define ENET_MAC_LPI_CTRL_STAT_TLPIEN(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CTRL_STAT_TLPIEN_SHIFT)) & ENET_MAC_LPI_CTRL_STAT_TLPIEN_MASK)

#define ENET_MAC_LPI_CTRL_STAT_TLPIEX_MASK       (0x2U)
#define ENET_MAC_LPI_CTRL_STAT_TLPIEX_SHIFT      (1U)
/*! TLPIEX - Transmit LPI Exit When this bit is set, it indicates that the MAC transmitter exited
 *    the LPI state after the application cleared the LPIEN bit and the LPI TW Timer has expired.
 */
#define ENET_MAC_LPI_CTRL_STAT_TLPIEX(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CTRL_STAT_TLPIEX_SHIFT)) & ENET_MAC_LPI_CTRL_STAT_TLPIEX_MASK)

#define ENET_MAC_LPI_CTRL_STAT_RLPIEN_MASK       (0x4U)
#define ENET_MAC_LPI_CTRL_STAT_RLPIEN_SHIFT      (2U)
/*! RLPIEN - Receive LPI Entry When this bit is set, it indicates that the MAC Receiver has received
 *    an LPI pattern and entered the LPI state.
 */
#define ENET_MAC_LPI_CTRL_STAT_RLPIEN(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CTRL_STAT_RLPIEN_SHIFT)) & ENET_MAC_LPI_CTRL_STAT_RLPIEN_MASK)

#define ENET_MAC_LPI_CTRL_STAT_RLPIEX_MASK       (0x8U)
#define ENET_MAC_LPI_CTRL_STAT_RLPIEX_SHIFT      (3U)
/*! RLPIEX - Receive LPI Exit When this bit is set, it indicates that the MAC Receiver has stopped
 *    receiving the LPI pattern on the MII interface, exited the LPI state, and resumed the normal
 *    reception.
 */
#define ENET_MAC_LPI_CTRL_STAT_RLPIEX(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CTRL_STAT_RLPIEX_SHIFT)) & ENET_MAC_LPI_CTRL_STAT_RLPIEX_MASK)

#define ENET_MAC_LPI_CTRL_STAT_TLPIST_MASK       (0x100U)
#define ENET_MAC_LPI_CTRL_STAT_TLPIST_SHIFT      (8U)
/*! TLPIST - Transmit LPI State When this bit is set, it indicates that the MAC is transmitting the LPI pattern on the MII interface. */
#define ENET_MAC_LPI_CTRL_STAT_TLPIST(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CTRL_STAT_TLPIST_SHIFT)) & ENET_MAC_LPI_CTRL_STAT_TLPIST_MASK)

#define ENET_MAC_LPI_CTRL_STAT_RLPIST_MASK       (0x200U)
#define ENET_MAC_LPI_CTRL_STAT_RLPIST_SHIFT      (9U)
/*! RLPIST - Receive LPI State When this bit is set, it indicates that the MAC is receiving the LPI pattern on the MII interface. */
#define ENET_MAC_LPI_CTRL_STAT_RLPIST(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CTRL_STAT_RLPIST_SHIFT)) & ENET_MAC_LPI_CTRL_STAT_RLPIST_MASK)

#define ENET_MAC_LPI_CTRL_STAT_LPIEN_MASK        (0x10000U)
#define ENET_MAC_LPI_CTRL_STAT_LPIEN_SHIFT       (16U)
/*! LPIEN - LPI Enable When this bit is set, it instructs the MAC Transmitter to enter the LPI state. */
#define ENET_MAC_LPI_CTRL_STAT_LPIEN(x)          (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CTRL_STAT_LPIEN_SHIFT)) & ENET_MAC_LPI_CTRL_STAT_LPIEN_MASK)

#define ENET_MAC_LPI_CTRL_STAT_PLS_MASK          (0x20000U)
#define ENET_MAC_LPI_CTRL_STAT_PLS_SHIFT         (17U)
/*! PLS - PHY Link Status This bit indicates the link status of the PHY. */
#define ENET_MAC_LPI_CTRL_STAT_PLS(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CTRL_STAT_PLS_SHIFT)) & ENET_MAC_LPI_CTRL_STAT_PLS_MASK)

#define ENET_MAC_LPI_CTRL_STAT_LPITXA_MASK       (0x80000U)
#define ENET_MAC_LPI_CTRL_STAT_LPITXA_SHIFT      (19U)
/*! LPITXA - LPI Tx Automate This bit controls the behavior of the MAC when it is entering or coming
 *    out of the LPI mode on the Transmit side.
 */
#define ENET_MAC_LPI_CTRL_STAT_LPITXA(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CTRL_STAT_LPITXA_SHIFT)) & ENET_MAC_LPI_CTRL_STAT_LPITXA_MASK)

#define ENET_MAC_LPI_CTRL_STAT_LPIATE_MASK       (0x100000U)
#define ENET_MAC_LPI_CTRL_STAT_LPIATE_SHIFT      (20U)
/*! LPIATE - LPI Timer Enable This bit controls the automatic entry of the MAC Transmitter into and exit out of the LPI state. */
#define ENET_MAC_LPI_CTRL_STAT_LPIATE(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CTRL_STAT_LPIATE_SHIFT)) & ENET_MAC_LPI_CTRL_STAT_LPIATE_MASK)

#define ENET_MAC_LPI_CTRL_STAT_LPITCSE_MASK      (0x200000U)
#define ENET_MAC_LPI_CTRL_STAT_LPITCSE_SHIFT     (21U)
/*! LPITCSE - LPI Tx Clock Stop Enable When this bit is set, the MAC asserts LPI Tx Clock Gating
 *    Control signal high after it enters Tx LPI mode to indicate that the Tx clock to MAC can be
 *    stopped.
 */
#define ENET_MAC_LPI_CTRL_STAT_LPITCSE(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_CTRL_STAT_LPITCSE_SHIFT)) & ENET_MAC_LPI_CTRL_STAT_LPITCSE_MASK)
/*! @} */

/*! @name MAC_LPI_TIMER_CTRL - LPI Timers Control register */
/*! @{ */

#define ENET_MAC_LPI_TIMER_CTRL_TWT_MASK         (0xFFFFU)
#define ENET_MAC_LPI_TIMER_CTRL_TWT_SHIFT        (0U)
/*! TWT - LPI TW Timer This field specifies the minimum time (in microseconds) for which the MAC
 *    waits after it stops transmitting the LPI pattern to the PHY and before it resumes the normal
 *    transmission.
 */
#define ENET_MAC_LPI_TIMER_CTRL_TWT(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_TIMER_CTRL_TWT_SHIFT)) & ENET_MAC_LPI_TIMER_CTRL_TWT_MASK)

#define ENET_MAC_LPI_TIMER_CTRL_LST_MASK         (0x3FF0000U)
#define ENET_MAC_LPI_TIMER_CTRL_LST_SHIFT        (16U)
/*! LST - LPI LS Timer This field specifies the minimum time (in milliseconds) for which the link
 *    status from the PHY should be up (OKAY) before the LPI pattern can be transmitted to the PHY.
 */
#define ENET_MAC_LPI_TIMER_CTRL_LST(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_TIMER_CTRL_LST_SHIFT)) & ENET_MAC_LPI_TIMER_CTRL_LST_MASK)
/*! @} */

/*! @name MAC_LPI_ENTR_TIMR - LPI entry Timer register */
/*! @{ */

#define ENET_MAC_LPI_ENTR_TIMR_LPIET_MASK        (0xFFFF8U)
#define ENET_MAC_LPI_ENTR_TIMR_LPIET_SHIFT       (3U)
/*! LPIET - LPI Entry Timer This field specifies the time in microseconds the MAC will wait to enter
 *    LPI mode, after it has transmitted all the frames.
 */
#define ENET_MAC_LPI_ENTR_TIMR_LPIET(x)          (((uint32_t)(((uint32_t)(x)) << ENET_MAC_LPI_ENTR_TIMR_LPIET_SHIFT)) & ENET_MAC_LPI_ENTR_TIMR_LPIET_MASK)
/*! @} */

/*! @name MAC_1US_TIC_COUNTR -  */
/*! @{ */

#define ENET_MAC_1US_TIC_COUNTR_TIC_1US_CNTR_MASK (0xFFFU)
#define ENET_MAC_1US_TIC_COUNTR_TIC_1US_CNTR_SHIFT (0U)
/*! TIC_1US_CNTR - 1US TIC Counter The application must program this counter so that the number of clock cycles of CSR clock is 1us. */
#define ENET_MAC_1US_TIC_COUNTR_TIC_1US_CNTR(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_1US_TIC_COUNTR_TIC_1US_CNTR_SHIFT)) & ENET_MAC_1US_TIC_COUNTR_TIC_1US_CNTR_MASK)
/*! @} */

/*! @name MAC_VERSION - MAC version register */
/*! @{ */

#define ENET_MAC_VERSION_SNPVER_MASK             (0xFFU)
#define ENET_MAC_VERSION_SNPVER_SHIFT            (0U)
/*! SNPVER - NXP defined version. */
#define ENET_MAC_VERSION_SNPVER(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VERSION_SNPVER_SHIFT)) & ENET_MAC_VERSION_SNPVER_MASK)

#define ENET_MAC_VERSION_USERVER_MASK            (0xFF00U)
#define ENET_MAC_VERSION_USERVER_SHIFT           (8U)
/*! USERVER - User defined version. */
#define ENET_MAC_VERSION_USERVER(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_VERSION_USERVER_SHIFT)) & ENET_MAC_VERSION_USERVER_MASK)
/*! @} */

/*! @name MAC_DBG - MAC debug register */
/*! @{ */

#define ENET_MAC_DBG_REPESTS_MASK                (0x1U)
#define ENET_MAC_DBG_REPESTS_SHIFT               (0U)
/*! REPESTS - MAC MII Receive Protocol Engine Status When this bit is set, it indicates that the MAC
 *    MII receive protocol engine is actively receiving data, and it is not in the Idle state.
 */
#define ENET_MAC_DBG_REPESTS(x)                  (((uint32_t)(((uint32_t)(x)) << ENET_MAC_DBG_REPESTS_SHIFT)) & ENET_MAC_DBG_REPESTS_MASK)

#define ENET_MAC_DBG_RFCFCSTS_MASK               (0x6U)
#define ENET_MAC_DBG_RFCFCSTS_SHIFT              (1U)
/*! RFCFCSTS - MAC Receive Packet Controller FIFO Status When this bit is set, this field indicates
 *    the active state of the small FIFO Read and Write controllers of the MAC Receive Packet
 *    Controller module.
 */
#define ENET_MAC_DBG_RFCFCSTS(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_DBG_RFCFCSTS_SHIFT)) & ENET_MAC_DBG_RFCFCSTS_MASK)

#define ENET_MAC_DBG_TPESTS_MASK                 (0x10000U)
#define ENET_MAC_DBG_TPESTS_SHIFT                (16U)
/*! TPESTS - MAC MII Transmit Protocol Engine Status When this bit is set, it indicates that the MAC
 *    or MII transmit protocol engine is actively transmitting data, and it is not in the Idle
 *    state.
 */
#define ENET_MAC_DBG_TPESTS(x)                   (((uint32_t)(((uint32_t)(x)) << ENET_MAC_DBG_TPESTS_SHIFT)) & ENET_MAC_DBG_TPESTS_MASK)

#define ENET_MAC_DBG_TFCSTS_MASK                 (0x60000U)
#define ENET_MAC_DBG_TFCSTS_SHIFT                (17U)
/*! TFCSTS - MAC Transmit Packet Controller Status This field indicates the state of the MAC Transmit Packet Controller module. */
#define ENET_MAC_DBG_TFCSTS(x)                   (((uint32_t)(((uint32_t)(x)) << ENET_MAC_DBG_TFCSTS_SHIFT)) & ENET_MAC_DBG_TFCSTS_MASK)
/*! @} */

/*! @name MAC_HW_FEAT - MAC hardware feature register 0x0201 */
/*! @{ */

#define ENET_MAC_HW_FEAT_MIISEL_MASK             (0x1U)
#define ENET_MAC_HW_FEAT_MIISEL_SHIFT            (0U)
/*! MIISEL - 10 or 100 Mbps Support. */
#define ENET_MAC_HW_FEAT_MIISEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_MIISEL_SHIFT)) & ENET_MAC_HW_FEAT_MIISEL_MASK)

#define ENET_MAC_HW_FEAT_RXFIFOSIZE_MASK         (0x1FU)
#define ENET_MAC_HW_FEAT_RXFIFOSIZE_SHIFT        (0U)
/*! RXFIFOSIZE - MTL Receive FIFO Size. */
#define ENET_MAC_HW_FEAT_RXFIFOSIZE(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_RXFIFOSIZE_SHIFT)) & ENET_MAC_HW_FEAT_RXFIFOSIZE_MASK)

#define ENET_MAC_HW_FEAT_RXQCNT_MASK             (0xFU)
#define ENET_MAC_HW_FEAT_RXQCNT_SHIFT            (0U)
/*! RXQCNT - Number of MTL Receive Queues. */
#define ENET_MAC_HW_FEAT_RXQCNT(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_RXQCNT_SHIFT)) & ENET_MAC_HW_FEAT_RXQCNT_MASK)

#define ENET_MAC_HW_FEAT_HDSEL_MASK              (0x4U)
#define ENET_MAC_HW_FEAT_HDSEL_SHIFT             (2U)
/*! HDSEL - Half-duplex Support. */
#define ENET_MAC_HW_FEAT_HDSEL(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_HDSEL_SHIFT)) & ENET_MAC_HW_FEAT_HDSEL_MASK)

#define ENET_MAC_HW_FEAT_VLHASH_MASK             (0x10U)
#define ENET_MAC_HW_FEAT_VLHASH_SHIFT            (4U)
/*! VLHASH - Hash Table Based Filtering option. */
#define ENET_MAC_HW_FEAT_VLHASH(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_VLHASH_SHIFT)) & ENET_MAC_HW_FEAT_VLHASH_MASK)

#define ENET_MAC_HW_FEAT_SMASEL_MASK             (0x20U)
#define ENET_MAC_HW_FEAT_SMASEL_SHIFT            (5U)
/*! SMASEL - SMA (MDIO) Interface. */
#define ENET_MAC_HW_FEAT_SMASEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_SMASEL_SHIFT)) & ENET_MAC_HW_FEAT_SMASEL_MASK)

#define ENET_MAC_HW_FEAT_RWKSEL_MASK             (0x40U)
#define ENET_MAC_HW_FEAT_RWKSEL_SHIFT            (6U)
/*! RWKSEL - PMT Remote Wake-up Packet Detection. */
#define ENET_MAC_HW_FEAT_RWKSEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_RWKSEL_SHIFT)) & ENET_MAC_HW_FEAT_RWKSEL_MASK)

#define ENET_MAC_HW_FEAT_TXFIFOSIZE_MASK         (0x7C0U)
#define ENET_MAC_HW_FEAT_TXFIFOSIZE_SHIFT        (6U)
/*! TXFIFOSIZE - MTL Transmit FIFO Size. */
#define ENET_MAC_HW_FEAT_TXFIFOSIZE(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TXFIFOSIZE_SHIFT)) & ENET_MAC_HW_FEAT_TXFIFOSIZE_MASK)

#define ENET_MAC_HW_FEAT_TXQCNT_MASK             (0x3C0U)
#define ENET_MAC_HW_FEAT_TXQCNT_SHIFT            (6U)
/*! TXQCNT - Number of MTL Transmit Queues. */
#define ENET_MAC_HW_FEAT_TXQCNT(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TXQCNT_SHIFT)) & ENET_MAC_HW_FEAT_TXQCNT_MASK)

#define ENET_MAC_HW_FEAT_MGKSEL_MASK             (0x80U)
#define ENET_MAC_HW_FEAT_MGKSEL_SHIFT            (7U)
/*! MGKSEL - PMT magic packet detection. */
#define ENET_MAC_HW_FEAT_MGKSEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_MGKSEL_SHIFT)) & ENET_MAC_HW_FEAT_MGKSEL_MASK)

#define ENET_MAC_HW_FEAT_MMCSEL_MASK             (0x100U)
#define ENET_MAC_HW_FEAT_MMCSEL_SHIFT            (8U)
/*! MMCSEL - RMON Module Enable. */
#define ENET_MAC_HW_FEAT_MMCSEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_MMCSEL_SHIFT)) & ENET_MAC_HW_FEAT_MMCSEL_MASK)

#define ENET_MAC_HW_FEAT_ARPOFFSEL_MASK          (0x200U)
#define ENET_MAC_HW_FEAT_ARPOFFSEL_SHIFT         (9U)
/*! ARPOFFSEL - ARP Offload Enabled. */
#define ENET_MAC_HW_FEAT_ARPOFFSEL(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_ARPOFFSEL_SHIFT)) & ENET_MAC_HW_FEAT_ARPOFFSEL_MASK)

#define ENET_MAC_HW_FEAT_OSTEN_MASK              (0x800U)
#define ENET_MAC_HW_FEAT_OSTEN_SHIFT             (11U)
/*! OSTEN - One-Step Timestamping Feature. */
#define ENET_MAC_HW_FEAT_OSTEN(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_OSTEN_SHIFT)) & ENET_MAC_HW_FEAT_OSTEN_MASK)

#define ENET_MAC_HW_FEAT_PTOEN_MASK              (0x1000U)
#define ENET_MAC_HW_FEAT_PTOEN_SHIFT             (12U)
/*! PTOEN - PTP OffLoad Feature. */
#define ENET_MAC_HW_FEAT_PTOEN(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_PTOEN_SHIFT)) & ENET_MAC_HW_FEAT_PTOEN_MASK)

#define ENET_MAC_HW_FEAT_RXCHCNT_MASK            (0xF000U)
#define ENET_MAC_HW_FEAT_RXCHCNT_SHIFT           (12U)
/*! RXCHCNT - Number of DMA Receive Channels. */
#define ENET_MAC_HW_FEAT_RXCHCNT(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_RXCHCNT_SHIFT)) & ENET_MAC_HW_FEAT_RXCHCNT_MASK)

#define ENET_MAC_HW_FEAT_TSSEL_MASK              (0x1000U)
#define ENET_MAC_HW_FEAT_TSSEL_SHIFT             (12U)
/*! TSSEL - IEEE 1588-2008 Timestamp support . */
#define ENET_MAC_HW_FEAT_TSSEL(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TSSEL_SHIFT)) & ENET_MAC_HW_FEAT_TSSEL_MASK)

#define ENET_MAC_HW_FEAT_ADVTHWORD_MASK          (0x2000U)
#define ENET_MAC_HW_FEAT_ADVTHWORD_SHIFT         (13U)
/*! ADVTHWORD - IEEE 1588 High Word Register Feature. */
#define ENET_MAC_HW_FEAT_ADVTHWORD(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_ADVTHWORD_SHIFT)) & ENET_MAC_HW_FEAT_ADVTHWORD_MASK)

#define ENET_MAC_HW_FEAT_EEESEL_MASK             (0x2000U)
#define ENET_MAC_HW_FEAT_EEESEL_SHIFT            (13U)
/*! EEESEL - Energy Efficient Ethernet Support . */
#define ENET_MAC_HW_FEAT_EEESEL(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_EEESEL_SHIFT)) & ENET_MAC_HW_FEAT_EEESEL_MASK)

#define ENET_MAC_HW_FEAT_ADDR64_MASK             (0xC000U)
#define ENET_MAC_HW_FEAT_ADDR64_SHIFT            (14U)
/*! ADDR64 - Address width. */
#define ENET_MAC_HW_FEAT_ADDR64(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_ADDR64_SHIFT)) & ENET_MAC_HW_FEAT_ADDR64_MASK)

#define ENET_MAC_HW_FEAT_TXCOESEL_MASK           (0x4000U)
#define ENET_MAC_HW_FEAT_TXCOESEL_SHIFT          (14U)
/*! TXCOESEL - Transmit Checksum Offload Support. */
#define ENET_MAC_HW_FEAT_TXCOESEL(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TXCOESEL_SHIFT)) & ENET_MAC_HW_FEAT_TXCOESEL_MASK)

#define ENET_MAC_HW_FEAT_DCBEN_MASK              (0x10000U)
#define ENET_MAC_HW_FEAT_DCBEN_SHIFT             (16U)
/*! DCBEN - Data Center Bridging feature. */
#define ENET_MAC_HW_FEAT_DCBEN(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_DCBEN_SHIFT)) & ENET_MAC_HW_FEAT_DCBEN_MASK)

#define ENET_MAC_HW_FEAT_RXCOESEL_MASK           (0x10000U)
#define ENET_MAC_HW_FEAT_RXCOESEL_SHIFT          (16U)
/*! RXCOESEL - Receive Checksum Offload Support. */
#define ENET_MAC_HW_FEAT_RXCOESEL(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_RXCOESEL_SHIFT)) & ENET_MAC_HW_FEAT_RXCOESEL_MASK)

#define ENET_MAC_HW_FEAT_SPEN_MASK               (0x20000U)
#define ENET_MAC_HW_FEAT_SPEN_SHIFT              (17U)
/*! SPEN - Split Header Structure feature. */
#define ENET_MAC_HW_FEAT_SPEN(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_SPEN_SHIFT)) & ENET_MAC_HW_FEAT_SPEN_MASK)

#define ENET_MAC_HW_FEAT_TSOEN_MASK              (0x40000U)
#define ENET_MAC_HW_FEAT_TSOEN_SHIFT             (18U)
/*! TSOEN - TCP Segment Offload Feature. */
#define ENET_MAC_HW_FEAT_TSOEN(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TSOEN_SHIFT)) & ENET_MAC_HW_FEAT_TSOEN_MASK)

#define ENET_MAC_HW_FEAT_TXCHCNT_MASK            (0x3C0000U)
#define ENET_MAC_HW_FEAT_TXCHCNT_SHIFT           (18U)
/*! TXCHCNT - Number of DMA Transmit Channels. */
#define ENET_MAC_HW_FEAT_TXCHCNT(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TXCHCNT_SHIFT)) & ENET_MAC_HW_FEAT_TXCHCNT_MASK)

#define ENET_MAC_HW_FEAT_DBGMEMA_MASK            (0x80000U)
#define ENET_MAC_HW_FEAT_DBGMEMA_SHIFT           (19U)
/*! DBGMEMA - DMA Debug Register Feature. */
#define ENET_MAC_HW_FEAT_DBGMEMA(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_DBGMEMA_SHIFT)) & ENET_MAC_HW_FEAT_DBGMEMA_MASK)

#define ENET_MAC_HW_FEAT_AVSEL_MASK              (0x100000U)
#define ENET_MAC_HW_FEAT_AVSEL_SHIFT             (20U)
/*! AVSEL - Audio Video Bridging Feature. */
#define ENET_MAC_HW_FEAT_AVSEL(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_AVSEL_SHIFT)) & ENET_MAC_HW_FEAT_AVSEL_MASK)

#define ENET_MAC_HW_FEAT_LPMODEEN_MASK           (0x800000U)
#define ENET_MAC_HW_FEAT_LPMODEEN_SHIFT          (23U)
/*! LPMODEEN - Low Power Mode Feature Support . */
#define ENET_MAC_HW_FEAT_LPMODEEN(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_LPMODEEN_SHIFT)) & ENET_MAC_HW_FEAT_LPMODEEN_MASK)

#define ENET_MAC_HW_FEAT_HASHTBLSZ_MASK          (0x3000000U)
#define ENET_MAC_HW_FEAT_HASHTBLSZ_SHIFT         (24U)
/*! HASHTBLSZ - Hash Table Size. */
#define ENET_MAC_HW_FEAT_HASHTBLSZ(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_HASHTBLSZ_SHIFT)) & ENET_MAC_HW_FEAT_HASHTBLSZ_MASK)

#define ENET_MAC_HW_FEAT_PPSOUTNUM_MASK          (0x7000000U)
#define ENET_MAC_HW_FEAT_PPSOUTNUM_SHIFT         (24U)
/*! PPSOUTNUM - Number of PPS Outputs. */
#define ENET_MAC_HW_FEAT_PPSOUTNUM(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_PPSOUTNUM_SHIFT)) & ENET_MAC_HW_FEAT_PPSOUTNUM_MASK)

#define ENET_MAC_HW_FEAT_TSSTSSEL_MASK           (0x6000000U)
#define ENET_MAC_HW_FEAT_TSSTSSEL_SHIFT          (25U)
/*! TSSTSSEL - Timestamp System Time Source. */
#define ENET_MAC_HW_FEAT_TSSTSSEL(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_TSSTSSEL_SHIFT)) & ENET_MAC_HW_FEAT_TSSTSSEL_MASK)

#define ENET_MAC_HW_FEAT_L3_L4_FILTER_MASK       (0x78000000U)
#define ENET_MAC_HW_FEAT_L3_L4_FILTER_SHIFT      (27U)
/*! L3_L4_FILTER - Total Number of L3 and L4 Filters . */
#define ENET_MAC_HW_FEAT_L3_L4_FILTER(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_L3_L4_FILTER_SHIFT)) & ENET_MAC_HW_FEAT_L3_L4_FILTER_MASK)

#define ENET_MAC_HW_FEAT_ACTPHYSEL_MASK          (0x70000000U)
#define ENET_MAC_HW_FEAT_ACTPHYSEL_SHIFT         (28U)
/*! ACTPHYSEL - Active PHY Selected. */
#define ENET_MAC_HW_FEAT_ACTPHYSEL(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_ACTPHYSEL_SHIFT)) & ENET_MAC_HW_FEAT_ACTPHYSEL_MASK)

#define ENET_MAC_HW_FEAT_AUXSNAPNUM_MASK         (0x70000000U)
#define ENET_MAC_HW_FEAT_AUXSNAPNUM_SHIFT        (28U)
/*! AUXSNAPNUM - Number of Auxiliary Snapshot Inputs. */
#define ENET_MAC_HW_FEAT_AUXSNAPNUM(x)           (((uint32_t)(((uint32_t)(x)) << ENET_MAC_HW_FEAT_AUXSNAPNUM_SHIFT)) & ENET_MAC_HW_FEAT_AUXSNAPNUM_MASK)
/*! @} */

/*! @name MAC_MDIO_ADDR - MIDO address Register */
/*! @{ */

#define ENET_MAC_MDIO_ADDR_MB_MASK               (0x1U)
#define ENET_MAC_MDIO_ADDR_MB_SHIFT              (0U)
/*! MB - MII busy. */
#define ENET_MAC_MDIO_ADDR_MB(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDR_MB_SHIFT)) & ENET_MAC_MDIO_ADDR_MB_MASK)

#define ENET_MAC_MDIO_ADDR_MOC_MASK              (0xCU)
#define ENET_MAC_MDIO_ADDR_MOC_SHIFT             (2U)
/*! MOC - MII Operation Command. */
#define ENET_MAC_MDIO_ADDR_MOC(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDR_MOC_SHIFT)) & ENET_MAC_MDIO_ADDR_MOC_MASK)

#define ENET_MAC_MDIO_ADDR_CR_MASK               (0xF00U)
#define ENET_MAC_MDIO_ADDR_CR_SHIFT              (8U)
/*! CR - CSR Clock Range. */
#define ENET_MAC_MDIO_ADDR_CR(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDR_CR_SHIFT)) & ENET_MAC_MDIO_ADDR_CR_MASK)

#define ENET_MAC_MDIO_ADDR_NTC_MASK              (0x7000U)
#define ENET_MAC_MDIO_ADDR_NTC_SHIFT             (12U)
/*! NTC - Number of Training Clocks This field controls the number of trailing clock cycles
 *    generated on MDC after the end of transmission of MDIO frame.
 */
#define ENET_MAC_MDIO_ADDR_NTC(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDR_NTC_SHIFT)) & ENET_MAC_MDIO_ADDR_NTC_MASK)

#define ENET_MAC_MDIO_ADDR_RDA_MASK              (0x1F0000U)
#define ENET_MAC_MDIO_ADDR_RDA_SHIFT             (16U)
/*! RDA - Register/Device Address These bits select the PHY register in selected PHY device. */
#define ENET_MAC_MDIO_ADDR_RDA(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDR_RDA_SHIFT)) & ENET_MAC_MDIO_ADDR_RDA_MASK)

#define ENET_MAC_MDIO_ADDR_PA_MASK               (0x3E00000U)
#define ENET_MAC_MDIO_ADDR_PA_SHIFT              (21U)
/*! PA - Physical Layer Address This field indicates which PHY devices (out of 32 devices) the MAC is accessing. */
#define ENET_MAC_MDIO_ADDR_PA(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDR_PA_SHIFT)) & ENET_MAC_MDIO_ADDR_PA_MASK)

#define ENET_MAC_MDIO_ADDR_BTB_MASK              (0x4000000U)
#define ENET_MAC_MDIO_ADDR_BTB_SHIFT             (26U)
/*! BTB - Back to Back transactions When this bit is set and the NTC has value greater than 0, then
 *    the MAC will inform the completion of a read or write command at the end of frame transfer
 *    (before the trailing clocks are transmitted).
 */
#define ENET_MAC_MDIO_ADDR_BTB(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDR_BTB_SHIFT)) & ENET_MAC_MDIO_ADDR_BTB_MASK)

#define ENET_MAC_MDIO_ADDR_PSE_MASK              (0x8000000U)
#define ENET_MAC_MDIO_ADDR_PSE_SHIFT             (27U)
/*! PSE - Preamble Suppression Enable When this bit is set, the SMA will suppress the 32-bit
 *    preamble and transmit MDIO frames with only 1 preamble bit.
 */
#define ENET_MAC_MDIO_ADDR_PSE(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_ADDR_PSE_SHIFT)) & ENET_MAC_MDIO_ADDR_PSE_MASK)
/*! @} */

/*! @name MAC_MDIO_DATA - MDIO Data register */
/*! @{ */

#define ENET_MAC_MDIO_DATA_MD_MASK               (0xFFFFU)
#define ENET_MAC_MDIO_DATA_MD_SHIFT              (0U)
/*! MD - MII Data This field contains the 16-bit data value read from the PHY after a Management
 *    Read operation or the 16-bit data value to be written to the PHY before a Management Write
 *    operation.
 */
#define ENET_MAC_MDIO_DATA_MD(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_MDIO_DATA_MD_SHIFT)) & ENET_MAC_MDIO_DATA_MD_MASK)
/*! @} */

/*! @name MAC_ADDR_HIGH - MAC address0 high register */
/*! @{ */

#define ENET_MAC_ADDR_HIGH_A47_32_MASK           (0xFFFFU)
#define ENET_MAC_ADDR_HIGH_A47_32_SHIFT          (0U)
/*! A47_32 - MAC Address0 [47:32] This field contains the upper 16 bits (47:32) of the 6-byte first MAC address. */
#define ENET_MAC_ADDR_HIGH_A47_32(x)             (((uint32_t)(((uint32_t)(x)) << ENET_MAC_ADDR_HIGH_A47_32_SHIFT)) & ENET_MAC_ADDR_HIGH_A47_32_MASK)

#define ENET_MAC_ADDR_HIGH_DCS_MASK              (0x10000U)
#define ENET_MAC_ADDR_HIGH_DCS_SHIFT             (16U)
/*! DCS - DMA Channel Select This field contains the DMA Channel number to which the Rx packet whose
 *    DA matches the MAC Address content is routed.
 */
#define ENET_MAC_ADDR_HIGH_DCS(x)                (((uint32_t)(((uint32_t)(x)) << ENET_MAC_ADDR_HIGH_DCS_SHIFT)) & ENET_MAC_ADDR_HIGH_DCS_MASK)

#define ENET_MAC_ADDR_HIGH_AE_MASK               (0x80000000U)
#define ENET_MAC_ADDR_HIGH_AE_SHIFT              (31U)
/*! AE - Address Enable. */
#define ENET_MAC_ADDR_HIGH_AE(x)                 (((uint32_t)(((uint32_t)(x)) << ENET_MAC_ADDR_HIGH_AE_SHIFT)) & ENET_MAC_ADDR_HIGH_AE_MASK)
/*! @} */

/*! @name MAC_ADDR_LOW - MAC address0 low register */
/*! @{ */

#define ENET_MAC_ADDR_LOW_A31_0_MASK             (0xFFFFFFFFU)
#define ENET_MAC_ADDR_LOW_A31_0_SHIFT            (0U)
/*! A31_0 - MAC Address0 [31:0] This field contains the lower 32 bits of the 6-byte first MAC address. */
#define ENET_MAC_ADDR_LOW_A31_0(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MAC_ADDR_LOW_A31_0_SHIFT)) & ENET_MAC_ADDR_LOW_A31_0_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_CTRL - Time stamp control register */
/*! @{ */

#define ENET_MAC_TIMESTAMP_CTRL_TSENA_MASK       (0x1U)
#define ENET_MAC_TIMESTAMP_CTRL_TSENA_SHIFT      (0U)
/*! TSENA - Enable Timestamp When this bit is set, the timestamp is added for Transmit and Receive packets. */
#define ENET_MAC_TIMESTAMP_CTRL_TSENA(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TSENA_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TSENA_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TSCFUPDT_MASK    (0x2U)
#define ENET_MAC_TIMESTAMP_CTRL_TSCFUPDT_SHIFT   (1U)
/*! TSCFUPDT - Fine or Coarse Timestamp Update When this bit is set, the Fine method is used to update system timestamp. */
#define ENET_MAC_TIMESTAMP_CTRL_TSCFUPDT(x)      (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TSCFUPDT_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TSCFUPDT_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TSINIT_MASK      (0x4U)
#define ENET_MAC_TIMESTAMP_CTRL_TSINIT_SHIFT     (2U)
/*! TSINIT - Initialize Timestamp When this bit is set, the system time is initialized (overwritten)
 *    with the value specified in the MAC Register 80 (System Time Seconds Update.
 */
#define ENET_MAC_TIMESTAMP_CTRL_TSINIT(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TSINIT_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TSINIT_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TSUPDT_MASK      (0x8U)
#define ENET_MAC_TIMESTAMP_CTRL_TSUPDT_SHIFT     (3U)
/*! TSUPDT - Update Timestamp When this bit is set, the system time is updated (added or subtracted)
 *    with the value specified in MAC System Time Seconds Update Table 753 and MAC System Time
 *    Nanoseconds Update Table 754.
 */
#define ENET_MAC_TIMESTAMP_CTRL_TSUPDT(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TSUPDT_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TSUPDT_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TSTRIG_MASK      (0x10U)
#define ENET_MAC_TIMESTAMP_CTRL_TSTRIG_SHIFT     (4U)
/*! TSTRIG - Enable Timestamp Interrupt Trigger When this bit is set, the timestamp interrupt is
 *    generated when the System Time becomes greater than the value written in the Target Time register.
 */
#define ENET_MAC_TIMESTAMP_CTRL_TSTRIG(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TSTRIG_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TSTRIG_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TADDREG_MASK     (0x20U)
#define ENET_MAC_TIMESTAMP_CTRL_TADDREG_SHIFT    (5U)
/*! TADDREG - Update Addend Register When this bit is set, the content of the Timestamp Addend
 *    register is updated in the PTP block for fine correction.
 */
#define ENET_MAC_TIMESTAMP_CTRL_TADDREG(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TADDREG_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TADDREG_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TSENALL_MASK     (0x100U)
#define ENET_MAC_TIMESTAMP_CTRL_TSENALL_SHIFT    (8U)
/*! TSENALL - Enable Timestamp for All Packets When this bit is set, the timestamp snapshot is
 *    enabled for all packets received by the MAC.
 */
#define ENET_MAC_TIMESTAMP_CTRL_TSENALL(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TSENALL_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TSENALL_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TSCTRLSSR_MASK   (0x200U)
#define ENET_MAC_TIMESTAMP_CTRL_TSCTRLSSR_SHIFT  (9U)
/*! TSCTRLSSR - Timestamp Digital or Binary Rollover Control When this bit is set, the Timestamp Low
 *    register rolls over after 0x3B9AC9FF value (that is, 1 nanosecond accuracy) and increments
 *    the timestamp (High) seconds.
 */
#define ENET_MAC_TIMESTAMP_CTRL_TSCTRLSSR(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TSCTRLSSR_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TSCTRLSSR_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TSVER2ENA_MASK   (0x400U)
#define ENET_MAC_TIMESTAMP_CTRL_TSVER2ENA_SHIFT  (10U)
/*! TSVER2ENA - Enable PTP Packet Processing for Version 2 Format When this bit is set, the IEEE
 *    1588 version 2 format is used to process the PTP packets.
 */
#define ENET_MAC_TIMESTAMP_CTRL_TSVER2ENA(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TSVER2ENA_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TSVER2ENA_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TSIPENA_MASK     (0x800U)
#define ENET_MAC_TIMESTAMP_CTRL_TSIPENA_SHIFT    (11U)
/*! TSIPENA - Enable Processing of PTP over Ethernet Packets When this bit is set, the MAC receiver
 *    processes the PTP packets encapsulated directly in the Ethernet packets.
 */
#define ENET_MAC_TIMESTAMP_CTRL_TSIPENA(x)       (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TSIPENA_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TSIPENA_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TSIPV6ENA_MASK   (0x1000U)
#define ENET_MAC_TIMESTAMP_CTRL_TSIPV6ENA_SHIFT  (12U)
/*! TSIPV6ENA - Enable Processing of PTP Packets Sent over 1Pv6-UDP When this bit is set, the MAC
 *    receiver processes the PTP packets encapsulated in IPv6-UDP packets.
 */
#define ENET_MAC_TIMESTAMP_CTRL_TSIPV6ENA(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TSIPV6ENA_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TSIPV6ENA_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TSIPV4ENA_MASK   (0x2000U)
#define ENET_MAC_TIMESTAMP_CTRL_TSIPV4ENA_SHIFT  (13U)
/*! TSIPV4ENA - Enable Processing of PTP Packets Sent over IPv4-UDP When this bit is set, the MAC
 *    receiver processes the PTP packets encapsulated in IPv4-UDP packets.
 */
#define ENET_MAC_TIMESTAMP_CTRL_TSIPV4ENA(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TSIPV4ENA_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TSIPV4ENA_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TSEVTENA_MASK    (0x4000U)
#define ENET_MAC_TIMESTAMP_CTRL_TSEVTENA_SHIFT   (14U)
/*! TSEVTENA - Enable Timestamp Snapshot for Event Messages When this bit is set, the timestamp
 *    snapshot is taken only for event messages (SYNC, Delay_Req, Pdelay_Req, or Pdelay_Resp).
 */
#define ENET_MAC_TIMESTAMP_CTRL_TSEVTENA(x)      (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TSEVTENA_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TSEVTENA_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TSMSTRENA_MASK   (0x8000U)
#define ENET_MAC_TIMESTAMP_CTRL_TSMSTRENA_SHIFT  (15U)
/*! TSMSTRENA - Enable Snapshot for Messages Relevant to Master When this bit is set, the snapshot
 *    is taken only for the messages that are relevant to the master node.
 */
#define ENET_MAC_TIMESTAMP_CTRL_TSMSTRENA(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TSMSTRENA_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TSMSTRENA_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_SNAPTYPSEL_MASK  (0x30000U)
#define ENET_MAC_TIMESTAMP_CTRL_SNAPTYPSEL_SHIFT (16U)
/*! SNAPTYPSEL - Select PTP packets for Taking Snapshots These bits, along with Bits 15 and 14,
 *    decide the set of PTP packet types for which snapshot needs to be taken.
 */
#define ENET_MAC_TIMESTAMP_CTRL_SNAPTYPSEL(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_SNAPTYPSEL_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_SNAPTYPSEL_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TSENMACADDR_MASK (0x40000U)
#define ENET_MAC_TIMESTAMP_CTRL_TSENMACADDR_SHIFT (18U)
/*! TSENMACADDR - Enable MAC Address for PTP Packet Filtering When this bit is set, the DA MAC
 *    address (that matches any MAC Address register) is used to filter the PTP packets when PTP is
 *    directly sent over Ethernet.
 */
#define ENET_MAC_TIMESTAMP_CTRL_TSENMACADDR(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TSENMACADDR_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TSENMACADDR_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_TXTTSSTSM_MASK   (0x1000000U)
#define ENET_MAC_TIMESTAMP_CTRL_TXTTSSTSM_SHIFT  (24U)
/*! TXTTSSTSM - Transmit Timestamp Status Mode When this bit is set, the MAC overwrites the earlier
 *    transmit timestamp status even if it is not read by the software.
 */
#define ENET_MAC_TIMESTAMP_CTRL_TXTTSSTSM(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_TXTTSSTSM_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_TXTTSSTSM_MASK)

#define ENET_MAC_TIMESTAMP_CTRL_AV8021ASMEN_MASK (0x10000000U)
#define ENET_MAC_TIMESTAMP_CTRL_AV8021ASMEN_SHIFT (28U)
/*! AV8021ASMEN - AV 802. */
#define ENET_MAC_TIMESTAMP_CTRL_AV8021ASMEN(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_CTRL_AV8021ASMEN_SHIFT)) & ENET_MAC_TIMESTAMP_CTRL_AV8021ASMEN_MASK)
/*! @} */

/*! @name MAC_SUB_SCND_INCR - Sub-second increment register */
/*! @{ */

#define ENET_MAC_SUB_SCND_INCR_SSINC_MASK        (0xFF0000U)
#define ENET_MAC_SUB_SCND_INCR_SSINC_SHIFT       (16U)
/*! SSINC - Sub-second increment value. */
#define ENET_MAC_SUB_SCND_INCR_SSINC(x)          (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SUB_SCND_INCR_SSINC_SHIFT)) & ENET_MAC_SUB_SCND_INCR_SSINC_MASK)
/*! @} */

/*! @name MAC_SYS_TIME_SCND - System time seconds register */
/*! @{ */

#define ENET_MAC_SYS_TIME_SCND_TSS_MASK          (0xFFFFFFFFU)
#define ENET_MAC_SYS_TIME_SCND_TSS_SHIFT         (0U)
/*! TSS - Time stamp second The value in this field indicates the current value in seconds of the
 *    System Time maintained by the MAC.
 */
#define ENET_MAC_SYS_TIME_SCND_TSS(x)            (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SYS_TIME_SCND_TSS_SHIFT)) & ENET_MAC_SYS_TIME_SCND_TSS_MASK)
/*! @} */

/*! @name MAC_SYS_TIME_NSCND - System time nanoseconds register */
/*! @{ */

#define ENET_MAC_SYS_TIME_NSCND_TSSS_MASK        (0x7FFFFFFFU)
#define ENET_MAC_SYS_TIME_NSCND_TSSS_SHIFT       (0U)
/*! TSSS - Time stamp sub seconds The value in this field has the sub second representation of time, with an accuracy of 0. */
#define ENET_MAC_SYS_TIME_NSCND_TSSS(x)          (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SYS_TIME_NSCND_TSSS_SHIFT)) & ENET_MAC_SYS_TIME_NSCND_TSSS_MASK)
/*! @} */

/*! @name MAC_SYS_TIME_SCND_UPD -  */
/*! @{ */

#define ENET_MAC_SYS_TIME_SCND_UPD_TSS_MASK      (0xFFFFFFFFU)
#define ENET_MAC_SYS_TIME_SCND_UPD_TSS_SHIFT     (0U)
/*! TSS - Time stamp second The value in this field indicates the time, in seconds, to be initialized or added to the system time. */
#define ENET_MAC_SYS_TIME_SCND_UPD_TSS(x)        (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SYS_TIME_SCND_UPD_TSS_SHIFT)) & ENET_MAC_SYS_TIME_SCND_UPD_TSS_MASK)
/*! @} */

/*! @name MAC_SYS_TIME_NSCND_UPD -  */
/*! @{ */

#define ENET_MAC_SYS_TIME_NSCND_UPD_TSSS_MASK    (0x7FFFFFFFU)
#define ENET_MAC_SYS_TIME_NSCND_UPD_TSSS_SHIFT   (0U)
/*! TSSS - Time stamp sub seconds The value in this field has the sub second representation of time, with an accuracy of 0. */
#define ENET_MAC_SYS_TIME_NSCND_UPD_TSSS(x)      (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SYS_TIME_NSCND_UPD_TSSS_SHIFT)) & ENET_MAC_SYS_TIME_NSCND_UPD_TSSS_MASK)

#define ENET_MAC_SYS_TIME_NSCND_UPD_ADDSUB_MASK  (0x80000000U)
#define ENET_MAC_SYS_TIME_NSCND_UPD_ADDSUB_SHIFT (31U)
/*! ADDSUB - Add or subtract time When this bit is set, the time value is subtracted with the contents of the update register. */
#define ENET_MAC_SYS_TIME_NSCND_UPD_ADDSUB(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SYS_TIME_NSCND_UPD_ADDSUB_SHIFT)) & ENET_MAC_SYS_TIME_NSCND_UPD_ADDSUB_MASK)
/*! @} */

/*! @name MAC_SYS_TIMESTMP_ADDEND - Time stamp addend register */
/*! @{ */

#define ENET_MAC_SYS_TIMESTMP_ADDEND_TSAR_MASK   (0xFFFFFFFFU)
#define ENET_MAC_SYS_TIMESTMP_ADDEND_TSAR_SHIFT  (0U)
/*! TSAR - Time stamp addend This register indicates the 32-bit time value to be added to the
 *    Accumulator register to achieve time synchronization.
 */
#define ENET_MAC_SYS_TIMESTMP_ADDEND_TSAR(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SYS_TIMESTMP_ADDEND_TSAR_SHIFT)) & ENET_MAC_SYS_TIMESTMP_ADDEND_TSAR_MASK)
/*! @} */

/*! @name MAC_SYS_TIME_HWORD_SCND -  */
/*! @{ */

#define ENET_MAC_SYS_TIME_HWORD_SCND_TSHWR_MASK  (0xFFFFU)
#define ENET_MAC_SYS_TIME_HWORD_SCND_TSHWR_SHIFT (0U)
/*! TSHWR - Time stamp higher word Contains the most significant 16-bits of the Time stamp seconds value. */
#define ENET_MAC_SYS_TIME_HWORD_SCND_TSHWR(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SYS_TIME_HWORD_SCND_TSHWR_SHIFT)) & ENET_MAC_SYS_TIME_HWORD_SCND_TSHWR_MASK)
/*! @} */

/*! @name MAC_SYS_TIMESTMP_STAT - Time stamp status register */
/*! @{ */

#define ENET_MAC_SYS_TIMESTMP_STAT_TSSOVF_MASK   (0x1U)
#define ENET_MAC_SYS_TIMESTMP_STAT_TSSOVF_SHIFT  (0U)
/*! TSSOVF - Time stamp seconds overflow When set, indicates that the seconds value of the Time
 *    stamp has overflowed beyond 0xFFFF_FFFF.
 */
#define ENET_MAC_SYS_TIMESTMP_STAT_TSSOVF(x)     (((uint32_t)(((uint32_t)(x)) << ENET_MAC_SYS_TIMESTMP_STAT_TSSOVF_SHIFT)) & ENET_MAC_SYS_TIMESTMP_STAT_TSSOVF_MASK)
/*! @} */

/*! @name MAC_TX_TIMESTAMP_STATUS_NANOSECONDS - Tx timestamp status nanoseconds */
/*! @{ */

#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSTSLO_MASK (0x7FFFFFFFU)
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSTSLO_SHIFT (0U)
/*! TXTSSTSLO - Transmit timestamp status low. */
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSTSLO(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSTSLO_SHIFT)) & ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSTSLO_MASK)

#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSTSMIS_MASK (0x80000000U)
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSTSMIS_SHIFT (31U)
/*! TXTSSTSMIS - Transmit timestamp status missed. */
#define ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSTSMIS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSTSMIS_SHIFT)) & ENET_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSTSMIS_MASK)
/*! @} */

/*! @name MAC_TX_TIMESTAMP_STATUS_SECONDS - Tx timestamp status seconds */
/*! @{ */

#define ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSTSHI_MASK (0xFFFFFFFFU)
#define ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSTSHI_SHIFT (0U)
/*! TXTSSTSHI - Transmit timestamp status high. */
#define ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSTSHI(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSTSHI_SHIFT)) & ENET_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSTSHI_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND - Timestamp ingress correction */
/*! @{ */

#define ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_MASK (0xFFFFFFFFU)
#define ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_SHIFT (0U)
/*! TSIC - Transmit ingress correction. */
#define ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_SHIFT)) & ENET_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND - Timestamp egress correction */
/*! @{ */

#define ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_MASK (0xFFFFFFFFU)
#define ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_SHIFT (0U)
/*! TSEC - Transmit egress correction. */
#define ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC(x) (((uint32_t)(((uint32_t)(x)) << ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_SHIFT)) & ENET_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_MASK)
/*! @} */

/*! @name MTL_OP_MODE - MTL Operation Mode Register */
/*! @{ */

#define ENET_MTL_OP_MODE_DTXSTS_MASK             (0x2U)
#define ENET_MTL_OP_MODE_DTXSTS_SHIFT            (1U)
/*! DTXSTS - Drop Transmit Status When this bit is set, the Tx packet status received from the MAC is dropped in the MTL. */
#define ENET_MTL_OP_MODE_DTXSTS(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MTL_OP_MODE_DTXSTS_SHIFT)) & ENET_MTL_OP_MODE_DTXSTS_MASK)

#define ENET_MTL_OP_MODE_RAA_MASK                (0x4U)
#define ENET_MTL_OP_MODE_RAA_SHIFT               (2U)
/*! RAA - Receive Arbitration Algorithm This field is used to select the arbitration algorithm for the Rx side. */
#define ENET_MTL_OP_MODE_RAA(x)                  (((uint32_t)(((uint32_t)(x)) << ENET_MTL_OP_MODE_RAA_SHIFT)) & ENET_MTL_OP_MODE_RAA_MASK)

#define ENET_MTL_OP_MODE_SCHALG_MASK             (0x60U)
#define ENET_MTL_OP_MODE_SCHALG_SHIFT            (5U)
/*! SCHALG - Tx Scheduling Algorithm This field indicates the algorithm for Tx scheduling: 0x00: WRR
 *    algorithm 0x1: Reserved 0x2: Reserved 0x3: Strict priority algorithm.
 */
#define ENET_MTL_OP_MODE_SCHALG(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MTL_OP_MODE_SCHALG_SHIFT)) & ENET_MTL_OP_MODE_SCHALG_MASK)

#define ENET_MTL_OP_MODE_CNTPRST_MASK            (0x100U)
#define ENET_MTL_OP_MODE_CNTPRST_SHIFT           (8U)
/*! CNTPRST - Counters Preset When this bit is set, MTL TxQ0 Underflow register (Table 762) and
 *    MTL_TxQ1_Underflow (Table 762) registers are initialized/preset to 0x7F0.
 */
#define ENET_MTL_OP_MODE_CNTPRST(x)              (((uint32_t)(((uint32_t)(x)) << ENET_MTL_OP_MODE_CNTPRST_SHIFT)) & ENET_MTL_OP_MODE_CNTPRST_MASK)

#define ENET_MTL_OP_MODE_CNTCLR_MASK             (0x200U)
#define ENET_MTL_OP_MODE_CNTCLR_SHIFT            (9U)
/*! CNTCLR - Counters Reset When this bit is set, all counters are reset. */
#define ENET_MTL_OP_MODE_CNTCLR(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MTL_OP_MODE_CNTCLR_SHIFT)) & ENET_MTL_OP_MODE_CNTCLR_MASK)
/*! @} */

/*! @name MTL_INTR_STAT - MTL Interrupt Status register */
/*! @{ */

#define ENET_MTL_INTR_STAT_Q0IS_MASK             (0x1U)
#define ENET_MTL_INTR_STAT_Q0IS_SHIFT            (0U)
/*! Q0IS - Queue 0 Interrupt status This bit indicates that there is an interrupt from Queue 0. */
#define ENET_MTL_INTR_STAT_Q0IS(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MTL_INTR_STAT_Q0IS_SHIFT)) & ENET_MTL_INTR_STAT_Q0IS_MASK)

#define ENET_MTL_INTR_STAT_Q1IS_MASK             (0x2U)
#define ENET_MTL_INTR_STAT_Q1IS_SHIFT            (1U)
/*! Q1IS - Queue 1 Interrupt status This bit indicates that there is an interrupt from Queue 1. */
#define ENET_MTL_INTR_STAT_Q1IS(x)               (((uint32_t)(((uint32_t)(x)) << ENET_MTL_INTR_STAT_Q1IS_SHIFT)) & ENET_MTL_INTR_STAT_Q1IS_MASK)
/*! @} */

/*! @name MTL_RXQ_DMA_MAP - MTL Receive Queue and DMA Channel Mapping register */
/*! @{ */

#define ENET_MTL_RXQ_DMA_MAP_Q0MDMACH_MASK       (0x1U)
#define ENET_MTL_RXQ_DMA_MAP_Q0MDMACH_SHIFT      (0U)
/*! Q0MDMACH - Queue 0 Mapped to DMA Channel This field controls the routing of the packet received
 *    in Queue 0 to the DMA channel: 0: DMA Channel 0 1: DMA Channel 1 This field is valid when the
 *    Q0DDMACH field is reset.
 */
#define ENET_MTL_RXQ_DMA_MAP_Q0MDMACH(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MTL_RXQ_DMA_MAP_Q0MDMACH_SHIFT)) & ENET_MTL_RXQ_DMA_MAP_Q0MDMACH_MASK)

#define ENET_MTL_RXQ_DMA_MAP_Q0DDMACH_MASK       (0x10U)
#define ENET_MTL_RXQ_DMA_MAP_Q0DDMACH_SHIFT      (4U)
/*! Q0DDMACH - Queue 0 Enabled for DA-based DMA Channel Selection When set, this bit indicates that
 *    the packets received in Queue 0 are routed to a particular DMA channel as decided in the MAC
 *    Receiver based on the DMA channel number programmed in the L3-L4 filter registers, or the
 *    Ethernet DA address.
 */
#define ENET_MTL_RXQ_DMA_MAP_Q0DDMACH(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MTL_RXQ_DMA_MAP_Q0DDMACH_SHIFT)) & ENET_MTL_RXQ_DMA_MAP_Q0DDMACH_MASK)

#define ENET_MTL_RXQ_DMA_MAP_Q1MDMACH_MASK       (0x100U)
#define ENET_MTL_RXQ_DMA_MAP_Q1MDMACH_SHIFT      (8U)
/*! Q1MDMACH - Queue 1 Mapped to DMA Channel This field controls the routing of the received packet
 *    in Queue 1 to the DMA channel: 0: DMA Channel 0 1: DMA Channel 1 This field is valid when the
 *    Q1DDMACH field is reset.
 */
#define ENET_MTL_RXQ_DMA_MAP_Q1MDMACH(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MTL_RXQ_DMA_MAP_Q1MDMACH_SHIFT)) & ENET_MTL_RXQ_DMA_MAP_Q1MDMACH_MASK)

#define ENET_MTL_RXQ_DMA_MAP_Q1DDMACH_MASK       (0x1000U)
#define ENET_MTL_RXQ_DMA_MAP_Q1DDMACH_SHIFT      (12U)
/*! Q1DDMACH - Queue 1 Enabled for DA-based DMA Channel Selection When set, this bit indicates that
 *    the packets received in Queue 1 are routed to a particular DMA channel as decided in the MAC
 *    Receiver based on the DMA channel number programmed in the L3-L4 filter registers, or the
 *    Ethernet DA address.
 */
#define ENET_MTL_RXQ_DMA_MAP_Q1DDMACH(x)         (((uint32_t)(((uint32_t)(x)) << ENET_MTL_RXQ_DMA_MAP_Q1DDMACH_SHIFT)) & ENET_MTL_RXQ_DMA_MAP_Q1DDMACH_MASK)
/*! @} */

/*! @name MTL_QUEUE_MTL_TXQX_OP_MODE - MTL TxQx Operation Mode register */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_FTQ_MASK (0x1U)
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_FTQ_SHIFT (0U)
/*! FTQ - Flush Transmit Queue When this bit is set, the Tx queue controller logic is reset to its default values. */
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_FTQ(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_FTQ_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_FTQ_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TSF_MASK (0x2U)
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TSF_SHIFT (1U)
/*! TSF - Transmit Store and Forward When this bit is set, the transmission starts when a full packet resides in the MTL Tx queue. */
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TSF(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TSF_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TSF_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TXQEN_MASK (0xCU)
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TXQEN_SHIFT (2U)
/*! TXQEN - Transmit Queue Enable This field is used to enable/disable the transmit queue 0. */
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TXQEN(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TXQEN_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TXQEN_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TTC_MASK (0x70U)
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TTC_SHIFT (4U)
/*! TTC - Transmit Threshold Control These bits control the threshold level of the MTL Tx Queue. */
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TTC(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TTC_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TTC_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TQS_MASK (0x70000U)
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TQS_SHIFT (16U)
/*! TQS - Transmit Queue Size This field indicates the size of the allocated Transmit queues in blocks of 256 bytes. */
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TQS(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TQS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_TQS_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_OP_MODE */
#define ENET_MTL_QUEUE_MTL_TXQX_OP_MODE_COUNT    (2U)

/*! @name MTL_QUEUE_MTL_TXQX_UNDRFLW - MTL TxQx Underflow register */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFFRMCNT_MASK (0x7FFU)
#define ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFFRMCNT_SHIFT (0U)
/*! UFFRMCNT - Underflow Packet Counter This field indicates the number of packets aborted by the
 *    controller because of Tx Queue Underflow.
 */
#define ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFFRMCNT(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFFRMCNT_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFFRMCNT_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFCNTOVF_MASK (0x800U)
#define ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFCNTOVF_SHIFT (11U)
/*! UFCNTOVF - Overflow Bit for Underflow Packet Counter This bit is set every time the Tx queue
 *    Underflow Packet Counter field overflows, that is, it has crossed the maximum count.
 */
#define ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFCNTOVF_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_UFCNTOVF_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW */
#define ENET_MTL_QUEUE_MTL_TXQX_UNDRFLW_COUNT    (2U)

/*! @name MTL_QUEUE_MTL_TXQX_DBG - MTL TxQx Debug register */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQPAUSED_MASK (0x1U)
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQPAUSED_SHIFT (0U)
/*! TXQPAUSED - Transmit Queue in Pause When this bit is high and the Rx flow control is enabled, it
 *    indicates that the Tx Queue is in the Pause condition (in the full-duplex only mode) because
 *    of the following: - Reception of the PFC packet for the priorities assigned to the Tx Queue
 *    when PFC is enabled - Reception of 802.
 */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQPAUSED(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQPAUSED_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQPAUSED_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TRCSTS_MASK  (0x6U)
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TRCSTS_SHIFT (1U)
/*! TRCSTS - MTL Tx Queue Read Controller Status This field indicates the state of the Tx Queue Read
 *    Controller: 00: Idle state 01: Read state (transferring data to the MAC transmitter) 10:
 *    Waiting for pending Tx Status from the MAC transmitter 11: Flushing the Tx queue because of the
 *    Packet Abort request from the MAC.
 */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TRCSTS(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_DBG_TRCSTS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_DBG_TRCSTS_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TWCSTS_MASK  (0x8U)
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TWCSTS_SHIFT (3U)
/*! TWCSTS - MTL Tx Queue Write Controller Status When high, this bit indicates that the MTL Tx
 *    Queue Write Controller is active, and it is transferring the data to the Tx Queue.
 */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TWCSTS(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_DBG_TWCSTS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_DBG_TWCSTS_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQSTS_MASK  (0x10U)
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQSTS_SHIFT (4U)
/*! TXQSTS - MTL Tx Queue Not Empty Status When this bit is high, it indicates that the MTL Tx Queue
 *    is not empty and some data is left for transmission.
 */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQSTS(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQSTS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_DBG_TXQSTS_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXSTSFSTS_MASK (0x20U)
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXSTSFSTS_SHIFT (5U)
/*! TXSTSFSTS - MTL Tx Status FIFO Full Status When high, this bit indicates that the MTL Tx Status FIFO is full. */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_TXSTSFSTS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_DBG_TXSTSFSTS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_DBG_TXSTSFSTS_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_DBG_PTXQ_MASK    (0x70000U)
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_PTXQ_SHIFT   (16U)
/*! PTXQ - Number of Packets in the Transmit Queue This field indicates the current number of packets in the Tx Queue. */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_PTXQ(x)      (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_DBG_PTXQ_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_DBG_PTXQ_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_DBG_STSXSTSF_MASK (0x700000U)
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_STSXSTSF_SHIFT (20U)
/*! STSXSTSF - Number of Status Words in Tx Status FIFO of Queue This field indicates the current
 *    number of status in the Tx Status FIFO of this queue.
 */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_STSXSTSF(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_DBG_STSXSTSF_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_DBG_STSXSTSF_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_DBG */
#define ENET_MTL_QUEUE_MTL_TXQX_DBG_COUNT        (2U)

/*! @name MTL_QUEUE_MTL_TXQX_ETS_CTRL - MTL TxQx ETS control register, only TxQ1 support */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_AVALG_MASK (0x4U)
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_AVALG_SHIFT (2U)
/*! AVALG - AV Algorithm. */
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_AVALG(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_AVALG_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_AVALG_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_CC_MASK (0x8U)
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_CC_SHIFT (3U)
/*! CC - Credit Control. */
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_CC(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_CC_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_CC_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_SLC_MASK (0x70U)
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_SLC_SHIFT (4U)
/*! SLC - Credit Control. */
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_SLC(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_SLC_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_SLC_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL */
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_CTRL_COUNT   (2U)

/*! @name MTL_QUEUE_MTL_TXQX_ETS_STAT - MTL TxQx ETS Status register */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_ETS_STAT_ABS_MASK (0xFFFFFFU)
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_STAT_ABS_SHIFT (0U)
/*! ABS - Average Bits per Slot. */
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_STAT_ABS(x)  (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_ETS_STAT_ABS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_ETS_STAT_ABS_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_ETS_STAT */
#define ENET_MTL_QUEUE_MTL_TXQX_ETS_STAT_COUNT   (2U)

/*! @name MTL_QUEUE_MTL_TXQX_QNTM_WGHT -  */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_QNTM_WGHT_ISCQW_MASK (0x1FFFFFU)
#define ENET_MTL_QUEUE_MTL_TXQX_QNTM_WGHT_ISCQW_SHIFT (0U)
/*! ISCQW - Average Bits per Slot. */
#define ENET_MTL_QUEUE_MTL_TXQX_QNTM_WGHT_ISCQW(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_QNTM_WGHT_ISCQW_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_QNTM_WGHT_ISCQW_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_QNTM_WGHT */
#define ENET_MTL_QUEUE_MTL_TXQX_QNTM_WGHT_COUNT  (2U)

/*! @name MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT - MTL TxQx SendSlopCredit register, only TxQ1 support */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT_SSC_MASK (0x3FFFU)
#define ENET_MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT_SSC_SHIFT (0U)
/*! SSC - sendSlopeCredit. */
#define ENET_MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT_SSC(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT_SSC_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT_SSC_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT */
#define ENET_MTL_QUEUE_MTL_TXQX_SNDSLP_CRDT_COUNT (2U)

/*! @name MTL_QUEUE_MTL_TXQX_HI_CRDT - MTL TxQx hiCredit register, only TxQ1 support */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_HI_CRDT_HC_MASK  (0x1FFFFFFFU)
#define ENET_MTL_QUEUE_MTL_TXQX_HI_CRDT_HC_SHIFT (0U)
/*! HC - hiCredit. */
#define ENET_MTL_QUEUE_MTL_TXQX_HI_CRDT_HC(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_HI_CRDT_HC_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_HI_CRDT_HC_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_HI_CRDT */
#define ENET_MTL_QUEUE_MTL_TXQX_HI_CRDT_COUNT    (2U)

/*! @name MTL_QUEUE_MTL_TXQX_LO_CRDT - MTL TxQx loCredit register, only TxQ1 support */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_LO_CRDT_LC_MASK  (0x1FFFFFFFU)
#define ENET_MTL_QUEUE_MTL_TXQX_LO_CRDT_LC_SHIFT (0U)
/*! LC - loCredit. */
#define ENET_MTL_QUEUE_MTL_TXQX_LO_CRDT_LC(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_LO_CRDT_LC_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_LO_CRDT_LC_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_LO_CRDT */
#define ENET_MTL_QUEUE_MTL_TXQX_LO_CRDT_COUNT    (2U)

/*! @name MTL_QUEUE_MTL_TXQX_INTCTRL_STAT -  */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_TXUNFIS_MASK (0x1U)
#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_TXUNFIS_SHIFT (0U)
/*! TXUNFIS - Transmit Queue Underflow Interrupt Status This bit indicates that the Transmit Queue
 *    had an underflow while transmitting the packet.
 */
#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_TXUNFIS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_TXUNFIS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_TXUNFIS_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_ABPSIS_MASK (0x2U)
#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_ABPSIS_SHIFT (1U)
/*! ABPSIS - Average Bits Per Slot Interrupt Status When set, this bit indicates that the MAC has updated the ABS value. */
#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_ABPSIS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_ABPSIS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_ABPSIS_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_TXUIE_MASK (0x100U)
#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_TXUIE_SHIFT (8U)
/*! TXUIE - Transmit Queue Underflow Interrupt Enable When this bit is set, the Transmit Queue Underflow interrupt is enabled. */
#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_TXUIE(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_TXUIE_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_TXUIE_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_ABPSIE_MASK (0x200U)
#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_ABPSIE_SHIFT (9U)
/*! ABPSIE - Average Bits Per Slot Interrupt Enable When this bit is set, the MAC asserts the
 *    interrupt when the average bits per slot status is updated.
 */
#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_ABPSIE(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_ABPSIE_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_ABPSIE_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_RXOVFIS_MASK (0x10000U)
#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_RXOVFIS_SHIFT (16U)
/*! RXOVFIS - Receive Queue Overflow Interrupt Status This bit indicates that the Receive Queue had
 *    an overflow while receiving the packet.
 */
#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_RXOVFIS(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_RXOVFIS_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_RXOVFIS_MASK)

#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_RXOIE_MASK (0x1000000U)
#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_RXOIE_SHIFT (24U)
/*! RXOIE - Receive Queue Overflow Interrupt Enable When this bit is set, the Receive Queue Overflow interrupt is enabled. */
#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_RXOIE(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_RXOIE_SHIFT)) & ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_RXOIE_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT */
#define ENET_MTL_QUEUE_MTL_TXQX_INTCTRL_STAT_COUNT (2U)

/*! @name MTL_QUEUE_MTL_RXQX_OP_MODE - MTL RxQx Operation Mode register */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RTC_MASK (0x3U)
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RTC_SHIFT (0U)
/*! RTC - Receive Queue Threshold Control These bits control the threshold level of the MTL Rx queue
 *    (in bytes): 00: 64 01: 32 10: 96 11: 128 The packet received is transferred to the
 *    application or DMA when the packet size within the MTL Rx queue is larger than the threshold.
 */
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RTC(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RTC_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RTC_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FUP_MASK (0x8U)
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FUP_SHIFT (3U)
/*! FUP - Forward Undersized Good Packets When this bit is set, the Rx queue forwards the undersized
 *    good packets (packets with no error and length less than 64 bytes), including pad-bytes and
 *    CRC.
 */
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FUP(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FUP_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FUP_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FEP_MASK (0x10U)
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FEP_SHIFT (4U)
/*! FEP - Forward Error Packets When this bit is reset, the Rx queue drops packets with error status
 *    (CRC error, Mll_ER, watchdog timeout, or overflow).
 */
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FEP(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FEP_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_FEP_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RSF_MASK (0x20U)
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RSF_SHIFT (5U)
/*! RSF - Receive Queue Store and Forward When this bit is set, the ethernet block on this chip
 *    reads a packet from the Rx queue only after the complete packet has been written to it, ignoring
 *    the RTC field of this register.
 */
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RSF(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RSF_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RSF_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_DIS_TCP_EF_MASK (0x40U)
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_DIS_TCP_EF_SHIFT (6U)
/*! DIS_TCP_EF - Disable Dropping of TCP/IP Checksum Error Packets When this bit is set, the MAC
 *    does not drop the packets which only have the errors detected by the Receive Checksum Offload
 *    engine.
 */
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_DIS_TCP_EF(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_DIS_TCP_EF_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_DIS_TCP_EF_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RQS_MASK (0x700000U)
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RQS_SHIFT (20U)
/*! RQS - This field indicates the size of the allocated Receive queues in blocks of 256 bytes. */
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RQS(x)   (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RQS_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_RQS_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_RXQX_OP_MODE */
#define ENET_MTL_QUEUE_MTL_RXQX_OP_MODE_COUNT    (2U)

/*! @name MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT - MTL RxQx Missed Packet Overflow Counter register */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFPKTCNT_MASK (0x7FFU)
#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFPKTCNT_SHIFT (0U)
/*! OVFPKTCNT - Overflow Packet Counter This field indicates the number of packets discarded by the
 *    Ethernet block because of Receive queue overflow.
 */
#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFPKTCNT(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFPKTCNT_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFPKTCNT_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFCNTOVF_MASK (0x800U)
#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFCNTOVF_SHIFT (11U)
/*! OVFCNTOVF - Overflow Counter Overflow Bit When set, this bit indicates that the Rx Queue
 *    Overflow Packet Counter field crossed the maximum limit.
 */
#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFCNTOVF_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_OVFCNTOVF_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT */
#define ENET_MTL_QUEUE_MTL_RXQX_MISSPKT_OVRFLW_CNT_COUNT (2U)

/*! @name MTL_QUEUE_MTL_RXQX_DBG - MTL RxQx Debug register */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RWCSTS_MASK  (0x1U)
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RWCSTS_SHIFT (0U)
/*! RWCSTS - MTL Rx Queue Write Controller Active Status When high, this bit indicates that the MTL
 *    Rx queue Write controller is active, and it is transferring a received packet to the Rx Queue.
 */
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RWCSTS(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_DBG_RWCSTS_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_DBG_RWCSTS_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RRCSTS_MASK  (0x6U)
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RRCSTS_SHIFT (1U)
/*! RRCSTS - MTL Rx Queue Read Controller State This field gives the state of the Rx queue Read
 *    controller: 00: Idle state 01: Reading packet data 10: Reading packet status (or timestamp) 11:
 *    Flushing the packet data and status.
 */
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RRCSTS(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_DBG_RRCSTS_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_DBG_RRCSTS_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RXQSTS_MASK  (0x30U)
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RXQSTS_SHIFT (4U)
/*! RXQSTS - MTL Rx Queue Fill-Level Status This field gives the status of the fill-level of the Rx
 *    Queue: 0x0: Rx Queue empty 0x1: Rx Queue fill-level below flow-control deactivate threshold
 *    0x2: Rx Queue fill-level above flow-control activate threshold 0x3: Rx Queue full.
 */
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_RXQSTS(x)    (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_DBG_RXQSTS_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_DBG_RXQSTS_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_DBG_PRXQ_MASK    (0x3FFF0000U)
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_PRXQ_SHIFT   (16U)
/*! PRXQ - Number of Packets in Receive Queue This field indicates the current number of packets in the Rx Queue. */
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_PRXQ(x)      (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_DBG_PRXQ_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_DBG_PRXQ_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_RXQX_DBG */
#define ENET_MTL_QUEUE_MTL_RXQX_DBG_COUNT        (2U)

/*! @name MTL_QUEUE_MTL_RXQX_CTRL - MTL RxQx Control register */
/*! @{ */

#define ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_WEGT_MASK (0x7U)
#define ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_WEGT_SHIFT (0U)
/*! RXQ_WEGT - Receive Queue Weight This field indicates the weight assigned to the Rx Queue 0. */
#define ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_WEGT(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_WEGT_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_WEGT_MASK)

#define ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_FRM_ARBIT_MASK (0x8U)
#define ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_FRM_ARBIT_SHIFT (3U)
/*! RXQ_FRM_ARBIT - Receive Queue Packet Arbitration When this bit is set, the The ethernet block
 *    drives the packet data to the ARI interface such that the entire packet data of
 *    currently-selected queue is transmitted before switching to other queue.
 */
#define ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_FRM_ARBIT(x) (((uint32_t)(((uint32_t)(x)) << ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_FRM_ARBIT_SHIFT)) & ENET_MTL_QUEUE_MTL_RXQX_CTRL_RXQ_FRM_ARBIT_MASK)
/*! @} */

/* The count of ENET_MTL_QUEUE_MTL_RXQX_CTRL */
#define ENET_MTL_QUEUE_MTL_RXQX_CTRL_COUNT       (2U)

/*! @name DMA_MODE - DMA mode register */
/*! @{ */

#define ENET_DMA_MODE_SWR_MASK                   (0x1U)
#define ENET_DMA_MODE_SWR_SHIFT                  (0U)
/*! SWR - Software Reset When this bit is set, the MAC and the OMA controller reset the logic and
 *    all internal registers of the OMA, MTL, and MAC.
 */
#define ENET_DMA_MODE_SWR(x)                     (((uint32_t)(((uint32_t)(x)) << ENET_DMA_MODE_SWR_SHIFT)) & ENET_DMA_MODE_SWR_MASK)

#define ENET_DMA_MODE_DA_MASK                    (0x2U)
#define ENET_DMA_MODE_DA_SHIFT                   (1U)
/*! DA - DMA Tx or Rx Arbitration Scheme This bit specifies the arbitration scheme between the
 *    Transmit and Receive paths of all channels: The Tx path has priority over the Rx path when the TXPR
 *    bit is set.
 */
#define ENET_DMA_MODE_DA(x)                      (((uint32_t)(((uint32_t)(x)) << ENET_DMA_MODE_DA_SHIFT)) & ENET_DMA_MODE_DA_MASK)

#define ENET_DMA_MODE_TAA_MASK                   (0x1CU)
#define ENET_DMA_MODE_TAA_SHIFT                  (2U)
/*! TAA - Transmit Arbitration Algorithm This field is used to select the arbitration algorithm for
 *    the Transmit side when multiple Tx DMAs are selected.
 */
#define ENET_DMA_MODE_TAA(x)                     (((uint32_t)(((uint32_t)(x)) << ENET_DMA_MODE_TAA_SHIFT)) & ENET_DMA_MODE_TAA_MASK)

#define ENET_DMA_MODE_TXPR_MASK                  (0x800U)
#define ENET_DMA_MODE_TXPR_SHIFT                 (11U)
/*! TXPR - Transmit Priority When set, this bit indicates that the Tx DMA has higher priority than
 *    the Rx DMA during arbitration for the system-side bus.
 */
#define ENET_DMA_MODE_TXPR(x)                    (((uint32_t)(((uint32_t)(x)) << ENET_DMA_MODE_TXPR_SHIFT)) & ENET_DMA_MODE_TXPR_MASK)

#define ENET_DMA_MODE_PR_MASK                    (0x7000U)
#define ENET_DMA_MODE_PR_SHIFT                   (12U)
/*! PR - Priority Ratio These bits control the priority ratio in weighted round-robin arbitration between the Rx DMA and Tx DMA. */
#define ENET_DMA_MODE_PR(x)                      (((uint32_t)(((uint32_t)(x)) << ENET_DMA_MODE_PR_SHIFT)) & ENET_DMA_MODE_PR_MASK)
/*! @} */

/*! @name DMA_SYSBUS_MODE - DMA System Bus mode */
/*! @{ */

#define ENET_DMA_SYSBUS_MODE_FB_MASK             (0x1U)
#define ENET_DMA_SYSBUS_MODE_FB_SHIFT            (0U)
/*! FB - Fixed Burst Length When this bit is set to 1, the AHB master will initiate burst transfers
 *    of specified length (INCRx or SINGLE).
 */
#define ENET_DMA_SYSBUS_MODE_FB(x)               (((uint32_t)(((uint32_t)(x)) << ENET_DMA_SYSBUS_MODE_FB_SHIFT)) & ENET_DMA_SYSBUS_MODE_FB_MASK)

#define ENET_DMA_SYSBUS_MODE_AAL_MASK            (0x1000U)
#define ENET_DMA_SYSBUS_MODE_AAL_SHIFT           (12U)
/*! AAL - Address-Aligned Beats When this bit is set to 1, the AHB master performs address-aligned
 *    burst transfers on Read and Write channels.
 */
#define ENET_DMA_SYSBUS_MODE_AAL(x)              (((uint32_t)(((uint32_t)(x)) << ENET_DMA_SYSBUS_MODE_AAL_SHIFT)) & ENET_DMA_SYSBUS_MODE_AAL_MASK)

#define ENET_DMA_SYSBUS_MODE_MB_MASK             (0x4000U)
#define ENET_DMA_SYSBUS_MODE_MB_SHIFT            (14U)
/*! MB - Mixed Burst When this bit is set high and the FB bit is low, the AHB master performs
 *    undefined bursts transfers (INCR) for burst length of 16 or more.
 */
#define ENET_DMA_SYSBUS_MODE_MB(x)               (((uint32_t)(((uint32_t)(x)) << ENET_DMA_SYSBUS_MODE_MB_SHIFT)) & ENET_DMA_SYSBUS_MODE_MB_MASK)

#define ENET_DMA_SYSBUS_MODE_RB_MASK             (0x8000U)
#define ENET_DMA_SYSBUS_MODE_RB_SHIFT            (15U)
/*! RB - Rebuild INCRx Burst When this bit is set high and the AHB master gets SPLIT, RETRY, or
 *    EarlyBurst Termination (EBT) response, the AHB master interface rebuilds the pending beats of any
 *    initiated burst transfer with INCRx and SINGLEtransfers.
 */
#define ENET_DMA_SYSBUS_MODE_RB(x)               (((uint32_t)(((uint32_t)(x)) << ENET_DMA_SYSBUS_MODE_RB_SHIFT)) & ENET_DMA_SYSBUS_MODE_RB_MASK)
/*! @} */

/*! @name DMA_INTR_STAT - DMA Interrupt status */
/*! @{ */

#define ENET_DMA_INTR_STAT_DC0IS_MASK            (0x1U)
#define ENET_DMA_INTR_STAT_DC0IS_SHIFT           (0U)
/*! DC0IS - DMA Channel 0 Interrupt Status This bit indicates an interrupt event in DMA Channel 0. */
#define ENET_DMA_INTR_STAT_DC0IS(x)              (((uint32_t)(((uint32_t)(x)) << ENET_DMA_INTR_STAT_DC0IS_SHIFT)) & ENET_DMA_INTR_STAT_DC0IS_MASK)

#define ENET_DMA_INTR_STAT_DC1IS_MASK            (0x2U)
#define ENET_DMA_INTR_STAT_DC1IS_SHIFT           (1U)
/*! DC1IS - DMA Channel 1 Interrupt Status This bit indicates an interrupt event in DMA Channel 1. */
#define ENET_DMA_INTR_STAT_DC1IS(x)              (((uint32_t)(((uint32_t)(x)) << ENET_DMA_INTR_STAT_DC1IS_SHIFT)) & ENET_DMA_INTR_STAT_DC1IS_MASK)

#define ENET_DMA_INTR_STAT_MTLIS_MASK            (0x10000U)
#define ENET_DMA_INTR_STAT_MTLIS_SHIFT           (16U)
/*! MTLIS - MTL Interrupt Status This bit indicates an interrupt event in the MTL. */
#define ENET_DMA_INTR_STAT_MTLIS(x)              (((uint32_t)(((uint32_t)(x)) << ENET_DMA_INTR_STAT_MTLIS_SHIFT)) & ENET_DMA_INTR_STAT_MTLIS_MASK)

#define ENET_DMA_INTR_STAT_MACIS_MASK            (0x20000U)
#define ENET_DMA_INTR_STAT_MACIS_SHIFT           (17U)
/*! MACIS - MAC Interrupt Status This bit indicates an interrupt event in the MAC. */
#define ENET_DMA_INTR_STAT_MACIS(x)              (((uint32_t)(((uint32_t)(x)) << ENET_DMA_INTR_STAT_MACIS_SHIFT)) & ENET_DMA_INTR_STAT_MACIS_MASK)
/*! @} */

/*! @name DMA_DBG_STAT - DMA Debug Status */
/*! @{ */

#define ENET_DMA_DBG_STAT_AHSTS_MASK             (0x1U)
#define ENET_DMA_DBG_STAT_AHSTS_SHIFT            (0U)
/*! AHSTS - AHB Master Status When high, this bit indicates that the AHB master FSMs are in the non-idle state. */
#define ENET_DMA_DBG_STAT_AHSTS(x)               (((uint32_t)(((uint32_t)(x)) << ENET_DMA_DBG_STAT_AHSTS_SHIFT)) & ENET_DMA_DBG_STAT_AHSTS_MASK)

#define ENET_DMA_DBG_STAT_RPS0_MASK              (0xF00U)
#define ENET_DMA_DBG_STAT_RPS0_SHIFT             (8U)
/*! RPS0 - DMA Channel 0 Receive Process State This field indicates the Rx DMA FSM state for Channel
 *    0: 0x0: Stopped (Reset or Stop Receive Command issued) 0x1: Running (Fetching Rx Transfer )
 *    0x2: Reserved 0x3: Running (Waiting for Rx packet) 0x4: Suspended (Rx Unavailable) 0x5: Running
 *    (Closing the Rx) 0x6: Timestamp write state 0x7: Running (Transferring the received packet
 *    data from the Rx buffer to the system memory) This field does not generate an interrupt.
 */
#define ENET_DMA_DBG_STAT_RPS0(x)                (((uint32_t)(((uint32_t)(x)) << ENET_DMA_DBG_STAT_RPS0_SHIFT)) & ENET_DMA_DBG_STAT_RPS0_MASK)

#define ENET_DMA_DBG_STAT_TPS0_MASK              (0xF000U)
#define ENET_DMA_DBG_STAT_TPS0_SHIFT             (12U)
/*! TPS0 - DMA Channel 0 Transmit Process State This field indicates the Tx DMA FSM state for
 *    Channel 0: 000: Stopped (Reset or Stop Transmit Command issued) 0x1: Running (Fetching Tx Transfer)
 *    0x2: Running (Waiting for status) 0x3: Running (Reading Data from system memory buffer and
 *    queuing it to the Tx buffer (Tx FIFO)) 0x4: Timestamp write state 0x5: Reserved for future use
 *    0x6: Suspended (Tx Unavailable or Tx Buffer Underflow) 0x7: Running (Closing Tx ) This field
 *    does not generate an interrupt.
 */
#define ENET_DMA_DBG_STAT_TPS0(x)                (((uint32_t)(((uint32_t)(x)) << ENET_DMA_DBG_STAT_TPS0_SHIFT)) & ENET_DMA_DBG_STAT_TPS0_MASK)

#define ENET_DMA_DBG_STAT_RPS1_MASK              (0xF0000U)
#define ENET_DMA_DBG_STAT_RPS1_SHIFT             (16U)
/*! RPS1 - DMA Channel 1 Receive Process State This field indicates the Rx DMA FSM state for Channel 1. */
#define ENET_DMA_DBG_STAT_RPS1(x)                (((uint32_t)(((uint32_t)(x)) << ENET_DMA_DBG_STAT_RPS1_SHIFT)) & ENET_DMA_DBG_STAT_RPS1_MASK)

#define ENET_DMA_DBG_STAT_TPS1_MASK              (0xF00000U)
#define ENET_DMA_DBG_STAT_TPS1_SHIFT             (20U)
/*! TPS1 - DMA Channel 1 Transmit Process State This field indicates the Tx DMA FSM state for Channel 1. */
#define ENET_DMA_DBG_STAT_TPS1(x)                (((uint32_t)(((uint32_t)(x)) << ENET_DMA_DBG_STAT_TPS1_SHIFT)) & ENET_DMA_DBG_STAT_TPS1_MASK)
/*! @} */

/*! @name DMA_CH_DMA_CHX_CTRL - DMA Channelx Control */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_CTRL_PBLx8_MASK      (0x10000U)
#define ENET_DMA_CH_DMA_CHX_CTRL_PBLx8_SHIFT     (16U)
/*! PBLx8 - 8xPBL mode When this bit is set, the PBL value programmed in Bits[21:16] in DMA Channel
 *    Transmit Control Table 780 is multiplied eight times.
 */
#define ENET_DMA_CH_DMA_CHX_CTRL_PBLx8(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_CTRL_PBLx8_SHIFT)) & ENET_DMA_CH_DMA_CHX_CTRL_PBLx8_MASK)

#define ENET_DMA_CH_DMA_CHX_CTRL_DSL_MASK        (0x1C0000U)
#define ENET_DMA_CH_DMA_CHX_CTRL_DSL_SHIFT       (18U)
/*! DSL - Skip Length This bit specifies the Word, Dword, or Lword number (depending on the 32- bit,
 *    64-bit, or 128-bit bus) to skip between two unchained s.
 */
#define ENET_DMA_CH_DMA_CHX_CTRL_DSL(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_CTRL_DSL_SHIFT)) & ENET_DMA_CH_DMA_CHX_CTRL_DSL_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_CTRL */
#define ENET_DMA_CH_DMA_CHX_CTRL_COUNT           (2U)

/*! @name DMA_CH_DMA_CHX_TX_CTRL - DMA Channelx Transmit Control */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_TX_CTRL_ST_MASK      (0x1U)
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_ST_SHIFT     (0U)
/*! ST - Start or Stop Transmission Command When this bit is set, transmission is placed in the Running state. */
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_ST(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TX_CTRL_ST_SHIFT)) & ENET_DMA_CH_DMA_CHX_TX_CTRL_ST_MASK)

#define ENET_DMA_CH_DMA_CHX_TX_CTRL_TCW_MASK     (0xEU)
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_TCW_SHIFT    (1U)
/*! TCW - Transmit Channel Weight This field indicates the weight assigned to the corresponding Transmit channel. */
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_TCW(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TX_CTRL_TCW_SHIFT)) & ENET_DMA_CH_DMA_CHX_TX_CTRL_TCW_MASK)

#define ENET_DMA_CH_DMA_CHX_TX_CTRL_OSF_MASK     (0x10U)
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_OSF_SHIFT    (4U)
/*! OSF - Operate on Second Frame When this bit is set, it instructs the DMA to process the second
 *    packet of the Transmit data even before the status for the first packet is obtained.
 */
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_OSF(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TX_CTRL_OSF_SHIFT)) & ENET_DMA_CH_DMA_CHX_TX_CTRL_OSF_MASK)

#define ENET_DMA_CH_DMA_CHX_TX_CTRL_TxPBL_MASK   (0x3F0000U)
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_TxPBL_SHIFT  (16U)
/*! TxPBL - Transmit Programmable Burst Length These bits indicate the maximum number of beats to be
 *    transferred in one DMA data transfer.
 */
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_TxPBL(x)     (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TX_CTRL_TxPBL_SHIFT)) & ENET_DMA_CH_DMA_CHX_TX_CTRL_TxPBL_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_TX_CTRL */
#define ENET_DMA_CH_DMA_CHX_TX_CTRL_COUNT        (2U)

/*! @name DMA_CH_DMA_CHX_RX_CTRL - DMA Channelx Receive Control */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_RX_CTRL_SR_MASK      (0x1U)
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_SR_SHIFT     (0U)
/*! SR - Start or Stop Receive When this bit is set, the DMA tries to acquire the from the receive
 *    list and processes the incoming packets.
 */
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_SR(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_CTRL_SR_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_CTRL_SR_MASK)

#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ_MASK    (0x7FF8U)
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ_SHIFT   (3U)
/*! RBSZ - Receive Buffer size This field indicates the size of the Rx buffers specified in bytes. */
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ(x)      (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_CTRL_RBSZ_MASK)

#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RxPBL_MASK   (0x3F0000U)
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RxPBL_SHIFT  (16U)
/*! RxPBL - Receive Programmable Burst Length These bits indicate the maximum number of beats to be
 *    transferred in one DMA data transfer.
 */
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RxPBL(x)     (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_CTRL_RxPBL_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_CTRL_RxPBL_MASK)

#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RPF_MASK     (0x80000000U)
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RPF_SHIFT    (31U)
/*! RPF - DMA Rx Channel 0 Packet Flush When this bit is set to 1, the DMA will automatically flush
 *    the packet from the Rx Queues destined to DMA Rx Channel 0 when the DMA Rx Channel 0 is
 *    stopped after a system bus error has occurred.
 */
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_RPF(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_CTRL_RPF_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_CTRL_RPF_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_RX_CTRL */
#define ENET_DMA_CH_DMA_CHX_RX_CTRL_COUNT        (2U)

/*! @name DMA_CH_DMA_CHX_TXDESC_LIST_ADDR -  */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_TXDESC_LIST_ADDR_STL_MASK (0xFFFFFFFCU)
#define ENET_DMA_CH_DMA_CHX_TXDESC_LIST_ADDR_STL_SHIFT (2U)
/*! STL - Start of transmit list This field contains the base address of the first in the Transmit list. */
#define ENET_DMA_CH_DMA_CHX_TXDESC_LIST_ADDR_STL(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TXDESC_LIST_ADDR_STL_SHIFT)) & ENET_DMA_CH_DMA_CHX_TXDESC_LIST_ADDR_STL_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_TXDESC_LIST_ADDR */
#define ENET_DMA_CH_DMA_CHX_TXDESC_LIST_ADDR_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_RXDESC_LIST_ADDR -  */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_RXDESC_LIST_ADDR_SRL_MASK (0xFFFFFFFCU)
#define ENET_DMA_CH_DMA_CHX_RXDESC_LIST_ADDR_SRL_SHIFT (2U)
/*! SRL - Start of receive list This field contains the base address of the First in the Receive list. */
#define ENET_DMA_CH_DMA_CHX_RXDESC_LIST_ADDR_SRL(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RXDESC_LIST_ADDR_SRL_SHIFT)) & ENET_DMA_CH_DMA_CHX_RXDESC_LIST_ADDR_SRL_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_RXDESC_LIST_ADDR */
#define ENET_DMA_CH_DMA_CHX_RXDESC_LIST_ADDR_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_TXDESC_TAIL_PTR -  */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_TXDESC_TAIL_PTR_TDTP_MASK (0xFFFFFFFCU)
#define ENET_DMA_CH_DMA_CHX_TXDESC_TAIL_PTR_TDTP_SHIFT (2U)
/*! TDTP - Transmit Tail Pointer This field contains the tail pointer for the Tx ring. */
#define ENET_DMA_CH_DMA_CHX_TXDESC_TAIL_PTR_TDTP(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TXDESC_TAIL_PTR_TDTP_SHIFT)) & ENET_DMA_CH_DMA_CHX_TXDESC_TAIL_PTR_TDTP_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_TXDESC_TAIL_PTR */
#define ENET_DMA_CH_DMA_CHX_TXDESC_TAIL_PTR_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_RXDESC_TAIL_PTR -  */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_RXDESC_TAIL_PTR_RDTP_MASK (0xFFFFFFFCU)
#define ENET_DMA_CH_DMA_CHX_RXDESC_TAIL_PTR_RDTP_SHIFT (2U)
/*! RDTP - Receive Tail Pointer This field contains the tail pointer for the Rx ring. */
#define ENET_DMA_CH_DMA_CHX_RXDESC_TAIL_PTR_RDTP(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RXDESC_TAIL_PTR_RDTP_SHIFT)) & ENET_DMA_CH_DMA_CHX_RXDESC_TAIL_PTR_RDTP_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_RXDESC_TAIL_PTR */
#define ENET_DMA_CH_DMA_CHX_RXDESC_TAIL_PTR_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_TXDESC_RING_LENGTH -  */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_TXDESC_RING_LENGTH_TDRL_MASK (0x3FFU)
#define ENET_DMA_CH_DMA_CHX_TXDESC_RING_LENGTH_TDRL_SHIFT (0U)
/*! TDRL - Transmit Ring Length This field sets the maximum number of Tx descriptors in the circular ring. */
#define ENET_DMA_CH_DMA_CHX_TXDESC_RING_LENGTH_TDRL(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_TXDESC_RING_LENGTH_TDRL_SHIFT)) & ENET_DMA_CH_DMA_CHX_TXDESC_RING_LENGTH_TDRL_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_TXDESC_RING_LENGTH */
#define ENET_DMA_CH_DMA_CHX_TXDESC_RING_LENGTH_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_RXDESC_RING_LENGTH - Channelx Rx descriptor Ring Length */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_RXDESC_RING_LENGTH_RDRL_MASK (0x3FFU)
#define ENET_DMA_CH_DMA_CHX_RXDESC_RING_LENGTH_RDRL_SHIFT (0U)
/*! RDRL - Receive Ring Length This register sets the maximum number of Rx descriptors in the circular ring. */
#define ENET_DMA_CH_DMA_CHX_RXDESC_RING_LENGTH_RDRL(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RXDESC_RING_LENGTH_RDRL_SHIFT)) & ENET_DMA_CH_DMA_CHX_RXDESC_RING_LENGTH_RDRL_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_RXDESC_RING_LENGTH */
#define ENET_DMA_CH_DMA_CHX_RXDESC_RING_LENGTH_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_INT_EN - Channelx Interrupt Enable */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_INT_EN_TIE_MASK      (0x1U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_TIE_SHIFT     (0U)
/*! TIE - Transmit interrupt enable When this bit is set with Normal Interrupt Summary Enable (bit
 *    16 in this register), Transmit Interrupt is enabled.
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_TIE(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_TIE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_TIE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_TSE_MASK      (0x2U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_TSE_SHIFT     (1U)
/*! TSE - Transmit stopped enable When this bit is set with Abnormal Interrupt Summary Enable (bit
 *    15 in this register), Transmission Stopped Interrupt is enabled.
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_TSE(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_TSE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_TSE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_TBUE_MASK     (0x4U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_TBUE_SHIFT    (2U)
/*! TBUE - Transmit buffer unavailable enable When this bit is set with Normal Interrupt Summary
 *    Enable (bit 16 in this register), Transmit Buffer Unavailable Interrupt is enabled.
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_TBUE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_TBUE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_TBUE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_RIE_MASK      (0x40U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_RIE_SHIFT     (6U)
/*! RIE - Receive interrupt enable When this bit is set with Normal Interrupt Summary Enable (bit 16
 *    in this register), Receive Interrupt is enabled.
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_RIE(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_RIE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_RIE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_RBUE_MASK     (0x80U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_RBUE_SHIFT    (7U)
/*! RBUE - Receive buffer unavailable enable When this bit is set with Abnormal Interrupt Summary
 *    Enable (bit 15 in this register), Receive Buffer Unavailable Interrupt is enabled.
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_RBUE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_RBUE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_RBUE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_RSE_MASK      (0x100U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_RSE_SHIFT     (8U)
/*! RSE - Received stopped enable When this bit is set with Abnormal Interrupt Summary Enable (bit
 *    15 in this register), Receive Stopped Interrupt is enabled.
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_RSE(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_RSE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_RSE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_RWTE_MASK     (0x200U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_RWTE_SHIFT    (9U)
/*! RWTE - Receive watchdog timeout enable When this bit is set with Abnormal Interrupt Summary
 *    Enable (bit 15 in this register), the Receive Watchdog Timeout Interrupt is enabled.
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_RWTE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_RWTE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_RWTE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_ETIE_MASK     (0x400U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_ETIE_SHIFT    (10U)
/*! ETIE - Early transmit interrupt enable When this bit is set with an Abnormal Interrupt Summary
 *    Enable (bit 15 in this register), Early Transmit Interrupt is enabled.
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_ETIE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_ETIE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_ETIE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_ERIE_MASK     (0x800U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_ERIE_SHIFT    (11U)
/*! ERIE - Early receive interrupt enable When this bit is set with Normal Interrupt Summary Enable
 *    (bit 16 in this register), Early Receive Interrupt is enabled.
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_ERIE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_ERIE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_ERIE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_FBEE_MASK     (0x1000U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_FBEE_SHIFT    (12U)
/*! FBEE - Fatal bus error enable When this bit is set with Abnormal Interrupt Summary Enable (bit
 *    15 in this register), the Fatal Bus Error Interrupt is enabled.
 */
#define ENET_DMA_CH_DMA_CHX_INT_EN_FBEE(x)       (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_FBEE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_FBEE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_AIE_MASK      (0x4000U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_AIE_SHIFT     (14U)
/*! AIE - Abnormal interrupt summary enable When this bit is set, an Abnormal Interrupt summary is enabled. */
#define ENET_DMA_CH_DMA_CHX_INT_EN_AIE(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_AIE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_AIE_MASK)

#define ENET_DMA_CH_DMA_CHX_INT_EN_NIE_MASK      (0x8000U)
#define ENET_DMA_CH_DMA_CHX_INT_EN_NIE_SHIFT     (15U)
/*! NIE - Normal interrupt summary enable When this bit is set, a normal interrupt is enabled. */
#define ENET_DMA_CH_DMA_CHX_INT_EN_NIE(x)        (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_INT_EN_NIE_SHIFT)) & ENET_DMA_CH_DMA_CHX_INT_EN_NIE_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_INT_EN */
#define ENET_DMA_CH_DMA_CHX_INT_EN_COUNT         (2U)

/*! @name DMA_CH_DMA_CHX_RX_INT_WDTIMER - Receive Interrupt Watchdog Timer */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RIWT_MASK (0xFFU)
#define ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RIWT_SHIFT (0U)
/*! RIWT - Receive Interrupt Watchdog Timer Count Indicates the number of system clock cycles
 *    multiplied by 256 for which the watchdog timer is set.
 */
#define ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RIWT(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RIWT_SHIFT)) & ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_RIWT_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER */
#define ENET_DMA_CH_DMA_CHX_RX_INT_WDTIMER_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT - Slot Function Control and Status */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ESC_MASK (0x1U)
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ESC_SHIFT (0U)
/*! ESC - Enable Slot Comparison When set, this bit enables the checking of the slot numbers
 *    programmed in the Tx descriptor with the current reference given in the RSN field.
 */
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ESC(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ESC_SHIFT)) & ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ESC_MASK)

#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ASC_MASK (0x2U)
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ASC_SHIFT (1U)
/*! ASC - Advance Slot Check When set, this bit enables the D MA to fetch the data from the buffer
 *    when the slot number (SLOTNUM) programmed in the Tx descriptor is equal to the reference slot
 *    number given in the RSN field or, ahead of the reference slot number by up to two slots This
 *    bit is applicable only when the ESC bit is set.
 */
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ASC(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ASC_SHIFT)) & ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_ASC_MASK)

#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_RSN_MASK (0xF0000U)
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_RSN_SHIFT (16U)
/*! RSN - Reference Slot Number This field gives the current value of the reference slot number in the DMA. */
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_RSN(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_RSN_SHIFT)) & ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_RSN_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT */
#define ENET_DMA_CH_DMA_CHX_SLOT_FUNC_CTRL_STAT_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_CUR_HST_TXDESC - Channelx Current Host Transmit descriptor */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXDESC_HTD_MASK (0xFFFFFFFFU)
#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXDESC_HTD_SHIFT (0U)
/*! HTD - Host Transmit descriptor Address Pointer Cleared on Reset. */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXDESC_HTD(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_CUR_HST_TXDESC_HTD_SHIFT)) & ENET_DMA_CH_DMA_CHX_CUR_HST_TXDESC_HTD_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_CUR_HST_TXDESC */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXDESC_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_CUR_HST_RXDESC -  */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXDESC_HRD_MASK (0xFFFFFFFFU)
#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXDESC_HRD_SHIFT (0U)
/*! HRD - Host Receive descriptor Address Pointer Cleared on Reset. */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXDESC_HRD(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_CUR_HST_RXDESC_HRD_SHIFT)) & ENET_DMA_CH_DMA_CHX_CUR_HST_RXDESC_HRD_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_CUR_HST_RXDESC */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXDESC_COUNT (2U)

/*! @name DMA_CH_DMA_CHX_CUR_HST_TXBUF -  */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXBUF_HTB_MASK (0xFFFFFFFFU)
#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXBUF_HTB_SHIFT (0U)
/*! HTB - Host Transmit Buffer Address Pointer Cleared on Reset. */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXBUF_HTB(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_CUR_HST_TXBUF_HTB_SHIFT)) & ENET_DMA_CH_DMA_CHX_CUR_HST_TXBUF_HTB_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_CUR_HST_TXBUF */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_TXBUF_COUNT  (2U)

/*! @name DMA_CH_DMA_CHX_CUR_HST_RXBUF - Channelx Current Application Receive Buffer Address */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXBUF_HRB_MASK (0xFFFFFFFFU)
#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXBUF_HRB_SHIFT (0U)
/*! HRB - Host Receive Buffer Address Pointer Cleared on Reset. */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXBUF_HRB(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_CUR_HST_RXBUF_HRB_SHIFT)) & ENET_DMA_CH_DMA_CHX_CUR_HST_RXBUF_HRB_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_CUR_HST_RXBUF */
#define ENET_DMA_CH_DMA_CHX_CUR_HST_RXBUF_COUNT  (2U)

/*! @name DMA_CH_DMA_CHX_STAT - Channelx DMA status register */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_STAT_TI_MASK         (0x1U)
#define ENET_DMA_CH_DMA_CHX_STAT_TI_SHIFT        (0U)
/*! TI - Transmit Interrupt This bit indicates that the packet transmission is complete. */
#define ENET_DMA_CH_DMA_CHX_STAT_TI(x)           (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_TI_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_TI_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_TPS_MASK        (0x2U)
#define ENET_DMA_CH_DMA_CHX_STAT_TPS_SHIFT       (1U)
/*! TPS - Transmit Process Stopped This bit is set when the transmission is stopped. */
#define ENET_DMA_CH_DMA_CHX_STAT_TPS(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_TPS_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_TPS_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_TBU_MASK        (0x4U)
#define ENET_DMA_CH_DMA_CHX_STAT_TBU_SHIFT       (2U)
/*! TBU - Transmit Buffer Unavailable This bit indicates that the application owns the next
 *    descriptor in the transmit list, and the DMA cannot acquire it.
 */
#define ENET_DMA_CH_DMA_CHX_STAT_TBU(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_TBU_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_TBU_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_RI_MASK         (0x40U)
#define ENET_DMA_CH_DMA_CHX_STAT_RI_SHIFT        (6U)
/*! RI - Receive Interrupt This bit indicates that the packet reception is complete. */
#define ENET_DMA_CH_DMA_CHX_STAT_RI(x)           (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_RI_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_RI_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_RBU_MASK        (0x80U)
#define ENET_DMA_CH_DMA_CHX_STAT_RBU_SHIFT       (7U)
/*! RBU - Receive Buffer Unavailable This bit indicates that the application owns the next in the
 *    receive list, and the DMA cannot acquire it.
 */
#define ENET_DMA_CH_DMA_CHX_STAT_RBU(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_RBU_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_RBU_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_RPS_MASK        (0x100U)
#define ENET_DMA_CH_DMA_CHX_STAT_RPS_SHIFT       (8U)
/*! RPS - Receive Process Stopped This bit is asserted when the Rx process enters the Stopped state. */
#define ENET_DMA_CH_DMA_CHX_STAT_RPS(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_RPS_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_RPS_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_RWT_MASK        (0x200U)
#define ENET_DMA_CH_DMA_CHX_STAT_RWT_SHIFT       (9U)
/*! RWT - Receive Watchdog time out This bit is asserted when a packet with length greater than
 *    2,048 bytes (10,240 bytes when Jumbo Packet mode is enabled) is received.
 */
#define ENET_DMA_CH_DMA_CHX_STAT_RWT(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_RWT_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_RWT_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_ETI_MASK        (0x400U)
#define ENET_DMA_CH_DMA_CHX_STAT_ETI_SHIFT       (10U)
/*! ETI - Early Transmit Interrupt This bit indicates that the packet to be transmitted is fully transferred to the MTL Tx FIFO. */
#define ENET_DMA_CH_DMA_CHX_STAT_ETI(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_ETI_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_ETI_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_ERI_MASK        (0x800U)
#define ENET_DMA_CH_DMA_CHX_STAT_ERI_SHIFT       (11U)
/*! ERI - Early Receive Interrupt This bit indicates that the DMA filled the first data buffer of the packet. */
#define ENET_DMA_CH_DMA_CHX_STAT_ERI(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_ERI_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_ERI_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_FBE_MASK        (0x1000U)
#define ENET_DMA_CH_DMA_CHX_STAT_FBE_SHIFT       (12U)
/*! FBE - Fatal Bus Error This bit indicates that a bus error occurred (as described in the EB field). */
#define ENET_DMA_CH_DMA_CHX_STAT_FBE(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_FBE_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_FBE_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_AIS_MASK        (0x4000U)
#define ENET_DMA_CH_DMA_CHX_STAT_AIS_SHIFT       (14U)
/*! AIS - Abnormal Interrupt Summary Abnormal Interrupt Summary bit value is the logical OR of the
 *    following when the corresponding interrupt bits are enabled in the DMA Channel Interrupt Enable
 *    register Table 778: Bit 1: Transmit Process Stopped Bit 7: Receive Buffer Unavailable Bit 8:
 *    Receive Process Stopped Bit 10: Ear1y Transmit Interrupt Bit 12: Fatal Bus Error Only unmasked
 *    bits affect the Abnormal Interrupt Summary bit.
 */
#define ENET_DMA_CH_DMA_CHX_STAT_AIS(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_AIS_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_AIS_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_NIS_MASK        (0x8000U)
#define ENET_DMA_CH_DMA_CHX_STAT_NIS_SHIFT       (15U)
/*! NIS - Normal Interrupt Summary Normal Interrupt Summary bit value is the logical OR of the
 *    following bits when the corresponding interrupt bits are enabled in the DMA Channel Interrupt
 *    Enable register Table 778: Bit 0: Transmit Interrupt Bit 2: Transmit Buffer Unavailable Bit 6:
 *    Receive Interrupt Bit 11: Early Receive Interrupt Only unmasked bits (interrupts for which
 *    interrupt enable is set in DMA Channel Interrupt Enable register Table 778) affect the Normal
 *    Interrupt Summary bit.
 */
#define ENET_DMA_CH_DMA_CHX_STAT_NIS(x)          (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_NIS_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_NIS_MASK)

#define ENET_DMA_CH_DMA_CHX_STAT_EB_MASK         (0x70000U)
#define ENET_DMA_CH_DMA_CHX_STAT_EB_SHIFT        (16U)
/*! EB - DMA Error Bits This field indicates the type of error that caused a Bus Error. */
#define ENET_DMA_CH_DMA_CHX_STAT_EB(x)           (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_STAT_EB_SHIFT)) & ENET_DMA_CH_DMA_CHX_STAT_EB_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_STAT */
#define ENET_DMA_CH_DMA_CHX_STAT_COUNT           (2U)

/*! @name DMA_CH_DMA_CHX_MISS_FRAME_CNT - Channelx missed frame count. */
/*! @{ */

#define ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFC_MASK (0x7FFU)
#define ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFC_SHIFT (0U)
/*! MFC - Dropped packet counters. */
#define ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFC(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFC_SHIFT)) & ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFC_MASK)

#define ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFCO_MASK (0x8000U)
#define ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFCO_SHIFT (15U)
/*! MFCO - Overflow status of the MFC counter. */
#define ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFCO(x) (((uint32_t)(((uint32_t)(x)) << ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFCO_SHIFT)) & ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_MFCO_MASK)
/*! @} */

/* The count of ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT */
#define ENET_DMA_CH_DMA_CHX_MISS_FRAME_CNT_COUNT (2U)


/*!
 * @}
 */ /* end of group ENET_Register_Masks */


/*!
 * @}
 */ /* end of group ENET_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_ENET_H_ */

