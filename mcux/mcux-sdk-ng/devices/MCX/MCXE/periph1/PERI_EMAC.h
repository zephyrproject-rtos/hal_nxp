/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for EMAC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_EMAC.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for EMAC
 *
 * CMSIS Peripheral Access Layer for EMAC
 */

#if !defined(PERI_EMAC_H_)
#define PERI_EMAC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
   -- EMAC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EMAC_Peripheral_Access_Layer EMAC Peripheral Access Layer
 * @{
 */

/** EMAC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MAC_CONFIGURATION;                 /**< MAC Configuration, offset: 0x0 */
  __IO uint32_t MAC_EXT_CONFIGURATION;             /**< MAC Extended Configuration, offset: 0x4 */
  __IO uint32_t MAC_PACKET_FILTER;                 /**< MAC Packet Filter, offset: 0x8 */
  __IO uint32_t MAC_WATCHDOG_TIMEOUT;              /**< MAC Watchdog Timeout, offset: 0xC */
  __IO uint32_t MAC_HASH_TABLE_REG0;               /**< MAC Hash Table First 32 Bits, offset: 0x10 */
  __IO uint32_t MAC_HASH_TABLE_REG1;               /**< MAC Hash Table Second 32 Bits, offset: 0x14 */
       uint8_t RESERVED_0[56];
  union {                                          /* offset: 0x50 */
    __IO uint32_t MAC_VLAN_TAG_CTRL;                 /**< MAC VLAN Tag Control, offset: 0x50 */
    __IO uint32_t MAC_VLAN_TAG;                      /**< MAC VLAN Tag, offset: 0x50 */
  };
  union {                                          /* offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_DATA;                 /**< MAC VLAN Tag Data, offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER0;              /**< MAC VLAN Tag Filter 0, offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER1;              /**< MAC VLAN Tag Filter 1, offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER2;              /**< MAC VLAN Tag Filter 2, offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER3;              /**< MAC VLAN Tag Filter 3, offset: 0x54 */
  };
  __IO uint32_t MAC_VLAN_HASH_TABLE;               /**< MAC VLAN Hash Table, offset: 0x58 */
       uint8_t RESERVED_1[4];
  union {                                          /* offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL0;                    /**< MAC VLAN Inclusion 0, offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL1;                    /**< MAC VLAN Inclusion 1, offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL2;                    /**< MAC VLAN Inclusion 2, offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL3;                    /**< MAC VLAN Inclusion 3, offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL4;                    /**< MAC VLAN Inclusion 4, offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL5;                    /**< MAC VLAN Inclusion 5, offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL6;                    /**< MAC VLAN Inclusion 6, offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL7;                    /**< MAC VLAN Inclusion 7, offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL;                     /**< MAC VLAN Inclusion Or Replacement, offset: 0x60 */
  };
  __IO uint32_t MAC_INNER_VLAN_INCL;               /**< Inner VLAN Tag Inclusion Or Replacement, offset: 0x64 */
       uint8_t RESERVED_2[8];
  __IO uint32_t MAC_Q0_TX_FLOW_CTRL;               /**< MAC Q0 Tx Flow Control, offset: 0x70 */
       uint8_t RESERVED_3[28];
  __IO uint32_t MAC_RX_FLOW_CTRL;                  /**< MAC Receive Flow Control, offset: 0x90 */
  __IO uint32_t MAC_RXQ_CTRL4;                     /**< MAC RxQ Control 4, offset: 0x94 */
       uint8_t RESERVED_4[8];
  __IO uint32_t MAC_RXQ_CTRL0;                     /**< MAC RxQ Control 0, offset: 0xA0 */
  __IO uint32_t MAC_RXQ_CTRL1;                     /**< Receive Queue Control 1, offset: 0xA4 */
  __IO uint32_t MAC_RXQ_CTRL2;                     /**< MAC RxQ Control 2, offset: 0xA8 */
       uint8_t RESERVED_5[4];
  __I  uint32_t MAC_INTERRUPT_STATUS;              /**< MAC Interrupt Status, offset: 0xB0 */
  __IO uint32_t MAC_INTERRUPT_ENABLE;              /**< MAC Interrupt Enable, offset: 0xB4 */
  __I  uint32_t MAC_RX_TX_STATUS;                  /**< MAC Rx Transmit Status, offset: 0xB8 */
       uint8_t RESERVED_6[84];
  __I  uint32_t MAC_VERSION;                       /**< MAC Version, offset: 0x110 */
  __I  uint32_t MAC_DEBUG;                         /**< MAC Debug, offset: 0x114 */
       uint8_t RESERVED_7[4];
  __I  uint32_t MAC_HW_FEATURE0;                   /**< MAC Hardware Feature 0, offset: 0x11C */
  __I  uint32_t MAC_HW_FEATURE1;                   /**< MAC Hardware Feature 1, offset: 0x120 */
  __I  uint32_t MAC_HW_FEATURE2;                   /**< MAC Hardware Feature 2, offset: 0x124 */
  __I  uint32_t MAC_HW_FEATURE3;                   /**< MAC Hardware Feature 3, offset: 0x128 */
       uint8_t RESERVED_8[20];
  __I  uint32_t MAC_DPP_FSM_INTERRUPT_STATUS;      /**< MAC DPP FSM Interrupt Status, offset: 0x140 */
       uint8_t RESERVED_9[4];
  __IO uint32_t MAC_FSM_CONTROL;                   /**< MAC FSM Control, offset: 0x148 */
  __IO uint32_t MAC_FSM_ACT_TIMER;                 /**< MAC FSM ACT Timer, offset: 0x14C */
  __IO uint32_t SCS_REG1;                          /**< SCS_REG 1, offset: 0x150 */
       uint8_t RESERVED_10[172];
  __IO uint32_t MAC_MDIO_ADDRESS;                  /**< MAC MDIO Address, offset: 0x200 */
  __IO uint32_t MAC_MDIO_DATA;                     /**< MAC MDIO Data, offset: 0x204 */
       uint8_t RESERVED_11[40];
  __IO uint32_t MAC_CSR_SW_CTRL;                   /**< MAC CSR Software Control, offset: 0x230 */
  __IO uint32_t MAC_FPE_CTRL_STS;                  /**< MAC FPE Control STS, offset: 0x234 */
       uint8_t RESERVED_12[8];
  __I  uint32_t MAC_PRESN_TIME_NS;                 /**< MAC Presentation Time, offset: 0x240 */
  __IO uint32_t MAC_PRESN_TIME_UPDT;               /**< MAC Presentation Time Update, offset: 0x244 */
       uint8_t RESERVED_13[184];
  __IO uint32_t MAC_ADDRESS0_HIGH;                 /**< MAC Address 0 High, offset: 0x300 */
  __IO uint32_t MAC_ADDRESS0_LOW;                  /**< MAC Address 0 Low, offset: 0x304 */
  __IO uint32_t MAC_ADDRESS1_HIGH;                 /**< MAC Address 1 High, offset: 0x308 */
  __IO uint32_t MAC_ADDRESS1_LOW;                  /**< MAC Address 1 Low, offset: 0x30C */
  __IO uint32_t MAC_ADDRESS2_HIGH;                 /**< MAC Address 2 High, offset: 0x310 */
  __IO uint32_t MAC_ADDRESS2_LOW;                  /**< MAC Address 2 Low, offset: 0x314 */
       uint8_t RESERVED_14[1000];
  __IO uint32_t MMC_CONTROL;                       /**< MMC Control, offset: 0x700 */
  __I  uint32_t MMC_RX_INTERRUPT;                  /**< MMC Receive Interrupt, offset: 0x704 */
  __I  uint32_t MMC_TX_INTERRUPT;                  /**< MMC Transmit Interrupt, offset: 0x708 */
  __IO uint32_t MMC_RX_INTERRUPT_MASK;             /**< MMC Receive Interrupt Mask, offset: 0x70C */
  __IO uint32_t MMC_TX_INTERRUPT_MASK;             /**< MMC Transmit Interrupt Mask, offset: 0x710 */
  __I  uint32_t TX_OCTET_COUNT_GOOD_BAD;           /**< Transmit Octet Count Good Bad, offset: 0x714 */
  __I  uint32_t TX_PACKET_COUNT_GOOD_BAD;          /**< Transmit Packet Count Good Bad, offset: 0x718 */
  __I  uint32_t TX_BROADCAST_PACKETS_GOOD;         /**< Transmit Broadcast Packets Good, offset: 0x71C */
  __I  uint32_t TX_MULTICAST_PACKETS_GOOD;         /**< Transmit Multicast Packets Good, offset: 0x720 */
  __I  uint32_t TX_64OCTETS_PACKETS_GOOD_BAD;      /**< Transmit 64-Octet Packets Good Bad, offset: 0x724 */
  __I  uint32_t TX_65TO127OCTETS_PACKETS_GOOD_BAD; /**< Transmit 65 To 127 Octet Packets Good Bad, offset: 0x728 */
  __I  uint32_t TX_128TO255OCTETS_PACKETS_GOOD_BAD; /**< Transmit 128 To 255 Octet Packets Good Bad, offset: 0x72C */
  __I  uint32_t TX_256TO511OCTETS_PACKETS_GOOD_BAD; /**< Transmit 256 To 511 Octet Packets Good Bad, offset: 0x730 */
  __I  uint32_t TX_512TO1023OCTETS_PACKETS_GOOD_BAD; /**< Transmit 512 To 1023 Octet Packets Good Bad, offset: 0x734 */
  __I  uint32_t TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD; /**< Transmit 1024 To Max Octet Packets Good Bad, offset: 0x738 */
  __I  uint32_t TX_UNICAST_PACKETS_GOOD_BAD;       /**< Transmit Unicast Packets Good Bad, offset: 0x73C */
  __I  uint32_t TX_MULTICAST_PACKETS_GOOD_BAD;     /**< Transmit Multicast Packets Good Bad, offset: 0x740 */
  __I  uint32_t TX_BROADCAST_PACKETS_GOOD_BAD;     /**< Transmit Broadcast Packets Good Bad, offset: 0x744 */
  __I  uint32_t TX_UNDERFLOW_ERROR_PACKETS;        /**< Transmit Underflow Error Packets, offset: 0x748 */
  __I  uint32_t TX_SINGLE_COLLISION_GOOD_PACKETS;  /**< Transmit Single Collision Good Packets, offset: 0x74C */
  __I  uint32_t TX_MULTIPLE_COLLISION_GOOD_PACKETS; /**< Transmit Multiple Collision Good Packets, offset: 0x750 */
  __I  uint32_t TX_DEFERRED_PACKETS;               /**< Transmit Deferred Packets, offset: 0x754 */
  __I  uint32_t TX_LATE_COLLISION_PACKETS;         /**< Transmit Late Collision Packets, offset: 0x758 */
  __I  uint32_t TX_EXCESSIVE_COLLISION_PACKETS;    /**< Transmit Excessive Collision Packets, offset: 0x75C */
  __I  uint32_t TX_CARRIER_ERROR_PACKETS;          /**< Transmit Carrier Error Packets, offset: 0x760 */
  __I  uint32_t TX_OCTET_COUNT_GOOD;               /**< Transmit Octet Count Good, offset: 0x764 */
  __I  uint32_t TX_PACKET_COUNT_GOOD;              /**< Transmit Packet Count Good, offset: 0x768 */
  __I  uint32_t TX_EXCESSIVE_DEFERRAL_ERROR;       /**< Transmit Excessive Deferral Error, offset: 0x76C */
  __I  uint32_t TX_PAUSE_PACKETS;                  /**< Transmit Pause Packets, offset: 0x770 */
  __I  uint32_t TX_VLAN_PACKETS_GOOD;              /**< Transmit VLAN Packets Good, offset: 0x774 */
  __I  uint32_t TX_OSIZE_PACKETS_GOOD;             /**< Transmit O Size Packets Good, offset: 0x778 */
       uint8_t RESERVED_15[4];
  __I  uint32_t RX_PACKETS_COUNT_GOOD_BAD;         /**< Receive Packets Count Good Bad, offset: 0x780 */
  __I  uint32_t RX_OCTET_COUNT_GOOD_BAD;           /**< Receive Octet Count Good Bad, offset: 0x784 */
  __I  uint32_t RX_OCTET_COUNT_GOOD;               /**< Receive Octet Count Good, offset: 0x788 */
  __I  uint32_t RX_BROADCAST_PACKETS_GOOD;         /**< Receive Broadcast Packets Good, offset: 0x78C */
  __I  uint32_t RX_MULTICAST_PACKETS_GOOD;         /**< Receive Multicast Packets Good, offset: 0x790 */
  __I  uint32_t RX_CRC_ERROR_PACKETS;              /**< Receive CRC Error Packets, offset: 0x794 */
  __I  uint32_t RX_ALIGNMENT_ERROR_PACKETS;        /**< Receive Alignment Error Packets, offset: 0x798 */
  __I  uint32_t RX_RUNT_ERROR_PACKETS;             /**< Receive Runt Error Packets, offset: 0x79C */
  __I  uint32_t RX_JABBER_ERROR_PACKETS;           /**< Receive Jabber Error Packets, offset: 0x7A0 */
  __I  uint32_t RX_UNDERSIZE_PACKETS_GOOD;         /**< Receive Undersize Packets Good, offset: 0x7A4 */
  __I  uint32_t RX_OVERSIZE_PACKETS_GOOD;          /**< Receive Oversize Packets Good, offset: 0x7A8 */
  __I  uint32_t RX_64OCTETS_PACKETS_GOOD_BAD;      /**< Receive 64 Octets Packets Good Bad, offset: 0x7AC */
  __I  uint32_t RX_65TO127OCTETS_PACKETS_GOOD_BAD; /**< Receive 65-127 Octets Packets Good Bad, offset: 0x7B0 */
  __I  uint32_t RX_128TO255OCTETS_PACKETS_GOOD_BAD; /**< Receive 128-255 Octets Packets Good Bad, offset: 0x7B4 */
  __I  uint32_t RX_256TO511OCTETS_PACKETS_GOOD_BAD; /**< Receive 256-511 Octets Packets Good Bad, offset: 0x7B8 */
  __I  uint32_t RX_512TO1023OCTETS_PACKETS_GOOD_BAD; /**< Receive 512-1023 Octets Packets Good Bad, offset: 0x7BC */
  __I  uint32_t RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD; /**< Receive 1024 To Max Octets Good Bad, offset: 0x7C0 */
  __I  uint32_t RX_UNICAST_PACKETS_GOOD;           /**< Receive Unicast Packets Good, offset: 0x7C4 */
  __I  uint32_t RX_LENGTH_ERROR_PACKETS;           /**< Receive Length Error Packets, offset: 0x7C8 */
  __I  uint32_t RX_OUT_OF_RANGE_TYPE_PACKETS;      /**< Receive Out of Range Type Packet, offset: 0x7CC */
  __I  uint32_t RX_PAUSE_PACKETS;                  /**< Receive Pause Packets, offset: 0x7D0 */
  __I  uint32_t RX_FIFO_OVERFLOW_PACKETS;          /**< Receive FIFO Overflow Packets, offset: 0x7D4 */
  __I  uint32_t RX_VLAN_PACKETS_GOOD_BAD;          /**< Receive VLAN Packets Good Bad, offset: 0x7D8 */
  __I  uint32_t RX_WATCHDOG_ERROR_PACKETS;         /**< Receive Watchdog Error Packets, offset: 0x7DC */
  __I  uint32_t RX_RECEIVE_ERROR_PACKETS;          /**< Receive Receive Error Packets, offset: 0x7E0 */
  __I  uint32_t RX_CONTROL_PACKETS_GOOD;           /**< Receive Control Packets Good, offset: 0x7E4 */
       uint8_t RESERVED_16[184];
  __I  uint32_t MMC_FPE_TX_INTERRUPT;              /**< MMC Transmit FPE Fragment Counter Interrupt Status, offset: 0x8A0 */
  __IO uint32_t MMC_FPE_TX_INTERRUPT_MASK;         /**< MMC FPE Transmit Interrupt Mask, offset: 0x8A4 */
  __I  uint32_t MMC_TX_FPE_FRAGMENT_CNTR;          /**< Transmit FPE Fragment Counter, offset: 0x8A8 */
  __I  uint32_t MMC_TX_HOLD_REQ_CNTR;              /**< Transmit Hold Request Counter, offset: 0x8AC */
       uint8_t RESERVED_17[16];
  __I  uint32_t MMC_FPE_RX_INTERRUPT;              /**< MMC Receive Packet Assembly Error Counter Interrupt Status, offset: 0x8C0 */
  __IO uint32_t MMC_FPE_RX_INTERRUPT_MASK;         /**< MMC FPE Receive Interrupt Mask, offset: 0x8C4 */
  __I  uint32_t MMC_RX_PACKET_ASSEMBLY_ERR_CNTR;   /**< MMC Receive Packet Assembly Error Counter, offset: 0x8C8 */
  __I  uint32_t MMC_RX_PACKET_SMD_ERR_CNTR;        /**< MMC Receive Packet SMD Error Counter, offset: 0x8CC */
  __I  uint32_t MMC_RX_PACKET_ASSEMBLY_OK_CNTR;    /**< MMC Receive Packet Assembly OK Counter, offset: 0x8D0 */
  __I  uint32_t MMC_RX_FPE_FRAGMENT_CNTR;          /**< MMC Receive FPE Fragment Counter, offset: 0x8D4 */
       uint8_t RESERVED_18[40];
  __IO uint32_t MAC_L3_L4_CONTROL0;                /**< MAC Layer 3 Layer 4 Control 0, offset: 0x900 */
  __IO uint32_t MAC_LAYER4_ADDRESS0;               /**< MAC Layer 4 Address 0, offset: 0x904 */
       uint8_t RESERVED_19[8];
  __IO uint32_t MAC_LAYER3_ADDR0_REG0;             /**< MAC Layer 3 Address 0 Reg 0, offset: 0x910 */
  __IO uint32_t MAC_LAYER3_ADDR1_REG0;             /**< MAC Layer 3 Address 1 Reg 0, offset: 0x914 */
  __IO uint32_t MAC_LAYER3_ADDR2_REG0;             /**< MAC Layer 3 Address 2 Reg 0, offset: 0x918 */
  __IO uint32_t MAC_LAYER3_ADDR3_REG0;             /**< MAC Layer 3 Address 3 Reg 0, offset: 0x91C */
       uint8_t RESERVED_20[16];
  __IO uint32_t MAC_L3_L4_CONTROL1;                /**< MAC L3 L4 Control 1, offset: 0x930 */
  __IO uint32_t MAC_LAYER4_ADDRESS1;               /**< MAC Layer 4 Address 1, offset: 0x934 */
       uint8_t RESERVED_21[8];
  __IO uint32_t MAC_LAYER3_ADDR0_REG1;             /**< MAC Layer 3 Address 0 Reg 1, offset: 0x940 */
  __IO uint32_t MAC_LAYER3_ADDR1_REG1;             /**< MAC Layer 3 Address 1 Reg 1, offset: 0x944 */
  __IO uint32_t MAC_LAYER3_ADDR2_REG1;             /**< MAC Layer 3 Address 2 Reg 1, offset: 0x948 */
  __IO uint32_t MAC_LAYER3_ADDR3_REG1;             /**< MAC Layer 3 Address 3 Reg 1, offset: 0x94C */
       uint8_t RESERVED_22[16];
  __IO uint32_t MAC_L3_L4_CONTROL2;                /**< MAC L3 L4 Control 2, offset: 0x960 */
  __IO uint32_t MAC_LAYER4_ADDRESS2;               /**< MAC Layer 4 Address 2, offset: 0x964 */
       uint8_t RESERVED_23[8];
  __IO uint32_t MAC_LAYER3_ADDR0_REG2;             /**< MAC Layer 3 Address 0 Reg 2, offset: 0x970 */
  __IO uint32_t MAC_LAYER3_ADDR1_REG2;             /**< MAC Layer 3 Address 1 Reg 2, offset: 0x974 */
  __IO uint32_t MAC_LAYER3_ADDR2_REG2;             /**< MAC Layer 3 Address 2 Reg 2, offset: 0x978 */
  __IO uint32_t MAC_LAYER3_ADDR3_REG2;             /**< MAC Layer 3 Address 3 Reg 2, offset: 0x97C */
       uint8_t RESERVED_24[16];
  __IO uint32_t MAC_L3_L4_CONTROL3;                /**< MAC L3 L4 Control 3, offset: 0x990 */
  __IO uint32_t MAC_LAYER4_ADDRESS3;               /**< MAC Layer 4 Address 3, offset: 0x994 */
       uint8_t RESERVED_25[8];
  __IO uint32_t MAC_LAYER3_ADDR0_REG3;             /**< MAC Layer 3 Address 0 Reg 3, offset: 0x9A0 */
  __IO uint32_t MAC_LAYER3_ADDR1_REG3;             /**< MAC Layer 3 Address 1 Reg 3, offset: 0x9A4 */
  __IO uint32_t MAC_LAYER3_ADDR2_REG3;             /**< MAC Layer 3 Address 2 Reg 3, offset: 0x9A8 */
  __IO uint32_t MAC_LAYER3_ADDR3_REG3;             /**< MAC Layer 3 Address 3 Reg 3, offset: 0x9AC */
       uint8_t RESERVED_26[336];
  __IO uint32_t MAC_TIMESTAMP_CONTROL;             /**< MAC Timestamp Control, offset: 0xB00 */
  __IO uint32_t MAC_SUB_SECOND_INCREMENT;          /**< MAC Sub Second Increment, offset: 0xB04 */
  __I  uint32_t MAC_SYSTEM_TIME_SECONDS;           /**< MAC System Time In Seconds, offset: 0xB08 */
  __I  uint32_t MAC_SYSTEM_TIME_NANOSECONDS;       /**< MAC System Time In Nanoseconds, offset: 0xB0C */
  __IO uint32_t MAC_SYSTEM_TIME_SECONDS_UPDATE;    /**< MAC System Time Seconds Update, offset: 0xB10 */
  __IO uint32_t MAC_SYSTEM_TIME_NANOSECONDS_UPDATE; /**< MAC System Time Nanoseconds Update, offset: 0xB14 */
  __IO uint32_t MAC_TIMESTAMP_ADDEND;              /**< MAC Timestamp Addend, offset: 0xB18 */
  __IO uint32_t MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS; /**< MAC System Time Higher Word In Seconds, offset: 0xB1C */
  __I  uint32_t MAC_TIMESTAMP_STATUS;              /**< MAC Timestamp Status, offset: 0xB20 */
       uint8_t RESERVED_27[12];
  __I  uint32_t MAC_TX_TIMESTAMP_STATUS_NANOSECONDS; /**< MAC Transmit Timestamp Status In Nanoseconds, offset: 0xB30 */
  __I  uint32_t MAC_TX_TIMESTAMP_STATUS_SECONDS;   /**< MAC Transmit Timestamp Status In Seconds, offset: 0xB34 */
       uint8_t RESERVED_28[24];
  __IO uint32_t MAC_TIMESTAMP_INGRESS_ASYM_CORR;   /**< MAC Timestamp Ingress Asymmetry Correction, offset: 0xB50 */
  __IO uint32_t MAC_TIMESTAMP_EGRESS_ASYM_CORR;    /**< MAC Timestamp Egress Asymmetry Correction, offset: 0xB54 */
  __IO uint32_t MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND; /**< MAC Timestamp Ingress Correction In Nanoseconds, offset: 0xB58 */
  __IO uint32_t MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND; /**< MAC Timestamp Egress Correction In Nanoseconds, offset: 0xB5C */
  __IO uint32_t MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC; /**< MAC Timestamp Ingress Correction In Subnanoseconds, offset: 0xB60 */
  __IO uint32_t MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC; /**< MAC Timestamp Engress Correction In Subnanoseconds, offset: 0xB64 */
  __I  uint32_t MAC_TIMESTAMP_INGRESS_LATENCY;     /**< MAC Timestamp Ingress Latency, offset: 0xB68 */
  __I  uint32_t MAC_TIMESTAMP_EGRESS_LATENCY;      /**< MAC Timestamp Egress Latecy, offset: 0xB6C */
  __IO uint32_t MAC_PPS_CONTROL;                   /**< MAC PPS Control, offset: 0xB70 */
       uint8_t RESERVED_29[12];
  __IO uint32_t MAC_PPS0_TARGET_TIME_SECONDS;      /**< MAC PPS0 Target Time In Seconds, offset: 0xB80 */
  __IO uint32_t MAC_PPS0_TARGET_TIME_NANOSECONDS;  /**< MAC PPS0 Target Time In Nanoseconds, offset: 0xB84 */
  __IO uint32_t MAC_PPS0_INTERVAL;                 /**< MAC PPS0 Interval, offset: 0xB88 */
  __IO uint32_t MAC_PPS0_WIDTH;                    /**< MAC PPS0 Width, offset: 0xB8C */
  __IO uint32_t MAC_PPS1_TARGET_TIME_SECONDS;      /**< MAC PPS1 Target Time In Seconds, offset: 0xB90 */
  __IO uint32_t MAC_PPS1_TARGET_TIME_NANOSECONDS;  /**< MAC PPS1 Target Time In Nanoseconds, offset: 0xB94 */
  __IO uint32_t MAC_PPS1_INTERVAL;                 /**< MAC PPS1 Interval, offset: 0xB98 */
  __IO uint32_t MAC_PPS1_WIDTH;                    /**< MAC PPS1 Width, offset: 0xB9C */
  __IO uint32_t MAC_PPS2_TARGET_TIME_SECONDS;      /**< MAC PPS2 Taget Time In Seconds, offset: 0xBA0 */
  __IO uint32_t MAC_PPS2_TARGET_TIME_NANOSECONDS;  /**< MAC PPS2 Target Time In Nanoseconds, offset: 0xBA4 */
  __IO uint32_t MAC_PPS2_INTERVAL;                 /**< MAC PPS2 Interval, offset: 0xBA8 */
  __IO uint32_t MAC_PPS2_WIDTH;                    /**< MAC PPS2 Width, offset: 0xBAC */
  __IO uint32_t MAC_PPS3_TARGET_TIME_SECONDS;      /**< MAC PPS3 Target Time In Seconds, offset: 0xBB0 */
  __IO uint32_t MAC_PPS3_TARGET_TIME_NANOSECONDS;  /**< MAC PPS3 Target Time In Nanoseconds, offset: 0xBB4 */
  __IO uint32_t MAC_PPS3_INTERVAL;                 /**< MAC PPS3 Interval, offset: 0xBB8 */
  __IO uint32_t MAC_PPS3_WIDTH;                    /**< MAC PPS3 Width, offset: 0xBBC */
       uint8_t RESERVED_30[64];
  __IO uint32_t MTL_OPERATION_MODE;                /**< MTL Operation Mode, offset: 0xC00 */
       uint8_t RESERVED_31[4];
  __IO uint32_t MTL_DBG_CTL;                       /**< MTL Debug Control, offset: 0xC08 */
  __IO uint32_t MTL_DBG_STS;                       /**< MTL Debug Status, offset: 0xC0C */
  __IO uint32_t MTL_FIFO_DEBUG_DATA;               /**< MTL FIFO Debug Data, offset: 0xC10 */
       uint8_t RESERVED_32[12];
  __I  uint32_t MTL_INTERRUPT_STATUS;              /**< MTL Interrupt Status, offset: 0xC20 */
       uint8_t RESERVED_33[12];
  __IO uint32_t MTL_RXQ_DMA_MAP0;                  /**< MTL Receive Queue DMA Map 0, offset: 0xC30 */
       uint8_t RESERVED_34[12];
  __IO uint32_t MTL_TBS_CTRL;                      /**< MTL TBS Control, offset: 0xC40 */
       uint8_t RESERVED_35[12];
  __IO uint32_t MTL_EST_CONTROL;                   /**< MTL EST Control, offset: 0xC50 */
       uint8_t RESERVED_36[4];
  __IO uint32_t MTL_EST_STATUS;                    /**< MTL EST Status, offset: 0xC58 */
       uint8_t RESERVED_37[4];
  __IO uint32_t MTL_EST_SCH_ERROR;                 /**< MTL EST Scheduling Error, offset: 0xC60 */
  __IO uint32_t MTL_EST_FRM_SIZE_ERROR;            /**< MTL EST Frame Size Error, offset: 0xC64 */
  __I  uint32_t MTL_EST_FRM_SIZE_CAPTURE;          /**< MTL EST Frame Size Capture, offset: 0xC68 */
       uint8_t RESERVED_38[4];
  __IO uint32_t MTL_EST_INTR_ENABLE;               /**< MTL EST Interrupt Enable, offset: 0xC70 */
       uint8_t RESERVED_39[12];
  __IO uint32_t MTL_EST_GCL_CONTROL;               /**< MTL EST GCL Control, offset: 0xC80 */
  __IO uint32_t MTL_EST_GCL_DATA;                  /**< MTL EST GCL Data, offset: 0xC84 */
       uint8_t RESERVED_40[8];
  __IO uint32_t MTL_FPE_CTRL_STS;                  /**< MTL FPE Control Status, offset: 0xC90 */
  __IO uint32_t MTL_FPE_ADVANCE;                   /**< MTL FPE Advance, offset: 0xC94 */
       uint8_t RESERVED_41[8];
  __IO uint32_t MTL_RXP_CONTROL_STATUS;            /**< MTL Rx Parser Control Status, offset: 0xCA0 */
  __IO uint32_t MTL_RXP_INTERRUPT_CONTROL_STATUS;  /**< MTL Rx Parser Interrupt Control Status, offset: 0xCA4 */
  __I  uint32_t MTL_RXP_DROP_CNT;                  /**< MTL Rx Parser Drop Count, offset: 0xCA8 */
  __I  uint32_t MTL_RXP_ERROR_CNT;                 /**< MTL Rx Parser Error Count, offset: 0xCAC */
  __IO uint32_t MTL_RXP_INDIRECT_ACC_CONTROL_STATUS; /**< MTL Rx Parser Indirect Access Control Status, offset: 0xCB0 */
  __I  uint32_t MTL_RXP_INDIRECT_ACC_DATA;         /**< MTL Rx Parser Indirect Access Data, offset: 0xCB4 */
       uint8_t RESERVED_42[8];
  __IO uint32_t MTL_ECC_CONTROL;                   /**< MTL ECC Control, offset: 0xCC0 */
  __I  uint32_t MTL_SAFETY_INTERRUPT_STATUS;       /**< MTL Safety Interript Status, offset: 0xCC4 */
  __IO uint32_t MTL_ECC_INTERRUPT_ENABLE;          /**< MTL ECC Interrupt Enable, offset: 0xCC8 */
  __IO uint32_t MTL_ECC_INTERRUPT_STATUS;          /**< MTL ECC Interrupt Status, offset: 0xCCC */
  __IO uint32_t MTL_ECC_ERR_STS_RCTL;              /**< MTL ECC Error Status, offset: 0xCD0 */
  __I  uint32_t MTL_ECC_ERR_ADDR_STATUS;           /**< MTL ECC Error Adress Status, offset: 0xCD4 */
  __I  uint32_t MTL_ECC_ERR_CNTR_STATUS;           /**< MTL ECC Error Control Status, offset: 0xCD8 */
       uint8_t RESERVED_43[4];
  __IO uint32_t MTL_DPP_CONTROL;                   /**< MTL DPP Control, offset: 0xCE0 */
       uint8_t RESERVED_44[28];
  __IO uint32_t MTL_TXQ0_OPERATION_MODE;           /**< MTL Tx Queue 0 Operation Mode, offset: 0xD00 */
  __I  uint32_t MTL_TXQ0_UNDERFLOW;                /**< MTL Tx Queue 0 Underflow, offset: 0xD04 */
  __I  uint32_t MTL_TXQ0_DEBUG;                    /**< MTL Tx Queue 0 Debug, offset: 0xD08 */
       uint8_t RESERVED_45[8];
  __I  uint32_t MTL_TXQ0_ETS_STATUS;               /**< MTL Tx Queue 0 ETS Status, offset: 0xD14 */
  __IO uint32_t MTL_TXQ0_QUANTUM_WEIGHT;           /**< MTL Tx Queue Quantum Weight, offset: 0xD18 */
       uint8_t RESERVED_46[16];
  __IO uint32_t MTL_Q0_INTERRUPT_CONTROL_STATUS;   /**< MTL Queue 0 Interrupt Control Status, offset: 0xD2C */
  __IO uint32_t MTL_RXQ0_OPERATION_MODE;           /**< MTL Rx Queue 0 Operation Mode, offset: 0xD30 */
  __I  uint32_t MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT; /**< MTL Rx Queue Missed Packet Overflow Count, offset: 0xD34 */
  __I  uint32_t MTL_RXQ0_DEBUG;                    /**< MTL Rx Queue 0 Debug, offset: 0xD38 */
  __IO uint32_t MTL_RXQ0_CONTROL;                  /**< MTL Rx Queue 0 Control 0, offset: 0xD3C */
  __IO uint32_t MTL_TXQ1_OPERATION_MODE;           /**< MTL Tx Queue 1 Operation Mode, offset: 0xD40 */
  __I  uint32_t MTL_TXQ1_UNDERFLOW;                /**< MTL Tx Queue 1 Underflow, offset: 0xD44 */
  __I  uint32_t MTL_TXQ1_DEBUG;                    /**< MTL Tx Queue 1 Debug, offset: 0xD48 */
       uint8_t RESERVED_47[4];
  __IO uint32_t MTL_TXQ1_ETS_CONTROL;              /**< MTL Tx Queue 1 ETS Control, offset: 0xD50 */
  __I  uint32_t MTL_TXQ1_ETS_STATUS;               /**< MTL Tx Queue 1 ETS Status, offset: 0xD54 */
  __IO uint32_t MTL_TXQ1_QUANTUM_WEIGHT;           /**< MTL Tx Queue 1 Quantum Weight, offset: 0xD58 */
  __IO uint32_t MTL_TXQ1_SENDSLOPECREDIT;          /**< MTL Tx Queue 1 Sendslope Credit, offset: 0xD5C */
  __IO uint32_t MTL_TXQ1_HICREDIT;                 /**< MTL Tx Queue 1 HiCredit, offset: 0xD60 */
  __IO uint32_t MTL_TXQ1_LOCREDIT;                 /**< MTL Tx Queue 1 LoCredit, offset: 0xD64 */
       uint8_t RESERVED_48[4];
  __IO uint32_t MTL_Q1_INTERRUPT_CONTROL_STATUS;   /**< MTL Queue 1 Interrupt Control Status, offset: 0xD6C */
  __IO uint32_t MTL_RXQ1_OPERATION_MODE;           /**< MTL Rx Queue 1 Operation Mode, offset: 0xD70 */
  __I  uint32_t MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT; /**< MTL Rx Queue 1 Missed Packet Overflow Counter, offset: 0xD74 */
  __I  uint32_t MTL_RXQ1_DEBUG;                    /**< MTL Rx Queue 1 Debug, offset: 0xD78 */
  __IO uint32_t MTL_RXQ1_CONTROL;                  /**< MTL Rx Queue 1 Control, offset: 0xD7C */
       uint8_t RESERVED_49[640];
  __IO uint32_t DMA_MODE;                          /**< DMA Mode, offset: 0x1000 */
  __IO uint32_t DMA_SYSBUS_MODE;                   /**< DMA System Bus Mode, offset: 0x1004 */
  __I  uint32_t DMA_INTERRUPT_STATUS;              /**< DMA Interrupt Status, offset: 0x1008 */
  __I  uint32_t DMA_DEBUG_STATUS0;                 /**< DMA Debug Status 0, offset: 0x100C */
       uint8_t RESERVED_50[64];
  __IO uint32_t DMA_TBS_CTRL;                      /**< DMA TBS Control, offset: 0x1050 */
       uint8_t RESERVED_51[44];
  __I  uint32_t DMA_SAFETY_INTERRUPT_STATUS;       /**< DMA Safety Interrupt Status, offset: 0x1080 */
       uint8_t RESERVED_52[124];
  __IO uint32_t DMA_CH0_CONTROL;                   /**< DMA Channel 0 Control, offset: 0x1100 */
  __IO uint32_t DMA_CH0_TX_CONTROL;                /**< DMA Channel Tx Control, offset: 0x1104 */
  __IO uint32_t DMA_CH0_RX_CONTROL;                /**< DMA Channel Rx Control, offset: 0x1108 */
       uint8_t RESERVED_53[8];
  __IO uint32_t DMA_CH0_TXDESC_LIST_ADDRESS;       /**< DMA Channel 0 Tx Descriptor List Address, offset: 0x1114 */
       uint8_t RESERVED_54[4];
  __IO uint32_t DMA_CH0_RXDESC_LIST_ADDRESS;       /**< DMA Channel 0 Rx Descriptor List Address, offset: 0x111C */
  __IO uint32_t DMA_CH0_TXDESC_TAIL_POINTER;       /**< DMA Channel 0 Tx Descriptor Tail Pointer, offset: 0x1120 */
       uint8_t RESERVED_55[4];
  __IO uint32_t DMA_CH0_RXDESC_TAIL_POINTER;       /**< DMA Channeli 0 Rx Descriptor List Pointer, offset: 0x1128 */
  __IO uint32_t DMA_CH0_TXDESC_RING_LENGTH;        /**< DMA Channel 0 Tx Descriptor Ring Length, offset: 0x112C */
  __IO uint32_t DMA_CH0_RXDESC_RING_LENGTH;        /**< DMA Channel 0 Rx Descriptor Ring Length, offset: 0x1130 */
  __IO uint32_t DMA_CH0_INTERRUPT_ENABLE;          /**< DMA Channel 0 Interrupt Enable, offset: 0x1134 */
  __IO uint32_t DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER; /**< DMA Channel 0 Rx Interrupt Watchdog Timer, offset: 0x1138 */
  __IO uint32_t DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS; /**< DMA Channel 0 Slot Function Control Status, offset: 0x113C */
       uint8_t RESERVED_56[4];
  __I  uint32_t DMA_CH0_CURRENT_APP_TXDESC;        /**< DMA Channel 0 Current Application Transmit Descriptor, offset: 0x1144 */
       uint8_t RESERVED_57[4];
  __I  uint32_t DMA_CH0_CURRENT_APP_RXDESC;        /**< DMA Channel 0 Current Application Receive Descriptor, offset: 0x114C */
       uint8_t RESERVED_58[4];
  __I  uint32_t DMA_CH0_CURRENT_APP_TXBUFFER;      /**< DMA Channel 0 Current Application Transmit Descriptor, offset: 0x1154 */
       uint8_t RESERVED_59[4];
  __I  uint32_t DMA_CH0_CURRENT_APP_RXBUFFER;      /**< DMA Channel 0 Current Application Receive Buffer, offset: 0x115C */
  __IO uint32_t DMA_CH0_STATUS;                    /**< DMA Channel 0 Status, offset: 0x1160 */
  __I  uint32_t DMA_CH0_MISS_FRAME_CNT;            /**< DMA Channel 0 Miss Frame Counter, offset: 0x1164 */
  __I  uint32_t DMA_CH0_RXP_ACCEPT_CNT;            /**< DMA Channel 0 Rx Parser Accept Count, offset: 0x1168 */
  __I  uint32_t DMA_CH0_RX_ERI_CNT;                /**< DMA Channel 0 Rx ERI Count, offset: 0x116C */
       uint8_t RESERVED_60[16];
  __IO uint32_t DMA_CH1_CONTROL;                   /**< DMA Channel 1 Control, offset: 0x1180 */
  __IO uint32_t DMA_CH1_TX_CONTROL;                /**< DMA Channel 1 Tx Control, offset: 0x1184 */
  __IO uint32_t DMA_CH1_RX_CONTROL;                /**< DMA Channel 1 Rx Control, offset: 0x1188 */
       uint8_t RESERVED_61[8];
  __IO uint32_t DMA_CH1_TXDESC_LIST_ADDRESS;       /**< DMA Channel 1 Tx Descriptor List Address, offset: 0x1194 */
       uint8_t RESERVED_62[4];
  __IO uint32_t DMA_CH1_RXDESC_LIST_ADDRESS;       /**< DMA Channel 1 Rx Descriptor List Address, offset: 0x119C */
  __IO uint32_t DMA_CH1_TXDESC_TAIL_POINTER;       /**< DMA Channel 1 Tx Descriptor Tail Pointer, offset: 0x11A0 */
       uint8_t RESERVED_63[4];
  __IO uint32_t DMA_CH1_RXDESC_TAIL_POINTER;       /**< DMA Channel 1 Rx Descriptor Tail Pointer, offset: 0x11A8 */
  __IO uint32_t DMA_CH1_TXDESC_RING_LENGTH;        /**< DMA Channel 1 Tx Descriptor Ring Length, offset: 0x11AC */
  __IO uint32_t DMA_CH1_RXDESC_RING_LENGTH;        /**< DMA Channel 1 Rx Descriptor Ring Length, offset: 0x11B0 */
  __IO uint32_t DMA_CH1_INTERRUPT_ENABLE;          /**< DMA Channel 1 Interrupt Enable, offset: 0x11B4 */
  __IO uint32_t DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER; /**< DMA Channel 1 Rx Interrupt Watchdog Timer, offset: 0x11B8 */
  __IO uint32_t DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS; /**< DMA Channel 1 Slot Function Control Status, offset: 0x11BC */
       uint8_t RESERVED_64[4];
  __I  uint32_t DMA_CH1_CURRENT_APP_TXDESC;        /**< DMA Channel 1 Current Application Transmit Descriptor, offset: 0x11C4 */
       uint8_t RESERVED_65[4];
  __I  uint32_t DMA_CH1_CURRENT_APP_RXDESC;        /**< DMA Channel 1 Current Application Receive Descriptor, offset: 0x11CC */
       uint8_t RESERVED_66[4];
  __I  uint32_t DMA_CH1_CURRENT_APP_TXBUFFER;      /**< DMA Channel 1 Current Application Transmit Buffer, offset: 0x11D4 */
       uint8_t RESERVED_67[4];
  __I  uint32_t DMA_CH1_CURRENT_APP_RXBUFFER;      /**< DMA Channel 1 Current Application Receive Buffer, offset: 0x11DC */
  __IO uint32_t DMA_CH1_STATUS;                    /**< DMA Channel 1 Status, offset: 0x11E0 */
  __I  uint32_t DMA_CH1_MISS_FRAME_CNT;            /**< DMA Channel 1 Miss Frame Counter, offset: 0x11E4 */
  __I  uint32_t DMA_CH1_RXP_ACCEPT_CNT;            /**< DMA Channel 1 Rx Parser Accept Count, offset: 0x11E8 */
  __I  uint32_t DMA_CH1_RX_ERI_CNT;                /**< DMA Channel 1 Rx ERI Count, offset: 0x11EC */
} EMAC_Type;

/* ----------------------------------------------------------------------------
   -- EMAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EMAC_Register_Masks EMAC Register Masks
 * @{
 */

/*! @name MAC_CONFIGURATION - MAC Configuration */
/*! @{ */

#define EMAC_MAC_CONFIGURATION_RE_MASK           (0x1U)
#define EMAC_MAC_CONFIGURATION_RE_SHIFT          (0U)
/*! RE - Receiver Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_CONFIGURATION_RE(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_RE_SHIFT)) & EMAC_MAC_CONFIGURATION_RE_MASK)

#define EMAC_MAC_CONFIGURATION_TE_MASK           (0x2U)
#define EMAC_MAC_CONFIGURATION_TE_SHIFT          (1U)
/*! TE - Transmitter Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_CONFIGURATION_TE(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_TE_SHIFT)) & EMAC_MAC_CONFIGURATION_TE_MASK)

#define EMAC_MAC_CONFIGURATION_PRELEN_MASK       (0xCU)
#define EMAC_MAC_CONFIGURATION_PRELEN_SHIFT      (2U)
/*! PRELEN - Preamble Length for Transmit Packets
 *  0b00..7 bytes
 *  0b01..5 bytes
 *  0b10..3 bytes
 *  0b11..Reserved
 */
#define EMAC_MAC_CONFIGURATION_PRELEN(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_PRELEN_SHIFT)) & EMAC_MAC_CONFIGURATION_PRELEN_MASK)

#define EMAC_MAC_CONFIGURATION_DC_MASK           (0x10U)
#define EMAC_MAC_CONFIGURATION_DC_SHIFT          (4U)
/*! DC - Deferral Check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_CONFIGURATION_DC(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_DC_SHIFT)) & EMAC_MAC_CONFIGURATION_DC_MASK)

#define EMAC_MAC_CONFIGURATION_BL_MASK           (0x60U)
#define EMAC_MAC_CONFIGURATION_BL_SHIFT          (5U)
/*! BL - Back-Off Limit
 *  0b00..k = min(n,10)
 *  0b01..k = min(n,8)
 *  0b10..k = min(n,4)
 *  0b11..k = min(n,1)
 */
#define EMAC_MAC_CONFIGURATION_BL(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_BL_SHIFT)) & EMAC_MAC_CONFIGURATION_BL_MASK)

#define EMAC_MAC_CONFIGURATION_DR_MASK           (0x100U)
#define EMAC_MAC_CONFIGURATION_DR_SHIFT          (8U)
/*! DR - Disable Retry
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_CONFIGURATION_DR(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_DR_SHIFT)) & EMAC_MAC_CONFIGURATION_DR_MASK)

#define EMAC_MAC_CONFIGURATION_DCRS_MASK         (0x200U)
#define EMAC_MAC_CONFIGURATION_DCRS_SHIFT        (9U)
/*! DCRS - Disable Carrier Sense During Transmission
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_CONFIGURATION_DCRS(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_DCRS_SHIFT)) & EMAC_MAC_CONFIGURATION_DCRS_MASK)

#define EMAC_MAC_CONFIGURATION_DO_MASK           (0x400U)
#define EMAC_MAC_CONFIGURATION_DO_SHIFT          (10U)
/*! DO - Disable Receive Own
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_CONFIGURATION_DO(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_DO_SHIFT)) & EMAC_MAC_CONFIGURATION_DO_MASK)

#define EMAC_MAC_CONFIGURATION_ECRSFD_MASK       (0x800U)
#define EMAC_MAC_CONFIGURATION_ECRSFD_SHIFT      (11U)
/*! ECRSFD - Enable Carrier Sense In Full-Duplex Mode
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_CONFIGURATION_ECRSFD(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_ECRSFD_SHIFT)) & EMAC_MAC_CONFIGURATION_ECRSFD_MASK)

#define EMAC_MAC_CONFIGURATION_LM_MASK           (0x1000U)
#define EMAC_MAC_CONFIGURATION_LM_SHIFT          (12U)
/*! LM - Loopback Mode
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_CONFIGURATION_LM(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_LM_SHIFT)) & EMAC_MAC_CONFIGURATION_LM_MASK)

#define EMAC_MAC_CONFIGURATION_DM_MASK           (0x2000U)
#define EMAC_MAC_CONFIGURATION_DM_SHIFT          (13U)
/*! DM - Duplex Mode
 *  0b0..Half-duplex mode
 *  0b1..Full-duplex mode
 */
#define EMAC_MAC_CONFIGURATION_DM(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_DM_SHIFT)) & EMAC_MAC_CONFIGURATION_DM_MASK)

#define EMAC_MAC_CONFIGURATION_FES_MASK          (0x4000U)
#define EMAC_MAC_CONFIGURATION_FES_SHIFT         (14U)
/*! FES - Speed
 *  0b0..10 Mbit/s if PS = 1 and 1 Gbps if PS = 0
 *  0b1..100 Mbit/s if PS = 1 and 2.5 Gbps if PS = 0
 */
#define EMAC_MAC_CONFIGURATION_FES(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_FES_SHIFT)) & EMAC_MAC_CONFIGURATION_FES_MASK)

#define EMAC_MAC_CONFIGURATION_PS_MASK           (0x8000U)
#define EMAC_MAC_CONFIGURATION_PS_SHIFT          (15U)
/*! PS - Port Select
 *  0b0..For 1000 or 2500 Mbit/s operations
 *  0b1..For 10 or 100 Mbit/s operations
 */
#define EMAC_MAC_CONFIGURATION_PS(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_PS_SHIFT)) & EMAC_MAC_CONFIGURATION_PS_MASK)

#define EMAC_MAC_CONFIGURATION_JE_MASK           (0x10000U)
#define EMAC_MAC_CONFIGURATION_JE_SHIFT          (16U)
/*! JE - Jumbo Packet Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_CONFIGURATION_JE(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_JE_SHIFT)) & EMAC_MAC_CONFIGURATION_JE_MASK)

#define EMAC_MAC_CONFIGURATION_JD_MASK           (0x20000U)
#define EMAC_MAC_CONFIGURATION_JD_SHIFT          (17U)
/*! JD - Jabber Disable
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_CONFIGURATION_JD(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_JD_SHIFT)) & EMAC_MAC_CONFIGURATION_JD_MASK)

#define EMAC_MAC_CONFIGURATION_WD_MASK           (0x80000U)
#define EMAC_MAC_CONFIGURATION_WD_SHIFT          (19U)
/*! WD - Watchdog Disable
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_CONFIGURATION_WD(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_WD_SHIFT)) & EMAC_MAC_CONFIGURATION_WD_MASK)

#define EMAC_MAC_CONFIGURATION_ACS_MASK          (0x100000U)
#define EMAC_MAC_CONFIGURATION_ACS_SHIFT         (20U)
/*! ACS - Automatic Pad Or CRC Stripping
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_CONFIGURATION_ACS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_ACS_SHIFT)) & EMAC_MAC_CONFIGURATION_ACS_MASK)

#define EMAC_MAC_CONFIGURATION_CST_MASK          (0x200000U)
#define EMAC_MAC_CONFIGURATION_CST_SHIFT         (21U)
/*! CST - CRC Stripping For Type Packets
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_CONFIGURATION_CST(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_CST_SHIFT)) & EMAC_MAC_CONFIGURATION_CST_MASK)

#define EMAC_MAC_CONFIGURATION_S2KP_MASK         (0x400000U)
#define EMAC_MAC_CONFIGURATION_S2KP_SHIFT        (22U)
/*! S2KP - IEEE 802.3 Support For 2K Packets
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_CONFIGURATION_S2KP(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_S2KP_SHIFT)) & EMAC_MAC_CONFIGURATION_S2KP_MASK)

#define EMAC_MAC_CONFIGURATION_GPSLCE_MASK       (0x800000U)
#define EMAC_MAC_CONFIGURATION_GPSLCE_SHIFT      (23U)
/*! GPSLCE - Giant Packet Size Limit Control Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_CONFIGURATION_GPSLCE(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_GPSLCE_SHIFT)) & EMAC_MAC_CONFIGURATION_GPSLCE_MASK)

#define EMAC_MAC_CONFIGURATION_IPG_MASK          (0x7000000U)
#define EMAC_MAC_CONFIGURATION_IPG_SHIFT         (24U)
/*! IPG - Inter-Packet Gap
 *  0b000..96-bit times IPG
 *  0b001..88-bit times IPG
 *  0b010..80-bit times IPG
 *  0b011..72-bit times IPG
 *  0b100..64-bit times IPG
 *  0b101..56-bit times IPG
 *  0b110..48-bit times IPG
 *  0b111..40-bit times IPG
 */
#define EMAC_MAC_CONFIGURATION_IPG(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_IPG_SHIFT)) & EMAC_MAC_CONFIGURATION_IPG_MASK)

#define EMAC_MAC_CONFIGURATION_IPC_MASK          (0x8000000U)
#define EMAC_MAC_CONFIGURATION_IPC_SHIFT         (27U)
/*! IPC - Checksum Offload
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_CONFIGURATION_IPC(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_IPC_SHIFT)) & EMAC_MAC_CONFIGURATION_IPC_MASK)

#define EMAC_MAC_CONFIGURATION_SARC_MASK         (0x70000000U)
#define EMAC_MAC_CONFIGURATION_SARC_SHIFT        (28U)
/*! SARC - Source Address Insertion Or Replacement Control
 *  0b000..mti_sa_ctrl_i and ati_sa_ctrl_i input signals control the SA field generation
 *  0b010..Contents of are inserted in the SA field
 *  0b011..Contents of replace the SA field
 *  0b110..Contents of are inserted in the SA field
 *  0b111..Contents of replace the SA field
 */
#define EMAC_MAC_CONFIGURATION_SARC(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CONFIGURATION_SARC_SHIFT)) & EMAC_MAC_CONFIGURATION_SARC_MASK)
/*! @} */

/*! @name MAC_EXT_CONFIGURATION - MAC Extended Configuration */
/*! @{ */

#define EMAC_MAC_EXT_CONFIGURATION_GPSL_MASK     (0x3FFFU)
#define EMAC_MAC_EXT_CONFIGURATION_GPSL_SHIFT    (0U)
/*! GPSL - Giant Packet Size Limit */
#define EMAC_MAC_EXT_CONFIGURATION_GPSL(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_EXT_CONFIGURATION_GPSL_SHIFT)) & EMAC_MAC_EXT_CONFIGURATION_GPSL_MASK)

#define EMAC_MAC_EXT_CONFIGURATION_DCRCC_MASK    (0x10000U)
#define EMAC_MAC_EXT_CONFIGURATION_DCRCC_SHIFT   (16U)
/*! DCRCC - Disable CRC Checking For Received Packets
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_EXT_CONFIGURATION_DCRCC(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_EXT_CONFIGURATION_DCRCC_SHIFT)) & EMAC_MAC_EXT_CONFIGURATION_DCRCC_MASK)

#define EMAC_MAC_EXT_CONFIGURATION_SPEN_MASK     (0x20000U)
#define EMAC_MAC_EXT_CONFIGURATION_SPEN_SHIFT    (17U)
/*! SPEN - Slow Protocol Detection Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_EXT_CONFIGURATION_SPEN(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_EXT_CONFIGURATION_SPEN_SHIFT)) & EMAC_MAC_EXT_CONFIGURATION_SPEN_MASK)

#define EMAC_MAC_EXT_CONFIGURATION_USP_MASK      (0x40000U)
#define EMAC_MAC_EXT_CONFIGURATION_USP_SHIFT     (18U)
/*! USP - Unicast Slow Protocol Packet Detect
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_EXT_CONFIGURATION_USP(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_EXT_CONFIGURATION_USP_SHIFT)) & EMAC_MAC_EXT_CONFIGURATION_USP_MASK)

#define EMAC_MAC_EXT_CONFIGURATION_PDC_MASK      (0x80000U)
#define EMAC_MAC_EXT_CONFIGURATION_PDC_SHIFT     (19U)
/*! PDC - Packet Duplication Control
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_EXT_CONFIGURATION_PDC(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_EXT_CONFIGURATION_PDC_SHIFT)) & EMAC_MAC_EXT_CONFIGURATION_PDC_MASK)

#define EMAC_MAC_EXT_CONFIGURATION_EIPGEN_MASK   (0x1000000U)
#define EMAC_MAC_EXT_CONFIGURATION_EIPGEN_SHIFT  (24U)
/*! EIPGEN - Extended Inter-Packet Gap Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_EXT_CONFIGURATION_EIPGEN(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_EXT_CONFIGURATION_EIPGEN_SHIFT)) & EMAC_MAC_EXT_CONFIGURATION_EIPGEN_MASK)

#define EMAC_MAC_EXT_CONFIGURATION_EIPG_MASK     (0x3E000000U)
#define EMAC_MAC_EXT_CONFIGURATION_EIPG_SHIFT    (25U)
/*! EIPG - Extended Inter-Packet Gap */
#define EMAC_MAC_EXT_CONFIGURATION_EIPG(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_EXT_CONFIGURATION_EIPG_SHIFT)) & EMAC_MAC_EXT_CONFIGURATION_EIPG_MASK)
/*! @} */

/*! @name MAC_PACKET_FILTER - MAC Packet Filter */
/*! @{ */

#define EMAC_MAC_PACKET_FILTER_PR_MASK           (0x1U)
#define EMAC_MAC_PACKET_FILTER_PR_SHIFT          (0U)
/*! PR - Promiscuous Mode
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_PACKET_FILTER_PR(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PACKET_FILTER_PR_SHIFT)) & EMAC_MAC_PACKET_FILTER_PR_MASK)

#define EMAC_MAC_PACKET_FILTER_HUC_MASK          (0x2U)
#define EMAC_MAC_PACKET_FILTER_HUC_SHIFT         (1U)
/*! HUC - Hash Unicast
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_PACKET_FILTER_HUC(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PACKET_FILTER_HUC_SHIFT)) & EMAC_MAC_PACKET_FILTER_HUC_MASK)

#define EMAC_MAC_PACKET_FILTER_HMC_MASK          (0x4U)
#define EMAC_MAC_PACKET_FILTER_HMC_SHIFT         (2U)
/*! HMC - Hash Multicast
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_PACKET_FILTER_HMC(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PACKET_FILTER_HMC_SHIFT)) & EMAC_MAC_PACKET_FILTER_HMC_MASK)

#define EMAC_MAC_PACKET_FILTER_DAIF_MASK         (0x8U)
#define EMAC_MAC_PACKET_FILTER_DAIF_SHIFT        (3U)
/*! DAIF - DA Inverse Filtering
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_PACKET_FILTER_DAIF(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PACKET_FILTER_DAIF_SHIFT)) & EMAC_MAC_PACKET_FILTER_DAIF_MASK)

#define EMAC_MAC_PACKET_FILTER_PM_MASK           (0x10U)
#define EMAC_MAC_PACKET_FILTER_PM_SHIFT          (4U)
/*! PM - Pass All Multicast
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_PACKET_FILTER_PM(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PACKET_FILTER_PM_SHIFT)) & EMAC_MAC_PACKET_FILTER_PM_MASK)

#define EMAC_MAC_PACKET_FILTER_DBF_MASK          (0x20U)
#define EMAC_MAC_PACKET_FILTER_DBF_SHIFT         (5U)
/*! DBF - Disable Broadcast Packets
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_PACKET_FILTER_DBF(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PACKET_FILTER_DBF_SHIFT)) & EMAC_MAC_PACKET_FILTER_DBF_MASK)

#define EMAC_MAC_PACKET_FILTER_PCF_MASK          (0xC0U)
#define EMAC_MAC_PACKET_FILTER_PCF_SHIFT         (6U)
/*! PCF - Pass Control Packets
 *  0b00..MAC filters all the control packets from reaching the application
 *  0b01..MAC forwards all the control packets, except pause packets, to the application even if they fail the address filter
 *  0b10..MAC forwards all the control packets to the application even if they fail the address filter
 *  0b11..MAC forwards all the control packets that pass the address filter
 */
#define EMAC_MAC_PACKET_FILTER_PCF(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PACKET_FILTER_PCF_SHIFT)) & EMAC_MAC_PACKET_FILTER_PCF_MASK)

#define EMAC_MAC_PACKET_FILTER_SAIF_MASK         (0x100U)
#define EMAC_MAC_PACKET_FILTER_SAIF_SHIFT        (8U)
/*! SAIF - SA Inverse Filtering
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_PACKET_FILTER_SAIF(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PACKET_FILTER_SAIF_SHIFT)) & EMAC_MAC_PACKET_FILTER_SAIF_MASK)

#define EMAC_MAC_PACKET_FILTER_SAF_MASK          (0x200U)
#define EMAC_MAC_PACKET_FILTER_SAF_SHIFT         (9U)
/*! SAF - Source Address Filter Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_PACKET_FILTER_SAF(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PACKET_FILTER_SAF_SHIFT)) & EMAC_MAC_PACKET_FILTER_SAF_MASK)

#define EMAC_MAC_PACKET_FILTER_HPF_MASK          (0x400U)
#define EMAC_MAC_PACKET_FILTER_HPF_SHIFT         (10U)
/*! HPF - Hash Or Perfect Filter
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_PACKET_FILTER_HPF(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PACKET_FILTER_HPF_SHIFT)) & EMAC_MAC_PACKET_FILTER_HPF_MASK)

#define EMAC_MAC_PACKET_FILTER_VTFE_MASK         (0x10000U)
#define EMAC_MAC_PACKET_FILTER_VTFE_SHIFT        (16U)
/*! VTFE - VLAN Tag Filter Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_PACKET_FILTER_VTFE(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PACKET_FILTER_VTFE_SHIFT)) & EMAC_MAC_PACKET_FILTER_VTFE_MASK)

#define EMAC_MAC_PACKET_FILTER_IPFE_MASK         (0x100000U)
#define EMAC_MAC_PACKET_FILTER_IPFE_SHIFT        (20U)
/*! IPFE - Layer 3 and Layer 4 Filter Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_PACKET_FILTER_IPFE(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PACKET_FILTER_IPFE_SHIFT)) & EMAC_MAC_PACKET_FILTER_IPFE_MASK)

#define EMAC_MAC_PACKET_FILTER_DNTU_MASK         (0x200000U)
#define EMAC_MAC_PACKET_FILTER_DNTU_SHIFT        (21U)
/*! DNTU - Drop Non-TCP/UDP Over IP Packets
 *  0b0..Forwards
 *  0b1..Drops
 */
#define EMAC_MAC_PACKET_FILTER_DNTU(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PACKET_FILTER_DNTU_SHIFT)) & EMAC_MAC_PACKET_FILTER_DNTU_MASK)

#define EMAC_MAC_PACKET_FILTER_RA_MASK           (0x80000000U)
#define EMAC_MAC_PACKET_FILTER_RA_SHIFT          (31U)
/*! RA - Receive All
 *  0b0..Receive All is disabled
 *  0b1..Receive All is enabled
 */
#define EMAC_MAC_PACKET_FILTER_RA(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PACKET_FILTER_RA_SHIFT)) & EMAC_MAC_PACKET_FILTER_RA_MASK)
/*! @} */

/*! @name MAC_WATCHDOG_TIMEOUT - MAC Watchdog Timeout */
/*! @{ */

#define EMAC_MAC_WATCHDOG_TIMEOUT_WTO_MASK       (0xFU)
#define EMAC_MAC_WATCHDOG_TIMEOUT_WTO_SHIFT      (0U)
/*! WTO - Watchdog Timeout
 *  0b0000..2 KB
 *  0b0001..3 KB
 *  0b0010..4 KB
 *  0b0011..5 KB
 *  0b0100..6 KB
 *  0b0101..7 KB
 *  0b0110..8 KB
 *  0b0111..9 KB
 *  0b1000..10 KB
 *  0b1001..11 KB
 *  0b1010..12 KB
 *  0b1011..13 KB
 *  0b1100..14 KB
 *  0b1101..15 KB
 *  0b1110..16383 bytes
 *  0b1111..Reserved
 */
#define EMAC_MAC_WATCHDOG_TIMEOUT_WTO(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_WATCHDOG_TIMEOUT_WTO_SHIFT)) & EMAC_MAC_WATCHDOG_TIMEOUT_WTO_MASK)

#define EMAC_MAC_WATCHDOG_TIMEOUT_PWE_MASK       (0x100U)
#define EMAC_MAC_WATCHDOG_TIMEOUT_PWE_SHIFT      (8U)
/*! PWE - Programmable Watchdog Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_WATCHDOG_TIMEOUT_PWE(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_WATCHDOG_TIMEOUT_PWE_SHIFT)) & EMAC_MAC_WATCHDOG_TIMEOUT_PWE_MASK)
/*! @} */

/*! @name MAC_HASH_TABLE_REG0 - MAC Hash Table First 32 Bits */
/*! @{ */

#define EMAC_MAC_HASH_TABLE_REG0_HT31T0_MASK     (0xFFFFFFFFU)
#define EMAC_MAC_HASH_TABLE_REG0_HT31T0_SHIFT    (0U)
/*! HT31T0 - MAC Hash Table First 32 Bits */
#define EMAC_MAC_HASH_TABLE_REG0_HT31T0(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HASH_TABLE_REG0_HT31T0_SHIFT)) & EMAC_MAC_HASH_TABLE_REG0_HT31T0_MASK)
/*! @} */

/*! @name MAC_HASH_TABLE_REG1 - MAC Hash Table Second 32 Bits */
/*! @{ */

#define EMAC_MAC_HASH_TABLE_REG1_HT63T32_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_HASH_TABLE_REG1_HT63T32_SHIFT   (0U)
/*! HT63T32 - MAC Hash Table Second 32 Bits */
#define EMAC_MAC_HASH_TABLE_REG1_HT63T32(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HASH_TABLE_REG1_HT63T32_SHIFT)) & EMAC_MAC_HASH_TABLE_REG1_HT63T32_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_CTRL - MAC VLAN Tag Control */
/*! @{ */

#define EMAC_MAC_VLAN_TAG_CTRL_OB_MASK           (0x1U)
#define EMAC_MAC_VLAN_TAG_CTRL_OB_SHIFT          (0U)
/*! OB - Operation Busy
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_CTRL_OB(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_OB_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_OB_MASK)

#define EMAC_MAC_VLAN_TAG_CTRL_CT_MASK           (0x2U)
#define EMAC_MAC_VLAN_TAG_CTRL_CT_SHIFT          (1U)
/*! CT - Command Type
 *  0b0..Write operation
 *  0b1..Read operation
 */
#define EMAC_MAC_VLAN_TAG_CTRL_CT(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_CT_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_CT_MASK)

#define EMAC_MAC_VLAN_TAG_CTRL_OFS_MASK          (0xCU)
#define EMAC_MAC_VLAN_TAG_CTRL_OFS_SHIFT         (2U)
/*! OFS - Offset */
#define EMAC_MAC_VLAN_TAG_CTRL_OFS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_OFS_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_OFS_MASK)

#define EMAC_MAC_VLAN_TAG_CTRL_ETV_MASK          (0x10000U)
#define EMAC_MAC_VLAN_TAG_CTRL_ETV_SHIFT         (16U)
/*! ETV - Enable Tag For VLAN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_CTRL_ETV(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_ETV_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_ETV_MASK)

#define EMAC_MAC_VLAN_TAG_CTRL_VTIM_MASK         (0x20000U)
#define EMAC_MAC_VLAN_TAG_CTRL_VTIM_SHIFT        (17U)
/*! VTIM - VLAN Tag Inverse Match Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_CTRL_VTIM(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_VTIM_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_VTIM_MASK)

#define EMAC_MAC_VLAN_TAG_CTRL_ESVL_MASK         (0x40000U)
#define EMAC_MAC_VLAN_TAG_CTRL_ESVL_SHIFT        (18U)
/*! ESVL - Enable S-VLAN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_CTRL_ESVL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_ESVL_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_ESVL_MASK)

#define EMAC_MAC_VLAN_TAG_CTRL_ERSVLM_MASK       (0x80000U)
#define EMAC_MAC_VLAN_TAG_CTRL_ERSVLM_SHIFT      (19U)
/*! ERSVLM - Enable Receive S-VLAN Match
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_CTRL_ERSVLM(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_ERSVLM_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_ERSVLM_MASK)

#define EMAC_MAC_VLAN_TAG_CTRL_DOVLTC_MASK       (0x100000U)
#define EMAC_MAC_VLAN_TAG_CTRL_DOVLTC_SHIFT      (20U)
/*! DOVLTC - Disable VLAN Type Check
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_VLAN_TAG_CTRL_DOVLTC(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_DOVLTC_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_DOVLTC_MASK)

#define EMAC_MAC_VLAN_TAG_CTRL_EVLS_MASK         (0x600000U)
#define EMAC_MAC_VLAN_TAG_CTRL_EVLS_SHIFT        (21U)
/*! EVLS - Enable VLAN Tag Stripping
 *  0b00..Do not strip
 *  0b01..Strip if VLAN filter passes
 *  0b10..Strip if VLAN filter fails
 *  0b11..Always strip
 */
#define EMAC_MAC_VLAN_TAG_CTRL_EVLS(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_EVLS_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_EVLS_MASK)

#define EMAC_MAC_VLAN_TAG_CTRL_EVLRXS_MASK       (0x1000000U)
#define EMAC_MAC_VLAN_TAG_CTRL_EVLRXS_SHIFT      (24U)
/*! EVLRXS - Enable VLAN Tag In Receive Status
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_CTRL_EVLRXS(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_EVLRXS_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_EVLRXS_MASK)

#define EMAC_MAC_VLAN_TAG_CTRL_VTHM_MASK         (0x2000000U)
#define EMAC_MAC_VLAN_TAG_CTRL_VTHM_SHIFT        (25U)
/*! VTHM - VLAN Tag Hash Table Match
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_CTRL_VTHM(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_VTHM_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_VTHM_MASK)

#define EMAC_MAC_VLAN_TAG_CTRL_EDVLP_MASK        (0x4000000U)
#define EMAC_MAC_VLAN_TAG_CTRL_EDVLP_SHIFT       (26U)
/*! EDVLP - Enable Double VLAN Processing
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_CTRL_EDVLP(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_EDVLP_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_EDVLP_MASK)

#define EMAC_MAC_VLAN_TAG_CTRL_ERIVLT_MASK       (0x8000000U)
#define EMAC_MAC_VLAN_TAG_CTRL_ERIVLT_SHIFT      (27U)
/*! ERIVLT - Enable Inner VLAN Tag Comparison
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_CTRL_ERIVLT(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_ERIVLT_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_ERIVLT_MASK)

#define EMAC_MAC_VLAN_TAG_CTRL_EIVLS_MASK        (0x30000000U)
#define EMAC_MAC_VLAN_TAG_CTRL_EIVLS_SHIFT       (28U)
/*! EIVLS - Enable Inner VLAN Tag Stripping
 *  0b00..Do not strip
 *  0b01..Strip if VLAN filter passes
 *  0b10..Strip if VLAN filter fails
 *  0b11..Always strip
 */
#define EMAC_MAC_VLAN_TAG_CTRL_EIVLS(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_EIVLS_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_EIVLS_MASK)

#define EMAC_MAC_VLAN_TAG_CTRL_EIVLRXS_MASK      (0x80000000U)
#define EMAC_MAC_VLAN_TAG_CTRL_EIVLRXS_SHIFT     (31U)
/*! EIVLRXS - Enable Inner VLAN Tag In Receive Status
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_CTRL_EIVLRXS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_CTRL_EIVLRXS_SHIFT)) & EMAC_MAC_VLAN_TAG_CTRL_EIVLRXS_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG - MAC VLAN Tag */
/*! @{ */

#define EMAC_MAC_VLAN_TAG_VL_MASK                (0xFFFFU)
#define EMAC_MAC_VLAN_TAG_VL_SHIFT               (0U)
/*! VL - VLAN Tag Identifier for Receive Packets */
#define EMAC_MAC_VLAN_TAG_VL(x)                  (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_VL_SHIFT)) & EMAC_MAC_VLAN_TAG_VL_MASK)

#define EMAC_MAC_VLAN_TAG_ETV_MASK               (0x10000U)
#define EMAC_MAC_VLAN_TAG_ETV_SHIFT              (16U)
/*! ETV - Enable Tag For VLAN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_ETV(x)                 (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_ETV_SHIFT)) & EMAC_MAC_VLAN_TAG_ETV_MASK)

#define EMAC_MAC_VLAN_TAG_VTIM_MASK              (0x20000U)
#define EMAC_MAC_VLAN_TAG_VTIM_SHIFT             (17U)
/*! VTIM - VLAN Tag Inverse Match Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_VTIM(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_VTIM_SHIFT)) & EMAC_MAC_VLAN_TAG_VTIM_MASK)

#define EMAC_MAC_VLAN_TAG_ESVL_MASK              (0x40000U)
#define EMAC_MAC_VLAN_TAG_ESVL_SHIFT             (18U)
/*! ESVL - Enable S-VLAN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_ESVL(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_ESVL_SHIFT)) & EMAC_MAC_VLAN_TAG_ESVL_MASK)

#define EMAC_MAC_VLAN_TAG_ERSVLM_MASK            (0x80000U)
#define EMAC_MAC_VLAN_TAG_ERSVLM_SHIFT           (19U)
/*! ERSVLM - Enable Receive S-VLAN Match
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_ERSVLM(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_ERSVLM_SHIFT)) & EMAC_MAC_VLAN_TAG_ERSVLM_MASK)

#define EMAC_MAC_VLAN_TAG_DOVLTC_MASK            (0x100000U)
#define EMAC_MAC_VLAN_TAG_DOVLTC_SHIFT           (20U)
/*! DOVLTC - Disable VLAN Type Check
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_VLAN_TAG_DOVLTC(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_DOVLTC_SHIFT)) & EMAC_MAC_VLAN_TAG_DOVLTC_MASK)

#define EMAC_MAC_VLAN_TAG_EVLS_MASK              (0x600000U)
#define EMAC_MAC_VLAN_TAG_EVLS_SHIFT             (21U)
/*! EVLS - Enable VLAN Tag Stripping
 *  0b00..Do not strip
 *  0b01..Strip if VLAN filter passes
 *  0b10..Strip if VLAN filter fails
 *  0b11..Always strip
 */
#define EMAC_MAC_VLAN_TAG_EVLS(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_EVLS_SHIFT)) & EMAC_MAC_VLAN_TAG_EVLS_MASK)

#define EMAC_MAC_VLAN_TAG_EVLRXS_MASK            (0x1000000U)
#define EMAC_MAC_VLAN_TAG_EVLRXS_SHIFT           (24U)
/*! EVLRXS - Enable VLAN Tag In Receive Status
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_EVLRXS(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_EVLRXS_SHIFT)) & EMAC_MAC_VLAN_TAG_EVLRXS_MASK)

#define EMAC_MAC_VLAN_TAG_VTHM_MASK              (0x2000000U)
#define EMAC_MAC_VLAN_TAG_VTHM_SHIFT             (25U)
/*! VTHM - VLAN Tag Hash Table Match
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_VTHM(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_VTHM_SHIFT)) & EMAC_MAC_VLAN_TAG_VTHM_MASK)

#define EMAC_MAC_VLAN_TAG_EDVLP_MASK             (0x4000000U)
#define EMAC_MAC_VLAN_TAG_EDVLP_SHIFT            (26U)
/*! EDVLP - Enable Double VLAN Processing
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_EDVLP(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_EDVLP_SHIFT)) & EMAC_MAC_VLAN_TAG_EDVLP_MASK)

#define EMAC_MAC_VLAN_TAG_ERIVLT_MASK            (0x8000000U)
#define EMAC_MAC_VLAN_TAG_ERIVLT_SHIFT           (27U)
/*! ERIVLT - Enable Inner VLAN Tag Comparison
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_ERIVLT(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_ERIVLT_SHIFT)) & EMAC_MAC_VLAN_TAG_ERIVLT_MASK)

#define EMAC_MAC_VLAN_TAG_EIVLS_MASK             (0x30000000U)
#define EMAC_MAC_VLAN_TAG_EIVLS_SHIFT            (28U)
/*! EIVLS - Enable Inner VLAN Tag Stripping
 *  0b00..Do not strip
 *  0b01..Strip if VLAN filter passes
 *  0b10..Strip if VLAN filter fails
 *  0b11..Always strip
 */
#define EMAC_MAC_VLAN_TAG_EIVLS(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_EIVLS_SHIFT)) & EMAC_MAC_VLAN_TAG_EIVLS_MASK)

#define EMAC_MAC_VLAN_TAG_EIVLRXS_MASK           (0x80000000U)
#define EMAC_MAC_VLAN_TAG_EIVLRXS_SHIFT          (31U)
/*! EIVLRXS - Enable Inner VLAN Tag In Receive Status
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_EIVLRXS(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_EIVLRXS_SHIFT)) & EMAC_MAC_VLAN_TAG_EIVLRXS_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_DATA - MAC VLAN Tag Data */
/*! @{ */

#define EMAC_MAC_VLAN_TAG_DATA_VID_MASK          (0xFFFFU)
#define EMAC_MAC_VLAN_TAG_DATA_VID_SHIFT         (0U)
/*! VID - VLAN Tag ID */
#define EMAC_MAC_VLAN_TAG_DATA_VID(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_DATA_VID_SHIFT)) & EMAC_MAC_VLAN_TAG_DATA_VID_MASK)

#define EMAC_MAC_VLAN_TAG_DATA_VEN_MASK          (0x10000U)
#define EMAC_MAC_VLAN_TAG_DATA_VEN_SHIFT         (16U)
/*! VEN - VLAN Tag Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_DATA_VEN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_DATA_VEN_SHIFT)) & EMAC_MAC_VLAN_TAG_DATA_VEN_MASK)

#define EMAC_MAC_VLAN_TAG_DATA_ETV_MASK          (0x20000U)
#define EMAC_MAC_VLAN_TAG_DATA_ETV_SHIFT         (17U)
/*! ETV - VLAN Comparison
 *  0b0..16-bit VLAN comparison
 *  0b1..12-bit VLAN comparison
 */
#define EMAC_MAC_VLAN_TAG_DATA_ETV(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_DATA_ETV_SHIFT)) & EMAC_MAC_VLAN_TAG_DATA_ETV_MASK)

#define EMAC_MAC_VLAN_TAG_DATA_DOVLTC_MASK       (0x40000U)
#define EMAC_MAC_VLAN_TAG_DATA_DOVLTC_SHIFT      (18U)
/*! DOVLTC - Disable VLAN Type Comparison
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_VLAN_TAG_DATA_DOVLTC(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_DATA_DOVLTC_SHIFT)) & EMAC_MAC_VLAN_TAG_DATA_DOVLTC_MASK)

#define EMAC_MAC_VLAN_TAG_DATA_ERSVLM_MASK       (0x80000U)
#define EMAC_MAC_VLAN_TAG_DATA_ERSVLM_SHIFT      (19U)
/*! ERSVLM - Enable S-VLAN Match
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_DATA_ERSVLM(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_DATA_ERSVLM_SHIFT)) & EMAC_MAC_VLAN_TAG_DATA_ERSVLM_MASK)

#define EMAC_MAC_VLAN_TAG_DATA_ERIVLT_MASK       (0x100000U)
#define EMAC_MAC_VLAN_TAG_DATA_ERIVLT_SHIFT      (20U)
/*! ERIVLT - Enable Inner VLAN Tag
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_DATA_ERIVLT(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_DATA_ERIVLT_SHIFT)) & EMAC_MAC_VLAN_TAG_DATA_ERIVLT_MASK)

#define EMAC_MAC_VLAN_TAG_DATA_DMACHEN_MASK      (0x1000000U)
#define EMAC_MAC_VLAN_TAG_DATA_DMACHEN_SHIFT     (24U)
/*! DMACHEN - DMA Channel Number Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_DATA_DMACHEN(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_DATA_DMACHEN_SHIFT)) & EMAC_MAC_VLAN_TAG_DATA_DMACHEN_MASK)

#define EMAC_MAC_VLAN_TAG_DATA_DMACHN_MASK       (0x2000000U)
#define EMAC_MAC_VLAN_TAG_DATA_DMACHN_SHIFT      (25U)
/*! DMACHN - DMA Channel Number */
#define EMAC_MAC_VLAN_TAG_DATA_DMACHN(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_DATA_DMACHN_SHIFT)) & EMAC_MAC_VLAN_TAG_DATA_DMACHN_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER0 - MAC VLAN Tag Filter 0 */
/*! @{ */

#define EMAC_MAC_VLAN_TAG_FILTER0_VID_MASK       (0xFFFFU)
#define EMAC_MAC_VLAN_TAG_FILTER0_VID_SHIFT      (0U)
/*! VID - VLAN Tag ID */
#define EMAC_MAC_VLAN_TAG_FILTER0_VID(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER0_VID_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER0_VID_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER0_VEN_MASK       (0x10000U)
#define EMAC_MAC_VLAN_TAG_FILTER0_VEN_SHIFT      (16U)
/*! VEN - VLAN Tag Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER0_VEN(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER0_VEN_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER0_VEN_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER0_ETV_MASK       (0x20000U)
#define EMAC_MAC_VLAN_TAG_FILTER0_ETV_SHIFT      (17U)
/*! ETV - VLAN Comparison
 *  0b0..16-bit VLAN comparison
 *  0b1..12-bit VLAN comparison
 */
#define EMAC_MAC_VLAN_TAG_FILTER0_ETV(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER0_ETV_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER0_ETV_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER0_DOVLTC_MASK    (0x40000U)
#define EMAC_MAC_VLAN_TAG_FILTER0_DOVLTC_SHIFT   (18U)
/*! DOVLTC - Disable VLAN Type Comparison
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER0_DOVLTC(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER0_DOVLTC_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER0_DOVLTC_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER0_ERSVLM_MASK    (0x80000U)
#define EMAC_MAC_VLAN_TAG_FILTER0_ERSVLM_SHIFT   (19U)
/*! ERSVLM - Enable S-VLAN Match
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER0_ERSVLM(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER0_ERSVLM_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER0_ERSVLM_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER0_ERIVLT_MASK    (0x100000U)
#define EMAC_MAC_VLAN_TAG_FILTER0_ERIVLT_SHIFT   (20U)
/*! ERIVLT - Enable Inner VLAN Tag
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER0_ERIVLT(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER0_ERIVLT_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER0_ERIVLT_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER0_DMACHEN_MASK   (0x1000000U)
#define EMAC_MAC_VLAN_TAG_FILTER0_DMACHEN_SHIFT  (24U)
/*! DMACHEN - DMA Channel Number Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER0_DMACHEN(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER0_DMACHEN_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER0_DMACHEN_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER0_DMACHN_MASK    (0x2000000U)
#define EMAC_MAC_VLAN_TAG_FILTER0_DMACHN_SHIFT   (25U)
/*! DMACHN - DMA Channel Number */
#define EMAC_MAC_VLAN_TAG_FILTER0_DMACHN(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER0_DMACHN_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER0_DMACHN_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER1 - MAC VLAN Tag Filter 1 */
/*! @{ */

#define EMAC_MAC_VLAN_TAG_FILTER1_VID_MASK       (0xFFFFU)
#define EMAC_MAC_VLAN_TAG_FILTER1_VID_SHIFT      (0U)
/*! VID - VLAN Tag ID */
#define EMAC_MAC_VLAN_TAG_FILTER1_VID(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER1_VID_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER1_VID_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER1_VEN_MASK       (0x10000U)
#define EMAC_MAC_VLAN_TAG_FILTER1_VEN_SHIFT      (16U)
/*! VEN - VLAN Tag Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER1_VEN(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER1_VEN_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER1_VEN_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER1_ETV_MASK       (0x20000U)
#define EMAC_MAC_VLAN_TAG_FILTER1_ETV_SHIFT      (17U)
/*! ETV - VLAN Comparison
 *  0b0..16-bit VLAN comparison
 *  0b1..12-bit VLAN comparison
 */
#define EMAC_MAC_VLAN_TAG_FILTER1_ETV(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER1_ETV_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER1_ETV_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER1_DOVLTC_MASK    (0x40000U)
#define EMAC_MAC_VLAN_TAG_FILTER1_DOVLTC_SHIFT   (18U)
/*! DOVLTC - Disable VLAN Type Comparison
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER1_DOVLTC(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER1_DOVLTC_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER1_DOVLTC_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER1_ERSVLM_MASK    (0x80000U)
#define EMAC_MAC_VLAN_TAG_FILTER1_ERSVLM_SHIFT   (19U)
/*! ERSVLM - Enable S-VLAN Match
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER1_ERSVLM(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER1_ERSVLM_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER1_ERSVLM_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER1_ERIVLT_MASK    (0x100000U)
#define EMAC_MAC_VLAN_TAG_FILTER1_ERIVLT_SHIFT   (20U)
/*! ERIVLT - Enable Inner VLAN Tag
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER1_ERIVLT(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER1_ERIVLT_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER1_ERIVLT_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER1_DMACHEN_MASK   (0x1000000U)
#define EMAC_MAC_VLAN_TAG_FILTER1_DMACHEN_SHIFT  (24U)
/*! DMACHEN - DMA Channel Number Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER1_DMACHEN(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER1_DMACHEN_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER1_DMACHEN_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER1_DMACHN_MASK    (0x2000000U)
#define EMAC_MAC_VLAN_TAG_FILTER1_DMACHN_SHIFT   (25U)
/*! DMACHN - DMA Channel Number */
#define EMAC_MAC_VLAN_TAG_FILTER1_DMACHN(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER1_DMACHN_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER1_DMACHN_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER2 - MAC VLAN Tag Filter 2 */
/*! @{ */

#define EMAC_MAC_VLAN_TAG_FILTER2_VID_MASK       (0xFFFFU)
#define EMAC_MAC_VLAN_TAG_FILTER2_VID_SHIFT      (0U)
/*! VID - VLAN Tag ID */
#define EMAC_MAC_VLAN_TAG_FILTER2_VID(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER2_VID_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER2_VID_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER2_VEN_MASK       (0x10000U)
#define EMAC_MAC_VLAN_TAG_FILTER2_VEN_SHIFT      (16U)
/*! VEN - VLAN Tag Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER2_VEN(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER2_VEN_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER2_VEN_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER2_ETV_MASK       (0x20000U)
#define EMAC_MAC_VLAN_TAG_FILTER2_ETV_SHIFT      (17U)
/*! ETV - VLAN Comparison
 *  0b0..16-bit VLAN comparison
 *  0b1..12-bit VLAN comparison
 */
#define EMAC_MAC_VLAN_TAG_FILTER2_ETV(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER2_ETV_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER2_ETV_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER2_DOVLTC_MASK    (0x40000U)
#define EMAC_MAC_VLAN_TAG_FILTER2_DOVLTC_SHIFT   (18U)
/*! DOVLTC - Disable VLAN Type Comparison
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER2_DOVLTC(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER2_DOVLTC_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER2_DOVLTC_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER2_ERSVLM_MASK    (0x80000U)
#define EMAC_MAC_VLAN_TAG_FILTER2_ERSVLM_SHIFT   (19U)
/*! ERSVLM - Enable S-VLAN Match
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER2_ERSVLM(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER2_ERSVLM_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER2_ERSVLM_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER2_ERIVLT_MASK    (0x100000U)
#define EMAC_MAC_VLAN_TAG_FILTER2_ERIVLT_SHIFT   (20U)
/*! ERIVLT - Enable Inner VLAN Tag
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER2_ERIVLT(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER2_ERIVLT_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER2_ERIVLT_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER2_DMACHEN_MASK   (0x1000000U)
#define EMAC_MAC_VLAN_TAG_FILTER2_DMACHEN_SHIFT  (24U)
/*! DMACHEN - DMA Channel Number Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER2_DMACHEN(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER2_DMACHEN_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER2_DMACHEN_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER2_DMACHN_MASK    (0x2000000U)
#define EMAC_MAC_VLAN_TAG_FILTER2_DMACHN_SHIFT   (25U)
/*! DMACHN - DMA Channel Number */
#define EMAC_MAC_VLAN_TAG_FILTER2_DMACHN(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER2_DMACHN_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER2_DMACHN_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER3 - MAC VLAN Tag Filter 3 */
/*! @{ */

#define EMAC_MAC_VLAN_TAG_FILTER3_VID_MASK       (0xFFFFU)
#define EMAC_MAC_VLAN_TAG_FILTER3_VID_SHIFT      (0U)
/*! VID - VLAN Tag ID */
#define EMAC_MAC_VLAN_TAG_FILTER3_VID(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER3_VID_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER3_VID_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER3_VEN_MASK       (0x10000U)
#define EMAC_MAC_VLAN_TAG_FILTER3_VEN_SHIFT      (16U)
/*! VEN - VLAN Tag Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER3_VEN(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER3_VEN_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER3_VEN_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER3_ETV_MASK       (0x20000U)
#define EMAC_MAC_VLAN_TAG_FILTER3_ETV_SHIFT      (17U)
/*! ETV - VLAN Comparison
 *  0b0..16-bit VLAN comparison
 *  0b1..12-bit VLAN comparison
 */
#define EMAC_MAC_VLAN_TAG_FILTER3_ETV(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER3_ETV_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER3_ETV_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER3_DOVLTC_MASK    (0x40000U)
#define EMAC_MAC_VLAN_TAG_FILTER3_DOVLTC_SHIFT   (18U)
/*! DOVLTC - Disable VLAN Type Comparison
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER3_DOVLTC(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER3_DOVLTC_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER3_DOVLTC_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER3_ERSVLM_MASK    (0x80000U)
#define EMAC_MAC_VLAN_TAG_FILTER3_ERSVLM_SHIFT   (19U)
/*! ERSVLM - Enable S-VLAN Match
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER3_ERSVLM(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER3_ERSVLM_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER3_ERSVLM_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER3_ERIVLT_MASK    (0x100000U)
#define EMAC_MAC_VLAN_TAG_FILTER3_ERIVLT_SHIFT   (20U)
/*! ERIVLT - Enable Inner VLAN Tag
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER3_ERIVLT(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER3_ERIVLT_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER3_ERIVLT_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER3_DMACHEN_MASK   (0x1000000U)
#define EMAC_MAC_VLAN_TAG_FILTER3_DMACHEN_SHIFT  (24U)
/*! DMACHEN - DMA Channel Number Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_TAG_FILTER3_DMACHEN(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER3_DMACHEN_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER3_DMACHEN_MASK)

#define EMAC_MAC_VLAN_TAG_FILTER3_DMACHN_MASK    (0x2000000U)
#define EMAC_MAC_VLAN_TAG_FILTER3_DMACHN_SHIFT   (25U)
/*! DMACHN - DMA Channel Number */
#define EMAC_MAC_VLAN_TAG_FILTER3_DMACHN(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_TAG_FILTER3_DMACHN_SHIFT)) & EMAC_MAC_VLAN_TAG_FILTER3_DMACHN_MASK)
/*! @} */

/*! @name MAC_VLAN_HASH_TABLE - MAC VLAN Hash Table */
/*! @{ */

#define EMAC_MAC_VLAN_HASH_TABLE_VLHT_MASK       (0xFFFFU)
#define EMAC_MAC_VLAN_HASH_TABLE_VLHT_SHIFT      (0U)
/*! VLHT - VLAN Hash Table */
#define EMAC_MAC_VLAN_HASH_TABLE_VLHT(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_HASH_TABLE_VLHT_SHIFT)) & EMAC_MAC_VLAN_HASH_TABLE_VLHT_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL0 - MAC VLAN Inclusion 0 */
/*! @{ */

#define EMAC_MAC_VLAN_INCL0_VLT_MASK             (0xFFFFU)
#define EMAC_MAC_VLAN_INCL0_VLT_SHIFT            (0U)
/*! VLT - VLAN Tag for Transmit Packets */
#define EMAC_MAC_VLAN_INCL0_VLT(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL0_VLT_SHIFT)) & EMAC_MAC_VLAN_INCL0_VLT_MASK)

#define EMAC_MAC_VLAN_INCL0_CSVL_MASK            (0x80000U)
#define EMAC_MAC_VLAN_INCL0_CSVL_SHIFT           (19U)
/*! CSVL - C-VLAN or S-VLAN
 *  0b0..C-VLAN type (0x8100) is inserted
 *  0b1..S-VLAN type (0x88A8) is inserted
 */
#define EMAC_MAC_VLAN_INCL0_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL0_CSVL_SHIFT)) & EMAC_MAC_VLAN_INCL0_CSVL_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL1 - MAC VLAN Inclusion 1 */
/*! @{ */

#define EMAC_MAC_VLAN_INCL1_VLT_MASK             (0xFFFFU)
#define EMAC_MAC_VLAN_INCL1_VLT_SHIFT            (0U)
/*! VLT - VLAN Tag for Transmit Packets */
#define EMAC_MAC_VLAN_INCL1_VLT(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL1_VLT_SHIFT)) & EMAC_MAC_VLAN_INCL1_VLT_MASK)

#define EMAC_MAC_VLAN_INCL1_CSVL_MASK            (0x80000U)
#define EMAC_MAC_VLAN_INCL1_CSVL_SHIFT           (19U)
/*! CSVL - C-VLAN or S-VLAN
 *  0b0..C-VLAN type (0x8100) is inserted
 *  0b1..S-VLAN type (0x88A8) is inserted
 */
#define EMAC_MAC_VLAN_INCL1_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL1_CSVL_SHIFT)) & EMAC_MAC_VLAN_INCL1_CSVL_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL2 - MAC VLAN Inclusion 2 */
/*! @{ */

#define EMAC_MAC_VLAN_INCL2_VLT_MASK             (0xFFFFU)
#define EMAC_MAC_VLAN_INCL2_VLT_SHIFT            (0U)
/*! VLT - VLAN Tag for Transmit Packets */
#define EMAC_MAC_VLAN_INCL2_VLT(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL2_VLT_SHIFT)) & EMAC_MAC_VLAN_INCL2_VLT_MASK)

#define EMAC_MAC_VLAN_INCL2_CSVL_MASK            (0x80000U)
#define EMAC_MAC_VLAN_INCL2_CSVL_SHIFT           (19U)
/*! CSVL - C-VLAN or S-VLAN
 *  0b0..C-VLAN type (0x8100) is inserted
 *  0b1..S-VLAN type (0x88A8) is inserted
 */
#define EMAC_MAC_VLAN_INCL2_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL2_CSVL_SHIFT)) & EMAC_MAC_VLAN_INCL2_CSVL_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL3 - MAC VLAN Inclusion 3 */
/*! @{ */

#define EMAC_MAC_VLAN_INCL3_VLT_MASK             (0xFFFFU)
#define EMAC_MAC_VLAN_INCL3_VLT_SHIFT            (0U)
/*! VLT - VLAN Tag for Transmit Packets */
#define EMAC_MAC_VLAN_INCL3_VLT(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL3_VLT_SHIFT)) & EMAC_MAC_VLAN_INCL3_VLT_MASK)

#define EMAC_MAC_VLAN_INCL3_CSVL_MASK            (0x80000U)
#define EMAC_MAC_VLAN_INCL3_CSVL_SHIFT           (19U)
/*! CSVL - C-VLAN or S-VLAN
 *  0b0..C-VLAN type (0x8100) is inserted
 *  0b1..S-VLAN type (0x88A8) is inserted
 */
#define EMAC_MAC_VLAN_INCL3_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL3_CSVL_SHIFT)) & EMAC_MAC_VLAN_INCL3_CSVL_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL4 - MAC VLAN Inclusion 4 */
/*! @{ */

#define EMAC_MAC_VLAN_INCL4_VLT_MASK             (0xFFFFU)
#define EMAC_MAC_VLAN_INCL4_VLT_SHIFT            (0U)
/*! VLT - VLAN Tag for Transmit Packets */
#define EMAC_MAC_VLAN_INCL4_VLT(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL4_VLT_SHIFT)) & EMAC_MAC_VLAN_INCL4_VLT_MASK)

#define EMAC_MAC_VLAN_INCL4_CSVL_MASK            (0x80000U)
#define EMAC_MAC_VLAN_INCL4_CSVL_SHIFT           (19U)
/*! CSVL - C-VLAN or S-VLAN
 *  0b0..C-VLAN type (0x8100) is inserted
 *  0b1..S-VLAN type (0x88A8) is inserted
 */
#define EMAC_MAC_VLAN_INCL4_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL4_CSVL_SHIFT)) & EMAC_MAC_VLAN_INCL4_CSVL_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL5 - MAC VLAN Inclusion 5 */
/*! @{ */

#define EMAC_MAC_VLAN_INCL5_VLT_MASK             (0xFFFFU)
#define EMAC_MAC_VLAN_INCL5_VLT_SHIFT            (0U)
/*! VLT - VLAN Tag for Transmit Packets */
#define EMAC_MAC_VLAN_INCL5_VLT(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL5_VLT_SHIFT)) & EMAC_MAC_VLAN_INCL5_VLT_MASK)

#define EMAC_MAC_VLAN_INCL5_CSVL_MASK            (0x80000U)
#define EMAC_MAC_VLAN_INCL5_CSVL_SHIFT           (19U)
/*! CSVL - C-VLAN or S-VLAN
 *  0b0..C-VLAN type (0x8100) is inserted
 *  0b1..S-VLAN type (0x88A8) is inserted
 */
#define EMAC_MAC_VLAN_INCL5_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL5_CSVL_SHIFT)) & EMAC_MAC_VLAN_INCL5_CSVL_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL6 - MAC VLAN Inclusion 6 */
/*! @{ */

#define EMAC_MAC_VLAN_INCL6_VLT_MASK             (0xFFFFU)
#define EMAC_MAC_VLAN_INCL6_VLT_SHIFT            (0U)
/*! VLT - VLAN Tag for Transmit Packets */
#define EMAC_MAC_VLAN_INCL6_VLT(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL6_VLT_SHIFT)) & EMAC_MAC_VLAN_INCL6_VLT_MASK)

#define EMAC_MAC_VLAN_INCL6_CSVL_MASK            (0x80000U)
#define EMAC_MAC_VLAN_INCL6_CSVL_SHIFT           (19U)
/*! CSVL - C-VLAN or S-VLAN
 *  0b0..C-VLAN type (0x8100) is inserted
 *  0b1..S-VLAN type (0x88A8) is inserted
 */
#define EMAC_MAC_VLAN_INCL6_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL6_CSVL_SHIFT)) & EMAC_MAC_VLAN_INCL6_CSVL_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL7 - MAC VLAN Inclusion 7 */
/*! @{ */

#define EMAC_MAC_VLAN_INCL7_VLT_MASK             (0xFFFFU)
#define EMAC_MAC_VLAN_INCL7_VLT_SHIFT            (0U)
/*! VLT - VLAN Tag for Transmit Packets */
#define EMAC_MAC_VLAN_INCL7_VLT(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL7_VLT_SHIFT)) & EMAC_MAC_VLAN_INCL7_VLT_MASK)

#define EMAC_MAC_VLAN_INCL7_CSVL_MASK            (0x80000U)
#define EMAC_MAC_VLAN_INCL7_CSVL_SHIFT           (19U)
/*! CSVL - C-VLAN or S-VLAN
 *  0b0..C-VLAN type (0x8100) is inserted
 *  0b1..S-VLAN type (0x88A8) is inserted
 */
#define EMAC_MAC_VLAN_INCL7_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL7_CSVL_SHIFT)) & EMAC_MAC_VLAN_INCL7_CSVL_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL - MAC VLAN Inclusion Or Replacement */
/*! @{ */

#define EMAC_MAC_VLAN_INCL_VLT_MASK              (0xFFFFU)
#define EMAC_MAC_VLAN_INCL_VLT_SHIFT             (0U)
/*! VLT - VLAN Tag For Transmit Packets */
#define EMAC_MAC_VLAN_INCL_VLT(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL_VLT_SHIFT)) & EMAC_MAC_VLAN_INCL_VLT_MASK)

#define EMAC_MAC_VLAN_INCL_VLC_MASK              (0x30000U)
#define EMAC_MAC_VLAN_INCL_VLC_SHIFT             (16U)
/*! VLC - VLAN Tag Control
 *  0b00..No VLAN tag deletion, insertion, or replacement
 *  0b01..VLAN tag deletion
 *  0b10..VLAN tag insertion
 *  0b11..VLAN tag replacement
 */
#define EMAC_MAC_VLAN_INCL_VLC(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL_VLC_SHIFT)) & EMAC_MAC_VLAN_INCL_VLC_MASK)

#define EMAC_MAC_VLAN_INCL_VLP_MASK              (0x40000U)
#define EMAC_MAC_VLAN_INCL_VLP_SHIFT             (18U)
/*! VLP - VLAN Priority Control
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_INCL_VLP(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL_VLP_SHIFT)) & EMAC_MAC_VLAN_INCL_VLP_MASK)

#define EMAC_MAC_VLAN_INCL_CSVL_MASK             (0x80000U)
#define EMAC_MAC_VLAN_INCL_CSVL_SHIFT            (19U)
/*! CSVL - C-VLAN Or S-VLAN
 *  0b0..C-VLAN
 *  0b1..S-VLAN
 */
#define EMAC_MAC_VLAN_INCL_CSVL(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL_CSVL_SHIFT)) & EMAC_MAC_VLAN_INCL_CSVL_MASK)

#define EMAC_MAC_VLAN_INCL_VLTI_MASK             (0x100000U)
#define EMAC_MAC_VLAN_INCL_VLTI_SHIFT            (20U)
/*! VLTI - VLAN Tag Input
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_INCL_VLTI(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL_VLTI_SHIFT)) & EMAC_MAC_VLAN_INCL_VLTI_MASK)

#define EMAC_MAC_VLAN_INCL_CBTI_MASK             (0x200000U)
#define EMAC_MAC_VLAN_INCL_CBTI_SHIFT            (21U)
/*! CBTI - Channel-Based Tag Insertion
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_VLAN_INCL_CBTI(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL_CBTI_SHIFT)) & EMAC_MAC_VLAN_INCL_CBTI_MASK)

#define EMAC_MAC_VLAN_INCL_ADDR_MASK             (0x1000000U)
#define EMAC_MAC_VLAN_INCL_ADDR_SHIFT            (24U)
/*! ADDR - Address */
#define EMAC_MAC_VLAN_INCL_ADDR(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL_ADDR_SHIFT)) & EMAC_MAC_VLAN_INCL_ADDR_MASK)

#define EMAC_MAC_VLAN_INCL_RDWR_MASK             (0x40000000U)
#define EMAC_MAC_VLAN_INCL_RDWR_SHIFT            (30U)
/*! RDWR - Read Write Control
 *  0b0..Read operation of indirect access
 *  0b1..Write operation of indirect access
 */
#define EMAC_MAC_VLAN_INCL_RDWR(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL_RDWR_SHIFT)) & EMAC_MAC_VLAN_INCL_RDWR_MASK)

#define EMAC_MAC_VLAN_INCL_BUSY_MASK             (0x80000000U)
#define EMAC_MAC_VLAN_INCL_BUSY_SHIFT            (31U)
/*! BUSY - Busy
 *  0b0..Busy status not detected
 *  0b1..Busy status detected
 */
#define EMAC_MAC_VLAN_INCL_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VLAN_INCL_BUSY_SHIFT)) & EMAC_MAC_VLAN_INCL_BUSY_MASK)
/*! @} */

/*! @name MAC_INNER_VLAN_INCL - Inner VLAN Tag Inclusion Or Replacement */
/*! @{ */

#define EMAC_MAC_INNER_VLAN_INCL_VLT_MASK        (0xFFFFU)
#define EMAC_MAC_INNER_VLAN_INCL_VLT_SHIFT       (0U)
/*! VLT - VLAN Tag For Transmit Packets */
#define EMAC_MAC_INNER_VLAN_INCL_VLT(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INNER_VLAN_INCL_VLT_SHIFT)) & EMAC_MAC_INNER_VLAN_INCL_VLT_MASK)

#define EMAC_MAC_INNER_VLAN_INCL_VLC_MASK        (0x30000U)
#define EMAC_MAC_INNER_VLAN_INCL_VLC_SHIFT       (16U)
/*! VLC - VLAN Tag Control in Transmit Packets
 *  0b00..No VLAN tag deletion, insertion, or replacement
 *  0b01..VLAN tag deletion
 *  0b10..VLAN tag insertion
 *  0b11..VLAN tag replacement
 */
#define EMAC_MAC_INNER_VLAN_INCL_VLC(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INNER_VLAN_INCL_VLC_SHIFT)) & EMAC_MAC_INNER_VLAN_INCL_VLC_MASK)

#define EMAC_MAC_INNER_VLAN_INCL_VLP_MASK        (0x40000U)
#define EMAC_MAC_INNER_VLAN_INCL_VLP_SHIFT       (18U)
/*! VLP - VLAN Priority Control
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_INNER_VLAN_INCL_VLP(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INNER_VLAN_INCL_VLP_SHIFT)) & EMAC_MAC_INNER_VLAN_INCL_VLP_MASK)

#define EMAC_MAC_INNER_VLAN_INCL_CSVL_MASK       (0x80000U)
#define EMAC_MAC_INNER_VLAN_INCL_CSVL_SHIFT      (19U)
/*! CSVL - C-VLAN Or S-VLAN
 *  0b0..C-VLAN type (8100h)
 *  0b1..S-VLAN type (88A8h)
 */
#define EMAC_MAC_INNER_VLAN_INCL_CSVL(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INNER_VLAN_INCL_CSVL_SHIFT)) & EMAC_MAC_INNER_VLAN_INCL_CSVL_MASK)

#define EMAC_MAC_INNER_VLAN_INCL_VLTI_MASK       (0x100000U)
#define EMAC_MAC_INNER_VLAN_INCL_VLTI_SHIFT      (20U)
/*! VLTI - VLAN Tag Input
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_INNER_VLAN_INCL_VLTI(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INNER_VLAN_INCL_VLTI_SHIFT)) & EMAC_MAC_INNER_VLAN_INCL_VLTI_MASK)
/*! @} */

/*! @name MAC_Q0_TX_FLOW_CTRL - MAC Q0 Tx Flow Control */
/*! @{ */

#define EMAC_MAC_Q0_TX_FLOW_CTRL_FCB_BPA_MASK    (0x1U)
#define EMAC_MAC_Q0_TX_FLOW_CTRL_FCB_BPA_SHIFT   (0U)
/*! FCB_BPA - Flow Control Busy Or Backpressure Activate
 *  0b0..Flow control busy or backpressure activate is disabled
 *  0b1..Flow control busy or backpressure activate is enabled
 */
#define EMAC_MAC_Q0_TX_FLOW_CTRL_FCB_BPA(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_Q0_TX_FLOW_CTRL_FCB_BPA_SHIFT)) & EMAC_MAC_Q0_TX_FLOW_CTRL_FCB_BPA_MASK)

#define EMAC_MAC_Q0_TX_FLOW_CTRL_TFE_MASK        (0x2U)
#define EMAC_MAC_Q0_TX_FLOW_CTRL_TFE_SHIFT       (1U)
/*! TFE - Transmit Flow Control Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_Q0_TX_FLOW_CTRL_TFE(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_Q0_TX_FLOW_CTRL_TFE_SHIFT)) & EMAC_MAC_Q0_TX_FLOW_CTRL_TFE_MASK)

#define EMAC_MAC_Q0_TX_FLOW_CTRL_PLT_MASK        (0x70U)
#define EMAC_MAC_Q0_TX_FLOW_CTRL_PLT_SHIFT       (4U)
/*! PLT - Pause Low Threshold
 *  0b000..Pause time minus 4 slot times (PT is 4 slot times)
 *  0b001..Pause time minus 28 slot times (PT is 28 slot times)
 *  0b010..Pause time minus 36 slot times (PT is 36 slot times)
 *  0b011..Pause time minus 144 slot times (PT is 144 slot times)
 *  0b100..Pause time minus 256 slot times (PT is 256 slot times)
 *  0b101..Pause time minus 512 slot times (PT is 512 slot times)
 *  0b110..Reserved
 */
#define EMAC_MAC_Q0_TX_FLOW_CTRL_PLT(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_Q0_TX_FLOW_CTRL_PLT_SHIFT)) & EMAC_MAC_Q0_TX_FLOW_CTRL_PLT_MASK)

#define EMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ_MASK       (0x80U)
#define EMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ_SHIFT      (7U)
/*! DZPQ - Disable Zero-Quanta Pause
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ_SHIFT)) & EMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ_MASK)

#define EMAC_MAC_Q0_TX_FLOW_CTRL_PT_MASK         (0xFFFF0000U)
#define EMAC_MAC_Q0_TX_FLOW_CTRL_PT_SHIFT        (16U)
/*! PT - Pause Time */
#define EMAC_MAC_Q0_TX_FLOW_CTRL_PT(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_Q0_TX_FLOW_CTRL_PT_SHIFT)) & EMAC_MAC_Q0_TX_FLOW_CTRL_PT_MASK)
/*! @} */

/*! @name MAC_RX_FLOW_CTRL - MAC Receive Flow Control */
/*! @{ */

#define EMAC_MAC_RX_FLOW_CTRL_RFE_MASK           (0x1U)
#define EMAC_MAC_RX_FLOW_CTRL_RFE_SHIFT          (0U)
/*! RFE - Receive Flow Control Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_RX_FLOW_CTRL_RFE(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RX_FLOW_CTRL_RFE_SHIFT)) & EMAC_MAC_RX_FLOW_CTRL_RFE_MASK)

#define EMAC_MAC_RX_FLOW_CTRL_UP_MASK            (0x2U)
#define EMAC_MAC_RX_FLOW_CTRL_UP_SHIFT           (1U)
/*! UP - Unicast Pause Packet Detect
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_RX_FLOW_CTRL_UP(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RX_FLOW_CTRL_UP_SHIFT)) & EMAC_MAC_RX_FLOW_CTRL_UP_MASK)
/*! @} */

/*! @name MAC_RXQ_CTRL4 - MAC RxQ Control 4 */
/*! @{ */

#define EMAC_MAC_RXQ_CTRL4_UFFQE_MASK            (0x1U)
#define EMAC_MAC_RXQ_CTRL4_UFFQE_SHIFT           (0U)
/*! UFFQE - Unicast Address Filter Fail Packets Queuing Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_RXQ_CTRL4_UFFQE(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL4_UFFQE_SHIFT)) & EMAC_MAC_RXQ_CTRL4_UFFQE_MASK)

#define EMAC_MAC_RXQ_CTRL4_UFFQ_MASK             (0x2U)
#define EMAC_MAC_RXQ_CTRL4_UFFQ_SHIFT            (1U)
/*! UFFQ - Unicast Address Filter Fail Packets Queue */
#define EMAC_MAC_RXQ_CTRL4_UFFQ(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL4_UFFQ_SHIFT)) & EMAC_MAC_RXQ_CTRL4_UFFQ_MASK)

#define EMAC_MAC_RXQ_CTRL4_MFFQE_MASK            (0x100U)
#define EMAC_MAC_RXQ_CTRL4_MFFQE_SHIFT           (8U)
/*! MFFQE - Multicast Address Filter Fail Packets Queuing Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_RXQ_CTRL4_MFFQE(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL4_MFFQE_SHIFT)) & EMAC_MAC_RXQ_CTRL4_MFFQE_MASK)

#define EMAC_MAC_RXQ_CTRL4_MFFQ_MASK             (0x200U)
#define EMAC_MAC_RXQ_CTRL4_MFFQ_SHIFT            (9U)
/*! MFFQ - Multicast Address Filter Fail Packets Queue */
#define EMAC_MAC_RXQ_CTRL4_MFFQ(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL4_MFFQ_SHIFT)) & EMAC_MAC_RXQ_CTRL4_MFFQ_MASK)

#define EMAC_MAC_RXQ_CTRL4_VFFQE_MASK            (0x10000U)
#define EMAC_MAC_RXQ_CTRL4_VFFQE_SHIFT           (16U)
/*! VFFQE - VLAN Tag Filter Fail Packets Queuing Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_RXQ_CTRL4_VFFQE(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL4_VFFQE_SHIFT)) & EMAC_MAC_RXQ_CTRL4_VFFQE_MASK)

#define EMAC_MAC_RXQ_CTRL4_VFFQ_MASK             (0x20000U)
#define EMAC_MAC_RXQ_CTRL4_VFFQ_SHIFT            (17U)
/*! VFFQ - VLAN Tag Filter Fail Packets Queue */
#define EMAC_MAC_RXQ_CTRL4_VFFQ(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL4_VFFQ_SHIFT)) & EMAC_MAC_RXQ_CTRL4_VFFQ_MASK)
/*! @} */

/*! @name MAC_RXQ_CTRL0 - MAC RxQ Control 0 */
/*! @{ */

#define EMAC_MAC_RXQ_CTRL0_RXQ0EN_MASK           (0x3U)
#define EMAC_MAC_RXQ_CTRL0_RXQ0EN_SHIFT          (0U)
/*! RXQ0EN - Receive Queue 0 Enable
 *  0b00..Queue not enabled
 *  0b01..Queue enabled for AV
 *  0b10..Queue enabled for DCB/generic
 *  0b11..Reserved
 */
#define EMAC_MAC_RXQ_CTRL0_RXQ0EN(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL0_RXQ0EN_SHIFT)) & EMAC_MAC_RXQ_CTRL0_RXQ0EN_MASK)

#define EMAC_MAC_RXQ_CTRL0_RXQ1EN_MASK           (0xCU)
#define EMAC_MAC_RXQ_CTRL0_RXQ1EN_SHIFT          (2U)
/*! RXQ1EN - Receive Queue 1 Enable
 *  0b00..Queue not enabled
 *  0b01..Queue enabled for AV
 *  0b10..Queue enabled for DCB/generic
 *  0b11..Reserved
 */
#define EMAC_MAC_RXQ_CTRL0_RXQ1EN(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL0_RXQ1EN_SHIFT)) & EMAC_MAC_RXQ_CTRL0_RXQ1EN_MASK)
/*! @} */

/*! @name MAC_RXQ_CTRL1 - Receive Queue Control 1 */
/*! @{ */

#define EMAC_MAC_RXQ_CTRL1_AVCPQ_MASK            (0x7U)
#define EMAC_MAC_RXQ_CTRL1_AVCPQ_SHIFT           (0U)
/*! AVCPQ - AV Untagged Control Packets Queue
 *  0b000..Receive queue 0
 *  0b001..Receive queue 1
 *  0b010..Receive queue 2
 *  0b011..Receive queue 3
 *  0b100..Receive queue 4
 *  0b101..Receive queue 5
 *  0b110..Receive queue 6
 *  0b111..Receive queue 7
 */
#define EMAC_MAC_RXQ_CTRL1_AVCPQ(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL1_AVCPQ_SHIFT)) & EMAC_MAC_RXQ_CTRL1_AVCPQ_MASK)

#define EMAC_MAC_RXQ_CTRL1_PTPQ_MASK             (0x70U)
#define EMAC_MAC_RXQ_CTRL1_PTPQ_SHIFT            (4U)
/*! PTPQ - PTP Packets Queue
 *  0b000..Receive queue 0
 *  0b001..Receive queue 1
 *  0b010..Receive queue 2
 *  0b011..Receive queue 3
 *  0b100..Receive queue 4
 *  0b101..Receive queue 5
 *  0b110..Receive queue 6
 *  0b111..Receive queue 7
 */
#define EMAC_MAC_RXQ_CTRL1_PTPQ(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL1_PTPQ_SHIFT)) & EMAC_MAC_RXQ_CTRL1_PTPQ_MASK)

#define EMAC_MAC_RXQ_CTRL1_UPQ_MASK              (0x7000U)
#define EMAC_MAC_RXQ_CTRL1_UPQ_SHIFT             (12U)
/*! UPQ - Untagged Packet Queue
 *  0b000..Receive queue 0
 *  0b001..Receive queue 1
 *  0b010..Receive queue 2
 *  0b011..Receive queue 3
 *  0b100..Receive queue 4
 *  0b101..Receive queue 5
 *  0b110..Receive queue 6
 *  0b111..Receive queue 7
 */
#define EMAC_MAC_RXQ_CTRL1_UPQ(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL1_UPQ_SHIFT)) & EMAC_MAC_RXQ_CTRL1_UPQ_MASK)

#define EMAC_MAC_RXQ_CTRL1_MCBCQ_MASK            (0x70000U)
#define EMAC_MAC_RXQ_CTRL1_MCBCQ_SHIFT           (16U)
/*! MCBCQ - Multicast And Broadcast Queue
 *  0b000..Receive queue 0
 *  0b001..Receive queue 1
 *  0b010..Receive queue 2
 *  0b011..Receive queue 3
 *  0b100..Receive queue 4
 *  0b101..Receive queue 5
 *  0b110..Receive queue 6
 *  0b111..Receive queue 7
 */
#define EMAC_MAC_RXQ_CTRL1_MCBCQ(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL1_MCBCQ_SHIFT)) & EMAC_MAC_RXQ_CTRL1_MCBCQ_MASK)

#define EMAC_MAC_RXQ_CTRL1_MCBCQEN_MASK          (0x100000U)
#define EMAC_MAC_RXQ_CTRL1_MCBCQEN_SHIFT         (20U)
/*! MCBCQEN - Multicast And Broadcast Queue Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_RXQ_CTRL1_MCBCQEN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL1_MCBCQEN_SHIFT)) & EMAC_MAC_RXQ_CTRL1_MCBCQEN_MASK)

#define EMAC_MAC_RXQ_CTRL1_TACPQE_MASK           (0x200000U)
#define EMAC_MAC_RXQ_CTRL1_TACPQE_SHIFT          (21U)
/*! TACPQE - Tagged AV Control Packets Queuing Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_RXQ_CTRL1_TACPQE(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL1_TACPQE_SHIFT)) & EMAC_MAC_RXQ_CTRL1_TACPQE_MASK)

#define EMAC_MAC_RXQ_CTRL1_TPQC_MASK             (0xC00000U)
#define EMAC_MAC_RXQ_CTRL1_TPQC_SHIFT            (22U)
/*! TPQC - Tagged PTP Over Ethernet Packets Queuing Control */
#define EMAC_MAC_RXQ_CTRL1_TPQC(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL1_TPQC_SHIFT)) & EMAC_MAC_RXQ_CTRL1_TPQC_MASK)

#define EMAC_MAC_RXQ_CTRL1_FPRQ_MASK             (0x7000000U)
#define EMAC_MAC_RXQ_CTRL1_FPRQ_SHIFT            (24U)
/*! FPRQ - Frame Preemption Residue Queue */
#define EMAC_MAC_RXQ_CTRL1_FPRQ(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL1_FPRQ_SHIFT)) & EMAC_MAC_RXQ_CTRL1_FPRQ_MASK)
/*! @} */

/*! @name MAC_RXQ_CTRL2 - MAC RxQ Control 2 */
/*! @{ */

#define EMAC_MAC_RXQ_CTRL2_PSRQ0_MASK            (0xFFU)
#define EMAC_MAC_RXQ_CTRL2_PSRQ0_SHIFT           (0U)
/*! PSRQ0 - Priorities Selected In Receive Queue 0 */
#define EMAC_MAC_RXQ_CTRL2_PSRQ0(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL2_PSRQ0_SHIFT)) & EMAC_MAC_RXQ_CTRL2_PSRQ0_MASK)

#define EMAC_MAC_RXQ_CTRL2_PSRQ1_MASK            (0xFF00U)
#define EMAC_MAC_RXQ_CTRL2_PSRQ1_SHIFT           (8U)
/*! PSRQ1 - Priorities Selected In Receive Queue 1 */
#define EMAC_MAC_RXQ_CTRL2_PSRQ1(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RXQ_CTRL2_PSRQ1_SHIFT)) & EMAC_MAC_RXQ_CTRL2_PSRQ1_MASK)
/*! @} */

/*! @name MAC_INTERRUPT_STATUS - MAC Interrupt Status */
/*! @{ */

#define EMAC_MAC_INTERRUPT_STATUS_PHYIS_MASK     (0x8U)
#define EMAC_MAC_INTERRUPT_STATUS_PHYIS_SHIFT    (3U)
/*! PHYIS - PHY Interrupt
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_INTERRUPT_STATUS_PHYIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_STATUS_PHYIS_SHIFT)) & EMAC_MAC_INTERRUPT_STATUS_PHYIS_MASK)

#define EMAC_MAC_INTERRUPT_STATUS_MMCIS_MASK     (0x100U)
#define EMAC_MAC_INTERRUPT_STATUS_MMCIS_SHIFT    (8U)
/*! MMCIS - MMC Interrupt Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define EMAC_MAC_INTERRUPT_STATUS_MMCIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_STATUS_MMCIS_SHIFT)) & EMAC_MAC_INTERRUPT_STATUS_MMCIS_MASK)

#define EMAC_MAC_INTERRUPT_STATUS_MMCRXIS_MASK   (0x200U)
#define EMAC_MAC_INTERRUPT_STATUS_MMCRXIS_SHIFT  (9U)
/*! MMCRXIS - MMC Receive Interrupt Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define EMAC_MAC_INTERRUPT_STATUS_MMCRXIS(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_STATUS_MMCRXIS_SHIFT)) & EMAC_MAC_INTERRUPT_STATUS_MMCRXIS_MASK)

#define EMAC_MAC_INTERRUPT_STATUS_MMCTXIS_MASK   (0x400U)
#define EMAC_MAC_INTERRUPT_STATUS_MMCTXIS_SHIFT  (10U)
/*! MMCTXIS - MMC Transmit Interrupt Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define EMAC_MAC_INTERRUPT_STATUS_MMCTXIS(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_STATUS_MMCTXIS_SHIFT)) & EMAC_MAC_INTERRUPT_STATUS_MMCTXIS_MASK)

#define EMAC_MAC_INTERRUPT_STATUS_TSIS_MASK      (0x1000U)
#define EMAC_MAC_INTERRUPT_STATUS_TSIS_SHIFT     (12U)
/*! TSIS - Timestamp Interrupt Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define EMAC_MAC_INTERRUPT_STATUS_TSIS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_STATUS_TSIS_SHIFT)) & EMAC_MAC_INTERRUPT_STATUS_TSIS_MASK)

#define EMAC_MAC_INTERRUPT_STATUS_TXSTSIS_MASK   (0x2000U)
#define EMAC_MAC_INTERRUPT_STATUS_TXSTSIS_SHIFT  (13U)
/*! TXSTSIS - Transmit Status Interrupt
 *  0b0..Inactive
 *  0b1..Active
 */
#define EMAC_MAC_INTERRUPT_STATUS_TXSTSIS(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_STATUS_TXSTSIS_SHIFT)) & EMAC_MAC_INTERRUPT_STATUS_TXSTSIS_MASK)

#define EMAC_MAC_INTERRUPT_STATUS_RXSTSIS_MASK   (0x4000U)
#define EMAC_MAC_INTERRUPT_STATUS_RXSTSIS_SHIFT  (14U)
/*! RXSTSIS - Receive Status Interrupt
 *  0b0..Inactive
 *  0b1..Active
 */
#define EMAC_MAC_INTERRUPT_STATUS_RXSTSIS(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_STATUS_RXSTSIS_SHIFT)) & EMAC_MAC_INTERRUPT_STATUS_RXSTSIS_MASK)

#define EMAC_MAC_INTERRUPT_STATUS_FPEIS_MASK     (0x20000U)
#define EMAC_MAC_INTERRUPT_STATUS_FPEIS_SHIFT    (17U)
/*! FPEIS - Frame Preemption Interrupt Status
 *  0b0..Inactive
 *  0b1..Ative
 */
#define EMAC_MAC_INTERRUPT_STATUS_FPEIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_STATUS_FPEIS_SHIFT)) & EMAC_MAC_INTERRUPT_STATUS_FPEIS_MASK)

#define EMAC_MAC_INTERRUPT_STATUS_MDIOIS_MASK    (0x40000U)
#define EMAC_MAC_INTERRUPT_STATUS_MDIOIS_SHIFT   (18U)
/*! MDIOIS - MDIO Interrupt Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define EMAC_MAC_INTERRUPT_STATUS_MDIOIS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_STATUS_MDIOIS_SHIFT)) & EMAC_MAC_INTERRUPT_STATUS_MDIOIS_MASK)

#define EMAC_MAC_INTERRUPT_STATUS_MFTIS_MASK     (0x80000U)
#define EMAC_MAC_INTERRUPT_STATUS_MFTIS_SHIFT    (19U)
/*! MFTIS - MMC FPE Transmit Interrupt Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define EMAC_MAC_INTERRUPT_STATUS_MFTIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_STATUS_MFTIS_SHIFT)) & EMAC_MAC_INTERRUPT_STATUS_MFTIS_MASK)

#define EMAC_MAC_INTERRUPT_STATUS_MFRIS_MASK     (0x100000U)
#define EMAC_MAC_INTERRUPT_STATUS_MFRIS_SHIFT    (20U)
/*! MFRIS - MMC FPE Receive Interrupt Status
 *  0b0..Inactive
 *  0b1..Active
 */
#define EMAC_MAC_INTERRUPT_STATUS_MFRIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_STATUS_MFRIS_SHIFT)) & EMAC_MAC_INTERRUPT_STATUS_MFRIS_MASK)
/*! @} */

/*! @name MAC_INTERRUPT_ENABLE - MAC Interrupt Enable */
/*! @{ */

#define EMAC_MAC_INTERRUPT_ENABLE_PHYIE_MASK     (0x8U)
#define EMAC_MAC_INTERRUPT_ENABLE_PHYIE_SHIFT    (3U)
/*! PHYIE - PHY Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_INTERRUPT_ENABLE_PHYIE(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_ENABLE_PHYIE_SHIFT)) & EMAC_MAC_INTERRUPT_ENABLE_PHYIE_MASK)

#define EMAC_MAC_INTERRUPT_ENABLE_TSIE_MASK      (0x1000U)
#define EMAC_MAC_INTERRUPT_ENABLE_TSIE_SHIFT     (12U)
/*! TSIE - Timestamp Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_INTERRUPT_ENABLE_TSIE(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_ENABLE_TSIE_SHIFT)) & EMAC_MAC_INTERRUPT_ENABLE_TSIE_MASK)

#define EMAC_MAC_INTERRUPT_ENABLE_TXSTSIE_MASK   (0x2000U)
#define EMAC_MAC_INTERRUPT_ENABLE_TXSTSIE_SHIFT  (13U)
/*! TXSTSIE - Transmit Status Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_INTERRUPT_ENABLE_TXSTSIE(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_ENABLE_TXSTSIE_SHIFT)) & EMAC_MAC_INTERRUPT_ENABLE_TXSTSIE_MASK)

#define EMAC_MAC_INTERRUPT_ENABLE_RXSTSIE_MASK   (0x4000U)
#define EMAC_MAC_INTERRUPT_ENABLE_RXSTSIE_SHIFT  (14U)
/*! RXSTSIE - Receive Status Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_INTERRUPT_ENABLE_RXSTSIE(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_ENABLE_RXSTSIE_SHIFT)) & EMAC_MAC_INTERRUPT_ENABLE_RXSTSIE_MASK)

#define EMAC_MAC_INTERRUPT_ENABLE_FPEIE_MASK     (0x20000U)
#define EMAC_MAC_INTERRUPT_ENABLE_FPEIE_SHIFT    (17U)
/*! FPEIE - Frame Preemption Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_INTERRUPT_ENABLE_FPEIE(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_ENABLE_FPEIE_SHIFT)) & EMAC_MAC_INTERRUPT_ENABLE_FPEIE_MASK)

#define EMAC_MAC_INTERRUPT_ENABLE_MDIOIE_MASK    (0x40000U)
#define EMAC_MAC_INTERRUPT_ENABLE_MDIOIE_SHIFT   (18U)
/*! MDIOIE - MDIO Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_INTERRUPT_ENABLE_MDIOIE(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_INTERRUPT_ENABLE_MDIOIE_SHIFT)) & EMAC_MAC_INTERRUPT_ENABLE_MDIOIE_MASK)
/*! @} */

/*! @name MAC_RX_TX_STATUS - MAC Rx Transmit Status */
/*! @{ */

#define EMAC_MAC_RX_TX_STATUS_TJT_MASK           (0x1U)
#define EMAC_MAC_RX_TX_STATUS_TJT_SHIFT          (0U)
/*! TJT - Transmit Jabber Timeout
 *  0b0..No transmit jabber timeout occurred
 *  0b1..Transmit jabber timeout occurred
 */
#define EMAC_MAC_RX_TX_STATUS_TJT(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RX_TX_STATUS_TJT_SHIFT)) & EMAC_MAC_RX_TX_STATUS_TJT_MASK)

#define EMAC_MAC_RX_TX_STATUS_NCARR_MASK         (0x2U)
#define EMAC_MAC_RX_TX_STATUS_NCARR_SHIFT        (1U)
/*! NCARR - No Carrier
 *  0b0..Present
 *  0b1..Absent
 */
#define EMAC_MAC_RX_TX_STATUS_NCARR(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RX_TX_STATUS_NCARR_SHIFT)) & EMAC_MAC_RX_TX_STATUS_NCARR_MASK)

#define EMAC_MAC_RX_TX_STATUS_LCARR_MASK         (0x4U)
#define EMAC_MAC_RX_TX_STATUS_LCARR_SHIFT        (2U)
/*! LCARR - Loss of Carrier
 *  0b0..Carrier is present
 *  0b1..Loss of carrier
 */
#define EMAC_MAC_RX_TX_STATUS_LCARR(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RX_TX_STATUS_LCARR_SHIFT)) & EMAC_MAC_RX_TX_STATUS_LCARR_MASK)

#define EMAC_MAC_RX_TX_STATUS_EXDEF_MASK         (0x8U)
#define EMAC_MAC_RX_TX_STATUS_EXDEF_SHIFT        (3U)
/*! EXDEF - Excessive Deferral
 *  0b0..No excessive deferral
 *  0b1..Excessive deferral
 */
#define EMAC_MAC_RX_TX_STATUS_EXDEF(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RX_TX_STATUS_EXDEF_SHIFT)) & EMAC_MAC_RX_TX_STATUS_EXDEF_MASK)

#define EMAC_MAC_RX_TX_STATUS_LCOL_MASK          (0x10U)
#define EMAC_MAC_RX_TX_STATUS_LCOL_SHIFT         (4U)
/*! LCOL - Late Collision
 *  0b0..No collision
 *  0b1..Late collision is sensed
 */
#define EMAC_MAC_RX_TX_STATUS_LCOL(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RX_TX_STATUS_LCOL_SHIFT)) & EMAC_MAC_RX_TX_STATUS_LCOL_MASK)

#define EMAC_MAC_RX_TX_STATUS_EXCOL_MASK         (0x20U)
#define EMAC_MAC_RX_TX_STATUS_EXCOL_SHIFT        (5U)
/*! EXCOL - Excessive Collisions
 *  0b0..No collision
 *  0b1..Excessive collision is sensed
 */
#define EMAC_MAC_RX_TX_STATUS_EXCOL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RX_TX_STATUS_EXCOL_SHIFT)) & EMAC_MAC_RX_TX_STATUS_EXCOL_MASK)

#define EMAC_MAC_RX_TX_STATUS_RWT_MASK           (0x100U)
#define EMAC_MAC_RX_TX_STATUS_RWT_SHIFT          (8U)
/*! RWT - Receive Watchdog Timeout
 *  0b0..No receive watchdog timed out
 *  0b1..Receive watchdog timed out
 */
#define EMAC_MAC_RX_TX_STATUS_RWT(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_RX_TX_STATUS_RWT_SHIFT)) & EMAC_MAC_RX_TX_STATUS_RWT_MASK)
/*! @} */

/*! @name MAC_VERSION - MAC Version */
/*! @{ */

#define EMAC_MAC_VERSION_IPVER_MASK              (0xFFU)
#define EMAC_MAC_VERSION_IPVER_SHIFT             (0U)
/*! IPVER - IP Version */
#define EMAC_MAC_VERSION_IPVER(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VERSION_IPVER_SHIFT)) & EMAC_MAC_VERSION_IPVER_MASK)

#define EMAC_MAC_VERSION_CFGVER_MASK             (0xFF00U)
#define EMAC_MAC_VERSION_CFGVER_SHIFT            (8U)
/*! CFGVER - IP Configuration Version */
#define EMAC_MAC_VERSION_CFGVER(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_VERSION_CFGVER_SHIFT)) & EMAC_MAC_VERSION_CFGVER_MASK)
/*! @} */

/*! @name MAC_DEBUG - MAC Debug */
/*! @{ */

#define EMAC_MAC_DEBUG_RPESTS_MASK               (0x1U)
#define EMAC_MAC_DEBUG_RPESTS_SHIFT              (0U)
/*! RPESTS - Receive Protocol Engine Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_DEBUG_RPESTS(x)                 (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_DEBUG_RPESTS_SHIFT)) & EMAC_MAC_DEBUG_RPESTS_MASK)

#define EMAC_MAC_DEBUG_RFCFCSTS_MASK             (0x6U)
#define EMAC_MAC_DEBUG_RFCFCSTS_SHIFT            (1U)
/*! RFCFCSTS - MAC Receive Packet Controller FIFO Status
 *  0b00..Inactive
 *  0b01..Active
 */
#define EMAC_MAC_DEBUG_RFCFCSTS(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_DEBUG_RFCFCSTS_SHIFT)) & EMAC_MAC_DEBUG_RFCFCSTS_MASK)

#define EMAC_MAC_DEBUG_TPESTS_MASK               (0x10000U)
#define EMAC_MAC_DEBUG_TPESTS_SHIFT              (16U)
/*! TPESTS - MAC GMII Or MII Transmit Protocol Engine Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_DEBUG_TPESTS(x)                 (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_DEBUG_TPESTS_SHIFT)) & EMAC_MAC_DEBUG_TPESTS_MASK)

#define EMAC_MAC_DEBUG_TFCSTS_MASK               (0x60000U)
#define EMAC_MAC_DEBUG_TFCSTS_SHIFT              (17U)
/*! TFCSTS - MAC Transmit Packet Controller Status
 *  0b00..Idle state
 *  0b01..Waiting for one of these: status of the previous packet or IPG, or for the back-off period to be over
 *  0b10..Generating and transmitting a pause control packet (in Full-Duplex mode)
 *  0b11..Transferring input packet for transmission
 */
#define EMAC_MAC_DEBUG_TFCSTS(x)                 (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_DEBUG_TFCSTS_SHIFT)) & EMAC_MAC_DEBUG_TFCSTS_MASK)
/*! @} */

/*! @name MAC_HW_FEATURE0 - MAC Hardware Feature 0 */
/*! @{ */

#define EMAC_MAC_HW_FEATURE0_MIISEL_MASK         (0x1U)
#define EMAC_MAC_HW_FEATURE0_MIISEL_SHIFT        (0U)
/*! MIISEL - 10 or 100 Mbit/s Support Feature
 *  0b0..Unavailable
 *  0b1..Available
 */
#define EMAC_MAC_HW_FEATURE0_MIISEL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_MIISEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_MIISEL_MASK)

#define EMAC_MAC_HW_FEATURE0_GMIISEL_MASK        (0x2U)
#define EMAC_MAC_HW_FEATURE0_GMIISEL_SHIFT       (1U)
/*! GMIISEL - 1000 Mbit/s Support Feature
 *  0b0..Unavailable
 *  0b1..Available
 */
#define EMAC_MAC_HW_FEATURE0_GMIISEL(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_GMIISEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_GMIISEL_MASK)

#define EMAC_MAC_HW_FEATURE0_HDSEL_MASK          (0x4U)
#define EMAC_MAC_HW_FEATURE0_HDSEL_SHIFT         (2U)
/*! HDSEL - Half-Duplex Support Feature
 *  0b0..Unavailable
 *  0b1..Available
 */
#define EMAC_MAC_HW_FEATURE0_HDSEL(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_HDSEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_HDSEL_MASK)

#define EMAC_MAC_HW_FEATURE0_PCSSEL_MASK         (0x8U)
#define EMAC_MAC_HW_FEATURE0_PCSSEL_SHIFT        (3U)
/*! PCSSEL - PCS Select
 *  0b0..No
 *  0b1..Yes
 */
#define EMAC_MAC_HW_FEATURE0_PCSSEL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_PCSSEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_PCSSEL_MASK)

#define EMAC_MAC_HW_FEATURE0_VLHASH_MASK         (0x10U)
#define EMAC_MAC_HW_FEATURE0_VLHASH_SHIFT        (4U)
/*! VLHASH - VLAN Hash Filter Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE0_VLHASH(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_VLHASH_SHIFT)) & EMAC_MAC_HW_FEATURE0_VLHASH_MASK)

#define EMAC_MAC_HW_FEATURE0_SMASEL_MASK         (0x20U)
#define EMAC_MAC_HW_FEATURE0_SMASEL_SHIFT        (5U)
/*! SMASEL - SMA (MDIO) Interface Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE0_SMASEL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_SMASEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_SMASEL_MASK)

#define EMAC_MAC_HW_FEATURE0_RWKSEL_MASK         (0x40U)
#define EMAC_MAC_HW_FEATURE0_RWKSEL_SHIFT        (6U)
/*! RWKSEL - PMT Remote Wake-Up Packet Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE0_RWKSEL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_RWKSEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_RWKSEL_MASK)

#define EMAC_MAC_HW_FEATURE0_MGKSEL_MASK         (0x80U)
#define EMAC_MAC_HW_FEATURE0_MGKSEL_SHIFT        (7U)
/*! MGKSEL - PMT Magic Packet Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE0_MGKSEL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_MGKSEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_MGKSEL_MASK)

#define EMAC_MAC_HW_FEATURE0_MMCSEL_MASK         (0x100U)
#define EMAC_MAC_HW_FEATURE0_MMCSEL_SHIFT        (8U)
/*! MMCSEL - MAC Management Counters (MMC) Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE0_MMCSEL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_MMCSEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_MMCSEL_MASK)

#define EMAC_MAC_HW_FEATURE0_ARPOFFSEL_MASK      (0x200U)
#define EMAC_MAC_HW_FEATURE0_ARPOFFSEL_SHIFT     (9U)
/*! ARPOFFSEL - ARP Offload Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE0_ARPOFFSEL(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_ARPOFFSEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_ARPOFFSEL_MASK)

#define EMAC_MAC_HW_FEATURE0_TSSEL_MASK          (0x1000U)
#define EMAC_MAC_HW_FEATURE0_TSSEL_SHIFT         (12U)
/*! TSSEL - IEEE 1588-2008 Timestamp Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE0_TSSEL(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_TSSEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_TSSEL_MASK)

#define EMAC_MAC_HW_FEATURE0_EEESEL_MASK         (0x2000U)
#define EMAC_MAC_HW_FEATURE0_EEESEL_SHIFT        (13U)
/*! EEESEL - Energy Efficient Ethernet (EEE) Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE0_EEESEL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_EEESEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_EEESEL_MASK)

#define EMAC_MAC_HW_FEATURE0_TXCOESEL_MASK       (0x4000U)
#define EMAC_MAC_HW_FEATURE0_TXCOESEL_SHIFT      (14U)
/*! TXCOESEL - Transmit Checksum Offload Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE0_TXCOESEL(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_TXCOESEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_TXCOESEL_MASK)

#define EMAC_MAC_HW_FEATURE0_RXCOESEL_MASK       (0x10000U)
#define EMAC_MAC_HW_FEATURE0_RXCOESEL_SHIFT      (16U)
/*! RXCOESEL - Receive Checksum Offload Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE0_RXCOESEL(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_RXCOESEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_RXCOESEL_MASK)

#define EMAC_MAC_HW_FEATURE0_ADDMACADRSEL_MASK   (0x7C0000U)
#define EMAC_MAC_HW_FEATURE0_ADDMACADRSEL_SHIFT  (18U)
/*! ADDMACADRSEL - MAC Addresses 1-31
 *  0b00000..Not selected
 *  0b00001..Selected
 */
#define EMAC_MAC_HW_FEATURE0_ADDMACADRSEL(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_ADDMACADRSEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_ADDMACADRSEL_MASK)

#define EMAC_MAC_HW_FEATURE0_MACADR32SEL_MASK    (0x800000U)
#define EMAC_MAC_HW_FEATURE0_MACADR32SEL_SHIFT   (23U)
/*! MACADR32SEL - MAC Addresses 32-63
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE0_MACADR32SEL(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_MACADR32SEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_MACADR32SEL_MASK)

#define EMAC_MAC_HW_FEATURE0_MACADR64SEL_MASK    (0x1000000U)
#define EMAC_MAC_HW_FEATURE0_MACADR64SEL_SHIFT   (24U)
/*! MACADR64SEL - MAC Addresses 64-127
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE0_MACADR64SEL(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_MACADR64SEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_MACADR64SEL_MASK)

#define EMAC_MAC_HW_FEATURE0_TSSTSSEL_MASK       (0x6000000U)
#define EMAC_MAC_HW_FEATURE0_TSSTSSEL_SHIFT      (25U)
/*! TSSTSSEL - Timestamp System Time Source Feature
 *  0b00..Internal
 *  0b01..External
 *  0b10..Both internal and external
 *  0b11..Reserved
 */
#define EMAC_MAC_HW_FEATURE0_TSSTSSEL(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_TSSTSSEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_TSSTSSEL_MASK)

#define EMAC_MAC_HW_FEATURE0_SAVLANINS_MASK      (0x8000000U)
#define EMAC_MAC_HW_FEATURE0_SAVLANINS_SHIFT     (27U)
/*! SAVLANINS - SA or VLAN Insertion Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE0_SAVLANINS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_SAVLANINS_SHIFT)) & EMAC_MAC_HW_FEATURE0_SAVLANINS_MASK)

#define EMAC_MAC_HW_FEATURE0_ACTPHYSEL_MASK      (0x70000000U)
#define EMAC_MAC_HW_FEATURE0_ACTPHYSEL_SHIFT     (28U)
/*! ACTPHYSEL - Active PHY Feature
 *  0b000..GMII or MII
 *  0b001..RGMII
 *  0b010..SGMII
 *  0b011..TBI
 *  0b100..RMII
 *  0b101..RTBI
 *  0b110..SMII
 *  0b111..RevMII
 */
#define EMAC_MAC_HW_FEATURE0_ACTPHYSEL(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE0_ACTPHYSEL_SHIFT)) & EMAC_MAC_HW_FEATURE0_ACTPHYSEL_MASK)
/*! @} */

/*! @name MAC_HW_FEATURE1 - MAC Hardware Feature 1 */
/*! @{ */

#define EMAC_MAC_HW_FEATURE1_RXFIFOSIZE_MASK     (0x1FU)
#define EMAC_MAC_HW_FEATURE1_RXFIFOSIZE_SHIFT    (0U)
/*! RXFIFOSIZE - MTL Receive FIFO Size Feature
 *  0b00000..128 bytes
 *  0b00001..256 bytes
 *  0b00010..512 bytes
 *  0b00011..1024 bytes
 *  0b00100..2048 bytes
 *  0b00101..4096 bytes
 *  0b00110..8192 bytes
 *  0b00111..16384 bytes
 *  0b01000..32 KB
 *  0b01001..64 KB
 *  0b01010..128 KB
 *  0b01011..256 KB
 *  0b01100..Reserved
 */
#define EMAC_MAC_HW_FEATURE1_RXFIFOSIZE(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_RXFIFOSIZE_SHIFT)) & EMAC_MAC_HW_FEATURE1_RXFIFOSIZE_MASK)

#define EMAC_MAC_HW_FEATURE1_SPRAM_MASK          (0x20U)
#define EMAC_MAC_HW_FEATURE1_SPRAM_SHIFT         (5U)
/*! SPRAM - Single Port RAM Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE1_SPRAM(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_SPRAM_SHIFT)) & EMAC_MAC_HW_FEATURE1_SPRAM_MASK)

#define EMAC_MAC_HW_FEATURE1_TXFIFOSIZE_MASK     (0x7C0U)
#define EMAC_MAC_HW_FEATURE1_TXFIFOSIZE_SHIFT    (6U)
/*! TXFIFOSIZE - MTL Transmit FIFO Size Feature
 *  0b00000..128 bytes
 *  0b00001..256 bytes
 *  0b00010..512 bytes
 *  0b00011..1024 bytes
 *  0b00100..2048 bytes
 *  0b00101..4096 bytes
 *  0b00110..8192 bytes
 *  0b00111..16384 bytes
 *  0b01000..32 KB
 *  0b01001..64 KB
 *  0b01010..128 KB
 *  0b01011..Reserved
 */
#define EMAC_MAC_HW_FEATURE1_TXFIFOSIZE(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_TXFIFOSIZE_SHIFT)) & EMAC_MAC_HW_FEATURE1_TXFIFOSIZE_MASK)

#define EMAC_MAC_HW_FEATURE1_OSTEN_MASK          (0x800U)
#define EMAC_MAC_HW_FEATURE1_OSTEN_SHIFT         (11U)
/*! OSTEN - One-Step Timestamping Enable Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE1_OSTEN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_OSTEN_SHIFT)) & EMAC_MAC_HW_FEATURE1_OSTEN_MASK)

#define EMAC_MAC_HW_FEATURE1_PTOEN_MASK          (0x1000U)
#define EMAC_MAC_HW_FEATURE1_PTOEN_SHIFT         (12U)
/*! PTOEN - PTP Offload Enable Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE1_PTOEN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_PTOEN_SHIFT)) & EMAC_MAC_HW_FEATURE1_PTOEN_MASK)

#define EMAC_MAC_HW_FEATURE1_ADVTHWORD_MASK      (0x2000U)
#define EMAC_MAC_HW_FEATURE1_ADVTHWORD_SHIFT     (13U)
/*! ADVTHWORD - IEEE 1588 High-Word Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE1_ADVTHWORD(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_ADVTHWORD_SHIFT)) & EMAC_MAC_HW_FEATURE1_ADVTHWORD_MASK)

#define EMAC_MAC_HW_FEATURE1_ADDR64_MASK         (0xC000U)
#define EMAC_MAC_HW_FEATURE1_ADDR64_SHIFT        (14U)
/*! ADDR64 - Address Width Feature
 *  0b00..32
 *  0b01..40
 *  0b10..48
 *  0b11..Reserved
 */
#define EMAC_MAC_HW_FEATURE1_ADDR64(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_ADDR64_SHIFT)) & EMAC_MAC_HW_FEATURE1_ADDR64_MASK)

#define EMAC_MAC_HW_FEATURE1_DCBEN_MASK          (0x10000U)
#define EMAC_MAC_HW_FEATURE1_DCBEN_SHIFT         (16U)
/*! DCBEN - DCB Enable Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE1_DCBEN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_DCBEN_SHIFT)) & EMAC_MAC_HW_FEATURE1_DCBEN_MASK)

#define EMAC_MAC_HW_FEATURE1_SPHEN_MASK          (0x20000U)
#define EMAC_MAC_HW_FEATURE1_SPHEN_SHIFT         (17U)
/*! SPHEN - Split Header Enable Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE1_SPHEN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_SPHEN_SHIFT)) & EMAC_MAC_HW_FEATURE1_SPHEN_MASK)

#define EMAC_MAC_HW_FEATURE1_TSOEN_MASK          (0x40000U)
#define EMAC_MAC_HW_FEATURE1_TSOEN_SHIFT         (18U)
/*! TSOEN - TCP Segmentation Offload Enable Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE1_TSOEN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_TSOEN_SHIFT)) & EMAC_MAC_HW_FEATURE1_TSOEN_MASK)

#define EMAC_MAC_HW_FEATURE1_DBGMEMA_MASK        (0x80000U)
#define EMAC_MAC_HW_FEATURE1_DBGMEMA_SHIFT       (19U)
/*! DBGMEMA - DMA Debug Registers Enable Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE1_DBGMEMA(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_DBGMEMA_SHIFT)) & EMAC_MAC_HW_FEATURE1_DBGMEMA_MASK)

#define EMAC_MAC_HW_FEATURE1_AVSEL_MASK          (0x100000U)
#define EMAC_MAC_HW_FEATURE1_AVSEL_SHIFT         (20U)
/*! AVSEL - AV Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE1_AVSEL(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_AVSEL_SHIFT)) & EMAC_MAC_HW_FEATURE1_AVSEL_MASK)

#define EMAC_MAC_HW_FEATURE1_RAVSEL_MASK         (0x200000U)
#define EMAC_MAC_HW_FEATURE1_RAVSEL_SHIFT        (21U)
/*! RAVSEL - Receive Side-Only AV Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE1_RAVSEL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_RAVSEL_SHIFT)) & EMAC_MAC_HW_FEATURE1_RAVSEL_MASK)

#define EMAC_MAC_HW_FEATURE1_POUOST_MASK         (0x800000U)
#define EMAC_MAC_HW_FEATURE1_POUOST_SHIFT        (23U)
/*! POUOST - One Step For PTP Over UDP/IP Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE1_POUOST(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_POUOST_SHIFT)) & EMAC_MAC_HW_FEATURE1_POUOST_MASK)

#define EMAC_MAC_HW_FEATURE1_HASHTBLSZ_MASK      (0x3000000U)
#define EMAC_MAC_HW_FEATURE1_HASHTBLSZ_SHIFT     (24U)
/*! HASHTBLSZ - Hash Table Size
 *  0b00..No hash table
 *  0b01..64
 *  0b10..128
 *  0b11..256
 */
#define EMAC_MAC_HW_FEATURE1_HASHTBLSZ(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_HASHTBLSZ_SHIFT)) & EMAC_MAC_HW_FEATURE1_HASHTBLSZ_MASK)

#define EMAC_MAC_HW_FEATURE1_L3L4FNUM_MASK       (0x78000000U)
#define EMAC_MAC_HW_FEATURE1_L3L4FNUM_SHIFT      (27U)
/*! L3L4FNUM - L3 Or L4 Filter Number
 *  0b0000..No filters (0)
 *  0b0001..1
 *  0b0010..2
 *  0b0011..3
 *  0b0100..4
 *  0b0101..5
 *  0b0110..6
 *  0b0111..7
 *  0b1000..8
 */
#define EMAC_MAC_HW_FEATURE1_L3L4FNUM(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE1_L3L4FNUM_SHIFT)) & EMAC_MAC_HW_FEATURE1_L3L4FNUM_MASK)
/*! @} */

/*! @name MAC_HW_FEATURE2 - MAC Hardware Feature 2 */
/*! @{ */

#define EMAC_MAC_HW_FEATURE2_RXQCNT_MASK         (0xFU)
#define EMAC_MAC_HW_FEATURE2_RXQCNT_SHIFT        (0U)
/*! RXQCNT - Number Of MTL Receive Queues
 *  0b0000..1
 *  0b0001..2
 *  0b0010..3
 *  0b0011..4
 *  0b0100..5
 *  0b0101..6
 *  0b0110..7
 *  0b0111..8
 */
#define EMAC_MAC_HW_FEATURE2_RXQCNT(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE2_RXQCNT_SHIFT)) & EMAC_MAC_HW_FEATURE2_RXQCNT_MASK)

#define EMAC_MAC_HW_FEATURE2_TXQCNT_MASK         (0x3C0U)
#define EMAC_MAC_HW_FEATURE2_TXQCNT_SHIFT        (6U)
/*! TXQCNT - Number Of MTL Transmit Queues
 *  0b0000..1
 *  0b0001..2
 *  0b0010..3
 *  0b0011..4
 *  0b0100..5
 *  0b0101..6
 *  0b0110..7
 *  0b0111..8
 */
#define EMAC_MAC_HW_FEATURE2_TXQCNT(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE2_TXQCNT_SHIFT)) & EMAC_MAC_HW_FEATURE2_TXQCNT_MASK)

#define EMAC_MAC_HW_FEATURE2_RXCHCNT_MASK        (0xF000U)
#define EMAC_MAC_HW_FEATURE2_RXCHCNT_SHIFT       (12U)
/*! RXCHCNT - Number Of DMA Receive Channels
 *  0b0000..1
 *  0b0001..2
 *  0b0010..3
 *  0b0011..4
 *  0b0100..5
 *  0b0101..6
 *  0b0110..7
 *  0b0111..8
 */
#define EMAC_MAC_HW_FEATURE2_RXCHCNT(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE2_RXCHCNT_SHIFT)) & EMAC_MAC_HW_FEATURE2_RXCHCNT_MASK)

#define EMAC_MAC_HW_FEATURE2_TXCHCNT_MASK        (0x3C0000U)
#define EMAC_MAC_HW_FEATURE2_TXCHCNT_SHIFT       (18U)
/*! TXCHCNT - Number Of DMA Transmit Channels
 *  0b0000..1
 *  0b0001..2
 *  0b0010..3
 *  0b0011..4
 *  0b0100..5
 *  0b0101..6
 *  0b0110..7
 *  0b0111..8
 */
#define EMAC_MAC_HW_FEATURE2_TXCHCNT(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE2_TXCHCNT_SHIFT)) & EMAC_MAC_HW_FEATURE2_TXCHCNT_MASK)

#define EMAC_MAC_HW_FEATURE2_PPSOUTNUM_MASK      (0x7000000U)
#define EMAC_MAC_HW_FEATURE2_PPSOUTNUM_SHIFT     (24U)
/*! PPSOUTNUM - Number Of PPS Outputs
 *  0b000..No PPS output (0)
 *  0b001..1
 *  0b010..2
 *  0b011..3
 *  0b100..4
 *  0b101..Reserved
 */
#define EMAC_MAC_HW_FEATURE2_PPSOUTNUM(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE2_PPSOUTNUM_SHIFT)) & EMAC_MAC_HW_FEATURE2_PPSOUTNUM_MASK)

#define EMAC_MAC_HW_FEATURE2_AUXSNAPNUM_MASK     (0x70000000U)
#define EMAC_MAC_HW_FEATURE2_AUXSNAPNUM_SHIFT    (28U)
/*! AUXSNAPNUM - Number Of Auxiliary Snapshot Inputs
 *  0b000..No auxiliary input (0)
 *  0b001..1
 *  0b010..2
 *  0b011..3
 *  0b100..4
 *  0b101..Reserved
 */
#define EMAC_MAC_HW_FEATURE2_AUXSNAPNUM(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE2_AUXSNAPNUM_SHIFT)) & EMAC_MAC_HW_FEATURE2_AUXSNAPNUM_MASK)
/*! @} */

/*! @name MAC_HW_FEATURE3 - MAC Hardware Feature 3 */
/*! @{ */

#define EMAC_MAC_HW_FEATURE3_NRVF_MASK           (0x7U)
#define EMAC_MAC_HW_FEATURE3_NRVF_SHIFT          (0U)
/*! NRVF
 *  0b000..No filters (0)
 *  0b001..4
 *  0b010..8
 *  0b011..16
 *  0b100..24
 *  0b101..32
 *  0b110..Reserved
 */
#define EMAC_MAC_HW_FEATURE3_NRVF(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE3_NRVF_SHIFT)) & EMAC_MAC_HW_FEATURE3_NRVF_MASK)

#define EMAC_MAC_HW_FEATURE3_CBTISEL_MASK        (0x10U)
#define EMAC_MAC_HW_FEATURE3_CBTISEL_SHIFT       (4U)
/*! CBTISEL - Queue/Channel Based VLAN Tag Insertion On Transmit Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE3_CBTISEL(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE3_CBTISEL_SHIFT)) & EMAC_MAC_HW_FEATURE3_CBTISEL_MASK)

#define EMAC_MAC_HW_FEATURE3_DVLAN_MASK          (0x20U)
#define EMAC_MAC_HW_FEATURE3_DVLAN_SHIFT         (5U)
/*! DVLAN - Double VLAN Tag Processing Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE3_DVLAN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE3_DVLAN_SHIFT)) & EMAC_MAC_HW_FEATURE3_DVLAN_MASK)

#define EMAC_MAC_HW_FEATURE3_PDUPSEL_MASK        (0x200U)
#define EMAC_MAC_HW_FEATURE3_PDUPSEL_SHIFT       (9U)
/*! PDUPSEL - Broadcast/Multicast Packet Duplication Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE3_PDUPSEL(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE3_PDUPSEL_SHIFT)) & EMAC_MAC_HW_FEATURE3_PDUPSEL_MASK)

#define EMAC_MAC_HW_FEATURE3_FRPSEL_MASK         (0x400U)
#define EMAC_MAC_HW_FEATURE3_FRPSEL_SHIFT        (10U)
/*! FRPSEL - Flexible Receive Parser Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE3_FRPSEL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE3_FRPSEL_SHIFT)) & EMAC_MAC_HW_FEATURE3_FRPSEL_MASK)

#define EMAC_MAC_HW_FEATURE3_FRPBS_MASK          (0x1800U)
#define EMAC_MAC_HW_FEATURE3_FRPBS_SHIFT         (11U)
/*! FRPBS - Flexible Receive Parser Buffer Size
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..Reserved
 */
#define EMAC_MAC_HW_FEATURE3_FRPBS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE3_FRPBS_SHIFT)) & EMAC_MAC_HW_FEATURE3_FRPBS_MASK)

#define EMAC_MAC_HW_FEATURE3_FRPES_MASK          (0x6000U)
#define EMAC_MAC_HW_FEATURE3_FRPES_SHIFT         (13U)
/*! FRPES - Flexible Receive Parser Table Entry Size
 *  0b00..64
 *  0b01..128
 *  0b10..256
 *  0b11..Reserved
 */
#define EMAC_MAC_HW_FEATURE3_FRPES(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE3_FRPES_SHIFT)) & EMAC_MAC_HW_FEATURE3_FRPES_MASK)

#define EMAC_MAC_HW_FEATURE3_ESTSEL_MASK         (0x10000U)
#define EMAC_MAC_HW_FEATURE3_ESTSEL_SHIFT        (16U)
/*! ESTSEL - Enhancements To Scheduling Traffic Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE3_ESTSEL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE3_ESTSEL_SHIFT)) & EMAC_MAC_HW_FEATURE3_ESTSEL_MASK)

#define EMAC_MAC_HW_FEATURE3_ESTDEP_MASK         (0xE0000U)
#define EMAC_MAC_HW_FEATURE3_ESTDEP_SHIFT        (17U)
/*! ESTDEP - Depth Of Gate Control List
 *  0b000..No depth configured
 *  0b001..64 bytes
 *  0b010..128 bytes
 *  0b011..256 bytes
 *  0b100..512 bytes
 *  0b101..1024 bytes
 *  0b110..Reserved
 */
#define EMAC_MAC_HW_FEATURE3_ESTDEP(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE3_ESTDEP_SHIFT)) & EMAC_MAC_HW_FEATURE3_ESTDEP_MASK)

#define EMAC_MAC_HW_FEATURE3_ESTWID_MASK         (0x300000U)
#define EMAC_MAC_HW_FEATURE3_ESTWID_SHIFT        (20U)
/*! ESTWID - Estimated Time Interval Width
 *  0b00..Width not configured
 *  0b01..16 bits
 *  0b10..20 bits
 *  0b11..24 bits
 */
#define EMAC_MAC_HW_FEATURE3_ESTWID(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE3_ESTWID_SHIFT)) & EMAC_MAC_HW_FEATURE3_ESTWID_MASK)

#define EMAC_MAC_HW_FEATURE3_FPESEL_MASK         (0x4000000U)
#define EMAC_MAC_HW_FEATURE3_FPESEL_SHIFT        (26U)
/*! FPESEL - Frame Preemption Feature
 *  0b0..Not selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE3_FPESEL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE3_FPESEL_SHIFT)) & EMAC_MAC_HW_FEATURE3_FPESEL_MASK)

#define EMAC_MAC_HW_FEATURE3_TBSSEL_MASK         (0x8000000U)
#define EMAC_MAC_HW_FEATURE3_TBSSEL_SHIFT        (27U)
/*! TBSSEL - Time-Based Scheduling Feature
 *  0b0..Selected
 *  0b1..Selected
 */
#define EMAC_MAC_HW_FEATURE3_TBSSEL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE3_TBSSEL_SHIFT)) & EMAC_MAC_HW_FEATURE3_TBSSEL_MASK)

#define EMAC_MAC_HW_FEATURE3_ASP_MASK            (0x30000000U)
#define EMAC_MAC_HW_FEATURE3_ASP_SHIFT           (28U)
/*! ASP - Automotive Safety Package
 *  0b00..No safety features selected
 *  0b01..Only "ECC protection for external memory" feature is selected
 *  0b10..All the safety features are selected without the "parity port enable for external interface" feature
 *  0b11..All the safety features are selected with the "parity port enable for external interface" feature
 */
#define EMAC_MAC_HW_FEATURE3_ASP(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_HW_FEATURE3_ASP_SHIFT)) & EMAC_MAC_HW_FEATURE3_ASP_MASK)
/*! @} */

/*! @name MAC_DPP_FSM_INTERRUPT_STATUS - MAC DPP FSM Interrupt Status */
/*! @{ */

#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_MASK (0x4U)
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_SHIFT (2U)
/*! RDPES - Read Descriptor Parity Checker Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_SHIFT)) & EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_MASK)

#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_MASK (0x8U)
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_SHIFT (3U)
/*! MPES - MTL Data Path Parity Checker Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MPES(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_SHIFT)) & EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_MASK)

#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_MASK (0x10U)
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_SHIFT (4U)
/*! MTSPES - MTL Transmit Status Data Path Parity Checker Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_SHIFT)) & EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_MASK)

#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_MASK (0x20U)
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_SHIFT (5U)
/*! ARPES - Application Receive Interface Data Path Parity Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_SHIFT)) & EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_MASK)

#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_MASK (0x100U)
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_SHIFT (8U)
/*! TTES - Transmit FSM Timeout Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_TTES(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_SHIFT)) & EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_MASK)

#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_MASK (0x200U)
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_SHIFT (9U)
/*! RTES - Receive FSM Timeout Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RTES(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_SHIFT)) & EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_MASK)

#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_MASK (0x800U)
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_SHIFT (11U)
/*! ATES - APP FSM Timeout Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ATES(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_SHIFT)) & EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_MASK)

#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_MASK (0x1000U)
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_SHIFT (12U)
/*! PTES - PTP FSM Timeout Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_PTES(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_SHIFT)) & EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_MASK)

#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES_MASK (0x10000U)
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES_SHIFT (16U)
/*! MSTTES - Master Read Or Write Timeout Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES_SHIFT)) & EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES_MASK)

#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_MASK (0x1000000U)
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_SHIFT (24U)
/*! FSMPES - FSM State Parity Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_SHIFT)) & EMAC_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_MASK)
/*! @} */

/*! @name MAC_FSM_CONTROL - MAC FSM Control */
/*! @{ */

#define EMAC_MAC_FSM_CONTROL_TMOUTEN_MASK        (0x1U)
#define EMAC_MAC_FSM_CONTROL_TMOUTEN_SHIFT       (0U)
/*! TMOUTEN - Time Out Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_FSM_CONTROL_TMOUTEN(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_CONTROL_TMOUTEN_SHIFT)) & EMAC_MAC_FSM_CONTROL_TMOUTEN_MASK)

#define EMAC_MAC_FSM_CONTROL_PRTYEN_MASK         (0x2U)
#define EMAC_MAC_FSM_CONTROL_PRTYEN_SHIFT        (1U)
/*! PRTYEN - Parity Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_FSM_CONTROL_PRTYEN(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_CONTROL_PRTYEN_SHIFT)) & EMAC_MAC_FSM_CONTROL_PRTYEN_MASK)

#define EMAC_MAC_FSM_CONTROL_TTEIN_MASK          (0x100U)
#define EMAC_MAC_FSM_CONTROL_TTEIN_SHIFT         (8U)
/*! TTEIN - Transmit FSM Timeout Error Injection
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_FSM_CONTROL_TTEIN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_CONTROL_TTEIN_SHIFT)) & EMAC_MAC_FSM_CONTROL_TTEIN_MASK)

#define EMAC_MAC_FSM_CONTROL_RTEIN_MASK          (0x200U)
#define EMAC_MAC_FSM_CONTROL_RTEIN_SHIFT         (9U)
/*! RTEIN - Receive FSM Timeout Error Injection
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_FSM_CONTROL_RTEIN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_CONTROL_RTEIN_SHIFT)) & EMAC_MAC_FSM_CONTROL_RTEIN_MASK)

#define EMAC_MAC_FSM_CONTROL_ATEIN_MASK          (0x800U)
#define EMAC_MAC_FSM_CONTROL_ATEIN_SHIFT         (11U)
/*! ATEIN - APP FSM Timeout Error Injection
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_FSM_CONTROL_ATEIN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_CONTROL_ATEIN_SHIFT)) & EMAC_MAC_FSM_CONTROL_ATEIN_MASK)

#define EMAC_MAC_FSM_CONTROL_PTEIN_MASK          (0x1000U)
#define EMAC_MAC_FSM_CONTROL_PTEIN_SHIFT         (12U)
/*! PTEIN - PTP FSM Timeout Error Injection
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_FSM_CONTROL_PTEIN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_CONTROL_PTEIN_SHIFT)) & EMAC_MAC_FSM_CONTROL_PTEIN_MASK)

#define EMAC_MAC_FSM_CONTROL_TPEIN_MASK          (0x10000U)
#define EMAC_MAC_FSM_CONTROL_TPEIN_SHIFT         (16U)
/*! TPEIN - Transmit FSM Parity Error Injection
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_FSM_CONTROL_TPEIN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_CONTROL_TPEIN_SHIFT)) & EMAC_MAC_FSM_CONTROL_TPEIN_MASK)

#define EMAC_MAC_FSM_CONTROL_RPEIN_MASK          (0x20000U)
#define EMAC_MAC_FSM_CONTROL_RPEIN_SHIFT         (17U)
/*! RPEIN - Receive FSM Parity Error Injection
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_FSM_CONTROL_RPEIN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_CONTROL_RPEIN_SHIFT)) & EMAC_MAC_FSM_CONTROL_RPEIN_MASK)

#define EMAC_MAC_FSM_CONTROL_APEIN_MASK          (0x80000U)
#define EMAC_MAC_FSM_CONTROL_APEIN_SHIFT         (19U)
/*! APEIN - APP FSM Parity Error Injection
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_FSM_CONTROL_APEIN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_CONTROL_APEIN_SHIFT)) & EMAC_MAC_FSM_CONTROL_APEIN_MASK)

#define EMAC_MAC_FSM_CONTROL_PPEIN_MASK          (0x100000U)
#define EMAC_MAC_FSM_CONTROL_PPEIN_SHIFT         (20U)
/*! PPEIN - PTP FSM Parity Error Injection
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_FSM_CONTROL_PPEIN(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_CONTROL_PPEIN_SHIFT)) & EMAC_MAC_FSM_CONTROL_PPEIN_MASK)

#define EMAC_MAC_FSM_CONTROL_TLGRNML_MASK        (0x1000000U)
#define EMAC_MAC_FSM_CONTROL_TLGRNML_SHIFT       (24U)
/*! TLGRNML - Transmit Large Or Normal Mode Select
 *  0b0..Normal mode
 *  0b1..Large mode
 */
#define EMAC_MAC_FSM_CONTROL_TLGRNML(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_CONTROL_TLGRNML_SHIFT)) & EMAC_MAC_FSM_CONTROL_TLGRNML_MASK)

#define EMAC_MAC_FSM_CONTROL_RLGRNML_MASK        (0x2000000U)
#define EMAC_MAC_FSM_CONTROL_RLGRNML_SHIFT       (25U)
/*! RLGRNML - Receive Large Or Normal Mode Select
 *  0b0..Normal mode
 *  0b1..Large mode
 */
#define EMAC_MAC_FSM_CONTROL_RLGRNML(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_CONTROL_RLGRNML_SHIFT)) & EMAC_MAC_FSM_CONTROL_RLGRNML_MASK)

#define EMAC_MAC_FSM_CONTROL_ALGRNML_MASK        (0x8000000U)
#define EMAC_MAC_FSM_CONTROL_ALGRNML_SHIFT       (27U)
/*! ALGRNML - APP Large Or Normal Mode Select
 *  0b0..Normal mode
 *  0b1..Large mode
 */
#define EMAC_MAC_FSM_CONTROL_ALGRNML(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_CONTROL_ALGRNML_SHIFT)) & EMAC_MAC_FSM_CONTROL_ALGRNML_MASK)

#define EMAC_MAC_FSM_CONTROL_PLGRNML_MASK        (0x10000000U)
#define EMAC_MAC_FSM_CONTROL_PLGRNML_SHIFT       (28U)
/*! PLGRNML - PTP Large Or Normal Mode Select
 *  0b0..Normal mode
 *  0b1..Large mode
 */
#define EMAC_MAC_FSM_CONTROL_PLGRNML(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_CONTROL_PLGRNML_SHIFT)) & EMAC_MAC_FSM_CONTROL_PLGRNML_MASK)
/*! @} */

/*! @name MAC_FSM_ACT_TIMER - MAC FSM ACT Timer */
/*! @{ */

#define EMAC_MAC_FSM_ACT_TIMER_TMR_MASK          (0x3FFU)
#define EMAC_MAC_FSM_ACT_TIMER_TMR_SHIFT         (0U)
/*! TMR - CSR Clocks For 1 us Tic */
#define EMAC_MAC_FSM_ACT_TIMER_TMR(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_ACT_TIMER_TMR_SHIFT)) & EMAC_MAC_FSM_ACT_TIMER_TMR_MASK)

#define EMAC_MAC_FSM_ACT_TIMER_NTMRMD_MASK       (0xF0000U)
#define EMAC_MAC_FSM_ACT_TIMER_NTMRMD_SHIFT      (16U)
/*! NTMRMD - Normal Mode Timeout Value
 *  0b0000..Timer disabled
 *  0b0001..1 us
 *  0b0010..1.024 ms (~4 ms)
 *  0b0011..16.384 ms (~16 ms)
 *  0b0100..65.536 ms (~64 ms)
 *  0b0101..262.144 ms (~256 ms)
 *  0b0110..1.048 sec (~1 sec)
 *  0b0111..4.194 sec (~4 sec)
 *  0b1000..16.777 sec (~16 sec)
 *  0b1001..33.554 sec (~32 sec)
 *  0b1010..67.108 sec (~64 sec)
 *  0b1011..Reserved
 */
#define EMAC_MAC_FSM_ACT_TIMER_NTMRMD(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_ACT_TIMER_NTMRMD_SHIFT)) & EMAC_MAC_FSM_ACT_TIMER_NTMRMD_MASK)

#define EMAC_MAC_FSM_ACT_TIMER_LTMRMD_MASK       (0xF00000U)
#define EMAC_MAC_FSM_ACT_TIMER_LTMRMD_SHIFT      (20U)
/*! LTMRMD - Large Mode Timeout Value
 *  0b0000..Timer disabled
 *  0b0001..1 us
 *  0b0010..1.024 ms (~4 ms)
 *  0b0011..16.384 ms (~16 ms)
 *  0b0100..65.536 ms (~64 ms)
 *  0b0101..262.144 ms (~256 ms)
 *  0b0110..1.048 sec (~1 sec)
 *  0b0111..4.194 sec (~4sec)
 *  0b1000..16.777 sec (~16 sec)
 *  0b1001..33.554 sec (~32 sec)
 *  0b1010..67.108 sec (~64 sec)
 *  0b1011..Reserved
 */
#define EMAC_MAC_FSM_ACT_TIMER_LTMRMD(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FSM_ACT_TIMER_LTMRMD_SHIFT)) & EMAC_MAC_FSM_ACT_TIMER_LTMRMD_MASK)
/*! @} */

/*! @name SCS_REG1 - SCS_REG 1 */
/*! @{ */

#define EMAC_SCS_REG1_MAC_SCS1_MASK              (0xFFFFFFFFU)
#define EMAC_SCS_REG1_MAC_SCS1_SHIFT             (0U)
/*! MAC_SCS1 - MAC SCS 1 */
#define EMAC_SCS_REG1_MAC_SCS1(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_SCS_REG1_MAC_SCS1_SHIFT)) & EMAC_SCS_REG1_MAC_SCS1_MASK)
/*! @} */

/*! @name MAC_MDIO_ADDRESS - MAC MDIO Address */
/*! @{ */

#define EMAC_MAC_MDIO_ADDRESS_GB_MASK            (0x1U)
#define EMAC_MAC_MDIO_ADDRESS_GB_SHIFT           (0U)
/*! GB - GMII Busy
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_MDIO_ADDRESS_GB(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_MDIO_ADDRESS_GB_SHIFT)) & EMAC_MAC_MDIO_ADDRESS_GB_MASK)

#define EMAC_MAC_MDIO_ADDRESS_C45E_MASK          (0x2U)
#define EMAC_MAC_MDIO_ADDRESS_C45E_SHIFT         (1U)
/*! C45E - Clause 45 PHY Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_MDIO_ADDRESS_C45E(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_MDIO_ADDRESS_C45E_SHIFT)) & EMAC_MAC_MDIO_ADDRESS_C45E_MASK)

#define EMAC_MAC_MDIO_ADDRESS_GOC_0_MASK         (0x4U)
#define EMAC_MAC_MDIO_ADDRESS_GOC_0_SHIFT        (2U)
/*! GOC_0 - GMII Operation Command 0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_MDIO_ADDRESS_GOC_0(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_MDIO_ADDRESS_GOC_0_SHIFT)) & EMAC_MAC_MDIO_ADDRESS_GOC_0_MASK)

#define EMAC_MAC_MDIO_ADDRESS_GOC_1_MASK         (0x8U)
#define EMAC_MAC_MDIO_ADDRESS_GOC_1_SHIFT        (3U)
/*! GOC_1 - GMII Operation Command 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_MDIO_ADDRESS_GOC_1(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_MDIO_ADDRESS_GOC_1_SHIFT)) & EMAC_MAC_MDIO_ADDRESS_GOC_1_MASK)

#define EMAC_MAC_MDIO_ADDRESS_SKAP_MASK          (0x10U)
#define EMAC_MAC_MDIO_ADDRESS_SKAP_SHIFT         (4U)
/*! SKAP - Skip Address Packet
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_MDIO_ADDRESS_SKAP(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_MDIO_ADDRESS_SKAP_SHIFT)) & EMAC_MAC_MDIO_ADDRESS_SKAP_MASK)

#define EMAC_MAC_MDIO_ADDRESS_CR_MASK            (0xF00U)
#define EMAC_MAC_MDIO_ADDRESS_CR_SHIFT           (8U)
/*! CR - CSR Clock Range */
#define EMAC_MAC_MDIO_ADDRESS_CR(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_MDIO_ADDRESS_CR_SHIFT)) & EMAC_MAC_MDIO_ADDRESS_CR_MASK)

#define EMAC_MAC_MDIO_ADDRESS_NTC_MASK           (0x7000U)
#define EMAC_MAC_MDIO_ADDRESS_NTC_SHIFT          (12U)
/*! NTC - Number Of Trailing Clocks */
#define EMAC_MAC_MDIO_ADDRESS_NTC(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_MDIO_ADDRESS_NTC_SHIFT)) & EMAC_MAC_MDIO_ADDRESS_NTC_MASK)

#define EMAC_MAC_MDIO_ADDRESS_RDA_MASK           (0x1F0000U)
#define EMAC_MAC_MDIO_ADDRESS_RDA_SHIFT          (16U)
/*! RDA - Register Or Device Address */
#define EMAC_MAC_MDIO_ADDRESS_RDA(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_MDIO_ADDRESS_RDA_SHIFT)) & EMAC_MAC_MDIO_ADDRESS_RDA_MASK)

#define EMAC_MAC_MDIO_ADDRESS_PA_MASK            (0x3E00000U)
#define EMAC_MAC_MDIO_ADDRESS_PA_SHIFT           (21U)
/*! PA - Physical Layer Address */
#define EMAC_MAC_MDIO_ADDRESS_PA(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_MDIO_ADDRESS_PA_SHIFT)) & EMAC_MAC_MDIO_ADDRESS_PA_MASK)

#define EMAC_MAC_MDIO_ADDRESS_BTB_MASK           (0x4000000U)
#define EMAC_MAC_MDIO_ADDRESS_BTB_SHIFT          (26U)
/*! BTB - Back-To-Back Transactions
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_MDIO_ADDRESS_BTB(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_MDIO_ADDRESS_BTB_SHIFT)) & EMAC_MAC_MDIO_ADDRESS_BTB_MASK)

#define EMAC_MAC_MDIO_ADDRESS_PSE_MASK           (0x8000000U)
#define EMAC_MAC_MDIO_ADDRESS_PSE_SHIFT          (27U)
/*! PSE - Preamble Suppression Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_MDIO_ADDRESS_PSE(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_MDIO_ADDRESS_PSE_SHIFT)) & EMAC_MAC_MDIO_ADDRESS_PSE_MASK)
/*! @} */

/*! @name MAC_MDIO_DATA - MAC MDIO Data */
/*! @{ */

#define EMAC_MAC_MDIO_DATA_GD_MASK               (0xFFFFU)
#define EMAC_MAC_MDIO_DATA_GD_SHIFT              (0U)
/*! GD - GMII Data */
#define EMAC_MAC_MDIO_DATA_GD(x)                 (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_MDIO_DATA_GD_SHIFT)) & EMAC_MAC_MDIO_DATA_GD_MASK)

#define EMAC_MAC_MDIO_DATA_RA_MASK               (0xFFFF0000U)
#define EMAC_MAC_MDIO_DATA_RA_SHIFT              (16U)
/*! RA - Register Address */
#define EMAC_MAC_MDIO_DATA_RA(x)                 (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_MDIO_DATA_RA_SHIFT)) & EMAC_MAC_MDIO_DATA_RA_MASK)
/*! @} */

/*! @name MAC_CSR_SW_CTRL - MAC CSR Software Control */
/*! @{ */

#define EMAC_MAC_CSR_SW_CTRL_RCWE_MASK           (0x1U)
#define EMAC_MAC_CSR_SW_CTRL_RCWE_SHIFT          (0U)
/*! RCWE - Enable Register Write 1 To Clear (W1C)
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_CSR_SW_CTRL_RCWE(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CSR_SW_CTRL_RCWE_SHIFT)) & EMAC_MAC_CSR_SW_CTRL_RCWE_MASK)

#define EMAC_MAC_CSR_SW_CTRL_SEEN_MASK           (0x100U)
#define EMAC_MAC_CSR_SW_CTRL_SEEN_SHIFT          (8U)
/*! SEEN - Slave Error Response Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_CSR_SW_CTRL_SEEN(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_CSR_SW_CTRL_SEEN_SHIFT)) & EMAC_MAC_CSR_SW_CTRL_SEEN_MASK)
/*! @} */

/*! @name MAC_FPE_CTRL_STS - MAC FPE Control STS */
/*! @{ */

#define EMAC_MAC_FPE_CTRL_STS_EFPE_MASK          (0x1U)
#define EMAC_MAC_FPE_CTRL_STS_EFPE_SHIFT         (0U)
/*! EFPE - Enable Transmit Frame Preemption
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_FPE_CTRL_STS_EFPE(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FPE_CTRL_STS_EFPE_SHIFT)) & EMAC_MAC_FPE_CTRL_STS_EFPE_MASK)

#define EMAC_MAC_FPE_CTRL_STS_SVER_MASK          (0x2U)
#define EMAC_MAC_FPE_CTRL_STS_SVER_SHIFT         (1U)
/*! SVER - Send Verify mPacket
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_FPE_CTRL_STS_SVER(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FPE_CTRL_STS_SVER_SHIFT)) & EMAC_MAC_FPE_CTRL_STS_SVER_MASK)

#define EMAC_MAC_FPE_CTRL_STS_SRSP_MASK          (0x4U)
#define EMAC_MAC_FPE_CTRL_STS_SRSP_SHIFT         (2U)
/*! SRSP - Send Respond mPacket
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_FPE_CTRL_STS_SRSP(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FPE_CTRL_STS_SRSP_SHIFT)) & EMAC_MAC_FPE_CTRL_STS_SRSP_MASK)

#define EMAC_MAC_FPE_CTRL_STS_S1_SET_0_MASK      (0x8U)
#define EMAC_MAC_FPE_CTRL_STS_S1_SET_0_SHIFT     (3U)
/*! S1_SET_0 - S1 SET 0 */
#define EMAC_MAC_FPE_CTRL_STS_S1_SET_0(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FPE_CTRL_STS_S1_SET_0_SHIFT)) & EMAC_MAC_FPE_CTRL_STS_S1_SET_0_MASK)

#define EMAC_MAC_FPE_CTRL_STS_RVER_MASK          (0x10000U)
#define EMAC_MAC_FPE_CTRL_STS_RVER_SHIFT         (16U)
/*! RVER - Received Verify Frame
 *  0b0..Not received
 *  0b1..Received
 */
#define EMAC_MAC_FPE_CTRL_STS_RVER(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FPE_CTRL_STS_RVER_SHIFT)) & EMAC_MAC_FPE_CTRL_STS_RVER_MASK)

#define EMAC_MAC_FPE_CTRL_STS_RRSP_MASK          (0x20000U)
#define EMAC_MAC_FPE_CTRL_STS_RRSP_SHIFT         (17U)
/*! RRSP - Received Respond Frame
 *  0b0..Not received
 *  0b1..Received
 */
#define EMAC_MAC_FPE_CTRL_STS_RRSP(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FPE_CTRL_STS_RRSP_SHIFT)) & EMAC_MAC_FPE_CTRL_STS_RRSP_MASK)

#define EMAC_MAC_FPE_CTRL_STS_TVER_MASK          (0x40000U)
#define EMAC_MAC_FPE_CTRL_STS_TVER_SHIFT         (18U)
/*! TVER - Transmitted Verify Frame
 *  0b0..Not transmitted
 *  0b1..Transmitted
 */
#define EMAC_MAC_FPE_CTRL_STS_TVER(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FPE_CTRL_STS_TVER_SHIFT)) & EMAC_MAC_FPE_CTRL_STS_TVER_MASK)

#define EMAC_MAC_FPE_CTRL_STS_TRSP_MASK          (0x80000U)
#define EMAC_MAC_FPE_CTRL_STS_TRSP_SHIFT         (19U)
/*! TRSP - Transmitted Respond Frame
 *  0b0..Not transmitted
 *  0b1..Transmitted
 */
#define EMAC_MAC_FPE_CTRL_STS_TRSP(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_FPE_CTRL_STS_TRSP_SHIFT)) & EMAC_MAC_FPE_CTRL_STS_TRSP_MASK)
/*! @} */

/*! @name MAC_PRESN_TIME_NS - MAC Presentation Time */
/*! @{ */

#define EMAC_MAC_PRESN_TIME_NS_MPTN_MASK         (0xFFFFFFFFU)
#define EMAC_MAC_PRESN_TIME_NS_MPTN_SHIFT        (0U)
/*! MPTN - MAC 1722 Presentation Time (In Nanoseconds) */
#define EMAC_MAC_PRESN_TIME_NS_MPTN(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PRESN_TIME_NS_MPTN_SHIFT)) & EMAC_MAC_PRESN_TIME_NS_MPTN_MASK)
/*! @} */

/*! @name MAC_PRESN_TIME_UPDT - MAC Presentation Time Update */
/*! @{ */

#define EMAC_MAC_PRESN_TIME_UPDT_MPTU_MASK       (0xFFFFFFFFU)
#define EMAC_MAC_PRESN_TIME_UPDT_MPTU_SHIFT      (0U)
/*! MPTU - MAC 1722 Presentation Time Update */
#define EMAC_MAC_PRESN_TIME_UPDT_MPTU(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PRESN_TIME_UPDT_MPTU_SHIFT)) & EMAC_MAC_PRESN_TIME_UPDT_MPTU_MASK)
/*! @} */

/*! @name MAC_ADDRESS0_HIGH - MAC Address 0 High */
/*! @{ */

#define EMAC_MAC_ADDRESS0_HIGH_ADDRHI_MASK       (0xFFFFU)
#define EMAC_MAC_ADDRESS0_HIGH_ADDRHI_SHIFT      (0U)
/*! ADDRHI - MAC Address 0 [47:32] */
#define EMAC_MAC_ADDRESS0_HIGH_ADDRHI(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS0_HIGH_ADDRHI_SHIFT)) & EMAC_MAC_ADDRESS0_HIGH_ADDRHI_MASK)

#define EMAC_MAC_ADDRESS0_HIGH_DCS_MASK          (0x30000U)
#define EMAC_MAC_ADDRESS0_HIGH_DCS_SHIFT         (16U)
/*! DCS - DMA Channel Select */
#define EMAC_MAC_ADDRESS0_HIGH_DCS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS0_HIGH_DCS_SHIFT)) & EMAC_MAC_ADDRESS0_HIGH_DCS_MASK)

#define EMAC_MAC_ADDRESS0_HIGH_AE_MASK           (0x80000000U)
#define EMAC_MAC_ADDRESS0_HIGH_AE_SHIFT          (31U)
/*! AE - Address Enable
 *  0b0..Disabled and invalid (the field's value must always be 1)
 *  0b1..Enabled
 */
#define EMAC_MAC_ADDRESS0_HIGH_AE(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS0_HIGH_AE_SHIFT)) & EMAC_MAC_ADDRESS0_HIGH_AE_MASK)
/*! @} */

/*! @name MAC_ADDRESS0_LOW - MAC Address 0 Low */
/*! @{ */

#define EMAC_MAC_ADDRESS0_LOW_ADDRLO_MASK        (0xFFFFFFFFU)
#define EMAC_MAC_ADDRESS0_LOW_ADDRLO_SHIFT       (0U)
/*! ADDRLO - MAC Address 0 [31:0] */
#define EMAC_MAC_ADDRESS0_LOW_ADDRLO(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS0_LOW_ADDRLO_SHIFT)) & EMAC_MAC_ADDRESS0_LOW_ADDRLO_MASK)
/*! @} */

/*! @name MAC_ADDRESS1_HIGH - MAC Address 1 High */
/*! @{ */

#define EMAC_MAC_ADDRESS1_HIGH_ADDRHI_MASK       (0xFFFFU)
#define EMAC_MAC_ADDRESS1_HIGH_ADDRHI_SHIFT      (0U)
/*! ADDRHI - MAC Address 1 [47:32] */
#define EMAC_MAC_ADDRESS1_HIGH_ADDRHI(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS1_HIGH_ADDRHI_SHIFT)) & EMAC_MAC_ADDRESS1_HIGH_ADDRHI_MASK)

#define EMAC_MAC_ADDRESS1_HIGH_DCS_MASK          (0x30000U)
#define EMAC_MAC_ADDRESS1_HIGH_DCS_SHIFT         (16U)
/*! DCS - DMA Channel Select */
#define EMAC_MAC_ADDRESS1_HIGH_DCS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS1_HIGH_DCS_SHIFT)) & EMAC_MAC_ADDRESS1_HIGH_DCS_MASK)

#define EMAC_MAC_ADDRESS1_HIGH_MBC_MASK          (0x3F000000U)
#define EMAC_MAC_ADDRESS1_HIGH_MBC_SHIFT         (24U)
/*! MBC - Mask Byte Control */
#define EMAC_MAC_ADDRESS1_HIGH_MBC(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS1_HIGH_MBC_SHIFT)) & EMAC_MAC_ADDRESS1_HIGH_MBC_MASK)

#define EMAC_MAC_ADDRESS1_HIGH_SA_MASK           (0x40000000U)
#define EMAC_MAC_ADDRESS1_HIGH_SA_SHIFT          (30U)
/*! SA - Source Address
 *  0b0..Destination address
 *  0b1..Source address
 */
#define EMAC_MAC_ADDRESS1_HIGH_SA(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS1_HIGH_SA_SHIFT)) & EMAC_MAC_ADDRESS1_HIGH_SA_MASK)

#define EMAC_MAC_ADDRESS1_HIGH_AE_MASK           (0x80000000U)
#define EMAC_MAC_ADDRESS1_HIGH_AE_SHIFT          (31U)
/*! AE - Address Enable
 *  0b0..Ignored
 *  0b1..Enabled
 */
#define EMAC_MAC_ADDRESS1_HIGH_AE(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS1_HIGH_AE_SHIFT)) & EMAC_MAC_ADDRESS1_HIGH_AE_MASK)
/*! @} */

/*! @name MAC_ADDRESS1_LOW - MAC Address 1 Low */
/*! @{ */

#define EMAC_MAC_ADDRESS1_LOW_ADDRLO_MASK        (0xFFFFFFFFU)
#define EMAC_MAC_ADDRESS1_LOW_ADDRLO_SHIFT       (0U)
/*! ADDRLO - MAC Address 1 [31:0] */
#define EMAC_MAC_ADDRESS1_LOW_ADDRLO(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS1_LOW_ADDRLO_SHIFT)) & EMAC_MAC_ADDRESS1_LOW_ADDRLO_MASK)
/*! @} */

/*! @name MAC_ADDRESS2_HIGH - MAC Address 2 High */
/*! @{ */

#define EMAC_MAC_ADDRESS2_HIGH_ADDRHI_MASK       (0xFFFFU)
#define EMAC_MAC_ADDRESS2_HIGH_ADDRHI_SHIFT      (0U)
/*! ADDRHI - MAC Address 1 [47:32] */
#define EMAC_MAC_ADDRESS2_HIGH_ADDRHI(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS2_HIGH_ADDRHI_SHIFT)) & EMAC_MAC_ADDRESS2_HIGH_ADDRHI_MASK)

#define EMAC_MAC_ADDRESS2_HIGH_DCS_MASK          (0x30000U)
#define EMAC_MAC_ADDRESS2_HIGH_DCS_SHIFT         (16U)
/*! DCS - DMA Channel Select */
#define EMAC_MAC_ADDRESS2_HIGH_DCS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS2_HIGH_DCS_SHIFT)) & EMAC_MAC_ADDRESS2_HIGH_DCS_MASK)

#define EMAC_MAC_ADDRESS2_HIGH_MBC_MASK          (0x3F000000U)
#define EMAC_MAC_ADDRESS2_HIGH_MBC_SHIFT         (24U)
/*! MBC - Mask Byte Control */
#define EMAC_MAC_ADDRESS2_HIGH_MBC(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS2_HIGH_MBC_SHIFT)) & EMAC_MAC_ADDRESS2_HIGH_MBC_MASK)

#define EMAC_MAC_ADDRESS2_HIGH_SA_MASK           (0x40000000U)
#define EMAC_MAC_ADDRESS2_HIGH_SA_SHIFT          (30U)
/*! SA - Source Address
 *  0b0..Destination address
 *  0b1..Source address
 */
#define EMAC_MAC_ADDRESS2_HIGH_SA(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS2_HIGH_SA_SHIFT)) & EMAC_MAC_ADDRESS2_HIGH_SA_MASK)

#define EMAC_MAC_ADDRESS2_HIGH_AE_MASK           (0x80000000U)
#define EMAC_MAC_ADDRESS2_HIGH_AE_SHIFT          (31U)
/*! AE - Address Enable
 *  0b0..Ignored
 *  0b1..Enabled
 */
#define EMAC_MAC_ADDRESS2_HIGH_AE(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS2_HIGH_AE_SHIFT)) & EMAC_MAC_ADDRESS2_HIGH_AE_MASK)
/*! @} */

/*! @name MAC_ADDRESS2_LOW - MAC Address 2 Low */
/*! @{ */

#define EMAC_MAC_ADDRESS2_LOW_ADDRLO_MASK        (0xFFFFFFFFU)
#define EMAC_MAC_ADDRESS2_LOW_ADDRLO_SHIFT       (0U)
/*! ADDRLO - MAC Address 1 [31:0] */
#define EMAC_MAC_ADDRESS2_LOW_ADDRLO(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_ADDRESS2_LOW_ADDRLO_SHIFT)) & EMAC_MAC_ADDRESS2_LOW_ADDRLO_MASK)
/*! @} */

/*! @name MMC_CONTROL - MMC Control */
/*! @{ */

#define EMAC_MMC_CONTROL_CNTRST_MASK             (0x1U)
#define EMAC_MMC_CONTROL_CNTRST_SHIFT            (0U)
/*! CNTRST - Counters Reset
 *  0b0..Counters are not reset
 *  0b1..All counters are reset
 */
#define EMAC_MMC_CONTROL_CNTRST(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_CONTROL_CNTRST_SHIFT)) & EMAC_MMC_CONTROL_CNTRST_MASK)

#define EMAC_MMC_CONTROL_CNTSTOPRO_MASK          (0x2U)
#define EMAC_MMC_CONTROL_CNTSTOPRO_SHIFT         (1U)
/*! CNTSTOPRO - Counter Stop Rollover
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_CONTROL_CNTSTOPRO(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_CONTROL_CNTSTOPRO_SHIFT)) & EMAC_MMC_CONTROL_CNTSTOPRO_MASK)

#define EMAC_MMC_CONTROL_RSTONRD_MASK            (0x4U)
#define EMAC_MMC_CONTROL_RSTONRD_SHIFT           (2U)
/*! RSTONRD - Reset On Read
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_CONTROL_RSTONRD(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_CONTROL_RSTONRD_SHIFT)) & EMAC_MMC_CONTROL_RSTONRD_MASK)

#define EMAC_MMC_CONTROL_CNTFREEZ_MASK           (0x8U)
#define EMAC_MMC_CONTROL_CNTFREEZ_SHIFT          (3U)
/*! CNTFREEZ - MMC Counter Freeze
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_CONTROL_CNTFREEZ(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_CONTROL_CNTFREEZ_SHIFT)) & EMAC_MMC_CONTROL_CNTFREEZ_MASK)

#define EMAC_MMC_CONTROL_CNTPRST_MASK            (0x10U)
#define EMAC_MMC_CONTROL_CNTPRST_SHIFT           (4U)
/*! CNTPRST - Counters Preset
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_CONTROL_CNTPRST(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_CONTROL_CNTPRST_SHIFT)) & EMAC_MMC_CONTROL_CNTPRST_MASK)

#define EMAC_MMC_CONTROL_CNTPRSTLVL_MASK         (0x20U)
#define EMAC_MMC_CONTROL_CNTPRSTLVL_SHIFT        (5U)
/*! CNTPRSTLVL - Full-Half Preset
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_CONTROL_CNTPRSTLVL(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_CONTROL_CNTPRSTLVL_SHIFT)) & EMAC_MMC_CONTROL_CNTPRSTLVL_MASK)

#define EMAC_MMC_CONTROL_UCDBC_MASK              (0x100U)
#define EMAC_MMC_CONTROL_UCDBC_SHIFT             (8U)
/*! UCDBC - Update MMC Counters For Dropped Broadcast Packets
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_CONTROL_UCDBC(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_CONTROL_UCDBC_SHIFT)) & EMAC_MMC_CONTROL_UCDBC_MASK)
/*! @} */

/*! @name MMC_RX_INTERRUPT - MMC Receive Interrupt */
/*! @{ */

#define EMAC_MMC_RX_INTERRUPT_RXGBPKTIS_MASK     (0x1U)
#define EMAC_MMC_RX_INTERRUPT_RXGBPKTIS_SHIFT    (0U)
/*! RXGBPKTIS - MMC Receive Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXGBPKTIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXGBPKTIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXGBPKTIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXGBOCTIS_MASK     (0x2U)
#define EMAC_MMC_RX_INTERRUPT_RXGBOCTIS_SHIFT    (1U)
/*! RXGBOCTIS - MMC Receive Good Bad Octet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXGBOCTIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXGBOCTIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXGBOCTIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXGOCTIS_MASK      (0x4U)
#define EMAC_MMC_RX_INTERRUPT_RXGOCTIS_SHIFT     (2U)
/*! RXGOCTIS - MMC Receive Good Octet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXGOCTIS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXGOCTIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXGOCTIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXBCGPIS_MASK      (0x8U)
#define EMAC_MMC_RX_INTERRUPT_RXBCGPIS_SHIFT     (3U)
/*! RXBCGPIS - MMC Receive Broadcast Good Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXBCGPIS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXBCGPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXBCGPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXMCGPIS_MASK      (0x10U)
#define EMAC_MMC_RX_INTERRUPT_RXMCGPIS_SHIFT     (4U)
/*! RXMCGPIS - MMC Receive Multicast Good Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXMCGPIS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXMCGPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXMCGPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXCRCERPIS_MASK    (0x20U)
#define EMAC_MMC_RX_INTERRUPT_RXCRCERPIS_SHIFT   (5U)
/*! RXCRCERPIS - MMC Receive CRC Error Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXCRCERPIS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXCRCERPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXCRCERPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXALGNERPIS_MASK   (0x40U)
#define EMAC_MMC_RX_INTERRUPT_RXALGNERPIS_SHIFT  (6U)
/*! RXALGNERPIS - MMC Receive Alignment Error Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXALGNERPIS(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXALGNERPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXALGNERPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXRUNTPIS_MASK     (0x80U)
#define EMAC_MMC_RX_INTERRUPT_RXRUNTPIS_SHIFT    (7U)
/*! RXRUNTPIS - MMC Receive Runt Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXRUNTPIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXRUNTPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXRUNTPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXJABERPIS_MASK    (0x100U)
#define EMAC_MMC_RX_INTERRUPT_RXJABERPIS_SHIFT   (8U)
/*! RXJABERPIS - MMC Receive Jabber Error Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXJABERPIS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXJABERPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXJABERPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXUSIZEGPIS_MASK   (0x200U)
#define EMAC_MMC_RX_INTERRUPT_RXUSIZEGPIS_SHIFT  (9U)
/*! RXUSIZEGPIS - MMC Receive Undersize Good Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXUSIZEGPIS(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXUSIZEGPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXUSIZEGPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXOSIZEGPIS_MASK   (0x400U)
#define EMAC_MMC_RX_INTERRUPT_RXOSIZEGPIS_SHIFT  (10U)
/*! RXOSIZEGPIS - MMC Receive Oversize Good Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXOSIZEGPIS(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXOSIZEGPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXOSIZEGPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RX64OCTGBPIS_MASK  (0x800U)
#define EMAC_MMC_RX_INTERRUPT_RX64OCTGBPIS_SHIFT (11U)
/*! RX64OCTGBPIS - MMC Receive 64 Octet Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RX64OCTGBPIS(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RX64OCTGBPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RX64OCTGBPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_MASK (0x1000U)
#define EMAC_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_SHIFT (12U)
/*! RX65T127OCTGBPIS - MMC Receive 65 To 127 Octet Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RX65T127OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_MASK (0x2000U)
#define EMAC_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_SHIFT (13U)
/*! RX128T255OCTGBPIS - MMC Receive 128 To 255 Octet Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RX128T255OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_MASK (0x4000U)
#define EMAC_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_SHIFT (14U)
/*! RX256T511OCTGBPIS - MMC Receive 256 To 511 Octet Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RX256T511OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_MASK (0x8000U)
#define EMAC_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_SHIFT (15U)
/*! RX512T1023OCTGBPIS - MMC Receive 512 To 1023 Octet Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_MASK (0x10000U)
#define EMAC_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_SHIFT (16U)
/*! RX1024TMAXOCTGBPIS - MMC Receive 1024 To Maximum Octet Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXUCGPIS_MASK      (0x20000U)
#define EMAC_MMC_RX_INTERRUPT_RXUCGPIS_SHIFT     (17U)
/*! RXUCGPIS - MMC Receive Unicast Good Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXUCGPIS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXUCGPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXUCGPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXLENERPIS_MASK    (0x40000U)
#define EMAC_MMC_RX_INTERRUPT_RXLENERPIS_SHIFT   (18U)
/*! RXLENERPIS - MMC Receive Length Error Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXLENERPIS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXLENERPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXLENERPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXORANGEPIS_MASK   (0x80000U)
#define EMAC_MMC_RX_INTERRUPT_RXORANGEPIS_SHIFT  (19U)
/*! RXORANGEPIS - MMC Receive Out-Of-Range Error Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXORANGEPIS(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXORANGEPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXORANGEPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXPAUSPIS_MASK     (0x100000U)
#define EMAC_MMC_RX_INTERRUPT_RXPAUSPIS_SHIFT    (20U)
/*! RXPAUSPIS - MMC Receive Pause Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXPAUSPIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXPAUSPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXPAUSPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXFOVPIS_MASK      (0x200000U)
#define EMAC_MMC_RX_INTERRUPT_RXFOVPIS_SHIFT     (21U)
/*! RXFOVPIS - MMC Receive FIFO Overflow Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXFOVPIS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXFOVPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXFOVPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXVLANGBPIS_MASK   (0x400000U)
#define EMAC_MMC_RX_INTERRUPT_RXVLANGBPIS_SHIFT  (22U)
/*! RXVLANGBPIS - MMC Receive VLAN Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXVLANGBPIS(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXVLANGBPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXVLANGBPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXWDOGPIS_MASK     (0x800000U)
#define EMAC_MMC_RX_INTERRUPT_RXWDOGPIS_SHIFT    (23U)
/*! RXWDOGPIS - MMC Receive Watchdog Error Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXWDOGPIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXWDOGPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXWDOGPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXRCVERRPIS_MASK   (0x1000000U)
#define EMAC_MMC_RX_INTERRUPT_RXRCVERRPIS_SHIFT  (24U)
/*! RXRCVERRPIS - MMC Receive Error Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXRCVERRPIS(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXRCVERRPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXRCVERRPIS_MASK)

#define EMAC_MMC_RX_INTERRUPT_RXCTRLPIS_MASK     (0x2000000U)
#define EMAC_MMC_RX_INTERRUPT_RXCTRLPIS_SHIFT    (25U)
/*! RXCTRLPIS - MMC Receive Control Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_RX_INTERRUPT_RXCTRLPIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_RXCTRLPIS_SHIFT)) & EMAC_MMC_RX_INTERRUPT_RXCTRLPIS_MASK)
/*! @} */

/*! @name MMC_TX_INTERRUPT - MMC Transmit Interrupt */
/*! @{ */

#define EMAC_MMC_TX_INTERRUPT_TXGBOCTIS_MASK     (0x1U)
#define EMAC_MMC_TX_INTERRUPT_TXGBOCTIS_SHIFT    (0U)
/*! TXGBOCTIS - MMC Transmit Good Bad Octet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXGBOCTIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXGBOCTIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXGBOCTIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXGBPKTIS_MASK     (0x2U)
#define EMAC_MMC_TX_INTERRUPT_TXGBPKTIS_SHIFT    (1U)
/*! TXGBPKTIS - MMC Transmit Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXGBPKTIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXGBPKTIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXGBPKTIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXBCGPIS_MASK      (0x4U)
#define EMAC_MMC_TX_INTERRUPT_TXBCGPIS_SHIFT     (2U)
/*! TXBCGPIS - MMC Transmit Broadcast Good Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXBCGPIS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXBCGPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXBCGPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXMCGPIS_MASK      (0x8U)
#define EMAC_MMC_TX_INTERRUPT_TXMCGPIS_SHIFT     (3U)
/*! TXMCGPIS - MMC Transmit Multicast Good Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXMCGPIS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXMCGPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXMCGPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TX64OCTGBPIS_MASK  (0x10U)
#define EMAC_MMC_TX_INTERRUPT_TX64OCTGBPIS_SHIFT (4U)
/*! TX64OCTGBPIS - MMC Transmit 64-Octet Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TX64OCTGBPIS(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TX64OCTGBPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TX64OCTGBPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_MASK (0x20U)
#define EMAC_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_SHIFT (5U)
/*! TX65T127OCTGBPIS - MMC Transmit 65 To 127 Octet Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TX65T127OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_MASK (0x40U)
#define EMAC_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_SHIFT (6U)
/*! TX128T255OCTGBPIS - MMC Transmit 128 To 255 Octet Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TX128T255OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_MASK (0x80U)
#define EMAC_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_SHIFT (7U)
/*! TX256T511OCTGBPIS - MMC Transmit 256 To 511 Octet Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TX256T511OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_MASK (0x100U)
#define EMAC_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_SHIFT (8U)
/*! TX512T1023OCTGBPIS - MMC Transmit 512 To 1023 Octet Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_MASK (0x200U)
#define EMAC_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_SHIFT (9U)
/*! TX1024TMAXOCTGBPIS - MMC Transmit 1024 To Maximum Octet Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXUCGBPIS_MASK     (0x400U)
#define EMAC_MMC_TX_INTERRUPT_TXUCGBPIS_SHIFT    (10U)
/*! TXUCGBPIS - MMC Transmit Unicast Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXUCGBPIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXUCGBPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXUCGBPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXMCGBPIS_MASK     (0x800U)
#define EMAC_MMC_TX_INTERRUPT_TXMCGBPIS_SHIFT    (11U)
/*! TXMCGBPIS - MMC Transmit Multicast Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXMCGBPIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXMCGBPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXMCGBPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXBCGBPIS_MASK     (0x1000U)
#define EMAC_MMC_TX_INTERRUPT_TXBCGBPIS_SHIFT    (12U)
/*! TXBCGBPIS - MMC Transmit Broadcast Good Bad Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXBCGBPIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXBCGBPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXBCGBPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXUFLOWERPIS_MASK  (0x2000U)
#define EMAC_MMC_TX_INTERRUPT_TXUFLOWERPIS_SHIFT (13U)
/*! TXUFLOWERPIS - MMC Transmit Underflow Error Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXUFLOWERPIS(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXUFLOWERPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXUFLOWERPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXSCOLGPIS_MASK    (0x4000U)
#define EMAC_MMC_TX_INTERRUPT_TXSCOLGPIS_SHIFT   (14U)
/*! TXSCOLGPIS - MMC Transmit Single Collision Good Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXSCOLGPIS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXSCOLGPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXSCOLGPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXMCOLGPIS_MASK    (0x8000U)
#define EMAC_MMC_TX_INTERRUPT_TXMCOLGPIS_SHIFT   (15U)
/*! TXMCOLGPIS - MMC Transmit Multiple Collision Good Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXMCOLGPIS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXMCOLGPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXMCOLGPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXDEFPIS_MASK      (0x10000U)
#define EMAC_MMC_TX_INTERRUPT_TXDEFPIS_SHIFT     (16U)
/*! TXDEFPIS - MMC Transmit Deferred Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXDEFPIS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXDEFPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXDEFPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXLATCOLPIS_MASK   (0x20000U)
#define EMAC_MMC_TX_INTERRUPT_TXLATCOLPIS_SHIFT  (17U)
/*! TXLATCOLPIS - MMC Transmit Late Collision Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXLATCOLPIS(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXLATCOLPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXLATCOLPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXEXCOLPIS_MASK    (0x40000U)
#define EMAC_MMC_TX_INTERRUPT_TXEXCOLPIS_SHIFT   (18U)
/*! TXEXCOLPIS - MMC Transmit Excessive Collision Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXEXCOLPIS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXEXCOLPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXEXCOLPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXCARERPIS_MASK    (0x80000U)
#define EMAC_MMC_TX_INTERRUPT_TXCARERPIS_SHIFT   (19U)
/*! TXCARERPIS - MMC Transmit Carrier Error Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXCARERPIS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXCARERPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXCARERPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXGOCTIS_MASK      (0x100000U)
#define EMAC_MMC_TX_INTERRUPT_TXGOCTIS_SHIFT     (20U)
/*! TXGOCTIS - MMC Transmit Good Octet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXGOCTIS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXGOCTIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXGOCTIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXGPKTIS_MASK      (0x200000U)
#define EMAC_MMC_TX_INTERRUPT_TXGPKTIS_SHIFT     (21U)
/*! TXGPKTIS - MMC Transmit Good Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXGPKTIS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXGPKTIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXGPKTIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXEXDEFPIS_MASK    (0x400000U)
#define EMAC_MMC_TX_INTERRUPT_TXEXDEFPIS_SHIFT   (22U)
/*! TXEXDEFPIS - MMC Transmit Excessive Deferral Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXEXDEFPIS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXEXDEFPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXEXDEFPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXPAUSPIS_MASK     (0x800000U)
#define EMAC_MMC_TX_INTERRUPT_TXPAUSPIS_SHIFT    (23U)
/*! TXPAUSPIS - MMC Transmit Pause Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXPAUSPIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXPAUSPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXPAUSPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXVLANGPIS_MASK    (0x1000000U)
#define EMAC_MMC_TX_INTERRUPT_TXVLANGPIS_SHIFT   (24U)
/*! TXVLANGPIS - MMC Transmit VLAN Good Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXVLANGPIS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXVLANGPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXVLANGPIS_MASK)

#define EMAC_MMC_TX_INTERRUPT_TXOSIZEGPIS_MASK   (0x2000000U)
#define EMAC_MMC_TX_INTERRUPT_TXOSIZEGPIS_SHIFT  (25U)
/*! TXOSIZEGPIS - MMC Transmit Oversize Good Packet Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_TX_INTERRUPT_TXOSIZEGPIS(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_TXOSIZEGPIS_SHIFT)) & EMAC_MMC_TX_INTERRUPT_TXOSIZEGPIS_MASK)
/*! @} */

/*! @name MMC_RX_INTERRUPT_MASK - MMC Receive Interrupt Mask */
/*! @{ */

#define EMAC_MMC_RX_INTERRUPT_MASK_RXGBPKTIM_MASK (0x1U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXGBPKTIM_SHIFT (0U)
/*! RXGBPKTIM - MMC Receive Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXGBPKTIM(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXGBPKTIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXGBPKTIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXGBOCTIM_MASK (0x2U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXGBOCTIM_SHIFT (1U)
/*! RXGBOCTIM - MMC Receive Good Bad Octet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXGBOCTIM(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXGBOCTIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXGBOCTIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXGOCTIM_MASK (0x4U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXGOCTIM_SHIFT (2U)
/*! RXGOCTIM - MMC Receive Good Octet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXGOCTIM(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXGOCTIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXGOCTIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXBCGPIM_MASK (0x8U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXBCGPIM_SHIFT (3U)
/*! RXBCGPIM - MMC Receive Broadcast Good Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXBCGPIM(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXBCGPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXBCGPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXMCGPIM_MASK (0x10U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXMCGPIM_SHIFT (4U)
/*! RXMCGPIM - MMC Receive Multicast Good Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXMCGPIM(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXMCGPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXMCGPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXCRCERPIM_MASK (0x20U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXCRCERPIM_SHIFT (5U)
/*! RXCRCERPIM - MMC Receive CRC Error Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXCRCERPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXCRCERPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXCRCERPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXALGNERPIM_MASK (0x40U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXALGNERPIM_SHIFT (6U)
/*! RXALGNERPIM - MMC Receive Alignment Error Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXALGNERPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXALGNERPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXALGNERPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXRUNTPIM_MASK (0x80U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXRUNTPIM_SHIFT (7U)
/*! RXRUNTPIM - MMC Receive Runt Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXRUNTPIM(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXRUNTPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXRUNTPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXJABERPIM_MASK (0x100U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXJABERPIM_SHIFT (8U)
/*! RXJABERPIM - MMC Receive Jabber Error Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXJABERPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXJABERPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXJABERPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM_MASK (0x200U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM_SHIFT (9U)
/*! RXUSIZEGPIM - MMC Receive Undersize Good Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM_MASK (0x400U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM_SHIFT (10U)
/*! RXOSIZEGPIM - MMC Receive Oversize Good Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM_MASK (0x800U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM_SHIFT (11U)
/*! RX64OCTGBPIM - MMC Receive 64-Octet Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM_MASK (0x1000U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM_SHIFT (12U)
/*! RX65T127OCTGBPIM - MMC Receive 65 To 127 Octet Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM_MASK (0x2000U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM_SHIFT (13U)
/*! RX128T255OCTGBPIM - MMC Receive 128 To 255 Octet Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM_MASK (0x4000U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM_SHIFT (14U)
/*! RX256T511OCTGBPIM - MMC Receive 256 To 511 Octet Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM_MASK (0x8000U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM_SHIFT (15U)
/*! RX512T1023OCTGBPIM - MMC Receive 512 To 1023 Octet Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM_MASK (0x10000U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM_SHIFT (16U)
/*! RX1024TMAXOCTGBPIM - MMC Receive 1024 To Maximum Octet Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXUCGPIM_MASK (0x20000U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXUCGPIM_SHIFT (17U)
/*! RXUCGPIM - MMC Receive Unicast Good Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXUCGPIM(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXUCGPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXUCGPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXLENERPIM_MASK (0x40000U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXLENERPIM_SHIFT (18U)
/*! RXLENERPIM - MMC Receive Length Error Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXLENERPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXLENERPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXLENERPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXORANGEPIM_MASK (0x80000U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXORANGEPIM_SHIFT (19U)
/*! RXORANGEPIM - MMC Receive Out-Of-Range Error Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXORANGEPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXORANGEPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXORANGEPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXPAUSPIM_MASK (0x100000U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXPAUSPIM_SHIFT (20U)
/*! RXPAUSPIM - MMC Receive Pause Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXPAUSPIM(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXPAUSPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXPAUSPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXFOVPIM_MASK (0x200000U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXFOVPIM_SHIFT (21U)
/*! RXFOVPIM - MMC Receive FIFO Overflow Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXFOVPIM(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXFOVPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXFOVPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM_MASK (0x400000U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM_SHIFT (22U)
/*! RXVLANGBPIM - MMC Receive VLAN Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXWDOGPIM_MASK (0x800000U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXWDOGPIM_SHIFT (23U)
/*! RXWDOGPIM - MMC Receive Watchdog Error Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXWDOGPIM(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXWDOGPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXWDOGPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM_MASK (0x1000000U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM_SHIFT (24U)
/*! RXRCVERRPIM - MMC Receive Error Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM_MASK)

#define EMAC_MMC_RX_INTERRUPT_MASK_RXCTRLPIM_MASK (0x2000000U)
#define EMAC_MMC_RX_INTERRUPT_MASK_RXCTRLPIM_SHIFT (25U)
/*! RXCTRLPIM - MMC Receive Control Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_RX_INTERRUPT_MASK_RXCTRLPIM(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_INTERRUPT_MASK_RXCTRLPIM_SHIFT)) & EMAC_MMC_RX_INTERRUPT_MASK_RXCTRLPIM_MASK)
/*! @} */

/*! @name MMC_TX_INTERRUPT_MASK - MMC Transmit Interrupt Mask */
/*! @{ */

#define EMAC_MMC_TX_INTERRUPT_MASK_TXGBOCTIM_MASK (0x1U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXGBOCTIM_SHIFT (0U)
/*! TXGBOCTIM - MMC Transmit Good Bad Octet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXGBOCTIM(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXGBOCTIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXGBOCTIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXGBPKTIM_MASK (0x2U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXGBPKTIM_SHIFT (1U)
/*! TXGBPKTIM - MMC Transmit Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXGBPKTIM(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXGBPKTIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXGBPKTIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXBCGPIM_MASK (0x4U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXBCGPIM_SHIFT (2U)
/*! TXBCGPIM - MMC Transmit Broadcast Good Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXBCGPIM(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXBCGPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXBCGPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXMCGPIM_MASK (0x8U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXMCGPIM_SHIFT (3U)
/*! TXMCGPIM - MMC Transmit Multicast Good Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXMCGPIM(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXMCGPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXMCGPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM_MASK (0x10U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM_SHIFT (4U)
/*! TX64OCTGBPIM - MMC Transmit 64-Octet Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM_MASK (0x20U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM_SHIFT (5U)
/*! TX65T127OCTGBPIM - MMC Transmit 65 To 127 Octet Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM_MASK (0x40U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM_SHIFT (6U)
/*! TX128T255OCTGBPIM - MMC Transmit 128 To 255 Octet Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM_MASK (0x80U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM_SHIFT (7U)
/*! TX256T511OCTGBPIM - MMC Transmit 256 To 511 Octet Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM_MASK (0x100U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM_SHIFT (8U)
/*! TX512T1023OCTGBPIM - MMC Transmit 512 To 1023 Octet Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM_MASK (0x200U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM_SHIFT (9U)
/*! TX1024TMAXOCTGBPIM - MMC Transmit 1024 To Maximum Octet Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXUCGBPIM_MASK (0x400U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXUCGBPIM_SHIFT (10U)
/*! TXUCGBPIM - MMC Transmit Unicast Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXUCGBPIM(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXUCGBPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXUCGBPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXMCGBPIM_MASK (0x800U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXMCGBPIM_SHIFT (11U)
/*! TXMCGBPIM - MMC Transmit Multicast Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXMCGBPIM(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXMCGBPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXMCGBPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXBCGBPIM_MASK (0x1000U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXBCGBPIM_SHIFT (12U)
/*! TXBCGBPIM - MMC Transmit Broadcast Good Bad Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXBCGBPIM(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXBCGBPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXBCGBPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM_MASK (0x2000U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM_SHIFT (13U)
/*! TXUFLOWERPIM - MMC Transmit Underflow Error Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM_MASK (0x4000U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM_SHIFT (14U)
/*! TXSCOLGPIM - MMC Transmit Single Collision Good Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM_MASK (0x8000U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM_SHIFT (15U)
/*! TXMCOLGPIM - MMC Transmit Multiple Collision Good Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXDEFPIM_MASK (0x10000U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXDEFPIM_SHIFT (16U)
/*! TXDEFPIM - MMC Transmit Deferred Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXDEFPIM(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXDEFPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXDEFPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM_MASK (0x20000U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM_SHIFT (17U)
/*! TXLATCOLPIM - MMC Transmit Late Collision Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM_MASK (0x40000U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM_SHIFT (18U)
/*! TXEXCOLPIM - MMC Transmit Excessive Collision Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXCARERPIM_MASK (0x80000U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXCARERPIM_SHIFT (19U)
/*! TXCARERPIM - MMC Transmit Carrier Error Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXCARERPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXCARERPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXCARERPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXGOCTIM_MASK (0x100000U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXGOCTIM_SHIFT (20U)
/*! TXGOCTIM - MMC Transmit Good Octet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXGOCTIM(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXGOCTIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXGOCTIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXGPKTIM_MASK (0x200000U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXGPKTIM_SHIFT (21U)
/*! TXGPKTIM - MMC Transmit Good Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXGPKTIM(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXGPKTIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXGPKTIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM_MASK (0x400000U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM_SHIFT (22U)
/*! TXEXDEFPIM - MMC Transmit Excessive Deferral Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXPAUSPIM_MASK (0x800000U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXPAUSPIM_SHIFT (23U)
/*! TXPAUSPIM - MMC Transmit Pause Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXPAUSPIM(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXPAUSPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXPAUSPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXVLANGPIM_MASK (0x1000000U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXVLANGPIM_SHIFT (24U)
/*! TXVLANGPIM - MMC Transmit VLAN Good Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXVLANGPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXVLANGPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXVLANGPIM_MASK)

#define EMAC_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM_MASK (0x2000000U)
#define EMAC_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM_SHIFT (25U)
/*! TXOSIZEGPIM - MMC Transmit Oversize Good Packet Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM_SHIFT)) & EMAC_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM_MASK)
/*! @} */

/*! @name TX_OCTET_COUNT_GOOD_BAD - Transmit Octet Count Good Bad */
/*! @{ */

#define EMAC_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_MASK (0xFFFFFFFFU)
#define EMAC_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_SHIFT (0U)
/*! TXOCTGB - Transmit Octet Count Good Bad */
#define EMAC_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_SHIFT)) & EMAC_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_MASK)
/*! @} */

/*! @name TX_PACKET_COUNT_GOOD_BAD - Transmit Packet Count Good Bad */
/*! @{ */

#define EMAC_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_MASK (0xFFFFFFFFU)
#define EMAC_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_SHIFT (0U)
/*! TXPKTGB - Transmit Packet Count Good Bad */
#define EMAC_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_SHIFT)) & EMAC_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_MASK)
/*! @} */

/*! @name TX_BROADCAST_PACKETS_GOOD - Transmit Broadcast Packets Good */
/*! @{ */

#define EMAC_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_MASK (0xFFFFFFFFU)
#define EMAC_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_SHIFT (0U)
/*! TXBCASTG - Transmit Broadcast Packets Good */
#define EMAC_TX_BROADCAST_PACKETS_GOOD_TXBCASTG(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_SHIFT)) & EMAC_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_MASK)
/*! @} */

/*! @name TX_MULTICAST_PACKETS_GOOD - Transmit Multicast Packets Good */
/*! @{ */

#define EMAC_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_MASK (0xFFFFFFFFU)
#define EMAC_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_SHIFT (0U)
/*! TXMCASTG - Transmit Multicast Packets Good */
#define EMAC_TX_MULTICAST_PACKETS_GOOD_TXMCASTG(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_SHIFT)) & EMAC_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_MASK)
/*! @} */

/*! @name TX_64OCTETS_PACKETS_GOOD_BAD - Transmit 64-Octet Packets Good Bad */
/*! @{ */

#define EMAC_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_MASK (0xFFFFFFFFU)
#define EMAC_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_SHIFT (0U)
/*! TX64OCTGB - Transmit 64-Octet Packets Good Bad */
#define EMAC_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_SHIFT)) & EMAC_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_MASK)
/*! @} */

/*! @name TX_65TO127OCTETS_PACKETS_GOOD_BAD - Transmit 65 To 127 Octet Packets Good Bad */
/*! @{ */

#define EMAC_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_MASK (0xFFFFFFFFU)
#define EMAC_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_SHIFT (0U)
/*! TX65_127OCTGB - Transmit 65 To 127 Octet Packets Good Bad */
#define EMAC_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_SHIFT)) & EMAC_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_MASK)
/*! @} */

/*! @name TX_128TO255OCTETS_PACKETS_GOOD_BAD - Transmit 128 To 255 Octet Packets Good Bad */
/*! @{ */

#define EMAC_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_MASK (0xFFFFFFFFU)
#define EMAC_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_SHIFT (0U)
/*! TX128_255OCTGB - Transmit 128 To 255 Octet Packets Good Bad */
#define EMAC_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_SHIFT)) & EMAC_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_MASK)
/*! @} */

/*! @name TX_256TO511OCTETS_PACKETS_GOOD_BAD - Transmit 256 To 511 Octet Packets Good Bad */
/*! @{ */

#define EMAC_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_MASK (0xFFFFFFFFU)
#define EMAC_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_SHIFT (0U)
/*! TX256_511OCTGB - Transmit 256 To 511 Octet Packets Good Bad */
#define EMAC_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_SHIFT)) & EMAC_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_MASK)
/*! @} */

/*! @name TX_512TO1023OCTETS_PACKETS_GOOD_BAD - Transmit 512 To 1023 Octet Packets Good Bad */
/*! @{ */

#define EMAC_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_MASK (0xFFFFFFFFU)
#define EMAC_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_SHIFT (0U)
/*! TX512_1023OCTGB - Transmit 512 To 1023 Octet Packets Good Bad */
#define EMAC_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_SHIFT)) & EMAC_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_MASK)
/*! @} */

/*! @name TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD - Transmit 1024 To Max Octet Packets Good Bad */
/*! @{ */

#define EMAC_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_MASK (0xFFFFFFFFU)
#define EMAC_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_SHIFT (0U)
/*! TX1024_MAXOCTGB - Transmit 1024 To Max Octet Packets Good Bad */
#define EMAC_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_SHIFT)) & EMAC_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_MASK)
/*! @} */

/*! @name TX_UNICAST_PACKETS_GOOD_BAD - Transmit Unicast Packets Good Bad */
/*! @{ */

#define EMAC_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_MASK (0xFFFFFFFFU)
#define EMAC_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_SHIFT (0U)
/*! TXUCASTGB - Transmit Unicast Packets Good Bad */
#define EMAC_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_SHIFT)) & EMAC_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_MASK)
/*! @} */

/*! @name TX_MULTICAST_PACKETS_GOOD_BAD - Transmit Multicast Packets Good Bad */
/*! @{ */

#define EMAC_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_MASK (0xFFFFFFFFU)
#define EMAC_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_SHIFT (0U)
/*! TXMCASTGB - Transmit Multicast Packets Good Bad */
#define EMAC_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_SHIFT)) & EMAC_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_MASK)
/*! @} */

/*! @name TX_BROADCAST_PACKETS_GOOD_BAD - Transmit Broadcast Packets Good Bad */
/*! @{ */

#define EMAC_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_MASK (0xFFFFFFFFU)
#define EMAC_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_SHIFT (0U)
/*! TXBCASTGB - Transmit Broadcast Packets Good Bad */
#define EMAC_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_SHIFT)) & EMAC_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_MASK)
/*! @} */

/*! @name TX_UNDERFLOW_ERROR_PACKETS - Transmit Underflow Error Packets */
/*! @{ */

#define EMAC_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_MASK (0xFFFFFFFFU)
#define EMAC_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_SHIFT (0U)
/*! TXUNDRFLW - Transmit Underflow Error Packets */
#define EMAC_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_SHIFT)) & EMAC_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_MASK)
/*! @} */

/*! @name TX_SINGLE_COLLISION_GOOD_PACKETS - Transmit Single Collision Good Packets */
/*! @{ */

#define EMAC_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_MASK (0xFFFFFFFFU)
#define EMAC_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_SHIFT (0U)
/*! TXSNGLCOLG - Transmit Single Collision Good Packets */
#define EMAC_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_SHIFT)) & EMAC_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_MASK)
/*! @} */

/*! @name TX_MULTIPLE_COLLISION_GOOD_PACKETS - Transmit Multiple Collision Good Packets */
/*! @{ */

#define EMAC_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_MASK (0xFFFFFFFFU)
#define EMAC_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_SHIFT (0U)
/*! TXMULTCOLG - Transmit Multiple Collision Good Packets */
#define EMAC_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_SHIFT)) & EMAC_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_MASK)
/*! @} */

/*! @name TX_DEFERRED_PACKETS - Transmit Deferred Packets */
/*! @{ */

#define EMAC_TX_DEFERRED_PACKETS_TXDEFRD_MASK    (0xFFFFFFFFU)
#define EMAC_TX_DEFERRED_PACKETS_TXDEFRD_SHIFT   (0U)
/*! TXDEFRD - Transmit Deferred Packets */
#define EMAC_TX_DEFERRED_PACKETS_TXDEFRD(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_TX_DEFERRED_PACKETS_TXDEFRD_SHIFT)) & EMAC_TX_DEFERRED_PACKETS_TXDEFRD_MASK)
/*! @} */

/*! @name TX_LATE_COLLISION_PACKETS - Transmit Late Collision Packets */
/*! @{ */

#define EMAC_TX_LATE_COLLISION_PACKETS_TXLATECOL_MASK (0xFFFFFFFFU)
#define EMAC_TX_LATE_COLLISION_PACKETS_TXLATECOL_SHIFT (0U)
/*! TXLATECOL - Transmit Late Collision Packets */
#define EMAC_TX_LATE_COLLISION_PACKETS_TXLATECOL(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_LATE_COLLISION_PACKETS_TXLATECOL_SHIFT)) & EMAC_TX_LATE_COLLISION_PACKETS_TXLATECOL_MASK)
/*! @} */

/*! @name TX_EXCESSIVE_COLLISION_PACKETS - Transmit Excessive Collision Packets */
/*! @{ */

#define EMAC_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_MASK (0xFFFFFFFFU)
#define EMAC_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_SHIFT (0U)
/*! TXEXSCOL - Transmit Excessive Collision Packets */
#define EMAC_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_SHIFT)) & EMAC_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_MASK)
/*! @} */

/*! @name TX_CARRIER_ERROR_PACKETS - Transmit Carrier Error Packets */
/*! @{ */

#define EMAC_TX_CARRIER_ERROR_PACKETS_TXCARR_MASK (0xFFFFFFFFU)
#define EMAC_TX_CARRIER_ERROR_PACKETS_TXCARR_SHIFT (0U)
/*! TXCARR - Transmit Carrier Error Packets */
#define EMAC_TX_CARRIER_ERROR_PACKETS_TXCARR(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_TX_CARRIER_ERROR_PACKETS_TXCARR_SHIFT)) & EMAC_TX_CARRIER_ERROR_PACKETS_TXCARR_MASK)
/*! @} */

/*! @name TX_OCTET_COUNT_GOOD - Transmit Octet Count Good */
/*! @{ */

#define EMAC_TX_OCTET_COUNT_GOOD_TXOCTG_MASK     (0xFFFFFFFFU)
#define EMAC_TX_OCTET_COUNT_GOOD_TXOCTG_SHIFT    (0U)
/*! TXOCTG - Transmit Octet Count Good */
#define EMAC_TX_OCTET_COUNT_GOOD_TXOCTG(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_TX_OCTET_COUNT_GOOD_TXOCTG_SHIFT)) & EMAC_TX_OCTET_COUNT_GOOD_TXOCTG_MASK)
/*! @} */

/*! @name TX_PACKET_COUNT_GOOD - Transmit Packet Count Good */
/*! @{ */

#define EMAC_TX_PACKET_COUNT_GOOD_TXPKTG_MASK    (0xFFFFFFFFU)
#define EMAC_TX_PACKET_COUNT_GOOD_TXPKTG_SHIFT   (0U)
/*! TXPKTG - Transmit Packet Count Good */
#define EMAC_TX_PACKET_COUNT_GOOD_TXPKTG(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_TX_PACKET_COUNT_GOOD_TXPKTG_SHIFT)) & EMAC_TX_PACKET_COUNT_GOOD_TXPKTG_MASK)
/*! @} */

/*! @name TX_EXCESSIVE_DEFERRAL_ERROR - Transmit Excessive Deferral Error */
/*! @{ */

#define EMAC_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_MASK (0xFFFFFFFFU)
#define EMAC_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_SHIFT (0U)
/*! TXEXSDEF - Transmit Excessive Deferral Error */
#define EMAC_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF(x) (((uint32_t)(((uint32_t)(x)) << EMAC_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_SHIFT)) & EMAC_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_MASK)
/*! @} */

/*! @name TX_PAUSE_PACKETS - Transmit Pause Packets */
/*! @{ */

#define EMAC_TX_PAUSE_PACKETS_TXPAUSE_MASK       (0xFFFFFFFFU)
#define EMAC_TX_PAUSE_PACKETS_TXPAUSE_SHIFT      (0U)
/*! TXPAUSE - Transmit Pause Packets */
#define EMAC_TX_PAUSE_PACKETS_TXPAUSE(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_TX_PAUSE_PACKETS_TXPAUSE_SHIFT)) & EMAC_TX_PAUSE_PACKETS_TXPAUSE_MASK)
/*! @} */

/*! @name TX_VLAN_PACKETS_GOOD - Transmit VLAN Packets Good */
/*! @{ */

#define EMAC_TX_VLAN_PACKETS_GOOD_TXVLANG_MASK   (0xFFFFFFFFU)
#define EMAC_TX_VLAN_PACKETS_GOOD_TXVLANG_SHIFT  (0U)
/*! TXVLANG - Transmit VLAN Packets Good */
#define EMAC_TX_VLAN_PACKETS_GOOD_TXVLANG(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_TX_VLAN_PACKETS_GOOD_TXVLANG_SHIFT)) & EMAC_TX_VLAN_PACKETS_GOOD_TXVLANG_MASK)
/*! @} */

/*! @name TX_OSIZE_PACKETS_GOOD - Transmit O Size Packets Good */
/*! @{ */

#define EMAC_TX_OSIZE_PACKETS_GOOD_TXOSIZG_MASK  (0xFFFFFFFFU)
#define EMAC_TX_OSIZE_PACKETS_GOOD_TXOSIZG_SHIFT (0U)
/*! TXOSIZG - Transmit O Size Packets Good */
#define EMAC_TX_OSIZE_PACKETS_GOOD_TXOSIZG(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_TX_OSIZE_PACKETS_GOOD_TXOSIZG_SHIFT)) & EMAC_TX_OSIZE_PACKETS_GOOD_TXOSIZG_MASK)
/*! @} */

/*! @name RX_PACKETS_COUNT_GOOD_BAD - Receive Packets Count Good Bad */
/*! @{ */

#define EMAC_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_MASK (0xFFFFFFFFU)
#define EMAC_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_SHIFT (0U)
/*! RXPKTGB - Receive Packets Count Good Bad */
#define EMAC_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_SHIFT)) & EMAC_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_MASK)
/*! @} */

/*! @name RX_OCTET_COUNT_GOOD_BAD - Receive Octet Count Good Bad */
/*! @{ */

#define EMAC_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_MASK (0xFFFFFFFFU)
#define EMAC_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_SHIFT (0U)
/*! RXOCTGB - Receive Octet Count Good Bad */
#define EMAC_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_SHIFT)) & EMAC_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_MASK)
/*! @} */

/*! @name RX_OCTET_COUNT_GOOD - Receive Octet Count Good */
/*! @{ */

#define EMAC_RX_OCTET_COUNT_GOOD_RXOCTG_MASK     (0xFFFFFFFFU)
#define EMAC_RX_OCTET_COUNT_GOOD_RXOCTG_SHIFT    (0U)
/*! RXOCTG - Receive Octet Count Good */
#define EMAC_RX_OCTET_COUNT_GOOD_RXOCTG(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_RX_OCTET_COUNT_GOOD_RXOCTG_SHIFT)) & EMAC_RX_OCTET_COUNT_GOOD_RXOCTG_MASK)
/*! @} */

/*! @name RX_BROADCAST_PACKETS_GOOD - Receive Broadcast Packets Good */
/*! @{ */

#define EMAC_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_MASK (0xFFFFFFFFU)
#define EMAC_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_SHIFT (0U)
/*! RXBCASTG - Receive Broadcast Packets Good */
#define EMAC_RX_BROADCAST_PACKETS_GOOD_RXBCASTG(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_SHIFT)) & EMAC_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_MASK)
/*! @} */

/*! @name RX_MULTICAST_PACKETS_GOOD - Receive Multicast Packets Good */
/*! @{ */

#define EMAC_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_MASK (0xFFFFFFFFU)
#define EMAC_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_SHIFT (0U)
/*! RXMCASTG - Receive Multicast Packets Good */
#define EMAC_RX_MULTICAST_PACKETS_GOOD_RXMCASTG(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_SHIFT)) & EMAC_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_MASK)
/*! @} */

/*! @name RX_CRC_ERROR_PACKETS - Receive CRC Error Packets */
/*! @{ */

#define EMAC_RX_CRC_ERROR_PACKETS_RXCRCERR_MASK  (0xFFFFFFFFU)
#define EMAC_RX_CRC_ERROR_PACKETS_RXCRCERR_SHIFT (0U)
/*! RXCRCERR - Receive CRC Error Packets */
#define EMAC_RX_CRC_ERROR_PACKETS_RXCRCERR(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_RX_CRC_ERROR_PACKETS_RXCRCERR_SHIFT)) & EMAC_RX_CRC_ERROR_PACKETS_RXCRCERR_MASK)
/*! @} */

/*! @name RX_ALIGNMENT_ERROR_PACKETS - Receive Alignment Error Packets */
/*! @{ */

#define EMAC_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_MASK (0xFFFFFFFFU)
#define EMAC_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_SHIFT (0U)
/*! RXALGNERR - Receive Alignment Error Packets */
#define EMAC_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_SHIFT)) & EMAC_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_MASK)
/*! @} */

/*! @name RX_RUNT_ERROR_PACKETS - Receive Runt Error Packets */
/*! @{ */

#define EMAC_RX_RUNT_ERROR_PACKETS_RXRUNTERR_MASK (0xFFFFFFFFU)
#define EMAC_RX_RUNT_ERROR_PACKETS_RXRUNTERR_SHIFT (0U)
/*! RXRUNTERR - Receive Runt Error Packets */
#define EMAC_RX_RUNT_ERROR_PACKETS_RXRUNTERR(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_RX_RUNT_ERROR_PACKETS_RXRUNTERR_SHIFT)) & EMAC_RX_RUNT_ERROR_PACKETS_RXRUNTERR_MASK)
/*! @} */

/*! @name RX_JABBER_ERROR_PACKETS - Receive Jabber Error Packets */
/*! @{ */

#define EMAC_RX_JABBER_ERROR_PACKETS_RXJABERR_MASK (0xFFFFFFFFU)
#define EMAC_RX_JABBER_ERROR_PACKETS_RXJABERR_SHIFT (0U)
/*! RXJABERR - Receive Jabber Error Packets */
#define EMAC_RX_JABBER_ERROR_PACKETS_RXJABERR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_JABBER_ERROR_PACKETS_RXJABERR_SHIFT)) & EMAC_RX_JABBER_ERROR_PACKETS_RXJABERR_MASK)
/*! @} */

/*! @name RX_UNDERSIZE_PACKETS_GOOD - Receive Undersize Packets Good */
/*! @{ */

#define EMAC_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_MASK (0xFFFFFFFFU)
#define EMAC_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_SHIFT (0U)
/*! RXUNDERSZG - Receive Undersize Packets Good */
#define EMAC_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_SHIFT)) & EMAC_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_MASK)
/*! @} */

/*! @name RX_OVERSIZE_PACKETS_GOOD - Receive Oversize Packets Good */
/*! @{ */

#define EMAC_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_MASK (0xFFFFFFFFU)
#define EMAC_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_SHIFT (0U)
/*! RXOVERSZG - Receive Oversize Packets Good */
#define EMAC_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_SHIFT)) & EMAC_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_MASK)
/*! @} */

/*! @name RX_64OCTETS_PACKETS_GOOD_BAD - Receive 64 Octets Packets Good Bad */
/*! @{ */

#define EMAC_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_MASK (0xFFFFFFFFU)
#define EMAC_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_SHIFT (0U)
/*! RX64OCTGB - Receive 64 Octets Packets Good Bad */
#define EMAC_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_SHIFT)) & EMAC_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_MASK)
/*! @} */

/*! @name RX_65TO127OCTETS_PACKETS_GOOD_BAD - Receive 65-127 Octets Packets Good Bad */
/*! @{ */

#define EMAC_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB_MASK (0xFFFFFFFFU)
#define EMAC_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB_SHIFT (0U)
/*! RX65_127OCTGB - Receive 65-127 Octets Packets Good Bad */
#define EMAC_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB_SHIFT)) & EMAC_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB_MASK)
/*! @} */

/*! @name RX_128TO255OCTETS_PACKETS_GOOD_BAD - Receive 128-255 Octets Packets Good Bad */
/*! @{ */

#define EMAC_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_MASK (0xFFFFFFFFU)
#define EMAC_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_SHIFT (0U)
/*! RX128_255OCTGB - Receive 128-255 Octets Packets Good Bad */
#define EMAC_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_SHIFT)) & EMAC_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_MASK)
/*! @} */

/*! @name RX_256TO511OCTETS_PACKETS_GOOD_BAD - Receive 256-511 Octets Packets Good Bad */
/*! @{ */

#define EMAC_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_MASK (0xFFFFFFFFU)
#define EMAC_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_SHIFT (0U)
/*! RX256_511OCTGB - Receive 256-511 Octets Packets Good Bad */
#define EMAC_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_SHIFT)) & EMAC_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_MASK)
/*! @} */

/*! @name RX_512TO1023OCTETS_PACKETS_GOOD_BAD - Receive 512-1023 Octets Packets Good Bad */
/*! @{ */

#define EMAC_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_MASK (0xFFFFFFFFU)
#define EMAC_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_SHIFT (0U)
/*! RX512_1023OCTGB - Receive 512-1023 Octets Packets Good Bad */
#define EMAC_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_SHIFT)) & EMAC_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_MASK)
/*! @} */

/*! @name RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD - Receive 1024 To Max Octets Good Bad */
/*! @{ */

#define EMAC_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_MASK (0xFFFFFFFFU)
#define EMAC_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_SHIFT (0U)
/*! RX1024_MAXOCTGB - Receive 1024-Max Octets Good Bad */
#define EMAC_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_SHIFT)) & EMAC_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_MASK)
/*! @} */

/*! @name RX_UNICAST_PACKETS_GOOD - Receive Unicast Packets Good */
/*! @{ */

#define EMAC_RX_UNICAST_PACKETS_GOOD_RXUCASTG_MASK (0xFFFFFFFFU)
#define EMAC_RX_UNICAST_PACKETS_GOOD_RXUCASTG_SHIFT (0U)
/*! RXUCASTG - Receive Unicast Packets Good */
#define EMAC_RX_UNICAST_PACKETS_GOOD_RXUCASTG(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_UNICAST_PACKETS_GOOD_RXUCASTG_SHIFT)) & EMAC_RX_UNICAST_PACKETS_GOOD_RXUCASTG_MASK)
/*! @} */

/*! @name RX_LENGTH_ERROR_PACKETS - Receive Length Error Packets */
/*! @{ */

#define EMAC_RX_LENGTH_ERROR_PACKETS_RXLENERR_MASK (0xFFFFFFFFU)
#define EMAC_RX_LENGTH_ERROR_PACKETS_RXLENERR_SHIFT (0U)
/*! RXLENERR - Receive Length Error Packets */
#define EMAC_RX_LENGTH_ERROR_PACKETS_RXLENERR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_LENGTH_ERROR_PACKETS_RXLENERR_SHIFT)) & EMAC_RX_LENGTH_ERROR_PACKETS_RXLENERR_MASK)
/*! @} */

/*! @name RX_OUT_OF_RANGE_TYPE_PACKETS - Receive Out of Range Type Packet */
/*! @{ */

#define EMAC_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG_MASK (0xFFFFFFFFU)
#define EMAC_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG_SHIFT (0U)
/*! RXOUTOFRNG - Receive Out of Range Type Packet */
#define EMAC_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG_SHIFT)) & EMAC_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG_MASK)
/*! @} */

/*! @name RX_PAUSE_PACKETS - Receive Pause Packets */
/*! @{ */

#define EMAC_RX_PAUSE_PACKETS_RXPAUSEPKT_MASK    (0xFFFFFFFFU)
#define EMAC_RX_PAUSE_PACKETS_RXPAUSEPKT_SHIFT   (0U)
/*! RXPAUSEPKT - Receive Pause Packets */
#define EMAC_RX_PAUSE_PACKETS_RXPAUSEPKT(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_RX_PAUSE_PACKETS_RXPAUSEPKT_SHIFT)) & EMAC_RX_PAUSE_PACKETS_RXPAUSEPKT_MASK)
/*! @} */

/*! @name RX_FIFO_OVERFLOW_PACKETS - Receive FIFO Overflow Packets */
/*! @{ */

#define EMAC_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_MASK (0xFFFFFFFFU)
#define EMAC_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_SHIFT (0U)
/*! RXFIFOOVFL - Receive FIFO Overflow Packets */
#define EMAC_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_SHIFT)) & EMAC_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_MASK)
/*! @} */

/*! @name RX_VLAN_PACKETS_GOOD_BAD - Receive VLAN Packets Good Bad */
/*! @{ */

#define EMAC_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_MASK (0xFFFFFFFFU)
#define EMAC_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_SHIFT (0U)
/*! RXVLANPKTGB - Receive VLAN Packets Good Bad */
#define EMAC_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_SHIFT)) & EMAC_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_MASK)
/*! @} */

/*! @name RX_WATCHDOG_ERROR_PACKETS - Receive Watchdog Error Packets */
/*! @{ */

#define EMAC_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_MASK (0xFFFFFFFFU)
#define EMAC_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_SHIFT (0U)
/*! RXWDGERR - Receive Watchdog Error Packets */
#define EMAC_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_SHIFT)) & EMAC_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_MASK)
/*! @} */

/*! @name RX_RECEIVE_ERROR_PACKETS - Receive Receive Error Packets */
/*! @{ */

#define EMAC_RX_RECEIVE_ERROR_PACKETS_RXRCVERR_MASK (0xFFFFFFFFU)
#define EMAC_RX_RECEIVE_ERROR_PACKETS_RXRCVERR_SHIFT (0U)
/*! RXRCVERR - Receive Receive Error Packets */
#define EMAC_RX_RECEIVE_ERROR_PACKETS_RXRCVERR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_RX_RECEIVE_ERROR_PACKETS_RXRCVERR_SHIFT)) & EMAC_RX_RECEIVE_ERROR_PACKETS_RXRCVERR_MASK)
/*! @} */

/*! @name RX_CONTROL_PACKETS_GOOD - Receive Control Packets Good */
/*! @{ */

#define EMAC_RX_CONTROL_PACKETS_GOOD_RXCTRLG_MASK (0xFFFFFFFFU)
#define EMAC_RX_CONTROL_PACKETS_GOOD_RXCTRLG_SHIFT (0U)
/*! RXCTRLG - Receive Control Packets Good */
#define EMAC_RX_CONTROL_PACKETS_GOOD_RXCTRLG(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_RX_CONTROL_PACKETS_GOOD_RXCTRLG_SHIFT)) & EMAC_RX_CONTROL_PACKETS_GOOD_RXCTRLG_MASK)
/*! @} */

/*! @name MMC_FPE_TX_INTERRUPT - MMC Transmit FPE Fragment Counter Interrupt Status */
/*! @{ */

#define EMAC_MMC_FPE_TX_INTERRUPT_FCIS_MASK      (0x1U)
#define EMAC_MMC_FPE_TX_INTERRUPT_FCIS_SHIFT     (0U)
/*! FCIS - MMC Transmit FPE Fragment Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_FPE_TX_INTERRUPT_FCIS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_FPE_TX_INTERRUPT_FCIS_SHIFT)) & EMAC_MMC_FPE_TX_INTERRUPT_FCIS_MASK)

#define EMAC_MMC_FPE_TX_INTERRUPT_HRCIS_MASK     (0x2U)
#define EMAC_MMC_FPE_TX_INTERRUPT_HRCIS_SHIFT    (1U)
/*! HRCIS - MMC Transmit Hold Request Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_FPE_TX_INTERRUPT_HRCIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_FPE_TX_INTERRUPT_HRCIS_SHIFT)) & EMAC_MMC_FPE_TX_INTERRUPT_HRCIS_MASK)
/*! @} */

/*! @name MMC_FPE_TX_INTERRUPT_MASK - MMC FPE Transmit Interrupt Mask */
/*! @{ */

#define EMAC_MMC_FPE_TX_INTERRUPT_MASK_FCIM_MASK (0x1U)
#define EMAC_MMC_FPE_TX_INTERRUPT_MASK_FCIM_SHIFT (0U)
/*! FCIM - MMC Transmit Fragment Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_FPE_TX_INTERRUPT_MASK_FCIM(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_FPE_TX_INTERRUPT_MASK_FCIM_SHIFT)) & EMAC_MMC_FPE_TX_INTERRUPT_MASK_FCIM_MASK)

#define EMAC_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_MASK (0x2U)
#define EMAC_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_SHIFT (1U)
/*! HRCIM - MMC Transmit Hold Request Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_FPE_TX_INTERRUPT_MASK_HRCIM(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_SHIFT)) & EMAC_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_MASK)
/*! @} */

/*! @name MMC_TX_FPE_FRAGMENT_CNTR - Transmit FPE Fragment Counter */
/*! @{ */

#define EMAC_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_MASK (0xFFFFFFFFU)
#define EMAC_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_SHIFT (0U)
/*! TXFFC - Transmit FPE Fragment Counter */
#define EMAC_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_SHIFT)) & EMAC_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_MASK)
/*! @} */

/*! @name MMC_TX_HOLD_REQ_CNTR - Transmit Hold Request Counter */
/*! @{ */

#define EMAC_MMC_TX_HOLD_REQ_CNTR_TXHRC_MASK     (0xFFFFFFFFU)
#define EMAC_MMC_TX_HOLD_REQ_CNTR_TXHRC_SHIFT    (0U)
/*! TXHRC - Transmit Hold Request Counter */
#define EMAC_MMC_TX_HOLD_REQ_CNTR_TXHRC(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_TX_HOLD_REQ_CNTR_TXHRC_SHIFT)) & EMAC_MMC_TX_HOLD_REQ_CNTR_TXHRC_MASK)
/*! @} */

/*! @name MMC_FPE_RX_INTERRUPT - MMC Receive Packet Assembly Error Counter Interrupt Status */
/*! @{ */

#define EMAC_MMC_FPE_RX_INTERRUPT_PAECIS_MASK    (0x1U)
#define EMAC_MMC_FPE_RX_INTERRUPT_PAECIS_SHIFT   (0U)
/*! PAECIS - MMC Receive, transmit, Packet Assembly Error Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_FPE_RX_INTERRUPT_PAECIS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_FPE_RX_INTERRUPT_PAECIS_SHIFT)) & EMAC_MMC_FPE_RX_INTERRUPT_PAECIS_MASK)

#define EMAC_MMC_FPE_RX_INTERRUPT_PSECIS_MASK    (0x2U)
#define EMAC_MMC_FPE_RX_INTERRUPT_PSECIS_SHIFT   (1U)
/*! PSECIS - MMC Receive, Transmit, Packet SMD Error Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_FPE_RX_INTERRUPT_PSECIS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_FPE_RX_INTERRUPT_PSECIS_SHIFT)) & EMAC_MMC_FPE_RX_INTERRUPT_PSECIS_MASK)

#define EMAC_MMC_FPE_RX_INTERRUPT_PAOCIS_MASK    (0x4U)
#define EMAC_MMC_FPE_RX_INTERRUPT_PAOCIS_SHIFT   (2U)
/*! PAOCIS - MMC Receive Packet Assembly OK Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_FPE_RX_INTERRUPT_PAOCIS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_FPE_RX_INTERRUPT_PAOCIS_SHIFT)) & EMAC_MMC_FPE_RX_INTERRUPT_PAOCIS_MASK)

#define EMAC_MMC_FPE_RX_INTERRUPT_FCIS_MASK      (0x8U)
#define EMAC_MMC_FPE_RX_INTERRUPT_FCIS_SHIFT     (3U)
/*! FCIS - MMC Receive FPE Fragment Counter Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MMC_FPE_RX_INTERRUPT_FCIS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_FPE_RX_INTERRUPT_FCIS_SHIFT)) & EMAC_MMC_FPE_RX_INTERRUPT_FCIS_MASK)
/*! @} */

/*! @name MMC_FPE_RX_INTERRUPT_MASK - MMC FPE Receive Interrupt Mask */
/*! @{ */

#define EMAC_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_MASK (0x1U)
#define EMAC_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_SHIFT (0U)
/*! PAECIM - MMC receive Packet Assembly Error Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_FPE_RX_INTERRUPT_MASK_PAECIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_SHIFT)) & EMAC_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_MASK)

#define EMAC_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_MASK (0x2U)
#define EMAC_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_SHIFT (1U)
/*! PSECIM - MMC Receive Packet SMD Error Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_FPE_RX_INTERRUPT_MASK_PSECIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_SHIFT)) & EMAC_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_MASK)

#define EMAC_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_MASK (0x4U)
#define EMAC_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_SHIFT (2U)
/*! PAOCIM - MMC Receive Packet Assembly OK Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_SHIFT)) & EMAC_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_MASK)

#define EMAC_MMC_FPE_RX_INTERRUPT_MASK_FCIM_MASK (0x8U)
#define EMAC_MMC_FPE_RX_INTERRUPT_MASK_FCIM_SHIFT (3U)
/*! FCIM - MMC Receive FPE Fragment Counter Interrupt Mask
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MMC_FPE_RX_INTERRUPT_MASK_FCIM(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_FPE_RX_INTERRUPT_MASK_FCIM_SHIFT)) & EMAC_MMC_FPE_RX_INTERRUPT_MASK_FCIM_MASK)
/*! @} */

/*! @name MMC_RX_PACKET_ASSEMBLY_ERR_CNTR - MMC Receive Packet Assembly Error Counter */
/*! @{ */

#define EMAC_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_MASK (0xFFFFFFFFU)
#define EMAC_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_SHIFT (0U)
/*! PAEC - Packet Assembly Error Counter */
#define EMAC_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_SHIFT)) & EMAC_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_MASK)
/*! @} */

/*! @name MMC_RX_PACKET_SMD_ERR_CNTR - MMC Receive Packet SMD Error Counter */
/*! @{ */

#define EMAC_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_MASK (0xFFFFFFFFU)
#define EMAC_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_SHIFT (0U)
/*! PSEC - Packet SMD Error Counter */
#define EMAC_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_SHIFT)) & EMAC_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_MASK)
/*! @} */

/*! @name MMC_RX_PACKET_ASSEMBLY_OK_CNTR - MMC Receive Packet Assembly OK Counter */
/*! @{ */

#define EMAC_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_MASK (0xFFFFFFFFU)
#define EMAC_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_SHIFT (0U)
/*! PAOC - Packet Assembly OK Counter */
#define EMAC_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_SHIFT)) & EMAC_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_MASK)
/*! @} */

/*! @name MMC_RX_FPE_FRAGMENT_CNTR - MMC Receive FPE Fragment Counter */
/*! @{ */

#define EMAC_MMC_RX_FPE_FRAGMENT_CNTR_FFC_MASK   (0xFFFFFFFFU)
#define EMAC_MMC_RX_FPE_FRAGMENT_CNTR_FFC_SHIFT  (0U)
/*! FFC - FPE Fragment Counter */
#define EMAC_MMC_RX_FPE_FRAGMENT_CNTR_FFC(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MMC_RX_FPE_FRAGMENT_CNTR_FFC_SHIFT)) & EMAC_MMC_RX_FPE_FRAGMENT_CNTR_FFC_MASK)
/*! @} */

/*! @name MAC_L3_L4_CONTROL0 - MAC Layer 3 Layer 4 Control 0 */
/*! @{ */

#define EMAC_MAC_L3_L4_CONTROL0_L3PEN0_MASK      (0x1U)
#define EMAC_MAC_L3_L4_CONTROL0_L3PEN0_SHIFT     (0U)
/*! L3PEN0 - Layer 3 Protocol Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL0_L3PEN0(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL0_L3PEN0_SHIFT)) & EMAC_MAC_L3_L4_CONTROL0_L3PEN0_MASK)

#define EMAC_MAC_L3_L4_CONTROL0_L3SAM0_MASK      (0x4U)
#define EMAC_MAC_L3_L4_CONTROL0_L3SAM0_SHIFT     (2U)
/*! L3SAM0 - Layer 3 IP SA Match Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL0_L3SAM0(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL0_L3SAM0_SHIFT)) & EMAC_MAC_L3_L4_CONTROL0_L3SAM0_MASK)

#define EMAC_MAC_L3_L4_CONTROL0_L3SAIM0_MASK     (0x8U)
#define EMAC_MAC_L3_L4_CONTROL0_L3SAIM0_SHIFT    (3U)
/*! L3SAIM0 - Layer 3 IP SA Inverse Match Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL0_L3SAIM0(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL0_L3SAIM0_SHIFT)) & EMAC_MAC_L3_L4_CONTROL0_L3SAIM0_MASK)

#define EMAC_MAC_L3_L4_CONTROL0_L3DAM0_MASK      (0x10U)
#define EMAC_MAC_L3_L4_CONTROL0_L3DAM0_SHIFT     (4U)
/*! L3DAM0 - Layer 3 IP DA Match Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL0_L3DAM0(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL0_L3DAM0_SHIFT)) & EMAC_MAC_L3_L4_CONTROL0_L3DAM0_MASK)

#define EMAC_MAC_L3_L4_CONTROL0_L3DAIM0_MASK     (0x20U)
#define EMAC_MAC_L3_L4_CONTROL0_L3DAIM0_SHIFT    (5U)
/*! L3DAIM0 - Layer 3 IP DA Inverse Match Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL0_L3DAIM0(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL0_L3DAIM0_SHIFT)) & EMAC_MAC_L3_L4_CONTROL0_L3DAIM0_MASK)

#define EMAC_MAC_L3_L4_CONTROL0_L3HSBM0_MASK     (0x7C0U)
#define EMAC_MAC_L3_L4_CONTROL0_L3HSBM0_SHIFT    (6U)
/*! L3HSBM0 - Layer 3 IP SA Higher Bits Match */
#define EMAC_MAC_L3_L4_CONTROL0_L3HSBM0(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL0_L3HSBM0_SHIFT)) & EMAC_MAC_L3_L4_CONTROL0_L3HSBM0_MASK)

#define EMAC_MAC_L3_L4_CONTROL0_L3HDBM0_MASK     (0xF800U)
#define EMAC_MAC_L3_L4_CONTROL0_L3HDBM0_SHIFT    (11U)
/*! L3HDBM0 - Layer 3 IP DA Higher Bits Match */
#define EMAC_MAC_L3_L4_CONTROL0_L3HDBM0(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL0_L3HDBM0_SHIFT)) & EMAC_MAC_L3_L4_CONTROL0_L3HDBM0_MASK)

#define EMAC_MAC_L3_L4_CONTROL0_L4PEN0_MASK      (0x10000U)
#define EMAC_MAC_L3_L4_CONTROL0_L4PEN0_SHIFT     (16U)
/*! L4PEN0 - Layer 4 Protocol Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL0_L4PEN0(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL0_L4PEN0_SHIFT)) & EMAC_MAC_L3_L4_CONTROL0_L4PEN0_MASK)

#define EMAC_MAC_L3_L4_CONTROL0_L4SPM0_MASK      (0x40000U)
#define EMAC_MAC_L3_L4_CONTROL0_L4SPM0_SHIFT     (18U)
/*! L4SPM0 - Layer 4 Source Port Match Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL0_L4SPM0(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL0_L4SPM0_SHIFT)) & EMAC_MAC_L3_L4_CONTROL0_L4SPM0_MASK)

#define EMAC_MAC_L3_L4_CONTROL0_L4SPIM0_MASK     (0x80000U)
#define EMAC_MAC_L3_L4_CONTROL0_L4SPIM0_SHIFT    (19U)
/*! L4SPIM0 - Layer 4 Source Port Inverse Match Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL0_L4SPIM0(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL0_L4SPIM0_SHIFT)) & EMAC_MAC_L3_L4_CONTROL0_L4SPIM0_MASK)

#define EMAC_MAC_L3_L4_CONTROL0_L4DPM0_MASK      (0x100000U)
#define EMAC_MAC_L3_L4_CONTROL0_L4DPM0_SHIFT     (20U)
/*! L4DPM0 - Layer 4 Destination Port Match Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL0_L4DPM0(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL0_L4DPM0_SHIFT)) & EMAC_MAC_L3_L4_CONTROL0_L4DPM0_MASK)

#define EMAC_MAC_L3_L4_CONTROL0_L4DPIM0_MASK     (0x200000U)
#define EMAC_MAC_L3_L4_CONTROL0_L4DPIM0_SHIFT    (21U)
/*! L4DPIM0 - Layer 4 Destination Port Inverse Match Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL0_L4DPIM0(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL0_L4DPIM0_SHIFT)) & EMAC_MAC_L3_L4_CONTROL0_L4DPIM0_MASK)

#define EMAC_MAC_L3_L4_CONTROL0_DMCHN0_MASK      (0x1000000U)
#define EMAC_MAC_L3_L4_CONTROL0_DMCHN0_SHIFT     (24U)
/*! DMCHN0 - DMA Channel Number */
#define EMAC_MAC_L3_L4_CONTROL0_DMCHN0(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL0_DMCHN0_SHIFT)) & EMAC_MAC_L3_L4_CONTROL0_DMCHN0_MASK)

#define EMAC_MAC_L3_L4_CONTROL0_DMCHEN0_MASK     (0x10000000U)
#define EMAC_MAC_L3_L4_CONTROL0_DMCHEN0_SHIFT    (28U)
/*! DMCHEN0 - DMA Channel Select Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL0_DMCHEN0(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL0_DMCHEN0_SHIFT)) & EMAC_MAC_L3_L4_CONTROL0_DMCHEN0_MASK)
/*! @} */

/*! @name MAC_LAYER4_ADDRESS0 - MAC Layer 4 Address 0 */
/*! @{ */

#define EMAC_MAC_LAYER4_ADDRESS0_L4SP0_MASK      (0xFFFFU)
#define EMAC_MAC_LAYER4_ADDRESS0_L4SP0_SHIFT     (0U)
/*! L4SP0 - Layer 4 Source Port Number */
#define EMAC_MAC_LAYER4_ADDRESS0_L4SP0(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER4_ADDRESS0_L4SP0_SHIFT)) & EMAC_MAC_LAYER4_ADDRESS0_L4SP0_MASK)

#define EMAC_MAC_LAYER4_ADDRESS0_L4DP0_MASK      (0xFFFF0000U)
#define EMAC_MAC_LAYER4_ADDRESS0_L4DP0_SHIFT     (16U)
/*! L4DP0 - Layer 4 Destination Port Number */
#define EMAC_MAC_LAYER4_ADDRESS0_L4DP0(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER4_ADDRESS0_L4DP0_SHIFT)) & EMAC_MAC_LAYER4_ADDRESS0_L4DP0_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR0_REG0 - MAC Layer 3 Address 0 Reg 0 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR0_REG0_L3A00_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR0_REG0_L3A00_SHIFT   (0U)
/*! L3A00 - Layer 3 Address 0 */
#define EMAC_MAC_LAYER3_ADDR0_REG0_L3A00(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR0_REG0_L3A00_SHIFT)) & EMAC_MAC_LAYER3_ADDR0_REG0_L3A00_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR1_REG0 - MAC Layer 3 Address 1 Reg 0 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR1_REG0_L3A10_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR1_REG0_L3A10_SHIFT   (0U)
/*! L3A10 - Layer 3 Address 1 */
#define EMAC_MAC_LAYER3_ADDR1_REG0_L3A10(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR1_REG0_L3A10_SHIFT)) & EMAC_MAC_LAYER3_ADDR1_REG0_L3A10_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR2_REG0 - MAC Layer 3 Address 2 Reg 0 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR2_REG0_L3A20_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR2_REG0_L3A20_SHIFT   (0U)
/*! L3A20 - Layer 3 Address 2 */
#define EMAC_MAC_LAYER3_ADDR2_REG0_L3A20(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR2_REG0_L3A20_SHIFT)) & EMAC_MAC_LAYER3_ADDR2_REG0_L3A20_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR3_REG0 - MAC Layer 3 Address 3 Reg 0 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR3_REG0_L3A30_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR3_REG0_L3A30_SHIFT   (0U)
/*! L3A30 - Layer 3 Address 3 */
#define EMAC_MAC_LAYER3_ADDR3_REG0_L3A30(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR3_REG0_L3A30_SHIFT)) & EMAC_MAC_LAYER3_ADDR3_REG0_L3A30_MASK)
/*! @} */

/*! @name MAC_L3_L4_CONTROL1 - MAC L3 L4 Control 1 */
/*! @{ */

#define EMAC_MAC_L3_L4_CONTROL1_L3PEN1_MASK      (0x1U)
#define EMAC_MAC_L3_L4_CONTROL1_L3PEN1_SHIFT     (0U)
/*! L3PEN1 - Layer 3 Protocol Enable 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL1_L3PEN1(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL1_L3PEN1_SHIFT)) & EMAC_MAC_L3_L4_CONTROL1_L3PEN1_MASK)

#define EMAC_MAC_L3_L4_CONTROL1_L3SAM1_MASK      (0x4U)
#define EMAC_MAC_L3_L4_CONTROL1_L3SAM1_SHIFT     (2U)
/*! L3SAM1 - Layer 3 IP SA Match Enable 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL1_L3SAM1(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL1_L3SAM1_SHIFT)) & EMAC_MAC_L3_L4_CONTROL1_L3SAM1_MASK)

#define EMAC_MAC_L3_L4_CONTROL1_L3SAIM1_MASK     (0x8U)
#define EMAC_MAC_L3_L4_CONTROL1_L3SAIM1_SHIFT    (3U)
/*! L3SAIM1 - Layer 3 IP SA Inverse Match Enable 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL1_L3SAIM1(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL1_L3SAIM1_SHIFT)) & EMAC_MAC_L3_L4_CONTROL1_L3SAIM1_MASK)

#define EMAC_MAC_L3_L4_CONTROL1_L3DAM1_MASK      (0x10U)
#define EMAC_MAC_L3_L4_CONTROL1_L3DAM1_SHIFT     (4U)
/*! L3DAM1 - Layer 3 IP DA Match Enable 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL1_L3DAM1(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL1_L3DAM1_SHIFT)) & EMAC_MAC_L3_L4_CONTROL1_L3DAM1_MASK)

#define EMAC_MAC_L3_L4_CONTROL1_L3DAIM1_MASK     (0x20U)
#define EMAC_MAC_L3_L4_CONTROL1_L3DAIM1_SHIFT    (5U)
/*! L3DAIM1 - Layer 3 IP DA Inverse Match Enable 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL1_L3DAIM1(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL1_L3DAIM1_SHIFT)) & EMAC_MAC_L3_L4_CONTROL1_L3DAIM1_MASK)

#define EMAC_MAC_L3_L4_CONTROL1_L3HSBM1_MASK     (0x7C0U)
#define EMAC_MAC_L3_L4_CONTROL1_L3HSBM1_SHIFT    (6U)
/*! L3HSBM1 - Layer 3 IP SA Higher Bits Match 1 */
#define EMAC_MAC_L3_L4_CONTROL1_L3HSBM1(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL1_L3HSBM1_SHIFT)) & EMAC_MAC_L3_L4_CONTROL1_L3HSBM1_MASK)

#define EMAC_MAC_L3_L4_CONTROL1_L3HDBM1_MASK     (0xF800U)
#define EMAC_MAC_L3_L4_CONTROL1_L3HDBM1_SHIFT    (11U)
/*! L3HDBM1 - Layer 3 IP DA Higher Bits Match 1 */
#define EMAC_MAC_L3_L4_CONTROL1_L3HDBM1(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL1_L3HDBM1_SHIFT)) & EMAC_MAC_L3_L4_CONTROL1_L3HDBM1_MASK)

#define EMAC_MAC_L3_L4_CONTROL1_L4PEN1_MASK      (0x10000U)
#define EMAC_MAC_L3_L4_CONTROL1_L4PEN1_SHIFT     (16U)
/*! L4PEN1 - Layer 4 Protocol Enable 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL1_L4PEN1(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL1_L4PEN1_SHIFT)) & EMAC_MAC_L3_L4_CONTROL1_L4PEN1_MASK)

#define EMAC_MAC_L3_L4_CONTROL1_L4SPM1_MASK      (0x40000U)
#define EMAC_MAC_L3_L4_CONTROL1_L4SPM1_SHIFT     (18U)
/*! L4SPM1 - Layer 4 Source Port Match Enable 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL1_L4SPM1(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL1_L4SPM1_SHIFT)) & EMAC_MAC_L3_L4_CONTROL1_L4SPM1_MASK)

#define EMAC_MAC_L3_L4_CONTROL1_L4SPIM1_MASK     (0x80000U)
#define EMAC_MAC_L3_L4_CONTROL1_L4SPIM1_SHIFT    (19U)
/*! L4SPIM1 - Layer 4 Source Port Inverse Match Enable 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL1_L4SPIM1(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL1_L4SPIM1_SHIFT)) & EMAC_MAC_L3_L4_CONTROL1_L4SPIM1_MASK)

#define EMAC_MAC_L3_L4_CONTROL1_L4DPM1_MASK      (0x100000U)
#define EMAC_MAC_L3_L4_CONTROL1_L4DPM1_SHIFT     (20U)
/*! L4DPM1 - Layer 4 Destination Port Match Enable 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL1_L4DPM1(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL1_L4DPM1_SHIFT)) & EMAC_MAC_L3_L4_CONTROL1_L4DPM1_MASK)

#define EMAC_MAC_L3_L4_CONTROL1_L4DPIM1_MASK     (0x200000U)
#define EMAC_MAC_L3_L4_CONTROL1_L4DPIM1_SHIFT    (21U)
/*! L4DPIM1 - Layer 4 Destination Port Inverse Match Enable 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL1_L4DPIM1(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL1_L4DPIM1_SHIFT)) & EMAC_MAC_L3_L4_CONTROL1_L4DPIM1_MASK)

#define EMAC_MAC_L3_L4_CONTROL1_DMCHN1_MASK      (0x1000000U)
#define EMAC_MAC_L3_L4_CONTROL1_DMCHN1_SHIFT     (24U)
/*! DMCHN1 - DMA Channel Number 1 */
#define EMAC_MAC_L3_L4_CONTROL1_DMCHN1(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL1_DMCHN1_SHIFT)) & EMAC_MAC_L3_L4_CONTROL1_DMCHN1_MASK)

#define EMAC_MAC_L3_L4_CONTROL1_DMCHEN1_MASK     (0x10000000U)
#define EMAC_MAC_L3_L4_CONTROL1_DMCHEN1_SHIFT    (28U)
/*! DMCHEN1 - DMA Channel Select Enable 1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL1_DMCHEN1(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL1_DMCHEN1_SHIFT)) & EMAC_MAC_L3_L4_CONTROL1_DMCHEN1_MASK)
/*! @} */

/*! @name MAC_LAYER4_ADDRESS1 - MAC Layer 4 Address 1 */
/*! @{ */

#define EMAC_MAC_LAYER4_ADDRESS1_L4SP1_MASK      (0xFFFFU)
#define EMAC_MAC_LAYER4_ADDRESS1_L4SP1_SHIFT     (0U)
/*! L4SP1 - Layer 4 Source Port Number 1 */
#define EMAC_MAC_LAYER4_ADDRESS1_L4SP1(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER4_ADDRESS1_L4SP1_SHIFT)) & EMAC_MAC_LAYER4_ADDRESS1_L4SP1_MASK)

#define EMAC_MAC_LAYER4_ADDRESS1_L4DP1_MASK      (0xFFFF0000U)
#define EMAC_MAC_LAYER4_ADDRESS1_L4DP1_SHIFT     (16U)
/*! L4DP1 - Layer 4 Destination Port Number 1 */
#define EMAC_MAC_LAYER4_ADDRESS1_L4DP1(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER4_ADDRESS1_L4DP1_SHIFT)) & EMAC_MAC_LAYER4_ADDRESS1_L4DP1_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR0_REG1 - MAC Layer 3 Address 0 Reg 1 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR0_REG1_L3A01_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR0_REG1_L3A01_SHIFT   (0U)
/*! L3A01 - Layer 3 Address 0 */
#define EMAC_MAC_LAYER3_ADDR0_REG1_L3A01(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR0_REG1_L3A01_SHIFT)) & EMAC_MAC_LAYER3_ADDR0_REG1_L3A01_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR1_REG1 - MAC Layer 3 Address 1 Reg 1 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR1_REG1_L3A11_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR1_REG1_L3A11_SHIFT   (0U)
/*! L3A11 - Layer 3 Address 1 */
#define EMAC_MAC_LAYER3_ADDR1_REG1_L3A11(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR1_REG1_L3A11_SHIFT)) & EMAC_MAC_LAYER3_ADDR1_REG1_L3A11_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR2_REG1 - MAC Layer 3 Address 2 Reg 1 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR2_REG1_L3A21_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR2_REG1_L3A21_SHIFT   (0U)
/*! L3A21 - Layer 3 Address 2 */
#define EMAC_MAC_LAYER3_ADDR2_REG1_L3A21(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR2_REG1_L3A21_SHIFT)) & EMAC_MAC_LAYER3_ADDR2_REG1_L3A21_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR3_REG1 - MAC Layer 3 Address 3 Reg 1 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR3_REG1_L3A31_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR3_REG1_L3A31_SHIFT   (0U)
/*! L3A31 - Layer 3 Address 3 */
#define EMAC_MAC_LAYER3_ADDR3_REG1_L3A31(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR3_REG1_L3A31_SHIFT)) & EMAC_MAC_LAYER3_ADDR3_REG1_L3A31_MASK)
/*! @} */

/*! @name MAC_L3_L4_CONTROL2 - MAC L3 L4 Control 2 */
/*! @{ */

#define EMAC_MAC_L3_L4_CONTROL2_L3PEN2_MASK      (0x1U)
#define EMAC_MAC_L3_L4_CONTROL2_L3PEN2_SHIFT     (0U)
/*! L3PEN2 - Layer 3 Protocol Enable 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL2_L3PEN2(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL2_L3PEN2_SHIFT)) & EMAC_MAC_L3_L4_CONTROL2_L3PEN2_MASK)

#define EMAC_MAC_L3_L4_CONTROL2_L3SAM2_MASK      (0x4U)
#define EMAC_MAC_L3_L4_CONTROL2_L3SAM2_SHIFT     (2U)
/*! L3SAM2 - Layer 3 IP SA Match Enable 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL2_L3SAM2(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL2_L3SAM2_SHIFT)) & EMAC_MAC_L3_L4_CONTROL2_L3SAM2_MASK)

#define EMAC_MAC_L3_L4_CONTROL2_L3SAIM2_MASK     (0x8U)
#define EMAC_MAC_L3_L4_CONTROL2_L3SAIM2_SHIFT    (3U)
/*! L3SAIM2 - Layer 3 IP SA Inverse Match Enable 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL2_L3SAIM2(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL2_L3SAIM2_SHIFT)) & EMAC_MAC_L3_L4_CONTROL2_L3SAIM2_MASK)

#define EMAC_MAC_L3_L4_CONTROL2_L3DAM2_MASK      (0x10U)
#define EMAC_MAC_L3_L4_CONTROL2_L3DAM2_SHIFT     (4U)
/*! L3DAM2 - Layer 3 IP DA Match Enable 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL2_L3DAM2(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL2_L3DAM2_SHIFT)) & EMAC_MAC_L3_L4_CONTROL2_L3DAM2_MASK)

#define EMAC_MAC_L3_L4_CONTROL2_L3DAIM2_MASK     (0x20U)
#define EMAC_MAC_L3_L4_CONTROL2_L3DAIM2_SHIFT    (5U)
/*! L3DAIM2 - Layer 3 IP DA Inverse Match Enable 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL2_L3DAIM2(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL2_L3DAIM2_SHIFT)) & EMAC_MAC_L3_L4_CONTROL2_L3DAIM2_MASK)

#define EMAC_MAC_L3_L4_CONTROL2_L3HSBM2_MASK     (0x7C0U)
#define EMAC_MAC_L3_L4_CONTROL2_L3HSBM2_SHIFT    (6U)
/*! L3HSBM2 - Layer 3 IP SA Higher Bits Match 2 */
#define EMAC_MAC_L3_L4_CONTROL2_L3HSBM2(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL2_L3HSBM2_SHIFT)) & EMAC_MAC_L3_L4_CONTROL2_L3HSBM2_MASK)

#define EMAC_MAC_L3_L4_CONTROL2_L3HDBM2_MASK     (0xF800U)
#define EMAC_MAC_L3_L4_CONTROL2_L3HDBM2_SHIFT    (11U)
/*! L3HDBM2 - Layer 3 IP DA Higher Bits Match 2 */
#define EMAC_MAC_L3_L4_CONTROL2_L3HDBM2(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL2_L3HDBM2_SHIFT)) & EMAC_MAC_L3_L4_CONTROL2_L3HDBM2_MASK)

#define EMAC_MAC_L3_L4_CONTROL2_L4PEN2_MASK      (0x10000U)
#define EMAC_MAC_L3_L4_CONTROL2_L4PEN2_SHIFT     (16U)
/*! L4PEN2 - Layer 4 Protocol Enable 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL2_L4PEN2(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL2_L4PEN2_SHIFT)) & EMAC_MAC_L3_L4_CONTROL2_L4PEN2_MASK)

#define EMAC_MAC_L3_L4_CONTROL2_L4SPM2_MASK      (0x40000U)
#define EMAC_MAC_L3_L4_CONTROL2_L4SPM2_SHIFT     (18U)
/*! L4SPM2 - Layer 4 Source Port Match Enable 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL2_L4SPM2(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL2_L4SPM2_SHIFT)) & EMAC_MAC_L3_L4_CONTROL2_L4SPM2_MASK)

#define EMAC_MAC_L3_L4_CONTROL2_L4SPIM2_MASK     (0x80000U)
#define EMAC_MAC_L3_L4_CONTROL2_L4SPIM2_SHIFT    (19U)
/*! L4SPIM2 - Layer 4 Source Port Inverse Match Enable 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL2_L4SPIM2(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL2_L4SPIM2_SHIFT)) & EMAC_MAC_L3_L4_CONTROL2_L4SPIM2_MASK)

#define EMAC_MAC_L3_L4_CONTROL2_L4DPM2_MASK      (0x100000U)
#define EMAC_MAC_L3_L4_CONTROL2_L4DPM2_SHIFT     (20U)
/*! L4DPM2 - Layer 4 Destination Port Match Enable 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL2_L4DPM2(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL2_L4DPM2_SHIFT)) & EMAC_MAC_L3_L4_CONTROL2_L4DPM2_MASK)

#define EMAC_MAC_L3_L4_CONTROL2_L4DPIM2_MASK     (0x200000U)
#define EMAC_MAC_L3_L4_CONTROL2_L4DPIM2_SHIFT    (21U)
/*! L4DPIM2 - Layer 4 Destination Port Inverse Match Enable 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL2_L4DPIM2(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL2_L4DPIM2_SHIFT)) & EMAC_MAC_L3_L4_CONTROL2_L4DPIM2_MASK)

#define EMAC_MAC_L3_L4_CONTROL2_DMCHN2_MASK      (0x1000000U)
#define EMAC_MAC_L3_L4_CONTROL2_DMCHN2_SHIFT     (24U)
/*! DMCHN2 - DMA Channel Number 2 */
#define EMAC_MAC_L3_L4_CONTROL2_DMCHN2(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL2_DMCHN2_SHIFT)) & EMAC_MAC_L3_L4_CONTROL2_DMCHN2_MASK)

#define EMAC_MAC_L3_L4_CONTROL2_DMCHEN2_MASK     (0x10000000U)
#define EMAC_MAC_L3_L4_CONTROL2_DMCHEN2_SHIFT    (28U)
/*! DMCHEN2 - DMA Channel Select Enable 2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL2_DMCHEN2(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL2_DMCHEN2_SHIFT)) & EMAC_MAC_L3_L4_CONTROL2_DMCHEN2_MASK)
/*! @} */

/*! @name MAC_LAYER4_ADDRESS2 - MAC Layer 4 Address 2 */
/*! @{ */

#define EMAC_MAC_LAYER4_ADDRESS2_L4SP2_MASK      (0xFFFFU)
#define EMAC_MAC_LAYER4_ADDRESS2_L4SP2_SHIFT     (0U)
/*! L4SP2 - Layer 4 Source Port Number 2 */
#define EMAC_MAC_LAYER4_ADDRESS2_L4SP2(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER4_ADDRESS2_L4SP2_SHIFT)) & EMAC_MAC_LAYER4_ADDRESS2_L4SP2_MASK)

#define EMAC_MAC_LAYER4_ADDRESS2_L4DP2_MASK      (0xFFFF0000U)
#define EMAC_MAC_LAYER4_ADDRESS2_L4DP2_SHIFT     (16U)
/*! L4DP2 - Layer 4 Destination Port Number 2 */
#define EMAC_MAC_LAYER4_ADDRESS2_L4DP2(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER4_ADDRESS2_L4DP2_SHIFT)) & EMAC_MAC_LAYER4_ADDRESS2_L4DP2_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR0_REG2 - MAC Layer 3 Address 0 Reg 2 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR0_REG2_L3A02_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR0_REG2_L3A02_SHIFT   (0U)
/*! L3A02 - Layer 3 Address 0 */
#define EMAC_MAC_LAYER3_ADDR0_REG2_L3A02(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR0_REG2_L3A02_SHIFT)) & EMAC_MAC_LAYER3_ADDR0_REG2_L3A02_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR1_REG2 - MAC Layer 3 Address 1 Reg 2 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR1_REG2_L3A12_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR1_REG2_L3A12_SHIFT   (0U)
/*! L3A12 - Layer 3 Address 1 */
#define EMAC_MAC_LAYER3_ADDR1_REG2_L3A12(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR1_REG2_L3A12_SHIFT)) & EMAC_MAC_LAYER3_ADDR1_REG2_L3A12_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR2_REG2 - MAC Layer 3 Address 2 Reg 2 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR2_REG2_L3A22_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR2_REG2_L3A22_SHIFT   (0U)
/*! L3A22 - Layer 3 Address 2 */
#define EMAC_MAC_LAYER3_ADDR2_REG2_L3A22(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR2_REG2_L3A22_SHIFT)) & EMAC_MAC_LAYER3_ADDR2_REG2_L3A22_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR3_REG2 - MAC Layer 3 Address 3 Reg 2 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR3_REG2_L3A32_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR3_REG2_L3A32_SHIFT   (0U)
/*! L3A32 - Layer 3 Address 3 */
#define EMAC_MAC_LAYER3_ADDR3_REG2_L3A32(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR3_REG2_L3A32_SHIFT)) & EMAC_MAC_LAYER3_ADDR3_REG2_L3A32_MASK)
/*! @} */

/*! @name MAC_L3_L4_CONTROL3 - MAC L3 L4 Control 3 */
/*! @{ */

#define EMAC_MAC_L3_L4_CONTROL3_L3PEN3_MASK      (0x1U)
#define EMAC_MAC_L3_L4_CONTROL3_L3PEN3_SHIFT     (0U)
/*! L3PEN3 - Layer 3 Protocol Enable 3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL3_L3PEN3(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL3_L3PEN3_SHIFT)) & EMAC_MAC_L3_L4_CONTROL3_L3PEN3_MASK)

#define EMAC_MAC_L3_L4_CONTROL3_L3SAM3_MASK      (0x4U)
#define EMAC_MAC_L3_L4_CONTROL3_L3SAM3_SHIFT     (2U)
/*! L3SAM3 - Layer 3 IP SA Match Enable 3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL3_L3SAM3(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL3_L3SAM3_SHIFT)) & EMAC_MAC_L3_L4_CONTROL3_L3SAM3_MASK)

#define EMAC_MAC_L3_L4_CONTROL3_L3SAIM3_MASK     (0x8U)
#define EMAC_MAC_L3_L4_CONTROL3_L3SAIM3_SHIFT    (3U)
/*! L3SAIM3 - Layer 3 IP SA Inverse Match Enable 3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL3_L3SAIM3(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL3_L3SAIM3_SHIFT)) & EMAC_MAC_L3_L4_CONTROL3_L3SAIM3_MASK)

#define EMAC_MAC_L3_L4_CONTROL3_L3DAM3_MASK      (0x10U)
#define EMAC_MAC_L3_L4_CONTROL3_L3DAM3_SHIFT     (4U)
/*! L3DAM3 - Layer 3 IP DA Match Enable 3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL3_L3DAM3(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL3_L3DAM3_SHIFT)) & EMAC_MAC_L3_L4_CONTROL3_L3DAM3_MASK)

#define EMAC_MAC_L3_L4_CONTROL3_L3DAIM3_MASK     (0x20U)
#define EMAC_MAC_L3_L4_CONTROL3_L3DAIM3_SHIFT    (5U)
/*! L3DAIM3 - Layer 3 IP DA Inverse Match Enable 3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL3_L3DAIM3(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL3_L3DAIM3_SHIFT)) & EMAC_MAC_L3_L4_CONTROL3_L3DAIM3_MASK)

#define EMAC_MAC_L3_L4_CONTROL3_L3HSBM3_MASK     (0x7C0U)
#define EMAC_MAC_L3_L4_CONTROL3_L3HSBM3_SHIFT    (6U)
/*! L3HSBM3 - Layer 3 IP SA Higher Bits Match 3 */
#define EMAC_MAC_L3_L4_CONTROL3_L3HSBM3(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL3_L3HSBM3_SHIFT)) & EMAC_MAC_L3_L4_CONTROL3_L3HSBM3_MASK)

#define EMAC_MAC_L3_L4_CONTROL3_L3HDBM3_MASK     (0xF800U)
#define EMAC_MAC_L3_L4_CONTROL3_L3HDBM3_SHIFT    (11U)
/*! L3HDBM3 - Layer 3 IP DA Higher Bits Match 3 */
#define EMAC_MAC_L3_L4_CONTROL3_L3HDBM3(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL3_L3HDBM3_SHIFT)) & EMAC_MAC_L3_L4_CONTROL3_L3HDBM3_MASK)

#define EMAC_MAC_L3_L4_CONTROL3_L4PEN3_MASK      (0x10000U)
#define EMAC_MAC_L3_L4_CONTROL3_L4PEN3_SHIFT     (16U)
/*! L4PEN3 - Layer 4 Protocol Enable 3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL3_L4PEN3(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL3_L4PEN3_SHIFT)) & EMAC_MAC_L3_L4_CONTROL3_L4PEN3_MASK)

#define EMAC_MAC_L3_L4_CONTROL3_L4SPM3_MASK      (0x40000U)
#define EMAC_MAC_L3_L4_CONTROL3_L4SPM3_SHIFT     (18U)
/*! L4SPM3 - Layer 4 Source Port Match Enable 3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL3_L4SPM3(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL3_L4SPM3_SHIFT)) & EMAC_MAC_L3_L4_CONTROL3_L4SPM3_MASK)

#define EMAC_MAC_L3_L4_CONTROL3_L4SPIM3_MASK     (0x80000U)
#define EMAC_MAC_L3_L4_CONTROL3_L4SPIM3_SHIFT    (19U)
/*! L4SPIM3 - Layer 4 Source Port Inverse Match Enable 3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL3_L4SPIM3(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL3_L4SPIM3_SHIFT)) & EMAC_MAC_L3_L4_CONTROL3_L4SPIM3_MASK)

#define EMAC_MAC_L3_L4_CONTROL3_L4DPM3_MASK      (0x100000U)
#define EMAC_MAC_L3_L4_CONTROL3_L4DPM3_SHIFT     (20U)
/*! L4DPM3 - Layer 4 Destination Port Match Enable 3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL3_L4DPM3(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL3_L4DPM3_SHIFT)) & EMAC_MAC_L3_L4_CONTROL3_L4DPM3_MASK)

#define EMAC_MAC_L3_L4_CONTROL3_L4DPIM3_MASK     (0x200000U)
#define EMAC_MAC_L3_L4_CONTROL3_L4DPIM3_SHIFT    (21U)
/*! L4DPIM3 - Layer 4 Destination Port Inverse Match Enable 3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL3_L4DPIM3(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL3_L4DPIM3_SHIFT)) & EMAC_MAC_L3_L4_CONTROL3_L4DPIM3_MASK)

#define EMAC_MAC_L3_L4_CONTROL3_DMCHN3_MASK      (0x1000000U)
#define EMAC_MAC_L3_L4_CONTROL3_DMCHN3_SHIFT     (24U)
/*! DMCHN3 - DMA Channel Number 2 */
#define EMAC_MAC_L3_L4_CONTROL3_DMCHN3(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL3_DMCHN3_SHIFT)) & EMAC_MAC_L3_L4_CONTROL3_DMCHN3_MASK)

#define EMAC_MAC_L3_L4_CONTROL3_DMCHEN3_MASK     (0x10000000U)
#define EMAC_MAC_L3_L4_CONTROL3_DMCHEN3_SHIFT    (28U)
/*! DMCHEN3 - DMA Channel Select Enable 3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_L3_L4_CONTROL3_DMCHEN3(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_L3_L4_CONTROL3_DMCHEN3_SHIFT)) & EMAC_MAC_L3_L4_CONTROL3_DMCHEN3_MASK)
/*! @} */

/*! @name MAC_LAYER4_ADDRESS3 - MAC Layer 4 Address 3 */
/*! @{ */

#define EMAC_MAC_LAYER4_ADDRESS3_L4SP3_MASK      (0xFFFFU)
#define EMAC_MAC_LAYER4_ADDRESS3_L4SP3_SHIFT     (0U)
/*! L4SP3 - Layer 4 Source Port Number 3 */
#define EMAC_MAC_LAYER4_ADDRESS3_L4SP3(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER4_ADDRESS3_L4SP3_SHIFT)) & EMAC_MAC_LAYER4_ADDRESS3_L4SP3_MASK)

#define EMAC_MAC_LAYER4_ADDRESS3_L4DP3_MASK      (0xFFFF0000U)
#define EMAC_MAC_LAYER4_ADDRESS3_L4DP3_SHIFT     (16U)
/*! L4DP3 - Layer 4 Destination Port Number 3 */
#define EMAC_MAC_LAYER4_ADDRESS3_L4DP3(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER4_ADDRESS3_L4DP3_SHIFT)) & EMAC_MAC_LAYER4_ADDRESS3_L4DP3_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR0_REG3 - MAC Layer 3 Address 0 Reg 3 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR0_REG3_L3A03_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR0_REG3_L3A03_SHIFT   (0U)
/*! L3A03 - Layer 3 Address 0 */
#define EMAC_MAC_LAYER3_ADDR0_REG3_L3A03(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR0_REG3_L3A03_SHIFT)) & EMAC_MAC_LAYER3_ADDR0_REG3_L3A03_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR1_REG3 - MAC Layer 3 Address 1 Reg 3 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR1_REG3_L3A13_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR1_REG3_L3A13_SHIFT   (0U)
/*! L3A13 - Layer 3 Address 1 */
#define EMAC_MAC_LAYER3_ADDR1_REG3_L3A13(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR1_REG3_L3A13_SHIFT)) & EMAC_MAC_LAYER3_ADDR1_REG3_L3A13_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR2_REG3 - MAC Layer 3 Address 2 Reg 3 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR2_REG3_L3A23_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR2_REG3_L3A23_SHIFT   (0U)
/*! L3A23 - Layer 3 Address 2 */
#define EMAC_MAC_LAYER3_ADDR2_REG3_L3A23(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR2_REG3_L3A23_SHIFT)) & EMAC_MAC_LAYER3_ADDR2_REG3_L3A23_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR3_REG3 - MAC Layer 3 Address 3 Reg 3 */
/*! @{ */

#define EMAC_MAC_LAYER3_ADDR3_REG3_L3A33_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_LAYER3_ADDR3_REG3_L3A33_SHIFT   (0U)
/*! L3A33 - Layer 3 Address 3 */
#define EMAC_MAC_LAYER3_ADDR3_REG3_L3A33(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_LAYER3_ADDR3_REG3_L3A33_SHIFT)) & EMAC_MAC_LAYER3_ADDR3_REG3_L3A33_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_CONTROL - MAC Timestamp Control */
/*! @{ */

#define EMAC_MAC_TIMESTAMP_CONTROL_TSENA_MASK    (0x1U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TSENA_SHIFT   (0U)
/*! TSENA - Timestamp Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TSENA(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TSENA_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TSENA_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_TSCFUPDT_MASK (0x2U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TSCFUPDT_SHIFT (1U)
/*! TSCFUPDT - Fine Or Coarse Timestamp Update
 *  0b0..Coarse method
 *  0b1..Fine method
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TSCFUPDT(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TSCFUPDT_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TSCFUPDT_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_TSINIT_MASK   (0x4U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TSINIT_SHIFT  (2U)
/*! TSINIT - Initialize Timestamp
 *  0b0..Not initialized
 *  0b1..Initialized
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TSINIT(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TSINIT_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TSINIT_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_TSUPDT_MASK   (0x8U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TSUPDT_SHIFT  (3U)
/*! TSUPDT - Update Timestamp
 *  0b0..Not updated
 *  0b1..Updated
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TSUPDT(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TSUPDT_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TSUPDT_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_TSADDREG_MASK (0x20U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TSADDREG_SHIFT (5U)
/*! TSADDREG - Update Addend Register
 *  0b0..Not updated
 *  0b1..Updated
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TSADDREG(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TSADDREG_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TSADDREG_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_PTGE_MASK     (0x40U)
#define EMAC_MAC_TIMESTAMP_CONTROL_PTGE_SHIFT    (6U)
/*! PTGE - Presentation Time Generation Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_PTGE(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_PTGE_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_PTGE_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_TSENALL_MASK  (0x100U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TSENALL_SHIFT (8U)
/*! TSENALL - Enable Timestamp For All Packets
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TSENALL(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TSENALL_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TSENALL_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_MASK (0x200U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_SHIFT (9U)
/*! TSCTRLSSR - Timestamp Digital Or Binary Rollover Control
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TSCTRLSSR(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_TSVER2ENA_MASK (0x400U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TSVER2ENA_SHIFT (10U)
/*! TSVER2ENA - Enable PTP Packet Processing For Version 2 Format
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TSVER2ENA(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TSVER2ENA_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TSVER2ENA_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_TSIPENA_MASK  (0x800U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TSIPENA_SHIFT (11U)
/*! TSIPENA - Enable Processing Of PTP Over Ethernet Packets
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TSIPENA(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TSIPENA_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TSIPENA_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_MASK (0x1000U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_SHIFT (12U)
/*! TSIPV6ENA - Enable Processing Of PTP Packets Sent Over IPv6-UDP
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TSIPV6ENA(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_MASK (0x2000U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_SHIFT (13U)
/*! TSIPV4ENA - Enable Processing Of PTP Packets Sent Over IPv4-UDP
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TSIPV4ENA(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_TSEVNTENA_MASK (0x4000U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TSEVNTENA_SHIFT (14U)
/*! TSEVNTENA - Enable Timestamp Snapshot For Event Messages
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TSEVNTENA(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TSEVNTENA_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TSEVNTENA_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_TSMSTRENA_MASK (0x8000U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TSMSTRENA_SHIFT (15U)
/*! TSMSTRENA - Enable Snapshot For Messages Relevant To Master
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TSMSTRENA(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TSMSTRENA_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TSMSTRENA_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_MASK (0x30000U)
#define EMAC_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_SHIFT (16U)
/*! SNAPTYPSEL - Select PTP Packets For Taking Snapshots */
#define EMAC_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_TSENMACADDR_MASK (0x40000U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TSENMACADDR_SHIFT (18U)
/*! TSENMACADDR - Enable MAC Address For PTP Packet Filtering
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TSENMACADDR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TSENMACADDR_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TSENMACADDR_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_ESTI_MASK     (0x100000U)
#define EMAC_MAC_TIMESTAMP_CONTROL_ESTI_SHIFT    (20U)
/*! ESTI - External System Time Input
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_ESTI(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_ESTI_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_ESTI_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_TXTSSTSM_MASK (0x1000000U)
#define EMAC_MAC_TIMESTAMP_CONTROL_TXTSSTSM_SHIFT (24U)
/*! TXTSSTSM - Transmit Timestamp Status Mode
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_TXTSSTSM(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_TXTSSTSM_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_TXTSSTSM_MASK)

#define EMAC_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_MASK (0x10000000U)
#define EMAC_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_SHIFT (28U)
/*! AV8021ASMEN - AV 802.1AS Mode Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_TIMESTAMP_CONTROL_AV8021ASMEN(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_SHIFT)) & EMAC_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_MASK)
/*! @} */

/*! @name MAC_SUB_SECOND_INCREMENT - MAC Sub Second Increment */
/*! @{ */

#define EMAC_MAC_SUB_SECOND_INCREMENT_SNSINC_MASK (0xFF00U)
#define EMAC_MAC_SUB_SECOND_INCREMENT_SNSINC_SHIFT (8U)
/*! SNSINC - Sub-Nanosecond Increment Value */
#define EMAC_MAC_SUB_SECOND_INCREMENT_SNSINC(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_SUB_SECOND_INCREMENT_SNSINC_SHIFT)) & EMAC_MAC_SUB_SECOND_INCREMENT_SNSINC_MASK)

#define EMAC_MAC_SUB_SECOND_INCREMENT_SSINC_MASK (0xFF0000U)
#define EMAC_MAC_SUB_SECOND_INCREMENT_SSINC_SHIFT (16U)
/*! SSINC - Sub-Second Increment Value */
#define EMAC_MAC_SUB_SECOND_INCREMENT_SSINC(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_SUB_SECOND_INCREMENT_SSINC_SHIFT)) & EMAC_MAC_SUB_SECOND_INCREMENT_SSINC_MASK)
/*! @} */

/*! @name MAC_SYSTEM_TIME_SECONDS - MAC System Time In Seconds */
/*! @{ */

#define EMAC_MAC_SYSTEM_TIME_SECONDS_TSS_MASK    (0xFFFFFFFFU)
#define EMAC_MAC_SYSTEM_TIME_SECONDS_TSS_SHIFT   (0U)
/*! TSS - Timestamp Second */
#define EMAC_MAC_SYSTEM_TIME_SECONDS_TSS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_SYSTEM_TIME_SECONDS_TSS_SHIFT)) & EMAC_MAC_SYSTEM_TIME_SECONDS_TSS_MASK)
/*! @} */

/*! @name MAC_SYSTEM_TIME_NANOSECONDS - MAC System Time In Nanoseconds */
/*! @{ */

#define EMAC_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_MASK (0x7FFFFFFFU)
#define EMAC_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_SHIFT (0U)
/*! TSSS - Timestamp Sub Seconds */
#define EMAC_MAC_SYSTEM_TIME_NANOSECONDS_TSSS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_SHIFT)) & EMAC_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_MASK)
/*! @} */

/*! @name MAC_SYSTEM_TIME_SECONDS_UPDATE - MAC System Time Seconds Update */
/*! @{ */

#define EMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_MASK (0xFFFFFFFFU)
#define EMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_SHIFT (0U)
/*! TSS - Timestamp Seconds */
#define EMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_SHIFT)) & EMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_MASK)
/*! @} */

/*! @name MAC_SYSTEM_TIME_NANOSECONDS_UPDATE - MAC System Time Nanoseconds Update */
/*! @{ */

#define EMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_MASK (0x7FFFFFFFU)
#define EMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_SHIFT (0U)
/*! TSSS - Timestamp Subseconds */
#define EMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_SHIFT)) & EMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_MASK)

#define EMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_MASK (0x80000000U)
#define EMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_SHIFT (31U)
/*! ADDSUB - Add Or Subtract Time
 *  0b0..Add time
 *  0b1..Subtract time
 */
#define EMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_SHIFT)) & EMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_ADDEND - MAC Timestamp Addend */
/*! @{ */

#define EMAC_MAC_TIMESTAMP_ADDEND_TSAR_MASK      (0xFFFFFFFFU)
#define EMAC_MAC_TIMESTAMP_ADDEND_TSAR_SHIFT     (0U)
/*! TSAR - Timestamp Addend Register */
#define EMAC_MAC_TIMESTAMP_ADDEND_TSAR(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_ADDEND_TSAR_SHIFT)) & EMAC_MAC_TIMESTAMP_ADDEND_TSAR_MASK)
/*! @} */

/*! @name MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS - MAC System Time Higher Word In Seconds */
/*! @{ */

#define EMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_MASK (0xFFFFU)
#define EMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_SHIFT (0U)
/*! TSHWR - Timestamp Higher Word Register */
#define EMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_SHIFT)) & EMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_STATUS - MAC Timestamp Status */
/*! @{ */

#define EMAC_MAC_TIMESTAMP_STATUS_TSSOVF_MASK    (0x1U)
#define EMAC_MAC_TIMESTAMP_STATUS_TSSOVF_SHIFT   (0U)
/*! TSSOVF - Timestamp Seconds Overflow
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_TIMESTAMP_STATUS_TSSOVF(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_STATUS_TSSOVF_SHIFT)) & EMAC_MAC_TIMESTAMP_STATUS_TSSOVF_MASK)

#define EMAC_MAC_TIMESTAMP_STATUS_TSTARGT0_MASK  (0x2U)
#define EMAC_MAC_TIMESTAMP_STATUS_TSTARGT0_SHIFT (1U)
/*! TSTARGT0 - Timestamp Target Time Reached
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_TIMESTAMP_STATUS_TSTARGT0(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_STATUS_TSTARGT0_SHIFT)) & EMAC_MAC_TIMESTAMP_STATUS_TSTARGT0_MASK)

#define EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR0_MASK (0x8U)
#define EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR0_SHIFT (3U)
/*! TSTRGTERR0 - Timestamp Target Time Error
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR0(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR0_SHIFT)) & EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR0_MASK)

#define EMAC_MAC_TIMESTAMP_STATUS_TSTARGT1_MASK  (0x10U)
#define EMAC_MAC_TIMESTAMP_STATUS_TSTARGT1_SHIFT (4U)
/*! TSTARGT1 - Timestamp Target Time Reached For Target Time PPS1
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_TIMESTAMP_STATUS_TSTARGT1(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_STATUS_TSTARGT1_SHIFT)) & EMAC_MAC_TIMESTAMP_STATUS_TSTARGT1_MASK)

#define EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR1_MASK (0x20U)
#define EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR1_SHIFT (5U)
/*! TSTRGTERR1 - Timestamp Target Time Error
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR1(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR1_SHIFT)) & EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR1_MASK)

#define EMAC_MAC_TIMESTAMP_STATUS_TSTARGT2_MASK  (0x40U)
#define EMAC_MAC_TIMESTAMP_STATUS_TSTARGT2_SHIFT (6U)
/*! TSTARGT2 - Timestamp Target Time Reached For Target Time PPS2
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_TIMESTAMP_STATUS_TSTARGT2(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_STATUS_TSTARGT2_SHIFT)) & EMAC_MAC_TIMESTAMP_STATUS_TSTARGT2_MASK)

#define EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR2_MASK (0x80U)
#define EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR2_SHIFT (7U)
/*! TSTRGTERR2 - Timestamp Target Time Error
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR2(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR2_SHIFT)) & EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR2_MASK)

#define EMAC_MAC_TIMESTAMP_STATUS_TSTARGT3_MASK  (0x100U)
#define EMAC_MAC_TIMESTAMP_STATUS_TSTARGT3_SHIFT (8U)
/*! TSTARGT3 - Timestamp Target Time Reached For Target Time PPS3
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_TIMESTAMP_STATUS_TSTARGT3(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_STATUS_TSTARGT3_SHIFT)) & EMAC_MAC_TIMESTAMP_STATUS_TSTARGT3_MASK)

#define EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR3_MASK (0x200U)
#define EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR3_SHIFT (9U)
/*! TSTRGTERR3 - Timestamp Target Time Error
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR3(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR3_SHIFT)) & EMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR3_MASK)

#define EMAC_MAC_TIMESTAMP_STATUS_TXTSSIS_MASK   (0x8000U)
#define EMAC_MAC_TIMESTAMP_STATUS_TXTSSIS_SHIFT  (15U)
/*! TXTSSIS - Transmit Timestamp Status Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_TIMESTAMP_STATUS_TXTSSIS(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_STATUS_TXTSSIS_SHIFT)) & EMAC_MAC_TIMESTAMP_STATUS_TXTSSIS_MASK)
/*! @} */

/*! @name MAC_TX_TIMESTAMP_STATUS_NANOSECONDS - MAC Transmit Timestamp Status In Nanoseconds */
/*! @{ */

#define EMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_MASK (0x7FFFFFFFU)
#define EMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_SHIFT (0U)
/*! TXTSSLO - Transmit Timestamp Status Low */
#define EMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_SHIFT)) & EMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_MASK)

#define EMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_MASK (0x80000000U)
#define EMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_SHIFT (31U)
/*! TXTSSMIS - Transmit Timestamp Status Missed
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_SHIFT)) & EMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_MASK)
/*! @} */

/*! @name MAC_TX_TIMESTAMP_STATUS_SECONDS - MAC Transmit Timestamp Status In Seconds */
/*! @{ */

#define EMAC_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_MASK (0xFFFFFFFFU)
#define EMAC_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_SHIFT (0U)
/*! TXTSSHI - Transmit Timestamp Status High */
#define EMAC_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_SHIFT)) & EMAC_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_INGRESS_ASYM_CORR - MAC Timestamp Ingress Asymmetry Correction */
/*! @{ */

#define EMAC_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_MASK (0xFFFFFFFFU)
#define EMAC_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_SHIFT (0U)
/*! OSTIAC - One-Step Timestamp Ingress Asymmetry Correction */
#define EMAC_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_SHIFT)) & EMAC_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_EGRESS_ASYM_CORR - MAC Timestamp Egress Asymmetry Correction */
/*! @{ */

#define EMAC_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_MASK (0xFFFFFFFFU)
#define EMAC_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_SHIFT (0U)
/*! OSTEAC - One-Step Timestamp Egress Asymmetry Correction */
#define EMAC_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_SHIFT)) & EMAC_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND - MAC Timestamp Ingress Correction In Nanoseconds */
/*! @{ */

#define EMAC_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_MASK (0xFFFFFFFFU)
#define EMAC_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_SHIFT (0U)
/*! TSIC - Timestamp Ingress Correction */
#define EMAC_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_SHIFT)) & EMAC_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND - MAC Timestamp Egress Correction In Nanoseconds */
/*! @{ */

#define EMAC_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_MASK (0xFFFFFFFFU)
#define EMAC_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_SHIFT (0U)
/*! TSEC - Timestamp Egress Correction */
#define EMAC_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_SHIFT)) & EMAC_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC - MAC Timestamp Ingress Correction In Subnanoseconds */
/*! @{ */

#define EMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS_MASK (0xFF00U)
#define EMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS_SHIFT (8U)
/*! TSICSNS - Timestamp Ingress Correction In Sub-Nanoseconds */
#define EMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS_SHIFT)) & EMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC - MAC Timestamp Engress Correction In Subnanoseconds */
/*! @{ */

#define EMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS_MASK (0xFF00U)
#define EMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS_SHIFT (8U)
/*! TSECSNS - Timestamp Egress Correction In Sub-Nanoseconds */
#define EMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS_SHIFT)) & EMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_INGRESS_LATENCY - MAC Timestamp Ingress Latency */
/*! @{ */

#define EMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_MASK (0xFF00U)
#define EMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_SHIFT (8U)
/*! ITLSNS - Ingress Timestamp Latency In Nanoseconds */
#define EMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_SHIFT)) & EMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_MASK)

#define EMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_MASK (0xFFF0000U)
#define EMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_SHIFT (16U)
/*! ITLNS - Ingress Timestamp Latency In Sub-Nanoseconds */
#define EMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_SHIFT)) & EMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_EGRESS_LATENCY - MAC Timestamp Egress Latecy */
/*! @{ */

#define EMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_MASK (0xFF00U)
#define EMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_SHIFT (8U)
/*! ETLSNS - Egress Timestamp Latency In Sub-Nanoseconds */
#define EMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_SHIFT)) & EMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_MASK)

#define EMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_MASK (0xFFF0000U)
#define EMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_SHIFT (16U)
/*! ETLNS - Egress Timestamp Latency In Nanoseconds */
#define EMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_SHIFT)) & EMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_MASK)
/*! @} */

/*! @name MAC_PPS_CONTROL - MAC PPS Control */
/*! @{ */

#define EMAC_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_MASK (0xFU)
#define EMAC_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_SHIFT (0U)
/*! PPSCTRL_PPSCMD - PPS Output Frequency Control */
#define EMAC_MAC_PPS_CONTROL_PPSCTRL_PPSCMD(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_SHIFT)) & EMAC_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_MASK)

#define EMAC_MAC_PPS_CONTROL_PPSEN0_MASK         (0x10U)
#define EMAC_MAC_PPS_CONTROL_PPSEN0_SHIFT        (4U)
/*! PPSEN0 - Flexible PPS Output Mode Enable 0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_PPS_CONTROL_PPSEN0(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS_CONTROL_PPSEN0_SHIFT)) & EMAC_MAC_PPS_CONTROL_PPSEN0_MASK)

#define EMAC_MAC_PPS_CONTROL_TRGTMODSEL0_MASK    (0x60U)
#define EMAC_MAC_PPS_CONTROL_TRGTMODSEL0_SHIFT   (5U)
/*! TRGTMODSEL0 - Target Time Register Mode For PPS0 Output
 *  0b00..Target Time registers are programmed only for generating the interrupt event. The flexible PPS function
 *        must not be 1 in this mode, otherwise spurious transitions may be observed on the corresponding ptp_pps_o
 *        output port.
 *  0b01..Reserved
 *  0b10..Target Time registers are programmed for generating the interrupt event and starting or stopping the PPS0 output signal generation.
 *  0b11..Target Time registers are programmed only for starting or stopping the PPS0 output signal generation. No interrupt is asserted.
 */
#define EMAC_MAC_PPS_CONTROL_TRGTMODSEL0(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS_CONTROL_TRGTMODSEL0_SHIFT)) & EMAC_MAC_PPS_CONTROL_TRGTMODSEL0_MASK)

#define EMAC_MAC_PPS_CONTROL_MCGREN0_MASK        (0x80U)
#define EMAC_MAC_PPS_CONTROL_MCGREN0_SHIFT       (7U)
/*! MCGREN0 - MCGR Mode Enable For PPS0 Output
 *  0b0..PPS mode
 *  0b1..MCGR mode
 */
#define EMAC_MAC_PPS_CONTROL_MCGREN0(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS_CONTROL_MCGREN0_SHIFT)) & EMAC_MAC_PPS_CONTROL_MCGREN0_MASK)

#define EMAC_MAC_PPS_CONTROL_PPSCMD1_MASK        (0xF00U)
#define EMAC_MAC_PPS_CONTROL_PPSCMD1_SHIFT       (8U)
/*! PPSCMD1 - Flexible PPS1 Output Control */
#define EMAC_MAC_PPS_CONTROL_PPSCMD1(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS_CONTROL_PPSCMD1_SHIFT)) & EMAC_MAC_PPS_CONTROL_PPSCMD1_MASK)

#define EMAC_MAC_PPS_CONTROL_TRGTMODSEL1_MASK    (0x6000U)
#define EMAC_MAC_PPS_CONTROL_TRGTMODSEL1_SHIFT   (13U)
/*! TRGTMODSEL1 - Target Time Register Mode For PPS1 Output
 *  0b00..Target Time registers are programmed only for generating the interrupt event. The flexible PPS function
 *        must not be 1 in this mode, otherwise spurious transitions may be observed on the corresponding ptp_pps_o
 *        output port.
 *  0b01..Reserved
 *  0b10..Target Time registers are programmed for generating the interrupt event and starting or stopping the PPS0 output signal generation.
 *  0b11..Target Time registers are programmed only for starting or stopping the PPS0 output signal generation. No interrupt is asserted.
 */
#define EMAC_MAC_PPS_CONTROL_TRGTMODSEL1(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS_CONTROL_TRGTMODSEL1_SHIFT)) & EMAC_MAC_PPS_CONTROL_TRGTMODSEL1_MASK)

#define EMAC_MAC_PPS_CONTROL_MCGREN1_MASK        (0x8000U)
#define EMAC_MAC_PPS_CONTROL_MCGREN1_SHIFT       (15U)
/*! MCGREN1 - MCGR Mode Enable For PPS1 Output
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_PPS_CONTROL_MCGREN1(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS_CONTROL_MCGREN1_SHIFT)) & EMAC_MAC_PPS_CONTROL_MCGREN1_MASK)

#define EMAC_MAC_PPS_CONTROL_PPSCMD2_MASK        (0xF0000U)
#define EMAC_MAC_PPS_CONTROL_PPSCMD2_SHIFT       (16U)
/*! PPSCMD2 - Flexible PPS2 Output Control */
#define EMAC_MAC_PPS_CONTROL_PPSCMD2(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS_CONTROL_PPSCMD2_SHIFT)) & EMAC_MAC_PPS_CONTROL_PPSCMD2_MASK)

#define EMAC_MAC_PPS_CONTROL_TRGTMODSEL2_MASK    (0x600000U)
#define EMAC_MAC_PPS_CONTROL_TRGTMODSEL2_SHIFT   (21U)
/*! TRGTMODSEL2 - Target Time Register Mode For PPS2 Output
 *  0b00..Target Time registers are programmed only for generating the interrupt event. The flexible PPS function
 *        must not be enabled in this mode, otherwise spurious transitions may be observed on the corresponding
 *        ptp_pps_o output port.
 *  0b01..Reserved
 *  0b10..Target Time registers are programmed for generating the interrupt event and starting or stopping the PPS0 output signal generation.
 *  0b11..Target Time registers are programmed only for starting or stopping the PPS0 output signal generation. No interrupt is asserted.
 */
#define EMAC_MAC_PPS_CONTROL_TRGTMODSEL2(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS_CONTROL_TRGTMODSEL2_SHIFT)) & EMAC_MAC_PPS_CONTROL_TRGTMODSEL2_MASK)

#define EMAC_MAC_PPS_CONTROL_MCGREN2_MASK        (0x800000U)
#define EMAC_MAC_PPS_CONTROL_MCGREN2_SHIFT       (23U)
/*! MCGREN2 - MCGR Mode Enable For PPS2 Output
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MAC_PPS_CONTROL_MCGREN2(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS_CONTROL_MCGREN2_SHIFT)) & EMAC_MAC_PPS_CONTROL_MCGREN2_MASK)

#define EMAC_MAC_PPS_CONTROL_PPSCMD3_MASK        (0xF000000U)
#define EMAC_MAC_PPS_CONTROL_PPSCMD3_SHIFT       (24U)
/*! PPSCMD3 - Flexible PPS3 Output Control */
#define EMAC_MAC_PPS_CONTROL_PPSCMD3(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS_CONTROL_PPSCMD3_SHIFT)) & EMAC_MAC_PPS_CONTROL_PPSCMD3_MASK)

#define EMAC_MAC_PPS_CONTROL_TRGTMODSEL3_MASK    (0x60000000U)
#define EMAC_MAC_PPS_CONTROL_TRGTMODSEL3_SHIFT   (29U)
/*! TRGTMODSEL3 - Target Time Register Mode For PPS3 Output
 *  0b00..Target Time registers are programmed only for generating the interrupt event. The flexible PPS function
 *        must not be enabled in this mode, otherwise spurious transitions may be observed on the corresponding
 *        ptp_pps_o output port.
 *  0b01..Reserved
 *  0b10..Target Time registers are programmed for generating the interrupt event and starting or stopping the PPS0 output signal generation.
 *  0b11..Target Time registers are programmed only for starting or stopping the PPS0 output signal generation. No interrupt is asserted.
 */
#define EMAC_MAC_PPS_CONTROL_TRGTMODSEL3(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS_CONTROL_TRGTMODSEL3_SHIFT)) & EMAC_MAC_PPS_CONTROL_TRGTMODSEL3_MASK)

#define EMAC_MAC_PPS_CONTROL_MCGREN3_MASK        (0x80000000U)
#define EMAC_MAC_PPS_CONTROL_MCGREN3_SHIFT       (31U)
/*! MCGREN3 - MCGR Mode Enable For PPS3 Output */
#define EMAC_MAC_PPS_CONTROL_MCGREN3(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS_CONTROL_MCGREN3_SHIFT)) & EMAC_MAC_PPS_CONTROL_MCGREN3_MASK)
/*! @} */

/*! @name MAC_PPS0_TARGET_TIME_SECONDS - MAC PPS0 Target Time In Seconds */
/*! @{ */

#define EMAC_MAC_PPS0_TARGET_TIME_SECONDS_TSTRH0_MASK (0xFFFFFFFFU)
#define EMAC_MAC_PPS0_TARGET_TIME_SECONDS_TSTRH0_SHIFT (0U)
/*! TSTRH0 - PPS Target Time In Seconds Register */
#define EMAC_MAC_PPS0_TARGET_TIME_SECONDS_TSTRH0(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS0_TARGET_TIME_SECONDS_TSTRH0_SHIFT)) & EMAC_MAC_PPS0_TARGET_TIME_SECONDS_TSTRH0_MASK)
/*! @} */

/*! @name MAC_PPS0_TARGET_TIME_NANOSECONDS - MAC PPS0 Target Time In Nanoseconds */
/*! @{ */

#define EMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_MASK (0x7FFFFFFFU)
#define EMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_SHIFT (0U)
/*! TTSL0 - Target Time Low For PPS0 */
#define EMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TTSL0(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_SHIFT)) & EMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_MASK)

#define EMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TRGTBUSY0_MASK (0x80000000U)
#define EMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TRGTBUSY0_SHIFT (31U)
/*! TRGTBUSY0 - PPS Target Time Busy Status 0
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TRGTBUSY0(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TRGTBUSY0_SHIFT)) & EMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TRGTBUSY0_MASK)
/*! @} */

/*! @name MAC_PPS0_INTERVAL - MAC PPS0 Interval */
/*! @{ */

#define EMAC_MAC_PPS0_INTERVAL_PPSINT0_MASK      (0xFFFFFFFFU)
#define EMAC_MAC_PPS0_INTERVAL_PPSINT0_SHIFT     (0U)
/*! PPSINT0 - PPS Output Signal Interval 0 */
#define EMAC_MAC_PPS0_INTERVAL_PPSINT0(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS0_INTERVAL_PPSINT0_SHIFT)) & EMAC_MAC_PPS0_INTERVAL_PPSINT0_MASK)
/*! @} */

/*! @name MAC_PPS0_WIDTH - MAC PPS0 Width */
/*! @{ */

#define EMAC_MAC_PPS0_WIDTH_PPSWIDTH0_MASK       (0xFFFFFFFFU)
#define EMAC_MAC_PPS0_WIDTH_PPSWIDTH0_SHIFT      (0U)
/*! PPSWIDTH0 - PPS Output Signal Width 0 */
#define EMAC_MAC_PPS0_WIDTH_PPSWIDTH0(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS0_WIDTH_PPSWIDTH0_SHIFT)) & EMAC_MAC_PPS0_WIDTH_PPSWIDTH0_MASK)
/*! @} */

/*! @name MAC_PPS1_TARGET_TIME_SECONDS - MAC PPS1 Target Time In Seconds */
/*! @{ */

#define EMAC_MAC_PPS1_TARGET_TIME_SECONDS_TSTRH1_MASK (0xFFFFFFFFU)
#define EMAC_MAC_PPS1_TARGET_TIME_SECONDS_TSTRH1_SHIFT (0U)
/*! TSTRH1 - PPS Target Time In Seconds 1 */
#define EMAC_MAC_PPS1_TARGET_TIME_SECONDS_TSTRH1(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS1_TARGET_TIME_SECONDS_TSTRH1_SHIFT)) & EMAC_MAC_PPS1_TARGET_TIME_SECONDS_TSTRH1_MASK)
/*! @} */

/*! @name MAC_PPS1_TARGET_TIME_NANOSECONDS - MAC PPS1 Target Time In Nanoseconds */
/*! @{ */

#define EMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TTSL1_MASK (0x7FFFFFFFU)
#define EMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TTSL1_SHIFT (0U)
/*! TTSL1 - Target Time Low For PPS1 */
#define EMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TTSL1(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TTSL1_SHIFT)) & EMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TTSL1_MASK)

#define EMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TRGTBUSY1_MASK (0x80000000U)
#define EMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TRGTBUSY1_SHIFT (31U)
/*! TRGTBUSY1 - PPS Target Time Busy Status 1
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TRGTBUSY1(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TRGTBUSY1_SHIFT)) & EMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TRGTBUSY1_MASK)
/*! @} */

/*! @name MAC_PPS1_INTERVAL - MAC PPS1 Interval */
/*! @{ */

#define EMAC_MAC_PPS1_INTERVAL_PPSINT1_MASK      (0xFFFFFFFFU)
#define EMAC_MAC_PPS1_INTERVAL_PPSINT1_SHIFT     (0U)
/*! PPSINT1 - PPS Output Signal Interval 1 */
#define EMAC_MAC_PPS1_INTERVAL_PPSINT1(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS1_INTERVAL_PPSINT1_SHIFT)) & EMAC_MAC_PPS1_INTERVAL_PPSINT1_MASK)
/*! @} */

/*! @name MAC_PPS1_WIDTH - MAC PPS1 Width */
/*! @{ */

#define EMAC_MAC_PPS1_WIDTH_PPSWIDTH1_MASK       (0xFFFFFFFFU)
#define EMAC_MAC_PPS1_WIDTH_PPSWIDTH1_SHIFT      (0U)
/*! PPSWIDTH1 - PPS Output Signal Width 1 */
#define EMAC_MAC_PPS1_WIDTH_PPSWIDTH1(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS1_WIDTH_PPSWIDTH1_SHIFT)) & EMAC_MAC_PPS1_WIDTH_PPSWIDTH1_MASK)
/*! @} */

/*! @name MAC_PPS2_TARGET_TIME_SECONDS - MAC PPS2 Taget Time In Seconds */
/*! @{ */

#define EMAC_MAC_PPS2_TARGET_TIME_SECONDS_TSTRH2_MASK (0xFFFFFFFFU)
#define EMAC_MAC_PPS2_TARGET_TIME_SECONDS_TSTRH2_SHIFT (0U)
/*! TSTRH2 - PPS Target Time In Seconds 2 */
#define EMAC_MAC_PPS2_TARGET_TIME_SECONDS_TSTRH2(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS2_TARGET_TIME_SECONDS_TSTRH2_SHIFT)) & EMAC_MAC_PPS2_TARGET_TIME_SECONDS_TSTRH2_MASK)
/*! @} */

/*! @name MAC_PPS2_TARGET_TIME_NANOSECONDS - MAC PPS2 Target Time In Nanoseconds */
/*! @{ */

#define EMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TTSL2_MASK (0x7FFFFFFFU)
#define EMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TTSL2_SHIFT (0U)
/*! TTSL2 - Target Time Low For PPS2 */
#define EMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TTSL2(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TTSL2_SHIFT)) & EMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TTSL2_MASK)

#define EMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TRGTBUSY2_MASK (0x80000000U)
#define EMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TRGTBUSY2_SHIFT (31U)
/*! TRGTBUSY2 - PPS Target Time Busy Status 2
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TRGTBUSY2(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TRGTBUSY2_SHIFT)) & EMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TRGTBUSY2_MASK)
/*! @} */

/*! @name MAC_PPS2_INTERVAL - MAC PPS2 Interval */
/*! @{ */

#define EMAC_MAC_PPS2_INTERVAL_PPSINT2_MASK      (0xFFFFFFFFU)
#define EMAC_MAC_PPS2_INTERVAL_PPSINT2_SHIFT     (0U)
/*! PPSINT2 - PPS Output Signal Interval 2 */
#define EMAC_MAC_PPS2_INTERVAL_PPSINT2(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS2_INTERVAL_PPSINT2_SHIFT)) & EMAC_MAC_PPS2_INTERVAL_PPSINT2_MASK)
/*! @} */

/*! @name MAC_PPS2_WIDTH - MAC PPS2 Width */
/*! @{ */

#define EMAC_MAC_PPS2_WIDTH_PPSWIDTH2_MASK       (0xFFFFFFFFU)
#define EMAC_MAC_PPS2_WIDTH_PPSWIDTH2_SHIFT      (0U)
/*! PPSWIDTH2 - PPS Output Signal Width 2 */
#define EMAC_MAC_PPS2_WIDTH_PPSWIDTH2(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS2_WIDTH_PPSWIDTH2_SHIFT)) & EMAC_MAC_PPS2_WIDTH_PPSWIDTH2_MASK)
/*! @} */

/*! @name MAC_PPS3_TARGET_TIME_SECONDS - MAC PPS3 Target Time In Seconds */
/*! @{ */

#define EMAC_MAC_PPS3_TARGET_TIME_SECONDS_TSTRH3_MASK (0xFFFFFFFFU)
#define EMAC_MAC_PPS3_TARGET_TIME_SECONDS_TSTRH3_SHIFT (0U)
/*! TSTRH3 - PPS Target Time In Seconds 3 */
#define EMAC_MAC_PPS3_TARGET_TIME_SECONDS_TSTRH3(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS3_TARGET_TIME_SECONDS_TSTRH3_SHIFT)) & EMAC_MAC_PPS3_TARGET_TIME_SECONDS_TSTRH3_MASK)
/*! @} */

/*! @name MAC_PPS3_TARGET_TIME_NANOSECONDS - MAC PPS3 Target Time In Nanoseconds */
/*! @{ */

#define EMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TTSL3_MASK (0x7FFFFFFFU)
#define EMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TTSL3_SHIFT (0U)
/*! TTSL3 - Target Time Low For PPS3 */
#define EMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TTSL3(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TTSL3_SHIFT)) & EMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TTSL3_MASK)

#define EMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TRGTBUSY3_MASK (0x80000000U)
#define EMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TRGTBUSY3_SHIFT (31U)
/*! TRGTBUSY3 - PPS Target Time Register Busy 3
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TRGTBUSY3(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TRGTBUSY3_SHIFT)) & EMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TRGTBUSY3_MASK)
/*! @} */

/*! @name MAC_PPS3_INTERVAL - MAC PPS3 Interval */
/*! @{ */

#define EMAC_MAC_PPS3_INTERVAL_PPSINT3_MASK      (0xFFFFFFFFU)
#define EMAC_MAC_PPS3_INTERVAL_PPSINT3_SHIFT     (0U)
/*! PPSINT3 - PPS Output Signal Interval */
#define EMAC_MAC_PPS3_INTERVAL_PPSINT3(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS3_INTERVAL_PPSINT3_SHIFT)) & EMAC_MAC_PPS3_INTERVAL_PPSINT3_MASK)
/*! @} */

/*! @name MAC_PPS3_WIDTH - MAC PPS3 Width */
/*! @{ */

#define EMAC_MAC_PPS3_WIDTH_PPSWIDTH3_MASK       (0xFFFFFFFFU)
#define EMAC_MAC_PPS3_WIDTH_PPSWIDTH3_SHIFT      (0U)
/*! PPSWIDTH3 - PPS Output Signal Width 3 */
#define EMAC_MAC_PPS3_WIDTH_PPSWIDTH3(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MAC_PPS3_WIDTH_PPSWIDTH3_SHIFT)) & EMAC_MAC_PPS3_WIDTH_PPSWIDTH3_MASK)
/*! @} */

/*! @name MTL_OPERATION_MODE - MTL Operation Mode */
/*! @{ */

#define EMAC_MTL_OPERATION_MODE_DTXSTS_MASK      (0x2U)
#define EMAC_MTL_OPERATION_MODE_DTXSTS_SHIFT     (1U)
/*! DTXSTS - Drop Transmit Status
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_OPERATION_MODE_DTXSTS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_OPERATION_MODE_DTXSTS_SHIFT)) & EMAC_MTL_OPERATION_MODE_DTXSTS_MASK)

#define EMAC_MTL_OPERATION_MODE_RAA_MASK         (0x4U)
#define EMAC_MTL_OPERATION_MODE_RAA_SHIFT        (2U)
/*! RAA - Receive Arbitration Algorithm
 *  0b0..Strict priority (SP)
 *  0b1..Weighted strict priority (WSP)
 */
#define EMAC_MTL_OPERATION_MODE_RAA(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_OPERATION_MODE_RAA_SHIFT)) & EMAC_MTL_OPERATION_MODE_RAA_MASK)

#define EMAC_MTL_OPERATION_MODE_SCHALG_MASK      (0x60U)
#define EMAC_MTL_OPERATION_MODE_SCHALG_SHIFT     (5U)
/*! SCHALG - Transmit Scheduling Algorithm
 *  0b00..WRR algorithm
 *  0b01..WFQ algorithm when DCB feature selected; otherwise, reserved
 *  0b10..DWRR algorithm when DCB feature selected; otherwise, reserved
 *  0b11..Strict priority algorithm
 */
#define EMAC_MTL_OPERATION_MODE_SCHALG(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_OPERATION_MODE_SCHALG_SHIFT)) & EMAC_MTL_OPERATION_MODE_SCHALG_MASK)

#define EMAC_MTL_OPERATION_MODE_CNTPRST_MASK     (0x100U)
#define EMAC_MTL_OPERATION_MODE_CNTPRST_SHIFT    (8U)
/*! CNTPRST - Counters Preset
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_OPERATION_MODE_CNTPRST(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_OPERATION_MODE_CNTPRST_SHIFT)) & EMAC_MTL_OPERATION_MODE_CNTPRST_MASK)

#define EMAC_MTL_OPERATION_MODE_CNTCLR_MASK      (0x200U)
#define EMAC_MTL_OPERATION_MODE_CNTCLR_SHIFT     (9U)
/*! CNTCLR - Counters Reset
 *  0b0..Not reset
 *  0b1..Reset
 */
#define EMAC_MTL_OPERATION_MODE_CNTCLR(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_OPERATION_MODE_CNTCLR_SHIFT)) & EMAC_MTL_OPERATION_MODE_CNTCLR_MASK)

#define EMAC_MTL_OPERATION_MODE_FRPE_MASK        (0x8000U)
#define EMAC_MTL_OPERATION_MODE_FRPE_SHIFT       (15U)
/*! FRPE - Flexible Receive Parser Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_OPERATION_MODE_FRPE(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_OPERATION_MODE_FRPE_SHIFT)) & EMAC_MTL_OPERATION_MODE_FRPE_MASK)
/*! @} */

/*! @name MTL_DBG_CTL - MTL Debug Control */
/*! @{ */

#define EMAC_MTL_DBG_CTL_FDBGEN_MASK             (0x1U)
#define EMAC_MTL_DBG_CTL_FDBGEN_SHIFT            (0U)
/*! FDBGEN - FIFO Debug Access Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DBG_CTL_FDBGEN(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_CTL_FDBGEN_SHIFT)) & EMAC_MTL_DBG_CTL_FDBGEN_MASK)

#define EMAC_MTL_DBG_CTL_DBGMOD_MASK             (0x2U)
#define EMAC_MTL_DBG_CTL_DBGMOD_SHIFT            (1U)
/*! DBGMOD - Debug Mode Access to FIFO
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DBG_CTL_DBGMOD(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_CTL_DBGMOD_SHIFT)) & EMAC_MTL_DBG_CTL_DBGMOD_MASK)

#define EMAC_MTL_DBG_CTL_BYTEEN_MASK             (0xCU)
#define EMAC_MTL_DBG_CTL_BYTEEN_SHIFT            (2U)
/*! BYTEEN - Byte Enables
 *  0b00..Byte 0 valid
 *  0b01..Byte 0 and byte 1 valid
 *  0b10..Byte 0, byte 1, and byte 2 valid
 *  0b11..All four bytes valid
 */
#define EMAC_MTL_DBG_CTL_BYTEEN(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_CTL_BYTEEN_SHIFT)) & EMAC_MTL_DBG_CTL_BYTEEN_MASK)

#define EMAC_MTL_DBG_CTL_PKTSTATE_MASK           (0x60U)
#define EMAC_MTL_DBG_CTL_PKTSTATE_SHIFT          (5U)
/*! PKTSTATE - Encoded Packet State
 *  0b00..Packet data
 *  0b01..Control word/normal status
 *  0b10..SOP data/last status
 *  0b11..EOP data/EOP
 */
#define EMAC_MTL_DBG_CTL_PKTSTATE(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_CTL_PKTSTATE_SHIFT)) & EMAC_MTL_DBG_CTL_PKTSTATE_MASK)

#define EMAC_MTL_DBG_CTL_RSTALL_MASK             (0x100U)
#define EMAC_MTL_DBG_CTL_RSTALL_SHIFT            (8U)
/*! RSTALL - Reset All Pointers
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DBG_CTL_RSTALL(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_CTL_RSTALL_SHIFT)) & EMAC_MTL_DBG_CTL_RSTALL_MASK)

#define EMAC_MTL_DBG_CTL_RSTSEL_MASK             (0x200U)
#define EMAC_MTL_DBG_CTL_RSTSEL_SHIFT            (9U)
/*! RSTSEL - Reset Pointers Of Selected FIFO
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DBG_CTL_RSTSEL(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_CTL_RSTSEL_SHIFT)) & EMAC_MTL_DBG_CTL_RSTSEL_MASK)

#define EMAC_MTL_DBG_CTL_FIFORDEN_MASK           (0x400U)
#define EMAC_MTL_DBG_CTL_FIFORDEN_SHIFT          (10U)
/*! FIFORDEN - FIFO Read Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DBG_CTL_FIFORDEN(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_CTL_FIFORDEN_SHIFT)) & EMAC_MTL_DBG_CTL_FIFORDEN_MASK)

#define EMAC_MTL_DBG_CTL_FIFOWREN_MASK           (0x800U)
#define EMAC_MTL_DBG_CTL_FIFOWREN_SHIFT          (11U)
/*! FIFOWREN - FIFO Write Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DBG_CTL_FIFOWREN(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_CTL_FIFOWREN_SHIFT)) & EMAC_MTL_DBG_CTL_FIFOWREN_MASK)

#define EMAC_MTL_DBG_CTL_FIFOSEL_MASK            (0x3000U)
#define EMAC_MTL_DBG_CTL_FIFOSEL_SHIFT           (12U)
/*! FIFOSEL - FIFO Selected for Access
 *  0b00..Transmit FIFO
 *  0b01..Transmit status FIFO (only read access when SLVMOD is set)
 *  0b10..TSO FIFO (cannot be accessed when SLVMOD is set)
 *  0b11..Receive FIFO
 */
#define EMAC_MTL_DBG_CTL_FIFOSEL(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_CTL_FIFOSEL_SHIFT)) & EMAC_MTL_DBG_CTL_FIFOSEL_MASK)

#define EMAC_MTL_DBG_CTL_PKTIE_MASK              (0x4000U)
#define EMAC_MTL_DBG_CTL_PKTIE_SHIFT             (14U)
/*! PKTIE - Receive Packet Available Interrupt Status Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DBG_CTL_PKTIE(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_CTL_PKTIE_SHIFT)) & EMAC_MTL_DBG_CTL_PKTIE_MASK)

#define EMAC_MTL_DBG_CTL_STSIE_MASK              (0x8000U)
#define EMAC_MTL_DBG_CTL_STSIE_SHIFT             (15U)
/*! STSIE - Transmit Status Available Interrupt Status Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DBG_CTL_STSIE(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_CTL_STSIE_SHIFT)) & EMAC_MTL_DBG_CTL_STSIE_MASK)

#define EMAC_MTL_DBG_CTL_EIEE_MASK               (0x10000U)
#define EMAC_MTL_DBG_CTL_EIEE_SHIFT              (16U)
/*! EIEE - ECC Inject Error Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DBG_CTL_EIEE(x)                 (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_CTL_EIEE_SHIFT)) & EMAC_MTL_DBG_CTL_EIEE_MASK)

#define EMAC_MTL_DBG_CTL_EIEC_MASK               (0x60000U)
#define EMAC_MTL_DBG_CTL_EIEC_SHIFT              (17U)
/*! EIEC - ECC Inject Error Control
 *  0b00..1-bit error
 *  0b01..2-bit errors
 *  0b10..3-bit errors
 *  0b11..1-bit error in the address field
 */
#define EMAC_MTL_DBG_CTL_EIEC(x)                 (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_CTL_EIEC_SHIFT)) & EMAC_MTL_DBG_CTL_EIEC_MASK)
/*! @} */

/*! @name MTL_DBG_STS - MTL Debug Status */
/*! @{ */

#define EMAC_MTL_DBG_STS_FIFOBUSY_MASK           (0x1U)
#define EMAC_MTL_DBG_STS_FIFOBUSY_SHIFT          (0U)
/*! FIFOBUSY - FIFO Busy
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_DBG_STS_FIFOBUSY(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_STS_FIFOBUSY_SHIFT)) & EMAC_MTL_DBG_STS_FIFOBUSY_MASK)

#define EMAC_MTL_DBG_STS_PKTSTATE_MASK           (0x6U)
#define EMAC_MTL_DBG_STS_PKTSTATE_SHIFT          (1U)
/*! PKTSTATE - Encoded Packet State
 *  0b00..Packet data
 *  0b01..Control word/normal status
 *  0b10..SOP data/last status
 *  0b11..EOP data/EOP
 */
#define EMAC_MTL_DBG_STS_PKTSTATE(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_STS_PKTSTATE_SHIFT)) & EMAC_MTL_DBG_STS_PKTSTATE_MASK)

#define EMAC_MTL_DBG_STS_BYTEEN_MASK             (0x18U)
#define EMAC_MTL_DBG_STS_BYTEEN_SHIFT            (3U)
/*! BYTEEN - Byte Enables
 *  0b00..Byte 0 valid
 *  0b01..Byte 0 and byte 1 valid
 *  0b10..Byte 0, byte 1, and byte 2 valid
 *  0b11..All four bytes valid
 */
#define EMAC_MTL_DBG_STS_BYTEEN(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_STS_BYTEEN_SHIFT)) & EMAC_MTL_DBG_STS_BYTEEN_MASK)

#define EMAC_MTL_DBG_STS_PKTI_MASK               (0x100U)
#define EMAC_MTL_DBG_STS_PKTI_SHIFT              (8U)
/*! PKTI - Receive Packet Available Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_DBG_STS_PKTI(x)                 (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_STS_PKTI_SHIFT)) & EMAC_MTL_DBG_STS_PKTI_MASK)

#define EMAC_MTL_DBG_STS_STSI_MASK               (0x200U)
#define EMAC_MTL_DBG_STS_STSI_SHIFT              (9U)
/*! STSI - Transmit Status Available Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_DBG_STS_STSI(x)                 (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_STS_STSI_SHIFT)) & EMAC_MTL_DBG_STS_STSI_MASK)

#define EMAC_MTL_DBG_STS_LOCR_MASK               (0xFFFF8000U)
#define EMAC_MTL_DBG_STS_LOCR_SHIFT              (15U)
/*! LOCR - Remaining Locations In FIFO */
#define EMAC_MTL_DBG_STS_LOCR(x)                 (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DBG_STS_LOCR_SHIFT)) & EMAC_MTL_DBG_STS_LOCR_MASK)
/*! @} */

/*! @name MTL_FIFO_DEBUG_DATA - MTL FIFO Debug Data */
/*! @{ */

#define EMAC_MTL_FIFO_DEBUG_DATA_FDBGDATA_MASK   (0xFFFFFFFFU)
#define EMAC_MTL_FIFO_DEBUG_DATA_FDBGDATA_SHIFT  (0U)
/*! FDBGDATA - FIFO Debug Data */
#define EMAC_MTL_FIFO_DEBUG_DATA_FDBGDATA(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_FIFO_DEBUG_DATA_FDBGDATA_SHIFT)) & EMAC_MTL_FIFO_DEBUG_DATA_FDBGDATA_MASK)
/*! @} */

/*! @name MTL_INTERRUPT_STATUS - MTL Interrupt Status */
/*! @{ */

#define EMAC_MTL_INTERRUPT_STATUS_Q0IS_MASK      (0x1U)
#define EMAC_MTL_INTERRUPT_STATUS_Q0IS_SHIFT     (0U)
/*! Q0IS - Queue 0 Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_INTERRUPT_STATUS_Q0IS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_INTERRUPT_STATUS_Q0IS_SHIFT)) & EMAC_MTL_INTERRUPT_STATUS_Q0IS_MASK)

#define EMAC_MTL_INTERRUPT_STATUS_Q1IS_MASK      (0x2U)
#define EMAC_MTL_INTERRUPT_STATUS_Q1IS_SHIFT     (1U)
/*! Q1IS - Queue 1 Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_INTERRUPT_STATUS_Q1IS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_INTERRUPT_STATUS_Q1IS_SHIFT)) & EMAC_MTL_INTERRUPT_STATUS_Q1IS_MASK)

#define EMAC_MTL_INTERRUPT_STATUS_DBGIS_MASK     (0x20000U)
#define EMAC_MTL_INTERRUPT_STATUS_DBGIS_SHIFT    (17U)
/*! DBGIS - Debug Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_INTERRUPT_STATUS_DBGIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_INTERRUPT_STATUS_DBGIS_SHIFT)) & EMAC_MTL_INTERRUPT_STATUS_DBGIS_MASK)

#define EMAC_MTL_INTERRUPT_STATUS_ESTIS_MASK     (0x40000U)
#define EMAC_MTL_INTERRUPT_STATUS_ESTIS_SHIFT    (18U)
/*! ESTIS - EST (TAS- 802.1Qbv) Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_INTERRUPT_STATUS_ESTIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_INTERRUPT_STATUS_ESTIS_SHIFT)) & EMAC_MTL_INTERRUPT_STATUS_ESTIS_MASK)

#define EMAC_MTL_INTERRUPT_STATUS_MTLPIS_MASK    (0x800000U)
#define EMAC_MTL_INTERRUPT_STATUS_MTLPIS_SHIFT   (23U)
/*! MTLPIS - MTL Receive Parser Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_INTERRUPT_STATUS_MTLPIS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_INTERRUPT_STATUS_MTLPIS_SHIFT)) & EMAC_MTL_INTERRUPT_STATUS_MTLPIS_MASK)
/*! @} */

/*! @name MTL_RXQ_DMA_MAP0 - MTL Receive Queue DMA Map 0 */
/*! @{ */

#define EMAC_MTL_RXQ_DMA_MAP0_Q0MDMACH_MASK      (0x1U)
#define EMAC_MTL_RXQ_DMA_MAP0_Q0MDMACH_SHIFT     (0U)
/*! Q0MDMACH - Queue 0 Mapped to DMA Channel */
#define EMAC_MTL_RXQ_DMA_MAP0_Q0MDMACH(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ_DMA_MAP0_Q0MDMACH_SHIFT)) & EMAC_MTL_RXQ_DMA_MAP0_Q0MDMACH_MASK)

#define EMAC_MTL_RXQ_DMA_MAP0_Q0DDMACH_MASK      (0x10U)
#define EMAC_MTL_RXQ_DMA_MAP0_Q0DDMACH_SHIFT     (4U)
/*! Q0DDMACH - Queue 0 Enabled for DA-based DMA Channel Selection
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_MTL_RXQ_DMA_MAP0_Q0DDMACH(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ_DMA_MAP0_Q0DDMACH_SHIFT)) & EMAC_MTL_RXQ_DMA_MAP0_Q0DDMACH_MASK)

#define EMAC_MTL_RXQ_DMA_MAP0_Q1MDMACH_MASK      (0x100U)
#define EMAC_MTL_RXQ_DMA_MAP0_Q1MDMACH_SHIFT     (8U)
/*! Q1MDMACH - Queue 1 Mapped to DMA Channel */
#define EMAC_MTL_RXQ_DMA_MAP0_Q1MDMACH(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ_DMA_MAP0_Q1MDMACH_SHIFT)) & EMAC_MTL_RXQ_DMA_MAP0_Q1MDMACH_MASK)

#define EMAC_MTL_RXQ_DMA_MAP0_Q1DDMACH_MASK      (0x1000U)
#define EMAC_MTL_RXQ_DMA_MAP0_Q1DDMACH_SHIFT     (12U)
/*! Q1DDMACH - Queue 1 Enabled for DA-based DMA Channel Selection
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_RXQ_DMA_MAP0_Q1DDMACH(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ_DMA_MAP0_Q1DDMACH_SHIFT)) & EMAC_MTL_RXQ_DMA_MAP0_Q1DDMACH_MASK)
/*! @} */

/*! @name MTL_TBS_CTRL - MTL TBS Control */
/*! @{ */

#define EMAC_MTL_TBS_CTRL_ESTM_MASK              (0x1U)
#define EMAC_MTL_TBS_CTRL_ESTM_SHIFT             (0U)
/*! ESTM - EST offset Mode
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_TBS_CTRL_ESTM(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TBS_CTRL_ESTM_SHIFT)) & EMAC_MTL_TBS_CTRL_ESTM_MASK)

#define EMAC_MTL_TBS_CTRL_LEOV_MASK              (0x2U)
#define EMAC_MTL_TBS_CTRL_LEOV_SHIFT             (1U)
/*! LEOV - Launch Expiry Offset Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define EMAC_MTL_TBS_CTRL_LEOV(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TBS_CTRL_LEOV_SHIFT)) & EMAC_MTL_TBS_CTRL_LEOV_MASK)

#define EMAC_MTL_TBS_CTRL_LEGOS_MASK             (0x70U)
#define EMAC_MTL_TBS_CTRL_LEGOS_SHIFT            (4U)
/*! LEGOS - Launch Expiry GSN Offset */
#define EMAC_MTL_TBS_CTRL_LEGOS(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TBS_CTRL_LEGOS_SHIFT)) & EMAC_MTL_TBS_CTRL_LEGOS_MASK)

#define EMAC_MTL_TBS_CTRL_LEOS_MASK              (0xFFFFFF00U)
#define EMAC_MTL_TBS_CTRL_LEOS_SHIFT             (8U)
/*! LEOS - Launch Expiry Offset */
#define EMAC_MTL_TBS_CTRL_LEOS(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TBS_CTRL_LEOS_SHIFT)) & EMAC_MTL_TBS_CTRL_LEOS_MASK)
/*! @} */

/*! @name MTL_EST_CONTROL - MTL EST Control */
/*! @{ */

#define EMAC_MTL_EST_CONTROL_EEST_MASK           (0x1U)
#define EMAC_MTL_EST_CONTROL_EEST_SHIFT          (0U)
/*! EEST - Enable EST
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_EST_CONTROL_EEST(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_CONTROL_EEST_SHIFT)) & EMAC_MTL_EST_CONTROL_EEST_MASK)

#define EMAC_MTL_EST_CONTROL_SSWL_MASK           (0x2U)
#define EMAC_MTL_EST_CONTROL_SSWL_SHIFT          (1U)
/*! SSWL - Switch to Software Owned List
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_EST_CONTROL_SSWL(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_CONTROL_SSWL_SHIFT)) & EMAC_MTL_EST_CONTROL_SSWL_MASK)

#define EMAC_MTL_EST_CONTROL_DDBF_MASK           (0x10U)
#define EMAC_MTL_EST_CONTROL_DDBF_SHIFT          (4U)
/*! DDBF - Do not Drop Frames during Frame Size Error
 *  0b0..Drop frames during frame size error
 *  0b1..Do not Drop frames during frame size error
 */
#define EMAC_MTL_EST_CONTROL_DDBF(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_CONTROL_DDBF_SHIFT)) & EMAC_MTL_EST_CONTROL_DDBF_MASK)

#define EMAC_MTL_EST_CONTROL_DFBS_MASK           (0x20U)
#define EMAC_MTL_EST_CONTROL_DFBS_SHIFT          (5U)
/*! DFBS - Drop Frames Causing Scheduling Error
 *  0b0..Do not drop frames
 *  0b1..Drop frames
 */
#define EMAC_MTL_EST_CONTROL_DFBS(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_CONTROL_DFBS_SHIFT)) & EMAC_MTL_EST_CONTROL_DFBS_MASK)

#define EMAC_MTL_EST_CONTROL_LCSE_MASK           (0xC0U)
#define EMAC_MTL_EST_CONTROL_LCSE_SHIFT          (6U)
/*! LCSE - Loop Count to Report Scheduling Error
 *  0b00..4 iterations
 *  0b01..8 iterations
 *  0b10..16 iterations
 *  0b11..32 iterations
 */
#define EMAC_MTL_EST_CONTROL_LCSE(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_CONTROL_LCSE_SHIFT)) & EMAC_MTL_EST_CONTROL_LCSE_MASK)

#define EMAC_MTL_EST_CONTROL_TILS_MASK           (0x700U)
#define EMAC_MTL_EST_CONTROL_TILS_SHIFT          (8U)
/*! TILS - Time Interval Left Shift Amount */
#define EMAC_MTL_EST_CONTROL_TILS(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_CONTROL_TILS_SHIFT)) & EMAC_MTL_EST_CONTROL_TILS_MASK)

#define EMAC_MTL_EST_CONTROL_CTOV_MASK           (0xFFF000U)
#define EMAC_MTL_EST_CONTROL_CTOV_SHIFT          (12U)
/*! CTOV - Current Time Offset Value */
#define EMAC_MTL_EST_CONTROL_CTOV(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_CONTROL_CTOV_SHIFT)) & EMAC_MTL_EST_CONTROL_CTOV_MASK)

#define EMAC_MTL_EST_CONTROL_PTOV_MASK           (0xFF000000U)
#define EMAC_MTL_EST_CONTROL_PTOV_SHIFT          (24U)
/*! PTOV - PTP Time Offset Value */
#define EMAC_MTL_EST_CONTROL_PTOV(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_CONTROL_PTOV_SHIFT)) & EMAC_MTL_EST_CONTROL_PTOV_MASK)
/*! @} */

/*! @name MTL_EST_STATUS - MTL EST Status */
/*! @{ */

#define EMAC_MTL_EST_STATUS_SWLC_MASK            (0x1U)
#define EMAC_MTL_EST_STATUS_SWLC_SHIFT           (0U)
/*! SWLC - Switch to Software Owned List Complete
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_EST_STATUS_SWLC(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_STATUS_SWLC_SHIFT)) & EMAC_MTL_EST_STATUS_SWLC_MASK)

#define EMAC_MTL_EST_STATUS_BTRE_MASK            (0x2U)
#define EMAC_MTL_EST_STATUS_BTRE_SHIFT           (1U)
/*! BTRE - BTR Error
 *  0b0..BTR Error not detected
 *  0b1..BTR Error detected
 */
#define EMAC_MTL_EST_STATUS_BTRE(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_STATUS_BTRE_SHIFT)) & EMAC_MTL_EST_STATUS_BTRE_MASK)

#define EMAC_MTL_EST_STATUS_HLBF_MASK            (0x4U)
#define EMAC_MTL_EST_STATUS_HLBF_SHIFT           (2U)
/*! HLBF
 *  0b0..Head-Of-Line Blocking due to Frame Size not detected
 *  0b1..Head-Of-Line Blocking due to Frame Size detected
 */
#define EMAC_MTL_EST_STATUS_HLBF(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_STATUS_HLBF_SHIFT)) & EMAC_MTL_EST_STATUS_HLBF_MASK)

#define EMAC_MTL_EST_STATUS_HLBS_MASK            (0x8U)
#define EMAC_MTL_EST_STATUS_HLBS_SHIFT           (3U)
/*! HLBS
 *  0b0..Head-Of-Line Blocking due to Scheduling not detected
 *  0b1..Head-Of-Line Blocking due to Scheduling detected
 */
#define EMAC_MTL_EST_STATUS_HLBS(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_STATUS_HLBS_SHIFT)) & EMAC_MTL_EST_STATUS_HLBS_MASK)

#define EMAC_MTL_EST_STATUS_CGCE_MASK            (0x10U)
#define EMAC_MTL_EST_STATUS_CGCE_SHIFT           (4U)
/*! CGCE
 *  0b0..Constant Gate Control Error not detected
 *  0b1..Constant Gate Control Error detected
 */
#define EMAC_MTL_EST_STATUS_CGCE(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_STATUS_CGCE_SHIFT)) & EMAC_MTL_EST_STATUS_CGCE_MASK)

#define EMAC_MTL_EST_STATUS_SWOL_MASK            (0x80U)
#define EMAC_MTL_EST_STATUS_SWOL_SHIFT           (7U)
/*! SWOL
 *  0b0..Gate control list number "0" is owned by software
 *  0b1..Gate control list number "1" is owned by software
 */
#define EMAC_MTL_EST_STATUS_SWOL(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_STATUS_SWOL_SHIFT)) & EMAC_MTL_EST_STATUS_SWOL_MASK)

#define EMAC_MTL_EST_STATUS_BTRL_MASK            (0xF00U)
#define EMAC_MTL_EST_STATUS_BTRL_SHIFT           (8U)
#define EMAC_MTL_EST_STATUS_BTRL(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_STATUS_BTRL_SHIFT)) & EMAC_MTL_EST_STATUS_BTRL_MASK)

#define EMAC_MTL_EST_STATUS_CGSN_MASK            (0xF0000U)
#define EMAC_MTL_EST_STATUS_CGSN_SHIFT           (16U)
#define EMAC_MTL_EST_STATUS_CGSN(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_STATUS_CGSN_SHIFT)) & EMAC_MTL_EST_STATUS_CGSN_MASK)
/*! @} */

/*! @name MTL_EST_SCH_ERROR - MTL EST Scheduling Error */
/*! @{ */

#define EMAC_MTL_EST_SCH_ERROR_SEQN_MASK         (0x3U)
#define EMAC_MTL_EST_SCH_ERROR_SEQN_SHIFT        (0U)
/*! SEQN - Schedule Error Queue Number */
#define EMAC_MTL_EST_SCH_ERROR_SEQN(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_SCH_ERROR_SEQN_SHIFT)) & EMAC_MTL_EST_SCH_ERROR_SEQN_MASK)
/*! @} */

/*! @name MTL_EST_FRM_SIZE_ERROR - MTL EST Frame Size Error */
/*! @{ */

#define EMAC_MTL_EST_FRM_SIZE_ERROR_FEQN_MASK    (0x3U)
#define EMAC_MTL_EST_FRM_SIZE_ERROR_FEQN_SHIFT   (0U)
/*! FEQN - Frame Size Error Queue Number */
#define EMAC_MTL_EST_FRM_SIZE_ERROR_FEQN(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_FRM_SIZE_ERROR_FEQN_SHIFT)) & EMAC_MTL_EST_FRM_SIZE_ERROR_FEQN_MASK)
/*! @} */

/*! @name MTL_EST_FRM_SIZE_CAPTURE - MTL EST Frame Size Capture */
/*! @{ */

#define EMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFS_MASK  (0x7FFFU)
#define EMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFS_SHIFT (0U)
/*! HBFS - Frame Size of HLBF */
#define EMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFS(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFS_SHIFT)) & EMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFS_MASK)

#define EMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_MASK  (0x10000U)
#define EMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_SHIFT (16U)
/*! HBFQ - Queue Number of HLBF */
#define EMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFQ(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_SHIFT)) & EMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_MASK)
/*! @} */

/*! @name MTL_EST_INTR_ENABLE - MTL EST Interrupt Enable */
/*! @{ */

#define EMAC_MTL_EST_INTR_ENABLE_IECC_MASK       (0x1U)
#define EMAC_MTL_EST_INTR_ENABLE_IECC_SHIFT      (0U)
/*! IECC - Interrupt Enable for Switch List
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_EST_INTR_ENABLE_IECC(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_INTR_ENABLE_IECC_SHIFT)) & EMAC_MTL_EST_INTR_ENABLE_IECC_MASK)

#define EMAC_MTL_EST_INTR_ENABLE_IEBE_MASK       (0x2U)
#define EMAC_MTL_EST_INTR_ENABLE_IEBE_SHIFT      (1U)
/*! IEBE - Interrupt Enable for BTR Error
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_EST_INTR_ENABLE_IEBE(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_INTR_ENABLE_IEBE_SHIFT)) & EMAC_MTL_EST_INTR_ENABLE_IEBE_MASK)

#define EMAC_MTL_EST_INTR_ENABLE_IEHF_MASK       (0x4U)
#define EMAC_MTL_EST_INTR_ENABLE_IEHF_SHIFT      (2U)
/*! IEHF - Interrupt Enable for HLBF
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_EST_INTR_ENABLE_IEHF(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_INTR_ENABLE_IEHF_SHIFT)) & EMAC_MTL_EST_INTR_ENABLE_IEHF_MASK)

#define EMAC_MTL_EST_INTR_ENABLE_IEHS_MASK       (0x8U)
#define EMAC_MTL_EST_INTR_ENABLE_IEHS_SHIFT      (3U)
/*! IEHS - Interrupt Enable for HLBS
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_EST_INTR_ENABLE_IEHS(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_INTR_ENABLE_IEHS_SHIFT)) & EMAC_MTL_EST_INTR_ENABLE_IEHS_MASK)

#define EMAC_MTL_EST_INTR_ENABLE_CGCE_MASK       (0x10U)
#define EMAC_MTL_EST_INTR_ENABLE_CGCE_SHIFT      (4U)
/*! CGCE - Interrupt Enable for CGCE
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_EST_INTR_ENABLE_CGCE(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_INTR_ENABLE_CGCE_SHIFT)) & EMAC_MTL_EST_INTR_ENABLE_CGCE_MASK)
/*! @} */

/*! @name MTL_EST_GCL_CONTROL - MTL EST GCL Control */
/*! @{ */

#define EMAC_MTL_EST_GCL_CONTROL_SRWO_MASK       (0x1U)
#define EMAC_MTL_EST_GCL_CONTROL_SRWO_SHIFT      (0U)
/*! SRWO - Start Read/Write Operation
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_EST_GCL_CONTROL_SRWO(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_GCL_CONTROL_SRWO_SHIFT)) & EMAC_MTL_EST_GCL_CONTROL_SRWO_MASK)

#define EMAC_MTL_EST_GCL_CONTROL_R1W0_MASK       (0x2U)
#define EMAC_MTL_EST_GCL_CONTROL_R1W0_SHIFT      (1U)
/*! R1W0 - Read '1', Write '0'
 *  0b0..Write operation
 *  0b1..Read operation
 */
#define EMAC_MTL_EST_GCL_CONTROL_R1W0(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_GCL_CONTROL_R1W0_SHIFT)) & EMAC_MTL_EST_GCL_CONTROL_R1W0_MASK)

#define EMAC_MTL_EST_GCL_CONTROL_GCRR_MASK       (0x4U)
#define EMAC_MTL_EST_GCL_CONTROL_GCRR_SHIFT      (2U)
/*! GCRR - Gate Control Related Registers
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_EST_GCL_CONTROL_GCRR(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_GCL_CONTROL_GCRR_SHIFT)) & EMAC_MTL_EST_GCL_CONTROL_GCRR_MASK)

#define EMAC_MTL_EST_GCL_CONTROL_DBGM_MASK       (0x10U)
#define EMAC_MTL_EST_GCL_CONTROL_DBGM_SHIFT      (4U)
/*! DBGM - Debug Mode
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_EST_GCL_CONTROL_DBGM(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_GCL_CONTROL_DBGM_SHIFT)) & EMAC_MTL_EST_GCL_CONTROL_DBGM_MASK)

#define EMAC_MTL_EST_GCL_CONTROL_DBGB_MASK       (0x20U)
#define EMAC_MTL_EST_GCL_CONTROL_DBGB_SHIFT      (5U)
/*! DBGB - Debug Mode Bank Select
 *  0b0..Directed to bank 0
 *  0b1..Directed to bank 1
 */
#define EMAC_MTL_EST_GCL_CONTROL_DBGB(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_GCL_CONTROL_DBGB_SHIFT)) & EMAC_MTL_EST_GCL_CONTROL_DBGB_MASK)

#define EMAC_MTL_EST_GCL_CONTROL_ADDR_MASK       (0xFF00U)
#define EMAC_MTL_EST_GCL_CONTROL_ADDR_SHIFT      (8U)
#define EMAC_MTL_EST_GCL_CONTROL_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_GCL_CONTROL_ADDR_SHIFT)) & EMAC_MTL_EST_GCL_CONTROL_ADDR_MASK)

#define EMAC_MTL_EST_GCL_CONTROL_ERR0_MASK       (0x100000U)
#define EMAC_MTL_EST_GCL_CONTROL_ERR0_SHIFT      (20U)
/*! ERR0
 *  0b0..ERR0 is disabled
 *  0b1..ERR1 is enabled
 */
#define EMAC_MTL_EST_GCL_CONTROL_ERR0(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_GCL_CONTROL_ERR0_SHIFT)) & EMAC_MTL_EST_GCL_CONTROL_ERR0_MASK)

#define EMAC_MTL_EST_GCL_CONTROL_ESTEIEE_MASK    (0x200000U)
#define EMAC_MTL_EST_GCL_CONTROL_ESTEIEE_SHIFT   (21U)
/*! ESTEIEE - EST ECC Inject Error Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_EST_GCL_CONTROL_ESTEIEE(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_GCL_CONTROL_ESTEIEE_SHIFT)) & EMAC_MTL_EST_GCL_CONTROL_ESTEIEE_MASK)

#define EMAC_MTL_EST_GCL_CONTROL_ESTEIEC_MASK    (0xC00000U)
#define EMAC_MTL_EST_GCL_CONTROL_ESTEIEC_SHIFT   (22U)
/*! ESTEIEC - ECC Inject Error Control for EST Memory
 *  0b00..Insert 1 bit error
 *  0b01..Insert 2 bit errors
 *  0b10..Insert 3 bit errors
 *  0b11..Insert 1 bit error in address field
 */
#define EMAC_MTL_EST_GCL_CONTROL_ESTEIEC(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_GCL_CONTROL_ESTEIEC_SHIFT)) & EMAC_MTL_EST_GCL_CONTROL_ESTEIEC_MASK)
/*! @} */

/*! @name MTL_EST_GCL_DATA - MTL EST GCL Data */
/*! @{ */

#define EMAC_MTL_EST_GCL_DATA_GCD_MASK           (0xFFFFFFFFU)
#define EMAC_MTL_EST_GCL_DATA_GCD_SHIFT          (0U)
/*! GCD - Gate Control Data */
#define EMAC_MTL_EST_GCL_DATA_GCD(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_EST_GCL_DATA_GCD_SHIFT)) & EMAC_MTL_EST_GCL_DATA_GCD_MASK)
/*! @} */

/*! @name MTL_FPE_CTRL_STS - MTL FPE Control Status */
/*! @{ */

#define EMAC_MTL_FPE_CTRL_STS_AFSZ_MASK          (0x3U)
#define EMAC_MTL_FPE_CTRL_STS_AFSZ_SHIFT         (0U)
/*! AFSZ - Additional Fragment Size */
#define EMAC_MTL_FPE_CTRL_STS_AFSZ(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_FPE_CTRL_STS_AFSZ_SHIFT)) & EMAC_MTL_FPE_CTRL_STS_AFSZ_MASK)

#define EMAC_MTL_FPE_CTRL_STS_PEC_MASK           (0x300U)
#define EMAC_MTL_FPE_CTRL_STS_PEC_SHIFT          (8U)
/*! PEC - Preemption Classification */
#define EMAC_MTL_FPE_CTRL_STS_PEC(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_FPE_CTRL_STS_PEC_SHIFT)) & EMAC_MTL_FPE_CTRL_STS_PEC_MASK)

#define EMAC_MTL_FPE_CTRL_STS_HRS_MASK           (0x10000000U)
#define EMAC_MTL_FPE_CTRL_STS_HRS_SHIFT          (28U)
/*! HRS - Hold/Release Status
 *  0b0..Release state
 *  0b1..Hold state
 */
#define EMAC_MTL_FPE_CTRL_STS_HRS(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_FPE_CTRL_STS_HRS_SHIFT)) & EMAC_MTL_FPE_CTRL_STS_HRS_MASK)
/*! @} */

/*! @name MTL_FPE_ADVANCE - MTL FPE Advance */
/*! @{ */

#define EMAC_MTL_FPE_ADVANCE_HADV_MASK           (0xFFFFU)
#define EMAC_MTL_FPE_ADVANCE_HADV_SHIFT          (0U)
/*! HADV - Hold Advance */
#define EMAC_MTL_FPE_ADVANCE_HADV(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_FPE_ADVANCE_HADV_SHIFT)) & EMAC_MTL_FPE_ADVANCE_HADV_MASK)

#define EMAC_MTL_FPE_ADVANCE_RADV_MASK           (0xFFFF0000U)
#define EMAC_MTL_FPE_ADVANCE_RADV_SHIFT          (16U)
/*! RADV - Release Advance */
#define EMAC_MTL_FPE_ADVANCE_RADV(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_FPE_ADVANCE_RADV_SHIFT)) & EMAC_MTL_FPE_ADVANCE_RADV_MASK)
/*! @} */

/*! @name MTL_RXP_CONTROL_STATUS - MTL Rx Parser Control Status */
/*! @{ */

#define EMAC_MTL_RXP_CONTROL_STATUS_NVE_MASK     (0x3FU)
#define EMAC_MTL_RXP_CONTROL_STATUS_NVE_SHIFT    (0U)
/*! NVE - Number Of Valid Entry Address Or Index In The Instruction Table */
#define EMAC_MTL_RXP_CONTROL_STATUS_NVE(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_CONTROL_STATUS_NVE_SHIFT)) & EMAC_MTL_RXP_CONTROL_STATUS_NVE_MASK)

#define EMAC_MTL_RXP_CONTROL_STATUS_MTL_SCS1_MASK (0x8000U)
#define EMAC_MTL_RXP_CONTROL_STATUS_MTL_SCS1_SHIFT (15U)
/*! MTL_SCS1 - MTL_SCS1 */
#define EMAC_MTL_RXP_CONTROL_STATUS_MTL_SCS1(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_CONTROL_STATUS_MTL_SCS1_SHIFT)) & EMAC_MTL_RXP_CONTROL_STATUS_MTL_SCS1_MASK)

#define EMAC_MTL_RXP_CONTROL_STATUS_NPE_MASK     (0x3F0000U)
#define EMAC_MTL_RXP_CONTROL_STATUS_NPE_SHIFT    (16U)
/*! NPE - Number of parsable entries in the Instruction table */
#define EMAC_MTL_RXP_CONTROL_STATUS_NPE(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_CONTROL_STATUS_NPE_SHIFT)) & EMAC_MTL_RXP_CONTROL_STATUS_NPE_MASK)

#define EMAC_MTL_RXP_CONTROL_STATUS_RXPI_MASK    (0x80000000U)
#define EMAC_MTL_RXP_CONTROL_STATUS_RXPI_SHIFT   (31U)
/*! RXPI - RX Parser in Idle State
 *  0b0..Not in Idle state
 *  0b1..Idle state
 */
#define EMAC_MTL_RXP_CONTROL_STATUS_RXPI(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_CONTROL_STATUS_RXPI_SHIFT)) & EMAC_MTL_RXP_CONTROL_STATUS_RXPI_MASK)
/*! @} */

/*! @name MTL_RXP_INTERRUPT_CONTROL_STATUS - MTL Rx Parser Interrupt Control Status */
/*! @{ */

#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS_MASK (0x1U)
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS_SHIFT (0U)
/*! NVEOVIS - Number of Valid Entry Address/Index Overflow Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS_SHIFT)) & EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS_MASK)

#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS_MASK (0x2U)
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS_SHIFT (1U)
/*! NPEOVIS - Number of Parsable Entries Overflow Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS_SHIFT)) & EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS_MASK)

#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS_MASK (0x4U)
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS_SHIFT (2U)
/*! FOOVIS - Frame Offset Overflow Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS_SHIFT)) & EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS_MASK)

#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS_MASK (0x8U)
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS_SHIFT (3U)
/*! PDRFIS - Packet Dropped due to RF Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS_SHIFT)) & EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS_MASK)

#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE_MASK (0x10000U)
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE_SHIFT (16U)
/*! NVEOVIE - Number of Valid Entries Overflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE_SHIFT)) & EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE_MASK)

#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE_MASK (0x20000U)
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE_SHIFT (17U)
/*! NPEOVIE - Number of Parsable Entries Overflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE_SHIFT)) & EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE_MASK)

#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE_MASK (0x40000U)
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE_SHIFT (18U)
/*! FOOVIE - Frame Offset Overflow Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE_SHIFT)) & EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE_MASK)

#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE_MASK (0x80000U)
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE_SHIFT (19U)
/*! PDRFIE - Packet Drop due to RF Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE_SHIFT)) & EMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE_MASK)
/*! @} */

/*! @name MTL_RXP_DROP_CNT - MTL Rx Parser Drop Count */
/*! @{ */

#define EMAC_MTL_RXP_DROP_CNT_RXPDC_MASK         (0x7FFFFFFFU)
#define EMAC_MTL_RXP_DROP_CNT_RXPDC_SHIFT        (0U)
/*! RXPDC - Rx Parser Drop Count */
#define EMAC_MTL_RXP_DROP_CNT_RXPDC(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_DROP_CNT_RXPDC_SHIFT)) & EMAC_MTL_RXP_DROP_CNT_RXPDC_MASK)

#define EMAC_MTL_RXP_DROP_CNT_RXPDCOVF_MASK      (0x80000000U)
#define EMAC_MTL_RXP_DROP_CNT_RXPDCOVF_SHIFT     (31U)
/*! RXPDCOVF - Rx Parser Drop Counter Overflow Bit
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define EMAC_MTL_RXP_DROP_CNT_RXPDCOVF(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_DROP_CNT_RXPDCOVF_SHIFT)) & EMAC_MTL_RXP_DROP_CNT_RXPDCOVF_MASK)
/*! @} */

/*! @name MTL_RXP_ERROR_CNT - MTL Rx Parser Error Count */
/*! @{ */

#define EMAC_MTL_RXP_ERROR_CNT_RXPEC_MASK        (0x7FFFFFFFU)
#define EMAC_MTL_RXP_ERROR_CNT_RXPEC_SHIFT       (0U)
/*! RXPEC - Rx Parser Error Count */
#define EMAC_MTL_RXP_ERROR_CNT_RXPEC(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_ERROR_CNT_RXPEC_SHIFT)) & EMAC_MTL_RXP_ERROR_CNT_RXPEC_MASK)

#define EMAC_MTL_RXP_ERROR_CNT_RXPECOVF_MASK     (0x80000000U)
#define EMAC_MTL_RXP_ERROR_CNT_RXPECOVF_SHIFT    (31U)
/*! RXPECOVF - Rx Parser Error Counter Overflow Bit
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define EMAC_MTL_RXP_ERROR_CNT_RXPECOVF(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_ERROR_CNT_RXPECOVF_SHIFT)) & EMAC_MTL_RXP_ERROR_CNT_RXPECOVF_MASK)
/*! @} */

/*! @name MTL_RXP_INDIRECT_ACC_CONTROL_STATUS - MTL Rx Parser Indirect Access Control Status */
/*! @{ */

#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR_MASK (0xFFU)
#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR_SHIFT (0U)
/*! ADDR - FRP Instruction Table Offset Address */
#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR_SHIFT)) & EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR_MASK)

#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN_MASK (0x10000U)
#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN_SHIFT (16U)
/*! WRRDN - Read Write Control
 *  0b0..Read operation to the receive parser memory
 *  0b1..Write operation to the receive parser memory
 */
#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN_SHIFT)) & EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN_MASK)

#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE_MASK (0x100000U)
#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE_SHIFT (20U)
/*! RXPEIEE - ECC Inject Error Enable for Rx Parser Memory
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE_SHIFT)) & EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE_MASK)

#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC_MASK (0x600000U)
#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC_SHIFT (21U)
/*! RXPEIEC - ECC Inject Error Control for Rx Parser Memory
 *  0b00..Insert 1 bit error
 *  0b01..Insert 2 bit errors
 *  0b10..Insert 3 bit errors
 *  0b11..Insert 1 bit error in address field
 */
#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC_SHIFT)) & EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC_MASK)

#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY_MASK (0x80000000U)
#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY_SHIFT (31U)
/*! STARTBUSY - FRP Instruction Table Access Busy
 *  0b0..hardware not busy
 *  0b1..hardware is busy (Read/Write operation from/to the Rx Parser Memory)
 */
#define EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY_SHIFT)) & EMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY_MASK)
/*! @} */

/*! @name MTL_RXP_INDIRECT_ACC_DATA - MTL Rx Parser Indirect Access Data */
/*! @{ */

#define EMAC_MTL_RXP_INDIRECT_ACC_DATA_DATA_MASK (0xFFFFFFFFU)
#define EMAC_MTL_RXP_INDIRECT_ACC_DATA_DATA_SHIFT (0U)
/*! DATA - FRP Instruction Table Write/Read Data */
#define EMAC_MTL_RXP_INDIRECT_ACC_DATA_DATA(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXP_INDIRECT_ACC_DATA_DATA_SHIFT)) & EMAC_MTL_RXP_INDIRECT_ACC_DATA_DATA_MASK)
/*! @} */

/*! @name MTL_ECC_CONTROL - MTL ECC Control */
/*! @{ */

#define EMAC_MTL_ECC_CONTROL_MTXEE_MASK          (0x1U)
#define EMAC_MTL_ECC_CONTROL_MTXEE_SHIFT         (0U)
/*! MTXEE - MTL Tx FIFO ECC Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_ECC_CONTROL_MTXEE(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_CONTROL_MTXEE_SHIFT)) & EMAC_MTL_ECC_CONTROL_MTXEE_MASK)

#define EMAC_MTL_ECC_CONTROL_MRXEE_MASK          (0x2U)
#define EMAC_MTL_ECC_CONTROL_MRXEE_SHIFT         (1U)
/*! MRXEE - MTL Rx FIFO ECC Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_ECC_CONTROL_MRXEE(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_CONTROL_MRXEE_SHIFT)) & EMAC_MTL_ECC_CONTROL_MRXEE_MASK)

#define EMAC_MTL_ECC_CONTROL_MESTEE_MASK         (0x4U)
#define EMAC_MTL_ECC_CONTROL_MESTEE_SHIFT        (2U)
/*! MESTEE - MTL EST ECC Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_ECC_CONTROL_MESTEE(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_CONTROL_MESTEE_SHIFT)) & EMAC_MTL_ECC_CONTROL_MESTEE_MASK)

#define EMAC_MTL_ECC_CONTROL_MRXPEE_MASK         (0x8U)
#define EMAC_MTL_ECC_CONTROL_MRXPEE_SHIFT        (3U)
/*! MRXPEE - MTL Rx Parser ECC Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_ECC_CONTROL_MRXPEE(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_CONTROL_MRXPEE_SHIFT)) & EMAC_MTL_ECC_CONTROL_MRXPEE_MASK)

#define EMAC_MTL_ECC_CONTROL_MEEAO_MASK          (0x100U)
#define EMAC_MTL_ECC_CONTROL_MEEAO_SHIFT         (8U)
/*! MEEAO - MTL ECC Error Address Status Over-ride
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_MTL_ECC_CONTROL_MEEAO(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_CONTROL_MEEAO_SHIFT)) & EMAC_MTL_ECC_CONTROL_MEEAO_MASK)
/*! @} */

/*! @name MTL_SAFETY_INTERRUPT_STATUS - MTL Safety Interript Status */
/*! @{ */

#define EMAC_MTL_SAFETY_INTERRUPT_STATUS_MECIS_MASK (0x1U)
#define EMAC_MTL_SAFETY_INTERRUPT_STATUS_MECIS_SHIFT (0U)
/*! MECIS - MTL ECC Correctable Error Interrupt Status
 *  0b0..MTL ECC Correctable error Interrupt Status not detected
 *  0b1..MTL ECC Correctable error Interrupt Status detected
 */
#define EMAC_MTL_SAFETY_INTERRUPT_STATUS_MECIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_SAFETY_INTERRUPT_STATUS_MECIS_SHIFT)) & EMAC_MTL_SAFETY_INTERRUPT_STATUS_MECIS_MASK)

#define EMAC_MTL_SAFETY_INTERRUPT_STATUS_MEUIS_MASK (0x2U)
#define EMAC_MTL_SAFETY_INTERRUPT_STATUS_MEUIS_SHIFT (1U)
/*! MEUIS - MTL ECC Uncorrectable Error Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_SAFETY_INTERRUPT_STATUS_MEUIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_SAFETY_INTERRUPT_STATUS_MEUIS_SHIFT)) & EMAC_MTL_SAFETY_INTERRUPT_STATUS_MEUIS_MASK)
/*! @} */

/*! @name MTL_ECC_INTERRUPT_ENABLE - MTL ECC Interrupt Enable */
/*! @{ */

#define EMAC_MTL_ECC_INTERRUPT_ENABLE_TXCEIE_MASK (0x1U)
#define EMAC_MTL_ECC_INTERRUPT_ENABLE_TXCEIE_SHIFT (0U)
/*! TXCEIE - Tx Memory Correctable Error Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_ECC_INTERRUPT_ENABLE_TXCEIE(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_ENABLE_TXCEIE_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_ENABLE_TXCEIE_MASK)

#define EMAC_MTL_ECC_INTERRUPT_ENABLE_RXCEIE_MASK (0x10U)
#define EMAC_MTL_ECC_INTERRUPT_ENABLE_RXCEIE_SHIFT (4U)
/*! RXCEIE - Rx Memory Correctable Error Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_ECC_INTERRUPT_ENABLE_RXCEIE(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_ENABLE_RXCEIE_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_ENABLE_RXCEIE_MASK)

#define EMAC_MTL_ECC_INTERRUPT_ENABLE_ECEIE_MASK (0x100U)
#define EMAC_MTL_ECC_INTERRUPT_ENABLE_ECEIE_SHIFT (8U)
/*! ECEIE - EST Memory Correctable Error Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_ECC_INTERRUPT_ENABLE_ECEIE(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_ENABLE_ECEIE_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_ENABLE_ECEIE_MASK)

#define EMAC_MTL_ECC_INTERRUPT_ENABLE_RPCEIE_MASK (0x1000U)
#define EMAC_MTL_ECC_INTERRUPT_ENABLE_RPCEIE_SHIFT (12U)
/*! RPCEIE - Rx Parser Memory Correctable Error Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_ECC_INTERRUPT_ENABLE_RPCEIE(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_ENABLE_RPCEIE_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_ENABLE_RPCEIE_MASK)
/*! @} */

/*! @name MTL_ECC_INTERRUPT_STATUS - MTL ECC Interrupt Status */
/*! @{ */

#define EMAC_MTL_ECC_INTERRUPT_STATUS_TXCES_MASK (0x1U)
#define EMAC_MTL_ECC_INTERRUPT_STATUS_TXCES_SHIFT (0U)
/*! TXCES - MTL Tx Memory Correctable Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_ECC_INTERRUPT_STATUS_TXCES(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_STATUS_TXCES_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_STATUS_TXCES_MASK)

#define EMAC_MTL_ECC_INTERRUPT_STATUS_TXAMS_MASK (0x2U)
#define EMAC_MTL_ECC_INTERRUPT_STATUS_TXAMS_SHIFT (1U)
/*! TXAMS - MTL Tx Memory Address Mismatch Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_ECC_INTERRUPT_STATUS_TXAMS(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_STATUS_TXAMS_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_STATUS_TXAMS_MASK)

#define EMAC_MTL_ECC_INTERRUPT_STATUS_TXUES_MASK (0x4U)
#define EMAC_MTL_ECC_INTERRUPT_STATUS_TXUES_SHIFT (2U)
/*! TXUES - MTL Tx Memory Uncorrectable Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_ECC_INTERRUPT_STATUS_TXUES(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_STATUS_TXUES_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_STATUS_TXUES_MASK)

#define EMAC_MTL_ECC_INTERRUPT_STATUS_RXCES_MASK (0x10U)
#define EMAC_MTL_ECC_INTERRUPT_STATUS_RXCES_SHIFT (4U)
/*! RXCES - MTL Rx memory Correctable Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_ECC_INTERRUPT_STATUS_RXCES(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_STATUS_RXCES_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_STATUS_RXCES_MASK)

#define EMAC_MTL_ECC_INTERRUPT_STATUS_RXAMS_MASK (0x20U)
#define EMAC_MTL_ECC_INTERRUPT_STATUS_RXAMS_SHIFT (5U)
/*! RXAMS - MTL Rx Memory Address Mismatch Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_ECC_INTERRUPT_STATUS_RXAMS(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_STATUS_RXAMS_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_STATUS_RXAMS_MASK)

#define EMAC_MTL_ECC_INTERRUPT_STATUS_RXUES_MASK (0x40U)
#define EMAC_MTL_ECC_INTERRUPT_STATUS_RXUES_SHIFT (6U)
/*! RXUES - MTL Rx Memory Uncorrectable Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_ECC_INTERRUPT_STATUS_RXUES(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_STATUS_RXUES_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_STATUS_RXUES_MASK)

#define EMAC_MTL_ECC_INTERRUPT_STATUS_ECES_MASK  (0x100U)
#define EMAC_MTL_ECC_INTERRUPT_STATUS_ECES_SHIFT (8U)
/*! ECES - MTL EST Memory Correctable Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_ECC_INTERRUPT_STATUS_ECES(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_STATUS_ECES_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_STATUS_ECES_MASK)

#define EMAC_MTL_ECC_INTERRUPT_STATUS_EAMS_MASK  (0x200U)
#define EMAC_MTL_ECC_INTERRUPT_STATUS_EAMS_SHIFT (9U)
/*! EAMS - MTL EST Memory Address Mismatch Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_ECC_INTERRUPT_STATUS_EAMS(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_STATUS_EAMS_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_STATUS_EAMS_MASK)

#define EMAC_MTL_ECC_INTERRUPT_STATUS_EUES_MASK  (0x400U)
#define EMAC_MTL_ECC_INTERRUPT_STATUS_EUES_SHIFT (10U)
/*! EUES - MTL EST Memory Uncorrectable Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_ECC_INTERRUPT_STATUS_EUES(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_STATUS_EUES_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_STATUS_EUES_MASK)

#define EMAC_MTL_ECC_INTERRUPT_STATUS_RPCES_MASK (0x1000U)
#define EMAC_MTL_ECC_INTERRUPT_STATUS_RPCES_SHIFT (12U)
/*! RPCES - MTL Rx Parser Memory Correctable Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_ECC_INTERRUPT_STATUS_RPCES(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_STATUS_RPCES_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_STATUS_RPCES_MASK)

#define EMAC_MTL_ECC_INTERRUPT_STATUS_RPAMS_MASK (0x2000U)
#define EMAC_MTL_ECC_INTERRUPT_STATUS_RPAMS_SHIFT (13U)
/*! RPAMS - MTL Rx Parser Memory Address Mismatch Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_ECC_INTERRUPT_STATUS_RPAMS(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_STATUS_RPAMS_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_STATUS_RPAMS_MASK)

#define EMAC_MTL_ECC_INTERRUPT_STATUS_RPUES_MASK (0x4000U)
#define EMAC_MTL_ECC_INTERRUPT_STATUS_RPUES_SHIFT (14U)
/*! RPUES - Rx Parser Memory Uncorrectable Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_ECC_INTERRUPT_STATUS_RPUES(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_INTERRUPT_STATUS_RPUES_SHIFT)) & EMAC_MTL_ECC_INTERRUPT_STATUS_RPUES_MASK)
/*! @} */

/*! @name MTL_ECC_ERR_STS_RCTL - MTL ECC Error Status */
/*! @{ */

#define EMAC_MTL_ECC_ERR_STS_RCTL_EESRE_MASK     (0x1U)
#define EMAC_MTL_ECC_ERR_STS_RCTL_EESRE_SHIFT    (0U)
/*! EESRE - MTL ECC Error Status Read Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_ECC_ERR_STS_RCTL_EESRE(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_ERR_STS_RCTL_EESRE_SHIFT)) & EMAC_MTL_ECC_ERR_STS_RCTL_EESRE_MASK)

#define EMAC_MTL_ECC_ERR_STS_RCTL_EMS_MASK       (0xEU)
#define EMAC_MTL_ECC_ERR_STS_RCTL_EMS_SHIFT      (1U)
/*! EMS - MTL ECC Memory Selection
 *  0b000..MTL Tx memory
 *  0b001..MTL Rx memory
 *  0b010..MTL EST memory
 *  0b011..MTL Rx Parser memory
 *  0b100..DMA TSO memory
 */
#define EMAC_MTL_ECC_ERR_STS_RCTL_EMS(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_ERR_STS_RCTL_EMS_SHIFT)) & EMAC_MTL_ECC_ERR_STS_RCTL_EMS_MASK)

#define EMAC_MTL_ECC_ERR_STS_RCTL_CCES_MASK      (0x10U)
#define EMAC_MTL_ECC_ERR_STS_RCTL_CCES_SHIFT     (4U)
/*! CCES - Clear Correctable Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_ECC_ERR_STS_RCTL_CCES(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_ERR_STS_RCTL_CCES_SHIFT)) & EMAC_MTL_ECC_ERR_STS_RCTL_CCES_MASK)

#define EMAC_MTL_ECC_ERR_STS_RCTL_CUES_MASK      (0x20U)
#define EMAC_MTL_ECC_ERR_STS_RCTL_CUES_SHIFT     (5U)
/*! CUES - Clear Uncorrectable Error Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_ECC_ERR_STS_RCTL_CUES(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_ERR_STS_RCTL_CUES_SHIFT)) & EMAC_MTL_ECC_ERR_STS_RCTL_CUES_MASK)
/*! @} */

/*! @name MTL_ECC_ERR_ADDR_STATUS - MTL ECC Error Adress Status */
/*! @{ */

#define EMAC_MTL_ECC_ERR_ADDR_STATUS_ECEAS_MASK  (0xFFFFU)
#define EMAC_MTL_ECC_ERR_ADDR_STATUS_ECEAS_SHIFT (0U)
/*! ECEAS - MTL ECC Correctable Error Address Status */
#define EMAC_MTL_ECC_ERR_ADDR_STATUS_ECEAS(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_ERR_ADDR_STATUS_ECEAS_SHIFT)) & EMAC_MTL_ECC_ERR_ADDR_STATUS_ECEAS_MASK)

#define EMAC_MTL_ECC_ERR_ADDR_STATUS_EUEAS_MASK  (0xFFFF0000U)
#define EMAC_MTL_ECC_ERR_ADDR_STATUS_EUEAS_SHIFT (16U)
/*! EUEAS - MTL ECC Uncorrectable Error Address Status */
#define EMAC_MTL_ECC_ERR_ADDR_STATUS_EUEAS(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_ERR_ADDR_STATUS_EUEAS_SHIFT)) & EMAC_MTL_ECC_ERR_ADDR_STATUS_EUEAS_MASK)
/*! @} */

/*! @name MTL_ECC_ERR_CNTR_STATUS - MTL ECC Error Control Status */
/*! @{ */

#define EMAC_MTL_ECC_ERR_CNTR_STATUS_ECECS_MASK  (0xFFU)
#define EMAC_MTL_ECC_ERR_CNTR_STATUS_ECECS_SHIFT (0U)
#define EMAC_MTL_ECC_ERR_CNTR_STATUS_ECECS(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_ERR_CNTR_STATUS_ECECS_SHIFT)) & EMAC_MTL_ECC_ERR_CNTR_STATUS_ECECS_MASK)

#define EMAC_MTL_ECC_ERR_CNTR_STATUS_EUECS_MASK  (0xF0000U)
#define EMAC_MTL_ECC_ERR_CNTR_STATUS_EUECS_SHIFT (16U)
#define EMAC_MTL_ECC_ERR_CNTR_STATUS_EUECS(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_ECC_ERR_CNTR_STATUS_EUECS_SHIFT)) & EMAC_MTL_ECC_ERR_CNTR_STATUS_EUECS_MASK)
/*! @} */

/*! @name MTL_DPP_CONTROL - MTL DPP Control */
/*! @{ */

#define EMAC_MTL_DPP_CONTROL_EDPP_MASK           (0x1U)
#define EMAC_MTL_DPP_CONTROL_EDPP_SHIFT          (0U)
/*! EDPP - Enable Data path Parity Protection
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_MTL_DPP_CONTROL_EDPP(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DPP_CONTROL_EDPP_SHIFT)) & EMAC_MTL_DPP_CONTROL_EDPP_MASK)

#define EMAC_MTL_DPP_CONTROL_OPE_MASK            (0x2U)
#define EMAC_MTL_DPP_CONTROL_OPE_SHIFT           (1U)
/*! OPE - Odd Parity Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DPP_CONTROL_OPE(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DPP_CONTROL_OPE_SHIFT)) & EMAC_MTL_DPP_CONTROL_OPE_MASK)

#define EMAC_MTL_DPP_CONTROL_IPEID_MASK          (0x10U)
#define EMAC_MTL_DPP_CONTROL_IPEID_SHIFT         (4U)
/*! IPEID - Insert Parity Error in Interface Data Parity Generator
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DPP_CONTROL_IPEID(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DPP_CONTROL_IPEID_SHIFT)) & EMAC_MTL_DPP_CONTROL_IPEID_MASK)

#define EMAC_MTL_DPP_CONTROL_IPEMC_MASK          (0x20U)
#define EMAC_MTL_DPP_CONTROL_IPEMC_SHIFT         (5U)
/*! IPEMC - Insert Parity Error in MTL Checksum Parity Generator
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DPP_CONTROL_IPEMC(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DPP_CONTROL_IPEMC_SHIFT)) & EMAC_MTL_DPP_CONTROL_IPEMC_MASK)

#define EMAC_MTL_DPP_CONTROL_IPEMTS_MASK         (0x40U)
#define EMAC_MTL_DPP_CONTROL_IPEMTS_SHIFT        (6U)
/*! IPEMTS - Insert Parity Error in MTL Tx Status Parity Generator
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DPP_CONTROL_IPEMTS(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DPP_CONTROL_IPEMTS_SHIFT)) & EMAC_MTL_DPP_CONTROL_IPEMTS_MASK)

#define EMAC_MTL_DPP_CONTROL_IPEMRF_MASK         (0x80U)
#define EMAC_MTL_DPP_CONTROL_IPEMRF_SHIFT        (7U)
/*! IPEMRF - Insert Parity Error in MTL Rx FIFO Read Control Parity Generator
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DPP_CONTROL_IPEMRF(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DPP_CONTROL_IPEMRF_SHIFT)) & EMAC_MTL_DPP_CONTROL_IPEMRF_MASK)

#define EMAC_MTL_DPP_CONTROL_IPEDDC_MASK         (0x100U)
#define EMAC_MTL_DPP_CONTROL_IPEDDC_SHIFT        (8U)
/*! IPEDDC - Insert Parity Error in DMA DTX Control Word Parity Generator
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DPP_CONTROL_IPEDDC(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DPP_CONTROL_IPEDDC_SHIFT)) & EMAC_MTL_DPP_CONTROL_IPEDDC_MASK)

#define EMAC_MTL_DPP_CONTROL_IPETD_MASK          (0x400U)
#define EMAC_MTL_DPP_CONTROL_IPETD_SHIFT         (10U)
/*! IPETD - Insert Parity error in Tx write-back Descriptor parity generator
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DPP_CONTROL_IPETD(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DPP_CONTROL_IPETD_SHIFT)) & EMAC_MTL_DPP_CONTROL_IPETD_MASK)

#define EMAC_MTL_DPP_CONTROL_IPERD_MASK          (0x800U)
#define EMAC_MTL_DPP_CONTROL_IPERD_SHIFT         (11U)
/*! IPERD - Insert Parity error in Rx write-back Descriptor parity generator
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_DPP_CONTROL_IPERD(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_DPP_CONTROL_IPERD_SHIFT)) & EMAC_MTL_DPP_CONTROL_IPERD_MASK)
/*! @} */

/*! @name MTL_TXQ0_OPERATION_MODE - MTL Tx Queue 0 Operation Mode */
/*! @{ */

#define EMAC_MTL_TXQ0_OPERATION_MODE_FTQ_MASK    (0x1U)
#define EMAC_MTL_TXQ0_OPERATION_MODE_FTQ_SHIFT   (0U)
/*! FTQ - Flush Transmit Queue
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_TXQ0_OPERATION_MODE_FTQ(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_OPERATION_MODE_FTQ_SHIFT)) & EMAC_MTL_TXQ0_OPERATION_MODE_FTQ_MASK)

#define EMAC_MTL_TXQ0_OPERATION_MODE_TSF_MASK    (0x2U)
#define EMAC_MTL_TXQ0_OPERATION_MODE_TSF_SHIFT   (1U)
/*! TSF - Transmit Store and Forward
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_TXQ0_OPERATION_MODE_TSF(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_OPERATION_MODE_TSF_SHIFT)) & EMAC_MTL_TXQ0_OPERATION_MODE_TSF_MASK)

#define EMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_MASK  (0xCU)
#define EMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_SHIFT (2U)
/*! TXQEN - Transmit Queue Enable
 *  0b00..Not enabled
 *  0b01..Enable in AV mode (Reserved in non-AV)
 *  0b10..Enabled
 *  0b11..Reserved
 */
#define EMAC_MTL_TXQ0_OPERATION_MODE_TXQEN(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_SHIFT)) & EMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_MASK)

#define EMAC_MTL_TXQ0_OPERATION_MODE_TTC_MASK    (0x70U)
#define EMAC_MTL_TXQ0_OPERATION_MODE_TTC_SHIFT   (4U)
/*! TTC - Transmit Threshold Control
 *  0b000..32
 *  0b001..64
 *  0b010..96
 *  0b011..128
 *  0b100..192
 *  0b101..256
 *  0b110..384
 *  0b111..512
 */
#define EMAC_MTL_TXQ0_OPERATION_MODE_TTC(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_OPERATION_MODE_TTC_SHIFT)) & EMAC_MTL_TXQ0_OPERATION_MODE_TTC_MASK)

#define EMAC_MTL_TXQ0_OPERATION_MODE_TQS_MASK    (0x1F0000U)
#define EMAC_MTL_TXQ0_OPERATION_MODE_TQS_SHIFT   (16U)
/*! TQS - Transmit Queue Size */
#define EMAC_MTL_TXQ0_OPERATION_MODE_TQS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_OPERATION_MODE_TQS_SHIFT)) & EMAC_MTL_TXQ0_OPERATION_MODE_TQS_MASK)
/*! @} */

/*! @name MTL_TXQ0_UNDERFLOW - MTL Tx Queue 0 Underflow */
/*! @{ */

#define EMAC_MTL_TXQ0_UNDERFLOW_UFFRMCNT_MASK    (0x7FFU)
#define EMAC_MTL_TXQ0_UNDERFLOW_UFFRMCNT_SHIFT   (0U)
/*! UFFRMCNT - Underflow Packet Counter */
#define EMAC_MTL_TXQ0_UNDERFLOW_UFFRMCNT(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_UNDERFLOW_UFFRMCNT_SHIFT)) & EMAC_MTL_TXQ0_UNDERFLOW_UFFRMCNT_MASK)

#define EMAC_MTL_TXQ0_UNDERFLOW_UFCNTOVF_MASK    (0x800U)
#define EMAC_MTL_TXQ0_UNDERFLOW_UFCNTOVF_SHIFT   (11U)
/*! UFCNTOVF - Overflow Bit for Underflow Packet Counter
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_TXQ0_UNDERFLOW_UFCNTOVF(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_UNDERFLOW_UFCNTOVF_SHIFT)) & EMAC_MTL_TXQ0_UNDERFLOW_UFCNTOVF_MASK)
/*! @} */

/*! @name MTL_TXQ0_DEBUG - MTL Tx Queue 0 Debug */
/*! @{ */

#define EMAC_MTL_TXQ0_DEBUG_TXQPAUSED_MASK       (0x1U)
#define EMAC_MTL_TXQ0_DEBUG_TXQPAUSED_SHIFT      (0U)
/*! TXQPAUSED - Transmit Queue in Pause
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_TXQ0_DEBUG_TXQPAUSED(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_DEBUG_TXQPAUSED_SHIFT)) & EMAC_MTL_TXQ0_DEBUG_TXQPAUSED_MASK)

#define EMAC_MTL_TXQ0_DEBUG_TRCSTS_MASK          (0x6U)
#define EMAC_MTL_TXQ0_DEBUG_TRCSTS_SHIFT         (1U)
/*! TRCSTS - MTL Tx Queue Read Controller Status
 *  0b00..Idle state
 *  0b01..Read state (transferring data to the MAC transmitter)
 *  0b10..Waiting for pending transit status from the MAC transmitter
 *  0b11..Flushing the transit queue because of the packet abort request from the MAC
 */
#define EMAC_MTL_TXQ0_DEBUG_TRCSTS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_DEBUG_TRCSTS_SHIFT)) & EMAC_MTL_TXQ0_DEBUG_TRCSTS_MASK)

#define EMAC_MTL_TXQ0_DEBUG_TWCSTS_MASK          (0x8U)
#define EMAC_MTL_TXQ0_DEBUG_TWCSTS_SHIFT         (3U)
/*! TWCSTS - MTL Tx Queue Write Controller Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_TXQ0_DEBUG_TWCSTS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_DEBUG_TWCSTS_SHIFT)) & EMAC_MTL_TXQ0_DEBUG_TWCSTS_MASK)

#define EMAC_MTL_TXQ0_DEBUG_TXQSTS_MASK          (0x10U)
#define EMAC_MTL_TXQ0_DEBUG_TXQSTS_SHIFT         (4U)
/*! TXQSTS - MTL Tx Queue Not Empty Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_TXQ0_DEBUG_TXQSTS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_DEBUG_TXQSTS_SHIFT)) & EMAC_MTL_TXQ0_DEBUG_TXQSTS_MASK)

#define EMAC_MTL_TXQ0_DEBUG_TXSTSFSTS_MASK       (0x20U)
#define EMAC_MTL_TXQ0_DEBUG_TXSTSFSTS_SHIFT      (5U)
/*! TXSTSFSTS - MTL Tx Status FIFO Full Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_TXQ0_DEBUG_TXSTSFSTS(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_DEBUG_TXSTSFSTS_SHIFT)) & EMAC_MTL_TXQ0_DEBUG_TXSTSFSTS_MASK)

#define EMAC_MTL_TXQ0_DEBUG_PTXQ_MASK            (0x70000U)
#define EMAC_MTL_TXQ0_DEBUG_PTXQ_SHIFT           (16U)
/*! PTXQ - Number of Packets in the Transmit Queue */
#define EMAC_MTL_TXQ0_DEBUG_PTXQ(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_DEBUG_PTXQ_SHIFT)) & EMAC_MTL_TXQ0_DEBUG_PTXQ_MASK)

#define EMAC_MTL_TXQ0_DEBUG_STXSTSF_MASK         (0x700000U)
#define EMAC_MTL_TXQ0_DEBUG_STXSTSF_SHIFT        (20U)
/*! STXSTSF - Number of Status Words in Tx Status FIFO of Queue */
#define EMAC_MTL_TXQ0_DEBUG_STXSTSF(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_DEBUG_STXSTSF_SHIFT)) & EMAC_MTL_TXQ0_DEBUG_STXSTSF_MASK)
/*! @} */

/*! @name MTL_TXQ0_ETS_STATUS - MTL Tx Queue 0 ETS Status */
/*! @{ */

#define EMAC_MTL_TXQ0_ETS_STATUS_ABS_MASK        (0xFFFFFFU)
#define EMAC_MTL_TXQ0_ETS_STATUS_ABS_SHIFT       (0U)
/*! ABS - Average Bits per Slot */
#define EMAC_MTL_TXQ0_ETS_STATUS_ABS(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_ETS_STATUS_ABS_SHIFT)) & EMAC_MTL_TXQ0_ETS_STATUS_ABS_MASK)
/*! @} */

/*! @name MTL_TXQ0_QUANTUM_WEIGHT - MTL Tx Queue Quantum Weight */
/*! @{ */

#define EMAC_MTL_TXQ0_QUANTUM_WEIGHT_ISCQW_MASK  (0x1FFFFFU)
#define EMAC_MTL_TXQ0_QUANTUM_WEIGHT_ISCQW_SHIFT (0U)
/*! ISCQW - Quantum or Weights */
#define EMAC_MTL_TXQ0_QUANTUM_WEIGHT_ISCQW(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ0_QUANTUM_WEIGHT_ISCQW_SHIFT)) & EMAC_MTL_TXQ0_QUANTUM_WEIGHT_ISCQW_MASK)
/*! @} */

/*! @name MTL_Q0_INTERRUPT_CONTROL_STATUS - MTL Queue 0 Interrupt Control Status */
/*! @{ */

#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUNFIS_MASK (0x1U)
#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUNFIS_SHIFT (0U)
/*! TXUNFIS - Transmit Queue Underflow Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUNFIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUNFIS_SHIFT)) & EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUNFIS_MASK)

#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIS_MASK (0x2U)
#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIS_SHIFT (1U)
/*! ABPSIS - Average Bits Per Slot Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIS_SHIFT)) & EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIS_MASK)

#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUIE_MASK (0x100U)
#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUIE_SHIFT (8U)
/*! TXUIE - Transmit Queue Underflow Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUIE(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUIE_SHIFT)) & EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUIE_MASK)

#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIE_MASK (0x200U)
#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIE_SHIFT (9U)
/*! ABPSIE - Average Bits Per Slot Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIE(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIE_SHIFT)) & EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIE_MASK)

#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOVFIS_MASK (0x10000U)
#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOVFIS_SHIFT (16U)
/*! RXOVFIS - Receive Queue Overflow Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOVFIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOVFIS_SHIFT)) & EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOVFIS_MASK)

#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOIE_MASK (0x1000000U)
#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOIE_SHIFT (24U)
/*! RXOIE - Receive Queue Overflow Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOIE(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOIE_SHIFT)) & EMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOIE_MASK)
/*! @} */

/*! @name MTL_RXQ0_OPERATION_MODE - MTL Rx Queue 0 Operation Mode */
/*! @{ */

#define EMAC_MTL_RXQ0_OPERATION_MODE_RTC_MASK    (0x3U)
#define EMAC_MTL_RXQ0_OPERATION_MODE_RTC_SHIFT   (0U)
/*! RTC - Receive Queue Threshold Control
 *  0b00..64
 *  0b01..32
 *  0b10..96
 *  0b11..128
 */
#define EMAC_MTL_RXQ0_OPERATION_MODE_RTC(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_OPERATION_MODE_RTC_SHIFT)) & EMAC_MTL_RXQ0_OPERATION_MODE_RTC_MASK)

#define EMAC_MTL_RXQ0_OPERATION_MODE_FUP_MASK    (0x8U)
#define EMAC_MTL_RXQ0_OPERATION_MODE_FUP_SHIFT   (3U)
/*! FUP - Forward Undersized Good Packets
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_RXQ0_OPERATION_MODE_FUP(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_OPERATION_MODE_FUP_SHIFT)) & EMAC_MTL_RXQ0_OPERATION_MODE_FUP_MASK)

#define EMAC_MTL_RXQ0_OPERATION_MODE_FEP_MASK    (0x10U)
#define EMAC_MTL_RXQ0_OPERATION_MODE_FEP_SHIFT   (4U)
/*! FEP - Forward Error Packets
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_RXQ0_OPERATION_MODE_FEP(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_OPERATION_MODE_FEP_SHIFT)) & EMAC_MTL_RXQ0_OPERATION_MODE_FEP_MASK)

#define EMAC_MTL_RXQ0_OPERATION_MODE_RSF_MASK    (0x20U)
#define EMAC_MTL_RXQ0_OPERATION_MODE_RSF_SHIFT   (5U)
/*! RSF - Receive Queue Store and Forward
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_RXQ0_OPERATION_MODE_RSF(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_OPERATION_MODE_RSF_SHIFT)) & EMAC_MTL_RXQ0_OPERATION_MODE_RSF_MASK)

#define EMAC_MTL_RXQ0_OPERATION_MODE_DIS_TCP_EF_MASK (0x40U)
#define EMAC_MTL_RXQ0_OPERATION_MODE_DIS_TCP_EF_SHIFT (6U)
/*! DIS_TCP_EF - Disable Dropping of TCP/IP Checksum Error Packets
 *  0b0..Enable
 *  0b1..Disable
 */
#define EMAC_MTL_RXQ0_OPERATION_MODE_DIS_TCP_EF(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_OPERATION_MODE_DIS_TCP_EF_SHIFT)) & EMAC_MTL_RXQ0_OPERATION_MODE_DIS_TCP_EF_MASK)

#define EMAC_MTL_RXQ0_OPERATION_MODE_EHFC_MASK   (0x80U)
#define EMAC_MTL_RXQ0_OPERATION_MODE_EHFC_SHIFT  (7U)
/*! EHFC - Enable Hardware Flow Control
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_MTL_RXQ0_OPERATION_MODE_EHFC(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_OPERATION_MODE_EHFC_SHIFT)) & EMAC_MTL_RXQ0_OPERATION_MODE_EHFC_MASK)

#define EMAC_MTL_RXQ0_OPERATION_MODE_RFA_MASK    (0xF00U)
#define EMAC_MTL_RXQ0_OPERATION_MODE_RFA_SHIFT   (8U)
/*! RFA - Threshold for Activating Flow Control (in half-duplex and full-duplex) */
#define EMAC_MTL_RXQ0_OPERATION_MODE_RFA(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_OPERATION_MODE_RFA_SHIFT)) & EMAC_MTL_RXQ0_OPERATION_MODE_RFA_MASK)

#define EMAC_MTL_RXQ0_OPERATION_MODE_RFD_MASK    (0x3C000U)
#define EMAC_MTL_RXQ0_OPERATION_MODE_RFD_SHIFT   (14U)
/*! RFD - Threshold for Deactivating Flow Control (in half-duplex and full-duplex modes) */
#define EMAC_MTL_RXQ0_OPERATION_MODE_RFD(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_OPERATION_MODE_RFD_SHIFT)) & EMAC_MTL_RXQ0_OPERATION_MODE_RFD_MASK)

#define EMAC_MTL_RXQ0_OPERATION_MODE_RQS_MASK    (0x1F00000U)
#define EMAC_MTL_RXQ0_OPERATION_MODE_RQS_SHIFT   (20U)
/*! RQS - Receive Queue Size */
#define EMAC_MTL_RXQ0_OPERATION_MODE_RQS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_OPERATION_MODE_RQS_SHIFT)) & EMAC_MTL_RXQ0_OPERATION_MODE_RQS_MASK)
/*! @} */

/*! @name MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT - MTL Rx Queue Missed Packet Overflow Count */
/*! @{ */

#define EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_MASK (0x7FFU)
#define EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_SHIFT (0U)
/*! OVFPKTCNT - Overflow Packet Counter */
#define EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_SHIFT)) & EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_MASK)

#define EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_MASK (0x800U)
#define EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_SHIFT (11U)
/*! OVFCNTOVF - Overflow Counter Overflow Bit
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_SHIFT)) & EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_MASK)

#define EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_MASK (0x7FF0000U)
#define EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_SHIFT (16U)
/*! MISPKTCNT - Missed Packet Counter */
#define EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_SHIFT)) & EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_MASK)

#define EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_MASK (0x8000000U)
#define EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_SHIFT (27U)
/*! MISCNTOVF - Missed Packet Counter Overflow Bit
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_SHIFT)) & EMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_MASK)
/*! @} */

/*! @name MTL_RXQ0_DEBUG - MTL Rx Queue 0 Debug */
/*! @{ */

#define EMAC_MTL_RXQ0_DEBUG_RWCSTS_MASK          (0x1U)
#define EMAC_MTL_RXQ0_DEBUG_RWCSTS_SHIFT         (0U)
/*! RWCSTS - MTL Rx Queue Write Controller Active Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_RXQ0_DEBUG_RWCSTS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_DEBUG_RWCSTS_SHIFT)) & EMAC_MTL_RXQ0_DEBUG_RWCSTS_MASK)

#define EMAC_MTL_RXQ0_DEBUG_RRCSTS_MASK          (0x6U)
#define EMAC_MTL_RXQ0_DEBUG_RRCSTS_SHIFT         (1U)
/*! RRCSTS - MTL Rx Queue Read Controller State
 *  0b00..Idle state
 *  0b01..Reading packet data
 *  0b10..Reading packet status (or timestamp)
 *  0b11..Flushing the packet data and status
 */
#define EMAC_MTL_RXQ0_DEBUG_RRCSTS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_DEBUG_RRCSTS_SHIFT)) & EMAC_MTL_RXQ0_DEBUG_RRCSTS_MASK)

#define EMAC_MTL_RXQ0_DEBUG_RXQSTS_MASK          (0x30U)
#define EMAC_MTL_RXQ0_DEBUG_RXQSTS_SHIFT         (4U)
/*! RXQSTS - MTL Rx Queue Fill-Level Status
 *  0b00..Rx Queue empty
 *  0b01..Rx Queue fill-level below flow-control deactivate threshold
 *  0b10..Rx Queue fill-level above flow-control activate threshold
 *  0b11..Rx Queue full
 */
#define EMAC_MTL_RXQ0_DEBUG_RXQSTS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_DEBUG_RXQSTS_SHIFT)) & EMAC_MTL_RXQ0_DEBUG_RXQSTS_MASK)

#define EMAC_MTL_RXQ0_DEBUG_PRXQ_MASK            (0x3FFF0000U)
#define EMAC_MTL_RXQ0_DEBUG_PRXQ_SHIFT           (16U)
/*! PRXQ - Number of Packets in Receive Queue */
#define EMAC_MTL_RXQ0_DEBUG_PRXQ(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_DEBUG_PRXQ_SHIFT)) & EMAC_MTL_RXQ0_DEBUG_PRXQ_MASK)
/*! @} */

/*! @name MTL_RXQ0_CONTROL - MTL Rx Queue 0 Control 0 */
/*! @{ */

#define EMAC_MTL_RXQ0_CONTROL_RXQ_WEGT_MASK      (0x7U)
#define EMAC_MTL_RXQ0_CONTROL_RXQ_WEGT_SHIFT     (0U)
/*! RXQ_WEGT - Receive Queue Weight */
#define EMAC_MTL_RXQ0_CONTROL_RXQ_WEGT(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_CONTROL_RXQ_WEGT_SHIFT)) & EMAC_MTL_RXQ0_CONTROL_RXQ_WEGT_MASK)

#define EMAC_MTL_RXQ0_CONTROL_RXQ_FRM_ARBIT_MASK (0x8U)
#define EMAC_MTL_RXQ0_CONTROL_RXQ_FRM_ARBIT_SHIFT (3U)
/*! RXQ_FRM_ARBIT - Receive Queue Packet Arbitration
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_RXQ0_CONTROL_RXQ_FRM_ARBIT(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ0_CONTROL_RXQ_FRM_ARBIT_SHIFT)) & EMAC_MTL_RXQ0_CONTROL_RXQ_FRM_ARBIT_MASK)
/*! @} */

/*! @name MTL_TXQ1_OPERATION_MODE - MTL Tx Queue 1 Operation Mode */
/*! @{ */

#define EMAC_MTL_TXQ1_OPERATION_MODE_FTQ_MASK    (0x1U)
#define EMAC_MTL_TXQ1_OPERATION_MODE_FTQ_SHIFT   (0U)
/*! FTQ - Flush Transmit Queue
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_TXQ1_OPERATION_MODE_FTQ(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_OPERATION_MODE_FTQ_SHIFT)) & EMAC_MTL_TXQ1_OPERATION_MODE_FTQ_MASK)

#define EMAC_MTL_TXQ1_OPERATION_MODE_TSF_MASK    (0x2U)
#define EMAC_MTL_TXQ1_OPERATION_MODE_TSF_SHIFT   (1U)
/*! TSF - Transmit Store and Forward
 *  0b0..Transmit Store and Forward is disabled
 *  0b1..Transmit Store and Forward is enabled
 */
#define EMAC_MTL_TXQ1_OPERATION_MODE_TSF(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_OPERATION_MODE_TSF_SHIFT)) & EMAC_MTL_TXQ1_OPERATION_MODE_TSF_MASK)

#define EMAC_MTL_TXQ1_OPERATION_MODE_TXQEN_MASK  (0xCU)
#define EMAC_MTL_TXQ1_OPERATION_MODE_TXQEN_SHIFT (2U)
/*! TXQEN - Transmit Queue Enable
 *  0b00..Not enabled
 *  0b01..Enable in AV mode (Reserved in non-AV)
 *  0b10..Enabled
 *  0b11..Reserved
 */
#define EMAC_MTL_TXQ1_OPERATION_MODE_TXQEN(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_OPERATION_MODE_TXQEN_SHIFT)) & EMAC_MTL_TXQ1_OPERATION_MODE_TXQEN_MASK)

#define EMAC_MTL_TXQ1_OPERATION_MODE_TTC_MASK    (0x70U)
#define EMAC_MTL_TXQ1_OPERATION_MODE_TTC_SHIFT   (4U)
/*! TTC - Transmit Threshold Control
 *  0b000..32
 *  0b001..64
 *  0b010..96
 *  0b011..128
 *  0b100..192
 *  0b101..256
 *  0b110..384
 *  0b111..512
 */
#define EMAC_MTL_TXQ1_OPERATION_MODE_TTC(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_OPERATION_MODE_TTC_SHIFT)) & EMAC_MTL_TXQ1_OPERATION_MODE_TTC_MASK)

#define EMAC_MTL_TXQ1_OPERATION_MODE_TQS_MASK    (0x1F0000U)
#define EMAC_MTL_TXQ1_OPERATION_MODE_TQS_SHIFT   (16U)
/*! TQS - Transmit Queue Size */
#define EMAC_MTL_TXQ1_OPERATION_MODE_TQS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_OPERATION_MODE_TQS_SHIFT)) & EMAC_MTL_TXQ1_OPERATION_MODE_TQS_MASK)
/*! @} */

/*! @name MTL_TXQ1_UNDERFLOW - MTL Tx Queue 1 Underflow */
/*! @{ */

#define EMAC_MTL_TXQ1_UNDERFLOW_UFFRMCNT_MASK    (0x7FFU)
#define EMAC_MTL_TXQ1_UNDERFLOW_UFFRMCNT_SHIFT   (0U)
/*! UFFRMCNT - Underflow Packet Counter */
#define EMAC_MTL_TXQ1_UNDERFLOW_UFFRMCNT(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_UNDERFLOW_UFFRMCNT_SHIFT)) & EMAC_MTL_TXQ1_UNDERFLOW_UFFRMCNT_MASK)

#define EMAC_MTL_TXQ1_UNDERFLOW_UFCNTOVF_MASK    (0x800U)
#define EMAC_MTL_TXQ1_UNDERFLOW_UFCNTOVF_SHIFT   (11U)
/*! UFCNTOVF - Overflow Bit for Underflow Packet Counter
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_TXQ1_UNDERFLOW_UFCNTOVF(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_UNDERFLOW_UFCNTOVF_SHIFT)) & EMAC_MTL_TXQ1_UNDERFLOW_UFCNTOVF_MASK)
/*! @} */

/*! @name MTL_TXQ1_DEBUG - MTL Tx Queue 1 Debug */
/*! @{ */

#define EMAC_MTL_TXQ1_DEBUG_TXQPAUSED_MASK       (0x1U)
#define EMAC_MTL_TXQ1_DEBUG_TXQPAUSED_SHIFT      (0U)
/*! TXQPAUSED - Transmit Queue in Pause
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_TXQ1_DEBUG_TXQPAUSED(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_DEBUG_TXQPAUSED_SHIFT)) & EMAC_MTL_TXQ1_DEBUG_TXQPAUSED_MASK)

#define EMAC_MTL_TXQ1_DEBUG_TRCSTS_MASK          (0x6U)
#define EMAC_MTL_TXQ1_DEBUG_TRCSTS_SHIFT         (1U)
/*! TRCSTS - MTL Tx Queue Read Controller Status
 *  0b00..Idle state
 *  0b01..Read state (transferring data to the MAC transmitter)
 *  0b10..Waiting for pending transit status from the MAC transmitter
 *  0b11..Flushing the transit queue because of the packet abort request from the MAC
 */
#define EMAC_MTL_TXQ1_DEBUG_TRCSTS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_DEBUG_TRCSTS_SHIFT)) & EMAC_MTL_TXQ1_DEBUG_TRCSTS_MASK)

#define EMAC_MTL_TXQ1_DEBUG_TWCSTS_MASK          (0x8U)
#define EMAC_MTL_TXQ1_DEBUG_TWCSTS_SHIFT         (3U)
/*! TWCSTS - MTL Tx Queue Write Controller Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_TXQ1_DEBUG_TWCSTS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_DEBUG_TWCSTS_SHIFT)) & EMAC_MTL_TXQ1_DEBUG_TWCSTS_MASK)

#define EMAC_MTL_TXQ1_DEBUG_TXQSTS_MASK          (0x10U)
#define EMAC_MTL_TXQ1_DEBUG_TXQSTS_SHIFT         (4U)
/*! TXQSTS - MTL Tx Queue Not Empty Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_TXQ1_DEBUG_TXQSTS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_DEBUG_TXQSTS_SHIFT)) & EMAC_MTL_TXQ1_DEBUG_TXQSTS_MASK)

#define EMAC_MTL_TXQ1_DEBUG_TXSTSFSTS_MASK       (0x20U)
#define EMAC_MTL_TXQ1_DEBUG_TXSTSFSTS_SHIFT      (5U)
/*! TXSTSFSTS - MTL Tx Status FIFO Full Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_TXQ1_DEBUG_TXSTSFSTS(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_DEBUG_TXSTSFSTS_SHIFT)) & EMAC_MTL_TXQ1_DEBUG_TXSTSFSTS_MASK)

#define EMAC_MTL_TXQ1_DEBUG_PTXQ_MASK            (0x70000U)
#define EMAC_MTL_TXQ1_DEBUG_PTXQ_SHIFT           (16U)
/*! PTXQ - Number of Packets in the Transmit Queue */
#define EMAC_MTL_TXQ1_DEBUG_PTXQ(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_DEBUG_PTXQ_SHIFT)) & EMAC_MTL_TXQ1_DEBUG_PTXQ_MASK)

#define EMAC_MTL_TXQ1_DEBUG_STXSTSF_MASK         (0x700000U)
#define EMAC_MTL_TXQ1_DEBUG_STXSTSF_SHIFT        (20U)
/*! STXSTSF - Number of Status Words in Tx Status FIFO of Queue */
#define EMAC_MTL_TXQ1_DEBUG_STXSTSF(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_DEBUG_STXSTSF_SHIFT)) & EMAC_MTL_TXQ1_DEBUG_STXSTSF_MASK)
/*! @} */

/*! @name MTL_TXQ1_ETS_CONTROL - MTL Tx Queue 1 ETS Control */
/*! @{ */

#define EMAC_MTL_TXQ1_ETS_CONTROL_AVALG_MASK     (0x4U)
#define EMAC_MTL_TXQ1_ETS_CONTROL_AVALG_SHIFT    (2U)
/*! AVALG - AV Algorithm
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_TXQ1_ETS_CONTROL_AVALG(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_ETS_CONTROL_AVALG_SHIFT)) & EMAC_MTL_TXQ1_ETS_CONTROL_AVALG_MASK)

#define EMAC_MTL_TXQ1_ETS_CONTROL_CC_MASK        (0x8U)
#define EMAC_MTL_TXQ1_ETS_CONTROL_CC_SHIFT       (3U)
/*! CC - Credit Control
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_TXQ1_ETS_CONTROL_CC(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_ETS_CONTROL_CC_SHIFT)) & EMAC_MTL_TXQ1_ETS_CONTROL_CC_MASK)

#define EMAC_MTL_TXQ1_ETS_CONTROL_SLC_MASK       (0x70U)
#define EMAC_MTL_TXQ1_ETS_CONTROL_SLC_SHIFT      (4U)
/*! SLC - Slot Count
 *  0b000..1 slot
 *  0b001..2 slots
 *  0b010..4 slots
 *  0b011..8 slots
 *  0b100..16 slots
 *  0b101..Reserved
 */
#define EMAC_MTL_TXQ1_ETS_CONTROL_SLC(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_ETS_CONTROL_SLC_SHIFT)) & EMAC_MTL_TXQ1_ETS_CONTROL_SLC_MASK)
/*! @} */

/*! @name MTL_TXQ1_ETS_STATUS - MTL Tx Queue 1 ETS Status */
/*! @{ */

#define EMAC_MTL_TXQ1_ETS_STATUS_ABS_MASK        (0xFFFFFFU)
#define EMAC_MTL_TXQ1_ETS_STATUS_ABS_SHIFT       (0U)
/*! ABS - Average Bits per Slot */
#define EMAC_MTL_TXQ1_ETS_STATUS_ABS(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_ETS_STATUS_ABS_SHIFT)) & EMAC_MTL_TXQ1_ETS_STATUS_ABS_MASK)
/*! @} */

/*! @name MTL_TXQ1_QUANTUM_WEIGHT - MTL Tx Queue 1 Quantum Weight */
/*! @{ */

#define EMAC_MTL_TXQ1_QUANTUM_WEIGHT_ISCQW_MASK  (0x1FFFFFU)
#define EMAC_MTL_TXQ1_QUANTUM_WEIGHT_ISCQW_SHIFT (0U)
/*! ISCQW - idleSlopeCredit, Quantum or Weights */
#define EMAC_MTL_TXQ1_QUANTUM_WEIGHT_ISCQW(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_QUANTUM_WEIGHT_ISCQW_SHIFT)) & EMAC_MTL_TXQ1_QUANTUM_WEIGHT_ISCQW_MASK)
/*! @} */

/*! @name MTL_TXQ1_SENDSLOPECREDIT - MTL Tx Queue 1 Sendslope Credit */
/*! @{ */

#define EMAC_MTL_TXQ1_SENDSLOPECREDIT_SSC_MASK   (0x3FFFU)
#define EMAC_MTL_TXQ1_SENDSLOPECREDIT_SSC_SHIFT  (0U)
/*! SSC - sendSlopeCredit Value */
#define EMAC_MTL_TXQ1_SENDSLOPECREDIT_SSC(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_SENDSLOPECREDIT_SSC_SHIFT)) & EMAC_MTL_TXQ1_SENDSLOPECREDIT_SSC_MASK)
/*! @} */

/*! @name MTL_TXQ1_HICREDIT - MTL Tx Queue 1 HiCredit */
/*! @{ */

#define EMAC_MTL_TXQ1_HICREDIT_HC_MASK           (0x1FFFFFFFU)
#define EMAC_MTL_TXQ1_HICREDIT_HC_SHIFT          (0U)
/*! HC - hiCredit Value */
#define EMAC_MTL_TXQ1_HICREDIT_HC(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_HICREDIT_HC_SHIFT)) & EMAC_MTL_TXQ1_HICREDIT_HC_MASK)
/*! @} */

/*! @name MTL_TXQ1_LOCREDIT - MTL Tx Queue 1 LoCredit */
/*! @{ */

#define EMAC_MTL_TXQ1_LOCREDIT_LC_MASK           (0x1FFFFFFFU)
#define EMAC_MTL_TXQ1_LOCREDIT_LC_SHIFT          (0U)
/*! LC - loCredit Value */
#define EMAC_MTL_TXQ1_LOCREDIT_LC(x)             (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_TXQ1_LOCREDIT_LC_SHIFT)) & EMAC_MTL_TXQ1_LOCREDIT_LC_MASK)
/*! @} */

/*! @name MTL_Q1_INTERRUPT_CONTROL_STATUS - MTL Queue 1 Interrupt Control Status */
/*! @{ */

#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUNFIS_MASK (0x1U)
#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUNFIS_SHIFT (0U)
/*! TXUNFIS - Transmit Queue Underflow Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUNFIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUNFIS_SHIFT)) & EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUNFIS_MASK)

#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIS_MASK (0x2U)
#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIS_SHIFT (1U)
/*! ABPSIS - Average Bits Per Slot Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIS_SHIFT)) & EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIS_MASK)

#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUIE_MASK (0x100U)
#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUIE_SHIFT (8U)
/*! TXUIE - Transmit Queue Underflow Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUIE(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUIE_SHIFT)) & EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUIE_MASK)

#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIE_MASK (0x200U)
#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIE_SHIFT (9U)
/*! ABPSIE - Average Bits Per Slot Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIE(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIE_SHIFT)) & EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIE_MASK)

#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOVFIS_MASK (0x10000U)
#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOVFIS_SHIFT (16U)
/*! RXOVFIS - Receive Queue Overflow Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOVFIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOVFIS_SHIFT)) & EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOVFIS_MASK)

#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOIE_MASK (0x1000000U)
#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOIE_SHIFT (24U)
/*! RXOIE - Receive Queue Overflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOIE(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOIE_SHIFT)) & EMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOIE_MASK)
/*! @} */

/*! @name MTL_RXQ1_OPERATION_MODE - MTL Rx Queue 1 Operation Mode */
/*! @{ */

#define EMAC_MTL_RXQ1_OPERATION_MODE_RTC_MASK    (0x3U)
#define EMAC_MTL_RXQ1_OPERATION_MODE_RTC_SHIFT   (0U)
/*! RTC - Receive Queue Threshold Control
 *  0b00..64
 *  0b01..32
 *  0b10..96
 *  0b11..128
 */
#define EMAC_MTL_RXQ1_OPERATION_MODE_RTC(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_OPERATION_MODE_RTC_SHIFT)) & EMAC_MTL_RXQ1_OPERATION_MODE_RTC_MASK)

#define EMAC_MTL_RXQ1_OPERATION_MODE_FUP_MASK    (0x8U)
#define EMAC_MTL_RXQ1_OPERATION_MODE_FUP_SHIFT   (3U)
/*! FUP - Forward Undersized Good Packets
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_RXQ1_OPERATION_MODE_FUP(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_OPERATION_MODE_FUP_SHIFT)) & EMAC_MTL_RXQ1_OPERATION_MODE_FUP_MASK)

#define EMAC_MTL_RXQ1_OPERATION_MODE_FEP_MASK    (0x10U)
#define EMAC_MTL_RXQ1_OPERATION_MODE_FEP_SHIFT   (4U)
/*! FEP - Forward Error Packets
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_RXQ1_OPERATION_MODE_FEP(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_OPERATION_MODE_FEP_SHIFT)) & EMAC_MTL_RXQ1_OPERATION_MODE_FEP_MASK)

#define EMAC_MTL_RXQ1_OPERATION_MODE_RSF_MASK    (0x20U)
#define EMAC_MTL_RXQ1_OPERATION_MODE_RSF_SHIFT   (5U)
/*! RSF - Receive Queue Store and Forward
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_RXQ1_OPERATION_MODE_RSF(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_OPERATION_MODE_RSF_SHIFT)) & EMAC_MTL_RXQ1_OPERATION_MODE_RSF_MASK)

#define EMAC_MTL_RXQ1_OPERATION_MODE_DIS_TCP_EF_MASK (0x40U)
#define EMAC_MTL_RXQ1_OPERATION_MODE_DIS_TCP_EF_SHIFT (6U)
/*! DIS_TCP_EF - Disable Dropping of TCP or IP Checksum Error Packets
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define EMAC_MTL_RXQ1_OPERATION_MODE_DIS_TCP_EF(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_OPERATION_MODE_DIS_TCP_EF_SHIFT)) & EMAC_MTL_RXQ1_OPERATION_MODE_DIS_TCP_EF_MASK)

#define EMAC_MTL_RXQ1_OPERATION_MODE_EHFC_MASK   (0x80U)
#define EMAC_MTL_RXQ1_OPERATION_MODE_EHFC_SHIFT  (7U)
/*! EHFC - Enable Hardware Flow Control
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_MTL_RXQ1_OPERATION_MODE_EHFC(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_OPERATION_MODE_EHFC_SHIFT)) & EMAC_MTL_RXQ1_OPERATION_MODE_EHFC_MASK)

#define EMAC_MTL_RXQ1_OPERATION_MODE_RFA_MASK    (0xF00U)
#define EMAC_MTL_RXQ1_OPERATION_MODE_RFA_SHIFT   (8U)
/*! RFA - Threshold for Activating Flow Control (in half-duplex and full-duplex */
#define EMAC_MTL_RXQ1_OPERATION_MODE_RFA(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_OPERATION_MODE_RFA_SHIFT)) & EMAC_MTL_RXQ1_OPERATION_MODE_RFA_MASK)

#define EMAC_MTL_RXQ1_OPERATION_MODE_RFD_MASK    (0x3C000U)
#define EMAC_MTL_RXQ1_OPERATION_MODE_RFD_SHIFT   (14U)
/*! RFD - Threshold for Deactivating Flow Control (in half-duplex and full-duplex modes) */
#define EMAC_MTL_RXQ1_OPERATION_MODE_RFD(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_OPERATION_MODE_RFD_SHIFT)) & EMAC_MTL_RXQ1_OPERATION_MODE_RFD_MASK)

#define EMAC_MTL_RXQ1_OPERATION_MODE_RQS_MASK    (0x1F00000U)
#define EMAC_MTL_RXQ1_OPERATION_MODE_RQS_SHIFT   (20U)
/*! RQS - Receive Queue Size */
#define EMAC_MTL_RXQ1_OPERATION_MODE_RQS(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_OPERATION_MODE_RQS_SHIFT)) & EMAC_MTL_RXQ1_OPERATION_MODE_RQS_MASK)
/*! @} */

/*! @name MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT - MTL Rx Queue 1 Missed Packet Overflow Counter */
/*! @{ */

#define EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_MASK (0x7FFU)
#define EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_SHIFT (0U)
/*! OVFPKTCNT - Overflow Packet Counter */
#define EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_SHIFT)) & EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_MASK)

#define EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_MASK (0x800U)
#define EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_SHIFT (11U)
/*! OVFCNTOVF - Overflow Counter Overflow Bit
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_SHIFT)) & EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_MASK)

#define EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_MASK (0x7FF0000U)
#define EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_SHIFT (16U)
/*! MISPKTCNT - Missed Packet Counter */
#define EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_SHIFT)) & EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_MASK)

#define EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_MASK (0x8000000U)
#define EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_SHIFT (27U)
/*! MISCNTOVF - Missed Packet Counter Overflow Bit
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_SHIFT)) & EMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_MASK)
/*! @} */

/*! @name MTL_RXQ1_DEBUG - MTL Rx Queue 1 Debug */
/*! @{ */

#define EMAC_MTL_RXQ1_DEBUG_RWCSTS_MASK          (0x1U)
#define EMAC_MTL_RXQ1_DEBUG_RWCSTS_SHIFT         (0U)
/*! RWCSTS - MTL Rx Queue Write Controller Active Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_MTL_RXQ1_DEBUG_RWCSTS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_DEBUG_RWCSTS_SHIFT)) & EMAC_MTL_RXQ1_DEBUG_RWCSTS_MASK)

#define EMAC_MTL_RXQ1_DEBUG_RRCSTS_MASK          (0x6U)
#define EMAC_MTL_RXQ1_DEBUG_RRCSTS_SHIFT         (1U)
/*! RRCSTS - MTL Rx Queue Read Controller State
 *  0b00..Idle state
 *  0b01..Reading packet data
 *  0b10..Reading packet status (or timestamp)
 *  0b11..Flushing the packet data and status
 */
#define EMAC_MTL_RXQ1_DEBUG_RRCSTS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_DEBUG_RRCSTS_SHIFT)) & EMAC_MTL_RXQ1_DEBUG_RRCSTS_MASK)

#define EMAC_MTL_RXQ1_DEBUG_RXQSTS_MASK          (0x30U)
#define EMAC_MTL_RXQ1_DEBUG_RXQSTS_SHIFT         (4U)
/*! RXQSTS - MTL Rx Queue Fill-Level Status
 *  0b00..Rx Queue empty
 *  0b01..Rx Queue fill-level below flow-control deactivate threshold
 *  0b10..Rx Queue fill-level above flow-control activate threshold
 *  0b11..Rx Queue full
 */
#define EMAC_MTL_RXQ1_DEBUG_RXQSTS(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_DEBUG_RXQSTS_SHIFT)) & EMAC_MTL_RXQ1_DEBUG_RXQSTS_MASK)

#define EMAC_MTL_RXQ1_DEBUG_PRXQ_MASK            (0x3FFF0000U)
#define EMAC_MTL_RXQ1_DEBUG_PRXQ_SHIFT           (16U)
/*! PRXQ - Number of Packets in Receive Queue */
#define EMAC_MTL_RXQ1_DEBUG_PRXQ(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_DEBUG_PRXQ_SHIFT)) & EMAC_MTL_RXQ1_DEBUG_PRXQ_MASK)
/*! @} */

/*! @name MTL_RXQ1_CONTROL - MTL Rx Queue 1 Control */
/*! @{ */

#define EMAC_MTL_RXQ1_CONTROL_RXQ_WEGT_MASK      (0x7U)
#define EMAC_MTL_RXQ1_CONTROL_RXQ_WEGT_SHIFT     (0U)
/*! RXQ_WEGT - Receive Queue Weight */
#define EMAC_MTL_RXQ1_CONTROL_RXQ_WEGT(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_CONTROL_RXQ_WEGT_SHIFT)) & EMAC_MTL_RXQ1_CONTROL_RXQ_WEGT_MASK)

#define EMAC_MTL_RXQ1_CONTROL_RXQ_FRM_ARBIT_MASK (0x8U)
#define EMAC_MTL_RXQ1_CONTROL_RXQ_FRM_ARBIT_SHIFT (3U)
/*! RXQ_FRM_ARBIT - Receive Queue Packet Arbitration
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_MTL_RXQ1_CONTROL_RXQ_FRM_ARBIT(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_MTL_RXQ1_CONTROL_RXQ_FRM_ARBIT_SHIFT)) & EMAC_MTL_RXQ1_CONTROL_RXQ_FRM_ARBIT_MASK)
/*! @} */

/*! @name DMA_MODE - DMA Mode */
/*! @{ */

#define EMAC_DMA_MODE_SWR_MASK                   (0x1U)
#define EMAC_DMA_MODE_SWR_SHIFT                  (0U)
/*! SWR - Software Reset
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_MODE_SWR(x)                     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_MODE_SWR_SHIFT)) & EMAC_DMA_MODE_SWR_MASK)

#define EMAC_DMA_MODE_DA_MASK                    (0x2U)
#define EMAC_DMA_MODE_DA_SHIFT                   (1U)
/*! DA - DMA Tx or Rx Arbitration Scheme
 *  0b0..Weighted Round-Robin with Rx:Tx or Tx:Rx
 *  0b1..Fixed Priority
 */
#define EMAC_DMA_MODE_DA(x)                      (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_MODE_DA_SHIFT)) & EMAC_DMA_MODE_DA_MASK)

#define EMAC_DMA_MODE_TAA_MASK                   (0x1CU)
#define EMAC_DMA_MODE_TAA_SHIFT                  (2U)
/*! TAA - Transmit Arbitration Algorithm
 *  0b000..Fixed priority (Channel 0 has the lowest priority and the last channel has the highest priority)
 *  0b001..Weighted Strict Priority (WSP)
 *  0b010..Weighted Round-Robin (WRR)
 *  0b011..Reserved (for 3'b011 to 3'b111)
 */
#define EMAC_DMA_MODE_TAA(x)                     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_MODE_TAA_SHIFT)) & EMAC_DMA_MODE_TAA_MASK)

#define EMAC_DMA_MODE_ARBC_MASK                  (0x200U)
#define EMAC_DMA_MODE_ARBC_SHIFT                 (9U)
/*! ARBC
 *  0b0..NXP reserved field disabled
 *  0b1..NXP reserved field enabled up on NXP request
 */
#define EMAC_DMA_MODE_ARBC(x)                    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_MODE_ARBC_SHIFT)) & EMAC_DMA_MODE_ARBC_MASK)

#define EMAC_DMA_MODE_TXPR_MASK                  (0x800U)
#define EMAC_DMA_MODE_TXPR_SHIFT                 (11U)
/*! TXPR - Transmit Priority
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_MODE_TXPR(x)                    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_MODE_TXPR_SHIFT)) & EMAC_DMA_MODE_TXPR_MASK)

#define EMAC_DMA_MODE_PR_MASK                    (0x7000U)
#define EMAC_DMA_MODE_PR_SHIFT                   (12U)
/*! PR - Priority Ratio
 *  0b000..The priority ratio is 1:1
 *  0b001..The priority ratio is 2:1
 *  0b010..The priority ratio is 3:1
 *  0b011..The priority ratio is 4:1
 *  0b100..The priority ratio is 5:1
 *  0b101..The priority ratio is 6:1
 *  0b110..The priority ratio is 7:1
 *  0b111..The priority ratio is 8:1
 */
#define EMAC_DMA_MODE_PR(x)                      (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_MODE_PR_SHIFT)) & EMAC_DMA_MODE_PR_MASK)

#define EMAC_DMA_MODE_INTM_MASK                  (0x30000U)
#define EMAC_DMA_MODE_INTM_SHIFT                 (16U)
/*! INTM - Interrupt Mode
 *  0b00..See above description
 *  0b01..See above description
 *  0b10..See above description
 *  0b11..Reserved
 */
#define EMAC_DMA_MODE_INTM(x)                    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_MODE_INTM_SHIFT)) & EMAC_DMA_MODE_INTM_MASK)
/*! @} */

/*! @name DMA_SYSBUS_MODE - DMA System Bus Mode */
/*! @{ */

#define EMAC_DMA_SYSBUS_MODE_FB_MASK             (0x1U)
#define EMAC_DMA_SYSBUS_MODE_FB_SHIFT            (0U)
/*! FB - Fixed Burst Length
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_SYSBUS_MODE_FB(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_SYSBUS_MODE_FB_SHIFT)) & EMAC_DMA_SYSBUS_MODE_FB_MASK)

#define EMAC_DMA_SYSBUS_MODE_AAL_MASK            (0x1000U)
#define EMAC_DMA_SYSBUS_MODE_AAL_SHIFT           (12U)
/*! AAL - Address-Aligned Beats
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_SYSBUS_MODE_AAL(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_SYSBUS_MODE_AAL_SHIFT)) & EMAC_DMA_SYSBUS_MODE_AAL_MASK)

#define EMAC_DMA_SYSBUS_MODE_MB_MASK             (0x4000U)
#define EMAC_DMA_SYSBUS_MODE_MB_SHIFT            (14U)
/*! MB - Mixed Burst
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_SYSBUS_MODE_MB(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_SYSBUS_MODE_MB_SHIFT)) & EMAC_DMA_SYSBUS_MODE_MB_MASK)

#define EMAC_DMA_SYSBUS_MODE_RB_MASK             (0x8000U)
#define EMAC_DMA_SYSBUS_MODE_RB_SHIFT            (15U)
/*! RB - Rebuild INCRx Burst
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_SYSBUS_MODE_RB(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_SYSBUS_MODE_RB_SHIFT)) & EMAC_DMA_SYSBUS_MODE_RB_MASK)
/*! @} */

/*! @name DMA_INTERRUPT_STATUS - DMA Interrupt Status */
/*! @{ */

#define EMAC_DMA_INTERRUPT_STATUS_DC0IS_MASK     (0x1U)
#define EMAC_DMA_INTERRUPT_STATUS_DC0IS_SHIFT    (0U)
/*! DC0IS - DMA Channel 0 Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_INTERRUPT_STATUS_DC0IS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_INTERRUPT_STATUS_DC0IS_SHIFT)) & EMAC_DMA_INTERRUPT_STATUS_DC0IS_MASK)

#define EMAC_DMA_INTERRUPT_STATUS_DC1IS_MASK     (0x2U)
#define EMAC_DMA_INTERRUPT_STATUS_DC1IS_SHIFT    (1U)
/*! DC1IS - DMA Channel 1 Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_INTERRUPT_STATUS_DC1IS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_INTERRUPT_STATUS_DC1IS_SHIFT)) & EMAC_DMA_INTERRUPT_STATUS_DC1IS_MASK)

#define EMAC_DMA_INTERRUPT_STATUS_MTLIS_MASK     (0x10000U)
#define EMAC_DMA_INTERRUPT_STATUS_MTLIS_SHIFT    (16U)
/*! MTLIS - MTL Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_INTERRUPT_STATUS_MTLIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_INTERRUPT_STATUS_MTLIS_SHIFT)) & EMAC_DMA_INTERRUPT_STATUS_MTLIS_MASK)

#define EMAC_DMA_INTERRUPT_STATUS_MACIS_MASK     (0x20000U)
#define EMAC_DMA_INTERRUPT_STATUS_MACIS_SHIFT    (17U)
/*! MACIS - MAC Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_INTERRUPT_STATUS_MACIS(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_INTERRUPT_STATUS_MACIS_SHIFT)) & EMAC_DMA_INTERRUPT_STATUS_MACIS_MASK)
/*! @} */

/*! @name DMA_DEBUG_STATUS0 - DMA Debug Status 0 */
/*! @{ */

#define EMAC_DMA_DEBUG_STATUS0_AXWHSTS_MASK      (0x1U)
#define EMAC_DMA_DEBUG_STATUS0_AXWHSTS_SHIFT     (0U)
/*! AXWHSTS - AHB Master Status
 *  0b0..Not detected
 *  0b1..detected
 */
#define EMAC_DMA_DEBUG_STATUS0_AXWHSTS(x)        (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_DEBUG_STATUS0_AXWHSTS_SHIFT)) & EMAC_DMA_DEBUG_STATUS0_AXWHSTS_MASK)

#define EMAC_DMA_DEBUG_STATUS0_RPS0_MASK         (0xF00U)
#define EMAC_DMA_DEBUG_STATUS0_RPS0_SHIFT        (8U)
/*! RPS0 - DMA Channel 0 Receive Process State
 *  0b0000..Stopped (Reset or stop receive command issued)
 *  0b0001..Running (Fetching receive transfer descriptor)
 *  0b0010..Reserved for future use
 *  0b0011..Running (Waiting for receive packet)
 *  0b0100..Suspended (Receive descriptor unavailable)
 *  0b0101..Running (Closing the receive descriptor)
 *  0b0110..Timestamp write state
 *  0b0111..Running (Transferring the received packet data from the receive buffer to the system memory)
 */
#define EMAC_DMA_DEBUG_STATUS0_RPS0(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_DEBUG_STATUS0_RPS0_SHIFT)) & EMAC_DMA_DEBUG_STATUS0_RPS0_MASK)

#define EMAC_DMA_DEBUG_STATUS0_TPS0_MASK         (0xF000U)
#define EMAC_DMA_DEBUG_STATUS0_TPS0_SHIFT        (12U)
/*! TPS0 - DMA Channel 0 Transmit Process State
 *  0b0000..Stopped (Reset or stop transmit command issued)
 *  0b0001..Running (Fetching transmit transfer descriptor)
 *  0b0010..Running (Waiting for status)
 *  0b0011..Running (Reading data from system memory buffer and queuing it to the transmit buffer (Tx FIFO))
 *  0b0100..Timestamp write state
 *  0b0101..Reserved for future use
 *  0b0110..Suspended (Transmit descriptor unavailable or transmit buffer underflow)
 *  0b0111..Running (Closing transmit descriptor)
 */
#define EMAC_DMA_DEBUG_STATUS0_TPS0(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_DEBUG_STATUS0_TPS0_SHIFT)) & EMAC_DMA_DEBUG_STATUS0_TPS0_MASK)

#define EMAC_DMA_DEBUG_STATUS0_RPS1_MASK         (0xF0000U)
#define EMAC_DMA_DEBUG_STATUS0_RPS1_SHIFT        (16U)
/*! RPS1 - DMA Channel 1 Receive Process State
 *  0b0000..Stopped (Reset or Stop receive command issued)
 *  0b0001..Running (Fetching receive transfer descriptor)
 *  0b0010..Reserved for future use
 *  0b0011..Running (Waiting for receive packet)
 *  0b0100..Suspended (Receive descriptor unavailable)
 *  0b0101..Running (Closing the receive descriptor)
 *  0b0110..Timestamp write state
 *  0b0111..Running (Transferring the received packet data from the receive buffer to the system memory)
 */
#define EMAC_DMA_DEBUG_STATUS0_RPS1(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_DEBUG_STATUS0_RPS1_SHIFT)) & EMAC_DMA_DEBUG_STATUS0_RPS1_MASK)

#define EMAC_DMA_DEBUG_STATUS0_TPS1_MASK         (0xF00000U)
#define EMAC_DMA_DEBUG_STATUS0_TPS1_SHIFT        (20U)
/*! TPS1 - DMA Channel 1 Transmit Process State
 *  0b0000..Stopped (Reset or stop transmit command issued)
 *  0b0001..Running (Fetching transmit transfer descriptor)
 *  0b0010..Running (Waiting for status)
 *  0b0011..Running (Reading data from system memory buffer and queuing it to the transmit buffer (Tx FIFO))
 *  0b0100..Timestamp write state
 *  0b0101..Reserved for future use
 *  0b0110..Suspended (Transmit descriptor unavailable or transmit buffer underflow)
 *  0b0111..Running (Closing transmit descriptor)
 */
#define EMAC_DMA_DEBUG_STATUS0_TPS1(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_DEBUG_STATUS0_TPS1_SHIFT)) & EMAC_DMA_DEBUG_STATUS0_TPS1_MASK)
/*! @} */

/*! @name DMA_TBS_CTRL - DMA TBS Control */
/*! @{ */

#define EMAC_DMA_TBS_CTRL_FTOV_MASK              (0x1U)
#define EMAC_DMA_TBS_CTRL_FTOV_SHIFT             (0U)
/*! FTOV - Fetch Time Offset Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define EMAC_DMA_TBS_CTRL_FTOV(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_TBS_CTRL_FTOV_SHIFT)) & EMAC_DMA_TBS_CTRL_FTOV_MASK)

#define EMAC_DMA_TBS_CTRL_FGOS_MASK              (0x70U)
#define EMAC_DMA_TBS_CTRL_FGOS_SHIFT             (4U)
/*! FGOS - Fetch GSN Offset */
#define EMAC_DMA_TBS_CTRL_FGOS(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_TBS_CTRL_FGOS_SHIFT)) & EMAC_DMA_TBS_CTRL_FGOS_MASK)

#define EMAC_DMA_TBS_CTRL_FTOS_MASK              (0xFFFFFF00U)
#define EMAC_DMA_TBS_CTRL_FTOS_SHIFT             (8U)
/*! FTOS - Fetch Time Offset */
#define EMAC_DMA_TBS_CTRL_FTOS(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_TBS_CTRL_FTOS_SHIFT)) & EMAC_DMA_TBS_CTRL_FTOS_MASK)
/*! @} */

/*! @name DMA_SAFETY_INTERRUPT_STATUS - DMA Safety Interrupt Status */
/*! @{ */

#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_DECIS_MASK (0x1U)
#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_DECIS_SHIFT (0U)
/*! DECIS - DMA ECC Correctable Error Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_DECIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_SAFETY_INTERRUPT_STATUS_DECIS_SHIFT)) & EMAC_DMA_SAFETY_INTERRUPT_STATUS_DECIS_MASK)

#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_DEUIS_MASK (0x2U)
#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_DEUIS_SHIFT (1U)
/*! DEUIS - DMA ECC Uncorrectable Error Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_DEUIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_SAFETY_INTERRUPT_STATUS_DEUIS_SHIFT)) & EMAC_DMA_SAFETY_INTERRUPT_STATUS_DEUIS_MASK)

#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_MSCIS_MASK (0x10000000U)
#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_MSCIS_SHIFT (28U)
/*! MSCIS - MTL Safety Correctable Error Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_MSCIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_SAFETY_INTERRUPT_STATUS_MSCIS_SHIFT)) & EMAC_DMA_SAFETY_INTERRUPT_STATUS_MSCIS_MASK)

#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_MASK (0x20000000U)
#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_SHIFT (29U)
/*! MSUIS - MTL Safety Uncorrectable Error Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_MSUIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_SHIFT)) & EMAC_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_MASK)

#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_MASK (0x80000000U)
#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_SHIFT (31U)
/*! MCSIS - MAC Safety Uncorrectable Interrupt Status
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_SAFETY_INTERRUPT_STATUS_MCSIS(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_SHIFT)) & EMAC_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_MASK)
/*! @} */

/*! @name DMA_CH0_CONTROL - DMA Channel 0 Control */
/*! @{ */

#define EMAC_DMA_CH0_CONTROL_PBLx8_MASK          (0x10000U)
#define EMAC_DMA_CH0_CONTROL_PBLx8_SHIFT         (16U)
/*! PBLx8 - 8xPBL mode
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH0_CONTROL_PBLx8(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_CONTROL_PBLx8_SHIFT)) & EMAC_DMA_CH0_CONTROL_PBLx8_MASK)

#define EMAC_DMA_CH0_CONTROL_DSL_MASK            (0x1C0000U)
#define EMAC_DMA_CH0_CONTROL_DSL_SHIFT           (18U)
/*! DSL - Descriptor Skip Length */
#define EMAC_DMA_CH0_CONTROL_DSL(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_CONTROL_DSL_SHIFT)) & EMAC_DMA_CH0_CONTROL_DSL_MASK)
/*! @} */

/*! @name DMA_CH0_TX_CONTROL - DMA Channel Tx Control */
/*! @{ */

#define EMAC_DMA_CH0_TX_CONTROL_ST_MASK          (0x1U)
#define EMAC_DMA_CH0_TX_CONTROL_ST_SHIFT         (0U)
/*! ST - Start or Stop Transmission Command
 *  0b0..Stop
 *  0b1..Start
 */
#define EMAC_DMA_CH0_TX_CONTROL_ST(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_TX_CONTROL_ST_SHIFT)) & EMAC_DMA_CH0_TX_CONTROL_ST_MASK)

#define EMAC_DMA_CH0_TX_CONTROL_TCW_MASK         (0xEU)
#define EMAC_DMA_CH0_TX_CONTROL_TCW_SHIFT        (1U)
/*! TCW - Transmit Channel Weight */
#define EMAC_DMA_CH0_TX_CONTROL_TCW(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_TX_CONTROL_TCW_SHIFT)) & EMAC_DMA_CH0_TX_CONTROL_TCW_MASK)

#define EMAC_DMA_CH0_TX_CONTROL_OSF_MASK         (0x10U)
#define EMAC_DMA_CH0_TX_CONTROL_OSF_SHIFT        (4U)
/*! OSF - Operate on Second Packet
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH0_TX_CONTROL_OSF(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_TX_CONTROL_OSF_SHIFT)) & EMAC_DMA_CH0_TX_CONTROL_OSF_MASK)

#define EMAC_DMA_CH0_TX_CONTROL_TxPBL_MASK       (0x3F0000U)
#define EMAC_DMA_CH0_TX_CONTROL_TxPBL_SHIFT      (16U)
/*! TxPBL - Transmit Programmable Burst Length */
#define EMAC_DMA_CH0_TX_CONTROL_TxPBL(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_TX_CONTROL_TxPBL_SHIFT)) & EMAC_DMA_CH0_TX_CONTROL_TxPBL_MASK)

#define EMAC_DMA_CH0_TX_CONTROL_ETIC_MASK        (0x400000U)
#define EMAC_DMA_CH0_TX_CONTROL_ETIC_SHIFT       (22U)
/*! ETIC - Early Transmit Interrupt Control
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH0_TX_CONTROL_ETIC(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_TX_CONTROL_ETIC_SHIFT)) & EMAC_DMA_CH0_TX_CONTROL_ETIC_MASK)

#define EMAC_DMA_CH0_TX_CONTROL_EDSE_MASK        (0x10000000U)
#define EMAC_DMA_CH0_TX_CONTROL_EDSE_SHIFT       (28U)
/*! EDSE - Enhanced Descriptor Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH0_TX_CONTROL_EDSE(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_TX_CONTROL_EDSE_SHIFT)) & EMAC_DMA_CH0_TX_CONTROL_EDSE_MASK)
/*! @} */

/*! @name DMA_CH0_RX_CONTROL - DMA Channel Rx Control */
/*! @{ */

#define EMAC_DMA_CH0_RX_CONTROL_SR_MASK          (0x1U)
#define EMAC_DMA_CH0_RX_CONTROL_SR_SHIFT         (0U)
/*! SR - Start or Stop Receive
 *  0b0..Stop
 *  0b1..Start
 */
#define EMAC_DMA_CH0_RX_CONTROL_SR(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_RX_CONTROL_SR_SHIFT)) & EMAC_DMA_CH0_RX_CONTROL_SR_MASK)

#define EMAC_DMA_CH0_RX_CONTROL_RBSZ_x_0_MASK    (0x6U)
#define EMAC_DMA_CH0_RX_CONTROL_RBSZ_x_0_SHIFT   (1U)
/*! RBSZ_x_0 - Receive Buffer size Low */
#define EMAC_DMA_CH0_RX_CONTROL_RBSZ_x_0(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_RX_CONTROL_RBSZ_x_0_SHIFT)) & EMAC_DMA_CH0_RX_CONTROL_RBSZ_x_0_MASK)

#define EMAC_DMA_CH0_RX_CONTROL_RBSZ_13_y_MASK   (0x7FF8U)
#define EMAC_DMA_CH0_RX_CONTROL_RBSZ_13_y_SHIFT  (3U)
/*! RBSZ_13_y - Receive Buffer size High */
#define EMAC_DMA_CH0_RX_CONTROL_RBSZ_13_y(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_RX_CONTROL_RBSZ_13_y_SHIFT)) & EMAC_DMA_CH0_RX_CONTROL_RBSZ_13_y_MASK)

#define EMAC_DMA_CH0_RX_CONTROL_RxPBL_MASK       (0x3F0000U)
#define EMAC_DMA_CH0_RX_CONTROL_RxPBL_SHIFT      (16U)
/*! RxPBL - Receive Programmable Burst Length */
#define EMAC_DMA_CH0_RX_CONTROL_RxPBL(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_RX_CONTROL_RxPBL_SHIFT)) & EMAC_DMA_CH0_RX_CONTROL_RxPBL_MASK)

#define EMAC_DMA_CH0_RX_CONTROL_ERIC_MASK        (0x400000U)
#define EMAC_DMA_CH0_RX_CONTROL_ERIC_SHIFT       (22U)
/*! ERIC - Early Receive Interrupt Control
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH0_RX_CONTROL_ERIC(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_RX_CONTROL_ERIC_SHIFT)) & EMAC_DMA_CH0_RX_CONTROL_ERIC_MASK)

#define EMAC_DMA_CH0_RX_CONTROL_RPF_MASK         (0x80000000U)
#define EMAC_DMA_CH0_RX_CONTROL_RPF_SHIFT        (31U)
/*! RPF - Rx Packet Flush
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH0_RX_CONTROL_RPF(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_RX_CONTROL_RPF_SHIFT)) & EMAC_DMA_CH0_RX_CONTROL_RPF_MASK)
/*! @} */

/*! @name DMA_CH0_TXDESC_LIST_ADDRESS - DMA Channel 0 Tx Descriptor List Address */
/*! @{ */

#define EMAC_DMA_CH0_TXDESC_LIST_ADDRESS_TDESLA_MASK (0xFFFFFFFCU)
#define EMAC_DMA_CH0_TXDESC_LIST_ADDRESS_TDESLA_SHIFT (2U)
/*! TDESLA - Start of Transmit List */
#define EMAC_DMA_CH0_TXDESC_LIST_ADDRESS_TDESLA(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_TXDESC_LIST_ADDRESS_TDESLA_SHIFT)) & EMAC_DMA_CH0_TXDESC_LIST_ADDRESS_TDESLA_MASK)
/*! @} */

/*! @name DMA_CH0_RXDESC_LIST_ADDRESS - DMA Channel 0 Rx Descriptor List Address */
/*! @{ */

#define EMAC_DMA_CH0_RXDESC_LIST_ADDRESS_RDESLA_MASK (0xFFFFFFFCU)
#define EMAC_DMA_CH0_RXDESC_LIST_ADDRESS_RDESLA_SHIFT (2U)
/*! RDESLA - Start of Receive List */
#define EMAC_DMA_CH0_RXDESC_LIST_ADDRESS_RDESLA(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_RXDESC_LIST_ADDRESS_RDESLA_SHIFT)) & EMAC_DMA_CH0_RXDESC_LIST_ADDRESS_RDESLA_MASK)
/*! @} */

/*! @name DMA_CH0_TXDESC_TAIL_POINTER - DMA Channel 0 Tx Descriptor Tail Pointer */
/*! @{ */

#define EMAC_DMA_CH0_TXDESC_TAIL_POINTER_TDTP_MASK (0xFFFFFFFCU)
#define EMAC_DMA_CH0_TXDESC_TAIL_POINTER_TDTP_SHIFT (2U)
/*! TDTP - Transmit Descriptor Tail Pointer */
#define EMAC_DMA_CH0_TXDESC_TAIL_POINTER_TDTP(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_TXDESC_TAIL_POINTER_TDTP_SHIFT)) & EMAC_DMA_CH0_TXDESC_TAIL_POINTER_TDTP_MASK)
/*! @} */

/*! @name DMA_CH0_RXDESC_TAIL_POINTER - DMA Channeli 0 Rx Descriptor List Pointer */
/*! @{ */

#define EMAC_DMA_CH0_RXDESC_TAIL_POINTER_RDTP_MASK (0xFFFFFFFCU)
#define EMAC_DMA_CH0_RXDESC_TAIL_POINTER_RDTP_SHIFT (2U)
/*! RDTP - Receive Descriptor Tail Pointer */
#define EMAC_DMA_CH0_RXDESC_TAIL_POINTER_RDTP(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_RXDESC_TAIL_POINTER_RDTP_SHIFT)) & EMAC_DMA_CH0_RXDESC_TAIL_POINTER_RDTP_MASK)
/*! @} */

/*! @name DMA_CH0_TXDESC_RING_LENGTH - DMA Channel 0 Tx Descriptor Ring Length */
/*! @{ */

#define EMAC_DMA_CH0_TXDESC_RING_LENGTH_TDRL_MASK (0x3FFU)
#define EMAC_DMA_CH0_TXDESC_RING_LENGTH_TDRL_SHIFT (0U)
/*! TDRL - Transmit Descriptor Ring Length */
#define EMAC_DMA_CH0_TXDESC_RING_LENGTH_TDRL(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_TXDESC_RING_LENGTH_TDRL_SHIFT)) & EMAC_DMA_CH0_TXDESC_RING_LENGTH_TDRL_MASK)
/*! @} */

/*! @name DMA_CH0_RXDESC_RING_LENGTH - DMA Channel 0 Rx Descriptor Ring Length */
/*! @{ */

#define EMAC_DMA_CH0_RXDESC_RING_LENGTH_RDRL_MASK (0x3FFU)
#define EMAC_DMA_CH0_RXDESC_RING_LENGTH_RDRL_SHIFT (0U)
/*! RDRL - Receive Descriptor Ring Length */
#define EMAC_DMA_CH0_RXDESC_RING_LENGTH_RDRL(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_RXDESC_RING_LENGTH_RDRL_SHIFT)) & EMAC_DMA_CH0_RXDESC_RING_LENGTH_RDRL_MASK)
/*! @} */

/*! @name DMA_CH0_INTERRUPT_ENABLE - DMA Channel 0 Interrupt Enable */
/*! @{ */

#define EMAC_DMA_CH0_INTERRUPT_ENABLE_TIE_MASK   (0x1U)
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_TIE_SHIFT  (0U)
/*! TIE - Transmit Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_TIE(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_INTERRUPT_ENABLE_TIE_SHIFT)) & EMAC_DMA_CH0_INTERRUPT_ENABLE_TIE_MASK)

#define EMAC_DMA_CH0_INTERRUPT_ENABLE_TXSE_MASK  (0x2U)
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_TXSE_SHIFT (1U)
/*! TXSE - Transmit Stopped Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_TXSE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_INTERRUPT_ENABLE_TXSE_SHIFT)) & EMAC_DMA_CH0_INTERRUPT_ENABLE_TXSE_MASK)

#define EMAC_DMA_CH0_INTERRUPT_ENABLE_TBUE_MASK  (0x4U)
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_TBUE_SHIFT (2U)
/*! TBUE - Transmit Buffer Unavailable Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_TBUE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_INTERRUPT_ENABLE_TBUE_SHIFT)) & EMAC_DMA_CH0_INTERRUPT_ENABLE_TBUE_MASK)

#define EMAC_DMA_CH0_INTERRUPT_ENABLE_RIE_MASK   (0x40U)
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_RIE_SHIFT  (6U)
/*! RIE - Receive Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_RIE(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_INTERRUPT_ENABLE_RIE_SHIFT)) & EMAC_DMA_CH0_INTERRUPT_ENABLE_RIE_MASK)

#define EMAC_DMA_CH0_INTERRUPT_ENABLE_RBUE_MASK  (0x80U)
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_RBUE_SHIFT (7U)
/*! RBUE - Receive Buffer Unavailable Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_RBUE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_INTERRUPT_ENABLE_RBUE_SHIFT)) & EMAC_DMA_CH0_INTERRUPT_ENABLE_RBUE_MASK)

#define EMAC_DMA_CH0_INTERRUPT_ENABLE_RSE_MASK   (0x100U)
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_RSE_SHIFT  (8U)
/*! RSE - Receive Stopped Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_RSE(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_INTERRUPT_ENABLE_RSE_SHIFT)) & EMAC_DMA_CH0_INTERRUPT_ENABLE_RSE_MASK)

#define EMAC_DMA_CH0_INTERRUPT_ENABLE_RWTE_MASK  (0x200U)
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_RWTE_SHIFT (9U)
/*! RWTE - Receive Watchdog Timeout Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_RWTE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_INTERRUPT_ENABLE_RWTE_SHIFT)) & EMAC_DMA_CH0_INTERRUPT_ENABLE_RWTE_MASK)

#define EMAC_DMA_CH0_INTERRUPT_ENABLE_ETIE_MASK  (0x400U)
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_ETIE_SHIFT (10U)
/*! ETIE - Early Transmit Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_ETIE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_INTERRUPT_ENABLE_ETIE_SHIFT)) & EMAC_DMA_CH0_INTERRUPT_ENABLE_ETIE_MASK)

#define EMAC_DMA_CH0_INTERRUPT_ENABLE_ERIE_MASK  (0x800U)
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_ERIE_SHIFT (11U)
/*! ERIE - Early Receive Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_ERIE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_INTERRUPT_ENABLE_ERIE_SHIFT)) & EMAC_DMA_CH0_INTERRUPT_ENABLE_ERIE_MASK)

#define EMAC_DMA_CH0_INTERRUPT_ENABLE_FBEE_MASK  (0x1000U)
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_FBEE_SHIFT (12U)
/*! FBEE - Fatal Bus Error Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_FBEE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_INTERRUPT_ENABLE_FBEE_SHIFT)) & EMAC_DMA_CH0_INTERRUPT_ENABLE_FBEE_MASK)

#define EMAC_DMA_CH0_INTERRUPT_ENABLE_CDEE_MASK  (0x2000U)
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_CDEE_SHIFT (13U)
/*! CDEE - Context Descriptor Error Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_CDEE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_INTERRUPT_ENABLE_CDEE_SHIFT)) & EMAC_DMA_CH0_INTERRUPT_ENABLE_CDEE_MASK)

#define EMAC_DMA_CH0_INTERRUPT_ENABLE_AIE_MASK   (0x4000U)
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_AIE_SHIFT  (14U)
/*! AIE - Abnormal Interrupt Summary Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_AIE(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_INTERRUPT_ENABLE_AIE_SHIFT)) & EMAC_DMA_CH0_INTERRUPT_ENABLE_AIE_MASK)

#define EMAC_DMA_CH0_INTERRUPT_ENABLE_NIE_MASK   (0x8000U)
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_NIE_SHIFT  (15U)
/*! NIE - Normal Interrupt Summary Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH0_INTERRUPT_ENABLE_NIE(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_INTERRUPT_ENABLE_NIE_SHIFT)) & EMAC_DMA_CH0_INTERRUPT_ENABLE_NIE_MASK)
/*! @} */

/*! @name DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER - DMA Channel 0 Rx Interrupt Watchdog Timer */
/*! @{ */

#define EMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK (0xFFU)
#define EMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWT_SHIFT (0U)
/*! RWT - Receive Interrupt Watchdog Timer Count */
#define EMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWT(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWT_SHIFT)) & EMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK)

#define EMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK (0x30000U)
#define EMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_SHIFT (16U)
/*! RWTU - Receive Interrupt Watchdog Timer Count Units */
#define EMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWTU(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_SHIFT)) & EMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK)
/*! @} */

/*! @name DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS - DMA Channel 0 Slot Function Control Status */
/*! @{ */

#define EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK (0x1U)
#define EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ESC_SHIFT (0U)
/*! ESC - Enable Slot Comparison
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ESC(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ESC_SHIFT)) & EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK)

#define EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK (0x2U)
#define EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ASC_SHIFT (1U)
/*! ASC - Advance Slot Check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ASC(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ASC_SHIFT)) & EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK)

#define EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_SIV_MASK (0xFFF0U)
#define EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_SIV_SHIFT (4U)
/*! SIV - Slot Interval Value */
#define EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_SIV(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_SIV_SHIFT)) & EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_SIV_MASK)

#define EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK (0xF0000U)
#define EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_RSN_SHIFT (16U)
/*! RSN - Reference Slot Number */
#define EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_RSN(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_RSN_SHIFT)) & EMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK)
/*! @} */

/*! @name DMA_CH0_CURRENT_APP_TXDESC - DMA Channel 0 Current Application Transmit Descriptor */
/*! @{ */

#define EMAC_DMA_CH0_CURRENT_APP_TXDESC_CURTDESAPTR_MASK (0xFFFFFFFFU)
#define EMAC_DMA_CH0_CURRENT_APP_TXDESC_CURTDESAPTR_SHIFT (0U)
/*! CURTDESAPTR - Application Transmit Descriptor Address Pointer */
#define EMAC_DMA_CH0_CURRENT_APP_TXDESC_CURTDESAPTR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_CURRENT_APP_TXDESC_CURTDESAPTR_SHIFT)) & EMAC_DMA_CH0_CURRENT_APP_TXDESC_CURTDESAPTR_MASK)
/*! @} */

/*! @name DMA_CH0_CURRENT_APP_RXDESC - DMA Channel 0 Current Application Receive Descriptor */
/*! @{ */

#define EMAC_DMA_CH0_CURRENT_APP_RXDESC_CURRDESAPTR_MASK (0xFFFFFFFFU)
#define EMAC_DMA_CH0_CURRENT_APP_RXDESC_CURRDESAPTR_SHIFT (0U)
/*! CURRDESAPTR - Application Receive Descriptor Address Pointer */
#define EMAC_DMA_CH0_CURRENT_APP_RXDESC_CURRDESAPTR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_CURRENT_APP_RXDESC_CURRDESAPTR_SHIFT)) & EMAC_DMA_CH0_CURRENT_APP_RXDESC_CURRDESAPTR_MASK)
/*! @} */

/*! @name DMA_CH0_CURRENT_APP_TXBUFFER - DMA Channel 0 Current Application Transmit Descriptor */
/*! @{ */

#define EMAC_DMA_CH0_CURRENT_APP_TXBUFFER_CURTBUFAPTR_MASK (0xFFFFFFFFU)
#define EMAC_DMA_CH0_CURRENT_APP_TXBUFFER_CURTBUFAPTR_SHIFT (0U)
/*! CURTBUFAPTR - Application Transmit Buffer Address Pointer */
#define EMAC_DMA_CH0_CURRENT_APP_TXBUFFER_CURTBUFAPTR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_CURRENT_APP_TXBUFFER_CURTBUFAPTR_SHIFT)) & EMAC_DMA_CH0_CURRENT_APP_TXBUFFER_CURTBUFAPTR_MASK)
/*! @} */

/*! @name DMA_CH0_CURRENT_APP_RXBUFFER - DMA Channel 0 Current Application Receive Buffer */
/*! @{ */

#define EMAC_DMA_CH0_CURRENT_APP_RXBUFFER_CURRBUFAPTR_MASK (0xFFFFFFFFU)
#define EMAC_DMA_CH0_CURRENT_APP_RXBUFFER_CURRBUFAPTR_SHIFT (0U)
/*! CURRBUFAPTR - Application Receive Buffer Address Pointer */
#define EMAC_DMA_CH0_CURRENT_APP_RXBUFFER_CURRBUFAPTR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_CURRENT_APP_RXBUFFER_CURRBUFAPTR_SHIFT)) & EMAC_DMA_CH0_CURRENT_APP_RXBUFFER_CURRBUFAPTR_MASK)
/*! @} */

/*! @name DMA_CH0_STATUS - DMA Channel 0 Status */
/*! @{ */

#define EMAC_DMA_CH0_STATUS_TI_MASK              (0x1U)
#define EMAC_DMA_CH0_STATUS_TI_SHIFT             (0U)
/*! TI - Transmit Interrupt
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH0_STATUS_TI(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_TI_SHIFT)) & EMAC_DMA_CH0_STATUS_TI_MASK)

#define EMAC_DMA_CH0_STATUS_TPS_MASK             (0x2U)
#define EMAC_DMA_CH0_STATUS_TPS_SHIFT            (1U)
/*! TPS - Transmit Process Stopped
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH0_STATUS_TPS(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_TPS_SHIFT)) & EMAC_DMA_CH0_STATUS_TPS_MASK)

#define EMAC_DMA_CH0_STATUS_TBU_MASK             (0x4U)
#define EMAC_DMA_CH0_STATUS_TBU_SHIFT            (2U)
/*! TBU - Transmit Buffer Unavailable
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH0_STATUS_TBU(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_TBU_SHIFT)) & EMAC_DMA_CH0_STATUS_TBU_MASK)

#define EMAC_DMA_CH0_STATUS_RI_MASK              (0x40U)
#define EMAC_DMA_CH0_STATUS_RI_SHIFT             (6U)
/*! RI - Receive Interrupt
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH0_STATUS_RI(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_RI_SHIFT)) & EMAC_DMA_CH0_STATUS_RI_MASK)

#define EMAC_DMA_CH0_STATUS_RBU_MASK             (0x80U)
#define EMAC_DMA_CH0_STATUS_RBU_SHIFT            (7U)
/*! RBU - Receive Buffer Unavailable
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH0_STATUS_RBU(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_RBU_SHIFT)) & EMAC_DMA_CH0_STATUS_RBU_MASK)

#define EMAC_DMA_CH0_STATUS_RPS_MASK             (0x100U)
#define EMAC_DMA_CH0_STATUS_RPS_SHIFT            (8U)
/*! RPS - Receive Process Stopped
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH0_STATUS_RPS(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_RPS_SHIFT)) & EMAC_DMA_CH0_STATUS_RPS_MASK)

#define EMAC_DMA_CH0_STATUS_RWT_MASK             (0x200U)
#define EMAC_DMA_CH0_STATUS_RWT_SHIFT            (9U)
/*! RWT - Receive Watchdog Timeout
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH0_STATUS_RWT(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_RWT_SHIFT)) & EMAC_DMA_CH0_STATUS_RWT_MASK)

#define EMAC_DMA_CH0_STATUS_ETI_MASK             (0x400U)
#define EMAC_DMA_CH0_STATUS_ETI_SHIFT            (10U)
/*! ETI - Early Transmit Interrupt
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH0_STATUS_ETI(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_ETI_SHIFT)) & EMAC_DMA_CH0_STATUS_ETI_MASK)

#define EMAC_DMA_CH0_STATUS_ERI_MASK             (0x800U)
#define EMAC_DMA_CH0_STATUS_ERI_SHIFT            (11U)
/*! ERI - Early Receive Interrupt
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH0_STATUS_ERI(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_ERI_SHIFT)) & EMAC_DMA_CH0_STATUS_ERI_MASK)

#define EMAC_DMA_CH0_STATUS_FBE_MASK             (0x1000U)
#define EMAC_DMA_CH0_STATUS_FBE_SHIFT            (12U)
/*! FBE - Fatal Bus Error
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH0_STATUS_FBE(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_FBE_SHIFT)) & EMAC_DMA_CH0_STATUS_FBE_MASK)

#define EMAC_DMA_CH0_STATUS_CDE_MASK             (0x2000U)
#define EMAC_DMA_CH0_STATUS_CDE_SHIFT            (13U)
/*! CDE - Context Descriptor Error
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH0_STATUS_CDE(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_CDE_SHIFT)) & EMAC_DMA_CH0_STATUS_CDE_MASK)

#define EMAC_DMA_CH0_STATUS_AIS_MASK             (0x4000U)
#define EMAC_DMA_CH0_STATUS_AIS_SHIFT            (14U)
/*! AIS - Abnormal Interrupt Summary
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH0_STATUS_AIS(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_AIS_SHIFT)) & EMAC_DMA_CH0_STATUS_AIS_MASK)

#define EMAC_DMA_CH0_STATUS_NIS_MASK             (0x8000U)
#define EMAC_DMA_CH0_STATUS_NIS_SHIFT            (15U)
/*! NIS - Normal Interrupt Summary
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH0_STATUS_NIS(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_NIS_SHIFT)) & EMAC_DMA_CH0_STATUS_NIS_MASK)

#define EMAC_DMA_CH0_STATUS_TEB_MASK             (0x70000U)
#define EMAC_DMA_CH0_STATUS_TEB_SHIFT            (16U)
/*! TEB - Tx DMA Error Bits */
#define EMAC_DMA_CH0_STATUS_TEB(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_TEB_SHIFT)) & EMAC_DMA_CH0_STATUS_TEB_MASK)

#define EMAC_DMA_CH0_STATUS_REB_MASK             (0x380000U)
#define EMAC_DMA_CH0_STATUS_REB_SHIFT            (19U)
/*! REB - Rx DMA Error Bits */
#define EMAC_DMA_CH0_STATUS_REB(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_STATUS_REB_SHIFT)) & EMAC_DMA_CH0_STATUS_REB_MASK)
/*! @} */

/*! @name DMA_CH0_MISS_FRAME_CNT - DMA Channel 0 Miss Frame Counter */
/*! @{ */

#define EMAC_DMA_CH0_MISS_FRAME_CNT_MFC_MASK     (0x7FFU)
#define EMAC_DMA_CH0_MISS_FRAME_CNT_MFC_SHIFT    (0U)
#define EMAC_DMA_CH0_MISS_FRAME_CNT_MFC(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_MISS_FRAME_CNT_MFC_SHIFT)) & EMAC_DMA_CH0_MISS_FRAME_CNT_MFC_MASK)

#define EMAC_DMA_CH0_MISS_FRAME_CNT_MFCO_MASK    (0x8000U)
#define EMAC_DMA_CH0_MISS_FRAME_CNT_MFCO_SHIFT   (15U)
/*! MFCO - Overflow status of the MFC Counter
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define EMAC_DMA_CH0_MISS_FRAME_CNT_MFCO(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_MISS_FRAME_CNT_MFCO_SHIFT)) & EMAC_DMA_CH0_MISS_FRAME_CNT_MFCO_MASK)
/*! @} */

/*! @name DMA_CH0_RXP_ACCEPT_CNT - DMA Channel 0 Rx Parser Accept Count */
/*! @{ */

#define EMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPAC_MASK   (0x7FFFFFFFU)
#define EMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPAC_SHIFT  (0U)
/*! RXPAC - Rx Parser Accept Counter */
#define EMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPAC(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPAC_SHIFT)) & EMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPAC_MASK)

#define EMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPACOF_MASK (0x80000000U)
#define EMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPACOF_SHIFT (31U)
/*! RXPACOF - Rx Parser Accept Counter Overflow Bit
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define EMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPACOF(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPACOF_SHIFT)) & EMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPACOF_MASK)
/*! @} */

/*! @name DMA_CH0_RX_ERI_CNT - DMA Channel 0 Rx ERI Count */
/*! @{ */

#define EMAC_DMA_CH0_RX_ERI_CNT_ECNT_MASK        (0xFFFU)
#define EMAC_DMA_CH0_RX_ERI_CNT_ECNT_SHIFT       (0U)
/*! ECNT - ERI Counter */
#define EMAC_DMA_CH0_RX_ERI_CNT_ECNT(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH0_RX_ERI_CNT_ECNT_SHIFT)) & EMAC_DMA_CH0_RX_ERI_CNT_ECNT_MASK)
/*! @} */

/*! @name DMA_CH1_CONTROL - DMA Channel 1 Control */
/*! @{ */

#define EMAC_DMA_CH1_CONTROL_PBLx8_MASK          (0x10000U)
#define EMAC_DMA_CH1_CONTROL_PBLx8_SHIFT         (16U)
/*! PBLx8 - 8xPBL mode
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH1_CONTROL_PBLx8(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_CONTROL_PBLx8_SHIFT)) & EMAC_DMA_CH1_CONTROL_PBLx8_MASK)

#define EMAC_DMA_CH1_CONTROL_DSL_MASK            (0x1C0000U)
#define EMAC_DMA_CH1_CONTROL_DSL_SHIFT           (18U)
/*! DSL - Descriptor Skip Length */
#define EMAC_DMA_CH1_CONTROL_DSL(x)              (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_CONTROL_DSL_SHIFT)) & EMAC_DMA_CH1_CONTROL_DSL_MASK)
/*! @} */

/*! @name DMA_CH1_TX_CONTROL - DMA Channel 1 Tx Control */
/*! @{ */

#define EMAC_DMA_CH1_TX_CONTROL_ST_MASK          (0x1U)
#define EMAC_DMA_CH1_TX_CONTROL_ST_SHIFT         (0U)
/*! ST - Start or Stop Transmission Command
 *  0b0..Stop
 *  0b1..Start
 */
#define EMAC_DMA_CH1_TX_CONTROL_ST(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_TX_CONTROL_ST_SHIFT)) & EMAC_DMA_CH1_TX_CONTROL_ST_MASK)

#define EMAC_DMA_CH1_TX_CONTROL_TCW_MASK         (0xEU)
#define EMAC_DMA_CH1_TX_CONTROL_TCW_SHIFT        (1U)
/*! TCW - Transmit Channel Weight */
#define EMAC_DMA_CH1_TX_CONTROL_TCW(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_TX_CONTROL_TCW_SHIFT)) & EMAC_DMA_CH1_TX_CONTROL_TCW_MASK)

#define EMAC_DMA_CH1_TX_CONTROL_OSF_MASK         (0x10U)
#define EMAC_DMA_CH1_TX_CONTROL_OSF_SHIFT        (4U)
/*! OSF - Operate on Second Packet
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH1_TX_CONTROL_OSF(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_TX_CONTROL_OSF_SHIFT)) & EMAC_DMA_CH1_TX_CONTROL_OSF_MASK)

#define EMAC_DMA_CH1_TX_CONTROL_TxPBL_MASK       (0x3F0000U)
#define EMAC_DMA_CH1_TX_CONTROL_TxPBL_SHIFT      (16U)
/*! TxPBL - Transmit Programmable Burst Length */
#define EMAC_DMA_CH1_TX_CONTROL_TxPBL(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_TX_CONTROL_TxPBL_SHIFT)) & EMAC_DMA_CH1_TX_CONTROL_TxPBL_MASK)

#define EMAC_DMA_CH1_TX_CONTROL_ETIC_MASK        (0x400000U)
#define EMAC_DMA_CH1_TX_CONTROL_ETIC_SHIFT       (22U)
/*! ETIC - Early Transmit Interrupt Control
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH1_TX_CONTROL_ETIC(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_TX_CONTROL_ETIC_SHIFT)) & EMAC_DMA_CH1_TX_CONTROL_ETIC_MASK)

#define EMAC_DMA_CH1_TX_CONTROL_EDSE_MASK        (0x10000000U)
#define EMAC_DMA_CH1_TX_CONTROL_EDSE_SHIFT       (28U)
/*! EDSE - Enhanced Descriptor Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH1_TX_CONTROL_EDSE(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_TX_CONTROL_EDSE_SHIFT)) & EMAC_DMA_CH1_TX_CONTROL_EDSE_MASK)
/*! @} */

/*! @name DMA_CH1_RX_CONTROL - DMA Channel 1 Rx Control */
/*! @{ */

#define EMAC_DMA_CH1_RX_CONTROL_SR_MASK          (0x1U)
#define EMAC_DMA_CH1_RX_CONTROL_SR_SHIFT         (0U)
/*! SR - Start or Stop Receive
 *  0b0..Stop
 *  0b1..Start
 */
#define EMAC_DMA_CH1_RX_CONTROL_SR(x)            (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_RX_CONTROL_SR_SHIFT)) & EMAC_DMA_CH1_RX_CONTROL_SR_MASK)

#define EMAC_DMA_CH1_RX_CONTROL_RBSZ_x_0_MASK    (0x6U)
#define EMAC_DMA_CH1_RX_CONTROL_RBSZ_x_0_SHIFT   (1U)
/*! RBSZ_x_0 - Receive Buffer size Low */
#define EMAC_DMA_CH1_RX_CONTROL_RBSZ_x_0(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_RX_CONTROL_RBSZ_x_0_SHIFT)) & EMAC_DMA_CH1_RX_CONTROL_RBSZ_x_0_MASK)

#define EMAC_DMA_CH1_RX_CONTROL_RBSZ_13_y_MASK   (0x7FF8U)
#define EMAC_DMA_CH1_RX_CONTROL_RBSZ_13_y_SHIFT  (3U)
/*! RBSZ_13_y - Receive Buffer size High */
#define EMAC_DMA_CH1_RX_CONTROL_RBSZ_13_y(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_RX_CONTROL_RBSZ_13_y_SHIFT)) & EMAC_DMA_CH1_RX_CONTROL_RBSZ_13_y_MASK)

#define EMAC_DMA_CH1_RX_CONTROL_RxPBL_MASK       (0x3F0000U)
#define EMAC_DMA_CH1_RX_CONTROL_RxPBL_SHIFT      (16U)
/*! RxPBL - Receive Programmable Burst Length */
#define EMAC_DMA_CH1_RX_CONTROL_RxPBL(x)         (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_RX_CONTROL_RxPBL_SHIFT)) & EMAC_DMA_CH1_RX_CONTROL_RxPBL_MASK)

#define EMAC_DMA_CH1_RX_CONTROL_ERIC_MASK        (0x400000U)
#define EMAC_DMA_CH1_RX_CONTROL_ERIC_SHIFT       (22U)
/*! ERIC - Early Receive Interrupt Control
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH1_RX_CONTROL_ERIC(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_RX_CONTROL_ERIC_SHIFT)) & EMAC_DMA_CH1_RX_CONTROL_ERIC_MASK)

#define EMAC_DMA_CH1_RX_CONTROL_RPF_MASK         (0x80000000U)
#define EMAC_DMA_CH1_RX_CONTROL_RPF_SHIFT        (31U)
/*! RPF - Rx Packet Flush
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH1_RX_CONTROL_RPF(x)           (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_RX_CONTROL_RPF_SHIFT)) & EMAC_DMA_CH1_RX_CONTROL_RPF_MASK)
/*! @} */

/*! @name DMA_CH1_TXDESC_LIST_ADDRESS - DMA Channel 1 Tx Descriptor List Address */
/*! @{ */

#define EMAC_DMA_CH1_TXDESC_LIST_ADDRESS_TDESLA_MASK (0xFFFFFFFCU)
#define EMAC_DMA_CH1_TXDESC_LIST_ADDRESS_TDESLA_SHIFT (2U)
/*! TDESLA - Start of Transmit List */
#define EMAC_DMA_CH1_TXDESC_LIST_ADDRESS_TDESLA(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_TXDESC_LIST_ADDRESS_TDESLA_SHIFT)) & EMAC_DMA_CH1_TXDESC_LIST_ADDRESS_TDESLA_MASK)
/*! @} */

/*! @name DMA_CH1_RXDESC_LIST_ADDRESS - DMA Channel 1 Rx Descriptor List Address */
/*! @{ */

#define EMAC_DMA_CH1_RXDESC_LIST_ADDRESS_RDESLA_MASK (0xFFFFFFFCU)
#define EMAC_DMA_CH1_RXDESC_LIST_ADDRESS_RDESLA_SHIFT (2U)
/*! RDESLA - Start of Receive List */
#define EMAC_DMA_CH1_RXDESC_LIST_ADDRESS_RDESLA(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_RXDESC_LIST_ADDRESS_RDESLA_SHIFT)) & EMAC_DMA_CH1_RXDESC_LIST_ADDRESS_RDESLA_MASK)
/*! @} */

/*! @name DMA_CH1_TXDESC_TAIL_POINTER - DMA Channel 1 Tx Descriptor Tail Pointer */
/*! @{ */

#define EMAC_DMA_CH1_TXDESC_TAIL_POINTER_TDTP_MASK (0xFFFFFFFCU)
#define EMAC_DMA_CH1_TXDESC_TAIL_POINTER_TDTP_SHIFT (2U)
/*! TDTP - Transmit Descriptor Tail Pointer */
#define EMAC_DMA_CH1_TXDESC_TAIL_POINTER_TDTP(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_TXDESC_TAIL_POINTER_TDTP_SHIFT)) & EMAC_DMA_CH1_TXDESC_TAIL_POINTER_TDTP_MASK)
/*! @} */

/*! @name DMA_CH1_RXDESC_TAIL_POINTER - DMA Channel 1 Rx Descriptor Tail Pointer */
/*! @{ */

#define EMAC_DMA_CH1_RXDESC_TAIL_POINTER_RDTP_MASK (0xFFFFFFFCU)
#define EMAC_DMA_CH1_RXDESC_TAIL_POINTER_RDTP_SHIFT (2U)
/*! RDTP - Receive Descriptor Tail Pointer */
#define EMAC_DMA_CH1_RXDESC_TAIL_POINTER_RDTP(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_RXDESC_TAIL_POINTER_RDTP_SHIFT)) & EMAC_DMA_CH1_RXDESC_TAIL_POINTER_RDTP_MASK)
/*! @} */

/*! @name DMA_CH1_TXDESC_RING_LENGTH - DMA Channel 1 Tx Descriptor Ring Length */
/*! @{ */

#define EMAC_DMA_CH1_TXDESC_RING_LENGTH_TDRL_MASK (0x3FFU)
#define EMAC_DMA_CH1_TXDESC_RING_LENGTH_TDRL_SHIFT (0U)
/*! TDRL - Transmit Descriptor Ring Length */
#define EMAC_DMA_CH1_TXDESC_RING_LENGTH_TDRL(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_TXDESC_RING_LENGTH_TDRL_SHIFT)) & EMAC_DMA_CH1_TXDESC_RING_LENGTH_TDRL_MASK)
/*! @} */

/*! @name DMA_CH1_RXDESC_RING_LENGTH - DMA Channel 1 Rx Descriptor Ring Length */
/*! @{ */

#define EMAC_DMA_CH1_RXDESC_RING_LENGTH_RDRL_MASK (0x3FFU)
#define EMAC_DMA_CH1_RXDESC_RING_LENGTH_RDRL_SHIFT (0U)
/*! RDRL - Receive Descriptor Ring Length */
#define EMAC_DMA_CH1_RXDESC_RING_LENGTH_RDRL(x)  (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_RXDESC_RING_LENGTH_RDRL_SHIFT)) & EMAC_DMA_CH1_RXDESC_RING_LENGTH_RDRL_MASK)
/*! @} */

/*! @name DMA_CH1_INTERRUPT_ENABLE - DMA Channel 1 Interrupt Enable */
/*! @{ */

#define EMAC_DMA_CH1_INTERRUPT_ENABLE_TIE_MASK   (0x1U)
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_TIE_SHIFT  (0U)
/*! TIE - Transmit Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_TIE(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_INTERRUPT_ENABLE_TIE_SHIFT)) & EMAC_DMA_CH1_INTERRUPT_ENABLE_TIE_MASK)

#define EMAC_DMA_CH1_INTERRUPT_ENABLE_TXSE_MASK  (0x2U)
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_TXSE_SHIFT (1U)
/*! TXSE - Transmit Stopped Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_TXSE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_INTERRUPT_ENABLE_TXSE_SHIFT)) & EMAC_DMA_CH1_INTERRUPT_ENABLE_TXSE_MASK)

#define EMAC_DMA_CH1_INTERRUPT_ENABLE_TBUE_MASK  (0x4U)
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_TBUE_SHIFT (2U)
/*! TBUE - Transmit Buffer Unavailable Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_TBUE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_INTERRUPT_ENABLE_TBUE_SHIFT)) & EMAC_DMA_CH1_INTERRUPT_ENABLE_TBUE_MASK)

#define EMAC_DMA_CH1_INTERRUPT_ENABLE_RIE_MASK   (0x40U)
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_RIE_SHIFT  (6U)
/*! RIE - Receive Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_RIE(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_INTERRUPT_ENABLE_RIE_SHIFT)) & EMAC_DMA_CH1_INTERRUPT_ENABLE_RIE_MASK)

#define EMAC_DMA_CH1_INTERRUPT_ENABLE_RBUE_MASK  (0x80U)
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_RBUE_SHIFT (7U)
/*! RBUE - Receive Buffer Unavailable Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_RBUE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_INTERRUPT_ENABLE_RBUE_SHIFT)) & EMAC_DMA_CH1_INTERRUPT_ENABLE_RBUE_MASK)

#define EMAC_DMA_CH1_INTERRUPT_ENABLE_RSE_MASK   (0x100U)
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_RSE_SHIFT  (8U)
/*! RSE - Receive Stopped Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_RSE(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_INTERRUPT_ENABLE_RSE_SHIFT)) & EMAC_DMA_CH1_INTERRUPT_ENABLE_RSE_MASK)

#define EMAC_DMA_CH1_INTERRUPT_ENABLE_RWTE_MASK  (0x200U)
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_RWTE_SHIFT (9U)
/*! RWTE - Receive Watchdog Timeout Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_RWTE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_INTERRUPT_ENABLE_RWTE_SHIFT)) & EMAC_DMA_CH1_INTERRUPT_ENABLE_RWTE_MASK)

#define EMAC_DMA_CH1_INTERRUPT_ENABLE_ETIE_MASK  (0x400U)
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_ETIE_SHIFT (10U)
/*! ETIE - Early Transmit Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_ETIE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_INTERRUPT_ENABLE_ETIE_SHIFT)) & EMAC_DMA_CH1_INTERRUPT_ENABLE_ETIE_MASK)

#define EMAC_DMA_CH1_INTERRUPT_ENABLE_ERIE_MASK  (0x800U)
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_ERIE_SHIFT (11U)
/*! ERIE - Early Receive Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_ERIE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_INTERRUPT_ENABLE_ERIE_SHIFT)) & EMAC_DMA_CH1_INTERRUPT_ENABLE_ERIE_MASK)

#define EMAC_DMA_CH1_INTERRUPT_ENABLE_FBEE_MASK  (0x1000U)
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_FBEE_SHIFT (12U)
/*! FBEE - Fatal Bus Error Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_FBEE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_INTERRUPT_ENABLE_FBEE_SHIFT)) & EMAC_DMA_CH1_INTERRUPT_ENABLE_FBEE_MASK)

#define EMAC_DMA_CH1_INTERRUPT_ENABLE_CDEE_MASK  (0x2000U)
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_CDEE_SHIFT (13U)
/*! CDEE - Context Descriptor Error Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_CDEE(x)    (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_INTERRUPT_ENABLE_CDEE_SHIFT)) & EMAC_DMA_CH1_INTERRUPT_ENABLE_CDEE_MASK)

#define EMAC_DMA_CH1_INTERRUPT_ENABLE_AIE_MASK   (0x4000U)
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_AIE_SHIFT  (14U)
/*! AIE - Abnormal Interrupt Summary Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_AIE(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_INTERRUPT_ENABLE_AIE_SHIFT)) & EMAC_DMA_CH1_INTERRUPT_ENABLE_AIE_MASK)

#define EMAC_DMA_CH1_INTERRUPT_ENABLE_NIE_MASK   (0x8000U)
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_NIE_SHIFT  (15U)
/*! NIE - Normal Interrupt Summary Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH1_INTERRUPT_ENABLE_NIE(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_INTERRUPT_ENABLE_NIE_SHIFT)) & EMAC_DMA_CH1_INTERRUPT_ENABLE_NIE_MASK)
/*! @} */

/*! @name DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER - DMA Channel 1 Rx Interrupt Watchdog Timer */
/*! @{ */

#define EMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK (0xFFU)
#define EMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWT_SHIFT (0U)
/*! RWT - Receive Interrupt Watchdog Timer Count */
#define EMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWT(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWT_SHIFT)) & EMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK)

#define EMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK (0x30000U)
#define EMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_SHIFT (16U)
/*! RWTU - Receive Interrupt Watchdog Timer Count Units */
#define EMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWTU(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_SHIFT)) & EMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK)
/*! @} */

/*! @name DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS - DMA Channel 1 Slot Function Control Status */
/*! @{ */

#define EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK (0x1U)
#define EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ESC_SHIFT (0U)
/*! ESC - Enable Slot Comparison
 *  0b0..Disable
 *  0b1..Enable
 */
#define EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ESC(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ESC_SHIFT)) & EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK)

#define EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK (0x2U)
#define EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ASC_SHIFT (1U)
/*! ASC - Advance Slot Check
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ASC(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ASC_SHIFT)) & EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK)

#define EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_SIV_MASK (0xFFF0U)
#define EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_SIV_SHIFT (4U)
/*! SIV - Slot Interval Value */
#define EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_SIV(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_SIV_SHIFT)) & EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_SIV_MASK)

#define EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK (0xF0000U)
#define EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_RSN_SHIFT (16U)
/*! RSN - Reference Slot Number */
#define EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_RSN(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_RSN_SHIFT)) & EMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK)
/*! @} */

/*! @name DMA_CH1_CURRENT_APP_TXDESC - DMA Channel 1 Current Application Transmit Descriptor */
/*! @{ */

#define EMAC_DMA_CH1_CURRENT_APP_TXDESC_CURTDESAPTR_MASK (0xFFFFFFFFU)
#define EMAC_DMA_CH1_CURRENT_APP_TXDESC_CURTDESAPTR_SHIFT (0U)
/*! CURTDESAPTR - Application Transmit Descriptor Address Pointer */
#define EMAC_DMA_CH1_CURRENT_APP_TXDESC_CURTDESAPTR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_CURRENT_APP_TXDESC_CURTDESAPTR_SHIFT)) & EMAC_DMA_CH1_CURRENT_APP_TXDESC_CURTDESAPTR_MASK)
/*! @} */

/*! @name DMA_CH1_CURRENT_APP_RXDESC - DMA Channel 1 Current Application Receive Descriptor */
/*! @{ */

#define EMAC_DMA_CH1_CURRENT_APP_RXDESC_CURRDESAPTR_MASK (0xFFFFFFFFU)
#define EMAC_DMA_CH1_CURRENT_APP_RXDESC_CURRDESAPTR_SHIFT (0U)
/*! CURRDESAPTR - Application Receive Descriptor Address Pointer */
#define EMAC_DMA_CH1_CURRENT_APP_RXDESC_CURRDESAPTR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_CURRENT_APP_RXDESC_CURRDESAPTR_SHIFT)) & EMAC_DMA_CH1_CURRENT_APP_RXDESC_CURRDESAPTR_MASK)
/*! @} */

/*! @name DMA_CH1_CURRENT_APP_TXBUFFER - DMA Channel 1 Current Application Transmit Buffer */
/*! @{ */

#define EMAC_DMA_CH1_CURRENT_APP_TXBUFFER_CURTBUFAPTR_MASK (0xFFFFFFFFU)
#define EMAC_DMA_CH1_CURRENT_APP_TXBUFFER_CURTBUFAPTR_SHIFT (0U)
/*! CURTBUFAPTR - Application Transmit Buffer Address Pointer */
#define EMAC_DMA_CH1_CURRENT_APP_TXBUFFER_CURTBUFAPTR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_CURRENT_APP_TXBUFFER_CURTBUFAPTR_SHIFT)) & EMAC_DMA_CH1_CURRENT_APP_TXBUFFER_CURTBUFAPTR_MASK)
/*! @} */

/*! @name DMA_CH1_CURRENT_APP_RXBUFFER - DMA Channel 1 Current Application Receive Buffer */
/*! @{ */

#define EMAC_DMA_CH1_CURRENT_APP_RXBUFFER_CURRBUFAPTR_MASK (0xFFFFFFFFU)
#define EMAC_DMA_CH1_CURRENT_APP_RXBUFFER_CURRBUFAPTR_SHIFT (0U)
/*! CURRBUFAPTR - Application Receive Buffer Address Pointer */
#define EMAC_DMA_CH1_CURRENT_APP_RXBUFFER_CURRBUFAPTR(x) (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_CURRENT_APP_RXBUFFER_CURRBUFAPTR_SHIFT)) & EMAC_DMA_CH1_CURRENT_APP_RXBUFFER_CURRBUFAPTR_MASK)
/*! @} */

/*! @name DMA_CH1_STATUS - DMA Channel 1 Status */
/*! @{ */

#define EMAC_DMA_CH1_STATUS_TI_MASK              (0x1U)
#define EMAC_DMA_CH1_STATUS_TI_SHIFT             (0U)
/*! TI - Transmit Interrupt
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH1_STATUS_TI(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_TI_SHIFT)) & EMAC_DMA_CH1_STATUS_TI_MASK)

#define EMAC_DMA_CH1_STATUS_TPS_MASK             (0x2U)
#define EMAC_DMA_CH1_STATUS_TPS_SHIFT            (1U)
/*! TPS - Transmit Process Stopped
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH1_STATUS_TPS(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_TPS_SHIFT)) & EMAC_DMA_CH1_STATUS_TPS_MASK)

#define EMAC_DMA_CH1_STATUS_TBU_MASK             (0x4U)
#define EMAC_DMA_CH1_STATUS_TBU_SHIFT            (2U)
/*! TBU - Transmit Buffer Unavailable
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH1_STATUS_TBU(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_TBU_SHIFT)) & EMAC_DMA_CH1_STATUS_TBU_MASK)

#define EMAC_DMA_CH1_STATUS_RI_MASK              (0x40U)
#define EMAC_DMA_CH1_STATUS_RI_SHIFT             (6U)
/*! RI - Receive Interrupt
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH1_STATUS_RI(x)                (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_RI_SHIFT)) & EMAC_DMA_CH1_STATUS_RI_MASK)

#define EMAC_DMA_CH1_STATUS_RBU_MASK             (0x80U)
#define EMAC_DMA_CH1_STATUS_RBU_SHIFT            (7U)
/*! RBU - Receive Buffer Unavailable
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH1_STATUS_RBU(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_RBU_SHIFT)) & EMAC_DMA_CH1_STATUS_RBU_MASK)

#define EMAC_DMA_CH1_STATUS_RPS_MASK             (0x100U)
#define EMAC_DMA_CH1_STATUS_RPS_SHIFT            (8U)
/*! RPS - Receive Process Stopped
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH1_STATUS_RPS(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_RPS_SHIFT)) & EMAC_DMA_CH1_STATUS_RPS_MASK)

#define EMAC_DMA_CH1_STATUS_RWT_MASK             (0x200U)
#define EMAC_DMA_CH1_STATUS_RWT_SHIFT            (9U)
/*! RWT - Receive Watchdog Timeout
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH1_STATUS_RWT(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_RWT_SHIFT)) & EMAC_DMA_CH1_STATUS_RWT_MASK)

#define EMAC_DMA_CH1_STATUS_ETI_MASK             (0x400U)
#define EMAC_DMA_CH1_STATUS_ETI_SHIFT            (10U)
/*! ETI - Early Transmit Interrupt
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH1_STATUS_ETI(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_ETI_SHIFT)) & EMAC_DMA_CH1_STATUS_ETI_MASK)

#define EMAC_DMA_CH1_STATUS_ERI_MASK             (0x800U)
#define EMAC_DMA_CH1_STATUS_ERI_SHIFT            (11U)
/*! ERI - Early Receive Interrupt
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH1_STATUS_ERI(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_ERI_SHIFT)) & EMAC_DMA_CH1_STATUS_ERI_MASK)

#define EMAC_DMA_CH1_STATUS_FBE_MASK             (0x1000U)
#define EMAC_DMA_CH1_STATUS_FBE_SHIFT            (12U)
/*! FBE - Fatal Bus Error
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH1_STATUS_FBE(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_FBE_SHIFT)) & EMAC_DMA_CH1_STATUS_FBE_MASK)

#define EMAC_DMA_CH1_STATUS_CDE_MASK             (0x2000U)
#define EMAC_DMA_CH1_STATUS_CDE_SHIFT            (13U)
/*! CDE - Context Descriptor Error
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH1_STATUS_CDE(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_CDE_SHIFT)) & EMAC_DMA_CH1_STATUS_CDE_MASK)

#define EMAC_DMA_CH1_STATUS_AIS_MASK             (0x4000U)
#define EMAC_DMA_CH1_STATUS_AIS_SHIFT            (14U)
/*! AIS - Abnormal Interrupt Summary
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH1_STATUS_AIS(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_AIS_SHIFT)) & EMAC_DMA_CH1_STATUS_AIS_MASK)

#define EMAC_DMA_CH1_STATUS_NIS_MASK             (0x8000U)
#define EMAC_DMA_CH1_STATUS_NIS_SHIFT            (15U)
/*! NIS - Normal Interrupt Summary
 *  0b0..Not detected
 *  0b1..Detected
 */
#define EMAC_DMA_CH1_STATUS_NIS(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_NIS_SHIFT)) & EMAC_DMA_CH1_STATUS_NIS_MASK)

#define EMAC_DMA_CH1_STATUS_TEB_MASK             (0x70000U)
#define EMAC_DMA_CH1_STATUS_TEB_SHIFT            (16U)
/*! TEB - Tx DMA Error Bits */
#define EMAC_DMA_CH1_STATUS_TEB(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_TEB_SHIFT)) & EMAC_DMA_CH1_STATUS_TEB_MASK)

#define EMAC_DMA_CH1_STATUS_REB_MASK             (0x380000U)
#define EMAC_DMA_CH1_STATUS_REB_SHIFT            (19U)
/*! REB - Rx DMA Error Bits */
#define EMAC_DMA_CH1_STATUS_REB(x)               (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_STATUS_REB_SHIFT)) & EMAC_DMA_CH1_STATUS_REB_MASK)
/*! @} */

/*! @name DMA_CH1_MISS_FRAME_CNT - DMA Channel 1 Miss Frame Counter */
/*! @{ */

#define EMAC_DMA_CH1_MISS_FRAME_CNT_MFC_MASK     (0x7FFU)
#define EMAC_DMA_CH1_MISS_FRAME_CNT_MFC_SHIFT    (0U)
/*! MFC - Dropped Packet Counters */
#define EMAC_DMA_CH1_MISS_FRAME_CNT_MFC(x)       (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_MISS_FRAME_CNT_MFC_SHIFT)) & EMAC_DMA_CH1_MISS_FRAME_CNT_MFC_MASK)

#define EMAC_DMA_CH1_MISS_FRAME_CNT_MFCO_MASK    (0x8000U)
#define EMAC_DMA_CH1_MISS_FRAME_CNT_MFCO_SHIFT   (15U)
/*! MFCO - Overflow status of the MFC Counter
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define EMAC_DMA_CH1_MISS_FRAME_CNT_MFCO(x)      (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_MISS_FRAME_CNT_MFCO_SHIFT)) & EMAC_DMA_CH1_MISS_FRAME_CNT_MFCO_MASK)
/*! @} */

/*! @name DMA_CH1_RXP_ACCEPT_CNT - DMA Channel 1 Rx Parser Accept Count */
/*! @{ */

#define EMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPAC_MASK   (0x7FFFFFFFU)
#define EMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPAC_SHIFT  (0U)
/*! RXPAC - Rx Parser Accept Counter */
#define EMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPAC(x)     (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPAC_SHIFT)) & EMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPAC_MASK)

#define EMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPACOF_MASK (0x80000000U)
#define EMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPACOF_SHIFT (31U)
/*! RXPACOF - Rx Parser Accept Counter Overflow Bit
 *  0b0..Not occurred
 *  0b1..Occurred
 */
#define EMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPACOF(x)   (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPACOF_SHIFT)) & EMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPACOF_MASK)
/*! @} */

/*! @name DMA_CH1_RX_ERI_CNT - DMA Channel 1 Rx ERI Count */
/*! @{ */

#define EMAC_DMA_CH1_RX_ERI_CNT_ECNT_MASK        (0xFFFU)
#define EMAC_DMA_CH1_RX_ERI_CNT_ECNT_SHIFT       (0U)
/*! ECNT - ERI Counter */
#define EMAC_DMA_CH1_RX_ERI_CNT_ECNT(x)          (((uint32_t)(((uint32_t)(x)) << EMAC_DMA_CH1_RX_ERI_CNT_ECNT_SHIFT)) & EMAC_DMA_CH1_RX_ERI_CNT_ECNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group EMAC_Register_Masks */


/*!
 * @}
 */ /* end of group EMAC_Peripheral_Access_Layer */


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


#endif  /* PERI_EMAC_H_ */

