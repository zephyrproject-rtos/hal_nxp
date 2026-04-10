/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K358_GMAC.h
 * @version 1.1
 * @date 2022-10-01
 * @brief Peripheral Access Layer for S32K358_GMAC
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32K358_GMAC_H_)  /* Check if memory map has not been already included */
#define S32K358_GMAC_H_

#include "S32K358_COMMON.h"

/* ----------------------------------------------------------------------------
   -- GMAC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GMAC_Peripheral_Access_Layer GMAC Peripheral Access Layer
 * @{
 */

/** GMAC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MAC_CONFIGURATION;                 /**< , offset: 0x0 */
  __IO uint32_t MAC_EXT_CONFIGURATION;             /**< , offset: 0x4 */
  __IO uint32_t MAC_PACKET_FILTER;                 /**< , offset: 0x8 */
  __IO uint32_t MAC_WATCHDOG_TIMEOUT;              /**< , offset: 0xC */
  __IO uint32_t MAC_HASH_TABLE_REG0;               /**< , offset: 0x10 */
  __IO uint32_t MAC_HASH_TABLE_REG1;               /**< , offset: 0x14 */
  __IO uint32_t MAC_HASH_TABLE_REG2;               /**< , offset: 0x18 */
  __IO uint32_t MAC_HASH_TABLE_REG3;               /**< , offset: 0x1C */
  __IO uint32_t MAC_HASH_TABLE_REG4;               /**< , offset: 0x20 */
  __IO uint32_t MAC_HASH_TABLE_REG5;               /**< , offset: 0x24 */
  __IO uint32_t MAC_HASH_TABLE_REG6;               /**< , offset: 0x28 */
  __IO uint32_t MAC_HASH_TABLE_REG7;               /**< , offset: 0x2C */
  uint8_t RESERVED_0[32];
  __IO uint32_t MAC_VLAN_TAG_CTRL;                 /**< , offset: 0x50 */
  union {                                          /* offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_DATA;                 /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER0;              /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER1;              /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER2;              /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER3;              /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER4;              /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER5;              /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER6;              /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER7;              /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER8;              /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER9;              /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER10;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER11;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER12;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER13;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER14;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER15;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER16;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER17;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER18;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER19;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER20;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER21;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER22;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER23;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER24;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER25;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER26;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER27;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER28;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER29;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER30;             /**< , offset: 0x54 */
    __IO uint32_t MAC_VLAN_TAG_FILTER31;             /**< , offset: 0x54 */
  } MAC_VLAN_TAG_DATA;
  __IO uint32_t MAC_VLAN_HASH_TABLE;               /**< , offset: 0x58 */
  uint8_t RESERVED_1[4];
  union {                                          /* offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL;                     /**< , offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL0;                    /**< , offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL1;                    /**< , offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL2;                    /**< , offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL3;                    /**< , offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL4;                    /**< , offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL5;                    /**< , offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL6;                    /**< , offset: 0x60 */
    __IO uint32_t MAC_VLAN_INCL7;                    /**< , offset: 0x60 */
  } MAC_VLAN_INCL;
  __IO uint32_t MAC_INNER_VLAN_INCL;               /**< , offset: 0x64 */
  uint8_t RESERVED_2[8];
  __IO uint32_t MAC_Q0_TX_FLOW_CTRL;               /**< , offset: 0x70 */
  __IO uint32_t MAC_Q1_TX_FLOW_CTRL;               /**< , offset: 0x74 */
  __IO uint32_t MAC_Q2_TX_FLOW_CTRL;               /**< , offset: 0x78 */
  uint8_t RESERVED_3[20];
  __IO uint32_t MAC_RX_FLOW_CTRL;                  /**< , offset: 0x90 */
  __IO uint32_t MAC_RXQ_CTRL4;                     /**< , offset: 0x94 */
  __IO uint32_t MAC_TXQ_PRTY_MAP0;                 /**< , offset: 0x98 */
  uint8_t RESERVED_4[4];
  __IO uint32_t MAC_RXQ_CTRL0;                     /**< , offset: 0xA0 */
  __IO uint32_t MAC_RXQ_CTRL1;                     /**< , offset: 0xA4 */
  __IO uint32_t MAC_RXQ_CTRL2;                     /**< , offset: 0xA8 */
  uint8_t RESERVED_5[4];
  __I  uint32_t MAC_INTERRUPT_STATUS;              /**< , offset: 0xB0 */
  __IO uint32_t MAC_INTERRUPT_ENABLE;              /**< , offset: 0xB4 */
  __I  uint32_t MAC_RX_TX_STATUS;                  /**< , offset: 0xB8 */
  uint8_t RESERVED_6[60];
  __IO uint32_t MAC_PHYIF_CONTROL_STATUS;          /**< , offset: 0xF8 */
  uint8_t RESERVED_7[20];
  __I  uint32_t MAC_VERSION;                       /**< , offset: 0x110 */
  __I  uint32_t MAC_DEBUG;                         /**< , offset: 0x114 */
  uint8_t RESERVED_8[4];
  __I  uint32_t MAC_HW_FEATURE0;                   /**< , offset: 0x11C */
  __I  uint32_t MAC_HW_FEATURE1;                   /**< , offset: 0x120 */
  __I  uint32_t MAC_HW_FEATURE2;                   /**< , offset: 0x124 */
  __I  uint32_t MAC_HW_FEATURE3;                   /**< , offset: 0x128 */
  uint8_t RESERVED_9[20];
  __IO uint32_t MAC_DPP_FSM_INTERRUPT_STATUS;      /**< , offset: 0x140 */
  uint8_t RESERVED_10[4];
  __IO uint32_t MAC_FSM_CONTROL;                   /**< , offset: 0x148 */
  __IO uint32_t MAC_FSM_ACT_TIMER;                 /**< , offset: 0x14C */
  __IO uint32_t SCS_REG1;                          /**< , offset: 0x150 */
  uint8_t RESERVED_11[172];
  __IO uint32_t MAC_MDIO_ADDRESS;                  /**< , offset: 0x200 */
  __IO uint32_t MAC_MDIO_DATA;                     /**< , offset: 0x204 */
  uint8_t RESERVED_12[8];
  __IO uint32_t MAC_ARP_ADDRESS;                   /**< , offset: 0x210 */
  uint8_t RESERVED_13[28];
  __IO uint32_t MAC_CSR_SW_CTRL;                   /**< , offset: 0x230 */
  __IO uint32_t MAC_FPE_CTRL_STS;                  /**< , offset: 0x234 */
  __IO uint32_t MAC_EXT_CFG1;                      /**< , offset: 0x238 */
  uint8_t RESERVED_14[4];
  __I  uint32_t MAC_PRESN_TIME_NS;                 /**< , offset: 0x240 */
  __IO uint32_t MAC_PRESN_TIME_UPDT;               /**< , offset: 0x244 */
  uint8_t RESERVED_15[184];
  __IO uint32_t MAC_ADDRESS0_HIGH;                 /**< , offset: 0x300 */
  __IO uint32_t MAC_ADDRESS0_LOW;                  /**< , offset: 0x304 */
  __IO uint32_t MAC_ADDRESS1_HIGH;                 /**< , offset: 0x308 */
  __IO uint32_t MAC_ADDRESS1_LOW;                  /**< , offset: 0x30C */
  __IO uint32_t MAC_ADDRESS2_HIGH;                 /**< , offset: 0x310 */
  __IO uint32_t MAC_ADDRESS2_LOW;                  /**< , offset: 0x314 */
  uint8_t RESERVED_16[1000];
  __IO uint32_t MMC_CONTROL;                       /**< , offset: 0x700 */
  __I  uint32_t MMC_RX_INTERRUPT;                  /**< , offset: 0x704 */
  __I  uint32_t MMC_TX_INTERRUPT;                  /**< , offset: 0x708 */
  __IO uint32_t MMC_RX_INTERRUPT_MASK;             /**< , offset: 0x70C */
  __IO uint32_t MMC_TX_INTERRUPT_MASK;             /**< , offset: 0x710 */
  __I  uint32_t TX_OCTET_COUNT_GOOD_BAD;           /**< , offset: 0x714 */
  __I  uint32_t TX_PACKET_COUNT_GOOD_BAD;          /**< , offset: 0x718 */
  __I  uint32_t TX_BROADCAST_PACKETS_GOOD;         /**< , offset: 0x71C */
  __I  uint32_t TX_MULTICAST_PACKETS_GOOD;         /**< , offset: 0x720 */
  __I  uint32_t TX_64OCTETS_PACKETS_GOOD_BAD;      /**< , offset: 0x724 */
  __I  uint32_t TX_65TO127OCTETS_PACKETS_GOOD_BAD; /**< , offset: 0x728 */
  __I  uint32_t TX_128TO255OCTETS_PACKETS_GOOD_BAD; /**< , offset: 0x72C */
  __I  uint32_t TX_256TO511OCTETS_PACKETS_GOOD_BAD; /**< , offset: 0x730 */
  __I  uint32_t TX_512TO1023OCTETS_PACKETS_GOOD_BAD; /**< , offset: 0x734 */
  __I  uint32_t TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD; /**< , offset: 0x738 */
  __I  uint32_t TX_UNICAST_PACKETS_GOOD_BAD;       /**< , offset: 0x73C */
  __I  uint32_t TX_MULTICAST_PACKETS_GOOD_BAD;     /**< , offset: 0x740 */
  __I  uint32_t TX_BROADCAST_PACKETS_GOOD_BAD;     /**< , offset: 0x744 */
  __I  uint32_t TX_UNDERFLOW_ERROR_PACKETS;        /**< , offset: 0x748 */
  __I  uint32_t TX_SINGLE_COLLISION_GOOD_PACKETS;  /**< , offset: 0x74C */
  __I  uint32_t TX_MULTIPLE_COLLISION_GOOD_PACKETS; /**< , offset: 0x750 */
  __I  uint32_t TX_DEFERRED_PACKETS;               /**< , offset: 0x754 */
  __I  uint32_t TX_LATE_COLLISION_PACKETS;         /**< , offset: 0x758 */
  __I  uint32_t TX_EXCESSIVE_COLLISION_PACKETS;    /**< , offset: 0x75C */
  __I  uint32_t TX_CARRIER_ERROR_PACKETS;          /**< , offset: 0x760 */
  __I  uint32_t TX_OCTET_COUNT_GOOD;               /**< , offset: 0x764 */
  __I  uint32_t TX_PACKET_COUNT_GOOD;              /**< , offset: 0x768 */
  __I  uint32_t TX_EXCESSIVE_DEFERRAL_ERROR;       /**< , offset: 0x76C */
  __I  uint32_t TX_PAUSE_PACKETS;                  /**< , offset: 0x770 */
  __I  uint32_t TX_VLAN_PACKETS_GOOD;              /**< , offset: 0x774 */
  __I  uint32_t TX_OSIZE_PACKETS_GOOD;             /**< , offset: 0x778 */
  uint8_t RESERVED_17[4];
  __I  uint32_t RX_PACKETS_COUNT_GOOD_BAD;         /**< , offset: 0x780 */
  __I  uint32_t RX_OCTET_COUNT_GOOD_BAD;           /**< , offset: 0x784 */
  __I  uint32_t RX_OCTET_COUNT_GOOD;               /**< , offset: 0x788 */
  __I  uint32_t RX_BROADCAST_PACKETS_GOOD;         /**< , offset: 0x78C */
  __I  uint32_t RX_MULTICAST_PACKETS_GOOD;         /**< , offset: 0x790 */
  __I  uint32_t RX_CRC_ERROR_PACKETS;              /**< , offset: 0x794 */
  __I  uint32_t RX_ALIGNMENT_ERROR_PACKETS;        /**< , offset: 0x798 */
  __I  uint32_t RX_RUNT_ERROR_PACKETS;             /**< , offset: 0x79C */
  __I  uint32_t RX_JABBER_ERROR_PACKETS;           /**< , offset: 0x7A0 */
  __I  uint32_t RX_UNDERSIZE_PACKETS_GOOD;         /**< , offset: 0x7A4 */
  __I  uint32_t RX_OVERSIZE_PACKETS_GOOD;          /**< , offset: 0x7A8 */
  __I  uint32_t RX_64OCTETS_PACKETS_GOOD_BAD;      /**< , offset: 0x7AC */
  __I  uint32_t RX_65TO127OCTETS_PACKETS_GOOD_BAD; /**< , offset: 0x7B0 */
  __I  uint32_t RX_128TO255OCTETS_PACKETS_GOOD_BAD; /**< , offset: 0x7B4 */
  __I  uint32_t RX_256TO511OCTETS_PACKETS_GOOD_BAD; /**< , offset: 0x7B8 */
  __I  uint32_t RX_512TO1023OCTETS_PACKETS_GOOD_BAD; /**< , offset: 0x7BC */
  __I  uint32_t RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD; /**< , offset: 0x7C0 */
  __I  uint32_t RX_UNICAST_PACKETS_GOOD;           /**< , offset: 0x7C4 */
  __I  uint32_t RX_LENGTH_ERROR_PACKETS;           /**< , offset: 0x7C8 */
  __I  uint32_t RX_OUT_OF_RANGE_TYPE_PACKETS;      /**< , offset: 0x7CC */
  __I  uint32_t RX_PAUSE_PACKETS;                  /**< , offset: 0x7D0 */
  __I  uint32_t RX_FIFO_OVERFLOW_PACKETS;          /**< , offset: 0x7D4 */
  __I  uint32_t RX_VLAN_PACKETS_GOOD_BAD;          /**< , offset: 0x7D8 */
  __I  uint32_t RX_WATCHDOG_ERROR_PACKETS;         /**< , offset: 0x7DC */
  __I  uint32_t RX_RECEIVE_ERROR_PACKETS;          /**< , offset: 0x7E0 */
  __I  uint32_t RX_CONTROL_PACKETS_GOOD;           /**< , offset: 0x7E4 */
  uint8_t RESERVED_18[184];
  __I  uint32_t MMC_FPE_TX_INTERRUPT;              /**< , offset: 0x8A0 */
  __IO uint32_t MMC_FPE_TX_INTERRUPT_MASK;         /**< , offset: 0x8A4 */
  __I  uint32_t MMC_TX_FPE_FRAGMENT_CNTR;          /**< , offset: 0x8A8 */
  __I  uint32_t MMC_TX_HOLD_REQ_CNTR;              /**< , offset: 0x8AC */
  uint8_t RESERVED_19[16];
  __I  uint32_t MMC_FPE_RX_INTERRUPT;              /**< , offset: 0x8C0 */
  __IO uint32_t MMC_FPE_RX_INTERRUPT_MASK;         /**< , offset: 0x8C4 */
  __I  uint32_t MMC_RX_PACKET_ASSEMBLY_ERR_CNTR;   /**< , offset: 0x8C8 */
  __I  uint32_t MMC_RX_PACKET_SMD_ERR_CNTR;        /**< , offset: 0x8CC */
  __I  uint32_t MMC_RX_PACKET_ASSEMBLY_OK_CNTR;    /**< , offset: 0x8D0 */
  __I  uint32_t MMC_RX_FPE_FRAGMENT_CNTR;          /**< , offset: 0x8D4 */
  uint8_t RESERVED_20[40];
  __IO uint32_t MAC_L3_L4_CONTROL0;                /**< , offset: 0x900 */
  __IO uint32_t MAC_LAYER4_ADDRESS0;               /**< , offset: 0x904 */
  uint8_t RESERVED_21[8];
  __IO uint32_t MAC_LAYER3_ADDR0_REG0;             /**< , offset: 0x910 */
  __IO uint32_t MAC_LAYER3_ADDR1_REG0;             /**< , offset: 0x914 */
  __IO uint32_t MAC_LAYER3_ADDR2_REG0;             /**< , offset: 0x918 */
  __IO uint32_t MAC_LAYER3_ADDR3_REG0;             /**< , offset: 0x91C */
  uint8_t RESERVED_22[16];
  __IO uint32_t MAC_L3_L4_CONTROL1;                /**< , offset: 0x930 */
  __IO uint32_t MAC_LAYER4_ADDRESS1;               /**< , offset: 0x934 */
  uint8_t RESERVED_23[8];
  __IO uint32_t MAC_LAYER3_ADDR0_REG1;             /**< , offset: 0x940 */
  __IO uint32_t MAC_LAYER3_ADDR1_REG1;             /**< , offset: 0x944 */
  __IO uint32_t MAC_LAYER3_ADDR2_REG1;             /**< , offset: 0x948 */
  __IO uint32_t MAC_LAYER3_ADDR3_REG1;             /**< , offset: 0x94C */
  uint8_t RESERVED_24[16];
  __IO uint32_t MAC_L3_L4_CONTROL2;                /**< , offset: 0x960 */
  __IO uint32_t MAC_LAYER4_ADDRESS2;               /**< , offset: 0x964 */
  uint8_t RESERVED_25[8];
  __IO uint32_t MAC_LAYER3_ADDR0_REG2;             /**< , offset: 0x970 */
  __IO uint32_t MAC_LAYER3_ADDR1_REG2;             /**< , offset: 0x974 */
  __IO uint32_t MAC_LAYER3_ADDR2_REG2;             /**< , offset: 0x978 */
  __IO uint32_t MAC_LAYER3_ADDR3_REG2;             /**< , offset: 0x97C */
  uint8_t RESERVED_26[16];
  __IO uint32_t MAC_L3_L4_CONTROL3;                /**< , offset: 0x990 */
  __IO uint32_t MAC_LAYER4_ADDRESS3;               /**< , offset: 0x994 */
  uint8_t RESERVED_27[8];
  __IO uint32_t MAC_LAYER3_ADDR0_REG3;             /**< , offset: 0x9A0 */
  __IO uint32_t MAC_LAYER3_ADDR1_REG3;             /**< , offset: 0x9A4 */
  __IO uint32_t MAC_LAYER3_ADDR2_REG3;             /**< , offset: 0x9A8 */
  __IO uint32_t MAC_LAYER3_ADDR3_REG3;             /**< , offset: 0x9AC */
  uint8_t RESERVED_28[16];
  __IO uint32_t MAC_L3_L4_CONTROL4;                /**< , offset: 0x9C0 */
  __IO uint32_t MAC_LAYER4_ADDRESS4;               /**< , offset: 0x9C4 */
  uint8_t RESERVED_29[8];
  __IO uint32_t MAC_LAYER3_ADDR0_REG4;             /**< , offset: 0x9D0 */
  __IO uint32_t MAC_LAYER3_ADDR1_REG4;             /**< , offset: 0x9D4 */
  __IO uint32_t MAC_LAYER3_ADDR2_REG4;             /**< , offset: 0x9D8 */
  __IO uint32_t MAC_LAYER3_ADDR3_REG4;             /**< , offset: 0x9DC */
  uint8_t RESERVED_30[16];
  __IO uint32_t MAC_L3_L4_CONTROL5;                /**< , offset: 0x9F0 */
  __IO uint32_t MAC_LAYER4_ADDRESS5;               /**< , offset: 0x9F4 */
  uint8_t RESERVED_31[8];
  __IO uint32_t MAC_LAYER3_ADDR0_REG5;             /**< , offset: 0xA00 */
  __IO uint32_t MAC_LAYER3_ADDR1_REG5;             /**< , offset: 0xA04 */
  __IO uint32_t MAC_LAYER3_ADDR2_REG5;             /**< , offset: 0xA08 */
  __IO uint32_t MAC_LAYER3_ADDR3_REG5;             /**< , offset: 0xA0C */
  uint8_t RESERVED_32[16];
  __IO uint32_t MAC_L3_L4_CONTROL6;                /**< , offset: 0xA20 */
  __IO uint32_t MAC_LAYER4_ADDRESS6;               /**< , offset: 0xA24 */
  uint8_t RESERVED_33[8];
  __IO uint32_t MAC_LAYER3_ADDR0_REG6;             /**< , offset: 0xA30 */
  __IO uint32_t MAC_LAYER3_ADDR1_REG6;             /**< , offset: 0xA34 */
  __IO uint32_t MAC_LAYER3_ADDR2_REG6;             /**< , offset: 0xA38 */
  __IO uint32_t MAC_LAYER3_ADDR3_REG6;             /**< , offset: 0xA3C */
  uint8_t RESERVED_34[16];
  __IO uint32_t MAC_L3_L4_CONTROL7;                /**< , offset: 0xA50 */
  __IO uint32_t MAC_LAYER4_ADDRESS7;               /**< , offset: 0xA54 */
  uint8_t RESERVED_35[8];
  __IO uint32_t MAC_LAYER3_ADDR0_REG7;             /**< , offset: 0xA60 */
  __IO uint32_t MAC_LAYER3_ADDR1_REG7;             /**< , offset: 0xA64 */
  __IO uint32_t MAC_LAYER3_ADDR2_REG7;             /**< , offset: 0xA68 */
  __IO uint32_t MAC_LAYER3_ADDR3_REG7;             /**< , offset: 0xA6C */
  __IO uint32_t MAC_INDIR_ACCESS_CTRL;             /**< , offset: 0xA70 */
  union {                                          /* offset: 0xA74 */
    __IO uint32_t MAC_INDIR_ACCESS_DATA;             /**< , offset: 0xA74 */
    __IO uint32_t MAC_TMRQ_REGS0;                    /**< , offset: 0xA74 */
    __IO uint32_t MAC_TMRQ_REGS1;                    /**< , offset: 0xA74 */
    __IO uint32_t MAC_TMRQ_REGS2;                    /**< , offset: 0xA74 */
    __IO uint32_t MAC_TMRQ_REGS3;                    /**< , offset: 0xA74 */
    __IO uint32_t MAC_TMRQ_REGS4;                    /**< , offset: 0xA74 */
    __IO uint32_t MAC_TMRQ_REGS5;                    /**< , offset: 0xA74 */
    __IO uint32_t MAC_TMRQ_REGS6;                    /**< , offset: 0xA74 */
    __IO uint32_t MAC_TMRQ_REGS7;                    /**< , offset: 0xA74 */
  } MAC_INDIR_ACCESS_DATA;
  uint8_t RESERVED_36[136];
  __IO uint32_t MAC_TIMESTAMP_CONTROL;             /**< , offset: 0xB00 */
  __IO uint32_t MAC_SUB_SECOND_INCREMENT;          /**< , offset: 0xB04 */
  __I  uint32_t MAC_SYSTEM_TIME_SECONDS;           /**< , offset: 0xB08 */
  __I  uint32_t MAC_SYSTEM_TIME_NANOSECONDS;       /**< , offset: 0xB0C */
  __IO uint32_t MAC_SYSTEM_TIME_SECONDS_UPDATE;    /**< , offset: 0xB10 */
  __IO uint32_t MAC_SYSTEM_TIME_NANOSECONDS_UPDATE; /**< , offset: 0xB14 */
  __IO uint32_t MAC_TIMESTAMP_ADDEND;              /**< , offset: 0xB18 */
  __IO uint32_t MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS; /**< , offset: 0xB1C */
  __I  uint32_t MAC_TIMESTAMP_STATUS;              /**< , offset: 0xB20 */
  uint8_t RESERVED_37[12];
  __I  uint32_t MAC_TX_TIMESTAMP_STATUS_NANOSECONDS; /**< , offset: 0xB30 */
  __I  uint32_t MAC_TX_TIMESTAMP_STATUS_SECONDS;   /**< , offset: 0xB34 */
  uint8_t RESERVED_38[24];
  __IO uint32_t MAC_TIMESTAMP_INGRESS_ASYM_CORR;   /**< , offset: 0xB50 */
  __IO uint32_t MAC_TIMESTAMP_EGRESS_ASYM_CORR;    /**< , offset: 0xB54 */
  __IO uint32_t MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND; /**< , offset: 0xB58 */
  __IO uint32_t MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND; /**< , offset: 0xB5C */
  __IO uint32_t MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC; /**< , offset: 0xB60 */
  __IO uint32_t MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC; /**< , offset: 0xB64 */
  __I  uint32_t MAC_TIMESTAMP_INGRESS_LATENCY;     /**< , offset: 0xB68 */
  __I  uint32_t MAC_TIMESTAMP_EGRESS_LATENCY;      /**< , offset: 0xB6C */
  __IO uint32_t MAC_PPS_CONTROL;                   /**< , offset: 0xB70 */
  uint8_t RESERVED_39[12];
  __IO uint32_t MAC_PPS0_TARGET_TIME_SECONDS;      /**< , offset: 0xB80 */
  __IO uint32_t MAC_PPS0_TARGET_TIME_NANOSECONDS;  /**< , offset: 0xB84 */
  __IO uint32_t MAC_PPS0_INTERVAL;                 /**< , offset: 0xB88 */
  __IO uint32_t MAC_PPS0_WIDTH;                    /**< , offset: 0xB8C */
  __IO uint32_t MAC_PPS1_TARGET_TIME_SECONDS;      /**< , offset: 0xB90 */
  __IO uint32_t MAC_PPS1_TARGET_TIME_NANOSECONDS;  /**< , offset: 0xB94 */
  __IO uint32_t MAC_PPS1_INTERVAL;                 /**< , offset: 0xB98 */
  __IO uint32_t MAC_PPS1_WIDTH;                    /**< , offset: 0xB9C */
  __IO uint32_t MAC_PPS2_TARGET_TIME_SECONDS;      /**< , offset: 0xBA0 */
  __IO uint32_t MAC_PPS2_TARGET_TIME_NANOSECONDS;  /**< , offset: 0xBA4 */
  __IO uint32_t MAC_PPS2_INTERVAL;                 /**< , offset: 0xBA8 */
  __IO uint32_t MAC_PPS2_WIDTH;                    /**< , offset: 0xBAC */
  __IO uint32_t MAC_PPS3_TARGET_TIME_SECONDS;      /**< , offset: 0xBB0 */
  __IO uint32_t MAC_PPS3_TARGET_TIME_NANOSECONDS;  /**< , offset: 0xBB4 */
  __IO uint32_t MAC_PPS3_INTERVAL;                 /**< , offset: 0xBB8 */
  __IO uint32_t MAC_PPS3_WIDTH;                    /**< , offset: 0xBBC */
  uint8_t RESERVED_40[64];
  __IO uint32_t MTL_OPERATION_MODE;                /**< , offset: 0xC00 */
  uint8_t RESERVED_41[4];
  __IO uint32_t MTL_DBG_CTL;                       /**< , offset: 0xC08 */
  __IO uint32_t MTL_DBG_STS;                       /**< , offset: 0xC0C */
  __IO uint32_t MTL_FIFO_DEBUG_DATA;               /**< , offset: 0xC10 */
  uint8_t RESERVED_42[12];
  __I  uint32_t MTL_INTERRUPT_STATUS;              /**< , offset: 0xC20 */
  uint8_t RESERVED_43[12];
  __IO uint32_t MTL_RXQ_DMA_MAP0;                  /**< , offset: 0xC30 */
  uint8_t RESERVED_44[12];
  __IO uint32_t MTL_TBS_CTRL;                      /**< , offset: 0xC40 */
  uint8_t RESERVED_45[12];
  __IO uint32_t MTL_EST_CONTROL;                   /**< , offset: 0xC50 */
  __IO uint32_t MTL_EST_EXT_CONTROL;               /**< , offset: 0xC54 */
  __IO uint32_t MTL_EST_STATUS;                    /**< , offset: 0xC58 */
  uint8_t RESERVED_46[4];
  __IO uint32_t MTL_EST_SCH_ERROR;                 /**< , offset: 0xC60 */
  __IO uint32_t MTL_EST_FRM_SIZE_ERROR;            /**< , offset: 0xC64 */
  __I  uint32_t MTL_EST_FRM_SIZE_CAPTURE;          /**< , offset: 0xC68 */
  uint8_t RESERVED_47[4];
  __IO uint32_t MTL_EST_INTR_ENABLE;               /**< , offset: 0xC70 */
  uint8_t RESERVED_48[12];
  __IO uint32_t MTL_EST_GCL_CONTROL;               /**< , offset: 0xC80 */
  __IO uint32_t MTL_EST_GCL_DATA;                  /**< , offset: 0xC84 */
  uint8_t RESERVED_49[8];
  __IO uint32_t MTL_FPE_CTRL_STS;                  /**< , offset: 0xC90 */
  __IO uint32_t MTL_FPE_ADVANCE;                   /**< , offset: 0xC94 */
  uint8_t RESERVED_50[8];
  __IO uint32_t MTL_RXP_CONTROL_STATUS;            /**< , offset: 0xCA0 */
  __IO uint32_t MTL_RXP_INTERRUPT_CONTROL_STATUS;  /**< , offset: 0xCA4 */
  __I  uint32_t MTL_RXP_DROP_CNT;                  /**< , offset: 0xCA8 */
  __I  uint32_t MTL_RXP_ERROR_CNT;                 /**< , offset: 0xCAC */
  __IO uint32_t MTL_RXP_INDIRECT_ACC_CONTROL_STATUS; /**< , offset: 0xCB0 */
  __I  uint32_t MTL_RXP_INDIRECT_ACC_DATA;         /**< , offset: 0xCB4 */
  __I  uint32_t MTL_RXP_BYPASS_CNT;                /**< , offset: 0xCB8 */
  uint8_t RESERVED_51[4];
  __IO uint32_t MTL_ECC_CONTROL;                   /**< , offset: 0xCC0 */
  __I  uint32_t MTL_SAFETY_INTERRUPT_STATUS;       /**< , offset: 0xCC4 */
  __IO uint32_t MTL_ECC_INTERRUPT_ENABLE;          /**< , offset: 0xCC8 */
  __IO uint32_t MTL_ECC_INTERRUPT_STATUS;          /**< , offset: 0xCCC */
  __IO uint32_t MTL_ECC_ERR_STS_RCTL;              /**< , offset: 0xCD0 */
  __I  uint32_t MTL_ECC_ERR_ADDR_STATUS;           /**< , offset: 0xCD4 */
  __I  uint32_t MTL_ECC_ERR_CNTR_STATUS;           /**< , offset: 0xCD8 */
  uint8_t RESERVED_52[4];
  __IO uint32_t MTL_DPP_CONTROL;                   /**< , offset: 0xCE0 */
  __IO uint32_t MTL_DPP_ECC_EIC;                   /**< , offset: 0xCE4 */
  uint8_t RESERVED_53[24];
  __IO uint32_t MTL_TXQ0_OPERATION_MODE;           /**< , offset: 0xD00 */
  __I  uint32_t MTL_TXQ0_UNDERFLOW;                /**< , offset: 0xD04 */
  __I  uint32_t MTL_TXQ0_DEBUG;                    /**< , offset: 0xD08 */
  uint8_t RESERVED_54[8];
  __I  uint32_t MTL_TXQ0_ETS_STATUS;               /**< , offset: 0xD14 */
  __IO uint32_t MTL_TXQ0_QUANTUM_WEIGHT;           /**< , offset: 0xD18 */
  uint8_t RESERVED_55[16];
  __IO uint32_t MTL_Q0_INTERRUPT_CONTROL_STATUS;   /**< , offset: 0xD2C */
  __IO uint32_t MTL_RXQ0_OPERATION_MODE;           /**< , offset: 0xD30 */
  __I  uint32_t MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT; /**< , offset: 0xD34 */
  __I  uint32_t MTL_RXQ0_DEBUG;                    /**< , offset: 0xD38 */
  __IO uint32_t MTL_RXQ0_CONTROL;                  /**< , offset: 0xD3C */
  __IO uint32_t MTL_TXQ1_OPERATION_MODE;           /**< , offset: 0xD40 */
  __I  uint32_t MTL_TXQ1_UNDERFLOW;                /**< , offset: 0xD44 */
  __I  uint32_t MTL_TXQ1_DEBUG;                    /**< , offset: 0xD48 */
  uint8_t RESERVED_56[4];
  __IO uint32_t MTL_TXQ1_ETS_CONTROL;              /**< , offset: 0xD50 */
  __I  uint32_t MTL_TXQ1_ETS_STATUS;               /**< , offset: 0xD54 */
  __IO uint32_t MTL_TXQ1_QUANTUM_WEIGHT;           /**< , offset: 0xD58 */
  __IO uint32_t MTL_TXQ1_SENDSLOPECREDIT;          /**< , offset: 0xD5C */
  __IO uint32_t MTL_TXQ1_HICREDIT;                 /**< , offset: 0xD60 */
  __IO uint32_t MTL_TXQ1_LOCREDIT;                 /**< , offset: 0xD64 */
  uint8_t RESERVED_57[4];
  __IO uint32_t MTL_Q1_INTERRUPT_CONTROL_STATUS;   /**< , offset: 0xD6C */
  __IO uint32_t MTL_RXQ1_OPERATION_MODE;           /**< , offset: 0xD70 */
  __I  uint32_t MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT; /**< , offset: 0xD74 */
  __I  uint32_t MTL_RXQ1_DEBUG;                    /**< , offset: 0xD78 */
  __IO uint32_t MTL_RXQ1_CONTROL;                  /**< , offset: 0xD7C */
  __IO uint32_t MTL_TXQ2_OPERATION_MODE;           /**< , offset: 0xD80 */
  __I  uint32_t MTL_TXQ2_UNDERFLOW;                /**< , offset: 0xD84 */
  __I  uint32_t MTL_TXQ2_DEBUG;                    /**< , offset: 0xD88 */
  uint8_t RESERVED_58[4];
  __IO uint32_t MTL_TXQ2_ETS_CONTROL;              /**< , offset: 0xD90 */
  __I  uint32_t MTL_TXQ2_ETS_STATUS;               /**< , offset: 0xD94 */
  __IO uint32_t MTL_TXQ2_QUANTUM_WEIGHT;           /**< , offset: 0xD98 */
  __IO uint32_t MTL_TXQ2_SENDSLOPECREDIT;          /**< , offset: 0xD9C */
  __IO uint32_t MTL_TXQ2_HICREDIT;                 /**< , offset: 0xDA0 */
  __IO uint32_t MTL_TXQ2_LOCREDIT;                 /**< , offset: 0xDA4 */
  uint8_t RESERVED_59[4];
  __IO uint32_t MTL_Q2_INTERRUPT_CONTROL_STATUS;   /**< , offset: 0xDAC */
  __IO uint32_t MTL_RXQ2_OPERATION_MODE;           /**< , offset: 0xDB0 */
  __I  uint32_t MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT; /**< , offset: 0xDB4 */
  __I  uint32_t MTL_RXQ2_DEBUG;                    /**< , offset: 0xDB8 */
  __IO uint32_t MTL_RXQ2_CONTROL;                  /**< , offset: 0xDBC */
  uint8_t RESERVED_60[576];
  __IO uint32_t DMA_MODE;                          /**< , offset: 0x1000 */
  __IO uint32_t DMA_SYSBUS_MODE;                   /**< , offset: 0x1004 */
  __I  uint32_t DMA_INTERRUPT_STATUS;              /**< , offset: 0x1008 */
  __I  uint32_t DMA_DEBUG_STATUS0;                 /**< , offset: 0x100C */
  uint8_t RESERVED_61[64];
  __IO uint32_t DMA_TBS_CTRL0;                     /**< , offset: 0x1050 */
  __IO uint32_t DMA_TBS_CTRL1;                     /**< , offset: 0x1054 */
  __IO uint32_t DMA_TBS_CTRL2;                     /**< , offset: 0x1058 */
  __IO uint32_t DMA_TBS_CTRL3;                     /**< , offset: 0x105C */
  uint8_t RESERVED_62[32];
  __I  uint32_t DMA_SAFETY_INTERRUPT_STATUS;       /**< , offset: 0x1080 */
  uint8_t RESERVED_63[124];
  __IO uint32_t DMA_CH0_CONTROL;                   /**< , offset: 0x1100 */
  __IO uint32_t DMA_CH0_TX_CONTROL;                /**< , offset: 0x1104 */
  __IO uint32_t DMA_CH0_RX_CONTROL;                /**< , offset: 0x1108 */
  uint8_t RESERVED_64[8];
  __IO uint32_t DMA_CH0_TXDESC_LIST_ADDRESS;       /**< , offset: 0x1114 */
  uint8_t RESERVED_65[4];
  __IO uint32_t DMA_CH0_RXDESC_LIST_ADDRESS;       /**< , offset: 0x111C */
  __IO uint32_t DMA_CH0_TXDESC_TAIL_POINTER;       /**< , offset: 0x1120 */
  uint8_t RESERVED_66[4];
  __IO uint32_t DMA_CH0_RXDESC_TAIL_POINTER;       /**< , offset: 0x1128 */
  __IO uint32_t DMA_CH0_TXDESC_RING_LENGTH;        /**< , offset: 0x112C */
  __IO uint32_t DMA_CH0_RX_CONTROL2;               /**< , offset: 0x1130 */
  __IO uint32_t DMA_CH0_INTERRUPT_ENABLE;          /**< , offset: 0x1134 */
  __IO uint32_t DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER; /**< , offset: 0x1138 */
  __IO uint32_t DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS; /**< , offset: 0x113C */
  uint8_t RESERVED_67[4];
  __I  uint32_t DMA_CH0_CURRENT_APP_TXDESC;        /**< , offset: 0x1144 */
  uint8_t RESERVED_68[4];
  __I  uint32_t DMA_CH0_CURRENT_APP_RXDESC;        /**< , offset: 0x114C */
  uint8_t RESERVED_69[4];
  __I  uint32_t DMA_CH0_CURRENT_APP_TXBUFFER;      /**< , offset: 0x1154 */
  uint8_t RESERVED_70[4];
  __I  uint32_t DMA_CH0_CURRENT_APP_RXBUFFER;      /**< , offset: 0x115C */
  __IO uint32_t DMA_CH0_STATUS;                    /**< , offset: 0x1160 */
  __I  uint32_t DMA_CH0_MISS_FRAME_CNT;            /**< , offset: 0x1164 */
  __I  uint32_t DMA_CH0_RXP_ACCEPT_CNT;            /**< , offset: 0x1168 */
  __I  uint32_t DMA_CH0_RX_ERI_CNT;                /**< , offset: 0x116C */
  uint8_t RESERVED_71[16];
  __IO uint32_t DMA_CH1_CONTROL;                   /**< , offset: 0x1180 */
  __IO uint32_t DMA_CH1_TX_CONTROL;                /**< , offset: 0x1184 */
  __IO uint32_t DMA_CH1_RX_CONTROL;                /**< , offset: 0x1188 */
  uint8_t RESERVED_72[8];
  __IO uint32_t DMA_CH1_TXDESC_LIST_ADDRESS;       /**< , offset: 0x1194 */
  uint8_t RESERVED_73[4];
  __IO uint32_t DMA_CH1_RXDESC_LIST_ADDRESS;       /**< , offset: 0x119C */
  __IO uint32_t DMA_CH1_TXDESC_TAIL_POINTER;       /**< , offset: 0x11A0 */
  uint8_t RESERVED_74[4];
  __IO uint32_t DMA_CH1_RXDESC_TAIL_POINTER;       /**< , offset: 0x11A8 */
  __IO uint32_t DMA_CH1_TXDESC_RING_LENGTH;        /**< , offset: 0x11AC */
  __IO uint32_t DMA_CH1_RX_CONTROL2;               /**< , offset: 0x11B0 */
  __IO uint32_t DMA_CH1_INTERRUPT_ENABLE;          /**< , offset: 0x11B4 */
  __IO uint32_t DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER; /**< , offset: 0x11B8 */
  __IO uint32_t DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS; /**< , offset: 0x11BC */
  uint8_t RESERVED_75[4];
  __I  uint32_t DMA_CH1_CURRENT_APP_TXDESC;        /**< , offset: 0x11C4 */
  uint8_t RESERVED_76[4];
  __I  uint32_t DMA_CH1_CURRENT_APP_RXDESC;        /**< , offset: 0x11CC */
  uint8_t RESERVED_77[4];
  __I  uint32_t DMA_CH1_CURRENT_APP_TXBUFFER;      /**< , offset: 0x11D4 */
  uint8_t RESERVED_78[4];
  __I  uint32_t DMA_CH1_CURRENT_APP_RXBUFFER;      /**< , offset: 0x11DC */
  __IO uint32_t DMA_CH1_STATUS;                    /**< , offset: 0x11E0 */
  __I  uint32_t DMA_CH1_MISS_FRAME_CNT;            /**< , offset: 0x11E4 */
  __I  uint32_t DMA_CH1_RXP_ACCEPT_CNT;            /**< , offset: 0x11E8 */
  __I  uint32_t DMA_CH1_RX_ERI_CNT;                /**< , offset: 0x11EC */
  uint8_t RESERVED_79[16];
  __IO uint32_t DMA_CH2_CONTROL;                   /**< , offset: 0x1200 */
  __IO uint32_t DMA_CH2_TX_CONTROL;                /**< , offset: 0x1204 */
  __IO uint32_t DMA_CH2_RX_CONTROL;                /**< , offset: 0x1208 */
  uint8_t RESERVED_80[8];
  __IO uint32_t DMA_CH2_TXDESC_LIST_ADDRESS;       /**< , offset: 0x1214 */
  uint8_t RESERVED_81[4];
  __IO uint32_t DMA_CH2_RXDESC_LIST_ADDRESS;       /**< , offset: 0x121C */
  __IO uint32_t DMA_CH2_TXDESC_TAIL_POINTER;       /**< , offset: 0x1220 */
  uint8_t RESERVED_82[4];
  __IO uint32_t DMA_CH2_RXDESC_TAIL_POINTER;       /**< , offset: 0x1228 */
  __IO uint32_t DMA_CH2_TXDESC_RING_LENGTH;        /**< , offset: 0x122C */
  __IO uint32_t DMA_CH2_RX_CONTROL2;               /**< , offset: 0x1230 */
  __IO uint32_t DMA_CH2_INTERRUPT_ENABLE;          /**< , offset: 0x1234 */
  __IO uint32_t DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER; /**< , offset: 0x1238 */
  __IO uint32_t DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS; /**< , offset: 0x123C */
  uint8_t RESERVED_83[4];
  __I  uint32_t DMA_CH2_CURRENT_APP_TXDESC;        /**< , offset: 0x1244 */
  uint8_t RESERVED_84[4];
  __I  uint32_t DMA_CH2_CURRENT_APP_RXDESC;        /**< , offset: 0x124C */
  uint8_t RESERVED_85[4];
  __I  uint32_t DMA_CH2_CURRENT_APP_TXBUFFER;      /**< , offset: 0x1254 */
  uint8_t RESERVED_86[4];
  __I  uint32_t DMA_CH2_CURRENT_APP_RXBUFFER;      /**< , offset: 0x125C */
  __IO uint32_t DMA_CH2_STATUS;                    /**< , offset: 0x1260 */
  __I  uint32_t DMA_CH2_MISS_FRAME_CNT;            /**< , offset: 0x1264 */
  __I  uint32_t DMA_CH2_RXP_ACCEPT_CNT;            /**< , offset: 0x1268 */
  __I  uint32_t DMA_CH2_RX_ERI_CNT;                /**< , offset: 0x126C */
} GMAC_Type, *GMAC_MemMapPtr;

/** Number of instances of the GMAC module. */
#define GMAC_INSTANCE_COUNT                      (1u)

/* GMAC - Peripheral instance base addresses */
/** Peripheral GMAC base address */
#define IP_GMAC_0_BASE                             (0x40484000u)
/** Peripheral GMAC base pointer */
#define IP_GMAC_0                                 ((GMAC_Type *)IP_GMAC_0_BASE)
/** Array initializer of GMAC peripheral base addresses */
#define IP_GMAC_BASE_ADDRS                       { IP_GMAC_0_BASE }
/** Array initializer of GMAC peripheral base pointers */
#define IP_GMAC_BASE_PTRS                        { IP_GMAC_0 }

/* ----------------------------------------------------------------------------
   -- GMAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GMAC_Register_Masks GMAC Register Masks
 * @{
 */

/*! @name MAC_CONFIGURATION -  */
/*! @{ */

#define GMAC_MAC_CONFIGURATION_RE_MASK           (0x1U)
#define GMAC_MAC_CONFIGURATION_RE_SHIFT          (0U)
#define GMAC_MAC_CONFIGURATION_RE_WIDTH          (1U)
#define GMAC_MAC_CONFIGURATION_RE(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_RE_SHIFT)) & GMAC_MAC_CONFIGURATION_RE_MASK)

#define GMAC_MAC_CONFIGURATION_TE_MASK           (0x2U)
#define GMAC_MAC_CONFIGURATION_TE_SHIFT          (1U)
#define GMAC_MAC_CONFIGURATION_TE_WIDTH          (1U)
#define GMAC_MAC_CONFIGURATION_TE(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_TE_SHIFT)) & GMAC_MAC_CONFIGURATION_TE_MASK)

#define GMAC_MAC_CONFIGURATION_PRELEN_MASK       (0xCU)
#define GMAC_MAC_CONFIGURATION_PRELEN_SHIFT      (2U)
#define GMAC_MAC_CONFIGURATION_PRELEN_WIDTH      (2U)
#define GMAC_MAC_CONFIGURATION_PRELEN(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_PRELEN_SHIFT)) & GMAC_MAC_CONFIGURATION_PRELEN_MASK)

#define GMAC_MAC_CONFIGURATION_DC_MASK           (0x10U)
#define GMAC_MAC_CONFIGURATION_DC_SHIFT          (4U)
#define GMAC_MAC_CONFIGURATION_DC_WIDTH          (1U)
#define GMAC_MAC_CONFIGURATION_DC(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_DC_SHIFT)) & GMAC_MAC_CONFIGURATION_DC_MASK)

#define GMAC_MAC_CONFIGURATION_BL_MASK           (0x60U)
#define GMAC_MAC_CONFIGURATION_BL_SHIFT          (5U)
#define GMAC_MAC_CONFIGURATION_BL_WIDTH          (2U)
#define GMAC_MAC_CONFIGURATION_BL(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_BL_SHIFT)) & GMAC_MAC_CONFIGURATION_BL_MASK)

#define GMAC_MAC_CONFIGURATION_Reserved_7_MASK   (0x80U)
#define GMAC_MAC_CONFIGURATION_Reserved_7_SHIFT  (7U)
#define GMAC_MAC_CONFIGURATION_Reserved_7_WIDTH  (1U)
#define GMAC_MAC_CONFIGURATION_Reserved_7(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_Reserved_7_SHIFT)) & GMAC_MAC_CONFIGURATION_Reserved_7_MASK)

#define GMAC_MAC_CONFIGURATION_DR_MASK           (0x100U)
#define GMAC_MAC_CONFIGURATION_DR_SHIFT          (8U)
#define GMAC_MAC_CONFIGURATION_DR_WIDTH          (1U)
#define GMAC_MAC_CONFIGURATION_DR(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_DR_SHIFT)) & GMAC_MAC_CONFIGURATION_DR_MASK)

#define GMAC_MAC_CONFIGURATION_DCRS_MASK         (0x200U)
#define GMAC_MAC_CONFIGURATION_DCRS_SHIFT        (9U)
#define GMAC_MAC_CONFIGURATION_DCRS_WIDTH        (1U)
#define GMAC_MAC_CONFIGURATION_DCRS(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_DCRS_SHIFT)) & GMAC_MAC_CONFIGURATION_DCRS_MASK)

#define GMAC_MAC_CONFIGURATION_DO_MASK           (0x400U)
#define GMAC_MAC_CONFIGURATION_DO_SHIFT          (10U)
#define GMAC_MAC_CONFIGURATION_DO_WIDTH          (1U)
#define GMAC_MAC_CONFIGURATION_DO(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_DO_SHIFT)) & GMAC_MAC_CONFIGURATION_DO_MASK)

#define GMAC_MAC_CONFIGURATION_ECRSFD_MASK       (0x800U)
#define GMAC_MAC_CONFIGURATION_ECRSFD_SHIFT      (11U)
#define GMAC_MAC_CONFIGURATION_ECRSFD_WIDTH      (1U)
#define GMAC_MAC_CONFIGURATION_ECRSFD(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_ECRSFD_SHIFT)) & GMAC_MAC_CONFIGURATION_ECRSFD_MASK)

#define GMAC_MAC_CONFIGURATION_LM_MASK           (0x1000U)
#define GMAC_MAC_CONFIGURATION_LM_SHIFT          (12U)
#define GMAC_MAC_CONFIGURATION_LM_WIDTH          (1U)
#define GMAC_MAC_CONFIGURATION_LM(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_LM_SHIFT)) & GMAC_MAC_CONFIGURATION_LM_MASK)

#define GMAC_MAC_CONFIGURATION_DM_MASK           (0x2000U)
#define GMAC_MAC_CONFIGURATION_DM_SHIFT          (13U)
#define GMAC_MAC_CONFIGURATION_DM_WIDTH          (1U)
#define GMAC_MAC_CONFIGURATION_DM(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_DM_SHIFT)) & GMAC_MAC_CONFIGURATION_DM_MASK)

#define GMAC_MAC_CONFIGURATION_FES_MASK          (0x4000U)
#define GMAC_MAC_CONFIGURATION_FES_SHIFT         (14U)
#define GMAC_MAC_CONFIGURATION_FES_WIDTH         (1U)
#define GMAC_MAC_CONFIGURATION_FES(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_FES_SHIFT)) & GMAC_MAC_CONFIGURATION_FES_MASK)

#define GMAC_MAC_CONFIGURATION_PS_MASK           (0x8000U)
#define GMAC_MAC_CONFIGURATION_PS_SHIFT          (15U)
#define GMAC_MAC_CONFIGURATION_PS_WIDTH          (1U)
#define GMAC_MAC_CONFIGURATION_PS(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_PS_SHIFT)) & GMAC_MAC_CONFIGURATION_PS_MASK)

#define GMAC_MAC_CONFIGURATION_JE_MASK           (0x10000U)
#define GMAC_MAC_CONFIGURATION_JE_SHIFT          (16U)
#define GMAC_MAC_CONFIGURATION_JE_WIDTH          (1U)
#define GMAC_MAC_CONFIGURATION_JE(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_JE_SHIFT)) & GMAC_MAC_CONFIGURATION_JE_MASK)

#define GMAC_MAC_CONFIGURATION_JD_MASK           (0x20000U)
#define GMAC_MAC_CONFIGURATION_JD_SHIFT          (17U)
#define GMAC_MAC_CONFIGURATION_JD_WIDTH          (1U)
#define GMAC_MAC_CONFIGURATION_JD(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_JD_SHIFT)) & GMAC_MAC_CONFIGURATION_JD_MASK)

#define GMAC_MAC_CONFIGURATION_BE_MASK           (0x40000U)
#define GMAC_MAC_CONFIGURATION_BE_SHIFT          (18U)
#define GMAC_MAC_CONFIGURATION_BE_WIDTH          (1U)
#define GMAC_MAC_CONFIGURATION_BE(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_BE_SHIFT)) & GMAC_MAC_CONFIGURATION_BE_MASK)

#define GMAC_MAC_CONFIGURATION_WD_MASK           (0x80000U)
#define GMAC_MAC_CONFIGURATION_WD_SHIFT          (19U)
#define GMAC_MAC_CONFIGURATION_WD_WIDTH          (1U)
#define GMAC_MAC_CONFIGURATION_WD(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_WD_SHIFT)) & GMAC_MAC_CONFIGURATION_WD_MASK)

#define GMAC_MAC_CONFIGURATION_ACS_MASK          (0x100000U)
#define GMAC_MAC_CONFIGURATION_ACS_SHIFT         (20U)
#define GMAC_MAC_CONFIGURATION_ACS_WIDTH         (1U)
#define GMAC_MAC_CONFIGURATION_ACS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_ACS_SHIFT)) & GMAC_MAC_CONFIGURATION_ACS_MASK)

#define GMAC_MAC_CONFIGURATION_CST_MASK          (0x200000U)
#define GMAC_MAC_CONFIGURATION_CST_SHIFT         (21U)
#define GMAC_MAC_CONFIGURATION_CST_WIDTH         (1U)
#define GMAC_MAC_CONFIGURATION_CST(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_CST_SHIFT)) & GMAC_MAC_CONFIGURATION_CST_MASK)

#define GMAC_MAC_CONFIGURATION_S2KP_MASK         (0x400000U)
#define GMAC_MAC_CONFIGURATION_S2KP_SHIFT        (22U)
#define GMAC_MAC_CONFIGURATION_S2KP_WIDTH        (1U)
#define GMAC_MAC_CONFIGURATION_S2KP(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_S2KP_SHIFT)) & GMAC_MAC_CONFIGURATION_S2KP_MASK)

#define GMAC_MAC_CONFIGURATION_GPSLCE_MASK       (0x800000U)
#define GMAC_MAC_CONFIGURATION_GPSLCE_SHIFT      (23U)
#define GMAC_MAC_CONFIGURATION_GPSLCE_WIDTH      (1U)
#define GMAC_MAC_CONFIGURATION_GPSLCE(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_GPSLCE_SHIFT)) & GMAC_MAC_CONFIGURATION_GPSLCE_MASK)

#define GMAC_MAC_CONFIGURATION_IPG_MASK          (0x7000000U)
#define GMAC_MAC_CONFIGURATION_IPG_SHIFT         (24U)
#define GMAC_MAC_CONFIGURATION_IPG_WIDTH         (3U)
#define GMAC_MAC_CONFIGURATION_IPG(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_IPG_SHIFT)) & GMAC_MAC_CONFIGURATION_IPG_MASK)

#define GMAC_MAC_CONFIGURATION_IPC_MASK          (0x8000000U)
#define GMAC_MAC_CONFIGURATION_IPC_SHIFT         (27U)
#define GMAC_MAC_CONFIGURATION_IPC_WIDTH         (1U)
#define GMAC_MAC_CONFIGURATION_IPC(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_IPC_SHIFT)) & GMAC_MAC_CONFIGURATION_IPC_MASK)

#define GMAC_MAC_CONFIGURATION_SARC_MASK         (0x70000000U)
#define GMAC_MAC_CONFIGURATION_SARC_SHIFT        (28U)
#define GMAC_MAC_CONFIGURATION_SARC_WIDTH        (3U)
#define GMAC_MAC_CONFIGURATION_SARC(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_SARC_SHIFT)) & GMAC_MAC_CONFIGURATION_SARC_MASK)

#define GMAC_MAC_CONFIGURATION_ARPEN_MASK        (0x80000000U)
#define GMAC_MAC_CONFIGURATION_ARPEN_SHIFT       (31U)
#define GMAC_MAC_CONFIGURATION_ARPEN_WIDTH       (1U)
#define GMAC_MAC_CONFIGURATION_ARPEN(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CONFIGURATION_ARPEN_SHIFT)) & GMAC_MAC_CONFIGURATION_ARPEN_MASK)
/*! @} */

/*! @name MAC_EXT_CONFIGURATION -  */
/*! @{ */

#define GMAC_MAC_EXT_CONFIGURATION_GPSL_MASK     (0x3FFFU)
#define GMAC_MAC_EXT_CONFIGURATION_GPSL_SHIFT    (0U)
#define GMAC_MAC_EXT_CONFIGURATION_GPSL_WIDTH    (14U)
#define GMAC_MAC_EXT_CONFIGURATION_GPSL(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CONFIGURATION_GPSL_SHIFT)) & GMAC_MAC_EXT_CONFIGURATION_GPSL_MASK)

#define GMAC_MAC_EXT_CONFIGURATION_Reserved_15_14_MASK (0xC000U)
#define GMAC_MAC_EXT_CONFIGURATION_Reserved_15_14_SHIFT (14U)
#define GMAC_MAC_EXT_CONFIGURATION_Reserved_15_14_WIDTH (2U)
#define GMAC_MAC_EXT_CONFIGURATION_Reserved_15_14(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CONFIGURATION_Reserved_15_14_SHIFT)) & GMAC_MAC_EXT_CONFIGURATION_Reserved_15_14_MASK)

#define GMAC_MAC_EXT_CONFIGURATION_DCRCC_MASK    (0x10000U)
#define GMAC_MAC_EXT_CONFIGURATION_DCRCC_SHIFT   (16U)
#define GMAC_MAC_EXT_CONFIGURATION_DCRCC_WIDTH   (1U)
#define GMAC_MAC_EXT_CONFIGURATION_DCRCC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CONFIGURATION_DCRCC_SHIFT)) & GMAC_MAC_EXT_CONFIGURATION_DCRCC_MASK)

#define GMAC_MAC_EXT_CONFIGURATION_SPEN_MASK     (0x20000U)
#define GMAC_MAC_EXT_CONFIGURATION_SPEN_SHIFT    (17U)
#define GMAC_MAC_EXT_CONFIGURATION_SPEN_WIDTH    (1U)
#define GMAC_MAC_EXT_CONFIGURATION_SPEN(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CONFIGURATION_SPEN_SHIFT)) & GMAC_MAC_EXT_CONFIGURATION_SPEN_MASK)

#define GMAC_MAC_EXT_CONFIGURATION_USP_MASK      (0x40000U)
#define GMAC_MAC_EXT_CONFIGURATION_USP_SHIFT     (18U)
#define GMAC_MAC_EXT_CONFIGURATION_USP_WIDTH     (1U)
#define GMAC_MAC_EXT_CONFIGURATION_USP(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CONFIGURATION_USP_SHIFT)) & GMAC_MAC_EXT_CONFIGURATION_USP_MASK)

#define GMAC_MAC_EXT_CONFIGURATION_PDC_MASK      (0x80000U)
#define GMAC_MAC_EXT_CONFIGURATION_PDC_SHIFT     (19U)
#define GMAC_MAC_EXT_CONFIGURATION_PDC_WIDTH     (1U)
#define GMAC_MAC_EXT_CONFIGURATION_PDC(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CONFIGURATION_PDC_SHIFT)) & GMAC_MAC_EXT_CONFIGURATION_PDC_MASK)

#define GMAC_MAC_EXT_CONFIGURATION_HDSMS_MASK    (0x700000U)
#define GMAC_MAC_EXT_CONFIGURATION_HDSMS_SHIFT   (20U)
#define GMAC_MAC_EXT_CONFIGURATION_HDSMS_WIDTH   (3U)
#define GMAC_MAC_EXT_CONFIGURATION_HDSMS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CONFIGURATION_HDSMS_SHIFT)) & GMAC_MAC_EXT_CONFIGURATION_HDSMS_MASK)

#define GMAC_MAC_EXT_CONFIGURATION_Reserved_23_MASK (0x800000U)
#define GMAC_MAC_EXT_CONFIGURATION_Reserved_23_SHIFT (23U)
#define GMAC_MAC_EXT_CONFIGURATION_Reserved_23_WIDTH (1U)
#define GMAC_MAC_EXT_CONFIGURATION_Reserved_23(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CONFIGURATION_Reserved_23_SHIFT)) & GMAC_MAC_EXT_CONFIGURATION_Reserved_23_MASK)

#define GMAC_MAC_EXT_CONFIGURATION_EIPGEN_MASK   (0x1000000U)
#define GMAC_MAC_EXT_CONFIGURATION_EIPGEN_SHIFT  (24U)
#define GMAC_MAC_EXT_CONFIGURATION_EIPGEN_WIDTH  (1U)
#define GMAC_MAC_EXT_CONFIGURATION_EIPGEN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CONFIGURATION_EIPGEN_SHIFT)) & GMAC_MAC_EXT_CONFIGURATION_EIPGEN_MASK)

#define GMAC_MAC_EXT_CONFIGURATION_EIPG_MASK     (0x3E000000U)
#define GMAC_MAC_EXT_CONFIGURATION_EIPG_SHIFT    (25U)
#define GMAC_MAC_EXT_CONFIGURATION_EIPG_WIDTH    (5U)
#define GMAC_MAC_EXT_CONFIGURATION_EIPG(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CONFIGURATION_EIPG_SHIFT)) & GMAC_MAC_EXT_CONFIGURATION_EIPG_MASK)

#define GMAC_MAC_EXT_CONFIGURATION_APDIM_MASK    (0x40000000U)
#define GMAC_MAC_EXT_CONFIGURATION_APDIM_SHIFT   (30U)
#define GMAC_MAC_EXT_CONFIGURATION_APDIM_WIDTH   (1U)
#define GMAC_MAC_EXT_CONFIGURATION_APDIM(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CONFIGURATION_APDIM_SHIFT)) & GMAC_MAC_EXT_CONFIGURATION_APDIM_MASK)

#define GMAC_MAC_EXT_CONFIGURATION_Reserved_FHE_MASK (0x80000000U)
#define GMAC_MAC_EXT_CONFIGURATION_Reserved_FHE_SHIFT (31U)
#define GMAC_MAC_EXT_CONFIGURATION_Reserved_FHE_WIDTH (1U)
#define GMAC_MAC_EXT_CONFIGURATION_Reserved_FHE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CONFIGURATION_Reserved_FHE_SHIFT)) & GMAC_MAC_EXT_CONFIGURATION_Reserved_FHE_MASK)
/*! @} */

/*! @name MAC_PACKET_FILTER -  */
/*! @{ */

#define GMAC_MAC_PACKET_FILTER_PR_MASK           (0x1U)
#define GMAC_MAC_PACKET_FILTER_PR_SHIFT          (0U)
#define GMAC_MAC_PACKET_FILTER_PR_WIDTH          (1U)
#define GMAC_MAC_PACKET_FILTER_PR(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_PR_SHIFT)) & GMAC_MAC_PACKET_FILTER_PR_MASK)

#define GMAC_MAC_PACKET_FILTER_HUC_MASK          (0x2U)
#define GMAC_MAC_PACKET_FILTER_HUC_SHIFT         (1U)
#define GMAC_MAC_PACKET_FILTER_HUC_WIDTH         (1U)
#define GMAC_MAC_PACKET_FILTER_HUC(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_HUC_SHIFT)) & GMAC_MAC_PACKET_FILTER_HUC_MASK)

#define GMAC_MAC_PACKET_FILTER_HMC_MASK          (0x4U)
#define GMAC_MAC_PACKET_FILTER_HMC_SHIFT         (2U)
#define GMAC_MAC_PACKET_FILTER_HMC_WIDTH         (1U)
#define GMAC_MAC_PACKET_FILTER_HMC(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_HMC_SHIFT)) & GMAC_MAC_PACKET_FILTER_HMC_MASK)

#define GMAC_MAC_PACKET_FILTER_DAIF_MASK         (0x8U)
#define GMAC_MAC_PACKET_FILTER_DAIF_SHIFT        (3U)
#define GMAC_MAC_PACKET_FILTER_DAIF_WIDTH        (1U)
#define GMAC_MAC_PACKET_FILTER_DAIF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_DAIF_SHIFT)) & GMAC_MAC_PACKET_FILTER_DAIF_MASK)

#define GMAC_MAC_PACKET_FILTER_PM_MASK           (0x10U)
#define GMAC_MAC_PACKET_FILTER_PM_SHIFT          (4U)
#define GMAC_MAC_PACKET_FILTER_PM_WIDTH          (1U)
#define GMAC_MAC_PACKET_FILTER_PM(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_PM_SHIFT)) & GMAC_MAC_PACKET_FILTER_PM_MASK)

#define GMAC_MAC_PACKET_FILTER_DBF_MASK          (0x20U)
#define GMAC_MAC_PACKET_FILTER_DBF_SHIFT         (5U)
#define GMAC_MAC_PACKET_FILTER_DBF_WIDTH         (1U)
#define GMAC_MAC_PACKET_FILTER_DBF(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_DBF_SHIFT)) & GMAC_MAC_PACKET_FILTER_DBF_MASK)

#define GMAC_MAC_PACKET_FILTER_PCF_MASK          (0xC0U)
#define GMAC_MAC_PACKET_FILTER_PCF_SHIFT         (6U)
#define GMAC_MAC_PACKET_FILTER_PCF_WIDTH         (2U)
#define GMAC_MAC_PACKET_FILTER_PCF(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_PCF_SHIFT)) & GMAC_MAC_PACKET_FILTER_PCF_MASK)

#define GMAC_MAC_PACKET_FILTER_SAIF_MASK         (0x100U)
#define GMAC_MAC_PACKET_FILTER_SAIF_SHIFT        (8U)
#define GMAC_MAC_PACKET_FILTER_SAIF_WIDTH        (1U)
#define GMAC_MAC_PACKET_FILTER_SAIF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_SAIF_SHIFT)) & GMAC_MAC_PACKET_FILTER_SAIF_MASK)

#define GMAC_MAC_PACKET_FILTER_SAF_MASK          (0x200U)
#define GMAC_MAC_PACKET_FILTER_SAF_SHIFT         (9U)
#define GMAC_MAC_PACKET_FILTER_SAF_WIDTH         (1U)
#define GMAC_MAC_PACKET_FILTER_SAF(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_SAF_SHIFT)) & GMAC_MAC_PACKET_FILTER_SAF_MASK)

#define GMAC_MAC_PACKET_FILTER_HPF_MASK          (0x400U)
#define GMAC_MAC_PACKET_FILTER_HPF_SHIFT         (10U)
#define GMAC_MAC_PACKET_FILTER_HPF_WIDTH         (1U)
#define GMAC_MAC_PACKET_FILTER_HPF(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_HPF_SHIFT)) & GMAC_MAC_PACKET_FILTER_HPF_MASK)

#define GMAC_MAC_PACKET_FILTER_Reserved_15_11_MASK (0xF800U)
#define GMAC_MAC_PACKET_FILTER_Reserved_15_11_SHIFT (11U)
#define GMAC_MAC_PACKET_FILTER_Reserved_15_11_WIDTH (5U)
#define GMAC_MAC_PACKET_FILTER_Reserved_15_11(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_Reserved_15_11_SHIFT)) & GMAC_MAC_PACKET_FILTER_Reserved_15_11_MASK)

#define GMAC_MAC_PACKET_FILTER_VTFE_MASK         (0x10000U)
#define GMAC_MAC_PACKET_FILTER_VTFE_SHIFT        (16U)
#define GMAC_MAC_PACKET_FILTER_VTFE_WIDTH        (1U)
#define GMAC_MAC_PACKET_FILTER_VTFE(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_VTFE_SHIFT)) & GMAC_MAC_PACKET_FILTER_VTFE_MASK)

#define GMAC_MAC_PACKET_FILTER_Reserved_19_17_MASK (0xE0000U)
#define GMAC_MAC_PACKET_FILTER_Reserved_19_17_SHIFT (17U)
#define GMAC_MAC_PACKET_FILTER_Reserved_19_17_WIDTH (3U)
#define GMAC_MAC_PACKET_FILTER_Reserved_19_17(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_Reserved_19_17_SHIFT)) & GMAC_MAC_PACKET_FILTER_Reserved_19_17_MASK)

#define GMAC_MAC_PACKET_FILTER_IPFE_MASK         (0x100000U)
#define GMAC_MAC_PACKET_FILTER_IPFE_SHIFT        (20U)
#define GMAC_MAC_PACKET_FILTER_IPFE_WIDTH        (1U)
#define GMAC_MAC_PACKET_FILTER_IPFE(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_IPFE_SHIFT)) & GMAC_MAC_PACKET_FILTER_IPFE_MASK)

#define GMAC_MAC_PACKET_FILTER_DNTU_MASK         (0x200000U)
#define GMAC_MAC_PACKET_FILTER_DNTU_SHIFT        (21U)
#define GMAC_MAC_PACKET_FILTER_DNTU_WIDTH        (1U)
#define GMAC_MAC_PACKET_FILTER_DNTU(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_DNTU_SHIFT)) & GMAC_MAC_PACKET_FILTER_DNTU_MASK)

#define GMAC_MAC_PACKET_FILTER_Reserved_30_22_MASK (0x7FC00000U)
#define GMAC_MAC_PACKET_FILTER_Reserved_30_22_SHIFT (22U)
#define GMAC_MAC_PACKET_FILTER_Reserved_30_22_WIDTH (9U)
#define GMAC_MAC_PACKET_FILTER_Reserved_30_22(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_Reserved_30_22_SHIFT)) & GMAC_MAC_PACKET_FILTER_Reserved_30_22_MASK)

#define GMAC_MAC_PACKET_FILTER_RA_MASK           (0x80000000U)
#define GMAC_MAC_PACKET_FILTER_RA_SHIFT          (31U)
#define GMAC_MAC_PACKET_FILTER_RA_WIDTH          (1U)
#define GMAC_MAC_PACKET_FILTER_RA(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PACKET_FILTER_RA_SHIFT)) & GMAC_MAC_PACKET_FILTER_RA_MASK)
/*! @} */

/*! @name MAC_WATCHDOG_TIMEOUT -  */
/*! @{ */

#define GMAC_MAC_WATCHDOG_TIMEOUT_WTO_MASK       (0xFU)
#define GMAC_MAC_WATCHDOG_TIMEOUT_WTO_SHIFT      (0U)
#define GMAC_MAC_WATCHDOG_TIMEOUT_WTO_WIDTH      (4U)
#define GMAC_MAC_WATCHDOG_TIMEOUT_WTO(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_WATCHDOG_TIMEOUT_WTO_SHIFT)) & GMAC_MAC_WATCHDOG_TIMEOUT_WTO_MASK)

#define GMAC_MAC_WATCHDOG_TIMEOUT_Reserved_7_4_MASK (0xF0U)
#define GMAC_MAC_WATCHDOG_TIMEOUT_Reserved_7_4_SHIFT (4U)
#define GMAC_MAC_WATCHDOG_TIMEOUT_Reserved_7_4_WIDTH (4U)
#define GMAC_MAC_WATCHDOG_TIMEOUT_Reserved_7_4(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_WATCHDOG_TIMEOUT_Reserved_7_4_SHIFT)) & GMAC_MAC_WATCHDOG_TIMEOUT_Reserved_7_4_MASK)

#define GMAC_MAC_WATCHDOG_TIMEOUT_PWE_MASK       (0x100U)
#define GMAC_MAC_WATCHDOG_TIMEOUT_PWE_SHIFT      (8U)
#define GMAC_MAC_WATCHDOG_TIMEOUT_PWE_WIDTH      (1U)
#define GMAC_MAC_WATCHDOG_TIMEOUT_PWE(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_WATCHDOG_TIMEOUT_PWE_SHIFT)) & GMAC_MAC_WATCHDOG_TIMEOUT_PWE_MASK)

#define GMAC_MAC_WATCHDOG_TIMEOUT_Reserved_31_9_MASK (0xFFFFFE00U)
#define GMAC_MAC_WATCHDOG_TIMEOUT_Reserved_31_9_SHIFT (9U)
#define GMAC_MAC_WATCHDOG_TIMEOUT_Reserved_31_9_WIDTH (23U)
#define GMAC_MAC_WATCHDOG_TIMEOUT_Reserved_31_9(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_WATCHDOG_TIMEOUT_Reserved_31_9_SHIFT)) & GMAC_MAC_WATCHDOG_TIMEOUT_Reserved_31_9_MASK)
/*! @} */

/*! @name MAC_HASH_TABLE_REG0 -  */
/*! @{ */

#define GMAC_MAC_HASH_TABLE_REG0_HT31T0_MASK     (0xFFFFFFFFU)
#define GMAC_MAC_HASH_TABLE_REG0_HT31T0_SHIFT    (0U)
#define GMAC_MAC_HASH_TABLE_REG0_HT31T0_WIDTH    (32U)
#define GMAC_MAC_HASH_TABLE_REG0_HT31T0(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HASH_TABLE_REG0_HT31T0_SHIFT)) & GMAC_MAC_HASH_TABLE_REG0_HT31T0_MASK)
/*! @} */

/*! @name MAC_HASH_TABLE_REG1 -  */
/*! @{ */

#define GMAC_MAC_HASH_TABLE_REG1_HT63T32_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_HASH_TABLE_REG1_HT63T32_SHIFT   (0U)
#define GMAC_MAC_HASH_TABLE_REG1_HT63T32_WIDTH   (32U)
#define GMAC_MAC_HASH_TABLE_REG1_HT63T32(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HASH_TABLE_REG1_HT63T32_SHIFT)) & GMAC_MAC_HASH_TABLE_REG1_HT63T32_MASK)
/*! @} */

/*! @name MAC_HASH_TABLE_REG2 -  */
/*! @{ */

#define GMAC_MAC_HASH_TABLE_REG2_HT95T64_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_HASH_TABLE_REG2_HT95T64_SHIFT   (0U)
#define GMAC_MAC_HASH_TABLE_REG2_HT95T64_WIDTH   (32U)
#define GMAC_MAC_HASH_TABLE_REG2_HT95T64(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HASH_TABLE_REG2_HT95T64_SHIFT)) & GMAC_MAC_HASH_TABLE_REG2_HT95T64_MASK)
/*! @} */

/*! @name MAC_HASH_TABLE_REG3 -  */
/*! @{ */

#define GMAC_MAC_HASH_TABLE_REG3_HT127T96_MASK   (0xFFFFFFFFU)
#define GMAC_MAC_HASH_TABLE_REG3_HT127T96_SHIFT  (0U)
#define GMAC_MAC_HASH_TABLE_REG3_HT127T96_WIDTH  (32U)
#define GMAC_MAC_HASH_TABLE_REG3_HT127T96(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HASH_TABLE_REG3_HT127T96_SHIFT)) & GMAC_MAC_HASH_TABLE_REG3_HT127T96_MASK)
/*! @} */

/*! @name MAC_HASH_TABLE_REG4 -  */
/*! @{ */

#define GMAC_MAC_HASH_TABLE_REG4_HT159T128_MASK  (0xFFFFFFFFU)
#define GMAC_MAC_HASH_TABLE_REG4_HT159T128_SHIFT (0U)
#define GMAC_MAC_HASH_TABLE_REG4_HT159T128_WIDTH (32U)
#define GMAC_MAC_HASH_TABLE_REG4_HT159T128(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HASH_TABLE_REG4_HT159T128_SHIFT)) & GMAC_MAC_HASH_TABLE_REG4_HT159T128_MASK)
/*! @} */

/*! @name MAC_HASH_TABLE_REG5 -  */
/*! @{ */

#define GMAC_MAC_HASH_TABLE_REG5_HT191T160_MASK  (0xFFFFFFFFU)
#define GMAC_MAC_HASH_TABLE_REG5_HT191T160_SHIFT (0U)
#define GMAC_MAC_HASH_TABLE_REG5_HT191T160_WIDTH (32U)
#define GMAC_MAC_HASH_TABLE_REG5_HT191T160(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HASH_TABLE_REG5_HT191T160_SHIFT)) & GMAC_MAC_HASH_TABLE_REG5_HT191T160_MASK)
/*! @} */

/*! @name MAC_HASH_TABLE_REG6 -  */
/*! @{ */

#define GMAC_MAC_HASH_TABLE_REG6_HT223T192_MASK  (0xFFFFFFFFU)
#define GMAC_MAC_HASH_TABLE_REG6_HT223T192_SHIFT (0U)
#define GMAC_MAC_HASH_TABLE_REG6_HT223T192_WIDTH (32U)
#define GMAC_MAC_HASH_TABLE_REG6_HT223T192(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HASH_TABLE_REG6_HT223T192_SHIFT)) & GMAC_MAC_HASH_TABLE_REG6_HT223T192_MASK)
/*! @} */

/*! @name MAC_HASH_TABLE_REG7 -  */
/*! @{ */

#define GMAC_MAC_HASH_TABLE_REG7_HT255T224_MASK  (0xFFFFFFFFU)
#define GMAC_MAC_HASH_TABLE_REG7_HT255T224_SHIFT (0U)
#define GMAC_MAC_HASH_TABLE_REG7_HT255T224_WIDTH (32U)
#define GMAC_MAC_HASH_TABLE_REG7_HT255T224(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HASH_TABLE_REG7_HT255T224_SHIFT)) & GMAC_MAC_HASH_TABLE_REG7_HT255T224_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_CTRL -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_CTRL_OB_MASK           (0x1U)
#define GMAC_MAC_VLAN_TAG_CTRL_OB_SHIFT          (0U)
#define GMAC_MAC_VLAN_TAG_CTRL_OB_WIDTH          (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_OB(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_OB_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_OB_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_CT_MASK           (0x2U)
#define GMAC_MAC_VLAN_TAG_CTRL_CT_SHIFT          (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_CT_WIDTH          (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_CT(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_CT_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_CT_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_OFS_MASK          (0x7CU)
#define GMAC_MAC_VLAN_TAG_CTRL_OFS_SHIFT         (2U)
#define GMAC_MAC_VLAN_TAG_CTRL_OFS_WIDTH         (5U)
#define GMAC_MAC_VLAN_TAG_CTRL_OFS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_OFS_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_OFS_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_Reserved_15_y_MASK (0xFF80U)
#define GMAC_MAC_VLAN_TAG_CTRL_Reserved_15_y_SHIFT (7U)
#define GMAC_MAC_VLAN_TAG_CTRL_Reserved_15_y_WIDTH (9U)
#define GMAC_MAC_VLAN_TAG_CTRL_Reserved_15_y(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_Reserved_15_y_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_Reserved_15_y_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_ETV_MASK          (0x10000U)
#define GMAC_MAC_VLAN_TAG_CTRL_ETV_SHIFT         (16U)
#define GMAC_MAC_VLAN_TAG_CTRL_ETV_WIDTH         (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_ETV(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_VTIM_MASK         (0x20000U)
#define GMAC_MAC_VLAN_TAG_CTRL_VTIM_SHIFT        (17U)
#define GMAC_MAC_VLAN_TAG_CTRL_VTIM_WIDTH        (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_VTIM(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_VTIM_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_VTIM_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_ESVL_MASK         (0x40000U)
#define GMAC_MAC_VLAN_TAG_CTRL_ESVL_SHIFT        (18U)
#define GMAC_MAC_VLAN_TAG_CTRL_ESVL_WIDTH        (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_ESVL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_ESVL_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_ESVL_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_ERSVLM_MASK       (0x80000U)
#define GMAC_MAC_VLAN_TAG_CTRL_ERSVLM_SHIFT      (19U)
#define GMAC_MAC_VLAN_TAG_CTRL_ERSVLM_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_ERSVLM(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_DOVLTC_MASK       (0x100000U)
#define GMAC_MAC_VLAN_TAG_CTRL_DOVLTC_SHIFT      (20U)
#define GMAC_MAC_VLAN_TAG_CTRL_DOVLTC_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_DOVLTC(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_EVLS_MASK         (0x600000U)
#define GMAC_MAC_VLAN_TAG_CTRL_EVLS_SHIFT        (21U)
#define GMAC_MAC_VLAN_TAG_CTRL_EVLS_WIDTH        (2U)
#define GMAC_MAC_VLAN_TAG_CTRL_EVLS(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_EVLS_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_EVLS_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_Reserved_23_MASK  (0x800000U)
#define GMAC_MAC_VLAN_TAG_CTRL_Reserved_23_SHIFT (23U)
#define GMAC_MAC_VLAN_TAG_CTRL_Reserved_23_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_Reserved_23(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_Reserved_23_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_Reserved_23_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_EVLRXS_MASK       (0x1000000U)
#define GMAC_MAC_VLAN_TAG_CTRL_EVLRXS_SHIFT      (24U)
#define GMAC_MAC_VLAN_TAG_CTRL_EVLRXS_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_EVLRXS(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_EVLRXS_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_EVLRXS_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_VTHM_MASK         (0x2000000U)
#define GMAC_MAC_VLAN_TAG_CTRL_VTHM_SHIFT        (25U)
#define GMAC_MAC_VLAN_TAG_CTRL_VTHM_WIDTH        (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_VTHM(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_VTHM_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_VTHM_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_EDVLP_MASK        (0x4000000U)
#define GMAC_MAC_VLAN_TAG_CTRL_EDVLP_SHIFT       (26U)
#define GMAC_MAC_VLAN_TAG_CTRL_EDVLP_WIDTH       (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_EDVLP(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_EDVLP_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_EDVLP_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_ERIVLT_MASK       (0x8000000U)
#define GMAC_MAC_VLAN_TAG_CTRL_ERIVLT_SHIFT      (27U)
#define GMAC_MAC_VLAN_TAG_CTRL_ERIVLT_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_ERIVLT(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_EIVLS_MASK        (0x30000000U)
#define GMAC_MAC_VLAN_TAG_CTRL_EIVLS_SHIFT       (28U)
#define GMAC_MAC_VLAN_TAG_CTRL_EIVLS_WIDTH       (2U)
#define GMAC_MAC_VLAN_TAG_CTRL_EIVLS(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_EIVLS_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_EIVLS_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_Reserved_30_MASK  (0x40000000U)
#define GMAC_MAC_VLAN_TAG_CTRL_Reserved_30_SHIFT (30U)
#define GMAC_MAC_VLAN_TAG_CTRL_Reserved_30_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_Reserved_30(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_Reserved_30_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_Reserved_30_MASK)

#define GMAC_MAC_VLAN_TAG_CTRL_EIVLRXS_MASK      (0x80000000U)
#define GMAC_MAC_VLAN_TAG_CTRL_EIVLRXS_SHIFT     (31U)
#define GMAC_MAC_VLAN_TAG_CTRL_EIVLRXS_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_CTRL_EIVLRXS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_CTRL_EIVLRXS_SHIFT)) & GMAC_MAC_VLAN_TAG_CTRL_EIVLRXS_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_DATA -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_DATA_VID_MASK          (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_DATA_VID_SHIFT         (0U)
#define GMAC_MAC_VLAN_TAG_DATA_VID_WIDTH         (16U)
#define GMAC_MAC_VLAN_TAG_DATA_VID(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_DATA_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_DATA_VID_MASK)

#define GMAC_MAC_VLAN_TAG_DATA_VEN_MASK          (0x10000U)
#define GMAC_MAC_VLAN_TAG_DATA_VEN_SHIFT         (16U)
#define GMAC_MAC_VLAN_TAG_DATA_VEN_WIDTH         (1U)
#define GMAC_MAC_VLAN_TAG_DATA_VEN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_DATA_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_DATA_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_DATA_ETV_MASK          (0x20000U)
#define GMAC_MAC_VLAN_TAG_DATA_ETV_SHIFT         (17U)
#define GMAC_MAC_VLAN_TAG_DATA_ETV_WIDTH         (1U)
#define GMAC_MAC_VLAN_TAG_DATA_ETV(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_DATA_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_DATA_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_DATA_DOVLTC_MASK       (0x40000U)
#define GMAC_MAC_VLAN_TAG_DATA_DOVLTC_SHIFT      (18U)
#define GMAC_MAC_VLAN_TAG_DATA_DOVLTC_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_DATA_DOVLTC(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_DATA_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_DATA_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_DATA_ERSVLM_MASK       (0x80000U)
#define GMAC_MAC_VLAN_TAG_DATA_ERSVLM_SHIFT      (19U)
#define GMAC_MAC_VLAN_TAG_DATA_ERSVLM_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_DATA_ERSVLM(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_DATA_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_DATA_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_DATA_ERIVLT_MASK       (0x100000U)
#define GMAC_MAC_VLAN_TAG_DATA_ERIVLT_SHIFT      (20U)
#define GMAC_MAC_VLAN_TAG_DATA_ERIVLT_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_DATA_ERIVLT(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_DATA_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_DATA_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_DATA_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_DATA_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_DATA_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_DATA_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_DATA_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_DATA_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_DATA_DMACHEN_MASK      (0x1000000U)
#define GMAC_MAC_VLAN_TAG_DATA_DMACHEN_SHIFT     (24U)
#define GMAC_MAC_VLAN_TAG_DATA_DMACHEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_DATA_DMACHEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_DATA_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_DATA_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_DATA_DMACHN_MASK       (0x6000000U)
#define GMAC_MAC_VLAN_TAG_DATA_DMACHN_SHIFT      (25U)
#define GMAC_MAC_VLAN_TAG_DATA_DMACHN_WIDTH      (2U)
#define GMAC_MAC_VLAN_TAG_DATA_DMACHN(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_DATA_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_DATA_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_DATA_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_DATA_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_DATA_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_DATA_Reserved_31_y(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_DATA_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_DATA_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER0 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER0_VID_MASK       (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER0_VID_SHIFT      (0U)
#define GMAC_MAC_VLAN_TAG_FILTER0_VID_WIDTH      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER0_VID(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER0_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER0_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER0_VEN_MASK       (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER0_VEN_SHIFT      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER0_VEN_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER0_VEN(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER0_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER0_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER0_ETV_MASK       (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER0_ETV_SHIFT      (17U)
#define GMAC_MAC_VLAN_TAG_FILTER0_ETV_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER0_ETV(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER0_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER0_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER0_DOVLTC_MASK    (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER0_DOVLTC_SHIFT   (18U)
#define GMAC_MAC_VLAN_TAG_FILTER0_DOVLTC_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER0_DOVLTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER0_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER0_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER0_ERSVLM_MASK    (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER0_ERSVLM_SHIFT   (19U)
#define GMAC_MAC_VLAN_TAG_FILTER0_ERSVLM_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER0_ERSVLM(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER0_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER0_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER0_ERIVLT_MASK    (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER0_ERIVLT_SHIFT   (20U)
#define GMAC_MAC_VLAN_TAG_FILTER0_ERIVLT_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER0_ERIVLT(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER0_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER0_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER0_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER0_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER0_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER0_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER0_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER0_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER0_DMACHEN_MASK   (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER0_DMACHEN_SHIFT  (24U)
#define GMAC_MAC_VLAN_TAG_FILTER0_DMACHEN_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER0_DMACHEN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER0_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER0_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER0_DMACHN_MASK    (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER0_DMACHN_SHIFT   (25U)
#define GMAC_MAC_VLAN_TAG_FILTER0_DMACHN_WIDTH   (2U)
#define GMAC_MAC_VLAN_TAG_FILTER0_DMACHN(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER0_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER0_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER0_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER0_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER0_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER0_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER0_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER0_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER1 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER1_VID_MASK       (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER1_VID_SHIFT      (0U)
#define GMAC_MAC_VLAN_TAG_FILTER1_VID_WIDTH      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER1_VID(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER1_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER1_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER1_VEN_MASK       (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER1_VEN_SHIFT      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER1_VEN_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER1_VEN(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER1_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER1_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER1_ETV_MASK       (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER1_ETV_SHIFT      (17U)
#define GMAC_MAC_VLAN_TAG_FILTER1_ETV_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER1_ETV(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER1_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER1_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER1_DOVLTC_MASK    (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER1_DOVLTC_SHIFT   (18U)
#define GMAC_MAC_VLAN_TAG_FILTER1_DOVLTC_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER1_DOVLTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER1_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER1_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER1_ERSVLM_MASK    (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER1_ERSVLM_SHIFT   (19U)
#define GMAC_MAC_VLAN_TAG_FILTER1_ERSVLM_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER1_ERSVLM(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER1_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER1_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER1_ERIVLT_MASK    (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER1_ERIVLT_SHIFT   (20U)
#define GMAC_MAC_VLAN_TAG_FILTER1_ERIVLT_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER1_ERIVLT(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER1_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER1_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER1_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER1_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER1_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER1_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER1_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER1_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER1_DMACHEN_MASK   (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER1_DMACHEN_SHIFT  (24U)
#define GMAC_MAC_VLAN_TAG_FILTER1_DMACHEN_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER1_DMACHEN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER1_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER1_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER1_DMACHN_MASK    (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER1_DMACHN_SHIFT   (25U)
#define GMAC_MAC_VLAN_TAG_FILTER1_DMACHN_WIDTH   (2U)
#define GMAC_MAC_VLAN_TAG_FILTER1_DMACHN(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER1_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER1_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER1_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER1_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER1_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER1_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER1_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER1_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER2 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER2_VID_MASK       (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER2_VID_SHIFT      (0U)
#define GMAC_MAC_VLAN_TAG_FILTER2_VID_WIDTH      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER2_VID(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER2_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER2_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER2_VEN_MASK       (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER2_VEN_SHIFT      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER2_VEN_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER2_VEN(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER2_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER2_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER2_ETV_MASK       (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER2_ETV_SHIFT      (17U)
#define GMAC_MAC_VLAN_TAG_FILTER2_ETV_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER2_ETV(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER2_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER2_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER2_DOVLTC_MASK    (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER2_DOVLTC_SHIFT   (18U)
#define GMAC_MAC_VLAN_TAG_FILTER2_DOVLTC_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER2_DOVLTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER2_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER2_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER2_ERSVLM_MASK    (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER2_ERSVLM_SHIFT   (19U)
#define GMAC_MAC_VLAN_TAG_FILTER2_ERSVLM_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER2_ERSVLM(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER2_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER2_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER2_ERIVLT_MASK    (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER2_ERIVLT_SHIFT   (20U)
#define GMAC_MAC_VLAN_TAG_FILTER2_ERIVLT_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER2_ERIVLT(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER2_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER2_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER2_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER2_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER2_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER2_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER2_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER2_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER2_DMACHEN_MASK   (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER2_DMACHEN_SHIFT  (24U)
#define GMAC_MAC_VLAN_TAG_FILTER2_DMACHEN_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER2_DMACHEN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER2_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER2_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER2_DMACHN_MASK    (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER2_DMACHN_SHIFT   (25U)
#define GMAC_MAC_VLAN_TAG_FILTER2_DMACHN_WIDTH   (2U)
#define GMAC_MAC_VLAN_TAG_FILTER2_DMACHN(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER2_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER2_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER2_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER2_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER2_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER2_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER2_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER2_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER3 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER3_VID_MASK       (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER3_VID_SHIFT      (0U)
#define GMAC_MAC_VLAN_TAG_FILTER3_VID_WIDTH      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER3_VID(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER3_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER3_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER3_VEN_MASK       (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER3_VEN_SHIFT      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER3_VEN_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER3_VEN(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER3_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER3_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER3_ETV_MASK       (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER3_ETV_SHIFT      (17U)
#define GMAC_MAC_VLAN_TAG_FILTER3_ETV_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER3_ETV(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER3_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER3_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER3_DOVLTC_MASK    (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER3_DOVLTC_SHIFT   (18U)
#define GMAC_MAC_VLAN_TAG_FILTER3_DOVLTC_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER3_DOVLTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER3_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER3_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER3_ERSVLM_MASK    (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER3_ERSVLM_SHIFT   (19U)
#define GMAC_MAC_VLAN_TAG_FILTER3_ERSVLM_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER3_ERSVLM(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER3_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER3_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER3_ERIVLT_MASK    (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER3_ERIVLT_SHIFT   (20U)
#define GMAC_MAC_VLAN_TAG_FILTER3_ERIVLT_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER3_ERIVLT(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER3_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER3_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER3_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER3_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER3_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER3_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER3_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER3_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER3_DMACHEN_MASK   (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER3_DMACHEN_SHIFT  (24U)
#define GMAC_MAC_VLAN_TAG_FILTER3_DMACHEN_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER3_DMACHEN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER3_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER3_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER3_DMACHN_MASK    (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER3_DMACHN_SHIFT   (25U)
#define GMAC_MAC_VLAN_TAG_FILTER3_DMACHN_WIDTH   (2U)
#define GMAC_MAC_VLAN_TAG_FILTER3_DMACHN(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER3_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER3_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER3_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER3_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER3_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER3_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER3_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER3_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER4 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER4_VID_MASK       (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER4_VID_SHIFT      (0U)
#define GMAC_MAC_VLAN_TAG_FILTER4_VID_WIDTH      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER4_VID(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER4_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER4_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER4_VEN_MASK       (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER4_VEN_SHIFT      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER4_VEN_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER4_VEN(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER4_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER4_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER4_ETV_MASK       (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER4_ETV_SHIFT      (17U)
#define GMAC_MAC_VLAN_TAG_FILTER4_ETV_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER4_ETV(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER4_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER4_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER4_DOVLTC_MASK    (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER4_DOVLTC_SHIFT   (18U)
#define GMAC_MAC_VLAN_TAG_FILTER4_DOVLTC_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER4_DOVLTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER4_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER4_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER4_ERSVLM_MASK    (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER4_ERSVLM_SHIFT   (19U)
#define GMAC_MAC_VLAN_TAG_FILTER4_ERSVLM_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER4_ERSVLM(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER4_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER4_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER4_ERIVLT_MASK    (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER4_ERIVLT_SHIFT   (20U)
#define GMAC_MAC_VLAN_TAG_FILTER4_ERIVLT_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER4_ERIVLT(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER4_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER4_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER4_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER4_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER4_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER4_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER4_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER4_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER4_DMACHEN_MASK   (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER4_DMACHEN_SHIFT  (24U)
#define GMAC_MAC_VLAN_TAG_FILTER4_DMACHEN_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER4_DMACHEN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER4_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER4_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER4_DMACHN_MASK    (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER4_DMACHN_SHIFT   (25U)
#define GMAC_MAC_VLAN_TAG_FILTER4_DMACHN_WIDTH   (2U)
#define GMAC_MAC_VLAN_TAG_FILTER4_DMACHN(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER4_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER4_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER4_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER4_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER4_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER4_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER4_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER4_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER5 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER5_VID_MASK       (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER5_VID_SHIFT      (0U)
#define GMAC_MAC_VLAN_TAG_FILTER5_VID_WIDTH      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER5_VID(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER5_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER5_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER5_VEN_MASK       (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER5_VEN_SHIFT      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER5_VEN_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER5_VEN(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER5_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER5_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER5_ETV_MASK       (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER5_ETV_SHIFT      (17U)
#define GMAC_MAC_VLAN_TAG_FILTER5_ETV_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER5_ETV(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER5_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER5_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER5_DOVLTC_MASK    (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER5_DOVLTC_SHIFT   (18U)
#define GMAC_MAC_VLAN_TAG_FILTER5_DOVLTC_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER5_DOVLTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER5_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER5_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER5_ERSVLM_MASK    (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER5_ERSVLM_SHIFT   (19U)
#define GMAC_MAC_VLAN_TAG_FILTER5_ERSVLM_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER5_ERSVLM(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER5_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER5_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER5_ERIVLT_MASK    (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER5_ERIVLT_SHIFT   (20U)
#define GMAC_MAC_VLAN_TAG_FILTER5_ERIVLT_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER5_ERIVLT(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER5_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER5_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER5_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER5_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER5_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER5_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER5_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER5_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER5_DMACHEN_MASK   (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER5_DMACHEN_SHIFT  (24U)
#define GMAC_MAC_VLAN_TAG_FILTER5_DMACHEN_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER5_DMACHEN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER5_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER5_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER5_DMACHN_MASK    (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER5_DMACHN_SHIFT   (25U)
#define GMAC_MAC_VLAN_TAG_FILTER5_DMACHN_WIDTH   (2U)
#define GMAC_MAC_VLAN_TAG_FILTER5_DMACHN(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER5_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER5_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER5_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER5_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER5_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER5_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER5_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER5_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER6 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER6_VID_MASK       (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER6_VID_SHIFT      (0U)
#define GMAC_MAC_VLAN_TAG_FILTER6_VID_WIDTH      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER6_VID(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER6_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER6_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER6_VEN_MASK       (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER6_VEN_SHIFT      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER6_VEN_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER6_VEN(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER6_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER6_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER6_ETV_MASK       (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER6_ETV_SHIFT      (17U)
#define GMAC_MAC_VLAN_TAG_FILTER6_ETV_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER6_ETV(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER6_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER6_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER6_DOVLTC_MASK    (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER6_DOVLTC_SHIFT   (18U)
#define GMAC_MAC_VLAN_TAG_FILTER6_DOVLTC_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER6_DOVLTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER6_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER6_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER6_ERSVLM_MASK    (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER6_ERSVLM_SHIFT   (19U)
#define GMAC_MAC_VLAN_TAG_FILTER6_ERSVLM_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER6_ERSVLM(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER6_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER6_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER6_ERIVLT_MASK    (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER6_ERIVLT_SHIFT   (20U)
#define GMAC_MAC_VLAN_TAG_FILTER6_ERIVLT_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER6_ERIVLT(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER6_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER6_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER6_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER6_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER6_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER6_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER6_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER6_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER6_DMACHEN_MASK   (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER6_DMACHEN_SHIFT  (24U)
#define GMAC_MAC_VLAN_TAG_FILTER6_DMACHEN_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER6_DMACHEN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER6_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER6_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER6_DMACHN_MASK    (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER6_DMACHN_SHIFT   (25U)
#define GMAC_MAC_VLAN_TAG_FILTER6_DMACHN_WIDTH   (2U)
#define GMAC_MAC_VLAN_TAG_FILTER6_DMACHN(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER6_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER6_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER6_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER6_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER6_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER6_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER6_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER6_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER7 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER7_VID_MASK       (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER7_VID_SHIFT      (0U)
#define GMAC_MAC_VLAN_TAG_FILTER7_VID_WIDTH      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER7_VID(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER7_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER7_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER7_VEN_MASK       (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER7_VEN_SHIFT      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER7_VEN_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER7_VEN(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER7_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER7_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER7_ETV_MASK       (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER7_ETV_SHIFT      (17U)
#define GMAC_MAC_VLAN_TAG_FILTER7_ETV_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER7_ETV(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER7_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER7_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER7_DOVLTC_MASK    (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER7_DOVLTC_SHIFT   (18U)
#define GMAC_MAC_VLAN_TAG_FILTER7_DOVLTC_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER7_DOVLTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER7_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER7_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER7_ERSVLM_MASK    (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER7_ERSVLM_SHIFT   (19U)
#define GMAC_MAC_VLAN_TAG_FILTER7_ERSVLM_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER7_ERSVLM(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER7_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER7_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER7_ERIVLT_MASK    (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER7_ERIVLT_SHIFT   (20U)
#define GMAC_MAC_VLAN_TAG_FILTER7_ERIVLT_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER7_ERIVLT(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER7_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER7_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER7_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER7_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER7_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER7_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER7_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER7_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER7_DMACHEN_MASK   (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER7_DMACHEN_SHIFT  (24U)
#define GMAC_MAC_VLAN_TAG_FILTER7_DMACHEN_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER7_DMACHEN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER7_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER7_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER7_DMACHN_MASK    (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER7_DMACHN_SHIFT   (25U)
#define GMAC_MAC_VLAN_TAG_FILTER7_DMACHN_WIDTH   (2U)
#define GMAC_MAC_VLAN_TAG_FILTER7_DMACHN(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER7_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER7_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER7_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER7_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER7_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER7_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER7_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER7_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER8 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER8_VID_MASK       (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER8_VID_SHIFT      (0U)
#define GMAC_MAC_VLAN_TAG_FILTER8_VID_WIDTH      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER8_VID(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER8_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER8_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER8_VEN_MASK       (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER8_VEN_SHIFT      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER8_VEN_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER8_VEN(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER8_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER8_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER8_ETV_MASK       (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER8_ETV_SHIFT      (17U)
#define GMAC_MAC_VLAN_TAG_FILTER8_ETV_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER8_ETV(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER8_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER8_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER8_DOVLTC_MASK    (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER8_DOVLTC_SHIFT   (18U)
#define GMAC_MAC_VLAN_TAG_FILTER8_DOVLTC_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER8_DOVLTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER8_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER8_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER8_ERSVLM_MASK    (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER8_ERSVLM_SHIFT   (19U)
#define GMAC_MAC_VLAN_TAG_FILTER8_ERSVLM_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER8_ERSVLM(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER8_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER8_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER8_ERIVLT_MASK    (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER8_ERIVLT_SHIFT   (20U)
#define GMAC_MAC_VLAN_TAG_FILTER8_ERIVLT_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER8_ERIVLT(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER8_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER8_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER8_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER8_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER8_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER8_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER8_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER8_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER8_DMACHEN_MASK   (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER8_DMACHEN_SHIFT  (24U)
#define GMAC_MAC_VLAN_TAG_FILTER8_DMACHEN_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER8_DMACHEN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER8_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER8_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER8_DMACHN_MASK    (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER8_DMACHN_SHIFT   (25U)
#define GMAC_MAC_VLAN_TAG_FILTER8_DMACHN_WIDTH   (2U)
#define GMAC_MAC_VLAN_TAG_FILTER8_DMACHN(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER8_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER8_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER8_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER8_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER8_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER8_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER8_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER8_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER9 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER9_VID_MASK       (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER9_VID_SHIFT      (0U)
#define GMAC_MAC_VLAN_TAG_FILTER9_VID_WIDTH      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER9_VID(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER9_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER9_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER9_VEN_MASK       (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER9_VEN_SHIFT      (16U)
#define GMAC_MAC_VLAN_TAG_FILTER9_VEN_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER9_VEN(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER9_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER9_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER9_ETV_MASK       (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER9_ETV_SHIFT      (17U)
#define GMAC_MAC_VLAN_TAG_FILTER9_ETV_WIDTH      (1U)
#define GMAC_MAC_VLAN_TAG_FILTER9_ETV(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER9_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER9_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER9_DOVLTC_MASK    (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER9_DOVLTC_SHIFT   (18U)
#define GMAC_MAC_VLAN_TAG_FILTER9_DOVLTC_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER9_DOVLTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER9_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER9_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER9_ERSVLM_MASK    (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER9_ERSVLM_SHIFT   (19U)
#define GMAC_MAC_VLAN_TAG_FILTER9_ERSVLM_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER9_ERSVLM(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER9_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER9_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER9_ERIVLT_MASK    (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER9_ERIVLT_SHIFT   (20U)
#define GMAC_MAC_VLAN_TAG_FILTER9_ERIVLT_WIDTH   (1U)
#define GMAC_MAC_VLAN_TAG_FILTER9_ERIVLT(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER9_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER9_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER9_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER9_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER9_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER9_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER9_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER9_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER9_DMACHEN_MASK   (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER9_DMACHEN_SHIFT  (24U)
#define GMAC_MAC_VLAN_TAG_FILTER9_DMACHEN_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER9_DMACHEN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER9_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER9_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER9_DMACHN_MASK    (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER9_DMACHN_SHIFT   (25U)
#define GMAC_MAC_VLAN_TAG_FILTER9_DMACHN_WIDTH   (2U)
#define GMAC_MAC_VLAN_TAG_FILTER9_DMACHN(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER9_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER9_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER9_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER9_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER9_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER9_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER9_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER9_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER10 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER10_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER10_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER10_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER10_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER10_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER10_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER10_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER10_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER10_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER10_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER10_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER10_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER10_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER10_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER10_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER10_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER10_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER10_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER10_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER10_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER10_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER10_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER10_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER10_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER10_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER10_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER10_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER10_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER10_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER10_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER10_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER10_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER10_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER10_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER10_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER10_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER10_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER10_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER10_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER10_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER10_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER10_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER10_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER10_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER10_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER10_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER10_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER10_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER10_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER10_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER10_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER10_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER10_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER10_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER10_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER10_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER10_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER10_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER10_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER10_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER11 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER11_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER11_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER11_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER11_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER11_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER11_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER11_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER11_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER11_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER11_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER11_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER11_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER11_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER11_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER11_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER11_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER11_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER11_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER11_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER11_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER11_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER11_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER11_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER11_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER11_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER11_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER11_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER11_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER11_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER11_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER11_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER11_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER11_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER11_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER11_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER11_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER11_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER11_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER11_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER11_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER11_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER11_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER11_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER11_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER11_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER11_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER11_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER11_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER11_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER11_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER11_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER11_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER11_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER11_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER11_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER11_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER11_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER11_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER11_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER11_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER12 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER12_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER12_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER12_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER12_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER12_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER12_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER12_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER12_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER12_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER12_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER12_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER12_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER12_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER12_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER12_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER12_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER12_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER12_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER12_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER12_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER12_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER12_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER12_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER12_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER12_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER12_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER12_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER12_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER12_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER12_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER12_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER12_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER12_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER12_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER12_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER12_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER12_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER12_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER12_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER12_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER12_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER12_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER12_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER12_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER12_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER12_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER12_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER12_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER12_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER12_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER12_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER12_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER12_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER12_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER12_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER12_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER12_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER12_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER12_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER12_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER13 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER13_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER13_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER13_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER13_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER13_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER13_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER13_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER13_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER13_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER13_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER13_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER13_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER13_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER13_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER13_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER13_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER13_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER13_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER13_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER13_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER13_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER13_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER13_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER13_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER13_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER13_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER13_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER13_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER13_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER13_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER13_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER13_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER13_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER13_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER13_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER13_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER13_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER13_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER13_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER13_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER13_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER13_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER13_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER13_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER13_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER13_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER13_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER13_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER13_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER13_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER13_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER13_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER13_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER13_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER13_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER13_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER13_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER13_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER13_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER13_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER14 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER14_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER14_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER14_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER14_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER14_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER14_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER14_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER14_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER14_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER14_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER14_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER14_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER14_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER14_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER14_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER14_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER14_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER14_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER14_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER14_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER14_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER14_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER14_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER14_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER14_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER14_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER14_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER14_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER14_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER14_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER14_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER14_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER14_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER14_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER14_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER14_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER14_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER14_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER14_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER14_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER14_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER14_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER14_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER14_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER14_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER14_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER14_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER14_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER14_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER14_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER14_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER14_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER14_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER14_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER14_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER14_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER14_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER14_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER14_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER14_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER15 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER15_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER15_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER15_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER15_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER15_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER15_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER15_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER15_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER15_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER15_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER15_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER15_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER15_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER15_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER15_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER15_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER15_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER15_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER15_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER15_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER15_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER15_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER15_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER15_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER15_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER15_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER15_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER15_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER15_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER15_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER15_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER15_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER15_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER15_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER15_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER15_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER15_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER15_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER15_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER15_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER15_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER15_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER15_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER15_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER15_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER15_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER15_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER15_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER15_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER15_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER15_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER15_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER15_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER15_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER15_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER15_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER15_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER15_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER15_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER15_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER16 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER16_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER16_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER16_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER16_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER16_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER16_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER16_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER16_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER16_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER16_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER16_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER16_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER16_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER16_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER16_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER16_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER16_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER16_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER16_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER16_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER16_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER16_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER16_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER16_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER16_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER16_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER16_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER16_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER16_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER16_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER16_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER16_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER16_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER16_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER16_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER16_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER16_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER16_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER16_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER16_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER16_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER16_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER16_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER16_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER16_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER16_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER16_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER16_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER16_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER16_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER16_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER16_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER16_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER16_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER16_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER16_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER16_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER16_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER16_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER16_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER17 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER17_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER17_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER17_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER17_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER17_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER17_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER17_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER17_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER17_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER17_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER17_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER17_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER17_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER17_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER17_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER17_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER17_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER17_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER17_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER17_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER17_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER17_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER17_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER17_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER17_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER17_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER17_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER17_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER17_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER17_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER17_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER17_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER17_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER17_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER17_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER17_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER17_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER17_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER17_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER17_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER17_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER17_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER17_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER17_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER17_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER17_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER17_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER17_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER17_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER17_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER17_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER17_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER17_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER17_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER17_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER17_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER17_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER17_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER17_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER17_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER18 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER18_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER18_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER18_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER18_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER18_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER18_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER18_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER18_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER18_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER18_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER18_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER18_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER18_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER18_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER18_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER18_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER18_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER18_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER18_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER18_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER18_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER18_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER18_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER18_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER18_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER18_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER18_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER18_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER18_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER18_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER18_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER18_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER18_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER18_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER18_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER18_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER18_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER18_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER18_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER18_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER18_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER18_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER18_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER18_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER18_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER18_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER18_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER18_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER18_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER18_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER18_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER18_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER18_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER18_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER18_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER18_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER18_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER18_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER18_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER18_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER19 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER19_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER19_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER19_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER19_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER19_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER19_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER19_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER19_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER19_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER19_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER19_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER19_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER19_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER19_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER19_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER19_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER19_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER19_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER19_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER19_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER19_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER19_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER19_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER19_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER19_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER19_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER19_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER19_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER19_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER19_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER19_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER19_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER19_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER19_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER19_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER19_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER19_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER19_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER19_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER19_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER19_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER19_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER19_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER19_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER19_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER19_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER19_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER19_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER19_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER19_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER19_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER19_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER19_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER19_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER19_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER19_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER19_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER19_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER19_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER19_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER20 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER20_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER20_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER20_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER20_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER20_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER20_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER20_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER20_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER20_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER20_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER20_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER20_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER20_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER20_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER20_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER20_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER20_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER20_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER20_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER20_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER20_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER20_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER20_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER20_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER20_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER20_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER20_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER20_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER20_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER20_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER20_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER20_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER20_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER20_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER20_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER20_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER20_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER20_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER20_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER20_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER20_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER20_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER20_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER20_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER20_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER20_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER20_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER20_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER20_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER20_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER20_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER20_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER20_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER20_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER20_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER20_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER20_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER20_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER20_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER20_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER21 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER21_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER21_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER21_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER21_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER21_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER21_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER21_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER21_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER21_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER21_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER21_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER21_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER21_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER21_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER21_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER21_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER21_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER21_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER21_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER21_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER21_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER21_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER21_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER21_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER21_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER21_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER21_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER21_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER21_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER21_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER21_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER21_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER21_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER21_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER21_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER21_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER21_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER21_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER21_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER21_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER21_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER21_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER21_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER21_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER21_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER21_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER21_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER21_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER21_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER21_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER21_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER21_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER21_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER21_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER21_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER21_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER21_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER21_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER21_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER21_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER22 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER22_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER22_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER22_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER22_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER22_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER22_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER22_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER22_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER22_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER22_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER22_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER22_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER22_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER22_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER22_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER22_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER22_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER22_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER22_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER22_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER22_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER22_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER22_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER22_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER22_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER22_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER22_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER22_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER22_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER22_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER22_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER22_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER22_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER22_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER22_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER22_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER22_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER22_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER22_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER22_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER22_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER22_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER22_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER22_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER22_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER22_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER22_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER22_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER22_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER22_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER22_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER22_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER22_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER22_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER22_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER22_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER22_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER22_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER22_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER22_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER23 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER23_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER23_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER23_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER23_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER23_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER23_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER23_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER23_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER23_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER23_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER23_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER23_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER23_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER23_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER23_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER23_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER23_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER23_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER23_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER23_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER23_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER23_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER23_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER23_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER23_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER23_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER23_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER23_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER23_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER23_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER23_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER23_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER23_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER23_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER23_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER23_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER23_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER23_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER23_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER23_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER23_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER23_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER23_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER23_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER23_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER23_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER23_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER23_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER23_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER23_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER23_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER23_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER23_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER23_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER23_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER23_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER23_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER23_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER23_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER23_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER24 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER24_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER24_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER24_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER24_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER24_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER24_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER24_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER24_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER24_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER24_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER24_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER24_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER24_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER24_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER24_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER24_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER24_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER24_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER24_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER24_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER24_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER24_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER24_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER24_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER24_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER24_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER24_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER24_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER24_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER24_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER24_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER24_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER24_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER24_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER24_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER24_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER24_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER24_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER24_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER24_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER24_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER24_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER24_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER24_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER24_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER24_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER24_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER24_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER24_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER24_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER24_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER24_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER24_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER24_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER24_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER24_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER24_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER24_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER24_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER24_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER25 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER25_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER25_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER25_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER25_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER25_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER25_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER25_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER25_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER25_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER25_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER25_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER25_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER25_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER25_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER25_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER25_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER25_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER25_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER25_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER25_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER25_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER25_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER25_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER25_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER25_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER25_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER25_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER25_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER25_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER25_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER25_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER25_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER25_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER25_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER25_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER25_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER25_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER25_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER25_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER25_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER25_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER25_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER25_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER25_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER25_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER25_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER25_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER25_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER25_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER25_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER25_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER25_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER25_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER25_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER25_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER25_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER25_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER25_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER25_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER25_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER26 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER26_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER26_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER26_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER26_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER26_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER26_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER26_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER26_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER26_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER26_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER26_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER26_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER26_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER26_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER26_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER26_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER26_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER26_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER26_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER26_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER26_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER26_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER26_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER26_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER26_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER26_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER26_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER26_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER26_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER26_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER26_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER26_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER26_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER26_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER26_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER26_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER26_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER26_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER26_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER26_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER26_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER26_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER26_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER26_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER26_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER26_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER26_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER26_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER26_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER26_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER26_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER26_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER26_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER26_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER26_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER26_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER26_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER26_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER26_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER26_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER27 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER27_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER27_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER27_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER27_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER27_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER27_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER27_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER27_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER27_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER27_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER27_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER27_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER27_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER27_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER27_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER27_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER27_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER27_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER27_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER27_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER27_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER27_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER27_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER27_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER27_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER27_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER27_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER27_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER27_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER27_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER27_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER27_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER27_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER27_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER27_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER27_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER27_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER27_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER27_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER27_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER27_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER27_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER27_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER27_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER27_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER27_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER27_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER27_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER27_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER27_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER27_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER27_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER27_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER27_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER27_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER27_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER27_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER27_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER27_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER27_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER28 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER28_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER28_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER28_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER28_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER28_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER28_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER28_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER28_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER28_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER28_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER28_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER28_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER28_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER28_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER28_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER28_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER28_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER28_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER28_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER28_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER28_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER28_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER28_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER28_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER28_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER28_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER28_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER28_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER28_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER28_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER28_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER28_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER28_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER28_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER28_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER28_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER28_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER28_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER28_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER28_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER28_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER28_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER28_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER28_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER28_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER28_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER28_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER28_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER28_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER28_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER28_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER28_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER28_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER28_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER28_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER28_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER28_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER28_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER28_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER28_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER29 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER29_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER29_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER29_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER29_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER29_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER29_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER29_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER29_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER29_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER29_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER29_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER29_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER29_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER29_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER29_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER29_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER29_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER29_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER29_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER29_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER29_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER29_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER29_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER29_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER29_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER29_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER29_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER29_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER29_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER29_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER29_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER29_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER29_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER29_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER29_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER29_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER29_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER29_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER29_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER29_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER29_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER29_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER29_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER29_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER29_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER29_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER29_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER29_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER29_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER29_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER29_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER29_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER29_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER29_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER29_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER29_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER29_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER29_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER29_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER29_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER30 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER30_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER30_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER30_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER30_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER30_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER30_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER30_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER30_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER30_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER30_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER30_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER30_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER30_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER30_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER30_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER30_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER30_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER30_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER30_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER30_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER30_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER30_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER30_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER30_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER30_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER30_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER30_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER30_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER30_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER30_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER30_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER30_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER30_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER30_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER30_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER30_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER30_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER30_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER30_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER30_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER30_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER30_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER30_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER30_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER30_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER30_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER30_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER30_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER30_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER30_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER30_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER30_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER30_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER30_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER30_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER30_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER30_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER30_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER30_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER30_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_TAG_FILTER31 -  */
/*! @{ */

#define GMAC_MAC_VLAN_TAG_FILTER31_VID_MASK      (0xFFFFU)
#define GMAC_MAC_VLAN_TAG_FILTER31_VID_SHIFT     (0U)
#define GMAC_MAC_VLAN_TAG_FILTER31_VID_WIDTH     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER31_VID(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER31_VID_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER31_VID_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER31_VEN_MASK      (0x10000U)
#define GMAC_MAC_VLAN_TAG_FILTER31_VEN_SHIFT     (16U)
#define GMAC_MAC_VLAN_TAG_FILTER31_VEN_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER31_VEN(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER31_VEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER31_VEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER31_ETV_MASK      (0x20000U)
#define GMAC_MAC_VLAN_TAG_FILTER31_ETV_SHIFT     (17U)
#define GMAC_MAC_VLAN_TAG_FILTER31_ETV_WIDTH     (1U)
#define GMAC_MAC_VLAN_TAG_FILTER31_ETV(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER31_ETV_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER31_ETV_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER31_DOVLTC_MASK   (0x40000U)
#define GMAC_MAC_VLAN_TAG_FILTER31_DOVLTC_SHIFT  (18U)
#define GMAC_MAC_VLAN_TAG_FILTER31_DOVLTC_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER31_DOVLTC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER31_DOVLTC_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER31_DOVLTC_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER31_ERSVLM_MASK   (0x80000U)
#define GMAC_MAC_VLAN_TAG_FILTER31_ERSVLM_SHIFT  (19U)
#define GMAC_MAC_VLAN_TAG_FILTER31_ERSVLM_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER31_ERSVLM(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER31_ERSVLM_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER31_ERSVLM_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER31_ERIVLT_MASK   (0x100000U)
#define GMAC_MAC_VLAN_TAG_FILTER31_ERIVLT_SHIFT  (20U)
#define GMAC_MAC_VLAN_TAG_FILTER31_ERIVLT_WIDTH  (1U)
#define GMAC_MAC_VLAN_TAG_FILTER31_ERIVLT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER31_ERIVLT_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER31_ERIVLT_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER31_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_VLAN_TAG_FILTER31_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_VLAN_TAG_FILTER31_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_VLAN_TAG_FILTER31_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER31_Reserved_23_21_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER31_Reserved_23_21_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER31_DMACHEN_MASK  (0x1000000U)
#define GMAC_MAC_VLAN_TAG_FILTER31_DMACHEN_SHIFT (24U)
#define GMAC_MAC_VLAN_TAG_FILTER31_DMACHEN_WIDTH (1U)
#define GMAC_MAC_VLAN_TAG_FILTER31_DMACHEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER31_DMACHEN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER31_DMACHEN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER31_DMACHN_MASK   (0x6000000U)
#define GMAC_MAC_VLAN_TAG_FILTER31_DMACHN_SHIFT  (25U)
#define GMAC_MAC_VLAN_TAG_FILTER31_DMACHN_WIDTH  (2U)
#define GMAC_MAC_VLAN_TAG_FILTER31_DMACHN(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER31_DMACHN_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER31_DMACHN_MASK)

#define GMAC_MAC_VLAN_TAG_FILTER31_Reserved_31_y_MASK (0xF8000000U)
#define GMAC_MAC_VLAN_TAG_FILTER31_Reserved_31_y_SHIFT (27U)
#define GMAC_MAC_VLAN_TAG_FILTER31_Reserved_31_y_WIDTH (5U)
#define GMAC_MAC_VLAN_TAG_FILTER31_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_TAG_FILTER31_Reserved_31_y_SHIFT)) & GMAC_MAC_VLAN_TAG_FILTER31_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_VLAN_HASH_TABLE -  */
/*! @{ */

#define GMAC_MAC_VLAN_HASH_TABLE_VLHT_MASK       (0xFFFFU)
#define GMAC_MAC_VLAN_HASH_TABLE_VLHT_SHIFT      (0U)
#define GMAC_MAC_VLAN_HASH_TABLE_VLHT_WIDTH      (16U)
#define GMAC_MAC_VLAN_HASH_TABLE_VLHT(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_HASH_TABLE_VLHT_SHIFT)) & GMAC_MAC_VLAN_HASH_TABLE_VLHT_MASK)

#define GMAC_MAC_VLAN_HASH_TABLE_Reserved_31_16_MASK (0xFFFF0000U)
#define GMAC_MAC_VLAN_HASH_TABLE_Reserved_31_16_SHIFT (16U)
#define GMAC_MAC_VLAN_HASH_TABLE_Reserved_31_16_WIDTH (16U)
#define GMAC_MAC_VLAN_HASH_TABLE_Reserved_31_16(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_HASH_TABLE_Reserved_31_16_SHIFT)) & GMAC_MAC_VLAN_HASH_TABLE_Reserved_31_16_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL -  */
/*! @{ */

#define GMAC_MAC_VLAN_INCL_VLT_MASK              (0xFFFFU)
#define GMAC_MAC_VLAN_INCL_VLT_SHIFT             (0U)
#define GMAC_MAC_VLAN_INCL_VLT_WIDTH             (16U)
#define GMAC_MAC_VLAN_INCL_VLT(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL_VLT_SHIFT)) & GMAC_MAC_VLAN_INCL_VLT_MASK)

#define GMAC_MAC_VLAN_INCL_VLC_MASK              (0x30000U)
#define GMAC_MAC_VLAN_INCL_VLC_SHIFT             (16U)
#define GMAC_MAC_VLAN_INCL_VLC_WIDTH             (2U)
#define GMAC_MAC_VLAN_INCL_VLC(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL_VLC_SHIFT)) & GMAC_MAC_VLAN_INCL_VLC_MASK)

#define GMAC_MAC_VLAN_INCL_VLP_MASK              (0x40000U)
#define GMAC_MAC_VLAN_INCL_VLP_SHIFT             (18U)
#define GMAC_MAC_VLAN_INCL_VLP_WIDTH             (1U)
#define GMAC_MAC_VLAN_INCL_VLP(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL_VLP_SHIFT)) & GMAC_MAC_VLAN_INCL_VLP_MASK)

#define GMAC_MAC_VLAN_INCL_CSVL_MASK             (0x80000U)
#define GMAC_MAC_VLAN_INCL_CSVL_SHIFT            (19U)
#define GMAC_MAC_VLAN_INCL_CSVL_WIDTH            (1U)
#define GMAC_MAC_VLAN_INCL_CSVL(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL_CSVL_SHIFT)) & GMAC_MAC_VLAN_INCL_CSVL_MASK)

#define GMAC_MAC_VLAN_INCL_VLTI_MASK             (0x100000U)
#define GMAC_MAC_VLAN_INCL_VLTI_SHIFT            (20U)
#define GMAC_MAC_VLAN_INCL_VLTI_WIDTH            (1U)
#define GMAC_MAC_VLAN_INCL_VLTI(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL_VLTI_SHIFT)) & GMAC_MAC_VLAN_INCL_VLTI_MASK)

#define GMAC_MAC_VLAN_INCL_CBTI_MASK             (0x200000U)
#define GMAC_MAC_VLAN_INCL_CBTI_SHIFT            (21U)
#define GMAC_MAC_VLAN_INCL_CBTI_WIDTH            (1U)
#define GMAC_MAC_VLAN_INCL_CBTI(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL_CBTI_SHIFT)) & GMAC_MAC_VLAN_INCL_CBTI_MASK)

#define GMAC_MAC_VLAN_INCL_Reserved_23_22_MASK   (0xC00000U)
#define GMAC_MAC_VLAN_INCL_Reserved_23_22_SHIFT  (22U)
#define GMAC_MAC_VLAN_INCL_Reserved_23_22_WIDTH  (2U)
#define GMAC_MAC_VLAN_INCL_Reserved_23_22(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL_Reserved_23_22_SHIFT)) & GMAC_MAC_VLAN_INCL_Reserved_23_22_MASK)

#define GMAC_MAC_VLAN_INCL_ADDR_MASK             (0x3000000U)
#define GMAC_MAC_VLAN_INCL_ADDR_SHIFT            (24U)
#define GMAC_MAC_VLAN_INCL_ADDR_WIDTH            (2U)
#define GMAC_MAC_VLAN_INCL_ADDR(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL_ADDR_SHIFT)) & GMAC_MAC_VLAN_INCL_ADDR_MASK)

#define GMAC_MAC_VLAN_INCL_Reserved_29_y_MASK    (0x3C000000U)
#define GMAC_MAC_VLAN_INCL_Reserved_29_y_SHIFT   (26U)
#define GMAC_MAC_VLAN_INCL_Reserved_29_y_WIDTH   (4U)
#define GMAC_MAC_VLAN_INCL_Reserved_29_y(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL_Reserved_29_y_SHIFT)) & GMAC_MAC_VLAN_INCL_Reserved_29_y_MASK)

#define GMAC_MAC_VLAN_INCL_RDWR_MASK             (0x40000000U)
#define GMAC_MAC_VLAN_INCL_RDWR_SHIFT            (30U)
#define GMAC_MAC_VLAN_INCL_RDWR_WIDTH            (1U)
#define GMAC_MAC_VLAN_INCL_RDWR(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL_RDWR_SHIFT)) & GMAC_MAC_VLAN_INCL_RDWR_MASK)

#define GMAC_MAC_VLAN_INCL_BUSY_MASK             (0x80000000U)
#define GMAC_MAC_VLAN_INCL_BUSY_SHIFT            (31U)
#define GMAC_MAC_VLAN_INCL_BUSY_WIDTH            (1U)
#define GMAC_MAC_VLAN_INCL_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL_BUSY_SHIFT)) & GMAC_MAC_VLAN_INCL_BUSY_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL0 -  */
/*! @{ */

#define GMAC_MAC_VLAN_INCL0_VLT_MASK             (0xFFFFU)
#define GMAC_MAC_VLAN_INCL0_VLT_SHIFT            (0U)
#define GMAC_MAC_VLAN_INCL0_VLT_WIDTH            (16U)
#define GMAC_MAC_VLAN_INCL0_VLT(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL0_VLT_SHIFT)) & GMAC_MAC_VLAN_INCL0_VLT_MASK)

#define GMAC_MAC_VLAN_INCL0_Reserved_18_16_MASK  (0x70000U)
#define GMAC_MAC_VLAN_INCL0_Reserved_18_16_SHIFT (16U)
#define GMAC_MAC_VLAN_INCL0_Reserved_18_16_WIDTH (3U)
#define GMAC_MAC_VLAN_INCL0_Reserved_18_16(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL0_Reserved_18_16_SHIFT)) & GMAC_MAC_VLAN_INCL0_Reserved_18_16_MASK)

#define GMAC_MAC_VLAN_INCL0_CSVL_MASK            (0x80000U)
#define GMAC_MAC_VLAN_INCL0_CSVL_SHIFT           (19U)
#define GMAC_MAC_VLAN_INCL0_CSVL_WIDTH           (1U)
#define GMAC_MAC_VLAN_INCL0_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL0_CSVL_SHIFT)) & GMAC_MAC_VLAN_INCL0_CSVL_MASK)

#define GMAC_MAC_VLAN_INCL0_Reserved_31_20_MASK  (0xFFF00000U)
#define GMAC_MAC_VLAN_INCL0_Reserved_31_20_SHIFT (20U)
#define GMAC_MAC_VLAN_INCL0_Reserved_31_20_WIDTH (12U)
#define GMAC_MAC_VLAN_INCL0_Reserved_31_20(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL0_Reserved_31_20_SHIFT)) & GMAC_MAC_VLAN_INCL0_Reserved_31_20_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL1 -  */
/*! @{ */

#define GMAC_MAC_VLAN_INCL1_VLT_MASK             (0xFFFFU)
#define GMAC_MAC_VLAN_INCL1_VLT_SHIFT            (0U)
#define GMAC_MAC_VLAN_INCL1_VLT_WIDTH            (16U)
#define GMAC_MAC_VLAN_INCL1_VLT(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL1_VLT_SHIFT)) & GMAC_MAC_VLAN_INCL1_VLT_MASK)

#define GMAC_MAC_VLAN_INCL1_Reserved_18_16_MASK  (0x70000U)
#define GMAC_MAC_VLAN_INCL1_Reserved_18_16_SHIFT (16U)
#define GMAC_MAC_VLAN_INCL1_Reserved_18_16_WIDTH (3U)
#define GMAC_MAC_VLAN_INCL1_Reserved_18_16(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL1_Reserved_18_16_SHIFT)) & GMAC_MAC_VLAN_INCL1_Reserved_18_16_MASK)

#define GMAC_MAC_VLAN_INCL1_CSVL_MASK            (0x80000U)
#define GMAC_MAC_VLAN_INCL1_CSVL_SHIFT           (19U)
#define GMAC_MAC_VLAN_INCL1_CSVL_WIDTH           (1U)
#define GMAC_MAC_VLAN_INCL1_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL1_CSVL_SHIFT)) & GMAC_MAC_VLAN_INCL1_CSVL_MASK)

#define GMAC_MAC_VLAN_INCL1_Reserved_31_20_MASK  (0xFFF00000U)
#define GMAC_MAC_VLAN_INCL1_Reserved_31_20_SHIFT (20U)
#define GMAC_MAC_VLAN_INCL1_Reserved_31_20_WIDTH (12U)
#define GMAC_MAC_VLAN_INCL1_Reserved_31_20(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL1_Reserved_31_20_SHIFT)) & GMAC_MAC_VLAN_INCL1_Reserved_31_20_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL2 -  */
/*! @{ */

#define GMAC_MAC_VLAN_INCL2_VLT_MASK             (0xFFFFU)
#define GMAC_MAC_VLAN_INCL2_VLT_SHIFT            (0U)
#define GMAC_MAC_VLAN_INCL2_VLT_WIDTH            (16U)
#define GMAC_MAC_VLAN_INCL2_VLT(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL2_VLT_SHIFT)) & GMAC_MAC_VLAN_INCL2_VLT_MASK)

#define GMAC_MAC_VLAN_INCL2_Reserved_18_16_MASK  (0x70000U)
#define GMAC_MAC_VLAN_INCL2_Reserved_18_16_SHIFT (16U)
#define GMAC_MAC_VLAN_INCL2_Reserved_18_16_WIDTH (3U)
#define GMAC_MAC_VLAN_INCL2_Reserved_18_16(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL2_Reserved_18_16_SHIFT)) & GMAC_MAC_VLAN_INCL2_Reserved_18_16_MASK)

#define GMAC_MAC_VLAN_INCL2_CSVL_MASK            (0x80000U)
#define GMAC_MAC_VLAN_INCL2_CSVL_SHIFT           (19U)
#define GMAC_MAC_VLAN_INCL2_CSVL_WIDTH           (1U)
#define GMAC_MAC_VLAN_INCL2_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL2_CSVL_SHIFT)) & GMAC_MAC_VLAN_INCL2_CSVL_MASK)

#define GMAC_MAC_VLAN_INCL2_Reserved_31_20_MASK  (0xFFF00000U)
#define GMAC_MAC_VLAN_INCL2_Reserved_31_20_SHIFT (20U)
#define GMAC_MAC_VLAN_INCL2_Reserved_31_20_WIDTH (12U)
#define GMAC_MAC_VLAN_INCL2_Reserved_31_20(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL2_Reserved_31_20_SHIFT)) & GMAC_MAC_VLAN_INCL2_Reserved_31_20_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL3 -  */
/*! @{ */

#define GMAC_MAC_VLAN_INCL3_VLT_MASK             (0xFFFFU)
#define GMAC_MAC_VLAN_INCL3_VLT_SHIFT            (0U)
#define GMAC_MAC_VLAN_INCL3_VLT_WIDTH            (16U)
#define GMAC_MAC_VLAN_INCL3_VLT(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL3_VLT_SHIFT)) & GMAC_MAC_VLAN_INCL3_VLT_MASK)

#define GMAC_MAC_VLAN_INCL3_Reserved_18_16_MASK  (0x70000U)
#define GMAC_MAC_VLAN_INCL3_Reserved_18_16_SHIFT (16U)
#define GMAC_MAC_VLAN_INCL3_Reserved_18_16_WIDTH (3U)
#define GMAC_MAC_VLAN_INCL3_Reserved_18_16(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL3_Reserved_18_16_SHIFT)) & GMAC_MAC_VLAN_INCL3_Reserved_18_16_MASK)

#define GMAC_MAC_VLAN_INCL3_CSVL_MASK            (0x80000U)
#define GMAC_MAC_VLAN_INCL3_CSVL_SHIFT           (19U)
#define GMAC_MAC_VLAN_INCL3_CSVL_WIDTH           (1U)
#define GMAC_MAC_VLAN_INCL3_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL3_CSVL_SHIFT)) & GMAC_MAC_VLAN_INCL3_CSVL_MASK)

#define GMAC_MAC_VLAN_INCL3_Reserved_31_20_MASK  (0xFFF00000U)
#define GMAC_MAC_VLAN_INCL3_Reserved_31_20_SHIFT (20U)
#define GMAC_MAC_VLAN_INCL3_Reserved_31_20_WIDTH (12U)
#define GMAC_MAC_VLAN_INCL3_Reserved_31_20(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL3_Reserved_31_20_SHIFT)) & GMAC_MAC_VLAN_INCL3_Reserved_31_20_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL4 -  */
/*! @{ */

#define GMAC_MAC_VLAN_INCL4_VLT_MASK             (0xFFFFU)
#define GMAC_MAC_VLAN_INCL4_VLT_SHIFT            (0U)
#define GMAC_MAC_VLAN_INCL4_VLT_WIDTH            (16U)
#define GMAC_MAC_VLAN_INCL4_VLT(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL4_VLT_SHIFT)) & GMAC_MAC_VLAN_INCL4_VLT_MASK)

#define GMAC_MAC_VLAN_INCL4_Reserved_18_16_MASK  (0x70000U)
#define GMAC_MAC_VLAN_INCL4_Reserved_18_16_SHIFT (16U)
#define GMAC_MAC_VLAN_INCL4_Reserved_18_16_WIDTH (3U)
#define GMAC_MAC_VLAN_INCL4_Reserved_18_16(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL4_Reserved_18_16_SHIFT)) & GMAC_MAC_VLAN_INCL4_Reserved_18_16_MASK)

#define GMAC_MAC_VLAN_INCL4_CSVL_MASK            (0x80000U)
#define GMAC_MAC_VLAN_INCL4_CSVL_SHIFT           (19U)
#define GMAC_MAC_VLAN_INCL4_CSVL_WIDTH           (1U)
#define GMAC_MAC_VLAN_INCL4_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL4_CSVL_SHIFT)) & GMAC_MAC_VLAN_INCL4_CSVL_MASK)

#define GMAC_MAC_VLAN_INCL4_Reserved_31_20_MASK  (0xFFF00000U)
#define GMAC_MAC_VLAN_INCL4_Reserved_31_20_SHIFT (20U)
#define GMAC_MAC_VLAN_INCL4_Reserved_31_20_WIDTH (12U)
#define GMAC_MAC_VLAN_INCL4_Reserved_31_20(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL4_Reserved_31_20_SHIFT)) & GMAC_MAC_VLAN_INCL4_Reserved_31_20_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL5 -  */
/*! @{ */

#define GMAC_MAC_VLAN_INCL5_VLT_MASK             (0xFFFFU)
#define GMAC_MAC_VLAN_INCL5_VLT_SHIFT            (0U)
#define GMAC_MAC_VLAN_INCL5_VLT_WIDTH            (16U)
#define GMAC_MAC_VLAN_INCL5_VLT(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL5_VLT_SHIFT)) & GMAC_MAC_VLAN_INCL5_VLT_MASK)

#define GMAC_MAC_VLAN_INCL5_Reserved_18_16_MASK  (0x70000U)
#define GMAC_MAC_VLAN_INCL5_Reserved_18_16_SHIFT (16U)
#define GMAC_MAC_VLAN_INCL5_Reserved_18_16_WIDTH (3U)
#define GMAC_MAC_VLAN_INCL5_Reserved_18_16(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL5_Reserved_18_16_SHIFT)) & GMAC_MAC_VLAN_INCL5_Reserved_18_16_MASK)

#define GMAC_MAC_VLAN_INCL5_CSVL_MASK            (0x80000U)
#define GMAC_MAC_VLAN_INCL5_CSVL_SHIFT           (19U)
#define GMAC_MAC_VLAN_INCL5_CSVL_WIDTH           (1U)
#define GMAC_MAC_VLAN_INCL5_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL5_CSVL_SHIFT)) & GMAC_MAC_VLAN_INCL5_CSVL_MASK)

#define GMAC_MAC_VLAN_INCL5_Reserved_31_20_MASK  (0xFFF00000U)
#define GMAC_MAC_VLAN_INCL5_Reserved_31_20_SHIFT (20U)
#define GMAC_MAC_VLAN_INCL5_Reserved_31_20_WIDTH (12U)
#define GMAC_MAC_VLAN_INCL5_Reserved_31_20(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL5_Reserved_31_20_SHIFT)) & GMAC_MAC_VLAN_INCL5_Reserved_31_20_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL6 -  */
/*! @{ */

#define GMAC_MAC_VLAN_INCL6_VLT_MASK             (0xFFFFU)
#define GMAC_MAC_VLAN_INCL6_VLT_SHIFT            (0U)
#define GMAC_MAC_VLAN_INCL6_VLT_WIDTH            (16U)
#define GMAC_MAC_VLAN_INCL6_VLT(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL6_VLT_SHIFT)) & GMAC_MAC_VLAN_INCL6_VLT_MASK)

#define GMAC_MAC_VLAN_INCL6_Reserved_18_16_MASK  (0x70000U)
#define GMAC_MAC_VLAN_INCL6_Reserved_18_16_SHIFT (16U)
#define GMAC_MAC_VLAN_INCL6_Reserved_18_16_WIDTH (3U)
#define GMAC_MAC_VLAN_INCL6_Reserved_18_16(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL6_Reserved_18_16_SHIFT)) & GMAC_MAC_VLAN_INCL6_Reserved_18_16_MASK)

#define GMAC_MAC_VLAN_INCL6_CSVL_MASK            (0x80000U)
#define GMAC_MAC_VLAN_INCL6_CSVL_SHIFT           (19U)
#define GMAC_MAC_VLAN_INCL6_CSVL_WIDTH           (1U)
#define GMAC_MAC_VLAN_INCL6_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL6_CSVL_SHIFT)) & GMAC_MAC_VLAN_INCL6_CSVL_MASK)

#define GMAC_MAC_VLAN_INCL6_Reserved_31_20_MASK  (0xFFF00000U)
#define GMAC_MAC_VLAN_INCL6_Reserved_31_20_SHIFT (20U)
#define GMAC_MAC_VLAN_INCL6_Reserved_31_20_WIDTH (12U)
#define GMAC_MAC_VLAN_INCL6_Reserved_31_20(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL6_Reserved_31_20_SHIFT)) & GMAC_MAC_VLAN_INCL6_Reserved_31_20_MASK)
/*! @} */

/*! @name MAC_VLAN_INCL7 -  */
/*! @{ */

#define GMAC_MAC_VLAN_INCL7_VLT_MASK             (0xFFFFU)
#define GMAC_MAC_VLAN_INCL7_VLT_SHIFT            (0U)
#define GMAC_MAC_VLAN_INCL7_VLT_WIDTH            (16U)
#define GMAC_MAC_VLAN_INCL7_VLT(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL7_VLT_SHIFT)) & GMAC_MAC_VLAN_INCL7_VLT_MASK)

#define GMAC_MAC_VLAN_INCL7_Reserved_18_16_MASK  (0x70000U)
#define GMAC_MAC_VLAN_INCL7_Reserved_18_16_SHIFT (16U)
#define GMAC_MAC_VLAN_INCL7_Reserved_18_16_WIDTH (3U)
#define GMAC_MAC_VLAN_INCL7_Reserved_18_16(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL7_Reserved_18_16_SHIFT)) & GMAC_MAC_VLAN_INCL7_Reserved_18_16_MASK)

#define GMAC_MAC_VLAN_INCL7_CSVL_MASK            (0x80000U)
#define GMAC_MAC_VLAN_INCL7_CSVL_SHIFT           (19U)
#define GMAC_MAC_VLAN_INCL7_CSVL_WIDTH           (1U)
#define GMAC_MAC_VLAN_INCL7_CSVL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL7_CSVL_SHIFT)) & GMAC_MAC_VLAN_INCL7_CSVL_MASK)

#define GMAC_MAC_VLAN_INCL7_Reserved_31_20_MASK  (0xFFF00000U)
#define GMAC_MAC_VLAN_INCL7_Reserved_31_20_SHIFT (20U)
#define GMAC_MAC_VLAN_INCL7_Reserved_31_20_WIDTH (12U)
#define GMAC_MAC_VLAN_INCL7_Reserved_31_20(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VLAN_INCL7_Reserved_31_20_SHIFT)) & GMAC_MAC_VLAN_INCL7_Reserved_31_20_MASK)
/*! @} */

/*! @name MAC_INNER_VLAN_INCL -  */
/*! @{ */

#define GMAC_MAC_INNER_VLAN_INCL_VLT_MASK        (0xFFFFU)
#define GMAC_MAC_INNER_VLAN_INCL_VLT_SHIFT       (0U)
#define GMAC_MAC_INNER_VLAN_INCL_VLT_WIDTH       (16U)
#define GMAC_MAC_INNER_VLAN_INCL_VLT(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INNER_VLAN_INCL_VLT_SHIFT)) & GMAC_MAC_INNER_VLAN_INCL_VLT_MASK)

#define GMAC_MAC_INNER_VLAN_INCL_VLC_MASK        (0x30000U)
#define GMAC_MAC_INNER_VLAN_INCL_VLC_SHIFT       (16U)
#define GMAC_MAC_INNER_VLAN_INCL_VLC_WIDTH       (2U)
#define GMAC_MAC_INNER_VLAN_INCL_VLC(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INNER_VLAN_INCL_VLC_SHIFT)) & GMAC_MAC_INNER_VLAN_INCL_VLC_MASK)

#define GMAC_MAC_INNER_VLAN_INCL_VLP_MASK        (0x40000U)
#define GMAC_MAC_INNER_VLAN_INCL_VLP_SHIFT       (18U)
#define GMAC_MAC_INNER_VLAN_INCL_VLP_WIDTH       (1U)
#define GMAC_MAC_INNER_VLAN_INCL_VLP(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INNER_VLAN_INCL_VLP_SHIFT)) & GMAC_MAC_INNER_VLAN_INCL_VLP_MASK)

#define GMAC_MAC_INNER_VLAN_INCL_CSVL_MASK       (0x80000U)
#define GMAC_MAC_INNER_VLAN_INCL_CSVL_SHIFT      (19U)
#define GMAC_MAC_INNER_VLAN_INCL_CSVL_WIDTH      (1U)
#define GMAC_MAC_INNER_VLAN_INCL_CSVL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INNER_VLAN_INCL_CSVL_SHIFT)) & GMAC_MAC_INNER_VLAN_INCL_CSVL_MASK)

#define GMAC_MAC_INNER_VLAN_INCL_VLTI_MASK       (0x100000U)
#define GMAC_MAC_INNER_VLAN_INCL_VLTI_SHIFT      (20U)
#define GMAC_MAC_INNER_VLAN_INCL_VLTI_WIDTH      (1U)
#define GMAC_MAC_INNER_VLAN_INCL_VLTI(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INNER_VLAN_INCL_VLTI_SHIFT)) & GMAC_MAC_INNER_VLAN_INCL_VLTI_MASK)

#define GMAC_MAC_INNER_VLAN_INCL_Reserved_31_21_MASK (0xFFE00000U)
#define GMAC_MAC_INNER_VLAN_INCL_Reserved_31_21_SHIFT (21U)
#define GMAC_MAC_INNER_VLAN_INCL_Reserved_31_21_WIDTH (11U)
#define GMAC_MAC_INNER_VLAN_INCL_Reserved_31_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INNER_VLAN_INCL_Reserved_31_21_SHIFT)) & GMAC_MAC_INNER_VLAN_INCL_Reserved_31_21_MASK)
/*! @} */

/*! @name MAC_Q0_TX_FLOW_CTRL -  */
/*! @{ */

#define GMAC_MAC_Q0_TX_FLOW_CTRL_FCB_BPA_MASK    (0x1U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_FCB_BPA_SHIFT   (0U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_FCB_BPA_WIDTH   (1U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_FCB_BPA(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q0_TX_FLOW_CTRL_FCB_BPA_SHIFT)) & GMAC_MAC_Q0_TX_FLOW_CTRL_FCB_BPA_MASK)

#define GMAC_MAC_Q0_TX_FLOW_CTRL_TFE_MASK        (0x2U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_TFE_SHIFT       (1U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_TFE_WIDTH       (1U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_TFE(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q0_TX_FLOW_CTRL_TFE_SHIFT)) & GMAC_MAC_Q0_TX_FLOW_CTRL_TFE_MASK)

#define GMAC_MAC_Q0_TX_FLOW_CTRL_Reserved_3_2_MASK (0xCU)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_Reserved_3_2_SHIFT (2U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_Reserved_3_2_WIDTH (2U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_Reserved_3_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q0_TX_FLOW_CTRL_Reserved_3_2_SHIFT)) & GMAC_MAC_Q0_TX_FLOW_CTRL_Reserved_3_2_MASK)

#define GMAC_MAC_Q0_TX_FLOW_CTRL_PLT_MASK        (0x70U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_PLT_SHIFT       (4U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_PLT_WIDTH       (3U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_PLT(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q0_TX_FLOW_CTRL_PLT_SHIFT)) & GMAC_MAC_Q0_TX_FLOW_CTRL_PLT_MASK)

#define GMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ_MASK       (0x80U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ_SHIFT      (7U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ_WIDTH      (1U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ_SHIFT)) & GMAC_MAC_Q0_TX_FLOW_CTRL_DZPQ_MASK)

#define GMAC_MAC_Q0_TX_FLOW_CTRL_Reserved_15_8_MASK (0xFF00U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_Reserved_15_8_SHIFT (8U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_Reserved_15_8_WIDTH (8U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_Reserved_15_8(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q0_TX_FLOW_CTRL_Reserved_15_8_SHIFT)) & GMAC_MAC_Q0_TX_FLOW_CTRL_Reserved_15_8_MASK)

#define GMAC_MAC_Q0_TX_FLOW_CTRL_PT_MASK         (0xFFFF0000U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_PT_SHIFT        (16U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_PT_WIDTH        (16U)
#define GMAC_MAC_Q0_TX_FLOW_CTRL_PT(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q0_TX_FLOW_CTRL_PT_SHIFT)) & GMAC_MAC_Q0_TX_FLOW_CTRL_PT_MASK)
/*! @} */

/*! @name MAC_Q1_TX_FLOW_CTRL -  */
/*! @{ */

#define GMAC_MAC_Q1_TX_FLOW_CTRL_FCB_BPA_MASK    (0x1U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_FCB_BPA_SHIFT   (0U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_FCB_BPA_WIDTH   (1U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_FCB_BPA(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q1_TX_FLOW_CTRL_FCB_BPA_SHIFT)) & GMAC_MAC_Q1_TX_FLOW_CTRL_FCB_BPA_MASK)

#define GMAC_MAC_Q1_TX_FLOW_CTRL_TFE_MASK        (0x2U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_TFE_SHIFT       (1U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_TFE_WIDTH       (1U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_TFE(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q1_TX_FLOW_CTRL_TFE_SHIFT)) & GMAC_MAC_Q1_TX_FLOW_CTRL_TFE_MASK)

#define GMAC_MAC_Q1_TX_FLOW_CTRL_Reserved_3_2_MASK (0xCU)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_Reserved_3_2_SHIFT (2U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_Reserved_3_2_WIDTH (2U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_Reserved_3_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q1_TX_FLOW_CTRL_Reserved_3_2_SHIFT)) & GMAC_MAC_Q1_TX_FLOW_CTRL_Reserved_3_2_MASK)

#define GMAC_MAC_Q1_TX_FLOW_CTRL_PLT_MASK        (0x70U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_PLT_SHIFT       (4U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_PLT_WIDTH       (3U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_PLT(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q1_TX_FLOW_CTRL_PLT_SHIFT)) & GMAC_MAC_Q1_TX_FLOW_CTRL_PLT_MASK)

#define GMAC_MAC_Q1_TX_FLOW_CTRL_DZPQ_MASK       (0x80U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_DZPQ_SHIFT      (7U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_DZPQ_WIDTH      (1U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_DZPQ(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q1_TX_FLOW_CTRL_DZPQ_SHIFT)) & GMAC_MAC_Q1_TX_FLOW_CTRL_DZPQ_MASK)

#define GMAC_MAC_Q1_TX_FLOW_CTRL_Reserved_15_8_MASK (0xFF00U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_Reserved_15_8_SHIFT (8U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_Reserved_15_8_WIDTH (8U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_Reserved_15_8(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q1_TX_FLOW_CTRL_Reserved_15_8_SHIFT)) & GMAC_MAC_Q1_TX_FLOW_CTRL_Reserved_15_8_MASK)

#define GMAC_MAC_Q1_TX_FLOW_CTRL_PT_MASK         (0xFFFF0000U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_PT_SHIFT        (16U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_PT_WIDTH        (16U)
#define GMAC_MAC_Q1_TX_FLOW_CTRL_PT(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q1_TX_FLOW_CTRL_PT_SHIFT)) & GMAC_MAC_Q1_TX_FLOW_CTRL_PT_MASK)
/*! @} */

/*! @name MAC_Q2_TX_FLOW_CTRL -  */
/*! @{ */

#define GMAC_MAC_Q2_TX_FLOW_CTRL_FCB_BPA_MASK    (0x1U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_FCB_BPA_SHIFT   (0U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_FCB_BPA_WIDTH   (1U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_FCB_BPA(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q2_TX_FLOW_CTRL_FCB_BPA_SHIFT)) & GMAC_MAC_Q2_TX_FLOW_CTRL_FCB_BPA_MASK)

#define GMAC_MAC_Q2_TX_FLOW_CTRL_TFE_MASK        (0x2U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_TFE_SHIFT       (1U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_TFE_WIDTH       (1U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_TFE(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q2_TX_FLOW_CTRL_TFE_SHIFT)) & GMAC_MAC_Q2_TX_FLOW_CTRL_TFE_MASK)

#define GMAC_MAC_Q2_TX_FLOW_CTRL_Reserved_3_2_MASK (0xCU)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_Reserved_3_2_SHIFT (2U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_Reserved_3_2_WIDTH (2U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_Reserved_3_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q2_TX_FLOW_CTRL_Reserved_3_2_SHIFT)) & GMAC_MAC_Q2_TX_FLOW_CTRL_Reserved_3_2_MASK)

#define GMAC_MAC_Q2_TX_FLOW_CTRL_PLT_MASK        (0x70U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_PLT_SHIFT       (4U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_PLT_WIDTH       (3U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_PLT(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q2_TX_FLOW_CTRL_PLT_SHIFT)) & GMAC_MAC_Q2_TX_FLOW_CTRL_PLT_MASK)

#define GMAC_MAC_Q2_TX_FLOW_CTRL_DZPQ_MASK       (0x80U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_DZPQ_SHIFT      (7U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_DZPQ_WIDTH      (1U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_DZPQ(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q2_TX_FLOW_CTRL_DZPQ_SHIFT)) & GMAC_MAC_Q2_TX_FLOW_CTRL_DZPQ_MASK)

#define GMAC_MAC_Q2_TX_FLOW_CTRL_Reserved_15_8_MASK (0xFF00U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_Reserved_15_8_SHIFT (8U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_Reserved_15_8_WIDTH (8U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_Reserved_15_8(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q2_TX_FLOW_CTRL_Reserved_15_8_SHIFT)) & GMAC_MAC_Q2_TX_FLOW_CTRL_Reserved_15_8_MASK)

#define GMAC_MAC_Q2_TX_FLOW_CTRL_PT_MASK         (0xFFFF0000U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_PT_SHIFT        (16U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_PT_WIDTH        (16U)
#define GMAC_MAC_Q2_TX_FLOW_CTRL_PT(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_Q2_TX_FLOW_CTRL_PT_SHIFT)) & GMAC_MAC_Q2_TX_FLOW_CTRL_PT_MASK)
/*! @} */

/*! @name MAC_RX_FLOW_CTRL -  */
/*! @{ */

#define GMAC_MAC_RX_FLOW_CTRL_RFE_MASK           (0x1U)
#define GMAC_MAC_RX_FLOW_CTRL_RFE_SHIFT          (0U)
#define GMAC_MAC_RX_FLOW_CTRL_RFE_WIDTH          (1U)
#define GMAC_MAC_RX_FLOW_CTRL_RFE(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RX_FLOW_CTRL_RFE_SHIFT)) & GMAC_MAC_RX_FLOW_CTRL_RFE_MASK)

#define GMAC_MAC_RX_FLOW_CTRL_UP_MASK            (0x2U)
#define GMAC_MAC_RX_FLOW_CTRL_UP_SHIFT           (1U)
#define GMAC_MAC_RX_FLOW_CTRL_UP_WIDTH           (1U)
#define GMAC_MAC_RX_FLOW_CTRL_UP(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RX_FLOW_CTRL_UP_SHIFT)) & GMAC_MAC_RX_FLOW_CTRL_UP_MASK)

#define GMAC_MAC_RX_FLOW_CTRL_Reserved_7_2_MASK  (0xFCU)
#define GMAC_MAC_RX_FLOW_CTRL_Reserved_7_2_SHIFT (2U)
#define GMAC_MAC_RX_FLOW_CTRL_Reserved_7_2_WIDTH (6U)
#define GMAC_MAC_RX_FLOW_CTRL_Reserved_7_2(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RX_FLOW_CTRL_Reserved_7_2_SHIFT)) & GMAC_MAC_RX_FLOW_CTRL_Reserved_7_2_MASK)

#define GMAC_MAC_RX_FLOW_CTRL_PFCE_MASK          (0x100U)
#define GMAC_MAC_RX_FLOW_CTRL_PFCE_SHIFT         (8U)
#define GMAC_MAC_RX_FLOW_CTRL_PFCE_WIDTH         (1U)
#define GMAC_MAC_RX_FLOW_CTRL_PFCE(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RX_FLOW_CTRL_PFCE_SHIFT)) & GMAC_MAC_RX_FLOW_CTRL_PFCE_MASK)

#define GMAC_MAC_RX_FLOW_CTRL_Reserved_31_9_MASK (0xFFFFFE00U)
#define GMAC_MAC_RX_FLOW_CTRL_Reserved_31_9_SHIFT (9U)
#define GMAC_MAC_RX_FLOW_CTRL_Reserved_31_9_WIDTH (23U)
#define GMAC_MAC_RX_FLOW_CTRL_Reserved_31_9(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RX_FLOW_CTRL_Reserved_31_9_SHIFT)) & GMAC_MAC_RX_FLOW_CTRL_Reserved_31_9_MASK)
/*! @} */

/*! @name MAC_RXQ_CTRL4 -  */
/*! @{ */

#define GMAC_MAC_RXQ_CTRL4_UFFQE_MASK            (0x1U)
#define GMAC_MAC_RXQ_CTRL4_UFFQE_SHIFT           (0U)
#define GMAC_MAC_RXQ_CTRL4_UFFQE_WIDTH           (1U)
#define GMAC_MAC_RXQ_CTRL4_UFFQE(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL4_UFFQE_SHIFT)) & GMAC_MAC_RXQ_CTRL4_UFFQE_MASK)

#define GMAC_MAC_RXQ_CTRL4_UFFQ_MASK             (0x6U)
#define GMAC_MAC_RXQ_CTRL4_UFFQ_SHIFT            (1U)
#define GMAC_MAC_RXQ_CTRL4_UFFQ_WIDTH            (2U)
#define GMAC_MAC_RXQ_CTRL4_UFFQ(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL4_UFFQ_SHIFT)) & GMAC_MAC_RXQ_CTRL4_UFFQ_MASK)

#define GMAC_MAC_RXQ_CTRL4_Reserved_7_y_MASK     (0xF8U)
#define GMAC_MAC_RXQ_CTRL4_Reserved_7_y_SHIFT    (3U)
#define GMAC_MAC_RXQ_CTRL4_Reserved_7_y_WIDTH    (5U)
#define GMAC_MAC_RXQ_CTRL4_Reserved_7_y(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL4_Reserved_7_y_SHIFT)) & GMAC_MAC_RXQ_CTRL4_Reserved_7_y_MASK)

#define GMAC_MAC_RXQ_CTRL4_MFFQE_MASK            (0x100U)
#define GMAC_MAC_RXQ_CTRL4_MFFQE_SHIFT           (8U)
#define GMAC_MAC_RXQ_CTRL4_MFFQE_WIDTH           (1U)
#define GMAC_MAC_RXQ_CTRL4_MFFQE(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL4_MFFQE_SHIFT)) & GMAC_MAC_RXQ_CTRL4_MFFQE_MASK)

#define GMAC_MAC_RXQ_CTRL4_MFFQ_MASK             (0x600U)
#define GMAC_MAC_RXQ_CTRL4_MFFQ_SHIFT            (9U)
#define GMAC_MAC_RXQ_CTRL4_MFFQ_WIDTH            (2U)
#define GMAC_MAC_RXQ_CTRL4_MFFQ(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL4_MFFQ_SHIFT)) & GMAC_MAC_RXQ_CTRL4_MFFQ_MASK)

#define GMAC_MAC_RXQ_CTRL4_Reserved_15_y_MASK    (0xF800U)
#define GMAC_MAC_RXQ_CTRL4_Reserved_15_y_SHIFT   (11U)
#define GMAC_MAC_RXQ_CTRL4_Reserved_15_y_WIDTH   (5U)
#define GMAC_MAC_RXQ_CTRL4_Reserved_15_y(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL4_Reserved_15_y_SHIFT)) & GMAC_MAC_RXQ_CTRL4_Reserved_15_y_MASK)

#define GMAC_MAC_RXQ_CTRL4_VFFQE_MASK            (0x10000U)
#define GMAC_MAC_RXQ_CTRL4_VFFQE_SHIFT           (16U)
#define GMAC_MAC_RXQ_CTRL4_VFFQE_WIDTH           (1U)
#define GMAC_MAC_RXQ_CTRL4_VFFQE(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL4_VFFQE_SHIFT)) & GMAC_MAC_RXQ_CTRL4_VFFQE_MASK)

#define GMAC_MAC_RXQ_CTRL4_VFFQ_MASK             (0x60000U)
#define GMAC_MAC_RXQ_CTRL4_VFFQ_SHIFT            (17U)
#define GMAC_MAC_RXQ_CTRL4_VFFQ_WIDTH            (2U)
#define GMAC_MAC_RXQ_CTRL4_VFFQ(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL4_VFFQ_SHIFT)) & GMAC_MAC_RXQ_CTRL4_VFFQ_MASK)

#define GMAC_MAC_RXQ_CTRL4_Reserved_31_y_MASK    (0xFFF80000U)
#define GMAC_MAC_RXQ_CTRL4_Reserved_31_y_SHIFT   (19U)
#define GMAC_MAC_RXQ_CTRL4_Reserved_31_y_WIDTH   (13U)
#define GMAC_MAC_RXQ_CTRL4_Reserved_31_y(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL4_Reserved_31_y_SHIFT)) & GMAC_MAC_RXQ_CTRL4_Reserved_31_y_MASK)
/*! @} */

/*! @name MAC_TXQ_PRTY_MAP0 -  */
/*! @{ */

#define GMAC_MAC_TXQ_PRTY_MAP0_PSTQ0_MASK        (0xFFU)
#define GMAC_MAC_TXQ_PRTY_MAP0_PSTQ0_SHIFT       (0U)
#define GMAC_MAC_TXQ_PRTY_MAP0_PSTQ0_WIDTH       (8U)
#define GMAC_MAC_TXQ_PRTY_MAP0_PSTQ0(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TXQ_PRTY_MAP0_PSTQ0_SHIFT)) & GMAC_MAC_TXQ_PRTY_MAP0_PSTQ0_MASK)

#define GMAC_MAC_TXQ_PRTY_MAP0_PSTQ1_MASK        (0xFF00U)
#define GMAC_MAC_TXQ_PRTY_MAP0_PSTQ1_SHIFT       (8U)
#define GMAC_MAC_TXQ_PRTY_MAP0_PSTQ1_WIDTH       (8U)
#define GMAC_MAC_TXQ_PRTY_MAP0_PSTQ1(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TXQ_PRTY_MAP0_PSTQ1_SHIFT)) & GMAC_MAC_TXQ_PRTY_MAP0_PSTQ1_MASK)

#define GMAC_MAC_TXQ_PRTY_MAP0_PSTQ2_MASK        (0xFF0000U)
#define GMAC_MAC_TXQ_PRTY_MAP0_PSTQ2_SHIFT       (16U)
#define GMAC_MAC_TXQ_PRTY_MAP0_PSTQ2_WIDTH       (8U)
#define GMAC_MAC_TXQ_PRTY_MAP0_PSTQ2(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TXQ_PRTY_MAP0_PSTQ2_SHIFT)) & GMAC_MAC_TXQ_PRTY_MAP0_PSTQ2_MASK)

#define GMAC_MAC_TXQ_PRTY_MAP0_Reserved_PSTQ3_MASK (0xFF000000U)
#define GMAC_MAC_TXQ_PRTY_MAP0_Reserved_PSTQ3_SHIFT (24U)
#define GMAC_MAC_TXQ_PRTY_MAP0_Reserved_PSTQ3_WIDTH (8U)
#define GMAC_MAC_TXQ_PRTY_MAP0_Reserved_PSTQ3(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TXQ_PRTY_MAP0_Reserved_PSTQ3_SHIFT)) & GMAC_MAC_TXQ_PRTY_MAP0_Reserved_PSTQ3_MASK)
/*! @} */

/*! @name MAC_RXQ_CTRL0 -  */
/*! @{ */

#define GMAC_MAC_RXQ_CTRL0_RXQ0EN_MASK           (0x3U)
#define GMAC_MAC_RXQ_CTRL0_RXQ0EN_SHIFT          (0U)
#define GMAC_MAC_RXQ_CTRL0_RXQ0EN_WIDTH          (2U)
#define GMAC_MAC_RXQ_CTRL0_RXQ0EN(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL0_RXQ0EN_SHIFT)) & GMAC_MAC_RXQ_CTRL0_RXQ0EN_MASK)

#define GMAC_MAC_RXQ_CTRL0_RXQ1EN_MASK           (0xCU)
#define GMAC_MAC_RXQ_CTRL0_RXQ1EN_SHIFT          (2U)
#define GMAC_MAC_RXQ_CTRL0_RXQ1EN_WIDTH          (2U)
#define GMAC_MAC_RXQ_CTRL0_RXQ1EN(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL0_RXQ1EN_SHIFT)) & GMAC_MAC_RXQ_CTRL0_RXQ1EN_MASK)

#define GMAC_MAC_RXQ_CTRL0_RXQ2EN_MASK           (0x30U)
#define GMAC_MAC_RXQ_CTRL0_RXQ2EN_SHIFT          (4U)
#define GMAC_MAC_RXQ_CTRL0_RXQ2EN_WIDTH          (2U)
#define GMAC_MAC_RXQ_CTRL0_RXQ2EN(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL0_RXQ2EN_SHIFT)) & GMAC_MAC_RXQ_CTRL0_RXQ2EN_MASK)

#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ3EN_MASK  (0xC0U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ3EN_SHIFT (6U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ3EN_WIDTH (2U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ3EN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL0_Reserved_RXQ3EN_SHIFT)) & GMAC_MAC_RXQ_CTRL0_Reserved_RXQ3EN_MASK)

#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ4EN_MASK  (0x300U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ4EN_SHIFT (8U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ4EN_WIDTH (2U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ4EN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL0_Reserved_RXQ4EN_SHIFT)) & GMAC_MAC_RXQ_CTRL0_Reserved_RXQ4EN_MASK)

#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ5EN_MASK  (0xC00U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ5EN_SHIFT (10U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ5EN_WIDTH (2U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ5EN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL0_Reserved_RXQ5EN_SHIFT)) & GMAC_MAC_RXQ_CTRL0_Reserved_RXQ5EN_MASK)

#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ6EN_MASK  (0x3000U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ6EN_SHIFT (12U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ6EN_WIDTH (2U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ6EN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL0_Reserved_RXQ6EN_SHIFT)) & GMAC_MAC_RXQ_CTRL0_Reserved_RXQ6EN_MASK)

#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ7EN_MASK  (0xC000U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ7EN_SHIFT (14U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ7EN_WIDTH (2U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_RXQ7EN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL0_Reserved_RXQ7EN_SHIFT)) & GMAC_MAC_RXQ_CTRL0_Reserved_RXQ7EN_MASK)

#define GMAC_MAC_RXQ_CTRL0_Reserved_31_16_MASK   (0xFFFF0000U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_31_16_SHIFT  (16U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_31_16_WIDTH  (16U)
#define GMAC_MAC_RXQ_CTRL0_Reserved_31_16(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL0_Reserved_31_16_SHIFT)) & GMAC_MAC_RXQ_CTRL0_Reserved_31_16_MASK)
/*! @} */

/*! @name MAC_RXQ_CTRL1 -  */
/*! @{ */

#define GMAC_MAC_RXQ_CTRL1_AVCPQ_MASK            (0x7U)
#define GMAC_MAC_RXQ_CTRL1_AVCPQ_SHIFT           (0U)
#define GMAC_MAC_RXQ_CTRL1_AVCPQ_WIDTH           (3U)
#define GMAC_MAC_RXQ_CTRL1_AVCPQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_AVCPQ_SHIFT)) & GMAC_MAC_RXQ_CTRL1_AVCPQ_MASK)

#define GMAC_MAC_RXQ_CTRL1_Reserved_3_MASK       (0x8U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_3_SHIFT      (3U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_3_WIDTH      (1U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_3(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_Reserved_3_SHIFT)) & GMAC_MAC_RXQ_CTRL1_Reserved_3_MASK)

#define GMAC_MAC_RXQ_CTRL1_PTPQ_MASK             (0x70U)
#define GMAC_MAC_RXQ_CTRL1_PTPQ_SHIFT            (4U)
#define GMAC_MAC_RXQ_CTRL1_PTPQ_WIDTH            (3U)
#define GMAC_MAC_RXQ_CTRL1_PTPQ(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_PTPQ_SHIFT)) & GMAC_MAC_RXQ_CTRL1_PTPQ_MASK)

#define GMAC_MAC_RXQ_CTRL1_Reserved_7_MASK       (0x80U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_7_SHIFT      (7U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_7_WIDTH      (1U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_7(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_Reserved_7_SHIFT)) & GMAC_MAC_RXQ_CTRL1_Reserved_7_MASK)

#define GMAC_MAC_RXQ_CTRL1_DCBCPQ_MASK           (0x700U)
#define GMAC_MAC_RXQ_CTRL1_DCBCPQ_SHIFT          (8U)
#define GMAC_MAC_RXQ_CTRL1_DCBCPQ_WIDTH          (3U)
#define GMAC_MAC_RXQ_CTRL1_DCBCPQ(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_DCBCPQ_SHIFT)) & GMAC_MAC_RXQ_CTRL1_DCBCPQ_MASK)

#define GMAC_MAC_RXQ_CTRL1_Reserved_11_MASK      (0x800U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_11_SHIFT     (11U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_11_WIDTH     (1U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_11(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_Reserved_11_SHIFT)) & GMAC_MAC_RXQ_CTRL1_Reserved_11_MASK)

#define GMAC_MAC_RXQ_CTRL1_UPQ_MASK              (0x7000U)
#define GMAC_MAC_RXQ_CTRL1_UPQ_SHIFT             (12U)
#define GMAC_MAC_RXQ_CTRL1_UPQ_WIDTH             (3U)
#define GMAC_MAC_RXQ_CTRL1_UPQ(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_UPQ_SHIFT)) & GMAC_MAC_RXQ_CTRL1_UPQ_MASK)

#define GMAC_MAC_RXQ_CTRL1_Reserved_15_MASK      (0x8000U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_15_SHIFT     (15U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_15_WIDTH     (1U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_15(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_Reserved_15_SHIFT)) & GMAC_MAC_RXQ_CTRL1_Reserved_15_MASK)

#define GMAC_MAC_RXQ_CTRL1_MCBCQ_MASK            (0x70000U)
#define GMAC_MAC_RXQ_CTRL1_MCBCQ_SHIFT           (16U)
#define GMAC_MAC_RXQ_CTRL1_MCBCQ_WIDTH           (3U)
#define GMAC_MAC_RXQ_CTRL1_MCBCQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_MCBCQ_SHIFT)) & GMAC_MAC_RXQ_CTRL1_MCBCQ_MASK)

#define GMAC_MAC_RXQ_CTRL1_Reserved_19_MASK      (0x80000U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_19_SHIFT     (19U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_19_WIDTH     (1U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_19(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_Reserved_19_SHIFT)) & GMAC_MAC_RXQ_CTRL1_Reserved_19_MASK)

#define GMAC_MAC_RXQ_CTRL1_MCBCQEN_MASK          (0x100000U)
#define GMAC_MAC_RXQ_CTRL1_MCBCQEN_SHIFT         (20U)
#define GMAC_MAC_RXQ_CTRL1_MCBCQEN_WIDTH         (1U)
#define GMAC_MAC_RXQ_CTRL1_MCBCQEN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_MCBCQEN_SHIFT)) & GMAC_MAC_RXQ_CTRL1_MCBCQEN_MASK)

#define GMAC_MAC_RXQ_CTRL1_TACPQE_MASK           (0x200000U)
#define GMAC_MAC_RXQ_CTRL1_TACPQE_SHIFT          (21U)
#define GMAC_MAC_RXQ_CTRL1_TACPQE_WIDTH          (1U)
#define GMAC_MAC_RXQ_CTRL1_TACPQE(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_TACPQE_SHIFT)) & GMAC_MAC_RXQ_CTRL1_TACPQE_MASK)

#define GMAC_MAC_RXQ_CTRL1_TPQC_MASK             (0xC00000U)
#define GMAC_MAC_RXQ_CTRL1_TPQC_SHIFT            (22U)
#define GMAC_MAC_RXQ_CTRL1_TPQC_WIDTH            (2U)
#define GMAC_MAC_RXQ_CTRL1_TPQC(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_TPQC_SHIFT)) & GMAC_MAC_RXQ_CTRL1_TPQC_MASK)

#define GMAC_MAC_RXQ_CTRL1_FPRQ_MASK             (0x7000000U)
#define GMAC_MAC_RXQ_CTRL1_FPRQ_SHIFT            (24U)
#define GMAC_MAC_RXQ_CTRL1_FPRQ_WIDTH            (3U)
#define GMAC_MAC_RXQ_CTRL1_FPRQ(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_FPRQ_SHIFT)) & GMAC_MAC_RXQ_CTRL1_FPRQ_MASK)

#define GMAC_MAC_RXQ_CTRL1_Reserved_27_MASK      (0x8000000U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_27_SHIFT     (27U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_27_WIDTH     (1U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_27(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_Reserved_27_SHIFT)) & GMAC_MAC_RXQ_CTRL1_Reserved_27_MASK)

#define GMAC_MAC_RXQ_CTRL1_OMCBCQ_MASK           (0x10000000U)
#define GMAC_MAC_RXQ_CTRL1_OMCBCQ_SHIFT          (28U)
#define GMAC_MAC_RXQ_CTRL1_OMCBCQ_WIDTH          (1U)
#define GMAC_MAC_RXQ_CTRL1_OMCBCQ(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_OMCBCQ_SHIFT)) & GMAC_MAC_RXQ_CTRL1_OMCBCQ_MASK)

#define GMAC_MAC_RXQ_CTRL1_TBRQE_MASK            (0x20000000U)
#define GMAC_MAC_RXQ_CTRL1_TBRQE_SHIFT           (29U)
#define GMAC_MAC_RXQ_CTRL1_TBRQE_WIDTH           (1U)
#define GMAC_MAC_RXQ_CTRL1_TBRQE(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_TBRQE_SHIFT)) & GMAC_MAC_RXQ_CTRL1_TBRQE_MASK)

#define GMAC_MAC_RXQ_CTRL1_Reserved_31_30_MASK   (0xC0000000U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_31_30_SHIFT  (30U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_31_30_WIDTH  (2U)
#define GMAC_MAC_RXQ_CTRL1_Reserved_31_30(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL1_Reserved_31_30_SHIFT)) & GMAC_MAC_RXQ_CTRL1_Reserved_31_30_MASK)
/*! @} */

/*! @name MAC_RXQ_CTRL2 -  */
/*! @{ */

#define GMAC_MAC_RXQ_CTRL2_PSRQ0_MASK            (0xFFU)
#define GMAC_MAC_RXQ_CTRL2_PSRQ0_SHIFT           (0U)
#define GMAC_MAC_RXQ_CTRL2_PSRQ0_WIDTH           (8U)
#define GMAC_MAC_RXQ_CTRL2_PSRQ0(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL2_PSRQ0_SHIFT)) & GMAC_MAC_RXQ_CTRL2_PSRQ0_MASK)

#define GMAC_MAC_RXQ_CTRL2_PSRQ1_MASK            (0xFF00U)
#define GMAC_MAC_RXQ_CTRL2_PSRQ1_SHIFT           (8U)
#define GMAC_MAC_RXQ_CTRL2_PSRQ1_WIDTH           (8U)
#define GMAC_MAC_RXQ_CTRL2_PSRQ1(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL2_PSRQ1_SHIFT)) & GMAC_MAC_RXQ_CTRL2_PSRQ1_MASK)

#define GMAC_MAC_RXQ_CTRL2_PSRQ2_MASK            (0xFF0000U)
#define GMAC_MAC_RXQ_CTRL2_PSRQ2_SHIFT           (16U)
#define GMAC_MAC_RXQ_CTRL2_PSRQ2_WIDTH           (8U)
#define GMAC_MAC_RXQ_CTRL2_PSRQ2(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL2_PSRQ2_SHIFT)) & GMAC_MAC_RXQ_CTRL2_PSRQ2_MASK)

#define GMAC_MAC_RXQ_CTRL2_Reserved_PSRQ3_MASK   (0xFF000000U)
#define GMAC_MAC_RXQ_CTRL2_Reserved_PSRQ3_SHIFT  (24U)
#define GMAC_MAC_RXQ_CTRL2_Reserved_PSRQ3_WIDTH  (8U)
#define GMAC_MAC_RXQ_CTRL2_Reserved_PSRQ3(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RXQ_CTRL2_Reserved_PSRQ3_SHIFT)) & GMAC_MAC_RXQ_CTRL2_Reserved_PSRQ3_MASK)
/*! @} */

/*! @name MAC_INTERRUPT_STATUS -  */
/*! @{ */

#define GMAC_MAC_INTERRUPT_STATUS_RGSMIIIS_MASK  (0x1U)
#define GMAC_MAC_INTERRUPT_STATUS_RGSMIIIS_SHIFT (0U)
#define GMAC_MAC_INTERRUPT_STATUS_RGSMIIIS_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_STATUS_RGSMIIIS(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_RGSMIIIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_RGSMIIIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_Reserved_PCSLCHGIS_MASK (0x2U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_PCSLCHGIS_SHIFT (1U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_PCSLCHGIS_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_PCSLCHGIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_Reserved_PCSLCHGIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_Reserved_PCSLCHGIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_Reserved_PCSANCIS_MASK (0x4U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_PCSANCIS_SHIFT (2U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_PCSANCIS_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_PCSANCIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_Reserved_PCSANCIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_Reserved_PCSANCIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_PHYIS_MASK     (0x8U)
#define GMAC_MAC_INTERRUPT_STATUS_PHYIS_SHIFT    (3U)
#define GMAC_MAC_INTERRUPT_STATUS_PHYIS_WIDTH    (1U)
#define GMAC_MAC_INTERRUPT_STATUS_PHYIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_PHYIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_PHYIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_Reserved_PMTIS_MASK (0x10U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_PMTIS_SHIFT (4U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_PMTIS_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_PMTIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_Reserved_PMTIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_Reserved_PMTIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_Reserved_LPIIS_MASK (0x20U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_LPIIS_SHIFT (5U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_LPIIS_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_LPIIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_Reserved_LPIIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_Reserved_LPIIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_Reserved_7_6_MASK (0xC0U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_7_6_SHIFT (6U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_7_6_WIDTH (2U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_7_6(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_Reserved_7_6_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_Reserved_7_6_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_MMCIS_MASK     (0x100U)
#define GMAC_MAC_INTERRUPT_STATUS_MMCIS_SHIFT    (8U)
#define GMAC_MAC_INTERRUPT_STATUS_MMCIS_WIDTH    (1U)
#define GMAC_MAC_INTERRUPT_STATUS_MMCIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_MMCIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_MMCIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_MMCRXIS_MASK   (0x200U)
#define GMAC_MAC_INTERRUPT_STATUS_MMCRXIS_SHIFT  (9U)
#define GMAC_MAC_INTERRUPT_STATUS_MMCRXIS_WIDTH  (1U)
#define GMAC_MAC_INTERRUPT_STATUS_MMCRXIS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_MMCRXIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_MMCRXIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_MMCTXIS_MASK   (0x400U)
#define GMAC_MAC_INTERRUPT_STATUS_MMCTXIS_SHIFT  (10U)
#define GMAC_MAC_INTERRUPT_STATUS_MMCTXIS_WIDTH  (1U)
#define GMAC_MAC_INTERRUPT_STATUS_MMCTXIS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_MMCTXIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_MMCTXIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_Reserved_MMCRXIPIS_MASK (0x800U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_MMCRXIPIS_SHIFT (11U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_MMCRXIPIS_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_MMCRXIPIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_Reserved_MMCRXIPIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_Reserved_MMCRXIPIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_TSIS_MASK      (0x1000U)
#define GMAC_MAC_INTERRUPT_STATUS_TSIS_SHIFT     (12U)
#define GMAC_MAC_INTERRUPT_STATUS_TSIS_WIDTH     (1U)
#define GMAC_MAC_INTERRUPT_STATUS_TSIS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_TSIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_TSIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_TXSTSIS_MASK   (0x2000U)
#define GMAC_MAC_INTERRUPT_STATUS_TXSTSIS_SHIFT  (13U)
#define GMAC_MAC_INTERRUPT_STATUS_TXSTSIS_WIDTH  (1U)
#define GMAC_MAC_INTERRUPT_STATUS_TXSTSIS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_TXSTSIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_TXSTSIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_RXSTSIS_MASK   (0x4000U)
#define GMAC_MAC_INTERRUPT_STATUS_RXSTSIS_SHIFT  (14U)
#define GMAC_MAC_INTERRUPT_STATUS_RXSTSIS_WIDTH  (1U)
#define GMAC_MAC_INTERRUPT_STATUS_RXSTSIS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_RXSTSIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_RXSTSIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_Reserved_GPIIS_MASK (0x8000U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_GPIIS_SHIFT (15U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_GPIIS_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_GPIIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_Reserved_GPIIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_Reserved_GPIIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_Reserved_16_MASK (0x10000U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_16_SHIFT (16U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_16_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_16(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_Reserved_16_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_Reserved_16_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_FPEIS_MASK     (0x20000U)
#define GMAC_MAC_INTERRUPT_STATUS_FPEIS_SHIFT    (17U)
#define GMAC_MAC_INTERRUPT_STATUS_FPEIS_WIDTH    (1U)
#define GMAC_MAC_INTERRUPT_STATUS_FPEIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_FPEIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_FPEIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_MDIOIS_MASK    (0x40000U)
#define GMAC_MAC_INTERRUPT_STATUS_MDIOIS_SHIFT   (18U)
#define GMAC_MAC_INTERRUPT_STATUS_MDIOIS_WIDTH   (1U)
#define GMAC_MAC_INTERRUPT_STATUS_MDIOIS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_MDIOIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_MDIOIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_MFTIS_MASK     (0x80000U)
#define GMAC_MAC_INTERRUPT_STATUS_MFTIS_SHIFT    (19U)
#define GMAC_MAC_INTERRUPT_STATUS_MFTIS_WIDTH    (1U)
#define GMAC_MAC_INTERRUPT_STATUS_MFTIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_MFTIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_MFTIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_MFRIS_MASK     (0x100000U)
#define GMAC_MAC_INTERRUPT_STATUS_MFRIS_SHIFT    (20U)
#define GMAC_MAC_INTERRUPT_STATUS_MFRIS_WIDTH    (1U)
#define GMAC_MAC_INTERRUPT_STATUS_MFRIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_MFRIS_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_MFRIS_MASK)

#define GMAC_MAC_INTERRUPT_STATUS_Reserved_31_21_MASK (0xFFE00000U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_31_21_SHIFT (21U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_31_21_WIDTH (11U)
#define GMAC_MAC_INTERRUPT_STATUS_Reserved_31_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_STATUS_Reserved_31_21_SHIFT)) & GMAC_MAC_INTERRUPT_STATUS_Reserved_31_21_MASK)
/*! @} */

/*! @name MAC_INTERRUPT_ENABLE -  */
/*! @{ */

#define GMAC_MAC_INTERRUPT_ENABLE_RGSMIIIE_MASK  (0x1U)
#define GMAC_MAC_INTERRUPT_ENABLE_RGSMIIIE_SHIFT (0U)
#define GMAC_MAC_INTERRUPT_ENABLE_RGSMIIIE_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_ENABLE_RGSMIIIE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_RGSMIIIE_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_RGSMIIIE_MASK)

#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_PCSLCHGIE_MASK (0x2U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_PCSLCHGIE_SHIFT (1U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_PCSLCHGIE_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_PCSLCHGIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_Reserved_PCSLCHGIE_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_Reserved_PCSLCHGIE_MASK)

#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_PCSANCIE_MASK (0x4U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_PCSANCIE_SHIFT (2U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_PCSANCIE_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_PCSANCIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_Reserved_PCSANCIE_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_Reserved_PCSANCIE_MASK)

#define GMAC_MAC_INTERRUPT_ENABLE_PHYIE_MASK     (0x8U)
#define GMAC_MAC_INTERRUPT_ENABLE_PHYIE_SHIFT    (3U)
#define GMAC_MAC_INTERRUPT_ENABLE_PHYIE_WIDTH    (1U)
#define GMAC_MAC_INTERRUPT_ENABLE_PHYIE(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_PHYIE_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_PHYIE_MASK)

#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_PMTIE_MASK (0x10U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_PMTIE_SHIFT (4U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_PMTIE_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_PMTIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_Reserved_PMTIE_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_Reserved_PMTIE_MASK)

#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_LPIIE_MASK (0x20U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_LPIIE_SHIFT (5U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_LPIIE_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_LPIIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_Reserved_LPIIE_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_Reserved_LPIIE_MASK)

#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_11_6_MASK (0xFC0U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_11_6_SHIFT (6U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_11_6_WIDTH (6U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_11_6(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_Reserved_11_6_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_Reserved_11_6_MASK)

#define GMAC_MAC_INTERRUPT_ENABLE_TSIE_MASK      (0x1000U)
#define GMAC_MAC_INTERRUPT_ENABLE_TSIE_SHIFT     (12U)
#define GMAC_MAC_INTERRUPT_ENABLE_TSIE_WIDTH     (1U)
#define GMAC_MAC_INTERRUPT_ENABLE_TSIE(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_TSIE_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_TSIE_MASK)

#define GMAC_MAC_INTERRUPT_ENABLE_TXSTSIE_MASK   (0x2000U)
#define GMAC_MAC_INTERRUPT_ENABLE_TXSTSIE_SHIFT  (13U)
#define GMAC_MAC_INTERRUPT_ENABLE_TXSTSIE_WIDTH  (1U)
#define GMAC_MAC_INTERRUPT_ENABLE_TXSTSIE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_TXSTSIE_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_TXSTSIE_MASK)

#define GMAC_MAC_INTERRUPT_ENABLE_RXSTSIE_MASK   (0x4000U)
#define GMAC_MAC_INTERRUPT_ENABLE_RXSTSIE_SHIFT  (14U)
#define GMAC_MAC_INTERRUPT_ENABLE_RXSTSIE_WIDTH  (1U)
#define GMAC_MAC_INTERRUPT_ENABLE_RXSTSIE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_RXSTSIE_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_RXSTSIE_MASK)

#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_15_MASK (0x8000U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_15_SHIFT (15U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_15_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_15(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_Reserved_15_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_Reserved_15_MASK)

#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_16_MASK (0x10000U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_16_SHIFT (16U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_16_WIDTH (1U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_16(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_Reserved_16_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_Reserved_16_MASK)

#define GMAC_MAC_INTERRUPT_ENABLE_FPEIE_MASK     (0x20000U)
#define GMAC_MAC_INTERRUPT_ENABLE_FPEIE_SHIFT    (17U)
#define GMAC_MAC_INTERRUPT_ENABLE_FPEIE_WIDTH    (1U)
#define GMAC_MAC_INTERRUPT_ENABLE_FPEIE(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_FPEIE_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_FPEIE_MASK)

#define GMAC_MAC_INTERRUPT_ENABLE_MDIOIE_MASK    (0x40000U)
#define GMAC_MAC_INTERRUPT_ENABLE_MDIOIE_SHIFT   (18U)
#define GMAC_MAC_INTERRUPT_ENABLE_MDIOIE_WIDTH   (1U)
#define GMAC_MAC_INTERRUPT_ENABLE_MDIOIE(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_MDIOIE_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_MDIOIE_MASK)

#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_31_19_MASK (0xFFF80000U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_31_19_SHIFT (19U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_31_19_WIDTH (13U)
#define GMAC_MAC_INTERRUPT_ENABLE_Reserved_31_19(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INTERRUPT_ENABLE_Reserved_31_19_SHIFT)) & GMAC_MAC_INTERRUPT_ENABLE_Reserved_31_19_MASK)
/*! @} */

/*! @name MAC_RX_TX_STATUS -  */
/*! @{ */

#define GMAC_MAC_RX_TX_STATUS_TJT_MASK           (0x1U)
#define GMAC_MAC_RX_TX_STATUS_TJT_SHIFT          (0U)
#define GMAC_MAC_RX_TX_STATUS_TJT_WIDTH          (1U)
#define GMAC_MAC_RX_TX_STATUS_TJT(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RX_TX_STATUS_TJT_SHIFT)) & GMAC_MAC_RX_TX_STATUS_TJT_MASK)

#define GMAC_MAC_RX_TX_STATUS_NCARR_MASK         (0x2U)
#define GMAC_MAC_RX_TX_STATUS_NCARR_SHIFT        (1U)
#define GMAC_MAC_RX_TX_STATUS_NCARR_WIDTH        (1U)
#define GMAC_MAC_RX_TX_STATUS_NCARR(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RX_TX_STATUS_NCARR_SHIFT)) & GMAC_MAC_RX_TX_STATUS_NCARR_MASK)

#define GMAC_MAC_RX_TX_STATUS_LCARR_MASK         (0x4U)
#define GMAC_MAC_RX_TX_STATUS_LCARR_SHIFT        (2U)
#define GMAC_MAC_RX_TX_STATUS_LCARR_WIDTH        (1U)
#define GMAC_MAC_RX_TX_STATUS_LCARR(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RX_TX_STATUS_LCARR_SHIFT)) & GMAC_MAC_RX_TX_STATUS_LCARR_MASK)

#define GMAC_MAC_RX_TX_STATUS_EXDEF_MASK         (0x8U)
#define GMAC_MAC_RX_TX_STATUS_EXDEF_SHIFT        (3U)
#define GMAC_MAC_RX_TX_STATUS_EXDEF_WIDTH        (1U)
#define GMAC_MAC_RX_TX_STATUS_EXDEF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RX_TX_STATUS_EXDEF_SHIFT)) & GMAC_MAC_RX_TX_STATUS_EXDEF_MASK)

#define GMAC_MAC_RX_TX_STATUS_LCOL_MASK          (0x10U)
#define GMAC_MAC_RX_TX_STATUS_LCOL_SHIFT         (4U)
#define GMAC_MAC_RX_TX_STATUS_LCOL_WIDTH         (1U)
#define GMAC_MAC_RX_TX_STATUS_LCOL(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RX_TX_STATUS_LCOL_SHIFT)) & GMAC_MAC_RX_TX_STATUS_LCOL_MASK)

#define GMAC_MAC_RX_TX_STATUS_EXCOL_MASK         (0x20U)
#define GMAC_MAC_RX_TX_STATUS_EXCOL_SHIFT        (5U)
#define GMAC_MAC_RX_TX_STATUS_EXCOL_WIDTH        (1U)
#define GMAC_MAC_RX_TX_STATUS_EXCOL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RX_TX_STATUS_EXCOL_SHIFT)) & GMAC_MAC_RX_TX_STATUS_EXCOL_MASK)

#define GMAC_MAC_RX_TX_STATUS_Reserved_7_6_MASK  (0xC0U)
#define GMAC_MAC_RX_TX_STATUS_Reserved_7_6_SHIFT (6U)
#define GMAC_MAC_RX_TX_STATUS_Reserved_7_6_WIDTH (2U)
#define GMAC_MAC_RX_TX_STATUS_Reserved_7_6(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RX_TX_STATUS_Reserved_7_6_SHIFT)) & GMAC_MAC_RX_TX_STATUS_Reserved_7_6_MASK)

#define GMAC_MAC_RX_TX_STATUS_RWT_MASK           (0x100U)
#define GMAC_MAC_RX_TX_STATUS_RWT_SHIFT          (8U)
#define GMAC_MAC_RX_TX_STATUS_RWT_WIDTH          (1U)
#define GMAC_MAC_RX_TX_STATUS_RWT(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RX_TX_STATUS_RWT_SHIFT)) & GMAC_MAC_RX_TX_STATUS_RWT_MASK)

#define GMAC_MAC_RX_TX_STATUS_Reserved_31_9_MASK (0xFFFFFE00U)
#define GMAC_MAC_RX_TX_STATUS_Reserved_31_9_SHIFT (9U)
#define GMAC_MAC_RX_TX_STATUS_Reserved_31_9_WIDTH (23U)
#define GMAC_MAC_RX_TX_STATUS_Reserved_31_9(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_RX_TX_STATUS_Reserved_31_9_SHIFT)) & GMAC_MAC_RX_TX_STATUS_Reserved_31_9_MASK)
/*! @} */

/*! @name MAC_PHYIF_CONTROL_STATUS -  */
/*! @{ */

#define GMAC_MAC_PHYIF_CONTROL_STATUS_TC_MASK    (0x1U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_TC_SHIFT   (0U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_TC_WIDTH   (1U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_TC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PHYIF_CONTROL_STATUS_TC_SHIFT)) & GMAC_MAC_PHYIF_CONTROL_STATUS_TC_MASK)

#define GMAC_MAC_PHYIF_CONTROL_STATUS_LUD_MASK   (0x2U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LUD_SHIFT  (1U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LUD_WIDTH  (1U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LUD(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PHYIF_CONTROL_STATUS_LUD_SHIFT)) & GMAC_MAC_PHYIF_CONTROL_STATUS_LUD_MASK)

#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_SFTERR_MASK (0x4U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_SFTERR_SHIFT (2U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_SFTERR_WIDTH (1U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_SFTERR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_SFTERR_SHIFT)) & GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_SFTERR_MASK)

#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_3_MASK (0x8U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_3_SHIFT (3U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_3_WIDTH (1U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_3(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_3_SHIFT)) & GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_3_MASK)

#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_SMIDRXS_MASK (0x10U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_SMIDRXS_SHIFT (4U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_SMIDRXS_WIDTH (1U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_SMIDRXS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_SMIDRXS_SHIFT)) & GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_SMIDRXS_MASK)

#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_15_5_MASK (0xFFE0U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_15_5_SHIFT (5U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_15_5_WIDTH (11U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_15_5(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_15_5_SHIFT)) & GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_15_5_MASK)

#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKMOD_MASK (0x10000U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKMOD_SHIFT (16U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKMOD_WIDTH (1U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKMOD(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PHYIF_CONTROL_STATUS_LNKMOD_SHIFT)) & GMAC_MAC_PHYIF_CONTROL_STATUS_LNKMOD_MASK)

#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSPEED_MASK (0x60000U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSPEED_SHIFT (17U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSPEED_WIDTH (2U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSPEED(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSPEED_SHIFT)) & GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSPEED_MASK)

#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSTS_MASK (0x80000U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSTS_SHIFT (19U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSTS_WIDTH (1U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSTS(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSTS_SHIFT)) & GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSTS_MASK)

#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_JABTO_MASK (0x100000U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_JABTO_SHIFT (20U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_JABTO_WIDTH (1U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_JABTO(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_JABTO_SHIFT)) & GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_JABTO_MASK)

#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_FALSCARDET_MASK (0x200000U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_FALSCARDET_SHIFT (21U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_FALSCARDET_WIDTH (1U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_FALSCARDET(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_FALSCARDET_SHIFT)) & GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_FALSCARDET_MASK)

#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_31_22_MASK (0xFFC00000U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_31_22_SHIFT (22U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_31_22_WIDTH (10U)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_31_22(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_31_22_SHIFT)) & GMAC_MAC_PHYIF_CONTROL_STATUS_Reserved_31_22_MASK)
/*! @} */

/*! @name MAC_VERSION -  */
/*! @{ */

#define GMAC_MAC_VERSION_IPVER_MASK              (0xFFU)
#define GMAC_MAC_VERSION_IPVER_SHIFT             (0U)
#define GMAC_MAC_VERSION_IPVER_WIDTH             (8U)
#define GMAC_MAC_VERSION_IPVER(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VERSION_IPVER_SHIFT)) & GMAC_MAC_VERSION_IPVER_MASK)

#define GMAC_MAC_VERSION_USERVER_MASK            (0xFF00U)
#define GMAC_MAC_VERSION_USERVER_SHIFT           (8U)
#define GMAC_MAC_VERSION_USERVER_WIDTH           (8U)
#define GMAC_MAC_VERSION_USERVER(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VERSION_USERVER_SHIFT)) & GMAC_MAC_VERSION_USERVER_MASK)

#define GMAC_MAC_VERSION_Reserved_31_16_MASK     (0xFFFF0000U)
#define GMAC_MAC_VERSION_Reserved_31_16_SHIFT    (16U)
#define GMAC_MAC_VERSION_Reserved_31_16_WIDTH    (16U)
#define GMAC_MAC_VERSION_Reserved_31_16(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_VERSION_Reserved_31_16_SHIFT)) & GMAC_MAC_VERSION_Reserved_31_16_MASK)
/*! @} */

/*! @name MAC_DEBUG -  */
/*! @{ */

#define GMAC_MAC_DEBUG_RPESTS_MASK               (0x1U)
#define GMAC_MAC_DEBUG_RPESTS_SHIFT              (0U)
#define GMAC_MAC_DEBUG_RPESTS_WIDTH              (1U)
#define GMAC_MAC_DEBUG_RPESTS(x)                 (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DEBUG_RPESTS_SHIFT)) & GMAC_MAC_DEBUG_RPESTS_MASK)

#define GMAC_MAC_DEBUG_RFCFCSTS_MASK             (0x6U)
#define GMAC_MAC_DEBUG_RFCFCSTS_SHIFT            (1U)
#define GMAC_MAC_DEBUG_RFCFCSTS_WIDTH            (2U)
#define GMAC_MAC_DEBUG_RFCFCSTS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DEBUG_RFCFCSTS_SHIFT)) & GMAC_MAC_DEBUG_RFCFCSTS_MASK)

#define GMAC_MAC_DEBUG_Reserved_15_3_MASK        (0xFFF8U)
#define GMAC_MAC_DEBUG_Reserved_15_3_SHIFT       (3U)
#define GMAC_MAC_DEBUG_Reserved_15_3_WIDTH       (13U)
#define GMAC_MAC_DEBUG_Reserved_15_3(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DEBUG_Reserved_15_3_SHIFT)) & GMAC_MAC_DEBUG_Reserved_15_3_MASK)

#define GMAC_MAC_DEBUG_TPESTS_MASK               (0x10000U)
#define GMAC_MAC_DEBUG_TPESTS_SHIFT              (16U)
#define GMAC_MAC_DEBUG_TPESTS_WIDTH              (1U)
#define GMAC_MAC_DEBUG_TPESTS(x)                 (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DEBUG_TPESTS_SHIFT)) & GMAC_MAC_DEBUG_TPESTS_MASK)

#define GMAC_MAC_DEBUG_TFCSTS_MASK               (0x60000U)
#define GMAC_MAC_DEBUG_TFCSTS_SHIFT              (17U)
#define GMAC_MAC_DEBUG_TFCSTS_WIDTH              (2U)
#define GMAC_MAC_DEBUG_TFCSTS(x)                 (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DEBUG_TFCSTS_SHIFT)) & GMAC_MAC_DEBUG_TFCSTS_MASK)

#define GMAC_MAC_DEBUG_Reserved_31_19_MASK       (0xFFF80000U)
#define GMAC_MAC_DEBUG_Reserved_31_19_SHIFT      (19U)
#define GMAC_MAC_DEBUG_Reserved_31_19_WIDTH      (13U)
#define GMAC_MAC_DEBUG_Reserved_31_19(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DEBUG_Reserved_31_19_SHIFT)) & GMAC_MAC_DEBUG_Reserved_31_19_MASK)
/*! @} */

/*! @name MAC_HW_FEATURE0 -  */
/*! @{ */

#define GMAC_MAC_HW_FEATURE0_MIISEL_MASK         (0x1U)
#define GMAC_MAC_HW_FEATURE0_MIISEL_SHIFT        (0U)
#define GMAC_MAC_HW_FEATURE0_MIISEL_WIDTH        (1U)
#define GMAC_MAC_HW_FEATURE0_MIISEL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_MIISEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_MIISEL_MASK)

#define GMAC_MAC_HW_FEATURE0_GMIISEL_MASK        (0x2U)
#define GMAC_MAC_HW_FEATURE0_GMIISEL_SHIFT       (1U)
#define GMAC_MAC_HW_FEATURE0_GMIISEL_WIDTH       (1U)
#define GMAC_MAC_HW_FEATURE0_GMIISEL(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_GMIISEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_GMIISEL_MASK)

#define GMAC_MAC_HW_FEATURE0_HDSEL_MASK          (0x4U)
#define GMAC_MAC_HW_FEATURE0_HDSEL_SHIFT         (2U)
#define GMAC_MAC_HW_FEATURE0_HDSEL_WIDTH         (1U)
#define GMAC_MAC_HW_FEATURE0_HDSEL(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_HDSEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_HDSEL_MASK)

#define GMAC_MAC_HW_FEATURE0_PCSSEL_MASK         (0x8U)
#define GMAC_MAC_HW_FEATURE0_PCSSEL_SHIFT        (3U)
#define GMAC_MAC_HW_FEATURE0_PCSSEL_WIDTH        (1U)
#define GMAC_MAC_HW_FEATURE0_PCSSEL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_PCSSEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_PCSSEL_MASK)

#define GMAC_MAC_HW_FEATURE0_VLHASH_MASK         (0x10U)
#define GMAC_MAC_HW_FEATURE0_VLHASH_SHIFT        (4U)
#define GMAC_MAC_HW_FEATURE0_VLHASH_WIDTH        (1U)
#define GMAC_MAC_HW_FEATURE0_VLHASH(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_VLHASH_SHIFT)) & GMAC_MAC_HW_FEATURE0_VLHASH_MASK)

#define GMAC_MAC_HW_FEATURE0_SMASEL_MASK         (0x20U)
#define GMAC_MAC_HW_FEATURE0_SMASEL_SHIFT        (5U)
#define GMAC_MAC_HW_FEATURE0_SMASEL_WIDTH        (1U)
#define GMAC_MAC_HW_FEATURE0_SMASEL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_SMASEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_SMASEL_MASK)

#define GMAC_MAC_HW_FEATURE0_RWKSEL_MASK         (0x40U)
#define GMAC_MAC_HW_FEATURE0_RWKSEL_SHIFT        (6U)
#define GMAC_MAC_HW_FEATURE0_RWKSEL_WIDTH        (1U)
#define GMAC_MAC_HW_FEATURE0_RWKSEL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_RWKSEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_RWKSEL_MASK)

#define GMAC_MAC_HW_FEATURE0_MGKSEL_MASK         (0x80U)
#define GMAC_MAC_HW_FEATURE0_MGKSEL_SHIFT        (7U)
#define GMAC_MAC_HW_FEATURE0_MGKSEL_WIDTH        (1U)
#define GMAC_MAC_HW_FEATURE0_MGKSEL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_MGKSEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_MGKSEL_MASK)

#define GMAC_MAC_HW_FEATURE0_MMCSEL_MASK         (0x100U)
#define GMAC_MAC_HW_FEATURE0_MMCSEL_SHIFT        (8U)
#define GMAC_MAC_HW_FEATURE0_MMCSEL_WIDTH        (1U)
#define GMAC_MAC_HW_FEATURE0_MMCSEL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_MMCSEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_MMCSEL_MASK)

#define GMAC_MAC_HW_FEATURE0_ARPOFFSEL_MASK      (0x200U)
#define GMAC_MAC_HW_FEATURE0_ARPOFFSEL_SHIFT     (9U)
#define GMAC_MAC_HW_FEATURE0_ARPOFFSEL_WIDTH     (1U)
#define GMAC_MAC_HW_FEATURE0_ARPOFFSEL(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_ARPOFFSEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_ARPOFFSEL_MASK)

#define GMAC_MAC_HW_FEATURE0_Reserved_11_10_MASK (0xC00U)
#define GMAC_MAC_HW_FEATURE0_Reserved_11_10_SHIFT (10U)
#define GMAC_MAC_HW_FEATURE0_Reserved_11_10_WIDTH (2U)
#define GMAC_MAC_HW_FEATURE0_Reserved_11_10(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_Reserved_11_10_SHIFT)) & GMAC_MAC_HW_FEATURE0_Reserved_11_10_MASK)

#define GMAC_MAC_HW_FEATURE0_TSSEL_MASK          (0x1000U)
#define GMAC_MAC_HW_FEATURE0_TSSEL_SHIFT         (12U)
#define GMAC_MAC_HW_FEATURE0_TSSEL_WIDTH         (1U)
#define GMAC_MAC_HW_FEATURE0_TSSEL(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_TSSEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_TSSEL_MASK)

#define GMAC_MAC_HW_FEATURE0_EEESEL_MASK         (0x2000U)
#define GMAC_MAC_HW_FEATURE0_EEESEL_SHIFT        (13U)
#define GMAC_MAC_HW_FEATURE0_EEESEL_WIDTH        (1U)
#define GMAC_MAC_HW_FEATURE0_EEESEL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_EEESEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_EEESEL_MASK)

#define GMAC_MAC_HW_FEATURE0_TXCOESEL_MASK       (0x4000U)
#define GMAC_MAC_HW_FEATURE0_TXCOESEL_SHIFT      (14U)
#define GMAC_MAC_HW_FEATURE0_TXCOESEL_WIDTH      (1U)
#define GMAC_MAC_HW_FEATURE0_TXCOESEL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_TXCOESEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_TXCOESEL_MASK)

#define GMAC_MAC_HW_FEATURE0_Reserved_15_MASK    (0x8000U)
#define GMAC_MAC_HW_FEATURE0_Reserved_15_SHIFT   (15U)
#define GMAC_MAC_HW_FEATURE0_Reserved_15_WIDTH   (1U)
#define GMAC_MAC_HW_FEATURE0_Reserved_15(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_Reserved_15_SHIFT)) & GMAC_MAC_HW_FEATURE0_Reserved_15_MASK)

#define GMAC_MAC_HW_FEATURE0_RXCOESEL_MASK       (0x10000U)
#define GMAC_MAC_HW_FEATURE0_RXCOESEL_SHIFT      (16U)
#define GMAC_MAC_HW_FEATURE0_RXCOESEL_WIDTH      (1U)
#define GMAC_MAC_HW_FEATURE0_RXCOESEL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_RXCOESEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_RXCOESEL_MASK)

#define GMAC_MAC_HW_FEATURE0_Reserved_17_MASK    (0x20000U)
#define GMAC_MAC_HW_FEATURE0_Reserved_17_SHIFT   (17U)
#define GMAC_MAC_HW_FEATURE0_Reserved_17_WIDTH   (1U)
#define GMAC_MAC_HW_FEATURE0_Reserved_17(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_Reserved_17_SHIFT)) & GMAC_MAC_HW_FEATURE0_Reserved_17_MASK)

#define GMAC_MAC_HW_FEATURE0_ADDMACADRSEL_MASK   (0x7C0000U)
#define GMAC_MAC_HW_FEATURE0_ADDMACADRSEL_SHIFT  (18U)
#define GMAC_MAC_HW_FEATURE0_ADDMACADRSEL_WIDTH  (5U)
#define GMAC_MAC_HW_FEATURE0_ADDMACADRSEL(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_ADDMACADRSEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_ADDMACADRSEL_MASK)

#define GMAC_MAC_HW_FEATURE0_MACADR32SEL_MASK    (0x800000U)
#define GMAC_MAC_HW_FEATURE0_MACADR32SEL_SHIFT   (23U)
#define GMAC_MAC_HW_FEATURE0_MACADR32SEL_WIDTH   (1U)
#define GMAC_MAC_HW_FEATURE0_MACADR32SEL(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_MACADR32SEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_MACADR32SEL_MASK)

#define GMAC_MAC_HW_FEATURE0_MACADR64SEL_MASK    (0x1000000U)
#define GMAC_MAC_HW_FEATURE0_MACADR64SEL_SHIFT   (24U)
#define GMAC_MAC_HW_FEATURE0_MACADR64SEL_WIDTH   (1U)
#define GMAC_MAC_HW_FEATURE0_MACADR64SEL(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_MACADR64SEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_MACADR64SEL_MASK)

#define GMAC_MAC_HW_FEATURE0_TSSTSSEL_MASK       (0x6000000U)
#define GMAC_MAC_HW_FEATURE0_TSSTSSEL_SHIFT      (25U)
#define GMAC_MAC_HW_FEATURE0_TSSTSSEL_WIDTH      (2U)
#define GMAC_MAC_HW_FEATURE0_TSSTSSEL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_TSSTSSEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_TSSTSSEL_MASK)

#define GMAC_MAC_HW_FEATURE0_SAVLANINS_MASK      (0x8000000U)
#define GMAC_MAC_HW_FEATURE0_SAVLANINS_SHIFT     (27U)
#define GMAC_MAC_HW_FEATURE0_SAVLANINS_WIDTH     (1U)
#define GMAC_MAC_HW_FEATURE0_SAVLANINS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_SAVLANINS_SHIFT)) & GMAC_MAC_HW_FEATURE0_SAVLANINS_MASK)

#define GMAC_MAC_HW_FEATURE0_ACTPHYSEL_MASK      (0x70000000U)
#define GMAC_MAC_HW_FEATURE0_ACTPHYSEL_SHIFT     (28U)
#define GMAC_MAC_HW_FEATURE0_ACTPHYSEL_WIDTH     (3U)
#define GMAC_MAC_HW_FEATURE0_ACTPHYSEL(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_ACTPHYSEL_SHIFT)) & GMAC_MAC_HW_FEATURE0_ACTPHYSEL_MASK)

#define GMAC_MAC_HW_FEATURE0_Reserved_31_MASK    (0x80000000U)
#define GMAC_MAC_HW_FEATURE0_Reserved_31_SHIFT   (31U)
#define GMAC_MAC_HW_FEATURE0_Reserved_31_WIDTH   (1U)
#define GMAC_MAC_HW_FEATURE0_Reserved_31(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE0_Reserved_31_SHIFT)) & GMAC_MAC_HW_FEATURE0_Reserved_31_MASK)
/*! @} */

/*! @name MAC_HW_FEATURE1 -  */
/*! @{ */

#define GMAC_MAC_HW_FEATURE1_RXFIFOSIZE_MASK     (0x1FU)
#define GMAC_MAC_HW_FEATURE1_RXFIFOSIZE_SHIFT    (0U)
#define GMAC_MAC_HW_FEATURE1_RXFIFOSIZE_WIDTH    (5U)
#define GMAC_MAC_HW_FEATURE1_RXFIFOSIZE(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_RXFIFOSIZE_SHIFT)) & GMAC_MAC_HW_FEATURE1_RXFIFOSIZE_MASK)

#define GMAC_MAC_HW_FEATURE1_SPRAM_MASK          (0x20U)
#define GMAC_MAC_HW_FEATURE1_SPRAM_SHIFT         (5U)
#define GMAC_MAC_HW_FEATURE1_SPRAM_WIDTH         (1U)
#define GMAC_MAC_HW_FEATURE1_SPRAM(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_SPRAM_SHIFT)) & GMAC_MAC_HW_FEATURE1_SPRAM_MASK)

#define GMAC_MAC_HW_FEATURE1_TXFIFOSIZE_MASK     (0x7C0U)
#define GMAC_MAC_HW_FEATURE1_TXFIFOSIZE_SHIFT    (6U)
#define GMAC_MAC_HW_FEATURE1_TXFIFOSIZE_WIDTH    (5U)
#define GMAC_MAC_HW_FEATURE1_TXFIFOSIZE(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_TXFIFOSIZE_SHIFT)) & GMAC_MAC_HW_FEATURE1_TXFIFOSIZE_MASK)

#define GMAC_MAC_HW_FEATURE1_OSTEN_MASK          (0x800U)
#define GMAC_MAC_HW_FEATURE1_OSTEN_SHIFT         (11U)
#define GMAC_MAC_HW_FEATURE1_OSTEN_WIDTH         (1U)
#define GMAC_MAC_HW_FEATURE1_OSTEN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_OSTEN_SHIFT)) & GMAC_MAC_HW_FEATURE1_OSTEN_MASK)

#define GMAC_MAC_HW_FEATURE1_PTOEN_MASK          (0x1000U)
#define GMAC_MAC_HW_FEATURE1_PTOEN_SHIFT         (12U)
#define GMAC_MAC_HW_FEATURE1_PTOEN_WIDTH         (1U)
#define GMAC_MAC_HW_FEATURE1_PTOEN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_PTOEN_SHIFT)) & GMAC_MAC_HW_FEATURE1_PTOEN_MASK)

#define GMAC_MAC_HW_FEATURE1_ADVTHWORD_MASK      (0x2000U)
#define GMAC_MAC_HW_FEATURE1_ADVTHWORD_SHIFT     (13U)
#define GMAC_MAC_HW_FEATURE1_ADVTHWORD_WIDTH     (1U)
#define GMAC_MAC_HW_FEATURE1_ADVTHWORD(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_ADVTHWORD_SHIFT)) & GMAC_MAC_HW_FEATURE1_ADVTHWORD_MASK)

#define GMAC_MAC_HW_FEATURE1_ADDR64_MASK         (0xC000U)
#define GMAC_MAC_HW_FEATURE1_ADDR64_SHIFT        (14U)
#define GMAC_MAC_HW_FEATURE1_ADDR64_WIDTH        (2U)
#define GMAC_MAC_HW_FEATURE1_ADDR64(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_ADDR64_SHIFT)) & GMAC_MAC_HW_FEATURE1_ADDR64_MASK)

#define GMAC_MAC_HW_FEATURE1_DCBEN_MASK          (0x10000U)
#define GMAC_MAC_HW_FEATURE1_DCBEN_SHIFT         (16U)
#define GMAC_MAC_HW_FEATURE1_DCBEN_WIDTH         (1U)
#define GMAC_MAC_HW_FEATURE1_DCBEN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_DCBEN_SHIFT)) & GMAC_MAC_HW_FEATURE1_DCBEN_MASK)

#define GMAC_MAC_HW_FEATURE1_SPHEN_MASK          (0x20000U)
#define GMAC_MAC_HW_FEATURE1_SPHEN_SHIFT         (17U)
#define GMAC_MAC_HW_FEATURE1_SPHEN_WIDTH         (1U)
#define GMAC_MAC_HW_FEATURE1_SPHEN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_SPHEN_SHIFT)) & GMAC_MAC_HW_FEATURE1_SPHEN_MASK)

#define GMAC_MAC_HW_FEATURE1_TSOEN_MASK          (0x40000U)
#define GMAC_MAC_HW_FEATURE1_TSOEN_SHIFT         (18U)
#define GMAC_MAC_HW_FEATURE1_TSOEN_WIDTH         (1U)
#define GMAC_MAC_HW_FEATURE1_TSOEN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_TSOEN_SHIFT)) & GMAC_MAC_HW_FEATURE1_TSOEN_MASK)

#define GMAC_MAC_HW_FEATURE1_DBGMEMA_MASK        (0x80000U)
#define GMAC_MAC_HW_FEATURE1_DBGMEMA_SHIFT       (19U)
#define GMAC_MAC_HW_FEATURE1_DBGMEMA_WIDTH       (1U)
#define GMAC_MAC_HW_FEATURE1_DBGMEMA(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_DBGMEMA_SHIFT)) & GMAC_MAC_HW_FEATURE1_DBGMEMA_MASK)

#define GMAC_MAC_HW_FEATURE1_AVSEL_MASK          (0x100000U)
#define GMAC_MAC_HW_FEATURE1_AVSEL_SHIFT         (20U)
#define GMAC_MAC_HW_FEATURE1_AVSEL_WIDTH         (1U)
#define GMAC_MAC_HW_FEATURE1_AVSEL(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_AVSEL_SHIFT)) & GMAC_MAC_HW_FEATURE1_AVSEL_MASK)

#define GMAC_MAC_HW_FEATURE1_RAVSEL_MASK         (0x200000U)
#define GMAC_MAC_HW_FEATURE1_RAVSEL_SHIFT        (21U)
#define GMAC_MAC_HW_FEATURE1_RAVSEL_WIDTH        (1U)
#define GMAC_MAC_HW_FEATURE1_RAVSEL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_RAVSEL_SHIFT)) & GMAC_MAC_HW_FEATURE1_RAVSEL_MASK)

#define GMAC_MAC_HW_FEATURE1_Reserved_22_MASK    (0x400000U)
#define GMAC_MAC_HW_FEATURE1_Reserved_22_SHIFT   (22U)
#define GMAC_MAC_HW_FEATURE1_Reserved_22_WIDTH   (1U)
#define GMAC_MAC_HW_FEATURE1_Reserved_22(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_Reserved_22_SHIFT)) & GMAC_MAC_HW_FEATURE1_Reserved_22_MASK)

#define GMAC_MAC_HW_FEATURE1_POUOST_MASK         (0x800000U)
#define GMAC_MAC_HW_FEATURE1_POUOST_SHIFT        (23U)
#define GMAC_MAC_HW_FEATURE1_POUOST_WIDTH        (1U)
#define GMAC_MAC_HW_FEATURE1_POUOST(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_POUOST_SHIFT)) & GMAC_MAC_HW_FEATURE1_POUOST_MASK)

#define GMAC_MAC_HW_FEATURE1_HASHTBLSZ_MASK      (0x3000000U)
#define GMAC_MAC_HW_FEATURE1_HASHTBLSZ_SHIFT     (24U)
#define GMAC_MAC_HW_FEATURE1_HASHTBLSZ_WIDTH     (2U)
#define GMAC_MAC_HW_FEATURE1_HASHTBLSZ(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_HASHTBLSZ_SHIFT)) & GMAC_MAC_HW_FEATURE1_HASHTBLSZ_MASK)

#define GMAC_MAC_HW_FEATURE1_Reserved_26_MASK    (0x4000000U)
#define GMAC_MAC_HW_FEATURE1_Reserved_26_SHIFT   (26U)
#define GMAC_MAC_HW_FEATURE1_Reserved_26_WIDTH   (1U)
#define GMAC_MAC_HW_FEATURE1_Reserved_26(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_Reserved_26_SHIFT)) & GMAC_MAC_HW_FEATURE1_Reserved_26_MASK)

#define GMAC_MAC_HW_FEATURE1_L3L4FNUM_MASK       (0x78000000U)
#define GMAC_MAC_HW_FEATURE1_L3L4FNUM_SHIFT      (27U)
#define GMAC_MAC_HW_FEATURE1_L3L4FNUM_WIDTH      (4U)
#define GMAC_MAC_HW_FEATURE1_L3L4FNUM(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_L3L4FNUM_SHIFT)) & GMAC_MAC_HW_FEATURE1_L3L4FNUM_MASK)

#define GMAC_MAC_HW_FEATURE1_Reserved_31_MASK    (0x80000000U)
#define GMAC_MAC_HW_FEATURE1_Reserved_31_SHIFT   (31U)
#define GMAC_MAC_HW_FEATURE1_Reserved_31_WIDTH   (1U)
#define GMAC_MAC_HW_FEATURE1_Reserved_31(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE1_Reserved_31_SHIFT)) & GMAC_MAC_HW_FEATURE1_Reserved_31_MASK)
/*! @} */

/*! @name MAC_HW_FEATURE2 -  */
/*! @{ */

#define GMAC_MAC_HW_FEATURE2_RXQCNT_MASK         (0xFU)
#define GMAC_MAC_HW_FEATURE2_RXQCNT_SHIFT        (0U)
#define GMAC_MAC_HW_FEATURE2_RXQCNT_WIDTH        (4U)
#define GMAC_MAC_HW_FEATURE2_RXQCNT(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE2_RXQCNT_SHIFT)) & GMAC_MAC_HW_FEATURE2_RXQCNT_MASK)

#define GMAC_MAC_HW_FEATURE2_Reserved_5_4_MASK   (0x30U)
#define GMAC_MAC_HW_FEATURE2_Reserved_5_4_SHIFT  (4U)
#define GMAC_MAC_HW_FEATURE2_Reserved_5_4_WIDTH  (2U)
#define GMAC_MAC_HW_FEATURE2_Reserved_5_4(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE2_Reserved_5_4_SHIFT)) & GMAC_MAC_HW_FEATURE2_Reserved_5_4_MASK)

#define GMAC_MAC_HW_FEATURE2_TXQCNT_MASK         (0x3C0U)
#define GMAC_MAC_HW_FEATURE2_TXQCNT_SHIFT        (6U)
#define GMAC_MAC_HW_FEATURE2_TXQCNT_WIDTH        (4U)
#define GMAC_MAC_HW_FEATURE2_TXQCNT(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE2_TXQCNT_SHIFT)) & GMAC_MAC_HW_FEATURE2_TXQCNT_MASK)

#define GMAC_MAC_HW_FEATURE2_Reserved_11_10_MASK (0xC00U)
#define GMAC_MAC_HW_FEATURE2_Reserved_11_10_SHIFT (10U)
#define GMAC_MAC_HW_FEATURE2_Reserved_11_10_WIDTH (2U)
#define GMAC_MAC_HW_FEATURE2_Reserved_11_10(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE2_Reserved_11_10_SHIFT)) & GMAC_MAC_HW_FEATURE2_Reserved_11_10_MASK)

#define GMAC_MAC_HW_FEATURE2_RXCHCNT_MASK        (0xF000U)
#define GMAC_MAC_HW_FEATURE2_RXCHCNT_SHIFT       (12U)
#define GMAC_MAC_HW_FEATURE2_RXCHCNT_WIDTH       (4U)
#define GMAC_MAC_HW_FEATURE2_RXCHCNT(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE2_RXCHCNT_SHIFT)) & GMAC_MAC_HW_FEATURE2_RXCHCNT_MASK)

#define GMAC_MAC_HW_FEATURE2_RDCSZ_MASK          (0x30000U)
#define GMAC_MAC_HW_FEATURE2_RDCSZ_SHIFT         (16U)
#define GMAC_MAC_HW_FEATURE2_RDCSZ_WIDTH         (2U)
#define GMAC_MAC_HW_FEATURE2_RDCSZ(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE2_RDCSZ_SHIFT)) & GMAC_MAC_HW_FEATURE2_RDCSZ_MASK)

#define GMAC_MAC_HW_FEATURE2_TXCHCNT_MASK        (0x3C0000U)
#define GMAC_MAC_HW_FEATURE2_TXCHCNT_SHIFT       (18U)
#define GMAC_MAC_HW_FEATURE2_TXCHCNT_WIDTH       (4U)
#define GMAC_MAC_HW_FEATURE2_TXCHCNT(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE2_TXCHCNT_SHIFT)) & GMAC_MAC_HW_FEATURE2_TXCHCNT_MASK)

#define GMAC_MAC_HW_FEATURE2_TDCSZ_MASK          (0xC00000U)
#define GMAC_MAC_HW_FEATURE2_TDCSZ_SHIFT         (22U)
#define GMAC_MAC_HW_FEATURE2_TDCSZ_WIDTH         (2U)
#define GMAC_MAC_HW_FEATURE2_TDCSZ(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE2_TDCSZ_SHIFT)) & GMAC_MAC_HW_FEATURE2_TDCSZ_MASK)

#define GMAC_MAC_HW_FEATURE2_PPSOUTNUM_MASK      (0x7000000U)
#define GMAC_MAC_HW_FEATURE2_PPSOUTNUM_SHIFT     (24U)
#define GMAC_MAC_HW_FEATURE2_PPSOUTNUM_WIDTH     (3U)
#define GMAC_MAC_HW_FEATURE2_PPSOUTNUM(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE2_PPSOUTNUM_SHIFT)) & GMAC_MAC_HW_FEATURE2_PPSOUTNUM_MASK)

#define GMAC_MAC_HW_FEATURE2_Reserved_27_MASK    (0x8000000U)
#define GMAC_MAC_HW_FEATURE2_Reserved_27_SHIFT   (27U)
#define GMAC_MAC_HW_FEATURE2_Reserved_27_WIDTH   (1U)
#define GMAC_MAC_HW_FEATURE2_Reserved_27(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE2_Reserved_27_SHIFT)) & GMAC_MAC_HW_FEATURE2_Reserved_27_MASK)

#define GMAC_MAC_HW_FEATURE2_AUXSNAPNUM_MASK     (0x70000000U)
#define GMAC_MAC_HW_FEATURE2_AUXSNAPNUM_SHIFT    (28U)
#define GMAC_MAC_HW_FEATURE2_AUXSNAPNUM_WIDTH    (3U)
#define GMAC_MAC_HW_FEATURE2_AUXSNAPNUM(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE2_AUXSNAPNUM_SHIFT)) & GMAC_MAC_HW_FEATURE2_AUXSNAPNUM_MASK)

#define GMAC_MAC_HW_FEATURE2_Reserved_31_MASK    (0x80000000U)
#define GMAC_MAC_HW_FEATURE2_Reserved_31_SHIFT   (31U)
#define GMAC_MAC_HW_FEATURE2_Reserved_31_WIDTH   (1U)
#define GMAC_MAC_HW_FEATURE2_Reserved_31(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE2_Reserved_31_SHIFT)) & GMAC_MAC_HW_FEATURE2_Reserved_31_MASK)
/*! @} */

/*! @name MAC_HW_FEATURE3 -  */
/*! @{ */

#define GMAC_MAC_HW_FEATURE3_NRVF_MASK           (0x7U)
#define GMAC_MAC_HW_FEATURE3_NRVF_SHIFT          (0U)
#define GMAC_MAC_HW_FEATURE3_NRVF_WIDTH          (3U)
#define GMAC_MAC_HW_FEATURE3_NRVF(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_NRVF_SHIFT)) & GMAC_MAC_HW_FEATURE3_NRVF_MASK)

#define GMAC_MAC_HW_FEATURE3_Reserved_3_MASK     (0x8U)
#define GMAC_MAC_HW_FEATURE3_Reserved_3_SHIFT    (3U)
#define GMAC_MAC_HW_FEATURE3_Reserved_3_WIDTH    (1U)
#define GMAC_MAC_HW_FEATURE3_Reserved_3(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_Reserved_3_SHIFT)) & GMAC_MAC_HW_FEATURE3_Reserved_3_MASK)

#define GMAC_MAC_HW_FEATURE3_CBTISEL_MASK        (0x10U)
#define GMAC_MAC_HW_FEATURE3_CBTISEL_SHIFT       (4U)
#define GMAC_MAC_HW_FEATURE3_CBTISEL_WIDTH       (1U)
#define GMAC_MAC_HW_FEATURE3_CBTISEL(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_CBTISEL_SHIFT)) & GMAC_MAC_HW_FEATURE3_CBTISEL_MASK)

#define GMAC_MAC_HW_FEATURE3_DVLAN_MASK          (0x20U)
#define GMAC_MAC_HW_FEATURE3_DVLAN_SHIFT         (5U)
#define GMAC_MAC_HW_FEATURE3_DVLAN_WIDTH         (1U)
#define GMAC_MAC_HW_FEATURE3_DVLAN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_DVLAN_SHIFT)) & GMAC_MAC_HW_FEATURE3_DVLAN_MASK)

#define GMAC_MAC_HW_FEATURE3_Reserved_7_6_MASK   (0x1C0U)
#define GMAC_MAC_HW_FEATURE3_Reserved_7_6_SHIFT  (6U)
#define GMAC_MAC_HW_FEATURE3_Reserved_7_6_WIDTH  (3U)
#define GMAC_MAC_HW_FEATURE3_Reserved_7_6(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_Reserved_7_6_SHIFT)) & GMAC_MAC_HW_FEATURE3_Reserved_7_6_MASK)

#define GMAC_MAC_HW_FEATURE3_PDUPSEL_MASK        (0x200U)
#define GMAC_MAC_HW_FEATURE3_PDUPSEL_SHIFT       (9U)
#define GMAC_MAC_HW_FEATURE3_PDUPSEL_WIDTH       (1U)
#define GMAC_MAC_HW_FEATURE3_PDUPSEL(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_PDUPSEL_SHIFT)) & GMAC_MAC_HW_FEATURE3_PDUPSEL_MASK)

#define GMAC_MAC_HW_FEATURE3_FRPSEL_MASK         (0x400U)
#define GMAC_MAC_HW_FEATURE3_FRPSEL_SHIFT        (10U)
#define GMAC_MAC_HW_FEATURE3_FRPSEL_WIDTH        (1U)
#define GMAC_MAC_HW_FEATURE3_FRPSEL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_FRPSEL_SHIFT)) & GMAC_MAC_HW_FEATURE3_FRPSEL_MASK)

#define GMAC_MAC_HW_FEATURE3_FRPBS_MASK          (0x1800U)
#define GMAC_MAC_HW_FEATURE3_FRPBS_SHIFT         (11U)
#define GMAC_MAC_HW_FEATURE3_FRPBS_WIDTH         (2U)
#define GMAC_MAC_HW_FEATURE3_FRPBS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_FRPBS_SHIFT)) & GMAC_MAC_HW_FEATURE3_FRPBS_MASK)

#define GMAC_MAC_HW_FEATURE3_FRPES_MASK          (0x6000U)
#define GMAC_MAC_HW_FEATURE3_FRPES_SHIFT         (13U)
#define GMAC_MAC_HW_FEATURE3_FRPES_WIDTH         (2U)
#define GMAC_MAC_HW_FEATURE3_FRPES(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_FRPES_SHIFT)) & GMAC_MAC_HW_FEATURE3_FRPES_MASK)

#define GMAC_MAC_HW_FEATURE3_Reserved_15_MASK    (0x8000U)
#define GMAC_MAC_HW_FEATURE3_Reserved_15_SHIFT   (15U)
#define GMAC_MAC_HW_FEATURE3_Reserved_15_WIDTH   (1U)
#define GMAC_MAC_HW_FEATURE3_Reserved_15(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_Reserved_15_SHIFT)) & GMAC_MAC_HW_FEATURE3_Reserved_15_MASK)

#define GMAC_MAC_HW_FEATURE3_ESTSEL_MASK         (0x10000U)
#define GMAC_MAC_HW_FEATURE3_ESTSEL_SHIFT        (16U)
#define GMAC_MAC_HW_FEATURE3_ESTSEL_WIDTH        (1U)
#define GMAC_MAC_HW_FEATURE3_ESTSEL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_ESTSEL_SHIFT)) & GMAC_MAC_HW_FEATURE3_ESTSEL_MASK)

#define GMAC_MAC_HW_FEATURE3_ESTDEP_MASK         (0xE0000U)
#define GMAC_MAC_HW_FEATURE3_ESTDEP_SHIFT        (17U)
#define GMAC_MAC_HW_FEATURE3_ESTDEP_WIDTH        (3U)
#define GMAC_MAC_HW_FEATURE3_ESTDEP(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_ESTDEP_SHIFT)) & GMAC_MAC_HW_FEATURE3_ESTDEP_MASK)

#define GMAC_MAC_HW_FEATURE3_ESTWID_MASK         (0x300000U)
#define GMAC_MAC_HW_FEATURE3_ESTWID_SHIFT        (20U)
#define GMAC_MAC_HW_FEATURE3_ESTWID_WIDTH        (2U)
#define GMAC_MAC_HW_FEATURE3_ESTWID(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_ESTWID_SHIFT)) & GMAC_MAC_HW_FEATURE3_ESTWID_MASK)

#define GMAC_MAC_HW_FEATURE3_Reserved_25_22_MASK (0x3C00000U)
#define GMAC_MAC_HW_FEATURE3_Reserved_25_22_SHIFT (22U)
#define GMAC_MAC_HW_FEATURE3_Reserved_25_22_WIDTH (4U)
#define GMAC_MAC_HW_FEATURE3_Reserved_25_22(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_Reserved_25_22_SHIFT)) & GMAC_MAC_HW_FEATURE3_Reserved_25_22_MASK)

#define GMAC_MAC_HW_FEATURE3_FPESEL_MASK         (0x4000000U)
#define GMAC_MAC_HW_FEATURE3_FPESEL_SHIFT        (26U)
#define GMAC_MAC_HW_FEATURE3_FPESEL_WIDTH        (1U)
#define GMAC_MAC_HW_FEATURE3_FPESEL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_FPESEL_SHIFT)) & GMAC_MAC_HW_FEATURE3_FPESEL_MASK)

#define GMAC_MAC_HW_FEATURE3_TBSSEL_MASK         (0x8000000U)
#define GMAC_MAC_HW_FEATURE3_TBSSEL_SHIFT        (27U)
#define GMAC_MAC_HW_FEATURE3_TBSSEL_WIDTH        (1U)
#define GMAC_MAC_HW_FEATURE3_TBSSEL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_TBSSEL_SHIFT)) & GMAC_MAC_HW_FEATURE3_TBSSEL_MASK)

#define GMAC_MAC_HW_FEATURE3_ASP_MASK            (0x30000000U)
#define GMAC_MAC_HW_FEATURE3_ASP_SHIFT           (28U)
#define GMAC_MAC_HW_FEATURE3_ASP_WIDTH           (2U)
#define GMAC_MAC_HW_FEATURE3_ASP(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_ASP_SHIFT)) & GMAC_MAC_HW_FEATURE3_ASP_MASK)

#define GMAC_MAC_HW_FEATURE3_Reserved_31_30_MASK (0xC0000000U)
#define GMAC_MAC_HW_FEATURE3_Reserved_31_30_SHIFT (30U)
#define GMAC_MAC_HW_FEATURE3_Reserved_31_30_WIDTH (2U)
#define GMAC_MAC_HW_FEATURE3_Reserved_31_30(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_HW_FEATURE3_Reserved_31_30_SHIFT)) & GMAC_MAC_HW_FEATURE3_Reserved_31_30_MASK)
/*! @} */

/*! @name MAC_DPP_FSM_INTERRUPT_STATUS -  */
/*! @{ */

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_ATPES_MASK (0x1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_ATPES_SHIFT (0U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_ATPES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_ATPES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_ATPES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_ATPES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_TPES_MASK (0x2U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_TPES_SHIFT (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_TPES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_TPES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_TPES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_TPES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_MASK (0x4U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_SHIFT (2U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RDPES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_MASK (0x8U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_SHIFT (3U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MPES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MPES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_MASK (0x10U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_SHIFT (4U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTSPES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_MASK (0x20U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_SHIFT (5U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ARPES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_CWPES_MASK (0x40U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_CWPES_SHIFT (6U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_CWPES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_CWPES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_CWPES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_CWPES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_ASRPES_MASK (0x80U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_ASRPES_SHIFT (7U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_ASRPES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_ASRPES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_ASRPES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_ASRPES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_MASK (0x100U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_SHIFT (8U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_TTES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_TTES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_MASK (0x200U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_SHIFT (9U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RTES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_RTES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_CTES_MASK (0x400U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_CTES_SHIFT (10U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_CTES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_CTES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_CTES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_CTES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_MASK (0x800U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_SHIFT (11U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ATES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_ATES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_MASK (0x1000U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_SHIFT (12U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_PTES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_PTES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_T125ES_MASK (0x2000U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_T125ES_SHIFT (13U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_T125ES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_T125ES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_T125ES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_T125ES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_R125ES_MASK (0x4000U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_R125ES_SHIFT (14U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_R125ES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_R125ES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_R125ES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_R125ES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_RVCTES_MASK (0x8000U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_RVCTES_SHIFT (15U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_RVCTES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_RVCTES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_RVCTES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_RVCTES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES_MASK (0x10000U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES_SHIFT (16U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MSTTES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_SLVTES_MASK (0x20000U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_SLVTES_SHIFT (17U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_SLVTES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_SLVTES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_SLVTES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_SLVTES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_23_18_MASK (0xFC0000U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_23_18_SHIFT (18U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_23_18_WIDTH (6U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_23_18(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_23_18_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_23_18_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_MASK (0x1000000U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_SHIFT (24U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_FSMPES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTBUPES_MASK (0x2000000U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTBUPES_SHIFT (25U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTBUPES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTBUPES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTBUPES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTBUPES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTFCPES_MASK (0x4000000U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTFCPES_SHIFT (26U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTFCPES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTFCPES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTFCPES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MTFCPES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MRWCPES_MASK (0x8000000U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MRWCPES_SHIFT (27U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MRWCPES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MRWCPES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MRWCPES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_MRWCPES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_DCPES_MASK (0x10000000U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_DCPES_SHIFT (28U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_DCPES_WIDTH (1U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_DCPES(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_DCPES_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_DCPES_MASK)

#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_31_29_SHIFT (29U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_31_29_WIDTH (3U)
#define GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_31_29(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_31_29_SHIFT)) & GMAC_MAC_DPP_FSM_INTERRUPT_STATUS_Reserved_31_29_MASK)
/*! @} */

/*! @name MAC_FSM_CONTROL -  */
/*! @{ */

#define GMAC_MAC_FSM_CONTROL_TMOUTEN_MASK        (0x1U)
#define GMAC_MAC_FSM_CONTROL_TMOUTEN_SHIFT       (0U)
#define GMAC_MAC_FSM_CONTROL_TMOUTEN_WIDTH       (1U)
#define GMAC_MAC_FSM_CONTROL_TMOUTEN(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_TMOUTEN_SHIFT)) & GMAC_MAC_FSM_CONTROL_TMOUTEN_MASK)

#define GMAC_MAC_FSM_CONTROL_PRTYEN_MASK         (0x2U)
#define GMAC_MAC_FSM_CONTROL_PRTYEN_SHIFT        (1U)
#define GMAC_MAC_FSM_CONTROL_PRTYEN_WIDTH        (1U)
#define GMAC_MAC_FSM_CONTROL_PRTYEN(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_PRTYEN_SHIFT)) & GMAC_MAC_FSM_CONTROL_PRTYEN_MASK)

#define GMAC_MAC_FSM_CONTROL_Reserved_7_2_MASK   (0xFCU)
#define GMAC_MAC_FSM_CONTROL_Reserved_7_2_SHIFT  (2U)
#define GMAC_MAC_FSM_CONTROL_Reserved_7_2_WIDTH  (6U)
#define GMAC_MAC_FSM_CONTROL_Reserved_7_2(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_Reserved_7_2_SHIFT)) & GMAC_MAC_FSM_CONTROL_Reserved_7_2_MASK)

#define GMAC_MAC_FSM_CONTROL_TTEIN_MASK          (0x100U)
#define GMAC_MAC_FSM_CONTROL_TTEIN_SHIFT         (8U)
#define GMAC_MAC_FSM_CONTROL_TTEIN_WIDTH         (1U)
#define GMAC_MAC_FSM_CONTROL_TTEIN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_TTEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_TTEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_RTEIN_MASK          (0x200U)
#define GMAC_MAC_FSM_CONTROL_RTEIN_SHIFT         (9U)
#define GMAC_MAC_FSM_CONTROL_RTEIN_WIDTH         (1U)
#define GMAC_MAC_FSM_CONTROL_RTEIN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_RTEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_RTEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_Reserved_CTEIN_MASK (0x400U)
#define GMAC_MAC_FSM_CONTROL_Reserved_CTEIN_SHIFT (10U)
#define GMAC_MAC_FSM_CONTROL_Reserved_CTEIN_WIDTH (1U)
#define GMAC_MAC_FSM_CONTROL_Reserved_CTEIN(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_Reserved_CTEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_Reserved_CTEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_ATEIN_MASK          (0x800U)
#define GMAC_MAC_FSM_CONTROL_ATEIN_SHIFT         (11U)
#define GMAC_MAC_FSM_CONTROL_ATEIN_WIDTH         (1U)
#define GMAC_MAC_FSM_CONTROL_ATEIN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_ATEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_ATEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_PTEIN_MASK          (0x1000U)
#define GMAC_MAC_FSM_CONTROL_PTEIN_SHIFT         (12U)
#define GMAC_MAC_FSM_CONTROL_PTEIN_WIDTH         (1U)
#define GMAC_MAC_FSM_CONTROL_PTEIN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_PTEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_PTEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_Reserved_T125TEIN_MASK (0x2000U)
#define GMAC_MAC_FSM_CONTROL_Reserved_T125TEIN_SHIFT (13U)
#define GMAC_MAC_FSM_CONTROL_Reserved_T125TEIN_WIDTH (1U)
#define GMAC_MAC_FSM_CONTROL_Reserved_T125TEIN(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_Reserved_T125TEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_Reserved_T125TEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_Reserved_R125TEIN_MASK (0x4000U)
#define GMAC_MAC_FSM_CONTROL_Reserved_R125TEIN_SHIFT (14U)
#define GMAC_MAC_FSM_CONTROL_Reserved_R125TEIN_WIDTH (1U)
#define GMAC_MAC_FSM_CONTROL_Reserved_R125TEIN(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_Reserved_R125TEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_Reserved_R125TEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_Reserved_RVCTEIN_MASK (0x8000U)
#define GMAC_MAC_FSM_CONTROL_Reserved_RVCTEIN_SHIFT (15U)
#define GMAC_MAC_FSM_CONTROL_Reserved_RVCTEIN_WIDTH (1U)
#define GMAC_MAC_FSM_CONTROL_Reserved_RVCTEIN(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_Reserved_RVCTEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_Reserved_RVCTEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_TPEIN_MASK          (0x10000U)
#define GMAC_MAC_FSM_CONTROL_TPEIN_SHIFT         (16U)
#define GMAC_MAC_FSM_CONTROL_TPEIN_WIDTH         (1U)
#define GMAC_MAC_FSM_CONTROL_TPEIN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_TPEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_TPEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_RPEIN_MASK          (0x20000U)
#define GMAC_MAC_FSM_CONTROL_RPEIN_SHIFT         (17U)
#define GMAC_MAC_FSM_CONTROL_RPEIN_WIDTH         (1U)
#define GMAC_MAC_FSM_CONTROL_RPEIN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_RPEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_RPEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_Reserved_CPEIN_MASK (0x40000U)
#define GMAC_MAC_FSM_CONTROL_Reserved_CPEIN_SHIFT (18U)
#define GMAC_MAC_FSM_CONTROL_Reserved_CPEIN_WIDTH (1U)
#define GMAC_MAC_FSM_CONTROL_Reserved_CPEIN(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_Reserved_CPEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_Reserved_CPEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_APEIN_MASK          (0x80000U)
#define GMAC_MAC_FSM_CONTROL_APEIN_SHIFT         (19U)
#define GMAC_MAC_FSM_CONTROL_APEIN_WIDTH         (1U)
#define GMAC_MAC_FSM_CONTROL_APEIN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_APEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_APEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_PPEIN_MASK          (0x100000U)
#define GMAC_MAC_FSM_CONTROL_PPEIN_SHIFT         (20U)
#define GMAC_MAC_FSM_CONTROL_PPEIN_WIDTH         (1U)
#define GMAC_MAC_FSM_CONTROL_PPEIN(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_PPEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_PPEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_Reserved_T125PEIN_MASK (0x200000U)
#define GMAC_MAC_FSM_CONTROL_Reserved_T125PEIN_SHIFT (21U)
#define GMAC_MAC_FSM_CONTROL_Reserved_T125PEIN_WIDTH (1U)
#define GMAC_MAC_FSM_CONTROL_Reserved_T125PEIN(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_Reserved_T125PEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_Reserved_T125PEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_Reserved_R125PEIN_MASK (0x400000U)
#define GMAC_MAC_FSM_CONTROL_Reserved_R125PEIN_SHIFT (22U)
#define GMAC_MAC_FSM_CONTROL_Reserved_R125PEIN_WIDTH (1U)
#define GMAC_MAC_FSM_CONTROL_Reserved_R125PEIN(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_Reserved_R125PEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_Reserved_R125PEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_Reserved_RVCPEIN_MASK (0x800000U)
#define GMAC_MAC_FSM_CONTROL_Reserved_RVCPEIN_SHIFT (23U)
#define GMAC_MAC_FSM_CONTROL_Reserved_RVCPEIN_WIDTH (1U)
#define GMAC_MAC_FSM_CONTROL_Reserved_RVCPEIN(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_Reserved_RVCPEIN_SHIFT)) & GMAC_MAC_FSM_CONTROL_Reserved_RVCPEIN_MASK)

#define GMAC_MAC_FSM_CONTROL_TLGRNML_MASK        (0x1000000U)
#define GMAC_MAC_FSM_CONTROL_TLGRNML_SHIFT       (24U)
#define GMAC_MAC_FSM_CONTROL_TLGRNML_WIDTH       (1U)
#define GMAC_MAC_FSM_CONTROL_TLGRNML(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_TLGRNML_SHIFT)) & GMAC_MAC_FSM_CONTROL_TLGRNML_MASK)

#define GMAC_MAC_FSM_CONTROL_RLGRNML_MASK        (0x2000000U)
#define GMAC_MAC_FSM_CONTROL_RLGRNML_SHIFT       (25U)
#define GMAC_MAC_FSM_CONTROL_RLGRNML_WIDTH       (1U)
#define GMAC_MAC_FSM_CONTROL_RLGRNML(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_RLGRNML_SHIFT)) & GMAC_MAC_FSM_CONTROL_RLGRNML_MASK)

#define GMAC_MAC_FSM_CONTROL_Reserved_CLGRNML_MASK (0x4000000U)
#define GMAC_MAC_FSM_CONTROL_Reserved_CLGRNML_SHIFT (26U)
#define GMAC_MAC_FSM_CONTROL_Reserved_CLGRNML_WIDTH (1U)
#define GMAC_MAC_FSM_CONTROL_Reserved_CLGRNML(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_Reserved_CLGRNML_SHIFT)) & GMAC_MAC_FSM_CONTROL_Reserved_CLGRNML_MASK)

#define GMAC_MAC_FSM_CONTROL_ALGRNML_MASK        (0x8000000U)
#define GMAC_MAC_FSM_CONTROL_ALGRNML_SHIFT       (27U)
#define GMAC_MAC_FSM_CONTROL_ALGRNML_WIDTH       (1U)
#define GMAC_MAC_FSM_CONTROL_ALGRNML(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_ALGRNML_SHIFT)) & GMAC_MAC_FSM_CONTROL_ALGRNML_MASK)

#define GMAC_MAC_FSM_CONTROL_PLGRNML_MASK        (0x10000000U)
#define GMAC_MAC_FSM_CONTROL_PLGRNML_SHIFT       (28U)
#define GMAC_MAC_FSM_CONTROL_PLGRNML_WIDTH       (1U)
#define GMAC_MAC_FSM_CONTROL_PLGRNML(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_PLGRNML_SHIFT)) & GMAC_MAC_FSM_CONTROL_PLGRNML_MASK)

#define GMAC_MAC_FSM_CONTROL_Reserved_T125LGRNML_MASK (0x20000000U)
#define GMAC_MAC_FSM_CONTROL_Reserved_T125LGRNML_SHIFT (29U)
#define GMAC_MAC_FSM_CONTROL_Reserved_T125LGRNML_WIDTH (1U)
#define GMAC_MAC_FSM_CONTROL_Reserved_T125LGRNML(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_Reserved_T125LGRNML_SHIFT)) & GMAC_MAC_FSM_CONTROL_Reserved_T125LGRNML_MASK)

#define GMAC_MAC_FSM_CONTROL_Reserved_R125LGRNML_MASK (0x40000000U)
#define GMAC_MAC_FSM_CONTROL_Reserved_R125LGRNML_SHIFT (30U)
#define GMAC_MAC_FSM_CONTROL_Reserved_R125LGRNML_WIDTH (1U)
#define GMAC_MAC_FSM_CONTROL_Reserved_R125LGRNML(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_Reserved_R125LGRNML_SHIFT)) & GMAC_MAC_FSM_CONTROL_Reserved_R125LGRNML_MASK)

#define GMAC_MAC_FSM_CONTROL_Reserved_RVCLGRNML_MASK (0x80000000U)
#define GMAC_MAC_FSM_CONTROL_Reserved_RVCLGRNML_SHIFT (31U)
#define GMAC_MAC_FSM_CONTROL_Reserved_RVCLGRNML_WIDTH (1U)
#define GMAC_MAC_FSM_CONTROL_Reserved_RVCLGRNML(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_CONTROL_Reserved_RVCLGRNML_SHIFT)) & GMAC_MAC_FSM_CONTROL_Reserved_RVCLGRNML_MASK)
/*! @} */

/*! @name MAC_FSM_ACT_TIMER -  */
/*! @{ */

#define GMAC_MAC_FSM_ACT_TIMER_TMR_MASK          (0x3FFU)
#define GMAC_MAC_FSM_ACT_TIMER_TMR_SHIFT         (0U)
#define GMAC_MAC_FSM_ACT_TIMER_TMR_WIDTH         (10U)
#define GMAC_MAC_FSM_ACT_TIMER_TMR(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_ACT_TIMER_TMR_SHIFT)) & GMAC_MAC_FSM_ACT_TIMER_TMR_MASK)

#define GMAC_MAC_FSM_ACT_TIMER_Reserved_15_10_MASK (0xFC00U)
#define GMAC_MAC_FSM_ACT_TIMER_Reserved_15_10_SHIFT (10U)
#define GMAC_MAC_FSM_ACT_TIMER_Reserved_15_10_WIDTH (6U)
#define GMAC_MAC_FSM_ACT_TIMER_Reserved_15_10(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_ACT_TIMER_Reserved_15_10_SHIFT)) & GMAC_MAC_FSM_ACT_TIMER_Reserved_15_10_MASK)

#define GMAC_MAC_FSM_ACT_TIMER_NTMRMD_MASK       (0xF0000U)
#define GMAC_MAC_FSM_ACT_TIMER_NTMRMD_SHIFT      (16U)
#define GMAC_MAC_FSM_ACT_TIMER_NTMRMD_WIDTH      (4U)
#define GMAC_MAC_FSM_ACT_TIMER_NTMRMD(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_ACT_TIMER_NTMRMD_SHIFT)) & GMAC_MAC_FSM_ACT_TIMER_NTMRMD_MASK)

#define GMAC_MAC_FSM_ACT_TIMER_LTMRMD_MASK       (0xF00000U)
#define GMAC_MAC_FSM_ACT_TIMER_LTMRMD_SHIFT      (20U)
#define GMAC_MAC_FSM_ACT_TIMER_LTMRMD_WIDTH      (4U)
#define GMAC_MAC_FSM_ACT_TIMER_LTMRMD(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_ACT_TIMER_LTMRMD_SHIFT)) & GMAC_MAC_FSM_ACT_TIMER_LTMRMD_MASK)

#define GMAC_MAC_FSM_ACT_TIMER_Reserved_31_24_MASK (0xFF000000U)
#define GMAC_MAC_FSM_ACT_TIMER_Reserved_31_24_SHIFT (24U)
#define GMAC_MAC_FSM_ACT_TIMER_Reserved_31_24_WIDTH (8U)
#define GMAC_MAC_FSM_ACT_TIMER_Reserved_31_24(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FSM_ACT_TIMER_Reserved_31_24_SHIFT)) & GMAC_MAC_FSM_ACT_TIMER_Reserved_31_24_MASK)
/*! @} */

/*! @name SCS_REG1 -  */
/*! @{ */

#define GMAC_SCS_REG1_MAC_SCS1_MASK              (0xFFFFFFFFU)
#define GMAC_SCS_REG1_MAC_SCS1_SHIFT             (0U)
#define GMAC_SCS_REG1_MAC_SCS1_WIDTH             (32U)
#define GMAC_SCS_REG1_MAC_SCS1(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_SCS_REG1_MAC_SCS1_SHIFT)) & GMAC_SCS_REG1_MAC_SCS1_MASK)
/*! @} */

/*! @name MAC_MDIO_ADDRESS -  */
/*! @{ */

#define GMAC_MAC_MDIO_ADDRESS_GB_MASK            (0x1U)
#define GMAC_MAC_MDIO_ADDRESS_GB_SHIFT           (0U)
#define GMAC_MAC_MDIO_ADDRESS_GB_WIDTH           (1U)
#define GMAC_MAC_MDIO_ADDRESS_GB(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_ADDRESS_GB_SHIFT)) & GMAC_MAC_MDIO_ADDRESS_GB_MASK)

#define GMAC_MAC_MDIO_ADDRESS_C45E_MASK          (0x2U)
#define GMAC_MAC_MDIO_ADDRESS_C45E_SHIFT         (1U)
#define GMAC_MAC_MDIO_ADDRESS_C45E_WIDTH         (1U)
#define GMAC_MAC_MDIO_ADDRESS_C45E(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_ADDRESS_C45E_SHIFT)) & GMAC_MAC_MDIO_ADDRESS_C45E_MASK)

#define GMAC_MAC_MDIO_ADDRESS_GOC_0_MASK         (0x4U)
#define GMAC_MAC_MDIO_ADDRESS_GOC_0_SHIFT        (2U)
#define GMAC_MAC_MDIO_ADDRESS_GOC_0_WIDTH        (1U)
#define GMAC_MAC_MDIO_ADDRESS_GOC_0(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_ADDRESS_GOC_0_SHIFT)) & GMAC_MAC_MDIO_ADDRESS_GOC_0_MASK)

#define GMAC_MAC_MDIO_ADDRESS_GOC_1_MASK         (0x8U)
#define GMAC_MAC_MDIO_ADDRESS_GOC_1_SHIFT        (3U)
#define GMAC_MAC_MDIO_ADDRESS_GOC_1_WIDTH        (1U)
#define GMAC_MAC_MDIO_ADDRESS_GOC_1(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_ADDRESS_GOC_1_SHIFT)) & GMAC_MAC_MDIO_ADDRESS_GOC_1_MASK)

#define GMAC_MAC_MDIO_ADDRESS_SKAP_MASK          (0x10U)
#define GMAC_MAC_MDIO_ADDRESS_SKAP_SHIFT         (4U)
#define GMAC_MAC_MDIO_ADDRESS_SKAP_WIDTH         (1U)
#define GMAC_MAC_MDIO_ADDRESS_SKAP(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_ADDRESS_SKAP_SHIFT)) & GMAC_MAC_MDIO_ADDRESS_SKAP_MASK)

#define GMAC_MAC_MDIO_ADDRESS_Reserved_7_5_MASK  (0xE0U)
#define GMAC_MAC_MDIO_ADDRESS_Reserved_7_5_SHIFT (5U)
#define GMAC_MAC_MDIO_ADDRESS_Reserved_7_5_WIDTH (3U)
#define GMAC_MAC_MDIO_ADDRESS_Reserved_7_5(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_ADDRESS_Reserved_7_5_SHIFT)) & GMAC_MAC_MDIO_ADDRESS_Reserved_7_5_MASK)

#define GMAC_MAC_MDIO_ADDRESS_CR_MASK            (0xF00U)
#define GMAC_MAC_MDIO_ADDRESS_CR_SHIFT           (8U)
#define GMAC_MAC_MDIO_ADDRESS_CR_WIDTH           (4U)
#define GMAC_MAC_MDIO_ADDRESS_CR(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_ADDRESS_CR_SHIFT)) & GMAC_MAC_MDIO_ADDRESS_CR_MASK)

#define GMAC_MAC_MDIO_ADDRESS_NTC_MASK           (0x7000U)
#define GMAC_MAC_MDIO_ADDRESS_NTC_SHIFT          (12U)
#define GMAC_MAC_MDIO_ADDRESS_NTC_WIDTH          (3U)
#define GMAC_MAC_MDIO_ADDRESS_NTC(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_ADDRESS_NTC_SHIFT)) & GMAC_MAC_MDIO_ADDRESS_NTC_MASK)

#define GMAC_MAC_MDIO_ADDRESS_Reserved_15_MASK   (0x8000U)
#define GMAC_MAC_MDIO_ADDRESS_Reserved_15_SHIFT  (15U)
#define GMAC_MAC_MDIO_ADDRESS_Reserved_15_WIDTH  (1U)
#define GMAC_MAC_MDIO_ADDRESS_Reserved_15(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_ADDRESS_Reserved_15_SHIFT)) & GMAC_MAC_MDIO_ADDRESS_Reserved_15_MASK)

#define GMAC_MAC_MDIO_ADDRESS_RDA_MASK           (0x1F0000U)
#define GMAC_MAC_MDIO_ADDRESS_RDA_SHIFT          (16U)
#define GMAC_MAC_MDIO_ADDRESS_RDA_WIDTH          (5U)
#define GMAC_MAC_MDIO_ADDRESS_RDA(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_ADDRESS_RDA_SHIFT)) & GMAC_MAC_MDIO_ADDRESS_RDA_MASK)

#define GMAC_MAC_MDIO_ADDRESS_PA_MASK            (0x3E00000U)
#define GMAC_MAC_MDIO_ADDRESS_PA_SHIFT           (21U)
#define GMAC_MAC_MDIO_ADDRESS_PA_WIDTH           (5U)
#define GMAC_MAC_MDIO_ADDRESS_PA(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_ADDRESS_PA_SHIFT)) & GMAC_MAC_MDIO_ADDRESS_PA_MASK)

#define GMAC_MAC_MDIO_ADDRESS_BTB_MASK           (0x4000000U)
#define GMAC_MAC_MDIO_ADDRESS_BTB_SHIFT          (26U)
#define GMAC_MAC_MDIO_ADDRESS_BTB_WIDTH          (1U)
#define GMAC_MAC_MDIO_ADDRESS_BTB(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_ADDRESS_BTB_SHIFT)) & GMAC_MAC_MDIO_ADDRESS_BTB_MASK)

#define GMAC_MAC_MDIO_ADDRESS_PSE_MASK           (0x8000000U)
#define GMAC_MAC_MDIO_ADDRESS_PSE_SHIFT          (27U)
#define GMAC_MAC_MDIO_ADDRESS_PSE_WIDTH          (1U)
#define GMAC_MAC_MDIO_ADDRESS_PSE(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_ADDRESS_PSE_SHIFT)) & GMAC_MAC_MDIO_ADDRESS_PSE_MASK)

#define GMAC_MAC_MDIO_ADDRESS_Reserved_31_28_MASK (0xF0000000U)
#define GMAC_MAC_MDIO_ADDRESS_Reserved_31_28_SHIFT (28U)
#define GMAC_MAC_MDIO_ADDRESS_Reserved_31_28_WIDTH (4U)
#define GMAC_MAC_MDIO_ADDRESS_Reserved_31_28(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_ADDRESS_Reserved_31_28_SHIFT)) & GMAC_MAC_MDIO_ADDRESS_Reserved_31_28_MASK)
/*! @} */

/*! @name MAC_MDIO_DATA -  */
/*! @{ */

#define GMAC_MAC_MDIO_DATA_GD_MASK               (0xFFFFU)
#define GMAC_MAC_MDIO_DATA_GD_SHIFT              (0U)
#define GMAC_MAC_MDIO_DATA_GD_WIDTH              (16U)
#define GMAC_MAC_MDIO_DATA_GD(x)                 (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_DATA_GD_SHIFT)) & GMAC_MAC_MDIO_DATA_GD_MASK)

#define GMAC_MAC_MDIO_DATA_RA_MASK               (0xFFFF0000U)
#define GMAC_MAC_MDIO_DATA_RA_SHIFT              (16U)
#define GMAC_MAC_MDIO_DATA_RA_WIDTH              (16U)
#define GMAC_MAC_MDIO_DATA_RA(x)                 (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_MDIO_DATA_RA_SHIFT)) & GMAC_MAC_MDIO_DATA_RA_MASK)
/*! @} */

/*! @name MAC_ARP_ADDRESS -  */
/*! @{ */

#define GMAC_MAC_ARP_ADDRESS_ARPPA_MASK          (0xFFFFFFFFU)
#define GMAC_MAC_ARP_ADDRESS_ARPPA_SHIFT         (0U)
#define GMAC_MAC_ARP_ADDRESS_ARPPA_WIDTH         (32U)
#define GMAC_MAC_ARP_ADDRESS_ARPPA(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ARP_ADDRESS_ARPPA_SHIFT)) & GMAC_MAC_ARP_ADDRESS_ARPPA_MASK)
/*! @} */

/*! @name MAC_CSR_SW_CTRL -  */
/*! @{ */

#define GMAC_MAC_CSR_SW_CTRL_RCWE_MASK           (0x1U)
#define GMAC_MAC_CSR_SW_CTRL_RCWE_SHIFT          (0U)
#define GMAC_MAC_CSR_SW_CTRL_RCWE_WIDTH          (1U)
#define GMAC_MAC_CSR_SW_CTRL_RCWE(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CSR_SW_CTRL_RCWE_SHIFT)) & GMAC_MAC_CSR_SW_CTRL_RCWE_MASK)

#define GMAC_MAC_CSR_SW_CTRL_Reserved_7_1_MASK   (0xFEU)
#define GMAC_MAC_CSR_SW_CTRL_Reserved_7_1_SHIFT  (1U)
#define GMAC_MAC_CSR_SW_CTRL_Reserved_7_1_WIDTH  (7U)
#define GMAC_MAC_CSR_SW_CTRL_Reserved_7_1(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CSR_SW_CTRL_Reserved_7_1_SHIFT)) & GMAC_MAC_CSR_SW_CTRL_Reserved_7_1_MASK)

#define GMAC_MAC_CSR_SW_CTRL_SEEN_MASK           (0x100U)
#define GMAC_MAC_CSR_SW_CTRL_SEEN_SHIFT          (8U)
#define GMAC_MAC_CSR_SW_CTRL_SEEN_WIDTH          (1U)
#define GMAC_MAC_CSR_SW_CTRL_SEEN(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CSR_SW_CTRL_SEEN_SHIFT)) & GMAC_MAC_CSR_SW_CTRL_SEEN_MASK)

#define GMAC_MAC_CSR_SW_CTRL_Reserved_31_9_MASK  (0xFFFFFE00U)
#define GMAC_MAC_CSR_SW_CTRL_Reserved_31_9_SHIFT (9U)
#define GMAC_MAC_CSR_SW_CTRL_Reserved_31_9_WIDTH (23U)
#define GMAC_MAC_CSR_SW_CTRL_Reserved_31_9(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_CSR_SW_CTRL_Reserved_31_9_SHIFT)) & GMAC_MAC_CSR_SW_CTRL_Reserved_31_9_MASK)
/*! @} */

/*! @name MAC_FPE_CTRL_STS -  */
/*! @{ */

#define GMAC_MAC_FPE_CTRL_STS_EFPE_MASK          (0x1U)
#define GMAC_MAC_FPE_CTRL_STS_EFPE_SHIFT         (0U)
#define GMAC_MAC_FPE_CTRL_STS_EFPE_WIDTH         (1U)
#define GMAC_MAC_FPE_CTRL_STS_EFPE(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FPE_CTRL_STS_EFPE_SHIFT)) & GMAC_MAC_FPE_CTRL_STS_EFPE_MASK)

#define GMAC_MAC_FPE_CTRL_STS_SVER_MASK          (0x2U)
#define GMAC_MAC_FPE_CTRL_STS_SVER_SHIFT         (1U)
#define GMAC_MAC_FPE_CTRL_STS_SVER_WIDTH         (1U)
#define GMAC_MAC_FPE_CTRL_STS_SVER(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FPE_CTRL_STS_SVER_SHIFT)) & GMAC_MAC_FPE_CTRL_STS_SVER_MASK)

#define GMAC_MAC_FPE_CTRL_STS_SRSP_MASK          (0x4U)
#define GMAC_MAC_FPE_CTRL_STS_SRSP_SHIFT         (2U)
#define GMAC_MAC_FPE_CTRL_STS_SRSP_WIDTH         (1U)
#define GMAC_MAC_FPE_CTRL_STS_SRSP(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FPE_CTRL_STS_SRSP_SHIFT)) & GMAC_MAC_FPE_CTRL_STS_SRSP_MASK)

#define GMAC_MAC_FPE_CTRL_STS_S1_SET_0_MASK      (0x8U)
#define GMAC_MAC_FPE_CTRL_STS_S1_SET_0_SHIFT     (3U)
#define GMAC_MAC_FPE_CTRL_STS_S1_SET_0_WIDTH     (1U)
#define GMAC_MAC_FPE_CTRL_STS_S1_SET_0(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FPE_CTRL_STS_S1_SET_0_SHIFT)) & GMAC_MAC_FPE_CTRL_STS_S1_SET_0_MASK)

#define GMAC_MAC_FPE_CTRL_STS_Reserved_15_4_MASK (0xFFF0U)
#define GMAC_MAC_FPE_CTRL_STS_Reserved_15_4_SHIFT (4U)
#define GMAC_MAC_FPE_CTRL_STS_Reserved_15_4_WIDTH (12U)
#define GMAC_MAC_FPE_CTRL_STS_Reserved_15_4(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FPE_CTRL_STS_Reserved_15_4_SHIFT)) & GMAC_MAC_FPE_CTRL_STS_Reserved_15_4_MASK)

#define GMAC_MAC_FPE_CTRL_STS_RVER_MASK          (0x10000U)
#define GMAC_MAC_FPE_CTRL_STS_RVER_SHIFT         (16U)
#define GMAC_MAC_FPE_CTRL_STS_RVER_WIDTH         (1U)
#define GMAC_MAC_FPE_CTRL_STS_RVER(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FPE_CTRL_STS_RVER_SHIFT)) & GMAC_MAC_FPE_CTRL_STS_RVER_MASK)

#define GMAC_MAC_FPE_CTRL_STS_RRSP_MASK          (0x20000U)
#define GMAC_MAC_FPE_CTRL_STS_RRSP_SHIFT         (17U)
#define GMAC_MAC_FPE_CTRL_STS_RRSP_WIDTH         (1U)
#define GMAC_MAC_FPE_CTRL_STS_RRSP(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FPE_CTRL_STS_RRSP_SHIFT)) & GMAC_MAC_FPE_CTRL_STS_RRSP_MASK)

#define GMAC_MAC_FPE_CTRL_STS_TVER_MASK          (0x40000U)
#define GMAC_MAC_FPE_CTRL_STS_TVER_SHIFT         (18U)
#define GMAC_MAC_FPE_CTRL_STS_TVER_WIDTH         (1U)
#define GMAC_MAC_FPE_CTRL_STS_TVER(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FPE_CTRL_STS_TVER_SHIFT)) & GMAC_MAC_FPE_CTRL_STS_TVER_MASK)

#define GMAC_MAC_FPE_CTRL_STS_TRSP_MASK          (0x80000U)
#define GMAC_MAC_FPE_CTRL_STS_TRSP_SHIFT         (19U)
#define GMAC_MAC_FPE_CTRL_STS_TRSP_WIDTH         (1U)
#define GMAC_MAC_FPE_CTRL_STS_TRSP(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FPE_CTRL_STS_TRSP_SHIFT)) & GMAC_MAC_FPE_CTRL_STS_TRSP_MASK)

#define GMAC_MAC_FPE_CTRL_STS_Reserved_31_20_MASK (0xFFF00000U)
#define GMAC_MAC_FPE_CTRL_STS_Reserved_31_20_SHIFT (20U)
#define GMAC_MAC_FPE_CTRL_STS_Reserved_31_20_WIDTH (12U)
#define GMAC_MAC_FPE_CTRL_STS_Reserved_31_20(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_FPE_CTRL_STS_Reserved_31_20_SHIFT)) & GMAC_MAC_FPE_CTRL_STS_Reserved_31_20_MASK)
/*! @} */

/*! @name MAC_EXT_CFG1 -  */
/*! @{ */

#define GMAC_MAC_EXT_CFG1_SPLOFST_MASK           (0x7FU)
#define GMAC_MAC_EXT_CFG1_SPLOFST_SHIFT          (0U)
#define GMAC_MAC_EXT_CFG1_SPLOFST_WIDTH          (7U)
#define GMAC_MAC_EXT_CFG1_SPLOFST(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CFG1_SPLOFST_SHIFT)) & GMAC_MAC_EXT_CFG1_SPLOFST_MASK)

#define GMAC_MAC_EXT_CFG1_Reserved_7_MASK        (0x80U)
#define GMAC_MAC_EXT_CFG1_Reserved_7_SHIFT       (7U)
#define GMAC_MAC_EXT_CFG1_Reserved_7_WIDTH       (1U)
#define GMAC_MAC_EXT_CFG1_Reserved_7(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CFG1_Reserved_7_SHIFT)) & GMAC_MAC_EXT_CFG1_Reserved_7_MASK)

#define GMAC_MAC_EXT_CFG1_SPLM_MASK              (0x300U)
#define GMAC_MAC_EXT_CFG1_SPLM_SHIFT             (8U)
#define GMAC_MAC_EXT_CFG1_SPLM_WIDTH             (2U)
#define GMAC_MAC_EXT_CFG1_SPLM(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CFG1_SPLM_SHIFT)) & GMAC_MAC_EXT_CFG1_SPLM_MASK)

#define GMAC_MAC_EXT_CFG1_Reserved_15_10_MASK    (0xFC00U)
#define GMAC_MAC_EXT_CFG1_Reserved_15_10_SHIFT   (10U)
#define GMAC_MAC_EXT_CFG1_Reserved_15_10_WIDTH   (6U)
#define GMAC_MAC_EXT_CFG1_Reserved_15_10(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CFG1_Reserved_15_10_SHIFT)) & GMAC_MAC_EXT_CFG1_Reserved_15_10_MASK)

#define GMAC_MAC_EXT_CFG1_SAVO_MASK              (0x7F0000U)
#define GMAC_MAC_EXT_CFG1_SAVO_SHIFT             (16U)
#define GMAC_MAC_EXT_CFG1_SAVO_WIDTH             (7U)
#define GMAC_MAC_EXT_CFG1_SAVO(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CFG1_SAVO_SHIFT)) & GMAC_MAC_EXT_CFG1_SAVO_MASK)

#define GMAC_MAC_EXT_CFG1_Reserved_23_MASK       (0x800000U)
#define GMAC_MAC_EXT_CFG1_Reserved_23_SHIFT      (23U)
#define GMAC_MAC_EXT_CFG1_Reserved_23_WIDTH      (1U)
#define GMAC_MAC_EXT_CFG1_Reserved_23(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CFG1_Reserved_23_SHIFT)) & GMAC_MAC_EXT_CFG1_Reserved_23_MASK)

#define GMAC_MAC_EXT_CFG1_SAVE_MASK              (0x1000000U)
#define GMAC_MAC_EXT_CFG1_SAVE_SHIFT             (24U)
#define GMAC_MAC_EXT_CFG1_SAVE_WIDTH             (1U)
#define GMAC_MAC_EXT_CFG1_SAVE(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CFG1_SAVE_SHIFT)) & GMAC_MAC_EXT_CFG1_SAVE_MASK)

#define GMAC_MAC_EXT_CFG1_Reserved_31_25_MASK    (0xFE000000U)
#define GMAC_MAC_EXT_CFG1_Reserved_31_25_SHIFT   (25U)
#define GMAC_MAC_EXT_CFG1_Reserved_31_25_WIDTH   (7U)
#define GMAC_MAC_EXT_CFG1_Reserved_31_25(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_EXT_CFG1_Reserved_31_25_SHIFT)) & GMAC_MAC_EXT_CFG1_Reserved_31_25_MASK)
/*! @} */

/*! @name MAC_PRESN_TIME_NS -  */
/*! @{ */

#define GMAC_MAC_PRESN_TIME_NS_MPTN_MASK         (0xFFFFFFFFU)
#define GMAC_MAC_PRESN_TIME_NS_MPTN_SHIFT        (0U)
#define GMAC_MAC_PRESN_TIME_NS_MPTN_WIDTH        (32U)
#define GMAC_MAC_PRESN_TIME_NS_MPTN(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PRESN_TIME_NS_MPTN_SHIFT)) & GMAC_MAC_PRESN_TIME_NS_MPTN_MASK)
/*! @} */

/*! @name MAC_PRESN_TIME_UPDT -  */
/*! @{ */

#define GMAC_MAC_PRESN_TIME_UPDT_MPTU_MASK       (0xFFFFFFFFU)
#define GMAC_MAC_PRESN_TIME_UPDT_MPTU_SHIFT      (0U)
#define GMAC_MAC_PRESN_TIME_UPDT_MPTU_WIDTH      (32U)
#define GMAC_MAC_PRESN_TIME_UPDT_MPTU(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PRESN_TIME_UPDT_MPTU_SHIFT)) & GMAC_MAC_PRESN_TIME_UPDT_MPTU_MASK)
/*! @} */

/*! @name MAC_ADDRESS0_HIGH -  */
/*! @{ */

#define GMAC_MAC_ADDRESS0_HIGH_ADDRHI_MASK       (0xFFFFU)
#define GMAC_MAC_ADDRESS0_HIGH_ADDRHI_SHIFT      (0U)
#define GMAC_MAC_ADDRESS0_HIGH_ADDRHI_WIDTH      (16U)
#define GMAC_MAC_ADDRESS0_HIGH_ADDRHI(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS0_HIGH_ADDRHI_SHIFT)) & GMAC_MAC_ADDRESS0_HIGH_ADDRHI_MASK)

#define GMAC_MAC_ADDRESS0_HIGH_DCS_MASK          (0x70000U)
#define GMAC_MAC_ADDRESS0_HIGH_DCS_SHIFT         (16U)
#define GMAC_MAC_ADDRESS0_HIGH_DCS_WIDTH         (3U)
#define GMAC_MAC_ADDRESS0_HIGH_DCS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS0_HIGH_DCS_SHIFT)) & GMAC_MAC_ADDRESS0_HIGH_DCS_MASK)

#define GMAC_MAC_ADDRESS0_HIGH_Reserved_30_y_MASK (0x7FF80000U)
#define GMAC_MAC_ADDRESS0_HIGH_Reserved_30_y_SHIFT (19U)
#define GMAC_MAC_ADDRESS0_HIGH_Reserved_30_y_WIDTH (12U)
#define GMAC_MAC_ADDRESS0_HIGH_Reserved_30_y(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS0_HIGH_Reserved_30_y_SHIFT)) & GMAC_MAC_ADDRESS0_HIGH_Reserved_30_y_MASK)

#define GMAC_MAC_ADDRESS0_HIGH_AE_MASK           (0x80000000U)
#define GMAC_MAC_ADDRESS0_HIGH_AE_SHIFT          (31U)
#define GMAC_MAC_ADDRESS0_HIGH_AE_WIDTH          (1U)
#define GMAC_MAC_ADDRESS0_HIGH_AE(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS0_HIGH_AE_SHIFT)) & GMAC_MAC_ADDRESS0_HIGH_AE_MASK)
/*! @} */

/*! @name MAC_ADDRESS0_LOW -  */
/*! @{ */

#define GMAC_MAC_ADDRESS0_LOW_ADDRLO_MASK        (0xFFFFFFFFU)
#define GMAC_MAC_ADDRESS0_LOW_ADDRLO_SHIFT       (0U)
#define GMAC_MAC_ADDRESS0_LOW_ADDRLO_WIDTH       (32U)
#define GMAC_MAC_ADDRESS0_LOW_ADDRLO(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS0_LOW_ADDRLO_SHIFT)) & GMAC_MAC_ADDRESS0_LOW_ADDRLO_MASK)
/*! @} */

/*! @name MAC_ADDRESS1_HIGH -  */
/*! @{ */

#define GMAC_MAC_ADDRESS1_HIGH_ADDRHI_MASK       (0xFFFFU)
#define GMAC_MAC_ADDRESS1_HIGH_ADDRHI_SHIFT      (0U)
#define GMAC_MAC_ADDRESS1_HIGH_ADDRHI_WIDTH      (16U)
#define GMAC_MAC_ADDRESS1_HIGH_ADDRHI(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS1_HIGH_ADDRHI_SHIFT)) & GMAC_MAC_ADDRESS1_HIGH_ADDRHI_MASK)

#define GMAC_MAC_ADDRESS1_HIGH_DCS_MASK          (0x70000U)
#define GMAC_MAC_ADDRESS1_HIGH_DCS_SHIFT         (16U)
#define GMAC_MAC_ADDRESS1_HIGH_DCS_WIDTH         (3U)
#define GMAC_MAC_ADDRESS1_HIGH_DCS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS1_HIGH_DCS_SHIFT)) & GMAC_MAC_ADDRESS1_HIGH_DCS_MASK)

#define GMAC_MAC_ADDRESS1_HIGH_Reserved_23_y_MASK (0xF80000U)
#define GMAC_MAC_ADDRESS1_HIGH_Reserved_23_y_SHIFT (19U)
#define GMAC_MAC_ADDRESS1_HIGH_Reserved_23_y_WIDTH (5U)
#define GMAC_MAC_ADDRESS1_HIGH_Reserved_23_y(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS1_HIGH_Reserved_23_y_SHIFT)) & GMAC_MAC_ADDRESS1_HIGH_Reserved_23_y_MASK)

#define GMAC_MAC_ADDRESS1_HIGH_MBC_MASK          (0x3F000000U)
#define GMAC_MAC_ADDRESS1_HIGH_MBC_SHIFT         (24U)
#define GMAC_MAC_ADDRESS1_HIGH_MBC_WIDTH         (6U)
#define GMAC_MAC_ADDRESS1_HIGH_MBC(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS1_HIGH_MBC_SHIFT)) & GMAC_MAC_ADDRESS1_HIGH_MBC_MASK)

#define GMAC_MAC_ADDRESS1_HIGH_SA_MASK           (0x40000000U)
#define GMAC_MAC_ADDRESS1_HIGH_SA_SHIFT          (30U)
#define GMAC_MAC_ADDRESS1_HIGH_SA_WIDTH          (1U)
#define GMAC_MAC_ADDRESS1_HIGH_SA(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS1_HIGH_SA_SHIFT)) & GMAC_MAC_ADDRESS1_HIGH_SA_MASK)

#define GMAC_MAC_ADDRESS1_HIGH_AE_MASK           (0x80000000U)
#define GMAC_MAC_ADDRESS1_HIGH_AE_SHIFT          (31U)
#define GMAC_MAC_ADDRESS1_HIGH_AE_WIDTH          (1U)
#define GMAC_MAC_ADDRESS1_HIGH_AE(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS1_HIGH_AE_SHIFT)) & GMAC_MAC_ADDRESS1_HIGH_AE_MASK)
/*! @} */

/*! @name MAC_ADDRESS1_LOW -  */
/*! @{ */

#define GMAC_MAC_ADDRESS1_LOW_ADDRLO_MASK        (0xFFFFFFFFU)
#define GMAC_MAC_ADDRESS1_LOW_ADDRLO_SHIFT       (0U)
#define GMAC_MAC_ADDRESS1_LOW_ADDRLO_WIDTH       (32U)
#define GMAC_MAC_ADDRESS1_LOW_ADDRLO(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS1_LOW_ADDRLO_SHIFT)) & GMAC_MAC_ADDRESS1_LOW_ADDRLO_MASK)
/*! @} */

/*! @name MAC_ADDRESS2_HIGH -  */
/*! @{ */

#define GMAC_MAC_ADDRESS2_HIGH_ADDRHI_MASK       (0xFFFFU)
#define GMAC_MAC_ADDRESS2_HIGH_ADDRHI_SHIFT      (0U)
#define GMAC_MAC_ADDRESS2_HIGH_ADDRHI_WIDTH      (16U)
#define GMAC_MAC_ADDRESS2_HIGH_ADDRHI(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS2_HIGH_ADDRHI_SHIFT)) & GMAC_MAC_ADDRESS2_HIGH_ADDRHI_MASK)

#define GMAC_MAC_ADDRESS2_HIGH_DCS_MASK          (0x70000U)
#define GMAC_MAC_ADDRESS2_HIGH_DCS_SHIFT         (16U)
#define GMAC_MAC_ADDRESS2_HIGH_DCS_WIDTH         (3U)
#define GMAC_MAC_ADDRESS2_HIGH_DCS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS2_HIGH_DCS_SHIFT)) & GMAC_MAC_ADDRESS2_HIGH_DCS_MASK)

#define GMAC_MAC_ADDRESS2_HIGH_Reserved_23_y_MASK (0xF80000U)
#define GMAC_MAC_ADDRESS2_HIGH_Reserved_23_y_SHIFT (19U)
#define GMAC_MAC_ADDRESS2_HIGH_Reserved_23_y_WIDTH (5U)
#define GMAC_MAC_ADDRESS2_HIGH_Reserved_23_y(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS2_HIGH_Reserved_23_y_SHIFT)) & GMAC_MAC_ADDRESS2_HIGH_Reserved_23_y_MASK)

#define GMAC_MAC_ADDRESS2_HIGH_MBC_MASK          (0x3F000000U)
#define GMAC_MAC_ADDRESS2_HIGH_MBC_SHIFT         (24U)
#define GMAC_MAC_ADDRESS2_HIGH_MBC_WIDTH         (6U)
#define GMAC_MAC_ADDRESS2_HIGH_MBC(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS2_HIGH_MBC_SHIFT)) & GMAC_MAC_ADDRESS2_HIGH_MBC_MASK)

#define GMAC_MAC_ADDRESS2_HIGH_SA_MASK           (0x40000000U)
#define GMAC_MAC_ADDRESS2_HIGH_SA_SHIFT          (30U)
#define GMAC_MAC_ADDRESS2_HIGH_SA_WIDTH          (1U)
#define GMAC_MAC_ADDRESS2_HIGH_SA(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS2_HIGH_SA_SHIFT)) & GMAC_MAC_ADDRESS2_HIGH_SA_MASK)

#define GMAC_MAC_ADDRESS2_HIGH_AE_MASK           (0x80000000U)
#define GMAC_MAC_ADDRESS2_HIGH_AE_SHIFT          (31U)
#define GMAC_MAC_ADDRESS2_HIGH_AE_WIDTH          (1U)
#define GMAC_MAC_ADDRESS2_HIGH_AE(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS2_HIGH_AE_SHIFT)) & GMAC_MAC_ADDRESS2_HIGH_AE_MASK)
/*! @} */

/*! @name MAC_ADDRESS2_LOW -  */
/*! @{ */

#define GMAC_MAC_ADDRESS2_LOW_ADDRLO_MASK        (0xFFFFFFFFU)
#define GMAC_MAC_ADDRESS2_LOW_ADDRLO_SHIFT       (0U)
#define GMAC_MAC_ADDRESS2_LOW_ADDRLO_WIDTH       (32U)
#define GMAC_MAC_ADDRESS2_LOW_ADDRLO(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_ADDRESS2_LOW_ADDRLO_SHIFT)) & GMAC_MAC_ADDRESS2_LOW_ADDRLO_MASK)
/*! @} */

/*! @name MMC_CONTROL -  */
/*! @{ */

#define GMAC_MMC_CONTROL_CNTRST_MASK             (0x1U)
#define GMAC_MMC_CONTROL_CNTRST_SHIFT            (0U)
#define GMAC_MMC_CONTROL_CNTRST_WIDTH            (1U)
#define GMAC_MMC_CONTROL_CNTRST(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_CONTROL_CNTRST_SHIFT)) & GMAC_MMC_CONTROL_CNTRST_MASK)

#define GMAC_MMC_CONTROL_CNTSTOPRO_MASK          (0x2U)
#define GMAC_MMC_CONTROL_CNTSTOPRO_SHIFT         (1U)
#define GMAC_MMC_CONTROL_CNTSTOPRO_WIDTH         (1U)
#define GMAC_MMC_CONTROL_CNTSTOPRO(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_CONTROL_CNTSTOPRO_SHIFT)) & GMAC_MMC_CONTROL_CNTSTOPRO_MASK)

#define GMAC_MMC_CONTROL_RSTONRD_MASK            (0x4U)
#define GMAC_MMC_CONTROL_RSTONRD_SHIFT           (2U)
#define GMAC_MMC_CONTROL_RSTONRD_WIDTH           (1U)
#define GMAC_MMC_CONTROL_RSTONRD(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_CONTROL_RSTONRD_SHIFT)) & GMAC_MMC_CONTROL_RSTONRD_MASK)

#define GMAC_MMC_CONTROL_CNTFREEZ_MASK           (0x8U)
#define GMAC_MMC_CONTROL_CNTFREEZ_SHIFT          (3U)
#define GMAC_MMC_CONTROL_CNTFREEZ_WIDTH          (1U)
#define GMAC_MMC_CONTROL_CNTFREEZ(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_CONTROL_CNTFREEZ_SHIFT)) & GMAC_MMC_CONTROL_CNTFREEZ_MASK)

#define GMAC_MMC_CONTROL_CNTPRST_MASK            (0x10U)
#define GMAC_MMC_CONTROL_CNTPRST_SHIFT           (4U)
#define GMAC_MMC_CONTROL_CNTPRST_WIDTH           (1U)
#define GMAC_MMC_CONTROL_CNTPRST(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_CONTROL_CNTPRST_SHIFT)) & GMAC_MMC_CONTROL_CNTPRST_MASK)

#define GMAC_MMC_CONTROL_CNTPRSTLVL_MASK         (0x20U)
#define GMAC_MMC_CONTROL_CNTPRSTLVL_SHIFT        (5U)
#define GMAC_MMC_CONTROL_CNTPRSTLVL_WIDTH        (1U)
#define GMAC_MMC_CONTROL_CNTPRSTLVL(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_CONTROL_CNTPRSTLVL_SHIFT)) & GMAC_MMC_CONTROL_CNTPRSTLVL_MASK)

#define GMAC_MMC_CONTROL_Reserved_7_6_MASK       (0xC0U)
#define GMAC_MMC_CONTROL_Reserved_7_6_SHIFT      (6U)
#define GMAC_MMC_CONTROL_Reserved_7_6_WIDTH      (2U)
#define GMAC_MMC_CONTROL_Reserved_7_6(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_CONTROL_Reserved_7_6_SHIFT)) & GMAC_MMC_CONTROL_Reserved_7_6_MASK)

#define GMAC_MMC_CONTROL_UCDBC_MASK              (0x100U)
#define GMAC_MMC_CONTROL_UCDBC_SHIFT             (8U)
#define GMAC_MMC_CONTROL_UCDBC_WIDTH             (1U)
#define GMAC_MMC_CONTROL_UCDBC(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_CONTROL_UCDBC_SHIFT)) & GMAC_MMC_CONTROL_UCDBC_MASK)

#define GMAC_MMC_CONTROL_Reserved_31_9_MASK      (0xFFFFFE00U)
#define GMAC_MMC_CONTROL_Reserved_31_9_SHIFT     (9U)
#define GMAC_MMC_CONTROL_Reserved_31_9_WIDTH     (23U)
#define GMAC_MMC_CONTROL_Reserved_31_9(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_CONTROL_Reserved_31_9_SHIFT)) & GMAC_MMC_CONTROL_Reserved_31_9_MASK)
/*! @} */

/*! @name MMC_RX_INTERRUPT -  */
/*! @{ */

#define GMAC_MMC_RX_INTERRUPT_RXGBPKTIS_MASK     (0x1U)
#define GMAC_MMC_RX_INTERRUPT_RXGBPKTIS_SHIFT    (0U)
#define GMAC_MMC_RX_INTERRUPT_RXGBPKTIS_WIDTH    (1U)
#define GMAC_MMC_RX_INTERRUPT_RXGBPKTIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXGBPKTIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXGBPKTIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXGBOCTIS_MASK     (0x2U)
#define GMAC_MMC_RX_INTERRUPT_RXGBOCTIS_SHIFT    (1U)
#define GMAC_MMC_RX_INTERRUPT_RXGBOCTIS_WIDTH    (1U)
#define GMAC_MMC_RX_INTERRUPT_RXGBOCTIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXGBOCTIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXGBOCTIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXGOCTIS_MASK      (0x4U)
#define GMAC_MMC_RX_INTERRUPT_RXGOCTIS_SHIFT     (2U)
#define GMAC_MMC_RX_INTERRUPT_RXGOCTIS_WIDTH     (1U)
#define GMAC_MMC_RX_INTERRUPT_RXGOCTIS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXGOCTIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXGOCTIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXBCGPIS_MASK      (0x8U)
#define GMAC_MMC_RX_INTERRUPT_RXBCGPIS_SHIFT     (3U)
#define GMAC_MMC_RX_INTERRUPT_RXBCGPIS_WIDTH     (1U)
#define GMAC_MMC_RX_INTERRUPT_RXBCGPIS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXBCGPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXBCGPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXMCGPIS_MASK      (0x10U)
#define GMAC_MMC_RX_INTERRUPT_RXMCGPIS_SHIFT     (4U)
#define GMAC_MMC_RX_INTERRUPT_RXMCGPIS_WIDTH     (1U)
#define GMAC_MMC_RX_INTERRUPT_RXMCGPIS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXMCGPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXMCGPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXCRCERPIS_MASK    (0x20U)
#define GMAC_MMC_RX_INTERRUPT_RXCRCERPIS_SHIFT   (5U)
#define GMAC_MMC_RX_INTERRUPT_RXCRCERPIS_WIDTH   (1U)
#define GMAC_MMC_RX_INTERRUPT_RXCRCERPIS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXCRCERPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXCRCERPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXALGNERPIS_MASK   (0x40U)
#define GMAC_MMC_RX_INTERRUPT_RXALGNERPIS_SHIFT  (6U)
#define GMAC_MMC_RX_INTERRUPT_RXALGNERPIS_WIDTH  (1U)
#define GMAC_MMC_RX_INTERRUPT_RXALGNERPIS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXALGNERPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXALGNERPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXRUNTPIS_MASK     (0x80U)
#define GMAC_MMC_RX_INTERRUPT_RXRUNTPIS_SHIFT    (7U)
#define GMAC_MMC_RX_INTERRUPT_RXRUNTPIS_WIDTH    (1U)
#define GMAC_MMC_RX_INTERRUPT_RXRUNTPIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXRUNTPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXRUNTPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXJABERPIS_MASK    (0x100U)
#define GMAC_MMC_RX_INTERRUPT_RXJABERPIS_SHIFT   (8U)
#define GMAC_MMC_RX_INTERRUPT_RXJABERPIS_WIDTH   (1U)
#define GMAC_MMC_RX_INTERRUPT_RXJABERPIS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXJABERPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXJABERPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXUSIZEGPIS_MASK   (0x200U)
#define GMAC_MMC_RX_INTERRUPT_RXUSIZEGPIS_SHIFT  (9U)
#define GMAC_MMC_RX_INTERRUPT_RXUSIZEGPIS_WIDTH  (1U)
#define GMAC_MMC_RX_INTERRUPT_RXUSIZEGPIS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXUSIZEGPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXUSIZEGPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXOSIZEGPIS_MASK   (0x400U)
#define GMAC_MMC_RX_INTERRUPT_RXOSIZEGPIS_SHIFT  (10U)
#define GMAC_MMC_RX_INTERRUPT_RXOSIZEGPIS_WIDTH  (1U)
#define GMAC_MMC_RX_INTERRUPT_RXOSIZEGPIS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXOSIZEGPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXOSIZEGPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RX64OCTGBPIS_MASK  (0x800U)
#define GMAC_MMC_RX_INTERRUPT_RX64OCTGBPIS_SHIFT (11U)
#define GMAC_MMC_RX_INTERRUPT_RX64OCTGBPIS_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_RX64OCTGBPIS(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RX64OCTGBPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RX64OCTGBPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_MASK (0x1000U)
#define GMAC_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_SHIFT (12U)
#define GMAC_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_RX65T127OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RX65T127OCTGBPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_MASK (0x2000U)
#define GMAC_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_SHIFT (13U)
#define GMAC_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_RX128T255OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RX128T255OCTGBPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_MASK (0x4000U)
#define GMAC_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_SHIFT (14U)
#define GMAC_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_RX256T511OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RX256T511OCTGBPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_MASK (0x8000U)
#define GMAC_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_SHIFT (15U)
#define GMAC_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_MASK (0x10000U)
#define GMAC_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_SHIFT (16U)
#define GMAC_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXUCGPIS_MASK      (0x20000U)
#define GMAC_MMC_RX_INTERRUPT_RXUCGPIS_SHIFT     (17U)
#define GMAC_MMC_RX_INTERRUPT_RXUCGPIS_WIDTH     (1U)
#define GMAC_MMC_RX_INTERRUPT_RXUCGPIS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXUCGPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXUCGPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXLENERPIS_MASK    (0x40000U)
#define GMAC_MMC_RX_INTERRUPT_RXLENERPIS_SHIFT   (18U)
#define GMAC_MMC_RX_INTERRUPT_RXLENERPIS_WIDTH   (1U)
#define GMAC_MMC_RX_INTERRUPT_RXLENERPIS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXLENERPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXLENERPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXORANGEPIS_MASK   (0x80000U)
#define GMAC_MMC_RX_INTERRUPT_RXORANGEPIS_SHIFT  (19U)
#define GMAC_MMC_RX_INTERRUPT_RXORANGEPIS_WIDTH  (1U)
#define GMAC_MMC_RX_INTERRUPT_RXORANGEPIS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXORANGEPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXORANGEPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXPAUSPIS_MASK     (0x100000U)
#define GMAC_MMC_RX_INTERRUPT_RXPAUSPIS_SHIFT    (20U)
#define GMAC_MMC_RX_INTERRUPT_RXPAUSPIS_WIDTH    (1U)
#define GMAC_MMC_RX_INTERRUPT_RXPAUSPIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXPAUSPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXPAUSPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXFOVPIS_MASK      (0x200000U)
#define GMAC_MMC_RX_INTERRUPT_RXFOVPIS_SHIFT     (21U)
#define GMAC_MMC_RX_INTERRUPT_RXFOVPIS_WIDTH     (1U)
#define GMAC_MMC_RX_INTERRUPT_RXFOVPIS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXFOVPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXFOVPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXVLANGBPIS_MASK   (0x400000U)
#define GMAC_MMC_RX_INTERRUPT_RXVLANGBPIS_SHIFT  (22U)
#define GMAC_MMC_RX_INTERRUPT_RXVLANGBPIS_WIDTH  (1U)
#define GMAC_MMC_RX_INTERRUPT_RXVLANGBPIS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXVLANGBPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXVLANGBPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXWDOGPIS_MASK     (0x800000U)
#define GMAC_MMC_RX_INTERRUPT_RXWDOGPIS_SHIFT    (23U)
#define GMAC_MMC_RX_INTERRUPT_RXWDOGPIS_WIDTH    (1U)
#define GMAC_MMC_RX_INTERRUPT_RXWDOGPIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXWDOGPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXWDOGPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXRCVERRPIS_MASK   (0x1000000U)
#define GMAC_MMC_RX_INTERRUPT_RXRCVERRPIS_SHIFT  (24U)
#define GMAC_MMC_RX_INTERRUPT_RXRCVERRPIS_WIDTH  (1U)
#define GMAC_MMC_RX_INTERRUPT_RXRCVERRPIS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXRCVERRPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXRCVERRPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_RXCTRLPIS_MASK     (0x2000000U)
#define GMAC_MMC_RX_INTERRUPT_RXCTRLPIS_SHIFT    (25U)
#define GMAC_MMC_RX_INTERRUPT_RXCTRLPIS_WIDTH    (1U)
#define GMAC_MMC_RX_INTERRUPT_RXCTRLPIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_RXCTRLPIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_RXCTRLPIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_Reserved_RXLPIUSCIS_MASK (0x4000000U)
#define GMAC_MMC_RX_INTERRUPT_Reserved_RXLPIUSCIS_SHIFT (26U)
#define GMAC_MMC_RX_INTERRUPT_Reserved_RXLPIUSCIS_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_Reserved_RXLPIUSCIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_Reserved_RXLPIUSCIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_Reserved_RXLPIUSCIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_Reserved_RXLPITRCIS_MASK (0x8000000U)
#define GMAC_MMC_RX_INTERRUPT_Reserved_RXLPITRCIS_SHIFT (27U)
#define GMAC_MMC_RX_INTERRUPT_Reserved_RXLPITRCIS_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_Reserved_RXLPITRCIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_Reserved_RXLPITRCIS_SHIFT)) & GMAC_MMC_RX_INTERRUPT_Reserved_RXLPITRCIS_MASK)

#define GMAC_MMC_RX_INTERRUPT_Reserved_31_28_MASK (0xF0000000U)
#define GMAC_MMC_RX_INTERRUPT_Reserved_31_28_SHIFT (28U)
#define GMAC_MMC_RX_INTERRUPT_Reserved_31_28_WIDTH (4U)
#define GMAC_MMC_RX_INTERRUPT_Reserved_31_28(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_Reserved_31_28_SHIFT)) & GMAC_MMC_RX_INTERRUPT_Reserved_31_28_MASK)
/*! @} */

/*! @name MMC_TX_INTERRUPT -  */
/*! @{ */

#define GMAC_MMC_TX_INTERRUPT_TXGBOCTIS_MASK     (0x1U)
#define GMAC_MMC_TX_INTERRUPT_TXGBOCTIS_SHIFT    (0U)
#define GMAC_MMC_TX_INTERRUPT_TXGBOCTIS_WIDTH    (1U)
#define GMAC_MMC_TX_INTERRUPT_TXGBOCTIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXGBOCTIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXGBOCTIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXGBPKTIS_MASK     (0x2U)
#define GMAC_MMC_TX_INTERRUPT_TXGBPKTIS_SHIFT    (1U)
#define GMAC_MMC_TX_INTERRUPT_TXGBPKTIS_WIDTH    (1U)
#define GMAC_MMC_TX_INTERRUPT_TXGBPKTIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXGBPKTIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXGBPKTIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXBCGPIS_MASK      (0x4U)
#define GMAC_MMC_TX_INTERRUPT_TXBCGPIS_SHIFT     (2U)
#define GMAC_MMC_TX_INTERRUPT_TXBCGPIS_WIDTH     (1U)
#define GMAC_MMC_TX_INTERRUPT_TXBCGPIS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXBCGPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXBCGPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXMCGPIS_MASK      (0x8U)
#define GMAC_MMC_TX_INTERRUPT_TXMCGPIS_SHIFT     (3U)
#define GMAC_MMC_TX_INTERRUPT_TXMCGPIS_WIDTH     (1U)
#define GMAC_MMC_TX_INTERRUPT_TXMCGPIS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXMCGPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXMCGPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TX64OCTGBPIS_MASK  (0x10U)
#define GMAC_MMC_TX_INTERRUPT_TX64OCTGBPIS_SHIFT (4U)
#define GMAC_MMC_TX_INTERRUPT_TX64OCTGBPIS_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_TX64OCTGBPIS(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TX64OCTGBPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TX64OCTGBPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_MASK (0x20U)
#define GMAC_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_SHIFT (5U)
#define GMAC_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_TX65T127OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TX65T127OCTGBPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_MASK (0x40U)
#define GMAC_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_SHIFT (6U)
#define GMAC_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_TX128T255OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TX128T255OCTGBPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_MASK (0x80U)
#define GMAC_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_SHIFT (7U)
#define GMAC_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_TX256T511OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TX256T511OCTGBPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_MASK (0x100U)
#define GMAC_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_SHIFT (8U)
#define GMAC_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_MASK (0x200U)
#define GMAC_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_SHIFT (9U)
#define GMAC_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXUCGBPIS_MASK     (0x400U)
#define GMAC_MMC_TX_INTERRUPT_TXUCGBPIS_SHIFT    (10U)
#define GMAC_MMC_TX_INTERRUPT_TXUCGBPIS_WIDTH    (1U)
#define GMAC_MMC_TX_INTERRUPT_TXUCGBPIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXUCGBPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXUCGBPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXMCGBPIS_MASK     (0x800U)
#define GMAC_MMC_TX_INTERRUPT_TXMCGBPIS_SHIFT    (11U)
#define GMAC_MMC_TX_INTERRUPT_TXMCGBPIS_WIDTH    (1U)
#define GMAC_MMC_TX_INTERRUPT_TXMCGBPIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXMCGBPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXMCGBPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXBCGBPIS_MASK     (0x1000U)
#define GMAC_MMC_TX_INTERRUPT_TXBCGBPIS_SHIFT    (12U)
#define GMAC_MMC_TX_INTERRUPT_TXBCGBPIS_WIDTH    (1U)
#define GMAC_MMC_TX_INTERRUPT_TXBCGBPIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXBCGBPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXBCGBPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXUFLOWERPIS_MASK  (0x2000U)
#define GMAC_MMC_TX_INTERRUPT_TXUFLOWERPIS_SHIFT (13U)
#define GMAC_MMC_TX_INTERRUPT_TXUFLOWERPIS_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_TXUFLOWERPIS(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXUFLOWERPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXUFLOWERPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXSCOLGPIS_MASK    (0x4000U)
#define GMAC_MMC_TX_INTERRUPT_TXSCOLGPIS_SHIFT   (14U)
#define GMAC_MMC_TX_INTERRUPT_TXSCOLGPIS_WIDTH   (1U)
#define GMAC_MMC_TX_INTERRUPT_TXSCOLGPIS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXSCOLGPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXSCOLGPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXMCOLGPIS_MASK    (0x8000U)
#define GMAC_MMC_TX_INTERRUPT_TXMCOLGPIS_SHIFT   (15U)
#define GMAC_MMC_TX_INTERRUPT_TXMCOLGPIS_WIDTH   (1U)
#define GMAC_MMC_TX_INTERRUPT_TXMCOLGPIS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXMCOLGPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXMCOLGPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXDEFPIS_MASK      (0x10000U)
#define GMAC_MMC_TX_INTERRUPT_TXDEFPIS_SHIFT     (16U)
#define GMAC_MMC_TX_INTERRUPT_TXDEFPIS_WIDTH     (1U)
#define GMAC_MMC_TX_INTERRUPT_TXDEFPIS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXDEFPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXDEFPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXLATCOLPIS_MASK   (0x20000U)
#define GMAC_MMC_TX_INTERRUPT_TXLATCOLPIS_SHIFT  (17U)
#define GMAC_MMC_TX_INTERRUPT_TXLATCOLPIS_WIDTH  (1U)
#define GMAC_MMC_TX_INTERRUPT_TXLATCOLPIS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXLATCOLPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXLATCOLPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXEXCOLPIS_MASK    (0x40000U)
#define GMAC_MMC_TX_INTERRUPT_TXEXCOLPIS_SHIFT   (18U)
#define GMAC_MMC_TX_INTERRUPT_TXEXCOLPIS_WIDTH   (1U)
#define GMAC_MMC_TX_INTERRUPT_TXEXCOLPIS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXEXCOLPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXEXCOLPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXCARERPIS_MASK    (0x80000U)
#define GMAC_MMC_TX_INTERRUPT_TXCARERPIS_SHIFT   (19U)
#define GMAC_MMC_TX_INTERRUPT_TXCARERPIS_WIDTH   (1U)
#define GMAC_MMC_TX_INTERRUPT_TXCARERPIS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXCARERPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXCARERPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXGOCTIS_MASK      (0x100000U)
#define GMAC_MMC_TX_INTERRUPT_TXGOCTIS_SHIFT     (20U)
#define GMAC_MMC_TX_INTERRUPT_TXGOCTIS_WIDTH     (1U)
#define GMAC_MMC_TX_INTERRUPT_TXGOCTIS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXGOCTIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXGOCTIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXGPKTIS_MASK      (0x200000U)
#define GMAC_MMC_TX_INTERRUPT_TXGPKTIS_SHIFT     (21U)
#define GMAC_MMC_TX_INTERRUPT_TXGPKTIS_WIDTH     (1U)
#define GMAC_MMC_TX_INTERRUPT_TXGPKTIS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXGPKTIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXGPKTIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXEXDEFPIS_MASK    (0x400000U)
#define GMAC_MMC_TX_INTERRUPT_TXEXDEFPIS_SHIFT   (22U)
#define GMAC_MMC_TX_INTERRUPT_TXEXDEFPIS_WIDTH   (1U)
#define GMAC_MMC_TX_INTERRUPT_TXEXDEFPIS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXEXDEFPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXEXDEFPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXPAUSPIS_MASK     (0x800000U)
#define GMAC_MMC_TX_INTERRUPT_TXPAUSPIS_SHIFT    (23U)
#define GMAC_MMC_TX_INTERRUPT_TXPAUSPIS_WIDTH    (1U)
#define GMAC_MMC_TX_INTERRUPT_TXPAUSPIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXPAUSPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXPAUSPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXVLANGPIS_MASK    (0x1000000U)
#define GMAC_MMC_TX_INTERRUPT_TXVLANGPIS_SHIFT   (24U)
#define GMAC_MMC_TX_INTERRUPT_TXVLANGPIS_WIDTH   (1U)
#define GMAC_MMC_TX_INTERRUPT_TXVLANGPIS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXVLANGPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXVLANGPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_TXOSIZEGPIS_MASK   (0x2000000U)
#define GMAC_MMC_TX_INTERRUPT_TXOSIZEGPIS_SHIFT  (25U)
#define GMAC_MMC_TX_INTERRUPT_TXOSIZEGPIS_WIDTH  (1U)
#define GMAC_MMC_TX_INTERRUPT_TXOSIZEGPIS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_TXOSIZEGPIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_TXOSIZEGPIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_Reserved_TXLPIUSCIS_MASK (0x4000000U)
#define GMAC_MMC_TX_INTERRUPT_Reserved_TXLPIUSCIS_SHIFT (26U)
#define GMAC_MMC_TX_INTERRUPT_Reserved_TXLPIUSCIS_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_Reserved_TXLPIUSCIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_Reserved_TXLPIUSCIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_Reserved_TXLPIUSCIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_Reserved_TXLPITRCIS_MASK (0x8000000U)
#define GMAC_MMC_TX_INTERRUPT_Reserved_TXLPITRCIS_SHIFT (27U)
#define GMAC_MMC_TX_INTERRUPT_Reserved_TXLPITRCIS_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_Reserved_TXLPITRCIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_Reserved_TXLPITRCIS_SHIFT)) & GMAC_MMC_TX_INTERRUPT_Reserved_TXLPITRCIS_MASK)

#define GMAC_MMC_TX_INTERRUPT_Reserved_31_28_MASK (0xF0000000U)
#define GMAC_MMC_TX_INTERRUPT_Reserved_31_28_SHIFT (28U)
#define GMAC_MMC_TX_INTERRUPT_Reserved_31_28_WIDTH (4U)
#define GMAC_MMC_TX_INTERRUPT_Reserved_31_28(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_Reserved_31_28_SHIFT)) & GMAC_MMC_TX_INTERRUPT_Reserved_31_28_MASK)
/*! @} */

/*! @name MMC_RX_INTERRUPT_MASK -  */
/*! @{ */

#define GMAC_MMC_RX_INTERRUPT_MASK_RXGBPKTIM_MASK (0x1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXGBPKTIM_SHIFT (0U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXGBPKTIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXGBPKTIM(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXGBPKTIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXGBPKTIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXGBOCTIM_MASK (0x2U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXGBOCTIM_SHIFT (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXGBOCTIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXGBOCTIM(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXGBOCTIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXGBOCTIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXGOCTIM_MASK (0x4U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXGOCTIM_SHIFT (2U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXGOCTIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXGOCTIM(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXGOCTIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXGOCTIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXBCGPIM_MASK (0x8U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXBCGPIM_SHIFT (3U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXBCGPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXBCGPIM(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXBCGPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXBCGPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXMCGPIM_MASK (0x10U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXMCGPIM_SHIFT (4U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXMCGPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXMCGPIM(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXMCGPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXMCGPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXCRCERPIM_MASK (0x20U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXCRCERPIM_SHIFT (5U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXCRCERPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXCRCERPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXCRCERPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXCRCERPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXALGNERPIM_MASK (0x40U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXALGNERPIM_SHIFT (6U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXALGNERPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXALGNERPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXALGNERPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXALGNERPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXRUNTPIM_MASK (0x80U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXRUNTPIM_SHIFT (7U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXRUNTPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXRUNTPIM(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXRUNTPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXRUNTPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXJABERPIM_MASK (0x100U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXJABERPIM_SHIFT (8U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXJABERPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXJABERPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXJABERPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXJABERPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM_MASK (0x200U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM_SHIFT (9U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM_MASK (0x400U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM_SHIFT (10U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM_MASK (0x800U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM_SHIFT (11U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM_MASK (0x1000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM_SHIFT (12U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM_MASK (0x2000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM_SHIFT (13U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM_MASK (0x4000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM_SHIFT (14U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM_MASK (0x8000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM_SHIFT (15U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM_MASK (0x10000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM_SHIFT (16U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXUCGPIM_MASK (0x20000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXUCGPIM_SHIFT (17U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXUCGPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXUCGPIM(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXUCGPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXUCGPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXLENERPIM_MASK (0x40000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXLENERPIM_SHIFT (18U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXLENERPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXLENERPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXLENERPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXLENERPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXORANGEPIM_MASK (0x80000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXORANGEPIM_SHIFT (19U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXORANGEPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXORANGEPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXORANGEPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXORANGEPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXPAUSPIM_MASK (0x100000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXPAUSPIM_SHIFT (20U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXPAUSPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXPAUSPIM(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXPAUSPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXPAUSPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXFOVPIM_MASK (0x200000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXFOVPIM_SHIFT (21U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXFOVPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXFOVPIM(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXFOVPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXFOVPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM_MASK (0x400000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM_SHIFT (22U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXWDOGPIM_MASK (0x800000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXWDOGPIM_SHIFT (23U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXWDOGPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXWDOGPIM(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXWDOGPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXWDOGPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM_MASK (0x1000000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM_SHIFT (24U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_RXCTRLPIM_MASK (0x2000000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXCTRLPIM_SHIFT (25U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXCTRLPIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_RXCTRLPIM(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_RXCTRLPIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_RXCTRLPIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_Reserved_RXLPIUSCIM_MASK (0x4000000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_Reserved_RXLPIUSCIM_SHIFT (26U)
#define GMAC_MMC_RX_INTERRUPT_MASK_Reserved_RXLPIUSCIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_Reserved_RXLPIUSCIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_Reserved_RXLPIUSCIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_Reserved_RXLPIUSCIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_Reserved_RXLPITRCIM_MASK (0x8000000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_Reserved_RXLPITRCIM_SHIFT (27U)
#define GMAC_MMC_RX_INTERRUPT_MASK_Reserved_RXLPITRCIM_WIDTH (1U)
#define GMAC_MMC_RX_INTERRUPT_MASK_Reserved_RXLPITRCIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_Reserved_RXLPITRCIM_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_Reserved_RXLPITRCIM_MASK)

#define GMAC_MMC_RX_INTERRUPT_MASK_Reserved_31_28_MASK (0xF0000000U)
#define GMAC_MMC_RX_INTERRUPT_MASK_Reserved_31_28_SHIFT (28U)
#define GMAC_MMC_RX_INTERRUPT_MASK_Reserved_31_28_WIDTH (4U)
#define GMAC_MMC_RX_INTERRUPT_MASK_Reserved_31_28(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_INTERRUPT_MASK_Reserved_31_28_SHIFT)) & GMAC_MMC_RX_INTERRUPT_MASK_Reserved_31_28_MASK)
/*! @} */

/*! @name MMC_TX_INTERRUPT_MASK -  */
/*! @{ */

#define GMAC_MMC_TX_INTERRUPT_MASK_TXGBOCTIM_MASK (0x1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXGBOCTIM_SHIFT (0U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXGBOCTIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXGBOCTIM(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXGBOCTIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXGBOCTIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXGBPKTIM_MASK (0x2U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXGBPKTIM_SHIFT (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXGBPKTIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXGBPKTIM(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXGBPKTIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXGBPKTIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXBCGPIM_MASK (0x4U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXBCGPIM_SHIFT (2U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXBCGPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXBCGPIM(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXBCGPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXBCGPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXMCGPIM_MASK (0x8U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXMCGPIM_SHIFT (3U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXMCGPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXMCGPIM(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXMCGPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXMCGPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM_MASK (0x10U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM_SHIFT (4U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM_MASK (0x20U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM_SHIFT (5U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM_MASK (0x40U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM_SHIFT (6U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM_MASK (0x80U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM_SHIFT (7U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM_MASK (0x100U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM_SHIFT (8U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM_MASK (0x200U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM_SHIFT (9U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXUCGBPIM_MASK (0x400U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXUCGBPIM_SHIFT (10U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXUCGBPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXUCGBPIM(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXUCGBPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXUCGBPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXMCGBPIM_MASK (0x800U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXMCGBPIM_SHIFT (11U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXMCGBPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXMCGBPIM(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXMCGBPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXMCGBPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXBCGBPIM_MASK (0x1000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXBCGBPIM_SHIFT (12U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXBCGBPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXBCGBPIM(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXBCGBPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXBCGBPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM_MASK (0x2000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM_SHIFT (13U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM_MASK (0x4000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM_SHIFT (14U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM_MASK (0x8000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM_SHIFT (15U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXDEFPIM_MASK (0x10000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXDEFPIM_SHIFT (16U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXDEFPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXDEFPIM(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXDEFPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXDEFPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM_MASK (0x20000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM_SHIFT (17U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM_MASK (0x40000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM_SHIFT (18U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXCARERPIM_MASK (0x80000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXCARERPIM_SHIFT (19U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXCARERPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXCARERPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXCARERPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXCARERPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXGOCTIM_MASK (0x100000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXGOCTIM_SHIFT (20U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXGOCTIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXGOCTIM(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXGOCTIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXGOCTIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXGPKTIM_MASK (0x200000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXGPKTIM_SHIFT (21U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXGPKTIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXGPKTIM(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXGPKTIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXGPKTIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM_MASK (0x400000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM_SHIFT (22U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXPAUSPIM_MASK (0x800000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXPAUSPIM_SHIFT (23U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXPAUSPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXPAUSPIM(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXPAUSPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXPAUSPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXVLANGPIM_MASK (0x1000000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXVLANGPIM_SHIFT (24U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXVLANGPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXVLANGPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXVLANGPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXVLANGPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM_MASK (0x2000000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM_SHIFT (25U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_Reserved_TXLPIUSCIM_MASK (0x4000000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_Reserved_TXLPIUSCIM_SHIFT (26U)
#define GMAC_MMC_TX_INTERRUPT_MASK_Reserved_TXLPIUSCIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_Reserved_TXLPIUSCIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_Reserved_TXLPIUSCIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_Reserved_TXLPIUSCIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_Reserved_TXLPITRCIM_MASK (0x8000000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_Reserved_TXLPITRCIM_SHIFT (27U)
#define GMAC_MMC_TX_INTERRUPT_MASK_Reserved_TXLPITRCIM_WIDTH (1U)
#define GMAC_MMC_TX_INTERRUPT_MASK_Reserved_TXLPITRCIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_Reserved_TXLPITRCIM_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_Reserved_TXLPITRCIM_MASK)

#define GMAC_MMC_TX_INTERRUPT_MASK_Reserved_31_28_MASK (0xF0000000U)
#define GMAC_MMC_TX_INTERRUPT_MASK_Reserved_31_28_SHIFT (28U)
#define GMAC_MMC_TX_INTERRUPT_MASK_Reserved_31_28_WIDTH (4U)
#define GMAC_MMC_TX_INTERRUPT_MASK_Reserved_31_28(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_INTERRUPT_MASK_Reserved_31_28_SHIFT)) & GMAC_MMC_TX_INTERRUPT_MASK_Reserved_31_28_MASK)
/*! @} */

/*! @name TX_OCTET_COUNT_GOOD_BAD -  */
/*! @{ */

#define GMAC_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_MASK (0xFFFFFFFFU)
#define GMAC_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_SHIFT (0U)
#define GMAC_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_WIDTH (32U)
#define GMAC_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_SHIFT)) & GMAC_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_MASK)
/*! @} */

/*! @name TX_PACKET_COUNT_GOOD_BAD -  */
/*! @{ */

#define GMAC_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_MASK (0xFFFFFFFFU)
#define GMAC_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_SHIFT (0U)
#define GMAC_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_WIDTH (32U)
#define GMAC_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_SHIFT)) & GMAC_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_MASK)
/*! @} */

/*! @name TX_BROADCAST_PACKETS_GOOD -  */
/*! @{ */

#define GMAC_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_MASK (0xFFFFFFFFU)
#define GMAC_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_SHIFT (0U)
#define GMAC_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_WIDTH (32U)
#define GMAC_TX_BROADCAST_PACKETS_GOOD_TXBCASTG(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_SHIFT)) & GMAC_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_MASK)
/*! @} */

/*! @name TX_MULTICAST_PACKETS_GOOD -  */
/*! @{ */

#define GMAC_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_MASK (0xFFFFFFFFU)
#define GMAC_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_SHIFT (0U)
#define GMAC_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_WIDTH (32U)
#define GMAC_TX_MULTICAST_PACKETS_GOOD_TXMCASTG(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_SHIFT)) & GMAC_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_MASK)
/*! @} */

/*! @name TX_64OCTETS_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_MASK (0xFFFFFFFFU)
#define GMAC_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_SHIFT (0U)
#define GMAC_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_WIDTH (32U)
#define GMAC_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_SHIFT)) & GMAC_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_MASK)
/*! @} */

/*! @name TX_65TO127OCTETS_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_MASK (0xFFFFFFFFU)
#define GMAC_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_SHIFT (0U)
#define GMAC_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_WIDTH (32U)
#define GMAC_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_SHIFT)) & GMAC_TX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_MASK)
/*! @} */

/*! @name TX_128TO255OCTETS_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_MASK (0xFFFFFFFFU)
#define GMAC_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_SHIFT (0U)
#define GMAC_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_WIDTH (32U)
#define GMAC_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_SHIFT)) & GMAC_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_MASK)
/*! @} */

/*! @name TX_256TO511OCTETS_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_MASK (0xFFFFFFFFU)
#define GMAC_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_SHIFT (0U)
#define GMAC_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_WIDTH (32U)
#define GMAC_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_SHIFT)) & GMAC_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_MASK)
/*! @} */

/*! @name TX_512TO1023OCTETS_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_MASK (0xFFFFFFFFU)
#define GMAC_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_SHIFT (0U)
#define GMAC_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_WIDTH (32U)
#define GMAC_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_SHIFT)) & GMAC_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_MASK)
/*! @} */

/*! @name TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_MASK (0xFFFFFFFFU)
#define GMAC_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_SHIFT (0U)
#define GMAC_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_WIDTH (32U)
#define GMAC_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_SHIFT)) & GMAC_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_MASK)
/*! @} */

/*! @name TX_UNICAST_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_MASK (0xFFFFFFFFU)
#define GMAC_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_SHIFT (0U)
#define GMAC_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_WIDTH (32U)
#define GMAC_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_SHIFT)) & GMAC_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_MASK)
/*! @} */

/*! @name TX_MULTICAST_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_MASK (0xFFFFFFFFU)
#define GMAC_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_SHIFT (0U)
#define GMAC_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_WIDTH (32U)
#define GMAC_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_SHIFT)) & GMAC_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_MASK)
/*! @} */

/*! @name TX_BROADCAST_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_MASK (0xFFFFFFFFU)
#define GMAC_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_SHIFT (0U)
#define GMAC_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_WIDTH (32U)
#define GMAC_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_SHIFT)) & GMAC_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_MASK)
/*! @} */

/*! @name TX_UNDERFLOW_ERROR_PACKETS -  */
/*! @{ */

#define GMAC_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_MASK (0xFFFFFFFFU)
#define GMAC_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_SHIFT (0U)
#define GMAC_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_WIDTH (32U)
#define GMAC_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_SHIFT)) & GMAC_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_MASK)
/*! @} */

/*! @name TX_SINGLE_COLLISION_GOOD_PACKETS -  */
/*! @{ */

#define GMAC_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_MASK (0xFFFFFFFFU)
#define GMAC_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_SHIFT (0U)
#define GMAC_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_WIDTH (32U)
#define GMAC_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_SHIFT)) & GMAC_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_MASK)
/*! @} */

/*! @name TX_MULTIPLE_COLLISION_GOOD_PACKETS -  */
/*! @{ */

#define GMAC_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_MASK (0xFFFFFFFFU)
#define GMAC_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_SHIFT (0U)
#define GMAC_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_WIDTH (32U)
#define GMAC_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_SHIFT)) & GMAC_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_MASK)
/*! @} */

/*! @name TX_DEFERRED_PACKETS -  */
/*! @{ */

#define GMAC_TX_DEFERRED_PACKETS_TXDEFRD_MASK    (0xFFFFFFFFU)
#define GMAC_TX_DEFERRED_PACKETS_TXDEFRD_SHIFT   (0U)
#define GMAC_TX_DEFERRED_PACKETS_TXDEFRD_WIDTH   (32U)
#define GMAC_TX_DEFERRED_PACKETS_TXDEFRD(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_TX_DEFERRED_PACKETS_TXDEFRD_SHIFT)) & GMAC_TX_DEFERRED_PACKETS_TXDEFRD_MASK)
/*! @} */

/*! @name TX_LATE_COLLISION_PACKETS -  */
/*! @{ */

#define GMAC_TX_LATE_COLLISION_PACKETS_TXLATECOL_MASK (0xFFFFFFFFU)
#define GMAC_TX_LATE_COLLISION_PACKETS_TXLATECOL_SHIFT (0U)
#define GMAC_TX_LATE_COLLISION_PACKETS_TXLATECOL_WIDTH (32U)
#define GMAC_TX_LATE_COLLISION_PACKETS_TXLATECOL(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_LATE_COLLISION_PACKETS_TXLATECOL_SHIFT)) & GMAC_TX_LATE_COLLISION_PACKETS_TXLATECOL_MASK)
/*! @} */

/*! @name TX_EXCESSIVE_COLLISION_PACKETS -  */
/*! @{ */

#define GMAC_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_MASK (0xFFFFFFFFU)
#define GMAC_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_SHIFT (0U)
#define GMAC_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_WIDTH (32U)
#define GMAC_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_SHIFT)) & GMAC_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_MASK)
/*! @} */

/*! @name TX_CARRIER_ERROR_PACKETS -  */
/*! @{ */

#define GMAC_TX_CARRIER_ERROR_PACKETS_TXCARR_MASK (0xFFFFFFFFU)
#define GMAC_TX_CARRIER_ERROR_PACKETS_TXCARR_SHIFT (0U)
#define GMAC_TX_CARRIER_ERROR_PACKETS_TXCARR_WIDTH (32U)
#define GMAC_TX_CARRIER_ERROR_PACKETS_TXCARR(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_TX_CARRIER_ERROR_PACKETS_TXCARR_SHIFT)) & GMAC_TX_CARRIER_ERROR_PACKETS_TXCARR_MASK)
/*! @} */

/*! @name TX_OCTET_COUNT_GOOD -  */
/*! @{ */

#define GMAC_TX_OCTET_COUNT_GOOD_TXOCTG_MASK     (0xFFFFFFFFU)
#define GMAC_TX_OCTET_COUNT_GOOD_TXOCTG_SHIFT    (0U)
#define GMAC_TX_OCTET_COUNT_GOOD_TXOCTG_WIDTH    (32U)
#define GMAC_TX_OCTET_COUNT_GOOD_TXOCTG(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_TX_OCTET_COUNT_GOOD_TXOCTG_SHIFT)) & GMAC_TX_OCTET_COUNT_GOOD_TXOCTG_MASK)
/*! @} */

/*! @name TX_PACKET_COUNT_GOOD -  */
/*! @{ */

#define GMAC_TX_PACKET_COUNT_GOOD_TXPKTG_MASK    (0xFFFFFFFFU)
#define GMAC_TX_PACKET_COUNT_GOOD_TXPKTG_SHIFT   (0U)
#define GMAC_TX_PACKET_COUNT_GOOD_TXPKTG_WIDTH   (32U)
#define GMAC_TX_PACKET_COUNT_GOOD_TXPKTG(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_TX_PACKET_COUNT_GOOD_TXPKTG_SHIFT)) & GMAC_TX_PACKET_COUNT_GOOD_TXPKTG_MASK)
/*! @} */

/*! @name TX_EXCESSIVE_DEFERRAL_ERROR -  */
/*! @{ */

#define GMAC_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_MASK (0xFFFFFFFFU)
#define GMAC_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_SHIFT (0U)
#define GMAC_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_WIDTH (32U)
#define GMAC_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF(x) (((uint32_t)(((uint32_t)(x)) << GMAC_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_SHIFT)) & GMAC_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_MASK)
/*! @} */

/*! @name TX_PAUSE_PACKETS -  */
/*! @{ */

#define GMAC_TX_PAUSE_PACKETS_TXPAUSE_MASK       (0xFFFFFFFFU)
#define GMAC_TX_PAUSE_PACKETS_TXPAUSE_SHIFT      (0U)
#define GMAC_TX_PAUSE_PACKETS_TXPAUSE_WIDTH      (32U)
#define GMAC_TX_PAUSE_PACKETS_TXPAUSE(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_TX_PAUSE_PACKETS_TXPAUSE_SHIFT)) & GMAC_TX_PAUSE_PACKETS_TXPAUSE_MASK)
/*! @} */

/*! @name TX_VLAN_PACKETS_GOOD -  */
/*! @{ */

#define GMAC_TX_VLAN_PACKETS_GOOD_TXVLANG_MASK   (0xFFFFFFFFU)
#define GMAC_TX_VLAN_PACKETS_GOOD_TXVLANG_SHIFT  (0U)
#define GMAC_TX_VLAN_PACKETS_GOOD_TXVLANG_WIDTH  (32U)
#define GMAC_TX_VLAN_PACKETS_GOOD_TXVLANG(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_TX_VLAN_PACKETS_GOOD_TXVLANG_SHIFT)) & GMAC_TX_VLAN_PACKETS_GOOD_TXVLANG_MASK)
/*! @} */

/*! @name TX_OSIZE_PACKETS_GOOD -  */
/*! @{ */

#define GMAC_TX_OSIZE_PACKETS_GOOD_TXOSIZG_MASK  (0xFFFFFFFFU)
#define GMAC_TX_OSIZE_PACKETS_GOOD_TXOSIZG_SHIFT (0U)
#define GMAC_TX_OSIZE_PACKETS_GOOD_TXOSIZG_WIDTH (32U)
#define GMAC_TX_OSIZE_PACKETS_GOOD_TXOSIZG(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_TX_OSIZE_PACKETS_GOOD_TXOSIZG_SHIFT)) & GMAC_TX_OSIZE_PACKETS_GOOD_TXOSIZG_MASK)
/*! @} */

/*! @name RX_PACKETS_COUNT_GOOD_BAD -  */
/*! @{ */

#define GMAC_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_MASK (0xFFFFFFFFU)
#define GMAC_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_SHIFT (0U)
#define GMAC_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_WIDTH (32U)
#define GMAC_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_SHIFT)) & GMAC_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_MASK)
/*! @} */

/*! @name RX_OCTET_COUNT_GOOD_BAD -  */
/*! @{ */

#define GMAC_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_MASK (0xFFFFFFFFU)
#define GMAC_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_SHIFT (0U)
#define GMAC_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_WIDTH (32U)
#define GMAC_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_SHIFT)) & GMAC_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_MASK)
/*! @} */

/*! @name RX_OCTET_COUNT_GOOD -  */
/*! @{ */

#define GMAC_RX_OCTET_COUNT_GOOD_RXOCTG_MASK     (0xFFFFFFFFU)
#define GMAC_RX_OCTET_COUNT_GOOD_RXOCTG_SHIFT    (0U)
#define GMAC_RX_OCTET_COUNT_GOOD_RXOCTG_WIDTH    (32U)
#define GMAC_RX_OCTET_COUNT_GOOD_RXOCTG(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_RX_OCTET_COUNT_GOOD_RXOCTG_SHIFT)) & GMAC_RX_OCTET_COUNT_GOOD_RXOCTG_MASK)
/*! @} */

/*! @name RX_BROADCAST_PACKETS_GOOD -  */
/*! @{ */

#define GMAC_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_MASK (0xFFFFFFFFU)
#define GMAC_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_SHIFT (0U)
#define GMAC_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_WIDTH (32U)
#define GMAC_RX_BROADCAST_PACKETS_GOOD_RXBCASTG(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_SHIFT)) & GMAC_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_MASK)
/*! @} */

/*! @name RX_MULTICAST_PACKETS_GOOD -  */
/*! @{ */

#define GMAC_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_MASK (0xFFFFFFFFU)
#define GMAC_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_SHIFT (0U)
#define GMAC_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_WIDTH (32U)
#define GMAC_RX_MULTICAST_PACKETS_GOOD_RXMCASTG(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_SHIFT)) & GMAC_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_MASK)
/*! @} */

/*! @name RX_CRC_ERROR_PACKETS -  */
/*! @{ */

#define GMAC_RX_CRC_ERROR_PACKETS_RXCRCERR_MASK  (0xFFFFFFFFU)
#define GMAC_RX_CRC_ERROR_PACKETS_RXCRCERR_SHIFT (0U)
#define GMAC_RX_CRC_ERROR_PACKETS_RXCRCERR_WIDTH (32U)
#define GMAC_RX_CRC_ERROR_PACKETS_RXCRCERR(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_RX_CRC_ERROR_PACKETS_RXCRCERR_SHIFT)) & GMAC_RX_CRC_ERROR_PACKETS_RXCRCERR_MASK)
/*! @} */

/*! @name RX_ALIGNMENT_ERROR_PACKETS -  */
/*! @{ */

#define GMAC_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_MASK (0xFFFFFFFFU)
#define GMAC_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_SHIFT (0U)
#define GMAC_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_WIDTH (32U)
#define GMAC_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_SHIFT)) & GMAC_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_MASK)
/*! @} */

/*! @name RX_RUNT_ERROR_PACKETS -  */
/*! @{ */

#define GMAC_RX_RUNT_ERROR_PACKETS_RXRUNTERR_MASK (0xFFFFFFFFU)
#define GMAC_RX_RUNT_ERROR_PACKETS_RXRUNTERR_SHIFT (0U)
#define GMAC_RX_RUNT_ERROR_PACKETS_RXRUNTERR_WIDTH (32U)
#define GMAC_RX_RUNT_ERROR_PACKETS_RXRUNTERR(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_RX_RUNT_ERROR_PACKETS_RXRUNTERR_SHIFT)) & GMAC_RX_RUNT_ERROR_PACKETS_RXRUNTERR_MASK)
/*! @} */

/*! @name RX_JABBER_ERROR_PACKETS -  */
/*! @{ */

#define GMAC_RX_JABBER_ERROR_PACKETS_RXJABERR_MASK (0xFFFFFFFFU)
#define GMAC_RX_JABBER_ERROR_PACKETS_RXJABERR_SHIFT (0U)
#define GMAC_RX_JABBER_ERROR_PACKETS_RXJABERR_WIDTH (32U)
#define GMAC_RX_JABBER_ERROR_PACKETS_RXJABERR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_JABBER_ERROR_PACKETS_RXJABERR_SHIFT)) & GMAC_RX_JABBER_ERROR_PACKETS_RXJABERR_MASK)
/*! @} */

/*! @name RX_UNDERSIZE_PACKETS_GOOD -  */
/*! @{ */

#define GMAC_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_MASK (0xFFFFFFFFU)
#define GMAC_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_SHIFT (0U)
#define GMAC_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_WIDTH (32U)
#define GMAC_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_SHIFT)) & GMAC_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_MASK)
/*! @} */

/*! @name RX_OVERSIZE_PACKETS_GOOD -  */
/*! @{ */

#define GMAC_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_MASK (0xFFFFFFFFU)
#define GMAC_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_SHIFT (0U)
#define GMAC_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_WIDTH (32U)
#define GMAC_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_SHIFT)) & GMAC_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_MASK)
/*! @} */

/*! @name RX_64OCTETS_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_MASK (0xFFFFFFFFU)
#define GMAC_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_SHIFT (0U)
#define GMAC_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_WIDTH (32U)
#define GMAC_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_SHIFT)) & GMAC_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_MASK)
/*! @} */

/*! @name RX_65TO127OCTETS_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB_MASK (0xFFFFFFFFU)
#define GMAC_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB_SHIFT (0U)
#define GMAC_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB_WIDTH (32U)
#define GMAC_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB_SHIFT)) & GMAC_RX_65TO127OCTETS_PACKETS_GOOD_BAD_RX65_127OCTGB_MASK)
/*! @} */

/*! @name RX_128TO255OCTETS_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_MASK (0xFFFFFFFFU)
#define GMAC_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_SHIFT (0U)
#define GMAC_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_WIDTH (32U)
#define GMAC_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_SHIFT)) & GMAC_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_MASK)
/*! @} */

/*! @name RX_256TO511OCTETS_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_MASK (0xFFFFFFFFU)
#define GMAC_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_SHIFT (0U)
#define GMAC_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_WIDTH (32U)
#define GMAC_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_SHIFT)) & GMAC_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_MASK)
/*! @} */

/*! @name RX_512TO1023OCTETS_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_MASK (0xFFFFFFFFU)
#define GMAC_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_SHIFT (0U)
#define GMAC_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_WIDTH (32U)
#define GMAC_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_SHIFT)) & GMAC_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_MASK)
/*! @} */

/*! @name RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_MASK (0xFFFFFFFFU)
#define GMAC_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_SHIFT (0U)
#define GMAC_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_WIDTH (32U)
#define GMAC_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_SHIFT)) & GMAC_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_MASK)
/*! @} */

/*! @name RX_UNICAST_PACKETS_GOOD -  */
/*! @{ */

#define GMAC_RX_UNICAST_PACKETS_GOOD_RXUCASTG_MASK (0xFFFFFFFFU)
#define GMAC_RX_UNICAST_PACKETS_GOOD_RXUCASTG_SHIFT (0U)
#define GMAC_RX_UNICAST_PACKETS_GOOD_RXUCASTG_WIDTH (32U)
#define GMAC_RX_UNICAST_PACKETS_GOOD_RXUCASTG(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_UNICAST_PACKETS_GOOD_RXUCASTG_SHIFT)) & GMAC_RX_UNICAST_PACKETS_GOOD_RXUCASTG_MASK)
/*! @} */

/*! @name RX_LENGTH_ERROR_PACKETS -  */
/*! @{ */

#define GMAC_RX_LENGTH_ERROR_PACKETS_RXLENERR_MASK (0xFFFFFFFFU)
#define GMAC_RX_LENGTH_ERROR_PACKETS_RXLENERR_SHIFT (0U)
#define GMAC_RX_LENGTH_ERROR_PACKETS_RXLENERR_WIDTH (32U)
#define GMAC_RX_LENGTH_ERROR_PACKETS_RXLENERR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_LENGTH_ERROR_PACKETS_RXLENERR_SHIFT)) & GMAC_RX_LENGTH_ERROR_PACKETS_RXLENERR_MASK)
/*! @} */

/*! @name RX_OUT_OF_RANGE_TYPE_PACKETS -  */
/*! @{ */

#define GMAC_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG_MASK (0xFFFFFFFFU)
#define GMAC_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG_SHIFT (0U)
#define GMAC_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG_WIDTH (32U)
#define GMAC_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG_SHIFT)) & GMAC_RX_OUT_OF_RANGE_TYPE_PACKETS_RXOUTOFRNG_MASK)
/*! @} */

/*! @name RX_PAUSE_PACKETS -  */
/*! @{ */

#define GMAC_RX_PAUSE_PACKETS_RXPAUSEPKT_MASK    (0xFFFFFFFFU)
#define GMAC_RX_PAUSE_PACKETS_RXPAUSEPKT_SHIFT   (0U)
#define GMAC_RX_PAUSE_PACKETS_RXPAUSEPKT_WIDTH   (32U)
#define GMAC_RX_PAUSE_PACKETS_RXPAUSEPKT(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_RX_PAUSE_PACKETS_RXPAUSEPKT_SHIFT)) & GMAC_RX_PAUSE_PACKETS_RXPAUSEPKT_MASK)
/*! @} */

/*! @name RX_FIFO_OVERFLOW_PACKETS -  */
/*! @{ */

#define GMAC_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_MASK (0xFFFFFFFFU)
#define GMAC_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_SHIFT (0U)
#define GMAC_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_WIDTH (32U)
#define GMAC_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_SHIFT)) & GMAC_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_MASK)
/*! @} */

/*! @name RX_VLAN_PACKETS_GOOD_BAD -  */
/*! @{ */

#define GMAC_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_MASK (0xFFFFFFFFU)
#define GMAC_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_SHIFT (0U)
#define GMAC_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_WIDTH (32U)
#define GMAC_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_SHIFT)) & GMAC_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_MASK)
/*! @} */

/*! @name RX_WATCHDOG_ERROR_PACKETS -  */
/*! @{ */

#define GMAC_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_MASK (0xFFFFFFFFU)
#define GMAC_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_SHIFT (0U)
#define GMAC_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_WIDTH (32U)
#define GMAC_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_SHIFT)) & GMAC_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_MASK)
/*! @} */

/*! @name RX_RECEIVE_ERROR_PACKETS -  */
/*! @{ */

#define GMAC_RX_RECEIVE_ERROR_PACKETS_RXRCVERR_MASK (0xFFFFFFFFU)
#define GMAC_RX_RECEIVE_ERROR_PACKETS_RXRCVERR_SHIFT (0U)
#define GMAC_RX_RECEIVE_ERROR_PACKETS_RXRCVERR_WIDTH (32U)
#define GMAC_RX_RECEIVE_ERROR_PACKETS_RXRCVERR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_RX_RECEIVE_ERROR_PACKETS_RXRCVERR_SHIFT)) & GMAC_RX_RECEIVE_ERROR_PACKETS_RXRCVERR_MASK)
/*! @} */

/*! @name RX_CONTROL_PACKETS_GOOD -  */
/*! @{ */

#define GMAC_RX_CONTROL_PACKETS_GOOD_RXCTRLG_MASK (0xFFFFFFFFU)
#define GMAC_RX_CONTROL_PACKETS_GOOD_RXCTRLG_SHIFT (0U)
#define GMAC_RX_CONTROL_PACKETS_GOOD_RXCTRLG_WIDTH (32U)
#define GMAC_RX_CONTROL_PACKETS_GOOD_RXCTRLG(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_RX_CONTROL_PACKETS_GOOD_RXCTRLG_SHIFT)) & GMAC_RX_CONTROL_PACKETS_GOOD_RXCTRLG_MASK)
/*! @} */

/*! @name MMC_FPE_TX_INTERRUPT -  */
/*! @{ */

#define GMAC_MMC_FPE_TX_INTERRUPT_FCIS_MASK      (0x1U)
#define GMAC_MMC_FPE_TX_INTERRUPT_FCIS_SHIFT     (0U)
#define GMAC_MMC_FPE_TX_INTERRUPT_FCIS_WIDTH     (1U)
#define GMAC_MMC_FPE_TX_INTERRUPT_FCIS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_TX_INTERRUPT_FCIS_SHIFT)) & GMAC_MMC_FPE_TX_INTERRUPT_FCIS_MASK)

#define GMAC_MMC_FPE_TX_INTERRUPT_HRCIS_MASK     (0x2U)
#define GMAC_MMC_FPE_TX_INTERRUPT_HRCIS_SHIFT    (1U)
#define GMAC_MMC_FPE_TX_INTERRUPT_HRCIS_WIDTH    (1U)
#define GMAC_MMC_FPE_TX_INTERRUPT_HRCIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_TX_INTERRUPT_HRCIS_SHIFT)) & GMAC_MMC_FPE_TX_INTERRUPT_HRCIS_MASK)

#define GMAC_MMC_FPE_TX_INTERRUPT_Reserved_31_2_MASK (0xFFFFFFFCU)
#define GMAC_MMC_FPE_TX_INTERRUPT_Reserved_31_2_SHIFT (2U)
#define GMAC_MMC_FPE_TX_INTERRUPT_Reserved_31_2_WIDTH (30U)
#define GMAC_MMC_FPE_TX_INTERRUPT_Reserved_31_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_TX_INTERRUPT_Reserved_31_2_SHIFT)) & GMAC_MMC_FPE_TX_INTERRUPT_Reserved_31_2_MASK)
/*! @} */

/*! @name MMC_FPE_TX_INTERRUPT_MASK -  */
/*! @{ */

#define GMAC_MMC_FPE_TX_INTERRUPT_MASK_FCIM_MASK (0x1U)
#define GMAC_MMC_FPE_TX_INTERRUPT_MASK_FCIM_SHIFT (0U)
#define GMAC_MMC_FPE_TX_INTERRUPT_MASK_FCIM_WIDTH (1U)
#define GMAC_MMC_FPE_TX_INTERRUPT_MASK_FCIM(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_TX_INTERRUPT_MASK_FCIM_SHIFT)) & GMAC_MMC_FPE_TX_INTERRUPT_MASK_FCIM_MASK)

#define GMAC_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_MASK (0x2U)
#define GMAC_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_SHIFT (1U)
#define GMAC_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_WIDTH (1U)
#define GMAC_MMC_FPE_TX_INTERRUPT_MASK_HRCIM(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_SHIFT)) & GMAC_MMC_FPE_TX_INTERRUPT_MASK_HRCIM_MASK)

#define GMAC_MMC_FPE_TX_INTERRUPT_MASK_Reserved_31_2_MASK (0xFFFFFFFCU)
#define GMAC_MMC_FPE_TX_INTERRUPT_MASK_Reserved_31_2_SHIFT (2U)
#define GMAC_MMC_FPE_TX_INTERRUPT_MASK_Reserved_31_2_WIDTH (30U)
#define GMAC_MMC_FPE_TX_INTERRUPT_MASK_Reserved_31_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_TX_INTERRUPT_MASK_Reserved_31_2_SHIFT)) & GMAC_MMC_FPE_TX_INTERRUPT_MASK_Reserved_31_2_MASK)
/*! @} */

/*! @name MMC_TX_FPE_FRAGMENT_CNTR -  */
/*! @{ */

#define GMAC_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_MASK (0xFFFFFFFFU)
#define GMAC_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_SHIFT (0U)
#define GMAC_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_WIDTH (32U)
#define GMAC_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_SHIFT)) & GMAC_MMC_TX_FPE_FRAGMENT_CNTR_TXFFC_MASK)
/*! @} */

/*! @name MMC_TX_HOLD_REQ_CNTR -  */
/*! @{ */

#define GMAC_MMC_TX_HOLD_REQ_CNTR_TXHRC_MASK     (0xFFFFFFFFU)
#define GMAC_MMC_TX_HOLD_REQ_CNTR_TXHRC_SHIFT    (0U)
#define GMAC_MMC_TX_HOLD_REQ_CNTR_TXHRC_WIDTH    (32U)
#define GMAC_MMC_TX_HOLD_REQ_CNTR_TXHRC(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_TX_HOLD_REQ_CNTR_TXHRC_SHIFT)) & GMAC_MMC_TX_HOLD_REQ_CNTR_TXHRC_MASK)
/*! @} */

/*! @name MMC_FPE_RX_INTERRUPT -  */
/*! @{ */

#define GMAC_MMC_FPE_RX_INTERRUPT_PAECIS_MASK    (0x1U)
#define GMAC_MMC_FPE_RX_INTERRUPT_PAECIS_SHIFT   (0U)
#define GMAC_MMC_FPE_RX_INTERRUPT_PAECIS_WIDTH   (1U)
#define GMAC_MMC_FPE_RX_INTERRUPT_PAECIS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_RX_INTERRUPT_PAECIS_SHIFT)) & GMAC_MMC_FPE_RX_INTERRUPT_PAECIS_MASK)

#define GMAC_MMC_FPE_RX_INTERRUPT_PSECIS_MASK    (0x2U)
#define GMAC_MMC_FPE_RX_INTERRUPT_PSECIS_SHIFT   (1U)
#define GMAC_MMC_FPE_RX_INTERRUPT_PSECIS_WIDTH   (1U)
#define GMAC_MMC_FPE_RX_INTERRUPT_PSECIS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_RX_INTERRUPT_PSECIS_SHIFT)) & GMAC_MMC_FPE_RX_INTERRUPT_PSECIS_MASK)

#define GMAC_MMC_FPE_RX_INTERRUPT_PAOCIS_MASK    (0x4U)
#define GMAC_MMC_FPE_RX_INTERRUPT_PAOCIS_SHIFT   (2U)
#define GMAC_MMC_FPE_RX_INTERRUPT_PAOCIS_WIDTH   (1U)
#define GMAC_MMC_FPE_RX_INTERRUPT_PAOCIS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_RX_INTERRUPT_PAOCIS_SHIFT)) & GMAC_MMC_FPE_RX_INTERRUPT_PAOCIS_MASK)

#define GMAC_MMC_FPE_RX_INTERRUPT_FCIS_MASK      (0x8U)
#define GMAC_MMC_FPE_RX_INTERRUPT_FCIS_SHIFT     (3U)
#define GMAC_MMC_FPE_RX_INTERRUPT_FCIS_WIDTH     (1U)
#define GMAC_MMC_FPE_RX_INTERRUPT_FCIS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_RX_INTERRUPT_FCIS_SHIFT)) & GMAC_MMC_FPE_RX_INTERRUPT_FCIS_MASK)

#define GMAC_MMC_FPE_RX_INTERRUPT_Reserved_31_4_MASK (0xFFFFFFF0U)
#define GMAC_MMC_FPE_RX_INTERRUPT_Reserved_31_4_SHIFT (4U)
#define GMAC_MMC_FPE_RX_INTERRUPT_Reserved_31_4_WIDTH (28U)
#define GMAC_MMC_FPE_RX_INTERRUPT_Reserved_31_4(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_RX_INTERRUPT_Reserved_31_4_SHIFT)) & GMAC_MMC_FPE_RX_INTERRUPT_Reserved_31_4_MASK)
/*! @} */

/*! @name MMC_FPE_RX_INTERRUPT_MASK -  */
/*! @{ */

#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_MASK (0x1U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_SHIFT (0U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_WIDTH (1U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_PAECIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_SHIFT)) & GMAC_MMC_FPE_RX_INTERRUPT_MASK_PAECIM_MASK)

#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_MASK (0x2U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_SHIFT (1U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_WIDTH (1U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_PSECIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_SHIFT)) & GMAC_MMC_FPE_RX_INTERRUPT_MASK_PSECIM_MASK)

#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_MASK (0x4U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_SHIFT (2U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_WIDTH (1U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_SHIFT)) & GMAC_MMC_FPE_RX_INTERRUPT_MASK_PAOCIM_MASK)

#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_FCIM_MASK (0x8U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_FCIM_SHIFT (3U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_FCIM_WIDTH (1U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_FCIM(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_RX_INTERRUPT_MASK_FCIM_SHIFT)) & GMAC_MMC_FPE_RX_INTERRUPT_MASK_FCIM_MASK)

#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_Reserved_31_4_MASK (0xFFFFFFF0U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_Reserved_31_4_SHIFT (4U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_Reserved_31_4_WIDTH (28U)
#define GMAC_MMC_FPE_RX_INTERRUPT_MASK_Reserved_31_4(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_FPE_RX_INTERRUPT_MASK_Reserved_31_4_SHIFT)) & GMAC_MMC_FPE_RX_INTERRUPT_MASK_Reserved_31_4_MASK)
/*! @} */

/*! @name MMC_RX_PACKET_ASSEMBLY_ERR_CNTR -  */
/*! @{ */

#define GMAC_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_MASK (0xFFFFFFFFU)
#define GMAC_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_SHIFT (0U)
#define GMAC_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_WIDTH (32U)
#define GMAC_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_SHIFT)) & GMAC_MMC_RX_PACKET_ASSEMBLY_ERR_CNTR_PAEC_MASK)
/*! @} */

/*! @name MMC_RX_PACKET_SMD_ERR_CNTR -  */
/*! @{ */

#define GMAC_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_MASK (0xFFFFFFFFU)
#define GMAC_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_SHIFT (0U)
#define GMAC_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_WIDTH (32U)
#define GMAC_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_SHIFT)) & GMAC_MMC_RX_PACKET_SMD_ERR_CNTR_PSEC_MASK)
/*! @} */

/*! @name MMC_RX_PACKET_ASSEMBLY_OK_CNTR -  */
/*! @{ */

#define GMAC_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_MASK (0xFFFFFFFFU)
#define GMAC_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_SHIFT (0U)
#define GMAC_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_WIDTH (32U)
#define GMAC_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_SHIFT)) & GMAC_MMC_RX_PACKET_ASSEMBLY_OK_CNTR_PAOC_MASK)
/*! @} */

/*! @name MMC_RX_FPE_FRAGMENT_CNTR -  */
/*! @{ */

#define GMAC_MMC_RX_FPE_FRAGMENT_CNTR_FFC_MASK   (0xFFFFFFFFU)
#define GMAC_MMC_RX_FPE_FRAGMENT_CNTR_FFC_SHIFT  (0U)
#define GMAC_MMC_RX_FPE_FRAGMENT_CNTR_FFC_WIDTH  (32U)
#define GMAC_MMC_RX_FPE_FRAGMENT_CNTR_FFC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MMC_RX_FPE_FRAGMENT_CNTR_FFC_SHIFT)) & GMAC_MMC_RX_FPE_FRAGMENT_CNTR_FFC_MASK)
/*! @} */

/*! @name MAC_L3_L4_CONTROL0 -  */
/*! @{ */

#define GMAC_MAC_L3_L4_CONTROL0_L3PEN0_MASK      (0x1U)
#define GMAC_MAC_L3_L4_CONTROL0_L3PEN0_SHIFT     (0U)
#define GMAC_MAC_L3_L4_CONTROL0_L3PEN0_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL0_L3PEN0(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_L3PEN0_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_L3PEN0_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_Reserved_1_MASK  (0x2U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_1_SHIFT (1U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_1_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_1(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_Reserved_1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_Reserved_1_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_L3SAM0_MASK      (0x4U)
#define GMAC_MAC_L3_L4_CONTROL0_L3SAM0_SHIFT     (2U)
#define GMAC_MAC_L3_L4_CONTROL0_L3SAM0_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL0_L3SAM0(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_L3SAM0_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_L3SAM0_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_L3SAIM0_MASK     (0x8U)
#define GMAC_MAC_L3_L4_CONTROL0_L3SAIM0_SHIFT    (3U)
#define GMAC_MAC_L3_L4_CONTROL0_L3SAIM0_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL0_L3SAIM0(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_L3SAIM0_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_L3SAIM0_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_L3DAM0_MASK      (0x10U)
#define GMAC_MAC_L3_L4_CONTROL0_L3DAM0_SHIFT     (4U)
#define GMAC_MAC_L3_L4_CONTROL0_L3DAM0_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL0_L3DAM0(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_L3DAM0_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_L3DAM0_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_L3DAIM0_MASK     (0x20U)
#define GMAC_MAC_L3_L4_CONTROL0_L3DAIM0_SHIFT    (5U)
#define GMAC_MAC_L3_L4_CONTROL0_L3DAIM0_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL0_L3DAIM0(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_L3DAIM0_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_L3DAIM0_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_L3HSBM0_MASK     (0x7C0U)
#define GMAC_MAC_L3_L4_CONTROL0_L3HSBM0_SHIFT    (6U)
#define GMAC_MAC_L3_L4_CONTROL0_L3HSBM0_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL0_L3HSBM0(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_L3HSBM0_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_L3HSBM0_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_L3HDBM0_MASK     (0xF800U)
#define GMAC_MAC_L3_L4_CONTROL0_L3HDBM0_SHIFT    (11U)
#define GMAC_MAC_L3_L4_CONTROL0_L3HDBM0_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL0_L3HDBM0(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_L3HDBM0_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_L3HDBM0_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_L4PEN0_MASK      (0x10000U)
#define GMAC_MAC_L3_L4_CONTROL0_L4PEN0_SHIFT     (16U)
#define GMAC_MAC_L3_L4_CONTROL0_L4PEN0_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL0_L4PEN0(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_L4PEN0_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_L4PEN0_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_Reserved_17_MASK (0x20000U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_17_SHIFT (17U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_17_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_17(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_Reserved_17_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_Reserved_17_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_L4SPM0_MASK      (0x40000U)
#define GMAC_MAC_L3_L4_CONTROL0_L4SPM0_SHIFT     (18U)
#define GMAC_MAC_L3_L4_CONTROL0_L4SPM0_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL0_L4SPM0(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_L4SPM0_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_L4SPM0_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_L4SPIM0_MASK     (0x80000U)
#define GMAC_MAC_L3_L4_CONTROL0_L4SPIM0_SHIFT    (19U)
#define GMAC_MAC_L3_L4_CONTROL0_L4SPIM0_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL0_L4SPIM0(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_L4SPIM0_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_L4SPIM0_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_L4DPM0_MASK      (0x100000U)
#define GMAC_MAC_L3_L4_CONTROL0_L4DPM0_SHIFT     (20U)
#define GMAC_MAC_L3_L4_CONTROL0_L4DPM0_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL0_L4DPM0(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_L4DPM0_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_L4DPM0_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_L4DPIM0_MASK     (0x200000U)
#define GMAC_MAC_L3_L4_CONTROL0_L4DPIM0_SHIFT    (21U)
#define GMAC_MAC_L3_L4_CONTROL0_L4DPIM0_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL0_L4DPIM0(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_L4DPIM0_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_L4DPIM0_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_Reserved_23_22_MASK (0xC00000U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_23_22_SHIFT (22U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_23_22_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_23_22(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_Reserved_23_22_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_Reserved_23_22_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_DMCHN0_MASK      (0x3000000U)
#define GMAC_MAC_L3_L4_CONTROL0_DMCHN0_SHIFT     (24U)
#define GMAC_MAC_L3_L4_CONTROL0_DMCHN0_WIDTH     (2U)
#define GMAC_MAC_L3_L4_CONTROL0_DMCHN0(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_DMCHN0_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_DMCHN0_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_Reserved_27_y_MASK (0xC000000U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_27_y_SHIFT (26U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_27_y_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_27_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_Reserved_27_y_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_Reserved_27_y_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_DMCHEN0_MASK     (0x10000000U)
#define GMAC_MAC_L3_L4_CONTROL0_DMCHEN0_SHIFT    (28U)
#define GMAC_MAC_L3_L4_CONTROL0_DMCHEN0_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL0_DMCHEN0(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_DMCHEN0_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_DMCHEN0_MASK)

#define GMAC_MAC_L3_L4_CONTROL0_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_31_29_SHIFT (29U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_31_29_WIDTH (3U)
#define GMAC_MAC_L3_L4_CONTROL0_Reserved_31_29(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL0_Reserved_31_29_SHIFT)) & GMAC_MAC_L3_L4_CONTROL0_Reserved_31_29_MASK)
/*! @} */

/*! @name MAC_LAYER4_ADDRESS0 -  */
/*! @{ */

#define GMAC_MAC_LAYER4_ADDRESS0_L4SP0_MASK      (0xFFFFU)
#define GMAC_MAC_LAYER4_ADDRESS0_L4SP0_SHIFT     (0U)
#define GMAC_MAC_LAYER4_ADDRESS0_L4SP0_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS0_L4SP0(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS0_L4SP0_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS0_L4SP0_MASK)

#define GMAC_MAC_LAYER4_ADDRESS0_L4DP0_MASK      (0xFFFF0000U)
#define GMAC_MAC_LAYER4_ADDRESS0_L4DP0_SHIFT     (16U)
#define GMAC_MAC_LAYER4_ADDRESS0_L4DP0_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS0_L4DP0(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS0_L4DP0_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS0_L4DP0_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR0_REG0 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR0_REG0_L3A00_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR0_REG0_L3A00_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR0_REG0_L3A00_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR0_REG0_L3A00(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR0_REG0_L3A00_SHIFT)) & GMAC_MAC_LAYER3_ADDR0_REG0_L3A00_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR1_REG0 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR1_REG0_L3A10_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR1_REG0_L3A10_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR1_REG0_L3A10_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR1_REG0_L3A10(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR1_REG0_L3A10_SHIFT)) & GMAC_MAC_LAYER3_ADDR1_REG0_L3A10_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR2_REG0 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR2_REG0_L3A20_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR2_REG0_L3A20_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR2_REG0_L3A20_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR2_REG0_L3A20(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR2_REG0_L3A20_SHIFT)) & GMAC_MAC_LAYER3_ADDR2_REG0_L3A20_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR3_REG0 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR3_REG0_L3A30_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR3_REG0_L3A30_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR3_REG0_L3A30_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR3_REG0_L3A30(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR3_REG0_L3A30_SHIFT)) & GMAC_MAC_LAYER3_ADDR3_REG0_L3A30_MASK)
/*! @} */

/*! @name MAC_L3_L4_CONTROL1 -  */
/*! @{ */

#define GMAC_MAC_L3_L4_CONTROL1_L3PEN1_MASK      (0x1U)
#define GMAC_MAC_L3_L4_CONTROL1_L3PEN1_SHIFT     (0U)
#define GMAC_MAC_L3_L4_CONTROL1_L3PEN1_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL1_L3PEN1(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_L3PEN1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_L3PEN1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_Reserved_1_MASK  (0x2U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_1_SHIFT (1U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_1_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_1(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_Reserved_1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_Reserved_1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_L3SAM1_MASK      (0x4U)
#define GMAC_MAC_L3_L4_CONTROL1_L3SAM1_SHIFT     (2U)
#define GMAC_MAC_L3_L4_CONTROL1_L3SAM1_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL1_L3SAM1(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_L3SAM1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_L3SAM1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_L3SAIM1_MASK     (0x8U)
#define GMAC_MAC_L3_L4_CONTROL1_L3SAIM1_SHIFT    (3U)
#define GMAC_MAC_L3_L4_CONTROL1_L3SAIM1_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL1_L3SAIM1(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_L3SAIM1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_L3SAIM1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_L3DAM1_MASK      (0x10U)
#define GMAC_MAC_L3_L4_CONTROL1_L3DAM1_SHIFT     (4U)
#define GMAC_MAC_L3_L4_CONTROL1_L3DAM1_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL1_L3DAM1(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_L3DAM1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_L3DAM1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_L3DAIM1_MASK     (0x20U)
#define GMAC_MAC_L3_L4_CONTROL1_L3DAIM1_SHIFT    (5U)
#define GMAC_MAC_L3_L4_CONTROL1_L3DAIM1_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL1_L3DAIM1(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_L3DAIM1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_L3DAIM1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_L3HSBM1_MASK     (0x7C0U)
#define GMAC_MAC_L3_L4_CONTROL1_L3HSBM1_SHIFT    (6U)
#define GMAC_MAC_L3_L4_CONTROL1_L3HSBM1_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL1_L3HSBM1(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_L3HSBM1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_L3HSBM1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_L3HDBM1_MASK     (0xF800U)
#define GMAC_MAC_L3_L4_CONTROL1_L3HDBM1_SHIFT    (11U)
#define GMAC_MAC_L3_L4_CONTROL1_L3HDBM1_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL1_L3HDBM1(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_L3HDBM1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_L3HDBM1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_L4PEN1_MASK      (0x10000U)
#define GMAC_MAC_L3_L4_CONTROL1_L4PEN1_SHIFT     (16U)
#define GMAC_MAC_L3_L4_CONTROL1_L4PEN1_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL1_L4PEN1(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_L4PEN1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_L4PEN1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_Reserved_17_MASK (0x20000U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_17_SHIFT (17U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_17_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_17(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_Reserved_17_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_Reserved_17_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_L4SPM1_MASK      (0x40000U)
#define GMAC_MAC_L3_L4_CONTROL1_L4SPM1_SHIFT     (18U)
#define GMAC_MAC_L3_L4_CONTROL1_L4SPM1_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL1_L4SPM1(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_L4SPM1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_L4SPM1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_L4SPIM1_MASK     (0x80000U)
#define GMAC_MAC_L3_L4_CONTROL1_L4SPIM1_SHIFT    (19U)
#define GMAC_MAC_L3_L4_CONTROL1_L4SPIM1_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL1_L4SPIM1(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_L4SPIM1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_L4SPIM1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_L4DPM1_MASK      (0x100000U)
#define GMAC_MAC_L3_L4_CONTROL1_L4DPM1_SHIFT     (20U)
#define GMAC_MAC_L3_L4_CONTROL1_L4DPM1_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL1_L4DPM1(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_L4DPM1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_L4DPM1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_L4DPIM1_MASK     (0x200000U)
#define GMAC_MAC_L3_L4_CONTROL1_L4DPIM1_SHIFT    (21U)
#define GMAC_MAC_L3_L4_CONTROL1_L4DPIM1_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL1_L4DPIM1(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_L4DPIM1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_L4DPIM1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_Reserved_23_22_MASK (0xC00000U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_23_22_SHIFT (22U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_23_22_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_23_22(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_Reserved_23_22_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_Reserved_23_22_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_DMCHN1_MASK      (0x3000000U)
#define GMAC_MAC_L3_L4_CONTROL1_DMCHN1_SHIFT     (24U)
#define GMAC_MAC_L3_L4_CONTROL1_DMCHN1_WIDTH     (2U)
#define GMAC_MAC_L3_L4_CONTROL1_DMCHN1(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_DMCHN1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_DMCHN1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_Reserved_27_y_MASK (0xC000000U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_27_y_SHIFT (26U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_27_y_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_27_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_Reserved_27_y_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_Reserved_27_y_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_DMCHEN1_MASK     (0x10000000U)
#define GMAC_MAC_L3_L4_CONTROL1_DMCHEN1_SHIFT    (28U)
#define GMAC_MAC_L3_L4_CONTROL1_DMCHEN1_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL1_DMCHEN1(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_DMCHEN1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_DMCHEN1_MASK)

#define GMAC_MAC_L3_L4_CONTROL1_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_31_29_SHIFT (29U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_31_29_WIDTH (3U)
#define GMAC_MAC_L3_L4_CONTROL1_Reserved_31_29(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL1_Reserved_31_29_SHIFT)) & GMAC_MAC_L3_L4_CONTROL1_Reserved_31_29_MASK)
/*! @} */

/*! @name MAC_LAYER4_ADDRESS1 -  */
/*! @{ */

#define GMAC_MAC_LAYER4_ADDRESS1_L4SP1_MASK      (0xFFFFU)
#define GMAC_MAC_LAYER4_ADDRESS1_L4SP1_SHIFT     (0U)
#define GMAC_MAC_LAYER4_ADDRESS1_L4SP1_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS1_L4SP1(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS1_L4SP1_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS1_L4SP1_MASK)

#define GMAC_MAC_LAYER4_ADDRESS1_L4DP1_MASK      (0xFFFF0000U)
#define GMAC_MAC_LAYER4_ADDRESS1_L4DP1_SHIFT     (16U)
#define GMAC_MAC_LAYER4_ADDRESS1_L4DP1_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS1_L4DP1(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS1_L4DP1_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS1_L4DP1_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR0_REG1 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR0_REG1_L3A01_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR0_REG1_L3A01_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR0_REG1_L3A01_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR0_REG1_L3A01(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR0_REG1_L3A01_SHIFT)) & GMAC_MAC_LAYER3_ADDR0_REG1_L3A01_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR1_REG1 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR1_REG1_L3A11_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR1_REG1_L3A11_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR1_REG1_L3A11_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR1_REG1_L3A11(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR1_REG1_L3A11_SHIFT)) & GMAC_MAC_LAYER3_ADDR1_REG1_L3A11_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR2_REG1 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR2_REG1_L3A21_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR2_REG1_L3A21_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR2_REG1_L3A21_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR2_REG1_L3A21(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR2_REG1_L3A21_SHIFT)) & GMAC_MAC_LAYER3_ADDR2_REG1_L3A21_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR3_REG1 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR3_REG1_L3A31_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR3_REG1_L3A31_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR3_REG1_L3A31_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR3_REG1_L3A31(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR3_REG1_L3A31_SHIFT)) & GMAC_MAC_LAYER3_ADDR3_REG1_L3A31_MASK)
/*! @} */

/*! @name MAC_L3_L4_CONTROL2 -  */
/*! @{ */

#define GMAC_MAC_L3_L4_CONTROL2_L3PEN2_MASK      (0x1U)
#define GMAC_MAC_L3_L4_CONTROL2_L3PEN2_SHIFT     (0U)
#define GMAC_MAC_L3_L4_CONTROL2_L3PEN2_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL2_L3PEN2(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_L3PEN2_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_L3PEN2_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_Reserved_1_MASK  (0x2U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_1_SHIFT (1U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_1_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_1(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_Reserved_1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_Reserved_1_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_L3SAM2_MASK      (0x4U)
#define GMAC_MAC_L3_L4_CONTROL2_L3SAM2_SHIFT     (2U)
#define GMAC_MAC_L3_L4_CONTROL2_L3SAM2_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL2_L3SAM2(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_L3SAM2_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_L3SAM2_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_L3SAIM2_MASK     (0x8U)
#define GMAC_MAC_L3_L4_CONTROL2_L3SAIM2_SHIFT    (3U)
#define GMAC_MAC_L3_L4_CONTROL2_L3SAIM2_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL2_L3SAIM2(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_L3SAIM2_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_L3SAIM2_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_L3DAM2_MASK      (0x10U)
#define GMAC_MAC_L3_L4_CONTROL2_L3DAM2_SHIFT     (4U)
#define GMAC_MAC_L3_L4_CONTROL2_L3DAM2_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL2_L3DAM2(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_L3DAM2_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_L3DAM2_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_L3DAIM2_MASK     (0x20U)
#define GMAC_MAC_L3_L4_CONTROL2_L3DAIM2_SHIFT    (5U)
#define GMAC_MAC_L3_L4_CONTROL2_L3DAIM2_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL2_L3DAIM2(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_L3DAIM2_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_L3DAIM2_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_L3HSBM2_MASK     (0x7C0U)
#define GMAC_MAC_L3_L4_CONTROL2_L3HSBM2_SHIFT    (6U)
#define GMAC_MAC_L3_L4_CONTROL2_L3HSBM2_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL2_L3HSBM2(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_L3HSBM2_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_L3HSBM2_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_L3HDBM2_MASK     (0xF800U)
#define GMAC_MAC_L3_L4_CONTROL2_L3HDBM2_SHIFT    (11U)
#define GMAC_MAC_L3_L4_CONTROL2_L3HDBM2_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL2_L3HDBM2(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_L3HDBM2_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_L3HDBM2_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_L4PEN2_MASK      (0x10000U)
#define GMAC_MAC_L3_L4_CONTROL2_L4PEN2_SHIFT     (16U)
#define GMAC_MAC_L3_L4_CONTROL2_L4PEN2_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL2_L4PEN2(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_L4PEN2_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_L4PEN2_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_Reserved_17_MASK (0x20000U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_17_SHIFT (17U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_17_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_17(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_Reserved_17_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_Reserved_17_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_L4SPM2_MASK      (0x40000U)
#define GMAC_MAC_L3_L4_CONTROL2_L4SPM2_SHIFT     (18U)
#define GMAC_MAC_L3_L4_CONTROL2_L4SPM2_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL2_L4SPM2(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_L4SPM2_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_L4SPM2_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_L4SPIM2_MASK     (0x80000U)
#define GMAC_MAC_L3_L4_CONTROL2_L4SPIM2_SHIFT    (19U)
#define GMAC_MAC_L3_L4_CONTROL2_L4SPIM2_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL2_L4SPIM2(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_L4SPIM2_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_L4SPIM2_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_L4DPM2_MASK      (0x100000U)
#define GMAC_MAC_L3_L4_CONTROL2_L4DPM2_SHIFT     (20U)
#define GMAC_MAC_L3_L4_CONTROL2_L4DPM2_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL2_L4DPM2(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_L4DPM2_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_L4DPM2_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_L4DPIM2_MASK     (0x200000U)
#define GMAC_MAC_L3_L4_CONTROL2_L4DPIM2_SHIFT    (21U)
#define GMAC_MAC_L3_L4_CONTROL2_L4DPIM2_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL2_L4DPIM2(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_L4DPIM2_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_L4DPIM2_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_Reserved_23_22_MASK (0xC00000U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_23_22_SHIFT (22U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_23_22_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_23_22(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_Reserved_23_22_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_Reserved_23_22_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_DMCHN2_MASK      (0x3000000U)
#define GMAC_MAC_L3_L4_CONTROL2_DMCHN2_SHIFT     (24U)
#define GMAC_MAC_L3_L4_CONTROL2_DMCHN2_WIDTH     (2U)
#define GMAC_MAC_L3_L4_CONTROL2_DMCHN2(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_DMCHN2_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_DMCHN2_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_Reserved_27_y_MASK (0xC000000U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_27_y_SHIFT (26U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_27_y_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_27_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_Reserved_27_y_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_Reserved_27_y_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_DMCHEN2_MASK     (0x10000000U)
#define GMAC_MAC_L3_L4_CONTROL2_DMCHEN2_SHIFT    (28U)
#define GMAC_MAC_L3_L4_CONTROL2_DMCHEN2_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL2_DMCHEN2(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_DMCHEN2_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_DMCHEN2_MASK)

#define GMAC_MAC_L3_L4_CONTROL2_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_31_29_SHIFT (29U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_31_29_WIDTH (3U)
#define GMAC_MAC_L3_L4_CONTROL2_Reserved_31_29(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL2_Reserved_31_29_SHIFT)) & GMAC_MAC_L3_L4_CONTROL2_Reserved_31_29_MASK)
/*! @} */

/*! @name MAC_LAYER4_ADDRESS2 -  */
/*! @{ */

#define GMAC_MAC_LAYER4_ADDRESS2_L4SP2_MASK      (0xFFFFU)
#define GMAC_MAC_LAYER4_ADDRESS2_L4SP2_SHIFT     (0U)
#define GMAC_MAC_LAYER4_ADDRESS2_L4SP2_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS2_L4SP2(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS2_L4SP2_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS2_L4SP2_MASK)

#define GMAC_MAC_LAYER4_ADDRESS2_L4DP2_MASK      (0xFFFF0000U)
#define GMAC_MAC_LAYER4_ADDRESS2_L4DP2_SHIFT     (16U)
#define GMAC_MAC_LAYER4_ADDRESS2_L4DP2_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS2_L4DP2(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS2_L4DP2_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS2_L4DP2_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR0_REG2 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR0_REG2_L3A02_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR0_REG2_L3A02_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR0_REG2_L3A02_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR0_REG2_L3A02(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR0_REG2_L3A02_SHIFT)) & GMAC_MAC_LAYER3_ADDR0_REG2_L3A02_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR1_REG2 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR1_REG2_L3A12_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR1_REG2_L3A12_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR1_REG2_L3A12_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR1_REG2_L3A12(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR1_REG2_L3A12_SHIFT)) & GMAC_MAC_LAYER3_ADDR1_REG2_L3A12_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR2_REG2 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR2_REG2_L3A22_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR2_REG2_L3A22_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR2_REG2_L3A22_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR2_REG2_L3A22(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR2_REG2_L3A22_SHIFT)) & GMAC_MAC_LAYER3_ADDR2_REG2_L3A22_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR3_REG2 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR3_REG2_L3A32_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR3_REG2_L3A32_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR3_REG2_L3A32_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR3_REG2_L3A32(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR3_REG2_L3A32_SHIFT)) & GMAC_MAC_LAYER3_ADDR3_REG2_L3A32_MASK)
/*! @} */

/*! @name MAC_L3_L4_CONTROL3 -  */
/*! @{ */

#define GMAC_MAC_L3_L4_CONTROL3_L3PEN3_MASK      (0x1U)
#define GMAC_MAC_L3_L4_CONTROL3_L3PEN3_SHIFT     (0U)
#define GMAC_MAC_L3_L4_CONTROL3_L3PEN3_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL3_L3PEN3(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_L3PEN3_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_L3PEN3_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_Reserved_1_MASK  (0x2U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_1_SHIFT (1U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_1_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_1(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_Reserved_1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_Reserved_1_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_L3SAM3_MASK      (0x4U)
#define GMAC_MAC_L3_L4_CONTROL3_L3SAM3_SHIFT     (2U)
#define GMAC_MAC_L3_L4_CONTROL3_L3SAM3_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL3_L3SAM3(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_L3SAM3_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_L3SAM3_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_L3SAIM3_MASK     (0x8U)
#define GMAC_MAC_L3_L4_CONTROL3_L3SAIM3_SHIFT    (3U)
#define GMAC_MAC_L3_L4_CONTROL3_L3SAIM3_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL3_L3SAIM3(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_L3SAIM3_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_L3SAIM3_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_L3DAM3_MASK      (0x10U)
#define GMAC_MAC_L3_L4_CONTROL3_L3DAM3_SHIFT     (4U)
#define GMAC_MAC_L3_L4_CONTROL3_L3DAM3_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL3_L3DAM3(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_L3DAM3_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_L3DAM3_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_L3DAIM3_MASK     (0x20U)
#define GMAC_MAC_L3_L4_CONTROL3_L3DAIM3_SHIFT    (5U)
#define GMAC_MAC_L3_L4_CONTROL3_L3DAIM3_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL3_L3DAIM3(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_L3DAIM3_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_L3DAIM3_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_L3HSBM3_MASK     (0x7C0U)
#define GMAC_MAC_L3_L4_CONTROL3_L3HSBM3_SHIFT    (6U)
#define GMAC_MAC_L3_L4_CONTROL3_L3HSBM3_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL3_L3HSBM3(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_L3HSBM3_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_L3HSBM3_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_L3HDBM3_MASK     (0xF800U)
#define GMAC_MAC_L3_L4_CONTROL3_L3HDBM3_SHIFT    (11U)
#define GMAC_MAC_L3_L4_CONTROL3_L3HDBM3_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL3_L3HDBM3(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_L3HDBM3_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_L3HDBM3_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_L4PEN3_MASK      (0x10000U)
#define GMAC_MAC_L3_L4_CONTROL3_L4PEN3_SHIFT     (16U)
#define GMAC_MAC_L3_L4_CONTROL3_L4PEN3_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL3_L4PEN3(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_L4PEN3_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_L4PEN3_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_Reserved_17_MASK (0x20000U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_17_SHIFT (17U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_17_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_17(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_Reserved_17_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_Reserved_17_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_L4SPM3_MASK      (0x40000U)
#define GMAC_MAC_L3_L4_CONTROL3_L4SPM3_SHIFT     (18U)
#define GMAC_MAC_L3_L4_CONTROL3_L4SPM3_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL3_L4SPM3(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_L4SPM3_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_L4SPM3_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_L4SPIM3_MASK     (0x80000U)
#define GMAC_MAC_L3_L4_CONTROL3_L4SPIM3_SHIFT    (19U)
#define GMAC_MAC_L3_L4_CONTROL3_L4SPIM3_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL3_L4SPIM3(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_L4SPIM3_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_L4SPIM3_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_L4DPM3_MASK      (0x100000U)
#define GMAC_MAC_L3_L4_CONTROL3_L4DPM3_SHIFT     (20U)
#define GMAC_MAC_L3_L4_CONTROL3_L4DPM3_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL3_L4DPM3(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_L4DPM3_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_L4DPM3_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_L4DPIM3_MASK     (0x200000U)
#define GMAC_MAC_L3_L4_CONTROL3_L4DPIM3_SHIFT    (21U)
#define GMAC_MAC_L3_L4_CONTROL3_L4DPIM3_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL3_L4DPIM3(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_L4DPIM3_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_L4DPIM3_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_Reserved_23_22_MASK (0xC00000U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_23_22_SHIFT (22U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_23_22_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_23_22(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_Reserved_23_22_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_Reserved_23_22_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_DMCHN3_MASK      (0x3000000U)
#define GMAC_MAC_L3_L4_CONTROL3_DMCHN3_SHIFT     (24U)
#define GMAC_MAC_L3_L4_CONTROL3_DMCHN3_WIDTH     (2U)
#define GMAC_MAC_L3_L4_CONTROL3_DMCHN3(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_DMCHN3_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_DMCHN3_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_Reserved_27_y_MASK (0xC000000U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_27_y_SHIFT (26U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_27_y_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_27_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_Reserved_27_y_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_Reserved_27_y_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_DMCHEN3_MASK     (0x10000000U)
#define GMAC_MAC_L3_L4_CONTROL3_DMCHEN3_SHIFT    (28U)
#define GMAC_MAC_L3_L4_CONTROL3_DMCHEN3_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL3_DMCHEN3(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_DMCHEN3_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_DMCHEN3_MASK)

#define GMAC_MAC_L3_L4_CONTROL3_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_31_29_SHIFT (29U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_31_29_WIDTH (3U)
#define GMAC_MAC_L3_L4_CONTROL3_Reserved_31_29(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL3_Reserved_31_29_SHIFT)) & GMAC_MAC_L3_L4_CONTROL3_Reserved_31_29_MASK)
/*! @} */

/*! @name MAC_LAYER4_ADDRESS3 -  */
/*! @{ */

#define GMAC_MAC_LAYER4_ADDRESS3_L4SP3_MASK      (0xFFFFU)
#define GMAC_MAC_LAYER4_ADDRESS3_L4SP3_SHIFT     (0U)
#define GMAC_MAC_LAYER4_ADDRESS3_L4SP3_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS3_L4SP3(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS3_L4SP3_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS3_L4SP3_MASK)

#define GMAC_MAC_LAYER4_ADDRESS3_L4DP3_MASK      (0xFFFF0000U)
#define GMAC_MAC_LAYER4_ADDRESS3_L4DP3_SHIFT     (16U)
#define GMAC_MAC_LAYER4_ADDRESS3_L4DP3_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS3_L4DP3(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS3_L4DP3_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS3_L4DP3_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR0_REG3 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR0_REG3_L3A03_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR0_REG3_L3A03_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR0_REG3_L3A03_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR0_REG3_L3A03(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR0_REG3_L3A03_SHIFT)) & GMAC_MAC_LAYER3_ADDR0_REG3_L3A03_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR1_REG3 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR1_REG3_L3A13_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR1_REG3_L3A13_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR1_REG3_L3A13_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR1_REG3_L3A13(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR1_REG3_L3A13_SHIFT)) & GMAC_MAC_LAYER3_ADDR1_REG3_L3A13_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR2_REG3 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR2_REG3_L3A23_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR2_REG3_L3A23_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR2_REG3_L3A23_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR2_REG3_L3A23(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR2_REG3_L3A23_SHIFT)) & GMAC_MAC_LAYER3_ADDR2_REG3_L3A23_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR3_REG3 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR3_REG3_L3A33_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR3_REG3_L3A33_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR3_REG3_L3A33_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR3_REG3_L3A33(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR3_REG3_L3A33_SHIFT)) & GMAC_MAC_LAYER3_ADDR3_REG3_L3A33_MASK)
/*! @} */

/*! @name MAC_L3_L4_CONTROL4 -  */
/*! @{ */

#define GMAC_MAC_L3_L4_CONTROL4_L3PEN4_MASK      (0x1U)
#define GMAC_MAC_L3_L4_CONTROL4_L3PEN4_SHIFT     (0U)
#define GMAC_MAC_L3_L4_CONTROL4_L3PEN4_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL4_L3PEN4(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_L3PEN4_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_L3PEN4_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_Reserved_1_MASK  (0x2U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_1_SHIFT (1U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_1_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_1(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_Reserved_1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_Reserved_1_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_L3SAM4_MASK      (0x4U)
#define GMAC_MAC_L3_L4_CONTROL4_L3SAM4_SHIFT     (2U)
#define GMAC_MAC_L3_L4_CONTROL4_L3SAM4_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL4_L3SAM4(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_L3SAM4_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_L3SAM4_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_L3SAIM4_MASK     (0x8U)
#define GMAC_MAC_L3_L4_CONTROL4_L3SAIM4_SHIFT    (3U)
#define GMAC_MAC_L3_L4_CONTROL4_L3SAIM4_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL4_L3SAIM4(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_L3SAIM4_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_L3SAIM4_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_L3DAM4_MASK      (0x10U)
#define GMAC_MAC_L3_L4_CONTROL4_L3DAM4_SHIFT     (4U)
#define GMAC_MAC_L3_L4_CONTROL4_L3DAM4_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL4_L3DAM4(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_L3DAM4_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_L3DAM4_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_L3DAIM4_MASK     (0x20U)
#define GMAC_MAC_L3_L4_CONTROL4_L3DAIM4_SHIFT    (5U)
#define GMAC_MAC_L3_L4_CONTROL4_L3DAIM4_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL4_L3DAIM4(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_L3DAIM4_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_L3DAIM4_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_L3HSBM4_MASK     (0x7C0U)
#define GMAC_MAC_L3_L4_CONTROL4_L3HSBM4_SHIFT    (6U)
#define GMAC_MAC_L3_L4_CONTROL4_L3HSBM4_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL4_L3HSBM4(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_L3HSBM4_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_L3HSBM4_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_L3HDBM4_MASK     (0xF800U)
#define GMAC_MAC_L3_L4_CONTROL4_L3HDBM4_SHIFT    (11U)
#define GMAC_MAC_L3_L4_CONTROL4_L3HDBM4_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL4_L3HDBM4(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_L3HDBM4_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_L3HDBM4_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_L4PEN4_MASK      (0x10000U)
#define GMAC_MAC_L3_L4_CONTROL4_L4PEN4_SHIFT     (16U)
#define GMAC_MAC_L3_L4_CONTROL4_L4PEN4_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL4_L4PEN4(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_L4PEN4_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_L4PEN4_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_Reserved_17_MASK (0x20000U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_17_SHIFT (17U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_17_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_17(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_Reserved_17_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_Reserved_17_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_L4SPM4_MASK      (0x40000U)
#define GMAC_MAC_L3_L4_CONTROL4_L4SPM4_SHIFT     (18U)
#define GMAC_MAC_L3_L4_CONTROL4_L4SPM4_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL4_L4SPM4(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_L4SPM4_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_L4SPM4_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_L4SPIM4_MASK     (0x80000U)
#define GMAC_MAC_L3_L4_CONTROL4_L4SPIM4_SHIFT    (19U)
#define GMAC_MAC_L3_L4_CONTROL4_L4SPIM4_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL4_L4SPIM4(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_L4SPIM4_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_L4SPIM4_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_L4DPM4_MASK      (0x100000U)
#define GMAC_MAC_L3_L4_CONTROL4_L4DPM4_SHIFT     (20U)
#define GMAC_MAC_L3_L4_CONTROL4_L4DPM4_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL4_L4DPM4(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_L4DPM4_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_L4DPM4_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_L4DPIM4_MASK     (0x200000U)
#define GMAC_MAC_L3_L4_CONTROL4_L4DPIM4_SHIFT    (21U)
#define GMAC_MAC_L3_L4_CONTROL4_L4DPIM4_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL4_L4DPIM4(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_L4DPIM4_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_L4DPIM4_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_Reserved_23_22_MASK (0xC00000U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_23_22_SHIFT (22U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_23_22_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_23_22(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_Reserved_23_22_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_Reserved_23_22_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_DMCHN4_MASK      (0x3000000U)
#define GMAC_MAC_L3_L4_CONTROL4_DMCHN4_SHIFT     (24U)
#define GMAC_MAC_L3_L4_CONTROL4_DMCHN4_WIDTH     (2U)
#define GMAC_MAC_L3_L4_CONTROL4_DMCHN4(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_DMCHN4_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_DMCHN4_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_Reserved_27_y_MASK (0xC000000U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_27_y_SHIFT (26U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_27_y_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_27_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_Reserved_27_y_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_Reserved_27_y_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_DMCHEN4_MASK     (0x10000000U)
#define GMAC_MAC_L3_L4_CONTROL4_DMCHEN4_SHIFT    (28U)
#define GMAC_MAC_L3_L4_CONTROL4_DMCHEN4_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL4_DMCHEN4(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_DMCHEN4_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_DMCHEN4_MASK)

#define GMAC_MAC_L3_L4_CONTROL4_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_31_29_SHIFT (29U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_31_29_WIDTH (3U)
#define GMAC_MAC_L3_L4_CONTROL4_Reserved_31_29(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL4_Reserved_31_29_SHIFT)) & GMAC_MAC_L3_L4_CONTROL4_Reserved_31_29_MASK)
/*! @} */

/*! @name MAC_LAYER4_ADDRESS4 -  */
/*! @{ */

#define GMAC_MAC_LAYER4_ADDRESS4_L4SP4_MASK      (0xFFFFU)
#define GMAC_MAC_LAYER4_ADDRESS4_L4SP4_SHIFT     (0U)
#define GMAC_MAC_LAYER4_ADDRESS4_L4SP4_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS4_L4SP4(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS4_L4SP4_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS4_L4SP4_MASK)

#define GMAC_MAC_LAYER4_ADDRESS4_L4DP4_MASK      (0xFFFF0000U)
#define GMAC_MAC_LAYER4_ADDRESS4_L4DP4_SHIFT     (16U)
#define GMAC_MAC_LAYER4_ADDRESS4_L4DP4_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS4_L4DP4(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS4_L4DP4_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS4_L4DP4_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR0_REG4 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR0_REG4_L3A04_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR0_REG4_L3A04_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR0_REG4_L3A04_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR0_REG4_L3A04(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR0_REG4_L3A04_SHIFT)) & GMAC_MAC_LAYER3_ADDR0_REG4_L3A04_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR1_REG4 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR1_REG4_L3A14_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR1_REG4_L3A14_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR1_REG4_L3A14_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR1_REG4_L3A14(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR1_REG4_L3A14_SHIFT)) & GMAC_MAC_LAYER3_ADDR1_REG4_L3A14_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR2_REG4 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR2_REG4_L3A24_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR2_REG4_L3A24_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR2_REG4_L3A24_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR2_REG4_L3A24(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR2_REG4_L3A24_SHIFT)) & GMAC_MAC_LAYER3_ADDR2_REG4_L3A24_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR3_REG4 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR3_REG4_L3A34_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR3_REG4_L3A34_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR3_REG4_L3A34_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR3_REG4_L3A34(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR3_REG4_L3A34_SHIFT)) & GMAC_MAC_LAYER3_ADDR3_REG4_L3A34_MASK)
/*! @} */

/*! @name MAC_L3_L4_CONTROL5 -  */
/*! @{ */

#define GMAC_MAC_L3_L4_CONTROL5_L3PEN5_MASK      (0x1U)
#define GMAC_MAC_L3_L4_CONTROL5_L3PEN5_SHIFT     (0U)
#define GMAC_MAC_L3_L4_CONTROL5_L3PEN5_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL5_L3PEN5(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_L3PEN5_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_L3PEN5_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_Reserved_1_MASK  (0x2U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_1_SHIFT (1U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_1_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_1(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_Reserved_1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_Reserved_1_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_L3SAM5_MASK      (0x4U)
#define GMAC_MAC_L3_L4_CONTROL5_L3SAM5_SHIFT     (2U)
#define GMAC_MAC_L3_L4_CONTROL5_L3SAM5_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL5_L3SAM5(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_L3SAM5_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_L3SAM5_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_L3SAIM5_MASK     (0x8U)
#define GMAC_MAC_L3_L4_CONTROL5_L3SAIM5_SHIFT    (3U)
#define GMAC_MAC_L3_L4_CONTROL5_L3SAIM5_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL5_L3SAIM5(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_L3SAIM5_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_L3SAIM5_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_L3DAM5_MASK      (0x10U)
#define GMAC_MAC_L3_L4_CONTROL5_L3DAM5_SHIFT     (4U)
#define GMAC_MAC_L3_L4_CONTROL5_L3DAM5_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL5_L3DAM5(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_L3DAM5_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_L3DAM5_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_L3DAIM5_MASK     (0x20U)
#define GMAC_MAC_L3_L4_CONTROL5_L3DAIM5_SHIFT    (5U)
#define GMAC_MAC_L3_L4_CONTROL5_L3DAIM5_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL5_L3DAIM5(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_L3DAIM5_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_L3DAIM5_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_L3HSBM5_MASK     (0x7C0U)
#define GMAC_MAC_L3_L4_CONTROL5_L3HSBM5_SHIFT    (6U)
#define GMAC_MAC_L3_L4_CONTROL5_L3HSBM5_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL5_L3HSBM5(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_L3HSBM5_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_L3HSBM5_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_L3HDBM5_MASK     (0xF800U)
#define GMAC_MAC_L3_L4_CONTROL5_L3HDBM5_SHIFT    (11U)
#define GMAC_MAC_L3_L4_CONTROL5_L3HDBM5_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL5_L3HDBM5(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_L3HDBM5_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_L3HDBM5_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_L4PEN5_MASK      (0x10000U)
#define GMAC_MAC_L3_L4_CONTROL5_L4PEN5_SHIFT     (16U)
#define GMAC_MAC_L3_L4_CONTROL5_L4PEN5_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL5_L4PEN5(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_L4PEN5_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_L4PEN5_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_Reserved_17_MASK (0x20000U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_17_SHIFT (17U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_17_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_17(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_Reserved_17_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_Reserved_17_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_L4SPM5_MASK      (0x40000U)
#define GMAC_MAC_L3_L4_CONTROL5_L4SPM5_SHIFT     (18U)
#define GMAC_MAC_L3_L4_CONTROL5_L4SPM5_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL5_L4SPM5(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_L4SPM5_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_L4SPM5_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_L4SPIM5_MASK     (0x80000U)
#define GMAC_MAC_L3_L4_CONTROL5_L4SPIM5_SHIFT    (19U)
#define GMAC_MAC_L3_L4_CONTROL5_L4SPIM5_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL5_L4SPIM5(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_L4SPIM5_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_L4SPIM5_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_L4DPM5_MASK      (0x100000U)
#define GMAC_MAC_L3_L4_CONTROL5_L4DPM5_SHIFT     (20U)
#define GMAC_MAC_L3_L4_CONTROL5_L4DPM5_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL5_L4DPM5(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_L4DPM5_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_L4DPM5_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_L4DPIM5_MASK     (0x200000U)
#define GMAC_MAC_L3_L4_CONTROL5_L4DPIM5_SHIFT    (21U)
#define GMAC_MAC_L3_L4_CONTROL5_L4DPIM5_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL5_L4DPIM5(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_L4DPIM5_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_L4DPIM5_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_Reserved_23_22_MASK (0xC00000U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_23_22_SHIFT (22U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_23_22_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_23_22(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_Reserved_23_22_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_Reserved_23_22_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_DMCHN5_MASK      (0x3000000U)
#define GMAC_MAC_L3_L4_CONTROL5_DMCHN5_SHIFT     (24U)
#define GMAC_MAC_L3_L4_CONTROL5_DMCHN5_WIDTH     (2U)
#define GMAC_MAC_L3_L4_CONTROL5_DMCHN5(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_DMCHN5_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_DMCHN5_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_Reserved_27_y_MASK (0xC000000U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_27_y_SHIFT (26U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_27_y_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_27_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_Reserved_27_y_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_Reserved_27_y_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_DMCHEN5_MASK     (0x10000000U)
#define GMAC_MAC_L3_L4_CONTROL5_DMCHEN5_SHIFT    (28U)
#define GMAC_MAC_L3_L4_CONTROL5_DMCHEN5_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL5_DMCHEN5(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_DMCHEN5_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_DMCHEN5_MASK)

#define GMAC_MAC_L3_L4_CONTROL5_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_31_29_SHIFT (29U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_31_29_WIDTH (3U)
#define GMAC_MAC_L3_L4_CONTROL5_Reserved_31_29(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL5_Reserved_31_29_SHIFT)) & GMAC_MAC_L3_L4_CONTROL5_Reserved_31_29_MASK)
/*! @} */

/*! @name MAC_LAYER4_ADDRESS5 -  */
/*! @{ */

#define GMAC_MAC_LAYER4_ADDRESS5_L4SP5_MASK      (0xFFFFU)
#define GMAC_MAC_LAYER4_ADDRESS5_L4SP5_SHIFT     (0U)
#define GMAC_MAC_LAYER4_ADDRESS5_L4SP5_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS5_L4SP5(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS5_L4SP5_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS5_L4SP5_MASK)

#define GMAC_MAC_LAYER4_ADDRESS5_L4DP5_MASK      (0xFFFF0000U)
#define GMAC_MAC_LAYER4_ADDRESS5_L4DP5_SHIFT     (16U)
#define GMAC_MAC_LAYER4_ADDRESS5_L4DP5_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS5_L4DP5(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS5_L4DP5_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS5_L4DP5_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR0_REG5 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR0_REG5_L3A05_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR0_REG5_L3A05_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR0_REG5_L3A05_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR0_REG5_L3A05(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR0_REG5_L3A05_SHIFT)) & GMAC_MAC_LAYER3_ADDR0_REG5_L3A05_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR1_REG5 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR1_REG5_L3A15_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR1_REG5_L3A15_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR1_REG5_L3A15_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR1_REG5_L3A15(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR1_REG5_L3A15_SHIFT)) & GMAC_MAC_LAYER3_ADDR1_REG5_L3A15_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR2_REG5 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR2_REG5_L3A25_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR2_REG5_L3A25_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR2_REG5_L3A25_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR2_REG5_L3A25(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR2_REG5_L3A25_SHIFT)) & GMAC_MAC_LAYER3_ADDR2_REG5_L3A25_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR3_REG5 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR3_REG5_L3A35_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR3_REG5_L3A35_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR3_REG5_L3A35_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR3_REG5_L3A35(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR3_REG5_L3A35_SHIFT)) & GMAC_MAC_LAYER3_ADDR3_REG5_L3A35_MASK)
/*! @} */

/*! @name MAC_L3_L4_CONTROL6 -  */
/*! @{ */

#define GMAC_MAC_L3_L4_CONTROL6_L3PEN6_MASK      (0x1U)
#define GMAC_MAC_L3_L4_CONTROL6_L3PEN6_SHIFT     (0U)
#define GMAC_MAC_L3_L4_CONTROL6_L3PEN6_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL6_L3PEN6(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_L3PEN6_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_L3PEN6_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_Reserved_1_MASK  (0x2U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_1_SHIFT (1U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_1_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_1(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_Reserved_1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_Reserved_1_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_L3SAM6_MASK      (0x4U)
#define GMAC_MAC_L3_L4_CONTROL6_L3SAM6_SHIFT     (2U)
#define GMAC_MAC_L3_L4_CONTROL6_L3SAM6_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL6_L3SAM6(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_L3SAM6_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_L3SAM6_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_L3SAIM6_MASK     (0x8U)
#define GMAC_MAC_L3_L4_CONTROL6_L3SAIM6_SHIFT    (3U)
#define GMAC_MAC_L3_L4_CONTROL6_L3SAIM6_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL6_L3SAIM6(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_L3SAIM6_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_L3SAIM6_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_L3DAM6_MASK      (0x10U)
#define GMAC_MAC_L3_L4_CONTROL6_L3DAM6_SHIFT     (4U)
#define GMAC_MAC_L3_L4_CONTROL6_L3DAM6_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL6_L3DAM6(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_L3DAM6_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_L3DAM6_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_L3DAIM6_MASK     (0x20U)
#define GMAC_MAC_L3_L4_CONTROL6_L3DAIM6_SHIFT    (5U)
#define GMAC_MAC_L3_L4_CONTROL6_L3DAIM6_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL6_L3DAIM6(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_L3DAIM6_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_L3DAIM6_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_L3HSBM6_MASK     (0x7C0U)
#define GMAC_MAC_L3_L4_CONTROL6_L3HSBM6_SHIFT    (6U)
#define GMAC_MAC_L3_L4_CONTROL6_L3HSBM6_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL6_L3HSBM6(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_L3HSBM6_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_L3HSBM6_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_L3HDBM6_MASK     (0xF800U)
#define GMAC_MAC_L3_L4_CONTROL6_L3HDBM6_SHIFT    (11U)
#define GMAC_MAC_L3_L4_CONTROL6_L3HDBM6_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL6_L3HDBM6(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_L3HDBM6_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_L3HDBM6_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_L4PEN6_MASK      (0x10000U)
#define GMAC_MAC_L3_L4_CONTROL6_L4PEN6_SHIFT     (16U)
#define GMAC_MAC_L3_L4_CONTROL6_L4PEN6_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL6_L4PEN6(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_L4PEN6_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_L4PEN6_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_Reserved_17_MASK (0x20000U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_17_SHIFT (17U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_17_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_17(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_Reserved_17_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_Reserved_17_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_L4SPM6_MASK      (0x40000U)
#define GMAC_MAC_L3_L4_CONTROL6_L4SPM6_SHIFT     (18U)
#define GMAC_MAC_L3_L4_CONTROL6_L4SPM6_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL6_L4SPM6(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_L4SPM6_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_L4SPM6_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_L4SPIM6_MASK     (0x80000U)
#define GMAC_MAC_L3_L4_CONTROL6_L4SPIM6_SHIFT    (19U)
#define GMAC_MAC_L3_L4_CONTROL6_L4SPIM6_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL6_L4SPIM6(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_L4SPIM6_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_L4SPIM6_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_L4DPM6_MASK      (0x100000U)
#define GMAC_MAC_L3_L4_CONTROL6_L4DPM6_SHIFT     (20U)
#define GMAC_MAC_L3_L4_CONTROL6_L4DPM6_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL6_L4DPM6(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_L4DPM6_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_L4DPM6_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_L4DPIM6_MASK     (0x200000U)
#define GMAC_MAC_L3_L4_CONTROL6_L4DPIM6_SHIFT    (21U)
#define GMAC_MAC_L3_L4_CONTROL6_L4DPIM6_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL6_L4DPIM6(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_L4DPIM6_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_L4DPIM6_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_Reserved_23_22_MASK (0xC00000U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_23_22_SHIFT (22U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_23_22_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_23_22(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_Reserved_23_22_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_Reserved_23_22_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_DMCHN6_MASK      (0x3000000U)
#define GMAC_MAC_L3_L4_CONTROL6_DMCHN6_SHIFT     (24U)
#define GMAC_MAC_L3_L4_CONTROL6_DMCHN6_WIDTH     (2U)
#define GMAC_MAC_L3_L4_CONTROL6_DMCHN6(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_DMCHN6_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_DMCHN6_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_Reserved_27_y_MASK (0xC000000U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_27_y_SHIFT (26U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_27_y_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_27_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_Reserved_27_y_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_Reserved_27_y_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_DMCHEN6_MASK     (0x10000000U)
#define GMAC_MAC_L3_L4_CONTROL6_DMCHEN6_SHIFT    (28U)
#define GMAC_MAC_L3_L4_CONTROL6_DMCHEN6_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL6_DMCHEN6(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_DMCHEN6_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_DMCHEN6_MASK)

#define GMAC_MAC_L3_L4_CONTROL6_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_31_29_SHIFT (29U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_31_29_WIDTH (3U)
#define GMAC_MAC_L3_L4_CONTROL6_Reserved_31_29(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL6_Reserved_31_29_SHIFT)) & GMAC_MAC_L3_L4_CONTROL6_Reserved_31_29_MASK)
/*! @} */

/*! @name MAC_LAYER4_ADDRESS6 -  */
/*! @{ */

#define GMAC_MAC_LAYER4_ADDRESS6_L4SP6_MASK      (0xFFFFU)
#define GMAC_MAC_LAYER4_ADDRESS6_L4SP6_SHIFT     (0U)
#define GMAC_MAC_LAYER4_ADDRESS6_L4SP6_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS6_L4SP6(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS6_L4SP6_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS6_L4SP6_MASK)

#define GMAC_MAC_LAYER4_ADDRESS6_L4DP6_MASK      (0xFFFF0000U)
#define GMAC_MAC_LAYER4_ADDRESS6_L4DP6_SHIFT     (16U)
#define GMAC_MAC_LAYER4_ADDRESS6_L4DP6_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS6_L4DP6(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS6_L4DP6_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS6_L4DP6_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR0_REG6 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR0_REG6_L3A06_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR0_REG6_L3A06_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR0_REG6_L3A06_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR0_REG6_L3A06(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR0_REG6_L3A06_SHIFT)) & GMAC_MAC_LAYER3_ADDR0_REG6_L3A06_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR1_REG6 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR1_REG6_L3A16_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR1_REG6_L3A16_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR1_REG6_L3A16_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR1_REG6_L3A16(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR1_REG6_L3A16_SHIFT)) & GMAC_MAC_LAYER3_ADDR1_REG6_L3A16_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR2_REG6 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR2_REG6_L3A26_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR2_REG6_L3A26_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR2_REG6_L3A26_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR2_REG6_L3A26(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR2_REG6_L3A26_SHIFT)) & GMAC_MAC_LAYER3_ADDR2_REG6_L3A26_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR3_REG6 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR3_REG6_L3A36_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR3_REG6_L3A36_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR3_REG6_L3A36_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR3_REG6_L3A36(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR3_REG6_L3A36_SHIFT)) & GMAC_MAC_LAYER3_ADDR3_REG6_L3A36_MASK)
/*! @} */

/*! @name MAC_L3_L4_CONTROL7 -  */
/*! @{ */

#define GMAC_MAC_L3_L4_CONTROL7_L3PEN7_MASK      (0x1U)
#define GMAC_MAC_L3_L4_CONTROL7_L3PEN7_SHIFT     (0U)
#define GMAC_MAC_L3_L4_CONTROL7_L3PEN7_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL7_L3PEN7(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_L3PEN7_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_L3PEN7_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_Reserved_1_MASK  (0x2U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_1_SHIFT (1U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_1_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_1(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_Reserved_1_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_Reserved_1_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_L3SAM7_MASK      (0x4U)
#define GMAC_MAC_L3_L4_CONTROL7_L3SAM7_SHIFT     (2U)
#define GMAC_MAC_L3_L4_CONTROL7_L3SAM7_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL7_L3SAM7(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_L3SAM7_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_L3SAM7_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_L3SAIM7_MASK     (0x8U)
#define GMAC_MAC_L3_L4_CONTROL7_L3SAIM7_SHIFT    (3U)
#define GMAC_MAC_L3_L4_CONTROL7_L3SAIM7_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL7_L3SAIM7(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_L3SAIM7_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_L3SAIM7_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_L3DAM7_MASK      (0x10U)
#define GMAC_MAC_L3_L4_CONTROL7_L3DAM7_SHIFT     (4U)
#define GMAC_MAC_L3_L4_CONTROL7_L3DAM7_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL7_L3DAM7(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_L3DAM7_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_L3DAM7_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_L3DAIM7_MASK     (0x20U)
#define GMAC_MAC_L3_L4_CONTROL7_L3DAIM7_SHIFT    (5U)
#define GMAC_MAC_L3_L4_CONTROL7_L3DAIM7_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL7_L3DAIM7(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_L3DAIM7_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_L3DAIM7_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_L3HSBM7_MASK     (0x7C0U)
#define GMAC_MAC_L3_L4_CONTROL7_L3HSBM7_SHIFT    (6U)
#define GMAC_MAC_L3_L4_CONTROL7_L3HSBM7_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL7_L3HSBM7(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_L3HSBM7_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_L3HSBM7_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_L3HDBM7_MASK     (0xF800U)
#define GMAC_MAC_L3_L4_CONTROL7_L3HDBM7_SHIFT    (11U)
#define GMAC_MAC_L3_L4_CONTROL7_L3HDBM7_WIDTH    (5U)
#define GMAC_MAC_L3_L4_CONTROL7_L3HDBM7(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_L3HDBM7_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_L3HDBM7_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_L4PEN7_MASK      (0x10000U)
#define GMAC_MAC_L3_L4_CONTROL7_L4PEN7_SHIFT     (16U)
#define GMAC_MAC_L3_L4_CONTROL7_L4PEN7_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL7_L4PEN7(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_L4PEN7_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_L4PEN7_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_Reserved_17_MASK (0x20000U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_17_SHIFT (17U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_17_WIDTH (1U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_17(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_Reserved_17_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_Reserved_17_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_L4SPM7_MASK      (0x40000U)
#define GMAC_MAC_L3_L4_CONTROL7_L4SPM7_SHIFT     (18U)
#define GMAC_MAC_L3_L4_CONTROL7_L4SPM7_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL7_L4SPM7(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_L4SPM7_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_L4SPM7_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_L4SPIM7_MASK     (0x80000U)
#define GMAC_MAC_L3_L4_CONTROL7_L4SPIM7_SHIFT    (19U)
#define GMAC_MAC_L3_L4_CONTROL7_L4SPIM7_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL7_L4SPIM7(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_L4SPIM7_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_L4SPIM7_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_L4DPM7_MASK      (0x100000U)
#define GMAC_MAC_L3_L4_CONTROL7_L4DPM7_SHIFT     (20U)
#define GMAC_MAC_L3_L4_CONTROL7_L4DPM7_WIDTH     (1U)
#define GMAC_MAC_L3_L4_CONTROL7_L4DPM7(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_L4DPM7_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_L4DPM7_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_L4DPIM7_MASK     (0x200000U)
#define GMAC_MAC_L3_L4_CONTROL7_L4DPIM7_SHIFT    (21U)
#define GMAC_MAC_L3_L4_CONTROL7_L4DPIM7_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL7_L4DPIM7(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_L4DPIM7_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_L4DPIM7_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_Reserved_23_22_MASK (0xC00000U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_23_22_SHIFT (22U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_23_22_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_23_22(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_Reserved_23_22_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_Reserved_23_22_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_DMCHN7_MASK      (0x3000000U)
#define GMAC_MAC_L3_L4_CONTROL7_DMCHN7_SHIFT     (24U)
#define GMAC_MAC_L3_L4_CONTROL7_DMCHN7_WIDTH     (2U)
#define GMAC_MAC_L3_L4_CONTROL7_DMCHN7(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_DMCHN7_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_DMCHN7_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_Reserved_27_y_MASK (0xC000000U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_27_y_SHIFT (26U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_27_y_WIDTH (2U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_27_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_Reserved_27_y_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_Reserved_27_y_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_DMCHEN7_MASK     (0x10000000U)
#define GMAC_MAC_L3_L4_CONTROL7_DMCHEN7_SHIFT    (28U)
#define GMAC_MAC_L3_L4_CONTROL7_DMCHEN7_WIDTH    (1U)
#define GMAC_MAC_L3_L4_CONTROL7_DMCHEN7(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_DMCHEN7_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_DMCHEN7_MASK)

#define GMAC_MAC_L3_L4_CONTROL7_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_31_29_SHIFT (29U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_31_29_WIDTH (3U)
#define GMAC_MAC_L3_L4_CONTROL7_Reserved_31_29(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_L3_L4_CONTROL7_Reserved_31_29_SHIFT)) & GMAC_MAC_L3_L4_CONTROL7_Reserved_31_29_MASK)
/*! @} */

/*! @name MAC_LAYER4_ADDRESS7 -  */
/*! @{ */

#define GMAC_MAC_LAYER4_ADDRESS7_L4SP7_MASK      (0xFFFFU)
#define GMAC_MAC_LAYER4_ADDRESS7_L4SP7_SHIFT     (0U)
#define GMAC_MAC_LAYER4_ADDRESS7_L4SP7_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS7_L4SP7(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS7_L4SP7_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS7_L4SP7_MASK)

#define GMAC_MAC_LAYER4_ADDRESS7_L4DP7_MASK      (0xFFFF0000U)
#define GMAC_MAC_LAYER4_ADDRESS7_L4DP7_SHIFT     (16U)
#define GMAC_MAC_LAYER4_ADDRESS7_L4DP7_WIDTH     (16U)
#define GMAC_MAC_LAYER4_ADDRESS7_L4DP7(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER4_ADDRESS7_L4DP7_SHIFT)) & GMAC_MAC_LAYER4_ADDRESS7_L4DP7_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR0_REG7 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR0_REG7_L3A07_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR0_REG7_L3A07_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR0_REG7_L3A07_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR0_REG7_L3A07(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR0_REG7_L3A07_SHIFT)) & GMAC_MAC_LAYER3_ADDR0_REG7_L3A07_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR1_REG7 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR1_REG7_L3A17_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR1_REG7_L3A17_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR1_REG7_L3A17_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR1_REG7_L3A17(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR1_REG7_L3A17_SHIFT)) & GMAC_MAC_LAYER3_ADDR1_REG7_L3A17_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR2_REG7 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR2_REG7_L3A27_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR2_REG7_L3A27_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR2_REG7_L3A27_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR2_REG7_L3A27(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR2_REG7_L3A27_SHIFT)) & GMAC_MAC_LAYER3_ADDR2_REG7_L3A27_MASK)
/*! @} */

/*! @name MAC_LAYER3_ADDR3_REG7 -  */
/*! @{ */

#define GMAC_MAC_LAYER3_ADDR3_REG7_L3A37_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_LAYER3_ADDR3_REG7_L3A37_SHIFT   (0U)
#define GMAC_MAC_LAYER3_ADDR3_REG7_L3A37_WIDTH   (32U)
#define GMAC_MAC_LAYER3_ADDR3_REG7_L3A37(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_LAYER3_ADDR3_REG7_L3A37_SHIFT)) & GMAC_MAC_LAYER3_ADDR3_REG7_L3A37_MASK)
/*! @} */

/*! @name MAC_INDIR_ACCESS_CTRL -  */
/*! @{ */

#define GMAC_MAC_INDIR_ACCESS_CTRL_OB_MASK       (0x1U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_OB_SHIFT      (0U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_OB_WIDTH      (1U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_OB(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INDIR_ACCESS_CTRL_OB_SHIFT)) & GMAC_MAC_INDIR_ACCESS_CTRL_OB_MASK)

#define GMAC_MAC_INDIR_ACCESS_CTRL_COM_MASK      (0x2U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_COM_SHIFT     (1U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_COM_WIDTH     (1U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_COM(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INDIR_ACCESS_CTRL_COM_SHIFT)) & GMAC_MAC_INDIR_ACCESS_CTRL_COM_MASK)

#define GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_4_2_MASK (0x1CU)
#define GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_4_2_SHIFT (2U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_4_2_WIDTH (3U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_4_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_4_2_SHIFT)) & GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_4_2_MASK)

#define GMAC_MAC_INDIR_ACCESS_CTRL_AUTO_MASK     (0x20U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_AUTO_SHIFT    (5U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_AUTO_WIDTH    (1U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_AUTO(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INDIR_ACCESS_CTRL_AUTO_SHIFT)) & GMAC_MAC_INDIR_ACCESS_CTRL_AUTO_MASK)

#define GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_7_6_MASK (0xC0U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_7_6_SHIFT (6U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_7_6_WIDTH (2U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_7_6(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_7_6_SHIFT)) & GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_7_6_MASK)

#define GMAC_MAC_INDIR_ACCESS_CTRL_AOFF_MASK     (0xFF00U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_AOFF_SHIFT    (8U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_AOFF_WIDTH    (8U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_AOFF(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INDIR_ACCESS_CTRL_AOFF_SHIFT)) & GMAC_MAC_INDIR_ACCESS_CTRL_AOFF_MASK)

#define GMAC_MAC_INDIR_ACCESS_CTRL_MSEL_MASK     (0xF0000U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_MSEL_SHIFT    (16U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_MSEL_WIDTH    (4U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_MSEL(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INDIR_ACCESS_CTRL_MSEL_SHIFT)) & GMAC_MAC_INDIR_ACCESS_CTRL_MSEL_MASK)

#define GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_31_20_MASK (0xFFF00000U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_31_20_SHIFT (20U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_31_20_WIDTH (12U)
#define GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_31_20(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_31_20_SHIFT)) & GMAC_MAC_INDIR_ACCESS_CTRL_Reserved_31_20_MASK)
/*! @} */

/*! @name MAC_INDIR_ACCESS_DATA -  */
/*! @{ */

#define GMAC_MAC_INDIR_ACCESS_DATA_DATA_MASK     (0xFFFFFFFFU)
#define GMAC_MAC_INDIR_ACCESS_DATA_DATA_SHIFT    (0U)
#define GMAC_MAC_INDIR_ACCESS_DATA_DATA_WIDTH    (32U)
#define GMAC_MAC_INDIR_ACCESS_DATA_DATA(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_INDIR_ACCESS_DATA_DATA_SHIFT)) & GMAC_MAC_INDIR_ACCESS_DATA_DATA_MASK)
/*! @} */

/*! @name MAC_TMRQ_REGS0 -  */
/*! @{ */

#define GMAC_MAC_TMRQ_REGS0_TYP_MASK             (0xFFFFU)
#define GMAC_MAC_TMRQ_REGS0_TYP_SHIFT            (0U)
#define GMAC_MAC_TMRQ_REGS0_TYP_WIDTH            (16U)
#define GMAC_MAC_TMRQ_REGS0_TYP(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS0_TYP_SHIFT)) & GMAC_MAC_TMRQ_REGS0_TYP_MASK)

#define GMAC_MAC_TMRQ_REGS0_TMRQ_MASK            (0x70000U)
#define GMAC_MAC_TMRQ_REGS0_TMRQ_SHIFT           (16U)
#define GMAC_MAC_TMRQ_REGS0_TMRQ_WIDTH           (3U)
#define GMAC_MAC_TMRQ_REGS0_TMRQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS0_TMRQ_SHIFT)) & GMAC_MAC_TMRQ_REGS0_TMRQ_MASK)

#define GMAC_MAC_TMRQ_REGS0_Reserved_19_MASK     (0x80000U)
#define GMAC_MAC_TMRQ_REGS0_Reserved_19_SHIFT    (19U)
#define GMAC_MAC_TMRQ_REGS0_Reserved_19_WIDTH    (1U)
#define GMAC_MAC_TMRQ_REGS0_Reserved_19(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS0_Reserved_19_SHIFT)) & GMAC_MAC_TMRQ_REGS0_Reserved_19_MASK)

#define GMAC_MAC_TMRQ_REGS0_PFEX_MASK            (0x100000U)
#define GMAC_MAC_TMRQ_REGS0_PFEX_SHIFT           (20U)
#define GMAC_MAC_TMRQ_REGS0_PFEX_WIDTH           (1U)
#define GMAC_MAC_TMRQ_REGS0_PFEX(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS0_PFEX_SHIFT)) & GMAC_MAC_TMRQ_REGS0_PFEX_MASK)

#define GMAC_MAC_TMRQ_REGS0_Reserved_31_21_MASK  (0xFFE00000U)
#define GMAC_MAC_TMRQ_REGS0_Reserved_31_21_SHIFT (21U)
#define GMAC_MAC_TMRQ_REGS0_Reserved_31_21_WIDTH (11U)
#define GMAC_MAC_TMRQ_REGS0_Reserved_31_21(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS0_Reserved_31_21_SHIFT)) & GMAC_MAC_TMRQ_REGS0_Reserved_31_21_MASK)
/*! @} */

/*! @name MAC_TMRQ_REGS1 -  */
/*! @{ */

#define GMAC_MAC_TMRQ_REGS1_TYP_MASK             (0xFFFFU)
#define GMAC_MAC_TMRQ_REGS1_TYP_SHIFT            (0U)
#define GMAC_MAC_TMRQ_REGS1_TYP_WIDTH            (16U)
#define GMAC_MAC_TMRQ_REGS1_TYP(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS1_TYP_SHIFT)) & GMAC_MAC_TMRQ_REGS1_TYP_MASK)

#define GMAC_MAC_TMRQ_REGS1_TMRQ_MASK            (0x70000U)
#define GMAC_MAC_TMRQ_REGS1_TMRQ_SHIFT           (16U)
#define GMAC_MAC_TMRQ_REGS1_TMRQ_WIDTH           (3U)
#define GMAC_MAC_TMRQ_REGS1_TMRQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS1_TMRQ_SHIFT)) & GMAC_MAC_TMRQ_REGS1_TMRQ_MASK)

#define GMAC_MAC_TMRQ_REGS1_Reserved_19_MASK     (0x80000U)
#define GMAC_MAC_TMRQ_REGS1_Reserved_19_SHIFT    (19U)
#define GMAC_MAC_TMRQ_REGS1_Reserved_19_WIDTH    (1U)
#define GMAC_MAC_TMRQ_REGS1_Reserved_19(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS1_Reserved_19_SHIFT)) & GMAC_MAC_TMRQ_REGS1_Reserved_19_MASK)

#define GMAC_MAC_TMRQ_REGS1_PFEX_MASK            (0x100000U)
#define GMAC_MAC_TMRQ_REGS1_PFEX_SHIFT           (20U)
#define GMAC_MAC_TMRQ_REGS1_PFEX_WIDTH           (1U)
#define GMAC_MAC_TMRQ_REGS1_PFEX(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS1_PFEX_SHIFT)) & GMAC_MAC_TMRQ_REGS1_PFEX_MASK)

#define GMAC_MAC_TMRQ_REGS1_Reserved_31_21_MASK  (0xFFE00000U)
#define GMAC_MAC_TMRQ_REGS1_Reserved_31_21_SHIFT (21U)
#define GMAC_MAC_TMRQ_REGS1_Reserved_31_21_WIDTH (11U)
#define GMAC_MAC_TMRQ_REGS1_Reserved_31_21(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS1_Reserved_31_21_SHIFT)) & GMAC_MAC_TMRQ_REGS1_Reserved_31_21_MASK)
/*! @} */

/*! @name MAC_TMRQ_REGS2 -  */
/*! @{ */

#define GMAC_MAC_TMRQ_REGS2_TYP_MASK             (0xFFFFU)
#define GMAC_MAC_TMRQ_REGS2_TYP_SHIFT            (0U)
#define GMAC_MAC_TMRQ_REGS2_TYP_WIDTH            (16U)
#define GMAC_MAC_TMRQ_REGS2_TYP(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS2_TYP_SHIFT)) & GMAC_MAC_TMRQ_REGS2_TYP_MASK)

#define GMAC_MAC_TMRQ_REGS2_TMRQ_MASK            (0x70000U)
#define GMAC_MAC_TMRQ_REGS2_TMRQ_SHIFT           (16U)
#define GMAC_MAC_TMRQ_REGS2_TMRQ_WIDTH           (3U)
#define GMAC_MAC_TMRQ_REGS2_TMRQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS2_TMRQ_SHIFT)) & GMAC_MAC_TMRQ_REGS2_TMRQ_MASK)

#define GMAC_MAC_TMRQ_REGS2_Reserved_19_MASK     (0x80000U)
#define GMAC_MAC_TMRQ_REGS2_Reserved_19_SHIFT    (19U)
#define GMAC_MAC_TMRQ_REGS2_Reserved_19_WIDTH    (1U)
#define GMAC_MAC_TMRQ_REGS2_Reserved_19(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS2_Reserved_19_SHIFT)) & GMAC_MAC_TMRQ_REGS2_Reserved_19_MASK)

#define GMAC_MAC_TMRQ_REGS2_PFEX_MASK            (0x100000U)
#define GMAC_MAC_TMRQ_REGS2_PFEX_SHIFT           (20U)
#define GMAC_MAC_TMRQ_REGS2_PFEX_WIDTH           (1U)
#define GMAC_MAC_TMRQ_REGS2_PFEX(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS2_PFEX_SHIFT)) & GMAC_MAC_TMRQ_REGS2_PFEX_MASK)

#define GMAC_MAC_TMRQ_REGS2_Reserved_31_21_MASK  (0xFFE00000U)
#define GMAC_MAC_TMRQ_REGS2_Reserved_31_21_SHIFT (21U)
#define GMAC_MAC_TMRQ_REGS2_Reserved_31_21_WIDTH (11U)
#define GMAC_MAC_TMRQ_REGS2_Reserved_31_21(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS2_Reserved_31_21_SHIFT)) & GMAC_MAC_TMRQ_REGS2_Reserved_31_21_MASK)
/*! @} */

/*! @name MAC_TMRQ_REGS3 -  */
/*! @{ */

#define GMAC_MAC_TMRQ_REGS3_TYP_MASK             (0xFFFFU)
#define GMAC_MAC_TMRQ_REGS3_TYP_SHIFT            (0U)
#define GMAC_MAC_TMRQ_REGS3_TYP_WIDTH            (16U)
#define GMAC_MAC_TMRQ_REGS3_TYP(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS3_TYP_SHIFT)) & GMAC_MAC_TMRQ_REGS3_TYP_MASK)

#define GMAC_MAC_TMRQ_REGS3_TMRQ_MASK            (0x70000U)
#define GMAC_MAC_TMRQ_REGS3_TMRQ_SHIFT           (16U)
#define GMAC_MAC_TMRQ_REGS3_TMRQ_WIDTH           (3U)
#define GMAC_MAC_TMRQ_REGS3_TMRQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS3_TMRQ_SHIFT)) & GMAC_MAC_TMRQ_REGS3_TMRQ_MASK)

#define GMAC_MAC_TMRQ_REGS3_Reserved_19_MASK     (0x80000U)
#define GMAC_MAC_TMRQ_REGS3_Reserved_19_SHIFT    (19U)
#define GMAC_MAC_TMRQ_REGS3_Reserved_19_WIDTH    (1U)
#define GMAC_MAC_TMRQ_REGS3_Reserved_19(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS3_Reserved_19_SHIFT)) & GMAC_MAC_TMRQ_REGS3_Reserved_19_MASK)

#define GMAC_MAC_TMRQ_REGS3_PFEX_MASK            (0x100000U)
#define GMAC_MAC_TMRQ_REGS3_PFEX_SHIFT           (20U)
#define GMAC_MAC_TMRQ_REGS3_PFEX_WIDTH           (1U)
#define GMAC_MAC_TMRQ_REGS3_PFEX(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS3_PFEX_SHIFT)) & GMAC_MAC_TMRQ_REGS3_PFEX_MASK)

#define GMAC_MAC_TMRQ_REGS3_Reserved_31_21_MASK  (0xFFE00000U)
#define GMAC_MAC_TMRQ_REGS3_Reserved_31_21_SHIFT (21U)
#define GMAC_MAC_TMRQ_REGS3_Reserved_31_21_WIDTH (11U)
#define GMAC_MAC_TMRQ_REGS3_Reserved_31_21(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS3_Reserved_31_21_SHIFT)) & GMAC_MAC_TMRQ_REGS3_Reserved_31_21_MASK)
/*! @} */

/*! @name MAC_TMRQ_REGS4 -  */
/*! @{ */

#define GMAC_MAC_TMRQ_REGS4_TYP_MASK             (0xFFFFU)
#define GMAC_MAC_TMRQ_REGS4_TYP_SHIFT            (0U)
#define GMAC_MAC_TMRQ_REGS4_TYP_WIDTH            (16U)
#define GMAC_MAC_TMRQ_REGS4_TYP(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS4_TYP_SHIFT)) & GMAC_MAC_TMRQ_REGS4_TYP_MASK)

#define GMAC_MAC_TMRQ_REGS4_TMRQ_MASK            (0x70000U)
#define GMAC_MAC_TMRQ_REGS4_TMRQ_SHIFT           (16U)
#define GMAC_MAC_TMRQ_REGS4_TMRQ_WIDTH           (3U)
#define GMAC_MAC_TMRQ_REGS4_TMRQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS4_TMRQ_SHIFT)) & GMAC_MAC_TMRQ_REGS4_TMRQ_MASK)

#define GMAC_MAC_TMRQ_REGS4_Reserved_19_MASK     (0x80000U)
#define GMAC_MAC_TMRQ_REGS4_Reserved_19_SHIFT    (19U)
#define GMAC_MAC_TMRQ_REGS4_Reserved_19_WIDTH    (1U)
#define GMAC_MAC_TMRQ_REGS4_Reserved_19(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS4_Reserved_19_SHIFT)) & GMAC_MAC_TMRQ_REGS4_Reserved_19_MASK)

#define GMAC_MAC_TMRQ_REGS4_PFEX_MASK            (0x100000U)
#define GMAC_MAC_TMRQ_REGS4_PFEX_SHIFT           (20U)
#define GMAC_MAC_TMRQ_REGS4_PFEX_WIDTH           (1U)
#define GMAC_MAC_TMRQ_REGS4_PFEX(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS4_PFEX_SHIFT)) & GMAC_MAC_TMRQ_REGS4_PFEX_MASK)

#define GMAC_MAC_TMRQ_REGS4_Reserved_31_21_MASK  (0xFFE00000U)
#define GMAC_MAC_TMRQ_REGS4_Reserved_31_21_SHIFT (21U)
#define GMAC_MAC_TMRQ_REGS4_Reserved_31_21_WIDTH (11U)
#define GMAC_MAC_TMRQ_REGS4_Reserved_31_21(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS4_Reserved_31_21_SHIFT)) & GMAC_MAC_TMRQ_REGS4_Reserved_31_21_MASK)
/*! @} */

/*! @name MAC_TMRQ_REGS5 -  */
/*! @{ */

#define GMAC_MAC_TMRQ_REGS5_TYP_MASK             (0xFFFFU)
#define GMAC_MAC_TMRQ_REGS5_TYP_SHIFT            (0U)
#define GMAC_MAC_TMRQ_REGS5_TYP_WIDTH            (16U)
#define GMAC_MAC_TMRQ_REGS5_TYP(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS5_TYP_SHIFT)) & GMAC_MAC_TMRQ_REGS5_TYP_MASK)

#define GMAC_MAC_TMRQ_REGS5_TMRQ_MASK            (0x70000U)
#define GMAC_MAC_TMRQ_REGS5_TMRQ_SHIFT           (16U)
#define GMAC_MAC_TMRQ_REGS5_TMRQ_WIDTH           (3U)
#define GMAC_MAC_TMRQ_REGS5_TMRQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS5_TMRQ_SHIFT)) & GMAC_MAC_TMRQ_REGS5_TMRQ_MASK)

#define GMAC_MAC_TMRQ_REGS5_Reserved_19_MASK     (0x80000U)
#define GMAC_MAC_TMRQ_REGS5_Reserved_19_SHIFT    (19U)
#define GMAC_MAC_TMRQ_REGS5_Reserved_19_WIDTH    (1U)
#define GMAC_MAC_TMRQ_REGS5_Reserved_19(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS5_Reserved_19_SHIFT)) & GMAC_MAC_TMRQ_REGS5_Reserved_19_MASK)

#define GMAC_MAC_TMRQ_REGS5_PFEX_MASK            (0x100000U)
#define GMAC_MAC_TMRQ_REGS5_PFEX_SHIFT           (20U)
#define GMAC_MAC_TMRQ_REGS5_PFEX_WIDTH           (1U)
#define GMAC_MAC_TMRQ_REGS5_PFEX(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS5_PFEX_SHIFT)) & GMAC_MAC_TMRQ_REGS5_PFEX_MASK)

#define GMAC_MAC_TMRQ_REGS5_Reserved_31_21_MASK  (0xFFE00000U)
#define GMAC_MAC_TMRQ_REGS5_Reserved_31_21_SHIFT (21U)
#define GMAC_MAC_TMRQ_REGS5_Reserved_31_21_WIDTH (11U)
#define GMAC_MAC_TMRQ_REGS5_Reserved_31_21(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS5_Reserved_31_21_SHIFT)) & GMAC_MAC_TMRQ_REGS5_Reserved_31_21_MASK)
/*! @} */

/*! @name MAC_TMRQ_REGS6 -  */
/*! @{ */

#define GMAC_MAC_TMRQ_REGS6_TYP_MASK             (0xFFFFU)
#define GMAC_MAC_TMRQ_REGS6_TYP_SHIFT            (0U)
#define GMAC_MAC_TMRQ_REGS6_TYP_WIDTH            (16U)
#define GMAC_MAC_TMRQ_REGS6_TYP(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS6_TYP_SHIFT)) & GMAC_MAC_TMRQ_REGS6_TYP_MASK)

#define GMAC_MAC_TMRQ_REGS6_TMRQ_MASK            (0x70000U)
#define GMAC_MAC_TMRQ_REGS6_TMRQ_SHIFT           (16U)
#define GMAC_MAC_TMRQ_REGS6_TMRQ_WIDTH           (3U)
#define GMAC_MAC_TMRQ_REGS6_TMRQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS6_TMRQ_SHIFT)) & GMAC_MAC_TMRQ_REGS6_TMRQ_MASK)

#define GMAC_MAC_TMRQ_REGS6_Reserved_19_MASK     (0x80000U)
#define GMAC_MAC_TMRQ_REGS6_Reserved_19_SHIFT    (19U)
#define GMAC_MAC_TMRQ_REGS6_Reserved_19_WIDTH    (1U)
#define GMAC_MAC_TMRQ_REGS6_Reserved_19(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS6_Reserved_19_SHIFT)) & GMAC_MAC_TMRQ_REGS6_Reserved_19_MASK)

#define GMAC_MAC_TMRQ_REGS6_PFEX_MASK            (0x100000U)
#define GMAC_MAC_TMRQ_REGS6_PFEX_SHIFT           (20U)
#define GMAC_MAC_TMRQ_REGS6_PFEX_WIDTH           (1U)
#define GMAC_MAC_TMRQ_REGS6_PFEX(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS6_PFEX_SHIFT)) & GMAC_MAC_TMRQ_REGS6_PFEX_MASK)

#define GMAC_MAC_TMRQ_REGS6_Reserved_31_21_MASK  (0xFFE00000U)
#define GMAC_MAC_TMRQ_REGS6_Reserved_31_21_SHIFT (21U)
#define GMAC_MAC_TMRQ_REGS6_Reserved_31_21_WIDTH (11U)
#define GMAC_MAC_TMRQ_REGS6_Reserved_31_21(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS6_Reserved_31_21_SHIFT)) & GMAC_MAC_TMRQ_REGS6_Reserved_31_21_MASK)
/*! @} */

/*! @name MAC_TMRQ_REGS7 -  */
/*! @{ */

#define GMAC_MAC_TMRQ_REGS7_TYP_MASK             (0xFFFFU)
#define GMAC_MAC_TMRQ_REGS7_TYP_SHIFT            (0U)
#define GMAC_MAC_TMRQ_REGS7_TYP_WIDTH            (16U)
#define GMAC_MAC_TMRQ_REGS7_TYP(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS7_TYP_SHIFT)) & GMAC_MAC_TMRQ_REGS7_TYP_MASK)

#define GMAC_MAC_TMRQ_REGS7_TMRQ_MASK            (0x70000U)
#define GMAC_MAC_TMRQ_REGS7_TMRQ_SHIFT           (16U)
#define GMAC_MAC_TMRQ_REGS7_TMRQ_WIDTH           (3U)
#define GMAC_MAC_TMRQ_REGS7_TMRQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS7_TMRQ_SHIFT)) & GMAC_MAC_TMRQ_REGS7_TMRQ_MASK)

#define GMAC_MAC_TMRQ_REGS7_Reserved_19_MASK     (0x80000U)
#define GMAC_MAC_TMRQ_REGS7_Reserved_19_SHIFT    (19U)
#define GMAC_MAC_TMRQ_REGS7_Reserved_19_WIDTH    (1U)
#define GMAC_MAC_TMRQ_REGS7_Reserved_19(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS7_Reserved_19_SHIFT)) & GMAC_MAC_TMRQ_REGS7_Reserved_19_MASK)

#define GMAC_MAC_TMRQ_REGS7_PFEX_MASK            (0x100000U)
#define GMAC_MAC_TMRQ_REGS7_PFEX_SHIFT           (20U)
#define GMAC_MAC_TMRQ_REGS7_PFEX_WIDTH           (1U)
#define GMAC_MAC_TMRQ_REGS7_PFEX(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS7_PFEX_SHIFT)) & GMAC_MAC_TMRQ_REGS7_PFEX_MASK)

#define GMAC_MAC_TMRQ_REGS7_Reserved_31_21_MASK  (0xFFE00000U)
#define GMAC_MAC_TMRQ_REGS7_Reserved_31_21_SHIFT (21U)
#define GMAC_MAC_TMRQ_REGS7_Reserved_31_21_WIDTH (11U)
#define GMAC_MAC_TMRQ_REGS7_Reserved_31_21(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TMRQ_REGS7_Reserved_31_21_SHIFT)) & GMAC_MAC_TMRQ_REGS7_Reserved_31_21_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_CONTROL -  */
/*! @{ */

#define GMAC_MAC_TIMESTAMP_CONTROL_TSENA_MASK    (0x1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSENA_SHIFT   (0U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSENA_WIDTH   (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSENA(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TSENA_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TSENA_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_TSCFUPDT_MASK (0x2U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSCFUPDT_SHIFT (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSCFUPDT_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSCFUPDT(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TSCFUPDT_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TSCFUPDT_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_TSINIT_MASK   (0x4U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSINIT_SHIFT  (2U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSINIT_WIDTH  (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSINIT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TSINIT_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TSINIT_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_TSUPDT_MASK   (0x8U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSUPDT_SHIFT  (3U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSUPDT_WIDTH  (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSUPDT(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TSUPDT_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TSUPDT_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_TSTRIG_MASK (0x10U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_TSTRIG_SHIFT (4U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_TSTRIG_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_TSTRIG(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_Reserved_TSTRIG_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_Reserved_TSTRIG_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_TSADDREG_MASK (0x20U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSADDREG_SHIFT (5U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSADDREG_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSADDREG(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TSADDREG_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TSADDREG_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_PTGE_MASK     (0x40U)
#define GMAC_MAC_TIMESTAMP_CONTROL_PTGE_SHIFT    (6U)
#define GMAC_MAC_TIMESTAMP_CONTROL_PTGE_WIDTH    (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_PTGE(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_PTGE_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_PTGE_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_7_MASK (0x80U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_7_SHIFT (7U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_7_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_7(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_Reserved_7_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_Reserved_7_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_TSENALL_MASK  (0x100U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSENALL_SHIFT (8U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSENALL_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSENALL(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TSENALL_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TSENALL_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_MASK (0x200U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_SHIFT (9U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSCTRLSSR(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TSCTRLSSR_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_TSVER2ENA_MASK (0x400U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSVER2ENA_SHIFT (10U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSVER2ENA_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSVER2ENA(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TSVER2ENA_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TSVER2ENA_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_TSIPENA_MASK  (0x800U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSIPENA_SHIFT (11U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSIPENA_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSIPENA(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TSIPENA_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TSIPENA_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_MASK (0x1000U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_SHIFT (12U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSIPV6ENA(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TSIPV6ENA_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_MASK (0x2000U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_SHIFT (13U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSIPV4ENA(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TSIPV4ENA_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_TSEVNTENA_MASK (0x4000U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSEVNTENA_SHIFT (14U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSEVNTENA_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSEVNTENA(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TSEVNTENA_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TSEVNTENA_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_TSMSTRENA_MASK (0x8000U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSMSTRENA_SHIFT (15U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSMSTRENA_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSMSTRENA(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TSMSTRENA_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TSMSTRENA_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_MASK (0x30000U)
#define GMAC_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_SHIFT (16U)
#define GMAC_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_WIDTH (2U)
#define GMAC_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_SNAPTYPSEL_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_TSENMACADDR_MASK (0x40000U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSENMACADDR_SHIFT (18U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSENMACADDR_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TSENMACADDR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TSENMACADDR_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TSENMACADDR_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_CSC_MASK (0x80000U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_CSC_SHIFT (19U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_CSC_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_CSC(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_Reserved_CSC_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_Reserved_CSC_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_ESTI_MASK     (0x100000U)
#define GMAC_MAC_TIMESTAMP_CONTROL_ESTI_SHIFT    (20U)
#define GMAC_MAC_TIMESTAMP_CONTROL_ESTI_WIDTH    (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_ESTI(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_ESTI_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_ESTI_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_23_21_SHIFT (21U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_23_21_WIDTH (3U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_23_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_Reserved_23_21_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_Reserved_23_21_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_TXTSSTSM_MASK (0x1000000U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TXTSSTSM_SHIFT (24U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TXTSSTSM_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_TXTSSTSM(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_TXTSSTSM_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_TXTSSTSM_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_27_25_MASK (0xE000000U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_27_25_SHIFT (25U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_27_25_WIDTH (3U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_27_25(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_Reserved_27_25_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_Reserved_27_25_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_MASK (0x10000000U)
#define GMAC_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_SHIFT (28U)
#define GMAC_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_CONTROL_AV8021ASMEN(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_AV8021ASMEN_MASK)

#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_31_29_SHIFT (29U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_31_29_WIDTH (3U)
#define GMAC_MAC_TIMESTAMP_CONTROL_Reserved_31_29(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_CONTROL_Reserved_31_29_SHIFT)) & GMAC_MAC_TIMESTAMP_CONTROL_Reserved_31_29_MASK)
/*! @} */

/*! @name MAC_SUB_SECOND_INCREMENT -  */
/*! @{ */

#define GMAC_MAC_SUB_SECOND_INCREMENT_Reserved_7_0_MASK (0xFFU)
#define GMAC_MAC_SUB_SECOND_INCREMENT_Reserved_7_0_SHIFT (0U)
#define GMAC_MAC_SUB_SECOND_INCREMENT_Reserved_7_0_WIDTH (8U)
#define GMAC_MAC_SUB_SECOND_INCREMENT_Reserved_7_0(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_SUB_SECOND_INCREMENT_Reserved_7_0_SHIFT)) & GMAC_MAC_SUB_SECOND_INCREMENT_Reserved_7_0_MASK)

#define GMAC_MAC_SUB_SECOND_INCREMENT_SNSINC_MASK (0xFF00U)
#define GMAC_MAC_SUB_SECOND_INCREMENT_SNSINC_SHIFT (8U)
#define GMAC_MAC_SUB_SECOND_INCREMENT_SNSINC_WIDTH (8U)
#define GMAC_MAC_SUB_SECOND_INCREMENT_SNSINC(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_SUB_SECOND_INCREMENT_SNSINC_SHIFT)) & GMAC_MAC_SUB_SECOND_INCREMENT_SNSINC_MASK)

#define GMAC_MAC_SUB_SECOND_INCREMENT_SSINC_MASK (0xFF0000U)
#define GMAC_MAC_SUB_SECOND_INCREMENT_SSINC_SHIFT (16U)
#define GMAC_MAC_SUB_SECOND_INCREMENT_SSINC_WIDTH (8U)
#define GMAC_MAC_SUB_SECOND_INCREMENT_SSINC(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_SUB_SECOND_INCREMENT_SSINC_SHIFT)) & GMAC_MAC_SUB_SECOND_INCREMENT_SSINC_MASK)

#define GMAC_MAC_SUB_SECOND_INCREMENT_Reserved_31_24_MASK (0xFF000000U)
#define GMAC_MAC_SUB_SECOND_INCREMENT_Reserved_31_24_SHIFT (24U)
#define GMAC_MAC_SUB_SECOND_INCREMENT_Reserved_31_24_WIDTH (8U)
#define GMAC_MAC_SUB_SECOND_INCREMENT_Reserved_31_24(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_SUB_SECOND_INCREMENT_Reserved_31_24_SHIFT)) & GMAC_MAC_SUB_SECOND_INCREMENT_Reserved_31_24_MASK)
/*! @} */

/*! @name MAC_SYSTEM_TIME_SECONDS -  */
/*! @{ */

#define GMAC_MAC_SYSTEM_TIME_SECONDS_TSS_MASK    (0xFFFFFFFFU)
#define GMAC_MAC_SYSTEM_TIME_SECONDS_TSS_SHIFT   (0U)
#define GMAC_MAC_SYSTEM_TIME_SECONDS_TSS_WIDTH   (32U)
#define GMAC_MAC_SYSTEM_TIME_SECONDS_TSS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_SYSTEM_TIME_SECONDS_TSS_SHIFT)) & GMAC_MAC_SYSTEM_TIME_SECONDS_TSS_MASK)
/*! @} */

/*! @name MAC_SYSTEM_TIME_NANOSECONDS -  */
/*! @{ */

#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_MASK (0x7FFFFFFFU)
#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_SHIFT (0U)
#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_WIDTH (31U)
#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_TSSS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_SHIFT)) & GMAC_MAC_SYSTEM_TIME_NANOSECONDS_TSSS_MASK)

#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_Reserved_31_MASK (0x80000000U)
#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_Reserved_31_SHIFT (31U)
#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_Reserved_31_WIDTH (1U)
#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_Reserved_31(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_SYSTEM_TIME_NANOSECONDS_Reserved_31_SHIFT)) & GMAC_MAC_SYSTEM_TIME_NANOSECONDS_Reserved_31_MASK)
/*! @} */

/*! @name MAC_SYSTEM_TIME_SECONDS_UPDATE -  */
/*! @{ */

#define GMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_MASK (0xFFFFFFFFU)
#define GMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_SHIFT (0U)
#define GMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_WIDTH (32U)
#define GMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_SHIFT)) & GMAC_MAC_SYSTEM_TIME_SECONDS_UPDATE_TSS_MASK)
/*! @} */

/*! @name MAC_SYSTEM_TIME_NANOSECONDS_UPDATE -  */
/*! @{ */

#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_MASK (0x7FFFFFFFU)
#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_SHIFT (0U)
#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_WIDTH (31U)
#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_SHIFT)) & GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_TSSS_MASK)

#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_MASK (0x80000000U)
#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_SHIFT (31U)
#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_WIDTH (1U)
#define GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_SHIFT)) & GMAC_MAC_SYSTEM_TIME_NANOSECONDS_UPDATE_ADDSUB_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_ADDEND -  */
/*! @{ */

#define GMAC_MAC_TIMESTAMP_ADDEND_TSAR_MASK      (0xFFFFFFFFU)
#define GMAC_MAC_TIMESTAMP_ADDEND_TSAR_SHIFT     (0U)
#define GMAC_MAC_TIMESTAMP_ADDEND_TSAR_WIDTH     (32U)
#define GMAC_MAC_TIMESTAMP_ADDEND_TSAR(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_ADDEND_TSAR_SHIFT)) & GMAC_MAC_TIMESTAMP_ADDEND_TSAR_MASK)
/*! @} */

/*! @name MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS -  */
/*! @{ */

#define GMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_MASK (0xFFFFU)
#define GMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_SHIFT (0U)
#define GMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_WIDTH (16U)
#define GMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_SHIFT)) & GMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_TSHWR_MASK)

#define GMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_Reserved_31_16_MASK (0xFFFF0000U)
#define GMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_Reserved_31_16_SHIFT (16U)
#define GMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_Reserved_31_16_WIDTH (16U)
#define GMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_Reserved_31_16(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_Reserved_31_16_SHIFT)) & GMAC_MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS_Reserved_31_16_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_STATUS -  */
/*! @{ */

#define GMAC_MAC_TIMESTAMP_STATUS_TSSOVF_MASK    (0x1U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSSOVF_SHIFT   (0U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSSOVF_WIDTH   (1U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSSOVF(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_TSSOVF_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_TSSOVF_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT0_MASK  (0x2U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT0_SHIFT (1U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT0_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT0(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_TSTARGT0_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_TSTARGT0_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_AUXTSTRIG_MASK (0x4U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_AUXTSTRIG_SHIFT (2U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_AUXTSTRIG_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_AUXTSTRIG(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_Reserved_AUXTSTRIG_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_Reserved_AUXTSTRIG_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR0_MASK (0x8U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR0_SHIFT (3U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR0_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR0(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR0_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR0_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT1_MASK  (0x10U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT1_SHIFT (4U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT1_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT1(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_TSTARGT1_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_TSTARGT1_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR1_MASK (0x20U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR1_SHIFT (5U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR1_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR1(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR1_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR1_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT2_MASK  (0x40U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT2_SHIFT (6U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT2_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT2(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_TSTARGT2_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_TSTARGT2_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR2_MASK (0x80U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR2_SHIFT (7U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR2_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR2(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR2_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR2_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT3_MASK  (0x100U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT3_SHIFT (8U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT3_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTARGT3(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_TSTARGT3_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_TSTARGT3_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR3_MASK (0x200U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR3_SHIFT (9U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR3_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR3(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR3_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_TSTRGTERR3_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_14_10_MASK (0x7C00U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_14_10_SHIFT (10U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_14_10_WIDTH (5U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_14_10(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_Reserved_14_10_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_Reserved_14_10_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_TXTSSIS_MASK   (0x8000U)
#define GMAC_MAC_TIMESTAMP_STATUS_TXTSSIS_SHIFT  (15U)
#define GMAC_MAC_TIMESTAMP_STATUS_TXTSSIS_WIDTH  (1U)
#define GMAC_MAC_TIMESTAMP_STATUS_TXTSSIS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_TXTSSIS_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_TXTSSIS_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSSTN_MASK (0xF0000U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSSTN_SHIFT (16U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSSTN_WIDTH (4U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSSTN(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSSTN_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSSTN_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_23_20_MASK (0xF00000U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_23_20_SHIFT (20U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_23_20_WIDTH (4U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_23_20(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_Reserved_23_20_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_Reserved_23_20_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSSTM_MASK (0x1000000U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSSTM_SHIFT (24U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSSTM_WIDTH (1U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSSTM(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSSTM_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSSTM_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSNS_MASK (0x3E000000U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSNS_SHIFT (25U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSNS_WIDTH (5U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSNS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSNS_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_Reserved_ATSNS_MASK)

#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_31_30_MASK (0xC0000000U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_31_30_SHIFT (30U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_31_30_WIDTH (2U)
#define GMAC_MAC_TIMESTAMP_STATUS_Reserved_31_30(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_STATUS_Reserved_31_30_SHIFT)) & GMAC_MAC_TIMESTAMP_STATUS_Reserved_31_30_MASK)
/*! @} */

/*! @name MAC_TX_TIMESTAMP_STATUS_NANOSECONDS -  */
/*! @{ */

#define GMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_MASK (0x7FFFFFFFU)
#define GMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_SHIFT (0U)
#define GMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_WIDTH (31U)
#define GMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_SHIFT)) & GMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSLO_MASK)

#define GMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_MASK (0x80000000U)
#define GMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_SHIFT (31U)
#define GMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_WIDTH (1U)
#define GMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_SHIFT)) & GMAC_MAC_TX_TIMESTAMP_STATUS_NANOSECONDS_TXTSSMIS_MASK)
/*! @} */

/*! @name MAC_TX_TIMESTAMP_STATUS_SECONDS -  */
/*! @{ */

#define GMAC_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_MASK (0xFFFFFFFFU)
#define GMAC_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_SHIFT (0U)
#define GMAC_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_WIDTH (32U)
#define GMAC_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_SHIFT)) & GMAC_MAC_TX_TIMESTAMP_STATUS_SECONDS_TXTSSHI_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_INGRESS_ASYM_CORR -  */
/*! @{ */

#define GMAC_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_MASK (0xFFFFFFFFU)
#define GMAC_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_SHIFT (0U)
#define GMAC_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_WIDTH (32U)
#define GMAC_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_SHIFT)) & GMAC_MAC_TIMESTAMP_INGRESS_ASYM_CORR_OSTIAC_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_EGRESS_ASYM_CORR -  */
/*! @{ */

#define GMAC_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_MASK (0xFFFFFFFFU)
#define GMAC_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_SHIFT (0U)
#define GMAC_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_WIDTH (32U)
#define GMAC_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_SHIFT)) & GMAC_MAC_TIMESTAMP_EGRESS_ASYM_CORR_OSTEAC_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND -  */
/*! @{ */

#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_MASK (0xFFFFFFFFU)
#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_SHIFT (0U)
#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_WIDTH (32U)
#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_SHIFT)) & GMAC_MAC_TIMESTAMP_INGRESS_CORR_NANOSECOND_TSIC_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND -  */
/*! @{ */

#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_MASK (0xFFFFFFFFU)
#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_SHIFT (0U)
#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_WIDTH (32U)
#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_SHIFT)) & GMAC_MAC_TIMESTAMP_EGRESS_CORR_NANOSECOND_TSEC_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC -  */
/*! @{ */

#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_Reserved_7_0_MASK (0xFFU)
#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_Reserved_7_0_SHIFT (0U)
#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_Reserved_7_0_WIDTH (8U)
#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_Reserved_7_0(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_Reserved_7_0_SHIFT)) & GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_Reserved_7_0_MASK)

#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS_MASK (0xFF00U)
#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS_SHIFT (8U)
#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS_WIDTH (8U)
#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS_SHIFT)) & GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_TSICSNS_MASK)

#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_Reserved_31_16_MASK (0xFFFF0000U)
#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_Reserved_31_16_SHIFT (16U)
#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_Reserved_31_16_WIDTH (16U)
#define GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_Reserved_31_16(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_Reserved_31_16_SHIFT)) & GMAC_MAC_TIMESTAMP_INGRESS_CORR_SUBNANOSEC_Reserved_31_16_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC -  */
/*! @{ */

#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_Reserved_7_0_MASK (0xFFU)
#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_Reserved_7_0_SHIFT (0U)
#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_Reserved_7_0_WIDTH (8U)
#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_Reserved_7_0(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_Reserved_7_0_SHIFT)) & GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_Reserved_7_0_MASK)

#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS_MASK (0xFF00U)
#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS_SHIFT (8U)
#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS_WIDTH (8U)
#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS_SHIFT)) & GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_TSECSNS_MASK)

#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_Reserved_31_16_MASK (0xFFFF0000U)
#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_Reserved_31_16_SHIFT (16U)
#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_Reserved_31_16_WIDTH (16U)
#define GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_Reserved_31_16(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_Reserved_31_16_SHIFT)) & GMAC_MAC_TIMESTAMP_EGRESS_CORR_SUBNANOSEC_Reserved_31_16_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_INGRESS_LATENCY -  */
/*! @{ */

#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_Reserved_7_0_MASK (0xFFU)
#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_Reserved_7_0_SHIFT (0U)
#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_Reserved_7_0_WIDTH (8U)
#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_Reserved_7_0(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_Reserved_7_0_SHIFT)) & GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_Reserved_7_0_MASK)

#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_MASK (0xFF00U)
#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_SHIFT (8U)
#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_WIDTH (8U)
#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_SHIFT)) & GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLSNS_MASK)

#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_MASK (0xFFF0000U)
#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_SHIFT (16U)
#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_WIDTH (12U)
#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_SHIFT)) & GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_ITLNS_MASK)

#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_Reserved_31_28_MASK (0xF0000000U)
#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_Reserved_31_28_SHIFT (28U)
#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_Reserved_31_28_WIDTH (4U)
#define GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_Reserved_31_28(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_Reserved_31_28_SHIFT)) & GMAC_MAC_TIMESTAMP_INGRESS_LATENCY_Reserved_31_28_MASK)
/*! @} */

/*! @name MAC_TIMESTAMP_EGRESS_LATENCY -  */
/*! @{ */

#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_Reserved_7_0_MASK (0xFFU)
#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_Reserved_7_0_SHIFT (0U)
#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_Reserved_7_0_WIDTH (8U)
#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_Reserved_7_0(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_Reserved_7_0_SHIFT)) & GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_Reserved_7_0_MASK)

#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_MASK (0xFF00U)
#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_SHIFT (8U)
#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_WIDTH (8U)
#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_SHIFT)) & GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLSNS_MASK)

#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_MASK (0xFFF0000U)
#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_SHIFT (16U)
#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_WIDTH (12U)
#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_SHIFT)) & GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_ETLNS_MASK)

#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_Reserved_31_28_MASK (0xF0000000U)
#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_Reserved_31_28_SHIFT (28U)
#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_Reserved_31_28_WIDTH (4U)
#define GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_Reserved_31_28(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_Reserved_31_28_SHIFT)) & GMAC_MAC_TIMESTAMP_EGRESS_LATENCY_Reserved_31_28_MASK)
/*! @} */

/*! @name MAC_PPS_CONTROL -  */
/*! @{ */

#define GMAC_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_MASK (0xFU)
#define GMAC_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_SHIFT (0U)
#define GMAC_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_WIDTH (4U)
#define GMAC_MAC_PPS_CONTROL_PPSCTRL_PPSCMD(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_SHIFT)) & GMAC_MAC_PPS_CONTROL_PPSCTRL_PPSCMD_MASK)

#define GMAC_MAC_PPS_CONTROL_PPSEN0_MASK         (0x10U)
#define GMAC_MAC_PPS_CONTROL_PPSEN0_SHIFT        (4U)
#define GMAC_MAC_PPS_CONTROL_PPSEN0_WIDTH        (1U)
#define GMAC_MAC_PPS_CONTROL_PPSEN0(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_PPSEN0_SHIFT)) & GMAC_MAC_PPS_CONTROL_PPSEN0_MASK)

#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL0_MASK    (0x60U)
#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL0_SHIFT   (5U)
#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL0_WIDTH   (2U)
#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL0(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_TRGTMODSEL0_SHIFT)) & GMAC_MAC_PPS_CONTROL_TRGTMODSEL0_MASK)

#define GMAC_MAC_PPS_CONTROL_MCGREN0_MASK        (0x80U)
#define GMAC_MAC_PPS_CONTROL_MCGREN0_SHIFT       (7U)
#define GMAC_MAC_PPS_CONTROL_MCGREN0_WIDTH       (1U)
#define GMAC_MAC_PPS_CONTROL_MCGREN0(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_MCGREN0_SHIFT)) & GMAC_MAC_PPS_CONTROL_MCGREN0_MASK)

#define GMAC_MAC_PPS_CONTROL_PPSCMD1_MASK        (0xF00U)
#define GMAC_MAC_PPS_CONTROL_PPSCMD1_SHIFT       (8U)
#define GMAC_MAC_PPS_CONTROL_PPSCMD1_WIDTH       (4U)
#define GMAC_MAC_PPS_CONTROL_PPSCMD1(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_PPSCMD1_SHIFT)) & GMAC_MAC_PPS_CONTROL_PPSCMD1_MASK)

#define GMAC_MAC_PPS_CONTROL_Reserved_12_MASK    (0x1000U)
#define GMAC_MAC_PPS_CONTROL_Reserved_12_SHIFT   (12U)
#define GMAC_MAC_PPS_CONTROL_Reserved_12_WIDTH   (1U)
#define GMAC_MAC_PPS_CONTROL_Reserved_12(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_Reserved_12_SHIFT)) & GMAC_MAC_PPS_CONTROL_Reserved_12_MASK)

#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL1_MASK    (0x6000U)
#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL1_SHIFT   (13U)
#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL1_WIDTH   (2U)
#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL1(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_TRGTMODSEL1_SHIFT)) & GMAC_MAC_PPS_CONTROL_TRGTMODSEL1_MASK)

#define GMAC_MAC_PPS_CONTROL_MCGREN1_MASK        (0x8000U)
#define GMAC_MAC_PPS_CONTROL_MCGREN1_SHIFT       (15U)
#define GMAC_MAC_PPS_CONTROL_MCGREN1_WIDTH       (1U)
#define GMAC_MAC_PPS_CONTROL_MCGREN1(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_MCGREN1_SHIFT)) & GMAC_MAC_PPS_CONTROL_MCGREN1_MASK)

#define GMAC_MAC_PPS_CONTROL_PPSCMD2_MASK        (0xF0000U)
#define GMAC_MAC_PPS_CONTROL_PPSCMD2_SHIFT       (16U)
#define GMAC_MAC_PPS_CONTROL_PPSCMD2_WIDTH       (4U)
#define GMAC_MAC_PPS_CONTROL_PPSCMD2(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_PPSCMD2_SHIFT)) & GMAC_MAC_PPS_CONTROL_PPSCMD2_MASK)

#define GMAC_MAC_PPS_CONTROL_Reserved_20_MASK    (0x100000U)
#define GMAC_MAC_PPS_CONTROL_Reserved_20_SHIFT   (20U)
#define GMAC_MAC_PPS_CONTROL_Reserved_20_WIDTH   (1U)
#define GMAC_MAC_PPS_CONTROL_Reserved_20(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_Reserved_20_SHIFT)) & GMAC_MAC_PPS_CONTROL_Reserved_20_MASK)

#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL2_MASK    (0x600000U)
#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL2_SHIFT   (21U)
#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL2_WIDTH   (2U)
#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL2(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_TRGTMODSEL2_SHIFT)) & GMAC_MAC_PPS_CONTROL_TRGTMODSEL2_MASK)

#define GMAC_MAC_PPS_CONTROL_MCGREN2_MASK        (0x800000U)
#define GMAC_MAC_PPS_CONTROL_MCGREN2_SHIFT       (23U)
#define GMAC_MAC_PPS_CONTROL_MCGREN2_WIDTH       (1U)
#define GMAC_MAC_PPS_CONTROL_MCGREN2(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_MCGREN2_SHIFT)) & GMAC_MAC_PPS_CONTROL_MCGREN2_MASK)

#define GMAC_MAC_PPS_CONTROL_PPSCMD3_MASK        (0xF000000U)
#define GMAC_MAC_PPS_CONTROL_PPSCMD3_SHIFT       (24U)
#define GMAC_MAC_PPS_CONTROL_PPSCMD3_WIDTH       (4U)
#define GMAC_MAC_PPS_CONTROL_PPSCMD3(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_PPSCMD3_SHIFT)) & GMAC_MAC_PPS_CONTROL_PPSCMD3_MASK)

#define GMAC_MAC_PPS_CONTROL_TIMESEL_MASK        (0x10000000U)
#define GMAC_MAC_PPS_CONTROL_TIMESEL_SHIFT       (28U)
#define GMAC_MAC_PPS_CONTROL_TIMESEL_WIDTH       (1U)
#define GMAC_MAC_PPS_CONTROL_TIMESEL(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_TIMESEL_SHIFT)) & GMAC_MAC_PPS_CONTROL_TIMESEL_MASK)

#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL3_MASK    (0x60000000U)
#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL3_SHIFT   (29U)
#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL3_WIDTH   (2U)
#define GMAC_MAC_PPS_CONTROL_TRGTMODSEL3(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_TRGTMODSEL3_SHIFT)) & GMAC_MAC_PPS_CONTROL_TRGTMODSEL3_MASK)

#define GMAC_MAC_PPS_CONTROL_MCGREN3_MASK        (0x80000000U)
#define GMAC_MAC_PPS_CONTROL_MCGREN3_SHIFT       (31U)
#define GMAC_MAC_PPS_CONTROL_MCGREN3_WIDTH       (1U)
#define GMAC_MAC_PPS_CONTROL_MCGREN3(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS_CONTROL_MCGREN3_SHIFT)) & GMAC_MAC_PPS_CONTROL_MCGREN3_MASK)
/*! @} */

/*! @name MAC_PPS0_TARGET_TIME_SECONDS -  */
/*! @{ */

#define GMAC_MAC_PPS0_TARGET_TIME_SECONDS_TSTRH0_MASK (0xFFFFFFFFU)
#define GMAC_MAC_PPS0_TARGET_TIME_SECONDS_TSTRH0_SHIFT (0U)
#define GMAC_MAC_PPS0_TARGET_TIME_SECONDS_TSTRH0_WIDTH (32U)
#define GMAC_MAC_PPS0_TARGET_TIME_SECONDS_TSTRH0(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS0_TARGET_TIME_SECONDS_TSTRH0_SHIFT)) & GMAC_MAC_PPS0_TARGET_TIME_SECONDS_TSTRH0_MASK)
/*! @} */

/*! @name MAC_PPS0_TARGET_TIME_NANOSECONDS -  */
/*! @{ */

#define GMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_MASK (0x7FFFFFFFU)
#define GMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_SHIFT (0U)
#define GMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_WIDTH (31U)
#define GMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TTSL0(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_SHIFT)) & GMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TTSL0_MASK)

#define GMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TRGTBUSY0_MASK (0x80000000U)
#define GMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TRGTBUSY0_SHIFT (31U)
#define GMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TRGTBUSY0_WIDTH (1U)
#define GMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TRGTBUSY0(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TRGTBUSY0_SHIFT)) & GMAC_MAC_PPS0_TARGET_TIME_NANOSECONDS_TRGTBUSY0_MASK)
/*! @} */

/*! @name MAC_PPS0_INTERVAL -  */
/*! @{ */

#define GMAC_MAC_PPS0_INTERVAL_PPSINT0_MASK      (0xFFFFFFFFU)
#define GMAC_MAC_PPS0_INTERVAL_PPSINT0_SHIFT     (0U)
#define GMAC_MAC_PPS0_INTERVAL_PPSINT0_WIDTH     (32U)
#define GMAC_MAC_PPS0_INTERVAL_PPSINT0(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS0_INTERVAL_PPSINT0_SHIFT)) & GMAC_MAC_PPS0_INTERVAL_PPSINT0_MASK)
/*! @} */

/*! @name MAC_PPS0_WIDTH -  */
/*! @{ */

#define GMAC_MAC_PPS0_WIDTH_PPSWIDTH0_MASK       (0xFFFFFFFFU)
#define GMAC_MAC_PPS0_WIDTH_PPSWIDTH0_SHIFT      (0U)
#define GMAC_MAC_PPS0_WIDTH_PPSWIDTH0_WIDTH      (32U)
#define GMAC_MAC_PPS0_WIDTH_PPSWIDTH0(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS0_WIDTH_PPSWIDTH0_SHIFT)) & GMAC_MAC_PPS0_WIDTH_PPSWIDTH0_MASK)
/*! @} */

/*! @name MAC_PPS1_TARGET_TIME_SECONDS -  */
/*! @{ */

#define GMAC_MAC_PPS1_TARGET_TIME_SECONDS_TSTRH1_MASK (0xFFFFFFFFU)
#define GMAC_MAC_PPS1_TARGET_TIME_SECONDS_TSTRH1_SHIFT (0U)
#define GMAC_MAC_PPS1_TARGET_TIME_SECONDS_TSTRH1_WIDTH (32U)
#define GMAC_MAC_PPS1_TARGET_TIME_SECONDS_TSTRH1(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS1_TARGET_TIME_SECONDS_TSTRH1_SHIFT)) & GMAC_MAC_PPS1_TARGET_TIME_SECONDS_TSTRH1_MASK)
/*! @} */

/*! @name MAC_PPS1_TARGET_TIME_NANOSECONDS -  */
/*! @{ */

#define GMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TTSL1_MASK (0x7FFFFFFFU)
#define GMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TTSL1_SHIFT (0U)
#define GMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TTSL1_WIDTH (31U)
#define GMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TTSL1(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TTSL1_SHIFT)) & GMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TTSL1_MASK)

#define GMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TRGTBUSY1_MASK (0x80000000U)
#define GMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TRGTBUSY1_SHIFT (31U)
#define GMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TRGTBUSY1_WIDTH (1U)
#define GMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TRGTBUSY1(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TRGTBUSY1_SHIFT)) & GMAC_MAC_PPS1_TARGET_TIME_NANOSECONDS_TRGTBUSY1_MASK)
/*! @} */

/*! @name MAC_PPS1_INTERVAL -  */
/*! @{ */

#define GMAC_MAC_PPS1_INTERVAL_PPSINT1_MASK      (0xFFFFFFFFU)
#define GMAC_MAC_PPS1_INTERVAL_PPSINT1_SHIFT     (0U)
#define GMAC_MAC_PPS1_INTERVAL_PPSINT1_WIDTH     (32U)
#define GMAC_MAC_PPS1_INTERVAL_PPSINT1(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS1_INTERVAL_PPSINT1_SHIFT)) & GMAC_MAC_PPS1_INTERVAL_PPSINT1_MASK)
/*! @} */

/*! @name MAC_PPS1_WIDTH -  */
/*! @{ */

#define GMAC_MAC_PPS1_WIDTH_PPSWIDTH1_MASK       (0xFFFFFFFFU)
#define GMAC_MAC_PPS1_WIDTH_PPSWIDTH1_SHIFT      (0U)
#define GMAC_MAC_PPS1_WIDTH_PPSWIDTH1_WIDTH      (32U)
#define GMAC_MAC_PPS1_WIDTH_PPSWIDTH1(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS1_WIDTH_PPSWIDTH1_SHIFT)) & GMAC_MAC_PPS1_WIDTH_PPSWIDTH1_MASK)
/*! @} */

/*! @name MAC_PPS2_TARGET_TIME_SECONDS -  */
/*! @{ */

#define GMAC_MAC_PPS2_TARGET_TIME_SECONDS_TSTRH2_MASK (0xFFFFFFFFU)
#define GMAC_MAC_PPS2_TARGET_TIME_SECONDS_TSTRH2_SHIFT (0U)
#define GMAC_MAC_PPS2_TARGET_TIME_SECONDS_TSTRH2_WIDTH (32U)
#define GMAC_MAC_PPS2_TARGET_TIME_SECONDS_TSTRH2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS2_TARGET_TIME_SECONDS_TSTRH2_SHIFT)) & GMAC_MAC_PPS2_TARGET_TIME_SECONDS_TSTRH2_MASK)
/*! @} */

/*! @name MAC_PPS2_TARGET_TIME_NANOSECONDS -  */
/*! @{ */

#define GMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TTSL2_MASK (0x7FFFFFFFU)
#define GMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TTSL2_SHIFT (0U)
#define GMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TTSL2_WIDTH (31U)
#define GMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TTSL2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TTSL2_SHIFT)) & GMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TTSL2_MASK)

#define GMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TRGTBUSY2_MASK (0x80000000U)
#define GMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TRGTBUSY2_SHIFT (31U)
#define GMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TRGTBUSY2_WIDTH (1U)
#define GMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TRGTBUSY2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TRGTBUSY2_SHIFT)) & GMAC_MAC_PPS2_TARGET_TIME_NANOSECONDS_TRGTBUSY2_MASK)
/*! @} */

/*! @name MAC_PPS2_INTERVAL -  */
/*! @{ */

#define GMAC_MAC_PPS2_INTERVAL_PPSINT2_MASK      (0xFFFFFFFFU)
#define GMAC_MAC_PPS2_INTERVAL_PPSINT2_SHIFT     (0U)
#define GMAC_MAC_PPS2_INTERVAL_PPSINT2_WIDTH     (32U)
#define GMAC_MAC_PPS2_INTERVAL_PPSINT2(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS2_INTERVAL_PPSINT2_SHIFT)) & GMAC_MAC_PPS2_INTERVAL_PPSINT2_MASK)
/*! @} */

/*! @name MAC_PPS2_WIDTH -  */
/*! @{ */

#define GMAC_MAC_PPS2_WIDTH_PPSWIDTH2_MASK       (0xFFFFFFFFU)
#define GMAC_MAC_PPS2_WIDTH_PPSWIDTH2_SHIFT      (0U)
#define GMAC_MAC_PPS2_WIDTH_PPSWIDTH2_WIDTH      (32U)
#define GMAC_MAC_PPS2_WIDTH_PPSWIDTH2(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS2_WIDTH_PPSWIDTH2_SHIFT)) & GMAC_MAC_PPS2_WIDTH_PPSWIDTH2_MASK)
/*! @} */

/*! @name MAC_PPS3_TARGET_TIME_SECONDS -  */
/*! @{ */

#define GMAC_MAC_PPS3_TARGET_TIME_SECONDS_TSTRH3_MASK (0xFFFFFFFFU)
#define GMAC_MAC_PPS3_TARGET_TIME_SECONDS_TSTRH3_SHIFT (0U)
#define GMAC_MAC_PPS3_TARGET_TIME_SECONDS_TSTRH3_WIDTH (32U)
#define GMAC_MAC_PPS3_TARGET_TIME_SECONDS_TSTRH3(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS3_TARGET_TIME_SECONDS_TSTRH3_SHIFT)) & GMAC_MAC_PPS3_TARGET_TIME_SECONDS_TSTRH3_MASK)
/*! @} */

/*! @name MAC_PPS3_TARGET_TIME_NANOSECONDS -  */
/*! @{ */

#define GMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TTSL3_MASK (0x7FFFFFFFU)
#define GMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TTSL3_SHIFT (0U)
#define GMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TTSL3_WIDTH (31U)
#define GMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TTSL3(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TTSL3_SHIFT)) & GMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TTSL3_MASK)

#define GMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TRGTBUSY3_MASK (0x80000000U)
#define GMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TRGTBUSY3_SHIFT (31U)
#define GMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TRGTBUSY3_WIDTH (1U)
#define GMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TRGTBUSY3(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TRGTBUSY3_SHIFT)) & GMAC_MAC_PPS3_TARGET_TIME_NANOSECONDS_TRGTBUSY3_MASK)
/*! @} */

/*! @name MAC_PPS3_INTERVAL -  */
/*! @{ */

#define GMAC_MAC_PPS3_INTERVAL_PPSINT3_MASK      (0xFFFFFFFFU)
#define GMAC_MAC_PPS3_INTERVAL_PPSINT3_SHIFT     (0U)
#define GMAC_MAC_PPS3_INTERVAL_PPSINT3_WIDTH     (32U)
#define GMAC_MAC_PPS3_INTERVAL_PPSINT3(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS3_INTERVAL_PPSINT3_SHIFT)) & GMAC_MAC_PPS3_INTERVAL_PPSINT3_MASK)
/*! @} */

/*! @name MAC_PPS3_WIDTH -  */
/*! @{ */

#define GMAC_MAC_PPS3_WIDTH_PPSWIDTH3_MASK       (0xFFFFFFFFU)
#define GMAC_MAC_PPS3_WIDTH_PPSWIDTH3_SHIFT      (0U)
#define GMAC_MAC_PPS3_WIDTH_PPSWIDTH3_WIDTH      (32U)
#define GMAC_MAC_PPS3_WIDTH_PPSWIDTH3(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MAC_PPS3_WIDTH_PPSWIDTH3_SHIFT)) & GMAC_MAC_PPS3_WIDTH_PPSWIDTH3_MASK)
/*! @} */

/*! @name MTL_OPERATION_MODE -  */
/*! @{ */

#define GMAC_MTL_OPERATION_MODE_Reserved_0_MASK  (0x1U)
#define GMAC_MTL_OPERATION_MODE_Reserved_0_SHIFT (0U)
#define GMAC_MTL_OPERATION_MODE_Reserved_0_WIDTH (1U)
#define GMAC_MTL_OPERATION_MODE_Reserved_0(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_OPERATION_MODE_Reserved_0_SHIFT)) & GMAC_MTL_OPERATION_MODE_Reserved_0_MASK)

#define GMAC_MTL_OPERATION_MODE_DTXSTS_MASK      (0x2U)
#define GMAC_MTL_OPERATION_MODE_DTXSTS_SHIFT     (1U)
#define GMAC_MTL_OPERATION_MODE_DTXSTS_WIDTH     (1U)
#define GMAC_MTL_OPERATION_MODE_DTXSTS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_OPERATION_MODE_DTXSTS_SHIFT)) & GMAC_MTL_OPERATION_MODE_DTXSTS_MASK)

#define GMAC_MTL_OPERATION_MODE_RAA_MASK         (0x4U)
#define GMAC_MTL_OPERATION_MODE_RAA_SHIFT        (2U)
#define GMAC_MTL_OPERATION_MODE_RAA_WIDTH        (1U)
#define GMAC_MTL_OPERATION_MODE_RAA(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_OPERATION_MODE_RAA_SHIFT)) & GMAC_MTL_OPERATION_MODE_RAA_MASK)

#define GMAC_MTL_OPERATION_MODE_Reserved_4_3_MASK (0x18U)
#define GMAC_MTL_OPERATION_MODE_Reserved_4_3_SHIFT (3U)
#define GMAC_MTL_OPERATION_MODE_Reserved_4_3_WIDTH (2U)
#define GMAC_MTL_OPERATION_MODE_Reserved_4_3(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_OPERATION_MODE_Reserved_4_3_SHIFT)) & GMAC_MTL_OPERATION_MODE_Reserved_4_3_MASK)

#define GMAC_MTL_OPERATION_MODE_SCHALG_MASK      (0x60U)
#define GMAC_MTL_OPERATION_MODE_SCHALG_SHIFT     (5U)
#define GMAC_MTL_OPERATION_MODE_SCHALG_WIDTH     (2U)
#define GMAC_MTL_OPERATION_MODE_SCHALG(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_OPERATION_MODE_SCHALG_SHIFT)) & GMAC_MTL_OPERATION_MODE_SCHALG_MASK)

#define GMAC_MTL_OPERATION_MODE_Reserved_7_MASK  (0x80U)
#define GMAC_MTL_OPERATION_MODE_Reserved_7_SHIFT (7U)
#define GMAC_MTL_OPERATION_MODE_Reserved_7_WIDTH (1U)
#define GMAC_MTL_OPERATION_MODE_Reserved_7(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_OPERATION_MODE_Reserved_7_SHIFT)) & GMAC_MTL_OPERATION_MODE_Reserved_7_MASK)

#define GMAC_MTL_OPERATION_MODE_CNTPRST_MASK     (0x100U)
#define GMAC_MTL_OPERATION_MODE_CNTPRST_SHIFT    (8U)
#define GMAC_MTL_OPERATION_MODE_CNTPRST_WIDTH    (1U)
#define GMAC_MTL_OPERATION_MODE_CNTPRST(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_OPERATION_MODE_CNTPRST_SHIFT)) & GMAC_MTL_OPERATION_MODE_CNTPRST_MASK)

#define GMAC_MTL_OPERATION_MODE_CNTCLR_MASK      (0x200U)
#define GMAC_MTL_OPERATION_MODE_CNTCLR_SHIFT     (9U)
#define GMAC_MTL_OPERATION_MODE_CNTCLR_WIDTH     (1U)
#define GMAC_MTL_OPERATION_MODE_CNTCLR(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_OPERATION_MODE_CNTCLR_SHIFT)) & GMAC_MTL_OPERATION_MODE_CNTCLR_MASK)

#define GMAC_MTL_OPERATION_MODE_Reserved_13_10_MASK (0x3C00U)
#define GMAC_MTL_OPERATION_MODE_Reserved_13_10_SHIFT (10U)
#define GMAC_MTL_OPERATION_MODE_Reserved_13_10_WIDTH (4U)
#define GMAC_MTL_OPERATION_MODE_Reserved_13_10(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_OPERATION_MODE_Reserved_13_10_SHIFT)) & GMAC_MTL_OPERATION_MODE_Reserved_13_10_MASK)

#define GMAC_MTL_OPERATION_MODE_RXPED_MASK       (0x4000U)
#define GMAC_MTL_OPERATION_MODE_RXPED_SHIFT      (14U)
#define GMAC_MTL_OPERATION_MODE_RXPED_WIDTH      (1U)
#define GMAC_MTL_OPERATION_MODE_RXPED(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_OPERATION_MODE_RXPED_SHIFT)) & GMAC_MTL_OPERATION_MODE_RXPED_MASK)

#define GMAC_MTL_OPERATION_MODE_FRPE_MASK        (0x8000U)
#define GMAC_MTL_OPERATION_MODE_FRPE_SHIFT       (15U)
#define GMAC_MTL_OPERATION_MODE_FRPE_WIDTH       (1U)
#define GMAC_MTL_OPERATION_MODE_FRPE(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_OPERATION_MODE_FRPE_SHIFT)) & GMAC_MTL_OPERATION_MODE_FRPE_MASK)

#define GMAC_MTL_OPERATION_MODE_Reserved_31_16_MASK (0xFFFF0000U)
#define GMAC_MTL_OPERATION_MODE_Reserved_31_16_SHIFT (16U)
#define GMAC_MTL_OPERATION_MODE_Reserved_31_16_WIDTH (16U)
#define GMAC_MTL_OPERATION_MODE_Reserved_31_16(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_OPERATION_MODE_Reserved_31_16_SHIFT)) & GMAC_MTL_OPERATION_MODE_Reserved_31_16_MASK)
/*! @} */

/*! @name MTL_DBG_CTL -  */
/*! @{ */

#define GMAC_MTL_DBG_CTL_FDBGEN_MASK             (0x1U)
#define GMAC_MTL_DBG_CTL_FDBGEN_SHIFT            (0U)
#define GMAC_MTL_DBG_CTL_FDBGEN_WIDTH            (1U)
#define GMAC_MTL_DBG_CTL_FDBGEN(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_FDBGEN_SHIFT)) & GMAC_MTL_DBG_CTL_FDBGEN_MASK)

#define GMAC_MTL_DBG_CTL_DBGMOD_MASK             (0x2U)
#define GMAC_MTL_DBG_CTL_DBGMOD_SHIFT            (1U)
#define GMAC_MTL_DBG_CTL_DBGMOD_WIDTH            (1U)
#define GMAC_MTL_DBG_CTL_DBGMOD(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_DBGMOD_SHIFT)) & GMAC_MTL_DBG_CTL_DBGMOD_MASK)

#define GMAC_MTL_DBG_CTL_BYTEEN_MASK             (0xCU)
#define GMAC_MTL_DBG_CTL_BYTEEN_SHIFT            (2U)
#define GMAC_MTL_DBG_CTL_BYTEEN_WIDTH            (2U)
#define GMAC_MTL_DBG_CTL_BYTEEN(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_BYTEEN_SHIFT)) & GMAC_MTL_DBG_CTL_BYTEEN_MASK)

#define GMAC_MTL_DBG_CTL_Reserved_4_MASK         (0x10U)
#define GMAC_MTL_DBG_CTL_Reserved_4_SHIFT        (4U)
#define GMAC_MTL_DBG_CTL_Reserved_4_WIDTH        (1U)
#define GMAC_MTL_DBG_CTL_Reserved_4(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_Reserved_4_SHIFT)) & GMAC_MTL_DBG_CTL_Reserved_4_MASK)

#define GMAC_MTL_DBG_CTL_PKTSTATE_MASK           (0x60U)
#define GMAC_MTL_DBG_CTL_PKTSTATE_SHIFT          (5U)
#define GMAC_MTL_DBG_CTL_PKTSTATE_WIDTH          (2U)
#define GMAC_MTL_DBG_CTL_PKTSTATE(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_PKTSTATE_SHIFT)) & GMAC_MTL_DBG_CTL_PKTSTATE_MASK)

#define GMAC_MTL_DBG_CTL_Reserved_7_MASK         (0x80U)
#define GMAC_MTL_DBG_CTL_Reserved_7_SHIFT        (7U)
#define GMAC_MTL_DBG_CTL_Reserved_7_WIDTH        (1U)
#define GMAC_MTL_DBG_CTL_Reserved_7(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_Reserved_7_SHIFT)) & GMAC_MTL_DBG_CTL_Reserved_7_MASK)

#define GMAC_MTL_DBG_CTL_RSTALL_MASK             (0x100U)
#define GMAC_MTL_DBG_CTL_RSTALL_SHIFT            (8U)
#define GMAC_MTL_DBG_CTL_RSTALL_WIDTH            (1U)
#define GMAC_MTL_DBG_CTL_RSTALL(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_RSTALL_SHIFT)) & GMAC_MTL_DBG_CTL_RSTALL_MASK)

#define GMAC_MTL_DBG_CTL_RSTSEL_MASK             (0x200U)
#define GMAC_MTL_DBG_CTL_RSTSEL_SHIFT            (9U)
#define GMAC_MTL_DBG_CTL_RSTSEL_WIDTH            (1U)
#define GMAC_MTL_DBG_CTL_RSTSEL(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_RSTSEL_SHIFT)) & GMAC_MTL_DBG_CTL_RSTSEL_MASK)

#define GMAC_MTL_DBG_CTL_FIFORDEN_MASK           (0x400U)
#define GMAC_MTL_DBG_CTL_FIFORDEN_SHIFT          (10U)
#define GMAC_MTL_DBG_CTL_FIFORDEN_WIDTH          (1U)
#define GMAC_MTL_DBG_CTL_FIFORDEN(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_FIFORDEN_SHIFT)) & GMAC_MTL_DBG_CTL_FIFORDEN_MASK)

#define GMAC_MTL_DBG_CTL_FIFOWREN_MASK           (0x800U)
#define GMAC_MTL_DBG_CTL_FIFOWREN_SHIFT          (11U)
#define GMAC_MTL_DBG_CTL_FIFOWREN_WIDTH          (1U)
#define GMAC_MTL_DBG_CTL_FIFOWREN(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_FIFOWREN_SHIFT)) & GMAC_MTL_DBG_CTL_FIFOWREN_MASK)

#define GMAC_MTL_DBG_CTL_FIFOSEL_MASK            (0x3000U)
#define GMAC_MTL_DBG_CTL_FIFOSEL_SHIFT           (12U)
#define GMAC_MTL_DBG_CTL_FIFOSEL_WIDTH           (2U)
#define GMAC_MTL_DBG_CTL_FIFOSEL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_FIFOSEL_SHIFT)) & GMAC_MTL_DBG_CTL_FIFOSEL_MASK)

#define GMAC_MTL_DBG_CTL_PKTIE_MASK              (0x4000U)
#define GMAC_MTL_DBG_CTL_PKTIE_SHIFT             (14U)
#define GMAC_MTL_DBG_CTL_PKTIE_WIDTH             (1U)
#define GMAC_MTL_DBG_CTL_PKTIE(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_PKTIE_SHIFT)) & GMAC_MTL_DBG_CTL_PKTIE_MASK)

#define GMAC_MTL_DBG_CTL_STSIE_MASK              (0x8000U)
#define GMAC_MTL_DBG_CTL_STSIE_SHIFT             (15U)
#define GMAC_MTL_DBG_CTL_STSIE_WIDTH             (1U)
#define GMAC_MTL_DBG_CTL_STSIE(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_STSIE_SHIFT)) & GMAC_MTL_DBG_CTL_STSIE_MASK)

#define GMAC_MTL_DBG_CTL_EIEE_MASK               (0x10000U)
#define GMAC_MTL_DBG_CTL_EIEE_SHIFT              (16U)
#define GMAC_MTL_DBG_CTL_EIEE_WIDTH              (1U)
#define GMAC_MTL_DBG_CTL_EIEE(x)                 (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_EIEE_SHIFT)) & GMAC_MTL_DBG_CTL_EIEE_MASK)

#define GMAC_MTL_DBG_CTL_EIAEE_MASK              (0x20000U)
#define GMAC_MTL_DBG_CTL_EIAEE_SHIFT             (17U)
#define GMAC_MTL_DBG_CTL_EIAEE_WIDTH             (1U)
#define GMAC_MTL_DBG_CTL_EIAEE(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_EIAEE_SHIFT)) & GMAC_MTL_DBG_CTL_EIAEE_MASK)

#define GMAC_MTL_DBG_CTL_EIEC_MASK               (0x40000U)
#define GMAC_MTL_DBG_CTL_EIEC_SHIFT              (18U)
#define GMAC_MTL_DBG_CTL_EIEC_WIDTH              (1U)
#define GMAC_MTL_DBG_CTL_EIEC(x)                 (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_EIEC_SHIFT)) & GMAC_MTL_DBG_CTL_EIEC_MASK)

#define GMAC_MTL_DBG_CTL_Reserved_31_19_MASK     (0xFFF80000U)
#define GMAC_MTL_DBG_CTL_Reserved_31_19_SHIFT    (19U)
#define GMAC_MTL_DBG_CTL_Reserved_31_19_WIDTH    (13U)
#define GMAC_MTL_DBG_CTL_Reserved_31_19(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_CTL_Reserved_31_19_SHIFT)) & GMAC_MTL_DBG_CTL_Reserved_31_19_MASK)
/*! @} */

/*! @name MTL_DBG_STS -  */
/*! @{ */

#define GMAC_MTL_DBG_STS_FIFOBUSY_MASK           (0x1U)
#define GMAC_MTL_DBG_STS_FIFOBUSY_SHIFT          (0U)
#define GMAC_MTL_DBG_STS_FIFOBUSY_WIDTH          (1U)
#define GMAC_MTL_DBG_STS_FIFOBUSY(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_STS_FIFOBUSY_SHIFT)) & GMAC_MTL_DBG_STS_FIFOBUSY_MASK)

#define GMAC_MTL_DBG_STS_PKTSTATE_MASK           (0x6U)
#define GMAC_MTL_DBG_STS_PKTSTATE_SHIFT          (1U)
#define GMAC_MTL_DBG_STS_PKTSTATE_WIDTH          (2U)
#define GMAC_MTL_DBG_STS_PKTSTATE(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_STS_PKTSTATE_SHIFT)) & GMAC_MTL_DBG_STS_PKTSTATE_MASK)

#define GMAC_MTL_DBG_STS_BYTEEN_MASK             (0x18U)
#define GMAC_MTL_DBG_STS_BYTEEN_SHIFT            (3U)
#define GMAC_MTL_DBG_STS_BYTEEN_WIDTH            (2U)
#define GMAC_MTL_DBG_STS_BYTEEN(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_STS_BYTEEN_SHIFT)) & GMAC_MTL_DBG_STS_BYTEEN_MASK)

#define GMAC_MTL_DBG_STS_Reserved_7_5_MASK       (0xE0U)
#define GMAC_MTL_DBG_STS_Reserved_7_5_SHIFT      (5U)
#define GMAC_MTL_DBG_STS_Reserved_7_5_WIDTH      (3U)
#define GMAC_MTL_DBG_STS_Reserved_7_5(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_STS_Reserved_7_5_SHIFT)) & GMAC_MTL_DBG_STS_Reserved_7_5_MASK)

#define GMAC_MTL_DBG_STS_PKTI_MASK               (0x100U)
#define GMAC_MTL_DBG_STS_PKTI_SHIFT              (8U)
#define GMAC_MTL_DBG_STS_PKTI_WIDTH              (1U)
#define GMAC_MTL_DBG_STS_PKTI(x)                 (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_STS_PKTI_SHIFT)) & GMAC_MTL_DBG_STS_PKTI_MASK)

#define GMAC_MTL_DBG_STS_STSI_MASK               (0x200U)
#define GMAC_MTL_DBG_STS_STSI_SHIFT              (9U)
#define GMAC_MTL_DBG_STS_STSI_WIDTH              (1U)
#define GMAC_MTL_DBG_STS_STSI(x)                 (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_STS_STSI_SHIFT)) & GMAC_MTL_DBG_STS_STSI_MASK)

#define GMAC_MTL_DBG_STS_Reserved_14_10_MASK     (0x7C00U)
#define GMAC_MTL_DBG_STS_Reserved_14_10_SHIFT    (10U)
#define GMAC_MTL_DBG_STS_Reserved_14_10_WIDTH    (5U)
#define GMAC_MTL_DBG_STS_Reserved_14_10(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_STS_Reserved_14_10_SHIFT)) & GMAC_MTL_DBG_STS_Reserved_14_10_MASK)

#define GMAC_MTL_DBG_STS_LOCR_MASK               (0xFFFF8000U)
#define GMAC_MTL_DBG_STS_LOCR_SHIFT              (15U)
#define GMAC_MTL_DBG_STS_LOCR_WIDTH              (17U)
#define GMAC_MTL_DBG_STS_LOCR(x)                 (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DBG_STS_LOCR_SHIFT)) & GMAC_MTL_DBG_STS_LOCR_MASK)
/*! @} */

/*! @name MTL_FIFO_DEBUG_DATA -  */
/*! @{ */

#define GMAC_MTL_FIFO_DEBUG_DATA_FDBGDATA_MASK   (0xFFFFFFFFU)
#define GMAC_MTL_FIFO_DEBUG_DATA_FDBGDATA_SHIFT  (0U)
#define GMAC_MTL_FIFO_DEBUG_DATA_FDBGDATA_WIDTH  (32U)
#define GMAC_MTL_FIFO_DEBUG_DATA_FDBGDATA(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_FIFO_DEBUG_DATA_FDBGDATA_SHIFT)) & GMAC_MTL_FIFO_DEBUG_DATA_FDBGDATA_MASK)
/*! @} */

/*! @name MTL_INTERRUPT_STATUS -  */
/*! @{ */

#define GMAC_MTL_INTERRUPT_STATUS_Q0IS_MASK      (0x1U)
#define GMAC_MTL_INTERRUPT_STATUS_Q0IS_SHIFT     (0U)
#define GMAC_MTL_INTERRUPT_STATUS_Q0IS_WIDTH     (1U)
#define GMAC_MTL_INTERRUPT_STATUS_Q0IS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_Q0IS_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_Q0IS_MASK)

#define GMAC_MTL_INTERRUPT_STATUS_Q1IS_MASK      (0x2U)
#define GMAC_MTL_INTERRUPT_STATUS_Q1IS_SHIFT     (1U)
#define GMAC_MTL_INTERRUPT_STATUS_Q1IS_WIDTH     (1U)
#define GMAC_MTL_INTERRUPT_STATUS_Q1IS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_Q1IS_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_Q1IS_MASK)

#define GMAC_MTL_INTERRUPT_STATUS_Q2IS_MASK      (0x4U)
#define GMAC_MTL_INTERRUPT_STATUS_Q2IS_SHIFT     (2U)
#define GMAC_MTL_INTERRUPT_STATUS_Q2IS_WIDTH     (1U)
#define GMAC_MTL_INTERRUPT_STATUS_Q2IS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_Q2IS_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_Q2IS_MASK)

#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q3IS_MASK (0x8U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q3IS_SHIFT (3U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q3IS_WIDTH (1U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q3IS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_Reserved_Q3IS_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_Reserved_Q3IS_MASK)

#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q4IS_MASK (0x10U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q4IS_SHIFT (4U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q4IS_WIDTH (1U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q4IS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_Reserved_Q4IS_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_Reserved_Q4IS_MASK)

#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q5IS_MASK (0x20U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q5IS_SHIFT (5U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q5IS_WIDTH (1U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q5IS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_Reserved_Q5IS_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_Reserved_Q5IS_MASK)

#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q6IS_MASK (0x40U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q6IS_SHIFT (6U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q6IS_WIDTH (1U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q6IS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_Reserved_Q6IS_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_Reserved_Q6IS_MASK)

#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q7IS_MASK (0x80U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q7IS_SHIFT (7U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q7IS_WIDTH (1U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_Q7IS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_Reserved_Q7IS_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_Reserved_Q7IS_MASK)

#define GMAC_MTL_INTERRUPT_STATUS_Reserved_15_8_MASK (0xFF00U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_15_8_SHIFT (8U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_15_8_WIDTH (8U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_15_8(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_Reserved_15_8_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_Reserved_15_8_MASK)

#define GMAC_MTL_INTERRUPT_STATUS_Reserved_MACIS_MASK (0x10000U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_MACIS_SHIFT (16U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_MACIS_WIDTH (1U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_MACIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_Reserved_MACIS_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_Reserved_MACIS_MASK)

#define GMAC_MTL_INTERRUPT_STATUS_DBGIS_MASK     (0x20000U)
#define GMAC_MTL_INTERRUPT_STATUS_DBGIS_SHIFT    (17U)
#define GMAC_MTL_INTERRUPT_STATUS_DBGIS_WIDTH    (1U)
#define GMAC_MTL_INTERRUPT_STATUS_DBGIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_DBGIS_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_DBGIS_MASK)

#define GMAC_MTL_INTERRUPT_STATUS_ESTIS_MASK     (0x40000U)
#define GMAC_MTL_INTERRUPT_STATUS_ESTIS_SHIFT    (18U)
#define GMAC_MTL_INTERRUPT_STATUS_ESTIS_WIDTH    (1U)
#define GMAC_MTL_INTERRUPT_STATUS_ESTIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_ESTIS_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_ESTIS_MASK)

#define GMAC_MTL_INTERRUPT_STATUS_Reserved_22_19_MASK (0x780000U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_22_19_SHIFT (19U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_22_19_WIDTH (4U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_22_19(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_Reserved_22_19_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_Reserved_22_19_MASK)

#define GMAC_MTL_INTERRUPT_STATUS_MTLPIS_MASK    (0x800000U)
#define GMAC_MTL_INTERRUPT_STATUS_MTLPIS_SHIFT   (23U)
#define GMAC_MTL_INTERRUPT_STATUS_MTLPIS_WIDTH   (1U)
#define GMAC_MTL_INTERRUPT_STATUS_MTLPIS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_MTLPIS_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_MTLPIS_MASK)

#define GMAC_MTL_INTERRUPT_STATUS_Reserved_31_24_MASK (0xFF000000U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_31_24_SHIFT (24U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_31_24_WIDTH (8U)
#define GMAC_MTL_INTERRUPT_STATUS_Reserved_31_24(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_INTERRUPT_STATUS_Reserved_31_24_SHIFT)) & GMAC_MTL_INTERRUPT_STATUS_Reserved_31_24_MASK)
/*! @} */

/*! @name MTL_RXQ_DMA_MAP0 -  */
/*! @{ */

#define GMAC_MTL_RXQ_DMA_MAP0_Q0MDMACH_MASK      (0x3U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q0MDMACH_SHIFT     (0U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q0MDMACH_WIDTH     (2U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q0MDMACH(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Q0MDMACH_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Q0MDMACH_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_3_y_MASK  (0xCU)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_3_y_SHIFT (2U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_3_y_WIDTH (2U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_3_y(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Reserved_3_y_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Reserved_3_y_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Q0DDMACH_MASK      (0x10U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q0DDMACH_SHIFT     (4U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q0DDMACH_WIDTH     (1U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q0DDMACH(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Q0DDMACH_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Q0DDMACH_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_7_5_MASK  (0xE0U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_7_5_SHIFT (5U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_7_5_WIDTH (3U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_7_5(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Reserved_7_5_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Reserved_7_5_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Q1MDMACH_MASK      (0x300U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q1MDMACH_SHIFT     (8U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q1MDMACH_WIDTH     (2U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q1MDMACH(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Q1MDMACH_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Q1MDMACH_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_11_y_MASK (0xC00U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_11_y_SHIFT (10U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_11_y_WIDTH (2U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_11_y(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Reserved_11_y_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Reserved_11_y_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Q1DDMACH_MASK      (0x1000U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q1DDMACH_SHIFT     (12U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q1DDMACH_WIDTH     (1U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q1DDMACH(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Q1DDMACH_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Q1DDMACH_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_15_13_MASK (0xE000U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_15_13_SHIFT (13U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_15_13_WIDTH (3U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_15_13(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Reserved_15_13_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Reserved_15_13_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Q2MDMACH_MASK      (0x30000U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q2MDMACH_SHIFT     (16U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q2MDMACH_WIDTH     (2U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q2MDMACH(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Q2MDMACH_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Q2MDMACH_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_19_y_MASK (0xC0000U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_19_y_SHIFT (18U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_19_y_WIDTH (2U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_19_y(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Reserved_19_y_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Reserved_19_y_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Q2DDMACH_MASK      (0x100000U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q2DDMACH_SHIFT     (20U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q2DDMACH_WIDTH     (1U)
#define GMAC_MTL_RXQ_DMA_MAP0_Q2DDMACH(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Q2DDMACH_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Q2DDMACH_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_23_21_MASK (0xE00000U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_23_21_SHIFT (21U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_23_21_WIDTH (3U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_23_21(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Reserved_23_21_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Reserved_23_21_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_Q3MDMACH_MASK (0x3000000U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_Q3MDMACH_SHIFT (24U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_Q3MDMACH_WIDTH (2U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_Q3MDMACH(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Reserved_Q3MDMACH_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Reserved_Q3MDMACH_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_27_y_MASK (0xC000000U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_27_y_SHIFT (26U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_27_y_WIDTH (2U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_27_y(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Reserved_27_y_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Reserved_27_y_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_Q3DDMACH_MASK (0x10000000U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_Q3DDMACH_SHIFT (28U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_Q3DDMACH_WIDTH (1U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_Q3DDMACH(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Reserved_Q3DDMACH_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Reserved_Q3DDMACH_MASK)

#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_31_29_SHIFT (29U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_31_29_WIDTH (3U)
#define GMAC_MTL_RXQ_DMA_MAP0_Reserved_31_29(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ_DMA_MAP0_Reserved_31_29_SHIFT)) & GMAC_MTL_RXQ_DMA_MAP0_Reserved_31_29_MASK)
/*! @} */

/*! @name MTL_TBS_CTRL -  */
/*! @{ */

#define GMAC_MTL_TBS_CTRL_ESTM_MASK              (0x1U)
#define GMAC_MTL_TBS_CTRL_ESTM_SHIFT             (0U)
#define GMAC_MTL_TBS_CTRL_ESTM_WIDTH             (1U)
#define GMAC_MTL_TBS_CTRL_ESTM(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TBS_CTRL_ESTM_SHIFT)) & GMAC_MTL_TBS_CTRL_ESTM_MASK)

#define GMAC_MTL_TBS_CTRL_LEOV_MASK              (0x2U)
#define GMAC_MTL_TBS_CTRL_LEOV_SHIFT             (1U)
#define GMAC_MTL_TBS_CTRL_LEOV_WIDTH             (1U)
#define GMAC_MTL_TBS_CTRL_LEOV(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TBS_CTRL_LEOV_SHIFT)) & GMAC_MTL_TBS_CTRL_LEOV_MASK)

#define GMAC_MTL_TBS_CTRL_Reserved_3_2_MASK      (0xCU)
#define GMAC_MTL_TBS_CTRL_Reserved_3_2_SHIFT     (2U)
#define GMAC_MTL_TBS_CTRL_Reserved_3_2_WIDTH     (2U)
#define GMAC_MTL_TBS_CTRL_Reserved_3_2(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TBS_CTRL_Reserved_3_2_SHIFT)) & GMAC_MTL_TBS_CTRL_Reserved_3_2_MASK)

#define GMAC_MTL_TBS_CTRL_LEGOS_MASK             (0x70U)
#define GMAC_MTL_TBS_CTRL_LEGOS_SHIFT            (4U)
#define GMAC_MTL_TBS_CTRL_LEGOS_WIDTH            (3U)
#define GMAC_MTL_TBS_CTRL_LEGOS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TBS_CTRL_LEGOS_SHIFT)) & GMAC_MTL_TBS_CTRL_LEGOS_MASK)

#define GMAC_MTL_TBS_CTRL_Reserved_7_MASK        (0x80U)
#define GMAC_MTL_TBS_CTRL_Reserved_7_SHIFT       (7U)
#define GMAC_MTL_TBS_CTRL_Reserved_7_WIDTH       (1U)
#define GMAC_MTL_TBS_CTRL_Reserved_7(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TBS_CTRL_Reserved_7_SHIFT)) & GMAC_MTL_TBS_CTRL_Reserved_7_MASK)

#define GMAC_MTL_TBS_CTRL_LEOS_MASK              (0xFFFFFF00U)
#define GMAC_MTL_TBS_CTRL_LEOS_SHIFT             (8U)
#define GMAC_MTL_TBS_CTRL_LEOS_WIDTH             (24U)
#define GMAC_MTL_TBS_CTRL_LEOS(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TBS_CTRL_LEOS_SHIFT)) & GMAC_MTL_TBS_CTRL_LEOS_MASK)
/*! @} */

/*! @name MTL_EST_CONTROL -  */
/*! @{ */

#define GMAC_MTL_EST_CONTROL_EEST_MASK           (0x1U)
#define GMAC_MTL_EST_CONTROL_EEST_SHIFT          (0U)
#define GMAC_MTL_EST_CONTROL_EEST_WIDTH          (1U)
#define GMAC_MTL_EST_CONTROL_EEST(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_CONTROL_EEST_SHIFT)) & GMAC_MTL_EST_CONTROL_EEST_MASK)

#define GMAC_MTL_EST_CONTROL_SSWL_MASK           (0x2U)
#define GMAC_MTL_EST_CONTROL_SSWL_SHIFT          (1U)
#define GMAC_MTL_EST_CONTROL_SSWL_WIDTH          (1U)
#define GMAC_MTL_EST_CONTROL_SSWL(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_CONTROL_SSWL_SHIFT)) & GMAC_MTL_EST_CONTROL_SSWL_MASK)

#define GMAC_MTL_EST_CONTROL_Reserved_2_MASK     (0x4U)
#define GMAC_MTL_EST_CONTROL_Reserved_2_SHIFT    (2U)
#define GMAC_MTL_EST_CONTROL_Reserved_2_WIDTH    (1U)
#define GMAC_MTL_EST_CONTROL_Reserved_2(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_CONTROL_Reserved_2_SHIFT)) & GMAC_MTL_EST_CONTROL_Reserved_2_MASK)

#define GMAC_MTL_EST_CONTROL_QHLBF_MASK          (0x8U)
#define GMAC_MTL_EST_CONTROL_QHLBF_SHIFT         (3U)
#define GMAC_MTL_EST_CONTROL_QHLBF_WIDTH         (1U)
#define GMAC_MTL_EST_CONTROL_QHLBF(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_CONTROL_QHLBF_SHIFT)) & GMAC_MTL_EST_CONTROL_QHLBF_MASK)

#define GMAC_MTL_EST_CONTROL_DDBF_MASK           (0x10U)
#define GMAC_MTL_EST_CONTROL_DDBF_SHIFT          (4U)
#define GMAC_MTL_EST_CONTROL_DDBF_WIDTH          (1U)
#define GMAC_MTL_EST_CONTROL_DDBF(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_CONTROL_DDBF_SHIFT)) & GMAC_MTL_EST_CONTROL_DDBF_MASK)

#define GMAC_MTL_EST_CONTROL_DFBS_MASK           (0x20U)
#define GMAC_MTL_EST_CONTROL_DFBS_SHIFT          (5U)
#define GMAC_MTL_EST_CONTROL_DFBS_WIDTH          (1U)
#define GMAC_MTL_EST_CONTROL_DFBS(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_CONTROL_DFBS_SHIFT)) & GMAC_MTL_EST_CONTROL_DFBS_MASK)

#define GMAC_MTL_EST_CONTROL_LCSE_MASK           (0xC0U)
#define GMAC_MTL_EST_CONTROL_LCSE_SHIFT          (6U)
#define GMAC_MTL_EST_CONTROL_LCSE_WIDTH          (2U)
#define GMAC_MTL_EST_CONTROL_LCSE(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_CONTROL_LCSE_SHIFT)) & GMAC_MTL_EST_CONTROL_LCSE_MASK)

#define GMAC_MTL_EST_CONTROL_TILS_MASK           (0x700U)
#define GMAC_MTL_EST_CONTROL_TILS_SHIFT          (8U)
#define GMAC_MTL_EST_CONTROL_TILS_WIDTH          (3U)
#define GMAC_MTL_EST_CONTROL_TILS(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_CONTROL_TILS_SHIFT)) & GMAC_MTL_EST_CONTROL_TILS_MASK)

#define GMAC_MTL_EST_CONTROL_Reserved_11_MASK    (0x800U)
#define GMAC_MTL_EST_CONTROL_Reserved_11_SHIFT   (11U)
#define GMAC_MTL_EST_CONTROL_Reserved_11_WIDTH   (1U)
#define GMAC_MTL_EST_CONTROL_Reserved_11(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_CONTROL_Reserved_11_SHIFT)) & GMAC_MTL_EST_CONTROL_Reserved_11_MASK)

#define GMAC_MTL_EST_CONTROL_CTOV_MASK           (0xFFF000U)
#define GMAC_MTL_EST_CONTROL_CTOV_SHIFT          (12U)
#define GMAC_MTL_EST_CONTROL_CTOV_WIDTH          (12U)
#define GMAC_MTL_EST_CONTROL_CTOV(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_CONTROL_CTOV_SHIFT)) & GMAC_MTL_EST_CONTROL_CTOV_MASK)

#define GMAC_MTL_EST_CONTROL_PTOV_MASK           (0xFF000000U)
#define GMAC_MTL_EST_CONTROL_PTOV_SHIFT          (24U)
#define GMAC_MTL_EST_CONTROL_PTOV_WIDTH          (8U)
#define GMAC_MTL_EST_CONTROL_PTOV(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_CONTROL_PTOV_SHIFT)) & GMAC_MTL_EST_CONTROL_PTOV_MASK)
/*! @} */

/*! @name MTL_EST_EXT_CONTROL -  */
/*! @{ */

#define GMAC_MTL_EST_EXT_CONTROL_OVHD_MASK       (0x3FU)
#define GMAC_MTL_EST_EXT_CONTROL_OVHD_SHIFT      (0U)
#define GMAC_MTL_EST_EXT_CONTROL_OVHD_WIDTH      (6U)
#define GMAC_MTL_EST_EXT_CONTROL_OVHD(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_EXT_CONTROL_OVHD_SHIFT)) & GMAC_MTL_EST_EXT_CONTROL_OVHD_MASK)

#define GMAC_MTL_EST_EXT_CONTROL_Reserved_31_6_MASK (0xFFFFFFC0U)
#define GMAC_MTL_EST_EXT_CONTROL_Reserved_31_6_SHIFT (6U)
#define GMAC_MTL_EST_EXT_CONTROL_Reserved_31_6_WIDTH (26U)
#define GMAC_MTL_EST_EXT_CONTROL_Reserved_31_6(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_EXT_CONTROL_Reserved_31_6_SHIFT)) & GMAC_MTL_EST_EXT_CONTROL_Reserved_31_6_MASK)
/*! @} */

/*! @name MTL_EST_STATUS -  */
/*! @{ */

#define GMAC_MTL_EST_STATUS_SWLC_MASK            (0x1U)
#define GMAC_MTL_EST_STATUS_SWLC_SHIFT           (0U)
#define GMAC_MTL_EST_STATUS_SWLC_WIDTH           (1U)
#define GMAC_MTL_EST_STATUS_SWLC(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_STATUS_SWLC_SHIFT)) & GMAC_MTL_EST_STATUS_SWLC_MASK)

#define GMAC_MTL_EST_STATUS_BTRE_MASK            (0x2U)
#define GMAC_MTL_EST_STATUS_BTRE_SHIFT           (1U)
#define GMAC_MTL_EST_STATUS_BTRE_WIDTH           (1U)
#define GMAC_MTL_EST_STATUS_BTRE(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_STATUS_BTRE_SHIFT)) & GMAC_MTL_EST_STATUS_BTRE_MASK)

#define GMAC_MTL_EST_STATUS_HLBF_MASK            (0x4U)
#define GMAC_MTL_EST_STATUS_HLBF_SHIFT           (2U)
#define GMAC_MTL_EST_STATUS_HLBF_WIDTH           (1U)
#define GMAC_MTL_EST_STATUS_HLBF(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_STATUS_HLBF_SHIFT)) & GMAC_MTL_EST_STATUS_HLBF_MASK)

#define GMAC_MTL_EST_STATUS_HLBS_MASK            (0x8U)
#define GMAC_MTL_EST_STATUS_HLBS_SHIFT           (3U)
#define GMAC_MTL_EST_STATUS_HLBS_WIDTH           (1U)
#define GMAC_MTL_EST_STATUS_HLBS(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_STATUS_HLBS_SHIFT)) & GMAC_MTL_EST_STATUS_HLBS_MASK)

#define GMAC_MTL_EST_STATUS_CGCE_MASK            (0x10U)
#define GMAC_MTL_EST_STATUS_CGCE_SHIFT           (4U)
#define GMAC_MTL_EST_STATUS_CGCE_WIDTH           (1U)
#define GMAC_MTL_EST_STATUS_CGCE(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_STATUS_CGCE_SHIFT)) & GMAC_MTL_EST_STATUS_CGCE_MASK)

#define GMAC_MTL_EST_STATUS_Reserved_6_5_MASK    (0x60U)
#define GMAC_MTL_EST_STATUS_Reserved_6_5_SHIFT   (5U)
#define GMAC_MTL_EST_STATUS_Reserved_6_5_WIDTH   (2U)
#define GMAC_MTL_EST_STATUS_Reserved_6_5(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_STATUS_Reserved_6_5_SHIFT)) & GMAC_MTL_EST_STATUS_Reserved_6_5_MASK)

#define GMAC_MTL_EST_STATUS_SWOL_MASK            (0x80U)
#define GMAC_MTL_EST_STATUS_SWOL_SHIFT           (7U)
#define GMAC_MTL_EST_STATUS_SWOL_WIDTH           (1U)
#define GMAC_MTL_EST_STATUS_SWOL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_STATUS_SWOL_SHIFT)) & GMAC_MTL_EST_STATUS_SWOL_MASK)

#define GMAC_MTL_EST_STATUS_BTRL_MASK            (0xFF00U)
#define GMAC_MTL_EST_STATUS_BTRL_SHIFT           (8U)
#define GMAC_MTL_EST_STATUS_BTRL_WIDTH           (8U)
#define GMAC_MTL_EST_STATUS_BTRL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_STATUS_BTRL_SHIFT)) & GMAC_MTL_EST_STATUS_BTRL_MASK)

#define GMAC_MTL_EST_STATUS_CGSN_MASK            (0xF0000U)
#define GMAC_MTL_EST_STATUS_CGSN_SHIFT           (16U)
#define GMAC_MTL_EST_STATUS_CGSN_WIDTH           (4U)
#define GMAC_MTL_EST_STATUS_CGSN(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_STATUS_CGSN_SHIFT)) & GMAC_MTL_EST_STATUS_CGSN_MASK)

#define GMAC_MTL_EST_STATUS_Reserved_31_20_MASK  (0xFFF00000U)
#define GMAC_MTL_EST_STATUS_Reserved_31_20_SHIFT (20U)
#define GMAC_MTL_EST_STATUS_Reserved_31_20_WIDTH (12U)
#define GMAC_MTL_EST_STATUS_Reserved_31_20(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_STATUS_Reserved_31_20_SHIFT)) & GMAC_MTL_EST_STATUS_Reserved_31_20_MASK)
/*! @} */

/*! @name MTL_EST_SCH_ERROR -  */
/*! @{ */

#define GMAC_MTL_EST_SCH_ERROR_SEQN_MASK         (0x7U)
#define GMAC_MTL_EST_SCH_ERROR_SEQN_SHIFT        (0U)
#define GMAC_MTL_EST_SCH_ERROR_SEQN_WIDTH        (3U)
#define GMAC_MTL_EST_SCH_ERROR_SEQN(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_SCH_ERROR_SEQN_SHIFT)) & GMAC_MTL_EST_SCH_ERROR_SEQN_MASK)

#define GMAC_MTL_EST_SCH_ERROR_Reserved_31_x_MASK (0xFFFFFFF8U)
#define GMAC_MTL_EST_SCH_ERROR_Reserved_31_x_SHIFT (3U)
#define GMAC_MTL_EST_SCH_ERROR_Reserved_31_x_WIDTH (29U)
#define GMAC_MTL_EST_SCH_ERROR_Reserved_31_x(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_SCH_ERROR_Reserved_31_x_SHIFT)) & GMAC_MTL_EST_SCH_ERROR_Reserved_31_x_MASK)
/*! @} */

/*! @name MTL_EST_FRM_SIZE_ERROR -  */
/*! @{ */

#define GMAC_MTL_EST_FRM_SIZE_ERROR_FEQN_MASK    (0x7U)
#define GMAC_MTL_EST_FRM_SIZE_ERROR_FEQN_SHIFT   (0U)
#define GMAC_MTL_EST_FRM_SIZE_ERROR_FEQN_WIDTH   (3U)
#define GMAC_MTL_EST_FRM_SIZE_ERROR_FEQN(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_FRM_SIZE_ERROR_FEQN_SHIFT)) & GMAC_MTL_EST_FRM_SIZE_ERROR_FEQN_MASK)

#define GMAC_MTL_EST_FRM_SIZE_ERROR_Reserved_31_x_MASK (0xFFFFFFF8U)
#define GMAC_MTL_EST_FRM_SIZE_ERROR_Reserved_31_x_SHIFT (3U)
#define GMAC_MTL_EST_FRM_SIZE_ERROR_Reserved_31_x_WIDTH (29U)
#define GMAC_MTL_EST_FRM_SIZE_ERROR_Reserved_31_x(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_FRM_SIZE_ERROR_Reserved_31_x_SHIFT)) & GMAC_MTL_EST_FRM_SIZE_ERROR_Reserved_31_x_MASK)
/*! @} */

/*! @name MTL_EST_FRM_SIZE_CAPTURE -  */
/*! @{ */

#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFS_MASK  (0x7FFFU)
#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFS_SHIFT (0U)
#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFS_WIDTH (15U)
#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFS(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFS_SHIFT)) & GMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFS_MASK)

#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_Reserved_15_MASK (0x8000U)
#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_Reserved_15_SHIFT (15U)
#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_Reserved_15_WIDTH (1U)
#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_Reserved_15(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_FRM_SIZE_CAPTURE_Reserved_15_SHIFT)) & GMAC_MTL_EST_FRM_SIZE_CAPTURE_Reserved_15_MASK)

#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_MASK  (0x30000U)
#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_SHIFT (16U)
#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_WIDTH (2U)
#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFQ(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_SHIFT)) & GMAC_MTL_EST_FRM_SIZE_CAPTURE_HBFQ_MASK)

#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_Reserved_31_x_MASK (0xFFFC0000U)
#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_Reserved_31_x_SHIFT (18U)
#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_Reserved_31_x_WIDTH (14U)
#define GMAC_MTL_EST_FRM_SIZE_CAPTURE_Reserved_31_x(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_FRM_SIZE_CAPTURE_Reserved_31_x_SHIFT)) & GMAC_MTL_EST_FRM_SIZE_CAPTURE_Reserved_31_x_MASK)
/*! @} */

/*! @name MTL_EST_INTR_ENABLE -  */
/*! @{ */

#define GMAC_MTL_EST_INTR_ENABLE_IECC_MASK       (0x1U)
#define GMAC_MTL_EST_INTR_ENABLE_IECC_SHIFT      (0U)
#define GMAC_MTL_EST_INTR_ENABLE_IECC_WIDTH      (1U)
#define GMAC_MTL_EST_INTR_ENABLE_IECC(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_INTR_ENABLE_IECC_SHIFT)) & GMAC_MTL_EST_INTR_ENABLE_IECC_MASK)

#define GMAC_MTL_EST_INTR_ENABLE_IEBE_MASK       (0x2U)
#define GMAC_MTL_EST_INTR_ENABLE_IEBE_SHIFT      (1U)
#define GMAC_MTL_EST_INTR_ENABLE_IEBE_WIDTH      (1U)
#define GMAC_MTL_EST_INTR_ENABLE_IEBE(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_INTR_ENABLE_IEBE_SHIFT)) & GMAC_MTL_EST_INTR_ENABLE_IEBE_MASK)

#define GMAC_MTL_EST_INTR_ENABLE_IEHF_MASK       (0x4U)
#define GMAC_MTL_EST_INTR_ENABLE_IEHF_SHIFT      (2U)
#define GMAC_MTL_EST_INTR_ENABLE_IEHF_WIDTH      (1U)
#define GMAC_MTL_EST_INTR_ENABLE_IEHF(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_INTR_ENABLE_IEHF_SHIFT)) & GMAC_MTL_EST_INTR_ENABLE_IEHF_MASK)

#define GMAC_MTL_EST_INTR_ENABLE_IEHS_MASK       (0x8U)
#define GMAC_MTL_EST_INTR_ENABLE_IEHS_SHIFT      (3U)
#define GMAC_MTL_EST_INTR_ENABLE_IEHS_WIDTH      (1U)
#define GMAC_MTL_EST_INTR_ENABLE_IEHS(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_INTR_ENABLE_IEHS_SHIFT)) & GMAC_MTL_EST_INTR_ENABLE_IEHS_MASK)

#define GMAC_MTL_EST_INTR_ENABLE_CGCE_MASK       (0x10U)
#define GMAC_MTL_EST_INTR_ENABLE_CGCE_SHIFT      (4U)
#define GMAC_MTL_EST_INTR_ENABLE_CGCE_WIDTH      (1U)
#define GMAC_MTL_EST_INTR_ENABLE_CGCE(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_INTR_ENABLE_CGCE_SHIFT)) & GMAC_MTL_EST_INTR_ENABLE_CGCE_MASK)

#define GMAC_MTL_EST_INTR_ENABLE_Reserved_31_5_MASK (0xFFFFFFE0U)
#define GMAC_MTL_EST_INTR_ENABLE_Reserved_31_5_SHIFT (5U)
#define GMAC_MTL_EST_INTR_ENABLE_Reserved_31_5_WIDTH (27U)
#define GMAC_MTL_EST_INTR_ENABLE_Reserved_31_5(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_INTR_ENABLE_Reserved_31_5_SHIFT)) & GMAC_MTL_EST_INTR_ENABLE_Reserved_31_5_MASK)
/*! @} */

/*! @name MTL_EST_GCL_CONTROL -  */
/*! @{ */

#define GMAC_MTL_EST_GCL_CONTROL_SRWO_MASK       (0x1U)
#define GMAC_MTL_EST_GCL_CONTROL_SRWO_SHIFT      (0U)
#define GMAC_MTL_EST_GCL_CONTROL_SRWO_WIDTH      (1U)
#define GMAC_MTL_EST_GCL_CONTROL_SRWO(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_GCL_CONTROL_SRWO_SHIFT)) & GMAC_MTL_EST_GCL_CONTROL_SRWO_MASK)

#define GMAC_MTL_EST_GCL_CONTROL_R1W0_MASK       (0x2U)
#define GMAC_MTL_EST_GCL_CONTROL_R1W0_SHIFT      (1U)
#define GMAC_MTL_EST_GCL_CONTROL_R1W0_WIDTH      (1U)
#define GMAC_MTL_EST_GCL_CONTROL_R1W0(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_GCL_CONTROL_R1W0_SHIFT)) & GMAC_MTL_EST_GCL_CONTROL_R1W0_MASK)

#define GMAC_MTL_EST_GCL_CONTROL_GCRR_MASK       (0x4U)
#define GMAC_MTL_EST_GCL_CONTROL_GCRR_SHIFT      (2U)
#define GMAC_MTL_EST_GCL_CONTROL_GCRR_WIDTH      (1U)
#define GMAC_MTL_EST_GCL_CONTROL_GCRR(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_GCL_CONTROL_GCRR_SHIFT)) & GMAC_MTL_EST_GCL_CONTROL_GCRR_MASK)

#define GMAC_MTL_EST_GCL_CONTROL_Reserved_3_MASK (0x8U)
#define GMAC_MTL_EST_GCL_CONTROL_Reserved_3_SHIFT (3U)
#define GMAC_MTL_EST_GCL_CONTROL_Reserved_3_WIDTH (1U)
#define GMAC_MTL_EST_GCL_CONTROL_Reserved_3(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_GCL_CONTROL_Reserved_3_SHIFT)) & GMAC_MTL_EST_GCL_CONTROL_Reserved_3_MASK)

#define GMAC_MTL_EST_GCL_CONTROL_DBGM_MASK       (0x10U)
#define GMAC_MTL_EST_GCL_CONTROL_DBGM_SHIFT      (4U)
#define GMAC_MTL_EST_GCL_CONTROL_DBGM_WIDTH      (1U)
#define GMAC_MTL_EST_GCL_CONTROL_DBGM(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_GCL_CONTROL_DBGM_SHIFT)) & GMAC_MTL_EST_GCL_CONTROL_DBGM_MASK)

#define GMAC_MTL_EST_GCL_CONTROL_DBGB_MASK       (0x20U)
#define GMAC_MTL_EST_GCL_CONTROL_DBGB_SHIFT      (5U)
#define GMAC_MTL_EST_GCL_CONTROL_DBGB_WIDTH      (1U)
#define GMAC_MTL_EST_GCL_CONTROL_DBGB(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_GCL_CONTROL_DBGB_SHIFT)) & GMAC_MTL_EST_GCL_CONTROL_DBGB_MASK)

#define GMAC_MTL_EST_GCL_CONTROL_Reserved_7_6_MASK (0xC0U)
#define GMAC_MTL_EST_GCL_CONTROL_Reserved_7_6_SHIFT (6U)
#define GMAC_MTL_EST_GCL_CONTROL_Reserved_7_6_WIDTH (2U)
#define GMAC_MTL_EST_GCL_CONTROL_Reserved_7_6(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_GCL_CONTROL_Reserved_7_6_SHIFT)) & GMAC_MTL_EST_GCL_CONTROL_Reserved_7_6_MASK)

#define GMAC_MTL_EST_GCL_CONTROL_ADDR_MASK       (0xFF00U)
#define GMAC_MTL_EST_GCL_CONTROL_ADDR_SHIFT      (8U)
#define GMAC_MTL_EST_GCL_CONTROL_ADDR_WIDTH      (8U)
#define GMAC_MTL_EST_GCL_CONTROL_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_GCL_CONTROL_ADDR_SHIFT)) & GMAC_MTL_EST_GCL_CONTROL_ADDR_MASK)

#define GMAC_MTL_EST_GCL_CONTROL_Reserved_20_y_MASK (0x1F0000U)
#define GMAC_MTL_EST_GCL_CONTROL_Reserved_20_y_SHIFT (16U)
#define GMAC_MTL_EST_GCL_CONTROL_Reserved_20_y_WIDTH (5U)
#define GMAC_MTL_EST_GCL_CONTROL_Reserved_20_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_GCL_CONTROL_Reserved_20_y_SHIFT)) & GMAC_MTL_EST_GCL_CONTROL_Reserved_20_y_MASK)

#define GMAC_MTL_EST_GCL_CONTROL_ESTEIEE_MASK    (0x200000U)
#define GMAC_MTL_EST_GCL_CONTROL_ESTEIEE_SHIFT   (21U)
#define GMAC_MTL_EST_GCL_CONTROL_ESTEIEE_WIDTH   (1U)
#define GMAC_MTL_EST_GCL_CONTROL_ESTEIEE(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_GCL_CONTROL_ESTEIEE_SHIFT)) & GMAC_MTL_EST_GCL_CONTROL_ESTEIEE_MASK)

#define GMAC_MTL_EST_GCL_CONTROL_ESTEIAEE_MASK   (0x400000U)
#define GMAC_MTL_EST_GCL_CONTROL_ESTEIAEE_SHIFT  (22U)
#define GMAC_MTL_EST_GCL_CONTROL_ESTEIAEE_WIDTH  (1U)
#define GMAC_MTL_EST_GCL_CONTROL_ESTEIAEE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_GCL_CONTROL_ESTEIAEE_SHIFT)) & GMAC_MTL_EST_GCL_CONTROL_ESTEIAEE_MASK)

#define GMAC_MTL_EST_GCL_CONTROL_ESTEIEC_MASK    (0x800000U)
#define GMAC_MTL_EST_GCL_CONTROL_ESTEIEC_SHIFT   (23U)
#define GMAC_MTL_EST_GCL_CONTROL_ESTEIEC_WIDTH   (1U)
#define GMAC_MTL_EST_GCL_CONTROL_ESTEIEC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_GCL_CONTROL_ESTEIEC_SHIFT)) & GMAC_MTL_EST_GCL_CONTROL_ESTEIEC_MASK)

#define GMAC_MTL_EST_GCL_CONTROL_Reserved_31_24_MASK (0xFF000000U)
#define GMAC_MTL_EST_GCL_CONTROL_Reserved_31_24_SHIFT (24U)
#define GMAC_MTL_EST_GCL_CONTROL_Reserved_31_24_WIDTH (8U)
#define GMAC_MTL_EST_GCL_CONTROL_Reserved_31_24(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_GCL_CONTROL_Reserved_31_24_SHIFT)) & GMAC_MTL_EST_GCL_CONTROL_Reserved_31_24_MASK)
/*! @} */

/*! @name MTL_EST_GCL_DATA -  */
/*! @{ */

#define GMAC_MTL_EST_GCL_DATA_GCD_MASK           (0xFFFFFFFFU)
#define GMAC_MTL_EST_GCL_DATA_GCD_SHIFT          (0U)
#define GMAC_MTL_EST_GCL_DATA_GCD_WIDTH          (32U)
#define GMAC_MTL_EST_GCL_DATA_GCD(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_EST_GCL_DATA_GCD_SHIFT)) & GMAC_MTL_EST_GCL_DATA_GCD_MASK)
/*! @} */

/*! @name MTL_FPE_CTRL_STS -  */
/*! @{ */

#define GMAC_MTL_FPE_CTRL_STS_AFSZ_MASK          (0x3U)
#define GMAC_MTL_FPE_CTRL_STS_AFSZ_SHIFT         (0U)
#define GMAC_MTL_FPE_CTRL_STS_AFSZ_WIDTH         (2U)
#define GMAC_MTL_FPE_CTRL_STS_AFSZ(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_FPE_CTRL_STS_AFSZ_SHIFT)) & GMAC_MTL_FPE_CTRL_STS_AFSZ_MASK)

#define GMAC_MTL_FPE_CTRL_STS_Reserved_7_2_MASK  (0xFCU)
#define GMAC_MTL_FPE_CTRL_STS_Reserved_7_2_SHIFT (2U)
#define GMAC_MTL_FPE_CTRL_STS_Reserved_7_2_WIDTH (6U)
#define GMAC_MTL_FPE_CTRL_STS_Reserved_7_2(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_FPE_CTRL_STS_Reserved_7_2_SHIFT)) & GMAC_MTL_FPE_CTRL_STS_Reserved_7_2_MASK)

#define GMAC_MTL_FPE_CTRL_STS_PEC_MASK           (0x700U)
#define GMAC_MTL_FPE_CTRL_STS_PEC_SHIFT          (8U)
#define GMAC_MTL_FPE_CTRL_STS_PEC_WIDTH          (3U)
#define GMAC_MTL_FPE_CTRL_STS_PEC(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_FPE_CTRL_STS_PEC_SHIFT)) & GMAC_MTL_FPE_CTRL_STS_PEC_MASK)

#define GMAC_MTL_FPE_CTRL_STS_Reserved_15_y_MASK (0xF800U)
#define GMAC_MTL_FPE_CTRL_STS_Reserved_15_y_SHIFT (11U)
#define GMAC_MTL_FPE_CTRL_STS_Reserved_15_y_WIDTH (5U)
#define GMAC_MTL_FPE_CTRL_STS_Reserved_15_y(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_FPE_CTRL_STS_Reserved_15_y_SHIFT)) & GMAC_MTL_FPE_CTRL_STS_Reserved_15_y_MASK)

#define GMAC_MTL_FPE_CTRL_STS_Reserved_27_16_MASK (0xFFF0000U)
#define GMAC_MTL_FPE_CTRL_STS_Reserved_27_16_SHIFT (16U)
#define GMAC_MTL_FPE_CTRL_STS_Reserved_27_16_WIDTH (12U)
#define GMAC_MTL_FPE_CTRL_STS_Reserved_27_16(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_FPE_CTRL_STS_Reserved_27_16_SHIFT)) & GMAC_MTL_FPE_CTRL_STS_Reserved_27_16_MASK)

#define GMAC_MTL_FPE_CTRL_STS_HRS_MASK           (0x10000000U)
#define GMAC_MTL_FPE_CTRL_STS_HRS_SHIFT          (28U)
#define GMAC_MTL_FPE_CTRL_STS_HRS_WIDTH          (1U)
#define GMAC_MTL_FPE_CTRL_STS_HRS(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_FPE_CTRL_STS_HRS_SHIFT)) & GMAC_MTL_FPE_CTRL_STS_HRS_MASK)

#define GMAC_MTL_FPE_CTRL_STS_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MTL_FPE_CTRL_STS_Reserved_31_29_SHIFT (29U)
#define GMAC_MTL_FPE_CTRL_STS_Reserved_31_29_WIDTH (3U)
#define GMAC_MTL_FPE_CTRL_STS_Reserved_31_29(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_FPE_CTRL_STS_Reserved_31_29_SHIFT)) & GMAC_MTL_FPE_CTRL_STS_Reserved_31_29_MASK)
/*! @} */

/*! @name MTL_FPE_ADVANCE -  */
/*! @{ */

#define GMAC_MTL_FPE_ADVANCE_HADV_MASK           (0xFFFFU)
#define GMAC_MTL_FPE_ADVANCE_HADV_SHIFT          (0U)
#define GMAC_MTL_FPE_ADVANCE_HADV_WIDTH          (16U)
#define GMAC_MTL_FPE_ADVANCE_HADV(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_FPE_ADVANCE_HADV_SHIFT)) & GMAC_MTL_FPE_ADVANCE_HADV_MASK)

#define GMAC_MTL_FPE_ADVANCE_RADV_MASK           (0xFFFF0000U)
#define GMAC_MTL_FPE_ADVANCE_RADV_SHIFT          (16U)
#define GMAC_MTL_FPE_ADVANCE_RADV_WIDTH          (16U)
#define GMAC_MTL_FPE_ADVANCE_RADV(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_FPE_ADVANCE_RADV_SHIFT)) & GMAC_MTL_FPE_ADVANCE_RADV_MASK)
/*! @} */

/*! @name MTL_RXP_CONTROL_STATUS -  */
/*! @{ */

#define GMAC_MTL_RXP_CONTROL_STATUS_NVE_MASK     (0x3FU)
#define GMAC_MTL_RXP_CONTROL_STATUS_NVE_SHIFT    (0U)
#define GMAC_MTL_RXP_CONTROL_STATUS_NVE_WIDTH    (6U)
#define GMAC_MTL_RXP_CONTROL_STATUS_NVE(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_CONTROL_STATUS_NVE_SHIFT)) & GMAC_MTL_RXP_CONTROL_STATUS_NVE_MASK)

#define GMAC_MTL_RXP_CONTROL_STATUS_Reserved_15_x_MASK (0xFFC0U)
#define GMAC_MTL_RXP_CONTROL_STATUS_Reserved_15_x_SHIFT (6U)
#define GMAC_MTL_RXP_CONTROL_STATUS_Reserved_15_x_WIDTH (10U)
#define GMAC_MTL_RXP_CONTROL_STATUS_Reserved_15_x(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_CONTROL_STATUS_Reserved_15_x_SHIFT)) & GMAC_MTL_RXP_CONTROL_STATUS_Reserved_15_x_MASK)

#define GMAC_MTL_RXP_CONTROL_STATUS_NPE_MASK     (0x3F0000U)
#define GMAC_MTL_RXP_CONTROL_STATUS_NPE_SHIFT    (16U)
#define GMAC_MTL_RXP_CONTROL_STATUS_NPE_WIDTH    (6U)
#define GMAC_MTL_RXP_CONTROL_STATUS_NPE(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_CONTROL_STATUS_NPE_SHIFT)) & GMAC_MTL_RXP_CONTROL_STATUS_NPE_MASK)

#define GMAC_MTL_RXP_CONTROL_STATUS_Reserved_29_x_MASK (0x3FC00000U)
#define GMAC_MTL_RXP_CONTROL_STATUS_Reserved_29_x_SHIFT (22U)
#define GMAC_MTL_RXP_CONTROL_STATUS_Reserved_29_x_WIDTH (8U)
#define GMAC_MTL_RXP_CONTROL_STATUS_Reserved_29_x(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_CONTROL_STATUS_Reserved_29_x_SHIFT)) & GMAC_MTL_RXP_CONTROL_STATUS_Reserved_29_x_MASK)

#define GMAC_MTL_RXP_CONTROL_STATUS_ELIRS_MASK   (0x40000000U)
#define GMAC_MTL_RXP_CONTROL_STATUS_ELIRS_SHIFT  (30U)
#define GMAC_MTL_RXP_CONTROL_STATUS_ELIRS_WIDTH  (1U)
#define GMAC_MTL_RXP_CONTROL_STATUS_ELIRS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_CONTROL_STATUS_ELIRS_SHIFT)) & GMAC_MTL_RXP_CONTROL_STATUS_ELIRS_MASK)

#define GMAC_MTL_RXP_CONTROL_STATUS_RXPI_MASK    (0x80000000U)
#define GMAC_MTL_RXP_CONTROL_STATUS_RXPI_SHIFT   (31U)
#define GMAC_MTL_RXP_CONTROL_STATUS_RXPI_WIDTH   (1U)
#define GMAC_MTL_RXP_CONTROL_STATUS_RXPI(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_CONTROL_STATUS_RXPI_SHIFT)) & GMAC_MTL_RXP_CONTROL_STATUS_RXPI_MASK)
/*! @} */

/*! @name MTL_RXP_INTERRUPT_CONTROL_STATUS -  */
/*! @{ */

#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS_MASK (0x1U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS_SHIFT (0U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS_WIDTH (1U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS_SHIFT)) & GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIS_MASK)

#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS_MASK (0x2U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS_SHIFT (1U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS_WIDTH (1U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS_SHIFT)) & GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIS_MASK)

#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS_MASK (0x4U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS_SHIFT (2U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS_WIDTH (1U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS_SHIFT)) & GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIS_MASK)

#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS_MASK (0x8U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS_SHIFT (3U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS_WIDTH (1U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS_SHIFT)) & GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIS_MASK)

#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_Reserved_15_4_MASK (0xFFF0U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_Reserved_15_4_SHIFT (4U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_Reserved_15_4_WIDTH (12U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_Reserved_15_4(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_Reserved_15_4_SHIFT)) & GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_Reserved_15_4_MASK)

#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE_MASK (0x10000U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE_SHIFT (16U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE_WIDTH (1U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE_SHIFT)) & GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NVEOVIE_MASK)

#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE_MASK (0x20000U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE_SHIFT (17U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE_WIDTH (1U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE_SHIFT)) & GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_NPEOVIE_MASK)

#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE_MASK (0x40000U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE_SHIFT (18U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE_WIDTH (1U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE_SHIFT)) & GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_FOOVIE_MASK)

#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE_MASK (0x80000U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE_SHIFT (19U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE_WIDTH (1U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE_SHIFT)) & GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_PDRFIE_MASK)

#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_Reserved_31_20_MASK (0xFFF00000U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_Reserved_31_20_SHIFT (20U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_Reserved_31_20_WIDTH (12U)
#define GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_Reserved_31_20(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_Reserved_31_20_SHIFT)) & GMAC_MTL_RXP_INTERRUPT_CONTROL_STATUS_Reserved_31_20_MASK)
/*! @} */

/*! @name MTL_RXP_DROP_CNT -  */
/*! @{ */

#define GMAC_MTL_RXP_DROP_CNT_RXPDC_MASK         (0x7FFFFFFFU)
#define GMAC_MTL_RXP_DROP_CNT_RXPDC_SHIFT        (0U)
#define GMAC_MTL_RXP_DROP_CNT_RXPDC_WIDTH        (31U)
#define GMAC_MTL_RXP_DROP_CNT_RXPDC(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_DROP_CNT_RXPDC_SHIFT)) & GMAC_MTL_RXP_DROP_CNT_RXPDC_MASK)

#define GMAC_MTL_RXP_DROP_CNT_RXPDCOVF_MASK      (0x80000000U)
#define GMAC_MTL_RXP_DROP_CNT_RXPDCOVF_SHIFT     (31U)
#define GMAC_MTL_RXP_DROP_CNT_RXPDCOVF_WIDTH     (1U)
#define GMAC_MTL_RXP_DROP_CNT_RXPDCOVF(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_DROP_CNT_RXPDCOVF_SHIFT)) & GMAC_MTL_RXP_DROP_CNT_RXPDCOVF_MASK)
/*! @} */

/*! @name MTL_RXP_ERROR_CNT -  */
/*! @{ */

#define GMAC_MTL_RXP_ERROR_CNT_RXPEC_MASK        (0x7FFFFFFFU)
#define GMAC_MTL_RXP_ERROR_CNT_RXPEC_SHIFT       (0U)
#define GMAC_MTL_RXP_ERROR_CNT_RXPEC_WIDTH       (31U)
#define GMAC_MTL_RXP_ERROR_CNT_RXPEC(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_ERROR_CNT_RXPEC_SHIFT)) & GMAC_MTL_RXP_ERROR_CNT_RXPEC_MASK)

#define GMAC_MTL_RXP_ERROR_CNT_RXPECOVF_MASK     (0x80000000U)
#define GMAC_MTL_RXP_ERROR_CNT_RXPECOVF_SHIFT    (31U)
#define GMAC_MTL_RXP_ERROR_CNT_RXPECOVF_WIDTH    (1U)
#define GMAC_MTL_RXP_ERROR_CNT_RXPECOVF(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_ERROR_CNT_RXPECOVF_SHIFT)) & GMAC_MTL_RXP_ERROR_CNT_RXPECOVF_MASK)
/*! @} */

/*! @name MTL_RXP_INDIRECT_ACC_CONTROL_STATUS -  */
/*! @{ */

#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR_MASK (0xFFU)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR_SHIFT (0U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR_WIDTH (8U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR_SHIFT)) & GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_ADDR_MASK)

#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_15_x_MASK (0xFF00U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_15_x_SHIFT (8U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_15_x_WIDTH (8U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_15_x(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_15_x_SHIFT)) & GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_15_x_MASK)

#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN_MASK (0x10000U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN_SHIFT (16U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN_WIDTH (1U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN_SHIFT)) & GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_WRRDN_MASK)

#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_19_17_MASK (0xE0000U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_19_17_SHIFT (17U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_19_17_WIDTH (3U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_19_17(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_19_17_SHIFT)) & GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_19_17_MASK)

#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE_MASK (0x100000U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE_SHIFT (20U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE_WIDTH (1U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE_SHIFT)) & GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEE_MASK)

#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIAEE_MASK (0x200000U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIAEE_SHIFT (21U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIAEE_WIDTH (1U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIAEE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIAEE_SHIFT)) & GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIAEE_MASK)

#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC_MASK (0x400000U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC_SHIFT (22U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC_WIDTH (1U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC_SHIFT)) & GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_RXPEIEC_MASK)

#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_30_23_MASK (0x7F800000U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_30_23_SHIFT (23U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_30_23_WIDTH (8U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_30_23(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_30_23_SHIFT)) & GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_Reserved_30_23_MASK)

#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY_MASK (0x80000000U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY_SHIFT (31U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY_WIDTH (1U)
#define GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY_SHIFT)) & GMAC_MTL_RXP_INDIRECT_ACC_CONTROL_STATUS_STARTBUSY_MASK)
/*! @} */

/*! @name MTL_RXP_INDIRECT_ACC_DATA -  */
/*! @{ */

#define GMAC_MTL_RXP_INDIRECT_ACC_DATA_DATA_MASK (0xFFFFFFFFU)
#define GMAC_MTL_RXP_INDIRECT_ACC_DATA_DATA_SHIFT (0U)
#define GMAC_MTL_RXP_INDIRECT_ACC_DATA_DATA_WIDTH (32U)
#define GMAC_MTL_RXP_INDIRECT_ACC_DATA_DATA(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_INDIRECT_ACC_DATA_DATA_SHIFT)) & GMAC_MTL_RXP_INDIRECT_ACC_DATA_DATA_MASK)
/*! @} */

/*! @name MTL_RXP_BYPASS_CNT -  */
/*! @{ */

#define GMAC_MTL_RXP_BYPASS_CNT_RXPBC_MASK       (0x7FFFFFFFU)
#define GMAC_MTL_RXP_BYPASS_CNT_RXPBC_SHIFT      (0U)
#define GMAC_MTL_RXP_BYPASS_CNT_RXPBC_WIDTH      (31U)
#define GMAC_MTL_RXP_BYPASS_CNT_RXPBC(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_BYPASS_CNT_RXPBC_SHIFT)) & GMAC_MTL_RXP_BYPASS_CNT_RXPBC_MASK)

#define GMAC_MTL_RXP_BYPASS_CNT_RXPBCOF_MASK     (0x80000000U)
#define GMAC_MTL_RXP_BYPASS_CNT_RXPBCOF_SHIFT    (31U)
#define GMAC_MTL_RXP_BYPASS_CNT_RXPBCOF_WIDTH    (1U)
#define GMAC_MTL_RXP_BYPASS_CNT_RXPBCOF(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXP_BYPASS_CNT_RXPBCOF_SHIFT)) & GMAC_MTL_RXP_BYPASS_CNT_RXPBCOF_MASK)
/*! @} */

/*! @name MTL_ECC_CONTROL -  */
/*! @{ */

#define GMAC_MTL_ECC_CONTROL_MTXEE_MASK          (0x1U)
#define GMAC_MTL_ECC_CONTROL_MTXEE_SHIFT         (0U)
#define GMAC_MTL_ECC_CONTROL_MTXEE_WIDTH         (1U)
#define GMAC_MTL_ECC_CONTROL_MTXEE(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_CONTROL_MTXEE_SHIFT)) & GMAC_MTL_ECC_CONTROL_MTXEE_MASK)

#define GMAC_MTL_ECC_CONTROL_MRXEE_MASK          (0x2U)
#define GMAC_MTL_ECC_CONTROL_MRXEE_SHIFT         (1U)
#define GMAC_MTL_ECC_CONTROL_MRXEE_WIDTH         (1U)
#define GMAC_MTL_ECC_CONTROL_MRXEE(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_CONTROL_MRXEE_SHIFT)) & GMAC_MTL_ECC_CONTROL_MRXEE_MASK)

#define GMAC_MTL_ECC_CONTROL_MESTEE_MASK         (0x4U)
#define GMAC_MTL_ECC_CONTROL_MESTEE_SHIFT        (2U)
#define GMAC_MTL_ECC_CONTROL_MESTEE_WIDTH        (1U)
#define GMAC_MTL_ECC_CONTROL_MESTEE(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_CONTROL_MESTEE_SHIFT)) & GMAC_MTL_ECC_CONTROL_MESTEE_MASK)

#define GMAC_MTL_ECC_CONTROL_MRXPEE_MASK         (0x8U)
#define GMAC_MTL_ECC_CONTROL_MRXPEE_SHIFT        (3U)
#define GMAC_MTL_ECC_CONTROL_MRXPEE_WIDTH        (1U)
#define GMAC_MTL_ECC_CONTROL_MRXPEE(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_CONTROL_MRXPEE_SHIFT)) & GMAC_MTL_ECC_CONTROL_MRXPEE_MASK)

#define GMAC_MTL_ECC_CONTROL_Reserved_TSOEE_MASK (0x10U)
#define GMAC_MTL_ECC_CONTROL_Reserved_TSOEE_SHIFT (4U)
#define GMAC_MTL_ECC_CONTROL_Reserved_TSOEE_WIDTH (1U)
#define GMAC_MTL_ECC_CONTROL_Reserved_TSOEE(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_CONTROL_Reserved_TSOEE_SHIFT)) & GMAC_MTL_ECC_CONTROL_Reserved_TSOEE_MASK)

#define GMAC_MTL_ECC_CONTROL_Reserved_DSCEE_MASK (0x20U)
#define GMAC_MTL_ECC_CONTROL_Reserved_DSCEE_SHIFT (5U)
#define GMAC_MTL_ECC_CONTROL_Reserved_DSCEE_WIDTH (1U)
#define GMAC_MTL_ECC_CONTROL_Reserved_DSCEE(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_CONTROL_Reserved_DSCEE_SHIFT)) & GMAC_MTL_ECC_CONTROL_Reserved_DSCEE_MASK)

#define GMAC_MTL_ECC_CONTROL_Reserved_7_6_MASK   (0xC0U)
#define GMAC_MTL_ECC_CONTROL_Reserved_7_6_SHIFT  (6U)
#define GMAC_MTL_ECC_CONTROL_Reserved_7_6_WIDTH  (2U)
#define GMAC_MTL_ECC_CONTROL_Reserved_7_6(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_CONTROL_Reserved_7_6_SHIFT)) & GMAC_MTL_ECC_CONTROL_Reserved_7_6_MASK)

#define GMAC_MTL_ECC_CONTROL_MEEAO_MASK          (0x100U)
#define GMAC_MTL_ECC_CONTROL_MEEAO_SHIFT         (8U)
#define GMAC_MTL_ECC_CONTROL_MEEAO_WIDTH         (1U)
#define GMAC_MTL_ECC_CONTROL_MEEAO(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_CONTROL_MEEAO_SHIFT)) & GMAC_MTL_ECC_CONTROL_MEEAO_MASK)

#define GMAC_MTL_ECC_CONTROL_Reserved_31_9_MASK  (0xFFFFFE00U)
#define GMAC_MTL_ECC_CONTROL_Reserved_31_9_SHIFT (9U)
#define GMAC_MTL_ECC_CONTROL_Reserved_31_9_WIDTH (23U)
#define GMAC_MTL_ECC_CONTROL_Reserved_31_9(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_CONTROL_Reserved_31_9_SHIFT)) & GMAC_MTL_ECC_CONTROL_Reserved_31_9_MASK)
/*! @} */

/*! @name MTL_SAFETY_INTERRUPT_STATUS -  */
/*! @{ */

#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_MECIS_MASK (0x1U)
#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_MECIS_SHIFT (0U)
#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_MECIS_WIDTH (1U)
#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_MECIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_SAFETY_INTERRUPT_STATUS_MECIS_SHIFT)) & GMAC_MTL_SAFETY_INTERRUPT_STATUS_MECIS_MASK)

#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_MEUIS_MASK (0x2U)
#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_MEUIS_SHIFT (1U)
#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_MEUIS_WIDTH (1U)
#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_MEUIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_SAFETY_INTERRUPT_STATUS_MEUIS_SHIFT)) & GMAC_MTL_SAFETY_INTERRUPT_STATUS_MEUIS_MASK)

#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_Reserved_30_2_MASK (0x7FFFFFFCU)
#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_Reserved_30_2_SHIFT (2U)
#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_Reserved_30_2_WIDTH (29U)
#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_Reserved_30_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_SAFETY_INTERRUPT_STATUS_Reserved_30_2_SHIFT)) & GMAC_MTL_SAFETY_INTERRUPT_STATUS_Reserved_30_2_MASK)

#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_Reserved_MCSIS_MASK (0x80000000U)
#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_Reserved_MCSIS_SHIFT (31U)
#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_Reserved_MCSIS_WIDTH (1U)
#define GMAC_MTL_SAFETY_INTERRUPT_STATUS_Reserved_MCSIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_SAFETY_INTERRUPT_STATUS_Reserved_MCSIS_SHIFT)) & GMAC_MTL_SAFETY_INTERRUPT_STATUS_Reserved_MCSIS_MASK)
/*! @} */

/*! @name MTL_ECC_INTERRUPT_ENABLE -  */
/*! @{ */

#define GMAC_MTL_ECC_INTERRUPT_ENABLE_TXCEIE_MASK (0x1U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_TXCEIE_SHIFT (0U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_TXCEIE_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_TXCEIE(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_ENABLE_TXCEIE_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_ENABLE_TXCEIE_MASK)

#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_3_1_MASK (0xEU)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_3_1_SHIFT (1U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_3_1_WIDTH (3U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_3_1(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_3_1_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_3_1_MASK)

#define GMAC_MTL_ECC_INTERRUPT_ENABLE_RXCEIE_MASK (0x10U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_RXCEIE_SHIFT (4U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_RXCEIE_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_RXCEIE(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_ENABLE_RXCEIE_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_ENABLE_RXCEIE_MASK)

#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_7_5_MASK (0xE0U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_7_5_SHIFT (5U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_7_5_WIDTH (3U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_7_5(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_7_5_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_7_5_MASK)

#define GMAC_MTL_ECC_INTERRUPT_ENABLE_ECEIE_MASK (0x100U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_ECEIE_SHIFT (8U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_ECEIE_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_ECEIE(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_ENABLE_ECEIE_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_ENABLE_ECEIE_MASK)

#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_11_9_MASK (0xE00U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_11_9_SHIFT (9U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_11_9_WIDTH (3U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_11_9(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_11_9_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_11_9_MASK)

#define GMAC_MTL_ECC_INTERRUPT_ENABLE_RPCEIE_MASK (0x1000U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_RPCEIE_SHIFT (12U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_RPCEIE_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_RPCEIE(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_ENABLE_RPCEIE_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_ENABLE_RPCEIE_MASK)

#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_31_13_MASK (0xFFFFE000U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_31_13_SHIFT (13U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_31_13_WIDTH (19U)
#define GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_31_13(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_31_13_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_ENABLE_Reserved_31_13_MASK)
/*! @} */

/*! @name MTL_ECC_INTERRUPT_STATUS -  */
/*! @{ */

#define GMAC_MTL_ECC_INTERRUPT_STATUS_TXCES_MASK (0x1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_TXCES_SHIFT (0U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_TXCES_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_TXCES(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_TXCES_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_TXCES_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_TXAMS_MASK (0x2U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_TXAMS_SHIFT (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_TXAMS_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_TXAMS(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_TXAMS_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_TXAMS_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_TXUES_MASK (0x4U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_TXUES_SHIFT (2U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_TXUES_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_TXUES(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_TXUES_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_TXUES_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_3_MASK (0x8U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_3_SHIFT (3U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_3_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_3(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_3_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_3_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_RXCES_MASK (0x10U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RXCES_SHIFT (4U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RXCES_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RXCES(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_RXCES_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_RXCES_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_RXAMS_MASK (0x20U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RXAMS_SHIFT (5U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RXAMS_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RXAMS(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_RXAMS_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_RXAMS_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_RXUES_MASK (0x40U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RXUES_SHIFT (6U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RXUES_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RXUES(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_RXUES_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_RXUES_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_7_MASK (0x80U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_7_SHIFT (7U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_7_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_7(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_7_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_7_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_ECES_MASK  (0x100U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_ECES_SHIFT (8U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_ECES_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_ECES(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_ECES_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_ECES_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_EAMS_MASK  (0x200U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_EAMS_SHIFT (9U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_EAMS_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_EAMS(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_EAMS_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_EAMS_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_EUES_MASK  (0x400U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_EUES_SHIFT (10U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_EUES_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_EUES(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_EUES_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_EUES_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_11_MASK (0x800U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_11_SHIFT (11U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_11_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_11(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_11_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_11_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_RPCES_MASK (0x1000U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RPCES_SHIFT (12U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RPCES_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RPCES(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_RPCES_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_RPCES_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_RPAMS_MASK (0x2000U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RPAMS_SHIFT (13U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RPAMS_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RPAMS(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_RPAMS_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_RPAMS_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_RPUES_MASK (0x4000U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RPUES_SHIFT (14U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RPUES_WIDTH (1U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_RPUES(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_RPUES_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_RPUES_MASK)

#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_31_15_MASK (0xFFFF8000U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_31_15_SHIFT (15U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_31_15_WIDTH (17U)
#define GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_31_15(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_31_15_SHIFT)) & GMAC_MTL_ECC_INTERRUPT_STATUS_Reserved_31_15_MASK)
/*! @} */

/*! @name MTL_ECC_ERR_STS_RCTL -  */
/*! @{ */

#define GMAC_MTL_ECC_ERR_STS_RCTL_EESRE_MASK     (0x1U)
#define GMAC_MTL_ECC_ERR_STS_RCTL_EESRE_SHIFT    (0U)
#define GMAC_MTL_ECC_ERR_STS_RCTL_EESRE_WIDTH    (1U)
#define GMAC_MTL_ECC_ERR_STS_RCTL_EESRE(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_ERR_STS_RCTL_EESRE_SHIFT)) & GMAC_MTL_ECC_ERR_STS_RCTL_EESRE_MASK)

#define GMAC_MTL_ECC_ERR_STS_RCTL_EMS_MASK       (0xEU)
#define GMAC_MTL_ECC_ERR_STS_RCTL_EMS_SHIFT      (1U)
#define GMAC_MTL_ECC_ERR_STS_RCTL_EMS_WIDTH      (3U)
#define GMAC_MTL_ECC_ERR_STS_RCTL_EMS(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_ERR_STS_RCTL_EMS_SHIFT)) & GMAC_MTL_ECC_ERR_STS_RCTL_EMS_MASK)

#define GMAC_MTL_ECC_ERR_STS_RCTL_CCES_MASK      (0x10U)
#define GMAC_MTL_ECC_ERR_STS_RCTL_CCES_SHIFT     (4U)
#define GMAC_MTL_ECC_ERR_STS_RCTL_CCES_WIDTH     (1U)
#define GMAC_MTL_ECC_ERR_STS_RCTL_CCES(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_ERR_STS_RCTL_CCES_SHIFT)) & GMAC_MTL_ECC_ERR_STS_RCTL_CCES_MASK)

#define GMAC_MTL_ECC_ERR_STS_RCTL_CUES_MASK      (0x20U)
#define GMAC_MTL_ECC_ERR_STS_RCTL_CUES_SHIFT     (5U)
#define GMAC_MTL_ECC_ERR_STS_RCTL_CUES_WIDTH     (1U)
#define GMAC_MTL_ECC_ERR_STS_RCTL_CUES(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_ERR_STS_RCTL_CUES_SHIFT)) & GMAC_MTL_ECC_ERR_STS_RCTL_CUES_MASK)

#define GMAC_MTL_ECC_ERR_STS_RCTL_Reserved_31_6_MASK (0xFFFFFFC0U)
#define GMAC_MTL_ECC_ERR_STS_RCTL_Reserved_31_6_SHIFT (6U)
#define GMAC_MTL_ECC_ERR_STS_RCTL_Reserved_31_6_WIDTH (26U)
#define GMAC_MTL_ECC_ERR_STS_RCTL_Reserved_31_6(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_ERR_STS_RCTL_Reserved_31_6_SHIFT)) & GMAC_MTL_ECC_ERR_STS_RCTL_Reserved_31_6_MASK)
/*! @} */

/*! @name MTL_ECC_ERR_ADDR_STATUS -  */
/*! @{ */

#define GMAC_MTL_ECC_ERR_ADDR_STATUS_ECEAS_MASK  (0xFFFFU)
#define GMAC_MTL_ECC_ERR_ADDR_STATUS_ECEAS_SHIFT (0U)
#define GMAC_MTL_ECC_ERR_ADDR_STATUS_ECEAS_WIDTH (16U)
#define GMAC_MTL_ECC_ERR_ADDR_STATUS_ECEAS(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_ERR_ADDR_STATUS_ECEAS_SHIFT)) & GMAC_MTL_ECC_ERR_ADDR_STATUS_ECEAS_MASK)

#define GMAC_MTL_ECC_ERR_ADDR_STATUS_EUEAS_MASK  (0xFFFF0000U)
#define GMAC_MTL_ECC_ERR_ADDR_STATUS_EUEAS_SHIFT (16U)
#define GMAC_MTL_ECC_ERR_ADDR_STATUS_EUEAS_WIDTH (16U)
#define GMAC_MTL_ECC_ERR_ADDR_STATUS_EUEAS(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_ERR_ADDR_STATUS_EUEAS_SHIFT)) & GMAC_MTL_ECC_ERR_ADDR_STATUS_EUEAS_MASK)
/*! @} */

/*! @name MTL_ECC_ERR_CNTR_STATUS -  */
/*! @{ */

#define GMAC_MTL_ECC_ERR_CNTR_STATUS_ECECS_MASK  (0xFFU)
#define GMAC_MTL_ECC_ERR_CNTR_STATUS_ECECS_SHIFT (0U)
#define GMAC_MTL_ECC_ERR_CNTR_STATUS_ECECS_WIDTH (8U)
#define GMAC_MTL_ECC_ERR_CNTR_STATUS_ECECS(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_ERR_CNTR_STATUS_ECECS_SHIFT)) & GMAC_MTL_ECC_ERR_CNTR_STATUS_ECECS_MASK)

#define GMAC_MTL_ECC_ERR_CNTR_STATUS_Reserved_15_8_MASK (0xFF00U)
#define GMAC_MTL_ECC_ERR_CNTR_STATUS_Reserved_15_8_SHIFT (8U)
#define GMAC_MTL_ECC_ERR_CNTR_STATUS_Reserved_15_8_WIDTH (8U)
#define GMAC_MTL_ECC_ERR_CNTR_STATUS_Reserved_15_8(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_ERR_CNTR_STATUS_Reserved_15_8_SHIFT)) & GMAC_MTL_ECC_ERR_CNTR_STATUS_Reserved_15_8_MASK)

#define GMAC_MTL_ECC_ERR_CNTR_STATUS_EUECS_MASK  (0xF0000U)
#define GMAC_MTL_ECC_ERR_CNTR_STATUS_EUECS_SHIFT (16U)
#define GMAC_MTL_ECC_ERR_CNTR_STATUS_EUECS_WIDTH (4U)
#define GMAC_MTL_ECC_ERR_CNTR_STATUS_EUECS(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_ERR_CNTR_STATUS_EUECS_SHIFT)) & GMAC_MTL_ECC_ERR_CNTR_STATUS_EUECS_MASK)

#define GMAC_MTL_ECC_ERR_CNTR_STATUS_Reserved_31_20_MASK (0xFFF00000U)
#define GMAC_MTL_ECC_ERR_CNTR_STATUS_Reserved_31_20_SHIFT (20U)
#define GMAC_MTL_ECC_ERR_CNTR_STATUS_Reserved_31_20_WIDTH (12U)
#define GMAC_MTL_ECC_ERR_CNTR_STATUS_Reserved_31_20(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_ECC_ERR_CNTR_STATUS_Reserved_31_20_SHIFT)) & GMAC_MTL_ECC_ERR_CNTR_STATUS_Reserved_31_20_MASK)
/*! @} */

/*! @name MTL_DPP_CONTROL -  */
/*! @{ */

#define GMAC_MTL_DPP_CONTROL_EDPP_MASK           (0x1U)
#define GMAC_MTL_DPP_CONTROL_EDPP_SHIFT          (0U)
#define GMAC_MTL_DPP_CONTROL_EDPP_WIDTH          (1U)
#define GMAC_MTL_DPP_CONTROL_EDPP(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_EDPP_SHIFT)) & GMAC_MTL_DPP_CONTROL_EDPP_MASK)

#define GMAC_MTL_DPP_CONTROL_OPE_MASK            (0x2U)
#define GMAC_MTL_DPP_CONTROL_OPE_SHIFT           (1U)
#define GMAC_MTL_DPP_CONTROL_OPE_WIDTH           (1U)
#define GMAC_MTL_DPP_CONTROL_OPE(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_OPE_SHIFT)) & GMAC_MTL_DPP_CONTROL_OPE_MASK)

#define GMAC_MTL_DPP_CONTROL_Reserved_EPSI_MASK  (0x4U)
#define GMAC_MTL_DPP_CONTROL_Reserved_EPSI_SHIFT (2U)
#define GMAC_MTL_DPP_CONTROL_Reserved_EPSI_WIDTH (1U)
#define GMAC_MTL_DPP_CONTROL_Reserved_EPSI(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_Reserved_EPSI_SHIFT)) & GMAC_MTL_DPP_CONTROL_Reserved_EPSI_MASK)

#define GMAC_MTL_DPP_CONTROL_Reserved_3_MASK     (0x8U)
#define GMAC_MTL_DPP_CONTROL_Reserved_3_SHIFT    (3U)
#define GMAC_MTL_DPP_CONTROL_Reserved_3_WIDTH    (1U)
#define GMAC_MTL_DPP_CONTROL_Reserved_3(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_Reserved_3_SHIFT)) & GMAC_MTL_DPP_CONTROL_Reserved_3_MASK)

#define GMAC_MTL_DPP_CONTROL_Reserved_IPETID_MASK (0x10U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPETID_SHIFT (4U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPETID_WIDTH (1U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPETID(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_Reserved_IPETID_SHIFT)) & GMAC_MTL_DPP_CONTROL_Reserved_IPETID_MASK)

#define GMAC_MTL_DPP_CONTROL_Reserved_IPETH_MASK (0x20U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPETH_SHIFT (5U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPETH_WIDTH (1U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPETH(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_Reserved_IPETH_SHIFT)) & GMAC_MTL_DPP_CONTROL_Reserved_IPETH_MASK)

#define GMAC_MTL_DPP_CONTROL_IPETRD_MASK         (0x40U)
#define GMAC_MTL_DPP_CONTROL_IPETRD_SHIFT        (6U)
#define GMAC_MTL_DPP_CONTROL_IPETRD_WIDTH        (1U)
#define GMAC_MTL_DPP_CONTROL_IPETRD(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_IPETRD_SHIFT)) & GMAC_MTL_DPP_CONTROL_IPETRD_MASK)

#define GMAC_MTL_DPP_CONTROL_IPEMTF_MASK         (0x80U)
#define GMAC_MTL_DPP_CONTROL_IPEMTF_SHIFT        (7U)
#define GMAC_MTL_DPP_CONTROL_IPEMTF_WIDTH        (1U)
#define GMAC_MTL_DPP_CONTROL_IPEMTF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_IPEMTF_SHIFT)) & GMAC_MTL_DPP_CONTROL_IPEMTF_MASK)

#define GMAC_MTL_DPP_CONTROL_IPEMTS_MASK         (0x100U)
#define GMAC_MTL_DPP_CONTROL_IPEMTS_SHIFT        (8U)
#define GMAC_MTL_DPP_CONTROL_IPEMTS_WIDTH        (1U)
#define GMAC_MTL_DPP_CONTROL_IPEMTS(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_IPEMTS_SHIFT)) & GMAC_MTL_DPP_CONTROL_IPEMTS_MASK)

#define GMAC_MTL_DPP_CONTROL_IPERID_MASK         (0x200U)
#define GMAC_MTL_DPP_CONTROL_IPERID_SHIFT        (9U)
#define GMAC_MTL_DPP_CONTROL_IPERID_WIDTH        (1U)
#define GMAC_MTL_DPP_CONTROL_IPERID(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_IPERID_SHIFT)) & GMAC_MTL_DPP_CONTROL_IPERID_MASK)

#define GMAC_MTL_DPP_CONTROL_Reserved_IPEASW_MASK (0x400U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPEASW_SHIFT (10U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPEASW_WIDTH (1U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPEASW(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_Reserved_IPEASW_SHIFT)) & GMAC_MTL_DPP_CONTROL_Reserved_IPEASW_MASK)

#define GMAC_MTL_DPP_CONTROL_Reserved_IPEMSW_MASK (0x800U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPEMSW_SHIFT (11U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPEMSW_WIDTH (1U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPEMSW(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_Reserved_IPEMSW_SHIFT)) & GMAC_MTL_DPP_CONTROL_Reserved_IPEMSW_MASK)

#define GMAC_MTL_DPP_CONTROL_Reserved_IPEASR_MASK (0x1000U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPEASR_SHIFT (12U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPEASR_WIDTH (1U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPEASR(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_Reserved_IPEASR_SHIFT)) & GMAC_MTL_DPP_CONTROL_Reserved_IPEASR_MASK)

#define GMAC_MTL_DPP_CONTROL_IPEMTBU_MASK        (0x2000U)
#define GMAC_MTL_DPP_CONTROL_IPEMTBU_SHIFT       (13U)
#define GMAC_MTL_DPP_CONTROL_IPEMTBU_WIDTH       (1U)
#define GMAC_MTL_DPP_CONTROL_IPEMTBU(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_IPEMTBU_SHIFT)) & GMAC_MTL_DPP_CONTROL_IPEMTBU_MASK)

#define GMAC_MTL_DPP_CONTROL_IPEMTFC_MASK        (0x4000U)
#define GMAC_MTL_DPP_CONTROL_IPEMTFC_SHIFT       (14U)
#define GMAC_MTL_DPP_CONTROL_IPEMTFC_WIDTH       (1U)
#define GMAC_MTL_DPP_CONTROL_IPEMTFC(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_IPEMTFC_SHIFT)) & GMAC_MTL_DPP_CONTROL_IPEMTFC_MASK)

#define GMAC_MTL_DPP_CONTROL_IPEMRWC_MASK        (0x8000U)
#define GMAC_MTL_DPP_CONTROL_IPEMRWC_SHIFT       (15U)
#define GMAC_MTL_DPP_CONTROL_IPEMRWC_WIDTH       (1U)
#define GMAC_MTL_DPP_CONTROL_IPEMRWC(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_IPEMRWC_SHIFT)) & GMAC_MTL_DPP_CONTROL_IPEMRWC_MASK)

#define GMAC_MTL_DPP_CONTROL_Reserved_IPEDC_MASK (0x10000U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPEDC_SHIFT (16U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPEDC_WIDTH (1U)
#define GMAC_MTL_DPP_CONTROL_Reserved_IPEDC(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_Reserved_IPEDC_SHIFT)) & GMAC_MTL_DPP_CONTROL_Reserved_IPEDC_MASK)

#define GMAC_MTL_DPP_CONTROL_Reserved_31_17_MASK (0xFFFE0000U)
#define GMAC_MTL_DPP_CONTROL_Reserved_31_17_SHIFT (17U)
#define GMAC_MTL_DPP_CONTROL_Reserved_31_17_WIDTH (15U)
#define GMAC_MTL_DPP_CONTROL_Reserved_31_17(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_CONTROL_Reserved_31_17_SHIFT)) & GMAC_MTL_DPP_CONTROL_Reserved_31_17_MASK)
/*! @} */

/*! @name MTL_DPP_ECC_EIC -  */
/*! @{ */

#define GMAC_MTL_DPP_ECC_EIC_BLEI_MASK           (0xFFU)
#define GMAC_MTL_DPP_ECC_EIC_BLEI_SHIFT          (0U)
#define GMAC_MTL_DPP_ECC_EIC_BLEI_WIDTH          (8U)
#define GMAC_MTL_DPP_ECC_EIC_BLEI(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_ECC_EIC_BLEI_SHIFT)) & GMAC_MTL_DPP_ECC_EIC_BLEI_MASK)

#define GMAC_MTL_DPP_ECC_EIC_Reserved_15_8_MASK  (0xFF00U)
#define GMAC_MTL_DPP_ECC_EIC_Reserved_15_8_SHIFT (8U)
#define GMAC_MTL_DPP_ECC_EIC_Reserved_15_8_WIDTH (8U)
#define GMAC_MTL_DPP_ECC_EIC_Reserved_15_8(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_ECC_EIC_Reserved_15_8_SHIFT)) & GMAC_MTL_DPP_ECC_EIC_Reserved_15_8_MASK)

#define GMAC_MTL_DPP_ECC_EIC_EIM_MASK            (0x10000U)
#define GMAC_MTL_DPP_ECC_EIC_EIM_SHIFT           (16U)
#define GMAC_MTL_DPP_ECC_EIC_EIM_WIDTH           (1U)
#define GMAC_MTL_DPP_ECC_EIC_EIM(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_ECC_EIC_EIM_SHIFT)) & GMAC_MTL_DPP_ECC_EIC_EIM_MASK)

#define GMAC_MTL_DPP_ECC_EIC_Reserved_31_17_MASK (0xFFFE0000U)
#define GMAC_MTL_DPP_ECC_EIC_Reserved_31_17_SHIFT (17U)
#define GMAC_MTL_DPP_ECC_EIC_Reserved_31_17_WIDTH (15U)
#define GMAC_MTL_DPP_ECC_EIC_Reserved_31_17(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_DPP_ECC_EIC_Reserved_31_17_SHIFT)) & GMAC_MTL_DPP_ECC_EIC_Reserved_31_17_MASK)
/*! @} */

/*! @name MTL_TXQ0_OPERATION_MODE -  */
/*! @{ */

#define GMAC_MTL_TXQ0_OPERATION_MODE_FTQ_MASK    (0x1U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_FTQ_SHIFT   (0U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_FTQ_WIDTH   (1U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_FTQ(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_OPERATION_MODE_FTQ_SHIFT)) & GMAC_MTL_TXQ0_OPERATION_MODE_FTQ_MASK)

#define GMAC_MTL_TXQ0_OPERATION_MODE_TSF_MASK    (0x2U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TSF_SHIFT   (1U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TSF_WIDTH   (1U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TSF(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_OPERATION_MODE_TSF_SHIFT)) & GMAC_MTL_TXQ0_OPERATION_MODE_TSF_MASK)

#define GMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_MASK  (0xCU)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_SHIFT (2U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_WIDTH (2U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TXQEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_SHIFT)) & GMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_MASK)

#define GMAC_MTL_TXQ0_OPERATION_MODE_TTC_MASK    (0x70U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TTC_SHIFT   (4U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TTC_WIDTH   (3U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_OPERATION_MODE_TTC_SHIFT)) & GMAC_MTL_TXQ0_OPERATION_MODE_TTC_MASK)

#define GMAC_MTL_TXQ0_OPERATION_MODE_Reserved_15_7_MASK (0xFF80U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_Reserved_15_7_SHIFT (7U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_Reserved_15_7_WIDTH (9U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_Reserved_15_7(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_OPERATION_MODE_Reserved_15_7_SHIFT)) & GMAC_MTL_TXQ0_OPERATION_MODE_Reserved_15_7_MASK)

#define GMAC_MTL_TXQ0_OPERATION_MODE_TQS_MASK    (0x3F0000U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TQS_SHIFT   (16U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TQS_WIDTH   (6U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TQS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_OPERATION_MODE_TQS_SHIFT)) & GMAC_MTL_TXQ0_OPERATION_MODE_TQS_MASK)

#define GMAC_MTL_TXQ0_OPERATION_MODE_Reserved_31_y_MASK (0xFFC00000U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_Reserved_31_y_SHIFT (22U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_Reserved_31_y_WIDTH (10U)
#define GMAC_MTL_TXQ0_OPERATION_MODE_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_OPERATION_MODE_Reserved_31_y_SHIFT)) & GMAC_MTL_TXQ0_OPERATION_MODE_Reserved_31_y_MASK)
/*! @} */

/*! @name MTL_TXQ0_UNDERFLOW -  */
/*! @{ */

#define GMAC_MTL_TXQ0_UNDERFLOW_UFFRMCNT_MASK    (0x7FFU)
#define GMAC_MTL_TXQ0_UNDERFLOW_UFFRMCNT_SHIFT   (0U)
#define GMAC_MTL_TXQ0_UNDERFLOW_UFFRMCNT_WIDTH   (11U)
#define GMAC_MTL_TXQ0_UNDERFLOW_UFFRMCNT(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_UNDERFLOW_UFFRMCNT_SHIFT)) & GMAC_MTL_TXQ0_UNDERFLOW_UFFRMCNT_MASK)

#define GMAC_MTL_TXQ0_UNDERFLOW_UFCNTOVF_MASK    (0x800U)
#define GMAC_MTL_TXQ0_UNDERFLOW_UFCNTOVF_SHIFT   (11U)
#define GMAC_MTL_TXQ0_UNDERFLOW_UFCNTOVF_WIDTH   (1U)
#define GMAC_MTL_TXQ0_UNDERFLOW_UFCNTOVF(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_UNDERFLOW_UFCNTOVF_SHIFT)) & GMAC_MTL_TXQ0_UNDERFLOW_UFCNTOVF_MASK)

#define GMAC_MTL_TXQ0_UNDERFLOW_Reserved_31_12_MASK (0xFFFFF000U)
#define GMAC_MTL_TXQ0_UNDERFLOW_Reserved_31_12_SHIFT (12U)
#define GMAC_MTL_TXQ0_UNDERFLOW_Reserved_31_12_WIDTH (20U)
#define GMAC_MTL_TXQ0_UNDERFLOW_Reserved_31_12(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_UNDERFLOW_Reserved_31_12_SHIFT)) & GMAC_MTL_TXQ0_UNDERFLOW_Reserved_31_12_MASK)
/*! @} */

/*! @name MTL_TXQ0_DEBUG -  */
/*! @{ */

#define GMAC_MTL_TXQ0_DEBUG_TXQPAUSED_MASK       (0x1U)
#define GMAC_MTL_TXQ0_DEBUG_TXQPAUSED_SHIFT      (0U)
#define GMAC_MTL_TXQ0_DEBUG_TXQPAUSED_WIDTH      (1U)
#define GMAC_MTL_TXQ0_DEBUG_TXQPAUSED(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_DEBUG_TXQPAUSED_SHIFT)) & GMAC_MTL_TXQ0_DEBUG_TXQPAUSED_MASK)

#define GMAC_MTL_TXQ0_DEBUG_TRCSTS_MASK          (0x6U)
#define GMAC_MTL_TXQ0_DEBUG_TRCSTS_SHIFT         (1U)
#define GMAC_MTL_TXQ0_DEBUG_TRCSTS_WIDTH         (2U)
#define GMAC_MTL_TXQ0_DEBUG_TRCSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_DEBUG_TRCSTS_SHIFT)) & GMAC_MTL_TXQ0_DEBUG_TRCSTS_MASK)

#define GMAC_MTL_TXQ0_DEBUG_TWCSTS_MASK          (0x8U)
#define GMAC_MTL_TXQ0_DEBUG_TWCSTS_SHIFT         (3U)
#define GMAC_MTL_TXQ0_DEBUG_TWCSTS_WIDTH         (1U)
#define GMAC_MTL_TXQ0_DEBUG_TWCSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_DEBUG_TWCSTS_SHIFT)) & GMAC_MTL_TXQ0_DEBUG_TWCSTS_MASK)

#define GMAC_MTL_TXQ0_DEBUG_TXQSTS_MASK          (0x10U)
#define GMAC_MTL_TXQ0_DEBUG_TXQSTS_SHIFT         (4U)
#define GMAC_MTL_TXQ0_DEBUG_TXQSTS_WIDTH         (1U)
#define GMAC_MTL_TXQ0_DEBUG_TXQSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_DEBUG_TXQSTS_SHIFT)) & GMAC_MTL_TXQ0_DEBUG_TXQSTS_MASK)

#define GMAC_MTL_TXQ0_DEBUG_TXSTSFSTS_MASK       (0x20U)
#define GMAC_MTL_TXQ0_DEBUG_TXSTSFSTS_SHIFT      (5U)
#define GMAC_MTL_TXQ0_DEBUG_TXSTSFSTS_WIDTH      (1U)
#define GMAC_MTL_TXQ0_DEBUG_TXSTSFSTS(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_DEBUG_TXSTSFSTS_SHIFT)) & GMAC_MTL_TXQ0_DEBUG_TXSTSFSTS_MASK)

#define GMAC_MTL_TXQ0_DEBUG_Reserved_15_6_MASK   (0xFFC0U)
#define GMAC_MTL_TXQ0_DEBUG_Reserved_15_6_SHIFT  (6U)
#define GMAC_MTL_TXQ0_DEBUG_Reserved_15_6_WIDTH  (10U)
#define GMAC_MTL_TXQ0_DEBUG_Reserved_15_6(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_DEBUG_Reserved_15_6_SHIFT)) & GMAC_MTL_TXQ0_DEBUG_Reserved_15_6_MASK)

#define GMAC_MTL_TXQ0_DEBUG_PTXQ_MASK            (0x70000U)
#define GMAC_MTL_TXQ0_DEBUG_PTXQ_SHIFT           (16U)
#define GMAC_MTL_TXQ0_DEBUG_PTXQ_WIDTH           (3U)
#define GMAC_MTL_TXQ0_DEBUG_PTXQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_DEBUG_PTXQ_SHIFT)) & GMAC_MTL_TXQ0_DEBUG_PTXQ_MASK)

#define GMAC_MTL_TXQ0_DEBUG_Reserved_19_MASK     (0x80000U)
#define GMAC_MTL_TXQ0_DEBUG_Reserved_19_SHIFT    (19U)
#define GMAC_MTL_TXQ0_DEBUG_Reserved_19_WIDTH    (1U)
#define GMAC_MTL_TXQ0_DEBUG_Reserved_19(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_DEBUG_Reserved_19_SHIFT)) & GMAC_MTL_TXQ0_DEBUG_Reserved_19_MASK)

#define GMAC_MTL_TXQ0_DEBUG_STXSTSF_MASK         (0x700000U)
#define GMAC_MTL_TXQ0_DEBUG_STXSTSF_SHIFT        (20U)
#define GMAC_MTL_TXQ0_DEBUG_STXSTSF_WIDTH        (3U)
#define GMAC_MTL_TXQ0_DEBUG_STXSTSF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_DEBUG_STXSTSF_SHIFT)) & GMAC_MTL_TXQ0_DEBUG_STXSTSF_MASK)

#define GMAC_MTL_TXQ0_DEBUG_Reserved_31_23_MASK  (0xFF800000U)
#define GMAC_MTL_TXQ0_DEBUG_Reserved_31_23_SHIFT (23U)
#define GMAC_MTL_TXQ0_DEBUG_Reserved_31_23_WIDTH (9U)
#define GMAC_MTL_TXQ0_DEBUG_Reserved_31_23(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_DEBUG_Reserved_31_23_SHIFT)) & GMAC_MTL_TXQ0_DEBUG_Reserved_31_23_MASK)
/*! @} */

/*! @name MTL_TXQ0_ETS_STATUS -  */
/*! @{ */

#define GMAC_MTL_TXQ0_ETS_STATUS_ABS_MASK        (0xFFFFFFU)
#define GMAC_MTL_TXQ0_ETS_STATUS_ABS_SHIFT       (0U)
#define GMAC_MTL_TXQ0_ETS_STATUS_ABS_WIDTH       (24U)
#define GMAC_MTL_TXQ0_ETS_STATUS_ABS(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_ETS_STATUS_ABS_SHIFT)) & GMAC_MTL_TXQ0_ETS_STATUS_ABS_MASK)

#define GMAC_MTL_TXQ0_ETS_STATUS_Reserved_31_24_MASK (0xFF000000U)
#define GMAC_MTL_TXQ0_ETS_STATUS_Reserved_31_24_SHIFT (24U)
#define GMAC_MTL_TXQ0_ETS_STATUS_Reserved_31_24_WIDTH (8U)
#define GMAC_MTL_TXQ0_ETS_STATUS_Reserved_31_24(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_ETS_STATUS_Reserved_31_24_SHIFT)) & GMAC_MTL_TXQ0_ETS_STATUS_Reserved_31_24_MASK)
/*! @} */

/*! @name MTL_TXQ0_QUANTUM_WEIGHT -  */
/*! @{ */

#define GMAC_MTL_TXQ0_QUANTUM_WEIGHT_ISCQW_MASK  (0x1FFFFFU)
#define GMAC_MTL_TXQ0_QUANTUM_WEIGHT_ISCQW_SHIFT (0U)
#define GMAC_MTL_TXQ0_QUANTUM_WEIGHT_ISCQW_WIDTH (21U)
#define GMAC_MTL_TXQ0_QUANTUM_WEIGHT_ISCQW(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_QUANTUM_WEIGHT_ISCQW_SHIFT)) & GMAC_MTL_TXQ0_QUANTUM_WEIGHT_ISCQW_MASK)

#define GMAC_MTL_TXQ0_QUANTUM_WEIGHT_Reserved_31_21_MASK (0xFFE00000U)
#define GMAC_MTL_TXQ0_QUANTUM_WEIGHT_Reserved_31_21_SHIFT (21U)
#define GMAC_MTL_TXQ0_QUANTUM_WEIGHT_Reserved_31_21_WIDTH (11U)
#define GMAC_MTL_TXQ0_QUANTUM_WEIGHT_Reserved_31_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ0_QUANTUM_WEIGHT_Reserved_31_21_SHIFT)) & GMAC_MTL_TXQ0_QUANTUM_WEIGHT_Reserved_31_21_MASK)
/*! @} */

/*! @name MTL_Q0_INTERRUPT_CONTROL_STATUS -  */
/*! @{ */

#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUNFIS_MASK (0x1U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUNFIS_SHIFT (0U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUNFIS_WIDTH (1U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUNFIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUNFIS_SHIFT)) & GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUNFIS_MASK)

#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIS_MASK (0x2U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIS_SHIFT (1U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIS_WIDTH (1U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIS_SHIFT)) & GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIS_MASK)

#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_7_2_MASK (0xFCU)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_7_2_SHIFT (2U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_7_2_WIDTH (6U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_7_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_7_2_SHIFT)) & GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_7_2_MASK)

#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUIE_MASK (0x100U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUIE_SHIFT (8U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUIE_WIDTH (1U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUIE_SHIFT)) & GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_TXUIE_MASK)

#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIE_MASK (0x200U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIE_SHIFT (9U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIE_WIDTH (1U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIE_SHIFT)) & GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_ABPSIE_MASK)

#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_15_10_MASK (0xFC00U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_15_10_SHIFT (10U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_15_10_WIDTH (6U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_15_10(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_15_10_SHIFT)) & GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_15_10_MASK)

#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOVFIS_MASK (0x10000U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOVFIS_SHIFT (16U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOVFIS_WIDTH (1U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOVFIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOVFIS_SHIFT)) & GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOVFIS_MASK)

#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_23_17_MASK (0xFE0000U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_23_17_SHIFT (17U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_23_17_WIDTH (7U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_23_17(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_23_17_SHIFT)) & GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_23_17_MASK)

#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOIE_MASK (0x1000000U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOIE_SHIFT (24U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOIE_WIDTH (1U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOIE_SHIFT)) & GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_RXOIE_MASK)

#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_31_25_MASK (0xFE000000U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_31_25_SHIFT (25U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_31_25_WIDTH (7U)
#define GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_31_25(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_31_25_SHIFT)) & GMAC_MTL_Q0_INTERRUPT_CONTROL_STATUS_Reserved_31_25_MASK)
/*! @} */

/*! @name MTL_RXQ0_OPERATION_MODE -  */
/*! @{ */

#define GMAC_MTL_RXQ0_OPERATION_MODE_RTC_MASK    (0x3U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RTC_SHIFT   (0U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RTC_WIDTH   (2U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_OPERATION_MODE_RTC_SHIFT)) & GMAC_MTL_RXQ0_OPERATION_MODE_RTC_MASK)

#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_2_MASK (0x4U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_2_SHIFT (2U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_2_WIDTH (1U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_2_SHIFT)) & GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_2_MASK)

#define GMAC_MTL_RXQ0_OPERATION_MODE_FUP_MASK    (0x8U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_FUP_SHIFT   (3U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_FUP_WIDTH   (1U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_FUP(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_OPERATION_MODE_FUP_SHIFT)) & GMAC_MTL_RXQ0_OPERATION_MODE_FUP_MASK)

#define GMAC_MTL_RXQ0_OPERATION_MODE_FEP_MASK    (0x10U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_FEP_SHIFT   (4U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_FEP_WIDTH   (1U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_FEP(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_OPERATION_MODE_FEP_SHIFT)) & GMAC_MTL_RXQ0_OPERATION_MODE_FEP_MASK)

#define GMAC_MTL_RXQ0_OPERATION_MODE_RSF_MASK    (0x20U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RSF_SHIFT   (5U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RSF_WIDTH   (1U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RSF(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_OPERATION_MODE_RSF_SHIFT)) & GMAC_MTL_RXQ0_OPERATION_MODE_RSF_MASK)

#define GMAC_MTL_RXQ0_OPERATION_MODE_DIS_TCP_EF_MASK (0x40U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_DIS_TCP_EF_SHIFT (6U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_DIS_TCP_EF_WIDTH (1U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_DIS_TCP_EF(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_OPERATION_MODE_DIS_TCP_EF_SHIFT)) & GMAC_MTL_RXQ0_OPERATION_MODE_DIS_TCP_EF_MASK)

#define GMAC_MTL_RXQ0_OPERATION_MODE_EHFC_MASK   (0x80U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_EHFC_SHIFT  (7U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_EHFC_WIDTH  (1U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_EHFC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_OPERATION_MODE_EHFC_SHIFT)) & GMAC_MTL_RXQ0_OPERATION_MODE_EHFC_MASK)

#define GMAC_MTL_RXQ0_OPERATION_MODE_RFA_MASK    (0x1F00U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RFA_SHIFT   (8U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RFA_WIDTH   (5U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RFA(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_OPERATION_MODE_RFA_SHIFT)) & GMAC_MTL_RXQ0_OPERATION_MODE_RFA_MASK)

#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_13_y_MASK (0x2000U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_13_y_SHIFT (13U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_13_y_WIDTH (1U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_13_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_13_y_SHIFT)) & GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_13_y_MASK)

#define GMAC_MTL_RXQ0_OPERATION_MODE_RFD_MASK    (0x7C000U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RFD_SHIFT   (14U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RFD_WIDTH   (5U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RFD(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_OPERATION_MODE_RFD_SHIFT)) & GMAC_MTL_RXQ0_OPERATION_MODE_RFD_MASK)

#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_19_y_MASK (0x80000U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_19_y_SHIFT (19U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_19_y_WIDTH (1U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_19_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_19_y_SHIFT)) & GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_19_y_MASK)

#define GMAC_MTL_RXQ0_OPERATION_MODE_RQS_MASK    (0x3F00000U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RQS_SHIFT   (20U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RQS_WIDTH   (6U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RQS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_OPERATION_MODE_RQS_SHIFT)) & GMAC_MTL_RXQ0_OPERATION_MODE_RQS_MASK)

#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_31_y_MASK (0xFC000000U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_31_y_SHIFT (26U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_31_y_WIDTH (6U)
#define GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_31_y_SHIFT)) & GMAC_MTL_RXQ0_OPERATION_MODE_Reserved_31_y_MASK)
/*! @} */

/*! @name MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT -  */
/*! @{ */

#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_MASK (0x7FFU)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_SHIFT (0U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_WIDTH (11U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_SHIFT)) & GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_MASK)

#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_MASK (0x800U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_SHIFT (11U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_WIDTH (1U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_SHIFT)) & GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_MASK)

#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_MASK (0xF000U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_SHIFT (12U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_WIDTH (4U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_SHIFT)) & GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_MASK)

#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_MASK (0x7FF0000U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_SHIFT (16U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_WIDTH (11U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_SHIFT)) & GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_MASK)

#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_MASK (0x8000000U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_SHIFT (27U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_WIDTH (1U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_SHIFT)) & GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_MASK)

#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_MASK (0xF0000000U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_SHIFT (28U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_WIDTH (4U)
#define GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_SHIFT)) & GMAC_MTL_RXQ0_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_MASK)
/*! @} */

/*! @name MTL_RXQ0_DEBUG -  */
/*! @{ */

#define GMAC_MTL_RXQ0_DEBUG_RWCSTS_MASK          (0x1U)
#define GMAC_MTL_RXQ0_DEBUG_RWCSTS_SHIFT         (0U)
#define GMAC_MTL_RXQ0_DEBUG_RWCSTS_WIDTH         (1U)
#define GMAC_MTL_RXQ0_DEBUG_RWCSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_DEBUG_RWCSTS_SHIFT)) & GMAC_MTL_RXQ0_DEBUG_RWCSTS_MASK)

#define GMAC_MTL_RXQ0_DEBUG_RRCSTS_MASK          (0x6U)
#define GMAC_MTL_RXQ0_DEBUG_RRCSTS_SHIFT         (1U)
#define GMAC_MTL_RXQ0_DEBUG_RRCSTS_WIDTH         (2U)
#define GMAC_MTL_RXQ0_DEBUG_RRCSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_DEBUG_RRCSTS_SHIFT)) & GMAC_MTL_RXQ0_DEBUG_RRCSTS_MASK)

#define GMAC_MTL_RXQ0_DEBUG_Reserved_3_MASK      (0x8U)
#define GMAC_MTL_RXQ0_DEBUG_Reserved_3_SHIFT     (3U)
#define GMAC_MTL_RXQ0_DEBUG_Reserved_3_WIDTH     (1U)
#define GMAC_MTL_RXQ0_DEBUG_Reserved_3(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_DEBUG_Reserved_3_SHIFT)) & GMAC_MTL_RXQ0_DEBUG_Reserved_3_MASK)

#define GMAC_MTL_RXQ0_DEBUG_RXQSTS_MASK          (0x30U)
#define GMAC_MTL_RXQ0_DEBUG_RXQSTS_SHIFT         (4U)
#define GMAC_MTL_RXQ0_DEBUG_RXQSTS_WIDTH         (2U)
#define GMAC_MTL_RXQ0_DEBUG_RXQSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_DEBUG_RXQSTS_SHIFT)) & GMAC_MTL_RXQ0_DEBUG_RXQSTS_MASK)

#define GMAC_MTL_RXQ0_DEBUG_Reserved_15_6_MASK   (0xFFC0U)
#define GMAC_MTL_RXQ0_DEBUG_Reserved_15_6_SHIFT  (6U)
#define GMAC_MTL_RXQ0_DEBUG_Reserved_15_6_WIDTH  (10U)
#define GMAC_MTL_RXQ0_DEBUG_Reserved_15_6(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_DEBUG_Reserved_15_6_SHIFT)) & GMAC_MTL_RXQ0_DEBUG_Reserved_15_6_MASK)

#define GMAC_MTL_RXQ0_DEBUG_PRXQ_MASK            (0x3FFF0000U)
#define GMAC_MTL_RXQ0_DEBUG_PRXQ_SHIFT           (16U)
#define GMAC_MTL_RXQ0_DEBUG_PRXQ_WIDTH           (14U)
#define GMAC_MTL_RXQ0_DEBUG_PRXQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_DEBUG_PRXQ_SHIFT)) & GMAC_MTL_RXQ0_DEBUG_PRXQ_MASK)

#define GMAC_MTL_RXQ0_DEBUG_Reserved_31_30_MASK  (0xC0000000U)
#define GMAC_MTL_RXQ0_DEBUG_Reserved_31_30_SHIFT (30U)
#define GMAC_MTL_RXQ0_DEBUG_Reserved_31_30_WIDTH (2U)
#define GMAC_MTL_RXQ0_DEBUG_Reserved_31_30(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_DEBUG_Reserved_31_30_SHIFT)) & GMAC_MTL_RXQ0_DEBUG_Reserved_31_30_MASK)
/*! @} */

/*! @name MTL_RXQ0_CONTROL -  */
/*! @{ */

#define GMAC_MTL_RXQ0_CONTROL_RXQ_WEGT_MASK      (0x7U)
#define GMAC_MTL_RXQ0_CONTROL_RXQ_WEGT_SHIFT     (0U)
#define GMAC_MTL_RXQ0_CONTROL_RXQ_WEGT_WIDTH     (3U)
#define GMAC_MTL_RXQ0_CONTROL_RXQ_WEGT(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_CONTROL_RXQ_WEGT_SHIFT)) & GMAC_MTL_RXQ0_CONTROL_RXQ_WEGT_MASK)

#define GMAC_MTL_RXQ0_CONTROL_RXQ_FRM_ARBIT_MASK (0x8U)
#define GMAC_MTL_RXQ0_CONTROL_RXQ_FRM_ARBIT_SHIFT (3U)
#define GMAC_MTL_RXQ0_CONTROL_RXQ_FRM_ARBIT_WIDTH (1U)
#define GMAC_MTL_RXQ0_CONTROL_RXQ_FRM_ARBIT(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_CONTROL_RXQ_FRM_ARBIT_SHIFT)) & GMAC_MTL_RXQ0_CONTROL_RXQ_FRM_ARBIT_MASK)

#define GMAC_MTL_RXQ0_CONTROL_Reserved_31_4_MASK (0xFFFFFFF0U)
#define GMAC_MTL_RXQ0_CONTROL_Reserved_31_4_SHIFT (4U)
#define GMAC_MTL_RXQ0_CONTROL_Reserved_31_4_WIDTH (28U)
#define GMAC_MTL_RXQ0_CONTROL_Reserved_31_4(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ0_CONTROL_Reserved_31_4_SHIFT)) & GMAC_MTL_RXQ0_CONTROL_Reserved_31_4_MASK)
/*! @} */

/*! @name MTL_TXQ1_OPERATION_MODE -  */
/*! @{ */

#define GMAC_MTL_TXQ1_OPERATION_MODE_FTQ_MASK    (0x1U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_FTQ_SHIFT   (0U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_FTQ_WIDTH   (1U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_FTQ(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_OPERATION_MODE_FTQ_SHIFT)) & GMAC_MTL_TXQ1_OPERATION_MODE_FTQ_MASK)

#define GMAC_MTL_TXQ1_OPERATION_MODE_TSF_MASK    (0x2U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_TSF_SHIFT   (1U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_TSF_WIDTH   (1U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_TSF(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_OPERATION_MODE_TSF_SHIFT)) & GMAC_MTL_TXQ1_OPERATION_MODE_TSF_MASK)

#define GMAC_MTL_TXQ1_OPERATION_MODE_TXQEN_MASK  (0xCU)
#define GMAC_MTL_TXQ1_OPERATION_MODE_TXQEN_SHIFT (2U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_TXQEN_WIDTH (2U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_TXQEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_OPERATION_MODE_TXQEN_SHIFT)) & GMAC_MTL_TXQ1_OPERATION_MODE_TXQEN_MASK)

#define GMAC_MTL_TXQ1_OPERATION_MODE_TTC_MASK    (0x70U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_TTC_SHIFT   (4U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_TTC_WIDTH   (3U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_TTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_OPERATION_MODE_TTC_SHIFT)) & GMAC_MTL_TXQ1_OPERATION_MODE_TTC_MASK)

#define GMAC_MTL_TXQ1_OPERATION_MODE_Reserved_15_7_MASK (0xFF80U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_Reserved_15_7_SHIFT (7U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_Reserved_15_7_WIDTH (9U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_Reserved_15_7(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_OPERATION_MODE_Reserved_15_7_SHIFT)) & GMAC_MTL_TXQ1_OPERATION_MODE_Reserved_15_7_MASK)

#define GMAC_MTL_TXQ1_OPERATION_MODE_TQS_MASK    (0x3F0000U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_TQS_SHIFT   (16U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_TQS_WIDTH   (6U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_TQS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_OPERATION_MODE_TQS_SHIFT)) & GMAC_MTL_TXQ1_OPERATION_MODE_TQS_MASK)

#define GMAC_MTL_TXQ1_OPERATION_MODE_Reserved_31_y_MASK (0xFFC00000U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_Reserved_31_y_SHIFT (22U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_Reserved_31_y_WIDTH (10U)
#define GMAC_MTL_TXQ1_OPERATION_MODE_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_OPERATION_MODE_Reserved_31_y_SHIFT)) & GMAC_MTL_TXQ1_OPERATION_MODE_Reserved_31_y_MASK)
/*! @} */

/*! @name MTL_TXQ1_UNDERFLOW -  */
/*! @{ */

#define GMAC_MTL_TXQ1_UNDERFLOW_UFFRMCNT_MASK    (0x7FFU)
#define GMAC_MTL_TXQ1_UNDERFLOW_UFFRMCNT_SHIFT   (0U)
#define GMAC_MTL_TXQ1_UNDERFLOW_UFFRMCNT_WIDTH   (11U)
#define GMAC_MTL_TXQ1_UNDERFLOW_UFFRMCNT(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_UNDERFLOW_UFFRMCNT_SHIFT)) & GMAC_MTL_TXQ1_UNDERFLOW_UFFRMCNT_MASK)

#define GMAC_MTL_TXQ1_UNDERFLOW_UFCNTOVF_MASK    (0x800U)
#define GMAC_MTL_TXQ1_UNDERFLOW_UFCNTOVF_SHIFT   (11U)
#define GMAC_MTL_TXQ1_UNDERFLOW_UFCNTOVF_WIDTH   (1U)
#define GMAC_MTL_TXQ1_UNDERFLOW_UFCNTOVF(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_UNDERFLOW_UFCNTOVF_SHIFT)) & GMAC_MTL_TXQ1_UNDERFLOW_UFCNTOVF_MASK)

#define GMAC_MTL_TXQ1_UNDERFLOW_Reserved_31_12_MASK (0xFFFFF000U)
#define GMAC_MTL_TXQ1_UNDERFLOW_Reserved_31_12_SHIFT (12U)
#define GMAC_MTL_TXQ1_UNDERFLOW_Reserved_31_12_WIDTH (20U)
#define GMAC_MTL_TXQ1_UNDERFLOW_Reserved_31_12(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_UNDERFLOW_Reserved_31_12_SHIFT)) & GMAC_MTL_TXQ1_UNDERFLOW_Reserved_31_12_MASK)
/*! @} */

/*! @name MTL_TXQ1_DEBUG -  */
/*! @{ */

#define GMAC_MTL_TXQ1_DEBUG_TXQPAUSED_MASK       (0x1U)
#define GMAC_MTL_TXQ1_DEBUG_TXQPAUSED_SHIFT      (0U)
#define GMAC_MTL_TXQ1_DEBUG_TXQPAUSED_WIDTH      (1U)
#define GMAC_MTL_TXQ1_DEBUG_TXQPAUSED(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_DEBUG_TXQPAUSED_SHIFT)) & GMAC_MTL_TXQ1_DEBUG_TXQPAUSED_MASK)

#define GMAC_MTL_TXQ1_DEBUG_TRCSTS_MASK          (0x6U)
#define GMAC_MTL_TXQ1_DEBUG_TRCSTS_SHIFT         (1U)
#define GMAC_MTL_TXQ1_DEBUG_TRCSTS_WIDTH         (2U)
#define GMAC_MTL_TXQ1_DEBUG_TRCSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_DEBUG_TRCSTS_SHIFT)) & GMAC_MTL_TXQ1_DEBUG_TRCSTS_MASK)

#define GMAC_MTL_TXQ1_DEBUG_TWCSTS_MASK          (0x8U)
#define GMAC_MTL_TXQ1_DEBUG_TWCSTS_SHIFT         (3U)
#define GMAC_MTL_TXQ1_DEBUG_TWCSTS_WIDTH         (1U)
#define GMAC_MTL_TXQ1_DEBUG_TWCSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_DEBUG_TWCSTS_SHIFT)) & GMAC_MTL_TXQ1_DEBUG_TWCSTS_MASK)

#define GMAC_MTL_TXQ1_DEBUG_TXQSTS_MASK          (0x10U)
#define GMAC_MTL_TXQ1_DEBUG_TXQSTS_SHIFT         (4U)
#define GMAC_MTL_TXQ1_DEBUG_TXQSTS_WIDTH         (1U)
#define GMAC_MTL_TXQ1_DEBUG_TXQSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_DEBUG_TXQSTS_SHIFT)) & GMAC_MTL_TXQ1_DEBUG_TXQSTS_MASK)

#define GMAC_MTL_TXQ1_DEBUG_TXSTSFSTS_MASK       (0x20U)
#define GMAC_MTL_TXQ1_DEBUG_TXSTSFSTS_SHIFT      (5U)
#define GMAC_MTL_TXQ1_DEBUG_TXSTSFSTS_WIDTH      (1U)
#define GMAC_MTL_TXQ1_DEBUG_TXSTSFSTS(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_DEBUG_TXSTSFSTS_SHIFT)) & GMAC_MTL_TXQ1_DEBUG_TXSTSFSTS_MASK)

#define GMAC_MTL_TXQ1_DEBUG_Reserved_15_6_MASK   (0xFFC0U)
#define GMAC_MTL_TXQ1_DEBUG_Reserved_15_6_SHIFT  (6U)
#define GMAC_MTL_TXQ1_DEBUG_Reserved_15_6_WIDTH  (10U)
#define GMAC_MTL_TXQ1_DEBUG_Reserved_15_6(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_DEBUG_Reserved_15_6_SHIFT)) & GMAC_MTL_TXQ1_DEBUG_Reserved_15_6_MASK)

#define GMAC_MTL_TXQ1_DEBUG_PTXQ_MASK            (0x70000U)
#define GMAC_MTL_TXQ1_DEBUG_PTXQ_SHIFT           (16U)
#define GMAC_MTL_TXQ1_DEBUG_PTXQ_WIDTH           (3U)
#define GMAC_MTL_TXQ1_DEBUG_PTXQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_DEBUG_PTXQ_SHIFT)) & GMAC_MTL_TXQ1_DEBUG_PTXQ_MASK)

#define GMAC_MTL_TXQ1_DEBUG_Reserved_19_MASK     (0x80000U)
#define GMAC_MTL_TXQ1_DEBUG_Reserved_19_SHIFT    (19U)
#define GMAC_MTL_TXQ1_DEBUG_Reserved_19_WIDTH    (1U)
#define GMAC_MTL_TXQ1_DEBUG_Reserved_19(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_DEBUG_Reserved_19_SHIFT)) & GMAC_MTL_TXQ1_DEBUG_Reserved_19_MASK)

#define GMAC_MTL_TXQ1_DEBUG_STXSTSF_MASK         (0x700000U)
#define GMAC_MTL_TXQ1_DEBUG_STXSTSF_SHIFT        (20U)
#define GMAC_MTL_TXQ1_DEBUG_STXSTSF_WIDTH        (3U)
#define GMAC_MTL_TXQ1_DEBUG_STXSTSF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_DEBUG_STXSTSF_SHIFT)) & GMAC_MTL_TXQ1_DEBUG_STXSTSF_MASK)

#define GMAC_MTL_TXQ1_DEBUG_Reserved_31_23_MASK  (0xFF800000U)
#define GMAC_MTL_TXQ1_DEBUG_Reserved_31_23_SHIFT (23U)
#define GMAC_MTL_TXQ1_DEBUG_Reserved_31_23_WIDTH (9U)
#define GMAC_MTL_TXQ1_DEBUG_Reserved_31_23(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_DEBUG_Reserved_31_23_SHIFT)) & GMAC_MTL_TXQ1_DEBUG_Reserved_31_23_MASK)
/*! @} */

/*! @name MTL_TXQ1_ETS_CONTROL -  */
/*! @{ */

#define GMAC_MTL_TXQ1_ETS_CONTROL_Reserved_1_0_MASK (0x3U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_Reserved_1_0_SHIFT (0U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_Reserved_1_0_WIDTH (2U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_Reserved_1_0(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_ETS_CONTROL_Reserved_1_0_SHIFT)) & GMAC_MTL_TXQ1_ETS_CONTROL_Reserved_1_0_MASK)

#define GMAC_MTL_TXQ1_ETS_CONTROL_AVALG_MASK     (0x4U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_AVALG_SHIFT    (2U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_AVALG_WIDTH    (1U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_AVALG(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_ETS_CONTROL_AVALG_SHIFT)) & GMAC_MTL_TXQ1_ETS_CONTROL_AVALG_MASK)

#define GMAC_MTL_TXQ1_ETS_CONTROL_CC_MASK        (0x8U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_CC_SHIFT       (3U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_CC_WIDTH       (1U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_CC(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_ETS_CONTROL_CC_SHIFT)) & GMAC_MTL_TXQ1_ETS_CONTROL_CC_MASK)

#define GMAC_MTL_TXQ1_ETS_CONTROL_SLC_MASK       (0x70U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_SLC_SHIFT      (4U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_SLC_WIDTH      (3U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_SLC(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_ETS_CONTROL_SLC_SHIFT)) & GMAC_MTL_TXQ1_ETS_CONTROL_SLC_MASK)

#define GMAC_MTL_TXQ1_ETS_CONTROL_Reserved_31_7_MASK (0xFFFFFF80U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_Reserved_31_7_SHIFT (7U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_Reserved_31_7_WIDTH (25U)
#define GMAC_MTL_TXQ1_ETS_CONTROL_Reserved_31_7(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_ETS_CONTROL_Reserved_31_7_SHIFT)) & GMAC_MTL_TXQ1_ETS_CONTROL_Reserved_31_7_MASK)
/*! @} */

/*! @name MTL_TXQ1_ETS_STATUS -  */
/*! @{ */

#define GMAC_MTL_TXQ1_ETS_STATUS_ABS_MASK        (0xFFFFFFU)
#define GMAC_MTL_TXQ1_ETS_STATUS_ABS_SHIFT       (0U)
#define GMAC_MTL_TXQ1_ETS_STATUS_ABS_WIDTH       (24U)
#define GMAC_MTL_TXQ1_ETS_STATUS_ABS(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_ETS_STATUS_ABS_SHIFT)) & GMAC_MTL_TXQ1_ETS_STATUS_ABS_MASK)

#define GMAC_MTL_TXQ1_ETS_STATUS_Reserved_31_24_MASK (0xFF000000U)
#define GMAC_MTL_TXQ1_ETS_STATUS_Reserved_31_24_SHIFT (24U)
#define GMAC_MTL_TXQ1_ETS_STATUS_Reserved_31_24_WIDTH (8U)
#define GMAC_MTL_TXQ1_ETS_STATUS_Reserved_31_24(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_ETS_STATUS_Reserved_31_24_SHIFT)) & GMAC_MTL_TXQ1_ETS_STATUS_Reserved_31_24_MASK)
/*! @} */

/*! @name MTL_TXQ1_QUANTUM_WEIGHT -  */
/*! @{ */

#define GMAC_MTL_TXQ1_QUANTUM_WEIGHT_ISCQW_MASK  (0x1FFFFFU)
#define GMAC_MTL_TXQ1_QUANTUM_WEIGHT_ISCQW_SHIFT (0U)
#define GMAC_MTL_TXQ1_QUANTUM_WEIGHT_ISCQW_WIDTH (21U)
#define GMAC_MTL_TXQ1_QUANTUM_WEIGHT_ISCQW(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_QUANTUM_WEIGHT_ISCQW_SHIFT)) & GMAC_MTL_TXQ1_QUANTUM_WEIGHT_ISCQW_MASK)

#define GMAC_MTL_TXQ1_QUANTUM_WEIGHT_Reserved_31_21_MASK (0xFFE00000U)
#define GMAC_MTL_TXQ1_QUANTUM_WEIGHT_Reserved_31_21_SHIFT (21U)
#define GMAC_MTL_TXQ1_QUANTUM_WEIGHT_Reserved_31_21_WIDTH (11U)
#define GMAC_MTL_TXQ1_QUANTUM_WEIGHT_Reserved_31_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_QUANTUM_WEIGHT_Reserved_31_21_SHIFT)) & GMAC_MTL_TXQ1_QUANTUM_WEIGHT_Reserved_31_21_MASK)
/*! @} */

/*! @name MTL_TXQ1_SENDSLOPECREDIT -  */
/*! @{ */

#define GMAC_MTL_TXQ1_SENDSLOPECREDIT_SSC_MASK   (0x3FFFU)
#define GMAC_MTL_TXQ1_SENDSLOPECREDIT_SSC_SHIFT  (0U)
#define GMAC_MTL_TXQ1_SENDSLOPECREDIT_SSC_WIDTH  (14U)
#define GMAC_MTL_TXQ1_SENDSLOPECREDIT_SSC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_SENDSLOPECREDIT_SSC_SHIFT)) & GMAC_MTL_TXQ1_SENDSLOPECREDIT_SSC_MASK)

#define GMAC_MTL_TXQ1_SENDSLOPECREDIT_Reserved_31_14_MASK (0xFFFFC000U)
#define GMAC_MTL_TXQ1_SENDSLOPECREDIT_Reserved_31_14_SHIFT (14U)
#define GMAC_MTL_TXQ1_SENDSLOPECREDIT_Reserved_31_14_WIDTH (18U)
#define GMAC_MTL_TXQ1_SENDSLOPECREDIT_Reserved_31_14(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_SENDSLOPECREDIT_Reserved_31_14_SHIFT)) & GMAC_MTL_TXQ1_SENDSLOPECREDIT_Reserved_31_14_MASK)
/*! @} */

/*! @name MTL_TXQ1_HICREDIT -  */
/*! @{ */

#define GMAC_MTL_TXQ1_HICREDIT_HC_MASK           (0x1FFFFFFFU)
#define GMAC_MTL_TXQ1_HICREDIT_HC_SHIFT          (0U)
#define GMAC_MTL_TXQ1_HICREDIT_HC_WIDTH          (29U)
#define GMAC_MTL_TXQ1_HICREDIT_HC(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_HICREDIT_HC_SHIFT)) & GMAC_MTL_TXQ1_HICREDIT_HC_MASK)

#define GMAC_MTL_TXQ1_HICREDIT_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MTL_TXQ1_HICREDIT_Reserved_31_29_SHIFT (29U)
#define GMAC_MTL_TXQ1_HICREDIT_Reserved_31_29_WIDTH (3U)
#define GMAC_MTL_TXQ1_HICREDIT_Reserved_31_29(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_HICREDIT_Reserved_31_29_SHIFT)) & GMAC_MTL_TXQ1_HICREDIT_Reserved_31_29_MASK)
/*! @} */

/*! @name MTL_TXQ1_LOCREDIT -  */
/*! @{ */

#define GMAC_MTL_TXQ1_LOCREDIT_LC_MASK           (0x1FFFFFFFU)
#define GMAC_MTL_TXQ1_LOCREDIT_LC_SHIFT          (0U)
#define GMAC_MTL_TXQ1_LOCREDIT_LC_WIDTH          (29U)
#define GMAC_MTL_TXQ1_LOCREDIT_LC(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_LOCREDIT_LC_SHIFT)) & GMAC_MTL_TXQ1_LOCREDIT_LC_MASK)

#define GMAC_MTL_TXQ1_LOCREDIT_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MTL_TXQ1_LOCREDIT_Reserved_31_29_SHIFT (29U)
#define GMAC_MTL_TXQ1_LOCREDIT_Reserved_31_29_WIDTH (3U)
#define GMAC_MTL_TXQ1_LOCREDIT_Reserved_31_29(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ1_LOCREDIT_Reserved_31_29_SHIFT)) & GMAC_MTL_TXQ1_LOCREDIT_Reserved_31_29_MASK)
/*! @} */

/*! @name MTL_Q1_INTERRUPT_CONTROL_STATUS -  */
/*! @{ */

#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUNFIS_MASK (0x1U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUNFIS_SHIFT (0U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUNFIS_WIDTH (1U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUNFIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUNFIS_SHIFT)) & GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUNFIS_MASK)

#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIS_MASK (0x2U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIS_SHIFT (1U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIS_WIDTH (1U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIS_SHIFT)) & GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIS_MASK)

#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_7_2_MASK (0xFCU)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_7_2_SHIFT (2U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_7_2_WIDTH (6U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_7_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_7_2_SHIFT)) & GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_7_2_MASK)

#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUIE_MASK (0x100U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUIE_SHIFT (8U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUIE_WIDTH (1U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUIE_SHIFT)) & GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_TXUIE_MASK)

#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIE_MASK (0x200U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIE_SHIFT (9U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIE_WIDTH (1U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIE_SHIFT)) & GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_ABPSIE_MASK)

#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_15_10_MASK (0xFC00U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_15_10_SHIFT (10U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_15_10_WIDTH (6U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_15_10(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_15_10_SHIFT)) & GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_15_10_MASK)

#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOVFIS_MASK (0x10000U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOVFIS_SHIFT (16U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOVFIS_WIDTH (1U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOVFIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOVFIS_SHIFT)) & GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOVFIS_MASK)

#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_23_17_MASK (0xFE0000U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_23_17_SHIFT (17U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_23_17_WIDTH (7U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_23_17(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_23_17_SHIFT)) & GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_23_17_MASK)

#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOIE_MASK (0x1000000U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOIE_SHIFT (24U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOIE_WIDTH (1U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOIE_SHIFT)) & GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_RXOIE_MASK)

#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_31_25_MASK (0xFE000000U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_31_25_SHIFT (25U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_31_25_WIDTH (7U)
#define GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_31_25(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_31_25_SHIFT)) & GMAC_MTL_Q1_INTERRUPT_CONTROL_STATUS_Reserved_31_25_MASK)
/*! @} */

/*! @name MTL_RXQ1_OPERATION_MODE -  */
/*! @{ */

#define GMAC_MTL_RXQ1_OPERATION_MODE_RTC_MASK    (0x3U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RTC_SHIFT   (0U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RTC_WIDTH   (2U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_OPERATION_MODE_RTC_SHIFT)) & GMAC_MTL_RXQ1_OPERATION_MODE_RTC_MASK)

#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_2_MASK (0x4U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_2_SHIFT (2U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_2_WIDTH (1U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_2_SHIFT)) & GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_2_MASK)

#define GMAC_MTL_RXQ1_OPERATION_MODE_FUP_MASK    (0x8U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_FUP_SHIFT   (3U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_FUP_WIDTH   (1U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_FUP(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_OPERATION_MODE_FUP_SHIFT)) & GMAC_MTL_RXQ1_OPERATION_MODE_FUP_MASK)

#define GMAC_MTL_RXQ1_OPERATION_MODE_FEP_MASK    (0x10U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_FEP_SHIFT   (4U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_FEP_WIDTH   (1U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_FEP(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_OPERATION_MODE_FEP_SHIFT)) & GMAC_MTL_RXQ1_OPERATION_MODE_FEP_MASK)

#define GMAC_MTL_RXQ1_OPERATION_MODE_RSF_MASK    (0x20U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RSF_SHIFT   (5U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RSF_WIDTH   (1U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RSF(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_OPERATION_MODE_RSF_SHIFT)) & GMAC_MTL_RXQ1_OPERATION_MODE_RSF_MASK)

#define GMAC_MTL_RXQ1_OPERATION_MODE_DIS_TCP_EF_MASK (0x40U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_DIS_TCP_EF_SHIFT (6U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_DIS_TCP_EF_WIDTH (1U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_DIS_TCP_EF(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_OPERATION_MODE_DIS_TCP_EF_SHIFT)) & GMAC_MTL_RXQ1_OPERATION_MODE_DIS_TCP_EF_MASK)

#define GMAC_MTL_RXQ1_OPERATION_MODE_EHFC_MASK   (0x80U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_EHFC_SHIFT  (7U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_EHFC_WIDTH  (1U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_EHFC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_OPERATION_MODE_EHFC_SHIFT)) & GMAC_MTL_RXQ1_OPERATION_MODE_EHFC_MASK)

#define GMAC_MTL_RXQ1_OPERATION_MODE_RFA_MASK    (0x1F00U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RFA_SHIFT   (8U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RFA_WIDTH   (5U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RFA(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_OPERATION_MODE_RFA_SHIFT)) & GMAC_MTL_RXQ1_OPERATION_MODE_RFA_MASK)

#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_13_y_MASK (0x2000U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_13_y_SHIFT (13U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_13_y_WIDTH (1U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_13_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_13_y_SHIFT)) & GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_13_y_MASK)

#define GMAC_MTL_RXQ1_OPERATION_MODE_RFD_MASK    (0x7C000U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RFD_SHIFT   (14U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RFD_WIDTH   (5U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RFD(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_OPERATION_MODE_RFD_SHIFT)) & GMAC_MTL_RXQ1_OPERATION_MODE_RFD_MASK)

#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_19_y_MASK (0x80000U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_19_y_SHIFT (19U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_19_y_WIDTH (1U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_19_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_19_y_SHIFT)) & GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_19_y_MASK)

#define GMAC_MTL_RXQ1_OPERATION_MODE_RQS_MASK    (0x3F00000U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RQS_SHIFT   (20U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RQS_WIDTH   (6U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_RQS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_OPERATION_MODE_RQS_SHIFT)) & GMAC_MTL_RXQ1_OPERATION_MODE_RQS_MASK)

#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_31_y_MASK (0xFC000000U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_31_y_SHIFT (26U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_31_y_WIDTH (6U)
#define GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_31_y_SHIFT)) & GMAC_MTL_RXQ1_OPERATION_MODE_Reserved_31_y_MASK)
/*! @} */

/*! @name MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT -  */
/*! @{ */

#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_MASK (0x7FFU)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_SHIFT (0U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_WIDTH (11U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_SHIFT)) & GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_MASK)

#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_MASK (0x800U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_SHIFT (11U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_WIDTH (1U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_SHIFT)) & GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_MASK)

#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_MASK (0xF000U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_SHIFT (12U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_WIDTH (4U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_SHIFT)) & GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_MASK)

#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_MASK (0x7FF0000U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_SHIFT (16U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_WIDTH (11U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_SHIFT)) & GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_MASK)

#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_MASK (0x8000000U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_SHIFT (27U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_WIDTH (1U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_SHIFT)) & GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_MASK)

#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_MASK (0xF0000000U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_SHIFT (28U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_WIDTH (4U)
#define GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_SHIFT)) & GMAC_MTL_RXQ1_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_MASK)
/*! @} */

/*! @name MTL_RXQ1_DEBUG -  */
/*! @{ */

#define GMAC_MTL_RXQ1_DEBUG_RWCSTS_MASK          (0x1U)
#define GMAC_MTL_RXQ1_DEBUG_RWCSTS_SHIFT         (0U)
#define GMAC_MTL_RXQ1_DEBUG_RWCSTS_WIDTH         (1U)
#define GMAC_MTL_RXQ1_DEBUG_RWCSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_DEBUG_RWCSTS_SHIFT)) & GMAC_MTL_RXQ1_DEBUG_RWCSTS_MASK)

#define GMAC_MTL_RXQ1_DEBUG_RRCSTS_MASK          (0x6U)
#define GMAC_MTL_RXQ1_DEBUG_RRCSTS_SHIFT         (1U)
#define GMAC_MTL_RXQ1_DEBUG_RRCSTS_WIDTH         (2U)
#define GMAC_MTL_RXQ1_DEBUG_RRCSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_DEBUG_RRCSTS_SHIFT)) & GMAC_MTL_RXQ1_DEBUG_RRCSTS_MASK)

#define GMAC_MTL_RXQ1_DEBUG_Reserved_3_MASK      (0x8U)
#define GMAC_MTL_RXQ1_DEBUG_Reserved_3_SHIFT     (3U)
#define GMAC_MTL_RXQ1_DEBUG_Reserved_3_WIDTH     (1U)
#define GMAC_MTL_RXQ1_DEBUG_Reserved_3(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_DEBUG_Reserved_3_SHIFT)) & GMAC_MTL_RXQ1_DEBUG_Reserved_3_MASK)

#define GMAC_MTL_RXQ1_DEBUG_RXQSTS_MASK          (0x30U)
#define GMAC_MTL_RXQ1_DEBUG_RXQSTS_SHIFT         (4U)
#define GMAC_MTL_RXQ1_DEBUG_RXQSTS_WIDTH         (2U)
#define GMAC_MTL_RXQ1_DEBUG_RXQSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_DEBUG_RXQSTS_SHIFT)) & GMAC_MTL_RXQ1_DEBUG_RXQSTS_MASK)

#define GMAC_MTL_RXQ1_DEBUG_Reserved_15_6_MASK   (0xFFC0U)
#define GMAC_MTL_RXQ1_DEBUG_Reserved_15_6_SHIFT  (6U)
#define GMAC_MTL_RXQ1_DEBUG_Reserved_15_6_WIDTH  (10U)
#define GMAC_MTL_RXQ1_DEBUG_Reserved_15_6(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_DEBUG_Reserved_15_6_SHIFT)) & GMAC_MTL_RXQ1_DEBUG_Reserved_15_6_MASK)

#define GMAC_MTL_RXQ1_DEBUG_PRXQ_MASK            (0x3FFF0000U)
#define GMAC_MTL_RXQ1_DEBUG_PRXQ_SHIFT           (16U)
#define GMAC_MTL_RXQ1_DEBUG_PRXQ_WIDTH           (14U)
#define GMAC_MTL_RXQ1_DEBUG_PRXQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_DEBUG_PRXQ_SHIFT)) & GMAC_MTL_RXQ1_DEBUG_PRXQ_MASK)

#define GMAC_MTL_RXQ1_DEBUG_Reserved_31_30_MASK  (0xC0000000U)
#define GMAC_MTL_RXQ1_DEBUG_Reserved_31_30_SHIFT (30U)
#define GMAC_MTL_RXQ1_DEBUG_Reserved_31_30_WIDTH (2U)
#define GMAC_MTL_RXQ1_DEBUG_Reserved_31_30(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_DEBUG_Reserved_31_30_SHIFT)) & GMAC_MTL_RXQ1_DEBUG_Reserved_31_30_MASK)
/*! @} */

/*! @name MTL_RXQ1_CONTROL -  */
/*! @{ */

#define GMAC_MTL_RXQ1_CONTROL_RXQ_WEGT_MASK      (0x7U)
#define GMAC_MTL_RXQ1_CONTROL_RXQ_WEGT_SHIFT     (0U)
#define GMAC_MTL_RXQ1_CONTROL_RXQ_WEGT_WIDTH     (3U)
#define GMAC_MTL_RXQ1_CONTROL_RXQ_WEGT(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_CONTROL_RXQ_WEGT_SHIFT)) & GMAC_MTL_RXQ1_CONTROL_RXQ_WEGT_MASK)

#define GMAC_MTL_RXQ1_CONTROL_RXQ_FRM_ARBIT_MASK (0x8U)
#define GMAC_MTL_RXQ1_CONTROL_RXQ_FRM_ARBIT_SHIFT (3U)
#define GMAC_MTL_RXQ1_CONTROL_RXQ_FRM_ARBIT_WIDTH (1U)
#define GMAC_MTL_RXQ1_CONTROL_RXQ_FRM_ARBIT(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_CONTROL_RXQ_FRM_ARBIT_SHIFT)) & GMAC_MTL_RXQ1_CONTROL_RXQ_FRM_ARBIT_MASK)

#define GMAC_MTL_RXQ1_CONTROL_Reserved_31_4_MASK (0xFFFFFFF0U)
#define GMAC_MTL_RXQ1_CONTROL_Reserved_31_4_SHIFT (4U)
#define GMAC_MTL_RXQ1_CONTROL_Reserved_31_4_WIDTH (28U)
#define GMAC_MTL_RXQ1_CONTROL_Reserved_31_4(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ1_CONTROL_Reserved_31_4_SHIFT)) & GMAC_MTL_RXQ1_CONTROL_Reserved_31_4_MASK)
/*! @} */

/*! @name MTL_TXQ2_OPERATION_MODE -  */
/*! @{ */

#define GMAC_MTL_TXQ2_OPERATION_MODE_FTQ_MASK    (0x1U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_FTQ_SHIFT   (0U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_FTQ_WIDTH   (1U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_FTQ(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_OPERATION_MODE_FTQ_SHIFT)) & GMAC_MTL_TXQ2_OPERATION_MODE_FTQ_MASK)

#define GMAC_MTL_TXQ2_OPERATION_MODE_TSF_MASK    (0x2U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_TSF_SHIFT   (1U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_TSF_WIDTH   (1U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_TSF(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_OPERATION_MODE_TSF_SHIFT)) & GMAC_MTL_TXQ2_OPERATION_MODE_TSF_MASK)

#define GMAC_MTL_TXQ2_OPERATION_MODE_TXQEN_MASK  (0xCU)
#define GMAC_MTL_TXQ2_OPERATION_MODE_TXQEN_SHIFT (2U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_TXQEN_WIDTH (2U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_TXQEN(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_OPERATION_MODE_TXQEN_SHIFT)) & GMAC_MTL_TXQ2_OPERATION_MODE_TXQEN_MASK)

#define GMAC_MTL_TXQ2_OPERATION_MODE_TTC_MASK    (0x70U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_TTC_SHIFT   (4U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_TTC_WIDTH   (3U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_TTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_OPERATION_MODE_TTC_SHIFT)) & GMAC_MTL_TXQ2_OPERATION_MODE_TTC_MASK)

#define GMAC_MTL_TXQ2_OPERATION_MODE_Reserved_15_7_MASK (0xFF80U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_Reserved_15_7_SHIFT (7U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_Reserved_15_7_WIDTH (9U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_Reserved_15_7(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_OPERATION_MODE_Reserved_15_7_SHIFT)) & GMAC_MTL_TXQ2_OPERATION_MODE_Reserved_15_7_MASK)

#define GMAC_MTL_TXQ2_OPERATION_MODE_TQS_MASK    (0x3F0000U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_TQS_SHIFT   (16U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_TQS_WIDTH   (6U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_TQS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_OPERATION_MODE_TQS_SHIFT)) & GMAC_MTL_TXQ2_OPERATION_MODE_TQS_MASK)

#define GMAC_MTL_TXQ2_OPERATION_MODE_Reserved_31_y_MASK (0xFFC00000U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_Reserved_31_y_SHIFT (22U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_Reserved_31_y_WIDTH (10U)
#define GMAC_MTL_TXQ2_OPERATION_MODE_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_OPERATION_MODE_Reserved_31_y_SHIFT)) & GMAC_MTL_TXQ2_OPERATION_MODE_Reserved_31_y_MASK)
/*! @} */

/*! @name MTL_TXQ2_UNDERFLOW -  */
/*! @{ */

#define GMAC_MTL_TXQ2_UNDERFLOW_UFFRMCNT_MASK    (0x7FFU)
#define GMAC_MTL_TXQ2_UNDERFLOW_UFFRMCNT_SHIFT   (0U)
#define GMAC_MTL_TXQ2_UNDERFLOW_UFFRMCNT_WIDTH   (11U)
#define GMAC_MTL_TXQ2_UNDERFLOW_UFFRMCNT(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_UNDERFLOW_UFFRMCNT_SHIFT)) & GMAC_MTL_TXQ2_UNDERFLOW_UFFRMCNT_MASK)

#define GMAC_MTL_TXQ2_UNDERFLOW_UFCNTOVF_MASK    (0x800U)
#define GMAC_MTL_TXQ2_UNDERFLOW_UFCNTOVF_SHIFT   (11U)
#define GMAC_MTL_TXQ2_UNDERFLOW_UFCNTOVF_WIDTH   (1U)
#define GMAC_MTL_TXQ2_UNDERFLOW_UFCNTOVF(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_UNDERFLOW_UFCNTOVF_SHIFT)) & GMAC_MTL_TXQ2_UNDERFLOW_UFCNTOVF_MASK)

#define GMAC_MTL_TXQ2_UNDERFLOW_Reserved_31_12_MASK (0xFFFFF000U)
#define GMAC_MTL_TXQ2_UNDERFLOW_Reserved_31_12_SHIFT (12U)
#define GMAC_MTL_TXQ2_UNDERFLOW_Reserved_31_12_WIDTH (20U)
#define GMAC_MTL_TXQ2_UNDERFLOW_Reserved_31_12(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_UNDERFLOW_Reserved_31_12_SHIFT)) & GMAC_MTL_TXQ2_UNDERFLOW_Reserved_31_12_MASK)
/*! @} */

/*! @name MTL_TXQ2_DEBUG -  */
/*! @{ */

#define GMAC_MTL_TXQ2_DEBUG_TXQPAUSED_MASK       (0x1U)
#define GMAC_MTL_TXQ2_DEBUG_TXQPAUSED_SHIFT      (0U)
#define GMAC_MTL_TXQ2_DEBUG_TXQPAUSED_WIDTH      (1U)
#define GMAC_MTL_TXQ2_DEBUG_TXQPAUSED(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_DEBUG_TXQPAUSED_SHIFT)) & GMAC_MTL_TXQ2_DEBUG_TXQPAUSED_MASK)

#define GMAC_MTL_TXQ2_DEBUG_TRCSTS_MASK          (0x6U)
#define GMAC_MTL_TXQ2_DEBUG_TRCSTS_SHIFT         (1U)
#define GMAC_MTL_TXQ2_DEBUG_TRCSTS_WIDTH         (2U)
#define GMAC_MTL_TXQ2_DEBUG_TRCSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_DEBUG_TRCSTS_SHIFT)) & GMAC_MTL_TXQ2_DEBUG_TRCSTS_MASK)

#define GMAC_MTL_TXQ2_DEBUG_TWCSTS_MASK          (0x8U)
#define GMAC_MTL_TXQ2_DEBUG_TWCSTS_SHIFT         (3U)
#define GMAC_MTL_TXQ2_DEBUG_TWCSTS_WIDTH         (1U)
#define GMAC_MTL_TXQ2_DEBUG_TWCSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_DEBUG_TWCSTS_SHIFT)) & GMAC_MTL_TXQ2_DEBUG_TWCSTS_MASK)

#define GMAC_MTL_TXQ2_DEBUG_TXQSTS_MASK          (0x10U)
#define GMAC_MTL_TXQ2_DEBUG_TXQSTS_SHIFT         (4U)
#define GMAC_MTL_TXQ2_DEBUG_TXQSTS_WIDTH         (1U)
#define GMAC_MTL_TXQ2_DEBUG_TXQSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_DEBUG_TXQSTS_SHIFT)) & GMAC_MTL_TXQ2_DEBUG_TXQSTS_MASK)

#define GMAC_MTL_TXQ2_DEBUG_TXSTSFSTS_MASK       (0x20U)
#define GMAC_MTL_TXQ2_DEBUG_TXSTSFSTS_SHIFT      (5U)
#define GMAC_MTL_TXQ2_DEBUG_TXSTSFSTS_WIDTH      (1U)
#define GMAC_MTL_TXQ2_DEBUG_TXSTSFSTS(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_DEBUG_TXSTSFSTS_SHIFT)) & GMAC_MTL_TXQ2_DEBUG_TXSTSFSTS_MASK)

#define GMAC_MTL_TXQ2_DEBUG_Reserved_15_6_MASK   (0xFFC0U)
#define GMAC_MTL_TXQ2_DEBUG_Reserved_15_6_SHIFT  (6U)
#define GMAC_MTL_TXQ2_DEBUG_Reserved_15_6_WIDTH  (10U)
#define GMAC_MTL_TXQ2_DEBUG_Reserved_15_6(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_DEBUG_Reserved_15_6_SHIFT)) & GMAC_MTL_TXQ2_DEBUG_Reserved_15_6_MASK)

#define GMAC_MTL_TXQ2_DEBUG_PTXQ_MASK            (0x70000U)
#define GMAC_MTL_TXQ2_DEBUG_PTXQ_SHIFT           (16U)
#define GMAC_MTL_TXQ2_DEBUG_PTXQ_WIDTH           (3U)
#define GMAC_MTL_TXQ2_DEBUG_PTXQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_DEBUG_PTXQ_SHIFT)) & GMAC_MTL_TXQ2_DEBUG_PTXQ_MASK)

#define GMAC_MTL_TXQ2_DEBUG_Reserved_19_MASK     (0x80000U)
#define GMAC_MTL_TXQ2_DEBUG_Reserved_19_SHIFT    (19U)
#define GMAC_MTL_TXQ2_DEBUG_Reserved_19_WIDTH    (1U)
#define GMAC_MTL_TXQ2_DEBUG_Reserved_19(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_DEBUG_Reserved_19_SHIFT)) & GMAC_MTL_TXQ2_DEBUG_Reserved_19_MASK)

#define GMAC_MTL_TXQ2_DEBUG_STXSTSF_MASK         (0x700000U)
#define GMAC_MTL_TXQ2_DEBUG_STXSTSF_SHIFT        (20U)
#define GMAC_MTL_TXQ2_DEBUG_STXSTSF_WIDTH        (3U)
#define GMAC_MTL_TXQ2_DEBUG_STXSTSF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_DEBUG_STXSTSF_SHIFT)) & GMAC_MTL_TXQ2_DEBUG_STXSTSF_MASK)

#define GMAC_MTL_TXQ2_DEBUG_Reserved_31_23_MASK  (0xFF800000U)
#define GMAC_MTL_TXQ2_DEBUG_Reserved_31_23_SHIFT (23U)
#define GMAC_MTL_TXQ2_DEBUG_Reserved_31_23_WIDTH (9U)
#define GMAC_MTL_TXQ2_DEBUG_Reserved_31_23(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_DEBUG_Reserved_31_23_SHIFT)) & GMAC_MTL_TXQ2_DEBUG_Reserved_31_23_MASK)
/*! @} */

/*! @name MTL_TXQ2_ETS_CONTROL -  */
/*! @{ */

#define GMAC_MTL_TXQ2_ETS_CONTROL_Reserved_1_0_MASK (0x3U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_Reserved_1_0_SHIFT (0U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_Reserved_1_0_WIDTH (2U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_Reserved_1_0(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_ETS_CONTROL_Reserved_1_0_SHIFT)) & GMAC_MTL_TXQ2_ETS_CONTROL_Reserved_1_0_MASK)

#define GMAC_MTL_TXQ2_ETS_CONTROL_AVALG_MASK     (0x4U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_AVALG_SHIFT    (2U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_AVALG_WIDTH    (1U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_AVALG(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_ETS_CONTROL_AVALG_SHIFT)) & GMAC_MTL_TXQ2_ETS_CONTROL_AVALG_MASK)

#define GMAC_MTL_TXQ2_ETS_CONTROL_CC_MASK        (0x8U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_CC_SHIFT       (3U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_CC_WIDTH       (1U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_CC(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_ETS_CONTROL_CC_SHIFT)) & GMAC_MTL_TXQ2_ETS_CONTROL_CC_MASK)

#define GMAC_MTL_TXQ2_ETS_CONTROL_SLC_MASK       (0x70U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_SLC_SHIFT      (4U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_SLC_WIDTH      (3U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_SLC(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_ETS_CONTROL_SLC_SHIFT)) & GMAC_MTL_TXQ2_ETS_CONTROL_SLC_MASK)

#define GMAC_MTL_TXQ2_ETS_CONTROL_Reserved_31_7_MASK (0xFFFFFF80U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_Reserved_31_7_SHIFT (7U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_Reserved_31_7_WIDTH (25U)
#define GMAC_MTL_TXQ2_ETS_CONTROL_Reserved_31_7(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_ETS_CONTROL_Reserved_31_7_SHIFT)) & GMAC_MTL_TXQ2_ETS_CONTROL_Reserved_31_7_MASK)
/*! @} */

/*! @name MTL_TXQ2_ETS_STATUS -  */
/*! @{ */

#define GMAC_MTL_TXQ2_ETS_STATUS_ABS_MASK        (0xFFFFFFU)
#define GMAC_MTL_TXQ2_ETS_STATUS_ABS_SHIFT       (0U)
#define GMAC_MTL_TXQ2_ETS_STATUS_ABS_WIDTH       (24U)
#define GMAC_MTL_TXQ2_ETS_STATUS_ABS(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_ETS_STATUS_ABS_SHIFT)) & GMAC_MTL_TXQ2_ETS_STATUS_ABS_MASK)

#define GMAC_MTL_TXQ2_ETS_STATUS_Reserved_31_24_MASK (0xFF000000U)
#define GMAC_MTL_TXQ2_ETS_STATUS_Reserved_31_24_SHIFT (24U)
#define GMAC_MTL_TXQ2_ETS_STATUS_Reserved_31_24_WIDTH (8U)
#define GMAC_MTL_TXQ2_ETS_STATUS_Reserved_31_24(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_ETS_STATUS_Reserved_31_24_SHIFT)) & GMAC_MTL_TXQ2_ETS_STATUS_Reserved_31_24_MASK)
/*! @} */

/*! @name MTL_TXQ2_QUANTUM_WEIGHT -  */
/*! @{ */

#define GMAC_MTL_TXQ2_QUANTUM_WEIGHT_ISCQW_MASK  (0x1FFFFFU)
#define GMAC_MTL_TXQ2_QUANTUM_WEIGHT_ISCQW_SHIFT (0U)
#define GMAC_MTL_TXQ2_QUANTUM_WEIGHT_ISCQW_WIDTH (21U)
#define GMAC_MTL_TXQ2_QUANTUM_WEIGHT_ISCQW(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_QUANTUM_WEIGHT_ISCQW_SHIFT)) & GMAC_MTL_TXQ2_QUANTUM_WEIGHT_ISCQW_MASK)

#define GMAC_MTL_TXQ2_QUANTUM_WEIGHT_Reserved_31_21_MASK (0xFFE00000U)
#define GMAC_MTL_TXQ2_QUANTUM_WEIGHT_Reserved_31_21_SHIFT (21U)
#define GMAC_MTL_TXQ2_QUANTUM_WEIGHT_Reserved_31_21_WIDTH (11U)
#define GMAC_MTL_TXQ2_QUANTUM_WEIGHT_Reserved_31_21(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_QUANTUM_WEIGHT_Reserved_31_21_SHIFT)) & GMAC_MTL_TXQ2_QUANTUM_WEIGHT_Reserved_31_21_MASK)
/*! @} */

/*! @name MTL_TXQ2_SENDSLOPECREDIT -  */
/*! @{ */

#define GMAC_MTL_TXQ2_SENDSLOPECREDIT_SSC_MASK   (0x3FFFU)
#define GMAC_MTL_TXQ2_SENDSLOPECREDIT_SSC_SHIFT  (0U)
#define GMAC_MTL_TXQ2_SENDSLOPECREDIT_SSC_WIDTH  (14U)
#define GMAC_MTL_TXQ2_SENDSLOPECREDIT_SSC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_SENDSLOPECREDIT_SSC_SHIFT)) & GMAC_MTL_TXQ2_SENDSLOPECREDIT_SSC_MASK)

#define GMAC_MTL_TXQ2_SENDSLOPECREDIT_Reserved_31_14_MASK (0xFFFFC000U)
#define GMAC_MTL_TXQ2_SENDSLOPECREDIT_Reserved_31_14_SHIFT (14U)
#define GMAC_MTL_TXQ2_SENDSLOPECREDIT_Reserved_31_14_WIDTH (18U)
#define GMAC_MTL_TXQ2_SENDSLOPECREDIT_Reserved_31_14(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_SENDSLOPECREDIT_Reserved_31_14_SHIFT)) & GMAC_MTL_TXQ2_SENDSLOPECREDIT_Reserved_31_14_MASK)
/*! @} */

/*! @name MTL_TXQ2_HICREDIT -  */
/*! @{ */

#define GMAC_MTL_TXQ2_HICREDIT_HC_MASK           (0x1FFFFFFFU)
#define GMAC_MTL_TXQ2_HICREDIT_HC_SHIFT          (0U)
#define GMAC_MTL_TXQ2_HICREDIT_HC_WIDTH          (29U)
#define GMAC_MTL_TXQ2_HICREDIT_HC(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_HICREDIT_HC_SHIFT)) & GMAC_MTL_TXQ2_HICREDIT_HC_MASK)

#define GMAC_MTL_TXQ2_HICREDIT_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MTL_TXQ2_HICREDIT_Reserved_31_29_SHIFT (29U)
#define GMAC_MTL_TXQ2_HICREDIT_Reserved_31_29_WIDTH (3U)
#define GMAC_MTL_TXQ2_HICREDIT_Reserved_31_29(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_HICREDIT_Reserved_31_29_SHIFT)) & GMAC_MTL_TXQ2_HICREDIT_Reserved_31_29_MASK)
/*! @} */

/*! @name MTL_TXQ2_LOCREDIT -  */
/*! @{ */

#define GMAC_MTL_TXQ2_LOCREDIT_LC_MASK           (0x1FFFFFFFU)
#define GMAC_MTL_TXQ2_LOCREDIT_LC_SHIFT          (0U)
#define GMAC_MTL_TXQ2_LOCREDIT_LC_WIDTH          (29U)
#define GMAC_MTL_TXQ2_LOCREDIT_LC(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_LOCREDIT_LC_SHIFT)) & GMAC_MTL_TXQ2_LOCREDIT_LC_MASK)

#define GMAC_MTL_TXQ2_LOCREDIT_Reserved_31_29_MASK (0xE0000000U)
#define GMAC_MTL_TXQ2_LOCREDIT_Reserved_31_29_SHIFT (29U)
#define GMAC_MTL_TXQ2_LOCREDIT_Reserved_31_29_WIDTH (3U)
#define GMAC_MTL_TXQ2_LOCREDIT_Reserved_31_29(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_TXQ2_LOCREDIT_Reserved_31_29_SHIFT)) & GMAC_MTL_TXQ2_LOCREDIT_Reserved_31_29_MASK)
/*! @} */

/*! @name MTL_Q2_INTERRUPT_CONTROL_STATUS -  */
/*! @{ */

#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_TXUNFIS_MASK (0x1U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_TXUNFIS_SHIFT (0U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_TXUNFIS_WIDTH (1U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_TXUNFIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_TXUNFIS_SHIFT)) & GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_TXUNFIS_MASK)

#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_ABPSIS_MASK (0x2U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_ABPSIS_SHIFT (1U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_ABPSIS_WIDTH (1U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_ABPSIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_ABPSIS_SHIFT)) & GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_ABPSIS_MASK)

#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_7_2_MASK (0xFCU)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_7_2_SHIFT (2U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_7_2_WIDTH (6U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_7_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_7_2_SHIFT)) & GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_7_2_MASK)

#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_TXUIE_MASK (0x100U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_TXUIE_SHIFT (8U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_TXUIE_WIDTH (1U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_TXUIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_TXUIE_SHIFT)) & GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_TXUIE_MASK)

#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_ABPSIE_MASK (0x200U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_ABPSIE_SHIFT (9U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_ABPSIE_WIDTH (1U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_ABPSIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_ABPSIE_SHIFT)) & GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_ABPSIE_MASK)

#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_15_10_MASK (0xFC00U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_15_10_SHIFT (10U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_15_10_WIDTH (6U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_15_10(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_15_10_SHIFT)) & GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_15_10_MASK)

#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_RXOVFIS_MASK (0x10000U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_RXOVFIS_SHIFT (16U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_RXOVFIS_WIDTH (1U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_RXOVFIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_RXOVFIS_SHIFT)) & GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_RXOVFIS_MASK)

#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_23_17_MASK (0xFE0000U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_23_17_SHIFT (17U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_23_17_WIDTH (7U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_23_17(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_23_17_SHIFT)) & GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_23_17_MASK)

#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_RXOIE_MASK (0x1000000U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_RXOIE_SHIFT (24U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_RXOIE_WIDTH (1U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_RXOIE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_RXOIE_SHIFT)) & GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_RXOIE_MASK)

#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_31_25_MASK (0xFE000000U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_31_25_SHIFT (25U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_31_25_WIDTH (7U)
#define GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_31_25(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_31_25_SHIFT)) & GMAC_MTL_Q2_INTERRUPT_CONTROL_STATUS_Reserved_31_25_MASK)
/*! @} */

/*! @name MTL_RXQ2_OPERATION_MODE -  */
/*! @{ */

#define GMAC_MTL_RXQ2_OPERATION_MODE_RTC_MASK    (0x3U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RTC_SHIFT   (0U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RTC_WIDTH   (2U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RTC(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_OPERATION_MODE_RTC_SHIFT)) & GMAC_MTL_RXQ2_OPERATION_MODE_RTC_MASK)

#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_2_MASK (0x4U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_2_SHIFT (2U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_2_WIDTH (1U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_2_SHIFT)) & GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_2_MASK)

#define GMAC_MTL_RXQ2_OPERATION_MODE_FUP_MASK    (0x8U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_FUP_SHIFT   (3U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_FUP_WIDTH   (1U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_FUP(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_OPERATION_MODE_FUP_SHIFT)) & GMAC_MTL_RXQ2_OPERATION_MODE_FUP_MASK)

#define GMAC_MTL_RXQ2_OPERATION_MODE_FEP_MASK    (0x10U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_FEP_SHIFT   (4U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_FEP_WIDTH   (1U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_FEP(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_OPERATION_MODE_FEP_SHIFT)) & GMAC_MTL_RXQ2_OPERATION_MODE_FEP_MASK)

#define GMAC_MTL_RXQ2_OPERATION_MODE_RSF_MASK    (0x20U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RSF_SHIFT   (5U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RSF_WIDTH   (1U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RSF(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_OPERATION_MODE_RSF_SHIFT)) & GMAC_MTL_RXQ2_OPERATION_MODE_RSF_MASK)

#define GMAC_MTL_RXQ2_OPERATION_MODE_DIS_TCP_EF_MASK (0x40U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_DIS_TCP_EF_SHIFT (6U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_DIS_TCP_EF_WIDTH (1U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_DIS_TCP_EF(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_OPERATION_MODE_DIS_TCP_EF_SHIFT)) & GMAC_MTL_RXQ2_OPERATION_MODE_DIS_TCP_EF_MASK)

#define GMAC_MTL_RXQ2_OPERATION_MODE_EHFC_MASK   (0x80U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_EHFC_SHIFT  (7U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_EHFC_WIDTH  (1U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_EHFC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_OPERATION_MODE_EHFC_SHIFT)) & GMAC_MTL_RXQ2_OPERATION_MODE_EHFC_MASK)

#define GMAC_MTL_RXQ2_OPERATION_MODE_RFA_MASK    (0x1F00U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RFA_SHIFT   (8U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RFA_WIDTH   (5U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RFA(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_OPERATION_MODE_RFA_SHIFT)) & GMAC_MTL_RXQ2_OPERATION_MODE_RFA_MASK)

#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_13_y_MASK (0x2000U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_13_y_SHIFT (13U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_13_y_WIDTH (1U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_13_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_13_y_SHIFT)) & GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_13_y_MASK)

#define GMAC_MTL_RXQ2_OPERATION_MODE_RFD_MASK    (0x7C000U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RFD_SHIFT   (14U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RFD_WIDTH   (5U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RFD(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_OPERATION_MODE_RFD_SHIFT)) & GMAC_MTL_RXQ2_OPERATION_MODE_RFD_MASK)

#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_19_y_MASK (0x80000U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_19_y_SHIFT (19U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_19_y_WIDTH (1U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_19_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_19_y_SHIFT)) & GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_19_y_MASK)

#define GMAC_MTL_RXQ2_OPERATION_MODE_RQS_MASK    (0x3F00000U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RQS_SHIFT   (20U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RQS_WIDTH   (6U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_RQS(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_OPERATION_MODE_RQS_SHIFT)) & GMAC_MTL_RXQ2_OPERATION_MODE_RQS_MASK)

#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_31_y_MASK (0xFC000000U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_31_y_SHIFT (26U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_31_y_WIDTH (6U)
#define GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_31_y(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_31_y_SHIFT)) & GMAC_MTL_RXQ2_OPERATION_MODE_Reserved_31_y_MASK)
/*! @} */

/*! @name MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT -  */
/*! @{ */

#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_MASK (0x7FFU)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_SHIFT (0U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_WIDTH (11U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_SHIFT)) & GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_OVFPKTCNT_MASK)

#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_MASK (0x800U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_SHIFT (11U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_WIDTH (1U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_SHIFT)) & GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_OVFCNTOVF_MASK)

#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_MASK (0xF000U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_SHIFT (12U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_WIDTH (4U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_SHIFT)) & GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_Reserved_15_12_MASK)

#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_MASK (0x7FF0000U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_SHIFT (16U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_WIDTH (11U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_SHIFT)) & GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_MISPKTCNT_MASK)

#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_MASK (0x8000000U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_SHIFT (27U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_WIDTH (1U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_SHIFT)) & GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_MISCNTOVF_MASK)

#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_MASK (0xF0000000U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_SHIFT (28U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_WIDTH (4U)
#define GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28(x) (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_SHIFT)) & GMAC_MTL_RXQ2_MISSED_PACKET_OVERFLOW_CNT_Reserved_31_28_MASK)
/*! @} */

/*! @name MTL_RXQ2_DEBUG -  */
/*! @{ */

#define GMAC_MTL_RXQ2_DEBUG_RWCSTS_MASK          (0x1U)
#define GMAC_MTL_RXQ2_DEBUG_RWCSTS_SHIFT         (0U)
#define GMAC_MTL_RXQ2_DEBUG_RWCSTS_WIDTH         (1U)
#define GMAC_MTL_RXQ2_DEBUG_RWCSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_DEBUG_RWCSTS_SHIFT)) & GMAC_MTL_RXQ2_DEBUG_RWCSTS_MASK)

#define GMAC_MTL_RXQ2_DEBUG_RRCSTS_MASK          (0x6U)
#define GMAC_MTL_RXQ2_DEBUG_RRCSTS_SHIFT         (1U)
#define GMAC_MTL_RXQ2_DEBUG_RRCSTS_WIDTH         (2U)
#define GMAC_MTL_RXQ2_DEBUG_RRCSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_DEBUG_RRCSTS_SHIFT)) & GMAC_MTL_RXQ2_DEBUG_RRCSTS_MASK)

#define GMAC_MTL_RXQ2_DEBUG_Reserved_3_MASK      (0x8U)
#define GMAC_MTL_RXQ2_DEBUG_Reserved_3_SHIFT     (3U)
#define GMAC_MTL_RXQ2_DEBUG_Reserved_3_WIDTH     (1U)
#define GMAC_MTL_RXQ2_DEBUG_Reserved_3(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_DEBUG_Reserved_3_SHIFT)) & GMAC_MTL_RXQ2_DEBUG_Reserved_3_MASK)

#define GMAC_MTL_RXQ2_DEBUG_RXQSTS_MASK          (0x30U)
#define GMAC_MTL_RXQ2_DEBUG_RXQSTS_SHIFT         (4U)
#define GMAC_MTL_RXQ2_DEBUG_RXQSTS_WIDTH         (2U)
#define GMAC_MTL_RXQ2_DEBUG_RXQSTS(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_DEBUG_RXQSTS_SHIFT)) & GMAC_MTL_RXQ2_DEBUG_RXQSTS_MASK)

#define GMAC_MTL_RXQ2_DEBUG_Reserved_15_6_MASK   (0xFFC0U)
#define GMAC_MTL_RXQ2_DEBUG_Reserved_15_6_SHIFT  (6U)
#define GMAC_MTL_RXQ2_DEBUG_Reserved_15_6_WIDTH  (10U)
#define GMAC_MTL_RXQ2_DEBUG_Reserved_15_6(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_DEBUG_Reserved_15_6_SHIFT)) & GMAC_MTL_RXQ2_DEBUG_Reserved_15_6_MASK)

#define GMAC_MTL_RXQ2_DEBUG_PRXQ_MASK            (0x3FFF0000U)
#define GMAC_MTL_RXQ2_DEBUG_PRXQ_SHIFT           (16U)
#define GMAC_MTL_RXQ2_DEBUG_PRXQ_WIDTH           (14U)
#define GMAC_MTL_RXQ2_DEBUG_PRXQ(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_DEBUG_PRXQ_SHIFT)) & GMAC_MTL_RXQ2_DEBUG_PRXQ_MASK)

#define GMAC_MTL_RXQ2_DEBUG_Reserved_31_30_MASK  (0xC0000000U)
#define GMAC_MTL_RXQ2_DEBUG_Reserved_31_30_SHIFT (30U)
#define GMAC_MTL_RXQ2_DEBUG_Reserved_31_30_WIDTH (2U)
#define GMAC_MTL_RXQ2_DEBUG_Reserved_31_30(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_DEBUG_Reserved_31_30_SHIFT)) & GMAC_MTL_RXQ2_DEBUG_Reserved_31_30_MASK)
/*! @} */

/*! @name MTL_RXQ2_CONTROL -  */
/*! @{ */

#define GMAC_MTL_RXQ2_CONTROL_RXQ_WEGT_MASK      (0x7U)
#define GMAC_MTL_RXQ2_CONTROL_RXQ_WEGT_SHIFT     (0U)
#define GMAC_MTL_RXQ2_CONTROL_RXQ_WEGT_WIDTH     (3U)
#define GMAC_MTL_RXQ2_CONTROL_RXQ_WEGT(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_CONTROL_RXQ_WEGT_SHIFT)) & GMAC_MTL_RXQ2_CONTROL_RXQ_WEGT_MASK)

#define GMAC_MTL_RXQ2_CONTROL_RXQ_FRM_ARBIT_MASK (0x8U)
#define GMAC_MTL_RXQ2_CONTROL_RXQ_FRM_ARBIT_SHIFT (3U)
#define GMAC_MTL_RXQ2_CONTROL_RXQ_FRM_ARBIT_WIDTH (1U)
#define GMAC_MTL_RXQ2_CONTROL_RXQ_FRM_ARBIT(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_CONTROL_RXQ_FRM_ARBIT_SHIFT)) & GMAC_MTL_RXQ2_CONTROL_RXQ_FRM_ARBIT_MASK)

#define GMAC_MTL_RXQ2_CONTROL_Reserved_31_4_MASK (0xFFFFFFF0U)
#define GMAC_MTL_RXQ2_CONTROL_Reserved_31_4_SHIFT (4U)
#define GMAC_MTL_RXQ2_CONTROL_Reserved_31_4_WIDTH (28U)
#define GMAC_MTL_RXQ2_CONTROL_Reserved_31_4(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_MTL_RXQ2_CONTROL_Reserved_31_4_SHIFT)) & GMAC_MTL_RXQ2_CONTROL_Reserved_31_4_MASK)
/*! @} */

/*! @name DMA_MODE -  */
/*! @{ */

#define GMAC_DMA_MODE_SWR_MASK                   (0x1U)
#define GMAC_DMA_MODE_SWR_SHIFT                  (0U)
#define GMAC_DMA_MODE_SWR_WIDTH                  (1U)
#define GMAC_DMA_MODE_SWR(x)                     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_SWR_SHIFT)) & GMAC_DMA_MODE_SWR_MASK)

#define GMAC_DMA_MODE_DA_MASK                    (0x2U)
#define GMAC_DMA_MODE_DA_SHIFT                   (1U)
#define GMAC_DMA_MODE_DA_WIDTH                   (1U)
#define GMAC_DMA_MODE_DA(x)                      (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_DA_SHIFT)) & GMAC_DMA_MODE_DA_MASK)

#define GMAC_DMA_MODE_TAA_MASK                   (0x1CU)
#define GMAC_DMA_MODE_TAA_SHIFT                  (2U)
#define GMAC_DMA_MODE_TAA_WIDTH                  (3U)
#define GMAC_DMA_MODE_TAA(x)                     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_TAA_SHIFT)) & GMAC_DMA_MODE_TAA_MASK)

#define GMAC_DMA_MODE_Reserved_7_5_MASK          (0xE0U)
#define GMAC_DMA_MODE_Reserved_7_5_SHIFT         (5U)
#define GMAC_DMA_MODE_Reserved_7_5_WIDTH         (3U)
#define GMAC_DMA_MODE_Reserved_7_5(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_Reserved_7_5_SHIFT)) & GMAC_DMA_MODE_Reserved_7_5_MASK)

#define GMAC_DMA_MODE_Reserved_DSPW_MASK         (0x100U)
#define GMAC_DMA_MODE_Reserved_DSPW_SHIFT        (8U)
#define GMAC_DMA_MODE_Reserved_DSPW_WIDTH        (1U)
#define GMAC_DMA_MODE_Reserved_DSPW(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_Reserved_DSPW_SHIFT)) & GMAC_DMA_MODE_Reserved_DSPW_MASK)

#define GMAC_DMA_MODE_ARBC_MASK                  (0x200U)
#define GMAC_DMA_MODE_ARBC_SHIFT                 (9U)
#define GMAC_DMA_MODE_ARBC_WIDTH                 (1U)
#define GMAC_DMA_MODE_ARBC(x)                    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_ARBC_SHIFT)) & GMAC_DMA_MODE_ARBC_MASK)

#define GMAC_DMA_MODE_Reserved_SCSW_MASK         (0x400U)
#define GMAC_DMA_MODE_Reserved_SCSW_SHIFT        (10U)
#define GMAC_DMA_MODE_Reserved_SCSW_WIDTH        (1U)
#define GMAC_DMA_MODE_Reserved_SCSW(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_Reserved_SCSW_SHIFT)) & GMAC_DMA_MODE_Reserved_SCSW_MASK)

#define GMAC_DMA_MODE_TXPR_MASK                  (0x800U)
#define GMAC_DMA_MODE_TXPR_SHIFT                 (11U)
#define GMAC_DMA_MODE_TXPR_WIDTH                 (1U)
#define GMAC_DMA_MODE_TXPR(x)                    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_TXPR_SHIFT)) & GMAC_DMA_MODE_TXPR_MASK)

#define GMAC_DMA_MODE_PR_MASK                    (0x7000U)
#define GMAC_DMA_MODE_PR_SHIFT                   (12U)
#define GMAC_DMA_MODE_PR_WIDTH                   (3U)
#define GMAC_DMA_MODE_PR(x)                      (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_PR_SHIFT)) & GMAC_DMA_MODE_PR_MASK)

#define GMAC_DMA_MODE_Reserved_15_MASK           (0x8000U)
#define GMAC_DMA_MODE_Reserved_15_SHIFT          (15U)
#define GMAC_DMA_MODE_Reserved_15_WIDTH          (1U)
#define GMAC_DMA_MODE_Reserved_15(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_Reserved_15_SHIFT)) & GMAC_DMA_MODE_Reserved_15_MASK)

#define GMAC_DMA_MODE_INTM_MASK                  (0x30000U)
#define GMAC_DMA_MODE_INTM_SHIFT                 (16U)
#define GMAC_DMA_MODE_INTM_WIDTH                 (2U)
#define GMAC_DMA_MODE_INTM(x)                    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_INTM_SHIFT)) & GMAC_DMA_MODE_INTM_MASK)

#define GMAC_DMA_MODE_Reserved_18_MASK           (0x40000U)
#define GMAC_DMA_MODE_Reserved_18_SHIFT          (18U)
#define GMAC_DMA_MODE_Reserved_18_WIDTH          (1U)
#define GMAC_DMA_MODE_Reserved_18(x)             (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_Reserved_18_SHIFT)) & GMAC_DMA_MODE_Reserved_18_MASK)

#define GMAC_DMA_MODE_Reserved_DCHE_MASK         (0x80000U)
#define GMAC_DMA_MODE_Reserved_DCHE_SHIFT        (19U)
#define GMAC_DMA_MODE_Reserved_DCHE_WIDTH        (1U)
#define GMAC_DMA_MODE_Reserved_DCHE(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_Reserved_DCHE_SHIFT)) & GMAC_DMA_MODE_Reserved_DCHE_MASK)

#define GMAC_DMA_MODE_Reserved_TNDF_MASK         (0x300000U)
#define GMAC_DMA_MODE_Reserved_TNDF_SHIFT        (20U)
#define GMAC_DMA_MODE_Reserved_TNDF_WIDTH        (2U)
#define GMAC_DMA_MODE_Reserved_TNDF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_Reserved_TNDF_SHIFT)) & GMAC_DMA_MODE_Reserved_TNDF_MASK)

#define GMAC_DMA_MODE_Reserved_RNDF_MASK         (0xC00000U)
#define GMAC_DMA_MODE_Reserved_RNDF_SHIFT        (22U)
#define GMAC_DMA_MODE_Reserved_RNDF_WIDTH        (2U)
#define GMAC_DMA_MODE_Reserved_RNDF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_Reserved_RNDF_SHIFT)) & GMAC_DMA_MODE_Reserved_RNDF_MASK)

#define GMAC_DMA_MODE_Reserved_31_24_MASK        (0xFF000000U)
#define GMAC_DMA_MODE_Reserved_31_24_SHIFT       (24U)
#define GMAC_DMA_MODE_Reserved_31_24_WIDTH       (8U)
#define GMAC_DMA_MODE_Reserved_31_24(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_MODE_Reserved_31_24_SHIFT)) & GMAC_DMA_MODE_Reserved_31_24_MASK)
/*! @} */

/*! @name DMA_SYSBUS_MODE -  */
/*! @{ */

#define GMAC_DMA_SYSBUS_MODE_FB_MASK             (0x1U)
#define GMAC_DMA_SYSBUS_MODE_FB_SHIFT            (0U)
#define GMAC_DMA_SYSBUS_MODE_FB_WIDTH            (1U)
#define GMAC_DMA_SYSBUS_MODE_FB(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_FB_SHIFT)) & GMAC_DMA_SYSBUS_MODE_FB_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN4_MASK (0x2U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN4_SHIFT (1U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN4_WIDTH (1U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN4(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_BLEN4_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_BLEN4_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN8_MASK (0x4U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN8_SHIFT (2U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN8_WIDTH (1U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN8(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_BLEN8_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_BLEN8_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN16_MASK (0x8U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN16_SHIFT (3U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN16_WIDTH (1U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN16(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_BLEN16_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_BLEN16_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN32_MASK (0x10U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN32_SHIFT (4U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN32_WIDTH (1U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN32(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_BLEN32_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_BLEN32_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN64_MASK (0x20U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN64_SHIFT (5U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN64_WIDTH (1U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN64(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_BLEN64_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_BLEN64_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN128_MASK (0x40U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN128_SHIFT (6U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN128_WIDTH (1U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN128(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_BLEN128_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_BLEN128_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN256_MASK (0x80U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN256_SHIFT (7U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN256_WIDTH (1U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_BLEN256(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_BLEN256_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_BLEN256_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_9_8_MASK   (0x300U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_9_8_SHIFT  (8U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_9_8_WIDTH  (2U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_9_8(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_9_8_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_9_8_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_AALE_MASK  (0x400U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_AALE_SHIFT (10U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_AALE_WIDTH (1U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_AALE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_AALE_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_AALE_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_EAME_MASK  (0x800U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_EAME_SHIFT (11U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_EAME_WIDTH (1U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_EAME(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_EAME_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_EAME_MASK)

#define GMAC_DMA_SYSBUS_MODE_AAL_MASK            (0x1000U)
#define GMAC_DMA_SYSBUS_MODE_AAL_SHIFT           (12U)
#define GMAC_DMA_SYSBUS_MODE_AAL_WIDTH           (1U)
#define GMAC_DMA_SYSBUS_MODE_AAL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_AAL_SHIFT)) & GMAC_DMA_SYSBUS_MODE_AAL_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_ONEKBBE_MASK (0x2000U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_ONEKBBE_SHIFT (13U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_ONEKBBE_WIDTH (1U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_ONEKBBE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_ONEKBBE_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_ONEKBBE_MASK)

#define GMAC_DMA_SYSBUS_MODE_MB_MASK             (0x4000U)
#define GMAC_DMA_SYSBUS_MODE_MB_SHIFT            (14U)
#define GMAC_DMA_SYSBUS_MODE_MB_WIDTH            (1U)
#define GMAC_DMA_SYSBUS_MODE_MB(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_MB_SHIFT)) & GMAC_DMA_SYSBUS_MODE_MB_MASK)

#define GMAC_DMA_SYSBUS_MODE_RB_MASK             (0x8000U)
#define GMAC_DMA_SYSBUS_MODE_RB_SHIFT            (15U)
#define GMAC_DMA_SYSBUS_MODE_RB_WIDTH            (1U)
#define GMAC_DMA_SYSBUS_MODE_RB(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_RB_SHIFT)) & GMAC_DMA_SYSBUS_MODE_RB_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_RD_OSR_LMT_MASK (0x70000U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_RD_OSR_LMT_SHIFT (16U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_RD_OSR_LMT_WIDTH (3U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_RD_OSR_LMT(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_RD_OSR_LMT_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_RD_OSR_LMT_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_23_y_MASK  (0xF80000U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_23_y_SHIFT (19U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_23_y_WIDTH (5U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_23_y(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_23_y_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_23_y_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_WR_OSR_LMT_MASK (0x7000000U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_WR_OSR_LMT_SHIFT (24U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_WR_OSR_LMT_WIDTH (3U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_WR_OSR_LMT(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_WR_OSR_LMT_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_WR_OSR_LMT_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_29_y_MASK  (0x38000000U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_29_y_SHIFT (27U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_29_y_WIDTH (3U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_29_y(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_29_y_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_29_y_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_LPI_XIT_PKT_MASK (0x40000000U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_LPI_XIT_PKT_SHIFT (30U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_LPI_XIT_PKT_WIDTH (1U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_LPI_XIT_PKT(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_LPI_XIT_PKT_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_LPI_XIT_PKT_MASK)

#define GMAC_DMA_SYSBUS_MODE_Reserved_EN_LPI_MASK (0x80000000U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_EN_LPI_SHIFT (31U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_EN_LPI_WIDTH (1U)
#define GMAC_DMA_SYSBUS_MODE_Reserved_EN_LPI(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SYSBUS_MODE_Reserved_EN_LPI_SHIFT)) & GMAC_DMA_SYSBUS_MODE_Reserved_EN_LPI_MASK)
/*! @} */

/*! @name DMA_INTERRUPT_STATUS -  */
/*! @{ */

#define GMAC_DMA_INTERRUPT_STATUS_DC0IS_MASK     (0x1U)
#define GMAC_DMA_INTERRUPT_STATUS_DC0IS_SHIFT    (0U)
#define GMAC_DMA_INTERRUPT_STATUS_DC0IS_WIDTH    (1U)
#define GMAC_DMA_INTERRUPT_STATUS_DC0IS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_INTERRUPT_STATUS_DC0IS_SHIFT)) & GMAC_DMA_INTERRUPT_STATUS_DC0IS_MASK)

#define GMAC_DMA_INTERRUPT_STATUS_DC1IS_MASK     (0x2U)
#define GMAC_DMA_INTERRUPT_STATUS_DC1IS_SHIFT    (1U)
#define GMAC_DMA_INTERRUPT_STATUS_DC1IS_WIDTH    (1U)
#define GMAC_DMA_INTERRUPT_STATUS_DC1IS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_INTERRUPT_STATUS_DC1IS_SHIFT)) & GMAC_DMA_INTERRUPT_STATUS_DC1IS_MASK)

#define GMAC_DMA_INTERRUPT_STATUS_DC2IS_MASK     (0x4U)
#define GMAC_DMA_INTERRUPT_STATUS_DC2IS_SHIFT    (2U)
#define GMAC_DMA_INTERRUPT_STATUS_DC2IS_WIDTH    (1U)
#define GMAC_DMA_INTERRUPT_STATUS_DC2IS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_INTERRUPT_STATUS_DC2IS_SHIFT)) & GMAC_DMA_INTERRUPT_STATUS_DC2IS_MASK)

#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC3IS_MASK (0x8U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC3IS_SHIFT (3U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC3IS_WIDTH (1U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC3IS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_INTERRUPT_STATUS_Reserved_DC3IS_SHIFT)) & GMAC_DMA_INTERRUPT_STATUS_Reserved_DC3IS_MASK)

#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC4IS_MASK (0x10U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC4IS_SHIFT (4U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC4IS_WIDTH (1U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC4IS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_INTERRUPT_STATUS_Reserved_DC4IS_SHIFT)) & GMAC_DMA_INTERRUPT_STATUS_Reserved_DC4IS_MASK)

#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC5IS_MASK (0x20U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC5IS_SHIFT (5U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC5IS_WIDTH (1U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC5IS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_INTERRUPT_STATUS_Reserved_DC5IS_SHIFT)) & GMAC_DMA_INTERRUPT_STATUS_Reserved_DC5IS_MASK)

#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC6IS_MASK (0x40U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC6IS_SHIFT (6U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC6IS_WIDTH (1U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC6IS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_INTERRUPT_STATUS_Reserved_DC6IS_SHIFT)) & GMAC_DMA_INTERRUPT_STATUS_Reserved_DC6IS_MASK)

#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC7IS_MASK (0x80U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC7IS_SHIFT (7U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC7IS_WIDTH (1U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_DC7IS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_INTERRUPT_STATUS_Reserved_DC7IS_SHIFT)) & GMAC_DMA_INTERRUPT_STATUS_Reserved_DC7IS_MASK)

#define GMAC_DMA_INTERRUPT_STATUS_Reserved_15_8_MASK (0xFF00U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_15_8_SHIFT (8U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_15_8_WIDTH (8U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_15_8(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_INTERRUPT_STATUS_Reserved_15_8_SHIFT)) & GMAC_DMA_INTERRUPT_STATUS_Reserved_15_8_MASK)

#define GMAC_DMA_INTERRUPT_STATUS_MTLIS_MASK     (0x10000U)
#define GMAC_DMA_INTERRUPT_STATUS_MTLIS_SHIFT    (16U)
#define GMAC_DMA_INTERRUPT_STATUS_MTLIS_WIDTH    (1U)
#define GMAC_DMA_INTERRUPT_STATUS_MTLIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_INTERRUPT_STATUS_MTLIS_SHIFT)) & GMAC_DMA_INTERRUPT_STATUS_MTLIS_MASK)

#define GMAC_DMA_INTERRUPT_STATUS_MACIS_MASK     (0x20000U)
#define GMAC_DMA_INTERRUPT_STATUS_MACIS_SHIFT    (17U)
#define GMAC_DMA_INTERRUPT_STATUS_MACIS_WIDTH    (1U)
#define GMAC_DMA_INTERRUPT_STATUS_MACIS(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_INTERRUPT_STATUS_MACIS_SHIFT)) & GMAC_DMA_INTERRUPT_STATUS_MACIS_MASK)

#define GMAC_DMA_INTERRUPT_STATUS_Reserved_31_18_MASK (0xFFFC0000U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_31_18_SHIFT (18U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_31_18_WIDTH (14U)
#define GMAC_DMA_INTERRUPT_STATUS_Reserved_31_18(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_INTERRUPT_STATUS_Reserved_31_18_SHIFT)) & GMAC_DMA_INTERRUPT_STATUS_Reserved_31_18_MASK)
/*! @} */

/*! @name DMA_DEBUG_STATUS0 -  */
/*! @{ */

#define GMAC_DMA_DEBUG_STATUS0_AXWHSTS_MASK      (0x1U)
#define GMAC_DMA_DEBUG_STATUS0_AXWHSTS_SHIFT     (0U)
#define GMAC_DMA_DEBUG_STATUS0_AXWHSTS_WIDTH     (1U)
#define GMAC_DMA_DEBUG_STATUS0_AXWHSTS(x)        (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_DEBUG_STATUS0_AXWHSTS_SHIFT)) & GMAC_DMA_DEBUG_STATUS0_AXWHSTS_MASK)

#define GMAC_DMA_DEBUG_STATUS0_Reserved_AXRHSTS_MASK (0x2U)
#define GMAC_DMA_DEBUG_STATUS0_Reserved_AXRHSTS_SHIFT (1U)
#define GMAC_DMA_DEBUG_STATUS0_Reserved_AXRHSTS_WIDTH (1U)
#define GMAC_DMA_DEBUG_STATUS0_Reserved_AXRHSTS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_DEBUG_STATUS0_Reserved_AXRHSTS_SHIFT)) & GMAC_DMA_DEBUG_STATUS0_Reserved_AXRHSTS_MASK)

#define GMAC_DMA_DEBUG_STATUS0_Reserved_7_2_MASK (0xFCU)
#define GMAC_DMA_DEBUG_STATUS0_Reserved_7_2_SHIFT (2U)
#define GMAC_DMA_DEBUG_STATUS0_Reserved_7_2_WIDTH (6U)
#define GMAC_DMA_DEBUG_STATUS0_Reserved_7_2(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_DEBUG_STATUS0_Reserved_7_2_SHIFT)) & GMAC_DMA_DEBUG_STATUS0_Reserved_7_2_MASK)

#define GMAC_DMA_DEBUG_STATUS0_RPS0_MASK         (0xF00U)
#define GMAC_DMA_DEBUG_STATUS0_RPS0_SHIFT        (8U)
#define GMAC_DMA_DEBUG_STATUS0_RPS0_WIDTH        (4U)
#define GMAC_DMA_DEBUG_STATUS0_RPS0(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_DEBUG_STATUS0_RPS0_SHIFT)) & GMAC_DMA_DEBUG_STATUS0_RPS0_MASK)

#define GMAC_DMA_DEBUG_STATUS0_TPS0_MASK         (0xF000U)
#define GMAC_DMA_DEBUG_STATUS0_TPS0_SHIFT        (12U)
#define GMAC_DMA_DEBUG_STATUS0_TPS0_WIDTH        (4U)
#define GMAC_DMA_DEBUG_STATUS0_TPS0(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_DEBUG_STATUS0_TPS0_SHIFT)) & GMAC_DMA_DEBUG_STATUS0_TPS0_MASK)

#define GMAC_DMA_DEBUG_STATUS0_RPS1_MASK         (0xF0000U)
#define GMAC_DMA_DEBUG_STATUS0_RPS1_SHIFT        (16U)
#define GMAC_DMA_DEBUG_STATUS0_RPS1_WIDTH        (4U)
#define GMAC_DMA_DEBUG_STATUS0_RPS1(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_DEBUG_STATUS0_RPS1_SHIFT)) & GMAC_DMA_DEBUG_STATUS0_RPS1_MASK)

#define GMAC_DMA_DEBUG_STATUS0_TPS1_MASK         (0xF00000U)
#define GMAC_DMA_DEBUG_STATUS0_TPS1_SHIFT        (20U)
#define GMAC_DMA_DEBUG_STATUS0_TPS1_WIDTH        (4U)
#define GMAC_DMA_DEBUG_STATUS0_TPS1(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_DEBUG_STATUS0_TPS1_SHIFT)) & GMAC_DMA_DEBUG_STATUS0_TPS1_MASK)

#define GMAC_DMA_DEBUG_STATUS0_RPS2_MASK         (0xF000000U)
#define GMAC_DMA_DEBUG_STATUS0_RPS2_SHIFT        (24U)
#define GMAC_DMA_DEBUG_STATUS0_RPS2_WIDTH        (4U)
#define GMAC_DMA_DEBUG_STATUS0_RPS2(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_DEBUG_STATUS0_RPS2_SHIFT)) & GMAC_DMA_DEBUG_STATUS0_RPS2_MASK)

#define GMAC_DMA_DEBUG_STATUS0_TPS2_MASK         (0xF0000000U)
#define GMAC_DMA_DEBUG_STATUS0_TPS2_SHIFT        (28U)
#define GMAC_DMA_DEBUG_STATUS0_TPS2_WIDTH        (4U)
#define GMAC_DMA_DEBUG_STATUS0_TPS2(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_DEBUG_STATUS0_TPS2_SHIFT)) & GMAC_DMA_DEBUG_STATUS0_TPS2_MASK)
/*! @} */

/*! @name DMA_TBS_CTRL0 -  */
/*! @{ */

#define GMAC_DMA_TBS_CTRL0_FTOV_MASK             (0x1U)
#define GMAC_DMA_TBS_CTRL0_FTOV_SHIFT            (0U)
#define GMAC_DMA_TBS_CTRL0_FTOV_WIDTH            (1U)
#define GMAC_DMA_TBS_CTRL0_FTOV(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL0_FTOV_SHIFT)) & GMAC_DMA_TBS_CTRL0_FTOV_MASK)

#define GMAC_DMA_TBS_CTRL0_Reserved_3_1_MASK     (0xEU)
#define GMAC_DMA_TBS_CTRL0_Reserved_3_1_SHIFT    (1U)
#define GMAC_DMA_TBS_CTRL0_Reserved_3_1_WIDTH    (3U)
#define GMAC_DMA_TBS_CTRL0_Reserved_3_1(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL0_Reserved_3_1_SHIFT)) & GMAC_DMA_TBS_CTRL0_Reserved_3_1_MASK)

#define GMAC_DMA_TBS_CTRL0_FGOS_MASK             (0x70U)
#define GMAC_DMA_TBS_CTRL0_FGOS_SHIFT            (4U)
#define GMAC_DMA_TBS_CTRL0_FGOS_WIDTH            (3U)
#define GMAC_DMA_TBS_CTRL0_FGOS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL0_FGOS_SHIFT)) & GMAC_DMA_TBS_CTRL0_FGOS_MASK)

#define GMAC_DMA_TBS_CTRL0_Reserved_7_MASK       (0x80U)
#define GMAC_DMA_TBS_CTRL0_Reserved_7_SHIFT      (7U)
#define GMAC_DMA_TBS_CTRL0_Reserved_7_WIDTH      (1U)
#define GMAC_DMA_TBS_CTRL0_Reserved_7(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL0_Reserved_7_SHIFT)) & GMAC_DMA_TBS_CTRL0_Reserved_7_MASK)

#define GMAC_DMA_TBS_CTRL0_FTOS_MASK             (0xFFFFFF00U)
#define GMAC_DMA_TBS_CTRL0_FTOS_SHIFT            (8U)
#define GMAC_DMA_TBS_CTRL0_FTOS_WIDTH            (24U)
#define GMAC_DMA_TBS_CTRL0_FTOS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL0_FTOS_SHIFT)) & GMAC_DMA_TBS_CTRL0_FTOS_MASK)
/*! @} */

/*! @name DMA_TBS_CTRL1 -  */
/*! @{ */

#define GMAC_DMA_TBS_CTRL1_FTOV_MASK             (0x1U)
#define GMAC_DMA_TBS_CTRL1_FTOV_SHIFT            (0U)
#define GMAC_DMA_TBS_CTRL1_FTOV_WIDTH            (1U)
#define GMAC_DMA_TBS_CTRL1_FTOV(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL1_FTOV_SHIFT)) & GMAC_DMA_TBS_CTRL1_FTOV_MASK)

#define GMAC_DMA_TBS_CTRL1_Reserved_3_1_MASK     (0xEU)
#define GMAC_DMA_TBS_CTRL1_Reserved_3_1_SHIFT    (1U)
#define GMAC_DMA_TBS_CTRL1_Reserved_3_1_WIDTH    (3U)
#define GMAC_DMA_TBS_CTRL1_Reserved_3_1(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL1_Reserved_3_1_SHIFT)) & GMAC_DMA_TBS_CTRL1_Reserved_3_1_MASK)

#define GMAC_DMA_TBS_CTRL1_FGOS_MASK             (0x70U)
#define GMAC_DMA_TBS_CTRL1_FGOS_SHIFT            (4U)
#define GMAC_DMA_TBS_CTRL1_FGOS_WIDTH            (3U)
#define GMAC_DMA_TBS_CTRL1_FGOS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL1_FGOS_SHIFT)) & GMAC_DMA_TBS_CTRL1_FGOS_MASK)

#define GMAC_DMA_TBS_CTRL1_Reserved_7_MASK       (0x80U)
#define GMAC_DMA_TBS_CTRL1_Reserved_7_SHIFT      (7U)
#define GMAC_DMA_TBS_CTRL1_Reserved_7_WIDTH      (1U)
#define GMAC_DMA_TBS_CTRL1_Reserved_7(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL1_Reserved_7_SHIFT)) & GMAC_DMA_TBS_CTRL1_Reserved_7_MASK)

#define GMAC_DMA_TBS_CTRL1_FTOS_MASK             (0xFFFFFF00U)
#define GMAC_DMA_TBS_CTRL1_FTOS_SHIFT            (8U)
#define GMAC_DMA_TBS_CTRL1_FTOS_WIDTH            (24U)
#define GMAC_DMA_TBS_CTRL1_FTOS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL1_FTOS_SHIFT)) & GMAC_DMA_TBS_CTRL1_FTOS_MASK)
/*! @} */

/*! @name DMA_TBS_CTRL2 -  */
/*! @{ */

#define GMAC_DMA_TBS_CTRL2_FTOV_MASK             (0x1U)
#define GMAC_DMA_TBS_CTRL2_FTOV_SHIFT            (0U)
#define GMAC_DMA_TBS_CTRL2_FTOV_WIDTH            (1U)
#define GMAC_DMA_TBS_CTRL2_FTOV(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL2_FTOV_SHIFT)) & GMAC_DMA_TBS_CTRL2_FTOV_MASK)

#define GMAC_DMA_TBS_CTRL2_Reserved_3_1_MASK     (0xEU)
#define GMAC_DMA_TBS_CTRL2_Reserved_3_1_SHIFT    (1U)
#define GMAC_DMA_TBS_CTRL2_Reserved_3_1_WIDTH    (3U)
#define GMAC_DMA_TBS_CTRL2_Reserved_3_1(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL2_Reserved_3_1_SHIFT)) & GMAC_DMA_TBS_CTRL2_Reserved_3_1_MASK)

#define GMAC_DMA_TBS_CTRL2_FGOS_MASK             (0x70U)
#define GMAC_DMA_TBS_CTRL2_FGOS_SHIFT            (4U)
#define GMAC_DMA_TBS_CTRL2_FGOS_WIDTH            (3U)
#define GMAC_DMA_TBS_CTRL2_FGOS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL2_FGOS_SHIFT)) & GMAC_DMA_TBS_CTRL2_FGOS_MASK)

#define GMAC_DMA_TBS_CTRL2_Reserved_7_MASK       (0x80U)
#define GMAC_DMA_TBS_CTRL2_Reserved_7_SHIFT      (7U)
#define GMAC_DMA_TBS_CTRL2_Reserved_7_WIDTH      (1U)
#define GMAC_DMA_TBS_CTRL2_Reserved_7(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL2_Reserved_7_SHIFT)) & GMAC_DMA_TBS_CTRL2_Reserved_7_MASK)

#define GMAC_DMA_TBS_CTRL2_FTOS_MASK             (0xFFFFFF00U)
#define GMAC_DMA_TBS_CTRL2_FTOS_SHIFT            (8U)
#define GMAC_DMA_TBS_CTRL2_FTOS_WIDTH            (24U)
#define GMAC_DMA_TBS_CTRL2_FTOS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL2_FTOS_SHIFT)) & GMAC_DMA_TBS_CTRL2_FTOS_MASK)
/*! @} */

/*! @name DMA_TBS_CTRL3 -  */
/*! @{ */

#define GMAC_DMA_TBS_CTRL3_FTOV_MASK             (0x1U)
#define GMAC_DMA_TBS_CTRL3_FTOV_SHIFT            (0U)
#define GMAC_DMA_TBS_CTRL3_FTOV_WIDTH            (1U)
#define GMAC_DMA_TBS_CTRL3_FTOV(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL3_FTOV_SHIFT)) & GMAC_DMA_TBS_CTRL3_FTOV_MASK)

#define GMAC_DMA_TBS_CTRL3_Reserved_3_1_MASK     (0xEU)
#define GMAC_DMA_TBS_CTRL3_Reserved_3_1_SHIFT    (1U)
#define GMAC_DMA_TBS_CTRL3_Reserved_3_1_WIDTH    (3U)
#define GMAC_DMA_TBS_CTRL3_Reserved_3_1(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL3_Reserved_3_1_SHIFT)) & GMAC_DMA_TBS_CTRL3_Reserved_3_1_MASK)

#define GMAC_DMA_TBS_CTRL3_FGOS_MASK             (0x70U)
#define GMAC_DMA_TBS_CTRL3_FGOS_SHIFT            (4U)
#define GMAC_DMA_TBS_CTRL3_FGOS_WIDTH            (3U)
#define GMAC_DMA_TBS_CTRL3_FGOS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL3_FGOS_SHIFT)) & GMAC_DMA_TBS_CTRL3_FGOS_MASK)

#define GMAC_DMA_TBS_CTRL3_Reserved_7_MASK       (0x80U)
#define GMAC_DMA_TBS_CTRL3_Reserved_7_SHIFT      (7U)
#define GMAC_DMA_TBS_CTRL3_Reserved_7_WIDTH      (1U)
#define GMAC_DMA_TBS_CTRL3_Reserved_7(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL3_Reserved_7_SHIFT)) & GMAC_DMA_TBS_CTRL3_Reserved_7_MASK)

#define GMAC_DMA_TBS_CTRL3_FTOS_MASK             (0xFFFFFF00U)
#define GMAC_DMA_TBS_CTRL3_FTOS_SHIFT            (8U)
#define GMAC_DMA_TBS_CTRL3_FTOS_WIDTH            (24U)
#define GMAC_DMA_TBS_CTRL3_FTOS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_TBS_CTRL3_FTOS_SHIFT)) & GMAC_DMA_TBS_CTRL3_FTOS_MASK)
/*! @} */

/*! @name DMA_SAFETY_INTERRUPT_STATUS -  */
/*! @{ */

#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_DECIS_MASK (0x1U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_DECIS_SHIFT (0U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_DECIS_WIDTH (1U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_DECIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SAFETY_INTERRUPT_STATUS_DECIS_SHIFT)) & GMAC_DMA_SAFETY_INTERRUPT_STATUS_DECIS_MASK)

#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_DEUIS_MASK (0x2U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_DEUIS_SHIFT (1U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_DEUIS_WIDTH (1U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_DEUIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SAFETY_INTERRUPT_STATUS_DEUIS_SHIFT)) & GMAC_DMA_SAFETY_INTERRUPT_STATUS_DEUIS_MASK)

#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_Reserved_27_2_MASK (0xFFFFFFCU)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_Reserved_27_2_SHIFT (2U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_Reserved_27_2_WIDTH (26U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_Reserved_27_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SAFETY_INTERRUPT_STATUS_Reserved_27_2_SHIFT)) & GMAC_DMA_SAFETY_INTERRUPT_STATUS_Reserved_27_2_MASK)

#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_MSCIS_MASK (0x10000000U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_MSCIS_SHIFT (28U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_MSCIS_WIDTH (1U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_MSCIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SAFETY_INTERRUPT_STATUS_MSCIS_SHIFT)) & GMAC_DMA_SAFETY_INTERRUPT_STATUS_MSCIS_MASK)

#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_MASK (0x20000000U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_SHIFT (29U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_WIDTH (1U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_MSUIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_SHIFT)) & GMAC_DMA_SAFETY_INTERRUPT_STATUS_MSUIS_MASK)

#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_Reserved_30_MASK (0x40000000U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_Reserved_30_SHIFT (30U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_Reserved_30_WIDTH (1U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_Reserved_30(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SAFETY_INTERRUPT_STATUS_Reserved_30_SHIFT)) & GMAC_DMA_SAFETY_INTERRUPT_STATUS_Reserved_30_MASK)

#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_MASK (0x80000000U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_SHIFT (31U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_WIDTH (1U)
#define GMAC_DMA_SAFETY_INTERRUPT_STATUS_MCSIS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_SHIFT)) & GMAC_DMA_SAFETY_INTERRUPT_STATUS_MCSIS_MASK)
/*! @} */

/*! @name DMA_CH0_CONTROL -  */
/*! @{ */

#define GMAC_DMA_CH0_CONTROL_Reserved_MSS_MASK   (0x3FFFU)
#define GMAC_DMA_CH0_CONTROL_Reserved_MSS_SHIFT  (0U)
#define GMAC_DMA_CH0_CONTROL_Reserved_MSS_WIDTH  (14U)
#define GMAC_DMA_CH0_CONTROL_Reserved_MSS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_CONTROL_Reserved_MSS_SHIFT)) & GMAC_DMA_CH0_CONTROL_Reserved_MSS_MASK)

#define GMAC_DMA_CH0_CONTROL_Reserved_15_14_MASK (0xC000U)
#define GMAC_DMA_CH0_CONTROL_Reserved_15_14_SHIFT (14U)
#define GMAC_DMA_CH0_CONTROL_Reserved_15_14_WIDTH (2U)
#define GMAC_DMA_CH0_CONTROL_Reserved_15_14(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_CONTROL_Reserved_15_14_SHIFT)) & GMAC_DMA_CH0_CONTROL_Reserved_15_14_MASK)

#define GMAC_DMA_CH0_CONTROL_PBLx8_MASK          (0x10000U)
#define GMAC_DMA_CH0_CONTROL_PBLx8_SHIFT         (16U)
#define GMAC_DMA_CH0_CONTROL_PBLx8_WIDTH         (1U)
#define GMAC_DMA_CH0_CONTROL_PBLx8(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_CONTROL_PBLx8_SHIFT)) & GMAC_DMA_CH0_CONTROL_PBLx8_MASK)

#define GMAC_DMA_CH0_CONTROL_Reserved_17_MASK    (0x20000U)
#define GMAC_DMA_CH0_CONTROL_Reserved_17_SHIFT   (17U)
#define GMAC_DMA_CH0_CONTROL_Reserved_17_WIDTH   (1U)
#define GMAC_DMA_CH0_CONTROL_Reserved_17(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_CONTROL_Reserved_17_SHIFT)) & GMAC_DMA_CH0_CONTROL_Reserved_17_MASK)

#define GMAC_DMA_CH0_CONTROL_DSL_MASK            (0x1C0000U)
#define GMAC_DMA_CH0_CONTROL_DSL_SHIFT           (18U)
#define GMAC_DMA_CH0_CONTROL_DSL_WIDTH           (3U)
#define GMAC_DMA_CH0_CONTROL_DSL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_CONTROL_DSL_SHIFT)) & GMAC_DMA_CH0_CONTROL_DSL_MASK)

#define GMAC_DMA_CH0_CONTROL_Reserved_23_21_MASK (0xE00000U)
#define GMAC_DMA_CH0_CONTROL_Reserved_23_21_SHIFT (21U)
#define GMAC_DMA_CH0_CONTROL_Reserved_23_21_WIDTH (3U)
#define GMAC_DMA_CH0_CONTROL_Reserved_23_21(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_CONTROL_Reserved_23_21_SHIFT)) & GMAC_DMA_CH0_CONTROL_Reserved_23_21_MASK)

#define GMAC_DMA_CH0_CONTROL_SPH_MASK            (0x1000000U)
#define GMAC_DMA_CH0_CONTROL_SPH_SHIFT           (24U)
#define GMAC_DMA_CH0_CONTROL_SPH_WIDTH           (1U)
#define GMAC_DMA_CH0_CONTROL_SPH(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_CONTROL_SPH_SHIFT)) & GMAC_DMA_CH0_CONTROL_SPH_MASK)

#define GMAC_DMA_CH0_CONTROL_Reserved_31_25_MASK (0xFE000000U)
#define GMAC_DMA_CH0_CONTROL_Reserved_31_25_SHIFT (25U)
#define GMAC_DMA_CH0_CONTROL_Reserved_31_25_WIDTH (7U)
#define GMAC_DMA_CH0_CONTROL_Reserved_31_25(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_CONTROL_Reserved_31_25_SHIFT)) & GMAC_DMA_CH0_CONTROL_Reserved_31_25_MASK)
/*! @} */

/*! @name DMA_CH0_TX_CONTROL -  */
/*! @{ */

#define GMAC_DMA_CH0_TX_CONTROL_ST_MASK          (0x1U)
#define GMAC_DMA_CH0_TX_CONTROL_ST_SHIFT         (0U)
#define GMAC_DMA_CH0_TX_CONTROL_ST_WIDTH         (1U)
#define GMAC_DMA_CH0_TX_CONTROL_ST(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TX_CONTROL_ST_SHIFT)) & GMAC_DMA_CH0_TX_CONTROL_ST_MASK)

#define GMAC_DMA_CH0_TX_CONTROL_TCW_MASK         (0xEU)
#define GMAC_DMA_CH0_TX_CONTROL_TCW_SHIFT        (1U)
#define GMAC_DMA_CH0_TX_CONTROL_TCW_WIDTH        (3U)
#define GMAC_DMA_CH0_TX_CONTROL_TCW(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TX_CONTROL_TCW_SHIFT)) & GMAC_DMA_CH0_TX_CONTROL_TCW_MASK)

#define GMAC_DMA_CH0_TX_CONTROL_OSF_MASK         (0x10U)
#define GMAC_DMA_CH0_TX_CONTROL_OSF_SHIFT        (4U)
#define GMAC_DMA_CH0_TX_CONTROL_OSF_WIDTH        (1U)
#define GMAC_DMA_CH0_TX_CONTROL_OSF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TX_CONTROL_OSF_SHIFT)) & GMAC_DMA_CH0_TX_CONTROL_OSF_MASK)

#define GMAC_DMA_CH0_TX_CONTROL_Reserved_11_5_MASK (0xFE0U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_11_5_SHIFT (5U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_11_5_WIDTH (7U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_11_5(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TX_CONTROL_Reserved_11_5_SHIFT)) & GMAC_DMA_CH0_TX_CONTROL_Reserved_11_5_MASK)

#define GMAC_DMA_CH0_TX_CONTROL_Reserved_TSE_MASK (0x1000U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_TSE_SHIFT (12U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_TSE_WIDTH (1U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_TSE(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TX_CONTROL_Reserved_TSE_SHIFT)) & GMAC_DMA_CH0_TX_CONTROL_Reserved_TSE_MASK)

#define GMAC_DMA_CH0_TX_CONTROL_Reserved_TSE_MODE_MASK (0x6000U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_TSE_MODE_SHIFT (13U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_TSE_MODE_WIDTH (2U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_TSE_MODE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TX_CONTROL_Reserved_TSE_MODE_SHIFT)) & GMAC_DMA_CH0_TX_CONTROL_Reserved_TSE_MODE_MASK)

#define GMAC_DMA_CH0_TX_CONTROL_Reserved_IPBL_MASK (0x8000U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_IPBL_SHIFT (15U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_IPBL_WIDTH (1U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_IPBL(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TX_CONTROL_Reserved_IPBL_SHIFT)) & GMAC_DMA_CH0_TX_CONTROL_Reserved_IPBL_MASK)

#define GMAC_DMA_CH0_TX_CONTROL_TxPBL_MASK       (0x3F0000U)
#define GMAC_DMA_CH0_TX_CONTROL_TxPBL_SHIFT      (16U)
#define GMAC_DMA_CH0_TX_CONTROL_TxPBL_WIDTH      (6U)
#define GMAC_DMA_CH0_TX_CONTROL_TxPBL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TX_CONTROL_TxPBL_SHIFT)) & GMAC_DMA_CH0_TX_CONTROL_TxPBL_MASK)

#define GMAC_DMA_CH0_TX_CONTROL_ETIC_MASK        (0x400000U)
#define GMAC_DMA_CH0_TX_CONTROL_ETIC_SHIFT       (22U)
#define GMAC_DMA_CH0_TX_CONTROL_ETIC_WIDTH       (1U)
#define GMAC_DMA_CH0_TX_CONTROL_ETIC(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TX_CONTROL_ETIC_SHIFT)) & GMAC_DMA_CH0_TX_CONTROL_ETIC_MASK)

#define GMAC_DMA_CH0_TX_CONTROL_Reserved_23_MASK (0x800000U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_23_SHIFT (23U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_23_WIDTH (1U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_23(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TX_CONTROL_Reserved_23_SHIFT)) & GMAC_DMA_CH0_TX_CONTROL_Reserved_23_MASK)

#define GMAC_DMA_CH0_TX_CONTROL_Reserved_TQOS_MASK (0xF000000U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_TQOS_SHIFT (24U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_TQOS_WIDTH (4U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_TQOS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TX_CONTROL_Reserved_TQOS_SHIFT)) & GMAC_DMA_CH0_TX_CONTROL_Reserved_TQOS_MASK)

#define GMAC_DMA_CH0_TX_CONTROL_EDSE_MASK        (0x10000000U)
#define GMAC_DMA_CH0_TX_CONTROL_EDSE_SHIFT       (28U)
#define GMAC_DMA_CH0_TX_CONTROL_EDSE_WIDTH       (1U)
#define GMAC_DMA_CH0_TX_CONTROL_EDSE(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TX_CONTROL_EDSE_SHIFT)) & GMAC_DMA_CH0_TX_CONTROL_EDSE_MASK)

#define GMAC_DMA_CH0_TX_CONTROL_TFSEL_MASK       (0x60000000U)
#define GMAC_DMA_CH0_TX_CONTROL_TFSEL_SHIFT      (29U)
#define GMAC_DMA_CH0_TX_CONTROL_TFSEL_WIDTH      (2U)
#define GMAC_DMA_CH0_TX_CONTROL_TFSEL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TX_CONTROL_TFSEL_SHIFT)) & GMAC_DMA_CH0_TX_CONTROL_TFSEL_MASK)

#define GMAC_DMA_CH0_TX_CONTROL_Reserved_31_MASK (0x80000000U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_31_SHIFT (31U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_31_WIDTH (1U)
#define GMAC_DMA_CH0_TX_CONTROL_Reserved_31(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TX_CONTROL_Reserved_31_SHIFT)) & GMAC_DMA_CH0_TX_CONTROL_Reserved_31_MASK)
/*! @} */

/*! @name DMA_CH0_RX_CONTROL -  */
/*! @{ */

#define GMAC_DMA_CH0_RX_CONTROL_SR_MASK          (0x1U)
#define GMAC_DMA_CH0_RX_CONTROL_SR_SHIFT         (0U)
#define GMAC_DMA_CH0_RX_CONTROL_SR_WIDTH         (1U)
#define GMAC_DMA_CH0_RX_CONTROL_SR(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_CONTROL_SR_SHIFT)) & GMAC_DMA_CH0_RX_CONTROL_SR_MASK)

#define GMAC_DMA_CH0_RX_CONTROL_RBSZ_x_0_MASK    (0xEU)
#define GMAC_DMA_CH0_RX_CONTROL_RBSZ_x_0_SHIFT   (1U)
#define GMAC_DMA_CH0_RX_CONTROL_RBSZ_x_0_WIDTH   (3U)
#define GMAC_DMA_CH0_RX_CONTROL_RBSZ_x_0(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_CONTROL_RBSZ_x_0_SHIFT)) & GMAC_DMA_CH0_RX_CONTROL_RBSZ_x_0_MASK)

#define GMAC_DMA_CH0_RX_CONTROL_RBSZ_13_y_MASK   (0x7FF0U)
#define GMAC_DMA_CH0_RX_CONTROL_RBSZ_13_y_SHIFT  (4U)
#define GMAC_DMA_CH0_RX_CONTROL_RBSZ_13_y_WIDTH  (11U)
#define GMAC_DMA_CH0_RX_CONTROL_RBSZ_13_y(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_CONTROL_RBSZ_13_y_SHIFT)) & GMAC_DMA_CH0_RX_CONTROL_RBSZ_13_y_MASK)

#define GMAC_DMA_CH0_RX_CONTROL_Reserved_15_MASK (0x8000U)
#define GMAC_DMA_CH0_RX_CONTROL_Reserved_15_SHIFT (15U)
#define GMAC_DMA_CH0_RX_CONTROL_Reserved_15_WIDTH (1U)
#define GMAC_DMA_CH0_RX_CONTROL_Reserved_15(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_CONTROL_Reserved_15_SHIFT)) & GMAC_DMA_CH0_RX_CONTROL_Reserved_15_MASK)

#define GMAC_DMA_CH0_RX_CONTROL_RxPBL_MASK       (0x3F0000U)
#define GMAC_DMA_CH0_RX_CONTROL_RxPBL_SHIFT      (16U)
#define GMAC_DMA_CH0_RX_CONTROL_RxPBL_WIDTH      (6U)
#define GMAC_DMA_CH0_RX_CONTROL_RxPBL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_CONTROL_RxPBL_SHIFT)) & GMAC_DMA_CH0_RX_CONTROL_RxPBL_MASK)

#define GMAC_DMA_CH0_RX_CONTROL_ERIC_MASK        (0x400000U)
#define GMAC_DMA_CH0_RX_CONTROL_ERIC_SHIFT       (22U)
#define GMAC_DMA_CH0_RX_CONTROL_ERIC_WIDTH       (1U)
#define GMAC_DMA_CH0_RX_CONTROL_ERIC(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_CONTROL_ERIC_SHIFT)) & GMAC_DMA_CH0_RX_CONTROL_ERIC_MASK)

#define GMAC_DMA_CH0_RX_CONTROL_Reserved_23_MASK (0x800000U)
#define GMAC_DMA_CH0_RX_CONTROL_Reserved_23_SHIFT (23U)
#define GMAC_DMA_CH0_RX_CONTROL_Reserved_23_WIDTH (1U)
#define GMAC_DMA_CH0_RX_CONTROL_Reserved_23(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_CONTROL_Reserved_23_SHIFT)) & GMAC_DMA_CH0_RX_CONTROL_Reserved_23_MASK)

#define GMAC_DMA_CH0_RX_CONTROL_Reserved_RQOS_MASK (0xF000000U)
#define GMAC_DMA_CH0_RX_CONTROL_Reserved_RQOS_SHIFT (24U)
#define GMAC_DMA_CH0_RX_CONTROL_Reserved_RQOS_WIDTH (4U)
#define GMAC_DMA_CH0_RX_CONTROL_Reserved_RQOS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_CONTROL_Reserved_RQOS_SHIFT)) & GMAC_DMA_CH0_RX_CONTROL_Reserved_RQOS_MASK)

#define GMAC_DMA_CH0_RX_CONTROL_Reserved_30_28_MASK (0x70000000U)
#define GMAC_DMA_CH0_RX_CONTROL_Reserved_30_28_SHIFT (28U)
#define GMAC_DMA_CH0_RX_CONTROL_Reserved_30_28_WIDTH (3U)
#define GMAC_DMA_CH0_RX_CONTROL_Reserved_30_28(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_CONTROL_Reserved_30_28_SHIFT)) & GMAC_DMA_CH0_RX_CONTROL_Reserved_30_28_MASK)

#define GMAC_DMA_CH0_RX_CONTROL_RPF_MASK         (0x80000000U)
#define GMAC_DMA_CH0_RX_CONTROL_RPF_SHIFT        (31U)
#define GMAC_DMA_CH0_RX_CONTROL_RPF_WIDTH        (1U)
#define GMAC_DMA_CH0_RX_CONTROL_RPF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_CONTROL_RPF_SHIFT)) & GMAC_DMA_CH0_RX_CONTROL_RPF_MASK)
/*! @} */

/*! @name DMA_CH0_TXDESC_LIST_ADDRESS -  */
/*! @{ */

#define GMAC_DMA_CH0_TXDESC_LIST_ADDRESS_Reserved_LSb_MASK (0x7U)
#define GMAC_DMA_CH0_TXDESC_LIST_ADDRESS_Reserved_LSb_SHIFT (0U)
#define GMAC_DMA_CH0_TXDESC_LIST_ADDRESS_Reserved_LSb_WIDTH (3U)
#define GMAC_DMA_CH0_TXDESC_LIST_ADDRESS_Reserved_LSb(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TXDESC_LIST_ADDRESS_Reserved_LSb_SHIFT)) & GMAC_DMA_CH0_TXDESC_LIST_ADDRESS_Reserved_LSb_MASK)

#define GMAC_DMA_CH0_TXDESC_LIST_ADDRESS_TDESLA_MASK (0xFFFFFFF8U)
#define GMAC_DMA_CH0_TXDESC_LIST_ADDRESS_TDESLA_SHIFT (3U)
#define GMAC_DMA_CH0_TXDESC_LIST_ADDRESS_TDESLA_WIDTH (29U)
#define GMAC_DMA_CH0_TXDESC_LIST_ADDRESS_TDESLA(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TXDESC_LIST_ADDRESS_TDESLA_SHIFT)) & GMAC_DMA_CH0_TXDESC_LIST_ADDRESS_TDESLA_MASK)
/*! @} */

/*! @name DMA_CH0_RXDESC_LIST_ADDRESS -  */
/*! @{ */

#define GMAC_DMA_CH0_RXDESC_LIST_ADDRESS_Reserved_LSb_MASK (0x7U)
#define GMAC_DMA_CH0_RXDESC_LIST_ADDRESS_Reserved_LSb_SHIFT (0U)
#define GMAC_DMA_CH0_RXDESC_LIST_ADDRESS_Reserved_LSb_WIDTH (3U)
#define GMAC_DMA_CH0_RXDESC_LIST_ADDRESS_Reserved_LSb(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RXDESC_LIST_ADDRESS_Reserved_LSb_SHIFT)) & GMAC_DMA_CH0_RXDESC_LIST_ADDRESS_Reserved_LSb_MASK)

#define GMAC_DMA_CH0_RXDESC_LIST_ADDRESS_RDESLA_MASK (0xFFFFFFF8U)
#define GMAC_DMA_CH0_RXDESC_LIST_ADDRESS_RDESLA_SHIFT (3U)
#define GMAC_DMA_CH0_RXDESC_LIST_ADDRESS_RDESLA_WIDTH (29U)
#define GMAC_DMA_CH0_RXDESC_LIST_ADDRESS_RDESLA(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RXDESC_LIST_ADDRESS_RDESLA_SHIFT)) & GMAC_DMA_CH0_RXDESC_LIST_ADDRESS_RDESLA_MASK)
/*! @} */

/*! @name DMA_CH0_TXDESC_TAIL_POINTER -  */
/*! @{ */

#define GMAC_DMA_CH0_TXDESC_TAIL_POINTER_Reserved_LSb_MASK (0x7U)
#define GMAC_DMA_CH0_TXDESC_TAIL_POINTER_Reserved_LSb_SHIFT (0U)
#define GMAC_DMA_CH0_TXDESC_TAIL_POINTER_Reserved_LSb_WIDTH (3U)
#define GMAC_DMA_CH0_TXDESC_TAIL_POINTER_Reserved_LSb(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TXDESC_TAIL_POINTER_Reserved_LSb_SHIFT)) & GMAC_DMA_CH0_TXDESC_TAIL_POINTER_Reserved_LSb_MASK)

#define GMAC_DMA_CH0_TXDESC_TAIL_POINTER_TDTP_MASK (0xFFFFFFF8U)
#define GMAC_DMA_CH0_TXDESC_TAIL_POINTER_TDTP_SHIFT (3U)
#define GMAC_DMA_CH0_TXDESC_TAIL_POINTER_TDTP_WIDTH (29U)
#define GMAC_DMA_CH0_TXDESC_TAIL_POINTER_TDTP(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TXDESC_TAIL_POINTER_TDTP_SHIFT)) & GMAC_DMA_CH0_TXDESC_TAIL_POINTER_TDTP_MASK)
/*! @} */

/*! @name DMA_CH0_RXDESC_TAIL_POINTER -  */
/*! @{ */

#define GMAC_DMA_CH0_RXDESC_TAIL_POINTER_Reserved_LSb_MASK (0x7U)
#define GMAC_DMA_CH0_RXDESC_TAIL_POINTER_Reserved_LSb_SHIFT (0U)
#define GMAC_DMA_CH0_RXDESC_TAIL_POINTER_Reserved_LSb_WIDTH (3U)
#define GMAC_DMA_CH0_RXDESC_TAIL_POINTER_Reserved_LSb(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RXDESC_TAIL_POINTER_Reserved_LSb_SHIFT)) & GMAC_DMA_CH0_RXDESC_TAIL_POINTER_Reserved_LSb_MASK)

#define GMAC_DMA_CH0_RXDESC_TAIL_POINTER_RDTP_MASK (0xFFFFFFF8U)
#define GMAC_DMA_CH0_RXDESC_TAIL_POINTER_RDTP_SHIFT (3U)
#define GMAC_DMA_CH0_RXDESC_TAIL_POINTER_RDTP_WIDTH (29U)
#define GMAC_DMA_CH0_RXDESC_TAIL_POINTER_RDTP(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RXDESC_TAIL_POINTER_RDTP_SHIFT)) & GMAC_DMA_CH0_RXDESC_TAIL_POINTER_RDTP_MASK)
/*! @} */

/*! @name DMA_CH0_TXDESC_RING_LENGTH -  */
/*! @{ */

#define GMAC_DMA_CH0_TXDESC_RING_LENGTH_TDRL_MASK (0x3FFU)
#define GMAC_DMA_CH0_TXDESC_RING_LENGTH_TDRL_SHIFT (0U)
#define GMAC_DMA_CH0_TXDESC_RING_LENGTH_TDRL_WIDTH (10U)
#define GMAC_DMA_CH0_TXDESC_RING_LENGTH_TDRL(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TXDESC_RING_LENGTH_TDRL_SHIFT)) & GMAC_DMA_CH0_TXDESC_RING_LENGTH_TDRL_MASK)

#define GMAC_DMA_CH0_TXDESC_RING_LENGTH_Reserved_31_10_MASK (0xFFFFFC00U)
#define GMAC_DMA_CH0_TXDESC_RING_LENGTH_Reserved_31_10_SHIFT (10U)
#define GMAC_DMA_CH0_TXDESC_RING_LENGTH_Reserved_31_10_WIDTH (22U)
#define GMAC_DMA_CH0_TXDESC_RING_LENGTH_Reserved_31_10(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_TXDESC_RING_LENGTH_Reserved_31_10_SHIFT)) & GMAC_DMA_CH0_TXDESC_RING_LENGTH_Reserved_31_10_MASK)
/*! @} */

/*! @name DMA_CH0_RX_CONTROL2 -  */
/*! @{ */

#define GMAC_DMA_CH0_RX_CONTROL2_RDRL_MASK       (0x3FFU)
#define GMAC_DMA_CH0_RX_CONTROL2_RDRL_SHIFT      (0U)
#define GMAC_DMA_CH0_RX_CONTROL2_RDRL_WIDTH      (10U)
#define GMAC_DMA_CH0_RX_CONTROL2_RDRL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_CONTROL2_RDRL_SHIFT)) & GMAC_DMA_CH0_RX_CONTROL2_RDRL_MASK)

#define GMAC_DMA_CH0_RX_CONTROL2_Reserved_x_10_MASK (0x1FC00U)
#define GMAC_DMA_CH0_RX_CONTROL2_Reserved_x_10_SHIFT (10U)
#define GMAC_DMA_CH0_RX_CONTROL2_Reserved_x_10_WIDTH (7U)
#define GMAC_DMA_CH0_RX_CONTROL2_Reserved_x_10(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_CONTROL2_Reserved_x_10_SHIFT)) & GMAC_DMA_CH0_RX_CONTROL2_Reserved_x_10_MASK)

#define GMAC_DMA_CH0_RX_CONTROL2_ARBS_MASK       (0xFE0000U)
#define GMAC_DMA_CH0_RX_CONTROL2_ARBS_SHIFT      (17U)
#define GMAC_DMA_CH0_RX_CONTROL2_ARBS_WIDTH      (7U)
#define GMAC_DMA_CH0_RX_CONTROL2_ARBS(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_CONTROL2_ARBS_SHIFT)) & GMAC_DMA_CH0_RX_CONTROL2_ARBS_MASK)

#define GMAC_DMA_CH0_RX_CONTROL2_Reserved_31_24_MASK (0xFF000000U)
#define GMAC_DMA_CH0_RX_CONTROL2_Reserved_31_24_SHIFT (24U)
#define GMAC_DMA_CH0_RX_CONTROL2_Reserved_31_24_WIDTH (8U)
#define GMAC_DMA_CH0_RX_CONTROL2_Reserved_31_24(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_CONTROL2_Reserved_31_24_SHIFT)) & GMAC_DMA_CH0_RX_CONTROL2_Reserved_31_24_MASK)
/*! @} */

/*! @name DMA_CH0_INTERRUPT_ENABLE -  */
/*! @{ */

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_TIE_MASK   (0x1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_TIE_SHIFT  (0U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_TIE_WIDTH  (1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_TIE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_TIE_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_TIE_MASK)

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_TXSE_MASK  (0x2U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_TXSE_SHIFT (1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_TXSE_WIDTH (1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_TXSE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_TXSE_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_TXSE_MASK)

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_TBUE_MASK  (0x4U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_TBUE_SHIFT (2U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_TBUE_WIDTH (1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_TBUE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_TBUE_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_TBUE_MASK)

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_Reserved_5_3_MASK (0x38U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_Reserved_5_3_SHIFT (3U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_Reserved_5_3_WIDTH (3U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_Reserved_5_3(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_Reserved_5_3_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_Reserved_5_3_MASK)

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RIE_MASK   (0x40U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RIE_SHIFT  (6U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RIE_WIDTH  (1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RIE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_RIE_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_RIE_MASK)

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RBUE_MASK  (0x80U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RBUE_SHIFT (7U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RBUE_WIDTH (1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RBUE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_RBUE_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_RBUE_MASK)

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RSE_MASK   (0x100U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RSE_SHIFT  (8U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RSE_WIDTH  (1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RSE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_RSE_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_RSE_MASK)

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RWTE_MASK  (0x200U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RWTE_SHIFT (9U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RWTE_WIDTH (1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_RWTE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_RWTE_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_RWTE_MASK)

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_ETIE_MASK  (0x400U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_ETIE_SHIFT (10U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_ETIE_WIDTH (1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_ETIE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_ETIE_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_ETIE_MASK)

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_ERIE_MASK  (0x800U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_ERIE_SHIFT (11U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_ERIE_WIDTH (1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_ERIE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_ERIE_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_ERIE_MASK)

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_FBEE_MASK  (0x1000U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_FBEE_SHIFT (12U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_FBEE_WIDTH (1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_FBEE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_FBEE_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_FBEE_MASK)

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_CDEE_MASK  (0x2000U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_CDEE_SHIFT (13U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_CDEE_WIDTH (1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_CDEE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_CDEE_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_CDEE_MASK)

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_AIE_MASK   (0x4000U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_AIE_SHIFT  (14U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_AIE_WIDTH  (1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_AIE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_AIE_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_AIE_MASK)

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_NIE_MASK   (0x8000U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_NIE_SHIFT  (15U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_NIE_WIDTH  (1U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_NIE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_NIE_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_NIE_MASK)

#define GMAC_DMA_CH0_INTERRUPT_ENABLE_Reserved_31_16_MASK (0xFFFF0000U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_Reserved_31_16_SHIFT (16U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_Reserved_31_16_WIDTH (16U)
#define GMAC_DMA_CH0_INTERRUPT_ENABLE_Reserved_31_16(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_INTERRUPT_ENABLE_Reserved_31_16_SHIFT)) & GMAC_DMA_CH0_INTERRUPT_ENABLE_Reserved_31_16_MASK)
/*! @} */

/*! @name DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER -  */
/*! @{ */

#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK (0xFFU)
#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWT_SHIFT (0U)
#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWT_WIDTH (8U)
#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWT(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWT_SHIFT)) & GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK)

#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_MASK (0xFF00U)
#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_SHIFT (8U)
#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_WIDTH (8U)
#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_SHIFT)) & GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_MASK)

#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK (0x30000U)
#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_SHIFT (16U)
#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_WIDTH (2U)
#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWTU(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_SHIFT)) & GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK)

#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_MASK (0xFFFC0000U)
#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_SHIFT (18U)
#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_WIDTH (14U)
#define GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_SHIFT)) & GMAC_DMA_CH0_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_MASK)
/*! @} */

/*! @name DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS -  */
/*! @{ */

#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK (0x1U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ESC_SHIFT (0U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ESC_WIDTH (1U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ESC(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ESC_SHIFT)) & GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK)

#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK (0x2U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ASC_SHIFT (1U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ASC_WIDTH (1U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ASC(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ASC_SHIFT)) & GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK)

#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_MASK (0xCU)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_SHIFT (2U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_WIDTH (2U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_SHIFT)) & GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_MASK)

#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_SIV_MASK (0xFFF0U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_SIV_SHIFT (4U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_SIV_WIDTH (12U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_SIV(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_SIV_SHIFT)) & GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_SIV_MASK)

#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK (0xF0000U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_RSN_SHIFT (16U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_RSN_WIDTH (4U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_RSN(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_RSN_SHIFT)) & GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK)

#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_MASK (0xFFF00000U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_SHIFT (20U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_WIDTH (12U)
#define GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_SHIFT)) & GMAC_DMA_CH0_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_MASK)
/*! @} */

/*! @name DMA_CH0_CURRENT_APP_TXDESC -  */
/*! @{ */

#define GMAC_DMA_CH0_CURRENT_APP_TXDESC_CURTDESAPTR_MASK (0xFFFFFFFFU)
#define GMAC_DMA_CH0_CURRENT_APP_TXDESC_CURTDESAPTR_SHIFT (0U)
#define GMAC_DMA_CH0_CURRENT_APP_TXDESC_CURTDESAPTR_WIDTH (32U)
#define GMAC_DMA_CH0_CURRENT_APP_TXDESC_CURTDESAPTR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_CURRENT_APP_TXDESC_CURTDESAPTR_SHIFT)) & GMAC_DMA_CH0_CURRENT_APP_TXDESC_CURTDESAPTR_MASK)
/*! @} */

/*! @name DMA_CH0_CURRENT_APP_RXDESC -  */
/*! @{ */

#define GMAC_DMA_CH0_CURRENT_APP_RXDESC_CURRDESAPTR_MASK (0xFFFFFFFFU)
#define GMAC_DMA_CH0_CURRENT_APP_RXDESC_CURRDESAPTR_SHIFT (0U)
#define GMAC_DMA_CH0_CURRENT_APP_RXDESC_CURRDESAPTR_WIDTH (32U)
#define GMAC_DMA_CH0_CURRENT_APP_RXDESC_CURRDESAPTR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_CURRENT_APP_RXDESC_CURRDESAPTR_SHIFT)) & GMAC_DMA_CH0_CURRENT_APP_RXDESC_CURRDESAPTR_MASK)
/*! @} */

/*! @name DMA_CH0_CURRENT_APP_TXBUFFER -  */
/*! @{ */

#define GMAC_DMA_CH0_CURRENT_APP_TXBUFFER_CURTBUFAPTR_MASK (0xFFFFFFFFU)
#define GMAC_DMA_CH0_CURRENT_APP_TXBUFFER_CURTBUFAPTR_SHIFT (0U)
#define GMAC_DMA_CH0_CURRENT_APP_TXBUFFER_CURTBUFAPTR_WIDTH (32U)
#define GMAC_DMA_CH0_CURRENT_APP_TXBUFFER_CURTBUFAPTR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_CURRENT_APP_TXBUFFER_CURTBUFAPTR_SHIFT)) & GMAC_DMA_CH0_CURRENT_APP_TXBUFFER_CURTBUFAPTR_MASK)
/*! @} */

/*! @name DMA_CH0_CURRENT_APP_RXBUFFER -  */
/*! @{ */

#define GMAC_DMA_CH0_CURRENT_APP_RXBUFFER_CURRBUFAPTR_MASK (0xFFFFFFFFU)
#define GMAC_DMA_CH0_CURRENT_APP_RXBUFFER_CURRBUFAPTR_SHIFT (0U)
#define GMAC_DMA_CH0_CURRENT_APP_RXBUFFER_CURRBUFAPTR_WIDTH (32U)
#define GMAC_DMA_CH0_CURRENT_APP_RXBUFFER_CURRBUFAPTR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_CURRENT_APP_RXBUFFER_CURRBUFAPTR_SHIFT)) & GMAC_DMA_CH0_CURRENT_APP_RXBUFFER_CURRBUFAPTR_MASK)
/*! @} */

/*! @name DMA_CH0_STATUS -  */
/*! @{ */

#define GMAC_DMA_CH0_STATUS_TI_MASK              (0x1U)
#define GMAC_DMA_CH0_STATUS_TI_SHIFT             (0U)
#define GMAC_DMA_CH0_STATUS_TI_WIDTH             (1U)
#define GMAC_DMA_CH0_STATUS_TI(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_TI_SHIFT)) & GMAC_DMA_CH0_STATUS_TI_MASK)

#define GMAC_DMA_CH0_STATUS_TPS_MASK             (0x2U)
#define GMAC_DMA_CH0_STATUS_TPS_SHIFT            (1U)
#define GMAC_DMA_CH0_STATUS_TPS_WIDTH            (1U)
#define GMAC_DMA_CH0_STATUS_TPS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_TPS_SHIFT)) & GMAC_DMA_CH0_STATUS_TPS_MASK)

#define GMAC_DMA_CH0_STATUS_TBU_MASK             (0x4U)
#define GMAC_DMA_CH0_STATUS_TBU_SHIFT            (2U)
#define GMAC_DMA_CH0_STATUS_TBU_WIDTH            (1U)
#define GMAC_DMA_CH0_STATUS_TBU(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_TBU_SHIFT)) & GMAC_DMA_CH0_STATUS_TBU_MASK)

#define GMAC_DMA_CH0_STATUS_Reserved_5_3_MASK    (0x38U)
#define GMAC_DMA_CH0_STATUS_Reserved_5_3_SHIFT   (3U)
#define GMAC_DMA_CH0_STATUS_Reserved_5_3_WIDTH   (3U)
#define GMAC_DMA_CH0_STATUS_Reserved_5_3(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_Reserved_5_3_SHIFT)) & GMAC_DMA_CH0_STATUS_Reserved_5_3_MASK)

#define GMAC_DMA_CH0_STATUS_RI_MASK              (0x40U)
#define GMAC_DMA_CH0_STATUS_RI_SHIFT             (6U)
#define GMAC_DMA_CH0_STATUS_RI_WIDTH             (1U)
#define GMAC_DMA_CH0_STATUS_RI(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_RI_SHIFT)) & GMAC_DMA_CH0_STATUS_RI_MASK)

#define GMAC_DMA_CH0_STATUS_RBU_MASK             (0x80U)
#define GMAC_DMA_CH0_STATUS_RBU_SHIFT            (7U)
#define GMAC_DMA_CH0_STATUS_RBU_WIDTH            (1U)
#define GMAC_DMA_CH0_STATUS_RBU(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_RBU_SHIFT)) & GMAC_DMA_CH0_STATUS_RBU_MASK)

#define GMAC_DMA_CH0_STATUS_RPS_MASK             (0x100U)
#define GMAC_DMA_CH0_STATUS_RPS_SHIFT            (8U)
#define GMAC_DMA_CH0_STATUS_RPS_WIDTH            (1U)
#define GMAC_DMA_CH0_STATUS_RPS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_RPS_SHIFT)) & GMAC_DMA_CH0_STATUS_RPS_MASK)

#define GMAC_DMA_CH0_STATUS_RWT_MASK             (0x200U)
#define GMAC_DMA_CH0_STATUS_RWT_SHIFT            (9U)
#define GMAC_DMA_CH0_STATUS_RWT_WIDTH            (1U)
#define GMAC_DMA_CH0_STATUS_RWT(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_RWT_SHIFT)) & GMAC_DMA_CH0_STATUS_RWT_MASK)

#define GMAC_DMA_CH0_STATUS_ETI_MASK             (0x400U)
#define GMAC_DMA_CH0_STATUS_ETI_SHIFT            (10U)
#define GMAC_DMA_CH0_STATUS_ETI_WIDTH            (1U)
#define GMAC_DMA_CH0_STATUS_ETI(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_ETI_SHIFT)) & GMAC_DMA_CH0_STATUS_ETI_MASK)

#define GMAC_DMA_CH0_STATUS_ERI_MASK             (0x800U)
#define GMAC_DMA_CH0_STATUS_ERI_SHIFT            (11U)
#define GMAC_DMA_CH0_STATUS_ERI_WIDTH            (1U)
#define GMAC_DMA_CH0_STATUS_ERI(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_ERI_SHIFT)) & GMAC_DMA_CH0_STATUS_ERI_MASK)

#define GMAC_DMA_CH0_STATUS_FBE_MASK             (0x1000U)
#define GMAC_DMA_CH0_STATUS_FBE_SHIFT            (12U)
#define GMAC_DMA_CH0_STATUS_FBE_WIDTH            (1U)
#define GMAC_DMA_CH0_STATUS_FBE(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_FBE_SHIFT)) & GMAC_DMA_CH0_STATUS_FBE_MASK)

#define GMAC_DMA_CH0_STATUS_CDE_MASK             (0x2000U)
#define GMAC_DMA_CH0_STATUS_CDE_SHIFT            (13U)
#define GMAC_DMA_CH0_STATUS_CDE_WIDTH            (1U)
#define GMAC_DMA_CH0_STATUS_CDE(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_CDE_SHIFT)) & GMAC_DMA_CH0_STATUS_CDE_MASK)

#define GMAC_DMA_CH0_STATUS_AIS_MASK             (0x4000U)
#define GMAC_DMA_CH0_STATUS_AIS_SHIFT            (14U)
#define GMAC_DMA_CH0_STATUS_AIS_WIDTH            (1U)
#define GMAC_DMA_CH0_STATUS_AIS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_AIS_SHIFT)) & GMAC_DMA_CH0_STATUS_AIS_MASK)

#define GMAC_DMA_CH0_STATUS_NIS_MASK             (0x8000U)
#define GMAC_DMA_CH0_STATUS_NIS_SHIFT            (15U)
#define GMAC_DMA_CH0_STATUS_NIS_WIDTH            (1U)
#define GMAC_DMA_CH0_STATUS_NIS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_NIS_SHIFT)) & GMAC_DMA_CH0_STATUS_NIS_MASK)

#define GMAC_DMA_CH0_STATUS_TEB_MASK             (0x70000U)
#define GMAC_DMA_CH0_STATUS_TEB_SHIFT            (16U)
#define GMAC_DMA_CH0_STATUS_TEB_WIDTH            (3U)
#define GMAC_DMA_CH0_STATUS_TEB(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_TEB_SHIFT)) & GMAC_DMA_CH0_STATUS_TEB_MASK)

#define GMAC_DMA_CH0_STATUS_REB_MASK             (0x380000U)
#define GMAC_DMA_CH0_STATUS_REB_SHIFT            (19U)
#define GMAC_DMA_CH0_STATUS_REB_WIDTH            (3U)
#define GMAC_DMA_CH0_STATUS_REB(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_REB_SHIFT)) & GMAC_DMA_CH0_STATUS_REB_MASK)

#define GMAC_DMA_CH0_STATUS_Reserved_31_22_MASK  (0xFFC00000U)
#define GMAC_DMA_CH0_STATUS_Reserved_31_22_SHIFT (22U)
#define GMAC_DMA_CH0_STATUS_Reserved_31_22_WIDTH (10U)
#define GMAC_DMA_CH0_STATUS_Reserved_31_22(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_STATUS_Reserved_31_22_SHIFT)) & GMAC_DMA_CH0_STATUS_Reserved_31_22_MASK)
/*! @} */

/*! @name DMA_CH0_MISS_FRAME_CNT -  */
/*! @{ */

#define GMAC_DMA_CH0_MISS_FRAME_CNT_MFC_MASK     (0x7FFU)
#define GMAC_DMA_CH0_MISS_FRAME_CNT_MFC_SHIFT    (0U)
#define GMAC_DMA_CH0_MISS_FRAME_CNT_MFC_WIDTH    (11U)
#define GMAC_DMA_CH0_MISS_FRAME_CNT_MFC(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_MISS_FRAME_CNT_MFC_SHIFT)) & GMAC_DMA_CH0_MISS_FRAME_CNT_MFC_MASK)

#define GMAC_DMA_CH0_MISS_FRAME_CNT_Reserved_14_11_MASK (0x7800U)
#define GMAC_DMA_CH0_MISS_FRAME_CNT_Reserved_14_11_SHIFT (11U)
#define GMAC_DMA_CH0_MISS_FRAME_CNT_Reserved_14_11_WIDTH (4U)
#define GMAC_DMA_CH0_MISS_FRAME_CNT_Reserved_14_11(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_MISS_FRAME_CNT_Reserved_14_11_SHIFT)) & GMAC_DMA_CH0_MISS_FRAME_CNT_Reserved_14_11_MASK)

#define GMAC_DMA_CH0_MISS_FRAME_CNT_MFCO_MASK    (0x8000U)
#define GMAC_DMA_CH0_MISS_FRAME_CNT_MFCO_SHIFT   (15U)
#define GMAC_DMA_CH0_MISS_FRAME_CNT_MFCO_WIDTH   (1U)
#define GMAC_DMA_CH0_MISS_FRAME_CNT_MFCO(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_MISS_FRAME_CNT_MFCO_SHIFT)) & GMAC_DMA_CH0_MISS_FRAME_CNT_MFCO_MASK)

#define GMAC_DMA_CH0_MISS_FRAME_CNT_Reserved_31_16_MASK (0xFFFF0000U)
#define GMAC_DMA_CH0_MISS_FRAME_CNT_Reserved_31_16_SHIFT (16U)
#define GMAC_DMA_CH0_MISS_FRAME_CNT_Reserved_31_16_WIDTH (16U)
#define GMAC_DMA_CH0_MISS_FRAME_CNT_Reserved_31_16(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_MISS_FRAME_CNT_Reserved_31_16_SHIFT)) & GMAC_DMA_CH0_MISS_FRAME_CNT_Reserved_31_16_MASK)
/*! @} */

/*! @name DMA_CH0_RXP_ACCEPT_CNT -  */
/*! @{ */

#define GMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPAC_MASK   (0x7FFFFFFFU)
#define GMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPAC_SHIFT  (0U)
#define GMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPAC_WIDTH  (31U)
#define GMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPAC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPAC_SHIFT)) & GMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPAC_MASK)

#define GMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPACOF_MASK (0x80000000U)
#define GMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPACOF_SHIFT (31U)
#define GMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPACOF_WIDTH (1U)
#define GMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPACOF(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPACOF_SHIFT)) & GMAC_DMA_CH0_RXP_ACCEPT_CNT_RXPACOF_MASK)
/*! @} */

/*! @name DMA_CH0_RX_ERI_CNT -  */
/*! @{ */

#define GMAC_DMA_CH0_RX_ERI_CNT_ECNT_MASK        (0xFFFU)
#define GMAC_DMA_CH0_RX_ERI_CNT_ECNT_SHIFT       (0U)
#define GMAC_DMA_CH0_RX_ERI_CNT_ECNT_WIDTH       (12U)
#define GMAC_DMA_CH0_RX_ERI_CNT_ECNT(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_ERI_CNT_ECNT_SHIFT)) & GMAC_DMA_CH0_RX_ERI_CNT_ECNT_MASK)

#define GMAC_DMA_CH0_RX_ERI_CNT_Reserved_31_12_MASK (0xFFFFF000U)
#define GMAC_DMA_CH0_RX_ERI_CNT_Reserved_31_12_SHIFT (12U)
#define GMAC_DMA_CH0_RX_ERI_CNT_Reserved_31_12_WIDTH (20U)
#define GMAC_DMA_CH0_RX_ERI_CNT_Reserved_31_12(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH0_RX_ERI_CNT_Reserved_31_12_SHIFT)) & GMAC_DMA_CH0_RX_ERI_CNT_Reserved_31_12_MASK)
/*! @} */

/*! @name DMA_CH1_CONTROL -  */
/*! @{ */

#define GMAC_DMA_CH1_CONTROL_Reserved_MSS_MASK   (0x3FFFU)
#define GMAC_DMA_CH1_CONTROL_Reserved_MSS_SHIFT  (0U)
#define GMAC_DMA_CH1_CONTROL_Reserved_MSS_WIDTH  (14U)
#define GMAC_DMA_CH1_CONTROL_Reserved_MSS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_CONTROL_Reserved_MSS_SHIFT)) & GMAC_DMA_CH1_CONTROL_Reserved_MSS_MASK)

#define GMAC_DMA_CH1_CONTROL_Reserved_15_14_MASK (0xC000U)
#define GMAC_DMA_CH1_CONTROL_Reserved_15_14_SHIFT (14U)
#define GMAC_DMA_CH1_CONTROL_Reserved_15_14_WIDTH (2U)
#define GMAC_DMA_CH1_CONTROL_Reserved_15_14(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_CONTROL_Reserved_15_14_SHIFT)) & GMAC_DMA_CH1_CONTROL_Reserved_15_14_MASK)

#define GMAC_DMA_CH1_CONTROL_PBLx8_MASK          (0x10000U)
#define GMAC_DMA_CH1_CONTROL_PBLx8_SHIFT         (16U)
#define GMAC_DMA_CH1_CONTROL_PBLx8_WIDTH         (1U)
#define GMAC_DMA_CH1_CONTROL_PBLx8(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_CONTROL_PBLx8_SHIFT)) & GMAC_DMA_CH1_CONTROL_PBLx8_MASK)

#define GMAC_DMA_CH1_CONTROL_Reserved_17_MASK    (0x20000U)
#define GMAC_DMA_CH1_CONTROL_Reserved_17_SHIFT   (17U)
#define GMAC_DMA_CH1_CONTROL_Reserved_17_WIDTH   (1U)
#define GMAC_DMA_CH1_CONTROL_Reserved_17(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_CONTROL_Reserved_17_SHIFT)) & GMAC_DMA_CH1_CONTROL_Reserved_17_MASK)

#define GMAC_DMA_CH1_CONTROL_DSL_MASK            (0x1C0000U)
#define GMAC_DMA_CH1_CONTROL_DSL_SHIFT           (18U)
#define GMAC_DMA_CH1_CONTROL_DSL_WIDTH           (3U)
#define GMAC_DMA_CH1_CONTROL_DSL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_CONTROL_DSL_SHIFT)) & GMAC_DMA_CH1_CONTROL_DSL_MASK)

#define GMAC_DMA_CH1_CONTROL_Reserved_23_21_MASK (0xE00000U)
#define GMAC_DMA_CH1_CONTROL_Reserved_23_21_SHIFT (21U)
#define GMAC_DMA_CH1_CONTROL_Reserved_23_21_WIDTH (3U)
#define GMAC_DMA_CH1_CONTROL_Reserved_23_21(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_CONTROL_Reserved_23_21_SHIFT)) & GMAC_DMA_CH1_CONTROL_Reserved_23_21_MASK)

#define GMAC_DMA_CH1_CONTROL_SPH_MASK            (0x1000000U)
#define GMAC_DMA_CH1_CONTROL_SPH_SHIFT           (24U)
#define GMAC_DMA_CH1_CONTROL_SPH_WIDTH           (1U)
#define GMAC_DMA_CH1_CONTROL_SPH(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_CONTROL_SPH_SHIFT)) & GMAC_DMA_CH1_CONTROL_SPH_MASK)

#define GMAC_DMA_CH1_CONTROL_Reserved_31_25_MASK (0xFE000000U)
#define GMAC_DMA_CH1_CONTROL_Reserved_31_25_SHIFT (25U)
#define GMAC_DMA_CH1_CONTROL_Reserved_31_25_WIDTH (7U)
#define GMAC_DMA_CH1_CONTROL_Reserved_31_25(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_CONTROL_Reserved_31_25_SHIFT)) & GMAC_DMA_CH1_CONTROL_Reserved_31_25_MASK)
/*! @} */

/*! @name DMA_CH1_TX_CONTROL -  */
/*! @{ */

#define GMAC_DMA_CH1_TX_CONTROL_ST_MASK          (0x1U)
#define GMAC_DMA_CH1_TX_CONTROL_ST_SHIFT         (0U)
#define GMAC_DMA_CH1_TX_CONTROL_ST_WIDTH         (1U)
#define GMAC_DMA_CH1_TX_CONTROL_ST(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TX_CONTROL_ST_SHIFT)) & GMAC_DMA_CH1_TX_CONTROL_ST_MASK)

#define GMAC_DMA_CH1_TX_CONTROL_TCW_MASK         (0xEU)
#define GMAC_DMA_CH1_TX_CONTROL_TCW_SHIFT        (1U)
#define GMAC_DMA_CH1_TX_CONTROL_TCW_WIDTH        (3U)
#define GMAC_DMA_CH1_TX_CONTROL_TCW(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TX_CONTROL_TCW_SHIFT)) & GMAC_DMA_CH1_TX_CONTROL_TCW_MASK)

#define GMAC_DMA_CH1_TX_CONTROL_OSF_MASK         (0x10U)
#define GMAC_DMA_CH1_TX_CONTROL_OSF_SHIFT        (4U)
#define GMAC_DMA_CH1_TX_CONTROL_OSF_WIDTH        (1U)
#define GMAC_DMA_CH1_TX_CONTROL_OSF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TX_CONTROL_OSF_SHIFT)) & GMAC_DMA_CH1_TX_CONTROL_OSF_MASK)

#define GMAC_DMA_CH1_TX_CONTROL_Reserved_11_5_MASK (0xFE0U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_11_5_SHIFT (5U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_11_5_WIDTH (7U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_11_5(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TX_CONTROL_Reserved_11_5_SHIFT)) & GMAC_DMA_CH1_TX_CONTROL_Reserved_11_5_MASK)

#define GMAC_DMA_CH1_TX_CONTROL_Reserved_TSE_MASK (0x1000U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_TSE_SHIFT (12U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_TSE_WIDTH (1U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_TSE(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TX_CONTROL_Reserved_TSE_SHIFT)) & GMAC_DMA_CH1_TX_CONTROL_Reserved_TSE_MASK)

#define GMAC_DMA_CH1_TX_CONTROL_Reserved_TSE_MODE_MASK (0x6000U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_TSE_MODE_SHIFT (13U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_TSE_MODE_WIDTH (2U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_TSE_MODE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TX_CONTROL_Reserved_TSE_MODE_SHIFT)) & GMAC_DMA_CH1_TX_CONTROL_Reserved_TSE_MODE_MASK)

#define GMAC_DMA_CH1_TX_CONTROL_Reserved_IPBL_MASK (0x8000U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_IPBL_SHIFT (15U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_IPBL_WIDTH (1U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_IPBL(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TX_CONTROL_Reserved_IPBL_SHIFT)) & GMAC_DMA_CH1_TX_CONTROL_Reserved_IPBL_MASK)

#define GMAC_DMA_CH1_TX_CONTROL_TxPBL_MASK       (0x3F0000U)
#define GMAC_DMA_CH1_TX_CONTROL_TxPBL_SHIFT      (16U)
#define GMAC_DMA_CH1_TX_CONTROL_TxPBL_WIDTH      (6U)
#define GMAC_DMA_CH1_TX_CONTROL_TxPBL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TX_CONTROL_TxPBL_SHIFT)) & GMAC_DMA_CH1_TX_CONTROL_TxPBL_MASK)

#define GMAC_DMA_CH1_TX_CONTROL_ETIC_MASK        (0x400000U)
#define GMAC_DMA_CH1_TX_CONTROL_ETIC_SHIFT       (22U)
#define GMAC_DMA_CH1_TX_CONTROL_ETIC_WIDTH       (1U)
#define GMAC_DMA_CH1_TX_CONTROL_ETIC(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TX_CONTROL_ETIC_SHIFT)) & GMAC_DMA_CH1_TX_CONTROL_ETIC_MASK)

#define GMAC_DMA_CH1_TX_CONTROL_Reserved_23_MASK (0x800000U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_23_SHIFT (23U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_23_WIDTH (1U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_23(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TX_CONTROL_Reserved_23_SHIFT)) & GMAC_DMA_CH1_TX_CONTROL_Reserved_23_MASK)

#define GMAC_DMA_CH1_TX_CONTROL_Reserved_TQOS_MASK (0xF000000U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_TQOS_SHIFT (24U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_TQOS_WIDTH (4U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_TQOS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TX_CONTROL_Reserved_TQOS_SHIFT)) & GMAC_DMA_CH1_TX_CONTROL_Reserved_TQOS_MASK)

#define GMAC_DMA_CH1_TX_CONTROL_EDSE_MASK        (0x10000000U)
#define GMAC_DMA_CH1_TX_CONTROL_EDSE_SHIFT       (28U)
#define GMAC_DMA_CH1_TX_CONTROL_EDSE_WIDTH       (1U)
#define GMAC_DMA_CH1_TX_CONTROL_EDSE(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TX_CONTROL_EDSE_SHIFT)) & GMAC_DMA_CH1_TX_CONTROL_EDSE_MASK)

#define GMAC_DMA_CH1_TX_CONTROL_TFSEL_MASK       (0x60000000U)
#define GMAC_DMA_CH1_TX_CONTROL_TFSEL_SHIFT      (29U)
#define GMAC_DMA_CH1_TX_CONTROL_TFSEL_WIDTH      (2U)
#define GMAC_DMA_CH1_TX_CONTROL_TFSEL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TX_CONTROL_TFSEL_SHIFT)) & GMAC_DMA_CH1_TX_CONTROL_TFSEL_MASK)

#define GMAC_DMA_CH1_TX_CONTROL_Reserved_31_MASK (0x80000000U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_31_SHIFT (31U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_31_WIDTH (1U)
#define GMAC_DMA_CH1_TX_CONTROL_Reserved_31(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TX_CONTROL_Reserved_31_SHIFT)) & GMAC_DMA_CH1_TX_CONTROL_Reserved_31_MASK)
/*! @} */

/*! @name DMA_CH1_RX_CONTROL -  */
/*! @{ */

#define GMAC_DMA_CH1_RX_CONTROL_SR_MASK          (0x1U)
#define GMAC_DMA_CH1_RX_CONTROL_SR_SHIFT         (0U)
#define GMAC_DMA_CH1_RX_CONTROL_SR_WIDTH         (1U)
#define GMAC_DMA_CH1_RX_CONTROL_SR(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_CONTROL_SR_SHIFT)) & GMAC_DMA_CH1_RX_CONTROL_SR_MASK)

#define GMAC_DMA_CH1_RX_CONTROL_RBSZ_x_0_MASK    (0xEU)
#define GMAC_DMA_CH1_RX_CONTROL_RBSZ_x_0_SHIFT   (1U)
#define GMAC_DMA_CH1_RX_CONTROL_RBSZ_x_0_WIDTH   (3U)
#define GMAC_DMA_CH1_RX_CONTROL_RBSZ_x_0(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_CONTROL_RBSZ_x_0_SHIFT)) & GMAC_DMA_CH1_RX_CONTROL_RBSZ_x_0_MASK)

#define GMAC_DMA_CH1_RX_CONTROL_RBSZ_13_y_MASK   (0x7FF0U)
#define GMAC_DMA_CH1_RX_CONTROL_RBSZ_13_y_SHIFT  (4U)
#define GMAC_DMA_CH1_RX_CONTROL_RBSZ_13_y_WIDTH  (11U)
#define GMAC_DMA_CH1_RX_CONTROL_RBSZ_13_y(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_CONTROL_RBSZ_13_y_SHIFT)) & GMAC_DMA_CH1_RX_CONTROL_RBSZ_13_y_MASK)

#define GMAC_DMA_CH1_RX_CONTROL_Reserved_15_MASK (0x8000U)
#define GMAC_DMA_CH1_RX_CONTROL_Reserved_15_SHIFT (15U)
#define GMAC_DMA_CH1_RX_CONTROL_Reserved_15_WIDTH (1U)
#define GMAC_DMA_CH1_RX_CONTROL_Reserved_15(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_CONTROL_Reserved_15_SHIFT)) & GMAC_DMA_CH1_RX_CONTROL_Reserved_15_MASK)

#define GMAC_DMA_CH1_RX_CONTROL_RxPBL_MASK       (0x3F0000U)
#define GMAC_DMA_CH1_RX_CONTROL_RxPBL_SHIFT      (16U)
#define GMAC_DMA_CH1_RX_CONTROL_RxPBL_WIDTH      (6U)
#define GMAC_DMA_CH1_RX_CONTROL_RxPBL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_CONTROL_RxPBL_SHIFT)) & GMAC_DMA_CH1_RX_CONTROL_RxPBL_MASK)

#define GMAC_DMA_CH1_RX_CONTROL_ERIC_MASK        (0x400000U)
#define GMAC_DMA_CH1_RX_CONTROL_ERIC_SHIFT       (22U)
#define GMAC_DMA_CH1_RX_CONTROL_ERIC_WIDTH       (1U)
#define GMAC_DMA_CH1_RX_CONTROL_ERIC(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_CONTROL_ERIC_SHIFT)) & GMAC_DMA_CH1_RX_CONTROL_ERIC_MASK)

#define GMAC_DMA_CH1_RX_CONTROL_Reserved_23_MASK (0x800000U)
#define GMAC_DMA_CH1_RX_CONTROL_Reserved_23_SHIFT (23U)
#define GMAC_DMA_CH1_RX_CONTROL_Reserved_23_WIDTH (1U)
#define GMAC_DMA_CH1_RX_CONTROL_Reserved_23(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_CONTROL_Reserved_23_SHIFT)) & GMAC_DMA_CH1_RX_CONTROL_Reserved_23_MASK)

#define GMAC_DMA_CH1_RX_CONTROL_Reserved_RQOS_MASK (0xF000000U)
#define GMAC_DMA_CH1_RX_CONTROL_Reserved_RQOS_SHIFT (24U)
#define GMAC_DMA_CH1_RX_CONTROL_Reserved_RQOS_WIDTH (4U)
#define GMAC_DMA_CH1_RX_CONTROL_Reserved_RQOS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_CONTROL_Reserved_RQOS_SHIFT)) & GMAC_DMA_CH1_RX_CONTROL_Reserved_RQOS_MASK)

#define GMAC_DMA_CH1_RX_CONTROL_Reserved_30_28_MASK (0x70000000U)
#define GMAC_DMA_CH1_RX_CONTROL_Reserved_30_28_SHIFT (28U)
#define GMAC_DMA_CH1_RX_CONTROL_Reserved_30_28_WIDTH (3U)
#define GMAC_DMA_CH1_RX_CONTROL_Reserved_30_28(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_CONTROL_Reserved_30_28_SHIFT)) & GMAC_DMA_CH1_RX_CONTROL_Reserved_30_28_MASK)

#define GMAC_DMA_CH1_RX_CONTROL_RPF_MASK         (0x80000000U)
#define GMAC_DMA_CH1_RX_CONTROL_RPF_SHIFT        (31U)
#define GMAC_DMA_CH1_RX_CONTROL_RPF_WIDTH        (1U)
#define GMAC_DMA_CH1_RX_CONTROL_RPF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_CONTROL_RPF_SHIFT)) & GMAC_DMA_CH1_RX_CONTROL_RPF_MASK)
/*! @} */

/*! @name DMA_CH1_TXDESC_LIST_ADDRESS -  */
/*! @{ */

#define GMAC_DMA_CH1_TXDESC_LIST_ADDRESS_Reserved_LSb_MASK (0x7U)
#define GMAC_DMA_CH1_TXDESC_LIST_ADDRESS_Reserved_LSb_SHIFT (0U)
#define GMAC_DMA_CH1_TXDESC_LIST_ADDRESS_Reserved_LSb_WIDTH (3U)
#define GMAC_DMA_CH1_TXDESC_LIST_ADDRESS_Reserved_LSb(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TXDESC_LIST_ADDRESS_Reserved_LSb_SHIFT)) & GMAC_DMA_CH1_TXDESC_LIST_ADDRESS_Reserved_LSb_MASK)

#define GMAC_DMA_CH1_TXDESC_LIST_ADDRESS_TDESLA_MASK (0xFFFFFFF8U)
#define GMAC_DMA_CH1_TXDESC_LIST_ADDRESS_TDESLA_SHIFT (3U)
#define GMAC_DMA_CH1_TXDESC_LIST_ADDRESS_TDESLA_WIDTH (29U)
#define GMAC_DMA_CH1_TXDESC_LIST_ADDRESS_TDESLA(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TXDESC_LIST_ADDRESS_TDESLA_SHIFT)) & GMAC_DMA_CH1_TXDESC_LIST_ADDRESS_TDESLA_MASK)
/*! @} */

/*! @name DMA_CH1_RXDESC_LIST_ADDRESS -  */
/*! @{ */

#define GMAC_DMA_CH1_RXDESC_LIST_ADDRESS_Reserved_LSb_MASK (0x7U)
#define GMAC_DMA_CH1_RXDESC_LIST_ADDRESS_Reserved_LSb_SHIFT (0U)
#define GMAC_DMA_CH1_RXDESC_LIST_ADDRESS_Reserved_LSb_WIDTH (3U)
#define GMAC_DMA_CH1_RXDESC_LIST_ADDRESS_Reserved_LSb(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RXDESC_LIST_ADDRESS_Reserved_LSb_SHIFT)) & GMAC_DMA_CH1_RXDESC_LIST_ADDRESS_Reserved_LSb_MASK)

#define GMAC_DMA_CH1_RXDESC_LIST_ADDRESS_RDESLA_MASK (0xFFFFFFF8U)
#define GMAC_DMA_CH1_RXDESC_LIST_ADDRESS_RDESLA_SHIFT (3U)
#define GMAC_DMA_CH1_RXDESC_LIST_ADDRESS_RDESLA_WIDTH (29U)
#define GMAC_DMA_CH1_RXDESC_LIST_ADDRESS_RDESLA(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RXDESC_LIST_ADDRESS_RDESLA_SHIFT)) & GMAC_DMA_CH1_RXDESC_LIST_ADDRESS_RDESLA_MASK)
/*! @} */

/*! @name DMA_CH1_TXDESC_TAIL_POINTER -  */
/*! @{ */

#define GMAC_DMA_CH1_TXDESC_TAIL_POINTER_Reserved_LSb_MASK (0x7U)
#define GMAC_DMA_CH1_TXDESC_TAIL_POINTER_Reserved_LSb_SHIFT (0U)
#define GMAC_DMA_CH1_TXDESC_TAIL_POINTER_Reserved_LSb_WIDTH (3U)
#define GMAC_DMA_CH1_TXDESC_TAIL_POINTER_Reserved_LSb(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TXDESC_TAIL_POINTER_Reserved_LSb_SHIFT)) & GMAC_DMA_CH1_TXDESC_TAIL_POINTER_Reserved_LSb_MASK)

#define GMAC_DMA_CH1_TXDESC_TAIL_POINTER_TDTP_MASK (0xFFFFFFF8U)
#define GMAC_DMA_CH1_TXDESC_TAIL_POINTER_TDTP_SHIFT (3U)
#define GMAC_DMA_CH1_TXDESC_TAIL_POINTER_TDTP_WIDTH (29U)
#define GMAC_DMA_CH1_TXDESC_TAIL_POINTER_TDTP(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TXDESC_TAIL_POINTER_TDTP_SHIFT)) & GMAC_DMA_CH1_TXDESC_TAIL_POINTER_TDTP_MASK)
/*! @} */

/*! @name DMA_CH1_RXDESC_TAIL_POINTER -  */
/*! @{ */

#define GMAC_DMA_CH1_RXDESC_TAIL_POINTER_Reserved_LSb_MASK (0x7U)
#define GMAC_DMA_CH1_RXDESC_TAIL_POINTER_Reserved_LSb_SHIFT (0U)
#define GMAC_DMA_CH1_RXDESC_TAIL_POINTER_Reserved_LSb_WIDTH (3U)
#define GMAC_DMA_CH1_RXDESC_TAIL_POINTER_Reserved_LSb(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RXDESC_TAIL_POINTER_Reserved_LSb_SHIFT)) & GMAC_DMA_CH1_RXDESC_TAIL_POINTER_Reserved_LSb_MASK)

#define GMAC_DMA_CH1_RXDESC_TAIL_POINTER_RDTP_MASK (0xFFFFFFF8U)
#define GMAC_DMA_CH1_RXDESC_TAIL_POINTER_RDTP_SHIFT (3U)
#define GMAC_DMA_CH1_RXDESC_TAIL_POINTER_RDTP_WIDTH (29U)
#define GMAC_DMA_CH1_RXDESC_TAIL_POINTER_RDTP(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RXDESC_TAIL_POINTER_RDTP_SHIFT)) & GMAC_DMA_CH1_RXDESC_TAIL_POINTER_RDTP_MASK)
/*! @} */

/*! @name DMA_CH1_TXDESC_RING_LENGTH -  */
/*! @{ */

#define GMAC_DMA_CH1_TXDESC_RING_LENGTH_TDRL_MASK (0x3FFU)
#define GMAC_DMA_CH1_TXDESC_RING_LENGTH_TDRL_SHIFT (0U)
#define GMAC_DMA_CH1_TXDESC_RING_LENGTH_TDRL_WIDTH (10U)
#define GMAC_DMA_CH1_TXDESC_RING_LENGTH_TDRL(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TXDESC_RING_LENGTH_TDRL_SHIFT)) & GMAC_DMA_CH1_TXDESC_RING_LENGTH_TDRL_MASK)

#define GMAC_DMA_CH1_TXDESC_RING_LENGTH_Reserved_31_10_MASK (0xFFFFFC00U)
#define GMAC_DMA_CH1_TXDESC_RING_LENGTH_Reserved_31_10_SHIFT (10U)
#define GMAC_DMA_CH1_TXDESC_RING_LENGTH_Reserved_31_10_WIDTH (22U)
#define GMAC_DMA_CH1_TXDESC_RING_LENGTH_Reserved_31_10(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_TXDESC_RING_LENGTH_Reserved_31_10_SHIFT)) & GMAC_DMA_CH1_TXDESC_RING_LENGTH_Reserved_31_10_MASK)
/*! @} */

/*! @name DMA_CH1_RX_CONTROL2 -  */
/*! @{ */

#define GMAC_DMA_CH1_RX_CONTROL2_RDRL_MASK       (0x3FFU)
#define GMAC_DMA_CH1_RX_CONTROL2_RDRL_SHIFT      (0U)
#define GMAC_DMA_CH1_RX_CONTROL2_RDRL_WIDTH      (10U)
#define GMAC_DMA_CH1_RX_CONTROL2_RDRL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_CONTROL2_RDRL_SHIFT)) & GMAC_DMA_CH1_RX_CONTROL2_RDRL_MASK)

#define GMAC_DMA_CH1_RX_CONTROL2_Reserved_x_10_MASK (0x1FC00U)
#define GMAC_DMA_CH1_RX_CONTROL2_Reserved_x_10_SHIFT (10U)
#define GMAC_DMA_CH1_RX_CONTROL2_Reserved_x_10_WIDTH (7U)
#define GMAC_DMA_CH1_RX_CONTROL2_Reserved_x_10(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_CONTROL2_Reserved_x_10_SHIFT)) & GMAC_DMA_CH1_RX_CONTROL2_Reserved_x_10_MASK)

#define GMAC_DMA_CH1_RX_CONTROL2_ARBS_MASK       (0xFE0000U)
#define GMAC_DMA_CH1_RX_CONTROL2_ARBS_SHIFT      (17U)
#define GMAC_DMA_CH1_RX_CONTROL2_ARBS_WIDTH      (7U)
#define GMAC_DMA_CH1_RX_CONTROL2_ARBS(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_CONTROL2_ARBS_SHIFT)) & GMAC_DMA_CH1_RX_CONTROL2_ARBS_MASK)

#define GMAC_DMA_CH1_RX_CONTROL2_Reserved_31_24_MASK (0xFF000000U)
#define GMAC_DMA_CH1_RX_CONTROL2_Reserved_31_24_SHIFT (24U)
#define GMAC_DMA_CH1_RX_CONTROL2_Reserved_31_24_WIDTH (8U)
#define GMAC_DMA_CH1_RX_CONTROL2_Reserved_31_24(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_CONTROL2_Reserved_31_24_SHIFT)) & GMAC_DMA_CH1_RX_CONTROL2_Reserved_31_24_MASK)
/*! @} */

/*! @name DMA_CH1_INTERRUPT_ENABLE -  */
/*! @{ */

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_TIE_MASK   (0x1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_TIE_SHIFT  (0U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_TIE_WIDTH  (1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_TIE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_TIE_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_TIE_MASK)

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_TXSE_MASK  (0x2U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_TXSE_SHIFT (1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_TXSE_WIDTH (1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_TXSE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_TXSE_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_TXSE_MASK)

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_TBUE_MASK  (0x4U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_TBUE_SHIFT (2U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_TBUE_WIDTH (1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_TBUE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_TBUE_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_TBUE_MASK)

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_Reserved_5_3_MASK (0x38U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_Reserved_5_3_SHIFT (3U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_Reserved_5_3_WIDTH (3U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_Reserved_5_3(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_Reserved_5_3_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_Reserved_5_3_MASK)

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RIE_MASK   (0x40U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RIE_SHIFT  (6U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RIE_WIDTH  (1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RIE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_RIE_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_RIE_MASK)

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RBUE_MASK  (0x80U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RBUE_SHIFT (7U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RBUE_WIDTH (1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RBUE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_RBUE_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_RBUE_MASK)

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RSE_MASK   (0x100U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RSE_SHIFT  (8U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RSE_WIDTH  (1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RSE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_RSE_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_RSE_MASK)

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RWTE_MASK  (0x200U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RWTE_SHIFT (9U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RWTE_WIDTH (1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_RWTE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_RWTE_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_RWTE_MASK)

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_ETIE_MASK  (0x400U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_ETIE_SHIFT (10U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_ETIE_WIDTH (1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_ETIE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_ETIE_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_ETIE_MASK)

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_ERIE_MASK  (0x800U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_ERIE_SHIFT (11U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_ERIE_WIDTH (1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_ERIE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_ERIE_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_ERIE_MASK)

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_FBEE_MASK  (0x1000U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_FBEE_SHIFT (12U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_FBEE_WIDTH (1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_FBEE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_FBEE_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_FBEE_MASK)

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_CDEE_MASK  (0x2000U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_CDEE_SHIFT (13U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_CDEE_WIDTH (1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_CDEE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_CDEE_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_CDEE_MASK)

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_AIE_MASK   (0x4000U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_AIE_SHIFT  (14U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_AIE_WIDTH  (1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_AIE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_AIE_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_AIE_MASK)

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_NIE_MASK   (0x8000U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_NIE_SHIFT  (15U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_NIE_WIDTH  (1U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_NIE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_NIE_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_NIE_MASK)

#define GMAC_DMA_CH1_INTERRUPT_ENABLE_Reserved_31_16_MASK (0xFFFF0000U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_Reserved_31_16_SHIFT (16U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_Reserved_31_16_WIDTH (16U)
#define GMAC_DMA_CH1_INTERRUPT_ENABLE_Reserved_31_16(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_INTERRUPT_ENABLE_Reserved_31_16_SHIFT)) & GMAC_DMA_CH1_INTERRUPT_ENABLE_Reserved_31_16_MASK)
/*! @} */

/*! @name DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER -  */
/*! @{ */

#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK (0xFFU)
#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWT_SHIFT (0U)
#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWT_WIDTH (8U)
#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWT(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWT_SHIFT)) & GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK)

#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_MASK (0xFF00U)
#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_SHIFT (8U)
#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_WIDTH (8U)
#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_SHIFT)) & GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_MASK)

#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK (0x30000U)
#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_SHIFT (16U)
#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_WIDTH (2U)
#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWTU(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_SHIFT)) & GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK)

#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_MASK (0xFFFC0000U)
#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_SHIFT (18U)
#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_WIDTH (14U)
#define GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_SHIFT)) & GMAC_DMA_CH1_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_MASK)
/*! @} */

/*! @name DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS -  */
/*! @{ */

#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK (0x1U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ESC_SHIFT (0U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ESC_WIDTH (1U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ESC(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ESC_SHIFT)) & GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK)

#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK (0x2U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ASC_SHIFT (1U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ASC_WIDTH (1U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ASC(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ASC_SHIFT)) & GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK)

#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_MASK (0xCU)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_SHIFT (2U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_WIDTH (2U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_SHIFT)) & GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_MASK)

#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_SIV_MASK (0xFFF0U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_SIV_SHIFT (4U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_SIV_WIDTH (12U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_SIV(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_SIV_SHIFT)) & GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_SIV_MASK)

#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK (0xF0000U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_RSN_SHIFT (16U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_RSN_WIDTH (4U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_RSN(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_RSN_SHIFT)) & GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK)

#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_MASK (0xFFF00000U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_SHIFT (20U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_WIDTH (12U)
#define GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_SHIFT)) & GMAC_DMA_CH1_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_MASK)
/*! @} */

/*! @name DMA_CH1_CURRENT_APP_TXDESC -  */
/*! @{ */

#define GMAC_DMA_CH1_CURRENT_APP_TXDESC_CURTDESAPTR_MASK (0xFFFFFFFFU)
#define GMAC_DMA_CH1_CURRENT_APP_TXDESC_CURTDESAPTR_SHIFT (0U)
#define GMAC_DMA_CH1_CURRENT_APP_TXDESC_CURTDESAPTR_WIDTH (32U)
#define GMAC_DMA_CH1_CURRENT_APP_TXDESC_CURTDESAPTR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_CURRENT_APP_TXDESC_CURTDESAPTR_SHIFT)) & GMAC_DMA_CH1_CURRENT_APP_TXDESC_CURTDESAPTR_MASK)
/*! @} */

/*! @name DMA_CH1_CURRENT_APP_RXDESC -  */
/*! @{ */

#define GMAC_DMA_CH1_CURRENT_APP_RXDESC_CURRDESAPTR_MASK (0xFFFFFFFFU)
#define GMAC_DMA_CH1_CURRENT_APP_RXDESC_CURRDESAPTR_SHIFT (0U)
#define GMAC_DMA_CH1_CURRENT_APP_RXDESC_CURRDESAPTR_WIDTH (32U)
#define GMAC_DMA_CH1_CURRENT_APP_RXDESC_CURRDESAPTR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_CURRENT_APP_RXDESC_CURRDESAPTR_SHIFT)) & GMAC_DMA_CH1_CURRENT_APP_RXDESC_CURRDESAPTR_MASK)
/*! @} */

/*! @name DMA_CH1_CURRENT_APP_TXBUFFER -  */
/*! @{ */

#define GMAC_DMA_CH1_CURRENT_APP_TXBUFFER_CURTBUFAPTR_MASK (0xFFFFFFFFU)
#define GMAC_DMA_CH1_CURRENT_APP_TXBUFFER_CURTBUFAPTR_SHIFT (0U)
#define GMAC_DMA_CH1_CURRENT_APP_TXBUFFER_CURTBUFAPTR_WIDTH (32U)
#define GMAC_DMA_CH1_CURRENT_APP_TXBUFFER_CURTBUFAPTR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_CURRENT_APP_TXBUFFER_CURTBUFAPTR_SHIFT)) & GMAC_DMA_CH1_CURRENT_APP_TXBUFFER_CURTBUFAPTR_MASK)
/*! @} */

/*! @name DMA_CH1_CURRENT_APP_RXBUFFER -  */
/*! @{ */

#define GMAC_DMA_CH1_CURRENT_APP_RXBUFFER_CURRBUFAPTR_MASK (0xFFFFFFFFU)
#define GMAC_DMA_CH1_CURRENT_APP_RXBUFFER_CURRBUFAPTR_SHIFT (0U)
#define GMAC_DMA_CH1_CURRENT_APP_RXBUFFER_CURRBUFAPTR_WIDTH (32U)
#define GMAC_DMA_CH1_CURRENT_APP_RXBUFFER_CURRBUFAPTR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_CURRENT_APP_RXBUFFER_CURRBUFAPTR_SHIFT)) & GMAC_DMA_CH1_CURRENT_APP_RXBUFFER_CURRBUFAPTR_MASK)
/*! @} */

/*! @name DMA_CH1_STATUS -  */
/*! @{ */

#define GMAC_DMA_CH1_STATUS_TI_MASK              (0x1U)
#define GMAC_DMA_CH1_STATUS_TI_SHIFT             (0U)
#define GMAC_DMA_CH1_STATUS_TI_WIDTH             (1U)
#define GMAC_DMA_CH1_STATUS_TI(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_TI_SHIFT)) & GMAC_DMA_CH1_STATUS_TI_MASK)

#define GMAC_DMA_CH1_STATUS_TPS_MASK             (0x2U)
#define GMAC_DMA_CH1_STATUS_TPS_SHIFT            (1U)
#define GMAC_DMA_CH1_STATUS_TPS_WIDTH            (1U)
#define GMAC_DMA_CH1_STATUS_TPS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_TPS_SHIFT)) & GMAC_DMA_CH1_STATUS_TPS_MASK)

#define GMAC_DMA_CH1_STATUS_TBU_MASK             (0x4U)
#define GMAC_DMA_CH1_STATUS_TBU_SHIFT            (2U)
#define GMAC_DMA_CH1_STATUS_TBU_WIDTH            (1U)
#define GMAC_DMA_CH1_STATUS_TBU(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_TBU_SHIFT)) & GMAC_DMA_CH1_STATUS_TBU_MASK)

#define GMAC_DMA_CH1_STATUS_Reserved_5_3_MASK    (0x38U)
#define GMAC_DMA_CH1_STATUS_Reserved_5_3_SHIFT   (3U)
#define GMAC_DMA_CH1_STATUS_Reserved_5_3_WIDTH   (3U)
#define GMAC_DMA_CH1_STATUS_Reserved_5_3(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_Reserved_5_3_SHIFT)) & GMAC_DMA_CH1_STATUS_Reserved_5_3_MASK)

#define GMAC_DMA_CH1_STATUS_RI_MASK              (0x40U)
#define GMAC_DMA_CH1_STATUS_RI_SHIFT             (6U)
#define GMAC_DMA_CH1_STATUS_RI_WIDTH             (1U)
#define GMAC_DMA_CH1_STATUS_RI(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_RI_SHIFT)) & GMAC_DMA_CH1_STATUS_RI_MASK)

#define GMAC_DMA_CH1_STATUS_RBU_MASK             (0x80U)
#define GMAC_DMA_CH1_STATUS_RBU_SHIFT            (7U)
#define GMAC_DMA_CH1_STATUS_RBU_WIDTH            (1U)
#define GMAC_DMA_CH1_STATUS_RBU(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_RBU_SHIFT)) & GMAC_DMA_CH1_STATUS_RBU_MASK)

#define GMAC_DMA_CH1_STATUS_RPS_MASK             (0x100U)
#define GMAC_DMA_CH1_STATUS_RPS_SHIFT            (8U)
#define GMAC_DMA_CH1_STATUS_RPS_WIDTH            (1U)
#define GMAC_DMA_CH1_STATUS_RPS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_RPS_SHIFT)) & GMAC_DMA_CH1_STATUS_RPS_MASK)

#define GMAC_DMA_CH1_STATUS_RWT_MASK             (0x200U)
#define GMAC_DMA_CH1_STATUS_RWT_SHIFT            (9U)
#define GMAC_DMA_CH1_STATUS_RWT_WIDTH            (1U)
#define GMAC_DMA_CH1_STATUS_RWT(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_RWT_SHIFT)) & GMAC_DMA_CH1_STATUS_RWT_MASK)

#define GMAC_DMA_CH1_STATUS_ETI_MASK             (0x400U)
#define GMAC_DMA_CH1_STATUS_ETI_SHIFT            (10U)
#define GMAC_DMA_CH1_STATUS_ETI_WIDTH            (1U)
#define GMAC_DMA_CH1_STATUS_ETI(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_ETI_SHIFT)) & GMAC_DMA_CH1_STATUS_ETI_MASK)

#define GMAC_DMA_CH1_STATUS_ERI_MASK             (0x800U)
#define GMAC_DMA_CH1_STATUS_ERI_SHIFT            (11U)
#define GMAC_DMA_CH1_STATUS_ERI_WIDTH            (1U)
#define GMAC_DMA_CH1_STATUS_ERI(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_ERI_SHIFT)) & GMAC_DMA_CH1_STATUS_ERI_MASK)

#define GMAC_DMA_CH1_STATUS_FBE_MASK             (0x1000U)
#define GMAC_DMA_CH1_STATUS_FBE_SHIFT            (12U)
#define GMAC_DMA_CH1_STATUS_FBE_WIDTH            (1U)
#define GMAC_DMA_CH1_STATUS_FBE(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_FBE_SHIFT)) & GMAC_DMA_CH1_STATUS_FBE_MASK)

#define GMAC_DMA_CH1_STATUS_CDE_MASK             (0x2000U)
#define GMAC_DMA_CH1_STATUS_CDE_SHIFT            (13U)
#define GMAC_DMA_CH1_STATUS_CDE_WIDTH            (1U)
#define GMAC_DMA_CH1_STATUS_CDE(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_CDE_SHIFT)) & GMAC_DMA_CH1_STATUS_CDE_MASK)

#define GMAC_DMA_CH1_STATUS_AIS_MASK             (0x4000U)
#define GMAC_DMA_CH1_STATUS_AIS_SHIFT            (14U)
#define GMAC_DMA_CH1_STATUS_AIS_WIDTH            (1U)
#define GMAC_DMA_CH1_STATUS_AIS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_AIS_SHIFT)) & GMAC_DMA_CH1_STATUS_AIS_MASK)

#define GMAC_DMA_CH1_STATUS_NIS_MASK             (0x8000U)
#define GMAC_DMA_CH1_STATUS_NIS_SHIFT            (15U)
#define GMAC_DMA_CH1_STATUS_NIS_WIDTH            (1U)
#define GMAC_DMA_CH1_STATUS_NIS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_NIS_SHIFT)) & GMAC_DMA_CH1_STATUS_NIS_MASK)

#define GMAC_DMA_CH1_STATUS_TEB_MASK             (0x70000U)
#define GMAC_DMA_CH1_STATUS_TEB_SHIFT            (16U)
#define GMAC_DMA_CH1_STATUS_TEB_WIDTH            (3U)
#define GMAC_DMA_CH1_STATUS_TEB(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_TEB_SHIFT)) & GMAC_DMA_CH1_STATUS_TEB_MASK)

#define GMAC_DMA_CH1_STATUS_REB_MASK             (0x380000U)
#define GMAC_DMA_CH1_STATUS_REB_SHIFT            (19U)
#define GMAC_DMA_CH1_STATUS_REB_WIDTH            (3U)
#define GMAC_DMA_CH1_STATUS_REB(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_REB_SHIFT)) & GMAC_DMA_CH1_STATUS_REB_MASK)

#define GMAC_DMA_CH1_STATUS_Reserved_31_22_MASK  (0xFFC00000U)
#define GMAC_DMA_CH1_STATUS_Reserved_31_22_SHIFT (22U)
#define GMAC_DMA_CH1_STATUS_Reserved_31_22_WIDTH (10U)
#define GMAC_DMA_CH1_STATUS_Reserved_31_22(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_STATUS_Reserved_31_22_SHIFT)) & GMAC_DMA_CH1_STATUS_Reserved_31_22_MASK)
/*! @} */

/*! @name DMA_CH1_MISS_FRAME_CNT -  */
/*! @{ */

#define GMAC_DMA_CH1_MISS_FRAME_CNT_MFC_MASK     (0x7FFU)
#define GMAC_DMA_CH1_MISS_FRAME_CNT_MFC_SHIFT    (0U)
#define GMAC_DMA_CH1_MISS_FRAME_CNT_MFC_WIDTH    (11U)
#define GMAC_DMA_CH1_MISS_FRAME_CNT_MFC(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_MISS_FRAME_CNT_MFC_SHIFT)) & GMAC_DMA_CH1_MISS_FRAME_CNT_MFC_MASK)

#define GMAC_DMA_CH1_MISS_FRAME_CNT_Reserved_14_11_MASK (0x7800U)
#define GMAC_DMA_CH1_MISS_FRAME_CNT_Reserved_14_11_SHIFT (11U)
#define GMAC_DMA_CH1_MISS_FRAME_CNT_Reserved_14_11_WIDTH (4U)
#define GMAC_DMA_CH1_MISS_FRAME_CNT_Reserved_14_11(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_MISS_FRAME_CNT_Reserved_14_11_SHIFT)) & GMAC_DMA_CH1_MISS_FRAME_CNT_Reserved_14_11_MASK)

#define GMAC_DMA_CH1_MISS_FRAME_CNT_MFCO_MASK    (0x8000U)
#define GMAC_DMA_CH1_MISS_FRAME_CNT_MFCO_SHIFT   (15U)
#define GMAC_DMA_CH1_MISS_FRAME_CNT_MFCO_WIDTH   (1U)
#define GMAC_DMA_CH1_MISS_FRAME_CNT_MFCO(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_MISS_FRAME_CNT_MFCO_SHIFT)) & GMAC_DMA_CH1_MISS_FRAME_CNT_MFCO_MASK)

#define GMAC_DMA_CH1_MISS_FRAME_CNT_Reserved_31_16_MASK (0xFFFF0000U)
#define GMAC_DMA_CH1_MISS_FRAME_CNT_Reserved_31_16_SHIFT (16U)
#define GMAC_DMA_CH1_MISS_FRAME_CNT_Reserved_31_16_WIDTH (16U)
#define GMAC_DMA_CH1_MISS_FRAME_CNT_Reserved_31_16(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_MISS_FRAME_CNT_Reserved_31_16_SHIFT)) & GMAC_DMA_CH1_MISS_FRAME_CNT_Reserved_31_16_MASK)
/*! @} */

/*! @name DMA_CH1_RXP_ACCEPT_CNT -  */
/*! @{ */

#define GMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPAC_MASK   (0x7FFFFFFFU)
#define GMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPAC_SHIFT  (0U)
#define GMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPAC_WIDTH  (31U)
#define GMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPAC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPAC_SHIFT)) & GMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPAC_MASK)

#define GMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPACOF_MASK (0x80000000U)
#define GMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPACOF_SHIFT (31U)
#define GMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPACOF_WIDTH (1U)
#define GMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPACOF(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPACOF_SHIFT)) & GMAC_DMA_CH1_RXP_ACCEPT_CNT_RXPACOF_MASK)
/*! @} */

/*! @name DMA_CH1_RX_ERI_CNT -  */
/*! @{ */

#define GMAC_DMA_CH1_RX_ERI_CNT_ECNT_MASK        (0xFFFU)
#define GMAC_DMA_CH1_RX_ERI_CNT_ECNT_SHIFT       (0U)
#define GMAC_DMA_CH1_RX_ERI_CNT_ECNT_WIDTH       (12U)
#define GMAC_DMA_CH1_RX_ERI_CNT_ECNT(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_ERI_CNT_ECNT_SHIFT)) & GMAC_DMA_CH1_RX_ERI_CNT_ECNT_MASK)

#define GMAC_DMA_CH1_RX_ERI_CNT_Reserved_31_12_MASK (0xFFFFF000U)
#define GMAC_DMA_CH1_RX_ERI_CNT_Reserved_31_12_SHIFT (12U)
#define GMAC_DMA_CH1_RX_ERI_CNT_Reserved_31_12_WIDTH (20U)
#define GMAC_DMA_CH1_RX_ERI_CNT_Reserved_31_12(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH1_RX_ERI_CNT_Reserved_31_12_SHIFT)) & GMAC_DMA_CH1_RX_ERI_CNT_Reserved_31_12_MASK)
/*! @} */

/*! @name DMA_CH2_CONTROL -  */
/*! @{ */

#define GMAC_DMA_CH2_CONTROL_Reserved_MSS_MASK   (0x3FFFU)
#define GMAC_DMA_CH2_CONTROL_Reserved_MSS_SHIFT  (0U)
#define GMAC_DMA_CH2_CONTROL_Reserved_MSS_WIDTH  (14U)
#define GMAC_DMA_CH2_CONTROL_Reserved_MSS(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_CONTROL_Reserved_MSS_SHIFT)) & GMAC_DMA_CH2_CONTROL_Reserved_MSS_MASK)

#define GMAC_DMA_CH2_CONTROL_Reserved_15_14_MASK (0xC000U)
#define GMAC_DMA_CH2_CONTROL_Reserved_15_14_SHIFT (14U)
#define GMAC_DMA_CH2_CONTROL_Reserved_15_14_WIDTH (2U)
#define GMAC_DMA_CH2_CONTROL_Reserved_15_14(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_CONTROL_Reserved_15_14_SHIFT)) & GMAC_DMA_CH2_CONTROL_Reserved_15_14_MASK)

#define GMAC_DMA_CH2_CONTROL_PBLx8_MASK          (0x10000U)
#define GMAC_DMA_CH2_CONTROL_PBLx8_SHIFT         (16U)
#define GMAC_DMA_CH2_CONTROL_PBLx8_WIDTH         (1U)
#define GMAC_DMA_CH2_CONTROL_PBLx8(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_CONTROL_PBLx8_SHIFT)) & GMAC_DMA_CH2_CONTROL_PBLx8_MASK)

#define GMAC_DMA_CH2_CONTROL_Reserved_17_MASK    (0x20000U)
#define GMAC_DMA_CH2_CONTROL_Reserved_17_SHIFT   (17U)
#define GMAC_DMA_CH2_CONTROL_Reserved_17_WIDTH   (1U)
#define GMAC_DMA_CH2_CONTROL_Reserved_17(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_CONTROL_Reserved_17_SHIFT)) & GMAC_DMA_CH2_CONTROL_Reserved_17_MASK)

#define GMAC_DMA_CH2_CONTROL_DSL_MASK            (0x1C0000U)
#define GMAC_DMA_CH2_CONTROL_DSL_SHIFT           (18U)
#define GMAC_DMA_CH2_CONTROL_DSL_WIDTH           (3U)
#define GMAC_DMA_CH2_CONTROL_DSL(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_CONTROL_DSL_SHIFT)) & GMAC_DMA_CH2_CONTROL_DSL_MASK)

#define GMAC_DMA_CH2_CONTROL_Reserved_23_21_MASK (0xE00000U)
#define GMAC_DMA_CH2_CONTROL_Reserved_23_21_SHIFT (21U)
#define GMAC_DMA_CH2_CONTROL_Reserved_23_21_WIDTH (3U)
#define GMAC_DMA_CH2_CONTROL_Reserved_23_21(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_CONTROL_Reserved_23_21_SHIFT)) & GMAC_DMA_CH2_CONTROL_Reserved_23_21_MASK)

#define GMAC_DMA_CH2_CONTROL_SPH_MASK            (0x1000000U)
#define GMAC_DMA_CH2_CONTROL_SPH_SHIFT           (24U)
#define GMAC_DMA_CH2_CONTROL_SPH_WIDTH           (1U)
#define GMAC_DMA_CH2_CONTROL_SPH(x)              (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_CONTROL_SPH_SHIFT)) & GMAC_DMA_CH2_CONTROL_SPH_MASK)

#define GMAC_DMA_CH2_CONTROL_Reserved_31_25_MASK (0xFE000000U)
#define GMAC_DMA_CH2_CONTROL_Reserved_31_25_SHIFT (25U)
#define GMAC_DMA_CH2_CONTROL_Reserved_31_25_WIDTH (7U)
#define GMAC_DMA_CH2_CONTROL_Reserved_31_25(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_CONTROL_Reserved_31_25_SHIFT)) & GMAC_DMA_CH2_CONTROL_Reserved_31_25_MASK)
/*! @} */

/*! @name DMA_CH2_TX_CONTROL -  */
/*! @{ */

#define GMAC_DMA_CH2_TX_CONTROL_ST_MASK          (0x1U)
#define GMAC_DMA_CH2_TX_CONTROL_ST_SHIFT         (0U)
#define GMAC_DMA_CH2_TX_CONTROL_ST_WIDTH         (1U)
#define GMAC_DMA_CH2_TX_CONTROL_ST(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TX_CONTROL_ST_SHIFT)) & GMAC_DMA_CH2_TX_CONTROL_ST_MASK)

#define GMAC_DMA_CH2_TX_CONTROL_TCW_MASK         (0xEU)
#define GMAC_DMA_CH2_TX_CONTROL_TCW_SHIFT        (1U)
#define GMAC_DMA_CH2_TX_CONTROL_TCW_WIDTH        (3U)
#define GMAC_DMA_CH2_TX_CONTROL_TCW(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TX_CONTROL_TCW_SHIFT)) & GMAC_DMA_CH2_TX_CONTROL_TCW_MASK)

#define GMAC_DMA_CH2_TX_CONTROL_OSF_MASK         (0x10U)
#define GMAC_DMA_CH2_TX_CONTROL_OSF_SHIFT        (4U)
#define GMAC_DMA_CH2_TX_CONTROL_OSF_WIDTH        (1U)
#define GMAC_DMA_CH2_TX_CONTROL_OSF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TX_CONTROL_OSF_SHIFT)) & GMAC_DMA_CH2_TX_CONTROL_OSF_MASK)

#define GMAC_DMA_CH2_TX_CONTROL_Reserved_11_5_MASK (0xFE0U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_11_5_SHIFT (5U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_11_5_WIDTH (7U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_11_5(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TX_CONTROL_Reserved_11_5_SHIFT)) & GMAC_DMA_CH2_TX_CONTROL_Reserved_11_5_MASK)

#define GMAC_DMA_CH2_TX_CONTROL_Reserved_TSE_MASK (0x1000U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_TSE_SHIFT (12U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_TSE_WIDTH (1U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_TSE(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TX_CONTROL_Reserved_TSE_SHIFT)) & GMAC_DMA_CH2_TX_CONTROL_Reserved_TSE_MASK)

#define GMAC_DMA_CH2_TX_CONTROL_Reserved_TSE_MODE_MASK (0x6000U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_TSE_MODE_SHIFT (13U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_TSE_MODE_WIDTH (2U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_TSE_MODE(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TX_CONTROL_Reserved_TSE_MODE_SHIFT)) & GMAC_DMA_CH2_TX_CONTROL_Reserved_TSE_MODE_MASK)

#define GMAC_DMA_CH2_TX_CONTROL_Reserved_IPBL_MASK (0x8000U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_IPBL_SHIFT (15U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_IPBL_WIDTH (1U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_IPBL(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TX_CONTROL_Reserved_IPBL_SHIFT)) & GMAC_DMA_CH2_TX_CONTROL_Reserved_IPBL_MASK)

#define GMAC_DMA_CH2_TX_CONTROL_TxPBL_MASK       (0x3F0000U)
#define GMAC_DMA_CH2_TX_CONTROL_TxPBL_SHIFT      (16U)
#define GMAC_DMA_CH2_TX_CONTROL_TxPBL_WIDTH      (6U)
#define GMAC_DMA_CH2_TX_CONTROL_TxPBL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TX_CONTROL_TxPBL_SHIFT)) & GMAC_DMA_CH2_TX_CONTROL_TxPBL_MASK)

#define GMAC_DMA_CH2_TX_CONTROL_ETIC_MASK        (0x400000U)
#define GMAC_DMA_CH2_TX_CONTROL_ETIC_SHIFT       (22U)
#define GMAC_DMA_CH2_TX_CONTROL_ETIC_WIDTH       (1U)
#define GMAC_DMA_CH2_TX_CONTROL_ETIC(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TX_CONTROL_ETIC_SHIFT)) & GMAC_DMA_CH2_TX_CONTROL_ETIC_MASK)

#define GMAC_DMA_CH2_TX_CONTROL_Reserved_23_MASK (0x800000U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_23_SHIFT (23U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_23_WIDTH (1U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_23(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TX_CONTROL_Reserved_23_SHIFT)) & GMAC_DMA_CH2_TX_CONTROL_Reserved_23_MASK)

#define GMAC_DMA_CH2_TX_CONTROL_Reserved_TQOS_MASK (0xF000000U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_TQOS_SHIFT (24U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_TQOS_WIDTH (4U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_TQOS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TX_CONTROL_Reserved_TQOS_SHIFT)) & GMAC_DMA_CH2_TX_CONTROL_Reserved_TQOS_MASK)

#define GMAC_DMA_CH2_TX_CONTROL_EDSE_MASK        (0x10000000U)
#define GMAC_DMA_CH2_TX_CONTROL_EDSE_SHIFT       (28U)
#define GMAC_DMA_CH2_TX_CONTROL_EDSE_WIDTH       (1U)
#define GMAC_DMA_CH2_TX_CONTROL_EDSE(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TX_CONTROL_EDSE_SHIFT)) & GMAC_DMA_CH2_TX_CONTROL_EDSE_MASK)

#define GMAC_DMA_CH2_TX_CONTROL_TFSEL_MASK       (0x60000000U)
#define GMAC_DMA_CH2_TX_CONTROL_TFSEL_SHIFT      (29U)
#define GMAC_DMA_CH2_TX_CONTROL_TFSEL_WIDTH      (2U)
#define GMAC_DMA_CH2_TX_CONTROL_TFSEL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TX_CONTROL_TFSEL_SHIFT)) & GMAC_DMA_CH2_TX_CONTROL_TFSEL_MASK)

#define GMAC_DMA_CH2_TX_CONTROL_Reserved_31_MASK (0x80000000U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_31_SHIFT (31U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_31_WIDTH (1U)
#define GMAC_DMA_CH2_TX_CONTROL_Reserved_31(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TX_CONTROL_Reserved_31_SHIFT)) & GMAC_DMA_CH2_TX_CONTROL_Reserved_31_MASK)
/*! @} */

/*! @name DMA_CH2_RX_CONTROL -  */
/*! @{ */

#define GMAC_DMA_CH2_RX_CONTROL_SR_MASK          (0x1U)
#define GMAC_DMA_CH2_RX_CONTROL_SR_SHIFT         (0U)
#define GMAC_DMA_CH2_RX_CONTROL_SR_WIDTH         (1U)
#define GMAC_DMA_CH2_RX_CONTROL_SR(x)            (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_CONTROL_SR_SHIFT)) & GMAC_DMA_CH2_RX_CONTROL_SR_MASK)

#define GMAC_DMA_CH2_RX_CONTROL_RBSZ_x_0_MASK    (0xEU)
#define GMAC_DMA_CH2_RX_CONTROL_RBSZ_x_0_SHIFT   (1U)
#define GMAC_DMA_CH2_RX_CONTROL_RBSZ_x_0_WIDTH   (3U)
#define GMAC_DMA_CH2_RX_CONTROL_RBSZ_x_0(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_CONTROL_RBSZ_x_0_SHIFT)) & GMAC_DMA_CH2_RX_CONTROL_RBSZ_x_0_MASK)

#define GMAC_DMA_CH2_RX_CONTROL_RBSZ_13_y_MASK   (0x7FF0U)
#define GMAC_DMA_CH2_RX_CONTROL_RBSZ_13_y_SHIFT  (4U)
#define GMAC_DMA_CH2_RX_CONTROL_RBSZ_13_y_WIDTH  (11U)
#define GMAC_DMA_CH2_RX_CONTROL_RBSZ_13_y(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_CONTROL_RBSZ_13_y_SHIFT)) & GMAC_DMA_CH2_RX_CONTROL_RBSZ_13_y_MASK)

#define GMAC_DMA_CH2_RX_CONTROL_Reserved_15_MASK (0x8000U)
#define GMAC_DMA_CH2_RX_CONTROL_Reserved_15_SHIFT (15U)
#define GMAC_DMA_CH2_RX_CONTROL_Reserved_15_WIDTH (1U)
#define GMAC_DMA_CH2_RX_CONTROL_Reserved_15(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_CONTROL_Reserved_15_SHIFT)) & GMAC_DMA_CH2_RX_CONTROL_Reserved_15_MASK)

#define GMAC_DMA_CH2_RX_CONTROL_RxPBL_MASK       (0x3F0000U)
#define GMAC_DMA_CH2_RX_CONTROL_RxPBL_SHIFT      (16U)
#define GMAC_DMA_CH2_RX_CONTROL_RxPBL_WIDTH      (6U)
#define GMAC_DMA_CH2_RX_CONTROL_RxPBL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_CONTROL_RxPBL_SHIFT)) & GMAC_DMA_CH2_RX_CONTROL_RxPBL_MASK)

#define GMAC_DMA_CH2_RX_CONTROL_ERIC_MASK        (0x400000U)
#define GMAC_DMA_CH2_RX_CONTROL_ERIC_SHIFT       (22U)
#define GMAC_DMA_CH2_RX_CONTROL_ERIC_WIDTH       (1U)
#define GMAC_DMA_CH2_RX_CONTROL_ERIC(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_CONTROL_ERIC_SHIFT)) & GMAC_DMA_CH2_RX_CONTROL_ERIC_MASK)

#define GMAC_DMA_CH2_RX_CONTROL_Reserved_23_MASK (0x800000U)
#define GMAC_DMA_CH2_RX_CONTROL_Reserved_23_SHIFT (23U)
#define GMAC_DMA_CH2_RX_CONTROL_Reserved_23_WIDTH (1U)
#define GMAC_DMA_CH2_RX_CONTROL_Reserved_23(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_CONTROL_Reserved_23_SHIFT)) & GMAC_DMA_CH2_RX_CONTROL_Reserved_23_MASK)

#define GMAC_DMA_CH2_RX_CONTROL_Reserved_RQOS_MASK (0xF000000U)
#define GMAC_DMA_CH2_RX_CONTROL_Reserved_RQOS_SHIFT (24U)
#define GMAC_DMA_CH2_RX_CONTROL_Reserved_RQOS_WIDTH (4U)
#define GMAC_DMA_CH2_RX_CONTROL_Reserved_RQOS(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_CONTROL_Reserved_RQOS_SHIFT)) & GMAC_DMA_CH2_RX_CONTROL_Reserved_RQOS_MASK)

#define GMAC_DMA_CH2_RX_CONTROL_Reserved_30_28_MASK (0x70000000U)
#define GMAC_DMA_CH2_RX_CONTROL_Reserved_30_28_SHIFT (28U)
#define GMAC_DMA_CH2_RX_CONTROL_Reserved_30_28_WIDTH (3U)
#define GMAC_DMA_CH2_RX_CONTROL_Reserved_30_28(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_CONTROL_Reserved_30_28_SHIFT)) & GMAC_DMA_CH2_RX_CONTROL_Reserved_30_28_MASK)

#define GMAC_DMA_CH2_RX_CONTROL_RPF_MASK         (0x80000000U)
#define GMAC_DMA_CH2_RX_CONTROL_RPF_SHIFT        (31U)
#define GMAC_DMA_CH2_RX_CONTROL_RPF_WIDTH        (1U)
#define GMAC_DMA_CH2_RX_CONTROL_RPF(x)           (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_CONTROL_RPF_SHIFT)) & GMAC_DMA_CH2_RX_CONTROL_RPF_MASK)
/*! @} */

/*! @name DMA_CH2_TXDESC_LIST_ADDRESS -  */
/*! @{ */

#define GMAC_DMA_CH2_TXDESC_LIST_ADDRESS_Reserved_LSb_MASK (0x7U)
#define GMAC_DMA_CH2_TXDESC_LIST_ADDRESS_Reserved_LSb_SHIFT (0U)
#define GMAC_DMA_CH2_TXDESC_LIST_ADDRESS_Reserved_LSb_WIDTH (3U)
#define GMAC_DMA_CH2_TXDESC_LIST_ADDRESS_Reserved_LSb(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TXDESC_LIST_ADDRESS_Reserved_LSb_SHIFT)) & GMAC_DMA_CH2_TXDESC_LIST_ADDRESS_Reserved_LSb_MASK)

#define GMAC_DMA_CH2_TXDESC_LIST_ADDRESS_TDESLA_MASK (0xFFFFFFF8U)
#define GMAC_DMA_CH2_TXDESC_LIST_ADDRESS_TDESLA_SHIFT (3U)
#define GMAC_DMA_CH2_TXDESC_LIST_ADDRESS_TDESLA_WIDTH (29U)
#define GMAC_DMA_CH2_TXDESC_LIST_ADDRESS_TDESLA(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TXDESC_LIST_ADDRESS_TDESLA_SHIFT)) & GMAC_DMA_CH2_TXDESC_LIST_ADDRESS_TDESLA_MASK)
/*! @} */

/*! @name DMA_CH2_RXDESC_LIST_ADDRESS -  */
/*! @{ */

#define GMAC_DMA_CH2_RXDESC_LIST_ADDRESS_Reserved_LSb_MASK (0x7U)
#define GMAC_DMA_CH2_RXDESC_LIST_ADDRESS_Reserved_LSb_SHIFT (0U)
#define GMAC_DMA_CH2_RXDESC_LIST_ADDRESS_Reserved_LSb_WIDTH (3U)
#define GMAC_DMA_CH2_RXDESC_LIST_ADDRESS_Reserved_LSb(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RXDESC_LIST_ADDRESS_Reserved_LSb_SHIFT)) & GMAC_DMA_CH2_RXDESC_LIST_ADDRESS_Reserved_LSb_MASK)

#define GMAC_DMA_CH2_RXDESC_LIST_ADDRESS_RDESLA_MASK (0xFFFFFFF8U)
#define GMAC_DMA_CH2_RXDESC_LIST_ADDRESS_RDESLA_SHIFT (3U)
#define GMAC_DMA_CH2_RXDESC_LIST_ADDRESS_RDESLA_WIDTH (29U)
#define GMAC_DMA_CH2_RXDESC_LIST_ADDRESS_RDESLA(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RXDESC_LIST_ADDRESS_RDESLA_SHIFT)) & GMAC_DMA_CH2_RXDESC_LIST_ADDRESS_RDESLA_MASK)
/*! @} */

/*! @name DMA_CH2_TXDESC_TAIL_POINTER -  */
/*! @{ */

#define GMAC_DMA_CH2_TXDESC_TAIL_POINTER_Reserved_LSb_MASK (0x7U)
#define GMAC_DMA_CH2_TXDESC_TAIL_POINTER_Reserved_LSb_SHIFT (0U)
#define GMAC_DMA_CH2_TXDESC_TAIL_POINTER_Reserved_LSb_WIDTH (3U)
#define GMAC_DMA_CH2_TXDESC_TAIL_POINTER_Reserved_LSb(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TXDESC_TAIL_POINTER_Reserved_LSb_SHIFT)) & GMAC_DMA_CH2_TXDESC_TAIL_POINTER_Reserved_LSb_MASK)

#define GMAC_DMA_CH2_TXDESC_TAIL_POINTER_TDTP_MASK (0xFFFFFFF8U)
#define GMAC_DMA_CH2_TXDESC_TAIL_POINTER_TDTP_SHIFT (3U)
#define GMAC_DMA_CH2_TXDESC_TAIL_POINTER_TDTP_WIDTH (29U)
#define GMAC_DMA_CH2_TXDESC_TAIL_POINTER_TDTP(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TXDESC_TAIL_POINTER_TDTP_SHIFT)) & GMAC_DMA_CH2_TXDESC_TAIL_POINTER_TDTP_MASK)
/*! @} */

/*! @name DMA_CH2_RXDESC_TAIL_POINTER -  */
/*! @{ */

#define GMAC_DMA_CH2_RXDESC_TAIL_POINTER_Reserved_LSb_MASK (0x7U)
#define GMAC_DMA_CH2_RXDESC_TAIL_POINTER_Reserved_LSb_SHIFT (0U)
#define GMAC_DMA_CH2_RXDESC_TAIL_POINTER_Reserved_LSb_WIDTH (3U)
#define GMAC_DMA_CH2_RXDESC_TAIL_POINTER_Reserved_LSb(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RXDESC_TAIL_POINTER_Reserved_LSb_SHIFT)) & GMAC_DMA_CH2_RXDESC_TAIL_POINTER_Reserved_LSb_MASK)

#define GMAC_DMA_CH2_RXDESC_TAIL_POINTER_RDTP_MASK (0xFFFFFFF8U)
#define GMAC_DMA_CH2_RXDESC_TAIL_POINTER_RDTP_SHIFT (3U)
#define GMAC_DMA_CH2_RXDESC_TAIL_POINTER_RDTP_WIDTH (29U)
#define GMAC_DMA_CH2_RXDESC_TAIL_POINTER_RDTP(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RXDESC_TAIL_POINTER_RDTP_SHIFT)) & GMAC_DMA_CH2_RXDESC_TAIL_POINTER_RDTP_MASK)
/*! @} */

/*! @name DMA_CH2_TXDESC_RING_LENGTH -  */
/*! @{ */

#define GMAC_DMA_CH2_TXDESC_RING_LENGTH_TDRL_MASK (0x3FFU)
#define GMAC_DMA_CH2_TXDESC_RING_LENGTH_TDRL_SHIFT (0U)
#define GMAC_DMA_CH2_TXDESC_RING_LENGTH_TDRL_WIDTH (10U)
#define GMAC_DMA_CH2_TXDESC_RING_LENGTH_TDRL(x)  (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TXDESC_RING_LENGTH_TDRL_SHIFT)) & GMAC_DMA_CH2_TXDESC_RING_LENGTH_TDRL_MASK)

#define GMAC_DMA_CH2_TXDESC_RING_LENGTH_Reserved_31_10_MASK (0xFFFFFC00U)
#define GMAC_DMA_CH2_TXDESC_RING_LENGTH_Reserved_31_10_SHIFT (10U)
#define GMAC_DMA_CH2_TXDESC_RING_LENGTH_Reserved_31_10_WIDTH (22U)
#define GMAC_DMA_CH2_TXDESC_RING_LENGTH_Reserved_31_10(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_TXDESC_RING_LENGTH_Reserved_31_10_SHIFT)) & GMAC_DMA_CH2_TXDESC_RING_LENGTH_Reserved_31_10_MASK)
/*! @} */

/*! @name DMA_CH2_RX_CONTROL2 -  */
/*! @{ */

#define GMAC_DMA_CH2_RX_CONTROL2_RDRL_MASK       (0x3FFU)
#define GMAC_DMA_CH2_RX_CONTROL2_RDRL_SHIFT      (0U)
#define GMAC_DMA_CH2_RX_CONTROL2_RDRL_WIDTH      (10U)
#define GMAC_DMA_CH2_RX_CONTROL2_RDRL(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_CONTROL2_RDRL_SHIFT)) & GMAC_DMA_CH2_RX_CONTROL2_RDRL_MASK)

#define GMAC_DMA_CH2_RX_CONTROL2_Reserved_x_10_MASK (0x1FC00U)
#define GMAC_DMA_CH2_RX_CONTROL2_Reserved_x_10_SHIFT (10U)
#define GMAC_DMA_CH2_RX_CONTROL2_Reserved_x_10_WIDTH (7U)
#define GMAC_DMA_CH2_RX_CONTROL2_Reserved_x_10(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_CONTROL2_Reserved_x_10_SHIFT)) & GMAC_DMA_CH2_RX_CONTROL2_Reserved_x_10_MASK)

#define GMAC_DMA_CH2_RX_CONTROL2_ARBS_MASK       (0xFE0000U)
#define GMAC_DMA_CH2_RX_CONTROL2_ARBS_SHIFT      (17U)
#define GMAC_DMA_CH2_RX_CONTROL2_ARBS_WIDTH      (7U)
#define GMAC_DMA_CH2_RX_CONTROL2_ARBS(x)         (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_CONTROL2_ARBS_SHIFT)) & GMAC_DMA_CH2_RX_CONTROL2_ARBS_MASK)

#define GMAC_DMA_CH2_RX_CONTROL2_Reserved_31_24_MASK (0xFF000000U)
#define GMAC_DMA_CH2_RX_CONTROL2_Reserved_31_24_SHIFT (24U)
#define GMAC_DMA_CH2_RX_CONTROL2_Reserved_31_24_WIDTH (8U)
#define GMAC_DMA_CH2_RX_CONTROL2_Reserved_31_24(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_CONTROL2_Reserved_31_24_SHIFT)) & GMAC_DMA_CH2_RX_CONTROL2_Reserved_31_24_MASK)
/*! @} */

/*! @name DMA_CH2_INTERRUPT_ENABLE -  */
/*! @{ */

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_TIE_MASK   (0x1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_TIE_SHIFT  (0U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_TIE_WIDTH  (1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_TIE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_TIE_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_TIE_MASK)

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_TXSE_MASK  (0x2U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_TXSE_SHIFT (1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_TXSE_WIDTH (1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_TXSE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_TXSE_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_TXSE_MASK)

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_TBUE_MASK  (0x4U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_TBUE_SHIFT (2U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_TBUE_WIDTH (1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_TBUE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_TBUE_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_TBUE_MASK)

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_Reserved_5_3_MASK (0x38U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_Reserved_5_3_SHIFT (3U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_Reserved_5_3_WIDTH (3U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_Reserved_5_3(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_Reserved_5_3_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_Reserved_5_3_MASK)

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RIE_MASK   (0x40U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RIE_SHIFT  (6U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RIE_WIDTH  (1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RIE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_RIE_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_RIE_MASK)

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RBUE_MASK  (0x80U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RBUE_SHIFT (7U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RBUE_WIDTH (1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RBUE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_RBUE_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_RBUE_MASK)

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RSE_MASK   (0x100U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RSE_SHIFT  (8U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RSE_WIDTH  (1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RSE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_RSE_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_RSE_MASK)

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RWTE_MASK  (0x200U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RWTE_SHIFT (9U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RWTE_WIDTH (1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_RWTE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_RWTE_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_RWTE_MASK)

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_ETIE_MASK  (0x400U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_ETIE_SHIFT (10U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_ETIE_WIDTH (1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_ETIE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_ETIE_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_ETIE_MASK)

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_ERIE_MASK  (0x800U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_ERIE_SHIFT (11U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_ERIE_WIDTH (1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_ERIE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_ERIE_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_ERIE_MASK)

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_FBEE_MASK  (0x1000U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_FBEE_SHIFT (12U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_FBEE_WIDTH (1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_FBEE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_FBEE_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_FBEE_MASK)

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_CDEE_MASK  (0x2000U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_CDEE_SHIFT (13U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_CDEE_WIDTH (1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_CDEE(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_CDEE_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_CDEE_MASK)

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_AIE_MASK   (0x4000U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_AIE_SHIFT  (14U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_AIE_WIDTH  (1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_AIE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_AIE_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_AIE_MASK)

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_NIE_MASK   (0x8000U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_NIE_SHIFT  (15U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_NIE_WIDTH  (1U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_NIE(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_NIE_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_NIE_MASK)

#define GMAC_DMA_CH2_INTERRUPT_ENABLE_Reserved_31_16_MASK (0xFFFF0000U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_Reserved_31_16_SHIFT (16U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_Reserved_31_16_WIDTH (16U)
#define GMAC_DMA_CH2_INTERRUPT_ENABLE_Reserved_31_16(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_INTERRUPT_ENABLE_Reserved_31_16_SHIFT)) & GMAC_DMA_CH2_INTERRUPT_ENABLE_Reserved_31_16_MASK)
/*! @} */

/*! @name DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER -  */
/*! @{ */

#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK (0xFFU)
#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWT_SHIFT (0U)
#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWT_WIDTH (8U)
#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWT(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWT_SHIFT)) & GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWT_MASK)

#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_MASK (0xFF00U)
#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_SHIFT (8U)
#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_WIDTH (8U)
#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_SHIFT)) & GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_15_8_MASK)

#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK (0x30000U)
#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_SHIFT (16U)
#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_WIDTH (2U)
#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWTU(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_SHIFT)) & GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_RWTU_MASK)

#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_MASK (0xFFFC0000U)
#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_SHIFT (18U)
#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_WIDTH (14U)
#define GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_SHIFT)) & GMAC_DMA_CH2_RX_INTERRUPT_WATCHDOG_TIMER_Reserved_31_18_MASK)
/*! @} */

/*! @name DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS -  */
/*! @{ */

#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK (0x1U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ESC_SHIFT (0U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ESC_WIDTH (1U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ESC(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ESC_SHIFT)) & GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ESC_MASK)

#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK (0x2U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ASC_SHIFT (1U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ASC_WIDTH (1U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ASC(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ASC_SHIFT)) & GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_ASC_MASK)

#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_MASK (0xCU)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_SHIFT (2U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_WIDTH (2U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_SHIFT)) & GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_Reserved_3_2_MASK)

#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_SIV_MASK (0xFFF0U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_SIV_SHIFT (4U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_SIV_WIDTH (12U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_SIV(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_SIV_SHIFT)) & GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_SIV_MASK)

#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK (0xF0000U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_RSN_SHIFT (16U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_RSN_WIDTH (4U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_RSN(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_RSN_SHIFT)) & GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_RSN_MASK)

#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_MASK (0xFFF00000U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_SHIFT (20U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_WIDTH (12U)
#define GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_SHIFT)) & GMAC_DMA_CH2_SLOT_FUNCTION_CONTROL_STATUS_Reserved_31_20_MASK)
/*! @} */

/*! @name DMA_CH2_CURRENT_APP_TXDESC -  */
/*! @{ */

#define GMAC_DMA_CH2_CURRENT_APP_TXDESC_CURTDESAPTR_MASK (0xFFFFFFFFU)
#define GMAC_DMA_CH2_CURRENT_APP_TXDESC_CURTDESAPTR_SHIFT (0U)
#define GMAC_DMA_CH2_CURRENT_APP_TXDESC_CURTDESAPTR_WIDTH (32U)
#define GMAC_DMA_CH2_CURRENT_APP_TXDESC_CURTDESAPTR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_CURRENT_APP_TXDESC_CURTDESAPTR_SHIFT)) & GMAC_DMA_CH2_CURRENT_APP_TXDESC_CURTDESAPTR_MASK)
/*! @} */

/*! @name DMA_CH2_CURRENT_APP_RXDESC -  */
/*! @{ */

#define GMAC_DMA_CH2_CURRENT_APP_RXDESC_CURRDESAPTR_MASK (0xFFFFFFFFU)
#define GMAC_DMA_CH2_CURRENT_APP_RXDESC_CURRDESAPTR_SHIFT (0U)
#define GMAC_DMA_CH2_CURRENT_APP_RXDESC_CURRDESAPTR_WIDTH (32U)
#define GMAC_DMA_CH2_CURRENT_APP_RXDESC_CURRDESAPTR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_CURRENT_APP_RXDESC_CURRDESAPTR_SHIFT)) & GMAC_DMA_CH2_CURRENT_APP_RXDESC_CURRDESAPTR_MASK)
/*! @} */

/*! @name DMA_CH2_CURRENT_APP_TXBUFFER -  */
/*! @{ */

#define GMAC_DMA_CH2_CURRENT_APP_TXBUFFER_CURTBUFAPTR_MASK (0xFFFFFFFFU)
#define GMAC_DMA_CH2_CURRENT_APP_TXBUFFER_CURTBUFAPTR_SHIFT (0U)
#define GMAC_DMA_CH2_CURRENT_APP_TXBUFFER_CURTBUFAPTR_WIDTH (32U)
#define GMAC_DMA_CH2_CURRENT_APP_TXBUFFER_CURTBUFAPTR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_CURRENT_APP_TXBUFFER_CURTBUFAPTR_SHIFT)) & GMAC_DMA_CH2_CURRENT_APP_TXBUFFER_CURTBUFAPTR_MASK)
/*! @} */

/*! @name DMA_CH2_CURRENT_APP_RXBUFFER -  */
/*! @{ */

#define GMAC_DMA_CH2_CURRENT_APP_RXBUFFER_CURRBUFAPTR_MASK (0xFFFFFFFFU)
#define GMAC_DMA_CH2_CURRENT_APP_RXBUFFER_CURRBUFAPTR_SHIFT (0U)
#define GMAC_DMA_CH2_CURRENT_APP_RXBUFFER_CURRBUFAPTR_WIDTH (32U)
#define GMAC_DMA_CH2_CURRENT_APP_RXBUFFER_CURRBUFAPTR(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_CURRENT_APP_RXBUFFER_CURRBUFAPTR_SHIFT)) & GMAC_DMA_CH2_CURRENT_APP_RXBUFFER_CURRBUFAPTR_MASK)
/*! @} */

/*! @name DMA_CH2_STATUS -  */
/*! @{ */

#define GMAC_DMA_CH2_STATUS_TI_MASK              (0x1U)
#define GMAC_DMA_CH2_STATUS_TI_SHIFT             (0U)
#define GMAC_DMA_CH2_STATUS_TI_WIDTH             (1U)
#define GMAC_DMA_CH2_STATUS_TI(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_TI_SHIFT)) & GMAC_DMA_CH2_STATUS_TI_MASK)

#define GMAC_DMA_CH2_STATUS_TPS_MASK             (0x2U)
#define GMAC_DMA_CH2_STATUS_TPS_SHIFT            (1U)
#define GMAC_DMA_CH2_STATUS_TPS_WIDTH            (1U)
#define GMAC_DMA_CH2_STATUS_TPS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_TPS_SHIFT)) & GMAC_DMA_CH2_STATUS_TPS_MASK)

#define GMAC_DMA_CH2_STATUS_TBU_MASK             (0x4U)
#define GMAC_DMA_CH2_STATUS_TBU_SHIFT            (2U)
#define GMAC_DMA_CH2_STATUS_TBU_WIDTH            (1U)
#define GMAC_DMA_CH2_STATUS_TBU(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_TBU_SHIFT)) & GMAC_DMA_CH2_STATUS_TBU_MASK)

#define GMAC_DMA_CH2_STATUS_Reserved_5_3_MASK    (0x38U)
#define GMAC_DMA_CH2_STATUS_Reserved_5_3_SHIFT   (3U)
#define GMAC_DMA_CH2_STATUS_Reserved_5_3_WIDTH   (3U)
#define GMAC_DMA_CH2_STATUS_Reserved_5_3(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_Reserved_5_3_SHIFT)) & GMAC_DMA_CH2_STATUS_Reserved_5_3_MASK)

#define GMAC_DMA_CH2_STATUS_RI_MASK              (0x40U)
#define GMAC_DMA_CH2_STATUS_RI_SHIFT             (6U)
#define GMAC_DMA_CH2_STATUS_RI_WIDTH             (1U)
#define GMAC_DMA_CH2_STATUS_RI(x)                (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_RI_SHIFT)) & GMAC_DMA_CH2_STATUS_RI_MASK)

#define GMAC_DMA_CH2_STATUS_RBU_MASK             (0x80U)
#define GMAC_DMA_CH2_STATUS_RBU_SHIFT            (7U)
#define GMAC_DMA_CH2_STATUS_RBU_WIDTH            (1U)
#define GMAC_DMA_CH2_STATUS_RBU(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_RBU_SHIFT)) & GMAC_DMA_CH2_STATUS_RBU_MASK)

#define GMAC_DMA_CH2_STATUS_RPS_MASK             (0x100U)
#define GMAC_DMA_CH2_STATUS_RPS_SHIFT            (8U)
#define GMAC_DMA_CH2_STATUS_RPS_WIDTH            (1U)
#define GMAC_DMA_CH2_STATUS_RPS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_RPS_SHIFT)) & GMAC_DMA_CH2_STATUS_RPS_MASK)

#define GMAC_DMA_CH2_STATUS_RWT_MASK             (0x200U)
#define GMAC_DMA_CH2_STATUS_RWT_SHIFT            (9U)
#define GMAC_DMA_CH2_STATUS_RWT_WIDTH            (1U)
#define GMAC_DMA_CH2_STATUS_RWT(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_RWT_SHIFT)) & GMAC_DMA_CH2_STATUS_RWT_MASK)

#define GMAC_DMA_CH2_STATUS_ETI_MASK             (0x400U)
#define GMAC_DMA_CH2_STATUS_ETI_SHIFT            (10U)
#define GMAC_DMA_CH2_STATUS_ETI_WIDTH            (1U)
#define GMAC_DMA_CH2_STATUS_ETI(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_ETI_SHIFT)) & GMAC_DMA_CH2_STATUS_ETI_MASK)

#define GMAC_DMA_CH2_STATUS_ERI_MASK             (0x800U)
#define GMAC_DMA_CH2_STATUS_ERI_SHIFT            (11U)
#define GMAC_DMA_CH2_STATUS_ERI_WIDTH            (1U)
#define GMAC_DMA_CH2_STATUS_ERI(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_ERI_SHIFT)) & GMAC_DMA_CH2_STATUS_ERI_MASK)

#define GMAC_DMA_CH2_STATUS_FBE_MASK             (0x1000U)
#define GMAC_DMA_CH2_STATUS_FBE_SHIFT            (12U)
#define GMAC_DMA_CH2_STATUS_FBE_WIDTH            (1U)
#define GMAC_DMA_CH2_STATUS_FBE(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_FBE_SHIFT)) & GMAC_DMA_CH2_STATUS_FBE_MASK)

#define GMAC_DMA_CH2_STATUS_CDE_MASK             (0x2000U)
#define GMAC_DMA_CH2_STATUS_CDE_SHIFT            (13U)
#define GMAC_DMA_CH2_STATUS_CDE_WIDTH            (1U)
#define GMAC_DMA_CH2_STATUS_CDE(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_CDE_SHIFT)) & GMAC_DMA_CH2_STATUS_CDE_MASK)

#define GMAC_DMA_CH2_STATUS_AIS_MASK             (0x4000U)
#define GMAC_DMA_CH2_STATUS_AIS_SHIFT            (14U)
#define GMAC_DMA_CH2_STATUS_AIS_WIDTH            (1U)
#define GMAC_DMA_CH2_STATUS_AIS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_AIS_SHIFT)) & GMAC_DMA_CH2_STATUS_AIS_MASK)

#define GMAC_DMA_CH2_STATUS_NIS_MASK             (0x8000U)
#define GMAC_DMA_CH2_STATUS_NIS_SHIFT            (15U)
#define GMAC_DMA_CH2_STATUS_NIS_WIDTH            (1U)
#define GMAC_DMA_CH2_STATUS_NIS(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_NIS_SHIFT)) & GMAC_DMA_CH2_STATUS_NIS_MASK)

#define GMAC_DMA_CH2_STATUS_TEB_MASK             (0x70000U)
#define GMAC_DMA_CH2_STATUS_TEB_SHIFT            (16U)
#define GMAC_DMA_CH2_STATUS_TEB_WIDTH            (3U)
#define GMAC_DMA_CH2_STATUS_TEB(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_TEB_SHIFT)) & GMAC_DMA_CH2_STATUS_TEB_MASK)

#define GMAC_DMA_CH2_STATUS_REB_MASK             (0x380000U)
#define GMAC_DMA_CH2_STATUS_REB_SHIFT            (19U)
#define GMAC_DMA_CH2_STATUS_REB_WIDTH            (3U)
#define GMAC_DMA_CH2_STATUS_REB(x)               (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_REB_SHIFT)) & GMAC_DMA_CH2_STATUS_REB_MASK)

#define GMAC_DMA_CH2_STATUS_Reserved_31_22_MASK  (0xFFC00000U)
#define GMAC_DMA_CH2_STATUS_Reserved_31_22_SHIFT (22U)
#define GMAC_DMA_CH2_STATUS_Reserved_31_22_WIDTH (10U)
#define GMAC_DMA_CH2_STATUS_Reserved_31_22(x)    (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_STATUS_Reserved_31_22_SHIFT)) & GMAC_DMA_CH2_STATUS_Reserved_31_22_MASK)
/*! @} */

/*! @name DMA_CH2_MISS_FRAME_CNT -  */
/*! @{ */

#define GMAC_DMA_CH2_MISS_FRAME_CNT_MFC_MASK     (0x7FFU)
#define GMAC_DMA_CH2_MISS_FRAME_CNT_MFC_SHIFT    (0U)
#define GMAC_DMA_CH2_MISS_FRAME_CNT_MFC_WIDTH    (11U)
#define GMAC_DMA_CH2_MISS_FRAME_CNT_MFC(x)       (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_MISS_FRAME_CNT_MFC_SHIFT)) & GMAC_DMA_CH2_MISS_FRAME_CNT_MFC_MASK)

#define GMAC_DMA_CH2_MISS_FRAME_CNT_Reserved_14_11_MASK (0x7800U)
#define GMAC_DMA_CH2_MISS_FRAME_CNT_Reserved_14_11_SHIFT (11U)
#define GMAC_DMA_CH2_MISS_FRAME_CNT_Reserved_14_11_WIDTH (4U)
#define GMAC_DMA_CH2_MISS_FRAME_CNT_Reserved_14_11(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_MISS_FRAME_CNT_Reserved_14_11_SHIFT)) & GMAC_DMA_CH2_MISS_FRAME_CNT_Reserved_14_11_MASK)

#define GMAC_DMA_CH2_MISS_FRAME_CNT_MFCO_MASK    (0x8000U)
#define GMAC_DMA_CH2_MISS_FRAME_CNT_MFCO_SHIFT   (15U)
#define GMAC_DMA_CH2_MISS_FRAME_CNT_MFCO_WIDTH   (1U)
#define GMAC_DMA_CH2_MISS_FRAME_CNT_MFCO(x)      (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_MISS_FRAME_CNT_MFCO_SHIFT)) & GMAC_DMA_CH2_MISS_FRAME_CNT_MFCO_MASK)

#define GMAC_DMA_CH2_MISS_FRAME_CNT_Reserved_31_16_MASK (0xFFFF0000U)
#define GMAC_DMA_CH2_MISS_FRAME_CNT_Reserved_31_16_SHIFT (16U)
#define GMAC_DMA_CH2_MISS_FRAME_CNT_Reserved_31_16_WIDTH (16U)
#define GMAC_DMA_CH2_MISS_FRAME_CNT_Reserved_31_16(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_MISS_FRAME_CNT_Reserved_31_16_SHIFT)) & GMAC_DMA_CH2_MISS_FRAME_CNT_Reserved_31_16_MASK)
/*! @} */

/*! @name DMA_CH2_RXP_ACCEPT_CNT -  */
/*! @{ */

#define GMAC_DMA_CH2_RXP_ACCEPT_CNT_RXPAC_MASK   (0x7FFFFFFFU)
#define GMAC_DMA_CH2_RXP_ACCEPT_CNT_RXPAC_SHIFT  (0U)
#define GMAC_DMA_CH2_RXP_ACCEPT_CNT_RXPAC_WIDTH  (31U)
#define GMAC_DMA_CH2_RXP_ACCEPT_CNT_RXPAC(x)     (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RXP_ACCEPT_CNT_RXPAC_SHIFT)) & GMAC_DMA_CH2_RXP_ACCEPT_CNT_RXPAC_MASK)

#define GMAC_DMA_CH2_RXP_ACCEPT_CNT_RXPACOF_MASK (0x80000000U)
#define GMAC_DMA_CH2_RXP_ACCEPT_CNT_RXPACOF_SHIFT (31U)
#define GMAC_DMA_CH2_RXP_ACCEPT_CNT_RXPACOF_WIDTH (1U)
#define GMAC_DMA_CH2_RXP_ACCEPT_CNT_RXPACOF(x)   (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RXP_ACCEPT_CNT_RXPACOF_SHIFT)) & GMAC_DMA_CH2_RXP_ACCEPT_CNT_RXPACOF_MASK)
/*! @} */

/*! @name DMA_CH2_RX_ERI_CNT -  */
/*! @{ */

#define GMAC_DMA_CH2_RX_ERI_CNT_ECNT_MASK        (0xFFFU)
#define GMAC_DMA_CH2_RX_ERI_CNT_ECNT_SHIFT       (0U)
#define GMAC_DMA_CH2_RX_ERI_CNT_ECNT_WIDTH       (12U)
#define GMAC_DMA_CH2_RX_ERI_CNT_ECNT(x)          (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_ERI_CNT_ECNT_SHIFT)) & GMAC_DMA_CH2_RX_ERI_CNT_ECNT_MASK)

#define GMAC_DMA_CH2_RX_ERI_CNT_Reserved_31_12_MASK (0xFFFFF000U)
#define GMAC_DMA_CH2_RX_ERI_CNT_Reserved_31_12_SHIFT (12U)
#define GMAC_DMA_CH2_RX_ERI_CNT_Reserved_31_12_WIDTH (20U)
#define GMAC_DMA_CH2_RX_ERI_CNT_Reserved_31_12(x) (((uint32_t)(((uint32_t)(x)) << GMAC_DMA_CH2_RX_ERI_CNT_Reserved_31_12_SHIFT)) & GMAC_DMA_CH2_RX_ERI_CNT_Reserved_31_12_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group GMAC_Register_Masks */

/*!
 * @}
 */ /* end of group GMAC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K358_GMAC_H_) */
