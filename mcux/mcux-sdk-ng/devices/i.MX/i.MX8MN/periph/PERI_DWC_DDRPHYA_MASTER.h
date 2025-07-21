/*
** ###################################################################
**     Processors:          MIMX8MN1CVPIZ_ca53
**                          MIMX8MN1CVPIZ_cm7
**                          MIMX8MN1CVTIZ_ca53
**                          MIMX8MN1CVTIZ_cm7
**                          MIMX8MN1DVPIZ_ca53
**                          MIMX8MN1DVPIZ_cm7
**                          MIMX8MN1DVTJZ_ca53
**                          MIMX8MN1DVTJZ_cm7
**                          MIMX8MN2CVTIZ_ca53
**                          MIMX8MN2CVTIZ_cm7
**                          MIMX8MN2DVTJZ_ca53
**                          MIMX8MN2DVTJZ_cm7
**                          MIMX8MN3CVPIZ_ca53
**                          MIMX8MN3CVPIZ_cm7
**                          MIMX8MN3CVTIZ_ca53
**                          MIMX8MN3CVTIZ_cm7
**                          MIMX8MN3DVPIZ_ca53
**                          MIMX8MN3DVPIZ_cm7
**                          MIMX8MN3DVTJZ_ca53
**                          MIMX8MN3DVTJZ_cm7
**                          MIMX8MN4CVTIZ_ca53
**                          MIMX8MN4CVTIZ_cm7
**                          MIMX8MN4DVTJZ_ca53
**                          MIMX8MN4DVTJZ_cm7
**                          MIMX8MN5CVPIZ_ca53
**                          MIMX8MN5CVPIZ_cm7
**                          MIMX8MN5CVTIZ_ca53
**                          MIMX8MN5CVTIZ_cm7
**                          MIMX8MN5DVPIZ_ca53
**                          MIMX8MN5DVPIZ_cm7
**                          MIMX8MN5DVTJZ_ca53
**                          MIMX8MN5DVTJZ_cm7
**                          MIMX8MN6CVTIZ_ca53
**                          MIMX8MN6CVTIZ_cm7
**                          MIMX8MN6DVTJZ_ca53
**                          MIMX8MN6DVTJZ_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DWC_DDRPHYA_MASTER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2019-09-23)
**         Rev.B Header RFP
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DWC_DDRPHYA_MASTER.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DWC_DDRPHYA_MASTER
 *
 * CMSIS Peripheral Access Layer for DWC_DDRPHYA_MASTER
 */

