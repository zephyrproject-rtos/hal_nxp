/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_SW_ETH_MAC_PORT0.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_SW_ETH_MAC_PORT0
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
#if !defined(S32Z2_SW_ETH_MAC_PORT0_H_)  /* Check if memory map has not been already included */
#define S32Z2_SW_ETH_MAC_PORT0_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SW_ETH_MAC_PORT0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SW_ETH_MAC_PORT0_Peripheral_Access_Layer SW_ETH_MAC_PORT0 Peripheral Access Layer
 * @{
 */

/** SW_ETH_MAC_PORT0 - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[8];
  __IO uint32_t PM0_COMMAND_CONFIG;                /**< Port MAC 0 Command and Configuration Register, offset: 0x8 */
  __I  uint32_t PM0_MAC_ADDR_0;                    /**< Port MAC 0 MAC Address Register 0, offset: 0xC */
  __I  uint32_t PM0_MAC_ADDR_1;                    /**< Port MAC 0 MAC Address Register 1, offset: 0x10 */
  __IO uint32_t PM0_MAXFRM;                        /**< Port MAC 0 Maximum Frame Length Register, offset: 0x14 */
  uint8_t RESERVED_1[40];
  __IO uint32_t PM0_IEVENT;                        /**< Port MAC 0 Interrupt Event Register, offset: 0x40 */
  uint8_t RESERVED_2[8];
  __IO uint32_t PM0_IMASK;                         /**< Port MAC 0 Interrupt Mask Register(INT_MASK), offset: 0x4C */
  uint8_t RESERVED_3[4];
  __IO uint32_t PM0_PAUSE_QUANTA;                  /**< Port MAC 0 Pause Quanta Register, offset: 0x54 */
  uint8_t RESERVED_4[12];
  __IO uint32_t PM0_PAUSE_THRESH;                  /**< Port MAC 0 Pause Quanta Threshold Register, offset: 0x64 */
  uint8_t RESERVED_5[12];
  __I  uint32_t PM0_RX_PAUSE_STATUS;               /**< Port MAC 0 Receive Pause Status Register, offset: 0x74 */
  uint8_t RESERVED_6[72];
  __IO uint32_t PM0_SINGLE_STEP;                   /**< Port MAC 0 IEEE1588 Single-Step Control Register, offset: 0xC0 */
  uint8_t RESERVED_7[12];
  __IO uint32_t PM0_HD_BACKOFF_ENTROPY;            /**< Port MAC 0 half-duplex backoff entropy register, offset: 0xD0 */
  uint8_t RESERVED_8[12];
  __IO uint32_t PM0_STATN_CONFIG;                  /**< Port MAC 0 Statistics Configuration Register, offset: 0xE0 */
  uint8_t RESERVED_9[28];
  __I  uint64_t PM0_REOCTN;                        /**< Port MAC 0 Receive Ethernet Octets Counter(etherStatsOctetsn), offset: 0x100 */
  __I  uint64_t PM0_ROCTN;                         /**< Port MAC 0 Receive Octets Counter(iflnOctetsn), offset: 0x108 */
  uint8_t RESERVED_10[8];
  __I  uint64_t PM0_RXPFN;                         /**< Port MAC 0 Receive Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn), offset: 0x118 */
  __I  uint64_t PM0_RFRMN;                         /**< Port MAC 0 Receive Frame Counter Register(aFramesReceivedOKn), offset: 0x120 */
  __I  uint64_t PM0_RFCSN;                         /**< Port MAC 0 Receive Frame Check Sequence Error Counter Register(), offset: 0x128 */
  __I  uint64_t PM0_RVLANN;                        /**< Port MAC 0 Receive VLAN Frame Counter Register(VLANReceivedOKn), offset: 0x130 */
  __I  uint64_t PM0_RERRN;                         /**< Port MAC 0 Receive Frame Error Counter Register(ifInErrorsn), offset: 0x138 */
  __I  uint64_t PM0_RUCAN;                         /**< Port MAC 0 Receive Unicast Frame Counter Register(ifInUcastPktsn), offset: 0x140 */
  __I  uint64_t PM0_RMCAN;                         /**< Port MAC 0 Receive Multicast Frame Counter Register(ifInMulticastPktsn), offset: 0x148 */
  __I  uint64_t PM0_RBCAN;                         /**< Port MAC 0 Receive Broadcast Frame Counter Register(ifInBroadcastPktsn), offset: 0x150 */
  __I  uint64_t PM0_RDRPN;                         /**< Port MAC 0 Receive Dropped Packets Counter Register(etherStatsDropEventsn), offset: 0x158 */
  __I  uint64_t PM0_RPKTN;                         /**< Port MAC 0 Receive Packets Counter Register(etherStatsPktsn), offset: 0x160 */
  __I  uint64_t PM0_RUNDN;                         /**< Port MAC 0 Receive Undersized Packet Counter Register(etherStatsUndersizePktsn), offset: 0x168 */
  __I  uint64_t PM0_R64N;                          /**< Port MAC 0 Receive 64-Octet Packet Counter Register(etherStatsPkts64OctetsN), offset: 0x170 */
  __I  uint64_t PM0_R127N;                         /**< Port MAC 0 Receive 65 to 127-Octet Packet Counter Register(etherStatsPkts65to127OctetsN), offset: 0x178 */
  __I  uint64_t PM0_R255N;                         /**< Port MAC 0 Receive 128 to 255-Octet Packet Counter Register(etherStatsPkts128to255OctetsN), offset: 0x180 */
  __I  uint64_t PM0_R511N;                         /**< Port MAC 0 Receive 256 to 511-Octet Packet Counter Register(etherStatsPkts256to511OctetsN), offset: 0x188 */
  __I  uint64_t PM0_R1023N;                        /**< Port MAC 0 Receive 512 to 1023-Octet Packet Counter Register(etherStatsPkts512to1023OctetsN), offset: 0x190 */
  __I  uint64_t PM0_R1522N;                        /**< Port MAC 0 Receive 1024 to 1522-Octet Packet Counter Register(etherStatsPkts1024to1522OctetsN), offset: 0x198 */
  __I  uint64_t PM0_R1523XN;                       /**< Port MAC 0 Receive 1523 to Max-Octet Packet Counter Register(etherStatsPkts1523toMaxOctetsN), offset: 0x1A0 */
  __I  uint64_t PM0_ROVRN;                         /**< Port MAC 0 Receive Oversized Packet Counter Register(etherStatsOversizePktsn), offset: 0x1A8 */
  __I  uint64_t PM0_RJBRN;                         /**< Port MAC 0 Receive Jabber Packet Counter Register(etherStatsJabbersn), offset: 0x1B0 */
  __I  uint64_t PM0_RFRGN;                         /**< Port MAC 0 Receive Fragment Packet Counter Register(etherStatsFragmentsn, offset: 0x1B8 */
  __I  uint64_t PM0_RCNPN;                         /**< Port MAC 0 Receive Control Packet Counter Register, offset: 0x1C0 */
  __I  uint64_t PM0_RDRNTPN;                       /**< Port MAC 0 Receive Dropped Not Truncated Packets Counter Register(etherStatsDropEventsn), offset: 0x1C8 */
  uint8_t RESERVED_11[48];
  __I  uint64_t PM0_TEOCTN;                        /**< Port MAC 0 Transmit Ethernet Octets Counter(etherStatsOctetsn), offset: 0x200 */
  __I  uint64_t PM0_TOCTN;                         /**< Port MAC 0 Transmit Octets Counter Register(ifOutOctetsn), offset: 0x208 */
  uint8_t RESERVED_12[8];
  __I  uint64_t PM0_TXPFN;                         /**< Port MAC 0 Transmit Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn), offset: 0x218 */
  __I  uint64_t PM0_TFRMN;                         /**< Port MAC 0 Transmit Frame Counter Register(aFramesTransmittedOKn), offset: 0x220 */
  __I  uint64_t PM0_TFCSN;                         /**< Port MAC 0 Transmit Frame Check Sequence Error Counter Register(), offset: 0x228 */
  __I  uint64_t PM0_TVLANN;                        /**< Port MAC 0 Transmit VLAN Frame Counter Register(VLANTransmittedOKn), offset: 0x230 */
  __I  uint64_t PM0_TERRN;                         /**< Port MAC 0 Transmit Frame Error Counter Register(ifOutErrorsn), offset: 0x238 */
  __I  uint64_t PM0_TUCAN;                         /**< Port MAC 0 Transmit Unicast Frame Counter Register(ifOutUcastPktsn), offset: 0x240 */
  __I  uint64_t PM0_TMCAN;                         /**< Port MAC 0 Transmit Multicast Frame Counter Register(ifOutMulticastPktsn), offset: 0x248 */
  __I  uint64_t PM0_TBCAN;                         /**< Port MAC 0 Transmit Broadcast Frame Counter Register(ifOutBroadcastPktsn), offset: 0x250 */
  uint8_t RESERVED_13[8];
  __I  uint64_t PM0_TPKTN;                         /**< Port MAC 0 Transmit Packets Counter Register(etherStatsPktsn), offset: 0x260 */
  __I  uint64_t PM0_TUNDN;                         /**< Port MAC 0 Transmit Undersized Packet Counter Register(etherStatsUndersizePktsn), offset: 0x268 */
  __I  uint64_t PM0_T64N;                          /**< Port MAC 0 Transmit 64-Octet Packet Counter Register (etherStatsPkts64OctetsN), offset: 0x270 */
  __I  uint64_t PM0_T127N;                         /**< Port MAC 0 Transmit 65 to 127-Octet Packet Counter Register (etherStatsPkts65to127OctetsN), offset: 0x278 */
  __I  uint64_t PM0_T255N;                         /**< Port MAC 0 Transmit 128 to 255-Octet Packet Counter Register (etherStatsPkts128to255OctetsN), offset: 0x280 */
  __I  uint64_t PM0_T511N;                         /**< Port MAC 0 Transmit 256 to 511-Octet Packet Counter Register (etherStatsPkts256to511OctetsN), offset: 0x288 */
  __I  uint64_t PM0_T1023N;                        /**< Port MAC 0 Transmit 512 to 1023-Octet Packet Counter Register (etherStatsPkts512to1023OctetsN), offset: 0x290 */
  __I  uint64_t PM0_T1522N;                        /**< Port MAC 0 Transmit 1024 to 1522-Octet Packet Counter Register (etherStatsPkts1024to1522OctetsN), offset: 0x298 */
  __I  uint64_t PM0_T1523XN;                       /**< Port MAC 0 Transmit 1523 to TX_MTU-Octet Packet Counter Register (etherStatsPkts1523toMaxOctetsN), offset: 0x2A0 */
  uint8_t RESERVED_14[24];
  __I  uint64_t PM0_TCNPN;                         /**< Port MAC 0 Transmit Control Packet Counter Register, offset: 0x2C0 */
  uint8_t RESERVED_15[8];
  __I  uint64_t PM0_TDFRN;                         /**< Port MAC 0 Transmit Deferred Packet Counter Register(aFramesWithDeferredXmissions), offset: 0x2D0 */
  __I  uint64_t PM0_TMCOLN;                        /**< Port MAC 0 Transmit Multiple Collisions Counter Register(aMultipleCollisionFrames), offset: 0x2D8 */
  __I  uint64_t PM0_TSCOLN;                        /**< Port MAC 0 Transmit Single Collision Counter(aSingleCollisionFrames) Register, offset: 0x2E0 */
  __I  uint64_t PM0_TLCOLN;                        /**< Port MAC 0 Transmit Late Collision Counter(aLateCollisions) Register, offset: 0x2E8 */
  __I  uint64_t PM0_TECOLN;                        /**< Port MAC 0 Transmit Excessive Collisions Counter Register, offset: 0x2F0 */
  uint8_t RESERVED_16[8];
  __IO uint32_t PM0_IF_MODE;                       /**< Port MAC 0 Interface Mode Control Register, offset: 0x300 */
  uint8_t RESERVED_17[260];
  __IO uint32_t PM1_COMMAND_CONFIG;                /**< Port MAC 1 Command and Configuration Register, offset: 0x408 */
  __I  uint32_t PM1_MAC_ADDR_0;                    /**< Port MAC 1 MAC Address Register 0, offset: 0x40C */
  __I  uint32_t PM1_MAC_ADDR_1;                    /**< Port MAC 1 MAC Address Register 1, offset: 0x410 */
  __IO uint32_t PM1_MAXFRM;                        /**< Port MAC 1 Maximum Frame Length Register, offset: 0x414 */
  uint8_t RESERVED_18[40];
  __IO uint32_t PM1_IEVENT;                        /**< Port MAC 1 Interrupt Event Register, offset: 0x440 */
  uint8_t RESERVED_19[8];
  __IO uint32_t PM1_IMASK;                         /**< Port MAC 1 Interrupt Mask Register(INT_MASK), offset: 0x44C */
  uint8_t RESERVED_20[4];
  __IO uint32_t PM1_PAUSE_QUANTA;                  /**< Port MAC 1 Pause Quanta Register, offset: 0x454 */
  uint8_t RESERVED_21[12];
  __IO uint32_t PM1_PAUSE_THRESH;                  /**< Port MAC 1 Pause Quanta Threshold Register, offset: 0x464 */
  uint8_t RESERVED_22[12];
  __I  uint32_t PM1_RX_PAUSE_STATUS;               /**< Port MAC 1 Receive Pause Status Register, offset: 0x474 */
  uint8_t RESERVED_23[72];
  __IO uint32_t PM1_SINGLE_STEP;                   /**< Port MAC 1 IEEE1588 Single-Step Control Register, offset: 0x4C0 */
  uint8_t RESERVED_24[12];
  __IO uint32_t PM1_HD_BACKOFF_ENTROPY;            /**< Port MAC 1 half-duplex backoff entropy register, offset: 0x4D0 */
  uint8_t RESERVED_25[12];
  __IO uint32_t PM1_STATN_CONFIG;                  /**< Port MAC 1 Statistics Configuration Register, offset: 0x4E0 */
  uint8_t RESERVED_26[28];
  __I  uint64_t PM1_REOCTN;                        /**< Port MAC 1 Receive Ethernet Octets Counter(etherStatsOctetsn), offset: 0x500 */
  __I  uint64_t PM1_ROCTN;                         /**< Port MAC 1 Receive Octets Counter(iflnOctetsn), offset: 0x508 */
  uint8_t RESERVED_27[8];
  __I  uint64_t PM1_RXPFN;                         /**< Port MAC 1 Receive Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn), offset: 0x518 */
  __I  uint64_t PM1_RFRMN;                         /**< Port MAC 1 Receive Frame Counter Register(aFramesReceivedOKn), offset: 0x520 */
  __I  uint64_t PM1_RFCSN;                         /**< Port MAC 1 Receive Frame Check Sequence Error Counter Register(), offset: 0x528 */
  __I  uint64_t PM1_RVLANN;                        /**< Port MAC 1 Receive VLAN Frame Counter Register(VLANReceivedOKn), offset: 0x530 */
  __I  uint64_t PM1_RERRN;                         /**< Port MAC 1 Receive Frame Error Counter Register(ifInErrorsn), offset: 0x538 */
  __I  uint64_t PM1_RUCAN;                         /**< Port MAC 1 Receive Unicast Frame Counter Register(ifInUcastPktsn), offset: 0x540 */
  __I  uint64_t PM1_RMCAN;                         /**< Port MAC 1 Receive Multicast Frame Counter Register(ifInMulticastPktsn), offset: 0x548 */
  __I  uint64_t PM1_RBCAN;                         /**< Port MAC 1 Receive Broadcast Frame Counter Register(ifInBroadcastPktsn), offset: 0x550 */
  __I  uint64_t PM1_RDRPN;                         /**< Port MAC 1 Receive Dropped Packets Counter Register(etherStatsDropEventsn), offset: 0x558 */
  __I  uint64_t PM1_RPKTN;                         /**< Port MAC 1 Receive Packets Counter Register(etherStatsPktsn), offset: 0x560 */
  __I  uint64_t PM1_RUNDN;                         /**< Port MAC 1 Receive Undersized Packet Counter Register(etherStatsUndersizePktsn), offset: 0x568 */
  __I  uint64_t PM1_R64N;                          /**< Port MAC 1 Receive 64-Octet Packet Counter Register(etherStatsPkts64OctetsN), offset: 0x570 */
  __I  uint64_t PM1_R127N;                         /**< Port MAC 1 Receive 65 to 127-Octet Packet Counter Register(etherStatsPkts65to127OctetsN), offset: 0x578 */
  __I  uint64_t PM1_R255N;                         /**< Port MAC 1 Receive 128 to 255-Octet Packet Counter Register(etherStatsPkts128to255OctetsN), offset: 0x580 */
  __I  uint64_t PM1_R511N;                         /**< Port MAC 1 Receive 256 to 511-Octet Packet Counter Register(etherStatsPkts256to511OctetsN), offset: 0x588 */
  __I  uint64_t PM1_R1023N;                        /**< Port MAC 1 Receive 512 to 1023-Octet Packet Counter Register(etherStatsPkts512to1023OctetsN), offset: 0x590 */
  __I  uint64_t PM1_R1522N;                        /**< Port MAC 1 Receive 1024 to 1522-Octet Packet Counter Register(etherStatsPkts1024to1522OctetsN), offset: 0x598 */
  __I  uint64_t PM1_R1523XN;                       /**< Port MAC 1 Receive 1523 to Max-Octet Packet Counter Register(etherStatsPkts1523toMaxOctetsN), offset: 0x5A0 */
  __I  uint64_t PM1_ROVRN;                         /**< Port MAC 1 Receive Oversized Packet Counter Register(etherStatsOversizePktsn), offset: 0x5A8 */
  __I  uint64_t PM1_RJBRN;                         /**< Port MAC 1 Receive Jabber Packet Counter Register(etherStatsJabbersn), offset: 0x5B0 */
  __I  uint64_t PM1_RFRGN;                         /**< Port MAC 1 Receive Fragment Packet Counter Register(etherStatsFragmentsn, offset: 0x5B8 */
  __I  uint64_t PM1_RCNPN;                         /**< Port MAC 1 Receive Control Packet Counter Register, offset: 0x5C0 */
  __I  uint64_t PM1_RDRNTPN;                       /**< Port MAC 1 Receive Dropped Not Truncated Packets Counter Register(etherStatsDropEventsn), offset: 0x5C8 */
  uint8_t RESERVED_28[48];
  __I  uint64_t PM1_TEOCTN;                        /**< Port MAC 1 Transmit Ethernet Octets Counter(etherStatsOctetsn), offset: 0x600 */
  __I  uint64_t PM1_TOCTN;                         /**< Port MAC 1 Transmit Octets Counter Register(ifOutOctetsn), offset: 0x608 */
  uint8_t RESERVED_29[8];
  __I  uint64_t PM1_TXPFN;                         /**< Port MAC 1 Transmit Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn), offset: 0x618 */
  __I  uint64_t PM1_TFRMN;                         /**< Port MAC 1 Transmit Frame Counter Register(aFramesTransmittedOKn), offset: 0x620 */
  __I  uint64_t PM1_TFCSN;                         /**< Port MAC 1 Transmit Frame Check Sequence Error Counter Register(), offset: 0x628 */
  __I  uint64_t PM1_TVLANN;                        /**< Port MAC 1 Transmit VLAN Frame Counter Register(VLANTransmittedOKn), offset: 0x630 */
  __I  uint64_t PM1_TERRN;                         /**< Port MAC 1 Transmit Frame Error Counter Register(ifOutErrorsn), offset: 0x638 */
  __I  uint64_t PM1_TUCAN;                         /**< Port MAC 1 Transmit Unicast Frame Counter Register(ifOutUcastPktsn), offset: 0x640 */
  __I  uint64_t PM1_TMCAN;                         /**< Port MAC 1 Transmit Multicast Frame Counter Register(ifOutMulticastPktsn), offset: 0x648 */
  __I  uint64_t PM1_TBCAN;                         /**< Port MAC 1 Transmit Broadcast Frame Counter Register(ifOutBroadcastPktsn), offset: 0x650 */
  uint8_t RESERVED_30[8];
  __I  uint64_t PM1_TPKTN;                         /**< Port MAC 1 Transmit Packets Counter Register(etherStatsPktsn), offset: 0x660 */
  __I  uint64_t PM1_TUNDN;                         /**< Port MAC 1 Transmit Undersized Packet Counter Register(etherStatsUndersizePktsn), offset: 0x668 */
  __I  uint64_t PM1_T64N;                          /**< Port MAC 1 Transmit 64-Octet Packet Counter Register (etherStatsPkts64OctetsN), offset: 0x670 */
  __I  uint64_t PM1_T127N;                         /**< Port MAC 1 Transmit 65 to 127-Octet Packet Counter Register (etherStatsPkts65to127OctetsN), offset: 0x678 */
  __I  uint64_t PM1_T255N;                         /**< Port MAC 1 Transmit 128 to 255-Octet Packet Counter Register (etherStatsPkts128to255OctetsN), offset: 0x680 */
  __I  uint64_t PM1_T511N;                         /**< Port MAC 1 Transmit 256 to 511-Octet Packet Counter Register (etherStatsPkts256to511OctetsN), offset: 0x688 */
  __I  uint64_t PM1_T1023N;                        /**< Port MAC 1 Transmit 512 to 1023-Octet Packet Counter Register (etherStatsPkts512to1023OctetsN), offset: 0x690 */
  __I  uint64_t PM1_T1522N;                        /**< Port MAC 1 Transmit 1024 to 1522-Octet Packet Counter Register (etherStatsPkts1024to1522OctetsN), offset: 0x698 */
  __I  uint64_t PM1_T1523XN;                       /**< Port MAC 1 Transmit 1523 to TX_MTU-Octet Packet Counter Register (etherStatsPkts1523toMaxOctetsN), offset: 0x6A0 */
  uint8_t RESERVED_31[24];
  __I  uint64_t PM1_TCNPN;                         /**< Port MAC 1 Transmit Control Packet Counter Register, offset: 0x6C0 */
  uint8_t RESERVED_32[8];
  __I  uint64_t PM1_TDFRN;                         /**< Port MAC 1 Transmit Deferred Packet Counter Register(aFramesWithDeferredXmissions), offset: 0x6D0 */
  __I  uint64_t PM1_TMCOLN;                        /**< Port MAC 1 Transmit Multiple Collisions Counter Register(aMultipleCollisionFrames), offset: 0x6D8 */
  __I  uint64_t PM1_TSCOLN;                        /**< Port MAC 1 Transmit Single Collision Counter(aSingleCollisionFrames) Register, offset: 0x6E0 */
  __I  uint64_t PM1_TLCOLN;                        /**< Port MAC 1 Transmit Late Collision Counter(aLateCollisions) Register, offset: 0x6E8 */
  __I  uint64_t PM1_TECOLN;                        /**< Port MAC 1 Transmit Excessive Collisions Counter Register, offset: 0x6F0 */
  uint8_t RESERVED_33[8];
  __IO uint32_t PM1_IF_MODE;                       /**< Port MAC 1 Interface Mode Control Register, offset: 0x700 */
  uint8_t RESERVED_34[252];
  __IO uint32_t MAC_MERGE_MMCSR;                   /**< Port MAC Merge Control and Status Register, offset: 0x800 */
  uint8_t RESERVED_35[4];
  __IO uint32_t MAC_MERGE_MMFAECR;                 /**< Port MAC Merge Frame Assembly Error Count Register, offset: 0x808 */
  __IO uint32_t MAC_MERGE_MMFSECR;                 /**< Port MAC Merge Frame SMD Error Count Register, offset: 0x80C */
  __IO uint32_t MAC_MERGE_MMFAOCR;                 /**< Port MAC Merge Frame Assembly OK Count Register, offset: 0x810 */
  __IO uint32_t MAC_MERGE_MMFCRXR;                 /**< Port MAC Merge Fragment Count RX Register, offset: 0x814 */
  __IO uint32_t MAC_MERGE_MMFCTXR;                 /**< Port MAC Merge Fragment Count TX Register, offset: 0x818 */
  __IO uint32_t MAC_MERGE_MMHCR;                   /**< Port MAC Merge Hold Count Register, offset: 0x81C */
  uint8_t RESERVED_36[992];
  __IO uint32_t PEMDIOCR;                          /**< Port external MDIO configuration register, offset: 0xC00 */
  __IO uint32_t PEMDIOICR;                         /**< Port external MDIO interface control register, offset: 0xC04 */
  __IO uint32_t PEMDIOIDR;                         /**< Port external MDIO interface data register, offset: 0xC08 */
  __IO uint32_t PEMDIORAR;                         /**< Port external MDIO register address register, offset: 0xC0C */
  __I  uint32_t PEMDIOSR;                          /**< Port external MDIO status register, offset: 0xC10 */
  uint8_t RESERVED_37[12];
  __IO uint32_t PPSCR;                             /**< PHY status configuration register, offset: 0xC20 */
  __IO uint32_t PPSCTRLR;                          /**< Port PHY status control register, offset: 0xC24 */
  __I  uint32_t PPSDR;                             /**< Port PHY status data register, offset: 0xC28 */
  __IO uint32_t PPSRAR;                            /**< Port PHY status register address register, offset: 0xC2C */
  __IO uint32_t PPSER;                             /**< Port PHY status event register, offset: 0xC30 */
  __IO uint32_t PPSMR;                             /**< Port PHY status mask register, offset: 0xC34 */
} SW_ETH_MAC_PORT0_Type, *SW_ETH_MAC_PORT0_MemMapPtr;

