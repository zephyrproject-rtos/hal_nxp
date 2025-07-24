/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
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
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DWC_DDRPHYA_MASTER.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DWC_DDRPHYA_MASTER
 *
 * CMSIS Peripheral Access Layer for DWC_DDRPHYA_MASTER
 */

#if !defined(PERI_DWC_DDRPHYA_MASTER_H_)
#define PERI_DWC_DDRPHYA_MASTER_H_               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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

#define DWC_DDRPHYA_MASTER_RXFIFOINIT_RXFIFOINITPTR_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_RXFIFOINIT_RXFIFOINITPTR_SHIFT (0U)
/*! RxFifoInitPtr - Setting this bit will reset the PHY RXDATAFIFO read and write pointers. */
#define DWC_DDRPHYA_MASTER_RXFIFOINIT_RXFIFOINITPTR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_RXFIFOINIT_RXFIFOINITPTR_SHIFT)) & DWC_DDRPHYA_MASTER_RXFIFOINIT_RXFIFOINITPTR_MASK)

#define DWC_DDRPHYA_MASTER_RXFIFOINIT_INHIBITRXFIFORD_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_RXFIFOINIT_INHIBITRXFIFORD_SHIFT (1U)
/*! InhibitRxFifoRd - This field is reserved for training FW use. */
#define DWC_DDRPHYA_MASTER_RXFIFOINIT_INHIBITRXFIFORD(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_RXFIFOINIT_INHIBITRXFIFORD_SHIFT)) & DWC_DDRPHYA_MASTER_RXFIFOINIT_INHIBITRXFIFORD_MASK)
/*! @} */

/*! @name FORCECLKDISABLE - Clock gating control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_FORCECLKDISABLE_FORCECLKDISABLE_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_FORCECLKDISABLE_FORCECLKDISABLE_SHIFT (0U)
/*! ForceClkDisable - This CSR forces the gating of MEMCLKs driven from the PHY ForceClkDisable[0] -
 *    controls CLK_H/L0 ForceClkDisable[1] - controls CLK_H/L1 (if present) ForceClkDisable[2] -
 *    controls CLK_H/L2 (if present) ForceClkDisable[3] - controls CLK_H/L3 (if present)
 */
#define DWC_DDRPHYA_MASTER_FORCECLKDISABLE_FORCECLKDISABLE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_FORCECLKDISABLE_FORCECLKDISABLE_SHIFT)) & DWC_DDRPHYA_MASTER_FORCECLKDISABLE_FORCECLKDISABLE_MASK)
/*! @} */

/*! @name FORCEINTERNALUPDATE - This Register used by Training Firmware to force an internal PHY Update Event. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_FORCEINTERNALUPDATE_FORCEINTERNALUPDATE_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_FORCEINTERNALUPDATE_FORCEINTERNALUPDATE_SHIFT (0U)
/*! ForceInternalUpdate - This Register is used by Training Firmware to force an internal PHY Update Event. */
#define DWC_DDRPHYA_MASTER_FORCEINTERNALUPDATE_FORCEINTERNALUPDATE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_FORCEINTERNALUPDATE_FORCEINTERNALUPDATE_SHIFT)) & DWC_DDRPHYA_MASTER_FORCEINTERNALUPDATE_FORCEINTERNALUPDATE_MASK)
/*! @} */

/*! @name PHYCONFIG - Read Only displays PHY Configuration. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGANIBS_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGANIBS_SHIFT (0U)
/*! PhyConfigAnibs - Returns the following value . */
#define DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGANIBS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGANIBS_SHIFT)) & DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGANIBS_MASK)

#define DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGDBYTES_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGDBYTES_SHIFT (4U)
/*! PhyConfigDbytes - Returns the following value . */
#define DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGDBYTES(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGDBYTES_SHIFT)) & DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGDBYTES_MASK)

#define DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGDFI_MASK (0x300U)
#define DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGDFI_SHIFT (8U)
/*! PhyConfigDfi - Returns the following value . */
#define DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGDFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGDFI_SHIFT)) & DWC_DDRPHYA_MASTER_PHYCONFIG_PHYCONFIGDFI_MASK)
/*! @} */

/*! @name PGCR - PHY General Configuration Register(PGCR). */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PGCR_RXCLKRISEFALLMODE_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PGCR_RXCLKRISEFALLMODE_SHIFT (0U)
/*! RxClkRiseFallMode - This register field controls independent training for RxClk_c and RxClk_t. */
#define DWC_DDRPHYA_MASTER_PGCR_RXCLKRISEFALLMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PGCR_RXCLKRISEFALLMODE_SHIFT)) & DWC_DDRPHYA_MASTER_PGCR_RXCLKRISEFALLMODE_MASK)
/*! @} */

/*! @name TESTBUMPCNTRL1 - Test Bump Control1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTMAJORMODE_MASK (0x7U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTMAJORMODE_SHIFT (0U)
/*! TestMajorMode - Selects the major mode of operation for the receiver. */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTMAJORMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTMAJORMODE_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTMAJORMODE_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTBIASBYPASSEN_MASK (0x8U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTBIASBYPASSEN_SHIFT (3U)
/*! TestBiasBypassEn - Do not use, for debug only */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTBIASBYPASSEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTBIASBYPASSEN_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTBIASBYPASSEN_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTANALOGOUTCTRL_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTANALOGOUTCTRL_SHIFT (4U)
/*! TestAnalogOutCtrl - Select receiver internal analog signals to monitor at analog test point
 *    0xxx: AnalogTestOut=HiZ 1000: AnalogTestOut=VSS 1001: AnalogTestOut=vref_dfe0 -- observe by
 *    sweeping MALERTVrefLevel 1010: AnalogTestOut=vref_dfe1 -- observe by sweeping MALERTVrefLevel 1011:
 *    AnalogTestOut=VSS 1100: AnalogTestOut=vstg2 1101: AnalogTestOut=vcasc_cs1 1110:
 *    AnalogTestOut=vbias_cs1 Recommended mission mode default = 4'b0000
 */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTANALOGOUTCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTANALOGOUTCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTANALOGOUTCTRL_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTGAINCURRADJ_MASK (0x1F00U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTGAINCURRADJ_SHIFT (8U)
/*! TestGainCurrAdj - Adjust gain and current of analog observe RX amplifier stage at analog test
 *    point Recommended mission mode default = 5'b01011
 */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTGAINCURRADJ(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTGAINCURRADJ_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTGAINCURRADJ_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTSELEXTERNALVREF_MASK (0x2000U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTSELEXTERNALVREF_SHIFT (13U)
/*! TestSelExternalVref - Do not use, for debug only */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTSELEXTERNALVREF(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTSELEXTERNALVREF_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTSELEXTERNALVREF_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTEXTVREFRANGE_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTEXTVREFRANGE_SHIFT (14U)
/*! TestExtVrefRange - Setting this bit will extend the VREF DAC range for debug. */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTEXTVREFRANGE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTEXTVREFRANGE_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTEXTVREFRANGE_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTPOWERGATEEN_MASK (0x8000U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTPOWERGATEEN_SHIFT (15U)
/*! TestPowerGateEn - Do not use, for debug only */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTPOWERGATEEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTPOWERGATEEN_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL1_TESTPOWERGATEEN_MASK)
/*! @} */

/*! @name CALUCLKINFO_P0 - Impedance Calibration Clock Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P0_CALUCLKTICKSPER1US_MASK (0x3FFU)
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P0_CALUCLKTICKSPER1US_SHIFT (0U)
/*! CalUClkTicksPer1uS - Must be programmed to the number of DfiClks in 1us (rounded up), with minimum value of 24. */
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P0_CALUCLKTICKSPER1US(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALUCLKINFO_P0_CALUCLKTICKSPER1US_SHIFT)) & DWC_DDRPHYA_MASTER_CALUCLKINFO_P0_CALUCLKTICKSPER1US_MASK)
/*! @} */

/*! @name TESTBUMPCNTRL - Test Bump Control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPEN_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPEN_SHIFT (0U)
/*! TestBumpEn - Field TestBumpEn[1:0] controls the output function of: the signal BP_ALERT_N. */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPEN_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPEN_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPTOGGLE_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPTOGGLE_SHIFT (2U)
/*! TestBumpToggle - This field controls the output function of the signal Digital Observation Pin,
 *    if available in the configuration of the PHY.
 */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPTOGGLE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPTOGGLE_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPTOGGLE_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPDATASEL_MASK (0x1F8U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPDATASEL_SHIFT (3U)
/*! TestBumpDataSel - RVSD. */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPDATASEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPDATASEL_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_TESTBUMPDATASEL_MASK)

#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_FORCEMTESTONALERT_MASK (0x200U)
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_FORCEMTESTONALERT_SHIFT (9U)
/*! ForceMtestOnAlert - When set, causes the Digital Observation output pin to be driven onto BP_ALERT_N */
#define DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_FORCEMTESTONALERT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_FORCEMTESTONALERT_SHIFT)) & DWC_DDRPHYA_MASTER_TESTBUMPCNTRL_FORCEMTESTONALERT_MASK)
/*! @} */

/*! @name SEQ0BDLY0_P0 - PHY Initialization Engine (PIE) Delay Register 0 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P0_SEQ0BDLY0_P0_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P0_SEQ0BDLY0_P0_SHIFT (0U)
/*! Seq0BDLY0_p0 - PHY Initialization Engine (PIE) Delay Register 0 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P0_SEQ0BDLY0_P0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY0_P0_SEQ0BDLY0_P0_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY0_P0_SEQ0BDLY0_P0_MASK)
/*! @} */

/*! @name SEQ0BDLY1_P0 - PHY Initialization Engine (PIE) Delay Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P0_SEQ0BDLY1_P0_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P0_SEQ0BDLY1_P0_SHIFT (0U)
/*! Seq0BDLY1_p0 - PHY Initialization Engine (PIE) Delay Register 1 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P0_SEQ0BDLY1_P0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY1_P0_SEQ0BDLY1_P0_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY1_P0_SEQ0BDLY1_P0_MASK)
/*! @} */

/*! @name SEQ0BDLY2_P0 - PHY Initialization Engine (PIE) Delay Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P0_SEQ0BDLY2_P0_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P0_SEQ0BDLY2_P0_SHIFT (0U)
/*! Seq0BDLY2_p0 - PHY Initialization Engine (PIE) Delay Register 2 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P0_SEQ0BDLY2_P0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY2_P0_SEQ0BDLY2_P0_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY2_P0_SEQ0BDLY2_P0_MASK)
/*! @} */

/*! @name SEQ0BDLY3_P0 - PHY Initialization Engine (PIE) Delay Register 3 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P0_SEQ0BDLY3_P0_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P0_SEQ0BDLY3_P0_SHIFT (0U)
/*! Seq0BDLY3_p0 - PHY Initialization Engine (PIE) Delay Register 3 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P0_SEQ0BDLY3_P0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY3_P0_SEQ0BDLY3_P0_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY3_P0_SEQ0BDLY3_P0_MASK)
/*! @} */

/*! @name PHYALERTSTATUS - PHY Alert status bit */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYALERTSTATUS_PHYALERT_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PHYALERTSTATUS_PHYALERT_SHIFT (0U)
/*! PhyAlert - Current state of ALERT_N. */
#define DWC_DDRPHYA_MASTER_PHYALERTSTATUS_PHYALERT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYALERTSTATUS_PHYALERT_SHIFT)) & DWC_DDRPHYA_MASTER_PHYALERTSTATUS_PHYALERT_MASK)
/*! @} */

/*! @name PPTTRAINSETUP_P0 - Setup Intervals for DFI PHY Master operations */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PHYMSTRTRAININTERVAL_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PHYMSTRTRAININTERVAL_SHIFT (0U)
/*! PhyMstrTrainInterval - Bits 3:0 of this register specifies the time between the end of one training and the start of the next. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PHYMSTRTRAININTERVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PHYMSTRTRAININTERVAL_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PHYMSTRTRAININTERVAL_MASK)

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PHYMSTRMAXREQTOACK_MASK (0x70U)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PHYMSTRMAXREQTOACK_SHIFT (4U)
/*! PhyMstrMaxReqToAck - Bits 6:4 of this register specify the max time from tdfi_phymstr_req asserted to tdfi_phymstr_ack asserted. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PHYMSTRMAXREQTOACK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PHYMSTRMAXREQTOACK_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P0_PHYMSTRMAXREQTOACK_MASK)
/*! @} */

/*! @name ATESTMODE - ATestMode control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ATESTMODE_ATESTPRBSEN_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_ATESTMODE_ATESTPRBSEN_SHIFT (0U)
/*! ATestPrbsEn - Enables loopback PRBS7 testing of all the DDR output pins in this chiplet. */
#define DWC_DDRPHYA_MASTER_ATESTMODE_ATESTPRBSEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ATESTMODE_ATESTPRBSEN_SHIFT)) & DWC_DDRPHYA_MASTER_ATESTMODE_ATESTPRBSEN_MASK)

#define DWC_DDRPHYA_MASTER_ATESTMODE_ATESTCLKEN_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_ATESTMODE_ATESTCLKEN_SHIFT (1U)
/*! ATestClkEn - Enables the clock for loopback PRBS7 testing for all BP_A* pins. */
#define DWC_DDRPHYA_MASTER_ATESTMODE_ATESTCLKEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ATESTMODE_ATESTCLKEN_SHIFT)) & DWC_DDRPHYA_MASTER_ATESTMODE_ATESTCLKEN_MASK)

#define DWC_DDRPHYA_MASTER_ATESTMODE_ATESTMODESEL_MASK (0x1CU)
#define DWC_DDRPHYA_MASTER_ATESTMODE_ATESTMODESEL_SHIFT (2U)
/*! ATestModeSel - Master Mode select for ATest (Loopback) 000 - Mission mode, all ATest disabled,
 *    loopback receivers powered down 001 - External Loopback mode [Single data rate pattern -
 *    dfi_cas sent to all lanes] 010 - Internal Loopback mode [Single data rate pattern] 011 - Internal
 *    Loopback mode [Double data rate pattern] 100 - External Loopback mode [Single data rate pattern
 *    - corresponding DFI signal sent to each lane]
 */
#define DWC_DDRPHYA_MASTER_ATESTMODE_ATESTMODESEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ATESTMODE_ATESTMODESEL_SHIFT)) & DWC_DDRPHYA_MASTER_ATESTMODE_ATESTMODESEL_MASK)
/*! @} */

/*! @name TXCALBINP - TX P Impedance Calibration observation */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TXCALBINP_TXCALBINP_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_TXCALBINP_TXCALBINP_SHIFT (0U)
/*! TxCalBinP - This csr holds the binary result of the 31 bit thermometer pullup code. */
#define DWC_DDRPHYA_MASTER_TXCALBINP_TXCALBINP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TXCALBINP_TXCALBINP_SHIFT)) & DWC_DDRPHYA_MASTER_TXCALBINP_TXCALBINP_MASK)
/*! @} */

/*! @name TXCALBINN - TX N Impedance Calibration observation */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TXCALBINN_TXCALBINN_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_TXCALBINN_TXCALBINN_SHIFT (0U)
/*! TxCalBinN - This csr holds the binary result of the 31 bit thermometer pulldown code. */
#define DWC_DDRPHYA_MASTER_TXCALBINN_TXCALBINN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TXCALBINN_TXCALBINN_SHIFT)) & DWC_DDRPHYA_MASTER_TXCALBINN_TXCALBINN_MASK)
/*! @} */

/*! @name TXCALPOVR - TX P Impedance Calibration override */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TXCALPOVR_TXCALBINPOVRVAL_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_TXCALPOVR_TXCALBINPOVRVAL_SHIFT (0U)
/*! TxCalBinPOvrVal - The binary value which can overide the Register TxCalBinP calibrator results if Register TxCalBinPOvrEn is set. */
#define DWC_DDRPHYA_MASTER_TXCALPOVR_TXCALBINPOVRVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TXCALPOVR_TXCALBINPOVRVAL_SHIFT)) & DWC_DDRPHYA_MASTER_TXCALPOVR_TXCALBINPOVRVAL_MASK)

#define DWC_DDRPHYA_MASTER_TXCALPOVR_TXCALBINPOVREN_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_TXCALPOVR_TXCALBINPOVREN_SHIFT (5U)
/*! TxCalBinPOvrEn - 1 = use the override value present in Register TxCalBinPOvrVal 0 = don't. */
#define DWC_DDRPHYA_MASTER_TXCALPOVR_TXCALBINPOVREN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TXCALPOVR_TXCALBINPOVREN_SHIFT)) & DWC_DDRPHYA_MASTER_TXCALPOVR_TXCALBINPOVREN_MASK)
/*! @} */

/*! @name TXCALNOVR - TX N Impedance Calibration override */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TXCALNOVR_TXCALBINNOVRVAL_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_TXCALNOVR_TXCALBINNOVRVAL_SHIFT (0U)
/*! TxCalBinNOvrVal - The binary value which can overide the Register TxCalBinN calibrator results if Register TxCalBinPOvrEn is set. */
#define DWC_DDRPHYA_MASTER_TXCALNOVR_TXCALBINNOVRVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TXCALNOVR_TXCALBINNOVRVAL_SHIFT)) & DWC_DDRPHYA_MASTER_TXCALNOVR_TXCALBINNOVRVAL_MASK)

#define DWC_DDRPHYA_MASTER_TXCALNOVR_TXCALBINNOVREN_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_TXCALNOVR_TXCALBINNOVREN_SHIFT (5U)
/*! TxCalBinNOvrEn - 1 = use the override value present in Register TxCalBinNOvrVal 0 = don't. */
#define DWC_DDRPHYA_MASTER_TXCALNOVR_TXCALBINNOVREN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TXCALNOVR_TXCALBINNOVREN_SHIFT)) & DWC_DDRPHYA_MASTER_TXCALNOVR_TXCALBINNOVREN_MASK)
/*! @} */

/*! @name DFIMODE - Enables for update and low-power interfaces for DFI0 and DFI1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIMODE_DFI0ENABLE_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DFIMODE_DFI0ENABLE_SHIFT (0U)
/*! Dfi0Enable - Enables operation for the PHY logic associated with DFI0 */
#define DWC_DDRPHYA_MASTER_DFIMODE_DFI0ENABLE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIMODE_DFI0ENABLE_SHIFT)) & DWC_DDRPHYA_MASTER_DFIMODE_DFI0ENABLE_MASK)

#define DWC_DDRPHYA_MASTER_DFIMODE_DFI1ENABLE_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DFIMODE_DFI1ENABLE_SHIFT (1U)
/*! Dfi1Enable - Enables operation for the PHY logic associated with DFI1 */
#define DWC_DDRPHYA_MASTER_DFIMODE_DFI1ENABLE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIMODE_DFI1ENABLE_SHIFT)) & DWC_DDRPHYA_MASTER_DFIMODE_DFI1ENABLE_MASK)

#define DWC_DDRPHYA_MASTER_DFIMODE_DFI1OVERRIDE_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_DFIMODE_DFI1OVERRIDE_SHIFT (2U)
/*! Dfi1Override - DFI0 is used to control the PHY logic associated with both DFI0 and DFI1 */
#define DWC_DDRPHYA_MASTER_DFIMODE_DFI1OVERRIDE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIMODE_DFI1OVERRIDE_SHIFT)) & DWC_DDRPHYA_MASTER_DFIMODE_DFI1OVERRIDE_MASK)
/*! @} */

/*! @name TRISTATEMODECA_P0 - Mode select register for MEMCLK/Address/Command Tristates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DISDYNADRTRI_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DISDYNADRTRI_SHIFT (0U)
/*! DisDynAdrTri - When DisDynAdrTri=1, Dynamic Tristating is disabled. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DISDYNADRTRI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DISDYNADRTRI_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DISDYNADRTRI_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DDR2TMODE_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DDR2TMODE_SHIFT (1U)
/*! DDR2TMode - Must be set to 1 for Dynamic Tristate to work when CA bus is 2T or Geardown mode. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DDR2TMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DDR2TMODE_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_DDR2TMODE_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_CKDISVAL_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_CKDISVAL_SHIFT (2U)
/*! CkDisVal - The PHY provides 4 memory clocks, n=0. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_CKDISVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_CKDISVAL_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P0_CKDISVAL_MASK)
/*! @} */

/*! @name MTESTMUXSEL - Digital Observation Pin control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MTESTMUXSEL_MTESTMUXSEL_MASK (0x3FU)
#define DWC_DDRPHYA_MASTER_MTESTMUXSEL_MTESTMUXSEL_SHIFT (0U)
/*! MtestMuxSel - Controls for the 64-1 mux for asynchronous data to the Digital Observation Pin. */
#define DWC_DDRPHYA_MASTER_MTESTMUXSEL_MTESTMUXSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MTESTMUXSEL_MTESTMUXSEL_SHIFT)) & DWC_DDRPHYA_MASTER_MTESTMUXSEL_MTESTMUXSEL_MASK)
/*! @} */

/*! @name MTESTPGMINFO - Digital Observation Pin program info for debug */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MTESTPGMINFO_MTESTPGMINFO_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_MTESTPGMINFO_MTESTPGMINFO_SHIFT (0U)
/*! MtestPgmInfo - The value of this csr may be driven onto the Digital Observation Pin. */
#define DWC_DDRPHYA_MASTER_MTESTPGMINFO_MTESTPGMINFO(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MTESTPGMINFO_MTESTPGMINFO_SHIFT)) & DWC_DDRPHYA_MASTER_MTESTPGMINFO_MTESTPGMINFO_MASK)
/*! @} */

/*! @name DYNPWRDNUP - Dynaimc Power Up/Down control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DYNPWRDNUP_DYNPOWERDOWN_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DYNPWRDNUP_DYNPOWERDOWN_SHIFT (0U)
/*! DynPowerDown - 1 - analog circuitry (voltage dacs, bias gen) is turned off. */
#define DWC_DDRPHYA_MASTER_DYNPWRDNUP_DYNPOWERDOWN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DYNPWRDNUP_DYNPOWERDOWN_SHIFT)) & DWC_DDRPHYA_MASTER_DYNPWRDNUP_DYNPOWERDOWN_MASK)
/*! @} */

/*! @name PHYTID - PHY Technology ID Register */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYTID_PHYTID_MASK    (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PHYTID_PHYTID_SHIFT   (0U)
/*! PhyTID - This register is a placeholder to store technology-specific information */
#define DWC_DDRPHYA_MASTER_PHYTID_PHYTID(x)      (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYTID_PHYTID_SHIFT)) & DWC_DDRPHYA_MASTER_PHYTID_PHYTID_MASK)
/*! @} */

/*! @name HWTMRL_P0 - HWT MaxReadLatency. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTMRL_P0_HWTMRL_P0_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTMRL_P0_HWTMRL_P0_SHIFT (0U)
/*! HwtMRL_p0 - This Max Read Latency CSR is to be trained to ensure the rx-data fifo is not read
 *    until after all dbytes have their read data valid.
 */
#define DWC_DDRPHYA_MASTER_HWTMRL_P0_HWTMRL_P0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTMRL_P0_HWTMRL_P0_SHIFT)) & DWC_DDRPHYA_MASTER_HWTMRL_P0_HWTMRL_P0_MASK)
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

#define DWC_DDRPHYA_MASTER_PDAMRSWRITEMODE_PDAMRSWRITEMODE_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PDAMRSWRITEMODE_PDAMRSWRITEMODE_SHIFT (0U)
/*! PdaMrsWriteMode - Controls the write DQ generation per the timing requirements on the DQ signals
 *    used for Per-Dram-Addressing mode of MRS commands.
 */
#define DWC_DDRPHYA_MASTER_PDAMRSWRITEMODE_PDAMRSWRITEMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PDAMRSWRITEMODE_PDAMRSWRITEMODE_SHIFT)) & DWC_DDRPHYA_MASTER_PDAMRSWRITEMODE_PDAMRSWRITEMODE_MASK)
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

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TWOTCKRXDQSPRE_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TWOTCKRXDQSPRE_SHIFT (0U)
/*! TwoTckRxDqsPre - Widens the RxDqsEn window to allow larger drift in the incoming read DQS to
 *    take advantage of the larger/wider preamble generated by the DRAMSs when the D4 DRAMS are
 *    configured with DDR4 MR4 A11 Read Preamble=1 for causing a 2nCK read preamble.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TWOTCKRXDQSPRE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TWOTCKRXDQSPRE_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TWOTCKRXDQSPRE_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TWOTCKTXDQSPRE_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TWOTCKTXDQSPRE_SHIFT (1U)
/*! TwoTckTxDqsPre - 0: Standard 1tck TxDqs Preamble 1: Enable Optional D4 2tck TxDqs Preamble The
 *    DDR4 MR4 A12 is Write Preamble, 1=2nCK, 0=1nCK.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TWOTCKTXDQSPRE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TWOTCKTXDQSPRE_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_TWOTCKTXDQSPRE_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_POSITIONDFEINIT_MASK (0x1CU)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_POSITIONDFEINIT_SHIFT (2U)
/*! PositionDfeInit - For DDR4 phy only when receive DFE is enabled. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_POSITIONDFEINIT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_POSITIONDFEINIT_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_POSITIONDFEINIT_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4TGLTWOTCKTXDQSPRE_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4TGLTWOTCKTXDQSPRE_SHIFT (5U)
/*! LP4TglTwoTckTxDqsPre - Used in LPDDR4 mode to modify the early preamble when Register
 *    TwoTckTxDqsPre=1 0: level first-memclk preamble 1: toggling first-memclk preamble
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4TGLTWOTCKTXDQSPRE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4TGLTWOTCKTXDQSPRE_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4TGLTWOTCKTXDQSPRE_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4POSTAMBLEEXT_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4POSTAMBLEEXT_SHIFT (6U)
/*! LP4PostambleExt - In LPDDR4 mode must be set to extend the write postamble. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4POSTAMBLEEXT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4POSTAMBLEEXT_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4POSTAMBLEEXT_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4STTCPREBRIDGERXEN_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4STTCPREBRIDGERXEN_SHIFT (7U)
/*! LP4SttcPreBridgeRxEn - Used in LPDDR4 static-preamble mode to bridge the RxEn between two reads
 *    to the same timing group when the bubble is 1 memclk.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4STTCPREBRIDGERXEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4STTCPREBRIDGERXEN_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P0_LP4STTCPREBRIDGERXEN_MASK)

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

#define DWC_DDRPHYA_MASTER_WRLEVBITS_WRLEVFORDQSL_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_WRLEVBITS_WRLEVFORDQSL_SHIFT (0U)
/*! WrLevForDQSL - Indicates which DQ bit is used for Write Levelization. */
#define DWC_DDRPHYA_MASTER_WRLEVBITS_WRLEVFORDQSL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_WRLEVBITS_WRLEVFORDQSL_SHIFT)) & DWC_DDRPHYA_MASTER_WRLEVBITS_WRLEVFORDQSL_MASK)

#define DWC_DDRPHYA_MASTER_WRLEVBITS_WRLEVFORDQSU_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_WRLEVBITS_WRLEVFORDQSU_SHIFT (4U)
/*! WrLevForDQSU - Indicates which DQ bit is used for Write Levelization. */
#define DWC_DDRPHYA_MASTER_WRLEVBITS_WRLEVFORDQSU(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_WRLEVBITS_WRLEVFORDQSU_SHIFT)) & DWC_DDRPHYA_MASTER_WRLEVBITS_WRLEVFORDQSU_MASK)
/*! @} */

/*! @name ENABLECSMULTICAST - In DDR4 Mode , this controls whether CS_N[3:2] should be multicast on CID[1:0] */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ENABLECSMULTICAST_ENABLECSMULTICAST_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_ENABLECSMULTICAST_ENABLECSMULTICAST_SHIFT (0U)
/*! EnableCsMulticast - In DDR4 Mode , this controls whether CS_N[3:2] should be multicast on
 *    CID[1:0] 0 - Do not override pins corresponding to cid[1:0] (dfi_cid[1:0] will connect to the pads)
 *    1 - Overrirde pins corresponding to cid[1:0] with dfi_cs[3:2].
 */
#define DWC_DDRPHYA_MASTER_ENABLECSMULTICAST_ENABLECSMULTICAST(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ENABLECSMULTICAST_ENABLECSMULTICAST_SHIFT)) & DWC_DDRPHYA_MASTER_ENABLECSMULTICAST_ENABLECSMULTICAST_MASK)
/*! @} */

/*! @name HWTLPCSMULTICAST - Drives cs_n[0] onto cs_n[1] during training */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTLPCSMULTICAST_HWTLPCSMULTICAST_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_HWTLPCSMULTICAST_HWTLPCSMULTICAST_SHIFT (0U)
/*! HwtLpCsMultiCast - When set, drives cs_n[0] onto cs_n[1] during training */
#define DWC_DDRPHYA_MASTER_HWTLPCSMULTICAST_HWTLPCSMULTICAST(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTLPCSMULTICAST_HWTLPCSMULTICAST_SHIFT)) & DWC_DDRPHYA_MASTER_HWTLPCSMULTICAST_HWTLPCSMULTICAST_MASK)
/*! @} */

/*! @name ACX4ANIBDIS - Disable for unused ACX Nibbles */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ACX4ANIBDIS_ACX4ANIBDIS_MASK (0xFFFU)
#define DWC_DDRPHYA_MASTER_ACX4ANIBDIS_ACX4ANIBDIS_SHIFT (0U)
/*! Acx4AnibDis - When a bit is set, the corresponding ACX nibble is disabled (specifically, the I/O
 *    OE is disabled, as is the Dfi-side FIFO clock
 */
#define DWC_DDRPHYA_MASTER_ACX4ANIBDIS_ACX4ANIBDIS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ACX4ANIBDIS_ACX4ANIBDIS_SHIFT)) & DWC_DDRPHYA_MASTER_ACX4ANIBDIS_ACX4ANIBDIS_MASK)
/*! @} */

/*! @name DMIPINPRESENT_P0 - This Register is used to enable the Read-DBI function in each DBYTE */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P0_RDDBIENABLED_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P0_RDDBIENABLED_SHIFT (0U)
/*! RdDbiEnabled - This bit must be set to 1'b1 if Read-DBI is enabled in a connected DDR4 or LPDDR4 device. */
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P0_RDDBIENABLED(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DMIPINPRESENT_P0_RDDBIENABLED_SHIFT)) & DWC_DDRPHYA_MASTER_DMIPINPRESENT_P0_RDDBIENABLED_MASK)
/*! @} */

/*! @name ARDPTRINITVAL_P0 - Address/Command FIFO ReadPointer Initial Value */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P0_ARDPTRINITVAL_P0_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P0_ARDPTRINITVAL_P0_SHIFT (0U)
/*! ARdPtrInitVal_p0 - This is the initial Pointer Offset for the free-running FIFOs in the DBYTE and ACX4 hardips. */
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P0_ARDPTRINITVAL_P0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P0_ARDPTRINITVAL_P0_SHIFT)) & DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P0_ARDPTRINITVAL_P0_MASK)
/*! @} */

