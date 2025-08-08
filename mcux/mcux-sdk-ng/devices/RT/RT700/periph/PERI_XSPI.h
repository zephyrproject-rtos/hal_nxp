/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XSPI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_XSPI.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for XSPI
 *
 * CMSIS Peripheral Access Layer for XSPI
 */

#if !defined(PERI_XSPI_H_)
#define PERI_XSPI_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- XSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XSPI_Peripheral_Access_Layer XSPI Peripheral Access Layer
 * @{
 */

/** XSPI - Size of Registers Arrays */
#define XSPI_BUFCR_COUNT                          4u
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
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __I  uint32_t IPCR;                              /**< IP Configuration, offset: 0x8 */
  __IO uint32_t FLSHCR;                            /**< Flash Memory Configuration, offset: 0xC */
  __IO uint32_t BUFCR[XSPI_BUFCR_COUNT];           /**< Buffer Configuration, array offset: 0x10, array step: 0x4 */
  __IO uint32_t BFGENCR;                           /**< Buffer Generic Configuration, offset: 0x20 */
  __IO uint32_t SOCCR;                             /**< SOC Configuration, offset: 0x24 */
       uint8_t RESERVED_1[8];
  __IO uint32_t BUFIND[XSPI_BUFIND_COUNT];         /**< Buffer 0 Top Index..Buffer 2 Top Index, array offset: 0x30, array step: 0x4 */
       uint8_t RESERVED_2[20];
  __IO uint32_t AWRCR;                             /**< AHB Write Configuration, offset: 0x50 */
       uint8_t RESERVED_3[12];
  __IO uint32_t DLLCR[XSPI_DLLCR_COUNT];           /**< DLL Flash Memory A Configuration, array offset: 0x60, array step: 0x4 */
       uint8_t RESERVED_4[156];
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
  __I  uint32_t AHB_RD_ERR_MID;                    /**< AHB Read Error Manager ID, offset: 0x4EC */
  __I  uint32_t SPNDST_ADDR;                       /**< Suspend Transaction Address, offset: 0x4F0 */
  __IO uint32_t PPWF_TCNT;                         /**< Page Program Wait Time Counter, offset: 0x4F4 */
  __IO uint32_t PPW_RDSR;                          /**< Page Program Wait Read Status, offset: 0x4F8 */
       uint8_t RESERVED_13[36];
  struct {                                         /* offset: 0x520, array step: 0x20 */
    __IO uint32_t IPEDCTXIV[XSPI_IPEDCTXXIV_IPEDCTXXIVY_COUNT];   /**< IPED Context Initial Vector, array offset: 0x520, array step: index*0x20, index2*0x4, available only on: XSPI0, XSPI1 (missing on XSPI2) */
    __IO uint32_t IPEDCTXSTART;                      /**< IPED Start Address Region, array offset: 0x528, array step: 0x20, available only on: XSPI0, XSPI1 (missing on XSPI2) */
    __IO uint32_t IPEDCTXEND;                        /**< IPED End Address Region, array offset: 0x52C, array step: 0x20, available only on: XSPI0, XSPI1 (missing on XSPI2) */
    __IO uint32_t IPEDCTXAAD[XSPI_IPEDCTXXIV_IPEDCTXXAADY_COUNT];   /**< IPED Context Additional Authentication Data, array offset: 0x530, array step: index*0x20, index2*0x4, available only on: XSPI0, XSPI1 (missing on XSPI2) */
         uint8_t RESERVED_0[8];
  } IPEDCTXXIV[XSPI_IPEDCTXXIV_COUNT];
  __IO uint32_t IPEDCTRL;                          /**< IPED Function Control, offset: 0x720, available only on: XSPI0, XSPI1 (missing on XSPI2) */
       uint8_t RESERVED_14[4];
  __IO uint32_t IPEDCTXCTRL[XSPI_IPEDCTXCTRLX_COUNT]; /**< IPED Context Control 0..IPED Context Control 1, array offset: 0x728, array step: 0x4, available only on: XSPI0, XSPI1 (missing on XSPI2) */
       uint8_t RESERVED_15[208];
  __IO uint32_t FRAD0_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x800 */
  __IO uint32_t FRAD0_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x804 */
  __IO uint32_t FRAD0_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x808 */
  __IO uint32_t FRAD0_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x80C */
  __I  uint32_t FRAD0_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x810 */
  __I  uint32_t FRAD0_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x814 */
       uint8_t RESERVED_16[8];
  __IO uint32_t FRAD1_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x820 */
  __IO uint32_t FRAD1_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x824 */
  __IO uint32_t FRAD1_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x828 */
  __IO uint32_t FRAD1_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x82C */
  __I  uint32_t FRAD1_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x830 */
  __I  uint32_t FRAD1_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x834 */
       uint8_t RESERVED_17[8];
  __IO uint32_t FRAD2_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x840 */
  __IO uint32_t FRAD2_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x844 */
  __IO uint32_t FRAD2_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x848 */
  __IO uint32_t FRAD2_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x84C */
  __I  uint32_t FRAD2_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x850 */
  __I  uint32_t FRAD2_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x854 */
       uint8_t RESERVED_18[8];
  __IO uint32_t FRAD3_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x860 */
  __IO uint32_t FRAD3_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x864 */
  __IO uint32_t FRAD3_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x868 */
  __IO uint32_t FRAD3_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x86C */
  __I  uint32_t FRAD3_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x870 */
  __I  uint32_t FRAD3_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x874 */
       uint8_t RESERVED_19[8];
  __IO uint32_t FRAD4_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x880 */
  __IO uint32_t FRAD4_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x884 */
  __IO uint32_t FRAD4_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x888 */
  __IO uint32_t FRAD4_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x88C */
  __I  uint32_t FRAD4_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x890 */
  __I  uint32_t FRAD4_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x894 */
       uint8_t RESERVED_20[8];
  __IO uint32_t FRAD5_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x8A0 */
  __IO uint32_t FRAD5_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x8A4 */
  __IO uint32_t FRAD5_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x8A8 */
  __IO uint32_t FRAD5_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x8AC */
  __I  uint32_t FRAD5_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x8B0 */
  __I  uint32_t FRAD5_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x8B4 */
       uint8_t RESERVED_21[8];
  __IO uint32_t FRAD6_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x8C0 */
  __IO uint32_t FRAD6_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x8C4 */
  __IO uint32_t FRAD6_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x8C8 */
  __IO uint32_t FRAD6_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x8CC */
  __I  uint32_t FRAD6_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x8D0 */
  __I  uint32_t FRAD6_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x8D4 */
       uint8_t RESERVED_22[8];
  __IO uint32_t FRAD7_WORD0;                       /**< Flash Region Word 0 - Start Address, offset: 0x8E0 */
  __IO uint32_t FRAD7_WORD1;                       /**< Flash Region Word 1 - End Address, offset: 0x8E4 */
  __IO uint32_t FRAD7_WORD2;                       /**< Flash Region Word 2 - Privileges, offset: 0x8E8 */
  __IO uint32_t FRAD7_WORD3;                       /**< Flash Region Word 3 - Lock Control, offset: 0x8EC */
  __I  uint32_t FRAD7_WORD4;                       /**< Flash Region Word 4 - Compare Address Status, offset: 0x8F0 */
  __I  uint32_t FRAD7_WORD5;                       /**< Flash Region Word 5 - Compare Status Data, offset: 0x8F4 */
       uint8_t RESERVED_23[4];
  __IO uint32_t SFP_ARB_TIMEOUT;                   /**< SFP Arbitration Lock Timeout Counter, offset: 0x8FC */
  __IO uint32_t TG0MDAD;                           /**< Target Group Manager Domain Access Descriptor, offset: 0x900 */
  __I  uint32_t TGSFAR;                            /**< Target Group SFAR Address, offset: 0x904 */
  __IO uint32_t TGSFARS;                           /**< Target Group SFAR Status, offset: 0x908 */
  __IO uint32_t TGIPCRS;                           /**< Target Group IP Configuration Status, offset: 0x90C */
  __IO uint32_t TG1MDAD;                           /**< Target Group Manager Domain Access Descriptor, offset: 0x910 */
       uint8_t RESERVED_24[12];
  __IO uint32_t MGC;                               /**< Manager Global Configuration, offset: 0x920 */
  __IO uint32_t MRC;                               /**< Manager Read Command, offset: 0x924 */
  __IO uint32_t MTO;                               /**< Manager Timeout, offset: 0x928 */
  __I  uint32_t FLSEQREQ;                          /**< Flash Sequence Request, offset: 0x92C */
  __I  uint32_t FSMSTAT;                           /**< FSM Status, offset: 0x930 */
  __IO uint32_t IPSERROR;                          /**< IPS Error, offset: 0x934 */
  __IO uint32_t ERRSTAT;                           /**< Error Status, offset: 0x938 */
  __IO uint32_t INT_EN;                            /**< Interrupt Enable, offset: 0x93C */
       uint8_t RESERVED_25[24];
  __IO uint32_t SFP_TG_IPCR;                       /**< IP Configuration, offset: 0x958 */
  __IO uint32_t SFP_TG_SFAR;                       /**< Serial Flash Memory Address, offset: 0x95C */
  __IO uint32_t SFP_LUT_EN[XSPI_SFP_LUT_EN_ARRAY_COUNT]; /**< LUT Access Enable, array offset: 0x960, array step: 0x4 */
       uint8_t RESERVED_26[276];
  __I  uint32_t SFP_LOCK_ERR_ADDR;                 /**< SFP Lock Error Address, offset: 0xA7C */
  struct {                                         /* offset: 0xA80, array step: 0x14 */
    __IO uint32_t SFP_TG_SUB_IPCR;                   /**< IP Configuration, array offset: 0xA80, array step: 0x14 */
    __IO uint32_t SFP_TG_SUB_SFAR;                   /**< Serial Flash Memory Address, array offset: 0xA84, array step: 0x14 */
    __I  uint32_t TGSFAR_SUB;                        /**< Target Group SFAR Address, array offset: 0xA88, array step: 0x14 */
    __IO uint32_t TGSFARS_SUB;                       /**< Target Group SFAR Status, array offset: 0xA8C, array step: 0x14 */
    __IO uint32_t TGIPCRS_SUB;                       /**< Target Group n IP Configuration Status, array offset: 0xA90, array step: 0x14 */
  } SUB_REG_MDAM_ARRAY[XSPI_SUB_REG_MDAM_ARRAY_COUNT];
} XSPI_Type;

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
/*! SWRSTSD - Software Reset for Serial Flash Memory Domain
 *  0b0..Deasserts reset
 *  0b1..Resets
 */
#define XSPI_MCR_SWRSTSD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_SWRSTSD_SHIFT)) & XSPI_MCR_SWRSTSD_MASK)

#define XSPI_MCR_SWRSTHD_MASK                    (0x2U)
#define XSPI_MCR_SWRSTHD_SHIFT                   (1U)
/*! SWRSTHD - Software Reset for AHB Domain
 *  0b0..Deasserts reset
 *  0b1..Resets
 */
#define XSPI_MCR_SWRSTHD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_SWRSTHD_SHIFT)) & XSPI_MCR_SWRSTHD_MASK)

#define XSPI_MCR_END_CFG_MASK                    (0xCU)
#define XSPI_MCR_END_CFG_SHIFT                   (2U)
/*! END_CFG - Byte Order
 *  0b00..64-bit BE
 *  0b01..32-bit LE
 *  0b10..32-bit BE
 *  0b11..64-bit LE
 */
#define XSPI_MCR_END_CFG(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_END_CFG_SHIFT)) & XSPI_MCR_END_CFG_MASK)

#define XSPI_MCR_DQS_OUT_EN_MASK                 (0x10U)
#define XSPI_MCR_DQS_OUT_EN_SHIFT                (4U)
/*! DQS_OUT_EN - DQS Output Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_MCR_DQS_OUT_EN(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_DQS_OUT_EN_SHIFT)) & XSPI_MCR_DQS_OUT_EN_MASK)

#define XSPI_MCR_DQS_LAT_EN_MASK                 (0x20U)
#define XSPI_MCR_DQS_LAT_EN_SHIFT                (5U)
/*! DQS_LAT_EN - DQS Latency Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_MCR_DQS_LAT_EN(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_DQS_LAT_EN_SHIFT)) & XSPI_MCR_DQS_LAT_EN_MASK)

#define XSPI_MCR_DQS_EN_MASK                     (0x40U)
#define XSPI_MCR_DQS_EN_SHIFT                    (6U)
/*! DQS_EN - DQS Enable
 *  0b0..Reserved
 *  0b1..Enables
 */
#define XSPI_MCR_DQS_EN(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_DQS_EN_SHIFT)) & XSPI_MCR_DQS_EN_MASK)

#define XSPI_MCR_DDR_EN_MASK                     (0x80U)
#define XSPI_MCR_DDR_EN_SHIFT                    (7U)
/*! DDR_EN - DDR Mode Enable
 *  0b0..2x clock disabled. Only SDR instructions processed
 *  0b1..2x clock enabled. Both SDR and DDR instructions processed
 */
#define XSPI_MCR_DDR_EN(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_DDR_EN_SHIFT)) & XSPI_MCR_DDR_EN_MASK)

#define XSPI_MCR_VAR_LAT_EN_MASK                 (0x100U)
#define XSPI_MCR_VAR_LAT_EN_SHIFT                (8U)
/*! VAR_LAT_EN - Variable Latency Enable
 *  0b0..Fixed latency
 *  0b1..Additional initial latency
 */
#define XSPI_MCR_VAR_LAT_EN(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_VAR_LAT_EN_SHIFT)) & XSPI_MCR_VAR_LAT_EN_MASK)

#define XSPI_MCR_IPS_TG_RST_MASK                 (0x200U)
#define XSPI_MCR_IPS_TG_RST_SHIFT                (9U)
/*! IPS_TG_RST - Software Reset for IPS Target Group Queue
 *  0b0..No action
 *  0b0..No action
 *  0b1..Reset of IPS TG queue is in progress if is having TG Grant
 *  0b1..Resets
 */
#define XSPI_MCR_IPS_TG_RST(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_IPS_TG_RST_SHIFT)) & XSPI_MCR_IPS_TG_RST_MASK)

#define XSPI_MCR_CLR_RXF_MASK                    (0x400U)
#define XSPI_MCR_CLR_RXF_SHIFT                   (10U)
/*! CLR_RXF - Clear RX FIFO
 *  0b0..No action. Always reads 0.
 *  0b1..Clears buffer and returns pointers to 0
 */
#define XSPI_MCR_CLR_RXF(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_CLR_RXF_SHIFT)) & XSPI_MCR_CLR_RXF_MASK)

#define XSPI_MCR_CLR_TXF_MASK                    (0x800U)
#define XSPI_MCR_CLR_TXF_SHIFT                   (11U)
/*! CLR_TXF - Clear TX FIFO
 *  0b0..No action. Always reads 0.
 *  0b1..Clears buffer and returns pointers to 0
 */
#define XSPI_MCR_CLR_TXF(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_CLR_TXF_SHIFT)) & XSPI_MCR_CLR_TXF_MASK)

#define XSPI_MCR_DLPEN_MASK                      (0x1000U)
#define XSPI_MCR_DLPEN_SHIFT                     (12U)
/*! DLPEN - Data Learning Pattern Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_MCR_DLPEN(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_DLPEN_SHIFT)) & XSPI_MCR_DLPEN_MASK)

#define XSPI_MCR_MDIS_MASK                       (0x4000U)
#define XSPI_MCR_MDIS_SHIFT                      (14U)
/*! MDIS - Module Disable
 *  0b0..Enables clocks
 *  0b1..Allows external logic to disable clocks
 */
#define XSPI_MCR_MDIS(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_MDIS_SHIFT)) & XSPI_MCR_MDIS_MASK)

#define XSPI_MCR_DOZE_MASK                       (0x8000U)
#define XSPI_MCR_DOZE_SHIFT                      (15U)
/*! DOZE - Doze Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_MCR_DOZE(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_DOZE_SHIFT)) & XSPI_MCR_DOZE_MASK)

#define XSPI_MCR_ISD2FA_MASK                     (0x10000U)
#define XSPI_MCR_ISD2FA_SHIFT                    (16U)
/*! ISD2FA - Idle Signal Drive IOFA[2] Flash Memory A
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define XSPI_MCR_ISD2FA(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_ISD2FA_SHIFT)) & XSPI_MCR_ISD2FA_MASK)

#define XSPI_MCR_ISD3FA_MASK                     (0x20000U)
#define XSPI_MCR_ISD3FA_SHIFT                    (17U)
/*! ISD3FA - Idle Signal Drive IOFA[3] Flash Memory A
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define XSPI_MCR_ISD3FA(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_ISD3FA_SHIFT)) & XSPI_MCR_ISD3FA_MASK)

#define XSPI_MCR_X16_DB_CA_EN_MASK               (0x100000U)
#define XSPI_MCR_X16_DB_CA_EN_SHIFT              (20U)
/*! X16_DB_CA_EN - X16 Databus Enable
 *  0b0..Data only
 *  0b1..Address and command information along with data
 */
#define XSPI_MCR_X16_DB_CA_EN(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_X16_DB_CA_EN_SHIFT)) & XSPI_MCR_X16_DB_CA_EN_MASK)

#define XSPI_MCR_X16_EN_MASK                     (0x200000U)
#define XSPI_MCR_X16_EN_SHIFT                    (21U)
/*! X16_EN - X16 Mode Enable
 *  0b0..Disables (x8, x4, x2, x1 modes remain enabled)
 *  0b1..Enables
 */
#define XSPI_MCR_X16_EN(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_X16_EN_SHIFT)) & XSPI_MCR_X16_EN_MASK)

#define XSPI_MCR_DQS_FA_SEL_MASK                 (0x3000000U)
#define XSPI_MCR_DQS_FA_SEL_SHIFT                (24U)
/*! DQS_FA_SEL - DQS Clock For Sampling Read Data Flash Memory A
 *  0b00..
 *  0b01..Dummy pad loopback
 *  0b10..DQS pad loopback
 *  0b11..External DQS
 */
#define XSPI_MCR_DQS_FA_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_DQS_FA_SEL_SHIFT)) & XSPI_MCR_DQS_FA_SEL_MASK)

#define XSPI_MCR_CKN_FA_EN_MASK                  (0x4000000U)
#define XSPI_MCR_CKN_FA_EN_SHIFT                 (26U)
/*! CKN_FA_EN - CKN Pad For Flash Memory A
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_MCR_CKN_FA_EN(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_MCR_CKN_FA_EN_SHIFT)) & XSPI_MCR_CKN_FA_EN_MASK)
/*! @} */

/*! @name IPCR - IP Configuration */
/*! @{ */

#define XSPI_IPCR_IDATSZ_MASK                    (0xFFFFU)
#define XSPI_IPCR_IDATSZ_SHIFT                   (0U)
/*! IDATSZ - IP Data Transfer Size */
#define XSPI_IPCR_IDATSZ(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_IPCR_IDATSZ_SHIFT)) & XSPI_IPCR_IDATSZ_MASK)

#define XSPI_IPCR_SEQID_MASK                     (0xF000000U)
#define XSPI_IPCR_SEQID_SHIFT                    (24U)
/*! SEQID - LUT Sequence ID */
#define XSPI_IPCR_SEQID(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_IPCR_SEQID_SHIFT)) & XSPI_IPCR_SEQID_MASK)
/*! @} */

/*! @name FLSHCR - Flash Memory Configuration */
/*! @{ */

#define XSPI_FLSHCR_TCSS_MASK                    (0xFU)
#define XSPI_FLSHCR_TCSS_SHIFT                   (0U)
/*! TCSS - Serial Flash Memory CS Setup Time */
#define XSPI_FLSHCR_TCSS(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FLSHCR_TCSS_SHIFT)) & XSPI_FLSHCR_TCSS_MASK)

#define XSPI_FLSHCR_TCSH_MASK                    (0xF00U)
#define XSPI_FLSHCR_TCSH_SHIFT                   (8U)
/*! TCSH - Serial Flash Memory CS Hold Time */
#define XSPI_FLSHCR_TCSH(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FLSHCR_TCSH_SHIFT)) & XSPI_FLSHCR_TCSH_MASK)

#define XSPI_FLSHCR_TDH_MASK                     (0x30000U)
#define XSPI_FLSHCR_TDH_SHIFT                    (16U)
/*! TDH - Serial Flash Memory Data in Hold Time
 *  0b00..Posedge of XSPI internal reference clock
 *  0b01..2x serial flash memory half clock
 */
#define XSPI_FLSHCR_TDH(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_FLSHCR_TDH_SHIFT)) & XSPI_FLSHCR_TDH_MASK)
/*! @} */

/*! @name BUFCR - Buffer Configuration */
/*! @{ */

#define XSPI_BUFCR_MSTRID_MASK                   (0x1FU)
#define XSPI_BUFCR_MSTRID_SHIFT                  (0U)
/*! MSTRID - Manager ID */
#define XSPI_BUFCR_MSTRID(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_BUFCR_MSTRID_SHIFT)) & XSPI_BUFCR_MSTRID_MASK)

#define XSPI_BUFCR_ADATSZ_MASK                   (0x3FF00U)
#define XSPI_BUFCR_ADATSZ_SHIFT                  (8U)
/*! ADATSZ - AHB Data Transfer Size */
#define XSPI_BUFCR_ADATSZ(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_BUFCR_ADATSZ_SHIFT)) & XSPI_BUFCR_ADATSZ_MASK)

#define XSPI_BUFCR_SUBBUF0_DIV_MASK              (0xE00000U)
#define XSPI_BUFCR_SUBBUF0_DIV_SHIFT             (21U)
/*! SUBBUF0_DIV - Sub-Buffer Division Factor
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 */
#define XSPI_BUFCR_SUBBUF0_DIV(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_BUFCR_SUBBUF0_DIV_SHIFT)) & XSPI_BUFCR_SUBBUF0_DIV_MASK)

#define XSPI_BUFCR_SUBBUF1_DIV_MASK              (0x7000000U)
#define XSPI_BUFCR_SUBBUF1_DIV_SHIFT             (24U)
/*! SUBBUF1_DIV - Sub-Buffer Division Factor
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 */
#define XSPI_BUFCR_SUBBUF1_DIV(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_BUFCR_SUBBUF1_DIV_SHIFT)) & XSPI_BUFCR_SUBBUF1_DIV_MASK)

#define XSPI_BUFCR_SUBBUF2_DIV_MASK              (0x38000000U)
#define XSPI_BUFCR_SUBBUF2_DIV_SHIFT             (27U)
/*! SUBBUF2_DIV - Sub-Buffer Division Factor
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 */
#define XSPI_BUFCR_SUBBUF2_DIV(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_BUFCR_SUBBUF2_DIV_SHIFT)) & XSPI_BUFCR_SUBBUF2_DIV_MASK)

#define XSPI_BUFCR_SUB_DIV_EN_MASK               (0x40000000U)
#define XSPI_BUFCR_SUB_DIV_EN_SHIFT              (30U)
/*! SUB_DIV_EN - Buffer Sub-Division Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_BUFCR_SUB_DIV_EN(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_BUFCR_SUB_DIV_EN_SHIFT)) & XSPI_BUFCR_SUB_DIV_EN_MASK)

#define XSPI_BUFCR_ALLMST_MASK                   (0x80000000U)
#define XSPI_BUFCR_ALLMST_SHIFT                  (31U)
/*! ALLMST - All Manager Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_BUFCR_ALLMST(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_BUFCR_ALLMST_SHIFT)) & XSPI_BUFCR_ALLMST_MASK)

#define XSPI_BUFCR_HP_EN_MASK                    (0x80000000U)
#define XSPI_BUFCR_HP_EN_SHIFT                   (31U)
/*! HP_EN - High Priority Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_BUFCR_HP_EN(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_BUFCR_HP_EN_SHIFT)) & XSPI_BUFCR_HP_EN_MASK)
/*! @} */

/*! @name BFGENCR - Buffer Generic Configuration */
/*! @{ */

#define XSPI_BFGENCR_SEQID_RDSR_MASK             (0xFU)
#define XSPI_BFGENCR_SEQID_RDSR_SHIFT            (0U)
/*! SEQID_RDSR - Read Status Register Sequence ID in LUT */
#define XSPI_BFGENCR_SEQID_RDSR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_SEQID_RDSR_SHIFT)) & XSPI_BFGENCR_SEQID_RDSR_MASK)

#define XSPI_BFGENCR_SPLITEN_MASK                (0x100U)
#define XSPI_BFGENCR_SPLITEN_SHIFT               (8U)
/*! SPLITEN - AHB Transaction Split Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_BFGENCR_SPLITEN(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_SPLITEN_SHIFT)) & XSPI_BFGENCR_SPLITEN_MASK)

#define XSPI_BFGENCR_AHBSSIZE_MASK               (0x600U)
#define XSPI_BFGENCR_AHBSSIZE_SHIFT              (9U)
/*! AHBSSIZE - AHB Split Size
 *  0b00..8 bytes
 *  0b01..16 bytes
 *  0b10..32 bytes
 *  0b11..64 bytes
 */
#define XSPI_BFGENCR_AHBSSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_AHBSSIZE_SHIFT)) & XSPI_BFGENCR_AHBSSIZE_MASK)

#define XSPI_BFGENCR_SEQID_MASK                  (0xF000U)
#define XSPI_BFGENCR_SEQID_SHIFT                 (12U)
/*! SEQID - LUT Sequence Pointer */
#define XSPI_BFGENCR_SEQID(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_SEQID_SHIFT)) & XSPI_BFGENCR_SEQID_MASK)

#define XSPI_BFGENCR_SEQID_WR_EN_MASK            (0x20000U)
#define XSPI_BFGENCR_SEQID_WR_EN_SHIFT           (17U)
/*! SEQID_WR_EN - Enable Write Sequence ID
 *  0b0..Disables (use SEQID)
 *  0b1..Enables
 */
#define XSPI_BFGENCR_SEQID_WR_EN(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_SEQID_WR_EN_SHIFT)) & XSPI_BFGENCR_SEQID_WR_EN_MASK)

#define XSPI_BFGENCR_PPWF_CLR_MASK               (0x100000U)
#define XSPI_BFGENCR_PPWF_CLR_SHIFT              (20U)
/*! PPWF_CLR - Page Program Wait Flag Clear
 *  0b0..Cleared by software
 *  0b1..Cleared by XSPI. No software intervention required.
 */
#define XSPI_BFGENCR_PPWF_CLR(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_PPWF_CLR_SHIFT)) & XSPI_BFGENCR_PPWF_CLR_MASK)

