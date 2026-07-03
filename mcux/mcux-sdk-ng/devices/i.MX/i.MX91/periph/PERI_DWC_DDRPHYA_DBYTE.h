/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DWC_DDRPHYA_DBYTE
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DWC_DDRPHYA_DBYTE.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for DWC_DDRPHYA_DBYTE
 *
 * CMSIS Peripheral Access Layer for DWC_DDRPHYA_DBYTE
 */

#if !defined(PERI_DWC_DDRPHYA_DBYTE_H_)
#define PERI_DWC_DDRPHYA_DBYTE_H_                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
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
   -- DWC_DDRPHYA_DBYTE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_DBYTE_Peripheral_Access_Layer DWC_DDRPHYA_DBYTE Peripheral Access Layer
 * @{
 */

/** DWC_DDRPHYA_DBYTE - Register Layout Typedef */
typedef struct {
  __IO uint16_t DBYTEMISCMODE;                     /**< DBYTE Module Disable, offset: 0x0 */
  __IO uint16_t TSMBYTE0;                          /**< Training knob source control., offset: 0x2 */
  __IO uint16_t TRAININGPARAM;                     /**< Training delay knob rate control, and control for what is being trained., offset: 0x4 */
  __IO uint16_t USEDQSENREPLICA_P0;                /**< Enable DqsEnArVIO Delay Matching Path, offset: 0x6 */
       uint8_t RESERVED_0[24];
  __IO uint16_t RXTRAINPATTERNENABLE;              /**< RxGate training pattern match enable for PPT, offset: 0x20 */
  __IO uint16_t TSMBYTE1;                          /**< DTSM accumulator increment/decrement step size., offset: 0x22 */
  __IO uint16_t TSMBYTE2;                          /**< DTSM accumulator upper threshold., offset: 0x24 */
  __IO uint16_t TSMBYTE3;                          /**< DTSM sample imput select and mode control., offset: 0x26 */
  __IO uint16_t TSMBYTE4;                          /**< DTSM inc/dec pulse width control., offset: 0x28 */
       uint8_t RESERVED_1[4];
  __IO uint16_t TESTMODECONFIG;                    /**< Test mode configuration register, offset: 0x2E */
  __IO uint16_t TSMBYTE5;                          /**< DTSM accumulator lower threshold., offset: 0x30 */
       uint8_t RESERVED_2[2];
  __IO uint16_t MTESTMUXSEL;                       /**< Digital Observation Pin control, offset: 0x34 */
       uint8_t RESERVED_3[8];
  __IO uint16_t DTSMTRAINMODECTRL;                 /**< DTSM training speed-up feature control., offset: 0x3E */
  __IO uint16_t DFIMRL_P0;                         /**< DFI MaxReadLatency, offset: 0x40 */
       uint8_t RESERVED_4[6];
  __IO uint16_t ASYNCDBYTEMODE;                    /**< Enables Async Flyover for all lanes of the DBYTE, offset: 0x48 */
       uint8_t RESERVED_5[2];
  __IO uint16_t ASYNCDBYTETXEN;                    /**< TxEnable bits for Async Flyover, offset: 0x4C */
       uint8_t RESERVED_6[2];
  __IO uint16_t ASYNCDBYTETXDATA;                  /**< TxData bits for Async Flyover, offset: 0x50 */
       uint8_t RESERVED_7[2];
  __I  uint16_t ASYNCDBYTERXDATA;                  /**< RxData bits for Async Flyover, offset: 0x54 */
       uint8_t RESERVED_8[10];
  __IO uint16_t VREFDAC1_R0;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0x60 */
       uint8_t RESERVED_9[2];
  __IO uint16_t TRAININGCNTR_R0;                   /**< Training counter., offset: 0x64 */
       uint8_t RESERVED_10[26];
  __IO uint16_t VREFDAC0_R0;                       /**< VrefDAC0 control for DQ Receiver, offset: 0x80 */
  __IO uint16_t TXIMPEDANCECTRL0_B0_P0;            /**< Reserved, offset: 0x82 */
       uint8_t RESERVED_11[2];
  __IO uint16_t DQDQSRCVCNTRL_B0_P0;               /**< Dq/Dqs receiver control, offset: 0x86 */
       uint8_t RESERVED_12[8];
  __IO uint16_t TXEQUALIZATIONMODE_P0;             /**< Tx dq driver equalization mode controls., offset: 0x90 */
  __IO uint16_t TXIMPEDANCECTRL1_B0_P0;            /**< TX impedance controls, offset: 0x92 */
  __IO uint16_t DQDQSRCVCNTRL1;                    /**< Dq/Dqs receiver control, offset: 0x94 */
  __IO uint16_t TXIMPEDANCECTRL2_B0_P0;            /**< Reserved, offset: 0x96 */
  __IO uint16_t DQDQSRCVCNTRL2_P0;                 /**< Dq/Dqs receiver control, offset: 0x98 */
  __IO uint16_t TXODTDRVSTREN_B0_P0;               /**< TX ODT driver strength control, offset: 0x9A */
       uint8_t RESERVED_13[16];
  __I  uint16_t RXFIFOCHECKSTATUS;                 /**< Status of RX FIFO Consistency Checks, offset: 0xAC */
  __I  uint16_t RXFIFOCHECKERRVALUES;              /**< Contains the captured values associated with an RxFifo consistency error, offset: 0xAE */
  __I  uint16_t RXFIFOINFO;                        /**< Data Receive FIFO Pointer Values, offset: 0xB0 */
  __IO uint16_t RXFIFOVISIBILITY;                  /**< RX FIFO visibility, offset: 0xB2 */
  __I  uint16_t RXFIFOCONTENTSDQ3210;              /**< RX FIFO contents, lane[3:0], offset: 0xB4 */
  __I  uint16_t RXFIFOCONTENTSDQ7654;              /**< RX FIFO contents, lane[7:4], offset: 0xB6 */
  __I  uint16_t RXFIFOCONTENTSDBI;                 /**< RX FIFO contents, dbi, offset: 0xB8 */
       uint8_t RESERVED_14[4];
  __IO uint16_t TXSLEWRATE_B0_P0;                  /**< TX slew rate controls, offset: 0xBE */
       uint8_t RESERVED_15[4];
  __IO uint16_t TRAININGINCDECDTSMEN_R0;           /**< Enables the any of a group of DTSMs to modify a particular TrainingCounter, offset: 0xC4 */
       uint8_t RESERVED_16[10];
  __IO uint16_t RXPBDLYTG0_R0;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0xD0 */
  __IO uint16_t RXPBDLYTG1_R0;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0xD2 */
  __IO uint16_t RXPBDLYTG2_R0;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0xD4 */
  __IO uint16_t RXPBDLYTG3_R0;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0xD6 */
       uint8_t RESERVED_17[40];
  __IO uint16_t RXENDLYTG0_U0_P0;                  /**< Trained Receive Enable Delay., offset: 0x100 */
  __IO uint16_t RXENDLYTG1_U0_P0;                  /**< Trained Receive Enable Delay., offset: 0x102 */
  __IO uint16_t RXENDLYTG2_U0_P0;                  /**< Trained Receive Enable Delay., offset: 0x104 */
  __IO uint16_t RXENDLYTG3_U0_P0;                  /**< Trained Receive Enable Delay., offset: 0x106 */
       uint8_t RESERVED_18[16];
  __IO uint16_t RXCLKDLYTG0_U0_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x118 */
  __IO uint16_t RXCLKDLYTG1_U0_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x11A */
  __IO uint16_t RXCLKDLYTG2_U0_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x11C */
  __IO uint16_t RXCLKDLYTG3_U0_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x11E */
  __IO uint16_t RXCLKCDLYTG0_U0_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x120 */
  __IO uint16_t RXCLKCDLYTG1_U0_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1)., offset: 0x122 */
  __IO uint16_t RXCLKCDLYTG2_U0_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x124 */
  __IO uint16_t RXCLKCDLYTG3_U0_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x126 */
       uint8_t RESERVED_19[24];
  __IO uint16_t DQ0LNSEL;                          /**< Maps Phy DQ lane to memory DQ0, offset: 0x140 */
  __IO uint16_t DQ1LNSEL;                          /**< Maps Phy DQ lane to memory DQ1, offset: 0x142 */
  __IO uint16_t DQ2LNSEL;                          /**< Maps Phy DQ lane to memory DQ2, offset: 0x144 */
  __IO uint16_t DQ3LNSEL;                          /**< Maps Phy DQ lane to memory DQ3, offset: 0x146 */
  __IO uint16_t DQ4LNSEL;                          /**< Maps Phy DQ lane to memory DQ4, offset: 0x148 */
  __IO uint16_t DQ5LNSEL;                          /**< Maps Phy DQ lane to memory DQ5, offset: 0x14A */
  __IO uint16_t DQ6LNSEL;                          /**< Maps Phy DQ lane to memory DQ6, offset: 0x14C */
  __IO uint16_t DQ7LNSEL;                          /**< Maps Phy DQ lane to memory DQ7, offset: 0x14E */
       uint8_t RESERVED_20[4];
  __IO uint16_t PPTCTLSTATIC;                      /**< Controls for the PPT of tDQS2DQ, offset: 0x154 */
  __IO uint16_t PPTCTLDYN;                         /**< Controls parameters for the DRAM drift compensation logic, offset: 0x156 */
  __I  uint16_t PPTINFO;                           /**< LPDDR4 PPT information, offset: 0x158 */
  __IO uint16_t PPTRXENEVNT;                       /**< LPDDR4 PPT RxEn control for initialization and for terminating, offset: 0x15A */
  __IO uint16_t PPTDQSCNTINVTRNTG0_P0;             /**< DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation, offset: 0x15C */
  __IO uint16_t PPTDQSCNTINVTRNTG1_P0;             /**< DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation, offset: 0x15E */
       uint8_t RESERVED_21[2];
  __IO uint16_t DTSMBLANKINGCTRL;                  /**< Per Dbyte DTSM blanking time., offset: 0x162 */
  __IO uint16_t TSM0_I0;                           /**< Per DTSM configuration and control, offset: 0x164 */
  __I  uint16_t TSM1_I0;                           /**< Per DTSM cumulative error count, offset: 0x166 */
  __IO uint16_t TSM2_I0;                           /**< Per DTSM control for disabling error checking, offset: 0x168 */
  __IO uint16_t TSM3;                              /**< Per DBYTE module DTSM clear error controls., offset: 0x16A */
  __IO uint16_t TXCHKDATASELECTS;                  /**< Selects to control the Tx and Chk bus selection on a byte basis, offset: 0x16C */
  __I  uint16_t DTSMUPTHLDXINGIND;                 /**< Indicator that latches DTSM upper threshold crossing events, offset: 0x16E */
  __I  uint16_t DTSMLOTHLDXINGIND;                 /**< Indicator that latches DTSM lower threshold crossing events, offset: 0x170 */
  __IO uint16_t DBYTEALLDTSMCTRL0;                 /**< Ctrl that inhibits an enabled DTSM from participating in training., offset: 0x172 */
  __IO uint16_t DBYTEALLDTSMCTRL1;                 /**< Ctrl that gates the increment signal internal to the DTSM., offset: 0x174 */
  __IO uint16_t DBYTEALLDTSMCTRL2;                 /**< Ctrl that gates teh decrement signal internal to the DTSM., offset: 0x176 */
       uint8_t RESERVED_22[8];
  __IO uint16_t TXDQDLYTG0_R0_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x180 */
  __IO uint16_t TXDQDLYTG1_R0_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x182 */
  __IO uint16_t TXDQDLYTG2_R0_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x184 */
  __IO uint16_t TXDQDLYTG3_R0_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x186 */
       uint8_t RESERVED_23[24];
  __IO uint16_t TXDQSDLYTG0_U0_P0;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x1A0 */
  __IO uint16_t TXDQSDLYTG1_U0_P0;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x1A2 */
  __IO uint16_t TXDQSDLYTG2_U0_P0;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x1A4 */
  __IO uint16_t TXDQSDLYTG3_U0_P0;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x1A6 */
       uint8_t RESERVED_24[32];
  __I  uint16_t DXLCDLSTATUS;                      /**< Debug status of the DBYTE LCDL, offset: 0x1C8 */
       uint8_t RESERVED_25[150];
  __IO uint16_t VREFDAC1_R1;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0x260 */
       uint8_t RESERVED_26[2];
  __IO uint16_t TRAININGCNTR_R1;                   /**< Training counter., offset: 0x264 */
       uint8_t RESERVED_27[26];
  __IO uint16_t VREFDAC0_R1;                       /**< VrefDAC0 control for DQ Receiver, offset: 0x280 */
  __IO uint16_t TXIMPEDANCECTRL0_B1_P0;            /**< Reserved, offset: 0x282 */
       uint8_t RESERVED_28[2];
  __IO uint16_t DQDQSRCVCNTRL_B1_P0;               /**< Dq/Dqs receiver control, offset: 0x286 */
       uint8_t RESERVED_29[10];
  __IO uint16_t TXIMPEDANCECTRL1_B1_P0;            /**< TX impedance controls, offset: 0x292 */
       uint8_t RESERVED_30[2];
  __IO uint16_t TXIMPEDANCECTRL2_B1_P0;            /**< Reserved, offset: 0x296 */
       uint8_t RESERVED_31[2];
  __IO uint16_t TXODTDRVSTREN_B1_P0;               /**< TX ODT driver strength control, offset: 0x29A */
       uint8_t RESERVED_32[34];
  __IO uint16_t TXSLEWRATE_B1_P0;                  /**< TX slew rate controls, offset: 0x2BE */
       uint8_t RESERVED_33[4];
  __IO uint16_t TRAININGINCDECDTSMEN_R1;           /**< Enables the any of a group of DTSMs to modify a particular TrainingCounter, offset: 0x2C4 */
       uint8_t RESERVED_34[10];
  __IO uint16_t RXPBDLYTG0_R1;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0x2D0 */
  __IO uint16_t RXPBDLYTG1_R1;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0x2D2 */
  __IO uint16_t RXPBDLYTG2_R1;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0x2D4 */
  __IO uint16_t RXPBDLYTG3_R1;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0x2D6 */
       uint8_t RESERVED_35[40];
  __IO uint16_t RXENDLYTG0_U1_P0;                  /**< Trained Receive Enable Delay., offset: 0x300 */
  __IO uint16_t RXENDLYTG1_U1_P0;                  /**< Trained Receive Enable Delay., offset: 0x302 */
  __IO uint16_t RXENDLYTG2_U1_P0;                  /**< Trained Receive Enable Delay., offset: 0x304 */
  __IO uint16_t RXENDLYTG3_U1_P0;                  /**< Trained Receive Enable Delay., offset: 0x306 */
       uint8_t RESERVED_36[16];
  __IO uint16_t RXCLKDLYTG0_U1_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x318 */
  __IO uint16_t RXCLKDLYTG1_U1_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x31A */
  __IO uint16_t RXCLKDLYTG2_U1_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x31C */
  __IO uint16_t RXCLKDLYTG3_U1_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x31E */
  __IO uint16_t RXCLKCDLYTG0_U1_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x320 */
  __IO uint16_t RXCLKCDLYTG1_U1_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1)., offset: 0x322 */
  __IO uint16_t RXCLKCDLYTG2_U1_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x324 */
  __IO uint16_t RXCLKCDLYTG3_U1_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x326 */
       uint8_t RESERVED_37[60];
  __IO uint16_t TSM0_I1;                           /**< Per DTSM configuration and control, offset: 0x364 */
  __I  uint16_t TSM1_I1;                           /**< Per DTSM cumulative error count, offset: 0x366 */
  __IO uint16_t TSM2_I1;                           /**< Per DTSM control for disabling error checking, offset: 0x368 */
       uint8_t RESERVED_38[22];
  __IO uint16_t TXDQDLYTG0_R1_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x380 */
  __IO uint16_t TXDQDLYTG1_R1_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x382 */
  __IO uint16_t TXDQDLYTG2_R1_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x384 */
  __IO uint16_t TXDQDLYTG3_R1_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x386 */
       uint8_t RESERVED_39[24];
  __IO uint16_t TXDQSDLYTG0_U1_P0;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x3A0 */
  __IO uint16_t TXDQSDLYTG1_U1_P0;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x3A2 */
  __IO uint16_t TXDQSDLYTG2_U1_P0;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x3A4 */
  __IO uint16_t TXDQSDLYTG3_U1_P0;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x3A6 */
       uint8_t RESERVED_40[184];
  __IO uint16_t VREFDAC1_R2;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0x460 */
       uint8_t RESERVED_41[2];
  __IO uint16_t TRAININGCNTR_R2;                   /**< Training counter., offset: 0x464 */
       uint8_t RESERVED_42[26];
  __IO uint16_t VREFDAC0_R2;                       /**< VrefDAC0 control for DQ Receiver, offset: 0x480 */
       uint8_t RESERVED_43[66];
  __IO uint16_t TRAININGINCDECDTSMEN_R2;           /**< Enables the any of a group of DTSMs to modify a particular TrainingCounter, offset: 0x4C4 */
       uint8_t RESERVED_44[10];
  __IO uint16_t RXPBDLYTG0_R2;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0x4D0 */
  __IO uint16_t RXPBDLYTG1_R2;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0x4D2 */
  __IO uint16_t RXPBDLYTG2_R2;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0x4D4 */
  __IO uint16_t RXPBDLYTG3_R2;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0x4D6 */
       uint8_t RESERVED_45[140];
  __IO uint16_t TSM0_I2;                           /**< Per DTSM configuration and control, offset: 0x564 */
  __I  uint16_t TSM1_I2;                           /**< Per DTSM cumulative error count, offset: 0x566 */
  __IO uint16_t TSM2_I2;                           /**< Per DTSM control for disabling error checking, offset: 0x568 */
       uint8_t RESERVED_46[22];
  __IO uint16_t TXDQDLYTG0_R2_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x580 */
  __IO uint16_t TXDQDLYTG1_R2_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x582 */
  __IO uint16_t TXDQDLYTG2_R2_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x584 */
  __IO uint16_t TXDQDLYTG3_R2_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x586 */
       uint8_t RESERVED_47[216];
  __IO uint16_t VREFDAC1_R3;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0x660 */
       uint8_t RESERVED_48[2];
  __IO uint16_t TRAININGCNTR_R3;                   /**< Training counter., offset: 0x664 */
       uint8_t RESERVED_49[26];
  __IO uint16_t VREFDAC0_R3;                       /**< VrefDAC0 control for DQ Receiver, offset: 0x680 */
       uint8_t RESERVED_50[66];
  __IO uint16_t TRAININGINCDECDTSMEN_R3;           /**< Enables the any of a group of DTSMs to modify a particular TrainingCounter, offset: 0x6C4 */
       uint8_t RESERVED_51[10];
  __IO uint16_t RXPBDLYTG0_R3;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0x6D0 */
  __IO uint16_t RXPBDLYTG1_R3;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0x6D2 */
  __IO uint16_t RXPBDLYTG2_R3;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0x6D4 */
  __IO uint16_t RXPBDLYTG3_R3;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0x6D6 */
       uint8_t RESERVED_52[140];
  __IO uint16_t TSM0_I3;                           /**< Per DTSM configuration and control, offset: 0x764 */
  __I  uint16_t TSM1_I3;                           /**< Per DTSM cumulative error count, offset: 0x766 */
  __IO uint16_t TSM2_I3;                           /**< Per DTSM control for disabling error checking, offset: 0x768 */
       uint8_t RESERVED_53[22];
  __IO uint16_t TXDQDLYTG0_R3_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x780 */
  __IO uint16_t TXDQDLYTG1_R3_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x782 */
  __IO uint16_t TXDQDLYTG2_R3_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x784 */
  __IO uint16_t TXDQDLYTG3_R3_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x786 */
       uint8_t RESERVED_54[216];
  __IO uint16_t VREFDAC1_R4;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0x860 */
       uint8_t RESERVED_55[2];
  __IO uint16_t TRAININGCNTR_R4;                   /**< Training counter., offset: 0x864 */
       uint8_t RESERVED_56[26];
  __IO uint16_t VREFDAC0_R4;                       /**< VrefDAC0 control for DQ Receiver, offset: 0x880 */
       uint8_t RESERVED_57[66];
  __IO uint16_t TRAININGINCDECDTSMEN_R4;           /**< Enables the any of a group of DTSMs to modify a particular TrainingCounter, offset: 0x8C4 */
       uint8_t RESERVED_58[10];
  __IO uint16_t RXPBDLYTG0_R4;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0x8D0 */
  __IO uint16_t RXPBDLYTG1_R4;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0x8D2 */
  __IO uint16_t RXPBDLYTG2_R4;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0x8D4 */
  __IO uint16_t RXPBDLYTG3_R4;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0x8D6 */
       uint8_t RESERVED_59[140];
  __IO uint16_t TSM0_I4;                           /**< Per DTSM configuration and control, offset: 0x964 */
  __I  uint16_t TSM1_I4;                           /**< Per DTSM cumulative error count, offset: 0x966 */
  __IO uint16_t TSM2_I4;                           /**< Per DTSM control for disabling error checking, offset: 0x968 */
       uint8_t RESERVED_60[22];
  __IO uint16_t TXDQDLYTG0_R4_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x980 */
  __IO uint16_t TXDQDLYTG1_R4_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x982 */
  __IO uint16_t TXDQDLYTG2_R4_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x984 */
  __IO uint16_t TXDQDLYTG3_R4_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x986 */
       uint8_t RESERVED_61[216];
  __IO uint16_t VREFDAC1_R5;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0xA60 */
       uint8_t RESERVED_62[2];
  __IO uint16_t TRAININGCNTR_R5;                   /**< Training counter., offset: 0xA64 */
       uint8_t RESERVED_63[26];
  __IO uint16_t VREFDAC0_R5;                       /**< VrefDAC0 control for DQ Receiver, offset: 0xA80 */
       uint8_t RESERVED_64[66];
  __IO uint16_t TRAININGINCDECDTSMEN_R5;           /**< Enables the any of a group of DTSMs to modify a particular TrainingCounter, offset: 0xAC4 */
       uint8_t RESERVED_65[10];
  __IO uint16_t RXPBDLYTG0_R5;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0xAD0 */
  __IO uint16_t RXPBDLYTG1_R5;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0xAD2 */
  __IO uint16_t RXPBDLYTG2_R5;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0xAD4 */
  __IO uint16_t RXPBDLYTG3_R5;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0xAD6 */
       uint8_t RESERVED_66[140];
  __IO uint16_t TSM0_I5;                           /**< Per DTSM configuration and control, offset: 0xB64 */
  __I  uint16_t TSM1_I5;                           /**< Per DTSM cumulative error count, offset: 0xB66 */
  __IO uint16_t TSM2_I5;                           /**< Per DTSM control for disabling error checking, offset: 0xB68 */
       uint8_t RESERVED_67[22];
  __IO uint16_t TXDQDLYTG0_R5_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0xB80 */
  __IO uint16_t TXDQDLYTG1_R5_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0xB82 */
  __IO uint16_t TXDQDLYTG2_R5_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0xB84 */
  __IO uint16_t TXDQDLYTG3_R5_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0xB86 */
       uint8_t RESERVED_68[216];
  __IO uint16_t VREFDAC1_R6;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0xC60 */
       uint8_t RESERVED_69[2];
  __IO uint16_t TRAININGCNTR_R6;                   /**< Training counter., offset: 0xC64 */
       uint8_t RESERVED_70[26];
  __IO uint16_t VREFDAC0_R6;                       /**< VrefDAC0 control for DQ Receiver, offset: 0xC80 */
       uint8_t RESERVED_71[66];
  __IO uint16_t TRAININGINCDECDTSMEN_R6;           /**< Enables the any of a group of DTSMs to modify a particular TrainingCounter, offset: 0xCC4 */
       uint8_t RESERVED_72[10];
  __IO uint16_t RXPBDLYTG0_R6;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0xCD0 */
  __IO uint16_t RXPBDLYTG1_R6;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0xCD2 */
  __IO uint16_t RXPBDLYTG2_R6;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0xCD4 */
  __IO uint16_t RXPBDLYTG3_R6;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0xCD6 */
       uint8_t RESERVED_73[140];
  __IO uint16_t TSM0_I6;                           /**< Per DTSM configuration and control, offset: 0xD64 */
  __I  uint16_t TSM1_I6;                           /**< Per DTSM cumulative error count, offset: 0xD66 */
  __IO uint16_t TSM2_I6;                           /**< Per DTSM control for disabling error checking, offset: 0xD68 */
       uint8_t RESERVED_74[22];
  __IO uint16_t TXDQDLYTG0_R6_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0xD80 */
  __IO uint16_t TXDQDLYTG1_R6_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0xD82 */
  __IO uint16_t TXDQDLYTG2_R6_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0xD84 */
  __IO uint16_t TXDQDLYTG3_R6_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0xD86 */
       uint8_t RESERVED_75[216];
  __IO uint16_t VREFDAC1_R7;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0xE60 */
       uint8_t RESERVED_76[2];
  __IO uint16_t TRAININGCNTR_R7;                   /**< Training counter., offset: 0xE64 */
       uint8_t RESERVED_77[26];
  __IO uint16_t VREFDAC0_R7;                       /**< VrefDAC0 control for DQ Receiver, offset: 0xE80 */
       uint8_t RESERVED_78[66];
  __IO uint16_t TRAININGINCDECDTSMEN_R7;           /**< Enables the any of a group of DTSMs to modify a particular TrainingCounter, offset: 0xEC4 */
       uint8_t RESERVED_79[10];
  __IO uint16_t RXPBDLYTG0_R7;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0xED0 */
  __IO uint16_t RXPBDLYTG1_R7;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0xED2 */
  __IO uint16_t RXPBDLYTG2_R7;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0xED4 */
  __IO uint16_t RXPBDLYTG3_R7;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0xED6 */
       uint8_t RESERVED_80[140];
  __IO uint16_t TSM0_I7;                           /**< Per DTSM configuration and control, offset: 0xF64 */
  __I  uint16_t TSM1_I7;                           /**< Per DTSM cumulative error count, offset: 0xF66 */
  __IO uint16_t TSM2_I7;                           /**< Per DTSM control for disabling error checking, offset: 0xF68 */
       uint8_t RESERVED_81[22];
  __IO uint16_t TXDQDLYTG0_R7_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0xF80 */
  __IO uint16_t TXDQDLYTG1_R7_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0xF82 */
  __IO uint16_t TXDQDLYTG2_R7_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0xF84 */
  __IO uint16_t TXDQDLYTG3_R7_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0xF86 */
       uint8_t RESERVED_82[216];
  __IO uint16_t VREFDAC1_R8;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0x1060 */
       uint8_t RESERVED_83[2];
  __IO uint16_t TRAININGCNTR_R8;                   /**< Training counter., offset: 0x1064 */
       uint8_t RESERVED_84[26];
  __IO uint16_t VREFDAC0_R8;                       /**< VrefDAC0 control for DQ Receiver, offset: 0x1080 */
       uint8_t RESERVED_85[66];
  __IO uint16_t TRAININGINCDECDTSMEN_R8;           /**< Enables the any of a group of DTSMs to modify a particular TrainingCounter, offset: 0x10C4 */
       uint8_t RESERVED_86[10];
  __IO uint16_t RXPBDLYTG0_R8;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0x10D0 */
  __IO uint16_t RXPBDLYTG1_R8;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0x10D2 */
  __IO uint16_t RXPBDLYTG2_R8;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0x10D4 */
  __IO uint16_t RXPBDLYTG3_R8;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0x10D6 */
       uint8_t RESERVED_87[140];
  __IO uint16_t TSM0_I8;                           /**< Per DTSM configuration and control, offset: 0x1164 */
  __I  uint16_t TSM1_I8;                           /**< Per DTSM cumulative error count, offset: 0x1166 */
  __IO uint16_t TSM2_I8;                           /**< Per DTSM control for disabling error checking, offset: 0x1168 */
       uint8_t RESERVED_88[22];
  __IO uint16_t TXDQDLYTG0_R8_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x1180 */
  __IO uint16_t TXDQDLYTG1_R8_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x1182 */
  __IO uint16_t TXDQDLYTG2_R8_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x1184 */
  __IO uint16_t TXDQDLYTG3_R8_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x1186 */
       uint8_t RESERVED_89[2092670];
  __IO uint16_t USEDQSENREPLICA_P1;                /**< Enable DqsEnArVIO Delay Matching Path, offset: 0x200006 */
       uint8_t RESERVED_90[56];
  __IO uint16_t DFIMRL_P1;                         /**< DFI MaxReadLatency, offset: 0x200040 */
       uint8_t RESERVED_91[64];
  __IO uint16_t TXIMPEDANCECTRL0_B0_P1;            /**< Reserved, offset: 0x200082 */
       uint8_t RESERVED_92[2];
  __IO uint16_t DQDQSRCVCNTRL_B0_P1;               /**< Dq/Dqs receiver control, offset: 0x200086 */
       uint8_t RESERVED_93[8];
  __IO uint16_t TXEQUALIZATIONMODE_P1;             /**< Tx dq driver equalization mode controls., offset: 0x200090 */
  __IO uint16_t TXIMPEDANCECTRL1_B0_P1;            /**< TX impedance controls, offset: 0x200092 */
       uint8_t RESERVED_94[2];
  __IO uint16_t TXIMPEDANCECTRL2_B0_P1;            /**< Reserved, offset: 0x200096 */
  __IO uint16_t DQDQSRCVCNTRL2_P1;                 /**< Dq/Dqs receiver control, offset: 0x200098 */
  __IO uint16_t TXODTDRVSTREN_B0_P1;               /**< TX ODT driver strength control, offset: 0x20009A */
       uint8_t RESERVED_95[34];
  __IO uint16_t TXSLEWRATE_B0_P1;                  /**< TX slew rate controls, offset: 0x2000BE */
       uint8_t RESERVED_96[64];
  __IO uint16_t RXENDLYTG0_U0_P1;                  /**< Trained Receive Enable Delay., offset: 0x200100 */
  __IO uint16_t RXENDLYTG1_U0_P1;                  /**< Trained Receive Enable Delay., offset: 0x200102 */
  __IO uint16_t RXENDLYTG2_U0_P1;                  /**< Trained Receive Enable Delay., offset: 0x200104 */
  __IO uint16_t RXENDLYTG3_U0_P1;                  /**< Trained Receive Enable Delay., offset: 0x200106 */
       uint8_t RESERVED_97[16];
  __IO uint16_t RXCLKDLYTG0_U0_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x200118 */
  __IO uint16_t RXCLKDLYTG1_U0_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x20011A */
  __IO uint16_t RXCLKDLYTG2_U0_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x20011C */
  __IO uint16_t RXCLKDLYTG3_U0_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x20011E */
  __IO uint16_t RXCLKCDLYTG0_U0_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x200120 */
  __IO uint16_t RXCLKCDLYTG1_U0_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1)., offset: 0x200122 */
  __IO uint16_t RXCLKCDLYTG2_U0_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x200124 */
  __IO uint16_t RXCLKCDLYTG3_U0_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x200126 */
       uint8_t RESERVED_98[52];
  __IO uint16_t PPTDQSCNTINVTRNTG0_P1;             /**< DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation, offset: 0x20015C */
  __IO uint16_t PPTDQSCNTINVTRNTG1_P1;             /**< DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation, offset: 0x20015E */
       uint8_t RESERVED_99[32];
  __IO uint16_t TXDQDLYTG0_R0_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200180 */
  __IO uint16_t TXDQDLYTG1_R0_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200182 */
  __IO uint16_t TXDQDLYTG2_R0_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200184 */
  __IO uint16_t TXDQDLYTG3_R0_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200186 */
       uint8_t RESERVED_100[24];
  __IO uint16_t TXDQSDLYTG0_U0_P1;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x2001A0 */
  __IO uint16_t TXDQSDLYTG1_U0_P1;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x2001A2 */
  __IO uint16_t TXDQSDLYTG2_U0_P1;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x2001A4 */
  __IO uint16_t TXDQSDLYTG3_U0_P1;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x2001A6 */
       uint8_t RESERVED_101[218];
  __IO uint16_t TXIMPEDANCECTRL0_B1_P1;            /**< Reserved, offset: 0x200282 */
       uint8_t RESERVED_102[2];
  __IO uint16_t DQDQSRCVCNTRL_B1_P1;               /**< Dq/Dqs receiver control, offset: 0x200286 */
       uint8_t RESERVED_103[10];
  __IO uint16_t TXIMPEDANCECTRL1_B1_P1;            /**< TX impedance controls, offset: 0x200292 */
       uint8_t RESERVED_104[2];
  __IO uint16_t TXIMPEDANCECTRL2_B1_P1;            /**< Reserved, offset: 0x200296 */
       uint8_t RESERVED_105[2];
  __IO uint16_t TXODTDRVSTREN_B1_P1;               /**< TX ODT driver strength control, offset: 0x20029A */
       uint8_t RESERVED_106[34];
  __IO uint16_t TXSLEWRATE_B1_P1;                  /**< TX slew rate controls, offset: 0x2002BE */
       uint8_t RESERVED_107[64];
  __IO uint16_t RXENDLYTG0_U1_P1;                  /**< Trained Receive Enable Delay., offset: 0x200300 */
  __IO uint16_t RXENDLYTG1_U1_P1;                  /**< Trained Receive Enable Delay., offset: 0x200302 */
  __IO uint16_t RXENDLYTG2_U1_P1;                  /**< Trained Receive Enable Delay., offset: 0x200304 */
  __IO uint16_t RXENDLYTG3_U1_P1;                  /**< Trained Receive Enable Delay., offset: 0x200306 */
       uint8_t RESERVED_108[16];
  __IO uint16_t RXCLKDLYTG0_U1_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x200318 */
  __IO uint16_t RXCLKDLYTG1_U1_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x20031A */
  __IO uint16_t RXCLKDLYTG2_U1_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x20031C */
  __IO uint16_t RXCLKDLYTG3_U1_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x20031E */
  __IO uint16_t RXCLKCDLYTG0_U1_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x200320 */
  __IO uint16_t RXCLKCDLYTG1_U1_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1)., offset: 0x200322 */
  __IO uint16_t RXCLKCDLYTG2_U1_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x200324 */
  __IO uint16_t RXCLKCDLYTG3_U1_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x200326 */
       uint8_t RESERVED_109[88];
  __IO uint16_t TXDQDLYTG0_R1_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200380 */
  __IO uint16_t TXDQDLYTG1_R1_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200382 */
  __IO uint16_t TXDQDLYTG2_R1_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200384 */
  __IO uint16_t TXDQDLYTG3_R1_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200386 */
       uint8_t RESERVED_110[24];
  __IO uint16_t TXDQSDLYTG0_U1_P1;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x2003A0 */
  __IO uint16_t TXDQSDLYTG1_U1_P1;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x2003A2 */
  __IO uint16_t TXDQSDLYTG2_U1_P1;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x2003A4 */
  __IO uint16_t TXDQSDLYTG3_U1_P1;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x2003A6 */
       uint8_t RESERVED_111[472];
  __IO uint16_t TXDQDLYTG0_R2_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200580 */
  __IO uint16_t TXDQDLYTG1_R2_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200582 */
  __IO uint16_t TXDQDLYTG2_R2_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200584 */
  __IO uint16_t TXDQDLYTG3_R2_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200586 */
       uint8_t RESERVED_112[504];
  __IO uint16_t TXDQDLYTG0_R3_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200780 */
  __IO uint16_t TXDQDLYTG1_R3_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200782 */
  __IO uint16_t TXDQDLYTG2_R3_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200784 */
  __IO uint16_t TXDQDLYTG3_R3_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200786 */
       uint8_t RESERVED_113[504];
  __IO uint16_t TXDQDLYTG0_R4_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200980 */
  __IO uint16_t TXDQDLYTG1_R4_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200982 */
  __IO uint16_t TXDQDLYTG2_R4_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200984 */
  __IO uint16_t TXDQDLYTG3_R4_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200986 */
       uint8_t RESERVED_114[504];
  __IO uint16_t TXDQDLYTG0_R5_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200B80 */
  __IO uint16_t TXDQDLYTG1_R5_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200B82 */
  __IO uint16_t TXDQDLYTG2_R5_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200B84 */
  __IO uint16_t TXDQDLYTG3_R5_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200B86 */
       uint8_t RESERVED_115[504];
  __IO uint16_t TXDQDLYTG0_R6_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200D80 */
  __IO uint16_t TXDQDLYTG1_R6_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200D82 */
  __IO uint16_t TXDQDLYTG2_R6_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200D84 */
  __IO uint16_t TXDQDLYTG3_R6_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200D86 */
       uint8_t RESERVED_116[504];
  __IO uint16_t TXDQDLYTG0_R7_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200F80 */
  __IO uint16_t TXDQDLYTG1_R7_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200F82 */
  __IO uint16_t TXDQDLYTG2_R7_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200F84 */
  __IO uint16_t TXDQDLYTG3_R7_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200F86 */
       uint8_t RESERVED_117[504];
  __IO uint16_t TXDQDLYTG0_R8_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x201180 */
  __IO uint16_t TXDQDLYTG1_R8_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x201182 */
  __IO uint16_t TXDQDLYTG2_R8_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x201184 */
  __IO uint16_t TXDQDLYTG3_R8_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x201186 */
       uint8_t RESERVED_118[2092670];
  __IO uint16_t USEDQSENREPLICA_P2;                /**< Enable DqsEnArVIO Delay Matching Path, offset: 0x400006 */
       uint8_t RESERVED_119[56];
  __IO uint16_t DFIMRL_P2;                         /**< DFI MaxReadLatency, offset: 0x400040 */
       uint8_t RESERVED_120[64];
  __IO uint16_t TXIMPEDANCECTRL0_B0_P2;            /**< Reserved, offset: 0x400082 */
       uint8_t RESERVED_121[2];
  __IO uint16_t DQDQSRCVCNTRL_B0_P2;               /**< Dq/Dqs receiver control, offset: 0x400086 */
       uint8_t RESERVED_122[8];
  __IO uint16_t TXEQUALIZATIONMODE_P2;             /**< Tx dq driver equalization mode controls., offset: 0x400090 */
  __IO uint16_t TXIMPEDANCECTRL1_B0_P2;            /**< TX impedance controls, offset: 0x400092 */
       uint8_t RESERVED_123[2];
  __IO uint16_t TXIMPEDANCECTRL2_B0_P2;            /**< Reserved, offset: 0x400096 */
  __IO uint16_t DQDQSRCVCNTRL2_P2;                 /**< Dq/Dqs receiver control, offset: 0x400098 */
  __IO uint16_t TXODTDRVSTREN_B0_P2;               /**< TX ODT driver strength control, offset: 0x40009A */
       uint8_t RESERVED_124[34];
  __IO uint16_t TXSLEWRATE_B0_P2;                  /**< TX slew rate controls, offset: 0x4000BE */
       uint8_t RESERVED_125[64];
  __IO uint16_t RXENDLYTG0_U0_P2;                  /**< Trained Receive Enable Delay., offset: 0x400100 */
  __IO uint16_t RXENDLYTG1_U0_P2;                  /**< Trained Receive Enable Delay., offset: 0x400102 */
  __IO uint16_t RXENDLYTG2_U0_P2;                  /**< Trained Receive Enable Delay., offset: 0x400104 */
  __IO uint16_t RXENDLYTG3_U0_P2;                  /**< Trained Receive Enable Delay., offset: 0x400106 */
       uint8_t RESERVED_126[16];
  __IO uint16_t RXCLKDLYTG0_U0_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x400118 */
  __IO uint16_t RXCLKDLYTG1_U0_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x40011A */
  __IO uint16_t RXCLKDLYTG2_U0_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x40011C */
  __IO uint16_t RXCLKDLYTG3_U0_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x40011E */
  __IO uint16_t RXCLKCDLYTG0_U0_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x400120 */
  __IO uint16_t RXCLKCDLYTG1_U0_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1)., offset: 0x400122 */
  __IO uint16_t RXCLKCDLYTG2_U0_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x400124 */
  __IO uint16_t RXCLKCDLYTG3_U0_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x400126 */
       uint8_t RESERVED_127[52];
  __IO uint16_t PPTDQSCNTINVTRNTG0_P2;             /**< DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation, offset: 0x40015C */
  __IO uint16_t PPTDQSCNTINVTRNTG1_P2;             /**< DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation, offset: 0x40015E */
       uint8_t RESERVED_128[32];
  __IO uint16_t TXDQDLYTG0_R0_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400180 */
  __IO uint16_t TXDQDLYTG1_R0_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400182 */
  __IO uint16_t TXDQDLYTG2_R0_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400184 */
  __IO uint16_t TXDQDLYTG3_R0_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400186 */
       uint8_t RESERVED_129[24];
  __IO uint16_t TXDQSDLYTG0_U0_P2;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x4001A0 */
  __IO uint16_t TXDQSDLYTG1_U0_P2;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x4001A2 */
  __IO uint16_t TXDQSDLYTG2_U0_P2;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x4001A4 */
  __IO uint16_t TXDQSDLYTG3_U0_P2;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x4001A6 */
       uint8_t RESERVED_130[218];
  __IO uint16_t TXIMPEDANCECTRL0_B1_P2;            /**< Reserved, offset: 0x400282 */
       uint8_t RESERVED_131[2];
  __IO uint16_t DQDQSRCVCNTRL_B1_P2;               /**< Dq/Dqs receiver control, offset: 0x400286 */
       uint8_t RESERVED_132[10];
  __IO uint16_t TXIMPEDANCECTRL1_B1_P2;            /**< TX impedance controls, offset: 0x400292 */
       uint8_t RESERVED_133[2];
  __IO uint16_t TXIMPEDANCECTRL2_B1_P2;            /**< Reserved, offset: 0x400296 */
       uint8_t RESERVED_134[2];
  __IO uint16_t TXODTDRVSTREN_B1_P2;               /**< TX ODT driver strength control, offset: 0x40029A */
       uint8_t RESERVED_135[34];
  __IO uint16_t TXSLEWRATE_B1_P2;                  /**< TX slew rate controls, offset: 0x4002BE */
       uint8_t RESERVED_136[64];
  __IO uint16_t RXENDLYTG0_U1_P2;                  /**< Trained Receive Enable Delay., offset: 0x400300 */
  __IO uint16_t RXENDLYTG1_U1_P2;                  /**< Trained Receive Enable Delay., offset: 0x400302 */
  __IO uint16_t RXENDLYTG2_U1_P2;                  /**< Trained Receive Enable Delay., offset: 0x400304 */
  __IO uint16_t RXENDLYTG3_U1_P2;                  /**< Trained Receive Enable Delay., offset: 0x400306 */
       uint8_t RESERVED_137[16];
  __IO uint16_t RXCLKDLYTG0_U1_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x400318 */
  __IO uint16_t RXCLKDLYTG1_U1_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x40031A */
  __IO uint16_t RXCLKDLYTG2_U1_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x40031C */
  __IO uint16_t RXCLKDLYTG3_U1_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x40031E */
  __IO uint16_t RXCLKCDLYTG0_U1_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x400320 */
  __IO uint16_t RXCLKCDLYTG1_U1_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1)., offset: 0x400322 */
  __IO uint16_t RXCLKCDLYTG2_U1_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x400324 */
  __IO uint16_t RXCLKCDLYTG3_U1_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x400326 */
       uint8_t RESERVED_138[88];
  __IO uint16_t TXDQDLYTG0_R1_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400380 */
  __IO uint16_t TXDQDLYTG1_R1_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400382 */
  __IO uint16_t TXDQDLYTG2_R1_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400384 */
  __IO uint16_t TXDQDLYTG3_R1_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400386 */
       uint8_t RESERVED_139[24];
  __IO uint16_t TXDQSDLYTG0_U1_P2;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x4003A0 */
  __IO uint16_t TXDQSDLYTG1_U1_P2;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x4003A2 */
  __IO uint16_t TXDQSDLYTG2_U1_P2;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x4003A4 */
  __IO uint16_t TXDQSDLYTG3_U1_P2;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x4003A6 */
       uint8_t RESERVED_140[472];
  __IO uint16_t TXDQDLYTG0_R2_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400580 */
  __IO uint16_t TXDQDLYTG1_R2_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400582 */
  __IO uint16_t TXDQDLYTG2_R2_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400584 */
  __IO uint16_t TXDQDLYTG3_R2_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400586 */
       uint8_t RESERVED_141[504];
  __IO uint16_t TXDQDLYTG0_R3_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400780 */
  __IO uint16_t TXDQDLYTG1_R3_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400782 */
  __IO uint16_t TXDQDLYTG2_R3_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400784 */
  __IO uint16_t TXDQDLYTG3_R3_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400786 */
       uint8_t RESERVED_142[504];
  __IO uint16_t TXDQDLYTG0_R4_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400980 */
  __IO uint16_t TXDQDLYTG1_R4_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400982 */
  __IO uint16_t TXDQDLYTG2_R4_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400984 */
  __IO uint16_t TXDQDLYTG3_R4_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400986 */
       uint8_t RESERVED_143[504];
  __IO uint16_t TXDQDLYTG0_R5_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400B80 */
  __IO uint16_t TXDQDLYTG1_R5_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400B82 */
  __IO uint16_t TXDQDLYTG2_R5_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400B84 */
  __IO uint16_t TXDQDLYTG3_R5_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400B86 */
       uint8_t RESERVED_144[504];
  __IO uint16_t TXDQDLYTG0_R6_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400D80 */
  __IO uint16_t TXDQDLYTG1_R6_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400D82 */
  __IO uint16_t TXDQDLYTG2_R6_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400D84 */
  __IO uint16_t TXDQDLYTG3_R6_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400D86 */
       uint8_t RESERVED_145[504];
  __IO uint16_t TXDQDLYTG0_R7_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400F80 */
  __IO uint16_t TXDQDLYTG1_R7_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400F82 */
  __IO uint16_t TXDQDLYTG2_R7_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400F84 */
  __IO uint16_t TXDQDLYTG3_R7_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400F86 */
       uint8_t RESERVED_146[504];
  __IO uint16_t TXDQDLYTG0_R8_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x401180 */
  __IO uint16_t TXDQDLYTG1_R8_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x401182 */
  __IO uint16_t TXDQDLYTG2_R8_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x401184 */
  __IO uint16_t TXDQDLYTG3_R8_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x401186 */
       uint8_t RESERVED_147[2092670];
  __IO uint16_t USEDQSENREPLICA_P3;                /**< Enable DqsEnArVIO Delay Matching Path, offset: 0x600006 */
       uint8_t RESERVED_148[56];
  __IO uint16_t DFIMRL_P3;                         /**< DFI MaxReadLatency, offset: 0x600040 */
       uint8_t RESERVED_149[64];
  __IO uint16_t TXIMPEDANCECTRL0_B0_P3;            /**< Reserved, offset: 0x600082 */
       uint8_t RESERVED_150[2];
  __IO uint16_t DQDQSRCVCNTRL_B0_P3;               /**< Dq/Dqs receiver control, offset: 0x600086 */
       uint8_t RESERVED_151[8];
  __IO uint16_t TXEQUALIZATIONMODE_P3;             /**< Tx dq driver equalization mode controls., offset: 0x600090 */
  __IO uint16_t TXIMPEDANCECTRL1_B0_P3;            /**< TX impedance controls, offset: 0x600092 */
       uint8_t RESERVED_152[2];
  __IO uint16_t TXIMPEDANCECTRL2_B0_P3;            /**< Reserved, offset: 0x600096 */
  __IO uint16_t DQDQSRCVCNTRL2_P3;                 /**< Dq/Dqs receiver control, offset: 0x600098 */
  __IO uint16_t TXODTDRVSTREN_B0_P3;               /**< TX ODT driver strength control, offset: 0x60009A */
       uint8_t RESERVED_153[34];
  __IO uint16_t TXSLEWRATE_B0_P3;                  /**< TX slew rate controls, offset: 0x6000BE */
       uint8_t RESERVED_154[64];
  __IO uint16_t RXENDLYTG0_U0_P3;                  /**< Trained Receive Enable Delay., offset: 0x600100 */
  __IO uint16_t RXENDLYTG1_U0_P3;                  /**< Trained Receive Enable Delay., offset: 0x600102 */
  __IO uint16_t RXENDLYTG2_U0_P3;                  /**< Trained Receive Enable Delay., offset: 0x600104 */
  __IO uint16_t RXENDLYTG3_U0_P3;                  /**< Trained Receive Enable Delay., offset: 0x600106 */
       uint8_t RESERVED_155[16];
  __IO uint16_t RXCLKDLYTG0_U0_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x600118 */
  __IO uint16_t RXCLKDLYTG1_U0_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x60011A */
  __IO uint16_t RXCLKDLYTG2_U0_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x60011C */
  __IO uint16_t RXCLKDLYTG3_U0_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x60011E */
  __IO uint16_t RXCLKCDLYTG0_U0_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x600120 */
  __IO uint16_t RXCLKCDLYTG1_U0_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1)., offset: 0x600122 */
  __IO uint16_t RXCLKCDLYTG2_U0_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x600124 */
  __IO uint16_t RXCLKCDLYTG3_U0_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x600126 */
       uint8_t RESERVED_156[52];
  __IO uint16_t PPTDQSCNTINVTRNTG0_P3;             /**< DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation, offset: 0x60015C */
  __IO uint16_t PPTDQSCNTINVTRNTG1_P3;             /**< DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation, offset: 0x60015E */
       uint8_t RESERVED_157[32];
  __IO uint16_t TXDQDLYTG0_R0_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600180 */
  __IO uint16_t TXDQDLYTG1_R0_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600182 */
  __IO uint16_t TXDQDLYTG2_R0_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600184 */
  __IO uint16_t TXDQDLYTG3_R0_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600186 */
       uint8_t RESERVED_158[24];
  __IO uint16_t TXDQSDLYTG0_U0_P3;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x6001A0 */
  __IO uint16_t TXDQSDLYTG1_U0_P3;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x6001A2 */
  __IO uint16_t TXDQSDLYTG2_U0_P3;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x6001A4 */
  __IO uint16_t TXDQSDLYTG3_U0_P3;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x6001A6 */
       uint8_t RESERVED_159[218];
  __IO uint16_t TXIMPEDANCECTRL0_B1_P3;            /**< Reserved, offset: 0x600282 */
       uint8_t RESERVED_160[2];
  __IO uint16_t DQDQSRCVCNTRL_B1_P3;               /**< Dq/Dqs receiver control, offset: 0x600286 */
       uint8_t RESERVED_161[10];
  __IO uint16_t TXIMPEDANCECTRL1_B1_P3;            /**< TX impedance controls, offset: 0x600292 */
       uint8_t RESERVED_162[2];
  __IO uint16_t TXIMPEDANCECTRL2_B1_P3;            /**< Reserved, offset: 0x600296 */
       uint8_t RESERVED_163[2];
  __IO uint16_t TXODTDRVSTREN_B1_P3;               /**< TX ODT driver strength control, offset: 0x60029A */
       uint8_t RESERVED_164[34];
  __IO uint16_t TXSLEWRATE_B1_P3;                  /**< TX slew rate controls, offset: 0x6002BE */
       uint8_t RESERVED_165[64];
  __IO uint16_t RXENDLYTG0_U1_P3;                  /**< Trained Receive Enable Delay., offset: 0x600300 */
  __IO uint16_t RXENDLYTG1_U1_P3;                  /**< Trained Receive Enable Delay., offset: 0x600302 */
  __IO uint16_t RXENDLYTG2_U1_P3;                  /**< Trained Receive Enable Delay., offset: 0x600304 */
  __IO uint16_t RXENDLYTG3_U1_P3;                  /**< Trained Receive Enable Delay., offset: 0x600306 */
       uint8_t RESERVED_166[16];
  __IO uint16_t RXCLKDLYTG0_U1_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x600318 */
  __IO uint16_t RXCLKDLYTG1_U1_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x60031A */
  __IO uint16_t RXCLKDLYTG2_U1_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x60031C */
  __IO uint16_t RXCLKDLYTG3_U1_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x60031E */
  __IO uint16_t RXCLKCDLYTG0_U1_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x600320 */
  __IO uint16_t RXCLKCDLYTG1_U1_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1)., offset: 0x600322 */
  __IO uint16_t RXCLKCDLYTG2_U1_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x600324 */
  __IO uint16_t RXCLKCDLYTG3_U1_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x600326 */
       uint8_t RESERVED_167[88];
  __IO uint16_t TXDQDLYTG0_R1_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600380 */
  __IO uint16_t TXDQDLYTG1_R1_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600382 */
  __IO uint16_t TXDQDLYTG2_R1_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600384 */
  __IO uint16_t TXDQDLYTG3_R1_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600386 */
       uint8_t RESERVED_168[24];
  __IO uint16_t TXDQSDLYTG0_U1_P3;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x6003A0 */
  __IO uint16_t TXDQSDLYTG1_U1_P3;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x6003A2 */
  __IO uint16_t TXDQSDLYTG2_U1_P3;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x6003A4 */
  __IO uint16_t TXDQSDLYTG3_U1_P3;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x6003A6 */
       uint8_t RESERVED_169[472];
  __IO uint16_t TXDQDLYTG0_R2_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600580 */
  __IO uint16_t TXDQDLYTG1_R2_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600582 */
  __IO uint16_t TXDQDLYTG2_R2_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600584 */
  __IO uint16_t TXDQDLYTG3_R2_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600586 */
       uint8_t RESERVED_170[504];
  __IO uint16_t TXDQDLYTG0_R3_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600780 */
  __IO uint16_t TXDQDLYTG1_R3_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600782 */
  __IO uint16_t TXDQDLYTG2_R3_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600784 */
  __IO uint16_t TXDQDLYTG3_R3_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600786 */
       uint8_t RESERVED_171[504];
  __IO uint16_t TXDQDLYTG0_R4_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600980 */
  __IO uint16_t TXDQDLYTG1_R4_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600982 */
  __IO uint16_t TXDQDLYTG2_R4_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600984 */
  __IO uint16_t TXDQDLYTG3_R4_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600986 */
       uint8_t RESERVED_172[504];
  __IO uint16_t TXDQDLYTG0_R5_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600B80 */
  __IO uint16_t TXDQDLYTG1_R5_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600B82 */
  __IO uint16_t TXDQDLYTG2_R5_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600B84 */
  __IO uint16_t TXDQDLYTG3_R5_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600B86 */
       uint8_t RESERVED_173[504];
  __IO uint16_t TXDQDLYTG0_R6_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600D80 */
  __IO uint16_t TXDQDLYTG1_R6_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600D82 */
  __IO uint16_t TXDQDLYTG2_R6_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600D84 */
  __IO uint16_t TXDQDLYTG3_R6_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600D86 */
       uint8_t RESERVED_174[504];
  __IO uint16_t TXDQDLYTG0_R7_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600F80 */
  __IO uint16_t TXDQDLYTG1_R7_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600F82 */
  __IO uint16_t TXDQDLYTG2_R7_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600F84 */
  __IO uint16_t TXDQDLYTG3_R7_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600F86 */
       uint8_t RESERVED_175[504];
  __IO uint16_t TXDQDLYTG0_R8_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x601180 */
  __IO uint16_t TXDQDLYTG1_R8_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x601182 */
  __IO uint16_t TXDQDLYTG2_R8_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x601184 */
  __IO uint16_t TXDQDLYTG3_R8_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x601186 */
} DWC_DDRPHYA_DBYTE_Type;