/** Number of instances of the SW_ETH_MAC_PORT0 module. */
#define SW_ETH_MAC_PORT0_INSTANCE_COUNT          (1u)

/* SW_ETH_MAC_PORT0 - Peripheral instance base addresses */
/** Peripheral NETC__SW0_ETH_MAC_PORT0 base address */
#define IP_NETC__SW0_ETH_MAC_PORT0_BASE          (0x74A05000u)
/** Peripheral NETC__SW0_ETH_MAC_PORT0 base pointer */
#define IP_NETC__SW0_ETH_MAC_PORT0               ((SW_ETH_MAC_PORT0_Type *)IP_NETC__SW0_ETH_MAC_PORT0_BASE)
/** Array initializer of SW_ETH_MAC_PORT0 peripheral base addresses */
#define IP_SW_ETH_MAC_PORT0_BASE_ADDRS           { IP_NETC__SW0_ETH_MAC_PORT0_BASE }
/** Array initializer of SW_ETH_MAC_PORT0 peripheral base pointers */
#define IP_SW_ETH_MAC_PORT0_BASE_PTRS            { IP_NETC__SW0_ETH_MAC_PORT0 }

/* ----------------------------------------------------------------------------
   -- SW_ETH_MAC_PORT0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SW_ETH_MAC_PORT0_Register_Masks SW_ETH_MAC_PORT0 Register Masks
 * @{
 */