#define XSPI_BFGENCR_WR_FLUSH_EN_MASK            (0x200000U)
#define XSPI_BFGENCR_WR_FLUSH_EN_SHIFT           (21U)
/*! WR_FLUSH_EN - Write Flush Enable
 *  0b0..Not cleared
 *  0b1..Cleared
 */
#define XSPI_BFGENCR_WR_FLUSH_EN(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_WR_FLUSH_EN_SHIFT)) & XSPI_BFGENCR_WR_FLUSH_EN_MASK)

#define XSPI_BFGENCR_ALIGN_MASK                  (0xC00000U)
#define XSPI_BFGENCR_ALIGN_SHIFT                 (22U)
/*! ALIGN - AHB Alignment
 *  0b00..No limit
 *  0b01..256 bytes
 *  0b10..512 bytes
 *  0b11..1 KB
 */
#define XSPI_BFGENCR_ALIGN(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_ALIGN_SHIFT)) & XSPI_BFGENCR_ALIGN_MASK)

#define XSPI_BFGENCR_SEQID_WR_MASK               (0xF0000000U)
#define XSPI_BFGENCR_SEQID_WR_SHIFT              (28U)
/*! SEQID_WR - Write Sequence ID */
#define XSPI_BFGENCR_SEQID_WR(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_BFGENCR_SEQID_WR_SHIFT)) & XSPI_BFGENCR_SEQID_WR_MASK)
/*! @} */

/*! @name SOCCR - SOC Configuration */
/*! @{ */

#define XSPI_SOCCR_SOCCFG_MASK                   (0xFFFFFFU)
#define XSPI_SOCCR_SOCCFG_SHIFT                  (0U)
/*! SOCCFG - SOC Configuration */
#define XSPI_SOCCR_SOCCFG(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_SOCCR_SOCCFG_SHIFT)) & XSPI_SOCCR_SOCCFG_MASK)

#define XSPI_SOCCR_MASK_ECC_MASK                 (0x2000000U)
#define XSPI_SOCCR_MASK_ECC_SHIFT                (25U)
/*! MASK_ECC - Mask ECC for False AHB Reads
 *  0b0..Unmask ECC error
 *  0b1..Mask ECC error
 */
#define XSPI_SOCCR_MASK_ECC(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SOCCR_MASK_ECC_SHIFT)) & XSPI_SOCCR_MASK_ECC_MASK)

#define XSPI_SOCCR_OBE_MASK_EN_MASK              (0x4000000U)
#define XSPI_SOCCR_OBE_MASK_EN_SHIFT             (26U)
/*! OBE_MASK_EN - Output Buffer Enable Mask Enable
 *  0b0..Enable all OBE in output direction for x8 mode during write transaction (in a non-Dummy phase)
 *  0b1..Normal OBE handling for both read and write operation
 */
#define XSPI_SOCCR_OBE_MASK_EN(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_SOCCR_OBE_MASK_EN_SHIFT)) & XSPI_SOCCR_OBE_MASK_EN_MASK)

#define XSPI_SOCCR_HRESP_ERR_MASK_MASK           (0x8000000U)
#define XSPI_SOCCR_HRESP_ERR_MASK_SHIFT          (27U)
/*! HRESP_ERR_MASK - HRESP Error Mask
 *  0b0..Allows HRESP error generation
 *  0b1..Masks HRESP error generation
 */
#define XSPI_SOCCR_HRESP_ERR_MASK(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_SOCCR_HRESP_ERR_MASK_SHIFT)) & XSPI_SOCCR_HRESP_ERR_MASK_MASK)

#define XSPI_SOCCR_ENA_DLLABRT_MASK              (0x10000000U)
#define XSPI_SOCCR_ENA_DLLABRT_SHIFT             (28U)
/*! ENA_DLLABRT - DLL Abort Request Status Enable
 *  0b0..Masks
 *  0b1..Unmasks
 */
#define XSPI_SOCCR_ENA_DLLABRT(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_SOCCR_ENA_DLLABRT_SHIFT)) & XSPI_SOCCR_ENA_DLLABRT_MASK)
/*! @} */

/*! @name BUFIND - Buffer 0 Top Index..Buffer 2 Top Index */
/*! @{ */

#define XSPI_BUFIND_TPINDX_MASK                  (0x1FF8U)
#define XSPI_BUFIND_TPINDX_SHIFT                 (3U)
/*! TPINDX - Top Index Buffer */
#define XSPI_BUFIND_TPINDX(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_BUFIND_TPINDX_SHIFT)) & XSPI_BUFIND_TPINDX_MASK)
/*! @} */

/*! @name AWRCR - AHB Write Configuration */
/*! @{ */

#define XSPI_AWRCR_PPW_RD_DIS_MASK               (0x4000U)
#define XSPI_AWRCR_PPW_RD_DIS_SHIFT              (14U)
/*! PPW_RD_DIS - Page Program Wait Read Disable
 *  0b0..Enables subsequent reads
 *  0b1..Disables subsequent reads
 */
#define XSPI_AWRCR_PPW_RD_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_AWRCR_PPW_RD_DIS_SHIFT)) & XSPI_AWRCR_PPW_RD_DIS_MASK)

#define XSPI_AWRCR_PPW_WR_DIS_MASK               (0x8000U)
#define XSPI_AWRCR_PPW_WR_DIS_SHIFT              (15U)
/*! PPW_WR_DIS - Page Program Wait Write Disable
 *  0b0..Enables subsequent writes
 *  0b1..Disables subsequent writes
 */
#define XSPI_AWRCR_PPW_WR_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_AWRCR_PPW_WR_DIS_SHIFT)) & XSPI_AWRCR_PPW_WR_DIS_MASK)
/*! @} */

/*! @name DLLCR - DLL Flash Memory A Configuration */
/*! @{ */

#define XSPI_DLLCR_SLV_UPD_MASK                  (0x1U)
#define XSPI_DLLCR_SLV_UPD_SHIFT                 (0U)
/*! SLV_UPD - Subordinate Update
 *  0b0..Disables any further update on the DQS subordinate delay chain.
 *  0b1..Updates
 */
#define XSPI_DLLCR_SLV_UPD(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLV_UPD_SHIFT)) & XSPI_DLLCR_SLV_UPD_MASK)

#define XSPI_DLLCR_SLV_DLL_BYPASS_MASK           (0x2U)
#define XSPI_DLLCR_SLV_DLL_BYPASS_SHIFT          (1U)
/*! SLV_DLL_BYPASS - Subordinate DLL Bypass
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_DLLCR_SLV_DLL_BYPASS(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLV_DLL_BYPASS_SHIFT)) & XSPI_DLLCR_SLV_DLL_BYPASS_MASK)

#define XSPI_DLLCR_SLV_EN_MASK                   (0x4U)
#define XSPI_DLLCR_SLV_EN_SHIFT                  (2U)
/*! SLV_EN - Subordinate Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_DLLCR_SLV_EN(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLV_EN_SHIFT)) & XSPI_DLLCR_SLV_EN_MASK)

#define XSPI_DLLCR_SLAVE_AUTO_UPDT_MASK          (0x8U)
#define XSPI_DLLCR_SLAVE_AUTO_UPDT_SHIFT         (3U)
/*! SLAVE_AUTO_UPDT - Subordinate Chain Auto-Update Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_DLLCR_SLAVE_AUTO_UPDT(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLAVE_AUTO_UPDT_SHIFT)) & XSPI_DLLCR_SLAVE_AUTO_UPDT_MASK)

#define XSPI_DLLCR_DLL_CDL8_MASK                 (0x10U)
#define XSPI_DLLCR_DLL_CDL8_SHIFT                (4U)
/*! DLL_CDL8 - DLL Course Delay Line 8 Enable
 *  0b0..DLL is implemented to support up to 2x variation
 *  0b1..DLL is implemented to support up to 3x variation (BCS -> WCS)
 */
#define XSPI_DLLCR_DLL_CDL8(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_DLL_CDL8_SHIFT)) & XSPI_DLLCR_DLL_CDL8_MASK)

#define XSPI_DLLCR_SLV_DLY_FINE_MASK             (0xE0U)
#define XSPI_DLLCR_SLV_DLY_FINE_SHIFT            (5U)
/*! SLV_DLY_FINE - Fine Adjustment Delay Elements */
#define XSPI_DLLCR_SLV_DLY_FINE(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLV_DLY_FINE_SHIFT)) & XSPI_DLLCR_SLV_DLY_FINE_MASK)

#define XSPI_DLLCR_SLV_DLY_COARSE_MASK           (0xF00U)
#define XSPI_DLLCR_SLV_DLY_COARSE_SHIFT          (8U)
/*! SLV_DLY_COARSE - Delay Elements in Delay Tap */
#define XSPI_DLLCR_SLV_DLY_COARSE(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLV_DLY_COARSE_SHIFT)) & XSPI_DLLCR_SLV_DLY_COARSE_MASK)

#define XSPI_DLLCR_SLV_DLY_OFFSET_MASK           (0x7000U)
#define XSPI_DLLCR_SLV_DLY_OFFSET_SHIFT          (12U)
/*! SLV_DLY_OFFSET - T/16 Offset Delay Elements */
#define XSPI_DLLCR_SLV_DLY_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLV_DLY_OFFSET_SHIFT)) & XSPI_DLLCR_SLV_DLY_OFFSET_MASK)

#define XSPI_DLLCR_SLV_FINE_OFFSET_MASK          (0xF0000U)
#define XSPI_DLLCR_SLV_FINE_OFFSET_SHIFT         (16U)
/*! SLV_FINE_OFFSET - Fine Offset Delay Elements */
#define XSPI_DLLCR_SLV_FINE_OFFSET(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_SLV_FINE_OFFSET_SHIFT)) & XSPI_DLLCR_SLV_FINE_OFFSET_MASK)

#define XSPI_DLLCR_DLLRES_MASK                   (0xF00000U)
#define XSPI_DLLCR_DLLRES_SHIFT                  (20U)
/*! DLLRES - DLL Resolution */
#define XSPI_DLLCR_DLLRES(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_DLLRES_SHIFT)) & XSPI_DLLCR_DLLRES_MASK)

#define XSPI_DLLCR_DLL_REFCNTR_MASK              (0xF000000U)
#define XSPI_DLLCR_DLL_REFCNTR_SHIFT             (24U)
/*! DLL_REFCNTR - DLL Reference Counter */
#define XSPI_DLLCR_DLL_REFCNTR(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_DLL_REFCNTR_SHIFT)) & XSPI_DLLCR_DLL_REFCNTR_MASK)

#define XSPI_DLLCR_FREQEN_MASK                   (0x40000000U)
#define XSPI_DLLCR_FREQEN_SHIFT                  (30U)
/*! FREQEN - Frequency Enable
 *  0b0..Low frequency
 *  0b1..High frequency
 */
#define XSPI_DLLCR_FREQEN(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_FREQEN_SHIFT)) & XSPI_DLLCR_FREQEN_MASK)

#define XSPI_DLLCR_DLLEN_MASK                    (0x80000000U)
#define XSPI_DLLCR_DLLEN_SHIFT                   (31U)
/*! DLLEN - DLL Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_DLLCR_DLLEN(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_DLLCR_DLLEN_SHIFT)) & XSPI_DLLCR_DLLEN_MASK)
/*! @} */

/*! @name SFAR - Serial Flash Memory Address */
/*! @{ */

#define XSPI_SFAR_SFADR_MASK                     (0xFFFFFFFFU)
#define XSPI_SFAR_SFADR_SHIFT                    (0U)
/*! SFADR - Serial Flash Memory Address */
#define XSPI_SFAR_SFADR(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SFAR_SFADR_SHIFT)) & XSPI_SFAR_SFADR_MASK)
/*! @} */

/*! @name SFACR - Serial Flash Memory Address Configuration */
/*! @{ */

#define XSPI_SFACR_CAS_MASK                      (0xFU)
#define XSPI_SFACR_CAS_SHIFT                     (0U)
/*! CAS - Column Address Space */
#define XSPI_SFACR_CAS(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_CAS_SHIFT)) & XSPI_SFACR_CAS_MASK)

#define XSPI_SFACR_PPWB_MASK                     (0x1F00U)
#define XSPI_SFACR_PPWB_SHIFT                    (8U)
/*! PPWB - Page Program Boundary */
#define XSPI_SFACR_PPWB(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_PPWB_SHIFT)) & XSPI_SFACR_PPWB_MASK)

#define XSPI_SFACR_WA_MASK                       (0x10000U)
#define XSPI_SFACR_WA_SHIFT                      (16U)
/*! WA - Word Addressable
 *  0b0..Byte addressable
 *  0b1..Word (2-byte) addressable mode
 */
#define XSPI_SFACR_WA(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_WA_SHIFT)) & XSPI_SFACR_WA_MASK)

#define XSPI_SFACR_BYTE_SWAP_MASK                (0x20000U)
#define XSPI_SFACR_BYTE_SWAP_SHIFT               (17U)
/*! BYTE_SWAP - Byte Swapping
 *  0b0..One word of two bytes at addresses [n, n + 1]
 *  0b1..One word of two bytes at addresses [n + 1, n]
 */
#define XSPI_SFACR_BYTE_SWAP(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_BYTE_SWAP_SHIFT)) & XSPI_SFACR_BYTE_SWAP_MASK)

#define XSPI_SFACR_RX_BP_EN_MASK                 (0x40000U)
#define XSPI_SFACR_RX_BP_EN_SHIFT                (18U)
/*! RX_BP_EN - RX Backpressure Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_SFACR_RX_BP_EN(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_RX_BP_EN_SHIFT)) & XSPI_SFACR_RX_BP_EN_MASK)

#define XSPI_SFACR_CAS_INTRLVD_MASK              (0x100000U)
#define XSPI_SFACR_CAS_INTRLVD_SHIFT             (20U)
/*! CAS_INTRLVD - CAS Interleaving
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_SFACR_CAS_INTRLVD(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_CAS_INTRLVD_SHIFT)) & XSPI_SFACR_CAS_INTRLVD_MASK)

#define XSPI_SFACR_WA_4B_EN_MASK                 (0x200000U)
#define XSPI_SFACR_WA_4B_EN_SHIFT                (21U)
/*! WA_4B_EN - 32-Bit Address Mode Enable
 *  0b0..Disables.
 *  0b1..32-bit mode
 */
#define XSPI_SFACR_WA_4B_EN(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_WA_4B_EN_SHIFT)) & XSPI_SFACR_WA_4B_EN_MASK)

#define XSPI_SFACR_FORCE_A10_MASK                (0x400000U)
#define XSPI_SFACR_FORCE_A10_SHIFT               (22U)
/*! FORCE_A10 - 10th Bit Status
 *  0b0..Force
 *  0b1..Do not force
 */
#define XSPI_SFACR_FORCE_A10(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_FORCE_A10_SHIFT)) & XSPI_SFACR_FORCE_A10_MASK)

#define XSPI_SFACR_X16_DLLA_SLVFINE_OFFSET_MASK  (0xF000000U)
#define XSPI_SFACR_X16_DLLA_SLVFINE_OFFSET_SHIFT (24U)
/*! X16_DLLA_SLVFINE_OFFSET - Fine Offset Delay Elements in Incoming DQS1 Flash Memory A */
#define XSPI_SFACR_X16_DLLA_SLVFINE_OFFSET(x)    (((uint32_t)(((uint32_t)(x)) << XSPI_SFACR_X16_DLLA_SLVFINE_OFFSET_SHIFT)) & XSPI_SFACR_X16_DLLA_SLVFINE_OFFSET_MASK)
/*! @} */

/*! @name SMPR - Sampling */
/*! @{ */

#define XSPI_SMPR_FSPHS_MASK                     (0x20U)
#define XSPI_SMPR_FSPHS_SHIFT                    (5U)
/*! FSPHS - Full-Speed Phase
 *  0b0..Sampling at non-inverted clock
 *  0b1..Sampling at inverted clock
 */
#define XSPI_SMPR_FSPHS(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SMPR_FSPHS_SHIFT)) & XSPI_SMPR_FSPHS_MASK)

#define XSPI_SMPR_FSDLY_MASK                     (0x40U)
#define XSPI_SMPR_FSDLY_SHIFT                    (6U)
/*! FSDLY - Full-Speed Delay For Internal/Pad Loopback
 *  0b0..Same DQS
 *  0b1..Half cycle early DQS
 */
#define XSPI_SMPR_FSDLY(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SMPR_FSDLY_SHIFT)) & XSPI_SMPR_FSDLY_MASK)

#define XSPI_SMPR_DLLFSMPFA_MASK                 (0x7000000U)
#define XSPI_SMPR_DLLFSMPFA_SHIFT                (24U)
/*! DLLFSMPFA - DLL Nth Tap Flash Memory A */
#define XSPI_SMPR_DLLFSMPFA(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SMPR_DLLFSMPFA_SHIFT)) & XSPI_SMPR_DLLFSMPFA_MASK)
/*! @} */

/*! @name RBSR - RX Buffer Status */
/*! @{ */

#define XSPI_RBSR_RDBFL_MASK                     (0xFFU)
#define XSPI_RBSR_RDBFL_SHIFT                    (0U)
/*! RDBFL - RX Buffer Fill Level */
#define XSPI_RBSR_RDBFL(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RBSR_RDBFL_SHIFT)) & XSPI_RBSR_RDBFL_MASK)

#define XSPI_RBSR_RDCTR_MASK                     (0xFFFF0000U)
#define XSPI_RBSR_RDCTR_SHIFT                    (16U)
/*! RDCTR - Read Counter */
#define XSPI_RBSR_RDCTR(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RBSR_RDCTR_SHIFT)) & XSPI_RBSR_RDCTR_MASK)
/*! @} */

/*! @name RBCT - RX Buffer Control */
/*! @{ */

#define XSPI_RBCT_WMRK_MASK                      (0x7FU)
#define XSPI_RBCT_WMRK_SHIFT                     (0U)
/*! WMRK - RX Buffer Watermark */
#define XSPI_RBCT_WMRK(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_RBCT_WMRK_SHIFT)) & XSPI_RBCT_WMRK_MASK)
/*! @} */

/*! @name AWRSR - AHB Write Status */
/*! @{ */

#define XSPI_AWRSR_SEQAUJOIN_MASK                (0x4U)
#define XSPI_AWRSR_SEQAUJOIN_SHIFT               (2U)
/*! SEQAUJOIN - Sequence Auto Join
 *  0b0..Not auto-joined
 *  0b1..Auto-joined
 */
#define XSPI_AWRSR_SEQAUJOIN(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_AWRSR_SEQAUJOIN_SHIFT)) & XSPI_AWRSR_SEQAUJOIN_MASK)
/*! @} */

/*! @name DLLSR - DLL Status */
/*! @{ */

#define XSPI_DLLSR_DLLA_SLV_COARSE_VAL_MASK      (0xFU)
#define XSPI_DLLSR_DLLA_SLV_COARSE_VAL_SHIFT     (0U)
/*! DLLA_SLV_COARSE_VAL - Coarse Delay Cells in Subordinate Delay Chain - Flash Memory A */
#define XSPI_DLLSR_DLLA_SLV_COARSE_VAL(x)        (((uint32_t)(((uint32_t)(x)) << XSPI_DLLSR_DLLA_SLV_COARSE_VAL_SHIFT)) & XSPI_DLLSR_DLLA_SLV_COARSE_VAL_MASK)

#define XSPI_DLLSR_DLLA_SLV_FINE_VAL_MASK        (0xF0U)
#define XSPI_DLLSR_DLLA_SLV_FINE_VAL_SHIFT       (4U)
/*! DLLA_SLV_FINE_VAL - Fine Delay Cells in Subordinate Delay Chain */
#define XSPI_DLLSR_DLLA_SLV_FINE_VAL(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_DLLSR_DLLA_SLV_FINE_VAL_SHIFT)) & XSPI_DLLSR_DLLA_SLV_FINE_VAL_MASK)

#define XSPI_DLLSR_DLLA_FINE_UNDERFLOW_MASK      (0x1000U)
#define XSPI_DLLSR_DLLA_FINE_UNDERFLOW_SHIFT     (12U)
/*! DLLA_FINE_UNDERFLOW - Fine Delay Chain Underflow - Flash Memory A
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define XSPI_DLLSR_DLLA_FINE_UNDERFLOW(x)        (((uint32_t)(((uint32_t)(x)) << XSPI_DLLSR_DLLA_FINE_UNDERFLOW_SHIFT)) & XSPI_DLLSR_DLLA_FINE_UNDERFLOW_MASK)

#define XSPI_DLLSR_DLLA_RANGE_ERR_MASK           (0x2000U)
#define XSPI_DLLSR_DLLA_RANGE_ERR_SHIFT          (13U)
/*! DLLA_RANGE_ERR - DLL Manager Delay Chain Range Error - Flash Memory A
 *  0b0..In range
 *  0b1..Out of range
 */
#define XSPI_DLLSR_DLLA_RANGE_ERR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_DLLSR_DLLA_RANGE_ERR_SHIFT)) & XSPI_DLLSR_DLLA_RANGE_ERR_MASK)

#define XSPI_DLLSR_SLVA_LOCK_MASK                (0x4000U)
#define XSPI_DLLSR_SLVA_LOCK_SHIFT               (14U)
/*! SLVA_LOCK - Subordinate High Lock Status - Flash Memory A
 *  0b0..Not locked
 *  0b1..Locked
 */
#define XSPI_DLLSR_SLVA_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_DLLSR_SLVA_LOCK_SHIFT)) & XSPI_DLLSR_SLVA_LOCK_MASK)

#define XSPI_DLLSR_DLLA_LOCK_MASK                (0x8000U)
#define XSPI_DLLSR_DLLA_LOCK_SHIFT               (15U)
/*! DLLA_LOCK - DLL A Lock Status
 *  0b0..Not locked
 *  0b1..Locked
 */
#define XSPI_DLLSR_DLLA_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_DLLSR_DLLA_LOCK_SHIFT)) & XSPI_DLLSR_DLLA_LOCK_MASK)
/*! @} */

/*! @name DLCR - Data Learning Configuration */
/*! @{ */

#define XSPI_DLCR_DLP_SEL_FA_MASK                (0xC000U)
#define XSPI_DLCR_DLP_SEL_FA_SHIFT               (14U)
/*! DLP_SEL_FA - DLP Selection Flash Memory A
 *  0b00..Ignore pattern matching
 *  0b01..IO1
 *  0b10..IO3
 *  0b11..Both IO1 and IO3
 */
#define XSPI_DLCR_DLP_SEL_FA(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_DLCR_DLP_SEL_FA_SHIFT)) & XSPI_DLCR_DLP_SEL_FA_MASK)

#define XSPI_DLCR_DL_NONDLP_FLSH_MASK            (0x1000000U)
#define XSPI_DLCR_DL_NONDLP_FLSH_SHIFT           (24U)
/*! DL_NONDLP_FLSH - DLP Non-DLP Flash Memory Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_DLCR_DL_NONDLP_FLSH(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_DLCR_DL_NONDLP_FLSH_SHIFT)) & XSPI_DLCR_DL_NONDLP_FLSH_MASK)
/*! @} */

/*! @name DLSR_F - Data Learning Status Flash Memory */
/*! @{ */

#define XSPI_DLSR_F_NEG_EDGE_MASK                (0xFFU)
#define XSPI_DLSR_F_NEG_EDGE_SHIFT               (0U)
/*! NEG_EDGE - DLP Negative Edge Match */
#define XSPI_DLSR_F_NEG_EDGE(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_DLSR_F_NEG_EDGE_SHIFT)) & XSPI_DLSR_F_NEG_EDGE_MASK)

#define XSPI_DLSR_F_POS_EDGE_MASK                (0xFF00U)
#define XSPI_DLSR_F_POS_EDGE_SHIFT               (8U)
/*! POS_EDGE - DLP Positive Edge Match */
#define XSPI_DLSR_F_POS_EDGE(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_DLSR_F_POS_EDGE_SHIFT)) & XSPI_DLSR_F_POS_EDGE_MASK)

#define XSPI_DLSR_F_DLPFF_MASK                   (0x80000000U)
#define XSPI_DLSR_F_DLPFF_SHIFT                  (31U)
/*! DLPFF - DLP Failure Flag
 *  0b0..No failure
 *  0b1..Failure
 */
#define XSPI_DLSR_F_DLPFF(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_DLSR_F_DLPFF_SHIFT)) & XSPI_DLSR_F_DLPFF_MASK)
/*! @} */

/* The count of XSPI_DLSR_F */
#define XSPI_DLSR_F_COUNT                        (1U)

/*! @name TBSR - TX Buffer Status */
/*! @{ */

#define XSPI_TBSR_TRBFL_MASK                     (0x1FFU)
#define XSPI_TBSR_TRBFL_SHIFT                    (0U)
/*! TRBFL - TX Buffer Fill Level */
#define XSPI_TBSR_TRBFL(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_TBSR_TRBFL_SHIFT)) & XSPI_TBSR_TRBFL_MASK)

#define XSPI_TBSR_TRCTR_MASK                     (0xFFFF0000U)
#define XSPI_TBSR_TRCTR_SHIFT                    (16U)
/*! TRCTR - Transmit Counter */
#define XSPI_TBSR_TRCTR(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_TBSR_TRCTR_SHIFT)) & XSPI_TBSR_TRCTR_MASK)
/*! @} */

/*! @name TBDR - TX Buffer Data */
/*! @{ */

#define XSPI_TBDR_TXDATA_MASK                    (0xFFFFFFFFU)
#define XSPI_TBDR_TXDATA_SHIFT                   (0U)
/*! TXDATA - TX Data */
#define XSPI_TBDR_TXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TBDR_TXDATA_SHIFT)) & XSPI_TBDR_TXDATA_MASK)
/*! @} */

/*! @name TBCT - TX Buffer Control */
/*! @{ */

#define XSPI_TBCT_WMRK_MASK                      (0xFFU)
#define XSPI_TBCT_WMRK_SHIFT                     (0U)
/*! WMRK - TX Buffer Watermark */
#define XSPI_TBCT_WMRK(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_TBCT_WMRK_SHIFT)) & XSPI_TBCT_WMRK_MASK)
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define XSPI_SR_BUSY_MASK                        (0x1U)
#define XSPI_SR_BUSY_SHIFT                       (0U)
/*! BUSY - Module Busy
 *  0b0..Not busy
 *  0b1..Busy
 */
#define XSPI_SR_BUSY(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_SR_BUSY_SHIFT)) & XSPI_SR_BUSY_MASK)