/* ----------------------------------------------------------------------------
   -- DWC_DDRPHYA_DBYTE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_DBYTE_Register_Masks DWC_DDRPHYA_DBYTE Register Masks
 * @{
 */

/*! @name DBYTEMISCMODE - DBYTE Module Disable */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DBYTEMISCMODE_DByteDisable_MASK (0x4U)
#define DWC_DDRPHYA_DBYTE_DBYTEMISCMODE_DByteDisable_SHIFT (2U)
/*! DByteDisable - Controls whether this DBYTE module is disabled. */
#define DWC_DDRPHYA_DBYTE_DBYTEMISCMODE_DByteDisable(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DBYTEMISCMODE_DByteDisable_SHIFT)) & DWC_DDRPHYA_DBYTE_DBYTEMISCMODE_DByteDisable_MASK)
/*! @} */

/*! @name TSMBYTE0 - Training knob source control. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSMBYTE0_RFU_TsmByte0_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TSMBYTE0_RFU_TsmByte0_SHIFT (0U)
/*! RFU_TsmByte0 - RFU_TsmByte0 */
#define DWC_DDRPHYA_DBYTE_TSMBYTE0_RFU_TsmByte0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSMBYTE0_RFU_TsmByte0_SHIFT)) & DWC_DDRPHYA_DBYTE_TSMBYTE0_RFU_TsmByte0_MASK)
/*! @} */

/*! @name TRAININGPARAM - Training delay knob rate control, and control for what is being trained. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGPARAM_RFU_TrainingParam_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TRAININGPARAM_RFU_TrainingParam_SHIFT (0U)
/*! RFU_TrainingParam - RFU_TrainingParam */
#define DWC_DDRPHYA_DBYTE_TRAININGPARAM_RFU_TrainingParam(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGPARAM_RFU_TrainingParam_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGPARAM_RFU_TrainingParam_MASK)
/*! @} */

/*! @name USEDQSENREPLICA_P0 - Enable DqsEnArVIO Delay Matching Path */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P0_UseDqsEnReplica_p0_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P0_UseDqsEnReplica_p0_SHIFT (0U)
/*! UseDqsEnReplica_p0 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P0_UseDqsEnReplica_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P0_UseDqsEnReplica_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P0_UseDqsEnReplica_p0_MASK)
/*! @} */

/*! @name RXTRAINPATTERNENABLE - RxGate training pattern match enable for PPT */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXTRAINPATTERNENABLE_RxTrainPatternEnable_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_RXTRAINPATTERNENABLE_RxTrainPatternEnable_SHIFT (0U)
/*! RxTrainPatternEnable - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_RXTRAINPATTERNENABLE_RxTrainPatternEnable(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXTRAINPATTERNENABLE_RxTrainPatternEnable_SHIFT)) & DWC_DDRPHYA_DBYTE_RXTRAINPATTERNENABLE_RxTrainPatternEnable_MASK)
/*! @} */

/*! @name TSMBYTE1 - DTSM accumulator increment/decrement step size. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSMBYTE1_RFU_TsmByte1_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TSMBYTE1_RFU_TsmByte1_SHIFT (0U)
/*! RFU_TsmByte1 - RFU_TsmByte1 */
#define DWC_DDRPHYA_DBYTE_TSMBYTE1_RFU_TsmByte1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSMBYTE1_RFU_TsmByte1_SHIFT)) & DWC_DDRPHYA_DBYTE_TSMBYTE1_RFU_TsmByte1_MASK)
/*! @} */

/*! @name TSMBYTE2 - DTSM accumulator upper threshold. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSMBYTE2_RFU_TsmByte2_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TSMBYTE2_RFU_TsmByte2_SHIFT (0U)
/*! RFU_TsmByte2 - RFU_TsmByte2 */
#define DWC_DDRPHYA_DBYTE_TSMBYTE2_RFU_TsmByte2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSMBYTE2_RFU_TsmByte2_SHIFT)) & DWC_DDRPHYA_DBYTE_TSMBYTE2_RFU_TsmByte2_MASK)
/*! @} */

/*! @name TSMBYTE3 - DTSM sample imput select and mode control. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSMBYTE3_RFU_TsmByte3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TSMBYTE3_RFU_TsmByte3_SHIFT (0U)
/*! RFU_TsmByte3 - RFU_TsmByte3 */
#define DWC_DDRPHYA_DBYTE_TSMBYTE3_RFU_TsmByte3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSMBYTE3_RFU_TsmByte3_SHIFT)) & DWC_DDRPHYA_DBYTE_TSMBYTE3_RFU_TsmByte3_MASK)
/*! @} */

/*! @name TSMBYTE4 - DTSM inc/dec pulse width control. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSMBYTE4_RFU_TsmByte4_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_TSMBYTE4_RFU_TsmByte4_SHIFT (0U)
/*! RFU_TsmByte4 - RFU_TsmByte4 */
#define DWC_DDRPHYA_DBYTE_TSMBYTE4_RFU_TsmByte4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSMBYTE4_RFU_TsmByte4_SHIFT)) & DWC_DDRPHYA_DBYTE_TSMBYTE4_RFU_TsmByte4_MASK)
/*! @} */

/*! @name TESTMODECONFIG - Test mode configuration register */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TESTMODECONFIG_RFU_TestModeConfig_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TESTMODECONFIG_RFU_TestModeConfig_SHIFT (0U)
/*! RFU_TestModeConfig - RFU_TestModeConfig */
#define DWC_DDRPHYA_DBYTE_TESTMODECONFIG_RFU_TestModeConfig(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TESTMODECONFIG_RFU_TestModeConfig_SHIFT)) & DWC_DDRPHYA_DBYTE_TESTMODECONFIG_RFU_TestModeConfig_MASK)
/*! @} */

/*! @name TSMBYTE5 - DTSM accumulator lower threshold. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSMBYTE5_RFU_TsmByte5_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TSMBYTE5_RFU_TsmByte5_SHIFT (0U)
/*! RFU_TsmByte5 - RFU_TsmByte5 */
#define DWC_DDRPHYA_DBYTE_TSMBYTE5_RFU_TsmByte5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSMBYTE5_RFU_TsmByte5_SHIFT)) & DWC_DDRPHYA_DBYTE_TSMBYTE5_RFU_TsmByte5_MASK)
/*! @} */

/*! @name MTESTMUXSEL - Digital Observation Pin control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_MTESTMUXSEL_MtestMuxSel_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_MTESTMUXSEL_MtestMuxSel_SHIFT (0U)
/*! MtestMuxSel - Controls for the 64-1 mux for asynchronous data to the Digital Observation Pin. */
#define DWC_DDRPHYA_DBYTE_MTESTMUXSEL_MtestMuxSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_MTESTMUXSEL_MtestMuxSel_SHIFT)) & DWC_DDRPHYA_DBYTE_MTESTMUXSEL_MtestMuxSel_MASK)
/*! @} */

