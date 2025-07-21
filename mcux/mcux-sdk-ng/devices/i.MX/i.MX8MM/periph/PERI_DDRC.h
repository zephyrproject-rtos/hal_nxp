/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DDRC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DDRC.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DDRC
 *
 * CMSIS Peripheral Access Layer for DDRC
 */

#if !defined(PERI_DDRC_H_)
#define PERI_DDRC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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
   -- DDRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDRC_Peripheral_Access_Layer DDRC Peripheral Access Layer
 * @{
 */

/** DDRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MSTR;                              /**< Master Register0, offset: 0x0 */
  __I  uint32_t STAT;                              /**< Operating Mode Status Register, offset: 0x4 */
  __IO uint32_t MSTR1;                             /**< Operating Mode Status Register, offset: 0x8 */
  __IO uint32_t MRCTRL3;                           /**< Operating Mode Status Register, offset: 0xC */
  __IO uint32_t MRCTRL0;                           /**< Mode Register Read/Write Control Register 0., offset: 0x10 */
  __IO uint32_t MRCTRL1;                           /**< Mode Register Read/Write Control Register 1, offset: 0x14 */
  __I  uint32_t MRSTAT;                            /**< Mode Register Read/Write Status Register, offset: 0x18 */
  __IO uint32_t MRCTRL2;                           /**< Mode Register Read/Write Control Register 2, offset: 0x1C */
  __IO uint32_t DERATEEN;                          /**< Temperature Derate Enable Register, offset: 0x20 */
  __IO uint32_t DERATEINT;                         /**< Temperature Derate Interval Register, offset: 0x24 */
       uint8_t RESERVED_0[8];
  __IO uint32_t PWRCTL;                            /**< Low Power Control Register, offset: 0x30 */
  __IO uint32_t PWRTMG;                            /**< Low Power Timing Register, offset: 0x34 */
  __IO uint32_t HWLPCTL;                           /**< Hardware Low Power Control Register, offset: 0x38 */
       uint8_t RESERVED_1[20];
  __IO uint32_t RFSHCTL0;                          /**< Refresh Control Register 0, offset: 0x50 */
  __IO uint32_t RFSHCTL1;                          /**< Refresh Control Register 1, offset: 0x54 */
       uint8_t RESERVED_2[8];
  __IO uint32_t RFSHCTL3;                          /**< Refresh Control Register 3, offset: 0x60 */
  __IO uint32_t RFSHTMG;                           /**< Refresh Timing Register, offset: 0x64 */
       uint8_t RESERVED_3[104];
  __IO uint32_t INIT0;                             /**< SDRAM Initialization Register 0, offset: 0xD0 */
  __IO uint32_t INIT1;                             /**< SDRAM Initialization Register 1, offset: 0xD4 */
  __IO uint32_t INIT2;                             /**< SDRAM Initialization Register 2, offset: 0xD8 */
  __IO uint32_t INIT3;                             /**< SDRAM Initialization Register 3, offset: 0xDC */
  __IO uint32_t INIT4;                             /**< SDRAM Initialization Register 4, offset: 0xE0 */
  __IO uint32_t INIT5;                             /**< SDRAM Initialization Register 5, offset: 0xE4 */
  __IO uint32_t INIT6;                             /**< SDRAM Initialization Register 6, offset: 0xE8 */
  __IO uint32_t INIT7;                             /**< SDRAM Initialization Register 7, offset: 0xEC */
  __IO uint32_t DIMMCTL;                           /**< DIMM Control Register, offset: 0xF0 */
  __IO uint32_t RANKCTL;                           /**< Rank Control Register, offset: 0xF4 */
       uint8_t RESERVED_4[8];
  __IO uint32_t DRAMTMG0;                          /**< SDRAM Timing Register 0, offset: 0x100 */
  __IO uint32_t DRAMTMG1;                          /**< SDRAM Timing Register 1, offset: 0x104 */
  __IO uint32_t DRAMTMG2;                          /**< SDRAM Timing Register 2, offset: 0x108 */
  __IO uint32_t DRAMTMG3;                          /**< SDRAM Timing Register 3, offset: 0x10C */
  __IO uint32_t DRAMTMG4;                          /**< SDRAM Timing Register 4, offset: 0x110 */
  __IO uint32_t DRAMTMG5;                          /**< SDRAM Timing Register 5, offset: 0x114 */
  __IO uint32_t DRAMTMG6;                          /**< SDRAM Timing Register 6, offset: 0x118 */
  __IO uint32_t DRAMTMG7;                          /**< SDRAM Timing Register 7, offset: 0x11C */
  __IO uint32_t DRAMTMG8;                          /**< SDRAM Timing Register 8, offset: 0x120 */
  __IO uint32_t DRAMTMG9;                          /**< SDRAM Timing Register 9, offset: 0x124 */
  __IO uint32_t DRAMTMG10;                         /**< SDRAM Timing Register 10, offset: 0x128 */
  __IO uint32_t DRAMTMG11;                         /**< SDRAM Timing Register 11, offset: 0x12C */
  __IO uint32_t DRAMTMG12;                         /**< SDRAM Timing Register 12, offset: 0x130 */
  __IO uint32_t DRAMTMG13;                         /**< SDRAM Timing Register 13, offset: 0x134 */
  __IO uint32_t DRAMTMG14;                         /**< SDRAM Timing Register 14, offset: 0x138 */
  __IO uint32_t DRAMTMG15;                         /**< SDRAM Timing Register 15, offset: 0x13C */
       uint8_t RESERVED_5[64];
  __IO uint32_t ZQCTL0;                            /**< ZQ Control Register 0, offset: 0x180 */
  __IO uint32_t ZQCTL1;                            /**< ZQ Control Register 1, offset: 0x184 */
  __IO uint32_t ZQCTL2;                            /**< ZQ Control Register 2, offset: 0x188 */
  __I  uint32_t ZQSTAT;                            /**< ZQ Status Register, offset: 0x18C */
  __IO uint32_t DFITMG0;                           /**< DFI Timing Register 0, offset: 0x190 */
  __IO uint32_t DFITMG1;                           /**< DFI Timing Register 1, offset: 0x194 */
  __IO uint32_t DFILPCFG0;                         /**< DFI Low Power Configuration Register 0, offset: 0x198 */
  __IO uint32_t DFILPCFG1;                         /**< DFI Low Power Configuration Register 1, offset: 0x19C */
  __IO uint32_t DFIUPD0;                           /**< DFI Update Register 0, offset: 0x1A0 */
  __IO uint32_t DFIUPD1;                           /**< DFI Update Register 1, offset: 0x1A4 */
  __IO uint32_t DFIUPD2;                           /**< DFI Update Register 2, offset: 0x1A8 */
       uint8_t RESERVED_6[4];
  __IO uint32_t DFIMISC;                           /**< DFI Miscellaneous Control Register, offset: 0x1B0 */
  __IO uint32_t DFITMG2;                           /**< DFI Timing Register 2, offset: 0x1B4 */
  __IO uint32_t DFITMG3;                           /**< DFI Timing Register 3, offset: 0x1B8 */
  __I  uint32_t DFISTAT;                           /**< DFI Status Register, offset: 0x1BC */
  __IO uint32_t DBICTL;                            /**< DM/DBI Control Register, offset: 0x1C0 */
       uint8_t RESERVED_7[60];
  __IO uint32_t ADDRMAP0;                          /**< Address Map Register 0, offset: 0x200 */
  __IO uint32_t ADDRMAP1;                          /**< Address Map Register 1, offset: 0x204 */
  __IO uint32_t ADDRMAP2;                          /**< Address Map Register 2, offset: 0x208 */
  __IO uint32_t ADDRMAP3;                          /**< Address Map Register 3, offset: 0x20C */
  __IO uint32_t ADDRMAP4;                          /**< Address Map Register 4, offset: 0x210 */
  __IO uint32_t ADDRMAP5;                          /**< Address Map Register 5, offset: 0x214 */
  __IO uint32_t ADDRMAP6;                          /**< Address Map Register 6, offset: 0x218 */
  __IO uint32_t ADDRMAP7;                          /**< Address Map Register 7, offset: 0x21C */
  __IO uint32_t ADDRMAP8;                          /**< Address Map Register 8, offset: 0x220 */
  __IO uint32_t ADDRMAP9;                          /**< Address Map Register 9, offset: 0x224 */
  __IO uint32_t ADDRMAP10;                         /**< Address Map Register 10, offset: 0x228 */
  __IO uint32_t ADDRMAP11;                         /**< Address Map Register 11, offset: 0x22C */
       uint8_t RESERVED_8[16];
  __IO uint32_t ODTCFG;                            /**< ODT Configuration Register, offset: 0x240 */
  __IO uint32_t ODTMAP;                            /**< ODT/Rank Map Register, offset: 0x244 */
       uint8_t RESERVED_9[8];
  __IO uint32_t SCHED;                             /**< Scheduler Control Register, offset: 0x250 */
  __IO uint32_t SCHED1;                            /**< Scheduler Control Register 1, offset: 0x254 */
       uint8_t RESERVED_10[4];
  __IO uint32_t PERFHPR1;                          /**< High Priority Read CAM Register 1, offset: 0x25C */
       uint8_t RESERVED_11[4];
  __IO uint32_t PERFLPR1;                          /**< Low Priority Read CAM Register 1, offset: 0x264 */
       uint8_t RESERVED_12[4];
  __IO uint32_t PERFWR1;                           /**< Write CAM Register 1, offset: 0x26C */
       uint8_t RESERVED_13[144];
  __IO uint32_t DBG0;                              /**< Debug Register 0, offset: 0x300 */
  __IO uint32_t DBG1;                              /**< Debug Register 1, offset: 0x304 */
  __I  uint32_t DBGCAM;                            /**< CAM Debug Register, offset: 0x308 */
  __IO uint32_t DBGCMD;                            /**< Command Debug Register, offset: 0x30C */
  __I  uint32_t DBGSTAT;                           /**< Status Debug Register, offset: 0x310 */
       uint8_t RESERVED_14[12];
  __IO uint32_t SWCTL;                             /**< Software Register Programming Control Enable, offset: 0x320 */
  __I  uint32_t SWSTAT;                            /**< Software Register Programming Control Status, offset: 0x324 */
       uint8_t RESERVED_15[68];
  __IO uint32_t POISONCFG;                         /**< AXI Poison Configuration Register., offset: 0x36C */
  __I  uint32_t POISONSTAT;                        /**< AXI Poison Status Register, offset: 0x370 */
       uint8_t RESERVED_16[136];
  __I  uint32_t PSTAT;                             /**< Port Status Register, offset: 0x3FC */
  __IO uint32_t PCCFG;                             /**< Port Common Configuration Register, offset: 0x400 */
  __IO uint32_t PCFGR_0;                           /**< Port n Configuration Read Register, offset: 0x404 */
  __IO uint32_t PCFGW_0;                           /**< Port n Configuration Write Register, offset: 0x408 */
       uint8_t RESERVED_17[132];
  __IO uint32_t PCTRL_0;                           /**< Port n Control Register, offset: 0x490 */
  __IO uint32_t PCFGQOS0_0;                        /**< Port n Read QoS Configuration Register 0, offset: 0x494 */
  __IO uint32_t PCFGQOS1_0;                        /**< Port n Read QoS Configuration Register 1, offset: 0x498 */
  __IO uint32_t PCFGWQOS0_0;                       /**< Port n Write QoS Configuration Register 0, offset: 0x49C */
  __IO uint32_t PCFGWQOS1_0;                       /**< Port n Write QoS Configuration Register 1, offset: 0x4A0 */
       uint8_t RESERVED_18[7036];
  __IO uint32_t DERATEEN_SHADOW;                   /**< [SHADOW] Temperature Derate Enable Register, offset: 0x2020 */
  __IO uint32_t DERATEINT_SHADOW;                  /**< [SHADOW] Temperature Derate Interval Register, offset: 0x2024 */
       uint8_t RESERVED_19[40];
  __IO uint32_t RFSHCTL0_SHADOW;                   /**< [SHADOW] Refresh Control Register 0, offset: 0x2050 */
       uint8_t RESERVED_20[16];
  __IO uint32_t RFSHTMG_SHADOW;                    /**< [SHADOW] Refresh Timing Register, offset: 0x2064 */
       uint8_t RESERVED_21[116];
  __IO uint32_t INIT3_SHADOW;                      /**< [SHADOW] SDRAM Initialization Register 3, offset: 0x20DC */
  __IO uint32_t INIT4_SHADOW;                      /**< [SHADOW] SDRAM Initialization Register 4, offset: 0x20E0 */
       uint8_t RESERVED_22[4];
  __IO uint32_t INIT6_SHADOW;                      /**< [SHADOW] SDRAM Initialization Register 6, offset: 0x20E8 */
  __IO uint32_t INIT7_SHADOW;                      /**< [SHADOW] SDRAM Initialization Register 7, offset: 0x20EC */
       uint8_t RESERVED_23[16];
  __IO uint32_t DRAMTMG0_SHADOW;                   /**< [SHADOW] SDRAM Timing Register 0, offset: 0x2100 */
  __IO uint32_t DRAMTMG1_SHADOW;                   /**< [SHADOW] SDRAM Timing Register 1, offset: 0x2104 */
  __IO uint32_t DRAMTMG2_SHADOW;                   /**< [SHADOW] SDRAM Timing Register 2, offset: 0x2108 */
  __IO uint32_t DRAMTMG3_SHADOW;                   /**< [SHADOW] SDRAM Timing Register 3, offset: 0x210C */
  __IO uint32_t DRAMTMG4_SHADOW;                   /**< [SHADOW] SDRAM Timing Register 4, offset: 0x2110 */
  __IO uint32_t DRAMTMG5_SHADOW;                   /**< [SHADOW] SDRAM Timing Register 5, offset: 0x2114 */
  __IO uint32_t DRAMTMG6_SHADOW;                   /**< [SHADOW] SDRAM Timing Register 6, offset: 0x2118 */
  __IO uint32_t DRAMTMG7_SHADOW;                   /**< [SHADOW] SDRAM Timing Register 7, offset: 0x211C */
  __IO uint32_t DRAMTMG8_SHADOW;                   /**< [SHADOW] SDRAM Timing Register 8, offset: 0x2120 */
  __IO uint32_t DRAMTMG9_SHADOW;                   /**< [SHADOW] SDRAM Timing Register 9, offset: 0x2124 */
  __IO uint32_t DRAMTMG10_SHADOW;                  /**< [SHADOW] SDRAM Timing Register 10, offset: 0x2128 */
  __IO uint32_t DRAMTMG11_SHADOW;                  /**< [SHADOW] SDRAM Timing Register 11, offset: 0x212C */
  __IO uint32_t DRAMTMG12_SHADOW;                  /**< [SHADOW] SDRAM Timing Register 12, offset: 0x2130 */
  __IO uint32_t DRAMTMG13_SHADOW;                  /**< [SHADOW] SDRAM Timing Register 13, offset: 0x2134 */
  __IO uint32_t DRAMTMG14_SHADOW;                  /**< [SHADOW] SDRAM Timing Register 14, offset: 0x2138 */
  __IO uint32_t DRAMTMG15_SHADOW;                  /**< [SHADOW] SDRAM Timing Register 15, offset: 0x213C */
       uint8_t RESERVED_24[64];
  __IO uint32_t ZQCTL0_SHADOW;                     /**< [SHADOW] ZQ Control Register 0, offset: 0x2180 */
       uint8_t RESERVED_25[12];
  __IO uint32_t DFITMG0_SHADOW;                    /**< [SHADOW] DFI Timing Register 0, offset: 0x2190 */
  __IO uint32_t DFITMG1_SHADOW;                    /**< [SHADOW] DFI Timing Register 1, offset: 0x2194 */
       uint8_t RESERVED_26[28];
  __IO uint32_t DFITMG2_SHADOW;                    /**< [SHADOW] DFI Timing Register 2, offset: 0x21B4 */
  __IO uint32_t DFITMG3_SHADOW;                    /**< [SHADOW] DFI Timing Register 3, offset: 0x21B8 */
       uint8_t RESERVED_27[132];
  __IO uint32_t ODTCFG_SHADOW;                     /**< [SHADOW] ODT Configuration Register, offset: 0x2240 */
} DDRC_Type;

/* ----------------------------------------------------------------------------
   -- DDRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDRC_Register_Masks DDRC Register Masks
 * @{
 */

/*! @name MSTR - Master Register0 */
/*! @{ */

#define DDRC_MSTR_ddr3_MASK                      (0x1U)
#define DDRC_MSTR_ddr3_SHIFT                     (0U)
/*! ddr3 - Select DDR3 SDRAM - 1 - DDR3 SDRAM device in use - 0 - non-DDR3 SDRAM device in use Only
 *    present in designs that support DDR3.
 */
#define DDRC_MSTR_ddr3(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_ddr3_SHIFT)) & DDRC_MSTR_ddr3_MASK)

#define DDRC_MSTR_lpddr2_MASK                    (0x4U)
#define DDRC_MSTR_lpddr2_SHIFT                   (2U)
/*! lpddr2 - Select LPDDR2 SDRAM - 1 - LPDDR2 SDRAM device in use. - 0 - non-LPDDR2 device in use
 *    Present only in designs configured to support LPDDR2.
 */
#define DDRC_MSTR_lpddr2(x)                      (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_lpddr2_SHIFT)) & DDRC_MSTR_lpddr2_MASK)

#define DDRC_MSTR_lpddr3_MASK                    (0x8U)
#define DDRC_MSTR_lpddr3_SHIFT                   (3U)
/*! lpddr3 - Select LPDDR3 SDRAM - 1 - LPDDR3 SDRAM device in use. - 0 - non-LPDDR3 device in use
 *    Present only in designs configured to support LPDDR3.
 */
#define DDRC_MSTR_lpddr3(x)                      (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_lpddr3_SHIFT)) & DDRC_MSTR_lpddr3_MASK)

#define DDRC_MSTR_ddr4_MASK                      (0x10U)
#define DDRC_MSTR_ddr4_SHIFT                     (4U)
/*! ddr4 - Select DDR4 SDRAM - 1 - DDR4 SDRAM device in use. - 0 - non-DDR4 device in use Present
 *    only in designs configured to support DDR4.
 */
#define DDRC_MSTR_ddr4(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_ddr4_SHIFT)) & DDRC_MSTR_ddr4_MASK)

#define DDRC_MSTR_lpddr4_MASK                    (0x20U)
#define DDRC_MSTR_lpddr4_SHIFT                   (5U)
/*! lpddr4 - Select LPDDR4 SDRAM - 1 - LPDDR4 SDRAM device in use. - 0 - non-LPDDR4 device in use
 *    Present only in designs configured to support LPDDR4.
 */
#define DDRC_MSTR_lpddr4(x)                      (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_lpddr4_SHIFT)) & DDRC_MSTR_lpddr4_MASK)

#define DDRC_MSTR_burstchop_MASK                 (0x200U)
#define DDRC_MSTR_burstchop_SHIFT                (9U)
/*! burstchop - When set, enable burst-chop (BC4 or 8 on-the-fly) in DDR3/DDR4. Burst Chop for Reads
 *    is exercised only in HIF configurations (DDRC_INCL_ARB not set) and if in full bus width mode
 *    (MSTR.data_bus_width = 00) and if MEMC_BURST_LENGTH=8 or 16. Burst Chop for Writes is
 *    exercised only if Partial Writes enabled (DDRC_PARTIAL_WR=1) and if CRC is disabled
 *    (CRCPARCTL1.crc_enable = 0). If DDR4 CRC/parity retry is enabled (CRCPARCTL1.crc_parity_retry_enable = 1),
 *    burst chop is not supported, and this bit must be set to '0'. BC4 (fixed) mode is not supported.
 */
#define DDRC_MSTR_burstchop(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_burstchop_SHIFT)) & DDRC_MSTR_burstchop_MASK)

#define DDRC_MSTR_en_2t_timing_mode_MASK         (0x400U)
#define DDRC_MSTR_en_2t_timing_mode_SHIFT        (10U)
/*! en_2t_timing_mode - If 1, then DDRC uses 2T timing. Otherwise, uses 1T timing. In 2T timing, all
 *    command signals (except chip select) are held for 2 clocks on the SDRAM bus. Chip select is
 *    asserted on the second cycle of the command Note: 2T timing is not supported in
 *    LPDDR2/LPDDR3/LPDDR4 mode Note: 2T timing is not supported if the configuration parameter MEMC_CMD_RTN2IDLE
 *    is set Note: 2T timing is not supported in DDR4 geardown mode. Note: 2T timing is not supported
 *    in Shared-AC dual channel mode and the register value is don't care.
 */
#define DDRC_MSTR_en_2t_timing_mode(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_en_2t_timing_mode_SHIFT)) & DDRC_MSTR_en_2t_timing_mode_MASK)

#define DDRC_MSTR_geardown_mode_MASK             (0x800U)
#define DDRC_MSTR_geardown_mode_SHIFT            (11U)
/*! geardown_mode - 1 indicates put the DRAM in geardown mode (2N) and 0 indicates put the DRAM in
 *    normal mode (1N). This register can be changed, only when the Controller is in self-refresh
 *    mode. This signal must be set the same value as MR3 bit A3. Note: Geardown mode is not supported
 *    if the configuration parameter MEMC_CMD_RTN2IDLE is set Note: Geardown mode is not supported
 *    if the configuration parameter DDRC_SHARED_AC is set (in Shared-AC mode) and the register value
 *    is don't care
 */
#define DDRC_MSTR_geardown_mode(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_geardown_mode_SHIFT)) & DDRC_MSTR_geardown_mode_MASK)

#define DDRC_MSTR_data_bus_width_MASK            (0x3000U)
#define DDRC_MSTR_data_bus_width_SHIFT           (12U)
/*! data_bus_width - Selects proportion of DQ bus width that is used by the SDRAM - 00 - Full DQ bus
 *    width to SDRAM - 01 - Half DQ bus width to SDRAM - 10 - Quarter DQ bus width to SDRAM - 11 -
 *    Reserved. Note that half bus width mode is only supported when the SDRAM bus width is a
 *    multiple of 16, and quarter bus width mode is only supported when the SDRAM bus width is a multiple
 *    of 32 and the configuration parameter MEMC_QBUS_SUPPORT is set. Bus width refers to DQ bus
 *    width (excluding any ECC width).
 */
#define DDRC_MSTR_data_bus_width(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_data_bus_width_SHIFT)) & DDRC_MSTR_data_bus_width_MASK)

#define DDRC_MSTR_dll_off_mode_MASK              (0x8000U)
#define DDRC_MSTR_dll_off_mode_SHIFT             (15U)
/*! dll_off_mode - Set to 1 when the DDRC and DRAM has to be put in DLL-off mode for low frequency
 *    operation. Set to 0 to put DDRC and DRAM in DLL-on mode for normal frequency operation. If DDR4
 *    CRC/parity retry is enabled (CRCPARCTL1.crc_parity_retry_enable = 1), dll_off_mode is not
 *    supported, and this bit must be set to '0'.
 */
#define DDRC_MSTR_dll_off_mode(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_dll_off_mode_SHIFT)) & DDRC_MSTR_dll_off_mode_MASK)

#define DDRC_MSTR_burst_rdwr_MASK                (0xF0000U)
#define DDRC_MSTR_burst_rdwr_SHIFT               (16U)
/*! burst_rdwr - SDRAM burst length used
 *  0b0001..Burst length of 2 (only supported for mDDR)
 *  0b0010..Burst length of 4
 *  0b0100..Burst length of 8
 *  0b1000..Burst length of 16 (only supported for mDDR, LPDDR2, and LPDDR4)
 */
#define DDRC_MSTR_burst_rdwr(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_burst_rdwr_SHIFT)) & DDRC_MSTR_burst_rdwr_MASK)

#define DDRC_MSTR_frequency_ratio_MASK           (0x400000U)
#define DDRC_MSTR_frequency_ratio_SHIFT          (22U)
/*! frequency_ratio - Selects the Frequency Ratio
 *  0b0..1:2 Mode
 *  0b1..1:1 Mode
 */
#define DDRC_MSTR_frequency_ratio(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_frequency_ratio_SHIFT)) & DDRC_MSTR_frequency_ratio_MASK)

#define DDRC_MSTR_active_ranks_MASK              (0x3000000U)
#define DDRC_MSTR_active_ranks_SHIFT             (24U)
/*! active_ranks - Only present for multi-rank configurations. Each bit represents one rank. For
 *    two-rank configurations, only bits[25:24] are present.
 */
#define DDRC_MSTR_active_ranks(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_active_ranks_SHIFT)) & DDRC_MSTR_active_ranks_MASK)

#define DDRC_MSTR_frequency_mode_MASK            (0x20000000U)
#define DDRC_MSTR_frequency_mode_SHIFT           (29U)
/*! frequency_mode - Choose which registers are used.
 *  0b0..Original Registers
 *  0b1..Shadow Registers
 */
#define DDRC_MSTR_frequency_mode(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_frequency_mode_SHIFT)) & DDRC_MSTR_frequency_mode_MASK)

#define DDRC_MSTR_device_config_MASK             (0xC0000000U)
#define DDRC_MSTR_device_config_SHIFT            (30U)
/*! device_config - Indicates the configuration of the device used in the system.
 *  0b00..x4 device
 *  0b01..x8 device
 *  0b10..x16 device
 *  0b11..x32 device
 */
#define DDRC_MSTR_device_config(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR_device_config_SHIFT)) & DDRC_MSTR_device_config_MASK)
/*! @} */

/*! @name STAT - Operating Mode Status Register */
/*! @{ */

#define DDRC_STAT_operating_mode_MASK            (0x7U)
#define DDRC_STAT_operating_mode_SHIFT           (0U)
/*! operating_mode - Operating mode */
#define DDRC_STAT_operating_mode(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_STAT_operating_mode_SHIFT)) & DDRC_STAT_operating_mode_MASK)

#define DDRC_STAT_selfref_type_MASK              (0x30U)
#define DDRC_STAT_selfref_type_SHIFT             (4U)
/*! selfref_type - Flags if Self Refresh (except LPDDR4) or SR-Powerdown (LPDDR4) is entered and if
 *    it was under Automatic Self Refresh control only or not.
 *  0b00..SDRAM is not in Self Refresh (except LPDDR4) or SR-Powerdown (LPDDR4). If retry is enabled by
 *        CRCPARCTRL1.crc_parity_retry_enable, this also indicates SRE command is still in parity error window or retry is
 *        in-progress.
 *  0b10..SDRAM is in Self Refresh (except LPDDR4) or SR-Powerdown (LPDDR4), which was not caused solely under
 *        Automatic Self Refresh control. It could have been caused by Hardware Low Power Interface and/or Software
 *        (reg_ddrc_selfref_sw). If retry is enabled, this guarantees SRE command is executed correctly without parity
 *  0b11..SDRAM is in Self Refresh (except LPDDR4) or SR-Powerdown (LPDDR4), which was caused by Automatic Self
 *        Refresh only. If retry is enabled, this guarantees SRE command is executed correctly without parity error.
 */
#define DDRC_STAT_selfref_type(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_STAT_selfref_type_SHIFT)) & DDRC_STAT_selfref_type_MASK)

#define DDRC_STAT_selfref_state_MASK             (0x300U)
#define DDRC_STAT_selfref_state_SHIFT            (8U)
/*! selfref_state - Self refresh state. This indicates self refresh or self refresh power down state
 *    for LPDDR4. This register is used for frequency change and MRR/MRW access during self refresh.
 *  0b00..SDRAM is not in Self Refresh.
 *  0b01..Self refresh 1
 *  0b10..Self refresh power down
 *  0b11..Self refresh
 */
#define DDRC_STAT_selfref_state(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_STAT_selfref_state_SHIFT)) & DDRC_STAT_selfref_state_MASK)
/*! @} */

/*! @name MSTR1 - Operating Mode Status Register */
/*! @{ */

#define DDRC_MSTR1_rank_tmgreg_sel_MASK          (0x3U)
#define DDRC_MSTR1_rank_tmgreg_sel_SHIFT         (0U)
/*! rank_tmgreg_sel - rank_tmgreg_sel
 *  0b00..USE DRAMTMGx registers for the rank
 *  0b01..USE MRAMTMGx registers for the rank
 */
#define DDRC_MSTR1_rank_tmgreg_sel(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR1_rank_tmgreg_sel_SHIFT)) & DDRC_MSTR1_rank_tmgreg_sel_MASK)

#define DDRC_MSTR1_alt_addrmap_en_MASK           (0x10000U)
#define DDRC_MSTR1_alt_addrmap_en_SHIFT          (16U)
/*! alt_addrmap_en - Enable Alternative Address Map
 *  0b0..Disable Alternative Address Map
 *  0b1..Enable Alternative Address Map
 */
#define DDRC_MSTR1_alt_addrmap_en(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_MSTR1_alt_addrmap_en_SHIFT)) & DDRC_MSTR1_alt_addrmap_en_MASK)
/*! @} */

/*! @name MRCTRL3 - Operating Mode Status Register */
/*! @{ */

#define DDRC_MRCTRL3_mr_rank_sel_MASK            (0x3U)
#define DDRC_MRCTRL3_mr_rank_sel_SHIFT           (0U)
/*! mr_rank_sel - mr_rank_sel */
#define DDRC_MRCTRL3_mr_rank_sel(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_MRCTRL3_mr_rank_sel_SHIFT)) & DDRC_MRCTRL3_mr_rank_sel_MASK)
/*! @} */

/*! @name MRCTRL0 - Mode Register Read/Write Control Register 0. */
/*! @{ */

#define DDRC_MRCTRL0_mr_type_MASK                (0x1U)
#define DDRC_MRCTRL0_mr_type_SHIFT               (0U)
/*! mr_type - Indicates whether the mode register operation is read or write. Only used for LPDDR2/LPDDR3/LPDDR4/DDR4.
 *  0b0..Write
 *  0b1..Read
 */
#define DDRC_MRCTRL0_mr_type(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_MRCTRL0_mr_type_SHIFT)) & DDRC_MRCTRL0_mr_type_MASK)

#define DDRC_MRCTRL0_mpr_en_MASK                 (0x2U)
#define DDRC_MRCTRL0_mpr_en_SHIFT                (1U)
/*! mpr_en - Indicates whether the mode register operation is MRS or WR/RD for MPR (only supported for DDR4).
 *  0b0..MRS
 *  0b1..WR/RD for MPR
 */
#define DDRC_MRCTRL0_mpr_en(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_MRCTRL0_mpr_en_SHIFT)) & DDRC_MRCTRL0_mpr_en_MASK)

#define DDRC_MRCTRL0_pda_en_MASK                 (0x4U)
#define DDRC_MRCTRL0_pda_en_SHIFT                (2U)
/*! pda_en - Indicates whether the mode register operation is MRS in PDA mode or not. Note that when
 *    pba_mode=1, PBA access is initiated instead of PDA access.
 *  0b0..MRS
 *  0b1..MRS in Per DRAM Addressability
 */
#define DDRC_MRCTRL0_pda_en(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_MRCTRL0_pda_en_SHIFT)) & DDRC_MRCTRL0_pda_en_MASK)

#define DDRC_MRCTRL0_sw_init_int_MASK            (0x8U)
#define DDRC_MRCTRL0_sw_init_int_SHIFT           (3U)
/*! sw_init_int - Indicates whether Software intervention is allowed via MRCTRL0/MRCTRL1 before
 *    automatic SDRAM initialization routine or not. For DDR4, this bit can be used to initialize the
 *    DDR4 RCD (MR7) before automatic SDRAM initialization. For LPDDR4, this bit can be used to
 *    program additional mode registers before automatic SDRAM initialization if necessary. In LPDDR4
 *    independent channel mode, note that this must be programmed to both channels beforehand. Note that
 *    this must be cleared to 0 after completing Software operation. Otherwise, SDRAM
 *    initialization routine will not re-start.
 *  0b0..Software intervention is not allowed
 *  0b1..Software intervention is allowed
 */
#define DDRC_MRCTRL0_sw_init_int(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_MRCTRL0_sw_init_int_SHIFT)) & DDRC_MRCTRL0_sw_init_int_MASK)

#define DDRC_MRCTRL0_mr_rank_MASK                (0x30U)
#define DDRC_MRCTRL0_mr_rank_SHIFT               (4U)
/*! mr_rank - Controls which rank is accessed by MRCTRL0.mr_wr. Normally, it is desired to access
 *    all ranks, so all bits should be set to 1. However, for multi-rank UDIMMs/RDIMMs/LRDIMMs which
 *    implement address mirroring, it may be necessary to access ranks individually. Examples (assume
 *    DDRC is configured for 4 ranks): 0x1 - select rank 0 only 0x2 - select rank 1 only 0x5 -
 *    select ranks 0 and 2 0xA - select ranks 1 and 3 0xF - select ranks 0, 1, 2 and 3
 */
#define DDRC_MRCTRL0_mr_rank(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_MRCTRL0_mr_rank_SHIFT)) & DDRC_MRCTRL0_mr_rank_MASK)

#define DDRC_MRCTRL0_mr_addr_MASK                (0xF000U)
#define DDRC_MRCTRL0_mr_addr_SHIFT               (12U)
/*! mr_addr - Address of the mode register that is to be written to.
 *  0b0000..MR0
 *  0b0001..MR1
 *  0b0010..MR2
 *  0b0011..MR3
 *  0b0100..MR4
 *  0b0101..MR5
 *  0b0110..MR6
 *  0b0111..MR7
 */
#define DDRC_MRCTRL0_mr_addr(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_MRCTRL0_mr_addr_SHIFT)) & DDRC_MRCTRL0_mr_addr_MASK)

#define DDRC_MRCTRL0_pba_mode_MASK               (0x40000000U)
#define DDRC_MRCTRL0_pba_mode_SHIFT              (30U)
/*! pba_mode - Indicates whether PBA access is executed. When setting this bit to 1 along with
 *    setting pda_en to 1, DDRC initiates PBA access instead of PDA access. - 0 - Per DRAM Addressability
 *    mode - 1 - Per Buffer Addressability mode The completion of PBA access is confirmed by
 *    MRSTAT.pda_done in the same way as PDA.
 */
#define DDRC_MRCTRL0_pba_mode(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_MRCTRL0_pba_mode_SHIFT)) & DDRC_MRCTRL0_pba_mode_MASK)

#define DDRC_MRCTRL0_mr_wr_MASK                  (0x80000000U)
#define DDRC_MRCTRL0_mr_wr_SHIFT                 (31U)
/*! mr_wr - Setting this register bit to 1 triggers a mode register read or write operation. When
 *    the MR operation is complete, the DDRC automatically clears this bit. The other register fields
 *    of this register must be written in a separate APB transaction, before setting this mr_wr bit.
 *    It is recommended NOT to set this signal if in Init, Deep power-down or MPSM operating modes.
 */
#define DDRC_MRCTRL0_mr_wr(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_MRCTRL0_mr_wr_SHIFT)) & DDRC_MRCTRL0_mr_wr_MASK)
/*! @} */

/*! @name MRCTRL1 - Mode Register Read/Write Control Register 1 */
/*! @{ */

#define DDRC_MRCTRL1_mr_data_MASK                (0x3FFFFU)
#define DDRC_MRCTRL1_mr_data_SHIFT               (0U)
/*! mr_data - Mode register write data for all non-LPDDR2/non-LPDDR3/non-LPDDR4 modes. For
 *    LPDDR2/LPDDR3/LPDDR4, MRCTRL1[15:0] are interpreted as [15:8] MR Address [7:0] MR data for writes,
 *    don't care for reads. This is 18-bits wide in configurations with DDR4 support and 16-bits in all
 *    other configurations.
 */
#define DDRC_MRCTRL1_mr_data(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_MRCTRL1_mr_data_SHIFT)) & DDRC_MRCTRL1_mr_data_MASK)
/*! @} */

/*! @name MRSTAT - Mode Register Read/Write Status Register */
/*! @{ */

#define DDRC_MRSTAT_mr_wr_busy_MASK              (0x1U)
#define DDRC_MRSTAT_mr_wr_busy_SHIFT             (0U)
/*! mr_wr_busy - The SoC core may initiate a MR write operation only if this signal is low. This
 *    signal goes high in the clock after the DDRC accepts the MRW/MRR request. It goes low when the
 *    MRW/MRR command is issued to the SDRAM. It is recommended not to perform MRW/MRR commands when
 *    'MRSTAT.mr_wr_busy' is high.
 *  0b0..Indicates that the SoC core can initiate a mode register write operation
 *  0b1..Indicates that mode register write operation is in progress
 */
#define DDRC_MRSTAT_mr_wr_busy(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_MRSTAT_mr_wr_busy_SHIFT)) & DDRC_MRSTAT_mr_wr_busy_MASK)

#define DDRC_MRSTAT_pda_done_MASK                (0x100U)
#define DDRC_MRSTAT_pda_done_SHIFT               (8U)
/*! pda_done - The SoC core may initiate a MR write operation in PDA/PBA mode only if this signal is
 *    low. This signal goes high when three consecutive MRS commands related to the PDA/PBA mode
 *    are issued to the SDRAM. This signal goes low when MRCTRL0.pda_en becomes 0. Therefore, it is
 *    recommended to write MRCTRL0.pda_en to 0 after this signal goes high in order to prepare to
 *    perform PDA operation next time
 *  0b0..Indicates that mode register write operation related to PDA/PBA is in progress or has not started yet.
 *  0b1..Indicates that mode register write operation related to PDA/PBA has competed.
 */
#define DDRC_MRSTAT_pda_done(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_MRSTAT_pda_done_SHIFT)) & DDRC_MRSTAT_pda_done_MASK)
/*! @} */

/*! @name MRCTRL2 - Mode Register Read/Write Control Register 2 */
/*! @{ */

#define DDRC_MRCTRL2_mr_device_sel_MASK          (0xFFFFFFFFU)
#define DDRC_MRCTRL2_mr_device_sel_SHIFT         (0U)
/*! mr_device_sel - Indicates the device(s) to be selected during the MRS that happens in PDA mode.
 *    Each bit is associated with one device. For example, bit[0] corresponds to Device 0, bit[1] to
 *    Device 1 etc. A '1' should be programmed to indicate that the MRS command should be applied
 *    to that device. A '0' indicates that the MRS commands should be skipped for that device.
 */
#define DDRC_MRCTRL2_mr_device_sel(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_MRCTRL2_mr_device_sel_SHIFT)) & DDRC_MRCTRL2_mr_device_sel_MASK)
/*! @} */

/*! @name DERATEEN - Temperature Derate Enable Register */
/*! @{ */

#define DDRC_DERATEEN_derate_enable_MASK         (0x1U)
#define DDRC_DERATEEN_derate_enable_SHIFT        (0U)
/*! derate_enable - Enables derating. Present only in designs configured to support
 *    LPDDR2/LPDDR3/LPDDR4. This field must be set to '0' for non-LPDDR2/LPDDR3/LPDDR4 mode.
 *  0b0..Timing parameter derating is disabled
 *  0b1..Timing parameter derating is enabled using MR4 read value.
 */
#define DDRC_DERATEEN_derate_enable(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DERATEEN_derate_enable_SHIFT)) & DDRC_DERATEEN_derate_enable_MASK)

#define DDRC_DERATEEN_derate_value_MASK          (0x2U)
#define DDRC_DERATEEN_derate_value_SHIFT         (1U)
/*! derate_value - Derate value. Present only in designs configured to support LPDDR2/LPDDR3/LPDDR4
 *    Set to 0 for all LPDDR2 speed grades as derating value of +1.875 ns is less than a
 *    core_ddrc_core_clk period. For LPDDR3/4, if the period of core_ddrc_core_clk is less than 1.875ns, this
 *    register field should be set to 1; otherwise it should be set to 0.
 *  0b0..Derating uses +1
 *  0b1..Derating uses +2
 */
#define DDRC_DERATEEN_derate_value(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DERATEEN_derate_value_SHIFT)) & DDRC_DERATEEN_derate_value_MASK)

#define DDRC_DERATEEN_derate_byte_MASK           (0xF0U)
#define DDRC_DERATEEN_derate_byte_SHIFT          (4U)
/*! derate_byte - Derate byte Present only in designs configured to support LPDDR2/LPDDR3/LPDDR4
 *    Indicates which byte of the MRR data is used for derating. The maximum valid value depends on
 *    MEMC_DRAM_TOTAL_DATA_WIDTH.
 */
#define DDRC_DERATEEN_derate_byte(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DERATEEN_derate_byte_SHIFT)) & DDRC_DERATEEN_derate_byte_MASK)

#define DDRC_DERATEEN_rc_derate_value_MASK       (0x300U)
#define DDRC_DERATEEN_rc_derate_value_SHIFT      (8U)
/*! rc_derate_value - Derate value of tRC for LPDDR4. Present only in designs configured to support
 *    LPDDR4. The required number of cycles for derating can be determined by dividing 3.75ns by the
 *    core_ddrc_core_clk period, and rounding up the next integer.
 *  0b00..Derating uses +1
 *  0b01..Derating uses +2
 *  0b10..Derating uses +3
 *  0b11..Derating uses +4
 */
#define DDRC_DERATEEN_rc_derate_value(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DERATEEN_rc_derate_value_SHIFT)) & DDRC_DERATEEN_rc_derate_value_MASK)
/*! @} */

/*! @name DERATEINT - Temperature Derate Interval Register */
/*! @{ */

#define DDRC_DERATEINT_mr4_read_interval_MASK    (0xFFFFFFFFU)
#define DDRC_DERATEINT_mr4_read_interval_SHIFT   (0U)
/*! mr4_read_interval - Interval between two MR4 reads, used to derate the timing parameters.
 *    Present only in designs configured to support LPDDR2/LPDDR3/LPDDR4. This register must not be set to
 *    zero. Unit: DFI clock cycle.
 */
#define DDRC_DERATEINT_mr4_read_interval(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_DERATEINT_mr4_read_interval_SHIFT)) & DDRC_DERATEINT_mr4_read_interval_MASK)
/*! @} */

/*! @name PWRCTL - Low Power Control Register */
/*! @{ */

#define DDRC_PWRCTL_selfref_en_MASK              (0x1U)
#define DDRC_PWRCTL_selfref_en_SHIFT             (0U)
/*! selfref_en - If true then the DDRC puts the SDRAM into Self Refresh after a programmable number
 *    of cycles "maximum idle clocks before Self Refresh (PWRTMG.selfref_to_x32)". This register bit
 *    may be re-programmed during the course of normal operation.
 */
#define DDRC_PWRCTL_selfref_en(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PWRCTL_selfref_en_SHIFT)) & DDRC_PWRCTL_selfref_en_MASK)

#define DDRC_PWRCTL_powerdown_en_MASK            (0x2U)
#define DDRC_PWRCTL_powerdown_en_SHIFT           (1U)
/*! powerdown_en - If true then the DDRC goes into power-down after a programmable number of cycles
 *    "maximum idle clocks before power down" (PWRTMG.powerdown_to_x32). This register bit may be
 *    re-programmed during the course of normal operation.
 */
#define DDRC_PWRCTL_powerdown_en(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_PWRCTL_powerdown_en_SHIFT)) & DDRC_PWRCTL_powerdown_en_MASK)

#define DDRC_PWRCTL_deeppowerdown_en_MASK        (0x4U)
#define DDRC_PWRCTL_deeppowerdown_en_SHIFT       (2U)
/*! deeppowerdown_en - When this is 1, DDRC puts the SDRAM into deep power-down mode when the
 *    transaction store is empty. This register must be reset to '0' to bring DDRC out of deep power-down
 *    mode. Controller performs automatic SDRAM initialization on deep power-down exit. Present only
 *    in designs configured to support mDDR or LPDDR2 or LPDDR3. For
 *    non-mDDR/non-LPDDR2/non-LPDDR3, this register should not be set to 1. FOR PERFORMANCE ONLY.
 */
#define DDRC_PWRCTL_deeppowerdown_en(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_PWRCTL_deeppowerdown_en_SHIFT)) & DDRC_PWRCTL_deeppowerdown_en_MASK)

#define DDRC_PWRCTL_en_dfi_dram_clk_disable_MASK (0x8U)
#define DDRC_PWRCTL_en_dfi_dram_clk_disable_SHIFT (3U)
/*! en_dfi_dram_clk_disable - Enable the assertion of dfi_dram_clk_disable whenever a clock is not
 *    required by the SDRAM. If set to 0, dfi_dram_clk_disable is never asserted. Assertion of
 *    dfi_dram_clk_disable is as follows: In DDR2/DDR3, can only be asserted in Self Refresh. In DDR4, can
 *    be asserted in following: in Self Refresh in Maximum Power Saving Mode In mDDR/LPDDR2/LPDDR3,
 *    can be asserted in following: in Self Refresh in Power Down in Deep Power Down during Normal
 *    operation (Clock Stop) In LPDDR4, can be asserted in following: in Self Refresh Power Down in
 *    Power Down during Normal operation (Clock Stop)
 */
#define DDRC_PWRCTL_en_dfi_dram_clk_disable(x)   (((uint32_t)(((uint32_t)(x)) << DDRC_PWRCTL_en_dfi_dram_clk_disable_SHIFT)) & DDRC_PWRCTL_en_dfi_dram_clk_disable_MASK)

#define DDRC_PWRCTL_mpsm_en_MASK                 (0x10U)
#define DDRC_PWRCTL_mpsm_en_SHIFT                (4U)
/*! mpsm_en - When this is 1, the DDRC puts the SDRAM into maximum power saving mode when the
 *    transaction store is empty. This register must be reset to '0' to bring DDRC out of maximum power
 *    saving mode. Present only in designs configured to support DDR4. For non-DDR4, this register
 *    should not be set to 1. Note that MPSM is not supported when using a DDR PHY, if the PHY
 *    parameter DDRC_AC_CS_USE is disabled, as the MPSM exit sequence requires the chip-select signal to
 *    toggle. FOR PERFORMANCE ONLY.
 */
#define DDRC_PWRCTL_mpsm_en(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_PWRCTL_mpsm_en_SHIFT)) & DDRC_PWRCTL_mpsm_en_MASK)

#define DDRC_PWRCTL_selfref_sw_MASK              (0x20U)
#define DDRC_PWRCTL_selfref_sw_SHIFT             (5U)
/*! selfref_sw - A value of 1 to this register causes system to move to Self Refresh state
 *    immediately, as long as it is not in INIT or DPD/MPSM operating_mode. This is referred to as Software
 *    Entry/Exit to Self Refresh.
 *  0b0..Software Exit from Self Refresh
 *  0b1..Software Entry to Self Refresh
 */
#define DDRC_PWRCTL_selfref_sw(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PWRCTL_selfref_sw_SHIFT)) & DDRC_PWRCTL_selfref_sw_MASK)

#define DDRC_PWRCTL_stay_in_selfref_MASK         (0x40U)
#define DDRC_PWRCTL_stay_in_selfref_SHIFT        (6U)
/*! stay_in_selfref - Self refresh state is an intermediate state to enter to Self refresh power
 *    down state or exit Self refresh power down state for LPDDR4. This register controls transition
 *    from the Self refresh state. - 1 - Prohibit transition from Self refresh state - 0 - Allow
 *    transition from Self refresh state
 *  0b0..
 *  0b1..
 */
#define DDRC_PWRCTL_stay_in_selfref(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_PWRCTL_stay_in_selfref_SHIFT)) & DDRC_PWRCTL_stay_in_selfref_MASK)
/*! @} */

/*! @name PWRTMG - Low Power Timing Register */
/*! @{ */

#define DDRC_PWRTMG_powerdown_to_x32_MASK        (0x1FU)
#define DDRC_PWRTMG_powerdown_to_x32_SHIFT       (0U)
/*! powerdown_to_x32 - After this many clocks of the DDRC command channel being idle the DDRC
 *    automatically puts the SDRAM into power-down. The DDRC command channel is considered idle when there
 *    are no HIF commands outstanding. This must be enabled in the PWRCTL.powerdown_en. Unit:
 *    Multiples of 32 DFI clocks FOR PERFORMANCE ONLY.
 */
#define DDRC_PWRTMG_powerdown_to_x32(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_PWRTMG_powerdown_to_x32_SHIFT)) & DDRC_PWRTMG_powerdown_to_x32_MASK)

#define DDRC_PWRTMG_t_dpd_x4096_MASK             (0xFF00U)
#define DDRC_PWRTMG_t_dpd_x4096_SHIFT            (8U)
/*! t_dpd_x4096 - Minimum deep power-down time. For mDDR, value from the JEDEC specification is 0 as
 *    mDDR exits from deep power-down mode immediately after PWRCTL.deeppowerdown_en is
 *    de-asserted. For LPDDR2/LPDDR3, value from the JEDEC specification is 500us. Unit: Multiples of 4096 DFI
 *    clocks. Present only in designs configured to support mDDR, LPDDR2 or LPDDR3. FOR PERFORMANCE
 *    ONLY.
 */
#define DDRC_PWRTMG_t_dpd_x4096(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_PWRTMG_t_dpd_x4096_SHIFT)) & DDRC_PWRTMG_t_dpd_x4096_MASK)

#define DDRC_PWRTMG_selfref_to_x32_MASK          (0xFF0000U)
#define DDRC_PWRTMG_selfref_to_x32_SHIFT         (16U)
/*! selfref_to_x32 - After this many clocks of the DDRC command channel being idle the DDRC
 *    automatically puts the SDRAM into Self Refresh. The DDRC command channel is considered idle when there
 *    are no HIF commands outstanding. This must be enabled in the PWRCTL.selfref_en. Unit:
 *    Multiples of 32 DFI clocks. FOR PERFORMANCE ONLY.
 */
#define DDRC_PWRTMG_selfref_to_x32(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_PWRTMG_selfref_to_x32_SHIFT)) & DDRC_PWRTMG_selfref_to_x32_MASK)
/*! @} */

/*! @name HWLPCTL - Hardware Low Power Control Register */
/*! @{ */

#define DDRC_HWLPCTL_hw_lp_en_MASK               (0x1U)
#define DDRC_HWLPCTL_hw_lp_en_SHIFT              (0U)
/*! hw_lp_en - Enable for Hardware Low Power Interface. */
#define DDRC_HWLPCTL_hw_lp_en(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_HWLPCTL_hw_lp_en_SHIFT)) & DDRC_HWLPCTL_hw_lp_en_MASK)

#define DDRC_HWLPCTL_hw_lp_exit_idle_en_MASK     (0x2U)
#define DDRC_HWLPCTL_hw_lp_exit_idle_en_SHIFT    (1U)
/*! hw_lp_exit_idle_en - When this bit is programmed to 1 the cactive_in_ddrc pin of the DDRC can be
 *    used to exit from the automatic clock stop, automatic power down or automatic self-refresh
 *    modes. Note, it will not cause exit of Self-Refresh that was caused by Hardware Low Power
 *    Interface and/or Software (PWRCTL.selfref_sw).
 */
#define DDRC_HWLPCTL_hw_lp_exit_idle_en(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_HWLPCTL_hw_lp_exit_idle_en_SHIFT)) & DDRC_HWLPCTL_hw_lp_exit_idle_en_MASK)

#define DDRC_HWLPCTL_hw_lp_idle_x32_MASK         (0xFFF0000U)
#define DDRC_HWLPCTL_hw_lp_idle_x32_SHIFT        (16U)
/*! hw_lp_idle_x32 - Hardware idle period. The cactive_ddrc output is driven low if the DDRC command
 *    channel is idle for hw_lp_idle * 32 cycles if not in INIT or DPD/MPSM operating_mode. The
 *    DDRC command channel is considered idle when there are no HIF commands outstanding. The hardware
 *    idle function is disabled when hw_lp_idle_x32=0. Unit: Multiples of 32 DFI clocks. FOR
 *    PERFORMANCE ONLY.
 */
#define DDRC_HWLPCTL_hw_lp_idle_x32(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_HWLPCTL_hw_lp_idle_x32_SHIFT)) & DDRC_HWLPCTL_hw_lp_idle_x32_MASK)
/*! @} */

/*! @name RFSHCTL0 - Refresh Control Register 0 */
/*! @{ */

#define DDRC_RFSHCTL0_per_bank_refresh_MASK      (0x4U)
#define DDRC_RFSHCTL0_per_bank_refresh_SHIFT     (2U)
/*! per_bank_refresh - Per bank refresh allows traffic to flow to other banks. Per bank refresh is
 *    not supported by all LPDDR2 devices but should be supported by all LPDDR3/LPDDR4 devices.
 *    Present only in designs configured to support LPDDR2/LPDDR3/LPDDR4
 *  0b0..All bank refresh
 *  0b1..Per bank refresh
 */
#define DDRC_RFSHCTL0_per_bank_refresh(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHCTL0_per_bank_refresh_SHIFT)) & DDRC_RFSHCTL0_per_bank_refresh_MASK)

#define DDRC_RFSHCTL0_refresh_burst_MASK         (0x1F0U)
#define DDRC_RFSHCTL0_refresh_burst_SHIFT        (4U)
/*! refresh_burst - The programmed value + 1 is the number of refresh timeouts that is allowed to
 *    accumulate before traffic is blocked and the refreshes are forced to execute. Closing pages to
 *    perform a refresh is a one-time penalty that must be paid for each group of refreshes.
 *    Therefore, performing refreshes in a burst reduces the per-refresh penalty of these page closings.
 *    Higher numbers for RFSHCTL.refresh_burst slightly increases utilization; lower numbers decreases
 *    the worst-case latency associated with refreshes. - 0 - single refresh - 1 - burst-of-2
 *    refresh - 7 - burst-of-8 refresh For information on burst refresh feature refer to section 3.9 of
 *    DDR2 JEDEC specification - JESD79-2F.pdf. For DDR2/3, the refresh is always per-rank and not
 *    per-bank. The rank refresh can be accumulated over 8*tREFI cycles using the burst refresh
 *    feature. In DDR4 mode, according to Fine Granularity feature, 8 refreshes can be postponed in 1X
 *    mode, 16 refreshes in 2X mode and 32 refreshes in 4X mode. If using PHY-initiated updates, care
 *    must be taken in the setting of RFSHCTL0.refresh_burst, to ensure that tRFCmax is not violated
 *    due to a PHY-initiated update occurring shortly before a refresh burst was due. In this
 *    situation, the refresh burst will be delayed until the PHY-initiated update is complete.
 */
#define DDRC_RFSHCTL0_refresh_burst(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHCTL0_refresh_burst_SHIFT)) & DDRC_RFSHCTL0_refresh_burst_MASK)

#define DDRC_RFSHCTL0_refresh_to_x32_MASK        (0x1F000U)
#define DDRC_RFSHCTL0_refresh_to_x32_SHIFT       (12U)
/*! refresh_to_x32 - If the refresh timer (tRFCnom, also known as tREFI) has expired at least once,
 *    but it has not expired (RFSHCTL0.refresh_burst+1) times yet, then a speculative refresh may be
 *    performed. A speculative refresh is a refresh performed at a time when refresh would be
 *    useful, but before it is absolutely required. When the SDRAM bus is idle for a period of time
 *    determined by this RFSHCTL0.refresh_to_x32 and the refresh timer has expired at least once since
 *    the last refresh, then a speculative refresh is performed. Speculative refreshes continues
 *    successively until there are no refreshes pending or until new reads or writes are issued to the
 *    DDRC. FOR PERFORMANCE ONLY. Unit: Multiples of 32 DFI clocks.
 */
#define DDRC_RFSHCTL0_refresh_to_x32(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHCTL0_refresh_to_x32_SHIFT)) & DDRC_RFSHCTL0_refresh_to_x32_MASK)

#define DDRC_RFSHCTL0_refresh_margin_MASK        (0xF00000U)
#define DDRC_RFSHCTL0_refresh_margin_SHIFT       (20U)
/*! refresh_margin - Threshold value in number of DFI clock cycles before the critical refresh or
 *    page timer expires. A critical refresh is to be issued before this threshold is reached. It is
 *    recommended that this not be changed from the default value, currently shown as 0x2. It must
 *    always be less than internally used t_rfc_nom_x32. Note that, in LPDDR2/LPDDR3/LPDDR4,
 *    internally used t_rfc_nom_x32 may be equal to RFSHTMG.t_rfc_nom_x32>>2 if derating is enabled
 *    (DERATEEN.derate_enable=1). Otherwise, internally used t_rfc_nom_x32 will be equal to
 *    RFSHTMG.t_rfc_nom_x32. Unit: Multiples of 32 DFI clocks.
 */
#define DDRC_RFSHCTL0_refresh_margin(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHCTL0_refresh_margin_SHIFT)) & DDRC_RFSHCTL0_refresh_margin_MASK)
/*! @} */

/*! @name RFSHCTL1 - Refresh Control Register 1 */
/*! @{ */

#define DDRC_RFSHCTL1_refresh_timer0_start_value_x32_MASK (0xFFFU)
#define DDRC_RFSHCTL1_refresh_timer0_start_value_x32_SHIFT (0U)
/*! refresh_timer0_start_value_x32 - Refresh timer start for rank 0 (only present in multi-rank
 *    configurations). This is useful in staggering the refreshes to multiple ranks to help traffic to
 *    proceed. This is explained in Refresh Controls section of architecture chapter. Unit: Multiples
 *    of 32 DFI clock cycles. FOR PERFORMANCE ONLY.
 */
#define DDRC_RFSHCTL1_refresh_timer0_start_value_x32(x) (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHCTL1_refresh_timer0_start_value_x32_SHIFT)) & DDRC_RFSHCTL1_refresh_timer0_start_value_x32_MASK)

#define DDRC_RFSHCTL1_refresh_timer1_start_value_x32_MASK (0xFFF0000U)
#define DDRC_RFSHCTL1_refresh_timer1_start_value_x32_SHIFT (16U)
/*! refresh_timer1_start_value_x32 - Refresh timer start for rank 1 (only present in multi-rank
 *    configurations). This is useful in staggering the refreshes to multiple ranks to help traffic to
 *    proceed. This is explained in Refresh Controls section of architecture chapter. Unit: Multiples
 *    of 32 DFI clock cycles. FOR PERFORMANCE ONLY.
 */
#define DDRC_RFSHCTL1_refresh_timer1_start_value_x32(x) (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHCTL1_refresh_timer1_start_value_x32_SHIFT)) & DDRC_RFSHCTL1_refresh_timer1_start_value_x32_MASK)
/*! @} */

/*! @name RFSHCTL3 - Refresh Control Register 3 */
/*! @{ */

#define DDRC_RFSHCTL3_dis_auto_refresh_MASK      (0x1U)
#define DDRC_RFSHCTL3_dis_auto_refresh_SHIFT     (0U)
/*! dis_auto_refresh - When '1', disable auto-refresh generated by the DDRC. When auto-refresh is
 *    disabled, the SoC core must generate refreshes using the registers reg_ddrc_rank0_refresh,
 *    reg_ddrc_rank1_refresh, reg_ddrc_rank2_refresh and reg_ddrc_rank3_refresh. When dis_auto_refresh
 *    transitions from 0 to 1, any pending refreshes are immediately scheduled by the DDRC. If DDR4
 *    CRC/parity retry is enabled (CRCPARCTL1.crc_parity_retry_enable = 1), disable auto-refresh is
 *    not supported, and this bit must be set to '0'. (DDR4 only) If FGR mode is enabled
 *    (RFSHCTL3.refresh_mode > 0), disable auto-refresh is not supported, and this bit must be set to '0'. This
 *    register field is changeable on the fly.
 */
#define DDRC_RFSHCTL3_dis_auto_refresh(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHCTL3_dis_auto_refresh_SHIFT)) & DDRC_RFSHCTL3_dis_auto_refresh_MASK)

#define DDRC_RFSHCTL3_refresh_update_level_MASK  (0x2U)
#define DDRC_RFSHCTL3_refresh_update_level_SHIFT (1U)
/*! refresh_update_level - Toggle this signal (either from 0 to 1 or from 1 to 0) to indicate that
 *    the refresh register(s) have been updated. refresh_update_level must not be toggled when the
 *    DDRC is in reset (core_ddrc_rstn = 0). The refresh register(s) are automatically updated when
 *    exiting reset.
 */
#define DDRC_RFSHCTL3_refresh_update_level(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHCTL3_refresh_update_level_SHIFT)) & DDRC_RFSHCTL3_refresh_update_level_MASK)

#define DDRC_RFSHCTL3_refresh_mode_MASK          (0x70U)
#define DDRC_RFSHCTL3_refresh_mode_SHIFT         (4U)
/*! refresh_mode - Fine Granularity Refresh Mode - 000 - Fixed 1x (Normal mode) - 001 - Fixed 2x -
 *    010 - Fixed 4x - 101 - Enable on the fly 2x (not supported) - 110 - Enable on the fly 4x (not
 *    supported) - Everything else - reserved Note: Only Fixed 1x mode is supported if
 *    RFSHCTL3.dis_auto_refresh = 1. Note: The on-the-fly modes are not supported in this version of the DDRC.
 *    Note: This must be set up while the Controller is in reset or while the Controller is in
 *    self-refresh mode. Changing this during normal operation is not allowed. Making this a dynamic
 *    register will be supported in future version of the DDRC. Note: This register field has effect only
 *    if a DDR4 SDRAM device is in use (MSTR.ddr4 = 1).
 */
#define DDRC_RFSHCTL3_refresh_mode(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHCTL3_refresh_mode_SHIFT)) & DDRC_RFSHCTL3_refresh_mode_MASK)
/*! @} */

/*! @name RFSHTMG - Refresh Timing Register */
/*! @{ */

#define DDRC_RFSHTMG_t_rfc_min_MASK              (0x3FFU)
#define DDRC_RFSHTMG_t_rfc_min_SHIFT             (0U)
/*! t_rfc_min - tRFC (min): Minimum time from refresh to refresh or activate. When the controller is
 *    operating in 1:1 mode, t_rfc_min should be set to RoundUp(tRFCmin/tCK). When the controller
 *    is operating in 1:2 mode, t_rfc_min should be set to RoundUp(RoundUp(tRFCmin/tCK)/2). In
 *    LPDDR2/LPDDR3/LPDDR4 mode: - if using all-bank refreshes, the tRFCmin value in the above equations
 *    is equal to tRFCab - if using per-bank refreshes, the tRFCmin value in the above equations is
 *    equal to tRFCpb In DDR4 mode, the tRFCmin value in the above equations is different depending
 *    on the refresh mode (fixed 1X,2X,4X) and the device density. The user should program the
 *    appropriate value from the spec based on the 'refresh_mode' and the device density that is used.
 *    Unit: Clocks.
 */
#define DDRC_RFSHTMG_t_rfc_min(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHTMG_t_rfc_min_SHIFT)) & DDRC_RFSHTMG_t_rfc_min_MASK)

#define DDRC_RFSHTMG_lpddr3_trefbw_en_MASK       (0x8000U)
#define DDRC_RFSHTMG_lpddr3_trefbw_en_SHIFT      (15U)
/*! lpddr3_trefbw_en - Used only when LPDDR3 memory type is connected. Should only be changed when
 *    DDRC is in reset. Specifies whether to use the tREFBW parameter (required by some LPDDR3
 *    devices which comply with earlier versions of the LPDDR3 JEDEC specification) or not: - 0 - tREFBW
 *    parameter not used - 1 - tREFBW parameter used
 */
#define DDRC_RFSHTMG_lpddr3_trefbw_en(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHTMG_lpddr3_trefbw_en_SHIFT)) & DDRC_RFSHTMG_lpddr3_trefbw_en_MASK)

#define DDRC_RFSHTMG_t_rfc_nom_x32_MASK          (0xFFF0000U)
#define DDRC_RFSHTMG_t_rfc_nom_x32_SHIFT         (16U)
/*! t_rfc_nom_x32 - tREFI: Average time interval between refreshes per rank (Specification: 7.8us
 *    for DDR2, DDR3 and DDR4. See JEDEC specification for mDDR, LPDDR2, LPDDR3 and LPDDR4). For
 *    LPDDR2/LPDDR3/LPDDR4: - if using all-bank refreshes (RFSHCTL0.per_bank_refresh = 0), this register
 *    should be set to tREFIab - if using per-bank refreshes (RFSHCTL0.per_bank_refresh = 1), this
 *    register should be set to tREFIpb When the controller is operating in 1:2 frequency ratio mode,
 *    program this to (tREFI/2), no rounding up. In DDR4 mode, tREFI value is different depending
 *    on the refresh mode. The user should program the appropriate value from the spec based on the
 *    value programmed in the refresh mode register. Note that RFSHTMG.t_rfc_nom_x32 * 32 must be
 *    greater than RFSHTMG.t_rfc_min, and RFSHTMG.t_rfc_nom_x32 must be greater than 0x1. - Non-DDR4 or
 *    DDR4 Fixed 1x mode: RFSHTMG.t_rfc_nom_x32 must be less than or equal to 0xFFE. - DDR4 Fixed
 *    2x mode: RFSHTMG.t_rfc_nom_x32 must be less than or equal to 0x7FF. - DDR4 Fixed 4x mode:
 *    RFSHTMG.t_rfc_nom_x32 must be less than or equal to 0x3FF. Unit: Multiples of 32 clocks.
 */
#define DDRC_RFSHTMG_t_rfc_nom_x32(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHTMG_t_rfc_nom_x32_SHIFT)) & DDRC_RFSHTMG_t_rfc_nom_x32_MASK)
/*! @} */

/*! @name INIT0 - SDRAM Initialization Register 0 */
/*! @{ */

#define DDRC_INIT0_pre_cke_x1024_MASK            (0xFFFU)
#define DDRC_INIT0_pre_cke_x1024_SHIFT           (0U)
/*! pre_cke_x1024 - Cycles to wait after reset before driving CKE high to start the SDRAM
 *    initialization sequence. Unit: 1024 DFI clock cycles. DDR2 specifications typically require this to be
 *    programmed for a delay of >= 200 us. LPDDR2/LPDDR3: tINIT1 of 100 ns (min) LPDDR4: tINIT3 of 2
 *    ms (min) When the controller is operating in 1:2 frequency ratio mode, program this to JEDEC
 *    spec value divided by 2, and round it up to the next integer value. For DDR3/DDR4 RDIMMs, this
 *    should include the time needed to satisfy tSTAB
 */
#define DDRC_INIT0_pre_cke_x1024(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_INIT0_pre_cke_x1024_SHIFT)) & DDRC_INIT0_pre_cke_x1024_MASK)

#define DDRC_INIT0_post_cke_x1024_MASK           (0x3FF0000U)
#define DDRC_INIT0_post_cke_x1024_SHIFT          (16U)
/*! post_cke_x1024 - Cycles to wait after driving CKE high to start the SDRAM initialization
 *    sequence. Unit: 1024 DFI clock cycles. DDR2 typically requires a 400 ns delay, requiring this value
 *    to be programmed to 2 at all clock speeds. LPDDR2/LPDDR3 typically requires this to be
 *    programmed for a delay of 200 us. LPDDR4 typically requires this to be programmed for a delay of 2 us.
 *    When the controller is operating in 1:2 frequency ratio mode, program this to JEDEC spec
 *    value divided by 2, and round it up to the next integer value.
 */
#define DDRC_INIT0_post_cke_x1024(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_INIT0_post_cke_x1024_SHIFT)) & DDRC_INIT0_post_cke_x1024_MASK)

#define DDRC_INIT0_skip_dram_init_MASK           (0xC0000000U)
#define DDRC_INIT0_skip_dram_init_SHIFT          (30U)
/*! skip_dram_init - If lower bit is enabled the SDRAM initialization routine is skipped. The upper
 *    bit decides what state the controller starts up in when reset is removed - 00 - SDRAM
 *    Intialization routine is run after power-up - 01 - SDRAM Initialization routine is skipped after
 *    power-up. Controller starts up in Normal Mode - 11 - SDRAM Initialization routine is skipped after
 *    power-up. Controller starts up in Self-refresh Mode - 10 - SDRAM Initialization routine is run
 *    after power-up.
 *  0b00..SDRAM Initialization routine is run after power-up
 *  0b01..SDRAM Initialization routine is skipped after power-up
 *  0b10..SDRAM Initialization routine is run after power-up
 *  0b11..SDRAM Initialization routine is skipped after power-up
 */
#define DDRC_INIT0_skip_dram_init(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_INIT0_skip_dram_init_SHIFT)) & DDRC_INIT0_skip_dram_init_MASK)
/*! @} */

/*! @name INIT1 - SDRAM Initialization Register 1 */
/*! @{ */

#define DDRC_INIT1_pre_ocd_x32_MASK              (0xFU)
#define DDRC_INIT1_pre_ocd_x32_SHIFT             (0U)
/*! pre_ocd_x32 - Wait period before driving the OCD complete command to SDRAM. Unit: Counts of a
 *    global timer that pulses every 32 DFI clock cycles. There is no known specific requirement for
 *    this; it may be set to zero.
 */
#define DDRC_INIT1_pre_ocd_x32(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_INIT1_pre_ocd_x32_SHIFT)) & DDRC_INIT1_pre_ocd_x32_MASK)

#define DDRC_INIT1_dram_rstn_x1024_MASK          (0x1FF0000U)
#define DDRC_INIT1_dram_rstn_x1024_SHIFT         (16U)
/*! dram_rstn_x1024 - Number of cycles to assert SDRAM reset signal during init sequence. This is
 *    only present for designs supporting DDR3, DDR4 or LPDDR4 devices. For use with a DDR PHY, this
 *    should be set to a minimum of 1. When the controller is operating in 1:2 frequency ratio mode,
 *    program this to JEDEC spec value divided by 2, and round it up to the next integer value.
 *    Unit: 1024 DFI clock cycles.
 */
#define DDRC_INIT1_dram_rstn_x1024(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_INIT1_dram_rstn_x1024_SHIFT)) & DDRC_INIT1_dram_rstn_x1024_MASK)
/*! @} */

/*! @name INIT2 - SDRAM Initialization Register 2 */
/*! @{ */

#define DDRC_INIT2_min_stable_clock_x1_MASK      (0xFU)
#define DDRC_INIT2_min_stable_clock_x1_SHIFT     (0U)
/*! min_stable_clock_x1 - Time to wait after the first CKE high, tINIT2. Present only in designs
 *    configured to support LPDDR2/LPDDR3. LPDDR2/LPDDR3 typically requires 5 x tCK delay. When the
 *    controller is operating in 1:2 frequency ratio mode, program this to JEDEC spec value divided by
 *    2, and round it up to the next integer value. Unit: DFI clock cycles.
 */
#define DDRC_INIT2_min_stable_clock_x1(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_INIT2_min_stable_clock_x1_SHIFT)) & DDRC_INIT2_min_stable_clock_x1_MASK)

#define DDRC_INIT2_idle_after_reset_x32_MASK     (0xFF00U)
#define DDRC_INIT2_idle_after_reset_x32_SHIFT    (8U)
/*! idle_after_reset_x32 - Idle time after the reset command, tINIT4. Present only in designs
 *    configured to support LPDDR2. When the controller is operating in 1:2 frequency ratio mode, program
 *    this to JEDEC spec value divided by 2, and round it up to the next integer value. Unit: 32 DFI
 *    clock cycles.
 */
#define DDRC_INIT2_idle_after_reset_x32(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_INIT2_idle_after_reset_x32_SHIFT)) & DDRC_INIT2_idle_after_reset_x32_MASK)
/*! @} */

/*! @name INIT3 - SDRAM Initialization Register 3 */
/*! @{ */

#define DDRC_INIT3_emr_MASK                      (0xFFFFU)
#define DDRC_INIT3_emr_SHIFT                     (0U)
/*! emr - DDR2: Value to write to EMR register. Bits 9:7 are for OCD and the setting in this
 *    register is ignored. The DDRC sets those bits appropriately. DDR3/DDR4: Value to write to MR1
 *    register Set bit 7 to 0. If PHY-evaluation mode training is enabled, this bit is set appropriately by
 *    the DDRC during write leveling. mDDR: Value to write to EMR register. LPDDR2/LPDDR3/LPDDR4 -
 *    Value to write to MR2 register
 */
#define DDRC_INIT3_emr(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_INIT3_emr_SHIFT)) & DDRC_INIT3_emr_MASK)

#define DDRC_INIT3_mr_MASK                       (0xFFFF0000U)
#define DDRC_INIT3_mr_SHIFT                      (16U)
/*! mr - DDR2: Value to write to MR register. Bit 8 is for DLL and the setting here is ignored. The
 *    DDRC sets this bit appropriately. DDR3/DDR4: Value loaded into MR0 register. mDDR: Value to
 *    write to MR register. LPDDR2/LPDDR3/LPDDR4 - Value to write to MR1 register
 */
#define DDRC_INIT3_mr(x)                         (((uint32_t)(((uint32_t)(x)) << DDRC_INIT3_mr_SHIFT)) & DDRC_INIT3_mr_MASK)
/*! @} */

/*! @name INIT4 - SDRAM Initialization Register 4 */
/*! @{ */

#define DDRC_INIT4_emr3_MASK                     (0xFFFFU)
#define DDRC_INIT4_emr3_SHIFT                    (0U)
/*! emr3 - DDR2: Value to write to EMR3 register. DDR3/DDR4: Value to write to MR3 register
 *    mDDR/LPDDR2/LPDDR3: Unused LPDDR4: Value to write to MR13 register
 */
#define DDRC_INIT4_emr3(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_INIT4_emr3_SHIFT)) & DDRC_INIT4_emr3_MASK)

#define DDRC_INIT4_emr2_MASK                     (0xFFFF0000U)
#define DDRC_INIT4_emr2_SHIFT                    (16U)
/*! emr2 - DDR2: Value to write to EMR2 register. DDR3/DDR4: Value to write to MR2 register
 *    LPDDR2/LPDDR3/LPDDR4: Value to write to MR3 register mDDR: Unused
 */
#define DDRC_INIT4_emr2(x)                       (((uint32_t)(((uint32_t)(x)) << DDRC_INIT4_emr2_SHIFT)) & DDRC_INIT4_emr2_MASK)
/*! @} */

/*! @name INIT5 - SDRAM Initialization Register 5 */
/*! @{ */

#define DDRC_INIT5_max_auto_init_x1024_MASK      (0x3FFU)
#define DDRC_INIT5_max_auto_init_x1024_SHIFT     (0U)
/*! max_auto_init_x1024 - Maximum duration of the auto initialization, tINIT5. Present only in
 *    designs configured to support LPDDR2/LPDDR3. LPDDR2/LPDDR3 typically requires 10 us. Unit: 1024 DFI
 *    clock cycles.
 */
#define DDRC_INIT5_max_auto_init_x1024(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_INIT5_max_auto_init_x1024_SHIFT)) & DDRC_INIT5_max_auto_init_x1024_MASK)

#define DDRC_INIT5_dev_zqinit_x32_MASK           (0xFF0000U)
#define DDRC_INIT5_dev_zqinit_x32_SHIFT          (16U)
/*! dev_zqinit_x32 - ZQ initial calibration, tZQINIT. Present only in designs configured to support
 *    DDR3 or DDR4 or LPDDR2/LPDDR3. DDR3 typically requires 512 SDRAM clock cycles. DDR4 requires
 *    1024 SDRAM clock cycles. LPDDR2/LPDDR3 requires 1 us. When the controller is operating in 1:2
 *    frequency ratio mode, program this to JEDEC spec value divided by 2, and round it up to the
 *    next integer value. Unit: 32 DFI clock cycles.
 */
#define DDRC_INIT5_dev_zqinit_x32(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_INIT5_dev_zqinit_x32_SHIFT)) & DDRC_INIT5_dev_zqinit_x32_MASK)
/*! @} */

/*! @name INIT6 - SDRAM Initialization Register 6 */
/*! @{ */

#define DDRC_INIT6_mr5_MASK                      (0xFFFFU)
#define DDRC_INIT6_mr5_SHIFT                     (0U)
/*! mr5 - DDR4- Value to be loaded into SDRAM MR5 registers. Used in DDR4 designs only. */
#define DDRC_INIT6_mr5(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_INIT6_mr5_SHIFT)) & DDRC_INIT6_mr5_MASK)

#define DDRC_INIT6_mr4_MASK                      (0xFFFF0000U)
#define DDRC_INIT6_mr4_SHIFT                     (16U)
/*! mr4 - DDR4- Value to be loaded into SDRAM MR4 registers. Used in DDR4 designs only. */
#define DDRC_INIT6_mr4(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_INIT6_mr4_SHIFT)) & DDRC_INIT6_mr4_MASK)
/*! @} */

/*! @name INIT7 - SDRAM Initialization Register 7 */
/*! @{ */

#define DDRC_INIT7_mr6_MASK                      (0xFFFF0000U)
#define DDRC_INIT7_mr6_SHIFT                     (16U)
/*! mr6 - DDR4- Value to be loaded into SDRAM MR6 registers. Used in DDR4 designs only. */
#define DDRC_INIT7_mr6(x)                        (((uint32_t)(((uint32_t)(x)) << DDRC_INIT7_mr6_SHIFT)) & DDRC_INIT7_mr6_MASK)
/*! @} */

/*! @name DIMMCTL - DIMM Control Register */
/*! @{ */

#define DDRC_DIMMCTL_dimm_stagger_cs_en_MASK     (0x1U)
#define DDRC_DIMMCTL_dimm_stagger_cs_en_SHIFT    (0U)
/*! dimm_stagger_cs_en - Staggering enable for multi-rank accesses (for multi-rank UDIMM, RDIMM and
 *    LRDIMM implementations only). This is not supported for mDDR, LPDDR2, LPDDR3 or LPDDR4 SDRAMs.
 *    Even if this bit is set it does not take care of software driven MR commands (via
 *    MRCTRL0/MRCTRL1), where software is responsible to send them to separate ranks as appropriate.
 *  0b0..Do not stagger accesses
 *  0b1..For(non-DDR4) Send all commands to even and odd ranks separately; For(DDR4) Send MRS commands to each ranks separately
 */
#define DDRC_DIMMCTL_dimm_stagger_cs_en(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DIMMCTL_dimm_stagger_cs_en_SHIFT)) & DDRC_DIMMCTL_dimm_stagger_cs_en_MASK)

#define DDRC_DIMMCTL_dimm_addr_mirr_en_MASK      (0x2U)
#define DDRC_DIMMCTL_dimm_addr_mirr_en_SHIFT     (1U)
/*! dimm_addr_mirr_en - Address Mirroring Enable (for multi-rank UDIMM implementations and
 *    multi-rank DDR4 RDIMM/LRDIMM implementations). Some UDIMMs and DDR4 RDIMMs/LRDIMMs implement address
 *    mirroring for odd ranks, which means that the following address, bank address and bank group
 *    bits are swapped: (A3, A4), (A5, A6), (A7, A8), (BA0, BA1) and also (A11, A13), (BG0, BG1) for
 *    the DDR4. Setting this bit ensures that, for mode register accesses during the automatic
 *    initialization routine, these bits are swapped within the DDRC to compensate for this
 *    UDIMM/RDIMM/LRDIMM swapping. In addition to the automatic initialization routine, in case of DDR4
 *    UDIMM/RDIMM/LRDIMM, they are swapped during the automatic MRS access to enable/disable of a particular
 *    DDR4 feature. Note: This has no effect on the address of any other memory accesses, or of
 *    software-driven mode register accesses. This is not supported for mDDR, LPDDR2, LPDDR3 or LPDDR4
 *    SDRAMs. Note: In case of x16 DDR4 DIMMs, BG1 output of MRS for the odd ranks is same as BG0
 *    because BG1 is invalid, hence dimm_dis_bg_mirroring register must be set to 1.
 *  0b0..Do not implement address mirroring
 *  0b1..For odd ranks, implement address mirroring for MRS commands to during initialization and for any
 *       automatic DDR4 MRS commands (to be used if UDIMM/RDIMM/LRDIMM implements address mirroring)
 */
#define DDRC_DIMMCTL_dimm_addr_mirr_en(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DIMMCTL_dimm_addr_mirr_en_SHIFT)) & DDRC_DIMMCTL_dimm_addr_mirr_en_MASK)

#define DDRC_DIMMCTL_dimm_output_inv_en_MASK     (0x4U)
#define DDRC_DIMMCTL_dimm_output_inv_en_SHIFT    (2U)
/*! dimm_output_inv_en - Output Inversion Enable (for DDR4 RDIMM/LRDIMM implementations only). DDR4
 *    RDIMM/LRDIMM implements the Output Inversion feature by default, which means that the
 *    following address, bank address and bank group bits of B-side DRAMs are inverted: A3-A9, A11, A13,
 *    A17, BA0-BA1, BG0-BG1. Setting this bit ensures that, for mode register accesses generated by the
 *    DDRC during the automatic initialization routine and enabling of a particular DDR4 feature,
 *    separate A-side and B-side mode register accesses are generated. For B-side mode register
 *    accesses, these bits are inverted within the DDRC to compensate for this RDIMM/LRDIMM inversion. It
 *    is recommended to set this bit always, if using DDR4 RDIMMs/LRDIMMs. Note: This has no effect
 *    on the address of any other memory accesses, or of software-driven mode register accesses.
 *  0b0..Do not implement output inversion for B-side DRAMs.
 *  0b1..Implement output inversion for B-side DRAMs.
 */
#define DDRC_DIMMCTL_dimm_output_inv_en(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DIMMCTL_dimm_output_inv_en_SHIFT)) & DDRC_DIMMCTL_dimm_output_inv_en_MASK)

#define DDRC_DIMMCTL_mrs_a17_en_MASK             (0x8U)
#define DDRC_DIMMCTL_mrs_a17_en_SHIFT            (3U)
/*! mrs_a17_en - Enable for A17 bit of MRS command. A17 bit of the mode register address is
 *    specified as RFU (Reserved for Future Use) and must be programmed to 0 during MRS. In case where DRAMs
 *    which do not have A17 are attached and the Output Inversion are enabled, this must be set to
 *    0, so that the calculation of CA parity will not include A17 bit. Note: This has no effect on
 *    the address of any other memory accesses, or of software-driven mode register accesses.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DDRC_DIMMCTL_mrs_a17_en(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DIMMCTL_mrs_a17_en_SHIFT)) & DDRC_DIMMCTL_mrs_a17_en_MASK)

#define DDRC_DIMMCTL_mrs_bg1_en_MASK             (0x10U)
#define DDRC_DIMMCTL_mrs_bg1_en_SHIFT            (4U)
/*! mrs_bg1_en - Enable for BG1 bit of MRS command. BG1 bit of the mode register address is
 *    specified as RFU (Reserved for Future Use) and must be programmed to 0 during MRS. In case where DRAMs
 *    which do not have BG1 are attached and both the CA parity and the Output Inversion are
 *    enabled, this must be set to 0, so that the calculation of CA parity will not include BG1 bit. Note:
 *    This has no effect on the address of any other memory accesses, or of software-driven mode
 *    register accesses. If address mirroring is enabled, this is applied to BG1 of even ranks and BG0
 *    of odd ranks.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DDRC_DIMMCTL_mrs_bg1_en(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DIMMCTL_mrs_bg1_en_SHIFT)) & DDRC_DIMMCTL_mrs_bg1_en_MASK)

#define DDRC_DIMMCTL_dimm_dis_bg_mirroring_MASK  (0x20U)
#define DDRC_DIMMCTL_dimm_dis_bg_mirroring_SHIFT (5U)
/*! dimm_dis_bg_mirroring - Disabling Address Mirroring for BG bits. When this is set to 1, BG0 and
 *    BG1 are NOT swapped even if Address Mirroring is enabled. This will be required for DDR4 DIMMs
 *    with x16 devices.
 *  0b0..BG0 and BG1 are swapped if address mirroring is enabled.
 *  0b1..BG0 and BG1 are NOT swapped.
 */
#define DDRC_DIMMCTL_dimm_dis_bg_mirroring(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_DIMMCTL_dimm_dis_bg_mirroring_SHIFT)) & DDRC_DIMMCTL_dimm_dis_bg_mirroring_MASK)

#define DDRC_DIMMCTL_lrdimm_bcom_cmd_prot_MASK   (0x40U)
#define DDRC_DIMMCTL_lrdimm_bcom_cmd_prot_SHIFT  (6U)
/*! lrdimm_bcom_cmd_prot - Protects the timing restrictions (tBCW/tMRC) between consecutive BCOM
 *    commands defined in the Data Buffer specification. When using DDR4 LRDIMM, this bit must be set
 *    to 1. Otherwise, this bit must be set to 0.
 */
#define DDRC_DIMMCTL_lrdimm_bcom_cmd_prot(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DIMMCTL_lrdimm_bcom_cmd_prot_SHIFT)) & DDRC_DIMMCTL_lrdimm_bcom_cmd_prot_MASK)
/*! @} */

/*! @name RANKCTL - Rank Control Register */
/*! @{ */

#define DDRC_RANKCTL_max_rank_rd_MASK            (0xFU)
#define DDRC_RANKCTL_max_rank_rd_SHIFT           (0U)
/*! max_rank_rd - Only present for multi-rank configurations. Background: Reads to the same rank can
 *    be performed back-to-back. Reads to different ranks require additional gap dictated by the
 *    register RANKCTL.diff_rank_rd_gap. This is to avoid possible data bus contention as well as to
 *    give PHY enough time to switch the delay when changing ranks. The DDRC arbitrates for bus
 *    access on a cycle-by-cycle basis; therefore after a read is scheduled, there are few clock cycles
 *    (determined by the value on RANKCTL.diff_rank_rd_gap register) in which only reads from the
 *    same rank are eligible to be scheduled. This prevents reads from other ranks from having fair
 *    access to the data bus. This parameter represents the maximum number of reads that can be
 *    scheduled consecutively to the same rank. After this number is reached, a delay equal to
 *    RANKCTL.diff_rank_rd_gap is inserted by the scheduler to allow all ranks a fair opportunity to be
 *    scheduled. Higher numbers increase bandwidth utilization, lower numbers increase fairness. This
 *    feature can be DISABLED by setting this register to 0. When set to 0, the Controller will stay on
 *    the same rank as long as commands are available for it. Minimum programmable value is 0 (feature
 *    disabled) and maximum programmable value is 0xF. FOR PERFORMANCE ONLY.
 */
#define DDRC_RANKCTL_max_rank_rd(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_RANKCTL_max_rank_rd_SHIFT)) & DDRC_RANKCTL_max_rank_rd_MASK)

#define DDRC_RANKCTL_diff_rank_rd_gap_MASK       (0xF0U)
#define DDRC_RANKCTL_diff_rank_rd_gap_SHIFT      (4U)
/*! diff_rank_rd_gap - Only present for multi-rank configurations. Indicates the number of clocks of
 *    gap in data responses when performing consecutive reads to different ranks. This is used to
 *    switch the delays in the PHY to match the rank requirements. This value should consider both
 *    PHY requirement and ODT requirement. - PHY requirement: tphy_rdcsgap + 1 (see PHY databook for
 *    value of tphy_rdcsgap) If read preamble is set to 2tCK(DDR4/LPDDR4 only), should be increased
 *    by 1. If read postamble is set to 1.5tCK(LPDDR4 only), should be increased by 1. - ODT
 *    requirement: The value programmed in this register takes care of the ODT switch off timing requirement
 *    when switching ranks during reads. When the controller is operating in 1:1 mode, program this
 *    to the larger of PHY requirement or ODT requirement. When the controller is operating in 1:2
 *    mode, program this to the larger value divided by two and round it up to the next integer.
 *    Note that, if using DDR4-LRDIMM, refer to TRDRD timing requirements in JEDEC DDR4 Data Buffer
 *    (DDR4DB01) Specification.
 */
#define DDRC_RANKCTL_diff_rank_rd_gap(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_RANKCTL_diff_rank_rd_gap_SHIFT)) & DDRC_RANKCTL_diff_rank_rd_gap_MASK)

#define DDRC_RANKCTL_diff_rank_wr_gap_MASK       (0xF00U)
#define DDRC_RANKCTL_diff_rank_wr_gap_SHIFT      (8U)
/*! diff_rank_wr_gap - Only present for multi-rank configurations. Indicates the number of clocks of
 *    gap in data responses when performing consecutive writes to different ranks. This is used to
 *    switch the delays in the PHY to match the rank requirements. This value should consider both
 *    PHY requirement and ODT requirement. - PHY requirement: tphy_wrcsgap + 1 (see PHY databook for
 *    value of tphy_wrcsgap) If CRC feature is enabled, should be increased by 1. If write preamble
 *    is set to 2tCK(DDR4/LPDDR4 only), should be increased by 1. If write postamble is set to
 *    1.5tCK(LPDDR4 only), should be increased by 1. - ODT requirement: The value programmed in this
 *    register takes care of the ODT switch off timing requirement when switching ranks during writes.
 *    For LPDDR4, the requirement is ODTLoff - ODTLon - BL/2 + 1 When the controller is operating in
 *    1:1 mode, program this to the larger of PHY requirement or ODT requirement. When the
 *    controller is operating in 1:2 mode, program this to the larger value divided by two and round it up to
 *    the next integer. Note that, if using DDR4-LRDIMM, refer to TWRWR timing requirements in
 *    JEDEC DDR4 Data Buffer (DDR4DB01) Specification.
 */
#define DDRC_RANKCTL_diff_rank_wr_gap(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_RANKCTL_diff_rank_wr_gap_SHIFT)) & DDRC_RANKCTL_diff_rank_wr_gap_MASK)
/*! @} */

/*! @name DRAMTMG0 - SDRAM Timing Register 0 */
/*! @{ */

#define DDRC_DRAMTMG0_t_ras_min_MASK             (0x3FU)
#define DDRC_DRAMTMG0_t_ras_min_SHIFT            (0U)
/*! t_ras_min - tRAS(min): Minimum time between activate and precharge to the same bank. When the
 *    controller is operating in 1:2 frequency mode, 1T mode, program this to tRAS(min)/2. No rounding
 *    up. When the controller is operating in 1:2 frequency ratio mode, 2T mode or LPDDR4 mode,
 *    program this to (tRAS(min)/2) and round it up to the next integer value. Unit: Clocks
 */
#define DDRC_DRAMTMG0_t_ras_min(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG0_t_ras_min_SHIFT)) & DDRC_DRAMTMG0_t_ras_min_MASK)

#define DDRC_DRAMTMG0_t_ras_max_MASK             (0x7F00U)
#define DDRC_DRAMTMG0_t_ras_max_SHIFT            (8U)
/*! t_ras_max - tRAS(max): Maximum time between activate and precharge to same bank. This is the
 *    maximum time that a page can be kept open Minimum value of this register is 1. Zero is invalid.
 *    When the controller is operating in 1:2 frequency ratio mode, program this to (tRAS(max)-1)/2.
 *    No rounding up. Unit: Multiples of 1024 clocks.
 */
#define DDRC_DRAMTMG0_t_ras_max(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG0_t_ras_max_SHIFT)) & DDRC_DRAMTMG0_t_ras_max_MASK)

#define DDRC_DRAMTMG0_t_faw_MASK                 (0x3F0000U)
#define DDRC_DRAMTMG0_t_faw_SHIFT                (16U)
/*! t_faw - tFAW Valid only when 8 or more banks(or banks x bank groups) are present. In 8-bank
 *    design, at most 4 banks must be activated in a rolling window of tFAW cycles. When the controller
 *    is operating in 1:2 frequency ratio mode, program this to (tFAW/2) and round up to next
 *    integer value. In a 4-bank design, set this register to 0x1 independent of the 1:1/1:2 frequency
 *    mode. Unit: Clocks
 */
#define DDRC_DRAMTMG0_t_faw(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG0_t_faw_SHIFT)) & DDRC_DRAMTMG0_t_faw_MASK)

#define DDRC_DRAMTMG0_wr2pre_MASK                (0x7F000000U)
#define DDRC_DRAMTMG0_wr2pre_SHIFT               (24U)
/*! wr2pre - Minimum time between write and precharge to same bank. Unit: Clocks Specifications: WL
 *    + BL/2 + tWR = approximately 8 cycles + 15 ns = 14 clocks @400MHz and less for lower
 *    frequencies where: - WL = write latency - BL = burst length. This must match the value programmed in
 *    the BL bit of the mode register to the SDRAM. BST (burst terminate) is not supported at present.
 *    - tWR = Write recovery time. This comes directly from the SDRAM specification. Add one extra
 *    cycle for LPDDR2/LPDDR3/LPDDR4 for this parameter. When the controller is operating in 1:2
 *    frequency ratio mode, 1T mode, divide the above value by 2. No rounding up. When the controller
 *    is operating in 1:2 frequency ratio mode, 2T mode or LPDDR4 mode, divide the above value by 2
 *    and round it up to the next integer value. Note that, depending on the PHY, if using LRDIMM, it
 *    may be necessary to adjust the value of this parameter to compensate for the extra cycle of
 *    latency through the LRDIMM.
 */
#define DDRC_DRAMTMG0_wr2pre(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG0_wr2pre_SHIFT)) & DDRC_DRAMTMG0_wr2pre_MASK)
/*! @} */

/*! @name DRAMTMG1 - SDRAM Timing Register 1 */
/*! @{ */

#define DDRC_DRAMTMG1_t_rc_MASK                  (0x7FU)
#define DDRC_DRAMTMG1_t_rc_SHIFT                 (0U)
/*! t_rc - tRC: Minimum time between activates to same bank. When the controller is operating in 1:2
 *    frequency ratio mode, program this to (tRC/2) and round up to next integer value. Unit:
 *    Clocks.
 */
#define DDRC_DRAMTMG1_t_rc(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG1_t_rc_SHIFT)) & DDRC_DRAMTMG1_t_rc_MASK)

#define DDRC_DRAMTMG1_rd2pre_MASK                (0x3F00U)
#define DDRC_DRAMTMG1_rd2pre_SHIFT               (8U)
/*! rd2pre - tRTP: Minimum time from read to precharge of same bank. - DDR2: tAL + BL/2 + max(tRTP,
 *    2) - 2 - DDR3: tAL + max (tRTP, 4) - DDR4: Max of following two equations: tAL + max (tRTP, 4)
 *    or, RL + BL/2 - tRP (*). - mDDR: BL/2 - LPDDR2: Depends on if it's LPDDR2-S2 or LPDDR2-S4:
 *    LPDDR2-S2: BL/2 + tRTP - 1. LPDDR2-S4: BL/2 + max(tRTP,2) - 2. - LPDDR3: BL/2 + max(tRTP,4) - 4
 *    - LPDDR4: BL/2 + max(tRTP,8) - 8 (*) When both DDR4 SDRAM and ST-MRAM are used simultaneously,
 *    use SDRAM's tRP value for calculation. When the controller is operating in 1:2 mode, 1T mode,
 *    divide the above value by 2. No rounding up. When the controller is operating in 1:2 mode, 2T
 *    mode or LPDDR4 mode, divide the above value by 2 and round it up to the next integer value.
 *    Unit: Clocks.
 */
#define DDRC_DRAMTMG1_rd2pre(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG1_rd2pre_SHIFT)) & DDRC_DRAMTMG1_rd2pre_MASK)

#define DDRC_DRAMTMG1_t_xp_MASK                  (0x1F0000U)
#define DDRC_DRAMTMG1_t_xp_SHIFT                 (16U)
/*! t_xp - tXP: Minimum time after power-down exit to any operation. For DDR3, this should be
 *    programmed to tXPDLL if slow powerdown exit is selected in MR0[12]. If C/A parity for DDR4 is used,
 *    set to (tXP+PL) instead. When the controller is operating in 1:2 frequency ratio mode, program
 *    this to (tXP/2) and round it up to the next integer value. Units: Clocks
 */
#define DDRC_DRAMTMG1_t_xp(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG1_t_xp_SHIFT)) & DDRC_DRAMTMG1_t_xp_MASK)
/*! @} */

/*! @name DRAMTMG2 - SDRAM Timing Register 2 */
/*! @{ */

#define DDRC_DRAMTMG2_wr2rd_MASK                 (0x3FU)
#define DDRC_DRAMTMG2_wr2rd_SHIFT                (0U)
/*! wr2rd - DDR4: CWL + PL + BL/2 + tWTR_L Others: CWL + BL/2 + tWTR In DDR4, minimum time from
 *    write command to read command for same bank group. In others, minimum time from write command to
 *    read command. Includes time for bus turnaround, recovery times, and all per-bank, per-rank, and
 *    global constraints. Unit: Clocks. Where: - CWL = CAS write latency - PL = Parity latency - BL
 *    = burst length. This must match the value programmed in the BL bit of the mode register to
 *    the SDRAM - tWTR_L = internal write to read command delay for same bank group. This comes
 *    directly from the SDRAM specification. - tWTR = internal write to read command delay. This comes
 *    directly from the SDRAM specification. Add one extra cycle for LPDDR2/LPDDR3/LPDDR4 operation.
 *    When the controller is operating in 1:2 mode, divide the value calculated using the above
 *    equation by 2, and round it up to next integer.
 */
#define DDRC_DRAMTMG2_wr2rd(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG2_wr2rd_SHIFT)) & DDRC_DRAMTMG2_wr2rd_MASK)

#define DDRC_DRAMTMG2_rd2wr_MASK                 (0x3F00U)
#define DDRC_DRAMTMG2_rd2wr_SHIFT                (8U)
/*! rd2wr - DDR2/3/mDDR: RL + BL/2 + 2 - WL DDR4: RL + BL/2 + 1 + WR_PREAMBLE - WL LPDDR2/LPDDR3: RL
 *    + BL/2 + RU(tDQSCKmax/tCK) + 1 - WL LPDDR4(DQ ODT is Disabled): RL + BL/2 + RU(tDQSCKmax/tCK)
 *    + WR_PREAMBLE + RD_POSTAMBLE - WL LPDDR4(DQ ODT is Enabled) : RL + BL/2 + RU(tDQSCKmax/tCK) +
 *    RD_POSTAMBLE - ODTLon - RU(tODTon(min)/tCK) Minimum time from read command to write command.
 *    Include time for bus turnaround and all per-bank, per-rank, and global constraints. Please see
 *    the relevant PHY databook for details of what should be included here. Unit: Clocks. Where: -
 *    WL = write latency - BL = burst length. This must match the value programmed in the BL bit of
 *    the mode register to the SDRAM - RL = read latency = CAS latency - WR_PREAMBLE = write
 *    preamble. This is unique to DDR4 and LPDDR4. - RD_POSTAMBLE = read postamble. This is unique to
 *    LPDDR4. For LPDDR2/LPDDR3/LPDDR4, if derating is enabled (DERATEEN.derate_enable=1), derated
 *    tDQSCKmax should be used. When the controller is operating in 1:2 frequency ratio mode, divide the
 *    value calculated using the above equation by 2, and round it up to next integer. Note that,
 *    depending on the PHY, if using LRDIMM, it may be necessary to adjust the value of this parameter
 *    to compensate for the extra cycle of latency through the LRDIMM.
 */
#define DDRC_DRAMTMG2_rd2wr(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG2_rd2wr_SHIFT)) & DDRC_DRAMTMG2_rd2wr_MASK)

#define DDRC_DRAMTMG2_read_latency_MASK          (0x3F0000U)
#define DDRC_DRAMTMG2_read_latency_SHIFT         (16U)
/*! read_latency - Set to RL Time from read command to read data on SDRAM interface. This must be
 *    set to RL. Note that, depending on the PHY, if using RDIMM/LRDIMM, it may be necessary to adjust
 *    the value of RL to compensate for the extra cycle of latency through the RDIMM/LRDIMM. When
 *    the controller is operating in 1:2 frequency ratio mode, divide the value calculated using the
 *    above equation by 2, and round it up to next integer. This register field is not required for
 *    DDR2 and DDR3 (except if MEMC_TRAINING is set), as the DFI read and write latencies defined in
 *    DFITMG0 and DFITMG1 are sufficient for those protocols Unit: clocks
 */
#define DDRC_DRAMTMG2_read_latency(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG2_read_latency_SHIFT)) & DDRC_DRAMTMG2_read_latency_MASK)

#define DDRC_DRAMTMG2_write_latency_MASK         (0x3F000000U)
#define DDRC_DRAMTMG2_write_latency_SHIFT        (24U)
/*! write_latency - Set to WL Time from write command to write data on SDRAM interface. This must be
 *    set to WL. For mDDR, it should normally be set to 1. Note that, depending on the PHY, if
 *    using RDIMM/LRDIMM, it may be necessary to adjust the value of WL to compensate for the extra
 *    cycle of latency through the RDIMM/LRDIMM. When the controller is operating in 1:2 frequency ratio
 *    mode, divide the value calculated using the above equation by 2, and round it up to next
 *    integer. This register field is not required for DDR2 and DDR3 (except if MEMC_TRAINING is set),
 *    as the DFI read and write latencies defined in DFITMG0 and DFITMG1 are sufficient for those
 *    protocols Unit: clocks
 */
#define DDRC_DRAMTMG2_write_latency(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG2_write_latency_SHIFT)) & DDRC_DRAMTMG2_write_latency_MASK)
/*! @} */

/*! @name DRAMTMG3 - SDRAM Timing Register 3 */
/*! @{ */

#define DDRC_DRAMTMG3_t_mod_MASK                 (0x3FFU)
#define DDRC_DRAMTMG3_t_mod_SHIFT                (0U)
/*! t_mod - tMOD: Parameter used only in DDR3 and DDR4. Cycles between load mode command and
 *    following non-load mode command. If C/A parity for DDR4 is used, set to tMOD_PAR(tMOD+PL) instead.
 *    Set to tMOD if controller is operating in 1:1 frequency ratio mode, or tMOD/2 (rounded up to
 *    next integer) if controller is operating in 1:2 frequency ratio mode. Note that if using
 *    RDIMM/LRDIMM, depending on the PHY, it may be necessary to adjust the value of this parameter to
 *    compensate for the extra cycle of latency applied to mode register writes by the RDIMM/LRDIMM chip.
 *    Also note that if using LRDIMM, the minimum value of this register is tMRD_L2 if controller
 *    is operating in 1:1 frequency ratio mode, or tMRD_L2/2 (rounded up to next integer) if
 *    controller is operating in 1:2 frequency ratio mode.
 */
#define DDRC_DRAMTMG3_t_mod(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG3_t_mod_SHIFT)) & DDRC_DRAMTMG3_t_mod_MASK)

#define DDRC_DRAMTMG3_t_mrd_MASK                 (0x3F000U)
#define DDRC_DRAMTMG3_t_mrd_SHIFT                (12U)
/*! t_mrd - tMRD: Cycles to wait after a mode register write or read. Depending on the connected
 *    SDRAM, tMRD represents: DDR2/mDDR: Time from MRS to any command DDR3/4: Time from MRS to MRS
 *    command LPDDR2: not used LPDDR3/4: Time from MRS to non-MRS command. When the controller is
 *    operating in 1:2 frequency ratio mode, program this to (tMRD/2) and round it up to the next integer
 *    value. If C/A parity for DDR4 is used, set to tMRD_PAR(tMOD+PL) instead.
 */
#define DDRC_DRAMTMG3_t_mrd(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG3_t_mrd_SHIFT)) & DDRC_DRAMTMG3_t_mrd_MASK)

#define DDRC_DRAMTMG3_t_mrw_MASK                 (0x3FF00000U)
#define DDRC_DRAMTMG3_t_mrw_SHIFT                (20U)
/*! t_mrw - Time to wait after a mode register write or read (MRW or MRR). Present only in designs
 *    configured to support LPDDR2, LPDDR3 or LPDDR4. LPDDR2 typically requires value of 5. LPDDR3
 *    typically requires value of 10. LPDDR4: Set this to the larger of tMRW and tMRWCKEL. For LPDDR2,
 *    this register is used for the time from a MRW/MRR to all other commands. When the controller
 *    is operating in 1:2 frequency ratio mode, program this to the above values divided by 2 and
 *    round it up to the next integer value. For LDPDR3, this register is used for the time from a
 *    MRW/MRR to a MRW/MRR.
 */
#define DDRC_DRAMTMG3_t_mrw(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG3_t_mrw_SHIFT)) & DDRC_DRAMTMG3_t_mrw_MASK)
/*! @} */

/*! @name DRAMTMG4 - SDRAM Timing Register 4 */
/*! @{ */

#define DDRC_DRAMTMG4_t_rp_MASK                  (0x1FU)
#define DDRC_DRAMTMG4_t_rp_SHIFT                 (0U)
/*! t_rp - tRP: Minimum time from precharge to activate of same bank. When the controller is
 *    operating in 1:1 frequency ratio mode, t_rp should be set to RoundUp(tRP/tCK). When the controller is
 *    operating in 1:2 frequency ratio mode, t_rp should be set to RoundDown(RoundUp(tRP/tCK)/2) +
 *    1. When the controller is operating in 1:2 frequency ratio mode in LPDDR4, t_rp should be set
 *    to RoundUp(RoundUp(tRP/tCK)/2). Unit: Clocks.
 */
#define DDRC_DRAMTMG4_t_rp(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG4_t_rp_SHIFT)) & DDRC_DRAMTMG4_t_rp_MASK)

#define DDRC_DRAMTMG4_t_rrd_MASK                 (0xF00U)
#define DDRC_DRAMTMG4_t_rrd_SHIFT                (8U)
/*! t_rrd - DDR4: tRRD_L: Minimum time between activates from bank "a" to bank "b" for same bank
 *    group. Others: tRRD: Minimum time between activates from bank "a" to bank "b" When the controller
 *    is operating in 1:2 frequency ratio mode, program this to (tRRD_L/2 or tRRD/2) and round it
 *    up to the next integer value. Unit: Clocks.
 */
#define DDRC_DRAMTMG4_t_rrd(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG4_t_rrd_SHIFT)) & DDRC_DRAMTMG4_t_rrd_MASK)

#define DDRC_DRAMTMG4_t_ccd_MASK                 (0xF0000U)
#define DDRC_DRAMTMG4_t_ccd_SHIFT                (16U)
/*! t_ccd - DDR4: tCCD_L: This is the minimum time between two reads or two writes for same bank
 *    group. Others: tCCD: This is the minimum time between two reads or two writes. When the
 *    controller is operating in 1:2 frequency ratio mode, program this to (tCCD_L/2 or tCCD/2) and round it
 *    up to the next integer value. Unit: clocks.
 */
#define DDRC_DRAMTMG4_t_ccd(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG4_t_ccd_SHIFT)) & DDRC_DRAMTMG4_t_ccd_MASK)

#define DDRC_DRAMTMG4_t_rcd_MASK                 (0x1F000000U)
#define DDRC_DRAMTMG4_t_rcd_SHIFT                (24U)
/*! t_rcd - tRCD - tAL: Minimum time from activate to read or write command to same bank. When the
 *    controller is operating in 1:2 frequency ratio mode, program this to ((tRCD - tAL)/2) and round
 *    it up to the next integer value. Minimum value allowed for this register is 1, which implies
 *    minimum (tRCD - tAL) value to be 2 when the controller is operating in 1:2 frequency ratio
 *    mode. Unit: Clocks.
 */
#define DDRC_DRAMTMG4_t_rcd(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG4_t_rcd_SHIFT)) & DDRC_DRAMTMG4_t_rcd_MASK)
/*! @} */

/*! @name DRAMTMG5 - SDRAM Timing Register 5 */
/*! @{ */

#define DDRC_DRAMTMG5_t_cke_MASK                 (0x1FU)
#define DDRC_DRAMTMG5_t_cke_SHIFT                (0U)
/*! t_cke - Minimum number of cycles of CKE HIGH/LOW during power-down and self refresh. -
 *    LPDDR2/LPDDR3 mode: Set this to the larger of tCKE or tCKESR - LPDDR4 mode: Set this to the larger of
 *    tCKE, tCKELPD or tSR. - Non-LPDDR2/non-LPDDR3/non-LPDDR4 designs: Set this to tCKE value. When
 *    the controller is operating in 1:2 frequency ratio mode, program this to (value described
 *    above)/2 and round it up to the next integer value. Unit: Clocks.
 */
#define DDRC_DRAMTMG5_t_cke(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG5_t_cke_SHIFT)) & DDRC_DRAMTMG5_t_cke_MASK)

#define DDRC_DRAMTMG5_t_ckesr_MASK               (0x3F00U)
#define DDRC_DRAMTMG5_t_ckesr_SHIFT              (8U)
/*! t_ckesr - Minimum CKE low width for Self refresh or Self refresh power down entry to exit timing
 *    in memory clock cycles. Recommended settings: - mDDR: tRFC - LPDDR2: tCKESR - LPDDR3: tCKESR
 *    - LPDDR4: max(tCKELPD, tSR) - DDR2: tCKE - DDR3: tCKE + 1 - DDR4: tCKE + 1 (+ PL(parity
 *    latency)(*)) (*)Only if CRCPARCTL1.caparity_disable_before_sr=0, this register should be increased
 *    by PL. When the controller is operating in 1:2 frequency ratio mode, program this to
 *    recommended value divided by two and round it up to next integer.
 */
#define DDRC_DRAMTMG5_t_ckesr(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG5_t_ckesr_SHIFT)) & DDRC_DRAMTMG5_t_ckesr_MASK)

#define DDRC_DRAMTMG5_t_cksre_MASK               (0xF0000U)
#define DDRC_DRAMTMG5_t_cksre_SHIFT              (16U)
/*! t_cksre - This is the time after Self Refresh Down Entry that CK is maintained as a valid clock.
 *    Specifies the clock disable delay after SRE. Recommended settings: - mDDR: 0 - LPDDR2: 2 -
 *    LPDDR3: 2 - LPDDR4: tCKCKEL - DDR2: 1 - DDR3: max (10 ns, 5 tCK) - DDR4: max (10 ns, 5 tCK) (+
 *    PL(parity latency)(*)) (*)Only if CRCPARCTL1.caparity_disable_before_sr=0, this register should
 *    be increased by PL. When the controller is operating in 1:2 frequency ratio mode, program
 *    this to recommended value divided by two and round it up to next integer.
 */
#define DDRC_DRAMTMG5_t_cksre(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG5_t_cksre_SHIFT)) & DDRC_DRAMTMG5_t_cksre_MASK)

#define DDRC_DRAMTMG5_t_cksrx_MASK               (0xF000000U)
#define DDRC_DRAMTMG5_t_cksrx_SHIFT              (24U)
/*! t_cksrx - This is the time before Self Refresh Exit that CK is maintained as a valid clock
 *    before issuing SRX. Specifies the clock stable time before SRX. Recommended settings: - mDDR: 1 -
 *    LPDDR2: 2 - LPDDR3: 2 - LPDDR4: tCKCKEH - DDR2: 1 - DDR3: tCKSRX - DDR4: tCKSRX When the
 *    controller is operating in 1:2 frequency ratio mode, program this to recommended value divided by
 *    two and round it up to next integer.
 */
#define DDRC_DRAMTMG5_t_cksrx(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG5_t_cksrx_SHIFT)) & DDRC_DRAMTMG5_t_cksrx_MASK)
/*! @} */

/*! @name DRAMTMG6 - SDRAM Timing Register 6 */
/*! @{ */

#define DDRC_DRAMTMG6_t_ckcsx_MASK               (0xFU)
#define DDRC_DRAMTMG6_t_ckcsx_SHIFT              (0U)
/*! t_ckcsx - This is the time before Clock Stop Exit that CK is maintained as a valid clock before
 *    issuing Clock Stop Exit. Specifies the clock stable time before next command after Clock Stop
 *    Exit. Recommended settings: - mDDR: 1 - LPDDR2: tXP + 2 - LPDDR3: tXP + 2 - LPDDR4: tXP + 2
 *    When the controller is operating in 1:2 frequency ratio mode, program this to recommended value
 *    divided by two and round it up to next integer. This is only present for designs supporting
 *    mDDR or LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_DRAMTMG6_t_ckcsx(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG6_t_ckcsx_SHIFT)) & DDRC_DRAMTMG6_t_ckcsx_MASK)

#define DDRC_DRAMTMG6_t_ckdpdx_MASK              (0xF0000U)
#define DDRC_DRAMTMG6_t_ckdpdx_SHIFT             (16U)
/*! t_ckdpdx - This is the time before Deep Power Down Exit that CK is maintained as a valid clock
 *    before issuing DPDX. Specifies the clock stable time before DPDX. Recommended settings: - mDDR:
 *    1 - LPDDR2: 2 - LPDDR3: 2 When the controller is operating in 1:2 frequency ratio mode,
 *    program this to recommended value divided by two and round it up to next integer. This is only
 *    present for designs supporting mDDR or LPDDR2 devices.
 */
#define DDRC_DRAMTMG6_t_ckdpdx(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG6_t_ckdpdx_SHIFT)) & DDRC_DRAMTMG6_t_ckdpdx_MASK)

#define DDRC_DRAMTMG6_t_ckdpde_MASK              (0xF000000U)
#define DDRC_DRAMTMG6_t_ckdpde_SHIFT             (24U)
/*! t_ckdpde - This is the time after Deep Power Down Entry that CK is maintained as a valid clock.
 *    Specifies the clock disable delay after DPDE. Recommended settings: - mDDR: 0 - LPDDR2: 2 -
 *    LPDDR3: 2 When the controller is operating in 1:2 frequency ratio mode, program this to
 *    recommended value divided by two and round it up to next integer. This is only present for designs
 *    supporting mDDR or LPDDR2/LPDDR3 devices.
 */
#define DDRC_DRAMTMG6_t_ckdpde(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG6_t_ckdpde_SHIFT)) & DDRC_DRAMTMG6_t_ckdpde_MASK)
/*! @} */

/*! @name DRAMTMG7 - SDRAM Timing Register 7 */
/*! @{ */

#define DDRC_DRAMTMG7_t_ckpdx_MASK               (0xFU)
#define DDRC_DRAMTMG7_t_ckpdx_SHIFT              (0U)
/*! t_ckpdx - This is the time before Power Down Exit that CK is maintained as a valid clock before
 *    issuing PDX. Specifies the clock stable time before PDX. Recommended settings: - mDDR: 0 -
 *    LPDDR2: 2 - LPDDR3: 2 - LPDDR4: 2 When using DDR2/3/4 SDRAM, this register should be set to the
 *    same value as DRAMTMG5.t_cksrx. When the controller is operating in 1:2 frequency ratio mode,
 *    program this to recommended value divided by two and round it up to next integer. This is only
 *    present for designs supporting mDDR or LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_DRAMTMG7_t_ckpdx(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG7_t_ckpdx_SHIFT)) & DDRC_DRAMTMG7_t_ckpdx_MASK)

#define DDRC_DRAMTMG7_t_ckpde_MASK               (0xF00U)
#define DDRC_DRAMTMG7_t_ckpde_SHIFT              (8U)
/*! t_ckpde - This is the time after Power Down Entry that CK is maintained as a valid clock.
 *    Specifies the clock disable delay after PDE. Recommended settings: - mDDR: 0 - LPDDR2: 2 - LPDDR3: 2
 *    - LPDDR4: tCKCKEL When using DDR2/3/4 SDRAM, this register should be set to the same value as
 *    DRAMTMG5.t_cksre. When the controller is operating in 1:2 frequency ratio mode, program this
 *    to recommended value divided by two and round it up to next integer. This is only present for
 *    designs supporting mDDR or LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_DRAMTMG7_t_ckpde(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG7_t_ckpde_SHIFT)) & DDRC_DRAMTMG7_t_ckpde_MASK)
/*! @} */

/*! @name DRAMTMG8 - SDRAM Timing Register 8 */
/*! @{ */

#define DDRC_DRAMTMG8_t_xs_x32_MASK              (0x7FU)
#define DDRC_DRAMTMG8_t_xs_x32_SHIFT             (0U)
/*! t_xs_x32 - tXS: Exit Self Refresh to commands not requiring a locked DLL. When the controller is
 *    operating in 1:2 frequency ratio mode, program this to the above value divided by 2 and round
 *    up to next integer value. Unit: Multiples of 32 clocks. Note: Used only for DDR2, DDR3 and
 *    DDR4 SDRAMs.
 */
#define DDRC_DRAMTMG8_t_xs_x32(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG8_t_xs_x32_SHIFT)) & DDRC_DRAMTMG8_t_xs_x32_MASK)

#define DDRC_DRAMTMG8_t_xs_dll_x32_MASK          (0x7F00U)
#define DDRC_DRAMTMG8_t_xs_dll_x32_SHIFT         (8U)
/*! t_xs_dll_x32 - tXSDLL: Exit Self Refresh to commands requiring a locked DLL. When the controller
 *    is operating in 1:2 frequency ratio mode, program this to the above value divided by 2 and
 *    round up to next integer value. Unit: Multiples of 32 clocks. Note: Used only for DDR2, DDR3 and
 *    DDR4 SDRAMs.
 */
#define DDRC_DRAMTMG8_t_xs_dll_x32(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG8_t_xs_dll_x32_SHIFT)) & DDRC_DRAMTMG8_t_xs_dll_x32_MASK)

#define DDRC_DRAMTMG8_t_xs_abort_x32_MASK        (0x7F0000U)
#define DDRC_DRAMTMG8_t_xs_abort_x32_SHIFT       (16U)
/*! t_xs_abort_x32 - tXS_ABORT: Exit Self Refresh to commands not requiring a locked DLL in Self
 *    Refresh Abort. When the controller is operating in 1:2 frequency ratio mode, program this to the
 *    above value divided by 2 and round up to next integer value. Unit: Multiples of 32 clocks.
 *    Note: Ensure this is less than or equal to t_xs_x32.
 */
#define DDRC_DRAMTMG8_t_xs_abort_x32(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG8_t_xs_abort_x32_SHIFT)) & DDRC_DRAMTMG8_t_xs_abort_x32_MASK)

#define DDRC_DRAMTMG8_t_xs_fast_x32_MASK         (0x7F000000U)
#define DDRC_DRAMTMG8_t_xs_fast_x32_SHIFT        (24U)
/*! t_xs_fast_x32 - tXS_FAST: Exit Self Refresh to ZQCL, ZQCS and MRS (only CL, WR, RTP and Geardown
 *    mode). When the controller is operating in 1:2 frequency ratio mode, program this to the
 *    above value divided by 2 and round up to next integer value. Unit: Multiples of 32 clocks. Note:
 *    This is applicable to only ZQCL/ZQCS commands. Note: Ensure this is less than or equal to
 *    t_xs_x32.
 */
#define DDRC_DRAMTMG8_t_xs_fast_x32(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG8_t_xs_fast_x32_SHIFT)) & DDRC_DRAMTMG8_t_xs_fast_x32_MASK)
/*! @} */

/*! @name DRAMTMG9 - SDRAM Timing Register 9 */
/*! @{ */

#define DDRC_DRAMTMG9_wr2rd_s_MASK               (0x3FU)
#define DDRC_DRAMTMG9_wr2rd_s_SHIFT              (0U)
/*! wr2rd_s - CWL + PL + BL/2 + tWTR_S Minimum time from write command to read command for different
 *    bank group. Includes time for bus turnaround, recovery times, and all per-bank, per-rank, and
 *    global constraints. Present only in designs configured to support DDR4. Unit: Clocks. Where:
 *    - CWL = CAS write latency - PL = Parity latency - BL = burst length. This must match the value
 *    programmed in the BL bit of the mode register to the SDRAM - tWTR_S = internal write to read
 *    command delay for different bank group. This comes directly from the SDRAM specification. When
 *    the controller is operating in 1:2 mode, divide the value calculated using the above equation
 *    by 2, and round it up to next integer.
 */
#define DDRC_DRAMTMG9_wr2rd_s(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG9_wr2rd_s_SHIFT)) & DDRC_DRAMTMG9_wr2rd_s_MASK)

#define DDRC_DRAMTMG9_t_rrd_s_MASK               (0xF00U)
#define DDRC_DRAMTMG9_t_rrd_s_SHIFT              (8U)
/*! t_rrd_s - tRRD_S: Minimum time between activates from bank "a" to bank "b" for different bank
 *    group. When the controller is operating in 1:2 frequency ratio mode, program this to (tRRD_S/2)
 *    and round it up to the next integer value. Present only in designs configured to support DDR4.
 *    Unit: Clocks.
 */
#define DDRC_DRAMTMG9_t_rrd_s(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG9_t_rrd_s_SHIFT)) & DDRC_DRAMTMG9_t_rrd_s_MASK)

#define DDRC_DRAMTMG9_t_ccd_s_MASK               (0x70000U)
#define DDRC_DRAMTMG9_t_ccd_s_SHIFT              (16U)
/*! t_ccd_s - tCCD_S: This is the minimum time between two reads or two writes for different bank
 *    group. For bank switching (from bank "a" to bank "b"), the minimum time is this value + 1. When
 *    the controller is operating in 1:2 frequency ratio mode, program this to (tCCD_S/2) and round
 *    it up to the next integer value. Present only in designs configured to support DDR4. Unit:
 *    clocks.
 */
#define DDRC_DRAMTMG9_t_ccd_s(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG9_t_ccd_s_SHIFT)) & DDRC_DRAMTMG9_t_ccd_s_MASK)

#define DDRC_DRAMTMG9_ddr4_wr_preamble_MASK      (0x40000000U)
#define DDRC_DRAMTMG9_ddr4_wr_preamble_SHIFT     (30U)
/*! ddr4_wr_preamble - DDR4 Write preamble mode - 0: 1tCK preamble - 1: 2tCK preamble Present only with MEMC_FREQ_RATIO=2 */
#define DDRC_DRAMTMG9_ddr4_wr_preamble(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG9_ddr4_wr_preamble_SHIFT)) & DDRC_DRAMTMG9_ddr4_wr_preamble_MASK)
/*! @} */

/*! @name DRAMTMG10 - SDRAM Timing Register 10 */
/*! @{ */

#define DDRC_DRAMTMG10_t_gear_hold_MASK          (0x3U)
#define DDRC_DRAMTMG10_t_gear_hold_SHIFT         (0U)
/*! t_gear_hold - Geardown hold time. Minimum value of this register is 1. Zero is invalid. For
 *    DDR4-2666 and DDR4-3200, this parameter is defined as 2 clks When the controller is operating in
 *    1:2 frequency ratio mode, program this to (tGEAR_hold/2) and round it up to the next integer
 *    value. Unit: Clocks
 */
#define DDRC_DRAMTMG10_t_gear_hold(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG10_t_gear_hold_SHIFT)) & DDRC_DRAMTMG10_t_gear_hold_MASK)

#define DDRC_DRAMTMG10_t_gear_setup_MASK         (0xCU)
#define DDRC_DRAMTMG10_t_gear_setup_SHIFT        (2U)
/*! t_gear_setup - Geardown setup time. Minimum value of this register is 1. Zero is invalid. For
 *    DDR4-2666 and DDR4-3200, this parameter is defined as 2 clks When the controller is operating in
 *    1:2 frequency ratio mode, program this to (tGEAR_setup/2) and round it up to the next integer
 *    value. Unit: Clocks
 */
#define DDRC_DRAMTMG10_t_gear_setup(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG10_t_gear_setup_SHIFT)) & DDRC_DRAMTMG10_t_gear_setup_MASK)

#define DDRC_DRAMTMG10_t_cmd_gear_MASK           (0x1F00U)
#define DDRC_DRAMTMG10_t_cmd_gear_SHIFT          (8U)
/*! t_cmd_gear - Sync pulse to first valid command. For DDR4-2666 and DDR4-3200, this parameter is
 *    defined as tMOD(min) tMOD(min) is greater of 24nCK or 15ns 15ns / .625ns = 24 Max value for
 *    this register is 24 When the controller is operating in 1:2 mode, program this to (tCMD_GEAR/2)
 *    and round it up to the next integer value. Unit: Clocks
 */
#define DDRC_DRAMTMG10_t_cmd_gear(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG10_t_cmd_gear_SHIFT)) & DDRC_DRAMTMG10_t_cmd_gear_MASK)

#define DDRC_DRAMTMG10_t_sync_gear_MASK          (0x1F0000U)
#define DDRC_DRAMTMG10_t_sync_gear_SHIFT         (16U)
/*! t_sync_gear - Indicates the time between MRS command and the sync pulse time. This must be even
 *    number of clocks. For DDR4-2666 and DDR4-3200, this parameter is defined as tMOD(min)+4nCK
 *    tMOD(min) is greater of 24nCK or 15ns 15ns / .625ns = 24 Max value for this register is 24+4 = 28
 *    When the controller is operating in 1:2 mode, program this to (tSYNC_GEAR/2) and round it up
 *    to the next integer value. Unit: Clocks
 */
#define DDRC_DRAMTMG10_t_sync_gear(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG10_t_sync_gear_SHIFT)) & DDRC_DRAMTMG10_t_sync_gear_MASK)
/*! @} */

/*! @name DRAMTMG11 - SDRAM Timing Register 11 */
/*! @{ */

#define DDRC_DRAMTMG11_t_ckmpe_MASK              (0x1FU)
#define DDRC_DRAMTMG11_t_ckmpe_SHIFT             (0U)
/*! t_ckmpe - tCKMPE: Minimum valid clock requirement after MPSM entry. Present only in designs
 *    configured to support DDR4. Unit: Clocks. When the controller is operating in 1:2 frequency ratio
 *    mode, divide the value calculated using the above equation by 2, and round it up to next
 *    integer.
 */
#define DDRC_DRAMTMG11_t_ckmpe(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG11_t_ckmpe_SHIFT)) & DDRC_DRAMTMG11_t_ckmpe_MASK)

#define DDRC_DRAMTMG11_t_mpx_s_MASK              (0x300U)
#define DDRC_DRAMTMG11_t_mpx_s_SHIFT             (8U)
/*! t_mpx_s - tMPX_S: Minimum time CS setup time to CKE. When the controller is operating in 1:2
 *    frequency ratio mode, program this to (tMPX_S/2) and round it up to the next integer value.
 *    Present only in designs configured to support DDR4. Unit: Clocks.
 */
#define DDRC_DRAMTMG11_t_mpx_s(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG11_t_mpx_s_SHIFT)) & DDRC_DRAMTMG11_t_mpx_s_MASK)

#define DDRC_DRAMTMG11_t_mpx_lh_MASK             (0x1F0000U)
#define DDRC_DRAMTMG11_t_mpx_lh_SHIFT            (16U)
/*! t_mpx_lh - tMPX_LH: This is the minimum CS_n Low hold time to CKE rising edge. When the
 *    controller is operating in 1:2 frequency ratio mode, program this to RoundUp(tMPX_LH/2)+1. Present
 *    only in designs configured to support DDR4. Unit: clocks.
 */
#define DDRC_DRAMTMG11_t_mpx_lh(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG11_t_mpx_lh_SHIFT)) & DDRC_DRAMTMG11_t_mpx_lh_MASK)

#define DDRC_DRAMTMG11_post_mpsm_gap_x32_MASK    (0x7F000000U)
#define DDRC_DRAMTMG11_post_mpsm_gap_x32_SHIFT   (24U)
/*! post_mpsm_gap_x32 - tXMPDLL: This is the minimum Exit MPSM to commands requiring a locked DLL.
 *    When the controller is operating in 1:2 frequency ratio mode, program this to (tXMPDLL/2) and
 *    round it up to the next integer value. Present only in designs configured to support DDR4.
 *    Unit: Multiples of 32 clocks.
 */
#define DDRC_DRAMTMG11_post_mpsm_gap_x32(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG11_post_mpsm_gap_x32_SHIFT)) & DDRC_DRAMTMG11_post_mpsm_gap_x32_MASK)
/*! @} */

/*! @name DRAMTMG12 - SDRAM Timing Register 12 */
/*! @{ */

#define DDRC_DRAMTMG12_t_mrd_pda_MASK            (0x1FU)
#define DDRC_DRAMTMG12_t_mrd_pda_SHIFT           (0U)
/*! t_mrd_pda - tMRD_PDA: This is the Mode Register Set command cycle time in PDA mode. When the
 *    controller is operating in 1:2 frequency ratio mode, program this to (tMRD_PDA/2) and round it up
 *    to the next integer value.
 */
#define DDRC_DRAMTMG12_t_mrd_pda(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG12_t_mrd_pda_SHIFT)) & DDRC_DRAMTMG12_t_mrd_pda_MASK)

#define DDRC_DRAMTMG12_t_ckehcmd_MASK            (0xF00U)
#define DDRC_DRAMTMG12_t_ckehcmd_SHIFT           (8U)
/*! t_ckehcmd - tCKEHCMD: Valid command requirement after CKE input HIGH. When the controller is
 *    operating in 1:2 frequency ratio mode, program this to (tCKEHCMD/2) and round it up to the next
 *    integer value.
 */
#define DDRC_DRAMTMG12_t_ckehcmd(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG12_t_ckehcmd_SHIFT)) & DDRC_DRAMTMG12_t_ckehcmd_MASK)

#define DDRC_DRAMTMG12_t_cmdcke_MASK             (0x30000U)
#define DDRC_DRAMTMG12_t_cmdcke_SHIFT            (16U)
/*! t_cmdcke - tCMDCKE: Delay from valid command to CKE input LOW. Set this to the larger of tESCKE
 *    or tCMDCKE When the controller is operating in 1:2 frequency ratio mode, program this to
 *    (max(tESCKE, tCMDCKE)/2) and round it up to the next integer value.
 */
#define DDRC_DRAMTMG12_t_cmdcke(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG12_t_cmdcke_SHIFT)) & DDRC_DRAMTMG12_t_cmdcke_MASK)
/*! @} */

/*! @name DRAMTMG13 - SDRAM Timing Register 13 */
/*! @{ */

#define DDRC_DRAMTMG13_t_ppd_MASK                (0x7U)
#define DDRC_DRAMTMG13_t_ppd_SHIFT               (0U)
/*! t_ppd - LPDDR4: tPPD: This is the minimum time from precharge to precharge command. When the
 *    controller is operating in 1:2 frequency ratio mode, program this to (tPPD/2) and round it up to
 *    the next integer value. Unit: Clocks.
 */
#define DDRC_DRAMTMG13_t_ppd(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG13_t_ppd_SHIFT)) & DDRC_DRAMTMG13_t_ppd_MASK)

#define DDRC_DRAMTMG13_t_ccd_mw_MASK             (0x3F0000U)
#define DDRC_DRAMTMG13_t_ccd_mw_SHIFT            (16U)
/*! t_ccd_mw - LPDDR4: tCCDMW: This is the minimum time from write or masked write to masked write
 *    command for same bank. When the controller is operating in 1:2 frequency ratio mode, program
 *    this to (tCCDMW/2) and round it up to the next integer value. Unit: Clocks.
 */
#define DDRC_DRAMTMG13_t_ccd_mw(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG13_t_ccd_mw_SHIFT)) & DDRC_DRAMTMG13_t_ccd_mw_MASK)

#define DDRC_DRAMTMG13_odtloff_MASK              (0x7F000000U)
#define DDRC_DRAMTMG13_odtloff_SHIFT             (24U)
/*! odtloff - LPDDR4: tODTLoff: This is the latency from CAS-2 command to tODToff reference. When
 *    the controller is operating in 1:2 frequency ratio mode, program this to (tODTLoff/2) and round
 *    it up to the next integer value. Unit: Clocks.
 */
#define DDRC_DRAMTMG13_odtloff(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG13_odtloff_SHIFT)) & DDRC_DRAMTMG13_odtloff_MASK)
/*! @} */

/*! @name DRAMTMG14 - SDRAM Timing Register 14 */
/*! @{ */

#define DDRC_DRAMTMG14_t_xsr_MASK                (0xFFFU)
#define DDRC_DRAMTMG14_t_xsr_SHIFT               (0U)
/*! t_xsr - tXSR: Exit Self Refresh to any command. When the controller is operating in 1:2
 *    frequency ratio mode, program this to the above value divided by 2 and round up to next integer value.
 *    Note: Used only for mDDR/LPDDR2/LPDDR3/LPDDR4 mode.
 */
#define DDRC_DRAMTMG14_t_xsr(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG14_t_xsr_SHIFT)) & DDRC_DRAMTMG14_t_xsr_MASK)
/*! @} */

/*! @name DRAMTMG15 - SDRAM Timing Register 15 */
/*! @{ */

#define DDRC_DRAMTMG15_t_stab_x32_MASK           (0xFFU)
#define DDRC_DRAMTMG15_t_stab_x32_SHIFT          (0U)
/*! t_stab_x32 - tSTAB: Stabilization time. It is required in the following two cases for DDR3/DDR4
 *    RDIMM : - when exiting power saving mode, if the clock was stopped, after re-enabling it the
 *    clock must be stable for a time specified by tSTAB - in the case of input clock frequency
 *    change (DDR4) - after issuing control words that refers to clock timing (Specification: 6us for
 *    DDR3, 5us for DDR4) When the controller is operating in 1:2 frequency ratio mode, program this to
 *    recommended value divided by two and round it up to next integer. Unit: Multiples of 32 clock
 *    cycles.
 */
#define DDRC_DRAMTMG15_t_stab_x32(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG15_t_stab_x32_SHIFT)) & DDRC_DRAMTMG15_t_stab_x32_MASK)

#define DDRC_DRAMTMG15_en_dfi_lp_t_stab_MASK     (0x80000000U)
#define DDRC_DRAMTMG15_en_dfi_lp_t_stab_SHIFT    (31U)
/*! en_dfi_lp_t_stab - Enable DFI tSTAB
 *  0b0..Disable using tSTAB when exiting DFI LP
 *  0b1..Enable using tSTAB when exiting DFI LP. Needs to be set when the PHY is stopping the clock during DFI LP to save maximum power.
 */
#define DDRC_DRAMTMG15_en_dfi_lp_t_stab(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG15_en_dfi_lp_t_stab_SHIFT)) & DDRC_DRAMTMG15_en_dfi_lp_t_stab_MASK)
/*! @} */

/*! @name ZQCTL0 - ZQ Control Register 0 */
/*! @{ */

#define DDRC_ZQCTL0_t_zq_short_nop_MASK          (0x3FFU)
#define DDRC_ZQCTL0_t_zq_short_nop_SHIFT         (0U)
/*! t_zq_short_nop - tZQCS for DDR3/DD4/LPDDR2/LPDDR3, tZQLAT for LPDDR4: Number of DFI clock cycles
 *    of NOP required after a ZQCS (ZQ calibration short)/MPC(ZQ Latch) command is issued to SDRAM.
 *    When the controller is operating in 1:2 frequency ratio mode, program this to tZQCS/2 and
 *    round it up to the next integer value. This is only present for designs supporting DDR3/DDR4 or
 *    LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_ZQCTL0_t_zq_short_nop(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL0_t_zq_short_nop_SHIFT)) & DDRC_ZQCTL0_t_zq_short_nop_MASK)

#define DDRC_ZQCTL0_t_zq_long_nop_MASK           (0x7FF0000U)
#define DDRC_ZQCTL0_t_zq_long_nop_SHIFT          (16U)
/*! t_zq_long_nop - tZQoper for DDR3/DDR4, tZQCL for LPDDR2/LPDDR3, tZQCAL for LPDDR4: Number of DFI
 *    clock cycles of NOP required after a ZQCL (ZQ calibration long)/MPC(ZQ Start) command is
 *    issued to SDRAM. When the controller is operating in 1:2 frequency ratio mode: DDR3/DDR4: program
 *    this to tZQoper/2 and round it up to the next integer value. LPDDR2/LPDDR3: program this to
 *    tZQCL/2 and round it up to the next integer value. LPDDR4: program this to tZQCAL/2 and round it
 *    up to the next integer value. This is only present for designs supporting DDR3/DDR4 or
 *    LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_ZQCTL0_t_zq_long_nop(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL0_t_zq_long_nop_SHIFT)) & DDRC_ZQCTL0_t_zq_long_nop_MASK)

#define DDRC_ZQCTL0_dis_mpsmx_zqcl_MASK          (0x10000000U)
#define DDRC_ZQCTL0_dis_mpsmx_zqcl_SHIFT         (28U)
/*! dis_mpsmx_zqcl - Do not issue ZQCL command at Maximum Power Save Mode exit if the DDRC_SHARED_AC
 *    configuration parameter is set. Program it to 1'b1. The software can send ZQCS after exiting
 *    MPSM mode.
 *  0b0..Enable issuing of ZQCL command at Maximum Power Saving Mode exit. Only applicable when run in DDR4 mode.
 *       This is only present for designs supporting DDR4 devices.
 *  0b1..Disable issuing of ZQCL command at Maximum Power Saving Mode exit. Only applicable when run in DDR4 mode.
 */
#define DDRC_ZQCTL0_dis_mpsmx_zqcl(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL0_dis_mpsmx_zqcl_SHIFT)) & DDRC_ZQCTL0_dis_mpsmx_zqcl_MASK)

#define DDRC_ZQCTL0_zq_resistor_shared_MASK      (0x20000000U)
#define DDRC_ZQCTL0_zq_resistor_shared_SHIFT     (29U)
/*! zq_resistor_shared - ZQ resistor sharing
 *  0b0..ZQ resistor is not shared. This is only present for designs supporting DDR3/DDR4 or LPDDR2/LPDDR3/LPDDR4 devices.
 *  0b1..Denotes that ZQ resistor is shared between ranks. Means ZQinit/ZQCL/ZQCS/MPC(ZQ calibration) commands are
 *       sent to one rank at a time with tZQinit/tZQCL/tZQCS/tZQCAL/tZQLAT timing met between commands so that
 *       commands to different ranks do not overlap.
 */
#define DDRC_ZQCTL0_zq_resistor_shared(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL0_zq_resistor_shared_SHIFT)) & DDRC_ZQCTL0_zq_resistor_shared_MASK)

#define DDRC_ZQCTL0_dis_srx_zqcl_MASK            (0x40000000U)
#define DDRC_ZQCTL0_dis_srx_zqcl_SHIFT           (30U)
/*! dis_srx_zqcl - Disable ZQCL/MPC
 *  0b0..Enable issuing of ZQCL/MPC(ZQ calibration) command at Self-Refresh/SR-Powerdown exit. Only applicable
 *       when run in DDR3 or DDR4 or LPDDR2 or LPDDR3 or LPDDR4 mode. This is only present for designs supporting
 *       DDR3/DDR4 or LPDDR2/LPDDR3/LPDDR4 devices.
 *  0b1..Disable issuing of ZQCL/MPC(ZQ calibration) command at Self-Refresh/SR-Powerdown exit. Only applicable
 *       when run in DDR3 or DDR4 or LPDDR2 or LPDDR3 or LPDDR4 mode.
 */
#define DDRC_ZQCTL0_dis_srx_zqcl(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL0_dis_srx_zqcl_SHIFT)) & DDRC_ZQCTL0_dis_srx_zqcl_MASK)

#define DDRC_ZQCTL0_dis_auto_zq_MASK             (0x80000000U)
#define DDRC_ZQCTL0_dis_auto_zq_SHIFT            (31U)
/*! dis_auto_zq - Disable Auto ZQCS/MPC
 *  0b0..Internally generate ZQCS/MPC(ZQ calibration) commands based on ZQCTL1.t_zq_short_interval_x1024.
 *  0b1..Disable DDRC generation of ZQCS/MPC(ZQ calibration) command. Register DBGCMD.zq_calib_short can be used
 *       instead to issue ZQ calibration request from APB module.
 */
#define DDRC_ZQCTL0_dis_auto_zq(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL0_dis_auto_zq_SHIFT)) & DDRC_ZQCTL0_dis_auto_zq_MASK)
/*! @} */

/*! @name ZQCTL1 - ZQ Control Register 1 */
/*! @{ */

#define DDRC_ZQCTL1_t_zq_short_interval_x1024_MASK (0xFFFFFU)
#define DDRC_ZQCTL1_t_zq_short_interval_x1024_SHIFT (0U)
/*! t_zq_short_interval_x1024 - Average interval to wait between automatically issuing ZQCS (ZQ
 *    calibration short)/MPC(ZQ calibration) commands to DDR3/DDR4/LPDDR2/LPDDR3/LPDDR4 devices.
 *    Meaningless, if ZQCTL0.dis_auto_zq=1. Unit: 1024 DFI clock cycles. This is only present for designs
 *    supporting DDR3/DDR4 or LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_ZQCTL1_t_zq_short_interval_x1024(x) (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL1_t_zq_short_interval_x1024_SHIFT)) & DDRC_ZQCTL1_t_zq_short_interval_x1024_MASK)

#define DDRC_ZQCTL1_t_zq_reset_nop_MASK          (0x3FF00000U)
#define DDRC_ZQCTL1_t_zq_reset_nop_SHIFT         (20U)
/*! t_zq_reset_nop - tZQReset: Number of DFI clock cycles of NOP required after a ZQReset (ZQ
 *    calibration Reset) command is issued to SDRAM. When the controller is operating in 1:2 frequency
 *    ratio mode, program this to tZQReset/2 and round it up to the next integer value. This is only
 *    present for designs supporting LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_ZQCTL1_t_zq_reset_nop(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL1_t_zq_reset_nop_SHIFT)) & DDRC_ZQCTL1_t_zq_reset_nop_MASK)
/*! @} */

/*! @name ZQCTL2 - ZQ Control Register 2 */
/*! @{ */

#define DDRC_ZQCTL2_zq_reset_MASK                (0x1U)
#define DDRC_ZQCTL2_zq_reset_SHIFT               (0U)
/*! zq_reset - Setting this register bit to 1 triggers a ZQ Reset operation. When the ZQ Reset
 *    operation is complete, the DDRC automatically clears this bit. It is recommended NOT to set this
 *    signal if in Init, Self-Refresh(except LPDDR4) or SR-Powerdown(LPDDR4) or Deep power-down
 *    operating modes. This is only present for designs supporting LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_ZQCTL2_zq_reset(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL2_zq_reset_SHIFT)) & DDRC_ZQCTL2_zq_reset_MASK)
/*! @} */

/*! @name ZQSTAT - ZQ Status Register */
/*! @{ */

#define DDRC_ZQSTAT_zq_reset_busy_MASK           (0x1U)
#define DDRC_ZQSTAT_zq_reset_busy_SHIFT          (0U)
/*! zq_reset_busy - SoC core may initiate a ZQ Reset operation only if this signal is low. This
 *    signal goes high in the clock after the DDRC accepts the ZQ Reset request. It goes low when the ZQ
 *    Reset command is issued to the SDRAM and the associated NOP period is over. It is recommended
 *    not to perform ZQ Reset commands when this signal is high.
 *  0b0..Indicates that the SoC core can initiate a ZQ Reset operation
 *  0b1..Indicates that ZQ Reset operation is in progress
 */
#define DDRC_ZQSTAT_zq_reset_busy(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_ZQSTAT_zq_reset_busy_SHIFT)) & DDRC_ZQSTAT_zq_reset_busy_MASK)
/*! @} */

/*! @name DFITMG0 - DFI Timing Register 0 */
/*! @{ */

#define DDRC_DFITMG0_dfi_tphy_wrlat_MASK         (0x3FU)
#define DDRC_DFITMG0_dfi_tphy_wrlat_SHIFT        (0U)
/*! dfi_tphy_wrlat - Write latency Number of clocks from the write command to write data enable
 *    (dfi_wrdata_en). This corresponds to the DFI timing parameter tphy_wrlat. Refer to PHY
 *    specification for correct value.Note that, depending on the PHY, if using RDIMM/LRDIMM, it may be
 *    necessary to use the adjusted value of CL in the calculation of tphy_wrlat. This is to compensate for
 *    the extra cycle(s) of latency through the RDIMM/LRDIMM. Unit: DFI clock cycles or DFI PHY
 *    clock cycles, depending on DFITMG0.dfi_wrdata_use_sdr.
 */
#define DDRC_DFITMG0_dfi_tphy_wrlat(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG0_dfi_tphy_wrlat_SHIFT)) & DDRC_DFITMG0_dfi_tphy_wrlat_MASK)

#define DDRC_DFITMG0_dfi_tphy_wrdata_MASK        (0x3F00U)
#define DDRC_DFITMG0_dfi_tphy_wrdata_SHIFT       (8U)
/*! dfi_tphy_wrdata - Specifies the number of clock cycles between when dfi_wrdata_en is asserted to
 *    when the associated write data is driven on the dfi_wrdata signal. This corresponds to the
 *    DFI timing parameter tphy_wrdata. Refer to PHY specification for correct value. Note, max
 *    supported value is 8. Unit: DFI clock cycles or DFI PHY clock cycles, depending on
 *    DFITMG0.dfi_wrdata_use_sdr.
 */
#define DDRC_DFITMG0_dfi_tphy_wrdata(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG0_dfi_tphy_wrdata_SHIFT)) & DDRC_DFITMG0_dfi_tphy_wrdata_MASK)

#define DDRC_DFITMG0_dfi_wrdata_use_sdr_MASK     (0x8000U)
#define DDRC_DFITMG0_dfi_wrdata_use_sdr_SHIFT    (15U)
/*! dfi_wrdata_use_sdr - Defines whether dfi_wrdata_en/dfi_wrdata/dfi_wrdata_mask is generated using
 *    HDR (DFI clock) or SDR (DFI PHY clock) values Selects whether value in DFITMG0.dfi_tphy_wrlat
 *    is in terms of HDR (DFI clock) or SDR (DFI PHY clock) cycles Selects whether value in
 *    DFITMG0.dfi_tphy_wrdata is in terms of HDR (DFI clock) or SDR (DFI PHY clock) cycles - 0 in terms of
 *    HDR (DFI clock) cycles - 1 in terms of SDR (DFI PHY clock) cycles Refer to PHY specification
 *    for correct value.
 */
#define DDRC_DFITMG0_dfi_wrdata_use_sdr(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG0_dfi_wrdata_use_sdr_SHIFT)) & DDRC_DFITMG0_dfi_wrdata_use_sdr_MASK)

#define DDRC_DFITMG0_dfi_t_rddata_en_MASK        (0x7F0000U)
#define DDRC_DFITMG0_dfi_t_rddata_en_SHIFT       (16U)
/*! dfi_t_rddata_en - Time from the assertion of a read command on the DFI interface to the
 *    assertion of the dfi_rddata_en signal. Refer to PHY specification for correct value. This corresponds
 *    to the DFI parameter trddata_en. Note that, depending on the PHY, if using RDIMM/LRDIMM, it
 *    may be necessary to use the adjusted value of CL in the calculation of trddata_en. This is to
 *    compensate for the extra cycle(s) of latency through the RDIMM/LRDIMM. Unit: DFI clock cycles or
 *    DFI PHY clock cycles, depending on DFITMG0.dfi_rddata_use_sdr.
 */
#define DDRC_DFITMG0_dfi_t_rddata_en(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG0_dfi_t_rddata_en_SHIFT)) & DDRC_DFITMG0_dfi_t_rddata_en_MASK)

#define DDRC_DFITMG0_dfi_rddata_use_sdr_MASK     (0x800000U)
#define DDRC_DFITMG0_dfi_rddata_use_sdr_SHIFT    (23U)
/*! dfi_rddata_use_sdr - Defines whether dfi_rddata_en/dfi_rddata/dfi_rddata_valid is generated
 *    using HDR (DFI clock) or SDR (DFI PHY clock) values. Selects whether value in
 *    DFITMG0.dfi_t_rddata_en is in terms of HDR (DFI clock) or SDR (DFI PHY clock) cycles: - 0 in terms of HDR (DFI
 *    clock) cycles - 1 in terms of SDR (DFI PHY clock) cycles Refer to PHY specification for correct
 *    value.
 */
#define DDRC_DFITMG0_dfi_rddata_use_sdr(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG0_dfi_rddata_use_sdr_SHIFT)) & DDRC_DFITMG0_dfi_rddata_use_sdr_MASK)

#define DDRC_DFITMG0_dfi_t_ctrl_delay_MASK       (0x1F000000U)
#define DDRC_DFITMG0_dfi_t_ctrl_delay_SHIFT      (24U)
/*! dfi_t_ctrl_delay - Specifies the number of DFI clock cycles after an assertion or de-assertion
 *    of the DFI control signals that the control signals at the PHY-DRAM interface reflect the
 *    assertion or de-assertion. If the DFI clock and the memory clock are not phase-aligned, this timing
 *    parameter should be rounded up to the next integer value. Note that if using RDIMM/LRDIMM, it
 *    is necessary to increment this parameter by RDIMM's/LRDIMM's extra cycle of latency in terms
 *    of DFI clock.
 */
#define DDRC_DFITMG0_dfi_t_ctrl_delay(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG0_dfi_t_ctrl_delay_SHIFT)) & DDRC_DFITMG0_dfi_t_ctrl_delay_MASK)
/*! @} */

/*! @name DFITMG1 - DFI Timing Register 1 */
/*! @{ */

#define DDRC_DFITMG1_dfi_t_dram_clk_enable_MASK  (0x1FU)
#define DDRC_DFITMG1_dfi_t_dram_clk_enable_SHIFT (0U)
/*! dfi_t_dram_clk_enable - Specifies the number of DFI clock cycles from the de-assertion of the
 *    dfi_dram_clk_disable signal on the DFI until the first valid rising edge of the clock to the
 *    DRAM memory devices, at the PHY-DRAM boundary. If the DFI clock and the memory clock are not
 *    phase aligned, this timing parameter should be rounded up to the next integer value.
 */
#define DDRC_DFITMG1_dfi_t_dram_clk_enable(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG1_dfi_t_dram_clk_enable_SHIFT)) & DDRC_DFITMG1_dfi_t_dram_clk_enable_MASK)

#define DDRC_DFITMG1_dfi_t_dram_clk_disable_MASK (0x1F00U)
#define DDRC_DFITMG1_dfi_t_dram_clk_disable_SHIFT (8U)
/*! dfi_t_dram_clk_disable - Specifies the number of DFI clock cycles from the assertion of the
 *    dfi_dram_clk_disable signal on the DFI until the clock to the DRAM memory devices, at the PHY-DRAM
 *    boundary, maintains a low value. If the DFI clock and the memory clock are not phase aligned,
 *    this timing parameter should be rounded up to the next integer value.
 */
#define DDRC_DFITMG1_dfi_t_dram_clk_disable(x)   (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG1_dfi_t_dram_clk_disable_SHIFT)) & DDRC_DFITMG1_dfi_t_dram_clk_disable_MASK)

#define DDRC_DFITMG1_dfi_t_wrdata_delay_MASK     (0x1F0000U)
#define DDRC_DFITMG1_dfi_t_wrdata_delay_SHIFT    (16U)
/*! dfi_t_wrdata_delay - Specifies the number of DFI clock cycles between when the dfi_wrdata_en
 *    signal is asserted and when the corresponding write data transfer is completed on the DRAM bus.
 *    This corresponds to the DFI timing parameter twrdata_delay. Refer to PHY specification for
 *    correct value. For DFI 3.0 PHY, set to twrdata_delay, a new timing parameter introduced in DFI
 *    3.0. For DFI 2.1 PHY, set to tphy_wrdata + (delay of DFI write data to the DRAM). Value to be
 *    programmed is in terms of DFI clocks, not PHY clocks. In FREQ_RATIO=2, divide PHY's value by 2
 *    and round up to next integer. If using DFITMG0.dfi_wrdata_use_sdr=1, add 1 to the value. Unit:
 *    Clocks
 */
#define DDRC_DFITMG1_dfi_t_wrdata_delay(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG1_dfi_t_wrdata_delay_SHIFT)) & DDRC_DFITMG1_dfi_t_wrdata_delay_MASK)

#define DDRC_DFITMG1_dfi_t_parin_lat_MASK        (0x3000000U)
#define DDRC_DFITMG1_dfi_t_parin_lat_SHIFT       (24U)
/*! dfi_t_parin_lat - Specifies the number of DFI PHY clock cycles between when the dfi_cs signal is
 *    asserted and when the associated dfi_parity_in signal is driven.
 */
#define DDRC_DFITMG1_dfi_t_parin_lat(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG1_dfi_t_parin_lat_SHIFT)) & DDRC_DFITMG1_dfi_t_parin_lat_MASK)

#define DDRC_DFITMG1_dfi_t_cmd_lat_MASK          (0xF0000000U)
#define DDRC_DFITMG1_dfi_t_cmd_lat_SHIFT         (28U)
/*! dfi_t_cmd_lat - Specifies the number of DFI PHY clock cycles between when the dfi_cs signal is
 *    asserted and when the associated command is driven. This field is used for CAL mode, should be
 *    set to '0' or the value which matches the CAL mode register setting in the DRAM. If the PHY
 *    can add the latency for CAL mode, this should be set to '0'. Valid Range: 0, 3, 4, 5, 6, and 8
 */
#define DDRC_DFITMG1_dfi_t_cmd_lat(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG1_dfi_t_cmd_lat_SHIFT)) & DDRC_DFITMG1_dfi_t_cmd_lat_MASK)
/*! @} */

/*! @name DFILPCFG0 - DFI Low Power Configuration Register 0 */
/*! @{ */

#define DDRC_DFILPCFG0_dfi_lp_en_pd_MASK         (0x1U)
#define DDRC_DFILPCFG0_dfi_lp_en_pd_SHIFT        (0U)
/*! dfi_lp_en_pd - Enables DFI Low Power interface handshaking during Power Down Entry/Exit. - 0 - Disabled - 1 - Enabled */
#define DDRC_DFILPCFG0_dfi_lp_en_pd(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DFILPCFG0_dfi_lp_en_pd_SHIFT)) & DDRC_DFILPCFG0_dfi_lp_en_pd_MASK)

#define DDRC_DFILPCFG0_dfi_lp_wakeup_pd_MASK     (0xF0U)
#define DDRC_DFILPCFG0_dfi_lp_wakeup_pd_SHIFT    (4U)
/*! dfi_lp_wakeup_pd - Value in DFI clock cycles to drive on dfi_lp_wakeup signal when Power Down
 *    mode is entered. Determines the DFI's tlp_wakeup time:
 *  0b0000..16 cycles
 *  0b0001..32 cycles
 *  0b0010..64 cycles
 *  0b0011..128 cycles
 *  0b0100..256 cycles
 *  0b0101..512 cycles
 *  0b0110..1024 cycles
 *  0b0111..2048 cycles
 *  0b1000..4096 cycles
 *  0b1001..8192 cycles
 *  0b1010..16384 cycles
 *  0b1011..32768 cycles
 *  0b1100..65536 cycles
 *  0b1101..131072 cycles
 *  0b1110..262144 cycles
 *  0b1111..Unlimited cycles
 */
#define DDRC_DFILPCFG0_dfi_lp_wakeup_pd(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DFILPCFG0_dfi_lp_wakeup_pd_SHIFT)) & DDRC_DFILPCFG0_dfi_lp_wakeup_pd_MASK)

#define DDRC_DFILPCFG0_dfi_lp_en_sr_MASK         (0x100U)
#define DDRC_DFILPCFG0_dfi_lp_en_sr_SHIFT        (8U)
/*! dfi_lp_en_sr - Enables DFI Low Power interface handshaking during Self Refresh Entry/Exit. - 0 - Disabled - 1 - Enabled
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DDRC_DFILPCFG0_dfi_lp_en_sr(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DFILPCFG0_dfi_lp_en_sr_SHIFT)) & DDRC_DFILPCFG0_dfi_lp_en_sr_MASK)

#define DDRC_DFILPCFG0_dfi_lp_wakeup_sr_MASK     (0xF000U)
#define DDRC_DFILPCFG0_dfi_lp_wakeup_sr_SHIFT    (12U)
/*! dfi_lp_wakeup_sr - Value in DFI clpck cycles to drive on dfi_lp_wakeup signal when Self Refresh
 *    mode is entered. Determines the DFI's tlp_wakeup time:
 *  0b0000..16 cycles
 *  0b0001..32 cycles
 *  0b0010..64 cycles
 *  0b0011..128 cycles
 *  0b0100..256 cycles
 *  0b0101..512 cycles
 *  0b0110..1024 cycles
 *  0b0111..2048 cycles
 *  0b1000..4096 cycles
 *  0b1001..8192 cycles
 *  0b1010..16384 cycles
 *  0b1011..32768 cycles
 *  0b1100..65536 cycles
 *  0b1101..131072 cycles
 *  0b1110..262144 cycles
 *  0b1111..Unlimited cycles
 */
#define DDRC_DFILPCFG0_dfi_lp_wakeup_sr(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DFILPCFG0_dfi_lp_wakeup_sr_SHIFT)) & DDRC_DFILPCFG0_dfi_lp_wakeup_sr_MASK)

#define DDRC_DFILPCFG0_dfi_lp_en_dpd_MASK        (0x10000U)
#define DDRC_DFILPCFG0_dfi_lp_en_dpd_SHIFT       (16U)
/*! dfi_lp_en_dpd - Enables DFI Low Power interface handshaking during Deep Power Down Entry/Exit. -
 *    0 - Disabled - 1 - Enabled This is only present for designs supporting mDDR or LPDDR2/LPDDR3
 *    devices.
 */
#define DDRC_DFILPCFG0_dfi_lp_en_dpd(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DFILPCFG0_dfi_lp_en_dpd_SHIFT)) & DDRC_DFILPCFG0_dfi_lp_en_dpd_MASK)

#define DDRC_DFILPCFG0_dfi_lp_wakeup_dpd_MASK    (0xF00000U)
#define DDRC_DFILPCFG0_dfi_lp_wakeup_dpd_SHIFT   (20U)
/*! dfi_lp_wakeup_dpd - Value in DFI clock cycles to drive on dfi_lp_wakeup signal when Deep Power
 *    Down mode is entered. Determines the DFI's tlp_wakeup time: This is only present for designs
 *    supporting mDDR or LPDDR2/LPDDR3 devices.
 *  0b0000..16 cycles
 *  0b0001..32 cycles
 *  0b0010..64 cycles
 *  0b0011..128 cycles
 *  0b0100..256 cycles
 *  0b0101..512 cycles
 *  0b0110..1024 cycles
 *  0b0111..2048 cycles
 *  0b1000..4096 cycles
 *  0b1001..8192 cycles
 *  0b1010..16384 cycles
 *  0b1011..32768 cycles
 *  0b1100..65536 cycles
 *  0b1101..131072 cycles
 *  0b1110..262144 cycles
 *  0b1111..Unlimited cycles
 */
#define DDRC_DFILPCFG0_dfi_lp_wakeup_dpd(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_DFILPCFG0_dfi_lp_wakeup_dpd_SHIFT)) & DDRC_DFILPCFG0_dfi_lp_wakeup_dpd_MASK)

#define DDRC_DFILPCFG0_dfi_tlp_resp_MASK         (0x1F000000U)
#define DDRC_DFILPCFG0_dfi_tlp_resp_SHIFT        (24U)
/*! dfi_tlp_resp - Setting in DFI clock cycles for DFI's tlp_resp time. Same value is used for both
 *    Power Down, Self Refresh, Deep Power Down and Maximum Power Saving modes. DFI 2.1
 *    specification onwards, recommends using a fixed value of 7 always.
 */
#define DDRC_DFILPCFG0_dfi_tlp_resp(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DFILPCFG0_dfi_tlp_resp_SHIFT)) & DDRC_DFILPCFG0_dfi_tlp_resp_MASK)
/*! @} */

/*! @name DFILPCFG1 - DFI Low Power Configuration Register 1 */
/*! @{ */

#define DDRC_DFILPCFG1_dfi_lp_en_mpsm_MASK       (0x1U)
#define DDRC_DFILPCFG1_dfi_lp_en_mpsm_SHIFT      (0U)
/*! dfi_lp_en_mpsm - Enables DFI Low Power interface handshaking during Maximum Power Saving Mode
 *    Entry/Exit. - 0 - Disabled - 1 - Enabled This is only present for designs supporting DDR4
 *    devices.
 */
#define DDRC_DFILPCFG1_dfi_lp_en_mpsm(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DFILPCFG1_dfi_lp_en_mpsm_SHIFT)) & DDRC_DFILPCFG1_dfi_lp_en_mpsm_MASK)

#define DDRC_DFILPCFG1_dfi_lp_wakeup_mpsm_MASK   (0xF0U)
#define DDRC_DFILPCFG1_dfi_lp_wakeup_mpsm_SHIFT  (4U)
/*! dfi_lp_wakeup_mpsm - Value in DFI clock cycles to drive on dfi_lp_wakeup signal when Maximum
 *    Power Saving Mode is entered. Determines the DFI's tlp_wakeup time:
 *  0b0000..16 cycles
 *  0b0001..32 cycles
 *  0b0010..64 cycles
 *  0b0011..128 cycles
 *  0b0100..256 cycles
 *  0b0101..512 cycles
 *  0b0110..1024 cycles
 *  0b0111..2048 cycles
 *  0b1000..4096 cycles
 *  0b1001..8192 cycles
 *  0b1010..16384 cycles
 *  0b1011..32768 cycles
 *  0b1100..65536 cycles
 *  0b1101..131072 cycles
 *  0b1110..262144 cycles
 *  0b1111..Unlimited cycles
 */
#define DDRC_DFILPCFG1_dfi_lp_wakeup_mpsm(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DFILPCFG1_dfi_lp_wakeup_mpsm_SHIFT)) & DDRC_DFILPCFG1_dfi_lp_wakeup_mpsm_MASK)
/*! @} */

/*! @name DFIUPD0 - DFI Update Register 0 */
/*! @{ */

#define DDRC_DFIUPD0_dfi_t_ctrlup_min_MASK       (0x3FFU)
#define DDRC_DFIUPD0_dfi_t_ctrlup_min_SHIFT      (0U)
/*! dfi_t_ctrlup_min - Specifies the minimum number of DFI clock cycles that the dfi_ctrlupd_req
 *    signal must be asserted. The DDRC expects the PHY to respond within this time. If the PHY does
 *    not respond, the DDRC will de-assert dfi_ctrlupd_req after dfi_t_ctrlup_min + 2 cycles. Lowest
 *    value to assign to this variable is 0x3.
 */
#define DDRC_DFIUPD0_dfi_t_ctrlup_min(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DFIUPD0_dfi_t_ctrlup_min_SHIFT)) & DDRC_DFIUPD0_dfi_t_ctrlup_min_MASK)

#define DDRC_DFIUPD0_dfi_t_ctrlup_max_MASK       (0x3FF0000U)
#define DDRC_DFIUPD0_dfi_t_ctrlup_max_SHIFT      (16U)
/*! dfi_t_ctrlup_max - Specifies the maximum number of DFI clock cycles that the dfi_ctrlupd_req
 *    signal can assert. Lowest value to assign to this variable is 0x40.
 */
#define DDRC_DFIUPD0_dfi_t_ctrlup_max(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DFIUPD0_dfi_t_ctrlup_max_SHIFT)) & DDRC_DFIUPD0_dfi_t_ctrlup_max_MASK)

#define DDRC_DFIUPD0_ctrlupd_pre_srx_MASK        (0x20000000U)
#define DDRC_DFIUPD0_ctrlupd_pre_srx_SHIFT       (29U)
/*! ctrlupd_pre_srx - Selects dfi_ctrlupd_req requirements at SRX: - 0 : send ctrlupd after SRX - 1
 *    : send ctrlupd before SRX If DFIUPD0.dis_auto_ctrlupd_srx=1, this register has no impact,
 *    because no dfi_ctrlupd_req will be issued when SRX.
 *  0b0..send ctrlupd after SRX
 *  0b1..send ctrlupd before SRX
 */
#define DDRC_DFIUPD0_ctrlupd_pre_srx(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DFIUPD0_ctrlupd_pre_srx_SHIFT)) & DDRC_DFIUPD0_ctrlupd_pre_srx_MASK)

#define DDRC_DFIUPD0_dis_auto_ctrlupd_srx_MASK   (0x40000000U)
#define DDRC_DFIUPD0_dis_auto_ctrlupd_srx_SHIFT  (30U)
/*! dis_auto_ctrlupd_srx - Auto ctrlupd request generation
 *  0b0..DDRC issues a dfi_ctrlupd_req before or after exiting self-refresh, depending on DFIUPD0.ctrlupd_pre_srx.
 *  0b1..disable the automatic dfi_ctrlupd_req generation by the DDRC at self-refresh exit.
 */
#define DDRC_DFIUPD0_dis_auto_ctrlupd_srx(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DFIUPD0_dis_auto_ctrlupd_srx_SHIFT)) & DDRC_DFIUPD0_dis_auto_ctrlupd_srx_MASK)

#define DDRC_DFIUPD0_dis_auto_ctrlupd_MASK       (0x80000000U)
#define DDRC_DFIUPD0_dis_auto_ctrlupd_SHIFT      (31U)
/*! dis_auto_ctrlupd - automatic dfi_ctrlupd_req generation by the DDRC
 *  0b0..DDRC issues dfi_ctrlupd_req periodically.
 *  0b1..disable the automatic dfi_ctrlupd_req generation by the DDRC. The core must issue the dfi_ctrlupd_req
 *       signal using register reg_ddrc_ctrlupd.
 */
#define DDRC_DFIUPD0_dis_auto_ctrlupd(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DFIUPD0_dis_auto_ctrlupd_SHIFT)) & DDRC_DFIUPD0_dis_auto_ctrlupd_MASK)
/*! @} */

/*! @name DFIUPD1 - DFI Update Register 1 */
/*! @{ */

#define DDRC_DFIUPD1_dfi_t_ctrlupd_interval_max_x1024_MASK (0xFFU)
#define DDRC_DFIUPD1_dfi_t_ctrlupd_interval_max_x1024_SHIFT (0U)
/*! dfi_t_ctrlupd_interval_max_x1024 - This is the maximum amount of time between DDRC initiated DFI
 *    update requests. This timer resets with each update request; when the timer expires
 *    dfi_ctrlupd_req is sent and traffic is blocked until the dfi_ctrlupd_ackx is received. PHY can use this
 *    idle time to recalibrate the delay lines to the DLLs. The DFI controller update is also used
 *    to reset PHY FIFO pointers in case of data capture errors. Updates are required to maintain
 *    calibration over PVT, but frequent updates may impact performance. Minimum allowed value for
 *    this field is 1. Note: Value programmed for DFIUPD1.dfi_t_ctrlupd_interval_max_x1024 must be
 *    greater than DFIUPD1.dfi_t_ctrlupd_interval_min_x1024. Unit: 1024 DFI clock cycles
 */
#define DDRC_DFIUPD1_dfi_t_ctrlupd_interval_max_x1024(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DFIUPD1_dfi_t_ctrlupd_interval_max_x1024_SHIFT)) & DDRC_DFIUPD1_dfi_t_ctrlupd_interval_max_x1024_MASK)

#define DDRC_DFIUPD1_dfi_t_ctrlupd_interval_min_x1024_MASK (0xFF0000U)
#define DDRC_DFIUPD1_dfi_t_ctrlupd_interval_min_x1024_SHIFT (16U)
/*! dfi_t_ctrlupd_interval_min_x1024 - This is the minimum amount of time between DDRC initiated DFI
 *    update requests (which is executed whenever the DDRC is idle). Set this number higher to
 *    reduce the frequency of update requests, which can have a small impact on the latency of the first
 *    read request when the DDRC is idle. Minimum allowed value for this field is 1. Unit: 1024 DFI
 *    clock cycles
 */
#define DDRC_DFIUPD1_dfi_t_ctrlupd_interval_min_x1024(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DFIUPD1_dfi_t_ctrlupd_interval_min_x1024_SHIFT)) & DDRC_DFIUPD1_dfi_t_ctrlupd_interval_min_x1024_MASK)
/*! @} */

/*! @name DFIUPD2 - DFI Update Register 2 */
/*! @{ */

#define DDRC_DFIUPD2_dfi_phyupd_en_MASK          (0x80000000U)
#define DDRC_DFIUPD2_dfi_phyupd_en_SHIFT         (31U)
/*! dfi_phyupd_en - Enables the support for acknowledging PHY-initiated updates:
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DDRC_DFIUPD2_dfi_phyupd_en(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DFIUPD2_dfi_phyupd_en_SHIFT)) & DDRC_DFIUPD2_dfi_phyupd_en_MASK)
/*! @} */

/*! @name DFIMISC - DFI Miscellaneous Control Register */
/*! @{ */

#define DDRC_DFIMISC_dfi_init_complete_en_MASK   (0x1U)
#define DDRC_DFIMISC_dfi_init_complete_en_SHIFT  (0U)
/*! dfi_init_complete_en - PHY initialization complete enable signal. When asserted the
 *    dfi_init_complete signal can be used to trigger SDRAM initialisation
 */
#define DDRC_DFIMISC_dfi_init_complete_en(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DFIMISC_dfi_init_complete_en_SHIFT)) & DDRC_DFIMISC_dfi_init_complete_en_MASK)

#define DDRC_DFIMISC_phy_dbi_mode_MASK           (0x2U)
#define DDRC_DFIMISC_phy_dbi_mode_SHIFT          (1U)
/*! phy_dbi_mode - DBI implemented in DDRC or PHY. Present only in designs configured to support DDR4 and LPDDR4.
 *  0b0..DDRC implements DBI functionality.
 *  0b1..PHY implements DBI functionality.
 */
#define DDRC_DFIMISC_phy_dbi_mode(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DFIMISC_phy_dbi_mode_SHIFT)) & DDRC_DFIMISC_phy_dbi_mode_MASK)

#define DDRC_DFIMISC_dfi_data_cs_polarity_MASK   (0x4U)
#define DDRC_DFIMISC_dfi_data_cs_polarity_SHIFT  (2U)
/*! dfi_data_cs_polarity - Defines polarity of dfi_wrdata_cs and dfi_rddata_cs signals.
 *  0b0..Signals are active low
 *  0b1..Signals are active high
 */
#define DDRC_DFIMISC_dfi_data_cs_polarity(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DFIMISC_dfi_data_cs_polarity_SHIFT)) & DDRC_DFIMISC_dfi_data_cs_polarity_MASK)

#define DDRC_DFIMISC_ctl_idle_en_MASK            (0x10U)
#define DDRC_DFIMISC_ctl_idle_en_SHIFT           (4U)
/*! ctl_idle_en - Enables support of ctl_idle signal, which is non-DFI related pin specific to
 *    certain PHYs. See signal description of ctl_idle signal for further details of ctl_idle
 *    functionality.
 */
#define DDRC_DFIMISC_ctl_idle_en(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_DFIMISC_ctl_idle_en_SHIFT)) & DDRC_DFIMISC_ctl_idle_en_MASK)

#define DDRC_DFIMISC_dfi_init_start_MASK         (0x20U)
#define DDRC_DFIMISC_dfi_init_start_SHIFT        (5U)
/*! dfi_init_start - PHY init start request signal.When asserted it triggers the PHY init start request */
#define DDRC_DFIMISC_dfi_init_start(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DFIMISC_dfi_init_start_SHIFT)) & DDRC_DFIMISC_dfi_init_start_MASK)

#define DDRC_DFIMISC_dfi_frequency_MASK          (0x1F00U)
#define DDRC_DFIMISC_dfi_frequency_SHIFT         (8U)
/*! dfi_frequency - Indicates the operating frequency of the system. The number of supported
 *    frequencies and the mapping of signal values to clock frequencies are defined by the PHY.
 */
#define DDRC_DFIMISC_dfi_frequency(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DFIMISC_dfi_frequency_SHIFT)) & DDRC_DFIMISC_dfi_frequency_MASK)
/*! @} */

/*! @name DFITMG2 - DFI Timing Register 2 */
/*! @{ */

#define DDRC_DFITMG2_dfi_tphy_wrcslat_MASK       (0x3FU)
#define DDRC_DFITMG2_dfi_tphy_wrcslat_SHIFT      (0U)
/*! dfi_tphy_wrcslat - Number of DFI PHY clock cycles between when a write command is sent on the
 *    DFI control interface and when the associated dfi_wrdata_cs signal is asserted. This corresponds
 *    to the DFI timing parameter tphy_wrcslat. Refer to PHY specification for correct value.
 */
#define DDRC_DFITMG2_dfi_tphy_wrcslat(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG2_dfi_tphy_wrcslat_SHIFT)) & DDRC_DFITMG2_dfi_tphy_wrcslat_MASK)

#define DDRC_DFITMG2_dfi_tphy_rdcslat_MASK       (0x7F00U)
#define DDRC_DFITMG2_dfi_tphy_rdcslat_SHIFT      (8U)
/*! dfi_tphy_rdcslat - Number of DFI PHY clock cycles between when a read command is sent on the DFI
 *    control interface and when the associated dfi_rddata_cs signal is asserted. This corresponds
 *    to the DFI timing parameter tphy_rdcslat. Refer to PHY specification for correct value.
 */
#define DDRC_DFITMG2_dfi_tphy_rdcslat(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG2_dfi_tphy_rdcslat_SHIFT)) & DDRC_DFITMG2_dfi_tphy_rdcslat_MASK)
/*! @} */

/*! @name DFITMG3 - DFI Timing Register 3 */
/*! @{ */

#define DDRC_DFITMG3_dfi_t_geardown_delay_MASK   (0x1FU)
#define DDRC_DFITMG3_dfi_t_geardown_delay_SHIFT  (0U)
/*! dfi_t_geardown_delay - The delay from dfi_geardown_en assertion to the time of the PHY being
 *    ready to receive commands. Refer to PHY specification for correct value. When the controller is
 *    operating in 1:2 frequency ratio mode, program this to (tgeardown_delay/2) and round it up to
 *    the next integer value. Unit: Clocks
 */
#define DDRC_DFITMG3_dfi_t_geardown_delay(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG3_dfi_t_geardown_delay_SHIFT)) & DDRC_DFITMG3_dfi_t_geardown_delay_MASK)
/*! @} */

/*! @name DFISTAT - DFI Status Register */
/*! @{ */

#define DDRC_DFISTAT_dfi_init_complete_MASK      (0x1U)
#define DDRC_DFISTAT_dfi_init_complete_SHIFT     (0U)
/*! dfi_init_complete - The status flag register which announces when the DFI initialization has
 *    been completed. The DFI INIT triggered by dfi_init_start signal and then the dfi_init_complete
 *    flag is polled to know when the initialization is done.
 */
#define DDRC_DFISTAT_dfi_init_complete(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DFISTAT_dfi_init_complete_SHIFT)) & DDRC_DFISTAT_dfi_init_complete_MASK)

#define DDRC_DFISTAT_dfi_lp_ack_MASK             (0x2U)
#define DDRC_DFISTAT_dfi_lp_ack_SHIFT            (1U)
/*! dfi_lp_ack - Stores the value of the dfi_lp_ack input to the controller. */
#define DDRC_DFISTAT_dfi_lp_ack(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DFISTAT_dfi_lp_ack_SHIFT)) & DDRC_DFISTAT_dfi_lp_ack_MASK)
/*! @} */

/*! @name DBICTL - DM/DBI Control Register */
/*! @{ */

#define DDRC_DBICTL_dm_en_MASK                   (0x1U)
#define DDRC_DBICTL_dm_en_SHIFT                  (0U)
/*! dm_en - DM enable signal in DDRC. This signal must be set the same logical value as DRAM's mode
 *    register. - DDR4: Set this to same value as MR5 bit A10. When x4 devices are used, this signal
 *    must be set to 0. - LPDDR4: Set this to inverted value of MR13[5] which is opposite polarity
 *    from this signal
 *  0b0..DM is disabled
 *  0b1..DM is enabled
 */
#define DDRC_DBICTL_dm_en(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_DBICTL_dm_en_SHIFT)) & DDRC_DBICTL_dm_en_MASK)

#define DDRC_DBICTL_wr_dbi_en_MASK               (0x2U)
#define DDRC_DBICTL_wr_dbi_en_SHIFT              (1U)
/*! wr_dbi_en - This signal must be set the same value as DRAM's mode register. - DDR4: MR5 bit A11.
 *    When x4 devices are used, this signal must be set to 0. - LPDDR4: MR3[7]
 *  0b0..Write DBI is disabled
 *  0b1..Write DBI is enabled.
 */
#define DDRC_DBICTL_wr_dbi_en(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DBICTL_wr_dbi_en_SHIFT)) & DDRC_DBICTL_wr_dbi_en_MASK)

#define DDRC_DBICTL_rd_dbi_en_MASK               (0x4U)
#define DDRC_DBICTL_rd_dbi_en_SHIFT              (2U)
/*! rd_dbi_en - Read DBI enable signal in DDRC. - 0 - Read DBI is disabled. - 1 - Read DBI is
 *    enabled. This signal must be set the same value as DRAM's mode register. - DDR4: MR5 bit A12. When
 *    x4 devices are used, this signal must be set to 0. - LPDDR4: MR3[6]
 */
#define DDRC_DBICTL_rd_dbi_en(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DBICTL_rd_dbi_en_SHIFT)) & DDRC_DBICTL_rd_dbi_en_MASK)
/*! @} */

/*! @name ADDRMAP0 - Address Map Register 0 */
/*! @{ */

#define DDRC_ADDRMAP0_addrmap_cs_bit0_MASK       (0x1FU)
#define DDRC_ADDRMAP0_addrmap_cs_bit0_SHIFT      (0U)
/*! addrmap_cs_bit0 - Selects the HIF address bit used as rank address bit 0. Valid Range: 0 to 28,
 *    and 31 Internal Base: 6 The selected HIF address bit is determined by adding the internal base
 *    to the value of this field. If set to 31, rank address bit 0 is set to 0.
 */
#define DDRC_ADDRMAP0_addrmap_cs_bit0(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP0_addrmap_cs_bit0_SHIFT)) & DDRC_ADDRMAP0_addrmap_cs_bit0_MASK)
/*! @} */

/*! @name ADDRMAP1 - Address Map Register 1 */
/*! @{ */

#define DDRC_ADDRMAP1_addrmap_bank_b0_MASK       (0x1FU)
#define DDRC_ADDRMAP1_addrmap_bank_b0_SHIFT      (0U)
/*! addrmap_bank_b0 - Selects the HIF address bits used as bank address bit 0. Valid Range: 0 to 31
 *    Internal Base: 2 The selected HIF address bit for each of the bank address bits is determined
 *    by adding the internal base to the value of this field.
 */
#define DDRC_ADDRMAP1_addrmap_bank_b0(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP1_addrmap_bank_b0_SHIFT)) & DDRC_ADDRMAP1_addrmap_bank_b0_MASK)

#define DDRC_ADDRMAP1_addrmap_bank_b1_MASK       (0x1F00U)
#define DDRC_ADDRMAP1_addrmap_bank_b1_SHIFT      (8U)
/*! addrmap_bank_b1 - Selects the HIF address bits used as bank address bit 1. Valid Range: 0 to 31
 *    Internal Base: 3 The selected HIF address bit for each of the bank address bits is determined
 *    by adding the internal base to the value of this field.
 */
#define DDRC_ADDRMAP1_addrmap_bank_b1(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP1_addrmap_bank_b1_SHIFT)) & DDRC_ADDRMAP1_addrmap_bank_b1_MASK)

#define DDRC_ADDRMAP1_addrmap_bank_b2_MASK       (0x1F0000U)
#define DDRC_ADDRMAP1_addrmap_bank_b2_SHIFT      (16U)
/*! addrmap_bank_b2 - Selects the HIF address bit used as bank address bit 2. Valid Range: 0 to 30
 *    and 31 Internal Base: 4 The selected HIF address bit is determined by adding the internal base
 *    to the value of this field. If set to 31, bank address bit 2 is set to 0.
 */
#define DDRC_ADDRMAP1_addrmap_bank_b2(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP1_addrmap_bank_b2_SHIFT)) & DDRC_ADDRMAP1_addrmap_bank_b2_MASK)
/*! @} */

/*! @name ADDRMAP2 - Address Map Register 2 */
/*! @{ */

#define DDRC_ADDRMAP2_addrmap_col_b2_MASK        (0xFU)
#define DDRC_ADDRMAP2_addrmap_col_b2_SHIFT       (0U)
/*! addrmap_col_b2 - - Full bus width mode: Selects the HIF address bit used as column address bit
 *    2. - Half bus width mode: Selects the HIF address bit used as column address bit 3. - Quarter
 *    bus width mode: Selects the HIF address bit used as column address bit 4. Valid Range: 0 to 7
 *    Internal Base: 2 The selected HIF address bit is determined by adding the internal base to the
 *    value of this field. Note, if DDRC_INCL_ARB=1 and MEMC_BURST_LENGTH=8, it is required to
 *    program this to 0 unless: - in Half or Quarter bus width (MSTR.data_bus_width!=00) and -
 *    PCCFG.bl_exp_mode==1 and either - In DDR4 and ADDRMAP8.addrmap_bg_b0==0 or - In LPDDR4 and
 *    ADDRMAP1.addrmap_bank_b0==0 If DDRC_INCL_ARB=1 and MEMC_BURST_LENGTH=16, it is required to program this to
 *    0 unless: - in Half or Quarter bus width (MSTR.data_bus_width!=00) and - PCCFG.bl_exp_mode==1
 *    and - In DDR4 and ADDRMAP8.addrmap_bg_b0==0 Otherwise, if MEMC_BURST_LENGTH=8 and Full Bus
 *    Width (MSTR.data_bus_width==00), it is recommended to program this to 0 so that HIF[2] maps to
 *    column address bit 2. If MEMC_BURST_LENGTH=16 and Full Bus Width (MSTR.data_bus_width==00), it
 *    is recommended to program this to 0 so that HIF[2] maps to column address bit 2. If
 *    MEMC_BURST_LENGTH=16 and Half Bus Width (MSTR.data_bus_width==01), it is recommended to program this to 0
 *    so that HIF[2] maps to column address bit 3.
 */
#define DDRC_ADDRMAP2_addrmap_col_b2(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP2_addrmap_col_b2_SHIFT)) & DDRC_ADDRMAP2_addrmap_col_b2_MASK)

#define DDRC_ADDRMAP2_addrmap_col_b3_MASK        (0xF00U)
#define DDRC_ADDRMAP2_addrmap_col_b3_SHIFT       (8U)
/*! addrmap_col_b3 - - Full bus width mode: Selects the HIF address bit used as column address bit
 *    3. - Half bus width mode: Selects the HIF address bit used as column address bit 4. - Quarter
 *    bus width mode: Selects the HIF address bit used as column address bit 5. Valid Range: 0 to 7
 *    Internal Base: 3 The selected HIF address bit is determined by adding the internal base to the
 *    value of this field. Note, if DDRC_INCL_ARB=1, MEMC_BURST_LENGTH=16, Full bus width
 *    (MSTR.data_bus_width=00) and BL16 (MSTR.burst_rdwr=1000), it is recommended to program this to 0.
 */
#define DDRC_ADDRMAP2_addrmap_col_b3(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP2_addrmap_col_b3_SHIFT)) & DDRC_ADDRMAP2_addrmap_col_b3_MASK)

#define DDRC_ADDRMAP2_addrmap_col_b4_MASK        (0xF0000U)
#define DDRC_ADDRMAP2_addrmap_col_b4_SHIFT       (16U)
/*! addrmap_col_b4 - - Full bus width mode: Selects the HIF address bit used as column address bit
 *    4. - Half bus width mode: Selects the HIF address bit used as column address bit 5. - Quarter
 *    bus width mode: Selects the HIF address bit used as column address bit 6. Valid Range: 0 to 7,
 *    and 15 Internal Base: 4 The selected HIF address bit is determined by adding the internal base
 *    to the value of this field. If set to 15, this column address bit is set to 0.
 */
#define DDRC_ADDRMAP2_addrmap_col_b4(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP2_addrmap_col_b4_SHIFT)) & DDRC_ADDRMAP2_addrmap_col_b4_MASK)

#define DDRC_ADDRMAP2_addrmap_col_b5_MASK        (0xF000000U)
#define DDRC_ADDRMAP2_addrmap_col_b5_SHIFT       (24U)
/*! addrmap_col_b5 - - Full bus width mode: Selects the HIF address bit used as column address bit
 *    5. - Half bus width mode: Selects the HIF address bit used as column address bit 6. - Quarter
 *    bus width mode: Selects the HIF address bit used as column address bit 7 . Valid Range: 0 to 7,
 *    and 15 Internal Base: 5 The selected HIF address bit is determined by adding the internal
 *    base to the value of this field. If set to 15, this column address bit is set to 0.
 */
#define DDRC_ADDRMAP2_addrmap_col_b5(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP2_addrmap_col_b5_SHIFT)) & DDRC_ADDRMAP2_addrmap_col_b5_MASK)
/*! @} */

/*! @name ADDRMAP3 - Address Map Register 3 */
/*! @{ */

#define DDRC_ADDRMAP3_addrmap_col_b6_MASK        (0xFU)
#define DDRC_ADDRMAP3_addrmap_col_b6_SHIFT       (0U)
/*! addrmap_col_b6 - - Full bus width mode: Selects the HIF address bit used as column address bit
 *    6. - Half bus width mode: Selects the HIF address bit used as column address bit 7. - Quarter
 *    bus width mode: Selects the HIF address bit used as column address bit 8. Valid Range: 0 to 7,
 *    and 15 Internal Base: 6 The selected HIF address bit is determined by adding the internal base
 *    to the value of this field. If set to 15, this column address bit is set to 0.
 */
#define DDRC_ADDRMAP3_addrmap_col_b6(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP3_addrmap_col_b6_SHIFT)) & DDRC_ADDRMAP3_addrmap_col_b6_MASK)

#define DDRC_ADDRMAP3_addrmap_col_b7_MASK        (0xF00U)
#define DDRC_ADDRMAP3_addrmap_col_b7_SHIFT       (8U)
/*! addrmap_col_b7 - - Full bus width mode: Selects the HIF address bit used as column address bit
 *    7. - Half bus width mode: Selects the HIF address bit used as column address bit 8. - Quarter
 *    bus width mode: Selects the HIF address bit used as column address bit 9. Valid Range: 0 to 7,
 *    and 15 Internal Base: 7 The selected HIF address bit is determined by adding the internal base
 *    to the value of this field. If set to 15, this column address bit is set to 0.
 */
#define DDRC_ADDRMAP3_addrmap_col_b7(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP3_addrmap_col_b7_SHIFT)) & DDRC_ADDRMAP3_addrmap_col_b7_MASK)

#define DDRC_ADDRMAP3_addrmap_col_b8_MASK        (0xF0000U)
#define DDRC_ADDRMAP3_addrmap_col_b8_SHIFT       (16U)
/*! addrmap_col_b8 - - Full bus width mode: Selects the HIF address bit used as column address bit
 *    8. - Half bus width mode: Selects the HIF address bit used as column address bit 9. - Quarter
 *    bus width mode: Selects the HIF address bit used as column address bit 11 (10 in LPDDR2/LPDDR3
 *    mode). Valid Range: 0 to 7, and 15 Internal Base: 8 The selected HIF address bit is determined
 *    by adding the internal base to the value of this field. If set to 15, this column address bit
 *    is set to 0. Note: Per JEDEC DDR2/3/mDDR specification, column address bit 10 is reserved for
 *    indicating auto-precharge, and hence no source address bit can be mapped to column address
 *    bit 10. In LPDDR2/LPDDR3, there is a dedicated bit for auto-precharge in the CA bus and hence
 *    column bit 10 is used.
 */
#define DDRC_ADDRMAP3_addrmap_col_b8(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP3_addrmap_col_b8_SHIFT)) & DDRC_ADDRMAP3_addrmap_col_b8_MASK)

#define DDRC_ADDRMAP3_addrmap_col_b9_MASK        (0xF000000U)
#define DDRC_ADDRMAP3_addrmap_col_b9_SHIFT       (24U)
/*! addrmap_col_b9 - - Full bus width mode: Selects the HIF address bit used as column address bit
 *    9. - Half bus width mode: Selects the HIF address bit used as column address bit 11 (10 in
 *    LPDDR2/LPDDR3 mode). - Quarter bus width mode: Selects the HIF address bit used as column address
 *    bit 13 (11 in LPDDR2/LPDDR3 mode). Valid Range: 0 to 7, and 15 Internal Base: 9 The selected
 *    HIF address bit is determined by adding the internal base to the value of this field. If set to
 *    15, this column address bit is set to 0. Note: Per JEDEC DDR2/3/mDDR specification, column
 *    address bit 10 is reserved for indicating auto-precharge, and hence no source address bit can be
 *    mapped to column address bit 10. In LPDDR2/LPDDR3, there is a dedicated bit for
 *    auto-precharge in the CA bus and hence column bit 10 is used.
 */
#define DDRC_ADDRMAP3_addrmap_col_b9(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP3_addrmap_col_b9_SHIFT)) & DDRC_ADDRMAP3_addrmap_col_b9_MASK)
/*! @} */

/*! @name ADDRMAP4 - Address Map Register 4 */
/*! @{ */

#define DDRC_ADDRMAP4_addrmap_col_b10_MASK       (0xFU)
#define DDRC_ADDRMAP4_addrmap_col_b10_SHIFT      (0U)
/*! addrmap_col_b10 - - Full bus width mode: Selects the HIF address bit used as column address bit
 *    11 (10 in LPDDR2/LPDDR3 mode). - Half bus width mode: Selects the HIF address bit used as
 *    column address bit 13 (11 in LPDDR2/LPDDR3 mode). - Quarter bus width mode: UNUSED. To make it
 *    unused, this must be tied to 4'hF. Valid Range: 0 to 7, and 15 Internal Base: 10 The selected HIF
 *    address bit is determined by adding the internal base to the value of this field. If set to
 *    15, this column address bit is set to 0. Note: Per JEDEC DDR2/3/mDDR specification, column
 *    address bit 10 is reserved for indicating auto-precharge, and hence no source address bit can be
 *    mapped to column address bit 10. In LPDDR2/LPDDR3, there is a dedicated bit for auto-precharge
 *    in the CA bus and hence column bit 10 is used.
 */
#define DDRC_ADDRMAP4_addrmap_col_b10(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP4_addrmap_col_b10_SHIFT)) & DDRC_ADDRMAP4_addrmap_col_b10_MASK)

#define DDRC_ADDRMAP4_addrmap_col_b11_MASK       (0xF00U)
#define DDRC_ADDRMAP4_addrmap_col_b11_SHIFT      (8U)
/*! addrmap_col_b11 - - Full bus width mode: Selects the HIF address bit used as column address bit
 *    13 (11 in LPDDR2/LPDDR3 mode). - Half bus width mode: Unused. To make it unused, this should
 *    be tied to 4'hF. - Quarter bus width mode: Unused. To make it unused, this must be tied to
 *    4'hF. Valid Range: 0 to 7, and 15 Internal Base: 11 The selected HIF address bit is determined by
 *    adding the internal base to the value of this field. If set to 15, this column address bit is
 *    set to 0. Note: Per JEDEC DDR2/3/mDDR specification, column address bit 10 is reserved for
 *    indicating auto-precharge, and hence no source address bit can be mapped to column address bit
 *    10. In LPDDR2/LPDDR3, there is a dedicated bit for auto-precharge in the CA bus and hence column
 *    bit 10 is used.
 */
#define DDRC_ADDRMAP4_addrmap_col_b11(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP4_addrmap_col_b11_SHIFT)) & DDRC_ADDRMAP4_addrmap_col_b11_MASK)
/*! @} */

/*! @name ADDRMAP5 - Address Map Register 5 */
/*! @{ */

#define DDRC_ADDRMAP5_addrmap_row_b0_MASK        (0xFU)
#define DDRC_ADDRMAP5_addrmap_row_b0_SHIFT       (0U)
/*! addrmap_row_b0 - Selects the HIF address bits used as row address bit 0. Valid Range: 0 to 11
 *    Internal Base: 6 The selected HIF address bit for each of the row address bits is determined by
 *    adding the internal base to the value of this field.
 */
#define DDRC_ADDRMAP5_addrmap_row_b0(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP5_addrmap_row_b0_SHIFT)) & DDRC_ADDRMAP5_addrmap_row_b0_MASK)

#define DDRC_ADDRMAP5_addrmap_row_b1_MASK        (0xF00U)
#define DDRC_ADDRMAP5_addrmap_row_b1_SHIFT       (8U)
/*! addrmap_row_b1 - Selects the HIF address bits used as row address bit 1. Valid Range: 0 to 11
 *    Internal Base: 7 The selected HIF address bit for each of the row address bits is determined by
 *    adding the internal base to the value of this field.
 */
#define DDRC_ADDRMAP5_addrmap_row_b1(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP5_addrmap_row_b1_SHIFT)) & DDRC_ADDRMAP5_addrmap_row_b1_MASK)

#define DDRC_ADDRMAP5_addrmap_row_b2_10_MASK     (0xF0000U)
#define DDRC_ADDRMAP5_addrmap_row_b2_10_SHIFT    (16U)
/*! addrmap_row_b2_10 - Selects the HIF address bits used as row address bits 2 to 10. Valid Range:
 *    0 to 11, and 15 Internal Base: 8 (for row address bit 2), 9 (for row address bit 3), 10 (for
 *    row address bit 4) etc increasing to 16 (for row address bit 10) The selected HIF address bit
 *    for each of the row address bits is determined by adding the internal base to the value of this
 *    field. When value 15 is used the values of row address bits 2 to 10 are defined by registers
 *    ADDRMAP9, ADDRMAP10, ADDRMAP11.
 */
#define DDRC_ADDRMAP5_addrmap_row_b2_10(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP5_addrmap_row_b2_10_SHIFT)) & DDRC_ADDRMAP5_addrmap_row_b2_10_MASK)

#define DDRC_ADDRMAP5_addrmap_row_b11_MASK       (0xF000000U)
#define DDRC_ADDRMAP5_addrmap_row_b11_SHIFT      (24U)
/*! addrmap_row_b11 - Selects the HIF address bit used as row address bit 11. Valid Range: 0 to 11,
 *    and 15 Internal Base: 17 The selected HIF address bit is determined by adding the internal
 *    base to the value of this field. If set to 15, row address bit 11 is set to 0.
 */
#define DDRC_ADDRMAP5_addrmap_row_b11(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP5_addrmap_row_b11_SHIFT)) & DDRC_ADDRMAP5_addrmap_row_b11_MASK)
/*! @} */

/*! @name ADDRMAP6 - Address Map Register 6 */
/*! @{ */

#define DDRC_ADDRMAP6_addrmap_row_b12_MASK       (0xFU)
#define DDRC_ADDRMAP6_addrmap_row_b12_SHIFT      (0U)
/*! addrmap_row_b12 - Selects the HIF address bit used as row address bit 12. Valid Range: 0 to 11,
 *    and 15 Internal Base: 18 The selected HIF address bit is determined by adding the internal
 *    base to the value of this field. If set to 15, row address bit 12 is set to 0.
 */
#define DDRC_ADDRMAP6_addrmap_row_b12(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP6_addrmap_row_b12_SHIFT)) & DDRC_ADDRMAP6_addrmap_row_b12_MASK)

#define DDRC_ADDRMAP6_addrmap_row_b13_MASK       (0xF00U)
#define DDRC_ADDRMAP6_addrmap_row_b13_SHIFT      (8U)
/*! addrmap_row_b13 - Selects the HIF address bit used as row address bit 13. Valid Range: 0 to 11,
 *    and 15 Internal Base: 19 The selected HIF address bit is determined by adding the internal
 *    base to the value of this field. If set to 15, row address bit 13 is set to 0.
 */
#define DDRC_ADDRMAP6_addrmap_row_b13(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP6_addrmap_row_b13_SHIFT)) & DDRC_ADDRMAP6_addrmap_row_b13_MASK)

#define DDRC_ADDRMAP6_addrmap_row_b14_MASK       (0xF0000U)
#define DDRC_ADDRMAP6_addrmap_row_b14_SHIFT      (16U)
/*! addrmap_row_b14 - Selects the HIF address bit used as row address bit 14. Valid Range: 0 to 11,
 *    and 15 Internal Base: 20 The selected HIF address bit is determined by adding the internal
 *    base to the value of this field. If set to 15, row address bit 14 is set to 0.
 */
#define DDRC_ADDRMAP6_addrmap_row_b14(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP6_addrmap_row_b14_SHIFT)) & DDRC_ADDRMAP6_addrmap_row_b14_MASK)

#define DDRC_ADDRMAP6_addrmap_row_b15_MASK       (0xF000000U)
#define DDRC_ADDRMAP6_addrmap_row_b15_SHIFT      (24U)
/*! addrmap_row_b15 - Selects the HIF address bit used as row address bit 15. Valid Range: 0 to 11,
 *    and 15 Internal Base: 21 The selected HIF address bit is determined by adding the internal
 *    base to the value of this field. If set to 15, row address bit 15 is set to 0.
 */
#define DDRC_ADDRMAP6_addrmap_row_b15(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP6_addrmap_row_b15_SHIFT)) & DDRC_ADDRMAP6_addrmap_row_b15_MASK)

#define DDRC_ADDRMAP6_lpddr3_6gb_12gb_MASK       (0x80000000U)
#define DDRC_ADDRMAP6_lpddr3_6gb_12gb_SHIFT      (31U)
/*! lpddr3_6gb_12gb - Set this to 1 if there is an LPDDR3 SDRAM 6Gb or 12Gb device in use. - 1 -
 *    LPDDR3 SDRAM 6Gb/12Gb device in use. Every address having row[14:13]==2'b11 is considered as
 *    invalid - 0 - non-LPDDR3 6Gb/12Gb device in use. All addresses are valid Present only in designs
 *    configured to support LPDDR3.
 */
#define DDRC_ADDRMAP6_lpddr3_6gb_12gb(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP6_lpddr3_6gb_12gb_SHIFT)) & DDRC_ADDRMAP6_lpddr3_6gb_12gb_MASK)
/*! @} */

/*! @name ADDRMAP7 - Address Map Register 7 */
/*! @{ */

#define DDRC_ADDRMAP7_addrmap_row_b16_MASK       (0xFU)
#define DDRC_ADDRMAP7_addrmap_row_b16_SHIFT      (0U)
/*! addrmap_row_b16 - Selects the HIF address bit used as row address bit 16. Valid Range: 0 to 11,
 *    and 15 Internal Base: 22 The selected HIF address bit is determined by adding the internal
 *    base to the value of this field. If set to 15, row address bit 16 is set to 0.
 */
#define DDRC_ADDRMAP7_addrmap_row_b16(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP7_addrmap_row_b16_SHIFT)) & DDRC_ADDRMAP7_addrmap_row_b16_MASK)

#define DDRC_ADDRMAP7_addrmap_row_b17_MASK       (0xF00U)
#define DDRC_ADDRMAP7_addrmap_row_b17_SHIFT      (8U)
/*! addrmap_row_b17 - Selects the HIF address bit used as row address bit 17. Valid Range: 0 to 11,
 *    and 15 Internal Base: 23 The selected HIF address bit is determined by adding the internal
 *    base to the value of this field. If set to 15, row address bit 17 is set to 0.
 */
#define DDRC_ADDRMAP7_addrmap_row_b17(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP7_addrmap_row_b17_SHIFT)) & DDRC_ADDRMAP7_addrmap_row_b17_MASK)
/*! @} */

/*! @name ADDRMAP8 - Address Map Register 8 */
/*! @{ */

#define DDRC_ADDRMAP8_addrmap_bg_b0_MASK         (0x1FU)
#define DDRC_ADDRMAP8_addrmap_bg_b0_SHIFT        (0U)
/*! addrmap_bg_b0 - Selects the HIF address bits used as bank group address bit 0. Valid Range: 0 to
 *    31 Internal Base: 2 The selected HIF address bit for each of the bank group address bits is
 *    determined by adding the internal base to the value of this field.
 */
#define DDRC_ADDRMAP8_addrmap_bg_b0(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP8_addrmap_bg_b0_SHIFT)) & DDRC_ADDRMAP8_addrmap_bg_b0_MASK)

#define DDRC_ADDRMAP8_addrmap_bg_b1_MASK         (0x3F00U)
#define DDRC_ADDRMAP8_addrmap_bg_b1_SHIFT        (8U)
/*! addrmap_bg_b1 - Selects the HIF address bits used as bank group address bit 1. Valid Range: 0 to
 *    31, and 63 Internal Base: 3 The selected HIF address bit for each of the bank group address
 *    bits is determined by adding the internal base to the value of this field. If set to 63, bank
 *    group address bit 1 is set to 0.
 */
#define DDRC_ADDRMAP8_addrmap_bg_b1(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP8_addrmap_bg_b1_SHIFT)) & DDRC_ADDRMAP8_addrmap_bg_b1_MASK)
/*! @} */

/*! @name ADDRMAP9 - Address Map Register 9 */
/*! @{ */

#define DDRC_ADDRMAP9_addrmap_row_b2_MASK        (0xFU)
#define DDRC_ADDRMAP9_addrmap_row_b2_SHIFT       (0U)
/*! addrmap_row_b2 - Selects the HIF address bits used as row address bit 2. Valid Range: 0 to 11
 *    Internal Base: 8 The selected HIF address bit for each of the row address bits is determined by
 *    adding the internal base to the value of this field. This register field is used only when
 *    ADDRMAP5.addrmap_row_b2_10 is set to value 15.
 */
#define DDRC_ADDRMAP9_addrmap_row_b2(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP9_addrmap_row_b2_SHIFT)) & DDRC_ADDRMAP9_addrmap_row_b2_MASK)

#define DDRC_ADDRMAP9_addrmap_row_b3_MASK        (0xF00U)
#define DDRC_ADDRMAP9_addrmap_row_b3_SHIFT       (8U)
/*! addrmap_row_b3 - Selects the HIF address bits used as row address bit 3. Valid Range: 0 to 11
 *    Internal Base: 9 The selected HIF address bit for each of the row address bits is determined by
 *    adding the internal base to the value of this field. This register field is used only when
 *    ADDRMAP5.addrmap_row_b2_10 is set to value 15.
 */
#define DDRC_ADDRMAP9_addrmap_row_b3(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP9_addrmap_row_b3_SHIFT)) & DDRC_ADDRMAP9_addrmap_row_b3_MASK)

#define DDRC_ADDRMAP9_addrmap_row_b4_MASK        (0xF0000U)
#define DDRC_ADDRMAP9_addrmap_row_b4_SHIFT       (16U)
/*! addrmap_row_b4 - Selects the HIF address bits used as row address bit 4. Valid Range: 0 to 11
 *    Internal Base: 10 The selected HIF address bit for each of the row address bits is determined by
 *    adding the internal base to the value of this field. This register field is used only when
 *    ADDRMAP5.addrmap_row_b2_10 is set to value 15.
 */
#define DDRC_ADDRMAP9_addrmap_row_b4(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP9_addrmap_row_b4_SHIFT)) & DDRC_ADDRMAP9_addrmap_row_b4_MASK)

#define DDRC_ADDRMAP9_addrmap_row_b5_MASK        (0xF000000U)
#define DDRC_ADDRMAP9_addrmap_row_b5_SHIFT       (24U)
/*! addrmap_row_b5 - Selects the HIF address bits used as row address bit 5. Valid Range: 0 to 11
 *    Internal Base: 11 The selected HIF address bit for each of the row address bits is determined by
 *    adding the internal base to the value of this field. This register field is used only when
 *    ADDRMAP5.addrmap_row_b2_10 is set to value 15.
 */
#define DDRC_ADDRMAP9_addrmap_row_b5(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP9_addrmap_row_b5_SHIFT)) & DDRC_ADDRMAP9_addrmap_row_b5_MASK)
/*! @} */

/*! @name ADDRMAP10 - Address Map Register 10 */
/*! @{ */

#define DDRC_ADDRMAP10_addrmap_row_b6_MASK       (0xFU)
#define DDRC_ADDRMAP10_addrmap_row_b6_SHIFT      (0U)
/*! addrmap_row_b6 - Selects the HIF address bits used as row address bit 6. Valid Range: 0 to 11
 *    Internal Base: 12 The selected HIF address bit for each of the row address bits is determined by
 *    adding the internal base to the value of this field. This register field is used only when
 *    ADDRMAP5.addrmap_row_b2_10 is set to value 15.
 */
#define DDRC_ADDRMAP10_addrmap_row_b6(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP10_addrmap_row_b6_SHIFT)) & DDRC_ADDRMAP10_addrmap_row_b6_MASK)

#define DDRC_ADDRMAP10_addrmap_row_b7_MASK       (0xF00U)
#define DDRC_ADDRMAP10_addrmap_row_b7_SHIFT      (8U)
/*! addrmap_row_b7 - Selects the HIF address bits used as row address bit 7. Valid Range: 0 to 11
 *    Internal Base: 13 The selected HIF address bit for each of the row address bits is determined by
 *    adding the internal base to the value of this field. This register field is used only when
 *    ADDRMAP5.addrmap_row_b2_10 is set to value 15.
 */
#define DDRC_ADDRMAP10_addrmap_row_b7(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP10_addrmap_row_b7_SHIFT)) & DDRC_ADDRMAP10_addrmap_row_b7_MASK)

#define DDRC_ADDRMAP10_addrmap_row_b8_MASK       (0xF0000U)
#define DDRC_ADDRMAP10_addrmap_row_b8_SHIFT      (16U)
/*! addrmap_row_b8 - Selects the HIF address bits used as row address bit 8. Valid Range: 0 to 11
 *    Internal Base: 14 The selected HIF address bit for each of the row address bits is determined by
 *    adding the internal base to the value of this field. This register field is used only when
 *    ADDRMAP5.addrmap_row_b2_10 is set to value 15.
 */
#define DDRC_ADDRMAP10_addrmap_row_b8(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP10_addrmap_row_b8_SHIFT)) & DDRC_ADDRMAP10_addrmap_row_b8_MASK)

#define DDRC_ADDRMAP10_addrmap_row_b9_MASK       (0xF000000U)
#define DDRC_ADDRMAP10_addrmap_row_b9_SHIFT      (24U)
/*! addrmap_row_b9 - Selects the HIF address bits used as row address bit 9. Valid Range: 0 to 11
 *    Internal Base: 15 The selected HIF address bit for each of the row address bits is determined by
 *    adding the internal base to the value of this field. This register field is used only when
 *    ADDRMAP5.addrmap_row_b2_10 is set to value 15.
 */
#define DDRC_ADDRMAP10_addrmap_row_b9(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP10_addrmap_row_b9_SHIFT)) & DDRC_ADDRMAP10_addrmap_row_b9_MASK)
/*! @} */

/*! @name ADDRMAP11 - Address Map Register 11 */
/*! @{ */

#define DDRC_ADDRMAP11_addrmap_row_b10_MASK      (0xFU)
#define DDRC_ADDRMAP11_addrmap_row_b10_SHIFT     (0U)
/*! addrmap_row_b10 - Selects the HIF address bits used as row address bit 10. Valid Range: 0 to 11
 *    Internal Base: 16 The selected HIF address bit for each of the row address bits is determined
 *    by adding the internal base to the value of this field. This register field is used only when
 *    ADDRMAP5.addrmap_row_b2_10 is set to value 15.
 */
#define DDRC_ADDRMAP11_addrmap_row_b10(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_ADDRMAP11_addrmap_row_b10_SHIFT)) & DDRC_ADDRMAP11_addrmap_row_b10_MASK)
/*! @} */

/*! @name ODTCFG - ODT Configuration Register */
/*! @{ */

#define DDRC_ODTCFG_rd_odt_delay_MASK            (0x7CU)
#define DDRC_ODTCFG_rd_odt_delay_SHIFT           (2U)
/*! rd_odt_delay - The delay, in DFI PHY clock cycles, from issuing a read command to setting ODT
 *    values associated with that command. ODT setting must remain constant for the entire time that
 *    DQS is driven by the DDRC. Recommended values: DDR2: - CL + AL - 4 (not DDR2-1066), CL + AL - 5
 *    (DDR2-1066) If (CL + AL - 4 < 0), DDRC does not support ODT for read operation. DDR3: - CL -
 *    CWL DDR4: - CL - CWL - RD_PREAMBLE + WR_PREAMBLE + DFITMG1.dfi_t_cmd_lat (to adjust for CAL
 *    mode) WR_PREAMBLE = 1 (1tCK write preamble), 2 (2tCK write preamble) RD_PREAMBLE = 1 (1tCK write
 *    preamble), 2 (2tCK write preamble) If (CL - CWL - RD_PREAMBLE + WR_PREAMBLE) < 0, DDRC does
 *    not support ODT for read operation. LPDDR3: - RL + RD(tDQSCK(min)/tCK) - 1 - RU(tODTon(max)/tCK)
 */
#define DDRC_ODTCFG_rd_odt_delay(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ODTCFG_rd_odt_delay_SHIFT)) & DDRC_ODTCFG_rd_odt_delay_MASK)

#define DDRC_ODTCFG_rd_odt_hold_MASK             (0xF00U)
#define DDRC_ODTCFG_rd_odt_hold_SHIFT            (8U)
/*! rd_odt_hold - DFI PHY clock cycles to hold ODT for a read command. The minimum supported value
 *    is 2. Recommended values: DDR2: - BL8: 0x6 (not DDR2-1066), 0x7 (DDR2-1066) - BL4: 0x4 (not
 *    DDR2-1066), 0x5 (DDR2-1066) DDR3: - BL8 - 0x6 DDR4: - BL8: 5 + RD_PREAMBLE RD_PREAMBLE = 1 (1tCK
 *    write preamble), 2 (2tCK write preamble) LPDDR3: - BL8: 5 + RU(tDQSCK(max)/tCK) -
 *    RD(tDQSCK(min)/tCK) + RU(tODTon(max)/tCK)
 */
#define DDRC_ODTCFG_rd_odt_hold(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ODTCFG_rd_odt_hold_SHIFT)) & DDRC_ODTCFG_rd_odt_hold_MASK)

#define DDRC_ODTCFG_wr_odt_delay_MASK            (0x1F0000U)
#define DDRC_ODTCFG_wr_odt_delay_SHIFT           (16U)
/*! wr_odt_delay - The delay, in DFI PHY clock cycles, from issuing a write command to setting ODT
 *    values associated with that command. ODT setting must remain constant for the entire time that
 *    DQS is driven by the DDRC. Recommended values: DDR2: - CWL + AL - 3 (DDR2-400/533/667), CWL +
 *    AL - 4 (DDR2-800), CWL + AL - 5 (DDR2-1066) If (CWL + AL - 3 < 0), DDRC does not support ODT
 *    for write operation. DDR3: - 0x0 DDR4: - DFITMG1.dfi_t_cmd_lat (to adjust for CAL mode) LPDDR3:
 *    - WL - 1 - RU(tODTon(max)/tCK))
 */
#define DDRC_ODTCFG_wr_odt_delay(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ODTCFG_wr_odt_delay_SHIFT)) & DDRC_ODTCFG_wr_odt_delay_MASK)

#define DDRC_ODTCFG_wr_odt_hold_MASK             (0xF000000U)
#define DDRC_ODTCFG_wr_odt_hold_SHIFT            (24U)
/*! wr_odt_hold - DFI PHY clock cycles to hold ODT for a write command. The minimum supported value
 *    is 2. Recommended values: DDR2: - BL8: 0x5 (DDR2-400/533/667), 0x6 (DDR2-800), 0x7 (DDR2-1066)
 *    - BL4: 0x3 (DDR2-400/533/667), 0x4 (DDR2-800), 0x5 (DDR2-1066) DDR3: - BL8: 0x6 DDR4: - BL8:
 *    5 + WR_PREAMBLE + CRC_MODE WR_PREAMBLE = 1 (1tCK write preamble), 2 (2tCK write preamble)
 *    CRC_MODE = 0 (not CRC mode), 1 (CRC mode) LPDDR3: - BL8: 7 + RU(tODTon(max)/tCK)
 */
#define DDRC_ODTCFG_wr_odt_hold(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_ODTCFG_wr_odt_hold_SHIFT)) & DDRC_ODTCFG_wr_odt_hold_MASK)
/*! @} */

/*! @name ODTMAP - ODT/Rank Map Register */
/*! @{ */

#define DDRC_ODTMAP_rank0_wr_odt_MASK            (0x3U)
#define DDRC_ODTMAP_rank0_wr_odt_SHIFT           (0U)
/*! rank0_wr_odt - Indicates which remote ODTs must be turned on during a write to rank 0. Each rank
 *    has a remote ODT (in the SDRAM) which can be turned on by setting the appropriate bit here.
 *    Rank 0 is controlled by the LSB; rank 1 is controlled by bit next to the LSB, etc. For each
 *    rank, set its bit to 1 to enable its ODT.
 */
#define DDRC_ODTMAP_rank0_wr_odt(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ODTMAP_rank0_wr_odt_SHIFT)) & DDRC_ODTMAP_rank0_wr_odt_MASK)

#define DDRC_ODTMAP_rank0_rd_odt_MASK            (0x30U)
#define DDRC_ODTMAP_rank0_rd_odt_SHIFT           (4U)
/*! rank0_rd_odt - Indicates which remote ODTs must be turned on during a read from rank 0. Each
 *    rank has a remote ODT (in the SDRAM) which can be turned on by setting the appropriate bit here.
 *    Rank 0 is controlled by the LSB; rank 1 is controlled by bit next to the LSB, etc. For each
 *    rank, set its bit to 1 to enable its ODT.
 */
#define DDRC_ODTMAP_rank0_rd_odt(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ODTMAP_rank0_rd_odt_SHIFT)) & DDRC_ODTMAP_rank0_rd_odt_MASK)

#define DDRC_ODTMAP_rank1_wr_odt_MASK            (0x300U)
#define DDRC_ODTMAP_rank1_wr_odt_SHIFT           (8U)
/*! rank1_wr_odt - Indicates which remote ODTs must be turned on during a write to rank 1. Each rank
 *    has a remote ODT (in the SDRAM) which can be turned on by setting the appropriate bit here.
 *    Rank 0 is controlled by the LSB; rank 1 is controlled by bit next to the LSB, etc. For each
 *    rank, set its bit to 1 to enable its ODT. Present only in configurations that have 2 or more ranks
 */
#define DDRC_ODTMAP_rank1_wr_odt(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ODTMAP_rank1_wr_odt_SHIFT)) & DDRC_ODTMAP_rank1_wr_odt_MASK)

#define DDRC_ODTMAP_rank1_rd_odt_MASK            (0x3000U)
#define DDRC_ODTMAP_rank1_rd_odt_SHIFT           (12U)
/*! rank1_rd_odt - Indicates which remote ODTs must be turned on during a read from rank 1. Each
 *    rank has a remote ODT (in the SDRAM) which can be turned on by setting the appropriate bit here.
 *    Rank 0 is controlled by the LSB; rank 1 is controlled by bit next to the LSB, etc. For each
 *    rank, set its bit to 1 to enable its ODT. Present only in configurations that have 2 or more
 *    ranks
 */
#define DDRC_ODTMAP_rank1_rd_odt(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_ODTMAP_rank1_rd_odt_SHIFT)) & DDRC_ODTMAP_rank1_rd_odt_MASK)
/*! @} */

/*! @name SCHED - Scheduler Control Register */
/*! @{ */

#define DDRC_SCHED_force_low_pri_n_MASK          (0x1U)
#define DDRC_SCHED_force_low_pri_n_SHIFT         (0U)
/*! force_low_pri_n - Active low signal. When asserted ('0'), all incoming transactions are forced
 *    to low priority. This implies that all High Priority Read (HPR) and Variable Priority Read
 *    commands (VPR) will be treated as Low Priority Read (LPR) commands. On the write side, all
 *    Variable Priority Write (VPW) commands will be treated as Normal Priority Write (NPW) commands.
 *    Forcing the incoming transactions to low priority implicitly turns off Bypass path for read
 *    commands. FOR PERFORMANCE ONLY.
 */
#define DDRC_SCHED_force_low_pri_n(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_SCHED_force_low_pri_n_SHIFT)) & DDRC_SCHED_force_low_pri_n_MASK)

#define DDRC_SCHED_prefer_write_MASK             (0x2U)
#define DDRC_SCHED_prefer_write_SHIFT            (1U)
/*! prefer_write - If set then the bank selector prefers writes over reads. FOR DEBUG ONLY. */
#define DDRC_SCHED_prefer_write(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_SCHED_prefer_write_SHIFT)) & DDRC_SCHED_prefer_write_MASK)

#define DDRC_SCHED_pageclose_MASK                (0x4U)
#define DDRC_SCHED_pageclose_SHIFT               (2U)
/*! pageclose - If true, bank is kept open only while there are page hit transactions available in
 *    the CAM to that bank. The last read or write command in the CAM with a bank and page hit will
 *    be executed with auto-precharge if SCHED1.pageclose_timer=0. Even if this register set to 1 and
 *    SCHED1.pageclose_timer is set to 0, explicit precharge (and not auto-precharge) may be issued
 *    in some cases where there is a mode switch between Write and Read or between LPR and HPR. The
 *    Read and Write commands that are executed as part of the ECC scrub requests are also executed
 *    without auto-precharge. If false, the bank remains open until there is a need to close it (to
 *    open a different page, or for page timeout or refresh timeout) - also known as open page
 *    policy. The open page policy can be overridden by setting the per-command-autopre bit on the HIF
 *    interface (hif_cmd_autopre). The pageclose feature provids a midway between Open and Close page
 *    policies. FOR PERFORMANCE ONLY.
 */
#define DDRC_SCHED_pageclose(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_SCHED_pageclose_SHIFT)) & DDRC_SCHED_pageclose_MASK)

#define DDRC_SCHED_lpr_num_entries_MASK          (0x1F00U)
#define DDRC_SCHED_lpr_num_entries_SHIFT         (8U)
/*! lpr_num_entries - Number of entries in the low priority transaction store is this value + 1.
 *    (MEMC_NO_OF_ENTRY - (SCHED.lpr_num_entries + 1)) is the number of entries available for the high
 *    priority transaction store. Setting this to maximum value allocates all entries to low
 *    priority transaction store. Setting this to 0 allocates 1 entry to low priority transaction store and
 *    the rest to high priority transaction store. Note: In ECC configurations, the numbers of
 *    write and low priority read credits issued is one less than in the non-ECC case. One entry each is
 *    reserved in the write and low-priority read CAMs for storing the RMW requests arising out of
 *    single bit error correction RMW operation.
 */
#define DDRC_SCHED_lpr_num_entries(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_SCHED_lpr_num_entries_SHIFT)) & DDRC_SCHED_lpr_num_entries_MASK)

#define DDRC_SCHED_go2critical_hysteresis_MASK   (0xFF0000U)
#define DDRC_SCHED_go2critical_hysteresis_SHIFT  (16U)
/*! go2critical_hysteresis - UNUSED */
#define DDRC_SCHED_go2critical_hysteresis(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_SCHED_go2critical_hysteresis_SHIFT)) & DDRC_SCHED_go2critical_hysteresis_MASK)

#define DDRC_SCHED_rdwr_idle_gap_MASK            (0x7F000000U)
#define DDRC_SCHED_rdwr_idle_gap_SHIFT           (24U)
/*! rdwr_idle_gap - When the preferred transaction store is empty for these many clock cycles,
 *    switch to the alternate transaction store if it is non-empty. The read transaction store (both high
 *    and low priority) is the default preferred transaction store and the write transaction store
 *    is the alternative store. When prefer write over read is set this is reversed. 0x0 is a legal
 *    value for this register. When set to 0x0, the transaction store switching will happen
 *    immediately when the switching conditions become true. FOR PERFORMANCE ONLY
 */
#define DDRC_SCHED_rdwr_idle_gap(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_SCHED_rdwr_idle_gap_SHIFT)) & DDRC_SCHED_rdwr_idle_gap_MASK)
/*! @} */

/*! @name SCHED1 - Scheduler Control Register 1 */
/*! @{ */

#define DDRC_SCHED1_pageclose_timer_MASK         (0xFFU)
#define DDRC_SCHED1_pageclose_timer_SHIFT        (0U)
/*! pageclose_timer - This field works in conjunction with SCHED.pageclose. It only has meaning if
 *    SCHED.pageclose==1. If SCHED.pageclose==1 and pageclose_timer==0, then an auto-precharge may be
 *    scheduled for last read or write command in the CAM with a bank and page hit. Note, sometimes
 *    an explicit precharge is scheduled instead of the auto-precharge. See SCHED.pageclose for
 *    details of when this may happen. If SCHED.pageclose==1 and pageclose_timer>0, then an
 *    auto-precharge is not scheduled for last read or write command in the CAM with a bank and page hit.
 *    Instead, a timer is started, with pageclose_timer as the initial value. There is a timer on a per
 *    bank basis. The timer decrements unless the next read or write in the CAM to a bank is a page
 *    hit. It gets reset to pageclose_timer value if the next read or write in the CAM to a bank is a
 *    page hit. Once the timer has reached zero, an explcit precharge will be attempted to be
 *    scheduled.
 */
#define DDRC_SCHED1_pageclose_timer(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_SCHED1_pageclose_timer_SHIFT)) & DDRC_SCHED1_pageclose_timer_MASK)
/*! @} */

/*! @name PERFHPR1 - High Priority Read CAM Register 1 */
/*! @{ */

#define DDRC_PERFHPR1_hpr_max_starve_MASK        (0xFFFFU)
#define DDRC_PERFHPR1_hpr_max_starve_SHIFT       (0U)
/*! hpr_max_starve - Number of DFI clocks that the HPR queue can be starved before it goes critical.
 *    The minimum valid functional value for this register is 0x1. Programming it to 0x0 will
 *    disable the starvation functionality; during normal operation, this function should not be disabled
 *    as it will cause excessive latencies. FOR PERFORMANCE ONLY.
 */
#define DDRC_PERFHPR1_hpr_max_starve(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_PERFHPR1_hpr_max_starve_SHIFT)) & DDRC_PERFHPR1_hpr_max_starve_MASK)

#define DDRC_PERFHPR1_hpr_xact_run_length_MASK   (0xFF000000U)
#define DDRC_PERFHPR1_hpr_xact_run_length_SHIFT  (24U)
/*! hpr_xact_run_length - Number of transactions that are serviced once the HPR queue goes critical
 *    is the smaller of: - (a) This number - (b) Number of transactions available. Unit:
 *    Transaction. FOR PERFORMANCE ONLY.
 */
#define DDRC_PERFHPR1_hpr_xact_run_length(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_PERFHPR1_hpr_xact_run_length_SHIFT)) & DDRC_PERFHPR1_hpr_xact_run_length_MASK)
/*! @} */

/*! @name PERFLPR1 - Low Priority Read CAM Register 1 */
/*! @{ */

#define DDRC_PERFLPR1_lpr_max_starve_MASK        (0xFFFFU)
#define DDRC_PERFLPR1_lpr_max_starve_SHIFT       (0U)
/*! lpr_max_starve - Number of DFI clocks that the LPR queue can be starved before it goes critical.
 *    The minimum valid functional value for this register is 0x1. Programming it to 0x0 will
 *    disable the starvation functionality; during normal operation, this function should not be disabled
 *    as it will cause excessive latencies. FOR PERFORMANCE ONLY.
 */
#define DDRC_PERFLPR1_lpr_max_starve(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_PERFLPR1_lpr_max_starve_SHIFT)) & DDRC_PERFLPR1_lpr_max_starve_MASK)

#define DDRC_PERFLPR1_lpr_xact_run_length_MASK   (0xFF000000U)
#define DDRC_PERFLPR1_lpr_xact_run_length_SHIFT  (24U)
/*! lpr_xact_run_length - Number of transactions that are serviced once the LPR queue goes critical
 *    is the smaller of: - (a) This number - (b) Number of transactions available. Unit:
 *    Transaction. FOR PERFORMANCE ONLY.
 */
#define DDRC_PERFLPR1_lpr_xact_run_length(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_PERFLPR1_lpr_xact_run_length_SHIFT)) & DDRC_PERFLPR1_lpr_xact_run_length_MASK)
/*! @} */

/*! @name PERFWR1 - Write CAM Register 1 */
/*! @{ */

#define DDRC_PERFWR1_w_max_starve_MASK           (0xFFFFU)
#define DDRC_PERFWR1_w_max_starve_SHIFT          (0U)
/*! w_max_starve - Number of DFI clocks that the WR queue can be starved before it goes critical.
 *    The minimum valid functional value for this register is 0x1. Programming it to 0x0 will disable
 *    the starvation functionality; during normal operation, this function should not be disabled as
 *    it will cause excessive latencies. FOR PERFORMANCE ONLY.
 */
#define DDRC_PERFWR1_w_max_starve(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_PERFWR1_w_max_starve_SHIFT)) & DDRC_PERFWR1_w_max_starve_MASK)

#define DDRC_PERFWR1_w_xact_run_length_MASK      (0xFF000000U)
#define DDRC_PERFWR1_w_xact_run_length_SHIFT     (24U)
/*! w_xact_run_length - Number of transactions that are serviced once the WR queue goes critical is
 *    the smaller of: - (a) This number - (b) Number of transactions available. Unit: Transaction.
 *    FOR PERFORMANCE ONLY.
 */
#define DDRC_PERFWR1_w_xact_run_length(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_PERFWR1_w_xact_run_length_SHIFT)) & DDRC_PERFWR1_w_xact_run_length_MASK)
/*! @} */

/*! @name DBG0 - Debug Register 0 */
/*! @{ */

#define DDRC_DBG0_dis_wc_MASK                    (0x1U)
#define DDRC_DBG0_dis_wc_SHIFT                   (0U)
/*! dis_wc - When 1, disable write combine. FOR DEBUG ONLY */
#define DDRC_DBG0_dis_wc(x)                      (((uint32_t)(((uint32_t)(x)) << DDRC_DBG0_dis_wc_SHIFT)) & DDRC_DBG0_dis_wc_MASK)

#define DDRC_DBG0_dis_rd_bypass_MASK             (0x2U)
#define DDRC_DBG0_dis_rd_bypass_SHIFT            (1U)
/*! dis_rd_bypass - Only present in designs supporting read bypass. When 1, disable bypass path for
 *    high priority read page hits FOR DEBUG ONLY.
 */
#define DDRC_DBG0_dis_rd_bypass(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_DBG0_dis_rd_bypass_SHIFT)) & DDRC_DBG0_dis_rd_bypass_MASK)

#define DDRC_DBG0_dis_act_bypass_MASK            (0x4U)
#define DDRC_DBG0_dis_act_bypass_SHIFT           (2U)
/*! dis_act_bypass - Only present in designs supporting activate bypass. When 1, disable bypass path
 *    for high priority read activates FOR DEBUG ONLY.
 */
#define DDRC_DBG0_dis_act_bypass(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_DBG0_dis_act_bypass_SHIFT)) & DDRC_DBG0_dis_act_bypass_MASK)

#define DDRC_DBG0_dis_collision_page_opt_MASK    (0x10U)
#define DDRC_DBG0_dis_collision_page_opt_SHIFT   (4U)
/*! dis_collision_page_opt - When this is set to '0', auto-precharge is disabled for the flushed
 *    command in a collision case. Collision cases are write followed by read to same address, read
 *    followed by write to same address, or write followed by write to same address with DBG0.dis_wc
 *    bit = 1 (where same address comparisons exclude the two address bits representing critical
 *    word). FOR DEBUG ONLY.
 */
#define DDRC_DBG0_dis_collision_page_opt(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_DBG0_dis_collision_page_opt_SHIFT)) & DDRC_DBG0_dis_collision_page_opt_MASK)
/*! @} */

/*! @name DBG1 - Debug Register 1 */
/*! @{ */

#define DDRC_DBG1_dis_dq_MASK                    (0x1U)
#define DDRC_DBG1_dis_dq_SHIFT                   (0U)
/*! dis_dq - When 1, DDRC will not de-queue any transactions from the CAM. Bypass is also disabled.
 *    All transactions are queued in the CAM. No reads or writes are issued to SDRAM as long as this
 *    is asserted. This bit may be used to prevent reads or writes being issued by the DDRC, which
 *    makes it safe to modify certain register fields associated with reads and writes (see User
 *    Guide for details). After setting this bit, it is strongly recommended to poll
 *    DBGCAM.wr_data_pipeline_empty and DBGCAM.rd_data_pipeline_empty, before making changes to any registers which
 *    affect reads and writes. This will ensure that the relevant logic in the DDRC is idle. This bit
 *    is intended to be switched on-the-fly.
 */
#define DDRC_DBG1_dis_dq(x)                      (((uint32_t)(((uint32_t)(x)) << DDRC_DBG1_dis_dq_SHIFT)) & DDRC_DBG1_dis_dq_MASK)

#define DDRC_DBG1_dis_hif_MASK                   (0x2U)
#define DDRC_DBG1_dis_hif_SHIFT                  (1U)
/*! dis_hif - When 1, DDRC asserts the HIF command signal hif_cmd_stall. DDRC will ignore the
 *    hif_cmd_valid and all other associated request signals. This bit is intended to be switched
 *    on-the-fly.
 */
#define DDRC_DBG1_dis_hif(x)                     (((uint32_t)(((uint32_t)(x)) << DDRC_DBG1_dis_hif_SHIFT)) & DDRC_DBG1_dis_hif_MASK)
/*! @} */

/*! @name DBGCAM - CAM Debug Register */
/*! @{ */

#define DDRC_DBGCAM_dbg_hpr_q_depth_MASK         (0x3FU)
#define DDRC_DBGCAM_dbg_hpr_q_depth_SHIFT        (0U)
/*! dbg_hpr_q_depth - High priority read queue depth FOR DEBUG ONLY */
#define DDRC_DBGCAM_dbg_hpr_q_depth(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DBGCAM_dbg_hpr_q_depth_SHIFT)) & DDRC_DBGCAM_dbg_hpr_q_depth_MASK)

#define DDRC_DBGCAM_dbg_lpr_q_depth_MASK         (0x3F00U)
#define DDRC_DBGCAM_dbg_lpr_q_depth_SHIFT        (8U)
/*! dbg_lpr_q_depth - Low priority read queue depth The last entry of Lpr queue is reserved for ECC
 *    SCRUB operation. This entry is not included in the calculation of the queue depth. FOR DEBUG
 *    ONLY
 */
#define DDRC_DBGCAM_dbg_lpr_q_depth(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DBGCAM_dbg_lpr_q_depth_SHIFT)) & DDRC_DBGCAM_dbg_lpr_q_depth_MASK)

#define DDRC_DBGCAM_dbg_w_q_depth_MASK           (0x3F0000U)
#define DDRC_DBGCAM_dbg_w_q_depth_SHIFT          (16U)
/*! dbg_w_q_depth - Write queue depth The last entry of WR queue is reserved for ECC SCRUB
 *    operation. This entry is not included in the calculation of the queue depth. FOR DEBUG ONLY
 */
#define DDRC_DBGCAM_dbg_w_q_depth(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DBGCAM_dbg_w_q_depth_SHIFT)) & DDRC_DBGCAM_dbg_w_q_depth_MASK)

#define DDRC_DBGCAM_dbg_stall_MASK               (0x1000000U)
#define DDRC_DBGCAM_dbg_stall_SHIFT              (24U)
/*! dbg_stall - Stall FOR DEBUG ONLY */
#define DDRC_DBGCAM_dbg_stall(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_DBGCAM_dbg_stall_SHIFT)) & DDRC_DBGCAM_dbg_stall_MASK)

#define DDRC_DBGCAM_dbg_rd_q_empty_MASK          (0x2000000U)
#define DDRC_DBGCAM_dbg_rd_q_empty_SHIFT         (25U)
/*! dbg_rd_q_empty - When 1, all the Read command queues and Read data buffers inside DDRC are
 *    empty. This register is to be used for debug purpose. An example use-case scenario: When Controller
 *    enters Self-Refresh using the Low-Power entry sequence, Controller is expected to have
 *    executed all the commands in its queues and the write and read data drained. Hence this register
 *    should be 1 at that time. FOR DEBUG ONLY
 */
#define DDRC_DBGCAM_dbg_rd_q_empty(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DBGCAM_dbg_rd_q_empty_SHIFT)) & DDRC_DBGCAM_dbg_rd_q_empty_MASK)

#define DDRC_DBGCAM_dbg_wr_q_empty_MASK          (0x4000000U)
#define DDRC_DBGCAM_dbg_wr_q_empty_SHIFT         (26U)
/*! dbg_wr_q_empty - When 1, all the Write command queues and Write data buffers inside DDRC are
 *    empty. This register is to be used for debug purpose. An example use-case scenario: When
 *    Controller enters Self-Refresh using the Low-Power entry sequence, Controller is expected to have
 *    executed all the commands in its queues and the write and read data drained. Hence this register
 *    should be 1 at that time. FOR DEBUG ONLY
 */
#define DDRC_DBGCAM_dbg_wr_q_empty(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DBGCAM_dbg_wr_q_empty_SHIFT)) & DDRC_DBGCAM_dbg_wr_q_empty_MASK)

#define DDRC_DBGCAM_rd_data_pipeline_empty_MASK  (0x10000000U)
#define DDRC_DBGCAM_rd_data_pipeline_empty_SHIFT (28U)
/*! rd_data_pipeline_empty - This bit indicates that the read data pipeline on the DFI interface is
 *    empty. This register is intended to be polled at least twice after setting DBG1.dis_dq, to
 *    ensure that all remaining commands/data have completed.
 */
#define DDRC_DBGCAM_rd_data_pipeline_empty(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_DBGCAM_rd_data_pipeline_empty_SHIFT)) & DDRC_DBGCAM_rd_data_pipeline_empty_MASK)

#define DDRC_DBGCAM_wr_data_pipeline_empty_MASK  (0x20000000U)
#define DDRC_DBGCAM_wr_data_pipeline_empty_SHIFT (29U)
/*! wr_data_pipeline_empty - This bit indicates that the write data pipeline on the DFI interface is
 *    empty. This register is intended to be polled at least twice after setting DBG1.dis_dq, to
 *    ensure that all remaining commands/data have completed.
 */
#define DDRC_DBGCAM_wr_data_pipeline_empty(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_DBGCAM_wr_data_pipeline_empty_SHIFT)) & DDRC_DBGCAM_wr_data_pipeline_empty_MASK)

#define DDRC_DBGCAM_dbg_stall_wr_MASK            (0x40000000U)
#define DDRC_DBGCAM_dbg_stall_wr_SHIFT           (30U)
/*! dbg_stall_wr - Stall for Write channel FOR DEBUG ONLY */
#define DDRC_DBGCAM_dbg_stall_wr(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_DBGCAM_dbg_stall_wr_SHIFT)) & DDRC_DBGCAM_dbg_stall_wr_MASK)

#define DDRC_DBGCAM_dbg_stall_rd_MASK            (0x80000000U)
#define DDRC_DBGCAM_dbg_stall_rd_SHIFT           (31U)
/*! dbg_stall_rd - Stall for Read channel FOR DEBUG ONLY */
#define DDRC_DBGCAM_dbg_stall_rd(x)              (((uint32_t)(((uint32_t)(x)) << DDRC_DBGCAM_dbg_stall_rd_SHIFT)) & DDRC_DBGCAM_dbg_stall_rd_MASK)
/*! @} */

/*! @name DBGCMD - Command Debug Register */
/*! @{ */

#define DDRC_DBGCMD_rank0_refresh_MASK           (0x1U)
#define DDRC_DBGCMD_rank0_refresh_SHIFT          (0U)
/*! rank0_refresh - Setting this register bit to 1 indicates to the DDRC to issue a refresh to rank
 *    0. Writing to this bit causes DBGSTAT.rank0_refresh_busy to be set. When
 *    DBGSTAT.rank0_refresh_busy is cleared, the command has been stored in DDRC. For 3DS configuration, refresh is sent
 *    to rank index 0. This operation can be performed only when RFSHCTL3.dis_auto_refresh=1. It is
 *    recommended NOT to set this register bit if in Init or Deep power-down operating modes or
 *    Maximum Power Saving Mode.
 */
#define DDRC_DBGCMD_rank0_refresh(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DBGCMD_rank0_refresh_SHIFT)) & DDRC_DBGCMD_rank0_refresh_MASK)

#define DDRC_DBGCMD_rank1_refresh_MASK           (0x2U)
#define DDRC_DBGCMD_rank1_refresh_SHIFT          (1U)
/*! rank1_refresh - Setting this register bit to 1 indicates to the DDRC to issue a refresh to rank
 *    1. Writing to this bit causes DBGSTAT.rank1_refresh_busy to be set. When
 *    DBGSTAT.rank1_refresh_busy is cleared, the command has been stored in DDRC. For 3DS configuration, refresh is sent
 *    to rank index 1. This operation can be performed only when RFSHCTL3.dis_auto_refresh=1. It is
 *    recommended NOT to set this register bit if in Init or Deep power-down operating modes or
 *    Maximum Power Saving Mode.
 */
#define DDRC_DBGCMD_rank1_refresh(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DBGCMD_rank1_refresh_SHIFT)) & DDRC_DBGCMD_rank1_refresh_MASK)

#define DDRC_DBGCMD_zq_calib_short_MASK          (0x10U)
#define DDRC_DBGCMD_zq_calib_short_SHIFT         (4U)
/*! zq_calib_short - Setting this register bit to 1 indicates to the DDRC to issue a ZQCS (ZQ
 *    calibration short)/MPC(ZQ calibration) command to the SDRAM. When this request is stored in the
 *    DDRC, the bit is automatically cleared. This operation can be performed only when
 *    ZQCTL0.dis_auto_zq=1. It is recommended NOT to set this register bit if in Init operating mode. This register
 *    bit is ignored when in Self-Refresh(except LPDDR4) and SR-Powerdown(LPDDR4) and Deep
 *    power-down operating modes and Maximum Power Saving Mode.
 */
#define DDRC_DBGCMD_zq_calib_short(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DBGCMD_zq_calib_short_SHIFT)) & DDRC_DBGCMD_zq_calib_short_MASK)

#define DDRC_DBGCMD_ctrlupd_MASK                 (0x20U)
#define DDRC_DBGCMD_ctrlupd_SHIFT                (5U)
/*! ctrlupd - Setting this register bit to 1 indicates to the DDRC to issue a dfi_ctrlupd_req to the
 *    PHY. When this request is stored in the DDRC, the bit is automatically cleared. This
 *    operation must only be performed when DFIUPD0.dis_auto_ctrlupd=1.
 */
#define DDRC_DBGCMD_ctrlupd(x)                   (((uint32_t)(((uint32_t)(x)) << DDRC_DBGCMD_ctrlupd_SHIFT)) & DDRC_DBGCMD_ctrlupd_MASK)
/*! @} */

/*! @name DBGSTAT - Status Debug Register */
/*! @{ */

#define DDRC_DBGSTAT_rank0_refresh_busy_MASK     (0x1U)
#define DDRC_DBGSTAT_rank0_refresh_busy_SHIFT    (0U)
/*! rank0_refresh_busy - SoC core may initiate a rank0_refresh operation (refresh operation to rank
 *    0) only if this signal is low. This signal goes high in the clock after DBGCMD.rank0_refresh
 *    is set to one. It goes low when the rank0_refresh operation is stored in the DDRC. It is
 *    recommended not to perform rank0_refresh operations when this signal is high. - 0 - Indicates that
 *    the SoC core can initiate a rank0_refresh operation - 1 - Indicates that rank0_refresh
 *    operation has not been stored yet in the DDRC
 */
#define DDRC_DBGSTAT_rank0_refresh_busy(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DBGSTAT_rank0_refresh_busy_SHIFT)) & DDRC_DBGSTAT_rank0_refresh_busy_MASK)

#define DDRC_DBGSTAT_rank1_refresh_busy_MASK     (0x2U)
#define DDRC_DBGSTAT_rank1_refresh_busy_SHIFT    (1U)
/*! rank1_refresh_busy - SoC core may initiate a rank1_refresh operation (refresh operation to rank
 *    1) only if this signal is low. This signal goes high in the clock after DBGCMD.rank1_refresh
 *    is set to one. It goes low when the rank1_refresh operation is stored in the DDRC. It is
 *    recommended not to perform rank1_refresh operations when this signal is high. - 0 - Indicates that
 *    the SoC core can initiate a rank1_refresh operation - 1 - Indicates that rank1_refresh
 *    operation has not been stored yet in the DDRC
 */
#define DDRC_DBGSTAT_rank1_refresh_busy(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DBGSTAT_rank1_refresh_busy_SHIFT)) & DDRC_DBGSTAT_rank1_refresh_busy_MASK)

#define DDRC_DBGSTAT_zq_calib_short_busy_MASK    (0x10U)
#define DDRC_DBGSTAT_zq_calib_short_busy_SHIFT   (4U)
/*! zq_calib_short_busy - SoC core may initiate a ZQCS (ZQ calibration short) operation only if this
 *    signal is low. This signal goes high in the clock after the DDRC accepts the ZQCS request. It
 *    goes low when the ZQCS operation is initiated in the DDRC. It is recommended not to perform
 *    ZQCS operations when this signal is high. - 0 - Indicates that the SoC core can initiate a ZQCS
 *    operation - 1 - Indicates that ZQCS operation has not been initiated yet in the DDRC
 */
#define DDRC_DBGSTAT_zq_calib_short_busy(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_DBGSTAT_zq_calib_short_busy_SHIFT)) & DDRC_DBGSTAT_zq_calib_short_busy_MASK)

#define DDRC_DBGSTAT_ctrlupd_busy_MASK           (0x20U)
#define DDRC_DBGSTAT_ctrlupd_busy_SHIFT          (5U)
/*! ctrlupd_busy - SoC core may initiate a ctrlupd operation only if this signal is low. This signal
 *    goes high in the clock after the DDRC accepts the ctrlupd request. It goes low when the
 *    ctrlupd operation is initiated in the DDRC. It is recommended not to perform ctrlupd operations
 *    when this signal is high. - 0 - Indicates that the SoC core can initiate a ctrlupd operation - 1
 *    - Indicates that ctrlupd operation has not been initiated yet in the DDRC
 */
#define DDRC_DBGSTAT_ctrlupd_busy(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DBGSTAT_ctrlupd_busy_SHIFT)) & DDRC_DBGSTAT_ctrlupd_busy_MASK)
/*! @} */

/*! @name SWCTL - Software Register Programming Control Enable */
/*! @{ */

#define DDRC_SWCTL_sw_done_MASK                  (0x1U)
#define DDRC_SWCTL_sw_done_SHIFT                 (0U)
/*! sw_done - Enable quasi-dynamic register programming outside reset. Program register to 0 to
 *    enable quasi-dynamic programming. Set back register to 1 once programming is done.
 */
#define DDRC_SWCTL_sw_done(x)                    (((uint32_t)(((uint32_t)(x)) << DDRC_SWCTL_sw_done_SHIFT)) & DDRC_SWCTL_sw_done_MASK)
/*! @} */

/*! @name SWSTAT - Software Register Programming Control Status */
/*! @{ */

#define DDRC_SWSTAT_sw_done_ack_MASK             (0x1U)
#define DDRC_SWSTAT_sw_done_ack_SHIFT            (0U)
/*! sw_done_ack - Register programming done. This register is the echo of SWCTL.sw_done. Wait for
 *    sw_done value 1 to propagate to sw_done_ack at the end of the programming sequence to ensure
 *    that the correct registers values are propagated to the destination clock domains.
 */
#define DDRC_SWSTAT_sw_done_ack(x)               (((uint32_t)(((uint32_t)(x)) << DDRC_SWSTAT_sw_done_ack_SHIFT)) & DDRC_SWSTAT_sw_done_ack_MASK)
/*! @} */

/*! @name POISONCFG - AXI Poison Configuration Register. */
/*! @{ */

#define DDRC_POISONCFG_wr_poison_slverr_en_MASK  (0x1U)
#define DDRC_POISONCFG_wr_poison_slverr_en_SHIFT (0U)
/*! wr_poison_slverr_en - If set to 1, enables SLVERR response for write transaction poisoning */
#define DDRC_POISONCFG_wr_poison_slverr_en(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_POISONCFG_wr_poison_slverr_en_SHIFT)) & DDRC_POISONCFG_wr_poison_slverr_en_MASK)

#define DDRC_POISONCFG_wr_poison_intr_en_MASK    (0x10U)
#define DDRC_POISONCFG_wr_poison_intr_en_SHIFT   (4U)
/*! wr_poison_intr_en - If set to 1, enables interrupts for write transaction poisoning */
#define DDRC_POISONCFG_wr_poison_intr_en(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_POISONCFG_wr_poison_intr_en_SHIFT)) & DDRC_POISONCFG_wr_poison_intr_en_MASK)

#define DDRC_POISONCFG_wr_poison_intr_clr_MASK   (0x100U)
#define DDRC_POISONCFG_wr_poison_intr_clr_SHIFT  (8U)
/*! wr_poison_intr_clr - Interrupt clear for write transaction poisoning. Allow 2/3 clock cycles for
 *    correct value to propagate to core logic and clear the interrupts.
 */
#define DDRC_POISONCFG_wr_poison_intr_clr(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_POISONCFG_wr_poison_intr_clr_SHIFT)) & DDRC_POISONCFG_wr_poison_intr_clr_MASK)

#define DDRC_POISONCFG_rd_poison_slverr_en_MASK  (0x10000U)
#define DDRC_POISONCFG_rd_poison_slverr_en_SHIFT (16U)
/*! rd_poison_slverr_en - If set to 1, enables SLVERR response for read transaction poisoning */
#define DDRC_POISONCFG_rd_poison_slverr_en(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_POISONCFG_rd_poison_slverr_en_SHIFT)) & DDRC_POISONCFG_rd_poison_slverr_en_MASK)

#define DDRC_POISONCFG_rd_poison_intr_en_MASK    (0x100000U)
#define DDRC_POISONCFG_rd_poison_intr_en_SHIFT   (20U)
/*! rd_poison_intr_en - If set to 1, enables interrupts for read transaction poisoning */
#define DDRC_POISONCFG_rd_poison_intr_en(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_POISONCFG_rd_poison_intr_en_SHIFT)) & DDRC_POISONCFG_rd_poison_intr_en_MASK)

#define DDRC_POISONCFG_rd_poison_intr_clr_MASK   (0x1000000U)
#define DDRC_POISONCFG_rd_poison_intr_clr_SHIFT  (24U)
/*! rd_poison_intr_clr - Interrupt clear for read transaction poisoning. Allow 2/3 clock cycles for
 *    correct value to propagate to core logic and clear the interrupts.
 */
#define DDRC_POISONCFG_rd_poison_intr_clr(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_POISONCFG_rd_poison_intr_clr_SHIFT)) & DDRC_POISONCFG_rd_poison_intr_clr_MASK)
/*! @} */

/*! @name POISONSTAT - AXI Poison Status Register */
/*! @{ */

#define DDRC_POISONSTAT_wr_poison_intr_0_MASK    (0x1U)
#define DDRC_POISONSTAT_wr_poison_intr_0_SHIFT   (0U)
/*! wr_poison_intr_0 - Write transaction poisoning error interrupt for port 0. This register is a
 *    APB clock copy (double register synchronizer) of the interrupt asserted when a transaction is
 *    poisoned on the corresponding AXI port's write address channel. Bit 0 corresponds to Port 0, and
 *    so on. Interrupt is cleared by register wr_poison_intr_clr, then value propagated to APB
 *    clock.
 */
#define DDRC_POISONSTAT_wr_poison_intr_0(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_POISONSTAT_wr_poison_intr_0_SHIFT)) & DDRC_POISONSTAT_wr_poison_intr_0_MASK)

#define DDRC_POISONSTAT_rd_poison_intr_0_MASK    (0x10000U)
#define DDRC_POISONSTAT_rd_poison_intr_0_SHIFT   (16U)
/*! rd_poison_intr_0 - Read transaction poisoning error interrupt for port 0. This register is a APB
 *    clock copy (double register synchronizer) of the interrupt asserted when a transaction is
 *    poisoned on the corresponding AXI port's read address channel. Bit 0 corresponds to Port 0, and
 *    so on. Interrupt is cleared by register rd_poison_intr_clr, then value propagated to APB clock.
 */
#define DDRC_POISONSTAT_rd_poison_intr_0(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_POISONSTAT_rd_poison_intr_0_SHIFT)) & DDRC_POISONSTAT_rd_poison_intr_0_MASK)
/*! @} */

/*! @name PSTAT - Port Status Register */
/*! @{ */

#define DDRC_PSTAT_rd_port_busy_0_MASK           (0x1U)
#define DDRC_PSTAT_rd_port_busy_0_SHIFT          (0U)
/*! rd_port_busy_0 - Indicates if there are outstanding reads for AXI port 0. */
#define DDRC_PSTAT_rd_port_busy_0(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_PSTAT_rd_port_busy_0_SHIFT)) & DDRC_PSTAT_rd_port_busy_0_MASK)

#define DDRC_PSTAT_wr_port_busy_0_MASK           (0x10000U)
#define DDRC_PSTAT_wr_port_busy_0_SHIFT          (16U)
/*! wr_port_busy_0 - Indicates if there are outstanding writes for AXI port 0. */
#define DDRC_PSTAT_wr_port_busy_0(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_PSTAT_wr_port_busy_0_SHIFT)) & DDRC_PSTAT_wr_port_busy_0_MASK)
/*! @} */

/*! @name PCCFG - Port Common Configuration Register */
/*! @{ */

#define DDRC_PCCFG_go2critical_en_MASK           (0x1U)
#define DDRC_PCCFG_go2critical_en_SHIFT          (0U)
/*! go2critical_en - If set to 1 (enabled), sets co_gs_go2critical_wr and
 *    co_gs_go2critical_lpr/co_gs_go2critical_hpr signals going to DDRC based on urgent input (awurgent, arurgent) coming from
 *    AXI master. If set to 0 (disabled), co_gs_go2critical_wr and
 *    co_gs_go2critical_lpr/co_gs_go2critical_hpr signals at DDRC are driven to 1b'0.
 */
#define DDRC_PCCFG_go2critical_en(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_PCCFG_go2critical_en_SHIFT)) & DDRC_PCCFG_go2critical_en_MASK)

#define DDRC_PCCFG_pagematch_limit_MASK          (0x10U)
#define DDRC_PCCFG_pagematch_limit_SHIFT         (4U)
/*! pagematch_limit - Page match four limit. If set to 1, limits the number of consecutive same page
 *    DDRC transactions that can be granted by the Port Arbiter to four when Page Match feature is
 *    enabled. If set to 0, there is no limit imposed on number of consecutive same page DDRC
 *    transactions.
 */
#define DDRC_PCCFG_pagematch_limit(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_PCCFG_pagematch_limit_SHIFT)) & DDRC_PCCFG_pagematch_limit_MASK)

#define DDRC_PCCFG_bl_exp_mode_MASK              (0x100U)
#define DDRC_PCCFG_bl_exp_mode_SHIFT             (8U)
/*! bl_exp_mode - Burst length expansion mode. By default (i.e. bl_exp_mode==0) XPI expands every
 *    AXI burst into multiple HIF commands, using the memory burst length as a unit. If set to 1, then
 *    XPI will use half of the memory burst length as a unit. This applies to both reads and
 *    writes. When MSTR.data_bus_width==00, setting bl_exp_mode to 1 has no effect. This can be used in
 *    cases where Partial Writes is enabled (DDRC_PARTIAL_WR=1), in order to avoid or minimize t_ccd_l
 *    penalty in DDR4 and t_ccd_mw penalty in LPDDR4. Hence, bl_exp_mode=1 is only recommended if
 *    DDR4 or LPDDR4. Note that if DBICTL.reg_ddrc_dm_en=0, functionality is not supported in the
 *    following cases: - DDRC_PARTIAL_WR=0 - DDRC_PARTIAL_WR=1, MSTR.data_bus_width=01,
 *    MEMC_BURST_LENGTH=8 and MSTR.burst_rdwr=1000 (LPDDR4 only) - DDRC_PARTIAL_WR=1, MSTR.data_bus_width=01,
 *    MEMC_BURST_LENGTH=4 and MSTR.burst_rdwr=0100 (DDR4 only), with either MSTR.reg_ddrc_burstchop=0 or
 *    CRCPARCTL1.reg_ddrc_crc_enable=1 Functionality is also not supported if Data Channel
 *    Interleave is enabled
 */
#define DDRC_PCCFG_bl_exp_mode(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_PCCFG_bl_exp_mode_SHIFT)) & DDRC_PCCFG_bl_exp_mode_MASK)
/*! @} */

/*! @name PCFGR_0 - Port n Configuration Read Register */
/*! @{ */

#define DDRC_PCFGR_0_rd_port_priority_MASK       (0x3FFU)
#define DDRC_PCFGR_0_rd_port_priority_SHIFT      (0U)
/*! rd_port_priority - Determines the initial load value of read aging counters. These counters will
 *    be parallel loaded after reset, or after each grant to the corresponding port. The aging
 *    counters down-count every clock cycle where the port is requesting but not granted. The higher
 *    significant 5-bits of the read aging counter sets the priority of the read channel of a given
 *    port. Port's priority will increase as the higher significant 5-bits of the counter starts to
 *    decrease. When the aging counter becomes 0, the corresponding port channel will have the highest
 *    priority level (timeout condition - Priority0). For multi-port configurations, the aging
 *    counters cannot be used to set port priorities when external dynamic priority inputs (arqos) are
 *    enabled (timeout is still applicable). For single port configurations, the aging counters are
 *    only used when they timeout (become 0) to force read-write direction switching. In this case,
 *    external dynamic priority input, arqos (for reads only) can still be used to set the DDRC read
 *    priority (2 priority levels: low priority read - LPR, high priority read - HPR) on a command by
 *    command basis. Note: The two LSBs of this register field are tied internally to 2'b00.
 */
#define DDRC_PCFGR_0_rd_port_priority(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGR_0_rd_port_priority_SHIFT)) & DDRC_PCFGR_0_rd_port_priority_MASK)

#define DDRC_PCFGR_0_rd_port_aging_en_MASK       (0x1000U)
#define DDRC_PCFGR_0_rd_port_aging_en_SHIFT      (12U)
/*! rd_port_aging_en - If set to 1, enables aging function for the read channel of the port. */
#define DDRC_PCFGR_0_rd_port_aging_en(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGR_0_rd_port_aging_en_SHIFT)) & DDRC_PCFGR_0_rd_port_aging_en_MASK)

#define DDRC_PCFGR_0_rd_port_urgent_en_MASK      (0x2000U)
#define DDRC_PCFGR_0_rd_port_urgent_en_SHIFT     (13U)
/*! rd_port_urgent_en - If set to 1, enables the AXI urgent sideband signal (arurgent). When enabled
 *    and arurgent is asserted by the master, that port becomes the highest priority and
 *    co_gs_go2critical_lpr/co_gs_go2critical_hpr signal to DDRC is asserted if enabled in
 *    PCCFG.go2critical_en register. Note that arurgent signal can be asserted anytime and as long as required which is
 *    independent of address handshaking (it is not associated with any particular command).
 */
#define DDRC_PCFGR_0_rd_port_urgent_en(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGR_0_rd_port_urgent_en_SHIFT)) & DDRC_PCFGR_0_rd_port_urgent_en_MASK)

#define DDRC_PCFGR_0_rd_port_pagematch_en_MASK   (0x4000U)
#define DDRC_PCFGR_0_rd_port_pagematch_en_SHIFT  (14U)
/*! rd_port_pagematch_en - If set to 1, enables the Page Match feature. If enabled, once a
 *    requesting port is granted, the port is continued to be granted if the following immediate commands are
 *    to the same memory page (same bank and same row). See also related PCCFG.pagematch_limit
 *    register.
 */
#define DDRC_PCFGR_0_rd_port_pagematch_en(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGR_0_rd_port_pagematch_en_SHIFT)) & DDRC_PCFGR_0_rd_port_pagematch_en_MASK)

#define DDRC_PCFGR_0_rdwr_ordered_en_MASK        (0x10000U)
#define DDRC_PCFGR_0_rdwr_ordered_en_SHIFT       (16U)
/*! rdwr_ordered_en - Enable ordered read/writes. If set to 1, preserves the ordering between read
 *    transaction and write transaction issued to the same address, on a given port. In other words,
 *    the controller ensures that all same address read and write commands from the application port
 *    interface are transported to the DFI interface in the order of acceptance. This feature is
 *    useful in cases where software coherency is desired for masters issuing back-to-back read/write
 *    transactions without waiting for write/read responses. Note that this register has an effect
 *    only if necessary logic is instantiated via the DDRC_RDWR_ORDERED_n parameter.
 */
#define DDRC_PCFGR_0_rdwr_ordered_en(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGR_0_rdwr_ordered_en_SHIFT)) & DDRC_PCFGR_0_rdwr_ordered_en_MASK)
/*! @} */

/*! @name PCFGW_0 - Port n Configuration Write Register */
/*! @{ */

#define DDRC_PCFGW_0_wr_port_priority_MASK       (0x3FFU)
#define DDRC_PCFGW_0_wr_port_priority_SHIFT      (0U)
/*! wr_port_priority - Determines the initial load value of write aging counters. These counters
 *    will be parallel loaded after reset, or after each grant to the corresponding port. The aging
 *    counters down-count every clock cycle where the port is requesting but not granted. The higher
 *    significant 5-bits of the write aging counter sets the initial priority of the write channel of
 *    a given port. Port's priority will increase as the higher significant 5-bits of the counter
 *    starts to decrease. When the aging counter becomes 0, the corresponding port channel will have
 *    the highest priority level. For multi-port configurations, the aging counters cannot be used to
 *    set port priorities when external dynamic priority inputs (awqos) are enabled (timeout is
 *    still applicable). For single port configurations, the aging counters are only used when they
 *    timeout (become 0) to force read-write direction switching. Note: The two LSBs of this register
 *    field are tied internally to 2'b00.
 */
#define DDRC_PCFGW_0_wr_port_priority(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGW_0_wr_port_priority_SHIFT)) & DDRC_PCFGW_0_wr_port_priority_MASK)

#define DDRC_PCFGW_0_wr_port_aging_en_MASK       (0x1000U)
#define DDRC_PCFGW_0_wr_port_aging_en_SHIFT      (12U)
/*! wr_port_aging_en - If set to 1, enables aging function for the write channel of the port. */
#define DDRC_PCFGW_0_wr_port_aging_en(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGW_0_wr_port_aging_en_SHIFT)) & DDRC_PCFGW_0_wr_port_aging_en_MASK)

#define DDRC_PCFGW_0_wr_port_urgent_en_MASK      (0x2000U)
#define DDRC_PCFGW_0_wr_port_urgent_en_SHIFT     (13U)
/*! wr_port_urgent_en - If set to 1, enables the AXI urgent sideband signal (awurgent). When enabled
 *    and awurgent is asserted by the master, that port becomes the highest priority and
 *    co_gs_go2critical_wr signal to DDRC is asserted if enabled in PCCFG.go2critical_en register. Note that
 *    awurgent signal can be asserted anytime and as long as required which is independent of address
 *    handshaking (it is not associated with any particular command).
 */
#define DDRC_PCFGW_0_wr_port_urgent_en(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGW_0_wr_port_urgent_en_SHIFT)) & DDRC_PCFGW_0_wr_port_urgent_en_MASK)

#define DDRC_PCFGW_0_wr_port_pagematch_en_MASK   (0x4000U)
#define DDRC_PCFGW_0_wr_port_pagematch_en_SHIFT  (14U)
/*! wr_port_pagematch_en - If set to 1, enables the Page Match feature. If enabled, once a
 *    requesting port is granted, the port is continued to be granted if the following immediate commands are
 *    to the same memory page (same bank and same row). See also related PCCFG.pagematch_limit
 *    register.
 */
#define DDRC_PCFGW_0_wr_port_pagematch_en(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGW_0_wr_port_pagematch_en_SHIFT)) & DDRC_PCFGW_0_wr_port_pagematch_en_MASK)
/*! @} */

/*! @name PCTRL_0 - Port n Control Register */
/*! @{ */

#define DDRC_PCTRL_0_port_en_MASK                (0x1U)
#define DDRC_PCTRL_0_port_en_SHIFT               (0U)
/*! port_en - Enables AXI port n. */
#define DDRC_PCTRL_0_port_en(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_PCTRL_0_port_en_SHIFT)) & DDRC_PCTRL_0_port_en_MASK)
/*! @} */

/*! @name PCFGQOS0_0 - Port n Read QoS Configuration Register 0 */
/*! @{ */

#define DDRC_PCFGQOS0_0_rqos_map_level1_MASK     (0xFU)
#define DDRC_PCFGQOS0_0_rqos_map_level1_SHIFT    (0U)
/*! rqos_map_level1 - Separation level1 indicating the end of region0 mapping; start of region0 is
 *    0. Possible values for level1 are 0 to 13 (for dual RAQ) or 0 to 14 (for single RAQ) which
 *    corresponds to arqos. Note that for PA, arqos values are used directly as port priorities, where
 *    the higher the value corresponds to higher port priority. All of the map_level* registers must
 *    be set to distinct values.
 */
#define DDRC_PCFGQOS0_0_rqos_map_level1(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGQOS0_0_rqos_map_level1_SHIFT)) & DDRC_PCFGQOS0_0_rqos_map_level1_MASK)

#define DDRC_PCFGQOS0_0_rqos_map_region0_MASK    (0x30000U)
#define DDRC_PCFGQOS0_0_rqos_map_region0_SHIFT   (16U)
/*! rqos_map_region0 - This bitfield indicates the traffic class of region 0. Valid values are: 0:
 *    LPR, 1: VPR, 2: HPR. For dual address queue configurations, region 0 maps to the blue address
 *    queue. In this case, valid values are: 0: LPR and 1: VPR only. When VPR support is disabled
 *    (DDRC_VPR_EN = 0) and traffic class of region0 is set to 1 (VPR), VPR traffic is aliased to LPR
 *    traffic.
 */
#define DDRC_PCFGQOS0_0_rqos_map_region0(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGQOS0_0_rqos_map_region0_SHIFT)) & DDRC_PCFGQOS0_0_rqos_map_region0_MASK)

#define DDRC_PCFGQOS0_0_rqos_map_region1_MASK    (0x300000U)
#define DDRC_PCFGQOS0_0_rqos_map_region1_SHIFT   (20U)
/*! rqos_map_region1 - This bitfield indicates the traffic class of region 1. Valid values are: 0 :
 *    LPR, 1: VPR, 2: HPR. For dual address queue configurations, region1 maps to the blue address
 *    queue. In this case, valid values are 0: LPR and 1: VPR only. When VPR support is disabled
 *    (DDRC_VPR_EN = 0) and traffic class of region 1 is set to 1 (VPR), VPR traffic is aliased to LPR
 *    traffic.
 */
#define DDRC_PCFGQOS0_0_rqos_map_region1(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGQOS0_0_rqos_map_region1_SHIFT)) & DDRC_PCFGQOS0_0_rqos_map_region1_MASK)
/*! @} */

/*! @name PCFGQOS1_0 - Port n Read QoS Configuration Register 1 */
/*! @{ */

#define DDRC_PCFGQOS1_0_rqos_map_timeoutb_MASK   (0x7FFU)
#define DDRC_PCFGQOS1_0_rqos_map_timeoutb_SHIFT  (0U)
/*! rqos_map_timeoutb - Specifies the timeout value for transactions mapped to the blue address queue. */
#define DDRC_PCFGQOS1_0_rqos_map_timeoutb(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGQOS1_0_rqos_map_timeoutb_SHIFT)) & DDRC_PCFGQOS1_0_rqos_map_timeoutb_MASK)

#define DDRC_PCFGQOS1_0_rqos_map_timeoutr_MASK   (0x7FF0000U)
#define DDRC_PCFGQOS1_0_rqos_map_timeoutr_SHIFT  (16U)
/*! rqos_map_timeoutr - Specifies the timeout value for transactions mapped to the red address queue. */
#define DDRC_PCFGQOS1_0_rqos_map_timeoutr(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGQOS1_0_rqos_map_timeoutr_SHIFT)) & DDRC_PCFGQOS1_0_rqos_map_timeoutr_MASK)
/*! @} */

/*! @name PCFGWQOS0_0 - Port n Write QoS Configuration Register 0 */
/*! @{ */

#define DDRC_PCFGWQOS0_0_wqos_map_level_MASK     (0xFU)
#define DDRC_PCFGWQOS0_0_wqos_map_level_SHIFT    (0U)
/*! wqos_map_level - Separation level indicating the end of region0 mapping; start of region0 is 0.
 *    Possible values for level1 are 0 to 14 which corresponds to awqos. Note that for PA, awqos
 *    values are used directly as port priorities, where the higher the value corresponds to higher
 *    port priority.
 */
#define DDRC_PCFGWQOS0_0_wqos_map_level(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGWQOS0_0_wqos_map_level_SHIFT)) & DDRC_PCFGWQOS0_0_wqos_map_level_MASK)

#define DDRC_PCFGWQOS0_0_wqos_map_region0_MASK   (0x30000U)
#define DDRC_PCFGWQOS0_0_wqos_map_region0_SHIFT  (16U)
/*! wqos_map_region0 - This bitfield indicates the traffic class of region 0. Valid values are: 0:
 *    NPW, 1: VPW. When VPW support is disabled (DDRC_VPW_EN = 0) and traffic class of region0 is set
 *    to 1 (VPW), VPW traffic is aliased to NPW traffic.
 */
#define DDRC_PCFGWQOS0_0_wqos_map_region0(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGWQOS0_0_wqos_map_region0_SHIFT)) & DDRC_PCFGWQOS0_0_wqos_map_region0_MASK)

#define DDRC_PCFGWQOS0_0_wqos_map_region1_MASK   (0x300000U)
#define DDRC_PCFGWQOS0_0_wqos_map_region1_SHIFT  (20U)
/*! wqos_map_region1 - This bitfield indicates the traffic class of region 1. Valid values are: 0:
 *    NPW, 1: VPW. When VPW support is disabled (DDRC_VPW_EN = 0) and traffic class of region 1 is
 *    set to 1 (VPW), VPW traffic is aliased to LPW traffic.
 */
#define DDRC_PCFGWQOS0_0_wqos_map_region1(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGWQOS0_0_wqos_map_region1_SHIFT)) & DDRC_PCFGWQOS0_0_wqos_map_region1_MASK)
/*! @} */

/*! @name PCFGWQOS1_0 - Port n Write QoS Configuration Register 1 */
/*! @{ */

#define DDRC_PCFGWQOS1_0_wqos_map_timeout_MASK   (0x7FFU)
#define DDRC_PCFGWQOS1_0_wqos_map_timeout_SHIFT  (0U)
/*! wqos_map_timeout - Specifies the timeout value for write transactions. */
#define DDRC_PCFGWQOS1_0_wqos_map_timeout(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_PCFGWQOS1_0_wqos_map_timeout_SHIFT)) & DDRC_PCFGWQOS1_0_wqos_map_timeout_MASK)
/*! @} */

/*! @name DERATEEN_SHADOW - [SHADOW] Temperature Derate Enable Register */
/*! @{ */

#define DDRC_DERATEEN_SHADOW_derate_enable_MASK  (0x1U)
#define DDRC_DERATEEN_SHADOW_derate_enable_SHIFT (0U)
/*! derate_enable - Enables derating - 0 - Timing parameter derating is disabled - 1 - Timing
 *    parameter derating is enabled using MR4 read value. Present only in designs configured to support
 *    LPDDR2/LPDDR3/LPDDR4 This field must be set to '0' for non-LPDDR2/LPDDR3/LPDDR4 mode.
 */
#define DDRC_DERATEEN_SHADOW_derate_enable(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_DERATEEN_SHADOW_derate_enable_SHIFT)) & DDRC_DERATEEN_SHADOW_derate_enable_MASK)

#define DDRC_DERATEEN_SHADOW_derate_value_MASK   (0x2U)
#define DDRC_DERATEEN_SHADOW_derate_value_SHIFT  (1U)
/*! derate_value - Derate value - 0 - Derating uses +1. - 1 - Derating uses +2. Present only in
 *    designs configured to support LPDDR2/LPDDR3/LPDDR4 Set to 0 for all LPDDR2 speed grades as
 *    derating value of +1.875 ns is less than a core_ddrc_core_clk period. For LPDDR3/4, if the period of
 *    core_ddrc_core_clk is less than 1.875ns, this register field should be set to 1; otherwise it
 *    should be set to 0.
 */
#define DDRC_DERATEEN_SHADOW_derate_value(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DERATEEN_SHADOW_derate_value_SHIFT)) & DDRC_DERATEEN_SHADOW_derate_value_MASK)

#define DDRC_DERATEEN_SHADOW_derate_byte_MASK    (0xF0U)
#define DDRC_DERATEEN_SHADOW_derate_byte_SHIFT   (4U)
/*! derate_byte - Derate byte Present only in designs configured to support LPDDR2/LPDDR3/LPDDR4
 *    Indicates which byte of the MRR data is used for derating. The maximum valid value depends on
 *    MEMC_DRAM_TOTAL_DATA_WIDTH.
 */
#define DDRC_DERATEEN_SHADOW_derate_byte(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_DERATEEN_SHADOW_derate_byte_SHIFT)) & DDRC_DERATEEN_SHADOW_derate_byte_MASK)

#define DDRC_DERATEEN_SHADOW_rc_derate_value_MASK (0x300U)
#define DDRC_DERATEEN_SHADOW_rc_derate_value_SHIFT (8U)
/*! rc_derate_value - Derate value of tRC for LPDDR4 - 0 - Derating uses +1. - 1 - Derating uses +2.
 *    - 2 - Derating uses +3. - 3 - Derating uses +4. Present only in designs configured to support
 *    LPDDR4. The required number of cycles for derating can be determined by dividing 3.75ns by
 *    the core_ddrc_core_clk period, and rounding up the next integer.
 */
#define DDRC_DERATEEN_SHADOW_rc_derate_value(x)  (((uint32_t)(((uint32_t)(x)) << DDRC_DERATEEN_SHADOW_rc_derate_value_SHIFT)) & DDRC_DERATEEN_SHADOW_rc_derate_value_MASK)
/*! @} */

/*! @name DERATEINT_SHADOW - [SHADOW] Temperature Derate Interval Register */
/*! @{ */

#define DDRC_DERATEINT_SHADOW_mr4_read_interval_MASK (0xFFFFFFFFU)
#define DDRC_DERATEINT_SHADOW_mr4_read_interval_SHIFT (0U)
/*! mr4_read_interval - Interval between two MR4 reads, used to derate the timing parameters.
 *    Present only in designs configured to support LPDDR2/LPDDR3/LPDDR4. This register must not be set to
 *    zero. Unit: DFI clock cycle.
 */
#define DDRC_DERATEINT_SHADOW_mr4_read_interval(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DERATEINT_SHADOW_mr4_read_interval_SHIFT)) & DDRC_DERATEINT_SHADOW_mr4_read_interval_MASK)
/*! @} */

/*! @name RFSHCTL0_SHADOW - [SHADOW] Refresh Control Register 0 */
/*! @{ */

#define DDRC_RFSHCTL0_SHADOW_per_bank_refresh_MASK (0x4U)
#define DDRC_RFSHCTL0_SHADOW_per_bank_refresh_SHIFT (2U)
/*! per_bank_refresh - - 1 - Per bank refresh; - 0 - All bank refresh. Per bank refresh allows
 *    traffic to flow to other banks. Per bank refresh is not supported by all LPDDR2 devices but should
 *    be supported by all LPDDR3/LPDDR4 devices. Present only in designs configured to support
 *    LPDDR2/LPDDR3/LPDDR4
 */
#define DDRC_RFSHCTL0_SHADOW_per_bank_refresh(x) (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHCTL0_SHADOW_per_bank_refresh_SHIFT)) & DDRC_RFSHCTL0_SHADOW_per_bank_refresh_MASK)

#define DDRC_RFSHCTL0_SHADOW_refresh_burst_MASK  (0x1F0U)
#define DDRC_RFSHCTL0_SHADOW_refresh_burst_SHIFT (4U)
/*! refresh_burst - The programmed value + 1 is the number of refresh timeouts that is allowed to
 *    accumulate before traffic is blocked and the refreshes are forced to execute. Closing pages to
 *    perform a refresh is a one-time penalty that must be paid for each group of refreshes.
 *    Therefore, performing refreshes in a burst reduces the per-refresh penalty of these page closings.
 *    Higher numbers for RFSHCTL.refresh_burst slightly increases utilization; lower numbers decreases
 *    the worst-case latency associated with refreshes. - 0 - single refresh - 1 - burst-of-2
 *    refresh - 7 - burst-of-8 refresh For information on burst refresh feature refer to section 3.9 of
 *    DDR2 JEDEC specification - JESD79-2F.pdf. For DDR2/3, the refresh is always per-rank and not
 *    per-bank. The rank refresh can be accumulated over 8*tREFI cycles using the burst refresh
 *    feature. In DDR4 mode, according to Fine Granularity feature, 8 refreshes can be postponed in 1X
 *    mode, 16 refreshes in 2X mode and 32 refreshes in 4X mode. If using PHY-initiated updates, care
 *    must be taken in the setting of RFSHCTL0.refresh_burst, to ensure that tRFCmax is not violated
 *    due to a PHY-initiated update occurring shortly before a refresh burst was due. In this
 *    situation, the refresh burst will be delayed until the PHY-initiated update is complete.
 */
#define DDRC_RFSHCTL0_SHADOW_refresh_burst(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHCTL0_SHADOW_refresh_burst_SHIFT)) & DDRC_RFSHCTL0_SHADOW_refresh_burst_MASK)

#define DDRC_RFSHCTL0_SHADOW_refresh_to_x32_MASK (0x1F000U)
#define DDRC_RFSHCTL0_SHADOW_refresh_to_x32_SHIFT (12U)
/*! refresh_to_x32 - If the refresh timer (tRFCnom, also known as tREFI) has expired at least once,
 *    but it has not expired (RFSHCTL0.refresh_burst+1) times yet, then a speculative refresh may be
 *    performed. A speculative refresh is a refresh performed at a time when refresh would be
 *    useful, but before it is absolutely required. When the SDRAM bus is idle for a period of time
 *    determined by this RFSHCTL0.refresh_to_x32 and the refresh timer has expired at least once since
 *    the last refresh, then a speculative refresh is performed. Speculative refreshes continues
 *    successively until there are no refreshes pending or until new reads or writes are issued to the
 *    DDRC. FOR PERFORMANCE ONLY. Unit: Multiples of 32 DFI clocks.
 */
#define DDRC_RFSHCTL0_SHADOW_refresh_to_x32(x)   (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHCTL0_SHADOW_refresh_to_x32_SHIFT)) & DDRC_RFSHCTL0_SHADOW_refresh_to_x32_MASK)

#define DDRC_RFSHCTL0_SHADOW_refresh_margin_MASK (0xF00000U)
#define DDRC_RFSHCTL0_SHADOW_refresh_margin_SHIFT (20U)
/*! refresh_margin - Threshold value in number of DFI clock cycles before the critical refresh or
 *    page timer expires. A critical refresh is to be issued before this threshold is reached. It is
 *    recommended that this not be changed from the default value, currently shown as 0x2. It must
 *    always be less than internally used t_rfc_nom_x32. Note that, in LPDDR2/LPDDR3/LPDDR4,
 *    internally used t_rfc_nom_x32 may be equal to RFSHTMG.t_rfc_nom_x32>>2 if derating is enabled
 *    (DERATEEN.derate_enable=1). Otherwise, internally used t_rfc_nom_x32 will be equal to
 *    RFSHTMG.t_rfc_nom_x32. Unit: Multiples of 32 DFI clocks.
 */
#define DDRC_RFSHCTL0_SHADOW_refresh_margin(x)   (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHCTL0_SHADOW_refresh_margin_SHIFT)) & DDRC_RFSHCTL0_SHADOW_refresh_margin_MASK)
/*! @} */

/*! @name RFSHTMG_SHADOW - [SHADOW] Refresh Timing Register */
/*! @{ */

#define DDRC_RFSHTMG_SHADOW_t_rfc_min_MASK       (0x3FFU)
#define DDRC_RFSHTMG_SHADOW_t_rfc_min_SHIFT      (0U)
/*! t_rfc_min - tRFC (min): Minimum time from refresh to refresh or activate. When the controller is
 *    operating in 1:1 mode, t_rfc_min should be set to RoundUp(tRFCmin/tCK). When the controller
 *    is operating in 1:2 mode, t_rfc_min should be set to RoundUp(RoundUp(tRFCmin/tCK)/2). In
 *    LPDDR2/LPDDR3/LPDDR4 mode: - if using all-bank refreshes, the tRFCmin value in the above equations
 *    is equal to tRFCab - if using per-bank refreshes, the tRFCmin value in the above equations is
 *    equal to tRFCpb In DDR4 mode, the tRFCmin value in the above equations is different depending
 *    on the refresh mode (fixed 1X,2X,4X) and the device density. The user should program the
 *    appropriate value from the spec based on the 'refresh_mode' and the device density that is used.
 *    Unit: Clocks.
 */
#define DDRC_RFSHTMG_SHADOW_t_rfc_min(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHTMG_SHADOW_t_rfc_min_SHIFT)) & DDRC_RFSHTMG_SHADOW_t_rfc_min_MASK)

#define DDRC_RFSHTMG_SHADOW_lpddr3_trefbw_en_MASK (0x8000U)
#define DDRC_RFSHTMG_SHADOW_lpddr3_trefbw_en_SHIFT (15U)
/*! lpddr3_trefbw_en - Used only when LPDDR3 memory type is connected. Should only be changed when
 *    DDRC is in reset. Specifies whether to use the tREFBW parameter (required by some LPDDR3
 *    devices which comply with earlier versions of the LPDDR3 JEDEC specification) or not: - 0 - tREFBW
 *    parameter not used - 1 - tREFBW parameter used
 */
#define DDRC_RFSHTMG_SHADOW_lpddr3_trefbw_en(x)  (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHTMG_SHADOW_lpddr3_trefbw_en_SHIFT)) & DDRC_RFSHTMG_SHADOW_lpddr3_trefbw_en_MASK)

#define DDRC_RFSHTMG_SHADOW_t_rfc_nom_x32_MASK   (0xFFF0000U)
#define DDRC_RFSHTMG_SHADOW_t_rfc_nom_x32_SHIFT  (16U)
/*! t_rfc_nom_x32 - tREFI: Average time interval between refreshes per rank (Specification: 7.8us
 *    for DDR2, DDR3 and DDR4. See JEDEC specification for mDDR, LPDDR2, LPDDR3 and LPDDR4). For
 *    LPDDR2/LPDDR3/LPDDR4: - if using all-bank refreshes (RFSHCTL0.per_bank_refresh = 0), this register
 *    should be set to tREFIab - if using per-bank refreshes (RFSHCTL0.per_bank_refresh = 1), this
 *    register should be set to tREFIpb When the controller is operating in 1:2 frequency ratio mode,
 *    program this to (tREFI/2), no rounding up. In DDR4 mode, tREFI value is different depending
 *    on the refresh mode. The user should program the appropriate value from the spec based on the
 *    value programmed in the refresh mode register. Note that RFSHTMG.t_rfc_nom_x32 * 32 must be
 *    greater than RFSHTMG.t_rfc_min, and RFSHTMG.t_rfc_nom_x32 must be greater than 0x1. - Non-DDR4 or
 *    DDR4 Fixed 1x mode: RFSHTMG.t_rfc_nom_x32 must be less than or equal to 0xFFE. - DDR4 Fixed
 *    2x mode: RFSHTMG.t_rfc_nom_x32 must be less than or equal to 0x7FF. - DDR4 Fixed 4x mode:
 *    RFSHTMG.t_rfc_nom_x32 must be less than or equal to 0x3FF. Unit: Multiples of 32 clocks.
 */
#define DDRC_RFSHTMG_SHADOW_t_rfc_nom_x32(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_RFSHTMG_SHADOW_t_rfc_nom_x32_SHIFT)) & DDRC_RFSHTMG_SHADOW_t_rfc_nom_x32_MASK)
/*! @} */

/*! @name INIT3_SHADOW - [SHADOW] SDRAM Initialization Register 3 */
/*! @{ */

#define DDRC_INIT3_SHADOW_emr_MASK               (0xFFFFU)
#define DDRC_INIT3_SHADOW_emr_SHIFT              (0U)
/*! emr - DDR2: Value to write to EMR register. Bits 9:7 are for OCD and the setting in this
 *    register is ignored. The DDRC sets those bits appropriately. DDR3/DDR4: Value to write to MR1
 *    register Set bit 7 to 0. If PHY-evaluation mode training is enabled, this bit is set appropriately by
 *    the DDRC during write leveling. mDDR: Value to write to EMR register. LPDDR2/LPDDR3/LPDDR4 -
 *    Value to write to MR2 register
 */
#define DDRC_INIT3_SHADOW_emr(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_INIT3_SHADOW_emr_SHIFT)) & DDRC_INIT3_SHADOW_emr_MASK)

#define DDRC_INIT3_SHADOW_mr_MASK                (0xFFFF0000U)
#define DDRC_INIT3_SHADOW_mr_SHIFT               (16U)
/*! mr - DDR2: Value to write to MR register. Bit 8 is for DLL and the setting here is ignored. The
 *    DDRC sets this bit appropriately. DDR3/DDR4: Value loaded into MR0 register. mDDR: Value to
 *    write to MR register. LPDDR2/LPDDR3/LPDDR4 - Value to write to MR1 register
 */
#define DDRC_INIT3_SHADOW_mr(x)                  (((uint32_t)(((uint32_t)(x)) << DDRC_INIT3_SHADOW_mr_SHIFT)) & DDRC_INIT3_SHADOW_mr_MASK)
/*! @} */

/*! @name INIT4_SHADOW - [SHADOW] SDRAM Initialization Register 4 */
/*! @{ */

#define DDRC_INIT4_SHADOW_emr3_MASK              (0xFFFFU)
#define DDRC_INIT4_SHADOW_emr3_SHIFT             (0U)
/*! emr3 - DDR2: Value to write to EMR3 register. DDR3/DDR4: Value to write to MR3 register
 *    mDDR/LPDDR2/LPDDR3: Unused LPDDR4: Value to write to MR13 register
 */
#define DDRC_INIT4_SHADOW_emr3(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_INIT4_SHADOW_emr3_SHIFT)) & DDRC_INIT4_SHADOW_emr3_MASK)

#define DDRC_INIT4_SHADOW_emr2_MASK              (0xFFFF0000U)
#define DDRC_INIT4_SHADOW_emr2_SHIFT             (16U)
/*! emr2 - DDR2: Value to write to EMR2 register. DDR3/DDR4: Value to write to MR2 register
 *    LPDDR2/LPDDR3/LPDDR4: Value to write to MR3 register mDDR: Unused
 */
#define DDRC_INIT4_SHADOW_emr2(x)                (((uint32_t)(((uint32_t)(x)) << DDRC_INIT4_SHADOW_emr2_SHIFT)) & DDRC_INIT4_SHADOW_emr2_MASK)
/*! @} */

/*! @name INIT6_SHADOW - [SHADOW] SDRAM Initialization Register 6 */
/*! @{ */

#define DDRC_INIT6_SHADOW_mr5_MASK               (0xFFFFU)
#define DDRC_INIT6_SHADOW_mr5_SHIFT              (0U)
/*! mr5 - DDR4- Value to be loaded into SDRAM MR5 registers. Used in DDR4 designs only. */
#define DDRC_INIT6_SHADOW_mr5(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_INIT6_SHADOW_mr5_SHIFT)) & DDRC_INIT6_SHADOW_mr5_MASK)

#define DDRC_INIT6_SHADOW_mr4_MASK               (0xFFFF0000U)
#define DDRC_INIT6_SHADOW_mr4_SHIFT              (16U)
/*! mr4 - DDR4- Value to be loaded into SDRAM MR4 registers. Used in DDR4 designs only. */
#define DDRC_INIT6_SHADOW_mr4(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_INIT6_SHADOW_mr4_SHIFT)) & DDRC_INIT6_SHADOW_mr4_MASK)
/*! @} */

/*! @name INIT7_SHADOW - [SHADOW] SDRAM Initialization Register 7 */
/*! @{ */

#define DDRC_INIT7_SHADOW_mr6_MASK               (0xFFFF0000U)
#define DDRC_INIT7_SHADOW_mr6_SHIFT              (16U)
/*! mr6 - DDR4- Value to be loaded into SDRAM MR6 registers. Used in DDR4 designs only. */
#define DDRC_INIT7_SHADOW_mr6(x)                 (((uint32_t)(((uint32_t)(x)) << DDRC_INIT7_SHADOW_mr6_SHIFT)) & DDRC_INIT7_SHADOW_mr6_MASK)
/*! @} */

/*! @name DRAMTMG0_SHADOW - [SHADOW] SDRAM Timing Register 0 */
/*! @{ */

#define DDRC_DRAMTMG0_SHADOW_t_ras_min_MASK      (0x3FU)
#define DDRC_DRAMTMG0_SHADOW_t_ras_min_SHIFT     (0U)
/*! t_ras_min - tRAS(min): Minimum time between activate and precharge to the same bank. When the
 *    controller is operating in 1:2 frequency mode, 1T mode, program this to tRAS(min)/2. No rounding
 *    up. When the controller is operating in 1:2 frequency ratio mode, 2T mode or LPDDR4 mode,
 *    program this to (tRAS(min)/2) and round it up to the next integer value. Unit: Clocks
 */
#define DDRC_DRAMTMG0_SHADOW_t_ras_min(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG0_SHADOW_t_ras_min_SHIFT)) & DDRC_DRAMTMG0_SHADOW_t_ras_min_MASK)

#define DDRC_DRAMTMG0_SHADOW_t_ras_max_MASK      (0x7F00U)
#define DDRC_DRAMTMG0_SHADOW_t_ras_max_SHIFT     (8U)
/*! t_ras_max - tRAS(max): Maximum time between activate and precharge to same bank. This is the
 *    maximum time that a page can be kept open Minimum value of this register is 1. Zero is invalid.
 *    When the controller is operating in 1:2 frequency ratio mode, program this to (tRAS(max)-1)/2.
 *    No rounding up. Unit: Multiples of 1024 clocks.
 */
#define DDRC_DRAMTMG0_SHADOW_t_ras_max(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG0_SHADOW_t_ras_max_SHIFT)) & DDRC_DRAMTMG0_SHADOW_t_ras_max_MASK)

#define DDRC_DRAMTMG0_SHADOW_t_faw_MASK          (0x3F0000U)
#define DDRC_DRAMTMG0_SHADOW_t_faw_SHIFT         (16U)
/*! t_faw - tFAW Valid only when 8 or more banks(or banks x bank groups) are present. In 8-bank
 *    design, at most 4 banks must be activated in a rolling window of tFAW cycles. When the controller
 *    is operating in 1:2 frequency ratio mode, program this to (tFAW/2) and round up to next
 *    integer value. In a 4-bank design, set this register to 0x1 independent of the 1:1/1:2 frequency
 *    mode. Unit: Clocks
 */
#define DDRC_DRAMTMG0_SHADOW_t_faw(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG0_SHADOW_t_faw_SHIFT)) & DDRC_DRAMTMG0_SHADOW_t_faw_MASK)

#define DDRC_DRAMTMG0_SHADOW_wr2pre_MASK         (0x7F000000U)
#define DDRC_DRAMTMG0_SHADOW_wr2pre_SHIFT        (24U)
/*! wr2pre - Minimum time between write and precharge to same bank. Unit: Clocks Specifications: WL
 *    + BL/2 + tWR = approximately 8 cycles + 15 ns = 14 clocks @400MHz and less for lower
 *    frequencies where: - WL = write latency - BL = burst length. This must match the value programmed in
 *    the BL bit of the mode register to the SDRAM. BST (burst terminate) is not supported at present.
 *    - tWR = Write recovery time. This comes directly from the SDRAM specification. Add one extra
 *    cycle for LPDDR2/LPDDR3/LPDDR4 for this parameter. When the controller is operating in 1:2
 *    frequency ratio mode, 1T mode, divide the above value by 2. No rounding up. When the controller
 *    is operating in 1:2 frequency ratio mode, 2T mode or LPDDR4 mode, divide the above value by 2
 *    and round it up to the next integer value. Note that, depending on the PHY, if using LRDIMM, it
 *    may be necessary to adjust the value of this parameter to compensate for the extra cycle of
 *    latency through the LRDIMM.
 */
#define DDRC_DRAMTMG0_SHADOW_wr2pre(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG0_SHADOW_wr2pre_SHIFT)) & DDRC_DRAMTMG0_SHADOW_wr2pre_MASK)
/*! @} */

/*! @name DRAMTMG1_SHADOW - [SHADOW] SDRAM Timing Register 1 */
/*! @{ */

#define DDRC_DRAMTMG1_SHADOW_t_rc_MASK           (0x7FU)
#define DDRC_DRAMTMG1_SHADOW_t_rc_SHIFT          (0U)
/*! t_rc - tRC: Minimum time between activates to same bank. When the controller is operating in 1:2
 *    frequency ratio mode, program this to (tRC/2) and round up to next integer value. Unit:
 *    Clocks.
 */
#define DDRC_DRAMTMG1_SHADOW_t_rc(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG1_SHADOW_t_rc_SHIFT)) & DDRC_DRAMTMG1_SHADOW_t_rc_MASK)

#define DDRC_DRAMTMG1_SHADOW_rd2pre_MASK         (0x3F00U)
#define DDRC_DRAMTMG1_SHADOW_rd2pre_SHIFT        (8U)
/*! rd2pre - tRTP: Minimum time from read to precharge of same bank. - DDR2: tAL + BL/2 + max(tRTP,
 *    2) - 2 - DDR3: tAL + max (tRTP, 4) - DDR4: Max of following two equations: tAL + max (tRTP, 4)
 *    or, RL + BL/2 - tRP (*). - mDDR: BL/2 - LPDDR2: Depends on if it's LPDDR2-S2 or LPDDR2-S4:
 *    LPDDR2-S2: BL/2 + tRTP - 1. LPDDR2-S4: BL/2 + max(tRTP,2) - 2. - LPDDR3: BL/2 + max(tRTP,4) - 4
 *    - LPDDR4: BL/2 + max(tRTP,8) - 8 (*) When both DDR4 SDRAM and ST-MRAM are used simultaneously,
 *    use SDRAM's tRP value for calculation. When the controller is operating in 1:2 mode, 1T mode,
 *    divide the above value by 2. No rounding up. When the controller is operating in 1:2 mode, 2T
 *    mode or LPDDR4 mode, divide the above value by 2 and round it up to the next integer value.
 *    Unit: Clocks.
 */
#define DDRC_DRAMTMG1_SHADOW_rd2pre(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG1_SHADOW_rd2pre_SHIFT)) & DDRC_DRAMTMG1_SHADOW_rd2pre_MASK)

#define DDRC_DRAMTMG1_SHADOW_t_xp_MASK           (0x1F0000U)
#define DDRC_DRAMTMG1_SHADOW_t_xp_SHIFT          (16U)
/*! t_xp - tXP: Minimum time after power-down exit to any operation. For DDR3, this should be
 *    programmed to tXPDLL if slow powerdown exit is selected in MR0[12]. If C/A parity for DDR4 is used,
 *    set to (tXP+PL) instead. When the controller is operating in 1:2 frequency ratio mode, program
 *    this to (tXP/2) and round it up to the next integer value. Units: Clocks
 */
#define DDRC_DRAMTMG1_SHADOW_t_xp(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG1_SHADOW_t_xp_SHIFT)) & DDRC_DRAMTMG1_SHADOW_t_xp_MASK)
/*! @} */

/*! @name DRAMTMG2_SHADOW - [SHADOW] SDRAM Timing Register 2 */
/*! @{ */

#define DDRC_DRAMTMG2_SHADOW_wr2rd_MASK          (0x3FU)
#define DDRC_DRAMTMG2_SHADOW_wr2rd_SHIFT         (0U)
/*! wr2rd - DDR4: CWL + PL + BL/2 + tWTR_L Others: CWL + BL/2 + tWTR In DDR4, minimum time from
 *    write command to read command for same bank group. In others, minimum time from write command to
 *    read command. Includes time for bus turnaround, recovery times, and all per-bank, per-rank, and
 *    global constraints. Unit: Clocks. Where: - CWL = CAS write latency - PL = Parity latency - BL
 *    = burst length. This must match the value programmed in the BL bit of the mode register to
 *    the SDRAM - tWTR_L = internal write to read command delay for same bank group. This comes
 *    directly from the SDRAM specification. - tWTR = internal write to read command delay. This comes
 *    directly from the SDRAM specification. Add one extra cycle for LPDDR2/LPDDR3/LPDDR4 operation.
 *    When the controller is operating in 1:2 mode, divide the value calculated using the above
 *    equation by 2, and round it up to next integer.
 */
#define DDRC_DRAMTMG2_SHADOW_wr2rd(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG2_SHADOW_wr2rd_SHIFT)) & DDRC_DRAMTMG2_SHADOW_wr2rd_MASK)

#define DDRC_DRAMTMG2_SHADOW_rd2wr_MASK          (0x3F00U)
#define DDRC_DRAMTMG2_SHADOW_rd2wr_SHIFT         (8U)
/*! rd2wr - DDR2/3/mDDR: RL + BL/2 + 2 - WL DDR4: RL + BL/2 + 1 + WR_PREAMBLE - WL LPDDR2/LPDDR3: RL
 *    + BL/2 + RU(tDQSCKmax/tCK) + 1 - WL LPDDR4(DQ ODT is Disabled): RL + BL/2 + RU(tDQSCKmax/tCK)
 *    + WR_PREAMBLE + RD_POSTAMBLE - WL LPDDR4(DQ ODT is Enabled) : RL + BL/2 + RU(tDQSCKmax/tCK) +
 *    RD_POSTAMBLE - ODTLon - RU(tODTon(min)/tCK) Minimum time from read command to write command.
 *    Include time for bus turnaround and all per-bank, per-rank, and global constraints. Please see
 *    the relevant PHY databook for details of what should be included here. Unit: Clocks. Where: -
 *    WL = write latency - BL = burst length. This must match the value programmed in the BL bit of
 *    the mode register to the SDRAM - RL = read latency = CAS latency - WR_PREAMBLE = write
 *    preamble. This is unique to DDR4 and LPDDR4. - RD_POSTAMBLE = read postamble. This is unique to
 *    LPDDR4. For LPDDR2/LPDDR3/LPDDR4, if derating is enabled (DERATEEN.derate_enable=1), derated
 *    tDQSCKmax should be used. When the controller is operating in 1:2 frequency ratio mode, divide the
 *    value calculated using the above equation by 2, and round it up to next integer. Note that,
 *    depending on the PHY, if using LRDIMM, it may be necessary to adjust the value of this parameter
 *    to compensate for the extra cycle of latency through the LRDIMM.
 */
#define DDRC_DRAMTMG2_SHADOW_rd2wr(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG2_SHADOW_rd2wr_SHIFT)) & DDRC_DRAMTMG2_SHADOW_rd2wr_MASK)

#define DDRC_DRAMTMG2_SHADOW_read_latency_MASK   (0x3F0000U)
#define DDRC_DRAMTMG2_SHADOW_read_latency_SHIFT  (16U)
/*! read_latency - Set to RL Time from read command to read data on SDRAM interface. This must be
 *    set to RL. Note that, depending on the PHY, if using RDIMM/LRDIMM, it may be necessary to adjust
 *    the value of RL to compensate for the extra cycle of latency through the RDIMM/LRDIMM. When
 *    the controller is operating in 1:2 frequency ratio mode, divide the value calculated using the
 *    above equation by 2, and round it up to next integer. This register field is not required for
 *    DDR2 and DDR3 (except if MEMC_TRAINING is set), as the DFI read and write latencies defined in
 *    DFITMG0 and DFITMG1 are sufficient for those protocols Unit: clocks
 */
#define DDRC_DRAMTMG2_SHADOW_read_latency(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG2_SHADOW_read_latency_SHIFT)) & DDRC_DRAMTMG2_SHADOW_read_latency_MASK)

#define DDRC_DRAMTMG2_SHADOW_write_latency_MASK  (0x3F000000U)
#define DDRC_DRAMTMG2_SHADOW_write_latency_SHIFT (24U)
/*! write_latency - Set to WL Time from write command to write data on SDRAM interface. This must be
 *    set to WL. For mDDR, it should normally be set to 1. Note that, depending on the PHY, if
 *    using RDIMM/LRDIMM, it may be necessary to adjust the value of WL to compensate for the extra
 *    cycle of latency through the RDIMM/LRDIMM. When the controller is operating in 1:2 frequency ratio
 *    mode, divide the value calculated using the above equation by 2, and round it up to next
 *    integer. This register field is not required for DDR2 and DDR3 (except if MEMC_TRAINING is set),
 *    as the DFI read and write latencies defined in DFITMG0 and DFITMG1 are sufficient for those
 *    protocols Unit: clocks
 */
#define DDRC_DRAMTMG2_SHADOW_write_latency(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG2_SHADOW_write_latency_SHIFT)) & DDRC_DRAMTMG2_SHADOW_write_latency_MASK)
/*! @} */

/*! @name DRAMTMG3_SHADOW - [SHADOW] SDRAM Timing Register 3 */
/*! @{ */

#define DDRC_DRAMTMG3_SHADOW_t_mod_MASK          (0x3FFU)
#define DDRC_DRAMTMG3_SHADOW_t_mod_SHIFT         (0U)
/*! t_mod - tMOD: Parameter used only in DDR3 and DDR4. Cycles between load mode command and
 *    following non-load mode command. If C/A parity for DDR4 is used, set to tMOD_PAR(tMOD+PL) instead.
 *    Set to tMOD if controller is operating in 1:1 frequency ratio mode, or tMOD/2 (rounded up to
 *    next integer) if controller is operating in 1:2 frequency ratio mode. Note that if using
 *    RDIMM/LRDIMM, depending on the PHY, it may be necessary to adjust the value of this parameter to
 *    compensate for the extra cycle of latency applied to mode register writes by the RDIMM/LRDIMM chip.
 *    Also note that if using LRDIMM, the minimum value of this register is tMRD_L2 if controller
 *    is operating in 1:1 frequency ratio mode, or tMRD_L2/2 (rounded up to next integer) if
 *    controller is operating in 1:2 frequency ratio mode.
 */
#define DDRC_DRAMTMG3_SHADOW_t_mod(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG3_SHADOW_t_mod_SHIFT)) & DDRC_DRAMTMG3_SHADOW_t_mod_MASK)

#define DDRC_DRAMTMG3_SHADOW_t_mrd_MASK          (0x3F000U)
#define DDRC_DRAMTMG3_SHADOW_t_mrd_SHIFT         (12U)
/*! t_mrd - tMRD: Cycles to wait after a mode register write or read. Depending on the connected
 *    SDRAM, tMRD represents: DDR2/mDDR: Time from MRS to any command DDR3/4: Time from MRS to MRS
 *    command LPDDR2: not used LPDDR3/4: Time from MRS to non-MRS command. When the controller is
 *    operating in 1:2 frequency ratio mode, program this to (tMRD/2) and round it up to the next integer
 *    value. If C/A parity for DDR4 is used, set to tMRD_PAR(tMOD+PL) instead.
 */
#define DDRC_DRAMTMG3_SHADOW_t_mrd(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG3_SHADOW_t_mrd_SHIFT)) & DDRC_DRAMTMG3_SHADOW_t_mrd_MASK)

#define DDRC_DRAMTMG3_SHADOW_t_mrw_MASK          (0x3FF00000U)
#define DDRC_DRAMTMG3_SHADOW_t_mrw_SHIFT         (20U)
/*! t_mrw - Time to wait after a mode register write or read (MRW or MRR). Present only in designs
 *    configured to support LPDDR2, LPDDR3 or LPDDR4. LPDDR2 typically requires value of 5. LPDDR3
 *    typically requires value of 10. LPDDR4: Set this to the larger of tMRW and tMRWCKEL. For LPDDR2,
 *    this register is used for the time from a MRW/MRR to all other commands. When the controller
 *    is operating in 1:2 frequency ratio mode, program this to the above values divided by 2 and
 *    round it up to the next integer value. For LDPDR3, this register is used for the time from a
 *    MRW/MRR to a MRW/MRR.
 */
#define DDRC_DRAMTMG3_SHADOW_t_mrw(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG3_SHADOW_t_mrw_SHIFT)) & DDRC_DRAMTMG3_SHADOW_t_mrw_MASK)
/*! @} */

/*! @name DRAMTMG4_SHADOW - [SHADOW] SDRAM Timing Register 4 */
/*! @{ */

#define DDRC_DRAMTMG4_SHADOW_t_rp_MASK           (0x1FU)
#define DDRC_DRAMTMG4_SHADOW_t_rp_SHIFT          (0U)
/*! t_rp - tRP: Minimum time from precharge to activate of same bank. When the controller is
 *    operating in 1:1 frequency ratio mode, t_rp should be set to RoundUp(tRP/tCK). When the controller is
 *    operating in 1:2 frequency ratio mode, t_rp should be set to RoundDown(RoundUp(tRP/tCK)/2) +
 *    1. When the controller is operating in 1:2 frequency ratio mode in LPDDR4, t_rp should be set
 *    to RoundUp(RoundUp(tRP/tCK)/2). Unit: Clocks.
 */
#define DDRC_DRAMTMG4_SHADOW_t_rp(x)             (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG4_SHADOW_t_rp_SHIFT)) & DDRC_DRAMTMG4_SHADOW_t_rp_MASK)

#define DDRC_DRAMTMG4_SHADOW_t_rrd_MASK          (0xF00U)
#define DDRC_DRAMTMG4_SHADOW_t_rrd_SHIFT         (8U)
/*! t_rrd - DDR4: tRRD_L: Minimum time between activates from bank "a" to bank "b" for same bank
 *    group. Others: tRRD: Minimum time between activates from bank "a" to bank "b" When the controller
 *    is operating in 1:2 frequency ratio mode, program this to (tRRD_L/2 or tRRD/2) and round it
 *    up to the next integer value. Unit: Clocks.
 */
#define DDRC_DRAMTMG4_SHADOW_t_rrd(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG4_SHADOW_t_rrd_SHIFT)) & DDRC_DRAMTMG4_SHADOW_t_rrd_MASK)

#define DDRC_DRAMTMG4_SHADOW_t_ccd_MASK          (0xF0000U)
#define DDRC_DRAMTMG4_SHADOW_t_ccd_SHIFT         (16U)
/*! t_ccd - DDR4: tCCD_L: This is the minimum time between two reads or two writes for same bank
 *    group. Others: tCCD: This is the minimum time between two reads or two writes. When the
 *    controller is operating in 1:2 frequency ratio mode, program this to (tCCD_L/2 or tCCD/2) and round it
 *    up to the next integer value. Unit: clocks.
 */
#define DDRC_DRAMTMG4_SHADOW_t_ccd(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG4_SHADOW_t_ccd_SHIFT)) & DDRC_DRAMTMG4_SHADOW_t_ccd_MASK)

#define DDRC_DRAMTMG4_SHADOW_t_rcd_MASK          (0x1F000000U)
#define DDRC_DRAMTMG4_SHADOW_t_rcd_SHIFT         (24U)
/*! t_rcd - tRCD - tAL: Minimum time from activate to read or write command to same bank. When the
 *    controller is operating in 1:2 frequency ratio mode, program this to ((tRCD - tAL)/2) and round
 *    it up to the next integer value. Minimum value allowed for this register is 1, which implies
 *    minimum (tRCD - tAL) value to be 2 when the controller is operating in 1:2 frequency ratio
 *    mode. Unit: Clocks.
 */
#define DDRC_DRAMTMG4_SHADOW_t_rcd(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG4_SHADOW_t_rcd_SHIFT)) & DDRC_DRAMTMG4_SHADOW_t_rcd_MASK)
/*! @} */

/*! @name DRAMTMG5_SHADOW - [SHADOW] SDRAM Timing Register 5 */
/*! @{ */

#define DDRC_DRAMTMG5_SHADOW_t_cke_MASK          (0x1FU)
#define DDRC_DRAMTMG5_SHADOW_t_cke_SHIFT         (0U)
/*! t_cke - Minimum number of cycles of CKE HIGH/LOW during power-down and self refresh. -
 *    LPDDR2/LPDDR3 mode: Set this to the larger of tCKE or tCKESR - LPDDR4 mode: Set this to the larger of
 *    tCKE, tCKELPD or tSR. - Non-LPDDR2/non-LPDDR3/non-LPDDR4 designs: Set this to tCKE value. When
 *    the controller is operating in 1:2 frequency ratio mode, program this to (value described
 *    above)/2 and round it up to the next integer value. Unit: Clocks.
 */
#define DDRC_DRAMTMG5_SHADOW_t_cke(x)            (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG5_SHADOW_t_cke_SHIFT)) & DDRC_DRAMTMG5_SHADOW_t_cke_MASK)

#define DDRC_DRAMTMG5_SHADOW_t_ckesr_MASK        (0x3F00U)
#define DDRC_DRAMTMG5_SHADOW_t_ckesr_SHIFT       (8U)
/*! t_ckesr - Minimum CKE low width for Self refresh or Self refresh power down entry to exit timing
 *    in memory clock cycles. Recommended settings: - mDDR: tRFC - LPDDR2: tCKESR - LPDDR3: tCKESR
 *    - LPDDR4: max(tCKELPD, tSR) - DDR2: tCKE - DDR3: tCKE + 1 - DDR4: tCKE + 1 (+ PL(parity
 *    latency)(*)) (*)Only if CRCPARCTL1.caparity_disable_before_sr=0, this register should be increased
 *    by PL. When the controller is operating in 1:2 frequency ratio mode, program this to
 *    recommended value divided by two and round it up to next integer.
 */
#define DDRC_DRAMTMG5_SHADOW_t_ckesr(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG5_SHADOW_t_ckesr_SHIFT)) & DDRC_DRAMTMG5_SHADOW_t_ckesr_MASK)

#define DDRC_DRAMTMG5_SHADOW_t_cksre_MASK        (0xF0000U)
#define DDRC_DRAMTMG5_SHADOW_t_cksre_SHIFT       (16U)
/*! t_cksre - This is the time after Self Refresh Down Entry that CK is maintained as a valid clock.
 *    Specifies the clock disable delay after SRE. Recommended settings: - mDDR: 0 - LPDDR2: 2 -
 *    LPDDR3: 2 - LPDDR4: tCKCKEL - DDR2: 1 - DDR3: max (10 ns, 5 tCK) - DDR4: max (10 ns, 5 tCK) (+
 *    PL(parity latency)(*)) (*)Only if CRCPARCTL1.caparity_disable_before_sr=0, this register should
 *    be increased by PL. When the controller is operating in 1:2 frequency ratio mode, program
 *    this to recommended value divided by two and round it up to next integer.
 */
#define DDRC_DRAMTMG5_SHADOW_t_cksre(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG5_SHADOW_t_cksre_SHIFT)) & DDRC_DRAMTMG5_SHADOW_t_cksre_MASK)

#define DDRC_DRAMTMG5_SHADOW_t_cksrx_MASK        (0xF000000U)
#define DDRC_DRAMTMG5_SHADOW_t_cksrx_SHIFT       (24U)
/*! t_cksrx - This is the time before Self Refresh Exit that CK is maintained as a valid clock
 *    before issuing SRX. Specifies the clock stable time before SRX. Recommended settings: - mDDR: 1 -
 *    LPDDR2: 2 - LPDDR3: 2 - LPDDR4: tCKCKEH - DDR2: 1 - DDR3: tCKSRX - DDR4: tCKSRX When the
 *    controller is operating in 1:2 frequency ratio mode, program this to recommended value divided by
 *    two and round it up to next integer.
 */
#define DDRC_DRAMTMG5_SHADOW_t_cksrx(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG5_SHADOW_t_cksrx_SHIFT)) & DDRC_DRAMTMG5_SHADOW_t_cksrx_MASK)
/*! @} */

/*! @name DRAMTMG6_SHADOW - [SHADOW] SDRAM Timing Register 6 */
/*! @{ */

#define DDRC_DRAMTMG6_SHADOW_t_ckcsx_MASK        (0xFU)
#define DDRC_DRAMTMG6_SHADOW_t_ckcsx_SHIFT       (0U)
/*! t_ckcsx - This is the time before Clock Stop Exit that CK is maintained as a valid clock before
 *    issuing Clock Stop Exit. Specifies the clock stable time before next command after Clock Stop
 *    Exit. Recommended settings: - mDDR: 1 - LPDDR2: tXP + 2 - LPDDR3: tXP + 2 - LPDDR4: tXP + 2
 *    When the controller is operating in 1:2 frequency ratio mode, program this to recommended value
 *    divided by two and round it up to next integer. This is only present for designs supporting
 *    mDDR or LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_DRAMTMG6_SHADOW_t_ckcsx(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG6_SHADOW_t_ckcsx_SHIFT)) & DDRC_DRAMTMG6_SHADOW_t_ckcsx_MASK)

#define DDRC_DRAMTMG6_SHADOW_t_ckdpdx_MASK       (0xF0000U)
#define DDRC_DRAMTMG6_SHADOW_t_ckdpdx_SHIFT      (16U)
/*! t_ckdpdx - This is the time before Deep Power Down Exit that CK is maintained as a valid clock
 *    before issuing DPDX. Specifies the clock stable time before DPDX. Recommended settings: - mDDR:
 *    1 - LPDDR2: 2 - LPDDR3: 2 When the controller is operating in 1:2 frequency ratio mode,
 *    program this to recommended value divided by two and round it up to next integer. This is only
 *    present for designs supporting mDDR or LPDDR2 devices.
 */
#define DDRC_DRAMTMG6_SHADOW_t_ckdpdx(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG6_SHADOW_t_ckdpdx_SHIFT)) & DDRC_DRAMTMG6_SHADOW_t_ckdpdx_MASK)

#define DDRC_DRAMTMG6_SHADOW_t_ckdpde_MASK       (0xF000000U)
#define DDRC_DRAMTMG6_SHADOW_t_ckdpde_SHIFT      (24U)
/*! t_ckdpde - This is the time after Deep Power Down Entry that CK is maintained as a valid clock.
 *    Specifies the clock disable delay after DPDE. Recommended settings: - mDDR: 0 - LPDDR2: 2 -
 *    LPDDR3: 2 When the controller is operating in 1:2 frequency ratio mode, program this to
 *    recommended value divided by two and round it up to next integer. This is only present for designs
 *    supporting mDDR or LPDDR2/LPDDR3 devices.
 */
#define DDRC_DRAMTMG6_SHADOW_t_ckdpde(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG6_SHADOW_t_ckdpde_SHIFT)) & DDRC_DRAMTMG6_SHADOW_t_ckdpde_MASK)
/*! @} */

/*! @name DRAMTMG7_SHADOW - [SHADOW] SDRAM Timing Register 7 */
/*! @{ */

#define DDRC_DRAMTMG7_SHADOW_t_ckpdx_MASK        (0xFU)
#define DDRC_DRAMTMG7_SHADOW_t_ckpdx_SHIFT       (0U)
/*! t_ckpdx - This is the time before Power Down Exit that CK is maintained as a valid clock before
 *    issuing PDX. Specifies the clock stable time before PDX. Recommended settings: - mDDR: 0 -
 *    LPDDR2: 2 - LPDDR3: 2 - LPDDR4: 2 When using DDR2/3/4 SDRAM, this register should be set to the
 *    same value as DRAMTMG5.t_cksrx. When the controller is operating in 1:2 frequency ratio mode,
 *    program this to recommended value divided by two and round it up to next integer. This is only
 *    present for designs supporting mDDR or LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_DRAMTMG7_SHADOW_t_ckpdx(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG7_SHADOW_t_ckpdx_SHIFT)) & DDRC_DRAMTMG7_SHADOW_t_ckpdx_MASK)

#define DDRC_DRAMTMG7_SHADOW_t_ckpde_MASK        (0xF00U)
#define DDRC_DRAMTMG7_SHADOW_t_ckpde_SHIFT       (8U)
/*! t_ckpde - This is the time after Power Down Entry that CK is maintained as a valid clock.
 *    Specifies the clock disable delay after PDE. Recommended settings: - mDDR: 0 - LPDDR2: 2 - LPDDR3: 2
 *    - LPDDR4: tCKCKEL When using DDR2/3/4 SDRAM, this register should be set to the same value as
 *    DRAMTMG5.t_cksre. When the controller is operating in 1:2 frequency ratio mode, program this
 *    to recommended value divided by two and round it up to next integer. This is only present for
 *    designs supporting mDDR or LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_DRAMTMG7_SHADOW_t_ckpde(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG7_SHADOW_t_ckpde_SHIFT)) & DDRC_DRAMTMG7_SHADOW_t_ckpde_MASK)
/*! @} */

/*! @name DRAMTMG8_SHADOW - [SHADOW] SDRAM Timing Register 8 */
/*! @{ */

#define DDRC_DRAMTMG8_SHADOW_t_xs_x32_MASK       (0x7FU)
#define DDRC_DRAMTMG8_SHADOW_t_xs_x32_SHIFT      (0U)
/*! t_xs_x32 - tXS: Exit Self Refresh to commands not requiring a locked DLL. When the controller is
 *    operating in 1:2 frequency ratio mode, program this to the above value divided by 2 and round
 *    up to next integer value. Unit: Multiples of 32 clocks. Note: Used only for DDR2, DDR3 and
 *    DDR4 SDRAMs.
 */
#define DDRC_DRAMTMG8_SHADOW_t_xs_x32(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG8_SHADOW_t_xs_x32_SHIFT)) & DDRC_DRAMTMG8_SHADOW_t_xs_x32_MASK)

#define DDRC_DRAMTMG8_SHADOW_t_xs_dll_x32_MASK   (0x7F00U)
#define DDRC_DRAMTMG8_SHADOW_t_xs_dll_x32_SHIFT  (8U)
/*! t_xs_dll_x32 - tXSDLL: Exit Self Refresh to commands requiring a locked DLL. When the controller
 *    is operating in 1:2 frequency ratio mode, program this to the above value divided by 2 and
 *    round up to next integer value. Unit: Multiples of 32 clocks. Note: Used only for DDR2, DDR3 and
 *    DDR4 SDRAMs.
 */
#define DDRC_DRAMTMG8_SHADOW_t_xs_dll_x32(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG8_SHADOW_t_xs_dll_x32_SHIFT)) & DDRC_DRAMTMG8_SHADOW_t_xs_dll_x32_MASK)

#define DDRC_DRAMTMG8_SHADOW_t_xs_abort_x32_MASK (0x7F0000U)
#define DDRC_DRAMTMG8_SHADOW_t_xs_abort_x32_SHIFT (16U)
/*! t_xs_abort_x32 - tXS_ABORT: Exit Self Refresh to commands not requiring a locked DLL in Self
 *    Refresh Abort. When the controller is operating in 1:2 frequency ratio mode, program this to the
 *    above value divided by 2 and round up to next integer value. Unit: Multiples of 32 clocks.
 *    Note: Ensure this is less than or equal to t_xs_x32.
 */
#define DDRC_DRAMTMG8_SHADOW_t_xs_abort_x32(x)   (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG8_SHADOW_t_xs_abort_x32_SHIFT)) & DDRC_DRAMTMG8_SHADOW_t_xs_abort_x32_MASK)

#define DDRC_DRAMTMG8_SHADOW_t_xs_fast_x32_MASK  (0x7F000000U)
#define DDRC_DRAMTMG8_SHADOW_t_xs_fast_x32_SHIFT (24U)
/*! t_xs_fast_x32 - tXS_FAST: Exit Self Refresh to ZQCL, ZQCS and MRS (only CL, WR, RTP and Geardown
 *    mode). When the controller is operating in 1:2 frequency ratio mode, program this to the
 *    above value divided by 2 and round up to next integer value. Unit: Multiples of 32 clocks. Note:
 *    This is applicable to only ZQCL/ZQCS commands. Note: Ensure this is less than or equal to
 *    t_xs_x32.
 */
#define DDRC_DRAMTMG8_SHADOW_t_xs_fast_x32(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG8_SHADOW_t_xs_fast_x32_SHIFT)) & DDRC_DRAMTMG8_SHADOW_t_xs_fast_x32_MASK)
/*! @} */

/*! @name DRAMTMG9_SHADOW - [SHADOW] SDRAM Timing Register 9 */
/*! @{ */

#define DDRC_DRAMTMG9_SHADOW_wr2rd_s_MASK        (0x3FU)
#define DDRC_DRAMTMG9_SHADOW_wr2rd_s_SHIFT       (0U)
/*! wr2rd_s - CWL + PL + BL/2 + tWTR_S Minimum time from write command to read command for different
 *    bank group. Includes time for bus turnaround, recovery times, and all per-bank, per-rank, and
 *    global constraints. Present only in designs configured to support DDR4. Unit: Clocks. Where:
 *    - CWL = CAS write latency - PL = Parity latency - BL = burst length. This must match the value
 *    programmed in the BL bit of the mode register to the SDRAM - tWTR_S = internal write to read
 *    command delay for different bank group. This comes directly from the SDRAM specification. When
 *    the controller is operating in 1:2 mode, divide the value calculated using the above equation
 *    by 2, and round it up to next integer.
 */
#define DDRC_DRAMTMG9_SHADOW_wr2rd_s(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG9_SHADOW_wr2rd_s_SHIFT)) & DDRC_DRAMTMG9_SHADOW_wr2rd_s_MASK)

#define DDRC_DRAMTMG9_SHADOW_t_rrd_s_MASK        (0xF00U)
#define DDRC_DRAMTMG9_SHADOW_t_rrd_s_SHIFT       (8U)
/*! t_rrd_s - tRRD_S: Minimum time between activates from bank "a" to bank "b" for different bank
 *    group. When the controller is operating in 1:2 frequency ratio mode, program this to (tRRD_S/2)
 *    and round it up to the next integer value. Present only in designs configured to support DDR4.
 *    Unit: Clocks.
 */
#define DDRC_DRAMTMG9_SHADOW_t_rrd_s(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG9_SHADOW_t_rrd_s_SHIFT)) & DDRC_DRAMTMG9_SHADOW_t_rrd_s_MASK)

#define DDRC_DRAMTMG9_SHADOW_t_ccd_s_MASK        (0x70000U)
#define DDRC_DRAMTMG9_SHADOW_t_ccd_s_SHIFT       (16U)
/*! t_ccd_s - tCCD_S: This is the minimum time between two reads or two writes for different bank
 *    group. For bank switching (from bank "a" to bank "b"), the minimum time is this value + 1. When
 *    the controller is operating in 1:2 frequency ratio mode, program this to (tCCD_S/2) and round
 *    it up to the next integer value. Present only in designs configured to support DDR4. Unit:
 *    clocks.
 */
#define DDRC_DRAMTMG9_SHADOW_t_ccd_s(x)          (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG9_SHADOW_t_ccd_s_SHIFT)) & DDRC_DRAMTMG9_SHADOW_t_ccd_s_MASK)

#define DDRC_DRAMTMG9_SHADOW_ddr4_wr_preamble_MASK (0x40000000U)
#define DDRC_DRAMTMG9_SHADOW_ddr4_wr_preamble_SHIFT (30U)
/*! ddr4_wr_preamble - DDR4 Write preamble mode - 0: 1tCK preamble - 1: 2tCK preamble Present only with MEMC_FREQ_RATIO=2 */
#define DDRC_DRAMTMG9_SHADOW_ddr4_wr_preamble(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG9_SHADOW_ddr4_wr_preamble_SHIFT)) & DDRC_DRAMTMG9_SHADOW_ddr4_wr_preamble_MASK)
/*! @} */

/*! @name DRAMTMG10_SHADOW - [SHADOW] SDRAM Timing Register 10 */
/*! @{ */

#define DDRC_DRAMTMG10_SHADOW_t_gear_hold_MASK   (0x3U)
#define DDRC_DRAMTMG10_SHADOW_t_gear_hold_SHIFT  (0U)
/*! t_gear_hold - Geardown hold time. Minimum value of this register is 1. Zero is invalid. For
 *    DDR4-2666 and DDR4-3200, this parameter is defined as 2 clks When the controller is operating in
 *    1:2 frequency ratio mode, program this to (tGEAR_hold/2) and round it up to the next integer
 *    value. Unit: Clocks
 */
#define DDRC_DRAMTMG10_SHADOW_t_gear_hold(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG10_SHADOW_t_gear_hold_SHIFT)) & DDRC_DRAMTMG10_SHADOW_t_gear_hold_MASK)

#define DDRC_DRAMTMG10_SHADOW_t_gear_setup_MASK  (0xCU)
#define DDRC_DRAMTMG10_SHADOW_t_gear_setup_SHIFT (2U)
/*! t_gear_setup - Geardown setup time. Minimum value of this register is 1. Zero is invalid. For
 *    DDR4-2666 and DDR4-3200, this parameter is defined as 2 clks When the controller is operating in
 *    1:2 frequency ratio mode, program this to (tGEAR_setup/2) and round it up to the next integer
 *    value. Unit: Clocks
 */
#define DDRC_DRAMTMG10_SHADOW_t_gear_setup(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG10_SHADOW_t_gear_setup_SHIFT)) & DDRC_DRAMTMG10_SHADOW_t_gear_setup_MASK)

#define DDRC_DRAMTMG10_SHADOW_t_cmd_gear_MASK    (0x1F00U)
#define DDRC_DRAMTMG10_SHADOW_t_cmd_gear_SHIFT   (8U)
/*! t_cmd_gear - Sync pulse to first valid command. For DDR4-2666 and DDR4-3200, this parameter is
 *    defined as tMOD(min) tMOD(min) is greater of 24nCK or 15ns 15ns / .625ns = 24 Max value for
 *    this register is 24 When the controller is operating in 1:2 mode, program this to (tCMD_GEAR/2)
 *    and round it up to the next integer value. Unit: Clocks
 */
#define DDRC_DRAMTMG10_SHADOW_t_cmd_gear(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG10_SHADOW_t_cmd_gear_SHIFT)) & DDRC_DRAMTMG10_SHADOW_t_cmd_gear_MASK)

#define DDRC_DRAMTMG10_SHADOW_t_sync_gear_MASK   (0x1F0000U)
#define DDRC_DRAMTMG10_SHADOW_t_sync_gear_SHIFT  (16U)
/*! t_sync_gear - Indicates the time between MRS command and the sync pulse time. This must be even
 *    number of clocks. For DDR4-2666 and DDR4-3200, this parameter is defined as tMOD(min)+4nCK
 *    tMOD(min) is greater of 24nCK or 15ns 15ns / .625ns = 24 Max value for this register is 24+4 = 28
 *    When the controller is operating in 1:2 mode, program this to (tSYNC_GEAR/2) and round it up
 *    to the next integer value. Unit: Clocks
 */
#define DDRC_DRAMTMG10_SHADOW_t_sync_gear(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG10_SHADOW_t_sync_gear_SHIFT)) & DDRC_DRAMTMG10_SHADOW_t_sync_gear_MASK)
/*! @} */

/*! @name DRAMTMG11_SHADOW - [SHADOW] SDRAM Timing Register 11 */
/*! @{ */

#define DDRC_DRAMTMG11_SHADOW_t_ckmpe_MASK       (0x1FU)
#define DDRC_DRAMTMG11_SHADOW_t_ckmpe_SHIFT      (0U)
/*! t_ckmpe - tCKMPE: Minimum valid clock requirement after MPSM entry. Present only in designs
 *    configured to support DDR4. Unit: Clocks. When the controller is operating in 1:2 frequency ratio
 *    mode, divide the value calculated using the above equation by 2, and round it up to next
 *    integer.
 */
#define DDRC_DRAMTMG11_SHADOW_t_ckmpe(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG11_SHADOW_t_ckmpe_SHIFT)) & DDRC_DRAMTMG11_SHADOW_t_ckmpe_MASK)

#define DDRC_DRAMTMG11_SHADOW_t_mpx_s_MASK       (0x300U)
#define DDRC_DRAMTMG11_SHADOW_t_mpx_s_SHIFT      (8U)
/*! t_mpx_s - tMPX_S: Minimum time CS setup time to CKE. When the controller is operating in 1:2
 *    frequency ratio mode, program this to (tMPX_S/2) and round it up to the next integer value.
 *    Present only in designs configured to support DDR4. Unit: Clocks.
 */
#define DDRC_DRAMTMG11_SHADOW_t_mpx_s(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG11_SHADOW_t_mpx_s_SHIFT)) & DDRC_DRAMTMG11_SHADOW_t_mpx_s_MASK)

#define DDRC_DRAMTMG11_SHADOW_t_mpx_lh_MASK      (0x1F0000U)
#define DDRC_DRAMTMG11_SHADOW_t_mpx_lh_SHIFT     (16U)
/*! t_mpx_lh - tMPX_LH: This is the minimum CS_n Low hold time to CKE rising edge. When the
 *    controller is operating in 1:2 frequency ratio mode, program this to RoundUp(tMPX_LH/2)+1. Present
 *    only in designs configured to support DDR4. Unit: clocks.
 */
#define DDRC_DRAMTMG11_SHADOW_t_mpx_lh(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG11_SHADOW_t_mpx_lh_SHIFT)) & DDRC_DRAMTMG11_SHADOW_t_mpx_lh_MASK)

#define DDRC_DRAMTMG11_SHADOW_post_mpsm_gap_x32_MASK (0x7F000000U)
#define DDRC_DRAMTMG11_SHADOW_post_mpsm_gap_x32_SHIFT (24U)
/*! post_mpsm_gap_x32 - tXMPDLL: This is the minimum Exit MPSM to commands requiring a locked DLL.
 *    When the controller is operating in 1:2 frequency ratio mode, program this to (tXMPDLL/2) and
 *    round it up to the next integer value. Present only in designs configured to support DDR4.
 *    Unit: Multiples of 32 clocks.
 */
#define DDRC_DRAMTMG11_SHADOW_post_mpsm_gap_x32(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG11_SHADOW_post_mpsm_gap_x32_SHIFT)) & DDRC_DRAMTMG11_SHADOW_post_mpsm_gap_x32_MASK)
/*! @} */

/*! @name DRAMTMG12_SHADOW - [SHADOW] SDRAM Timing Register 12 */
/*! @{ */

#define DDRC_DRAMTMG12_SHADOW_t_mrd_pda_MASK     (0x1FU)
#define DDRC_DRAMTMG12_SHADOW_t_mrd_pda_SHIFT    (0U)
/*! t_mrd_pda - tMRD_PDA: This is the Mode Register Set command cycle time in PDA mode. When the
 *    controller is operating in 1:2 frequency ratio mode, program this to (tMRD_PDA/2) and round it up
 *    to the next integer value.
 */
#define DDRC_DRAMTMG12_SHADOW_t_mrd_pda(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG12_SHADOW_t_mrd_pda_SHIFT)) & DDRC_DRAMTMG12_SHADOW_t_mrd_pda_MASK)

#define DDRC_DRAMTMG12_SHADOW_t_ckehcmd_MASK     (0xF00U)
#define DDRC_DRAMTMG12_SHADOW_t_ckehcmd_SHIFT    (8U)
/*! t_ckehcmd - tCKEHCMD: Valid command requirement after CKE input HIGH. When the controller is
 *    operating in 1:2 frequency ratio mode, program this to (tCKEHCMD/2) and round it up to the next
 *    integer value.
 */
#define DDRC_DRAMTMG12_SHADOW_t_ckehcmd(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG12_SHADOW_t_ckehcmd_SHIFT)) & DDRC_DRAMTMG12_SHADOW_t_ckehcmd_MASK)

#define DDRC_DRAMTMG12_SHADOW_t_cmdcke_MASK      (0x30000U)
#define DDRC_DRAMTMG12_SHADOW_t_cmdcke_SHIFT     (16U)
/*! t_cmdcke - tCMDCKE: Delay from valid command to CKE input LOW. Set this to the larger of tESCKE
 *    or tCMDCKE When the controller is operating in 1:2 frequency ratio mode, program this to
 *    (max(tESCKE, tCMDCKE)/2) and round it up to the next integer value.
 */
#define DDRC_DRAMTMG12_SHADOW_t_cmdcke(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG12_SHADOW_t_cmdcke_SHIFT)) & DDRC_DRAMTMG12_SHADOW_t_cmdcke_MASK)
/*! @} */

/*! @name DRAMTMG13_SHADOW - [SHADOW] SDRAM Timing Register 13 */
/*! @{ */

#define DDRC_DRAMTMG13_SHADOW_t_ppd_MASK         (0x7U)
#define DDRC_DRAMTMG13_SHADOW_t_ppd_SHIFT        (0U)
/*! t_ppd - LPDDR4: tPPD: This is the minimum time from precharge to precharge command. When the
 *    controller is operating in 1:2 frequency ratio mode, program this to (tPPD/2) and round it up to
 *    the next integer value. Unit: Clocks.
 */
#define DDRC_DRAMTMG13_SHADOW_t_ppd(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG13_SHADOW_t_ppd_SHIFT)) & DDRC_DRAMTMG13_SHADOW_t_ppd_MASK)

#define DDRC_DRAMTMG13_SHADOW_t_ccd_mw_MASK      (0x3F0000U)
#define DDRC_DRAMTMG13_SHADOW_t_ccd_mw_SHIFT     (16U)
/*! t_ccd_mw - LPDDR4: tCCDMW: This is the minimum time from write or masked write to masked write
 *    command for same bank. When the controller is operating in 1:2 frequency ratio mode, program
 *    this to (tCCDMW/2) and round it up to the next integer value. Unit: Clocks.
 */
#define DDRC_DRAMTMG13_SHADOW_t_ccd_mw(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG13_SHADOW_t_ccd_mw_SHIFT)) & DDRC_DRAMTMG13_SHADOW_t_ccd_mw_MASK)

#define DDRC_DRAMTMG13_SHADOW_odtloff_MASK       (0x7F000000U)
#define DDRC_DRAMTMG13_SHADOW_odtloff_SHIFT      (24U)
/*! odtloff - LPDDR4: tODTLoff: This is the latency from CAS-2 command to tODToff reference. When
 *    the controller is operating in 1:2 frequency ratio mode, program this to (tODTLoff/2) and round
 *    it up to the next integer value. Unit: Clocks.
 */
#define DDRC_DRAMTMG13_SHADOW_odtloff(x)         (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG13_SHADOW_odtloff_SHIFT)) & DDRC_DRAMTMG13_SHADOW_odtloff_MASK)
/*! @} */

/*! @name DRAMTMG14_SHADOW - [SHADOW] SDRAM Timing Register 14 */
/*! @{ */

#define DDRC_DRAMTMG14_SHADOW_t_xsr_MASK         (0xFFFU)
#define DDRC_DRAMTMG14_SHADOW_t_xsr_SHIFT        (0U)
/*! t_xsr - tXSR: Exit Self Refresh to any command. When the controller is operating in 1:2
 *    frequency ratio mode, program this to the above value divided by 2 and round up to next integer value.
 *    Note: Used only for mDDR/LPDDR2/LPDDR3/LPDDR4 mode.
 */
#define DDRC_DRAMTMG14_SHADOW_t_xsr(x)           (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG14_SHADOW_t_xsr_SHIFT)) & DDRC_DRAMTMG14_SHADOW_t_xsr_MASK)
/*! @} */

/*! @name DRAMTMG15_SHADOW - [SHADOW] SDRAM Timing Register 15 */
/*! @{ */

#define DDRC_DRAMTMG15_SHADOW_t_stab_x32_MASK    (0xFFU)
#define DDRC_DRAMTMG15_SHADOW_t_stab_x32_SHIFT   (0U)
/*! t_stab_x32 - tSTAB: Stabilization time. It is required in the following two cases for DDR3/DDR4
 *    RDIMM : - when exiting power saving mode, if the clock was stopped, after re-enabling it the
 *    clock must be stable for a time specified by tSTAB - in the case of input clock frequency
 *    change (DDR4) - after issuing control words that refers to clock timing (Specification: 6us for
 *    DDR3, 5us for DDR4) When the controller is operating in 1:2 frequency ratio mode, program this to
 *    recommended value divided by two and round it up to next integer. Unit: Multiples of 32 clock
 *    cycles.
 */
#define DDRC_DRAMTMG15_SHADOW_t_stab_x32(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG15_SHADOW_t_stab_x32_SHIFT)) & DDRC_DRAMTMG15_SHADOW_t_stab_x32_MASK)

#define DDRC_DRAMTMG15_SHADOW_en_dfi_lp_t_stab_MASK (0x80000000U)
#define DDRC_DRAMTMG15_SHADOW_en_dfi_lp_t_stab_SHIFT (31U)
/*! en_dfi_lp_t_stab - - 1 - Enable using tSTAB when exiting DFI LP. Needs to be set when the PHY is
 *    stopping the clock during DFI LP to save maximum power. - 0 - Disable using tSTAB when
 *    exiting DFI LP
 */
#define DDRC_DRAMTMG15_SHADOW_en_dfi_lp_t_stab(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DRAMTMG15_SHADOW_en_dfi_lp_t_stab_SHIFT)) & DDRC_DRAMTMG15_SHADOW_en_dfi_lp_t_stab_MASK)
/*! @} */

/*! @name ZQCTL0_SHADOW - [SHADOW] ZQ Control Register 0 */
/*! @{ */

#define DDRC_ZQCTL0_SHADOW_t_zq_short_nop_MASK   (0x3FFU)
#define DDRC_ZQCTL0_SHADOW_t_zq_short_nop_SHIFT  (0U)
/*! t_zq_short_nop - tZQCS for DDR3/DD4/LPDDR2/LPDDR3, tZQLAT for LPDDR4: Number of DFI clock cycles
 *    of NOP required after a ZQCS (ZQ calibration short)/MPC(ZQ Latch) command is issued to SDRAM.
 *    When the controller is operating in 1:2 frequency ratio mode, program this to tZQCS/2 and
 *    round it up to the next integer value. This is only present for designs supporting DDR3/DDR4 or
 *    LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_ZQCTL0_SHADOW_t_zq_short_nop(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL0_SHADOW_t_zq_short_nop_SHIFT)) & DDRC_ZQCTL0_SHADOW_t_zq_short_nop_MASK)

#define DDRC_ZQCTL0_SHADOW_t_zq_long_nop_MASK    (0x7FF0000U)
#define DDRC_ZQCTL0_SHADOW_t_zq_long_nop_SHIFT   (16U)
/*! t_zq_long_nop - tZQoper for DDR3/DDR4, tZQCL for LPDDR2/LPDDR3, tZQCAL for LPDDR4: Number of DFI
 *    clock cycles of NOP required after a ZQCL (ZQ calibration long)/MPC(ZQ Start) command is
 *    issued to SDRAM. When the controller is operating in 1:2 frequency ratio mode: DDR3/DDR4: program
 *    this to tZQoper/2 and round it up to the next integer value. LPDDR2/LPDDR3: program this to
 *    tZQCL/2 and round it up to the next integer value. LPDDR4: program this to tZQCAL/2 and round it
 *    up to the next integer value. This is only present for designs supporting DDR3/DDR4 or
 *    LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_ZQCTL0_SHADOW_t_zq_long_nop(x)      (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL0_SHADOW_t_zq_long_nop_SHIFT)) & DDRC_ZQCTL0_SHADOW_t_zq_long_nop_MASK)

#define DDRC_ZQCTL0_SHADOW_dis_mpsmx_zqcl_MASK   (0x10000000U)
#define DDRC_ZQCTL0_SHADOW_dis_mpsmx_zqcl_SHIFT  (28U)
/*! dis_mpsmx_zqcl - - 1 - Disable issuing of ZQCL command at Maximum Power Saving Mode exit. Only
 *    applicable when run in DDR4 mode. - 0 - Enable issuing of ZQCL command at Maximum Power Saving
 *    Mode exit. Only applicable when run in DDR4 mode. This is only present for designs supporting
 *    DDR4 devices. Note: Do not issue ZQCL command at Maximum Power Save Mode exit if the
 *    DDRC_SHARED_AC configuration parameter is set. Program it to 1'b1. The software can send ZQCS after
 *    exiting MPSM mode.
 */
#define DDRC_ZQCTL0_SHADOW_dis_mpsmx_zqcl(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL0_SHADOW_dis_mpsmx_zqcl_SHIFT)) & DDRC_ZQCTL0_SHADOW_dis_mpsmx_zqcl_MASK)

#define DDRC_ZQCTL0_SHADOW_zq_resistor_shared_MASK (0x20000000U)
#define DDRC_ZQCTL0_SHADOW_zq_resistor_shared_SHIFT (29U)
/*! zq_resistor_shared - - 1 - Denotes that ZQ resistor is shared between ranks. Means
 *    ZQinit/ZQCL/ZQCS/MPC(ZQ calibration) commands are sent to one rank at a time with
 *    tZQinit/tZQCL/tZQCS/tZQCAL/tZQLAT timing met between commands so that commands to different ranks do not overlap. - 0 -
 *    ZQ resistor is not shared. This is only present for designs supporting DDR3/DDR4 or
 *    LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_ZQCTL0_SHADOW_zq_resistor_shared(x) (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL0_SHADOW_zq_resistor_shared_SHIFT)) & DDRC_ZQCTL0_SHADOW_zq_resistor_shared_MASK)

#define DDRC_ZQCTL0_SHADOW_dis_srx_zqcl_MASK     (0x40000000U)
#define DDRC_ZQCTL0_SHADOW_dis_srx_zqcl_SHIFT    (30U)
/*! dis_srx_zqcl - - 1 - Disable issuing of ZQCL/MPC(ZQ calibration) command at
 *    Self-Refresh/SR-Powerdown exit. Only applicable when run in DDR3 or DDR4 or LPDDR2 or LPDDR3 or LPDDR4 mode. - 0 -
 *    Enable issuing of ZQCL/MPC(ZQ calibration) command at Self-Refresh/SR-Powerdown exit. Only
 *    applicable when run in DDR3 or DDR4 or LPDDR2 or LPDDR3 or LPDDR4 mode. This is only present for
 *    designs supporting DDR3/DDR4 or LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_ZQCTL0_SHADOW_dis_srx_zqcl(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL0_SHADOW_dis_srx_zqcl_SHIFT)) & DDRC_ZQCTL0_SHADOW_dis_srx_zqcl_MASK)

#define DDRC_ZQCTL0_SHADOW_dis_auto_zq_MASK      (0x80000000U)
#define DDRC_ZQCTL0_SHADOW_dis_auto_zq_SHIFT     (31U)
/*! dis_auto_zq - - 1 - Disable DDRC generation of ZQCS/MPC(ZQ calibration) command. Register
 *    DBGCMD.zq_calib_short can be used instead to issue ZQ calibration request from APB module. - 0 -
 *    Internally generate ZQCS/MPC(ZQ calibration) commands based on ZQCTL1.t_zq_short_interval_x1024.
 *    This is only present for designs supporting DDR3/DDR4 or LPDDR2/LPDDR3/LPDDR4 devices.
 */
#define DDRC_ZQCTL0_SHADOW_dis_auto_zq(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_ZQCTL0_SHADOW_dis_auto_zq_SHIFT)) & DDRC_ZQCTL0_SHADOW_dis_auto_zq_MASK)
/*! @} */

/*! @name DFITMG0_SHADOW - [SHADOW] DFI Timing Register 0 */
/*! @{ */

#define DDRC_DFITMG0_SHADOW_dfi_tphy_wrlat_MASK  (0x3FU)
#define DDRC_DFITMG0_SHADOW_dfi_tphy_wrlat_SHIFT (0U)
/*! dfi_tphy_wrlat - Write latency Number of clocks from the write command to write data enable
 *    (dfi_wrdata_en). This corresponds to the DFI timing parameter tphy_wrlat. Refer to PHY
 *    specification for correct value.Note that, depending on the PHY, if using RDIMM/LRDIMM, it may be
 *    necessary to use the adjusted value of CL in the calculation of tphy_wrlat. This is to compensate for
 *    the extra cycle(s) of latency through the RDIMM/LRDIMM. Unit: DFI clock cycles or DFI PHY
 *    clock cycles, depending on DFITMG0.dfi_wrdata_use_sdr.
 */
#define DDRC_DFITMG0_SHADOW_dfi_tphy_wrlat(x)    (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG0_SHADOW_dfi_tphy_wrlat_SHIFT)) & DDRC_DFITMG0_SHADOW_dfi_tphy_wrlat_MASK)

#define DDRC_DFITMG0_SHADOW_dfi_tphy_wrdata_MASK (0x3F00U)
#define DDRC_DFITMG0_SHADOW_dfi_tphy_wrdata_SHIFT (8U)
/*! dfi_tphy_wrdata - Specifies the number of clock cycles between when dfi_wrdata_en is asserted to
 *    when the associated write data is driven on the dfi_wrdata signal. This corresponds to the
 *    DFI timing parameter tphy_wrdata. Refer to PHY specification for correct value. Note, max
 *    supported value is 8. Unit: DFI clock cycles or DFI PHY clock cycles, depending on
 *    DFITMG0.dfi_wrdata_use_sdr.
 */
#define DDRC_DFITMG0_SHADOW_dfi_tphy_wrdata(x)   (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG0_SHADOW_dfi_tphy_wrdata_SHIFT)) & DDRC_DFITMG0_SHADOW_dfi_tphy_wrdata_MASK)

#define DDRC_DFITMG0_SHADOW_dfi_wrdata_use_sdr_MASK (0x8000U)
#define DDRC_DFITMG0_SHADOW_dfi_wrdata_use_sdr_SHIFT (15U)
/*! dfi_wrdata_use_sdr - Defines whether dfi_wrdata_en/dfi_wrdata/dfi_wrdata_mask is generated using
 *    HDR (DFI clock) or SDR (DFI PHY clock) values Selects whether value in DFITMG0.dfi_tphy_wrlat
 *    is in terms of HDR (DFI clock) or SDR (DFI PHY clock) cycles Selects whether value in
 *    DFITMG0.dfi_tphy_wrdata is in terms of HDR (DFI clock) or SDR (DFI PHY clock) cycles - 0 in terms of
 *    HDR (DFI clock) cycles - 1 in terms of SDR (DFI PHY clock) cycles Refer to PHY specification
 *    for correct value.
 */
#define DDRC_DFITMG0_SHADOW_dfi_wrdata_use_sdr(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG0_SHADOW_dfi_wrdata_use_sdr_SHIFT)) & DDRC_DFITMG0_SHADOW_dfi_wrdata_use_sdr_MASK)

#define DDRC_DFITMG0_SHADOW_dfi_t_rddata_en_MASK (0x7F0000U)
#define DDRC_DFITMG0_SHADOW_dfi_t_rddata_en_SHIFT (16U)
/*! dfi_t_rddata_en - Time from the assertion of a read command on the DFI interface to the
 *    assertion of the dfi_rddata_en signal. Refer to PHY specification for correct value. This corresponds
 *    to the DFI parameter trddata_en. Note that, depending on the PHY, if using RDIMM/LRDIMM, it
 *    may be necessary to use the adjusted value of CL in the calculation of trddata_en. This is to
 *    compensate for the extra cycle(s) of latency through the RDIMM/LRDIMM. Unit: DFI clock cycles or
 *    DFI PHY clock cycles, depending on DFITMG0.dfi_rddata_use_sdr.
 */
#define DDRC_DFITMG0_SHADOW_dfi_t_rddata_en(x)   (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG0_SHADOW_dfi_t_rddata_en_SHIFT)) & DDRC_DFITMG0_SHADOW_dfi_t_rddata_en_MASK)

#define DDRC_DFITMG0_SHADOW_dfi_rddata_use_sdr_MASK (0x800000U)
#define DDRC_DFITMG0_SHADOW_dfi_rddata_use_sdr_SHIFT (23U)
/*! dfi_rddata_use_sdr - Defines whether dfi_rddata_en/dfi_rddata/dfi_rddata_valid is generated
 *    using HDR (DFI clock) or SDR (DFI PHY clock) values. Selects whether value in
 *    DFITMG0.dfi_t_rddata_en is in terms of HDR (DFI clock) or SDR (DFI PHY clock) cycles: - 0 in terms of HDR (DFI
 *    clock) cycles - 1 in terms of SDR (DFI PHY clock) cycles Refer to PHY specification for correct
 *    value.
 */
#define DDRC_DFITMG0_SHADOW_dfi_rddata_use_sdr(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG0_SHADOW_dfi_rddata_use_sdr_SHIFT)) & DDRC_DFITMG0_SHADOW_dfi_rddata_use_sdr_MASK)

#define DDRC_DFITMG0_SHADOW_dfi_t_ctrl_delay_MASK (0x1F000000U)
#define DDRC_DFITMG0_SHADOW_dfi_t_ctrl_delay_SHIFT (24U)
/*! dfi_t_ctrl_delay - Specifies the number of DFI clock cycles after an assertion or de-assertion
 *    of the DFI control signals that the control signals at the PHY-DRAM interface reflect the
 *    assertion or de-assertion. If the DFI clock and the memory clock are not phase-aligned, this timing
 *    parameter should be rounded up to the next integer value. Note that if using RDIMM/LRDIMM, it
 *    is necessary to increment this parameter by RDIMM's/LRDIMM's extra cycle of latency in terms
 *    of DFI clock.
 */
#define DDRC_DFITMG0_SHADOW_dfi_t_ctrl_delay(x)  (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG0_SHADOW_dfi_t_ctrl_delay_SHIFT)) & DDRC_DFITMG0_SHADOW_dfi_t_ctrl_delay_MASK)
/*! @} */

/*! @name DFITMG1_SHADOW - [SHADOW] DFI Timing Register 1 */
/*! @{ */

#define DDRC_DFITMG1_SHADOW_dfi_t_dram_clk_enable_MASK (0x1FU)
#define DDRC_DFITMG1_SHADOW_dfi_t_dram_clk_enable_SHIFT (0U)
/*! dfi_t_dram_clk_enable - Specifies the number of DFI clock cycles from the de-assertion of the
 *    dfi_dram_clk_disable signal on the DFI until the first valid rising edge of the clock to the
 *    DRAM memory devices, at the PHY-DRAM boundary. If the DFI clock and the memory clock are not
 *    phase aligned, this timing parameter should be rounded up to the next integer value.
 */
#define DDRC_DFITMG1_SHADOW_dfi_t_dram_clk_enable(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG1_SHADOW_dfi_t_dram_clk_enable_SHIFT)) & DDRC_DFITMG1_SHADOW_dfi_t_dram_clk_enable_MASK)

#define DDRC_DFITMG1_SHADOW_dfi_t_dram_clk_disable_MASK (0x1F00U)
#define DDRC_DFITMG1_SHADOW_dfi_t_dram_clk_disable_SHIFT (8U)
/*! dfi_t_dram_clk_disable - Specifies the number of DFI clock cycles from the assertion of the
 *    dfi_dram_clk_disable signal on the DFI until the clock to the DRAM memory devices, at the PHY-DRAM
 *    boundary, maintains a low value. If the DFI clock and the memory clock are not phase aligned,
 *    this timing parameter should be rounded up to the next integer value.
 */
#define DDRC_DFITMG1_SHADOW_dfi_t_dram_clk_disable(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG1_SHADOW_dfi_t_dram_clk_disable_SHIFT)) & DDRC_DFITMG1_SHADOW_dfi_t_dram_clk_disable_MASK)

#define DDRC_DFITMG1_SHADOW_dfi_t_wrdata_delay_MASK (0x1F0000U)
#define DDRC_DFITMG1_SHADOW_dfi_t_wrdata_delay_SHIFT (16U)
/*! dfi_t_wrdata_delay - Specifies the number of DFI clock cycles between when the dfi_wrdata_en
 *    signal is asserted and when the corresponding write data transfer is completed on the DRAM bus.
 *    This corresponds to the DFI timing parameter twrdata_delay. Refer to PHY specification for
 *    correct value. For DFI 3.0 PHY, set to twrdata_delay, a new timing parameter introduced in DFI
 *    3.0. For DFI 2.1 PHY, set to tphy_wrdata + (delay of DFI write data to the DRAM). Value to be
 *    programmed is in terms of DFI clocks, not PHY clocks. In FREQ_RATIO=2, divide PHY's value by 2
 *    and round up to next integer. If using DFITMG0.dfi_wrdata_use_sdr=1, add 1 to the value. Unit:
 *    Clocks
 */
#define DDRC_DFITMG1_SHADOW_dfi_t_wrdata_delay(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG1_SHADOW_dfi_t_wrdata_delay_SHIFT)) & DDRC_DFITMG1_SHADOW_dfi_t_wrdata_delay_MASK)

#define DDRC_DFITMG1_SHADOW_dfi_t_parin_lat_MASK (0x3000000U)
#define DDRC_DFITMG1_SHADOW_dfi_t_parin_lat_SHIFT (24U)
/*! dfi_t_parin_lat - Specifies the number of DFI PHY clock cycles between when the dfi_cs signal is
 *    asserted and when the associated dfi_parity_in signal is driven.
 */
#define DDRC_DFITMG1_SHADOW_dfi_t_parin_lat(x)   (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG1_SHADOW_dfi_t_parin_lat_SHIFT)) & DDRC_DFITMG1_SHADOW_dfi_t_parin_lat_MASK)

#define DDRC_DFITMG1_SHADOW_dfi_t_cmd_lat_MASK   (0xF0000000U)
#define DDRC_DFITMG1_SHADOW_dfi_t_cmd_lat_SHIFT  (28U)
/*! dfi_t_cmd_lat - Specifies the number of DFI PHY clock cycles between when the dfi_cs signal is
 *    asserted and when the associated command is driven. This field is used for CAL mode, should be
 *    set to '0' or the value which matches the CAL mode register setting in the DRAM. If the PHY
 *    can add the latency for CAL mode, this should be set to '0'. Valid Range: 0, 3, 4, 5, 6, and 8
 */
#define DDRC_DFITMG1_SHADOW_dfi_t_cmd_lat(x)     (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG1_SHADOW_dfi_t_cmd_lat_SHIFT)) & DDRC_DFITMG1_SHADOW_dfi_t_cmd_lat_MASK)
/*! @} */

/*! @name DFITMG2_SHADOW - [SHADOW] DFI Timing Register 2 */
/*! @{ */

#define DDRC_DFITMG2_SHADOW_dfi_tphy_wrcslat_MASK (0x3FU)
#define DDRC_DFITMG2_SHADOW_dfi_tphy_wrcslat_SHIFT (0U)
/*! dfi_tphy_wrcslat - Number of DFI PHY clock cycles between when a write command is sent on the
 *    DFI control interface and when the associated dfi_wrdata_cs signal is asserted. This corresponds
 *    to the DFI timing parameter tphy_wrcslat. Refer to PHY specification for correct value.
 */
#define DDRC_DFITMG2_SHADOW_dfi_tphy_wrcslat(x)  (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG2_SHADOW_dfi_tphy_wrcslat_SHIFT)) & DDRC_DFITMG2_SHADOW_dfi_tphy_wrcslat_MASK)

#define DDRC_DFITMG2_SHADOW_dfi_tphy_rdcslat_MASK (0x7F00U)
#define DDRC_DFITMG2_SHADOW_dfi_tphy_rdcslat_SHIFT (8U)
/*! dfi_tphy_rdcslat - Number of DFI PHY clock cycles between when a read command is sent on the DFI
 *    control interface and when the associated dfi_rddata_cs signal is asserted. This corresponds
 *    to the DFI timing parameter tphy_rdcslat. Refer to PHY specification for correct value.
 */
#define DDRC_DFITMG2_SHADOW_dfi_tphy_rdcslat(x)  (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG2_SHADOW_dfi_tphy_rdcslat_SHIFT)) & DDRC_DFITMG2_SHADOW_dfi_tphy_rdcslat_MASK)
/*! @} */

/*! @name DFITMG3_SHADOW - [SHADOW] DFI Timing Register 3 */
/*! @{ */

#define DDRC_DFITMG3_SHADOW_dfi_t_geardown_delay_MASK (0x1FU)
#define DDRC_DFITMG3_SHADOW_dfi_t_geardown_delay_SHIFT (0U)
/*! dfi_t_geardown_delay - The delay from dfi_geardown_en assertion to the time of the PHY being
 *    ready to receive commands. Refer to PHY specification for correct value. When the controller is
 *    operating in 1:2 frequency ratio mode, program this to (tgeardown_delay/2) and round it up to
 *    the next integer value. Unit: Clocks
 */
#define DDRC_DFITMG3_SHADOW_dfi_t_geardown_delay(x) (((uint32_t)(((uint32_t)(x)) << DDRC_DFITMG3_SHADOW_dfi_t_geardown_delay_SHIFT)) & DDRC_DFITMG3_SHADOW_dfi_t_geardown_delay_MASK)
/*! @} */

/*! @name ODTCFG_SHADOW - [SHADOW] ODT Configuration Register */
/*! @{ */

#define DDRC_ODTCFG_SHADOW_rd_odt_delay_MASK     (0x7CU)
#define DDRC_ODTCFG_SHADOW_rd_odt_delay_SHIFT    (2U)
/*! rd_odt_delay - The delay, in DFI PHY clock cycles, from issuing a read command to setting ODT
 *    values associated with that command. ODT setting must remain constant for the entire time that
 *    DQS is driven by the DDRC. Recommended values: DDR2: - CL + AL - 4 (not DDR2-1066), CL + AL - 5
 *    (DDR2-1066) If (CL + AL - 4 < 0), DDRC does not support ODT for read operation. DDR3: - CL -
 *    CWL DDR4: - CL - CWL - RD_PREAMBLE + WR_PREAMBLE + DFITMG1.dfi_t_cmd_lat (to adjust for CAL
 *    mode) WR_PREAMBLE = 1 (1tCK write preamble), 2 (2tCK write preamble) RD_PREAMBLE = 1 (1tCK write
 *    preamble), 2 (2tCK write preamble) If (CL - CWL - RD_PREAMBLE + WR_PREAMBLE) < 0, DDRC does
 *    not support ODT for read operation. LPDDR3: - RL + RD(tDQSCK(min)/tCK) - 1 - RU(tODTon(max)/tCK)
 */
#define DDRC_ODTCFG_SHADOW_rd_odt_delay(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_ODTCFG_SHADOW_rd_odt_delay_SHIFT)) & DDRC_ODTCFG_SHADOW_rd_odt_delay_MASK)

#define DDRC_ODTCFG_SHADOW_rd_odt_hold_MASK      (0xF00U)
#define DDRC_ODTCFG_SHADOW_rd_odt_hold_SHIFT     (8U)
/*! rd_odt_hold - DFI PHY clock cycles to hold ODT for a read command. The minimum supported value
 *    is 2. Recommended values: DDR2: - BL8: 0x6 (not DDR2-1066), 0x7 (DDR2-1066) - BL4: 0x4 (not
 *    DDR2-1066), 0x5 (DDR2-1066) DDR3: - BL8 - 0x6 DDR4: - BL8: 5 + RD_PREAMBLE RD_PREAMBLE = 1 (1tCK
 *    write preamble), 2 (2tCK write preamble) LPDDR3: - BL8: 5 + RU(tDQSCK(max)/tCK) -
 *    RD(tDQSCK(min)/tCK) + RU(tODTon(max)/tCK)
 */
#define DDRC_ODTCFG_SHADOW_rd_odt_hold(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_ODTCFG_SHADOW_rd_odt_hold_SHIFT)) & DDRC_ODTCFG_SHADOW_rd_odt_hold_MASK)

#define DDRC_ODTCFG_SHADOW_wr_odt_delay_MASK     (0x1F0000U)
#define DDRC_ODTCFG_SHADOW_wr_odt_delay_SHIFT    (16U)
/*! wr_odt_delay - The delay, in DFI PHY clock cycles, from issuing a write command to setting ODT
 *    values associated with that command. ODT setting must remain constant for the entire time that
 *    DQS is driven by the DDRC. Recommended values: DDR2: - CWL + AL - 3 (DDR2-400/533/667), CWL +
 *    AL - 4 (DDR2-800), CWL + AL - 5 (DDR2-1066) If (CWL + AL - 3 < 0), DDRC does not support ODT
 *    for write operation. DDR3: - 0x0 DDR4: - DFITMG1.dfi_t_cmd_lat (to adjust for CAL mode) LPDDR3:
 *    - WL - 1 - RU(tODTon(max)/tCK))
 */
#define DDRC_ODTCFG_SHADOW_wr_odt_delay(x)       (((uint32_t)(((uint32_t)(x)) << DDRC_ODTCFG_SHADOW_wr_odt_delay_SHIFT)) & DDRC_ODTCFG_SHADOW_wr_odt_delay_MASK)

#define DDRC_ODTCFG_SHADOW_wr_odt_hold_MASK      (0xF000000U)
#define DDRC_ODTCFG_SHADOW_wr_odt_hold_SHIFT     (24U)
/*! wr_odt_hold - DFI PHY clock cycles to hold ODT for a write command. The minimum supported value
 *    is 2. Recommended values: DDR2: - BL8: 0x5 (DDR2-400/533/667), 0x6 (DDR2-800), 0x7 (DDR2-1066)
 *    - BL4: 0x3 (DDR2-400/533/667), 0x4 (DDR2-800), 0x5 (DDR2-1066) DDR3: - BL8: 0x6 DDR4: - BL8:
 *    5 + WR_PREAMBLE + CRC_MODE WR_PREAMBLE = 1 (1tCK write preamble), 2 (2tCK write preamble)
 *    CRC_MODE = 0 (not CRC mode), 1 (CRC mode) LPDDR3: - BL8: 7 + RU(tODTon(max)/tCK)
 */
#define DDRC_ODTCFG_SHADOW_wr_odt_hold(x)        (((uint32_t)(((uint32_t)(x)) << DDRC_ODTCFG_SHADOW_wr_odt_hold_SHIFT)) & DDRC_ODTCFG_SHADOW_wr_odt_hold_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DDRC_Register_Masks */


/*!
 * @}
 */ /* end of group DDRC_Peripheral_Access_Layer */


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


#endif  /* PERI_DDRC_H_ */