#if !defined(PERI_DWC_DDRPHYA_MASTER_H_)
#define PERI_DWC_DDRPHYA_MASTER_H_               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MN1CVPIZ_ca53) || defined(CPU_MIMX8MN1CVTIZ_ca53) || defined(CPU_MIMX8MN1DVPIZ_ca53) || defined(CPU_MIMX8MN1DVTJZ_ca53))
#include "MIMX8MN1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN1CVPIZ_cm7) || defined(CPU_MIMX8MN1CVTIZ_cm7) || defined(CPU_MIMX8MN1DVPIZ_cm7) || defined(CPU_MIMX8MN1DVTJZ_cm7))
#include "MIMX8MN1_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_ca53) || defined(CPU_MIMX8MN2DVTJZ_ca53))
#include "MIMX8MN2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_cm7) || defined(CPU_MIMX8MN2DVTJZ_cm7))
#include "MIMX8MN2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_ca53) || defined(CPU_MIMX8MN3CVTIZ_ca53) || defined(CPU_MIMX8MN3DVPIZ_ca53) || defined(CPU_MIMX8MN3DVTJZ_ca53))
#include "MIMX8MN3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_cm7) || defined(CPU_MIMX8MN3CVTIZ_cm7) || defined(CPU_MIMX8MN3DVPIZ_cm7) || defined(CPU_MIMX8MN3DVTJZ_cm7))
#include "MIMX8MN3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_ca53) || defined(CPU_MIMX8MN4DVTJZ_ca53))
#include "MIMX8MN4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_cm7) || defined(CPU_MIMX8MN4DVTJZ_cm7))
#include "MIMX8MN4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_ca53) || defined(CPU_MIMX8MN5CVTIZ_ca53) || defined(CPU_MIMX8MN5DVPIZ_ca53) || defined(CPU_MIMX8MN5DVTJZ_ca53))
#include "MIMX8MN5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_cm7) || defined(CPU_MIMX8MN5CVTIZ_cm7) || defined(CPU_MIMX8MN5DVPIZ_cm7) || defined(CPU_MIMX8MN5DVTJZ_cm7))
#include "MIMX8MN5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_ca53) || defined(CPU_MIMX8MN6DVTJZ_ca53))
#include "MIMX8MN6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_cm7) || defined(CPU_MIMX8MN6DVTJZ_cm7))
#include "MIMX8MN6_cm7_COMMON.h"
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
   -- DWC_DDRPHYA_MASTER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_MASTER_Peripheral_Access_Layer DWC_DDRPHYA_MASTER Peripheral Access Layer
 * @{
 */

/** DWC_DDRPHYA_MASTER - Register Layout Typedef */
typedef struct {
  __IO uint16_t RXFIFOINIT;                        /**< Rx FIFO pointer initialization control, offset: 0x0 */
  __IO uint16_t FORCECLKDISABLE;                   /**< Clock gating control, offset: 0x2 */
       uint8_t RESERVED_0[2];
  __IO uint16_t FORCEINTERNALUPDATE;               /**< This Register used by Training Firmware to force an internal PHY Update Event., offset: 0x6 */
  __I  uint16_t PHYCONFIG;                         /**< Read Only displays PHY Configuration., offset: 0x8 */
  __IO uint16_t PGCR;                              /**< PHY General Configuration Register(PGCR)., offset: 0xA */
       uint8_t RESERVED_1[2];
  __IO uint16_t TESTBUMPCNTRL1;                    /**< Test Bump Control1, offset: 0xE */
  __IO uint16_t CALUCLKINFO_P0;                    /**< Impedance Calibration Clock Ratio, offset: 0x10 */
       uint8_t RESERVED_2[2];
  __IO uint16_t TESTBUMPCNTRL;                     /**< Test Bump Control, offset: 0x14 */
  __IO uint16_t SEQ0BDLY0_P0;                      /**< PHY Initialization Engine (PIE) Delay Register 0, offset: 0x16 */
  __IO uint16_t SEQ0BDLY1_P0;                      /**< PHY Initialization Engine (PIE) Delay Register 1, offset: 0x18 */
  __IO uint16_t SEQ0BDLY2_P0;                      /**< PHY Initialization Engine (PIE) Delay Register 2, offset: 0x1A */
  __IO uint16_t SEQ0BDLY3_P0;                      /**< PHY Initialization Engine (PIE) Delay Register 3, offset: 0x1C */
  __I  uint16_t PHYALERTSTATUS;                    /**< PHY Alert status bit, offset: 0x1E */
  __IO uint16_t PPTTRAINSETUP_P0;                  /**< Setup Intervals for DFI PHY Master operations, offset: 0x20 */
       uint8_t RESERVED_3[2];
  __IO uint16_t ATESTMODE;                         /**< ATestMode control, offset: 0x24 */
       uint8_t RESERVED_4[2];
  __I  uint16_t TXCALBINP;                         /**< TX P Impedance Calibration observation, offset: 0x28 */
  __I  uint16_t TXCALBINN;                         /**< TX N Impedance Calibration observation, offset: 0x2A */
  __IO uint16_t TXCALPOVR;                         /**< TX P Impedance Calibration override, offset: 0x2C */
  __IO uint16_t TXCALNOVR;                         /**< TX N Impedance Calibration override, offset: 0x2E */
  __IO uint16_t DFIMODE;                           /**< Enables for update and low-power interfaces for DFI0 and DFI1, offset: 0x30 */
  __IO uint16_t TRISTATEMODECA_P0;                 /**< Mode select register for MEMCLK/Address/Command Tristates, offset: 0x32 */
  __IO uint16_t MTESTMUXSEL;                       /**< Digital Observation Pin control, offset: 0x34 */
  __IO uint16_t MTESTPGMINFO;                      /**< Digital Observation Pin program info for debug, offset: 0x36 */
  __IO uint16_t DYNPWRDNUP;                        /**< Dynaimc Power Up/Down control, offset: 0x38 */
       uint8_t RESERVED_5[2];
  __IO uint16_t PHYTID;                            /**< PHY Technology ID Register, offset: 0x3C */
       uint8_t RESERVED_6[2];
  __IO uint16_t HWTMRL_P0;                         /**< HWT MaxReadLatency., offset: 0x40 */
  __IO uint16_t DFIPHYUPD;                         /**< DFI PhyUpdate Request time counter (in MEMCLKs), offset: 0x42 */
  __IO uint16_t PDAMRSWRITEMODE;                   /**< Controls the write DQ generation for Per-Dram-Addressing of MRS, offset: 0x44 */
  __IO uint16_t DFIGEARDOWNCTL;                    /**< Controls whether dfi_geardown_en will cause CS and CKE timing to change., offset: 0x46 */
  __IO uint16_t DQSPREAMBLECONTROL_P0;             /**< Control the PHY logic related to the read and write DQS preamble, offset: 0x48 */
  __IO uint16_t MASTERX4CONFIG;                    /**< DBYTE module controls to select X4 Dram device mode, offset: 0x4A */
  __IO uint16_t WRLEVBITS;                         /**< Write level feedback DQ observability select., offset: 0x4C */
  __IO uint16_t ENABLECSMULTICAST;                 /**< In DDR4 Mode , this controls whether CS_N[3:2] should be multicast on CID[1:0], offset: 0x4E */
  __IO uint16_t HWTLPCSMULTICAST;                  /**< Drives cs_n[0] onto cs_n[1] during training, offset: 0x50 */
       uint8_t RESERVED_7[6];
  __IO uint16_t ACX4ANIBDIS;                       /**< Disable for unused ACX Nibbles, offset: 0x58 */
  __IO uint16_t DMIPINPRESENT_P0;                  /**< This Register is used to enable the Read-DBI function in each DBYTE, offset: 0x5A */
  __IO uint16_t ARDPTRINITVAL_P0;                  /**< Address/Command FIFO ReadPointer Initial Value, offset: 0x5C */
       uint8_t RESERVED_8[22];
  __IO uint16_t DBYTEDLLMODECNTRL;                 /**< DLL Mode control CSR for DBYTEs, offset: 0x74 */
       uint8_t RESERVED_9[20];
  __IO uint16_t CALOFFSETS;                        /**< Impedance Calibration offsets control, offset: 0x8A */
       uint8_t RESERVED_10[2];
  __IO uint16_t SARINITVALS;                       /**< Sar Init Vals, offset: 0x8E */
       uint8_t RESERVED_11[2];
  __IO uint16_t CALPEXTOVR;                        /**< Impedance Calibration PExt Override control, offset: 0x92 */
  __IO uint16_t CALCMPR5OVR;                       /**< Impedance Calibration Cmpr 50 control, offset: 0x94 */
  __IO uint16_t CALNINTOVR;                        /**< Impedance Calibration NInt Override control, offset: 0x96 */
       uint8_t RESERVED_12[8];
  __IO uint16_t CALDRVSTR0;                        /**< Impedance Calibration driver strength control, offset: 0xA0 */
       uint8_t RESERVED_13[10];
  __IO uint16_t PROCODTTIMECTL_P0;                 /**< READ DATA On-Die Termination Timing Control (by PHY), offset: 0xAC */
       uint8_t RESERVED_14[8];
  __IO uint16_t MEMALERTCONTROL;                   /**< This Register is used to configure the MemAlert Receiver, offset: 0xB6 */
  __IO uint16_t MEMALERTCONTROL2;                  /**< This Register is used to configure the MemAlert Receiver, offset: 0xB8 */
       uint8_t RESERVED_15[6];
  __IO uint16_t MEMRESETL;                         /**< Protection and control of BP_MemReset_L, offset: 0xC0 */
       uint8_t RESERVED_16[24];
  __IO uint16_t DRIVECSLOWONTOHIGH;                /**< Drive CS_N 3:0 onto CS_N 7:4, offset: 0xDA */
  __IO uint16_t PUBMODE;                           /**< PUBMODE - HWT Mux Select, offset: 0xDC */
  __I  uint16_t MISCPHYSTATUS;                     /**< Misc PHY status bits, offset: 0xDE */
  __IO uint16_t CORELOOPBACKSEL;                   /**< Controls whether the loopback path bypasses the final PAD node., offset: 0xE0 */
  __IO uint16_t DLLTRAINPARAM;                     /**< DLL Various Training Parameters, offset: 0xE2 */
       uint8_t RESERVED_17[4];
  __IO uint16_t HWTLPCSENBYPASS;                   /**< CSn Disable Bypass for LPDDR3/4, offset: 0xE8 */
  __IO uint16_t DFICAMODE;                         /**< Dfi Command/Address Mode, offset: 0xEA */
       uint8_t RESERVED_18[4];
  __IO uint16_t DLLCONTROL;                        /**< DLL Lock State machine control register, offset: 0xF0 */
  __IO uint16_t PULSEDLLUPDATEPHASE;               /**< DLL update phase control, offset: 0xF2 */
       uint8_t RESERVED_19[4];
  __IO uint16_t DLLGAINCTL_P0;                     /**< DLL gain control, offset: 0xF8 */
       uint8_t RESERVED_20[22];
  __IO uint16_t CALRATE;                           /**< Impedance Calibration Control, offset: 0x110 */
  __IO uint16_t CALZAP;                            /**< Impedance Calibration Zap/Reset, offset: 0x112 */
       uint8_t RESERVED_21[2];
  __IO uint16_t PSTATE;                            /**< PSTATE Selection, offset: 0x116 */
       uint8_t RESERVED_22[2];
  __IO uint16_t PLLOUTGATECONTROL;                 /**< PLL Output Control, offset: 0x11A */
       uint8_t RESERVED_23[4];
  __IO uint16_t PORCONTROL;                        /**< PMU Power-on Reset Control (PLL/DLL Lock Done), offset: 0x120 */
       uint8_t RESERVED_24[12];
  __I  uint16_t CALBUSY;                           /**< Impedance Calibration Busy Status, offset: 0x12E */
  __IO uint16_t CALMISC2;                          /**< Miscellaneous impedance calibration controls., offset: 0x130 */
       uint8_t RESERVED_25[2];
  __IO uint16_t CALMISC;                           /**< Controls for disabling the impedance calibration of certain targets., offset: 0x134 */
  __I  uint16_t CALVREFS;                          /**< offset: 0x136 */
  __I  uint16_t CALCMPR5;                          /**< Impedance Calibration Cmpr control, offset: 0x138 */
  __I  uint16_t CALNINT;                           /**< Impedance Calibration NInt control, offset: 0x13A */
  __I  uint16_t CALPEXT;                           /**< Impedance Calibration PExt control, offset: 0x13C */
       uint8_t RESERVED_26[18];
  __IO uint16_t CALCMPINVERT;                      /**< Impedance Calibration Cmp Invert control, offset: 0x150 */
       uint8_t RESERVED_27[10];
  __IO uint16_t CALCMPANACNTRL;                    /**< Impedance Calibration Cmpana control, offset: 0x15C */
       uint8_t RESERVED_28[2];
  __IO uint16_t DFIRDDATACSDESTMAP_P0;             /**< Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM, offset: 0x160 */
       uint8_t RESERVED_29[2];
  __IO uint16_t VREFINGLOBAL_P0;                   /**< PHY Global Vref Controls, offset: 0x164 */
       uint8_t RESERVED_30[2];
  __IO uint16_t DFIWRDATACSDESTMAP_P0;             /**< Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM, offset: 0x168 */
  __I  uint16_t MASUPDGOODCTR;                     /**< Counts successful PHY Master Interface Updates (PPTs), offset: 0x16A */
  __I  uint16_t PHYUPD0GOODCTR;                    /**< Counts successful PHY-initiated DFI0 Interface Updates, offset: 0x16C */
  __I  uint16_t PHYUPD1GOODCTR;                    /**< Counts successful PHY-initiated DFI1 Interface Updates, offset: 0x16E */
  __I  uint16_t CTLUPD0GOODCTR;                    /**< Counts successful Memory Controller DFI0 Interface Updates, offset: 0x170 */
  __I  uint16_t CTLUPD1GOODCTR;                    /**< Counts successful Memory Controller DFI1 Interface Updates, offset: 0x172 */
  __I  uint16_t MASUPDFAILCTR;                     /**< Counts unsuccessful PHY Master Interface Updates, offset: 0x174 */
  __I  uint16_t PHYUPD0FAILCTR;                    /**< Counts unsuccessful PHY-initiated DFI0 Interface Updates, offset: 0x176 */
  __I  uint16_t PHYUPD1FAILCTR;                    /**< Counts unsuccessful PHY-initiated DFI1 Interface Updates, offset: 0x178 */
  __IO uint16_t PHYPERFCTRENABLE;                  /**< Enables for Performance Counters, offset: 0x17A */
       uint8_t RESERVED_31[10];
  __IO uint16_t PLLPWRDN;                          /**< PLL Power Down, offset: 0x186 */
  __IO uint16_t PLLRESET;                          /**< PLL Reset, offset: 0x188 */
  __IO uint16_t PLLCTRL2_P0;                       /**< PState dependent PLL Control Register 2, offset: 0x18A */
  __IO uint16_t PLLCTRL0;                          /**< PLL Control Register 0, offset: 0x18C */
  __IO uint16_t PLLCTRL1_P0;                       /**< PState dependent PLL Control Register 1, offset: 0x18E */
  __IO uint16_t PLLTST;                            /**< PLL Testing Control Register, offset: 0x190 */
  __I  uint16_t PLLLOCKSTATUS;                     /**< PLL's pll_lock pin output, offset: 0x192 */
  __IO uint16_t PLLTESTMODE_P0;                    /**< Additional controls for PLL CP/VCO modes of operation, offset: 0x194 */
  __IO uint16_t PLLCTRL3;                          /**< PLL Control Register 3, offset: 0x196 */
  __IO uint16_t PLLCTRL4_P0;                       /**< PState dependent PLL Control Register 4, offset: 0x198 */
  __I  uint16_t PLLENDOFCAL;                       /**< PLL's eoc (end of calibration) output, offset: 0x19A */
  __I  uint16_t PLLSTANDBYEFF;                     /**< PLL's standby_eff (effective standby) output, offset: 0x19C */
  __I  uint16_t PLLDACVALOUT;                      /**< PLL's Dacval_out output, offset: 0x19E */
       uint8_t RESERVED_32[38];
  __IO uint16_t LCDLDBGCNTL;                       /**< Controls for use in observing and testing the LCDLs., offset: 0x1C6 */
  __I  uint16_t ACLCDLSTATUS;                      /**< Debug status of the DBYTE LCDL, offset: 0x1C8 */
       uint8_t RESERVED_33[16];
  __I  uint16_t CUSTPHYREV;                        /**< Customer settable by the customer, offset: 0x1DA */
  __I  uint16_t PHYREV;                            /**< The hardware version of this PHY, excluding the PUB, offset: 0x1DC */
  __IO uint16_t LP3EXITSEQ0BSTARTVECTOR;           /**< Start vector value to be used for LP3-exit or Init PIE Sequence, offset: 0x1DE */
  __IO uint16_t DFIFREQXLAT0;                      /**< DFI Frequency Translation Register 0, offset: 0x1E0 */
  __IO uint16_t DFIFREQXLAT1;                      /**< DFI Frequency Translation Register 1, offset: 0x1E2 */
  __IO uint16_t DFIFREQXLAT2;                      /**< DFI Frequency Translation Register 2, offset: 0x1E4 */
  __IO uint16_t DFIFREQXLAT3;                      /**< DFI Frequency Translation Register 3, offset: 0x1E6 */
  __IO uint16_t DFIFREQXLAT4;                      /**< DFI Frequency Translation Register 4, offset: 0x1E8 */
  __IO uint16_t DFIFREQXLAT5;                      /**< DFI Frequency Translation Register 5, offset: 0x1EA */
  __IO uint16_t DFIFREQXLAT6;                      /**< DFI Frequency Translation Register 6, offset: 0x1EC */
  __IO uint16_t DFIFREQXLAT7;                      /**< DFI Frequency Translation Register 7, offset: 0x1EE */
  __IO uint16_t TXRDPTRINIT;                       /**< TxRdPtrInit control register, offset: 0x1F0 */
  __IO uint16_t DFIINITCOMPLETE;                   /**< DFI Init Complete control, offset: 0x1F2 */
  __IO uint16_t DFIFREQRATIO_P0;                   /**< DFI Frequency Ratio, offset: 0x1F4 */
  __IO uint16_t RXFIFOCHECKS;                      /**< Enable more frequent consistency checks of the RX FIFOs, offset: 0x1F6 */
       uint8_t RESERVED_34[6];
  __IO uint16_t MTESTDTOCTRL;                      /**< offset: 0x1FE */
  __IO uint16_t MAPCAA0TODFI;                      /**< Maps PHY CAA lane 0 from dfi0_address of the index of the register contents, offset: 0x200 */
  __IO uint16_t MAPCAA1TODFI;                      /**< Maps PHY CAA lane 1 from dfi0_address of the index of the register contents, offset: 0x202 */
  __IO uint16_t MAPCAA2TODFI;                      /**< Maps PHY CAA lane 2 from dfi0_address of the index of the register contents, offset: 0x204 */
  __IO uint16_t MAPCAA3TODFI;                      /**< Maps PHY CAA lane 3 from dfi0_address of the index of the register contents, offset: 0x206 */
  __IO uint16_t MAPCAA4TODFI;                      /**< Maps PHY CAA lane 4 from dfi0_address of the index of the register contents, offset: 0x208 */
  __IO uint16_t MAPCAA5TODFI;                      /**< Maps PHY CAA lane 5 from dfi0_address of the index of the register contents, offset: 0x20A */
  __IO uint16_t MAPCAA6TODFI;                      /**< Maps PHY CAA lane 6 from dfi0_address of the index of the register contents, offset: 0x20C */
  __IO uint16_t MAPCAA7TODFI;                      /**< Maps PHY CAA lane 7 from dfi0_address of the index of the register contents, offset: 0x20E */
  __IO uint16_t MAPCAA8TODFI;                      /**< Maps PHY CAA lane 8 from dfi0_address of the index of the register contents, offset: 0x210 */
  __IO uint16_t MAPCAA9TODFI;                      /**< Maps PHY CAA lane 9 from dfi0_address of the index of the register contents, offset: 0x212 */
       uint8_t RESERVED_35[12];
  __IO uint16_t MAPCAB0TODFI;                      /**< Maps PHY CAB lane 0 from dfi1_address of the index of the register contents, offset: 0x220 */
  __IO uint16_t MAPCAB1TODFI;                      /**< Maps PHY CAB lane 1 from dfi1_address of the index of the register contents, offset: 0x222 */
  __IO uint16_t MAPCAB2TODFI;                      /**< Maps PHY CAB lane 2 from dfi1_address of the index of the register contents, offset: 0x224 */
  __IO uint16_t MAPCAB3TODFI;                      /**< Maps PHY CAB lane 3 from dfi1_address of the index of the register contents, offset: 0x226 */
  __IO uint16_t MAPCAB4TODFI;                      /**< Maps PHY CAB lane 4 from dfi1_address of the index of the register contents, offset: 0x228 */
  __IO uint16_t MAPCAB5TODFI;                      /**< Maps PHY CAB lane 5 from dfi1_address of the index of the register contents, offset: 0x22A */
  __IO uint16_t MAPCAB6TODFI;                      /**< Maps PHY CAB lane 6 from dfi1_address of the index of the register contents, offset: 0x22C */
  __IO uint16_t MAPCAB7TODFI;                      /**< Maps PHY CAB lane 7 from dfi1_address of the index of the register contents, offset: 0x22E */
  __IO uint16_t MAPCAB8TODFI;                      /**< Maps PHY CAB lane 8 from dfi1_address of the index of the register contents, offset: 0x230 */
  __IO uint16_t MAPCAB9TODFI;                      /**< Maps PHY CAB lane 9 from dfi1_address of the index of the register contents, offset: 0x232 */
       uint8_t RESERVED_36[2];
  __IO uint16_t PHYINTERRUPTENABLE;                /**< Interrupt Enable Bits, offset: 0x236 */
  __IO uint16_t PHYINTERRUPTFWCONTROL;             /**< Interrupt Firmware Control Bits, offset: 0x238 */
  __IO uint16_t PHYINTERRUPTMASK;                  /**< Interrupt Mask Bits, offset: 0x23A */
  __IO uint16_t PHYINTERRUPTCLEAR;                 /**< Interrupt Clear Bits, offset: 0x23C */
  __I  uint16_t PHYINTERRUPTSTATUS;                /**< Interrupt Status Bits, offset: 0x23E */
  __IO uint16_t HWTSWIZZLEHWTADDRESS0;             /**< Signal swizzle selection for HWT swizzle, offset: 0x240 */
  __IO uint16_t HWTSWIZZLEHWTADDRESS1;             /**< Signal swizzle selection for HWT swizzle, offset: 0x242 */
  __IO uint16_t HWTSWIZZLEHWTADDRESS2;             /**< Signal swizzle selection for HWT swizzle, offset: 0x244 */
  __IO uint16_t HWTSWIZZLEHWTADDRESS3;             /**< Signal swizzle selection for HWT swizzle, offset: 0x246 */
  __IO uint16_t HWTSWIZZLEHWTADDRESS4;             /**< Signal swizzle selection for HWT swizzle, offset: 0x248 */
  __IO uint16_t HWTSWIZZLEHWTADDRESS5;             /**< Signal swizzle selection for HWT swizzle, offset: 0x24A */
  __IO uint16_t HWTSWIZZLEHWTADDRESS6;             /**< Signal swizzle selection for HWT swizzle, offset: 0x24C */
  __IO uint16_t HWTSWIZZLEHWTADDRESS7;             /**< Signal swizzle selection for HWT swizzle, offset: 0x24E */
  __IO uint16_t HWTSWIZZLEHWTADDRESS8;             /**< Signal swizzle selection for HWT swizzle, offset: 0x250 */
  __IO uint16_t HWTSWIZZLEHWTADDRESS9;             /**< Signal swizzle selection for HWT swizzle, offset: 0x252 */
  __IO uint16_t HWTSWIZZLEHWTADDRESS10;            /**< Signal swizzle selection for HWT swizzle, offset: 0x254 */
  __IO uint16_t HWTSWIZZLEHWTADDRESS11;            /**< Signal swizzle selection for HWT swizzle, offset: 0x256 */
  __IO uint16_t HWTSWIZZLEHWTADDRESS12;            /**< Signal swizzle selection for HWT swizzle, offset: 0x258 */
  __IO uint16_t HWTSWIZZLEHWTADDRESS13;            /**< Signal swizzle selection for HWT swizzle, offset: 0x25A */
  __IO uint16_t HWTSWIZZLEHWTADDRESS14;            /**< Signal swizzle selection for HWT swizzle, offset: 0x25C */
  __IO uint16_t HWTSWIZZLEHWTADDRESS15;            /**< Signal swizzle selection for HWT swizzle, offset: 0x25E */
  __IO uint16_t HWTSWIZZLEHWTADDRESS17;            /**< Signal swizzle selection for HWT swizzle, offset: 0x260 */
  __IO uint16_t HWTSWIZZLEHWTACTN;                 /**< Signal swizzle selection for HWT swizzle, offset: 0x262 */
  __IO uint16_t HWTSWIZZLEHWTBANK0;                /**< Signal swizzle selection for HWT swizzle, offset: 0x264 */
  __IO uint16_t HWTSWIZZLEHWTBANK1;                /**< Signal swizzle selection for HWT swizzle, offset: 0x266 */
  __IO uint16_t HWTSWIZZLEHWTBANK2;                /**< Signal swizzle selection for HWT swizzle, offset: 0x268 */
  __IO uint16_t HWTSWIZZLEHWTBG0;                  /**< Signal swizzle selection for HWT swizzle, offset: 0x26A */
  __IO uint16_t HWTSWIZZLEHWTBG1;                  /**< Signal swizzle selection for HWT swizzle, offset: 0x26C */
  __IO uint16_t HWTSWIZZLEHWTCASN;                 /**< Signal swizzle selection for HWT swizzle, offset: 0x26E */
  __IO uint16_t HWTSWIZZLEHWTRASN;                 /**< Signal swizzle selection for HWT swizzle, offset: 0x270 */
  __IO uint16_t HWTSWIZZLEHWTWEN;                  /**< Signal swizzle selection for HWT swizzle, offset: 0x272 */
  __IO uint16_t HWTSWIZZLEHWTPARITYIN;             /**< Signal swizzle selection for HWT swizzle, offset: 0x274 */
       uint8_t RESERVED_37[2];
  __IO uint16_t DFIHANDSHAKEDELAYS0;               /**< Add assertion/deassertion delays on handshake signals Logic assumes that dfi signal assertions exceed the programmed delays, offset: 0x278 */
  __IO uint16_t DFIHANDSHAKEDELAYS1;               /**< Add assertion/deassertion delays on handshake signals Logic assumes that dfi signal assertions exceed the programmed delays, offset: 0x27A */
       uint8_t RESERVED_38[2096532];
  __IO uint16_t CALUCLKINFO_P1;                    /**< Impedance Calibration Clock Ratio, offset: 0x200010 */
       uint8_t RESERVED_39[4];
  __IO uint16_t SEQ0BDLY0_P1;                      /**< PHY Initialization Engine (PIE) Delay Register 0, offset: 0x200016 */
  __IO uint16_t SEQ0BDLY1_P1;                      /**< PHY Initialization Engine (PIE) Delay Register 1, offset: 0x200018 */
  __IO uint16_t SEQ0BDLY2_P1;                      /**< PHY Initialization Engine (PIE) Delay Register 2, offset: 0x20001A */
  __IO uint16_t SEQ0BDLY3_P1;                      /**< PHY Initialization Engine (PIE) Delay Register 3, offset: 0x20001C */
       uint8_t RESERVED_40[2];
  __IO uint16_t PPTTRAINSETUP_P1;                  /**< Setup Intervals for DFI PHY Master operations, offset: 0x200020 */
       uint8_t RESERVED_41[16];
  __IO uint16_t TRISTATEMODECA_P1;                 /**< Mode select register for MEMCLK/Address/Command Tristates, offset: 0x200032 */
       uint8_t RESERVED_42[12];
  __IO uint16_t HWTMRL_P1;                         /**< HWT MaxReadLatency., offset: 0x200040 */
       uint8_t RESERVED_43[6];
  __IO uint16_t DQSPREAMBLECONTROL_P1;             /**< Control the PHY logic related to the read and write DQS preamble, offset: 0x200048 */
       uint8_t RESERVED_44[16];
  __IO uint16_t DMIPINPRESENT_P1;                  /**< This Register is used to enable the Read-DBI function in each DBYTE, offset: 0x20005A */
  __IO uint16_t ARDPTRINITVAL_P1;                  /**< Address/Command FIFO ReadPointer Initial Value, offset: 0x20005C */
       uint8_t RESERVED_45[78];
  __IO uint16_t PROCODTTIMECTL_P1;                 /**< READ DATA On-Die Termination Timing Control (by PHY), offset: 0x2000AC */
       uint8_t RESERVED_46[74];
  __IO uint16_t DLLGAINCTL_P1;                     /**< DLL gain control, offset: 0x2000F8 */
       uint8_t RESERVED_47[102];
  __IO uint16_t DFIRDDATACSDESTMAP_P1;             /**< Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM, offset: 0x200160 */
       uint8_t RESERVED_48[2];
  __IO uint16_t VREFINGLOBAL_P1;                   /**< PHY Global Vref Controls, offset: 0x200164 */
       uint8_t RESERVED_49[2];
  __IO uint16_t DFIWRDATACSDESTMAP_P1;             /**< Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM, offset: 0x200168 */
       uint8_t RESERVED_50[32];
  __IO uint16_t PLLCTRL2_P1;                       /**< PState dependent PLL Control Register 2, offset: 0x20018A */
       uint8_t RESERVED_51[2];
  __IO uint16_t PLLCTRL1_P1;                       /**< PState dependent PLL Control Register 1, offset: 0x20018E */
       uint8_t RESERVED_52[4];
  __IO uint16_t PLLTESTMODE_P1;                    /**< Additional controls for PLL CP/VCO modes of operation, offset: 0x200194 */
       uint8_t RESERVED_53[2];
  __IO uint16_t PLLCTRL4_P1;                       /**< PState dependent PLL Control Register 4, offset: 0x200198 */
       uint8_t RESERVED_54[90];
  __IO uint16_t DFIFREQRATIO_P1;                   /**< DFI Frequency Ratio, offset: 0x2001F4 */
       uint8_t RESERVED_55[2096666];
  __IO uint16_t CALUCLKINFO_P2;                    /**< Impedance Calibration Clock Ratio, offset: 0x400010 */
       uint8_t RESERVED_56[4];
  __IO uint16_t SEQ0BDLY0_P2;                      /**< PHY Initialization Engine (PIE) Delay Register 0, offset: 0x400016 */
  __IO uint16_t SEQ0BDLY1_P2;                      /**< PHY Initialization Engine (PIE) Delay Register 1, offset: 0x400018 */
  __IO uint16_t SEQ0BDLY2_P2;                      /**< PHY Initialization Engine (PIE) Delay Register 2, offset: 0x40001A */
  __IO uint16_t SEQ0BDLY3_P2;                      /**< PHY Initialization Engine (PIE) Delay Register 3, offset: 0x40001C */
       uint8_t RESERVED_57[2];
  __IO uint16_t PPTTRAINSETUP_P2;                  /**< Setup Intervals for DFI PHY Master operations, offset: 0x400020 */
       uint8_t RESERVED_58[16];
  __IO uint16_t TRISTATEMODECA_P2;                 /**< Mode select register for MEMCLK/Address/Command Tristates, offset: 0x400032 */
       uint8_t RESERVED_59[12];
  __IO uint16_t HWTMRL_P2;                         /**< HWT MaxReadLatency., offset: 0x400040 */
       uint8_t RESERVED_60[6];
  __IO uint16_t DQSPREAMBLECONTROL_P2;             /**< Control the PHY logic related to the read and write DQS preamble, offset: 0x400048 */
       uint8_t RESERVED_61[16];
  __IO uint16_t DMIPINPRESENT_P2;                  /**< This Register is used to enable the Read-DBI function in each DBYTE, offset: 0x40005A */
  __IO uint16_t ARDPTRINITVAL_P2;                  /**< Address/Command FIFO ReadPointer Initial Value, offset: 0x40005C */
       uint8_t RESERVED_62[78];
  __IO uint16_t PROCODTTIMECTL_P2;                 /**< READ DATA On-Die Termination Timing Control (by PHY), offset: 0x4000AC */
       uint8_t RESERVED_63[74];
  __IO uint16_t DLLGAINCTL_P2;                     /**< DLL gain control, offset: 0x4000F8 */
       uint8_t RESERVED_64[102];
  __IO uint16_t DFIRDDATACSDESTMAP_P2;             /**< Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM, offset: 0x400160 */
       uint8_t RESERVED_65[2];
  __IO uint16_t VREFINGLOBAL_P2;                   /**< PHY Global Vref Controls, offset: 0x400164 */
       uint8_t RESERVED_66[2];
  __IO uint16_t DFIWRDATACSDESTMAP_P2;             /**< Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM, offset: 0x400168 */
       uint8_t RESERVED_67[32];
  __IO uint16_t PLLCTRL2_P2;                       /**< PState dependent PLL Control Register 2, offset: 0x40018A */
       uint8_t RESERVED_68[2];
  __IO uint16_t PLLCTRL1_P2;                       /**< PState dependent PLL Control Register 1, offset: 0x40018E */
       uint8_t RESERVED_69[4];
  __IO uint16_t PLLTESTMODE_P2;                    /**< Additional controls for PLL CP/VCO modes of operation, offset: 0x400194 */
       uint8_t RESERVED_70[2];
  __IO uint16_t PLLCTRL4_P2;                       /**< PState dependent PLL Control Register 4, offset: 0x400198 */
       uint8_t RESERVED_71[90];
  __IO uint16_t DFIFREQRATIO_P2;                   /**< DFI Frequency Ratio, offset: 0x4001F4 */
       uint8_t RESERVED_72[2096666];
  __IO uint16_t CALUCLKINFO_P3;                    /**< Impedance Calibration Clock Ratio, offset: 0x600010 */
       uint8_t RESERVED_73[4];
  __IO uint16_t SEQ0BDLY0_P3;                      /**< PHY Initialization Engine (PIE) Delay Register 0, offset: 0x600016 */
  __IO uint16_t SEQ0BDLY1_P3;                      /**< PHY Initialization Engine (PIE) Delay Register 1, offset: 0x600018 */
  __IO uint16_t SEQ0BDLY2_P3;                      /**< PHY Initialization Engine (PIE) Delay Register 2, offset: 0x60001A */
  __IO uint16_t SEQ0BDLY3_P3;                      /**< PHY Initialization Engine (PIE) Delay Register 3, offset: 0x60001C */
       uint8_t RESERVED_74[2];
  __IO uint16_t PPTTRAINSETUP_P3;                  /**< Setup Intervals for DFI PHY Master operations, offset: 0x600020 */
       uint8_t RESERVED_75[16];
  __IO uint16_t TRISTATEMODECA_P3;                 /**< Mode select register for MEMCLK/Address/Command Tristates, offset: 0x600032 */
       uint8_t RESERVED_76[12];
  __IO uint16_t HWTMRL_P3;                         /**< HWT MaxReadLatency., offset: 0x600040 */
       uint8_t RESERVED_77[6];
  __IO uint16_t DQSPREAMBLECONTROL_P3;             /**< Control the PHY logic related to the read and write DQS preamble, offset: 0x600048 */
       uint8_t RESERVED_78[16];
  __IO uint16_t DMIPINPRESENT_P3;                  /**< This Register is used to enable the Read-DBI function in each DBYTE, offset: 0x60005A */
  __IO uint16_t ARDPTRINITVAL_P3;                  /**< Address/Command FIFO ReadPointer Initial Value, offset: 0x60005C */
       uint8_t RESERVED_79[78];
  __IO uint16_t PROCODTTIMECTL_P3;                 /**< READ DATA On-Die Termination Timing Control (by PHY), offset: 0x6000AC */
       uint8_t RESERVED_80[74];
  __IO uint16_t DLLGAINCTL_P3;                     /**< DLL gain control, offset: 0x6000F8 */
       uint8_t RESERVED_81[102];
  __IO uint16_t DFIRDDATACSDESTMAP_P3;             /**< Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM, offset: 0x600160 */
       uint8_t RESERVED_82[2];
  __IO uint16_t VREFINGLOBAL_P3;                   /**< PHY Global Vref Controls, offset: 0x600164 */
       uint8_t RESERVED_83[2];
  __IO uint16_t DFIWRDATACSDESTMAP_P3;             /**< Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM, offset: 0x600168 */
       uint8_t RESERVED_84[32];
  __IO uint16_t PLLCTRL2_P3;                       /**< PState dependent PLL Control Register 2, offset: 0x60018A */
       uint8_t RESERVED_85[2];
  __IO uint16_t PLLCTRL1_P3;                       /**< PState dependent PLL Control Register 1, offset: 0x60018E */
       uint8_t RESERVED_86[4];
  __IO uint16_t PLLTESTMODE_P3;                    /**< Additional controls for PLL CP/VCO modes of operation, offset: 0x600194 */
       uint8_t RESERVED_87[2];
  __IO uint16_t PLLCTRL4_P3;                       /**< PState dependent PLL Control Register 4, offset: 0x600198 */
       uint8_t RESERVED_88[90];
  __IO uint16_t DFIFREQRATIO_P3;                   /**< DFI Frequency Ratio, offset: 0x6001F4 */
} DWC_DDRPHYA_MASTER_Type;

/* ----------------------------------------------------------------------------
   -- DWC_DDRPHYA_MASTER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_MASTER_Register_Masks DWC_DDRPHYA_MASTER Register Masks
 * @{
 */

/*! @name RXFIFOINIT - Rx FIFO pointer initialization control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_RXFIFOINIT_RxFifoInitPtr_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_RXFIFOINIT_RxFifoInitPtr_SHIFT (0U)
/*! RxFifoInitPtr - Setting this bit will reset the PHY RXDATAFIFO read and write pointers. */
#define DWC_DDRPHYA_MASTER_RXFIFOINIT_RxFifoInitPtr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_RXFIFOINIT_RxFifoInitPtr_SHIFT)) & DWC_DDRPHYA_MASTER_RXFIFOINIT_RxFifoInitPtr_MASK)

#define DWC_DDRPHYA_MASTER_RXFIFOINIT_InhibitRxFifoRd_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_RXFIFOINIT_InhibitRxFifoRd_SHIFT (1U)
/*! InhibitRxFifoRd - This field is reserved for training FW use. */
#define DWC_DDRPHYA_MASTER_RXFIFOINIT_InhibitRxFifoRd(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_RXFIFOINIT_InhibitRxFifoRd_SHIFT)) & DWC_DDRPHYA_MASTER_RXFIFOINIT_InhibitRxFifoRd_MASK)
/*! @} */

/*! @name FORCECLKDISABLE - Clock gating control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_FORCECLKDISABLE_ForceClkDisable_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_FORCECLKDISABLE_ForceClkDisable_SHIFT (0U)
/*! ForceClkDisable - This CSR forces the gating of MEMCLKs driven from the PHY ForceClkDisable[0] -
 *    controls CLK_H/L0 ForceClkDisable[1] - controls CLK_H/L1 (if present) ForceClkDisable[2] -
 *    controls CLK_H/L2 (if present) ForceClkDisable[3] - controls CLK_H/L3 (if present)
 */
#define DWC_DDRPHYA_MASTER_FORCECLKDISABLE_ForceClkDisable(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_FORCECLKDISABLE_ForceClkDisable_SHIFT)) & DWC_DDRPHYA_MASTER_FORCECLKDISABLE_ForceClkDisable_MASK)
/*! @} */

/*! @name FORCEINTERNALUPDATE - This Register used by Training Firmware to force an internal PHY Update Event. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_FORCEINTERNALUPDATE_ForceInternalUpdate_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_FORCEINTERNALUPDATE_ForceInternalUpdate_SHIFT (0U)
/*! ForceInternalUpdate - This Register is used by Training Firmware to force an internal PHY Update Event. */
#define DWC_DDRPHYA_MASTER_FORCEINTERNALUPDATE_ForceInternalUpdate(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_FORCEINTERNALUPDATE_ForceInternalUpdate_SHIFT)) & DWC_DDRPHYA_MASTER_FORCEINTERNALUPDATE_ForceInternalUpdate_MASK)
/*! @} */

/*! @name PHYCONFIG - Read Only displays PHY Configuration. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigAnibs_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigAnibs_SHIFT (0U)
/*! PhyConfigAnibs - Returns the following value . */
#define DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigAnibs(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigAnibs_SHIFT)) & DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigAnibs_MASK)

#define DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigDbytes_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigDbytes_SHIFT (4U)
/*! PhyConfigDbytes - Returns the following value . */
#define DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigDbytes(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigDbytes_SHIFT)) & DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigDbytes_MASK)

#define DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigDfi_MASK (0x300U)
#define DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigDfi_SHIFT (8U)
/*! PhyConfigDfi - Returns the following value . */
#define DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigDfi_SHIFT)) & DWC_DDRPHYA_MASTER_PHYCONFIG_PhyConfigDfi_MASK)
/*! @} */

/*! @name PGCR - PHY General Configuration Register(PGCR). */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PGCR_RxClkRiseFallMode_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PGCR_RxClkRiseFallMode_SHIFT (0U)
/*! RxClkRiseFallMode - This register field controls independent training for RxClk_c and RxClk_t. */
#define DWC_DDRPHYA_MASTER_PGCR_RxClkRiseFallMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PGCR_RxClkRiseFallMode_SHIFT)) & DWC_DDRPHYA_MASTER_PGCR_RxClkRiseFallMode_MASK)
/*! @} */

/*! @name TESTBUMPCNTRL1 - Test Bump Control1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestMajorMode_MASK (0x7U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestMajorMode_SHIFT (0U)
/*! TestMajorMode - Selects the major mode of operation for the receiver. */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestMajorMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestMajorMode_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestMajorMode_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestBiasBypassEn_MASK (0x8U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestBiasBypassEn_SHIFT (3U)
/*! TestBiasBypassEn - Do not use, for debug only */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestBiasBypassEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestBiasBypassEn_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestBiasBypassEn_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestAnalogOutCtrl_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestAnalogOutCtrl_SHIFT (4U)
/*! TestAnalogOutCtrl - Select receiver internal analog signals to monitor at analog test point
 *    0xxx: AnalogTestOut=HiZ 1000: AnalogTestOut=VSS 1001: AnalogTestOut=vref_dfe0 -- observe by
 *    sweeping MALERTVrefLevel 1010: AnalogTestOut=vref_dfe1 -- observe by sweeping MALERTVrefLevel 1011:
 *    AnalogTestOut=VSS 1100: AnalogTestOut=vstg2 1101: AnalogTestOut=vcasc_cs1 1110:
 *    AnalogTestOut=vbias_cs1 Recommended mission mode default = 4'b0000
 */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestAnalogOutCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestAnalogOutCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestAnalogOutCtrl_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestGainCurrAdj_MASK (0x1F00U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestGainCurrAdj_SHIFT (8U)
/*! TestGainCurrAdj - Adjust gain and current of analog observe RX amplifier stage at analog test
 *    point Recommended mission mode default = 5'b01011
 */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestGainCurrAdj(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestGainCurrAdj_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestGainCurrAdj_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestSelExternalVref_MASK (0x2000U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestSelExternalVref_SHIFT (13U)
/*! TestSelExternalVref - Do not use, for debug only */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestSelExternalVref(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestSelExternalVref_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestSelExternalVref_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestExtVrefRange_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestExtVrefRange_SHIFT (14U)
/*! TestExtVrefRange - Setting this bit will extend the VREF DAC range for debug. */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestExtVrefRange(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestExtVrefRange_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestExtVrefRange_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestPowerGateEn_MASK (0x8000U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestPowerGateEn_SHIFT (15U)
/*! TestPowerGateEn - Do not use, for debug only */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestPowerGateEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestPowerGateEn_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TestPowerGateEn_MASK)
/*! @} */

/*! @name CALUCLKINFO_P0 - Impedance Calibration Clock Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P0_CalUClkTicksPer1uS_MASK (0x3FFU)
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P0_CalUClkTicksPer1uS_SHIFT (0U)
/*! CalUClkTicksPer1uS - Must be programmed to the number of DfiClks in 1us (rounded up), with minimum value of 24. */
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P0_CalUClkTicksPer1uS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALUCLKINFO_P0_CalUClkTicksPer1uS_SHIFT)) & DWC_DDRPHYA_MASTER_CALUCLKINFO_P0_CalUClkTicksPer1uS_MASK)
/*! @} */

/*! @name TESTBUMPCNTRL - Test Bump Control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpEn_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpEn_SHIFT (0U)
/*! TestBumpEn - Field TestBumpEn[1:0] controls the output function of: the signal BP_ALERT_N. */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpEn_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpEn_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpToggle_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpToggle_SHIFT (2U)
/*! TestBumpToggle - This field controls the output function of the signal Digital Observation Pin,
 *    if available in the configuration of the PHY.
 */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpToggle(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpToggle_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpToggle_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpDataSel_MASK (0x1F8U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpDataSel_SHIFT (3U)
/*! TestBumpDataSel - RVSD. */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpDataSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpDataSel_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TestBumpDataSel_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_ForceMtestOnAlert_MASK (0x200U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_ForceMtestOnAlert_SHIFT (9U)
/*! ForceMtestOnAlert - When set, causes the Digital Observation output pin to be driven onto BP_ALERT_N */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_ForceMtestOnAlert(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_ForceMtestOnAlert_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_ForceMtestOnAlert_MASK)
/*! @} */

/*! @name SEQ0BDLY0_P0 - PHY Initialization Engine (PIE) Delay Register 0 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P0_Seq0BDLY0_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P0_Seq0BDLY0_p0_SHIFT (0U)
/*! Seq0BDLY0_p0 - PHY Initialization Engine (PIE) Delay Register 0 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P0_Seq0BDLY0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY0_P0_Seq0BDLY0_p0_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY0_P0_Seq0BDLY0_p0_MASK)
/*! @} */

/*! @name SEQ0BDLY1_P0 - PHY Initialization Engine (PIE) Delay Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P0_Seq0BDLY1_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P0_Seq0BDLY1_p0_SHIFT (0U)
/*! Seq0BDLY1_p0 - PHY Initialization Engine (PIE) Delay Register 1 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P0_Seq0BDLY1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY1_P0_Seq0BDLY1_p0_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY1_P0_Seq0BDLY1_p0_MASK)
/*! @} */

/*! @name SEQ0BDLY2_P0 - PHY Initialization Engine (PIE) Delay Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P0_Seq0BDLY2_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P0_Seq0BDLY2_p0_SHIFT (0U)
/*! Seq0BDLY2_p0 - PHY Initialization Engine (PIE) Delay Register 2 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P0_Seq0BDLY2_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY2_P0_Seq0BDLY2_p0_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY2_P0_Seq0BDLY2_p0_MASK)
/*! @} */

/*! @name SEQ0BDLY3_P0 - PHY Initialization Engine (PIE) Delay Register 3 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P0_Seq0BDLY3_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P0_Seq0BDLY3_p0_SHIFT (0U)
/*! Seq0BDLY3_p0 - PHY Initialization Engine (PIE) Delay Register 3 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P0_Seq0BDLY3_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY3_P0_Seq0BDLY3_p0_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY3_P0_Seq0BDLY3_p0_MASK)
/*! @} */

/*! @name PHYALERTSTATUS - PHY Alert status bit */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYALERTSTATUS_PhyAlert_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PHYALERTSTATUS_PhyAlert_SHIFT (0U)
/*! PhyAlert - Current state of ALERT_N. */
#define DWC_DDRPHYA_MASTER_PHYALERTSTATUS_PhyAlert(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYALERTSTATUS_PhyAlert_SHIFT)) & DWC_DDRPHYA_MASTER_PHYALERTSTATUS_PhyAlert_MASK)
/*! @} */

/*! @name PPTTRAINSETUP_P0 - Setup Intervals for DFI PHY Master operations */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PhyMstrTrainInterval_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PhyMstrTrainInterval_SHIFT (0U)
/*! PhyMstrTrainInterval - Bits 3:0 of this register specifies the time between the end of one training and the start of the next. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PhyMstrTrainInterval(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PhyMstrTrainInterval_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PhyMstrTrainInterval_MASK)

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PhyMstrMaxReqToAck_MASK (0x70U)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PhyMstrMaxReqToAck_SHIFT (4U)
/*! PhyMstrMaxReqToAck - Bits 6:4 of this register specify the max time from tdfi_phymstr_req asserted to tdfi_phymstr_ack asserted. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PhyMstrMaxReqToAck(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PhyMstrMaxReqToAck_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PhyMstrMaxReqToAck_MASK)
/*! @} */

/*! @name ATESTMODE - ATestMode control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ATESTMODE_ATestPrbsEn_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_ATESTMODE_ATestPrbsEn_SHIFT (0U)
/*! ATestPrbsEn - Enables loopback PRBS7 testing of all the DDR output pins in this chiplet. */
#define DWC_DDRPHYA_MASTER_ATESTMODE_ATestPrbsEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ATESTMODE_ATestPrbsEn_SHIFT)) & DWC_DDRPHYA_MASTER_ATESTMODE_ATestPrbsEn_MASK)

#define DWC_DDRPHYA_MASTER_ATESTMODE_ATestClkEn_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_ATESTMODE_ATestClkEn_SHIFT (1U)
/*! ATestClkEn - Enables the clock for loopback PRBS7 testing for all BP_A* pins. */
#define DWC_DDRPHYA_MASTER_ATESTMODE_ATestClkEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ATESTMODE_ATestClkEn_SHIFT)) & DWC_DDRPHYA_MASTER_ATESTMODE_ATestClkEn_MASK)

#define DWC_DDRPHYA_MASTER_ATESTMODE_ATestModeSel_MASK (0x1CU)
#define DWC_DDRPHYA_MASTER_ATESTMODE_ATestModeSel_SHIFT (2U)
/*! ATestModeSel - Master Mode select for ATest (Loopback) 000 - Mission mode, all ATest disabled,
 *    loopback receivers powered down 001 - External Loopback mode [Single data rate pattern -
 *    dfi_cas sent to all lanes] 010 - Internal Loopback mode [Single data rate pattern] 011 - Internal
 *    Loopback mode [Double data rate pattern] 100 - External Loopback mode [Single data rate pattern
 *    - corresponding DFI signal sent to each lane]
 */
#define DWC_DDRPHYA_MASTER_ATESTMODE_ATestModeSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ATESTMODE_ATestModeSel_SHIFT)) & DWC_DDRPHYA_MASTER_ATESTMODE_ATestModeSel_MASK)
/*! @} */

/*! @name TXCALBINP - TX P Impedance Calibration observation */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TXCALBINP_TxCalBinP_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_TXCALBINP_TxCalBinP_SHIFT (0U)
/*! TxCalBinP - This csr holds the binary result of the 31 bit thermometer pullup code. */
#define DWC_DDRPHYA_MASTER_TXCALBINP_TxCalBinP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TXCALBINP_TxCalBinP_SHIFT)) & DWC_DDRPHYA_MASTER_TXCALBINP_TxCalBinP_MASK)
/*! @} */

/*! @name TXCALBINN - TX N Impedance Calibration observation */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TXCALBINN_TxCalBinN_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_TXCALBINN_TxCalBinN_SHIFT (0U)
/*! TxCalBinN - This csr holds the binary result of the 31 bit thermometer pulldown code. */
#define DWC_DDRPHYA_MASTER_TXCALBINN_TxCalBinN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TXCALBINN_TxCalBinN_SHIFT)) & DWC_DDRPHYA_MASTER_TXCALBINN_TxCalBinN_MASK)
/*! @} */

/*! @name TXCALPOVR - TX P Impedance Calibration override */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TXCALPOVR_TxCalBinPOvrVal_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_TXCALPOVR_TxCalBinPOvrVal_SHIFT (0U)
/*! TxCalBinPOvrVal - The binary value which can overide the Register TxCalBinP calibrator results if Register TxCalBinPOvrEn is set. */
#define DWC_DDRPHYA_MASTER_TXCALPOVR_TxCalBinPOvrVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TXCALPOVR_TxCalBinPOvrVal_SHIFT)) & DWC_DDRPHYA_MASTER_TXCALPOVR_TxCalBinPOvrVal_MASK)

#define DWC_DDRPHYA_MASTER_TXCALPOVR_TxCalBinPOvrEn_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_TXCALPOVR_TxCalBinPOvrEn_SHIFT (5U)
/*! TxCalBinPOvrEn - 1 = use the override value present in Register TxCalBinPOvrVal 0 = don't. */
#define DWC_DDRPHYA_MASTER_TXCALPOVR_TxCalBinPOvrEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TXCALPOVR_TxCalBinPOvrEn_SHIFT)) & DWC_DDRPHYA_MASTER_TXCALPOVR_TxCalBinPOvrEn_MASK)
/*! @} */

/*! @name TXCALNOVR - TX N Impedance Calibration override */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TXCALNOVR_TxCalBinNOvrVal_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_TXCALNOVR_TxCalBinNOvrVal_SHIFT (0U)
/*! TxCalBinNOvrVal - The binary value which can overide the Register TxCalBinN calibrator results if Register TxCalBinPOvrEn is set. */
#define DWC_DDRPHYA_MASTER_TXCALNOVR_TxCalBinNOvrVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TXCALNOVR_TxCalBinNOvrVal_SHIFT)) & DWC_DDRPHYA_MASTER_TXCALNOVR_TxCalBinNOvrVal_MASK)

#define DWC_DDRPHYA_MASTER_TXCALNOVR_TxCalBinNOvrEn_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_TXCALNOVR_TxCalBinNOvrEn_SHIFT (5U)
/*! TxCalBinNOvrEn - 1 = use the override value present in Register TxCalBinNOvrVal 0 = don't. */
#define DWC_DDRPHYA_MASTER_TXCALNOVR_TxCalBinNOvrEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TXCALNOVR_TxCalBinNOvrEn_SHIFT)) & DWC_DDRPHYA_MASTER_TXCALNOVR_TxCalBinNOvrEn_MASK)
/*! @} */

/*! @name DFIMODE - Enables for update and low-power interfaces for DFI0 and DFI1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIMODE_Dfi0Enable_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DFIMODE_Dfi0Enable_SHIFT (0U)
/*! Dfi0Enable - Enables operation for the PHY logic associated with DFI0 */
#define DWC_DDRPHYA_MASTER_DFIMODE_Dfi0Enable(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIMODE_Dfi0Enable_SHIFT)) & DWC_DDRPHYA_MASTER_DFIMODE_Dfi0Enable_MASK)

#define DWC_DDRPHYA_MASTER_DFIMODE_Dfi1Enable_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DFIMODE_Dfi1Enable_SHIFT (1U)
/*! Dfi1Enable - Enables operation for the PHY logic associated with DFI1 */
#define DWC_DDRPHYA_MASTER_DFIMODE_Dfi1Enable(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIMODE_Dfi1Enable_SHIFT)) & DWC_DDRPHYA_MASTER_DFIMODE_Dfi1Enable_MASK)

#define DWC_DDRPHYA_MASTER_DFIMODE_Dfi1Override_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_DFIMODE_Dfi1Override_SHIFT (2U)
/*! Dfi1Override - DFI0 is used to control the PHY logic associated with both DFI0 and DFI1 */
#define DWC_DDRPHYA_MASTER_DFIMODE_Dfi1Override(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIMODE_Dfi1Override_SHIFT)) & DWC_DDRPHYA_MASTER_DFIMODE_Dfi1Override_MASK)
/*! @} */

/*! @name TRISTATEMODECA_P0 - Mode select register for MEMCLK/Address/Command Tristates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DisDynAdrTri_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DisDynAdrTri_SHIFT (0U)
/*! DisDynAdrTri - When DisDynAdrTri=1, Dynamic Tristating is disabled. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DisDynAdrTri(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DisDynAdrTri_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DisDynAdrTri_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DDR2TMode_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DDR2TMode_SHIFT (1U)
/*! DDR2TMode - Must be set to 1 for Dynamic Tristate to work when CA bus is 2T or Geardown mode. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DDR2TMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DDR2TMode_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DDR2TMode_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_CkDisVal_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_CkDisVal_SHIFT (2U)
/*! CkDisVal - The PHY provides 4 memory clocks, n=0. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_CkDisVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_CkDisVal_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_CkDisVal_MASK)
/*! @} */

/*! @name MTESTMUXSEL - Digital Observation Pin control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MTESTMUXSEL_MtestMuxSel_MASK (0x3FU)
#define DWC_DDRPHYA_MASTER_MTESTMUXSEL_MtestMuxSel_SHIFT (0U)
/*! MtestMuxSel - Controls for the 64-1 mux for asynchronous data to the Digital Observation Pin. */
#define DWC_DDRPHYA_MASTER_MTESTMUXSEL_MtestMuxSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MTESTMUXSEL_MtestMuxSel_SHIFT)) & DWC_DDRPHYA_MASTER_MTESTMUXSEL_MtestMuxSel_MASK)
/*! @} */

/*! @name MTESTPGMINFO - Digital Observation Pin program info for debug */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MTESTPGMINFO_MtestPgmInfo_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_MTESTPGMINFO_MtestPgmInfo_SHIFT (0U)
/*! MtestPgmInfo - The value of this csr may be driven onto the Digital Observation Pin. */
#define DWC_DDRPHYA_MASTER_MTESTPGMINFO_MtestPgmInfo(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MTESTPGMINFO_MtestPgmInfo_SHIFT)) & DWC_DDRPHYA_MASTER_MTESTPGMINFO_MtestPgmInfo_MASK)
/*! @} */

/*! @name DYNPWRDNUP - Dynaimc Power Up/Down control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DYNPWRDNUP_DynPowerDown_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DYNPWRDNUP_DynPowerDown_SHIFT (0U)
/*! DynPowerDown - 1 - analog circuitry (voltage dacs, bias gen) is turned off. */
#define DWC_DDRPHYA_MASTER_DYNPWRDNUP_DynPowerDown(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DYNPWRDNUP_DynPowerDown_SHIFT)) & DWC_DDRPHYA_MASTER_DYNPWRDNUP_DynPowerDown_MASK)
/*! @} */

/*! @name PHYTID - PHY Technology ID Register */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYTID_PhyTID_MASK    (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PHYTID_PhyTID_SHIFT   (0U)
/*! PhyTID - This register is a placeholder to store technology-specific information */
#define DWC_DDRPHYA_MASTER_PHYTID_PhyTID(x)      (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYTID_PhyTID_SHIFT)) & DWC_DDRPHYA_MASTER_PHYTID_PhyTID_MASK)
/*! @} */

/*! @name HWTMRL_P0 - HWT MaxReadLatency. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTMRL_P0_HwtMRL_p0_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTMRL_P0_HwtMRL_p0_SHIFT (0U)
/*! HwtMRL_p0 - This Max Read Latency CSR is to be trained to ensure the rx-data fifo is not read
 *    until after all dbytes have their read data valid.
 */
#define DWC_DDRPHYA_MASTER_HWTMRL_P0_HwtMRL_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTMRL_P0_HwtMRL_p0_SHIFT)) & DWC_DDRPHYA_MASTER_HWTMRL_P0_HwtMRL_p0_MASK)
/*! @} */

/*! @name DFIPHYUPD - DFI PhyUpdate Request time counter (in MEMCLKs) */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDCNT_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDCNT_SHIFT (0U)
/*! DFIPHYUPDCNT - This controls the interval between the end of a phyupdate transaction and a subsequent request. */
#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDCNT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDCNT_SHIFT)) & DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDCNT_MASK)

#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDRESP_MASK (0x70U)
#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDRESP_SHIFT (4U)
/*! DFIPHYUPDRESP - Enforces the t_phyupd_resp time, the maximum time that is allowed to controller
 *    to respond to the request for a PHY update.
 */
#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDRESP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDRESP_SHIFT)) & DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDRESP_MASK)

#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDMODE_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDMODE_SHIFT (7U)
/*! DFIPHYUPDMODE - 1'b0 [Default] deterministic timer-based Phy Update Requests; enables multi-channel/multi-phy lockstep operation. */
#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDMODE_SHIFT)) & DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDMODE_MASK)

#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDTHRESHOLD_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDTHRESHOLD_SHIFT (8U)
/*! DFIPHYUPDTHRESHOLD - 4'h0 Disable Threshold-based Phy Update Requests when DFIPHYUPDMODE==1'b1
 *    Nonzero codes are the threshold value for the change in the master LCDL 1UI phase code since
 *    the last Phy Update Request that will trigger a new Phy Update Request; If (current_1UI_phase -
 *    last_1UI_phase) > DFIPHYUPDTHRESHOLD, then a Phy Update will be requested.
 */
#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDTHRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDTHRESHOLD_SHIFT)) & DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDTHRESHOLD_MASK)

#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDINTTHRESHOLD_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDINTTHRESHOLD_SHIFT (12U)
/*! DFIPHYUPDINTTHRESHOLD - This subfield is similar to DFIPHYUPDTHRESHOLD except that rather than
 *    affecting the Phy Update request, it affects only the threshold used to generate the VT Drift
 *    Alarm Interrupt.
 */
#define DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDINTTHRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDINTTHRESHOLD_SHIFT)) & DWC_DDRPHYA_MASTER_DFIPHYUPD_DFIPHYUPDINTTHRESHOLD_MASK)
/*! @} */

/*! @name PDAMRSWRITEMODE - Controls the write DQ generation for Per-Dram-Addressing of MRS */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PDAMRSWRITEMODE_PdaMrsWriteMode_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PDAMRSWRITEMODE_PdaMrsWriteMode_SHIFT (0U)
/*! PdaMrsWriteMode - Controls the write DQ generation per the timing requirements on the DQ signals
 *    used for Per-Dram-Addressing mode of MRS commands.
 */
#define DWC_DDRPHYA_MASTER_PDAMRSWRITEMODE_PdaMrsWriteMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PDAMRSWRITEMODE_PdaMrsWriteMode_SHIFT)) & DWC_DDRPHYA_MASTER_PDAMRSWRITEMODE_PdaMrsWriteMode_MASK)
/*! @} */

/*! @name DFIGEARDOWNCTL - Controls whether dfi_geardown_en will cause CS and CKE timing to change. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIGEARDOWNCTL_DFIGEARDOWNCTL_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIGEARDOWNCTL_DFIGEARDOWNCTL_SHIFT (0U)
/*! DFIGEARDOWNCTL - DFIGEARDOWNCTL[0] controls whether dfi_geardown_en will cause chip-select (CS) timing to change. */
#define DWC_DDRPHYA_MASTER_DFIGEARDOWNCTL_DFIGEARDOWNCTL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIGEARDOWNCTL_DFIGEARDOWNCTL_SHIFT)) & DWC_DDRPHYA_MASTER_DFIGEARDOWNCTL_DFIGEARDOWNCTL_MASK)
/*! @} */

/*! @name DQSPREAMBLECONTROL_P0 - Control the PHY logic related to the read and write DQS preamble */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TwoTckRxDqsPre_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TwoTckRxDqsPre_SHIFT (0U)
/*! TwoTckRxDqsPre - Widens the RxDqsEn window to allow larger drift in the incoming read DQS to
 *    take advantage of the larger/wider preamble generated by the DRAMSs when the D4 DRAMS are
 *    configured with DDR4 MR4 A11 Read Preamble=1 for causing a 2nCK read preamble.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TwoTckRxDqsPre(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TwoTckRxDqsPre_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TwoTckRxDqsPre_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TwoTckTxDqsPre_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TwoTckTxDqsPre_SHIFT (1U)
/*! TwoTckTxDqsPre - 0: Standard 1tck TxDqs Preamble 1: Enable Optional D4 2tck TxDqs Preamble The
 *    DDR4 MR4 A12 is Write Preamble, 1=2nCK, 0=1nCK.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TwoTckTxDqsPre(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TwoTckTxDqsPre_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TwoTckTxDqsPre_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_PositionDfeInit_MASK (0x1CU)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_PositionDfeInit_SHIFT (2U)
/*! PositionDfeInit - For DDR4 phy only when receive DFE is enabled. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_PositionDfeInit(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_PositionDfeInit_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_PositionDfeInit_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4TglTwoTckTxDqsPre_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4TglTwoTckTxDqsPre_SHIFT (5U)
/*! LP4TglTwoTckTxDqsPre - Used in LPDDR4 mode to modify the early preamble when Register
 *    TwoTckTxDqsPre=1 0: level first-memclk preamble 1: toggling first-memclk preamble
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4TglTwoTckTxDqsPre(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4TglTwoTckTxDqsPre_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4TglTwoTckTxDqsPre_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4PostambleExt_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4PostambleExt_SHIFT (6U)
/*! LP4PostambleExt - In LPDDR4 mode must be set to extend the write postamble. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4PostambleExt(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4PostambleExt_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4PostambleExt_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4SttcPreBridgeRxEn_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4SttcPreBridgeRxEn_SHIFT (7U)
/*! LP4SttcPreBridgeRxEn - Used in LPDDR4 static-preamble mode to bridge the RxEn between two reads
 *    to the same timing group when the bubble is 1 memclk.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4SttcPreBridgeRxEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4SttcPreBridgeRxEn_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4SttcPreBridgeRxEn_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_WDQSEXTENSION_MASK (0x100U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_WDQSEXTENSION_SHIFT (8U)
/*! WDQSEXTENSION - When set, DQS_T and DQS_C will be driven differentially to 0 and 1,
 *    respectively, before and after a write burst, except during a memory read transaction.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_WDQSEXTENSION(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_WDQSEXTENSION_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_WDQSEXTENSION_MASK)
/*! @} */

/*! @name MASTERX4CONFIG - DBYTE module controls to select X4 Dram device mode */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MASTERX4CONFIG_X4TG_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MASTERX4CONFIG_X4TG_SHIFT (0U)
/*! X4TG - Set to 1 if this Timing Group/Rank is x4 (as opposed to x8) memory. */
#define DWC_DDRPHYA_MASTER_MASTERX4CONFIG_X4TG(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MASTERX4CONFIG_X4TG_SHIFT)) & DWC_DDRPHYA_MASTER_MASTERX4CONFIG_X4TG_MASK)
/*! @} */

/*! @name WRLEVBITS - Write level feedback DQ observability select. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_WRLEVBITS_WrLevForDQSL_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_WRLEVBITS_WrLevForDQSL_SHIFT (0U)
/*! WrLevForDQSL - Indicates which DQ bit is used for Write Levelization. */
#define DWC_DDRPHYA_MASTER_WRLEVBITS_WrLevForDQSL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_WRLEVBITS_WrLevForDQSL_SHIFT)) & DWC_DDRPHYA_MASTER_WRLEVBITS_WrLevForDQSL_MASK)

#define DWC_DDRPHYA_MASTER_WRLEVBITS_WrLevForDQSU_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_WRLEVBITS_WrLevForDQSU_SHIFT (4U)
/*! WrLevForDQSU - Indicates which DQ bit is used for Write Levelization. */
#define DWC_DDRPHYA_MASTER_WRLEVBITS_WrLevForDQSU(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_WRLEVBITS_WrLevForDQSU_SHIFT)) & DWC_DDRPHYA_MASTER_WRLEVBITS_WrLevForDQSU_MASK)
/*! @} */

/*! @name ENABLECSMULTICAST - In DDR4 Mode , this controls whether CS_N[3:2] should be multicast on CID[1:0] */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ENABLECSMULTICAST_EnableCsMulticast_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_ENABLECSMULTICAST_EnableCsMulticast_SHIFT (0U)
/*! EnableCsMulticast - In DDR4 Mode , this controls whether CS_N[3:2] should be multicast on
 *    CID[1:0] 0 - Do not override pins corresponding to cid[1:0] (dfi_cid[1:0] will connect to the pads)
 *    1 - Overrirde pins corresponding to cid[1:0] with dfi_cs[3:2].
 */
#define DWC_DDRPHYA_MASTER_ENABLECSMULTICAST_EnableCsMulticast(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ENABLECSMULTICAST_EnableCsMulticast_SHIFT)) & DWC_DDRPHYA_MASTER_ENABLECSMULTICAST_EnableCsMulticast_MASK)
/*! @} */

/*! @name HWTLPCSMULTICAST - Drives cs_n[0] onto cs_n[1] during training */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTLPCSMULTICAST_HwtLpCsMultiCast_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_HWTLPCSMULTICAST_HwtLpCsMultiCast_SHIFT (0U)
/*! HwtLpCsMultiCast - When set, drives cs_n[0] onto cs_n[1] during training */
#define DWC_DDRPHYA_MASTER_HWTLPCSMULTICAST_HwtLpCsMultiCast(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTLPCSMULTICAST_HwtLpCsMultiCast_SHIFT)) & DWC_DDRPHYA_MASTER_HWTLPCSMULTICAST_HwtLpCsMultiCast_MASK)
/*! @} */

/*! @name ACX4ANIBDIS - Disable for unused ACX Nibbles */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ACX4ANIBDIS_Acx4AnibDis_MASK (0xFFFU)
#define DWC_DDRPHYA_MASTER_ACX4ANIBDIS_Acx4AnibDis_SHIFT (0U)
/*! Acx4AnibDis - When a bit is set, the corresponding ACX nibble is disabled (specifically, the I/O
 *    OE is disabled, as is the Dfi-side FIFO clock
 */
#define DWC_DDRPHYA_MASTER_ACX4ANIBDIS_Acx4AnibDis(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ACX4ANIBDIS_Acx4AnibDis_SHIFT)) & DWC_DDRPHYA_MASTER_ACX4ANIBDIS_Acx4AnibDis_MASK)
/*! @} */

/*! @name DMIPINPRESENT_P0 - This Register is used to enable the Read-DBI function in each DBYTE */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P0_RdDbiEnabled_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P0_RdDbiEnabled_SHIFT (0U)
/*! RdDbiEnabled - This bit must be set to 1'b1 if Read-DBI is enabled in a connected DDR4 or LPDDR4 device. */
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P0_RdDbiEnabled(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DMIPINPRESENT_P0_RdDbiEnabled_SHIFT)) & DWC_DDRPHYA_MASTER_DMIPINPRESENT_P0_RdDbiEnabled_MASK)
/*! @} */

/*! @name ARDPTRINITVAL_P0 - Address/Command FIFO ReadPointer Initial Value */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P0_ARdPtrInitVal_p0_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P0_ARdPtrInitVal_p0_SHIFT (0U)
/*! ARdPtrInitVal_p0 - This is the initial Pointer Offset for the free-running FIFOs in the DBYTE and ACX4 hardips. */
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P0_ARdPtrInitVal_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P0_ARdPtrInitVal_p0_SHIFT)) & DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P0_ARdPtrInitVal_p0_MASK)
/*! @} */

/*! @name DBYTEDLLMODECNTRL - DLL Mode control CSR for DBYTEs */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DBYTEDLLMODECNTRL_DllRxPreambleMode_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DBYTEDLLMODECNTRL_DllRxPreambleMode_SHIFT (1U)
/*! DllRxPreambleMode - Must be set to 1 if read DQS preamble contains a toggle, for example DDR4 or LPDDR4 read toggling preambe mode */
#define DWC_DDRPHYA_MASTER_DBYTEDLLMODECNTRL_DllRxPreambleMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DBYTEDLLMODECNTRL_DllRxPreambleMode_SHIFT)) & DWC_DDRPHYA_MASTER_DBYTEDLLMODECNTRL_DllRxPreambleMode_MASK)
/*! @} */

/*! @name CALOFFSETS - Impedance Calibration offsets control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALOFFSETS_CalCmpr5Offset_MASK (0x3FU)
#define DWC_DDRPHYA_MASTER_CALOFFSETS_CalCmpr5Offset_SHIFT (0U)
/*! CalCmpr5Offset - This value adjusts the offset-compensated DAC code for the cmpana circuit at VRef == 0. */
#define DWC_DDRPHYA_MASTER_CALOFFSETS_CalCmpr5Offset(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALOFFSETS_CalCmpr5Offset_SHIFT)) & DWC_DDRPHYA_MASTER_CALOFFSETS_CalCmpr5Offset_MASK)

#define DWC_DDRPHYA_MASTER_CALOFFSETS_CalDrvPdThOffset_MASK (0x3C0U)
#define DWC_DDRPHYA_MASTER_CALOFFSETS_CalDrvPdThOffset_SHIFT (6U)
/*! CalDrvPdThOffset - This value adjusts the driver pulldown calibration code */
#define DWC_DDRPHYA_MASTER_CALOFFSETS_CalDrvPdThOffset(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALOFFSETS_CalDrvPdThOffset_SHIFT)) & DWC_DDRPHYA_MASTER_CALOFFSETS_CalDrvPdThOffset_MASK)

#define DWC_DDRPHYA_MASTER_CALOFFSETS_CalDrvPuThOffset_MASK (0x3C00U)
#define DWC_DDRPHYA_MASTER_CALOFFSETS_CalDrvPuThOffset_SHIFT (10U)
/*! CalDrvPuThOffset - This value adjusts the driver pullup calibration code */
#define DWC_DDRPHYA_MASTER_CALOFFSETS_CalDrvPuThOffset(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALOFFSETS_CalDrvPuThOffset_SHIFT)) & DWC_DDRPHYA_MASTER_CALOFFSETS_CalDrvPuThOffset_MASK)
/*! @} */

/*! @name SARINITVALS - Sar Init Vals */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SARINITVALS_SarInitOFFSET05_MASK (0x7U)
#define DWC_DDRPHYA_MASTER_SARINITVALS_SarInitOFFSET05_SHIFT (0U)
/*! SarInitOFFSET05 - Specify the SAR starting value for OFFSET05 calibration. */
#define DWC_DDRPHYA_MASTER_SARINITVALS_SarInitOFFSET05(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SARINITVALS_SarInitOFFSET05_SHIFT)) & DWC_DDRPHYA_MASTER_SARINITVALS_SarInitOFFSET05_MASK)

#define DWC_DDRPHYA_MASTER_SARINITVALS_SarInitNINT_MASK (0x38U)
#define DWC_DDRPHYA_MASTER_SARINITVALS_SarInitNINT_SHIFT (3U)
/*! SarInitNINT - Specify the SAR starting value for NINT calibration. */
#define DWC_DDRPHYA_MASTER_SARINITVALS_SarInitNINT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SARINITVALS_SarInitNINT_SHIFT)) & DWC_DDRPHYA_MASTER_SARINITVALS_SarInitNINT_MASK)

#define DWC_DDRPHYA_MASTER_SARINITVALS_SarInitPEXT_MASK (0x1C0U)
#define DWC_DDRPHYA_MASTER_SARINITVALS_SarInitPEXT_SHIFT (6U)
/*! SarInitPEXT - Specify the SAR starting value for PEXT calibration. */
#define DWC_DDRPHYA_MASTER_SARINITVALS_SarInitPEXT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SARINITVALS_SarInitPEXT_SHIFT)) & DWC_DDRPHYA_MASTER_SARINITVALS_SarInitPEXT_MASK)
/*! @} */

/*! @name CALPEXTOVR - Impedance Calibration PExt Override control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALPEXTOVR_CalPExtOvr_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_CALPEXTOVR_CalPExtOvr_SHIFT (0U)
/*! CalPExtOvr - If the CSR CalPExtDis is set then the value provided here by software will be used
 *    instead of the automatically generated value which is visible via CSR CalPExt This CSR may
 *    only be written when the calibrator is not running.
 */
#define DWC_DDRPHYA_MASTER_CALPEXTOVR_CalPExtOvr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALPEXTOVR_CalPExtOvr_SHIFT)) & DWC_DDRPHYA_MASTER_CALPEXTOVR_CalPExtOvr_MASK)
/*! @} */

/*! @name CALCMPR5OVR - Impedance Calibration Cmpr 50 control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALCMPR5OVR_CalCmpr5Ovr_MASK (0xFFU)
#define DWC_DDRPHYA_MASTER_CALCMPR5OVR_CalCmpr5Ovr_SHIFT (0U)
/*! CalCmpr5Ovr - If the CSR CalCmpr5Dis is set then the value provided here by software will be
 *    used instead of the automatically generated value which is visible via CSR CalCmpr5 This CSR may
 *    only be written when the calibrator is not running.
 */
#define DWC_DDRPHYA_MASTER_CALCMPR5OVR_CalCmpr5Ovr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPR5OVR_CalCmpr5Ovr_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPR5OVR_CalCmpr5Ovr_MASK)
/*! @} */

/*! @name CALNINTOVR - Impedance Calibration NInt Override control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALNINTOVR_CalNIntOvr_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_CALNINTOVR_CalNIntOvr_SHIFT (0U)
/*! CalNIntOvr - If the CSR CalNIntDis is set then the value provided here by software will be used
 *    instead of the automatically generated value which is visible via CSR CalNInt.
 */
#define DWC_DDRPHYA_MASTER_CALNINTOVR_CalNIntOvr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALNINTOVR_CalNIntOvr_SHIFT)) & DWC_DDRPHYA_MASTER_CALNINTOVR_CalNIntOvr_MASK)
/*! @} */

/*! @name CALDRVSTR0 - Impedance Calibration driver strength control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALDRVSTR0_CalDrvStrPd50_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_CALDRVSTR0_CalDrvStrPd50_SHIFT (0U)
/*! CalDrvStrPd50 - 3. */
#define DWC_DDRPHYA_MASTER_CALDRVSTR0_CalDrvStrPd50(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALDRVSTR0_CalDrvStrPd50_SHIFT)) & DWC_DDRPHYA_MASTER_CALDRVSTR0_CalDrvStrPd50_MASK)

#define DWC_DDRPHYA_MASTER_CALDRVSTR0_CalDrvStrPu50_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_CALDRVSTR0_CalDrvStrPu50_SHIFT (4U)
/*! CalDrvStrPu50 - 3. */
#define DWC_DDRPHYA_MASTER_CALDRVSTR0_CalDrvStrPu50(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALDRVSTR0_CalDrvStrPu50_SHIFT)) & DWC_DDRPHYA_MASTER_CALDRVSTR0_CalDrvStrPu50_MASK)
/*! @} */

/*! @name PROCODTTIMECTL_P0 - READ DATA On-Die Termination Timing Control (by PHY) */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_POdtTailWidth_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_POdtTailWidth_SHIFT (0U)
/*! POdtTailWidth - controls the length of the tail of ProcOdt, units of UI 3 tail 3UI more than for
 *    Register POdtTailWidth=0, maximum 2 tail 2UI more than for Register POdtTailWidth=0, default
 *    1 tail 1UI more than for Register POdtTailWidth=0 0 minimum length tail The time from ProcODT
 *    to closing the window to receive DQS to ProcODT POdtTailWidth is (2 + POdtTailWidth) UI
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_POdtTailWidth(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_POdtTailWidth_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_POdtTailWidth_MASK)

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_POdtStartDelay_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_POdtStartDelay_SHIFT (2U)
/*! POdtStartDelay - controls the start of ProcOdt, units of UI 3 delay start 2 UI, maximum delay of
 *    start of ProcOdt 2 delay start 1 UI, 1 delay start 0 UI, default 0 early by 1 UI, The time
 *    from ProcODT assertion to opening the window to receive DQS is (10 - POdtStartDelay) UI.
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_POdtStartDelay(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_POdtStartDelay_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_POdtStartDelay_MASK)
/*! @} */

/*! @name MEMALERTCONTROL - This Register is used to configure the MemAlert Receiver */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVrefLevel_MASK (0x7FU)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVrefLevel_SHIFT (0U)
/*! MALERTVrefLevel - Sets the vref level of internal VREF DAC. */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVrefLevel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVrefLevel_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVrefLevel_MASK)

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVrefExtEn_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVrefExtEn_SHIFT (7U)
/*! MALERTVrefExtEn - When set for test/debug, selects external Vref source, This should not be set in mission mode. */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVrefExtEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVrefExtEn_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVrefExtEn_MASK)

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPuStren_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPuStren_SHIFT (8U)
/*! MALERTPuStren - Controls the Pull-up termination on MALERT
 *    ========================================== bit[8] - controls a 240 Ohm Pull-up leg bit[9] - controls a 240 Ohm Pull-up leg bit[10]
 *    - controls a 120 Ohm Pull-up leg bit[11] - controls a 120 Ohm Pull-up leg
 *    ========================================== 0000 - No PullUp Strength 0001 - 240 Ohm PullUp Strength 0010 - 240 Ohm
 *    PullUp Strength 0011 - 120 Ohm PullUp Strength 0100 - 120 Ohm PullUp Strength 0101 - 80 Ohm
 *    PullUp Strength 0110 - 80 Ohm PullUp Strength 0111 - 60 Ohm PullUp Strength 1000 - 120 Ohm
 *    PullUp Strength 1001 - 80 Ohm PullUp Strength 1010 - 80 Ohm PullUp Strength 1011 - 60 Ohm PullUp
 *    Strength 1100 - 60 Ohm PullUp Strength 1101 - 48 Ohm PullUp Strength 1110 - 48 Ohm PullUp
 *    Strength 1111 - 40 Ohm PullUp Strength
 */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPuStren(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPuStren_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPuStren_MASK)

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPuEn_MASK (0x1000U)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPuEn_SHIFT (12U)
/*! MALERTPuEn - When set, enables the Pull-up termination on MALERT */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPuEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPuEn_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPuEn_MASK)

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTRxEn_MASK (0x2000U)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTRxEn_SHIFT (13U)
/*! MALERTRxEn - 1 - Enables receiver and received data is forwared to dfi_alert_n. */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTRxEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTRxEn_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTRxEn_MASK)

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTDisableVal_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTDisableVal_SHIFT (14U)
/*! MALERTDisableVal - When MALERTRxEn is not set, this CSR state is used to drive dfi_alert_n. */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTDisableVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTDisableVal_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTDisableVal_MASK)

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTForceError_MASK (0x8000U)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTForceError_SHIFT (15U)
/*! MALERTForceError - When MALERTForceError is set, this CSR state is used to force parity error to memory. */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTForceError(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTForceError_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTForceError_MASK)
/*! @} */