/*! @name DTSMTRAINMODECTRL - DTSM training speed-up feature control. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DTSMTRAINMODECTRL_RFU_DtsmTrainModeCtrl_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_DTSMTRAINMODECTRL_RFU_DtsmTrainModeCtrl_SHIFT (0U)
/*! RFU_DtsmTrainModeCtrl - RFU_DtsmTrainModeCtrl */
#define DWC_DDRPHYA_DBYTE_DTSMTRAINMODECTRL_RFU_DtsmTrainModeCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DTSMTRAINMODECTRL_RFU_DtsmTrainModeCtrl_SHIFT)) & DWC_DDRPHYA_DBYTE_DTSMTRAINMODECTRL_RFU_DtsmTrainModeCtrl_MASK)
/*! @} */

/*! @name DFIMRL_P0 - DFI MaxReadLatency */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DFIMRL_P0_DFIMRL_p0_MASK (0x1FU)
#define DWC_DDRPHYA_DBYTE_DFIMRL_P0_DFIMRL_p0_SHIFT (0U)
/*! DFIMRL_p0 - This Max Read Latency CSR is to be trained to ensure the rx-data fifo is not read
 *    until after all dbytes have their read data valid.
 */
#define DWC_DDRPHYA_DBYTE_DFIMRL_P0_DFIMRL_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DFIMRL_P0_DFIMRL_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_DFIMRL_P0_DFIMRL_p0_MASK)
/*! @} */

/*! @name ASYNCDBYTEMODE - Enables Async Flyover for all lanes of the DBYTE */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_ASYNCDBYTEMODE_AsyncDbyteMode_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_ASYNCDBYTEMODE_AsyncDbyteMode_SHIFT (0U)
/*! AsyncDbyteMode - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_ASYNCDBYTEMODE_AsyncDbyteMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_ASYNCDBYTEMODE_AsyncDbyteMode_SHIFT)) & DWC_DDRPHYA_DBYTE_ASYNCDBYTEMODE_AsyncDbyteMode_MASK)
/*! @} */

/*! @name ASYNCDBYTETXEN - TxEnable bits for Async Flyover */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_ASYNCDBYTETXEN_AsyncDbyteTxEn_MASK (0xFFFU)
#define DWC_DDRPHYA_DBYTE_ASYNCDBYTETXEN_AsyncDbyteTxEn_SHIFT (0U)
/*! AsyncDbyteTxEn - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_ASYNCDBYTETXEN_AsyncDbyteTxEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_ASYNCDBYTETXEN_AsyncDbyteTxEn_SHIFT)) & DWC_DDRPHYA_DBYTE_ASYNCDBYTETXEN_AsyncDbyteTxEn_MASK)
/*! @} */

/*! @name ASYNCDBYTETXDATA - TxData bits for Async Flyover */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_ASYNCDBYTETXDATA_AsyncDbyteTxData_MASK (0xFFFU)
#define DWC_DDRPHYA_DBYTE_ASYNCDBYTETXDATA_AsyncDbyteTxData_SHIFT (0U)
/*! AsyncDbyteTxData - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_ASYNCDBYTETXDATA_AsyncDbyteTxData(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_ASYNCDBYTETXDATA_AsyncDbyteTxData_SHIFT)) & DWC_DDRPHYA_DBYTE_ASYNCDBYTETXDATA_AsyncDbyteTxData_MASK)
/*! @} */

/*! @name ASYNCDBYTERXDATA - RxData bits for Async Flyover */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_ASYNCDBYTERXDATA_AsyncDbyteRxData_MASK (0xFFFU)
#define DWC_DDRPHYA_DBYTE_ASYNCDBYTERXDATA_AsyncDbyteRxData_SHIFT (0U)
/*! AsyncDbyteRxData - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_ASYNCDBYTERXDATA_AsyncDbyteRxData(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_ASYNCDBYTERXDATA_AsyncDbyteRxData_SHIFT)) & DWC_DDRPHYA_DBYTE_ASYNCDBYTERXDATA_AsyncDbyteRxData_MASK)
/*! @} */

/*! @name VREFDAC1_R0 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R0_VrefDAC1_r0_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R0_VrefDAC1_r0_SHIFT (0U)
/*! VrefDAC1_r0 - VrefDAC1_r0 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R0_VrefDAC1_r0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R0_VrefDAC1_r0_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R0_VrefDAC1_r0_MASK)
/*! @} */

/*! @name TRAININGCNTR_R0 - Training counter. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R0_RFU_TrainingCntr_r0_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R0_RFU_TrainingCntr_r0_SHIFT (0U)
/*! RFU_TrainingCntr_r0 - RFU_TrainingCntr_r0 */
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R0_RFU_TrainingCntr_r0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGCNTR_R0_RFU_TrainingCntr_r0_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGCNTR_R0_RFU_TrainingCntr_r0_MASK)
/*! @} */

/*! @name VREFDAC0_R0 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R0_VrefDAC0_r0_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R0_VrefDAC0_r0_SHIFT (0U)
/*! VrefDAC0_r0 - VrefDAC0_r0 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R0_VrefDAC0_r0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R0_VrefDAC0_r0_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R0_VrefDAC0_r0_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL0_B0_P0 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqN_MASK)
/*! @} */

/*! @name DQDQSRCVCNTRL_B0_P0 - Dq/Dqs receiver control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_SelAnalogVref_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_SelAnalogVref_SHIFT (0U)
/*! SelAnalogVref - Setting this signal high will force the local per-bit VREF generator to pass the global VREFA to the samplers. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_SelAnalogVref(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_SelAnalogVref_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_SelAnalogVref_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_ExtVrefRange_MASK (0x2U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_ExtVrefRange_SHIFT (1U)
/*! ExtVrefRange - Extends the range available in the local per-bit VREF generator. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_ExtVrefRange(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_ExtVrefRange_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_ExtVrefRange_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_DfeCtrl_MASK (0xCU)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_DfeCtrl_SHIFT (2U)
/*! DfeCtrl - This field is programmable as follows - 00 - DFE off - 01 - DFE on - 10 - Train DFE0
 *    Amplifier - 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
 *    should not be overridden.
 */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_DfeCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_DfeCtrl_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_DfeCtrl_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_MajorModeDbyte_MASK (0x70U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_MajorModeDbyte_SHIFT (4U)
/*! MajorModeDbyte - Selects the major mode of operation for the receiver. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_MajorModeDbyte(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_MajorModeDbyte_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_MajorModeDbyte_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_GainCurrAdj_MASK (0xF80U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_GainCurrAdj_SHIFT (7U)
/*! GainCurrAdj - Adjust gain current of RX amplifier stage. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_GainCurrAdj(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_GainCurrAdj_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P0_GainCurrAdj_MASK)
/*! @} */

/*! @name TXEQUALIZATIONMODE_P0 - Tx dq driver equalization mode controls. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P0_TxEqMode_MASK (0x3U)
#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P0_TxEqMode_SHIFT (0U)
/*! TxEqMode - Tx dq driver equalization mode controls. */
#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P0_TxEqMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P0_TxEqMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P0_TxEqMode_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL1_B0_P0 - TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqP_SHIFT (0U)
/*! DrvStrenFSDqP - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name DQDQSRCVCNTRL1 - Dq/Dqs receiver control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_PowerDownRcvr_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_PowerDownRcvr_SHIFT (0U)
/*! PowerDownRcvr - Active high signal which powers down the receiver. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_PowerDownRcvr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_PowerDownRcvr_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_PowerDownRcvr_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_PowerDownRcvrDqs_MASK (0x200U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_PowerDownRcvrDqs_SHIFT (9U)
/*! PowerDownRcvrDqs - Active high signal which powers down the receiver. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_PowerDownRcvrDqs(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_PowerDownRcvrDqs_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_PowerDownRcvrDqs_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_RxPadStandbyEn_MASK (0x400U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_RxPadStandbyEn_SHIFT (10U)
/*! RxPadStandbyEn - Enables the rxdq/rxdqs StandBy power savings, per pad-group. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_RxPadStandbyEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_RxPadStandbyEn_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_RxPadStandbyEn_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_EnLPReqPDR_MASK (0x800U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_EnLPReqPDR_SHIFT (11U)
/*! EnLPReqPDR - Reserved for future use */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_EnLPReqPDR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_EnLPReqPDR_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL1_EnLPReqPDR_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B0_P0 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQLoDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQLoDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQLoDqN_MASK)
/*! @} */

/*! @name DQDQSRCVCNTRL2_P0 - Dq/Dqs receiver control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P0_EnRxAgressivePDR_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P0_EnRxAgressivePDR_SHIFT (0U)
/*! EnRxAgressivePDR - reserved */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P0_EnRxAgressivePDR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P0_EnRxAgressivePDR_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P0_EnRxAgressivePDR_MASK)
/*! @} */

/*! @name TXODTDRVSTREN_B0_P0 - TX ODT driver strength control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P0_ODTStrenP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P0_ODTStrenP_SHIFT (0U)
/*! ODTStrenP - Selects the ODT pull-up impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P0_ODTStrenP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P0_ODTStrenP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P0_ODTStrenP_MASK)

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P0_ODTStrenN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P0_ODTStrenN_SHIFT (6U)
/*! ODTStrenN - Selects the ODT pull-down impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P0_ODTStrenN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P0_ODTStrenN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P0_ODTStrenN_MASK)
/*! @} */

/*! @name RXFIFOCHECKSTATUS - Status of RX FIFO Consistency Checks */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoLocErr_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoLocErr_SHIFT (0U)
/*! RxFifoLocErr - If set, the read pointer (DFI side) on the read FIFO associated with data bits
 *    [3:0] didn't match the write pointer (DQS side) on the read FIFO associated with data bits [3:0];
 */
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoLocErr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoLocErr_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoLocErr_MASK)

#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoLocUErr_MASK (0x2U)
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoLocUErr_SHIFT (1U)
/*! RxFifoLocUErr - If set, the read pointer (DFI side) on the read FIFO associated with data bits
 *    [7:4] didn't match the write pointer (DQS side) on the read FIFO associated with data bits
 *    [7:4];
 */
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoLocUErr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoLocUErr_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoLocUErr_MASK)
/*! @} */

/*! @name RXFIFOCHECKERRVALUES - Contains the captured values associated with an RxFifo consistency error */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoRdLocErrValue_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoRdLocErrValue_SHIFT (0U)
/*! RxFifoRdLocErrValue - The first error value captured for the read pointer (DFI side) on the read FIFO associated with data bits [3:0]; */
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoRdLocErrValue(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoRdLocErrValue_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoRdLocErrValue_MASK)

#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoWrLocErrValue_MASK (0xF0U)
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoWrLocErrValue_SHIFT (4U)
/*! RxFifoWrLocErrValue - The first error value captured for the write pointer (DQS side) on the read FIFO associated with data bits [3:0]; */
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoWrLocErrValue(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoWrLocErrValue_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoWrLocErrValue_MASK)

#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoRdLocUErrValue_MASK (0xF00U)
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoRdLocUErrValue_SHIFT (8U)
/*! RxFifoRdLocUErrValue - The first error value captured for the read pointer (DFI side) on the read FIFO associated with data bits [7:4]; */
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoRdLocUErrValue(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoRdLocUErrValue_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoRdLocUErrValue_MASK)

#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoWrLocUErrValue_MASK (0xF000U)
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoWrLocUErrValue_SHIFT (12U)
/*! RxFifoWrLocUErrValue - The first error value captured for the write pointer (DQS side) on the read FIFO associated with data bits [7:4]; */
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoWrLocUErrValue(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoWrLocUErrValue_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCHECKERRVALUES_RxFifoWrLocUErrValue_MASK)
/*! @} */

/*! @name RXFIFOINFO - Data Receive FIFO Pointer Values */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoRdLoc_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoRdLoc_SHIFT (0U)
/*! RxFifoRdLoc - The Mission mode read pointer of the lower-nibble Rx fifo. */
#define DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoRdLoc(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoRdLoc_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoRdLoc_MASK)

#define DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoWrLoc_MASK (0xF0U)
#define DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoWrLoc_SHIFT (4U)
/*! RxFifoWrLoc - The Mission mode write pointer of the lower-nibble Rx fifo. */
#define DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoWrLoc(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoWrLoc_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoWrLoc_MASK)

#define DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoRdLocU_MASK (0xF00U)
#define DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoRdLocU_SHIFT (8U)
/*! RxFifoRdLocU - The Mission mode read pointer of the upper-nibble Rx fifo. */
#define DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoRdLocU(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoRdLocU_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoRdLocU_MASK)

#define DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoWrLocU_MASK (0xF000U)
#define DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoWrLocU_SHIFT (12U)
/*! RxFifoWrLocU - The Mission mode write pointer of the upper-nibble Rx fifo. */
#define DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoWrLocU(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoWrLocU_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOINFO_RxFifoWrLocU_MASK)
/*! @} */

/*! @name RXFIFOVISIBILITY - RX FIFO visibility */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtr_MASK (0x7U)
#define DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtr_SHIFT (0U)
/*! RxFifoRdPtr - If CSR RxFifoRdPtrOVr is set, then this CSR selects the rxfifo entry is visible in CSR. */
#define DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtr_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtr_MASK)

#define DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtrOvr_MASK (0x8U)
#define DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtrOvr_SHIFT (3U)
/*! RxFifoRdPtrOvr - This field is programmable as follows: - 0 : Normal operation - mission mode
 *    read pointer is enabled - 1 : Override - Control of the rx fifo read pointer is ceded to CSR
 *    RxFifoRdPtr.
 */
#define DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtrOvr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtrOvr_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtrOvr_MASK)

#define DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdEn_MASK (0x10U)
#define DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdEn_SHIFT (4U)
/*! RxFifoRdEn - Pulse set 0-->1-->0 this bit to capture the Fifo Contents. */
#define DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdEn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdEn_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdEn_MASK)
/*! @} */

/*! @name RXFIFOCONTENTSDQ3210 - RX FIFO contents, lane[3:0] */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ3210_RxFifoContentsDQ3210_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ3210_RxFifoContentsDQ3210_SHIFT (0U)
/*! RxFifoContentsDQ3210 - A window into the contents of the RxFifo, as controlled by CSR RxFifoVisibility. */
#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ3210_RxFifoContentsDQ3210(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ3210_RxFifoContentsDQ3210_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ3210_RxFifoContentsDQ3210_MASK)
/*! @} */

/*! @name RXFIFOCONTENTSDQ7654 - RX FIFO contents, lane[7:4] */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ7654_RxFifoContentsDQ7654_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ7654_RxFifoContentsDQ7654_SHIFT (0U)
/*! RxFifoContentsDQ7654 - A window into the contents of the RxFifo, as controlled by CSR RxFifoVisibility. */
#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ7654_RxFifoContentsDQ7654(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ7654_RxFifoContentsDQ7654_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ7654_RxFifoContentsDQ7654_MASK)
/*! @} */

/*! @name RXFIFOCONTENTSDBI - RX FIFO contents, dbi */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDBI_RxFifoContentsDBI_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDBI_RxFifoContentsDBI_SHIFT (0U)
/*! RxFifoContentsDBI - A window into the contents of the RxFifo, as controlled by CSR RxFifoVisibility. */
#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDBI_RxFifoContentsDBI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDBI_RxFifoContentsDBI_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDBI_RxFifoContentsDBI_MASK)
/*! @} */

/*! @name TXSLEWRATE_B0_P0 - TX slew rate controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreP_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreP_SHIFT (0U)
/*! TxPreP - This is the 4-bit binary trim for the driver pull up slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreP_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreN_MASK (0xF0U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreN_SHIFT (4U)
/*! TxPreN - 4 bit binary trim for the driver pull down slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreN_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreDrvMode_MASK (0x700U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreDrvMode_SHIFT (8U)
/*! TxPreDrvMode - Controls predrivers to adjust timing of turn-on and turn-off of pull-up and pull-down segments. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreDrvMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreDrvMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreDrvMode_MASK)
/*! @} */

/*! @name TRAININGINCDECDTSMEN_R0 - Enables the any of a group of DTSMs to modify a particular TrainingCounter */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R0_TrainingIncDecDtsmEn_r0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R0_TrainingIncDecDtsmEn_r0_SHIFT (0U)
/*! TrainingIncDecDtsmEn_r0 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R0_TrainingIncDecDtsmEn_r0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R0_TrainingIncDecDtsmEn_r0_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R0_TrainingIncDecDtsmEn_r0_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R0 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R0_RxPBDlyTg0_r0_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R0_RxPBDlyTg0_r0_SHIFT (0U)
/*! RxPBDlyTg0_r0 - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R0_RxPBDlyTg0_r0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R0_RxPBDlyTg0_r0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R0_RxPBDlyTg0_r0_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R0 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R0_RxPBDlyTg1_r0_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R0_RxPBDlyTg1_r0_SHIFT (0U)
/*! RxPBDlyTg1_r0 - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R0_RxPBDlyTg1_r0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R0_RxPBDlyTg1_r0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R0_RxPBDlyTg1_r0_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R0 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R0_RxPBDlyTg2_r0_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R0_RxPBDlyTg2_r0_SHIFT (0U)
/*! RxPBDlyTg2_r0 - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R0_RxPBDlyTg2_r0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R0_RxPBDlyTg2_r0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R0_RxPBDlyTg2_r0_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R0 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R0_RxPBDlyTg3_r0_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R0_RxPBDlyTg3_r0_SHIFT (0U)
/*! RxPBDlyTg3_r0 - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R0_RxPBDlyTg3_r0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R0_RxPBDlyTg3_r0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R0_RxPBDlyTg3_r0_MASK)
/*! @} */

/*! @name RXENDLYTG0_U0_P0 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P0_RxEnDlyTg0_u0_p0_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P0_RxEnDlyTg0_u0_p0_SHIFT (0U)
/*! RxEnDlyTg0_u0_p0 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P0_RxEnDlyTg0_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P0_RxEnDlyTg0_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P0_RxEnDlyTg0_u0_p0_MASK)
/*! @} */

/*! @name RXENDLYTG1_U0_P0 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P0_RxEnDlyTg1_u0_p0_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P0_RxEnDlyTg1_u0_p0_SHIFT (0U)
/*! RxEnDlyTg1_u0_p0 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P0_RxEnDlyTg1_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P0_RxEnDlyTg1_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P0_RxEnDlyTg1_u0_p0_MASK)
/*! @} */

/*! @name RXENDLYTG2_U0_P0 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P0_RxEnDlyTg2_u0_p0_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P0_RxEnDlyTg2_u0_p0_SHIFT (0U)
/*! RxEnDlyTg2_u0_p0 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P0_RxEnDlyTg2_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P0_RxEnDlyTg2_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P0_RxEnDlyTg2_u0_p0_MASK)
/*! @} */

/*! @name RXENDLYTG3_U0_P0 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P0_RxEnDlyTg3_u0_p0_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P0_RxEnDlyTg3_u0_p0_SHIFT (0U)
/*! RxEnDlyTg3_u0_p0 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P0_RxEnDlyTg3_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P0_RxEnDlyTg3_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P0_RxEnDlyTg3_u0_p0_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U0_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P0_RxClkDlyTg0_u0_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P0_RxClkDlyTg0_u0_p0_SHIFT (0U)
/*! RxClkDlyTg0_u0_p0 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P0_RxClkDlyTg0_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P0_RxClkDlyTg0_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P0_RxClkDlyTg0_u0_p0_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U0_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P0_RxClkDlyTg1_u0_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P0_RxClkDlyTg1_u0_p0_SHIFT (0U)
/*! RxClkDlyTg1_u0_p0 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P0_RxClkDlyTg1_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P0_RxClkDlyTg1_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P0_RxClkDlyTg1_u0_p0_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U0_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P0_RxClkDlyTg2_u0_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P0_RxClkDlyTg2_u0_p0_SHIFT (0U)
/*! RxClkDlyTg2_u0_p0 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P0_RxClkDlyTg2_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P0_RxClkDlyTg2_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P0_RxClkDlyTg2_u0_p0_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U0_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P0_RxClkDlyTg3_u0_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P0_RxClkDlyTg3_u0_p0_SHIFT (0U)
/*! RxClkDlyTg3_u0_p0 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P0_RxClkDlyTg3_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P0_RxClkDlyTg3_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P0_RxClkDlyTg3_u0_p0_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U0_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P0_RxClkcDlyTg0_u0_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P0_RxClkcDlyTg0_u0_p0_SHIFT (0U)
/*! RxClkcDlyTg0_u0_p0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P0_RxClkcDlyTg0_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P0_RxClkcDlyTg0_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P0_RxClkcDlyTg0_u0_p0_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U0_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P0_RxClkcDlyTg1_u0_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P0_RxClkcDlyTg1_u0_p0_SHIFT (0U)
/*! RxClkcDlyTg1_u0_p0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P0_RxClkcDlyTg1_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P0_RxClkcDlyTg1_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P0_RxClkcDlyTg1_u0_p0_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U0_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P0_RxClkcDlyTg2_u0_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P0_RxClkcDlyTg2_u0_p0_SHIFT (0U)
/*! RxClkcDlyTg2_u0_p0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P0_RxClkcDlyTg2_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P0_RxClkcDlyTg2_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P0_RxClkcDlyTg2_u0_p0_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U0_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P0_RxClkcDlyTg3_u0_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P0_RxClkcDlyTg3_u0_p0_SHIFT (0U)
/*! RxClkcDlyTg3_u0_p0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P0_RxClkcDlyTg3_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P0_RxClkcDlyTg3_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P0_RxClkcDlyTg3_u0_p0_MASK)
/*! @} */

/*! @name DQ0LNSEL - Maps Phy DQ lane to memory DQ0 */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQ0LNSEL_Dq0LnSel_MASK (0x7U)
#define DWC_DDRPHYA_DBYTE_DQ0LNSEL_Dq0LnSel_SHIFT (0U)
/*! Dq0LnSel - Supports mapping of PHY dq to dram dq within a byte (swizzle). */
#define DWC_DDRPHYA_DBYTE_DQ0LNSEL_Dq0LnSel(x)   (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQ0LNSEL_Dq0LnSel_SHIFT)) & DWC_DDRPHYA_DBYTE_DQ0LNSEL_Dq0LnSel_MASK)
/*! @} */

/*! @name DQ1LNSEL - Maps Phy DQ lane to memory DQ1 */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQ1LNSEL_Dq1LnSel_MASK (0x7U)
#define DWC_DDRPHYA_DBYTE_DQ1LNSEL_Dq1LnSel_SHIFT (0U)
/*! Dq1LnSel - Supports mapping of PHY dq to dram dq within a byte (swizzle). */
#define DWC_DDRPHYA_DBYTE_DQ1LNSEL_Dq1LnSel(x)   (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQ1LNSEL_Dq1LnSel_SHIFT)) & DWC_DDRPHYA_DBYTE_DQ1LNSEL_Dq1LnSel_MASK)
/*! @} */

/*! @name DQ2LNSEL - Maps Phy DQ lane to memory DQ2 */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQ2LNSEL_Dq2LnSel_MASK (0x7U)
#define DWC_DDRPHYA_DBYTE_DQ2LNSEL_Dq2LnSel_SHIFT (0U)
/*! Dq2LnSel - Supports mapping of PHY dq to dram dq within a byte (swizzle). */
#define DWC_DDRPHYA_DBYTE_DQ2LNSEL_Dq2LnSel(x)   (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQ2LNSEL_Dq2LnSel_SHIFT)) & DWC_DDRPHYA_DBYTE_DQ2LNSEL_Dq2LnSel_MASK)
/*! @} */

/*! @name DQ3LNSEL - Maps Phy DQ lane to memory DQ3 */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQ3LNSEL_Dq3LnSel_MASK (0x7U)
#define DWC_DDRPHYA_DBYTE_DQ3LNSEL_Dq3LnSel_SHIFT (0U)
/*! Dq3LnSel - Supports mapping of PHY dq to dram dq within a byte (swizzle). */
#define DWC_DDRPHYA_DBYTE_DQ3LNSEL_Dq3LnSel(x)   (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQ3LNSEL_Dq3LnSel_SHIFT)) & DWC_DDRPHYA_DBYTE_DQ3LNSEL_Dq3LnSel_MASK)
/*! @} */

/*! @name DQ4LNSEL - Maps Phy DQ lane to memory DQ4 */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQ4LNSEL_Dq4LnSel_MASK (0x7U)
#define DWC_DDRPHYA_DBYTE_DQ4LNSEL_Dq4LnSel_SHIFT (0U)
/*! Dq4LnSel - Supports mapping of PHY dq to dram dq within a byte (swizzle). */
#define DWC_DDRPHYA_DBYTE_DQ4LNSEL_Dq4LnSel(x)   (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQ4LNSEL_Dq4LnSel_SHIFT)) & DWC_DDRPHYA_DBYTE_DQ4LNSEL_Dq4LnSel_MASK)
/*! @} */

/*! @name DQ5LNSEL - Maps Phy DQ lane to memory DQ5 */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQ5LNSEL_Dq5LnSel_MASK (0x7U)
#define DWC_DDRPHYA_DBYTE_DQ5LNSEL_Dq5LnSel_SHIFT (0U)
/*! Dq5LnSel - Supports mapping of PHY dq to dram dq within a byte (swizzle). */
#define DWC_DDRPHYA_DBYTE_DQ5LNSEL_Dq5LnSel(x)   (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQ5LNSEL_Dq5LnSel_SHIFT)) & DWC_DDRPHYA_DBYTE_DQ5LNSEL_Dq5LnSel_MASK)
/*! @} */

/*! @name DQ6LNSEL - Maps Phy DQ lane to memory DQ6 */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQ6LNSEL_Dq6LnSel_MASK (0x7U)
#define DWC_DDRPHYA_DBYTE_DQ6LNSEL_Dq6LnSel_SHIFT (0U)
/*! Dq6LnSel - Supports mapping of PHY dq to dram dq within a byte (swizzle). */
#define DWC_DDRPHYA_DBYTE_DQ6LNSEL_Dq6LnSel(x)   (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQ6LNSEL_Dq6LnSel_SHIFT)) & DWC_DDRPHYA_DBYTE_DQ6LNSEL_Dq6LnSel_MASK)
/*! @} */

/*! @name DQ7LNSEL - Maps Phy DQ lane to memory DQ7 */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQ7LNSEL_Dq7LnSel_MASK (0x7U)
#define DWC_DDRPHYA_DBYTE_DQ7LNSEL_Dq7LnSel_SHIFT (0U)
/*! Dq7LnSel - Supports mapping of PHY dq to dram dq within a byte (swizzle). */
#define DWC_DDRPHYA_DBYTE_DQ7LNSEL_Dq7LnSel(x)   (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQ7LNSEL_Dq7LnSel_SHIFT)) & DWC_DDRPHYA_DBYTE_DQ7LNSEL_Dq7LnSel_MASK)
/*! @} */

/*! @name PPTCTLSTATIC - Controls for the PPT of tDQS2DQ */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_PPTCTLSTATIC_RFU_PptCtlStatic_MASK (0xFFFU)
#define DWC_DDRPHYA_DBYTE_PPTCTLSTATIC_RFU_PptCtlStatic_SHIFT (0U)
/*! RFU_PptCtlStatic - RFU_PptCtlStatic */
#define DWC_DDRPHYA_DBYTE_PPTCTLSTATIC_RFU_PptCtlStatic(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_PPTCTLSTATIC_RFU_PptCtlStatic_SHIFT)) & DWC_DDRPHYA_DBYTE_PPTCTLSTATIC_RFU_PptCtlStatic_MASK)
/*! @} */

/*! @name PPTCTLDYN - Controls parameters for the DRAM drift compensation logic */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_PPTCTLDYN_RFU_PptCtlDyn_MASK (0x3U)
#define DWC_DDRPHYA_DBYTE_PPTCTLDYN_RFU_PptCtlDyn_SHIFT (0U)
/*! RFU_PptCtlDyn - RFU_PptCtlDyn */
#define DWC_DDRPHYA_DBYTE_PPTCTLDYN_RFU_PptCtlDyn(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_PPTCTLDYN_RFU_PptCtlDyn_SHIFT)) & DWC_DDRPHYA_DBYTE_PPTCTLDYN_RFU_PptCtlDyn_MASK)
/*! @} */

/*! @name PPTINFO - LPDDR4 PPT information */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_PPTINFO_PptInfo_MASK   (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_PPTINFO_PptInfo_SHIFT  (0U)
/*! PptInfo - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_PPTINFO_PptInfo(x)     (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_PPTINFO_PptInfo_SHIFT)) & DWC_DDRPHYA_DBYTE_PPTINFO_PptInfo_MASK)
/*! @} */

/*! @name PPTRXENEVNT - LPDDR4 PPT RxEn control for initialization and for terminating */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_PPTRXENEVNT_RFU_PptRxEnEvnt_MASK (0x3U)
#define DWC_DDRPHYA_DBYTE_PPTRXENEVNT_RFU_PptRxEnEvnt_SHIFT (0U)
/*! RFU_PptRxEnEvnt - RFU_PptRxEnEvnt */
#define DWC_DDRPHYA_DBYTE_PPTRXENEVNT_RFU_PptRxEnEvnt(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_PPTRXENEVNT_RFU_PptRxEnEvnt_SHIFT)) & DWC_DDRPHYA_DBYTE_PPTRXENEVNT_RFU_PptRxEnEvnt_MASK)
/*! @} */

/*! @name PPTDQSCNTINVTRNTG0_P0 - DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P0_PptDqsCntInvTrnTg0_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P0_PptDqsCntInvTrnTg0_p0_SHIFT (0U)
/*! PptDqsCntInvTrnTg0_p0 - Programmed by PHY training firmware to support LPDDR3/LPDDR4 DRAM drift compensation. */
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P0_PptDqsCntInvTrnTg0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P0_PptDqsCntInvTrnTg0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P0_PptDqsCntInvTrnTg0_p0_MASK)
/*! @} */

/*! @name PPTDQSCNTINVTRNTG1_P0 - DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P0_PptDqsCntInvTrnTg1_p0_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P0_PptDqsCntInvTrnTg1_p0_SHIFT (0U)
/*! PptDqsCntInvTrnTg1_p0 - Programmed by PHY training firmware to support LPDDR3/LPDDR4 DRAM drift compensation. */
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P0_PptDqsCntInvTrnTg1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P0_PptDqsCntInvTrnTg1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P0_PptDqsCntInvTrnTg1_p0_MASK)
/*! @} */

/*! @name DTSMBLANKINGCTRL - Per Dbyte DTSM blanking time. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DTSMBLANKINGCTRL_RFU_DtsmBlankingCtrl_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_DTSMBLANKINGCTRL_RFU_DtsmBlankingCtrl_SHIFT (0U)
/*! RFU_DtsmBlankingCtrl - RFU_DtsmBlankingCtrl */
#define DWC_DDRPHYA_DBYTE_DTSMBLANKINGCTRL_RFU_DtsmBlankingCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DTSMBLANKINGCTRL_RFU_DtsmBlankingCtrl_SHIFT)) & DWC_DDRPHYA_DBYTE_DTSMBLANKINGCTRL_RFU_DtsmBlankingCtrl_MASK)
/*! @} */

