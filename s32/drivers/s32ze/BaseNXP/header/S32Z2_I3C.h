/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_I3C.h
 * @version 1.8
 * @date 2022-07-13
 * @brief Peripheral Access Layer for S32Z2_I3C
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
#if !defined(S32Z2_I3C_H_)  /* Check if memory map has not been already included */
#define S32Z2_I3C_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- I3C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I3C_Peripheral_Access_Layer I3C Peripheral Access Layer
 * @{
 */

/** I3C - Size of Registers Arrays */
#define I3C_SMAPCTRLN_COUNT                       3u

/** I3C - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCONFIG;                           /**< Master Configuration, offset: 0x0 */
  __IO uint32_t SCONFIG;                           /**< Slave Configuration, offset: 0x4 */
  __IO uint32_t SSTATUS;                           /**< Slave Status, offset: 0x8 */
  __IO uint32_t SCTRL;                             /**< Slave Control, offset: 0xC */
  __IO uint32_t SINTSET;                           /**< Slave Interrupt Set, offset: 0x10 */
  __IO uint32_t SINTCLR;                           /**< Slave Interrupt Clear, offset: 0x14 */
  __I  uint32_t SINTMASKED;                        /**< Slave Interrupt Mask, offset: 0x18 */
  __IO uint32_t SERRWARN;                          /**< Slave Errors and Warnings, offset: 0x1C */
  __IO uint32_t SDMACTRL;                          /**< Slave DMA Control, offset: 0x20 */
  __IO uint32_t SHDRBTCFG;                         /**< Slave HDR-BT Configuration, offset: 0x24 */
  __I  uint32_t SHDRBTLAST;                        /**< Slave HDR-Last, offset: 0x28 */
  __IO uint32_t SDATACTRL;                         /**< Slave Data Control, offset: 0x2C */
  __O  uint32_t SWDATAB;                           /**< Slave Write Data Byte, offset: 0x30 */
  __O  uint32_t SWDATABE;                          /**< Slave Write Data Byte End, offset: 0x34 */
  __O  uint32_t SWDATAH;                           /**< Slave Write Data Half-word, offset: 0x38 */
  __O  uint32_t SWDATAHE;                          /**< Slave Write Data Half-word End, offset: 0x3C */
  __I  uint32_t SRDATAB;                           /**< Slave Read Data Byte, offset: 0x40 */
  uint8_t RESERVED_0[4];
  __I  uint32_t SRDATAH;                           /**< Slave Read Data Half-word, offset: 0x48 */
  uint8_t RESERVED_1[16];
  __I  uint32_t SCAPABILITIES2;                    /**< Slave Capabilities 2, offset: 0x5C */
  __I  uint32_t SCAPABILITIES;                     /**< Slave Capabilities, offset: 0x60 */
  uint8_t RESERVED_2[4];
  __IO uint32_t SMAXLIMITS;                        /**< Slave Maximum Limits, offset: 0x68 */
  __IO uint32_t SIDPARTNO;                         /**< Slave ID Part Number, offset: 0x6C */
  __IO uint32_t SIDEXT;                            /**< Slave ID Extension, offset: 0x70 */
  __IO uint32_t SVENDORID;                         /**< Slave Vendor ID, offset: 0x74 */
  __IO uint32_t STCCLOCK;                          /**< Slave Time Control Clock, offset: 0x78 */
  __I  uint32_t SMSGLAST;                          /**< Slave Message Last Matched, offset: 0x7C */
  uint8_t RESERVED_3[4];
  __IO uint32_t MCTRL;                             /**< Master Control, offset: 0x84 */
  __IO uint32_t MSTATUS;                           /**< Master Status, offset: 0x88 */
  __IO uint32_t MIBIRULES;                         /**< Master In-band Interrupt Registry and Rules, offset: 0x8C */
  __IO uint32_t MINTSET;                           /**< Master Interrupt Set, offset: 0x90 */
  __IO uint32_t MINTCLR;                           /**< Master Interrupt Clear, offset: 0x94 */
  __I  uint32_t MINTMASKED;                        /**< Master Interrupt Mask, offset: 0x98 */
  __IO uint32_t MERRWARN;                          /**< Master Errors and Warnings, offset: 0x9C */
  __IO uint32_t MDMACTRL;                          /**< Master DMA Control, offset: 0xA0 */
  __IO uint32_t MHDRBTCFG;                         /**< Master HDR-BT Configuration, offset: 0xA4 */
  __I  uint32_t MHDRBTLAST;                        /**< Master HDR-Last, offset: 0xA8 */
  __IO uint32_t MDATACTRL;                         /**< Master Data Control, offset: 0xAC */
  __O  uint32_t MWDATAB;                           /**< Master Write Data Byte, offset: 0xB0 */
  __O  uint32_t MWDATABE;                          /**< Master Write Data Byte End, offset: 0xB4 */
  __O  uint32_t MWDATAH;                           /**< Master Write Data Half-word, offset: 0xB8 */
  __O  uint32_t MWDATAHE;                          /**< Master Write Data Byte End, offset: 0xBC */
  __I  uint32_t MRDATAB;                           /**< Master Read Data Byte, offset: 0xC0 */
  uint8_t RESERVED_4[4];
  __I  uint32_t MRDATAH;                           /**< Master Read Data Half-word, offset: 0xC8 */
  __O  uint32_t MWDATAB1;                          /**< Byte-only Write Byte Data (to bus), offset: 0xCC */
  union {                                          /* offset: 0xD0 */
    __O  uint32_t MWMSG_SDR_CONTROL;                 /**< Master Write Message in SDR mode, offset: 0xD0 */
    __O  uint32_t MWMSG_SDR_DATA;                    /**< Master Write Message Data in SDR mode, offset: 0xD0 */
  } MWMSG_SDR;
  __I  uint32_t MRMSG_SDR;                         /**< Master Read Message in SDR mode, offset: 0xD4 */
  union {                                          /* offset: 0xD8 */
    __O  uint32_t MWMSG_DDR_CONTROL;                 /**< Master Write Message in DDR mode, offset: 0xD8 */
    __O  uint32_t MWMSG_DDR_DATA;                    /**< Master Write Message Data in DDR mode, offset: 0xD8 */
  } MWMSG_DDR;
  __I  uint32_t MRMSG_DDR;                         /**< Master Read Message in DDR mode, offset: 0xDC */
  uint8_t RESERVED_5[4];
  __IO uint32_t MDYNADDR;                          /**< Master Dynamic Address, offset: 0xE4 */
  uint8_t RESERVED_6[8];
  __O  uint32_t MWDATAW;                           /**< Write Word Data (to bus), offset: 0xF0 */
  uint8_t RESERVED_7[4];
  __I  uint32_t MRDATAW;                           /**< Read Word Data (from bus), offset: 0xF8 */
  uint8_t RESERVED_8[4];
  __IO uint32_t SRSTACTTIME;                       /**< Timing Rules for SlaveReset Recovery, offset: 0x100 */
  uint8_t RESERVED_9[8];
  __IO uint32_t SCCCMASK;                          /**< CCC Mask for Unhandled CCCs, offset: 0x10C */
  __IO uint32_t SERRWARNMASK;                      /**< Slave Errors and Warnings Mask, offset: 0x110 */
  __I  uint32_t GROUPDEF;                          /**< Group Definitions, offset: 0x114 */
  uint8_t RESERVED_10[4];
  __I  uint32_t SMAPCTRL0;                         /**< Map Feature Control 0, offset: 0x11C */
  __IO uint32_t SMAPCTRL1;                         /**< Map Feature Control 1, offset: 0x120 */
  __IO uint32_t SMAPCTRL[I3C_SMAPCTRLN_COUNT];     /**< Map Feature Control, array offset: 0x124, array step: 0x4 */
  uint8_t RESERVED_11[16];
  __IO uint32_t IBIEXT1;                           /**< Extended IBI Data 1, offset: 0x140 */
  __IO uint32_t IBIEXT2;                           /**< Extended IBI Data 2, offset: 0x144 */
  uint8_t RESERVED_12[8];
  __O  uint32_t SWDATAW;                           /**< Slave Write Word Data (to bus), offset: 0x150 */
  uint8_t RESERVED_13[4];
  __I  uint32_t SRDATAW;                           /**< Slave Read Word Data (from bus), offset: 0x158 */
  uint8_t RESERVED_14[3732];
  __IO uint32_t SELFRESET;                         /**< Self Reset, offset: 0xFF0 */
} I3C_Type, *I3C_MemMapPtr;

/** Number of instances of the I3C module. */
#define I3C_INSTANCE_COUNT                       (3u)

/* I3C - Peripheral instance base addresses */
/** Peripheral I3C_0 base address */
#define IP_I3C_0_BASE                            (0x401D0000u)
/** Peripheral I3C_0 base pointer */
#define IP_I3C_0                                 ((I3C_Type *)IP_I3C_0_BASE)
/** Peripheral I3C_1 base address */
#define IP_I3C_1_BASE                            (0x409D0000u)
/** Peripheral I3C_1 base pointer */
#define IP_I3C_1                                 ((I3C_Type *)IP_I3C_1_BASE)
/** Peripheral I3C_2 base address */
#define IP_I3C_2_BASE                            (0x421D0000u)
/** Peripheral I3C_2 base pointer */
#define IP_I3C_2                                 ((I3C_Type *)IP_I3C_2_BASE)
/** Array initializer of I3C peripheral base addresses */
#define IP_I3C_BASE_ADDRS                        { IP_I3C_0_BASE, IP_I3C_1_BASE, IP_I3C_2_BASE }
/** Array initializer of I3C peripheral base pointers */
#define IP_I3C_BASE_PTRS                         { IP_I3C_0, IP_I3C_1, IP_I3C_2 }

/* ----------------------------------------------------------------------------
   -- I3C Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I3C_Register_Masks I3C Register Masks
 * @{
 */

/*! @name MCONFIG - Master Configuration */
/*! @{ */

#define I3C_MCONFIG_MSTENA_MASK                  (0x3U)
#define I3C_MCONFIG_MSTENA_SHIFT                 (0U)
#define I3C_MCONFIG_MSTENA_WIDTH                 (2U)
#define I3C_MCONFIG_MSTENA(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_MSTENA_SHIFT)) & I3C_MCONFIG_MSTENA_MASK)

#define I3C_MCONFIG_DISTO_MASK                   (0x8U)
#define I3C_MCONFIG_DISTO_SHIFT                  (3U)
#define I3C_MCONFIG_DISTO_WIDTH                  (1U)
#define I3C_MCONFIG_DISTO(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_DISTO_SHIFT)) & I3C_MCONFIG_DISTO_MASK)

#define I3C_MCONFIG_HKEEP_MASK                   (0x30U)
#define I3C_MCONFIG_HKEEP_SHIFT                  (4U)
#define I3C_MCONFIG_HKEEP_WIDTH                  (2U)
#define I3C_MCONFIG_HKEEP(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_HKEEP_SHIFT)) & I3C_MCONFIG_HKEEP_MASK)

#define I3C_MCONFIG_ODSTOP_MASK                  (0x40U)
#define I3C_MCONFIG_ODSTOP_SHIFT                 (6U)
#define I3C_MCONFIG_ODSTOP_WIDTH                 (1U)
#define I3C_MCONFIG_ODSTOP(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_ODSTOP_SHIFT)) & I3C_MCONFIG_ODSTOP_MASK)

#define I3C_MCONFIG_PPBAUD_MASK                  (0xF00U)
#define I3C_MCONFIG_PPBAUD_SHIFT                 (8U)
#define I3C_MCONFIG_PPBAUD_WIDTH                 (4U)
#define I3C_MCONFIG_PPBAUD(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_PPBAUD_SHIFT)) & I3C_MCONFIG_PPBAUD_MASK)

#define I3C_MCONFIG_PPLOW_MASK                   (0xF000U)
#define I3C_MCONFIG_PPLOW_SHIFT                  (12U)
#define I3C_MCONFIG_PPLOW_WIDTH                  (4U)
#define I3C_MCONFIG_PPLOW(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_PPLOW_SHIFT)) & I3C_MCONFIG_PPLOW_MASK)

#define I3C_MCONFIG_ODBAUD_MASK                  (0xFF0000U)
#define I3C_MCONFIG_ODBAUD_SHIFT                 (16U)
#define I3C_MCONFIG_ODBAUD_WIDTH                 (8U)
#define I3C_MCONFIG_ODBAUD(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_ODBAUD_SHIFT)) & I3C_MCONFIG_ODBAUD_MASK)

#define I3C_MCONFIG_ODHPP_MASK                   (0x1000000U)
#define I3C_MCONFIG_ODHPP_SHIFT                  (24U)
#define I3C_MCONFIG_ODHPP_WIDTH                  (1U)
#define I3C_MCONFIG_ODHPP(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_ODHPP_SHIFT)) & I3C_MCONFIG_ODHPP_MASK)

#define I3C_MCONFIG_SKEW_MASK                    (0xE000000U)
#define I3C_MCONFIG_SKEW_SHIFT                   (25U)
#define I3C_MCONFIG_SKEW_WIDTH                   (3U)
#define I3C_MCONFIG_SKEW(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_SKEW_SHIFT)) & I3C_MCONFIG_SKEW_MASK)

#define I3C_MCONFIG_I2CBAUD_MASK                 (0xF0000000U)
#define I3C_MCONFIG_I2CBAUD_SHIFT                (28U)
#define I3C_MCONFIG_I2CBAUD_WIDTH                (4U)
#define I3C_MCONFIG_I2CBAUD(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MCONFIG_I2CBAUD_SHIFT)) & I3C_MCONFIG_I2CBAUD_MASK)
/*! @} */

/*! @name SCONFIG - Slave Configuration */
/*! @{ */

#define I3C_SCONFIG_SLVENA_MASK                  (0x1U)
#define I3C_SCONFIG_SLVENA_SHIFT                 (0U)
#define I3C_SCONFIG_SLVENA_WIDTH                 (1U)
#define I3C_SCONFIG_SLVENA(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_SLVENA_SHIFT)) & I3C_SCONFIG_SLVENA_MASK)

#define I3C_SCONFIG_NACK_MASK                    (0x2U)
#define I3C_SCONFIG_NACK_SHIFT                   (1U)
#define I3C_SCONFIG_NACK_WIDTH                   (1U)
#define I3C_SCONFIG_NACK(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_NACK_SHIFT)) & I3C_SCONFIG_NACK_MASK)

#define I3C_SCONFIG_MATCHSS_MASK                 (0x4U)
#define I3C_SCONFIG_MATCHSS_SHIFT                (2U)
#define I3C_SCONFIG_MATCHSS_WIDTH                (1U)
#define I3C_SCONFIG_MATCHSS(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_MATCHSS_SHIFT)) & I3C_SCONFIG_MATCHSS_MASK)

#define I3C_SCONFIG_S0IGNORE_MASK                (0x8U)
#define I3C_SCONFIG_S0IGNORE_SHIFT               (3U)
#define I3C_SCONFIG_S0IGNORE_WIDTH               (1U)
#define I3C_SCONFIG_S0IGNORE(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_S0IGNORE_SHIFT)) & I3C_SCONFIG_S0IGNORE_MASK)

#define I3C_SCONFIG_HDROK_MASK                   (0x10U)
#define I3C_SCONFIG_HDROK_SHIFT                  (4U)
#define I3C_SCONFIG_HDROK_WIDTH                  (1U)
#define I3C_SCONFIG_HDROK(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_HDROK_SHIFT)) & I3C_SCONFIG_HDROK_MASK)

#define I3C_SCONFIG_BTML_MASK                    (0x60U)
#define I3C_SCONFIG_BTML_SHIFT                   (5U)
#define I3C_SCONFIG_BTML_WIDTH                   (2U)
#define I3C_SCONFIG_BTML(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_BTML_SHIFT)) & I3C_SCONFIG_BTML_MASK)

#define I3C_SCONFIG_OFFLINE_MASK                 (0x200U)
#define I3C_SCONFIG_OFFLINE_SHIFT                (9U)
#define I3C_SCONFIG_OFFLINE_WIDTH                (1U)
#define I3C_SCONFIG_OFFLINE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_OFFLINE_SHIFT)) & I3C_SCONFIG_OFFLINE_MASK)

#define I3C_SCONFIG_BAMATCH_MASK                 (0x3F0000U)
#define I3C_SCONFIG_BAMATCH_SHIFT                (16U)
#define I3C_SCONFIG_BAMATCH_WIDTH                (6U)
#define I3C_SCONFIG_BAMATCH(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_BAMATCH_SHIFT)) & I3C_SCONFIG_BAMATCH_MASK)

#define I3C_SCONFIG_SADDR_MASK                   (0xFE000000U)
#define I3C_SCONFIG_SADDR_SHIFT                  (25U)
#define I3C_SCONFIG_SADDR_WIDTH                  (7U)
#define I3C_SCONFIG_SADDR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SCONFIG_SADDR_SHIFT)) & I3C_SCONFIG_SADDR_MASK)
/*! @} */

/*! @name SSTATUS - Slave Status */
/*! @{ */

#define I3C_SSTATUS_STNOTSTOP_MASK               (0x1U)
#define I3C_SSTATUS_STNOTSTOP_SHIFT              (0U)
#define I3C_SSTATUS_STNOTSTOP_WIDTH              (1U)
#define I3C_SSTATUS_STNOTSTOP(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STNOTSTOP_SHIFT)) & I3C_SSTATUS_STNOTSTOP_MASK)

#define I3C_SSTATUS_STMSG_MASK                   (0x2U)
#define I3C_SSTATUS_STMSG_SHIFT                  (1U)
#define I3C_SSTATUS_STMSG_WIDTH                  (1U)
#define I3C_SSTATUS_STMSG(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STMSG_SHIFT)) & I3C_SSTATUS_STMSG_MASK)

#define I3C_SSTATUS_STCCCH_MASK                  (0x4U)
#define I3C_SSTATUS_STCCCH_SHIFT                 (2U)
#define I3C_SSTATUS_STCCCH_WIDTH                 (1U)
#define I3C_SSTATUS_STCCCH(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STCCCH_SHIFT)) & I3C_SSTATUS_STCCCH_MASK)