/*! @name MEMALERTCONTROL2 - This Register is used to configure the MemAlert Receiver */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL2_MALERTSyncBypass_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL2_MALERTSyncBypass_SHIFT (0U)
/*! MALERTSyncBypass - MALERTSyncBypass==[0], the phy will drive dfi_alert_n with a synchronized value of the ALERT_N receiver. */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL2_MALERTSyncBypass(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL2_MALERTSyncBypass_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL2_MALERTSyncBypass_MASK)
/*! @} */

/*! @name MEMRESETL - Protection and control of BP_MemReset_L */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MEMRESETL_MemResetLValue_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_MEMRESETL_MemResetLValue_SHIFT (0U)
/*! MemResetLValue - Control the MemResetL output of the PHY. */
#define DWC_DDRPHYA_MASTER_MEMRESETL_MemResetLValue(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMRESETL_MemResetLValue_SHIFT)) & DWC_DDRPHYA_MASTER_MEMRESETL_MemResetLValue_MASK)

#define DWC_DDRPHYA_MASTER_MEMRESETL_ProtectMemReset_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_MEMRESETL_ProtectMemReset_SHIFT (1U)
/*! ProtectMemReset - Control the MemResetL output of the PHY. */
#define DWC_DDRPHYA_MASTER_MEMRESETL_ProtectMemReset(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMRESETL_ProtectMemReset_SHIFT)) & DWC_DDRPHYA_MASTER_MEMRESETL_ProtectMemReset_MASK)
/*! @} */