/*! @name TSM0_I0 - Per DTSM configuration and control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM0_I0_RFU_Tsm0_i0_MASK (0x3FFFU)
#define DWC_DDRPHYA_DBYTE_TSM0_I0_RFU_Tsm0_i0_SHIFT (0U)
/*! RFU_Tsm0_i0 - RFU_Tsm0_i0 */
#define DWC_DDRPHYA_DBYTE_TSM0_I0_RFU_Tsm0_i0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM0_I0_RFU_Tsm0_i0_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM0_I0_RFU_Tsm0_i0_MASK)
/*! @} */

/*! @name TSM1_I0 - Per DTSM cumulative error count */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM1_I0_RFU_Tsm1_i0_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TSM1_I0_RFU_Tsm1_i0_SHIFT (0U)
/*! RFU_Tsm1_i0 - RFU_Tsm1_i0 */
#define DWC_DDRPHYA_DBYTE_TSM1_I0_RFU_Tsm1_i0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM1_I0_RFU_Tsm1_i0_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM1_I0_RFU_Tsm1_i0_MASK)
/*! @} */

/*! @name TSM2_I0 - Per DTSM control for disabling error checking */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM2_I0_RFU_Tsm2_i0_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_TSM2_I0_RFU_Tsm2_i0_SHIFT (0U)
/*! RFU_Tsm2_i0 - RFU_Tsm2_i0 */
#define DWC_DDRPHYA_DBYTE_TSM2_I0_RFU_Tsm2_i0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM2_I0_RFU_Tsm2_i0_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM2_I0_RFU_Tsm2_i0_MASK)
/*! @} */

/*! @name TSM3 - Per DBYTE module DTSM clear error controls. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM3_RFU_Tsm3_MASK     (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TSM3_RFU_Tsm3_SHIFT    (0U)
/*! RFU_Tsm3 - RFU_Tsm3 */
#define DWC_DDRPHYA_DBYTE_TSM3_RFU_Tsm3(x)       (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM3_RFU_Tsm3_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM3_RFU_Tsm3_MASK)
/*! @} */

/*! @name TXCHKDATASELECTS - Selects to control the Tx and Chk bus selection on a byte basis */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXCHKDATASELECTS_RFU_TxChkDataSelects_MASK (0x3U)
#define DWC_DDRPHYA_DBYTE_TXCHKDATASELECTS_RFU_TxChkDataSelects_SHIFT (0U)
/*! RFU_TxChkDataSelects - RFU_TxChkDataSelects */
#define DWC_DDRPHYA_DBYTE_TXCHKDATASELECTS_RFU_TxChkDataSelects(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXCHKDATASELECTS_RFU_TxChkDataSelects_SHIFT)) & DWC_DDRPHYA_DBYTE_TXCHKDATASELECTS_RFU_TxChkDataSelects_MASK)
/*! @} */

/*! @name DTSMUPTHLDXINGIND - Indicator that latches DTSM upper threshold crossing events */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DTSMUPTHLDXINGIND_DtsmUpThldXingInd_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_DTSMUPTHLDXINGIND_DtsmUpThldXingInd_SHIFT (0U)
/*! DtsmUpThldXingInd - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_DTSMUPTHLDXINGIND_DtsmUpThldXingInd(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DTSMUPTHLDXINGIND_DtsmUpThldXingInd_SHIFT)) & DWC_DDRPHYA_DBYTE_DTSMUPTHLDXINGIND_DtsmUpThldXingInd_MASK)
/*! @} */

/*! @name DTSMLOTHLDXINGIND - Indicator that latches DTSM lower threshold crossing events */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DTSMLOTHLDXINGIND_DtsmLoThldXingInd_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_DTSMLOTHLDXINGIND_DtsmLoThldXingInd_SHIFT (0U)
/*! DtsmLoThldXingInd - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_DTSMLOTHLDXINGIND_DtsmLoThldXingInd(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DTSMLOTHLDXINGIND_DtsmLoThldXingInd_SHIFT)) & DWC_DDRPHYA_DBYTE_DTSMLOTHLDXINGIND_DtsmLoThldXingInd_MASK)
/*! @} */

/*! @name DBYTEALLDTSMCTRL0 - Ctrl that inhibits an enabled DTSM from participating in training. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL0_RFU_DbyteAllDtsmCtrl0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL0_RFU_DbyteAllDtsmCtrl0_SHIFT (0U)
/*! RFU_DbyteAllDtsmCtrl0 - RFU_DbyteAllDtsmCtrl0 */
#define DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL0_RFU_DbyteAllDtsmCtrl0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL0_RFU_DbyteAllDtsmCtrl0_SHIFT)) & DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL0_RFU_DbyteAllDtsmCtrl0_MASK)
/*! @} */

/*! @name DBYTEALLDTSMCTRL1 - Ctrl that gates the increment signal internal to the DTSM. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL1_RFU_DbyteAllDtsmCtrl1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL1_RFU_DbyteAllDtsmCtrl1_SHIFT (0U)
/*! RFU_DbyteAllDtsmCtrl1 - RFU_DbyteAllDtsmCtrl1 */
#define DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL1_RFU_DbyteAllDtsmCtrl1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL1_RFU_DbyteAllDtsmCtrl1_SHIFT)) & DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL1_RFU_DbyteAllDtsmCtrl1_MASK)
/*! @} */

/*! @name DBYTEALLDTSMCTRL2 - Ctrl that gates teh decrement signal internal to the DTSM. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL2_RFU_DbyteAllDtsmCtrl2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL2_RFU_DbyteAllDtsmCtrl2_SHIFT (0U)
/*! RFU_DbyteAllDtsmCtrl2 - RFU_DbyteAllDtsmCtrl2 */
#define DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL2_RFU_DbyteAllDtsmCtrl2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL2_RFU_DbyteAllDtsmCtrl2_SHIFT)) & DWC_DDRPHYA_DBYTE_DBYTEALLDTSMCTRL2_RFU_DbyteAllDtsmCtrl2_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R0_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P0_TxDqDlyTg0_r0_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P0_TxDqDlyTg0_r0_p0_SHIFT (0U)
/*! TxDqDlyTg0_r0_p0 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P0_TxDqDlyTg0_r0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P0_TxDqDlyTg0_r0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P0_TxDqDlyTg0_r0_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R0_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P0_TxDqDlyTg1_r0_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P0_TxDqDlyTg1_r0_p0_SHIFT (0U)
/*! TxDqDlyTg1_r0_p0 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P0_TxDqDlyTg1_r0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P0_TxDqDlyTg1_r0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P0_TxDqDlyTg1_r0_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R0_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P0_TxDqDlyTg2_r0_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P0_TxDqDlyTg2_r0_p0_SHIFT (0U)
/*! TxDqDlyTg2_r0_p0 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P0_TxDqDlyTg2_r0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P0_TxDqDlyTg2_r0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P0_TxDqDlyTg2_r0_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R0_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P0_TxDqDlyTg3_r0_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P0_TxDqDlyTg3_r0_p0_SHIFT (0U)
/*! TxDqDlyTg3_r0_p0 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P0_TxDqDlyTg3_r0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P0_TxDqDlyTg3_r0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P0_TxDqDlyTg3_r0_p0_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U0_P0 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P0_TxDqsDlyTg0_u0_p0_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P0_TxDqsDlyTg0_u0_p0_SHIFT (0U)
/*! TxDqsDlyTg0_u0_p0 - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P0_TxDqsDlyTg0_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P0_TxDqsDlyTg0_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P0_TxDqsDlyTg0_u0_p0_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U0_P0 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P0_TxDqsDlyTg1_u0_p0_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P0_TxDqsDlyTg1_u0_p0_SHIFT (0U)
/*! TxDqsDlyTg1_u0_p0 - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P0_TxDqsDlyTg1_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P0_TxDqsDlyTg1_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P0_TxDqsDlyTg1_u0_p0_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U0_P0 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P0_TxDqsDlyTg2_u0_p0_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P0_TxDqsDlyTg2_u0_p0_SHIFT (0U)
/*! TxDqsDlyTg2_u0_p0 - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P0_TxDqsDlyTg2_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P0_TxDqsDlyTg2_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P0_TxDqsDlyTg2_u0_p0_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U0_P0 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P0_TxDqsDlyTg3_u0_p0_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P0_TxDqsDlyTg3_u0_p0_SHIFT (0U)
/*! TxDqsDlyTg3_u0_p0 - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P0_TxDqsDlyTg3_u0_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P0_TxDqsDlyTg3_u0_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P0_TxDqsDlyTg3_u0_p0_MASK)
/*! @} */

/*! @name DXLCDLSTATUS - Debug status of the DBYTE LCDL */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlFineSnapVal_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlFineSnapVal_SHIFT (0U)
/*! DxLcdlFineSnapVal - Value of the LCDL 1UI estimate code, latched by pulse on csr LcdlFineSnap while csr LcdlTstEnable=1. */
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlFineSnapVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlFineSnapVal_SHIFT)) & DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlFineSnapVal_MASK)

#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlPhdSnapVal_MASK (0x400U)
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlPhdSnapVal_SHIFT (10U)
/*! DxLcdlPhdSnapVal - Value of the LCDL phase-detector output, latched by pulse on csr LcdlFineSnap. */
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlPhdSnapVal(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlPhdSnapVal_SHIFT)) & DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlPhdSnapVal_MASK)

#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyLock_MASK (0x800U)
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyLock_SHIFT (11U)
/*! DxLcdlStickyLock - Latched value of whether the LCDL ever achieved lock after the assertion of LcdlTstEnable. */
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyLock(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyLock_SHIFT)) & DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyLock_MASK)

#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyUnlock_MASK (0x1000U)
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyUnlock_SHIFT (12U)
/*! DxLcdlStickyUnlock - Latched value of whether the LCDL ever lost lock after the assertion of LcdlTstEnable. */
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyUnlock(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyUnlock_SHIFT)) & DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyUnlock_MASK)

#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlLiveLock_MASK (0x2000U)
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlLiveLock_SHIFT (13U)
/*! DxLcdlLiveLock - Present value of whether the LCDL is locked. */
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlLiveLock(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlLiveLock_SHIFT)) & DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlLiveLock_MASK)
/*! @} */

/*! @name VREFDAC1_R1 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R1_VrefDAC1_r1_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R1_VrefDAC1_r1_SHIFT (0U)
/*! VrefDAC1_r1 - VrefDAC1_r1 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R1_VrefDAC1_r1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R1_VrefDAC1_r1_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R1_VrefDAC1_r1_MASK)
/*! @} */

/*! @name TRAININGCNTR_R1 - Training counter. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R1_RFU_TrainingCntr_r1_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R1_RFU_TrainingCntr_r1_SHIFT (0U)
/*! RFU_TrainingCntr_r1 - RFU_TrainingCntr_r1 */
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R1_RFU_TrainingCntr_r1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGCNTR_R1_RFU_TrainingCntr_r1_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGCNTR_R1_RFU_TrainingCntr_r1_MASK)
/*! @} */

/*! @name VREFDAC0_R1 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R1_VrefDAC0_r1_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R1_VrefDAC0_r1_SHIFT (0U)
/*! VrefDAC0_r1 - VrefDAC0_r1 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R1_VrefDAC0_r1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R1_VrefDAC0_r1_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R1_VrefDAC0_r1_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL0_B1_P0 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqN_MASK)
/*! @} */

/*! @name DQDQSRCVCNTRL_B1_P0 - Dq/Dqs receiver control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_SelAnalogVref_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_SelAnalogVref_SHIFT (0U)
/*! SelAnalogVref - Setting this signal high will force the local per-bit VREF generator to pass the global VREFA to the samplers. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_SelAnalogVref(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_SelAnalogVref_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_SelAnalogVref_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_ExtVrefRange_MASK (0x2U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_ExtVrefRange_SHIFT (1U)
/*! ExtVrefRange - Extends the range available in the local per-bit VREF generator. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_ExtVrefRange(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_ExtVrefRange_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_ExtVrefRange_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_DfeCtrl_MASK (0xCU)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_DfeCtrl_SHIFT (2U)
/*! DfeCtrl - This field is programmable as follows - 00 - DFE off - 01 - DFE on - 10 - Train DFE0
 *    Amplifier - 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
 *    should not be overridden.
 */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_DfeCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_DfeCtrl_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_DfeCtrl_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_MajorModeDbyte_MASK (0x70U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_MajorModeDbyte_SHIFT (4U)
/*! MajorModeDbyte - Selects the major mode of operation for the receiver. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_MajorModeDbyte(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_MajorModeDbyte_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_MajorModeDbyte_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_GainCurrAdj_MASK (0xF80U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_GainCurrAdj_SHIFT (7U)
/*! GainCurrAdj - Adjust gain current of RX amplifier stage. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_GainCurrAdj(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_GainCurrAdj_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P0_GainCurrAdj_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL1_B1_P0 - TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqP_SHIFT (0U)
/*! DrvStrenFSDqP - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B1_P0 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQLoDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQLoDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQLoDqN_MASK)
/*! @} */

/*! @name TXODTDRVSTREN_B1_P0 - TX ODT driver strength control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P0_ODTStrenP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P0_ODTStrenP_SHIFT (0U)
/*! ODTStrenP - Selects the ODT pull-up impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P0_ODTStrenP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P0_ODTStrenP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P0_ODTStrenP_MASK)

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P0_ODTStrenN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P0_ODTStrenN_SHIFT (6U)
/*! ODTStrenN - Selects the ODT pull-down impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P0_ODTStrenN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P0_ODTStrenN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P0_ODTStrenN_MASK)
/*! @} */

/*! @name TXSLEWRATE_B1_P0 - TX slew rate controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreP_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreP_SHIFT (0U)
/*! TxPreP - This is the 4-bit binary trim for the driver pull up slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreP_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreN_MASK (0xF0U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreN_SHIFT (4U)
/*! TxPreN - 4 bit binary trim for the driver pull down slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreN_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreDrvMode_MASK (0x700U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreDrvMode_SHIFT (8U)
/*! TxPreDrvMode - Controls predrivers to adjust timing of turn-on and turn-off of pull-up and pull-down segments. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreDrvMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreDrvMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P0_TxPreDrvMode_MASK)
/*! @} */

/*! @name TRAININGINCDECDTSMEN_R1 - Enables the any of a group of DTSMs to modify a particular TrainingCounter */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R1_TrainingIncDecDtsmEn_r1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R1_TrainingIncDecDtsmEn_r1_SHIFT (0U)
/*! TrainingIncDecDtsmEn_r1 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R1_TrainingIncDecDtsmEn_r1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R1_TrainingIncDecDtsmEn_r1_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R1_TrainingIncDecDtsmEn_r1_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R1 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R1_RxPBDlyTg0_r1_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R1_RxPBDlyTg0_r1_SHIFT (0U)
/*! RxPBDlyTg0_r1 - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R1_RxPBDlyTg0_r1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R1_RxPBDlyTg0_r1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R1_RxPBDlyTg0_r1_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R1 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R1_RxPBDlyTg1_r1_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R1_RxPBDlyTg1_r1_SHIFT (0U)
/*! RxPBDlyTg1_r1 - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R1_RxPBDlyTg1_r1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R1_RxPBDlyTg1_r1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R1_RxPBDlyTg1_r1_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R1 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R1_RxPBDlyTg2_r1_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R1_RxPBDlyTg2_r1_SHIFT (0U)
/*! RxPBDlyTg2_r1 - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R1_RxPBDlyTg2_r1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R1_RxPBDlyTg2_r1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R1_RxPBDlyTg2_r1_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R1 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R1_RxPBDlyTg3_r1_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R1_RxPBDlyTg3_r1_SHIFT (0U)
/*! RxPBDlyTg3_r1 - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R1_RxPBDlyTg3_r1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R1_RxPBDlyTg3_r1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R1_RxPBDlyTg3_r1_MASK)
/*! @} */

/*! @name RXENDLYTG0_U1_P0 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P0_RxEnDlyTg0_u1_p0_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P0_RxEnDlyTg0_u1_p0_SHIFT (0U)
/*! RxEnDlyTg0_u1_p0 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P0_RxEnDlyTg0_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P0_RxEnDlyTg0_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P0_RxEnDlyTg0_u1_p0_MASK)
/*! @} */

/*! @name RXENDLYTG1_U1_P0 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P0_RxEnDlyTg1_u1_p0_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P0_RxEnDlyTg1_u1_p0_SHIFT (0U)
/*! RxEnDlyTg1_u1_p0 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P0_RxEnDlyTg1_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P0_RxEnDlyTg1_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P0_RxEnDlyTg1_u1_p0_MASK)
/*! @} */

/*! @name RXENDLYTG2_U1_P0 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P0_RxEnDlyTg2_u1_p0_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P0_RxEnDlyTg2_u1_p0_SHIFT (0U)
/*! RxEnDlyTg2_u1_p0 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P0_RxEnDlyTg2_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P0_RxEnDlyTg2_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P0_RxEnDlyTg2_u1_p0_MASK)
/*! @} */

/*! @name RXENDLYTG3_U1_P0 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P0_RxEnDlyTg3_u1_p0_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P0_RxEnDlyTg3_u1_p0_SHIFT (0U)
/*! RxEnDlyTg3_u1_p0 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P0_RxEnDlyTg3_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P0_RxEnDlyTg3_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P0_RxEnDlyTg3_u1_p0_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U1_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P0_RxClkDlyTg0_u1_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P0_RxClkDlyTg0_u1_p0_SHIFT (0U)
/*! RxClkDlyTg0_u1_p0 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P0_RxClkDlyTg0_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P0_RxClkDlyTg0_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P0_RxClkDlyTg0_u1_p0_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U1_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P0_RxClkDlyTg1_u1_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P0_RxClkDlyTg1_u1_p0_SHIFT (0U)
/*! RxClkDlyTg1_u1_p0 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P0_RxClkDlyTg1_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P0_RxClkDlyTg1_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P0_RxClkDlyTg1_u1_p0_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U1_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P0_RxClkDlyTg2_u1_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P0_RxClkDlyTg2_u1_p0_SHIFT (0U)
/*! RxClkDlyTg2_u1_p0 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P0_RxClkDlyTg2_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P0_RxClkDlyTg2_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P0_RxClkDlyTg2_u1_p0_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U1_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P0_RxClkDlyTg3_u1_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P0_RxClkDlyTg3_u1_p0_SHIFT (0U)
/*! RxClkDlyTg3_u1_p0 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P0_RxClkDlyTg3_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P0_RxClkDlyTg3_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P0_RxClkDlyTg3_u1_p0_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U1_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P0_RxClkcDlyTg0_u1_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P0_RxClkcDlyTg0_u1_p0_SHIFT (0U)
/*! RxClkcDlyTg0_u1_p0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P0_RxClkcDlyTg0_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P0_RxClkcDlyTg0_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P0_RxClkcDlyTg0_u1_p0_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U1_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P0_RxClkcDlyTg1_u1_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P0_RxClkcDlyTg1_u1_p0_SHIFT (0U)
/*! RxClkcDlyTg1_u1_p0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P0_RxClkcDlyTg1_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P0_RxClkcDlyTg1_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P0_RxClkcDlyTg1_u1_p0_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U1_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P0_RxClkcDlyTg2_u1_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P0_RxClkcDlyTg2_u1_p0_SHIFT (0U)
/*! RxClkcDlyTg2_u1_p0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P0_RxClkcDlyTg2_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P0_RxClkcDlyTg2_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P0_RxClkcDlyTg2_u1_p0_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U1_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P0_RxClkcDlyTg3_u1_p0_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P0_RxClkcDlyTg3_u1_p0_SHIFT (0U)
/*! RxClkcDlyTg3_u1_p0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P0_RxClkcDlyTg3_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P0_RxClkcDlyTg3_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P0_RxClkcDlyTg3_u1_p0_MASK)
/*! @} */

/*! @name TSM0_I1 - Per DTSM configuration and control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM0_I1_RFU_Tsm0_i1_MASK (0x3FFFU)
#define DWC_DDRPHYA_DBYTE_TSM0_I1_RFU_Tsm0_i1_SHIFT (0U)
/*! RFU_Tsm0_i1 - RFU_Tsm0_i1 */
#define DWC_DDRPHYA_DBYTE_TSM0_I1_RFU_Tsm0_i1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM0_I1_RFU_Tsm0_i1_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM0_I1_RFU_Tsm0_i1_MASK)
/*! @} */

/*! @name TSM1_I1 - Per DTSM cumulative error count */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM1_I1_RFU_Tsm1_i1_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TSM1_I1_RFU_Tsm1_i1_SHIFT (0U)
/*! RFU_Tsm1_i1 - RFU_Tsm1_i1 */
#define DWC_DDRPHYA_DBYTE_TSM1_I1_RFU_Tsm1_i1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM1_I1_RFU_Tsm1_i1_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM1_I1_RFU_Tsm1_i1_MASK)
/*! @} */

/*! @name TSM2_I1 - Per DTSM control for disabling error checking */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM2_I1_RFU_Tsm2_i1_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_TSM2_I1_RFU_Tsm2_i1_SHIFT (0U)
/*! RFU_Tsm2_i1 - RFU_Tsm2_i1 */
#define DWC_DDRPHYA_DBYTE_TSM2_I1_RFU_Tsm2_i1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM2_I1_RFU_Tsm2_i1_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM2_I1_RFU_Tsm2_i1_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R1_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P0_TxDqDlyTg0_r1_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P0_TxDqDlyTg0_r1_p0_SHIFT (0U)
/*! TxDqDlyTg0_r1_p0 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P0_TxDqDlyTg0_r1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P0_TxDqDlyTg0_r1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P0_TxDqDlyTg0_r1_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R1_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P0_TxDqDlyTg1_r1_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P0_TxDqDlyTg1_r1_p0_SHIFT (0U)
/*! TxDqDlyTg1_r1_p0 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P0_TxDqDlyTg1_r1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P0_TxDqDlyTg1_r1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P0_TxDqDlyTg1_r1_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R1_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P0_TxDqDlyTg2_r1_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P0_TxDqDlyTg2_r1_p0_SHIFT (0U)
/*! TxDqDlyTg2_r1_p0 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P0_TxDqDlyTg2_r1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P0_TxDqDlyTg2_r1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P0_TxDqDlyTg2_r1_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R1_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P0_TxDqDlyTg3_r1_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P0_TxDqDlyTg3_r1_p0_SHIFT (0U)
/*! TxDqDlyTg3_r1_p0 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P0_TxDqDlyTg3_r1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P0_TxDqDlyTg3_r1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P0_TxDqDlyTg3_r1_p0_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U1_P0 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P0_TxDqsDlyTg0_u1_p0_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P0_TxDqsDlyTg0_u1_p0_SHIFT (0U)
/*! TxDqsDlyTg0_u1_p0 - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P0_TxDqsDlyTg0_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P0_TxDqsDlyTg0_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P0_TxDqsDlyTg0_u1_p0_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U1_P0 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P0_TxDqsDlyTg1_u1_p0_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P0_TxDqsDlyTg1_u1_p0_SHIFT (0U)
/*! TxDqsDlyTg1_u1_p0 - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P0_TxDqsDlyTg1_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P0_TxDqsDlyTg1_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P0_TxDqsDlyTg1_u1_p0_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U1_P0 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P0_TxDqsDlyTg2_u1_p0_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P0_TxDqsDlyTg2_u1_p0_SHIFT (0U)
/*! TxDqsDlyTg2_u1_p0 - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P0_TxDqsDlyTg2_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P0_TxDqsDlyTg2_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P0_TxDqsDlyTg2_u1_p0_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U1_P0 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P0_TxDqsDlyTg3_u1_p0_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P0_TxDqsDlyTg3_u1_p0_SHIFT (0U)
/*! TxDqsDlyTg3_u1_p0 - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P0_TxDqsDlyTg3_u1_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P0_TxDqsDlyTg3_u1_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P0_TxDqsDlyTg3_u1_p0_MASK)
/*! @} */

/*! @name VREFDAC1_R2 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R2_VrefDAC1_r2_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R2_VrefDAC1_r2_SHIFT (0U)
/*! VrefDAC1_r2 - VrefDAC1_r2 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R2_VrefDAC1_r2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R2_VrefDAC1_r2_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R2_VrefDAC1_r2_MASK)
/*! @} */

/*! @name TRAININGCNTR_R2 - Training counter. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R2_RFU_TrainingCntr_r2_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R2_RFU_TrainingCntr_r2_SHIFT (0U)
/*! RFU_TrainingCntr_r2 - RFU_TrainingCntr_r2 */
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R2_RFU_TrainingCntr_r2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGCNTR_R2_RFU_TrainingCntr_r2_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGCNTR_R2_RFU_TrainingCntr_r2_MASK)
/*! @} */

/*! @name VREFDAC0_R2 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R2_VrefDAC0_r2_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R2_VrefDAC0_r2_SHIFT (0U)
/*! VrefDAC0_r2 - VrefDAC0_r2 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R2_VrefDAC0_r2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R2_VrefDAC0_r2_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R2_VrefDAC0_r2_MASK)
/*! @} */

/*! @name TRAININGINCDECDTSMEN_R2 - Enables the any of a group of DTSMs to modify a particular TrainingCounter */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R2_TrainingIncDecDtsmEn_r2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R2_TrainingIncDecDtsmEn_r2_SHIFT (0U)
/*! TrainingIncDecDtsmEn_r2 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R2_TrainingIncDecDtsmEn_r2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R2_TrainingIncDecDtsmEn_r2_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R2_TrainingIncDecDtsmEn_r2_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R2 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R2_RxPBDlyTg0_r2_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R2_RxPBDlyTg0_r2_SHIFT (0U)
/*! RxPBDlyTg0_r2 - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R2_RxPBDlyTg0_r2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R2_RxPBDlyTg0_r2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R2_RxPBDlyTg0_r2_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R2 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R2_RxPBDlyTg1_r2_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R2_RxPBDlyTg1_r2_SHIFT (0U)
/*! RxPBDlyTg1_r2 - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R2_RxPBDlyTg1_r2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R2_RxPBDlyTg1_r2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R2_RxPBDlyTg1_r2_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R2 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R2_RxPBDlyTg2_r2_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R2_RxPBDlyTg2_r2_SHIFT (0U)
/*! RxPBDlyTg2_r2 - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R2_RxPBDlyTg2_r2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R2_RxPBDlyTg2_r2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R2_RxPBDlyTg2_r2_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R2 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R2_RxPBDlyTg3_r2_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R2_RxPBDlyTg3_r2_SHIFT (0U)
/*! RxPBDlyTg3_r2 - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R2_RxPBDlyTg3_r2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R2_RxPBDlyTg3_r2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R2_RxPBDlyTg3_r2_MASK)
/*! @} */

/*! @name TSM0_I2 - Per DTSM configuration and control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM0_I2_RFU_Tsm0_i2_MASK (0x3FFFU)
#define DWC_DDRPHYA_DBYTE_TSM0_I2_RFU_Tsm0_i2_SHIFT (0U)
/*! RFU_Tsm0_i2 - RFU_Tsm0_i2 */
#define DWC_DDRPHYA_DBYTE_TSM0_I2_RFU_Tsm0_i2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM0_I2_RFU_Tsm0_i2_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM0_I2_RFU_Tsm0_i2_MASK)
/*! @} */

/*! @name TSM1_I2 - Per DTSM cumulative error count */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM1_I2_RFU_Tsm1_i2_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TSM1_I2_RFU_Tsm1_i2_SHIFT (0U)
/*! RFU_Tsm1_i2 - RFU_Tsm1_i2 */
#define DWC_DDRPHYA_DBYTE_TSM1_I2_RFU_Tsm1_i2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM1_I2_RFU_Tsm1_i2_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM1_I2_RFU_Tsm1_i2_MASK)
/*! @} */

/*! @name TSM2_I2 - Per DTSM control for disabling error checking */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM2_I2_RFU_Tsm2_i2_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_TSM2_I2_RFU_Tsm2_i2_SHIFT (0U)
/*! RFU_Tsm2_i2 - RFU_Tsm2_i2 */
#define DWC_DDRPHYA_DBYTE_TSM2_I2_RFU_Tsm2_i2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM2_I2_RFU_Tsm2_i2_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM2_I2_RFU_Tsm2_i2_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R2_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P0_TxDqDlyTg0_r2_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P0_TxDqDlyTg0_r2_p0_SHIFT (0U)
/*! TxDqDlyTg0_r2_p0 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P0_TxDqDlyTg0_r2_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P0_TxDqDlyTg0_r2_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P0_TxDqDlyTg0_r2_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R2_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P0_TxDqDlyTg1_r2_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P0_TxDqDlyTg1_r2_p0_SHIFT (0U)
/*! TxDqDlyTg1_r2_p0 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P0_TxDqDlyTg1_r2_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P0_TxDqDlyTg1_r2_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P0_TxDqDlyTg1_r2_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R2_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P0_TxDqDlyTg2_r2_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P0_TxDqDlyTg2_r2_p0_SHIFT (0U)
/*! TxDqDlyTg2_r2_p0 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P0_TxDqDlyTg2_r2_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P0_TxDqDlyTg2_r2_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P0_TxDqDlyTg2_r2_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R2_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P0_TxDqDlyTg3_r2_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P0_TxDqDlyTg3_r2_p0_SHIFT (0U)
/*! TxDqDlyTg3_r2_p0 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P0_TxDqDlyTg3_r2_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P0_TxDqDlyTg3_r2_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P0_TxDqDlyTg3_r2_p0_MASK)
/*! @} */

/*! @name VREFDAC1_R3 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R3_VrefDAC1_r3_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R3_VrefDAC1_r3_SHIFT (0U)
/*! VrefDAC1_r3 - VrefDAC1_r3 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R3_VrefDAC1_r3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R3_VrefDAC1_r3_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R3_VrefDAC1_r3_MASK)
/*! @} */

/*! @name TRAININGCNTR_R3 - Training counter. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R3_RFU_TrainingCntr_r3_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R3_RFU_TrainingCntr_r3_SHIFT (0U)
/*! RFU_TrainingCntr_r3 - RFU_TrainingCntr_r3 */
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R3_RFU_TrainingCntr_r3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGCNTR_R3_RFU_TrainingCntr_r3_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGCNTR_R3_RFU_TrainingCntr_r3_MASK)
/*! @} */

/*! @name VREFDAC0_R3 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R3_VrefDAC0_r3_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R3_VrefDAC0_r3_SHIFT (0U)
/*! VrefDAC0_r3 - VrefDAC0_r3 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R3_VrefDAC0_r3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R3_VrefDAC0_r3_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R3_VrefDAC0_r3_MASK)
/*! @} */