#define XSPI_SR_IP_ACC_MASK                      (0x2U)
#define XSPI_SR_IP_ACC_SHIFT                     (1U)
/*! IP_ACC - IP Access
 *  0b0..Not initiated by IP bus
 *  0b1..Initiated by IP bus
 */
#define XSPI_SR_IP_ACC(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_IP_ACC_SHIFT)) & XSPI_SR_IP_ACC_MASK)

#define XSPI_SR_AHB_ACC_MASK                     (0x4U)
#define XSPI_SR_AHB_ACC_SHIFT                    (2U)
/*! AHB_ACC - AHB Read Access
 *  0b0..Not initiated by AHB bus
 *  0b1..Initiated by AHB bus
 */
#define XSPI_SR_AHB_ACC(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB_ACC_SHIFT)) & XSPI_SR_AHB_ACC_MASK)

#define XSPI_SR_AWRACC_MASK                      (0x10U)
#define XSPI_SR_AWRACC_SHIFT                     (4U)
/*! AWRACC - AHB Write Access
 *  0b0..No AHB write access
 *  0b1..AHB write access
 */
#define XSPI_SR_AWRACC(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AWRACC_SHIFT)) & XSPI_SR_AWRACC_MASK)

#define XSPI_SR_AHBTRN_MASK                      (0x40U)
#define XSPI_SR_AHBTRN_SHIFT                     (6U)
/*! AHBTRN - AHB Access Transaction Pending
 *  0b0..No pending request
 *  0b1..Request is pending
 */
#define XSPI_SR_AHBTRN(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHBTRN_SHIFT)) & XSPI_SR_AHBTRN_MASK)

#define XSPI_SR_AHB0NE_MASK                      (0x80U)
#define XSPI_SR_AHB0NE_SHIFT                     (7U)
/*! AHB0NE - AHB Buffer 0 Not Empty
 *  0b0..Empty
 *  0b1..Not empty
 */
#define XSPI_SR_AHB0NE(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB0NE_SHIFT)) & XSPI_SR_AHB0NE_MASK)

#define XSPI_SR_AHB1NE_MASK                      (0x100U)
#define XSPI_SR_AHB1NE_SHIFT                     (8U)
/*! AHB1NE - AHB Buffer 1 Not Empty
 *  0b0..Empty
 *  0b1..Not empty
 */
#define XSPI_SR_AHB1NE(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB1NE_SHIFT)) & XSPI_SR_AHB1NE_MASK)

#define XSPI_SR_AHB2NE_MASK                      (0x200U)
#define XSPI_SR_AHB2NE_SHIFT                     (9U)
/*! AHB2NE - AHB Buffer 2 Not Empty
 *  0b0..Empty
 *  0b1..Not empty
 */
#define XSPI_SR_AHB2NE(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB2NE_SHIFT)) & XSPI_SR_AHB2NE_MASK)

#define XSPI_SR_AHB3NE_MASK                      (0x400U)
#define XSPI_SR_AHB3NE_SHIFT                     (10U)
/*! AHB3NE - AHB Buffer 3 Not Empty
 *  0b0..Empty
 *  0b1..Not empty
 */
#define XSPI_SR_AHB3NE(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB3NE_SHIFT)) & XSPI_SR_AHB3NE_MASK)

#define XSPI_SR_AHB0FUL_MASK                     (0x800U)
#define XSPI_SR_AHB0FUL_SHIFT                    (11U)
/*! AHB0FUL - AHB Buffer 0 Full
 *  0b0..Not full
 *  0b1..Full
 */
#define XSPI_SR_AHB0FUL(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB0FUL_SHIFT)) & XSPI_SR_AHB0FUL_MASK)

#define XSPI_SR_AHB1FUL_MASK                     (0x1000U)
#define XSPI_SR_AHB1FUL_SHIFT                    (12U)
/*! AHB1FUL - AHB Buffer 1 Full
 *  0b0..Not full
 *  0b1..Full
 */
#define XSPI_SR_AHB1FUL(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB1FUL_SHIFT)) & XSPI_SR_AHB1FUL_MASK)

#define XSPI_SR_AHB2FUL_MASK                     (0x2000U)
#define XSPI_SR_AHB2FUL_SHIFT                    (13U)
/*! AHB2FUL - AHB Buffer 2 Full
 *  0b0..Not full
 *  0b1..Full
 */
#define XSPI_SR_AHB2FUL(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB2FUL_SHIFT)) & XSPI_SR_AHB2FUL_MASK)

#define XSPI_SR_AHB3FUL_MASK                     (0x4000U)
#define XSPI_SR_AHB3FUL_SHIFT                    (14U)
/*! AHB3FUL - AHB Buffer 3 Full
 *  0b0..Not full
 *  0b1..Full
 */
#define XSPI_SR_AHB3FUL(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SR_AHB3FUL_SHIFT)) & XSPI_SR_AHB3FUL_MASK)

#define XSPI_SR_ARB_LCK_MASK                     (0x8000U)
#define XSPI_SR_ARB_LCK_SHIFT                    (15U)
/*! ARB_LCK - Arbitration Lock Status
 *  0b0..Not locked
 *  0b1..Locked
 */
#define XSPI_SR_ARB_LCK(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_SR_ARB_LCK_SHIFT)) & XSPI_SR_ARB_LCK_MASK)

#define XSPI_SR_RXWE_MASK                        (0x10000U)
#define XSPI_SR_RXWE_SHIFT                       (16U)
/*! RXWE - RX Buffer Watermark Exceeded
 *  0b0..Not exceeded
 *  0b1..Exceeded
 */
#define XSPI_SR_RXWE(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_SR_RXWE_SHIFT)) & XSPI_SR_RXWE_MASK)

#define XSPI_SR_RXFULL_MASK                      (0x80000U)
#define XSPI_SR_RXFULL_SHIFT                     (19U)
/*! RXFULL - RX Buffer Full
 *  0b0..Not full
 *  0b1..Full
 */
#define XSPI_SR_RXFULL(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_RXFULL_SHIFT)) & XSPI_SR_RXFULL_MASK)

#define XSPI_SR_ARB_STATE_MASK                   (0x700000U)
#define XSPI_SR_ARB_STATE_SHIFT                  (20U)
/*! ARB_STATE - XSPI Arbitration State
 *  0b000..Idle
 *  0b001..ARB - Arbitration
 *  0b010..AHBWR_PROC - AHB write processing
 *  0b011..AHBRD_PROC - AHB read processing
 *  0b101..TG_PROC - IP command processing
 *  0b110..PROC_FIN - XSPI processing finish wait
 *  0b111..RDSR_PROC - RDSR read processing
 */
#define XSPI_SR_ARB_STATE(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_SR_ARB_STATE_SHIFT)) & XSPI_SR_ARB_STATE_MASK)

#define XSPI_SR_RXDMA_MASK                       (0x800000U)
#define XSPI_SR_RXDMA_SHIFT                      (23U)
/*! RXDMA - RX Buffer DMA
 *  0b0..Not active
 *  0b1..Active
 */
#define XSPI_SR_RXDMA(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_SR_RXDMA_SHIFT)) & XSPI_SR_RXDMA_MASK)

#define XSPI_SR_TXNE_MASK                        (0x1000000U)
#define XSPI_SR_TXNE_SHIFT                       (24U)
/*! TXNE - TX Buffer Not Empty
 *  0b0..Empty
 *  0b1..Not empty
 */
#define XSPI_SR_TXNE(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_SR_TXNE_SHIFT)) & XSPI_SR_TXNE_MASK)

#define XSPI_SR_TXWA_MASK                        (0x2000000U)
#define XSPI_SR_TXWA_SHIFT                       (25U)
/*! TXWA - TX Buffer Watermark Available
 *  0b0..Not available
 *  0b1..Available
 */
#define XSPI_SR_TXWA(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_SR_TXWA_SHIFT)) & XSPI_SR_TXWA_MASK)

#define XSPI_SR_TXDMA_MASK                       (0x4000000U)
#define XSPI_SR_TXDMA_SHIFT                      (26U)
/*! TXDMA - TX DMA
 *  0b0..Disabled or not processing the DMA request
 *  0b1..Enabled and processing DMA request
 */
#define XSPI_SR_TXDMA(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_SR_TXDMA_SHIFT)) & XSPI_SR_TXDMA_MASK)

#define XSPI_SR_TXFULL_MASK                      (0x8000000U)
#define XSPI_SR_TXFULL_SHIFT                     (27U)
/*! TXFULL - TX Buffer Full
 *  0b0..Not full
 *  0b1..Full
 */
#define XSPI_SR_TXFULL(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SR_TXFULL_SHIFT)) & XSPI_SR_TXFULL_MASK)
/*! @} */

/*! @name FR - Flag */
/*! @{ */

#define XSPI_FR_TFF_MASK                         (0x1U)
#define XSPI_FR_TFF_SHIFT                        (0U)
/*! TFF - IP Command Transaction Finished Flag
 *  0b0..No action
 *  0b0..Not completed
 *  0b1..Clears flag
 *  0b1..Completed
 */
#define XSPI_FR_TFF(x)                           (((uint32_t)(((uint32_t)(x)) << XSPI_FR_TFF_SHIFT)) & XSPI_FR_TFF_MASK)

#define XSPI_FR_RDADDR_MASK                      (0x2U)
#define XSPI_FR_RDADDR_SHIFT                     (1U)
/*! RDADDR - AHB Read Address Error Flag
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears flag
 *  0b1..Error
 */
#define XSPI_FR_RDADDR(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_FR_RDADDR_SHIFT)) & XSPI_FR_RDADDR_MASK)

#define XSPI_FR_PERFOVF_MASK                     (0x4U)
#define XSPI_FR_PERFOVF_SHIFT                    (2U)
/*! PERFOVF - AHB Performance Monitor Overflow Flag
 *  0b0..No action
 *  0b0..No overflow
 *  0b1..Clears flags
 *  0b1..Overflow
 */
#define XSPI_FR_PERFOVF(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_FR_PERFOVF_SHIFT)) & XSPI_FR_PERFOVF_MASK)

#define XSPI_FR_IPEDERR_MASK                     (0x20U)
#define XSPI_FR_IPEDERR_SHIFT                    (5U)
/*! IPEDERR - IPED RX Decryption Error Flag
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears error flag
 *  0b1..Error
 */
#define XSPI_FR_IPEDERR(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_FR_IPEDERR_SHIFT)) & XSPI_FR_IPEDERR_MASK)

#define XSPI_FR_IPIEF_MASK                       (0x40U)
#define XSPI_FR_IPIEF_SHIFT                      (6U)
/*! IPIEF - IP Command Trigger Fail Error Flag
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears error flag
 *  0b1..Error
 */
#define XSPI_FR_IPIEF(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_FR_IPIEF_SHIFT)) & XSPI_FR_IPIEF_MASK)

#define XSPI_FR_PPWF_MASK                        (0x100U)
#define XSPI_FR_PPWF_SHIFT                       (8U)
/*! PPWF - Page-Program Wait Flag
 *  0b0..No action
 *  0b0..No page program wait
 *  0b1..Clears flag
 *  0b1..Page program wait in effect
 */
#define XSPI_FR_PPWF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_PPWF_SHIFT)) & XSPI_FR_PPWF_MASK)

#define XSPI_FR_ABOF_MASK                        (0x1000U)
#define XSPI_FR_ABOF_SHIFT                       (12U)
/*! ABOF - AHB Buffer Overflow Flag
 *  0b0..No action
 *  0b0..No overflow
 *  0b1..Clears overflow flag
 *  0b1..Overflow
 */
#define XSPI_FR_ABOF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_ABOF_SHIFT)) & XSPI_FR_ABOF_MASK)

#define XSPI_FR_AIBSEF_MASK                      (0x2000U)
#define XSPI_FR_AIBSEF_SHIFT                     (13U)
/*! AIBSEF - AHB Illegal Burst Size Error Flag
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears error flag
 *  0b1..Error
 */
#define XSPI_FR_AIBSEF(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_FR_AIBSEF_SHIFT)) & XSPI_FR_AIBSEF_MASK)

#define XSPI_FR_AITEF_MASK                       (0x4000U)
#define XSPI_FR_AITEF_SHIFT                      (14U)
/*! AITEF - AHB Illegal Transaction Error Flag
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears error flag
 *  0b1..Error
 */
#define XSPI_FR_AITEF(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_FR_AITEF_SHIFT)) & XSPI_FR_AITEF_MASK)

#define XSPI_FR_AAEF_MASK                        (0x8000U)
#define XSPI_FR_AAEF_SHIFT                       (15U)
/*! AAEF - AHB Abort Error Flag
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears error flag
 *  0b1..Error
 */
#define XSPI_FR_AAEF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_AAEF_SHIFT)) & XSPI_FR_AAEF_MASK)

#define XSPI_FR_RBDF_MASK                        (0x10000U)
#define XSPI_FR_RBDF_SHIFT                       (16U)
/*! RBDF - RX Buffer Drain Flag
 *  0b0..No action
 *  0b0..RX buffer is not over the watermark
 *  0b1..Clears flag if RX buffer is not over the watermark after POP
 *  0b1..RX buffer is over the watermark
 */
#define XSPI_FR_RBDF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_RBDF_SHIFT)) & XSPI_FR_RBDF_MASK)

#define XSPI_FR_RBOF_MASK                        (0x20000U)
#define XSPI_FR_RBOF_SHIFT                       (17U)
/*! RBOF - RX Buffer Overflow Flag
 *  0b0..No action
 *  0b0..No overflow
 *  0b1..Clears flag
 *  0b1..Overflow
 */
#define XSPI_FR_RBOF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_RBOF_SHIFT)) & XSPI_FR_RBOF_MASK)

#define XSPI_FR_ILLINE_MASK                      (0x800000U)
#define XSPI_FR_ILLINE_SHIFT                     (23U)
/*! ILLINE - Illegal Instruction Error Flag
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears error flag
 *  0b1..Error
 */
#define XSPI_FR_ILLINE(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_FR_ILLINE_SHIFT)) & XSPI_FR_ILLINE_MASK)

#define XSPI_FR_DLLUNLCK_MASK                    (0x1000000U)
#define XSPI_FR_DLLUNLCK_SHIFT                   (24U)
/*! DLLUNLCK - DLL Unlock
 *  0b0..No action
 *  0b0..No unlock event
 *  0b1..Clears the flag
 *  0b1..Unlock event has occurred
 */
#define XSPI_FR_DLLUNLCK(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FR_DLLUNLCK_SHIFT)) & XSPI_FR_DLLUNLCK_MASK)

#define XSPI_FR_TBUF_MASK                        (0x4000000U)
#define XSPI_FR_TBUF_SHIFT                       (26U)
/*! TBUF - TX Buffer Underrun Flag
 *  0b0..No action
 *  0b0..No underrun
 *  0b1..Clears flag
 *  0b1..Underrun
 */
#define XSPI_FR_TBUF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_TBUF_SHIFT)) & XSPI_FR_TBUF_MASK)

#define XSPI_FR_TBFF_MASK                        (0x8000000U)
#define XSPI_FR_TBFF_SHIFT                       (27U)
/*! TBFF - TX Buffer Fill Flag
 *  0b0..No action
 *  0b0..No room in the TX buffer
 *  0b1..Clears flag
 *  0b1..TX buffer has room
 */
#define XSPI_FR_TBFF(x)                          (((uint32_t)(((uint32_t)(x)) << XSPI_FR_TBFF_SHIFT)) & XSPI_FR_TBFF_MASK)

#define XSPI_FR_DLLABRT_MASK                     (0x10000000U)
#define XSPI_FR_DLLABRT_SHIFT                    (28U)
/*! DLLABRT - DLL Terminate
 *  0b0..No action
 *  0b0..No lock has occurred
 *  0b1..Clears flag
 *  0b1..DLL unlock occurred
 */
#define XSPI_FR_DLLABRT(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_FR_DLLABRT_SHIFT)) & XSPI_FR_DLLABRT_MASK)

#define XSPI_FR_DLPFF_MASK                       (0x80000000U)
#define XSPI_FR_DLPFF_SHIFT                      (31U)
/*! DLPFF - Data Learning Pattern Failure Flag
 *  0b0..No action
 *  0b0..No failure
 *  0b1..Clears flag
 *  0b1..Failure
 */
#define XSPI_FR_DLPFF(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_FR_DLPFF_SHIFT)) & XSPI_FR_DLPFF_MASK)
/*! @} */

/*! @name RSER - Interrupt and DMA Request Enable */
/*! @{ */

#define XSPI_RSER_TFIE_MASK                      (0x1U)
#define XSPI_RSER_TFIE_SHIFT                     (0U)
/*! TFIE - Transaction Finished Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_TFIE(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_TFIE_SHIFT)) & XSPI_RSER_TFIE_MASK)

#define XSPI_RSER_RDADDRIE_MASK                  (0x2U)
#define XSPI_RSER_RDADDRIE_SHIFT                 (1U)
/*! RDADDRIE - AHB Read Address Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_RDADDRIE(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_RDADDRIE_SHIFT)) & XSPI_RSER_RDADDRIE_MASK)

#define XSPI_RSER_PERFOVIE_MASK                  (0x4U)
#define XSPI_RSER_PERFOVIE_SHIFT                 (2U)
/*! PERFOVIE - AHB Performance Monitor Overflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_PERFOVIE(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_PERFOVIE_SHIFT)) & XSPI_RSER_PERFOVIE_MASK)

#define XSPI_RSER_IPEDIE_MASK                    (0x20U)
#define XSPI_RSER_IPEDIE_SHIFT                   (5U)
/*! IPEDIE - IPED RX Decryption Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_IPEDIE(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_IPEDIE_SHIFT)) & XSPI_RSER_IPEDIE_MASK)

#define XSPI_RSER_IPIEIE_MASK                    (0x40U)
#define XSPI_RSER_IPIEIE_SHIFT                   (6U)
/*! IPIEIE - IP Command Trigger Fail Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_IPIEIE(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_IPIEIE_SHIFT)) & XSPI_RSER_IPIEIE_MASK)

#define XSPI_RSER_PPWIE_MASK                     (0x100U)
#define XSPI_RSER_PPWIE_SHIFT                    (8U)
/*! PPWIE - Page-Program Wait Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_PPWIE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_PPWIE_SHIFT)) & XSPI_RSER_PPWIE_MASK)

#define XSPI_RSER_ABOIE_MASK                     (0x1000U)
#define XSPI_RSER_ABOIE_SHIFT                    (12U)
/*! ABOIE - AHB Buffer Overflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_ABOIE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_ABOIE_SHIFT)) & XSPI_RSER_ABOIE_MASK)

#define XSPI_RSER_AIBSIE_MASK                    (0x2000U)
#define XSPI_RSER_AIBSIE_SHIFT                   (13U)
/*! AIBSIE - AHB Illegal Burst Size Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_AIBSIE(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_AIBSIE_SHIFT)) & XSPI_RSER_AIBSIE_MASK)

#define XSPI_RSER_AITIE_MASK                     (0x4000U)
#define XSPI_RSER_AITIE_SHIFT                    (14U)
/*! AITIE - AHB Illegal Transaction Error Interrupt Enable flag
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_AITIE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_AITIE_SHIFT)) & XSPI_RSER_AITIE_MASK)

#define XSPI_RSER_AAIE_MASK                      (0x8000U)
#define XSPI_RSER_AAIE_SHIFT                     (15U)
/*! AAIE - AHB Abort Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_AAIE(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_AAIE_SHIFT)) & XSPI_RSER_AAIE_MASK)

#define XSPI_RSER_RBDIE_MASK                     (0x10000U)
#define XSPI_RSER_RBDIE_SHIFT                    (16U)
/*! RBDIE - RX Buffer Drain Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_RBDIE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_RBDIE_SHIFT)) & XSPI_RSER_RBDIE_MASK)

#define XSPI_RSER_RBOIE_MASK                     (0x20000U)
#define XSPI_RSER_RBOIE_SHIFT                    (17U)
/*! RBOIE - RX Buffer Overflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_RBOIE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_RBOIE_SHIFT)) & XSPI_RSER_RBOIE_MASK)

#define XSPI_RSER_RBDDE_MASK                     (0x200000U)
#define XSPI_RSER_RBDDE_SHIFT                    (21U)
/*! RBDDE - RX Buffer Drain DMA Enable
 *  0b0..Disabled
 *  0b1..Enables
 */
#define XSPI_RSER_RBDDE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_RBDDE_SHIFT)) & XSPI_RSER_RBDDE_MASK)

#define XSPI_RSER_ILLINIE_MASK                   (0x800000U)
#define XSPI_RSER_ILLINIE_SHIFT                  (23U)
/*! ILLINIE - Illegal Instruction Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_ILLINIE(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_ILLINIE_SHIFT)) & XSPI_RSER_ILLINIE_MASK)

#define XSPI_RSER_DLLULIE_MASK                   (0x1000000U)
#define XSPI_RSER_DLLULIE_SHIFT                  (24U)
/*! DLLULIE - DLL unlock interrupt enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_DLLULIE(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_DLLULIE_SHIFT)) & XSPI_RSER_DLLULIE_MASK)

#define XSPI_RSER_TBFDE_MASK                     (0x2000000U)
#define XSPI_RSER_TBFDE_SHIFT                    (25U)
/*! TBFDE - TX Buffer Fill DMA Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_TBFDE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_TBFDE_SHIFT)) & XSPI_RSER_TBFDE_MASK)

#define XSPI_RSER_TBUIE_MASK                     (0x4000000U)
#define XSPI_RSER_TBUIE_SHIFT                    (26U)
/*! TBUIE - TX Buffer Underrun Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_TBUIE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_TBUIE_SHIFT)) & XSPI_RSER_TBUIE_MASK)

#define XSPI_RSER_TBFIE_MASK                     (0x8000000U)
#define XSPI_RSER_TBFIE_SHIFT                    (27U)
/*! TBFIE - TX Buffer Fill Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_TBFIE(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_TBFIE_SHIFT)) & XSPI_RSER_TBFIE_MASK)

#define XSPI_RSER_DLPFIE_MASK                    (0x80000000U)
#define XSPI_RSER_DLPFIE_SHIFT                   (31U)
/*! DLPFIE - Data Learning Pattern Failure Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_RSER_DLPFIE(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_RSER_DLPFIE_SHIFT)) & XSPI_RSER_DLPFIE_MASK)
/*! @} */

/*! @name SPNDST - Sequence Suspend Status */
/*! @{ */

#define XSPI_SPNDST_STATE_MASK                   (0x3U)
#define XSPI_SPNDST_STATE_SHIFT                  (0U)
/*! STATE - Suspended Resume State
 *  0b00..No suspended transaction pending
 *  0b01..Suspended transaction waiting to be resumed
 *  0b10..Not applicable
 *  0b11..Suspended transaction is resumed
 */
#define XSPI_SPNDST_STATE(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_SPNDST_STATE_SHIFT)) & XSPI_SPNDST_STATE_MASK)

#define XSPI_SPNDST_SPDSBUF_MASK                 (0x30U)
#define XSPI_SPNDST_SPDSBUF_SHIFT                (4U)
/*! SPDSBUF - Suspended Sub-Buffer */
#define XSPI_SPNDST_SPDSBUF(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SPNDST_SPDSBUF_SHIFT)) & XSPI_SPNDST_SPDSBUF_MASK)

#define XSPI_SPNDST_SPDBUF_MASK                  (0xC0U)
#define XSPI_SPNDST_SPDBUF_SHIFT                 (6U)
/*! SPDBUF - Suspended Buffer */
#define XSPI_SPNDST_SPDBUF(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_SPNDST_SPDBUF_SHIFT)) & XSPI_SPNDST_SPDBUF_MASK)

#define XSPI_SPNDST_DATLFT_MASK                  (0x3FE00U)
#define XSPI_SPNDST_DATLFT_SHIFT                 (9U)
/*! DATLFT - Data Left */
#define XSPI_SPNDST_DATLFT(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_SPNDST_DATLFT_SHIFT)) & XSPI_SPNDST_DATLFT_MASK)
/*! @} */

/*! @name SPTRCLR - Sequence Pointer Clear */
/*! @{ */

#define XSPI_SPTRCLR_BFPTRC_MASK                 (0x1U)
#define XSPI_SPTRCLR_BFPTRC_SHIFT                (0U)
/*! BFPTRC - Buffer Pointer Clear
 *  0b0..Conveys no useful information
 *  0b0..No action
 *  0b1..Clears the sequence pointer
 */
#define XSPI_SPTRCLR_BFPTRC(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SPTRCLR_BFPTRC_SHIFT)) & XSPI_SPTRCLR_BFPTRC_MASK)

#define XSPI_SPTRCLR_IPPTRC_MASK                 (0x100U)
#define XSPI_SPTRCLR_IPPTRC_SHIFT                (8U)
/*! IPPTRC - IP Pointer Clear
 *  0b0..Conveys no useful information
 *  0b0..No action
 *  0b1..Clears the sequence pointer
 */
#define XSPI_SPTRCLR_IPPTRC(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_SPTRCLR_IPPTRC_SHIFT)) & XSPI_SPTRCLR_IPPTRC_MASK)

#define XSPI_SPTRCLR_ABRT_CLR_MASK               (0x10000U)
#define XSPI_SPTRCLR_ABRT_CLR_SHIFT              (16U)
/*! ABRT_CLR - Flash Memory Abort-AHB Buffer Clear
 *  0b0..No action
 *  0b1..Clears pointers and terminates transaction
 */
#define XSPI_SPTRCLR_ABRT_CLR(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_SPTRCLR_ABRT_CLR_SHIFT)) & XSPI_SPTRCLR_ABRT_CLR_MASK)

#define XSPI_SPTRCLR_PREFETCH_DIS_MASK           (0x20000U)
#define XSPI_SPTRCLR_PREFETCH_DIS_SHIFT          (17U)
/*! PREFETCH_DIS - Prefetch Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SPTRCLR_PREFETCH_DIS(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_SPTRCLR_PREFETCH_DIS_SHIFT)) & XSPI_SPTRCLR_PREFETCH_DIS_MASK)

#define XSPI_SPTRCLR_STREAM_EN_MASK              (0x40000U)
#define XSPI_SPTRCLR_STREAM_EN_SHIFT             (18U)
/*! STREAM_EN - Enable Streaming Port
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SPTRCLR_STREAM_EN(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_SPTRCLR_STREAM_EN_SHIFT)) & XSPI_SPTRCLR_STREAM_EN_MASK)

#define XSPI_SPTRCLR_OTFAD_BNDRY_MASK            (0x3000000U)
#define XSPI_SPTRCLR_OTFAD_BNDRY_SHIFT           (24U)
/*! OTFAD_BNDRY - OTFAD Prefetch Address Boundary
 *  0b00..No prefetch address boundary
 *  0b01..Prefetch address boundary is 1K.
 */