/*! @name DRIVECSLOWONTOHIGH - Drive CS_N 3:0 onto CS_N 7:4 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DRIVECSLOWONTOHIGH_CsLowOntoHigh_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DRIVECSLOWONTOHIGH_CsLowOntoHigh_SHIFT (0U)
/*! CsLowOntoHigh - When this is set to a 1, CS[3:0] from the ACSM are driven to CS[7:4] pins and CS[3:0] are deasserted. */
#define DWC_DDRPHYA_MASTER_DRIVECSLOWONTOHIGH_CsLowOntoHigh(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DRIVECSLOWONTOHIGH_CsLowOntoHigh_SHIFT)) & DWC_DDRPHYA_MASTER_DRIVECSLOWONTOHIGH_CsLowOntoHigh_MASK)
/*! @} */

/*! @name PUBMODE - PUBMODE - HWT Mux Select */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PUBMODE_HwtMemSrc_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PUBMODE_HwtMemSrc_SHIFT (0U)
/*! HwtMemSrc - When this is set to a 1, the mux that switches between DCT and HWT for the source of
 *    memory transactions is switched to HWT.
 */
#define DWC_DDRPHYA_MASTER_PUBMODE_HwtMemSrc(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PUBMODE_HwtMemSrc_SHIFT)) & DWC_DDRPHYA_MASTER_PUBMODE_HwtMemSrc_MASK)
/*! @} */

/*! @name MISCPHYSTATUS - Misc PHY status bits */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MISCPHYSTATUS_DctSane_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_MISCPHYSTATUS_DctSane_SHIFT (0U)
/*! DctSane - Returns the status of the custom circuit which protects the MemResetL output of the PHY on initial power-on or reset. */
#define DWC_DDRPHYA_MASTER_MISCPHYSTATUS_DctSane(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MISCPHYSTATUS_DctSane_SHIFT)) & DWC_DDRPHYA_MASTER_MISCPHYSTATUS_DctSane_MASK)

#define DWC_DDRPHYA_MASTER_MISCPHYSTATUS_PORMemReset_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_MISCPHYSTATUS_PORMemReset_SHIFT (1U)
/*! PORMemReset - Returns the active-high value used by the custom circuit which drives the memory RESET signal. */
#define DWC_DDRPHYA_MASTER_MISCPHYSTATUS_PORMemReset(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MISCPHYSTATUS_PORMemReset_SHIFT)) & DWC_DDRPHYA_MASTER_MISCPHYSTATUS_PORMemReset_MASK)
/*! @} */

/*! @name CORELOOPBACKSEL - Controls whether the loopback path bypasses the final PAD node. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CORELOOPBACKSEL_CoreLoopbackSel_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_CORELOOPBACKSEL_CoreLoopbackSel_SHIFT (0U)
/*! CoreLoopbackSel - This register is controlled by the PHY test firmware This register enables Core-Side loopback operation of the PHY. */
#define DWC_DDRPHYA_MASTER_CORELOOPBACKSEL_CoreLoopbackSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CORELOOPBACKSEL_CoreLoopbackSel_SHIFT)) & DWC_DDRPHYA_MASTER_CORELOOPBACKSEL_CoreLoopbackSel_MASK)
/*! @} */

/*! @name DLLTRAINPARAM - DLL Various Training Parameters */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DLLTRAINPARAM_ExtendPhdTime_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DLLTRAINPARAM_ExtendPhdTime_SHIFT (0U)
/*! ExtendPhdTime - Used by the PHY firmware locking the LCDL delay cells. */
#define DWC_DDRPHYA_MASTER_DLLTRAINPARAM_ExtendPhdTime(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLTRAINPARAM_ExtendPhdTime_SHIFT)) & DWC_DDRPHYA_MASTER_DLLTRAINPARAM_ExtendPhdTime_MASK)
/*! @} */

/*! @name HWTLPCSENBYPASS - CSn Disable Bypass for LPDDR3/4 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTLPCSENBYPASS_HwtLpCsEnBypass_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_HWTLPCSENBYPASS_HwtLpCsEnBypass_SHIFT (0U)
/*! HwtLpCsEnBypass - When set, these bits disable LpCsEn function for LPDDR3/4 */
#define DWC_DDRPHYA_MASTER_HWTLPCSENBYPASS_HwtLpCsEnBypass(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTLPCSENBYPASS_HwtLpCsEnBypass_SHIFT)) & DWC_DDRPHYA_MASTER_HWTLPCSENBYPASS_HwtLpCsEnBypass_MASK)
/*! @} */

/*! @name DFICAMODE - Dfi Command/Address Mode */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFICAMODE_DfiLp3CAMode_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DFICAMODE_DfiLp3CAMode_SHIFT (0U)
/*! DfiLp3CAMode - Controls the output data-rate of the AC module Command/Address pins 0: LP3 DDR
 *    address mode disabled 1: LP3 DDR address mode enabled
 */
#define DWC_DDRPHYA_MASTER_DFICAMODE_DfiLp3CAMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFICAMODE_DfiLp3CAMode_SHIFT)) & DWC_DDRPHYA_MASTER_DFICAMODE_DfiLp3CAMode_MASK)

#define DWC_DDRPHYA_MASTER_DFICAMODE_DfiD4CAMode_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DFICAMODE_DfiD4CAMode_SHIFT (1U)
/*! DfiD4CAMode - Enable D4 Mode 0: D4 mode disabled 1: D4 mode enabled */
#define DWC_DDRPHYA_MASTER_DFICAMODE_DfiD4CAMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFICAMODE_DfiD4CAMode_SHIFT)) & DWC_DDRPHYA_MASTER_DFICAMODE_DfiD4CAMode_MASK)

#define DWC_DDRPHYA_MASTER_DFICAMODE_DfiLp4CAMode_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_DFICAMODE_DfiLp4CAMode_SHIFT (2U)
/*! DfiLp4CAMode - Enable LP4 Mode 0: LP4 mode disabled 1: LP4 mode enabled */
#define DWC_DDRPHYA_MASTER_DFICAMODE_DfiLp4CAMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFICAMODE_DfiLp4CAMode_SHIFT)) & DWC_DDRPHYA_MASTER_DFICAMODE_DfiLp4CAMode_MASK)

#define DWC_DDRPHYA_MASTER_DFICAMODE_DfiD4AltCAMode_MASK (0x8U)
#define DWC_DDRPHYA_MASTER_DFICAMODE_DfiD4AltCAMode_SHIFT (3U)
/*! DfiD4AltCAMode - Enable D4-Alt Mode 0: D4-Altmode disabled 1: D4-Altmode enabled */
#define DWC_DDRPHYA_MASTER_DFICAMODE_DfiD4AltCAMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFICAMODE_DfiD4AltCAMode_SHIFT)) & DWC_DDRPHYA_MASTER_DFICAMODE_DfiD4AltCAMode_MASK)
/*! @} */

/*! @name DLLCONTROL - DLL Lock State machine control register */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetRelock_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetRelock_SHIFT (0U)
/*! DllResetRelock - Used to reset the DDL/LCDL lock state machine Deasserting starts locking sequence. */
#define DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetRelock(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetRelock_SHIFT)) & DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetRelock_MASK)

#define DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetSlave_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetSlave_SHIFT (1U)
/*! DllResetSlave - Reserved. */
#define DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetSlave(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetSlave_SHIFT)) & DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetSlave_MASK)

#define DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetRSVD_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetRSVD_SHIFT (2U)
/*! DllResetRSVD - RSVD for future use */
#define DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetRSVD(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetRSVD_SHIFT)) & DWC_DDRPHYA_MASTER_DLLCONTROL_DllResetRSVD_MASK)
/*! @} */

/*! @name PULSEDLLUPDATEPHASE - DLL update phase control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseDbyteDllUpdatePhase_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseDbyteDllUpdatePhase_SHIFT (0U)
/*! PulseDbyteDllUpdatePhase - Causes a LongBubble to the DBYTE modules, which causes a update of the DBYTE module DLLs (tx,rxen,rxclk). */
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseDbyteDllUpdatePhase(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseDbyteDllUpdatePhase_SHIFT)) & DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseDbyteDllUpdatePhase_MASK)

#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseACkDllUpdatePhase_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseACkDllUpdatePhase_SHIFT (1U)
/*! PulseACkDllUpdatePhase - Causes an AC module CK (memck) DLL phase update. */
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseACkDllUpdatePhase(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseACkDllUpdatePhase_SHIFT)) & DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseACkDllUpdatePhase_MASK)

#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseACaDllUpdatePhase_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseACaDllUpdatePhase_SHIFT (2U)
/*! PulseACaDllUpdatePhase - Causes an AC module CA (command/address/cke/odt) DLL phase update. */
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseACaDllUpdatePhase(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseACaDllUpdatePhase_SHIFT)) & DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PulseACaDllUpdatePhase_MASK)

#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_UpdatePhaseDestReserved_MASK (0x38U)
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_UpdatePhaseDestReserved_SHIFT (3U)
/*! UpdatePhaseDestReserved - reserved, not used */
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_UpdatePhaseDestReserved(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_UpdatePhaseDestReserved_SHIFT)) & DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_UpdatePhaseDestReserved_MASK)

#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_TrainUpdatePhaseOnLongBubble_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_TrainUpdatePhaseOnLongBubble_SHIFT (6U)
/*! TrainUpdatePhaseOnLongBubble - Causes LongBubble to update the dbyte & anib LDCL Phase. */
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_TrainUpdatePhaseOnLongBubble(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_TrainUpdatePhaseOnLongBubble_SHIFT)) & DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_TrainUpdatePhaseOnLongBubble_MASK)

#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_AlwaysUpdateLcdlPhase_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_AlwaysUpdateLcdlPhase_SHIFT (7U)
/*! AlwaysUpdateLcdlPhase - Causes each new operation to reload the LcdlPhase; will increase bubbles. */
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_AlwaysUpdateLcdlPhase(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_AlwaysUpdateLcdlPhase_SHIFT)) & DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_AlwaysUpdateLcdlPhase_MASK)
/*! @} */

/*! @name DLLGAINCTL_P0 - DLL gain control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllGainIV_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllGainIV_SHIFT (0U)
/*! DllGainIV - Initial value of DllGain. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllGainIV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllGainIV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllGainIV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllGainTV_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllGainTV_SHIFT (4U)
/*! DllGainTV - Terminal value of DllGain, ie the value in effect when locking is done and the value
 *    used for maintaining lock, ie tracking pclk variation.
 */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllGainTV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllGainTV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllGainTV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllSeedSel_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllSeedSel_SHIFT (8U)
/*! DllSeedSel - Reserved, must be configured to be 0. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllSeedSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllSeedSel_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DllSeedSel_MASK)
/*! @} */

/*! @name CALRATE - Impedance Calibration Control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALRATE_CalInterval_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_CALRATE_CalInterval_SHIFT (0U)
/*! CalInterval - This CSR specifies the interval between successive calibrations, in mS. */
#define DWC_DDRPHYA_MASTER_CALRATE_CalInterval(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALRATE_CalInterval_SHIFT)) & DWC_DDRPHYA_MASTER_CALRATE_CalInterval_MASK)

#define DWC_DDRPHYA_MASTER_CALRATE_CalRun_MASK   (0x10U)
#define DWC_DDRPHYA_MASTER_CALRATE_CalRun_SHIFT  (4U)
/*! CalRun - 1: A calibration sequence will be triggered by the 0->1 transition of this bit, as determined by CSR CalOnce. */
#define DWC_DDRPHYA_MASTER_CALRATE_CalRun(x)     (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALRATE_CalRun_SHIFT)) & DWC_DDRPHYA_MASTER_CALRATE_CalRun_MASK)

#define DWC_DDRPHYA_MASTER_CALRATE_CalOnce_MASK  (0x20U)
#define DWC_DDRPHYA_MASTER_CALRATE_CalOnce_SHIFT (5U)
/*! CalOnce - The setting of this CSR changes the behaviour of CSR CalRun. */
#define DWC_DDRPHYA_MASTER_CALRATE_CalOnce(x)    (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALRATE_CalOnce_SHIFT)) & DWC_DDRPHYA_MASTER_CALRATE_CalOnce_MASK)

#define DWC_DDRPHYA_MASTER_CALRATE_DisableBackgroundZQUpdates_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_CALRATE_DisableBackgroundZQUpdates_SHIFT (6U)
/*! DisableBackgroundZQUpdates - 1: Instead of having the driver compensation codes go
 *    asynchronously out to all IO, hold until for any of PHYUPD ACK, CTRLUPD ACK, PHYMSTR ACK) 0: Calibrated ZQ
 *    Updates to IO aren't gated.
 */
#define DWC_DDRPHYA_MASTER_CALRATE_DisableBackgroundZQUpdates(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALRATE_DisableBackgroundZQUpdates_SHIFT)) & DWC_DDRPHYA_MASTER_CALRATE_DisableBackgroundZQUpdates_MASK)
/*! @} */

/*! @name CALZAP - Impedance Calibration Zap/Reset */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALZAP_CalZap_MASK    (0x1U)
#define DWC_DDRPHYA_MASTER_CALZAP_CalZap_SHIFT   (0U)
/*! CalZap - NOTE : This CSR is written by PHY Initialization Engine (PIE) and the data in here will be overwritten. */
#define DWC_DDRPHYA_MASTER_CALZAP_CalZap(x)      (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALZAP_CalZap_SHIFT)) & DWC_DDRPHYA_MASTER_CALZAP_CalZap_MASK)
/*! @} */

/*! @name PSTATE - PSTATE Selection */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PSTATE_PState_MASK    (0xFU)
#define DWC_DDRPHYA_MASTER_PSTATE_PState_SHIFT   (0U)
/*! PState - NOTE : This CSR is written by PHY Initialization Engine (PIE) and the data in here will be overwritten. */
#define DWC_DDRPHYA_MASTER_PSTATE_PState(x)      (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PSTATE_PState_SHIFT)) & DWC_DDRPHYA_MASTER_PSTATE_PState_MASK)
/*! @} */

/*! @name PLLOUTGATECONTROL - PLL Output Control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLOUTGATECONTROL_PclkGateEn_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLOUTGATECONTROL_PclkGateEn_SHIFT (0U)
/*! PclkGateEn - Reserved. */
#define DWC_DDRPHYA_MASTER_PLLOUTGATECONTROL_PclkGateEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLOUTGATECONTROL_PclkGateEn_SHIFT)) & DWC_DDRPHYA_MASTER_PLLOUTGATECONTROL_PclkGateEn_MASK)
/*! @} */

/*! @name PORCONTROL - PMU Power-on Reset Control (PLL/DLL Lock Done) */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PORCONTROL_PllDllLockDone_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PORCONTROL_PllDllLockDone_SHIFT (0U)
/*! PllDllLockDone - Set by the PIE to 1 after it has finished the PLL/DLL lock sequence. */
#define DWC_DDRPHYA_MASTER_PORCONTROL_PllDllLockDone(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PORCONTROL_PllDllLockDone_SHIFT)) & DWC_DDRPHYA_MASTER_PORCONTROL_PllDllLockDone_MASK)
/*! @} */

/*! @name CALBUSY - Impedance Calibration Busy Status */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALBUSY_CalBusy_MASK  (0x1U)
#define DWC_DDRPHYA_MASTER_CALBUSY_CalBusy_SHIFT (0U)
/*! CalBusy - Read 1 if the calibrator is actively calibrating. */
#define DWC_DDRPHYA_MASTER_CALBUSY_CalBusy(x)    (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALBUSY_CalBusy_SHIFT)) & DWC_DDRPHYA_MASTER_CALBUSY_CalBusy_MASK)
/*! @} */

/*! @name CALMISC2 - Miscellaneous impedance calibration controls. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALMISC2_CalNumVotes_MASK (0x7U)
#define DWC_DDRPHYA_MASTER_CALMISC2_CalNumVotes_SHIFT (0U)
/*! CalNumVotes - This CSR controls the number of consecutive comparator output bits over which majority voting is done. */
#define DWC_DDRPHYA_MASTER_CALMISC2_CalNumVotes(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALMISC2_CalNumVotes_SHIFT)) & DWC_DDRPHYA_MASTER_CALMISC2_CalNumVotes_MASK)

#define DWC_DDRPHYA_MASTER_CALMISC2_CalCmptrResTrim_MASK (0x1000U)
#define DWC_DDRPHYA_MASTER_CALMISC2_CalCmptrResTrim_SHIFT (12U)
/*! CalCmptrResTrim - Reserved for future use. */
#define DWC_DDRPHYA_MASTER_CALMISC2_CalCmptrResTrim(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALMISC2_CalCmptrResTrim_SHIFT)) & DWC_DDRPHYA_MASTER_CALMISC2_CalCmptrResTrim_MASK)

#define DWC_DDRPHYA_MASTER_CALMISC2_CalCancelRoundErrDis_MASK (0x2000U)
#define DWC_DDRPHYA_MASTER_CALMISC2_CalCancelRoundErrDis_SHIFT (13U)
/*! CalCancelRoundErrDis - The PEXT calibration result and NINT calibration results naturally
 *    include a rounding error which manifests as a change of impedance at the pad.
 */
#define DWC_DDRPHYA_MASTER_CALMISC2_CalCancelRoundErrDis(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALMISC2_CalCancelRoundErrDis_SHIFT)) & DWC_DDRPHYA_MASTER_CALMISC2_CalCancelRoundErrDis_MASK)

#define DWC_DDRPHYA_MASTER_CALMISC2_CalSlowCmpana_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_CALMISC2_CalSlowCmpana_SHIFT (14U)
/*! CalSlowCmpana - When set, this CSR increases the time allowed for the cmpana cell to settle, by 50%. */
#define DWC_DDRPHYA_MASTER_CALMISC2_CalSlowCmpana(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALMISC2_CalSlowCmpana_SHIFT)) & DWC_DDRPHYA_MASTER_CALMISC2_CalSlowCmpana_MASK)
/*! @} */

/*! @name CALMISC - Controls for disabling the impedance calibration of certain targets. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALMISC_CalCmpr5Dis_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_CALMISC_CalCmpr5Dis_SHIFT (0U)
/*! CalCmpr5Dis - Setting this CSR prevents the calibration engine from using the result from the CalCmpr5 stage of calibration. */
#define DWC_DDRPHYA_MASTER_CALMISC_CalCmpr5Dis(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALMISC_CalCmpr5Dis_SHIFT)) & DWC_DDRPHYA_MASTER_CALMISC_CalCmpr5Dis_MASK)

#define DWC_DDRPHYA_MASTER_CALMISC_CalNIntDis_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_CALMISC_CalNIntDis_SHIFT (1U)
/*! CalNIntDis - Setting this CSR prevents the calibration engine from overwriting the CSRs
 *    TxCalBinN and TxCalThN with an automatically generated value, in which case a value must be supplied
 *    by software.
 */
#define DWC_DDRPHYA_MASTER_CALMISC_CalNIntDis(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALMISC_CalNIntDis_SHIFT)) & DWC_DDRPHYA_MASTER_CALMISC_CalNIntDis_MASK)

#define DWC_DDRPHYA_MASTER_CALMISC_CalPExtDis_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_CALMISC_CalPExtDis_SHIFT (2U)
/*! CalPExtDis - Setting this CSR prevents the calibration engine from overwriting the CSRs
 *    TxCalBinP and TxCalThP with an automatically generated value, in which case a value must be supplied
 *    by software.
 */
#define DWC_DDRPHYA_MASTER_CALMISC_CalPExtDis(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALMISC_CalPExtDis_SHIFT)) & DWC_DDRPHYA_MASTER_CALMISC_CalPExtDis_MASK)
/*! @} */

/*! @name CALVREFS -  */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALVREFS_CalVRefs_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_CALVREFS_CalVRefs_SHIFT (0U)
/*! CalVRefs - This CSR drives the Cmpdig_CalRef pin of the cmpana cell at various stages of calibration. */
#define DWC_DDRPHYA_MASTER_CALVREFS_CalVRefs(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALVREFS_CalVRefs_SHIFT)) & DWC_DDRPHYA_MASTER_CALVREFS_CalVRefs_MASK)
/*! @} */

/*! @name CALCMPR5 - Impedance Calibration Cmpr control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALCMPR5_CalCmpr5_MASK (0xFFU)
#define DWC_DDRPHYA_MASTER_CALCMPR5_CalCmpr5_SHIFT (0U)
/*! CalCmpr5 - Returns the offset-compensated DAC code for the cmpana circuit at VRef == 0. */
#define DWC_DDRPHYA_MASTER_CALCMPR5_CalCmpr5(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPR5_CalCmpr5_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPR5_CalCmpr5_MASK)
/*! @} */

/*! @name CALNINT - Impedance Calibration NInt control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALNINT_CalNIntThB_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_CALNINT_CalNIntThB_SHIFT (0U)
/*! CalNIntThB - The value here is the number of thermometer bits which are set. */
#define DWC_DDRPHYA_MASTER_CALNINT_CalNIntThB(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALNINT_CalNIntThB_SHIFT)) & DWC_DDRPHYA_MASTER_CALNINT_CalNIntThB_MASK)
/*! @} */

/*! @name CALPEXT - Impedance Calibration PExt control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALPEXT_CalPExtThB_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_CALPEXT_CalPExtThB_SHIFT (0U)
/*! CalPExtThB - The value here is the number of thermometer bits which are set. */
#define DWC_DDRPHYA_MASTER_CALPEXT_CalPExtThB(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALPEXT_CalPExtThB_SHIFT)) & DWC_DDRPHYA_MASTER_CALPEXT_CalPExtThB_MASK)
/*! @} */

/*! @name CALCMPINVERT - Impedance Calibration Cmp Invert control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDac50_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDac50_SHIFT (0U)
/*! CmpInvertCalDac50 - Impedance Calibration Cmp Invert control */
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDac50(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDac50_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDac50_MASK)

#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDrvPd50_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDrvPd50_SHIFT (1U)
/*! CmpInvertCalDrvPd50 - Impedance Calibration Cmp Invert control */
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDrvPd50(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDrvPd50_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDrvPd50_MASK)

#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDrvPu50_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDrvPu50_SHIFT (2U)
/*! CmpInvertCalDrvPu50 - Impedance Calibration Cmp Invert control */
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDrvPu50(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDrvPu50_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalDrvPu50_MASK)

#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalOdtPd_MASK (0x8U)
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalOdtPd_SHIFT (3U)
/*! CmpInvertCalOdtPd - Impedance Calibration Cmp Invert control */
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalOdtPd(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalOdtPd_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalOdtPd_MASK)

#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalOdtPu_MASK (0x10U)
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalOdtPu_SHIFT (4U)
/*! CmpInvertCalOdtPu - Impedance Calibration Cmp Invert control */
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalOdtPu(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalOdtPu_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPINVERT_CmpInvertCalOdtPu_MASK)
/*! @} */

/*! @name CALCMPANACNTRL - Impedance Calibration Cmpana control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprGainCurrAdj_MASK (0xFFU)
#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprGainCurrAdj_SHIFT (0U)
/*! CmprGainCurrAdj - Impedance Calibration Cmpana control */
#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprGainCurrAdj(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprGainCurrAdj_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprGainCurrAdj_MASK)

#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprGainResAdj_MASK (0x100U)
#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprGainResAdj_SHIFT (8U)
/*! CmprGainResAdj - Impedance Calibration Cmpana control */
#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprGainResAdj(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprGainResAdj_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprGainResAdj_MASK)

#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprBiasBypassEn_MASK (0x200U)
#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprBiasBypassEn_SHIFT (9U)
/*! CmprBiasBypassEn - Impedance Calibration Cmpana control */
#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprBiasBypassEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprBiasBypassEn_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CmprBiasBypassEn_MASK)
/*! @} */

/*! @name DFIRDDATACSDESTMAP_P0 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm0_SHIFT (0U)
/*! DfiRdDestm0 - Maps dfi_rddata_cs_n_p0[0] to dest DfiRdDestm0 timing For example, if 0
 *    dfi_rddata_cs_n_p0[0] will use Register RxEn,ClkDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm0_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm1_SHIFT (2U)
/*! DfiRdDestm1 - Maps dfi_rddata_cs_n_p0[1] to dest DfiRdDestm1 timing For example, if 1
 *    dfi_rddata_cs_n[_p01] will use Register RxEn,ClkDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm1_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm2_SHIFT (4U)
/*! DfiRdDestm2 - Maps dfi_rddata_cs_n_p0[2] to dest DfiRdDestm2 timing For example, if 2
 *    dfi_rddata_cs_n_p0[2] will use Register RxEn,ClkDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm2_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm3_SHIFT (6U)
/*! DfiRdDestm3 - Maps dfi_rddata_cs_n_p0[3] to dest DfiRdDestm3 timing For example, if 3
 *    dfi_rddata_cs_n_p0[3] will use Register RxEn,ClkDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DfiRdDestm3_MASK)
/*! @} */