/*! @name TRAININGINCDECDTSMEN_R3 - Enables the any of a group of DTSMs to modify a particular TrainingCounter */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R3_TrainingIncDecDtsmEn_r3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R3_TrainingIncDecDtsmEn_r3_SHIFT (0U)
/*! TrainingIncDecDtsmEn_r3 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R3_TrainingIncDecDtsmEn_r3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R3_TrainingIncDecDtsmEn_r3_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R3_TrainingIncDecDtsmEn_r3_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R3 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R3_RxPBDlyTg0_r3_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R3_RxPBDlyTg0_r3_SHIFT (0U)
/*! RxPBDlyTg0_r3 - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R3_RxPBDlyTg0_r3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R3_RxPBDlyTg0_r3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R3_RxPBDlyTg0_r3_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R3 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R3_RxPBDlyTg1_r3_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R3_RxPBDlyTg1_r3_SHIFT (0U)
/*! RxPBDlyTg1_r3 - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R3_RxPBDlyTg1_r3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R3_RxPBDlyTg1_r3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R3_RxPBDlyTg1_r3_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R3 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R3_RxPBDlyTg2_r3_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R3_RxPBDlyTg2_r3_SHIFT (0U)
/*! RxPBDlyTg2_r3 - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R3_RxPBDlyTg2_r3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R3_RxPBDlyTg2_r3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R3_RxPBDlyTg2_r3_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R3 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R3_RxPBDlyTg3_r3_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R3_RxPBDlyTg3_r3_SHIFT (0U)
/*! RxPBDlyTg3_r3 - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R3_RxPBDlyTg3_r3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R3_RxPBDlyTg3_r3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R3_RxPBDlyTg3_r3_MASK)
/*! @} */

/*! @name TSM0_I3 - Per DTSM configuration and control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM0_I3_RFU_Tsm0_i3_MASK (0x3FFFU)
#define DWC_DDRPHYA_DBYTE_TSM0_I3_RFU_Tsm0_i3_SHIFT (0U)
/*! RFU_Tsm0_i3 - RFU_Tsm0_i3 */
#define DWC_DDRPHYA_DBYTE_TSM0_I3_RFU_Tsm0_i3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM0_I3_RFU_Tsm0_i3_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM0_I3_RFU_Tsm0_i3_MASK)
/*! @} */

/*! @name TSM1_I3 - Per DTSM cumulative error count */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM1_I3_RFU_Tsm1_i3_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TSM1_I3_RFU_Tsm1_i3_SHIFT (0U)
/*! RFU_Tsm1_i3 - RFU_Tsm1_i3 */
#define DWC_DDRPHYA_DBYTE_TSM1_I3_RFU_Tsm1_i3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM1_I3_RFU_Tsm1_i3_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM1_I3_RFU_Tsm1_i3_MASK)
/*! @} */

/*! @name TSM2_I3 - Per DTSM control for disabling error checking */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM2_I3_RFU_Tsm2_i3_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_TSM2_I3_RFU_Tsm2_i3_SHIFT (0U)
/*! RFU_Tsm2_i3 - RFU_Tsm2_i3 */
#define DWC_DDRPHYA_DBYTE_TSM2_I3_RFU_Tsm2_i3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM2_I3_RFU_Tsm2_i3_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM2_I3_RFU_Tsm2_i3_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R3_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P0_TxDqDlyTg0_r3_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P0_TxDqDlyTg0_r3_p0_SHIFT (0U)
/*! TxDqDlyTg0_r3_p0 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P0_TxDqDlyTg0_r3_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P0_TxDqDlyTg0_r3_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P0_TxDqDlyTg0_r3_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R3_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P0_TxDqDlyTg1_r3_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P0_TxDqDlyTg1_r3_p0_SHIFT (0U)
/*! TxDqDlyTg1_r3_p0 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P0_TxDqDlyTg1_r3_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P0_TxDqDlyTg1_r3_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P0_TxDqDlyTg1_r3_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R3_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P0_TxDqDlyTg2_r3_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P0_TxDqDlyTg2_r3_p0_SHIFT (0U)
/*! TxDqDlyTg2_r3_p0 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P0_TxDqDlyTg2_r3_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P0_TxDqDlyTg2_r3_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P0_TxDqDlyTg2_r3_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R3_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P0_TxDqDlyTg3_r3_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P0_TxDqDlyTg3_r3_p0_SHIFT (0U)
/*! TxDqDlyTg3_r3_p0 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P0_TxDqDlyTg3_r3_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P0_TxDqDlyTg3_r3_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P0_TxDqDlyTg3_r3_p0_MASK)
/*! @} */

/*! @name VREFDAC1_R4 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R4_VrefDAC1_r4_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R4_VrefDAC1_r4_SHIFT (0U)
/*! VrefDAC1_r4 - VrefDAC1_r4 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R4_VrefDAC1_r4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R4_VrefDAC1_r4_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R4_VrefDAC1_r4_MASK)
/*! @} */

/*! @name TRAININGCNTR_R4 - Training counter. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R4_RFU_TrainingCntr_r4_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R4_RFU_TrainingCntr_r4_SHIFT (0U)
/*! RFU_TrainingCntr_r4 - RFU_TrainingCntr_r4 */
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R4_RFU_TrainingCntr_r4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGCNTR_R4_RFU_TrainingCntr_r4_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGCNTR_R4_RFU_TrainingCntr_r4_MASK)
/*! @} */

/*! @name VREFDAC0_R4 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R4_VrefDAC0_r4_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R4_VrefDAC0_r4_SHIFT (0U)
/*! VrefDAC0_r4 - VrefDAC0_r4 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R4_VrefDAC0_r4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R4_VrefDAC0_r4_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R4_VrefDAC0_r4_MASK)
/*! @} */

/*! @name TRAININGINCDECDTSMEN_R4 - Enables the any of a group of DTSMs to modify a particular TrainingCounter */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R4_TrainingIncDecDtsmEn_r4_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R4_TrainingIncDecDtsmEn_r4_SHIFT (0U)
/*! TrainingIncDecDtsmEn_r4 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R4_TrainingIncDecDtsmEn_r4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R4_TrainingIncDecDtsmEn_r4_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R4_TrainingIncDecDtsmEn_r4_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R4 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R4_RxPBDlyTg0_r4_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R4_RxPBDlyTg0_r4_SHIFT (0U)
/*! RxPBDlyTg0_r4 - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R4_RxPBDlyTg0_r4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R4_RxPBDlyTg0_r4_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R4_RxPBDlyTg0_r4_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R4 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R4_RxPBDlyTg1_r4_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R4_RxPBDlyTg1_r4_SHIFT (0U)
/*! RxPBDlyTg1_r4 - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R4_RxPBDlyTg1_r4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R4_RxPBDlyTg1_r4_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R4_RxPBDlyTg1_r4_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R4 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R4_RxPBDlyTg2_r4_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R4_RxPBDlyTg2_r4_SHIFT (0U)
/*! RxPBDlyTg2_r4 - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R4_RxPBDlyTg2_r4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R4_RxPBDlyTg2_r4_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R4_RxPBDlyTg2_r4_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R4 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R4_RxPBDlyTg3_r4_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R4_RxPBDlyTg3_r4_SHIFT (0U)
/*! RxPBDlyTg3_r4 - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R4_RxPBDlyTg3_r4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R4_RxPBDlyTg3_r4_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R4_RxPBDlyTg3_r4_MASK)
/*! @} */

/*! @name TSM0_I4 - Per DTSM configuration and control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM0_I4_RFU_Tsm0_i4_MASK (0x3FFFU)
#define DWC_DDRPHYA_DBYTE_TSM0_I4_RFU_Tsm0_i4_SHIFT (0U)
/*! RFU_Tsm0_i4 - RFU_Tsm0_i4 */
#define DWC_DDRPHYA_DBYTE_TSM0_I4_RFU_Tsm0_i4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM0_I4_RFU_Tsm0_i4_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM0_I4_RFU_Tsm0_i4_MASK)
/*! @} */

/*! @name TSM1_I4 - Per DTSM cumulative error count */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM1_I4_RFU_Tsm1_i4_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TSM1_I4_RFU_Tsm1_i4_SHIFT (0U)
/*! RFU_Tsm1_i4 - RFU_Tsm1_i4 */
#define DWC_DDRPHYA_DBYTE_TSM1_I4_RFU_Tsm1_i4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM1_I4_RFU_Tsm1_i4_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM1_I4_RFU_Tsm1_i4_MASK)
/*! @} */

/*! @name TSM2_I4 - Per DTSM control for disabling error checking */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM2_I4_RFU_Tsm2_i4_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_TSM2_I4_RFU_Tsm2_i4_SHIFT (0U)
/*! RFU_Tsm2_i4 - RFU_Tsm2_i4 */
#define DWC_DDRPHYA_DBYTE_TSM2_I4_RFU_Tsm2_i4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM2_I4_RFU_Tsm2_i4_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM2_I4_RFU_Tsm2_i4_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R4_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P0_TxDqDlyTg0_r4_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P0_TxDqDlyTg0_r4_p0_SHIFT (0U)
/*! TxDqDlyTg0_r4_p0 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P0_TxDqDlyTg0_r4_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P0_TxDqDlyTg0_r4_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P0_TxDqDlyTg0_r4_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R4_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P0_TxDqDlyTg1_r4_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P0_TxDqDlyTg1_r4_p0_SHIFT (0U)
/*! TxDqDlyTg1_r4_p0 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P0_TxDqDlyTg1_r4_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P0_TxDqDlyTg1_r4_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P0_TxDqDlyTg1_r4_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R4_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P0_TxDqDlyTg2_r4_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P0_TxDqDlyTg2_r4_p0_SHIFT (0U)
/*! TxDqDlyTg2_r4_p0 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P0_TxDqDlyTg2_r4_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P0_TxDqDlyTg2_r4_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P0_TxDqDlyTg2_r4_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R4_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P0_TxDqDlyTg3_r4_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P0_TxDqDlyTg3_r4_p0_SHIFT (0U)
/*! TxDqDlyTg3_r4_p0 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P0_TxDqDlyTg3_r4_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P0_TxDqDlyTg3_r4_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P0_TxDqDlyTg3_r4_p0_MASK)
/*! @} */

/*! @name VREFDAC1_R5 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R5_VrefDAC1_r5_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R5_VrefDAC1_r5_SHIFT (0U)
/*! VrefDAC1_r5 - VrefDAC1_r5 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R5_VrefDAC1_r5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R5_VrefDAC1_r5_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R5_VrefDAC1_r5_MASK)
/*! @} */

/*! @name TRAININGCNTR_R5 - Training counter. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R5_RFU_TrainingCntr_r5_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R5_RFU_TrainingCntr_r5_SHIFT (0U)
/*! RFU_TrainingCntr_r5 - RFU_TrainingCntr_r5 */
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R5_RFU_TrainingCntr_r5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGCNTR_R5_RFU_TrainingCntr_r5_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGCNTR_R5_RFU_TrainingCntr_r5_MASK)
/*! @} */

/*! @name VREFDAC0_R5 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R5_VrefDAC0_r5_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R5_VrefDAC0_r5_SHIFT (0U)
/*! VrefDAC0_r5 - VrefDAC0_r5 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R5_VrefDAC0_r5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R5_VrefDAC0_r5_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R5_VrefDAC0_r5_MASK)
/*! @} */

/*! @name TRAININGINCDECDTSMEN_R5 - Enables the any of a group of DTSMs to modify a particular TrainingCounter */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R5_TrainingIncDecDtsmEn_r5_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R5_TrainingIncDecDtsmEn_r5_SHIFT (0U)
/*! TrainingIncDecDtsmEn_r5 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R5_TrainingIncDecDtsmEn_r5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R5_TrainingIncDecDtsmEn_r5_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R5_TrainingIncDecDtsmEn_r5_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R5 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R5_RxPBDlyTg0_r5_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R5_RxPBDlyTg0_r5_SHIFT (0U)
/*! RxPBDlyTg0_r5 - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R5_RxPBDlyTg0_r5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R5_RxPBDlyTg0_r5_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R5_RxPBDlyTg0_r5_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R5 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R5_RxPBDlyTg1_r5_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R5_RxPBDlyTg1_r5_SHIFT (0U)
/*! RxPBDlyTg1_r5 - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R5_RxPBDlyTg1_r5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R5_RxPBDlyTg1_r5_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R5_RxPBDlyTg1_r5_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R5 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R5_RxPBDlyTg2_r5_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R5_RxPBDlyTg2_r5_SHIFT (0U)
/*! RxPBDlyTg2_r5 - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R5_RxPBDlyTg2_r5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R5_RxPBDlyTg2_r5_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R5_RxPBDlyTg2_r5_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R5 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R5_RxPBDlyTg3_r5_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R5_RxPBDlyTg3_r5_SHIFT (0U)
/*! RxPBDlyTg3_r5 - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R5_RxPBDlyTg3_r5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R5_RxPBDlyTg3_r5_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R5_RxPBDlyTg3_r5_MASK)
/*! @} */

/*! @name TSM0_I5 - Per DTSM configuration and control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM0_I5_RFU_Tsm0_i5_MASK (0x3FFFU)
#define DWC_DDRPHYA_DBYTE_TSM0_I5_RFU_Tsm0_i5_SHIFT (0U)
/*! RFU_Tsm0_i5 - RFU_Tsm0_i5 */
#define DWC_DDRPHYA_DBYTE_TSM0_I5_RFU_Tsm0_i5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM0_I5_RFU_Tsm0_i5_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM0_I5_RFU_Tsm0_i5_MASK)
/*! @} */

/*! @name TSM1_I5 - Per DTSM cumulative error count */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM1_I5_RFU_Tsm1_i5_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TSM1_I5_RFU_Tsm1_i5_SHIFT (0U)
/*! RFU_Tsm1_i5 - RFU_Tsm1_i5 */
#define DWC_DDRPHYA_DBYTE_TSM1_I5_RFU_Tsm1_i5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM1_I5_RFU_Tsm1_i5_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM1_I5_RFU_Tsm1_i5_MASK)
/*! @} */

/*! @name TSM2_I5 - Per DTSM control for disabling error checking */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM2_I5_RFU_Tsm2_i5_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_TSM2_I5_RFU_Tsm2_i5_SHIFT (0U)
/*! RFU_Tsm2_i5 - RFU_Tsm2_i5 */
#define DWC_DDRPHYA_DBYTE_TSM2_I5_RFU_Tsm2_i5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM2_I5_RFU_Tsm2_i5_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM2_I5_RFU_Tsm2_i5_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R5_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P0_TxDqDlyTg0_r5_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P0_TxDqDlyTg0_r5_p0_SHIFT (0U)
/*! TxDqDlyTg0_r5_p0 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P0_TxDqDlyTg0_r5_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P0_TxDqDlyTg0_r5_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P0_TxDqDlyTg0_r5_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R5_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P0_TxDqDlyTg1_r5_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P0_TxDqDlyTg1_r5_p0_SHIFT (0U)
/*! TxDqDlyTg1_r5_p0 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P0_TxDqDlyTg1_r5_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P0_TxDqDlyTg1_r5_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P0_TxDqDlyTg1_r5_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R5_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P0_TxDqDlyTg2_r5_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P0_TxDqDlyTg2_r5_p0_SHIFT (0U)
/*! TxDqDlyTg2_r5_p0 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P0_TxDqDlyTg2_r5_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P0_TxDqDlyTg2_r5_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P0_TxDqDlyTg2_r5_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R5_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P0_TxDqDlyTg3_r5_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P0_TxDqDlyTg3_r5_p0_SHIFT (0U)
/*! TxDqDlyTg3_r5_p0 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P0_TxDqDlyTg3_r5_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P0_TxDqDlyTg3_r5_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P0_TxDqDlyTg3_r5_p0_MASK)
/*! @} */

/*! @name VREFDAC1_R6 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R6_VrefDAC1_r6_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R6_VrefDAC1_r6_SHIFT (0U)
/*! VrefDAC1_r6 - VrefDAC1_r6 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R6_VrefDAC1_r6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R6_VrefDAC1_r6_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R6_VrefDAC1_r6_MASK)
/*! @} */

/*! @name TRAININGCNTR_R6 - Training counter. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R6_RFU_TrainingCntr_r6_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R6_RFU_TrainingCntr_r6_SHIFT (0U)
/*! RFU_TrainingCntr_r6 - RFU_TrainingCntr_r6 */
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R6_RFU_TrainingCntr_r6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGCNTR_R6_RFU_TrainingCntr_r6_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGCNTR_R6_RFU_TrainingCntr_r6_MASK)
/*! @} */

/*! @name VREFDAC0_R6 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R6_VrefDAC0_r6_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R6_VrefDAC0_r6_SHIFT (0U)
/*! VrefDAC0_r6 - VrefDAC0_r6 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R6_VrefDAC0_r6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R6_VrefDAC0_r6_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R6_VrefDAC0_r6_MASK)
/*! @} */

/*! @name TRAININGINCDECDTSMEN_R6 - Enables the any of a group of DTSMs to modify a particular TrainingCounter */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R6_TrainingIncDecDtsmEn_r6_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R6_TrainingIncDecDtsmEn_r6_SHIFT (0U)
/*! TrainingIncDecDtsmEn_r6 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R6_TrainingIncDecDtsmEn_r6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R6_TrainingIncDecDtsmEn_r6_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R6_TrainingIncDecDtsmEn_r6_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R6 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R6_RxPBDlyTg0_r6_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R6_RxPBDlyTg0_r6_SHIFT (0U)
/*! RxPBDlyTg0_r6 - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R6_RxPBDlyTg0_r6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R6_RxPBDlyTg0_r6_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R6_RxPBDlyTg0_r6_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R6 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R6_RxPBDlyTg1_r6_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R6_RxPBDlyTg1_r6_SHIFT (0U)
/*! RxPBDlyTg1_r6 - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R6_RxPBDlyTg1_r6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R6_RxPBDlyTg1_r6_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R6_RxPBDlyTg1_r6_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R6 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R6_RxPBDlyTg2_r6_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R6_RxPBDlyTg2_r6_SHIFT (0U)
/*! RxPBDlyTg2_r6 - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R6_RxPBDlyTg2_r6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R6_RxPBDlyTg2_r6_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R6_RxPBDlyTg2_r6_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R6 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R6_RxPBDlyTg3_r6_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R6_RxPBDlyTg3_r6_SHIFT (0U)
/*! RxPBDlyTg3_r6 - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R6_RxPBDlyTg3_r6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R6_RxPBDlyTg3_r6_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R6_RxPBDlyTg3_r6_MASK)
/*! @} */

/*! @name TSM0_I6 - Per DTSM configuration and control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM0_I6_RFU_Tsm0_i6_MASK (0x3FFFU)
#define DWC_DDRPHYA_DBYTE_TSM0_I6_RFU_Tsm0_i6_SHIFT (0U)
/*! RFU_Tsm0_i6 - RFU_Tsm0_i6 */
#define DWC_DDRPHYA_DBYTE_TSM0_I6_RFU_Tsm0_i6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM0_I6_RFU_Tsm0_i6_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM0_I6_RFU_Tsm0_i6_MASK)
/*! @} */

/*! @name TSM1_I6 - Per DTSM cumulative error count */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM1_I6_RFU_Tsm1_i6_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TSM1_I6_RFU_Tsm1_i6_SHIFT (0U)
/*! RFU_Tsm1_i6 - RFU_Tsm1_i6 */
#define DWC_DDRPHYA_DBYTE_TSM1_I6_RFU_Tsm1_i6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM1_I6_RFU_Tsm1_i6_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM1_I6_RFU_Tsm1_i6_MASK)
/*! @} */

/*! @name TSM2_I6 - Per DTSM control for disabling error checking */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM2_I6_RFU_Tsm2_i6_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_TSM2_I6_RFU_Tsm2_i6_SHIFT (0U)
/*! RFU_Tsm2_i6 - RFU_Tsm2_i6 */
#define DWC_DDRPHYA_DBYTE_TSM2_I6_RFU_Tsm2_i6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM2_I6_RFU_Tsm2_i6_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM2_I6_RFU_Tsm2_i6_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R6_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P0_TxDqDlyTg0_r6_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P0_TxDqDlyTg0_r6_p0_SHIFT (0U)
/*! TxDqDlyTg0_r6_p0 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P0_TxDqDlyTg0_r6_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P0_TxDqDlyTg0_r6_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P0_TxDqDlyTg0_r6_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R6_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P0_TxDqDlyTg1_r6_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P0_TxDqDlyTg1_r6_p0_SHIFT (0U)
/*! TxDqDlyTg1_r6_p0 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P0_TxDqDlyTg1_r6_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P0_TxDqDlyTg1_r6_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P0_TxDqDlyTg1_r6_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R6_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P0_TxDqDlyTg2_r6_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P0_TxDqDlyTg2_r6_p0_SHIFT (0U)
/*! TxDqDlyTg2_r6_p0 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P0_TxDqDlyTg2_r6_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P0_TxDqDlyTg2_r6_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P0_TxDqDlyTg2_r6_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R6_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P0_TxDqDlyTg3_r6_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P0_TxDqDlyTg3_r6_p0_SHIFT (0U)
/*! TxDqDlyTg3_r6_p0 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P0_TxDqDlyTg3_r6_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P0_TxDqDlyTg3_r6_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P0_TxDqDlyTg3_r6_p0_MASK)
/*! @} */

/*! @name VREFDAC1_R7 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R7_VrefDAC1_r7_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R7_VrefDAC1_r7_SHIFT (0U)
/*! VrefDAC1_r7 - VrefDAC1_r7 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R7_VrefDAC1_r7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R7_VrefDAC1_r7_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R7_VrefDAC1_r7_MASK)
/*! @} */

/*! @name TRAININGCNTR_R7 - Training counter. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R7_RFU_TrainingCntr_r7_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R7_RFU_TrainingCntr_r7_SHIFT (0U)
/*! RFU_TrainingCntr_r7 - RFU_TrainingCntr_r7 */
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R7_RFU_TrainingCntr_r7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGCNTR_R7_RFU_TrainingCntr_r7_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGCNTR_R7_RFU_TrainingCntr_r7_MASK)
/*! @} */

/*! @name VREFDAC0_R7 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R7_VrefDAC0_r7_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R7_VrefDAC0_r7_SHIFT (0U)
/*! VrefDAC0_r7 - VrefDAC0_r7 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R7_VrefDAC0_r7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R7_VrefDAC0_r7_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R7_VrefDAC0_r7_MASK)
/*! @} */

/*! @name TRAININGINCDECDTSMEN_R7 - Enables the any of a group of DTSMs to modify a particular TrainingCounter */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R7_TrainingIncDecDtsmEn_r7_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R7_TrainingIncDecDtsmEn_r7_SHIFT (0U)
/*! TrainingIncDecDtsmEn_r7 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R7_TrainingIncDecDtsmEn_r7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R7_TrainingIncDecDtsmEn_r7_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R7_TrainingIncDecDtsmEn_r7_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R7 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R7_RxPBDlyTg0_r7_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R7_RxPBDlyTg0_r7_SHIFT (0U)
/*! RxPBDlyTg0_r7 - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R7_RxPBDlyTg0_r7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R7_RxPBDlyTg0_r7_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R7_RxPBDlyTg0_r7_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R7 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R7_RxPBDlyTg1_r7_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R7_RxPBDlyTg1_r7_SHIFT (0U)
/*! RxPBDlyTg1_r7 - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R7_RxPBDlyTg1_r7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R7_RxPBDlyTg1_r7_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R7_RxPBDlyTg1_r7_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R7 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R7_RxPBDlyTg2_r7_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R7_RxPBDlyTg2_r7_SHIFT (0U)
/*! RxPBDlyTg2_r7 - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R7_RxPBDlyTg2_r7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R7_RxPBDlyTg2_r7_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R7_RxPBDlyTg2_r7_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R7 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R7_RxPBDlyTg3_r7_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R7_RxPBDlyTg3_r7_SHIFT (0U)
/*! RxPBDlyTg3_r7 - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R7_RxPBDlyTg3_r7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R7_RxPBDlyTg3_r7_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R7_RxPBDlyTg3_r7_MASK)
/*! @} */

/*! @name TSM0_I7 - Per DTSM configuration and control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM0_I7_RFU_Tsm0_i7_MASK (0x3FFFU)
#define DWC_DDRPHYA_DBYTE_TSM0_I7_RFU_Tsm0_i7_SHIFT (0U)
/*! RFU_Tsm0_i7 - RFU_Tsm0_i7 */
#define DWC_DDRPHYA_DBYTE_TSM0_I7_RFU_Tsm0_i7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM0_I7_RFU_Tsm0_i7_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM0_I7_RFU_Tsm0_i7_MASK)
/*! @} */

/*! @name TSM1_I7 - Per DTSM cumulative error count */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM1_I7_RFU_Tsm1_i7_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TSM1_I7_RFU_Tsm1_i7_SHIFT (0U)
/*! RFU_Tsm1_i7 - RFU_Tsm1_i7 */
#define DWC_DDRPHYA_DBYTE_TSM1_I7_RFU_Tsm1_i7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM1_I7_RFU_Tsm1_i7_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM1_I7_RFU_Tsm1_i7_MASK)
/*! @} */

/*! @name TSM2_I7 - Per DTSM control for disabling error checking */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM2_I7_RFU_Tsm2_i7_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_TSM2_I7_RFU_Tsm2_i7_SHIFT (0U)
/*! RFU_Tsm2_i7 - RFU_Tsm2_i7 */
#define DWC_DDRPHYA_DBYTE_TSM2_I7_RFU_Tsm2_i7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM2_I7_RFU_Tsm2_i7_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM2_I7_RFU_Tsm2_i7_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R7_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P0_TxDqDlyTg0_r7_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P0_TxDqDlyTg0_r7_p0_SHIFT (0U)
/*! TxDqDlyTg0_r7_p0 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P0_TxDqDlyTg0_r7_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P0_TxDqDlyTg0_r7_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P0_TxDqDlyTg0_r7_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R7_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P0_TxDqDlyTg1_r7_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P0_TxDqDlyTg1_r7_p0_SHIFT (0U)
/*! TxDqDlyTg1_r7_p0 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P0_TxDqDlyTg1_r7_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P0_TxDqDlyTg1_r7_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P0_TxDqDlyTg1_r7_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R7_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P0_TxDqDlyTg2_r7_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P0_TxDqDlyTg2_r7_p0_SHIFT (0U)
/*! TxDqDlyTg2_r7_p0 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P0_TxDqDlyTg2_r7_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P0_TxDqDlyTg2_r7_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P0_TxDqDlyTg2_r7_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R7_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P0_TxDqDlyTg3_r7_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P0_TxDqDlyTg3_r7_p0_SHIFT (0U)
/*! TxDqDlyTg3_r7_p0 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P0_TxDqDlyTg3_r7_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P0_TxDqDlyTg3_r7_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P0_TxDqDlyTg3_r7_p0_MASK)
/*! @} */

/*! @name VREFDAC1_R8 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R8_VrefDAC1_r8_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R8_VrefDAC1_r8_SHIFT (0U)
/*! VrefDAC1_r8 - VrefDAC1_r8 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R8_VrefDAC1_r8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R8_VrefDAC1_r8_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R8_VrefDAC1_r8_MASK)
/*! @} */

/*! @name TRAININGCNTR_R8 - Training counter. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R8_RFU_TrainingCntr_r8_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R8_RFU_TrainingCntr_r8_SHIFT (0U)
/*! RFU_TrainingCntr_r8 - RFU_TrainingCntr_r8 */
#define DWC_DDRPHYA_DBYTE_TRAININGCNTR_R8_RFU_TrainingCntr_r8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGCNTR_R8_RFU_TrainingCntr_r8_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGCNTR_R8_RFU_TrainingCntr_r8_MASK)
/*! @} */

/*! @name VREFDAC0_R8 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R8_VrefDAC0_r8_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R8_VrefDAC0_r8_SHIFT (0U)
/*! VrefDAC0_r8 - VrefDAC0_r8 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R8_VrefDAC0_r8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R8_VrefDAC0_r8_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R8_VrefDAC0_r8_MASK)
/*! @} */

/*! @name TRAININGINCDECDTSMEN_R8 - Enables the any of a group of DTSMs to modify a particular TrainingCounter */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R8_TrainingIncDecDtsmEn_r8_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R8_TrainingIncDecDtsmEn_r8_SHIFT (0U)
/*! TrainingIncDecDtsmEn_r8 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R8_TrainingIncDecDtsmEn_r8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R8_TrainingIncDecDtsmEn_r8_SHIFT)) & DWC_DDRPHYA_DBYTE_TRAININGINCDECDTSMEN_R8_TrainingIncDecDtsmEn_r8_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R8 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R8_RxPBDlyTg0_r8_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R8_RxPBDlyTg0_r8_SHIFT (0U)
/*! RxPBDlyTg0_r8 - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R8_RxPBDlyTg0_r8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R8_RxPBDlyTg0_r8_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R8_RxPBDlyTg0_r8_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R8 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R8_RxPBDlyTg1_r8_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R8_RxPBDlyTg1_r8_SHIFT (0U)
/*! RxPBDlyTg1_r8 - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R8_RxPBDlyTg1_r8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R8_RxPBDlyTg1_r8_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R8_RxPBDlyTg1_r8_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R8 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R8_RxPBDlyTg2_r8_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R8_RxPBDlyTg2_r8_SHIFT (0U)
/*! RxPBDlyTg2_r8 - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R8_RxPBDlyTg2_r8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R8_RxPBDlyTg2_r8_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R8_RxPBDlyTg2_r8_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R8 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R8_RxPBDlyTg3_r8_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R8_RxPBDlyTg3_r8_SHIFT (0U)
/*! RxPBDlyTg3_r8 - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R8_RxPBDlyTg3_r8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R8_RxPBDlyTg3_r8_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R8_RxPBDlyTg3_r8_MASK)
/*! @} */

/*! @name TSM0_I8 - Per DTSM configuration and control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM0_I8_RFU_Tsm0_i8_MASK (0x3FFFU)
#define DWC_DDRPHYA_DBYTE_TSM0_I8_RFU_Tsm0_i8_SHIFT (0U)
/*! RFU_Tsm0_i8 - RFU_Tsm0_i8 */
#define DWC_DDRPHYA_DBYTE_TSM0_I8_RFU_Tsm0_i8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM0_I8_RFU_Tsm0_i8_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM0_I8_RFU_Tsm0_i8_MASK)
/*! @} */

/*! @name TSM1_I8 - Per DTSM cumulative error count */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM1_I8_RFU_Tsm1_i8_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_TSM1_I8_RFU_Tsm1_i8_SHIFT (0U)
/*! RFU_Tsm1_i8 - RFU_Tsm1_i8 */
#define DWC_DDRPHYA_DBYTE_TSM1_I8_RFU_Tsm1_i8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM1_I8_RFU_Tsm1_i8_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM1_I8_RFU_Tsm1_i8_MASK)
/*! @} */