/*! @name PM0_COMMAND_CONFIG - Port MAC 0 Command and Configuration Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_EN_MASK (0x1U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_EN_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_EN_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_EN_SHIFT)) & SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_EN_MASK)

#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_RX_EN_MASK (0x2U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_RX_EN_SHIFT (1U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_RX_EN_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_RX_EN_SHIFT)) & SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_RX_EN_MASK)

#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_PAUSE_FWD_MASK (0x80U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_PAUSE_FWD_SHIFT (7U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_PAUSE_FWD_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_PAUSE_FWD(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_PAUSE_FWD_SHIFT)) & SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_PAUSE_FWD_MASK)

#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_PAUSE_IGN_MASK (0x100U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_PAUSE_IGN_SHIFT (8U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_PAUSE_IGN_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_PAUSE_IGN(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_PAUSE_IGN_SHIFT)) & SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_PAUSE_IGN_MASK)

#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_ADDR_INS_MASK (0x200U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_ADDR_INS_SHIFT (9U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_ADDR_INS_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_ADDR_INS(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_ADDR_INS_SHIFT)) & SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_ADDR_INS_MASK)

#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_LOOP_ENA_MASK (0x400U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_LOOP_ENA_SHIFT (10U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_LOOP_ENA_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_LOOP_ENA(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_LOOP_ENA_SHIFT)) & SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_LOOP_ENA_MASK)

#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_CNT_FRM_EN_MASK (0x2000U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_CNT_FRM_EN_SHIFT (13U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_CNT_FRM_EN_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_CNT_FRM_EN(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_CNT_FRM_EN_SHIFT)) & SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_CNT_FRM_EN_MASK)

#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TXP_MASK (0x8000U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TXP_SHIFT (15U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TXP_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TXP(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TXP_SHIFT)) & SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TXP_MASK)

#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_FLUSH_MASK (0x400000U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_FLUSH_SHIFT (22U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_FLUSH_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_FLUSH(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_FLUSH_SHIFT)) & SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TX_FLUSH_MASK)

#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_SWR_MASK (0x4000000U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_SWR_SHIFT (26U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_SWR_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_SWR(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_SWR_SHIFT)) & SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_SWR_MASK)

#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TS_MODE_MASK (0x40000000U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TS_MODE_SHIFT (30U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TS_MODE_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TS_MODE(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TS_MODE_SHIFT)) & SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_TS_MODE_MASK)

#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_MG_MASK (0x80000000U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_MG_SHIFT (31U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_MG_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_MG(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_MG_SHIFT)) & SW_ETH_MAC_PORT0_PM0_COMMAND_CONFIG_MG_MASK)
/*! @} */

/*! @name PM0_MAC_ADDR_0 - Port MAC 0 MAC Address Register 0 */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_MAC_ADDR_0_MAC_ADDR_0_MASK (0xFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_MAC_ADDR_0_MAC_ADDR_0_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_MAC_ADDR_0_MAC_ADDR_0_WIDTH (32U)
#define SW_ETH_MAC_PORT0_PM0_MAC_ADDR_0_MAC_ADDR_0(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_MAC_ADDR_0_MAC_ADDR_0_SHIFT)) & SW_ETH_MAC_PORT0_PM0_MAC_ADDR_0_MAC_ADDR_0_MASK)
/*! @} */

/*! @name PM0_MAC_ADDR_1 - Port MAC 0 MAC Address Register 1 */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_MAC_ADDR_1_MAC_ADDR_1_MASK (0xFFFFU)
#define SW_ETH_MAC_PORT0_PM0_MAC_ADDR_1_MAC_ADDR_1_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_MAC_ADDR_1_MAC_ADDR_1_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PM0_MAC_ADDR_1_MAC_ADDR_1(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_MAC_ADDR_1_MAC_ADDR_1_SHIFT)) & SW_ETH_MAC_PORT0_PM0_MAC_ADDR_1_MAC_ADDR_1_MASK)
/*! @} */

/*! @name PM0_MAXFRM - Port MAC 0 Maximum Frame Length Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_MAXFRM_MAXFRM_MASK  (0xFFFFU)
#define SW_ETH_MAC_PORT0_PM0_MAXFRM_MAXFRM_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_MAXFRM_MAXFRM_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PM0_MAXFRM_MAXFRM(x)    (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_MAXFRM_MAXFRM_SHIFT)) & SW_ETH_MAC_PORT0_PM0_MAXFRM_MAXFRM_MASK)

#define SW_ETH_MAC_PORT0_PM0_MAXFRM_TX_MTU_MASK  (0xFFFF0000U)
#define SW_ETH_MAC_PORT0_PM0_MAXFRM_TX_MTU_SHIFT (16U)
#define SW_ETH_MAC_PORT0_PM0_MAXFRM_TX_MTU_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PM0_MAXFRM_TX_MTU(x)    (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_MAXFRM_TX_MTU_SHIFT)) & SW_ETH_MAC_PORT0_PM0_MAXFRM_TX_MTU_MASK)
/*! @} */

/*! @name PM0_IEVENT - Port MAC 0 Interrupt Event Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_IEVENT_TX_EMPTY_MASK (0x20U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_TX_EMPTY_SHIFT (5U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_TX_EMPTY_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_TX_EMPTY(x)  (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_IEVENT_TX_EMPTY_SHIFT)) & SW_ETH_MAC_PORT0_PM0_IEVENT_TX_EMPTY_MASK)

#define SW_ETH_MAC_PORT0_PM0_IEVENT_RX_EMPTY_MASK (0x40U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_RX_EMPTY_SHIFT (6U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_RX_EMPTY_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_RX_EMPTY(x)  (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_IEVENT_RX_EMPTY_SHIFT)) & SW_ETH_MAC_PORT0_PM0_IEVENT_RX_EMPTY_MASK)

#define SW_ETH_MAC_PORT0_PM0_IEVENT_TX_OVFL_MASK (0x400U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_TX_OVFL_SHIFT (10U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_TX_OVFL_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_TX_OVFL(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_IEVENT_TX_OVFL_SHIFT)) & SW_ETH_MAC_PORT0_PM0_IEVENT_TX_OVFL_MASK)

#define SW_ETH_MAC_PORT0_PM0_IEVENT_TX_UNFL_MASK (0x800U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_TX_UNFL_SHIFT (11U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_TX_UNFL_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_TX_UNFL(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_IEVENT_TX_UNFL_SHIFT)) & SW_ETH_MAC_PORT0_PM0_IEVENT_TX_UNFL_MASK)

#define SW_ETH_MAC_PORT0_PM0_IEVENT_RX_OVFL_MASK (0x1000U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_RX_OVFL_SHIFT (12U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_RX_OVFL_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_RX_OVFL(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_IEVENT_RX_OVFL_SHIFT)) & SW_ETH_MAC_PORT0_PM0_IEVENT_RX_OVFL_MASK)

#define SW_ETH_MAC_PORT0_PM0_IEVENT_MGI_MASK     (0x4000U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_MGI_SHIFT    (14U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_MGI_WIDTH    (1U)
#define SW_ETH_MAC_PORT0_PM0_IEVENT_MGI(x)       (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_IEVENT_MGI_SHIFT)) & SW_ETH_MAC_PORT0_PM0_IEVENT_MGI_MASK)
/*! @} */

/*! @name PM0_IMASK - Port MAC 0 Interrupt Mask Register(INT_MASK) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_IMASK_MGI_MASK      (0x4000U)
#define SW_ETH_MAC_PORT0_PM0_IMASK_MGI_SHIFT     (14U)
#define SW_ETH_MAC_PORT0_PM0_IMASK_MGI_WIDTH     (1U)
#define SW_ETH_MAC_PORT0_PM0_IMASK_MGI(x)        (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_IMASK_MGI_SHIFT)) & SW_ETH_MAC_PORT0_PM0_IMASK_MGI_MASK)
/*! @} */

/*! @name PM0_PAUSE_QUANTA - Port MAC 0 Pause Quanta Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_PAUSE_QUANTA_PQNT_MASK (0xFFFFU)
#define SW_ETH_MAC_PORT0_PM0_PAUSE_QUANTA_PQNT_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_PAUSE_QUANTA_PQNT_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PM0_PAUSE_QUANTA_PQNT(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_PAUSE_QUANTA_PQNT_SHIFT)) & SW_ETH_MAC_PORT0_PM0_PAUSE_QUANTA_PQNT_MASK)
/*! @} */

/*! @name PM0_PAUSE_THRESH - Port MAC 0 Pause Quanta Threshold Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_PAUSE_THRESH_QTH_MASK (0xFFFFU)
#define SW_ETH_MAC_PORT0_PM0_PAUSE_THRESH_QTH_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_PAUSE_THRESH_QTH_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PM0_PAUSE_THRESH_QTH(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_PAUSE_THRESH_QTH_SHIFT)) & SW_ETH_MAC_PORT0_PM0_PAUSE_THRESH_QTH_MASK)
/*! @} */

/*! @name PM0_RX_PAUSE_STATUS - Port MAC 0 Receive Pause Status Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RX_PAUSE_STATUS_PSTAT_MASK (0x1U)
#define SW_ETH_MAC_PORT0_PM0_RX_PAUSE_STATUS_PSTAT_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_RX_PAUSE_STATUS_PSTAT_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_RX_PAUSE_STATUS_PSTAT(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_RX_PAUSE_STATUS_PSTAT_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RX_PAUSE_STATUS_PSTAT_MASK)
/*! @} */

/*! @name PM0_SINGLE_STEP - Port MAC 0 IEEE1588 Single-Step Control Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_SINGLE_STEP_OFFSET_MASK (0x7F80U)
#define SW_ETH_MAC_PORT0_PM0_SINGLE_STEP_OFFSET_SHIFT (7U)
#define SW_ETH_MAC_PORT0_PM0_SINGLE_STEP_OFFSET_WIDTH (8U)
#define SW_ETH_MAC_PORT0_PM0_SINGLE_STEP_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_SINGLE_STEP_OFFSET_SHIFT)) & SW_ETH_MAC_PORT0_PM0_SINGLE_STEP_OFFSET_MASK)

#define SW_ETH_MAC_PORT0_PM0_SINGLE_STEP_EN_MASK (0x80000000U)
#define SW_ETH_MAC_PORT0_PM0_SINGLE_STEP_EN_SHIFT (31U)
#define SW_ETH_MAC_PORT0_PM0_SINGLE_STEP_EN_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_SINGLE_STEP_EN(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_SINGLE_STEP_EN_SHIFT)) & SW_ETH_MAC_PORT0_PM0_SINGLE_STEP_EN_MASK)
/*! @} */

/*! @name PM0_HD_BACKOFF_ENTROPY - Port MAC 0 half-duplex backoff entropy register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_HD_BACKOFF_ENTROPY_HD_BACKOFF_ENTROPY_MASK (0x3FFU)
#define SW_ETH_MAC_PORT0_PM0_HD_BACKOFF_ENTROPY_HD_BACKOFF_ENTROPY_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_HD_BACKOFF_ENTROPY_HD_BACKOFF_ENTROPY_WIDTH (10U)
#define SW_ETH_MAC_PORT0_PM0_HD_BACKOFF_ENTROPY_HD_BACKOFF_ENTROPY(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_HD_BACKOFF_ENTROPY_HD_BACKOFF_ENTROPY_SHIFT)) & SW_ETH_MAC_PORT0_PM0_HD_BACKOFF_ENTROPY_HD_BACKOFF_ENTROPY_MASK)

#define SW_ETH_MAC_PORT0_PM0_HD_BACKOFF_ENTROPY_SW_ENTROPY_VALID_MASK (0x80000000U)
#define SW_ETH_MAC_PORT0_PM0_HD_BACKOFF_ENTROPY_SW_ENTROPY_VALID_SHIFT (31U)
#define SW_ETH_MAC_PORT0_PM0_HD_BACKOFF_ENTROPY_SW_ENTROPY_VALID_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_HD_BACKOFF_ENTROPY_SW_ENTROPY_VALID(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_HD_BACKOFF_ENTROPY_SW_ENTROPY_VALID_SHIFT)) & SW_ETH_MAC_PORT0_PM0_HD_BACKOFF_ENTROPY_SW_ENTROPY_VALID_MASK)
/*! @} */

/*! @name PM0_STATN_CONFIG - Port MAC 0 Statistics Configuration Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_SAT_MASK (0x1U)
#define SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_SAT_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_SAT_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_SAT(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_SAT_SHIFT)) & SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_SAT_MASK)

#define SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_COD_MASK (0x2U)
#define SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_COD_SHIFT (1U)
#define SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_COD_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_COD(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_COD_SHIFT)) & SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_COD_MASK)

#define SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_CLR_MASK (0x4U)
#define SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_CLR_SHIFT (2U)
#define SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_CLR_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_CLR(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_CLR_SHIFT)) & SW_ETH_MAC_PORT0_PM0_STATN_CONFIG_CLR_MASK)
/*! @} */

/*! @name PM0_REOCTN - Port MAC 0 Receive Ethernet Octets Counter(etherStatsOctetsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_REOCTN_REOCTn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_REOCTN_REOCTn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_REOCTN_REOCTn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_REOCTN_REOCTn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_REOCTN_REOCTn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_REOCTN_REOCTn_MASK)
/*! @} */

/*! @name PM0_ROCTN - Port MAC 0 Receive Octets Counter(iflnOctetsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_ROCTN_ROCTn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_ROCTN_ROCTn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_ROCTN_ROCTn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_ROCTN_ROCTn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_ROCTN_ROCTn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_ROCTN_ROCTn_MASK)
/*! @} */

/*! @name PM0_RXPFN - Port MAC 0 Receive Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RXPFN_RXPFn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RXPFN_RXPFn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_RXPFN_RXPFn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_RXPFN_RXPFn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RXPFN_RXPFn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RXPFN_RXPFn_MASK)
/*! @} */

/*! @name PM0_RFRMN - Port MAC 0 Receive Frame Counter Register(aFramesReceivedOKn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RFRMN_RFRMn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RFRMN_RFRMn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_RFRMN_RFRMn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_RFRMN_RFRMn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RFRMN_RFRMn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RFRMN_RFRMn_MASK)
/*! @} */

/*! @name PM0_RFCSN - Port MAC 0 Receive Frame Check Sequence Error Counter Register() */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RFCSN_RFCSn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RFCSN_RFCSn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_RFCSN_RFCSn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_RFCSN_RFCSn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RFCSN_RFCSn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RFCSN_RFCSn_MASK)
/*! @} */

/*! @name PM0_RVLANN - Port MAC 0 Receive VLAN Frame Counter Register(VLANReceivedOKn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RVLANN_RVLANn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RVLANN_RVLANn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_RVLANN_RVLANn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_RVLANN_RVLANn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RVLANN_RVLANn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RVLANN_RVLANn_MASK)
/*! @} */