/*! @name DBYTEDLLMODECNTRL - DLL Mode control CSR for DBYTEs */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DBYTEDLLMODECNTRL_DLLRXPREAMBLEMODE_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DBYTEDLLMODECNTRL_DLLRXPREAMBLEMODE_SHIFT (1U)
/*! DllRxPreambleMode - Must be set to 1 if read DQS preamble contains a toggle, for example DDR4 or LPDDR4 read toggling preambe mode */
#define DWC_DDRPHYA_MASTER_DBYTEDLLMODECNTRL_DLLRXPREAMBLEMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DBYTEDLLMODECNTRL_DLLRXPREAMBLEMODE_SHIFT)) & DWC_DDRPHYA_MASTER_DBYTEDLLMODECNTRL_DLLRXPREAMBLEMODE_MASK)
/*! @} */

/*! @name CALOFFSETS - Impedance Calibration offsets control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALOFFSETS_CALCMPR5OFFSET_MASK (0x3FU)
#define DWC_DDRPHYA_MASTER_CALOFFSETS_CALCMPR5OFFSET_SHIFT (0U)
/*! CalCmpr5Offset - This value adjusts the offset-compensated DAC code for the cmpana circuit at VRef == 0. */
#define DWC_DDRPHYA_MASTER_CALOFFSETS_CALCMPR5OFFSET(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALOFFSETS_CALCMPR5OFFSET_SHIFT)) & DWC_DDRPHYA_MASTER_CALOFFSETS_CALCMPR5OFFSET_MASK)

#define DWC_DDRPHYA_MASTER_CALOFFSETS_CALDRVPDTHOFFSET_MASK (0x3C0U)
#define DWC_DDRPHYA_MASTER_CALOFFSETS_CALDRVPDTHOFFSET_SHIFT (6U)
/*! CalDrvPdThOffset - This value adjusts the driver pulldown calibration code */
#define DWC_DDRPHYA_MASTER_CALOFFSETS_CALDRVPDTHOFFSET(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALOFFSETS_CALDRVPDTHOFFSET_SHIFT)) & DWC_DDRPHYA_MASTER_CALOFFSETS_CALDRVPDTHOFFSET_MASK)

#define DWC_DDRPHYA_MASTER_CALOFFSETS_CALDRVPUTHOFFSET_MASK (0x3C00U)
#define DWC_DDRPHYA_MASTER_CALOFFSETS_CALDRVPUTHOFFSET_SHIFT (10U)
/*! CalDrvPuThOffset - This value adjusts the driver pullup calibration code */
#define DWC_DDRPHYA_MASTER_CALOFFSETS_CALDRVPUTHOFFSET(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALOFFSETS_CALDRVPUTHOFFSET_SHIFT)) & DWC_DDRPHYA_MASTER_CALOFFSETS_CALDRVPUTHOFFSET_MASK)
/*! @} */

/*! @name SARINITVALS - Sar Init Vals */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SARINITVALS_SARINITOFFSET05_MASK (0x7U)
#define DWC_DDRPHYA_MASTER_SARINITVALS_SARINITOFFSET05_SHIFT (0U)
/*! SarInitOFFSET05 - Specify the SAR starting value for OFFSET05 calibration. */
#define DWC_DDRPHYA_MASTER_SARINITVALS_SARINITOFFSET05(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SARINITVALS_SARINITOFFSET05_SHIFT)) & DWC_DDRPHYA_MASTER_SARINITVALS_SARINITOFFSET05_MASK)

#define DWC_DDRPHYA_MASTER_SARINITVALS_SARINITNINT_MASK (0x38U)
#define DWC_DDRPHYA_MASTER_SARINITVALS_SARINITNINT_SHIFT (3U)
/*! SarInitNINT - Specify the SAR starting value for NINT calibration. */
#define DWC_DDRPHYA_MASTER_SARINITVALS_SARINITNINT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SARINITVALS_SARINITNINT_SHIFT)) & DWC_DDRPHYA_MASTER_SARINITVALS_SARINITNINT_MASK)

#define DWC_DDRPHYA_MASTER_SARINITVALS_SARINITPEXT_MASK (0x1C0U)
#define DWC_DDRPHYA_MASTER_SARINITVALS_SARINITPEXT_SHIFT (6U)
/*! SarInitPEXT - Specify the SAR starting value for PEXT calibration. */
#define DWC_DDRPHYA_MASTER_SARINITVALS_SARINITPEXT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SARINITVALS_SARINITPEXT_SHIFT)) & DWC_DDRPHYA_MASTER_SARINITVALS_SARINITPEXT_MASK)
/*! @} */

/*! @name CALPEXTOVR - Impedance Calibration PExt Override control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALPEXTOVR_CALPEXTOVR_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_CALPEXTOVR_CALPEXTOVR_SHIFT (0U)
/*! CalPExtOvr - If the CSR CalPExtDis is set then the value provided here by software will be used
 *    instead of the automatically generated value which is visible via CSR CalPExt This CSR may
 *    only be written when the calibrator is not running.
 */
#define DWC_DDRPHYA_MASTER_CALPEXTOVR_CALPEXTOVR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALPEXTOVR_CALPEXTOVR_SHIFT)) & DWC_DDRPHYA_MASTER_CALPEXTOVR_CALPEXTOVR_MASK)
/*! @} */

/*! @name CALCMPR5OVR - Impedance Calibration Cmpr 50 control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALCMPR5OVR_CALCMPR5OVR_MASK (0xFFU)
#define DWC_DDRPHYA_MASTER_CALCMPR5OVR_CALCMPR5OVR_SHIFT (0U)
/*! CalCmpr5Ovr - If the CSR CalCmpr5Dis is set then the value provided here by software will be
 *    used instead of the automatically generated value which is visible via CSR CalCmpr5 This CSR may
 *    only be written when the calibrator is not running.
 */
#define DWC_DDRPHYA_MASTER_CALCMPR5OVR_CALCMPR5OVR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPR5OVR_CALCMPR5OVR_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPR5OVR_CALCMPR5OVR_MASK)
/*! @} */

/*! @name CALNINTOVR - Impedance Calibration NInt Override control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALNINTOVR_CALNINTOVR_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_CALNINTOVR_CALNINTOVR_SHIFT (0U)
/*! CalNIntOvr - If the CSR CalNIntDis is set then the value provided here by software will be used
 *    instead of the automatically generated value which is visible via CSR CalNInt.
 */
#define DWC_DDRPHYA_MASTER_CALNINTOVR_CALNINTOVR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALNINTOVR_CALNINTOVR_SHIFT)) & DWC_DDRPHYA_MASTER_CALNINTOVR_CALNINTOVR_MASK)
/*! @} */

/*! @name CALDRVSTR0 - Impedance Calibration driver strength control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALDRVSTR0_CALDRVSTRPD50_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_CALDRVSTR0_CALDRVSTRPD50_SHIFT (0U)
/*! CalDrvStrPd50 - 3. */
#define DWC_DDRPHYA_MASTER_CALDRVSTR0_CALDRVSTRPD50(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALDRVSTR0_CALDRVSTRPD50_SHIFT)) & DWC_DDRPHYA_MASTER_CALDRVSTR0_CALDRVSTRPD50_MASK)

#define DWC_DDRPHYA_MASTER_CALDRVSTR0_CALDRVSTRPU50_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_CALDRVSTR0_CALDRVSTRPU50_SHIFT (4U)
/*! CalDrvStrPu50 - 3. */
#define DWC_DDRPHYA_MASTER_CALDRVSTR0_CALDRVSTRPU50(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALDRVSTR0_CALDRVSTRPU50_SHIFT)) & DWC_DDRPHYA_MASTER_CALDRVSTR0_CALDRVSTRPU50_MASK)
/*! @} */

/*! @name PROCODTTIMECTL_P0 - READ DATA On-Die Termination Timing Control (by PHY) */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_PODTTAILWIDTH_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_PODTTAILWIDTH_SHIFT (0U)
/*! POdtTailWidth - controls the length of the tail of ProcOdt, units of UI 3 tail 3UI more than for
 *    Register POdtTailWidth=0, maximum 2 tail 2UI more than for Register POdtTailWidth=0, default
 *    1 tail 1UI more than for Register POdtTailWidth=0 0 minimum length tail The time from ProcODT
 *    to closing the window to receive DQS to ProcODT POdtTailWidth is (2 + POdtTailWidth) UI
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_PODTTAILWIDTH(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_PODTTAILWIDTH_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_PODTTAILWIDTH_MASK)

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_PODTSTARTDELAY_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_PODTSTARTDELAY_SHIFT (2U)
/*! POdtStartDelay - controls the start of ProcOdt, units of UI 3 delay start 2 UI, maximum delay of
 *    start of ProcOdt 2 delay start 1 UI, 1 delay start 0 UI, default 0 early by 1 UI, The time
 *    from ProcODT assertion to opening the window to receive DQS is (10 - POdtStartDelay) UI.
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_PODTSTARTDELAY(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_PODTSTARTDELAY_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P0_PODTSTARTDELAY_MASK)
/*! @} */

/*! @name MEMALERTCONTROL - This Register is used to configure the MemAlert Receiver */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVREFLEVEL_MASK (0x7FU)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVREFLEVEL_SHIFT (0U)
/*! MALERTVrefLevel - Sets the vref level of internal VREF DAC. */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVREFLEVEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVREFLEVEL_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVREFLEVEL_MASK)

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVREFEXTEN_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVREFEXTEN_SHIFT (7U)
/*! MALERTVrefExtEn - When set for test/debug, selects external Vref source, This should not be set in mission mode. */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVREFEXTEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVREFEXTEN_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTVREFEXTEN_MASK)

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPUSTREN_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPUSTREN_SHIFT (8U)
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
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPUSTREN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPUSTREN_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPUSTREN_MASK)

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPUEN_MASK (0x1000U)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPUEN_SHIFT (12U)
/*! MALERTPuEn - When set, enables the Pull-up termination on MALERT */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPUEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPUEN_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTPUEN_MASK)

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTRXEN_MASK (0x2000U)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTRXEN_SHIFT (13U)
/*! MALERTRxEn - 1 - Enables receiver and received data is forwared to dfi_alert_n. */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTRXEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTRXEN_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTRXEN_MASK)

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTDISABLEVAL_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTDISABLEVAL_SHIFT (14U)
/*! MALERTDisableVal - When MALERTRxEn is not set, this CSR state is used to drive dfi_alert_n. */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTDISABLEVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTDISABLEVAL_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTDISABLEVAL_MASK)

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTFORCEERROR_MASK (0x8000U)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTFORCEERROR_SHIFT (15U)
/*! MALERTForceError - When MALERTForceError is set, this CSR state is used to force parity error to memory. */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTFORCEERROR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTFORCEERROR_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL_MALERTFORCEERROR_MASK)
/*! @} */

/*! @name MEMALERTCONTROL2 - This Register is used to configure the MemAlert Receiver */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL2_MALERTSYNCBYPASS_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL2_MALERTSYNCBYPASS_SHIFT (0U)
/*! MALERTSyncBypass - MALERTSyncBypass==[0], the phy will drive dfi_alert_n with a synchronized value of the ALERT_N receiver. */
#define DWC_DDRPHYA_MASTER_MEMALERTCONTROL2_MALERTSYNCBYPASS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMALERTCONTROL2_MALERTSYNCBYPASS_SHIFT)) & DWC_DDRPHYA_MASTER_MEMALERTCONTROL2_MALERTSYNCBYPASS_MASK)
/*! @} */

/*! @name MEMRESETL - Protection and control of BP_MemReset_L */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MEMRESETL_MEMRESETLVALUE_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_MEMRESETL_MEMRESETLVALUE_SHIFT (0U)
/*! MemResetLValue - Control the MemResetL output of the PHY. */
#define DWC_DDRPHYA_MASTER_MEMRESETL_MEMRESETLVALUE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMRESETL_MEMRESETLVALUE_SHIFT)) & DWC_DDRPHYA_MASTER_MEMRESETL_MEMRESETLVALUE_MASK)

#define DWC_DDRPHYA_MASTER_MEMRESETL_PROTECTMEMRESET_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_MEMRESETL_PROTECTMEMRESET_SHIFT (1U)
/*! ProtectMemReset - Control the MemResetL output of the PHY. */
#define DWC_DDRPHYA_MASTER_MEMRESETL_PROTECTMEMRESET(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MEMRESETL_PROTECTMEMRESET_SHIFT)) & DWC_DDRPHYA_MASTER_MEMRESETL_PROTECTMEMRESET_MASK)
/*! @} */

/*! @name DRIVECSLOWONTOHIGH - Drive CS_N 3:0 onto CS_N 7:4 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DRIVECSLOWONTOHIGH_CSLOWONTOHIGH_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DRIVECSLOWONTOHIGH_CSLOWONTOHIGH_SHIFT (0U)
/*! CsLowOntoHigh - When this is set to a 1, CS[3:0] from the ACSM are driven to CS[7:4] pins and CS[3:0] are deasserted. */
#define DWC_DDRPHYA_MASTER_DRIVECSLOWONTOHIGH_CSLOWONTOHIGH(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DRIVECSLOWONTOHIGH_CSLOWONTOHIGH_SHIFT)) & DWC_DDRPHYA_MASTER_DRIVECSLOWONTOHIGH_CSLOWONTOHIGH_MASK)
/*! @} */

/*! @name PUBMODE - PUBMODE - HWT Mux Select */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PUBMODE_HWTMEMSRC_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PUBMODE_HWTMEMSRC_SHIFT (0U)
/*! HwtMemSrc - When this is set to a 1, the mux that switches between DCT and HWT for the source of
 *    memory transactions is switched to HWT.
 */
#define DWC_DDRPHYA_MASTER_PUBMODE_HWTMEMSRC(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PUBMODE_HWTMEMSRC_SHIFT)) & DWC_DDRPHYA_MASTER_PUBMODE_HWTMEMSRC_MASK)
/*! @} */

/*! @name MISCPHYSTATUS - Misc PHY status bits */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MISCPHYSTATUS_DCTSANE_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_MISCPHYSTATUS_DCTSANE_SHIFT (0U)
/*! DctSane - Returns the status of the custom circuit which protects the MemResetL output of the PHY on initial power-on or reset. */
#define DWC_DDRPHYA_MASTER_MISCPHYSTATUS_DCTSANE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MISCPHYSTATUS_DCTSANE_SHIFT)) & DWC_DDRPHYA_MASTER_MISCPHYSTATUS_DCTSANE_MASK)

#define DWC_DDRPHYA_MASTER_MISCPHYSTATUS_PORMEMRESET_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_MISCPHYSTATUS_PORMEMRESET_SHIFT (1U)
/*! PORMemReset - Returns the active-high value used by the custom circuit which drives the memory RESET signal. */
#define DWC_DDRPHYA_MASTER_MISCPHYSTATUS_PORMEMRESET(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MISCPHYSTATUS_PORMEMRESET_SHIFT)) & DWC_DDRPHYA_MASTER_MISCPHYSTATUS_PORMEMRESET_MASK)
/*! @} */

/*! @name CORELOOPBACKSEL - Controls whether the loopback path bypasses the final PAD node. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CORELOOPBACKSEL_CORELOOPBACKSEL_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_CORELOOPBACKSEL_CORELOOPBACKSEL_SHIFT (0U)
/*! CoreLoopbackSel - This register is controlled by the PHY test firmware This register enables Core-Side loopback operation of the PHY. */
#define DWC_DDRPHYA_MASTER_CORELOOPBACKSEL_CORELOOPBACKSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CORELOOPBACKSEL_CORELOOPBACKSEL_SHIFT)) & DWC_DDRPHYA_MASTER_CORELOOPBACKSEL_CORELOOPBACKSEL_MASK)
/*! @} */

/*! @name DLLTRAINPARAM - DLL Various Training Parameters */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DLLTRAINPARAM_EXTENDPHDTIME_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DLLTRAINPARAM_EXTENDPHDTIME_SHIFT (0U)
/*! ExtendPhdTime - Used by the PHY firmware locking the LCDL delay cells. */
#define DWC_DDRPHYA_MASTER_DLLTRAINPARAM_EXTENDPHDTIME(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLTRAINPARAM_EXTENDPHDTIME_SHIFT)) & DWC_DDRPHYA_MASTER_DLLTRAINPARAM_EXTENDPHDTIME_MASK)
/*! @} */

/*! @name HWTLPCSENBYPASS - CSn Disable Bypass for LPDDR3/4 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTLPCSENBYPASS_HWTLPCSENBYPASS_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_HWTLPCSENBYPASS_HWTLPCSENBYPASS_SHIFT (0U)
/*! HwtLpCsEnBypass - When set, these bits disable LpCsEn function for LPDDR3/4 */
#define DWC_DDRPHYA_MASTER_HWTLPCSENBYPASS_HWTLPCSENBYPASS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTLPCSENBYPASS_HWTLPCSENBYPASS_SHIFT)) & DWC_DDRPHYA_MASTER_HWTLPCSENBYPASS_HWTLPCSENBYPASS_MASK)
/*! @} */

/*! @name DFICAMODE - Dfi Command/Address Mode */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFICAMODE_DFILP3CAMODE_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DFICAMODE_DFILP3CAMODE_SHIFT (0U)
/*! DfiLp3CAMode - Controls the output data-rate of the AC module Command/Address pins 0: LP3 DDR
 *    address mode disabled 1: LP3 DDR address mode enabled
 */
#define DWC_DDRPHYA_MASTER_DFICAMODE_DFILP3CAMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFICAMODE_DFILP3CAMODE_SHIFT)) & DWC_DDRPHYA_MASTER_DFICAMODE_DFILP3CAMODE_MASK)

#define DWC_DDRPHYA_MASTER_DFICAMODE_DFID4CAMODE_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DFICAMODE_DFID4CAMODE_SHIFT (1U)
/*! DfiD4CAMode - Enable D4 Mode 0: D4 mode disabled 1: D4 mode enabled */
#define DWC_DDRPHYA_MASTER_DFICAMODE_DFID4CAMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFICAMODE_DFID4CAMODE_SHIFT)) & DWC_DDRPHYA_MASTER_DFICAMODE_DFID4CAMODE_MASK)

