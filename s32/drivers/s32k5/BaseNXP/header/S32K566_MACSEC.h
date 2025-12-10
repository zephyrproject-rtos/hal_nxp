/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_MACSEC.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_MACSEC
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
#if !defined(S32K566_MACSEC_H_)  /* Check if memory map has not been already included */
#define S32K566_MACSEC_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MACSEC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MACSEC_Peripheral_Access_Layer MACSEC Peripheral Access Layer
 * @{
 */

/** MACSEC - Size of Registers Arrays */
#define MACSEC_MACSEC_RXANINUSS_COUNT             4u
#define MACSEC_MACSEC_RXANIPUSS_COUNT             4u

/** MACSEC - Register Layout Typedef */
typedef struct MACSEC_Struct {
  __IO uint32_t MACSEC_CFG;                        /**< MACsec configuration, offset: 0x0 */
  __IO uint32_t MACSEC_ET;                         /**< MACsec EtherType, offset: 0x4 */
  __IO uint32_t MACSEC_CTPID1;                     /**< MACsec Configured TPID1, offset: 0x8 */
  __IO uint32_t MACSEC_CTPID2;                     /**< MACsec Configured TPID2, offset: 0xC */
  __IO uint32_t MACSEC_VCLCTR;                     /**< MACsec VLAN Classification Control, offset: 0x10 */
  uint8_t RESERVED_0[44];
  __IO uint32_t MACSEC_MFL;                        /**< Maximum Frame Length, offset: 0x40 */
  __IO uint32_t MACSEC_TPNET;                      /**< TX Packet Number exhaustion threshold, offset: 0x44 */
  uint8_t RESERVED_1[56];
  __IO uint32_t MACSEC_RXSCA;                      /**< RX SC access select, offset: 0x80 */
  uint8_t RESERVED_2[60];
  __IO uint32_t MACSEC_TXSCA;                      /**< TX SC access select, offset: 0xC0 */
  uint8_t RESERVED_3[60];
  __IO uint32_t MACSEC_RXSCI1H;                    /**< RX Secure Channel Identifier first half, offset: 0x100 */
  __IO uint32_t MACSEC_RXSCI2H;                    /**< RX Secure Channel Identifier second half, offset: 0x104 */
  uint8_t RESERVED_4[8];
  __IO uint32_t MACSEC_IFIO1HS;                    /**< ifInOctets first half Statistic, offset: 0x110 */
  __IO uint32_t MACSEC_IFIO2HS;                    /**< ifInOctets second half Statistic, offset: 0x114 */
  __IO uint32_t MACSEC_IFIUPS;                     /**< ifInUcastPkts Statistic, offset: 0x118 */
  uint8_t RESERVED_5[4];
  __IO uint32_t MACSEC_IFIMPS;                     /**< ifInMulticastPkts Statistic, offset: 0x120 */
  __IO uint32_t MACSEC_IFIBPS;                     /**< ifInBroadcastPkts Statistic, offset: 0x124 */
  __IO uint32_t MACSEC_RXSCCFG;                    /**< RX Secure Channel configuration, offset: 0x128 */
  __IO uint32_t MACSEC_RPW;                        /**< replayWindow, offset: 0x12C */
  uint8_t RESERVED_6[16];
  __IO uint32_t MACSEC_INOV1HS;                    /**< InOctetsValidated first half Statistic, offset: 0x140 */
  __IO uint32_t MACSEC_INOV2HS;                    /**< InOctetsValidated second half Statistic, offset: 0x144 */
  __IO uint32_t MACSEC_INOD1HS;                    /**< InOctetsDecrypted first half Statistic, offset: 0x148 */
  __IO uint32_t MACSEC_INOD2HS;                    /**< InOctetsDecrypted second half Statistic, offset: 0x14C */
  __IO uint32_t MACSEC_RXSCIPUS;                   /**< RX Secure Channel InPktsUnchecked Statistic, offset: 0x150 */
  __IO uint32_t MACSEC_RXSCIPDS;                   /**< RX Secure Channel InPktsDelayed Statistic, offset: 0x154 */
  __IO uint32_t MACSEC_RXSCIPLS;                   /**< RX Secure Channel InPktsLate Statistic, offset: 0x158 */
  uint8_t RESERVED_7[4];
  __IO uint32_t MACSEC_RXANINUSS[MACSEC_MACSEC_RXANINUSS_COUNT]; /**< RX AN 0 InNotUsingSA Statistic..RX AN 3 InNotUsingSA Statistic, array offset: 0x160, array step: 0x4 */
  __IO uint32_t MACSEC_RXANIPUSS[MACSEC_MACSEC_RXANIPUSS_COUNT]; /**< RX AN 0 InPktsUnusedSA Statistic..RX AN 3 InPktsUnusedSA Statistic, array offset: 0x170, array step: 0x4 */
  __IO uint32_t MACSEC_RXSAACS;                    /**< RX Security Association A configuration and status, offset: 0x180 */
  __IO uint32_t MACSEC_RXSAANPN;                   /**< RX Security Association A nextPN, offset: 0x184 */
  __IO uint32_t MACSEC_RXSAAXNPN;                  /**< RX Security Association Extended A nextPN, offset: 0x188 */
  __IO uint32_t MACSEC_RXSAALPN;                   /**< RX Security Association A lowestPN, offset: 0x18C */
  __IO uint32_t MACSEC_RXSAAXLPN;                  /**< RX Security Association Extended A lowestPN, offset: 0x190 */
  __IO uint32_t MACSEC_RXSAAIPOS;                  /**< RX Security Association A InPktsOK Statistic, offset: 0x194 */
  uint8_t RESERVED_8[24];
  __IO uint32_t MACSEC_RXSAAIPIS;                  /**< RX Security Association A InPktsInvalid Statistic, offset: 0x1B0 */
  __IO uint32_t MACSEC_RXSAAIPNVS;                 /**< RX Security Association A InPktsNotValid Statistic, offset: 0x1B4 */
  uint8_t RESERVED_9[8];
  __IO uint32_t MACSEC_RXSABCS;                    /**< RX Security Association B configuration and status, offset: 0x1C0 */
  __IO uint32_t MACSEC_RXSABNPN;                   /**< RX Security Association B nextPN, offset: 0x1C4 */
  __IO uint32_t MACSEC_RXSABXNPN;                  /**< RX Security Association Extended B nextPN, offset: 0x1C8 */
  __IO uint32_t MACSEC_RXSABLPN;                   /**< RX Security Association B lowestPN, offset: 0x1CC */
  __IO uint32_t MACSEC_RXSABXLPN;                  /**< RX Security Association Extended B lowestPN, offset: 0x1D0 */
  __IO uint32_t MACSEC_RXSABIPOS;                  /**< RX Security Association B InPktsOK Statistic, offset: 0x1D4 */
  uint8_t RESERVED_10[24];
  __IO uint32_t MACSEC_RXSABIPIS;                  /**< RX Security Association B InPktsInvalid Statistic, offset: 0x1F0 */
  __IO uint32_t MACSEC_RXSABIPNVS;                 /**< RX Security Association B InPktsNotValid Statistic, offset: 0x1F4 */
  uint8_t RESERVED_11[8];
  __IO uint32_t MACSEC_TXSCI1H;                    /**< TX Secure Channel Identifier first half, offset: 0x200 */
  __IO uint32_t MACSEC_TXSCI2H;                    /**< TX Secure Channel Identifier second half, offset: 0x204 */
  uint8_t RESERVED_12[8];
  __IO uint32_t MACSEC_IFOO1HS;                    /**< ifOutOctets first half Statistic, offset: 0x210 */
  __IO uint32_t MACSEC_IFOO2HS;                    /**< ifOutOctets second half Statistic, offset: 0x214 */
  __IO uint32_t MACSEC_IFOUPS;                     /**< ifOutUcastPkts Statistic, offset: 0x218 */
  __IO uint32_t MACSEC_OPUS;                       /**< OutPktsUntagged Statistic, offset: 0x21C */
  __IO uint32_t MACSEC_IFOMPS;                     /**< ifOutMulticastPkts Statistic, offset: 0x220 */
  __IO uint32_t MACSEC_IFOBPS;                     /**< ifOutBroadcastPkts Statistic, offset: 0x224 */
  __IO uint32_t MACSEC_TXSCCFG;                    /**< TX Secure Channel configuration, offset: 0x228 */
  __IO uint32_t MACSEC_OPTLS;                      /**< OutPktsTooLong Statistic, offset: 0x22C */
  uint8_t RESERVED_13[16];
  __IO uint32_t MACSEC_OOP1HS;                     /**< OutOctetsProtected first half Statistic, offset: 0x240 */
  __IO uint32_t MACSEC_OOP2HS;                     /**< OutOctetsProtected second half Statistic, offset: 0x244 */
  __IO uint32_t MACSEC_OOE1HS;                     /**< OutOctetsEncrypted first half Statistic, offset: 0x248 */
  __IO uint32_t MACSEC_OOE2HS;                     /**< OutOctetsEncrypted second half Statistic, offset: 0x24C */
  uint8_t RESERVED_14[48];
  __IO uint32_t MACSEC_TXSAACS;                    /**< TX Security Association A configuration and status, offset: 0x280 */
  __IO uint32_t MACSEC_TXSAANPN;                   /**< TX Security Association A nextPN, offset: 0x284 */
  __IO uint32_t MACSEC_TXSAAXNPN;                  /**< TX Security Association Extended A nextPN, offset: 0x288 */
  __IO uint32_t MACSEC_TXSAAOPPS;                  /**< TX Security Association A OutPktsProtected Statistic, offset: 0x28C */
  __IO uint32_t MACSEC_TXSAAOPES;                  /**< TX Security Association A OutPktsEncrypted Statistic, offset: 0x290 */
  uint8_t RESERVED_15[44];
  __IO uint32_t MACSEC_TXSABCS;                    /**< TX Security Association B configuration and status, offset: 0x2C0 */
  __IO uint32_t MACSEC_TXSABNPN;                   /**< TX Security Association B nextPN, offset: 0x2C4 */
  __IO uint32_t MACSEC_TXSABXNPN;                  /**< TX Security Association Extended B nextPN, offset: 0x2C8 */
  __IO uint32_t MACSEC_TXSABOPPS;                  /**< TX Security Association B OutPktsProtected Statistic, offset: 0x2CC */
  __IO uint32_t MACSEC_TXSABOPES;                  /**< TX Security Association B OutPktsEncrypted Statistic, offset: 0x2D0 */
  uint8_t RESERVED_16[292];
  __I  uint32_t MACSEC_IP_REV_1;                   /**< MACsec IP Block Revision 1 register, offset: 0x3F8 */
  __I  uint32_t MACSEC_IP_REV_2;                   /**< MACsec IP Block Revision 2 register, offset: 0x3FC */
  __IO uint32_t MACSEC_EVR;                        /**< MACsec Event Register, offset: 0x400 */
  __IO uint32_t MACSEC_EVER;                       /**< MACsec Event Enable Register, offset: 0x404 */
  uint8_t RESERVED_17[4];
  __IO uint32_t MACSEC_ERR;                        /**< MACsec Error Register, offset: 0x40C */
  __IO uint32_t MACSEC_ERER;                       /**< MACsec Error Enable Register, offset: 0x410 */
  uint8_t RESERVED_18[44];
  __IO uint32_t MACSEC_MEEC;                       /**< MACsec Memory ECC Error Capture Register, offset: 0x440 */
  __I  uint32_t MACSEC_STATUS;                     /**< MACsec Idle status Register, offset: 0x444 */
  uint8_t RESERVED_19[440];
  __IO uint32_t MACSEC_IFIOCP1HS;                  /**< ifInOctetsCp first half Statistic, offset: 0x600 */
  __IO uint32_t MACSEC_IFIOCP2HS;                  /**< ifInOctetsCp second half Statistic, offset: 0x604 */
  __IO uint32_t MACSEC_IFIUPCPS;                   /**< ifInUcastPktsCp Statistic, offset: 0x608 */
  uint8_t RESERVED_20[4];
  __IO uint32_t MACSEC_IFIOUP1HS;                  /**< ifInOctetsUp first half Statistic, offset: 0x610 */
  __IO uint32_t MACSEC_IFIOUP2HS;                  /**< ifInOctetsUp second half Statistic, offset: 0x614 */
  __IO uint32_t MACSEC_IFIUPUPS;                   /**< ifInUcastPktsUp Statistic, offset: 0x618 */
  uint8_t RESERVED_21[4];
  __IO uint32_t MACSEC_IFIMPCPS;                   /**< ifInMulticastPktsCp Statistic, offset: 0x620 */
  __IO uint32_t MACSEC_IFIBPCPS;                   /**< ifInBroadcastPktsCp Statistic, offset: 0x624 */
  __IO uint32_t MACSEC_IFIMPUPS;                   /**< ifInMulticastPktsUp Statistic, offset: 0x628 */
  __IO uint32_t MACSEC_IFIBPUPS;                   /**< ifInBroadcastPktsUp Statistic, offset: 0x62C */
  __IO uint32_t MACSEC_INPWTS;                     /**< InPktsWithoutTag Statistic, offset: 0x630 */
  __IO uint32_t MACSEC_INPKAYS;                    /**< InPktsKaY Statistic, offset: 0x634 */
  __IO uint32_t MACSEC_INPBTS;                     /**< InPktsBadTag Statistic, offset: 0x638 */
  __IO uint32_t MACSEC_IPSNFS;                     /**< InPktsSCINotFound Statistic, offset: 0x63C */
  __IO uint32_t MACSEC_IPUECS;                     /**< InPktsUnsupportedEC Statistic, offset: 0x640 */
  __IO uint32_t MACSEC_IPESCBS;                    /**< nPktsEponSingleCopyBroadcast Statistic, offset: 0x644 */
  __IO uint32_t MACSEC_IPTLS;                      /**< InPktsTooLong Statistic, offset: 0x648 */
  __IO uint32_t MACSEC_IPFUS;                      /**< InPktsFilteredUp Statistic, offset: 0x64C */
  __IO uint32_t MACSEC_IPDUS;                      /**< InPktsDiscardedUp Statistic, offset: 0x650 */
  uint8_t RESERVED_22[44];
  __IO uint32_t MACSEC_OPDS;                       /**< OutPktsDiscarded Statistic, offset: 0x680 */
  uint8_t RESERVED_23[156];
  __IO uint32_t MACSEC_RXSAASSCI;                  /**< RX Security Association A Short Secure Channel Identifier, offset: 0x720 */
  __IO uint32_t MACSEC_RXSAASALT1T;                /**< RX Security Association A SALT 1 of 3, offset: 0x724 */
  __IO uint32_t MACSEC_RXSAASALT2T;                /**< RX Security Association A SALT 2 of 3, offset: 0x728 */
  __IO uint32_t MACSEC_RXSAASALT3T;                /**< RX Security Association A SALT 3 of 3, offset: 0x72C */
  uint8_t RESERVED_24[48];
  __IO uint32_t MACSEC_RXSABSSCI;                  /**< RX Security Association B Short Secure Channel Identifier, offset: 0x760 */
  __IO uint32_t MACSEC_RXSABSALT1T;                /**< RX Security Association B SALT 1 of 3, offset: 0x764 */
  __IO uint32_t MACSEC_RXSABSALT2T;                /**< RX Security Association B SALT 2 of 3, offset: 0x768 */
  __IO uint32_t MACSEC_RXSABSALT3T;                /**< RX Security Association B SALT 3 of 3, offset: 0x76C */
  uint8_t RESERVED_25[48];
  __IO uint32_t MACSEC_TXSAASSCI;                  /**< TX Security Association A Short Secure Channel Identifier, offset: 0x7A0 */
  __IO uint32_t MACSEC_TXSAASALT1T;                /**< TX Security Association A SALT 1 of 3, offset: 0x7A4 */
  __IO uint32_t MACSEC_TXSAASALT2T;                /**< TX Security Association A SALT 2 of 3, offset: 0x7A8 */
  __IO uint32_t MACSEC_TXSAASALT3T;                /**< TX Security Association A SALT 3 of 3, offset: 0x7AC */
  uint8_t RESERVED_26[48];
  __IO uint32_t MACSEC_TXSABSSCI;                  /**< TX Security Association B Short Secure Channel Identifier, offset: 0x7E0 */
  __IO uint32_t MACSEC_TXSABSALT1T;                /**< TX Security Association B SALT 1 of 3, offset: 0x7E4 */
  __IO uint32_t MACSEC_TXSABSALT2T;                /**< TX Security Association B SALT 2 of 3, offset: 0x7E8 */
  __IO uint32_t MACSEC_TXSABSALT3T;                /**< TX Security Association B SALT 3 of 3, offset: 0x7EC */
  uint8_t RESERVED_27[16];
  __IO uint32_t MACSEC_TXSCSR0P0;                  /**< TX SC Selection Record 0 part 0, offset: 0x800 */
  __IO uint32_t MACSEC_TXSCSR0P1;                  /**< TX SC Selection Record 0 part 1, offset: 0x804 */
  __IO uint32_t MACSEC_TXSCSR0P2;                  /**< TX SC Selection Record 0 part 2, offset: 0x808 */
  __IO uint32_t MACSEC_TXSCSR0P3;                  /**< TX SC Selection Record 0 part 3, offset: 0x80C */
  __IO uint32_t MACSEC_TXSCSR1P0;                  /**< TX SC Selection Record 1 part 0, offset: 0x810 */
  __IO uint32_t MACSEC_TXSCSR1P1;                  /**< TX SC Selection Record 1 part 1, offset: 0x814 */
  __IO uint32_t MACSEC_TXSCSR1P2;                  /**< TX SC Selection Record 1 part 2, offset: 0x818 */
  __IO uint32_t MACSEC_TXSCSR1P3;                  /**< TX SC Selection Record 1 part 3, offset: 0x81C */
  __IO uint32_t MACSEC_TXSCSR2P0;                  /**< TX SC Selection Record 2 part 0, offset: 0x820 */
  __IO uint32_t MACSEC_TXSCSR2P1;                  /**< TX SC Selection Record 2 part 1, offset: 0x824 */
  __IO uint32_t MACSEC_TXSCSR2P2;                  /**< TX SC Selection Record 2 part 2, offset: 0x828 */
  __IO uint32_t MACSEC_TXSCSR2P3;                  /**< TX SC Selection Record 2 part 3, offset: 0x82C */
  __IO uint32_t MACSEC_TXSCSR3P0;                  /**< TX SC Selection Record 3 part 0, offset: 0x830 */
  __IO uint32_t MACSEC_TXSCSR3P1;                  /**< TX SC Selection Record 3 part 1, offset: 0x834 */
  __IO uint32_t MACSEC_TXSCSR3P2;                  /**< TX SC Selection Record 3 part 2, offset: 0x838 */
  __IO uint32_t MACSEC_TXSCSR3P3;                  /**< TX SC Selection Record 3 part 3, offset: 0x83C */
  __IO uint32_t MACSEC_TXSCSR4P0;                  /**< TX SC Selection Record 4 part 0, offset: 0x840 */
  __IO uint32_t MACSEC_TXSCSR4P1;                  /**< TX SC Selection Record 4 part 1, offset: 0x844 */
  __IO uint32_t MACSEC_TXSCSR4P2;                  /**< TX SC Selection Record 4 part 2, offset: 0x848 */
  __IO uint32_t MACSEC_TXSCSR4P3;                  /**< TX SC Selection Record 4 part 3, offset: 0x84C */
  __IO uint32_t MACSEC_TXSCSR5P0;                  /**< TX SC Selection Record 5 part 0, offset: 0x850 */
  __IO uint32_t MACSEC_TXSCSR5P1;                  /**< TX SC Selection Record 5 part 1, offset: 0x854 */
  __IO uint32_t MACSEC_TXSCSR5P2;                  /**< TX SC Selection Record 5 part 2, offset: 0x858 */
  __IO uint32_t MACSEC_TXSCSR5P3;                  /**< TX SC Selection Record 5 part 3, offset: 0x85C */
  __IO uint32_t MACSEC_TXSCSR6P0;                  /**< TX SC Selection Record 6 part 0, offset: 0x860 */
  __IO uint32_t MACSEC_TXSCSR6P1;                  /**< TX SC Selection Record 6 part 1, offset: 0x864 */
  __IO uint32_t MACSEC_TXSCSR6P2;                  /**< TX SC Selection Record 6 part 2, offset: 0x868 */
  __IO uint32_t MACSEC_TXSCSR6P3;                  /**< TX SC Selection Record 6 part 3, offset: 0x86C */
  __IO uint32_t MACSEC_TXSCSR7P0;                  /**< TX SC Selection Record 7 part 0, offset: 0x870 */
  __IO uint32_t MACSEC_TXSCSR7P1;                  /**< TX SC Selection Record 7 part 1, offset: 0x874 */
  __IO uint32_t MACSEC_TXSCSR7P2;                  /**< TX SC Selection Record 7 part 2, offset: 0x878 */
  __IO uint32_t MACSEC_TXSCSR7P3;                  /**< TX SC Selection Record 7 part 3, offset: 0x87C */
  uint8_t RESERVED_28[384];
  __IO uint32_t MACSEC_UPFR0D0;                    /**< Uncontrolled Port filter Record 0 data part 0, offset: 0xA00 */
  __IO uint32_t MACSEC_UPFR0D1;                    /**< Uncontrolled Port filter Record 0 data part 1, offset: 0xA04 */
  __IO uint32_t MACSEC_UPFR0D2;                    /**< Uncontrolled Port filter Record 0 data part 2, offset: 0xA08 */
  __IO uint32_t MACSEC_UPFR0M0;                    /**< Uncontrolled Port filter Record 0 mask part 0, offset: 0xA0C */
  __IO uint32_t MACSEC_UPFR0M1;                    /**< Uncontrolled Port filter Record 0 mask part 1, offset: 0xA10 */
  __IO uint32_t MACSEC_UPFR0M2;                    /**< Uncontrolled Port filter Record 0 mask part 2, offset: 0xA14 */
  __IO uint32_t MACSEC_UPFR0R;                     /**< Uncontrolled Port filter Record 0 Result, offset: 0xA18 */
  uint8_t RESERVED_29[4];
  __IO uint32_t MACSEC_UPFR1D0;                    /**< Uncontrolled Port filter Record 1 data part 0, offset: 0xA20 */
  __IO uint32_t MACSEC_UPFR1D1;                    /**< Uncontrolled Port filter Record 1 data part 1, offset: 0xA24 */
  __IO uint32_t MACSEC_UPFR1D2;                    /**< Uncontrolled Port filter Record 1 data part 2, offset: 0xA28 */
  __IO uint32_t MACSEC_UPFR1M0;                    /**< Uncontrolled Port filter Record 1 mask part 0, offset: 0xA2C */
  __IO uint32_t MACSEC_UPFR1M1;                    /**< Uncontrolled Port filter Record 1 mask part 1, offset: 0xA30 */
  __IO uint32_t MACSEC_UPFR1M2;                    /**< Uncontrolled Port filter Record 1 mask part 2, offset: 0xA34 */
  __IO uint32_t MACSEC_UPFR1R;                     /**< Uncontrolled Port filter Record 1 Result, offset: 0xA38 */
  uint8_t RESERVED_30[4];
  __IO uint32_t MACSEC_UPFR2D0;                    /**< Uncontrolled Port filter Record 2 data part 0, offset: 0xA40 */
  __IO uint32_t MACSEC_UPFR2D1;                    /**< Uncontrolled Port filter Record 2 data part 1, offset: 0xA44 */
  __IO uint32_t MACSEC_UPFR2D2;                    /**< Uncontrolled Port filter Record 2 data part 2, offset: 0xA48 */
  __IO uint32_t MACSEC_UPFR2M0;                    /**< Uncontrolled Port filter Record 2 mask part 0, offset: 0xA4C */
  __IO uint32_t MACSEC_UPFR2M1;                    /**< Uncontrolled Port filter Record 2 mask part 1, offset: 0xA50 */
  __IO uint32_t MACSEC_UPFR2M2;                    /**< Uncontrolled Port filter Record 2 mask part 2, offset: 0xA54 */
  __IO uint32_t MACSEC_UPFR2R;                     /**< Uncontrolled Port filter Record 2 Result, offset: 0xA58 */
  uint8_t RESERVED_31[4];
  __IO uint32_t MACSEC_UPFR3D0;                    /**< Uncontrolled Port filter Record 3 data part 0, offset: 0xA60 */
  __IO uint32_t MACSEC_UPFR3D1;                    /**< Uncontrolled Port filter Record 3 data part 1, offset: 0xA64 */
  __IO uint32_t MACSEC_UPFR3D2;                    /**< Uncontrolled Port filter Record 3 data part 2, offset: 0xA68 */
  __IO uint32_t MACSEC_UPFR3M0;                    /**< Uncontrolled Port filter Record 3 mask part 0, offset: 0xA6C */
  __IO uint32_t MACSEC_UPFR3M1;                    /**< Uncontrolled Port filter Record 3 mask part 1, offset: 0xA70 */
  __IO uint32_t MACSEC_UPFR3M2;                    /**< Uncontrolled Port filter Record 3 mask part 2, offset: 0xA74 */
  __IO uint32_t MACSEC_UPFR3R;                     /**< Uncontrolled Port filter Record 3 Result, offset: 0xA78 */
  uint8_t RESERVED_32[4];
  __IO uint32_t MACSEC_UPFR4D0;                    /**< Uncontrolled Port filter Record 4 data part 0, offset: 0xA80 */
  __IO uint32_t MACSEC_UPFR4D1;                    /**< Uncontrolled Port filter Record 4 data part 1, offset: 0xA84 */
  __IO uint32_t MACSEC_UPFR4D2;                    /**< Uncontrolled Port filter Record 4 data part 2, offset: 0xA88 */
  __IO uint32_t MACSEC_UPFR4M0;                    /**< Uncontrolled Port filter Record 4 mask part 0, offset: 0xA8C */
  __IO uint32_t MACSEC_UPFR4M1;                    /**< Uncontrolled Port filter Record 4 mask part 1, offset: 0xA90 */
  __IO uint32_t MACSEC_UPFR4M2;                    /**< Uncontrolled Port filter Record 4 mask part 2, offset: 0xA94 */
  __IO uint32_t MACSEC_UPFR4R;                     /**< Uncontrolled Port filter Record 4 Result, offset: 0xA98 */
  uint8_t RESERVED_33[4];
  __IO uint32_t MACSEC_UPFR5D0;                    /**< Uncontrolled Port filter Record 5 data part 0, offset: 0xAA0 */
  __IO uint32_t MACSEC_UPFR5D1;                    /**< Uncontrolled Port filter Record 5 data part 1, offset: 0xAA4 */
  __IO uint32_t MACSEC_UPFR5D2;                    /**< Uncontrolled Port filter Record 5 data part 2, offset: 0xAA8 */
  __IO uint32_t MACSEC_UPFR5M0;                    /**< Uncontrolled Port filter Record 5 mask part 0, offset: 0xAAC */
  __IO uint32_t MACSEC_UPFR5M1;                    /**< Uncontrolled Port filter Record 5 mask part 1, offset: 0xAB0 */
  __IO uint32_t MACSEC_UPFR5M2;                    /**< Uncontrolled Port filter Record 5 mask part 2, offset: 0xAB4 */
  __IO uint32_t MACSEC_UPFR5R;                     /**< Uncontrolled Port filter Record 5 Result, offset: 0xAB8 */
  uint8_t RESERVED_34[4];
  __IO uint32_t MACSEC_UPFR6D0;                    /**< Uncontrolled Port filter Record 6 data part 0, offset: 0xAC0 */
  __IO uint32_t MACSEC_UPFR6D1;                    /**< Uncontrolled Port filter Record 6 data part 1, offset: 0xAC4 */
  __IO uint32_t MACSEC_UPFR6D2;                    /**< Uncontrolled Port filter Record 6 data part 2, offset: 0xAC8 */
  __IO uint32_t MACSEC_UPFR6M0;                    /**< Uncontrolled Port filter Record 6 mask part 0, offset: 0xACC */
  __IO uint32_t MACSEC_UPFR6M1;                    /**< Uncontrolled Port filter Record 6 mask part 1, offset: 0xAD0 */
  __IO uint32_t MACSEC_UPFR6M2;                    /**< Uncontrolled Port filter Record 6 mask part 2, offset: 0xAD4 */
  __IO uint32_t MACSEC_UPFR6R;                     /**< Uncontrolled Port filter Record 6 Result, offset: 0xAD8 */
  uint8_t RESERVED_35[4];
  __IO uint32_t MACSEC_UPFR7D0;                    /**< Uncontrolled Port filter Record 7 data part 0, offset: 0xAE0 */
  __IO uint32_t MACSEC_UPFR7D1;                    /**< Uncontrolled Port filter Record 7 data part 1, offset: 0xAE4 */
  __IO uint32_t MACSEC_UPFR7D2;                    /**< Uncontrolled Port filter Record 7 data part 2, offset: 0xAE8 */
  __IO uint32_t MACSEC_UPFR7M0;                    /**< Uncontrolled Port filter Record 7 mask part 0, offset: 0xAEC */
  __IO uint32_t MACSEC_UPFR7M1;                    /**< Uncontrolled Port filter Record 7 mask part 1, offset: 0xAF0 */
  __IO uint32_t MACSEC_UPFR7M2;                    /**< Uncontrolled Port filter Record 7 mask part 2, offset: 0xAF4 */
  __IO uint32_t MACSEC_UPFR7R;                     /**< Uncontrolled Port filter Record 7 Result, offset: 0xAF8 */
} MACSEC_Type, *MACSEC_MemMapPtr;

/** Number of instances of the MACSEC module. */
#define MACSEC_INSTANCE_COUNT                    (5u)

/* MACSEC - Peripheral instance base addresses */
/** Peripheral NETC__SW0_ETH_MACSEC_PORT0 base address */
#define IP_NETC__SW0_ETH_MACSEC_PORT0_BASE       (0x6D006000u)
/** Peripheral NETC__SW0_ETH_MACSEC_PORT0 base pointer */
#define IP_NETC__SW0_ETH_MACSEC_PORT0            ((MACSEC_Type *)IP_NETC__SW0_ETH_MACSEC_PORT0_BASE)
/** Peripheral NETC__SW0_ETH_MACSEC_PORT1 base address */
#define IP_NETC__SW0_ETH_MACSEC_PORT1_BASE       (0x6D00A000u)
/** Peripheral NETC__SW0_ETH_MACSEC_PORT1 base pointer */
#define IP_NETC__SW0_ETH_MACSEC_PORT1            ((MACSEC_Type *)IP_NETC__SW0_ETH_MACSEC_PORT1_BASE)
/** Peripheral NETC__SW0_ETH_MACSEC_PORT2 base address */
#define IP_NETC__SW0_ETH_MACSEC_PORT2_BASE       (0x6D00E000u)
/** Peripheral NETC__SW0_ETH_MACSEC_PORT2 base pointer */
#define IP_NETC__SW0_ETH_MACSEC_PORT2            ((MACSEC_Type *)IP_NETC__SW0_ETH_MACSEC_PORT2_BASE)
/** Peripheral NETC__SW0_ETH_MACSEC_PORT3 base address */
#define IP_NETC__SW0_ETH_MACSEC_PORT3_BASE       (0x6D012000u)
/** Peripheral NETC__SW0_ETH_MACSEC_PORT3 base pointer */
#define IP_NETC__SW0_ETH_MACSEC_PORT3            ((MACSEC_Type *)IP_NETC__SW0_ETH_MACSEC_PORT3_BASE)
/** Peripheral NETC__SW0_ETH_MACSEC_PORT4 base address */
#define IP_NETC__SW0_ETH_MACSEC_PORT4_BASE       (0x6D016000u)
/** Peripheral NETC__SW0_ETH_MACSEC_PORT4 base pointer */
#define IP_NETC__SW0_ETH_MACSEC_PORT4            ((MACSEC_Type *)IP_NETC__SW0_ETH_MACSEC_PORT4_BASE)
/** Array initializer of MACSEC peripheral base addresses */
#define IP_MACSEC_BASE_ADDRS                     { IP_NETC__SW0_ETH_MACSEC_PORT0_BASE, IP_NETC__SW0_ETH_MACSEC_PORT1_BASE, IP_NETC__SW0_ETH_MACSEC_PORT2_BASE, IP_NETC__SW0_ETH_MACSEC_PORT3_BASE, IP_NETC__SW0_ETH_MACSEC_PORT4_BASE }
/** Array initializer of MACSEC peripheral base pointers */
#define IP_MACSEC_BASE_PTRS                      { IP_NETC__SW0_ETH_MACSEC_PORT0, IP_NETC__SW0_ETH_MACSEC_PORT1, IP_NETC__SW0_ETH_MACSEC_PORT2, IP_NETC__SW0_ETH_MACSEC_PORT3, IP_NETC__SW0_ETH_MACSEC_PORT4 }

/* ----------------------------------------------------------------------------
   -- MACSEC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MACSEC_Register_Masks MACSEC Register Masks
 * @{
 */

/*! @name MACSEC_CFG - MACsec configuration */
/*! @{ */

#define MACSEC_MACSEC_CFG_S0I_MASK               (0x1U)
#define MACSEC_MACSEC_CFG_S0I_SHIFT              (0U)
#define MACSEC_MACSEC_CFG_S0I_WIDTH              (1U)
#define MACSEC_MACSEC_CFG_S0I(x)                 (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_S0I_SHIFT)) & MACSEC_MACSEC_CFG_S0I_MASK)

#define MACSEC_MACSEC_CFG_BYPN_MASK              (0x2U)
#define MACSEC_MACSEC_CFG_BYPN_SHIFT             (1U)
#define MACSEC_MACSEC_CFG_BYPN_WIDTH             (1U)
#define MACSEC_MACSEC_CFG_BYPN(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_BYPN_SHIFT)) & MACSEC_MACSEC_CFG_BYPN_MASK)

#define MACSEC_MACSEC_CFG_KSS_MASK               (0x4U)
#define MACSEC_MACSEC_CFG_KSS_SHIFT              (2U)
#define MACSEC_MACSEC_CFG_KSS_WIDTH              (1U)
#define MACSEC_MACSEC_CFG_KSS(x)                 (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_KSS_SHIFT)) & MACSEC_MACSEC_CFG_KSS_MASK)

#define MACSEC_MACSEC_CFG_VFN_MASK               (0x8U)
#define MACSEC_MACSEC_CFG_VFN_SHIFT              (3U)
#define MACSEC_MACSEC_CFG_VFN_WIDTH              (1U)
#define MACSEC_MACSEC_CFG_VFN(x)                 (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_VFN_SHIFT)) & MACSEC_MACSEC_CFG_VFN_MASK)

#define MACSEC_MACSEC_CFG_UFT_MASK               (0x30U)
#define MACSEC_MACSEC_CFG_UFT_SHIFT              (4U)
#define MACSEC_MACSEC_CFG_UFT_WIDTH              (2U)
#define MACSEC_MACSEC_CFG_UFT(x)                 (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_UFT_SHIFT)) & MACSEC_MACSEC_CFG_UFT_MASK)

#define MACSEC_MACSEC_CFG_KFT_MASK               (0x40U)
#define MACSEC_MACSEC_CFG_KFT_SHIFT              (6U)
#define MACSEC_MACSEC_CFG_KFT_WIDTH              (1U)
#define MACSEC_MACSEC_CFG_KFT(x)                 (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_KFT_SHIFT)) & MACSEC_MACSEC_CFG_KFT_MASK)

#define MACSEC_MACSEC_CFG_ITT_MASK               (0x80U)
#define MACSEC_MACSEC_CFG_ITT_SHIFT              (7U)
#define MACSEC_MACSEC_CFG_ITT_WIDTH              (1U)
#define MACSEC_MACSEC_CFG_ITT(x)                 (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_ITT_SHIFT)) & MACSEC_MACSEC_CFG_ITT_MASK)

#define MACSEC_MACSEC_CFG_USFT_MASK              (0x300U)
#define MACSEC_MACSEC_CFG_USFT_SHIFT             (8U)
#define MACSEC_MACSEC_CFG_USFT_WIDTH             (2U)
#define MACSEC_MACSEC_CFG_USFT(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_USFT_SHIFT)) & MACSEC_MACSEC_CFG_USFT_MASK)

#define MACSEC_MACSEC_CFG_ESCBT_MASK             (0x400U)
#define MACSEC_MACSEC_CFG_ESCBT_SHIFT            (10U)
#define MACSEC_MACSEC_CFG_ESCBT_WIDTH            (1U)
#define MACSEC_MACSEC_CFG_ESCBT(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_ESCBT_SHIFT)) & MACSEC_MACSEC_CFG_ESCBT_MASK)

#define MACSEC_MACSEC_CFG_UECT_MASK              (0x800U)
#define MACSEC_MACSEC_CFG_UECT_SHIFT             (11U)
#define MACSEC_MACSEC_CFG_UECT_WIDTH             (1U)
#define MACSEC_MACSEC_CFG_UECT(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_UECT_SHIFT)) & MACSEC_MACSEC_CFG_UECT_MASK)

#define MACSEC_MACSEC_CFG_UPSCMT_MASK            (0x1000U)
#define MACSEC_MACSEC_CFG_UPSCMT_SHIFT           (12U)
#define MACSEC_MACSEC_CFG_UPSCMT_WIDTH           (1U)
#define MACSEC_MACSEC_CFG_UPSCMT(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_UPSCMT_SHIFT)) & MACSEC_MACSEC_CFG_UPSCMT_MASK)

#define MACSEC_MACSEC_CFG_KSSHD_MASK             (0x2000U)
#define MACSEC_MACSEC_CFG_KSSHD_SHIFT            (13U)
#define MACSEC_MACSEC_CFG_KSSHD_WIDTH            (1U)
#define MACSEC_MACSEC_CFG_KSSHD(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_KSSHD_SHIFT)) & MACSEC_MACSEC_CFG_KSSHD_MASK)

#define MACSEC_MACSEC_CFG_SLC_MASK               (0x10000U)
#define MACSEC_MACSEC_CFG_SLC_SHIFT              (16U)
#define MACSEC_MACSEC_CFG_SLC_WIDTH              (1U)
#define MACSEC_MACSEC_CFG_SLC(x)                 (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_SLC_SHIFT)) & MACSEC_MACSEC_CFG_SLC_MASK)

#define MACSEC_MACSEC_CFG_SLD_MASK               (0x20000U)
#define MACSEC_MACSEC_CFG_SLD_SHIFT              (17U)
#define MACSEC_MACSEC_CFG_SLD_WIDTH              (1U)
#define MACSEC_MACSEC_CFG_SLD(x)                 (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_SLD_SHIFT)) & MACSEC_MACSEC_CFG_SLD_MASK)

#define MACSEC_MACSEC_CFG_VCT_MASK               (0x1000000U)
#define MACSEC_MACSEC_CFG_VCT_SHIFT              (24U)
#define MACSEC_MACSEC_CFG_VCT_WIDTH              (1U)
#define MACSEC_MACSEC_CFG_VCT(x)                 (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_VCT_SHIFT)) & MACSEC_MACSEC_CFG_VCT_MASK)

#define MACSEC_MACSEC_CFG_UFDCD_MASK             (0x2000000U)
#define MACSEC_MACSEC_CFG_UFDCD_SHIFT            (25U)
#define MACSEC_MACSEC_CFG_UFDCD_WIDTH            (1U)
#define MACSEC_MACSEC_CFG_UFDCD(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_UFDCD_SHIFT)) & MACSEC_MACSEC_CFG_UFDCD_MASK)

#define MACSEC_MACSEC_CFG_EXTSCS_MASK            (0x4000000U)
#define MACSEC_MACSEC_CFG_EXTSCS_SHIFT           (26U)
#define MACSEC_MACSEC_CFG_EXTSCS_WIDTH           (1U)
#define MACSEC_MACSEC_CFG_EXTSCS(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_EXTSCS_SHIFT)) & MACSEC_MACSEC_CFG_EXTSCS_MASK)

#define MACSEC_MACSEC_CFG_UFDCM_MASK             (0x8000000U)
#define MACSEC_MACSEC_CFG_UFDCM_SHIFT            (27U)
#define MACSEC_MACSEC_CFG_UFDCM_WIDTH            (1U)
#define MACSEC_MACSEC_CFG_UFDCM(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CFG_UFDCM_SHIFT)) & MACSEC_MACSEC_CFG_UFDCM_MASK)
/*! @} */

/*! @name MACSEC_ET - MACsec EtherType */
/*! @{ */

#define MACSEC_MACSEC_ET_MACSEC_ET_MASK          (0xFFFFU)
#define MACSEC_MACSEC_ET_MACSEC_ET_SHIFT         (0U)
#define MACSEC_MACSEC_ET_MACSEC_ET_WIDTH         (16U)
#define MACSEC_MACSEC_ET_MACSEC_ET(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ET_MACSEC_ET_SHIFT)) & MACSEC_MACSEC_ET_MACSEC_ET_MASK)
/*! @} */

/*! @name MACSEC_CTPID1 - MACsec Configured TPID1 */
/*! @{ */

#define MACSEC_MACSEC_CTPID1_ETYPE_MASK          (0xFFFFU)
#define MACSEC_MACSEC_CTPID1_ETYPE_SHIFT         (0U)
#define MACSEC_MACSEC_CTPID1_ETYPE_WIDTH         (16U)
#define MACSEC_MACSEC_CTPID1_ETYPE(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CTPID1_ETYPE_SHIFT)) & MACSEC_MACSEC_CTPID1_ETYPE_MASK)

#define MACSEC_MACSEC_CTPID1_V_MASK              (0x80000000U)
#define MACSEC_MACSEC_CTPID1_V_SHIFT             (31U)
#define MACSEC_MACSEC_CTPID1_V_WIDTH             (1U)
#define MACSEC_MACSEC_CTPID1_V(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CTPID1_V_SHIFT)) & MACSEC_MACSEC_CTPID1_V_MASK)
/*! @} */

/*! @name MACSEC_CTPID2 - MACsec Configured TPID2 */
/*! @{ */

#define MACSEC_MACSEC_CTPID2_ETYPE_MASK          (0xFFFFU)
#define MACSEC_MACSEC_CTPID2_ETYPE_SHIFT         (0U)
#define MACSEC_MACSEC_CTPID2_ETYPE_WIDTH         (16U)
#define MACSEC_MACSEC_CTPID2_ETYPE(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CTPID2_ETYPE_SHIFT)) & MACSEC_MACSEC_CTPID2_ETYPE_MASK)

#define MACSEC_MACSEC_CTPID2_TAG_SIZE_MASK       (0x1F0000U)
#define MACSEC_MACSEC_CTPID2_TAG_SIZE_SHIFT      (16U)
#define MACSEC_MACSEC_CTPID2_TAG_SIZE_WIDTH      (5U)
#define MACSEC_MACSEC_CTPID2_TAG_SIZE(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CTPID2_TAG_SIZE_SHIFT)) & MACSEC_MACSEC_CTPID2_TAG_SIZE_MASK)

#define MACSEC_MACSEC_CTPID2_VLAN_MASK           (0x40000000U)
#define MACSEC_MACSEC_CTPID2_VLAN_SHIFT          (30U)
#define MACSEC_MACSEC_CTPID2_VLAN_WIDTH          (1U)
#define MACSEC_MACSEC_CTPID2_VLAN(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CTPID2_VLAN_SHIFT)) & MACSEC_MACSEC_CTPID2_VLAN_MASK)

#define MACSEC_MACSEC_CTPID2_V_MASK              (0x80000000U)
#define MACSEC_MACSEC_CTPID2_V_SHIFT             (31U)
#define MACSEC_MACSEC_CTPID2_V_WIDTH             (1U)
#define MACSEC_MACSEC_CTPID2_V(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_CTPID2_V_SHIFT)) & MACSEC_MACSEC_CTPID2_V_MASK)
/*! @} */

/*! @name MACSEC_VCLCTR - MACsec VLAN Classification Control */
/*! @{ */

#define MACSEC_MACSEC_VCLCTR_OVTPIDL_MASK        (0xFU)
#define MACSEC_MACSEC_VCLCTR_OVTPIDL_SHIFT       (0U)
#define MACSEC_MACSEC_VCLCTR_OVTPIDL_WIDTH       (4U)
#define MACSEC_MACSEC_VCLCTR_OVTPIDL(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_VCLCTR_OVTPIDL_SHIFT)) & MACSEC_MACSEC_VCLCTR_OVTPIDL_MASK)

#define MACSEC_MACSEC_VCLCTR_IVTPIDL_MASK        (0xF0U)
#define MACSEC_MACSEC_VCLCTR_IVTPIDL_SHIFT       (4U)
#define MACSEC_MACSEC_VCLCTR_IVTPIDL_WIDTH       (4U)
#define MACSEC_MACSEC_VCLCTR_IVTPIDL(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_VCLCTR_IVTPIDL_SHIFT)) & MACSEC_MACSEC_VCLCTR_IVTPIDL_MASK)

#define MACSEC_MACSEC_VCLCTR_CTTPIDL_MASK        (0x100U)
#define MACSEC_MACSEC_VCLCTR_CTTPIDL_SHIFT       (8U)
#define MACSEC_MACSEC_VCLCTR_CTTPIDL_WIDTH       (1U)
#define MACSEC_MACSEC_VCLCTR_CTTPIDL(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_VCLCTR_CTTPIDL_SHIFT)) & MACSEC_MACSEC_VCLCTR_CTTPIDL_MASK)
/*! @} */

/*! @name MACSEC_MFL - Maximum Frame Length */
/*! @{ */

#define MACSEC_MACSEC_MFL_MAX_LEN_MASK           (0xFFFFU)
#define MACSEC_MACSEC_MFL_MAX_LEN_SHIFT          (0U)
#define MACSEC_MACSEC_MFL_MAX_LEN_WIDTH          (16U)
#define MACSEC_MACSEC_MFL_MAX_LEN(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_MFL_MAX_LEN_SHIFT)) & MACSEC_MACSEC_MFL_MAX_LEN_MASK)
/*! @} */

/*! @name MACSEC_TPNET - TX Packet Number exhaustion threshold */
/*! @{ */

#define MACSEC_MACSEC_TPNET_EXH_THR_MASK         (0xFFFFFFFFU)
#define MACSEC_MACSEC_TPNET_EXH_THR_SHIFT        (0U)
#define MACSEC_MACSEC_TPNET_EXH_THR_WIDTH        (32U)
#define MACSEC_MACSEC_TPNET_EXH_THR(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TPNET_EXH_THR_SHIFT)) & MACSEC_MACSEC_TPNET_EXH_THR_MASK)
/*! @} */

/*! @name MACSEC_RXSCA - RX SC access select */
/*! @{ */

#define MACSEC_MACSEC_RXSCA_SC_SEL_MASK          (0x3FU)
#define MACSEC_MACSEC_RXSCA_SC_SEL_SHIFT         (0U)
#define MACSEC_MACSEC_RXSCA_SC_SEL_WIDTH         (6U)
#define MACSEC_MACSEC_RXSCA_SC_SEL(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSCA_SC_SEL_SHIFT)) & MACSEC_MACSEC_RXSCA_SC_SEL_MASK)
/*! @} */

/*! @name MACSEC_TXSCA - TX SC access select */
/*! @{ */

#define MACSEC_MACSEC_TXSCA_SC_SEL_MASK          (0x1FU)
#define MACSEC_MACSEC_TXSCA_SC_SEL_SHIFT         (0U)
#define MACSEC_MACSEC_TXSCA_SC_SEL_WIDTH         (5U)
#define MACSEC_MACSEC_TXSCA_SC_SEL(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCA_SC_SEL_SHIFT)) & MACSEC_MACSEC_TXSCA_SC_SEL_MASK)
/*! @} */

/*! @name MACSEC_RXSCI1H - RX Secure Channel Identifier first half */
/*! @{ */

#define MACSEC_MACSEC_RXSCI1H_RXSCI_MASK         (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSCI1H_RXSCI_SHIFT        (0U)
#define MACSEC_MACSEC_RXSCI1H_RXSCI_WIDTH        (32U)
#define MACSEC_MACSEC_RXSCI1H_RXSCI(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSCI1H_RXSCI_SHIFT)) & MACSEC_MACSEC_RXSCI1H_RXSCI_MASK)
/*! @} */

/*! @name MACSEC_RXSCI2H - RX Secure Channel Identifier second half */
/*! @{ */

#define MACSEC_MACSEC_RXSCI2H_RXSCI_MASK         (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSCI2H_RXSCI_SHIFT        (0U)
#define MACSEC_MACSEC_RXSCI2H_RXSCI_WIDTH        (32U)
#define MACSEC_MACSEC_RXSCI2H_RXSCI(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSCI2H_RXSCI_SHIFT)) & MACSEC_MACSEC_RXSCI2H_RXSCI_MASK)
/*! @} */

/*! @name MACSEC_IFIO1HS - ifInOctets first half Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIO1HS_ifInOctets_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIO1HS_ifInOctets_SHIFT   (0U)
#define MACSEC_MACSEC_IFIO1HS_ifInOctets_WIDTH   (32U)
#define MACSEC_MACSEC_IFIO1HS_ifInOctets(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIO1HS_ifInOctets_SHIFT)) & MACSEC_MACSEC_IFIO1HS_ifInOctets_MASK)
/*! @} */

/*! @name MACSEC_IFIO2HS - ifInOctets second half Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIO2HS_ifInOctets_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIO2HS_ifInOctets_SHIFT   (0U)
#define MACSEC_MACSEC_IFIO2HS_ifInOctets_WIDTH   (32U)
#define MACSEC_MACSEC_IFIO2HS_ifInOctets(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIO2HS_ifInOctets_SHIFT)) & MACSEC_MACSEC_IFIO2HS_ifInOctets_MASK)
/*! @} */

/*! @name MACSEC_IFIUPS - ifInUcastPkts Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIUPS_ifInUcastPkts_MASK  (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIUPS_ifInUcastPkts_SHIFT (0U)
#define MACSEC_MACSEC_IFIUPS_ifInUcastPkts_WIDTH (32U)
#define MACSEC_MACSEC_IFIUPS_ifInUcastPkts(x)    (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIUPS_ifInUcastPkts_SHIFT)) & MACSEC_MACSEC_IFIUPS_ifInUcastPkts_MASK)
/*! @} */

/*! @name MACSEC_IFIMPS - ifInMulticastPkts Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIMPS_ifInMulticastPkts_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIMPS_ifInMulticastPkts_SHIFT (0U)
#define MACSEC_MACSEC_IFIMPS_ifInMulticastPkts_WIDTH (32U)
#define MACSEC_MACSEC_IFIMPS_ifInMulticastPkts(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIMPS_ifInMulticastPkts_SHIFT)) & MACSEC_MACSEC_IFIMPS_ifInMulticastPkts_MASK)
/*! @} */

/*! @name MACSEC_IFIBPS - ifInBroadcastPkts Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIBPS_ifInBroadcastPkts_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIBPS_ifInBroadcastPkts_SHIFT (0U)
#define MACSEC_MACSEC_IFIBPS_ifInBroadcastPkts_WIDTH (32U)
#define MACSEC_MACSEC_IFIBPS_ifInBroadcastPkts(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIBPS_ifInBroadcastPkts_SHIFT)) & MACSEC_MACSEC_IFIBPS_ifInBroadcastPkts_MASK)
/*! @} */

/*! @name MACSEC_RXSCCFG - RX Secure Channel configuration */
/*! @{ */

#define MACSEC_MACSEC_RXSCCFG_CO_MASK            (0x3FU)
#define MACSEC_MACSEC_RXSCCFG_CO_SHIFT           (0U)
#define MACSEC_MACSEC_RXSCCFG_CO_WIDTH           (6U)
#define MACSEC_MACSEC_RXSCCFG_CO(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSCCFG_CO_SHIFT)) & MACSEC_MACSEC_RXSCCFG_CO_MASK)

#define MACSEC_MACSEC_RXSCCFG_VF_MASK            (0x300U)
#define MACSEC_MACSEC_RXSCCFG_VF_SHIFT           (8U)
#define MACSEC_MACSEC_RXSCCFG_VF_WIDTH           (2U)
#define MACSEC_MACSEC_RXSCCFG_VF(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSCCFG_VF_SHIFT)) & MACSEC_MACSEC_RXSCCFG_VF_MASK)

#define MACSEC_MACSEC_RXSCCFG_RP_MASK            (0x400U)
#define MACSEC_MACSEC_RXSCCFG_RP_SHIFT           (10U)
#define MACSEC_MACSEC_RXSCCFG_RP_WIDTH           (1U)
#define MACSEC_MACSEC_RXSCCFG_RP(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSCCFG_RP_SHIFT)) & MACSEC_MACSEC_RXSCCFG_RP_MASK)

#define MACSEC_MACSEC_RXSCCFG_SCI_EN_MASK        (0x800U)
#define MACSEC_MACSEC_RXSCCFG_SCI_EN_SHIFT       (11U)
#define MACSEC_MACSEC_RXSCCFG_SCI_EN_WIDTH       (1U)
#define MACSEC_MACSEC_RXSCCFG_SCI_EN(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSCCFG_SCI_EN_SHIFT)) & MACSEC_MACSEC_RXSCCFG_SCI_EN_MASK)

#define MACSEC_MACSEC_RXSCCFG_VID_MASK           (0xFFF000U)
#define MACSEC_MACSEC_RXSCCFG_VID_SHIFT          (12U)
#define MACSEC_MACSEC_RXSCCFG_VID_WIDTH          (12U)
#define MACSEC_MACSEC_RXSCCFG_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSCCFG_VID_SHIFT)) & MACSEC_MACSEC_RXSCCFG_VID_MASK)

#define MACSEC_MACSEC_RXSCCFG_CS_MASK            (0x3000000U)
#define MACSEC_MACSEC_RXSCCFG_CS_SHIFT           (24U)
#define MACSEC_MACSEC_RXSCCFG_CS_WIDTH           (2U)
#define MACSEC_MACSEC_RXSCCFG_CS(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSCCFG_CS_SHIFT)) & MACSEC_MACSEC_RXSCCFG_CS_MASK)

#define MACSEC_MACSEC_RXSCCFG_NUM_TAGS_MASK      (0x60000000U)
#define MACSEC_MACSEC_RXSCCFG_NUM_TAGS_SHIFT     (29U)
#define MACSEC_MACSEC_RXSCCFG_NUM_TAGS_WIDTH     (2U)
#define MACSEC_MACSEC_RXSCCFG_NUM_TAGS(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSCCFG_NUM_TAGS_SHIFT)) & MACSEC_MACSEC_RXSCCFG_NUM_TAGS_MASK)

#define MACSEC_MACSEC_RXSCCFG_TAG_CE_MASK        (0x80000000U)
#define MACSEC_MACSEC_RXSCCFG_TAG_CE_SHIFT       (31U)
#define MACSEC_MACSEC_RXSCCFG_TAG_CE_WIDTH       (1U)
#define MACSEC_MACSEC_RXSCCFG_TAG_CE(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSCCFG_TAG_CE_SHIFT)) & MACSEC_MACSEC_RXSCCFG_TAG_CE_MASK)
/*! @} */

/*! @name MACSEC_RPW - replayWindow */
/*! @{ */

#define MACSEC_MACSEC_RPW_RPW_MASK               (0xFFFFFFFFU)
#define MACSEC_MACSEC_RPW_RPW_SHIFT              (0U)
#define MACSEC_MACSEC_RPW_RPW_WIDTH              (32U)
#define MACSEC_MACSEC_RPW_RPW(x)                 (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RPW_RPW_SHIFT)) & MACSEC_MACSEC_RPW_RPW_MASK)
/*! @} */

/*! @name MACSEC_INOV1HS - InOctetsValidated first half Statistic */
/*! @{ */

#define MACSEC_MACSEC_INOV1HS_InOctetsValidated_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_INOV1HS_InOctetsValidated_SHIFT (0U)
#define MACSEC_MACSEC_INOV1HS_InOctetsValidated_WIDTH (32U)
#define MACSEC_MACSEC_INOV1HS_InOctetsValidated(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_INOV1HS_InOctetsValidated_SHIFT)) & MACSEC_MACSEC_INOV1HS_InOctetsValidated_MASK)
/*! @} */

/*! @name MACSEC_INOV2HS - InOctetsValidated second half Statistic */
/*! @{ */

#define MACSEC_MACSEC_INOV2HS_InOctetsValidated_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_INOV2HS_InOctetsValidated_SHIFT (0U)
#define MACSEC_MACSEC_INOV2HS_InOctetsValidated_WIDTH (32U)
#define MACSEC_MACSEC_INOV2HS_InOctetsValidated(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_INOV2HS_InOctetsValidated_SHIFT)) & MACSEC_MACSEC_INOV2HS_InOctetsValidated_MASK)
/*! @} */

/*! @name MACSEC_INOD1HS - InOctetsDecrypted first half Statistic */
/*! @{ */

#define MACSEC_MACSEC_INOD1HS_InOctetsDecrypted_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_INOD1HS_InOctetsDecrypted_SHIFT (0U)
#define MACSEC_MACSEC_INOD1HS_InOctetsDecrypted_WIDTH (32U)
#define MACSEC_MACSEC_INOD1HS_InOctetsDecrypted(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_INOD1HS_InOctetsDecrypted_SHIFT)) & MACSEC_MACSEC_INOD1HS_InOctetsDecrypted_MASK)
/*! @} */

/*! @name MACSEC_INOD2HS - InOctetsDecrypted second half Statistic */
/*! @{ */

#define MACSEC_MACSEC_INOD2HS_InOctetsDecrypted_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_INOD2HS_InOctetsDecrypted_SHIFT (0U)
#define MACSEC_MACSEC_INOD2HS_InOctetsDecrypted_WIDTH (32U)
#define MACSEC_MACSEC_INOD2HS_InOctetsDecrypted(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_INOD2HS_InOctetsDecrypted_SHIFT)) & MACSEC_MACSEC_INOD2HS_InOctetsDecrypted_MASK)
/*! @} */

/*! @name MACSEC_RXSCIPUS - RX Secure Channel InPktsUnchecked Statistic */
/*! @{ */

#define MACSEC_MACSEC_RXSCIPUS_InPktsUnchecked_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSCIPUS_InPktsUnchecked_SHIFT (0U)
#define MACSEC_MACSEC_RXSCIPUS_InPktsUnchecked_WIDTH (32U)
#define MACSEC_MACSEC_RXSCIPUS_InPktsUnchecked(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSCIPUS_InPktsUnchecked_SHIFT)) & MACSEC_MACSEC_RXSCIPUS_InPktsUnchecked_MASK)
/*! @} */

/*! @name MACSEC_RXSCIPDS - RX Secure Channel InPktsDelayed Statistic */
/*! @{ */

#define MACSEC_MACSEC_RXSCIPDS_InPktsDelayed_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSCIPDS_InPktsDelayed_SHIFT (0U)
#define MACSEC_MACSEC_RXSCIPDS_InPktsDelayed_WIDTH (32U)
#define MACSEC_MACSEC_RXSCIPDS_InPktsDelayed(x)  (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSCIPDS_InPktsDelayed_SHIFT)) & MACSEC_MACSEC_RXSCIPDS_InPktsDelayed_MASK)
/*! @} */

/*! @name MACSEC_RXSCIPLS - RX Secure Channel InPktsLate Statistic */
/*! @{ */

#define MACSEC_MACSEC_RXSCIPLS_InPktsLate_MASK   (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSCIPLS_InPktsLate_SHIFT  (0U)
#define MACSEC_MACSEC_RXSCIPLS_InPktsLate_WIDTH  (32U)
#define MACSEC_MACSEC_RXSCIPLS_InPktsLate(x)     (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSCIPLS_InPktsLate_SHIFT)) & MACSEC_MACSEC_RXSCIPLS_InPktsLate_MASK)
/*! @} */

/*! @name MACSEC_RXANINUSS - RX AN 0 InNotUsingSA Statistic..RX AN 3 InNotUsingSA Statistic */
/*! @{ */

#define MACSEC_MACSEC_RXANINUSS_InNotUsingSA_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXANINUSS_InNotUsingSA_SHIFT (0U)
#define MACSEC_MACSEC_RXANINUSS_InNotUsingSA_WIDTH (32U)
#define MACSEC_MACSEC_RXANINUSS_InNotUsingSA(x)  (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXANINUSS_InNotUsingSA_SHIFT)) & MACSEC_MACSEC_RXANINUSS_InNotUsingSA_MASK)
/*! @} */

/*! @name MACSEC_RXANIPUSS - RX AN 0 InPktsUnusedSA Statistic..RX AN 3 InPktsUnusedSA Statistic */
/*! @{ */

#define MACSEC_MACSEC_RXANIPUSS_InPktsUnusedSA_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXANIPUSS_InPktsUnusedSA_SHIFT (0U)
#define MACSEC_MACSEC_RXANIPUSS_InPktsUnusedSA_WIDTH (32U)
#define MACSEC_MACSEC_RXANIPUSS_InPktsUnusedSA(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXANIPUSS_InPktsUnusedSA_SHIFT)) & MACSEC_MACSEC_RXANIPUSS_InPktsUnusedSA_MASK)
/*! @} */

/*! @name MACSEC_RXSAACS - RX Security Association A configuration and status */
/*! @{ */

#define MACSEC_MACSEC_RXSAACS_EN_MASK            (0x1U)
#define MACSEC_MACSEC_RXSAACS_EN_SHIFT           (0U)
#define MACSEC_MACSEC_RXSAACS_EN_WIDTH           (1U)
#define MACSEC_MACSEC_RXSAACS_EN(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSAACS_EN_SHIFT)) & MACSEC_MACSEC_RXSAACS_EN_MASK)

#define MACSEC_MACSEC_RXSAACS_AN_MASK            (0x6U)
#define MACSEC_MACSEC_RXSAACS_AN_SHIFT           (1U)
#define MACSEC_MACSEC_RXSAACS_AN_WIDTH           (2U)
#define MACSEC_MACSEC_RXSAACS_AN(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSAACS_AN_SHIFT)) & MACSEC_MACSEC_RXSAACS_AN_MASK)

#define MACSEC_MACSEC_RXSAACS_A_MASK             (0x80000000U)
#define MACSEC_MACSEC_RXSAACS_A_SHIFT            (31U)
#define MACSEC_MACSEC_RXSAACS_A_WIDTH            (1U)
#define MACSEC_MACSEC_RXSAACS_A(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSAACS_A_SHIFT)) & MACSEC_MACSEC_RXSAACS_A_MASK)
/*! @} */

/*! @name MACSEC_RXSAANPN - RX Security Association A nextPN */
/*! @{ */

#define MACSEC_MACSEC_RXSAANPN_nextPN_MASK       (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSAANPN_nextPN_SHIFT      (0U)
#define MACSEC_MACSEC_RXSAANPN_nextPN_WIDTH      (32U)
#define MACSEC_MACSEC_RXSAANPN_nextPN(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSAANPN_nextPN_SHIFT)) & MACSEC_MACSEC_RXSAANPN_nextPN_MASK)
/*! @} */

/*! @name MACSEC_RXSAAXNPN - RX Security Association Extended A nextPN */
/*! @{ */

#define MACSEC_MACSEC_RXSAAXNPN_ext_nextPN_MASK  (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSAAXNPN_ext_nextPN_SHIFT (0U)
#define MACSEC_MACSEC_RXSAAXNPN_ext_nextPN_WIDTH (32U)
#define MACSEC_MACSEC_RXSAAXNPN_ext_nextPN(x)    (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSAAXNPN_ext_nextPN_SHIFT)) & MACSEC_MACSEC_RXSAAXNPN_ext_nextPN_MASK)
/*! @} */

/*! @name MACSEC_RXSAALPN - RX Security Association A lowestPN */
/*! @{ */

#define MACSEC_MACSEC_RXSAALPN_lowestPN_MASK     (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSAALPN_lowestPN_SHIFT    (0U)
#define MACSEC_MACSEC_RXSAALPN_lowestPN_WIDTH    (32U)
#define MACSEC_MACSEC_RXSAALPN_lowestPN(x)       (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSAALPN_lowestPN_SHIFT)) & MACSEC_MACSEC_RXSAALPN_lowestPN_MASK)
/*! @} */

/*! @name MACSEC_RXSAAXLPN - RX Security Association Extended A lowestPN */
/*! @{ */

#define MACSEC_MACSEC_RXSAAXLPN_ext_lowestPN_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSAAXLPN_ext_lowestPN_SHIFT (0U)
#define MACSEC_MACSEC_RXSAAXLPN_ext_lowestPN_WIDTH (32U)
#define MACSEC_MACSEC_RXSAAXLPN_ext_lowestPN(x)  (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSAAXLPN_ext_lowestPN_SHIFT)) & MACSEC_MACSEC_RXSAAXLPN_ext_lowestPN_MASK)
/*! @} */

/*! @name MACSEC_RXSAAIPOS - RX Security Association A InPktsOK Statistic */
/*! @{ */

#define MACSEC_MACSEC_RXSAAIPOS_InPktsOK_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSAAIPOS_InPktsOK_SHIFT   (0U)
#define MACSEC_MACSEC_RXSAAIPOS_InPktsOK_WIDTH   (32U)
#define MACSEC_MACSEC_RXSAAIPOS_InPktsOK(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSAAIPOS_InPktsOK_SHIFT)) & MACSEC_MACSEC_RXSAAIPOS_InPktsOK_MASK)
/*! @} */

/*! @name MACSEC_RXSAAIPIS - RX Security Association A InPktsInvalid Statistic */
/*! @{ */

#define MACSEC_MACSEC_RXSAAIPIS_InPktsInvalid_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSAAIPIS_InPktsInvalid_SHIFT (0U)
#define MACSEC_MACSEC_RXSAAIPIS_InPktsInvalid_WIDTH (32U)
#define MACSEC_MACSEC_RXSAAIPIS_InPktsInvalid(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSAAIPIS_InPktsInvalid_SHIFT)) & MACSEC_MACSEC_RXSAAIPIS_InPktsInvalid_MASK)
/*! @} */

/*! @name MACSEC_RXSAAIPNVS - RX Security Association A InPktsNotValid Statistic */
/*! @{ */

#define MACSEC_MACSEC_RXSAAIPNVS_InPktsNotValid_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSAAIPNVS_InPktsNotValid_SHIFT (0U)
#define MACSEC_MACSEC_RXSAAIPNVS_InPktsNotValid_WIDTH (32U)
#define MACSEC_MACSEC_RXSAAIPNVS_InPktsNotValid(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSAAIPNVS_InPktsNotValid_SHIFT)) & MACSEC_MACSEC_RXSAAIPNVS_InPktsNotValid_MASK)
/*! @} */

/*! @name MACSEC_RXSABCS - RX Security Association B configuration and status */
/*! @{ */

#define MACSEC_MACSEC_RXSABCS_EN_MASK            (0x1U)
#define MACSEC_MACSEC_RXSABCS_EN_SHIFT           (0U)
#define MACSEC_MACSEC_RXSABCS_EN_WIDTH           (1U)
#define MACSEC_MACSEC_RXSABCS_EN(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSABCS_EN_SHIFT)) & MACSEC_MACSEC_RXSABCS_EN_MASK)

#define MACSEC_MACSEC_RXSABCS_AN_MASK            (0x6U)
#define MACSEC_MACSEC_RXSABCS_AN_SHIFT           (1U)
#define MACSEC_MACSEC_RXSABCS_AN_WIDTH           (2U)
#define MACSEC_MACSEC_RXSABCS_AN(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSABCS_AN_SHIFT)) & MACSEC_MACSEC_RXSABCS_AN_MASK)

#define MACSEC_MACSEC_RXSABCS_A_MASK             (0x80000000U)
#define MACSEC_MACSEC_RXSABCS_A_SHIFT            (31U)
#define MACSEC_MACSEC_RXSABCS_A_WIDTH            (1U)
#define MACSEC_MACSEC_RXSABCS_A(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSABCS_A_SHIFT)) & MACSEC_MACSEC_RXSABCS_A_MASK)
/*! @} */

/*! @name MACSEC_RXSABNPN - RX Security Association B nextPN */
/*! @{ */

#define MACSEC_MACSEC_RXSABNPN_nextPN_MASK       (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSABNPN_nextPN_SHIFT      (0U)
#define MACSEC_MACSEC_RXSABNPN_nextPN_WIDTH      (32U)
#define MACSEC_MACSEC_RXSABNPN_nextPN(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSABNPN_nextPN_SHIFT)) & MACSEC_MACSEC_RXSABNPN_nextPN_MASK)
/*! @} */

/*! @name MACSEC_RXSABXNPN - RX Security Association Extended B nextPN */
/*! @{ */

#define MACSEC_MACSEC_RXSABXNPN_ext_nextPN_MASK  (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSABXNPN_ext_nextPN_SHIFT (0U)
#define MACSEC_MACSEC_RXSABXNPN_ext_nextPN_WIDTH (32U)
#define MACSEC_MACSEC_RXSABXNPN_ext_nextPN(x)    (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSABXNPN_ext_nextPN_SHIFT)) & MACSEC_MACSEC_RXSABXNPN_ext_nextPN_MASK)
/*! @} */

/*! @name MACSEC_RXSABLPN - RX Security Association B lowestPN */
/*! @{ */

#define MACSEC_MACSEC_RXSABLPN_lowestPN_MASK     (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSABLPN_lowestPN_SHIFT    (0U)
#define MACSEC_MACSEC_RXSABLPN_lowestPN_WIDTH    (32U)
#define MACSEC_MACSEC_RXSABLPN_lowestPN(x)       (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSABLPN_lowestPN_SHIFT)) & MACSEC_MACSEC_RXSABLPN_lowestPN_MASK)
/*! @} */

/*! @name MACSEC_RXSABXLPN - RX Security Association Extended B lowestPN */
/*! @{ */

#define MACSEC_MACSEC_RXSABXLPN_ext_lowestPN_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSABXLPN_ext_lowestPN_SHIFT (0U)
#define MACSEC_MACSEC_RXSABXLPN_ext_lowestPN_WIDTH (32U)
#define MACSEC_MACSEC_RXSABXLPN_ext_lowestPN(x)  (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSABXLPN_ext_lowestPN_SHIFT)) & MACSEC_MACSEC_RXSABXLPN_ext_lowestPN_MASK)
/*! @} */

/*! @name MACSEC_RXSABIPOS - RX Security Association B InPktsOK Statistic */
/*! @{ */

#define MACSEC_MACSEC_RXSABIPOS_InPktsOK_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSABIPOS_InPktsOK_SHIFT   (0U)
#define MACSEC_MACSEC_RXSABIPOS_InPktsOK_WIDTH   (32U)
#define MACSEC_MACSEC_RXSABIPOS_InPktsOK(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSABIPOS_InPktsOK_SHIFT)) & MACSEC_MACSEC_RXSABIPOS_InPktsOK_MASK)
/*! @} */

/*! @name MACSEC_RXSABIPIS - RX Security Association B InPktsInvalid Statistic */
/*! @{ */

#define MACSEC_MACSEC_RXSABIPIS_InPktsInvalid_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSABIPIS_InPktsInvalid_SHIFT (0U)
#define MACSEC_MACSEC_RXSABIPIS_InPktsInvalid_WIDTH (32U)
#define MACSEC_MACSEC_RXSABIPIS_InPktsInvalid(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSABIPIS_InPktsInvalid_SHIFT)) & MACSEC_MACSEC_RXSABIPIS_InPktsInvalid_MASK)
/*! @} */

/*! @name MACSEC_RXSABIPNVS - RX Security Association B InPktsNotValid Statistic */
/*! @{ */

#define MACSEC_MACSEC_RXSABIPNVS_InPktsNotValid_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSABIPNVS_InPktsNotValid_SHIFT (0U)
#define MACSEC_MACSEC_RXSABIPNVS_InPktsNotValid_WIDTH (32U)
#define MACSEC_MACSEC_RXSABIPNVS_InPktsNotValid(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSABIPNVS_InPktsNotValid_SHIFT)) & MACSEC_MACSEC_RXSABIPNVS_InPktsNotValid_MASK)
/*! @} */

/*! @name MACSEC_TXSCI1H - TX Secure Channel Identifier first half */
/*! @{ */

#define MACSEC_MACSEC_TXSCI1H_TXSCI_MASK         (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCI1H_TXSCI_SHIFT        (0U)
#define MACSEC_MACSEC_TXSCI1H_TXSCI_WIDTH        (32U)
#define MACSEC_MACSEC_TXSCI1H_TXSCI(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCI1H_TXSCI_SHIFT)) & MACSEC_MACSEC_TXSCI1H_TXSCI_MASK)
/*! @} */

/*! @name MACSEC_TXSCI2H - TX Secure Channel Identifier second half */
/*! @{ */

#define MACSEC_MACSEC_TXSCI2H_TXSCI_MASK         (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCI2H_TXSCI_SHIFT        (0U)
#define MACSEC_MACSEC_TXSCI2H_TXSCI_WIDTH        (32U)
#define MACSEC_MACSEC_TXSCI2H_TXSCI(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCI2H_TXSCI_SHIFT)) & MACSEC_MACSEC_TXSCI2H_TXSCI_MASK)
/*! @} */

/*! @name MACSEC_IFOO1HS - ifOutOctets first half Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFOO1HS_ifOutOctets_MASK   (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFOO1HS_ifOutOctets_SHIFT  (0U)
#define MACSEC_MACSEC_IFOO1HS_ifOutOctets_WIDTH  (32U)
#define MACSEC_MACSEC_IFOO1HS_ifOutOctets(x)     (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFOO1HS_ifOutOctets_SHIFT)) & MACSEC_MACSEC_IFOO1HS_ifOutOctets_MASK)
/*! @} */

/*! @name MACSEC_IFOO2HS - ifOutOctets second half Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFOO2HS_ifOutOctets_MASK   (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFOO2HS_ifOutOctets_SHIFT  (0U)
#define MACSEC_MACSEC_IFOO2HS_ifOutOctets_WIDTH  (32U)
#define MACSEC_MACSEC_IFOO2HS_ifOutOctets(x)     (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFOO2HS_ifOutOctets_SHIFT)) & MACSEC_MACSEC_IFOO2HS_ifOutOctets_MASK)
/*! @} */

/*! @name MACSEC_IFOUPS - ifOutUcastPkts Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFOUPS_ifOutUcastPkts_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFOUPS_ifOutUcastPkts_SHIFT (0U)
#define MACSEC_MACSEC_IFOUPS_ifOutUcastPkts_WIDTH (32U)
#define MACSEC_MACSEC_IFOUPS_ifOutUcastPkts(x)   (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFOUPS_ifOutUcastPkts_SHIFT)) & MACSEC_MACSEC_IFOUPS_ifOutUcastPkts_MASK)
/*! @} */

/*! @name MACSEC_OPUS - OutPktsUntagged Statistic */
/*! @{ */

#define MACSEC_MACSEC_OPUS_OutPktsUntagged_MASK  (0xFFFFFFFFU)
#define MACSEC_MACSEC_OPUS_OutPktsUntagged_SHIFT (0U)
#define MACSEC_MACSEC_OPUS_OutPktsUntagged_WIDTH (32U)
#define MACSEC_MACSEC_OPUS_OutPktsUntagged(x)    (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_OPUS_OutPktsUntagged_SHIFT)) & MACSEC_MACSEC_OPUS_OutPktsUntagged_MASK)
/*! @} */

/*! @name MACSEC_IFOMPS - ifOutMulticastPkts Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFOMPS_ifOutMulticastPkts_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFOMPS_ifOutMulticastPkts_SHIFT (0U)
#define MACSEC_MACSEC_IFOMPS_ifOutMulticastPkts_WIDTH (32U)
#define MACSEC_MACSEC_IFOMPS_ifOutMulticastPkts(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFOMPS_ifOutMulticastPkts_SHIFT)) & MACSEC_MACSEC_IFOMPS_ifOutMulticastPkts_MASK)
/*! @} */

/*! @name MACSEC_IFOBPS - ifOutBroadcastPkts Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFOBPS_ifOutBroadcastPkts_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFOBPS_ifOutBroadcastPkts_SHIFT (0U)
#define MACSEC_MACSEC_IFOBPS_ifOutBroadcastPkts_WIDTH (32U)
#define MACSEC_MACSEC_IFOBPS_ifOutBroadcastPkts(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFOBPS_ifOutBroadcastPkts_SHIFT)) & MACSEC_MACSEC_IFOBPS_ifOutBroadcastPkts_MASK)
/*! @} */

/*! @name MACSEC_TXSCCFG - TX Secure Channel configuration */
/*! @{ */

#define MACSEC_MACSEC_TXSCCFG_USCB_MASK          (0x1U)
#define MACSEC_MACSEC_TXSCCFG_USCB_SHIFT         (0U)
#define MACSEC_MACSEC_TXSCCFG_USCB_WIDTH         (1U)
#define MACSEC_MACSEC_TXSCCFG_USCB(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCCFG_USCB_SHIFT)) & MACSEC_MACSEC_TXSCCFG_USCB_MASK)

#define MACSEC_MACSEC_TXSCCFG_UES_MASK           (0x2U)
#define MACSEC_MACSEC_TXSCCFG_UES_SHIFT          (1U)
#define MACSEC_MACSEC_TXSCCFG_UES_WIDTH          (1U)
#define MACSEC_MACSEC_TXSCCFG_UES(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCCFG_UES_SHIFT)) & MACSEC_MACSEC_TXSCCFG_UES_MASK)

#define MACSEC_MACSEC_TXSCCFG_AIS_MASK           (0x4U)
#define MACSEC_MACSEC_TXSCCFG_AIS_SHIFT          (2U)
#define MACSEC_MACSEC_TXSCCFG_AIS_WIDTH          (1U)
#define MACSEC_MACSEC_TXSCCFG_AIS(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCCFG_AIS_SHIFT)) & MACSEC_MACSEC_TXSCCFG_AIS_MASK)

#define MACSEC_MACSEC_TXSCCFG_PF_MASK            (0x8U)
#define MACSEC_MACSEC_TXSCCFG_PF_SHIFT           (3U)
#define MACSEC_MACSEC_TXSCCFG_PF_WIDTH           (1U)
#define MACSEC_MACSEC_TXSCCFG_PF(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCCFG_PF_SHIFT)) & MACSEC_MACSEC_TXSCCFG_PF_MASK)

#define MACSEC_MACSEC_TXSCCFG_CE_MASK            (0x10U)
#define MACSEC_MACSEC_TXSCCFG_CE_SHIFT           (4U)
#define MACSEC_MACSEC_TXSCCFG_CE_WIDTH           (1U)
#define MACSEC_MACSEC_TXSCCFG_CE(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCCFG_CE_SHIFT)) & MACSEC_MACSEC_TXSCCFG_CE_MASK)

#define MACSEC_MACSEC_TXSCCFG_CO_MASK            (0x3F00U)
#define MACSEC_MACSEC_TXSCCFG_CO_SHIFT           (8U)
#define MACSEC_MACSEC_TXSCCFG_CO_WIDTH           (6U)
#define MACSEC_MACSEC_TXSCCFG_CO(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCCFG_CO_SHIFT)) & MACSEC_MACSEC_TXSCCFG_CO_MASK)

#define MACSEC_MACSEC_TXSCCFG_SCE_MASK           (0x10000U)
#define MACSEC_MACSEC_TXSCCFG_SCE_SHIFT          (16U)
#define MACSEC_MACSEC_TXSCCFG_SCE_WIDTH          (1U)
#define MACSEC_MACSEC_TXSCCFG_SCE(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCCFG_SCE_SHIFT)) & MACSEC_MACSEC_TXSCCFG_SCE_MASK)

#define MACSEC_MACSEC_TXSCCFG_ASA_MASK           (0x20000U)
#define MACSEC_MACSEC_TXSCCFG_ASA_SHIFT          (17U)
#define MACSEC_MACSEC_TXSCCFG_ASA_WIDTH          (1U)
#define MACSEC_MACSEC_TXSCCFG_ASA(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCCFG_ASA_SHIFT)) & MACSEC_MACSEC_TXSCCFG_ASA_MASK)

#define MACSEC_MACSEC_TXSCCFG_AN_MASK            (0xC0000U)
#define MACSEC_MACSEC_TXSCCFG_AN_SHIFT           (18U)
#define MACSEC_MACSEC_TXSCCFG_AN_WIDTH           (2U)
#define MACSEC_MACSEC_TXSCCFG_AN(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCCFG_AN_SHIFT)) & MACSEC_MACSEC_TXSCCFG_AN_MASK)

#define MACSEC_MACSEC_TXSCCFG_CS_MASK            (0x3000000U)
#define MACSEC_MACSEC_TXSCCFG_CS_SHIFT           (24U)
#define MACSEC_MACSEC_TXSCCFG_CS_WIDTH           (2U)
#define MACSEC_MACSEC_TXSCCFG_CS(x)              (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCCFG_CS_SHIFT)) & MACSEC_MACSEC_TXSCCFG_CS_MASK)

#define MACSEC_MACSEC_TXSCCFG_TVM_MASK           (0x30000000U)
#define MACSEC_MACSEC_TXSCCFG_TVM_SHIFT          (28U)
#define MACSEC_MACSEC_TXSCCFG_TVM_WIDTH          (2U)
#define MACSEC_MACSEC_TXSCCFG_TVM(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCCFG_TVM_SHIFT)) & MACSEC_MACSEC_TXSCCFG_TVM_MASK)

#define MACSEC_MACSEC_TXSCCFG_TCM_MASK           (0x40000000U)
#define MACSEC_MACSEC_TXSCCFG_TCM_SHIFT          (30U)
#define MACSEC_MACSEC_TXSCCFG_TCM_WIDTH          (1U)
#define MACSEC_MACSEC_TXSCCFG_TCM(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCCFG_TCM_SHIFT)) & MACSEC_MACSEC_TXSCCFG_TCM_MASK)
/*! @} */

/*! @name MACSEC_OPTLS - OutPktsTooLong Statistic */
/*! @{ */

#define MACSEC_MACSEC_OPTLS_OutPktsTooLong_MASK  (0xFFFFFFFFU)
#define MACSEC_MACSEC_OPTLS_OutPktsTooLong_SHIFT (0U)
#define MACSEC_MACSEC_OPTLS_OutPktsTooLong_WIDTH (32U)
#define MACSEC_MACSEC_OPTLS_OutPktsTooLong(x)    (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_OPTLS_OutPktsTooLong_SHIFT)) & MACSEC_MACSEC_OPTLS_OutPktsTooLong_MASK)
/*! @} */

/*! @name MACSEC_OOP1HS - OutOctetsProtected first half Statistic */
/*! @{ */

#define MACSEC_MACSEC_OOP1HS_OutOctetsProtected_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_OOP1HS_OutOctetsProtected_SHIFT (0U)
#define MACSEC_MACSEC_OOP1HS_OutOctetsProtected_WIDTH (32U)
#define MACSEC_MACSEC_OOP1HS_OutOctetsProtected(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_OOP1HS_OutOctetsProtected_SHIFT)) & MACSEC_MACSEC_OOP1HS_OutOctetsProtected_MASK)
/*! @} */

/*! @name MACSEC_OOP2HS - OutOctetsProtected second half Statistic */
/*! @{ */

#define MACSEC_MACSEC_OOP2HS_OutOctetsProtected_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_OOP2HS_OutOctetsProtected_SHIFT (0U)
#define MACSEC_MACSEC_OOP2HS_OutOctetsProtected_WIDTH (32U)
#define MACSEC_MACSEC_OOP2HS_OutOctetsProtected(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_OOP2HS_OutOctetsProtected_SHIFT)) & MACSEC_MACSEC_OOP2HS_OutOctetsProtected_MASK)
/*! @} */

/*! @name MACSEC_OOE1HS - OutOctetsEncrypted first half Statistic */
/*! @{ */

#define MACSEC_MACSEC_OOE1HS_OutOctetsEncrypted_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_OOE1HS_OutOctetsEncrypted_SHIFT (0U)
#define MACSEC_MACSEC_OOE1HS_OutOctetsEncrypted_WIDTH (32U)
#define MACSEC_MACSEC_OOE1HS_OutOctetsEncrypted(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_OOE1HS_OutOctetsEncrypted_SHIFT)) & MACSEC_MACSEC_OOE1HS_OutOctetsEncrypted_MASK)
/*! @} */

/*! @name MACSEC_OOE2HS - OutOctetsEncrypted second half Statistic */
/*! @{ */

#define MACSEC_MACSEC_OOE2HS_OutOctetsEncrypted_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_OOE2HS_OutOctetsEncrypted_SHIFT (0U)
#define MACSEC_MACSEC_OOE2HS_OutOctetsEncrypted_WIDTH (32U)
#define MACSEC_MACSEC_OOE2HS_OutOctetsEncrypted(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_OOE2HS_OutOctetsEncrypted_SHIFT)) & MACSEC_MACSEC_OOE2HS_OutOctetsEncrypted_MASK)
/*! @} */

/*! @name MACSEC_TXSAACS - TX Security Association A configuration and status */
/*! @{ */

#define MACSEC_MACSEC_TXSAACS_A_MASK             (0x80000000U)
#define MACSEC_MACSEC_TXSAACS_A_SHIFT            (31U)
#define MACSEC_MACSEC_TXSAACS_A_WIDTH            (1U)
#define MACSEC_MACSEC_TXSAACS_A(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSAACS_A_SHIFT)) & MACSEC_MACSEC_TXSAACS_A_MASK)
/*! @} */

/*! @name MACSEC_TXSAANPN - TX Security Association A nextPN */
/*! @{ */

#define MACSEC_MACSEC_TXSAANPN_nextPN_MASK       (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSAANPN_nextPN_SHIFT      (0U)
#define MACSEC_MACSEC_TXSAANPN_nextPN_WIDTH      (32U)
#define MACSEC_MACSEC_TXSAANPN_nextPN(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSAANPN_nextPN_SHIFT)) & MACSEC_MACSEC_TXSAANPN_nextPN_MASK)
/*! @} */

/*! @name MACSEC_TXSAAXNPN - TX Security Association Extended A nextPN */
/*! @{ */

#define MACSEC_MACSEC_TXSAAXNPN_ext_nextPN_MASK  (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSAAXNPN_ext_nextPN_SHIFT (0U)
#define MACSEC_MACSEC_TXSAAXNPN_ext_nextPN_WIDTH (32U)
#define MACSEC_MACSEC_TXSAAXNPN_ext_nextPN(x)    (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSAAXNPN_ext_nextPN_SHIFT)) & MACSEC_MACSEC_TXSAAXNPN_ext_nextPN_MASK)
/*! @} */

/*! @name MACSEC_TXSAAOPPS - TX Security Association A OutPktsProtected Statistic */
/*! @{ */

#define MACSEC_MACSEC_TXSAAOPPS_OutPktsProtected_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSAAOPPS_OutPktsProtected_SHIFT (0U)
#define MACSEC_MACSEC_TXSAAOPPS_OutPktsProtected_WIDTH (32U)
#define MACSEC_MACSEC_TXSAAOPPS_OutPktsProtected(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSAAOPPS_OutPktsProtected_SHIFT)) & MACSEC_MACSEC_TXSAAOPPS_OutPktsProtected_MASK)
/*! @} */

/*! @name MACSEC_TXSAAOPES - TX Security Association A OutPktsEncrypted Statistic */
/*! @{ */

#define MACSEC_MACSEC_TXSAAOPES_OutPktsEncrypted_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSAAOPES_OutPktsEncrypted_SHIFT (0U)
#define MACSEC_MACSEC_TXSAAOPES_OutPktsEncrypted_WIDTH (32U)
#define MACSEC_MACSEC_TXSAAOPES_OutPktsEncrypted(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSAAOPES_OutPktsEncrypted_SHIFT)) & MACSEC_MACSEC_TXSAAOPES_OutPktsEncrypted_MASK)
/*! @} */

/*! @name MACSEC_TXSABCS - TX Security Association B configuration and status */
/*! @{ */

#define MACSEC_MACSEC_TXSABCS_A_MASK             (0x80000000U)
#define MACSEC_MACSEC_TXSABCS_A_SHIFT            (31U)
#define MACSEC_MACSEC_TXSABCS_A_WIDTH            (1U)
#define MACSEC_MACSEC_TXSABCS_A(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSABCS_A_SHIFT)) & MACSEC_MACSEC_TXSABCS_A_MASK)
/*! @} */

/*! @name MACSEC_TXSABNPN - TX Security Association B nextPN */
/*! @{ */

#define MACSEC_MACSEC_TXSABNPN_nextPN_MASK       (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSABNPN_nextPN_SHIFT      (0U)
#define MACSEC_MACSEC_TXSABNPN_nextPN_WIDTH      (32U)
#define MACSEC_MACSEC_TXSABNPN_nextPN(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSABNPN_nextPN_SHIFT)) & MACSEC_MACSEC_TXSABNPN_nextPN_MASK)
/*! @} */

/*! @name MACSEC_TXSABXNPN - TX Security Association Extended B nextPN */
/*! @{ */

#define MACSEC_MACSEC_TXSABXNPN_ext_nextPN_MASK  (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSABXNPN_ext_nextPN_SHIFT (0U)
#define MACSEC_MACSEC_TXSABXNPN_ext_nextPN_WIDTH (32U)
#define MACSEC_MACSEC_TXSABXNPN_ext_nextPN(x)    (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSABXNPN_ext_nextPN_SHIFT)) & MACSEC_MACSEC_TXSABXNPN_ext_nextPN_MASK)
/*! @} */

/*! @name MACSEC_TXSABOPPS - TX Security Association B OutPktsProtected Statistic */
/*! @{ */

#define MACSEC_MACSEC_TXSABOPPS_OutPktsProtected_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSABOPPS_OutPktsProtected_SHIFT (0U)
#define MACSEC_MACSEC_TXSABOPPS_OutPktsProtected_WIDTH (32U)
#define MACSEC_MACSEC_TXSABOPPS_OutPktsProtected(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSABOPPS_OutPktsProtected_SHIFT)) & MACSEC_MACSEC_TXSABOPPS_OutPktsProtected_MASK)
/*! @} */

/*! @name MACSEC_TXSABOPES - TX Security Association B OutPktsEncrypted Statistic */
/*! @{ */

#define MACSEC_MACSEC_TXSABOPES_OutPktsEncrypted_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSABOPES_OutPktsEncrypted_SHIFT (0U)
#define MACSEC_MACSEC_TXSABOPES_OutPktsEncrypted_WIDTH (32U)
#define MACSEC_MACSEC_TXSABOPES_OutPktsEncrypted(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSABOPES_OutPktsEncrypted_SHIFT)) & MACSEC_MACSEC_TXSABOPES_OutPktsEncrypted_MASK)
/*! @} */

/*! @name MACSEC_IP_REV_1 - MACsec IP Block Revision 1 register */
/*! @{ */

#define MACSEC_MACSEC_IP_REV_1_IP_MN_MASK        (0xFFU)
#define MACSEC_MACSEC_IP_REV_1_IP_MN_SHIFT       (0U)
#define MACSEC_MACSEC_IP_REV_1_IP_MN_WIDTH       (8U)
#define MACSEC_MACSEC_IP_REV_1_IP_MN(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IP_REV_1_IP_MN_SHIFT)) & MACSEC_MACSEC_IP_REV_1_IP_MN_MASK)

#define MACSEC_MACSEC_IP_REV_1_IP_MJ_MASK        (0xFF00U)
#define MACSEC_MACSEC_IP_REV_1_IP_MJ_SHIFT       (8U)
#define MACSEC_MACSEC_IP_REV_1_IP_MJ_WIDTH       (8U)
#define MACSEC_MACSEC_IP_REV_1_IP_MJ(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IP_REV_1_IP_MJ_SHIFT)) & MACSEC_MACSEC_IP_REV_1_IP_MJ_MASK)

#define MACSEC_MACSEC_IP_REV_1_IP_ID_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_IP_REV_1_IP_ID_SHIFT       (16U)
#define MACSEC_MACSEC_IP_REV_1_IP_ID_WIDTH       (16U)
#define MACSEC_MACSEC_IP_REV_1_IP_ID(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IP_REV_1_IP_ID_SHIFT)) & MACSEC_MACSEC_IP_REV_1_IP_ID_MASK)
/*! @} */

/*! @name MACSEC_IP_REV_2 - MACsec IP Block Revision 2 register */
/*! @{ */

#define MACSEC_MACSEC_IP_REV_2_IP_CFG_MASK       (0xFFU)
#define MACSEC_MACSEC_IP_REV_2_IP_CFG_SHIFT      (0U)
#define MACSEC_MACSEC_IP_REV_2_IP_CFG_WIDTH      (8U)
#define MACSEC_MACSEC_IP_REV_2_IP_CFG(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IP_REV_2_IP_CFG_SHIFT)) & MACSEC_MACSEC_IP_REV_2_IP_CFG_MASK)

#define MACSEC_MACSEC_IP_REV_2_IP_ERR_MASK       (0xFF00U)
#define MACSEC_MACSEC_IP_REV_2_IP_ERR_SHIFT      (8U)
#define MACSEC_MACSEC_IP_REV_2_IP_ERR_WIDTH      (8U)
#define MACSEC_MACSEC_IP_REV_2_IP_ERR(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IP_REV_2_IP_ERR_SHIFT)) & MACSEC_MACSEC_IP_REV_2_IP_ERR_MASK)

#define MACSEC_MACSEC_IP_REV_2_IP_INT_MASK       (0xFF0000U)
#define MACSEC_MACSEC_IP_REV_2_IP_INT_SHIFT      (16U)
#define MACSEC_MACSEC_IP_REV_2_IP_INT_WIDTH      (8U)
#define MACSEC_MACSEC_IP_REV_2_IP_INT(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IP_REV_2_IP_INT_SHIFT)) & MACSEC_MACSEC_IP_REV_2_IP_INT_MASK)
/*! @} */

/*! @name MACSEC_EVR - MACsec Event Register */
/*! @{ */

#define MACSEC_MACSEC_EVR_TS7R_MASK              (0x1000000U)
#define MACSEC_MACSEC_EVR_TS7R_SHIFT             (24U)
#define MACSEC_MACSEC_EVR_TS7R_WIDTH             (1U)
#define MACSEC_MACSEC_EVR_TS7R(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVR_TS7R_SHIFT)) & MACSEC_MACSEC_EVR_TS7R_MASK)

#define MACSEC_MACSEC_EVR_TS6R_MASK              (0x2000000U)
#define MACSEC_MACSEC_EVR_TS6R_SHIFT             (25U)
#define MACSEC_MACSEC_EVR_TS6R_WIDTH             (1U)
#define MACSEC_MACSEC_EVR_TS6R(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVR_TS6R_SHIFT)) & MACSEC_MACSEC_EVR_TS6R_MASK)

#define MACSEC_MACSEC_EVR_TS5R_MASK              (0x4000000U)
#define MACSEC_MACSEC_EVR_TS5R_SHIFT             (26U)
#define MACSEC_MACSEC_EVR_TS5R_WIDTH             (1U)
#define MACSEC_MACSEC_EVR_TS5R(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVR_TS5R_SHIFT)) & MACSEC_MACSEC_EVR_TS5R_MASK)

#define MACSEC_MACSEC_EVR_TS4R_MASK              (0x8000000U)
#define MACSEC_MACSEC_EVR_TS4R_SHIFT             (27U)
#define MACSEC_MACSEC_EVR_TS4R_WIDTH             (1U)
#define MACSEC_MACSEC_EVR_TS4R(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVR_TS4R_SHIFT)) & MACSEC_MACSEC_EVR_TS4R_MASK)

#define MACSEC_MACSEC_EVR_TS3R_MASK              (0x10000000U)
#define MACSEC_MACSEC_EVR_TS3R_SHIFT             (28U)
#define MACSEC_MACSEC_EVR_TS3R_WIDTH             (1U)
#define MACSEC_MACSEC_EVR_TS3R(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVR_TS3R_SHIFT)) & MACSEC_MACSEC_EVR_TS3R_MASK)

#define MACSEC_MACSEC_EVR_TS2R_MASK              (0x20000000U)
#define MACSEC_MACSEC_EVR_TS2R_SHIFT             (29U)
#define MACSEC_MACSEC_EVR_TS2R_WIDTH             (1U)
#define MACSEC_MACSEC_EVR_TS2R(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVR_TS2R_SHIFT)) & MACSEC_MACSEC_EVR_TS2R_MASK)

#define MACSEC_MACSEC_EVR_TS1R_MASK              (0x40000000U)
#define MACSEC_MACSEC_EVR_TS1R_SHIFT             (30U)
#define MACSEC_MACSEC_EVR_TS1R_WIDTH             (1U)
#define MACSEC_MACSEC_EVR_TS1R(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVR_TS1R_SHIFT)) & MACSEC_MACSEC_EVR_TS1R_MASK)

#define MACSEC_MACSEC_EVR_TS0R_MASK              (0x80000000U)
#define MACSEC_MACSEC_EVR_TS0R_SHIFT             (31U)
#define MACSEC_MACSEC_EVR_TS0R_WIDTH             (1U)
#define MACSEC_MACSEC_EVR_TS0R(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVR_TS0R_SHIFT)) & MACSEC_MACSEC_EVR_TS0R_MASK)
/*! @} */

/*! @name MACSEC_EVER - MACsec Event Enable Register */
/*! @{ */

#define MACSEC_MACSEC_EVER_TS7R_MASK             (0x1000000U)
#define MACSEC_MACSEC_EVER_TS7R_SHIFT            (24U)
#define MACSEC_MACSEC_EVER_TS7R_WIDTH            (1U)
#define MACSEC_MACSEC_EVER_TS7R(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVER_TS7R_SHIFT)) & MACSEC_MACSEC_EVER_TS7R_MASK)

#define MACSEC_MACSEC_EVER_TS6R_MASK             (0x2000000U)
#define MACSEC_MACSEC_EVER_TS6R_SHIFT            (25U)
#define MACSEC_MACSEC_EVER_TS6R_WIDTH            (1U)
#define MACSEC_MACSEC_EVER_TS6R(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVER_TS6R_SHIFT)) & MACSEC_MACSEC_EVER_TS6R_MASK)

#define MACSEC_MACSEC_EVER_TS5R_MASK             (0x4000000U)
#define MACSEC_MACSEC_EVER_TS5R_SHIFT            (26U)
#define MACSEC_MACSEC_EVER_TS5R_WIDTH            (1U)
#define MACSEC_MACSEC_EVER_TS5R(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVER_TS5R_SHIFT)) & MACSEC_MACSEC_EVER_TS5R_MASK)

#define MACSEC_MACSEC_EVER_TS4R_MASK             (0x8000000U)
#define MACSEC_MACSEC_EVER_TS4R_SHIFT            (27U)
#define MACSEC_MACSEC_EVER_TS4R_WIDTH            (1U)
#define MACSEC_MACSEC_EVER_TS4R(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVER_TS4R_SHIFT)) & MACSEC_MACSEC_EVER_TS4R_MASK)

#define MACSEC_MACSEC_EVER_TS3R_MASK             (0x10000000U)
#define MACSEC_MACSEC_EVER_TS3R_SHIFT            (28U)
#define MACSEC_MACSEC_EVER_TS3R_WIDTH            (1U)
#define MACSEC_MACSEC_EVER_TS3R(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVER_TS3R_SHIFT)) & MACSEC_MACSEC_EVER_TS3R_MASK)

#define MACSEC_MACSEC_EVER_TS2R_MASK             (0x20000000U)
#define MACSEC_MACSEC_EVER_TS2R_SHIFT            (29U)
#define MACSEC_MACSEC_EVER_TS2R_WIDTH            (1U)
#define MACSEC_MACSEC_EVER_TS2R(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVER_TS2R_SHIFT)) & MACSEC_MACSEC_EVER_TS2R_MASK)

#define MACSEC_MACSEC_EVER_TS1R_MASK             (0x40000000U)
#define MACSEC_MACSEC_EVER_TS1R_SHIFT            (30U)
#define MACSEC_MACSEC_EVER_TS1R_WIDTH            (1U)
#define MACSEC_MACSEC_EVER_TS1R(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVER_TS1R_SHIFT)) & MACSEC_MACSEC_EVER_TS1R_MASK)

#define MACSEC_MACSEC_EVER_TS0R_MASK             (0x80000000U)
#define MACSEC_MACSEC_EVER_TS0R_SHIFT            (31U)
#define MACSEC_MACSEC_EVER_TS0R_WIDTH            (1U)
#define MACSEC_MACSEC_EVER_TS0R(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_EVER_TS0R_SHIFT)) & MACSEC_MACSEC_EVER_TS0R_MASK)
/*! @} */

/*! @name MACSEC_ERR - MACsec Error Register */
/*! @{ */

#define MACSEC_MACSEC_ERR_ECCE_MASK              (0x1U)
#define MACSEC_MACSEC_ERR_ECCE_SHIFT             (0U)
#define MACSEC_MACSEC_ERR_ECCE_WIDTH             (1U)
#define MACSEC_MACSEC_ERR_ECCE(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERR_ECCE_SHIFT)) & MACSEC_MACSEC_ERR_ECCE_MASK)

#define MACSEC_MACSEC_ERR_TS7E_MASK              (0x1000000U)
#define MACSEC_MACSEC_ERR_TS7E_SHIFT             (24U)
#define MACSEC_MACSEC_ERR_TS7E_WIDTH             (1U)
#define MACSEC_MACSEC_ERR_TS7E(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERR_TS7E_SHIFT)) & MACSEC_MACSEC_ERR_TS7E_MASK)

#define MACSEC_MACSEC_ERR_TS6E_MASK              (0x2000000U)
#define MACSEC_MACSEC_ERR_TS6E_SHIFT             (25U)
#define MACSEC_MACSEC_ERR_TS6E_WIDTH             (1U)
#define MACSEC_MACSEC_ERR_TS6E(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERR_TS6E_SHIFT)) & MACSEC_MACSEC_ERR_TS6E_MASK)

#define MACSEC_MACSEC_ERR_TS5E_MASK              (0x4000000U)
#define MACSEC_MACSEC_ERR_TS5E_SHIFT             (26U)
#define MACSEC_MACSEC_ERR_TS5E_WIDTH             (1U)
#define MACSEC_MACSEC_ERR_TS5E(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERR_TS5E_SHIFT)) & MACSEC_MACSEC_ERR_TS5E_MASK)

#define MACSEC_MACSEC_ERR_TS4E_MASK              (0x8000000U)
#define MACSEC_MACSEC_ERR_TS4E_SHIFT             (27U)
#define MACSEC_MACSEC_ERR_TS4E_WIDTH             (1U)
#define MACSEC_MACSEC_ERR_TS4E(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERR_TS4E_SHIFT)) & MACSEC_MACSEC_ERR_TS4E_MASK)

#define MACSEC_MACSEC_ERR_TS3E_MASK              (0x10000000U)
#define MACSEC_MACSEC_ERR_TS3E_SHIFT             (28U)
#define MACSEC_MACSEC_ERR_TS3E_WIDTH             (1U)
#define MACSEC_MACSEC_ERR_TS3E(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERR_TS3E_SHIFT)) & MACSEC_MACSEC_ERR_TS3E_MASK)

#define MACSEC_MACSEC_ERR_TS2E_MASK              (0x20000000U)
#define MACSEC_MACSEC_ERR_TS2E_SHIFT             (29U)
#define MACSEC_MACSEC_ERR_TS2E_WIDTH             (1U)
#define MACSEC_MACSEC_ERR_TS2E(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERR_TS2E_SHIFT)) & MACSEC_MACSEC_ERR_TS2E_MASK)

#define MACSEC_MACSEC_ERR_TS1E_MASK              (0x40000000U)
#define MACSEC_MACSEC_ERR_TS1E_SHIFT             (30U)
#define MACSEC_MACSEC_ERR_TS1E_WIDTH             (1U)
#define MACSEC_MACSEC_ERR_TS1E(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERR_TS1E_SHIFT)) & MACSEC_MACSEC_ERR_TS1E_MASK)

#define MACSEC_MACSEC_ERR_TS0E_MASK              (0x80000000U)
#define MACSEC_MACSEC_ERR_TS0E_SHIFT             (31U)
#define MACSEC_MACSEC_ERR_TS0E_WIDTH             (1U)
#define MACSEC_MACSEC_ERR_TS0E(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERR_TS0E_SHIFT)) & MACSEC_MACSEC_ERR_TS0E_MASK)
/*! @} */

/*! @name MACSEC_ERER - MACsec Error Enable Register */
/*! @{ */

#define MACSEC_MACSEC_ERER_ECCE_MASK             (0x1U)
#define MACSEC_MACSEC_ERER_ECCE_SHIFT            (0U)
#define MACSEC_MACSEC_ERER_ECCE_WIDTH            (1U)
#define MACSEC_MACSEC_ERER_ECCE(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERER_ECCE_SHIFT)) & MACSEC_MACSEC_ERER_ECCE_MASK)

#define MACSEC_MACSEC_ERER_TS7E_MASK             (0x1000000U)
#define MACSEC_MACSEC_ERER_TS7E_SHIFT            (24U)
#define MACSEC_MACSEC_ERER_TS7E_WIDTH            (1U)
#define MACSEC_MACSEC_ERER_TS7E(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERER_TS7E_SHIFT)) & MACSEC_MACSEC_ERER_TS7E_MASK)

#define MACSEC_MACSEC_ERER_TS6E_MASK             (0x2000000U)
#define MACSEC_MACSEC_ERER_TS6E_SHIFT            (25U)
#define MACSEC_MACSEC_ERER_TS6E_WIDTH            (1U)
#define MACSEC_MACSEC_ERER_TS6E(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERER_TS6E_SHIFT)) & MACSEC_MACSEC_ERER_TS6E_MASK)

#define MACSEC_MACSEC_ERER_TS5E_MASK             (0x4000000U)
#define MACSEC_MACSEC_ERER_TS5E_SHIFT            (26U)
#define MACSEC_MACSEC_ERER_TS5E_WIDTH            (1U)
#define MACSEC_MACSEC_ERER_TS5E(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERER_TS5E_SHIFT)) & MACSEC_MACSEC_ERER_TS5E_MASK)

#define MACSEC_MACSEC_ERER_TS4E_MASK             (0x8000000U)
#define MACSEC_MACSEC_ERER_TS4E_SHIFT            (27U)
#define MACSEC_MACSEC_ERER_TS4E_WIDTH            (1U)
#define MACSEC_MACSEC_ERER_TS4E(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERER_TS4E_SHIFT)) & MACSEC_MACSEC_ERER_TS4E_MASK)

#define MACSEC_MACSEC_ERER_TS3E_MASK             (0x10000000U)
#define MACSEC_MACSEC_ERER_TS3E_SHIFT            (28U)
#define MACSEC_MACSEC_ERER_TS3E_WIDTH            (1U)
#define MACSEC_MACSEC_ERER_TS3E(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERER_TS3E_SHIFT)) & MACSEC_MACSEC_ERER_TS3E_MASK)

#define MACSEC_MACSEC_ERER_TS2E_MASK             (0x20000000U)
#define MACSEC_MACSEC_ERER_TS2E_SHIFT            (29U)
#define MACSEC_MACSEC_ERER_TS2E_WIDTH            (1U)
#define MACSEC_MACSEC_ERER_TS2E(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERER_TS2E_SHIFT)) & MACSEC_MACSEC_ERER_TS2E_MASK)

#define MACSEC_MACSEC_ERER_TS1E_MASK             (0x40000000U)
#define MACSEC_MACSEC_ERER_TS1E_SHIFT            (30U)
#define MACSEC_MACSEC_ERER_TS1E_WIDTH            (1U)
#define MACSEC_MACSEC_ERER_TS1E(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERER_TS1E_SHIFT)) & MACSEC_MACSEC_ERER_TS1E_MASK)

#define MACSEC_MACSEC_ERER_TS0E_MASK             (0x80000000U)
#define MACSEC_MACSEC_ERER_TS0E_SHIFT            (31U)
#define MACSEC_MACSEC_ERER_TS0E_WIDTH            (1U)
#define MACSEC_MACSEC_ERER_TS0E(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_ERER_TS0E_SHIFT)) & MACSEC_MACSEC_ERER_TS0E_MASK)
/*! @} */

/*! @name MACSEC_MEEC - MACsec Memory ECC Error Capture Register */
/*! @{ */

#define MACSEC_MACSEC_MEEC_MEMADDR_MASK          (0x3FFU)
#define MACSEC_MACSEC_MEEC_MEMADDR_SHIFT         (0U)
#define MACSEC_MACSEC_MEEC_MEMADDR_WIDTH         (10U)
#define MACSEC_MACSEC_MEEC_MEMADDR(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_MEEC_MEMADDR_SHIFT)) & MACSEC_MACSEC_MEEC_MEMADDR_MASK)

#define MACSEC_MACSEC_MEEC_SERCNT_MASK           (0xFF0000U)
#define MACSEC_MACSEC_MEEC_SERCNT_SHIFT          (16U)
#define MACSEC_MACSEC_MEEC_SERCNT_WIDTH          (8U)
#define MACSEC_MACSEC_MEEC_SERCNT(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_MEEC_SERCNT_SHIFT)) & MACSEC_MACSEC_MEEC_SERCNT_MASK)

#define MACSEC_MACSEC_MEEC_CET_MASK              (0x40000000U)
#define MACSEC_MACSEC_MEEC_CET_SHIFT             (30U)
#define MACSEC_MACSEC_MEEC_CET_WIDTH             (1U)
#define MACSEC_MACSEC_MEEC_CET(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_MEEC_CET_SHIFT)) & MACSEC_MACSEC_MEEC_CET_MASK)

#define MACSEC_MACSEC_MEEC_CAP_MASK              (0x80000000U)
#define MACSEC_MACSEC_MEEC_CAP_SHIFT             (31U)
#define MACSEC_MACSEC_MEEC_CAP_WIDTH             (1U)
#define MACSEC_MACSEC_MEEC_CAP(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_MEEC_CAP_SHIFT)) & MACSEC_MACSEC_MEEC_CAP_MASK)
/*! @} */

/*! @name MACSEC_STATUS - MACsec Idle status Register */
/*! @{ */

#define MACSEC_MACSEC_STATUS_I_MASK              (0x1U)
#define MACSEC_MACSEC_STATUS_I_SHIFT             (0U)
#define MACSEC_MACSEC_STATUS_I_WIDTH             (1U)
#define MACSEC_MACSEC_STATUS_I(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_STATUS_I_SHIFT)) & MACSEC_MACSEC_STATUS_I_MASK)
/*! @} */

/*! @name MACSEC_IFIOCP1HS - ifInOctetsCp first half Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIOCP1HS_ifInOctetsCp_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIOCP1HS_ifInOctetsCp_SHIFT (0U)
#define MACSEC_MACSEC_IFIOCP1HS_ifInOctetsCp_WIDTH (32U)
#define MACSEC_MACSEC_IFIOCP1HS_ifInOctetsCp(x)  (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIOCP1HS_ifInOctetsCp_SHIFT)) & MACSEC_MACSEC_IFIOCP1HS_ifInOctetsCp_MASK)
/*! @} */

/*! @name MACSEC_IFIOCP2HS - ifInOctetsCp second half Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIOCP2HS_ifInOctetsCp_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIOCP2HS_ifInOctetsCp_SHIFT (0U)
#define MACSEC_MACSEC_IFIOCP2HS_ifInOctetsCp_WIDTH (32U)
#define MACSEC_MACSEC_IFIOCP2HS_ifInOctetsCp(x)  (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIOCP2HS_ifInOctetsCp_SHIFT)) & MACSEC_MACSEC_IFIOCP2HS_ifInOctetsCp_MASK)
/*! @} */

/*! @name MACSEC_IFIUPCPS - ifInUcastPktsCp Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIUPCPS_ifInUcastPktsCp_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIUPCPS_ifInUcastPktsCp_SHIFT (0U)
#define MACSEC_MACSEC_IFIUPCPS_ifInUcastPktsCp_WIDTH (32U)
#define MACSEC_MACSEC_IFIUPCPS_ifInUcastPktsCp(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIUPCPS_ifInUcastPktsCp_SHIFT)) & MACSEC_MACSEC_IFIUPCPS_ifInUcastPktsCp_MASK)
/*! @} */

/*! @name MACSEC_IFIOUP1HS - ifInOctetsUp first half Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIOUP1HS_ifInOctetsUp_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIOUP1HS_ifInOctetsUp_SHIFT (0U)
#define MACSEC_MACSEC_IFIOUP1HS_ifInOctetsUp_WIDTH (32U)
#define MACSEC_MACSEC_IFIOUP1HS_ifInOctetsUp(x)  (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIOUP1HS_ifInOctetsUp_SHIFT)) & MACSEC_MACSEC_IFIOUP1HS_ifInOctetsUp_MASK)
/*! @} */

/*! @name MACSEC_IFIOUP2HS - ifInOctetsUp second half Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIOUP2HS_ifInOctetsUp_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIOUP2HS_ifInOctetsUp_SHIFT (0U)
#define MACSEC_MACSEC_IFIOUP2HS_ifInOctetsUp_WIDTH (32U)
#define MACSEC_MACSEC_IFIOUP2HS_ifInOctetsUp(x)  (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIOUP2HS_ifInOctetsUp_SHIFT)) & MACSEC_MACSEC_IFIOUP2HS_ifInOctetsUp_MASK)
/*! @} */

/*! @name MACSEC_IFIUPUPS - ifInUcastPktsUp Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIUPUPS_ifInUcastPktsUp_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIUPUPS_ifInUcastPktsUp_SHIFT (0U)
#define MACSEC_MACSEC_IFIUPUPS_ifInUcastPktsUp_WIDTH (32U)
#define MACSEC_MACSEC_IFIUPUPS_ifInUcastPktsUp(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIUPUPS_ifInUcastPktsUp_SHIFT)) & MACSEC_MACSEC_IFIUPUPS_ifInUcastPktsUp_MASK)
/*! @} */

/*! @name MACSEC_IFIMPCPS - ifInMulticastPktsCp Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIMPCPS_ifInMulticastPktsCp_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIMPCPS_ifInMulticastPktsCp_SHIFT (0U)
#define MACSEC_MACSEC_IFIMPCPS_ifInMulticastPktsCp_WIDTH (32U)
#define MACSEC_MACSEC_IFIMPCPS_ifInMulticastPktsCp(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIMPCPS_ifInMulticastPktsCp_SHIFT)) & MACSEC_MACSEC_IFIMPCPS_ifInMulticastPktsCp_MASK)
/*! @} */

/*! @name MACSEC_IFIBPCPS - ifInBroadcastPktsCp Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIBPCPS_ifInBroadcastPktsCp_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIBPCPS_ifInBroadcastPktsCp_SHIFT (0U)
#define MACSEC_MACSEC_IFIBPCPS_ifInBroadcastPktsCp_WIDTH (32U)
#define MACSEC_MACSEC_IFIBPCPS_ifInBroadcastPktsCp(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIBPCPS_ifInBroadcastPktsCp_SHIFT)) & MACSEC_MACSEC_IFIBPCPS_ifInBroadcastPktsCp_MASK)
/*! @} */

/*! @name MACSEC_IFIMPUPS - ifInMulticastPktsUp Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIMPUPS_ifInMulticastPktsUp_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIMPUPS_ifInMulticastPktsUp_SHIFT (0U)
#define MACSEC_MACSEC_IFIMPUPS_ifInMulticastPktsUp_WIDTH (32U)
#define MACSEC_MACSEC_IFIMPUPS_ifInMulticastPktsUp(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIMPUPS_ifInMulticastPktsUp_SHIFT)) & MACSEC_MACSEC_IFIMPUPS_ifInMulticastPktsUp_MASK)
/*! @} */

/*! @name MACSEC_IFIBPUPS - ifInBroadcastPktsUp Statistic */
/*! @{ */

#define MACSEC_MACSEC_IFIBPUPS_ifInBroadcastPktsUp_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IFIBPUPS_ifInBroadcastPktsUp_SHIFT (0U)
#define MACSEC_MACSEC_IFIBPUPS_ifInBroadcastPktsUp_WIDTH (32U)
#define MACSEC_MACSEC_IFIBPUPS_ifInBroadcastPktsUp(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IFIBPUPS_ifInBroadcastPktsUp_SHIFT)) & MACSEC_MACSEC_IFIBPUPS_ifInBroadcastPktsUp_MASK)
/*! @} */

/*! @name MACSEC_INPWTS - InPktsWithoutTag Statistic */
/*! @{ */

#define MACSEC_MACSEC_INPWTS_InPktsWithoutTag_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_INPWTS_InPktsWithoutTag_SHIFT (0U)
#define MACSEC_MACSEC_INPWTS_InPktsWithoutTag_WIDTH (32U)
#define MACSEC_MACSEC_INPWTS_InPktsWithoutTag(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_INPWTS_InPktsWithoutTag_SHIFT)) & MACSEC_MACSEC_INPWTS_InPktsWithoutTag_MASK)
/*! @} */

/*! @name MACSEC_INPKAYS - InPktsKaY Statistic */
/*! @{ */

#define MACSEC_MACSEC_INPKAYS_InPktsKaY_MASK     (0xFFFFFFFFU)
#define MACSEC_MACSEC_INPKAYS_InPktsKaY_SHIFT    (0U)
#define MACSEC_MACSEC_INPKAYS_InPktsKaY_WIDTH    (32U)
#define MACSEC_MACSEC_INPKAYS_InPktsKaY(x)       (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_INPKAYS_InPktsKaY_SHIFT)) & MACSEC_MACSEC_INPKAYS_InPktsKaY_MASK)
/*! @} */

/*! @name MACSEC_INPBTS - InPktsBadTag Statistic */
/*! @{ */

#define MACSEC_MACSEC_INPBTS_InPktsBadTag_MASK   (0xFFFFFFFFU)
#define MACSEC_MACSEC_INPBTS_InPktsBadTag_SHIFT  (0U)
#define MACSEC_MACSEC_INPBTS_InPktsBadTag_WIDTH  (32U)
#define MACSEC_MACSEC_INPBTS_InPktsBadTag(x)     (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_INPBTS_InPktsBadTag_SHIFT)) & MACSEC_MACSEC_INPBTS_InPktsBadTag_MASK)
/*! @} */

/*! @name MACSEC_IPSNFS - InPktsSCINotFound Statistic */
/*! @{ */

#define MACSEC_MACSEC_IPSNFS_InPktsSCINotFound_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IPSNFS_InPktsSCINotFound_SHIFT (0U)
#define MACSEC_MACSEC_IPSNFS_InPktsSCINotFound_WIDTH (32U)
#define MACSEC_MACSEC_IPSNFS_InPktsSCINotFound(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IPSNFS_InPktsSCINotFound_SHIFT)) & MACSEC_MACSEC_IPSNFS_InPktsSCINotFound_MASK)
/*! @} */

/*! @name MACSEC_IPUECS - InPktsUnsupportedEC Statistic */
/*! @{ */

#define MACSEC_MACSEC_IPUECS_InPktsUnsupportedEC_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IPUECS_InPktsUnsupportedEC_SHIFT (0U)
#define MACSEC_MACSEC_IPUECS_InPktsUnsupportedEC_WIDTH (32U)
#define MACSEC_MACSEC_IPUECS_InPktsUnsupportedEC(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IPUECS_InPktsUnsupportedEC_SHIFT)) & MACSEC_MACSEC_IPUECS_InPktsUnsupportedEC_MASK)
/*! @} */

/*! @name MACSEC_IPESCBS - nPktsEponSingleCopyBroadcast Statistic */
/*! @{ */

#define MACSEC_MACSEC_IPESCBS_InPktsEponSingleCopyBroadcast_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IPESCBS_InPktsEponSingleCopyBroadcast_SHIFT (0U)
#define MACSEC_MACSEC_IPESCBS_InPktsEponSingleCopyBroadcast_WIDTH (32U)
#define MACSEC_MACSEC_IPESCBS_InPktsEponSingleCopyBroadcast(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IPESCBS_InPktsEponSingleCopyBroadcast_SHIFT)) & MACSEC_MACSEC_IPESCBS_InPktsEponSingleCopyBroadcast_MASK)
/*! @} */

/*! @name MACSEC_IPTLS - InPktsTooLong Statistic */
/*! @{ */

#define MACSEC_MACSEC_IPTLS_InPktsTooLong_MASK   (0xFFFFFFFFU)
#define MACSEC_MACSEC_IPTLS_InPktsTooLong_SHIFT  (0U)
#define MACSEC_MACSEC_IPTLS_InPktsTooLong_WIDTH  (32U)
#define MACSEC_MACSEC_IPTLS_InPktsTooLong(x)     (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IPTLS_InPktsTooLong_SHIFT)) & MACSEC_MACSEC_IPTLS_InPktsTooLong_MASK)
/*! @} */

/*! @name MACSEC_IPFUS - InPktsFilteredUp Statistic */
/*! @{ */

#define MACSEC_MACSEC_IPFUS_InPktsFilteredUp_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IPFUS_InPktsFilteredUp_SHIFT (0U)
#define MACSEC_MACSEC_IPFUS_InPktsFilteredUp_WIDTH (32U)
#define MACSEC_MACSEC_IPFUS_InPktsFilteredUp(x)  (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IPFUS_InPktsFilteredUp_SHIFT)) & MACSEC_MACSEC_IPFUS_InPktsFilteredUp_MASK)
/*! @} */

/*! @name MACSEC_IPDUS - InPktsDiscardedUp Statistic */
/*! @{ */

#define MACSEC_MACSEC_IPDUS_InPktsDiscardedUp_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_IPDUS_InPktsDiscardedUp_SHIFT (0U)
#define MACSEC_MACSEC_IPDUS_InPktsDiscardedUp_WIDTH (32U)
#define MACSEC_MACSEC_IPDUS_InPktsDiscardedUp(x) (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_IPDUS_InPktsDiscardedUp_SHIFT)) & MACSEC_MACSEC_IPDUS_InPktsDiscardedUp_MASK)
/*! @} */

/*! @name MACSEC_OPDS - OutPktsDiscarded Statistic */
/*! @{ */

#define MACSEC_MACSEC_OPDS_OutPktsDiscarded_MASK (0xFFFFFFFFU)
#define MACSEC_MACSEC_OPDS_OutPktsDiscarded_SHIFT (0U)
#define MACSEC_MACSEC_OPDS_OutPktsDiscarded_WIDTH (32U)
#define MACSEC_MACSEC_OPDS_OutPktsDiscarded(x)   (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_OPDS_OutPktsDiscarded_SHIFT)) & MACSEC_MACSEC_OPDS_OutPktsDiscarded_MASK)
/*! @} */

/*! @name MACSEC_RXSAASSCI - RX Security Association A Short Secure Channel Identifier */
/*! @{ */

#define MACSEC_MACSEC_RXSAASSCI_RXSSCI_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSAASSCI_RXSSCI_SHIFT     (0U)
#define MACSEC_MACSEC_RXSAASSCI_RXSSCI_WIDTH     (32U)
#define MACSEC_MACSEC_RXSAASSCI_RXSSCI(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSAASSCI_RXSSCI_SHIFT)) & MACSEC_MACSEC_RXSAASSCI_RXSSCI_MASK)
/*! @} */

/*! @name MACSEC_RXSAASALT1T - RX Security Association A SALT 1 of 3 */
/*! @{ */

#define MACSEC_MACSEC_RXSAASALT1T_RXSALT_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSAASALT1T_RXSALT_SHIFT   (0U)
#define MACSEC_MACSEC_RXSAASALT1T_RXSALT_WIDTH   (32U)
#define MACSEC_MACSEC_RXSAASALT1T_RXSALT(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSAASALT1T_RXSALT_SHIFT)) & MACSEC_MACSEC_RXSAASALT1T_RXSALT_MASK)
/*! @} */

/*! @name MACSEC_RXSAASALT2T - RX Security Association A SALT 2 of 3 */
/*! @{ */

#define MACSEC_MACSEC_RXSAASALT2T_RXSALT_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSAASALT2T_RXSALT_SHIFT   (0U)
#define MACSEC_MACSEC_RXSAASALT2T_RXSALT_WIDTH   (32U)
#define MACSEC_MACSEC_RXSAASALT2T_RXSALT(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSAASALT2T_RXSALT_SHIFT)) & MACSEC_MACSEC_RXSAASALT2T_RXSALT_MASK)
/*! @} */

/*! @name MACSEC_RXSAASALT3T - RX Security Association A SALT 3 of 3 */
/*! @{ */

#define MACSEC_MACSEC_RXSAASALT3T_RXSALT_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSAASALT3T_RXSALT_SHIFT   (0U)
#define MACSEC_MACSEC_RXSAASALT3T_RXSALT_WIDTH   (32U)
#define MACSEC_MACSEC_RXSAASALT3T_RXSALT(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSAASALT3T_RXSALT_SHIFT)) & MACSEC_MACSEC_RXSAASALT3T_RXSALT_MASK)
/*! @} */

/*! @name MACSEC_RXSABSSCI - RX Security Association B Short Secure Channel Identifier */
/*! @{ */

#define MACSEC_MACSEC_RXSABSSCI_RXSSCI_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSABSSCI_RXSSCI_SHIFT     (0U)
#define MACSEC_MACSEC_RXSABSSCI_RXSSCI_WIDTH     (32U)
#define MACSEC_MACSEC_RXSABSSCI_RXSSCI(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSABSSCI_RXSSCI_SHIFT)) & MACSEC_MACSEC_RXSABSSCI_RXSSCI_MASK)
/*! @} */

/*! @name MACSEC_RXSABSALT1T - RX Security Association B SALT 1 of 3 */
/*! @{ */

#define MACSEC_MACSEC_RXSABSALT1T_RXSALT_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSABSALT1T_RXSALT_SHIFT   (0U)
#define MACSEC_MACSEC_RXSABSALT1T_RXSALT_WIDTH   (32U)
#define MACSEC_MACSEC_RXSABSALT1T_RXSALT(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSABSALT1T_RXSALT_SHIFT)) & MACSEC_MACSEC_RXSABSALT1T_RXSALT_MASK)
/*! @} */

/*! @name MACSEC_RXSABSALT2T - RX Security Association B SALT 2 of 3 */
/*! @{ */

#define MACSEC_MACSEC_RXSABSALT2T_RXSALT_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSABSALT2T_RXSALT_SHIFT   (0U)
#define MACSEC_MACSEC_RXSABSALT2T_RXSALT_WIDTH   (32U)
#define MACSEC_MACSEC_RXSABSALT2T_RXSALT(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSABSALT2T_RXSALT_SHIFT)) & MACSEC_MACSEC_RXSABSALT2T_RXSALT_MASK)
/*! @} */

/*! @name MACSEC_RXSABSALT3T - RX Security Association B SALT 3 of 3 */
/*! @{ */

#define MACSEC_MACSEC_RXSABSALT3T_RXSALT_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_RXSABSALT3T_RXSALT_SHIFT   (0U)
#define MACSEC_MACSEC_RXSABSALT3T_RXSALT_WIDTH   (32U)
#define MACSEC_MACSEC_RXSABSALT3T_RXSALT(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_RXSABSALT3T_RXSALT_SHIFT)) & MACSEC_MACSEC_RXSABSALT3T_RXSALT_MASK)
/*! @} */

/*! @name MACSEC_TXSAASSCI - TX Security Association A Short Secure Channel Identifier */
/*! @{ */

#define MACSEC_MACSEC_TXSAASSCI_TXSSCI_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSAASSCI_TXSSCI_SHIFT     (0U)
#define MACSEC_MACSEC_TXSAASSCI_TXSSCI_WIDTH     (32U)
#define MACSEC_MACSEC_TXSAASSCI_TXSSCI(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSAASSCI_TXSSCI_SHIFT)) & MACSEC_MACSEC_TXSAASSCI_TXSSCI_MASK)
/*! @} */

/*! @name MACSEC_TXSAASALT1T - TX Security Association A SALT 1 of 3 */
/*! @{ */

#define MACSEC_MACSEC_TXSAASALT1T_TXSALT_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSAASALT1T_TXSALT_SHIFT   (0U)
#define MACSEC_MACSEC_TXSAASALT1T_TXSALT_WIDTH   (32U)
#define MACSEC_MACSEC_TXSAASALT1T_TXSALT(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSAASALT1T_TXSALT_SHIFT)) & MACSEC_MACSEC_TXSAASALT1T_TXSALT_MASK)
/*! @} */

/*! @name MACSEC_TXSAASALT2T - TX Security Association A SALT 2 of 3 */
/*! @{ */

#define MACSEC_MACSEC_TXSAASALT2T_TXSALT_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSAASALT2T_TXSALT_SHIFT   (0U)
#define MACSEC_MACSEC_TXSAASALT2T_TXSALT_WIDTH   (32U)
#define MACSEC_MACSEC_TXSAASALT2T_TXSALT(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSAASALT2T_TXSALT_SHIFT)) & MACSEC_MACSEC_TXSAASALT2T_TXSALT_MASK)
/*! @} */

/*! @name MACSEC_TXSAASALT3T - TX Security Association A SALT 3 of 3 */
/*! @{ */

#define MACSEC_MACSEC_TXSAASALT3T_TXSALT_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSAASALT3T_TXSALT_SHIFT   (0U)
#define MACSEC_MACSEC_TXSAASALT3T_TXSALT_WIDTH   (32U)
#define MACSEC_MACSEC_TXSAASALT3T_TXSALT(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSAASALT3T_TXSALT_SHIFT)) & MACSEC_MACSEC_TXSAASALT3T_TXSALT_MASK)
/*! @} */

/*! @name MACSEC_TXSABSSCI - TX Security Association B Short Secure Channel Identifier */
/*! @{ */

#define MACSEC_MACSEC_TXSABSSCI_TXSSCI_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSABSSCI_TXSSCI_SHIFT     (0U)
#define MACSEC_MACSEC_TXSABSSCI_TXSSCI_WIDTH     (32U)
#define MACSEC_MACSEC_TXSABSSCI_TXSSCI(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSABSSCI_TXSSCI_SHIFT)) & MACSEC_MACSEC_TXSABSSCI_TXSSCI_MASK)
/*! @} */

/*! @name MACSEC_TXSABSALT1T - TX Security Association B SALT 1 of 3 */
/*! @{ */

#define MACSEC_MACSEC_TXSABSALT1T_TXSALT_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSABSALT1T_TXSALT_SHIFT   (0U)
#define MACSEC_MACSEC_TXSABSALT1T_TXSALT_WIDTH   (32U)
#define MACSEC_MACSEC_TXSABSALT1T_TXSALT(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSABSALT1T_TXSALT_SHIFT)) & MACSEC_MACSEC_TXSABSALT1T_TXSALT_MASK)
/*! @} */

/*! @name MACSEC_TXSABSALT2T - TX Security Association B SALT 2 of 3 */
/*! @{ */

#define MACSEC_MACSEC_TXSABSALT2T_TXSALT_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSABSALT2T_TXSALT_SHIFT   (0U)
#define MACSEC_MACSEC_TXSABSALT2T_TXSALT_WIDTH   (32U)
#define MACSEC_MACSEC_TXSABSALT2T_TXSALT(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSABSALT2T_TXSALT_SHIFT)) & MACSEC_MACSEC_TXSABSALT2T_TXSALT_MASK)
/*! @} */

/*! @name MACSEC_TXSABSALT3T - TX Security Association B SALT 3 of 3 */
/*! @{ */

#define MACSEC_MACSEC_TXSABSALT3T_TXSALT_MASK    (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSABSALT3T_TXSALT_SHIFT   (0U)
#define MACSEC_MACSEC_TXSABSALT3T_TXSALT_WIDTH   (32U)
#define MACSEC_MACSEC_TXSABSALT3T_TXSALT(x)      (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSABSALT3T_TXSALT_SHIFT)) & MACSEC_MACSEC_TXSABSALT3T_TXSALT_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR0P0 - TX SC Selection Record 0 part 0 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR0P0_MAC_DA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR0P0_MAC_DA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR0P0_MAC_DA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR0P0_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR0P0_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR0P0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR0P1 - TX SC Selection Record 0 part 1 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR0P1_MAC_SA_MASK      (0xFFFFU)
#define MACSEC_MACSEC_TXSCSR0P1_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR0P1_MAC_SA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR0P1_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR0P1_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR0P1_MAC_SA_MASK)

#define MACSEC_MACSEC_TXSCSR0P1_MAC_DA_MASK      (0xFFFF0000U)
#define MACSEC_MACSEC_TXSCSR0P1_MAC_DA_SHIFT     (16U)
#define MACSEC_MACSEC_TXSCSR0P1_MAC_DA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR0P1_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR0P1_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR0P1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR0P2 - TX SC Selection Record 0 part 2 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR0P2_MAC_SA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR0P2_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR0P2_MAC_SA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR0P2_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR0P2_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR0P2_MAC_SA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR0P3 - TX SC Selection Record 0 part 3 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR0P3_TX_SC_MASK       (0x1FU)
#define MACSEC_MACSEC_TXSCSR0P3_TX_SC_SHIFT      (0U)
#define MACSEC_MACSEC_TXSCSR0P3_TX_SC_WIDTH      (5U)
#define MACSEC_MACSEC_TXSCSR0P3_TX_SC(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR0P3_TX_SC_SHIFT)) & MACSEC_MACSEC_TXSCSR0P3_TX_SC_MASK)

#define MACSEC_MACSEC_TXSCSR0P3_EN_MASK          (0x100U)
#define MACSEC_MACSEC_TXSCSR0P3_EN_SHIFT         (8U)
#define MACSEC_MACSEC_TXSCSR0P3_EN_WIDTH         (1U)
#define MACSEC_MACSEC_TXSCSR0P3_EN(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR0P3_EN_SHIFT)) & MACSEC_MACSEC_TXSCSR0P3_EN_MASK)

#define MACSEC_MACSEC_TXSCSR0P3_UVD_MASK         (0x800U)
#define MACSEC_MACSEC_TXSCSR0P3_UVD_SHIFT        (11U)
#define MACSEC_MACSEC_TXSCSR0P3_UVD_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR0P3_UVD(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR0P3_UVD_SHIFT)) & MACSEC_MACSEC_TXSCSR0P3_UVD_MASK)

#define MACSEC_MACSEC_TXSCSR0P3_UVP_MASK         (0x1000U)
#define MACSEC_MACSEC_TXSCSR0P3_UVP_SHIFT        (12U)
#define MACSEC_MACSEC_TXSCSR0P3_UVP_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR0P3_UVP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR0P3_UVP_SHIFT)) & MACSEC_MACSEC_TXSCSR0P3_UVP_MASK)

#define MACSEC_MACSEC_TXSCSR0P3_UVV_MASK         (0x2000U)
#define MACSEC_MACSEC_TXSCSR0P3_UVV_SHIFT        (13U)
#define MACSEC_MACSEC_TXSCSR0P3_UVV_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR0P3_UVV(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR0P3_UVV_SHIFT)) & MACSEC_MACSEC_TXSCSR0P3_UVV_MASK)

#define MACSEC_MACSEC_TXSCSR0P3_USA_MASK         (0x4000U)
#define MACSEC_MACSEC_TXSCSR0P3_USA_SHIFT        (14U)
#define MACSEC_MACSEC_TXSCSR0P3_USA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR0P3_USA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR0P3_USA_SHIFT)) & MACSEC_MACSEC_TXSCSR0P3_USA_MASK)

#define MACSEC_MACSEC_TXSCSR0P3_UDA_MASK         (0x8000U)
#define MACSEC_MACSEC_TXSCSR0P3_UDA_SHIFT        (15U)
#define MACSEC_MACSEC_TXSCSR0P3_UDA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR0P3_UDA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR0P3_UDA_SHIFT)) & MACSEC_MACSEC_TXSCSR0P3_UDA_MASK)

#define MACSEC_MACSEC_TXSCSR0P3_VID_MASK         (0xFFF0000U)
#define MACSEC_MACSEC_TXSCSR0P3_VID_SHIFT        (16U)
#define MACSEC_MACSEC_TXSCSR0P3_VID_WIDTH        (12U)
#define MACSEC_MACSEC_TXSCSR0P3_VID(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR0P3_VID_SHIFT)) & MACSEC_MACSEC_TXSCSR0P3_VID_MASK)

#define MACSEC_MACSEC_TXSCSR0P3_DEI_MASK         (0x10000000U)
#define MACSEC_MACSEC_TXSCSR0P3_DEI_SHIFT        (28U)
#define MACSEC_MACSEC_TXSCSR0P3_DEI_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR0P3_DEI(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR0P3_DEI_SHIFT)) & MACSEC_MACSEC_TXSCSR0P3_DEI_MASK)

#define MACSEC_MACSEC_TXSCSR0P3_PCP_MASK         (0xE0000000U)
#define MACSEC_MACSEC_TXSCSR0P3_PCP_SHIFT        (29U)
#define MACSEC_MACSEC_TXSCSR0P3_PCP_WIDTH        (3U)
#define MACSEC_MACSEC_TXSCSR0P3_PCP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR0P3_PCP_SHIFT)) & MACSEC_MACSEC_TXSCSR0P3_PCP_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR1P0 - TX SC Selection Record 1 part 0 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR1P0_MAC_DA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR1P0_MAC_DA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR1P0_MAC_DA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR1P0_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR1P0_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR1P0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR1P1 - TX SC Selection Record 1 part 1 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR1P1_MAC_SA_MASK      (0xFFFFU)
#define MACSEC_MACSEC_TXSCSR1P1_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR1P1_MAC_SA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR1P1_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR1P1_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR1P1_MAC_SA_MASK)

#define MACSEC_MACSEC_TXSCSR1P1_MAC_DA_MASK      (0xFFFF0000U)
#define MACSEC_MACSEC_TXSCSR1P1_MAC_DA_SHIFT     (16U)
#define MACSEC_MACSEC_TXSCSR1P1_MAC_DA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR1P1_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR1P1_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR1P1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR1P2 - TX SC Selection Record 1 part 2 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR1P2_MAC_SA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR1P2_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR1P2_MAC_SA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR1P2_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR1P2_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR1P2_MAC_SA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR1P3 - TX SC Selection Record 1 part 3 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR1P3_TX_SC_MASK       (0x1FU)
#define MACSEC_MACSEC_TXSCSR1P3_TX_SC_SHIFT      (0U)
#define MACSEC_MACSEC_TXSCSR1P3_TX_SC_WIDTH      (5U)
#define MACSEC_MACSEC_TXSCSR1P3_TX_SC(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR1P3_TX_SC_SHIFT)) & MACSEC_MACSEC_TXSCSR1P3_TX_SC_MASK)

#define MACSEC_MACSEC_TXSCSR1P3_EN_MASK          (0x100U)
#define MACSEC_MACSEC_TXSCSR1P3_EN_SHIFT         (8U)
#define MACSEC_MACSEC_TXSCSR1P3_EN_WIDTH         (1U)
#define MACSEC_MACSEC_TXSCSR1P3_EN(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR1P3_EN_SHIFT)) & MACSEC_MACSEC_TXSCSR1P3_EN_MASK)

#define MACSEC_MACSEC_TXSCSR1P3_UVD_MASK         (0x800U)
#define MACSEC_MACSEC_TXSCSR1P3_UVD_SHIFT        (11U)
#define MACSEC_MACSEC_TXSCSR1P3_UVD_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR1P3_UVD(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR1P3_UVD_SHIFT)) & MACSEC_MACSEC_TXSCSR1P3_UVD_MASK)

#define MACSEC_MACSEC_TXSCSR1P3_UVP_MASK         (0x1000U)
#define MACSEC_MACSEC_TXSCSR1P3_UVP_SHIFT        (12U)
#define MACSEC_MACSEC_TXSCSR1P3_UVP_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR1P3_UVP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR1P3_UVP_SHIFT)) & MACSEC_MACSEC_TXSCSR1P3_UVP_MASK)

#define MACSEC_MACSEC_TXSCSR1P3_UVV_MASK         (0x2000U)
#define MACSEC_MACSEC_TXSCSR1P3_UVV_SHIFT        (13U)
#define MACSEC_MACSEC_TXSCSR1P3_UVV_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR1P3_UVV(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR1P3_UVV_SHIFT)) & MACSEC_MACSEC_TXSCSR1P3_UVV_MASK)

#define MACSEC_MACSEC_TXSCSR1P3_USA_MASK         (0x4000U)
#define MACSEC_MACSEC_TXSCSR1P3_USA_SHIFT        (14U)
#define MACSEC_MACSEC_TXSCSR1P3_USA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR1P3_USA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR1P3_USA_SHIFT)) & MACSEC_MACSEC_TXSCSR1P3_USA_MASK)

#define MACSEC_MACSEC_TXSCSR1P3_UDA_MASK         (0x8000U)
#define MACSEC_MACSEC_TXSCSR1P3_UDA_SHIFT        (15U)
#define MACSEC_MACSEC_TXSCSR1P3_UDA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR1P3_UDA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR1P3_UDA_SHIFT)) & MACSEC_MACSEC_TXSCSR1P3_UDA_MASK)

#define MACSEC_MACSEC_TXSCSR1P3_VID_MASK         (0xFFF0000U)
#define MACSEC_MACSEC_TXSCSR1P3_VID_SHIFT        (16U)
#define MACSEC_MACSEC_TXSCSR1P3_VID_WIDTH        (12U)
#define MACSEC_MACSEC_TXSCSR1P3_VID(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR1P3_VID_SHIFT)) & MACSEC_MACSEC_TXSCSR1P3_VID_MASK)

#define MACSEC_MACSEC_TXSCSR1P3_DEI_MASK         (0x10000000U)
#define MACSEC_MACSEC_TXSCSR1P3_DEI_SHIFT        (28U)
#define MACSEC_MACSEC_TXSCSR1P3_DEI_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR1P3_DEI(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR1P3_DEI_SHIFT)) & MACSEC_MACSEC_TXSCSR1P3_DEI_MASK)

#define MACSEC_MACSEC_TXSCSR1P3_PCP_MASK         (0xE0000000U)
#define MACSEC_MACSEC_TXSCSR1P3_PCP_SHIFT        (29U)
#define MACSEC_MACSEC_TXSCSR1P3_PCP_WIDTH        (3U)
#define MACSEC_MACSEC_TXSCSR1P3_PCP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR1P3_PCP_SHIFT)) & MACSEC_MACSEC_TXSCSR1P3_PCP_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR2P0 - TX SC Selection Record 2 part 0 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR2P0_MAC_DA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR2P0_MAC_DA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR2P0_MAC_DA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR2P0_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR2P0_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR2P0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR2P1 - TX SC Selection Record 2 part 1 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR2P1_MAC_SA_MASK      (0xFFFFU)
#define MACSEC_MACSEC_TXSCSR2P1_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR2P1_MAC_SA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR2P1_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR2P1_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR2P1_MAC_SA_MASK)

#define MACSEC_MACSEC_TXSCSR2P1_MAC_DA_MASK      (0xFFFF0000U)
#define MACSEC_MACSEC_TXSCSR2P1_MAC_DA_SHIFT     (16U)
#define MACSEC_MACSEC_TXSCSR2P1_MAC_DA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR2P1_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR2P1_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR2P1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR2P2 - TX SC Selection Record 2 part 2 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR2P2_MAC_SA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR2P2_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR2P2_MAC_SA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR2P2_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR2P2_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR2P2_MAC_SA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR2P3 - TX SC Selection Record 2 part 3 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR2P3_TX_SC_MASK       (0x1FU)
#define MACSEC_MACSEC_TXSCSR2P3_TX_SC_SHIFT      (0U)
#define MACSEC_MACSEC_TXSCSR2P3_TX_SC_WIDTH      (5U)
#define MACSEC_MACSEC_TXSCSR2P3_TX_SC(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR2P3_TX_SC_SHIFT)) & MACSEC_MACSEC_TXSCSR2P3_TX_SC_MASK)

#define MACSEC_MACSEC_TXSCSR2P3_EN_MASK          (0x100U)
#define MACSEC_MACSEC_TXSCSR2P3_EN_SHIFT         (8U)
#define MACSEC_MACSEC_TXSCSR2P3_EN_WIDTH         (1U)
#define MACSEC_MACSEC_TXSCSR2P3_EN(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR2P3_EN_SHIFT)) & MACSEC_MACSEC_TXSCSR2P3_EN_MASK)

#define MACSEC_MACSEC_TXSCSR2P3_UVD_MASK         (0x800U)
#define MACSEC_MACSEC_TXSCSR2P3_UVD_SHIFT        (11U)
#define MACSEC_MACSEC_TXSCSR2P3_UVD_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR2P3_UVD(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR2P3_UVD_SHIFT)) & MACSEC_MACSEC_TXSCSR2P3_UVD_MASK)

#define MACSEC_MACSEC_TXSCSR2P3_UVP_MASK         (0x1000U)
#define MACSEC_MACSEC_TXSCSR2P3_UVP_SHIFT        (12U)
#define MACSEC_MACSEC_TXSCSR2P3_UVP_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR2P3_UVP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR2P3_UVP_SHIFT)) & MACSEC_MACSEC_TXSCSR2P3_UVP_MASK)

#define MACSEC_MACSEC_TXSCSR2P3_UVV_MASK         (0x2000U)
#define MACSEC_MACSEC_TXSCSR2P3_UVV_SHIFT        (13U)
#define MACSEC_MACSEC_TXSCSR2P3_UVV_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR2P3_UVV(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR2P3_UVV_SHIFT)) & MACSEC_MACSEC_TXSCSR2P3_UVV_MASK)

#define MACSEC_MACSEC_TXSCSR2P3_USA_MASK         (0x4000U)
#define MACSEC_MACSEC_TXSCSR2P3_USA_SHIFT        (14U)
#define MACSEC_MACSEC_TXSCSR2P3_USA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR2P3_USA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR2P3_USA_SHIFT)) & MACSEC_MACSEC_TXSCSR2P3_USA_MASK)

#define MACSEC_MACSEC_TXSCSR2P3_UDA_MASK         (0x8000U)
#define MACSEC_MACSEC_TXSCSR2P3_UDA_SHIFT        (15U)
#define MACSEC_MACSEC_TXSCSR2P3_UDA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR2P3_UDA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR2P3_UDA_SHIFT)) & MACSEC_MACSEC_TXSCSR2P3_UDA_MASK)

#define MACSEC_MACSEC_TXSCSR2P3_VID_MASK         (0xFFF0000U)
#define MACSEC_MACSEC_TXSCSR2P3_VID_SHIFT        (16U)
#define MACSEC_MACSEC_TXSCSR2P3_VID_WIDTH        (12U)
#define MACSEC_MACSEC_TXSCSR2P3_VID(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR2P3_VID_SHIFT)) & MACSEC_MACSEC_TXSCSR2P3_VID_MASK)

#define MACSEC_MACSEC_TXSCSR2P3_DEI_MASK         (0x10000000U)
#define MACSEC_MACSEC_TXSCSR2P3_DEI_SHIFT        (28U)
#define MACSEC_MACSEC_TXSCSR2P3_DEI_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR2P3_DEI(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR2P3_DEI_SHIFT)) & MACSEC_MACSEC_TXSCSR2P3_DEI_MASK)

#define MACSEC_MACSEC_TXSCSR2P3_PCP_MASK         (0xE0000000U)
#define MACSEC_MACSEC_TXSCSR2P3_PCP_SHIFT        (29U)
#define MACSEC_MACSEC_TXSCSR2P3_PCP_WIDTH        (3U)
#define MACSEC_MACSEC_TXSCSR2P3_PCP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR2P3_PCP_SHIFT)) & MACSEC_MACSEC_TXSCSR2P3_PCP_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR3P0 - TX SC Selection Record 3 part 0 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR3P0_MAC_DA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR3P0_MAC_DA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR3P0_MAC_DA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR3P0_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR3P0_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR3P0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR3P1 - TX SC Selection Record 3 part 1 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR3P1_MAC_SA_MASK      (0xFFFFU)
#define MACSEC_MACSEC_TXSCSR3P1_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR3P1_MAC_SA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR3P1_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR3P1_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR3P1_MAC_SA_MASK)

#define MACSEC_MACSEC_TXSCSR3P1_MAC_DA_MASK      (0xFFFF0000U)
#define MACSEC_MACSEC_TXSCSR3P1_MAC_DA_SHIFT     (16U)
#define MACSEC_MACSEC_TXSCSR3P1_MAC_DA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR3P1_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR3P1_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR3P1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR3P2 - TX SC Selection Record 3 part 2 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR3P2_MAC_SA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR3P2_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR3P2_MAC_SA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR3P2_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR3P2_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR3P2_MAC_SA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR3P3 - TX SC Selection Record 3 part 3 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR3P3_TX_SC_MASK       (0x1FU)
#define MACSEC_MACSEC_TXSCSR3P3_TX_SC_SHIFT      (0U)
#define MACSEC_MACSEC_TXSCSR3P3_TX_SC_WIDTH      (5U)
#define MACSEC_MACSEC_TXSCSR3P3_TX_SC(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR3P3_TX_SC_SHIFT)) & MACSEC_MACSEC_TXSCSR3P3_TX_SC_MASK)

#define MACSEC_MACSEC_TXSCSR3P3_EN_MASK          (0x100U)
#define MACSEC_MACSEC_TXSCSR3P3_EN_SHIFT         (8U)
#define MACSEC_MACSEC_TXSCSR3P3_EN_WIDTH         (1U)
#define MACSEC_MACSEC_TXSCSR3P3_EN(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR3P3_EN_SHIFT)) & MACSEC_MACSEC_TXSCSR3P3_EN_MASK)

#define MACSEC_MACSEC_TXSCSR3P3_UVD_MASK         (0x800U)
#define MACSEC_MACSEC_TXSCSR3P3_UVD_SHIFT        (11U)
#define MACSEC_MACSEC_TXSCSR3P3_UVD_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR3P3_UVD(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR3P3_UVD_SHIFT)) & MACSEC_MACSEC_TXSCSR3P3_UVD_MASK)

#define MACSEC_MACSEC_TXSCSR3P3_UVP_MASK         (0x1000U)
#define MACSEC_MACSEC_TXSCSR3P3_UVP_SHIFT        (12U)
#define MACSEC_MACSEC_TXSCSR3P3_UVP_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR3P3_UVP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR3P3_UVP_SHIFT)) & MACSEC_MACSEC_TXSCSR3P3_UVP_MASK)

#define MACSEC_MACSEC_TXSCSR3P3_UVV_MASK         (0x2000U)
#define MACSEC_MACSEC_TXSCSR3P3_UVV_SHIFT        (13U)
#define MACSEC_MACSEC_TXSCSR3P3_UVV_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR3P3_UVV(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR3P3_UVV_SHIFT)) & MACSEC_MACSEC_TXSCSR3P3_UVV_MASK)

#define MACSEC_MACSEC_TXSCSR3P3_USA_MASK         (0x4000U)
#define MACSEC_MACSEC_TXSCSR3P3_USA_SHIFT        (14U)
#define MACSEC_MACSEC_TXSCSR3P3_USA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR3P3_USA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR3P3_USA_SHIFT)) & MACSEC_MACSEC_TXSCSR3P3_USA_MASK)

#define MACSEC_MACSEC_TXSCSR3P3_UDA_MASK         (0x8000U)
#define MACSEC_MACSEC_TXSCSR3P3_UDA_SHIFT        (15U)
#define MACSEC_MACSEC_TXSCSR3P3_UDA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR3P3_UDA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR3P3_UDA_SHIFT)) & MACSEC_MACSEC_TXSCSR3P3_UDA_MASK)

#define MACSEC_MACSEC_TXSCSR3P3_VID_MASK         (0xFFF0000U)
#define MACSEC_MACSEC_TXSCSR3P3_VID_SHIFT        (16U)
#define MACSEC_MACSEC_TXSCSR3P3_VID_WIDTH        (12U)
#define MACSEC_MACSEC_TXSCSR3P3_VID(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR3P3_VID_SHIFT)) & MACSEC_MACSEC_TXSCSR3P3_VID_MASK)

#define MACSEC_MACSEC_TXSCSR3P3_DEI_MASK         (0x10000000U)
#define MACSEC_MACSEC_TXSCSR3P3_DEI_SHIFT        (28U)
#define MACSEC_MACSEC_TXSCSR3P3_DEI_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR3P3_DEI(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR3P3_DEI_SHIFT)) & MACSEC_MACSEC_TXSCSR3P3_DEI_MASK)

#define MACSEC_MACSEC_TXSCSR3P3_PCP_MASK         (0xE0000000U)
#define MACSEC_MACSEC_TXSCSR3P3_PCP_SHIFT        (29U)
#define MACSEC_MACSEC_TXSCSR3P3_PCP_WIDTH        (3U)
#define MACSEC_MACSEC_TXSCSR3P3_PCP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR3P3_PCP_SHIFT)) & MACSEC_MACSEC_TXSCSR3P3_PCP_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR4P0 - TX SC Selection Record 4 part 0 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR4P0_MAC_DA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR4P0_MAC_DA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR4P0_MAC_DA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR4P0_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR4P0_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR4P0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR4P1 - TX SC Selection Record 4 part 1 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR4P1_MAC_SA_MASK      (0xFFFFU)
#define MACSEC_MACSEC_TXSCSR4P1_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR4P1_MAC_SA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR4P1_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR4P1_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR4P1_MAC_SA_MASK)

#define MACSEC_MACSEC_TXSCSR4P1_MAC_DA_MASK      (0xFFFF0000U)
#define MACSEC_MACSEC_TXSCSR4P1_MAC_DA_SHIFT     (16U)
#define MACSEC_MACSEC_TXSCSR4P1_MAC_DA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR4P1_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR4P1_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR4P1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR4P2 - TX SC Selection Record 4 part 2 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR4P2_MAC_SA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR4P2_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR4P2_MAC_SA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR4P2_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR4P2_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR4P2_MAC_SA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR4P3 - TX SC Selection Record 4 part 3 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR4P3_TX_SC_MASK       (0x1FU)
#define MACSEC_MACSEC_TXSCSR4P3_TX_SC_SHIFT      (0U)
#define MACSEC_MACSEC_TXSCSR4P3_TX_SC_WIDTH      (5U)
#define MACSEC_MACSEC_TXSCSR4P3_TX_SC(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR4P3_TX_SC_SHIFT)) & MACSEC_MACSEC_TXSCSR4P3_TX_SC_MASK)

#define MACSEC_MACSEC_TXSCSR4P3_EN_MASK          (0x100U)
#define MACSEC_MACSEC_TXSCSR4P3_EN_SHIFT         (8U)
#define MACSEC_MACSEC_TXSCSR4P3_EN_WIDTH         (1U)
#define MACSEC_MACSEC_TXSCSR4P3_EN(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR4P3_EN_SHIFT)) & MACSEC_MACSEC_TXSCSR4P3_EN_MASK)

#define MACSEC_MACSEC_TXSCSR4P3_UVD_MASK         (0x800U)
#define MACSEC_MACSEC_TXSCSR4P3_UVD_SHIFT        (11U)
#define MACSEC_MACSEC_TXSCSR4P3_UVD_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR4P3_UVD(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR4P3_UVD_SHIFT)) & MACSEC_MACSEC_TXSCSR4P3_UVD_MASK)

#define MACSEC_MACSEC_TXSCSR4P3_UVP_MASK         (0x1000U)
#define MACSEC_MACSEC_TXSCSR4P3_UVP_SHIFT        (12U)
#define MACSEC_MACSEC_TXSCSR4P3_UVP_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR4P3_UVP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR4P3_UVP_SHIFT)) & MACSEC_MACSEC_TXSCSR4P3_UVP_MASK)

#define MACSEC_MACSEC_TXSCSR4P3_UVV_MASK         (0x2000U)
#define MACSEC_MACSEC_TXSCSR4P3_UVV_SHIFT        (13U)
#define MACSEC_MACSEC_TXSCSR4P3_UVV_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR4P3_UVV(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR4P3_UVV_SHIFT)) & MACSEC_MACSEC_TXSCSR4P3_UVV_MASK)

#define MACSEC_MACSEC_TXSCSR4P3_USA_MASK         (0x4000U)
#define MACSEC_MACSEC_TXSCSR4P3_USA_SHIFT        (14U)
#define MACSEC_MACSEC_TXSCSR4P3_USA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR4P3_USA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR4P3_USA_SHIFT)) & MACSEC_MACSEC_TXSCSR4P3_USA_MASK)

#define MACSEC_MACSEC_TXSCSR4P3_UDA_MASK         (0x8000U)
#define MACSEC_MACSEC_TXSCSR4P3_UDA_SHIFT        (15U)
#define MACSEC_MACSEC_TXSCSR4P3_UDA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR4P3_UDA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR4P3_UDA_SHIFT)) & MACSEC_MACSEC_TXSCSR4P3_UDA_MASK)

#define MACSEC_MACSEC_TXSCSR4P3_VID_MASK         (0xFFF0000U)
#define MACSEC_MACSEC_TXSCSR4P3_VID_SHIFT        (16U)
#define MACSEC_MACSEC_TXSCSR4P3_VID_WIDTH        (12U)
#define MACSEC_MACSEC_TXSCSR4P3_VID(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR4P3_VID_SHIFT)) & MACSEC_MACSEC_TXSCSR4P3_VID_MASK)

#define MACSEC_MACSEC_TXSCSR4P3_DEI_MASK         (0x10000000U)
#define MACSEC_MACSEC_TXSCSR4P3_DEI_SHIFT        (28U)
#define MACSEC_MACSEC_TXSCSR4P3_DEI_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR4P3_DEI(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR4P3_DEI_SHIFT)) & MACSEC_MACSEC_TXSCSR4P3_DEI_MASK)

#define MACSEC_MACSEC_TXSCSR4P3_PCP_MASK         (0xE0000000U)
#define MACSEC_MACSEC_TXSCSR4P3_PCP_SHIFT        (29U)
#define MACSEC_MACSEC_TXSCSR4P3_PCP_WIDTH        (3U)
#define MACSEC_MACSEC_TXSCSR4P3_PCP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR4P3_PCP_SHIFT)) & MACSEC_MACSEC_TXSCSR4P3_PCP_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR5P0 - TX SC Selection Record 5 part 0 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR5P0_MAC_DA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR5P0_MAC_DA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR5P0_MAC_DA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR5P0_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR5P0_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR5P0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR5P1 - TX SC Selection Record 5 part 1 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR5P1_MAC_SA_MASK      (0xFFFFU)
#define MACSEC_MACSEC_TXSCSR5P1_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR5P1_MAC_SA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR5P1_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR5P1_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR5P1_MAC_SA_MASK)

#define MACSEC_MACSEC_TXSCSR5P1_MAC_DA_MASK      (0xFFFF0000U)
#define MACSEC_MACSEC_TXSCSR5P1_MAC_DA_SHIFT     (16U)
#define MACSEC_MACSEC_TXSCSR5P1_MAC_DA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR5P1_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR5P1_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR5P1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR5P2 - TX SC Selection Record 5 part 2 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR5P2_MAC_SA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR5P2_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR5P2_MAC_SA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR5P2_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR5P2_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR5P2_MAC_SA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR5P3 - TX SC Selection Record 5 part 3 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR5P3_TX_SC_MASK       (0x1FU)
#define MACSEC_MACSEC_TXSCSR5P3_TX_SC_SHIFT      (0U)
#define MACSEC_MACSEC_TXSCSR5P3_TX_SC_WIDTH      (5U)
#define MACSEC_MACSEC_TXSCSR5P3_TX_SC(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR5P3_TX_SC_SHIFT)) & MACSEC_MACSEC_TXSCSR5P3_TX_SC_MASK)

#define MACSEC_MACSEC_TXSCSR5P3_EN_MASK          (0x100U)
#define MACSEC_MACSEC_TXSCSR5P3_EN_SHIFT         (8U)
#define MACSEC_MACSEC_TXSCSR5P3_EN_WIDTH         (1U)
#define MACSEC_MACSEC_TXSCSR5P3_EN(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR5P3_EN_SHIFT)) & MACSEC_MACSEC_TXSCSR5P3_EN_MASK)

#define MACSEC_MACSEC_TXSCSR5P3_UVD_MASK         (0x800U)
#define MACSEC_MACSEC_TXSCSR5P3_UVD_SHIFT        (11U)
#define MACSEC_MACSEC_TXSCSR5P3_UVD_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR5P3_UVD(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR5P3_UVD_SHIFT)) & MACSEC_MACSEC_TXSCSR5P3_UVD_MASK)

#define MACSEC_MACSEC_TXSCSR5P3_UVP_MASK         (0x1000U)
#define MACSEC_MACSEC_TXSCSR5P3_UVP_SHIFT        (12U)
#define MACSEC_MACSEC_TXSCSR5P3_UVP_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR5P3_UVP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR5P3_UVP_SHIFT)) & MACSEC_MACSEC_TXSCSR5P3_UVP_MASK)

#define MACSEC_MACSEC_TXSCSR5P3_UVV_MASK         (0x2000U)
#define MACSEC_MACSEC_TXSCSR5P3_UVV_SHIFT        (13U)
#define MACSEC_MACSEC_TXSCSR5P3_UVV_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR5P3_UVV(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR5P3_UVV_SHIFT)) & MACSEC_MACSEC_TXSCSR5P3_UVV_MASK)

#define MACSEC_MACSEC_TXSCSR5P3_USA_MASK         (0x4000U)
#define MACSEC_MACSEC_TXSCSR5P3_USA_SHIFT        (14U)
#define MACSEC_MACSEC_TXSCSR5P3_USA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR5P3_USA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR5P3_USA_SHIFT)) & MACSEC_MACSEC_TXSCSR5P3_USA_MASK)

#define MACSEC_MACSEC_TXSCSR5P3_UDA_MASK         (0x8000U)
#define MACSEC_MACSEC_TXSCSR5P3_UDA_SHIFT        (15U)
#define MACSEC_MACSEC_TXSCSR5P3_UDA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR5P3_UDA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR5P3_UDA_SHIFT)) & MACSEC_MACSEC_TXSCSR5P3_UDA_MASK)

#define MACSEC_MACSEC_TXSCSR5P3_VID_MASK         (0xFFF0000U)
#define MACSEC_MACSEC_TXSCSR5P3_VID_SHIFT        (16U)
#define MACSEC_MACSEC_TXSCSR5P3_VID_WIDTH        (12U)
#define MACSEC_MACSEC_TXSCSR5P3_VID(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR5P3_VID_SHIFT)) & MACSEC_MACSEC_TXSCSR5P3_VID_MASK)

#define MACSEC_MACSEC_TXSCSR5P3_DEI_MASK         (0x10000000U)
#define MACSEC_MACSEC_TXSCSR5P3_DEI_SHIFT        (28U)
#define MACSEC_MACSEC_TXSCSR5P3_DEI_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR5P3_DEI(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR5P3_DEI_SHIFT)) & MACSEC_MACSEC_TXSCSR5P3_DEI_MASK)

#define MACSEC_MACSEC_TXSCSR5P3_PCP_MASK         (0xE0000000U)
#define MACSEC_MACSEC_TXSCSR5P3_PCP_SHIFT        (29U)
#define MACSEC_MACSEC_TXSCSR5P3_PCP_WIDTH        (3U)
#define MACSEC_MACSEC_TXSCSR5P3_PCP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR5P3_PCP_SHIFT)) & MACSEC_MACSEC_TXSCSR5P3_PCP_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR6P0 - TX SC Selection Record 6 part 0 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR6P0_MAC_DA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR6P0_MAC_DA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR6P0_MAC_DA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR6P0_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR6P0_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR6P0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR6P1 - TX SC Selection Record 6 part 1 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR6P1_MAC_SA_MASK      (0xFFFFU)
#define MACSEC_MACSEC_TXSCSR6P1_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR6P1_MAC_SA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR6P1_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR6P1_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR6P1_MAC_SA_MASK)

#define MACSEC_MACSEC_TXSCSR6P1_MAC_DA_MASK      (0xFFFF0000U)
#define MACSEC_MACSEC_TXSCSR6P1_MAC_DA_SHIFT     (16U)
#define MACSEC_MACSEC_TXSCSR6P1_MAC_DA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR6P1_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR6P1_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR6P1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR6P2 - TX SC Selection Record 6 part 2 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR6P2_MAC_SA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR6P2_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR6P2_MAC_SA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR6P2_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR6P2_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR6P2_MAC_SA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR6P3 - TX SC Selection Record 6 part 3 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR6P3_TX_SC_MASK       (0x1FU)
#define MACSEC_MACSEC_TXSCSR6P3_TX_SC_SHIFT      (0U)
#define MACSEC_MACSEC_TXSCSR6P3_TX_SC_WIDTH      (5U)
#define MACSEC_MACSEC_TXSCSR6P3_TX_SC(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR6P3_TX_SC_SHIFT)) & MACSEC_MACSEC_TXSCSR6P3_TX_SC_MASK)

#define MACSEC_MACSEC_TXSCSR6P3_EN_MASK          (0x100U)
#define MACSEC_MACSEC_TXSCSR6P3_EN_SHIFT         (8U)
#define MACSEC_MACSEC_TXSCSR6P3_EN_WIDTH         (1U)
#define MACSEC_MACSEC_TXSCSR6P3_EN(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR6P3_EN_SHIFT)) & MACSEC_MACSEC_TXSCSR6P3_EN_MASK)

#define MACSEC_MACSEC_TXSCSR6P3_UVD_MASK         (0x800U)
#define MACSEC_MACSEC_TXSCSR6P3_UVD_SHIFT        (11U)
#define MACSEC_MACSEC_TXSCSR6P3_UVD_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR6P3_UVD(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR6P3_UVD_SHIFT)) & MACSEC_MACSEC_TXSCSR6P3_UVD_MASK)

#define MACSEC_MACSEC_TXSCSR6P3_UVP_MASK         (0x1000U)
#define MACSEC_MACSEC_TXSCSR6P3_UVP_SHIFT        (12U)
#define MACSEC_MACSEC_TXSCSR6P3_UVP_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR6P3_UVP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR6P3_UVP_SHIFT)) & MACSEC_MACSEC_TXSCSR6P3_UVP_MASK)

#define MACSEC_MACSEC_TXSCSR6P3_UVV_MASK         (0x2000U)
#define MACSEC_MACSEC_TXSCSR6P3_UVV_SHIFT        (13U)
#define MACSEC_MACSEC_TXSCSR6P3_UVV_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR6P3_UVV(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR6P3_UVV_SHIFT)) & MACSEC_MACSEC_TXSCSR6P3_UVV_MASK)

#define MACSEC_MACSEC_TXSCSR6P3_USA_MASK         (0x4000U)
#define MACSEC_MACSEC_TXSCSR6P3_USA_SHIFT        (14U)
#define MACSEC_MACSEC_TXSCSR6P3_USA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR6P3_USA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR6P3_USA_SHIFT)) & MACSEC_MACSEC_TXSCSR6P3_USA_MASK)

#define MACSEC_MACSEC_TXSCSR6P3_UDA_MASK         (0x8000U)
#define MACSEC_MACSEC_TXSCSR6P3_UDA_SHIFT        (15U)
#define MACSEC_MACSEC_TXSCSR6P3_UDA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR6P3_UDA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR6P3_UDA_SHIFT)) & MACSEC_MACSEC_TXSCSR6P3_UDA_MASK)

#define MACSEC_MACSEC_TXSCSR6P3_VID_MASK         (0xFFF0000U)
#define MACSEC_MACSEC_TXSCSR6P3_VID_SHIFT        (16U)
#define MACSEC_MACSEC_TXSCSR6P3_VID_WIDTH        (12U)
#define MACSEC_MACSEC_TXSCSR6P3_VID(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR6P3_VID_SHIFT)) & MACSEC_MACSEC_TXSCSR6P3_VID_MASK)

#define MACSEC_MACSEC_TXSCSR6P3_DEI_MASK         (0x10000000U)
#define MACSEC_MACSEC_TXSCSR6P3_DEI_SHIFT        (28U)
#define MACSEC_MACSEC_TXSCSR6P3_DEI_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR6P3_DEI(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR6P3_DEI_SHIFT)) & MACSEC_MACSEC_TXSCSR6P3_DEI_MASK)

#define MACSEC_MACSEC_TXSCSR6P3_PCP_MASK         (0xE0000000U)
#define MACSEC_MACSEC_TXSCSR6P3_PCP_SHIFT        (29U)
#define MACSEC_MACSEC_TXSCSR6P3_PCP_WIDTH        (3U)
#define MACSEC_MACSEC_TXSCSR6P3_PCP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR6P3_PCP_SHIFT)) & MACSEC_MACSEC_TXSCSR6P3_PCP_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR7P0 - TX SC Selection Record 7 part 0 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR7P0_MAC_DA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR7P0_MAC_DA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR7P0_MAC_DA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR7P0_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR7P0_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR7P0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR7P1 - TX SC Selection Record 7 part 1 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR7P1_MAC_SA_MASK      (0xFFFFU)
#define MACSEC_MACSEC_TXSCSR7P1_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR7P1_MAC_SA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR7P1_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR7P1_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR7P1_MAC_SA_MASK)

#define MACSEC_MACSEC_TXSCSR7P1_MAC_DA_MASK      (0xFFFF0000U)
#define MACSEC_MACSEC_TXSCSR7P1_MAC_DA_SHIFT     (16U)
#define MACSEC_MACSEC_TXSCSR7P1_MAC_DA_WIDTH     (16U)
#define MACSEC_MACSEC_TXSCSR7P1_MAC_DA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR7P1_MAC_DA_SHIFT)) & MACSEC_MACSEC_TXSCSR7P1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR7P2 - TX SC Selection Record 7 part 2 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR7P2_MAC_SA_MASK      (0xFFFFFFFFU)
#define MACSEC_MACSEC_TXSCSR7P2_MAC_SA_SHIFT     (0U)
#define MACSEC_MACSEC_TXSCSR7P2_MAC_SA_WIDTH     (32U)
#define MACSEC_MACSEC_TXSCSR7P2_MAC_SA(x)        (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR7P2_MAC_SA_SHIFT)) & MACSEC_MACSEC_TXSCSR7P2_MAC_SA_MASK)
/*! @} */

/*! @name MACSEC_TXSCSR7P3 - TX SC Selection Record 7 part 3 */
/*! @{ */

#define MACSEC_MACSEC_TXSCSR7P3_TX_SC_MASK       (0x1FU)
#define MACSEC_MACSEC_TXSCSR7P3_TX_SC_SHIFT      (0U)
#define MACSEC_MACSEC_TXSCSR7P3_TX_SC_WIDTH      (5U)
#define MACSEC_MACSEC_TXSCSR7P3_TX_SC(x)         (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR7P3_TX_SC_SHIFT)) & MACSEC_MACSEC_TXSCSR7P3_TX_SC_MASK)

#define MACSEC_MACSEC_TXSCSR7P3_EN_MASK          (0x100U)
#define MACSEC_MACSEC_TXSCSR7P3_EN_SHIFT         (8U)
#define MACSEC_MACSEC_TXSCSR7P3_EN_WIDTH         (1U)
#define MACSEC_MACSEC_TXSCSR7P3_EN(x)            (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR7P3_EN_SHIFT)) & MACSEC_MACSEC_TXSCSR7P3_EN_MASK)

#define MACSEC_MACSEC_TXSCSR7P3_UVD_MASK         (0x800U)
#define MACSEC_MACSEC_TXSCSR7P3_UVD_SHIFT        (11U)
#define MACSEC_MACSEC_TXSCSR7P3_UVD_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR7P3_UVD(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR7P3_UVD_SHIFT)) & MACSEC_MACSEC_TXSCSR7P3_UVD_MASK)

#define MACSEC_MACSEC_TXSCSR7P3_UVP_MASK         (0x1000U)
#define MACSEC_MACSEC_TXSCSR7P3_UVP_SHIFT        (12U)
#define MACSEC_MACSEC_TXSCSR7P3_UVP_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR7P3_UVP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR7P3_UVP_SHIFT)) & MACSEC_MACSEC_TXSCSR7P3_UVP_MASK)

#define MACSEC_MACSEC_TXSCSR7P3_UVV_MASK         (0x2000U)
#define MACSEC_MACSEC_TXSCSR7P3_UVV_SHIFT        (13U)
#define MACSEC_MACSEC_TXSCSR7P3_UVV_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR7P3_UVV(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR7P3_UVV_SHIFT)) & MACSEC_MACSEC_TXSCSR7P3_UVV_MASK)

#define MACSEC_MACSEC_TXSCSR7P3_USA_MASK         (0x4000U)
#define MACSEC_MACSEC_TXSCSR7P3_USA_SHIFT        (14U)
#define MACSEC_MACSEC_TXSCSR7P3_USA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR7P3_USA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR7P3_USA_SHIFT)) & MACSEC_MACSEC_TXSCSR7P3_USA_MASK)

#define MACSEC_MACSEC_TXSCSR7P3_UDA_MASK         (0x8000U)
#define MACSEC_MACSEC_TXSCSR7P3_UDA_SHIFT        (15U)
#define MACSEC_MACSEC_TXSCSR7P3_UDA_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR7P3_UDA(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR7P3_UDA_SHIFT)) & MACSEC_MACSEC_TXSCSR7P3_UDA_MASK)

#define MACSEC_MACSEC_TXSCSR7P3_VID_MASK         (0xFFF0000U)
#define MACSEC_MACSEC_TXSCSR7P3_VID_SHIFT        (16U)
#define MACSEC_MACSEC_TXSCSR7P3_VID_WIDTH        (12U)
#define MACSEC_MACSEC_TXSCSR7P3_VID(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR7P3_VID_SHIFT)) & MACSEC_MACSEC_TXSCSR7P3_VID_MASK)

#define MACSEC_MACSEC_TXSCSR7P3_DEI_MASK         (0x10000000U)
#define MACSEC_MACSEC_TXSCSR7P3_DEI_SHIFT        (28U)
#define MACSEC_MACSEC_TXSCSR7P3_DEI_WIDTH        (1U)
#define MACSEC_MACSEC_TXSCSR7P3_DEI(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR7P3_DEI_SHIFT)) & MACSEC_MACSEC_TXSCSR7P3_DEI_MASK)

#define MACSEC_MACSEC_TXSCSR7P3_PCP_MASK         (0xE0000000U)
#define MACSEC_MACSEC_TXSCSR7P3_PCP_SHIFT        (29U)
#define MACSEC_MACSEC_TXSCSR7P3_PCP_WIDTH        (3U)
#define MACSEC_MACSEC_TXSCSR7P3_PCP(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_TXSCSR7P3_PCP_SHIFT)) & MACSEC_MACSEC_TXSCSR7P3_PCP_MASK)
/*! @} */

/*! @name MACSEC_UPFR0D0 - Uncontrolled Port filter Record 0 data part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR0D0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR0D0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR0D0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR0D0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR0D0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR0D0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR0D1 - Uncontrolled Port filter Record 0 data part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR0D1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR0D1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR0D1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR0D1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR0D1_VID_SHIFT)) & MACSEC_MACSEC_UPFR0D1_VID_MASK)

#define MACSEC_MACSEC_UPFR0D1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR0D1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR0D1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR0D1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR0D1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR0D1_OVP_MASK)

#define MACSEC_MACSEC_UPFR0D1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR0D1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR0D1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR0D1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR0D1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR0D1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR0D2 - Uncontrolled Port filter Record 0 data part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR0D2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR0D2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR0D2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR0D2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR0D2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR0D2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR0M0 - Uncontrolled Port filter Record 0 mask part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR0M0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR0M0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR0M0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR0M0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR0M0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR0M0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR0M1 - Uncontrolled Port filter Record 0 mask part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR0M1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR0M1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR0M1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR0M1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR0M1_VID_SHIFT)) & MACSEC_MACSEC_UPFR0M1_VID_MASK)

#define MACSEC_MACSEC_UPFR0M1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR0M1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR0M1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR0M1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR0M1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR0M1_OVP_MASK)

#define MACSEC_MACSEC_UPFR0M1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR0M1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR0M1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR0M1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR0M1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR0M1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR0M2 - Uncontrolled Port filter Record 0 mask part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR0M2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR0M2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR0M2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR0M2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR0M2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR0M2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR0R - Uncontrolled Port filter Record 0 Result */
/*! @{ */

#define MACSEC_MACSEC_UPFR0R_EN_MASK             (0x1U)
#define MACSEC_MACSEC_UPFR0R_EN_SHIFT            (0U)
#define MACSEC_MACSEC_UPFR0R_EN_WIDTH            (1U)
#define MACSEC_MACSEC_UPFR0R_EN(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR0R_EN_SHIFT)) & MACSEC_MACSEC_UPFR0R_EN_MASK)

#define MACSEC_MACSEC_UPFR0R_A_MASK              (0x100U)
#define MACSEC_MACSEC_UPFR0R_A_SHIFT             (8U)
#define MACSEC_MACSEC_UPFR0R_A_WIDTH             (1U)
#define MACSEC_MACSEC_UPFR0R_A(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR0R_A_SHIFT)) & MACSEC_MACSEC_UPFR0R_A_MASK)
/*! @} */

/*! @name MACSEC_UPFR1D0 - Uncontrolled Port filter Record 1 data part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR1D0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR1D0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR1D0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR1D0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR1D0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR1D0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR1D1 - Uncontrolled Port filter Record 1 data part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR1D1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR1D1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR1D1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR1D1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR1D1_VID_SHIFT)) & MACSEC_MACSEC_UPFR1D1_VID_MASK)

#define MACSEC_MACSEC_UPFR1D1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR1D1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR1D1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR1D1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR1D1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR1D1_OVP_MASK)

#define MACSEC_MACSEC_UPFR1D1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR1D1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR1D1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR1D1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR1D1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR1D1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR1D2 - Uncontrolled Port filter Record 1 data part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR1D2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR1D2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR1D2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR1D2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR1D2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR1D2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR1M0 - Uncontrolled Port filter Record 1 mask part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR1M0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR1M0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR1M0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR1M0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR1M0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR1M0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR1M1 - Uncontrolled Port filter Record 1 mask part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR1M1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR1M1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR1M1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR1M1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR1M1_VID_SHIFT)) & MACSEC_MACSEC_UPFR1M1_VID_MASK)

#define MACSEC_MACSEC_UPFR1M1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR1M1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR1M1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR1M1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR1M1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR1M1_OVP_MASK)

#define MACSEC_MACSEC_UPFR1M1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR1M1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR1M1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR1M1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR1M1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR1M1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR1M2 - Uncontrolled Port filter Record 1 mask part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR1M2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR1M2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR1M2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR1M2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR1M2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR1M2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR1R - Uncontrolled Port filter Record 1 Result */
/*! @{ */

#define MACSEC_MACSEC_UPFR1R_EN_MASK             (0x1U)
#define MACSEC_MACSEC_UPFR1R_EN_SHIFT            (0U)
#define MACSEC_MACSEC_UPFR1R_EN_WIDTH            (1U)
#define MACSEC_MACSEC_UPFR1R_EN(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR1R_EN_SHIFT)) & MACSEC_MACSEC_UPFR1R_EN_MASK)

#define MACSEC_MACSEC_UPFR1R_A_MASK              (0x100U)
#define MACSEC_MACSEC_UPFR1R_A_SHIFT             (8U)
#define MACSEC_MACSEC_UPFR1R_A_WIDTH             (1U)
#define MACSEC_MACSEC_UPFR1R_A(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR1R_A_SHIFT)) & MACSEC_MACSEC_UPFR1R_A_MASK)
/*! @} */

/*! @name MACSEC_UPFR2D0 - Uncontrolled Port filter Record 2 data part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR2D0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR2D0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR2D0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR2D0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR2D0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR2D0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR2D1 - Uncontrolled Port filter Record 2 data part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR2D1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR2D1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR2D1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR2D1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR2D1_VID_SHIFT)) & MACSEC_MACSEC_UPFR2D1_VID_MASK)

#define MACSEC_MACSEC_UPFR2D1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR2D1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR2D1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR2D1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR2D1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR2D1_OVP_MASK)

#define MACSEC_MACSEC_UPFR2D1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR2D1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR2D1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR2D1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR2D1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR2D1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR2D2 - Uncontrolled Port filter Record 2 data part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR2D2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR2D2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR2D2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR2D2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR2D2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR2D2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR2M0 - Uncontrolled Port filter Record 2 mask part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR2M0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR2M0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR2M0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR2M0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR2M0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR2M0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR2M1 - Uncontrolled Port filter Record 2 mask part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR2M1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR2M1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR2M1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR2M1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR2M1_VID_SHIFT)) & MACSEC_MACSEC_UPFR2M1_VID_MASK)

#define MACSEC_MACSEC_UPFR2M1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR2M1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR2M1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR2M1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR2M1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR2M1_OVP_MASK)

#define MACSEC_MACSEC_UPFR2M1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR2M1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR2M1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR2M1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR2M1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR2M1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR2M2 - Uncontrolled Port filter Record 2 mask part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR2M2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR2M2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR2M2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR2M2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR2M2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR2M2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR2R - Uncontrolled Port filter Record 2 Result */
/*! @{ */

#define MACSEC_MACSEC_UPFR2R_EN_MASK             (0x1U)
#define MACSEC_MACSEC_UPFR2R_EN_SHIFT            (0U)
#define MACSEC_MACSEC_UPFR2R_EN_WIDTH            (1U)
#define MACSEC_MACSEC_UPFR2R_EN(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR2R_EN_SHIFT)) & MACSEC_MACSEC_UPFR2R_EN_MASK)

#define MACSEC_MACSEC_UPFR2R_A_MASK              (0x100U)
#define MACSEC_MACSEC_UPFR2R_A_SHIFT             (8U)
#define MACSEC_MACSEC_UPFR2R_A_WIDTH             (1U)
#define MACSEC_MACSEC_UPFR2R_A(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR2R_A_SHIFT)) & MACSEC_MACSEC_UPFR2R_A_MASK)
/*! @} */

/*! @name MACSEC_UPFR3D0 - Uncontrolled Port filter Record 3 data part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR3D0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR3D0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR3D0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR3D0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR3D0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR3D0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR3D1 - Uncontrolled Port filter Record 3 data part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR3D1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR3D1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR3D1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR3D1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR3D1_VID_SHIFT)) & MACSEC_MACSEC_UPFR3D1_VID_MASK)

#define MACSEC_MACSEC_UPFR3D1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR3D1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR3D1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR3D1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR3D1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR3D1_OVP_MASK)

#define MACSEC_MACSEC_UPFR3D1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR3D1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR3D1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR3D1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR3D1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR3D1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR3D2 - Uncontrolled Port filter Record 3 data part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR3D2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR3D2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR3D2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR3D2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR3D2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR3D2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR3M0 - Uncontrolled Port filter Record 3 mask part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR3M0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR3M0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR3M0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR3M0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR3M0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR3M0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR3M1 - Uncontrolled Port filter Record 3 mask part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR3M1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR3M1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR3M1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR3M1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR3M1_VID_SHIFT)) & MACSEC_MACSEC_UPFR3M1_VID_MASK)

#define MACSEC_MACSEC_UPFR3M1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR3M1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR3M1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR3M1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR3M1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR3M1_OVP_MASK)

#define MACSEC_MACSEC_UPFR3M1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR3M1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR3M1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR3M1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR3M1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR3M1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR3M2 - Uncontrolled Port filter Record 3 mask part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR3M2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR3M2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR3M2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR3M2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR3M2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR3M2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR3R - Uncontrolled Port filter Record 3 Result */
/*! @{ */

#define MACSEC_MACSEC_UPFR3R_EN_MASK             (0x1U)
#define MACSEC_MACSEC_UPFR3R_EN_SHIFT            (0U)
#define MACSEC_MACSEC_UPFR3R_EN_WIDTH            (1U)
#define MACSEC_MACSEC_UPFR3R_EN(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR3R_EN_SHIFT)) & MACSEC_MACSEC_UPFR3R_EN_MASK)

#define MACSEC_MACSEC_UPFR3R_A_MASK              (0x100U)
#define MACSEC_MACSEC_UPFR3R_A_SHIFT             (8U)
#define MACSEC_MACSEC_UPFR3R_A_WIDTH             (1U)
#define MACSEC_MACSEC_UPFR3R_A(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR3R_A_SHIFT)) & MACSEC_MACSEC_UPFR3R_A_MASK)
/*! @} */

/*! @name MACSEC_UPFR4D0 - Uncontrolled Port filter Record 4 data part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR4D0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR4D0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR4D0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR4D0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR4D0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR4D0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR4D1 - Uncontrolled Port filter Record 4 data part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR4D1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR4D1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR4D1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR4D1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR4D1_VID_SHIFT)) & MACSEC_MACSEC_UPFR4D1_VID_MASK)

#define MACSEC_MACSEC_UPFR4D1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR4D1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR4D1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR4D1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR4D1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR4D1_OVP_MASK)

#define MACSEC_MACSEC_UPFR4D1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR4D1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR4D1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR4D1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR4D1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR4D1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR4D2 - Uncontrolled Port filter Record 4 data part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR4D2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR4D2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR4D2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR4D2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR4D2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR4D2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR4M0 - Uncontrolled Port filter Record 4 mask part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR4M0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR4M0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR4M0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR4M0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR4M0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR4M0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR4M1 - Uncontrolled Port filter Record 4 mask part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR4M1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR4M1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR4M1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR4M1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR4M1_VID_SHIFT)) & MACSEC_MACSEC_UPFR4M1_VID_MASK)

#define MACSEC_MACSEC_UPFR4M1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR4M1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR4M1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR4M1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR4M1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR4M1_OVP_MASK)

#define MACSEC_MACSEC_UPFR4M1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR4M1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR4M1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR4M1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR4M1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR4M1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR4M2 - Uncontrolled Port filter Record 4 mask part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR4M2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR4M2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR4M2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR4M2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR4M2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR4M2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR4R - Uncontrolled Port filter Record 4 Result */
/*! @{ */

#define MACSEC_MACSEC_UPFR4R_EN_MASK             (0x1U)
#define MACSEC_MACSEC_UPFR4R_EN_SHIFT            (0U)
#define MACSEC_MACSEC_UPFR4R_EN_WIDTH            (1U)
#define MACSEC_MACSEC_UPFR4R_EN(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR4R_EN_SHIFT)) & MACSEC_MACSEC_UPFR4R_EN_MASK)

#define MACSEC_MACSEC_UPFR4R_A_MASK              (0x100U)
#define MACSEC_MACSEC_UPFR4R_A_SHIFT             (8U)
#define MACSEC_MACSEC_UPFR4R_A_WIDTH             (1U)
#define MACSEC_MACSEC_UPFR4R_A(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR4R_A_SHIFT)) & MACSEC_MACSEC_UPFR4R_A_MASK)
/*! @} */

/*! @name MACSEC_UPFR5D0 - Uncontrolled Port filter Record 5 data part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR5D0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR5D0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR5D0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR5D0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR5D0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR5D0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR5D1 - Uncontrolled Port filter Record 5 data part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR5D1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR5D1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR5D1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR5D1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR5D1_VID_SHIFT)) & MACSEC_MACSEC_UPFR5D1_VID_MASK)

#define MACSEC_MACSEC_UPFR5D1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR5D1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR5D1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR5D1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR5D1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR5D1_OVP_MASK)

#define MACSEC_MACSEC_UPFR5D1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR5D1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR5D1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR5D1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR5D1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR5D1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR5D2 - Uncontrolled Port filter Record 5 data part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR5D2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR5D2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR5D2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR5D2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR5D2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR5D2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR5M0 - Uncontrolled Port filter Record 5 mask part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR5M0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR5M0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR5M0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR5M0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR5M0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR5M0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR5M1 - Uncontrolled Port filter Record 5 mask part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR5M1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR5M1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR5M1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR5M1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR5M1_VID_SHIFT)) & MACSEC_MACSEC_UPFR5M1_VID_MASK)

#define MACSEC_MACSEC_UPFR5M1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR5M1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR5M1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR5M1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR5M1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR5M1_OVP_MASK)

#define MACSEC_MACSEC_UPFR5M1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR5M1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR5M1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR5M1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR5M1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR5M1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR5M2 - Uncontrolled Port filter Record 5 mask part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR5M2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR5M2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR5M2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR5M2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR5M2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR5M2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR5R - Uncontrolled Port filter Record 5 Result */
/*! @{ */

#define MACSEC_MACSEC_UPFR5R_EN_MASK             (0x1U)
#define MACSEC_MACSEC_UPFR5R_EN_SHIFT            (0U)
#define MACSEC_MACSEC_UPFR5R_EN_WIDTH            (1U)
#define MACSEC_MACSEC_UPFR5R_EN(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR5R_EN_SHIFT)) & MACSEC_MACSEC_UPFR5R_EN_MASK)

#define MACSEC_MACSEC_UPFR5R_A_MASK              (0x100U)
#define MACSEC_MACSEC_UPFR5R_A_SHIFT             (8U)
#define MACSEC_MACSEC_UPFR5R_A_WIDTH             (1U)
#define MACSEC_MACSEC_UPFR5R_A(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR5R_A_SHIFT)) & MACSEC_MACSEC_UPFR5R_A_MASK)
/*! @} */

/*! @name MACSEC_UPFR6D0 - Uncontrolled Port filter Record 6 data part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR6D0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR6D0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR6D0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR6D0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR6D0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR6D0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR6D1 - Uncontrolled Port filter Record 6 data part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR6D1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR6D1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR6D1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR6D1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR6D1_VID_SHIFT)) & MACSEC_MACSEC_UPFR6D1_VID_MASK)

#define MACSEC_MACSEC_UPFR6D1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR6D1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR6D1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR6D1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR6D1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR6D1_OVP_MASK)

#define MACSEC_MACSEC_UPFR6D1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR6D1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR6D1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR6D1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR6D1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR6D1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR6D2 - Uncontrolled Port filter Record 6 data part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR6D2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR6D2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR6D2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR6D2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR6D2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR6D2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR6M0 - Uncontrolled Port filter Record 6 mask part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR6M0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR6M0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR6M0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR6M0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR6M0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR6M0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR6M1 - Uncontrolled Port filter Record 6 mask part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR6M1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR6M1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR6M1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR6M1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR6M1_VID_SHIFT)) & MACSEC_MACSEC_UPFR6M1_VID_MASK)

#define MACSEC_MACSEC_UPFR6M1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR6M1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR6M1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR6M1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR6M1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR6M1_OVP_MASK)

#define MACSEC_MACSEC_UPFR6M1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR6M1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR6M1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR6M1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR6M1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR6M1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR6M2 - Uncontrolled Port filter Record 6 mask part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR6M2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR6M2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR6M2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR6M2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR6M2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR6M2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR6R - Uncontrolled Port filter Record 6 Result */
/*! @{ */

#define MACSEC_MACSEC_UPFR6R_EN_MASK             (0x1U)
#define MACSEC_MACSEC_UPFR6R_EN_SHIFT            (0U)
#define MACSEC_MACSEC_UPFR6R_EN_WIDTH            (1U)
#define MACSEC_MACSEC_UPFR6R_EN(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR6R_EN_SHIFT)) & MACSEC_MACSEC_UPFR6R_EN_MASK)

#define MACSEC_MACSEC_UPFR6R_A_MASK              (0x100U)
#define MACSEC_MACSEC_UPFR6R_A_SHIFT             (8U)
#define MACSEC_MACSEC_UPFR6R_A_WIDTH             (1U)
#define MACSEC_MACSEC_UPFR6R_A(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR6R_A_SHIFT)) & MACSEC_MACSEC_UPFR6R_A_MASK)
/*! @} */

/*! @name MACSEC_UPFR7D0 - Uncontrolled Port filter Record 7 data part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR7D0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR7D0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR7D0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR7D0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR7D0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR7D0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR7D1 - Uncontrolled Port filter Record 7 data part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR7D1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR7D1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR7D1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR7D1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR7D1_VID_SHIFT)) & MACSEC_MACSEC_UPFR7D1_VID_MASK)

#define MACSEC_MACSEC_UPFR7D1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR7D1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR7D1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR7D1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR7D1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR7D1_OVP_MASK)

#define MACSEC_MACSEC_UPFR7D1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR7D1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR7D1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR7D1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR7D1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR7D1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR7D2 - Uncontrolled Port filter Record 7 data part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR7D2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR7D2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR7D2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR7D2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR7D2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR7D2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR7M0 - Uncontrolled Port filter Record 7 mask part 0 */
/*! @{ */

#define MACSEC_MACSEC_UPFR7M0_MAC_DA_MASK        (0xFFFFFFFFU)
#define MACSEC_MACSEC_UPFR7M0_MAC_DA_SHIFT       (0U)
#define MACSEC_MACSEC_UPFR7M0_MAC_DA_WIDTH       (32U)
#define MACSEC_MACSEC_UPFR7M0_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR7M0_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR7M0_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR7M1 - Uncontrolled Port filter Record 7 mask part 1 */
/*! @{ */

#define MACSEC_MACSEC_UPFR7M1_VID_MASK           (0xFFFU)
#define MACSEC_MACSEC_UPFR7M1_VID_SHIFT          (0U)
#define MACSEC_MACSEC_UPFR7M1_VID_WIDTH          (12U)
#define MACSEC_MACSEC_UPFR7M1_VID(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR7M1_VID_SHIFT)) & MACSEC_MACSEC_UPFR7M1_VID_MASK)

#define MACSEC_MACSEC_UPFR7M1_OVP_MASK           (0x1000U)
#define MACSEC_MACSEC_UPFR7M1_OVP_SHIFT          (12U)
#define MACSEC_MACSEC_UPFR7M1_OVP_WIDTH          (1U)
#define MACSEC_MACSEC_UPFR7M1_OVP(x)             (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR7M1_OVP_SHIFT)) & MACSEC_MACSEC_UPFR7M1_OVP_MASK)

#define MACSEC_MACSEC_UPFR7M1_MAC_DA_MASK        (0xFFFF0000U)
#define MACSEC_MACSEC_UPFR7M1_MAC_DA_SHIFT       (16U)
#define MACSEC_MACSEC_UPFR7M1_MAC_DA_WIDTH       (16U)
#define MACSEC_MACSEC_UPFR7M1_MAC_DA(x)          (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR7M1_MAC_DA_SHIFT)) & MACSEC_MACSEC_UPFR7M1_MAC_DA_MASK)
/*! @} */

/*! @name MACSEC_UPFR7M2 - Uncontrolled Port filter Record 7 mask part 2 */
/*! @{ */

#define MACSEC_MACSEC_UPFR7M2_ETYPE_MASK         (0xFFFFU)
#define MACSEC_MACSEC_UPFR7M2_ETYPE_SHIFT        (0U)
#define MACSEC_MACSEC_UPFR7M2_ETYPE_WIDTH        (16U)
#define MACSEC_MACSEC_UPFR7M2_ETYPE(x)           (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR7M2_ETYPE_SHIFT)) & MACSEC_MACSEC_UPFR7M2_ETYPE_MASK)
/*! @} */

/*! @name MACSEC_UPFR7R - Uncontrolled Port filter Record 7 Result */
/*! @{ */

#define MACSEC_MACSEC_UPFR7R_EN_MASK             (0x1U)
#define MACSEC_MACSEC_UPFR7R_EN_SHIFT            (0U)
#define MACSEC_MACSEC_UPFR7R_EN_WIDTH            (1U)
#define MACSEC_MACSEC_UPFR7R_EN(x)               (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR7R_EN_SHIFT)) & MACSEC_MACSEC_UPFR7R_EN_MASK)

#define MACSEC_MACSEC_UPFR7R_A_MASK              (0x100U)
#define MACSEC_MACSEC_UPFR7R_A_SHIFT             (8U)
#define MACSEC_MACSEC_UPFR7R_A_WIDTH             (1U)
#define MACSEC_MACSEC_UPFR7R_A(x)                (((uint32_t)(((uint32_t)(x)) << MACSEC_MACSEC_UPFR7R_A_SHIFT)) & MACSEC_MACSEC_UPFR7R_A_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MACSEC_Register_Masks */

/*!
 * @}
 */ /* end of group MACSEC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_MACSEC_H_) */