#define XSPI_SPTRCLR_OTFAD_BNDRY(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_SPTRCLR_OTFAD_BNDRY_SHIFT)) & XSPI_SPTRCLR_OTFAD_BNDRY_MASK)
/*! @} */

/*! @name SFAD - Serial Flash Memory Top Address */
/*! @{ */

#define XSPI_SFAD_TPAD_MASK                      (0xFFFFFC00U)
#define XSPI_SFAD_TPAD_SHIFT                     (10U)
/*! TPAD - Top Address */
#define XSPI_SFAD_TPAD(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_SFAD_TPAD_SHIFT)) & XSPI_SFAD_TPAD_MASK)
/*! @} */

/* The count of XSPI_SFAD */
#define XSPI_SFAD_COUNT                          (1U)

/* The count of XSPI_SFAD */
#define XSPI_SFAD_COUNT2                         (2U)

/*! @name DLPR - Data Learning Pattern */
/*! @{ */

#define XSPI_DLPR_DLPV_MASK                      (0xFFFFFFFFU)
#define XSPI_DLPR_DLPV_SHIFT                     (0U)
/*! DLPV - Data Learning Pattern */
#define XSPI_DLPR_DLPV(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_DLPR_DLPV_SHIFT)) & XSPI_DLPR_DLPV_MASK)
/*! @} */

/*! @name FAIL_ADDR - Flash Memory A Failing Address Status */
/*! @{ */

#define XSPI_FAIL_ADDR_ADDR_MASK                 (0xFFFFFFFFU)
#define XSPI_FAIL_ADDR_ADDR_SHIFT                (0U)
/*! ADDR - Failing Address */
#define XSPI_FAIL_ADDR_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_FAIL_ADDR_ADDR_SHIFT)) & XSPI_FAIL_ADDR_ADDR_MASK)
/*! @} */

/* The count of XSPI_FAIL_ADDR */
#define XSPI_FAIL_ADDR_COUNT                     (1U)

/*! @name RBDR - RX Buffer Data */
/*! @{ */

#define XSPI_RBDR_RXDATA_MASK                    (0xFFFFFFFFU)
#define XSPI_RBDR_RXDATA_SHIFT                   (0U)
/*! RXDATA - RX Data */
#define XSPI_RBDR_RXDATA(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_RBDR_RXDATA_SHIFT)) & XSPI_RBDR_RXDATA_MASK)
/*! @} */

/* The count of XSPI_RBDR */
#define XSPI_RBDR_COUNT                          (64U)

/*! @name LUTKEY - LUT Key */
/*! @{ */

#define XSPI_LUTKEY_KEY_MASK                     (0xFFFFFFFFU)
#define XSPI_LUTKEY_KEY_SHIFT                    (0U)
/*! KEY - Key */
#define XSPI_LUTKEY_KEY(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_LUTKEY_KEY_SHIFT)) & XSPI_LUTKEY_KEY_MASK)
/*! @} */

/*! @name LCKCR - LUT Lock Configuration */
/*! @{ */

#define XSPI_LCKCR_LOCK_MASK                     (0x1U)
#define XSPI_LCKCR_LOCK_SHIFT                    (0U)
/*! LOCK - Lock LUT
 *  0b0..No action
 *  0b1..Locks
 */
#define XSPI_LCKCR_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_LCKCR_LOCK_SHIFT)) & XSPI_LCKCR_LOCK_MASK)

#define XSPI_LCKCR_UNLOCK_MASK                   (0x2U)
#define XSPI_LCKCR_UNLOCK_SHIFT                  (1U)
/*! UNLOCK - Unlock LUT
 *  0b0..No action
 *  0b1..Unlocks
 */
#define XSPI_LCKCR_UNLOCK(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_LCKCR_UNLOCK_SHIFT)) & XSPI_LCKCR_UNLOCK_MASK)
/*! @} */

/*! @name LUT - Lookup Table */
/*! @{ */

#define XSPI_LUT_OPRND0_MASK                     (0xFFU)
#define XSPI_LUT_OPRND0_SHIFT                    (0U)
/*! OPRND0 - Operand for INSTR0 */
#define XSPI_LUT_OPRND0(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_LUT_OPRND0_SHIFT)) & XSPI_LUT_OPRND0_MASK)

#define XSPI_LUT_PAD0_MASK                       (0x300U)
#define XSPI_LUT_PAD0_SHIFT                      (8U)
/*! PAD0 - Pads for INSTR0
 *  0b00..1
 *  0b01..2
 *  0b10..4
 *  0b11..8
 */
#define XSPI_LUT_PAD0(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_LUT_PAD0_SHIFT)) & XSPI_LUT_PAD0_MASK)

#define XSPI_LUT_INSTR0_MASK                     (0xFC00U)
#define XSPI_LUT_INSTR0_SHIFT                    (10U)
/*! INSTR0 - Instruction 0 */
#define XSPI_LUT_INSTR0(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_LUT_INSTR0_SHIFT)) & XSPI_LUT_INSTR0_MASK)

#define XSPI_LUT_OPRND1_MASK                     (0xFF0000U)
#define XSPI_LUT_OPRND1_SHIFT                    (16U)
/*! OPRND1 - Operand for INSTR1 */
#define XSPI_LUT_OPRND1(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_LUT_OPRND1_SHIFT)) & XSPI_LUT_OPRND1_MASK)

#define XSPI_LUT_PAD1_MASK                       (0x3000000U)
#define XSPI_LUT_PAD1_SHIFT                      (24U)
/*! PAD1 - Pads for INSTR1
 *  0b00..1
 *  0b01..2
 *  0b10..4
 *  0b11..8
 */
#define XSPI_LUT_PAD1(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_LUT_PAD1_SHIFT)) & XSPI_LUT_PAD1_MASK)

#define XSPI_LUT_INSTR1_MASK                     (0xFC000000U)
#define XSPI_LUT_INSTR1_SHIFT                    (26U)
/*! INSTR1 - Instruction 1 */
#define XSPI_LUT_INSTR1(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_LUT_INSTR1_SHIFT)) & XSPI_LUT_INSTR1_MASK)
/*! @} */

/*! @name BUF_ADDR_RANGE - AHB Buffer 0 Sub Buffer 0 Start and End Address Range..AHB Buffer 3 Sub Buffer 3 Start and End Address Range */
/*! @{ */

#define XSPI_BUF_ADDR_RANGE_STARTADR_MASK        (0xFFFFU)
#define XSPI_BUF_ADDR_RANGE_STARTADR_SHIFT       (0U)
/*! STARTADR - Start Address */
#define XSPI_BUF_ADDR_RANGE_STARTADR(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_BUF_ADDR_RANGE_STARTADR_SHIFT)) & XSPI_BUF_ADDR_RANGE_STARTADR_MASK)

#define XSPI_BUF_ADDR_RANGE_ENDADR_MASK          (0xFFFF0000U)
#define XSPI_BUF_ADDR_RANGE_ENDADR_SHIFT         (16U)
/*! ENDADR - End Address */
#define XSPI_BUF_ADDR_RANGE_ENDADR(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_BUF_ADDR_RANGE_ENDADR_SHIFT)) & XSPI_BUF_ADDR_RANGE_ENDADR_MASK)
/*! @} */

/* The count of XSPI_BUF_ADDR_RANGE */
#define XSPI_BUF_ADDR_RANGE_COUNT                (4U)

/* The count of XSPI_BUF_ADDR_RANGE */
#define XSPI_BUF_ADDR_RANGE_COUNT2               (4U)

/*! @name AHB_BUF_STATUS - AHB Buffer Status */
/*! @{ */

#define XSPI_AHB_BUF_STATUS_BUF0_0_MASK          (0x3U)
#define XSPI_AHB_BUF_STATUS_BUF0_0_SHIFT         (0U)
/*! BUF0_0 - AHB Buffer 0 Sub Buffer 0 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF0_0(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF0_0_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF0_0_MASK)

#define XSPI_AHB_BUF_STATUS_BUF0_1_MASK          (0xCU)
#define XSPI_AHB_BUF_STATUS_BUF0_1_SHIFT         (2U)
/*! BUF0_1 - AHB Buffer 0 Sub Buffer 1 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF0_1(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF0_1_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF0_1_MASK)

#define XSPI_AHB_BUF_STATUS_BUF0_2_MASK          (0x30U)
#define XSPI_AHB_BUF_STATUS_BUF0_2_SHIFT         (4U)
/*! BUF0_2 - AHB Buffer 0 Sub Buffer 2 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF0_2(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF0_2_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF0_2_MASK)

#define XSPI_AHB_BUF_STATUS_BUF0_3_MASK          (0xC0U)
#define XSPI_AHB_BUF_STATUS_BUF0_3_SHIFT         (6U)
/*! BUF0_3 - AHB Buffer 0 Sub Buffer 3 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF0_3(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF0_3_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF0_3_MASK)

#define XSPI_AHB_BUF_STATUS_BUF1_0_MASK          (0x300U)
#define XSPI_AHB_BUF_STATUS_BUF1_0_SHIFT         (8U)
/*! BUF1_0 - AHB Buffer 1 Sub Buffer 0 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF1_0(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF1_0_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF1_0_MASK)

#define XSPI_AHB_BUF_STATUS_BUF1_1_MASK          (0xC00U)
#define XSPI_AHB_BUF_STATUS_BUF1_1_SHIFT         (10U)
/*! BUF1_1 - AHB Buffer 1 Sub Buffer 1 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF1_1(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF1_1_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF1_1_MASK)

#define XSPI_AHB_BUF_STATUS_BUF1_2_MASK          (0x3000U)
#define XSPI_AHB_BUF_STATUS_BUF1_2_SHIFT         (12U)
/*! BUF1_2 - AHB Buffer 1 Sub Buffer 2 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF1_2(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF1_2_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF1_2_MASK)

#define XSPI_AHB_BUF_STATUS_BUF1_3_MASK          (0xC000U)
#define XSPI_AHB_BUF_STATUS_BUF1_3_SHIFT         (14U)
/*! BUF1_3 - AHB Buffer 1 Sub Buffer 3 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF1_3(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF1_3_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF1_3_MASK)

#define XSPI_AHB_BUF_STATUS_BUF2_0_MASK          (0x30000U)
#define XSPI_AHB_BUF_STATUS_BUF2_0_SHIFT         (16U)
/*! BUF2_0 - AHB Buffer 2 Sub Buffer 0 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF2_0(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF2_0_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF2_0_MASK)

#define XSPI_AHB_BUF_STATUS_BUF2_1_MASK          (0xC0000U)
#define XSPI_AHB_BUF_STATUS_BUF2_1_SHIFT         (18U)
/*! BUF2_1 - AHB Buffer 2 Sub Buffer 1 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF2_1(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF2_1_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF2_1_MASK)

#define XSPI_AHB_BUF_STATUS_BUF2_2_MASK          (0x300000U)
#define XSPI_AHB_BUF_STATUS_BUF2_2_SHIFT         (20U)
/*! BUF2_2 - AHB Buffer 2 Sub Buffer 2 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF2_2(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF2_2_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF2_2_MASK)

#define XSPI_AHB_BUF_STATUS_BUF2_3_MASK          (0xC00000U)
#define XSPI_AHB_BUF_STATUS_BUF2_3_SHIFT         (22U)
/*! BUF2_3 - AHB Buffer 2 Sub Buffer 3 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF2_3(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF2_3_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF2_3_MASK)

#define XSPI_AHB_BUF_STATUS_BUF3_0_MASK          (0x3000000U)
#define XSPI_AHB_BUF_STATUS_BUF3_0_SHIFT         (24U)
/*! BUF3_0 - AHB Buffer 3 Sub Buffer 0 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF3_0(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF3_0_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF3_0_MASK)

#define XSPI_AHB_BUF_STATUS_BUF3_1_MASK          (0xC000000U)
#define XSPI_AHB_BUF_STATUS_BUF3_1_SHIFT         (26U)
/*! BUF3_1 - AHB Buffer 3 Sub Buffer 1 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF3_1(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF3_1_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF3_1_MASK)

#define XSPI_AHB_BUF_STATUS_BUF3_2_MASK          (0x30000000U)
#define XSPI_AHB_BUF_STATUS_BUF3_2_SHIFT         (28U)
/*! BUF3_2 - AHB Buffer 3 Sub Buffer 2 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF3_2(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF3_2_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF3_2_MASK)

#define XSPI_AHB_BUF_STATUS_BUF3_3_MASK          (0xC0000000U)
#define XSPI_AHB_BUF_STATUS_BUF3_3_SHIFT         (30U)
/*! BUF3_3 - AHB Buffer 3 Sub Buffer 3 Status
 *  0b00..Empty
 *  0b01..Full
 *  0b10..Partially full
 */
#define XSPI_AHB_BUF_STATUS_BUF3_3(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_BUF_STATUS_BUF3_3_SHIFT)) & XSPI_AHB_BUF_STATUS_BUF3_3_MASK)
/*! @} */

/*! @name AHB_PERF_CTRL - AHB Buffer Hit/Miss Performance Monitor Control */
/*! @{ */

#define XSPI_AHB_PERF_CTRL_BUF0_EN_MASK          (0x1U)
#define XSPI_AHB_PERF_CTRL_BUF0_EN_SHIFT         (0U)
/*! BUF0_EN - Buffer 0 Counter Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_AHB_PERF_CTRL_BUF0_EN(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF0_EN_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF0_EN_MASK)

#define XSPI_AHB_PERF_CTRL_BUF1_EN_MASK          (0x2U)
#define XSPI_AHB_PERF_CTRL_BUF1_EN_SHIFT         (1U)
/*! BUF1_EN - Buffer 1 Counter Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_AHB_PERF_CTRL_BUF1_EN(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF1_EN_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF1_EN_MASK)

#define XSPI_AHB_PERF_CTRL_BUF2_EN_MASK          (0x4U)
#define XSPI_AHB_PERF_CTRL_BUF2_EN_SHIFT         (2U)
/*! BUF2_EN - Buffer 2 Counter Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_AHB_PERF_CTRL_BUF2_EN(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF2_EN_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF2_EN_MASK)

#define XSPI_AHB_PERF_CTRL_BUF3_EN_MASK          (0x8U)
#define XSPI_AHB_PERF_CTRL_BUF3_EN_SHIFT         (3U)
/*! BUF3_EN - Buffer 3 Counter Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_AHB_PERF_CTRL_BUF3_EN(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF3_EN_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF3_EN_MASK)

#define XSPI_AHB_PERF_CTRL_CNTSTP_MASK           (0x10U)
#define XSPI_AHB_PERF_CTRL_CNTSTP_SHIFT          (4U)
/*! CNTSTP - Performance Counter Stop
 *  0b0..No effect
 *  0b1..Stops counter
 */
#define XSPI_AHB_PERF_CTRL_CNTSTP(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_CNTSTP_SHIFT)) & XSPI_AHB_PERF_CTRL_CNTSTP_MASK)

#define XSPI_AHB_PERF_CTRL_CNTSTART_MASK         (0x20U)
#define XSPI_AHB_PERF_CTRL_CNTSTART_SHIFT        (5U)
/*! CNTSTART - Performance Counter Start
 *  0b0..No effect
 *  0b1..Starts
 */
#define XSPI_AHB_PERF_CTRL_CNTSTART(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_CNTSTART_SHIFT)) & XSPI_AHB_PERF_CTRL_CNTSTART_MASK)

#define XSPI_AHB_PERF_CTRL_BUF0_MISS_OVF_MASK    (0x1000U)
#define XSPI_AHB_PERF_CTRL_BUF0_MISS_OVF_SHIFT   (12U)
/*! BUF0_MISS_OVF - Buffer 0 Miss Counter Overflow
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define XSPI_AHB_PERF_CTRL_BUF0_MISS_OVF(x)      (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF0_MISS_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF0_MISS_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_BUF1_MISS_OVF_MASK    (0x2000U)
#define XSPI_AHB_PERF_CTRL_BUF1_MISS_OVF_SHIFT   (13U)
/*! BUF1_MISS_OVF - Buffer 1 Miss Counter Overflow
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define XSPI_AHB_PERF_CTRL_BUF1_MISS_OVF(x)      (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF1_MISS_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF1_MISS_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_BUF2_MISS_OVF_MASK    (0x4000U)
#define XSPI_AHB_PERF_CTRL_BUF2_MISS_OVF_SHIFT   (14U)
/*! BUF2_MISS_OVF - Buffer 2 Miss Counter Overflow
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define XSPI_AHB_PERF_CTRL_BUF2_MISS_OVF(x)      (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF2_MISS_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF2_MISS_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_BUF3_MISS_OVF_MASK    (0x8000U)
#define XSPI_AHB_PERF_CTRL_BUF3_MISS_OVF_SHIFT   (15U)
/*! BUF3_MISS_OVF - Buffer 3 Miss Counter Overflow
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define XSPI_AHB_PERF_CTRL_BUF3_MISS_OVF(x)      (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF3_MISS_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF3_MISS_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_BUF0_HIT_OVF_MASK     (0x10000U)
#define XSPI_AHB_PERF_CTRL_BUF0_HIT_OVF_SHIFT    (16U)
/*! BUF0_HIT_OVF - Buffer 0 Hit Counter Overflow
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define XSPI_AHB_PERF_CTRL_BUF0_HIT_OVF(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF0_HIT_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF0_HIT_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_BUF1_HIT_OVF_MASK     (0x20000U)
#define XSPI_AHB_PERF_CTRL_BUF1_HIT_OVF_SHIFT    (17U)
/*! BUF1_HIT_OVF - Buffer 1 Hit Counter Overflow
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define XSPI_AHB_PERF_CTRL_BUF1_HIT_OVF(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF1_HIT_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF1_HIT_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_BUF2_HIT_OVF_MASK     (0x40000U)
#define XSPI_AHB_PERF_CTRL_BUF2_HIT_OVF_SHIFT    (18U)
/*! BUF2_HIT_OVF - Buffer 2 Hit Counter Overflow
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define XSPI_AHB_PERF_CTRL_BUF2_HIT_OVF(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF2_HIT_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF2_HIT_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_BUF3_HIT_OVF_MASK     (0x80000U)
#define XSPI_AHB_PERF_CTRL_BUF3_HIT_OVF_SHIFT    (19U)
/*! BUF3_HIT_OVF - Buffer 3 Hit Counter Overflow
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define XSPI_AHB_PERF_CTRL_BUF3_HIT_OVF(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_BUF3_HIT_OVF_SHIFT)) & XSPI_AHB_PERF_CTRL_BUF3_HIT_OVF_MASK)

#define XSPI_AHB_PERF_CTRL_TCNTO_MASK            (0x100000U)
#define XSPI_AHB_PERF_CTRL_TCNTO_SHIFT           (20U)
/*! TCNTO - Time Counter Overflow
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define XSPI_AHB_PERF_CTRL_TCNTO(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_TCNTO_SHIFT)) & XSPI_AHB_PERF_CTRL_TCNTO_MASK)

#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL0_MASK     (0x3000000U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL0_SHIFT    (24U)
/*! SUB_BUF_SEL0 - Sub-buffer Selection for Buffer 0 Performance Monitoring
 *  0b00..0
 *  0b01..1
 *  0b10..2
 *  0b11..3
 */
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL0(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_SUB_BUF_SEL0_SHIFT)) & XSPI_AHB_PERF_CTRL_SUB_BUF_SEL0_MASK)

#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL1_MASK     (0xC000000U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL1_SHIFT    (26U)
/*! SUB_BUF_SEL1 - Sub-buffer Selection for Buffer 1 Performance Monitoring
 *  0b00..0
 *  0b01..1
 *  0b10..2
 *  0b11..3
 */
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL1(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_SUB_BUF_SEL1_SHIFT)) & XSPI_AHB_PERF_CTRL_SUB_BUF_SEL1_MASK)

#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL2_MASK     (0x30000000U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL2_SHIFT    (28U)
/*! SUB_BUF_SEL2 - Sub-buffer Selection for Buffer 2 Performance Monitoring
 *  0b00..0
 *  0b01..1
 *  0b10..2
 *  0b11..3
 */
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL2(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_SUB_BUF_SEL2_SHIFT)) & XSPI_AHB_PERF_CTRL_SUB_BUF_SEL2_MASK)

#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL3_MASK     (0xC0000000U)
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL3_SHIFT    (30U)
/*! SUB_BUF_SEL3 - Sub-buffer Selection for Buffer 3 Performance Monitoring
 *  0b00..0
 *  0b01..1
 *  0b10..2
 *  0b11..3
 */
#define XSPI_AHB_PERF_CTRL_SUB_BUF_SEL3(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_CTRL_SUB_BUF_SEL3_SHIFT)) & XSPI_AHB_PERF_CTRL_SUB_BUF_SEL3_MASK)
/*! @} */

/*! @name AHB_PERF_TIME_CNT - AHB Performance Monitor Time Counter */
/*! @{ */

#define XSPI_AHB_PERF_TIME_CNT_PERF_TIME_COUNT_MASK (0xFFFFFFFFU)
#define XSPI_AHB_PERF_TIME_CNT_PERF_TIME_COUNT_SHIFT (0U)
/*! PERF_TIME_COUNT - Time Count */
#define XSPI_AHB_PERF_TIME_CNT_PERF_TIME_COUNT(x) (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_TIME_CNT_PERF_TIME_COUNT_SHIFT)) & XSPI_AHB_PERF_TIME_CNT_PERF_TIME_COUNT_MASK)
/*! @} */

/*! @name AHB_PERF_BUF - AHB Buffer 0 Performance Monitor..AHB Buffer 3 Performance Monitor */
/*! @{ */

#define XSPI_AHB_PERF_BUF_PERF_MISS_CNT_MASK     (0xFFFFU)
#define XSPI_AHB_PERF_BUF_PERF_MISS_CNT_SHIFT    (0U)
/*! PERF_MISS_CNT - Performance Miss Count */
#define XSPI_AHB_PERF_BUF_PERF_MISS_CNT(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_BUF_PERF_MISS_CNT_SHIFT)) & XSPI_AHB_PERF_BUF_PERF_MISS_CNT_MASK)

#define XSPI_AHB_PERF_BUF_PERF_HIT_CNT_MASK      (0xFFFF0000U)
#define XSPI_AHB_PERF_BUF_PERF_HIT_CNT_SHIFT     (16U)
/*! PERF_HIT_CNT - Performance Hit Count */
#define XSPI_AHB_PERF_BUF_PERF_HIT_CNT(x)        (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_PERF_BUF_PERF_HIT_CNT_SHIFT)) & XSPI_AHB_PERF_BUF_PERF_HIT_CNT_MASK)
/*! @} */

/* The count of XSPI_AHB_PERF_BUF */
#define XSPI_AHB_PERF_BUF_COUNT                  (4U)

/*! @name AHRDYTO - AHB HREADY Timeout */
/*! @{ */

#define XSPI_AHRDYTO_HREADY_TO_MASK              (0xFFFFU)
#define XSPI_AHRDYTO_HREADY_TO_SHIFT             (0U)
/*! HREADY_TO - AHB HREADY Low Timeout Counter Value */
#define XSPI_AHRDYTO_HREADY_TO(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_AHRDYTO_HREADY_TO_SHIFT)) & XSPI_AHRDYTO_HREADY_TO_MASK)
/*! @} */

/*! @name AHB_ERR_PAYLOAD_HI - AHB Error Payload High */
/*! @{ */

#define XSPI_AHB_ERR_PAYLOAD_HI_ERR_PAYLOAD_H_MASK (0xFFFFFFFFU)
#define XSPI_AHB_ERR_PAYLOAD_HI_ERR_PAYLOAD_H_SHIFT (0U)
/*! ERR_PAYLOAD_H - Error Payload High */
#define XSPI_AHB_ERR_PAYLOAD_HI_ERR_PAYLOAD_H(x) (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_ERR_PAYLOAD_HI_ERR_PAYLOAD_H_SHIFT)) & XSPI_AHB_ERR_PAYLOAD_HI_ERR_PAYLOAD_H_MASK)
/*! @} */

/*! @name AHB_ERR_PAYLOAD_LO - AHB Error Payload Low */
/*! @{ */

#define XSPI_AHB_ERR_PAYLOAD_LO_ERR_PAYLOAD_L_MASK (0xFFFFFFFFU)
#define XSPI_AHB_ERR_PAYLOAD_LO_ERR_PAYLOAD_L_SHIFT (0U)
/*! ERR_PAYLOAD_L - Error Payload Low */
#define XSPI_AHB_ERR_PAYLOAD_LO_ERR_PAYLOAD_L(x) (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_ERR_PAYLOAD_LO_ERR_PAYLOAD_L_SHIFT)) & XSPI_AHB_ERR_PAYLOAD_LO_ERR_PAYLOAD_L_MASK)
/*! @} */

/*! @name AHB_RD_ERR_ADDR - AHB Read Error Address */
/*! @{ */

#define XSPI_AHB_RD_ERR_ADDR_READDR_MASK         (0xFFFFFFFFU)
#define XSPI_AHB_RD_ERR_ADDR_READDR_SHIFT        (0U)
/*! READDR - Read Error Address */
#define XSPI_AHB_RD_ERR_ADDR_READDR(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_RD_ERR_ADDR_READDR_SHIFT)) & XSPI_AHB_RD_ERR_ADDR_READDR_MASK)
/*! @} */

/*! @name AHB_RD_ERR_MID - AHB Read Error Manager ID */
/*! @{ */

#define XSPI_AHB_RD_ERR_MID_REMID_MASK           (0x1FU)
#define XSPI_AHB_RD_ERR_MID_REMID_SHIFT          (0U)
/*! REMID - Read Error Manager ID */
#define XSPI_AHB_RD_ERR_MID_REMID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_AHB_RD_ERR_MID_REMID_SHIFT)) & XSPI_AHB_RD_ERR_MID_REMID_MASK)
/*! @} */

/*! @name SPNDST_ADDR - Suspend Transaction Address */
/*! @{ */

#define XSPI_SPNDST_ADDR_ASAHBR_MASK             (0xFFFFFFF8U)
#define XSPI_SPNDST_ADDR_ASAHBR_SHIFT            (3U)
/*! ASAHBR - Address of Suspended AHB Read Transaction */
#define XSPI_SPNDST_ADDR_ASAHBR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_SPNDST_ADDR_ASAHBR_SHIFT)) & XSPI_SPNDST_ADDR_ASAHBR_MASK)
/*! @} */

/*! @name PPWF_TCNT - Page Program Wait Time Counter */
/*! @{ */