/*! @name TSM2_I8 - Per DTSM control for disabling error checking */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TSM2_I8_RFU_Tsm2_i8_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_TSM2_I8_RFU_Tsm2_i8_SHIFT (0U)
/*! RFU_Tsm2_i8 - RFU_Tsm2_i8 */
#define DWC_DDRPHYA_DBYTE_TSM2_I8_RFU_Tsm2_i8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TSM2_I8_RFU_Tsm2_i8_SHIFT)) & DWC_DDRPHYA_DBYTE_TSM2_I8_RFU_Tsm2_i8_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R8_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P0_TxDqDlyTg0_r8_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P0_TxDqDlyTg0_r8_p0_SHIFT (0U)
/*! TxDqDlyTg0_r8_p0 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P0_TxDqDlyTg0_r8_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P0_TxDqDlyTg0_r8_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P0_TxDqDlyTg0_r8_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R8_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P0_TxDqDlyTg1_r8_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P0_TxDqDlyTg1_r8_p0_SHIFT (0U)
/*! TxDqDlyTg1_r8_p0 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P0_TxDqDlyTg1_r8_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P0_TxDqDlyTg1_r8_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P0_TxDqDlyTg1_r8_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R8_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P0_TxDqDlyTg2_r8_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P0_TxDqDlyTg2_r8_p0_SHIFT (0U)
/*! TxDqDlyTg2_r8_p0 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P0_TxDqDlyTg2_r8_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P0_TxDqDlyTg2_r8_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P0_TxDqDlyTg2_r8_p0_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R8_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P0_TxDqDlyTg3_r8_p0_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P0_TxDqDlyTg3_r8_p0_SHIFT (0U)
/*! TxDqDlyTg3_r8_p0 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P0_TxDqDlyTg3_r8_p0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P0_TxDqDlyTg3_r8_p0_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P0_TxDqDlyTg3_r8_p0_MASK)
/*! @} */

/*! @name USEDQSENREPLICA_P1 - Enable DqsEnArVIO Delay Matching Path */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P1_UseDqsEnReplica_p1_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P1_UseDqsEnReplica_p1_SHIFT (0U)
/*! UseDqsEnReplica_p1 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P1_UseDqsEnReplica_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P1_UseDqsEnReplica_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P1_UseDqsEnReplica_p1_MASK)
/*! @} */

/*! @name DFIMRL_P1 - DFI MaxReadLatency */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DFIMRL_P1_DFIMRL_p1_MASK (0x1FU)
#define DWC_DDRPHYA_DBYTE_DFIMRL_P1_DFIMRL_p1_SHIFT (0U)
/*! DFIMRL_p1 - This Max Read Latency CSR is to be trained to ensure the rx-data fifo is not read
 *    until after all dbytes have their read data valid.
 */
#define DWC_DDRPHYA_DBYTE_DFIMRL_P1_DFIMRL_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DFIMRL_P1_DFIMRL_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_DFIMRL_P1_DFIMRL_p1_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL0_B0_P1 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqN_MASK)
/*! @} */

/*! @name DQDQSRCVCNTRL_B0_P1 - Dq/Dqs receiver control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_SelAnalogVref_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_SelAnalogVref_SHIFT (0U)
/*! SelAnalogVref - Setting this signal high will force the local per-bit VREF generator to pass the global VREFA to the samplers. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_SelAnalogVref(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_SelAnalogVref_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_SelAnalogVref_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_ExtVrefRange_MASK (0x2U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_ExtVrefRange_SHIFT (1U)
/*! ExtVrefRange - Extends the range available in the local per-bit VREF generator. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_ExtVrefRange(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_ExtVrefRange_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_ExtVrefRange_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_DfeCtrl_MASK (0xCU)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_DfeCtrl_SHIFT (2U)
/*! DfeCtrl - This field is programmable as follows - 00 - DFE off - 01 - DFE on - 10 - Train DFE0
 *    Amplifier - 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
 *    should not be overridden.
 */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_DfeCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_DfeCtrl_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_DfeCtrl_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_MajorModeDbyte_MASK (0x70U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_MajorModeDbyte_SHIFT (4U)
/*! MajorModeDbyte - Selects the major mode of operation for the receiver. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_MajorModeDbyte(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_MajorModeDbyte_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_MajorModeDbyte_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_GainCurrAdj_MASK (0xF80U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_GainCurrAdj_SHIFT (7U)
/*! GainCurrAdj - Adjust gain current of RX amplifier stage. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_GainCurrAdj(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_GainCurrAdj_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P1_GainCurrAdj_MASK)
/*! @} */

/*! @name TXEQUALIZATIONMODE_P1 - Tx dq driver equalization mode controls. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P1_TxEqMode_MASK (0x3U)
#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P1_TxEqMode_SHIFT (0U)
/*! TxEqMode - Tx dq driver equalization mode controls. */
#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P1_TxEqMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P1_TxEqMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P1_TxEqMode_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL1_B0_P1 - TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqP_SHIFT (0U)
/*! DrvStrenFSDqP - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B0_P1 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQLoDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQLoDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQLoDqN_MASK)
/*! @} */

/*! @name DQDQSRCVCNTRL2_P1 - Dq/Dqs receiver control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P1_EnRxAgressivePDR_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P1_EnRxAgressivePDR_SHIFT (0U)
/*! EnRxAgressivePDR - reserved */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P1_EnRxAgressivePDR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P1_EnRxAgressivePDR_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P1_EnRxAgressivePDR_MASK)
/*! @} */

/*! @name TXODTDRVSTREN_B0_P1 - TX ODT driver strength control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P1_ODTStrenP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P1_ODTStrenP_SHIFT (0U)
/*! ODTStrenP - Selects the ODT pull-up impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P1_ODTStrenP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P1_ODTStrenP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P1_ODTStrenP_MASK)

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P1_ODTStrenN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P1_ODTStrenN_SHIFT (6U)
/*! ODTStrenN - Selects the ODT pull-down impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P1_ODTStrenN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P1_ODTStrenN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P1_ODTStrenN_MASK)
/*! @} */

/*! @name TXSLEWRATE_B0_P1 - TX slew rate controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreP_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreP_SHIFT (0U)
/*! TxPreP - This is the 4-bit binary trim for the driver pull up slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreP_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreN_MASK (0xF0U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreN_SHIFT (4U)
/*! TxPreN - 4 bit binary trim for the driver pull down slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreN_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreDrvMode_MASK (0x700U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreDrvMode_SHIFT (8U)
/*! TxPreDrvMode - Controls predrivers to adjust timing of turn-on and turn-off of pull-up and pull-down segments. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreDrvMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreDrvMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P1_TxPreDrvMode_MASK)
/*! @} */

/*! @name RXENDLYTG0_U0_P1 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P1_RxEnDlyTg0_u0_p1_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P1_RxEnDlyTg0_u0_p1_SHIFT (0U)
/*! RxEnDlyTg0_u0_p1 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P1_RxEnDlyTg0_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P1_RxEnDlyTg0_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P1_RxEnDlyTg0_u0_p1_MASK)
/*! @} */

/*! @name RXENDLYTG1_U0_P1 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P1_RxEnDlyTg1_u0_p1_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P1_RxEnDlyTg1_u0_p1_SHIFT (0U)
/*! RxEnDlyTg1_u0_p1 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P1_RxEnDlyTg1_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P1_RxEnDlyTg1_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P1_RxEnDlyTg1_u0_p1_MASK)
/*! @} */

/*! @name RXENDLYTG2_U0_P1 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P1_RxEnDlyTg2_u0_p1_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P1_RxEnDlyTg2_u0_p1_SHIFT (0U)
/*! RxEnDlyTg2_u0_p1 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P1_RxEnDlyTg2_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P1_RxEnDlyTg2_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P1_RxEnDlyTg2_u0_p1_MASK)
/*! @} */

/*! @name RXENDLYTG3_U0_P1 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P1_RxEnDlyTg3_u0_p1_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P1_RxEnDlyTg3_u0_p1_SHIFT (0U)
/*! RxEnDlyTg3_u0_p1 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P1_RxEnDlyTg3_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P1_RxEnDlyTg3_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P1_RxEnDlyTg3_u0_p1_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U0_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P1_RxClkDlyTg0_u0_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P1_RxClkDlyTg0_u0_p1_SHIFT (0U)
/*! RxClkDlyTg0_u0_p1 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P1_RxClkDlyTg0_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P1_RxClkDlyTg0_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P1_RxClkDlyTg0_u0_p1_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U0_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P1_RxClkDlyTg1_u0_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P1_RxClkDlyTg1_u0_p1_SHIFT (0U)
/*! RxClkDlyTg1_u0_p1 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P1_RxClkDlyTg1_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P1_RxClkDlyTg1_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P1_RxClkDlyTg1_u0_p1_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U0_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P1_RxClkDlyTg2_u0_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P1_RxClkDlyTg2_u0_p1_SHIFT (0U)
/*! RxClkDlyTg2_u0_p1 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P1_RxClkDlyTg2_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P1_RxClkDlyTg2_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P1_RxClkDlyTg2_u0_p1_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U0_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P1_RxClkDlyTg3_u0_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P1_RxClkDlyTg3_u0_p1_SHIFT (0U)
/*! RxClkDlyTg3_u0_p1 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P1_RxClkDlyTg3_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P1_RxClkDlyTg3_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P1_RxClkDlyTg3_u0_p1_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U0_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P1_RxClkcDlyTg0_u0_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P1_RxClkcDlyTg0_u0_p1_SHIFT (0U)
/*! RxClkcDlyTg0_u0_p1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P1_RxClkcDlyTg0_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P1_RxClkcDlyTg0_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P1_RxClkcDlyTg0_u0_p1_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U0_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P1_RxClkcDlyTg1_u0_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P1_RxClkcDlyTg1_u0_p1_SHIFT (0U)
/*! RxClkcDlyTg1_u0_p1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P1_RxClkcDlyTg1_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P1_RxClkcDlyTg1_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P1_RxClkcDlyTg1_u0_p1_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U0_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P1_RxClkcDlyTg2_u0_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P1_RxClkcDlyTg2_u0_p1_SHIFT (0U)
/*! RxClkcDlyTg2_u0_p1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P1_RxClkcDlyTg2_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P1_RxClkcDlyTg2_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P1_RxClkcDlyTg2_u0_p1_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U0_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P1_RxClkcDlyTg3_u0_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P1_RxClkcDlyTg3_u0_p1_SHIFT (0U)
/*! RxClkcDlyTg3_u0_p1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P1_RxClkcDlyTg3_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P1_RxClkcDlyTg3_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P1_RxClkcDlyTg3_u0_p1_MASK)
/*! @} */

/*! @name PPTDQSCNTINVTRNTG0_P1 - DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P1_PptDqsCntInvTrnTg0_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P1_PptDqsCntInvTrnTg0_p1_SHIFT (0U)
/*! PptDqsCntInvTrnTg0_p1 - Programmed by PHY training firmware to support LPDDR3/LPDDR4 DRAM drift compensation. */
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P1_PptDqsCntInvTrnTg0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P1_PptDqsCntInvTrnTg0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P1_PptDqsCntInvTrnTg0_p1_MASK)
/*! @} */

/*! @name PPTDQSCNTINVTRNTG1_P1 - DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P1_PptDqsCntInvTrnTg1_p1_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P1_PptDqsCntInvTrnTg1_p1_SHIFT (0U)
/*! PptDqsCntInvTrnTg1_p1 - Programmed by PHY training firmware to support LPDDR3/LPDDR4 DRAM drift compensation. */
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P1_PptDqsCntInvTrnTg1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P1_PptDqsCntInvTrnTg1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P1_PptDqsCntInvTrnTg1_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R0_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P1_TxDqDlyTg0_r0_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P1_TxDqDlyTg0_r0_p1_SHIFT (0U)
/*! TxDqDlyTg0_r0_p1 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P1_TxDqDlyTg0_r0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P1_TxDqDlyTg0_r0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P1_TxDqDlyTg0_r0_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R0_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P1_TxDqDlyTg1_r0_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P1_TxDqDlyTg1_r0_p1_SHIFT (0U)
/*! TxDqDlyTg1_r0_p1 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P1_TxDqDlyTg1_r0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P1_TxDqDlyTg1_r0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P1_TxDqDlyTg1_r0_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R0_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P1_TxDqDlyTg2_r0_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P1_TxDqDlyTg2_r0_p1_SHIFT (0U)
/*! TxDqDlyTg2_r0_p1 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P1_TxDqDlyTg2_r0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P1_TxDqDlyTg2_r0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P1_TxDqDlyTg2_r0_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R0_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P1_TxDqDlyTg3_r0_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P1_TxDqDlyTg3_r0_p1_SHIFT (0U)
/*! TxDqDlyTg3_r0_p1 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P1_TxDqDlyTg3_r0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P1_TxDqDlyTg3_r0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P1_TxDqDlyTg3_r0_p1_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U0_P1 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P1_TxDqsDlyTg0_u0_p1_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P1_TxDqsDlyTg0_u0_p1_SHIFT (0U)
/*! TxDqsDlyTg0_u0_p1 - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P1_TxDqsDlyTg0_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P1_TxDqsDlyTg0_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P1_TxDqsDlyTg0_u0_p1_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U0_P1 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P1_TxDqsDlyTg1_u0_p1_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P1_TxDqsDlyTg1_u0_p1_SHIFT (0U)
/*! TxDqsDlyTg1_u0_p1 - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P1_TxDqsDlyTg1_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P1_TxDqsDlyTg1_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P1_TxDqsDlyTg1_u0_p1_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U0_P1 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P1_TxDqsDlyTg2_u0_p1_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P1_TxDqsDlyTg2_u0_p1_SHIFT (0U)
/*! TxDqsDlyTg2_u0_p1 - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P1_TxDqsDlyTg2_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P1_TxDqsDlyTg2_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P1_TxDqsDlyTg2_u0_p1_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U0_P1 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P1_TxDqsDlyTg3_u0_p1_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P1_TxDqsDlyTg3_u0_p1_SHIFT (0U)
/*! TxDqsDlyTg3_u0_p1 - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P1_TxDqsDlyTg3_u0_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P1_TxDqsDlyTg3_u0_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P1_TxDqsDlyTg3_u0_p1_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL0_B1_P1 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqN_MASK)
/*! @} */

/*! @name DQDQSRCVCNTRL_B1_P1 - Dq/Dqs receiver control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_SelAnalogVref_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_SelAnalogVref_SHIFT (0U)
/*! SelAnalogVref - Setting this signal high will force the local per-bit VREF generator to pass the global VREFA to the samplers. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_SelAnalogVref(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_SelAnalogVref_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_SelAnalogVref_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_ExtVrefRange_MASK (0x2U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_ExtVrefRange_SHIFT (1U)
/*! ExtVrefRange - Extends the range available in the local per-bit VREF generator. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_ExtVrefRange(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_ExtVrefRange_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_ExtVrefRange_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_DfeCtrl_MASK (0xCU)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_DfeCtrl_SHIFT (2U)
/*! DfeCtrl - This field is programmable as follows - 00 - DFE off - 01 - DFE on - 10 - Train DFE0
 *    Amplifier - 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
 *    should not be overridden.
 */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_DfeCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_DfeCtrl_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_DfeCtrl_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_MajorModeDbyte_MASK (0x70U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_MajorModeDbyte_SHIFT (4U)
/*! MajorModeDbyte - Selects the major mode of operation for the receiver. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_MajorModeDbyte(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_MajorModeDbyte_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_MajorModeDbyte_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_GainCurrAdj_MASK (0xF80U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_GainCurrAdj_SHIFT (7U)
/*! GainCurrAdj - Adjust gain current of RX amplifier stage. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_GainCurrAdj(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_GainCurrAdj_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P1_GainCurrAdj_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL1_B1_P1 - TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqP_SHIFT (0U)
/*! DrvStrenFSDqP - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B1_P1 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQLoDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQLoDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQLoDqN_MASK)
/*! @} */

/*! @name TXODTDRVSTREN_B1_P1 - TX ODT driver strength control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P1_ODTStrenP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P1_ODTStrenP_SHIFT (0U)
/*! ODTStrenP - Selects the ODT pull-up impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P1_ODTStrenP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P1_ODTStrenP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P1_ODTStrenP_MASK)

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P1_ODTStrenN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P1_ODTStrenN_SHIFT (6U)
/*! ODTStrenN - Selects the ODT pull-down impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P1_ODTStrenN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P1_ODTStrenN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P1_ODTStrenN_MASK)
/*! @} */

/*! @name TXSLEWRATE_B1_P1 - TX slew rate controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreP_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreP_SHIFT (0U)
/*! TxPreP - This is the 4-bit binary trim for the driver pull up slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreP_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreN_MASK (0xF0U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreN_SHIFT (4U)
/*! TxPreN - 4 bit binary trim for the driver pull down slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreN_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreDrvMode_MASK (0x700U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreDrvMode_SHIFT (8U)
/*! TxPreDrvMode - Controls predrivers to adjust timing of turn-on and turn-off of pull-up and pull-down segments. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreDrvMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreDrvMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P1_TxPreDrvMode_MASK)
/*! @} */

/*! @name RXENDLYTG0_U1_P1 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P1_RxEnDlyTg0_u1_p1_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P1_RxEnDlyTg0_u1_p1_SHIFT (0U)
/*! RxEnDlyTg0_u1_p1 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P1_RxEnDlyTg0_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P1_RxEnDlyTg0_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P1_RxEnDlyTg0_u1_p1_MASK)
/*! @} */

/*! @name RXENDLYTG1_U1_P1 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P1_RxEnDlyTg1_u1_p1_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P1_RxEnDlyTg1_u1_p1_SHIFT (0U)
/*! RxEnDlyTg1_u1_p1 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P1_RxEnDlyTg1_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P1_RxEnDlyTg1_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P1_RxEnDlyTg1_u1_p1_MASK)
/*! @} */

/*! @name RXENDLYTG2_U1_P1 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P1_RxEnDlyTg2_u1_p1_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P1_RxEnDlyTg2_u1_p1_SHIFT (0U)
/*! RxEnDlyTg2_u1_p1 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P1_RxEnDlyTg2_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P1_RxEnDlyTg2_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P1_RxEnDlyTg2_u1_p1_MASK)
/*! @} */

/*! @name RXENDLYTG3_U1_P1 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P1_RxEnDlyTg3_u1_p1_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P1_RxEnDlyTg3_u1_p1_SHIFT (0U)
/*! RxEnDlyTg3_u1_p1 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P1_RxEnDlyTg3_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P1_RxEnDlyTg3_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P1_RxEnDlyTg3_u1_p1_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U1_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P1_RxClkDlyTg0_u1_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P1_RxClkDlyTg0_u1_p1_SHIFT (0U)
/*! RxClkDlyTg0_u1_p1 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P1_RxClkDlyTg0_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P1_RxClkDlyTg0_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P1_RxClkDlyTg0_u1_p1_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U1_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P1_RxClkDlyTg1_u1_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P1_RxClkDlyTg1_u1_p1_SHIFT (0U)
/*! RxClkDlyTg1_u1_p1 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P1_RxClkDlyTg1_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P1_RxClkDlyTg1_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P1_RxClkDlyTg1_u1_p1_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U1_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P1_RxClkDlyTg2_u1_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P1_RxClkDlyTg2_u1_p1_SHIFT (0U)
/*! RxClkDlyTg2_u1_p1 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P1_RxClkDlyTg2_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P1_RxClkDlyTg2_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P1_RxClkDlyTg2_u1_p1_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U1_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P1_RxClkDlyTg3_u1_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P1_RxClkDlyTg3_u1_p1_SHIFT (0U)
/*! RxClkDlyTg3_u1_p1 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P1_RxClkDlyTg3_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P1_RxClkDlyTg3_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P1_RxClkDlyTg3_u1_p1_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U1_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P1_RxClkcDlyTg0_u1_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P1_RxClkcDlyTg0_u1_p1_SHIFT (0U)
/*! RxClkcDlyTg0_u1_p1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P1_RxClkcDlyTg0_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P1_RxClkcDlyTg0_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P1_RxClkcDlyTg0_u1_p1_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U1_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P1_RxClkcDlyTg1_u1_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P1_RxClkcDlyTg1_u1_p1_SHIFT (0U)
/*! RxClkcDlyTg1_u1_p1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P1_RxClkcDlyTg1_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P1_RxClkcDlyTg1_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P1_RxClkcDlyTg1_u1_p1_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U1_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P1_RxClkcDlyTg2_u1_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P1_RxClkcDlyTg2_u1_p1_SHIFT (0U)
/*! RxClkcDlyTg2_u1_p1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P1_RxClkcDlyTg2_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P1_RxClkcDlyTg2_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P1_RxClkcDlyTg2_u1_p1_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U1_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P1_RxClkcDlyTg3_u1_p1_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P1_RxClkcDlyTg3_u1_p1_SHIFT (0U)
/*! RxClkcDlyTg3_u1_p1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P1_RxClkcDlyTg3_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P1_RxClkcDlyTg3_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P1_RxClkcDlyTg3_u1_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R1_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P1_TxDqDlyTg0_r1_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P1_TxDqDlyTg0_r1_p1_SHIFT (0U)
/*! TxDqDlyTg0_r1_p1 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P1_TxDqDlyTg0_r1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P1_TxDqDlyTg0_r1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P1_TxDqDlyTg0_r1_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R1_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P1_TxDqDlyTg1_r1_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P1_TxDqDlyTg1_r1_p1_SHIFT (0U)
/*! TxDqDlyTg1_r1_p1 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P1_TxDqDlyTg1_r1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P1_TxDqDlyTg1_r1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P1_TxDqDlyTg1_r1_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R1_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P1_TxDqDlyTg2_r1_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P1_TxDqDlyTg2_r1_p1_SHIFT (0U)
/*! TxDqDlyTg2_r1_p1 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P1_TxDqDlyTg2_r1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P1_TxDqDlyTg2_r1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P1_TxDqDlyTg2_r1_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R1_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P1_TxDqDlyTg3_r1_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P1_TxDqDlyTg3_r1_p1_SHIFT (0U)
/*! TxDqDlyTg3_r1_p1 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P1_TxDqDlyTg3_r1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P1_TxDqDlyTg3_r1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P1_TxDqDlyTg3_r1_p1_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U1_P1 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P1_TxDqsDlyTg0_u1_p1_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P1_TxDqsDlyTg0_u1_p1_SHIFT (0U)
/*! TxDqsDlyTg0_u1_p1 - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P1_TxDqsDlyTg0_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P1_TxDqsDlyTg0_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P1_TxDqsDlyTg0_u1_p1_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U1_P1 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P1_TxDqsDlyTg1_u1_p1_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P1_TxDqsDlyTg1_u1_p1_SHIFT (0U)
/*! TxDqsDlyTg1_u1_p1 - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P1_TxDqsDlyTg1_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P1_TxDqsDlyTg1_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P1_TxDqsDlyTg1_u1_p1_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U1_P1 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P1_TxDqsDlyTg2_u1_p1_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P1_TxDqsDlyTg2_u1_p1_SHIFT (0U)
/*! TxDqsDlyTg2_u1_p1 - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P1_TxDqsDlyTg2_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P1_TxDqsDlyTg2_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P1_TxDqsDlyTg2_u1_p1_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U1_P1 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P1_TxDqsDlyTg3_u1_p1_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P1_TxDqsDlyTg3_u1_p1_SHIFT (0U)
/*! TxDqsDlyTg3_u1_p1 - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P1_TxDqsDlyTg3_u1_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P1_TxDqsDlyTg3_u1_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P1_TxDqsDlyTg3_u1_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R2_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P1_TxDqDlyTg0_r2_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P1_TxDqDlyTg0_r2_p1_SHIFT (0U)
/*! TxDqDlyTg0_r2_p1 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P1_TxDqDlyTg0_r2_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P1_TxDqDlyTg0_r2_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P1_TxDqDlyTg0_r2_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R2_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P1_TxDqDlyTg1_r2_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P1_TxDqDlyTg1_r2_p1_SHIFT (0U)
/*! TxDqDlyTg1_r2_p1 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P1_TxDqDlyTg1_r2_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P1_TxDqDlyTg1_r2_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P1_TxDqDlyTg1_r2_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R2_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P1_TxDqDlyTg2_r2_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P1_TxDqDlyTg2_r2_p1_SHIFT (0U)
/*! TxDqDlyTg2_r2_p1 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P1_TxDqDlyTg2_r2_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P1_TxDqDlyTg2_r2_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P1_TxDqDlyTg2_r2_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R2_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P1_TxDqDlyTg3_r2_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P1_TxDqDlyTg3_r2_p1_SHIFT (0U)
/*! TxDqDlyTg3_r2_p1 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P1_TxDqDlyTg3_r2_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P1_TxDqDlyTg3_r2_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P1_TxDqDlyTg3_r2_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R3_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P1_TxDqDlyTg0_r3_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P1_TxDqDlyTg0_r3_p1_SHIFT (0U)
/*! TxDqDlyTg0_r3_p1 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P1_TxDqDlyTg0_r3_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P1_TxDqDlyTg0_r3_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P1_TxDqDlyTg0_r3_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R3_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P1_TxDqDlyTg1_r3_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P1_TxDqDlyTg1_r3_p1_SHIFT (0U)
/*! TxDqDlyTg1_r3_p1 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P1_TxDqDlyTg1_r3_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P1_TxDqDlyTg1_r3_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P1_TxDqDlyTg1_r3_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R3_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P1_TxDqDlyTg2_r3_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P1_TxDqDlyTg2_r3_p1_SHIFT (0U)
/*! TxDqDlyTg2_r3_p1 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P1_TxDqDlyTg2_r3_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P1_TxDqDlyTg2_r3_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P1_TxDqDlyTg2_r3_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R3_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P1_TxDqDlyTg3_r3_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P1_TxDqDlyTg3_r3_p1_SHIFT (0U)
/*! TxDqDlyTg3_r3_p1 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P1_TxDqDlyTg3_r3_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P1_TxDqDlyTg3_r3_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P1_TxDqDlyTg3_r3_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R4_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P1_TxDqDlyTg0_r4_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P1_TxDqDlyTg0_r4_p1_SHIFT (0U)
/*! TxDqDlyTg0_r4_p1 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P1_TxDqDlyTg0_r4_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P1_TxDqDlyTg0_r4_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P1_TxDqDlyTg0_r4_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R4_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P1_TxDqDlyTg1_r4_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P1_TxDqDlyTg1_r4_p1_SHIFT (0U)
/*! TxDqDlyTg1_r4_p1 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P1_TxDqDlyTg1_r4_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P1_TxDqDlyTg1_r4_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P1_TxDqDlyTg1_r4_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R4_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P1_TxDqDlyTg2_r4_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P1_TxDqDlyTg2_r4_p1_SHIFT (0U)
/*! TxDqDlyTg2_r4_p1 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P1_TxDqDlyTg2_r4_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P1_TxDqDlyTg2_r4_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P1_TxDqDlyTg2_r4_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R4_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P1_TxDqDlyTg3_r4_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P1_TxDqDlyTg3_r4_p1_SHIFT (0U)
/*! TxDqDlyTg3_r4_p1 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P1_TxDqDlyTg3_r4_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P1_TxDqDlyTg3_r4_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P1_TxDqDlyTg3_r4_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R5_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P1_TxDqDlyTg0_r5_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P1_TxDqDlyTg0_r5_p1_SHIFT (0U)
/*! TxDqDlyTg0_r5_p1 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P1_TxDqDlyTg0_r5_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P1_TxDqDlyTg0_r5_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P1_TxDqDlyTg0_r5_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R5_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P1_TxDqDlyTg1_r5_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P1_TxDqDlyTg1_r5_p1_SHIFT (0U)
/*! TxDqDlyTg1_r5_p1 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P1_TxDqDlyTg1_r5_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P1_TxDqDlyTg1_r5_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P1_TxDqDlyTg1_r5_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R5_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P1_TxDqDlyTg2_r5_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P1_TxDqDlyTg2_r5_p1_SHIFT (0U)
/*! TxDqDlyTg2_r5_p1 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P1_TxDqDlyTg2_r5_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P1_TxDqDlyTg2_r5_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P1_TxDqDlyTg2_r5_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R5_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P1_TxDqDlyTg3_r5_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P1_TxDqDlyTg3_r5_p1_SHIFT (0U)
/*! TxDqDlyTg3_r5_p1 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P1_TxDqDlyTg3_r5_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P1_TxDqDlyTg3_r5_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P1_TxDqDlyTg3_r5_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R6_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P1_TxDqDlyTg0_r6_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P1_TxDqDlyTg0_r6_p1_SHIFT (0U)
/*! TxDqDlyTg0_r6_p1 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P1_TxDqDlyTg0_r6_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P1_TxDqDlyTg0_r6_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P1_TxDqDlyTg0_r6_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R6_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P1_TxDqDlyTg1_r6_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P1_TxDqDlyTg1_r6_p1_SHIFT (0U)
/*! TxDqDlyTg1_r6_p1 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P1_TxDqDlyTg1_r6_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P1_TxDqDlyTg1_r6_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P1_TxDqDlyTg1_r6_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R6_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P1_TxDqDlyTg2_r6_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P1_TxDqDlyTg2_r6_p1_SHIFT (0U)
/*! TxDqDlyTg2_r6_p1 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P1_TxDqDlyTg2_r6_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P1_TxDqDlyTg2_r6_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P1_TxDqDlyTg2_r6_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R6_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P1_TxDqDlyTg3_r6_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P1_TxDqDlyTg3_r6_p1_SHIFT (0U)
/*! TxDqDlyTg3_r6_p1 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P1_TxDqDlyTg3_r6_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P1_TxDqDlyTg3_r6_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P1_TxDqDlyTg3_r6_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R7_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P1_TxDqDlyTg0_r7_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P1_TxDqDlyTg0_r7_p1_SHIFT (0U)
/*! TxDqDlyTg0_r7_p1 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P1_TxDqDlyTg0_r7_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P1_TxDqDlyTg0_r7_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P1_TxDqDlyTg0_r7_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R7_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P1_TxDqDlyTg1_r7_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P1_TxDqDlyTg1_r7_p1_SHIFT (0U)
/*! TxDqDlyTg1_r7_p1 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P1_TxDqDlyTg1_r7_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P1_TxDqDlyTg1_r7_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P1_TxDqDlyTg1_r7_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R7_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P1_TxDqDlyTg2_r7_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P1_TxDqDlyTg2_r7_p1_SHIFT (0U)
/*! TxDqDlyTg2_r7_p1 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P1_TxDqDlyTg2_r7_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P1_TxDqDlyTg2_r7_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P1_TxDqDlyTg2_r7_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R7_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P1_TxDqDlyTg3_r7_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P1_TxDqDlyTg3_r7_p1_SHIFT (0U)
/*! TxDqDlyTg3_r7_p1 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P1_TxDqDlyTg3_r7_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P1_TxDqDlyTg3_r7_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P1_TxDqDlyTg3_r7_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R8_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P1_TxDqDlyTg0_r8_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P1_TxDqDlyTg0_r8_p1_SHIFT (0U)
/*! TxDqDlyTg0_r8_p1 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P1_TxDqDlyTg0_r8_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P1_TxDqDlyTg0_r8_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P1_TxDqDlyTg0_r8_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R8_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P1_TxDqDlyTg1_r8_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P1_TxDqDlyTg1_r8_p1_SHIFT (0U)
/*! TxDqDlyTg1_r8_p1 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P1_TxDqDlyTg1_r8_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P1_TxDqDlyTg1_r8_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P1_TxDqDlyTg1_r8_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R8_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P1_TxDqDlyTg2_r8_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P1_TxDqDlyTg2_r8_p1_SHIFT (0U)
/*! TxDqDlyTg2_r8_p1 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P1_TxDqDlyTg2_r8_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P1_TxDqDlyTg2_r8_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P1_TxDqDlyTg2_r8_p1_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R8_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P1_TxDqDlyTg3_r8_p1_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P1_TxDqDlyTg3_r8_p1_SHIFT (0U)
/*! TxDqDlyTg3_r8_p1 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P1_TxDqDlyTg3_r8_p1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P1_TxDqDlyTg3_r8_p1_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P1_TxDqDlyTg3_r8_p1_MASK)
/*! @} */

/*! @name USEDQSENREPLICA_P2 - Enable DqsEnArVIO Delay Matching Path */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P2_UseDqsEnReplica_p2_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P2_UseDqsEnReplica_p2_SHIFT (0U)
/*! UseDqsEnReplica_p2 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P2_UseDqsEnReplica_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P2_UseDqsEnReplica_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P2_UseDqsEnReplica_p2_MASK)
/*! @} */

/*! @name DFIMRL_P2 - DFI MaxReadLatency */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DFIMRL_P2_DFIMRL_p2_MASK (0x1FU)
#define DWC_DDRPHYA_DBYTE_DFIMRL_P2_DFIMRL_p2_SHIFT (0U)
/*! DFIMRL_p2 - This Max Read Latency CSR is to be trained to ensure the rx-data fifo is not read
 *    until after all dbytes have their read data valid.
 */
#define DWC_DDRPHYA_DBYTE_DFIMRL_P2_DFIMRL_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DFIMRL_P2_DFIMRL_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_DFIMRL_P2_DFIMRL_p2_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL0_B0_P2 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqN_MASK)
/*! @} */

/*! @name DQDQSRCVCNTRL_B0_P2 - Dq/Dqs receiver control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_SelAnalogVref_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_SelAnalogVref_SHIFT (0U)
/*! SelAnalogVref - Setting this signal high will force the local per-bit VREF generator to pass the global VREFA to the samplers. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_SelAnalogVref(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_SelAnalogVref_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_SelAnalogVref_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_ExtVrefRange_MASK (0x2U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_ExtVrefRange_SHIFT (1U)
/*! ExtVrefRange - Extends the range available in the local per-bit VREF generator. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_ExtVrefRange(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_ExtVrefRange_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_ExtVrefRange_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_DfeCtrl_MASK (0xCU)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_DfeCtrl_SHIFT (2U)
/*! DfeCtrl - This field is programmable as follows - 00 - DFE off - 01 - DFE on - 10 - Train DFE0
 *    Amplifier - 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
 *    should not be overridden.
 */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_DfeCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_DfeCtrl_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_DfeCtrl_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_MajorModeDbyte_MASK (0x70U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_MajorModeDbyte_SHIFT (4U)
/*! MajorModeDbyte - Selects the major mode of operation for the receiver. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_MajorModeDbyte(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_MajorModeDbyte_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_MajorModeDbyte_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_GainCurrAdj_MASK (0xF80U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_GainCurrAdj_SHIFT (7U)
/*! GainCurrAdj - Adjust gain current of RX amplifier stage. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_GainCurrAdj(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_GainCurrAdj_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P2_GainCurrAdj_MASK)
/*! @} */

/*! @name TXEQUALIZATIONMODE_P2 - Tx dq driver equalization mode controls. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P2_TxEqMode_MASK (0x3U)
#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P2_TxEqMode_SHIFT (0U)
/*! TxEqMode - Tx dq driver equalization mode controls. */
#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P2_TxEqMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P2_TxEqMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P2_TxEqMode_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL1_B0_P2 - TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqP_SHIFT (0U)
/*! DrvStrenFSDqP - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B0_P2 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQLoDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQLoDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQLoDqN_MASK)
/*! @} */

/*! @name DQDQSRCVCNTRL2_P2 - Dq/Dqs receiver control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P2_EnRxAgressivePDR_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P2_EnRxAgressivePDR_SHIFT (0U)
/*! EnRxAgressivePDR - reserved */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P2_EnRxAgressivePDR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P2_EnRxAgressivePDR_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P2_EnRxAgressivePDR_MASK)
/*! @} */

/*! @name TXODTDRVSTREN_B0_P2 - TX ODT driver strength control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P2_ODTStrenP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P2_ODTStrenP_SHIFT (0U)
/*! ODTStrenP - Selects the ODT pull-up impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P2_ODTStrenP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P2_ODTStrenP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P2_ODTStrenP_MASK)

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P2_ODTStrenN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P2_ODTStrenN_SHIFT (6U)
/*! ODTStrenN - Selects the ODT pull-down impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P2_ODTStrenN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P2_ODTStrenN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P2_ODTStrenN_MASK)
/*! @} */

/*! @name TXSLEWRATE_B0_P2 - TX slew rate controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreP_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreP_SHIFT (0U)
/*! TxPreP - This is the 4-bit binary trim for the driver pull up slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreP_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreN_MASK (0xF0U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreN_SHIFT (4U)
/*! TxPreN - 4 bit binary trim for the driver pull down slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreN_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreDrvMode_MASK (0x700U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreDrvMode_SHIFT (8U)
/*! TxPreDrvMode - Controls predrivers to adjust timing of turn-on and turn-off of pull-up and pull-down segments. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreDrvMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreDrvMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P2_TxPreDrvMode_MASK)
/*! @} */

/*! @name RXENDLYTG0_U0_P2 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P2_RxEnDlyTg0_u0_p2_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P2_RxEnDlyTg0_u0_p2_SHIFT (0U)
/*! RxEnDlyTg0_u0_p2 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P2_RxEnDlyTg0_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P2_RxEnDlyTg0_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P2_RxEnDlyTg0_u0_p2_MASK)
/*! @} */

/*! @name RXENDLYTG1_U0_P2 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P2_RxEnDlyTg1_u0_p2_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P2_RxEnDlyTg1_u0_p2_SHIFT (0U)
/*! RxEnDlyTg1_u0_p2 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P2_RxEnDlyTg1_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P2_RxEnDlyTg1_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P2_RxEnDlyTg1_u0_p2_MASK)
/*! @} */

/*! @name RXENDLYTG2_U0_P2 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P2_RxEnDlyTg2_u0_p2_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P2_RxEnDlyTg2_u0_p2_SHIFT (0U)
/*! RxEnDlyTg2_u0_p2 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P2_RxEnDlyTg2_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P2_RxEnDlyTg2_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P2_RxEnDlyTg2_u0_p2_MASK)
/*! @} */

/*! @name RXENDLYTG3_U0_P2 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P2_RxEnDlyTg3_u0_p2_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P2_RxEnDlyTg3_u0_p2_SHIFT (0U)
/*! RxEnDlyTg3_u0_p2 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P2_RxEnDlyTg3_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P2_RxEnDlyTg3_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P2_RxEnDlyTg3_u0_p2_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U0_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P2_RxClkDlyTg0_u0_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P2_RxClkDlyTg0_u0_p2_SHIFT (0U)
/*! RxClkDlyTg0_u0_p2 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P2_RxClkDlyTg0_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P2_RxClkDlyTg0_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P2_RxClkDlyTg0_u0_p2_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U0_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P2_RxClkDlyTg1_u0_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P2_RxClkDlyTg1_u0_p2_SHIFT (0U)
/*! RxClkDlyTg1_u0_p2 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P2_RxClkDlyTg1_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P2_RxClkDlyTg1_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P2_RxClkDlyTg1_u0_p2_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U0_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P2_RxClkDlyTg2_u0_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P2_RxClkDlyTg2_u0_p2_SHIFT (0U)
/*! RxClkDlyTg2_u0_p2 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P2_RxClkDlyTg2_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P2_RxClkDlyTg2_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P2_RxClkDlyTg2_u0_p2_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U0_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P2_RxClkDlyTg3_u0_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P2_RxClkDlyTg3_u0_p2_SHIFT (0U)
/*! RxClkDlyTg3_u0_p2 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P2_RxClkDlyTg3_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P2_RxClkDlyTg3_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P2_RxClkDlyTg3_u0_p2_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U0_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P2_RxClkcDlyTg0_u0_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P2_RxClkcDlyTg0_u0_p2_SHIFT (0U)
/*! RxClkcDlyTg0_u0_p2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P2_RxClkcDlyTg0_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P2_RxClkcDlyTg0_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P2_RxClkcDlyTg0_u0_p2_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U0_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P2_RxClkcDlyTg1_u0_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P2_RxClkcDlyTg1_u0_p2_SHIFT (0U)
/*! RxClkcDlyTg1_u0_p2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P2_RxClkcDlyTg1_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P2_RxClkcDlyTg1_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P2_RxClkcDlyTg1_u0_p2_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U0_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P2_RxClkcDlyTg2_u0_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P2_RxClkcDlyTg2_u0_p2_SHIFT (0U)
/*! RxClkcDlyTg2_u0_p2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P2_RxClkcDlyTg2_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P2_RxClkcDlyTg2_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P2_RxClkcDlyTg2_u0_p2_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U0_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P2_RxClkcDlyTg3_u0_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P2_RxClkcDlyTg3_u0_p2_SHIFT (0U)
/*! RxClkcDlyTg3_u0_p2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P2_RxClkcDlyTg3_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P2_RxClkcDlyTg3_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P2_RxClkcDlyTg3_u0_p2_MASK)
/*! @} */

/*! @name PPTDQSCNTINVTRNTG0_P2 - DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P2_PptDqsCntInvTrnTg0_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P2_PptDqsCntInvTrnTg0_p2_SHIFT (0U)
/*! PptDqsCntInvTrnTg0_p2 - Programmed by PHY training firmware to support LPDDR3/LPDDR4 DRAM drift compensation. */
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P2_PptDqsCntInvTrnTg0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P2_PptDqsCntInvTrnTg0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P2_PptDqsCntInvTrnTg0_p2_MASK)
/*! @} */