/*! @name PM0_RERRN - Port MAC 0 Receive Frame Error Counter Register(ifInErrorsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RERRN_RERRn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RERRN_RERRn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_RERRN_RERRn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_RERRN_RERRn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RERRN_RERRn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RERRN_RERRn_MASK)
/*! @} */

/*! @name PM0_RUCAN - Port MAC 0 Receive Unicast Frame Counter Register(ifInUcastPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RUCAN_RUCAn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RUCAN_RUCAn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_RUCAN_RUCAn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_RUCAN_RUCAn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RUCAN_RUCAn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RUCAN_RUCAn_MASK)
/*! @} */

/*! @name PM0_RMCAN - Port MAC 0 Receive Multicast Frame Counter Register(ifInMulticastPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RMCAN_RMCAn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RMCAN_RMCAn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_RMCAN_RMCAn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_RMCAN_RMCAn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RMCAN_RMCAn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RMCAN_RMCAn_MASK)
/*! @} */

/*! @name PM0_RBCAN - Port MAC 0 Receive Broadcast Frame Counter Register(ifInBroadcastPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RBCAN_RBCAn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RBCAN_RBCAn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_RBCAN_RBCAn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_RBCAN_RBCAn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RBCAN_RBCAn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RBCAN_RBCAn_MASK)
/*! @} */

/*! @name PM0_RDRPN - Port MAC 0 Receive Dropped Packets Counter Register(etherStatsDropEventsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RDRPN_RDRPn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RDRPN_RDRPn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_RDRPN_RDRPn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_RDRPN_RDRPn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RDRPN_RDRPn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RDRPN_RDRPn_MASK)
/*! @} */

/*! @name PM0_RPKTN - Port MAC 0 Receive Packets Counter Register(etherStatsPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RPKTN_RPKTn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RPKTN_RPKTn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_RPKTN_RPKTn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_RPKTN_RPKTn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RPKTN_RPKTn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RPKTN_RPKTn_MASK)
/*! @} */

/*! @name PM0_RUNDN - Port MAC 0 Receive Undersized Packet Counter Register(etherStatsUndersizePktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RUNDN_RUNDn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RUNDN_RUNDn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_RUNDN_RUNDn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_RUNDN_RUNDn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RUNDN_RUNDn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RUNDN_RUNDn_MASK)
/*! @} */

/*! @name PM0_R64N - Port MAC 0 Receive 64-Octet Packet Counter Register(etherStatsPkts64OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_R64N_R64n_MASK      (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_R64N_R64n_SHIFT     (0U)
#define SW_ETH_MAC_PORT0_PM0_R64N_R64n_WIDTH     (64U)
#define SW_ETH_MAC_PORT0_PM0_R64N_R64n(x)        (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_R64N_R64n_SHIFT)) & SW_ETH_MAC_PORT0_PM0_R64N_R64n_MASK)
/*! @} */

/*! @name PM0_R127N - Port MAC 0 Receive 65 to 127-Octet Packet Counter Register(etherStatsPkts65to127OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_R127N_R127n_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_R127N_R127n_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_R127N_R127n_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_R127N_R127n(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_R127N_R127n_SHIFT)) & SW_ETH_MAC_PORT0_PM0_R127N_R127n_MASK)
/*! @} */

/*! @name PM0_R255N - Port MAC 0 Receive 128 to 255-Octet Packet Counter Register(etherStatsPkts128to255OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_R255N_R255n_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_R255N_R255n_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_R255N_R255n_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_R255N_R255n(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_R255N_R255n_SHIFT)) & SW_ETH_MAC_PORT0_PM0_R255N_R255n_MASK)
/*! @} */

/*! @name PM0_R511N - Port MAC 0 Receive 256 to 511-Octet Packet Counter Register(etherStatsPkts256to511OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_R511N_R511n_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_R511N_R511n_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_R511N_R511n_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_R511N_R511n(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_R511N_R511n_SHIFT)) & SW_ETH_MAC_PORT0_PM0_R511N_R511n_MASK)
/*! @} */

/*! @name PM0_R1023N - Port MAC 0 Receive 512 to 1023-Octet Packet Counter Register(etherStatsPkts512to1023OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_R1023N_R1023n_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_R1023N_R1023n_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_R1023N_R1023n_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_R1023N_R1023n(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_R1023N_R1023n_SHIFT)) & SW_ETH_MAC_PORT0_PM0_R1023N_R1023n_MASK)
/*! @} */

/*! @name PM0_R1522N - Port MAC 0 Receive 1024 to 1522-Octet Packet Counter Register(etherStatsPkts1024to1522OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_R1522N_R1522n_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_R1522N_R1522n_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_R1522N_R1522n_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_R1522N_R1522n(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_R1522N_R1522n_SHIFT)) & SW_ETH_MAC_PORT0_PM0_R1522N_R1522n_MASK)
/*! @} */

/*! @name PM0_R1523XN - Port MAC 0 Receive 1523 to Max-Octet Packet Counter Register(etherStatsPkts1523toMaxOctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_R1523XN_R1523Xn_MASK (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_R1523XN_R1523Xn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_R1523XN_R1523Xn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_R1523XN_R1523Xn(x)  (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_R1523XN_R1523Xn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_R1523XN_R1523Xn_MASK)
/*! @} */

/*! @name PM0_ROVRN - Port MAC 0 Receive Oversized Packet Counter Register(etherStatsOversizePktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_ROVRN_ROVRn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_ROVRN_ROVRn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_ROVRN_ROVRn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_ROVRN_ROVRn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_ROVRN_ROVRn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_ROVRN_ROVRn_MASK)
/*! @} */

/*! @name PM0_RJBRN - Port MAC 0 Receive Jabber Packet Counter Register(etherStatsJabbersn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RJBRN_RJBRn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RJBRN_RJBRn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_RJBRN_RJBRn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_RJBRN_RJBRn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RJBRN_RJBRn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RJBRN_RJBRn_MASK)
/*! @} */

/*! @name PM0_RFRGN - Port MAC 0 Receive Fragment Packet Counter Register(etherStatsFragmentsn */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RFRGN_RFRGn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RFRGN_RFRGn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_RFRGN_RFRGn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_RFRGN_RFRGn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RFRGN_RFRGn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RFRGN_RFRGn_MASK)
/*! @} */

/*! @name PM0_RCNPN - Port MAC 0 Receive Control Packet Counter Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RCNPN_RCNPn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RCNPN_RCNPn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_RCNPN_RCNPn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_RCNPN_RCNPn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RCNPN_RCNPn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RCNPN_RCNPn_MASK)
/*! @} */

/*! @name PM0_RDRNTPN - Port MAC 0 Receive Dropped Not Truncated Packets Counter Register(etherStatsDropEventsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_RDRNTPN_RDRNTPn_MASK (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_RDRNTPN_RDRNTPn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_RDRNTPN_RDRNTPn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_RDRNTPN_RDRNTPn(x)  (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_RDRNTPN_RDRNTPn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_RDRNTPN_RDRNTPn_MASK)
/*! @} */

/*! @name PM0_TEOCTN - Port MAC 0 Transmit Ethernet Octets Counter(etherStatsOctetsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TEOCTN_TEOCTn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TEOCTN_TEOCTn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_TEOCTN_TEOCTn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_TEOCTN_TEOCTn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TEOCTN_TEOCTn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TEOCTN_TEOCTn_MASK)
/*! @} */

/*! @name PM0_TOCTN - Port MAC 0 Transmit Octets Counter Register(ifOutOctetsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TOCTN_TOCTn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TOCTN_TOCTn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_TOCTN_TOCTn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_TOCTN_TOCTn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TOCTN_TOCTn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TOCTN_TOCTn_MASK)
/*! @} */

/*! @name PM0_TXPFN - Port MAC 0 Transmit Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TXPFN_TXPFn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TXPFN_TXPFn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_TXPFN_TXPFn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_TXPFN_TXPFn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TXPFN_TXPFn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TXPFN_TXPFn_MASK)
/*! @} */

/*! @name PM0_TFRMN - Port MAC 0 Transmit Frame Counter Register(aFramesTransmittedOKn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TFRMN_TFRMn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TFRMN_TFRMn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_TFRMN_TFRMn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_TFRMN_TFRMn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TFRMN_TFRMn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TFRMN_TFRMn_MASK)
/*! @} */

/*! @name PM0_TFCSN - Port MAC 0 Transmit Frame Check Sequence Error Counter Register() */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TFCSN_TFCSn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TFCSN_TFCSn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_TFCSN_TFCSn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_TFCSN_TFCSn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TFCSN_TFCSn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TFCSN_TFCSn_MASK)
/*! @} */

/*! @name PM0_TVLANN - Port MAC 0 Transmit VLAN Frame Counter Register(VLANTransmittedOKn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TVLANN_TVLANn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TVLANN_TVLANn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_TVLANN_TVLANn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_TVLANN_TVLANn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TVLANN_TVLANn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TVLANN_TVLANn_MASK)
/*! @} */

/*! @name PM0_TERRN - Port MAC 0 Transmit Frame Error Counter Register(ifOutErrorsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TERRN_TERRn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TERRN_TERRn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_TERRN_TERRn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_TERRN_TERRn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TERRN_TERRn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TERRN_TERRn_MASK)
/*! @} */

/*! @name PM0_TUCAN - Port MAC 0 Transmit Unicast Frame Counter Register(ifOutUcastPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TUCAN_TUCAn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TUCAN_TUCAn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_TUCAN_TUCAn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_TUCAN_TUCAn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TUCAN_TUCAn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TUCAN_TUCAn_MASK)
/*! @} */

/*! @name PM0_TMCAN - Port MAC 0 Transmit Multicast Frame Counter Register(ifOutMulticastPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TMCAN_TMCAn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TMCAN_TMCAn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_TMCAN_TMCAn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_TMCAN_TMCAn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TMCAN_TMCAn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TMCAN_TMCAn_MASK)
/*! @} */

/*! @name PM0_TBCAN - Port MAC 0 Transmit Broadcast Frame Counter Register(ifOutBroadcastPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TBCAN_TBCAn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TBCAN_TBCAn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_TBCAN_TBCAn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_TBCAN_TBCAn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TBCAN_TBCAn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TBCAN_TBCAn_MASK)
/*! @} */

/*! @name PM0_TPKTN - Port MAC 0 Transmit Packets Counter Register(etherStatsPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TPKTN_TPKTn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TPKTN_TPKTn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_TPKTN_TPKTn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_TPKTN_TPKTn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TPKTN_TPKTn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TPKTN_TPKTn_MASK)
/*! @} */

/*! @name PM0_TUNDN - Port MAC 0 Transmit Undersized Packet Counter Register(etherStatsUndersizePktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TUNDN_TUNDn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TUNDN_TUNDn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_TUNDN_TUNDn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_TUNDN_TUNDn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TUNDN_TUNDn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TUNDN_TUNDn_MASK)
/*! @} */

/*! @name PM0_T64N - Port MAC 0 Transmit 64-Octet Packet Counter Register (etherStatsPkts64OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_T64N_T64n_MASK      (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_T64N_T64n_SHIFT     (0U)
#define SW_ETH_MAC_PORT0_PM0_T64N_T64n_WIDTH     (64U)
#define SW_ETH_MAC_PORT0_PM0_T64N_T64n(x)        (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_T64N_T64n_SHIFT)) & SW_ETH_MAC_PORT0_PM0_T64N_T64n_MASK)
/*! @} */

/*! @name PM0_T127N - Port MAC 0 Transmit 65 to 127-Octet Packet Counter Register (etherStatsPkts65to127OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_T127N_T127n_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_T127N_T127n_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_T127N_T127n_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_T127N_T127n(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_T127N_T127n_SHIFT)) & SW_ETH_MAC_PORT0_PM0_T127N_T127n_MASK)
/*! @} */

/*! @name PM0_T255N - Port MAC 0 Transmit 128 to 255-Octet Packet Counter Register (etherStatsPkts128to255OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_T255N_T255n_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_T255N_T255n_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_T255N_T255n_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_T255N_T255n(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_T255N_T255n_SHIFT)) & SW_ETH_MAC_PORT0_PM0_T255N_T255n_MASK)
/*! @} */

/*! @name PM0_T511N - Port MAC 0 Transmit 256 to 511-Octet Packet Counter Register (etherStatsPkts256to511OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_T511N_T511n_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_T511N_T511n_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_T511N_T511n_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_T511N_T511n(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_T511N_T511n_SHIFT)) & SW_ETH_MAC_PORT0_PM0_T511N_T511n_MASK)
/*! @} */

/*! @name PM0_T1023N - Port MAC 0 Transmit 512 to 1023-Octet Packet Counter Register (etherStatsPkts512to1023OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_T1023N_T1023n_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_T1023N_T1023n_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_T1023N_T1023n_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_T1023N_T1023n(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_T1023N_T1023n_SHIFT)) & SW_ETH_MAC_PORT0_PM0_T1023N_T1023n_MASK)
/*! @} */

/*! @name PM0_T1522N - Port MAC 0 Transmit 1024 to 1522-Octet Packet Counter Register (etherStatsPkts1024to1522OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_T1522N_T1522n_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_T1522N_T1522n_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_T1522N_T1522n_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_T1522N_T1522n(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_T1522N_T1522n_SHIFT)) & SW_ETH_MAC_PORT0_PM0_T1522N_T1522n_MASK)
/*! @} */

/*! @name PM0_T1523XN - Port MAC 0 Transmit 1523 to TX_MTU-Octet Packet Counter Register (etherStatsPkts1523toMaxOctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_T1523XN_T1523Xn_MASK (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_T1523XN_T1523Xn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_T1523XN_T1523Xn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_T1523XN_T1523Xn(x)  (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_T1523XN_T1523Xn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_T1523XN_T1523Xn_MASK)
/*! @} */

/*! @name PM0_TCNPN - Port MAC 0 Transmit Control Packet Counter Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TCNPN_TCNPn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TCNPN_TCNPn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_TCNPN_TCNPn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_TCNPN_TCNPn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TCNPN_TCNPn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TCNPN_TCNPn_MASK)
/*! @} */