#define I3C_SSTATUS_STREQRD_MASK                 (0x8U)
#define I3C_SSTATUS_STREQRD_SHIFT                (3U)
#define I3C_SSTATUS_STREQRD_WIDTH                (1U)
#define I3C_SSTATUS_STREQRD(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STREQRD_SHIFT)) & I3C_SSTATUS_STREQRD_MASK)

#define I3C_SSTATUS_STREQWR_MASK                 (0x10U)
#define I3C_SSTATUS_STREQWR_SHIFT                (4U)
#define I3C_SSTATUS_STREQWR_WIDTH                (1U)
#define I3C_SSTATUS_STREQWR(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STREQWR_SHIFT)) & I3C_SSTATUS_STREQWR_MASK)

#define I3C_SSTATUS_STDAA_MASK                   (0x20U)
#define I3C_SSTATUS_STDAA_SHIFT                  (5U)
#define I3C_SSTATUS_STDAA_WIDTH                  (1U)
#define I3C_SSTATUS_STDAA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STDAA_SHIFT)) & I3C_SSTATUS_STDAA_MASK)

#define I3C_SSTATUS_STHDR_MASK                   (0x40U)
#define I3C_SSTATUS_STHDR_SHIFT                  (6U)
#define I3C_SSTATUS_STHDR_WIDTH                  (1U)
#define I3C_SSTATUS_STHDR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STHDR_SHIFT)) & I3C_SSTATUS_STHDR_MASK)

#define I3C_SSTATUS_START_MASK                   (0x100U)
#define I3C_SSTATUS_START_SHIFT                  (8U)
#define I3C_SSTATUS_START_WIDTH                  (1U)
#define I3C_SSTATUS_START(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_START_SHIFT)) & I3C_SSTATUS_START_MASK)

#define I3C_SSTATUS_MATCHED_MASK                 (0x200U)
#define I3C_SSTATUS_MATCHED_SHIFT                (9U)
#define I3C_SSTATUS_MATCHED_WIDTH                (1U)
#define I3C_SSTATUS_MATCHED(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_MATCHED_SHIFT)) & I3C_SSTATUS_MATCHED_MASK)

#define I3C_SSTATUS_STOP_MASK                    (0x400U)
#define I3C_SSTATUS_STOP_SHIFT                   (10U)
#define I3C_SSTATUS_STOP_WIDTH                   (1U)
#define I3C_SSTATUS_STOP(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_STOP_SHIFT)) & I3C_SSTATUS_STOP_MASK)

#define I3C_SSTATUS_RX_PEND_MASK                 (0x800U)
#define I3C_SSTATUS_RX_PEND_SHIFT                (11U)
#define I3C_SSTATUS_RX_PEND_WIDTH                (1U)
#define I3C_SSTATUS_RX_PEND(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_RX_PEND_SHIFT)) & I3C_SSTATUS_RX_PEND_MASK)

#define I3C_SSTATUS_TXNOTFULL_MASK               (0x1000U)
#define I3C_SSTATUS_TXNOTFULL_SHIFT              (12U)
#define I3C_SSTATUS_TXNOTFULL_WIDTH              (1U)
#define I3C_SSTATUS_TXNOTFULL(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_TXNOTFULL_SHIFT)) & I3C_SSTATUS_TXNOTFULL_MASK)

#define I3C_SSTATUS_DACHG_MASK                   (0x2000U)
#define I3C_SSTATUS_DACHG_SHIFT                  (13U)
#define I3C_SSTATUS_DACHG_WIDTH                  (1U)
#define I3C_SSTATUS_DACHG(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_DACHG_SHIFT)) & I3C_SSTATUS_DACHG_MASK)

#define I3C_SSTATUS_CCC_MASK                     (0x4000U)
#define I3C_SSTATUS_CCC_SHIFT                    (14U)
#define I3C_SSTATUS_CCC_WIDTH                    (1U)
#define I3C_SSTATUS_CCC(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_CCC_SHIFT)) & I3C_SSTATUS_CCC_MASK)

#define I3C_SSTATUS_ERRWARN_MASK                 (0x8000U)
#define I3C_SSTATUS_ERRWARN_SHIFT                (15U)
#define I3C_SSTATUS_ERRWARN_WIDTH                (1U)
#define I3C_SSTATUS_ERRWARN(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_ERRWARN_SHIFT)) & I3C_SSTATUS_ERRWARN_MASK)

#define I3C_SSTATUS_HDRMATCH_MASK                (0x10000U)
#define I3C_SSTATUS_HDRMATCH_SHIFT               (16U)
#define I3C_SSTATUS_HDRMATCH_WIDTH               (1U)
#define I3C_SSTATUS_HDRMATCH(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_HDRMATCH_SHIFT)) & I3C_SSTATUS_HDRMATCH_MASK)

#define I3C_SSTATUS_CHANDLED_MASK                (0x20000U)
#define I3C_SSTATUS_CHANDLED_SHIFT               (17U)
#define I3C_SSTATUS_CHANDLED_WIDTH               (1U)
#define I3C_SSTATUS_CHANDLED(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_CHANDLED_SHIFT)) & I3C_SSTATUS_CHANDLED_MASK)

#define I3C_SSTATUS_EVENT_MASK                   (0x40000U)
#define I3C_SSTATUS_EVENT_SHIFT                  (18U)
#define I3C_SSTATUS_EVENT_WIDTH                  (1U)
#define I3C_SSTATUS_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_EVENT_SHIFT)) & I3C_SSTATUS_EVENT_MASK)

#define I3C_SSTATUS_SLVRST_MASK                  (0x80000U)
#define I3C_SSTATUS_SLVRST_SHIFT                 (19U)
#define I3C_SSTATUS_SLVRST_WIDTH                 (1U)
#define I3C_SSTATUS_SLVRST(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_SLVRST_SHIFT)) & I3C_SSTATUS_SLVRST_MASK)

#define I3C_SSTATUS_EVDET_MASK                   (0x300000U)
#define I3C_SSTATUS_EVDET_SHIFT                  (20U)
#define I3C_SSTATUS_EVDET_WIDTH                  (2U)
#define I3C_SSTATUS_EVDET(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_EVDET_SHIFT)) & I3C_SSTATUS_EVDET_MASK)

#define I3C_SSTATUS_IBIDIS_MASK                  (0x1000000U)
#define I3C_SSTATUS_IBIDIS_SHIFT                 (24U)
#define I3C_SSTATUS_IBIDIS_WIDTH                 (1U)
#define I3C_SSTATUS_IBIDIS(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_IBIDIS_SHIFT)) & I3C_SSTATUS_IBIDIS_MASK)

#define I3C_SSTATUS_MRDIS_MASK                   (0x2000000U)
#define I3C_SSTATUS_MRDIS_SHIFT                  (25U)
#define I3C_SSTATUS_MRDIS_WIDTH                  (1U)
#define I3C_SSTATUS_MRDIS(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_MRDIS_SHIFT)) & I3C_SSTATUS_MRDIS_MASK)

#define I3C_SSTATUS_HJDIS_MASK                   (0x8000000U)
#define I3C_SSTATUS_HJDIS_SHIFT                  (27U)
#define I3C_SSTATUS_HJDIS_WIDTH                  (1U)
#define I3C_SSTATUS_HJDIS(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_HJDIS_SHIFT)) & I3C_SSTATUS_HJDIS_MASK)

#define I3C_SSTATUS_ACTSTATE_MASK                (0x30000000U)
#define I3C_SSTATUS_ACTSTATE_SHIFT               (28U)
#define I3C_SSTATUS_ACTSTATE_WIDTH               (2U)
#define I3C_SSTATUS_ACTSTATE(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_ACTSTATE_SHIFT)) & I3C_SSTATUS_ACTSTATE_MASK)

#define I3C_SSTATUS_TIMECTRL_MASK                (0xC0000000U)
#define I3C_SSTATUS_TIMECTRL_SHIFT               (30U)
#define I3C_SSTATUS_TIMECTRL_WIDTH               (2U)
#define I3C_SSTATUS_TIMECTRL(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SSTATUS_TIMECTRL_SHIFT)) & I3C_SSTATUS_TIMECTRL_MASK)
/*! @} */

/*! @name SCTRL - Slave Control */
/*! @{ */

#define I3C_SCTRL_EVENT_MASK                     (0x3U)
#define I3C_SCTRL_EVENT_SHIFT                    (0U)
#define I3C_SCTRL_EVENT_WIDTH                    (2U)
#define I3C_SCTRL_EVENT(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SCTRL_EVENT_SHIFT)) & I3C_SCTRL_EVENT_MASK)

#define I3C_SCTRL_EXTDATA_MASK                   (0x8U)
#define I3C_SCTRL_EXTDATA_SHIFT                  (3U)
#define I3C_SCTRL_EXTDATA_WIDTH                  (1U)
#define I3C_SCTRL_EXTDATA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SCTRL_EXTDATA_SHIFT)) & I3C_SCTRL_EXTDATA_MASK)

#define I3C_SCTRL_MAPIDX_MASK                    (0x70U)
#define I3C_SCTRL_MAPIDX_SHIFT                   (4U)
#define I3C_SCTRL_MAPIDX_WIDTH                   (3U)
#define I3C_SCTRL_MAPIDX(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SCTRL_MAPIDX_SHIFT)) & I3C_SCTRL_MAPIDX_MASK)

#define I3C_SCTRL_IBIDATA_MASK                   (0xFF00U)
#define I3C_SCTRL_IBIDATA_SHIFT                  (8U)
#define I3C_SCTRL_IBIDATA_WIDTH                  (8U)
#define I3C_SCTRL_IBIDATA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SCTRL_IBIDATA_SHIFT)) & I3C_SCTRL_IBIDATA_MASK)

#define I3C_SCTRL_PENDINT_MASK                   (0xF0000U)
#define I3C_SCTRL_PENDINT_SHIFT                  (16U)
#define I3C_SCTRL_PENDINT_WIDTH                  (4U)
#define I3C_SCTRL_PENDINT(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SCTRL_PENDINT_SHIFT)) & I3C_SCTRL_PENDINT_MASK)

#define I3C_SCTRL_ACTSTATE_MASK                  (0x300000U)
#define I3C_SCTRL_ACTSTATE_SHIFT                 (20U)
#define I3C_SCTRL_ACTSTATE_WIDTH                 (2U)
#define I3C_SCTRL_ACTSTATE(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SCTRL_ACTSTATE_SHIFT)) & I3C_SCTRL_ACTSTATE_MASK)

#define I3C_SCTRL_VENDINFO_MASK                  (0xFF000000U)
#define I3C_SCTRL_VENDINFO_SHIFT                 (24U)
#define I3C_SCTRL_VENDINFO_WIDTH                 (8U)
#define I3C_SCTRL_VENDINFO(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SCTRL_VENDINFO_SHIFT)) & I3C_SCTRL_VENDINFO_MASK)
/*! @} */

/*! @name SINTSET - Slave Interrupt Set */
/*! @{ */

#define I3C_SINTSET_START_MASK                   (0x100U)
#define I3C_SINTSET_START_SHIFT                  (8U)
#define I3C_SINTSET_START_WIDTH                  (1U)
#define I3C_SINTSET_START(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_START_SHIFT)) & I3C_SINTSET_START_MASK)

#define I3C_SINTSET_MATCHED_MASK                 (0x200U)
#define I3C_SINTSET_MATCHED_SHIFT                (9U)
#define I3C_SINTSET_MATCHED_WIDTH                (1U)
#define I3C_SINTSET_MATCHED(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_MATCHED_SHIFT)) & I3C_SINTSET_MATCHED_MASK)

#define I3C_SINTSET_STOP_MASK                    (0x400U)
#define I3C_SINTSET_STOP_SHIFT                   (10U)
#define I3C_SINTSET_STOP_WIDTH                   (1U)
#define I3C_SINTSET_STOP(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_STOP_SHIFT)) & I3C_SINTSET_STOP_MASK)

#define I3C_SINTSET_RXPEND_MASK                  (0x800U)
#define I3C_SINTSET_RXPEND_SHIFT                 (11U)
#define I3C_SINTSET_RXPEND_WIDTH                 (1U)
#define I3C_SINTSET_RXPEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_RXPEND_SHIFT)) & I3C_SINTSET_RXPEND_MASK)

#define I3C_SINTSET_TXSEND_MASK                  (0x1000U)
#define I3C_SINTSET_TXSEND_SHIFT                 (12U)
#define I3C_SINTSET_TXSEND_WIDTH                 (1U)
#define I3C_SINTSET_TXSEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_TXSEND_SHIFT)) & I3C_SINTSET_TXSEND_MASK)

#define I3C_SINTSET_DACHG_MASK                   (0x2000U)
#define I3C_SINTSET_DACHG_SHIFT                  (13U)
#define I3C_SINTSET_DACHG_WIDTH                  (1U)
#define I3C_SINTSET_DACHG(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_DACHG_SHIFT)) & I3C_SINTSET_DACHG_MASK)

#define I3C_SINTSET_CCC_MASK                     (0x4000U)
#define I3C_SINTSET_CCC_SHIFT                    (14U)
#define I3C_SINTSET_CCC_WIDTH                    (1U)
#define I3C_SINTSET_CCC(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_CCC_SHIFT)) & I3C_SINTSET_CCC_MASK)

#define I3C_SINTSET_ERRWARN_MASK                 (0x8000U)
#define I3C_SINTSET_ERRWARN_SHIFT                (15U)
#define I3C_SINTSET_ERRWARN_WIDTH                (1U)
#define I3C_SINTSET_ERRWARN(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_ERRWARN_SHIFT)) & I3C_SINTSET_ERRWARN_MASK)

#define I3C_SINTSET_DDRMATCHED_MASK              (0x10000U)
#define I3C_SINTSET_DDRMATCHED_SHIFT             (16U)
#define I3C_SINTSET_DDRMATCHED_WIDTH             (1U)
#define I3C_SINTSET_DDRMATCHED(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_DDRMATCHED_SHIFT)) & I3C_SINTSET_DDRMATCHED_MASK)

#define I3C_SINTSET_CHANDLED_MASK                (0x20000U)
#define I3C_SINTSET_CHANDLED_SHIFT               (17U)
#define I3C_SINTSET_CHANDLED_WIDTH               (1U)
#define I3C_SINTSET_CHANDLED(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_CHANDLED_SHIFT)) & I3C_SINTSET_CHANDLED_MASK)

#define I3C_SINTSET_EVENT_MASK                   (0x40000U)
#define I3C_SINTSET_EVENT_SHIFT                  (18U)
#define I3C_SINTSET_EVENT_WIDTH                  (1U)
#define I3C_SINTSET_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_EVENT_SHIFT)) & I3C_SINTSET_EVENT_MASK)

#define I3C_SINTSET_SLVRST_MASK                  (0x80000U)
#define I3C_SINTSET_SLVRST_SHIFT                 (19U)
#define I3C_SINTSET_SLVRST_WIDTH                 (1U)
#define I3C_SINTSET_SLVRST(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SINTSET_SLVRST_SHIFT)) & I3C_SINTSET_SLVRST_MASK)
/*! @} */

/*! @name SINTCLR - Slave Interrupt Clear */
/*! @{ */

#define I3C_SINTCLR_START_MASK                   (0x100U)
#define I3C_SINTCLR_START_SHIFT                  (8U)
#define I3C_SINTCLR_START_WIDTH                  (1U)
#define I3C_SINTCLR_START(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_START_SHIFT)) & I3C_SINTCLR_START_MASK)

#define I3C_SINTCLR_MATCHED_MASK                 (0x200U)
#define I3C_SINTCLR_MATCHED_SHIFT                (9U)
#define I3C_SINTCLR_MATCHED_WIDTH                (1U)
#define I3C_SINTCLR_MATCHED(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_MATCHED_SHIFT)) & I3C_SINTCLR_MATCHED_MASK)

#define I3C_SINTCLR_STOP_MASK                    (0x400U)
#define I3C_SINTCLR_STOP_SHIFT                   (10U)
#define I3C_SINTCLR_STOP_WIDTH                   (1U)
#define I3C_SINTCLR_STOP(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_STOP_SHIFT)) & I3C_SINTCLR_STOP_MASK)

#define I3C_SINTCLR_RXPEND_MASK                  (0x800U)
#define I3C_SINTCLR_RXPEND_SHIFT                 (11U)
#define I3C_SINTCLR_RXPEND_WIDTH                 (1U)
#define I3C_SINTCLR_RXPEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_RXPEND_SHIFT)) & I3C_SINTCLR_RXPEND_MASK)

#define I3C_SINTCLR_TXSEND_MASK                  (0x1000U)
#define I3C_SINTCLR_TXSEND_SHIFT                 (12U)
#define I3C_SINTCLR_TXSEND_WIDTH                 (1U)
#define I3C_SINTCLR_TXSEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_TXSEND_SHIFT)) & I3C_SINTCLR_TXSEND_MASK)

#define I3C_SINTCLR_DACHG_MASK                   (0x2000U)
#define I3C_SINTCLR_DACHG_SHIFT                  (13U)
#define I3C_SINTCLR_DACHG_WIDTH                  (1U)
#define I3C_SINTCLR_DACHG(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_DACHG_SHIFT)) & I3C_SINTCLR_DACHG_MASK)

#define I3C_SINTCLR_CCC_MASK                     (0x4000U)
#define I3C_SINTCLR_CCC_SHIFT                    (14U)
#define I3C_SINTCLR_CCC_WIDTH                    (1U)
#define I3C_SINTCLR_CCC(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_CCC_SHIFT)) & I3C_SINTCLR_CCC_MASK)

#define I3C_SINTCLR_ERRWARN_MASK                 (0x8000U)
#define I3C_SINTCLR_ERRWARN_SHIFT                (15U)
#define I3C_SINTCLR_ERRWARN_WIDTH                (1U)
#define I3C_SINTCLR_ERRWARN(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_ERRWARN_SHIFT)) & I3C_SINTCLR_ERRWARN_MASK)