/*! @name PPTDQSCNTINVTRNTG1_P2 - DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P2_PptDqsCntInvTrnTg1_p2_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P2_PptDqsCntInvTrnTg1_p2_SHIFT (0U)
/*! PptDqsCntInvTrnTg1_p2 - Programmed by PHY training firmware to support LPDDR3/LPDDR4 DRAM drift compensation. */
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P2_PptDqsCntInvTrnTg1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P2_PptDqsCntInvTrnTg1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P2_PptDqsCntInvTrnTg1_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R0_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P2_TxDqDlyTg0_r0_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P2_TxDqDlyTg0_r0_p2_SHIFT (0U)
/*! TxDqDlyTg0_r0_p2 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P2_TxDqDlyTg0_r0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P2_TxDqDlyTg0_r0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P2_TxDqDlyTg0_r0_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R0_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P2_TxDqDlyTg1_r0_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P2_TxDqDlyTg1_r0_p2_SHIFT (0U)
/*! TxDqDlyTg1_r0_p2 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P2_TxDqDlyTg1_r0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P2_TxDqDlyTg1_r0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P2_TxDqDlyTg1_r0_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R0_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P2_TxDqDlyTg2_r0_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P2_TxDqDlyTg2_r0_p2_SHIFT (0U)
/*! TxDqDlyTg2_r0_p2 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P2_TxDqDlyTg2_r0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P2_TxDqDlyTg2_r0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P2_TxDqDlyTg2_r0_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R0_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P2_TxDqDlyTg3_r0_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P2_TxDqDlyTg3_r0_p2_SHIFT (0U)
/*! TxDqDlyTg3_r0_p2 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P2_TxDqDlyTg3_r0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P2_TxDqDlyTg3_r0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P2_TxDqDlyTg3_r0_p2_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U0_P2 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P2_TxDqsDlyTg0_u0_p2_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P2_TxDqsDlyTg0_u0_p2_SHIFT (0U)
/*! TxDqsDlyTg0_u0_p2 - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P2_TxDqsDlyTg0_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P2_TxDqsDlyTg0_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P2_TxDqsDlyTg0_u0_p2_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U0_P2 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P2_TxDqsDlyTg1_u0_p2_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P2_TxDqsDlyTg1_u0_p2_SHIFT (0U)
/*! TxDqsDlyTg1_u0_p2 - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P2_TxDqsDlyTg1_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P2_TxDqsDlyTg1_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P2_TxDqsDlyTg1_u0_p2_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U0_P2 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P2_TxDqsDlyTg2_u0_p2_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P2_TxDqsDlyTg2_u0_p2_SHIFT (0U)
/*! TxDqsDlyTg2_u0_p2 - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P2_TxDqsDlyTg2_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P2_TxDqsDlyTg2_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P2_TxDqsDlyTg2_u0_p2_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U0_P2 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P2_TxDqsDlyTg3_u0_p2_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P2_TxDqsDlyTg3_u0_p2_SHIFT (0U)
/*! TxDqsDlyTg3_u0_p2 - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P2_TxDqsDlyTg3_u0_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P2_TxDqsDlyTg3_u0_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P2_TxDqsDlyTg3_u0_p2_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL0_B1_P2 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqN_MASK)
/*! @} */

/*! @name DQDQSRCVCNTRL_B1_P2 - Dq/Dqs receiver control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_SelAnalogVref_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_SelAnalogVref_SHIFT (0U)
/*! SelAnalogVref - Setting this signal high will force the local per-bit VREF generator to pass the global VREFA to the samplers. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_SelAnalogVref(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_SelAnalogVref_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_SelAnalogVref_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_ExtVrefRange_MASK (0x2U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_ExtVrefRange_SHIFT (1U)
/*! ExtVrefRange - Extends the range available in the local per-bit VREF generator. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_ExtVrefRange(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_ExtVrefRange_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_ExtVrefRange_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_DfeCtrl_MASK (0xCU)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_DfeCtrl_SHIFT (2U)
/*! DfeCtrl - This field is programmable as follows - 00 - DFE off - 01 - DFE on - 10 - Train DFE0
 *    Amplifier - 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
 *    should not be overridden.
 */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_DfeCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_DfeCtrl_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_DfeCtrl_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_MajorModeDbyte_MASK (0x70U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_MajorModeDbyte_SHIFT (4U)
/*! MajorModeDbyte - Selects the major mode of operation for the receiver. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_MajorModeDbyte(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_MajorModeDbyte_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_MajorModeDbyte_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_GainCurrAdj_MASK (0xF80U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_GainCurrAdj_SHIFT (7U)
/*! GainCurrAdj - Adjust gain current of RX amplifier stage. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_GainCurrAdj(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_GainCurrAdj_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P2_GainCurrAdj_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL1_B1_P2 - TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqP_SHIFT (0U)
/*! DrvStrenFSDqP - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B1_P2 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQLoDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQLoDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQLoDqN_MASK)
/*! @} */

/*! @name TXODTDRVSTREN_B1_P2 - TX ODT driver strength control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P2_ODTStrenP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P2_ODTStrenP_SHIFT (0U)
/*! ODTStrenP - Selects the ODT pull-up impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P2_ODTStrenP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P2_ODTStrenP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P2_ODTStrenP_MASK)

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P2_ODTStrenN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P2_ODTStrenN_SHIFT (6U)
/*! ODTStrenN - Selects the ODT pull-down impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P2_ODTStrenN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P2_ODTStrenN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P2_ODTStrenN_MASK)
/*! @} */

/*! @name TXSLEWRATE_B1_P2 - TX slew rate controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreP_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreP_SHIFT (0U)
/*! TxPreP - This is the 4-bit binary trim for the driver pull up slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreP_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreN_MASK (0xF0U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreN_SHIFT (4U)
/*! TxPreN - 4 bit binary trim for the driver pull down slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreN_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreDrvMode_MASK (0x700U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreDrvMode_SHIFT (8U)
/*! TxPreDrvMode - Controls predrivers to adjust timing of turn-on and turn-off of pull-up and pull-down segments. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreDrvMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreDrvMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P2_TxPreDrvMode_MASK)
/*! @} */

/*! @name RXENDLYTG0_U1_P2 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P2_RxEnDlyTg0_u1_p2_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P2_RxEnDlyTg0_u1_p2_SHIFT (0U)
/*! RxEnDlyTg0_u1_p2 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P2_RxEnDlyTg0_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P2_RxEnDlyTg0_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P2_RxEnDlyTg0_u1_p2_MASK)
/*! @} */

/*! @name RXENDLYTG1_U1_P2 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P2_RxEnDlyTg1_u1_p2_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P2_RxEnDlyTg1_u1_p2_SHIFT (0U)
/*! RxEnDlyTg1_u1_p2 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P2_RxEnDlyTg1_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P2_RxEnDlyTg1_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P2_RxEnDlyTg1_u1_p2_MASK)
/*! @} */

/*! @name RXENDLYTG2_U1_P2 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P2_RxEnDlyTg2_u1_p2_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P2_RxEnDlyTg2_u1_p2_SHIFT (0U)
/*! RxEnDlyTg2_u1_p2 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P2_RxEnDlyTg2_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P2_RxEnDlyTg2_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P2_RxEnDlyTg2_u1_p2_MASK)
/*! @} */

/*! @name RXENDLYTG3_U1_P2 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P2_RxEnDlyTg3_u1_p2_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P2_RxEnDlyTg3_u1_p2_SHIFT (0U)
/*! RxEnDlyTg3_u1_p2 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P2_RxEnDlyTg3_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P2_RxEnDlyTg3_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P2_RxEnDlyTg3_u1_p2_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U1_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P2_RxClkDlyTg0_u1_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P2_RxClkDlyTg0_u1_p2_SHIFT (0U)
/*! RxClkDlyTg0_u1_p2 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P2_RxClkDlyTg0_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P2_RxClkDlyTg0_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P2_RxClkDlyTg0_u1_p2_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U1_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P2_RxClkDlyTg1_u1_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P2_RxClkDlyTg1_u1_p2_SHIFT (0U)
/*! RxClkDlyTg1_u1_p2 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P2_RxClkDlyTg1_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P2_RxClkDlyTg1_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P2_RxClkDlyTg1_u1_p2_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U1_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P2_RxClkDlyTg2_u1_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P2_RxClkDlyTg2_u1_p2_SHIFT (0U)
/*! RxClkDlyTg2_u1_p2 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P2_RxClkDlyTg2_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P2_RxClkDlyTg2_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P2_RxClkDlyTg2_u1_p2_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U1_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P2_RxClkDlyTg3_u1_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P2_RxClkDlyTg3_u1_p2_SHIFT (0U)
/*! RxClkDlyTg3_u1_p2 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P2_RxClkDlyTg3_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P2_RxClkDlyTg3_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P2_RxClkDlyTg3_u1_p2_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U1_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P2_RxClkcDlyTg0_u1_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P2_RxClkcDlyTg0_u1_p2_SHIFT (0U)
/*! RxClkcDlyTg0_u1_p2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P2_RxClkcDlyTg0_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P2_RxClkcDlyTg0_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P2_RxClkcDlyTg0_u1_p2_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U1_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P2_RxClkcDlyTg1_u1_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P2_RxClkcDlyTg1_u1_p2_SHIFT (0U)
/*! RxClkcDlyTg1_u1_p2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P2_RxClkcDlyTg1_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P2_RxClkcDlyTg1_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P2_RxClkcDlyTg1_u1_p2_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U1_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P2_RxClkcDlyTg2_u1_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P2_RxClkcDlyTg2_u1_p2_SHIFT (0U)
/*! RxClkcDlyTg2_u1_p2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P2_RxClkcDlyTg2_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P2_RxClkcDlyTg2_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P2_RxClkcDlyTg2_u1_p2_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U1_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P2_RxClkcDlyTg3_u1_p2_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P2_RxClkcDlyTg3_u1_p2_SHIFT (0U)
/*! RxClkcDlyTg3_u1_p2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P2_RxClkcDlyTg3_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P2_RxClkcDlyTg3_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P2_RxClkcDlyTg3_u1_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R1_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P2_TxDqDlyTg0_r1_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P2_TxDqDlyTg0_r1_p2_SHIFT (0U)
/*! TxDqDlyTg0_r1_p2 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P2_TxDqDlyTg0_r1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P2_TxDqDlyTg0_r1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P2_TxDqDlyTg0_r1_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R1_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P2_TxDqDlyTg1_r1_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P2_TxDqDlyTg1_r1_p2_SHIFT (0U)
/*! TxDqDlyTg1_r1_p2 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P2_TxDqDlyTg1_r1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P2_TxDqDlyTg1_r1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P2_TxDqDlyTg1_r1_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R1_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P2_TxDqDlyTg2_r1_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P2_TxDqDlyTg2_r1_p2_SHIFT (0U)
/*! TxDqDlyTg2_r1_p2 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P2_TxDqDlyTg2_r1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P2_TxDqDlyTg2_r1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P2_TxDqDlyTg2_r1_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R1_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P2_TxDqDlyTg3_r1_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P2_TxDqDlyTg3_r1_p2_SHIFT (0U)
/*! TxDqDlyTg3_r1_p2 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P2_TxDqDlyTg3_r1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P2_TxDqDlyTg3_r1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P2_TxDqDlyTg3_r1_p2_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U1_P2 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P2_TxDqsDlyTg0_u1_p2_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P2_TxDqsDlyTg0_u1_p2_SHIFT (0U)
/*! TxDqsDlyTg0_u1_p2 - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P2_TxDqsDlyTg0_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P2_TxDqsDlyTg0_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P2_TxDqsDlyTg0_u1_p2_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U1_P2 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P2_TxDqsDlyTg1_u1_p2_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P2_TxDqsDlyTg1_u1_p2_SHIFT (0U)
/*! TxDqsDlyTg1_u1_p2 - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P2_TxDqsDlyTg1_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P2_TxDqsDlyTg1_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P2_TxDqsDlyTg1_u1_p2_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U1_P2 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P2_TxDqsDlyTg2_u1_p2_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P2_TxDqsDlyTg2_u1_p2_SHIFT (0U)
/*! TxDqsDlyTg2_u1_p2 - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P2_TxDqsDlyTg2_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P2_TxDqsDlyTg2_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P2_TxDqsDlyTg2_u1_p2_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U1_P2 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P2_TxDqsDlyTg3_u1_p2_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P2_TxDqsDlyTg3_u1_p2_SHIFT (0U)
/*! TxDqsDlyTg3_u1_p2 - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P2_TxDqsDlyTg3_u1_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P2_TxDqsDlyTg3_u1_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P2_TxDqsDlyTg3_u1_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R2_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P2_TxDqDlyTg0_r2_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P2_TxDqDlyTg0_r2_p2_SHIFT (0U)
/*! TxDqDlyTg0_r2_p2 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P2_TxDqDlyTg0_r2_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P2_TxDqDlyTg0_r2_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P2_TxDqDlyTg0_r2_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R2_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P2_TxDqDlyTg1_r2_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P2_TxDqDlyTg1_r2_p2_SHIFT (0U)
/*! TxDqDlyTg1_r2_p2 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P2_TxDqDlyTg1_r2_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P2_TxDqDlyTg1_r2_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P2_TxDqDlyTg1_r2_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R2_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P2_TxDqDlyTg2_r2_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P2_TxDqDlyTg2_r2_p2_SHIFT (0U)
/*! TxDqDlyTg2_r2_p2 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P2_TxDqDlyTg2_r2_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P2_TxDqDlyTg2_r2_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P2_TxDqDlyTg2_r2_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R2_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P2_TxDqDlyTg3_r2_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P2_TxDqDlyTg3_r2_p2_SHIFT (0U)
/*! TxDqDlyTg3_r2_p2 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P2_TxDqDlyTg3_r2_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P2_TxDqDlyTg3_r2_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P2_TxDqDlyTg3_r2_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R3_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P2_TxDqDlyTg0_r3_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P2_TxDqDlyTg0_r3_p2_SHIFT (0U)
/*! TxDqDlyTg0_r3_p2 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P2_TxDqDlyTg0_r3_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P2_TxDqDlyTg0_r3_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P2_TxDqDlyTg0_r3_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R3_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P2_TxDqDlyTg1_r3_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P2_TxDqDlyTg1_r3_p2_SHIFT (0U)
/*! TxDqDlyTg1_r3_p2 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P2_TxDqDlyTg1_r3_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P2_TxDqDlyTg1_r3_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P2_TxDqDlyTg1_r3_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R3_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P2_TxDqDlyTg2_r3_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P2_TxDqDlyTg2_r3_p2_SHIFT (0U)
/*! TxDqDlyTg2_r3_p2 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P2_TxDqDlyTg2_r3_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P2_TxDqDlyTg2_r3_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P2_TxDqDlyTg2_r3_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R3_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P2_TxDqDlyTg3_r3_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P2_TxDqDlyTg3_r3_p2_SHIFT (0U)
/*! TxDqDlyTg3_r3_p2 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P2_TxDqDlyTg3_r3_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P2_TxDqDlyTg3_r3_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P2_TxDqDlyTg3_r3_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R4_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P2_TxDqDlyTg0_r4_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P2_TxDqDlyTg0_r4_p2_SHIFT (0U)
/*! TxDqDlyTg0_r4_p2 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P2_TxDqDlyTg0_r4_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P2_TxDqDlyTg0_r4_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P2_TxDqDlyTg0_r4_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R4_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P2_TxDqDlyTg1_r4_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P2_TxDqDlyTg1_r4_p2_SHIFT (0U)
/*! TxDqDlyTg1_r4_p2 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P2_TxDqDlyTg1_r4_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P2_TxDqDlyTg1_r4_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P2_TxDqDlyTg1_r4_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R4_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P2_TxDqDlyTg2_r4_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P2_TxDqDlyTg2_r4_p2_SHIFT (0U)
/*! TxDqDlyTg2_r4_p2 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P2_TxDqDlyTg2_r4_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P2_TxDqDlyTg2_r4_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P2_TxDqDlyTg2_r4_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R4_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P2_TxDqDlyTg3_r4_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P2_TxDqDlyTg3_r4_p2_SHIFT (0U)
/*! TxDqDlyTg3_r4_p2 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P2_TxDqDlyTg3_r4_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P2_TxDqDlyTg3_r4_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P2_TxDqDlyTg3_r4_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R5_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P2_TxDqDlyTg0_r5_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P2_TxDqDlyTg0_r5_p2_SHIFT (0U)
/*! TxDqDlyTg0_r5_p2 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P2_TxDqDlyTg0_r5_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P2_TxDqDlyTg0_r5_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P2_TxDqDlyTg0_r5_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R5_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P2_TxDqDlyTg1_r5_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P2_TxDqDlyTg1_r5_p2_SHIFT (0U)
/*! TxDqDlyTg1_r5_p2 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P2_TxDqDlyTg1_r5_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P2_TxDqDlyTg1_r5_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P2_TxDqDlyTg1_r5_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R5_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P2_TxDqDlyTg2_r5_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P2_TxDqDlyTg2_r5_p2_SHIFT (0U)
/*! TxDqDlyTg2_r5_p2 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P2_TxDqDlyTg2_r5_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P2_TxDqDlyTg2_r5_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P2_TxDqDlyTg2_r5_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R5_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P2_TxDqDlyTg3_r5_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P2_TxDqDlyTg3_r5_p2_SHIFT (0U)
/*! TxDqDlyTg3_r5_p2 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P2_TxDqDlyTg3_r5_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P2_TxDqDlyTg3_r5_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P2_TxDqDlyTg3_r5_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R6_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P2_TxDqDlyTg0_r6_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P2_TxDqDlyTg0_r6_p2_SHIFT (0U)
/*! TxDqDlyTg0_r6_p2 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P2_TxDqDlyTg0_r6_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P2_TxDqDlyTg0_r6_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P2_TxDqDlyTg0_r6_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R6_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P2_TxDqDlyTg1_r6_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P2_TxDqDlyTg1_r6_p2_SHIFT (0U)
/*! TxDqDlyTg1_r6_p2 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P2_TxDqDlyTg1_r6_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P2_TxDqDlyTg1_r6_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P2_TxDqDlyTg1_r6_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R6_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P2_TxDqDlyTg2_r6_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P2_TxDqDlyTg2_r6_p2_SHIFT (0U)
/*! TxDqDlyTg2_r6_p2 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P2_TxDqDlyTg2_r6_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P2_TxDqDlyTg2_r6_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P2_TxDqDlyTg2_r6_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R6_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P2_TxDqDlyTg3_r6_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P2_TxDqDlyTg3_r6_p2_SHIFT (0U)
/*! TxDqDlyTg3_r6_p2 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P2_TxDqDlyTg3_r6_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P2_TxDqDlyTg3_r6_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P2_TxDqDlyTg3_r6_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R7_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P2_TxDqDlyTg0_r7_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P2_TxDqDlyTg0_r7_p2_SHIFT (0U)
/*! TxDqDlyTg0_r7_p2 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P2_TxDqDlyTg0_r7_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P2_TxDqDlyTg0_r7_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P2_TxDqDlyTg0_r7_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R7_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P2_TxDqDlyTg1_r7_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P2_TxDqDlyTg1_r7_p2_SHIFT (0U)
/*! TxDqDlyTg1_r7_p2 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P2_TxDqDlyTg1_r7_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P2_TxDqDlyTg1_r7_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P2_TxDqDlyTg1_r7_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R7_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P2_TxDqDlyTg2_r7_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P2_TxDqDlyTg2_r7_p2_SHIFT (0U)
/*! TxDqDlyTg2_r7_p2 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P2_TxDqDlyTg2_r7_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P2_TxDqDlyTg2_r7_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P2_TxDqDlyTg2_r7_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R7_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P2_TxDqDlyTg3_r7_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P2_TxDqDlyTg3_r7_p2_SHIFT (0U)
/*! TxDqDlyTg3_r7_p2 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P2_TxDqDlyTg3_r7_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P2_TxDqDlyTg3_r7_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P2_TxDqDlyTg3_r7_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R8_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P2_TxDqDlyTg0_r8_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P2_TxDqDlyTg0_r8_p2_SHIFT (0U)
/*! TxDqDlyTg0_r8_p2 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P2_TxDqDlyTg0_r8_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P2_TxDqDlyTg0_r8_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P2_TxDqDlyTg0_r8_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R8_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P2_TxDqDlyTg1_r8_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P2_TxDqDlyTg1_r8_p2_SHIFT (0U)
/*! TxDqDlyTg1_r8_p2 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P2_TxDqDlyTg1_r8_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P2_TxDqDlyTg1_r8_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P2_TxDqDlyTg1_r8_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R8_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P2_TxDqDlyTg2_r8_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P2_TxDqDlyTg2_r8_p2_SHIFT (0U)
/*! TxDqDlyTg2_r8_p2 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P2_TxDqDlyTg2_r8_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P2_TxDqDlyTg2_r8_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P2_TxDqDlyTg2_r8_p2_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R8_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P2_TxDqDlyTg3_r8_p2_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P2_TxDqDlyTg3_r8_p2_SHIFT (0U)
/*! TxDqDlyTg3_r8_p2 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P2_TxDqDlyTg3_r8_p2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P2_TxDqDlyTg3_r8_p2_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P2_TxDqDlyTg3_r8_p2_MASK)
/*! @} */

/*! @name USEDQSENREPLICA_P3 - Enable DqsEnArVIO Delay Matching Path */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P3_UseDqsEnReplica_p3_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P3_UseDqsEnReplica_p3_SHIFT (0U)
/*! UseDqsEnReplica_p3 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P3_UseDqsEnReplica_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P3_UseDqsEnReplica_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_USEDQSENREPLICA_P3_UseDqsEnReplica_p3_MASK)
/*! @} */

/*! @name DFIMRL_P3 - DFI MaxReadLatency */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DFIMRL_P3_DFIMRL_p3_MASK (0x1FU)
#define DWC_DDRPHYA_DBYTE_DFIMRL_P3_DFIMRL_p3_SHIFT (0U)
/*! DFIMRL_p3 - This Max Read Latency CSR is to be trained to ensure the rx-data fifo is not read
 *    until after all dbytes have their read data valid.
 */
#define DWC_DDRPHYA_DBYTE_DFIMRL_P3_DFIMRL_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DFIMRL_P3_DFIMRL_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_DFIMRL_P3_DFIMRL_p3_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL0_B0_P3 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqN_MASK)
/*! @} */

/*! @name DQDQSRCVCNTRL_B0_P3 - Dq/Dqs receiver control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_SelAnalogVref_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_SelAnalogVref_SHIFT (0U)
/*! SelAnalogVref - Setting this signal high will force the local per-bit VREF generator to pass the global VREFA to the samplers. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_SelAnalogVref(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_SelAnalogVref_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_SelAnalogVref_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_ExtVrefRange_MASK (0x2U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_ExtVrefRange_SHIFT (1U)
/*! ExtVrefRange - Extends the range available in the local per-bit VREF generator. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_ExtVrefRange(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_ExtVrefRange_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_ExtVrefRange_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_DfeCtrl_MASK (0xCU)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_DfeCtrl_SHIFT (2U)
/*! DfeCtrl - This field is programmable as follows - 00 - DFE off - 01 - DFE on - 10 - Train DFE0
 *    Amplifier - 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
 *    should not be overridden.
 */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_DfeCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_DfeCtrl_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_DfeCtrl_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_MajorModeDbyte_MASK (0x70U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_MajorModeDbyte_SHIFT (4U)
/*! MajorModeDbyte - Selects the major mode of operation for the receiver. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_MajorModeDbyte(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_MajorModeDbyte_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_MajorModeDbyte_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_GainCurrAdj_MASK (0xF80U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_GainCurrAdj_SHIFT (7U)
/*! GainCurrAdj - Adjust gain current of RX amplifier stage. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_GainCurrAdj(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_GainCurrAdj_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B0_P3_GainCurrAdj_MASK)
/*! @} */

/*! @name TXEQUALIZATIONMODE_P3 - Tx dq driver equalization mode controls. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P3_TxEqMode_MASK (0x3U)
#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P3_TxEqMode_SHIFT (0U)
/*! TxEqMode - Tx dq driver equalization mode controls. */
#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P3_TxEqMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P3_TxEqMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P3_TxEqMode_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL1_B0_P3 - TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqP_SHIFT (0U)
/*! DrvStrenFSDqP - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B0_P3 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQLoDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQLoDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQLoDqN_MASK)
/*! @} */

/*! @name DQDQSRCVCNTRL2_P3 - Dq/Dqs receiver control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P3_EnRxAgressivePDR_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P3_EnRxAgressivePDR_SHIFT (0U)
/*! EnRxAgressivePDR - reserved */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P3_EnRxAgressivePDR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P3_EnRxAgressivePDR_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL2_P3_EnRxAgressivePDR_MASK)
/*! @} */

/*! @name TXODTDRVSTREN_B0_P3 - TX ODT driver strength control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P3_ODTStrenP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P3_ODTStrenP_SHIFT (0U)
/*! ODTStrenP - Selects the ODT pull-up impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P3_ODTStrenP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P3_ODTStrenP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P3_ODTStrenP_MASK)

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P3_ODTStrenN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P3_ODTStrenN_SHIFT (6U)
/*! ODTStrenN - Selects the ODT pull-down impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P3_ODTStrenN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P3_ODTStrenN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B0_P3_ODTStrenN_MASK)
/*! @} */

/*! @name TXSLEWRATE_B0_P3 - TX slew rate controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreP_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreP_SHIFT (0U)
/*! TxPreP - This is the 4-bit binary trim for the driver pull up slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreP_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreN_MASK (0xF0U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreN_SHIFT (4U)
/*! TxPreN - 4 bit binary trim for the driver pull down slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreN_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreDrvMode_MASK (0x700U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreDrvMode_SHIFT (8U)
/*! TxPreDrvMode - Controls predrivers to adjust timing of turn-on and turn-off of pull-up and pull-down segments. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreDrvMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreDrvMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P3_TxPreDrvMode_MASK)
/*! @} */

/*! @name RXENDLYTG0_U0_P3 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P3_RxEnDlyTg0_u0_p3_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P3_RxEnDlyTg0_u0_p3_SHIFT (0U)
/*! RxEnDlyTg0_u0_p3 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P3_RxEnDlyTg0_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P3_RxEnDlyTg0_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P3_RxEnDlyTg0_u0_p3_MASK)
/*! @} */

/*! @name RXENDLYTG1_U0_P3 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P3_RxEnDlyTg1_u0_p3_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P3_RxEnDlyTg1_u0_p3_SHIFT (0U)
/*! RxEnDlyTg1_u0_p3 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P3_RxEnDlyTg1_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P3_RxEnDlyTg1_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P3_RxEnDlyTg1_u0_p3_MASK)
/*! @} */

/*! @name RXENDLYTG2_U0_P3 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P3_RxEnDlyTg2_u0_p3_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P3_RxEnDlyTg2_u0_p3_SHIFT (0U)
/*! RxEnDlyTg2_u0_p3 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P3_RxEnDlyTg2_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P3_RxEnDlyTg2_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P3_RxEnDlyTg2_u0_p3_MASK)
/*! @} */

/*! @name RXENDLYTG3_U0_P3 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P3_RxEnDlyTg3_u0_p3_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P3_RxEnDlyTg3_u0_p3_SHIFT (0U)
/*! RxEnDlyTg3_u0_p3 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P3_RxEnDlyTg3_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P3_RxEnDlyTg3_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P3_RxEnDlyTg3_u0_p3_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U0_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P3_RxClkDlyTg0_u0_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P3_RxClkDlyTg0_u0_p3_SHIFT (0U)
/*! RxClkDlyTg0_u0_p3 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P3_RxClkDlyTg0_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P3_RxClkDlyTg0_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P3_RxClkDlyTg0_u0_p3_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U0_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P3_RxClkDlyTg1_u0_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P3_RxClkDlyTg1_u0_p3_SHIFT (0U)
/*! RxClkDlyTg1_u0_p3 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P3_RxClkDlyTg1_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P3_RxClkDlyTg1_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P3_RxClkDlyTg1_u0_p3_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U0_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P3_RxClkDlyTg2_u0_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P3_RxClkDlyTg2_u0_p3_SHIFT (0U)
/*! RxClkDlyTg2_u0_p3 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P3_RxClkDlyTg2_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P3_RxClkDlyTg2_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P3_RxClkDlyTg2_u0_p3_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U0_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P3_RxClkDlyTg3_u0_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P3_RxClkDlyTg3_u0_p3_SHIFT (0U)
/*! RxClkDlyTg3_u0_p3 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P3_RxClkDlyTg3_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P3_RxClkDlyTg3_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P3_RxClkDlyTg3_u0_p3_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U0_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P3_RxClkcDlyTg0_u0_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P3_RxClkcDlyTg0_u0_p3_SHIFT (0U)
/*! RxClkcDlyTg0_u0_p3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P3_RxClkcDlyTg0_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P3_RxClkcDlyTg0_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P3_RxClkcDlyTg0_u0_p3_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U0_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P3_RxClkcDlyTg1_u0_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P3_RxClkcDlyTg1_u0_p3_SHIFT (0U)
/*! RxClkcDlyTg1_u0_p3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P3_RxClkcDlyTg1_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P3_RxClkcDlyTg1_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P3_RxClkcDlyTg1_u0_p3_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U0_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P3_RxClkcDlyTg2_u0_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P3_RxClkcDlyTg2_u0_p3_SHIFT (0U)
/*! RxClkcDlyTg2_u0_p3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P3_RxClkcDlyTg2_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P3_RxClkcDlyTg2_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P3_RxClkcDlyTg2_u0_p3_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U0_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P3_RxClkcDlyTg3_u0_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P3_RxClkcDlyTg3_u0_p3_SHIFT (0U)
/*! RxClkcDlyTg3_u0_p3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P3_RxClkcDlyTg3_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P3_RxClkcDlyTg3_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P3_RxClkcDlyTg3_u0_p3_MASK)
/*! @} */

/*! @name PPTDQSCNTINVTRNTG0_P3 - DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P3_PptDqsCntInvTrnTg0_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P3_PptDqsCntInvTrnTg0_p3_SHIFT (0U)
/*! PptDqsCntInvTrnTg0_p3 - Programmed by PHY training firmware to support LPDDR3/LPDDR4 DRAM drift compensation. */
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P3_PptDqsCntInvTrnTg0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P3_PptDqsCntInvTrnTg0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG0_P3_PptDqsCntInvTrnTg0_p3_MASK)
/*! @} */