/*! @name PM0_TDFRN - Port MAC 0 Transmit Deferred Packet Counter Register(aFramesWithDeferredXmissions) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TDFRN_TDFRn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TDFRN_TDFRn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM0_TDFRN_TDFRn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM0_TDFRN_TDFRn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TDFRN_TDFRn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TDFRN_TDFRn_MASK)
/*! @} */

/*! @name PM0_TMCOLN - Port MAC 0 Transmit Multiple Collisions Counter Register(aMultipleCollisionFrames) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TMCOLN_TMCOLn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TMCOLN_TMCOLn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_TMCOLN_TMCOLn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_TMCOLN_TMCOLn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TMCOLN_TMCOLn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TMCOLN_TMCOLn_MASK)
/*! @} */

/*! @name PM0_TSCOLN - Port MAC 0 Transmit Single Collision Counter(aSingleCollisionFrames) Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TSCOLN_TSCOLn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TSCOLN_TSCOLn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_TSCOLN_TSCOLn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_TSCOLN_TSCOLn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TSCOLN_TSCOLn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TSCOLN_TSCOLn_MASK)
/*! @} */

/*! @name PM0_TLCOLN - Port MAC 0 Transmit Late Collision Counter(aLateCollisions) Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TLCOLN_TLCOLn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TLCOLN_TLCOLn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_TLCOLN_TLCOLn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_TLCOLN_TLCOLn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TLCOLN_TLCOLn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TLCOLN_TLCOLn_MASK)
/*! @} */

/*! @name PM0_TECOLN - Port MAC 0 Transmit Excessive Collisions Counter Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_TECOLN_TECOLn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM0_TECOLN_TECOLn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_TECOLN_TECOLn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM0_TECOLN_TECOLn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM0_TECOLN_TECOLn_SHIFT)) & SW_ETH_MAC_PORT0_PM0_TECOLN_TECOLn_MASK)
/*! @} */

/*! @name PM0_IF_MODE - Port MAC 0 Interface Mode Control Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM0_IF_MODE_IFMODE_MASK (0x7U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_IFMODE_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_IFMODE_WIDTH (3U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_IFMODE(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_IF_MODE_IFMODE_SHIFT)) & SW_ETH_MAC_PORT0_PM0_IF_MODE_IFMODE_MASK)

#define SW_ETH_MAC_PORT0_PM0_IF_MODE_REVMII_MASK (0x8U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_REVMII_SHIFT (3U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_REVMII_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_REVMII(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_IF_MODE_REVMII_SHIFT)) & SW_ETH_MAC_PORT0_PM0_IF_MODE_REVMII_MASK)

#define SW_ETH_MAC_PORT0_PM0_IF_MODE_M10_MASK    (0x10U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_M10_SHIFT   (4U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_M10_WIDTH   (1U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_M10(x)      (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_IF_MODE_M10_SHIFT)) & SW_ETH_MAC_PORT0_PM0_IF_MODE_M10_MASK)

#define SW_ETH_MAC_PORT0_PM0_IF_MODE_HD_MASK     (0x40U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_HD_SHIFT    (6U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_HD_WIDTH    (1U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_HD(x)       (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_IF_MODE_HD_SHIFT)) & SW_ETH_MAC_PORT0_PM0_IF_MODE_HD_MASK)

#define SW_ETH_MAC_PORT0_PM0_IF_MODE_SSP_MASK    (0x6000U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_SSP_SHIFT   (13U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_SSP_WIDTH   (2U)
#define SW_ETH_MAC_PORT0_PM0_IF_MODE_SSP(x)      (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM0_IF_MODE_SSP_SHIFT)) & SW_ETH_MAC_PORT0_PM0_IF_MODE_SSP_MASK)
/*! @} */

/*! @name PM1_COMMAND_CONFIG - Port MAC 1 Command and Configuration Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_EN_MASK (0x1U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_EN_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_EN_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_EN_SHIFT)) & SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_EN_MASK)

#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_RX_EN_MASK (0x2U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_RX_EN_SHIFT (1U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_RX_EN_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_RX_EN_SHIFT)) & SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_RX_EN_MASK)

#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_PAUSE_FWD_MASK (0x80U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_PAUSE_FWD_SHIFT (7U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_PAUSE_FWD_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_PAUSE_FWD(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_PAUSE_FWD_SHIFT)) & SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_PAUSE_FWD_MASK)

#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_PAUSE_IGN_MASK (0x100U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_PAUSE_IGN_SHIFT (8U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_PAUSE_IGN_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_PAUSE_IGN(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_PAUSE_IGN_SHIFT)) & SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_PAUSE_IGN_MASK)

#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_ADDR_INS_MASK (0x200U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_ADDR_INS_SHIFT (9U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_ADDR_INS_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_ADDR_INS(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_ADDR_INS_SHIFT)) & SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_ADDR_INS_MASK)

#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_LOOP_ENA_MASK (0x400U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_LOOP_ENA_SHIFT (10U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_LOOP_ENA_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_LOOP_ENA(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_LOOP_ENA_SHIFT)) & SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_LOOP_ENA_MASK)

#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_CNT_FRM_EN_MASK (0x2000U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_CNT_FRM_EN_SHIFT (13U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_CNT_FRM_EN_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_CNT_FRM_EN(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_CNT_FRM_EN_SHIFT)) & SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_CNT_FRM_EN_MASK)

#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TXP_MASK (0x8000U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TXP_SHIFT (15U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TXP_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TXP(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TXP_SHIFT)) & SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TXP_MASK)

#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_FLUSH_MASK (0x400000U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_FLUSH_SHIFT (22U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_FLUSH_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_FLUSH(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_FLUSH_SHIFT)) & SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TX_FLUSH_MASK)

#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_SWR_MASK (0x4000000U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_SWR_SHIFT (26U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_SWR_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_SWR(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_SWR_SHIFT)) & SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_SWR_MASK)

#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TS_MODE_MASK (0x40000000U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TS_MODE_SHIFT (30U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TS_MODE_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TS_MODE(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TS_MODE_SHIFT)) & SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_TS_MODE_MASK)

#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_MG_MASK (0x80000000U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_MG_SHIFT (31U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_MG_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_MG(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_MG_SHIFT)) & SW_ETH_MAC_PORT0_PM1_COMMAND_CONFIG_MG_MASK)
/*! @} */

/*! @name PM1_MAC_ADDR_0 - Port MAC 1 MAC Address Register 0 */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_MAC_ADDR_0_MAC_ADDR_0_MASK (0xFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_MAC_ADDR_0_MAC_ADDR_0_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_MAC_ADDR_0_MAC_ADDR_0_WIDTH (32U)
#define SW_ETH_MAC_PORT0_PM1_MAC_ADDR_0_MAC_ADDR_0(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_MAC_ADDR_0_MAC_ADDR_0_SHIFT)) & SW_ETH_MAC_PORT0_PM1_MAC_ADDR_0_MAC_ADDR_0_MASK)
/*! @} */

/*! @name PM1_MAC_ADDR_1 - Port MAC 1 MAC Address Register 1 */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_MAC_ADDR_1_MAC_ADDR_1_MASK (0xFFFFU)
#define SW_ETH_MAC_PORT0_PM1_MAC_ADDR_1_MAC_ADDR_1_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_MAC_ADDR_1_MAC_ADDR_1_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PM1_MAC_ADDR_1_MAC_ADDR_1(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_MAC_ADDR_1_MAC_ADDR_1_SHIFT)) & SW_ETH_MAC_PORT0_PM1_MAC_ADDR_1_MAC_ADDR_1_MASK)
/*! @} */

/*! @name PM1_MAXFRM - Port MAC 1 Maximum Frame Length Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_MAXFRM_MAXFRM_MASK  (0xFFFFU)
#define SW_ETH_MAC_PORT0_PM1_MAXFRM_MAXFRM_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_MAXFRM_MAXFRM_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PM1_MAXFRM_MAXFRM(x)    (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_MAXFRM_MAXFRM_SHIFT)) & SW_ETH_MAC_PORT0_PM1_MAXFRM_MAXFRM_MASK)

#define SW_ETH_MAC_PORT0_PM1_MAXFRM_TX_MTU_MASK  (0xFFFF0000U)
#define SW_ETH_MAC_PORT0_PM1_MAXFRM_TX_MTU_SHIFT (16U)
#define SW_ETH_MAC_PORT0_PM1_MAXFRM_TX_MTU_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PM1_MAXFRM_TX_MTU(x)    (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_MAXFRM_TX_MTU_SHIFT)) & SW_ETH_MAC_PORT0_PM1_MAXFRM_TX_MTU_MASK)
/*! @} */

/*! @name PM1_IEVENT - Port MAC 1 Interrupt Event Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_IEVENT_TX_EMPTY_MASK (0x20U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_TX_EMPTY_SHIFT (5U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_TX_EMPTY_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_TX_EMPTY(x)  (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_IEVENT_TX_EMPTY_SHIFT)) & SW_ETH_MAC_PORT0_PM1_IEVENT_TX_EMPTY_MASK)

#define SW_ETH_MAC_PORT0_PM1_IEVENT_RX_EMPTY_MASK (0x40U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_RX_EMPTY_SHIFT (6U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_RX_EMPTY_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_RX_EMPTY(x)  (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_IEVENT_RX_EMPTY_SHIFT)) & SW_ETH_MAC_PORT0_PM1_IEVENT_RX_EMPTY_MASK)

#define SW_ETH_MAC_PORT0_PM1_IEVENT_TX_OVFL_MASK (0x400U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_TX_OVFL_SHIFT (10U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_TX_OVFL_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_TX_OVFL(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_IEVENT_TX_OVFL_SHIFT)) & SW_ETH_MAC_PORT0_PM1_IEVENT_TX_OVFL_MASK)

#define SW_ETH_MAC_PORT0_PM1_IEVENT_TX_UNFL_MASK (0x800U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_TX_UNFL_SHIFT (11U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_TX_UNFL_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_TX_UNFL(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_IEVENT_TX_UNFL_SHIFT)) & SW_ETH_MAC_PORT0_PM1_IEVENT_TX_UNFL_MASK)

#define SW_ETH_MAC_PORT0_PM1_IEVENT_RX_OVFL_MASK (0x1000U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_RX_OVFL_SHIFT (12U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_RX_OVFL_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_RX_OVFL(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_IEVENT_RX_OVFL_SHIFT)) & SW_ETH_MAC_PORT0_PM1_IEVENT_RX_OVFL_MASK)

#define SW_ETH_MAC_PORT0_PM1_IEVENT_MGI_MASK     (0x4000U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_MGI_SHIFT    (14U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_MGI_WIDTH    (1U)
#define SW_ETH_MAC_PORT0_PM1_IEVENT_MGI(x)       (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_IEVENT_MGI_SHIFT)) & SW_ETH_MAC_PORT0_PM1_IEVENT_MGI_MASK)
/*! @} */

/*! @name PM1_IMASK - Port MAC 1 Interrupt Mask Register(INT_MASK) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_IMASK_MGI_MASK      (0x4000U)
#define SW_ETH_MAC_PORT0_PM1_IMASK_MGI_SHIFT     (14U)
#define SW_ETH_MAC_PORT0_PM1_IMASK_MGI_WIDTH     (1U)
#define SW_ETH_MAC_PORT0_PM1_IMASK_MGI(x)        (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_IMASK_MGI_SHIFT)) & SW_ETH_MAC_PORT0_PM1_IMASK_MGI_MASK)
/*! @} */

/*! @name PM1_PAUSE_QUANTA - Port MAC 1 Pause Quanta Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_PAUSE_QUANTA_PQNT_MASK (0xFFFFU)
#define SW_ETH_MAC_PORT0_PM1_PAUSE_QUANTA_PQNT_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_PAUSE_QUANTA_PQNT_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PM1_PAUSE_QUANTA_PQNT(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_PAUSE_QUANTA_PQNT_SHIFT)) & SW_ETH_MAC_PORT0_PM1_PAUSE_QUANTA_PQNT_MASK)
/*! @} */

/*! @name PM1_PAUSE_THRESH - Port MAC 1 Pause Quanta Threshold Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_PAUSE_THRESH_QTH_MASK (0xFFFFU)
#define SW_ETH_MAC_PORT0_PM1_PAUSE_THRESH_QTH_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_PAUSE_THRESH_QTH_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PM1_PAUSE_THRESH_QTH(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_PAUSE_THRESH_QTH_SHIFT)) & SW_ETH_MAC_PORT0_PM1_PAUSE_THRESH_QTH_MASK)
/*! @} */

/*! @name PM1_RX_PAUSE_STATUS - Port MAC 1 Receive Pause Status Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RX_PAUSE_STATUS_PSTAT_MASK (0x1U)
#define SW_ETH_MAC_PORT0_PM1_RX_PAUSE_STATUS_PSTAT_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_RX_PAUSE_STATUS_PSTAT_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_RX_PAUSE_STATUS_PSTAT(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_RX_PAUSE_STATUS_PSTAT_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RX_PAUSE_STATUS_PSTAT_MASK)
/*! @} */

/*! @name PM1_SINGLE_STEP - Port MAC 1 IEEE1588 Single-Step Control Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_SINGLE_STEP_OFFSET_MASK (0x7F80U)
#define SW_ETH_MAC_PORT0_PM1_SINGLE_STEP_OFFSET_SHIFT (7U)
#define SW_ETH_MAC_PORT0_PM1_SINGLE_STEP_OFFSET_WIDTH (8U)
#define SW_ETH_MAC_PORT0_PM1_SINGLE_STEP_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_SINGLE_STEP_OFFSET_SHIFT)) & SW_ETH_MAC_PORT0_PM1_SINGLE_STEP_OFFSET_MASK)

#define SW_ETH_MAC_PORT0_PM1_SINGLE_STEP_EN_MASK (0x80000000U)
#define SW_ETH_MAC_PORT0_PM1_SINGLE_STEP_EN_SHIFT (31U)
#define SW_ETH_MAC_PORT0_PM1_SINGLE_STEP_EN_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_SINGLE_STEP_EN(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_SINGLE_STEP_EN_SHIFT)) & SW_ETH_MAC_PORT0_PM1_SINGLE_STEP_EN_MASK)
/*! @} */

/*! @name PM1_HD_BACKOFF_ENTROPY - Port MAC 1 half-duplex backoff entropy register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_HD_BACKOFF_ENTROPY_HD_BACKOFF_ENTROPY_MASK (0x3FFU)
#define SW_ETH_MAC_PORT0_PM1_HD_BACKOFF_ENTROPY_HD_BACKOFF_ENTROPY_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_HD_BACKOFF_ENTROPY_HD_BACKOFF_ENTROPY_WIDTH (10U)
#define SW_ETH_MAC_PORT0_PM1_HD_BACKOFF_ENTROPY_HD_BACKOFF_ENTROPY(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_HD_BACKOFF_ENTROPY_HD_BACKOFF_ENTROPY_SHIFT)) & SW_ETH_MAC_PORT0_PM1_HD_BACKOFF_ENTROPY_HD_BACKOFF_ENTROPY_MASK)

#define SW_ETH_MAC_PORT0_PM1_HD_BACKOFF_ENTROPY_SW_ENTROPY_VALID_MASK (0x80000000U)
#define SW_ETH_MAC_PORT0_PM1_HD_BACKOFF_ENTROPY_SW_ENTROPY_VALID_SHIFT (31U)
#define SW_ETH_MAC_PORT0_PM1_HD_BACKOFF_ENTROPY_SW_ENTROPY_VALID_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_HD_BACKOFF_ENTROPY_SW_ENTROPY_VALID(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_HD_BACKOFF_ENTROPY_SW_ENTROPY_VALID_SHIFT)) & SW_ETH_MAC_PORT0_PM1_HD_BACKOFF_ENTROPY_SW_ENTROPY_VALID_MASK)
/*! @} */

/*! @name PM1_STATN_CONFIG - Port MAC 1 Statistics Configuration Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_SAT_MASK (0x1U)
#define SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_SAT_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_SAT_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_SAT(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_SAT_SHIFT)) & SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_SAT_MASK)

#define SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_COD_MASK (0x2U)
#define SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_COD_SHIFT (1U)
#define SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_COD_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_COD(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_COD_SHIFT)) & SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_COD_MASK)

#define SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_CLR_MASK (0x4U)
#define SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_CLR_SHIFT (2U)
#define SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_CLR_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_CLR(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_CLR_SHIFT)) & SW_ETH_MAC_PORT0_PM1_STATN_CONFIG_CLR_MASK)
/*! @} */

/*! @name PM1_REOCTN - Port MAC 1 Receive Ethernet Octets Counter(etherStatsOctetsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_REOCTN_REOCTn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_REOCTN_REOCTn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_REOCTN_REOCTn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_REOCTN_REOCTn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_REOCTN_REOCTn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_REOCTN_REOCTn_MASK)
/*! @} */

/*! @name PM1_ROCTN - Port MAC 1 Receive Octets Counter(iflnOctetsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_ROCTN_ROCTn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_ROCTN_ROCTn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_ROCTN_ROCTn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_ROCTN_ROCTn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_ROCTN_ROCTn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_ROCTN_ROCTn_MASK)
/*! @} */

/*! @name PM1_RXPFN - Port MAC 1 Receive Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RXPFN_RXPFn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RXPFN_RXPFn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_RXPFN_RXPFn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_RXPFN_RXPFn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RXPFN_RXPFn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RXPFN_RXPFn_MASK)
/*! @} */

/*! @name PM1_RFRMN - Port MAC 1 Receive Frame Counter Register(aFramesReceivedOKn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RFRMN_RFRMn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RFRMN_RFRMn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_RFRMN_RFRMn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_RFRMN_RFRMn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RFRMN_RFRMn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RFRMN_RFRMn_MASK)
/*! @} */

/*! @name PM1_RFCSN - Port MAC 1 Receive Frame Check Sequence Error Counter Register() */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RFCSN_RFCSn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RFCSN_RFCSn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_RFCSN_RFCSn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_RFCSN_RFCSn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RFCSN_RFCSn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RFCSN_RFCSn_MASK)
/*! @} */