/*! @name VREFINGLOBAL_P0 - PHY Global Vref Controls */
/*! @{ */

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInSel_MASK (0x7U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInSel_SHIFT (0U)
/*! GlobalVrefInSel - GlobalVrefInSel[1:0] controls the mode of the PHY VREF DAC and the BP_VREF pin
 *    ========================================================== 2'b00 - PHY Vref DAC Range0 --
 *    BP_VREF = Hi-Z 2'b01 - Reserved Encoding 2'b10 - PHY Vref DAC Range0 -- BP_VREF connected to PLL
 *    Analog Bus 2'b11 - PHY Vref DAC Range0 -- BP_VREF connected to PHY Vref DAC
 *    ========================================================== GlobalVrefInSel[2] shall be set according to Dram
 *    Protocol: Protocol GlobalVrefInSel[2] ------------------------------------------ DDR3 1'b0 DDR4
 *    1'b0 LPDDR3 1'b0 LPDDR4 1'b1
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInSel_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInSel_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInDAC_MASK (0x3F8U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInDAC_SHIFT (3U)
/*! GlobalVrefInDAC - DAC code for internal Vref generation The DAC has two ranges; the range is set
 *    by GlobalVrefInSel[2] ========================================================== RANGE0 :
 *    DDR3,DDR4,LPDDR3 [GlobalVrefInSel[2] = 0] DAC Output Voltage = GlobalVrefInDAC == 6'h00 ? Hi-Z :
 *    0.
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInDAC(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInDAC_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInDAC_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInTrim_MASK (0x3C00U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInTrim_SHIFT (10U)
/*! GlobalVrefInTrim - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInTrim(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInTrim_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInTrim_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInMode_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInMode_SHIFT (14U)
/*! GlobalVrefInMode - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInMode_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GlobalVrefInMode_MASK)
/*! @} */

/*! @name DFIWRDATACSDESTMAP_P0 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm0_SHIFT (0U)
/*! DfiWrDestm0 - Maps dfi_wrdata_cs_n_p0[0] to dest DfiWrDestm0 timing For example, if 0
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm0_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm1_SHIFT (2U)
/*! DfiWrDestm1 - Maps dfi_wrdata_cs_n_p0[1] to dest DfiWrDestm1 timing For example, if 1
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm1_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm2_SHIFT (4U)
/*! DfiWrDestm2 - Maps dfi_wrdata_cs_n_p0[2] to dest DfiWrDestm2 timing For example, if 2
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm2_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm3_SHIFT (6U)
/*! DfiWrDestm3 - Maps dfi_wrdata_cs_n_p0[3] to dest DfiWrDestm3 timing (use Register
 *    TxDq,DqsDlyTg3) For example, if 3 dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DfiWrDestm3_MASK)
/*! @} */

/*! @name MASUPDGOODCTR - Counts successful PHY Master Interface Updates (PPTs) */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MASUPDGOODCTR_MasUpdGoodCtr_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_MASUPDGOODCTR_MasUpdGoodCtr_SHIFT (0U)
/*! MasUpdGoodCtr - This register increments whenever the Memory Controller acknowledges a PHY Master Interface request (i. */
#define DWC_DDRPHYA_MASTER_MASUPDGOODCTR_MasUpdGoodCtr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MASUPDGOODCTR_MasUpdGoodCtr_SHIFT)) & DWC_DDRPHYA_MASTER_MASUPDGOODCTR_MasUpdGoodCtr_MASK)
/*! @} */

/*! @name PHYUPD0GOODCTR - Counts successful PHY-initiated DFI0 Interface Updates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYUPD0GOODCTR_PhyUpd0GoodCtr_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PHYUPD0GOODCTR_PhyUpd0GoodCtr_SHIFT (0U)
/*! PhyUpd0GoodCtr - This register increments whenever the Memory Controller acknowledges a PHY-initiated DFI0 interface update request. */
#define DWC_DDRPHYA_MASTER_PHYUPD0GOODCTR_PhyUpd0GoodCtr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYUPD0GOODCTR_PhyUpd0GoodCtr_SHIFT)) & DWC_DDRPHYA_MASTER_PHYUPD0GOODCTR_PhyUpd0GoodCtr_MASK)
/*! @} */

/*! @name PHYUPD1GOODCTR - Counts successful PHY-initiated DFI1 Interface Updates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYUPD1GOODCTR_PhyUpd1GoodCtr_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PHYUPD1GOODCTR_PhyUpd1GoodCtr_SHIFT (0U)
/*! PhyUpd1GoodCtr - This register increments whenever the Memory Controller acknowledges a PHY-initiated DFI1 interface update request. */
#define DWC_DDRPHYA_MASTER_PHYUPD1GOODCTR_PhyUpd1GoodCtr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYUPD1GOODCTR_PhyUpd1GoodCtr_SHIFT)) & DWC_DDRPHYA_MASTER_PHYUPD1GOODCTR_PhyUpd1GoodCtr_MASK)
/*! @} */

/*! @name CTLUPD0GOODCTR - Counts successful Memory Controller DFI0 Interface Updates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CTLUPD0GOODCTR_CtlUpd0GoodCtr_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_CTLUPD0GOODCTR_CtlUpd0GoodCtr_SHIFT (0U)
/*! CtlUpd0GoodCtr - This register increments whenever the PHY acknowledges a Memory Controller-initiated DFI0 interface update request. */
#define DWC_DDRPHYA_MASTER_CTLUPD0GOODCTR_CtlUpd0GoodCtr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CTLUPD0GOODCTR_CtlUpd0GoodCtr_SHIFT)) & DWC_DDRPHYA_MASTER_CTLUPD0GOODCTR_CtlUpd0GoodCtr_MASK)
/*! @} */

/*! @name CTLUPD1GOODCTR - Counts successful Memory Controller DFI1 Interface Updates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CTLUPD1GOODCTR_CtlUpd1GoodCtr_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_CTLUPD1GOODCTR_CtlUpd1GoodCtr_SHIFT (0U)
/*! CtlUpd1GoodCtr - This register increments whenever the PHY acknowledges a Memory Controller-initiated DFI1 interface update request. */
#define DWC_DDRPHYA_MASTER_CTLUPD1GOODCTR_CtlUpd1GoodCtr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CTLUPD1GOODCTR_CtlUpd1GoodCtr_SHIFT)) & DWC_DDRPHYA_MASTER_CTLUPD1GOODCTR_CtlUpd1GoodCtr_MASK)
/*! @} */

/*! @name MASUPDFAILCTR - Counts unsuccessful PHY Master Interface Updates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MASUPDFAILCTR_MasUpdFailCtr_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_MASUPDFAILCTR_MasUpdFailCtr_SHIFT (0U)
/*! MasUpdFailCtr - This register increments whenever the PHY asserts a PHY Master Interface
 *    request, but the Memory Controller doesn't acknowledge the request within the allowed interval.
 */
#define DWC_DDRPHYA_MASTER_MASUPDFAILCTR_MasUpdFailCtr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MASUPDFAILCTR_MasUpdFailCtr_SHIFT)) & DWC_DDRPHYA_MASTER_MASUPDFAILCTR_MasUpdFailCtr_MASK)
/*! @} */

/*! @name PHYUPD0FAILCTR - Counts unsuccessful PHY-initiated DFI0 Interface Updates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYUPD0FAILCTR_PhyUpd0FailCtr_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PHYUPD0FAILCTR_PhyUpd0FailCtr_SHIFT (0U)
/*! PhyUpd0FailCtr - This register increments whenever the PHY asserts a DFI0 Interface update
 *    request, but the Memory Controller doesn't acknowledge the request within the allowed interval.
 */
#define DWC_DDRPHYA_MASTER_PHYUPD0FAILCTR_PhyUpd0FailCtr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYUPD0FAILCTR_PhyUpd0FailCtr_SHIFT)) & DWC_DDRPHYA_MASTER_PHYUPD0FAILCTR_PhyUpd0FailCtr_MASK)
/*! @} */

/*! @name PHYUPD1FAILCTR - Counts unsuccessful PHY-initiated DFI1 Interface Updates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYUPD1FAILCTR_PhyUpd1FailCtr_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PHYUPD1FAILCTR_PhyUpd1FailCtr_SHIFT (0U)
/*! PhyUpd1FailCtr - This register increments whenever the PHY asserts a DFI1 Interface update
 *    request, but the Memory Controller doesn't acknowledge the request within the allowed interval.
 */
#define DWC_DDRPHYA_MASTER_PHYUPD1FAILCTR_PhyUpd1FailCtr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYUPD1FAILCTR_PhyUpd1FailCtr_SHIFT)) & DWC_DDRPHYA_MASTER_PHYUPD1FAILCTR_PhyUpd1FailCtr_MASK)
/*! @} */

/*! @name PHYPERFCTRENABLE - Enables for Performance Counters */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MasUpdGoodCtl_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MasUpdGoodCtl_SHIFT (0U)
/*! MasUpdGoodCtl - Enables MasUpdGoodCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MasUpdGoodCtl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MasUpdGoodCtl_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MasUpdGoodCtl_MASK)

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd0GoodCtl_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd0GoodCtl_SHIFT (1U)
/*! PhyUpd0GoodCtl - Enables PhyUpd0GoodCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd0GoodCtl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd0GoodCtl_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd0GoodCtl_MASK)

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd1GoodCtl_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd1GoodCtl_SHIFT (2U)
/*! PhyUpd1GoodCtl - Enables PhyUpd1GoodCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd1GoodCtl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd1GoodCtl_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd1GoodCtl_MASK)

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CtlUpd0GoodCtl_MASK (0x8U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CtlUpd0GoodCtl_SHIFT (3U)
/*! CtlUpd0GoodCtl - Enables CtlUpd0GoodCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CtlUpd0GoodCtl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CtlUpd0GoodCtl_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CtlUpd0GoodCtl_MASK)

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CtlUpd1GoodCtl_MASK (0x10U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CtlUpd1GoodCtl_SHIFT (4U)
/*! CtlUpd1GoodCtl - Enables CtlUpd1GoodCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CtlUpd1GoodCtl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CtlUpd1GoodCtl_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CtlUpd1GoodCtl_MASK)

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MasUpdFailCtl_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MasUpdFailCtl_SHIFT (5U)
/*! MasUpdFailCtl - Enables MasUpdFailCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MasUpdFailCtl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MasUpdFailCtl_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MasUpdFailCtl_MASK)

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd0FailCtl_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd0FailCtl_SHIFT (6U)
/*! PhyUpd0FailCtl - Enables PhyUpd0FailCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd0FailCtl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd0FailCtl_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd0FailCtl_MASK)

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd1FailCtl_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd1FailCtl_SHIFT (7U)
/*! PhyUpd1FailCtl - Enables PhyUpd1FailCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd1FailCtl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd1FailCtl_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PhyUpd1FailCtl_MASK)
/*! @} */

/*! @name PLLPWRDN - PLL Power Down */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLPWRDN_PllPwrDn_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLPWRDN_PllPwrDn_SHIFT (0U)
/*! PllPwrDn - NOTE : This CSR is written by PHY Initialization Engine (PIE) and the data in here will be overwritten. */
#define DWC_DDRPHYA_MASTER_PLLPWRDN_PllPwrDn(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLPWRDN_PllPwrDn_SHIFT)) & DWC_DDRPHYA_MASTER_PLLPWRDN_PllPwrDn_MASK)
/*! @} */

/*! @name PLLRESET - PLL Reset */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLRESET_PllReset_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLRESET_PllReset_SHIFT (0U)
/*! PllReset - Reserved */
#define DWC_DDRPHYA_MASTER_PLLRESET_PllReset(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLRESET_PllReset_SHIFT)) & DWC_DDRPHYA_MASTER_PLLRESET_PllReset_MASK)
/*! @} */

/*! @name PLLCTRL2_P0 - PState dependent PLL Control Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL2_P0_PllFreqSel_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P0_PllFreqSel_SHIFT (0U)
/*! PllFreqSel - Adjusts the loop parameters to compensate for different VCO bias points, and input/output clock division ratios. */
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P0_PllFreqSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL2_P0_PllFreqSel_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL2_P0_PllFreqSel_MASK)
/*! @} */

/*! @name PLLCTRL0 - PLL Control Register 0 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllStandby_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllStandby_SHIFT (0U)
/*! PllStandby - Connects directly to standby pin of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllStandby(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PllStandby_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PllStandby_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllBypSel_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllBypSel_SHIFT (1U)
/*! PllBypSel - Reserved. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllBypSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PllBypSel_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PllBypSel_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllX2Mode_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllX2Mode_SHIFT (2U)
/*! PllX2Mode - conects to x2_mode pins of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllX2Mode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PllX2Mode_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PllX2Mode_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllOutBypEn_MASK (0x8U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllOutBypEn_SHIFT (3U)
/*! PllOutBypEn - Controls the antiglitch mux on the pllout_x1x2x4 path 1: pllout_x1x2x4 =
 *    byp_pllin_x1 0: pllout_x1x2x4 = VCO (SCD) (selected by x2_mode)
 */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllOutBypEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PllOutBypEn_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PllOutBypEn_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllPreset_MASK (0x10U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllPreset_SHIFT (4U)
/*! PllPreset - Put PLL in preset mode. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllPreset(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PllPreset_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PllPreset_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllBypassMode_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllBypassMode_SHIFT (5U)
/*! PllBypassMode - PLL Bypass clock mux control. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllBypassMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PllBypassMode_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PllBypassMode_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllSelDfiFreqRatio_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllSelDfiFreqRatio_SHIFT (6U)
/*! PllSelDfiFreqRatio - reserved. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllSelDfiFreqRatio(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PllSelDfiFreqRatio_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PllSelDfiFreqRatio_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllSyncBusFlush_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllSyncBusFlush_SHIFT (7U)
/*! PllSyncBusFlush - Used to flush the syncbus logic of the PLL during PHY initialization or LP3 Exit sequence. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllSyncBusFlush(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PllSyncBusFlush_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PllSyncBusFlush_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllSyncBusByp_MASK (0x100U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllSyncBusByp_SHIFT (8U)
/*! PllSyncBusByp - When asserted bypasses the Pll SyncPulse and uses a synchronizer of the same latency. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllSyncBusByp(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PllSyncBusByp_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PllSyncBusByp_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllReserved10x9_MASK (0x600U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllReserved10x9_SHIFT (9U)
/*! PllReserved10x9 - for future use. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllReserved10x9(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PllReserved10x9_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PllReserved10x9_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllGearShift_MASK (0x800U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllGearShift_SHIFT (11U)
/*! PllGearShift - Puts PLL in fast re-locking mode 0: default, normal mode 1: fast relock gear */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllGearShift(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PllGearShift_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PllGearShift_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllLockCntSel_MASK (0x1000U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllLockCntSel_SHIFT (12U)
/*! PllLockCntSel - Lock detect counter selection. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllLockCntSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PllLockCntSel_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PllLockCntSel_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllLockPhSel_MASK (0x6000U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllLockPhSel_SHIFT (13U)
/*! PllLockPhSel - Lock detect phase selection. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllLockPhSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PllLockPhSel_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PllLockPhSel_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllSpareCtrl0_MASK (0x8000U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllSpareCtrl0_SHIFT (15U)
/*! PllSpareCtrl0 - Spare bits for PLL control. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PllSpareCtrl0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PllSpareCtrl0_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PllSpareCtrl0_MASK)
/*! @} */

/*! @name PLLCTRL1_P0 - PState dependent PLL Control Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PllCpIntCtrl_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PllCpIntCtrl_SHIFT (0U)
/*! PllCpIntCtrl - connects directly to cp_int_cntrl<1:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PllCpIntCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PllCpIntCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PllCpIntCtrl_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PllCpPropCtrl_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PllCpPropCtrl_SHIFT (5U)
/*! PllCpPropCtrl - connects directly to cp_prop_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PllCpPropCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PllCpPropCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PllCpPropCtrl_MASK)
/*! @} */

/*! @name PLLTST - PLL Testing Control Register */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLTST_PllAnaTstEn_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLTST_PllAnaTstEn_SHIFT (0U)
/*! PllAnaTstEn - Connects directly to pll_ana_test_en of PLL. */
#define DWC_DDRPHYA_MASTER_PLLTST_PllAnaTstEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLTST_PllAnaTstEn_SHIFT)) & DWC_DDRPHYA_MASTER_PLLTST_PllAnaTstEn_MASK)

#define DWC_DDRPHYA_MASTER_PLLTST_PllAnaTstSel_MASK (0x1EU)
#define DWC_DDRPHYA_MASTER_PLLTST_PllAnaTstSel_SHIFT (1U)
/*! PllAnaTstSel - Connects directly to pll_ana_test_sel<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLTST_PllAnaTstSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLTST_PllAnaTstSel_SHIFT)) & DWC_DDRPHYA_MASTER_PLLTST_PllAnaTstSel_MASK)

#define DWC_DDRPHYA_MASTER_PLLTST_PllDigTstSel_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLTST_PllDigTstSel_SHIFT (5U)
/*! PllDigTstSel - Connects directly to pll_dig_test_sel<2:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLTST_PllDigTstSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLTST_PllDigTstSel_SHIFT)) & DWC_DDRPHYA_MASTER_PLLTST_PllDigTstSel_MASK)
/*! @} */

/*! @name PLLLOCKSTATUS - PLL's pll_lock pin output */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLLOCKSTATUS_PllLockStatus_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLLOCKSTATUS_PllLockStatus_SHIFT (0U)
/*! PllLockStatus - Directly connected to the pll_Lock output. */
#define DWC_DDRPHYA_MASTER_PLLLOCKSTATUS_PllLockStatus(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLLOCKSTATUS_PllLockStatus_SHIFT)) & DWC_DDRPHYA_MASTER_PLLLOCKSTATUS_PllLockStatus_MASK)
/*! @} */

/*! @name PLLTESTMODE_P0 - Additional controls for PLL CP/VCO modes of operation */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P0_PllTestMode_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P0_PllTestMode_p0_SHIFT (0U)
/*! PllTestMode_p0 - It is required to use default values for this CSR unless directed otherwise by Synopsys. */
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P0_PllTestMode_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLTESTMODE_P0_PllTestMode_p0_SHIFT)) & DWC_DDRPHYA_MASTER_PLLTESTMODE_P0_PllTestMode_p0_MASK)
/*! @} */

/*! @name PLLCTRL3 - PLL Control Register 3 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllSpare_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllSpare_SHIFT (0U)
/*! PllSpare - Spare bits for future PLL control modes */
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllSpare(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL3_PllSpare_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL3_PllSpare_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllMaxRange_MASK (0x1F0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllMaxRange_SHIFT (4U)
/*! PllMaxRange - connects directly to maxrange of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllMaxRange(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL3_PllMaxRange_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL3_PllMaxRange_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllDacValIn_MASK (0x3E00U)
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllDacValIn_SHIFT (9U)
/*! PllDacValIn - connects directly to dacval_in<4:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllDacValIn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL3_PllDacValIn_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL3_PllDacValIn_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllForceCal_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllForceCal_SHIFT (14U)
/*! PllForceCal - connects directly to force_cal of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllForceCal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL3_PllForceCal_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL3_PllForceCal_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllEnCal_MASK (0x8000U)
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllEnCal_SHIFT (15U)
/*! PllEnCal - Calibration will run at standby rising edge if en_cal=1 if en_cal=0 calibration will not run */
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PllEnCal(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL3_PllEnCal_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL3_PllEnCal_MASK)
/*! @} */

/*! @name PLLCTRL4_P0 - PState dependent PLL Control Register 4 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PllCpIntGsCtrl_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PllCpIntGsCtrl_SHIFT (0U)
/*! PllCpIntGsCtrl - connects directly to cp_int_gs_cntrl<4:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PllCpIntGsCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PllCpIntGsCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PllCpIntGsCtrl_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PllCpPropGsCtrl_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PllCpPropGsCtrl_SHIFT (5U)
/*! PllCpPropGsCtrl - connects directly to cp_prop_gs_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PllCpPropGsCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PllCpPropGsCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PllCpPropGsCtrl_MASK)
/*! @} */

/*! @name PLLENDOFCAL - PLL's eoc (end of calibration) output */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLENDOFCAL_PllEndofCal_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLENDOFCAL_PllEndofCal_SHIFT (0U)
/*! PllEndofCal - Directly connected to the pll's eoc output. */
#define DWC_DDRPHYA_MASTER_PLLENDOFCAL_PllEndofCal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLENDOFCAL_PllEndofCal_SHIFT)) & DWC_DDRPHYA_MASTER_PLLENDOFCAL_PllEndofCal_MASK)
/*! @} */

/*! @name PLLSTANDBYEFF - PLL's standby_eff (effective standby) output */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLSTANDBYEFF_PllStandbyEff_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLSTANDBYEFF_PllStandbyEff_SHIFT (0U)
/*! PllStandbyEff - Returns state off PLL standby. */
#define DWC_DDRPHYA_MASTER_PLLSTANDBYEFF_PllStandbyEff(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLSTANDBYEFF_PllStandbyEff_SHIFT)) & DWC_DDRPHYA_MASTER_PLLSTANDBYEFF_PllStandbyEff_MASK)
/*! @} */

/*! @name PLLDACVALOUT - PLL's Dacval_out output */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLDACVALOUT_PllDacValOut_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLDACVALOUT_PllDacValOut_SHIFT (0U)
/*! PllDacValOut - Directly connected to the pll's dacval_out output. */
#define DWC_DDRPHYA_MASTER_PLLDACVALOUT_PllDacValOut(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLDACVALOUT_PllDacValOut_SHIFT)) & DWC_DDRPHYA_MASTER_PLLDACVALOUT_PllDacValOut_MASK)
/*! @} */

/*! @name LCDLDBGCNTL - Controls for use in observing and testing the LCDLs. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineOvrVal_MASK (0x1FFU)
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineOvrVal_SHIFT (0U)
/*! LcdlFineOvrVal - Value forced as the initial value while LcdlTstEnable=1 and LcdlFineOvr. */
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineOvrVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineOvrVal_SHIFT)) & DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineOvrVal_MASK)

#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineOvr_MASK (0x200U)
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineOvr_SHIFT (9U)
/*! LcdlFineOvr - Forces the value of the present LCDL 1UI estimate code to be LcdlFineOvrVal for all LCDLs. */
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineOvr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineOvr_SHIFT)) & DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineOvr_MASK)

#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineSnap_MASK (0x400U)
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineSnap_SHIFT (10U)
/*! LcdlFineSnap - Latch enable for reading the present LCDL 1UI estimate code in LcdlFineSnapVal
 *    and the present phase-detector value in LcdlPhdSnapVal
 */
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineSnap(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineSnap_SHIFT)) & DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlFineSnap_MASK)

#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlTstEnable_MASK (0x800U)
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlTstEnable_SHIFT (11U)
/*! LcdlTstEnable - Enables the debug/test operations and status Ovr,Snap,StickyLock,StickyUnlock, and LiveLock. */
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlTstEnable(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlTstEnable_SHIFT)) & DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlTstEnable_MASK)

#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlStatusSel_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlStatusSel_SHIFT (12U)
/*! LcdlStatusSel - Selects the LCDL status, from among the status for the 16 LCDLs in the DBYTE,
 *    for reading via Register DxLcdlStatus and an LCDL from among the LCDLs in the ANIB for reading
 *    via Register AcLcdlStatus LcdlStatusSel source for DxLcdlStatus source for AcLcdlStatus 15
 *    lcdl_rxclk1t reserved 14 lcdl_rxclk0t reserved 13 lcdl_rxclk1c reserved 12 lcdl_rxclk0c reserved
 *    11 lcdl_rxen1 anib11-tx 10 lcdl_rxen0 anib10-tx 9 lcdl_txln9 (dqs-lower) anib9-tx 8 lcdl_txln8
 *    (dm/dqs-upper) anib8-tx 7 lcdl_txln7 (dq7) anib7-tx 6 lcdl_txln6 (dq6) anib6-tx 5 lcdl_txln5
 *    (dq5) anib5-tx 4 lcdl_txln4 (dq4) anib4-tx 3 lcdl_txln3 (dq3) anib3-tx 2 lcdl_txln2 (dq2)
 *    anib2-tx 1 lcdl_txln1 (dq1) anib1-tx 0 lcdl_txln0 (dq0) anib0-tx
 */
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlStatusSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlStatusSel_SHIFT)) & DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LcdlStatusSel_MASK)
/*! @} */

/*! @name ACLCDLSTATUS - Debug status of the DBYTE LCDL */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlFineSnapVal_MASK (0x3FFU)
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlFineSnapVal_SHIFT (0U)
/*! AcLcdlFineSnapVal - Value of the LCDL 1UI estimate code, latched by pulse on csrLcdlFineSnap while csr LcdlTstEnable=1. */
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlFineSnapVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlFineSnapVal_SHIFT)) & DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlFineSnapVal_MASK)

#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlPhdSnapVal_MASK (0x400U)
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlPhdSnapVal_SHIFT (10U)
/*! AcLcdlPhdSnapVal - Value of the LCDL phase-detector output, latched by pulse on LcdlFineSnap while csr LcdlTstEnable=1. */
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlPhdSnapVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlPhdSnapVal_SHIFT)) & DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlPhdSnapVal_MASK)

#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlStickyLock_MASK (0x800U)
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlStickyLock_SHIFT (11U)
/*! AcLcdlStickyLock - latched value of whether the LCDL ever achieved lock after the assertion of LcdlTstEnable. */
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlStickyLock(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlStickyLock_SHIFT)) & DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlStickyLock_MASK)

#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlStickyUnlock_MASK (0x1000U)
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlStickyUnlock_SHIFT (12U)
/*! AcLcdlStickyUnlock - latched value of whether the LCDL ever lost lock after the assertion of LcdlTstEnable. */
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlStickyUnlock(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlStickyUnlock_SHIFT)) & DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlStickyUnlock_MASK)

#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlLiveLock_MASK (0x2000U)
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlLiveLock_SHIFT (13U)
/*! AcLcdlLiveLock - present value of whether the LCDL is locked, valid when LcdlTstEnable=1. */
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlLiveLock(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlLiveLock_SHIFT)) & DWC_DDRPHYA_MASTER_ACLCDLSTATUS_AcLcdlLiveLock_MASK)
/*! @} */

/*! @name CUSTPHYREV - Customer settable by the customer */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CUSTPHYREV_CUSTPHYREV_MASK (0x3FU)
#define DWC_DDRPHYA_MASTER_CUSTPHYREV_CUSTPHYREV_SHIFT (0U)
/*! CUSTPHYREV - The customer settable PHY version number. */
#define DWC_DDRPHYA_MASTER_CUSTPHYREV_CUSTPHYREV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CUSTPHYREV_CUSTPHYREV_SHIFT)) & DWC_DDRPHYA_MASTER_CUSTPHYREV_CUSTPHYREV_MASK)
/*! @} */

/*! @name PHYREV - The hardware version of this PHY, excluding the PUB */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYREV_PHYMNR_MASK    (0xFU)
#define DWC_DDRPHYA_MASTER_PHYREV_PHYMNR_SHIFT   (0U)
/*! PHYMNR - Indicates minor update of the PHY. */
#define DWC_DDRPHYA_MASTER_PHYREV_PHYMNR(x)      (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYREV_PHYMNR_SHIFT)) & DWC_DDRPHYA_MASTER_PHYREV_PHYMNR_MASK)

#define DWC_DDRPHYA_MASTER_PHYREV_PHYMDR_MASK    (0xF0U)
#define DWC_DDRPHYA_MASTER_PHYREV_PHYMDR_SHIFT   (4U)
/*! PHYMDR - Indicates moderate revision of the PHY. */
#define DWC_DDRPHYA_MASTER_PHYREV_PHYMDR(x)      (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYREV_PHYMDR_SHIFT)) & DWC_DDRPHYA_MASTER_PHYREV_PHYMDR_MASK)

#define DWC_DDRPHYA_MASTER_PHYREV_PHYMJR_MASK    (0xFF00U)
#define DWC_DDRPHYA_MASTER_PHYREV_PHYMJR_SHIFT   (8U)
/*! PHYMJR - Indicates major revision of the PHY. */
#define DWC_DDRPHYA_MASTER_PHYREV_PHYMJR(x)      (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYREV_PHYMJR_SHIFT)) & DWC_DDRPHYA_MASTER_PHYREV_PHYMJR_MASK)
/*! @} */

/*! @name LP3EXITSEQ0BSTARTVECTOR - Start vector value to be used for LP3-exit or Init PIE Sequence */
/*! @{ */

#define DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3ExitSeq0BStartVecPllEnabled_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3ExitSeq0BStartVecPllEnabled_SHIFT (0U)
/*! LP3ExitSeq0BStartVecPllEnabled - PIE Start Vector value to be used for LP3-exit or Init and target P-state has PLL enabled */
#define DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3ExitSeq0BStartVecPllEnabled(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3ExitSeq0BStartVecPllEnabled_SHIFT)) & DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3ExitSeq0BStartVecPllEnabled_MASK)

#define DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3ExitSeq0BStartVecPllBypassed_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3ExitSeq0BStartVecPllBypassed_SHIFT (4U)
/*! LP3ExitSeq0BStartVecPllBypassed - PIE Start Vector value to be used for LP3-exit or Init and target P-state has PLL bypassed */
#define DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3ExitSeq0BStartVecPllBypassed(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3ExitSeq0BStartVecPllBypassed_SHIFT)) & DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3ExitSeq0BStartVecPllBypassed_MASK)
/*! @} */

/*! @name DFIFREQXLAT0 - DFI Frequency Translation Register 0 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal0_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal0_SHIFT (0U)
/*! DfiFreqXlatVal0 - The sequencer start vector used when dfi_freq value is 0. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal0_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal1_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal1_SHIFT (4U)
/*! DfiFreqXlatVal1 - The sequencer start vector used when dfi_freq value is 1. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal1_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal2_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal2_SHIFT (8U)
/*! DfiFreqXlatVal2 - The sequencer start vector used when dfi_freq value is 2. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal2_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal3_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal3_SHIFT (12U)
/*! DfiFreqXlatVal3 - The sequencer start vector used when dfi_freq value is 3. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DfiFreqXlatVal3_MASK)
/*! @} */

/*! @name DFIFREQXLAT1 - DFI Frequency Translation Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal4_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal4_SHIFT (0U)
/*! DfiFreqXlatVal4 - The sequencer start vector used when dfi_freq value is 4. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal4_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal4_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal5_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal5_SHIFT (4U)
/*! DfiFreqXlatVal5 - The sequencer start vector used when dfi_freq value is 5. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal5_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal5_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal6_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal6_SHIFT (8U)
/*! DfiFreqXlatVal6 - The sequencer start vector used when dfi_freq value is 6. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal6_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal6_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal7_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal7_SHIFT (12U)
/*! DfiFreqXlatVal7 - The sequencer start vector used when dfi_freq value is 7. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal7_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DfiFreqXlatVal7_MASK)
/*! @} */

/*! @name DFIFREQXLAT2 - DFI Frequency Translation Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal8_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal8_SHIFT (0U)
/*! DfiFreqXlatVal8 - The sequencer start vector used when dfi_freq value is 8. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal8_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal8_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal9_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal9_SHIFT (4U)
/*! DfiFreqXlatVal9 - The sequencer start vector used when dfi_freq value is 9. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal9(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal9_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal9_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal10_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal10_SHIFT (8U)
/*! DfiFreqXlatVal10 - The sequencer start vector used when dfi_freq value is 10. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal10(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal10_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal10_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal11_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal11_SHIFT (12U)
/*! DfiFreqXlatVal11 - The sequencer start vector used when dfi_freq value is 11. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal11(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal11_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DfiFreqXlatVal11_MASK)
/*! @} */

/*! @name DFIFREQXLAT3 - DFI Frequency Translation Register 3 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal12_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal12_SHIFT (0U)
/*! DfiFreqXlatVal12 - The sequencer start vector used when dfi_freq value is 12. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal12(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal12_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal12_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal13_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal13_SHIFT (4U)
/*! DfiFreqXlatVal13 - The sequencer start vector used when dfi_freq value is 13. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal13(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal13_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal13_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal14_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal14_SHIFT (8U)
/*! DfiFreqXlatVal14 - The sequencer start vector used when dfi_freq value is 14. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal14(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal14_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal14_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal15_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal15_SHIFT (12U)
/*! DfiFreqXlatVal15 - The sequencer start vector used when dfi_freq value is 15. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal15(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal15_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DfiFreqXlatVal15_MASK)
/*! @} */