#define XSPI_PPWF_TCNT_PPWTC_MASK                (0xFFFFFFFFU)
#define XSPI_PPWF_TCNT_PPWTC_SHIFT               (0U)
/*! PPWTC - Page Program Wait Time Counter Value */
#define XSPI_PPWF_TCNT_PPWTC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_PPWF_TCNT_PPWTC_SHIFT)) & XSPI_PPWF_TCNT_PPWTC_MASK)
/*! @} */

/*! @name PPW_RDSR - Page Program Wait Read Status */
/*! @{ */

#define XSPI_PPW_RDSR_RDSR_MASK                  (0xFFFFU)
#define XSPI_PPW_RDSR_RDSR_SHIFT                 (0U)
/*! RDSR - Value of Flash Status Register Read */
#define XSPI_PPW_RDSR_RDSR(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_PPW_RDSR_RDSR_SHIFT)) & XSPI_PPW_RDSR_RDSR_MASK)

#define XSPI_PPW_RDSR_RDSR_VAL_CHK_MASK          (0x400000U)
#define XSPI_PPW_RDSR_RDSR_VAL_CHK_SHIFT         (22U)
/*! RDSR_VAL_CHK - RDSR Value Check
 *  0b0..Check for 0
 *  0b1..Check for 1
 */
#define XSPI_PPW_RDSR_RDSR_VAL_CHK(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_PPW_RDSR_RDSR_VAL_CHK_SHIFT)) & XSPI_PPW_RDSR_RDSR_VAL_CHK_MASK)

#define XSPI_PPW_RDSR_RDSR_HWORD_SEL_MASK        (0x800000U)
#define XSPI_PPW_RDSR_RDSR_HWORD_SEL_SHIFT       (23U)
/*! RDSR_HWORD_SEL - RDSR Half Word Select
 *  0b0..RDSR contains 16 least significant bits (15:0) of RDSR read from flash.
 *  0b1..RDSR contains 16 most significant bits (31:16) of RDSR read from flash.
 */
#define XSPI_PPW_RDSR_RDSR_HWORD_SEL(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_PPW_RDSR_RDSR_HWORD_SEL_SHIFT)) & XSPI_PPW_RDSR_RDSR_HWORD_SEL_MASK)

#define XSPI_PPW_RDSR_LOC_MASK                   (0xF000000U)
#define XSPI_PPW_RDSR_LOC_SHIFT                  (24U)
/*! LOC - Location of RDSR */
#define XSPI_PPW_RDSR_LOC(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_PPW_RDSR_LOC_SHIFT)) & XSPI_PPW_RDSR_LOC_MASK)

#define XSPI_PPW_RDSR_VALID_MASK                 (0x80000000U)
#define XSPI_PPW_RDSR_VALID_SHIFT                (31U)
/*! VALID - Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define XSPI_PPW_RDSR_VALID(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_PPW_RDSR_VALID_SHIFT)) & XSPI_PPW_RDSR_VALID_MASK)
/*! @} */

/*! @name IPEDCTXIV - IPED Context Initial Vector */
/*! @{ */

#define XSPI_IPEDCTXIV_CTX_IV_MASK               (0xFFFFFFFFU)
#define XSPI_IPEDCTXIV_CTX_IV_SHIFT              (0U)
/*! CTX_IV - 32 bits of IV for the context region */
#define XSPI_IPEDCTXIV_CTX_IV(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXIV_CTX_IV_SHIFT)) & XSPI_IPEDCTXIV_CTX_IV_MASK)
/*! @} */

/* The count of XSPI_IPEDCTXIV */
#define XSPI_IPEDCTXIV_COUNT                     (16U)

/* The count of XSPI_IPEDCTXIV */
#define XSPI_IPEDCTXIV_COUNT2                    (2U)

/*! @name IPEDCTXSTART - IPED Start Address Region */
/*! @{ */

#define XSPI_IPEDCTXSTART_GCM_MASK               (0x1U)
#define XSPI_IPEDCTXSTART_GCM_SHIFT              (0U)
/*! GCM - GCM Mode Region
 *  0b0..CTR
 *  0b1..GCM
 */
#define XSPI_IPEDCTXSTART_GCM(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXSTART_GCM_SHIFT)) & XSPI_IPEDCTXSTART_GCM_MASK)

#define XSPI_IPEDCTXSTART_SADD_MASK              (0xFFFFFF00U)
#define XSPI_IPEDCTXSTART_SADD_SHIFT             (8U)
/*! SADD - Start Address */
#define XSPI_IPEDCTXSTART_SADD(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXSTART_SADD_SHIFT)) & XSPI_IPEDCTXSTART_SADD_MASK)
/*! @} */

/* The count of XSPI_IPEDCTXSTART */
#define XSPI_IPEDCTXSTART_COUNT                  (16U)

/*! @name IPEDCTXEND - IPED End Address Region */
/*! @{ */

#define XSPI_IPEDCTXEND_END_ADDRESS_MASK         (0xFFFFFF00U)
#define XSPI_IPEDCTXEND_END_ADDRESS_SHIFT        (8U)
/*! END_ADDRESS - End Address */
#define XSPI_IPEDCTXEND_END_ADDRESS(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXEND_END_ADDRESS_SHIFT)) & XSPI_IPEDCTXEND_END_ADDRESS_MASK)
/*! @} */

/* The count of XSPI_IPEDCTXEND */
#define XSPI_IPEDCTXEND_COUNT                    (16U)

/*! @name IPEDCTXAAD - IPED Context Additional Authentication Data */
/*! @{ */

#define XSPI_IPEDCTXAAD_CTX_AAD_MASK             (0xFFFFFFFFU)
#define XSPI_IPEDCTXAAD_CTX_AAD_SHIFT            (0U)
/*! CTX_AAD - 32 bits of AAD for the region */
#define XSPI_IPEDCTXAAD_CTX_AAD(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXAAD_CTX_AAD_SHIFT)) & XSPI_IPEDCTXAAD_CTX_AAD_MASK)
/*! @} */

/* The count of XSPI_IPEDCTXAAD */
#define XSPI_IPEDCTXAAD_COUNT                    (16U)

/* The count of XSPI_IPEDCTXAAD */
#define XSPI_IPEDCTXAAD_COUNT2                   (2U)

/*! @name IPEDCTRL - IPED Function Control */
/*! @{ */

#define XSPI_IPEDCTRL_CONFIG_MASK                (0x1U)
#define XSPI_IPEDCTRL_CONFIG_SHIFT               (0U)
/*! CONFIG - IPED CTR/GCM Interface Configure
 *  0b0..Prince 12 rounds
 *  0b1..Prince 22 rounds
 */
#define XSPI_IPEDCTRL_CONFIG(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_CONFIG_SHIFT)) & XSPI_IPEDCTRL_CONFIG_MASK)

#define XSPI_IPEDCTRL_IPED_EN_MASK               (0x2U)
#define XSPI_IPEDCTRL_IPED_EN_SHIFT              (1U)
/*! IPED_EN - IPED CTR-GCM Interface Enable
 *  0b0..Bypasses IPED logic and allows writing of unencrypted or undecrypted data
 *  0b1..Enables
 */
#define XSPI_IPEDCTRL_IPED_EN(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPED_EN_SHIFT)) & XSPI_IPEDCTRL_IPED_EN_MASK)

#define XSPI_IPEDCTRL_IPWR_EN_MASK               (0x4U)
#define XSPI_IPEDCTRL_IPWR_EN_SHIFT              (2U)
/*! IPWR_EN - IP Write IPED XEX or CTR Mode Enable
 *  0b0..Bypasses IPS-based data and writes unencrypted data
 *  0b1..Enables
 */
#define XSPI_IPEDCTRL_IPWR_EN(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPWR_EN_SHIFT)) & XSPI_IPEDCTRL_IPWR_EN_MASK)

#define XSPI_IPEDCTRL_AHBWR_EN_MASK              (0x8U)
#define XSPI_IPEDCTRL_AHBWR_EN_SHIFT             (3U)
/*! AHBWR_EN - AHB Write IPED XEX or CTR Mode Encryption Enable
 *  0b0..Bypasses AHB-based data and writes unencrypted
 *  0b1..Enables
 */
#define XSPI_IPEDCTRL_AHBWR_EN(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_AHBWR_EN_SHIFT)) & XSPI_IPEDCTRL_AHBWR_EN_MASK)

#define XSPI_IPEDCTRL_AHBRD_EN_MASK              (0x10U)
#define XSPI_IPEDCTRL_AHBRD_EN_SHIFT             (4U)
/*! AHBRD_EN - AHB Read IPED XEX or CTR Mode Decryption Enable
 *  0b0..Bypasses AHB-based data and reads unencrypted
 *  0b1..Enables
 */
#define XSPI_IPEDCTRL_AHBRD_EN(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_AHBRD_EN_SHIFT)) & XSPI_IPEDCTRL_AHBRD_EN_MASK)

#define XSPI_IPEDCTRL_IPGCMWR_MASK               (0x40U)
#define XSPI_IPEDCTRL_IPGCMWR_SHIFT              (6U)
/*! IPGCMWR - IP Write GCM Enable
 *  0b0..Bypasses IPS-based data and writes unencrypted data
 *  0b1..Enables
 */
#define XSPI_IPEDCTRL_IPGCMWR(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPGCMWR_SHIFT)) & XSPI_IPEDCTRL_IPGCMWR_MASK)

#define XSPI_IPEDCTRL_AHGCMWR_MASK               (0x80U)
#define XSPI_IPEDCTRL_AHGCMWR_SHIFT              (7U)
/*! AHGCMWR - AHB Write IPED GCM Encryption Enable
 *  0b0..Bypasses AHB data and writes unencrypted data
 *  0b1..Enables
 */
#define XSPI_IPEDCTRL_AHGCMWR(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_AHGCMWR_SHIFT)) & XSPI_IPEDCTRL_AHGCMWR_MASK)

#define XSPI_IPEDCTRL_AHBGCMRD_MASK              (0x100U)
#define XSPI_IPEDCTRL_AHBGCMRD_SHIFT             (8U)
/*! AHBGCMRD - AHB Read IPED GCM Decryption Enable
 *  0b0..Bypasses AHB data and reads unencrypted data
 *  0b1..Enables
 */
#define XSPI_IPEDCTRL_AHBGCMRD(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_AHBGCMRD_SHIFT)) & XSPI_IPEDCTRL_AHBGCMRD_MASK)

#define XSPI_IPEDCTRL_IPED_PROTECT_MASK          (0x200U)
#define XSPI_IPEDCTRL_IPED_PROTECT_SHIFT         (9U)
/*! IPED_PROTECT - IPED Protection
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_IPEDCTRL_IPED_PROTECT(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPED_PROTECT_SHIFT)) & XSPI_IPEDCTRL_IPED_PROTECT_MASK)

#define XSPI_IPEDCTRL_IPED_SWRESET_MASK          (0x400U)
#define XSPI_IPEDCTRL_IPED_SWRESET_SHIFT         (10U)
/*! IPED_SWRESET - IPED CTR/GCM and XEX Interface Software Reset
 *  0b0..No reset
 *  0b1..Resets
 */
#define XSPI_IPEDCTRL_IPED_SWRESET(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPED_SWRESET_SHIFT)) & XSPI_IPEDCTRL_IPED_SWRESET_MASK)

#define XSPI_IPEDCTRL_IPED_XEX_EN_MASK           (0x800U)
#define XSPI_IPEDCTRL_IPED_XEX_EN_SHIFT          (11U)
/*! IPED_XEX_EN - IPED XEX Interface Enable
 *  0b0..Bypasses IPED logic and writes unencrypted or undecrypted data
 *  0b1..Enables
 */
#define XSPI_IPEDCTRL_IPED_XEX_EN(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPED_XEX_EN_SHIFT)) & XSPI_IPEDCTRL_IPED_XEX_EN_MASK)

#define XSPI_IPEDCTRL_IPS_GCM_MASK               (0x10000U)
#define XSPI_IPEDCTRL_IPS_GCM_SHIFT              (16U)
/*! IPS_GCM - IPS Transaction Region Status
 *  0b0..Non-GCM region, either CTR or bypass
 *  0b1..GCM region
 */
#define XSPI_IPEDCTRL_IPS_GCM(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTRL_IPS_GCM_SHIFT)) & XSPI_IPEDCTRL_IPS_GCM_MASK)
/*! @} */

/*! @name IPEDCTXCTRL - IPED Context Control 0..IPED Context Control 1 */
/*! @{ */

#define XSPI_IPEDCTXCTRL_CTX0_FREEZE_MASK        (0x3U)
#define XSPI_IPEDCTXCTRL_CTX0_FREEZE_SHIFT       (0U)
/*! CTX0_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX0_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX0_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX0_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX1_FREEZE_MASK        (0xCU)
#define XSPI_IPEDCTXCTRL_CTX1_FREEZE_SHIFT       (2U)
/*! CTX1_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX1_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX1_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX1_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX2_FREEZE_MASK        (0x30U)
#define XSPI_IPEDCTXCTRL_CTX2_FREEZE_SHIFT       (4U)
/*! CTX2_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX2_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX2_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX2_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX3_FREEZE_MASK        (0xC0U)
#define XSPI_IPEDCTXCTRL_CTX3_FREEZE_SHIFT       (6U)
/*! CTX3_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX3_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX3_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX3_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX4_FREEZE_MASK        (0x300U)
#define XSPI_IPEDCTXCTRL_CTX4_FREEZE_SHIFT       (8U)
/*! CTX4_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX4_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX4_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX4_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX5_FREEZE_MASK        (0xC00U)
#define XSPI_IPEDCTXCTRL_CTX5_FREEZE_SHIFT       (10U)
/*! CTX5_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX5_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX5_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX5_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX6_FREEZE_MASK        (0x3000U)
#define XSPI_IPEDCTXCTRL_CTX6_FREEZE_SHIFT       (12U)
/*! CTX6_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX6_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX6_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX6_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX7_FREEZE_MASK        (0xC000U)
#define XSPI_IPEDCTXCTRL_CTX7_FREEZE_SHIFT       (14U)
/*! CTX7_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX7_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX7_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX7_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX8_FREEZE_MASK        (0x30000U)
#define XSPI_IPEDCTXCTRL_CTX8_FREEZE_SHIFT       (16U)
/*! CTX8_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX8_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX8_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX8_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX9_FREEZE_MASK        (0xC0000U)
#define XSPI_IPEDCTXCTRL_CTX9_FREEZE_SHIFT       (18U)
/*! CTX9_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX9_FREEZE(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX9_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX9_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX10_FREEZE_MASK       (0x300000U)
#define XSPI_IPEDCTXCTRL_CTX10_FREEZE_SHIFT      (20U)
/*! CTX10_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX10_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX10_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX10_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX11_FREEZE_MASK       (0xC00000U)
#define XSPI_IPEDCTXCTRL_CTX11_FREEZE_SHIFT      (22U)
/*! CTX11_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX11_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX11_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX11_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX12_FREEZE_MASK       (0x3000000U)
#define XSPI_IPEDCTXCTRL_CTX12_FREEZE_SHIFT      (24U)
/*! CTX12_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX12_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX12_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX12_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX13_FREEZE_MASK       (0xC000000U)
#define XSPI_IPEDCTXCTRL_CTX13_FREEZE_SHIFT      (26U)
/*! CTX13_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX13_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX13_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX13_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX14_FREEZE_MASK       (0x30000000U)
#define XSPI_IPEDCTXCTRL_CTX14_FREEZE_SHIFT      (28U)
/*! CTX14_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX14_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX14_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX14_FREEZE_MASK)

#define XSPI_IPEDCTXCTRL_CTX15_FREEZE_MASK       (0xC0000000U)
#define XSPI_IPEDCTXCTRL_CTX15_FREEZE_SHIFT      (30U)
/*! CTX15_FREEZE - CTX Freeze */
#define XSPI_IPEDCTXCTRL_CTX15_FREEZE(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_IPEDCTXCTRL_CTX15_FREEZE_SHIFT)) & XSPI_IPEDCTXCTRL_CTX15_FREEZE_MASK)
/*! @} */

/* The count of XSPI_IPEDCTXCTRL */
#define XSPI_IPEDCTXCTRL_COUNT                   (2U)

/*! @name FRAD0_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD0_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD0_WORD0_STARTADR_SHIFT          (16U)
/*! STARTADR - Start Address */
#define XSPI_FRAD0_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD0_STARTADR_SHIFT)) & XSPI_FRAD0_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD0_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD0_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD0_WORD1_ENDADR_SHIFT            (16U)
/*! ENDADR - End Address */
#define XSPI_FRAD0_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD1_ENDADR_SHIFT)) & XSPI_FRAD0_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD0_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD0_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD0_WORD2_MD0ACP_SHIFT            (0U)
/*! MD0ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD0_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD0_WORD2_MD0ACP_MASK)

#define XSPI_FRAD0_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD0_WORD2_MD1ACP_SHIFT            (3U)
/*! MD1ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD0_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD0_WORD2_MD1ACP_MASK)

#define XSPI_FRAD0_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD0_WORD2_EALO_SHIFT              (24U)
/*! EALO - Exclusive Access Lock Owner */
#define XSPI_FRAD0_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD2_EALO_SHIFT)) & XSPI_FRAD0_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD0_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD0_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD0_WORD3_EAL_SHIFT               (24U)
/*! EAL - Exclusive Access Lock
 *  0b00..No lock
 *  0b01..No action
 *  0b10..Enables lock
 *  0b11..Enables exclusive access lock
 */
#define XSPI_FRAD0_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD3_EAL_SHIFT)) & XSPI_FRAD0_WORD3_EAL_MASK)

#define XSPI_FRAD0_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD0_WORD3_LOCK_SHIFT              (29U)
/*! LOCK - Descriptor Lock
 *  0b00..Unlocks
 *  0b01..Locks until hard reset
 *  0b10..Locks except for manager
 *  0b11..Locks
 */
#define XSPI_FRAD0_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD3_LOCK_SHIFT)) & XSPI_FRAD0_WORD3_LOCK_MASK)

#define XSPI_FRAD0_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD0_WORD3_VLD_SHIFT               (31U)
/*! VLD - Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define XSPI_FRAD0_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD3_VLD_SHIFT)) & XSPI_FRAD0_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD0_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD0_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD0_WORD4_CMP_ADDR_SHIFT          (0U)
/*! CMP_ADDR - Capture Address */
#define XSPI_FRAD0_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD0_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD0_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD0_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD0_WORD5_CMP_MDID_SHIFT          (0U)
/*! CMP_MDID - Captured Manager Value */
#define XSPI_FRAD0_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD0_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD0_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD0_WORD5_CMP_SA_SHIFT            (6U)
/*! CMP_SA - Captured Secure Attribute
 *  0b0..Non-secure
 *  0b1..Secure
 */
#define XSPI_FRAD0_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD0_WORD5_CMP_SA_MASK)

#define XSPI_FRAD0_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD0_WORD5_CMP_PA_SHIFT            (7U)
/*! CMP_PA - Captured Privilege Attribute
 *  0b0..Non-privileged
 *  0b1..Privileged
 */
#define XSPI_FRAD0_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD0_WORD5_CMP_PA_MASK)

#define XSPI_FRAD0_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD0_WORD5_CMP_ERR_SHIFT           (29U)
/*! CMP_ERR - Comparison Error
 *  0b0..No error
 *  0b1..Error
 */
#define XSPI_FRAD0_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD0_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD0_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD0_WORD5_CMPVALID_SHIFT          (30U)
/*! CMPVALID - Comparison Valid
 *  0b0..Not available
 *  0b1..Available
 */
#define XSPI_FRAD0_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD0_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD0_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name FRAD1_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD1_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD1_WORD0_STARTADR_SHIFT          (16U)
/*! STARTADR - Start Address */
#define XSPI_FRAD1_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD0_STARTADR_SHIFT)) & XSPI_FRAD1_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD1_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD1_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD1_WORD1_ENDADR_SHIFT            (16U)
/*! ENDADR - End Address */
#define XSPI_FRAD1_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD1_ENDADR_SHIFT)) & XSPI_FRAD1_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD1_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD1_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD1_WORD2_MD0ACP_SHIFT            (0U)
/*! MD0ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD1_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD1_WORD2_MD0ACP_MASK)

#define XSPI_FRAD1_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD1_WORD2_MD1ACP_SHIFT            (3U)
/*! MD1ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD1_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD1_WORD2_MD1ACP_MASK)

#define XSPI_FRAD1_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD1_WORD2_EALO_SHIFT              (24U)
/*! EALO - Exclusive Access Lock Owner */
#define XSPI_FRAD1_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD2_EALO_SHIFT)) & XSPI_FRAD1_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD1_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD1_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD1_WORD3_EAL_SHIFT               (24U)
/*! EAL - Exclusive Access Lock
 *  0b00..No lock
 *  0b01..No action
 *  0b10..Enables lock
 *  0b11..Enables exclusive access lock
 */
#define XSPI_FRAD1_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD3_EAL_SHIFT)) & XSPI_FRAD1_WORD3_EAL_MASK)

#define XSPI_FRAD1_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD1_WORD3_LOCK_SHIFT              (29U)
/*! LOCK - Descriptor Lock
 *  0b00..Unlocks
 *  0b01..Locks until hard reset
 *  0b10..Locks except for manager
 *  0b11..Locks
 */
#define XSPI_FRAD1_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD3_LOCK_SHIFT)) & XSPI_FRAD1_WORD3_LOCK_MASK)

#define XSPI_FRAD1_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD1_WORD3_VLD_SHIFT               (31U)
/*! VLD - Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define XSPI_FRAD1_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD3_VLD_SHIFT)) & XSPI_FRAD1_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD1_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD1_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD1_WORD4_CMP_ADDR_SHIFT          (0U)
/*! CMP_ADDR - Capture Address */
#define XSPI_FRAD1_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD1_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD1_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD1_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD1_WORD5_CMP_MDID_SHIFT          (0U)
/*! CMP_MDID - Captured Manager Value */
#define XSPI_FRAD1_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD1_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD1_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD1_WORD5_CMP_SA_SHIFT            (6U)
/*! CMP_SA - Captured Secure Attribute
 *  0b0..Non-secure
 *  0b1..Secure
 */
#define XSPI_FRAD1_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD1_WORD5_CMP_SA_MASK)

#define XSPI_FRAD1_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD1_WORD5_CMP_PA_SHIFT            (7U)
/*! CMP_PA - Captured Privilege Attribute
 *  0b0..Non-privileged
 *  0b1..Privileged
 */
#define XSPI_FRAD1_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD1_WORD5_CMP_PA_MASK)

#define XSPI_FRAD1_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD1_WORD5_CMP_ERR_SHIFT           (29U)
/*! CMP_ERR - Comparison Error
 *  0b0..No error
 *  0b1..Error
 */
#define XSPI_FRAD1_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD1_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD1_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD1_WORD5_CMPVALID_SHIFT          (30U)
/*! CMPVALID - Comparison Valid
 *  0b0..Not available
 *  0b1..Available
 */
#define XSPI_FRAD1_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD1_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD1_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name FRAD2_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD2_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD2_WORD0_STARTADR_SHIFT          (16U)
/*! STARTADR - Start Address */
#define XSPI_FRAD2_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD0_STARTADR_SHIFT)) & XSPI_FRAD2_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD2_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD2_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD2_WORD1_ENDADR_SHIFT            (16U)
/*! ENDADR - End Address */
#define XSPI_FRAD2_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD1_ENDADR_SHIFT)) & XSPI_FRAD2_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD2_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD2_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD2_WORD2_MD0ACP_SHIFT            (0U)
/*! MD0ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD2_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD2_WORD2_MD0ACP_MASK)

#define XSPI_FRAD2_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD2_WORD2_MD1ACP_SHIFT            (3U)
/*! MD1ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD2_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD2_WORD2_MD1ACP_MASK)

#define XSPI_FRAD2_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD2_WORD2_EALO_SHIFT              (24U)
/*! EALO - Exclusive Access Lock Owner */
#define XSPI_FRAD2_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD2_EALO_SHIFT)) & XSPI_FRAD2_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD2_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD2_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD2_WORD3_EAL_SHIFT               (24U)
/*! EAL - Exclusive Access Lock
 *  0b00..No lock
 *  0b01..No action
 *  0b10..Enables lock
 *  0b11..Enables exclusive access lock
 */
#define XSPI_FRAD2_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD3_EAL_SHIFT)) & XSPI_FRAD2_WORD3_EAL_MASK)

#define XSPI_FRAD2_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD2_WORD3_LOCK_SHIFT              (29U)
/*! LOCK - Descriptor Lock
 *  0b00..Unlocks
 *  0b01..Locks until hard reset
 *  0b10..Locks except for manager
 *  0b11..Locks
 */
#define XSPI_FRAD2_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD3_LOCK_SHIFT)) & XSPI_FRAD2_WORD3_LOCK_MASK)

#define XSPI_FRAD2_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD2_WORD3_VLD_SHIFT               (31U)
/*! VLD - Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define XSPI_FRAD2_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD3_VLD_SHIFT)) & XSPI_FRAD2_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD2_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD2_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD2_WORD4_CMP_ADDR_SHIFT          (0U)
/*! CMP_ADDR - Capture Address */
#define XSPI_FRAD2_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD2_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD2_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD2_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD2_WORD5_CMP_MDID_SHIFT          (0U)
/*! CMP_MDID - Captured Manager Value */
#define XSPI_FRAD2_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD2_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD2_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD2_WORD5_CMP_SA_SHIFT            (6U)
/*! CMP_SA - Captured Secure Attribute
 *  0b0..Non-secure
 *  0b1..Secure
 */
#define XSPI_FRAD2_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD2_WORD5_CMP_SA_MASK)

#define XSPI_FRAD2_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD2_WORD5_CMP_PA_SHIFT            (7U)
/*! CMP_PA - Captured Privilege Attribute
 *  0b0..Non-privileged
 *  0b1..Privileged
 */
#define XSPI_FRAD2_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD2_WORD5_CMP_PA_MASK)

#define XSPI_FRAD2_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD2_WORD5_CMP_ERR_SHIFT           (29U)
/*! CMP_ERR - Comparison Error
 *  0b0..No error
 *  0b1..Error
 */
#define XSPI_FRAD2_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD2_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD2_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD2_WORD5_CMPVALID_SHIFT          (30U)
/*! CMPVALID - Comparison Valid
 *  0b0..Not available
 *  0b1..Available
 */