/*! @name PM1_RVLANN - Port MAC 1 Receive VLAN Frame Counter Register(VLANReceivedOKn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RVLANN_RVLANn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RVLANN_RVLANn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_RVLANN_RVLANn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_RVLANN_RVLANn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RVLANN_RVLANn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RVLANN_RVLANn_MASK)
/*! @} */

/*! @name PM1_RERRN - Port MAC 1 Receive Frame Error Counter Register(ifInErrorsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RERRN_RERRn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RERRN_RERRn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_RERRN_RERRn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_RERRN_RERRn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RERRN_RERRn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RERRN_RERRn_MASK)
/*! @} */

/*! @name PM1_RUCAN - Port MAC 1 Receive Unicast Frame Counter Register(ifInUcastPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RUCAN_RUCAn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RUCAN_RUCAn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_RUCAN_RUCAn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_RUCAN_RUCAn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RUCAN_RUCAn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RUCAN_RUCAn_MASK)
/*! @} */

/*! @name PM1_RMCAN - Port MAC 1 Receive Multicast Frame Counter Register(ifInMulticastPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RMCAN_RMCAn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RMCAN_RMCAn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_RMCAN_RMCAn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_RMCAN_RMCAn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RMCAN_RMCAn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RMCAN_RMCAn_MASK)
/*! @} */

/*! @name PM1_RBCAN - Port MAC 1 Receive Broadcast Frame Counter Register(ifInBroadcastPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RBCAN_RBCAn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RBCAN_RBCAn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_RBCAN_RBCAn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_RBCAN_RBCAn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RBCAN_RBCAn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RBCAN_RBCAn_MASK)
/*! @} */

/*! @name PM1_RDRPN - Port MAC 1 Receive Dropped Packets Counter Register(etherStatsDropEventsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RDRPN_RDRPn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RDRPN_RDRPn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_RDRPN_RDRPn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_RDRPN_RDRPn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RDRPN_RDRPn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RDRPN_RDRPn_MASK)
/*! @} */

/*! @name PM1_RPKTN - Port MAC 1 Receive Packets Counter Register(etherStatsPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RPKTN_RPKTn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RPKTN_RPKTn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_RPKTN_RPKTn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_RPKTN_RPKTn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RPKTN_RPKTn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RPKTN_RPKTn_MASK)
/*! @} */

/*! @name PM1_RUNDN - Port MAC 1 Receive Undersized Packet Counter Register(etherStatsUndersizePktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RUNDN_RUNDn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RUNDN_RUNDn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_RUNDN_RUNDn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_RUNDN_RUNDn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RUNDN_RUNDn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RUNDN_RUNDn_MASK)
/*! @} */

/*! @name PM1_R64N - Port MAC 1 Receive 64-Octet Packet Counter Register(etherStatsPkts64OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_R64N_R64n_MASK      (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_R64N_R64n_SHIFT     (0U)
#define SW_ETH_MAC_PORT0_PM1_R64N_R64n_WIDTH     (64U)
#define SW_ETH_MAC_PORT0_PM1_R64N_R64n(x)        (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_R64N_R64n_SHIFT)) & SW_ETH_MAC_PORT0_PM1_R64N_R64n_MASK)
/*! @} */

/*! @name PM1_R127N - Port MAC 1 Receive 65 to 127-Octet Packet Counter Register(etherStatsPkts65to127OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_R127N_R127n_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_R127N_R127n_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_R127N_R127n_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_R127N_R127n(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_R127N_R127n_SHIFT)) & SW_ETH_MAC_PORT0_PM1_R127N_R127n_MASK)
/*! @} */

/*! @name PM1_R255N - Port MAC 1 Receive 128 to 255-Octet Packet Counter Register(etherStatsPkts128to255OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_R255N_R255n_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_R255N_R255n_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_R255N_R255n_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_R255N_R255n(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_R255N_R255n_SHIFT)) & SW_ETH_MAC_PORT0_PM1_R255N_R255n_MASK)
/*! @} */

/*! @name PM1_R511N - Port MAC 1 Receive 256 to 511-Octet Packet Counter Register(etherStatsPkts256to511OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_R511N_R511n_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_R511N_R511n_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_R511N_R511n_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_R511N_R511n(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_R511N_R511n_SHIFT)) & SW_ETH_MAC_PORT0_PM1_R511N_R511n_MASK)
/*! @} */

/*! @name PM1_R1023N - Port MAC 1 Receive 512 to 1023-Octet Packet Counter Register(etherStatsPkts512to1023OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_R1023N_R1023n_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_R1023N_R1023n_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_R1023N_R1023n_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_R1023N_R1023n(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_R1023N_R1023n_SHIFT)) & SW_ETH_MAC_PORT0_PM1_R1023N_R1023n_MASK)
/*! @} */

/*! @name PM1_R1522N - Port MAC 1 Receive 1024 to 1522-Octet Packet Counter Register(etherStatsPkts1024to1522OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_R1522N_R1522n_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_R1522N_R1522n_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_R1522N_R1522n_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_R1522N_R1522n(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_R1522N_R1522n_SHIFT)) & SW_ETH_MAC_PORT0_PM1_R1522N_R1522n_MASK)
/*! @} */

/*! @name PM1_R1523XN - Port MAC 1 Receive 1523 to Max-Octet Packet Counter Register(etherStatsPkts1523toMaxOctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_R1523XN_R1523Xn_MASK (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_R1523XN_R1523Xn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_R1523XN_R1523Xn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_R1523XN_R1523Xn(x)  (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_R1523XN_R1523Xn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_R1523XN_R1523Xn_MASK)
/*! @} */

/*! @name PM1_ROVRN - Port MAC 1 Receive Oversized Packet Counter Register(etherStatsOversizePktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_ROVRN_ROVRn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_ROVRN_ROVRn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_ROVRN_ROVRn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_ROVRN_ROVRn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_ROVRN_ROVRn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_ROVRN_ROVRn_MASK)
/*! @} */

/*! @name PM1_RJBRN - Port MAC 1 Receive Jabber Packet Counter Register(etherStatsJabbersn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RJBRN_RJBRn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RJBRN_RJBRn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_RJBRN_RJBRn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_RJBRN_RJBRn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RJBRN_RJBRn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RJBRN_RJBRn_MASK)
/*! @} */

/*! @name PM1_RFRGN - Port MAC 1 Receive Fragment Packet Counter Register(etherStatsFragmentsn */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RFRGN_RFRGn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RFRGN_RFRGn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_RFRGN_RFRGn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_RFRGN_RFRGn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RFRGN_RFRGn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RFRGN_RFRGn_MASK)
/*! @} */

/*! @name PM1_RCNPN - Port MAC 1 Receive Control Packet Counter Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RCNPN_RCNPn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RCNPN_RCNPn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_RCNPN_RCNPn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_RCNPN_RCNPn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RCNPN_RCNPn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RCNPN_RCNPn_MASK)
/*! @} */

/*! @name PM1_RDRNTPN - Port MAC 1 Receive Dropped Not Truncated Packets Counter Register(etherStatsDropEventsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_RDRNTPN_RDRNTPn_MASK (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_RDRNTPN_RDRNTPn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_RDRNTPN_RDRNTPn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_RDRNTPN_RDRNTPn(x)  (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_RDRNTPN_RDRNTPn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_RDRNTPN_RDRNTPn_MASK)
/*! @} */

/*! @name PM1_TEOCTN - Port MAC 1 Transmit Ethernet Octets Counter(etherStatsOctetsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TEOCTN_TEOCTn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TEOCTN_TEOCTn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_TEOCTN_TEOCTn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_TEOCTN_TEOCTn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TEOCTN_TEOCTn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TEOCTN_TEOCTn_MASK)
/*! @} */

/*! @name PM1_TOCTN - Port MAC 1 Transmit Octets Counter Register(ifOutOctetsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TOCTN_TOCTn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TOCTN_TOCTn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_TOCTN_TOCTn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_TOCTN_TOCTn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TOCTN_TOCTn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TOCTN_TOCTn_MASK)
/*! @} */

/*! @name PM1_TXPFN - Port MAC 1 Transmit Valid Pause Frame Counter Register(aPAUSEMACCtrlFramesReceivedn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TXPFN_TXPFn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TXPFN_TXPFn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_TXPFN_TXPFn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_TXPFN_TXPFn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TXPFN_TXPFn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TXPFN_TXPFn_MASK)
/*! @} */

/*! @name PM1_TFRMN - Port MAC 1 Transmit Frame Counter Register(aFramesTransmittedOKn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TFRMN_TFRMn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TFRMN_TFRMn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_TFRMN_TFRMn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_TFRMN_TFRMn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TFRMN_TFRMn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TFRMN_TFRMn_MASK)
/*! @} */

/*! @name PM1_TFCSN - Port MAC 1 Transmit Frame Check Sequence Error Counter Register() */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TFCSN_TFCSn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TFCSN_TFCSn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_TFCSN_TFCSn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_TFCSN_TFCSn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TFCSN_TFCSn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TFCSN_TFCSn_MASK)
/*! @} */

/*! @name PM1_TVLANN - Port MAC 1 Transmit VLAN Frame Counter Register(VLANTransmittedOKn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TVLANN_TVLANn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TVLANN_TVLANn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_TVLANN_TVLANn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_TVLANN_TVLANn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TVLANN_TVLANn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TVLANN_TVLANn_MASK)
/*! @} */

/*! @name PM1_TERRN - Port MAC 1 Transmit Frame Error Counter Register(ifOutErrorsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TERRN_TERRn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TERRN_TERRn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_TERRN_TERRn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_TERRN_TERRn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TERRN_TERRn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TERRN_TERRn_MASK)
/*! @} */

/*! @name PM1_TUCAN - Port MAC 1 Transmit Unicast Frame Counter Register(ifOutUcastPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TUCAN_TUCAn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TUCAN_TUCAn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_TUCAN_TUCAn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_TUCAN_TUCAn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TUCAN_TUCAn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TUCAN_TUCAn_MASK)
/*! @} */