#define I3C_SINTCLR_DDRMATCHED_MASK              (0x10000U)
#define I3C_SINTCLR_DDRMATCHED_SHIFT             (16U)
#define I3C_SINTCLR_DDRMATCHED_WIDTH             (1U)
#define I3C_SINTCLR_DDRMATCHED(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_DDRMATCHED_SHIFT)) & I3C_SINTCLR_DDRMATCHED_MASK)

#define I3C_SINTCLR_CHANDLED_MASK                (0x20000U)
#define I3C_SINTCLR_CHANDLED_SHIFT               (17U)
#define I3C_SINTCLR_CHANDLED_WIDTH               (1U)
#define I3C_SINTCLR_CHANDLED(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_CHANDLED_SHIFT)) & I3C_SINTCLR_CHANDLED_MASK)

#define I3C_SINTCLR_EVENT_MASK                   (0x40000U)
#define I3C_SINTCLR_EVENT_SHIFT                  (18U)
#define I3C_SINTCLR_EVENT_WIDTH                  (1U)
#define I3C_SINTCLR_EVENT(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_EVENT_SHIFT)) & I3C_SINTCLR_EVENT_MASK)

#define I3C_SINTCLR_SLVRST_MASK                  (0x80000U)
#define I3C_SINTCLR_SLVRST_SHIFT                 (19U)
#define I3C_SINTCLR_SLVRST_WIDTH                 (1U)
#define I3C_SINTCLR_SLVRST(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SINTCLR_SLVRST_SHIFT)) & I3C_SINTCLR_SLVRST_MASK)
/*! @} */

/*! @name SINTMASKED - Slave Interrupt Mask */
/*! @{ */

#define I3C_SINTMASKED_START_MASK                (0x100U)
#define I3C_SINTMASKED_START_SHIFT               (8U)
#define I3C_SINTMASKED_START_WIDTH               (1U)
#define I3C_SINTMASKED_START(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_START_SHIFT)) & I3C_SINTMASKED_START_MASK)

#define I3C_SINTMASKED_MATCHED_MASK              (0x200U)
#define I3C_SINTMASKED_MATCHED_SHIFT             (9U)
#define I3C_SINTMASKED_MATCHED_WIDTH             (1U)
#define I3C_SINTMASKED_MATCHED(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_MATCHED_SHIFT)) & I3C_SINTMASKED_MATCHED_MASK)

#define I3C_SINTMASKED_STOP_MASK                 (0x400U)
#define I3C_SINTMASKED_STOP_SHIFT                (10U)
#define I3C_SINTMASKED_STOP_WIDTH                (1U)
#define I3C_SINTMASKED_STOP(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_STOP_SHIFT)) & I3C_SINTMASKED_STOP_MASK)

#define I3C_SINTMASKED_RXPEND_MASK               (0x800U)
#define I3C_SINTMASKED_RXPEND_SHIFT              (11U)
#define I3C_SINTMASKED_RXPEND_WIDTH              (1U)
#define I3C_SINTMASKED_RXPEND(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_RXPEND_SHIFT)) & I3C_SINTMASKED_RXPEND_MASK)

#define I3C_SINTMASKED_TXSEND_MASK               (0x1000U)
#define I3C_SINTMASKED_TXSEND_SHIFT              (12U)
#define I3C_SINTMASKED_TXSEND_WIDTH              (1U)
#define I3C_SINTMASKED_TXSEND(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_TXSEND_SHIFT)) & I3C_SINTMASKED_TXSEND_MASK)

#define I3C_SINTMASKED_DACHG_MASK                (0x2000U)
#define I3C_SINTMASKED_DACHG_SHIFT               (13U)
#define I3C_SINTMASKED_DACHG_WIDTH               (1U)
#define I3C_SINTMASKED_DACHG(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_DACHG_SHIFT)) & I3C_SINTMASKED_DACHG_MASK)

#define I3C_SINTMASKED_CCC_MASK                  (0x4000U)
#define I3C_SINTMASKED_CCC_SHIFT                 (14U)
#define I3C_SINTMASKED_CCC_WIDTH                 (1U)
#define I3C_SINTMASKED_CCC(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_CCC_SHIFT)) & I3C_SINTMASKED_CCC_MASK)

#define I3C_SINTMASKED_ERRWARN_MASK              (0x8000U)
#define I3C_SINTMASKED_ERRWARN_SHIFT             (15U)
#define I3C_SINTMASKED_ERRWARN_WIDTH             (1U)
#define I3C_SINTMASKED_ERRWARN(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_ERRWARN_SHIFT)) & I3C_SINTMASKED_ERRWARN_MASK)

#define I3C_SINTMASKED_DDRMATCHED_MASK           (0x10000U)
#define I3C_SINTMASKED_DDRMATCHED_SHIFT          (16U)
#define I3C_SINTMASKED_DDRMATCHED_WIDTH          (1U)
#define I3C_SINTMASKED_DDRMATCHED(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_DDRMATCHED_SHIFT)) & I3C_SINTMASKED_DDRMATCHED_MASK)

#define I3C_SINTMASKED_CHANDLED_MASK             (0x20000U)
#define I3C_SINTMASKED_CHANDLED_SHIFT            (17U)
#define I3C_SINTMASKED_CHANDLED_WIDTH            (1U)
#define I3C_SINTMASKED_CHANDLED(x)               (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_CHANDLED_SHIFT)) & I3C_SINTMASKED_CHANDLED_MASK)

#define I3C_SINTMASKED_EVENT_MASK                (0x40000U)
#define I3C_SINTMASKED_EVENT_SHIFT               (18U)
#define I3C_SINTMASKED_EVENT_WIDTH               (1U)
#define I3C_SINTMASKED_EVENT(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SINTMASKED_EVENT_SHIFT)) & I3C_SINTMASKED_EVENT_MASK)
/*! @} */

/*! @name SERRWARN - Slave Errors and Warnings */
/*! @{ */

#define I3C_SERRWARN_ORUN_MASK                   (0x1U)
#define I3C_SERRWARN_ORUN_SHIFT                  (0U)
#define I3C_SERRWARN_ORUN_WIDTH                  (1U)
#define I3C_SERRWARN_ORUN(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_ORUN_SHIFT)) & I3C_SERRWARN_ORUN_MASK)

#define I3C_SERRWARN_URUN_MASK                   (0x2U)
#define I3C_SERRWARN_URUN_SHIFT                  (1U)
#define I3C_SERRWARN_URUN_WIDTH                  (1U)
#define I3C_SERRWARN_URUN(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_URUN_SHIFT)) & I3C_SERRWARN_URUN_MASK)

#define I3C_SERRWARN_URUNNACK_MASK               (0x4U)
#define I3C_SERRWARN_URUNNACK_SHIFT              (2U)
#define I3C_SERRWARN_URUNNACK_WIDTH              (1U)
#define I3C_SERRWARN_URUNNACK(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_URUNNACK_SHIFT)) & I3C_SERRWARN_URUNNACK_MASK)

#define I3C_SERRWARN_TERM_MASK                   (0x8U)
#define I3C_SERRWARN_TERM_SHIFT                  (3U)
#define I3C_SERRWARN_TERM_WIDTH                  (1U)
#define I3C_SERRWARN_TERM(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_TERM_SHIFT)) & I3C_SERRWARN_TERM_MASK)

#define I3C_SERRWARN_INVSTART_MASK               (0x10U)
#define I3C_SERRWARN_INVSTART_SHIFT              (4U)
#define I3C_SERRWARN_INVSTART_WIDTH              (1U)
#define I3C_SERRWARN_INVSTART(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_INVSTART_SHIFT)) & I3C_SERRWARN_INVSTART_MASK)

#define I3C_SERRWARN_SPAR_MASK                   (0x100U)
#define I3C_SERRWARN_SPAR_SHIFT                  (8U)
#define I3C_SERRWARN_SPAR_WIDTH                  (1U)
#define I3C_SERRWARN_SPAR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_SPAR_SHIFT)) & I3C_SERRWARN_SPAR_MASK)

#define I3C_SERRWARN_HPAR_MASK                   (0x200U)
#define I3C_SERRWARN_HPAR_SHIFT                  (9U)
#define I3C_SERRWARN_HPAR_WIDTH                  (1U)
#define I3C_SERRWARN_HPAR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_HPAR_SHIFT)) & I3C_SERRWARN_HPAR_MASK)

#define I3C_SERRWARN_HCRC_MASK                   (0x400U)
#define I3C_SERRWARN_HCRC_SHIFT                  (10U)
#define I3C_SERRWARN_HCRC_WIDTH                  (1U)
#define I3C_SERRWARN_HCRC(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_HCRC_SHIFT)) & I3C_SERRWARN_HCRC_MASK)

#define I3C_SERRWARN_S0S1_MASK                   (0x800U)
#define I3C_SERRWARN_S0S1_SHIFT                  (11U)
#define I3C_SERRWARN_S0S1_WIDTH                  (1U)
#define I3C_SERRWARN_S0S1(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_S0S1_SHIFT)) & I3C_SERRWARN_S0S1_MASK)

#define I3C_SERRWARN_HNOVERIFY_MASK              (0x1000U)
#define I3C_SERRWARN_HNOVERIFY_SHIFT             (12U)
#define I3C_SERRWARN_HNOVERIFY_WIDTH             (1U)
#define I3C_SERRWARN_HNOVERIFY(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_HNOVERIFY_SHIFT)) & I3C_SERRWARN_HNOVERIFY_MASK)

#define I3C_SERRWARN_HINVREQ_MASK                (0x2000U)
#define I3C_SERRWARN_HINVREQ_SHIFT               (13U)
#define I3C_SERRWARN_HINVREQ_WIDTH               (1U)
#define I3C_SERRWARN_HINVREQ(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_HINVREQ_SHIFT)) & I3C_SERRWARN_HINVREQ_MASK)

#define I3C_SERRWARN_OREAD_MASK                  (0x10000U)
#define I3C_SERRWARN_OREAD_SHIFT                 (16U)
#define I3C_SERRWARN_OREAD_WIDTH                 (1U)
#define I3C_SERRWARN_OREAD(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_OREAD_SHIFT)) & I3C_SERRWARN_OREAD_MASK)

#define I3C_SERRWARN_OWRITE_MASK                 (0x20000U)
#define I3C_SERRWARN_OWRITE_SHIFT                (17U)
#define I3C_SERRWARN_OWRITE_WIDTH                (1U)
#define I3C_SERRWARN_OWRITE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_OWRITE_SHIFT)) & I3C_SERRWARN_OWRITE_MASK)

#define I3C_SERRWARN_WRONGSIZE_MASK              (0x200000U)
#define I3C_SERRWARN_WRONGSIZE_SHIFT             (21U)
#define I3C_SERRWARN_WRONGSIZE_WIDTH             (1U)
#define I3C_SERRWARN_WRONGSIZE(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARN_WRONGSIZE_SHIFT)) & I3C_SERRWARN_WRONGSIZE_MASK)
/*! @} */

/*! @name SDMACTRL - Slave DMA Control */
/*! @{ */

#define I3C_SDMACTRL_DMAFB_MASK                  (0x3U)
#define I3C_SDMACTRL_DMAFB_SHIFT                 (0U)
#define I3C_SDMACTRL_DMAFB_WIDTH                 (2U)
#define I3C_SDMACTRL_DMAFB(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SDMACTRL_DMAFB_SHIFT)) & I3C_SDMACTRL_DMAFB_MASK)

#define I3C_SDMACTRL_DMATB_MASK                  (0xCU)
#define I3C_SDMACTRL_DMATB_SHIFT                 (2U)
#define I3C_SDMACTRL_DMATB_WIDTH                 (2U)
#define I3C_SDMACTRL_DMATB(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SDMACTRL_DMATB_SHIFT)) & I3C_SDMACTRL_DMATB_MASK)

#define I3C_SDMACTRL_DMAWIDTH_MASK               (0x30U)
#define I3C_SDMACTRL_DMAWIDTH_SHIFT              (4U)
#define I3C_SDMACTRL_DMAWIDTH_WIDTH              (2U)
#define I3C_SDMACTRL_DMAWIDTH(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SDMACTRL_DMAWIDTH_SHIFT)) & I3C_SDMACTRL_DMAWIDTH_MASK)
/*! @} */

/*! @name SHDRBTCFG - Slave HDR-BT Configuration */
/*! @{ */

#define I3C_SHDRBTCFG_CRC32_MASK                 (0x4U)
#define I3C_SHDRBTCFG_CRC32_SHIFT                (2U)
#define I3C_SHDRBTCFG_CRC32_WIDTH                (1U)
#define I3C_SHDRBTCFG_CRC32(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SHDRBTCFG_CRC32_SHIFT)) & I3C_SHDRBTCFG_CRC32_MASK)

#define I3C_SHDRBTCFG_WDATAMAX_MASK              (0xFFF0U)
#define I3C_SHDRBTCFG_WDATAMAX_SHIFT             (4U)
#define I3C_SHDRBTCFG_WDATAMAX_WIDTH             (12U)
#define I3C_SHDRBTCFG_WDATAMAX(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SHDRBTCFG_WDATAMAX_SHIFT)) & I3C_SHDRBTCFG_WDATAMAX_MASK)

#define I3C_SHDRBTCFG_DATALEN_MASK               (0xFFFF0000U)
#define I3C_SHDRBTCFG_DATALEN_SHIFT              (16U)
#define I3C_SHDRBTCFG_DATALEN_WIDTH              (16U)
#define I3C_SHDRBTCFG_DATALEN(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SHDRBTCFG_DATALEN_SHIFT)) & I3C_SHDRBTCFG_DATALEN_MASK)
/*! @} */

/*! @name SHDRBTLAST - Slave HDR-Last */
/*! @{ */

#define I3C_SHDRBTLAST_DATALEN_MASK              (0xFFFF0000U)
#define I3C_SHDRBTLAST_DATALEN_SHIFT             (16U)
#define I3C_SHDRBTLAST_DATALEN_WIDTH             (16U)
#define I3C_SHDRBTLAST_DATALEN(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SHDRBTLAST_DATALEN_SHIFT)) & I3C_SHDRBTLAST_DATALEN_MASK)
/*! @} */

/*! @name SDATACTRL - Slave Data Control */
/*! @{ */

#define I3C_SDATACTRL_FLUSHTB_MASK               (0x1U)
#define I3C_SDATACTRL_FLUSHTB_SHIFT              (0U)
#define I3C_SDATACTRL_FLUSHTB_WIDTH              (1U)
#define I3C_SDATACTRL_FLUSHTB(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_FLUSHTB_SHIFT)) & I3C_SDATACTRL_FLUSHTB_MASK)

#define I3C_SDATACTRL_FLUSHFB_MASK               (0x2U)
#define I3C_SDATACTRL_FLUSHFB_SHIFT              (1U)
#define I3C_SDATACTRL_FLUSHFB_WIDTH              (1U)
#define I3C_SDATACTRL_FLUSHFB(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_FLUSHFB_SHIFT)) & I3C_SDATACTRL_FLUSHFB_MASK)

#define I3C_SDATACTRL_UNLOCK_MASK                (0x8U)
#define I3C_SDATACTRL_UNLOCK_SHIFT               (3U)
#define I3C_SDATACTRL_UNLOCK_WIDTH               (1U)
#define I3C_SDATACTRL_UNLOCK(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_UNLOCK_SHIFT)) & I3C_SDATACTRL_UNLOCK_MASK)

#define I3C_SDATACTRL_TXTRIG_MASK                (0x30U)
#define I3C_SDATACTRL_TXTRIG_SHIFT               (4U)
#define I3C_SDATACTRL_TXTRIG_WIDTH               (2U)
#define I3C_SDATACTRL_TXTRIG(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_TXTRIG_SHIFT)) & I3C_SDATACTRL_TXTRIG_MASK)

#define I3C_SDATACTRL_RXTRIG_MASK                (0xC0U)
#define I3C_SDATACTRL_RXTRIG_SHIFT               (6U)
#define I3C_SDATACTRL_RXTRIG_WIDTH               (2U)
#define I3C_SDATACTRL_RXTRIG(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_RXTRIG_SHIFT)) & I3C_SDATACTRL_RXTRIG_MASK)

#define I3C_SDATACTRL_TXCOUNT_MASK               (0x1F0000U)
#define I3C_SDATACTRL_TXCOUNT_SHIFT              (16U)
#define I3C_SDATACTRL_TXCOUNT_WIDTH              (5U)
#define I3C_SDATACTRL_TXCOUNT(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_TXCOUNT_SHIFT)) & I3C_SDATACTRL_TXCOUNT_MASK)

#define I3C_SDATACTRL_RXCOUNT_MASK               (0x1F000000U)
#define I3C_SDATACTRL_RXCOUNT_SHIFT              (24U)
#define I3C_SDATACTRL_RXCOUNT_WIDTH              (5U)
#define I3C_SDATACTRL_RXCOUNT(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_RXCOUNT_SHIFT)) & I3C_SDATACTRL_RXCOUNT_MASK)

#define I3C_SDATACTRL_TXFULL_MASK                (0x40000000U)
#define I3C_SDATACTRL_TXFULL_SHIFT               (30U)
#define I3C_SDATACTRL_TXFULL_WIDTH               (1U)
#define I3C_SDATACTRL_TXFULL(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_TXFULL_SHIFT)) & I3C_SDATACTRL_TXFULL_MASK)

#define I3C_SDATACTRL_RXEMPTY_MASK               (0x80000000U)
#define I3C_SDATACTRL_RXEMPTY_SHIFT              (31U)
#define I3C_SDATACTRL_RXEMPTY_WIDTH              (1U)
#define I3C_SDATACTRL_RXEMPTY(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SDATACTRL_RXEMPTY_SHIFT)) & I3C_SDATACTRL_RXEMPTY_MASK)
/*! @} */

/*! @name SWDATAB - Slave Write Data Byte */
/*! @{ */

#define I3C_SWDATAB_DATA_MASK                    (0xFFU)
#define I3C_SWDATAB_DATA_SHIFT                   (0U)
#define I3C_SWDATAB_DATA_WIDTH                   (8U)
#define I3C_SWDATAB_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAB_DATA_SHIFT)) & I3C_SWDATAB_DATA_MASK)

