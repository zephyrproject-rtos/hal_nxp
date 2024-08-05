/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_USDHC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_USDHC
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
#if !defined(S32Z2_USDHC_H_)  /* Check if memory map has not been already included */
#define S32Z2_USDHC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- USDHC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USDHC_Peripheral_Access_Layer USDHC Peripheral Access Layer
 * @{
 */

/** USDHC - Register Layout Typedef */
typedef struct {
  __IO uint32_t DS_ADDR;                           /**< DMA System Address, offset: 0x0 */
  __IO uint32_t BLK_ATT;                           /**< Block Attributes, offset: 0x4 */
  __IO uint32_t CMD_ARG;                           /**< Command Argument, offset: 0x8 */
  __IO uint32_t CMD_XFR_TYP;                       /**< Command Transfer Type, offset: 0xC */
  __I  uint32_t CMD_RSP0;                          /**< Command Response0, offset: 0x10 */
  __I  uint32_t CMD_RSP1;                          /**< Command Response1, offset: 0x14 */
  __I  uint32_t CMD_RSP2;                          /**< Command Response2, offset: 0x18 */
  __I  uint32_t CMD_RSP3;                          /**< Command Response3, offset: 0x1C */
  __IO uint32_t DATA_BUFF_ACC_PORT;                /**< Data Buffer Access Port, offset: 0x20 */
  __I  uint32_t PRES_STATE;                        /**< Present State, offset: 0x24 */
  __IO uint32_t PROT_CTRL;                         /**< Protocol Control, offset: 0x28 */
  __IO uint32_t SYS_CTRL;                          /**< System Control, offset: 0x2C */
  __IO uint32_t INT_STATUS;                        /**< Interrupt Status, offset: 0x30 */
  __IO uint32_t INT_STATUS_EN;                     /**< Interrupt Status Enable, offset: 0x34 */
  __IO uint32_t INT_SIGNAL_EN;                     /**< Interrupt Signal Enable, offset: 0x38 */
  __IO uint32_t AUTOCMD12_ERR_STATUS;              /**< Auto CMD12 Error Status, offset: 0x3C */
  __IO uint32_t HOST_CTRL_CAP;                     /**< Host Controller Capabilities, offset: 0x40 */
  __IO uint32_t WTMK_LVL;                          /**< Watermark Level, offset: 0x44 */
  __IO uint32_t MIX_CTRL;                          /**< Mixer Control, offset: 0x48 */
  uint8_t RESERVED_0[4];
  __O  uint32_t FORCE_EVENT;                       /**< Force Event, offset: 0x50 */
  __I  uint32_t ADMA_ERR_STATUS;                   /**< ADMA Error Status, offset: 0x54 */
  __IO uint32_t ADMA_SYS_ADDR;                     /**< ADMA System Address, offset: 0x58 */
  uint8_t RESERVED_1[4];
  __IO uint32_t DLL_CTRL;                          /**< DLL (Delay Line) Control, offset: 0x60 */
  __I  uint32_t DLL_STATUS;                        /**< DLL Status, offset: 0x64 */
  __IO uint32_t CLK_TUNE_CTRL_STATUS;              /**< CLK Tuning Control and Status, offset: 0x68 */
  uint8_t RESERVED_2[4];
  __IO uint32_t STROBE_DLL_CTRL;                   /**< Strobe DLL control, offset: 0x70 */
  __I  uint32_t STROBE_DLL_STATUS;                 /**< Strobe DLL status, offset: 0x74 */
  uint8_t RESERVED_3[72];
  __IO uint32_t VEND_SPEC;                         /**< Vendor Specific Register, offset: 0xC0 */
  __IO uint32_t MMC_BOOT;                          /**< eMMC Boot, offset: 0xC4 */
  __IO uint32_t VEND_SPEC2;                        /**< Vendor Specific 2 Register, offset: 0xC8 */
  __IO uint32_t TUNING_CTRL;                       /**< Tuning Control, offset: 0xCC */
  uint8_t RESERVED_4[48];
  __I  uint32_t CQVER;                             /**< Command Queuing Version, offset: 0x100 */
  __IO uint32_t CQCAP;                             /**< Command Queuing Capabilities, offset: 0x104 */
  __IO uint32_t CQCFG;                             /**< Command Queuing Configuration, offset: 0x108 */
  __IO uint32_t CQCTL;                             /**< Command Queuing Control, offset: 0x10C */
  __IO uint32_t CQIS;                              /**< Command Queuing Interrupt Status, offset: 0x110 */
  __IO uint32_t CQISTE;                            /**< Command Queuing Interrupt Status Enable, offset: 0x114 */
  __IO uint32_t CQISGE;                            /**< Command Queuing Interrupt Signal Enable, offset: 0x118 */
  __IO uint32_t CQIC;                              /**< Command Queuing Interrupt Coalescing, offset: 0x11C */
  __IO uint32_t CQTDLBA;                           /**< Command Queuing Task Descriptor List Base Address, offset: 0x120 */
  __IO uint32_t CQTDLBAU;                          /**< Command Queuing Task Descriptor List Base Address Upper 32 Bits, offset: 0x124 */
  __IO uint32_t CQTDBR;                            /**< Command Queuing Task Doorbell, offset: 0x128 */
  __IO uint32_t CQTCN;                             /**< Command Queuing Task Completion Notification, offset: 0x12C */
  __I  uint32_t CQDQS;                             /**< Command Queuing Device Queue Status, offset: 0x130 */
  __I  uint32_t CQDPT;                             /**< Command Queuing Device Pending Tasks, offset: 0x134 */
  __IO uint32_t CQTCLR;                            /**< Command Queuing Task Clear, offset: 0x138 */
  uint8_t RESERVED_5[4];
  __IO uint32_t CQSSC1;                            /**< Command Queuing Send Status Configuration 1, offset: 0x140 */
  __IO uint32_t CQSSC2;                            /**< Command Queuing Send Status Configuration 2, offset: 0x144 */
  __I  uint32_t CQCRDCT;                           /**< Command Queuing Command Response for Direct-Command Task, offset: 0x148 */
  uint8_t RESERVED_6[4];
  __IO uint32_t CQRMEM;                            /**< Command Queuing Response Mode Error Mask, offset: 0x150 */
  __I  uint32_t CQTERRI;                           /**< Command Queuing Task Error Information, offset: 0x154 */
  __I  uint32_t CQCRI;                             /**< Command Queuing Command Response Index, offset: 0x158 */
  __I  uint32_t CQCRA;                             /**< Command Queuing Command Response Argument, offset: 0x15C */
} USDHC_Type, *USDHC_MemMapPtr;

/** Number of instances of the USDHC module. */
#define USDHC_INSTANCE_COUNT                     (1u)

/* USDHC - Peripheral instance base addresses */
/** Peripheral USDHC base address */
#define IP_USDHC_BASE                            (0x42300000u)
/** Peripheral USDHC base pointer */
#define IP_USDHC                                 ((USDHC_Type *)IP_USDHC_BASE)
/** Array initializer of USDHC peripheral base addresses */
#define IP_USDHC_BASE_ADDRS                      { IP_USDHC_BASE }
/** Array initializer of USDHC peripheral base pointers */
#define IP_USDHC_BASE_PTRS                       { IP_USDHC }

/* ----------------------------------------------------------------------------
   -- USDHC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USDHC_Register_Masks USDHC Register Masks
 * @{
 */

/*! @name DS_ADDR - DMA System Address */
/*! @{ */

#define USDHC_DS_ADDR_DS_ADDR_MASK               (0xFFFFFFFFU)
#define USDHC_DS_ADDR_DS_ADDR_SHIFT              (0U)
#define USDHC_DS_ADDR_DS_ADDR_WIDTH              (32U)
#define USDHC_DS_ADDR_DS_ADDR(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_DS_ADDR_DS_ADDR_SHIFT)) & USDHC_DS_ADDR_DS_ADDR_MASK)
/*! @} */

/*! @name BLK_ATT - Block Attributes */
/*! @{ */

#define USDHC_BLK_ATT_BLKSIZE_MASK               (0x1FFFU)
#define USDHC_BLK_ATT_BLKSIZE_SHIFT              (0U)
#define USDHC_BLK_ATT_BLKSIZE_WIDTH              (13U)
#define USDHC_BLK_ATT_BLKSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_BLK_ATT_BLKSIZE_SHIFT)) & USDHC_BLK_ATT_BLKSIZE_MASK)

#define USDHC_BLK_ATT_BLKCNT_MASK                (0xFFFF0000U)
#define USDHC_BLK_ATT_BLKCNT_SHIFT               (16U)
#define USDHC_BLK_ATT_BLKCNT_WIDTH               (16U)
#define USDHC_BLK_ATT_BLKCNT(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_BLK_ATT_BLKCNT_SHIFT)) & USDHC_BLK_ATT_BLKCNT_MASK)
/*! @} */

/*! @name CMD_ARG - Command Argument */
/*! @{ */

#define USDHC_CMD_ARG_CMDARG_MASK                (0xFFFFFFFFU)
#define USDHC_CMD_ARG_CMDARG_SHIFT               (0U)
#define USDHC_CMD_ARG_CMDARG_WIDTH               (32U)
#define USDHC_CMD_ARG_CMDARG(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_ARG_CMDARG_SHIFT)) & USDHC_CMD_ARG_CMDARG_MASK)
/*! @} */

/*! @name CMD_XFR_TYP - Command Transfer Type */
/*! @{ */

#define USDHC_CMD_XFR_TYP_DMAEN_MASK             (0x1U)
#define USDHC_CMD_XFR_TYP_DMAEN_SHIFT            (0U)
#define USDHC_CMD_XFR_TYP_DMAEN_WIDTH            (1U)
#define USDHC_CMD_XFR_TYP_DMAEN(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_DMAEN_SHIFT)) & USDHC_CMD_XFR_TYP_DMAEN_MASK)

#define USDHC_CMD_XFR_TYP_BCEN_MASK              (0x2U)
#define USDHC_CMD_XFR_TYP_BCEN_SHIFT             (1U)
#define USDHC_CMD_XFR_TYP_BCEN_WIDTH             (1U)
#define USDHC_CMD_XFR_TYP_BCEN(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_BCEN_SHIFT)) & USDHC_CMD_XFR_TYP_BCEN_MASK)

#define USDHC_CMD_XFR_TYP_AC12EN_MASK            (0x4U)
#define USDHC_CMD_XFR_TYP_AC12EN_SHIFT           (2U)
#define USDHC_CMD_XFR_TYP_AC12EN_WIDTH           (1U)
#define USDHC_CMD_XFR_TYP_AC12EN(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_AC12EN_SHIFT)) & USDHC_CMD_XFR_TYP_AC12EN_MASK)

#define USDHC_CMD_XFR_TYP_DDR_EN_MASK            (0x8U)
#define USDHC_CMD_XFR_TYP_DDR_EN_SHIFT           (3U)
#define USDHC_CMD_XFR_TYP_DDR_EN_WIDTH           (1U)
#define USDHC_CMD_XFR_TYP_DDR_EN(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_DDR_EN_SHIFT)) & USDHC_CMD_XFR_TYP_DDR_EN_MASK)

#define USDHC_CMD_XFR_TYP_DTDSEL_MASK            (0x10U)
#define USDHC_CMD_XFR_TYP_DTDSEL_SHIFT           (4U)
#define USDHC_CMD_XFR_TYP_DTDSEL_WIDTH           (1U)
#define USDHC_CMD_XFR_TYP_DTDSEL(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_DTDSEL_SHIFT)) & USDHC_CMD_XFR_TYP_DTDSEL_MASK)

#define USDHC_CMD_XFR_TYP_MSBSEL_MASK            (0x20U)
#define USDHC_CMD_XFR_TYP_MSBSEL_SHIFT           (5U)
#define USDHC_CMD_XFR_TYP_MSBSEL_WIDTH           (1U)
#define USDHC_CMD_XFR_TYP_MSBSEL(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_MSBSEL_SHIFT)) & USDHC_CMD_XFR_TYP_MSBSEL_MASK)

#define USDHC_CMD_XFR_TYP_NIBBLE_POS_MASK        (0x40U)
#define USDHC_CMD_XFR_TYP_NIBBLE_POS_SHIFT       (6U)
#define USDHC_CMD_XFR_TYP_NIBBLE_POS_WIDTH       (1U)
#define USDHC_CMD_XFR_TYP_NIBBLE_POS(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_NIBBLE_POS_SHIFT)) & USDHC_CMD_XFR_TYP_NIBBLE_POS_MASK)

#define USDHC_CMD_XFR_TYP_AC23EN_MASK            (0x80U)
#define USDHC_CMD_XFR_TYP_AC23EN_SHIFT           (7U)
#define USDHC_CMD_XFR_TYP_AC23EN_WIDTH           (1U)
#define USDHC_CMD_XFR_TYP_AC23EN(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_AC23EN_SHIFT)) & USDHC_CMD_XFR_TYP_AC23EN_MASK)

#define USDHC_CMD_XFR_TYP_RSPTYP_MASK            (0x30000U)
#define USDHC_CMD_XFR_TYP_RSPTYP_SHIFT           (16U)
#define USDHC_CMD_XFR_TYP_RSPTYP_WIDTH           (2U)
#define USDHC_CMD_XFR_TYP_RSPTYP(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_RSPTYP_SHIFT)) & USDHC_CMD_XFR_TYP_RSPTYP_MASK)

#define USDHC_CMD_XFR_TYP_CCCEN_MASK             (0x80000U)
#define USDHC_CMD_XFR_TYP_CCCEN_SHIFT            (19U)
#define USDHC_CMD_XFR_TYP_CCCEN_WIDTH            (1U)
#define USDHC_CMD_XFR_TYP_CCCEN(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_CCCEN_SHIFT)) & USDHC_CMD_XFR_TYP_CCCEN_MASK)

#define USDHC_CMD_XFR_TYP_CICEN_MASK             (0x100000U)
#define USDHC_CMD_XFR_TYP_CICEN_SHIFT            (20U)
#define USDHC_CMD_XFR_TYP_CICEN_WIDTH            (1U)
#define USDHC_CMD_XFR_TYP_CICEN(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_CICEN_SHIFT)) & USDHC_CMD_XFR_TYP_CICEN_MASK)

#define USDHC_CMD_XFR_TYP_DPSEL_MASK             (0x200000U)
#define USDHC_CMD_XFR_TYP_DPSEL_SHIFT            (21U)
#define USDHC_CMD_XFR_TYP_DPSEL_WIDTH            (1U)
#define USDHC_CMD_XFR_TYP_DPSEL(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_DPSEL_SHIFT)) & USDHC_CMD_XFR_TYP_DPSEL_MASK)

#define USDHC_CMD_XFR_TYP_CMDTYP_MASK            (0xC00000U)
#define USDHC_CMD_XFR_TYP_CMDTYP_SHIFT           (22U)
#define USDHC_CMD_XFR_TYP_CMDTYP_WIDTH           (2U)
#define USDHC_CMD_XFR_TYP_CMDTYP(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_CMDTYP_SHIFT)) & USDHC_CMD_XFR_TYP_CMDTYP_MASK)

#define USDHC_CMD_XFR_TYP_CMDINX_MASK            (0x3F000000U)
#define USDHC_CMD_XFR_TYP_CMDINX_SHIFT           (24U)
#define USDHC_CMD_XFR_TYP_CMDINX_WIDTH           (6U)
#define USDHC_CMD_XFR_TYP_CMDINX(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_XFR_TYP_CMDINX_SHIFT)) & USDHC_CMD_XFR_TYP_CMDINX_MASK)
/*! @} */

/*! @name CMD_RSP0 - Command Response0 */
/*! @{ */

#define USDHC_CMD_RSP0_CMDRSP0_MASK              (0xFFFFFFFFU)
#define USDHC_CMD_RSP0_CMDRSP0_SHIFT             (0U)
#define USDHC_CMD_RSP0_CMDRSP0_WIDTH             (32U)
#define USDHC_CMD_RSP0_CMDRSP0(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_RSP0_CMDRSP0_SHIFT)) & USDHC_CMD_RSP0_CMDRSP0_MASK)
/*! @} */

/*! @name CMD_RSP1 - Command Response1 */
/*! @{ */

#define USDHC_CMD_RSP1_CMDRSP1_MASK              (0xFFFFFFFFU)
#define USDHC_CMD_RSP1_CMDRSP1_SHIFT             (0U)
#define USDHC_CMD_RSP1_CMDRSP1_WIDTH             (32U)
#define USDHC_CMD_RSP1_CMDRSP1(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_RSP1_CMDRSP1_SHIFT)) & USDHC_CMD_RSP1_CMDRSP1_MASK)
/*! @} */

/*! @name CMD_RSP2 - Command Response2 */
/*! @{ */

#define USDHC_CMD_RSP2_CMDRSP2_MASK              (0xFFFFFFFFU)
#define USDHC_CMD_RSP2_CMDRSP2_SHIFT             (0U)
#define USDHC_CMD_RSP2_CMDRSP2_WIDTH             (32U)
#define USDHC_CMD_RSP2_CMDRSP2(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_RSP2_CMDRSP2_SHIFT)) & USDHC_CMD_RSP2_CMDRSP2_MASK)
/*! @} */

/*! @name CMD_RSP3 - Command Response3 */
/*! @{ */

#define USDHC_CMD_RSP3_CMDRSP3_MASK              (0xFFFFFFFFU)
#define USDHC_CMD_RSP3_CMDRSP3_SHIFT             (0U)
#define USDHC_CMD_RSP3_CMDRSP3_WIDTH             (32U)
#define USDHC_CMD_RSP3_CMDRSP3(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_CMD_RSP3_CMDRSP3_SHIFT)) & USDHC_CMD_RSP3_CMDRSP3_MASK)
/*! @} */

/*! @name DATA_BUFF_ACC_PORT - Data Buffer Access Port */
/*! @{ */

#define USDHC_DATA_BUFF_ACC_PORT_DATCONT_MASK    (0xFFFFFFFFU)
#define USDHC_DATA_BUFF_ACC_PORT_DATCONT_SHIFT   (0U)
#define USDHC_DATA_BUFF_ACC_PORT_DATCONT_WIDTH   (32U)
#define USDHC_DATA_BUFF_ACC_PORT_DATCONT(x)      (((uint32_t)(((uint32_t)(x)) << USDHC_DATA_BUFF_ACC_PORT_DATCONT_SHIFT)) & USDHC_DATA_BUFF_ACC_PORT_DATCONT_MASK)
/*! @} */

/*! @name PRES_STATE - Present State */
/*! @{ */

#define USDHC_PRES_STATE_CIHB_MASK               (0x1U)
#define USDHC_PRES_STATE_CIHB_SHIFT              (0U)
#define USDHC_PRES_STATE_CIHB_WIDTH              (1U)
#define USDHC_PRES_STATE_CIHB(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_CIHB_SHIFT)) & USDHC_PRES_STATE_CIHB_MASK)

#define USDHC_PRES_STATE_CDIHB_MASK              (0x2U)
#define USDHC_PRES_STATE_CDIHB_SHIFT             (1U)
#define USDHC_PRES_STATE_CDIHB_WIDTH             (1U)
#define USDHC_PRES_STATE_CDIHB(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_CDIHB_SHIFT)) & USDHC_PRES_STATE_CDIHB_MASK)

#define USDHC_PRES_STATE_DLA_MASK                (0x4U)
#define USDHC_PRES_STATE_DLA_SHIFT               (2U)
#define USDHC_PRES_STATE_DLA_WIDTH               (1U)
#define USDHC_PRES_STATE_DLA(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_DLA_SHIFT)) & USDHC_PRES_STATE_DLA_MASK)

#define USDHC_PRES_STATE_SDSTB_MASK              (0x8U)
#define USDHC_PRES_STATE_SDSTB_SHIFT             (3U)
#define USDHC_PRES_STATE_SDSTB_WIDTH             (1U)
#define USDHC_PRES_STATE_SDSTB(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_SDSTB_SHIFT)) & USDHC_PRES_STATE_SDSTB_MASK)

#define USDHC_PRES_STATE_WTA_MASK                (0x100U)
#define USDHC_PRES_STATE_WTA_SHIFT               (8U)
#define USDHC_PRES_STATE_WTA_WIDTH               (1U)
#define USDHC_PRES_STATE_WTA(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_WTA_SHIFT)) & USDHC_PRES_STATE_WTA_MASK)

#define USDHC_PRES_STATE_RTA_MASK                (0x200U)
#define USDHC_PRES_STATE_RTA_SHIFT               (9U)
#define USDHC_PRES_STATE_RTA_WIDTH               (1U)
#define USDHC_PRES_STATE_RTA(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_RTA_SHIFT)) & USDHC_PRES_STATE_RTA_MASK)

#define USDHC_PRES_STATE_BWEN_MASK               (0x400U)
#define USDHC_PRES_STATE_BWEN_SHIFT              (10U)
#define USDHC_PRES_STATE_BWEN_WIDTH              (1U)
#define USDHC_PRES_STATE_BWEN(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_BWEN_SHIFT)) & USDHC_PRES_STATE_BWEN_MASK)

#define USDHC_PRES_STATE_BREN_MASK               (0x800U)
#define USDHC_PRES_STATE_BREN_SHIFT              (11U)
#define USDHC_PRES_STATE_BREN_WIDTH              (1U)
#define USDHC_PRES_STATE_BREN(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_BREN_SHIFT)) & USDHC_PRES_STATE_BREN_MASK)

#define USDHC_PRES_STATE_RTR_MASK                (0x1000U)
#define USDHC_PRES_STATE_RTR_SHIFT               (12U)
#define USDHC_PRES_STATE_RTR_WIDTH               (1U)
#define USDHC_PRES_STATE_RTR(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_RTR_SHIFT)) & USDHC_PRES_STATE_RTR_MASK)

#define USDHC_PRES_STATE_TSCD_MASK               (0x8000U)
#define USDHC_PRES_STATE_TSCD_SHIFT              (15U)
#define USDHC_PRES_STATE_TSCD_WIDTH              (1U)
#define USDHC_PRES_STATE_TSCD(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_TSCD_SHIFT)) & USDHC_PRES_STATE_TSCD_MASK)

#define USDHC_PRES_STATE_CINST_MASK              (0x10000U)
#define USDHC_PRES_STATE_CINST_SHIFT             (16U)
#define USDHC_PRES_STATE_CINST_WIDTH             (1U)
#define USDHC_PRES_STATE_CINST(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_CINST_SHIFT)) & USDHC_PRES_STATE_CINST_MASK)

#define USDHC_PRES_STATE_CLSL_MASK               (0x800000U)
#define USDHC_PRES_STATE_CLSL_SHIFT              (23U)
#define USDHC_PRES_STATE_CLSL_WIDTH              (1U)
#define USDHC_PRES_STATE_CLSL(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_CLSL_SHIFT)) & USDHC_PRES_STATE_CLSL_MASK)

#define USDHC_PRES_STATE_DLSL_MASK               (0xFF000000U)
#define USDHC_PRES_STATE_DLSL_SHIFT              (24U)
#define USDHC_PRES_STATE_DLSL_WIDTH              (8U)
#define USDHC_PRES_STATE_DLSL(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PRES_STATE_DLSL_SHIFT)) & USDHC_PRES_STATE_DLSL_MASK)
/*! @} */

/*! @name PROT_CTRL - Protocol Control */
/*! @{ */

#define USDHC_PROT_CTRL_DTW_MASK                 (0x6U)
#define USDHC_PROT_CTRL_DTW_SHIFT                (1U)
#define USDHC_PROT_CTRL_DTW_WIDTH                (2U)
#define USDHC_PROT_CTRL_DTW(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_DTW_SHIFT)) & USDHC_PROT_CTRL_DTW_MASK)

#define USDHC_PROT_CTRL_D3CD_MASK                (0x8U)
#define USDHC_PROT_CTRL_D3CD_SHIFT               (3U)
#define USDHC_PROT_CTRL_D3CD_WIDTH               (1U)
#define USDHC_PROT_CTRL_D3CD(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_D3CD_SHIFT)) & USDHC_PROT_CTRL_D3CD_MASK)

#define USDHC_PROT_CTRL_EMODE_MASK               (0x30U)
#define USDHC_PROT_CTRL_EMODE_SHIFT              (4U)
#define USDHC_PROT_CTRL_EMODE_WIDTH              (2U)
#define USDHC_PROT_CTRL_EMODE(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_EMODE_SHIFT)) & USDHC_PROT_CTRL_EMODE_MASK)

#define USDHC_PROT_CTRL_DMASEL_MASK              (0x300U)
#define USDHC_PROT_CTRL_DMASEL_SHIFT             (8U)
#define USDHC_PROT_CTRL_DMASEL_WIDTH             (2U)
#define USDHC_PROT_CTRL_DMASEL(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_DMASEL_SHIFT)) & USDHC_PROT_CTRL_DMASEL_MASK)

#define USDHC_PROT_CTRL_SABGREQ_MASK             (0x10000U)
#define USDHC_PROT_CTRL_SABGREQ_SHIFT            (16U)
#define USDHC_PROT_CTRL_SABGREQ_WIDTH            (1U)
#define USDHC_PROT_CTRL_SABGREQ(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_SABGREQ_SHIFT)) & USDHC_PROT_CTRL_SABGREQ_MASK)

#define USDHC_PROT_CTRL_CREQ_MASK                (0x20000U)
#define USDHC_PROT_CTRL_CREQ_SHIFT               (17U)
#define USDHC_PROT_CTRL_CREQ_WIDTH               (1U)
#define USDHC_PROT_CTRL_CREQ(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_CREQ_SHIFT)) & USDHC_PROT_CTRL_CREQ_MASK)

#define USDHC_PROT_CTRL_RWCTL_MASK               (0x40000U)
#define USDHC_PROT_CTRL_RWCTL_SHIFT              (18U)
#define USDHC_PROT_CTRL_RWCTL_WIDTH              (1U)
#define USDHC_PROT_CTRL_RWCTL(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_RWCTL_SHIFT)) & USDHC_PROT_CTRL_RWCTL_MASK)

#define USDHC_PROT_CTRL_IABG_MASK                (0x80000U)
#define USDHC_PROT_CTRL_IABG_SHIFT               (19U)
#define USDHC_PROT_CTRL_IABG_WIDTH               (1U)
#define USDHC_PROT_CTRL_IABG(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_IABG_SHIFT)) & USDHC_PROT_CTRL_IABG_MASK)

#define USDHC_PROT_CTRL_RD_DONE_NO_8CLK_MASK     (0x100000U)
#define USDHC_PROT_CTRL_RD_DONE_NO_8CLK_SHIFT    (20U)
#define USDHC_PROT_CTRL_RD_DONE_NO_8CLK_WIDTH    (1U)
#define USDHC_PROT_CTRL_RD_DONE_NO_8CLK(x)       (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_RD_DONE_NO_8CLK_SHIFT)) & USDHC_PROT_CTRL_RD_DONE_NO_8CLK_MASK)

#define USDHC_PROT_CTRL_WECINT_MASK              (0x1000000U)
#define USDHC_PROT_CTRL_WECINT_SHIFT             (24U)
#define USDHC_PROT_CTRL_WECINT_WIDTH             (1U)
#define USDHC_PROT_CTRL_WECINT(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_WECINT_SHIFT)) & USDHC_PROT_CTRL_WECINT_MASK)

#define USDHC_PROT_CTRL_WECINS_MASK              (0x2000000U)
#define USDHC_PROT_CTRL_WECINS_SHIFT             (25U)
#define USDHC_PROT_CTRL_WECINS_WIDTH             (1U)
#define USDHC_PROT_CTRL_WECINS(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_WECINS_SHIFT)) & USDHC_PROT_CTRL_WECINS_MASK)

#define USDHC_PROT_CTRL_WECRM_MASK               (0x4000000U)
#define USDHC_PROT_CTRL_WECRM_SHIFT              (26U)
#define USDHC_PROT_CTRL_WECRM_WIDTH              (1U)
#define USDHC_PROT_CTRL_WECRM(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_WECRM_SHIFT)) & USDHC_PROT_CTRL_WECRM_MASK)

#define USDHC_PROT_CTRL_NON_EXACT_BLK_RD_MASK    (0x40000000U)
#define USDHC_PROT_CTRL_NON_EXACT_BLK_RD_SHIFT   (30U)
#define USDHC_PROT_CTRL_NON_EXACT_BLK_RD_WIDTH   (1U)
#define USDHC_PROT_CTRL_NON_EXACT_BLK_RD(x)      (((uint32_t)(((uint32_t)(x)) << USDHC_PROT_CTRL_NON_EXACT_BLK_RD_SHIFT)) & USDHC_PROT_CTRL_NON_EXACT_BLK_RD_MASK)
/*! @} */

/*! @name SYS_CTRL - System Control */
/*! @{ */

#define USDHC_SYS_CTRL_DVS_MASK                  (0xF0U)
#define USDHC_SYS_CTRL_DVS_SHIFT                 (4U)
#define USDHC_SYS_CTRL_DVS_WIDTH                 (4U)
#define USDHC_SYS_CTRL_DVS(x)                    (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_DVS_SHIFT)) & USDHC_SYS_CTRL_DVS_MASK)

#define USDHC_SYS_CTRL_SDCLKFS_MASK              (0xFF00U)
#define USDHC_SYS_CTRL_SDCLKFS_SHIFT             (8U)
#define USDHC_SYS_CTRL_SDCLKFS_WIDTH             (8U)
#define USDHC_SYS_CTRL_SDCLKFS(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_SDCLKFS_SHIFT)) & USDHC_SYS_CTRL_SDCLKFS_MASK)

#define USDHC_SYS_CTRL_DTOCV_MASK                (0xF0000U)
#define USDHC_SYS_CTRL_DTOCV_SHIFT               (16U)
#define USDHC_SYS_CTRL_DTOCV_WIDTH               (4U)
#define USDHC_SYS_CTRL_DTOCV(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_DTOCV_SHIFT)) & USDHC_SYS_CTRL_DTOCV_MASK)

#define USDHC_SYS_CTRL_RST_FIFO_MASK             (0x400000U)
#define USDHC_SYS_CTRL_RST_FIFO_SHIFT            (22U)
#define USDHC_SYS_CTRL_RST_FIFO_WIDTH            (1U)
#define USDHC_SYS_CTRL_RST_FIFO(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_RST_FIFO_SHIFT)) & USDHC_SYS_CTRL_RST_FIFO_MASK)

#define USDHC_SYS_CTRL_IPP_RST_N_MASK            (0x800000U)
#define USDHC_SYS_CTRL_IPP_RST_N_SHIFT           (23U)
#define USDHC_SYS_CTRL_IPP_RST_N_WIDTH           (1U)
#define USDHC_SYS_CTRL_IPP_RST_N(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_IPP_RST_N_SHIFT)) & USDHC_SYS_CTRL_IPP_RST_N_MASK)

#define USDHC_SYS_CTRL_RSTA_MASK                 (0x1000000U)
#define USDHC_SYS_CTRL_RSTA_SHIFT                (24U)
#define USDHC_SYS_CTRL_RSTA_WIDTH                (1U)
#define USDHC_SYS_CTRL_RSTA(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_RSTA_SHIFT)) & USDHC_SYS_CTRL_RSTA_MASK)

#define USDHC_SYS_CTRL_RSTC_MASK                 (0x2000000U)
#define USDHC_SYS_CTRL_RSTC_SHIFT                (25U)
#define USDHC_SYS_CTRL_RSTC_WIDTH                (1U)
#define USDHC_SYS_CTRL_RSTC(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_RSTC_SHIFT)) & USDHC_SYS_CTRL_RSTC_MASK)

#define USDHC_SYS_CTRL_RSTD_MASK                 (0x4000000U)
#define USDHC_SYS_CTRL_RSTD_SHIFT                (26U)
#define USDHC_SYS_CTRL_RSTD_WIDTH                (1U)
#define USDHC_SYS_CTRL_RSTD(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_RSTD_SHIFT)) & USDHC_SYS_CTRL_RSTD_MASK)

#define USDHC_SYS_CTRL_INITA_MASK                (0x8000000U)
#define USDHC_SYS_CTRL_INITA_SHIFT               (27U)
#define USDHC_SYS_CTRL_INITA_WIDTH               (1U)
#define USDHC_SYS_CTRL_INITA(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_INITA_SHIFT)) & USDHC_SYS_CTRL_INITA_MASK)

#define USDHC_SYS_CTRL_RSTT_MASK                 (0x10000000U)
#define USDHC_SYS_CTRL_RSTT_SHIFT                (28U)
#define USDHC_SYS_CTRL_RSTT_WIDTH                (1U)
#define USDHC_SYS_CTRL_RSTT(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_SYS_CTRL_RSTT_SHIFT)) & USDHC_SYS_CTRL_RSTT_MASK)
/*! @} */

/*! @name INT_STATUS - Interrupt Status */
/*! @{ */

#define USDHC_INT_STATUS_CC_MASK                 (0x1U)
#define USDHC_INT_STATUS_CC_SHIFT                (0U)
#define USDHC_INT_STATUS_CC_WIDTH                (1U)
#define USDHC_INT_STATUS_CC(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CC_SHIFT)) & USDHC_INT_STATUS_CC_MASK)

#define USDHC_INT_STATUS_TC_MASK                 (0x2U)
#define USDHC_INT_STATUS_TC_SHIFT                (1U)
#define USDHC_INT_STATUS_TC_WIDTH                (1U)
#define USDHC_INT_STATUS_TC(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_TC_SHIFT)) & USDHC_INT_STATUS_TC_MASK)

#define USDHC_INT_STATUS_BGE_MASK                (0x4U)
#define USDHC_INT_STATUS_BGE_SHIFT               (2U)
#define USDHC_INT_STATUS_BGE_WIDTH               (1U)
#define USDHC_INT_STATUS_BGE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_BGE_SHIFT)) & USDHC_INT_STATUS_BGE_MASK)

#define USDHC_INT_STATUS_DINT_MASK               (0x8U)
#define USDHC_INT_STATUS_DINT_SHIFT              (3U)
#define USDHC_INT_STATUS_DINT_WIDTH              (1U)
#define USDHC_INT_STATUS_DINT(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_DINT_SHIFT)) & USDHC_INT_STATUS_DINT_MASK)

#define USDHC_INT_STATUS_BWR_MASK                (0x10U)
#define USDHC_INT_STATUS_BWR_SHIFT               (4U)
#define USDHC_INT_STATUS_BWR_WIDTH               (1U)
#define USDHC_INT_STATUS_BWR(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_BWR_SHIFT)) & USDHC_INT_STATUS_BWR_MASK)

#define USDHC_INT_STATUS_BRR_MASK                (0x20U)
#define USDHC_INT_STATUS_BRR_SHIFT               (5U)
#define USDHC_INT_STATUS_BRR_WIDTH               (1U)
#define USDHC_INT_STATUS_BRR(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_BRR_SHIFT)) & USDHC_INT_STATUS_BRR_MASK)

#define USDHC_INT_STATUS_CINS_MASK               (0x40U)
#define USDHC_INT_STATUS_CINS_SHIFT              (6U)
#define USDHC_INT_STATUS_CINS_WIDTH              (1U)
#define USDHC_INT_STATUS_CINS(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CINS_SHIFT)) & USDHC_INT_STATUS_CINS_MASK)

#define USDHC_INT_STATUS_CRM_MASK                (0x80U)
#define USDHC_INT_STATUS_CRM_SHIFT               (7U)
#define USDHC_INT_STATUS_CRM_WIDTH               (1U)
#define USDHC_INT_STATUS_CRM(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CRM_SHIFT)) & USDHC_INT_STATUS_CRM_MASK)

#define USDHC_INT_STATUS_CINT_MASK               (0x100U)
#define USDHC_INT_STATUS_CINT_SHIFT              (8U)
#define USDHC_INT_STATUS_CINT_WIDTH              (1U)
#define USDHC_INT_STATUS_CINT(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CINT_SHIFT)) & USDHC_INT_STATUS_CINT_MASK)

#define USDHC_INT_STATUS_RTE_MASK                (0x1000U)
#define USDHC_INT_STATUS_RTE_SHIFT               (12U)
#define USDHC_INT_STATUS_RTE_WIDTH               (1U)
#define USDHC_INT_STATUS_RTE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_RTE_SHIFT)) & USDHC_INT_STATUS_RTE_MASK)

#define USDHC_INT_STATUS_TP_MASK                 (0x2000U)
#define USDHC_INT_STATUS_TP_SHIFT                (13U)
#define USDHC_INT_STATUS_TP_WIDTH                (1U)
#define USDHC_INT_STATUS_TP(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_TP_SHIFT)) & USDHC_INT_STATUS_TP_MASK)

#define USDHC_INT_STATUS_CQI_MASK                (0x4000U)
#define USDHC_INT_STATUS_CQI_SHIFT               (14U)
#define USDHC_INT_STATUS_CQI_WIDTH               (1U)
#define USDHC_INT_STATUS_CQI(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CQI_SHIFT)) & USDHC_INT_STATUS_CQI_MASK)

#define USDHC_INT_STATUS_ERR_INT_STATUS_MASK     (0x8000U)
#define USDHC_INT_STATUS_ERR_INT_STATUS_SHIFT    (15U)
#define USDHC_INT_STATUS_ERR_INT_STATUS_WIDTH    (1U)
#define USDHC_INT_STATUS_ERR_INT_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_ERR_INT_STATUS_SHIFT)) & USDHC_INT_STATUS_ERR_INT_STATUS_MASK)

#define USDHC_INT_STATUS_CTOE_MASK               (0x10000U)
#define USDHC_INT_STATUS_CTOE_SHIFT              (16U)
#define USDHC_INT_STATUS_CTOE_WIDTH              (1U)
#define USDHC_INT_STATUS_CTOE(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CTOE_SHIFT)) & USDHC_INT_STATUS_CTOE_MASK)

#define USDHC_INT_STATUS_CCE_MASK                (0x20000U)
#define USDHC_INT_STATUS_CCE_SHIFT               (17U)
#define USDHC_INT_STATUS_CCE_WIDTH               (1U)
#define USDHC_INT_STATUS_CCE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CCE_SHIFT)) & USDHC_INT_STATUS_CCE_MASK)

#define USDHC_INT_STATUS_CEBE_MASK               (0x40000U)
#define USDHC_INT_STATUS_CEBE_SHIFT              (18U)
#define USDHC_INT_STATUS_CEBE_WIDTH              (1U)
#define USDHC_INT_STATUS_CEBE(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CEBE_SHIFT)) & USDHC_INT_STATUS_CEBE_MASK)

#define USDHC_INT_STATUS_CIE_MASK                (0x80000U)
#define USDHC_INT_STATUS_CIE_SHIFT               (19U)
#define USDHC_INT_STATUS_CIE_WIDTH               (1U)
#define USDHC_INT_STATUS_CIE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_CIE_SHIFT)) & USDHC_INT_STATUS_CIE_MASK)

#define USDHC_INT_STATUS_DTOE_MASK               (0x100000U)
#define USDHC_INT_STATUS_DTOE_SHIFT              (20U)
#define USDHC_INT_STATUS_DTOE_WIDTH              (1U)
#define USDHC_INT_STATUS_DTOE(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_DTOE_SHIFT)) & USDHC_INT_STATUS_DTOE_MASK)

#define USDHC_INT_STATUS_DCE_MASK                (0x200000U)
#define USDHC_INT_STATUS_DCE_SHIFT               (21U)
#define USDHC_INT_STATUS_DCE_WIDTH               (1U)
#define USDHC_INT_STATUS_DCE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_DCE_SHIFT)) & USDHC_INT_STATUS_DCE_MASK)

#define USDHC_INT_STATUS_DEBE_MASK               (0x400000U)
#define USDHC_INT_STATUS_DEBE_SHIFT              (22U)
#define USDHC_INT_STATUS_DEBE_WIDTH              (1U)
#define USDHC_INT_STATUS_DEBE(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_DEBE_SHIFT)) & USDHC_INT_STATUS_DEBE_MASK)

#define USDHC_INT_STATUS_AC12E_MASK              (0x1000000U)
#define USDHC_INT_STATUS_AC12E_SHIFT             (24U)
#define USDHC_INT_STATUS_AC12E_WIDTH             (1U)
#define USDHC_INT_STATUS_AC12E(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_AC12E_SHIFT)) & USDHC_INT_STATUS_AC12E_MASK)

#define USDHC_INT_STATUS_TNE_MASK                (0x4000000U)
#define USDHC_INT_STATUS_TNE_SHIFT               (26U)
#define USDHC_INT_STATUS_TNE_WIDTH               (1U)
#define USDHC_INT_STATUS_TNE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_TNE_SHIFT)) & USDHC_INT_STATUS_TNE_MASK)

#define USDHC_INT_STATUS_DMAE_MASK               (0x10000000U)
#define USDHC_INT_STATUS_DMAE_SHIFT              (28U)
#define USDHC_INT_STATUS_DMAE_WIDTH              (1U)
#define USDHC_INT_STATUS_DMAE(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_DMAE_SHIFT)) & USDHC_INT_STATUS_DMAE_MASK)
/*! @} */

/*! @name INT_STATUS_EN - Interrupt Status Enable */
/*! @{ */

#define USDHC_INT_STATUS_EN_CCSEN_MASK           (0x1U)
#define USDHC_INT_STATUS_EN_CCSEN_SHIFT          (0U)
#define USDHC_INT_STATUS_EN_CCSEN_WIDTH          (1U)
#define USDHC_INT_STATUS_EN_CCSEN(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CCSEN_SHIFT)) & USDHC_INT_STATUS_EN_CCSEN_MASK)

#define USDHC_INT_STATUS_EN_TCSEN_MASK           (0x2U)
#define USDHC_INT_STATUS_EN_TCSEN_SHIFT          (1U)
#define USDHC_INT_STATUS_EN_TCSEN_WIDTH          (1U)
#define USDHC_INT_STATUS_EN_TCSEN(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_TCSEN_SHIFT)) & USDHC_INT_STATUS_EN_TCSEN_MASK)

#define USDHC_INT_STATUS_EN_BGESEN_MASK          (0x4U)
#define USDHC_INT_STATUS_EN_BGESEN_SHIFT         (2U)
#define USDHC_INT_STATUS_EN_BGESEN_WIDTH         (1U)
#define USDHC_INT_STATUS_EN_BGESEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_BGESEN_SHIFT)) & USDHC_INT_STATUS_EN_BGESEN_MASK)

#define USDHC_INT_STATUS_EN_DINTSEN_MASK         (0x8U)
#define USDHC_INT_STATUS_EN_DINTSEN_SHIFT        (3U)
#define USDHC_INT_STATUS_EN_DINTSEN_WIDTH        (1U)
#define USDHC_INT_STATUS_EN_DINTSEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_DINTSEN_SHIFT)) & USDHC_INT_STATUS_EN_DINTSEN_MASK)

#define USDHC_INT_STATUS_EN_BWRSEN_MASK          (0x10U)
#define USDHC_INT_STATUS_EN_BWRSEN_SHIFT         (4U)
#define USDHC_INT_STATUS_EN_BWRSEN_WIDTH         (1U)
#define USDHC_INT_STATUS_EN_BWRSEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_BWRSEN_SHIFT)) & USDHC_INT_STATUS_EN_BWRSEN_MASK)

#define USDHC_INT_STATUS_EN_BRRSEN_MASK          (0x20U)
#define USDHC_INT_STATUS_EN_BRRSEN_SHIFT         (5U)
#define USDHC_INT_STATUS_EN_BRRSEN_WIDTH         (1U)
#define USDHC_INT_STATUS_EN_BRRSEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_BRRSEN_SHIFT)) & USDHC_INT_STATUS_EN_BRRSEN_MASK)

#define USDHC_INT_STATUS_EN_CINSSEN_MASK         (0x40U)
#define USDHC_INT_STATUS_EN_CINSSEN_SHIFT        (6U)
#define USDHC_INT_STATUS_EN_CINSSEN_WIDTH        (1U)
#define USDHC_INT_STATUS_EN_CINSSEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CINSSEN_SHIFT)) & USDHC_INT_STATUS_EN_CINSSEN_MASK)

#define USDHC_INT_STATUS_EN_CRMSEN_MASK          (0x80U)
#define USDHC_INT_STATUS_EN_CRMSEN_SHIFT         (7U)
#define USDHC_INT_STATUS_EN_CRMSEN_WIDTH         (1U)
#define USDHC_INT_STATUS_EN_CRMSEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CRMSEN_SHIFT)) & USDHC_INT_STATUS_EN_CRMSEN_MASK)

#define USDHC_INT_STATUS_EN_CINTSEN_MASK         (0x100U)
#define USDHC_INT_STATUS_EN_CINTSEN_SHIFT        (8U)
#define USDHC_INT_STATUS_EN_CINTSEN_WIDTH        (1U)
#define USDHC_INT_STATUS_EN_CINTSEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CINTSEN_SHIFT)) & USDHC_INT_STATUS_EN_CINTSEN_MASK)

#define USDHC_INT_STATUS_EN_RTESEN_MASK          (0x1000U)
#define USDHC_INT_STATUS_EN_RTESEN_SHIFT         (12U)
#define USDHC_INT_STATUS_EN_RTESEN_WIDTH         (1U)
#define USDHC_INT_STATUS_EN_RTESEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_RTESEN_SHIFT)) & USDHC_INT_STATUS_EN_RTESEN_MASK)

#define USDHC_INT_STATUS_EN_TPSEN_MASK           (0x2000U)
#define USDHC_INT_STATUS_EN_TPSEN_SHIFT          (13U)
#define USDHC_INT_STATUS_EN_TPSEN_WIDTH          (1U)
#define USDHC_INT_STATUS_EN_TPSEN(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_TPSEN_SHIFT)) & USDHC_INT_STATUS_EN_TPSEN_MASK)

#define USDHC_INT_STATUS_EN_CQISEN_MASK          (0x4000U)
#define USDHC_INT_STATUS_EN_CQISEN_SHIFT         (14U)
#define USDHC_INT_STATUS_EN_CQISEN_WIDTH         (1U)
#define USDHC_INT_STATUS_EN_CQISEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CQISEN_SHIFT)) & USDHC_INT_STATUS_EN_CQISEN_MASK)

#define USDHC_INT_STATUS_EN_CTOESEN_MASK         (0x10000U)
#define USDHC_INT_STATUS_EN_CTOESEN_SHIFT        (16U)
#define USDHC_INT_STATUS_EN_CTOESEN_WIDTH        (1U)
#define USDHC_INT_STATUS_EN_CTOESEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CTOESEN_SHIFT)) & USDHC_INT_STATUS_EN_CTOESEN_MASK)

#define USDHC_INT_STATUS_EN_CCESEN_MASK          (0x20000U)
#define USDHC_INT_STATUS_EN_CCESEN_SHIFT         (17U)
#define USDHC_INT_STATUS_EN_CCESEN_WIDTH         (1U)
#define USDHC_INT_STATUS_EN_CCESEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CCESEN_SHIFT)) & USDHC_INT_STATUS_EN_CCESEN_MASK)

#define USDHC_INT_STATUS_EN_CEBESEN_MASK         (0x40000U)
#define USDHC_INT_STATUS_EN_CEBESEN_SHIFT        (18U)
#define USDHC_INT_STATUS_EN_CEBESEN_WIDTH        (1U)
#define USDHC_INT_STATUS_EN_CEBESEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CEBESEN_SHIFT)) & USDHC_INT_STATUS_EN_CEBESEN_MASK)

#define USDHC_INT_STATUS_EN_CIESEN_MASK          (0x80000U)
#define USDHC_INT_STATUS_EN_CIESEN_SHIFT         (19U)
#define USDHC_INT_STATUS_EN_CIESEN_WIDTH         (1U)
#define USDHC_INT_STATUS_EN_CIESEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_CIESEN_SHIFT)) & USDHC_INT_STATUS_EN_CIESEN_MASK)

#define USDHC_INT_STATUS_EN_DTOESEN_MASK         (0x100000U)
#define USDHC_INT_STATUS_EN_DTOESEN_SHIFT        (20U)
#define USDHC_INT_STATUS_EN_DTOESEN_WIDTH        (1U)
#define USDHC_INT_STATUS_EN_DTOESEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_DTOESEN_SHIFT)) & USDHC_INT_STATUS_EN_DTOESEN_MASK)

#define USDHC_INT_STATUS_EN_DCESEN_MASK          (0x200000U)
#define USDHC_INT_STATUS_EN_DCESEN_SHIFT         (21U)
#define USDHC_INT_STATUS_EN_DCESEN_WIDTH         (1U)
#define USDHC_INT_STATUS_EN_DCESEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_DCESEN_SHIFT)) & USDHC_INT_STATUS_EN_DCESEN_MASK)

#define USDHC_INT_STATUS_EN_DEBESEN_MASK         (0x400000U)
#define USDHC_INT_STATUS_EN_DEBESEN_SHIFT        (22U)
#define USDHC_INT_STATUS_EN_DEBESEN_WIDTH        (1U)
#define USDHC_INT_STATUS_EN_DEBESEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_DEBESEN_SHIFT)) & USDHC_INT_STATUS_EN_DEBESEN_MASK)

#define USDHC_INT_STATUS_EN_AC12ESEN_MASK        (0x1000000U)
#define USDHC_INT_STATUS_EN_AC12ESEN_SHIFT       (24U)
#define USDHC_INT_STATUS_EN_AC12ESEN_WIDTH       (1U)
#define USDHC_INT_STATUS_EN_AC12ESEN(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_AC12ESEN_SHIFT)) & USDHC_INT_STATUS_EN_AC12ESEN_MASK)

#define USDHC_INT_STATUS_EN_TNESEN_MASK          (0x4000000U)
#define USDHC_INT_STATUS_EN_TNESEN_SHIFT         (26U)
#define USDHC_INT_STATUS_EN_TNESEN_WIDTH         (1U)
#define USDHC_INT_STATUS_EN_TNESEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_TNESEN_SHIFT)) & USDHC_INT_STATUS_EN_TNESEN_MASK)

#define USDHC_INT_STATUS_EN_DMAESEN_MASK         (0x10000000U)
#define USDHC_INT_STATUS_EN_DMAESEN_SHIFT        (28U)
#define USDHC_INT_STATUS_EN_DMAESEN_WIDTH        (1U)
#define USDHC_INT_STATUS_EN_DMAESEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_STATUS_EN_DMAESEN_SHIFT)) & USDHC_INT_STATUS_EN_DMAESEN_MASK)
/*! @} */

/*! @name INT_SIGNAL_EN - Interrupt Signal Enable */
/*! @{ */

#define USDHC_INT_SIGNAL_EN_CCIEN_MASK           (0x1U)
#define USDHC_INT_SIGNAL_EN_CCIEN_SHIFT          (0U)
#define USDHC_INT_SIGNAL_EN_CCIEN_WIDTH          (1U)
#define USDHC_INT_SIGNAL_EN_CCIEN(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CCIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CCIEN_MASK)

#define USDHC_INT_SIGNAL_EN_TCIEN_MASK           (0x2U)
#define USDHC_INT_SIGNAL_EN_TCIEN_SHIFT          (1U)
#define USDHC_INT_SIGNAL_EN_TCIEN_WIDTH          (1U)
#define USDHC_INT_SIGNAL_EN_TCIEN(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_TCIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_TCIEN_MASK)

#define USDHC_INT_SIGNAL_EN_BGEIEN_MASK          (0x4U)
#define USDHC_INT_SIGNAL_EN_BGEIEN_SHIFT         (2U)
#define USDHC_INT_SIGNAL_EN_BGEIEN_WIDTH         (1U)
#define USDHC_INT_SIGNAL_EN_BGEIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_BGEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_BGEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_DINTIEN_MASK         (0x8U)
#define USDHC_INT_SIGNAL_EN_DINTIEN_SHIFT        (3U)
#define USDHC_INT_SIGNAL_EN_DINTIEN_WIDTH        (1U)
#define USDHC_INT_SIGNAL_EN_DINTIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_DINTIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_DINTIEN_MASK)

#define USDHC_INT_SIGNAL_EN_BWRIEN_MASK          (0x10U)
#define USDHC_INT_SIGNAL_EN_BWRIEN_SHIFT         (4U)
#define USDHC_INT_SIGNAL_EN_BWRIEN_WIDTH         (1U)
#define USDHC_INT_SIGNAL_EN_BWRIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_BWRIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_BWRIEN_MASK)

#define USDHC_INT_SIGNAL_EN_BRRIEN_MASK          (0x20U)
#define USDHC_INT_SIGNAL_EN_BRRIEN_SHIFT         (5U)
#define USDHC_INT_SIGNAL_EN_BRRIEN_WIDTH         (1U)
#define USDHC_INT_SIGNAL_EN_BRRIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_BRRIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_BRRIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CINSIEN_MASK         (0x40U)
#define USDHC_INT_SIGNAL_EN_CINSIEN_SHIFT        (6U)
#define USDHC_INT_SIGNAL_EN_CINSIEN_WIDTH        (1U)
#define USDHC_INT_SIGNAL_EN_CINSIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CINSIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CINSIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CRMIEN_MASK          (0x80U)
#define USDHC_INT_SIGNAL_EN_CRMIEN_SHIFT         (7U)
#define USDHC_INT_SIGNAL_EN_CRMIEN_WIDTH         (1U)
#define USDHC_INT_SIGNAL_EN_CRMIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CRMIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CRMIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CINTIEN_MASK         (0x100U)
#define USDHC_INT_SIGNAL_EN_CINTIEN_SHIFT        (8U)
#define USDHC_INT_SIGNAL_EN_CINTIEN_WIDTH        (1U)
#define USDHC_INT_SIGNAL_EN_CINTIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CINTIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CINTIEN_MASK)

#define USDHC_INT_SIGNAL_EN_RTEIEN_MASK          (0x1000U)
#define USDHC_INT_SIGNAL_EN_RTEIEN_SHIFT         (12U)
#define USDHC_INT_SIGNAL_EN_RTEIEN_WIDTH         (1U)
#define USDHC_INT_SIGNAL_EN_RTEIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_RTEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_RTEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_TPIEN_MASK           (0x2000U)
#define USDHC_INT_SIGNAL_EN_TPIEN_SHIFT          (13U)
#define USDHC_INT_SIGNAL_EN_TPIEN_WIDTH          (1U)
#define USDHC_INT_SIGNAL_EN_TPIEN(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_TPIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_TPIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CQIIEN_MASK          (0x4000U)
#define USDHC_INT_SIGNAL_EN_CQIIEN_SHIFT         (14U)
#define USDHC_INT_SIGNAL_EN_CQIIEN_WIDTH         (1U)
#define USDHC_INT_SIGNAL_EN_CQIIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CQIIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CQIIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CTOEIEN_MASK         (0x10000U)
#define USDHC_INT_SIGNAL_EN_CTOEIEN_SHIFT        (16U)
#define USDHC_INT_SIGNAL_EN_CTOEIEN_WIDTH        (1U)
#define USDHC_INT_SIGNAL_EN_CTOEIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CTOEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CTOEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CCEIEN_MASK          (0x20000U)
#define USDHC_INT_SIGNAL_EN_CCEIEN_SHIFT         (17U)
#define USDHC_INT_SIGNAL_EN_CCEIEN_WIDTH         (1U)
#define USDHC_INT_SIGNAL_EN_CCEIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CCEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CCEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CEBEIEN_MASK         (0x40000U)
#define USDHC_INT_SIGNAL_EN_CEBEIEN_SHIFT        (18U)
#define USDHC_INT_SIGNAL_EN_CEBEIEN_WIDTH        (1U)
#define USDHC_INT_SIGNAL_EN_CEBEIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CEBEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CEBEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_CIEIEN_MASK          (0x80000U)
#define USDHC_INT_SIGNAL_EN_CIEIEN_SHIFT         (19U)
#define USDHC_INT_SIGNAL_EN_CIEIEN_WIDTH         (1U)
#define USDHC_INT_SIGNAL_EN_CIEIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_CIEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_CIEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_DTOEIEN_MASK         (0x100000U)
#define USDHC_INT_SIGNAL_EN_DTOEIEN_SHIFT        (20U)
#define USDHC_INT_SIGNAL_EN_DTOEIEN_WIDTH        (1U)
#define USDHC_INT_SIGNAL_EN_DTOEIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_DTOEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_DTOEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_DCEIEN_MASK          (0x200000U)
#define USDHC_INT_SIGNAL_EN_DCEIEN_SHIFT         (21U)
#define USDHC_INT_SIGNAL_EN_DCEIEN_WIDTH         (1U)
#define USDHC_INT_SIGNAL_EN_DCEIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_DCEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_DCEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_DEBEIEN_MASK         (0x400000U)
#define USDHC_INT_SIGNAL_EN_DEBEIEN_SHIFT        (22U)
#define USDHC_INT_SIGNAL_EN_DEBEIEN_WIDTH        (1U)
#define USDHC_INT_SIGNAL_EN_DEBEIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_DEBEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_DEBEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_AC12EIEN_MASK        (0x1000000U)
#define USDHC_INT_SIGNAL_EN_AC12EIEN_SHIFT       (24U)
#define USDHC_INT_SIGNAL_EN_AC12EIEN_WIDTH       (1U)
#define USDHC_INT_SIGNAL_EN_AC12EIEN(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_AC12EIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_AC12EIEN_MASK)

#define USDHC_INT_SIGNAL_EN_TNEIEN_MASK          (0x4000000U)
#define USDHC_INT_SIGNAL_EN_TNEIEN_SHIFT         (26U)
#define USDHC_INT_SIGNAL_EN_TNEIEN_WIDTH         (1U)
#define USDHC_INT_SIGNAL_EN_TNEIEN(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_TNEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_TNEIEN_MASK)

#define USDHC_INT_SIGNAL_EN_DMAEIEN_MASK         (0x10000000U)
#define USDHC_INT_SIGNAL_EN_DMAEIEN_SHIFT        (28U)
#define USDHC_INT_SIGNAL_EN_DMAEIEN_WIDTH        (1U)
#define USDHC_INT_SIGNAL_EN_DMAEIEN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_INT_SIGNAL_EN_DMAEIEN_SHIFT)) & USDHC_INT_SIGNAL_EN_DMAEIEN_MASK)
/*! @} */

/*! @name AUTOCMD12_ERR_STATUS - Auto CMD12 Error Status */
/*! @{ */

#define USDHC_AUTOCMD12_ERR_STATUS_AC12NE_MASK   (0x1U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12NE_SHIFT  (0U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12NE_WIDTH  (1U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12NE(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_AC12NE_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_AC12NE_MASK)

#define USDHC_AUTOCMD12_ERR_STATUS_AC12TOE_MASK  (0x2U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12TOE_SHIFT (1U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12TOE_WIDTH (1U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12TOE(x)    (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_AC12TOE_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_AC12TOE_MASK)

#define USDHC_AUTOCMD12_ERR_STATUS_AC12CE_MASK   (0x4U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12CE_SHIFT  (2U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12CE_WIDTH  (1U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12CE(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_AC12CE_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_AC12CE_MASK)

#define USDHC_AUTOCMD12_ERR_STATUS_AC12EBE_MASK  (0x8U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12EBE_SHIFT (3U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12EBE_WIDTH (1U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12EBE(x)    (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_AC12EBE_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_AC12EBE_MASK)

#define USDHC_AUTOCMD12_ERR_STATUS_AC12IE_MASK   (0x10U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12IE_SHIFT  (4U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12IE_WIDTH  (1U)
#define USDHC_AUTOCMD12_ERR_STATUS_AC12IE(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_AC12IE_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_AC12IE_MASK)

#define USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E_MASK (0x80U)
#define USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E_SHIFT (7U)
#define USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E_WIDTH (1U)
#define USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E(x)  (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_CNIBAC12E_MASK)

#define USDHC_AUTOCMD12_ERR_STATUS_EXECUTE_TUNING_MASK (0x400000U)
#define USDHC_AUTOCMD12_ERR_STATUS_EXECUTE_TUNING_SHIFT (22U)
#define USDHC_AUTOCMD12_ERR_STATUS_EXECUTE_TUNING_WIDTH (1U)
#define USDHC_AUTOCMD12_ERR_STATUS_EXECUTE_TUNING(x) (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_EXECUTE_TUNING_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_EXECUTE_TUNING_MASK)

#define USDHC_AUTOCMD12_ERR_STATUS_SMP_CLK_SEL_MASK (0x800000U)
#define USDHC_AUTOCMD12_ERR_STATUS_SMP_CLK_SEL_SHIFT (23U)
#define USDHC_AUTOCMD12_ERR_STATUS_SMP_CLK_SEL_WIDTH (1U)
#define USDHC_AUTOCMD12_ERR_STATUS_SMP_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << USDHC_AUTOCMD12_ERR_STATUS_SMP_CLK_SEL_SHIFT)) & USDHC_AUTOCMD12_ERR_STATUS_SMP_CLK_SEL_MASK)
/*! @} */

/*! @name HOST_CTRL_CAP - Host Controller Capabilities */
/*! @{ */

#define USDHC_HOST_CTRL_CAP_SDR50_SUPPORT_MASK   (0x1U)
#define USDHC_HOST_CTRL_CAP_SDR50_SUPPORT_SHIFT  (0U)
#define USDHC_HOST_CTRL_CAP_SDR50_SUPPORT_WIDTH  (1U)
#define USDHC_HOST_CTRL_CAP_SDR50_SUPPORT(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_SDR50_SUPPORT_SHIFT)) & USDHC_HOST_CTRL_CAP_SDR50_SUPPORT_MASK)

#define USDHC_HOST_CTRL_CAP_SDR104_SUPPORT_MASK  (0x2U)
#define USDHC_HOST_CTRL_CAP_SDR104_SUPPORT_SHIFT (1U)
#define USDHC_HOST_CTRL_CAP_SDR104_SUPPORT_WIDTH (1U)
#define USDHC_HOST_CTRL_CAP_SDR104_SUPPORT(x)    (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_SDR104_SUPPORT_SHIFT)) & USDHC_HOST_CTRL_CAP_SDR104_SUPPORT_MASK)

#define USDHC_HOST_CTRL_CAP_DDR50_SUPPORT_MASK   (0x4U)
#define USDHC_HOST_CTRL_CAP_DDR50_SUPPORT_SHIFT  (2U)
#define USDHC_HOST_CTRL_CAP_DDR50_SUPPORT_WIDTH  (1U)
#define USDHC_HOST_CTRL_CAP_DDR50_SUPPORT(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_DDR50_SUPPORT_SHIFT)) & USDHC_HOST_CTRL_CAP_DDR50_SUPPORT_MASK)

#define USDHC_HOST_CTRL_CAP_USE_TUNING_SDR50_MASK (0x2000U)
#define USDHC_HOST_CTRL_CAP_USE_TUNING_SDR50_SHIFT (13U)
#define USDHC_HOST_CTRL_CAP_USE_TUNING_SDR50_WIDTH (1U)
#define USDHC_HOST_CTRL_CAP_USE_TUNING_SDR50(x)  (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_USE_TUNING_SDR50_SHIFT)) & USDHC_HOST_CTRL_CAP_USE_TUNING_SDR50_MASK)

#define USDHC_HOST_CTRL_CAP_MBL_MASK             (0x70000U)
#define USDHC_HOST_CTRL_CAP_MBL_SHIFT            (16U)
#define USDHC_HOST_CTRL_CAP_MBL_WIDTH            (3U)
#define USDHC_HOST_CTRL_CAP_MBL(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_MBL_SHIFT)) & USDHC_HOST_CTRL_CAP_MBL_MASK)

#define USDHC_HOST_CTRL_CAP_ADMAS_MASK           (0x100000U)
#define USDHC_HOST_CTRL_CAP_ADMAS_SHIFT          (20U)
#define USDHC_HOST_CTRL_CAP_ADMAS_WIDTH          (1U)
#define USDHC_HOST_CTRL_CAP_ADMAS(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_ADMAS_SHIFT)) & USDHC_HOST_CTRL_CAP_ADMAS_MASK)

#define USDHC_HOST_CTRL_CAP_HSS_MASK             (0x200000U)
#define USDHC_HOST_CTRL_CAP_HSS_SHIFT            (21U)
#define USDHC_HOST_CTRL_CAP_HSS_WIDTH            (1U)
#define USDHC_HOST_CTRL_CAP_HSS(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_HSS_SHIFT)) & USDHC_HOST_CTRL_CAP_HSS_MASK)

#define USDHC_HOST_CTRL_CAP_DMAS_MASK            (0x400000U)
#define USDHC_HOST_CTRL_CAP_DMAS_SHIFT           (22U)
#define USDHC_HOST_CTRL_CAP_DMAS_WIDTH           (1U)
#define USDHC_HOST_CTRL_CAP_DMAS(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_DMAS_SHIFT)) & USDHC_HOST_CTRL_CAP_DMAS_MASK)

#define USDHC_HOST_CTRL_CAP_SRS_MASK             (0x800000U)
#define USDHC_HOST_CTRL_CAP_SRS_SHIFT            (23U)
#define USDHC_HOST_CTRL_CAP_SRS_WIDTH            (1U)
#define USDHC_HOST_CTRL_CAP_SRS(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_SRS_SHIFT)) & USDHC_HOST_CTRL_CAP_SRS_MASK)

#define USDHC_HOST_CTRL_CAP_VS33_MASK            (0x1000000U)
#define USDHC_HOST_CTRL_CAP_VS33_SHIFT           (24U)
#define USDHC_HOST_CTRL_CAP_VS33_WIDTH           (1U)
#define USDHC_HOST_CTRL_CAP_VS33(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_VS33_SHIFT)) & USDHC_HOST_CTRL_CAP_VS33_MASK)

#define USDHC_HOST_CTRL_CAP_VS30_MASK            (0x2000000U)
#define USDHC_HOST_CTRL_CAP_VS30_SHIFT           (25U)
#define USDHC_HOST_CTRL_CAP_VS30_WIDTH           (1U)
#define USDHC_HOST_CTRL_CAP_VS30(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_VS30_SHIFT)) & USDHC_HOST_CTRL_CAP_VS30_MASK)

#define USDHC_HOST_CTRL_CAP_VS18_MASK            (0x4000000U)
#define USDHC_HOST_CTRL_CAP_VS18_SHIFT           (26U)
#define USDHC_HOST_CTRL_CAP_VS18_WIDTH           (1U)
#define USDHC_HOST_CTRL_CAP_VS18(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_HOST_CTRL_CAP_VS18_SHIFT)) & USDHC_HOST_CTRL_CAP_VS18_MASK)
/*! @} */

/*! @name WTMK_LVL - Watermark Level */
/*! @{ */

#define USDHC_WTMK_LVL_RD_WML_MASK               (0xFFU)
#define USDHC_WTMK_LVL_RD_WML_SHIFT              (0U)
#define USDHC_WTMK_LVL_RD_WML_WIDTH              (8U)
#define USDHC_WTMK_LVL_RD_WML(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_WTMK_LVL_RD_WML_SHIFT)) & USDHC_WTMK_LVL_RD_WML_MASK)

#define USDHC_WTMK_LVL_WR_WML_MASK               (0xFF0000U)
#define USDHC_WTMK_LVL_WR_WML_SHIFT              (16U)
#define USDHC_WTMK_LVL_WR_WML_WIDTH              (8U)
#define USDHC_WTMK_LVL_WR_WML(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_WTMK_LVL_WR_WML_SHIFT)) & USDHC_WTMK_LVL_WR_WML_MASK)
/*! @} */

/*! @name MIX_CTRL - Mixer Control */
/*! @{ */

#define USDHC_MIX_CTRL_DMAEN_MASK                (0x1U)
#define USDHC_MIX_CTRL_DMAEN_SHIFT               (0U)
#define USDHC_MIX_CTRL_DMAEN_WIDTH               (1U)
#define USDHC_MIX_CTRL_DMAEN(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_DMAEN_SHIFT)) & USDHC_MIX_CTRL_DMAEN_MASK)

#define USDHC_MIX_CTRL_BCEN_MASK                 (0x2U)
#define USDHC_MIX_CTRL_BCEN_SHIFT                (1U)
#define USDHC_MIX_CTRL_BCEN_WIDTH                (1U)
#define USDHC_MIX_CTRL_BCEN(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_BCEN_SHIFT)) & USDHC_MIX_CTRL_BCEN_MASK)

#define USDHC_MIX_CTRL_AC12EN_MASK               (0x4U)
#define USDHC_MIX_CTRL_AC12EN_SHIFT              (2U)
#define USDHC_MIX_CTRL_AC12EN_WIDTH              (1U)
#define USDHC_MIX_CTRL_AC12EN(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_AC12EN_SHIFT)) & USDHC_MIX_CTRL_AC12EN_MASK)

#define USDHC_MIX_CTRL_DDR_EN_MASK               (0x8U)
#define USDHC_MIX_CTRL_DDR_EN_SHIFT              (3U)
#define USDHC_MIX_CTRL_DDR_EN_WIDTH              (1U)
#define USDHC_MIX_CTRL_DDR_EN(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_DDR_EN_SHIFT)) & USDHC_MIX_CTRL_DDR_EN_MASK)

#define USDHC_MIX_CTRL_DTDSEL_MASK               (0x10U)
#define USDHC_MIX_CTRL_DTDSEL_SHIFT              (4U)
#define USDHC_MIX_CTRL_DTDSEL_WIDTH              (1U)
#define USDHC_MIX_CTRL_DTDSEL(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_DTDSEL_SHIFT)) & USDHC_MIX_CTRL_DTDSEL_MASK)

#define USDHC_MIX_CTRL_MSBSEL_MASK               (0x20U)
#define USDHC_MIX_CTRL_MSBSEL_SHIFT              (5U)
#define USDHC_MIX_CTRL_MSBSEL_WIDTH              (1U)
#define USDHC_MIX_CTRL_MSBSEL(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_MSBSEL_SHIFT)) & USDHC_MIX_CTRL_MSBSEL_MASK)

#define USDHC_MIX_CTRL_NIBBLE_POS_MASK           (0x40U)
#define USDHC_MIX_CTRL_NIBBLE_POS_SHIFT          (6U)
#define USDHC_MIX_CTRL_NIBBLE_POS_WIDTH          (1U)
#define USDHC_MIX_CTRL_NIBBLE_POS(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_NIBBLE_POS_SHIFT)) & USDHC_MIX_CTRL_NIBBLE_POS_MASK)

#define USDHC_MIX_CTRL_AC23EN_MASK               (0x80U)
#define USDHC_MIX_CTRL_AC23EN_SHIFT              (7U)
#define USDHC_MIX_CTRL_AC23EN_WIDTH              (1U)
#define USDHC_MIX_CTRL_AC23EN(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_AC23EN_SHIFT)) & USDHC_MIX_CTRL_AC23EN_MASK)

#define USDHC_MIX_CTRL_EXE_TUNE_MASK             (0x400000U)
#define USDHC_MIX_CTRL_EXE_TUNE_SHIFT            (22U)
#define USDHC_MIX_CTRL_EXE_TUNE_WIDTH            (1U)
#define USDHC_MIX_CTRL_EXE_TUNE(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_EXE_TUNE_SHIFT)) & USDHC_MIX_CTRL_EXE_TUNE_MASK)

#define USDHC_MIX_CTRL_SMP_CLK_SEL_MASK          (0x800000U)
#define USDHC_MIX_CTRL_SMP_CLK_SEL_SHIFT         (23U)
#define USDHC_MIX_CTRL_SMP_CLK_SEL_WIDTH         (1U)
#define USDHC_MIX_CTRL_SMP_CLK_SEL(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_SMP_CLK_SEL_SHIFT)) & USDHC_MIX_CTRL_SMP_CLK_SEL_MASK)

#define USDHC_MIX_CTRL_AUTO_TUNE_EN_MASK         (0x1000000U)
#define USDHC_MIX_CTRL_AUTO_TUNE_EN_SHIFT        (24U)
#define USDHC_MIX_CTRL_AUTO_TUNE_EN_WIDTH        (1U)
#define USDHC_MIX_CTRL_AUTO_TUNE_EN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_AUTO_TUNE_EN_SHIFT)) & USDHC_MIX_CTRL_AUTO_TUNE_EN_MASK)

#define USDHC_MIX_CTRL_FBCLK_SEL_MASK            (0x2000000U)
#define USDHC_MIX_CTRL_FBCLK_SEL_SHIFT           (25U)
#define USDHC_MIX_CTRL_FBCLK_SEL_WIDTH           (1U)
#define USDHC_MIX_CTRL_FBCLK_SEL(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_FBCLK_SEL_SHIFT)) & USDHC_MIX_CTRL_FBCLK_SEL_MASK)

#define USDHC_MIX_CTRL_HS400_MODE_MASK           (0x4000000U)
#define USDHC_MIX_CTRL_HS400_MODE_SHIFT          (26U)
#define USDHC_MIX_CTRL_HS400_MODE_WIDTH          (1U)
#define USDHC_MIX_CTRL_HS400_MODE(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_HS400_MODE_SHIFT)) & USDHC_MIX_CTRL_HS400_MODE_MASK)

#define USDHC_MIX_CTRL_EN_HS400_MODE_MASK        (0x8000000U)
#define USDHC_MIX_CTRL_EN_HS400_MODE_SHIFT       (27U)
#define USDHC_MIX_CTRL_EN_HS400_MODE_WIDTH       (1U)
#define USDHC_MIX_CTRL_EN_HS400_MODE(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_MIX_CTRL_EN_HS400_MODE_SHIFT)) & USDHC_MIX_CTRL_EN_HS400_MODE_MASK)
/*! @} */

/*! @name FORCE_EVENT - Force Event */
/*! @{ */

#define USDHC_FORCE_EVENT_FEVTAC12NE_MASK        (0x1U)
#define USDHC_FORCE_EVENT_FEVTAC12NE_SHIFT       (0U)
#define USDHC_FORCE_EVENT_FEVTAC12NE_WIDTH       (1U)
#define USDHC_FORCE_EVENT_FEVTAC12NE(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTAC12NE_SHIFT)) & USDHC_FORCE_EVENT_FEVTAC12NE_MASK)

#define USDHC_FORCE_EVENT_FEVTAC12TOE_MASK       (0x2U)
#define USDHC_FORCE_EVENT_FEVTAC12TOE_SHIFT      (1U)
#define USDHC_FORCE_EVENT_FEVTAC12TOE_WIDTH      (1U)
#define USDHC_FORCE_EVENT_FEVTAC12TOE(x)         (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTAC12TOE_SHIFT)) & USDHC_FORCE_EVENT_FEVTAC12TOE_MASK)

#define USDHC_FORCE_EVENT_FEVTAC12CE_MASK        (0x4U)
#define USDHC_FORCE_EVENT_FEVTAC12CE_SHIFT       (2U)
#define USDHC_FORCE_EVENT_FEVTAC12CE_WIDTH       (1U)
#define USDHC_FORCE_EVENT_FEVTAC12CE(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTAC12CE_SHIFT)) & USDHC_FORCE_EVENT_FEVTAC12CE_MASK)

#define USDHC_FORCE_EVENT_FEVTAC12EBE_MASK       (0x8U)
#define USDHC_FORCE_EVENT_FEVTAC12EBE_SHIFT      (3U)
#define USDHC_FORCE_EVENT_FEVTAC12EBE_WIDTH      (1U)
#define USDHC_FORCE_EVENT_FEVTAC12EBE(x)         (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTAC12EBE_SHIFT)) & USDHC_FORCE_EVENT_FEVTAC12EBE_MASK)

#define USDHC_FORCE_EVENT_FEVTAC12IE_MASK        (0x10U)
#define USDHC_FORCE_EVENT_FEVTAC12IE_SHIFT       (4U)
#define USDHC_FORCE_EVENT_FEVTAC12IE_WIDTH       (1U)
#define USDHC_FORCE_EVENT_FEVTAC12IE(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTAC12IE_SHIFT)) & USDHC_FORCE_EVENT_FEVTAC12IE_MASK)

#define USDHC_FORCE_EVENT_FEVTCNIBAC12E_MASK     (0x80U)
#define USDHC_FORCE_EVENT_FEVTCNIBAC12E_SHIFT    (7U)
#define USDHC_FORCE_EVENT_FEVTCNIBAC12E_WIDTH    (1U)
#define USDHC_FORCE_EVENT_FEVTCNIBAC12E(x)       (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTCNIBAC12E_SHIFT)) & USDHC_FORCE_EVENT_FEVTCNIBAC12E_MASK)

#define USDHC_FORCE_EVENT_FEVTCTOE_MASK          (0x10000U)
#define USDHC_FORCE_EVENT_FEVTCTOE_SHIFT         (16U)
#define USDHC_FORCE_EVENT_FEVTCTOE_WIDTH         (1U)
#define USDHC_FORCE_EVENT_FEVTCTOE(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTCTOE_SHIFT)) & USDHC_FORCE_EVENT_FEVTCTOE_MASK)

#define USDHC_FORCE_EVENT_FEVTCCE_MASK           (0x20000U)
#define USDHC_FORCE_EVENT_FEVTCCE_SHIFT          (17U)
#define USDHC_FORCE_EVENT_FEVTCCE_WIDTH          (1U)
#define USDHC_FORCE_EVENT_FEVTCCE(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTCCE_SHIFT)) & USDHC_FORCE_EVENT_FEVTCCE_MASK)

#define USDHC_FORCE_EVENT_FEVTCEBE_MASK          (0x40000U)
#define USDHC_FORCE_EVENT_FEVTCEBE_SHIFT         (18U)
#define USDHC_FORCE_EVENT_FEVTCEBE_WIDTH         (1U)
#define USDHC_FORCE_EVENT_FEVTCEBE(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTCEBE_SHIFT)) & USDHC_FORCE_EVENT_FEVTCEBE_MASK)

#define USDHC_FORCE_EVENT_FEVTCIE_MASK           (0x80000U)
#define USDHC_FORCE_EVENT_FEVTCIE_SHIFT          (19U)
#define USDHC_FORCE_EVENT_FEVTCIE_WIDTH          (1U)
#define USDHC_FORCE_EVENT_FEVTCIE(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTCIE_SHIFT)) & USDHC_FORCE_EVENT_FEVTCIE_MASK)

#define USDHC_FORCE_EVENT_FEVTDTOE_MASK          (0x100000U)
#define USDHC_FORCE_EVENT_FEVTDTOE_SHIFT         (20U)
#define USDHC_FORCE_EVENT_FEVTDTOE_WIDTH         (1U)
#define USDHC_FORCE_EVENT_FEVTDTOE(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTDTOE_SHIFT)) & USDHC_FORCE_EVENT_FEVTDTOE_MASK)

#define USDHC_FORCE_EVENT_FEVTDCE_MASK           (0x200000U)
#define USDHC_FORCE_EVENT_FEVTDCE_SHIFT          (21U)
#define USDHC_FORCE_EVENT_FEVTDCE_WIDTH          (1U)
#define USDHC_FORCE_EVENT_FEVTDCE(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTDCE_SHIFT)) & USDHC_FORCE_EVENT_FEVTDCE_MASK)

#define USDHC_FORCE_EVENT_FEVTDEBE_MASK          (0x400000U)
#define USDHC_FORCE_EVENT_FEVTDEBE_SHIFT         (22U)
#define USDHC_FORCE_EVENT_FEVTDEBE_WIDTH         (1U)
#define USDHC_FORCE_EVENT_FEVTDEBE(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTDEBE_SHIFT)) & USDHC_FORCE_EVENT_FEVTDEBE_MASK)

#define USDHC_FORCE_EVENT_FEVTAC12E_MASK         (0x1000000U)
#define USDHC_FORCE_EVENT_FEVTAC12E_SHIFT        (24U)
#define USDHC_FORCE_EVENT_FEVTAC12E_WIDTH        (1U)
#define USDHC_FORCE_EVENT_FEVTAC12E(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTAC12E_SHIFT)) & USDHC_FORCE_EVENT_FEVTAC12E_MASK)

#define USDHC_FORCE_EVENT_FEVTTNE_MASK           (0x4000000U)
#define USDHC_FORCE_EVENT_FEVTTNE_SHIFT          (26U)
#define USDHC_FORCE_EVENT_FEVTTNE_WIDTH          (1U)
#define USDHC_FORCE_EVENT_FEVTTNE(x)             (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTTNE_SHIFT)) & USDHC_FORCE_EVENT_FEVTTNE_MASK)

#define USDHC_FORCE_EVENT_FEVTDMAE_MASK          (0x10000000U)
#define USDHC_FORCE_EVENT_FEVTDMAE_SHIFT         (28U)
#define USDHC_FORCE_EVENT_FEVTDMAE_WIDTH         (1U)
#define USDHC_FORCE_EVENT_FEVTDMAE(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTDMAE_SHIFT)) & USDHC_FORCE_EVENT_FEVTDMAE_MASK)

#define USDHC_FORCE_EVENT_FEVTCINT_MASK          (0x80000000U)
#define USDHC_FORCE_EVENT_FEVTCINT_SHIFT         (31U)
#define USDHC_FORCE_EVENT_FEVTCINT_WIDTH         (1U)
#define USDHC_FORCE_EVENT_FEVTCINT(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_FORCE_EVENT_FEVTCINT_SHIFT)) & USDHC_FORCE_EVENT_FEVTCINT_MASK)
/*! @} */

/*! @name ADMA_ERR_STATUS - ADMA Error Status */
/*! @{ */

#define USDHC_ADMA_ERR_STATUS_ADMAES_MASK        (0x3U)
#define USDHC_ADMA_ERR_STATUS_ADMAES_SHIFT       (0U)
#define USDHC_ADMA_ERR_STATUS_ADMAES_WIDTH       (2U)
#define USDHC_ADMA_ERR_STATUS_ADMAES(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_ADMA_ERR_STATUS_ADMAES_SHIFT)) & USDHC_ADMA_ERR_STATUS_ADMAES_MASK)

#define USDHC_ADMA_ERR_STATUS_ADMALME_MASK       (0x4U)
#define USDHC_ADMA_ERR_STATUS_ADMALME_SHIFT      (2U)
#define USDHC_ADMA_ERR_STATUS_ADMALME_WIDTH      (1U)
#define USDHC_ADMA_ERR_STATUS_ADMALME(x)         (((uint32_t)(((uint32_t)(x)) << USDHC_ADMA_ERR_STATUS_ADMALME_SHIFT)) & USDHC_ADMA_ERR_STATUS_ADMALME_MASK)

#define USDHC_ADMA_ERR_STATUS_ADMADCE_MASK       (0x8U)
#define USDHC_ADMA_ERR_STATUS_ADMADCE_SHIFT      (3U)
#define USDHC_ADMA_ERR_STATUS_ADMADCE_WIDTH      (1U)
#define USDHC_ADMA_ERR_STATUS_ADMADCE(x)         (((uint32_t)(((uint32_t)(x)) << USDHC_ADMA_ERR_STATUS_ADMADCE_SHIFT)) & USDHC_ADMA_ERR_STATUS_ADMADCE_MASK)
/*! @} */

/*! @name ADMA_SYS_ADDR - ADMA System Address */
/*! @{ */

#define USDHC_ADMA_SYS_ADDR_ADS_ADDR_MASK        (0xFFFFFFFCU)
#define USDHC_ADMA_SYS_ADDR_ADS_ADDR_SHIFT       (2U)
#define USDHC_ADMA_SYS_ADDR_ADS_ADDR_WIDTH       (30U)
#define USDHC_ADMA_SYS_ADDR_ADS_ADDR(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_ADMA_SYS_ADDR_ADS_ADDR_SHIFT)) & USDHC_ADMA_SYS_ADDR_ADS_ADDR_MASK)
/*! @} */

/*! @name DLL_CTRL - DLL (Delay Line) Control */
/*! @{ */

#define USDHC_DLL_CTRL_DLL_CTRL_ENABLE_MASK      (0x1U)
#define USDHC_DLL_CTRL_DLL_CTRL_ENABLE_SHIFT     (0U)
#define USDHC_DLL_CTRL_DLL_CTRL_ENABLE_WIDTH     (1U)
#define USDHC_DLL_CTRL_DLL_CTRL_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_ENABLE_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_ENABLE_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_RESET_MASK       (0x2U)
#define USDHC_DLL_CTRL_DLL_CTRL_RESET_SHIFT      (1U)
#define USDHC_DLL_CTRL_DLL_CTRL_RESET_WIDTH      (1U)
#define USDHC_DLL_CTRL_DLL_CTRL_RESET(x)         (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_RESET_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_RESET_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD_MASK (0x4U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD_SHIFT (2U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD_WIDTH (1U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD(x) (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_SLV_FORCE_UPD_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET0_MASK (0x78U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET0_SHIFT (3U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET0_WIDTH (4U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET0(x) (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET0_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET0_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE_MASK (0x80U)
#define USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE_SHIFT (7U)
#define USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE_WIDTH (1U)
#define USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE(x)   (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_GATE_UPDATE_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_MASK (0x100U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_SHIFT (8U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_WIDTH (1U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE(x)  (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL_MASK (0xFE00U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL_SHIFT (9U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL_WIDTH (7U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL(x) (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_SLV_OVERRIDE_VAL_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET1_MASK (0x70000U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET1_SHIFT (16U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET1_WIDTH (3U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET1(x) (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET1_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_SLV_DLY_TARGET1_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT_MASK (0xFF00000U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT_SHIFT (20U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT_WIDTH (8U)
#define USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT(x) (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_SLV_UPDATE_INT_MASK)

#define USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT_MASK (0xF0000000U)
#define USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT_SHIFT (28U)
#define USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT_WIDTH (4U)
#define USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT(x) (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT_SHIFT)) & USDHC_DLL_CTRL_DLL_CTRL_REF_UPDATE_INT_MASK)
/*! @} */

/*! @name DLL_STATUS - DLL Status */
/*! @{ */

#define USDHC_DLL_STATUS_DLL_STS_SLV_LOCK_MASK   (0x1U)
#define USDHC_DLL_STATUS_DLL_STS_SLV_LOCK_SHIFT  (0U)
#define USDHC_DLL_STATUS_DLL_STS_SLV_LOCK_WIDTH  (1U)
#define USDHC_DLL_STATUS_DLL_STS_SLV_LOCK(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_STATUS_DLL_STS_SLV_LOCK_SHIFT)) & USDHC_DLL_STATUS_DLL_STS_SLV_LOCK_MASK)

#define USDHC_DLL_STATUS_DLL_STS_REF_LOCK_MASK   (0x2U)
#define USDHC_DLL_STATUS_DLL_STS_REF_LOCK_SHIFT  (1U)
#define USDHC_DLL_STATUS_DLL_STS_REF_LOCK_WIDTH  (1U)
#define USDHC_DLL_STATUS_DLL_STS_REF_LOCK(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_STATUS_DLL_STS_REF_LOCK_SHIFT)) & USDHC_DLL_STATUS_DLL_STS_REF_LOCK_MASK)

#define USDHC_DLL_STATUS_DLL_STS_SLV_SEL_MASK    (0x1FCU)
#define USDHC_DLL_STATUS_DLL_STS_SLV_SEL_SHIFT   (2U)
#define USDHC_DLL_STATUS_DLL_STS_SLV_SEL_WIDTH   (7U)
#define USDHC_DLL_STATUS_DLL_STS_SLV_SEL(x)      (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_STATUS_DLL_STS_SLV_SEL_SHIFT)) & USDHC_DLL_STATUS_DLL_STS_SLV_SEL_MASK)

#define USDHC_DLL_STATUS_DLL_STS_REF_SEL_MASK    (0xFE00U)
#define USDHC_DLL_STATUS_DLL_STS_REF_SEL_SHIFT   (9U)
#define USDHC_DLL_STATUS_DLL_STS_REF_SEL_WIDTH   (7U)
#define USDHC_DLL_STATUS_DLL_STS_REF_SEL(x)      (((uint32_t)(((uint32_t)(x)) << USDHC_DLL_STATUS_DLL_STS_REF_SEL_SHIFT)) & USDHC_DLL_STATUS_DLL_STS_REF_SEL_MASK)
/*! @} */

/*! @name CLK_TUNE_CTRL_STATUS - CLK Tuning Control and Status */
/*! @{ */

#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST_MASK (0xFU)
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST_SHIFT (0U)
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST_WIDTH (4U)
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST(x) (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_POST_MASK)

#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT_MASK (0xF0U)
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT_SHIFT (4U)
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT_WIDTH (4U)
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT(x) (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_OUT_MASK)

#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE_MASK (0x7F00U)
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE_SHIFT (8U)
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE_WIDTH (7U)
#define USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE(x) (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_DLY_CELL_SET_PRE_MASK)

#define USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR_MASK  (0x8000U)
#define USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR_SHIFT (15U)
#define USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR_WIDTH (1U)
#define USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR(x)    (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_NXT_ERR_MASK)

#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST_MASK (0xF0000U)
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST_SHIFT (16U)
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST_WIDTH (4U)
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST(x) (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_POST_MASK)

#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT_MASK (0xF00000U)
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT_SHIFT (20U)
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT_WIDTH (4U)
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT(x) (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_OUT_MASK)

#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE_MASK (0x7F000000U)
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE_SHIFT (24U)
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE_WIDTH (7U)
#define USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE(x) (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_TAP_SEL_PRE_MASK)

#define USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR_MASK  (0x80000000U)
#define USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR_SHIFT (31U)
#define USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR_WIDTH (1U)
#define USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR(x)    (((uint32_t)(((uint32_t)(x)) << USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR_SHIFT)) & USDHC_CLK_TUNE_CTRL_STATUS_PRE_ERR_MASK)
/*! @} */

/*! @name STROBE_DLL_CTRL - Strobe DLL control */
/*! @{ */

#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_ENABLE_MASK (0x1U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_ENABLE_SHIFT (0U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_ENABLE_WIDTH (1U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_ENABLE_SHIFT)) & USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_ENABLE_MASK)

#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_RESET_MASK (0x2U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_RESET_SHIFT (1U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_RESET_WIDTH (1U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_RESET(x) (((uint32_t)(((uint32_t)(x)) << USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_RESET_SHIFT)) & USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_RESET_MASK)

#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_FORCE_UPD_MASK (0x4U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_FORCE_UPD_SHIFT (2U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_FORCE_UPD_WIDTH (1U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_FORCE_UPD(x) (((uint32_t)(((uint32_t)(x)) << USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_FORCE_UPD_SHIFT)) & USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_FORCE_UPD_MASK)

#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_DLY_TARGET_MASK (0x78U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_DLY_TARGET_SHIFT (3U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_DLY_TARGET_WIDTH (4U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_DLY_TARGET(x) (((uint32_t)(((uint32_t)(x)) << USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_DLY_TARGET_SHIFT)) & USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_DLY_TARGET_MASK)

#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_GATE_UPDATE_MASK (0x80U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_GATE_UPDATE_SHIFT (7U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_GATE_UPDATE_WIDTH (1U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_GATE_UPDATE(x) (((uint32_t)(((uint32_t)(x)) << USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_GATE_UPDATE_SHIFT)) & USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_GATE_UPDATE_MASK)

#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_OVERRIDE_MASK (0x100U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_OVERRIDE_SHIFT (8U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_OVERRIDE_WIDTH (1U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_OVERRIDE_SHIFT)) & USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_OVERRIDE_MASK)

#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_OVERRIDE_VAL_MASK (0xFE00U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_OVERRIDE_VAL_SHIFT (9U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_OVERRIDE_VAL_WIDTH (7U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_OVERRIDE_VAL(x) (((uint32_t)(((uint32_t)(x)) << USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_OVERRIDE_VAL_SHIFT)) & USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_OVERRIDE_VAL_MASK)

#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_UPDATE_INT_MASK (0xFF00000U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_UPDATE_INT_SHIFT (20U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_UPDATE_INT_WIDTH (8U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_UPDATE_INT(x) (((uint32_t)(((uint32_t)(x)) << USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_UPDATE_INT_SHIFT)) & USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_SLV_UPDATE_INT_MASK)

#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_REF_UPDATE_INT_MASK (0xF0000000U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_REF_UPDATE_INT_SHIFT (28U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_REF_UPDATE_INT_WIDTH (4U)
#define USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_REF_UPDATE_INT(x) (((uint32_t)(((uint32_t)(x)) << USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_REF_UPDATE_INT_SHIFT)) & USDHC_STROBE_DLL_CTRL_STROBE_DLL_CTRL_REF_UPDATE_INT_MASK)
/*! @} */

/*! @name STROBE_DLL_STATUS - Strobe DLL status */
/*! @{ */

#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_SLV_LOCK_MASK (0x1U)
#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_SLV_LOCK_SHIFT (0U)
#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_SLV_LOCK_WIDTH (1U)
#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_SLV_LOCK(x) (((uint32_t)(((uint32_t)(x)) << USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_SLV_LOCK_SHIFT)) & USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_SLV_LOCK_MASK)

#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_REF_LOCK_MASK (0x2U)
#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_REF_LOCK_SHIFT (1U)
#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_REF_LOCK_WIDTH (1U)
#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_REF_LOCK(x) (((uint32_t)(((uint32_t)(x)) << USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_REF_LOCK_SHIFT)) & USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_REF_LOCK_MASK)

#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_SLV_SEL_MASK (0x1FCU)
#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_SLV_SEL_SHIFT (2U)
#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_SLV_SEL_WIDTH (7U)
#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_SLV_SEL(x) (((uint32_t)(((uint32_t)(x)) << USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_SLV_SEL_SHIFT)) & USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_SLV_SEL_MASK)

#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_REF_SEL_MASK (0xFE00U)
#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_REF_SEL_SHIFT (9U)
#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_REF_SEL_WIDTH (7U)
#define USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_REF_SEL(x) (((uint32_t)(((uint32_t)(x)) << USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_REF_SEL_SHIFT)) & USDHC_STROBE_DLL_STATUS_STROBE_DLL_STS_REF_SEL_MASK)
/*! @} */

/*! @name VEND_SPEC - Vendor Specific Register */
/*! @{ */

#define USDHC_VEND_SPEC_VSELECT_MASK             (0x2U)
#define USDHC_VEND_SPEC_VSELECT_SHIFT            (1U)
#define USDHC_VEND_SPEC_VSELECT_WIDTH            (1U)
#define USDHC_VEND_SPEC_VSELECT(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC_VSELECT_SHIFT)) & USDHC_VEND_SPEC_VSELECT_MASK)

#define USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN_MASK  (0x8U)
#define USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN_SHIFT (3U)
#define USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN_WIDTH (1U)
#define USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN(x)    (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN_SHIFT)) & USDHC_VEND_SPEC_AC12_WR_CHKBUSY_EN_MASK)

#define USDHC_VEND_SPEC_FRC_SDCLK_ON_MASK        (0x100U)
#define USDHC_VEND_SPEC_FRC_SDCLK_ON_SHIFT       (8U)
#define USDHC_VEND_SPEC_FRC_SDCLK_ON_WIDTH       (1U)
#define USDHC_VEND_SPEC_FRC_SDCLK_ON(x)          (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC_FRC_SDCLK_ON_SHIFT)) & USDHC_VEND_SPEC_FRC_SDCLK_ON_MASK)

#define USDHC_VEND_SPEC_CRC_CHK_DIS_MASK         (0x8000U)
#define USDHC_VEND_SPEC_CRC_CHK_DIS_SHIFT        (15U)
#define USDHC_VEND_SPEC_CRC_CHK_DIS_WIDTH        (1U)
#define USDHC_VEND_SPEC_CRC_CHK_DIS(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC_CRC_CHK_DIS_SHIFT)) & USDHC_VEND_SPEC_CRC_CHK_DIS_MASK)

#define USDHC_VEND_SPEC_CMD_BYTE_EN_MASK         (0x80000000U)
#define USDHC_VEND_SPEC_CMD_BYTE_EN_SHIFT        (31U)
#define USDHC_VEND_SPEC_CMD_BYTE_EN_WIDTH        (1U)
#define USDHC_VEND_SPEC_CMD_BYTE_EN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC_CMD_BYTE_EN_SHIFT)) & USDHC_VEND_SPEC_CMD_BYTE_EN_MASK)
/*! @} */

/*! @name MMC_BOOT - eMMC Boot */
/*! @{ */

#define USDHC_MMC_BOOT_DTOCV_ACK_MASK            (0xFU)
#define USDHC_MMC_BOOT_DTOCV_ACK_SHIFT           (0U)
#define USDHC_MMC_BOOT_DTOCV_ACK_WIDTH           (4U)
#define USDHC_MMC_BOOT_DTOCV_ACK(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_MMC_BOOT_DTOCV_ACK_SHIFT)) & USDHC_MMC_BOOT_DTOCV_ACK_MASK)

#define USDHC_MMC_BOOT_BOOT_ACK_MASK             (0x10U)
#define USDHC_MMC_BOOT_BOOT_ACK_SHIFT            (4U)
#define USDHC_MMC_BOOT_BOOT_ACK_WIDTH            (1U)
#define USDHC_MMC_BOOT_BOOT_ACK(x)               (((uint32_t)(((uint32_t)(x)) << USDHC_MMC_BOOT_BOOT_ACK_SHIFT)) & USDHC_MMC_BOOT_BOOT_ACK_MASK)

#define USDHC_MMC_BOOT_BOOT_MODE_MASK            (0x20U)
#define USDHC_MMC_BOOT_BOOT_MODE_SHIFT           (5U)
#define USDHC_MMC_BOOT_BOOT_MODE_WIDTH           (1U)
#define USDHC_MMC_BOOT_BOOT_MODE(x)              (((uint32_t)(((uint32_t)(x)) << USDHC_MMC_BOOT_BOOT_MODE_SHIFT)) & USDHC_MMC_BOOT_BOOT_MODE_MASK)

#define USDHC_MMC_BOOT_BOOT_EN_MASK              (0x40U)
#define USDHC_MMC_BOOT_BOOT_EN_SHIFT             (6U)
#define USDHC_MMC_BOOT_BOOT_EN_WIDTH             (1U)
#define USDHC_MMC_BOOT_BOOT_EN(x)                (((uint32_t)(((uint32_t)(x)) << USDHC_MMC_BOOT_BOOT_EN_SHIFT)) & USDHC_MMC_BOOT_BOOT_EN_MASK)

#define USDHC_MMC_BOOT_AUTO_SABG_EN_MASK         (0x80U)
#define USDHC_MMC_BOOT_AUTO_SABG_EN_SHIFT        (7U)
#define USDHC_MMC_BOOT_AUTO_SABG_EN_WIDTH        (1U)
#define USDHC_MMC_BOOT_AUTO_SABG_EN(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_MMC_BOOT_AUTO_SABG_EN_SHIFT)) & USDHC_MMC_BOOT_AUTO_SABG_EN_MASK)

#define USDHC_MMC_BOOT_DISABLE_TIME_OUT_MASK     (0x100U)
#define USDHC_MMC_BOOT_DISABLE_TIME_OUT_SHIFT    (8U)
#define USDHC_MMC_BOOT_DISABLE_TIME_OUT_WIDTH    (1U)
#define USDHC_MMC_BOOT_DISABLE_TIME_OUT(x)       (((uint32_t)(((uint32_t)(x)) << USDHC_MMC_BOOT_DISABLE_TIME_OUT_SHIFT)) & USDHC_MMC_BOOT_DISABLE_TIME_OUT_MASK)

#define USDHC_MMC_BOOT_BOOT_BLK_CNT_MASK         (0xFFFF0000U)
#define USDHC_MMC_BOOT_BOOT_BLK_CNT_SHIFT        (16U)
#define USDHC_MMC_BOOT_BOOT_BLK_CNT_WIDTH        (16U)
#define USDHC_MMC_BOOT_BOOT_BLK_CNT(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_MMC_BOOT_BOOT_BLK_CNT_SHIFT)) & USDHC_MMC_BOOT_BOOT_BLK_CNT_MASK)
/*! @} */

/*! @name VEND_SPEC2 - Vendor Specific 2 Register */
/*! @{ */

#define USDHC_VEND_SPEC2_CARD_INT_D3_TEST_MASK   (0x8U)
#define USDHC_VEND_SPEC2_CARD_INT_D3_TEST_SHIFT  (3U)
#define USDHC_VEND_SPEC2_CARD_INT_D3_TEST_WIDTH  (1U)
#define USDHC_VEND_SPEC2_CARD_INT_D3_TEST(x)     (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC2_CARD_INT_D3_TEST_SHIFT)) & USDHC_VEND_SPEC2_CARD_INT_D3_TEST_MASK)

#define USDHC_VEND_SPEC2_TUNING_BIT_EN_MASK      (0x30U)
#define USDHC_VEND_SPEC2_TUNING_BIT_EN_SHIFT     (4U)
#define USDHC_VEND_SPEC2_TUNING_BIT_EN_WIDTH     (2U)
#define USDHC_VEND_SPEC2_TUNING_BIT_EN(x)        (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC2_TUNING_BIT_EN_SHIFT)) & USDHC_VEND_SPEC2_TUNING_BIT_EN_MASK)

#define USDHC_VEND_SPEC2_TUNING_CMD_EN_MASK      (0x40U)
#define USDHC_VEND_SPEC2_TUNING_CMD_EN_SHIFT     (6U)
#define USDHC_VEND_SPEC2_TUNING_CMD_EN_WIDTH     (1U)
#define USDHC_VEND_SPEC2_TUNING_CMD_EN(x)        (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC2_TUNING_CMD_EN_SHIFT)) & USDHC_VEND_SPEC2_TUNING_CMD_EN_MASK)

#define USDHC_VEND_SPEC2_HS400_WR_CLK_STOP_EN_MASK (0x400U)
#define USDHC_VEND_SPEC2_HS400_WR_CLK_STOP_EN_SHIFT (10U)
#define USDHC_VEND_SPEC2_HS400_WR_CLK_STOP_EN_WIDTH (1U)
#define USDHC_VEND_SPEC2_HS400_WR_CLK_STOP_EN(x) (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC2_HS400_WR_CLK_STOP_EN_SHIFT)) & USDHC_VEND_SPEC2_HS400_WR_CLK_STOP_EN_MASK)

#define USDHC_VEND_SPEC2_HS400_RD_CLK_STOP_EN_MASK (0x800U)
#define USDHC_VEND_SPEC2_HS400_RD_CLK_STOP_EN_SHIFT (11U)
#define USDHC_VEND_SPEC2_HS400_RD_CLK_STOP_EN_WIDTH (1U)
#define USDHC_VEND_SPEC2_HS400_RD_CLK_STOP_EN(x) (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC2_HS400_RD_CLK_STOP_EN_SHIFT)) & USDHC_VEND_SPEC2_HS400_RD_CLK_STOP_EN_MASK)

#define USDHC_VEND_SPEC2_ACMD23_ARGU2_EN_MASK    (0x1000U)
#define USDHC_VEND_SPEC2_ACMD23_ARGU2_EN_SHIFT   (12U)
#define USDHC_VEND_SPEC2_ACMD23_ARGU2_EN_WIDTH   (1U)
#define USDHC_VEND_SPEC2_ACMD23_ARGU2_EN(x)      (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC2_ACMD23_ARGU2_EN_SHIFT)) & USDHC_VEND_SPEC2_ACMD23_ARGU2_EN_MASK)

#define USDHC_VEND_SPEC2_EN_32K_CLK_MASK         (0x8000U)
#define USDHC_VEND_SPEC2_EN_32K_CLK_SHIFT        (15U)
#define USDHC_VEND_SPEC2_EN_32K_CLK_WIDTH        (1U)
#define USDHC_VEND_SPEC2_EN_32K_CLK(x)           (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC2_EN_32K_CLK_SHIFT)) & USDHC_VEND_SPEC2_EN_32K_CLK_MASK)

#define USDHC_VEND_SPEC2_FBCLK_TAP_SEL_MASK      (0xFFFF0000U)
#define USDHC_VEND_SPEC2_FBCLK_TAP_SEL_SHIFT     (16U)
#define USDHC_VEND_SPEC2_FBCLK_TAP_SEL_WIDTH     (16U)
#define USDHC_VEND_SPEC2_FBCLK_TAP_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USDHC_VEND_SPEC2_FBCLK_TAP_SEL_SHIFT)) & USDHC_VEND_SPEC2_FBCLK_TAP_SEL_MASK)
/*! @} */

/*! @name TUNING_CTRL - Tuning Control */
/*! @{ */

#define USDHC_TUNING_CTRL_TUNING_START_TAP_MASK  (0x7FU)
#define USDHC_TUNING_CTRL_TUNING_START_TAP_SHIFT (0U)
#define USDHC_TUNING_CTRL_TUNING_START_TAP_WIDTH (7U)
#define USDHC_TUNING_CTRL_TUNING_START_TAP(x)    (((uint32_t)(((uint32_t)(x)) << USDHC_TUNING_CTRL_TUNING_START_TAP_SHIFT)) & USDHC_TUNING_CTRL_TUNING_START_TAP_MASK)

#define USDHC_TUNING_CTRL_DIS_CMD_CHK_FOR_STD_TUNING_MASK (0x80U)
#define USDHC_TUNING_CTRL_DIS_CMD_CHK_FOR_STD_TUNING_SHIFT (7U)
#define USDHC_TUNING_CTRL_DIS_CMD_CHK_FOR_STD_TUNING_WIDTH (1U)
#define USDHC_TUNING_CTRL_DIS_CMD_CHK_FOR_STD_TUNING(x) (((uint32_t)(((uint32_t)(x)) << USDHC_TUNING_CTRL_DIS_CMD_CHK_FOR_STD_TUNING_SHIFT)) & USDHC_TUNING_CTRL_DIS_CMD_CHK_FOR_STD_TUNING_MASK)

#define USDHC_TUNING_CTRL_TUNING_COUNTER_MASK    (0xFF00U)
#define USDHC_TUNING_CTRL_TUNING_COUNTER_SHIFT   (8U)
#define USDHC_TUNING_CTRL_TUNING_COUNTER_WIDTH   (8U)
#define USDHC_TUNING_CTRL_TUNING_COUNTER(x)      (((uint32_t)(((uint32_t)(x)) << USDHC_TUNING_CTRL_TUNING_COUNTER_SHIFT)) & USDHC_TUNING_CTRL_TUNING_COUNTER_MASK)

#define USDHC_TUNING_CTRL_TUNING_STEP_MASK       (0x70000U)
#define USDHC_TUNING_CTRL_TUNING_STEP_SHIFT      (16U)
#define USDHC_TUNING_CTRL_TUNING_STEP_WIDTH      (3U)
#define USDHC_TUNING_CTRL_TUNING_STEP(x)         (((uint32_t)(((uint32_t)(x)) << USDHC_TUNING_CTRL_TUNING_STEP_SHIFT)) & USDHC_TUNING_CTRL_TUNING_STEP_MASK)

#define USDHC_TUNING_CTRL_TUNING_WINDOW_MASK     (0x700000U)
#define USDHC_TUNING_CTRL_TUNING_WINDOW_SHIFT    (20U)
#define USDHC_TUNING_CTRL_TUNING_WINDOW_WIDTH    (3U)
#define USDHC_TUNING_CTRL_TUNING_WINDOW(x)       (((uint32_t)(((uint32_t)(x)) << USDHC_TUNING_CTRL_TUNING_WINDOW_SHIFT)) & USDHC_TUNING_CTRL_TUNING_WINDOW_MASK)

#define USDHC_TUNING_CTRL_STD_TUNING_EN_MASK     (0x1000000U)
#define USDHC_TUNING_CTRL_STD_TUNING_EN_SHIFT    (24U)
#define USDHC_TUNING_CTRL_STD_TUNING_EN_WIDTH    (1U)
#define USDHC_TUNING_CTRL_STD_TUNING_EN(x)       (((uint32_t)(((uint32_t)(x)) << USDHC_TUNING_CTRL_STD_TUNING_EN_SHIFT)) & USDHC_TUNING_CTRL_STD_TUNING_EN_MASK)
/*! @} */

/*! @name CQVER - Command Queuing Version */
/*! @{ */

#define USDHC_CQVER_VERSION_SUFFIX_MASK          (0xFU)
#define USDHC_CQVER_VERSION_SUFFIX_SHIFT         (0U)
#define USDHC_CQVER_VERSION_SUFFIX_WIDTH         (4U)
#define USDHC_CQVER_VERSION_SUFFIX(x)            (((uint32_t)(((uint32_t)(x)) << USDHC_CQVER_VERSION_SUFFIX_SHIFT)) & USDHC_CQVER_VERSION_SUFFIX_MASK)

#define USDHC_CQVER_MINOR_VN_MASK                (0xF0U)
#define USDHC_CQVER_MINOR_VN_SHIFT               (4U)
#define USDHC_CQVER_MINOR_VN_WIDTH               (4U)
#define USDHC_CQVER_MINOR_VN(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_CQVER_MINOR_VN_SHIFT)) & USDHC_CQVER_MINOR_VN_MASK)

#define USDHC_CQVER_MAJOR_VN_MASK                (0xF00U)
#define USDHC_CQVER_MAJOR_VN_SHIFT               (8U)
#define USDHC_CQVER_MAJOR_VN_WIDTH               (4U)
#define USDHC_CQVER_MAJOR_VN(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_CQVER_MAJOR_VN_SHIFT)) & USDHC_CQVER_MAJOR_VN_MASK)
/*! @} */

/*! @name CQCAP - Command Queuing Capabilities */
/*! @{ */

#define USDHC_CQCAP_ITCFVAL_MASK                 (0x3FFU)
#define USDHC_CQCAP_ITCFVAL_SHIFT                (0U)
#define USDHC_CQCAP_ITCFVAL_WIDTH                (10U)
#define USDHC_CQCAP_ITCFVAL(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_CQCAP_ITCFVAL_SHIFT)) & USDHC_CQCAP_ITCFVAL_MASK)

#define USDHC_CQCAP_ITCFMUL_MASK                 (0xF000U)
#define USDHC_CQCAP_ITCFMUL_SHIFT                (12U)
#define USDHC_CQCAP_ITCFMUL_WIDTH                (4U)
#define USDHC_CQCAP_ITCFMUL(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_CQCAP_ITCFMUL_SHIFT)) & USDHC_CQCAP_ITCFMUL_MASK)
/*! @} */

/*! @name CQCFG - Command Queuing Configuration */
/*! @{ */

#define USDHC_CQCFG_CQUE_MASK                    (0x1U)
#define USDHC_CQCFG_CQUE_SHIFT                   (0U)
#define USDHC_CQCFG_CQUE_WIDTH                   (1U)
#define USDHC_CQCFG_CQUE(x)                      (((uint32_t)(((uint32_t)(x)) << USDHC_CQCFG_CQUE_SHIFT)) & USDHC_CQCFG_CQUE_MASK)

#define USDHC_CQCFG_TDS_MASK                     (0x100U)
#define USDHC_CQCFG_TDS_SHIFT                    (8U)
#define USDHC_CQCFG_TDS_WIDTH                    (1U)
#define USDHC_CQCFG_TDS(x)                       (((uint32_t)(((uint32_t)(x)) << USDHC_CQCFG_TDS_SHIFT)) & USDHC_CQCFG_TDS_MASK)

#define USDHC_CQCFG_DCMDE_MASK                   (0x1000U)
#define USDHC_CQCFG_DCMDE_SHIFT                  (12U)
#define USDHC_CQCFG_DCMDE_WIDTH                  (1U)
#define USDHC_CQCFG_DCMDE(x)                     (((uint32_t)(((uint32_t)(x)) << USDHC_CQCFG_DCMDE_SHIFT)) & USDHC_CQCFG_DCMDE_MASK)
/*! @} */

/*! @name CQCTL - Command Queuing Control */
/*! @{ */

#define USDHC_CQCTL_HALT_MASK                    (0x1U)
#define USDHC_CQCTL_HALT_SHIFT                   (0U)
#define USDHC_CQCTL_HALT_WIDTH                   (1U)
#define USDHC_CQCTL_HALT(x)                      (((uint32_t)(((uint32_t)(x)) << USDHC_CQCTL_HALT_SHIFT)) & USDHC_CQCTL_HALT_MASK)

#define USDHC_CQCTL_CLEAR_MASK                   (0x100U)
#define USDHC_CQCTL_CLEAR_SHIFT                  (8U)
#define USDHC_CQCTL_CLEAR_WIDTH                  (1U)
#define USDHC_CQCTL_CLEAR(x)                     (((uint32_t)(((uint32_t)(x)) << USDHC_CQCTL_CLEAR_SHIFT)) & USDHC_CQCTL_CLEAR_MASK)
/*! @} */

/*! @name CQIS - Command Queuing Interrupt Status */
/*! @{ */

#define USDHC_CQIS_HAC_MASK                      (0x1U)
#define USDHC_CQIS_HAC_SHIFT                     (0U)
#define USDHC_CQIS_HAC_WIDTH                     (1U)
#define USDHC_CQIS_HAC(x)                        (((uint32_t)(((uint32_t)(x)) << USDHC_CQIS_HAC_SHIFT)) & USDHC_CQIS_HAC_MASK)

#define USDHC_CQIS_TCC_MASK                      (0x2U)
#define USDHC_CQIS_TCC_SHIFT                     (1U)
#define USDHC_CQIS_TCC_WIDTH                     (1U)
#define USDHC_CQIS_TCC(x)                        (((uint32_t)(((uint32_t)(x)) << USDHC_CQIS_TCC_SHIFT)) & USDHC_CQIS_TCC_MASK)

#define USDHC_CQIS_RED_MASK                      (0x4U)
#define USDHC_CQIS_RED_SHIFT                     (2U)
#define USDHC_CQIS_RED_WIDTH                     (1U)
#define USDHC_CQIS_RED(x)                        (((uint32_t)(((uint32_t)(x)) << USDHC_CQIS_RED_SHIFT)) & USDHC_CQIS_RED_MASK)

#define USDHC_CQIS_TCL_MASK                      (0x8U)
#define USDHC_CQIS_TCL_SHIFT                     (3U)
#define USDHC_CQIS_TCL_WIDTH                     (1U)
#define USDHC_CQIS_TCL(x)                        (((uint32_t)(((uint32_t)(x)) << USDHC_CQIS_TCL_SHIFT)) & USDHC_CQIS_TCL_MASK)
/*! @} */

/*! @name CQISTE - Command Queuing Interrupt Status Enable */
/*! @{ */

#define USDHC_CQISTE_HAC_STE_MASK                (0x1U)
#define USDHC_CQISTE_HAC_STE_SHIFT               (0U)
#define USDHC_CQISTE_HAC_STE_WIDTH               (1U)
#define USDHC_CQISTE_HAC_STE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_CQISTE_HAC_STE_SHIFT)) & USDHC_CQISTE_HAC_STE_MASK)

#define USDHC_CQISTE_TCC_STE_MASK                (0x2U)
#define USDHC_CQISTE_TCC_STE_SHIFT               (1U)
#define USDHC_CQISTE_TCC_STE_WIDTH               (1U)
#define USDHC_CQISTE_TCC_STE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_CQISTE_TCC_STE_SHIFT)) & USDHC_CQISTE_TCC_STE_MASK)

#define USDHC_CQISTE_RED_STE_MASK                (0x4U)
#define USDHC_CQISTE_RED_STE_SHIFT               (2U)
#define USDHC_CQISTE_RED_STE_WIDTH               (1U)
#define USDHC_CQISTE_RED_STE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_CQISTE_RED_STE_SHIFT)) & USDHC_CQISTE_RED_STE_MASK)

#define USDHC_CQISTE_TCL_STE_MASK                (0x8U)
#define USDHC_CQISTE_TCL_STE_SHIFT               (3U)
#define USDHC_CQISTE_TCL_STE_WIDTH               (1U)
#define USDHC_CQISTE_TCL_STE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_CQISTE_TCL_STE_SHIFT)) & USDHC_CQISTE_TCL_STE_MASK)
/*! @} */

/*! @name CQISGE - Command Queuing Interrupt Signal Enable */
/*! @{ */

#define USDHC_CQISGE_HAC_SGE_MASK                (0x1U)
#define USDHC_CQISGE_HAC_SGE_SHIFT               (0U)
#define USDHC_CQISGE_HAC_SGE_WIDTH               (1U)
#define USDHC_CQISGE_HAC_SGE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_CQISGE_HAC_SGE_SHIFT)) & USDHC_CQISGE_HAC_SGE_MASK)

#define USDHC_CQISGE_TCC_SGE_MASK                (0x2U)
#define USDHC_CQISGE_TCC_SGE_SHIFT               (1U)
#define USDHC_CQISGE_TCC_SGE_WIDTH               (1U)
#define USDHC_CQISGE_TCC_SGE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_CQISGE_TCC_SGE_SHIFT)) & USDHC_CQISGE_TCC_SGE_MASK)

#define USDHC_CQISGE_RED_SGE_MASK                (0x4U)
#define USDHC_CQISGE_RED_SGE_SHIFT               (2U)
#define USDHC_CQISGE_RED_SGE_WIDTH               (1U)
#define USDHC_CQISGE_RED_SGE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_CQISGE_RED_SGE_SHIFT)) & USDHC_CQISGE_RED_SGE_MASK)

#define USDHC_CQISGE_TCL_SGE_MASK                (0x8U)
#define USDHC_CQISGE_TCL_SGE_SHIFT               (3U)
#define USDHC_CQISGE_TCL_SGE_WIDTH               (1U)
#define USDHC_CQISGE_TCL_SGE(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_CQISGE_TCL_SGE_SHIFT)) & USDHC_CQISGE_TCL_SGE_MASK)
/*! @} */

/*! @name CQIC - Command Queuing Interrupt Coalescing */
/*! @{ */

#define USDHC_CQIC_ICTOVAL_MASK                  (0x7FU)
#define USDHC_CQIC_ICTOVAL_SHIFT                 (0U)
#define USDHC_CQIC_ICTOVAL_WIDTH                 (7U)
#define USDHC_CQIC_ICTOVAL(x)                    (((uint32_t)(((uint32_t)(x)) << USDHC_CQIC_ICTOVAL_SHIFT)) & USDHC_CQIC_ICTOVAL_MASK)

#define USDHC_CQIC_ICTOVALWEN_MASK               (0x80U)
#define USDHC_CQIC_ICTOVALWEN_SHIFT              (7U)
#define USDHC_CQIC_ICTOVALWEN_WIDTH              (1U)
#define USDHC_CQIC_ICTOVALWEN(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_CQIC_ICTOVALWEN_SHIFT)) & USDHC_CQIC_ICTOVALWEN_MASK)

#define USDHC_CQIC_ICCTH_MASK                    (0x1F00U)
#define USDHC_CQIC_ICCTH_SHIFT                   (8U)
#define USDHC_CQIC_ICCTH_WIDTH                   (5U)
#define USDHC_CQIC_ICCTH(x)                      (((uint32_t)(((uint32_t)(x)) << USDHC_CQIC_ICCTH_SHIFT)) & USDHC_CQIC_ICCTH_MASK)

#define USDHC_CQIC_ICCTHWEN_MASK                 (0x8000U)
#define USDHC_CQIC_ICCTHWEN_SHIFT                (15U)
#define USDHC_CQIC_ICCTHWEN_WIDTH                (1U)
#define USDHC_CQIC_ICCTHWEN(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_CQIC_ICCTHWEN_SHIFT)) & USDHC_CQIC_ICCTHWEN_MASK)

#define USDHC_CQIC_ICCTR_MASK                    (0x10000U)
#define USDHC_CQIC_ICCTR_SHIFT                   (16U)
#define USDHC_CQIC_ICCTR_WIDTH                   (1U)
#define USDHC_CQIC_ICCTR(x)                      (((uint32_t)(((uint32_t)(x)) << USDHC_CQIC_ICCTR_SHIFT)) & USDHC_CQIC_ICCTR_MASK)

#define USDHC_CQIC_ICSB_MASK                     (0x100000U)
#define USDHC_CQIC_ICSB_SHIFT                    (20U)
#define USDHC_CQIC_ICSB_WIDTH                    (1U)
#define USDHC_CQIC_ICSB(x)                       (((uint32_t)(((uint32_t)(x)) << USDHC_CQIC_ICSB_SHIFT)) & USDHC_CQIC_ICSB_MASK)

#define USDHC_CQIC_ICENDIS_MASK                  (0x80000000U)
#define USDHC_CQIC_ICENDIS_SHIFT                 (31U)
#define USDHC_CQIC_ICENDIS_WIDTH                 (1U)
#define USDHC_CQIC_ICENDIS(x)                    (((uint32_t)(((uint32_t)(x)) << USDHC_CQIC_ICENDIS_SHIFT)) & USDHC_CQIC_ICENDIS_MASK)
/*! @} */

/*! @name CQTDLBA - Command Queuing Task Descriptor List Base Address */
/*! @{ */

#define USDHC_CQTDLBA_TDLBA_MASK                 (0xFFFFFFFFU)
#define USDHC_CQTDLBA_TDLBA_SHIFT                (0U)
#define USDHC_CQTDLBA_TDLBA_WIDTH                (32U)
#define USDHC_CQTDLBA_TDLBA(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_CQTDLBA_TDLBA_SHIFT)) & USDHC_CQTDLBA_TDLBA_MASK)
/*! @} */

/*! @name CQTDLBAU - Command Queuing Task Descriptor List Base Address Upper 32 Bits */
/*! @{ */

#define USDHC_CQTDLBAU_TDLBAU_MASK               (0xFFFFFFFFU)
#define USDHC_CQTDLBAU_TDLBAU_SHIFT              (0U)
#define USDHC_CQTDLBAU_TDLBAU_WIDTH              (32U)
#define USDHC_CQTDLBAU_TDLBAU(x)                 (((uint32_t)(((uint32_t)(x)) << USDHC_CQTDLBAU_TDLBAU_SHIFT)) & USDHC_CQTDLBAU_TDLBAU_MASK)
/*! @} */

/*! @name CQTDBR - Command Queuing Task Doorbell */
/*! @{ */

#define USDHC_CQTDBR_TDBR_MASK                   (0xFFFFFFFFU)
#define USDHC_CQTDBR_TDBR_SHIFT                  (0U)
#define USDHC_CQTDBR_TDBR_WIDTH                  (32U)
#define USDHC_CQTDBR_TDBR(x)                     (((uint32_t)(((uint32_t)(x)) << USDHC_CQTDBR_TDBR_SHIFT)) & USDHC_CQTDBR_TDBR_MASK)
/*! @} */

/*! @name CQTCN - Command Queuing Task Completion Notification */
/*! @{ */

#define USDHC_CQTCN_TCN_MASK                     (0xFFFFFFFFU)
#define USDHC_CQTCN_TCN_SHIFT                    (0U)
#define USDHC_CQTCN_TCN_WIDTH                    (32U)
#define USDHC_CQTCN_TCN(x)                       (((uint32_t)(((uint32_t)(x)) << USDHC_CQTCN_TCN_SHIFT)) & USDHC_CQTCN_TCN_MASK)
/*! @} */

/*! @name CQDQS - Command Queuing Device Queue Status */
/*! @{ */

#define USDHC_CQDQS_DQS_MASK                     (0xFFFFFFFFU)
#define USDHC_CQDQS_DQS_SHIFT                    (0U)
#define USDHC_CQDQS_DQS_WIDTH                    (32U)
#define USDHC_CQDQS_DQS(x)                       (((uint32_t)(((uint32_t)(x)) << USDHC_CQDQS_DQS_SHIFT)) & USDHC_CQDQS_DQS_MASK)
/*! @} */

/*! @name CQDPT - Command Queuing Device Pending Tasks */
/*! @{ */

#define USDHC_CQDPT_DPT_MASK                     (0xFFFFFFFFU)
#define USDHC_CQDPT_DPT_SHIFT                    (0U)
#define USDHC_CQDPT_DPT_WIDTH                    (32U)
#define USDHC_CQDPT_DPT(x)                       (((uint32_t)(((uint32_t)(x)) << USDHC_CQDPT_DPT_SHIFT)) & USDHC_CQDPT_DPT_MASK)
/*! @} */

/*! @name CQTCLR - Command Queuing Task Clear */
/*! @{ */

#define USDHC_CQTCLR_TCLR_MASK                   (0xFFFFFFFFU)
#define USDHC_CQTCLR_TCLR_SHIFT                  (0U)
#define USDHC_CQTCLR_TCLR_WIDTH                  (32U)
#define USDHC_CQTCLR_TCLR(x)                     (((uint32_t)(((uint32_t)(x)) << USDHC_CQTCLR_TCLR_SHIFT)) & USDHC_CQTCLR_TCLR_MASK)
/*! @} */

/*! @name CQSSC1 - Command Queuing Send Status Configuration 1 */
/*! @{ */

#define USDHC_CQSSC1_CIT_MASK                    (0xFFFFU)
#define USDHC_CQSSC1_CIT_SHIFT                   (0U)
#define USDHC_CQSSC1_CIT_WIDTH                   (16U)
#define USDHC_CQSSC1_CIT(x)                      (((uint32_t)(((uint32_t)(x)) << USDHC_CQSSC1_CIT_SHIFT)) & USDHC_CQSSC1_CIT_MASK)

#define USDHC_CQSSC1_CBC_MASK                    (0xF0000U)
#define USDHC_CQSSC1_CBC_SHIFT                   (16U)
#define USDHC_CQSSC1_CBC_WIDTH                   (4U)
#define USDHC_CQSSC1_CBC(x)                      (((uint32_t)(((uint32_t)(x)) << USDHC_CQSSC1_CBC_SHIFT)) & USDHC_CQSSC1_CBC_MASK)
/*! @} */

/*! @name CQSSC2 - Command Queuing Send Status Configuration 2 */
/*! @{ */

#define USDHC_CQSSC2_SSC2_MASK                   (0xFFFFU)
#define USDHC_CQSSC2_SSC2_SHIFT                  (0U)
#define USDHC_CQSSC2_SSC2_WIDTH                  (16U)
#define USDHC_CQSSC2_SSC2(x)                     (((uint32_t)(((uint32_t)(x)) << USDHC_CQSSC2_SSC2_SHIFT)) & USDHC_CQSSC2_SSC2_MASK)
/*! @} */

/*! @name CQCRDCT - Command Queuing Command Response for Direct-Command Task */
/*! @{ */

#define USDHC_CQCRDCT_CRDCT_MASK                 (0xFFFFFFFFU)
#define USDHC_CQCRDCT_CRDCT_SHIFT                (0U)
#define USDHC_CQCRDCT_CRDCT_WIDTH                (32U)
#define USDHC_CQCRDCT_CRDCT(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_CQCRDCT_CRDCT_SHIFT)) & USDHC_CQCRDCT_CRDCT_MASK)
/*! @} */

/*! @name CQRMEM - Command Queuing Response Mode Error Mask */
/*! @{ */

#define USDHC_CQRMEM_RMEM_MASK                   (0xFFFFFFFFU)
#define USDHC_CQRMEM_RMEM_SHIFT                  (0U)
#define USDHC_CQRMEM_RMEM_WIDTH                  (32U)
#define USDHC_CQRMEM_RMEM(x)                     (((uint32_t)(((uint32_t)(x)) << USDHC_CQRMEM_RMEM_SHIFT)) & USDHC_CQRMEM_RMEM_MASK)
/*! @} */

/*! @name CQTERRI - Command Queuing Task Error Information */
/*! @{ */

#define USDHC_CQTERRI_RMECI_MASK                 (0x3FU)
#define USDHC_CQTERRI_RMECI_SHIFT                (0U)
#define USDHC_CQTERRI_RMECI_WIDTH                (6U)
#define USDHC_CQTERRI_RMECI(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_CQTERRI_RMECI_SHIFT)) & USDHC_CQTERRI_RMECI_MASK)

#define USDHC_CQTERRI_RMETID_MASK                (0x1F00U)
#define USDHC_CQTERRI_RMETID_SHIFT               (8U)
#define USDHC_CQTERRI_RMETID_WIDTH               (5U)
#define USDHC_CQTERRI_RMETID(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_CQTERRI_RMETID_SHIFT)) & USDHC_CQTERRI_RMETID_MASK)

#define USDHC_CQTERRI_RMEFV_MASK                 (0x8000U)
#define USDHC_CQTERRI_RMEFV_SHIFT                (15U)
#define USDHC_CQTERRI_RMEFV_WIDTH                (1U)
#define USDHC_CQTERRI_RMEFV(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_CQTERRI_RMEFV_SHIFT)) & USDHC_CQTERRI_RMEFV_MASK)

#define USDHC_CQTERRI_DTECI_MASK                 (0x3F0000U)
#define USDHC_CQTERRI_DTECI_SHIFT                (16U)
#define USDHC_CQTERRI_DTECI_WIDTH                (6U)
#define USDHC_CQTERRI_DTECI(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_CQTERRI_DTECI_SHIFT)) & USDHC_CQTERRI_DTECI_MASK)

#define USDHC_CQTERRI_DTETID_MASK                (0x1F000000U)
#define USDHC_CQTERRI_DTETID_SHIFT               (24U)
#define USDHC_CQTERRI_DTETID_WIDTH               (5U)
#define USDHC_CQTERRI_DTETID(x)                  (((uint32_t)(((uint32_t)(x)) << USDHC_CQTERRI_DTETID_SHIFT)) & USDHC_CQTERRI_DTETID_MASK)

#define USDHC_CQTERRI_DTEFV_MASK                 (0x80000000U)
#define USDHC_CQTERRI_DTEFV_SHIFT                (31U)
#define USDHC_CQTERRI_DTEFV_WIDTH                (1U)
#define USDHC_CQTERRI_DTEFV(x)                   (((uint32_t)(((uint32_t)(x)) << USDHC_CQTERRI_DTEFV_SHIFT)) & USDHC_CQTERRI_DTEFV_MASK)
/*! @} */

/*! @name CQCRI - Command Queuing Command Response Index */
/*! @{ */

#define USDHC_CQCRI_LCMDRI_MASK                  (0x3FU)
#define USDHC_CQCRI_LCMDRI_SHIFT                 (0U)
#define USDHC_CQCRI_LCMDRI_WIDTH                 (6U)
#define USDHC_CQCRI_LCMDRI(x)                    (((uint32_t)(((uint32_t)(x)) << USDHC_CQCRI_LCMDRI_SHIFT)) & USDHC_CQCRI_LCMDRI_MASK)
/*! @} */

/*! @name CQCRA - Command Queuing Command Response Argument */
/*! @{ */

#define USDHC_CQCRA_LCMDRA_MASK                  (0xFFFFFFFFU)
#define USDHC_CQCRA_LCMDRA_SHIFT                 (0U)
#define USDHC_CQCRA_LCMDRA_WIDTH                 (32U)
#define USDHC_CQCRA_LCMDRA(x)                    (((uint32_t)(((uint32_t)(x)) << USDHC_CQCRA_LCMDRA_SHIFT)) & USDHC_CQCRA_LCMDRA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group USDHC_Register_Masks */

/*!
 * @}
 */ /* end of group USDHC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_USDHC_H_) */
