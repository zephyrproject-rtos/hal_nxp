/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_XSPI.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_XSPI
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
#if !defined(S32K566_XSPI_H_)  /* Check if memory map has not been already included */
#define S32K566_XSPI_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- XSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XSPI_Peripheral_Access_Layer XSPI Peripheral Access Layer
 * @{
 */

/** XSPI - Size of Registers Arrays */
#define XSPI_BUFIND_COUNT                         3u
#define XSPI_DLLCR_COUNT                          1u
#define XSPI_DLSR_ARRAY_COUNT                     1u
#define XSPI_SFMTA_COUNT                          1u
#define XSPI_SFMTA_SFM_COUNT                      2u
#define XSPI_FAIL_ADDR_ARRAY_COUNT                1u
#define XSPI_RBDR_ARRAY_COUNT                     64u
#define XSPI_LUT_COUNT                            80u
#define XSPI_BUFN_M_ADDR_RANGE_COUNT              4u
#define XSPI_BUFN_M_ADDR_RANGE_BUFN_M_ADDR_RANGE_COUNT 4u
#define XSPI_AHB_PERF_BUFN_COUNT                  4u
#define XSPI_IPEDCTXXIV_IPEDCTXXIVY_COUNT         2u
#define XSPI_IPEDCTXXIV_IPEDCTXXAADY_COUNT        2u
#define XSPI_IPEDCTXXIV_COUNT                     16u
#define XSPI_IPEDCTXCTRLX_COUNT                   2u
#define XSPI_SFP_LUT_EN_ARRAY_COUNT               2u
#define XSPI_SUB_REG_MDAM_ARRAY_COUNT             1u

/** XSPI - Register Layout Typedef */
typedef struct XSPI_Struct {
  __IO uint32_t MCR;                               /**< Module Configuration, offset: 0x0 */
  uint8_t RESERVED_0[4];
  __I  uint32_t IPCR;                              /**< IP Configuration, offset: 0x8 */
  __IO uint32_t FLSHCR;                            /**< Flash Memory Configuration, offset: 0xC */
  __IO uint32_t BUF0CR;                            /**< Buffer Configuration, offset: 0x10 */
  __IO uint32_t BUF1CR;                            /**< Buffer Configuration, offset: 0x14 */
  __IO uint32_t BUF2CR;                            /**< Buffer Configuration, offset: 0x18 */
  __IO uint32_t BUF3CR;                            /**< Buffer Configuration, offset: 0x1C */
  __IO uint32_t BFGENCR;                           /**< Buffer Generic Configuration, offset: 0x20 */
  __IO uint32_t SOCCR;                             /**< SOC Configuration, offset: 0x24 */
  uint8_t RESERVED_1[8];
  __IO uint32_t BUFIND[XSPI_BUFIND_COUNT];         /**< Buffer 0 Top Index..Buffer 2 Top Index, array offset: 0x30, array step: 0x4 */
  uint8_t RESERVED_2[16];
  __IO uint32_t PRW_RDSR;                          /**< Page Read Wait Status, offset: 0x4C */
  __IO uint32_t AWRCR;                             /**< AHB Write Configuration, offset: 0x50 */
  __IO uint32_t ARDCR;                             /**< AHB Read Configuration, offset: 0x54 */
  __IO uint32_t AWITO;                             /**< AHB Write Idle Timeout Configuration, offset: 0x58 */
  __IO uint32_t FSR_ADDR;                          /**< Flash Status Register Address, offset: 0x5C */
  __IO uint32_t DLLCR[XSPI_DLLCR_COUNT];           /**< DLL Flash Memory A Configuration, array offset: 0x60, array step: 0x4 */
  uint8_t RESERVED_3[8];
  __IO uint32_t PARITYCR;                          /**< Parity Configuration, offset: 0x6C */
  uint8_t RESERVED_4[144];
  __I  uint32_t SFAR;                              /**< Serial Flash Memory Address, offset: 0x100 */
  __IO uint32_t SFACR;                             /**< Serial Flash Memory Address Configuration, offset: 0x104 */
  __IO uint32_t SMPR;                              /**< Sampling, offset: 0x108 */
  __I  uint32_t RBSR;                              /**< RX Buffer Status, offset: 0x10C */
  __IO uint32_t RBCT;                              /**< RX Buffer Control, offset: 0x110 */
  uint8_t RESERVED_5[12];
  __I  uint32_t AWRSR;                             /**< AHB Write Status, offset: 0x120 */
  uint8_t RESERVED_6[8];
  __I  uint32_t DLLSR;                             /**< DLL Status, offset: 0x12C */
  __IO uint32_t DLCR;                              /**< Data Learning Configuration, offset: 0x130 */
  __I  uint32_t DLSR_F[XSPI_DLSR_ARRAY_COUNT];     /**< Data Learning Status Flash Memory, array offset: 0x134, array step: 0x4 */
  uint8_t RESERVED_7[24];
  __I  uint32_t TBSR;                              /**< TX Buffer Status, offset: 0x150 */
  __IO uint32_t TBDR;                              /**< TX Buffer Data, offset: 0x154 */
  __IO uint32_t TBCT;                              /**< TX Buffer Control, offset: 0x158 */
  __I  uint32_t SR;                                /**< Status, offset: 0x15C */
  __IO uint32_t FR;                                /**< Flag, offset: 0x160 */
  __IO uint32_t RSER;                              /**< Interrupt and DMA Request Enable, offset: 0x164 */
  __I  uint32_t SPNDST;                            /**< Sequence Suspend Status, offset: 0x168 */
  __IO uint32_t SPTRCLR;                           /**< Sequence Pointer Clear, offset: 0x16C */
  uint8_t RESERVED_8[16];
  __IO uint32_t SFAD[XSPI_SFMTA_COUNT][XSPI_SFMTA_SFM_COUNT]; /**< Serial Flash Memory Top Address, array offset: 0x180, array step: index*0x8, index2*0x4 */
  uint8_t RESERVED_9[8];
  __IO uint32_t DLPR;                              /**< Data Learning Pattern, offset: 0x190 */
  __I  uint32_t FAIL_ADDR[XSPI_FAIL_ADDR_ARRAY_COUNT]; /**< Flash Memory A Failing Address Status, array offset: 0x194, array step: 0x4 */
  uint8_t RESERVED_10[104];
  __I  uint32_t RBDR[XSPI_RBDR_ARRAY_COUNT];       /**< RX Buffer Data, array offset: 0x200, array step: 0x4 */
  __IO uint32_t LUTKEY;                            /**< LUT Key, offset: 0x300 */
  __IO uint32_t LCKCR;                             /**< LUT Lock Configuration, offset: 0x304 */
  uint8_t RESERVED_11[8];
  __IO uint32_t LUT[XSPI_LUT_COUNT];               /**< Lookup Table, array offset: 0x310, array step: 0x4 */
  uint8_t RESERVED_12[48];
  __IO uint32_t BUF_ADDR_RANGE[XSPI_BUFN_M_ADDR_RANGE_COUNT][XSPI_BUFN_M_ADDR_RANGE_BUFN_M_ADDR_RANGE_COUNT]; /**< AHB Buffer 0 Sub Buffer 0 Start and End Address Range..AHB Buffer 3 Sub Buffer 3 Start and End Address Range, array offset: 0x480, array step: index*0x10, index2*0x4 */
  __I  uint32_t AHB_BUF_STATUS;                    /**< AHB Buffer Status, offset: 0x4C0 */
  __IO uint32_t AHB_PERF_CTRL;                     /**< AHB Buffer Hit/Miss Performance Monitor Control, offset: 0x4C4 */
  __I  uint32_t AHB_PERF_TIME_CNT;                 /**< AHB Performance Monitor Time Counter, offset: 0x4C8 */
  __I  uint32_t AHB_PERF_BUF[XSPI_AHB_PERF_BUFN_COUNT]; /**< AHB Buffer 0 Performance Monitor..AHB Buffer 3 Performance Monitor, array offset: 0x4CC, array step: 0x4 */
  __IO uint32_t AHRDYTO;                           /**< AHB HREADY Timeout, offset: 0x4DC */
  __IO uint32_t AHB_ERR_PAYLOAD_HI;                /**< AHB Error Payload High, offset: 0x4E0 */
  __IO uint32_t AHB_ERR_PAYLOAD_LO;                /**< AHB Error Payload Low, offset: 0x4E4 */
  __I  uint32_t AHB_RD_ERR_ADDR;                   /**< AHB Read Error Address, offset: 0x4E8 */
  __I  uint32_t AHB_RD_ERR_MID;                    /**< AHB Read Error Initiator ID, offset: 0x4EC */
  __I  uint32_t SPNDST_ADDR;                       /**< Suspend Transaction Address, offset: 0x4F0 */
  __IO uint32_t PPWF_TCNT;                         /**< Page Program Wait Time Counter, offset: 0x4F4 */
  __IO uint32_t PPW_RDSR;                          /**< Page Program Wait Read Status, offset: 0x4F8 */
  uint8_t RESERVED_13[36];
  struct XSPI_IPEDCTXXIV {                         /* offset: 0x520, array step: 0x20 */
    __IO uint32_t IPEDCTXIV[XSPI_IPEDCTXXIV_IPEDCTXXIVY_COUNT];   /**< IPED Context Initial Vector, array offset: 0x520, array step: index*0x20, index2*0x4 */
    __IO uint32_t IPEDCTXSTART;                      /**< IPED Start Address Region, array offset: 0x528, array step: 0x20 */
    __IO uint32_t IPEDCTXEND;                        /**< IPED End Address Region, array offset: 0x52C, array step: 0x20 */
    __IO uint32_t IPEDCTXAAD[XSPI_IPEDCTXXIV_IPEDCTXXAADY_COUNT];   /**< IPED Context Additional Authentication Data, array offset: 0x530, array step: index*0x20, index2*0x4 */
    uint8_t RESERVED_0[8];
  } IPEDCTXXIV[XSPI_IPEDCTXXIV_COUNT];
  __IO uint32_t IPEDCTRL;                          /**< IPED Function Control, offset: 0x720 */
  uint8_t RESERVED_14[4];
  __IO uint32_t IPEDCTXCTRL[XSPI_IPEDCTXCTRLX_COUNT]; /**< IPED Context Control 0..IPED Context Control 1, array offset: 0x728, array step: 0x4 */
  uint8_t RESERVED_15[80];
  __I  uint32_t AWR_WRAP_STATUS;                   /**< AHB Write Wrap Status, offset: 0x780 */
  __I  uint32_t AHB_WW_ERR_ADDR_EBT;               /**< Write Wrap Burst Error Address due to Early Termination, offset: 0x784 */
  __I  uint32_t AHB_WW_ERR_ADDR_ARL;               /**< Write Wrap Burst Error Address due to Arbitration Lock, offset: 0x788 */
  __I  uint32_t AHB_WW_ERR_ADDR;                   /**< AHB Write Wrap Burst Error Address, offset: 0x78C */
  __IO uint32_t FR2;                               /**< Flag 2, offset: 0x790 */
  __IO uint32_t RSER2;                             /**< Interrupt and DMA Request Enable 2, offset: 0x794 */
  uint8_t RESERVED_16[64];
  __I  uint32_t ARSWRST_ADDR;                      /**< AHB Read Burst Address on Soft Reset, offset: 0x7D8 */
  __I  uint32_t ARSWRST_MID;                       /**< AHB Read Burst Initiator ID on Soft Reset, offset: 0x7DC */
  __I  uint32_t AWSWRST_ADDR;                      /**< AHB Write Burst Address on Soft Reset, offset: 0x7E0 */
  uint8_t RESERVED_17[28];
  __IO uint32_t FRAD0_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x800 */
  __IO uint32_t FRAD0_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x804 */
  __IO uint32_t FRAD0_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x808 */
  __IO uint32_t FRAD0_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x80C */
  __I  uint32_t FRAD0_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x810 */
  __I  uint32_t FRAD0_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x814 */
  uint8_t RESERVED_18[8];
  __IO uint32_t FRAD1_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x820 */
  __IO uint32_t FRAD1_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x824 */
  __IO uint32_t FRAD1_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x828 */
  __IO uint32_t FRAD1_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x82C */
  __I  uint32_t FRAD1_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x830 */
  __I  uint32_t FRAD1_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x834 */
  uint8_t RESERVED_19[8];
  __IO uint32_t FRAD2_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x840 */
  __IO uint32_t FRAD2_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x844 */
  __IO uint32_t FRAD2_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x848 */
  __IO uint32_t FRAD2_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x84C */
  __I  uint32_t FRAD2_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x850 */
  __I  uint32_t FRAD2_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x854 */
  uint8_t RESERVED_20[8];
  __IO uint32_t FRAD3_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x860 */
  __IO uint32_t FRAD3_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x864 */
  __IO uint32_t FRAD3_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x868 */
  __IO uint32_t FRAD3_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x86C */
  __I  uint32_t FRAD3_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x870 */
  __I  uint32_t FRAD3_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x874 */
  uint8_t RESERVED_21[8];
  __IO uint32_t FRAD4_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x880 */
  __IO uint32_t FRAD4_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x884 */
  __IO uint32_t FRAD4_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x888 */
  __IO uint32_t FRAD4_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x88C */
  __I  uint32_t FRAD4_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x890 */
  __I  uint32_t FRAD4_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x894 */
  uint8_t RESERVED_22[8];
  __IO uint32_t FRAD5_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x8A0 */
  __IO uint32_t FRAD5_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x8A4 */
  __IO uint32_t FRAD5_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x8A8 */
  __IO uint32_t FRAD5_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x8AC */
  __I  uint32_t FRAD5_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x8B0 */
  __I  uint32_t FRAD5_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x8B4 */
  uint8_t RESERVED_23[8];
  __IO uint32_t FRAD6_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x8C0 */
  __IO uint32_t FRAD6_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x8C4 */
  __IO uint32_t FRAD6_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x8C8 */
  __IO uint32_t FRAD6_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x8CC */
  __I  uint32_t FRAD6_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x8D0 */
  __I  uint32_t FRAD6_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x8D4 */
  uint8_t RESERVED_24[8];
  __IO uint32_t FRAD7_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x8E0 */
  __IO uint32_t FRAD7_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x8E4 */
  __IO uint32_t FRAD7_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x8E8 */
  __IO uint32_t FRAD7_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x8EC */
  __I  uint32_t FRAD7_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x8F0 */
  __I  uint32_t FRAD7_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x8F4 */
  uint8_t RESERVED_25[4];
  __IO uint32_t SFP_ARB_TIMEOUT;                   /**< SFP Arbitration Lock Timeout Counter, offset: 0x8FC */
  __IO uint32_t TG0MDAD;                           /**< Target Group Initiator Domain Access Descriptor, offset: 0x900 */
  __I  uint32_t TGSFAR;                            /**< Target Group SFAR Address, offset: 0x904 */
  __IO uint32_t TGSFARS;                           /**< Target Group SFAR Status, offset: 0x908 */
  __IO uint32_t TGIPCRS;                           /**< Target Group IP Configuration Status, offset: 0x90C */
  __IO uint32_t TG1MDAD;                           /**< Target Group Initiator Domain Access Descriptor, offset: 0x910 */
  uint8_t RESERVED_26[12];
  __IO uint32_t MGC;                               /**< Initiator Global Configuration, offset: 0x920 */
  __IO uint32_t MRC;                               /**< Initiator Read Command, offset: 0x924 */
  __IO uint32_t MTO;                               /**< Initiator Timeout, offset: 0x928 */
  __I  uint32_t FLSEQREQ;                          /**< Flash Sequence Request, offset: 0x92C */
  __I  uint32_t FSMSTAT;                           /**< FSM Status, offset: 0x930 */
  __IO uint32_t IPSERROR;                          /**< IPS Error, offset: 0x934 */
  __IO uint32_t ERRSTAT;                           /**< Error Status, offset: 0x938 */
  __IO uint32_t INT_EN;                            /**< Interrupt Enable, offset: 0x93C */
  uint8_t RESERVED_27[24];
  __IO uint32_t SFP_TG_IPCR;                       /**< IP Configuration, offset: 0x958 */
  __IO uint32_t SFP_TG_SFAR;                       /**< Serial Flash Memory Address, offset: 0x95C */
  __IO uint32_t SFP_LUT_EN[XSPI_SFP_LUT_EN_ARRAY_COUNT]; /**< LUT Access Enable, array offset: 0x960, array step: 0x4 */
  uint8_t RESERVED_28[276];
  __I  uint32_t SFP_LOCK_ERR_ADDR;                 /**< SFP Lock Error Address, offset: 0xA7C */
  struct XSPI_SUB_REG_MDAM_ARRAY {                 /* offset: 0xA80, array step: 0x14 */
    __IO uint32_t SFP_TG_SUB_IPCR;                   /**< IP Configuration, array offset: 0xA80, array step: 0x14 */
    __IO uint32_t SFP_TG_SUB_SFAR;                   /**< Serial Flash Memory Address, array offset: 0xA84, array step: 0x14 */
    __I  uint32_t TGSFAR_SUB;                        /**< Target Group SFAR Address, array offset: 0xA88, array step: 0x14 */
    __IO uint32_t TGSFARS_SUB;                       /**< Target Group SFAR Status, array offset: 0xA8C, array step: 0x14 */
    __IO uint32_t TGIPCRS_SUB;                       /**< Target Group n IP Configuration Status, array offset: 0xA90, array step: 0x14 */
  } SUB_REG_MDAM_ARRAY[XSPI_SUB_REG_MDAM_ARRAY_COUNT];
} XSPI_Type, *XSPI_MemMapPtr;

/** Number of instances of the XSPI module. */
#define XSPI_INSTANCE_COUNT                      (1u)

/* XSPI - Peripheral instance base addresses */
/** Peripheral XSPI base address */
#define IP_XSPI_BASE                             (0x40BA4000u)
/** Peripheral XSPI base pointer */
#define IP_XSPI                                  ((XSPI_Type *)IP_XSPI_BASE)
/** Array initializer of XSPI peripheral base addresses */
#define IP_XSPI_BASE_ADDRS                       { IP_XSPI_BASE }
/** Array initializer of XSPI peripheral base pointers */
#define IP_XSPI_BASE_PTRS                        { IP_XSPI }

/* ----------------------------------------------------------------------------
   -- XSPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XSPI_Register_Masks XSPI Register Masks
 * @{
 */

/*! @name MCR - Module Configuration */
/*! @{ */

#define XSPI_MCR_SWRSTSD_MASK                    (0x1U)
#define XSPI_MCR_SWRSTSD_SHIFT                   (0U)
#define XSPI_MCR_SWRSTSD_WIDTH                   (1U)
#define XSPI_MCR_SWRSTSD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_SWRSTSD_SHIFT)) & XSPI_MCR_SWRSTSD_MASK)

#define XSPI_MCR_SWRSTHD_MASK                    (0x2U)
#define XSPI_MCR_SWRSTHD_SHIFT                   (1U)
#define XSPI_MCR_SWRSTHD_WIDTH                   (1U)
#define XSPI_MCR_SWRSTHD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_SWRSTHD_SHIFT)) & XSPI_MCR_SWRSTHD_MASK)

#define XSPI_MCR_DQS_OUT_EN_MASK                 (0x10U)
#define XSPI_MCR_DQS_OUT_EN_SHIFT                (4U)
#define XSPI_MCR_DQS_OUT_EN_WIDTH                (1U)
#define XSPI_MCR_DQS_OUT_EN(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_DQS_OUT_EN_SHIFT)) & XSPI_MCR_DQS_OUT_EN_MASK)

#define XSPI_MCR_DQS_EN_MASK                     (0x40U)
#define XSPI_MCR_DQS_EN_SHIFT                    (6U)
#define XSPI_MCR_DQS_EN_WIDTH                    (1U)
#define XSPI_MCR_DQS_EN(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_DQS_EN_SHIFT)) & XSPI_MCR_DQS_EN_MASK)

#define XSPI_MCR_DDR_EN_MASK                     (0x80U)
#define XSPI_MCR_DDR_EN_SHIFT                    (7U)
#define XSPI_MCR_DDR_EN_WIDTH                    (1U)
#define XSPI_MCR_DDR_EN(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_DDR_EN_SHIFT)) & XSPI_MCR_DDR_EN_MASK)

#define XSPI_MCR_VAR_LAT_EN_MASK                 (0x100U)
#define XSPI_MCR_VAR_LAT_EN_SHIFT                (8U)
#define XSPI_MCR_VAR_LAT_EN_WIDTH                (1U)
#define XSPI_MCR_VAR_LAT_EN(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_VAR_LAT_EN_SHIFT)) & XSPI_MCR_VAR_LAT_EN_MASK)

#define XSPI_MCR_IPS_TG_RST_MASK                 (0x200U)
#define XSPI_MCR_IPS_TG_RST_SHIFT                (9U)
#define XSPI_MCR_IPS_TG_RST_WIDTH                (1U)
#define XSPI_MCR_IPS_TG_RST(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_IPS_TG_RST_SHIFT)) & XSPI_MCR_IPS_TG_RST_MASK)

#define XSPI_MCR_CLR_RXF_MASK                    (0x400U)
#define XSPI_MCR_CLR_RXF_SHIFT                   (10U)
#define XSPI_MCR_CLR_RXF_WIDTH                   (1U)
#define XSPI_MCR_CLR_RXF(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_CLR_RXF_SHIFT)) & XSPI_MCR_CLR_RXF_MASK)

#define XSPI_MCR_CLR_TXF_MASK                    (0x800U)
#define XSPI_MCR_CLR_TXF_SHIFT                   (11U)
#define XSPI_MCR_CLR_TXF_WIDTH                   (1U)
#define XSPI_MCR_CLR_TXF(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_CLR_TXF_SHIFT)) & XSPI_MCR_CLR_TXF_MASK)

#define XSPI_MCR_DLPEN_MASK                      (0x1000U)
#define XSPI_MCR_DLPEN_SHIFT                     (12U)
#define XSPI_MCR_DLPEN_WIDTH                     (1U)
#define XSPI_MCR_DLPEN(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_DLPEN_SHIFT)) & XSPI_MCR_DLPEN_MASK)

#define XSPI_MCR_MDIS_MASK                       (0x4000U)
#define XSPI_MCR_MDIS_SHIFT                      (14U)
#define XSPI_MCR_MDIS_WIDTH                      (1U)
#define XSPI_MCR_MDIS(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_MDIS_SHIFT)) & XSPI_MCR_MDIS_MASK)

#define XSPI_MCR_ISD2FA_MASK                     (0x10000U)
#define XSPI_MCR_ISD2FA_SHIFT                    (16U)
#define XSPI_MCR_ISD2FA_WIDTH                    (1U)
#define XSPI_MCR_ISD2FA(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_ISD2FA_SHIFT)) & XSPI_MCR_ISD2FA_MASK)

#define XSPI_MCR_ISD3FA_MASK                     (0x20000U)
#define XSPI_MCR_ISD3FA_SHIFT                    (17U)
#define XSPI_MCR_ISD3FA_WIDTH                    (1U)
#define XSPI_MCR_ISD3FA(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_ISD3FA_SHIFT)) & XSPI_MCR_ISD3FA_MASK)

#define XSPI_MCR_DQS_FA_SEL_MASK                 (0x3000000U)
#define XSPI_MCR_DQS_FA_SEL_SHIFT                (24U)
#define XSPI_MCR_DQS_FA_SEL_WIDTH                (2U)
#define XSPI_MCR_DQS_FA_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_DQS_FA_SEL_SHIFT)) & XSPI_MCR_DQS_FA_SEL_MASK)

#define XSPI_MCR_CKN_FA_EN_MASK                  (0x4000000U)
#define XSPI_MCR_CKN_FA_EN_SHIFT                 (26U)
#define XSPI_MCR_CKN_FA_EN_WIDTH                 (1U)
#define XSPI_MCR_CKN_FA_EN(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_CKN_FA_EN_SHIFT)) & XSPI_MCR_CKN_FA_EN_MASK)
/*! @} */

/*! @name IPCR - IP Configuration */
/*! @{ */

#define XSPI_IPCR_IDATSZ_MASK                    (0xFFFFU)
#define XSPI_IPCR_IDATSZ_SHIFT                   (0U)
#define XSPI_IPCR_IDATSZ_WIDTH                   (16U)
#define XSPI_IPCR_IDATSZ(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_IPCR_IDATSZ_SHIFT)) & XSPI_IPCR_IDATSZ_MASK)

#define XSPI_IPCR_SEQID_MASK                     (0xF000000U)
#define XSPI_IPCR_SEQID_SHIFT                    (24U)
#define XSPI_IPCR_SEQID_WIDTH                    (4U)
#define XSPI_IPCR_SEQID(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_IPCR_SEQID_SHIFT)) & XSPI_IPCR_SEQID_MASK)
/*! @} */

/*! @name FLSHCR - Flash Memory Configuration */
/*! @{ */

#define XSPI_FLSHCR_TCSS_MASK                    (0xFU)
#define XSPI_FLSHCR_TCSS_SHIFT                   (0U)
#define XSPI_FLSHCR_TCSS_WIDTH                   (4U)
#define XSPI_FLSHCR_TCSS(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FLSHCR_TCSS_SHIFT)) & XSPI_FLSHCR_TCSS_MASK)

#define XSPI_FLSHCR_TCSH_MASK                    (0xF00U)
#define XSPI_FLSHCR_TCSH_SHIFT                   (8U)
#define XSPI_FLSHCR_TCSH_WIDTH                   (4U)
#define XSPI_FLSHCR_TCSH(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FLSHCR_TCSH_SHIFT)) & XSPI_FLSHCR_TCSH_MASK)

#define XSPI_FLSHCR_TDH_MASK                     (0x30000U)
#define XSPI_FLSHCR_TDH_SHIFT                    (16U)
#define XSPI_FLSHCR_TDH_WIDTH                    (2U)
#define XSPI_FLSHCR_TDH(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_FLSHCR_TDH_SHIFT)) & XSPI_FLSHCR_TDH_MASK)
/*! @} */

/*! @name BUF0CR - Buffer Configuration */
/*! @{ */

#define XSPI_BUF0CR_MSTRID_MASK                  (0x3FU)
#define XSPI_BUF0CR_MSTRID_SHIFT                 (0U)
#define XSPI_BUF0CR_MSTRID_WIDTH                 (6U)
#define XSPI_BUF0CR_MSTRID(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BUF0CR_MSTRID_SHIFT)) & XSPI_BUF0CR_MSTRID_MASK)

#define XSPI_BUF0CR_ADATSZ_MASK                  (0x3FF00U)
#define XSPI_BUF0CR_ADATSZ_SHIFT                 (8U)
#define XSPI_BUF0CR_ADATSZ_WIDTH                 (10U)
#define XSPI_BUF0CR_ADATSZ(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BUF0CR_ADATSZ_SHIFT)) & XSPI_BUF0CR_ADATSZ_MASK)

#define XSPI_BUF0CR_SUBBUF0_DIV_MASK             (0xE00000U)
#define XSPI_BUF0CR_SUBBUF0_DIV_SHIFT            (21U)
#define XSPI_BUF0CR_SUBBUF0_DIV_WIDTH            (3U)
#define XSPI_BUF0CR_SUBBUF0_DIV(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_BUF0CR_SUBBUF0_DIV_SHIFT)) & XSPI_BUF0CR_SUBBUF0_DIV_MASK)

#define XSPI_BUF0CR_SUBBUF1_DIV_MASK             (0x7000000U)
#define XSPI_BUF0CR_SUBBUF1_DIV_SHIFT            (24U)
#define XSPI_BUF0CR_SUBBUF1_DIV_WIDTH            (3U)
#define XSPI_BUF0CR_SUBBUF1_DIV(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_BUF0CR_SUBBUF1_DIV_SHIFT)) & XSPI_BUF0CR_SUBBUF1_DIV_MASK)

#define XSPI_BUF0CR_SUBBUF2_DIV_MASK             (0x38000000U)
#define XSPI_BUF0CR_SUBBUF2_DIV_SHIFT            (27U)
#define XSPI_BUF0CR_SUBBUF2_DIV_WIDTH            (3U)
#define XSPI_BUF0CR_SUBBUF2_DIV(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_BUF0CR_SUBBUF2_DIV_SHIFT)) & XSPI_BUF0CR_SUBBUF2_DIV_MASK)

#define XSPI_BUF0CR_SUB_DIV_EN_MASK              (0x40000000U)
#define XSPI_BUF0CR_SUB_DIV_EN_SHIFT             (30U)
#define XSPI_BUF0CR_SUB_DIV_EN_WIDTH             (1U)
#define XSPI_BUF0CR_SUB_DIV_EN(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_BUF0CR_SUB_DIV_EN_SHIFT)) & XSPI_BUF0CR_SUB_DIV_EN_MASK)

#define XSPI_BUF0CR_HP_EN_MASK                   (0x80000000U)
#define XSPI_BUF0CR_HP_EN_SHIFT                  (31U)
#define XSPI_BUF0CR_HP_EN_WIDTH                  (1U)
#define XSPI_BUF0CR_HP_EN(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_BUF0CR_HP_EN_SHIFT)) & XSPI_BUF0CR_HP_EN_MASK)
/*! @} */

/*! @name BUF1CR - Buffer Configuration */
/*! @{ */

#define XSPI_BUF1CR_MSTRID_MASK                  (0x3FU)
#define XSPI_BUF1CR_MSTRID_SHIFT                 (0U)
#define XSPI_BUF1CR_MSTRID_WIDTH                 (6U)
#define XSPI_BUF1CR_MSTRID(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BUF1CR_MSTRID_SHIFT)) & XSPI_BUF1CR_MSTRID_MASK)

#define XSPI_BUF1CR_ADATSZ_MASK                  (0x3FF00U)
#define XSPI_BUF1CR_ADATSZ_SHIFT                 (8U)
#define XSPI_BUF1CR_ADATSZ_WIDTH                 (10U)
#define XSPI_BUF1CR_ADATSZ(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BUF1CR_ADATSZ_SHIFT)) & XSPI_BUF1CR_ADATSZ_MASK)

#define XSPI_BUF1CR_SUBBUF0_DIV_MASK             (0xE00000U)
#define XSPI_BUF1CR_SUBBUF0_DIV_SHIFT            (21U)
#define XSPI_BUF1CR_SUBBUF0_DIV_WIDTH            (3U)
#define XSPI_BUF1CR_SUBBUF0_DIV(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_BUF1CR_SUBBUF0_DIV_SHIFT)) & XSPI_BUF1CR_SUBBUF0_DIV_MASK)

#define XSPI_BUF1CR_SUBBUF1_DIV_MASK             (0x7000000U)
#define XSPI_BUF1CR_SUBBUF1_DIV_SHIFT            (24U)
#define XSPI_BUF1CR_SUBBUF1_DIV_WIDTH            (3U)
#define XSPI_BUF1CR_SUBBUF1_DIV(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_BUF1CR_SUBBUF1_DIV_SHIFT)) & XSPI_BUF1CR_SUBBUF1_DIV_MASK)

#define XSPI_BUF1CR_SUBBUF2_DIV_MASK             (0x38000000U)
#define XSPI_BUF1CR_SUBBUF2_DIV_SHIFT            (27U)
#define XSPI_BUF1CR_SUBBUF2_DIV_WIDTH            (3U)
#define XSPI_BUF1CR_SUBBUF2_DIV(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_BUF1CR_SUBBUF2_DIV_SHIFT)) & XSPI_BUF1CR_SUBBUF2_DIV_MASK)

#define XSPI_BUF1CR_SUB_DIV_EN_MASK              (0x40000000U)
#define XSPI_BUF1CR_SUB_DIV_EN_SHIFT             (30U)
#define XSPI_BUF1CR_SUB_DIV_EN_WIDTH             (1U)
#define XSPI_BUF1CR_SUB_DIV_EN(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_BUF1CR_SUB_DIV_EN_SHIFT)) & XSPI_BUF1CR_SUB_DIV_EN_MASK)

#define XSPI_BUF1CR_HP_EN_MASK                   (0x80000000U)
#define XSPI_BUF1CR_HP_EN_SHIFT                  (31U)
#define XSPI_BUF1CR_HP_EN_WIDTH                  (1U)
#define XSPI_BUF1CR_HP_EN(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_BUF1CR_HP_EN_SHIFT)) & XSPI_BUF1CR_HP_EN_MASK)
/*! @} */

/*! @name BUF2CR - Buffer Configuration */
/*! @{ */

#define XSPI_BUF2CR_MSTRID_MASK                  (0x3FU)
#define XSPI_BUF2CR_MSTRID_SHIFT                 (0U)
#define XSPI_BUF2CR_MSTRID_WIDTH                 (6U)
#define XSPI_BUF2CR_MSTRID(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BUF2CR_MSTRID_SHIFT)) & XSPI_BUF2CR_MSTRID_MASK)

#define XSPI_BUF2CR_ADATSZ_MASK                  (0x3FF00U)
#define XSPI_BUF2CR_ADATSZ_SHIFT                 (8U)
#define XSPI_BUF2CR_ADATSZ_WIDTH                 (10U)
#define XSPI_BUF2CR_ADATSZ(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BUF2CR_ADATSZ_SHIFT)) & XSPI_BUF2CR_ADATSZ_MASK)

#define XSPI_BUF2CR_SUBBUF0_DIV_MASK             (0xE00000U)
#define XSPI_BUF2CR_SUBBUF0_DIV_SHIFT            (21U)
#define XSPI_BUF2CR_SUBBUF0_DIV_WIDTH            (3U)
#define XSPI_BUF2CR_SUBBUF0_DIV(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_BUF2CR_SUBBUF0_DIV_SHIFT)) & XSPI_BUF2CR_SUBBUF0_DIV_MASK)

#define XSPI_BUF2CR_SUBBUF1_DIV_MASK             (0x7000000U)
#define XSPI_BUF2CR_SUBBUF1_DIV_SHIFT            (24U)
#define XSPI_BUF2CR_SUBBUF1_DIV_WIDTH            (3U)
#define XSPI_BUF2CR_SUBBUF1_DIV(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_BUF2CR_SUBBUF1_DIV_SHIFT)) & XSPI_BUF2CR_SUBBUF1_DIV_MASK)

#define XSPI_BUF2CR_SUBBUF2_DIV_MASK             (0x38000000U)
#define XSPI_BUF2CR_SUBBUF2_DIV_SHIFT            (27U)
#define XSPI_BUF2CR_SUBBUF2_DIV_WIDTH            (3U)
#define XSPI_BUF2CR_SUBBUF2_DIV(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_BUF2CR_SUBBUF2_DIV_SHIFT)) & XSPI_BUF2CR_SUBBUF2_DIV_MASK)

#define XSPI_BUF2CR_SUB_DIV_EN_MASK              (0x40000000U)
#define XSPI_BUF2CR_SUB_DIV_EN_SHIFT             (30U)
#define XSPI_BUF2CR_SUB_DIV_EN_WIDTH             (1U)
#define XSPI_BUF2CR_SUB_DIV_EN(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_BUF2CR_SUB_DIV_EN_SHIFT)) & XSPI_BUF2CR_SUB_DIV_EN_MASK)
/*! @} */

/*! @name BUF3CR - Buffer Configuration */
/*! @{ */

#define XSPI_BUF3CR_MSTRID_MASK                  (0x3FU)
#define XSPI_BUF3CR_MSTRID_SHIFT                 (0U)
#define XSPI_BUF3CR_MSTRID_WIDTH                 (6U)
#define XSPI_BUF3CR_MSTRID(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BUF3CR_MSTRID_SHIFT)) & XSPI_BUF3CR_MSTRID_MASK)

#define XSPI_BUF3CR_ADATSZ_MASK                  (0x3FF00U)
#define XSPI_BUF3CR_ADATSZ_SHIFT                 (8U)
#define XSPI_BUF3CR_ADATSZ_WIDTH                 (10U)
#define XSPI_BUF3CR_ADATSZ(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BUF3CR_ADATSZ_SHIFT)) & XSPI_BUF3CR_ADATSZ_MASK)

#define XSPI_BUF3CR_SUBBUF0_DIV_MASK             (0xE00000U)
#define XSPI_BUF3CR_SUBBUF0_DIV_SHIFT            (21U)
#define XSPI_BUF3CR_SUBBUF0_DIV_WIDTH            (3U)
#define XSPI_BUF3CR_SUBBUF0_DIV(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_BUF3CR_SUBBUF0_DIV_SHIFT)) & XSPI_BUF3CR_SUBBUF0_DIV_MASK)

#define XSPI_BUF3CR_SUBBUF1_DIV_MASK             (0x7000000U)
#define XSPI_BUF3CR_SUBBUF1_DIV_SHIFT            (24U)
#define XSPI_BUF3CR_SUBBUF1_DIV_WIDTH            (3U)
#define XSPI_BUF3CR_SUBBUF1_DIV(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_BUF3CR_SUBBUF1_DIV_SHIFT)) & XSPI_BUF3CR_SUBBUF1_DIV_MASK)

#define XSPI_BUF3CR_SUBBUF2_DIV_MASK             (0x38000000U)
#define XSPI_BUF3CR_SUBBUF2_DIV_SHIFT            (27U)
#define XSPI_BUF3CR_SUBBUF2_DIV_WIDTH            (3U)
#define XSPI_BUF3CR_SUBBUF2_DIV(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_BUF3CR_SUBBUF2_DIV_SHIFT)) & XSPI_BUF3CR_SUBBUF2_DIV_MASK)

#define XSPI_BUF3CR_SUB_DIV_EN_MASK              (0x40000000U)
#define XSPI_BUF3CR_SUB_DIV_EN_SHIFT             (30U)
#define XSPI_BUF3CR_SUB_DIV_EN_WIDTH             (1U)
#define XSPI_BUF3CR_SUB_DIV_EN(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_BUF3CR_SUB_DIV_EN_SHIFT)) & XSPI_BUF3CR_SUB_DIV_EN_MASK)

#define XSPI_BUF3CR_ALLMST_MASK                  (0x80000000U)
#define XSPI_BUF3CR_ALLMST_SHIFT                 (31U)
#define XSPI_BUF3CR_ALLMST_WIDTH                 (1U)
#define XSPI_BUF3CR_ALLMST(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BUF3CR_ALLMST_SHIFT)) & XSPI_BUF3CR_ALLMST_MASK)
/*! @} */

/*! @name BFGENCR - Buffer Generic Configuration */
/*! @{ */

#define XSPI_BFGENCR_SEQID_RDSR_MASK             (0xFU)
#define XSPI_BFGENCR_SEQID_RDSR_SHIFT            (0U)
#define XSPI_BFGENCR_SEQID_RDSR_WIDTH            (4U)
#define XSPI_BFGENCR_SEQID_RDSR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_SEQID_RDSR_SHIFT)) & XSPI_BFGENCR_SEQID_RDSR_MASK)

#define XSPI_BFGENCR_WRTER_EN_MASK               (0x10U)
#define XSPI_BFGENCR_WRTER_EN_SHIFT              (4U)
#define XSPI_BFGENCR_WRTER_EN_WIDTH              (1U)
#define XSPI_BFGENCR_WRTER_EN(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_WRTER_EN_SHIFT)) & XSPI_BFGENCR_WRTER_EN_MASK)

#define XSPI_BFGENCR_SPLITEN_MASK                (0x100U)
#define XSPI_BFGENCR_SPLITEN_SHIFT               (8U)
#define XSPI_BFGENCR_SPLITEN_WIDTH               (1U)
#define XSPI_BFGENCR_SPLITEN(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_SPLITEN_SHIFT)) & XSPI_BFGENCR_SPLITEN_MASK)

#define XSPI_BFGENCR_AHBSSIZE_MASK               (0x600U)
#define XSPI_BFGENCR_AHBSSIZE_SHIFT              (9U)
#define XSPI_BFGENCR_AHBSSIZE_WIDTH              (2U)
#define XSPI_BFGENCR_AHBSSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_AHBSSIZE_SHIFT)) & XSPI_BFGENCR_AHBSSIZE_MASK)

#define XSPI_BFGENCR_FLSHINTP_MASK               (0x800U)
#define XSPI_BFGENCR_FLSHINTP_SHIFT              (11U)
#define XSPI_BFGENCR_FLSHINTP_WIDTH              (1U)
#define XSPI_BFGENCR_FLSHINTP(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_FLSHINTP_SHIFT)) & XSPI_BFGENCR_FLSHINTP_MASK)

#define XSPI_BFGENCR_SEQID_MASK                  (0xF000U)
#define XSPI_BFGENCR_SEQID_SHIFT                 (12U)
#define XSPI_BFGENCR_SEQID_WIDTH                 (4U)
#define XSPI_BFGENCR_SEQID(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_SEQID_SHIFT)) & XSPI_BFGENCR_SEQID_MASK)

#define XSPI_BFGENCR_SEQID_WR_EN_MASK            (0x20000U)
#define XSPI_BFGENCR_SEQID_WR_EN_SHIFT           (17U)
#define XSPI_BFGENCR_SEQID_WR_EN_WIDTH           (1U)
#define XSPI_BFGENCR_SEQID_WR_EN(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_SEQID_WR_EN_SHIFT)) & XSPI_BFGENCR_SEQID_WR_EN_MASK)

#define XSPI_BFGENCR_PPWF_CLR_MASK               (0x100000U)
#define XSPI_BFGENCR_PPWF_CLR_SHIFT              (20U)
#define XSPI_BFGENCR_PPWF_CLR_WIDTH              (1U)
#define XSPI_BFGENCR_PPWF_CLR(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_PPWF_CLR_SHIFT)) & XSPI_BFGENCR_PPWF_CLR_MASK)

#define XSPI_BFGENCR_WR_FLUSH_EN_MASK            (0x200000U)
#define XSPI_BFGENCR_WR_FLUSH_EN_SHIFT           (21U)
#define XSPI_BFGENCR_WR_FLUSH_EN_WIDTH           (1U)
#define XSPI_BFGENCR_WR_FLUSH_EN(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_WR_FLUSH_EN_SHIFT)) & XSPI_BFGENCR_WR_FLUSH_EN_MASK)

#define XSPI_BFGENCR_ALIGN_MASK                  (0x1C00000U)
#define XSPI_BFGENCR_ALIGN_SHIFT                 (22U)
#define XSPI_BFGENCR_ALIGN_WIDTH                 (3U)
#define XSPI_BFGENCR_ALIGN(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_ALIGN_SHIFT)) & XSPI_BFGENCR_ALIGN_MASK)

#define XSPI_BFGENCR_SEQID_WR_MASK               (0xF0000000U)
#define XSPI_BFGENCR_SEQID_WR_SHIFT              (28U)
#define XSPI_BFGENCR_SEQID_WR_WIDTH              (4U)
#define XSPI_BFGENCR_SEQID_WR(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_SEQID_WR_SHIFT)) & XSPI_BFGENCR_SEQID_WR_MASK)
/*! @} */

/*! @name SOCCR - SOC Configuration */
/*! @{ */

#define XSPI_SOCCR_SOCCFG_MASK                   (0xFFFFFFU)
#define XSPI_SOCCR_SOCCFG_SHIFT                  (0U)
#define XSPI_SOCCR_SOCCFG_WIDTH                  (24U)
#define XSPI_SOCCR_SOCCFG(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_SOCCR_SOCCFG_SHIFT)) & XSPI_SOCCR_SOCCFG_MASK)

#define XSPI_SOCCR_MASK_ECC_MASK                 (0x2000000U)
#define XSPI_SOCCR_MASK_ECC_SHIFT                (25U)
#define XSPI_SOCCR_MASK_ECC_WIDTH                (1U)
#define XSPI_SOCCR_MASK_ECC(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SOCCR_MASK_ECC_SHIFT)) & XSPI_SOCCR_MASK_ECC_MASK)

#define XSPI_SOCCR_OBE_MASK_EN_MASK              (0x4000000U)
#define XSPI_SOCCR_OBE_MASK_EN_SHIFT             (26U)
#define XSPI_SOCCR_OBE_MASK_EN_WIDTH             (1U)
#define XSPI_SOCCR_OBE_MASK_EN(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_SOCCR_OBE_MASK_EN_SHIFT)) & XSPI_SOCCR_OBE_MASK_EN_MASK)

#define XSPI_SOCCR_HRESP_ERR_MASK_MASK           (0x8000000U)
#define XSPI_SOCCR_HRESP_ERR_MASK_SHIFT          (27U)
#define XSPI_SOCCR_HRESP_ERR_MASK_WIDTH          (1U)
#define XSPI_SOCCR_HRESP_ERR_MASK(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_SOCCR_HRESP_ERR_MASK_SHIFT)) & XSPI_SOCCR_HRESP_ERR_MASK_MASK)

#define XSPI_SOCCR_ENA_DLLABRT_MASK              (0x10000000U)
#define XSPI_SOCCR_ENA_DLLABRT_SHIFT             (28U)
#define XSPI_SOCCR_ENA_DLLABRT_WIDTH             (1U)
#define XSPI_SOCCR_ENA_DLLABRT(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_SOCCR_ENA_DLLABRT_SHIFT)) & XSPI_SOCCR_ENA_DLLABRT_MASK)
/*! @} */

/*! @name BUFIND - Buffer 0 Top Index..Buffer 2 Top Index */
/*! @{ */

#define XSPI_BUFIND_TPINDX_MASK                  (0x1FF8U)
#define XSPI_BUFIND_TPINDX_SHIFT                 (3U)
#define XSPI_BUFIND_TPINDX_WIDTH                 (10U)
#define XSPI_BUFIND_TPINDX(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BUFIND_TPINDX_SHIFT)) & XSPI_BUFIND_TPINDX_MASK)
/*! @} */

/*! @name PRW_RDSR - Page Read Wait Status */
/*! @{ */

#define XSPI_PRW_RDSR_RDSR_MASK                  (0xFFFFU)
#define XSPI_PRW_RDSR_RDSR_SHIFT                 (0U)
#define XSPI_PRW_RDSR_RDSR_WIDTH                 (16U)
#define XSPI_PRW_RDSR_RDSR(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_PRW_RDSR_RDSR_SHIFT)) & XSPI_PRW_RDSR_RDSR_MASK)

#define XSPI_PRW_RDSR_RDSRWSEL_MASK              (0x200000U)
#define XSPI_PRW_RDSR_RDSRWSEL_SHIFT             (21U)
#define XSPI_PRW_RDSR_RDSRWSEL_WIDTH             (1U)
#define XSPI_PRW_RDSR_RDSRWSEL(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_PRW_RDSR_RDSRWSEL_SHIFT)) & XSPI_PRW_RDSR_RDSRWSEL_MASK)

#define XSPI_PRW_RDSR_RDSRVCHK_MASK              (0x400000U)
#define XSPI_PRW_RDSR_RDSRVCHK_SHIFT             (22U)
#define XSPI_PRW_RDSR_RDSRVCHK_WIDTH             (1U)
#define XSPI_PRW_RDSR_RDSRVCHK(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_PRW_RDSR_RDSRVCHK_SHIFT)) & XSPI_PRW_RDSR_RDSRVCHK_MASK)

#define XSPI_PRW_RDSR_RDSR_HWS_MASK              (0x800000U)
#define XSPI_PRW_RDSR_RDSR_HWS_SHIFT             (23U)
#define XSPI_PRW_RDSR_RDSR_HWS_WIDTH             (1U)
#define XSPI_PRW_RDSR_RDSR_HWS(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_PRW_RDSR_RDSR_HWS_SHIFT)) & XSPI_PRW_RDSR_RDSR_HWS_MASK)

#define XSPI_PRW_RDSR_LOC_MASK                   (0xF000000U)
#define XSPI_PRW_RDSR_LOC_SHIFT                  (24U)
#define XSPI_PRW_RDSR_LOC_WIDTH                  (4U)
#define XSPI_PRW_RDSR_LOC(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_PRW_RDSR_LOC_SHIFT)) & XSPI_PRW_RDSR_LOC_MASK)

#define XSPI_PRW_RDSR_VALID_MASK                 (0x80000000U)
#define XSPI_PRW_RDSR_VALID_SHIFT                (31U)
#define XSPI_PRW_RDSR_VALID_WIDTH                (1U)
#define XSPI_PRW_RDSR_VALID(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_PRW_RDSR_VALID_SHIFT)) & XSPI_PRW_RDSR_VALID_MASK)
/*! @} */

/*! @name AWRCR - AHB Write Configuration */
/*! @{ */

#define XSPI_AWRCR_PPW_RD_DIS_MASK               (0x4000U)
#define XSPI_AWRCR_PPW_RD_DIS_SHIFT              (14U)
#define XSPI_AWRCR_PPW_RD_DIS_WIDTH              (1U)
#define XSPI_AWRCR_PPW_RD_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_AWRCR_PPW_RD_DIS_SHIFT)) & XSPI_AWRCR_PPW_RD_DIS_MASK)

#define XSPI_AWRCR_PPW_WR_DIS_MASK               (0x8000U)
#define XSPI_AWRCR_PPW_WR_DIS_SHIFT              (15U)
#define XSPI_AWRCR_PPW_WR_DIS_WIDTH              (1U)
#define XSPI_AWRCR_PPW_WR_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_AWRCR_PPW_WR_DIS_SHIFT)) & XSPI_AWRCR_PPW_WR_DIS_MASK)

#define XSPI_AWRCR_L2WSEQID_MASK                 (0xF00000U)
#define XSPI_AWRCR_L2WSEQID_SHIFT                (20U)
#define XSPI_AWRCR_L2WSEQID_WIDTH                (4U)
#define XSPI_AWRCR_L2WSEQID(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_AWRCR_L2WSEQID_SHIFT)) & XSPI_AWRCR_L2WSEQID_MASK)
/*! @} */

/*! @name ARDCR - AHB Read Configuration */
/*! @{ */

#define XSPI_ARDCR_SNAND_RD_MASK                 (0x3U)
#define XSPI_ARDCR_SNAND_RD_SHIFT                (0U)
#define XSPI_ARDCR_SNAND_RD_WIDTH                (2U)
#define XSPI_ARDCR_SNAND_RD(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_ARDCR_SNAND_RD_SHIFT)) & XSPI_ARDCR_SNAND_RD_MASK)

#define XSPI_ARDCR_SNANDEXT_MASK                 (0x4U)
#define XSPI_ARDCR_SNANDEXT_SHIFT                (2U)
#define XSPI_ARDCR_SNANDEXT_WIDTH                (1U)
#define XSPI_ARDCR_SNANDEXT(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_ARDCR_SNANDEXT_SHIFT)) & XSPI_ARDCR_SNANDEXT_MASK)

#define XSPI_ARDCR_L2_SEQID_MASK                 (0xF0U)
#define XSPI_ARDCR_L2_SEQID_SHIFT                (4U)
#define XSPI_ARDCR_L2_SEQID_WIDTH                (4U)
#define XSPI_ARDCR_L2_SEQID(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_ARDCR_L2_SEQID_SHIFT)) & XSPI_ARDCR_L2_SEQID_MASK)

#define XSPI_ARDCR_RDSR_ID_MASK                  (0xF000U)
#define XSPI_ARDCR_RDSR_ID_SHIFT                 (12U)
#define XSPI_ARDCR_RDSR_ID_WIDTH                 (4U)
#define XSPI_ARDCR_RDSR_ID(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_ARDCR_RDSR_ID_SHIFT)) & XSPI_ARDCR_RDSR_ID_MASK)

#define XSPI_ARDCR_SNANDRAS_MASK                 (0x3E0000U)
#define XSPI_ARDCR_SNANDRAS_SHIFT                (17U)
#define XSPI_ARDCR_SNANDRAS_WIDTH                (5U)
#define XSPI_ARDCR_SNANDRAS(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_ARDCR_SNANDRAS_SHIFT)) & XSPI_ARDCR_SNANDRAS_MASK)
/*! @} */

/*! @name AWITO - AHB Write Idle Timeout Configuration */
/*! @{ */

#define XSPI_AWITO_AWITOVAL_MASK                 (0x7FFFFFFFU)
#define XSPI_AWITO_AWITOVAL_SHIFT                (0U)
#define XSPI_AWITO_AWITOVAL_WIDTH                (31U)
#define XSPI_AWITO_AWITOVAL(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_AWITO_AWITOVAL_SHIFT)) & XSPI_AWITO_AWITOVAL_MASK)

#define XSPI_AWITO_AWICNTEN_MASK                 (0x80000000U)
#define XSPI_AWITO_AWICNTEN_SHIFT                (31U)
#define XSPI_AWITO_AWICNTEN_WIDTH                (1U)
#define XSPI_AWITO_AWICNTEN(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_AWITO_AWICNTEN_SHIFT)) & XSPI_AWITO_AWICNTEN_MASK)
/*! @} */

/*! @name FSR_ADDR - Flash Status Register Address */
/*! @{ */

#define XSPI_FSR_ADDR_ADDR_MASK                  (0xFFFFU)
#define XSPI_FSR_ADDR_ADDR_SHIFT                 (0U)
#define XSPI_FSR_ADDR_ADDR_WIDTH                 (16U)
#define XSPI_FSR_ADDR_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_FSR_ADDR_ADDR_SHIFT)) & XSPI_FSR_ADDR_ADDR_MASK)
/*! @} */

/*! @name DLLCR - DLL Flash Memory A Configuration */
/*! @{ */

#define XSPI_DLLCR_SLV_UPD_MASK                  (0x1U)
#define XSPI_DLLCR_SLV_UPD_SHIFT                 (0U)
#define XSPI_DLLCR_SLV_UPD_WIDTH                 (1U)
#define XSPI_DLLCR_SLV_UPD(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLV_UPD_SHIFT)) & XSPI_DLLCR_SLV_UPD_MASK)

#define XSPI_DLLCR_SLV_DLL_BYPASS_MASK           (0x2U)
#define XSPI_DLLCR_SLV_DLL_BYPASS_SHIFT          (1U)
#define XSPI_DLLCR_SLV_DLL_BYPASS_WIDTH          (1U)
#define XSPI_DLLCR_SLV_DLL_BYPASS(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLV_DLL_BYPASS_SHIFT)) & XSPI_DLLCR_SLV_DLL_BYPASS_MASK)

#define XSPI_DLLCR_SLV_EN_MASK                   (0x4U)
#define XSPI_DLLCR_SLV_EN_SHIFT                  (2U)
#define XSPI_DLLCR_SLV_EN_WIDTH                  (1U)
#define XSPI_DLLCR_SLV_EN(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLV_EN_SHIFT)) & XSPI_DLLCR_SLV_EN_MASK)

#define XSPI_DLLCR_SLAVE_AUTO_UPDT_MASK          (0x8U)
#define XSPI_DLLCR_SLAVE_AUTO_UPDT_SHIFT         (3U)
#define XSPI_DLLCR_SLAVE_AUTO_UPDT_WIDTH         (1U)
#define XSPI_DLLCR_SLAVE_AUTO_UPDT(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLAVE_AUTO_UPDT_SHIFT)) & XSPI_DLLCR_SLAVE_AUTO_UPDT_MASK)

#define XSPI_DLLCR_DLL_CDL8_MASK                 (0x10U)
#define XSPI_DLLCR_DLL_CDL8_SHIFT                (4U)
#define XSPI_DLLCR_DLL_CDL8_WIDTH                (1U)
#define XSPI_DLLCR_DLL_CDL8(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_DLL_CDL8_SHIFT)) & XSPI_DLLCR_DLL_CDL8_MASK)

#define XSPI_DLLCR_SLV_DLY_FINE_MASK             (0xE0U)
#define XSPI_DLLCR_SLV_DLY_FINE_SHIFT            (5U)
#define XSPI_DLLCR_SLV_DLY_FINE_WIDTH            (3U)
#define XSPI_DLLCR_SLV_DLY_FINE(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLV_DLY_FINE_SHIFT)) & XSPI_DLLCR_SLV_DLY_FINE_MASK)

#define XSPI_DLLCR_SLV_DLY_COARSE_MASK           (0xF00U)
#define XSPI_DLLCR_SLV_DLY_COARSE_SHIFT          (8U)
#define XSPI_DLLCR_SLV_DLY_COARSE_WIDTH          (4U)
#define XSPI_DLLCR_SLV_DLY_COARSE(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLV_DLY_COARSE_SHIFT)) & XSPI_DLLCR_SLV_DLY_COARSE_MASK)

#define XSPI_DLLCR_SLV_DLY_OFFSET_MASK           (0x7000U)
#define XSPI_DLLCR_SLV_DLY_OFFSET_SHIFT          (12U)
#define XSPI_DLLCR_SLV_DLY_OFFSET_WIDTH          (3U)
#define XSPI_DLLCR_SLV_DLY_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLV_DLY_OFFSET_SHIFT)) & XSPI_DLLCR_SLV_DLY_OFFSET_MASK)

#define XSPI_DLLCR_SLV_FINE_OFFSET_MASK          (0xF0000U)
#define XSPI_DLLCR_SLV_FINE_OFFSET_SHIFT         (16U)
#define XSPI_DLLCR_SLV_FINE_OFFSET_WIDTH         (4U)
#define XSPI_DLLCR_SLV_FINE_OFFSET(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLV_FINE_OFFSET_SHIFT)) & XSPI_DLLCR_SLV_FINE_OFFSET_MASK)

#define XSPI_DLLCR_DLLRES_MASK                   (0xF00000U)
#define XSPI_DLLCR_DLLRES_SHIFT                  (20U)
#define XSPI_DLLCR_DLLRES_WIDTH                  (4U)
#define XSPI_DLLCR_DLLRES(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_DLLRES_SHIFT)) & XSPI_DLLCR_DLLRES_MASK)

#define XSPI_DLLCR_DLL_REFCNTR_MASK              (0xF000000U)
#define XSPI_DLLCR_DLL_REFCNTR_SHIFT             (24U)
#define XSPI_DLLCR_DLL_REFCNTR_WIDTH             (4U)
#define XSPI_DLLCR_DLL_REFCNTR(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_DLL_REFCNTR_SHIFT)) & XSPI_DLLCR_DLL_REFCNTR_MASK)

#define XSPI_DLLCR_FREQEN_MASK                   (0x40000000U)
#define XSPI_DLLCR_FREQEN_SHIFT                  (30U)
#define XSPI_DLLCR_FREQEN_WIDTH                  (1U)
#define XSPI_DLLCR_FREQEN(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_FREQEN_SHIFT)) & XSPI_DLLCR_FREQEN_MASK)

#define XSPI_DLLCR_DLLEN_MASK                    (0x80000000U)
#define XSPI_DLLCR_DLLEN_SHIFT                   (31U)
#define XSPI_DLLCR_DLLEN_WIDTH                   (1U)
#define XSPI_DLLCR_DLLEN(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_DLLEN_SHIFT)) & XSPI_DLLCR_DLLEN_MASK)
/*! @} */

/*! @name PARITYCR - Parity Configuration */
/*! @{ */

#define XSPI_PARITYCR_CRCBIN_FA_MASK             (0x20U)
#define XSPI_PARITYCR_CRCBIN_FA_SHIFT            (5U)
#define XSPI_PARITYCR_CRCBIN_FA_WIDTH            (1U)
#define XSPI_PARITYCR_CRCBIN_FA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_PARITYCR_CRCBIN_FA_SHIFT)) & XSPI_PARITYCR_CRCBIN_FA_MASK)

#define XSPI_PARITYCR_CRCBEN_FA_MASK             (0x40U)
#define XSPI_PARITYCR_CRCBEN_FA_SHIFT            (6U)
#define XSPI_PARITYCR_CRCBEN_FA_WIDTH            (1U)
#define XSPI_PARITYCR_CRCBEN_FA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_PARITYCR_CRCBEN_FA_SHIFT)) & XSPI_PARITYCR_CRCBEN_FA_MASK)

#define XSPI_PARITYCR_CRCEN_FA_MASK              (0x80U)
#define XSPI_PARITYCR_CRCEN_FA_SHIFT             (7U)
#define XSPI_PARITYCR_CRCEN_FA_WIDTH             (1U)
#define XSPI_PARITYCR_CRCEN_FA(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_PARITYCR_CRCEN_FA_SHIFT)) & XSPI_PARITYCR_CRCEN_FA_MASK)

#define XSPI_PARITYCR_BYTE_SIZE_FA_MASK          (0x100U)
#define XSPI_PARITYCR_BYTE_SIZE_FA_SHIFT         (8U)
#define XSPI_PARITYCR_BYTE_SIZE_FA_WIDTH         (1U)
#define XSPI_PARITYCR_BYTE_SIZE_FA(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_PARITYCR_BYTE_SIZE_FA_SHIFT)) & XSPI_PARITYCR_BYTE_SIZE_FA_MASK)

#define XSPI_PARITYCR_CHUNKSIZE_FA_MASK          (0x7E00U)
#define XSPI_PARITYCR_CHUNKSIZE_FA_SHIFT         (9U)
#define XSPI_PARITYCR_CHUNKSIZE_FA_WIDTH         (6U)
#define XSPI_PARITYCR_CHUNKSIZE_FA(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_PARITYCR_CHUNKSIZE_FA_SHIFT)) & XSPI_PARITYCR_CHUNKSIZE_FA_MASK)

#define XSPI_PARITYCR_CRC_WNDW_FA_MASK           (0x8000U)
#define XSPI_PARITYCR_CRC_WNDW_FA_SHIFT          (15U)
#define XSPI_PARITYCR_CRC_WNDW_FA_WIDTH          (1U)
#define XSPI_PARITYCR_CRC_WNDW_FA(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_PARITYCR_CRC_WNDW_FA_SHIFT)) & XSPI_PARITYCR_CRC_WNDW_FA_MASK)
/*! @} */

/*! @name SFAR - Serial Flash Memory Address */
/*! @{ */

#define XSPI_SFAR_SFADR_MASK                     (0xFFFFFFFFU)
#define XSPI_SFAR_SFADR_SHIFT                    (0U)
#define XSPI_SFAR_SFADR_WIDTH                    (32U)
#define XSPI_SFAR_SFADR(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SFAR_SFADR_SHIFT)) & XSPI_SFAR_SFADR_MASK)
/*! @} */

/*! @name SFACR - Serial Flash Memory Address Configuration */
/*! @{ */

#define XSPI_SFACR_CAS_MASK                      (0xFU)
#define XSPI_SFACR_CAS_SHIFT                     (0U)
#define XSPI_SFACR_CAS_WIDTH                     (4U)
#define XSPI_SFACR_CAS(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_CAS_SHIFT)) & XSPI_SFACR_CAS_MASK)

#define XSPI_SFACR_PRWB_MASK                     (0xF0U)
#define XSPI_SFACR_PRWB_SHIFT                    (4U)
#define XSPI_SFACR_PRWB_WIDTH                    (4U)
#define XSPI_SFACR_PRWB(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_PRWB_SHIFT)) & XSPI_SFACR_PRWB_MASK)

#define XSPI_SFACR_PPWB_MASK                     (0x1F00U)
#define XSPI_SFACR_PPWB_SHIFT                    (8U)
#define XSPI_SFACR_PPWB_WIDTH                    (5U)
#define XSPI_SFACR_PPWB(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_PPWB_SHIFT)) & XSPI_SFACR_PPWB_MASK)

#define XSPI_SFACR_SIOCMDEN_MASK                 (0x4000U)
#define XSPI_SFACR_SIOCMDEN_SHIFT                (14U)
#define XSPI_SFACR_SIOCMDEN_WIDTH                (1U)
#define XSPI_SFACR_SIOCMDEN(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_SIOCMDEN_SHIFT)) & XSPI_SFACR_SIOCMDEN_MASK)

#define XSPI_SFACR_RD_PB_EN_MASK                 (0x8000U)
#define XSPI_SFACR_RD_PB_EN_SHIFT                (15U)
#define XSPI_SFACR_RD_PB_EN_WIDTH                (1U)
#define XSPI_SFACR_RD_PB_EN(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_RD_PB_EN_SHIFT)) & XSPI_SFACR_RD_PB_EN_MASK)

#define XSPI_SFACR_WA_MASK                       (0x10000U)
#define XSPI_SFACR_WA_SHIFT                      (16U)
#define XSPI_SFACR_WA_WIDTH                      (1U)
#define XSPI_SFACR_WA(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_WA_SHIFT)) & XSPI_SFACR_WA_MASK)

#define XSPI_SFACR_BYTE_SWAP_MASK                (0x20000U)
#define XSPI_SFACR_BYTE_SWAP_SHIFT               (17U)
#define XSPI_SFACR_BYTE_SWAP_WIDTH               (1U)
#define XSPI_SFACR_BYTE_SWAP(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_BYTE_SWAP_SHIFT)) & XSPI_SFACR_BYTE_SWAP_MASK)

#define XSPI_SFACR_RX_BP_EN_MASK                 (0x40000U)
#define XSPI_SFACR_RX_BP_EN_SHIFT                (18U)
#define XSPI_SFACR_RX_BP_EN_WIDTH                (1U)
#define XSPI_SFACR_RX_BP_EN(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_RX_BP_EN_SHIFT)) & XSPI_SFACR_RX_BP_EN_MASK)

#define XSPI_SFACR_TBDRGTEN_MASK                 (0x80000U)
#define XSPI_SFACR_TBDRGTEN_SHIFT                (19U)
#define XSPI_SFACR_TBDRGTEN_WIDTH                (1U)
#define XSPI_SFACR_TBDRGTEN(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_TBDRGTEN_SHIFT)) & XSPI_SFACR_TBDRGTEN_MASK)

#define XSPI_SFACR_CAS_INTRLVD_MASK              (0x100000U)
#define XSPI_SFACR_CAS_INTRLVD_SHIFT             (20U)
#define XSPI_SFACR_CAS_INTRLVD_WIDTH             (1U)
#define XSPI_SFACR_CAS_INTRLVD(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_CAS_INTRLVD_SHIFT)) & XSPI_SFACR_CAS_INTRLVD_MASK)

#define XSPI_SFACR_WA_4B_EN_MASK                 (0x200000U)
#define XSPI_SFACR_WA_4B_EN_SHIFT                (21U)
#define XSPI_SFACR_WA_4B_EN_WIDTH                (1U)
#define XSPI_SFACR_WA_4B_EN(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_WA_4B_EN_SHIFT)) & XSPI_SFACR_WA_4B_EN_MASK)

#define XSPI_SFACR_FORCE_A10_MASK                (0x400000U)
#define XSPI_SFACR_FORCE_A10_SHIFT               (22U)
#define XSPI_SFACR_FORCE_A10_WIDTH               (1U)
#define XSPI_SFACR_FORCE_A10(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_FORCE_A10_SHIFT)) & XSPI_SFACR_FORCE_A10_MASK)

#define XSPI_SFACR_TX_FLUSH_MASK                 (0x800000U)
#define XSPI_SFACR_TX_FLUSH_SHIFT                (23U)
#define XSPI_SFACR_TX_FLUSH_WIDTH                (1U)
#define XSPI_SFACR_TX_FLUSH(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_TX_FLUSH_SHIFT)) & XSPI_SFACR_TX_FLUSH_MASK)
/*! @} */

/*! @name SMPR - Sampling */
/*! @{ */

#define XSPI_SMPR_FSPHS_MASK                     (0x20U)
#define XSPI_SMPR_FSPHS_SHIFT                    (5U)
#define XSPI_SMPR_FSPHS_WIDTH                    (1U)
#define XSPI_SMPR_FSPHS(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SMPR_FSPHS_SHIFT)) & XSPI_SMPR_FSPHS_MASK)

#define XSPI_SMPR_FSDLY_MASK                     (0x40U)
#define XSPI_SMPR_FSDLY_SHIFT                    (6U)
#define XSPI_SMPR_FSDLY_WIDTH                    (1U)
#define XSPI_SMPR_FSDLY(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SMPR_FSDLY_SHIFT)) & XSPI_SMPR_FSDLY_MASK)

#define XSPI_SMPR_DLLFSMPFA_MASK                 (0x7000000U)
#define XSPI_SMPR_DLLFSMPFA_SHIFT                (24U)
#define XSPI_SMPR_DLLFSMPFA_WIDTH                (3U)
#define XSPI_SMPR_DLLFSMPFA(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SMPR_DLLFSMPFA_SHIFT)) & XSPI_SMPR_DLLFSMPFA_MASK)
/*! @} */

/*! @name RBSR - RX Buffer Status */
/*! @{ */

#define XSPI_RBSR_RDBFL_MASK                     (0xFFU)
#define XSPI_RBSR_RDBFL_SHIFT                    (0U)
#define XSPI_RBSR_RDBFL_WIDTH                    (8U)
#define XSPI_RBSR_RDBFL(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RBSR_RDBFL_SHIFT)) & XSPI_RBSR_RDBFL_MASK)

#define XSPI_RBSR_RDCTR_MASK                     (0xFFFF0000U)
#define XSPI_RBSR_RDCTR_SHIFT                    (16U)
#define XSPI_RBSR_RDCTR_WIDTH                    (16U)
#define XSPI_RBSR_RDCTR(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RBSR_RDCTR_SHIFT)) & XSPI_RBSR_RDCTR_MASK)
/*! @} */

/*! @name RBCT - RX Buffer Control */
/*! @{ */

#define XSPI_RBCT_WMRK_MASK                      (0x7FU)
#define XSPI_RBCT_WMRK_SHIFT                     (0U)
#define XSPI_RBCT_WMRK_WIDTH                     (7U)
#define XSPI_RBCT_WMRK(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_RBCT_WMRK_SHIFT)) & XSPI_RBCT_WMRK_MASK)
/*! @} */

/*! @name AWRSR - AHB Write Status */
/*! @{ */

#define XSPI_AWRSR_SEQAUJOIN_MASK                (0x4U)
#define XSPI_AWRSR_SEQAUJOIN_SHIFT               (2U)
#define XSPI_AWRSR_SEQAUJOIN_WIDTH               (1U)
#define XSPI_AWRSR_SEQAUJOIN(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_AWRSR_SEQAUJOIN_SHIFT)) & XSPI_AWRSR_SEQAUJOIN_MASK)
/*! @} */

/*! @name DLLSR - DLL Status */
/*! @{ */

#define XSPI_DLLSR_DLLA_SLV_COARSE_VAL_MASK      (0xFU)
#define XSPI_DLLSR_DLLA_SLV_COARSE_VAL_SHIFT     (0U)
#define XSPI_DLLSR_DLLA_SLV_COARSE_VAL_WIDTH     (4U)
#define XSPI_DLLSR_DLLA_SLV_COARSE_VAL(x)        (((uint32_t)(((uint32_t)(x)) << XSPI_DLLSR_DLLA_SLV_COARSE_VAL_SHIFT)) & XSPI_DLLSR_DLLA_SLV_COARSE_VAL_MASK)

#define XSPI_DLLSR_DLLA_SLV_FINE_VAL_MASK        (0xF0U)
#define XSPI_DLLSR_DLLA_SLV_FINE_VAL_SHIFT       (4U)
#define XSPI_DLLSR_DLLA_SLV_FINE_VAL_WIDTH       (4U)
#define XSPI_DLLSR_DLLA_SLV_FINE_VAL(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_DLLSR_DLLA_SLV_FINE_VAL_SHIFT)) & XSPI_DLLSR_DLLA_SLV_FINE_VAL_MASK)

#define XSPI_DLLSR_DLLA_FINE_UNDERFLOW_MASK      (0x1000U)
#define XSPI_DLLSR_DLLA_FINE_UNDERFLOW_SHIFT     (12U)
#define XSPI_DLLSR_DLLA_FINE_UNDERFLOW_WIDTH     (1U)
#define XSPI_DLLSR_DLLA_FINE_UNDERFLOW(x)        (((uint32_t)(((uint32_t)(x)) << XSPI_DLLSR_DLLA_FINE_UNDERFLOW_SHIFT)) & XSPI_DLLSR_DLLA_FINE_UNDERFLOW_MASK)

#define XSPI_DLLSR_DLLA_RANGE_ERR_MASK           (0x2000U)
#define XSPI_DLLSR_DLLA_RANGE_ERR_SHIFT          (13U)
#define XSPI_DLLSR_DLLA_RANGE_ERR_WIDTH          (1U)
#define XSPI_DLLSR_DLLA_RANGE_ERR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_DLLSR_DLLA_RANGE_ERR_SHIFT)) & XSPI_DLLSR_DLLA_RANGE_ERR_MASK)

#define XSPI_DLLSR_SLVA_LOCK_MASK                (0x4000U)
#define XSPI_DLLSR_SLVA_LOCK_SHIFT               (14U)
#define XSPI_DLLSR_SLVA_LOCK_WIDTH               (1U)
#define XSPI_DLLSR_SLVA_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_DLLSR_SLVA_LOCK_SHIFT)) & XSPI_DLLSR_SLVA_LOCK_MASK)

#define XSPI_DLLSR_DLLA_LOCK_MASK                (0x8000U)
#define XSPI_DLLSR_DLLA_LOCK_SHIFT               (15U)
#define XSPI_DLLSR_DLLA_LOCK_WIDTH               (1U)
#define XSPI_DLLSR_DLLA_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_DLLSR_DLLA_LOCK_SHIFT)) & XSPI_DLLSR_DLLA_LOCK_MASK)
/*! @} */

/*! @name DLCR - Data Learning Configuration */
/*! @{ */

#define XSPI_DLCR_DLP_SEL_FA_MASK                (0xC000U)
#define XSPI_DLCR_DLP_SEL_FA_SHIFT               (14U)
#define XSPI_DLCR_DLP_SEL_FA_WIDTH               (2U)
#define XSPI_DLCR_DLP_SEL_FA(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_DLCR_DLP_SEL_FA_SHIFT)) & XSPI_DLCR_DLP_SEL_FA_MASK)

#define XSPI_DLCR_DL_NONDLP_FLSH_MASK            (0x1000000U)
#define XSPI_DLCR_DL_NONDLP_FLSH_SHIFT           (24U)
#define XSPI_DLCR_DL_NONDLP_FLSH_WIDTH           (1U)
#define XSPI_DLCR_DL_NONDLP_FLSH(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_DLCR_DL_NONDLP_FLSH_SHIFT)) & XSPI_DLCR_DL_NONDLP_FLSH_MASK)
/*! @} */

/*! @name DLSR_F - Data Learning Status Flash Memory */
/*! @{ */

#define XSPI_DLSR_F_NEG_EDGE_MASK                (0xFFU)
#define XSPI_DLSR_F_NEG_EDGE_SHIFT               (0U)
#define XSPI_DLSR_F_NEG_EDGE_WIDTH               (8U)
#define XSPI_DLSR_F_NEG_EDGE(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_DLSR_F_NEG_EDGE_SHIFT)) & XSPI_DLSR_F_NEG_EDGE_MASK)

#define XSPI_DLSR_F_POS_EDGE_MASK                (0xFF00U)
#define XSPI_DLSR_F_POS_EDGE_SHIFT               (8U)
#define XSPI_DLSR_F_POS_EDGE_WIDTH               (8U)
#define XSPI_DLSR_F_POS_EDGE(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_DLSR_F_POS_EDGE_SHIFT)) & XSPI_DLSR_F_POS_EDGE_MASK)

#define XSPI_DLSR_F_DLPFF_MASK                   (0x80000000U)
#define XSPI_DLSR_F_DLPFF_SHIFT                  (31U)
#define XSPI_DLSR_F_DLPFF_WIDTH                  (1U)
#define XSPI_DLSR_F_DLPFF(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_DLSR_F_DLPFF_SHIFT)) & XSPI_DLSR_F_DLPFF_MASK)
/*! @} */

/*! @name TBSR - TX Buffer Status */
/*! @{ */

#define XSPI_TBSR_TRBFL_MASK                     (0x1FFU)
#define XSPI_TBSR_TRBFL_SHIFT                    (0U)
#define XSPI_TBSR_TRBFL_WIDTH                    (9U)
#define XSPI_TBSR_TRBFL(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_TBSR_TRBFL_SHIFT)) & XSPI_TBSR_TRBFL_MASK)

#define XSPI_TBSR_TRCTR_MASK                     (0xFFFF0000U)
#define XSPI_TBSR_TRCTR_SHIFT                    (16U)
#define XSPI_TBSR_TRCTR_WIDTH                    (16U)
#define XSPI_TBSR_TRCTR(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_TBSR_TRCTR_SHIFT)) & XSPI_TBSR_TRCTR_MASK)
/*! @} */

/*! @name TBDR - TX Buffer Data */
/*! @{ */

#define XSPI_TBDR_TXDATA_MASK                    (0xFFFFFFFFU)
#define XSPI_TBDR_TXDATA_SHIFT                   (0U)
#define XSPI_TBDR_TXDATA_WIDTH                   (32U)
#define XSPI_TBDR_TXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TBDR_TXDATA_SHIFT)) & XSPI_TBDR_TXDATA_MASK)
/*! @} */

/*! @name TBCT - TX Buffer Control */
/*! @{ */

#define XSPI_TBCT_WMRK_MASK                      (0xFFU)
#define XSPI_TBCT_WMRK_SHIFT                     (0U)
#define XSPI_TBCT_WMRK_WIDTH                     (8U)
#define XSPI_TBCT_WMRK(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_TBCT_WMRK_SHIFT)) & XSPI_TBCT_WMRK_MASK)
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define XSPI_SR_BUSY_MASK                        (0x1U)
#define XSPI_SR_BUSY_SHIFT                       (0U)
#define XSPI_SR_BUSY_WIDTH                       (1U)
#define XSPI_SR_BUSY(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_SR_BUSY_SHIFT)) & XSPI_SR_BUSY_MASK)

#define XSPI_SR_IP_ACC_MASK                      (0x2U)
#define XSPI_SR_IP_ACC_SHIFT                     (1U)
#define XSPI_SR_IP_ACC_WIDTH                     (1U)
#define XSPI_SR_IP_ACC(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_IP_ACC_SHIFT)) & XSPI_SR_IP_ACC_MASK)

#define XSPI_SR_AHB_ACC_MASK                     (0x4U)
#define XSPI_SR_AHB_ACC_SHIFT                    (2U)
#define XSPI_SR_AHB_ACC_WIDTH                    (1U)
#define XSPI_SR_AHB_ACC(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB_ACC_SHIFT)) & XSPI_SR_AHB_ACC_MASK)

#define XSPI_SR_AWRACC_MASK                      (0x10U)
#define XSPI_SR_AWRACC_SHIFT                     (4U)
#define XSPI_SR_AWRACC_WIDTH                     (1U)
#define XSPI_SR_AWRACC(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AWRACC_SHIFT)) & XSPI_SR_AWRACC_MASK)

#define XSPI_SR_AHBTRN_MASK                      (0x40U)
#define XSPI_SR_AHBTRN_SHIFT                     (6U)
#define XSPI_SR_AHBTRN_WIDTH                     (1U)
#define XSPI_SR_AHBTRN(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHBTRN_SHIFT)) & XSPI_SR_AHBTRN_MASK)

#define XSPI_SR_AHB0NE_MASK                      (0x80U)
#define XSPI_SR_AHB0NE_SHIFT                     (7U)
#define XSPI_SR_AHB0NE_WIDTH                     (1U)
#define XSPI_SR_AHB0NE(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB0NE_SHIFT)) & XSPI_SR_AHB0NE_MASK)

#define XSPI_SR_AHB1NE_MASK                      (0x100U)
#define XSPI_SR_AHB1NE_SHIFT                     (8U)
#define XSPI_SR_AHB1NE_WIDTH                     (1U)
#define XSPI_SR_AHB1NE(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB1NE_SHIFT)) & XSPI_SR_AHB1NE_MASK)

#define XSPI_SR_AHB2NE_MASK                      (0x200U)
#define XSPI_SR_AHB2NE_SHIFT                     (9U)
#define XSPI_SR_AHB2NE_WIDTH                     (1U)
#define XSPI_SR_AHB2NE(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB2NE_SHIFT)) & XSPI_SR_AHB2NE_MASK)

#define XSPI_SR_AHB3NE_MASK                      (0x400U)
#define XSPI_SR_AHB3NE_SHIFT                     (10U)
#define XSPI_SR_AHB3NE_WIDTH                     (1U)
#define XSPI_SR_AHB3NE(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB3NE_SHIFT)) & XSPI_SR_AHB3NE_MASK)

#define XSPI_SR_AHB0FUL_MASK                     (0x800U)
#define XSPI_SR_AHB0FUL_SHIFT                    (11U)
#define XSPI_SR_AHB0FUL_WIDTH                    (1U)
#define XSPI_SR_AHB0FUL(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB0FUL_SHIFT)) & XSPI_SR_AHB0FUL_MASK)

#define XSPI_SR_AHB1FUL_MASK                     (0x1000U)
#define XSPI_SR_AHB1FUL_SHIFT                    (12U)
#define XSPI_SR_AHB1FUL_WIDTH                    (1U)
#define XSPI_SR_AHB1FUL(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB1FUL_SHIFT)) & XSPI_SR_AHB1FUL_MASK)

#define XSPI_SR_AHB2FUL_MASK                     (0x2000U)
#define XSPI_SR_AHB2FUL_SHIFT                    (13U)
#define XSPI_SR_AHB2FUL_WIDTH                    (1U)
#define XSPI_SR_AHB2FUL(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB2FUL_SHIFT)) & XSPI_SR_AHB2FUL_MASK)

#define XSPI_SR_AHB3FUL_MASK                     (0x4000U)
#define XSPI_SR_AHB3FUL_SHIFT                    (14U)
#define XSPI_SR_AHB3FUL_WIDTH                    (1U)
#define XSPI_SR_AHB3FUL(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB3FUL_SHIFT)) & XSPI_SR_AHB3FUL_MASK)

#define XSPI_SR_ARB_LCK_MASK                     (0x8000U)
#define XSPI_SR_ARB_LCK_SHIFT                    (15U)
#define XSPI_SR_ARB_LCK_WIDTH                    (1U)
#define XSPI_SR_ARB_LCK(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SR_ARB_LCK_SHIFT)) & XSPI_SR_ARB_LCK_MASK)

#define XSPI_SR_RXWE_MASK                        (0x10000U)
#define XSPI_SR_RXWE_SHIFT                       (16U)
#define XSPI_SR_RXWE_WIDTH                       (1U)
#define XSPI_SR_RXWE(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_SR_RXWE_SHIFT)) & XSPI_SR_RXWE_MASK)

#define XSPI_SR_RXFULL_MASK                      (0x80000U)
#define XSPI_SR_RXFULL_SHIFT                     (19U)
#define XSPI_SR_RXFULL_WIDTH                     (1U)
#define XSPI_SR_RXFULL(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_RXFULL_SHIFT)) & XSPI_SR_RXFULL_MASK)

#define XSPI_SR_ARB_STATE_MASK                   (0x700000U)
#define XSPI_SR_ARB_STATE_SHIFT                  (20U)
#define XSPI_SR_ARB_STATE_WIDTH                  (3U)
#define XSPI_SR_ARB_STATE(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_SR_ARB_STATE_SHIFT)) & XSPI_SR_ARB_STATE_MASK)

#define XSPI_SR_RXDMA_MASK                       (0x800000U)
#define XSPI_SR_RXDMA_SHIFT                      (23U)
#define XSPI_SR_RXDMA_WIDTH                      (1U)
#define XSPI_SR_RXDMA(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_SR_RXDMA_SHIFT)) & XSPI_SR_RXDMA_MASK)

#define XSPI_SR_TXNE_MASK                        (0x1000000U)
#define XSPI_SR_TXNE_SHIFT                       (24U)
#define XSPI_SR_TXNE_WIDTH                       (1U)
#define XSPI_SR_TXNE(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_SR_TXNE_SHIFT)) & XSPI_SR_TXNE_MASK)

#define XSPI_SR_TXWA_MASK                        (0x2000000U)
#define XSPI_SR_TXWA_SHIFT                       (25U)
#define XSPI_SR_TXWA_WIDTH                       (1U)
#define XSPI_SR_TXWA(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_SR_TXWA_SHIFT)) & XSPI_SR_TXWA_MASK)

#define XSPI_SR_TXDMA_MASK                       (0x4000000U)
#define XSPI_SR_TXDMA_SHIFT                      (26U)
#define XSPI_SR_TXDMA_WIDTH                      (1U)
#define XSPI_SR_TXDMA(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_SR_TXDMA_SHIFT)) & XSPI_SR_TXDMA_MASK)

#define XSPI_SR_TXFULL_MASK                      (0x8000000U)
#define XSPI_SR_TXFULL_SHIFT                     (27U)
#define XSPI_SR_TXFULL_WIDTH                     (1U)
#define XSPI_SR_TXFULL(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_TXFULL_SHIFT)) & XSPI_SR_TXFULL_MASK)

#define XSPI_SR_AR_SWRST_MASK                    (0x10000000U)
#define XSPI_SR_AR_SWRST_SHIFT                   (28U)
#define XSPI_SR_AR_SWRST_WIDTH                   (1U)
#define XSPI_SR_AR_SWRST(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AR_SWRST_SHIFT)) & XSPI_SR_AR_SWRST_MASK)

#define XSPI_SR_AW_SWRST_MASK                    (0x20000000U)
#define XSPI_SR_AW_SWRST_SHIFT                   (29U)
#define XSPI_SR_AW_SWRST_WIDTH                   (1U)
#define XSPI_SR_AW_SWRST(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AW_SWRST_SHIFT)) & XSPI_SR_AW_SWRST_MASK)
/*! @} */

/*! @name FR - Flag */
/*! @{ */

#define XSPI_FR_TFF_MASK                         (0x1U)
#define XSPI_FR_TFF_SHIFT                        (0U)
#define XSPI_FR_TFF_WIDTH                        (1U)
#define XSPI_FR_TFF(x)                           (((uint32_t)(((uint32_t)(x)) << XSPI_FR_TFF_SHIFT)) & XSPI_FR_TFF_MASK)

#define XSPI_FR_RDADDR_MASK                      (0x2U)
#define XSPI_FR_RDADDR_SHIFT                     (1U)
#define XSPI_FR_RDADDR_WIDTH                     (1U)
#define XSPI_FR_RDADDR(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_FR_RDADDR_SHIFT)) & XSPI_FR_RDADDR_MASK)

#define XSPI_FR_PERFOVF_MASK                     (0x4U)
#define XSPI_FR_PERFOVF_SHIFT                    (2U)
#define XSPI_FR_PERFOVF_WIDTH                    (1U)
#define XSPI_FR_PERFOVF(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_FR_PERFOVF_SHIFT)) & XSPI_FR_PERFOVF_MASK)

#define XSPI_FR_IPEDERR_MASK                     (0x20U)
#define XSPI_FR_IPEDERR_SHIFT                    (5U)
#define XSPI_FR_IPEDERR_WIDTH                    (1U)
#define XSPI_FR_IPEDERR(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_FR_IPEDERR_SHIFT)) & XSPI_FR_IPEDERR_MASK)

#define XSPI_FR_IPIEF_MASK                       (0x40U)
#define XSPI_FR_IPIEF_SHIFT                      (6U)
#define XSPI_FR_IPIEF_WIDTH                      (1U)
#define XSPI_FR_IPIEF(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_FR_IPIEF_SHIFT)) & XSPI_FR_IPIEF_MASK)

#define XSPI_FR_PPWF_MASK                        (0x100U)
#define XSPI_FR_PPWF_SHIFT                       (8U)
#define XSPI_FR_PPWF_WIDTH                       (1U)
#define XSPI_FR_PPWF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_PPWF_SHIFT)) & XSPI_FR_PPWF_MASK)

#define XSPI_FR_CRCAEF_MASK                      (0x400U)
#define XSPI_FR_CRCAEF_SHIFT                     (10U)
#define XSPI_FR_CRCAEF_WIDTH                     (1U)
#define XSPI_FR_CRCAEF(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_FR_CRCAEF_SHIFT)) & XSPI_FR_CRCAEF_MASK)

#define XSPI_FR_ABOF_MASK                        (0x1000U)
#define XSPI_FR_ABOF_SHIFT                       (12U)
#define XSPI_FR_ABOF_WIDTH                       (1U)
#define XSPI_FR_ABOF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_ABOF_SHIFT)) & XSPI_FR_ABOF_MASK)

#define XSPI_FR_AIBSEF_MASK                      (0x2000U)
#define XSPI_FR_AIBSEF_SHIFT                     (13U)
#define XSPI_FR_AIBSEF_WIDTH                     (1U)
#define XSPI_FR_AIBSEF(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_FR_AIBSEF_SHIFT)) & XSPI_FR_AIBSEF_MASK)

#define XSPI_FR_AITEF_MASK                       (0x4000U)
#define XSPI_FR_AITEF_SHIFT                      (14U)
#define XSPI_FR_AITEF_WIDTH                      (1U)
#define XSPI_FR_AITEF(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_FR_AITEF_SHIFT)) & XSPI_FR_AITEF_MASK)

#define XSPI_FR_AAEF_MASK                        (0x8000U)
#define XSPI_FR_AAEF_SHIFT                       (15U)
#define XSPI_FR_AAEF_WIDTH                       (1U)
#define XSPI_FR_AAEF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_AAEF_SHIFT)) & XSPI_FR_AAEF_MASK)

#define XSPI_FR_RBDF_MASK                        (0x10000U)
#define XSPI_FR_RBDF_SHIFT                       (16U)
#define XSPI_FR_RBDF_WIDTH                       (1U)
#define XSPI_FR_RBDF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_RBDF_SHIFT)) & XSPI_FR_RBDF_MASK)

#define XSPI_FR_RBOF_MASK                        (0x20000U)
#define XSPI_FR_RBOF_SHIFT                       (17U)
#define XSPI_FR_RBOF_WIDTH                       (1U)
#define XSPI_FR_RBOF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_RBOF_SHIFT)) & XSPI_FR_RBOF_MASK)

#define XSPI_FR_PECMDF_MASK                      (0x200000U)
#define XSPI_FR_PECMDF_SHIFT                     (21U)
#define XSPI_FR_PECMDF_WIDTH                     (1U)
#define XSPI_FR_PECMDF(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_FR_PECMDF_SHIFT)) & XSPI_FR_PECMDF_MASK)

#define XSPI_FR_ILLACC_MASK                      (0x400000U)
#define XSPI_FR_ILLACC_SHIFT                     (22U)
#define XSPI_FR_ILLACC_WIDTH                     (1U)
#define XSPI_FR_ILLACC(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_FR_ILLACC_SHIFT)) & XSPI_FR_ILLACC_MASK)

#define XSPI_FR_ILLINE_MASK                      (0x800000U)
#define XSPI_FR_ILLINE_SHIFT                     (23U)
#define XSPI_FR_ILLINE_WIDTH                     (1U)
#define XSPI_FR_ILLINE(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_FR_ILLINE_SHIFT)) & XSPI_FR_ILLINE_MASK)

#define XSPI_FR_DLLUNLCK_MASK                    (0x1000000U)
#define XSPI_FR_DLLUNLCK_SHIFT                   (24U)
#define XSPI_FR_DLLUNLCK_WIDTH                   (1U)
#define XSPI_FR_DLLUNLCK(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FR_DLLUNLCK_SHIFT)) & XSPI_FR_DLLUNLCK_MASK)

#define XSPI_FR_PRWF_MASK                        (0x2000000U)
#define XSPI_FR_PRWF_SHIFT                       (25U)
#define XSPI_FR_PRWF_WIDTH                       (1U)
#define XSPI_FR_PRWF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_PRWF_SHIFT)) & XSPI_FR_PRWF_MASK)

#define XSPI_FR_TBUF_MASK                        (0x4000000U)
#define XSPI_FR_TBUF_SHIFT                       (26U)
#define XSPI_FR_TBUF_WIDTH                       (1U)
#define XSPI_FR_TBUF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_TBUF_SHIFT)) & XSPI_FR_TBUF_MASK)

#define XSPI_FR_TBFF_MASK                        (0x8000000U)
#define XSPI_FR_TBFF_SHIFT                       (27U)
#define XSPI_FR_TBFF_WIDTH                       (1U)
#define XSPI_FR_TBFF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_TBFF_SHIFT)) & XSPI_FR_TBFF_MASK)

#define XSPI_FR_DLLABRT_MASK                     (0x10000000U)
#define XSPI_FR_DLLABRT_SHIFT                    (28U)
#define XSPI_FR_DLLABRT_WIDTH                    (1U)
#define XSPI_FR_DLLABRT(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_FR_DLLABRT_SHIFT)) & XSPI_FR_DLLABRT_MASK)

#define XSPI_FR_DLPFF_MASK                       (0x80000000U)
#define XSPI_FR_DLPFF_SHIFT                      (31U)
#define XSPI_FR_DLPFF_WIDTH                      (1U)
#define XSPI_FR_DLPFF(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_FR_DLPFF_SHIFT)) & XSPI_FR_DLPFF_MASK)
/*! @} */

/*! @name RSER - Interrupt and DMA Request Enable */
/*! @{ */

#define XSPI_RSER_TFIE_MASK                      (0x1U)
#define XSPI_RSER_TFIE_SHIFT                     (0U)
#define XSPI_RSER_TFIE_WIDTH                     (1U)
#define XSPI_RSER_TFIE(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_TFIE_SHIFT)) & XSPI_RSER_TFIE_MASK)

#define XSPI_RSER_RDADDRIE_MASK                  (0x2U)
#define XSPI_RSER_RDADDRIE_SHIFT                 (1U)
#define XSPI_RSER_RDADDRIE_WIDTH                 (1U)
#define XSPI_RSER_RDADDRIE(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_RDADDRIE_SHIFT)) & XSPI_RSER_RDADDRIE_MASK)

#define XSPI_RSER_PERFOVIE_MASK                  (0x4U)
#define XSPI_RSER_PERFOVIE_SHIFT                 (2U)
#define XSPI_RSER_PERFOVIE_WIDTH                 (1U)
#define XSPI_RSER_PERFOVIE(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_PERFOVIE_SHIFT)) & XSPI_RSER_PERFOVIE_MASK)

#define XSPI_RSER_IPEDIE_MASK                    (0x20U)
#define XSPI_RSER_IPEDIE_SHIFT                   (5U)
#define XSPI_RSER_IPEDIE_WIDTH                   (1U)
#define XSPI_RSER_IPEDIE(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_IPEDIE_SHIFT)) & XSPI_RSER_IPEDIE_MASK)

#define XSPI_RSER_IPIEIE_MASK                    (0x40U)
#define XSPI_RSER_IPIEIE_SHIFT                   (6U)
#define XSPI_RSER_IPIEIE_WIDTH                   (1U)
#define XSPI_RSER_IPIEIE(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_IPIEIE_SHIFT)) & XSPI_RSER_IPIEIE_MASK)

#define XSPI_RSER_PPWIE_MASK                     (0x100U)
#define XSPI_RSER_PPWIE_SHIFT                    (8U)
#define XSPI_RSER_PPWIE_WIDTH                    (1U)
#define XSPI_RSER_PPWIE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_PPWIE_SHIFT)) & XSPI_RSER_PPWIE_MASK)

#define XSPI_RSER_CRCAIE_MASK                    (0x400U)
#define XSPI_RSER_CRCAIE_SHIFT                   (10U)
#define XSPI_RSER_CRCAIE_WIDTH                   (1U)
#define XSPI_RSER_CRCAIE(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_CRCAIE_SHIFT)) & XSPI_RSER_CRCAIE_MASK)

#define XSPI_RSER_ABOIE_MASK                     (0x1000U)
#define XSPI_RSER_ABOIE_SHIFT                    (12U)
#define XSPI_RSER_ABOIE_WIDTH                    (1U)
#define XSPI_RSER_ABOIE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_ABOIE_SHIFT)) & XSPI_RSER_ABOIE_MASK)

#define XSPI_RSER_AIBSIE_MASK                    (0x2000U)
#define XSPI_RSER_AIBSIE_SHIFT                   (13U)
#define XSPI_RSER_AIBSIE_WIDTH                   (1U)
#define XSPI_RSER_AIBSIE(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_AIBSIE_SHIFT)) & XSPI_RSER_AIBSIE_MASK)

#define XSPI_RSER_AITIE_MASK                     (0x4000U)
#define XSPI_RSER_AITIE_SHIFT                    (14U)
#define XSPI_RSER_AITIE_WIDTH                    (1U)
#define XSPI_RSER_AITIE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_AITIE_SHIFT)) & XSPI_RSER_AITIE_MASK)

#define XSPI_RSER_AAIE_MASK                      (0x8000U)
#define XSPI_RSER_AAIE_SHIFT                     (15U)
#define XSPI_RSER_AAIE_WIDTH                     (1U)
#define XSPI_RSER_AAIE(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_AAIE_SHIFT)) & XSPI_RSER_AAIE_MASK)

#define XSPI_RSER_RBDIE_MASK                     (0x10000U)
#define XSPI_RSER_RBDIE_SHIFT                    (16U)
#define XSPI_RSER_RBDIE_WIDTH                    (1U)
#define XSPI_RSER_RBDIE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_RBDIE_SHIFT)) & XSPI_RSER_RBDIE_MASK)

#define XSPI_RSER_RBOIE_MASK                     (0x20000U)
#define XSPI_RSER_RBOIE_SHIFT                    (17U)
#define XSPI_RSER_RBOIE_WIDTH                    (1U)
#define XSPI_RSER_RBOIE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_RBOIE_SHIFT)) & XSPI_RSER_RBOIE_MASK)

#define XSPI_RSER_PRWFIE_MASK                    (0x40000U)
#define XSPI_RSER_PRWFIE_SHIFT                   (18U)
#define XSPI_RSER_PRWFIE_WIDTH                   (1U)
#define XSPI_RSER_PRWFIE(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_PRWFIE_SHIFT)) & XSPI_RSER_PRWFIE_MASK)

#define XSPI_RSER_ILLACCIE_MASK                  (0x80000U)
#define XSPI_RSER_ILLACCIE_SHIFT                 (19U)
#define XSPI_RSER_ILLACCIE_WIDTH                 (1U)
#define XSPI_RSER_ILLACCIE(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_ILLACCIE_SHIFT)) & XSPI_RSER_ILLACCIE_MASK)

#define XSPI_RSER_RBDDE_MASK                     (0x200000U)
#define XSPI_RSER_RBDDE_SHIFT                    (21U)
#define XSPI_RSER_RBDDE_WIDTH                    (1U)
#define XSPI_RSER_RBDDE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_RBDDE_SHIFT)) & XSPI_RSER_RBDDE_MASK)

#define XSPI_RSER_ILLINIE_MASK                   (0x800000U)
#define XSPI_RSER_ILLINIE_SHIFT                  (23U)
#define XSPI_RSER_ILLINIE_WIDTH                  (1U)
#define XSPI_RSER_ILLINIE(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_ILLINIE_SHIFT)) & XSPI_RSER_ILLINIE_MASK)

#define XSPI_RSER_DLLULIE_MASK                   (0x1000000U)
#define XSPI_RSER_DLLULIE_SHIFT                  (24U)
#define XSPI_RSER_DLLULIE_WIDTH                  (1U)
#define XSPI_RSER_DLLULIE(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_DLLULIE_SHIFT)) & XSPI_RSER_DLLULIE_MASK)

#define XSPI_RSER_TBFDE_MASK                     (0x2000000U)
#define XSPI_RSER_TBFDE_SHIFT                    (25U)
#define XSPI_RSER_TBFDE_WIDTH                    (1U)
#define XSPI_RSER_TBFDE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_TBFDE_SHIFT)) & XSPI_RSER_TBFDE_MASK)

#define XSPI_RSER_TBUIE_MASK                     (0x4000000U)
#define XSPI_RSER_TBUIE_SHIFT                    (26U)
#define XSPI_RSER_TBUIE_WIDTH                    (1U)
#define XSPI_RSER_TBUIE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_TBUIE_SHIFT)) & XSPI_RSER_TBUIE_MASK)

#define XSPI_RSER_TBFIE_MASK                     (0x8000000U)
#define XSPI_RSER_TBFIE_SHIFT                    (27U)
#define XSPI_RSER_TBFIE_WIDTH                    (1U)
#define XSPI_RSER_TBFIE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_TBFIE_SHIFT)) & XSPI_RSER_TBFIE_MASK)

#define XSPI_RSER_DLPFIE_MASK                    (0x80000000U)
#define XSPI_RSER_DLPFIE_SHIFT                   (31U)
#define XSPI_RSER_DLPFIE_WIDTH                   (1U)
#define XSPI_RSER_DLPFIE(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_DLPFIE_SHIFT)) & XSPI_RSER_DLPFIE_MASK)
/*! @} */

/*! @name SPNDST - Sequence Suspend Status */
/*! @{ */

#define XSPI_SPNDST_STATE_MASK                   (0x3U)
#define XSPI_SPNDST_STATE_SHIFT                  (0U)
#define XSPI_SPNDST_STATE_WIDTH                  (2U)
#define XSPI_SPNDST_STATE(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_SPNDST_STATE_SHIFT)) & XSPI_SPNDST_STATE_MASK)

#define XSPI_SPNDST_SPDSBUF_MASK                 (0x30U)
#define XSPI_SPNDST_SPDSBUF_SHIFT                (4U)
#define XSPI_SPNDST_SPDSBUF_WIDTH                (2U)
#define XSPI_SPNDST_SPDSBUF(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SPNDST_SPDSBUF_SHIFT)) & XSPI_SPNDST_SPDSBUF_MASK)

#define XSPI_SPNDST_SPDBUF_MASK                  (0xC0U)
#define XSPI_SPNDST_SPDBUF_SHIFT                 (6U)
#define XSPI_SPNDST_SPDBUF_WIDTH                 (2U)
#define XSPI_SPNDST_SPDBUF(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_SPNDST_SPDBUF_SHIFT)) & XSPI_SPNDST_SPDBUF_MASK)

#define XSPI_SPNDST_DATLFT_MASK                  (0x3FE00U)
#define XSPI_SPNDST_DATLFT_SHIFT                 (9U)
#define XSPI_SPNDST_DATLFT_WIDTH                 (9U)
#define XSPI_SPNDST_DATLFT(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_SPNDST_DATLFT_SHIFT)) & XSPI_SPNDST_DATLFT_MASK)
/*! @} */

/*! @name SPTRCLR - Sequence Pointer Clear */
/*! @{ */

#define XSPI_SPTRCLR_BFPTRC_MASK                 (0x1U)
#define XSPI_SPTRCLR_BFPTRC_SHIFT                (0U)
#define XSPI_SPTRCLR_BFPTRC_WIDTH                (1U)
#define XSPI_SPTRCLR_BFPTRC(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SPTRCLR_BFPTRC_SHIFT)) & XSPI_SPTRCLR_BFPTRC_MASK)

#define XSPI_SPTRCLR_IPPTRC_MASK                 (0x100U)
#define XSPI_SPTRCLR_IPPTRC_SHIFT                (8U)
#define XSPI_SPTRCLR_IPPTRC_WIDTH                (1U)
#define XSPI_SPTRCLR_IPPTRC(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SPTRCLR_IPPTRC_SHIFT)) & XSPI_SPTRCLR_IPPTRC_MASK)

#define XSPI_SPTRCLR_ABRT_CLR_MASK               (0x10000U)
#define XSPI_SPTRCLR_ABRT_CLR_SHIFT              (16U)
#define XSPI_SPTRCLR_ABRT_CLR_WIDTH              (1U)
#define XSPI_SPTRCLR_ABRT_CLR(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_SPTRCLR_ABRT_CLR_SHIFT)) & XSPI_SPTRCLR_ABRT_CLR_MASK)

#define XSPI_SPTRCLR_PREFETCH_DIS_MASK           (0x20000U)
#define XSPI_SPTRCLR_PREFETCH_DIS_SHIFT          (17U)
#define XSPI_SPTRCLR_PREFETCH_DIS_WIDTH          (1U)
#define XSPI_SPTRCLR_PREFETCH_DIS(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_SPTRCLR_PREFETCH_DIS_SHIFT)) & XSPI_SPTRCLR_PREFETCH_DIS_MASK)

#define XSPI_SPTRCLR_STREAM_EN_MASK              (0x40000U)
#define XSPI_SPTRCLR_STREAM_EN_SHIFT             (18U)
#define XSPI_SPTRCLR_STREAM_EN_WIDTH             (1U)
#define XSPI_SPTRCLR_STREAM_EN(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_SPTRCLR_STREAM_EN_SHIFT)) & XSPI_SPTRCLR_STREAM_EN_MASK)

#define XSPI_SPTRCLR_OSD4GBIT_MASK               (0x400000U)
#define XSPI_SPTRCLR_OSD4GBIT_SHIFT              (22U)
#define XSPI_SPTRCLR_OSD4GBIT_WIDTH              (1U)
#define XSPI_SPTRCLR_OSD4GBIT(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_SPTRCLR_OSD4GBIT_SHIFT)) & XSPI_SPTRCLR_OSD4GBIT_MASK)

#define XSPI_SPTRCLR_OTFAD_BNDRY_MASK            (0x3000000U)
#define XSPI_SPTRCLR_OTFAD_BNDRY_SHIFT           (24U)
#define XSPI_SPTRCLR_OTFAD_BNDRY_WIDTH           (2U)
#define XSPI_SPTRCLR_OTFAD_BNDRY(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_SPTRCLR_OTFAD_BNDRY_SHIFT)) & XSPI_SPTRCLR_OTFAD_BNDRY_MASK)

#define XSPI_SPTRCLR_OS4GASFT_MASK               (0xC000000U)
#define XSPI_SPTRCLR_OS4GASFT_SHIFT              (26U)
#define XSPI_SPTRCLR_OS4GASFT_WIDTH              (2U)
#define XSPI_SPTRCLR_OS4GASFT(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_SPTRCLR_OS4GASFT_SHIFT)) & XSPI_SPTRCLR_OS4GASFT_MASK)
/*! @} */

/*! @name SFAD - Serial Flash Memory Top Address */
/*! @{ */

#define XSPI_SFAD_TPAD_MASK                      (0xFFFFFC00U)
#define XSPI_SFAD_TPAD_SHIFT                     (10U)
#define XSPI_SFAD_TPAD_WIDTH                     (22U)
#define XSPI_SFAD_TPAD(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SFAD_TPAD_SHIFT)) & XSPI_SFAD_TPAD_MASK)
/*! @} */

/*! @name DLPR - Data Learning Pattern */
/*! @{ */

#define XSPI_DLPR_DLPV_MASK                      (0xFFFFFFFFU)
#define XSPI_DLPR_DLPV_SHIFT                     (0U)
#define XSPI_DLPR_DLPV_WIDTH                     (32U)
#define XSPI_DLPR_DLPV(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_DLPR_DLPV_SHIFT)) & XSPI_DLPR_DLPV_MASK)
/*! @} */

/*! @name FAIL_ADDR - Flash Memory A Failing Address Status */
/*! @{ */

#define XSPI_FAIL_ADDR_ADDR_MASK                 (0xFFFFFFFFU)
#define XSPI_FAIL_ADDR_ADDR_SHIFT                (0U)
#define XSPI_FAIL_ADDR_ADDR_WIDTH                (32U)
#define XSPI_FAIL_ADDR_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_FAIL_ADDR_ADDR_SHIFT)) & XSPI_FAIL_ADDR_ADDR_MASK)
/*! @} */

/*! @name RBDR - RX Buffer Data */
/*! @{ */

#define XSPI_RBDR_RXDATA_MASK                    (0xFFFFFFFFU)
#define XSPI_RBDR_RXDATA_SHIFT                   (0U)
#define XSPI_RBDR_RXDATA_WIDTH                   (32U)
#define XSPI_RBDR_RXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_RBDR_RXDATA_SHIFT)) & XSPI_RBDR_RXDATA_MASK)
/*! @} */

/*! @name LUTKEY - LUT Key */
/*! @{ */

#define XSPI_LUTKEY_KEY_MASK                     (0xFFFFFFFFU)
#define XSPI_LUTKEY_KEY_SHIFT                    (0U)
#define XSPI_LUTKEY_KEY_WIDTH                    (32U)
#define XSPI_LUTKEY_KEY(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_LUTKEY_KEY_SHIFT)) & XSPI_LUTKEY_KEY_MASK)
/*! @} */

/*! @name LCKCR - LUT Lock Configuration */
/*! @{ */

#define XSPI_LCKCR_LOCK_MASK                     (0x1U)
#define XSPI_LCKCR_LOCK_SHIFT                    (0U)
#define XSPI_LCKCR_LOCK_WIDTH                    (1U)
#define XSPI_LCKCR_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_LCKCR_LOCK_SHIFT)) & XSPI_LCKCR_LOCK_MASK)

#define XSPI_LCKCR_UNLOCK_MASK                   (0x2U)
#define XSPI_LCKCR_UNLOCK_SHIFT                  (1U)
#define XSPI_LCKCR_UNLOCK_WIDTH                  (1U)
#define XSPI_LCKCR_UNLOCK(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_LCKCR_UNLOCK_SHIFT)) & XSPI_LCKCR_UNLOCK_MASK)
/*! @} */

/*! @name LUT - Lookup Table */
/*! @{ */

#define XSPI_LUT_OPRND0_MASK                     (0xFFU)
#define XSPI_LUT_OPRND0_SHIFT                    (0U)
#define XSPI_LUT_OPRND0_WIDTH                    (8U)
#define XSPI_LUT_OPRND0(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_LUT_OPRND0_SHIFT)) & XSPI_LUT_OPRND0_MASK)

#define XSPI_LUT_PAD0_MASK                       (0x300U)
#define XSPI_LUT_PAD0_SHIFT                      (8U)
#define XSPI_LUT_PAD0_WIDTH                      (2U)
#define XSPI_LUT_PAD0(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_LUT_PAD0_SHIFT)) & XSPI_LUT_PAD0_MASK)

#define XSPI_LUT_INSTR0_MASK                     (0xFC00U)
#define XSPI_LUT_INSTR0_SHIFT                    (10U)
#define XSPI_LUT_INSTR0_WIDTH                    (6U)
#define XSPI_LUT_INSTR0(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_LUT_INSTR0_SHIFT)) & XSPI_LUT_INSTR0_MASK)

#define XSPI_LUT_OPRND1_MASK                     (0xFF0000U)
#define XSPI_LUT_OPRND1_SHIFT                    (16U)
#define XSPI_LUT_OPRND1_WIDTH                    (8U)
#define XSPI_LUT_OPRND1(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_LUT_OPRND1_SHIFT)) & XSPI_LUT_OPRND1_MASK)

#define XSPI_LUT_PAD1_MASK                       (0x3000000U)
#define XSPI_LUT_PAD1_SHIFT                      (24U)
#define XSPI_LUT_PAD1_WIDTH                      (2U)
#define XSPI_LUT_PAD1(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_LUT_PAD1_SHIFT)) & XSPI_LUT_PAD1_MASK)

#define XSPI_LUT_INSTR1_MASK                     (0xFC000000U)
#define XSPI_LUT_INSTR1_SHIFT                    (26U)
#define XSPI_LUT_INSTR1_WIDTH                    (6U)
#define XSPI_LUT_INSTR1(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_LUT_INSTR1_SHIFT)) & XSPI_LUT_INSTR1_MASK)
/*! @} */

/*! @name BUF_ADDR_RANGE - AHB Buffer 0 Sub Buffer 0 Start and End Address Range..AHB Buffer 3 Sub Buffer 3 Start and End Address Range */
/*! @{ */

#define XSPI_BUF_ADDR_RANGE_STARTADR_MASK        (0xFFFFU)
#define XSPI_BUF_ADDR_RANGE_STARTADR_SHIFT       (0U)
#define XSPI_BUF_ADDR_RANGE_STARTADR_WIDTH       (16U)
#define XSPI_BUF_ADDR_RANGE_STARTADR(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_BUF_ADDR_RANGE_STARTADR_SHIFT)) & XSPI_BUF_ADDR_RANGE_STARTADR_MASK)

#define XSPI_BUF_ADDR_RANGE_ENDADR_MASK          (0xFFFF0000U)
#define XSPI_BUF_ADDR_RANGE_ENDADR_SHIFT         (16U)
#define XSPI_BUF_ADDR_RANGE_ENDADR_WIDTH         (16U)
#define XSPI_BUF_ADDR_RANGE_ENDADR(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_BUF_ADDR_RANGE_ENDADR_SHIFT)) & XSPI_BUF_ADDR_RANGE_ENDADR_MASK)
/*! @} */

/*! @name AHB_BUF_STATUS - AHB Buffer Status */
/*! @{ */

#define XSPI_AHB_BUF_STATUS_BUF0_0_MASK          (0x3U)
#define XSPI_AHB_BUF_STATUS_BUF0_0_SHIFT         (0U)
#define XSPI_AHB_BUF_STATUS_BUF0_0_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF0_0(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF0_0_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF0_0_MASK)

#define XSPI_AHB_BUF_STATUS_BUF0_1_MASK          (0xCU)
#define XSPI_AHB_BUF_STATUS_BUF0_1_SHIFT         (2U)
#define XSPI_AHB_BUF_STATUS_BUF0_1_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF0_1(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF0_1_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF0_1_MASK)

#define XSPI_AHB_BUF_STATUS_BUF0_2_MASK          (0x30U)
#define XSPI_AHB_BUF_STATUS_BUF0_2_SHIFT         (4U)
#define XSPI_AHB_BUF_STATUS_BUF0_2_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF0_2(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF0_2_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF0_2_MASK)

#define XSPI_AHB_BUF_STATUS_BUF0_3_MASK          (0xC0U)
#define XSPI_AHB_BUF_STATUS_BUF0_3_SHIFT         (6U)
#define XSPI_AHB_BUF_STATUS_BUF0_3_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF0_3(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF0_3_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF0_3_MASK)

#define XSPI_AHB_BUF_STATUS_BUF1_0_MASK          (0x300U)
#define XSPI_AHB_BUF_STATUS_BUF1_0_SHIFT         (8U)
#define XSPI_AHB_BUF_STATUS_BUF1_0_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF1_0(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF1_0_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF1_0_MASK)

#define XSPI_AHB_BUF_STATUS_BUF1_1_MASK          (0xC00U)
#define XSPI_AHB_BUF_STATUS_BUF1_1_SHIFT         (10U)
#define XSPI_AHB_BUF_STATUS_BUF1_1_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF1_1(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF1_1_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF1_1_MASK)

#define XSPI_AHB_BUF_STATUS_BUF1_2_MASK          (0x3000U)
#define XSPI_AHB_BUF_STATUS_BUF1_2_SHIFT         (12U)
#define XSPI_AHB_BUF_STATUS_BUF1_2_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF1_2(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF1_2_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF1_2_MASK)

#define XSPI_AHB_BUF_STATUS_BUF1_3_MASK          (0xC000U)
#define XSPI_AHB_BUF_STATUS_BUF1_3_SHIFT         (14U)
#define XSPI_AHB_BUF_STATUS_BUF1_3_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF1_3(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF1_3_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF1_3_MASK)

#define XSPI_AHB_BUF_STATUS_BUF2_0_MASK          (0x30000U)
#define XSPI_AHB_BUF_STATUS_BUF2_0_SHIFT         (16U)
#define XSPI_AHB_BUF_STATUS_BUF2_0_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF2_0(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF2_0_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF2_0_MASK)

#define XSPI_AHB_BUF_STATUS_BUF2_1_MASK          (0xC0000U)
#define XSPI_AHB_BUF_STATUS_BUF2_1_SHIFT         (18U)
#define XSPI_AHB_BUF_STATUS_BUF2_1_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF2_1(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF2_1_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF2_1_MASK)

#define XSPI_AHB_BUF_STATUS_BUF2_2_MASK          (0x300000U)
#define XSPI_AHB_BUF_STATUS_BUF2_2_SHIFT         (20U)
#define XSPI_AHB_BUF_STATUS_BUF2_2_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF2_2(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF2_2_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF2_2_MASK)

#define XSPI_AHB_BUF_STATUS_BUF2_3_MASK          (0xC00000U)
#define XSPI_AHB_BUF_STATUS_BUF2_3_SHIFT         (22U)
#define XSPI_AHB_BUF_STATUS_BUF2_3_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF2_3(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF2_3_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF2_3_MASK)

#define XSPI_AHB_BUF_STATUS_BUF3_0_MASK          (0x3000000U)
#define XSPI_AHB_BUF_STATUS_BUF3_0_SHIFT         (24U)
#define XSPI_AHB_BUF_STATUS_BUF3_0_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF3_0(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF3_0_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF3_0_MASK)

#define XSPI_AHB_BUF_STATUS_BUF3_1_MASK          (0xC000000U)
#define XSPI_AHB_BUF_STATUS_BUF3_1_SHIFT         (26U)
#define XSPI_AHB_BUF_STATUS_BUF3_1_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF3_1(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF3_1_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF3_1_MASK)

#define XSPI_AHB_BUF_STATUS_BUF3_2_MASK          (0x30000000U)
#define XSPI_AHB_BUF_STATUS_BUF3_2_SHIFT         (28U)
#define XSPI_AHB_BUF_STATUS_BUF3_2_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF3_2(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF3_2_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF3_2_MASK)

#define XSPI_AHB_BUF_STATUS_BUF3_3_MASK          (0xC0000000U)
#define XSPI_AHB_BUF_STATUS_BUF3_3_SHIFT         (30U)
#define XSPI_AHB_BUF_STATUS_BUF3_3_WIDTH         (2U)
#define XSPI_AHB_BUF_STATUS_BUF3_3(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF3_3_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF3_3_MASK)
/*! @} */

/*! @name AHB_PERF_CTRL - AHB Buffer Hit/Miss Performance Monitor Control */
/*! @{ */

#define XSPI_AHB_PERF_CTRL_BUF0_EN_MASK          (0x1U)
#define XSPI_AHB_PERF_CTRL_BUF0_EN_SHIFT         (0U)
#define XSPI_AHB_PERF_CTRL_BUF0_EN_WIDTH         (1U)
#define XSPI_AHB_PERF_CTRL_BUF0_EN(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF0_EN_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF0_EN_MASK)

#define XSPI_AHB_PERF_CTRL_BUF1_EN_MASK          (0x2U)
#define XSPI_AHB_PERF_CTRL_BUF1_EN_SHIFT         (1U)
#define XSPI_AHB_PERF_CTRL_BUF1_EN_WIDTH         (1U)
#define XSPI_AHB_PERF_CTRL_BUF1_EN(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF1_EN_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF1_EN_MASK)

#define XSPI_AHB_PERF_CTRL_BUF2_EN_MASK          (0x4U)
#define XSPI_AHB_PERF_CTRL_BUF2_EN_SHIFT         (2U)
#define XSPI_AHB_PERF_CTRL_BUF2_EN_WIDTH         (1U)
#define XSPI_AHB_PERF_CTRL_BUF2_EN(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF2_EN_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF2_EN_MASK)

#define XSPI_AHB_PERF_CTRL_BUF3_EN_MASK          (0x8U)
#define XSPI_AHB_PERF_CTRL_BUF3_EN_SHIFT         (3U)
#define XSPI_AHB_PERF_CTRL_BUF3_EN_WIDTH         (1U)
#define XSPI_AHB_PERF_CTRL_BUF3_EN(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF3_EN_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF3_EN_MASK)

#define XSPI_AHB_PERF_CTRL_CNTSTP_MASK           (0x10U)
#define XSPI_AHB_PERF_CTRL_CNTSTP_SHIFT          (4U)
#define XSPI_AHB_PERF_CTRL_CNTSTP_WIDTH          (1U)
#define XSPI_AHB_PERF_CTRL_CNTSTP(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_CNTSTP_SHIFT)) & XSPI_AHB_PERF_CTRL_CNTSTP_MASK)

#define XSPI_AHB_PERF_CTRL_CNTSTART_MASK         (0x20U)
#define XSPI_AHB_PERF_CTRL_CNTSTART_SHIFT        (5U)
#define XSPI_AHB_PERF_CTRL_CNTSTART_WIDTH        (1U)
#define XSPI_AHB_PERF_CTRL_CNTSTART(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_CNTSTART_SHIFT)) & XSPI_AHB_PERF_CTRL_CNTSTART_MASK)

#define XSPI_AHB_PERF_CTRL_BUF0_MISS_OVF_MASK    (0x1000U)
#define XSPI_AHB_PERF_CTRL_BUF0_MISS_OVF_SHIFT   (12U)
#define XSPI_AHB_PERF_CTRL_BUF0_MISS_OVF_WIDTH   (1U)
#define XSPI_AHB_PERF_CTRL_BUF0_MISS_OVF(x)      (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF0_MISS_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF0_MISS_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_BUF1_MISS_OVF_MASK    (0x2000U)
#define XSPI_AHB_PERF_CTRL_BUF1_MISS_OVF_SHIFT   (13U)
#define XSPI_AHB_PERF_CTRL_BUF1_MISS_OVF_WIDTH   (1U)
#define XSPI_AHB_PERF_CTRL_BUF1_MISS_OVF(x)      (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF1_MISS_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF1_MISS_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_BUF2_MISS_OVF_MASK    (0x4000U)
#define XSPI_AHB_PERF_CTRL_BUF2_MISS_OVF_SHIFT   (14U)
#define XSPI_AHB_PERF_CTRL_BUF2_MISS_OVF_WIDTH   (1U)
#define XSPI_AHB_PERF_CTRL_BUF2_MISS_OVF(x)      (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF2_MISS_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF2_MISS_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_BUF3_MISS_OVF_MASK    (0x8000U)
#define XSPI_AHB_PERF_CTRL_BUF3_MISS_OVF_SHIFT   (15U)
#define XSPI_AHB_PERF_CTRL_BUF3_MISS_OVF_WIDTH   (1U)
#define XSPI_AHB_PERF_CTRL_BUF3_MISS_OVF(x)      (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF3_MISS_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF3_MISS_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_BUF0_HIT_OVF_MASK     (0x10000U)
#define XSPI_AHB_PERF_CTRL_BUF0_HIT_OVF_SHIFT    (16U)
#define XSPI_AHB_PERF_CTRL_BUF0_HIT_OVF_WIDTH    (1U)
#define XSPI_AHB_PERF_CTRL_BUF0_HIT_OVF(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF0_HIT_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF0_HIT_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_BUF1_HIT_OVF_MASK     (0x20000U)
#define XSPI_AHB_PERF_CTRL_BUF1_HIT_OVF_SHIFT    (17U)
#define XSPI_AHB_PERF_CTRL_BUF1_HIT_OVF_WIDTH    (1U)
#define XSPI_AHB_PERF_CTRL_BUF1_HIT_OVF(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF1_HIT_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF1_HIT_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_BUF2_HIT_OVF_MASK     (0x40000U)
#define XSPI_AHB_PERF_CTRL_BUF2_HIT_OVF_SHIFT    (18U)
#define XSPI_AHB_PERF_CTRL_BUF2_HIT_OVF_WIDTH    (1U)
#define XSPI_AHB_PERF_CTRL_BUF2_HIT_OVF(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF2_HIT_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF2_HIT_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_BUF3_HIT_OVF_MASK     (0x80000U)
#define XSPI_AHB_PERF_CTRL_BUF3_HIT_OVF_SHIFT    (19U)
#define XSPI_AHB_PERF_CTRL_BUF3_HIT_OVF_WIDTH    (1U)
#define XSPI_AHB_PERF_CTRL_BUF3_HIT_OVF(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF3_HIT_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF3_HIT_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_TCNTO_MASK            (0x100000U)
#define XSPI_AHB_PERF_CTRL_TCNTO_SHIFT           (20U)
#define XSPI_AHB_PERF_CTRL_TCNTO_WIDTH           (1U)
#define XSPI_AHB_PERF_CTRL_TCNTO(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_TCNTO_SHIFT)) & XSPI_AHB_PERF_CTRL_TCNTO_MASK)

#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL0_MASK     (0x3000000U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL0_SHIFT    (24U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL0_WIDTH    (2U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL0(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_SUB_BUF_SEL0_SHIFT)) & XSPI_AHB_PERF_CTRL_SUB_BUF_SEL0_MASK)

#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL1_MASK     (0xC000000U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL1_SHIFT    (26U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL1_WIDTH    (2U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL1(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_SUB_BUF_SEL1_SHIFT)) & XSPI_AHB_PERF_CTRL_SUB_BUF_SEL1_MASK)

#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL2_MASK     (0x30000000U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL2_SHIFT    (28U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL2_WIDTH    (2U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL2(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_SUB_BUF_SEL2_SHIFT)) & XSPI_AHB_PERF_CTRL_SUB_BUF_SEL2_MASK)

#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL3_MASK     (0xC0000000U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL3_SHIFT    (30U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL3_WIDTH    (2U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL3(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_SUB_BUF_SEL3_SHIFT)) & XSPI_AHB_PERF_CTRL_SUB_BUF_SEL3_MASK)
/*! @} */

/*! @name AHB_PERF_TIME_CNT - AHB Performance Monitor Time Counter */
/*! @{ */

#define XSPI_AHB_PERF_TIME_CNT_PERF_TIME_COUNT_MASK (0xFFFFFFFFU)
#define XSPI_AHB_PERF_TIME_CNT_PERF_TIME_COUNT_SHIFT (0U)
#define XSPI_AHB_PERF_TIME_CNT_PERF_TIME_COUNT_WIDTH (32U)
#define XSPI_AHB_PERF_TIME_CNT_PERF_TIME_COUNT(x) (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_TIME_CNT_PERF_TIME_COUNT_SHIFT)) & XSPI_AHB_PERF_TIME_CNT_PERF_TIME_COUNT_MASK)
/*! @} */

/*! @name AHB_PERF_BUF - AHB Buffer 0 Performance Monitor..AHB Buffer 3 Performance Monitor */
/*! @{ */

#define XSPI_AHB_PERF_BUF_PERF_MISS_CNT_MASK     (0xFFFFU)
#define XSPI_AHB_PERF_BUF_PERF_MISS_CNT_SHIFT    (0U)
#define XSPI_AHB_PERF_BUF_PERF_MISS_CNT_WIDTH    (16U)
#define XSPI_AHB_PERF_BUF_PERF_MISS_CNT(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_BUF_PERF_MISS_CNT_SHIFT)) & XSPI_AHB_PERF_BUF_PERF_MISS_CNT_MASK)

#define XSPI_AHB_PERF_BUF_PERF_HIT_CNT_MASK      (0xFFFF0000U)
#define XSPI_AHB_PERF_BUF_PERF_HIT_CNT_SHIFT     (16U)
#define XSPI_AHB_PERF_BUF_PERF_HIT_CNT_WIDTH     (16U)
#define XSPI_AHB_PERF_BUF_PERF_HIT_CNT(x)        (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_BUF_PERF_HIT_CNT_SHIFT)) & XSPI_AHB_PERF_BUF_PERF_HIT_CNT_MASK)
/*! @} */

/*! @name AHRDYTO - AHB HREADY Timeout */
/*! @{ */

#define XSPI_AHRDYTO_HREADY_TO_MASK              (0xFFFFU)
#define XSPI_AHRDYTO_HREADY_TO_SHIFT             (0U)
#define XSPI_AHRDYTO_HREADY_TO_WIDTH             (16U)
#define XSPI_AHRDYTO_HREADY_TO(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_AHRDYTO_HREADY_TO_SHIFT)) & XSPI_AHRDYTO_HREADY_TO_MASK)
/*! @} */

/*! @name AHB_ERR_PAYLOAD_HI - AHB Error Payload High */
/*! @{ */

#define XSPI_AHB_ERR_PAYLOAD_HI_ERR_PAYLOAD_H_MASK (0xFFFFFFFFU)
#define XSPI_AHB_ERR_PAYLOAD_HI_ERR_PAYLOAD_H_SHIFT (0U)
#define XSPI_AHB_ERR_PAYLOAD_HI_ERR_PAYLOAD_H_WIDTH (32U)
#define XSPI_AHB_ERR_PAYLOAD_HI_ERR_PAYLOAD_H(x) (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_ERR_PAYLOAD_HI_ERR_PAYLOAD_H_SHIFT)) & XSPI_AHB_ERR_PAYLOAD_HI_ERR_PAYLOAD_H_MASK)
/*! @} */

/*! @name AHB_ERR_PAYLOAD_LO - AHB Error Payload Low */
/*! @{ */

#define XSPI_AHB_ERR_PAYLOAD_LO_ERR_PAYLOAD_L_MASK (0xFFFFFFFFU)
#define XSPI_AHB_ERR_PAYLOAD_LO_ERR_PAYLOAD_L_SHIFT (0U)
#define XSPI_AHB_ERR_PAYLOAD_LO_ERR_PAYLOAD_L_WIDTH (32U)
#define XSPI_AHB_ERR_PAYLOAD_LO_ERR_PAYLOAD_L(x) (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_ERR_PAYLOAD_LO_ERR_PAYLOAD_L_SHIFT)) & XSPI_AHB_ERR_PAYLOAD_LO_ERR_PAYLOAD_L_MASK)
/*! @} */

/*! @name AHB_RD_ERR_ADDR - AHB Read Error Address */
/*! @{ */

#define XSPI_AHB_RD_ERR_ADDR_READDR_MASK         (0xFFFFFFFFU)
#define XSPI_AHB_RD_ERR_ADDR_READDR_SHIFT        (0U)
#define XSPI_AHB_RD_ERR_ADDR_READDR_WIDTH        (32U)
#define XSPI_AHB_RD_ERR_ADDR_READDR(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_RD_ERR_ADDR_READDR_SHIFT)) & XSPI_AHB_RD_ERR_ADDR_READDR_MASK)
/*! @} */

/*! @name AHB_RD_ERR_MID - AHB Read Error Initiator ID */
/*! @{ */

#define XSPI_AHB_RD_ERR_MID_REMID_MASK           (0x3FU)
#define XSPI_AHB_RD_ERR_MID_REMID_SHIFT          (0U)
#define XSPI_AHB_RD_ERR_MID_REMID_WIDTH          (6U)
#define XSPI_AHB_RD_ERR_MID_REMID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_RD_ERR_MID_REMID_SHIFT)) & XSPI_AHB_RD_ERR_MID_REMID_MASK)
/*! @} */

/*! @name SPNDST_ADDR - Suspend Transaction Address */
/*! @{ */

#define XSPI_SPNDST_ADDR_ASAHBR_MASK             (0xFFFFFFF8U)
#define XSPI_SPNDST_ADDR_ASAHBR_SHIFT            (3U)
#define XSPI_SPNDST_ADDR_ASAHBR_WIDTH            (29U)
#define XSPI_SPNDST_ADDR_ASAHBR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_SPNDST_ADDR_ASAHBR_SHIFT)) & XSPI_SPNDST_ADDR_ASAHBR_MASK)
/*! @} */

/*! @name PPWF_TCNT - Page Program Wait Time Counter */
/*! @{ */

#define XSPI_PPWF_TCNT_PPWTC_MASK                (0xFFFFFFFFU)
#define XSPI_PPWF_TCNT_PPWTC_SHIFT               (0U)
#define XSPI_PPWF_TCNT_PPWTC_WIDTH               (32U)
#define XSPI_PPWF_TCNT_PPWTC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_PPWF_TCNT_PPWTC_SHIFT)) & XSPI_PPWF_TCNT_PPWTC_MASK)
/*! @} */

/*! @name PPW_RDSR - Page Program Wait Read Status */
/*! @{ */

#define XSPI_PPW_RDSR_RDSR_MASK                  (0xFFFFU)
#define XSPI_PPW_RDSR_RDSR_SHIFT                 (0U)
#define XSPI_PPW_RDSR_RDSR_WIDTH                 (16U)
#define XSPI_PPW_RDSR_RDSR(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_PPW_RDSR_RDSR_SHIFT)) & XSPI_PPW_RDSR_RDSR_MASK)

#define XSPI_PPW_RDSR_RDSRWSEL_MASK              (0x200000U)
#define XSPI_PPW_RDSR_RDSRWSEL_SHIFT             (21U)
#define XSPI_PPW_RDSR_RDSRWSEL_WIDTH             (1U)
#define XSPI_PPW_RDSR_RDSRWSEL(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_PPW_RDSR_RDSRWSEL_SHIFT)) & XSPI_PPW_RDSR_RDSRWSEL_MASK)

#define XSPI_PPW_RDSR_RDSR_VAL_CHK_MASK          (0x400000U)
#define XSPI_PPW_RDSR_RDSR_VAL_CHK_SHIFT         (22U)
#define XSPI_PPW_RDSR_RDSR_VAL_CHK_WIDTH         (1U)
#define XSPI_PPW_RDSR_RDSR_VAL_CHK(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_PPW_RDSR_RDSR_VAL_CHK_SHIFT)) & XSPI_PPW_RDSR_RDSR_VAL_CHK_MASK)

#define XSPI_PPW_RDSR_RDSR_HWORD_SEL_MASK        (0x800000U)
#define XSPI_PPW_RDSR_RDSR_HWORD_SEL_SHIFT       (23U)
#define XSPI_PPW_RDSR_RDSR_HWORD_SEL_WIDTH       (1U)
#define XSPI_PPW_RDSR_RDSR_HWORD_SEL(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_PPW_RDSR_RDSR_HWORD_SEL_SHIFT)) & XSPI_PPW_RDSR_RDSR_HWORD_SEL_MASK)

#define XSPI_PPW_RDSR_LOC_MASK                   (0xF000000U)
#define XSPI_PPW_RDSR_LOC_SHIFT                  (24U)
#define XSPI_PPW_RDSR_LOC_WIDTH                  (4U)
#define XSPI_PPW_RDSR_LOC(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_PPW_RDSR_LOC_SHIFT)) & XSPI_PPW_RDSR_LOC_MASK)

#define XSPI_PPW_RDSR_VALID_MASK                 (0x80000000U)
#define XSPI_PPW_RDSR_VALID_SHIFT                (31U)
#define XSPI_PPW_RDSR_VALID_WIDTH                (1U)
#define XSPI_PPW_RDSR_VALID(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_PPW_RDSR_VALID_SHIFT)) & XSPI_PPW_RDSR_VALID_MASK)
/*! @} */

/*! @name IPEDCTXIV - IPED Context Initial Vector */
/*! @{ */

#define XSPI_IPEDCTXIV_CTX_IV_MASK               (0xFFFFFFFFU)
#define XSPI_IPEDCTXIV_CTX_IV_SHIFT              (0U)
#define XSPI_IPEDCTXIV_CTX_IV_WIDTH              (32U)
#define XSPI_IPEDCTXIV_CTX_IV(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXIV_CTX_IV_SHIFT)) & XSPI_IPEDCTXIV_CTX_IV_MASK)
/*! @} */

/*! @name IPEDCTXSTART - IPED Start Address Region */
/*! @{ */

#define XSPI_IPEDCTXSTART_CMR_MASK               (0x3U)
#define XSPI_IPEDCTXSTART_CMR_SHIFT              (0U)
#define XSPI_IPEDCTXSTART_CMR_WIDTH              (2U)
#define XSPI_IPEDCTXSTART_CMR(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXSTART_CMR_SHIFT)) & XSPI_IPEDCTXSTART_CMR_MASK)

#define XSPI_IPEDCTXSTART_SADD_MASK              (0xFFFFFF00U)
#define XSPI_IPEDCTXSTART_SADD_SHIFT             (8U)
#define XSPI_IPEDCTXSTART_SADD_WIDTH             (24U)
#define XSPI_IPEDCTXSTART_SADD(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXSTART_SADD_SHIFT)) & XSPI_IPEDCTXSTART_SADD_MASK)
/*! @} */

/*! @name IPEDCTXEND - IPED End Address Region */
/*! @{ */

#define XSPI_IPEDCTXEND_END_ADDRESS_MASK         (0xFFFFFF00U)
#define XSPI_IPEDCTXEND_END_ADDRESS_SHIFT        (8U)
#define XSPI_IPEDCTXEND_END_ADDRESS_WIDTH        (24U)
#define XSPI_IPEDCTXEND_END_ADDRESS(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXEND_END_ADDRESS_SHIFT)) & XSPI_IPEDCTXEND_END_ADDRESS_MASK)
/*! @} */

/*! @name IPEDCTXAAD - IPED Context Additional Authentication Data */
/*! @{ */

#define XSPI_IPEDCTXAAD_CTX_AAD_MASK             (0xFFFFFFFFU)
#define XSPI_IPEDCTXAAD_CTX_AAD_SHIFT            (0U)
#define XSPI_IPEDCTXAAD_CTX_AAD_WIDTH            (32U)
#define XSPI_IPEDCTXAAD_CTX_AAD(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXAAD_CTX_AAD_SHIFT)) & XSPI_IPEDCTXAAD_CTX_AAD_MASK)
/*! @} */

/*! @name IPEDCTRL - IPED Function Control */
/*! @{ */

#define XSPI_IPEDCTRL_CONFIG_MASK                (0x1U)
#define XSPI_IPEDCTRL_CONFIG_SHIFT               (0U)
#define XSPI_IPEDCTRL_CONFIG_WIDTH               (1U)
#define XSPI_IPEDCTRL_CONFIG(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_CONFIG_SHIFT)) & XSPI_IPEDCTRL_CONFIG_MASK)

#define XSPI_IPEDCTRL_IPED_EN_MASK               (0x2U)
#define XSPI_IPEDCTRL_IPED_EN_SHIFT              (1U)
#define XSPI_IPEDCTRL_IPED_EN_WIDTH              (1U)
#define XSPI_IPEDCTRL_IPED_EN(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPED_EN_SHIFT)) & XSPI_IPEDCTRL_IPED_EN_MASK)

#define XSPI_IPEDCTRL_IPWR_EN_MASK               (0x4U)
#define XSPI_IPEDCTRL_IPWR_EN_SHIFT              (2U)
#define XSPI_IPEDCTRL_IPWR_EN_WIDTH              (1U)
#define XSPI_IPEDCTRL_IPWR_EN(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPWR_EN_SHIFT)) & XSPI_IPEDCTRL_IPWR_EN_MASK)

#define XSPI_IPEDCTRL_AHBWR_EN_MASK              (0x8U)
#define XSPI_IPEDCTRL_AHBWR_EN_SHIFT             (3U)
#define XSPI_IPEDCTRL_AHBWR_EN_WIDTH             (1U)
#define XSPI_IPEDCTRL_AHBWR_EN(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_AHBWR_EN_SHIFT)) & XSPI_IPEDCTRL_AHBWR_EN_MASK)

#define XSPI_IPEDCTRL_AHBRD_EN_MASK              (0x10U)
#define XSPI_IPEDCTRL_AHBRD_EN_SHIFT             (4U)
#define XSPI_IPEDCTRL_AHBRD_EN_WIDTH             (1U)
#define XSPI_IPEDCTRL_AHBRD_EN(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_AHBRD_EN_SHIFT)) & XSPI_IPEDCTRL_AHBRD_EN_MASK)

#define XSPI_IPEDCTRL_IPGCMWR_MASK               (0x40U)
#define XSPI_IPEDCTRL_IPGCMWR_SHIFT              (6U)
#define XSPI_IPEDCTRL_IPGCMWR_WIDTH              (1U)
#define XSPI_IPEDCTRL_IPGCMWR(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPGCMWR_SHIFT)) & XSPI_IPEDCTRL_IPGCMWR_MASK)

#define XSPI_IPEDCTRL_AHGCMWR_MASK               (0x80U)
#define XSPI_IPEDCTRL_AHGCMWR_SHIFT              (7U)
#define XSPI_IPEDCTRL_AHGCMWR_WIDTH              (1U)
#define XSPI_IPEDCTRL_AHGCMWR(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_AHGCMWR_SHIFT)) & XSPI_IPEDCTRL_AHGCMWR_MASK)

#define XSPI_IPEDCTRL_AHBGCMRD_MASK              (0x100U)
#define XSPI_IPEDCTRL_AHBGCMRD_SHIFT             (8U)
#define XSPI_IPEDCTRL_AHBGCMRD_WIDTH             (1U)
#define XSPI_IPEDCTRL_AHBGCMRD(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_AHBGCMRD_SHIFT)) & XSPI_IPEDCTRL_AHBGCMRD_MASK)

#define XSPI_IPEDCTRL_IPED_PROTECT_MASK          (0x200U)
#define XSPI_IPEDCTRL_IPED_PROTECT_SHIFT         (9U)
#define XSPI_IPEDCTRL_IPED_PROTECT_WIDTH         (1U)
#define XSPI_IPEDCTRL_IPED_PROTECT(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPED_PROTECT_SHIFT)) & XSPI_IPEDCTRL_IPED_PROTECT_MASK)

#define XSPI_IPEDCTRL_IPED_SWRESET_MASK          (0x400U)
#define XSPI_IPEDCTRL_IPED_SWRESET_SHIFT         (10U)
#define XSPI_IPEDCTRL_IPED_SWRESET_WIDTH         (1U)
#define XSPI_IPEDCTRL_IPED_SWRESET(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPED_SWRESET_SHIFT)) & XSPI_IPEDCTRL_IPED_SWRESET_MASK)

#define XSPI_IPEDCTRL_IPED_XEX_EN_MASK           (0x800U)
#define XSPI_IPEDCTRL_IPED_XEX_EN_SHIFT          (11U)
#define XSPI_IPEDCTRL_IPED_XEX_EN_WIDTH          (1U)
#define XSPI_IPEDCTRL_IPED_XEX_EN(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPED_XEX_EN_SHIFT)) & XSPI_IPEDCTRL_IPED_XEX_EN_MASK)

#define XSPI_IPEDCTRL_IPSXEXWE_MASK              (0x1000U)
#define XSPI_IPEDCTRL_IPSXEXWE_SHIFT             (12U)
#define XSPI_IPEDCTRL_IPSXEXWE_WIDTH             (1U)
#define XSPI_IPEDCTRL_IPSXEXWE(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPSXEXWE_SHIFT)) & XSPI_IPEDCTRL_IPSXEXWE_MASK)

#define XSPI_IPEDCTRL_AHBXEXWE_MASK              (0x2000U)
#define XSPI_IPEDCTRL_AHBXEXWE_SHIFT             (13U)
#define XSPI_IPEDCTRL_AHBXEXWE_WIDTH             (1U)
#define XSPI_IPEDCTRL_AHBXEXWE(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_AHBXEXWE_SHIFT)) & XSPI_IPEDCTRL_AHBXEXWE_MASK)

#define XSPI_IPEDCTRL_AHBXEXRE_MASK              (0x4000U)
#define XSPI_IPEDCTRL_AHBXEXRE_SHIFT             (14U)
#define XSPI_IPEDCTRL_AHBXEXRE_WIDTH             (1U)
#define XSPI_IPEDCTRL_AHBXEXRE(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_AHBXEXRE_SHIFT)) & XSPI_IPEDCTRL_AHBXEXRE_MASK)

#define XSPI_IPEDCTRL_IPS_GCM_MASK               (0x10000U)
#define XSPI_IPEDCTRL_IPS_GCM_SHIFT              (16U)
#define XSPI_IPEDCTRL_IPS_GCM_WIDTH              (1U)
#define XSPI_IPEDCTRL_IPS_GCM(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPS_GCM_SHIFT)) & XSPI_IPEDCTRL_IPS_GCM_MASK)
/*! @} */

/*! @name IPEDCTXCTRL - IPED Context Control 0..IPED Context Control 1 */
/*! @{ */

#define XSPI_IPEDCTXCTRL_CTX0_FREEZE_MASK        (0x3U)
#define XSPI_IPEDCTXCTRL_CTX0_FREEZE_SHIFT       (0U)
#define XSPI_IPEDCTXCTRL_CTX0_FREEZE_WIDTH       (2U)
#define XSPI_IPEDCTXCTRL_CTX0_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX0_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX0_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX1_FREEZE_MASK        (0xCU)
#define XSPI_IPEDCTXCTRL_CTX1_FREEZE_SHIFT       (2U)
#define XSPI_IPEDCTXCTRL_CTX1_FREEZE_WIDTH       (2U)
#define XSPI_IPEDCTXCTRL_CTX1_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX1_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX1_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX2_FREEZE_MASK        (0x30U)
#define XSPI_IPEDCTXCTRL_CTX2_FREEZE_SHIFT       (4U)
#define XSPI_IPEDCTXCTRL_CTX2_FREEZE_WIDTH       (2U)
#define XSPI_IPEDCTXCTRL_CTX2_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX2_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX2_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX3_FREEZE_MASK        (0xC0U)
#define XSPI_IPEDCTXCTRL_CTX3_FREEZE_SHIFT       (6U)
#define XSPI_IPEDCTXCTRL_CTX3_FREEZE_WIDTH       (2U)
#define XSPI_IPEDCTXCTRL_CTX3_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX3_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX3_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX4_FREEZE_MASK        (0x300U)
#define XSPI_IPEDCTXCTRL_CTX4_FREEZE_SHIFT       (8U)
#define XSPI_IPEDCTXCTRL_CTX4_FREEZE_WIDTH       (2U)
#define XSPI_IPEDCTXCTRL_CTX4_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX4_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX4_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX5_FREEZE_MASK        (0xC00U)
#define XSPI_IPEDCTXCTRL_CTX5_FREEZE_SHIFT       (10U)
#define XSPI_IPEDCTXCTRL_CTX5_FREEZE_WIDTH       (2U)
#define XSPI_IPEDCTXCTRL_CTX5_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX5_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX5_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX6_FREEZE_MASK        (0x3000U)
#define XSPI_IPEDCTXCTRL_CTX6_FREEZE_SHIFT       (12U)
#define XSPI_IPEDCTXCTRL_CTX6_FREEZE_WIDTH       (2U)
#define XSPI_IPEDCTXCTRL_CTX6_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX6_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX6_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX7_FREEZE_MASK        (0xC000U)
#define XSPI_IPEDCTXCTRL_CTX7_FREEZE_SHIFT       (14U)
#define XSPI_IPEDCTXCTRL_CTX7_FREEZE_WIDTH       (2U)
#define XSPI_IPEDCTXCTRL_CTX7_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX7_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX7_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX8_FREEZE_MASK        (0x30000U)
#define XSPI_IPEDCTXCTRL_CTX8_FREEZE_SHIFT       (16U)
#define XSPI_IPEDCTXCTRL_CTX8_FREEZE_WIDTH       (2U)
#define XSPI_IPEDCTXCTRL_CTX8_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX8_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX8_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX9_FREEZE_MASK        (0xC0000U)
#define XSPI_IPEDCTXCTRL_CTX9_FREEZE_SHIFT       (18U)
#define XSPI_IPEDCTXCTRL_CTX9_FREEZE_WIDTH       (2U)
#define XSPI_IPEDCTXCTRL_CTX9_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX9_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX9_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX10_FREEZE_MASK       (0x300000U)
#define XSPI_IPEDCTXCTRL_CTX10_FREEZE_SHIFT      (20U)
#define XSPI_IPEDCTXCTRL_CTX10_FREEZE_WIDTH      (2U)
#define XSPI_IPEDCTXCTRL_CTX10_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX10_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX10_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX11_FREEZE_MASK       (0xC00000U)
#define XSPI_IPEDCTXCTRL_CTX11_FREEZE_SHIFT      (22U)
#define XSPI_IPEDCTXCTRL_CTX11_FREEZE_WIDTH      (2U)
#define XSPI_IPEDCTXCTRL_CTX11_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX11_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX11_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX12_FREEZE_MASK       (0x3000000U)
#define XSPI_IPEDCTXCTRL_CTX12_FREEZE_SHIFT      (24U)
#define XSPI_IPEDCTXCTRL_CTX12_FREEZE_WIDTH      (2U)
#define XSPI_IPEDCTXCTRL_CTX12_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX12_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX12_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX13_FREEZE_MASK       (0xC000000U)
#define XSPI_IPEDCTXCTRL_CTX13_FREEZE_SHIFT      (26U)
#define XSPI_IPEDCTXCTRL_CTX13_FREEZE_WIDTH      (2U)
#define XSPI_IPEDCTXCTRL_CTX13_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX13_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX13_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX14_FREEZE_MASK       (0x30000000U)
#define XSPI_IPEDCTXCTRL_CTX14_FREEZE_SHIFT      (28U)
#define XSPI_IPEDCTXCTRL_CTX14_FREEZE_WIDTH      (2U)
#define XSPI_IPEDCTXCTRL_CTX14_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX14_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX14_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX15_FREEZE_MASK       (0xC0000000U)
#define XSPI_IPEDCTXCTRL_CTX15_FREEZE_SHIFT      (30U)
#define XSPI_IPEDCTXCTRL_CTX15_FREEZE_WIDTH      (2U)
#define XSPI_IPEDCTXCTRL_CTX15_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX15_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX15_FREEZE_MASK)
/*! @} */

/*! @name AWR_WRAP_STATUS - AHB Write Wrap Status */
/*! @{ */

#define XSPI_AWR_WRAP_STATUS_WWEBTMID_MASK       (0x3FU)
#define XSPI_AWR_WRAP_STATUS_WWEBTMID_SHIFT      (0U)
#define XSPI_AWR_WRAP_STATUS_WWEBTMID_WIDTH      (6U)
#define XSPI_AWR_WRAP_STATUS_WWEBTMID(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_AWR_WRAP_STATUS_WWEBTMID_SHIFT)) & XSPI_AWR_WRAP_STATUS_WWEBTMID_MASK)

#define XSPI_AWR_WRAP_STATUS_WWARLMID_MASK       (0x3F00U)
#define XSPI_AWR_WRAP_STATUS_WWARLMID_SHIFT      (8U)
#define XSPI_AWR_WRAP_STATUS_WWARLMID_WIDTH      (6U)
#define XSPI_AWR_WRAP_STATUS_WWARLMID(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_AWR_WRAP_STATUS_WWARLMID_SHIFT)) & XSPI_AWR_WRAP_STATUS_WWARLMID_MASK)

#define XSPI_AWR_WRAP_STATUS_WWMID_MASK          (0xFC000U)
#define XSPI_AWR_WRAP_STATUS_WWMID_SHIFT         (14U)
#define XSPI_AWR_WRAP_STATUS_WWMID_WIDTH         (6U)
#define XSPI_AWR_WRAP_STATUS_WWMID(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AWR_WRAP_STATUS_WWMID_SHIFT)) & XSPI_AWR_WRAP_STATUS_WWMID_MASK)
/*! @} */

/*! @name AHB_WW_ERR_ADDR_EBT - Write Wrap Burst Error Address due to Early Termination */
/*! @{ */

#define XSPI_AHB_WW_ERR_ADDR_EBT_WWEBTADR_MASK   (0xFFFFFFFFU)
#define XSPI_AHB_WW_ERR_ADDR_EBT_WWEBTADR_SHIFT  (0U)
#define XSPI_AHB_WW_ERR_ADDR_EBT_WWEBTADR_WIDTH  (32U)
#define XSPI_AHB_WW_ERR_ADDR_EBT_WWEBTADR(x)     (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_WW_ERR_ADDR_EBT_WWEBTADR_SHIFT)) & XSPI_AHB_WW_ERR_ADDR_EBT_WWEBTADR_MASK)
/*! @} */

/*! @name AHB_WW_ERR_ADDR_ARL - Write Wrap Burst Error Address due to Arbitration Lock */
/*! @{ */

#define XSPI_AHB_WW_ERR_ADDR_ARL_WWARLADR_MASK   (0xFFFFFFFFU)
#define XSPI_AHB_WW_ERR_ADDR_ARL_WWARLADR_SHIFT  (0U)
#define XSPI_AHB_WW_ERR_ADDR_ARL_WWARLADR_WIDTH  (32U)
#define XSPI_AHB_WW_ERR_ADDR_ARL_WWARLADR(x)     (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_WW_ERR_ADDR_ARL_WWARLADR_SHIFT)) & XSPI_AHB_WW_ERR_ADDR_ARL_WWARLADR_MASK)
/*! @} */

/*! @name AHB_WW_ERR_ADDR - AHB Write Wrap Burst Error Address */
/*! @{ */

#define XSPI_AHB_WW_ERR_ADDR_WWADR_MASK          (0xFFFFFFFFU)
#define XSPI_AHB_WW_ERR_ADDR_WWADR_SHIFT         (0U)
#define XSPI_AHB_WW_ERR_ADDR_WWADR_WIDTH         (32U)
#define XSPI_AHB_WW_ERR_ADDR_WWADR(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_WW_ERR_ADDR_WWADR_SHIFT)) & XSPI_AHB_WW_ERR_ADDR_WWADR_MASK)
/*! @} */

/*! @name FR2 - Flag 2 */
/*! @{ */

#define XSPI_FR2_WWI_MASK                        (0x1U)
#define XSPI_FR2_WWI_SHIFT                       (0U)
#define XSPI_FR2_WWI_WIDTH                       (1U)
#define XSPI_FR2_WWI(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR2_WWI_SHIFT)) & XSPI_FR2_WWI_MASK)

#define XSPI_FR2_WWI_EBT_MASK                    (0x2U)
#define XSPI_FR2_WWI_EBT_SHIFT                   (1U)
#define XSPI_FR2_WWI_EBT_WIDTH                   (1U)
#define XSPI_FR2_WWI_EBT(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FR2_WWI_EBT_SHIFT)) & XSPI_FR2_WWI_EBT_MASK)

#define XSPI_FR2_WWI_ARL_MASK                    (0x4U)
#define XSPI_FR2_WWI_ARL_SHIFT                   (2U)
#define XSPI_FR2_WWI_ARL_WIDTH                   (1U)
#define XSPI_FR2_WWI_ARL(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FR2_WWI_ARL_SHIFT)) & XSPI_FR2_WWI_ARL_MASK)
/*! @} */

/*! @name RSER2 - Interrupt and DMA Request Enable 2 */
/*! @{ */

#define XSPI_RSER2_WW_IE_MASK                    (0x1U)
#define XSPI_RSER2_WW_IE_SHIFT                   (0U)
#define XSPI_RSER2_WW_IE_WIDTH                   (1U)
#define XSPI_RSER2_WW_IE(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_RSER2_WW_IE_SHIFT)) & XSPI_RSER2_WW_IE_MASK)

#define XSPI_RSER2_WWEBTIE_MASK                  (0x2U)
#define XSPI_RSER2_WWEBTIE_SHIFT                 (1U)
#define XSPI_RSER2_WWEBTIE_WIDTH                 (1U)
#define XSPI_RSER2_WWEBTIE(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_RSER2_WWEBTIE_SHIFT)) & XSPI_RSER2_WWEBTIE_MASK)

#define XSPI_RSER2_WWARLIE_MASK                  (0x4U)
#define XSPI_RSER2_WWARLIE_SHIFT                 (2U)
#define XSPI_RSER2_WWARLIE_WIDTH                 (1U)
#define XSPI_RSER2_WWARLIE(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_RSER2_WWARLIE_SHIFT)) & XSPI_RSER2_WWARLIE_MASK)
/*! @} */

/*! @name ARSWRST_ADDR - AHB Read Burst Address on Soft Reset */
/*! @{ */

#define XSPI_ARSWRST_ADDR_ARSWRSTA_MASK          (0xFFFFFFFFU)
#define XSPI_ARSWRST_ADDR_ARSWRSTA_SHIFT         (0U)
#define XSPI_ARSWRST_ADDR_ARSWRSTA_WIDTH         (32U)
#define XSPI_ARSWRST_ADDR_ARSWRSTA(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_ARSWRST_ADDR_ARSWRSTA_SHIFT)) & XSPI_ARSWRST_ADDR_ARSWRSTA_MASK)
/*! @} */

/*! @name ARSWRST_MID - AHB Read Burst Initiator ID on Soft Reset */
/*! @{ */

#define XSPI_ARSWRST_MID_ARSWRSTM_MASK           (0x3FU)
#define XSPI_ARSWRST_MID_ARSWRSTM_SHIFT          (0U)
#define XSPI_ARSWRST_MID_ARSWRSTM_WIDTH          (6U)
#define XSPI_ARSWRST_MID_ARSWRSTM(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_ARSWRST_MID_ARSWRSTM_SHIFT)) & XSPI_ARSWRST_MID_ARSWRSTM_MASK)
/*! @} */

/*! @name AWSWRST_ADDR - AHB Write Burst Address on Soft Reset */
/*! @{ */

#define XSPI_AWSWRST_ADDR_AWSWRSTA_MASK          (0xFFFFFFFFU)
#define XSPI_AWSWRST_ADDR_AWSWRSTA_SHIFT         (0U)
#define XSPI_AWSWRST_ADDR_AWSWRSTA_WIDTH         (32U)
#define XSPI_AWSWRST_ADDR_AWSWRSTA(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AWSWRST_ADDR_AWSWRSTA_SHIFT)) & XSPI_AWSWRST_ADDR_AWSWRSTA_MASK)
/*! @} */

/*! @name FRAD0_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD0_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD0_WORD0_STARTADR_SHIFT          (16U)
#define XSPI_FRAD0_WORD0_STARTADR_WIDTH          (16U)
#define XSPI_FRAD0_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD0_STARTADR_SHIFT)) & XSPI_FRAD0_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD0_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD0_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD0_WORD1_ENDADR_SHIFT            (16U)
#define XSPI_FRAD0_WORD1_ENDADR_WIDTH            (16U)
#define XSPI_FRAD0_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD1_ENDADR_SHIFT)) & XSPI_FRAD0_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD0_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD0_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD0_WORD2_MD0ACP_SHIFT            (0U)
#define XSPI_FRAD0_WORD2_MD0ACP_WIDTH            (3U)
#define XSPI_FRAD0_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD0_WORD2_MD0ACP_MASK)

#define XSPI_FRAD0_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD0_WORD2_MD1ACP_SHIFT            (3U)
#define XSPI_FRAD0_WORD2_MD1ACP_WIDTH            (3U)
#define XSPI_FRAD0_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD0_WORD2_MD1ACP_MASK)

#define XSPI_FRAD0_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD0_WORD2_EALO_SHIFT              (24U)
#define XSPI_FRAD0_WORD2_EALO_WIDTH              (6U)
#define XSPI_FRAD0_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD2_EALO_SHIFT)) & XSPI_FRAD0_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD0_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD0_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD0_WORD3_EAL_SHIFT               (24U)
#define XSPI_FRAD0_WORD3_EAL_WIDTH               (2U)
#define XSPI_FRAD0_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD3_EAL_SHIFT)) & XSPI_FRAD0_WORD3_EAL_MASK)

#define XSPI_FRAD0_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD0_WORD3_LOCK_SHIFT              (29U)
#define XSPI_FRAD0_WORD3_LOCK_WIDTH              (2U)
#define XSPI_FRAD0_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD3_LOCK_SHIFT)) & XSPI_FRAD0_WORD3_LOCK_MASK)

#define XSPI_FRAD0_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD0_WORD3_VLD_SHIFT               (31U)
#define XSPI_FRAD0_WORD3_VLD_WIDTH               (1U)
#define XSPI_FRAD0_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD3_VLD_SHIFT)) & XSPI_FRAD0_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD0_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD0_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD0_WORD4_CMP_ADDR_SHIFT          (0U)
#define XSPI_FRAD0_WORD4_CMP_ADDR_WIDTH          (32U)
#define XSPI_FRAD0_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD0_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD0_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD0_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD0_WORD5_CMP_MDID_SHIFT          (0U)
#define XSPI_FRAD0_WORD5_CMP_MDID_WIDTH          (6U)
#define XSPI_FRAD0_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD0_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD0_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD0_WORD5_CMP_SA_SHIFT            (6U)
#define XSPI_FRAD0_WORD5_CMP_SA_WIDTH            (1U)
#define XSPI_FRAD0_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD0_WORD5_CMP_SA_MASK)

#define XSPI_FRAD0_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD0_WORD5_CMP_PA_SHIFT            (7U)
#define XSPI_FRAD0_WORD5_CMP_PA_WIDTH            (1U)
#define XSPI_FRAD0_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD0_WORD5_CMP_PA_MASK)

#define XSPI_FRAD0_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD0_WORD5_CMP_ERR_SHIFT           (29U)
#define XSPI_FRAD0_WORD5_CMP_ERR_WIDTH           (1U)
#define XSPI_FRAD0_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD0_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD0_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD0_WORD5_CMPVALID_SHIFT          (30U)
#define XSPI_FRAD0_WORD5_CMPVALID_WIDTH          (1U)
#define XSPI_FRAD0_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD0_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name FRAD1_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD1_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD1_WORD0_STARTADR_SHIFT          (16U)
#define XSPI_FRAD1_WORD0_STARTADR_WIDTH          (16U)
#define XSPI_FRAD1_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD0_STARTADR_SHIFT)) & XSPI_FRAD1_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD1_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD1_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD1_WORD1_ENDADR_SHIFT            (16U)
#define XSPI_FRAD1_WORD1_ENDADR_WIDTH            (16U)
#define XSPI_FRAD1_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD1_ENDADR_SHIFT)) & XSPI_FRAD1_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD1_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD1_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD1_WORD2_MD0ACP_SHIFT            (0U)
#define XSPI_FRAD1_WORD2_MD0ACP_WIDTH            (3U)
#define XSPI_FRAD1_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD1_WORD2_MD0ACP_MASK)

#define XSPI_FRAD1_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD1_WORD2_MD1ACP_SHIFT            (3U)
#define XSPI_FRAD1_WORD2_MD1ACP_WIDTH            (3U)
#define XSPI_FRAD1_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD1_WORD2_MD1ACP_MASK)

#define XSPI_FRAD1_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD1_WORD2_EALO_SHIFT              (24U)
#define XSPI_FRAD1_WORD2_EALO_WIDTH              (6U)
#define XSPI_FRAD1_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD2_EALO_SHIFT)) & XSPI_FRAD1_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD1_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD1_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD1_WORD3_EAL_SHIFT               (24U)
#define XSPI_FRAD1_WORD3_EAL_WIDTH               (2U)
#define XSPI_FRAD1_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD3_EAL_SHIFT)) & XSPI_FRAD1_WORD3_EAL_MASK)

#define XSPI_FRAD1_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD1_WORD3_LOCK_SHIFT              (29U)
#define XSPI_FRAD1_WORD3_LOCK_WIDTH              (2U)
#define XSPI_FRAD1_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD3_LOCK_SHIFT)) & XSPI_FRAD1_WORD3_LOCK_MASK)

#define XSPI_FRAD1_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD1_WORD3_VLD_SHIFT               (31U)
#define XSPI_FRAD1_WORD3_VLD_WIDTH               (1U)
#define XSPI_FRAD1_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD3_VLD_SHIFT)) & XSPI_FRAD1_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD1_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD1_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD1_WORD4_CMP_ADDR_SHIFT          (0U)
#define XSPI_FRAD1_WORD4_CMP_ADDR_WIDTH          (32U)
#define XSPI_FRAD1_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD1_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD1_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD1_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD1_WORD5_CMP_MDID_SHIFT          (0U)
#define XSPI_FRAD1_WORD5_CMP_MDID_WIDTH          (6U)
#define XSPI_FRAD1_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD1_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD1_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD1_WORD5_CMP_SA_SHIFT            (6U)
#define XSPI_FRAD1_WORD5_CMP_SA_WIDTH            (1U)
#define XSPI_FRAD1_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD1_WORD5_CMP_SA_MASK)

#define XSPI_FRAD1_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD1_WORD5_CMP_PA_SHIFT            (7U)
#define XSPI_FRAD1_WORD5_CMP_PA_WIDTH            (1U)
#define XSPI_FRAD1_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD1_WORD5_CMP_PA_MASK)

#define XSPI_FRAD1_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD1_WORD5_CMP_ERR_SHIFT           (29U)
#define XSPI_FRAD1_WORD5_CMP_ERR_WIDTH           (1U)
#define XSPI_FRAD1_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD1_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD1_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD1_WORD5_CMPVALID_SHIFT          (30U)
#define XSPI_FRAD1_WORD5_CMPVALID_WIDTH          (1U)
#define XSPI_FRAD1_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD1_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name FRAD2_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD2_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD2_WORD0_STARTADR_SHIFT          (16U)
#define XSPI_FRAD2_WORD0_STARTADR_WIDTH          (16U)
#define XSPI_FRAD2_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD0_STARTADR_SHIFT)) & XSPI_FRAD2_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD2_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD2_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD2_WORD1_ENDADR_SHIFT            (16U)
#define XSPI_FRAD2_WORD1_ENDADR_WIDTH            (16U)
#define XSPI_FRAD2_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD1_ENDADR_SHIFT)) & XSPI_FRAD2_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD2_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD2_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD2_WORD2_MD0ACP_SHIFT            (0U)
#define XSPI_FRAD2_WORD2_MD0ACP_WIDTH            (3U)
#define XSPI_FRAD2_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD2_WORD2_MD0ACP_MASK)

#define XSPI_FRAD2_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD2_WORD2_MD1ACP_SHIFT            (3U)
#define XSPI_FRAD2_WORD2_MD1ACP_WIDTH            (3U)
#define XSPI_FRAD2_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD2_WORD2_MD1ACP_MASK)

#define XSPI_FRAD2_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD2_WORD2_EALO_SHIFT              (24U)
#define XSPI_FRAD2_WORD2_EALO_WIDTH              (6U)
#define XSPI_FRAD2_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD2_EALO_SHIFT)) & XSPI_FRAD2_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD2_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD2_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD2_WORD3_EAL_SHIFT               (24U)
#define XSPI_FRAD2_WORD3_EAL_WIDTH               (2U)
#define XSPI_FRAD2_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD3_EAL_SHIFT)) & XSPI_FRAD2_WORD3_EAL_MASK)

#define XSPI_FRAD2_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD2_WORD3_LOCK_SHIFT              (29U)
#define XSPI_FRAD2_WORD3_LOCK_WIDTH              (2U)
#define XSPI_FRAD2_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD3_LOCK_SHIFT)) & XSPI_FRAD2_WORD3_LOCK_MASK)

#define XSPI_FRAD2_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD2_WORD3_VLD_SHIFT               (31U)
#define XSPI_FRAD2_WORD3_VLD_WIDTH               (1U)
#define XSPI_FRAD2_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD3_VLD_SHIFT)) & XSPI_FRAD2_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD2_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD2_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD2_WORD4_CMP_ADDR_SHIFT          (0U)
#define XSPI_FRAD2_WORD4_CMP_ADDR_WIDTH          (32U)
#define XSPI_FRAD2_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD2_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD2_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD2_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD2_WORD5_CMP_MDID_SHIFT          (0U)
#define XSPI_FRAD2_WORD5_CMP_MDID_WIDTH          (6U)
#define XSPI_FRAD2_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD2_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD2_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD2_WORD5_CMP_SA_SHIFT            (6U)
#define XSPI_FRAD2_WORD5_CMP_SA_WIDTH            (1U)
#define XSPI_FRAD2_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD2_WORD5_CMP_SA_MASK)

#define XSPI_FRAD2_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD2_WORD5_CMP_PA_SHIFT            (7U)
#define XSPI_FRAD2_WORD5_CMP_PA_WIDTH            (1U)
#define XSPI_FRAD2_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD2_WORD5_CMP_PA_MASK)

#define XSPI_FRAD2_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD2_WORD5_CMP_ERR_SHIFT           (29U)
#define XSPI_FRAD2_WORD5_CMP_ERR_WIDTH           (1U)
#define XSPI_FRAD2_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD2_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD2_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD2_WORD5_CMPVALID_SHIFT          (30U)
#define XSPI_FRAD2_WORD5_CMPVALID_WIDTH          (1U)
#define XSPI_FRAD2_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD2_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name FRAD3_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD3_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD3_WORD0_STARTADR_SHIFT          (16U)
#define XSPI_FRAD3_WORD0_STARTADR_WIDTH          (16U)
#define XSPI_FRAD3_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD0_STARTADR_SHIFT)) & XSPI_FRAD3_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD3_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD3_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD3_WORD1_ENDADR_SHIFT            (16U)
#define XSPI_FRAD3_WORD1_ENDADR_WIDTH            (16U)
#define XSPI_FRAD3_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD1_ENDADR_SHIFT)) & XSPI_FRAD3_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD3_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD3_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD3_WORD2_MD0ACP_SHIFT            (0U)
#define XSPI_FRAD3_WORD2_MD0ACP_WIDTH            (3U)
#define XSPI_FRAD3_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD3_WORD2_MD0ACP_MASK)

#define XSPI_FRAD3_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD3_WORD2_MD1ACP_SHIFT            (3U)
#define XSPI_FRAD3_WORD2_MD1ACP_WIDTH            (3U)
#define XSPI_FRAD3_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD3_WORD2_MD1ACP_MASK)

#define XSPI_FRAD3_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD3_WORD2_EALO_SHIFT              (24U)
#define XSPI_FRAD3_WORD2_EALO_WIDTH              (6U)
#define XSPI_FRAD3_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD2_EALO_SHIFT)) & XSPI_FRAD3_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD3_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD3_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD3_WORD3_EAL_SHIFT               (24U)
#define XSPI_FRAD3_WORD3_EAL_WIDTH               (2U)
#define XSPI_FRAD3_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD3_EAL_SHIFT)) & XSPI_FRAD3_WORD3_EAL_MASK)

#define XSPI_FRAD3_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD3_WORD3_LOCK_SHIFT              (29U)
#define XSPI_FRAD3_WORD3_LOCK_WIDTH              (2U)
#define XSPI_FRAD3_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD3_LOCK_SHIFT)) & XSPI_FRAD3_WORD3_LOCK_MASK)

#define XSPI_FRAD3_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD3_WORD3_VLD_SHIFT               (31U)
#define XSPI_FRAD3_WORD3_VLD_WIDTH               (1U)
#define XSPI_FRAD3_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD3_VLD_SHIFT)) & XSPI_FRAD3_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD3_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD3_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD3_WORD4_CMP_ADDR_SHIFT          (0U)
#define XSPI_FRAD3_WORD4_CMP_ADDR_WIDTH          (32U)
#define XSPI_FRAD3_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD3_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD3_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD3_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD3_WORD5_CMP_MDID_SHIFT          (0U)
#define XSPI_FRAD3_WORD5_CMP_MDID_WIDTH          (6U)
#define XSPI_FRAD3_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD3_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD3_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD3_WORD5_CMP_SA_SHIFT            (6U)
#define XSPI_FRAD3_WORD5_CMP_SA_WIDTH            (1U)
#define XSPI_FRAD3_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD3_WORD5_CMP_SA_MASK)

#define XSPI_FRAD3_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD3_WORD5_CMP_PA_SHIFT            (7U)
#define XSPI_FRAD3_WORD5_CMP_PA_WIDTH            (1U)
#define XSPI_FRAD3_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD3_WORD5_CMP_PA_MASK)

#define XSPI_FRAD3_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD3_WORD5_CMP_ERR_SHIFT           (29U)
#define XSPI_FRAD3_WORD5_CMP_ERR_WIDTH           (1U)
#define XSPI_FRAD3_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD3_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD3_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD3_WORD5_CMPVALID_SHIFT          (30U)
#define XSPI_FRAD3_WORD5_CMPVALID_WIDTH          (1U)
#define XSPI_FRAD3_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD3_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name FRAD4_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD4_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD4_WORD0_STARTADR_SHIFT          (16U)
#define XSPI_FRAD4_WORD0_STARTADR_WIDTH          (16U)
#define XSPI_FRAD4_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD0_STARTADR_SHIFT)) & XSPI_FRAD4_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD4_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD4_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD4_WORD1_ENDADR_SHIFT            (16U)
#define XSPI_FRAD4_WORD1_ENDADR_WIDTH            (16U)
#define XSPI_FRAD4_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD1_ENDADR_SHIFT)) & XSPI_FRAD4_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD4_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD4_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD4_WORD2_MD0ACP_SHIFT            (0U)
#define XSPI_FRAD4_WORD2_MD0ACP_WIDTH            (3U)
#define XSPI_FRAD4_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD4_WORD2_MD0ACP_MASK)

#define XSPI_FRAD4_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD4_WORD2_MD1ACP_SHIFT            (3U)
#define XSPI_FRAD4_WORD2_MD1ACP_WIDTH            (3U)
#define XSPI_FRAD4_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD4_WORD2_MD1ACP_MASK)

#define XSPI_FRAD4_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD4_WORD2_EALO_SHIFT              (24U)
#define XSPI_FRAD4_WORD2_EALO_WIDTH              (6U)
#define XSPI_FRAD4_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD2_EALO_SHIFT)) & XSPI_FRAD4_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD4_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD4_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD4_WORD3_EAL_SHIFT               (24U)
#define XSPI_FRAD4_WORD3_EAL_WIDTH               (2U)
#define XSPI_FRAD4_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD3_EAL_SHIFT)) & XSPI_FRAD4_WORD3_EAL_MASK)

#define XSPI_FRAD4_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD4_WORD3_LOCK_SHIFT              (29U)
#define XSPI_FRAD4_WORD3_LOCK_WIDTH              (2U)
#define XSPI_FRAD4_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD3_LOCK_SHIFT)) & XSPI_FRAD4_WORD3_LOCK_MASK)

#define XSPI_FRAD4_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD4_WORD3_VLD_SHIFT               (31U)
#define XSPI_FRAD4_WORD3_VLD_WIDTH               (1U)
#define XSPI_FRAD4_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD3_VLD_SHIFT)) & XSPI_FRAD4_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD4_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD4_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD4_WORD4_CMP_ADDR_SHIFT          (0U)
#define XSPI_FRAD4_WORD4_CMP_ADDR_WIDTH          (32U)
#define XSPI_FRAD4_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD4_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD4_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD4_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD4_WORD5_CMP_MDID_SHIFT          (0U)
#define XSPI_FRAD4_WORD5_CMP_MDID_WIDTH          (6U)
#define XSPI_FRAD4_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD4_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD4_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD4_WORD5_CMP_SA_SHIFT            (6U)
#define XSPI_FRAD4_WORD5_CMP_SA_WIDTH            (1U)
#define XSPI_FRAD4_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD4_WORD5_CMP_SA_MASK)

#define XSPI_FRAD4_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD4_WORD5_CMP_PA_SHIFT            (7U)
#define XSPI_FRAD4_WORD5_CMP_PA_WIDTH            (1U)
#define XSPI_FRAD4_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD4_WORD5_CMP_PA_MASK)

#define XSPI_FRAD4_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD4_WORD5_CMP_ERR_SHIFT           (29U)
#define XSPI_FRAD4_WORD5_CMP_ERR_WIDTH           (1U)
#define XSPI_FRAD4_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD4_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD4_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD4_WORD5_CMPVALID_SHIFT          (30U)
#define XSPI_FRAD4_WORD5_CMPVALID_WIDTH          (1U)
#define XSPI_FRAD4_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD4_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name FRAD5_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD5_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD5_WORD0_STARTADR_SHIFT          (16U)
#define XSPI_FRAD5_WORD0_STARTADR_WIDTH          (16U)
#define XSPI_FRAD5_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD0_STARTADR_SHIFT)) & XSPI_FRAD5_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD5_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD5_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD5_WORD1_ENDADR_SHIFT            (16U)
#define XSPI_FRAD5_WORD1_ENDADR_WIDTH            (16U)
#define XSPI_FRAD5_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD1_ENDADR_SHIFT)) & XSPI_FRAD5_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD5_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD5_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD5_WORD2_MD0ACP_SHIFT            (0U)
#define XSPI_FRAD5_WORD2_MD0ACP_WIDTH            (3U)
#define XSPI_FRAD5_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD5_WORD2_MD0ACP_MASK)

#define XSPI_FRAD5_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD5_WORD2_MD1ACP_SHIFT            (3U)
#define XSPI_FRAD5_WORD2_MD1ACP_WIDTH            (3U)
#define XSPI_FRAD5_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD5_WORD2_MD1ACP_MASK)

#define XSPI_FRAD5_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD5_WORD2_EALO_SHIFT              (24U)
#define XSPI_FRAD5_WORD2_EALO_WIDTH              (6U)
#define XSPI_FRAD5_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD2_EALO_SHIFT)) & XSPI_FRAD5_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD5_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD5_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD5_WORD3_EAL_SHIFT               (24U)
#define XSPI_FRAD5_WORD3_EAL_WIDTH               (2U)
#define XSPI_FRAD5_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD3_EAL_SHIFT)) & XSPI_FRAD5_WORD3_EAL_MASK)

#define XSPI_FRAD5_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD5_WORD3_LOCK_SHIFT              (29U)
#define XSPI_FRAD5_WORD3_LOCK_WIDTH              (2U)
#define XSPI_FRAD5_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD3_LOCK_SHIFT)) & XSPI_FRAD5_WORD3_LOCK_MASK)

#define XSPI_FRAD5_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD5_WORD3_VLD_SHIFT               (31U)
#define XSPI_FRAD5_WORD3_VLD_WIDTH               (1U)
#define XSPI_FRAD5_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD3_VLD_SHIFT)) & XSPI_FRAD5_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD5_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD5_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD5_WORD4_CMP_ADDR_SHIFT          (0U)
#define XSPI_FRAD5_WORD4_CMP_ADDR_WIDTH          (32U)
#define XSPI_FRAD5_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD5_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD5_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD5_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD5_WORD5_CMP_MDID_SHIFT          (0U)
#define XSPI_FRAD5_WORD5_CMP_MDID_WIDTH          (6U)
#define XSPI_FRAD5_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD5_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD5_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD5_WORD5_CMP_SA_SHIFT            (6U)
#define XSPI_FRAD5_WORD5_CMP_SA_WIDTH            (1U)
#define XSPI_FRAD5_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD5_WORD5_CMP_SA_MASK)

#define XSPI_FRAD5_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD5_WORD5_CMP_PA_SHIFT            (7U)
#define XSPI_FRAD5_WORD5_CMP_PA_WIDTH            (1U)
#define XSPI_FRAD5_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD5_WORD5_CMP_PA_MASK)

#define XSPI_FRAD5_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD5_WORD5_CMP_ERR_SHIFT           (29U)
#define XSPI_FRAD5_WORD5_CMP_ERR_WIDTH           (1U)
#define XSPI_FRAD5_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD5_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD5_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD5_WORD5_CMPVALID_SHIFT          (30U)
#define XSPI_FRAD5_WORD5_CMPVALID_WIDTH          (1U)
#define XSPI_FRAD5_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD5_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name FRAD6_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD6_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD6_WORD0_STARTADR_SHIFT          (16U)
#define XSPI_FRAD6_WORD0_STARTADR_WIDTH          (16U)
#define XSPI_FRAD6_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD0_STARTADR_SHIFT)) & XSPI_FRAD6_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD6_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD6_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD6_WORD1_ENDADR_SHIFT            (16U)
#define XSPI_FRAD6_WORD1_ENDADR_WIDTH            (16U)
#define XSPI_FRAD6_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD1_ENDADR_SHIFT)) & XSPI_FRAD6_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD6_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD6_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD6_WORD2_MD0ACP_SHIFT            (0U)
#define XSPI_FRAD6_WORD2_MD0ACP_WIDTH            (3U)
#define XSPI_FRAD6_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD6_WORD2_MD0ACP_MASK)

#define XSPI_FRAD6_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD6_WORD2_MD1ACP_SHIFT            (3U)
#define XSPI_FRAD6_WORD2_MD1ACP_WIDTH            (3U)
#define XSPI_FRAD6_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD6_WORD2_MD1ACP_MASK)

#define XSPI_FRAD6_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD6_WORD2_EALO_SHIFT              (24U)
#define XSPI_FRAD6_WORD2_EALO_WIDTH              (6U)
#define XSPI_FRAD6_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD2_EALO_SHIFT)) & XSPI_FRAD6_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD6_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD6_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD6_WORD3_EAL_SHIFT               (24U)
#define XSPI_FRAD6_WORD3_EAL_WIDTH               (2U)
#define XSPI_FRAD6_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD3_EAL_SHIFT)) & XSPI_FRAD6_WORD3_EAL_MASK)

#define XSPI_FRAD6_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD6_WORD3_LOCK_SHIFT              (29U)
#define XSPI_FRAD6_WORD3_LOCK_WIDTH              (2U)
#define XSPI_FRAD6_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD3_LOCK_SHIFT)) & XSPI_FRAD6_WORD3_LOCK_MASK)

#define XSPI_FRAD6_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD6_WORD3_VLD_SHIFT               (31U)
#define XSPI_FRAD6_WORD3_VLD_WIDTH               (1U)
#define XSPI_FRAD6_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD3_VLD_SHIFT)) & XSPI_FRAD6_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD6_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD6_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD6_WORD4_CMP_ADDR_SHIFT          (0U)
#define XSPI_FRAD6_WORD4_CMP_ADDR_WIDTH          (32U)
#define XSPI_FRAD6_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD6_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD6_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD6_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD6_WORD5_CMP_MDID_SHIFT          (0U)
#define XSPI_FRAD6_WORD5_CMP_MDID_WIDTH          (6U)
#define XSPI_FRAD6_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD6_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD6_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD6_WORD5_CMP_SA_SHIFT            (6U)
#define XSPI_FRAD6_WORD5_CMP_SA_WIDTH            (1U)
#define XSPI_FRAD6_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD6_WORD5_CMP_SA_MASK)

#define XSPI_FRAD6_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD6_WORD5_CMP_PA_SHIFT            (7U)
#define XSPI_FRAD6_WORD5_CMP_PA_WIDTH            (1U)
#define XSPI_FRAD6_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD6_WORD5_CMP_PA_MASK)

#define XSPI_FRAD6_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD6_WORD5_CMP_ERR_SHIFT           (29U)
#define XSPI_FRAD6_WORD5_CMP_ERR_WIDTH           (1U)
#define XSPI_FRAD6_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD6_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD6_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD6_WORD5_CMPVALID_SHIFT          (30U)
#define XSPI_FRAD6_WORD5_CMPVALID_WIDTH          (1U)
#define XSPI_FRAD6_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD6_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name FRAD7_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD7_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD7_WORD0_STARTADR_SHIFT          (16U)
#define XSPI_FRAD7_WORD0_STARTADR_WIDTH          (16U)
#define XSPI_FRAD7_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD0_STARTADR_SHIFT)) & XSPI_FRAD7_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD7_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD7_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD7_WORD1_ENDADR_SHIFT            (16U)
#define XSPI_FRAD7_WORD1_ENDADR_WIDTH            (16U)
#define XSPI_FRAD7_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD1_ENDADR_SHIFT)) & XSPI_FRAD7_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD7_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD7_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD7_WORD2_MD0ACP_SHIFT            (0U)
#define XSPI_FRAD7_WORD2_MD0ACP_WIDTH            (3U)
#define XSPI_FRAD7_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD7_WORD2_MD0ACP_MASK)

#define XSPI_FRAD7_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD7_WORD2_MD1ACP_SHIFT            (3U)
#define XSPI_FRAD7_WORD2_MD1ACP_WIDTH            (3U)
#define XSPI_FRAD7_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD7_WORD2_MD1ACP_MASK)

#define XSPI_FRAD7_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD7_WORD2_EALO_SHIFT              (24U)
#define XSPI_FRAD7_WORD2_EALO_WIDTH              (6U)
#define XSPI_FRAD7_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD2_EALO_SHIFT)) & XSPI_FRAD7_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD7_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD7_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD7_WORD3_EAL_SHIFT               (24U)
#define XSPI_FRAD7_WORD3_EAL_WIDTH               (2U)
#define XSPI_FRAD7_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD3_EAL_SHIFT)) & XSPI_FRAD7_WORD3_EAL_MASK)

#define XSPI_FRAD7_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD7_WORD3_LOCK_SHIFT              (29U)
#define XSPI_FRAD7_WORD3_LOCK_WIDTH              (2U)
#define XSPI_FRAD7_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD3_LOCK_SHIFT)) & XSPI_FRAD7_WORD3_LOCK_MASK)

#define XSPI_FRAD7_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD7_WORD3_VLD_SHIFT               (31U)
#define XSPI_FRAD7_WORD3_VLD_WIDTH               (1U)
#define XSPI_FRAD7_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD3_VLD_SHIFT)) & XSPI_FRAD7_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD7_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD7_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD7_WORD4_CMP_ADDR_SHIFT          (0U)
#define XSPI_FRAD7_WORD4_CMP_ADDR_WIDTH          (32U)
#define XSPI_FRAD7_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD7_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD7_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD7_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD7_WORD5_CMP_MDID_SHIFT          (0U)
#define XSPI_FRAD7_WORD5_CMP_MDID_WIDTH          (6U)
#define XSPI_FRAD7_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD7_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD7_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD7_WORD5_CMP_SA_SHIFT            (6U)
#define XSPI_FRAD7_WORD5_CMP_SA_WIDTH            (1U)
#define XSPI_FRAD7_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD7_WORD5_CMP_SA_MASK)

#define XSPI_FRAD7_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD7_WORD5_CMP_PA_SHIFT            (7U)
#define XSPI_FRAD7_WORD5_CMP_PA_WIDTH            (1U)
#define XSPI_FRAD7_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD7_WORD5_CMP_PA_MASK)

#define XSPI_FRAD7_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD7_WORD5_CMP_ERR_SHIFT           (29U)
#define XSPI_FRAD7_WORD5_CMP_ERR_WIDTH           (1U)
#define XSPI_FRAD7_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD7_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD7_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD7_WORD5_CMPVALID_SHIFT          (30U)
#define XSPI_FRAD7_WORD5_CMPVALID_WIDTH          (1U)
#define XSPI_FRAD7_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD7_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name SFP_ARB_TIMEOUT - SFP Arbitration Lock Timeout Counter */
/*! @{ */

#define XSPI_SFP_ARB_TIMEOUT_SFP_ARB_TOC_MASK    (0xFFFFFFFFU)
#define XSPI_SFP_ARB_TIMEOUT_SFP_ARB_TOC_SHIFT   (0U)
#define XSPI_SFP_ARB_TIMEOUT_SFP_ARB_TOC_WIDTH   (32U)
#define XSPI_SFP_ARB_TIMEOUT_SFP_ARB_TOC(x)      (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_ARB_TIMEOUT_SFP_ARB_TOC_SHIFT)) & XSPI_SFP_ARB_TIMEOUT_SFP_ARB_TOC_MASK)
/*! @} */

/*! @name TG0MDAD - Target Group Initiator Domain Access Descriptor */
/*! @{ */

#define XSPI_TG0MDAD_MIDMATCH_MASK               (0x3FU)
#define XSPI_TG0MDAD_MIDMATCH_SHIFT              (0U)
#define XSPI_TG0MDAD_MIDMATCH_WIDTH              (6U)
#define XSPI_TG0MDAD_MIDMATCH(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_TG0MDAD_MIDMATCH_SHIFT)) & XSPI_TG0MDAD_MIDMATCH_MASK)

#define XSPI_TG0MDAD_MASK_MASK                   (0xFC0U)
#define XSPI_TG0MDAD_MASK_SHIFT                  (6U)
#define XSPI_TG0MDAD_MASK_WIDTH                  (6U)
#define XSPI_TG0MDAD_MASK(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_TG0MDAD_MASK_SHIFT)) & XSPI_TG0MDAD_MASK_MASK)

#define XSPI_TG0MDAD_MASKTYPE_MASK               (0x1000U)
#define XSPI_TG0MDAD_MASKTYPE_SHIFT              (12U)
#define XSPI_TG0MDAD_MASKTYPE_WIDTH              (1U)
#define XSPI_TG0MDAD_MASKTYPE(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_TG0MDAD_MASKTYPE_SHIFT)) & XSPI_TG0MDAD_MASKTYPE_MASK)

#define XSPI_TG0MDAD_SA_MASK                     (0xC000U)
#define XSPI_TG0MDAD_SA_SHIFT                    (14U)
#define XSPI_TG0MDAD_SA_WIDTH                    (2U)
#define XSPI_TG0MDAD_SA(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_TG0MDAD_SA_SHIFT)) & XSPI_TG0MDAD_SA_MASK)

#define XSPI_TG0MDAD_LCK_MASK                    (0x20000000U)
#define XSPI_TG0MDAD_LCK_SHIFT                   (29U)
#define XSPI_TG0MDAD_LCK_WIDTH                   (1U)
#define XSPI_TG0MDAD_LCK(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TG0MDAD_LCK_SHIFT)) & XSPI_TG0MDAD_LCK_MASK)

#define XSPI_TG0MDAD_VLD_MASK                    (0x80000000U)
#define XSPI_TG0MDAD_VLD_SHIFT                   (31U)
#define XSPI_TG0MDAD_VLD_WIDTH                   (1U)
#define XSPI_TG0MDAD_VLD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TG0MDAD_VLD_SHIFT)) & XSPI_TG0MDAD_VLD_MASK)
/*! @} */

/*! @name TGSFAR - Target Group SFAR Address */
/*! @{ */

#define XSPI_TGSFAR_SFARADDR_MASK                (0xFFFFFFFFU)
#define XSPI_TGSFAR_SFARADDR_SHIFT               (0U)
#define XSPI_TGSFAR_SFARADDR_WIDTH               (32U)
#define XSPI_TGSFAR_SFARADDR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFAR_SFARADDR_SHIFT)) & XSPI_TGSFAR_SFARADDR_MASK)
/*! @} */

/*! @name TGSFARS - Target Group SFAR Status */
/*! @{ */

#define XSPI_TGSFARS_TG_MID_MASK                 (0x3FU)
#define XSPI_TGSFARS_TG_MID_SHIFT                (0U)
#define XSPI_TGSFARS_TG_MID_WIDTH                (6U)
#define XSPI_TGSFARS_TG_MID(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_TG_MID_SHIFT)) & XSPI_TGSFARS_TG_MID_MASK)

#define XSPI_TGSFARS_SA_MASK                     (0x400U)
#define XSPI_TGSFARS_SA_SHIFT                    (10U)
#define XSPI_TGSFARS_SA_WIDTH                    (1U)
#define XSPI_TGSFARS_SA(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_SA_SHIFT)) & XSPI_TGSFARS_SA_MASK)

#define XSPI_TGSFARS_PA_MASK                     (0x1000U)
#define XSPI_TGSFARS_PA_SHIFT                    (12U)
#define XSPI_TGSFARS_PA_WIDTH                    (1U)
#define XSPI_TGSFARS_PA(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_PA_SHIFT)) & XSPI_TGSFARS_PA_MASK)

#define XSPI_TGSFARS_CLR_MASK                    (0x20000000U)
#define XSPI_TGSFARS_CLR_SHIFT                   (29U)
#define XSPI_TGSFARS_CLR_WIDTH                   (1U)
#define XSPI_TGSFARS_CLR(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_CLR_SHIFT)) & XSPI_TGSFARS_CLR_MASK)

#define XSPI_TGSFARS_ERR_MASK                    (0x40000000U)
#define XSPI_TGSFARS_ERR_SHIFT                   (30U)
#define XSPI_TGSFARS_ERR_WIDTH                   (1U)
#define XSPI_TGSFARS_ERR(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_ERR_SHIFT)) & XSPI_TGSFARS_ERR_MASK)

#define XSPI_TGSFARS_VLD_MASK                    (0x80000000U)
#define XSPI_TGSFARS_VLD_SHIFT                   (31U)
#define XSPI_TGSFARS_VLD_WIDTH                   (1U)
#define XSPI_TGSFARS_VLD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_VLD_SHIFT)) & XSPI_TGSFARS_VLD_MASK)
/*! @} */

/*! @name TGIPCRS - Target Group IP Configuration Status */
/*! @{ */

#define XSPI_TGIPCRS_IDATSZ_MASK                 (0xFFFFU)
#define XSPI_TGIPCRS_IDATSZ_SHIFT                (0U)
#define XSPI_TGIPCRS_IDATSZ_WIDTH                (16U)
#define XSPI_TGIPCRS_IDATSZ(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_IDATSZ_SHIFT)) & XSPI_TGIPCRS_IDATSZ_MASK)

#define XSPI_TGIPCRS_SEQID_MASK                  (0xF0000U)
#define XSPI_TGIPCRS_SEQID_SHIFT                 (16U)
#define XSPI_TGIPCRS_SEQID_WIDTH                 (4U)
#define XSPI_TGIPCRS_SEQID(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SEQID_SHIFT)) & XSPI_TGIPCRS_SEQID_MASK)

#define XSPI_TGIPCRS_ARB_LOCK_MASK               (0x200000U)
#define XSPI_TGIPCRS_ARB_LOCK_SHIFT              (21U)
#define XSPI_TGIPCRS_ARB_LOCK_WIDTH              (1U)
#define XSPI_TGIPCRS_ARB_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_ARB_LOCK_SHIFT)) & XSPI_TGIPCRS_ARB_LOCK_MASK)

#define XSPI_TGIPCRS_ARB_UNLOCK_MASK             (0x400000U)
#define XSPI_TGIPCRS_ARB_UNLOCK_SHIFT            (22U)
#define XSPI_TGIPCRS_ARB_UNLOCK_WIDTH            (1U)
#define XSPI_TGIPCRS_ARB_UNLOCK(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_ARB_UNLOCK_SHIFT)) & XSPI_TGIPCRS_ARB_UNLOCK_MASK)

#define XSPI_TGIPCRS_ADDRTRDS_MASK               (0x1000000U)
#define XSPI_TGIPCRS_ADDRTRDS_SHIFT              (24U)
#define XSPI_TGIPCRS_ADDRTRDS_WIDTH              (1U)
#define XSPI_TGIPCRS_ADDRTRDS(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_ADDRTRDS_SHIFT)) & XSPI_TGIPCRS_ADDRTRDS_MASK)

#define XSPI_TGIPCRS_CLR_MASK                    (0x10000000U)
#define XSPI_TGIPCRS_CLR_SHIFT                   (28U)
#define XSPI_TGIPCRS_CLR_WIDTH                   (1U)
#define XSPI_TGIPCRS_CLR(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_CLR_SHIFT)) & XSPI_TGIPCRS_CLR_MASK)

#define XSPI_TGIPCRS_ERR_MASK                    (0x60000000U)
#define XSPI_TGIPCRS_ERR_SHIFT                   (29U)
#define XSPI_TGIPCRS_ERR_WIDTH                   (2U)
#define XSPI_TGIPCRS_ERR(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_ERR_SHIFT)) & XSPI_TGIPCRS_ERR_MASK)

#define XSPI_TGIPCRS_VLD_MASK                    (0x80000000U)
#define XSPI_TGIPCRS_VLD_SHIFT                   (31U)
#define XSPI_TGIPCRS_VLD_WIDTH                   (1U)
#define XSPI_TGIPCRS_VLD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_VLD_SHIFT)) & XSPI_TGIPCRS_VLD_MASK)
/*! @} */

/*! @name TG1MDAD - Target Group Initiator Domain Access Descriptor */
/*! @{ */

#define XSPI_TG1MDAD_MIDMATCH_MASK               (0x3FU)
#define XSPI_TG1MDAD_MIDMATCH_SHIFT              (0U)
#define XSPI_TG1MDAD_MIDMATCH_WIDTH              (6U)
#define XSPI_TG1MDAD_MIDMATCH(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_TG1MDAD_MIDMATCH_SHIFT)) & XSPI_TG1MDAD_MIDMATCH_MASK)

#define XSPI_TG1MDAD_MASK_MASK                   (0xFC0U)
#define XSPI_TG1MDAD_MASK_SHIFT                  (6U)
#define XSPI_TG1MDAD_MASK_WIDTH                  (6U)
#define XSPI_TG1MDAD_MASK(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_TG1MDAD_MASK_SHIFT)) & XSPI_TG1MDAD_MASK_MASK)

#define XSPI_TG1MDAD_MASKTYPE_MASK               (0x1000U)
#define XSPI_TG1MDAD_MASKTYPE_SHIFT              (12U)
#define XSPI_TG1MDAD_MASKTYPE_WIDTH              (1U)
#define XSPI_TG1MDAD_MASKTYPE(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_TG1MDAD_MASKTYPE_SHIFT)) & XSPI_TG1MDAD_MASKTYPE_MASK)

#define XSPI_TG1MDAD_SA_MASK                     (0xC000U)
#define XSPI_TG1MDAD_SA_SHIFT                    (14U)
#define XSPI_TG1MDAD_SA_WIDTH                    (2U)
#define XSPI_TG1MDAD_SA(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_TG1MDAD_SA_SHIFT)) & XSPI_TG1MDAD_SA_MASK)

#define XSPI_TG1MDAD_LCK_MASK                    (0x20000000U)
#define XSPI_TG1MDAD_LCK_SHIFT                   (29U)
#define XSPI_TG1MDAD_LCK_WIDTH                   (1U)
#define XSPI_TG1MDAD_LCK(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TG1MDAD_LCK_SHIFT)) & XSPI_TG1MDAD_LCK_MASK)

#define XSPI_TG1MDAD_VLD_MASK                    (0x80000000U)
#define XSPI_TG1MDAD_VLD_SHIFT                   (31U)
#define XSPI_TG1MDAD_VLD_WIDTH                   (1U)
#define XSPI_TG1MDAD_VLD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TG1MDAD_VLD_SHIFT)) & XSPI_TG1MDAD_VLD_MASK)
/*! @} */

/*! @name MGC - Initiator Global Configuration */
/*! @{ */

#define XSPI_MGC_GCLCKMID_MASK                   (0x3FU)
#define XSPI_MGC_GCLCKMID_SHIFT                  (0U)
#define XSPI_MGC_GCLCKMID_WIDTH                  (6U)
#define XSPI_MGC_GCLCKMID(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_MGC_GCLCKMID_SHIFT)) & XSPI_MGC_GCLCKMID_MASK)

#define XSPI_MGC_GCLCK_MASK                      (0xC00U)
#define XSPI_MGC_GCLCK_SHIFT                     (10U)
#define XSPI_MGC_GCLCK_WIDTH                     (2U)
#define XSPI_MGC_GCLCK(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_MGC_GCLCK_SHIFT)) & XSPI_MGC_GCLCK_MASK)

#define XSPI_MGC_TG1_FIX_PRIO_MASK               (0x10000U)
#define XSPI_MGC_TG1_FIX_PRIO_SHIFT              (16U)
#define XSPI_MGC_TG1_FIX_PRIO_WIDTH              (1U)
#define XSPI_MGC_TG1_FIX_PRIO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_MGC_TG1_FIX_PRIO_SHIFT)) & XSPI_MGC_TG1_FIX_PRIO_MASK)

#define XSPI_MGC_GVLDFRAD_MASK                   (0x8000000U)
#define XSPI_MGC_GVLDFRAD_SHIFT                  (27U)
#define XSPI_MGC_GVLDFRAD_WIDTH                  (1U)
#define XSPI_MGC_GVLDFRAD(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_MGC_GVLDFRAD_SHIFT)) & XSPI_MGC_GVLDFRAD_MASK)

#define XSPI_MGC_GVLDMDAD_MASK                   (0x20000000U)
#define XSPI_MGC_GVLDMDAD_SHIFT                  (29U)
#define XSPI_MGC_GVLDMDAD_WIDTH                  (1U)
#define XSPI_MGC_GVLDMDAD(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_MGC_GVLDMDAD_SHIFT)) & XSPI_MGC_GVLDMDAD_MASK)

#define XSPI_MGC_GVLD_MASK                       (0x80000000U)
#define XSPI_MGC_GVLD_SHIFT                      (31U)
#define XSPI_MGC_GVLD_WIDTH                      (1U)
#define XSPI_MGC_GVLD(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_MGC_GVLD_SHIFT)) & XSPI_MGC_GVLD_MASK)
/*! @} */

/*! @name MRC - Initiator Read Command */
/*! @{ */

#define XSPI_MRC_READ_CMD0_MASK                  (0x3FU)
#define XSPI_MRC_READ_CMD0_SHIFT                 (0U)
#define XSPI_MRC_READ_CMD0_WIDTH                 (6U)
#define XSPI_MRC_READ_CMD0(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_MRC_READ_CMD0_SHIFT)) & XSPI_MRC_READ_CMD0_MASK)

#define XSPI_MRC_READ_CMD1_MASK                  (0x3F00U)
#define XSPI_MRC_READ_CMD1_SHIFT                 (8U)
#define XSPI_MRC_READ_CMD1_WIDTH                 (6U)
#define XSPI_MRC_READ_CMD1(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_MRC_READ_CMD1_SHIFT)) & XSPI_MRC_READ_CMD1_MASK)

#define XSPI_MRC_READ_CMD2_MASK                  (0x3F0000U)
#define XSPI_MRC_READ_CMD2_SHIFT                 (16U)
#define XSPI_MRC_READ_CMD2_WIDTH                 (6U)
#define XSPI_MRC_READ_CMD2(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_MRC_READ_CMD2_SHIFT)) & XSPI_MRC_READ_CMD2_MASK)

#define XSPI_MRC_VLDCMD02_MASK                   (0x400000U)
#define XSPI_MRC_VLDCMD02_SHIFT                  (22U)
#define XSPI_MRC_VLDCMD02_WIDTH                  (1U)
#define XSPI_MRC_VLDCMD02(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_MRC_VLDCMD02_SHIFT)) & XSPI_MRC_VLDCMD02_MASK)

#define XSPI_MRC_READ_CMD3_MASK                  (0x3F000000U)
#define XSPI_MRC_READ_CMD3_SHIFT                 (24U)
#define XSPI_MRC_READ_CMD3_WIDTH                 (6U)
#define XSPI_MRC_READ_CMD3(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_MRC_READ_CMD3_SHIFT)) & XSPI_MRC_READ_CMD3_MASK)

#define XSPI_MRC_VLDCMD03_MASK                   (0x40000000U)
#define XSPI_MRC_VLDCMD03_SHIFT                  (30U)
#define XSPI_MRC_VLDCMD03_WIDTH                  (1U)
#define XSPI_MRC_VLDCMD03(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_MRC_VLDCMD03_SHIFT)) & XSPI_MRC_VLDCMD03_MASK)
/*! @} */

/*! @name MTO - Initiator Timeout */
/*! @{ */

#define XSPI_MTO_SFP_ACC_TO_MASK                 (0xFFFFFFFFU)
#define XSPI_MTO_SFP_ACC_TO_SHIFT                (0U)
#define XSPI_MTO_SFP_ACC_TO_WIDTH                (32U)
#define XSPI_MTO_SFP_ACC_TO(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_MTO_SFP_ACC_TO_SHIFT)) & XSPI_MTO_SFP_ACC_TO_MASK)
/*! @} */

/*! @name FLSEQREQ - Flash Sequence Request */
/*! @{ */

#define XSPI_FLSEQREQ_REQ_MID_MASK               (0x3FU)
#define XSPI_FLSEQREQ_REQ_MID_SHIFT              (0U)
#define XSPI_FLSEQREQ_REQ_MID_WIDTH              (6U)
#define XSPI_FLSEQREQ_REQ_MID(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_REQ_MID_SHIFT)) & XSPI_FLSEQREQ_REQ_MID_MASK)

#define XSPI_FLSEQREQ_REQ_TG_MASK                (0x40U)
#define XSPI_FLSEQREQ_REQ_TG_SHIFT               (6U)
#define XSPI_FLSEQREQ_REQ_TG_WIDTH               (1U)
#define XSPI_FLSEQREQ_REQ_TG(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_REQ_TG_SHIFT)) & XSPI_FLSEQREQ_REQ_TG_MASK)

#define XSPI_FLSEQREQ_SA_MASK                    (0x100U)
#define XSPI_FLSEQREQ_SA_SHIFT                   (8U)
#define XSPI_FLSEQREQ_SA_WIDTH                   (1U)
#define XSPI_FLSEQREQ_SA(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_SA_SHIFT)) & XSPI_FLSEQREQ_SA_MASK)

#define XSPI_FLSEQREQ_PA_MASK                    (0x200U)
#define XSPI_FLSEQREQ_PA_SHIFT                   (9U)
#define XSPI_FLSEQREQ_PA_WIDTH                   (1U)
#define XSPI_FLSEQREQ_PA(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_PA_SHIFT)) & XSPI_FLSEQREQ_PA_MASK)

#define XSPI_FLSEQREQ_ARB_LOCK_MASK              (0x400U)
#define XSPI_FLSEQREQ_ARB_LOCK_SHIFT             (10U)
#define XSPI_FLSEQREQ_ARB_LOCK_WIDTH             (1U)
#define XSPI_FLSEQREQ_ARB_LOCK(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_ARB_LOCK_SHIFT)) & XSPI_FLSEQREQ_ARB_LOCK_MASK)

#define XSPI_FLSEQREQ_FRAD_MASK                  (0x7000U)
#define XSPI_FLSEQREQ_FRAD_SHIFT                 (12U)
#define XSPI_FLSEQREQ_FRAD_WIDTH                 (3U)
#define XSPI_FLSEQREQ_FRAD(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_FRAD_SHIFT)) & XSPI_FLSEQREQ_FRAD_MASK)

#define XSPI_FLSEQREQ_SEQID_MASK                 (0xF0000U)
#define XSPI_FLSEQREQ_SEQID_SHIFT                (16U)
#define XSPI_FLSEQREQ_SEQID_WIDTH                (4U)
#define XSPI_FLSEQREQ_SEQID(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_SEQID_SHIFT)) & XSPI_FLSEQREQ_SEQID_MASK)

#define XSPI_FLSEQREQ_CMD_MASK                   (0x400000U)
#define XSPI_FLSEQREQ_CMD_SHIFT                  (22U)
#define XSPI_FLSEQREQ_CMD_WIDTH                  (1U)
#define XSPI_FLSEQREQ_CMD(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_CMD_SHIFT)) & XSPI_FLSEQREQ_CMD_MASK)

#define XSPI_FLSEQREQ_TIMEOUT_MASK               (0x8000000U)
#define XSPI_FLSEQREQ_TIMEOUT_SHIFT              (27U)
#define XSPI_FLSEQREQ_TIMEOUT_WIDTH              (1U)
#define XSPI_FLSEQREQ_TIMEOUT(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_TIMEOUT_SHIFT)) & XSPI_FLSEQREQ_TIMEOUT_MASK)

#define XSPI_FLSEQREQ_VLD_MASK                   (0x80000000U)
#define XSPI_FLSEQREQ_VLD_SHIFT                  (31U)
#define XSPI_FLSEQREQ_VLD_WIDTH                  (1U)
#define XSPI_FLSEQREQ_VLD(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_VLD_SHIFT)) & XSPI_FLSEQREQ_VLD_MASK)
/*! @} */

/*! @name FSMSTAT - FSM Status */
/*! @{ */

#define XSPI_FSMSTAT_STATE_MASK                  (0x3U)
#define XSPI_FSMSTAT_STATE_SHIFT                 (0U)
#define XSPI_FSMSTAT_STATE_WIDTH                 (2U)
#define XSPI_FSMSTAT_STATE(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_FSMSTAT_STATE_SHIFT)) & XSPI_FSMSTAT_STATE_MASK)

#define XSPI_FSMSTAT_MID_MASK                    (0x3F00U)
#define XSPI_FSMSTAT_MID_SHIFT                   (8U)
#define XSPI_FSMSTAT_MID_WIDTH                   (6U)
#define XSPI_FSMSTAT_MID(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FSMSTAT_MID_SHIFT)) & XSPI_FSMSTAT_MID_MASK)

#define XSPI_FSMSTAT_CMD_MASK                    (0x10000U)
#define XSPI_FSMSTAT_CMD_SHIFT                   (16U)
#define XSPI_FSMSTAT_CMD_WIDTH                   (1U)
#define XSPI_FSMSTAT_CMD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FSMSTAT_CMD_SHIFT)) & XSPI_FSMSTAT_CMD_MASK)

#define XSPI_FSMSTAT_ARB_LOCK_MASK               (0x20000U)
#define XSPI_FSMSTAT_ARB_LOCK_SHIFT              (17U)
#define XSPI_FSMSTAT_ARB_LOCK_WIDTH              (1U)
#define XSPI_FSMSTAT_ARB_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FSMSTAT_ARB_LOCK_SHIFT)) & XSPI_FSMSTAT_ARB_LOCK_MASK)

#define XSPI_FSMSTAT_VLD_MASK                    (0x80000000U)
#define XSPI_FSMSTAT_VLD_SHIFT                   (31U)
#define XSPI_FSMSTAT_VLD_WIDTH                   (1U)
#define XSPI_FSMSTAT_VLD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FSMSTAT_VLD_SHIFT)) & XSPI_FSMSTAT_VLD_MASK)
/*! @} */

/*! @name IPSERROR - IPS Error */
/*! @{ */

#define XSPI_IPSERROR_MID_MASK                   (0x3FU)
#define XSPI_IPSERROR_MID_SHIFT                  (0U)
#define XSPI_IPSERROR_MID_WIDTH                  (6U)
#define XSPI_IPSERROR_MID(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_MID_SHIFT)) & XSPI_IPSERROR_MID_MASK)

#define XSPI_IPSERROR_TG0LCK_MASK                (0x100U)
#define XSPI_IPSERROR_TG0LCK_SHIFT               (8U)
#define XSPI_IPSERROR_TG0LCK_WIDTH               (1U)
#define XSPI_IPSERROR_TG0LCK(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_TG0LCK_SHIFT)) & XSPI_IPSERROR_TG0LCK_MASK)

#define XSPI_IPSERROR_TG1LCK_MASK                (0x200U)
#define XSPI_IPSERROR_TG1LCK_SHIFT               (9U)
#define XSPI_IPSERROR_TG1LCK_WIDTH               (1U)
#define XSPI_IPSERROR_TG1LCK(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_TG1LCK_SHIFT)) & XSPI_IPSERROR_TG1LCK_MASK)

#define XSPI_IPSERROR_TG0SEC_MASK                (0x400U)
#define XSPI_IPSERROR_TG0SEC_SHIFT               (10U)
#define XSPI_IPSERROR_TG0SEC_WIDTH               (1U)
#define XSPI_IPSERROR_TG0SEC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_TG0SEC_SHIFT)) & XSPI_IPSERROR_TG0SEC_MASK)

#define XSPI_IPSERROR_TG1SEC_MASK                (0x800U)
#define XSPI_IPSERROR_TG1SEC_SHIFT               (11U)
#define XSPI_IPSERROR_TG1SEC_WIDTH               (1U)
#define XSPI_IPSERROR_TG1SEC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_TG1SEC_SHIFT)) & XSPI_IPSERROR_TG1SEC_MASK)

#define XSPI_IPSERROR_TG0MID_MASK                (0x1000U)
#define XSPI_IPSERROR_TG0MID_SHIFT               (12U)
#define XSPI_IPSERROR_TG0MID_WIDTH               (1U)
#define XSPI_IPSERROR_TG0MID(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_TG0MID_SHIFT)) & XSPI_IPSERROR_TG0MID_MASK)

#define XSPI_IPSERROR_TG1MID_MASK                (0x2000U)
#define XSPI_IPSERROR_TG1MID_SHIFT               (13U)
#define XSPI_IPSERROR_TG1MID_WIDTH               (1U)
#define XSPI_IPSERROR_TG1MID(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_TG1MID_SHIFT)) & XSPI_IPSERROR_TG1MID_MASK)

#define XSPI_IPSERROR_MDADPROG_MASK              (0x4000U)
#define XSPI_IPSERROR_MDADPROG_SHIFT             (14U)
#define XSPI_IPSERROR_MDADPROG_WIDTH             (1U)
#define XSPI_IPSERROR_MDADPROG(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_MDADPROG_SHIFT)) & XSPI_IPSERROR_MDADPROG_MASK)

#define XSPI_IPSERROR_FRADPROG_MASK              (0x8000U)
#define XSPI_IPSERROR_FRADPROG_SHIFT             (15U)
#define XSPI_IPSERROR_FRADPROG_WIDTH             (1U)
#define XSPI_IPSERROR_FRADPROG(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_FRADPROG_SHIFT)) & XSPI_IPSERROR_FRADPROG_MASK)

#define XSPI_IPSERROR_CLR_MASK                   (0x20000000U)
#define XSPI_IPSERROR_CLR_SHIFT                  (29U)
#define XSPI_IPSERROR_CLR_WIDTH                  (1U)
#define XSPI_IPSERROR_CLR(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_CLR_SHIFT)) & XSPI_IPSERROR_CLR_MASK)
/*! @} */

/*! @name ERRSTAT - Error Status */
/*! @{ */

#define XSPI_ERRSTAT_FRADMTCH_MASK               (0x1U)
#define XSPI_ERRSTAT_FRADMTCH_SHIFT              (0U)
#define XSPI_ERRSTAT_FRADMTCH_WIDTH              (1U)
#define XSPI_ERRSTAT_FRADMTCH(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRADMTCH_SHIFT)) & XSPI_ERRSTAT_FRADMTCH_MASK)

#define XSPI_ERRSTAT_FRAD0ACC_MASK               (0x2U)
#define XSPI_ERRSTAT_FRAD0ACC_SHIFT              (1U)
#define XSPI_ERRSTAT_FRAD0ACC_WIDTH              (1U)
#define XSPI_ERRSTAT_FRAD0ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD0ACC_SHIFT)) & XSPI_ERRSTAT_FRAD0ACC_MASK)

#define XSPI_ERRSTAT_FRAD1ACC_MASK               (0x4U)
#define XSPI_ERRSTAT_FRAD1ACC_SHIFT              (2U)
#define XSPI_ERRSTAT_FRAD1ACC_WIDTH              (1U)
#define XSPI_ERRSTAT_FRAD1ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD1ACC_SHIFT)) & XSPI_ERRSTAT_FRAD1ACC_MASK)

#define XSPI_ERRSTAT_FRAD2ACC_MASK               (0x8U)
#define XSPI_ERRSTAT_FRAD2ACC_SHIFT              (3U)
#define XSPI_ERRSTAT_FRAD2ACC_WIDTH              (1U)
#define XSPI_ERRSTAT_FRAD2ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD2ACC_SHIFT)) & XSPI_ERRSTAT_FRAD2ACC_MASK)

#define XSPI_ERRSTAT_FRAD3ACC_MASK               (0x10U)
#define XSPI_ERRSTAT_FRAD3ACC_SHIFT              (4U)
#define XSPI_ERRSTAT_FRAD3ACC_WIDTH              (1U)
#define XSPI_ERRSTAT_FRAD3ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD3ACC_SHIFT)) & XSPI_ERRSTAT_FRAD3ACC_MASK)

#define XSPI_ERRSTAT_FRAD4ACC_MASK               (0x20U)
#define XSPI_ERRSTAT_FRAD4ACC_SHIFT              (5U)
#define XSPI_ERRSTAT_FRAD4ACC_WIDTH              (1U)
#define XSPI_ERRSTAT_FRAD4ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD4ACC_SHIFT)) & XSPI_ERRSTAT_FRAD4ACC_MASK)

#define XSPI_ERRSTAT_FRAD5ACC_MASK               (0x40U)
#define XSPI_ERRSTAT_FRAD5ACC_SHIFT              (6U)
#define XSPI_ERRSTAT_FRAD5ACC_WIDTH              (1U)
#define XSPI_ERRSTAT_FRAD5ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD5ACC_SHIFT)) & XSPI_ERRSTAT_FRAD5ACC_MASK)

#define XSPI_ERRSTAT_FRAD6ACC_MASK               (0x80U)
#define XSPI_ERRSTAT_FRAD6ACC_SHIFT              (7U)
#define XSPI_ERRSTAT_FRAD6ACC_WIDTH              (1U)
#define XSPI_ERRSTAT_FRAD6ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD6ACC_SHIFT)) & XSPI_ERRSTAT_FRAD6ACC_MASK)

#define XSPI_ERRSTAT_FRAD7ACC_MASK               (0x100U)
#define XSPI_ERRSTAT_FRAD7ACC_SHIFT              (8U)
#define XSPI_ERRSTAT_FRAD7ACC_WIDTH              (1U)
#define XSPI_ERRSTAT_FRAD7ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD7ACC_SHIFT)) & XSPI_ERRSTAT_FRAD7ACC_MASK)

#define XSPI_ERRSTAT_IPS_ERR_MASK                (0x200U)
#define XSPI_ERRSTAT_IPS_ERR_SHIFT               (9U)
#define XSPI_ERRSTAT_IPS_ERR_WIDTH               (1U)
#define XSPI_ERRSTAT_IPS_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_IPS_ERR_SHIFT)) & XSPI_ERRSTAT_IPS_ERR_MASK)

#define XSPI_ERRSTAT_TG0SFAR_MASK                (0x400U)
#define XSPI_ERRSTAT_TG0SFAR_SHIFT               (10U)
#define XSPI_ERRSTAT_TG0SFAR_WIDTH               (1U)
#define XSPI_ERRSTAT_TG0SFAR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_TG0SFAR_SHIFT)) & XSPI_ERRSTAT_TG0SFAR_MASK)

#define XSPI_ERRSTAT_TG1SFAR_MASK                (0x800U)
#define XSPI_ERRSTAT_TG1SFAR_SHIFT               (11U)
#define XSPI_ERRSTAT_TG1SFAR_WIDTH               (1U)
#define XSPI_ERRSTAT_TG1SFAR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_TG1SFAR_SHIFT)) & XSPI_ERRSTAT_TG1SFAR_MASK)

#define XSPI_ERRSTAT_TG0IPCR_MASK                (0x1000U)
#define XSPI_ERRSTAT_TG0IPCR_SHIFT               (12U)
#define XSPI_ERRSTAT_TG0IPCR_WIDTH               (1U)
#define XSPI_ERRSTAT_TG0IPCR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_TG0IPCR_SHIFT)) & XSPI_ERRSTAT_TG0IPCR_MASK)

#define XSPI_ERRSTAT_TG1IPCR_MASK                (0x2000U)
#define XSPI_ERRSTAT_TG1IPCR_SHIFT               (13U)
#define XSPI_ERRSTAT_TG1IPCR_WIDTH               (1U)
#define XSPI_ERRSTAT_TG1IPCR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_TG1IPCR_SHIFT)) & XSPI_ERRSTAT_TG1IPCR_MASK)

#define XSPI_ERRSTAT_TO_ERR_MASK                 (0x4000U)
#define XSPI_ERRSTAT_TO_ERR_SHIFT                (14U)
#define XSPI_ERRSTAT_TO_ERR_WIDTH                (1U)
#define XSPI_ERRSTAT_TO_ERR(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_TO_ERR_SHIFT)) & XSPI_ERRSTAT_TO_ERR_MASK)

#define XSPI_ERRSTAT_ARB_WIN_MASK                (0x10000000U)
#define XSPI_ERRSTAT_ARB_WIN_SHIFT               (28U)
#define XSPI_ERRSTAT_ARB_WIN_WIDTH               (1U)
#define XSPI_ERRSTAT_ARB_WIN(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_ARB_WIN_SHIFT)) & XSPI_ERRSTAT_ARB_WIN_MASK)

#define XSPI_ERRSTAT_ARB_LOCK_TO_MASK            (0x20000000U)
#define XSPI_ERRSTAT_ARB_LOCK_TO_SHIFT           (29U)
#define XSPI_ERRSTAT_ARB_LOCK_TO_WIDTH           (1U)
#define XSPI_ERRSTAT_ARB_LOCK_TO(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_ARB_LOCK_TO_SHIFT)) & XSPI_ERRSTAT_ARB_LOCK_TO_MASK)

#define XSPI_ERRSTAT_LOCK_ERR_MASK               (0x40000000U)
#define XSPI_ERRSTAT_LOCK_ERR_SHIFT              (30U)
#define XSPI_ERRSTAT_LOCK_ERR_WIDTH              (1U)
#define XSPI_ERRSTAT_LOCK_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_LOCK_ERR_SHIFT)) & XSPI_ERRSTAT_LOCK_ERR_MASK)
/*! @} */

/*! @name INT_EN - Interrupt Enable */
/*! @{ */

#define XSPI_INT_EN_FRADMTCH_MASK                (0x1U)
#define XSPI_INT_EN_FRADMTCH_SHIFT               (0U)
#define XSPI_INT_EN_FRADMTCH_WIDTH               (1U)
#define XSPI_INT_EN_FRADMTCH(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRADMTCH_SHIFT)) & XSPI_INT_EN_FRADMTCH_MASK)

#define XSPI_INT_EN_FRAD0ACC_MASK                (0x2U)
#define XSPI_INT_EN_FRAD0ACC_SHIFT               (1U)
#define XSPI_INT_EN_FRAD0ACC_WIDTH               (1U)
#define XSPI_INT_EN_FRAD0ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD0ACC_SHIFT)) & XSPI_INT_EN_FRAD0ACC_MASK)

#define XSPI_INT_EN_FRAD1ACC_MASK                (0x4U)
#define XSPI_INT_EN_FRAD1ACC_SHIFT               (2U)
#define XSPI_INT_EN_FRAD1ACC_WIDTH               (1U)
#define XSPI_INT_EN_FRAD1ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD1ACC_SHIFT)) & XSPI_INT_EN_FRAD1ACC_MASK)

#define XSPI_INT_EN_FRAD2ACC_MASK                (0x8U)
#define XSPI_INT_EN_FRAD2ACC_SHIFT               (3U)
#define XSPI_INT_EN_FRAD2ACC_WIDTH               (1U)
#define XSPI_INT_EN_FRAD2ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD2ACC_SHIFT)) & XSPI_INT_EN_FRAD2ACC_MASK)

#define XSPI_INT_EN_FRAD3ACC_MASK                (0x10U)
#define XSPI_INT_EN_FRAD3ACC_SHIFT               (4U)
#define XSPI_INT_EN_FRAD3ACC_WIDTH               (1U)
#define XSPI_INT_EN_FRAD3ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD3ACC_SHIFT)) & XSPI_INT_EN_FRAD3ACC_MASK)

#define XSPI_INT_EN_FRAD4ACC_MASK                (0x20U)
#define XSPI_INT_EN_FRAD4ACC_SHIFT               (5U)
#define XSPI_INT_EN_FRAD4ACC_WIDTH               (1U)
#define XSPI_INT_EN_FRAD4ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD4ACC_SHIFT)) & XSPI_INT_EN_FRAD4ACC_MASK)

#define XSPI_INT_EN_FRAD5ACC_MASK                (0x40U)
#define XSPI_INT_EN_FRAD5ACC_SHIFT               (6U)
#define XSPI_INT_EN_FRAD5ACC_WIDTH               (1U)
#define XSPI_INT_EN_FRAD5ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD5ACC_SHIFT)) & XSPI_INT_EN_FRAD5ACC_MASK)

#define XSPI_INT_EN_FRAD6ACC_MASK                (0x80U)
#define XSPI_INT_EN_FRAD6ACC_SHIFT               (7U)
#define XSPI_INT_EN_FRAD6ACC_WIDTH               (1U)
#define XSPI_INT_EN_FRAD6ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD6ACC_SHIFT)) & XSPI_INT_EN_FRAD6ACC_MASK)

#define XSPI_INT_EN_FRAD7ACC_MASK                (0x100U)
#define XSPI_INT_EN_FRAD7ACC_SHIFT               (8U)
#define XSPI_INT_EN_FRAD7ACC_WIDTH               (1U)
#define XSPI_INT_EN_FRAD7ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD7ACC_SHIFT)) & XSPI_INT_EN_FRAD7ACC_MASK)

#define XSPI_INT_EN_IPS_ERR_MASK                 (0x200U)
#define XSPI_INT_EN_IPS_ERR_SHIFT                (9U)
#define XSPI_INT_EN_IPS_ERR_WIDTH                (1U)
#define XSPI_INT_EN_IPS_ERR(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_IPS_ERR_SHIFT)) & XSPI_INT_EN_IPS_ERR_MASK)

#define XSPI_INT_EN_TG0SFAR_MASK                 (0x400U)
#define XSPI_INT_EN_TG0SFAR_SHIFT                (10U)
#define XSPI_INT_EN_TG0SFAR_WIDTH                (1U)
#define XSPI_INT_EN_TG0SFAR(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_TG0SFAR_SHIFT)) & XSPI_INT_EN_TG0SFAR_MASK)

#define XSPI_INT_EN_TG1SFAR_MASK                 (0x800U)
#define XSPI_INT_EN_TG1SFAR_SHIFT                (11U)
#define XSPI_INT_EN_TG1SFAR_WIDTH                (1U)
#define XSPI_INT_EN_TG1SFAR(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_TG1SFAR_SHIFT)) & XSPI_INT_EN_TG1SFAR_MASK)

#define XSPI_INT_EN_TG0IPCR_MASK                 (0x1000U)
#define XSPI_INT_EN_TG0IPCR_SHIFT                (12U)
#define XSPI_INT_EN_TG0IPCR_WIDTH                (1U)
#define XSPI_INT_EN_TG0IPCR(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_TG0IPCR_SHIFT)) & XSPI_INT_EN_TG0IPCR_MASK)

#define XSPI_INT_EN_TG1IPCR_MASK                 (0x2000U)
#define XSPI_INT_EN_TG1IPCR_SHIFT                (13U)
#define XSPI_INT_EN_TG1IPCR_WIDTH                (1U)
#define XSPI_INT_EN_TG1IPCR(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_TG1IPCR_SHIFT)) & XSPI_INT_EN_TG1IPCR_MASK)

#define XSPI_INT_EN_TO_ERR_MASK                  (0x4000U)
#define XSPI_INT_EN_TO_ERR_SHIFT                 (14U)
#define XSPI_INT_EN_TO_ERR_WIDTH                 (1U)
#define XSPI_INT_EN_TO_ERR(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_TO_ERR_SHIFT)) & XSPI_INT_EN_TO_ERR_MASK)

#define XSPI_INT_EN_ARB_WIN_IE_MASK              (0x10000000U)
#define XSPI_INT_EN_ARB_WIN_IE_SHIFT             (28U)
#define XSPI_INT_EN_ARB_WIN_IE_WIDTH             (1U)
#define XSPI_INT_EN_ARB_WIN_IE(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_ARB_WIN_IE_SHIFT)) & XSPI_INT_EN_ARB_WIN_IE_MASK)

#define XSPI_INT_EN_ARB_TO_IE_MASK               (0x20000000U)
#define XSPI_INT_EN_ARB_TO_IE_SHIFT              (29U)
#define XSPI_INT_EN_ARB_TO_IE_WIDTH              (1U)
#define XSPI_INT_EN_ARB_TO_IE(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_ARB_TO_IE_SHIFT)) & XSPI_INT_EN_ARB_TO_IE_MASK)

#define XSPI_INT_EN_LCK_ERR_IE_MASK              (0x40000000U)
#define XSPI_INT_EN_LCK_ERR_IE_SHIFT             (30U)
#define XSPI_INT_EN_LCK_ERR_IE_WIDTH             (1U)
#define XSPI_INT_EN_LCK_ERR_IE(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_LCK_ERR_IE_SHIFT)) & XSPI_INT_EN_LCK_ERR_IE_MASK)

#define XSPI_INT_EN_LCK_MASK                     (0x80000000U)
#define XSPI_INT_EN_LCK_SHIFT                    (31U)
#define XSPI_INT_EN_LCK_WIDTH                    (1U)
#define XSPI_INT_EN_LCK(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_LCK_SHIFT)) & XSPI_INT_EN_LCK_MASK)
/*! @} */

/*! @name SFP_TG_IPCR - IP Configuration */
/*! @{ */

#define XSPI_SFP_TG_IPCR_IDATSZ_MASK             (0xFFFFU)
#define XSPI_SFP_TG_IPCR_IDATSZ_SHIFT            (0U)
#define XSPI_SFP_TG_IPCR_IDATSZ_WIDTH            (16U)
#define XSPI_SFP_TG_IPCR_IDATSZ(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_IPCR_IDATSZ_SHIFT)) & XSPI_SFP_TG_IPCR_IDATSZ_MASK)

#define XSPI_SFP_TG_IPCR_ADDRTRD_MASK            (0x40000U)
#define XSPI_SFP_TG_IPCR_ADDRTRD_SHIFT           (18U)
#define XSPI_SFP_TG_IPCR_ADDRTRD_WIDTH           (1U)
#define XSPI_SFP_TG_IPCR_ADDRTRD(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_IPCR_ADDRTRD_SHIFT)) & XSPI_SFP_TG_IPCR_ADDRTRD_MASK)

#define XSPI_SFP_TG_IPCR_ARB_LOCK_MASK           (0x400000U)
#define XSPI_SFP_TG_IPCR_ARB_LOCK_SHIFT          (22U)
#define XSPI_SFP_TG_IPCR_ARB_LOCK_WIDTH          (1U)
#define XSPI_SFP_TG_IPCR_ARB_LOCK(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_IPCR_ARB_LOCK_SHIFT)) & XSPI_SFP_TG_IPCR_ARB_LOCK_MASK)

#define XSPI_SFP_TG_IPCR_ARB_UNLOCK_MASK         (0x800000U)
#define XSPI_SFP_TG_IPCR_ARB_UNLOCK_SHIFT        (23U)
#define XSPI_SFP_TG_IPCR_ARB_UNLOCK_WIDTH        (1U)
#define XSPI_SFP_TG_IPCR_ARB_UNLOCK(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_IPCR_ARB_UNLOCK_SHIFT)) & XSPI_SFP_TG_IPCR_ARB_UNLOCK_MASK)

#define XSPI_SFP_TG_IPCR_SEQID_MASK              (0xF000000U)
#define XSPI_SFP_TG_IPCR_SEQID_SHIFT             (24U)
#define XSPI_SFP_TG_IPCR_SEQID_WIDTH             (4U)
#define XSPI_SFP_TG_IPCR_SEQID(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_IPCR_SEQID_SHIFT)) & XSPI_SFP_TG_IPCR_SEQID_MASK)
/*! @} */

/*! @name SFP_TG_SFAR - Serial Flash Memory Address */
/*! @{ */

#define XSPI_SFP_TG_SFAR_SFADR_MASK              (0xFFFFFFFFU)
#define XSPI_SFP_TG_SFAR_SFADR_SHIFT             (0U)
#define XSPI_SFP_TG_SFAR_SFADR_WIDTH             (32U)
#define XSPI_SFP_TG_SFAR_SFADR(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_SFAR_SFADR_SHIFT)) & XSPI_SFP_TG_SFAR_SFADR_MASK)
/*! @} */

/*! @name SFP_LUT_EN - LUT Access Enable */
/*! @{ */

#define XSPI_SFP_LUT_EN_LUT_SEQ0_EN_MASK         (0x1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ0_EN_SHIFT        (0U)
#define XSPI_SFP_LUT_EN_LUT_SEQ0_EN_WIDTH        (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ0_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ0_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ0_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ1_EN_MASK         (0x2U)
#define XSPI_SFP_LUT_EN_LUT_SEQ1_EN_SHIFT        (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ1_EN_WIDTH        (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ1_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ1_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ1_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ2_EN_MASK         (0x4U)
#define XSPI_SFP_LUT_EN_LUT_SEQ2_EN_SHIFT        (2U)
#define XSPI_SFP_LUT_EN_LUT_SEQ2_EN_WIDTH        (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ2_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ2_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ2_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ3_EN_MASK         (0x8U)
#define XSPI_SFP_LUT_EN_LUT_SEQ3_EN_SHIFT        (3U)
#define XSPI_SFP_LUT_EN_LUT_SEQ3_EN_WIDTH        (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ3_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ3_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ3_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ4_EN_MASK         (0x10U)
#define XSPI_SFP_LUT_EN_LUT_SEQ4_EN_SHIFT        (4U)
#define XSPI_SFP_LUT_EN_LUT_SEQ4_EN_WIDTH        (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ4_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ4_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ4_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ5_EN_MASK         (0x20U)
#define XSPI_SFP_LUT_EN_LUT_SEQ5_EN_SHIFT        (5U)
#define XSPI_SFP_LUT_EN_LUT_SEQ5_EN_WIDTH        (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ5_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ5_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ5_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ6_EN_MASK         (0x40U)
#define XSPI_SFP_LUT_EN_LUT_SEQ6_EN_SHIFT        (6U)
#define XSPI_SFP_LUT_EN_LUT_SEQ6_EN_WIDTH        (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ6_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ6_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ6_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ7_EN_MASK         (0x80U)
#define XSPI_SFP_LUT_EN_LUT_SEQ7_EN_SHIFT        (7U)
#define XSPI_SFP_LUT_EN_LUT_SEQ7_EN_WIDTH        (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ7_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ7_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ7_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ8_EN_MASK         (0x100U)
#define XSPI_SFP_LUT_EN_LUT_SEQ8_EN_SHIFT        (8U)
#define XSPI_SFP_LUT_EN_LUT_SEQ8_EN_WIDTH        (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ8_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ8_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ8_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ9_EN_MASK         (0x200U)
#define XSPI_SFP_LUT_EN_LUT_SEQ9_EN_SHIFT        (9U)
#define XSPI_SFP_LUT_EN_LUT_SEQ9_EN_WIDTH        (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ9_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ9_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ9_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ10_EN_MASK        (0x400U)
#define XSPI_SFP_LUT_EN_LUT_SEQ10_EN_SHIFT       (10U)
#define XSPI_SFP_LUT_EN_LUT_SEQ10_EN_WIDTH       (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ10_EN(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ10_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ10_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ11_EN_MASK        (0x800U)
#define XSPI_SFP_LUT_EN_LUT_SEQ11_EN_SHIFT       (11U)
#define XSPI_SFP_LUT_EN_LUT_SEQ11_EN_WIDTH       (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ11_EN(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ11_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ11_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ12_EN_MASK        (0x1000U)
#define XSPI_SFP_LUT_EN_LUT_SEQ12_EN_SHIFT       (12U)
#define XSPI_SFP_LUT_EN_LUT_SEQ12_EN_WIDTH       (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ12_EN(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ12_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ12_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ13_EN_MASK        (0x2000U)
#define XSPI_SFP_LUT_EN_LUT_SEQ13_EN_SHIFT       (13U)
#define XSPI_SFP_LUT_EN_LUT_SEQ13_EN_WIDTH       (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ13_EN(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ13_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ13_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ14_EN_MASK        (0x4000U)
#define XSPI_SFP_LUT_EN_LUT_SEQ14_EN_SHIFT       (14U)
#define XSPI_SFP_LUT_EN_LUT_SEQ14_EN_WIDTH       (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ14_EN(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ14_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ14_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ15_EN_MASK        (0x8000U)
#define XSPI_SFP_LUT_EN_LUT_SEQ15_EN_SHIFT       (15U)
#define XSPI_SFP_LUT_EN_LUT_SEQ15_EN_WIDTH       (1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ15_EN(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ15_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ15_EN_MASK)

#define XSPI_SFP_LUT_EN_LOCK_MASK                (0x80000000U)
#define XSPI_SFP_LUT_EN_LOCK_SHIFT               (31U)
#define XSPI_SFP_LUT_EN_LOCK_WIDTH               (1U)
#define XSPI_SFP_LUT_EN_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LOCK_SHIFT)) & XSPI_SFP_LUT_EN_LOCK_MASK)
/*! @} */

/*! @name SFP_LOCK_ERR_ADDR - SFP Lock Error Address */
/*! @{ */

#define XSPI_SFP_LOCK_ERR_ADDR_ADDRW_MASK        (0x7FFFU)
#define XSPI_SFP_LOCK_ERR_ADDR_ADDRW_SHIFT       (0U)
#define XSPI_SFP_LOCK_ERR_ADDR_ADDRW_WIDTH       (15U)
#define XSPI_SFP_LOCK_ERR_ADDR_ADDRW(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LOCK_ERR_ADDR_ADDRW_SHIFT)) & XSPI_SFP_LOCK_ERR_ADDR_ADDRW_MASK)
/*! @} */

/*! @name SFP_TG_SUB_IPCR - IP Configuration */
/*! @{ */

#define XSPI_SFP_TG_SUB_IPCR_IDATSZ_MASK         (0xFFFFU)
#define XSPI_SFP_TG_SUB_IPCR_IDATSZ_SHIFT        (0U)
#define XSPI_SFP_TG_SUB_IPCR_IDATSZ_WIDTH        (16U)
#define XSPI_SFP_TG_SUB_IPCR_IDATSZ(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_SUB_IPCR_IDATSZ_SHIFT)) & XSPI_SFP_TG_SUB_IPCR_IDATSZ_MASK)

#define XSPI_SFP_TG_SUB_IPCR_ADDRTRD_MASK        (0x40000U)
#define XSPI_SFP_TG_SUB_IPCR_ADDRTRD_SHIFT       (18U)
#define XSPI_SFP_TG_SUB_IPCR_ADDRTRD_WIDTH       (1U)
#define XSPI_SFP_TG_SUB_IPCR_ADDRTRD(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_SUB_IPCR_ADDRTRD_SHIFT)) & XSPI_SFP_TG_SUB_IPCR_ADDRTRD_MASK)

#define XSPI_SFP_TG_SUB_IPCR_ARB_LOCK_MASK       (0x400000U)
#define XSPI_SFP_TG_SUB_IPCR_ARB_LOCK_SHIFT      (22U)
#define XSPI_SFP_TG_SUB_IPCR_ARB_LOCK_WIDTH      (1U)
#define XSPI_SFP_TG_SUB_IPCR_ARB_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_SUB_IPCR_ARB_LOCK_SHIFT)) & XSPI_SFP_TG_SUB_IPCR_ARB_LOCK_MASK)

#define XSPI_SFP_TG_SUB_IPCR_ARB_UNLOCK_MASK     (0x800000U)
#define XSPI_SFP_TG_SUB_IPCR_ARB_UNLOCK_SHIFT    (23U)
#define XSPI_SFP_TG_SUB_IPCR_ARB_UNLOCK_WIDTH    (1U)
#define XSPI_SFP_TG_SUB_IPCR_ARB_UNLOCK(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_SUB_IPCR_ARB_UNLOCK_SHIFT)) & XSPI_SFP_TG_SUB_IPCR_ARB_UNLOCK_MASK)

#define XSPI_SFP_TG_SUB_IPCR_SEQID_MASK          (0xF000000U)
#define XSPI_SFP_TG_SUB_IPCR_SEQID_SHIFT         (24U)
#define XSPI_SFP_TG_SUB_IPCR_SEQID_WIDTH         (4U)
#define XSPI_SFP_TG_SUB_IPCR_SEQID(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_SUB_IPCR_SEQID_SHIFT)) & XSPI_SFP_TG_SUB_IPCR_SEQID_MASK)
/*! @} */

/*! @name SFP_TG_SUB_SFAR - Serial Flash Memory Address */
/*! @{ */

#define XSPI_SFP_TG_SUB_SFAR_SFADR_MASK          (0xFFFFFFFFU)
#define XSPI_SFP_TG_SUB_SFAR_SFADR_SHIFT         (0U)
#define XSPI_SFP_TG_SUB_SFAR_SFADR_WIDTH         (32U)
#define XSPI_SFP_TG_SUB_SFAR_SFADR(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_SUB_SFAR_SFADR_SHIFT)) & XSPI_SFP_TG_SUB_SFAR_SFADR_MASK)
/*! @} */

/*! @name TGSFAR_SUB - Target Group SFAR Address */
/*! @{ */

#define XSPI_TGSFAR_SUB_SFARADDR_MASK            (0xFFFFFFFFU)
#define XSPI_TGSFAR_SUB_SFARADDR_SHIFT           (0U)
#define XSPI_TGSFAR_SUB_SFARADDR_WIDTH           (32U)
#define XSPI_TGSFAR_SUB_SFARADDR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFAR_SUB_SFARADDR_SHIFT)) & XSPI_TGSFAR_SUB_SFARADDR_MASK)
/*! @} */

/*! @name TGSFARS_SUB - Target Group SFAR Status */
/*! @{ */

#define XSPI_TGSFARS_SUB_TG_MID_MASK             (0x3FU)
#define XSPI_TGSFARS_SUB_TG_MID_SHIFT            (0U)
#define XSPI_TGSFARS_SUB_TG_MID_WIDTH            (6U)
#define XSPI_TGSFARS_SUB_TG_MID(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_SUB_TG_MID_SHIFT)) & XSPI_TGSFARS_SUB_TG_MID_MASK)

#define XSPI_TGSFARS_SUB_SA_MASK                 (0x400U)
#define XSPI_TGSFARS_SUB_SA_SHIFT                (10U)
#define XSPI_TGSFARS_SUB_SA_WIDTH                (1U)
#define XSPI_TGSFARS_SUB_SA(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_SUB_SA_SHIFT)) & XSPI_TGSFARS_SUB_SA_MASK)

#define XSPI_TGSFARS_SUB_PA_MASK                 (0x1000U)
#define XSPI_TGSFARS_SUB_PA_SHIFT                (12U)
#define XSPI_TGSFARS_SUB_PA_WIDTH                (1U)
#define XSPI_TGSFARS_SUB_PA(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_SUB_PA_SHIFT)) & XSPI_TGSFARS_SUB_PA_MASK)

#define XSPI_TGSFARS_SUB_CLR_MASK                (0x20000000U)
#define XSPI_TGSFARS_SUB_CLR_SHIFT               (29U)
#define XSPI_TGSFARS_SUB_CLR_WIDTH               (1U)
#define XSPI_TGSFARS_SUB_CLR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_SUB_CLR_SHIFT)) & XSPI_TGSFARS_SUB_CLR_MASK)

#define XSPI_TGSFARS_SUB_ERR_MASK                (0x40000000U)
#define XSPI_TGSFARS_SUB_ERR_SHIFT               (30U)
#define XSPI_TGSFARS_SUB_ERR_WIDTH               (1U)
#define XSPI_TGSFARS_SUB_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_SUB_ERR_SHIFT)) & XSPI_TGSFARS_SUB_ERR_MASK)

#define XSPI_TGSFARS_SUB_VLD_MASK                (0x80000000U)
#define XSPI_TGSFARS_SUB_VLD_SHIFT               (31U)
#define XSPI_TGSFARS_SUB_VLD_WIDTH               (1U)
#define XSPI_TGSFARS_SUB_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_SUB_VLD_SHIFT)) & XSPI_TGSFARS_SUB_VLD_MASK)
/*! @} */

/*! @name TGIPCRS_SUB - Target Group n IP Configuration Status */
/*! @{ */

#define XSPI_TGIPCRS_SUB_IDATSZ_MASK             (0xFFFFU)
#define XSPI_TGIPCRS_SUB_IDATSZ_SHIFT            (0U)
#define XSPI_TGIPCRS_SUB_IDATSZ_WIDTH            (16U)
#define XSPI_TGIPCRS_SUB_IDATSZ(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_IDATSZ_SHIFT)) & XSPI_TGIPCRS_SUB_IDATSZ_MASK)

#define XSPI_TGIPCRS_SUB_SEQID_MASK              (0xF0000U)
#define XSPI_TGIPCRS_SUB_SEQID_SHIFT             (16U)
#define XSPI_TGIPCRS_SUB_SEQID_WIDTH             (4U)
#define XSPI_TGIPCRS_SUB_SEQID(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_SEQID_SHIFT)) & XSPI_TGIPCRS_SUB_SEQID_MASK)

#define XSPI_TGIPCRS_SUB_ARB_LOCK_MASK           (0x200000U)
#define XSPI_TGIPCRS_SUB_ARB_LOCK_SHIFT          (21U)
#define XSPI_TGIPCRS_SUB_ARB_LOCK_WIDTH          (1U)
#define XSPI_TGIPCRS_SUB_ARB_LOCK(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_ARB_LOCK_SHIFT)) & XSPI_TGIPCRS_SUB_ARB_LOCK_MASK)

#define XSPI_TGIPCRS_SUB_ARB_UNLOCK_MASK         (0x400000U)
#define XSPI_TGIPCRS_SUB_ARB_UNLOCK_SHIFT        (22U)
#define XSPI_TGIPCRS_SUB_ARB_UNLOCK_WIDTH        (1U)
#define XSPI_TGIPCRS_SUB_ARB_UNLOCK(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_ARB_UNLOCK_SHIFT)) & XSPI_TGIPCRS_SUB_ARB_UNLOCK_MASK)

#define XSPI_TGIPCRS_SUB_ADDRTRDS_MASK           (0x1000000U)
#define XSPI_TGIPCRS_SUB_ADDRTRDS_SHIFT          (24U)
#define XSPI_TGIPCRS_SUB_ADDRTRDS_WIDTH          (1U)
#define XSPI_TGIPCRS_SUB_ADDRTRDS(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_ADDRTRDS_SHIFT)) & XSPI_TGIPCRS_SUB_ADDRTRDS_MASK)

#define XSPI_TGIPCRS_SUB_CLR_MASK                (0x10000000U)
#define XSPI_TGIPCRS_SUB_CLR_SHIFT               (28U)
#define XSPI_TGIPCRS_SUB_CLR_WIDTH               (1U)
#define XSPI_TGIPCRS_SUB_CLR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_CLR_SHIFT)) & XSPI_TGIPCRS_SUB_CLR_MASK)

#define XSPI_TGIPCRS_SUB_ERR_MASK                (0x60000000U)
#define XSPI_TGIPCRS_SUB_ERR_SHIFT               (29U)
#define XSPI_TGIPCRS_SUB_ERR_WIDTH               (2U)
#define XSPI_TGIPCRS_SUB_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_ERR_SHIFT)) & XSPI_TGIPCRS_SUB_ERR_MASK)

#define XSPI_TGIPCRS_SUB_VLD_MASK                (0x80000000U)
#define XSPI_TGIPCRS_SUB_VLD_SHIFT               (31U)
#define XSPI_TGIPCRS_SUB_VLD_WIDTH               (1U)
#define XSPI_TGIPCRS_SUB_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_VLD_SHIFT)) & XSPI_TGIPCRS_SUB_VLD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group XSPI_Register_Masks */

/*!
 * @}
 */ /* end of group XSPI_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_XSPI_H_) */