#define I3C_SWDATAB_END_MASK                     (0x100U)
#define I3C_SWDATAB_END_SHIFT                    (8U)
#define I3C_SWDATAB_END_WIDTH                    (1U)
#define I3C_SWDATAB_END(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAB_END_SHIFT)) & I3C_SWDATAB_END_MASK)

#define I3C_SWDATAB_END_ALSO_MASK                (0x10000U)
#define I3C_SWDATAB_END_ALSO_SHIFT               (16U)
#define I3C_SWDATAB_END_ALSO_WIDTH               (1U)
#define I3C_SWDATAB_END_ALSO(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAB_END_ALSO_SHIFT)) & I3C_SWDATAB_END_ALSO_MASK)
/*! @} */

/*! @name SWDATABE - Slave Write Data Byte End */
/*! @{ */

#define I3C_SWDATABE_DATA_MASK                   (0xFFU)
#define I3C_SWDATABE_DATA_SHIFT                  (0U)
#define I3C_SWDATABE_DATA_WIDTH                  (8U)
#define I3C_SWDATABE_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SWDATABE_DATA_SHIFT)) & I3C_SWDATABE_DATA_MASK)
/*! @} */

/*! @name SWDATAH - Slave Write Data Half-word */
/*! @{ */

#define I3C_SWDATAH_DATA0_MASK                   (0xFFU)
#define I3C_SWDATAH_DATA0_SHIFT                  (0U)
#define I3C_SWDATAH_DATA0_WIDTH                  (8U)
#define I3C_SWDATAH_DATA0(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAH_DATA0_SHIFT)) & I3C_SWDATAH_DATA0_MASK)

#define I3C_SWDATAH_DATA1_MASK                   (0xFF00U)
#define I3C_SWDATAH_DATA1_SHIFT                  (8U)
#define I3C_SWDATAH_DATA1_WIDTH                  (8U)
#define I3C_SWDATAH_DATA1(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAH_DATA1_SHIFT)) & I3C_SWDATAH_DATA1_MASK)

#define I3C_SWDATAH_END_MASK                     (0x10000U)
#define I3C_SWDATAH_END_SHIFT                    (16U)
#define I3C_SWDATAH_END_WIDTH                    (1U)
#define I3C_SWDATAH_END(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAH_END_SHIFT)) & I3C_SWDATAH_END_MASK)
/*! @} */

/*! @name SWDATAHE - Slave Write Data Half-word End */
/*! @{ */

#define I3C_SWDATAHE_DATA0_MASK                  (0xFFU)
#define I3C_SWDATAHE_DATA0_SHIFT                 (0U)
#define I3C_SWDATAHE_DATA0_WIDTH                 (8U)
#define I3C_SWDATAHE_DATA0(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAHE_DATA0_SHIFT)) & I3C_SWDATAHE_DATA0_MASK)

#define I3C_SWDATAHE_DATA1_MASK                  (0xFF00U)
#define I3C_SWDATAHE_DATA1_SHIFT                 (8U)
#define I3C_SWDATAHE_DATA1_WIDTH                 (8U)
#define I3C_SWDATAHE_DATA1(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAHE_DATA1_SHIFT)) & I3C_SWDATAHE_DATA1_MASK)
/*! @} */

/*! @name SRDATAB - Slave Read Data Byte */
/*! @{ */

#define I3C_SRDATAB_DATA0_MASK                   (0xFFU)
#define I3C_SRDATAB_DATA0_SHIFT                  (0U)
#define I3C_SRDATAB_DATA0_WIDTH                  (8U)
#define I3C_SRDATAB_DATA0(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SRDATAB_DATA0_SHIFT)) & I3C_SRDATAB_DATA0_MASK)
/*! @} */

/*! @name SRDATAH - Slave Read Data Half-word */
/*! @{ */

#define I3C_SRDATAH_LSB_MASK                     (0xFFU)
#define I3C_SRDATAH_LSB_SHIFT                    (0U)
#define I3C_SRDATAH_LSB_WIDTH                    (8U)
#define I3C_SRDATAH_LSB(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SRDATAH_LSB_SHIFT)) & I3C_SRDATAH_LSB_MASK)

#define I3C_SRDATAH_MSB_MASK                     (0xFF00U)
#define I3C_SRDATAH_MSB_SHIFT                    (8U)
#define I3C_SRDATAH_MSB_WIDTH                    (8U)
#define I3C_SRDATAH_MSB(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_SRDATAH_MSB_SHIFT)) & I3C_SRDATAH_MSB_MASK)
/*! @} */

/*! @name SCAPABILITIES2 - Slave Capabilities 2 */
/*! @{ */

#define I3C_SCAPABILITIES2_MAPCNT_MASK           (0xFU)
#define I3C_SCAPABILITIES2_MAPCNT_SHIFT          (0U)
#define I3C_SCAPABILITIES2_MAPCNT_WIDTH          (4U)
#define I3C_SCAPABILITIES2_MAPCNT(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_MAPCNT_SHIFT)) & I3C_SCAPABILITIES2_MAPCNT_MASK)

#define I3C_SCAPABILITIES2_I2C10B_MASK           (0x10U)
#define I3C_SCAPABILITIES2_I2C10B_SHIFT          (4U)
#define I3C_SCAPABILITIES2_I2C10B_WIDTH          (1U)
#define I3C_SCAPABILITIES2_I2C10B(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_I2C10B_SHIFT)) & I3C_SCAPABILITIES2_I2C10B_MASK)

#define I3C_SCAPABILITIES2_I2CRST_MASK           (0x20U)
#define I3C_SCAPABILITIES2_I2CRST_SHIFT          (5U)
#define I3C_SCAPABILITIES2_I2CRST_WIDTH          (1U)
#define I3C_SCAPABILITIES2_I2CRST(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_I2CRST_SHIFT)) & I3C_SCAPABILITIES2_I2CRST_MASK)

#define I3C_SCAPABILITIES2_I2CDEVID_MASK         (0x40U)
#define I3C_SCAPABILITIES2_I2CDEVID_SHIFT        (6U)
#define I3C_SCAPABILITIES2_I2CDEVID_WIDTH        (1U)
#define I3C_SCAPABILITIES2_I2CDEVID(x)           (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_I2CDEVID_SHIFT)) & I3C_SCAPABILITIES2_I2CDEVID_MASK)

#define I3C_SCAPABILITIES2_DATA32_MASK           (0x80U)
#define I3C_SCAPABILITIES2_DATA32_SHIFT          (7U)
#define I3C_SCAPABILITIES2_DATA32_WIDTH          (1U)
#define I3C_SCAPABILITIES2_DATA32(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_DATA32_SHIFT)) & I3C_SCAPABILITIES2_DATA32_MASK)

#define I3C_SCAPABILITIES2_IBIEXT_MASK           (0x100U)
#define I3C_SCAPABILITIES2_IBIEXT_SHIFT          (8U)
#define I3C_SCAPABILITIES2_IBIEXT_WIDTH          (1U)
#define I3C_SCAPABILITIES2_IBIEXT(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_IBIEXT_SHIFT)) & I3C_SCAPABILITIES2_IBIEXT_MASK)

#define I3C_SCAPABILITIES2_IBIXREG_MASK          (0x200U)
#define I3C_SCAPABILITIES2_IBIXREG_SHIFT         (9U)
#define I3C_SCAPABILITIES2_IBIXREG_WIDTH         (1U)
#define I3C_SCAPABILITIES2_IBIXREG(x)            (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_IBIXREG_SHIFT)) & I3C_SCAPABILITIES2_IBIXREG_MASK)

#define I3C_SCAPABILITIES2_SMLANE_MASK           (0x3000U)
#define I3C_SCAPABILITIES2_SMLANE_SHIFT          (12U)
#define I3C_SCAPABILITIES2_SMLANE_WIDTH          (2U)
#define I3C_SCAPABILITIES2_SMLANE(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_SMLANE_SHIFT)) & I3C_SCAPABILITIES2_SMLANE_MASK)

#define I3C_SCAPABILITIES2_V1_1_MASK             (0x10000U)
#define I3C_SCAPABILITIES2_V1_1_SHIFT            (16U)
#define I3C_SCAPABILITIES2_V1_1_WIDTH            (1U)
#define I3C_SCAPABILITIES2_V1_1(x)               (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_V1_1_SHIFT)) & I3C_SCAPABILITIES2_V1_1_MASK)

#define I3C_SCAPABILITIES2_SLVRST_MASK           (0x20000U)
#define I3C_SCAPABILITIES2_SLVRST_SHIFT          (17U)
#define I3C_SCAPABILITIES2_SLVRST_WIDTH          (1U)
#define I3C_SCAPABILITIES2_SLVRST(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_SLVRST_SHIFT)) & I3C_SCAPABILITIES2_SLVRST_MASK)

#define I3C_SCAPABILITIES2_GROUP_MASK            (0xC0000U)
#define I3C_SCAPABILITIES2_GROUP_SHIFT           (18U)
#define I3C_SCAPABILITIES2_GROUP_WIDTH           (2U)
#define I3C_SCAPABILITIES2_GROUP(x)              (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_GROUP_SHIFT)) & I3C_SCAPABILITIES2_GROUP_MASK)

#define I3C_SCAPABILITIES2_AASA_MASK             (0x200000U)
#define I3C_SCAPABILITIES2_AASA_SHIFT            (21U)
#define I3C_SCAPABILITIES2_AASA_WIDTH            (1U)
#define I3C_SCAPABILITIES2_AASA(x)               (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_AASA_SHIFT)) & I3C_SCAPABILITIES2_AASA_MASK)

#define I3C_SCAPABILITIES2_SSTSUB_MASK           (0x400000U)
#define I3C_SCAPABILITIES2_SSTSUB_SHIFT          (22U)
#define I3C_SCAPABILITIES2_SSTSUB_WIDTH          (1U)
#define I3C_SCAPABILITIES2_SSTSUB(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_SSTSUB_SHIFT)) & I3C_SCAPABILITIES2_SSTSUB_MASK)

#define I3C_SCAPABILITIES2_SSTWR_MASK            (0x800000U)
#define I3C_SCAPABILITIES2_SSTWR_SHIFT           (23U)
#define I3C_SCAPABILITIES2_SSTWR_WIDTH           (1U)
#define I3C_SCAPABILITIES2_SSTWR(x)              (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES2_SSTWR_SHIFT)) & I3C_SCAPABILITIES2_SSTWR_MASK)
/*! @} */

/*! @name SCAPABILITIES - Slave Capabilities */
/*! @{ */

#define I3C_SCAPABILITIES_IDENA_MASK             (0x3U)
#define I3C_SCAPABILITIES_IDENA_SHIFT            (0U)
#define I3C_SCAPABILITIES_IDENA_WIDTH            (2U)
#define I3C_SCAPABILITIES_IDENA(x)               (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_IDENA_SHIFT)) & I3C_SCAPABILITIES_IDENA_MASK)

#define I3C_SCAPABILITIES_IDREG_MASK             (0x3CU)
#define I3C_SCAPABILITIES_IDREG_SHIFT            (2U)
#define I3C_SCAPABILITIES_IDREG_WIDTH            (4U)
#define I3C_SCAPABILITIES_IDREG(x)               (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_IDREG_SHIFT)) & I3C_SCAPABILITIES_IDREG_MASK)

#define I3C_SCAPABILITIES_HDRSUPP_MASK           (0x1C0U)
#define I3C_SCAPABILITIES_HDRSUPP_SHIFT          (6U)
#define I3C_SCAPABILITIES_HDRSUPP_WIDTH          (3U)
#define I3C_SCAPABILITIES_HDRSUPP(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_HDRSUPP_SHIFT)) & I3C_SCAPABILITIES_HDRSUPP_MASK)

#define I3C_SCAPABILITIES_MASTER_MASK            (0x200U)
#define I3C_SCAPABILITIES_MASTER_SHIFT           (9U)
#define I3C_SCAPABILITIES_MASTER_WIDTH           (1U)
#define I3C_SCAPABILITIES_MASTER(x)              (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_MASTER_SHIFT)) & I3C_SCAPABILITIES_MASTER_MASK)

#define I3C_SCAPABILITIES_SADDR_MASK             (0xC00U)
#define I3C_SCAPABILITIES_SADDR_SHIFT            (10U)
#define I3C_SCAPABILITIES_SADDR_WIDTH            (2U)
#define I3C_SCAPABILITIES_SADDR(x)               (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_SADDR_SHIFT)) & I3C_SCAPABILITIES_SADDR_MASK)

#define I3C_SCAPABILITIES_CCCHANDLE_MASK         (0xF000U)
#define I3C_SCAPABILITIES_CCCHANDLE_SHIFT        (12U)
#define I3C_SCAPABILITIES_CCCHANDLE_WIDTH        (4U)
#define I3C_SCAPABILITIES_CCCHANDLE(x)           (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_CCCHANDLE_SHIFT)) & I3C_SCAPABILITIES_CCCHANDLE_MASK)

#define I3C_SCAPABILITIES_IBI_MR_HJ_MASK         (0x1F0000U)
#define I3C_SCAPABILITIES_IBI_MR_HJ_SHIFT        (16U)
#define I3C_SCAPABILITIES_IBI_MR_HJ_WIDTH        (5U)
#define I3C_SCAPABILITIES_IBI_MR_HJ(x)           (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_IBI_MR_HJ_SHIFT)) & I3C_SCAPABILITIES_IBI_MR_HJ_MASK)

#define I3C_SCAPABILITIES_TIMECTRL_MASK          (0x200000U)
#define I3C_SCAPABILITIES_TIMECTRL_SHIFT         (21U)
#define I3C_SCAPABILITIES_TIMECTRL_WIDTH         (1U)
#define I3C_SCAPABILITIES_TIMECTRL(x)            (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_TIMECTRL_SHIFT)) & I3C_SCAPABILITIES_TIMECTRL_MASK)

#define I3C_SCAPABILITIES_EXTFIFO_MASK           (0x3800000U)
#define I3C_SCAPABILITIES_EXTFIFO_SHIFT          (23U)
#define I3C_SCAPABILITIES_EXTFIFO_WIDTH          (3U)
#define I3C_SCAPABILITIES_EXTFIFO(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_EXTFIFO_SHIFT)) & I3C_SCAPABILITIES_EXTFIFO_MASK)

#define I3C_SCAPABILITIES_FIFOTX_MASK            (0xC000000U)
#define I3C_SCAPABILITIES_FIFOTX_SHIFT           (26U)
#define I3C_SCAPABILITIES_FIFOTX_WIDTH           (2U)
#define I3C_SCAPABILITIES_FIFOTX(x)              (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_FIFOTX_SHIFT)) & I3C_SCAPABILITIES_FIFOTX_MASK)

#define I3C_SCAPABILITIES_FIFORX_MASK            (0x30000000U)
#define I3C_SCAPABILITIES_FIFORX_SHIFT           (28U)
#define I3C_SCAPABILITIES_FIFORX_WIDTH           (2U)
#define I3C_SCAPABILITIES_FIFORX(x)              (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_FIFORX_SHIFT)) & I3C_SCAPABILITIES_FIFORX_MASK)

#define I3C_SCAPABILITIES_INT_MASK               (0x40000000U)
#define I3C_SCAPABILITIES_INT_SHIFT              (30U)
#define I3C_SCAPABILITIES_INT_WIDTH              (1U)
#define I3C_SCAPABILITIES_INT(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_INT_SHIFT)) & I3C_SCAPABILITIES_INT_MASK)

#define I3C_SCAPABILITIES_DMA_MASK               (0x80000000U)
#define I3C_SCAPABILITIES_DMA_SHIFT              (31U)
#define I3C_SCAPABILITIES_DMA_WIDTH              (1U)
#define I3C_SCAPABILITIES_DMA(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SCAPABILITIES_DMA_SHIFT)) & I3C_SCAPABILITIES_DMA_MASK)
/*! @} */

/*! @name SMAXLIMITS - Slave Maximum Limits */
/*! @{ */

#define I3C_SMAXLIMITS_MAXRD_MASK                (0xFFFU)
#define I3C_SMAXLIMITS_MAXRD_SHIFT               (0U)
#define I3C_SMAXLIMITS_MAXRD_WIDTH               (12U)
#define I3C_SMAXLIMITS_MAXRD(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SMAXLIMITS_MAXRD_SHIFT)) & I3C_SMAXLIMITS_MAXRD_MASK)

#define I3C_SMAXLIMITS_MAXWR_MASK                (0xFFF0000U)
#define I3C_SMAXLIMITS_MAXWR_SHIFT               (16U)
#define I3C_SMAXLIMITS_MAXWR_WIDTH               (12U)
#define I3C_SMAXLIMITS_MAXWR(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SMAXLIMITS_MAXWR_SHIFT)) & I3C_SMAXLIMITS_MAXWR_MASK)
/*! @} */

/*! @name SIDPARTNO - Slave ID Part Number */
/*! @{ */

#define I3C_SIDPARTNO_PARTNO_MASK                (0xFFFFFFFFU)
#define I3C_SIDPARTNO_PARTNO_SHIFT               (0U)
#define I3C_SIDPARTNO_PARTNO_WIDTH               (32U)
#define I3C_SIDPARTNO_PARTNO(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SIDPARTNO_PARTNO_SHIFT)) & I3C_SIDPARTNO_PARTNO_MASK)
/*! @} */

/*! @name SIDEXT - Slave ID Extension */
/*! @{ */

#define I3C_SIDEXT_DCR_MASK                      (0xFF00U)
#define I3C_SIDEXT_DCR_SHIFT                     (8U)
#define I3C_SIDEXT_DCR_WIDTH                     (8U)
#define I3C_SIDEXT_DCR(x)                        (((uint32_t)(((uint32_t)(x)) << I3C_SIDEXT_DCR_SHIFT)) & I3C_SIDEXT_DCR_MASK)

#define I3C_SIDEXT_BCR_MASK                      (0xFF0000U)
#define I3C_SIDEXT_BCR_SHIFT                     (16U)
#define I3C_SIDEXT_BCR_WIDTH                     (8U)
#define I3C_SIDEXT_BCR(x)                        (((uint32_t)(((uint32_t)(x)) << I3C_SIDEXT_BCR_SHIFT)) & I3C_SIDEXT_BCR_MASK)
/*! @} */