/*! @name DFIFREQXLAT4 - DFI Frequency Translation Register 4 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal16_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal16_SHIFT (0U)
/*! DfiFreqXlatVal16 - The sequencer start vector used when dfi_freq value is 16. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal16(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal16_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal16_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal17_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal17_SHIFT (4U)
/*! DfiFreqXlatVal17 - The sequencer start vector used when dfi_freq value is 17. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal17(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal17_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal17_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal18_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal18_SHIFT (8U)
/*! DfiFreqXlatVal18 - The sequencer start vector used when dfi_freq value is 18. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal18(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal18_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal18_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal19_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal19_SHIFT (12U)
/*! DfiFreqXlatVal19 - The sequencer start vector used when dfi_freq value is 19. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal19(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal19_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DfiFreqXlatVal19_MASK)
/*! @} */

/*! @name DFIFREQXLAT5 - DFI Frequency Translation Register 5 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal20_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal20_SHIFT (0U)
/*! DfiFreqXlatVal20 - The sequencer start vector used when dfi_freq value is 20. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal20(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal20_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal20_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal21_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal21_SHIFT (4U)
/*! DfiFreqXlatVal21 - The sequencer start vector used when dfi_freq value is 21. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal21(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal21_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal21_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal22_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal22_SHIFT (8U)
/*! DfiFreqXlatVal22 - The sequencer start vector used when dfi_freq value is 22. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal22(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal22_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal22_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal23_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal23_SHIFT (12U)
/*! DfiFreqXlatVal23 - The sequencer start vector used when dfi_freq value is 23. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal23(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal23_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DfiFreqXlatVal23_MASK)
/*! @} */

/*! @name DFIFREQXLAT6 - DFI Frequency Translation Register 6 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal24_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal24_SHIFT (0U)
/*! DfiFreqXlatVal24 - The sequencer start vector used when dfi_freq value is 24. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal24(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal24_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal24_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal25_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal25_SHIFT (4U)
/*! DfiFreqXlatVal25 - The sequencer start vector used when dfi_freq value is 25. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal25(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal25_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal25_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal26_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal26_SHIFT (8U)
/*! DfiFreqXlatVal26 - The sequencer start vector used when dfi_freq value is 26. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal26(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal26_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal26_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal27_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal27_SHIFT (12U)
/*! DfiFreqXlatVal27 - The sequencer start vector used when dfi_freq value is 27. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal27(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal27_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DfiFreqXlatVal27_MASK)
/*! @} */

/*! @name DFIFREQXLAT7 - DFI Frequency Translation Register 7 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal28_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal28_SHIFT (0U)
/*! DfiFreqXlatVal28 - The sequencer start vector used when dfi_freq value is 28. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal28(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal28_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal28_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal29_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal29_SHIFT (4U)
/*! DfiFreqXlatVal29 - The sequencer start vector used when dfi_freq value is 29. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal29(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal29_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal29_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal30_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal30_SHIFT (8U)
/*! DfiFreqXlatVal30 - The sequencer start vector used when dfi_freq value is 30. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal30(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal30_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal30_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal31_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal31_SHIFT (12U)
/*! DfiFreqXlatVal31 - The sequencer start vector used when dfi_freq value is 31. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal31(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal31_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DfiFreqXlatVal31_MASK)
/*! @} */

/*! @name TXRDPTRINIT - TxRdPtrInit control register */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TXRDPTRINIT_TxRdPtrInit_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_TXRDPTRINIT_TxRdPtrInit_SHIFT (0U)
/*! TxRdPtrInit - This register directly controls TxRdPtrInit, and is meant to be written by the
 *    PState sequencer as part of the power state switching sequence.
 */
#define DWC_DDRPHYA_MASTER_TXRDPTRINIT_TxRdPtrInit(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TXRDPTRINIT_TxRdPtrInit_SHIFT)) & DWC_DDRPHYA_MASTER_TXRDPTRINIT_TxRdPtrInit_MASK)
/*! @} */

/*! @name DFIINITCOMPLETE - DFI Init Complete control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIINITCOMPLETE_DfiInitComplete_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DFIINITCOMPLETE_DfiInitComplete_SHIFT (0U)
/*! DfiInitComplete - This register directly controls DfiInitComplete, and is meant to be written by
 *    the PState sequencer as part of the power state switching sequence.
 */
#define DWC_DDRPHYA_MASTER_DFIINITCOMPLETE_DfiInitComplete(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIINITCOMPLETE_DfiInitComplete_SHIFT)) & DWC_DDRPHYA_MASTER_DFIINITCOMPLETE_DfiInitComplete_MASK)
/*! @} */

/*! @name DFIFREQRATIO_P0 - DFI Frequency Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P0_DfiFreqRatio_p0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P0_DfiFreqRatio_p0_SHIFT (0U)
/*! DfiFreqRatio_p0 - Used in dwc_ddrphy_pub_serdes to serialize or de-serialize DFI signals 00 =
 *    1:1 mode 01 = 1:2 mode 1x = 1:4 mode* *Note: 1:4 is for future pub revision.
 */
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P0_DfiFreqRatio_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQRATIO_P0_DfiFreqRatio_p0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQRATIO_P0_DfiFreqRatio_p0_MASK)
/*! @} */

/*! @name RXFIFOCHECKS - Enable more frequent consistency checks of the RX FIFOs */
/*! @{ */

#define DWC_DDRPHYA_MASTER_RXFIFOCHECKS_DoFrequentRxFifoChecks_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_RXFIFOCHECKS_DoFrequentRxFifoChecks_SHIFT (0U)
/*! DoFrequentRxFifoChecks - When 0, read data FIFO pointer consistency checks are performed only during sideband transactions (i. */
#define DWC_DDRPHYA_MASTER_RXFIFOCHECKS_DoFrequentRxFifoChecks(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_RXFIFOCHECKS_DoFrequentRxFifoChecks_SHIFT)) & DWC_DDRPHYA_MASTER_RXFIFOCHECKS_DoFrequentRxFifoChecks_MASK)
/*! @} */

/*! @name MTESTDTOCTRL -  */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MTESTDTOCTRL_MTestDtoCtrl_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_MTESTDTOCTRL_MTestDtoCtrl_SHIFT (0U)
/*! MTestDtoCtrl - MTESTdtoEn==[0], dwc_ddrphy_dto will be squelched (0) MTESTdtoEn==[1],
 *    dwc_ddrphy_dto will reflect the observability signal multiplexed on MTestCombo
 */
#define DWC_DDRPHYA_MASTER_MTESTDTOCTRL_MTestDtoCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MTESTDTOCTRL_MTestDtoCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_MTESTDTOCTRL_MTestDtoCtrl_MASK)
/*! @} */

/*! @name MAPCAA0TODFI - Maps PHY CAA lane 0 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA0TODFI_MapCAA0toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA0TODFI_MapCAA0toDfi_SHIFT (0U)
/*! MapCAA0toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 0. */
#define DWC_DDRPHYA_MASTER_MAPCAA0TODFI_MapCAA0toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA0TODFI_MapCAA0toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA0TODFI_MapCAA0toDfi_MASK)
/*! @} */

/*! @name MAPCAA1TODFI - Maps PHY CAA lane 1 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA1TODFI_MapCAA1toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA1TODFI_MapCAA1toDfi_SHIFT (0U)
/*! MapCAA1toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 1. */
#define DWC_DDRPHYA_MASTER_MAPCAA1TODFI_MapCAA1toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA1TODFI_MapCAA1toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA1TODFI_MapCAA1toDfi_MASK)
/*! @} */

/*! @name MAPCAA2TODFI - Maps PHY CAA lane 2 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA2TODFI_MapCAA2toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA2TODFI_MapCAA2toDfi_SHIFT (0U)
/*! MapCAA2toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 2. */
#define DWC_DDRPHYA_MASTER_MAPCAA2TODFI_MapCAA2toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA2TODFI_MapCAA2toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA2TODFI_MapCAA2toDfi_MASK)
/*! @} */

/*! @name MAPCAA3TODFI - Maps PHY CAA lane 3 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA3TODFI_MapCAA3toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA3TODFI_MapCAA3toDfi_SHIFT (0U)
/*! MapCAA3toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 3. */
#define DWC_DDRPHYA_MASTER_MAPCAA3TODFI_MapCAA3toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA3TODFI_MapCAA3toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA3TODFI_MapCAA3toDfi_MASK)
/*! @} */

/*! @name MAPCAA4TODFI - Maps PHY CAA lane 4 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA4TODFI_MapCAA4toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA4TODFI_MapCAA4toDfi_SHIFT (0U)
/*! MapCAA4toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 4. */
#define DWC_DDRPHYA_MASTER_MAPCAA4TODFI_MapCAA4toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA4TODFI_MapCAA4toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA4TODFI_MapCAA4toDfi_MASK)
/*! @} */

/*! @name MAPCAA5TODFI - Maps PHY CAA lane 5 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA5TODFI_MapCAA5toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA5TODFI_MapCAA5toDfi_SHIFT (0U)
/*! MapCAA5toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 5. */
#define DWC_DDRPHYA_MASTER_MAPCAA5TODFI_MapCAA5toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA5TODFI_MapCAA5toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA5TODFI_MapCAA5toDfi_MASK)
/*! @} */

/*! @name MAPCAA6TODFI - Maps PHY CAA lane 6 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA6TODFI_MapCAA6toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA6TODFI_MapCAA6toDfi_SHIFT (0U)
/*! MapCAA6toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 6. */
#define DWC_DDRPHYA_MASTER_MAPCAA6TODFI_MapCAA6toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA6TODFI_MapCAA6toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA6TODFI_MapCAA6toDfi_MASK)
/*! @} */

/*! @name MAPCAA7TODFI - Maps PHY CAA lane 7 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA7TODFI_MapCAA7toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA7TODFI_MapCAA7toDfi_SHIFT (0U)
/*! MapCAA7toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 7. */
#define DWC_DDRPHYA_MASTER_MAPCAA7TODFI_MapCAA7toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA7TODFI_MapCAA7toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA7TODFI_MapCAA7toDfi_MASK)
/*! @} */

/*! @name MAPCAA8TODFI - Maps PHY CAA lane 8 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA8TODFI_MapCAA8toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA8TODFI_MapCAA8toDfi_SHIFT (0U)
/*! MapCAA8toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 8. */
#define DWC_DDRPHYA_MASTER_MAPCAA8TODFI_MapCAA8toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA8TODFI_MapCAA8toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA8TODFI_MapCAA8toDfi_MASK)
/*! @} */

/*! @name MAPCAA9TODFI - Maps PHY CAA lane 9 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA9TODFI_MapCAA9toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA9TODFI_MapCAA9toDfi_SHIFT (0U)
/*! MapCAA9toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 9. */
#define DWC_DDRPHYA_MASTER_MAPCAA9TODFI_MapCAA9toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA9TODFI_MapCAA9toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA9TODFI_MapCAA9toDfi_MASK)
/*! @} */

/*! @name MAPCAB0TODFI - Maps PHY CAB lane 0 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB0TODFI_MapCAB0toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB0TODFI_MapCAB0toDfi_SHIFT (0U)
/*! MapCAB0toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 0. */
#define DWC_DDRPHYA_MASTER_MAPCAB0TODFI_MapCAB0toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB0TODFI_MapCAB0toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB0TODFI_MapCAB0toDfi_MASK)
/*! @} */

/*! @name MAPCAB1TODFI - Maps PHY CAB lane 1 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB1TODFI_MapCAB1toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB1TODFI_MapCAB1toDfi_SHIFT (0U)
/*! MapCAB1toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 1. */
#define DWC_DDRPHYA_MASTER_MAPCAB1TODFI_MapCAB1toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB1TODFI_MapCAB1toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB1TODFI_MapCAB1toDfi_MASK)
/*! @} */

/*! @name MAPCAB2TODFI - Maps PHY CAB lane 2 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB2TODFI_MapCAB2toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB2TODFI_MapCAB2toDfi_SHIFT (0U)
/*! MapCAB2toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 2. */
#define DWC_DDRPHYA_MASTER_MAPCAB2TODFI_MapCAB2toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB2TODFI_MapCAB2toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB2TODFI_MapCAB2toDfi_MASK)
/*! @} */

/*! @name MAPCAB3TODFI - Maps PHY CAB lane 3 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB3TODFI_MapCAB3toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB3TODFI_MapCAB3toDfi_SHIFT (0U)
/*! MapCAB3toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 3. */
#define DWC_DDRPHYA_MASTER_MAPCAB3TODFI_MapCAB3toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB3TODFI_MapCAB3toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB3TODFI_MapCAB3toDfi_MASK)
/*! @} */

/*! @name MAPCAB4TODFI - Maps PHY CAB lane 4 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB4TODFI_MapCAB4toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB4TODFI_MapCAB4toDfi_SHIFT (0U)
/*! MapCAB4toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 4. */
#define DWC_DDRPHYA_MASTER_MAPCAB4TODFI_MapCAB4toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB4TODFI_MapCAB4toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB4TODFI_MapCAB4toDfi_MASK)
/*! @} */

/*! @name MAPCAB5TODFI - Maps PHY CAB lane 5 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB5TODFI_MapCAB5toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB5TODFI_MapCAB5toDfi_SHIFT (0U)
/*! MapCAB5toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 5. */
#define DWC_DDRPHYA_MASTER_MAPCAB5TODFI_MapCAB5toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB5TODFI_MapCAB5toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB5TODFI_MapCAB5toDfi_MASK)
/*! @} */

/*! @name MAPCAB6TODFI - Maps PHY CAB lane 6 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB6TODFI_MapCAB6toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB6TODFI_MapCAB6toDfi_SHIFT (0U)
/*! MapCAB6toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 6. */
#define DWC_DDRPHYA_MASTER_MAPCAB6TODFI_MapCAB6toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB6TODFI_MapCAB6toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB6TODFI_MapCAB6toDfi_MASK)
/*! @} */

/*! @name MAPCAB7TODFI - Maps PHY CAB lane 7 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB7TODFI_MapCAB7toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB7TODFI_MapCAB7toDfi_SHIFT (0U)
/*! MapCAB7toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 7. */
#define DWC_DDRPHYA_MASTER_MAPCAB7TODFI_MapCAB7toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB7TODFI_MapCAB7toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB7TODFI_MapCAB7toDfi_MASK)
/*! @} */

/*! @name MAPCAB8TODFI - Maps PHY CAB lane 8 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB8TODFI_MapCAB8toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB8TODFI_MapCAB8toDfi_SHIFT (0U)
/*! MapCAB8toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 8. */
#define DWC_DDRPHYA_MASTER_MAPCAB8TODFI_MapCAB8toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB8TODFI_MapCAB8toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB8TODFI_MapCAB8toDfi_MASK)
/*! @} */

/*! @name MAPCAB9TODFI - Maps PHY CAB lane 9 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB9TODFI_MapCAB9toDfi_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB9TODFI_MapCAB9toDfi_SHIFT (0U)
/*! MapCAB9toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 9. */
#define DWC_DDRPHYA_MASTER_MAPCAB9TODFI_MapCAB9toDfi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB9TODFI_MapCAB9toDfi_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB9TODFI_MapCAB9toDfi_MASK)
/*! @} */

/*! @name PHYINTERRUPTENABLE - Interrupt Enable Bits */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyTrngCmpltEn_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyTrngCmpltEn_SHIFT (0U)
/*! PhyTrngCmpltEn - Enable for the PHY Training Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyTrngCmpltEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyTrngCmpltEn_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyTrngCmpltEn_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyInitCmpltEn_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyInitCmpltEn_SHIFT (1U)
/*! PhyInitCmpltEn - Enable for the PHY Initialization Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyInitCmpltEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyInitCmpltEn_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyInitCmpltEn_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyTrngFailEn_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyTrngFailEn_SHIFT (2U)
/*! PhyTrngFailEn - Enable for the PHY Training Failure interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyTrngFailEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyTrngFailEn_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyTrngFailEn_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyFWReservedEn_MASK (0xF8U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyFWReservedEn_SHIFT (3U)
/*! PhyFWReservedEn - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyFWReservedEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyFWReservedEn_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyFWReservedEn_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyVTDriftAlarmEn_MASK (0x300U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyVTDriftAlarmEn_SHIFT (8U)
/*! PhyVTDriftAlarmEn - Enable for the PHY VT Drift Alarm interrupts. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyVTDriftAlarmEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyVTDriftAlarmEn_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyVTDriftAlarmEn_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyRxFifoCheckEn_MASK (0x400U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyRxFifoCheckEn_SHIFT (10U)
/*! PhyRxFifoCheckEn - Enable for the RxFifo Pointers Check Interrupt 0 : Interrupt not enabled 1 : Interrupt enabled */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyRxFifoCheckEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyRxFifoCheckEn_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyRxFifoCheckEn_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyHWReservedEn_MASK (0xF800U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyHWReservedEn_SHIFT (11U)
/*! PhyHWReservedEn - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyHWReservedEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyHWReservedEn_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PhyHWReservedEn_MASK)
/*! @} */

/*! @name PHYINTERRUPTFWCONTROL - Interrupt Firmware Control Bits */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyTrngCmpltFW_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyTrngCmpltFW_SHIFT (0U)
/*! PhyTrngCmpltFW - PHY Training Complete Firmware interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyTrngCmpltFW(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyTrngCmpltFW_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyTrngCmpltFW_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyInitCmpltFW_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyInitCmpltFW_SHIFT (1U)
/*! PhyInitCmpltFW - PHY Initialization Complete Firmware interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyInitCmpltFW(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyInitCmpltFW_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyInitCmpltFW_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyTrngFailFW_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyTrngFailFW_SHIFT (2U)
/*! PhyTrngFailFW - PHY Training Failure Firmware interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyTrngFailFW(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyTrngFailFW_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyTrngFailFW_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyFWReservedFW_MASK (0xF8U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyFWReservedFW_SHIFT (3U)
/*! PhyFWReservedFW - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyFWReservedFW(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyFWReservedFW_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PhyFWReservedFW_MASK)
/*! @} */

/*! @name PHYINTERRUPTMASK - Interrupt Mask Bits */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyTrngCmpltMsk_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyTrngCmpltMsk_SHIFT (0U)
/*! PhyTrngCmpltMsk - Mask for the PHY Training Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyTrngCmpltMsk(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyTrngCmpltMsk_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyTrngCmpltMsk_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyInitCmpltMsk_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyInitCmpltMsk_SHIFT (1U)
/*! PhyInitCmpltMsk - Mask for the PHY Initialization Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyInitCmpltMsk(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyInitCmpltMsk_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyInitCmpltMsk_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyTrngFailMsk_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyTrngFailMsk_SHIFT (2U)
/*! PhyTrngFailMsk - Mask for the PHY Training Failure interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyTrngFailMsk(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyTrngFailMsk_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyTrngFailMsk_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyFWReservedMsk_MASK (0xF8U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyFWReservedMsk_SHIFT (3U)
/*! PhyFWReservedMsk - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyFWReservedMsk(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyFWReservedMsk_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyFWReservedMsk_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyVTDriftAlarmMsk_MASK (0x300U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyVTDriftAlarmMsk_SHIFT (8U)
/*! PhyVTDriftAlarmMsk - Mask for the PHY VT Drift Alarm interrupts. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyVTDriftAlarmMsk(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyVTDriftAlarmMsk_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyVTDriftAlarmMsk_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyRxFifoCheckMsk_MASK (0x400U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyRxFifoCheckMsk_SHIFT (10U)
/*! PhyRxFifoCheckMsk - Mask for the RxFifo Pointers Check Interrupt 0 : Interrupt not masked 1 : Interrupt masked */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyRxFifoCheckMsk(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyRxFifoCheckMsk_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyRxFifoCheckMsk_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyHWReservedMsk_MASK (0xF800U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyHWReservedMsk_SHIFT (11U)
/*! PhyHWReservedMsk - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyHWReservedMsk(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyHWReservedMsk_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PhyHWReservedMsk_MASK)
/*! @} */

/*! @name PHYINTERRUPTCLEAR - Interrupt Clear Bits */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyTrngCmpltClr_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyTrngCmpltClr_SHIFT (0U)
/*! PhyTrngCmpltClr - Clear for the PHY Training Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyTrngCmpltClr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyTrngCmpltClr_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyTrngCmpltClr_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyInitCmpltClr_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyInitCmpltClr_SHIFT (1U)
/*! PhyInitCmpltClr - Clear for the PHY Initialization Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyInitCmpltClr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyInitCmpltClr_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyInitCmpltClr_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyTrngFailClr_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyTrngFailClr_SHIFT (2U)
/*! PhyTrngFailClr - Clear for the PHY Training Failure interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyTrngFailClr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyTrngFailClr_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyTrngFailClr_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyFWReservedClr_MASK (0xF8U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyFWReservedClr_SHIFT (3U)
/*! PhyFWReservedClr - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyFWReservedClr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyFWReservedClr_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyFWReservedClr_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyVTDriftAlarmClr_MASK (0x300U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyVTDriftAlarmClr_SHIFT (8U)
/*! PhyVTDriftAlarmClr - Clear for the PHY VT Drift Alarm interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyVTDriftAlarmClr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyVTDriftAlarmClr_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyVTDriftAlarmClr_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyRxFifoCheckClr_MASK (0x400U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyRxFifoCheckClr_SHIFT (10U)
/*! PhyRxFifoCheckClr - Clear for the RxFifo Pointers Check Interrupt 0 : Interrupt not affected 1 : Interrupt cleared */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyRxFifoCheckClr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyRxFifoCheckClr_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyRxFifoCheckClr_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyHWReservedClr_MASK (0xF800U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyHWReservedClr_SHIFT (11U)
/*! PhyHWReservedClr - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyHWReservedClr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyHWReservedClr_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PhyHWReservedClr_MASK)
/*! @} */

/*! @name PHYINTERRUPTSTATUS - Interrupt Status Bits */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyTrngCmplt_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyTrngCmplt_SHIFT (0U)
/*! PhyTrngCmplt - PHY Training Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyTrngCmplt(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyTrngCmplt_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyTrngCmplt_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyInitCmplt_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyInitCmplt_SHIFT (1U)
/*! PhyInitCmplt - PHY Initialization Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyInitCmplt(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyInitCmplt_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyInitCmplt_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyTrngFail_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyTrngFail_SHIFT (2U)
/*! PhyTrngFail - PHY Training Failure interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyTrngFail(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyTrngFail_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyTrngFail_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyFWReserved_MASK (0xF8U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyFWReserved_SHIFT (3U)
/*! PhyFWReserved - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyFWReserved(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyFWReserved_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyFWReserved_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_VTDriftAlarm_MASK (0x300U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_VTDriftAlarm_SHIFT (8U)
/*! VTDriftAlarm - PHY VT Drift Alarm interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_VTDriftAlarm(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_VTDriftAlarm_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_VTDriftAlarm_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyRxFifoCheck_MASK (0x400U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyRxFifoCheck_SHIFT (10U)
/*! PhyRxFifoCheck - A mechanism in the PHY checks the Read Fifo pointers for consistency at times they are idle. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyRxFifoCheck(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyRxFifoCheck_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyRxFifoCheck_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyHWReserved_MASK (0xF800U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyHWReserved_SHIFT (11U)
/*! PhyHWReserved - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyHWReserved(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyHWReserved_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PhyHWReserved_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS0 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS0_HwtSwizzleHwtAddress0_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS0_HwtSwizzleHwtAddress0_SHIFT (0U)
/*! HwtSwizzleHwtAddress0 - This set of registers is used in DDR3/DDR4 mode where a user has re-mapped the DFI inputs to the PHY. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS0_HwtSwizzleHwtAddress0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS0_HwtSwizzleHwtAddress0_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS0_HwtSwizzleHwtAddress0_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS1 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS1_HwtSwizzleHwtAddress1_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS1_HwtSwizzleHwtAddress1_SHIFT (0U)
/*! HwtSwizzleHwtAddress1 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS1_HwtSwizzleHwtAddress1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS1_HwtSwizzleHwtAddress1_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS1_HwtSwizzleHwtAddress1_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS2 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS2_HwtSwizzleHwtAddress2_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS2_HwtSwizzleHwtAddress2_SHIFT (0U)
/*! HwtSwizzleHwtAddress2 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS2_HwtSwizzleHwtAddress2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS2_HwtSwizzleHwtAddress2_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS2_HwtSwizzleHwtAddress2_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS3 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS3_HwtSwizzleHwtAddress3_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS3_HwtSwizzleHwtAddress3_SHIFT (0U)
/*! HwtSwizzleHwtAddress3 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS3_HwtSwizzleHwtAddress3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS3_HwtSwizzleHwtAddress3_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS3_HwtSwizzleHwtAddress3_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS4 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS4_HwtSwizzleHwtAddress4_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS4_HwtSwizzleHwtAddress4_SHIFT (0U)
/*! HwtSwizzleHwtAddress4 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS4_HwtSwizzleHwtAddress4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS4_HwtSwizzleHwtAddress4_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS4_HwtSwizzleHwtAddress4_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS5 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS5_HwtSwizzleHwtAddress5_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS5_HwtSwizzleHwtAddress5_SHIFT (0U)
/*! HwtSwizzleHwtAddress5 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS5_HwtSwizzleHwtAddress5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS5_HwtSwizzleHwtAddress5_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS5_HwtSwizzleHwtAddress5_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS6 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS6_HwtSwizzleHwtAddress6_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS6_HwtSwizzleHwtAddress6_SHIFT (0U)
/*! HwtSwizzleHwtAddress6 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS6_HwtSwizzleHwtAddress6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS6_HwtSwizzleHwtAddress6_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS6_HwtSwizzleHwtAddress6_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS7 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS7_HwtSwizzleHwtAddress7_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS7_HwtSwizzleHwtAddress7_SHIFT (0U)
/*! HwtSwizzleHwtAddress7 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS7_HwtSwizzleHwtAddress7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS7_HwtSwizzleHwtAddress7_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS7_HwtSwizzleHwtAddress7_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS8 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS8_HwtSwizzleHwtAddress8_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS8_HwtSwizzleHwtAddress8_SHIFT (0U)
/*! HwtSwizzleHwtAddress8 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS8_HwtSwizzleHwtAddress8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS8_HwtSwizzleHwtAddress8_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS8_HwtSwizzleHwtAddress8_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS9 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS9_HwtSwizzleHwtAddress9_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS9_HwtSwizzleHwtAddress9_SHIFT (0U)
/*! HwtSwizzleHwtAddress9 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS9_HwtSwizzleHwtAddress9(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS9_HwtSwizzleHwtAddress9_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS9_HwtSwizzleHwtAddress9_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS10 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS10_HwtSwizzleHwtAddress10_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS10_HwtSwizzleHwtAddress10_SHIFT (0U)
/*! HwtSwizzleHwtAddress10 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS10_HwtSwizzleHwtAddress10(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS10_HwtSwizzleHwtAddress10_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS10_HwtSwizzleHwtAddress10_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS11 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS11_HwtSwizzleHwtAddress11_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS11_HwtSwizzleHwtAddress11_SHIFT (0U)
/*! HwtSwizzleHwtAddress11 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS11_HwtSwizzleHwtAddress11(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS11_HwtSwizzleHwtAddress11_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS11_HwtSwizzleHwtAddress11_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS12 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS12_HwtSwizzleHwtAddress12_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS12_HwtSwizzleHwtAddress12_SHIFT (0U)
/*! HwtSwizzleHwtAddress12 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS12_HwtSwizzleHwtAddress12(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS12_HwtSwizzleHwtAddress12_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS12_HwtSwizzleHwtAddress12_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS13 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS13_HwtSwizzleHwtAddress13_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS13_HwtSwizzleHwtAddress13_SHIFT (0U)
/*! HwtSwizzleHwtAddress13 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS13_HwtSwizzleHwtAddress13(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS13_HwtSwizzleHwtAddress13_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS13_HwtSwizzleHwtAddress13_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS14 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS14_HwtSwizzleHwtAddress14_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS14_HwtSwizzleHwtAddress14_SHIFT (0U)
/*! HwtSwizzleHwtAddress14 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS14_HwtSwizzleHwtAddress14(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS14_HwtSwizzleHwtAddress14_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS14_HwtSwizzleHwtAddress14_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS15 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS15_HwtSwizzleHwtAddress15_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS15_HwtSwizzleHwtAddress15_SHIFT (0U)
/*! HwtSwizzleHwtAddress15 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS15_HwtSwizzleHwtAddress15(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS15_HwtSwizzleHwtAddress15_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS15_HwtSwizzleHwtAddress15_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS17 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS17_HwtSwizzleHwtAddress17_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS17_HwtSwizzleHwtAddress17_SHIFT (0U)
/*! HwtSwizzleHwtAddress17 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS17_HwtSwizzleHwtAddress17(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS17_HwtSwizzleHwtAddress17_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS17_HwtSwizzleHwtAddress17_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTACTN - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTACTN_HwtSwizzleHwtActN_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTACTN_HwtSwizzleHwtActN_SHIFT (0U)
/*! HwtSwizzleHwtActN - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTACTN_HwtSwizzleHwtActN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTACTN_HwtSwizzleHwtActN_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTACTN_HwtSwizzleHwtActN_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTBANK0 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK0_HwtSwizzleHwtBank0_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK0_HwtSwizzleHwtBank0_SHIFT (0U)
/*! HwtSwizzleHwtBank0 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK0_HwtSwizzleHwtBank0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK0_HwtSwizzleHwtBank0_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK0_HwtSwizzleHwtBank0_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTBANK1 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK1_HwtSwizzleHwtBank1_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK1_HwtSwizzleHwtBank1_SHIFT (0U)
/*! HwtSwizzleHwtBank1 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK1_HwtSwizzleHwtBank1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK1_HwtSwizzleHwtBank1_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK1_HwtSwizzleHwtBank1_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTBANK2 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK2_HwtSwizzleHwtBank2_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK2_HwtSwizzleHwtBank2_SHIFT (0U)
/*! HwtSwizzleHwtBank2 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK2_HwtSwizzleHwtBank2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK2_HwtSwizzleHwtBank2_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK2_HwtSwizzleHwtBank2_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTBG0 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG0_HwtSwizzleHwtBg0_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG0_HwtSwizzleHwtBg0_SHIFT (0U)
/*! HwtSwizzleHwtBg0 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG0_HwtSwizzleHwtBg0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG0_HwtSwizzleHwtBg0_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG0_HwtSwizzleHwtBg0_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTBG1 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG1_HwtSwizzleHwtBg1_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG1_HwtSwizzleHwtBg1_SHIFT (0U)
/*! HwtSwizzleHwtBg1 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG1_HwtSwizzleHwtBg1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG1_HwtSwizzleHwtBg1_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG1_HwtSwizzleHwtBg1_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTCASN - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTCASN_HwtSwizzleHwtCasN_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTCASN_HwtSwizzleHwtCasN_SHIFT (0U)
/*! HwtSwizzleHwtCasN - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTCASN_HwtSwizzleHwtCasN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTCASN_HwtSwizzleHwtCasN_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTCASN_HwtSwizzleHwtCasN_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTRASN - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTRASN_HwtSwizzleHwtRasN_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTRASN_HwtSwizzleHwtRasN_SHIFT (0U)
/*! HwtSwizzleHwtRasN - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTRASN_HwtSwizzleHwtRasN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTRASN_HwtSwizzleHwtRasN_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTRASN_HwtSwizzleHwtRasN_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTWEN - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTWEN_HwtSwizzleHwtWeN_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTWEN_HwtSwizzleHwtWeN_SHIFT (0U)
/*! HwtSwizzleHwtWeN - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTWEN_HwtSwizzleHwtWeN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTWEN_HwtSwizzleHwtWeN_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTWEN_HwtSwizzleHwtWeN_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTPARITYIN - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTPARITYIN_HwtSwizzleHwtParityIn_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTPARITYIN_HwtSwizzleHwtParityIn_SHIFT (0U)
/*! HwtSwizzleHwtParityIn - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTPARITYIN_HwtSwizzleHwtParityIn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTPARITYIN_HwtSwizzleHwtParityIn_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTPARITYIN_HwtSwizzleHwtParityIn_MASK)
/*! @} */

/*! @name DFIHANDSHAKEDELAYS0 - Add assertion/deassertion delays on handshake signals Logic assumes that dfi signal assertions exceed the programmed delays */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PhyUpdAckDelay0_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PhyUpdAckDelay0_SHIFT (0U)
/*! PhyUpdAckDelay0 - Adds 0-15 DfiClks of delay after dfi0_phyupd_ack asserts, before the PHY takes
 *    any action (such as starting DDL calibration).
 */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PhyUpdAckDelay0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PhyUpdAckDelay0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PhyUpdAckDelay0_MASK)

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PhyUpdReqDelay0_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PhyUpdReqDelay0_SHIFT (4U)
/*! PhyUpdReqDelay0 - Adds 0-15 DfiClks of delay after the PHY completes all PHY update activities, before deasserting dfi0_phyupd_req. */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PhyUpdReqDelay0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PhyUpdReqDelay0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PhyUpdReqDelay0_MASK)

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CtrlUpdAckDelay0_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CtrlUpdAckDelay0_SHIFT (8U)
/*! CtrlUpdAckDelay0 - Adds 0-15 DfiClks of delay after dfi0_ctrlupd_req asserts, before the PHY takes any action. */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CtrlUpdAckDelay0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CtrlUpdAckDelay0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CtrlUpdAckDelay0_MASK)

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CtrlUpdReqDelay0_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CtrlUpdReqDelay0_SHIFT (12U)
/*! CtrlUpdReqDelay0 - Adds 0-15 DfiClks of delay after the PHY completes all PHY update activities, before deasserting dfi0_ctrlupd_ack. */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CtrlUpdReqDelay0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CtrlUpdReqDelay0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CtrlUpdReqDelay0_MASK)
/*! @} */