/*! @name PPTDQSCNTINVTRNTG1_P3 - DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P3_PptDqsCntInvTrnTg1_p3_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P3_PptDqsCntInvTrnTg1_p3_SHIFT (0U)
/*! PptDqsCntInvTrnTg1_p3 - Programmed by PHY training firmware to support LPDDR3/LPDDR4 DRAM drift compensation. */
#define DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P3_PptDqsCntInvTrnTg1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P3_PptDqsCntInvTrnTg1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_PPTDQSCNTINVTRNTG1_P3_PptDqsCntInvTrnTg1_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R0_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P3_TxDqDlyTg0_r0_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P3_TxDqDlyTg0_r0_p3_SHIFT (0U)
/*! TxDqDlyTg0_r0_p3 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P3_TxDqDlyTg0_r0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P3_TxDqDlyTg0_r0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P3_TxDqDlyTg0_r0_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R0_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P3_TxDqDlyTg1_r0_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P3_TxDqDlyTg1_r0_p3_SHIFT (0U)
/*! TxDqDlyTg1_r0_p3 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P3_TxDqDlyTg1_r0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P3_TxDqDlyTg1_r0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P3_TxDqDlyTg1_r0_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R0_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P3_TxDqDlyTg2_r0_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P3_TxDqDlyTg2_r0_p3_SHIFT (0U)
/*! TxDqDlyTg2_r0_p3 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P3_TxDqDlyTg2_r0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P3_TxDqDlyTg2_r0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P3_TxDqDlyTg2_r0_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R0_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P3_TxDqDlyTg3_r0_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P3_TxDqDlyTg3_r0_p3_SHIFT (0U)
/*! TxDqDlyTg3_r0_p3 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P3_TxDqDlyTg3_r0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P3_TxDqDlyTg3_r0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P3_TxDqDlyTg3_r0_p3_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U0_P3 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P3_TxDqsDlyTg0_u0_p3_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P3_TxDqsDlyTg0_u0_p3_SHIFT (0U)
/*! TxDqsDlyTg0_u0_p3 - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P3_TxDqsDlyTg0_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P3_TxDqsDlyTg0_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P3_TxDqsDlyTg0_u0_p3_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U0_P3 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P3_TxDqsDlyTg1_u0_p3_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P3_TxDqsDlyTg1_u0_p3_SHIFT (0U)
/*! TxDqsDlyTg1_u0_p3 - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P3_TxDqsDlyTg1_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P3_TxDqsDlyTg1_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P3_TxDqsDlyTg1_u0_p3_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U0_P3 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P3_TxDqsDlyTg2_u0_p3_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P3_TxDqsDlyTg2_u0_p3_SHIFT (0U)
/*! TxDqsDlyTg2_u0_p3 - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P3_TxDqsDlyTg2_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P3_TxDqsDlyTg2_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P3_TxDqsDlyTg2_u0_p3_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U0_P3 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P3_TxDqsDlyTg3_u0_p3_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P3_TxDqsDlyTg3_u0_p3_SHIFT (0U)
/*! TxDqsDlyTg3_u0_p3 - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P3_TxDqsDlyTg3_u0_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P3_TxDqsDlyTg3_u0_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P3_TxDqsDlyTg3_u0_p3_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL0_B1_P3 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqN_MASK)
/*! @} */

/*! @name DQDQSRCVCNTRL_B1_P3 - Dq/Dqs receiver control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_SelAnalogVref_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_SelAnalogVref_SHIFT (0U)
/*! SelAnalogVref - Setting this signal high will force the local per-bit VREF generator to pass the global VREFA to the samplers. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_SelAnalogVref(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_SelAnalogVref_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_SelAnalogVref_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_ExtVrefRange_MASK (0x2U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_ExtVrefRange_SHIFT (1U)
/*! ExtVrefRange - Extends the range available in the local per-bit VREF generator. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_ExtVrefRange(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_ExtVrefRange_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_ExtVrefRange_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_DfeCtrl_MASK (0xCU)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_DfeCtrl_SHIFT (2U)
/*! DfeCtrl - This field is programmable as follows - 00 - DFE off - 01 - DFE on - 10 - Train DFE0
 *    Amplifier - 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
 *    should not be overridden.
 */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_DfeCtrl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_DfeCtrl_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_DfeCtrl_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_MajorModeDbyte_MASK (0x70U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_MajorModeDbyte_SHIFT (4U)
/*! MajorModeDbyte - Selects the major mode of operation for the receiver. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_MajorModeDbyte(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_MajorModeDbyte_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_MajorModeDbyte_MASK)

#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_GainCurrAdj_MASK (0xF80U)
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_GainCurrAdj_SHIFT (7U)
/*! GainCurrAdj - Adjust gain current of RX amplifier stage. */
#define DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_GainCurrAdj(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_GainCurrAdj_SHIFT)) & DWC_DDRPHYA_DBYTE_DQDQSRCVCNTRL_B1_P3_GainCurrAdj_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL1_B1_P3 - TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqP_SHIFT (0U)
/*! DrvStrenFSDqP - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Refer to Technology specific PHY Databook for supported options. */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B1_P3 - Reserved */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Reserved */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQLoDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQLoDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQLoDqN_MASK)
/*! @} */

/*! @name TXODTDRVSTREN_B1_P3 - TX ODT driver strength control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P3_ODTStrenP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P3_ODTStrenP_SHIFT (0U)
/*! ODTStrenP - Selects the ODT pull-up impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P3_ODTStrenP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P3_ODTStrenP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P3_ODTStrenP_MASK)

#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P3_ODTStrenN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P3_ODTStrenN_SHIFT (6U)
/*! ODTStrenN - Selects the ODT pull-down impedance. */
#define DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P3_ODTStrenN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P3_ODTStrenN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXODTDRVSTREN_B1_P3_ODTStrenN_MASK)
/*! @} */

/*! @name TXSLEWRATE_B1_P3 - TX slew rate controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreP_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreP_SHIFT (0U)
/*! TxPreP - This is the 4-bit binary trim for the driver pull up slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreP_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreN_MASK (0xF0U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreN_SHIFT (4U)
/*! TxPreN - 4 bit binary trim for the driver pull down slew rate. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreN_MASK)

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreDrvMode_MASK (0x700U)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreDrvMode_SHIFT (8U)
/*! TxPreDrvMode - Controls predrivers to adjust timing of turn-on and turn-off of pull-up and pull-down segments. */
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreDrvMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreDrvMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXSLEWRATE_B1_P3_TxPreDrvMode_MASK)
/*! @} */

/*! @name RXENDLYTG0_U1_P3 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P3_RxEnDlyTg0_u1_p3_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P3_RxEnDlyTg0_u1_p3_SHIFT (0U)
/*! RxEnDlyTg0_u1_p3 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P3_RxEnDlyTg0_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P3_RxEnDlyTg0_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P3_RxEnDlyTg0_u1_p3_MASK)
/*! @} */

/*! @name RXENDLYTG1_U1_P3 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P3_RxEnDlyTg1_u1_p3_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P3_RxEnDlyTg1_u1_p3_SHIFT (0U)
/*! RxEnDlyTg1_u1_p3 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P3_RxEnDlyTg1_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P3_RxEnDlyTg1_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P3_RxEnDlyTg1_u1_p3_MASK)
/*! @} */

/*! @name RXENDLYTG2_U1_P3 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P3_RxEnDlyTg2_u1_p3_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P3_RxEnDlyTg2_u1_p3_SHIFT (0U)
/*! RxEnDlyTg2_u1_p3 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P3_RxEnDlyTg2_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P3_RxEnDlyTg2_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P3_RxEnDlyTg2_u1_p3_MASK)
/*! @} */

/*! @name RXENDLYTG3_U1_P3 - Trained Receive Enable Delay. */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P3_RxEnDlyTg3_u1_p3_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P3_RxEnDlyTg3_u1_p3_SHIFT (0U)
/*! RxEnDlyTg3_u1_p3 - Trained Receive Enable Delay. */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P3_RxEnDlyTg3_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P3_RxEnDlyTg3_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P3_RxEnDlyTg3_u1_p3_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U1_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P3_RxClkDlyTg0_u1_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P3_RxClkDlyTg0_u1_p3_SHIFT (0U)
/*! RxClkDlyTg0_u1_p3 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P3_RxClkDlyTg0_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P3_RxClkDlyTg0_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P3_RxClkDlyTg0_u1_p3_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U1_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P3_RxClkDlyTg1_u1_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P3_RxClkDlyTg1_u1_p3_SHIFT (0U)
/*! RxClkDlyTg1_u1_p3 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P3_RxClkDlyTg1_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P3_RxClkDlyTg1_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P3_RxClkDlyTg1_u1_p3_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U1_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P3_RxClkDlyTg2_u1_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P3_RxClkDlyTg2_u1_p3_SHIFT (0U)
/*! RxClkDlyTg2_u1_p3 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P3_RxClkDlyTg2_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P3_RxClkDlyTg2_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P3_RxClkDlyTg2_u1_p3_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U1_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P3_RxClkDlyTg3_u1_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P3_RxClkDlyTg3_u1_p3_SHIFT (0U)
/*! RxClkDlyTg3_u1_p3 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P3_RxClkDlyTg3_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P3_RxClkDlyTg3_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P3_RxClkDlyTg3_u1_p3_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U1_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P3_RxClkcDlyTg0_u1_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P3_RxClkcDlyTg0_u1_p3_SHIFT (0U)
/*! RxClkcDlyTg0_u1_p3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P3_RxClkcDlyTg0_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P3_RxClkcDlyTg0_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P3_RxClkcDlyTg0_u1_p3_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U1_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P3_RxClkcDlyTg1_u1_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P3_RxClkcDlyTg1_u1_p3_SHIFT (0U)
/*! RxClkcDlyTg1_u1_p3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P3_RxClkcDlyTg1_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P3_RxClkcDlyTg1_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P3_RxClkcDlyTg1_u1_p3_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U1_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P3_RxClkcDlyTg2_u1_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P3_RxClkcDlyTg2_u1_p3_SHIFT (0U)
/*! RxClkcDlyTg2_u1_p3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P3_RxClkcDlyTg2_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P3_RxClkcDlyTg2_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P3_RxClkcDlyTg2_u1_p3_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U1_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P3_RxClkcDlyTg3_u1_p3_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P3_RxClkcDlyTg3_u1_p3_SHIFT (0U)
/*! RxClkcDlyTg3_u1_p3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P3_RxClkcDlyTg3_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P3_RxClkcDlyTg3_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P3_RxClkcDlyTg3_u1_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R1_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P3_TxDqDlyTg0_r1_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P3_TxDqDlyTg0_r1_p3_SHIFT (0U)
/*! TxDqDlyTg0_r1_p3 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P3_TxDqDlyTg0_r1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P3_TxDqDlyTg0_r1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P3_TxDqDlyTg0_r1_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R1_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P3_TxDqDlyTg1_r1_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P3_TxDqDlyTg1_r1_p3_SHIFT (0U)
/*! TxDqDlyTg1_r1_p3 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P3_TxDqDlyTg1_r1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P3_TxDqDlyTg1_r1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P3_TxDqDlyTg1_r1_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R1_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P3_TxDqDlyTg2_r1_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P3_TxDqDlyTg2_r1_p3_SHIFT (0U)
/*! TxDqDlyTg2_r1_p3 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P3_TxDqDlyTg2_r1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P3_TxDqDlyTg2_r1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P3_TxDqDlyTg2_r1_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R1_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P3_TxDqDlyTg3_r1_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P3_TxDqDlyTg3_r1_p3_SHIFT (0U)
/*! TxDqDlyTg3_r1_p3 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P3_TxDqDlyTg3_r1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P3_TxDqDlyTg3_r1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P3_TxDqDlyTg3_r1_p3_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U1_P3 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P3_TxDqsDlyTg0_u1_p3_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P3_TxDqsDlyTg0_u1_p3_SHIFT (0U)
/*! TxDqsDlyTg0_u1_p3 - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P3_TxDqsDlyTg0_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P3_TxDqsDlyTg0_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P3_TxDqsDlyTg0_u1_p3_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U1_P3 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P3_TxDqsDlyTg1_u1_p3_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P3_TxDqsDlyTg1_u1_p3_SHIFT (0U)
/*! TxDqsDlyTg1_u1_p3 - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P3_TxDqsDlyTg1_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P3_TxDqsDlyTg1_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P3_TxDqsDlyTg1_u1_p3_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U1_P3 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P3_TxDqsDlyTg2_u1_p3_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P3_TxDqsDlyTg2_u1_p3_SHIFT (0U)
/*! TxDqsDlyTg2_u1_p3 - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P3_TxDqsDlyTg2_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P3_TxDqsDlyTg2_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P3_TxDqsDlyTg2_u1_p3_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U1_P3 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P3_TxDqsDlyTg3_u1_p3_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P3_TxDqsDlyTg3_u1_p3_SHIFT (0U)
/*! TxDqsDlyTg3_u1_p3 - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P3_TxDqsDlyTg3_u1_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P3_TxDqsDlyTg3_u1_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P3_TxDqsDlyTg3_u1_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R2_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P3_TxDqDlyTg0_r2_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P3_TxDqDlyTg0_r2_p3_SHIFT (0U)
/*! TxDqDlyTg0_r2_p3 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P3_TxDqDlyTg0_r2_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P3_TxDqDlyTg0_r2_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P3_TxDqDlyTg0_r2_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R2_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P3_TxDqDlyTg1_r2_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P3_TxDqDlyTg1_r2_p3_SHIFT (0U)
/*! TxDqDlyTg1_r2_p3 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P3_TxDqDlyTg1_r2_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P3_TxDqDlyTg1_r2_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P3_TxDqDlyTg1_r2_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R2_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P3_TxDqDlyTg2_r2_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P3_TxDqDlyTg2_r2_p3_SHIFT (0U)
/*! TxDqDlyTg2_r2_p3 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P3_TxDqDlyTg2_r2_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P3_TxDqDlyTg2_r2_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P3_TxDqDlyTg2_r2_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R2_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P3_TxDqDlyTg3_r2_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P3_TxDqDlyTg3_r2_p3_SHIFT (0U)
/*! TxDqDlyTg3_r2_p3 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P3_TxDqDlyTg3_r2_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P3_TxDqDlyTg3_r2_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P3_TxDqDlyTg3_r2_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R3_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P3_TxDqDlyTg0_r3_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P3_TxDqDlyTg0_r3_p3_SHIFT (0U)
/*! TxDqDlyTg0_r3_p3 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P3_TxDqDlyTg0_r3_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P3_TxDqDlyTg0_r3_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P3_TxDqDlyTg0_r3_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R3_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P3_TxDqDlyTg1_r3_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P3_TxDqDlyTg1_r3_p3_SHIFT (0U)
/*! TxDqDlyTg1_r3_p3 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P3_TxDqDlyTg1_r3_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P3_TxDqDlyTg1_r3_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P3_TxDqDlyTg1_r3_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R3_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P3_TxDqDlyTg2_r3_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P3_TxDqDlyTg2_r3_p3_SHIFT (0U)
/*! TxDqDlyTg2_r3_p3 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P3_TxDqDlyTg2_r3_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P3_TxDqDlyTg2_r3_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P3_TxDqDlyTg2_r3_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R3_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P3_TxDqDlyTg3_r3_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P3_TxDqDlyTg3_r3_p3_SHIFT (0U)
/*! TxDqDlyTg3_r3_p3 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P3_TxDqDlyTg3_r3_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P3_TxDqDlyTg3_r3_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P3_TxDqDlyTg3_r3_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R4_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P3_TxDqDlyTg0_r4_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P3_TxDqDlyTg0_r4_p3_SHIFT (0U)
/*! TxDqDlyTg0_r4_p3 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P3_TxDqDlyTg0_r4_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P3_TxDqDlyTg0_r4_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P3_TxDqDlyTg0_r4_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R4_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P3_TxDqDlyTg1_r4_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P3_TxDqDlyTg1_r4_p3_SHIFT (0U)
/*! TxDqDlyTg1_r4_p3 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P3_TxDqDlyTg1_r4_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P3_TxDqDlyTg1_r4_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P3_TxDqDlyTg1_r4_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R4_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P3_TxDqDlyTg2_r4_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P3_TxDqDlyTg2_r4_p3_SHIFT (0U)
/*! TxDqDlyTg2_r4_p3 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P3_TxDqDlyTg2_r4_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P3_TxDqDlyTg2_r4_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P3_TxDqDlyTg2_r4_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R4_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P3_TxDqDlyTg3_r4_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P3_TxDqDlyTg3_r4_p3_SHIFT (0U)
/*! TxDqDlyTg3_r4_p3 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P3_TxDqDlyTg3_r4_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P3_TxDqDlyTg3_r4_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P3_TxDqDlyTg3_r4_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R5_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P3_TxDqDlyTg0_r5_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P3_TxDqDlyTg0_r5_p3_SHIFT (0U)
/*! TxDqDlyTg0_r5_p3 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P3_TxDqDlyTg0_r5_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P3_TxDqDlyTg0_r5_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P3_TxDqDlyTg0_r5_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R5_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P3_TxDqDlyTg1_r5_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P3_TxDqDlyTg1_r5_p3_SHIFT (0U)
/*! TxDqDlyTg1_r5_p3 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P3_TxDqDlyTg1_r5_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P3_TxDqDlyTg1_r5_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P3_TxDqDlyTg1_r5_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R5_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P3_TxDqDlyTg2_r5_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P3_TxDqDlyTg2_r5_p3_SHIFT (0U)
/*! TxDqDlyTg2_r5_p3 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P3_TxDqDlyTg2_r5_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P3_TxDqDlyTg2_r5_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P3_TxDqDlyTg2_r5_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R5_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P3_TxDqDlyTg3_r5_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P3_TxDqDlyTg3_r5_p3_SHIFT (0U)
/*! TxDqDlyTg3_r5_p3 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P3_TxDqDlyTg3_r5_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P3_TxDqDlyTg3_r5_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P3_TxDqDlyTg3_r5_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R6_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P3_TxDqDlyTg0_r6_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P3_TxDqDlyTg0_r6_p3_SHIFT (0U)
/*! TxDqDlyTg0_r6_p3 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P3_TxDqDlyTg0_r6_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P3_TxDqDlyTg0_r6_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P3_TxDqDlyTg0_r6_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R6_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P3_TxDqDlyTg1_r6_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P3_TxDqDlyTg1_r6_p3_SHIFT (0U)
/*! TxDqDlyTg1_r6_p3 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P3_TxDqDlyTg1_r6_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P3_TxDqDlyTg1_r6_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P3_TxDqDlyTg1_r6_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R6_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P3_TxDqDlyTg2_r6_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P3_TxDqDlyTg2_r6_p3_SHIFT (0U)
/*! TxDqDlyTg2_r6_p3 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P3_TxDqDlyTg2_r6_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P3_TxDqDlyTg2_r6_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P3_TxDqDlyTg2_r6_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R6_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P3_TxDqDlyTg3_r6_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P3_TxDqDlyTg3_r6_p3_SHIFT (0U)
/*! TxDqDlyTg3_r6_p3 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P3_TxDqDlyTg3_r6_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P3_TxDqDlyTg3_r6_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P3_TxDqDlyTg3_r6_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R7_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P3_TxDqDlyTg0_r7_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P3_TxDqDlyTg0_r7_p3_SHIFT (0U)
/*! TxDqDlyTg0_r7_p3 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P3_TxDqDlyTg0_r7_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P3_TxDqDlyTg0_r7_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P3_TxDqDlyTg0_r7_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R7_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P3_TxDqDlyTg1_r7_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P3_TxDqDlyTg1_r7_p3_SHIFT (0U)
/*! TxDqDlyTg1_r7_p3 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P3_TxDqDlyTg1_r7_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P3_TxDqDlyTg1_r7_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P3_TxDqDlyTg1_r7_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R7_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P3_TxDqDlyTg2_r7_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P3_TxDqDlyTg2_r7_p3_SHIFT (0U)
/*! TxDqDlyTg2_r7_p3 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P3_TxDqDlyTg2_r7_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P3_TxDqDlyTg2_r7_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P3_TxDqDlyTg2_r7_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R7_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P3_TxDqDlyTg3_r7_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P3_TxDqDlyTg3_r7_p3_SHIFT (0U)
/*! TxDqDlyTg3_r7_p3 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P3_TxDqDlyTg3_r7_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P3_TxDqDlyTg3_r7_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P3_TxDqDlyTg3_r7_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R8_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P3_TxDqDlyTg0_r8_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P3_TxDqDlyTg0_r8_p3_SHIFT (0U)
/*! TxDqDlyTg0_r8_p3 - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P3_TxDqDlyTg0_r8_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P3_TxDqDlyTg0_r8_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P3_TxDqDlyTg0_r8_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R8_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P3_TxDqDlyTg1_r8_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P3_TxDqDlyTg1_r8_p3_SHIFT (0U)
/*! TxDqDlyTg1_r8_p3 - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P3_TxDqDlyTg1_r8_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P3_TxDqDlyTg1_r8_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P3_TxDqDlyTg1_r8_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R8_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P3_TxDqDlyTg2_r8_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P3_TxDqDlyTg2_r8_p3_SHIFT (0U)
/*! TxDqDlyTg2_r8_p3 - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P3_TxDqDlyTg2_r8_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P3_TxDqDlyTg2_r8_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P3_TxDqDlyTg2_r8_p3_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R8_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P3_TxDqDlyTg3_r8_p3_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P3_TxDqDlyTg3_r8_p3_SHIFT (0U)
/*! TxDqDlyTg3_r8_p3 - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P3_TxDqDlyTg3_r8_p3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P3_TxDqDlyTg3_r8_p3_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P3_TxDqDlyTg3_r8_p3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_DBYTE_Register_Masks */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_DBYTE_Peripheral_Access_Layer */


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


#endif  /* PERI_DWC_DDRPHYA_DBYTE_H_ */