/*! @name SVENDORID - Slave Vendor ID */
/*! @{ */

#define I3C_SVENDORID_VID_MASK                   (0x7FFFU)
#define I3C_SVENDORID_VID_SHIFT                  (0U)
#define I3C_SVENDORID_VID_WIDTH                  (15U)
#define I3C_SVENDORID_VID(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SVENDORID_VID_SHIFT)) & I3C_SVENDORID_VID_MASK)
/*! @} */

/*! @name STCCLOCK - Slave Time Control Clock */
/*! @{ */

#define I3C_STCCLOCK_ACCURACY_MASK               (0xFFU)
#define I3C_STCCLOCK_ACCURACY_SHIFT              (0U)
#define I3C_STCCLOCK_ACCURACY_WIDTH              (8U)
#define I3C_STCCLOCK_ACCURACY(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_STCCLOCK_ACCURACY_SHIFT)) & I3C_STCCLOCK_ACCURACY_MASK)

#define I3C_STCCLOCK_FREQ_MASK                   (0xFF00U)
#define I3C_STCCLOCK_FREQ_SHIFT                  (8U)
#define I3C_STCCLOCK_FREQ_WIDTH                  (8U)
#define I3C_STCCLOCK_FREQ(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_STCCLOCK_FREQ_SHIFT)) & I3C_STCCLOCK_FREQ_MASK)
/*! @} */

/*! @name SMSGLAST - Slave Message Last Matched */
/*! @{ */

#define I3C_SMSGLAST_MAPLAST_MASK                (0xFU)
#define I3C_SMSGLAST_MAPLAST_SHIFT               (0U)
#define I3C_SMSGLAST_MAPLAST_WIDTH               (4U)
#define I3C_SMSGLAST_MAPLAST(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_SMSGLAST_MAPLAST_SHIFT)) & I3C_SMSGLAST_MAPLAST_MASK)

#define I3C_SMSGLAST_LASTSTATIC_MASK             (0x10U)
#define I3C_SMSGLAST_LASTSTATIC_SHIFT            (4U)
#define I3C_SMSGLAST_LASTSTATIC_WIDTH            (1U)
#define I3C_SMSGLAST_LASTSTATIC(x)               (((uint32_t)(((uint32_t)(x)) << I3C_SMSGLAST_LASTSTATIC_SHIFT)) & I3C_SMSGLAST_LASTSTATIC_MASK)

#define I3C_SMSGLAST_LASTGROUP_MASK              (0x20U)
#define I3C_SMSGLAST_LASTGROUP_SHIFT             (5U)
#define I3C_SMSGLAST_LASTGROUP_WIDTH             (1U)
#define I3C_SMSGLAST_LASTGROUP(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SMSGLAST_LASTGROUP_SHIFT)) & I3C_SMSGLAST_LASTGROUP_MASK)

#define I3C_SMSGLAST_LASTMODE_MASK               (0xC0U)
#define I3C_SMSGLAST_LASTMODE_SHIFT              (6U)
#define I3C_SMSGLAST_LASTMODE_WIDTH              (2U)
#define I3C_SMSGLAST_LASTMODE(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SMSGLAST_LASTMODE_SHIFT)) & I3C_SMSGLAST_LASTMODE_MASK)

#define I3C_SMSGLAST_MAPLASTM1_MASK              (0xF00U)
#define I3C_SMSGLAST_MAPLASTM1_SHIFT             (8U)
#define I3C_SMSGLAST_MAPLASTM1_WIDTH             (4U)
#define I3C_SMSGLAST_MAPLASTM1(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SMSGLAST_MAPLASTM1_SHIFT)) & I3C_SMSGLAST_MAPLASTM1_MASK)

#define I3C_SMSGLAST_LASTGROUPM1_MASK            (0x2000U)
#define I3C_SMSGLAST_LASTGROUPM1_SHIFT           (13U)
#define I3C_SMSGLAST_LASTGROUPM1_WIDTH           (1U)
#define I3C_SMSGLAST_LASTGROUPM1(x)              (((uint32_t)(((uint32_t)(x)) << I3C_SMSGLAST_LASTGROUPM1_SHIFT)) & I3C_SMSGLAST_LASTGROUPM1_MASK)

#define I3C_SMSGLAST_LASTMODE1_MASK              (0xC000U)
#define I3C_SMSGLAST_LASTMODE1_SHIFT             (14U)
#define I3C_SMSGLAST_LASTMODE1_WIDTH             (2U)
#define I3C_SMSGLAST_LASTMODE1(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SMSGLAST_LASTMODE1_SHIFT)) & I3C_SMSGLAST_LASTMODE1_MASK)

#define I3C_SMSGLAST_MAPLASTM2_MASK              (0xF0000U)
#define I3C_SMSGLAST_MAPLASTM2_SHIFT             (16U)
#define I3C_SMSGLAST_MAPLASTM2_WIDTH             (4U)
#define I3C_SMSGLAST_MAPLASTM2(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SMSGLAST_MAPLASTM2_SHIFT)) & I3C_SMSGLAST_MAPLASTM2_MASK)

#define I3C_SMSGLAST_LASTGROUPM2_MASK            (0x200000U)
#define I3C_SMSGLAST_LASTGROUPM2_SHIFT           (21U)
#define I3C_SMSGLAST_LASTGROUPM2_WIDTH           (1U)
#define I3C_SMSGLAST_LASTGROUPM2(x)              (((uint32_t)(((uint32_t)(x)) << I3C_SMSGLAST_LASTGROUPM2_SHIFT)) & I3C_SMSGLAST_LASTGROUPM2_MASK)

#define I3C_SMSGLAST_LASTMODE2_MASK              (0xC00000U)
#define I3C_SMSGLAST_LASTMODE2_SHIFT             (22U)
#define I3C_SMSGLAST_LASTMODE2_WIDTH             (2U)
#define I3C_SMSGLAST_LASTMODE2(x)                (((uint32_t)(((uint32_t)(x)) << I3C_SMSGLAST_LASTMODE2_SHIFT)) & I3C_SMSGLAST_LASTMODE2_MASK)
/*! @} */

/*! @name MCTRL - Master Control */
/*! @{ */

#define I3C_MCTRL_REQUEST_MASK                   (0x7U)
#define I3C_MCTRL_REQUEST_SHIFT                  (0U)
#define I3C_MCTRL_REQUEST_WIDTH                  (3U)
#define I3C_MCTRL_REQUEST(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MCTRL_REQUEST_SHIFT)) & I3C_MCTRL_REQUEST_MASK)

#define I3C_MCTRL_TYPE_MASK                      (0x30U)
#define I3C_MCTRL_TYPE_SHIFT                     (4U)
#define I3C_MCTRL_TYPE_WIDTH                     (2U)
#define I3C_MCTRL_TYPE(x)                        (((uint32_t)(((uint32_t)(x)) << I3C_MCTRL_TYPE_SHIFT)) & I3C_MCTRL_TYPE_MASK)

#define I3C_MCTRL_IBIRESP_MASK                   (0xC0U)
#define I3C_MCTRL_IBIRESP_SHIFT                  (6U)
#define I3C_MCTRL_IBIRESP_WIDTH                  (2U)
#define I3C_MCTRL_IBIRESP(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MCTRL_IBIRESP_SHIFT)) & I3C_MCTRL_IBIRESP_MASK)

#define I3C_MCTRL_DIR_MASK                       (0x100U)
#define I3C_MCTRL_DIR_SHIFT                      (8U)
#define I3C_MCTRL_DIR_WIDTH                      (1U)
#define I3C_MCTRL_DIR(x)                         (((uint32_t)(((uint32_t)(x)) << I3C_MCTRL_DIR_SHIFT)) & I3C_MCTRL_DIR_MASK)

#define I3C_MCTRL_ADDR_MASK                      (0xFE00U)
#define I3C_MCTRL_ADDR_SHIFT                     (9U)
#define I3C_MCTRL_ADDR_WIDTH                     (7U)
#define I3C_MCTRL_ADDR(x)                        (((uint32_t)(((uint32_t)(x)) << I3C_MCTRL_ADDR_SHIFT)) & I3C_MCTRL_ADDR_MASK)

#define I3C_MCTRL_RDTERM_MASK                    (0xFF0000U)
#define I3C_MCTRL_RDTERM_SHIFT                   (16U)
#define I3C_MCTRL_RDTERM_WIDTH                   (8U)
#define I3C_MCTRL_RDTERM(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_MCTRL_RDTERM_SHIFT)) & I3C_MCTRL_RDTERM_MASK)
/*! @} */

/*! @name MSTATUS - Master Status */
/*! @{ */

#define I3C_MSTATUS_STATE_MASK                   (0x7U)
#define I3C_MSTATUS_STATE_SHIFT                  (0U)
#define I3C_MSTATUS_STATE_WIDTH                  (3U)
#define I3C_MSTATUS_STATE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_STATE_SHIFT)) & I3C_MSTATUS_STATE_MASK)

#define I3C_MSTATUS_BETWEEN_MASK                 (0x10U)
#define I3C_MSTATUS_BETWEEN_SHIFT                (4U)
#define I3C_MSTATUS_BETWEEN_WIDTH                (1U)
#define I3C_MSTATUS_BETWEEN(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_BETWEEN_SHIFT)) & I3C_MSTATUS_BETWEEN_MASK)

#define I3C_MSTATUS_NACKED_MASK                  (0x20U)
#define I3C_MSTATUS_NACKED_SHIFT                 (5U)
#define I3C_MSTATUS_NACKED_WIDTH                 (1U)
#define I3C_MSTATUS_NACKED(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_NACKED_SHIFT)) & I3C_MSTATUS_NACKED_MASK)

#define I3C_MSTATUS_IBITYPE_MASK                 (0xC0U)
#define I3C_MSTATUS_IBITYPE_SHIFT                (6U)
#define I3C_MSTATUS_IBITYPE_WIDTH                (2U)
#define I3C_MSTATUS_IBITYPE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_IBITYPE_SHIFT)) & I3C_MSTATUS_IBITYPE_MASK)

#define I3C_MSTATUS_SLVSTART_MASK                (0x100U)
#define I3C_MSTATUS_SLVSTART_SHIFT               (8U)
#define I3C_MSTATUS_SLVSTART_WIDTH               (1U)
#define I3C_MSTATUS_SLVSTART(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_SLVSTART_SHIFT)) & I3C_MSTATUS_SLVSTART_MASK)

#define I3C_MSTATUS_MCTRLDONE_MASK               (0x200U)
#define I3C_MSTATUS_MCTRLDONE_SHIFT              (9U)
#define I3C_MSTATUS_MCTRLDONE_WIDTH              (1U)
#define I3C_MSTATUS_MCTRLDONE(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_MCTRLDONE_SHIFT)) & I3C_MSTATUS_MCTRLDONE_MASK)

#define I3C_MSTATUS_COMPLETE_MASK                (0x400U)
#define I3C_MSTATUS_COMPLETE_SHIFT               (10U)
#define I3C_MSTATUS_COMPLETE_WIDTH               (1U)
#define I3C_MSTATUS_COMPLETE(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_COMPLETE_SHIFT)) & I3C_MSTATUS_COMPLETE_MASK)

#define I3C_MSTATUS_RXPEND_MASK                  (0x800U)
#define I3C_MSTATUS_RXPEND_SHIFT                 (11U)
#define I3C_MSTATUS_RXPEND_WIDTH                 (1U)
#define I3C_MSTATUS_RXPEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_RXPEND_SHIFT)) & I3C_MSTATUS_RXPEND_MASK)

#define I3C_MSTATUS_TXNOTFULL_MASK               (0x1000U)
#define I3C_MSTATUS_TXNOTFULL_SHIFT              (12U)
#define I3C_MSTATUS_TXNOTFULL_WIDTH              (1U)
#define I3C_MSTATUS_TXNOTFULL(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_TXNOTFULL_SHIFT)) & I3C_MSTATUS_TXNOTFULL_MASK)

#define I3C_MSTATUS_IBIWON_MASK                  (0x2000U)
#define I3C_MSTATUS_IBIWON_SHIFT                 (13U)
#define I3C_MSTATUS_IBIWON_WIDTH                 (1U)
#define I3C_MSTATUS_IBIWON(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_IBIWON_SHIFT)) & I3C_MSTATUS_IBIWON_MASK)

#define I3C_MSTATUS_ERRWARN_MASK                 (0x8000U)
#define I3C_MSTATUS_ERRWARN_SHIFT                (15U)
#define I3C_MSTATUS_ERRWARN_WIDTH                (1U)
#define I3C_MSTATUS_ERRWARN(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_ERRWARN_SHIFT)) & I3C_MSTATUS_ERRWARN_MASK)

#define I3C_MSTATUS_NOWMASTER_MASK               (0x80000U)
#define I3C_MSTATUS_NOWMASTER_SHIFT              (19U)
#define I3C_MSTATUS_NOWMASTER_WIDTH              (1U)
#define I3C_MSTATUS_NOWMASTER(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_NOWMASTER_SHIFT)) & I3C_MSTATUS_NOWMASTER_MASK)

#define I3C_MSTATUS_IBIADDR_MASK                 (0x7F000000U)
#define I3C_MSTATUS_IBIADDR_SHIFT                (24U)
#define I3C_MSTATUS_IBIADDR_WIDTH                (7U)
#define I3C_MSTATUS_IBIADDR(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MSTATUS_IBIADDR_SHIFT)) & I3C_MSTATUS_IBIADDR_MASK)
/*! @} */

/*! @name MIBIRULES - Master In-band Interrupt Registry and Rules */
/*! @{ */

#define I3C_MIBIRULES_ADDR0_MASK                 (0x3FU)
#define I3C_MIBIRULES_ADDR0_SHIFT                (0U)
#define I3C_MIBIRULES_ADDR0_WIDTH                (6U)
#define I3C_MIBIRULES_ADDR0(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MIBIRULES_ADDR0_SHIFT)) & I3C_MIBIRULES_ADDR0_MASK)

#define I3C_MIBIRULES_ADDR1_MASK                 (0xFC0U)
#define I3C_MIBIRULES_ADDR1_SHIFT                (6U)
#define I3C_MIBIRULES_ADDR1_WIDTH                (6U)
#define I3C_MIBIRULES_ADDR1(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MIBIRULES_ADDR1_SHIFT)) & I3C_MIBIRULES_ADDR1_MASK)

#define I3C_MIBIRULES_ADDR2_MASK                 (0x3F000U)
#define I3C_MIBIRULES_ADDR2_SHIFT                (12U)
#define I3C_MIBIRULES_ADDR2_WIDTH                (6U)
#define I3C_MIBIRULES_ADDR2(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MIBIRULES_ADDR2_SHIFT)) & I3C_MIBIRULES_ADDR2_MASK)

#define I3C_MIBIRULES_ADDR3_MASK                 (0xFC0000U)
#define I3C_MIBIRULES_ADDR3_SHIFT                (18U)
#define I3C_MIBIRULES_ADDR3_WIDTH                (6U)
#define I3C_MIBIRULES_ADDR3(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MIBIRULES_ADDR3_SHIFT)) & I3C_MIBIRULES_ADDR3_MASK)

#define I3C_MIBIRULES_ADDR4_MASK                 (0x3F000000U)
#define I3C_MIBIRULES_ADDR4_SHIFT                (24U)
#define I3C_MIBIRULES_ADDR4_WIDTH                (6U)
#define I3C_MIBIRULES_ADDR4(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MIBIRULES_ADDR4_SHIFT)) & I3C_MIBIRULES_ADDR4_MASK)

#define I3C_MIBIRULES_MSB0_MASK                  (0x40000000U)
#define I3C_MIBIRULES_MSB0_SHIFT                 (30U)
#define I3C_MIBIRULES_MSB0_WIDTH                 (1U)
#define I3C_MIBIRULES_MSB0(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MIBIRULES_MSB0_SHIFT)) & I3C_MIBIRULES_MSB0_MASK)

#define I3C_MIBIRULES_NOBYTE_MASK                (0x80000000U)
#define I3C_MIBIRULES_NOBYTE_SHIFT               (31U)
#define I3C_MIBIRULES_NOBYTE_WIDTH               (1U)
#define I3C_MIBIRULES_NOBYTE(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MIBIRULES_NOBYTE_SHIFT)) & I3C_MIBIRULES_NOBYTE_MASK)
/*! @} */

/*! @name MINTSET - Master Interrupt Set */
/*! @{ */

#define I3C_MINTSET_SLVSTART_MASK                (0x100U)
#define I3C_MINTSET_SLVSTART_SHIFT               (8U)
#define I3C_MINTSET_SLVSTART_WIDTH               (1U)
#define I3C_MINTSET_SLVSTART(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_SLVSTART_SHIFT)) & I3C_MINTSET_SLVSTART_MASK)

#define I3C_MINTSET_MCTRLDONE_MASK               (0x200U)
#define I3C_MINTSET_MCTRLDONE_SHIFT              (9U)
#define I3C_MINTSET_MCTRLDONE_WIDTH              (1U)
#define I3C_MINTSET_MCTRLDONE(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_MCTRLDONE_SHIFT)) & I3C_MINTSET_MCTRLDONE_MASK)

#define I3C_MINTSET_COMPLETE_MASK                (0x400U)
#define I3C_MINTSET_COMPLETE_SHIFT               (10U)
#define I3C_MINTSET_COMPLETE_WIDTH               (1U)
#define I3C_MINTSET_COMPLETE(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_COMPLETE_SHIFT)) & I3C_MINTSET_COMPLETE_MASK)

#define I3C_MINTSET_RXPEND_MASK                  (0x800U)
#define I3C_MINTSET_RXPEND_SHIFT                 (11U)
#define I3C_MINTSET_RXPEND_WIDTH                 (1U)
#define I3C_MINTSET_RXPEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_RXPEND_SHIFT)) & I3C_MINTSET_RXPEND_MASK)

#define I3C_MINTSET_TXNOTFULL_MASK               (0x1000U)
#define I3C_MINTSET_TXNOTFULL_SHIFT              (12U)
#define I3C_MINTSET_TXNOTFULL_WIDTH              (1U)
#define I3C_MINTSET_TXNOTFULL(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_TXNOTFULL_SHIFT)) & I3C_MINTSET_TXNOTFULL_MASK)