/*! @name DFIHANDSHAKEDELAYS1 - Add assertion/deassertion delays on handshake signals Logic assumes that dfi signal assertions exceed the programmed delays */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PhyUpdAckDelay1_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PhyUpdAckDelay1_SHIFT (0U)
/*! PhyUpdAckDelay1 - Adds 0-15 DfiClks of delay after dfi1_phyupd_ack asserts, before the PHY takes
 *    any action (such as starting DDL calibration).
 */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PhyUpdAckDelay1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PhyUpdAckDelay1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PhyUpdAckDelay1_MASK)

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PhyUpdReqDelay1_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PhyUpdReqDelay1_SHIFT (4U)
/*! PhyUpdReqDelay1 - Adds 0-15 DfiClks of delay after the PHY completes all PHY update activities, before deasserting dfi1_phyupd_req. */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PhyUpdReqDelay1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PhyUpdReqDelay1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PhyUpdReqDelay1_MASK)

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CtrlUpdAckDelay1_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CtrlUpdAckDelay1_SHIFT (8U)
/*! CtrlUpdAckDelay1 - Adds 0-15 DfiClks of delay after dfi1_ctrlupd_req asserts, before the PHY takes any action. */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CtrlUpdAckDelay1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CtrlUpdAckDelay1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CtrlUpdAckDelay1_MASK)

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CtrlUpdReqDelay1_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CtrlUpdReqDelay1_SHIFT (12U)
/*! CtrlUpdReqDelay1 - Adds 0-15 DfiClks of delay after the PHY completes all PHY update activities, before deasserting dfi1_ctrlupd_ack. */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CtrlUpdReqDelay1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CtrlUpdReqDelay1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CtrlUpdReqDelay1_MASK)
/*! @} */

/*! @name CALUCLKINFO_P1 - Impedance Calibration Clock Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P1_CalUClkTicksPer1uS_MASK (0x3FFU)
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P1_CalUClkTicksPer1uS_SHIFT (0U)
/*! CalUClkTicksPer1uS - Must be programmed to the number of DfiClks in 1us (rounded up), with minimum value of 24. */
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P1_CalUClkTicksPer1uS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALUCLKINFO_P1_CalUClkTicksPer1uS_SHIFT)) & DWC_DDRPHYA_MASTER_CALUCLKINFO_P1_CalUClkTicksPer1uS_MASK)
/*! @} */

/*! @name SEQ0BDLY0_P1 - PHY Initialization Engine (PIE) Delay Register 0 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P1_Seq0BDLY0_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P1_Seq0BDLY0_p1_SHIFT (0U)
/*! Seq0BDLY0_p1 - PHY Initialization Engine (PIE) Delay Register 0 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P1_Seq0BDLY0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY0_P1_Seq0BDLY0_p1_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY0_P1_Seq0BDLY0_p1_MASK)
/*! @} */

/*! @name SEQ0BDLY1_P1 - PHY Initialization Engine (PIE) Delay Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P1_Seq0BDLY1_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P1_Seq0BDLY1_p1_SHIFT (0U)
/*! Seq0BDLY1_p1 - PHY Initialization Engine (PIE) Delay Register 1 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P1_Seq0BDLY1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY1_P1_Seq0BDLY1_p1_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY1_P1_Seq0BDLY1_p1_MASK)
/*! @} */

/*! @name SEQ0BDLY2_P1 - PHY Initialization Engine (PIE) Delay Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P1_Seq0BDLY2_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P1_Seq0BDLY2_p1_SHIFT (0U)
/*! Seq0BDLY2_p1 - PHY Initialization Engine (PIE) Delay Register 2 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P1_Seq0BDLY2_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY2_P1_Seq0BDLY2_p1_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY2_P1_Seq0BDLY2_p1_MASK)
/*! @} */

/*! @name SEQ0BDLY3_P1 - PHY Initialization Engine (PIE) Delay Register 3 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P1_Seq0BDLY3_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P1_Seq0BDLY3_p1_SHIFT (0U)
/*! Seq0BDLY3_p1 - PHY Initialization Engine (PIE) Delay Register 3 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P1_Seq0BDLY3_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY3_P1_Seq0BDLY3_p1_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY3_P1_Seq0BDLY3_p1_MASK)
/*! @} */

/*! @name PPTTRAINSETUP_P1 - Setup Intervals for DFI PHY Master operations */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PhyMstrTrainInterval_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PhyMstrTrainInterval_SHIFT (0U)
/*! PhyMstrTrainInterval - Bits 3:0 of this register specifies the time between the end of one training and the start of the next. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PhyMstrTrainInterval(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PhyMstrTrainInterval_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PhyMstrTrainInterval_MASK)

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PhyMstrMaxReqToAck_MASK (0x70U)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PhyMstrMaxReqToAck_SHIFT (4U)
/*! PhyMstrMaxReqToAck - Bits 6:4 of this register specify the max time from tdfi_phymstr_req asserted to tdfi_phymstr_ack asserted. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PhyMstrMaxReqToAck(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PhyMstrMaxReqToAck_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PhyMstrMaxReqToAck_MASK)
/*! @} */

/*! @name TRISTATEMODECA_P1 - Mode select register for MEMCLK/Address/Command Tristates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DisDynAdrTri_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DisDynAdrTri_SHIFT (0U)
/*! DisDynAdrTri - When DisDynAdrTri=1, Dynamic Tristating is disabled. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DisDynAdrTri(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DisDynAdrTri_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DisDynAdrTri_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DDR2TMode_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DDR2TMode_SHIFT (1U)
/*! DDR2TMode - Must be set to 1 for Dynamic Tristate to work when CA bus is 2T or Geardown mode. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DDR2TMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DDR2TMode_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DDR2TMode_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_CkDisVal_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_CkDisVal_SHIFT (2U)
/*! CkDisVal - The PHY provides 4 memory clocks, n=0. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_CkDisVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_CkDisVal_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_CkDisVal_MASK)
/*! @} */

/*! @name HWTMRL_P1 - HWT MaxReadLatency. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTMRL_P1_HwtMRL_p1_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTMRL_P1_HwtMRL_p1_SHIFT (0U)
/*! HwtMRL_p1 - This Max Read Latency CSR is to be trained to ensure the rx-data fifo is not read
 *    until after all dbytes have their read data valid.
 */
#define DWC_DDRPHYA_MASTER_HWTMRL_P1_HwtMRL_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTMRL_P1_HwtMRL_p1_SHIFT)) & DWC_DDRPHYA_MASTER_HWTMRL_P1_HwtMRL_p1_MASK)
/*! @} */

/*! @name DQSPREAMBLECONTROL_P1 - Control the PHY logic related to the read and write DQS preamble */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TwoTckRxDqsPre_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TwoTckRxDqsPre_SHIFT (0U)
/*! TwoTckRxDqsPre - Widens the RxDqsEn window to allow larger drift in the incoming read DQS to
 *    take advantage of the larger/wider preamble generated by the DRAMSs when the D4 DRAMS are
 *    configured with DDR4 MR4 A11 Read Preamble=1 for causing a 2nCK read preamble.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TwoTckRxDqsPre(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TwoTckRxDqsPre_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TwoTckRxDqsPre_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TwoTckTxDqsPre_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TwoTckTxDqsPre_SHIFT (1U)
/*! TwoTckTxDqsPre - 0: Standard 1tck TxDqs Preamble 1: Enable Optional D4 2tck TxDqs Preamble The
 *    DDR4 MR4 A12 is Write Preamble, 1=2nCK, 0=1nCK.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TwoTckTxDqsPre(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TwoTckTxDqsPre_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TwoTckTxDqsPre_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_PositionDfeInit_MASK (0x1CU)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_PositionDfeInit_SHIFT (2U)
/*! PositionDfeInit - For DDR4 phy only when receive DFE is enabled. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_PositionDfeInit(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_PositionDfeInit_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_PositionDfeInit_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4TglTwoTckTxDqsPre_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4TglTwoTckTxDqsPre_SHIFT (5U)
/*! LP4TglTwoTckTxDqsPre - Used in LPDDR4 mode to modify the early preamble when Register
 *    TwoTckTxDqsPre=1 0: level first-memclk preamble 1: toggling first-memclk preamble
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4TglTwoTckTxDqsPre(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4TglTwoTckTxDqsPre_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4TglTwoTckTxDqsPre_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4PostambleExt_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4PostambleExt_SHIFT (6U)
/*! LP4PostambleExt - In LPDDR4 mode must be set to extend the write postamble. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4PostambleExt(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4PostambleExt_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4PostambleExt_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4SttcPreBridgeRxEn_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4SttcPreBridgeRxEn_SHIFT (7U)
/*! LP4SttcPreBridgeRxEn - Used in LPDDR4 static-preamble mode to bridge the RxEn between two reads
 *    to the same timing group when the bubble is 1 memclk.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4SttcPreBridgeRxEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4SttcPreBridgeRxEn_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4SttcPreBridgeRxEn_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_WDQSEXTENSION_MASK (0x100U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_WDQSEXTENSION_SHIFT (8U)
/*! WDQSEXTENSION - When set, DQS_T and DQS_C will be driven differentially to 0 and 1,
 *    respectively, before and after a write burst, except during a memory read transaction.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_WDQSEXTENSION(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_WDQSEXTENSION_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_WDQSEXTENSION_MASK)
/*! @} */

/*! @name DMIPINPRESENT_P1 - This Register is used to enable the Read-DBI function in each DBYTE */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P1_RdDbiEnabled_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P1_RdDbiEnabled_SHIFT (0U)
/*! RdDbiEnabled - This bit must be set to 1'b1 if Read-DBI is enabled in a connected DDR4 or LPDDR4 device. */
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P1_RdDbiEnabled(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DMIPINPRESENT_P1_RdDbiEnabled_SHIFT)) & DWC_DDRPHYA_MASTER_DMIPINPRESENT_P1_RdDbiEnabled_MASK)
/*! @} */

/*! @name ARDPTRINITVAL_P1 - Address/Command FIFO ReadPointer Initial Value */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P1_ARdPtrInitVal_p1_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P1_ARdPtrInitVal_p1_SHIFT (0U)
/*! ARdPtrInitVal_p1 - This is the initial Pointer Offset for the free-running FIFOs in the DBYTE and ACX4 hardips. */
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P1_ARdPtrInitVal_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P1_ARdPtrInitVal_p1_SHIFT)) & DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P1_ARdPtrInitVal_p1_MASK)
/*! @} */

/*! @name PROCODTTIMECTL_P1 - READ DATA On-Die Termination Timing Control (by PHY) */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_POdtTailWidth_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_POdtTailWidth_SHIFT (0U)
/*! POdtTailWidth - controls the length of the tail of ProcOdt, units of UI 3 tail 3UI more than for
 *    Register POdtTailWidth=0, maximum 2 tail 2UI more than for Register POdtTailWidth=0, default
 *    1 tail 1UI more than for Register POdtTailWidth=0 0 minimum length tail The time from ProcODT
 *    to closing the window to receive DQS to ProcODT POdtTailWidth is (2 + POdtTailWidth) UI
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_POdtTailWidth(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_POdtTailWidth_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_POdtTailWidth_MASK)

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_POdtStartDelay_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_POdtStartDelay_SHIFT (2U)
/*! POdtStartDelay - controls the start of ProcOdt, units of UI 3 delay start 2 UI, maximum delay of
 *    start of ProcOdt 2 delay start 1 UI, 1 delay start 0 UI, default 0 early by 1 UI, The time
 *    from ProcODT assertion to opening the window to receive DQS is (10 - POdtStartDelay) UI.
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_POdtStartDelay(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_POdtStartDelay_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_POdtStartDelay_MASK)
/*! @} */

/*! @name DLLGAINCTL_P1 - DLL gain control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllGainIV_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllGainIV_SHIFT (0U)
/*! DllGainIV - Initial value of DllGain. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllGainIV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllGainIV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllGainIV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllGainTV_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllGainTV_SHIFT (4U)
/*! DllGainTV - Terminal value of DllGain, ie the value in effect when locking is done and the value
 *    used for maintaining lock, ie tracking pclk variation.
 */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllGainTV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllGainTV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllGainTV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllSeedSel_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllSeedSel_SHIFT (8U)
/*! DllSeedSel - Reserved, must be configured to be 0. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllSeedSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllSeedSel_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DllSeedSel_MASK)
/*! @} */

/*! @name DFIRDDATACSDESTMAP_P1 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm0_SHIFT (0U)
/*! DfiRdDestm0 - Maps dfi_rddata_cs_n_p0[0] to dest DfiRdDestm0 timing For example, if 0
 *    dfi_rddata_cs_n_p0[0] will use Register RxEn,ClkDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm0_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm1_SHIFT (2U)
/*! DfiRdDestm1 - Maps dfi_rddata_cs_n_p0[1] to dest DfiRdDestm1 timing For example, if 1
 *    dfi_rddata_cs_n[_p01] will use Register RxEn,ClkDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm1_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm2_SHIFT (4U)
/*! DfiRdDestm2 - Maps dfi_rddata_cs_n_p0[2] to dest DfiRdDestm2 timing For example, if 2
 *    dfi_rddata_cs_n_p0[2] will use Register RxEn,ClkDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm2_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm3_SHIFT (6U)
/*! DfiRdDestm3 - Maps dfi_rddata_cs_n_p0[3] to dest DfiRdDestm3 timing For example, if 3
 *    dfi_rddata_cs_n_p0[3] will use Register RxEn,ClkDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DfiRdDestm3_MASK)
/*! @} */

/*! @name VREFINGLOBAL_P1 - PHY Global Vref Controls */
/*! @{ */

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInSel_MASK (0x7U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInSel_SHIFT (0U)
/*! GlobalVrefInSel - GlobalVrefInSel[1:0] controls the mode of the PHY VREF DAC and the BP_VREF pin
 *    ========================================================== 2'b00 - PHY Vref DAC Range0 --
 *    BP_VREF = Hi-Z 2'b01 - Reserved Encoding 2'b10 - PHY Vref DAC Range0 -- BP_VREF connected to PLL
 *    Analog Bus 2'b11 - PHY Vref DAC Range0 -- BP_VREF connected to PHY Vref DAC
 *    ========================================================== GlobalVrefInSel[2] shall be set according to Dram
 *    Protocol: Protocol GlobalVrefInSel[2] ------------------------------------------ DDR3 1'b0 DDR4
 *    1'b0 LPDDR3 1'b0 LPDDR4 1'b1
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInSel_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInSel_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInDAC_MASK (0x3F8U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInDAC_SHIFT (3U)
/*! GlobalVrefInDAC - DAC code for internal Vref generation The DAC has two ranges; the range is set
 *    by GlobalVrefInSel[2] ========================================================== RANGE0 :
 *    DDR3,DDR4,LPDDR3 [GlobalVrefInSel[2] = 0] DAC Output Voltage = GlobalVrefInDAC == 6'h00 ? Hi-Z :
 *    0.
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInDAC(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInDAC_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInDAC_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInTrim_MASK (0x3C00U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInTrim_SHIFT (10U)
/*! GlobalVrefInTrim - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInTrim(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInTrim_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInTrim_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInMode_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInMode_SHIFT (14U)
/*! GlobalVrefInMode - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInMode_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GlobalVrefInMode_MASK)
/*! @} */

/*! @name DFIWRDATACSDESTMAP_P1 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm0_SHIFT (0U)
/*! DfiWrDestm0 - Maps dfi_wrdata_cs_n_p0[0] to dest DfiWrDestm0 timing For example, if 0
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm0_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm1_SHIFT (2U)
/*! DfiWrDestm1 - Maps dfi_wrdata_cs_n_p0[1] to dest DfiWrDestm1 timing For example, if 1
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm1_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm2_SHIFT (4U)
/*! DfiWrDestm2 - Maps dfi_wrdata_cs_n_p0[2] to dest DfiWrDestm2 timing For example, if 2
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm2_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm3_SHIFT (6U)
/*! DfiWrDestm3 - Maps dfi_wrdata_cs_n_p0[3] to dest DfiWrDestm3 timing (use Register
 *    TxDq,DqsDlyTg3) For example, if 3 dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DfiWrDestm3_MASK)
/*! @} */

/*! @name PLLCTRL2_P1 - PState dependent PLL Control Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL2_P1_PllFreqSel_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P1_PllFreqSel_SHIFT (0U)
/*! PllFreqSel - Adjusts the loop parameters to compensate for different VCO bias points, and input/output clock division ratios. */
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P1_PllFreqSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL2_P1_PllFreqSel_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL2_P1_PllFreqSel_MASK)
/*! @} */

/*! @name PLLCTRL1_P1 - PState dependent PLL Control Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PllCpIntCtrl_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PllCpIntCtrl_SHIFT (0U)
/*! PllCpIntCtrl - connects directly to cp_int_cntrl<1:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PllCpIntCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PllCpIntCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PllCpIntCtrl_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PllCpPropCtrl_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PllCpPropCtrl_SHIFT (5U)
/*! PllCpPropCtrl - connects directly to cp_prop_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PllCpPropCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PllCpPropCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PllCpPropCtrl_MASK)
/*! @} */

/*! @name PLLTESTMODE_P1 - Additional controls for PLL CP/VCO modes of operation */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P1_PllTestMode_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P1_PllTestMode_p1_SHIFT (0U)
/*! PllTestMode_p1 - It is required to use default values for this CSR unless directed otherwise by Synopsys. */
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P1_PllTestMode_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLTESTMODE_P1_PllTestMode_p1_SHIFT)) & DWC_DDRPHYA_MASTER_PLLTESTMODE_P1_PllTestMode_p1_MASK)
/*! @} */

/*! @name PLLCTRL4_P1 - PState dependent PLL Control Register 4 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PllCpIntGsCtrl_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PllCpIntGsCtrl_SHIFT (0U)
/*! PllCpIntGsCtrl - connects directly to cp_int_gs_cntrl<4:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PllCpIntGsCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PllCpIntGsCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PllCpIntGsCtrl_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PllCpPropGsCtrl_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PllCpPropGsCtrl_SHIFT (5U)
/*! PllCpPropGsCtrl - connects directly to cp_prop_gs_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PllCpPropGsCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PllCpPropGsCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PllCpPropGsCtrl_MASK)
/*! @} */

/*! @name DFIFREQRATIO_P1 - DFI Frequency Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P1_DfiFreqRatio_p1_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P1_DfiFreqRatio_p1_SHIFT (0U)
/*! DfiFreqRatio_p1 - Used in dwc_ddrphy_pub_serdes to serialize or de-serialize DFI signals 00 =
 *    1:1 mode 01 = 1:2 mode 1x = 1:4 mode* *Note: 1:4 is for future pub revision.
 */
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P1_DfiFreqRatio_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQRATIO_P1_DfiFreqRatio_p1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQRATIO_P1_DfiFreqRatio_p1_MASK)
/*! @} */

/*! @name CALUCLKINFO_P2 - Impedance Calibration Clock Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P2_CalUClkTicksPer1uS_MASK (0x3FFU)
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P2_CalUClkTicksPer1uS_SHIFT (0U)
/*! CalUClkTicksPer1uS - Must be programmed to the number of DfiClks in 1us (rounded up), with minimum value of 24. */
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P2_CalUClkTicksPer1uS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALUCLKINFO_P2_CalUClkTicksPer1uS_SHIFT)) & DWC_DDRPHYA_MASTER_CALUCLKINFO_P2_CalUClkTicksPer1uS_MASK)
/*! @} */

/*! @name SEQ0BDLY0_P2 - PHY Initialization Engine (PIE) Delay Register 0 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P2_Seq0BDLY0_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P2_Seq0BDLY0_p2_SHIFT (0U)
/*! Seq0BDLY0_p2 - PHY Initialization Engine (PIE) Delay Register 0 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P2_Seq0BDLY0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY0_P2_Seq0BDLY0_p2_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY0_P2_Seq0BDLY0_p2_MASK)
/*! @} */

/*! @name SEQ0BDLY1_P2 - PHY Initialization Engine (PIE) Delay Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P2_Seq0BDLY1_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P2_Seq0BDLY1_p2_SHIFT (0U)
/*! Seq0BDLY1_p2 - PHY Initialization Engine (PIE) Delay Register 1 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P2_Seq0BDLY1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY1_P2_Seq0BDLY1_p2_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY1_P2_Seq0BDLY1_p2_MASK)
/*! @} */

/*! @name SEQ0BDLY2_P2 - PHY Initialization Engine (PIE) Delay Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P2_Seq0BDLY2_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P2_Seq0BDLY2_p2_SHIFT (0U)
/*! Seq0BDLY2_p2 - PHY Initialization Engine (PIE) Delay Register 2 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P2_Seq0BDLY2_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY2_P2_Seq0BDLY2_p2_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY2_P2_Seq0BDLY2_p2_MASK)
/*! @} */

/*! @name SEQ0BDLY3_P2 - PHY Initialization Engine (PIE) Delay Register 3 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P2_Seq0BDLY3_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P2_Seq0BDLY3_p2_SHIFT (0U)
/*! Seq0BDLY3_p2 - PHY Initialization Engine (PIE) Delay Register 3 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P2_Seq0BDLY3_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY3_P2_Seq0BDLY3_p2_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY3_P2_Seq0BDLY3_p2_MASK)
/*! @} */

/*! @name PPTTRAINSETUP_P2 - Setup Intervals for DFI PHY Master operations */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PhyMstrTrainInterval_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PhyMstrTrainInterval_SHIFT (0U)
/*! PhyMstrTrainInterval - Bits 3:0 of this register specifies the time between the end of one training and the start of the next. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PhyMstrTrainInterval(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PhyMstrTrainInterval_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PhyMstrTrainInterval_MASK)

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PhyMstrMaxReqToAck_MASK (0x70U)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PhyMstrMaxReqToAck_SHIFT (4U)
/*! PhyMstrMaxReqToAck - Bits 6:4 of this register specify the max time from tdfi_phymstr_req asserted to tdfi_phymstr_ack asserted. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PhyMstrMaxReqToAck(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PhyMstrMaxReqToAck_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PhyMstrMaxReqToAck_MASK)
/*! @} */

/*! @name TRISTATEMODECA_P2 - Mode select register for MEMCLK/Address/Command Tristates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DisDynAdrTri_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DisDynAdrTri_SHIFT (0U)
/*! DisDynAdrTri - When DisDynAdrTri=1, Dynamic Tristating is disabled. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DisDynAdrTri(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DisDynAdrTri_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DisDynAdrTri_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DDR2TMode_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DDR2TMode_SHIFT (1U)
/*! DDR2TMode - Must be set to 1 for Dynamic Tristate to work when CA bus is 2T or Geardown mode. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DDR2TMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DDR2TMode_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DDR2TMode_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_CkDisVal_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_CkDisVal_SHIFT (2U)
/*! CkDisVal - The PHY provides 4 memory clocks, n=0. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_CkDisVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_CkDisVal_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_CkDisVal_MASK)
/*! @} */

/*! @name HWTMRL_P2 - HWT MaxReadLatency. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTMRL_P2_HwtMRL_p2_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTMRL_P2_HwtMRL_p2_SHIFT (0U)
/*! HwtMRL_p2 - This Max Read Latency CSR is to be trained to ensure the rx-data fifo is not read
 *    until after all dbytes have their read data valid.
 */
#define DWC_DDRPHYA_MASTER_HWTMRL_P2_HwtMRL_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTMRL_P2_HwtMRL_p2_SHIFT)) & DWC_DDRPHYA_MASTER_HWTMRL_P2_HwtMRL_p2_MASK)
/*! @} */