#define DWC_DDRPHYA_MASTER_DFICAMODE_DFILP4CAMODE_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_DFICAMODE_DFILP4CAMODE_SHIFT (2U)
/*! DfiLp4CAMode - Enable LP4 Mode 0: LP4 mode disabled 1: LP4 mode enabled */
#define DWC_DDRPHYA_MASTER_DFICAMODE_DFILP4CAMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFICAMODE_DFILP4CAMODE_SHIFT)) & DWC_DDRPHYA_MASTER_DFICAMODE_DFILP4CAMODE_MASK)

#define DWC_DDRPHYA_MASTER_DFICAMODE_DFID4ALTCAMODE_MASK (0x8U)
#define DWC_DDRPHYA_MASTER_DFICAMODE_DFID4ALTCAMODE_SHIFT (3U)
/*! DfiD4AltCAMode - Enable D4-Alt Mode 0: D4-Altmode disabled 1: D4-Altmode enabled */
#define DWC_DDRPHYA_MASTER_DFICAMODE_DFID4ALTCAMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFICAMODE_DFID4ALTCAMODE_SHIFT)) & DWC_DDRPHYA_MASTER_DFICAMODE_DFID4ALTCAMODE_MASK)
/*! @} */

/*! @name DLLCONTROL - DLL Lock State machine control register */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETRELOCK_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETRELOCK_SHIFT (0U)
/*! DllResetRelock - Used to reset the DDL/LCDL lock state machine Deasserting starts locking sequence. */
#define DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETRELOCK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETRELOCK_SHIFT)) & DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETRELOCK_MASK)

#define DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETSLAVE_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETSLAVE_SHIFT (1U)
/*! DllResetSlave - Reserved. */
#define DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETSLAVE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETSLAVE_SHIFT)) & DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETSLAVE_MASK)

#define DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETRSVD_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETRSVD_SHIFT (2U)
/*! DllResetRSVD - RSVD for future use */
#define DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETRSVD(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETRSVD_SHIFT)) & DWC_DDRPHYA_MASTER_DLLCONTROL_DLLRESETRSVD_MASK)
/*! @} */

/*! @name PULSEDLLUPDATEPHASE - DLL update phase control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEDBYTEDLLUPDATEPHASE_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEDBYTEDLLUPDATEPHASE_SHIFT (0U)
/*! PulseDbyteDllUpdatePhase - Causes a LongBubble to the DBYTE modules, which causes a update of the DBYTE module DLLs (tx,rxen,rxclk). */
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEDBYTEDLLUPDATEPHASE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEDBYTEDLLUPDATEPHASE_SHIFT)) & DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEDBYTEDLLUPDATEPHASE_MASK)

#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEACKDLLUPDATEPHASE_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEACKDLLUPDATEPHASE_SHIFT (1U)
/*! PulseACkDllUpdatePhase - Causes an AC module CK (memck) DLL phase update. */
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEACKDLLUPDATEPHASE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEACKDLLUPDATEPHASE_SHIFT)) & DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEACKDLLUPDATEPHASE_MASK)

#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEACADLLUPDATEPHASE_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEACADLLUPDATEPHASE_SHIFT (2U)
/*! PulseACaDllUpdatePhase - Causes an AC module CA (command/address/cke/odt) DLL phase update. */
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEACADLLUPDATEPHASE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEACADLLUPDATEPHASE_SHIFT)) & DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_PULSEACADLLUPDATEPHASE_MASK)

#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_UPDATEPHASEDESTRESERVED_MASK (0x38U)
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_UPDATEPHASEDESTRESERVED_SHIFT (3U)
/*! UpdatePhaseDestReserved - reserved, not used */
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_UPDATEPHASEDESTRESERVED(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_UPDATEPHASEDESTRESERVED_SHIFT)) & DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_UPDATEPHASEDESTRESERVED_MASK)

#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_TRAINUPDATEPHASEONLONGBUBBLE_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_TRAINUPDATEPHASEONLONGBUBBLE_SHIFT (6U)
/*! TrainUpdatePhaseOnLongBubble - Causes LongBubble to update the dbyte & anib LDCL Phase. */
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_TRAINUPDATEPHASEONLONGBUBBLE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_TRAINUPDATEPHASEONLONGBUBBLE_SHIFT)) & DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_TRAINUPDATEPHASEONLONGBUBBLE_MASK)

#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_ALWAYSUPDATELCDLPHASE_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_ALWAYSUPDATELCDLPHASE_SHIFT (7U)
/*! AlwaysUpdateLcdlPhase - Causes each new operation to reload the LcdlPhase; will increase bubbles. */
#define DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_ALWAYSUPDATELCDLPHASE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_ALWAYSUPDATELCDLPHASE_SHIFT)) & DWC_DDRPHYA_MASTER_PULSEDLLUPDATEPHASE_ALWAYSUPDATELCDLPHASE_MASK)
/*! @} */

/*! @name DLLGAINCTL_P0 - DLL gain control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLGAINIV_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLGAINIV_SHIFT (0U)
/*! DllGainIV - Initial value of DllGain. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLGAINIV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLGAINIV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLGAINIV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLGAINTV_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLGAINTV_SHIFT (4U)
/*! DllGainTV - Terminal value of DllGain, ie the value in effect when locking is done and the value
 *    used for maintaining lock, ie tracking pclk variation.
 */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLGAINTV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLGAINTV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLGAINTV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLSEEDSEL_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLSEEDSEL_SHIFT (8U)
/*! DllSeedSel - Reserved, must be configured to be 0. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLSEEDSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLSEEDSEL_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P0_DLLSEEDSEL_MASK)
/*! @} */

/*! @name CALRATE - Impedance Calibration Control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALRATE_CALINTERVAL_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_CALRATE_CALINTERVAL_SHIFT (0U)
/*! CalInterval - This CSR specifies the interval between successive calibrations, in mS. */
#define DWC_DDRPHYA_MASTER_CALRATE_CALINTERVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALRATE_CALINTERVAL_SHIFT)) & DWC_DDRPHYA_MASTER_CALRATE_CALINTERVAL_MASK)

#define DWC_DDRPHYA_MASTER_CALRATE_CALRUN_MASK   (0x10U)
#define DWC_DDRPHYA_MASTER_CALRATE_CALRUN_SHIFT  (4U)
/*! CalRun - 1: A calibration sequence will be triggered by the 0->1 transition of this bit, as determined by CSR CalOnce. */
#define DWC_DDRPHYA_MASTER_CALRATE_CALRUN(x)     (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALRATE_CALRUN_SHIFT)) & DWC_DDRPHYA_MASTER_CALRATE_CALRUN_MASK)

#define DWC_DDRPHYA_MASTER_CALRATE_CALONCE_MASK  (0x20U)
#define DWC_DDRPHYA_MASTER_CALRATE_CALONCE_SHIFT (5U)
/*! CalOnce - The setting of this CSR changes the behaviour of CSR CalRun. */
#define DWC_DDRPHYA_MASTER_CALRATE_CALONCE(x)    (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALRATE_CALONCE_SHIFT)) & DWC_DDRPHYA_MASTER_CALRATE_CALONCE_MASK)

#define DWC_DDRPHYA_MASTER_CALRATE_DISABLEBACKGROUNDZQUPDATES_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_CALRATE_DISABLEBACKGROUNDZQUPDATES_SHIFT (6U)
/*! DisableBackgroundZQUpdates - 1: Instead of having the driver compensation codes go
 *    asynchronously out to all IO, hold until for any of PHYUPD ACK, CTRLUPD ACK, PHYMSTR ACK) 0: Calibrated ZQ
 *    Updates to IO aren't gated.
 */
#define DWC_DDRPHYA_MASTER_CALRATE_DISABLEBACKGROUNDZQUPDATES(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALRATE_DISABLEBACKGROUNDZQUPDATES_SHIFT)) & DWC_DDRPHYA_MASTER_CALRATE_DISABLEBACKGROUNDZQUPDATES_MASK)
/*! @} */

/*! @name CALZAP - Impedance Calibration Zap/Reset */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALZAP_CALZAP_MASK    (0x1U)
#define DWC_DDRPHYA_MASTER_CALZAP_CALZAP_SHIFT   (0U)
/*! CalZap - NOTE : This CSR is written by PHY Initialization Engine (PIE) and the data in here will be overwritten. */
#define DWC_DDRPHYA_MASTER_CALZAP_CALZAP(x)      (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALZAP_CALZAP_SHIFT)) & DWC_DDRPHYA_MASTER_CALZAP_CALZAP_MASK)
/*! @} */

/*! @name PSTATE - PSTATE Selection */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PSTATE_PSTATE_MASK    (0xFU)
#define DWC_DDRPHYA_MASTER_PSTATE_PSTATE_SHIFT   (0U)
/*! PState - NOTE : This CSR is written by PHY Initialization Engine (PIE) and the data in here will be overwritten. */
#define DWC_DDRPHYA_MASTER_PSTATE_PSTATE(x)      (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PSTATE_PSTATE_SHIFT)) & DWC_DDRPHYA_MASTER_PSTATE_PSTATE_MASK)
/*! @} */

/*! @name PLLOUTGATECONTROL - PLL Output Control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLOUTGATECONTROL_PCLKGATEEN_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLOUTGATECONTROL_PCLKGATEEN_SHIFT (0U)
/*! PclkGateEn - Reserved. */
#define DWC_DDRPHYA_MASTER_PLLOUTGATECONTROL_PCLKGATEEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLOUTGATECONTROL_PCLKGATEEN_SHIFT)) & DWC_DDRPHYA_MASTER_PLLOUTGATECONTROL_PCLKGATEEN_MASK)
/*! @} */

/*! @name PORCONTROL - PMU Power-on Reset Control (PLL/DLL Lock Done) */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PORCONTROL_PLLDLLLOCKDONE_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PORCONTROL_PLLDLLLOCKDONE_SHIFT (0U)
/*! PllDllLockDone - Set by the PIE to 1 after it has finished the PLL/DLL lock sequence. */
#define DWC_DDRPHYA_MASTER_PORCONTROL_PLLDLLLOCKDONE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PORCONTROL_PLLDLLLOCKDONE_SHIFT)) & DWC_DDRPHYA_MASTER_PORCONTROL_PLLDLLLOCKDONE_MASK)
/*! @} */

/*! @name CALBUSY - Impedance Calibration Busy Status */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALBUSY_CALBUSY_MASK  (0x1U)
#define DWC_DDRPHYA_MASTER_CALBUSY_CALBUSY_SHIFT (0U)
/*! CalBusy - Read 1 if the calibrator is actively calibrating. */
#define DWC_DDRPHYA_MASTER_CALBUSY_CALBUSY(x)    (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALBUSY_CALBUSY_SHIFT)) & DWC_DDRPHYA_MASTER_CALBUSY_CALBUSY_MASK)
/*! @} */

/*! @name CALMISC2 - Miscellaneous impedance calibration controls. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALMISC2_CALNUMVOTES_MASK (0x7U)
#define DWC_DDRPHYA_MASTER_CALMISC2_CALNUMVOTES_SHIFT (0U)
/*! CalNumVotes - This CSR controls the number of consecutive comparator output bits over which majority voting is done. */
#define DWC_DDRPHYA_MASTER_CALMISC2_CALNUMVOTES(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALMISC2_CALNUMVOTES_SHIFT)) & DWC_DDRPHYA_MASTER_CALMISC2_CALNUMVOTES_MASK)

#define DWC_DDRPHYA_MASTER_CALMISC2_CALCMPTRRESTRIM_MASK (0x1000U)
#define DWC_DDRPHYA_MASTER_CALMISC2_CALCMPTRRESTRIM_SHIFT (12U)
/*! CalCmptrResTrim - Reserved for future use. */
#define DWC_DDRPHYA_MASTER_CALMISC2_CALCMPTRRESTRIM(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALMISC2_CALCMPTRRESTRIM_SHIFT)) & DWC_DDRPHYA_MASTER_CALMISC2_CALCMPTRRESTRIM_MASK)

#define DWC_DDRPHYA_MASTER_CALMISC2_CALCANCELROUNDERRDIS_MASK (0x2000U)
#define DWC_DDRPHYA_MASTER_CALMISC2_CALCANCELROUNDERRDIS_SHIFT (13U)
/*! CalCancelRoundErrDis - The PEXT calibration result and NINT calibration results naturally
 *    include a rounding error which manifests as a change of impedance at the pad.
 */
#define DWC_DDRPHYA_MASTER_CALMISC2_CALCANCELROUNDERRDIS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALMISC2_CALCANCELROUNDERRDIS_SHIFT)) & DWC_DDRPHYA_MASTER_CALMISC2_CALCANCELROUNDERRDIS_MASK)

#define DWC_DDRPHYA_MASTER_CALMISC2_CALSLOWCMPANA_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_CALMISC2_CALSLOWCMPANA_SHIFT (14U)
/*! CalSlowCmpana - When set, this CSR increases the time allowed for the cmpana cell to settle, by 50%. */
#define DWC_DDRPHYA_MASTER_CALMISC2_CALSLOWCMPANA(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALMISC2_CALSLOWCMPANA_SHIFT)) & DWC_DDRPHYA_MASTER_CALMISC2_CALSLOWCMPANA_MASK)
/*! @} */

/*! @name CALMISC - Controls for disabling the impedance calibration of certain targets. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALMISC_CALCMPR5DIS_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_CALMISC_CALCMPR5DIS_SHIFT (0U)
/*! CalCmpr5Dis - Setting this CSR prevents the calibration engine from using the result from the CalCmpr5 stage of calibration. */
#define DWC_DDRPHYA_MASTER_CALMISC_CALCMPR5DIS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALMISC_CALCMPR5DIS_SHIFT)) & DWC_DDRPHYA_MASTER_CALMISC_CALCMPR5DIS_MASK)

#define DWC_DDRPHYA_MASTER_CALMISC_CALNINTDIS_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_CALMISC_CALNINTDIS_SHIFT (1U)
/*! CalNIntDis - Setting this CSR prevents the calibration engine from overwriting the CSRs
 *    TxCalBinN and TxCalThN with an automatically generated value, in which case a value must be supplied
 *    by software.
 */
#define DWC_DDRPHYA_MASTER_CALMISC_CALNINTDIS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALMISC_CALNINTDIS_SHIFT)) & DWC_DDRPHYA_MASTER_CALMISC_CALNINTDIS_MASK)

#define DWC_DDRPHYA_MASTER_CALMISC_CALPEXTDIS_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_CALMISC_CALPEXTDIS_SHIFT (2U)
/*! CalPExtDis - Setting this CSR prevents the calibration engine from overwriting the CSRs
 *    TxCalBinP and TxCalThP with an automatically generated value, in which case a value must be supplied
 *    by software.
 */
#define DWC_DDRPHYA_MASTER_CALMISC_CALPEXTDIS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALMISC_CALPEXTDIS_SHIFT)) & DWC_DDRPHYA_MASTER_CALMISC_CALPEXTDIS_MASK)
/*! @} */

/*! @name CALVREFS -  */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALVREFS_CALVREFS_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_CALVREFS_CALVREFS_SHIFT (0U)
/*! CalVRefs - This CSR drives the Cmpdig_CalRef pin of the cmpana cell at various stages of calibration. */
#define DWC_DDRPHYA_MASTER_CALVREFS_CALVREFS(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALVREFS_CALVREFS_SHIFT)) & DWC_DDRPHYA_MASTER_CALVREFS_CALVREFS_MASK)
/*! @} */

/*! @name CALCMPR5 - Impedance Calibration Cmpr control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALCMPR5_CALCMPR5_MASK (0xFFU)
#define DWC_DDRPHYA_MASTER_CALCMPR5_CALCMPR5_SHIFT (0U)
/*! CalCmpr5 - Returns the offset-compensated DAC code for the cmpana circuit at VRef == 0. */
#define DWC_DDRPHYA_MASTER_CALCMPR5_CALCMPR5(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPR5_CALCMPR5_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPR5_CALCMPR5_MASK)
/*! @} */

/*! @name CALNINT - Impedance Calibration NInt control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALNINT_CALNINTTHB_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_CALNINT_CALNINTTHB_SHIFT (0U)
/*! CalNIntThB - The value here is the number of thermometer bits which are set. */
#define DWC_DDRPHYA_MASTER_CALNINT_CALNINTTHB(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALNINT_CALNINTTHB_SHIFT)) & DWC_DDRPHYA_MASTER_CALNINT_CALNINTTHB_MASK)
/*! @} */

/*! @name CALPEXT - Impedance Calibration PExt control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALPEXT_CALPEXTTHB_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_CALPEXT_CALPEXTTHB_SHIFT (0U)
/*! CalPExtThB - The value here is the number of thermometer bits which are set. */
#define DWC_DDRPHYA_MASTER_CALPEXT_CALPEXTTHB(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALPEXT_CALPEXTTHB_SHIFT)) & DWC_DDRPHYA_MASTER_CALPEXT_CALPEXTTHB_MASK)
/*! @} */

/*! @name CALCMPINVERT - Impedance Calibration Cmp Invert control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDAC50_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDAC50_SHIFT (0U)
/*! CmpInvertCalDac50 - Impedance Calibration Cmp Invert control */
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDAC50(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDAC50_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDAC50_MASK)

#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDRVPD50_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDRVPD50_SHIFT (1U)
/*! CmpInvertCalDrvPd50 - Impedance Calibration Cmp Invert control */
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDRVPD50(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDRVPD50_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDRVPD50_MASK)

#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDRVPU50_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDRVPU50_SHIFT (2U)
/*! CmpInvertCalDrvPu50 - Impedance Calibration Cmp Invert control */
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDRVPU50(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDRVPU50_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALDRVPU50_MASK)

#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALODTPD_MASK (0x8U)
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALODTPD_SHIFT (3U)
/*! CmpInvertCalOdtPd - Impedance Calibration Cmp Invert control */
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALODTPD(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALODTPD_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALODTPD_MASK)

#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALODTPU_MASK (0x10U)
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALODTPU_SHIFT (4U)
/*! CmpInvertCalOdtPu - Impedance Calibration Cmp Invert control */
#define DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALODTPU(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALODTPU_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPINVERT_CMPINVERTCALODTPU_MASK)
/*! @} */

/*! @name CALCMPANACNTRL - Impedance Calibration Cmpana control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRGAINCURRADJ_MASK (0xFFU)
#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRGAINCURRADJ_SHIFT (0U)
/*! CmprGainCurrAdj - Impedance Calibration Cmpana control */
#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRGAINCURRADJ(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRGAINCURRADJ_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRGAINCURRADJ_MASK)

#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRGAINRESADJ_MASK (0x100U)
#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRGAINRESADJ_SHIFT (8U)
/*! CmprGainResAdj - Impedance Calibration Cmpana control */
#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRGAINRESADJ(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRGAINRESADJ_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRGAINRESADJ_MASK)

#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRBIASBYPASSEN_MASK (0x200U)
#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRBIASBYPASSEN_SHIFT (9U)
/*! CmprBiasBypassEn - Impedance Calibration Cmpana control */
#define DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRBIASBYPASSEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRBIASBYPASSEN_SHIFT)) & DWC_DDRPHYA_MASTER_CALCMPANACNTRL_CMPRBIASBYPASSEN_MASK)
/*! @} */

/*! @name DFIRDDATACSDESTMAP_P0 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM0_SHIFT (0U)
/*! DfiRdDestm0 - Maps dfi_rddata_cs_n_p0[0] to dest DfiRdDestm0 timing For example, if 0
 *    dfi_rddata_cs_n_p0[0] will use Register RxEn,ClkDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM0_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM1_SHIFT (2U)
/*! DfiRdDestm1 - Maps dfi_rddata_cs_n_p0[1] to dest DfiRdDestm1 timing For example, if 1
 *    dfi_rddata_cs_n[_p01] will use Register RxEn,ClkDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM1_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM2_SHIFT (4U)
/*! DfiRdDestm2 - Maps dfi_rddata_cs_n_p0[2] to dest DfiRdDestm2 timing For example, if 2
 *    dfi_rddata_cs_n_p0[2] will use Register RxEn,ClkDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM2_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM3_SHIFT (6U)
/*! DfiRdDestm3 - Maps dfi_rddata_cs_n_p0[3] to dest DfiRdDestm3 timing For example, if 3
 *    dfi_rddata_cs_n_p0[3] will use Register RxEn,ClkDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P0_DFIRDDESTM3_MASK)
/*! @} */