/*! @name PM1_TMCAN - Port MAC 1 Transmit Multicast Frame Counter Register(ifOutMulticastPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TMCAN_TMCAn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TMCAN_TMCAn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_TMCAN_TMCAn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_TMCAN_TMCAn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TMCAN_TMCAn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TMCAN_TMCAn_MASK)
/*! @} */

/*! @name PM1_TBCAN - Port MAC 1 Transmit Broadcast Frame Counter Register(ifOutBroadcastPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TBCAN_TBCAn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TBCAN_TBCAn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_TBCAN_TBCAn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_TBCAN_TBCAn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TBCAN_TBCAn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TBCAN_TBCAn_MASK)
/*! @} */

/*! @name PM1_TPKTN - Port MAC 1 Transmit Packets Counter Register(etherStatsPktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TPKTN_TPKTn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TPKTN_TPKTn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_TPKTN_TPKTn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_TPKTN_TPKTn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TPKTN_TPKTn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TPKTN_TPKTn_MASK)
/*! @} */

/*! @name PM1_TUNDN - Port MAC 1 Transmit Undersized Packet Counter Register(etherStatsUndersizePktsn) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TUNDN_TUNDn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TUNDN_TUNDn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_TUNDN_TUNDn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_TUNDN_TUNDn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TUNDN_TUNDn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TUNDN_TUNDn_MASK)
/*! @} */

/*! @name PM1_T64N - Port MAC 1 Transmit 64-Octet Packet Counter Register (etherStatsPkts64OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_T64N_T64n_MASK      (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_T64N_T64n_SHIFT     (0U)
#define SW_ETH_MAC_PORT0_PM1_T64N_T64n_WIDTH     (64U)
#define SW_ETH_MAC_PORT0_PM1_T64N_T64n(x)        (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_T64N_T64n_SHIFT)) & SW_ETH_MAC_PORT0_PM1_T64N_T64n_MASK)
/*! @} */

/*! @name PM1_T127N - Port MAC 1 Transmit 65 to 127-Octet Packet Counter Register (etherStatsPkts65to127OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_T127N_T127n_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_T127N_T127n_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_T127N_T127n_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_T127N_T127n(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_T127N_T127n_SHIFT)) & SW_ETH_MAC_PORT0_PM1_T127N_T127n_MASK)
/*! @} */

/*! @name PM1_T255N - Port MAC 1 Transmit 128 to 255-Octet Packet Counter Register (etherStatsPkts128to255OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_T255N_T255n_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_T255N_T255n_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_T255N_T255n_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_T255N_T255n(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_T255N_T255n_SHIFT)) & SW_ETH_MAC_PORT0_PM1_T255N_T255n_MASK)
/*! @} */

/*! @name PM1_T511N - Port MAC 1 Transmit 256 to 511-Octet Packet Counter Register (etherStatsPkts256to511OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_T511N_T511n_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_T511N_T511n_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_T511N_T511n_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_T511N_T511n(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_T511N_T511n_SHIFT)) & SW_ETH_MAC_PORT0_PM1_T511N_T511n_MASK)
/*! @} */

/*! @name PM1_T1023N - Port MAC 1 Transmit 512 to 1023-Octet Packet Counter Register (etherStatsPkts512to1023OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_T1023N_T1023n_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_T1023N_T1023n_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_T1023N_T1023n_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_T1023N_T1023n(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_T1023N_T1023n_SHIFT)) & SW_ETH_MAC_PORT0_PM1_T1023N_T1023n_MASK)
/*! @} */

/*! @name PM1_T1522N - Port MAC 1 Transmit 1024 to 1522-Octet Packet Counter Register (etherStatsPkts1024to1522OctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_T1522N_T1522n_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_T1522N_T1522n_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_T1522N_T1522n_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_T1522N_T1522n(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_T1522N_T1522n_SHIFT)) & SW_ETH_MAC_PORT0_PM1_T1522N_T1522n_MASK)
/*! @} */

/*! @name PM1_T1523XN - Port MAC 1 Transmit 1523 to TX_MTU-Octet Packet Counter Register (etherStatsPkts1523toMaxOctetsN) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_T1523XN_T1523Xn_MASK (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_T1523XN_T1523Xn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_T1523XN_T1523Xn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_T1523XN_T1523Xn(x)  (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_T1523XN_T1523Xn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_T1523XN_T1523Xn_MASK)
/*! @} */

/*! @name PM1_TCNPN - Port MAC 1 Transmit Control Packet Counter Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TCNPN_TCNPn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TCNPN_TCNPn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_TCNPN_TCNPn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_TCNPN_TCNPn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TCNPN_TCNPn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TCNPN_TCNPn_MASK)
/*! @} */

/*! @name PM1_TDFRN - Port MAC 1 Transmit Deferred Packet Counter Register(aFramesWithDeferredXmissions) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TDFRN_TDFRn_MASK    (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TDFRN_TDFRn_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PM1_TDFRN_TDFRn_WIDTH   (64U)
#define SW_ETH_MAC_PORT0_PM1_TDFRN_TDFRn(x)      (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TDFRN_TDFRn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TDFRN_TDFRn_MASK)
/*! @} */

/*! @name PM1_TMCOLN - Port MAC 1 Transmit Multiple Collisions Counter Register(aMultipleCollisionFrames) */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TMCOLN_TMCOLn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TMCOLN_TMCOLn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_TMCOLN_TMCOLn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_TMCOLN_TMCOLn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TMCOLN_TMCOLn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TMCOLN_TMCOLn_MASK)
/*! @} */

/*! @name PM1_TSCOLN - Port MAC 1 Transmit Single Collision Counter(aSingleCollisionFrames) Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TSCOLN_TSCOLn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TSCOLN_TSCOLn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_TSCOLN_TSCOLn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_TSCOLN_TSCOLn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TSCOLN_TSCOLn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TSCOLN_TSCOLn_MASK)
/*! @} */

/*! @name PM1_TLCOLN - Port MAC 1 Transmit Late Collision Counter(aLateCollisions) Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TLCOLN_TLCOLn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TLCOLN_TLCOLn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_TLCOLN_TLCOLn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_TLCOLN_TLCOLn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TLCOLN_TLCOLn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TLCOLN_TLCOLn_MASK)
/*! @} */

/*! @name PM1_TECOLN - Port MAC 1 Transmit Excessive Collisions Counter Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_TECOLN_TECOLn_MASK  (0xFFFFFFFFFFFFFFFFU)
#define SW_ETH_MAC_PORT0_PM1_TECOLN_TECOLn_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_TECOLN_TECOLn_WIDTH (64U)
#define SW_ETH_MAC_PORT0_PM1_TECOLN_TECOLn(x)    (((uint64_t)(((uint64_t)(x)) << SW_ETH_MAC_PORT0_PM1_TECOLN_TECOLn_SHIFT)) & SW_ETH_MAC_PORT0_PM1_TECOLN_TECOLn_MASK)
/*! @} */

/*! @name PM1_IF_MODE - Port MAC 1 Interface Mode Control Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PM1_IF_MODE_IFMODE_MASK (0x7U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_IFMODE_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_IFMODE_WIDTH (3U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_IFMODE(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_IF_MODE_IFMODE_SHIFT)) & SW_ETH_MAC_PORT0_PM1_IF_MODE_IFMODE_MASK)

#define SW_ETH_MAC_PORT0_PM1_IF_MODE_REVMII_MASK (0x8U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_REVMII_SHIFT (3U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_REVMII_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_REVMII(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_IF_MODE_REVMII_SHIFT)) & SW_ETH_MAC_PORT0_PM1_IF_MODE_REVMII_MASK)

#define SW_ETH_MAC_PORT0_PM1_IF_MODE_M10_MASK    (0x10U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_M10_SHIFT   (4U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_M10_WIDTH   (1U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_M10(x)      (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_IF_MODE_M10_SHIFT)) & SW_ETH_MAC_PORT0_PM1_IF_MODE_M10_MASK)

#define SW_ETH_MAC_PORT0_PM1_IF_MODE_HD_MASK     (0x40U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_HD_SHIFT    (6U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_HD_WIDTH    (1U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_HD(x)       (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_IF_MODE_HD_SHIFT)) & SW_ETH_MAC_PORT0_PM1_IF_MODE_HD_MASK)

#define SW_ETH_MAC_PORT0_PM1_IF_MODE_SSP_MASK    (0x6000U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_SSP_SHIFT   (13U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_SSP_WIDTH   (2U)
#define SW_ETH_MAC_PORT0_PM1_IF_MODE_SSP(x)      (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PM1_IF_MODE_SSP_SHIFT)) & SW_ETH_MAC_PORT0_PM1_IF_MODE_SSP_MASK)
/*! @} */

/*! @name MAC_MERGE_MMCSR - Port MAC Merge Control and Status Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPS_MASK (0x1U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPS_SHIFT (0U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPS_WIDTH (1U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPS(x)  (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPS_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPS_MASK)

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPE_MASK (0x2U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPE_SHIFT (1U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPE_WIDTH (1U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPE(x)  (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPE_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPE_MASK)

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPA_MASK (0x4U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPA_SHIFT (2U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPA_WIDTH (1U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPA(x)  (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPA_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LPA_MASK)

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LAFS_MASK (0x18U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LAFS_SHIFT (3U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LAFS_WIDTH (2U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LAFS(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LAFS_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LAFS_MASK)

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPS_MASK (0x20U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPS_SHIFT (5U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPS_WIDTH (1U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPS(x)  (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPS_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPS_MASK)

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPE_MASK (0x40U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPE_SHIFT (6U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPE_WIDTH (1U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPE(x)  (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPE_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPE_MASK)

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPA_MASK (0x80U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPA_SHIFT (7U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPA_WIDTH (1U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPA(x)  (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPA_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RPA_MASK)

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RAFS_MASK (0x300U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RAFS_SHIFT (8U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RAFS_WIDTH (2U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RAFS(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RAFS_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_RAFS_MASK)

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_ME_MASK (0x18000U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_ME_SHIFT (15U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_ME_WIDTH (2U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_ME(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_ME_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_ME_MASK)

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VDIS_MASK (0x20000U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VDIS_SHIFT (17U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VDIS_WIDTH (1U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VDIS(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VDIS_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VDIS_MASK)

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VSTS_MASK (0x1C0000U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VSTS_SHIFT (18U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VSTS_WIDTH (3U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VSTS(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VSTS_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VSTS_MASK)

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_TXSTS_MASK (0x600000U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_TXSTS_SHIFT (21U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_TXSTS_WIDTH (2U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_TXSTS(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_TXSTS_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_TXSTS_MASK)

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VT_MASK (0x3F800000U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VT_SHIFT (23U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VT_WIDTH (7U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VT(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VT_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_VT_MASK)

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LINK_FAIL_MASK (0x80000000U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LINK_FAIL_SHIFT (31U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LINK_FAIL_WIDTH (1U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LINK_FAIL(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LINK_FAIL_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMCSR_LINK_FAIL_MASK)
/*! @} */

/*! @name MAC_MERGE_MMFAECR - Port MAC Merge Frame Assembly Error Count Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFAECR_MMFAEC_MASK (0xFFFFFFFFU)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFAECR_MMFAEC_SHIFT (0U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFAECR_MMFAEC_WIDTH (32U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFAECR_MMFAEC(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMFAECR_MMFAEC_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMFAECR_MMFAEC_MASK)
/*! @} */

/*! @name MAC_MERGE_MMFSECR - Port MAC Merge Frame SMD Error Count Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFSECR_MMFSEC_MASK (0xFFFFFFFFU)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFSECR_MMFSEC_SHIFT (0U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFSECR_MMFSEC_WIDTH (32U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFSECR_MMFSEC(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMFSECR_MMFSEC_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMFSECR_MMFSEC_MASK)
/*! @} */

/*! @name MAC_MERGE_MMFAOCR - Port MAC Merge Frame Assembly OK Count Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFAOCR_MMFAOC_MASK (0xFFFFFFFFU)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFAOCR_MMFAOC_SHIFT (0U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFAOCR_MMFAOC_WIDTH (32U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFAOCR_MMFAOC(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMFAOCR_MMFAOC_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMFAOCR_MMFAOC_MASK)
/*! @} */

/*! @name MAC_MERGE_MMFCRXR - Port MAC Merge Fragment Count RX Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFCRXR_MMFCRX_MASK (0xFFFFFFFFU)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFCRXR_MMFCRX_SHIFT (0U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFCRXR_MMFCRX_WIDTH (32U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFCRXR_MMFCRX(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMFCRXR_MMFCRX_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMFCRXR_MMFCRX_MASK)
/*! @} */

/*! @name MAC_MERGE_MMFCTXR - Port MAC Merge Fragment Count TX Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFCTXR_MMFCTX_MASK (0xFFFFFFFFU)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFCTXR_MMFCTX_SHIFT (0U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFCTXR_MMFCTX_WIDTH (32U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMFCTXR_MMFCTX(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMFCTXR_MMFCTX_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMFCTXR_MMFCTX_MASK)
/*! @} */

/*! @name MAC_MERGE_MMHCR - Port MAC Merge Hold Count Register */
/*! @{ */

#define SW_ETH_MAC_PORT0_MAC_MERGE_MMHCR_MMHC_MASK (0xFFFFFFFFU)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMHCR_MMHC_SHIFT (0U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMHCR_MMHC_WIDTH (32U)
#define SW_ETH_MAC_PORT0_MAC_MERGE_MMHCR_MMHC(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_MAC_MERGE_MMHCR_MMHC_SHIFT)) & SW_ETH_MAC_PORT0_MAC_MERGE_MMHCR_MMHC_MASK)
/*! @} */