#define XSPI_FRAD2_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD2_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD2_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name FRAD3_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD3_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD3_WORD0_STARTADR_SHIFT          (16U)
/*! STARTADR - Start Address */
#define XSPI_FRAD3_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD0_STARTADR_SHIFT)) & XSPI_FRAD3_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD3_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD3_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD3_WORD1_ENDADR_SHIFT            (16U)
/*! ENDADR - End Address */
#define XSPI_FRAD3_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD1_ENDADR_SHIFT)) & XSPI_FRAD3_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD3_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD3_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD3_WORD2_MD0ACP_SHIFT            (0U)
/*! MD0ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD3_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD3_WORD2_MD0ACP_MASK)

#define XSPI_FRAD3_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD3_WORD2_MD1ACP_SHIFT            (3U)
/*! MD1ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD3_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD3_WORD2_MD1ACP_MASK)

#define XSPI_FRAD3_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD3_WORD2_EALO_SHIFT              (24U)
/*! EALO - Exclusive Access Lock Owner */
#define XSPI_FRAD3_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD2_EALO_SHIFT)) & XSPI_FRAD3_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD3_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD3_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD3_WORD3_EAL_SHIFT               (24U)
/*! EAL - Exclusive Access Lock
 *  0b00..No lock
 *  0b01..No action
 *  0b10..Enables lock
 *  0b11..Enables exclusive access lock
 */
#define XSPI_FRAD3_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD3_EAL_SHIFT)) & XSPI_FRAD3_WORD3_EAL_MASK)

#define XSPI_FRAD3_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD3_WORD3_LOCK_SHIFT              (29U)
/*! LOCK - Descriptor Lock
 *  0b00..Unlocks
 *  0b01..Locks until hard reset
 *  0b10..Locks except for manager
 *  0b11..Locks
 */
#define XSPI_FRAD3_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD3_LOCK_SHIFT)) & XSPI_FRAD3_WORD3_LOCK_MASK)

#define XSPI_FRAD3_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD3_WORD3_VLD_SHIFT               (31U)
/*! VLD - Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define XSPI_FRAD3_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD3_VLD_SHIFT)) & XSPI_FRAD3_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD3_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD3_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD3_WORD4_CMP_ADDR_SHIFT          (0U)
/*! CMP_ADDR - Capture Address */
#define XSPI_FRAD3_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD3_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD3_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD3_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD3_WORD5_CMP_MDID_SHIFT          (0U)
/*! CMP_MDID - Captured Manager Value */
#define XSPI_FRAD3_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD3_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD3_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD3_WORD5_CMP_SA_SHIFT            (6U)
/*! CMP_SA - Captured Secure Attribute
 *  0b0..Non-secure
 *  0b1..Secure
 */
#define XSPI_FRAD3_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD3_WORD5_CMP_SA_MASK)

#define XSPI_FRAD3_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD3_WORD5_CMP_PA_SHIFT            (7U)
/*! CMP_PA - Captured Privilege Attribute
 *  0b0..Non-privileged
 *  0b1..Privileged
 */
#define XSPI_FRAD3_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD3_WORD5_CMP_PA_MASK)

#define XSPI_FRAD3_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD3_WORD5_CMP_ERR_SHIFT           (29U)
/*! CMP_ERR - Comparison Error
 *  0b0..No error
 *  0b1..Error
 */
#define XSPI_FRAD3_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD3_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD3_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD3_WORD5_CMPVALID_SHIFT          (30U)
/*! CMPVALID - Comparison Valid
 *  0b0..Not available
 *  0b1..Available
 */
#define XSPI_FRAD3_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD3_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD3_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name FRAD4_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD4_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD4_WORD0_STARTADR_SHIFT          (16U)
/*! STARTADR - Start Address */
#define XSPI_FRAD4_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD0_STARTADR_SHIFT)) & XSPI_FRAD4_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD4_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD4_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD4_WORD1_ENDADR_SHIFT            (16U)
/*! ENDADR - End Address */
#define XSPI_FRAD4_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD1_ENDADR_SHIFT)) & XSPI_FRAD4_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD4_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD4_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD4_WORD2_MD0ACP_SHIFT            (0U)
/*! MD0ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD4_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD4_WORD2_MD0ACP_MASK)

#define XSPI_FRAD4_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD4_WORD2_MD1ACP_SHIFT            (3U)
/*! MD1ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD4_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD4_WORD2_MD1ACP_MASK)

#define XSPI_FRAD4_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD4_WORD2_EALO_SHIFT              (24U)
/*! EALO - Exclusive Access Lock Owner */
#define XSPI_FRAD4_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD2_EALO_SHIFT)) & XSPI_FRAD4_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD4_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD4_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD4_WORD3_EAL_SHIFT               (24U)
/*! EAL - Exclusive Access Lock
 *  0b00..No lock
 *  0b01..No action
 *  0b10..Enables lock
 *  0b11..Enables exclusive access lock
 */
#define XSPI_FRAD4_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD3_EAL_SHIFT)) & XSPI_FRAD4_WORD3_EAL_MASK)

#define XSPI_FRAD4_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD4_WORD3_LOCK_SHIFT              (29U)
/*! LOCK - Descriptor Lock
 *  0b00..Unlocks
 *  0b01..Locks until hard reset
 *  0b10..Locks except for manager
 *  0b11..Locks
 */
#define XSPI_FRAD4_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD3_LOCK_SHIFT)) & XSPI_FRAD4_WORD3_LOCK_MASK)

#define XSPI_FRAD4_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD4_WORD3_VLD_SHIFT               (31U)
/*! VLD - Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define XSPI_FRAD4_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD3_VLD_SHIFT)) & XSPI_FRAD4_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD4_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD4_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD4_WORD4_CMP_ADDR_SHIFT          (0U)
/*! CMP_ADDR - Capture Address */
#define XSPI_FRAD4_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD4_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD4_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD4_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD4_WORD5_CMP_MDID_SHIFT          (0U)
/*! CMP_MDID - Captured Manager Value */
#define XSPI_FRAD4_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD4_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD4_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD4_WORD5_CMP_SA_SHIFT            (6U)
/*! CMP_SA - Captured Secure Attribute
 *  0b0..Non-secure
 *  0b1..Secure
 */
#define XSPI_FRAD4_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD4_WORD5_CMP_SA_MASK)

#define XSPI_FRAD4_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD4_WORD5_CMP_PA_SHIFT            (7U)
/*! CMP_PA - Captured Privilege Attribute
 *  0b0..Non-privileged
 *  0b1..Privileged
 */
#define XSPI_FRAD4_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD4_WORD5_CMP_PA_MASK)

#define XSPI_FRAD4_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD4_WORD5_CMP_ERR_SHIFT           (29U)
/*! CMP_ERR - Comparison Error
 *  0b0..No error
 *  0b1..Error
 */
#define XSPI_FRAD4_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD4_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD4_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD4_WORD5_CMPVALID_SHIFT          (30U)
/*! CMPVALID - Comparison Valid
 *  0b0..Not available
 *  0b1..Available
 */
#define XSPI_FRAD4_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD4_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD4_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name FRAD5_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD5_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD5_WORD0_STARTADR_SHIFT          (16U)
/*! STARTADR - Start Address */
#define XSPI_FRAD5_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD0_STARTADR_SHIFT)) & XSPI_FRAD5_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD5_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD5_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD5_WORD1_ENDADR_SHIFT            (16U)
/*! ENDADR - End Address */
#define XSPI_FRAD5_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD1_ENDADR_SHIFT)) & XSPI_FRAD5_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD5_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD5_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD5_WORD2_MD0ACP_SHIFT            (0U)
/*! MD0ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD5_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD5_WORD2_MD0ACP_MASK)

#define XSPI_FRAD5_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD5_WORD2_MD1ACP_SHIFT            (3U)
/*! MD1ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD5_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD5_WORD2_MD1ACP_MASK)

#define XSPI_FRAD5_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD5_WORD2_EALO_SHIFT              (24U)
/*! EALO - Exclusive Access Lock Owner */
#define XSPI_FRAD5_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD2_EALO_SHIFT)) & XSPI_FRAD5_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD5_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD5_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD5_WORD3_EAL_SHIFT               (24U)
/*! EAL - Exclusive Access Lock
 *  0b00..No lock
 *  0b01..No action
 *  0b10..Enables lock
 *  0b11..Enables exclusive access lock
 */
#define XSPI_FRAD5_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD3_EAL_SHIFT)) & XSPI_FRAD5_WORD3_EAL_MASK)

#define XSPI_FRAD5_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD5_WORD3_LOCK_SHIFT              (29U)
/*! LOCK - Descriptor Lock
 *  0b00..Unlocks
 *  0b01..Locks until hard reset
 *  0b10..Locks except for manager
 *  0b11..Locks
 */
#define XSPI_FRAD5_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD3_LOCK_SHIFT)) & XSPI_FRAD5_WORD3_LOCK_MASK)

#define XSPI_FRAD5_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD5_WORD3_VLD_SHIFT               (31U)
/*! VLD - Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define XSPI_FRAD5_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD3_VLD_SHIFT)) & XSPI_FRAD5_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD5_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD5_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD5_WORD4_CMP_ADDR_SHIFT          (0U)
/*! CMP_ADDR - Capture Address */
#define XSPI_FRAD5_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD5_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD5_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD5_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD5_WORD5_CMP_MDID_SHIFT          (0U)
/*! CMP_MDID - Captured Manager Value */
#define XSPI_FRAD5_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD5_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD5_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD5_WORD5_CMP_SA_SHIFT            (6U)
/*! CMP_SA - Captured Secure Attribute
 *  0b0..Non-secure
 *  0b1..Secure
 */
#define XSPI_FRAD5_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD5_WORD5_CMP_SA_MASK)

#define XSPI_FRAD5_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD5_WORD5_CMP_PA_SHIFT            (7U)
/*! CMP_PA - Captured Privilege Attribute
 *  0b0..Non-privileged
 *  0b1..Privileged
 */
#define XSPI_FRAD5_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD5_WORD5_CMP_PA_MASK)

#define XSPI_FRAD5_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD5_WORD5_CMP_ERR_SHIFT           (29U)
/*! CMP_ERR - Comparison Error
 *  0b0..No error
 *  0b1..Error
 */
#define XSPI_FRAD5_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD5_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD5_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD5_WORD5_CMPVALID_SHIFT          (30U)
/*! CMPVALID - Comparison Valid
 *  0b0..Not available
 *  0b1..Available
 */
#define XSPI_FRAD5_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD5_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD5_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name FRAD6_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD6_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD6_WORD0_STARTADR_SHIFT          (16U)
/*! STARTADR - Start Address */
#define XSPI_FRAD6_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD0_STARTADR_SHIFT)) & XSPI_FRAD6_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD6_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD6_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD6_WORD1_ENDADR_SHIFT            (16U)
/*! ENDADR - End Address */
#define XSPI_FRAD6_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD1_ENDADR_SHIFT)) & XSPI_FRAD6_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD6_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD6_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD6_WORD2_MD0ACP_SHIFT            (0U)
/*! MD0ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD6_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD6_WORD2_MD0ACP_MASK)

#define XSPI_FRAD6_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD6_WORD2_MD1ACP_SHIFT            (3U)
/*! MD1ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD6_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD6_WORD2_MD1ACP_MASK)

#define XSPI_FRAD6_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD6_WORD2_EALO_SHIFT              (24U)
/*! EALO - Exclusive Access Lock Owner */
#define XSPI_FRAD6_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD2_EALO_SHIFT)) & XSPI_FRAD6_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD6_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD6_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD6_WORD3_EAL_SHIFT               (24U)
/*! EAL - Exclusive Access Lock
 *  0b00..No lock
 *  0b01..No action
 *  0b10..Enables lock
 *  0b11..Enables exclusive access lock
 */
#define XSPI_FRAD6_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD3_EAL_SHIFT)) & XSPI_FRAD6_WORD3_EAL_MASK)

#define XSPI_FRAD6_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD6_WORD3_LOCK_SHIFT              (29U)
/*! LOCK - Descriptor Lock
 *  0b00..Unlocks
 *  0b01..Locks until hard reset
 *  0b10..Locks except for manager
 *  0b11..Locks
 */
#define XSPI_FRAD6_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD3_LOCK_SHIFT)) & XSPI_FRAD6_WORD3_LOCK_MASK)

#define XSPI_FRAD6_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD6_WORD3_VLD_SHIFT               (31U)
/*! VLD - Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define XSPI_FRAD6_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD3_VLD_SHIFT)) & XSPI_FRAD6_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD6_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD6_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD6_WORD4_CMP_ADDR_SHIFT          (0U)
/*! CMP_ADDR - Capture Address */
#define XSPI_FRAD6_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD6_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD6_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD6_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD6_WORD5_CMP_MDID_SHIFT          (0U)
/*! CMP_MDID - Captured Manager Value */
#define XSPI_FRAD6_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD6_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD6_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD6_WORD5_CMP_SA_SHIFT            (6U)
/*! CMP_SA - Captured Secure Attribute
 *  0b0..Non-secure
 *  0b1..Secure
 */
#define XSPI_FRAD6_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD6_WORD5_CMP_SA_MASK)

#define XSPI_FRAD6_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD6_WORD5_CMP_PA_SHIFT            (7U)
/*! CMP_PA - Captured Privilege Attribute
 *  0b0..Non-privileged
 *  0b1..Privileged
 */
#define XSPI_FRAD6_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD6_WORD5_CMP_PA_MASK)

#define XSPI_FRAD6_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD6_WORD5_CMP_ERR_SHIFT           (29U)
/*! CMP_ERR - Comparison Error
 *  0b0..No error
 *  0b1..Error
 */
#define XSPI_FRAD6_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD6_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD6_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD6_WORD5_CMPVALID_SHIFT          (30U)
/*! CMPVALID - Comparison Valid
 *  0b0..Not available
 *  0b1..Available
 */
#define XSPI_FRAD6_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD6_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD6_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name FRAD7_WORD0 - Flash Region Word 0 - Start Address */
/*! @{ */

#define XSPI_FRAD7_WORD0_STARTADR_MASK           (0xFFFF0000U)
#define XSPI_FRAD7_WORD0_STARTADR_SHIFT          (16U)
/*! STARTADR - Start Address */
#define XSPI_FRAD7_WORD0_STARTADR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD0_STARTADR_SHIFT)) & XSPI_FRAD7_WORD0_STARTADR_MASK)
/*! @} */

/*! @name FRAD7_WORD1 - Flash Region Word 1 - End Address */
/*! @{ */

#define XSPI_FRAD7_WORD1_ENDADR_MASK             (0xFFFF0000U)
#define XSPI_FRAD7_WORD1_ENDADR_SHIFT            (16U)
/*! ENDADR - End Address */
#define XSPI_FRAD7_WORD1_ENDADR(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD1_ENDADR_SHIFT)) & XSPI_FRAD7_WORD1_ENDADR_MASK)
/*! @} */

/*! @name FRAD7_WORD2 - Flash Region Word 2 - Privileges */
/*! @{ */

#define XSPI_FRAD7_WORD2_MD0ACP_MASK             (0x7U)
#define XSPI_FRAD7_WORD2_MD0ACP_SHIFT            (0U)
/*! MD0ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD7_WORD2_MD0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD2_MD0ACP_SHIFT)) & XSPI_FRAD7_WORD2_MD0ACP_MASK)

#define XSPI_FRAD7_WORD2_MD1ACP_MASK             (0x38U)
#define XSPI_FRAD7_WORD2_MD1ACP_SHIFT            (3U)
/*! MD1ACP - Manager Domain Access Control Policy */
#define XSPI_FRAD7_WORD2_MD1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD2_MD1ACP_SHIFT)) & XSPI_FRAD7_WORD2_MD1ACP_MASK)

#define XSPI_FRAD7_WORD2_EALO_MASK               (0x3F000000U)
#define XSPI_FRAD7_WORD2_EALO_SHIFT              (24U)
/*! EALO - Exclusive Access Lock Owner */
#define XSPI_FRAD7_WORD2_EALO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD2_EALO_SHIFT)) & XSPI_FRAD7_WORD2_EALO_MASK)
/*! @} */

/*! @name FRAD7_WORD3 - Flash Region Word 3 - Lock Control */
/*! @{ */

#define XSPI_FRAD7_WORD3_EAL_MASK                (0x3000000U)
#define XSPI_FRAD7_WORD3_EAL_SHIFT               (24U)
/*! EAL - Exclusive Access Lock
 *  0b00..No lock
 *  0b01..No action
 *  0b10..Enables lock
 *  0b11..Enables exclusive access lock
 */
#define XSPI_FRAD7_WORD3_EAL(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD3_EAL_SHIFT)) & XSPI_FRAD7_WORD3_EAL_MASK)

#define XSPI_FRAD7_WORD3_LOCK_MASK               (0x60000000U)
#define XSPI_FRAD7_WORD3_LOCK_SHIFT              (29U)
/*! LOCK - Descriptor Lock
 *  0b00..Unlocks
 *  0b01..Locks until hard reset
 *  0b10..Locks except for manager
 *  0b11..Locks
 */
#define XSPI_FRAD7_WORD3_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD3_LOCK_SHIFT)) & XSPI_FRAD7_WORD3_LOCK_MASK)

#define XSPI_FRAD7_WORD3_VLD_MASK                (0x80000000U)
#define XSPI_FRAD7_WORD3_VLD_SHIFT               (31U)
/*! VLD - Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define XSPI_FRAD7_WORD3_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD3_VLD_SHIFT)) & XSPI_FRAD7_WORD3_VLD_MASK)
/*! @} */

/*! @name FRAD7_WORD4 - Flash Region Word 4 - Compare Address Status */
/*! @{ */

#define XSPI_FRAD7_WORD4_CMP_ADDR_MASK           (0xFFFFFFFFU)
#define XSPI_FRAD7_WORD4_CMP_ADDR_SHIFT          (0U)
/*! CMP_ADDR - Capture Address */
#define XSPI_FRAD7_WORD4_CMP_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD4_CMP_ADDR_SHIFT)) & XSPI_FRAD7_WORD4_CMP_ADDR_MASK)
/*! @} */

/*! @name FRAD7_WORD5 - Flash Region Word 5 - Compare Status Data */
/*! @{ */

#define XSPI_FRAD7_WORD5_CMP_MDID_MASK           (0x3FU)
#define XSPI_FRAD7_WORD5_CMP_MDID_SHIFT          (0U)
/*! CMP_MDID - Captured Manager Value */
#define XSPI_FRAD7_WORD5_CMP_MDID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD5_CMP_MDID_SHIFT)) & XSPI_FRAD7_WORD5_CMP_MDID_MASK)

#define XSPI_FRAD7_WORD5_CMP_SA_MASK             (0x40U)
#define XSPI_FRAD7_WORD5_CMP_SA_SHIFT            (6U)
/*! CMP_SA - Captured Secure Attribute
 *  0b0..Non-secure
 *  0b1..Secure
 */
#define XSPI_FRAD7_WORD5_CMP_SA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD5_CMP_SA_SHIFT)) & XSPI_FRAD7_WORD5_CMP_SA_MASK)

#define XSPI_FRAD7_WORD5_CMP_PA_MASK             (0x80U)
#define XSPI_FRAD7_WORD5_CMP_PA_SHIFT            (7U)
/*! CMP_PA - Captured Privilege Attribute
 *  0b0..Non-privileged
 *  0b1..Privileged
 */
#define XSPI_FRAD7_WORD5_CMP_PA(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD5_CMP_PA_SHIFT)) & XSPI_FRAD7_WORD5_CMP_PA_MASK)

#define XSPI_FRAD7_WORD5_CMP_ERR_MASK            (0x20000000U)
#define XSPI_FRAD7_WORD5_CMP_ERR_SHIFT           (29U)
/*! CMP_ERR - Comparison Error
 *  0b0..No error
 *  0b1..Error
 */
#define XSPI_FRAD7_WORD5_CMP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD5_CMP_ERR_SHIFT)) & XSPI_FRAD7_WORD5_CMP_ERR_MASK)

#define XSPI_FRAD7_WORD5_CMPVALID_MASK           (0x40000000U)
#define XSPI_FRAD7_WORD5_CMPVALID_SHIFT          (30U)
/*! CMPVALID - Comparison Valid
 *  0b0..Not available
 *  0b1..Available
 */
#define XSPI_FRAD7_WORD5_CMPVALID(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_FRAD7_WORD5_CMPVALID_SHIFT)) & XSPI_FRAD7_WORD5_CMPVALID_MASK)
/*! @} */

/*! @name SFP_ARB_TIMEOUT - SFP Arbitration Lock Timeout Counter */
/*! @{ */

#define XSPI_SFP_ARB_TIMEOUT_SFP_ARB_TOC_MASK    (0xFFFFFFFFU)
#define XSPI_SFP_ARB_TIMEOUT_SFP_ARB_TOC_SHIFT   (0U)
/*! SFP_ARB_TOC - SFP Arbitration Timeout Value */
#define XSPI_SFP_ARB_TIMEOUT_SFP_ARB_TOC(x)      (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_ARB_TIMEOUT_SFP_ARB_TOC_SHIFT)) & XSPI_SFP_ARB_TIMEOUT_SFP_ARB_TOC_MASK)
/*! @} */

/*! @name TG0MDAD - Target Group Manager Domain Access Descriptor */
/*! @{ */

#define XSPI_TG0MDAD_MIDMATCH_MASK               (0x3FU)
#define XSPI_TG0MDAD_MIDMATCH_SHIFT              (0U)
/*! MIDMATCH - Manager ID Reference */
#define XSPI_TG0MDAD_MIDMATCH(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_TG0MDAD_MIDMATCH_SHIFT)) & XSPI_TG0MDAD_MIDMATCH_MASK)

#define XSPI_TG0MDAD_MASK_MASK                   (0xFC0U)
#define XSPI_TG0MDAD_MASK_SHIFT                  (6U)
/*! MASK - Mask */
#define XSPI_TG0MDAD_MASK(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_TG0MDAD_MASK_SHIFT)) & XSPI_TG0MDAD_MASK_MASK)

#define XSPI_TG0MDAD_MASKTYPE_MASK               (0x1000U)
#define XSPI_TG0MDAD_MASKTYPE_SHIFT              (12U)
/*! MASKTYPE - Mask Type
 *  0b0..AND
 *  0b1..OR
 */
#define XSPI_TG0MDAD_MASKTYPE(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_TG0MDAD_MASKTYPE_SHIFT)) & XSPI_TG0MDAD_MASKTYPE_MASK)

#define XSPI_TG0MDAD_SA_MASK                     (0xC000U)
#define XSPI_TG0MDAD_SA_SHIFT                    (14U)
/*! SA - Secure Attribute
 *  0b00..
 *  0b01..Non-secure only
 *  0b10..Secure only
 *  0b11..Both secure and non-secure
 */
#define XSPI_TG0MDAD_SA(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_TG0MDAD_SA_SHIFT)) & XSPI_TG0MDAD_SA_MASK)

#define XSPI_TG0MDAD_LCK_MASK                    (0x20000000U)
#define XSPI_TG0MDAD_LCK_SHIFT                   (29U)
/*! LCK - Descriptor Lock
 *  0b0..No action
 *  0b1..Locks
 */
#define XSPI_TG0MDAD_LCK(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TG0MDAD_LCK_SHIFT)) & XSPI_TG0MDAD_LCK_MASK)

#define XSPI_TG0MDAD_VLD_MASK                    (0x80000000U)
#define XSPI_TG0MDAD_VLD_SHIFT                   (31U)
/*! VLD - Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define XSPI_TG0MDAD_VLD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TG0MDAD_VLD_SHIFT)) & XSPI_TG0MDAD_VLD_MASK)
/*! @} */

/*! @name TGSFAR - Target Group SFAR Address */
/*! @{ */

#define XSPI_TGSFAR_SFARADDR_MASK                (0xFFFFFFFFU)
#define XSPI_TGSFAR_SFARADDR_SHIFT               (0U)
/*! SFARADDR - SFAR Address */
#define XSPI_TGSFAR_SFARADDR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFAR_SFARADDR_SHIFT)) & XSPI_TGSFAR_SFARADDR_MASK)
/*! @} */

/*! @name TGSFARS - Target Group SFAR Status */
/*! @{ */

#define XSPI_TGSFARS_TG_MID_MASK                 (0x3FU)
#define XSPI_TGSFARS_TG_MID_SHIFT                (0U)
/*! TG_MID - Transaction Manager ID */
#define XSPI_TGSFARS_TG_MID(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_TG_MID_SHIFT)) & XSPI_TGSFARS_TG_MID_MASK)

#define XSPI_TGSFARS_SA_MASK                     (0x400U)
#define XSPI_TGSFARS_SA_SHIFT                    (10U)
/*! SA - Secure Attribute
 *  0b0..Non-secure
 *  0b1..Secure
 */
#define XSPI_TGSFARS_SA(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_SA_SHIFT)) & XSPI_TGSFARS_SA_MASK)

#define XSPI_TGSFARS_PA_MASK                     (0x1000U)
#define XSPI_TGSFARS_PA_SHIFT                    (12U)
/*! PA - Privileged Attribute
 *  0b0..Not privileged
 *  0b1..Privileged
 */
#define XSPI_TGSFARS_PA(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_PA_SHIFT)) & XSPI_TGSFARS_PA_MASK)

#define XSPI_TGSFARS_CLR_MASK                    (0x20000000U)
#define XSPI_TGSFARS_CLR_SHIFT                   (29U)
/*! CLR - Clear
 *  0b0..Conveys no useful information
 *  0b0..No action
 *  0b1..Clears
 */
#define XSPI_TGSFARS_CLR(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_CLR_SHIFT)) & XSPI_TGSFARS_CLR_MASK)

#define XSPI_TGSFARS_ERR_MASK                    (0x40000000U)
#define XSPI_TGSFARS_ERR_SHIFT                   (30U)
/*! ERR - Error
 *  0b0..With required attributes
 *  0b1..Without required attributes
 */
#define XSPI_TGSFARS_ERR(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_ERR_SHIFT)) & XSPI_TGSFARS_ERR_MASK)

#define XSPI_TGSFARS_VLD_MASK                    (0x80000000U)
#define XSPI_TGSFARS_VLD_SHIFT                   (31U)
/*! VLD - Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define XSPI_TGSFARS_VLD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_VLD_SHIFT)) & XSPI_TGSFARS_VLD_MASK)
/*! @} */

/*! @name TGIPCRS - Target Group IP Configuration Status */
/*! @{ */

#define XSPI_TGIPCRS_IDATSZ_MASK                 (0xFFFFU)
#define XSPI_TGIPCRS_IDATSZ_SHIFT                (0U)
/*! IDATSZ - IP Data Transfer Size */
#define XSPI_TGIPCRS_IDATSZ(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_IDATSZ_SHIFT)) & XSPI_TGIPCRS_IDATSZ_MASK)