/*! @name VREFINGLOBAL_P0 - PHY Global Vref Controls */
/*! @{ */

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINSEL_MASK (0x7U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINSEL_SHIFT (0U)
/*! GlobalVrefInSel - GlobalVrefInSel[1:0] controls the mode of the PHY VREF DAC and the BP_VREF pin
 *    ========================================================== 2'b00 - PHY Vref DAC Range0 --
 *    BP_VREF = Hi-Z 2'b01 - Reserved Encoding 2'b10 - PHY Vref DAC Range0 -- BP_VREF connected to PLL
 *    Analog Bus 2'b11 - PHY Vref DAC Range0 -- BP_VREF connected to PHY Vref DAC
 *    ========================================================== GlobalVrefInSel[2] shall be set according to Dram
 *    Protocol: Protocol GlobalVrefInSel[2] ------------------------------------------ DDR3 1'b0 DDR4
 *    1'b0 LPDDR3 1'b0 LPDDR4 1'b1
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINSEL_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINSEL_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINDAC_MASK (0x3F8U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINDAC_SHIFT (3U)
/*! GlobalVrefInDAC - DAC code for internal Vref generation The DAC has two ranges; the range is set
 *    by GlobalVrefInSel[2] ========================================================== RANGE0 :
 *    DDR3,DDR4,LPDDR3 [GlobalVrefInSel[2] = 0] DAC Output Voltage = GlobalVrefInDAC == 6'h00 ? Hi-Z :
 *    0.
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINDAC(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINDAC_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINDAC_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINTRIM_MASK (0x3C00U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINTRIM_SHIFT (10U)
/*! GlobalVrefInTrim - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINTRIM(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINTRIM_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINTRIM_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINMODE_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINMODE_SHIFT (14U)
/*! GlobalVrefInMode - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINMODE_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P0_GLOBALVREFINMODE_MASK)
/*! @} */

/*! @name DFIWRDATACSDESTMAP_P0 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM0_SHIFT (0U)
/*! DfiWrDestm0 - Maps dfi_wrdata_cs_n_p0[0] to dest DfiWrDestm0 timing For example, if 0
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM0_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM1_SHIFT (2U)
/*! DfiWrDestm1 - Maps dfi_wrdata_cs_n_p0[1] to dest DfiWrDestm1 timing For example, if 1
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM1_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM2_SHIFT (4U)
/*! DfiWrDestm2 - Maps dfi_wrdata_cs_n_p0[2] to dest DfiWrDestm2 timing For example, if 2
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM2_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM3_SHIFT (6U)
/*! DfiWrDestm3 - Maps dfi_wrdata_cs_n_p0[3] to dest DfiWrDestm3 timing (use Register
 *    TxDq,DqsDlyTg3) For example, if 3 dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P0_DFIWRDESTM3_MASK)
/*! @} */

/*! @name MASUPDGOODCTR - Counts successful PHY Master Interface Updates (PPTs) */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MASUPDGOODCTR_MASUPDGOODCTR_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_MASUPDGOODCTR_MASUPDGOODCTR_SHIFT (0U)
/*! MasUpdGoodCtr - This register increments whenever the Memory Controller acknowledges a PHY Master Interface request (i. */
#define DWC_DDRPHYA_MASTER_MASUPDGOODCTR_MASUPDGOODCTR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MASUPDGOODCTR_MASUPDGOODCTR_SHIFT)) & DWC_DDRPHYA_MASTER_MASUPDGOODCTR_MASUPDGOODCTR_MASK)
/*! @} */

/*! @name PHYUPD0GOODCTR - Counts successful PHY-initiated DFI0 Interface Updates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYUPD0GOODCTR_PHYUPD0GOODCTR_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PHYUPD0GOODCTR_PHYUPD0GOODCTR_SHIFT (0U)
/*! PhyUpd0GoodCtr - This register increments whenever the Memory Controller acknowledges a PHY-initiated DFI0 interface update request. */
#define DWC_DDRPHYA_MASTER_PHYUPD0GOODCTR_PHYUPD0GOODCTR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYUPD0GOODCTR_PHYUPD0GOODCTR_SHIFT)) & DWC_DDRPHYA_MASTER_PHYUPD0GOODCTR_PHYUPD0GOODCTR_MASK)
/*! @} */

/*! @name PHYUPD1GOODCTR - Counts successful PHY-initiated DFI1 Interface Updates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYUPD1GOODCTR_PHYUPD1GOODCTR_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PHYUPD1GOODCTR_PHYUPD1GOODCTR_SHIFT (0U)
/*! PhyUpd1GoodCtr - This register increments whenever the Memory Controller acknowledges a PHY-initiated DFI1 interface update request. */
#define DWC_DDRPHYA_MASTER_PHYUPD1GOODCTR_PHYUPD1GOODCTR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYUPD1GOODCTR_PHYUPD1GOODCTR_SHIFT)) & DWC_DDRPHYA_MASTER_PHYUPD1GOODCTR_PHYUPD1GOODCTR_MASK)
/*! @} */

/*! @name CTLUPD0GOODCTR - Counts successful Memory Controller DFI0 Interface Updates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CTLUPD0GOODCTR_CTLUPD0GOODCTR_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_CTLUPD0GOODCTR_CTLUPD0GOODCTR_SHIFT (0U)
/*! CtlUpd0GoodCtr - This register increments whenever the PHY acknowledges a Memory Controller-initiated DFI0 interface update request. */
#define DWC_DDRPHYA_MASTER_CTLUPD0GOODCTR_CTLUPD0GOODCTR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CTLUPD0GOODCTR_CTLUPD0GOODCTR_SHIFT)) & DWC_DDRPHYA_MASTER_CTLUPD0GOODCTR_CTLUPD0GOODCTR_MASK)
/*! @} */

/*! @name CTLUPD1GOODCTR - Counts successful Memory Controller DFI1 Interface Updates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CTLUPD1GOODCTR_CTLUPD1GOODCTR_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_CTLUPD1GOODCTR_CTLUPD1GOODCTR_SHIFT (0U)
/*! CtlUpd1GoodCtr - This register increments whenever the PHY acknowledges a Memory Controller-initiated DFI1 interface update request. */
#define DWC_DDRPHYA_MASTER_CTLUPD1GOODCTR_CTLUPD1GOODCTR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CTLUPD1GOODCTR_CTLUPD1GOODCTR_SHIFT)) & DWC_DDRPHYA_MASTER_CTLUPD1GOODCTR_CTLUPD1GOODCTR_MASK)
/*! @} */

/*! @name MASUPDFAILCTR - Counts unsuccessful PHY Master Interface Updates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MASUPDFAILCTR_MASUPDFAILCTR_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_MASUPDFAILCTR_MASUPDFAILCTR_SHIFT (0U)
/*! MasUpdFailCtr - This register increments whenever the PHY asserts a PHY Master Interface
 *    request, but the Memory Controller doesn't acknowledge the request within the allowed interval.
 */
#define DWC_DDRPHYA_MASTER_MASUPDFAILCTR_MASUPDFAILCTR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MASUPDFAILCTR_MASUPDFAILCTR_SHIFT)) & DWC_DDRPHYA_MASTER_MASUPDFAILCTR_MASUPDFAILCTR_MASK)
/*! @} */

/*! @name PHYUPD0FAILCTR - Counts unsuccessful PHY-initiated DFI0 Interface Updates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYUPD0FAILCTR_PHYUPD0FAILCTR_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PHYUPD0FAILCTR_PHYUPD0FAILCTR_SHIFT (0U)
/*! PhyUpd0FailCtr - This register increments whenever the PHY asserts a DFI0 Interface update
 *    request, but the Memory Controller doesn't acknowledge the request within the allowed interval.
 */
#define DWC_DDRPHYA_MASTER_PHYUPD0FAILCTR_PHYUPD0FAILCTR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYUPD0FAILCTR_PHYUPD0FAILCTR_SHIFT)) & DWC_DDRPHYA_MASTER_PHYUPD0FAILCTR_PHYUPD0FAILCTR_MASK)
/*! @} */

/*! @name PHYUPD1FAILCTR - Counts unsuccessful PHY-initiated DFI1 Interface Updates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYUPD1FAILCTR_PHYUPD1FAILCTR_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PHYUPD1FAILCTR_PHYUPD1FAILCTR_SHIFT (0U)
/*! PhyUpd1FailCtr - This register increments whenever the PHY asserts a DFI1 Interface update
 *    request, but the Memory Controller doesn't acknowledge the request within the allowed interval.
 */
#define DWC_DDRPHYA_MASTER_PHYUPD1FAILCTR_PHYUPD1FAILCTR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYUPD1FAILCTR_PHYUPD1FAILCTR_SHIFT)) & DWC_DDRPHYA_MASTER_PHYUPD1FAILCTR_PHYUPD1FAILCTR_MASK)
/*! @} */

/*! @name PHYPERFCTRENABLE - Enables for Performance Counters */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MASUPDGOODCTL_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MASUPDGOODCTL_SHIFT (0U)
/*! MasUpdGoodCtl - Enables MasUpdGoodCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MASUPDGOODCTL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MASUPDGOODCTL_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MASUPDGOODCTL_MASK)

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD0GOODCTL_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD0GOODCTL_SHIFT (1U)
/*! PhyUpd0GoodCtl - Enables PhyUpd0GoodCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD0GOODCTL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD0GOODCTL_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD0GOODCTL_MASK)

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD1GOODCTL_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD1GOODCTL_SHIFT (2U)
/*! PhyUpd1GoodCtl - Enables PhyUpd1GoodCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD1GOODCTL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD1GOODCTL_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD1GOODCTL_MASK)

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CTLUPD0GOODCTL_MASK (0x8U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CTLUPD0GOODCTL_SHIFT (3U)
/*! CtlUpd0GoodCtl - Enables CtlUpd0GoodCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CTLUPD0GOODCTL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CTLUPD0GOODCTL_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CTLUPD0GOODCTL_MASK)

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CTLUPD1GOODCTL_MASK (0x10U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CTLUPD1GOODCTL_SHIFT (4U)
/*! CtlUpd1GoodCtl - Enables CtlUpd1GoodCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CTLUPD1GOODCTL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CTLUPD1GOODCTL_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_CTLUPD1GOODCTL_MASK)

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MASUPDFAILCTL_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MASUPDFAILCTL_SHIFT (5U)
/*! MasUpdFailCtl - Enables MasUpdFailCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MASUPDFAILCTL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MASUPDFAILCTL_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_MASUPDFAILCTL_MASK)

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD0FAILCTL_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD0FAILCTL_SHIFT (6U)
/*! PhyUpd0FailCtl - Enables PhyUpd0FailCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD0FAILCTL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD0FAILCTL_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD0FAILCTL_MASK)

#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD1FAILCTL_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD1FAILCTL_SHIFT (7U)
/*! PhyUpd1FailCtl - Enables PhyUpd1FailCtr */
#define DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD1FAILCTL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD1FAILCTL_SHIFT)) & DWC_DDRPHYA_MASTER_PHYPERFCTRENABLE_PHYUPD1FAILCTL_MASK)
/*! @} */

/*! @name PLLPWRDN - PLL Power Down */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLPWRDN_PLLPWRDN_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLPWRDN_PLLPWRDN_SHIFT (0U)
/*! PllPwrDn - NOTE : This CSR is written by PHY Initialization Engine (PIE) and the data in here will be overwritten. */
#define DWC_DDRPHYA_MASTER_PLLPWRDN_PLLPWRDN(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLPWRDN_PLLPWRDN_SHIFT)) & DWC_DDRPHYA_MASTER_PLLPWRDN_PLLPWRDN_MASK)
/*! @} */

/*! @name PLLRESET - PLL Reset */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLRESET_PLLRESET_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLRESET_PLLRESET_SHIFT (0U)
/*! PllReset - Reserved */
#define DWC_DDRPHYA_MASTER_PLLRESET_PLLRESET(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLRESET_PLLRESET_SHIFT)) & DWC_DDRPHYA_MASTER_PLLRESET_PLLRESET_MASK)
/*! @} */

/*! @name PLLCTRL2_P0 - PState dependent PLL Control Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL2_P0_PLLFREQSEL_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P0_PLLFREQSEL_SHIFT (0U)
/*! PllFreqSel - Adjusts the loop parameters to compensate for different VCO bias points, and input/output clock division ratios. */
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P0_PLLFREQSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL2_P0_PLLFREQSEL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL2_P0_PLLFREQSEL_MASK)
/*! @} */

/*! @name PLLCTRL0 - PLL Control Register 0 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSTANDBY_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSTANDBY_SHIFT (0U)
/*! PllStandby - Connects directly to standby pin of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSTANDBY(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSTANDBY_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSTANDBY_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLBYPSEL_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLBYPSEL_SHIFT (1U)
/*! PllBypSel - Reserved. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLBYPSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PLLBYPSEL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PLLBYPSEL_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLX2MODE_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLX2MODE_SHIFT (2U)
/*! PllX2Mode - conects to x2_mode pins of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLX2MODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PLLX2MODE_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PLLX2MODE_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLOUTBYPEN_MASK (0x8U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLOUTBYPEN_SHIFT (3U)
/*! PllOutBypEn - Controls the antiglitch mux on the pllout_x1x2x4 path 1: pllout_x1x2x4 =
 *    byp_pllin_x1 0: pllout_x1x2x4 = VCO (SCD) (selected by x2_mode)
 */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLOUTBYPEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PLLOUTBYPEN_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PLLOUTBYPEN_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLPRESET_MASK (0x10U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLPRESET_SHIFT (4U)
/*! PllPreset - Put PLL in preset mode. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLPRESET(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PLLPRESET_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PLLPRESET_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLBYPASSMODE_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLBYPASSMODE_SHIFT (5U)
/*! PllBypassMode - PLL Bypass clock mux control. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLBYPASSMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PLLBYPASSMODE_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PLLBYPASSMODE_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSELDFIFREQRATIO_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSELDFIFREQRATIO_SHIFT (6U)
/*! PllSelDfiFreqRatio - reserved. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSELDFIFREQRATIO(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSELDFIFREQRATIO_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSELDFIFREQRATIO_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSYNCBUSFLUSH_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSYNCBUSFLUSH_SHIFT (7U)
/*! PllSyncBusFlush - Used to flush the syncbus logic of the PLL during PHY initialization or LP3 Exit sequence. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSYNCBUSFLUSH(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSYNCBUSFLUSH_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSYNCBUSFLUSH_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSYNCBUSBYP_MASK (0x100U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSYNCBUSBYP_SHIFT (8U)
/*! PllSyncBusByp - When asserted bypasses the Pll SyncPulse and uses a synchronizer of the same latency. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSYNCBUSBYP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSYNCBUSBYP_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSYNCBUSBYP_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLRESERVED10X9_MASK (0x600U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLRESERVED10X9_SHIFT (9U)
/*! PllReserved10x9 - for future use. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLRESERVED10X9(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PLLRESERVED10X9_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PLLRESERVED10X9_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLGEARSHIFT_MASK (0x800U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLGEARSHIFT_SHIFT (11U)
/*! PllGearShift - Puts PLL in fast re-locking mode 0: default, normal mode 1: fast relock gear */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLGEARSHIFT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PLLGEARSHIFT_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PLLGEARSHIFT_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLLOCKCNTSEL_MASK (0x1000U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLLOCKCNTSEL_SHIFT (12U)
/*! PllLockCntSel - Lock detect counter selection. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLLOCKCNTSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PLLLOCKCNTSEL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PLLLOCKCNTSEL_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLLOCKPHSEL_MASK (0x6000U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLLOCKPHSEL_SHIFT (13U)
/*! PllLockPhSel - Lock detect phase selection. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLLOCKPHSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PLLLOCKPHSEL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PLLLOCKPHSEL_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSPARECTRL0_MASK (0x8000U)
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSPARECTRL0_SHIFT (15U)
/*! PllSpareCtrl0 - Spare bits for PLL control. */
#define DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSPARECTRL0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSPARECTRL0_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL0_PLLSPARECTRL0_MASK)
/*! @} */

/*! @name PLLCTRL1_P0 - PState dependent PLL Control Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PLLCPINTCTRL_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PLLCPINTCTRL_SHIFT (0U)
/*! PllCpIntCtrl - connects directly to cp_int_cntrl<1:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PLLCPINTCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PLLCPINTCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PLLCPINTCTRL_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PLLCPPROPCTRL_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PLLCPPROPCTRL_SHIFT (5U)
/*! PllCpPropCtrl - connects directly to cp_prop_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PLLCPPROPCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PLLCPPROPCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P0_PLLCPPROPCTRL_MASK)
/*! @} */

/*! @name PLLTST - PLL Testing Control Register */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLTST_PLLANATSTEN_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLTST_PLLANATSTEN_SHIFT (0U)
/*! PllAnaTstEn - Connects directly to pll_ana_test_en of PLL. */
#define DWC_DDRPHYA_MASTER_PLLTST_PLLANATSTEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLTST_PLLANATSTEN_SHIFT)) & DWC_DDRPHYA_MASTER_PLLTST_PLLANATSTEN_MASK)

#define DWC_DDRPHYA_MASTER_PLLTST_PLLANATSTSEL_MASK (0x1EU)
#define DWC_DDRPHYA_MASTER_PLLTST_PLLANATSTSEL_SHIFT (1U)
/*! PllAnaTstSel - Connects directly to pll_ana_test_sel<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLTST_PLLANATSTSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLTST_PLLANATSTSEL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLTST_PLLANATSTSEL_MASK)

#define DWC_DDRPHYA_MASTER_PLLTST_PLLDIGTSTSEL_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLTST_PLLDIGTSTSEL_SHIFT (5U)
/*! PllDigTstSel - Connects directly to pll_dig_test_sel<2:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLTST_PLLDIGTSTSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLTST_PLLDIGTSTSEL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLTST_PLLDIGTSTSEL_MASK)
/*! @} */

/*! @name PLLLOCKSTATUS - PLL's pll_lock pin output */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLLOCKSTATUS_PLLLOCKSTATUS_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLLOCKSTATUS_PLLLOCKSTATUS_SHIFT (0U)
/*! PllLockStatus - Directly connected to the pll_Lock output. */
#define DWC_DDRPHYA_MASTER_PLLLOCKSTATUS_PLLLOCKSTATUS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLLOCKSTATUS_PLLLOCKSTATUS_SHIFT)) & DWC_DDRPHYA_MASTER_PLLLOCKSTATUS_PLLLOCKSTATUS_MASK)
/*! @} */

/*! @name PLLTESTMODE_P0 - Additional controls for PLL CP/VCO modes of operation */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P0_PLLTESTMODE_P0_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P0_PLLTESTMODE_P0_SHIFT (0U)
/*! PllTestMode_p0 - It is required to use default values for this CSR unless directed otherwise by Synopsys. */
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P0_PLLTESTMODE_P0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLTESTMODE_P0_PLLTESTMODE_P0_SHIFT)) & DWC_DDRPHYA_MASTER_PLLTESTMODE_P0_PLLTESTMODE_P0_MASK)
/*! @} */

/*! @name PLLCTRL3 - PLL Control Register 3 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLSPARE_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLSPARE_SHIFT (0U)
/*! PllSpare - Spare bits for future PLL control modes */
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLSPARE(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL3_PLLSPARE_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL3_PLLSPARE_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLMAXRANGE_MASK (0x1F0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLMAXRANGE_SHIFT (4U)
/*! PllMaxRange - connects directly to maxrange of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLMAXRANGE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL3_PLLMAXRANGE_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL3_PLLMAXRANGE_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLDACVALIN_MASK (0x3E00U)
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLDACVALIN_SHIFT (9U)
/*! PllDacValIn - connects directly to dacval_in<4:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLDACVALIN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL3_PLLDACVALIN_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL3_PLLDACVALIN_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLFORCECAL_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLFORCECAL_SHIFT (14U)
/*! PllForceCal - connects directly to force_cal of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLFORCECAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL3_PLLFORCECAL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL3_PLLFORCECAL_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLENCAL_MASK (0x8000U)
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLENCAL_SHIFT (15U)
/*! PllEnCal - Calibration will run at standby rising edge if en_cal=1 if en_cal=0 calibration will not run */
#define DWC_DDRPHYA_MASTER_PLLCTRL3_PLLENCAL(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL3_PLLENCAL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL3_PLLENCAL_MASK)
/*! @} */

/*! @name PLLCTRL4_P0 - PState dependent PLL Control Register 4 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PLLCPINTGSCTRL_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PLLCPINTGSCTRL_SHIFT (0U)
/*! PllCpIntGsCtrl - connects directly to cp_int_gs_cntrl<4:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PLLCPINTGSCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PLLCPINTGSCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PLLCPINTGSCTRL_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PLLCPPROPGSCTRL_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PLLCPPROPGSCTRL_SHIFT (5U)
/*! PllCpPropGsCtrl - connects directly to cp_prop_gs_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PLLCPPROPGSCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PLLCPPROPGSCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P0_PLLCPPROPGSCTRL_MASK)
/*! @} */

/*! @name PLLENDOFCAL - PLL's eoc (end of calibration) output */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLENDOFCAL_PLLENDOFCAL_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLENDOFCAL_PLLENDOFCAL_SHIFT (0U)
/*! PllEndofCal - Directly connected to the pll's eoc output. */
#define DWC_DDRPHYA_MASTER_PLLENDOFCAL_PLLENDOFCAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLENDOFCAL_PLLENDOFCAL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLENDOFCAL_PLLENDOFCAL_MASK)
/*! @} */

/*! @name PLLSTANDBYEFF - PLL's standby_eff (effective standby) output */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLSTANDBYEFF_PLLSTANDBYEFF_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PLLSTANDBYEFF_PLLSTANDBYEFF_SHIFT (0U)
/*! PllStandbyEff - Returns state off PLL standby. */
#define DWC_DDRPHYA_MASTER_PLLSTANDBYEFF_PLLSTANDBYEFF(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLSTANDBYEFF_PLLSTANDBYEFF_SHIFT)) & DWC_DDRPHYA_MASTER_PLLSTANDBYEFF_PLLSTANDBYEFF_MASK)
/*! @} */

/*! @name PLLDACVALOUT - PLL's Dacval_out output */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLDACVALOUT_PLLDACVALOUT_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLDACVALOUT_PLLDACVALOUT_SHIFT (0U)
/*! PllDacValOut - Directly connected to the pll's dacval_out output. */
#define DWC_DDRPHYA_MASTER_PLLDACVALOUT_PLLDACVALOUT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLDACVALOUT_PLLDACVALOUT_SHIFT)) & DWC_DDRPHYA_MASTER_PLLDACVALOUT_PLLDACVALOUT_MASK)
/*! @} */

/*! @name LCDLDBGCNTL - Controls for use in observing and testing the LCDLs. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINEOVRVAL_MASK (0x1FFU)
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINEOVRVAL_SHIFT (0U)
/*! LcdlFineOvrVal - Value forced as the initial value while LcdlTstEnable=1 and LcdlFineOvr. */
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINEOVRVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINEOVRVAL_SHIFT)) & DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINEOVRVAL_MASK)

#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINEOVR_MASK (0x200U)
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINEOVR_SHIFT (9U)
/*! LcdlFineOvr - Forces the value of the present LCDL 1UI estimate code to be LcdlFineOvrVal for all LCDLs. */
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINEOVR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINEOVR_SHIFT)) & DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINEOVR_MASK)

#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINESNAP_MASK (0x400U)
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINESNAP_SHIFT (10U)
/*! LcdlFineSnap - Latch enable for reading the present LCDL 1UI estimate code in LcdlFineSnapVal
 *    and the present phase-detector value in LcdlPhdSnapVal
 */
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINESNAP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINESNAP_SHIFT)) & DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLFINESNAP_MASK)

#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLTSTENABLE_MASK (0x800U)
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLTSTENABLE_SHIFT (11U)
/*! LcdlTstEnable - Enables the debug/test operations and status Ovr,Snap,StickyLock,StickyUnlock, and LiveLock. */
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLTSTENABLE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLTSTENABLE_SHIFT)) & DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLTSTENABLE_MASK)

#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLSTATUSSEL_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLSTATUSSEL_SHIFT (12U)
/*! LcdlStatusSel - Selects the LCDL status, from among the status for the 16 LCDLs in the DBYTE,
 *    for reading via Register DxLcdlStatus and an LCDL from among the LCDLs in the ANIB for reading
 *    via Register AcLcdlStatus LcdlStatusSel source for DxLcdlStatus source for AcLcdlStatus 15
 *    lcdl_rxclk1t reserved 14 lcdl_rxclk0t reserved 13 lcdl_rxclk1c reserved 12 lcdl_rxclk0c reserved
 *    11 lcdl_rxen1 anib11-tx 10 lcdl_rxen0 anib10-tx 9 lcdl_txln9 (dqs-lower) anib9-tx 8 lcdl_txln8
 *    (dm/dqs-upper) anib8-tx 7 lcdl_txln7 (dq7) anib7-tx 6 lcdl_txln6 (dq6) anib6-tx 5 lcdl_txln5
 *    (dq5) anib5-tx 4 lcdl_txln4 (dq4) anib4-tx 3 lcdl_txln3 (dq3) anib3-tx 2 lcdl_txln2 (dq2)
 *    anib2-tx 1 lcdl_txln1 (dq1) anib1-tx 0 lcdl_txln0 (dq0) anib0-tx
 */
#define DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLSTATUSSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLSTATUSSEL_SHIFT)) & DWC_DDRPHYA_MASTER_LCDLDBGCNTL_LCDLSTATUSSEL_MASK)
/*! @} */

/*! @name ACLCDLSTATUS - Debug status of the DBYTE LCDL */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLFINESNAPVAL_MASK (0x3FFU)
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLFINESNAPVAL_SHIFT (0U)
/*! AcLcdlFineSnapVal - Value of the LCDL 1UI estimate code, latched by pulse on csrLcdlFineSnap while csr LcdlTstEnable=1. */
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLFINESNAPVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLFINESNAPVAL_SHIFT)) & DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLFINESNAPVAL_MASK)

#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLPHDSNAPVAL_MASK (0x400U)
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLPHDSNAPVAL_SHIFT (10U)
/*! AcLcdlPhdSnapVal - Value of the LCDL phase-detector output, latched by pulse on LcdlFineSnap while csr LcdlTstEnable=1. */
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLPHDSNAPVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLPHDSNAPVAL_SHIFT)) & DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLPHDSNAPVAL_MASK)

#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLSTICKYLOCK_MASK (0x800U)
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLSTICKYLOCK_SHIFT (11U)
/*! AcLcdlStickyLock - latched value of whether the LCDL ever achieved lock after the assertion of LcdlTstEnable. */
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLSTICKYLOCK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLSTICKYLOCK_SHIFT)) & DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLSTICKYLOCK_MASK)

#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLSTICKYUNLOCK_MASK (0x1000U)
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLSTICKYUNLOCK_SHIFT (12U)
/*! AcLcdlStickyUnlock - latched value of whether the LCDL ever lost lock after the assertion of LcdlTstEnable. */
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLSTICKYUNLOCK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLSTICKYUNLOCK_SHIFT)) & DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLSTICKYUNLOCK_MASK)

#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLLIVELOCK_MASK (0x2000U)
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLLIVELOCK_SHIFT (13U)
/*! AcLcdlLiveLock - present value of whether the LCDL is locked, valid when LcdlTstEnable=1. */
#define DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLLIVELOCK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLLIVELOCK_SHIFT)) & DWC_DDRPHYA_MASTER_ACLCDLSTATUS_ACLCDLLIVELOCK_MASK)
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

#define DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3EXITSEQ0BSTARTVECPLLENABLED_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3EXITSEQ0BSTARTVECPLLENABLED_SHIFT (0U)
/*! LP3ExitSeq0BStartVecPllEnabled - PIE Start Vector value to be used for LP3-exit or Init and target P-state has PLL enabled */
#define DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3EXITSEQ0BSTARTVECPLLENABLED(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3EXITSEQ0BSTARTVECPLLENABLED_SHIFT)) & DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3EXITSEQ0BSTARTVECPLLENABLED_MASK)

#define DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3EXITSEQ0BSTARTVECPLLBYPASSED_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3EXITSEQ0BSTARTVECPLLBYPASSED_SHIFT (4U)
/*! LP3ExitSeq0BStartVecPllBypassed - PIE Start Vector value to be used for LP3-exit or Init and target P-state has PLL bypassed */
#define DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3EXITSEQ0BSTARTVECPLLBYPASSED(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3EXITSEQ0BSTARTVECPLLBYPASSED_SHIFT)) & DWC_DDRPHYA_MASTER_LP3EXITSEQ0BSTARTVECTOR_LP3EXITSEQ0BSTARTVECPLLBYPASSED_MASK)
/*! @} */