#define I3C_MINTSET_IBIWON_MASK                  (0x2000U)
#define I3C_MINTSET_IBIWON_SHIFT                 (13U)
#define I3C_MINTSET_IBIWON_WIDTH                 (1U)
#define I3C_MINTSET_IBIWON(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_IBIWON_SHIFT)) & I3C_MINTSET_IBIWON_MASK)

#define I3C_MINTSET_ERRWARN_MASK                 (0x8000U)
#define I3C_MINTSET_ERRWARN_SHIFT                (15U)
#define I3C_MINTSET_ERRWARN_WIDTH                (1U)
#define I3C_MINTSET_ERRWARN(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_ERRWARN_SHIFT)) & I3C_MINTSET_ERRWARN_MASK)

#define I3C_MINTSET_NOWMASTER_MASK               (0x80000U)
#define I3C_MINTSET_NOWMASTER_SHIFT              (19U)
#define I3C_MINTSET_NOWMASTER_WIDTH              (1U)
#define I3C_MINTSET_NOWMASTER(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTSET_NOWMASTER_SHIFT)) & I3C_MINTSET_NOWMASTER_MASK)
/*! @} */

/*! @name MINTCLR - Master Interrupt Clear */
/*! @{ */

#define I3C_MINTCLR_SLVSTART_MASK                (0x100U)
#define I3C_MINTCLR_SLVSTART_SHIFT               (8U)
#define I3C_MINTCLR_SLVSTART_WIDTH               (1U)
#define I3C_MINTCLR_SLVSTART(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_SLVSTART_SHIFT)) & I3C_MINTCLR_SLVSTART_MASK)

#define I3C_MINTCLR_MCTRLDONE_MASK               (0x200U)
#define I3C_MINTCLR_MCTRLDONE_SHIFT              (9U)
#define I3C_MINTCLR_MCTRLDONE_WIDTH              (1U)
#define I3C_MINTCLR_MCTRLDONE(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_MCTRLDONE_SHIFT)) & I3C_MINTCLR_MCTRLDONE_MASK)

#define I3C_MINTCLR_COMPLETE_MASK                (0x400U)
#define I3C_MINTCLR_COMPLETE_SHIFT               (10U)
#define I3C_MINTCLR_COMPLETE_WIDTH               (1U)
#define I3C_MINTCLR_COMPLETE(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_COMPLETE_SHIFT)) & I3C_MINTCLR_COMPLETE_MASK)

#define I3C_MINTCLR_RXPEND_MASK                  (0x800U)
#define I3C_MINTCLR_RXPEND_SHIFT                 (11U)
#define I3C_MINTCLR_RXPEND_WIDTH                 (1U)
#define I3C_MINTCLR_RXPEND(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_RXPEND_SHIFT)) & I3C_MINTCLR_RXPEND_MASK)

#define I3C_MINTCLR_TXNOTFULL_MASK               (0x1000U)
#define I3C_MINTCLR_TXNOTFULL_SHIFT              (12U)
#define I3C_MINTCLR_TXNOTFULL_WIDTH              (1U)
#define I3C_MINTCLR_TXNOTFULL(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_TXNOTFULL_SHIFT)) & I3C_MINTCLR_TXNOTFULL_MASK)

#define I3C_MINTCLR_IBIWON_MASK                  (0x2000U)
#define I3C_MINTCLR_IBIWON_SHIFT                 (13U)
#define I3C_MINTCLR_IBIWON_WIDTH                 (1U)
#define I3C_MINTCLR_IBIWON(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_IBIWON_SHIFT)) & I3C_MINTCLR_IBIWON_MASK)

#define I3C_MINTCLR_ERRWARN_MASK                 (0x8000U)
#define I3C_MINTCLR_ERRWARN_SHIFT                (15U)
#define I3C_MINTCLR_ERRWARN_WIDTH                (1U)
#define I3C_MINTCLR_ERRWARN(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_ERRWARN_SHIFT)) & I3C_MINTCLR_ERRWARN_MASK)

#define I3C_MINTCLR_NOWMASTER_MASK               (0x80000U)
#define I3C_MINTCLR_NOWMASTER_SHIFT              (19U)
#define I3C_MINTCLR_NOWMASTER_WIDTH              (1U)
#define I3C_MINTCLR_NOWMASTER(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTCLR_NOWMASTER_SHIFT)) & I3C_MINTCLR_NOWMASTER_MASK)
/*! @} */

/*! @name MINTMASKED - Master Interrupt Mask */
/*! @{ */

#define I3C_MINTMASKED_SLVSTART_MASK             (0x100U)
#define I3C_MINTMASKED_SLVSTART_SHIFT            (8U)
#define I3C_MINTMASKED_SLVSTART_WIDTH            (1U)
#define I3C_MINTMASKED_SLVSTART(x)               (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_SLVSTART_SHIFT)) & I3C_MINTMASKED_SLVSTART_MASK)

#define I3C_MINTMASKED_MCTRLDONE_MASK            (0x200U)
#define I3C_MINTMASKED_MCTRLDONE_SHIFT           (9U)
#define I3C_MINTMASKED_MCTRLDONE_WIDTH           (1U)
#define I3C_MINTMASKED_MCTRLDONE(x)              (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_MCTRLDONE_SHIFT)) & I3C_MINTMASKED_MCTRLDONE_MASK)

#define I3C_MINTMASKED_COMPLETE_MASK             (0x400U)
#define I3C_MINTMASKED_COMPLETE_SHIFT            (10U)
#define I3C_MINTMASKED_COMPLETE_WIDTH            (1U)
#define I3C_MINTMASKED_COMPLETE(x)               (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_COMPLETE_SHIFT)) & I3C_MINTMASKED_COMPLETE_MASK)

#define I3C_MINTMASKED_RXPEND_MASK               (0x800U)
#define I3C_MINTMASKED_RXPEND_SHIFT              (11U)
#define I3C_MINTMASKED_RXPEND_WIDTH              (1U)
#define I3C_MINTMASKED_RXPEND(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_RXPEND_SHIFT)) & I3C_MINTMASKED_RXPEND_MASK)

#define I3C_MINTMASKED_TXNOTFULL_MASK            (0x1000U)
#define I3C_MINTMASKED_TXNOTFULL_SHIFT           (12U)
#define I3C_MINTMASKED_TXNOTFULL_WIDTH           (1U)
#define I3C_MINTMASKED_TXNOTFULL(x)              (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_TXNOTFULL_SHIFT)) & I3C_MINTMASKED_TXNOTFULL_MASK)

#define I3C_MINTMASKED_IBIWON_MASK               (0x2000U)
#define I3C_MINTMASKED_IBIWON_SHIFT              (13U)
#define I3C_MINTMASKED_IBIWON_WIDTH              (1U)
#define I3C_MINTMASKED_IBIWON(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_IBIWON_SHIFT)) & I3C_MINTMASKED_IBIWON_MASK)

#define I3C_MINTMASKED_ERRWARN_MASK              (0x8000U)
#define I3C_MINTMASKED_ERRWARN_SHIFT             (15U)
#define I3C_MINTMASKED_ERRWARN_WIDTH             (1U)
#define I3C_MINTMASKED_ERRWARN(x)                (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_ERRWARN_SHIFT)) & I3C_MINTMASKED_ERRWARN_MASK)

#define I3C_MINTMASKED_NOWMASTER_MASK            (0x80000U)
#define I3C_MINTMASKED_NOWMASTER_SHIFT           (19U)
#define I3C_MINTMASKED_NOWMASTER_WIDTH           (1U)
#define I3C_MINTMASKED_NOWMASTER(x)              (((uint32_t)(((uint32_t)(x)) << I3C_MINTMASKED_NOWMASTER_SHIFT)) & I3C_MINTMASKED_NOWMASTER_MASK)
/*! @} */

/*! @name MERRWARN - Master Errors and Warnings */
/*! @{ */

#define I3C_MERRWARN_URUN_MASK                   (0x2U)
#define I3C_MERRWARN_URUN_SHIFT                  (1U)
#define I3C_MERRWARN_URUN_WIDTH                  (1U)
#define I3C_MERRWARN_URUN(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_URUN_SHIFT)) & I3C_MERRWARN_URUN_MASK)

#define I3C_MERRWARN_NACK_MASK                   (0x4U)
#define I3C_MERRWARN_NACK_SHIFT                  (2U)
#define I3C_MERRWARN_NACK_WIDTH                  (1U)
#define I3C_MERRWARN_NACK(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_NACK_SHIFT)) & I3C_MERRWARN_NACK_MASK)

#define I3C_MERRWARN_WRABT_MASK                  (0x8U)
#define I3C_MERRWARN_WRABT_SHIFT                 (3U)
#define I3C_MERRWARN_WRABT_WIDTH                 (1U)
#define I3C_MERRWARN_WRABT(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_WRABT_SHIFT)) & I3C_MERRWARN_WRABT_MASK)

#define I3C_MERRWARN_TERM_MASK                   (0x10U)
#define I3C_MERRWARN_TERM_SHIFT                  (4U)
#define I3C_MERRWARN_TERM_WIDTH                  (1U)
#define I3C_MERRWARN_TERM(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_TERM_SHIFT)) & I3C_MERRWARN_TERM_MASK)

#define I3C_MERRWARN_HPAR_MASK                   (0x200U)
#define I3C_MERRWARN_HPAR_SHIFT                  (9U)
#define I3C_MERRWARN_HPAR_WIDTH                  (1U)
#define I3C_MERRWARN_HPAR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_HPAR_SHIFT)) & I3C_MERRWARN_HPAR_MASK)

#define I3C_MERRWARN_HCRC_MASK                   (0x400U)
#define I3C_MERRWARN_HCRC_SHIFT                  (10U)
#define I3C_MERRWARN_HCRC_WIDTH                  (1U)
#define I3C_MERRWARN_HCRC(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_HCRC_SHIFT)) & I3C_MERRWARN_HCRC_MASK)

#define I3C_MERRWARN_HNOVERIFY_MASK              (0x1000U)
#define I3C_MERRWARN_HNOVERIFY_SHIFT             (12U)
#define I3C_MERRWARN_HNOVERIFY_WIDTH             (1U)
#define I3C_MERRWARN_HNOVERIFY(x)                (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_HNOVERIFY_SHIFT)) & I3C_MERRWARN_HNOVERIFY_MASK)

#define I3C_MERRWARN_OREAD_MASK                  (0x10000U)
#define I3C_MERRWARN_OREAD_SHIFT                 (16U)
#define I3C_MERRWARN_OREAD_WIDTH                 (1U)
#define I3C_MERRWARN_OREAD(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_OREAD_SHIFT)) & I3C_MERRWARN_OREAD_MASK)

#define I3C_MERRWARN_OWRITE_MASK                 (0x20000U)
#define I3C_MERRWARN_OWRITE_SHIFT                (17U)
#define I3C_MERRWARN_OWRITE_WIDTH                (1U)
#define I3C_MERRWARN_OWRITE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_OWRITE_SHIFT)) & I3C_MERRWARN_OWRITE_MASK)

#define I3C_MERRWARN_MSGERR_MASK                 (0x40000U)
#define I3C_MERRWARN_MSGERR_SHIFT                (18U)
#define I3C_MERRWARN_MSGERR_WIDTH                (1U)
#define I3C_MERRWARN_MSGERR(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_MSGERR_SHIFT)) & I3C_MERRWARN_MSGERR_MASK)

#define I3C_MERRWARN_INVREQ_MASK                 (0x80000U)
#define I3C_MERRWARN_INVREQ_SHIFT                (19U)
#define I3C_MERRWARN_INVREQ_WIDTH                (1U)
#define I3C_MERRWARN_INVREQ(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_INVREQ_SHIFT)) & I3C_MERRWARN_INVREQ_MASK)

#define I3C_MERRWARN_TIMEOUT_MASK                (0x100000U)
#define I3C_MERRWARN_TIMEOUT_SHIFT               (20U)
#define I3C_MERRWARN_TIMEOUT_WIDTH               (1U)
#define I3C_MERRWARN_TIMEOUT(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_TIMEOUT_SHIFT)) & I3C_MERRWARN_TIMEOUT_MASK)

#define I3C_MERRWARN_WRONGSIZE_MASK              (0x200000U)
#define I3C_MERRWARN_WRONGSIZE_SHIFT             (21U)
#define I3C_MERRWARN_WRONGSIZE_WIDTH             (1U)
#define I3C_MERRWARN_WRONGSIZE(x)                (((uint32_t)(((uint32_t)(x)) << I3C_MERRWARN_WRONGSIZE_SHIFT)) & I3C_MERRWARN_WRONGSIZE_MASK)
/*! @} */

/*! @name MDMACTRL - Master DMA Control */
/*! @{ */

#define I3C_MDMACTRL_DMAFB_MASK                  (0x3U)
#define I3C_MDMACTRL_DMAFB_SHIFT                 (0U)
#define I3C_MDMACTRL_DMAFB_WIDTH                 (2U)
#define I3C_MDMACTRL_DMAFB(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MDMACTRL_DMAFB_SHIFT)) & I3C_MDMACTRL_DMAFB_MASK)

#define I3C_MDMACTRL_DMATB_MASK                  (0xCU)
#define I3C_MDMACTRL_DMATB_SHIFT                 (2U)
#define I3C_MDMACTRL_DMATB_WIDTH                 (2U)
#define I3C_MDMACTRL_DMATB(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MDMACTRL_DMATB_SHIFT)) & I3C_MDMACTRL_DMATB_MASK)

#define I3C_MDMACTRL_DMAWIDTH_MASK               (0x30U)
#define I3C_MDMACTRL_DMAWIDTH_SHIFT              (4U)
#define I3C_MDMACTRL_DMAWIDTH_WIDTH              (2U)
#define I3C_MDMACTRL_DMAWIDTH(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MDMACTRL_DMAWIDTH_SHIFT)) & I3C_MDMACTRL_DMAWIDTH_MASK)
/*! @} */

/*! @name MHDRBTCFG - Master HDR-BT Configuration */
/*! @{ */

#define I3C_MHDRBTCFG_MLHDR_MASK                 (0x3U)
#define I3C_MHDRBTCFG_MLHDR_SHIFT                (0U)
#define I3C_MHDRBTCFG_MLHDR_WIDTH                (2U)
#define I3C_MHDRBTCFG_MLHDR(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MHDRBTCFG_MLHDR_SHIFT)) & I3C_MHDRBTCFG_MLHDR_MASK)

#define I3C_MHDRBTCFG_MLDAT_MASK                 (0xCU)
#define I3C_MHDRBTCFG_MLDAT_SHIFT                (2U)
#define I3C_MHDRBTCFG_MLDAT_WIDTH                (2U)
#define I3C_MHDRBTCFG_MLDAT(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MHDRBTCFG_MLDAT_SHIFT)) & I3C_MHDRBTCFG_MLDAT_MASK)

#define I3C_MHDRBTCFG_CRC32_MASK                 (0x10U)
#define I3C_MHDRBTCFG_CRC32_SHIFT                (4U)
#define I3C_MHDRBTCFG_CRC32_WIDTH                (1U)
#define I3C_MHDRBTCFG_CRC32(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_MHDRBTCFG_CRC32_SHIFT)) & I3C_MHDRBTCFG_CRC32_MASK)

#define I3C_MHDRBTCFG_DATALEN_MASK               (0xFFFF0000U)
#define I3C_MHDRBTCFG_DATALEN_SHIFT              (16U)
#define I3C_MHDRBTCFG_DATALEN_WIDTH              (16U)
#define I3C_MHDRBTCFG_DATALEN(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MHDRBTCFG_DATALEN_SHIFT)) & I3C_MHDRBTCFG_DATALEN_MASK)
/*! @} */

/*! @name MHDRBTLAST - Master HDR-Last */
/*! @{ */

#define I3C_MHDRBTLAST_DATALEN_MASK              (0xFFFF0000U)
#define I3C_MHDRBTLAST_DATALEN_SHIFT             (16U)
#define I3C_MHDRBTLAST_DATALEN_WIDTH             (16U)
#define I3C_MHDRBTLAST_DATALEN(x)                (((uint32_t)(((uint32_t)(x)) << I3C_MHDRBTLAST_DATALEN_SHIFT)) & I3C_MHDRBTLAST_DATALEN_MASK)
/*! @} */

/*! @name MDATACTRL - Master Data Control */
/*! @{ */

#define I3C_MDATACTRL_FLUSHTB_MASK               (0x1U)
#define I3C_MDATACTRL_FLUSHTB_SHIFT              (0U)
#define I3C_MDATACTRL_FLUSHTB_WIDTH              (1U)
#define I3C_MDATACTRL_FLUSHTB(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_FLUSHTB_SHIFT)) & I3C_MDATACTRL_FLUSHTB_MASK)

#define I3C_MDATACTRL_FLUSHFB_MASK               (0x2U)
#define I3C_MDATACTRL_FLUSHFB_SHIFT              (1U)
#define I3C_MDATACTRL_FLUSHFB_WIDTH              (1U)
#define I3C_MDATACTRL_FLUSHFB(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_FLUSHFB_SHIFT)) & I3C_MDATACTRL_FLUSHFB_MASK)

#define I3C_MDATACTRL_UNLOCK_MASK                (0x8U)
#define I3C_MDATACTRL_UNLOCK_SHIFT               (3U)
#define I3C_MDATACTRL_UNLOCK_WIDTH               (1U)
#define I3C_MDATACTRL_UNLOCK(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_UNLOCK_SHIFT)) & I3C_MDATACTRL_UNLOCK_MASK)

#define I3C_MDATACTRL_TXTRIG_MASK                (0x30U)
#define I3C_MDATACTRL_TXTRIG_SHIFT               (4U)
#define I3C_MDATACTRL_TXTRIG_WIDTH               (2U)
#define I3C_MDATACTRL_TXTRIG(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_TXTRIG_SHIFT)) & I3C_MDATACTRL_TXTRIG_MASK)