#define XSPI_TGIPCRS_SEQID_MASK                  (0xF0000U)
#define XSPI_TGIPCRS_SEQID_SHIFT                 (16U)
/*! SEQID - SEQID Value */
#define XSPI_TGIPCRS_SEQID(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SEQID_SHIFT)) & XSPI_TGIPCRS_SEQID_MASK)

#define XSPI_TGIPCRS_ARB_LOCK_MASK               (0x200000U)
#define XSPI_TGIPCRS_ARB_LOCK_SHIFT              (21U)
/*! ARB_LOCK - Arbitration Lock
 *  0b0..Not requested
 *  0b1..Requested
 */
#define XSPI_TGIPCRS_ARB_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_ARB_LOCK_SHIFT)) & XSPI_TGIPCRS_ARB_LOCK_MASK)

#define XSPI_TGIPCRS_ARB_UNLOCK_MASK             (0x400000U)
#define XSPI_TGIPCRS_ARB_UNLOCK_SHIFT            (22U)
/*! ARB_UNLOCK - Arbitration Unlock
 *  0b0..Not requested
 *  0b1..Requested
 */
#define XSPI_TGIPCRS_ARB_UNLOCK(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_ARB_UNLOCK_SHIFT)) & XSPI_TGIPCRS_ARB_UNLOCK_MASK)

#define XSPI_TGIPCRS_CLR_MASK                    (0x10000000U)
#define XSPI_TGIPCRS_CLR_SHIFT                   (28U)
/*! CLR - Clear
 *  0b0..Conveys no useful information
 *  0b0..No action
 *  0b1..Clears
 */
#define XSPI_TGIPCRS_CLR(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_CLR_SHIFT)) & XSPI_TGIPCRS_CLR_MASK)

#define XSPI_TGIPCRS_ERR_MASK                    (0x60000000U)
#define XSPI_TGIPCRS_ERR_SHIFT                   (29U)
/*! ERR - Error
 *  0b00..Required attributes
 *  0b01..IPCR DATZ without required attributes
 *  0b10..IPCR SEQID without required attributes
 *  0b11..IPCR IDATSZ and SEQID without required attributes
 */
#define XSPI_TGIPCRS_ERR(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_ERR_SHIFT)) & XSPI_TGIPCRS_ERR_MASK)

#define XSPI_TGIPCRS_VLD_MASK                    (0x80000000U)
#define XSPI_TGIPCRS_VLD_SHIFT                   (31U)
/*! VLD - Valid
 *  0b0..Not valid
 *  0b1..Valid and queue is locked
 */
#define XSPI_TGIPCRS_VLD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_VLD_SHIFT)) & XSPI_TGIPCRS_VLD_MASK)
/*! @} */

/*! @name TG1MDAD - Target Group Manager Domain Access Descriptor */
/*! @{ */

#define XSPI_TG1MDAD_MIDMATCH_MASK               (0x3FU)
#define XSPI_TG1MDAD_MIDMATCH_SHIFT              (0U)
/*! MIDMATCH - Manager ID Reference */
#define XSPI_TG1MDAD_MIDMATCH(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_TG1MDAD_MIDMATCH_SHIFT)) & XSPI_TG1MDAD_MIDMATCH_MASK)

#define XSPI_TG1MDAD_MASK_MASK                   (0xFC0U)
#define XSPI_TG1MDAD_MASK_SHIFT                  (6U)
/*! MASK - Mask */
#define XSPI_TG1MDAD_MASK(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_TG1MDAD_MASK_SHIFT)) & XSPI_TG1MDAD_MASK_MASK)

#define XSPI_TG1MDAD_MASKTYPE_MASK               (0x1000U)
#define XSPI_TG1MDAD_MASKTYPE_SHIFT              (12U)
/*! MASKTYPE - Mask Type
 *  0b0..AND
 *  0b1..OR
 */
#define XSPI_TG1MDAD_MASKTYPE(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_TG1MDAD_MASKTYPE_SHIFT)) & XSPI_TG1MDAD_MASKTYPE_MASK)

#define XSPI_TG1MDAD_SA_MASK                     (0xC000U)
#define XSPI_TG1MDAD_SA_SHIFT                    (14U)
/*! SA - Secure Attribute
 *  0b00..
 *  0b01..Non-secure only
 *  0b10..Secure only
 *  0b11..Both secure and non-secure
 */
#define XSPI_TG1MDAD_SA(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_TG1MDAD_SA_SHIFT)) & XSPI_TG1MDAD_SA_MASK)

#define XSPI_TG1MDAD_LCK_MASK                    (0x20000000U)
#define XSPI_TG1MDAD_LCK_SHIFT                   (29U)
/*! LCK - Descriptor Lock
 *  0b0..No action
 *  0b1..Locks
 */
#define XSPI_TG1MDAD_LCK(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TG1MDAD_LCK_SHIFT)) & XSPI_TG1MDAD_LCK_MASK)

#define XSPI_TG1MDAD_VLD_MASK                    (0x80000000U)
#define XSPI_TG1MDAD_VLD_SHIFT                   (31U)
/*! VLD - Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define XSPI_TG1MDAD_VLD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_TG1MDAD_VLD_SHIFT)) & XSPI_TG1MDAD_VLD_MASK)
/*! @} */

/*! @name MGC - Manager Global Configuration */
/*! @{ */

#define XSPI_MGC_GCLCKMID_MASK                   (0x3FU)
#define XSPI_MGC_GCLCKMID_SHIFT                  (0U)
/*! GCLCKMID - Global Configuration Lock Owner */
#define XSPI_MGC_GCLCKMID(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_MGC_GCLCKMID_SHIFT)) & XSPI_MGC_GCLCKMID_MASK)

#define XSPI_MGC_GCLCK_MASK                      (0xC00U)
#define XSPI_MGC_GCLCK_SHIFT                     (10U)
/*! GCLCK - Global Configuration Lock
 *  0b00..Unlocks
 *  0b01..Locks
 *  0b10..Locks
 *  0b11..Locks
 */
#define XSPI_MGC_GCLCK(x)                        (((uint32_t)(((uint32_t)(x)) << XSPI_MGC_GCLCK_SHIFT)) & XSPI_MGC_GCLCK_MASK)

#define XSPI_MGC_TG1_FIX_PRIO_MASK               (0x10000U)
#define XSPI_MGC_TG1_FIX_PRIO_SHIFT              (16U)
/*! TG1_FIX_PRIO - Target Group Queue 1 Fixed Priority Enable
 *  *..TG1 always has fixed priority regardless of this value.
 */
#define XSPI_MGC_TG1_FIX_PRIO(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_MGC_TG1_FIX_PRIO_SHIFT)) & XSPI_MGC_TG1_FIX_PRIO_MASK)

#define XSPI_MGC_GVLDFRAD_MASK                   (0x8000000U)
#define XSPI_MGC_GVLDFRAD_SHIFT                  (27U)
/*! GVLDFRAD - Global Valid FRAD
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_MGC_GVLDFRAD(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_MGC_GVLDFRAD_SHIFT)) & XSPI_MGC_GVLDFRAD_MASK)

#define XSPI_MGC_GVLDMDAD_MASK                   (0x20000000U)
#define XSPI_MGC_GVLDMDAD_SHIFT                  (29U)
/*! GVLDMDAD - Global Valid MDAD
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_MGC_GVLDMDAD(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_MGC_GVLDMDAD_SHIFT)) & XSPI_MGC_GVLDMDAD_MASK)

#define XSPI_MGC_GVLD_MASK                       (0x80000000U)
#define XSPI_MGC_GVLD_SHIFT                      (31U)
/*! GVLD - Global Valid Access Control
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_MGC_GVLD(x)                         (((uint32_t)(((uint32_t)(x)) << XSPI_MGC_GVLD_SHIFT)) & XSPI_MGC_GVLD_MASK)
/*! @} */

/*! @name MRC - Manager Read Command */
/*! @{ */

#define XSPI_MRC_READ_CMD0_MASK                  (0x3FU)
#define XSPI_MRC_READ_CMD0_SHIFT                 (0U)
/*! READ_CMD0 - Read Command 0 */
#define XSPI_MRC_READ_CMD0(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_MRC_READ_CMD0_SHIFT)) & XSPI_MRC_READ_CMD0_MASK)

#define XSPI_MRC_READ_CMD1_MASK                  (0x3F00U)
#define XSPI_MRC_READ_CMD1_SHIFT                 (8U)
/*! READ_CMD1 - Read Command 1 */
#define XSPI_MRC_READ_CMD1(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_MRC_READ_CMD1_SHIFT)) & XSPI_MRC_READ_CMD1_MASK)

#define XSPI_MRC_READ_CMD2_MASK                  (0x3F0000U)
#define XSPI_MRC_READ_CMD2_SHIFT                 (16U)
/*! READ_CMD2 - Read Command 2 */
#define XSPI_MRC_READ_CMD2(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_MRC_READ_CMD2_SHIFT)) & XSPI_MRC_READ_CMD2_MASK)

#define XSPI_MRC_VLDCMD02_MASK                   (0x400000U)
#define XSPI_MRC_VLDCMD02_SHIFT                  (22U)
/*! VLDCMD02 - Valid Command 2
 *  0b0..Not valid
 *  0b1..Valid
 */
#define XSPI_MRC_VLDCMD02(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_MRC_VLDCMD02_SHIFT)) & XSPI_MRC_VLDCMD02_MASK)

#define XSPI_MRC_READ_CMD3_MASK                  (0x3F000000U)
#define XSPI_MRC_READ_CMD3_SHIFT                 (24U)
/*! READ_CMD3 - Read Command 3 */
#define XSPI_MRC_READ_CMD3(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_MRC_READ_CMD3_SHIFT)) & XSPI_MRC_READ_CMD3_MASK)

#define XSPI_MRC_VLDCMD03_MASK                   (0x40000000U)
#define XSPI_MRC_VLDCMD03_SHIFT                  (30U)
/*! VLDCMD03 - Valid Command 3
 *  0b0..Not valid
 *  0b1..Valid
 */
#define XSPI_MRC_VLDCMD03(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_MRC_VLDCMD03_SHIFT)) & XSPI_MRC_VLDCMD03_MASK)
/*! @} */

/*! @name MTO - Manager Timeout */
/*! @{ */

#define XSPI_MTO_SFP_ACC_TO_MASK                 (0xFFFFFFFFU)
#define XSPI_MTO_SFP_ACC_TO_SHIFT                (0U)
/*! SFP_ACC_TO - SFP Access Timeout */
#define XSPI_MTO_SFP_ACC_TO(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_MTO_SFP_ACC_TO_SHIFT)) & XSPI_MTO_SFP_ACC_TO_MASK)
/*! @} */

/*! @name FLSEQREQ - Flash Sequence Request */
/*! @{ */

#define XSPI_FLSEQREQ_REQ_MID_MASK               (0x3FU)
#define XSPI_FLSEQREQ_REQ_MID_SHIFT              (0U)
/*! REQ_MID - Flash Sequence Request Manager ID */
#define XSPI_FLSEQREQ_REQ_MID(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_REQ_MID_SHIFT)) & XSPI_FLSEQREQ_REQ_MID_MASK)

#define XSPI_FLSEQREQ_REQ_TG_MASK                (0x40U)
#define XSPI_FLSEQREQ_REQ_TG_SHIFT               (6U)
/*! REQ_TG - FlashSeq Request Target Group
 *  0b0..TG0
 *  0b1..TG1
 */
#define XSPI_FLSEQREQ_REQ_TG(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_REQ_TG_SHIFT)) & XSPI_FLSEQREQ_REQ_TG_MASK)

#define XSPI_FLSEQREQ_SA_MASK                    (0x100U)
#define XSPI_FLSEQREQ_SA_SHIFT                   (8U)
/*! SA - Secure Attribute
 *  0b0..Non-secure
 *  0b1..Secure
 */
#define XSPI_FLSEQREQ_SA(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_SA_SHIFT)) & XSPI_FLSEQREQ_SA_MASK)

#define XSPI_FLSEQREQ_PA_MASK                    (0x200U)
#define XSPI_FLSEQREQ_PA_SHIFT                   (9U)
/*! PA - Privilege Attribute
 *  0b0..Non-privilege
 *  0b1..Privilege
 */
#define XSPI_FLSEQREQ_PA(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_PA_SHIFT)) & XSPI_FLSEQREQ_PA_MASK)

#define XSPI_FLSEQREQ_ARB_LOCK_MASK              (0x400U)
#define XSPI_FLSEQREQ_ARB_LOCK_SHIFT             (10U)
/*! ARB_LOCK - Arbitration Lock
 *  0b0..Not locked
 *  0b1..Locked
 */
#define XSPI_FLSEQREQ_ARB_LOCK(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_ARB_LOCK_SHIFT)) & XSPI_FLSEQREQ_ARB_LOCK_MASK)

#define XSPI_FLSEQREQ_FRAD_MASK                  (0x7000U)
#define XSPI_FLSEQREQ_FRAD_SHIFT                 (12U)
/*! FRAD - Flash Region Descriptor Number */
#define XSPI_FLSEQREQ_FRAD(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_FRAD_SHIFT)) & XSPI_FLSEQREQ_FRAD_MASK)

#define XSPI_FLSEQREQ_SEQID_MASK                 (0xF0000U)
#define XSPI_FLSEQREQ_SEQID_SHIFT                (16U)
/*! SEQID - Sequence ID */
#define XSPI_FLSEQREQ_SEQID(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_SEQID_SHIFT)) & XSPI_FLSEQREQ_SEQID_MASK)

#define XSPI_FLSEQREQ_CMD_MASK                   (0x400000U)
#define XSPI_FLSEQREQ_CMD_SHIFT                  (22U)
/*! CMD - Instruction Type
 *  0b0..Read
 *  0b1..Non-read
 */
#define XSPI_FLSEQREQ_CMD(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_CMD_SHIFT)) & XSPI_FLSEQREQ_CMD_MASK)

#define XSPI_FLSEQREQ_TIMEOUT_MASK               (0x8000000U)
#define XSPI_FLSEQREQ_TIMEOUT_SHIFT              (27U)
/*! TIMEOUT - Timeout Error Status
 *  0b0..No error
 *  0b1..Error
 */
#define XSPI_FLSEQREQ_TIMEOUT(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_TIMEOUT_SHIFT)) & XSPI_FLSEQREQ_TIMEOUT_MASK)

#define XSPI_FLSEQREQ_VLD_MASK                   (0x80000000U)
#define XSPI_FLSEQREQ_VLD_SHIFT                  (31U)
/*! VLD - Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define XSPI_FLSEQREQ_VLD(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_FLSEQREQ_VLD_SHIFT)) & XSPI_FLSEQREQ_VLD_MASK)
/*! @} */

/*! @name FSMSTAT - FSM Status */
/*! @{ */

#define XSPI_FSMSTAT_STATE_MASK                  (0x3U)
#define XSPI_FSMSTAT_STATE_SHIFT                 (0U)
/*! STATE - FSM State
 *  0b00..Transaction granted
 *  0b01..TBDR lock open
 *  0b10..Write transfer triggered
 *  0b11..Read transfer triggered
 */
#define XSPI_FSMSTAT_STATE(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_FSMSTAT_STATE_SHIFT)) & XSPI_FSMSTAT_STATE_MASK)

#define XSPI_FSMSTAT_MID_MASK                    (0x3F00U)
#define XSPI_FSMSTAT_MID_SHIFT                   (8U)
/*! MID - Manager ID */
#define XSPI_FSMSTAT_MID(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FSMSTAT_MID_SHIFT)) & XSPI_FSMSTAT_MID_MASK)

#define XSPI_FSMSTAT_CMD_MASK                    (0x10000U)
#define XSPI_FSMSTAT_CMD_SHIFT                   (16U)
/*! CMD - Command
 *  0b0..Read instruction sequence
 *  0b1..Non-read instruction sequence
 */
#define XSPI_FSMSTAT_CMD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FSMSTAT_CMD_SHIFT)) & XSPI_FSMSTAT_CMD_MASK)

#define XSPI_FSMSTAT_ARB_LOCK_MASK               (0x20000U)
#define XSPI_FSMSTAT_ARB_LOCK_SHIFT              (17U)
/*! ARB_LOCK - Arbitration Lock
 *  0b0..Not locked
 *  0b1..Locked
 */
#define XSPI_FSMSTAT_ARB_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_FSMSTAT_ARB_LOCK_SHIFT)) & XSPI_FSMSTAT_ARB_LOCK_MASK)

#define XSPI_FSMSTAT_VLD_MASK                    (0x80000000U)
#define XSPI_FSMSTAT_VLD_SHIFT                   (31U)
/*! VLD - Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define XSPI_FSMSTAT_VLD(x)                      (((uint32_t)(((uint32_t)(x)) << XSPI_FSMSTAT_VLD_SHIFT)) & XSPI_FSMSTAT_VLD_MASK)
/*! @} */

/*! @name IPSERROR - IPS Error */
/*! @{ */

#define XSPI_IPSERROR_MID_MASK                   (0x3FU)
#define XSPI_IPSERROR_MID_SHIFT                  (0U)
/*! MID - IPS Manager ID */
#define XSPI_IPSERROR_MID(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_MID_SHIFT)) & XSPI_IPSERROR_MID_MASK)

#define XSPI_IPSERROR_TG0LCK_MASK                (0x100U)
#define XSPI_IPSERROR_TG0LCK_SHIFT               (8U)
/*! TG0LCK - TG0 Lock
 *  0b0..SEQID not written yet
 *  0b1..SEQID written and queue locked
 */
#define XSPI_IPSERROR_TG0LCK(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_TG0LCK_SHIFT)) & XSPI_IPSERROR_TG0LCK_MASK)

#define XSPI_IPSERROR_TG1LCK_MASK                (0x200U)
#define XSPI_IPSERROR_TG1LCK_SHIFT               (9U)
/*! TG1LCK - TG1 Lock
 *  0b0..SEQID not written yet
 *  0b1..SEQID written and queue locked
 */
#define XSPI_IPSERROR_TG1LCK(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_TG1LCK_SHIFT)) & XSPI_IPSERROR_TG1LCK_MASK)

#define XSPI_IPSERROR_TG0SEC_MASK                (0x400U)
#define XSPI_IPSERROR_TG0SEC_SHIFT               (10U)
/*! TG0SEC - TG Security Status
 *  0b0..Security attribute check passed
 *  0b1..Security attribute check failed
 */
#define XSPI_IPSERROR_TG0SEC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_TG0SEC_SHIFT)) & XSPI_IPSERROR_TG0SEC_MASK)

#define XSPI_IPSERROR_TG1SEC_MASK                (0x800U)
#define XSPI_IPSERROR_TG1SEC_SHIFT               (11U)
/*! TG1SEC - TG Security Status
 *  0b0..Security attribute check passed
 *  0b1..Security attribute check failed
 */
#define XSPI_IPSERROR_TG1SEC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_TG1SEC_SHIFT)) & XSPI_IPSERROR_TG1SEC_MASK)

#define XSPI_IPSERROR_TG0MID_MASK                (0x1000U)
#define XSPI_IPSERROR_TG0MID_SHIFT               (12U)
/*! TG0MID - TGn Manager-ID Status
 *  0b0..Passed
 *  0b1..Failed
 */
#define XSPI_IPSERROR_TG0MID(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_TG0MID_SHIFT)) & XSPI_IPSERROR_TG0MID_MASK)

#define XSPI_IPSERROR_TG1MID_MASK                (0x2000U)
#define XSPI_IPSERROR_TG1MID_SHIFT               (13U)
/*! TG1MID - TGn Manager-ID Status
 *  0b0..Passed
 *  0b1..Failed
 */
#define XSPI_IPSERROR_TG1MID(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_TG1MID_SHIFT)) & XSPI_IPSERROR_TG1MID_MASK)

#define XSPI_IPSERROR_MDADPROG_MASK              (0x4000U)
#define XSPI_IPSERROR_MDADPROG_SHIFT             (14U)
/*! MDADPROG - TG/MDA Descriptor Program Status
 *  0b0..One or both target group descriptors programmed
 *  0b1..None of the target group descriptors are programmed or valid
 */
#define XSPI_IPSERROR_MDADPROG(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_MDADPROG_SHIFT)) & XSPI_IPSERROR_MDADPROG_MASK)

#define XSPI_IPSERROR_FRADPROG_MASK              (0x8000U)
#define XSPI_IPSERROR_FRADPROG_SHIFT             (15U)
/*! FRADPROG - FRAD Program Status
 *  0b0..Some or all FRADs programmed
 *  0b1..No FRADs programmed
 */
#define XSPI_IPSERROR_FRADPROG(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_FRADPROG_SHIFT)) & XSPI_IPSERROR_FRADPROG_MASK)

#define XSPI_IPSERROR_CLR_MASK                   (0x20000000U)
#define XSPI_IPSERROR_CLR_SHIFT                  (29U)
/*! CLR - Clear
 *  0b0..Conveys no useful information
 *  0b0..No action
 *  0b1..Clears
 */
#define XSPI_IPSERROR_CLR(x)                     (((uint32_t)(((uint32_t)(x)) << XSPI_IPSERROR_CLR_SHIFT)) & XSPI_IPSERROR_CLR_MASK)
/*! @} */

/*! @name ERRSTAT - Error Status */
/*! @{ */

#define XSPI_ERRSTAT_FRADMTCH_MASK               (0x1U)
#define XSPI_ERRSTAT_FRADMTCH_SHIFT              (0U)
/*! FRADMTCH - No FRAD Match Error
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears
 *  0b1..Error
 */
#define XSPI_ERRSTAT_FRADMTCH(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRADMTCH_SHIFT)) & XSPI_ERRSTAT_FRADMTCH_MASK)

#define XSPI_ERRSTAT_FRAD0ACC_MASK               (0x2U)
#define XSPI_ERRSTAT_FRAD0ACC_SHIFT              (1U)
/*! FRAD0ACC - FRAD Access Error
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears
 *  0b1..Error
 */
#define XSPI_ERRSTAT_FRAD0ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD0ACC_SHIFT)) & XSPI_ERRSTAT_FRAD0ACC_MASK)

#define XSPI_ERRSTAT_FRAD1ACC_MASK               (0x4U)
#define XSPI_ERRSTAT_FRAD1ACC_SHIFT              (2U)
/*! FRAD1ACC - FRAD Access Error
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears
 *  0b1..Error
 */
#define XSPI_ERRSTAT_FRAD1ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD1ACC_SHIFT)) & XSPI_ERRSTAT_FRAD1ACC_MASK)

#define XSPI_ERRSTAT_FRAD2ACC_MASK               (0x8U)
#define XSPI_ERRSTAT_FRAD2ACC_SHIFT              (3U)
/*! FRAD2ACC - FRAD Access Error
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears
 *  0b1..Error
 */
#define XSPI_ERRSTAT_FRAD2ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD2ACC_SHIFT)) & XSPI_ERRSTAT_FRAD2ACC_MASK)

#define XSPI_ERRSTAT_FRAD3ACC_MASK               (0x10U)
#define XSPI_ERRSTAT_FRAD3ACC_SHIFT              (4U)
/*! FRAD3ACC - FRAD Access Error
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears
 *  0b1..Error
 */
#define XSPI_ERRSTAT_FRAD3ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD3ACC_SHIFT)) & XSPI_ERRSTAT_FRAD3ACC_MASK)

#define XSPI_ERRSTAT_FRAD4ACC_MASK               (0x20U)
#define XSPI_ERRSTAT_FRAD4ACC_SHIFT              (5U)
/*! FRAD4ACC - FRAD Access Error
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears
 *  0b1..Error
 */
#define XSPI_ERRSTAT_FRAD4ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD4ACC_SHIFT)) & XSPI_ERRSTAT_FRAD4ACC_MASK)

#define XSPI_ERRSTAT_FRAD5ACC_MASK               (0x40U)
#define XSPI_ERRSTAT_FRAD5ACC_SHIFT              (6U)
/*! FRAD5ACC - FRAD Access Error
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears
 *  0b1..Error
 */
#define XSPI_ERRSTAT_FRAD5ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD5ACC_SHIFT)) & XSPI_ERRSTAT_FRAD5ACC_MASK)

#define XSPI_ERRSTAT_FRAD6ACC_MASK               (0x80U)
#define XSPI_ERRSTAT_FRAD6ACC_SHIFT              (7U)
/*! FRAD6ACC - FRAD Access Error
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears
 *  0b1..Error
 */
#define XSPI_ERRSTAT_FRAD6ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD6ACC_SHIFT)) & XSPI_ERRSTAT_FRAD6ACC_MASK)

#define XSPI_ERRSTAT_FRAD7ACC_MASK               (0x100U)
#define XSPI_ERRSTAT_FRAD7ACC_SHIFT              (8U)
/*! FRAD7ACC - FRAD Access Error
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears
 *  0b1..Error
 */
#define XSPI_ERRSTAT_FRAD7ACC(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_FRAD7ACC_SHIFT)) & XSPI_ERRSTAT_FRAD7ACC_MASK)

#define XSPI_ERRSTAT_IPS_ERR_MASK                (0x200U)
#define XSPI_ERRSTAT_IPS_ERR_SHIFT               (9U)
/*! IPS_ERR - IPS Error
 *  0b0..No error
 *  0b1..Error
 */
#define XSPI_ERRSTAT_IPS_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_IPS_ERR_SHIFT)) & XSPI_ERRSTAT_IPS_ERR_MASK)

#define XSPI_ERRSTAT_TG0SFAR_MASK                (0x400U)
#define XSPI_ERRSTAT_TG0SFAR_SHIFT               (10U)
/*! TG0SFAR - TG SFAR Error
 *  0b0..No error
 *  0b1..Error
 */
#define XSPI_ERRSTAT_TG0SFAR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_TG0SFAR_SHIFT)) & XSPI_ERRSTAT_TG0SFAR_MASK)

#define XSPI_ERRSTAT_TG1SFAR_MASK                (0x800U)
#define XSPI_ERRSTAT_TG1SFAR_SHIFT               (11U)
/*! TG1SFAR - TG SFAR Error
 *  0b0..No error
 *  0b1..Error
 */
#define XSPI_ERRSTAT_TG1SFAR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_TG1SFAR_SHIFT)) & XSPI_ERRSTAT_TG1SFAR_MASK)

#define XSPI_ERRSTAT_TG0IPCR_MASK                (0x1000U)
#define XSPI_ERRSTAT_TG0IPCR_SHIFT               (12U)
/*! TG0IPCR - TG IPCR Error
 *  0b0..No error
 *  0b1..Error
 */