/*! @name DFIFREQXLAT0 - DFI Frequency Translation Register 0 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL0_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL0_SHIFT (0U)
/*! DfiFreqXlatVal0 - The sequencer start vector used when dfi_freq value is 0. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL0_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL1_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL1_SHIFT (4U)
/*! DfiFreqXlatVal1 - The sequencer start vector used when dfi_freq value is 1. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL1_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL2_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL2_SHIFT (8U)
/*! DfiFreqXlatVal2 - The sequencer start vector used when dfi_freq value is 2. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL2_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL3_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL3_SHIFT (12U)
/*! DfiFreqXlatVal3 - The sequencer start vector used when dfi_freq value is 3. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT0_DFIFREQXLATVAL3_MASK)
/*! @} */

/*! @name DFIFREQXLAT1 - DFI Frequency Translation Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL4_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL4_SHIFT (0U)
/*! DfiFreqXlatVal4 - The sequencer start vector used when dfi_freq value is 4. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL4_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL4_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL5_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL5_SHIFT (4U)
/*! DfiFreqXlatVal5 - The sequencer start vector used when dfi_freq value is 5. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL5_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL5_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL6_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL6_SHIFT (8U)
/*! DfiFreqXlatVal6 - The sequencer start vector used when dfi_freq value is 6. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL6_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL6_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL7_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL7_SHIFT (12U)
/*! DfiFreqXlatVal7 - The sequencer start vector used when dfi_freq value is 7. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL7_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT1_DFIFREQXLATVAL7_MASK)
/*! @} */

/*! @name DFIFREQXLAT2 - DFI Frequency Translation Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL8_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL8_SHIFT (0U)
/*! DfiFreqXlatVal8 - The sequencer start vector used when dfi_freq value is 8. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL8_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL8_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL9_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL9_SHIFT (4U)
/*! DfiFreqXlatVal9 - The sequencer start vector used when dfi_freq value is 9. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL9(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL9_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL9_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL10_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL10_SHIFT (8U)
/*! DfiFreqXlatVal10 - The sequencer start vector used when dfi_freq value is 10. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL10(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL10_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL10_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL11_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL11_SHIFT (12U)
/*! DfiFreqXlatVal11 - The sequencer start vector used when dfi_freq value is 11. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL11(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL11_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT2_DFIFREQXLATVAL11_MASK)
/*! @} */

/*! @name DFIFREQXLAT3 - DFI Frequency Translation Register 3 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL12_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL12_SHIFT (0U)
/*! DfiFreqXlatVal12 - The sequencer start vector used when dfi_freq value is 12. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL12(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL12_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL12_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL13_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL13_SHIFT (4U)
/*! DfiFreqXlatVal13 - The sequencer start vector used when dfi_freq value is 13. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL13(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL13_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL13_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL14_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL14_SHIFT (8U)
/*! DfiFreqXlatVal14 - The sequencer start vector used when dfi_freq value is 14. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL14(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL14_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL14_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL15_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL15_SHIFT (12U)
/*! DfiFreqXlatVal15 - The sequencer start vector used when dfi_freq value is 15. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL15(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL15_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT3_DFIFREQXLATVAL15_MASK)
/*! @} */

/*! @name DFIFREQXLAT4 - DFI Frequency Translation Register 4 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL16_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL16_SHIFT (0U)
/*! DfiFreqXlatVal16 - The sequencer start vector used when dfi_freq value is 16. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL16(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL16_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL16_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL17_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL17_SHIFT (4U)
/*! DfiFreqXlatVal17 - The sequencer start vector used when dfi_freq value is 17. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL17(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL17_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL17_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL18_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL18_SHIFT (8U)
/*! DfiFreqXlatVal18 - The sequencer start vector used when dfi_freq value is 18. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL18(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL18_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL18_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL19_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL19_SHIFT (12U)
/*! DfiFreqXlatVal19 - The sequencer start vector used when dfi_freq value is 19. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL19(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL19_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT4_DFIFREQXLATVAL19_MASK)
/*! @} */

/*! @name DFIFREQXLAT5 - DFI Frequency Translation Register 5 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL20_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL20_SHIFT (0U)
/*! DfiFreqXlatVal20 - The sequencer start vector used when dfi_freq value is 20. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL20(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL20_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL20_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL21_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL21_SHIFT (4U)
/*! DfiFreqXlatVal21 - The sequencer start vector used when dfi_freq value is 21. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL21(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL21_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL21_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL22_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL22_SHIFT (8U)
/*! DfiFreqXlatVal22 - The sequencer start vector used when dfi_freq value is 22. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL22(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL22_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL22_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL23_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL23_SHIFT (12U)
/*! DfiFreqXlatVal23 - The sequencer start vector used when dfi_freq value is 23. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL23(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL23_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT5_DFIFREQXLATVAL23_MASK)
/*! @} */

/*! @name DFIFREQXLAT6 - DFI Frequency Translation Register 6 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL24_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL24_SHIFT (0U)
/*! DfiFreqXlatVal24 - The sequencer start vector used when dfi_freq value is 24. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL24(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL24_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL24_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL25_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL25_SHIFT (4U)
/*! DfiFreqXlatVal25 - The sequencer start vector used when dfi_freq value is 25. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL25(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL25_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL25_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL26_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL26_SHIFT (8U)
/*! DfiFreqXlatVal26 - The sequencer start vector used when dfi_freq value is 26. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL26(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL26_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL26_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL27_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL27_SHIFT (12U)
/*! DfiFreqXlatVal27 - The sequencer start vector used when dfi_freq value is 27. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL27(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL27_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT6_DFIFREQXLATVAL27_MASK)
/*! @} */

/*! @name DFIFREQXLAT7 - DFI Frequency Translation Register 7 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL28_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL28_SHIFT (0U)
/*! DfiFreqXlatVal28 - The sequencer start vector used when dfi_freq value is 28. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL28(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL28_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL28_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL29_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL29_SHIFT (4U)
/*! DfiFreqXlatVal29 - The sequencer start vector used when dfi_freq value is 29. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL29(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL29_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL29_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL30_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL30_SHIFT (8U)
/*! DfiFreqXlatVal30 - The sequencer start vector used when dfi_freq value is 30. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL30(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL30_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL30_MASK)

#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL31_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL31_SHIFT (12U)
/*! DfiFreqXlatVal31 - The sequencer start vector used when dfi_freq value is 31. */
#define DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL31(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL31_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQXLAT7_DFIFREQXLATVAL31_MASK)
/*! @} */

/*! @name TXRDPTRINIT - TxRdPtrInit control register */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TXRDPTRINIT_TXRDPTRINIT_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_TXRDPTRINIT_TXRDPTRINIT_SHIFT (0U)
/*! TxRdPtrInit - This register directly controls TxRdPtrInit, and is meant to be written by the
 *    PState sequencer as part of the power state switching sequence.
 */
#define DWC_DDRPHYA_MASTER_TXRDPTRINIT_TXRDPTRINIT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TXRDPTRINIT_TXRDPTRINIT_SHIFT)) & DWC_DDRPHYA_MASTER_TXRDPTRINIT_TXRDPTRINIT_MASK)
/*! @} */

/*! @name DFIINITCOMPLETE - DFI Init Complete control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIINITCOMPLETE_DFIINITCOMPLETE_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DFIINITCOMPLETE_DFIINITCOMPLETE_SHIFT (0U)
/*! DfiInitComplete - This register directly controls DfiInitComplete, and is meant to be written by
 *    the PState sequencer as part of the power state switching sequence.
 */
#define DWC_DDRPHYA_MASTER_DFIINITCOMPLETE_DFIINITCOMPLETE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIINITCOMPLETE_DFIINITCOMPLETE_SHIFT)) & DWC_DDRPHYA_MASTER_DFIINITCOMPLETE_DFIINITCOMPLETE_MASK)
/*! @} */

/*! @name DFIFREQRATIO_P0 - DFI Frequency Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P0_DFIFREQRATIO_P0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P0_DFIFREQRATIO_P0_SHIFT (0U)
/*! DfiFreqRatio_p0 - Used in dwc_ddrphy_pub_serdes to serialize or de-serialize DFI signals 00 =
 *    1:1 mode 01 = 1:2 mode 1x = 1:4 mode* *Note: 1:4 is for future pub revision.
 */
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P0_DFIFREQRATIO_P0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQRATIO_P0_DFIFREQRATIO_P0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQRATIO_P0_DFIFREQRATIO_P0_MASK)
/*! @} */

/*! @name RXFIFOCHECKS - Enable more frequent consistency checks of the RX FIFOs */
/*! @{ */

#define DWC_DDRPHYA_MASTER_RXFIFOCHECKS_DOFREQUENTRXFIFOCHECKS_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_RXFIFOCHECKS_DOFREQUENTRXFIFOCHECKS_SHIFT (0U)
/*! DoFrequentRxFifoChecks - When 0, read data FIFO pointer consistency checks are performed only during sideband transactions (i. */
#define DWC_DDRPHYA_MASTER_RXFIFOCHECKS_DOFREQUENTRXFIFOCHECKS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_RXFIFOCHECKS_DOFREQUENTRXFIFOCHECKS_SHIFT)) & DWC_DDRPHYA_MASTER_RXFIFOCHECKS_DOFREQUENTRXFIFOCHECKS_MASK)
/*! @} */

/*! @name MTESTDTOCTRL -  */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MTESTDTOCTRL_MTESTDTOCTRL_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_MTESTDTOCTRL_MTESTDTOCTRL_SHIFT (0U)
/*! MTestDtoCtrl - MTESTdtoEn==[0], dwc_ddrphy_dto will be squelched (0) MTESTdtoEn==[1],
 *    dwc_ddrphy_dto will reflect the observability signal multiplexed on MTestCombo
 */
#define DWC_DDRPHYA_MASTER_MTESTDTOCTRL_MTESTDTOCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MTESTDTOCTRL_MTESTDTOCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_MTESTDTOCTRL_MTESTDTOCTRL_MASK)
/*! @} */

/*! @name MAPCAA0TODFI - Maps PHY CAA lane 0 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA0TODFI_MAPCAA0TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA0TODFI_MAPCAA0TODFI_SHIFT (0U)
/*! MapCAA0toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 0. */
#define DWC_DDRPHYA_MASTER_MAPCAA0TODFI_MAPCAA0TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA0TODFI_MAPCAA0TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA0TODFI_MAPCAA0TODFI_MASK)
/*! @} */

/*! @name MAPCAA1TODFI - Maps PHY CAA lane 1 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA1TODFI_MAPCAA1TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA1TODFI_MAPCAA1TODFI_SHIFT (0U)
/*! MapCAA1toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 1. */
#define DWC_DDRPHYA_MASTER_MAPCAA1TODFI_MAPCAA1TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA1TODFI_MAPCAA1TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA1TODFI_MAPCAA1TODFI_MASK)
/*! @} */

/*! @name MAPCAA2TODFI - Maps PHY CAA lane 2 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA2TODFI_MAPCAA2TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA2TODFI_MAPCAA2TODFI_SHIFT (0U)
/*! MapCAA2toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 2. */
#define DWC_DDRPHYA_MASTER_MAPCAA2TODFI_MAPCAA2TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA2TODFI_MAPCAA2TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA2TODFI_MAPCAA2TODFI_MASK)
/*! @} */

/*! @name MAPCAA3TODFI - Maps PHY CAA lane 3 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA3TODFI_MAPCAA3TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA3TODFI_MAPCAA3TODFI_SHIFT (0U)
/*! MapCAA3toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 3. */
#define DWC_DDRPHYA_MASTER_MAPCAA3TODFI_MAPCAA3TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA3TODFI_MAPCAA3TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA3TODFI_MAPCAA3TODFI_MASK)
/*! @} */

/*! @name MAPCAA4TODFI - Maps PHY CAA lane 4 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA4TODFI_MAPCAA4TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA4TODFI_MAPCAA4TODFI_SHIFT (0U)
/*! MapCAA4toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 4. */
#define DWC_DDRPHYA_MASTER_MAPCAA4TODFI_MAPCAA4TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA4TODFI_MAPCAA4TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA4TODFI_MAPCAA4TODFI_MASK)
/*! @} */

/*! @name MAPCAA5TODFI - Maps PHY CAA lane 5 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA5TODFI_MAPCAA5TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA5TODFI_MAPCAA5TODFI_SHIFT (0U)
/*! MapCAA5toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 5. */
#define DWC_DDRPHYA_MASTER_MAPCAA5TODFI_MAPCAA5TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA5TODFI_MAPCAA5TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA5TODFI_MAPCAA5TODFI_MASK)
/*! @} */

/*! @name MAPCAA6TODFI - Maps PHY CAA lane 6 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA6TODFI_MAPCAA6TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA6TODFI_MAPCAA6TODFI_SHIFT (0U)
/*! MapCAA6toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 6. */
#define DWC_DDRPHYA_MASTER_MAPCAA6TODFI_MAPCAA6TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA6TODFI_MAPCAA6TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA6TODFI_MAPCAA6TODFI_MASK)
/*! @} */

/*! @name MAPCAA7TODFI - Maps PHY CAA lane 7 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA7TODFI_MAPCAA7TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA7TODFI_MAPCAA7TODFI_SHIFT (0U)
/*! MapCAA7toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 7. */
#define DWC_DDRPHYA_MASTER_MAPCAA7TODFI_MAPCAA7TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA7TODFI_MAPCAA7TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA7TODFI_MAPCAA7TODFI_MASK)
/*! @} */

/*! @name MAPCAA8TODFI - Maps PHY CAA lane 8 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA8TODFI_MAPCAA8TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA8TODFI_MAPCAA8TODFI_SHIFT (0U)
/*! MapCAA8toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 8. */
#define DWC_DDRPHYA_MASTER_MAPCAA8TODFI_MAPCAA8TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA8TODFI_MAPCAA8TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA8TODFI_MAPCAA8TODFI_MASK)
/*! @} */

/*! @name MAPCAA9TODFI - Maps PHY CAA lane 9 from dfi0_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAA9TODFI_MAPCAA9TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAA9TODFI_MAPCAA9TODFI_SHIFT (0U)
/*! MapCAA9toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi0_address to CAA 9. */
#define DWC_DDRPHYA_MASTER_MAPCAA9TODFI_MAPCAA9TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAA9TODFI_MAPCAA9TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAA9TODFI_MAPCAA9TODFI_MASK)
/*! @} */

/*! @name MAPCAB0TODFI - Maps PHY CAB lane 0 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB0TODFI_MAPCAB0TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB0TODFI_MAPCAB0TODFI_SHIFT (0U)
/*! MapCAB0toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 0. */
#define DWC_DDRPHYA_MASTER_MAPCAB0TODFI_MAPCAB0TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB0TODFI_MAPCAB0TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB0TODFI_MAPCAB0TODFI_MASK)
/*! @} */

/*! @name MAPCAB1TODFI - Maps PHY CAB lane 1 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB1TODFI_MAPCAB1TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB1TODFI_MAPCAB1TODFI_SHIFT (0U)
/*! MapCAB1toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 1. */
#define DWC_DDRPHYA_MASTER_MAPCAB1TODFI_MAPCAB1TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB1TODFI_MAPCAB1TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB1TODFI_MAPCAB1TODFI_MASK)
/*! @} */

/*! @name MAPCAB2TODFI - Maps PHY CAB lane 2 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB2TODFI_MAPCAB2TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB2TODFI_MAPCAB2TODFI_SHIFT (0U)
/*! MapCAB2toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 2. */
#define DWC_DDRPHYA_MASTER_MAPCAB2TODFI_MAPCAB2TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB2TODFI_MAPCAB2TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB2TODFI_MAPCAB2TODFI_MASK)
/*! @} */

/*! @name MAPCAB3TODFI - Maps PHY CAB lane 3 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB3TODFI_MAPCAB3TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB3TODFI_MAPCAB3TODFI_SHIFT (0U)
/*! MapCAB3toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 3. */
#define DWC_DDRPHYA_MASTER_MAPCAB3TODFI_MAPCAB3TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB3TODFI_MAPCAB3TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB3TODFI_MAPCAB3TODFI_MASK)
/*! @} */

/*! @name MAPCAB4TODFI - Maps PHY CAB lane 4 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB4TODFI_MAPCAB4TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB4TODFI_MAPCAB4TODFI_SHIFT (0U)
/*! MapCAB4toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 4. */
#define DWC_DDRPHYA_MASTER_MAPCAB4TODFI_MAPCAB4TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB4TODFI_MAPCAB4TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB4TODFI_MAPCAB4TODFI_MASK)
/*! @} */

/*! @name MAPCAB5TODFI - Maps PHY CAB lane 5 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB5TODFI_MAPCAB5TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB5TODFI_MAPCAB5TODFI_SHIFT (0U)
/*! MapCAB5toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 5. */
#define DWC_DDRPHYA_MASTER_MAPCAB5TODFI_MAPCAB5TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB5TODFI_MAPCAB5TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB5TODFI_MAPCAB5TODFI_MASK)
/*! @} */

/*! @name MAPCAB6TODFI - Maps PHY CAB lane 6 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB6TODFI_MAPCAB6TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB6TODFI_MAPCAB6TODFI_SHIFT (0U)
/*! MapCAB6toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 6. */
#define DWC_DDRPHYA_MASTER_MAPCAB6TODFI_MAPCAB6TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB6TODFI_MAPCAB6TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB6TODFI_MAPCAB6TODFI_MASK)
/*! @} */

/*! @name MAPCAB7TODFI - Maps PHY CAB lane 7 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB7TODFI_MAPCAB7TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB7TODFI_MAPCAB7TODFI_SHIFT (0U)
/*! MapCAB7toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 7. */
#define DWC_DDRPHYA_MASTER_MAPCAB7TODFI_MAPCAB7TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB7TODFI_MAPCAB7TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB7TODFI_MAPCAB7TODFI_MASK)
/*! @} */

/*! @name MAPCAB8TODFI - Maps PHY CAB lane 8 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB8TODFI_MAPCAB8TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB8TODFI_MAPCAB8TODFI_SHIFT (0U)
/*! MapCAB8toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 8. */
#define DWC_DDRPHYA_MASTER_MAPCAB8TODFI_MAPCAB8TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB8TODFI_MAPCAB8TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB8TODFI_MAPCAB8TODFI_MASK)
/*! @} */

/*! @name MAPCAB9TODFI - Maps PHY CAB lane 9 from dfi1_address of the index of the register contents */
/*! @{ */

#define DWC_DDRPHYA_MASTER_MAPCAB9TODFI_MAPCAB9TODFI_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_MAPCAB9TODFI_MAPCAB9TODFI_SHIFT (0U)
/*! MapCAB9toDfi - For LPDDR3 and LPDDR4 applications, these CSRs map a dfi1_address to CAB 9. */
#define DWC_DDRPHYA_MASTER_MAPCAB9TODFI_MAPCAB9TODFI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_MAPCAB9TODFI_MAPCAB9TODFI_SHIFT)) & DWC_DDRPHYA_MASTER_MAPCAB9TODFI_MAPCAB9TODFI_MASK)
/*! @} */