#define I3C_MDATACTRL_RXTRIG_MASK                (0xC0U)
#define I3C_MDATACTRL_RXTRIG_SHIFT               (6U)
#define I3C_MDATACTRL_RXTRIG_WIDTH               (2U)
#define I3C_MDATACTRL_RXTRIG(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_RXTRIG_SHIFT)) & I3C_MDATACTRL_RXTRIG_MASK)

#define I3C_MDATACTRL_TXCOUNT_MASK               (0x1F0000U)
#define I3C_MDATACTRL_TXCOUNT_SHIFT              (16U)
#define I3C_MDATACTRL_TXCOUNT_WIDTH              (5U)
#define I3C_MDATACTRL_TXCOUNT(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_TXCOUNT_SHIFT)) & I3C_MDATACTRL_TXCOUNT_MASK)

#define I3C_MDATACTRL_RXCOUNT_MASK               (0x1F000000U)
#define I3C_MDATACTRL_RXCOUNT_SHIFT              (24U)
#define I3C_MDATACTRL_RXCOUNT_WIDTH              (5U)
#define I3C_MDATACTRL_RXCOUNT(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_RXCOUNT_SHIFT)) & I3C_MDATACTRL_RXCOUNT_MASK)

#define I3C_MDATACTRL_TXFULL_MASK                (0x40000000U)
#define I3C_MDATACTRL_TXFULL_SHIFT               (30U)
#define I3C_MDATACTRL_TXFULL_WIDTH               (1U)
#define I3C_MDATACTRL_TXFULL(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_TXFULL_SHIFT)) & I3C_MDATACTRL_TXFULL_MASK)

#define I3C_MDATACTRL_RXEMPTY_MASK               (0x80000000U)
#define I3C_MDATACTRL_RXEMPTY_SHIFT              (31U)
#define I3C_MDATACTRL_RXEMPTY_WIDTH              (1U)
#define I3C_MDATACTRL_RXEMPTY(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_MDATACTRL_RXEMPTY_SHIFT)) & I3C_MDATACTRL_RXEMPTY_MASK)
/*! @} */

/*! @name MWDATAB - Master Write Data Byte */
/*! @{ */

#define I3C_MWDATAB_VALUE_MASK                   (0xFFU)
#define I3C_MWDATAB_VALUE_SHIFT                  (0U)
#define I3C_MWDATAB_VALUE_WIDTH                  (8U)
#define I3C_MWDATAB_VALUE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAB_VALUE_SHIFT)) & I3C_MWDATAB_VALUE_MASK)

#define I3C_MWDATAB_END_MASK                     (0x100U)
#define I3C_MWDATAB_END_SHIFT                    (8U)
#define I3C_MWDATAB_END_WIDTH                    (1U)
#define I3C_MWDATAB_END(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAB_END_SHIFT)) & I3C_MWDATAB_END_MASK)

#define I3C_MWDATAB_END_ALSO_MASK                (0x10000U)
#define I3C_MWDATAB_END_ALSO_SHIFT               (16U)
#define I3C_MWDATAB_END_ALSO_WIDTH               (1U)
#define I3C_MWDATAB_END_ALSO(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAB_END_ALSO_SHIFT)) & I3C_MWDATAB_END_ALSO_MASK)
/*! @} */

/*! @name MWDATABE - Master Write Data Byte End */
/*! @{ */

#define I3C_MWDATABE_VALUE_MASK                  (0xFFU)
#define I3C_MWDATABE_VALUE_SHIFT                 (0U)
#define I3C_MWDATABE_VALUE_WIDTH                 (8U)
#define I3C_MWDATABE_VALUE(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MWDATABE_VALUE_SHIFT)) & I3C_MWDATABE_VALUE_MASK)
/*! @} */

/*! @name MWDATAH - Master Write Data Half-word */
/*! @{ */

#define I3C_MWDATAH_DATA0_MASK                   (0xFFU)
#define I3C_MWDATAH_DATA0_SHIFT                  (0U)
#define I3C_MWDATAH_DATA0_WIDTH                  (8U)
#define I3C_MWDATAH_DATA0(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAH_DATA0_SHIFT)) & I3C_MWDATAH_DATA0_MASK)

#define I3C_MWDATAH_DATA1_MASK                   (0xFF00U)
#define I3C_MWDATAH_DATA1_SHIFT                  (8U)
#define I3C_MWDATAH_DATA1_WIDTH                  (8U)
#define I3C_MWDATAH_DATA1(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAH_DATA1_SHIFT)) & I3C_MWDATAH_DATA1_MASK)

#define I3C_MWDATAH_END_MASK                     (0x10000U)
#define I3C_MWDATAH_END_SHIFT                    (16U)
#define I3C_MWDATAH_END_WIDTH                    (1U)
#define I3C_MWDATAH_END(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAH_END_SHIFT)) & I3C_MWDATAH_END_MASK)
/*! @} */

/*! @name MWDATAHE - Master Write Data Byte End */
/*! @{ */

#define I3C_MWDATAHE_DATA0_MASK                  (0xFFU)
#define I3C_MWDATAHE_DATA0_SHIFT                 (0U)
#define I3C_MWDATAHE_DATA0_WIDTH                 (8U)
#define I3C_MWDATAHE_DATA0(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAHE_DATA0_SHIFT)) & I3C_MWDATAHE_DATA0_MASK)

#define I3C_MWDATAHE_DATA1_MASK                  (0xFF00U)
#define I3C_MWDATAHE_DATA1_SHIFT                 (8U)
#define I3C_MWDATAHE_DATA1_WIDTH                 (8U)
#define I3C_MWDATAHE_DATA1(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAHE_DATA1_SHIFT)) & I3C_MWDATAHE_DATA1_MASK)
/*! @} */

/*! @name MRDATAB - Master Read Data Byte */
/*! @{ */

#define I3C_MRDATAB_VALUE_MASK                   (0xFFU)
#define I3C_MRDATAB_VALUE_SHIFT                  (0U)
#define I3C_MRDATAB_VALUE_WIDTH                  (8U)
#define I3C_MRDATAB_VALUE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MRDATAB_VALUE_SHIFT)) & I3C_MRDATAB_VALUE_MASK)
/*! @} */

/*! @name MRDATAH - Master Read Data Half-word */
/*! @{ */

#define I3C_MRDATAH_LSB_MASK                     (0xFFU)
#define I3C_MRDATAH_LSB_SHIFT                    (0U)
#define I3C_MRDATAH_LSB_WIDTH                    (8U)
#define I3C_MRDATAH_LSB(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_MRDATAH_LSB_SHIFT)) & I3C_MRDATAH_LSB_MASK)

#define I3C_MRDATAH_MSB_MASK                     (0xFF00U)
#define I3C_MRDATAH_MSB_SHIFT                    (8U)
#define I3C_MRDATAH_MSB_WIDTH                    (8U)
#define I3C_MRDATAH_MSB(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_MRDATAH_MSB_SHIFT)) & I3C_MRDATAH_MSB_MASK)
/*! @} */

/*! @name MWDATAB1 - Byte-only Write Byte Data (to bus) */
/*! @{ */

#define I3C_MWDATAB1_VALUE_MASK                  (0xFFU)
#define I3C_MWDATAB1_VALUE_SHIFT                 (0U)
#define I3C_MWDATAB1_VALUE_WIDTH                 (8U)
#define I3C_MWDATAB1_VALUE(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAB1_VALUE_SHIFT)) & I3C_MWDATAB1_VALUE_MASK)
/*! @} */

/*! @name MWMSG_SDR_CONTROL - Master Write Message in SDR mode */
/*! @{ */

#define I3C_MWMSG_SDR_CONTROL_DIR_MASK           (0x1U)
#define I3C_MWMSG_SDR_CONTROL_DIR_SHIFT          (0U)
#define I3C_MWMSG_SDR_CONTROL_DIR_WIDTH          (1U)
#define I3C_MWMSG_SDR_CONTROL_DIR(x)             (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_SDR_CONTROL_DIR_SHIFT)) & I3C_MWMSG_SDR_CONTROL_DIR_MASK)

#define I3C_MWMSG_SDR_CONTROL_ADDR_MASK          (0xFEU)
#define I3C_MWMSG_SDR_CONTROL_ADDR_SHIFT         (1U)
#define I3C_MWMSG_SDR_CONTROL_ADDR_WIDTH         (7U)
#define I3C_MWMSG_SDR_CONTROL_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_SDR_CONTROL_ADDR_SHIFT)) & I3C_MWMSG_SDR_CONTROL_ADDR_MASK)

#define I3C_MWMSG_SDR_CONTROL_END_MASK           (0x100U)
#define I3C_MWMSG_SDR_CONTROL_END_SHIFT          (8U)
#define I3C_MWMSG_SDR_CONTROL_END_WIDTH          (1U)
#define I3C_MWMSG_SDR_CONTROL_END(x)             (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_SDR_CONTROL_END_SHIFT)) & I3C_MWMSG_SDR_CONTROL_END_MASK)

#define I3C_MWMSG_SDR_CONTROL_I2C_MASK           (0x400U)
#define I3C_MWMSG_SDR_CONTROL_I2C_SHIFT          (10U)
#define I3C_MWMSG_SDR_CONTROL_I2C_WIDTH          (1U)
#define I3C_MWMSG_SDR_CONTROL_I2C(x)             (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_SDR_CONTROL_I2C_SHIFT)) & I3C_MWMSG_SDR_CONTROL_I2C_MASK)

#define I3C_MWMSG_SDR_CONTROL_LEN_MASK           (0xF800U)
#define I3C_MWMSG_SDR_CONTROL_LEN_SHIFT          (11U)
#define I3C_MWMSG_SDR_CONTROL_LEN_WIDTH          (5U)
#define I3C_MWMSG_SDR_CONTROL_LEN(x)             (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_SDR_CONTROL_LEN_SHIFT)) & I3C_MWMSG_SDR_CONTROL_LEN_MASK)
/*! @} */

/*! @name MWMSG_SDR_DATA - Master Write Message Data in SDR mode */
/*! @{ */

#define I3C_MWMSG_SDR_DATA_DATA16B_MASK          (0xFFFFU)
#define I3C_MWMSG_SDR_DATA_DATA16B_SHIFT         (0U)
#define I3C_MWMSG_SDR_DATA_DATA16B_WIDTH         (16U)
#define I3C_MWMSG_SDR_DATA_DATA16B(x)            (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_SDR_DATA_DATA16B_SHIFT)) & I3C_MWMSG_SDR_DATA_DATA16B_MASK)
/*! @} */

/*! @name MRMSG_SDR - Master Read Message in SDR mode */
/*! @{ */

#define I3C_MRMSG_SDR_DATA_MASK                  (0xFFFFU)
#define I3C_MRMSG_SDR_DATA_SHIFT                 (0U)
#define I3C_MRMSG_SDR_DATA_WIDTH                 (16U)
#define I3C_MRMSG_SDR_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MRMSG_SDR_DATA_SHIFT)) & I3C_MRMSG_SDR_DATA_MASK)
/*! @} */

/*! @name MWMSG_DDR_CONTROL - Master Write Message in DDR mode */
/*! @{ */

#define I3C_MWMSG_DDR_CONTROL_LEN_MASK           (0x3FFU)
#define I3C_MWMSG_DDR_CONTROL_LEN_SHIFT          (0U)
#define I3C_MWMSG_DDR_CONTROL_LEN_WIDTH          (10U)
#define I3C_MWMSG_DDR_CONTROL_LEN(x)             (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_DDR_CONTROL_LEN_SHIFT)) & I3C_MWMSG_DDR_CONTROL_LEN_MASK)

#define I3C_MWMSG_DDR_CONTROL_END_MASK           (0x4000U)
#define I3C_MWMSG_DDR_CONTROL_END_SHIFT          (14U)
#define I3C_MWMSG_DDR_CONTROL_END_WIDTH          (1U)
#define I3C_MWMSG_DDR_CONTROL_END(x)             (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_DDR_CONTROL_END_SHIFT)) & I3C_MWMSG_DDR_CONTROL_END_MASK)
/*! @} */

/*! @name MWMSG_DDR_DATA - Master Write Message Data in DDR mode */
/*! @{ */

#define I3C_MWMSG_DDR_DATA_DATA16B_MASK          (0xFFFFU)
#define I3C_MWMSG_DDR_DATA_DATA16B_SHIFT         (0U)
#define I3C_MWMSG_DDR_DATA_DATA16B_WIDTH         (16U)
#define I3C_MWMSG_DDR_DATA_DATA16B(x)            (((uint32_t)(((uint32_t)(x)) << I3C_MWMSG_DDR_DATA_DATA16B_SHIFT)) & I3C_MWMSG_DDR_DATA_DATA16B_MASK)
/*! @} */

/*! @name MRMSG_DDR - Master Read Message in DDR mode */
/*! @{ */

#define I3C_MRMSG_DDR_DATA_MASK                  (0xFFFFU)
#define I3C_MRMSG_DDR_DATA_SHIFT                 (0U)
#define I3C_MRMSG_DDR_DATA_WIDTH                 (16U)
#define I3C_MRMSG_DDR_DATA(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MRMSG_DDR_DATA_SHIFT)) & I3C_MRMSG_DDR_DATA_MASK)
/*! @} */

/*! @name MDYNADDR - Master Dynamic Address */
/*! @{ */

#define I3C_MDYNADDR_DAVALID_MASK                (0x1U)
#define I3C_MDYNADDR_DAVALID_SHIFT               (0U)
#define I3C_MDYNADDR_DAVALID_WIDTH               (1U)
#define I3C_MDYNADDR_DAVALID(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_MDYNADDR_DAVALID_SHIFT)) & I3C_MDYNADDR_DAVALID_MASK)

#define I3C_MDYNADDR_DADDR_MASK                  (0xFEU)
#define I3C_MDYNADDR_DADDR_SHIFT                 (1U)
#define I3C_MDYNADDR_DADDR_WIDTH                 (7U)
#define I3C_MDYNADDR_DADDR(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_MDYNADDR_DADDR_SHIFT)) & I3C_MDYNADDR_DADDR_MASK)
/*! @} */

/*! @name MWDATAW - Write Word Data (to bus) */
/*! @{ */

#define I3C_MWDATAW_DATA_MASK                    (0xFFFFFFFFU)
#define I3C_MWDATAW_DATA_SHIFT                   (0U)
#define I3C_MWDATAW_DATA_WIDTH                   (32U)
#define I3C_MWDATAW_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_MWDATAW_DATA_SHIFT)) & I3C_MWDATAW_DATA_MASK)
/*! @} */

/*! @name MRDATAW - Read Word Data (from bus) */
/*! @{ */

#define I3C_MRDATAW_VALUE_MASK                   (0xFFFFFFFFU)
#define I3C_MRDATAW_VALUE_SHIFT                  (0U)
#define I3C_MRDATAW_VALUE_WIDTH                  (32U)
#define I3C_MRDATAW_VALUE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_MRDATAW_VALUE_SHIFT)) & I3C_MRDATAW_VALUE_MASK)
/*! @} */

/*! @name SRSTACTTIME - Timing Rules for SlaveReset Recovery */
/*! @{ */

#define I3C_SRSTACTTIME_PERRSTTIM_MASK           (0xFFU)
#define I3C_SRSTACTTIME_PERRSTTIM_SHIFT          (0U)
#define I3C_SRSTACTTIME_PERRSTTIM_WIDTH          (8U)
#define I3C_SRSTACTTIME_PERRSTTIM(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SRSTACTTIME_PERRSTTIM_SHIFT)) & I3C_SRSTACTTIME_PERRSTTIM_MASK)

#define I3C_SRSTACTTIME_SYSRSTTIM_MASK           (0xFF00U)
#define I3C_SRSTACTTIME_SYSRSTTIM_SHIFT          (8U)
#define I3C_SRSTACTTIME_SYSRSTTIM_WIDTH          (8U)
#define I3C_SRSTACTTIME_SYSRSTTIM(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SRSTACTTIME_SYSRSTTIM_SHIFT)) & I3C_SRSTACTTIME_SYSRSTTIM_MASK)

#define I3C_SRSTACTTIME_CUSRSTTIM_MASK           (0xFF0000U)
#define I3C_SRSTACTTIME_CUSRSTTIM_SHIFT          (16U)
#define I3C_SRSTACTTIME_CUSRSTTIM_WIDTH          (8U)
#define I3C_SRSTACTTIME_CUSRSTTIM(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SRSTACTTIME_CUSRSTTIM_SHIFT)) & I3C_SRSTACTTIME_CUSRSTTIM_MASK)
/*! @} */

/*! @name SCCCMASK - CCC Mask for Unhandled CCCs */
/*! @{ */

#define I3C_SCCCMASK_BASE_MASK                   (0x1U)
#define I3C_SCCCMASK_BASE_SHIFT                  (0U)
#define I3C_SCCCMASK_BASE_WIDTH                  (1U)
#define I3C_SCCCMASK_BASE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SCCCMASK_BASE_SHIFT)) & I3C_SCCCMASK_BASE_MASK)

#define I3C_SCCCMASK_BASEBX_MASK                 (0x2U)
#define I3C_SCCCMASK_BASEBX_SHIFT                (1U)
#define I3C_SCCCMASK_BASEBX_WIDTH                (1U)
#define I3C_SCCCMASK_BASEBX(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SCCCMASK_BASEBX_SHIFT)) & I3C_SCCCMASK_BASEBX_MASK)

#define I3C_SCCCMASK_BASEDX_MASK                 (0x4U)
#define I3C_SCCCMASK_BASEDX_SHIFT                (2U)
#define I3C_SCCCMASK_BASEDX_WIDTH                (1U)
#define I3C_SCCCMASK_BASEDX(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SCCCMASK_BASEDX_SHIFT)) & I3C_SCCCMASK_BASEDX_MASK)

#define I3C_SCCCMASK_MEXTB_MASK                  (0x8U)
#define I3C_SCCCMASK_MEXTB_SHIFT                 (3U)
#define I3C_SCCCMASK_MEXTB_WIDTH                 (1U)
#define I3C_SCCCMASK_MEXTB(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SCCCMASK_MEXTB_SHIFT)) & I3C_SCCCMASK_MEXTB_MASK)