/*! @name DQSPREAMBLECONTROL_P2 - Control the PHY logic related to the read and write DQS preamble */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TwoTckRxDqsPre_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TwoTckRxDqsPre_SHIFT (0U)
/*! TwoTckRxDqsPre - Widens the RxDqsEn window to allow larger drift in the incoming read DQS to
 *    take advantage of the larger/wider preamble generated by the DRAMSs when the D4 DRAMS are
 *    configured with DDR4 MR4 A11 Read Preamble=1 for causing a 2nCK read preamble.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TwoTckRxDqsPre(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TwoTckRxDqsPre_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TwoTckRxDqsPre_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TwoTckTxDqsPre_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TwoTckTxDqsPre_SHIFT (1U)
/*! TwoTckTxDqsPre - 0: Standard 1tck TxDqs Preamble 1: Enable Optional D4 2tck TxDqs Preamble The
 *    DDR4 MR4 A12 is Write Preamble, 1=2nCK, 0=1nCK.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TwoTckTxDqsPre(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TwoTckTxDqsPre_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TwoTckTxDqsPre_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_PositionDfeInit_MASK (0x1CU)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_PositionDfeInit_SHIFT (2U)
/*! PositionDfeInit - For DDR4 phy only when receive DFE is enabled. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_PositionDfeInit(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_PositionDfeInit_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_PositionDfeInit_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4TglTwoTckTxDqsPre_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4TglTwoTckTxDqsPre_SHIFT (5U)
/*! LP4TglTwoTckTxDqsPre - Used in LPDDR4 mode to modify the early preamble when Register
 *    TwoTckTxDqsPre=1 0: level first-memclk preamble 1: toggling first-memclk preamble
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4TglTwoTckTxDqsPre(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4TglTwoTckTxDqsPre_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4TglTwoTckTxDqsPre_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4PostambleExt_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4PostambleExt_SHIFT (6U)
/*! LP4PostambleExt - In LPDDR4 mode must be set to extend the write postamble. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4PostambleExt(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4PostambleExt_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4PostambleExt_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4SttcPreBridgeRxEn_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4SttcPreBridgeRxEn_SHIFT (7U)
/*! LP4SttcPreBridgeRxEn - Used in LPDDR4 static-preamble mode to bridge the RxEn between two reads
 *    to the same timing group when the bubble is 1 memclk.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4SttcPreBridgeRxEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4SttcPreBridgeRxEn_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4SttcPreBridgeRxEn_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_WDQSEXTENSION_MASK (0x100U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_WDQSEXTENSION_SHIFT (8U)
/*! WDQSEXTENSION - When set, DQS_T and DQS_C will be driven differentially to 0 and 1,
 *    respectively, before and after a write burst, except during a memory read transaction.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_WDQSEXTENSION(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_WDQSEXTENSION_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_WDQSEXTENSION_MASK)
/*! @} */

/*! @name DMIPINPRESENT_P2 - This Register is used to enable the Read-DBI function in each DBYTE */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P2_RdDbiEnabled_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P2_RdDbiEnabled_SHIFT (0U)
/*! RdDbiEnabled - This bit must be set to 1'b1 if Read-DBI is enabled in a connected DDR4 or LPDDR4 device. */
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P2_RdDbiEnabled(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DMIPINPRESENT_P2_RdDbiEnabled_SHIFT)) & DWC_DDRPHYA_MASTER_DMIPINPRESENT_P2_RdDbiEnabled_MASK)
/*! @} */

/*! @name ARDPTRINITVAL_P2 - Address/Command FIFO ReadPointer Initial Value */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P2_ARdPtrInitVal_p2_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P2_ARdPtrInitVal_p2_SHIFT (0U)
/*! ARdPtrInitVal_p2 - This is the initial Pointer Offset for the free-running FIFOs in the DBYTE and ACX4 hardips. */
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P2_ARdPtrInitVal_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P2_ARdPtrInitVal_p2_SHIFT)) & DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P2_ARdPtrInitVal_p2_MASK)
/*! @} */

/*! @name PROCODTTIMECTL_P2 - READ DATA On-Die Termination Timing Control (by PHY) */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_POdtTailWidth_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_POdtTailWidth_SHIFT (0U)
/*! POdtTailWidth - controls the length of the tail of ProcOdt, units of UI 3 tail 3UI more than for
 *    Register POdtTailWidth=0, maximum 2 tail 2UI more than for Register POdtTailWidth=0, default
 *    1 tail 1UI more than for Register POdtTailWidth=0 0 minimum length tail The time from ProcODT
 *    to closing the window to receive DQS to ProcODT POdtTailWidth is (2 + POdtTailWidth) UI
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_POdtTailWidth(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_POdtTailWidth_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_POdtTailWidth_MASK)

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_POdtStartDelay_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_POdtStartDelay_SHIFT (2U)
/*! POdtStartDelay - controls the start of ProcOdt, units of UI 3 delay start 2 UI, maximum delay of
 *    start of ProcOdt 2 delay start 1 UI, 1 delay start 0 UI, default 0 early by 1 UI, The time
 *    from ProcODT assertion to opening the window to receive DQS is (10 - POdtStartDelay) UI.
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_POdtStartDelay(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_POdtStartDelay_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_POdtStartDelay_MASK)
/*! @} */

/*! @name DLLGAINCTL_P2 - DLL gain control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllGainIV_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllGainIV_SHIFT (0U)
/*! DllGainIV - Initial value of DllGain. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllGainIV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllGainIV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllGainIV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllGainTV_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllGainTV_SHIFT (4U)
/*! DllGainTV - Terminal value of DllGain, ie the value in effect when locking is done and the value
 *    used for maintaining lock, ie tracking pclk variation.
 */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllGainTV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllGainTV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllGainTV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllSeedSel_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllSeedSel_SHIFT (8U)
/*! DllSeedSel - Reserved, must be configured to be 0. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllSeedSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllSeedSel_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DllSeedSel_MASK)
/*! @} */

/*! @name DFIRDDATACSDESTMAP_P2 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm0_SHIFT (0U)
/*! DfiRdDestm0 - Maps dfi_rddata_cs_n_p0[0] to dest DfiRdDestm0 timing For example, if 0
 *    dfi_rddata_cs_n_p0[0] will use Register RxEn,ClkDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm0_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm1_SHIFT (2U)
/*! DfiRdDestm1 - Maps dfi_rddata_cs_n_p0[1] to dest DfiRdDestm1 timing For example, if 1
 *    dfi_rddata_cs_n[_p01] will use Register RxEn,ClkDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm1_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm2_SHIFT (4U)
/*! DfiRdDestm2 - Maps dfi_rddata_cs_n_p0[2] to dest DfiRdDestm2 timing For example, if 2
 *    dfi_rddata_cs_n_p0[2] will use Register RxEn,ClkDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm2_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm3_SHIFT (6U)
/*! DfiRdDestm3 - Maps dfi_rddata_cs_n_p0[3] to dest DfiRdDestm3 timing For example, if 3
 *    dfi_rddata_cs_n_p0[3] will use Register RxEn,ClkDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DfiRdDestm3_MASK)
/*! @} */

/*! @name VREFINGLOBAL_P2 - PHY Global Vref Controls */
/*! @{ */

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInSel_MASK (0x7U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInSel_SHIFT (0U)
/*! GlobalVrefInSel - GlobalVrefInSel[1:0] controls the mode of the PHY VREF DAC and the BP_VREF pin
 *    ========================================================== 2'b00 - PHY Vref DAC Range0 --
 *    BP_VREF = Hi-Z 2'b01 - Reserved Encoding 2'b10 - PHY Vref DAC Range0 -- BP_VREF connected to PLL
 *    Analog Bus 2'b11 - PHY Vref DAC Range0 -- BP_VREF connected to PHY Vref DAC
 *    ========================================================== GlobalVrefInSel[2] shall be set according to Dram
 *    Protocol: Protocol GlobalVrefInSel[2] ------------------------------------------ DDR3 1'b0 DDR4
 *    1'b0 LPDDR3 1'b0 LPDDR4 1'b1
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInSel_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInSel_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInDAC_MASK (0x3F8U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInDAC_SHIFT (3U)
/*! GlobalVrefInDAC - DAC code for internal Vref generation The DAC has two ranges; the range is set
 *    by GlobalVrefInSel[2] ========================================================== RANGE0 :
 *    DDR3,DDR4,LPDDR3 [GlobalVrefInSel[2] = 0] DAC Output Voltage = GlobalVrefInDAC == 6'h00 ? Hi-Z :
 *    0.
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInDAC(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInDAC_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInDAC_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInTrim_MASK (0x3C00U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInTrim_SHIFT (10U)
/*! GlobalVrefInTrim - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInTrim(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInTrim_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInTrim_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInMode_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInMode_SHIFT (14U)
/*! GlobalVrefInMode - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInMode_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GlobalVrefInMode_MASK)
/*! @} */

/*! @name DFIWRDATACSDESTMAP_P2 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm0_SHIFT (0U)
/*! DfiWrDestm0 - Maps dfi_wrdata_cs_n_p0[0] to dest DfiWrDestm0 timing For example, if 0
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm0_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm1_SHIFT (2U)
/*! DfiWrDestm1 - Maps dfi_wrdata_cs_n_p0[1] to dest DfiWrDestm1 timing For example, if 1
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm1_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm2_SHIFT (4U)
/*! DfiWrDestm2 - Maps dfi_wrdata_cs_n_p0[2] to dest DfiWrDestm2 timing For example, if 2
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm2_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm3_SHIFT (6U)
/*! DfiWrDestm3 - Maps dfi_wrdata_cs_n_p0[3] to dest DfiWrDestm3 timing (use Register
 *    TxDq,DqsDlyTg3) For example, if 3 dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DfiWrDestm3_MASK)
/*! @} */

/*! @name PLLCTRL2_P2 - PState dependent PLL Control Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL2_P2_PllFreqSel_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P2_PllFreqSel_SHIFT (0U)
/*! PllFreqSel - Adjusts the loop parameters to compensate for different VCO bias points, and input/output clock division ratios. */
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P2_PllFreqSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL2_P2_PllFreqSel_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL2_P2_PllFreqSel_MASK)
/*! @} */

/*! @name PLLCTRL1_P2 - PState dependent PLL Control Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PllCpIntCtrl_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PllCpIntCtrl_SHIFT (0U)
/*! PllCpIntCtrl - connects directly to cp_int_cntrl<1:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PllCpIntCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PllCpIntCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PllCpIntCtrl_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PllCpPropCtrl_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PllCpPropCtrl_SHIFT (5U)
/*! PllCpPropCtrl - connects directly to cp_prop_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PllCpPropCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PllCpPropCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PllCpPropCtrl_MASK)
/*! @} */

/*! @name PLLTESTMODE_P2 - Additional controls for PLL CP/VCO modes of operation */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P2_PllTestMode_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P2_PllTestMode_p2_SHIFT (0U)
/*! PllTestMode_p2 - It is required to use default values for this CSR unless directed otherwise by Synopsys. */
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P2_PllTestMode_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLTESTMODE_P2_PllTestMode_p2_SHIFT)) & DWC_DDRPHYA_MASTER_PLLTESTMODE_P2_PllTestMode_p2_MASK)
/*! @} */

/*! @name PLLCTRL4_P2 - PState dependent PLL Control Register 4 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PllCpIntGsCtrl_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PllCpIntGsCtrl_SHIFT (0U)
/*! PllCpIntGsCtrl - connects directly to cp_int_gs_cntrl<4:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PllCpIntGsCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PllCpIntGsCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PllCpIntGsCtrl_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PllCpPropGsCtrl_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PllCpPropGsCtrl_SHIFT (5U)
/*! PllCpPropGsCtrl - connects directly to cp_prop_gs_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PllCpPropGsCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PllCpPropGsCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PllCpPropGsCtrl_MASK)
/*! @} */

/*! @name DFIFREQRATIO_P2 - DFI Frequency Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P2_DfiFreqRatio_p2_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P2_DfiFreqRatio_p2_SHIFT (0U)
/*! DfiFreqRatio_p2 - Used in dwc_ddrphy_pub_serdes to serialize or de-serialize DFI signals 00 =
 *    1:1 mode 01 = 1:2 mode 1x = 1:4 mode* *Note: 1:4 is for future pub revision.
 */
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P2_DfiFreqRatio_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQRATIO_P2_DfiFreqRatio_p2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQRATIO_P2_DfiFreqRatio_p2_MASK)
/*! @} */

/*! @name CALUCLKINFO_P3 - Impedance Calibration Clock Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P3_CalUClkTicksPer1uS_MASK (0x3FFU)
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P3_CalUClkTicksPer1uS_SHIFT (0U)
/*! CalUClkTicksPer1uS - Must be programmed to the number of DfiClks in 1us (rounded up), with minimum value of 24. */
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P3_CalUClkTicksPer1uS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALUCLKINFO_P3_CalUClkTicksPer1uS_SHIFT)) & DWC_DDRPHYA_MASTER_CALUCLKINFO_P3_CalUClkTicksPer1uS_MASK)
/*! @} */

/*! @name SEQ0BDLY0_P3 - PHY Initialization Engine (PIE) Delay Register 0 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P3_Seq0BDLY0_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P3_Seq0BDLY0_p3_SHIFT (0U)
/*! Seq0BDLY0_p3 - PHY Initialization Engine (PIE) Delay Register 0 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P3_Seq0BDLY0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY0_P3_Seq0BDLY0_p3_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY0_P3_Seq0BDLY0_p3_MASK)
/*! @} */

/*! @name SEQ0BDLY1_P3 - PHY Initialization Engine (PIE) Delay Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P3_Seq0BDLY1_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P3_Seq0BDLY1_p3_SHIFT (0U)
/*! Seq0BDLY1_p3 - PHY Initialization Engine (PIE) Delay Register 1 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P3_Seq0BDLY1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY1_P3_Seq0BDLY1_p3_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY1_P3_Seq0BDLY1_p3_MASK)
/*! @} */

/*! @name SEQ0BDLY2_P3 - PHY Initialization Engine (PIE) Delay Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P3_Seq0BDLY2_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P3_Seq0BDLY2_p3_SHIFT (0U)
/*! Seq0BDLY2_p3 - PHY Initialization Engine (PIE) Delay Register 2 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P3_Seq0BDLY2_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY2_P3_Seq0BDLY2_p3_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY2_P3_Seq0BDLY2_p3_MASK)
/*! @} */

/*! @name SEQ0BDLY3_P3 - PHY Initialization Engine (PIE) Delay Register 3 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P3_Seq0BDLY3_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P3_Seq0BDLY3_p3_SHIFT (0U)
/*! Seq0BDLY3_p3 - PHY Initialization Engine (PIE) Delay Register 3 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P3_Seq0BDLY3_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY3_P3_Seq0BDLY3_p3_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY3_P3_Seq0BDLY3_p3_MASK)
/*! @} */

/*! @name PPTTRAINSETUP_P3 - Setup Intervals for DFI PHY Master operations */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PhyMstrTrainInterval_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PhyMstrTrainInterval_SHIFT (0U)
/*! PhyMstrTrainInterval - Bits 3:0 of this register specifies the time between the end of one training and the start of the next. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PhyMstrTrainInterval(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PhyMstrTrainInterval_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PhyMstrTrainInterval_MASK)

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PhyMstrMaxReqToAck_MASK (0x70U)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PhyMstrMaxReqToAck_SHIFT (4U)
/*! PhyMstrMaxReqToAck - Bits 6:4 of this register specify the max time from tdfi_phymstr_req asserted to tdfi_phymstr_ack asserted. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PhyMstrMaxReqToAck(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PhyMstrMaxReqToAck_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PhyMstrMaxReqToAck_MASK)
/*! @} */

/*! @name TRISTATEMODECA_P3 - Mode select register for MEMCLK/Address/Command Tristates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DisDynAdrTri_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DisDynAdrTri_SHIFT (0U)
/*! DisDynAdrTri - When DisDynAdrTri=1, Dynamic Tristating is disabled. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DisDynAdrTri(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DisDynAdrTri_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DisDynAdrTri_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DDR2TMode_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DDR2TMode_SHIFT (1U)
/*! DDR2TMode - Must be set to 1 for Dynamic Tristate to work when CA bus is 2T or Geardown mode. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DDR2TMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DDR2TMode_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DDR2TMode_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_CkDisVal_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_CkDisVal_SHIFT (2U)
/*! CkDisVal - The PHY provides 4 memory clocks, n=0. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_CkDisVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_CkDisVal_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_CkDisVal_MASK)
/*! @} */

/*! @name HWTMRL_P3 - HWT MaxReadLatency. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTMRL_P3_HwtMRL_p3_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTMRL_P3_HwtMRL_p3_SHIFT (0U)
/*! HwtMRL_p3 - This Max Read Latency CSR is to be trained to ensure the rx-data fifo is not read
 *    until after all dbytes have their read data valid.
 */
#define DWC_DDRPHYA_MASTER_HWTMRL_P3_HwtMRL_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTMRL_P3_HwtMRL_p3_SHIFT)) & DWC_DDRPHYA_MASTER_HWTMRL_P3_HwtMRL_p3_MASK)
/*! @} */

/*! @name DQSPREAMBLECONTROL_P3 - Control the PHY logic related to the read and write DQS preamble */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TwoTckRxDqsPre_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TwoTckRxDqsPre_SHIFT (0U)
/*! TwoTckRxDqsPre - Widens the RxDqsEn window to allow larger drift in the incoming read DQS to
 *    take advantage of the larger/wider preamble generated by the DRAMSs when the D4 DRAMS are
 *    configured with DDR4 MR4 A11 Read Preamble=1 for causing a 2nCK read preamble.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TwoTckRxDqsPre(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TwoTckRxDqsPre_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TwoTckRxDqsPre_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TwoTckTxDqsPre_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TwoTckTxDqsPre_SHIFT (1U)
/*! TwoTckTxDqsPre - 0: Standard 1tck TxDqs Preamble 1: Enable Optional D4 2tck TxDqs Preamble The
 *    DDR4 MR4 A12 is Write Preamble, 1=2nCK, 0=1nCK.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TwoTckTxDqsPre(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TwoTckTxDqsPre_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TwoTckTxDqsPre_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_PositionDfeInit_MASK (0x1CU)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_PositionDfeInit_SHIFT (2U)
/*! PositionDfeInit - For DDR4 phy only when receive DFE is enabled. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_PositionDfeInit(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_PositionDfeInit_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_PositionDfeInit_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4TglTwoTckTxDqsPre_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4TglTwoTckTxDqsPre_SHIFT (5U)
/*! LP4TglTwoTckTxDqsPre - Used in LPDDR4 mode to modify the early preamble when Register
 *    TwoTckTxDqsPre=1 0: level first-memclk preamble 1: toggling first-memclk preamble
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4TglTwoTckTxDqsPre(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4TglTwoTckTxDqsPre_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4TglTwoTckTxDqsPre_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4PostambleExt_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4PostambleExt_SHIFT (6U)
/*! LP4PostambleExt - In LPDDR4 mode must be set to extend the write postamble. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4PostambleExt(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4PostambleExt_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4PostambleExt_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4SttcPreBridgeRxEn_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4SttcPreBridgeRxEn_SHIFT (7U)
/*! LP4SttcPreBridgeRxEn - Used in LPDDR4 static-preamble mode to bridge the RxEn between two reads
 *    to the same timing group when the bubble is 1 memclk.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4SttcPreBridgeRxEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4SttcPreBridgeRxEn_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4SttcPreBridgeRxEn_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_WDQSEXTENSION_MASK (0x100U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_WDQSEXTENSION_SHIFT (8U)
/*! WDQSEXTENSION - When set, DQS_T and DQS_C will be driven differentially to 0 and 1,
 *    respectively, before and after a write burst, except during a memory read transaction.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_WDQSEXTENSION(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_WDQSEXTENSION_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_WDQSEXTENSION_MASK)
/*! @} */

/*! @name DMIPINPRESENT_P3 - This Register is used to enable the Read-DBI function in each DBYTE */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P3_RdDbiEnabled_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P3_RdDbiEnabled_SHIFT (0U)
/*! RdDbiEnabled - This bit must be set to 1'b1 if Read-DBI is enabled in a connected DDR4 or LPDDR4 device. */
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P3_RdDbiEnabled(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DMIPINPRESENT_P3_RdDbiEnabled_SHIFT)) & DWC_DDRPHYA_MASTER_DMIPINPRESENT_P3_RdDbiEnabled_MASK)
/*! @} */

/*! @name ARDPTRINITVAL_P3 - Address/Command FIFO ReadPointer Initial Value */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P3_ARdPtrInitVal_p3_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P3_ARdPtrInitVal_p3_SHIFT (0U)
/*! ARdPtrInitVal_p3 - This is the initial Pointer Offset for the free-running FIFOs in the DBYTE and ACX4 hardips. */
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P3_ARdPtrInitVal_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P3_ARdPtrInitVal_p3_SHIFT)) & DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P3_ARdPtrInitVal_p3_MASK)
/*! @} */

/*! @name PROCODTTIMECTL_P3 - READ DATA On-Die Termination Timing Control (by PHY) */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_POdtTailWidth_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_POdtTailWidth_SHIFT (0U)
/*! POdtTailWidth - controls the length of the tail of ProcOdt, units of UI 3 tail 3UI more than for
 *    Register POdtTailWidth=0, maximum 2 tail 2UI more than for Register POdtTailWidth=0, default
 *    1 tail 1UI more than for Register POdtTailWidth=0 0 minimum length tail The time from ProcODT
 *    to closing the window to receive DQS to ProcODT POdtTailWidth is (2 + POdtTailWidth) UI
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_POdtTailWidth(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_POdtTailWidth_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_POdtTailWidth_MASK)

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_POdtStartDelay_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_POdtStartDelay_SHIFT (2U)
/*! POdtStartDelay - controls the start of ProcOdt, units of UI 3 delay start 2 UI, maximum delay of
 *    start of ProcOdt 2 delay start 1 UI, 1 delay start 0 UI, default 0 early by 1 UI, The time
 *    from ProcODT assertion to opening the window to receive DQS is (10 - POdtStartDelay) UI.
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_POdtStartDelay(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_POdtStartDelay_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_POdtStartDelay_MASK)
/*! @} */

/*! @name DLLGAINCTL_P3 - DLL gain control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllGainIV_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllGainIV_SHIFT (0U)
/*! DllGainIV - Initial value of DllGain. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllGainIV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllGainIV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllGainIV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllGainTV_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllGainTV_SHIFT (4U)
/*! DllGainTV - Terminal value of DllGain, ie the value in effect when locking is done and the value
 *    used for maintaining lock, ie tracking pclk variation.
 */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllGainTV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllGainTV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllGainTV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllSeedSel_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllSeedSel_SHIFT (8U)
/*! DllSeedSel - Reserved, must be configured to be 0. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllSeedSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllSeedSel_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DllSeedSel_MASK)
/*! @} */

/*! @name DFIRDDATACSDESTMAP_P3 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm0_SHIFT (0U)
/*! DfiRdDestm0 - Maps dfi_rddata_cs_n_p0[0] to dest DfiRdDestm0 timing For example, if 0
 *    dfi_rddata_cs_n_p0[0] will use Register RxEn,ClkDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm0_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm1_SHIFT (2U)
/*! DfiRdDestm1 - Maps dfi_rddata_cs_n_p0[1] to dest DfiRdDestm1 timing For example, if 1
 *    dfi_rddata_cs_n[_p01] will use Register RxEn,ClkDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm1_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm2_SHIFT (4U)
/*! DfiRdDestm2 - Maps dfi_rddata_cs_n_p0[2] to dest DfiRdDestm2 timing For example, if 2
 *    dfi_rddata_cs_n_p0[2] will use Register RxEn,ClkDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm2_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm3_SHIFT (6U)
/*! DfiRdDestm3 - Maps dfi_rddata_cs_n_p0[3] to dest DfiRdDestm3 timing For example, if 3
 *    dfi_rddata_cs_n_p0[3] will use Register RxEn,ClkDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DfiRdDestm3_MASK)
/*! @} */

/*! @name VREFINGLOBAL_P3 - PHY Global Vref Controls */
/*! @{ */

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInSel_MASK (0x7U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInSel_SHIFT (0U)
/*! GlobalVrefInSel - GlobalVrefInSel[1:0] controls the mode of the PHY VREF DAC and the BP_VREF pin
 *    ========================================================== 2'b00 - PHY Vref DAC Range0 --
 *    BP_VREF = Hi-Z 2'b01 - Reserved Encoding 2'b10 - PHY Vref DAC Range0 -- BP_VREF connected to PLL
 *    Analog Bus 2'b11 - PHY Vref DAC Range0 -- BP_VREF connected to PHY Vref DAC
 *    ========================================================== GlobalVrefInSel[2] shall be set according to Dram
 *    Protocol: Protocol GlobalVrefInSel[2] ------------------------------------------ DDR3 1'b0 DDR4
 *    1'b0 LPDDR3 1'b0 LPDDR4 1'b1
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInSel_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInSel_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInDAC_MASK (0x3F8U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInDAC_SHIFT (3U)
/*! GlobalVrefInDAC - DAC code for internal Vref generation The DAC has two ranges; the range is set
 *    by GlobalVrefInSel[2] ========================================================== RANGE0 :
 *    DDR3,DDR4,LPDDR3 [GlobalVrefInSel[2] = 0] DAC Output Voltage = GlobalVrefInDAC == 6'h00 ? Hi-Z :
 *    0.
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInDAC(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInDAC_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInDAC_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInTrim_MASK (0x3C00U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInTrim_SHIFT (10U)
/*! GlobalVrefInTrim - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInTrim(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInTrim_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInTrim_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInMode_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInMode_SHIFT (14U)
/*! GlobalVrefInMode - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInMode_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GlobalVrefInMode_MASK)
/*! @} */

/*! @name DFIWRDATACSDESTMAP_P3 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm0_SHIFT (0U)
/*! DfiWrDestm0 - Maps dfi_wrdata_cs_n_p0[0] to dest DfiWrDestm0 timing For example, if 0
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm0_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm1_SHIFT (2U)
/*! DfiWrDestm1 - Maps dfi_wrdata_cs_n_p0[1] to dest DfiWrDestm1 timing For example, if 1
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm1_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm2_SHIFT (4U)
/*! DfiWrDestm2 - Maps dfi_wrdata_cs_n_p0[2] to dest DfiWrDestm2 timing For example, if 2
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm2_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm3_SHIFT (6U)
/*! DfiWrDestm3 - Maps dfi_wrdata_cs_n_p0[3] to dest DfiWrDestm3 timing (use Register
 *    TxDq,DqsDlyTg3) For example, if 3 dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DfiWrDestm3_MASK)
/*! @} */

/*! @name PLLCTRL2_P3 - PState dependent PLL Control Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL2_P3_PllFreqSel_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P3_PllFreqSel_SHIFT (0U)
/*! PllFreqSel - Adjusts the loop parameters to compensate for different VCO bias points, and input/output clock division ratios. */
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P3_PllFreqSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL2_P3_PllFreqSel_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL2_P3_PllFreqSel_MASK)
/*! @} */

/*! @name PLLCTRL1_P3 - PState dependent PLL Control Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PllCpIntCtrl_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PllCpIntCtrl_SHIFT (0U)
/*! PllCpIntCtrl - connects directly to cp_int_cntrl<1:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PllCpIntCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PllCpIntCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PllCpIntCtrl_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PllCpPropCtrl_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PllCpPropCtrl_SHIFT (5U)
/*! PllCpPropCtrl - connects directly to cp_prop_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PllCpPropCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PllCpPropCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PllCpPropCtrl_MASK)
/*! @} */

/*! @name PLLTESTMODE_P3 - Additional controls for PLL CP/VCO modes of operation */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P3_PllTestMode_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P3_PllTestMode_p3_SHIFT (0U)
/*! PllTestMode_p3 - It is required to use default values for this CSR unless directed otherwise by Synopsys. */
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P3_PllTestMode_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLTESTMODE_P3_PllTestMode_p3_SHIFT)) & DWC_DDRPHYA_MASTER_PLLTESTMODE_P3_PllTestMode_p3_MASK)
/*! @} */

/*! @name PLLCTRL4_P3 - PState dependent PLL Control Register 4 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PllCpIntGsCtrl_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PllCpIntGsCtrl_SHIFT (0U)
/*! PllCpIntGsCtrl - connects directly to cp_int_gs_cntrl<4:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PllCpIntGsCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PllCpIntGsCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PllCpIntGsCtrl_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PllCpPropGsCtrl_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PllCpPropGsCtrl_SHIFT (5U)
/*! PllCpPropGsCtrl - connects directly to cp_prop_gs_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PllCpPropGsCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PllCpPropGsCtrl_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PllCpPropGsCtrl_MASK)
/*! @} */

/*! @name DFIFREQRATIO_P3 - DFI Frequency Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P3_DfiFreqRatio_p3_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P3_DfiFreqRatio_p3_SHIFT (0U)
/*! DfiFreqRatio_p3 - Used in dwc_ddrphy_pub_serdes to serialize or de-serialize DFI signals 00 =
 *    1:1 mode 01 = 1:2 mode 1x = 1:4 mode* *Note: 1:4 is for future pub revision.
 */
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P3_DfiFreqRatio_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQRATIO_P3_DfiFreqRatio_p3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQRATIO_P3_DfiFreqRatio_p3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_MASTER_Register_Masks */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_MASTER_Peripheral_Access_Layer */


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


#endif  /* PERI_DWC_DDRPHYA_MASTER_H_ */