/*! @name PHYINTERRUPTENABLE - Interrupt Enable Bits */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYTRNGCMPLTEN_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYTRNGCMPLTEN_SHIFT (0U)
/*! PhyTrngCmpltEn - Enable for the PHY Training Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYTRNGCMPLTEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYTRNGCMPLTEN_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYTRNGCMPLTEN_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYINITCMPLTEN_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYINITCMPLTEN_SHIFT (1U)
/*! PhyInitCmpltEn - Enable for the PHY Initialization Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYINITCMPLTEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYINITCMPLTEN_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYINITCMPLTEN_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYTRNGFAILEN_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYTRNGFAILEN_SHIFT (2U)
/*! PhyTrngFailEn - Enable for the PHY Training Failure interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYTRNGFAILEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYTRNGFAILEN_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYTRNGFAILEN_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYFWRESERVEDEN_MASK (0xF8U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYFWRESERVEDEN_SHIFT (3U)
/*! PhyFWReservedEn - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYFWRESERVEDEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYFWRESERVEDEN_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYFWRESERVEDEN_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYVTDRIFTALARMEN_MASK (0x300U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYVTDRIFTALARMEN_SHIFT (8U)
/*! PhyVTDriftAlarmEn - Enable for the PHY VT Drift Alarm interrupts. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYVTDRIFTALARMEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYVTDRIFTALARMEN_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYVTDRIFTALARMEN_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYRXFIFOCHECKEN_MASK (0x400U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYRXFIFOCHECKEN_SHIFT (10U)
/*! PhyRxFifoCheckEn - Enable for the RxFifo Pointers Check Interrupt 0 : Interrupt not enabled 1 : Interrupt enabled */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYRXFIFOCHECKEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYRXFIFOCHECKEN_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYRXFIFOCHECKEN_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYHWRESERVEDEN_MASK (0xF800U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYHWRESERVEDEN_SHIFT (11U)
/*! PhyHWReservedEn - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYHWRESERVEDEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYHWRESERVEDEN_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTENABLE_PHYHWRESERVEDEN_MASK)
/*! @} */

/*! @name PHYINTERRUPTFWCONTROL - Interrupt Firmware Control Bits */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYTRNGCMPLTFW_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYTRNGCMPLTFW_SHIFT (0U)
/*! PhyTrngCmpltFW - PHY Training Complete Firmware interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYTRNGCMPLTFW(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYTRNGCMPLTFW_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYTRNGCMPLTFW_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYINITCMPLTFW_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYINITCMPLTFW_SHIFT (1U)
/*! PhyInitCmpltFW - PHY Initialization Complete Firmware interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYINITCMPLTFW(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYINITCMPLTFW_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYINITCMPLTFW_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYTRNGFAILFW_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYTRNGFAILFW_SHIFT (2U)
/*! PhyTrngFailFW - PHY Training Failure Firmware interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYTRNGFAILFW(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYTRNGFAILFW_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYTRNGFAILFW_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYFWRESERVEDFW_MASK (0xF8U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYFWRESERVEDFW_SHIFT (3U)
/*! PhyFWReservedFW - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYFWRESERVEDFW(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYFWRESERVEDFW_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTFWCONTROL_PHYFWRESERVEDFW_MASK)
/*! @} */

/*! @name PHYINTERRUPTMASK - Interrupt Mask Bits */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYTRNGCMPLTMSK_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYTRNGCMPLTMSK_SHIFT (0U)
/*! PhyTrngCmpltMsk - Mask for the PHY Training Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYTRNGCMPLTMSK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYTRNGCMPLTMSK_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYTRNGCMPLTMSK_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYINITCMPLTMSK_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYINITCMPLTMSK_SHIFT (1U)
/*! PhyInitCmpltMsk - Mask for the PHY Initialization Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYINITCMPLTMSK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYINITCMPLTMSK_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYINITCMPLTMSK_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYTRNGFAILMSK_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYTRNGFAILMSK_SHIFT (2U)
/*! PhyTrngFailMsk - Mask for the PHY Training Failure interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYTRNGFAILMSK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYTRNGFAILMSK_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYTRNGFAILMSK_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYFWRESERVEDMSK_MASK (0xF8U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYFWRESERVEDMSK_SHIFT (3U)
/*! PhyFWReservedMsk - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYFWRESERVEDMSK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYFWRESERVEDMSK_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYFWRESERVEDMSK_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYVTDRIFTALARMMSK_MASK (0x300U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYVTDRIFTALARMMSK_SHIFT (8U)
/*! PhyVTDriftAlarmMsk - Mask for the PHY VT Drift Alarm interrupts. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYVTDRIFTALARMMSK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYVTDRIFTALARMMSK_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYVTDRIFTALARMMSK_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYRXFIFOCHECKMSK_MASK (0x400U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYRXFIFOCHECKMSK_SHIFT (10U)
/*! PhyRxFifoCheckMsk - Mask for the RxFifo Pointers Check Interrupt 0 : Interrupt not masked 1 : Interrupt masked */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYRXFIFOCHECKMSK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYRXFIFOCHECKMSK_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYRXFIFOCHECKMSK_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYHWRESERVEDMSK_MASK (0xF800U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYHWRESERVEDMSK_SHIFT (11U)
/*! PhyHWReservedMsk - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYHWRESERVEDMSK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYHWRESERVEDMSK_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTMASK_PHYHWRESERVEDMSK_MASK)
/*! @} */

/*! @name PHYINTERRUPTCLEAR - Interrupt Clear Bits */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYTRNGCMPLTCLR_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYTRNGCMPLTCLR_SHIFT (0U)
/*! PhyTrngCmpltClr - Clear for the PHY Training Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYTRNGCMPLTCLR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYTRNGCMPLTCLR_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYTRNGCMPLTCLR_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYINITCMPLTCLR_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYINITCMPLTCLR_SHIFT (1U)
/*! PhyInitCmpltClr - Clear for the PHY Initialization Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYINITCMPLTCLR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYINITCMPLTCLR_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYINITCMPLTCLR_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYTRNGFAILCLR_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYTRNGFAILCLR_SHIFT (2U)
/*! PhyTrngFailClr - Clear for the PHY Training Failure interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYTRNGFAILCLR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYTRNGFAILCLR_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYTRNGFAILCLR_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYFWRESERVEDCLR_MASK (0xF8U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYFWRESERVEDCLR_SHIFT (3U)
/*! PhyFWReservedClr - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYFWRESERVEDCLR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYFWRESERVEDCLR_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYFWRESERVEDCLR_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYVTDRIFTALARMCLR_MASK (0x300U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYVTDRIFTALARMCLR_SHIFT (8U)
/*! PhyVTDriftAlarmClr - Clear for the PHY VT Drift Alarm interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYVTDRIFTALARMCLR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYVTDRIFTALARMCLR_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYVTDRIFTALARMCLR_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYRXFIFOCHECKCLR_MASK (0x400U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYRXFIFOCHECKCLR_SHIFT (10U)
/*! PhyRxFifoCheckClr - Clear for the RxFifo Pointers Check Interrupt 0 : Interrupt not affected 1 : Interrupt cleared */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYRXFIFOCHECKCLR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYRXFIFOCHECKCLR_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYRXFIFOCHECKCLR_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYHWRESERVEDCLR_MASK (0xF800U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYHWRESERVEDCLR_SHIFT (11U)
/*! PhyHWReservedClr - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYHWRESERVEDCLR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYHWRESERVEDCLR_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTCLEAR_PHYHWRESERVEDCLR_MASK)
/*! @} */

/*! @name PHYINTERRUPTSTATUS - Interrupt Status Bits */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYTRNGCMPLT_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYTRNGCMPLT_SHIFT (0U)
/*! PhyTrngCmplt - PHY Training Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYTRNGCMPLT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYTRNGCMPLT_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYTRNGCMPLT_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYINITCMPLT_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYINITCMPLT_SHIFT (1U)
/*! PhyInitCmplt - PHY Initialization Complete interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYINITCMPLT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYINITCMPLT_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYINITCMPLT_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYTRNGFAIL_MASK (0x4U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYTRNGFAIL_SHIFT (2U)
/*! PhyTrngFail - PHY Training Failure interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYTRNGFAIL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYTRNGFAIL_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYTRNGFAIL_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYFWRESERVED_MASK (0xF8U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYFWRESERVED_SHIFT (3U)
/*! PhyFWReserved - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYFWRESERVED(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYFWRESERVED_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYFWRESERVED_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_VTDRIFTALARM_MASK (0x300U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_VTDRIFTALARM_SHIFT (8U)
/*! VTDriftAlarm - PHY VT Drift Alarm interrupt. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_VTDRIFTALARM(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_VTDRIFTALARM_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_VTDRIFTALARM_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYRXFIFOCHECK_MASK (0x400U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYRXFIFOCHECK_SHIFT (10U)
/*! PhyRxFifoCheck - A mechanism in the PHY checks the Read Fifo pointers for consistency at times they are idle. */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYRXFIFOCHECK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYRXFIFOCHECK_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYRXFIFOCHECK_MASK)

#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYHWRESERVED_MASK (0xF800U)
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYHWRESERVED_SHIFT (11U)
/*! PhyHWReserved - Reserved */
#define DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYHWRESERVED(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYHWRESERVED_SHIFT)) & DWC_DDRPHYA_MASTER_PHYINTERRUPTSTATUS_PHYHWRESERVED_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS0 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS0_HWTSWIZZLEHWTADDRESS0_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS0_HWTSWIZZLEHWTADDRESS0_SHIFT (0U)
/*! HwtSwizzleHwtAddress0 - This set of registers is used in DDR3/DDR4 mode where a user has re-mapped the DFI inputs to the PHY. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS0_HWTSWIZZLEHWTADDRESS0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS0_HWTSWIZZLEHWTADDRESS0_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS0_HWTSWIZZLEHWTADDRESS0_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS1 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS1_HWTSWIZZLEHWTADDRESS1_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS1_HWTSWIZZLEHWTADDRESS1_SHIFT (0U)
/*! HwtSwizzleHwtAddress1 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS1_HWTSWIZZLEHWTADDRESS1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS1_HWTSWIZZLEHWTADDRESS1_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS1_HWTSWIZZLEHWTADDRESS1_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS2 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS2_HWTSWIZZLEHWTADDRESS2_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS2_HWTSWIZZLEHWTADDRESS2_SHIFT (0U)
/*! HwtSwizzleHwtAddress2 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS2_HWTSWIZZLEHWTADDRESS2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS2_HWTSWIZZLEHWTADDRESS2_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS2_HWTSWIZZLEHWTADDRESS2_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS3 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS3_HWTSWIZZLEHWTADDRESS3_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS3_HWTSWIZZLEHWTADDRESS3_SHIFT (0U)
/*! HwtSwizzleHwtAddress3 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS3_HWTSWIZZLEHWTADDRESS3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS3_HWTSWIZZLEHWTADDRESS3_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS3_HWTSWIZZLEHWTADDRESS3_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS4 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS4_HWTSWIZZLEHWTADDRESS4_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS4_HWTSWIZZLEHWTADDRESS4_SHIFT (0U)
/*! HwtSwizzleHwtAddress4 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS4_HWTSWIZZLEHWTADDRESS4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS4_HWTSWIZZLEHWTADDRESS4_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS4_HWTSWIZZLEHWTADDRESS4_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS5 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS5_HWTSWIZZLEHWTADDRESS5_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS5_HWTSWIZZLEHWTADDRESS5_SHIFT (0U)
/*! HwtSwizzleHwtAddress5 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS5_HWTSWIZZLEHWTADDRESS5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS5_HWTSWIZZLEHWTADDRESS5_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS5_HWTSWIZZLEHWTADDRESS5_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS6 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS6_HWTSWIZZLEHWTADDRESS6_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS6_HWTSWIZZLEHWTADDRESS6_SHIFT (0U)
/*! HwtSwizzleHwtAddress6 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS6_HWTSWIZZLEHWTADDRESS6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS6_HWTSWIZZLEHWTADDRESS6_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS6_HWTSWIZZLEHWTADDRESS6_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS7 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS7_HWTSWIZZLEHWTADDRESS7_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS7_HWTSWIZZLEHWTADDRESS7_SHIFT (0U)
/*! HwtSwizzleHwtAddress7 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS7_HWTSWIZZLEHWTADDRESS7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS7_HWTSWIZZLEHWTADDRESS7_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS7_HWTSWIZZLEHWTADDRESS7_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS8 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS8_HWTSWIZZLEHWTADDRESS8_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS8_HWTSWIZZLEHWTADDRESS8_SHIFT (0U)
/*! HwtSwizzleHwtAddress8 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS8_HWTSWIZZLEHWTADDRESS8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS8_HWTSWIZZLEHWTADDRESS8_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS8_HWTSWIZZLEHWTADDRESS8_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS9 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS9_HWTSWIZZLEHWTADDRESS9_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS9_HWTSWIZZLEHWTADDRESS9_SHIFT (0U)
/*! HwtSwizzleHwtAddress9 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS9_HWTSWIZZLEHWTADDRESS9(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS9_HWTSWIZZLEHWTADDRESS9_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS9_HWTSWIZZLEHWTADDRESS9_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS10 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS10_HWTSWIZZLEHWTADDRESS10_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS10_HWTSWIZZLEHWTADDRESS10_SHIFT (0U)
/*! HwtSwizzleHwtAddress10 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS10_HWTSWIZZLEHWTADDRESS10(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS10_HWTSWIZZLEHWTADDRESS10_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS10_HWTSWIZZLEHWTADDRESS10_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS11 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS11_HWTSWIZZLEHWTADDRESS11_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS11_HWTSWIZZLEHWTADDRESS11_SHIFT (0U)
/*! HwtSwizzleHwtAddress11 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS11_HWTSWIZZLEHWTADDRESS11(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS11_HWTSWIZZLEHWTADDRESS11_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS11_HWTSWIZZLEHWTADDRESS11_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS12 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS12_HWTSWIZZLEHWTADDRESS12_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS12_HWTSWIZZLEHWTADDRESS12_SHIFT (0U)
/*! HwtSwizzleHwtAddress12 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS12_HWTSWIZZLEHWTADDRESS12(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS12_HWTSWIZZLEHWTADDRESS12_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS12_HWTSWIZZLEHWTADDRESS12_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS13 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS13_HWTSWIZZLEHWTADDRESS13_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS13_HWTSWIZZLEHWTADDRESS13_SHIFT (0U)
/*! HwtSwizzleHwtAddress13 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS13_HWTSWIZZLEHWTADDRESS13(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS13_HWTSWIZZLEHWTADDRESS13_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS13_HWTSWIZZLEHWTADDRESS13_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS14 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS14_HWTSWIZZLEHWTADDRESS14_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS14_HWTSWIZZLEHWTADDRESS14_SHIFT (0U)
/*! HwtSwizzleHwtAddress14 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS14_HWTSWIZZLEHWTADDRESS14(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS14_HWTSWIZZLEHWTADDRESS14_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS14_HWTSWIZZLEHWTADDRESS14_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS15 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS15_HWTSWIZZLEHWTADDRESS15_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS15_HWTSWIZZLEHWTADDRESS15_SHIFT (0U)
/*! HwtSwizzleHwtAddress15 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS15_HWTSWIZZLEHWTADDRESS15(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS15_HWTSWIZZLEHWTADDRESS15_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS15_HWTSWIZZLEHWTADDRESS15_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTADDRESS17 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS17_HWTSWIZZLEHWTADDRESS17_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS17_HWTSWIZZLEHWTADDRESS17_SHIFT (0U)
/*! HwtSwizzleHwtAddress17 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS17_HWTSWIZZLEHWTADDRESS17(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS17_HWTSWIZZLEHWTADDRESS17_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTADDRESS17_HWTSWIZZLEHWTADDRESS17_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTACTN - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTACTN_HWTSWIZZLEHWTACTN_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTACTN_HWTSWIZZLEHWTACTN_SHIFT (0U)
/*! HwtSwizzleHwtActN - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTACTN_HWTSWIZZLEHWTACTN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTACTN_HWTSWIZZLEHWTACTN_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTACTN_HWTSWIZZLEHWTACTN_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTBANK0 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK0_HWTSWIZZLEHWTBANK0_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK0_HWTSWIZZLEHWTBANK0_SHIFT (0U)
/*! HwtSwizzleHwtBank0 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK0_HWTSWIZZLEHWTBANK0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK0_HWTSWIZZLEHWTBANK0_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK0_HWTSWIZZLEHWTBANK0_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTBANK1 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK1_HWTSWIZZLEHWTBANK1_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK1_HWTSWIZZLEHWTBANK1_SHIFT (0U)
/*! HwtSwizzleHwtBank1 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK1_HWTSWIZZLEHWTBANK1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK1_HWTSWIZZLEHWTBANK1_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK1_HWTSWIZZLEHWTBANK1_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTBANK2 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK2_HWTSWIZZLEHWTBANK2_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK2_HWTSWIZZLEHWTBANK2_SHIFT (0U)
/*! HwtSwizzleHwtBank2 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK2_HWTSWIZZLEHWTBANK2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK2_HWTSWIZZLEHWTBANK2_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBANK2_HWTSWIZZLEHWTBANK2_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTBG0 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG0_HWTSWIZZLEHWTBG0_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG0_HWTSWIZZLEHWTBG0_SHIFT (0U)
/*! HwtSwizzleHwtBg0 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG0_HWTSWIZZLEHWTBG0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG0_HWTSWIZZLEHWTBG0_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG0_HWTSWIZZLEHWTBG0_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTBG1 - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG1_HWTSWIZZLEHWTBG1_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG1_HWTSWIZZLEHWTBG1_SHIFT (0U)
/*! HwtSwizzleHwtBg1 - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG1_HWTSWIZZLEHWTBG1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG1_HWTSWIZZLEHWTBG1_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTBG1_HWTSWIZZLEHWTBG1_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTCASN - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTCASN_HWTSWIZZLEHWTCASN_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTCASN_HWTSWIZZLEHWTCASN_SHIFT (0U)
/*! HwtSwizzleHwtCasN - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTCASN_HWTSWIZZLEHWTCASN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTCASN_HWTSWIZZLEHWTCASN_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTCASN_HWTSWIZZLEHWTCASN_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTRASN - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTRASN_HWTSWIZZLEHWTRASN_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTRASN_HWTSWIZZLEHWTRASN_SHIFT (0U)
/*! HwtSwizzleHwtRasN - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTRASN_HWTSWIZZLEHWTRASN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTRASN_HWTSWIZZLEHWTRASN_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTRASN_HWTSWIZZLEHWTRASN_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTWEN - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTWEN_HWTSWIZZLEHWTWEN_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTWEN_HWTSWIZZLEHWTWEN_SHIFT (0U)
/*! HwtSwizzleHwtWeN - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTWEN_HWTSWIZZLEHWTWEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTWEN_HWTSWIZZLEHWTWEN_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTWEN_HWTSWIZZLEHWTWEN_MASK)
/*! @} */

/*! @name HWTSWIZZLEHWTPARITYIN - Signal swizzle selection for HWT swizzle */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTPARITYIN_HWTSWIZZLEHWTPARITYIN_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTPARITYIN_HWTSWIZZLEHWTPARITYIN_SHIFT (0U)
/*! HwtSwizzleHwtParityIn - See Description of HwtSwizzleHwtAddress0 for details. */
#define DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTPARITYIN_HWTSWIZZLEHWTPARITYIN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTPARITYIN_HWTSWIZZLEHWTPARITYIN_SHIFT)) & DWC_DDRPHYA_MASTER_HWTSWIZZLEHWTPARITYIN_HWTSWIZZLEHWTPARITYIN_MASK)
/*! @} */

/*! @name DFIHANDSHAKEDELAYS0 - Add assertion/deassertion delays on handshake signals Logic assumes that dfi signal assertions exceed the programmed delays */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PHYUPDACKDELAY0_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PHYUPDACKDELAY0_SHIFT (0U)
/*! PhyUpdAckDelay0 - Adds 0-15 DfiClks of delay after dfi0_phyupd_ack asserts, before the PHY takes
 *    any action (such as starting DDL calibration).
 */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PHYUPDACKDELAY0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PHYUPDACKDELAY0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PHYUPDACKDELAY0_MASK)

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PHYUPDREQDELAY0_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PHYUPDREQDELAY0_SHIFT (4U)
/*! PhyUpdReqDelay0 - Adds 0-15 DfiClks of delay after the PHY completes all PHY update activities, before deasserting dfi0_phyupd_req. */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PHYUPDREQDELAY0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PHYUPDREQDELAY0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_PHYUPDREQDELAY0_MASK)

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CTRLUPDACKDELAY0_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CTRLUPDACKDELAY0_SHIFT (8U)
/*! CtrlUpdAckDelay0 - Adds 0-15 DfiClks of delay after dfi0_ctrlupd_req asserts, before the PHY takes any action. */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CTRLUPDACKDELAY0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CTRLUPDACKDELAY0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CTRLUPDACKDELAY0_MASK)

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CTRLUPDREQDELAY0_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CTRLUPDREQDELAY0_SHIFT (12U)
/*! CtrlUpdReqDelay0 - Adds 0-15 DfiClks of delay after the PHY completes all PHY update activities, before deasserting dfi0_ctrlupd_ack. */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CTRLUPDREQDELAY0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CTRLUPDREQDELAY0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS0_CTRLUPDREQDELAY0_MASK)
/*! @} */

/*! @name DFIHANDSHAKEDELAYS1 - Add assertion/deassertion delays on handshake signals Logic assumes that dfi signal assertions exceed the programmed delays */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PHYUPDACKDELAY1_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PHYUPDACKDELAY1_SHIFT (0U)
/*! PhyUpdAckDelay1 - Adds 0-15 DfiClks of delay after dfi1_phyupd_ack asserts, before the PHY takes
 *    any action (such as starting DDL calibration).
 */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PHYUPDACKDELAY1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PHYUPDACKDELAY1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PHYUPDACKDELAY1_MASK)

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PHYUPDREQDELAY1_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PHYUPDREQDELAY1_SHIFT (4U)
/*! PhyUpdReqDelay1 - Adds 0-15 DfiClks of delay after the PHY completes all PHY update activities, before deasserting dfi1_phyupd_req. */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PHYUPDREQDELAY1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PHYUPDREQDELAY1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_PHYUPDREQDELAY1_MASK)

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CTRLUPDACKDELAY1_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CTRLUPDACKDELAY1_SHIFT (8U)
/*! CtrlUpdAckDelay1 - Adds 0-15 DfiClks of delay after dfi1_ctrlupd_req asserts, before the PHY takes any action. */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CTRLUPDACKDELAY1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CTRLUPDACKDELAY1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CTRLUPDACKDELAY1_MASK)

#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CTRLUPDREQDELAY1_MASK (0xF000U)
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CTRLUPDREQDELAY1_SHIFT (12U)
/*! CtrlUpdReqDelay1 - Adds 0-15 DfiClks of delay after the PHY completes all PHY update activities, before deasserting dfi1_ctrlupd_ack. */
#define DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CTRLUPDREQDELAY1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CTRLUPDREQDELAY1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIHANDSHAKEDELAYS1_CTRLUPDREQDELAY1_MASK)
/*! @} */

/*! @name CALUCLKINFO_P1 - Impedance Calibration Clock Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P1_CALUCLKTICKSPER1US_MASK (0x3FFU)
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P1_CALUCLKTICKSPER1US_SHIFT (0U)
/*! CalUClkTicksPer1uS - Must be programmed to the number of DfiClks in 1us (rounded up), with minimum value of 24. */
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P1_CALUCLKTICKSPER1US(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALUCLKINFO_P1_CALUCLKTICKSPER1US_SHIFT)) & DWC_DDRPHYA_MASTER_CALUCLKINFO_P1_CALUCLKTICKSPER1US_MASK)
/*! @} */

/*! @name SEQ0BDLY0_P1 - PHY Initialization Engine (PIE) Delay Register 0 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P1_SEQ0BDLY0_P1_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P1_SEQ0BDLY0_P1_SHIFT (0U)
/*! Seq0BDLY0_p1 - PHY Initialization Engine (PIE) Delay Register 0 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P1_SEQ0BDLY0_P1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY0_P1_SEQ0BDLY0_P1_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY0_P1_SEQ0BDLY0_P1_MASK)
/*! @} */

/*! @name SEQ0BDLY1_P1 - PHY Initialization Engine (PIE) Delay Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P1_SEQ0BDLY1_P1_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P1_SEQ0BDLY1_P1_SHIFT (0U)
/*! Seq0BDLY1_p1 - PHY Initialization Engine (PIE) Delay Register 1 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P1_SEQ0BDLY1_P1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY1_P1_SEQ0BDLY1_P1_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY1_P1_SEQ0BDLY1_P1_MASK)
/*! @} */

/*! @name SEQ0BDLY2_P1 - PHY Initialization Engine (PIE) Delay Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P1_SEQ0BDLY2_P1_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P1_SEQ0BDLY2_P1_SHIFT (0U)
/*! Seq0BDLY2_p1 - PHY Initialization Engine (PIE) Delay Register 2 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P1_SEQ0BDLY2_P1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY2_P1_SEQ0BDLY2_P1_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY2_P1_SEQ0BDLY2_P1_MASK)
/*! @} */

/*! @name SEQ0BDLY3_P1 - PHY Initialization Engine (PIE) Delay Register 3 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P1_SEQ0BDLY3_P1_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P1_SEQ0BDLY3_P1_SHIFT (0U)
/*! Seq0BDLY3_p1 - PHY Initialization Engine (PIE) Delay Register 3 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P1_SEQ0BDLY3_P1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY3_P1_SEQ0BDLY3_P1_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY3_P1_SEQ0BDLY3_P1_MASK)
/*! @} */

/*! @name PPTTRAINSETUP_P1 - Setup Intervals for DFI PHY Master operations */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PHYMSTRTRAININTERVAL_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PHYMSTRTRAININTERVAL_SHIFT (0U)
/*! PhyMstrTrainInterval - Bits 3:0 of this register specifies the time between the end of one training and the start of the next. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PHYMSTRTRAININTERVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PHYMSTRTRAININTERVAL_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PHYMSTRTRAININTERVAL_MASK)

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PHYMSTRMAXREQTOACK_MASK (0x70U)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PHYMSTRMAXREQTOACK_SHIFT (4U)
/*! PhyMstrMaxReqToAck - Bits 6:4 of this register specify the max time from tdfi_phymstr_req asserted to tdfi_phymstr_ack asserted. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PHYMSTRMAXREQTOACK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PHYMSTRMAXREQTOACK_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P1_PHYMSTRMAXREQTOACK_MASK)
/*! @} */

/*! @name TRISTATEMODECA_P1 - Mode select register for MEMCLK/Address/Command Tristates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DISDYNADRTRI_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DISDYNADRTRI_SHIFT (0U)
/*! DisDynAdrTri - When DisDynAdrTri=1, Dynamic Tristating is disabled. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DISDYNADRTRI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DISDYNADRTRI_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DISDYNADRTRI_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DDR2TMODE_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DDR2TMODE_SHIFT (1U)
/*! DDR2TMode - Must be set to 1 for Dynamic Tristate to work when CA bus is 2T or Geardown mode. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DDR2TMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DDR2TMODE_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_DDR2TMODE_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_CKDISVAL_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_CKDISVAL_SHIFT (2U)
/*! CkDisVal - The PHY provides 4 memory clocks, n=0. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_CKDISVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_CKDISVAL_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P1_CKDISVAL_MASK)
/*! @} */

/*! @name HWTMRL_P1 - HWT MaxReadLatency. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTMRL_P1_HWTMRL_P1_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTMRL_P1_HWTMRL_P1_SHIFT (0U)
/*! HwtMRL_p1 - This Max Read Latency CSR is to be trained to ensure the rx-data fifo is not read
 *    until after all dbytes have their read data valid.
 */
#define DWC_DDRPHYA_MASTER_HWTMRL_P1_HWTMRL_P1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTMRL_P1_HWTMRL_P1_SHIFT)) & DWC_DDRPHYA_MASTER_HWTMRL_P1_HWTMRL_P1_MASK)
/*! @} */

/*! @name DQSPREAMBLECONTROL_P1 - Control the PHY logic related to the read and write DQS preamble */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TWOTCKRXDQSPRE_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TWOTCKRXDQSPRE_SHIFT (0U)
/*! TwoTckRxDqsPre - Widens the RxDqsEn window to allow larger drift in the incoming read DQS to
 *    take advantage of the larger/wider preamble generated by the DRAMSs when the D4 DRAMS are
 *    configured with DDR4 MR4 A11 Read Preamble=1 for causing a 2nCK read preamble.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TWOTCKRXDQSPRE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TWOTCKRXDQSPRE_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TWOTCKRXDQSPRE_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TWOTCKTXDQSPRE_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TWOTCKTXDQSPRE_SHIFT (1U)
/*! TwoTckTxDqsPre - 0: Standard 1tck TxDqs Preamble 1: Enable Optional D4 2tck TxDqs Preamble The
 *    DDR4 MR4 A12 is Write Preamble, 1=2nCK, 0=1nCK.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TWOTCKTXDQSPRE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TWOTCKTXDQSPRE_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_TWOTCKTXDQSPRE_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_POSITIONDFEINIT_MASK (0x1CU)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_POSITIONDFEINIT_SHIFT (2U)
/*! PositionDfeInit - For DDR4 phy only when receive DFE is enabled. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_POSITIONDFEINIT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_POSITIONDFEINIT_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_POSITIONDFEINIT_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4TGLTWOTCKTXDQSPRE_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4TGLTWOTCKTXDQSPRE_SHIFT (5U)
/*! LP4TglTwoTckTxDqsPre - Used in LPDDR4 mode to modify the early preamble when Register
 *    TwoTckTxDqsPre=1 0: level first-memclk preamble 1: toggling first-memclk preamble
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4TGLTWOTCKTXDQSPRE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4TGLTWOTCKTXDQSPRE_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4TGLTWOTCKTXDQSPRE_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4POSTAMBLEEXT_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4POSTAMBLEEXT_SHIFT (6U)
/*! LP4PostambleExt - In LPDDR4 mode must be set to extend the write postamble. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4POSTAMBLEEXT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4POSTAMBLEEXT_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4POSTAMBLEEXT_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4STTCPREBRIDGERXEN_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4STTCPREBRIDGERXEN_SHIFT (7U)
/*! LP4SttcPreBridgeRxEn - Used in LPDDR4 static-preamble mode to bridge the RxEn between two reads
 *    to the same timing group when the bubble is 1 memclk.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4STTCPREBRIDGERXEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4STTCPREBRIDGERXEN_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_LP4STTCPREBRIDGERXEN_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_WDQSEXTENSION_MASK (0x100U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_WDQSEXTENSION_SHIFT (8U)
/*! WDQSEXTENSION - When set, DQS_T and DQS_C will be driven differentially to 0 and 1,
 *    respectively, before and after a write burst, except during a memory read transaction.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_WDQSEXTENSION(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_WDQSEXTENSION_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P1_WDQSEXTENSION_MASK)
/*! @} */