#define I3C_SCCCMASK_MEXTD_MASK                  (0x10U)
#define I3C_SCCCMASK_MEXTD_SHIFT                 (4U)
#define I3C_SCCCMASK_MEXTD_WIDTH                 (1U)
#define I3C_SCCCMASK_MEXTD(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SCCCMASK_MEXTD_SHIFT)) & I3C_SCCCMASK_MEXTD_MASK)

#define I3C_SCCCMASK_VENDB_MASK                  (0x20U)
#define I3C_SCCCMASK_VENDB_SHIFT                 (5U)
#define I3C_SCCCMASK_VENDB_WIDTH                 (1U)
#define I3C_SCCCMASK_VENDB(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SCCCMASK_VENDB_SHIFT)) & I3C_SCCCMASK_VENDB_MASK)

#define I3C_SCCCMASK_VENDD_MASK                  (0x40U)
#define I3C_SCCCMASK_VENDD_SHIFT                 (6U)
#define I3C_SCCCMASK_VENDD_WIDTH                 (1U)
#define I3C_SCCCMASK_VENDD(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SCCCMASK_VENDD_SHIFT)) & I3C_SCCCMASK_VENDD_MASK)
/*! @} */

/*! @name SERRWARNMASK - Slave Errors and Warnings Mask */
/*! @{ */

#define I3C_SERRWARNMASK_ORUN_MASK               (0x1U)
#define I3C_SERRWARNMASK_ORUN_SHIFT              (0U)
#define I3C_SERRWARNMASK_ORUN_WIDTH              (1U)
#define I3C_SERRWARNMASK_ORUN(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARNMASK_ORUN_SHIFT)) & I3C_SERRWARNMASK_ORUN_MASK)

#define I3C_SERRWARNMASK_URUN_MASK               (0x2U)
#define I3C_SERRWARNMASK_URUN_SHIFT              (1U)
#define I3C_SERRWARNMASK_URUN_WIDTH              (1U)
#define I3C_SERRWARNMASK_URUN(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARNMASK_URUN_SHIFT)) & I3C_SERRWARNMASK_URUN_MASK)

#define I3C_SERRWARNMASK_URUNNACK_MASK           (0x4U)
#define I3C_SERRWARNMASK_URUNNACK_SHIFT          (2U)
#define I3C_SERRWARNMASK_URUNNACK_WIDTH          (1U)
#define I3C_SERRWARNMASK_URUNNACK(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARNMASK_URUNNACK_SHIFT)) & I3C_SERRWARNMASK_URUNNACK_MASK)

#define I3C_SERRWARNMASK_TERM_MASK               (0x8U)
#define I3C_SERRWARNMASK_TERM_SHIFT              (3U)
#define I3C_SERRWARNMASK_TERM_WIDTH              (1U)
#define I3C_SERRWARNMASK_TERM(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARNMASK_TERM_SHIFT)) & I3C_SERRWARNMASK_TERM_MASK)

#define I3C_SERRWARNMASK_INVSTART_MASK           (0x10U)
#define I3C_SERRWARNMASK_INVSTART_SHIFT          (4U)
#define I3C_SERRWARNMASK_INVSTART_WIDTH          (1U)
#define I3C_SERRWARNMASK_INVSTART(x)             (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARNMASK_INVSTART_SHIFT)) & I3C_SERRWARNMASK_INVSTART_MASK)

#define I3C_SERRWARNMASK_SPAR_MASK               (0x100U)
#define I3C_SERRWARNMASK_SPAR_SHIFT              (8U)
#define I3C_SERRWARNMASK_SPAR_WIDTH              (1U)
#define I3C_SERRWARNMASK_SPAR(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARNMASK_SPAR_SHIFT)) & I3C_SERRWARNMASK_SPAR_MASK)

#define I3C_SERRWARNMASK_HPAR_MASK               (0x200U)
#define I3C_SERRWARNMASK_HPAR_SHIFT              (9U)
#define I3C_SERRWARNMASK_HPAR_WIDTH              (1U)
#define I3C_SERRWARNMASK_HPAR(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARNMASK_HPAR_SHIFT)) & I3C_SERRWARNMASK_HPAR_MASK)

#define I3C_SERRWARNMASK_HCRC_MASK               (0x400U)
#define I3C_SERRWARNMASK_HCRC_SHIFT              (10U)
#define I3C_SERRWARNMASK_HCRC_WIDTH              (1U)
#define I3C_SERRWARNMASK_HCRC(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARNMASK_HCRC_SHIFT)) & I3C_SERRWARNMASK_HCRC_MASK)

#define I3C_SERRWARNMASK_S0S1_MASK               (0x800U)
#define I3C_SERRWARNMASK_S0S1_SHIFT              (11U)
#define I3C_SERRWARNMASK_S0S1_WIDTH              (1U)
#define I3C_SERRWARNMASK_S0S1(x)                 (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARNMASK_S0S1_SHIFT)) & I3C_SERRWARNMASK_S0S1_MASK)

#define I3C_SERRWARNMASK_HNOVERIFY_MASK          (0x1000U)
#define I3C_SERRWARNMASK_HNOVERIFY_SHIFT         (12U)
#define I3C_SERRWARNMASK_HNOVERIFY_WIDTH         (1U)
#define I3C_SERRWARNMASK_HNOVERIFY(x)            (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARNMASK_HNOVERIFY_SHIFT)) & I3C_SERRWARNMASK_HNOVERIFY_MASK)

#define I3C_SERRWARNMASK_HINVREQ_MASK            (0x2000U)
#define I3C_SERRWARNMASK_HINVREQ_SHIFT           (13U)
#define I3C_SERRWARNMASK_HINVREQ_WIDTH           (1U)
#define I3C_SERRWARNMASK_HINVREQ(x)              (((uint32_t)(((uint32_t)(x)) << I3C_SERRWARNMASK_HINVREQ_SHIFT)) & I3C_SERRWARNMASK_HINVREQ_MASK)
/*! @} */

/*! @name GROUPDEF - Group Definitions */
/*! @{ */

#define I3C_GROUPDEF_GRP0ENA_MASK                (0x1U)
#define I3C_GROUPDEF_GRP0ENA_SHIFT               (0U)
#define I3C_GROUPDEF_GRP0ENA_WIDTH               (1U)
#define I3C_GROUPDEF_GRP0ENA(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_GROUPDEF_GRP0ENA_SHIFT)) & I3C_GROUPDEF_GRP0ENA_MASK)

#define I3C_GROUPDEF_GRP0DA_MASK                 (0xFEU)
#define I3C_GROUPDEF_GRP0DA_SHIFT                (1U)
#define I3C_GROUPDEF_GRP0DA_WIDTH                (7U)
#define I3C_GROUPDEF_GRP0DA(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_GROUPDEF_GRP0DA_SHIFT)) & I3C_GROUPDEF_GRP0DA_MASK)

#define I3C_GROUPDEF_GRP1ENA_MASK                (0x100U)
#define I3C_GROUPDEF_GRP1ENA_SHIFT               (8U)
#define I3C_GROUPDEF_GRP1ENA_WIDTH               (1U)
#define I3C_GROUPDEF_GRP1ENA(x)                  (((uint32_t)(((uint32_t)(x)) << I3C_GROUPDEF_GRP1ENA_SHIFT)) & I3C_GROUPDEF_GRP1ENA_MASK)

#define I3C_GROUPDEF_GRP1DA_MASK                 (0xFE00U)
#define I3C_GROUPDEF_GRP1DA_SHIFT                (9U)
#define I3C_GROUPDEF_GRP1DA_WIDTH                (7U)
#define I3C_GROUPDEF_GRP1DA(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_GROUPDEF_GRP1DA_SHIFT)) & I3C_GROUPDEF_GRP1DA_MASK)
/*! @} */

/*! @name SMAPCTRL0 - Map Feature Control 0 */
/*! @{ */

#define I3C_SMAPCTRL0_ENA_MASK                   (0x1U)
#define I3C_SMAPCTRL0_ENA_SHIFT                  (0U)
#define I3C_SMAPCTRL0_ENA_WIDTH                  (1U)
#define I3C_SMAPCTRL0_ENA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL0_ENA_SHIFT)) & I3C_SMAPCTRL0_ENA_MASK)

#define I3C_SMAPCTRL0_DA_MASK                    (0xFEU)
#define I3C_SMAPCTRL0_DA_SHIFT                   (1U)
#define I3C_SMAPCTRL0_DA_WIDTH                   (7U)
#define I3C_SMAPCTRL0_DA(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL0_DA_SHIFT)) & I3C_SMAPCTRL0_DA_MASK)

#define I3C_SMAPCTRL0_CAUSE_MASK                 (0x700U)
#define I3C_SMAPCTRL0_CAUSE_SHIFT                (8U)
#define I3C_SMAPCTRL0_CAUSE_WIDTH                (3U)
#define I3C_SMAPCTRL0_CAUSE(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL0_CAUSE_SHIFT)) & I3C_SMAPCTRL0_CAUSE_MASK)
/*! @} */

/*! @name SMAPCTRL1 - Map Feature Control 1 */
/*! @{ */

#define I3C_SMAPCTRL1_ENA_MASK                   (0x1U)
#define I3C_SMAPCTRL1_ENA_SHIFT                  (0U)
#define I3C_SMAPCTRL1_ENA_WIDTH                  (1U)
#define I3C_SMAPCTRL1_ENA(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL1_ENA_SHIFT)) & I3C_SMAPCTRL1_ENA_MASK)

#define I3C_SMAPCTRL1_ADDR_MASK                  (0xFEU)
#define I3C_SMAPCTRL1_ADDR_SHIFT                 (1U)
#define I3C_SMAPCTRL1_ADDR_WIDTH                 (7U)
#define I3C_SMAPCTRL1_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL1_ADDR_SHIFT)) & I3C_SMAPCTRL1_ADDR_MASK)

#define I3C_SMAPCTRL1_MAPSA_MASK                 (0x100U)
#define I3C_SMAPCTRL1_MAPSA_SHIFT                (8U)
#define I3C_SMAPCTRL1_MAPSA_WIDTH                (1U)
#define I3C_SMAPCTRL1_MAPSA(x)                   (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL1_MAPSA_SHIFT)) & I3C_SMAPCTRL1_MAPSA_MASK)

#define I3C_SMAPCTRL1_NACK_MASK                  (0x1000U)
#define I3C_SMAPCTRL1_NACK_SHIFT                 (12U)
#define I3C_SMAPCTRL1_NACK_WIDTH                 (1U)
#define I3C_SMAPCTRL1_NACK(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL1_NACK_SHIFT)) & I3C_SMAPCTRL1_NACK_MASK)

#define I3C_SMAPCTRL1_AUTO_MASK                  (0x2000U)
#define I3C_SMAPCTRL1_AUTO_SHIFT                 (13U)
#define I3C_SMAPCTRL1_AUTO_WIDTH                 (1U)
#define I3C_SMAPCTRL1_AUTO(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL1_AUTO_SHIFT)) & I3C_SMAPCTRL1_AUTO_MASK)

#define I3C_SMAPCTRL1_DCR_MASK                   (0xFF000000U)
#define I3C_SMAPCTRL1_DCR_SHIFT                  (24U)
#define I3C_SMAPCTRL1_DCR_WIDTH                  (8U)
#define I3C_SMAPCTRL1_DCR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL1_DCR_SHIFT)) & I3C_SMAPCTRL1_DCR_MASK)
/*! @} */

/*! @name SMAPCTRL - Map Feature Control */
/*! @{ */

#define I3C_SMAPCTRL_ENA_MASK                    (0x1U)
#define I3C_SMAPCTRL_ENA_SHIFT                   (0U)
#define I3C_SMAPCTRL_ENA_WIDTH                   (1U)
#define I3C_SMAPCTRL_ENA(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL_ENA_SHIFT)) & I3C_SMAPCTRL_ENA_MASK)

#define I3C_SMAPCTRL_ADDR_MASK                   (0xFEU)
#define I3C_SMAPCTRL_ADDR_SHIFT                  (1U)
#define I3C_SMAPCTRL_ADDR_WIDTH                  (7U)
#define I3C_SMAPCTRL_ADDR(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL_ADDR_SHIFT)) & I3C_SMAPCTRL_ADDR_MASK)

#define I3C_SMAPCTRL_MAPSA_MASK                  (0x100U)
#define I3C_SMAPCTRL_MAPSA_SHIFT                 (8U)
#define I3C_SMAPCTRL_MAPSA_WIDTH                 (1U)
#define I3C_SMAPCTRL_MAPSA(x)                    (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL_MAPSA_SHIFT)) & I3C_SMAPCTRL_MAPSA_MASK)

#define I3C_SMAPCTRL_NACK_MASK                   (0x1000U)
#define I3C_SMAPCTRL_NACK_SHIFT                  (12U)
#define I3C_SMAPCTRL_NACK_WIDTH                  (1U)
#define I3C_SMAPCTRL_NACK(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL_NACK_SHIFT)) & I3C_SMAPCTRL_NACK_MASK)

#define I3C_SMAPCTRL_AUTO_MASK                   (0x2000U)
#define I3C_SMAPCTRL_AUTO_SHIFT                  (13U)
#define I3C_SMAPCTRL_AUTO_WIDTH                  (1U)
#define I3C_SMAPCTRL_AUTO(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL_AUTO_SHIFT)) & I3C_SMAPCTRL_AUTO_MASK)

#define I3C_SMAPCTRL_DCR_MASK                    (0xFF000000U)
#define I3C_SMAPCTRL_DCR_SHIFT                   (24U)
#define I3C_SMAPCTRL_DCR_WIDTH                   (8U)
#define I3C_SMAPCTRL_DCR(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SMAPCTRL_DCR_SHIFT)) & I3C_SMAPCTRL_DCR_MASK)
/*! @} */

/*! @name IBIEXT1 - Extended IBI Data 1 */
/*! @{ */

#define I3C_IBIEXT1_CNT_MASK                     (0x7U)
#define I3C_IBIEXT1_CNT_SHIFT                    (0U)
#define I3C_IBIEXT1_CNT_WIDTH                    (3U)
#define I3C_IBIEXT1_CNT(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT1_CNT_SHIFT)) & I3C_IBIEXT1_CNT_MASK)

#define I3C_IBIEXT1_MAX_MASK                     (0x70U)
#define I3C_IBIEXT1_MAX_SHIFT                    (4U)
#define I3C_IBIEXT1_MAX_WIDTH                    (3U)
#define I3C_IBIEXT1_MAX(x)                       (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT1_MAX_SHIFT)) & I3C_IBIEXT1_MAX_MASK)

#define I3C_IBIEXT1_EXT1_MASK                    (0xFF00U)
#define I3C_IBIEXT1_EXT1_SHIFT                   (8U)
#define I3C_IBIEXT1_EXT1_WIDTH                   (8U)
#define I3C_IBIEXT1_EXT1(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT1_EXT1_SHIFT)) & I3C_IBIEXT1_EXT1_MASK)

#define I3C_IBIEXT1_EXT2_MASK                    (0xFF0000U)
#define I3C_IBIEXT1_EXT2_SHIFT                   (16U)
#define I3C_IBIEXT1_EXT2_WIDTH                   (8U)
#define I3C_IBIEXT1_EXT2(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT1_EXT2_SHIFT)) & I3C_IBIEXT1_EXT2_MASK)

#define I3C_IBIEXT1_EXT3_MASK                    (0xFF000000U)
#define I3C_IBIEXT1_EXT3_SHIFT                   (24U)
#define I3C_IBIEXT1_EXT3_WIDTH                   (8U)
#define I3C_IBIEXT1_EXT3(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT1_EXT3_SHIFT)) & I3C_IBIEXT1_EXT3_MASK)
/*! @} */

/*! @name IBIEXT2 - Extended IBI Data 2 */
/*! @{ */

#define I3C_IBIEXT2_EXT4_MASK                    (0xFFU)
#define I3C_IBIEXT2_EXT4_SHIFT                   (0U)
#define I3C_IBIEXT2_EXT4_WIDTH                   (8U)
#define I3C_IBIEXT2_EXT4(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_IBIEXT2_EXT4_SHIFT)) & I3C_IBIEXT2_EXT4_MASK)
/*! @} */

/*! @name SWDATAW - Slave Write Word Data (to bus) */
/*! @{ */

#define I3C_SWDATAW_DATA_MASK                    (0xFFFFFFFFU)
#define I3C_SWDATAW_DATA_SHIFT                   (0U)
#define I3C_SWDATAW_DATA_WIDTH                   (32U)
#define I3C_SWDATAW_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << I3C_SWDATAW_DATA_SHIFT)) & I3C_SWDATAW_DATA_MASK)
/*! @} */

/*! @name SRDATAW - Slave Read Word Data (from bus) */
/*! @{ */

#define I3C_SRDATAW_VALUE_MASK                   (0xFFFFFFFFU)
#define I3C_SRDATAW_VALUE_SHIFT                  (0U)
#define I3C_SRDATAW_VALUE_WIDTH                  (32U)
#define I3C_SRDATAW_VALUE(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SRDATAW_VALUE_SHIFT)) & I3C_SRDATAW_VALUE_MASK)
/*! @} */

/*! @name SELFRESET - Self Reset */
/*! @{ */

#define I3C_SELFRESET_RST_MASK                   (0x1U)
#define I3C_SELFRESET_RST_SHIFT                  (0U)
#define I3C_SELFRESET_RST_WIDTH                  (1U)
#define I3C_SELFRESET_RST(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SELFRESET_RST_SHIFT)) & I3C_SELFRESET_RST_MASK)

#define I3C_SELFRESET_KEY_MASK                   (0xFFFFFF00U)
#define I3C_SELFRESET_KEY_SHIFT                  (8U)
#define I3C_SELFRESET_KEY_WIDTH                  (24U)
#define I3C_SELFRESET_KEY(x)                     (((uint32_t)(((uint32_t)(x)) << I3C_SELFRESET_KEY_SHIFT)) & I3C_SELFRESET_KEY_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group I3C_Register_Masks */

/*!
 * @}
 */ /* end of group I3C_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_I3C_H_) */