#define XSPI_ERRSTAT_TG0IPCR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_TG0IPCR_SHIFT)) & XSPI_ERRSTAT_TG0IPCR_MASK)

#define XSPI_ERRSTAT_TG1IPCR_MASK                (0x2000U)
#define XSPI_ERRSTAT_TG1IPCR_SHIFT               (13U)
/*! TG1IPCR - TG IPCR Error
 *  0b0..No error
 *  0b1..Error
 */
#define XSPI_ERRSTAT_TG1IPCR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_TG1IPCR_SHIFT)) & XSPI_ERRSTAT_TG1IPCR_MASK)

#define XSPI_ERRSTAT_TO_ERR_MASK                 (0x4000U)
#define XSPI_ERRSTAT_TO_ERR_SHIFT                (14U)
/*! TO_ERR - Timeout Error
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears
 *  0b1..Error
 */
#define XSPI_ERRSTAT_TO_ERR(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_TO_ERR_SHIFT)) & XSPI_ERRSTAT_TO_ERR_MASK)

#define XSPI_ERRSTAT_ARB_WIN_MASK                (0x10000000U)
#define XSPI_ERRSTAT_ARB_WIN_SHIFT               (28U)
/*! ARB_WIN - Arbitration Win Event Status
 *  0b0..No action
 *  0b0..Request not granted or the interrupt is already cleared
 *  0b1..Clears interrupt
 *  0b1..Request granted and interrupt generated
 */
#define XSPI_ERRSTAT_ARB_WIN(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_ARB_WIN_SHIFT)) & XSPI_ERRSTAT_ARB_WIN_MASK)

#define XSPI_ERRSTAT_ARB_LOCK_TO_MASK            (0x20000000U)
#define XSPI_ERRSTAT_ARB_LOCK_TO_SHIFT           (29U)
/*! ARB_LOCK_TO - Arbitration Lock Timeout Error
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears flag
 *  0b1..Error
 */
#define XSPI_ERRSTAT_ARB_LOCK_TO(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_ARB_LOCK_TO_SHIFT)) & XSPI_ERRSTAT_ARB_LOCK_TO_MASK)

#define XSPI_ERRSTAT_LOCK_ERR_MASK               (0x40000000U)
#define XSPI_ERRSTAT_LOCK_ERR_SHIFT              (30U)
/*! LOCK_ERR - Lock Register Error
 *  0b0..No action
 *  0b0..No error
 *  0b1..Clears
 *  0b1..Error
 */
#define XSPI_ERRSTAT_LOCK_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_ERRSTAT_LOCK_ERR_SHIFT)) & XSPI_ERRSTAT_LOCK_ERR_MASK)
/*! @} */

/*! @name INT_EN - Interrupt Enable */
/*! @{ */

#define XSPI_INT_EN_FRADMTCH_MASK                (0x1U)
#define XSPI_INT_EN_FRADMTCH_SHIFT               (0U)
/*! FRADMTCH - No FRAD Match Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_FRADMTCH(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRADMTCH_SHIFT)) & XSPI_INT_EN_FRADMTCH_MASK)

#define XSPI_INT_EN_FRAD0ACC_MASK                (0x2U)
#define XSPI_INT_EN_FRAD0ACC_SHIFT               (1U)
/*! FRAD0ACC - FRAD Access Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_FRAD0ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD0ACC_SHIFT)) & XSPI_INT_EN_FRAD0ACC_MASK)

#define XSPI_INT_EN_FRAD1ACC_MASK                (0x4U)
#define XSPI_INT_EN_FRAD1ACC_SHIFT               (2U)
/*! FRAD1ACC - FRAD Access Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_FRAD1ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD1ACC_SHIFT)) & XSPI_INT_EN_FRAD1ACC_MASK)

#define XSPI_INT_EN_FRAD2ACC_MASK                (0x8U)
#define XSPI_INT_EN_FRAD2ACC_SHIFT               (3U)
/*! FRAD2ACC - FRAD Access Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_FRAD2ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD2ACC_SHIFT)) & XSPI_INT_EN_FRAD2ACC_MASK)

#define XSPI_INT_EN_FRAD3ACC_MASK                (0x10U)
#define XSPI_INT_EN_FRAD3ACC_SHIFT               (4U)
/*! FRAD3ACC - FRAD Access Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_FRAD3ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD3ACC_SHIFT)) & XSPI_INT_EN_FRAD3ACC_MASK)

#define XSPI_INT_EN_FRAD4ACC_MASK                (0x20U)
#define XSPI_INT_EN_FRAD4ACC_SHIFT               (5U)
/*! FRAD4ACC - FRAD Access Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_FRAD4ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD4ACC_SHIFT)) & XSPI_INT_EN_FRAD4ACC_MASK)

#define XSPI_INT_EN_FRAD5ACC_MASK                (0x40U)
#define XSPI_INT_EN_FRAD5ACC_SHIFT               (6U)
/*! FRAD5ACC - FRAD Access Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_FRAD5ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD5ACC_SHIFT)) & XSPI_INT_EN_FRAD5ACC_MASK)

#define XSPI_INT_EN_FRAD6ACC_MASK                (0x80U)
#define XSPI_INT_EN_FRAD6ACC_SHIFT               (7U)
/*! FRAD6ACC - FRAD Access Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_FRAD6ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD6ACC_SHIFT)) & XSPI_INT_EN_FRAD6ACC_MASK)

#define XSPI_INT_EN_FRAD7ACC_MASK                (0x100U)
#define XSPI_INT_EN_FRAD7ACC_SHIFT               (8U)
/*! FRAD7ACC - FRAD Access Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_FRAD7ACC(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_FRAD7ACC_SHIFT)) & XSPI_INT_EN_FRAD7ACC_MASK)

#define XSPI_INT_EN_IPS_ERR_MASK                 (0x200U)
#define XSPI_INT_EN_IPS_ERR_SHIFT                (9U)
/*! IPS_ERR - IPS Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_IPS_ERR(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_IPS_ERR_SHIFT)) & XSPI_INT_EN_IPS_ERR_MASK)

#define XSPI_INT_EN_TG0SFAR_MASK                 (0x400U)
#define XSPI_INT_EN_TG0SFAR_SHIFT                (10U)
/*! TG0SFAR - TG SFAR Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_TG0SFAR(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_TG0SFAR_SHIFT)) & XSPI_INT_EN_TG0SFAR_MASK)

#define XSPI_INT_EN_TG1SFAR_MASK                 (0x800U)
#define XSPI_INT_EN_TG1SFAR_SHIFT                (11U)
/*! TG1SFAR - TG SFAR Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_TG1SFAR(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_TG1SFAR_SHIFT)) & XSPI_INT_EN_TG1SFAR_MASK)

#define XSPI_INT_EN_TG0IPCR_MASK                 (0x1000U)
#define XSPI_INT_EN_TG0IPCR_SHIFT                (12U)
/*! TG0IPCR - TGn IPCR Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_TG0IPCR(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_TG0IPCR_SHIFT)) & XSPI_INT_EN_TG0IPCR_MASK)

#define XSPI_INT_EN_TG1IPCR_MASK                 (0x2000U)
#define XSPI_INT_EN_TG1IPCR_SHIFT                (13U)
/*! TG1IPCR - TGn IPCR Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_TG1IPCR(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_TG1IPCR_SHIFT)) & XSPI_INT_EN_TG1IPCR_MASK)

#define XSPI_INT_EN_TO_ERR_MASK                  (0x4000U)
#define XSPI_INT_EN_TO_ERR_SHIFT                 (14U)
/*! TO_ERR - Timeout Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_TO_ERR(x)                    (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_TO_ERR_SHIFT)) & XSPI_INT_EN_TO_ERR_MASK)

#define XSPI_INT_EN_ARB_WIN_IE_MASK              (0x10000000U)
#define XSPI_INT_EN_ARB_WIN_IE_SHIFT             (28U)
/*! ARB_WIN_IE - Arbitration Win Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_ARB_WIN_IE(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_ARB_WIN_IE_SHIFT)) & XSPI_INT_EN_ARB_WIN_IE_MASK)

#define XSPI_INT_EN_ARB_TO_IE_MASK               (0x20000000U)
#define XSPI_INT_EN_ARB_TO_IE_SHIFT              (29U)
/*! ARB_TO_IE - Arbitration Lock Timeout Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_ARB_TO_IE(x)                 (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_ARB_TO_IE_SHIFT)) & XSPI_INT_EN_ARB_TO_IE_MASK)

#define XSPI_INT_EN_LCK_ERR_IE_MASK              (0x40000000U)
#define XSPI_INT_EN_LCK_ERR_IE_SHIFT             (30U)
/*! LCK_ERR_IE - Lock Register Write Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define XSPI_INT_EN_LCK_ERR_IE(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_LCK_ERR_IE_SHIFT)) & XSPI_INT_EN_LCK_ERR_IE_MASK)

#define XSPI_INT_EN_LCK_MASK                     (0x80000000U)
#define XSPI_INT_EN_LCK_SHIFT                    (31U)
/*! LCK - Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define XSPI_INT_EN_LCK(x)                       (((uint32_t)(((uint32_t)(x)) << XSPI_INT_EN_LCK_SHIFT)) & XSPI_INT_EN_LCK_MASK)
/*! @} */

/*! @name SFP_TG_IPCR - IP Configuration */
/*! @{ */

#define XSPI_SFP_TG_IPCR_IDATSZ_MASK             (0xFFFFU)
#define XSPI_SFP_TG_IPCR_IDATSZ_SHIFT            (0U)
/*! IDATSZ - IP Data Transfer Size */
#define XSPI_SFP_TG_IPCR_IDATSZ(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_IPCR_IDATSZ_SHIFT)) & XSPI_SFP_TG_IPCR_IDATSZ_MASK)

#define XSPI_SFP_TG_IPCR_ARB_LOCK_MASK           (0x400000U)
#define XSPI_SFP_TG_IPCR_ARB_LOCK_SHIFT          (22U)
/*! ARB_LOCK - Arbitration Lock
 *  0b0..No effect. Always reads 0.
 *  0b1..Locks
 */
#define XSPI_SFP_TG_IPCR_ARB_LOCK(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_IPCR_ARB_LOCK_SHIFT)) & XSPI_SFP_TG_IPCR_ARB_LOCK_MASK)

#define XSPI_SFP_TG_IPCR_ARB_UNLOCK_MASK         (0x800000U)
#define XSPI_SFP_TG_IPCR_ARB_UNLOCK_SHIFT        (23U)
/*! ARB_UNLOCK - Arbitration Unlock
 *  0b0..No effect. Always reads 0.
 *  0b1..Unlocks
 */
#define XSPI_SFP_TG_IPCR_ARB_UNLOCK(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_IPCR_ARB_UNLOCK_SHIFT)) & XSPI_SFP_TG_IPCR_ARB_UNLOCK_MASK)

#define XSPI_SFP_TG_IPCR_SEQID_MASK              (0xF000000U)
#define XSPI_SFP_TG_IPCR_SEQID_SHIFT             (24U)
/*! SEQID - Sequence ID */
#define XSPI_SFP_TG_IPCR_SEQID(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_IPCR_SEQID_SHIFT)) & XSPI_SFP_TG_IPCR_SEQID_MASK)
/*! @} */

/*! @name SFP_TG_SFAR - Serial Flash Memory Address */
/*! @{ */

#define XSPI_SFP_TG_SFAR_SFADR_MASK              (0xFFFFFFFFU)
#define XSPI_SFP_TG_SFAR_SFADR_SHIFT             (0U)
/*! SFADR - Serial Flash Memory Address */
#define XSPI_SFP_TG_SFAR_SFADR(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_SFAR_SFADR_SHIFT)) & XSPI_SFP_TG_SFAR_SFADR_MASK)
/*! @} */

/*! @name SFP_LUT_EN - LUT Access Enable */
/*! @{ */

#define XSPI_SFP_LUT_EN_LUT_SEQ0_EN_MASK         (0x1U)
#define XSPI_SFP_LUT_EN_LUT_SEQ0_EN_SHIFT        (0U)
/*! LUT_SEQ0_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ0_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ0_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ0_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ1_EN_MASK         (0x2U)
#define XSPI_SFP_LUT_EN_LUT_SEQ1_EN_SHIFT        (1U)
/*! LUT_SEQ1_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ1_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ1_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ1_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ2_EN_MASK         (0x4U)
#define XSPI_SFP_LUT_EN_LUT_SEQ2_EN_SHIFT        (2U)
/*! LUT_SEQ2_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ2_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ2_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ2_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ3_EN_MASK         (0x8U)
#define XSPI_SFP_LUT_EN_LUT_SEQ3_EN_SHIFT        (3U)
/*! LUT_SEQ3_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ3_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ3_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ3_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ4_EN_MASK         (0x10U)
#define XSPI_SFP_LUT_EN_LUT_SEQ4_EN_SHIFT        (4U)
/*! LUT_SEQ4_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ4_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ4_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ4_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ5_EN_MASK         (0x20U)
#define XSPI_SFP_LUT_EN_LUT_SEQ5_EN_SHIFT        (5U)
/*! LUT_SEQ5_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ5_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ5_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ5_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ6_EN_MASK         (0x40U)
#define XSPI_SFP_LUT_EN_LUT_SEQ6_EN_SHIFT        (6U)
/*! LUT_SEQ6_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ6_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ6_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ6_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ7_EN_MASK         (0x80U)
#define XSPI_SFP_LUT_EN_LUT_SEQ7_EN_SHIFT        (7U)
/*! LUT_SEQ7_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ7_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ7_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ7_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ8_EN_MASK         (0x100U)
#define XSPI_SFP_LUT_EN_LUT_SEQ8_EN_SHIFT        (8U)
/*! LUT_SEQ8_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ8_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ8_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ8_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ9_EN_MASK         (0x200U)
#define XSPI_SFP_LUT_EN_LUT_SEQ9_EN_SHIFT        (9U)
/*! LUT_SEQ9_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ9_EN(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ9_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ9_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ10_EN_MASK        (0x400U)
#define XSPI_SFP_LUT_EN_LUT_SEQ10_EN_SHIFT       (10U)
/*! LUT_SEQ10_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ10_EN(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ10_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ10_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ11_EN_MASK        (0x800U)
#define XSPI_SFP_LUT_EN_LUT_SEQ11_EN_SHIFT       (11U)
/*! LUT_SEQ11_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ11_EN(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ11_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ11_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ12_EN_MASK        (0x1000U)
#define XSPI_SFP_LUT_EN_LUT_SEQ12_EN_SHIFT       (12U)
/*! LUT_SEQ12_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ12_EN(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ12_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ12_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ13_EN_MASK        (0x2000U)
#define XSPI_SFP_LUT_EN_LUT_SEQ13_EN_SHIFT       (13U)
/*! LUT_SEQ13_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ13_EN(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ13_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ13_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ14_EN_MASK        (0x4000U)
#define XSPI_SFP_LUT_EN_LUT_SEQ14_EN_SHIFT       (14U)
/*! LUT_SEQ14_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ14_EN(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ14_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ14_EN_MASK)

#define XSPI_SFP_LUT_EN_LUT_SEQ15_EN_MASK        (0x8000U)
#define XSPI_SFP_LUT_EN_LUT_SEQ15_EN_SHIFT       (15U)
/*! LUT_SEQ15_EN - LUT Sequence Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define XSPI_SFP_LUT_EN_LUT_SEQ15_EN(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LUT_SEQ15_EN_SHIFT)) & XSPI_SFP_LUT_EN_LUT_SEQ15_EN_MASK)

#define XSPI_SFP_LUT_EN_LOCK_MASK                (0x80000000U)
#define XSPI_SFP_LUT_EN_LOCK_SHIFT               (31U)
/*! LOCK
 *  0b0..No effect
 *  0b1..Locks
 */
#define XSPI_SFP_LUT_EN_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LUT_EN_LOCK_SHIFT)) & XSPI_SFP_LUT_EN_LOCK_MASK)
/*! @} */

/* The count of XSPI_SFP_LUT_EN */
#define XSPI_SFP_LUT_EN_COUNT                    (2U)

/*! @name SFP_LOCK_ERR_ADDR - SFP Lock Error Address */
/*! @{ */

#define XSPI_SFP_LOCK_ERR_ADDR_ADDRW_MASK        (0x7FFFU)
#define XSPI_SFP_LOCK_ERR_ADDR_ADDRW_SHIFT       (0U)
/*! ADDRW - Address */
#define XSPI_SFP_LOCK_ERR_ADDR_ADDRW(x)          (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_LOCK_ERR_ADDR_ADDRW_SHIFT)) & XSPI_SFP_LOCK_ERR_ADDR_ADDRW_MASK)
/*! @} */

/*! @name SFP_TG_SUB_IPCR - IP Configuration */
/*! @{ */

#define XSPI_SFP_TG_SUB_IPCR_IDATSZ_MASK         (0xFFFFU)
#define XSPI_SFP_TG_SUB_IPCR_IDATSZ_SHIFT        (0U)
/*! IDATSZ - IP Data Transfer Size */
#define XSPI_SFP_TG_SUB_IPCR_IDATSZ(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_SUB_IPCR_IDATSZ_SHIFT)) & XSPI_SFP_TG_SUB_IPCR_IDATSZ_MASK)

#define XSPI_SFP_TG_SUB_IPCR_ARB_LOCK_MASK       (0x400000U)
#define XSPI_SFP_TG_SUB_IPCR_ARB_LOCK_SHIFT      (22U)
/*! ARB_LOCK - Arbitration Lock
 *  0b0..No effect. Always reads 0.
 *  0b1..Locks
 */
#define XSPI_SFP_TG_SUB_IPCR_ARB_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_SUB_IPCR_ARB_LOCK_SHIFT)) & XSPI_SFP_TG_SUB_IPCR_ARB_LOCK_MASK)

#define XSPI_SFP_TG_SUB_IPCR_ARB_UNLOCK_MASK     (0x800000U)
#define XSPI_SFP_TG_SUB_IPCR_ARB_UNLOCK_SHIFT    (23U)
/*! ARB_UNLOCK - Arbitration Unlock
 *  0b0..No effect. Always reads 0.
 *  0b1..Unlocks
 */
#define XSPI_SFP_TG_SUB_IPCR_ARB_UNLOCK(x)       (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_SUB_IPCR_ARB_UNLOCK_SHIFT)) & XSPI_SFP_TG_SUB_IPCR_ARB_UNLOCK_MASK)

#define XSPI_SFP_TG_SUB_IPCR_SEQID_MASK          (0xF000000U)
#define XSPI_SFP_TG_SUB_IPCR_SEQID_SHIFT         (24U)
/*! SEQID - Points to a sequence in the LUT */
#define XSPI_SFP_TG_SUB_IPCR_SEQID(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_SUB_IPCR_SEQID_SHIFT)) & XSPI_SFP_TG_SUB_IPCR_SEQID_MASK)
/*! @} */

/* The count of XSPI_SFP_TG_SUB_IPCR */
#define XSPI_SFP_TG_SUB_IPCR_COUNT               (1U)

/*! @name SFP_TG_SUB_SFAR - Serial Flash Memory Address */
/*! @{ */

#define XSPI_SFP_TG_SUB_SFAR_SFADR_MASK          (0xFFFFFFFFU)
#define XSPI_SFP_TG_SUB_SFAR_SFADR_SHIFT         (0U)
/*! SFADR - Serial flash memory address */
#define XSPI_SFP_TG_SUB_SFAR_SFADR(x)            (((uint32_t)(((uint32_t)(x)) << XSPI_SFP_TG_SUB_SFAR_SFADR_SHIFT)) & XSPI_SFP_TG_SUB_SFAR_SFADR_MASK)
/*! @} */

/* The count of XSPI_SFP_TG_SUB_SFAR */
#define XSPI_SFP_TG_SUB_SFAR_COUNT               (1U)

/*! @name TGSFAR_SUB - Target Group SFAR Address */
/*! @{ */

#define XSPI_TGSFAR_SUB_SFARADDR_MASK            (0xFFFFFFFFU)
#define XSPI_TGSFAR_SUB_SFARADDR_SHIFT           (0U)
/*! SFARADDR - SFAR Address */
#define XSPI_TGSFAR_SUB_SFARADDR(x)              (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFAR_SUB_SFARADDR_SHIFT)) & XSPI_TGSFAR_SUB_SFARADDR_MASK)
/*! @} */

/* The count of XSPI_TGSFAR_SUB */
#define XSPI_TGSFAR_SUB_COUNT                    (1U)

/*! @name TGSFARS_SUB - Target Group SFAR Status */
/*! @{ */

#define XSPI_TGSFARS_SUB_TG_MID_MASK             (0x3FU)
#define XSPI_TGSFARS_SUB_TG_MID_SHIFT            (0U)
/*! TG_MID - Transaction Manager ID */
#define XSPI_TGSFARS_SUB_TG_MID(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_SUB_TG_MID_SHIFT)) & XSPI_TGSFARS_SUB_TG_MID_MASK)

#define XSPI_TGSFARS_SUB_SA_MASK                 (0x400U)
#define XSPI_TGSFARS_SUB_SA_SHIFT                (10U)
/*! SA - Secure Attribute
 *  0b0..Non-secure
 *  0b1..Secure
 */
#define XSPI_TGSFARS_SUB_SA(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_SUB_SA_SHIFT)) & XSPI_TGSFARS_SUB_SA_MASK)

#define XSPI_TGSFARS_SUB_PA_MASK                 (0x1000U)
#define XSPI_TGSFARS_SUB_PA_SHIFT                (12U)
/*! PA - Privileged Attribute
 *  0b0..Non-privileged
 *  0b1..Privileged
 */
#define XSPI_TGSFARS_SUB_PA(x)                   (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_SUB_PA_SHIFT)) & XSPI_TGSFARS_SUB_PA_MASK)

#define XSPI_TGSFARS_SUB_CLR_MASK                (0x20000000U)
#define XSPI_TGSFARS_SUB_CLR_SHIFT               (29U)
/*! CLR - Clear
 *  0b0..Conveys no useful information
 *  0b0..No action
 *  0b1..Clears
 */
#define XSPI_TGSFARS_SUB_CLR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_SUB_CLR_SHIFT)) & XSPI_TGSFARS_SUB_CLR_MASK)

#define XSPI_TGSFARS_SUB_ERR_MASK                (0x40000000U)
#define XSPI_TGSFARS_SUB_ERR_SHIFT               (30U)
/*! ERR - Error
 *  0b0..With required attributes
 *  0b1..Without required attributes
 */
#define XSPI_TGSFARS_SUB_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_SUB_ERR_SHIFT)) & XSPI_TGSFARS_SUB_ERR_MASK)

#define XSPI_TGSFARS_SUB_VLD_MASK                (0x80000000U)
#define XSPI_TGSFARS_SUB_VLD_SHIFT               (31U)
/*! VLD - Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define XSPI_TGSFARS_SUB_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_TGSFARS_SUB_VLD_SHIFT)) & XSPI_TGSFARS_SUB_VLD_MASK)
/*! @} */

/* The count of XSPI_TGSFARS_SUB */
#define XSPI_TGSFARS_SUB_COUNT                   (1U)

/*! @name TGIPCRS_SUB - Target Group n IP Configuration Status */
/*! @{ */

#define XSPI_TGIPCRS_SUB_IDATSZ_MASK             (0xFFFFU)
#define XSPI_TGIPCRS_SUB_IDATSZ_SHIFT            (0U)
/*! IDATSZ - IP Data Transfer Size */
#define XSPI_TGIPCRS_SUB_IDATSZ(x)               (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_IDATSZ_SHIFT)) & XSPI_TGIPCRS_SUB_IDATSZ_MASK)

#define XSPI_TGIPCRS_SUB_SEQID_MASK              (0xF0000U)
#define XSPI_TGIPCRS_SUB_SEQID_SHIFT             (16U)
/*! SEQID - SEQID Value */
#define XSPI_TGIPCRS_SUB_SEQID(x)                (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_SEQID_SHIFT)) & XSPI_TGIPCRS_SUB_SEQID_MASK)

#define XSPI_TGIPCRS_SUB_ARB_LOCK_MASK           (0x200000U)
#define XSPI_TGIPCRS_SUB_ARB_LOCK_SHIFT          (21U)
/*! ARB_LOCK - Arbitration Lock
 *  0b0..Not requested
 *  0b1..Requested
 */
#define XSPI_TGIPCRS_SUB_ARB_LOCK(x)             (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_ARB_LOCK_SHIFT)) & XSPI_TGIPCRS_SUB_ARB_LOCK_MASK)

#define XSPI_TGIPCRS_SUB_ARB_UNLOCK_MASK         (0x400000U)
#define XSPI_TGIPCRS_SUB_ARB_UNLOCK_SHIFT        (22U)
/*! ARB_UNLOCK - Arbitration Unlock
 *  0b0..Not requested
 *  0b1..Requested
 */
#define XSPI_TGIPCRS_SUB_ARB_UNLOCK(x)           (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_ARB_UNLOCK_SHIFT)) & XSPI_TGIPCRS_SUB_ARB_UNLOCK_MASK)

#define XSPI_TGIPCRS_SUB_CLR_MASK                (0x10000000U)
#define XSPI_TGIPCRS_SUB_CLR_SHIFT               (28U)
/*! CLR - Clear
 *  0b0..Conveys no useful information
 *  0b0..No action
 *  0b1..Clears
 */
#define XSPI_TGIPCRS_SUB_CLR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_CLR_SHIFT)) & XSPI_TGIPCRS_SUB_CLR_MASK)

#define XSPI_TGIPCRS_SUB_ERR_MASK                (0x60000000U)
#define XSPI_TGIPCRS_SUB_ERR_SHIFT               (29U)
/*! ERR - Error
 *  0b00..Required attributes
 *  0b01..IPCR DATZ without required attributes
 *  0b10..IPCR SEQID without required attributes
 *  0b11..IPCR DATZ and SEQID without required attributes
 */
#define XSPI_TGIPCRS_SUB_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_ERR_SHIFT)) & XSPI_TGIPCRS_SUB_ERR_MASK)

#define XSPI_TGIPCRS_SUB_VLD_MASK                (0x80000000U)
#define XSPI_TGIPCRS_SUB_VLD_SHIFT               (31U)
/*! VLD - Valid
 *  0b0..Not valid
 *  0b1..Valid and queue is locked
 */
#define XSPI_TGIPCRS_SUB_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << XSPI_TGIPCRS_SUB_VLD_SHIFT)) & XSPI_TGIPCRS_SUB_VLD_MASK)
/*! @} */

/* The count of XSPI_TGIPCRS_SUB */
#define XSPI_TGIPCRS_SUB_COUNT                   (1U)


/*!
 * @}
 */ /* end of group XSPI_Register_Masks */


/*!
 * @}
 */ /* end of group XSPI_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_XSPI_H_ */