/*! @name DMIPINPRESENT_P1 - This Register is used to enable the Read-DBI function in each DBYTE */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P1_RDDBIENABLED_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P1_RDDBIENABLED_SHIFT (0U)
/*! RdDbiEnabled - This bit must be set to 1'b1 if Read-DBI is enabled in a connected DDR4 or LPDDR4 device. */
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P1_RDDBIENABLED(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DMIPINPRESENT_P1_RDDBIENABLED_SHIFT)) & DWC_DDRPHYA_MASTER_DMIPINPRESENT_P1_RDDBIENABLED_MASK)
/*! @} */

/*! @name ARDPTRINITVAL_P1 - Address/Command FIFO ReadPointer Initial Value */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P1_ARDPTRINITVAL_P1_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P1_ARDPTRINITVAL_P1_SHIFT (0U)
/*! ARdPtrInitVal_p1 - This is the initial Pointer Offset for the free-running FIFOs in the DBYTE and ACX4 hardips. */
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P1_ARDPTRINITVAL_P1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P1_ARDPTRINITVAL_P1_SHIFT)) & DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P1_ARDPTRINITVAL_P1_MASK)
/*! @} */

/*! @name PROCODTTIMECTL_P1 - READ DATA On-Die Termination Timing Control (by PHY) */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_PODTTAILWIDTH_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_PODTTAILWIDTH_SHIFT (0U)
/*! POdtTailWidth - controls the length of the tail of ProcOdt, units of UI 3 tail 3UI more than for
 *    Register POdtTailWidth=0, maximum 2 tail 2UI more than for Register POdtTailWidth=0, default
 *    1 tail 1UI more than for Register POdtTailWidth=0 0 minimum length tail The time from ProcODT
 *    to closing the window to receive DQS to ProcODT POdtTailWidth is (2 + POdtTailWidth) UI
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_PODTTAILWIDTH(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_PODTTAILWIDTH_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_PODTTAILWIDTH_MASK)

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_PODTSTARTDELAY_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_PODTSTARTDELAY_SHIFT (2U)
/*! POdtStartDelay - controls the start of ProcOdt, units of UI 3 delay start 2 UI, maximum delay of
 *    start of ProcOdt 2 delay start 1 UI, 1 delay start 0 UI, default 0 early by 1 UI, The time
 *    from ProcODT assertion to opening the window to receive DQS is (10 - POdtStartDelay) UI.
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_PODTSTARTDELAY(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_PODTSTARTDELAY_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P1_PODTSTARTDELAY_MASK)
/*! @} */

/*! @name DLLGAINCTL_P1 - DLL gain control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLGAINIV_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLGAINIV_SHIFT (0U)
/*! DllGainIV - Initial value of DllGain. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLGAINIV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLGAINIV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLGAINIV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLGAINTV_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLGAINTV_SHIFT (4U)
/*! DllGainTV - Terminal value of DllGain, ie the value in effect when locking is done and the value
 *    used for maintaining lock, ie tracking pclk variation.
 */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLGAINTV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLGAINTV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLGAINTV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLSEEDSEL_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLSEEDSEL_SHIFT (8U)
/*! DllSeedSel - Reserved, must be configured to be 0. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLSEEDSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLSEEDSEL_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P1_DLLSEEDSEL_MASK)
/*! @} */

/*! @name DFIRDDATACSDESTMAP_P1 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM0_SHIFT (0U)
/*! DfiRdDestm0 - Maps dfi_rddata_cs_n_p0[0] to dest DfiRdDestm0 timing For example, if 0
 *    dfi_rddata_cs_n_p0[0] will use Register RxEn,ClkDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM0_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM1_SHIFT (2U)
/*! DfiRdDestm1 - Maps dfi_rddata_cs_n_p0[1] to dest DfiRdDestm1 timing For example, if 1
 *    dfi_rddata_cs_n[_p01] will use Register RxEn,ClkDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM1_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM2_SHIFT (4U)
/*! DfiRdDestm2 - Maps dfi_rddata_cs_n_p0[2] to dest DfiRdDestm2 timing For example, if 2
 *    dfi_rddata_cs_n_p0[2] will use Register RxEn,ClkDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM2_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM3_SHIFT (6U)
/*! DfiRdDestm3 - Maps dfi_rddata_cs_n_p0[3] to dest DfiRdDestm3 timing For example, if 3
 *    dfi_rddata_cs_n_p0[3] will use Register RxEn,ClkDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P1_DFIRDDESTM3_MASK)
/*! @} */

/*! @name VREFINGLOBAL_P1 - PHY Global Vref Controls */
/*! @{ */

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINSEL_MASK (0x7U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINSEL_SHIFT (0U)
/*! GlobalVrefInSel - GlobalVrefInSel[1:0] controls the mode of the PHY VREF DAC and the BP_VREF pin
 *    ========================================================== 2'b00 - PHY Vref DAC Range0 --
 *    BP_VREF = Hi-Z 2'b01 - Reserved Encoding 2'b10 - PHY Vref DAC Range0 -- BP_VREF connected to PLL
 *    Analog Bus 2'b11 - PHY Vref DAC Range0 -- BP_VREF connected to PHY Vref DAC
 *    ========================================================== GlobalVrefInSel[2] shall be set according to Dram
 *    Protocol: Protocol GlobalVrefInSel[2] ------------------------------------------ DDR3 1'b0 DDR4
 *    1'b0 LPDDR3 1'b0 LPDDR4 1'b1
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINSEL_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINSEL_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINDAC_MASK (0x3F8U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINDAC_SHIFT (3U)
/*! GlobalVrefInDAC - DAC code for internal Vref generation The DAC has two ranges; the range is set
 *    by GlobalVrefInSel[2] ========================================================== RANGE0 :
 *    DDR3,DDR4,LPDDR3 [GlobalVrefInSel[2] = 0] DAC Output Voltage = GlobalVrefInDAC == 6'h00 ? Hi-Z :
 *    0.
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINDAC(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINDAC_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINDAC_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINTRIM_MASK (0x3C00U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINTRIM_SHIFT (10U)
/*! GlobalVrefInTrim - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINTRIM(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINTRIM_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINTRIM_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINMODE_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINMODE_SHIFT (14U)
/*! GlobalVrefInMode - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINMODE_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P1_GLOBALVREFINMODE_MASK)
/*! @} */

/*! @name DFIWRDATACSDESTMAP_P1 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM0_SHIFT (0U)
/*! DfiWrDestm0 - Maps dfi_wrdata_cs_n_p0[0] to dest DfiWrDestm0 timing For example, if 0
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM0_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM1_SHIFT (2U)
/*! DfiWrDestm1 - Maps dfi_wrdata_cs_n_p0[1] to dest DfiWrDestm1 timing For example, if 1
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM1_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM2_SHIFT (4U)
/*! DfiWrDestm2 - Maps dfi_wrdata_cs_n_p0[2] to dest DfiWrDestm2 timing For example, if 2
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM2_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM3_SHIFT (6U)
/*! DfiWrDestm3 - Maps dfi_wrdata_cs_n_p0[3] to dest DfiWrDestm3 timing (use Register
 *    TxDq,DqsDlyTg3) For example, if 3 dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P1_DFIWRDESTM3_MASK)
/*! @} */

/*! @name PLLCTRL2_P1 - PState dependent PLL Control Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL2_P1_PLLFREQSEL_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P1_PLLFREQSEL_SHIFT (0U)
/*! PllFreqSel - Adjusts the loop parameters to compensate for different VCO bias points, and input/output clock division ratios. */
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P1_PLLFREQSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL2_P1_PLLFREQSEL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL2_P1_PLLFREQSEL_MASK)
/*! @} */

/*! @name PLLCTRL1_P1 - PState dependent PLL Control Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PLLCPINTCTRL_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PLLCPINTCTRL_SHIFT (0U)
/*! PllCpIntCtrl - connects directly to cp_int_cntrl<1:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PLLCPINTCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PLLCPINTCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PLLCPINTCTRL_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PLLCPPROPCTRL_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PLLCPPROPCTRL_SHIFT (5U)
/*! PllCpPropCtrl - connects directly to cp_prop_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PLLCPPROPCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PLLCPPROPCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P1_PLLCPPROPCTRL_MASK)
/*! @} */

/*! @name PLLTESTMODE_P1 - Additional controls for PLL CP/VCO modes of operation */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P1_PLLTESTMODE_P1_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P1_PLLTESTMODE_P1_SHIFT (0U)
/*! PllTestMode_p1 - It is required to use default values for this CSR unless directed otherwise by Synopsys. */
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P1_PLLTESTMODE_P1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLTESTMODE_P1_PLLTESTMODE_P1_SHIFT)) & DWC_DDRPHYA_MASTER_PLLTESTMODE_P1_PLLTESTMODE_P1_MASK)
/*! @} */

/*! @name PLLCTRL4_P1 - PState dependent PLL Control Register 4 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PLLCPINTGSCTRL_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PLLCPINTGSCTRL_SHIFT (0U)
/*! PllCpIntGsCtrl - connects directly to cp_int_gs_cntrl<4:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PLLCPINTGSCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PLLCPINTGSCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PLLCPINTGSCTRL_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PLLCPPROPGSCTRL_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PLLCPPROPGSCTRL_SHIFT (5U)
/*! PllCpPropGsCtrl - connects directly to cp_prop_gs_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PLLCPPROPGSCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PLLCPPROPGSCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P1_PLLCPPROPGSCTRL_MASK)
/*! @} */

/*! @name DFIFREQRATIO_P1 - DFI Frequency Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P1_DFIFREQRATIO_P1_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P1_DFIFREQRATIO_P1_SHIFT (0U)
/*! DfiFreqRatio_p1 - Used in dwc_ddrphy_pub_serdes to serialize or de-serialize DFI signals 00 =
 *    1:1 mode 01 = 1:2 mode 1x = 1:4 mode* *Note: 1:4 is for future pub revision.
 */
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P1_DFIFREQRATIO_P1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQRATIO_P1_DFIFREQRATIO_P1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQRATIO_P1_DFIFREQRATIO_P1_MASK)
/*! @} */

/*! @name CALUCLKINFO_P2 - Impedance Calibration Clock Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P2_CALUCLKTICKSPER1US_MASK (0x3FFU)
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P2_CALUCLKTICKSPER1US_SHIFT (0U)
/*! CalUClkTicksPer1uS - Must be programmed to the number of DfiClks in 1us (rounded up), with minimum value of 24. */
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P2_CALUCLKTICKSPER1US(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALUCLKINFO_P2_CALUCLKTICKSPER1US_SHIFT)) & DWC_DDRPHYA_MASTER_CALUCLKINFO_P2_CALUCLKTICKSPER1US_MASK)
/*! @} */

/*! @name SEQ0BDLY0_P2 - PHY Initialization Engine (PIE) Delay Register 0 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P2_SEQ0BDLY0_P2_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P2_SEQ0BDLY0_P2_SHIFT (0U)
/*! Seq0BDLY0_p2 - PHY Initialization Engine (PIE) Delay Register 0 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P2_SEQ0BDLY0_P2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY0_P2_SEQ0BDLY0_P2_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY0_P2_SEQ0BDLY0_P2_MASK)
/*! @} */

/*! @name SEQ0BDLY1_P2 - PHY Initialization Engine (PIE) Delay Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P2_SEQ0BDLY1_P2_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P2_SEQ0BDLY1_P2_SHIFT (0U)
/*! Seq0BDLY1_p2 - PHY Initialization Engine (PIE) Delay Register 1 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P2_SEQ0BDLY1_P2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY1_P2_SEQ0BDLY1_P2_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY1_P2_SEQ0BDLY1_P2_MASK)
/*! @} */

/*! @name SEQ0BDLY2_P2 - PHY Initialization Engine (PIE) Delay Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P2_SEQ0BDLY2_P2_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P2_SEQ0BDLY2_P2_SHIFT (0U)
/*! Seq0BDLY2_p2 - PHY Initialization Engine (PIE) Delay Register 2 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P2_SEQ0BDLY2_P2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY2_P2_SEQ0BDLY2_P2_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY2_P2_SEQ0BDLY2_P2_MASK)
/*! @} */

/*! @name SEQ0BDLY3_P2 - PHY Initialization Engine (PIE) Delay Register 3 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P2_SEQ0BDLY3_P2_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P2_SEQ0BDLY3_P2_SHIFT (0U)
/*! Seq0BDLY3_p2 - PHY Initialization Engine (PIE) Delay Register 3 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P2_SEQ0BDLY3_P2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY3_P2_SEQ0BDLY3_P2_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY3_P2_SEQ0BDLY3_P2_MASK)
/*! @} */

/*! @name PPTTRAINSETUP_P2 - Setup Intervals for DFI PHY Master operations */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PHYMSTRTRAININTERVAL_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PHYMSTRTRAININTERVAL_SHIFT (0U)
/*! PhyMstrTrainInterval - Bits 3:0 of this register specifies the time between the end of one training and the start of the next. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PHYMSTRTRAININTERVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PHYMSTRTRAININTERVAL_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PHYMSTRTRAININTERVAL_MASK)

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PHYMSTRMAXREQTOACK_MASK (0x70U)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PHYMSTRMAXREQTOACK_SHIFT (4U)
/*! PhyMstrMaxReqToAck - Bits 6:4 of this register specify the max time from tdfi_phymstr_req asserted to tdfi_phymstr_ack asserted. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PHYMSTRMAXREQTOACK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PHYMSTRMAXREQTOACK_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P2_PHYMSTRMAXREQTOACK_MASK)
/*! @} */

/*! @name TRISTATEMODECA_P2 - Mode select register for MEMCLK/Address/Command Tristates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DISDYNADRTRI_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DISDYNADRTRI_SHIFT (0U)
/*! DisDynAdrTri - When DisDynAdrTri=1, Dynamic Tristating is disabled. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DISDYNADRTRI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DISDYNADRTRI_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DISDYNADRTRI_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DDR2TMODE_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DDR2TMODE_SHIFT (1U)
/*! DDR2TMode - Must be set to 1 for Dynamic Tristate to work when CA bus is 2T or Geardown mode. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DDR2TMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DDR2TMODE_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_DDR2TMODE_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_CKDISVAL_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_CKDISVAL_SHIFT (2U)
/*! CkDisVal - The PHY provides 4 memory clocks, n=0. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_CKDISVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_CKDISVAL_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P2_CKDISVAL_MASK)
/*! @} */

/*! @name HWTMRL_P2 - HWT MaxReadLatency. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTMRL_P2_HWTMRL_P2_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTMRL_P2_HWTMRL_P2_SHIFT (0U)
/*! HwtMRL_p2 - This Max Read Latency CSR is to be trained to ensure the rx-data fifo is not read
 *    until after all dbytes have their read data valid.
 */
#define DWC_DDRPHYA_MASTER_HWTMRL_P2_HWTMRL_P2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTMRL_P2_HWTMRL_P2_SHIFT)) & DWC_DDRPHYA_MASTER_HWTMRL_P2_HWTMRL_P2_MASK)
/*! @} */

/*! @name DQSPREAMBLECONTROL_P2 - Control the PHY logic related to the read and write DQS preamble */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TWOTCKRXDQSPRE_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TWOTCKRXDQSPRE_SHIFT (0U)
/*! TwoTckRxDqsPre - Widens the RxDqsEn window to allow larger drift in the incoming read DQS to
 *    take advantage of the larger/wider preamble generated by the DRAMSs when the D4 DRAMS are
 *    configured with DDR4 MR4 A11 Read Preamble=1 for causing a 2nCK read preamble.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TWOTCKRXDQSPRE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TWOTCKRXDQSPRE_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TWOTCKRXDQSPRE_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TWOTCKTXDQSPRE_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TWOTCKTXDQSPRE_SHIFT (1U)
/*! TwoTckTxDqsPre - 0: Standard 1tck TxDqs Preamble 1: Enable Optional D4 2tck TxDqs Preamble The
 *    DDR4 MR4 A12 is Write Preamble, 1=2nCK, 0=1nCK.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TWOTCKTXDQSPRE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TWOTCKTXDQSPRE_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_TWOTCKTXDQSPRE_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_POSITIONDFEINIT_MASK (0x1CU)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_POSITIONDFEINIT_SHIFT (2U)
/*! PositionDfeInit - For DDR4 phy only when receive DFE is enabled. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_POSITIONDFEINIT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_POSITIONDFEINIT_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_POSITIONDFEINIT_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4TGLTWOTCKTXDQSPRE_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4TGLTWOTCKTXDQSPRE_SHIFT (5U)
/*! LP4TglTwoTckTxDqsPre - Used in LPDDR4 mode to modify the early preamble when Register
 *    TwoTckTxDqsPre=1 0: level first-memclk preamble 1: toggling first-memclk preamble
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4TGLTWOTCKTXDQSPRE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4TGLTWOTCKTXDQSPRE_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4TGLTWOTCKTXDQSPRE_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4POSTAMBLEEXT_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4POSTAMBLEEXT_SHIFT (6U)
/*! LP4PostambleExt - In LPDDR4 mode must be set to extend the write postamble. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4POSTAMBLEEXT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4POSTAMBLEEXT_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4POSTAMBLEEXT_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4STTCPREBRIDGERXEN_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4STTCPREBRIDGERXEN_SHIFT (7U)
/*! LP4SttcPreBridgeRxEn - Used in LPDDR4 static-preamble mode to bridge the RxEn between two reads
 *    to the same timing group when the bubble is 1 memclk.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4STTCPREBRIDGERXEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4STTCPREBRIDGERXEN_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_LP4STTCPREBRIDGERXEN_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_WDQSEXTENSION_MASK (0x100U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_WDQSEXTENSION_SHIFT (8U)
/*! WDQSEXTENSION - When set, DQS_T and DQS_C will be driven differentially to 0 and 1,
 *    respectively, before and after a write burst, except during a memory read transaction.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_WDQSEXTENSION(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_WDQSEXTENSION_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P2_WDQSEXTENSION_MASK)
/*! @} */

/*! @name DMIPINPRESENT_P2 - This Register is used to enable the Read-DBI function in each DBYTE */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P2_RDDBIENABLED_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P2_RDDBIENABLED_SHIFT (0U)
/*! RdDbiEnabled - This bit must be set to 1'b1 if Read-DBI is enabled in a connected DDR4 or LPDDR4 device. */
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P2_RDDBIENABLED(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DMIPINPRESENT_P2_RDDBIENABLED_SHIFT)) & DWC_DDRPHYA_MASTER_DMIPINPRESENT_P2_RDDBIENABLED_MASK)
/*! @} */

/*! @name ARDPTRINITVAL_P2 - Address/Command FIFO ReadPointer Initial Value */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P2_ARDPTRINITVAL_P2_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P2_ARDPTRINITVAL_P2_SHIFT (0U)
/*! ARdPtrInitVal_p2 - This is the initial Pointer Offset for the free-running FIFOs in the DBYTE and ACX4 hardips. */
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P2_ARDPTRINITVAL_P2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P2_ARDPTRINITVAL_P2_SHIFT)) & DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P2_ARDPTRINITVAL_P2_MASK)
/*! @} */

/*! @name PROCODTTIMECTL_P2 - READ DATA On-Die Termination Timing Control (by PHY) */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_PODTTAILWIDTH_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_PODTTAILWIDTH_SHIFT (0U)
/*! POdtTailWidth - controls the length of the tail of ProcOdt, units of UI 3 tail 3UI more than for
 *    Register POdtTailWidth=0, maximum 2 tail 2UI more than for Register POdtTailWidth=0, default
 *    1 tail 1UI more than for Register POdtTailWidth=0 0 minimum length tail The time from ProcODT
 *    to closing the window to receive DQS to ProcODT POdtTailWidth is (2 + POdtTailWidth) UI
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_PODTTAILWIDTH(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_PODTTAILWIDTH_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_PODTTAILWIDTH_MASK)

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_PODTSTARTDELAY_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_PODTSTARTDELAY_SHIFT (2U)
/*! POdtStartDelay - controls the start of ProcOdt, units of UI 3 delay start 2 UI, maximum delay of
 *    start of ProcOdt 2 delay start 1 UI, 1 delay start 0 UI, default 0 early by 1 UI, The time
 *    from ProcODT assertion to opening the window to receive DQS is (10 - POdtStartDelay) UI.
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_PODTSTARTDELAY(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_PODTSTARTDELAY_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P2_PODTSTARTDELAY_MASK)
/*! @} */

/*! @name DLLGAINCTL_P2 - DLL gain control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLGAINIV_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLGAINIV_SHIFT (0U)
/*! DllGainIV - Initial value of DllGain. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLGAINIV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLGAINIV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLGAINIV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLGAINTV_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLGAINTV_SHIFT (4U)
/*! DllGainTV - Terminal value of DllGain, ie the value in effect when locking is done and the value
 *    used for maintaining lock, ie tracking pclk variation.
 */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLGAINTV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLGAINTV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLGAINTV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLSEEDSEL_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLSEEDSEL_SHIFT (8U)
/*! DllSeedSel - Reserved, must be configured to be 0. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLSEEDSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLSEEDSEL_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P2_DLLSEEDSEL_MASK)
/*! @} */

/*! @name DFIRDDATACSDESTMAP_P2 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM0_SHIFT (0U)
/*! DfiRdDestm0 - Maps dfi_rddata_cs_n_p0[0] to dest DfiRdDestm0 timing For example, if 0
 *    dfi_rddata_cs_n_p0[0] will use Register RxEn,ClkDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM0_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM1_SHIFT (2U)
/*! DfiRdDestm1 - Maps dfi_rddata_cs_n_p0[1] to dest DfiRdDestm1 timing For example, if 1
 *    dfi_rddata_cs_n[_p01] will use Register RxEn,ClkDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM1_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM2_SHIFT (4U)
/*! DfiRdDestm2 - Maps dfi_rddata_cs_n_p0[2] to dest DfiRdDestm2 timing For example, if 2
 *    dfi_rddata_cs_n_p0[2] will use Register RxEn,ClkDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM2_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM3_SHIFT (6U)
/*! DfiRdDestm3 - Maps dfi_rddata_cs_n_p0[3] to dest DfiRdDestm3 timing For example, if 3
 *    dfi_rddata_cs_n_p0[3] will use Register RxEn,ClkDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P2_DFIRDDESTM3_MASK)
/*! @} */

/*! @name VREFINGLOBAL_P2 - PHY Global Vref Controls */
/*! @{ */

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINSEL_MASK (0x7U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINSEL_SHIFT (0U)
/*! GlobalVrefInSel - GlobalVrefInSel[1:0] controls the mode of the PHY VREF DAC and the BP_VREF pin
 *    ========================================================== 2'b00 - PHY Vref DAC Range0 --
 *    BP_VREF = Hi-Z 2'b01 - Reserved Encoding 2'b10 - PHY Vref DAC Range0 -- BP_VREF connected to PLL
 *    Analog Bus 2'b11 - PHY Vref DAC Range0 -- BP_VREF connected to PHY Vref DAC
 *    ========================================================== GlobalVrefInSel[2] shall be set according to Dram
 *    Protocol: Protocol GlobalVrefInSel[2] ------------------------------------------ DDR3 1'b0 DDR4
 *    1'b0 LPDDR3 1'b0 LPDDR4 1'b1
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINSEL_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINSEL_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINDAC_MASK (0x3F8U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINDAC_SHIFT (3U)
/*! GlobalVrefInDAC - DAC code for internal Vref generation The DAC has two ranges; the range is set
 *    by GlobalVrefInSel[2] ========================================================== RANGE0 :
 *    DDR3,DDR4,LPDDR3 [GlobalVrefInSel[2] = 0] DAC Output Voltage = GlobalVrefInDAC == 6'h00 ? Hi-Z :
 *    0.
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINDAC(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINDAC_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINDAC_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINTRIM_MASK (0x3C00U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINTRIM_SHIFT (10U)
/*! GlobalVrefInTrim - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINTRIM(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINTRIM_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINTRIM_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINMODE_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINMODE_SHIFT (14U)
/*! GlobalVrefInMode - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINMODE_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P2_GLOBALVREFINMODE_MASK)
/*! @} */

/*! @name DFIWRDATACSDESTMAP_P2 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM0_SHIFT (0U)
/*! DfiWrDestm0 - Maps dfi_wrdata_cs_n_p0[0] to dest DfiWrDestm0 timing For example, if 0
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM0_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM1_SHIFT (2U)
/*! DfiWrDestm1 - Maps dfi_wrdata_cs_n_p0[1] to dest DfiWrDestm1 timing For example, if 1
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM1_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM2_SHIFT (4U)
/*! DfiWrDestm2 - Maps dfi_wrdata_cs_n_p0[2] to dest DfiWrDestm2 timing For example, if 2
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM2_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM3_SHIFT (6U)
/*! DfiWrDestm3 - Maps dfi_wrdata_cs_n_p0[3] to dest DfiWrDestm3 timing (use Register
 *    TxDq,DqsDlyTg3) For example, if 3 dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P2_DFIWRDESTM3_MASK)
/*! @} */

/*! @name PLLCTRL2_P2 - PState dependent PLL Control Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL2_P2_PLLFREQSEL_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P2_PLLFREQSEL_SHIFT (0U)
/*! PllFreqSel - Adjusts the loop parameters to compensate for different VCO bias points, and input/output clock division ratios. */
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P2_PLLFREQSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL2_P2_PLLFREQSEL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL2_P2_PLLFREQSEL_MASK)
/*! @} */