/*! @name PEMDIOCR - Port external MDIO configuration register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PEMDIOCR_BSY2_MASK      (0x1U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_BSY2_SHIFT     (0U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_BSY2_WIDTH     (1U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_BSY2(x)        (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOCR_BSY2_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOCR_BSY2_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_RD_ER_MASK (0x2U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_RD_ER_SHIFT (1U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_RD_ER_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_RD_ER(x)  (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_RD_ER_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_RD_ER_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_HOLD_MASK (0x1CU)
#define SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_HOLD_SHIFT (2U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_HOLD_WIDTH (3U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_HOLD(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_HOLD_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_HOLD_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOCR_PRE_DIS_MASK   (0x20U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_PRE_DIS_SHIFT  (5U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_PRE_DIS_WIDTH  (1U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_PRE_DIS(x)     (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOCR_PRE_DIS_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOCR_PRE_DIS_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOCR_ENC45_MASK     (0x40U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_ENC45_SHIFT    (6U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_ENC45_WIDTH    (1U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_ENC45(x)       (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOCR_ENC45_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOCR_ENC45_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_CLK_DIV_MASK (0xFF80U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_CLK_DIV_SHIFT (7U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_CLK_DIV_WIDTH (9U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_CLK_DIV(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_CLK_DIV_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOCR_MDIO_CLK_DIV_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOCR_WHOAMI_MASK    (0x70000U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_WHOAMI_SHIFT   (16U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_WHOAMI_WIDTH   (3U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_WHOAMI(x)      (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOCR_WHOAMI_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOCR_WHOAMI_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOCR_EHOLD_MASK     (0x400000U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_EHOLD_SHIFT    (22U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_EHOLD_WIDTH    (1U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_EHOLD(x)       (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOCR_EHOLD_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOCR_EHOLD_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOCR_NEG_MASK       (0x800000U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_NEG_SHIFT      (23U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_NEG_WIDTH      (1U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_NEG(x)         (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOCR_NEG_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOCR_NEG_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOCR_ADDR_ERR_MASK  (0x10000000U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_ADDR_ERR_SHIFT (28U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_ADDR_ERR_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_ADDR_ERR(x)    (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOCR_ADDR_ERR_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOCR_ADDR_ERR_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOCR_CIM_MASK       (0x20000000U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_CIM_SHIFT      (29U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_CIM_WIDTH      (1U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_CIM(x)         (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOCR_CIM_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOCR_CIM_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOCR_CMP_MASK       (0x40000000U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_CMP_SHIFT      (30U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_CMP_WIDTH      (1U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_CMP(x)         (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOCR_CMP_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOCR_CMP_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOCR_BSY1_MASK      (0x80000000U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_BSY1_SHIFT     (31U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_BSY1_WIDTH     (1U)
#define SW_ETH_MAC_PORT0_PEMDIOCR_BSY1(x)        (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOCR_BSY1_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOCR_BSY1_MASK)
/*! @} */

/*! @name PEMDIOICR - Port external MDIO interface control register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PEMDIOICR_DEV_ADDR_MASK (0x1FU)
#define SW_ETH_MAC_PORT0_PEMDIOICR_DEV_ADDR_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PEMDIOICR_DEV_ADDR_WIDTH (5U)
#define SW_ETH_MAC_PORT0_PEMDIOICR_DEV_ADDR(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOICR_DEV_ADDR_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOICR_DEV_ADDR_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOICR_PORT_ADDR_MASK (0x3E0U)
#define SW_ETH_MAC_PORT0_PEMDIOICR_PORT_ADDR_SHIFT (5U)
#define SW_ETH_MAC_PORT0_PEMDIOICR_PORT_ADDR_WIDTH (5U)
#define SW_ETH_MAC_PORT0_PEMDIOICR_PORT_ADDR(x)  (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOICR_PORT_ADDR_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOICR_PORT_ADDR_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOICR_POST_INC_MASK (0x4000U)
#define SW_ETH_MAC_PORT0_PEMDIOICR_POST_INC_SHIFT (14U)
#define SW_ETH_MAC_PORT0_PEMDIOICR_POST_INC_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PEMDIOICR_POST_INC(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOICR_POST_INC_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOICR_POST_INC_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOICR_READ_MASK     (0x8000U)
#define SW_ETH_MAC_PORT0_PEMDIOICR_READ_SHIFT    (15U)
#define SW_ETH_MAC_PORT0_PEMDIOICR_READ_WIDTH    (1U)
#define SW_ETH_MAC_PORT0_PEMDIOICR_READ(x)       (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOICR_READ_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOICR_READ_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOICR_BSY_MASK      (0x80000000U)
#define SW_ETH_MAC_PORT0_PEMDIOICR_BSY_SHIFT     (31U)
#define SW_ETH_MAC_PORT0_PEMDIOICR_BSY_WIDTH     (1U)
#define SW_ETH_MAC_PORT0_PEMDIOICR_BSY(x)        (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOICR_BSY_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOICR_BSY_MASK)
/*! @} */

/*! @name PEMDIOIDR - Port external MDIO interface data register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PEMDIOIDR_MDIO_DATA_MASK (0xFFFFU)
#define SW_ETH_MAC_PORT0_PEMDIOIDR_MDIO_DATA_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PEMDIOIDR_MDIO_DATA_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PEMDIOIDR_MDIO_DATA(x)  (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOIDR_MDIO_DATA_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOIDR_MDIO_DATA_MASK)
/*! @} */

/*! @name PEMDIORAR - Port external MDIO register address register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PEMDIORAR_REGADDR_MASK  (0xFFFFU)
#define SW_ETH_MAC_PORT0_PEMDIORAR_REGADDR_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PEMDIORAR_REGADDR_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PEMDIORAR_REGADDR(x)    (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIORAR_REGADDR_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIORAR_REGADDR_MASK)
/*! @} */

/*! @name PEMDIOSR - Port external MDIO status register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PEMDIOSR_BSY_MASK       (0x1U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_BSY_SHIFT      (0U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_BSY_WIDTH      (1U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_BSY(x)         (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOSR_BSY_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOSR_BSY_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOSR_WHT_LIST_MASK  (0x1F00U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_WHT_LIST_SHIFT (8U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_WHT_LIST_WIDTH (5U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_WHT_LIST(x)    (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOSR_WHT_LIST_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOSR_WHT_LIST_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOSR_WHT_LIST_ENA_MASK (0x8000U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_WHT_LIST_ENA_SHIFT (15U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_WHT_LIST_ENA_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_WHT_LIST_ENA(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOSR_WHT_LIST_ENA_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOSR_WHT_LIST_ENA_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOSR_PORT_ID_MASK   (0x70000U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_PORT_ID_SHIFT  (16U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_PORT_ID_WIDTH  (3U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_PORT_ID(x)     (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOSR_PORT_ID_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOSR_PORT_ID_MASK)

#define SW_ETH_MAC_PORT0_PEMDIOSR_REQ_TYPE_MASK  (0x80000U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_REQ_TYPE_SHIFT (19U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_REQ_TYPE_WIDTH (1U)
#define SW_ETH_MAC_PORT0_PEMDIOSR_REQ_TYPE(x)    (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PEMDIOSR_REQ_TYPE_SHIFT)) & SW_ETH_MAC_PORT0_PEMDIOSR_REQ_TYPE_MASK)
/*! @} */

/*! @name PPSCR - PHY status configuration register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PPSCR_BSY_MASK          (0x1U)
#define SW_ETH_MAC_PORT0_PPSCR_BSY_SHIFT         (0U)
#define SW_ETH_MAC_PORT0_PPSCR_BSY_WIDTH         (1U)
#define SW_ETH_MAC_PORT0_PPSCR_BSY(x)            (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PPSCR_BSY_SHIFT)) & SW_ETH_MAC_PORT0_PPSCR_BSY_MASK)

#define SW_ETH_MAC_PORT0_PPSCR_MDIO_RD_ER_MASK   (0x2U)
#define SW_ETH_MAC_PORT0_PPSCR_MDIO_RD_ER_SHIFT  (1U)
#define SW_ETH_MAC_PORT0_PPSCR_MDIO_RD_ER_WIDTH  (1U)
#define SW_ETH_MAC_PORT0_PPSCR_MDIO_RD_ER(x)     (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PPSCR_MDIO_RD_ER_SHIFT)) & SW_ETH_MAC_PORT0_PPSCR_MDIO_RD_ER_MASK)

#define SW_ETH_MAC_PORT0_PPSCR_STATUS_INTERVAL_MASK (0xFFFF0000U)
#define SW_ETH_MAC_PORT0_PPSCR_STATUS_INTERVAL_SHIFT (16U)
#define SW_ETH_MAC_PORT0_PPSCR_STATUS_INTERVAL_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PPSCR_STATUS_INTERVAL(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PPSCR_STATUS_INTERVAL_SHIFT)) & SW_ETH_MAC_PORT0_PPSCR_STATUS_INTERVAL_MASK)
/*! @} */

/*! @name PPSCTRLR - Port PHY status control register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PPSCTRLR_DEV_ADDR_MASK  (0x1FU)
#define SW_ETH_MAC_PORT0_PPSCTRLR_DEV_ADDR_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PPSCTRLR_DEV_ADDR_WIDTH (5U)
#define SW_ETH_MAC_PORT0_PPSCTRLR_DEV_ADDR(x)    (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PPSCTRLR_DEV_ADDR_SHIFT)) & SW_ETH_MAC_PORT0_PPSCTRLR_DEV_ADDR_MASK)

#define SW_ETH_MAC_PORT0_PPSCTRLR_PORT_ADDR_MASK (0x3E0U)
#define SW_ETH_MAC_PORT0_PPSCTRLR_PORT_ADDR_SHIFT (5U)
#define SW_ETH_MAC_PORT0_PPSCTRLR_PORT_ADDR_WIDTH (5U)
#define SW_ETH_MAC_PORT0_PPSCTRLR_PORT_ADDR(x)   (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PPSCTRLR_PORT_ADDR_SHIFT)) & SW_ETH_MAC_PORT0_PPSCTRLR_PORT_ADDR_MASK)
/*! @} */

/*! @name PPSDR - Port PHY status data register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PPSDR_MDIO_DATA_MASK    (0xFFFFU)
#define SW_ETH_MAC_PORT0_PPSDR_MDIO_DATA_SHIFT   (0U)
#define SW_ETH_MAC_PORT0_PPSDR_MDIO_DATA_WIDTH   (16U)
#define SW_ETH_MAC_PORT0_PPSDR_MDIO_DATA(x)      (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PPSDR_MDIO_DATA_SHIFT)) & SW_ETH_MAC_PORT0_PPSDR_MDIO_DATA_MASK)

#define SW_ETH_MAC_PORT0_PPSDR_CURR_CNT_MASK     (0xFFFF0000U)
#define SW_ETH_MAC_PORT0_PPSDR_CURR_CNT_SHIFT    (16U)
#define SW_ETH_MAC_PORT0_PPSDR_CURR_CNT_WIDTH    (16U)
#define SW_ETH_MAC_PORT0_PPSDR_CURR_CNT(x)       (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PPSDR_CURR_CNT_SHIFT)) & SW_ETH_MAC_PORT0_PPSDR_CURR_CNT_MASK)
/*! @} */

/*! @name PPSRAR - Port PHY status register address register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PPSRAR_REGADDR_MASK     (0xFFFFU)
#define SW_ETH_MAC_PORT0_PPSRAR_REGADDR_SHIFT    (0U)
#define SW_ETH_MAC_PORT0_PPSRAR_REGADDR_WIDTH    (16U)
#define SW_ETH_MAC_PORT0_PPSRAR_REGADDR(x)       (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PPSRAR_REGADDR_SHIFT)) & SW_ETH_MAC_PORT0_PPSRAR_REGADDR_MASK)
/*! @} */

/*! @name PPSER - Port PHY status event register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PPSER_STATUS_EVENT_HL_MASK (0xFFFFU)
#define SW_ETH_MAC_PORT0_PPSER_STATUS_EVENT_HL_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PPSER_STATUS_EVENT_HL_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PPSER_STATUS_EVENT_HL(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PPSER_STATUS_EVENT_HL_SHIFT)) & SW_ETH_MAC_PORT0_PPSER_STATUS_EVENT_HL_MASK)

#define SW_ETH_MAC_PORT0_PPSER_STATUS_EVENT_LH_MASK (0xFFFF0000U)
#define SW_ETH_MAC_PORT0_PPSER_STATUS_EVENT_LH_SHIFT (16U)
#define SW_ETH_MAC_PORT0_PPSER_STATUS_EVENT_LH_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PPSER_STATUS_EVENT_LH(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PPSER_STATUS_EVENT_LH_SHIFT)) & SW_ETH_MAC_PORT0_PPSER_STATUS_EVENT_LH_MASK)
/*! @} */

/*! @name PPSMR - Port PHY status mask register */
/*! @{ */

#define SW_ETH_MAC_PORT0_PPSMR_STATUS_MASK_HL_MASK (0xFFFFU)
#define SW_ETH_MAC_PORT0_PPSMR_STATUS_MASK_HL_SHIFT (0U)
#define SW_ETH_MAC_PORT0_PPSMR_STATUS_MASK_HL_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PPSMR_STATUS_MASK_HL(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PPSMR_STATUS_MASK_HL_SHIFT)) & SW_ETH_MAC_PORT0_PPSMR_STATUS_MASK_HL_MASK)

#define SW_ETH_MAC_PORT0_PPSMR_STATUS_MASK_LH_MASK (0xFFFF0000U)
#define SW_ETH_MAC_PORT0_PPSMR_STATUS_MASK_LH_SHIFT (16U)
#define SW_ETH_MAC_PORT0_PPSMR_STATUS_MASK_LH_WIDTH (16U)
#define SW_ETH_MAC_PORT0_PPSMR_STATUS_MASK_LH(x) (((uint32_t)(((uint32_t)(x)) << SW_ETH_MAC_PORT0_PPSMR_STATUS_MASK_LH_SHIFT)) & SW_ETH_MAC_PORT0_PPSMR_STATUS_MASK_LH_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SW_ETH_MAC_PORT0_Register_Masks */

/*!
 * @}
 */ /* end of group SW_ETH_MAC_PORT0_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_SW_ETH_MAC_PORT0_H_) */