/*! @name PLLCTRL1_P2 - PState dependent PLL Control Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PLLCPINTCTRL_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PLLCPINTCTRL_SHIFT (0U)
/*! PllCpIntCtrl - connects directly to cp_int_cntrl<1:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PLLCPINTCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PLLCPINTCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PLLCPINTCTRL_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PLLCPPROPCTRL_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PLLCPPROPCTRL_SHIFT (5U)
/*! PllCpPropCtrl - connects directly to cp_prop_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PLLCPPROPCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PLLCPPROPCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P2_PLLCPPROPCTRL_MASK)
/*! @} */

/*! @name PLLTESTMODE_P2 - Additional controls for PLL CP/VCO modes of operation */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P2_PLLTESTMODE_P2_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P2_PLLTESTMODE_P2_SHIFT (0U)
/*! PllTestMode_p2 - It is required to use default values for this CSR unless directed otherwise by Synopsys. */
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P2_PLLTESTMODE_P2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLTESTMODE_P2_PLLTESTMODE_P2_SHIFT)) & DWC_DDRPHYA_MASTER_PLLTESTMODE_P2_PLLTESTMODE_P2_MASK)
/*! @} */

/*! @name PLLCTRL4_P2 - PState dependent PLL Control Register 4 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PLLCPINTGSCTRL_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PLLCPINTGSCTRL_SHIFT (0U)
/*! PllCpIntGsCtrl - connects directly to cp_int_gs_cntrl<4:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PLLCPINTGSCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PLLCPINTGSCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PLLCPINTGSCTRL_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PLLCPPROPGSCTRL_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PLLCPPROPGSCTRL_SHIFT (5U)
/*! PllCpPropGsCtrl - connects directly to cp_prop_gs_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PLLCPPROPGSCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PLLCPPROPGSCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P2_PLLCPPROPGSCTRL_MASK)
/*! @} */

/*! @name DFIFREQRATIO_P2 - DFI Frequency Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P2_DFIFREQRATIO_P2_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P2_DFIFREQRATIO_P2_SHIFT (0U)
/*! DfiFreqRatio_p2 - Used in dwc_ddrphy_pub_serdes to serialize or de-serialize DFI signals 00 =
 *    1:1 mode 01 = 1:2 mode 1x = 1:4 mode* *Note: 1:4 is for future pub revision.
 */
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P2_DFIFREQRATIO_P2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQRATIO_P2_DFIFREQRATIO_P2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQRATIO_P2_DFIFREQRATIO_P2_MASK)
/*! @} */

/*! @name CALUCLKINFO_P3 - Impedance Calibration Clock Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P3_CALUCLKTICKSPER1US_MASK (0x3FFU)
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P3_CALUCLKTICKSPER1US_SHIFT (0U)
/*! CalUClkTicksPer1uS - Must be programmed to the number of DfiClks in 1us (rounded up), with minimum value of 24. */
#define DWC_DDRPHYA_MASTER_CALUCLKINFO_P3_CALUCLKTICKSPER1US(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_CALUCLKINFO_P3_CALUCLKTICKSPER1US_SHIFT)) & DWC_DDRPHYA_MASTER_CALUCLKINFO_P3_CALUCLKTICKSPER1US_MASK)
/*! @} */

/*! @name SEQ0BDLY0_P3 - PHY Initialization Engine (PIE) Delay Register 0 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P3_SEQ0BDLY0_P3_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P3_SEQ0BDLY0_P3_SHIFT (0U)
/*! Seq0BDLY0_p3 - PHY Initialization Engine (PIE) Delay Register 0 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY0_P3_SEQ0BDLY0_P3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY0_P3_SEQ0BDLY0_P3_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY0_P3_SEQ0BDLY0_P3_MASK)
/*! @} */

/*! @name SEQ0BDLY1_P3 - PHY Initialization Engine (PIE) Delay Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P3_SEQ0BDLY1_P3_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P3_SEQ0BDLY1_P3_SHIFT (0U)
/*! Seq0BDLY1_p3 - PHY Initialization Engine (PIE) Delay Register 1 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY1_P3_SEQ0BDLY1_P3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY1_P3_SEQ0BDLY1_P3_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY1_P3_SEQ0BDLY1_P3_MASK)
/*! @} */

/*! @name SEQ0BDLY2_P3 - PHY Initialization Engine (PIE) Delay Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P3_SEQ0BDLY2_P3_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P3_SEQ0BDLY2_P3_SHIFT (0U)
/*! Seq0BDLY2_p3 - PHY Initialization Engine (PIE) Delay Register 2 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY2_P3_SEQ0BDLY2_P3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY2_P3_SEQ0BDLY2_P3_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY2_P3_SEQ0BDLY2_P3_MASK)
/*! @} */

/*! @name SEQ0BDLY3_P3 - PHY Initialization Engine (PIE) Delay Register 3 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P3_SEQ0BDLY3_P3_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P3_SEQ0BDLY3_P3_SHIFT (0U)
/*! Seq0BDLY3_p3 - PHY Initialization Engine (PIE) Delay Register 3 This register is available for
 *    selection by the NOP and WAIT instructions in the PIE for the delay value.
 */
#define DWC_DDRPHYA_MASTER_SEQ0BDLY3_P3_SEQ0BDLY3_P3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_SEQ0BDLY3_P3_SEQ0BDLY3_P3_SHIFT)) & DWC_DDRPHYA_MASTER_SEQ0BDLY3_P3_SEQ0BDLY3_P3_MASK)
/*! @} */

/*! @name PPTTRAINSETUP_P3 - Setup Intervals for DFI PHY Master operations */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PHYMSTRTRAININTERVAL_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PHYMSTRTRAININTERVAL_SHIFT (0U)
/*! PhyMstrTrainInterval - Bits 3:0 of this register specifies the time between the end of one training and the start of the next. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PHYMSTRTRAININTERVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PHYMSTRTRAININTERVAL_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PHYMSTRTRAININTERVAL_MASK)

#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PHYMSTRMAXREQTOACK_MASK (0x70U)
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PHYMSTRMAXREQTOACK_SHIFT (4U)
/*! PhyMstrMaxReqToAck - Bits 6:4 of this register specify the max time from tdfi_phymstr_req asserted to tdfi_phymstr_ack asserted. */
#define DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PHYMSTRMAXREQTOACK(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PHYMSTRMAXREQTOACK_SHIFT)) & DWC_DDRPHYA_MASTER_PPTTRAINSETUP_P3_PHYMSTRMAXREQTOACK_MASK)
/*! @} */

/*! @name TRISTATEMODECA_P3 - Mode select register for MEMCLK/Address/Command Tristates */
/*! @{ */

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DISDYNADRTRI_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DISDYNADRTRI_SHIFT (0U)
/*! DisDynAdrTri - When DisDynAdrTri=1, Dynamic Tristating is disabled. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DISDYNADRTRI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DISDYNADRTRI_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DISDYNADRTRI_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DDR2TMODE_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DDR2TMODE_SHIFT (1U)
/*! DDR2TMode - Must be set to 1 for Dynamic Tristate to work when CA bus is 2T or Geardown mode. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DDR2TMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DDR2TMODE_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_DDR2TMODE_MASK)

#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_CKDISVAL_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_CKDISVAL_SHIFT (2U)
/*! CkDisVal - The PHY provides 4 memory clocks, n=0. */
#define DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_CKDISVAL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_CKDISVAL_SHIFT)) & DWC_DDRPHYA_MASTER_TRISTATEMODECA_P3_CKDISVAL_MASK)
/*! @} */

/*! @name HWTMRL_P3 - HWT MaxReadLatency. */
/*! @{ */

#define DWC_DDRPHYA_MASTER_HWTMRL_P3_HWTMRL_P3_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_HWTMRL_P3_HWTMRL_P3_SHIFT (0U)
/*! HwtMRL_p3 - This Max Read Latency CSR is to be trained to ensure the rx-data fifo is not read
 *    until after all dbytes have their read data valid.
 */
#define DWC_DDRPHYA_MASTER_HWTMRL_P3_HWTMRL_P3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_HWTMRL_P3_HWTMRL_P3_SHIFT)) & DWC_DDRPHYA_MASTER_HWTMRL_P3_HWTMRL_P3_MASK)
/*! @} */

/*! @name DQSPREAMBLECONTROL_P3 - Control the PHY logic related to the read and write DQS preamble */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TWOTCKRXDQSPRE_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TWOTCKRXDQSPRE_SHIFT (0U)
/*! TwoTckRxDqsPre - Widens the RxDqsEn window to allow larger drift in the incoming read DQS to
 *    take advantage of the larger/wider preamble generated by the DRAMSs when the D4 DRAMS are
 *    configured with DDR4 MR4 A11 Read Preamble=1 for causing a 2nCK read preamble.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TWOTCKRXDQSPRE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TWOTCKRXDQSPRE_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TWOTCKRXDQSPRE_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TWOTCKTXDQSPRE_MASK (0x2U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TWOTCKTXDQSPRE_SHIFT (1U)
/*! TwoTckTxDqsPre - 0: Standard 1tck TxDqs Preamble 1: Enable Optional D4 2tck TxDqs Preamble The
 *    DDR4 MR4 A12 is Write Preamble, 1=2nCK, 0=1nCK.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TWOTCKTXDQSPRE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TWOTCKTXDQSPRE_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_TWOTCKTXDQSPRE_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_POSITIONDFEINIT_MASK (0x1CU)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_POSITIONDFEINIT_SHIFT (2U)
/*! PositionDfeInit - For DDR4 phy only when receive DFE is enabled. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_POSITIONDFEINIT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_POSITIONDFEINIT_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_POSITIONDFEINIT_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4TGLTWOTCKTXDQSPRE_MASK (0x20U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4TGLTWOTCKTXDQSPRE_SHIFT (5U)
/*! LP4TglTwoTckTxDqsPre - Used in LPDDR4 mode to modify the early preamble when Register
 *    TwoTckTxDqsPre=1 0: level first-memclk preamble 1: toggling first-memclk preamble
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4TGLTWOTCKTXDQSPRE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4TGLTWOTCKTXDQSPRE_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4TGLTWOTCKTXDQSPRE_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4POSTAMBLEEXT_MASK (0x40U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4POSTAMBLEEXT_SHIFT (6U)
/*! LP4PostambleExt - In LPDDR4 mode must be set to extend the write postamble. */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4POSTAMBLEEXT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4POSTAMBLEEXT_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4POSTAMBLEEXT_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4STTCPREBRIDGERXEN_MASK (0x80U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4STTCPREBRIDGERXEN_SHIFT (7U)
/*! LP4SttcPreBridgeRxEn - Used in LPDDR4 static-preamble mode to bridge the RxEn between two reads
 *    to the same timing group when the bubble is 1 memclk.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4STTCPREBRIDGERXEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4STTCPREBRIDGERXEN_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_LP4STTCPREBRIDGERXEN_MASK)

#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_WDQSEXTENSION_MASK (0x100U)
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_WDQSEXTENSION_SHIFT (8U)
/*! WDQSEXTENSION - When set, DQS_T and DQS_C will be driven differentially to 0 and 1,
 *    respectively, before and after a write burst, except during a memory read transaction.
 */
#define DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_WDQSEXTENSION(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_WDQSEXTENSION_SHIFT)) & DWC_DDRPHYA_MASTER_DQSPREAMBLECONTROL_P3_WDQSEXTENSION_MASK)
/*! @} */

/*! @name DMIPINPRESENT_P3 - This Register is used to enable the Read-DBI function in each DBYTE */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P3_RDDBIENABLED_MASK (0x1U)
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P3_RDDBIENABLED_SHIFT (0U)
/*! RdDbiEnabled - This bit must be set to 1'b1 if Read-DBI is enabled in a connected DDR4 or LPDDR4 device. */
#define DWC_DDRPHYA_MASTER_DMIPINPRESENT_P3_RDDBIENABLED(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DMIPINPRESENT_P3_RDDBIENABLED_SHIFT)) & DWC_DDRPHYA_MASTER_DMIPINPRESENT_P3_RDDBIENABLED_MASK)
/*! @} */

/*! @name ARDPTRINITVAL_P3 - Address/Command FIFO ReadPointer Initial Value */
/*! @{ */

#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P3_ARDPTRINITVAL_P3_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P3_ARDPTRINITVAL_P3_SHIFT (0U)
/*! ARdPtrInitVal_p3 - This is the initial Pointer Offset for the free-running FIFOs in the DBYTE and ACX4 hardips. */
#define DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P3_ARDPTRINITVAL_P3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P3_ARDPTRINITVAL_P3_SHIFT)) & DWC_DDRPHYA_MASTER_ARDPTRINITVAL_P3_ARDPTRINITVAL_P3_MASK)
/*! @} */

/*! @name PROCODTTIMECTL_P3 - READ DATA On-Die Termination Timing Control (by PHY) */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_PODTTAILWIDTH_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_PODTTAILWIDTH_SHIFT (0U)
/*! POdtTailWidth - controls the length of the tail of ProcOdt, units of UI 3 tail 3UI more than for
 *    Register POdtTailWidth=0, maximum 2 tail 2UI more than for Register POdtTailWidth=0, default
 *    1 tail 1UI more than for Register POdtTailWidth=0 0 minimum length tail The time from ProcODT
 *    to closing the window to receive DQS to ProcODT POdtTailWidth is (2 + POdtTailWidth) UI
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_PODTTAILWIDTH(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_PODTTAILWIDTH_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_PODTTAILWIDTH_MASK)

#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_PODTSTARTDELAY_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_PODTSTARTDELAY_SHIFT (2U)
/*! POdtStartDelay - controls the start of ProcOdt, units of UI 3 delay start 2 UI, maximum delay of
 *    start of ProcOdt 2 delay start 1 UI, 1 delay start 0 UI, default 0 early by 1 UI, The time
 *    from ProcODT assertion to opening the window to receive DQS is (10 - POdtStartDelay) UI.
 */
#define DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_PODTSTARTDELAY(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_PODTSTARTDELAY_SHIFT)) & DWC_DDRPHYA_MASTER_PROCODTTIMECTL_P3_PODTSTARTDELAY_MASK)
/*! @} */

/*! @name DLLGAINCTL_P3 - DLL gain control */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLGAINIV_MASK (0xFU)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLGAINIV_SHIFT (0U)
/*! DllGainIV - Initial value of DllGain. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLGAINIV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLGAINIV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLGAINIV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLGAINTV_MASK (0xF0U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLGAINTV_SHIFT (4U)
/*! DllGainTV - Terminal value of DllGain, ie the value in effect when locking is done and the value
 *    used for maintaining lock, ie tracking pclk variation.
 */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLGAINTV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLGAINTV_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLGAINTV_MASK)

#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLSEEDSEL_MASK (0xF00U)
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLSEEDSEL_SHIFT (8U)
/*! DllSeedSel - Reserved, must be configured to be 0. */
#define DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLSEEDSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLSEEDSEL_SHIFT)) & DWC_DDRPHYA_MASTER_DLLGAINCTL_P3_DLLSEEDSEL_MASK)
/*! @} */

/*! @name DFIRDDATACSDESTMAP_P3 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM0_SHIFT (0U)
/*! DfiRdDestm0 - Maps dfi_rddata_cs_n_p0[0] to dest DfiRdDestm0 timing For example, if 0
 *    dfi_rddata_cs_n_p0[0] will use Register RxEn,ClkDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM0_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM1_SHIFT (2U)
/*! DfiRdDestm1 - Maps dfi_rddata_cs_n_p0[1] to dest DfiRdDestm1 timing For example, if 1
 *    dfi_rddata_cs_n[_p01] will use Register RxEn,ClkDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM1_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM2_SHIFT (4U)
/*! DfiRdDestm2 - Maps dfi_rddata_cs_n_p0[2] to dest DfiRdDestm2 timing For example, if 2
 *    dfi_rddata_cs_n_p0[2] will use Register RxEn,ClkDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM2_MASK)

#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM3_SHIFT (6U)
/*! DfiRdDestm3 - Maps dfi_rddata_cs_n_p0[3] to dest DfiRdDestm3 timing For example, if 3
 *    dfi_rddata_cs_n_p0[3] will use Register RxEn,ClkDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIRDDATACSDESTMAP_P3_DFIRDDESTM3_MASK)
/*! @} */

/*! @name VREFINGLOBAL_P3 - PHY Global Vref Controls */
/*! @{ */

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINSEL_MASK (0x7U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINSEL_SHIFT (0U)
/*! GlobalVrefInSel - GlobalVrefInSel[1:0] controls the mode of the PHY VREF DAC and the BP_VREF pin
 *    ========================================================== 2'b00 - PHY Vref DAC Range0 --
 *    BP_VREF = Hi-Z 2'b01 - Reserved Encoding 2'b10 - PHY Vref DAC Range0 -- BP_VREF connected to PLL
 *    Analog Bus 2'b11 - PHY Vref DAC Range0 -- BP_VREF connected to PHY Vref DAC
 *    ========================================================== GlobalVrefInSel[2] shall be set according to Dram
 *    Protocol: Protocol GlobalVrefInSel[2] ------------------------------------------ DDR3 1'b0 DDR4
 *    1'b0 LPDDR3 1'b0 LPDDR4 1'b1
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINSEL_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINSEL_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINDAC_MASK (0x3F8U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINDAC_SHIFT (3U)
/*! GlobalVrefInDAC - DAC code for internal Vref generation The DAC has two ranges; the range is set
 *    by GlobalVrefInSel[2] ========================================================== RANGE0 :
 *    DDR3,DDR4,LPDDR3 [GlobalVrefInSel[2] = 0] DAC Output Voltage = GlobalVrefInDAC == 6'h00 ? Hi-Z :
 *    0.
 */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINDAC(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINDAC_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINDAC_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINTRIM_MASK (0x3C00U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINTRIM_SHIFT (10U)
/*! GlobalVrefInTrim - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINTRIM(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINTRIM_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINTRIM_MASK)

#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINMODE_MASK (0x4000U)
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINMODE_SHIFT (14U)
/*! GlobalVrefInMode - RSVD */
#define DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINMODE_SHIFT)) & DWC_DDRPHYA_MASTER_VREFINGLOBAL_P3_GLOBALVREFINMODE_MASK)
/*! @} */

/*! @name DFIWRDATACSDESTMAP_P3 - Maps dfi_rddata_cs_n to destination dimm timing group for use with D4 LRDIMM */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM0_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM0_SHIFT (0U)
/*! DfiWrDestm0 - Maps dfi_wrdata_cs_n_p0[0] to dest DfiWrDestm0 timing For example, if 0
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg0 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM0_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM0_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM1_MASK (0xCU)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM1_SHIFT (2U)
/*! DfiWrDestm1 - Maps dfi_wrdata_cs_n_p0[1] to dest DfiWrDestm1 timing For example, if 1
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg1 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM1_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM1_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM2_MASK (0x30U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM2_SHIFT (4U)
/*! DfiWrDestm2 - Maps dfi_wrdata_cs_n_p0[2] to dest DfiWrDestm2 timing For example, if 2
 *    dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg2 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM2_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM2_MASK)

#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM3_MASK (0xC0U)
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM3_SHIFT (6U)
/*! DfiWrDestm3 - Maps dfi_wrdata_cs_n_p0[3] to dest DfiWrDestm3 timing (use Register
 *    TxDq,DqsDlyTg3) For example, if 3 dfi_wrdata_cs_n_p0[0] will use Register TxDq,DqsDlyTg3 timing.
 */
#define DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIWRDATACSDESTMAP_P3_DFIWRDESTM3_MASK)
/*! @} */

/*! @name PLLCTRL2_P3 - PState dependent PLL Control Register 2 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL2_P3_PLLFREQSEL_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P3_PLLFREQSEL_SHIFT (0U)
/*! PllFreqSel - Adjusts the loop parameters to compensate for different VCO bias points, and input/output clock division ratios. */
#define DWC_DDRPHYA_MASTER_PLLCTRL2_P3_PLLFREQSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL2_P3_PLLFREQSEL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL2_P3_PLLFREQSEL_MASK)
/*! @} */

/*! @name PLLCTRL1_P3 - PState dependent PLL Control Register 1 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PLLCPINTCTRL_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PLLCPINTCTRL_SHIFT (0U)
/*! PllCpIntCtrl - connects directly to cp_int_cntrl<1:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PLLCPINTCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PLLCPINTCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PLLCPINTCTRL_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PLLCPPROPCTRL_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PLLCPPROPCTRL_SHIFT (5U)
/*! PllCpPropCtrl - connects directly to cp_prop_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PLLCPPROPCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PLLCPPROPCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL1_P3_PLLCPPROPCTRL_MASK)
/*! @} */

/*! @name PLLTESTMODE_P3 - Additional controls for PLL CP/VCO modes of operation */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P3_PLLTESTMODE_P3_MASK (0xFFFFU)
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P3_PLLTESTMODE_P3_SHIFT (0U)
/*! PllTestMode_p3 - It is required to use default values for this CSR unless directed otherwise by Synopsys. */
#define DWC_DDRPHYA_MASTER_PLLTESTMODE_P3_PLLTESTMODE_P3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLTESTMODE_P3_PLLTESTMODE_P3_SHIFT)) & DWC_DDRPHYA_MASTER_PLLTESTMODE_P3_PLLTESTMODE_P3_MASK)
/*! @} */

/*! @name PLLCTRL4_P3 - PState dependent PLL Control Register 4 */
/*! @{ */

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PLLCPINTGSCTRL_MASK (0x1FU)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PLLCPINTGSCTRL_SHIFT (0U)
/*! PllCpIntGsCtrl - connects directly to cp_int_gs_cntrl<4:0> in PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PLLCPINTGSCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PLLCPINTGSCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PLLCPINTGSCTRL_MASK)

#define DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PLLCPPROPGSCTRL_MASK (0x1E0U)
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PLLCPPROPGSCTRL_SHIFT (5U)
/*! PllCpPropGsCtrl - connects directly to cp_prop_gs_cntrl<3:0> of PLL. */
#define DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PLLCPPROPGSCTRL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PLLCPPROPGSCTRL_SHIFT)) & DWC_DDRPHYA_MASTER_PLLCTRL4_P3_PLLCPPROPGSCTRL_MASK)
/*! @} */

/*! @name DFIFREQRATIO_P3 - DFI Frequency Ratio */
/*! @{ */

#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P3_DFIFREQRATIO_P3_MASK (0x3U)
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P3_DFIFREQRATIO_P3_SHIFT (0U)
/*! DfiFreqRatio_p3 - Used in dwc_ddrphy_pub_serdes to serialize or de-serialize DFI signals 00 =
 *    1:1 mode 01 = 1:2 mode 1x = 1:4 mode* *Note: 1:4 is for future pub revision.
 */
#define DWC_DDRPHYA_MASTER_DFIFREQRATIO_P3_DFIFREQRATIO_P3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_MASTER_DFIFREQRATIO_P3_DFIFREQRATIO_P3_SHIFT)) & DWC_DDRPHYA_MASTER_DFIFREQRATIO_P3_DFIFREQRATIO_P3_MASK)
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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_DWC_DDRPHYA_MASTER_H_ */

