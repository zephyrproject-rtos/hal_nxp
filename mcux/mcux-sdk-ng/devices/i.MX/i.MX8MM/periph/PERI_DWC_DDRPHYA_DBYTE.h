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
 * @file PERI_DWC_DDRPHYA_DBYTE.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DWC_DDRPHYA_DBYTE
 *
 * CMSIS Peripheral Access Layer for DWC_DDRPHYA_DBYTE
 */

#if !defined(PERI_DWC_DDRPHYA_DBYTE_H_)
#define PERI_DWC_DDRPHYA_DBYTE_H_                /**< Symbol preventing repeated inclusion */

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
   -- DWC_DDRPHYA_DBYTE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_DBYTE_Peripheral_Access_Layer DWC_DDRPHYA_DBYTE Peripheral Access Layer
 * @{
 */

/** DWC_DDRPHYA_DBYTE - Size of Registers Arrays */
#define DWC_DDRPHYA_DBYTE_DQNLNSEL_COUNT          8u

/** DWC_DDRPHYA_DBYTE - Register Layout Typedef */
typedef struct {
  __IO uint16_t DBYTEMISCMODE;                     /**< DBYTE Module Disable, offset: 0x0 */
       uint8_t RESERVED_0[50];
  __IO uint16_t MTESTMUXSEL;                       /**< Digital Observation Pin control, offset: 0x34 */
       uint8_t RESERVED_1[10];
  __IO uint16_t DFIMRL_P0;                         /**< DFI MaxReadLatency, offset: 0x40 */
       uint8_t RESERVED_2[30];
  __IO uint16_t VREFDAC1_R0;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0x60 */
       uint8_t RESERVED_3[30];
  __IO uint16_t VREFDAC0_R0;                       /**< VrefDAC0 control for DQ Receiver, offset: 0x80 */
  __IO uint16_t TXIMPEDANCECTRL0_B0_P0;            /**< Data TX impedance controls, offset: 0x82 */
       uint8_t RESERVED_4[2];
  __IO uint16_t DQDQSRCVCNTRL_B0_P0;               /**< Dq/Dqs receiver control, offset: 0x86 */
       uint8_t RESERVED_5[8];
  __IO uint16_t TXEQUALIZATIONMODE_P0;             /**< Tx dq driver equalization mode controls., offset: 0x90 */
  __IO uint16_t TXIMPEDANCECTRL1_B0_P0;            /**< TX impedance controls, offset: 0x92 */
  __IO uint16_t DQDQSRCVCNTRL1;                    /**< Dq/Dqs receiver control, offset: 0x94 */
  __IO uint16_t TXIMPEDANCECTRL2_B0_P0;            /**< TX equalization impedance controls, offset: 0x96 */
  __IO uint16_t DQDQSRCVCNTRL2_P0;                 /**< Dq/Dqs receiver control, offset: 0x98 */
  __IO uint16_t TXODTDRVSTREN_B0_P0;               /**< TX ODT driver strength control, offset: 0x9A */
       uint8_t RESERVED_6[16];
  __I  uint16_t RXFIFOCHECKSTATUS;                 /**< Status of RX FIFO Consistency Checks, offset: 0xAC */
  __I  uint16_t RXFIFOCHECKERRVALUES;              /**< Contains the captured values associated with an RxFifo consistency error, offset: 0xAE */
  __I  uint16_t RXFIFOINFO;                        /**< Data Receive FIFO Pointer Values, offset: 0xB0 */
  __IO uint16_t RXFIFOVISIBILITY;                  /**< RX FIFO visibility, offset: 0xB2 */
  __I  uint16_t RXFIFOCONTENTSDQ3210;              /**< RX FIFO contents, lane[3:0], offset: 0xB4 */
  __I  uint16_t RXFIFOCONTENTSDQ7654;              /**< RX FIFO contents, lane[7:4], offset: 0xB6 */
  __I  uint16_t RXFIFOCONTENTSDBI;                 /**< RX FIFO contents, dbi, offset: 0xB8 */
       uint8_t RESERVED_7[4];
  __IO uint16_t TXSLEWRATE_B0_P0;                  /**< TX slew rate controls, offset: 0xBE */
       uint8_t RESERVED_8[16];
  __IO uint16_t RXPBDLYTG0_R0;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0xD0 */
  __IO uint16_t RXPBDLYTG1_R0;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0xD2 */
  __IO uint16_t RXPBDLYTG2_R0;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0xD4 */
  __IO uint16_t RXPBDLYTG3_R0;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0xD6 */
       uint8_t RESERVED_9[40];
  __IO uint16_t RXENDLYTG0_U0_P0;                  /**< Trained Receive Enable Delay (For Timing Group 0), offset: 0x100 */
  __IO uint16_t RXENDLYTG1_U0_P0;                  /**< Trained Receive Enable Delay (For Timing Group 1), offset: 0x102 */
  __IO uint16_t RXENDLYTG2_U0_P0;                  /**< Trained Receive Enable Delay (For Timing Group 2), offset: 0x104 */
  __IO uint16_t RXENDLYTG3_U0_P0;                  /**< Trained Receive Enable Delay (For Timing Group 3), offset: 0x106 */
       uint8_t RESERVED_10[16];
  __IO uint16_t RXCLKDLYTG0_U0_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x118 */
  __IO uint16_t RXCLKDLYTG1_U0_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x11A */
  __IO uint16_t RXCLKDLYTG2_U0_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x11C */
  __IO uint16_t RXCLKDLYTG3_U0_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x11E */
  __IO uint16_t RXCLKCDLYTG0_U0_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x120 */
  __IO uint16_t RXCLKCDLYTG1_U0_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x122 */
  __IO uint16_t RXCLKCDLYTG2_U0_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x124 */
       uint8_t RESERVED_11[2];
  __IO uint16_t RXCLKCDLYTG3_U0_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x128 */
       uint8_t RESERVED_12[22];
  __IO uint16_t DQLNSEL[DWC_DDRPHYA_DBYTE_DQNLNSEL_COUNT]; /**< Maps Phy DQ lane to memory DQ0, array offset: 0x140, array step: 0x2 */
       uint8_t RESERVED_13[48];
  __IO uint16_t TXDQDLYTG0_R0_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x180 */
  __IO uint16_t TXDQDLYTG1_R0_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x182 */
  __IO uint16_t TXDQDLYTG2_R0_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x184 */
  __IO uint16_t TXDQDLYTG3_R0_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x186 */
       uint8_t RESERVED_14[24];
  __IO uint16_t TXDQSDLYTG0_U0_P0;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x1A0 */
  __IO uint16_t TXDQSDLYTG1_U0_P0;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x1A2 */
  __IO uint16_t TXDQSDLYTG2_U0_P0;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x1A4 */
  __IO uint16_t TXDQSDLYTG3_U0_P0;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x1A6 */
       uint8_t RESERVED_15[32];
  __I  uint16_t DXLCDLSTATUS;                      /**< Debug status of the DBYTE LCDL, offset: 0x1C8 */
       uint8_t RESERVED_16[150];
  __IO uint16_t VREFDAC1_R1;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0x260 */
       uint8_t RESERVED_17[30];
  __IO uint16_t VREFDAC0_R1;                       /**< VrefDAC0 control for DQ Receiver, offset: 0x280 */
  __IO uint16_t TXIMPEDANCECTRL0_B1_P0;            /**< Data TX impedance controls, offset: 0x282 */
       uint8_t RESERVED_18[2];
  __IO uint16_t DQDQSRCVCNTRL_B1_P0;               /**< Dq/Dqs receiver control, offset: 0x286 */
       uint8_t RESERVED_19[10];
  __IO uint16_t TXIMPEDANCECTRL1_B1_P0;            /**< TX impedance controls, offset: 0x292 */
       uint8_t RESERVED_20[2];
  __IO uint16_t TXIMPEDANCECTRL2_B1_P0;            /**< TX equalization impedance controls, offset: 0x296 */
       uint8_t RESERVED_21[2];
  __IO uint16_t TXODTDRVSTREN_B1_P0;               /**< TX ODT driver strength control, offset: 0x29A */
       uint8_t RESERVED_22[34];
  __IO uint16_t TXSLEWRATE_B1_P0;                  /**< TX slew rate controls, offset: 0x2BE */
       uint8_t RESERVED_23[16];
  __IO uint16_t RXPBDLYTG0_R1;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0x2D0 */
  __IO uint16_t RXPBDLYTG1_R1;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0x2D2 */
  __IO uint16_t RXPBDLYTG2_R1;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0x2D4 */
  __IO uint16_t RXPBDLYTG3_R1;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0x2D6 */
       uint8_t RESERVED_24[40];
  __IO uint16_t RXENDLYTG0_U1_P0;                  /**< Trained Receive Enable Delay (For Timing Group 0), offset: 0x300 */
  __IO uint16_t RXENDLYTG1_U1_P0;                  /**< Trained Receive Enable Delay (For Timing Group 1), offset: 0x302 */
  __IO uint16_t RXENDLYTG2_U1_P0;                  /**< Trained Receive Enable Delay (For Timing Group 2), offset: 0x304 */
  __IO uint16_t RXENDLYTG3_U1_P0;                  /**< Trained Receive Enable Delay (For Timing Group 3), offset: 0x306 */
       uint8_t RESERVED_25[16];
  __IO uint16_t RXCLKDLYTG0_U1_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x318 */
  __IO uint16_t RXCLKDLYTG1_U1_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x31A */
  __IO uint16_t RXCLKDLYTG2_U1_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x31C */
  __IO uint16_t RXCLKDLYTG3_U1_P0;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x31E */
  __IO uint16_t RXCLKCDLYTG0_U1_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x320 */
  __IO uint16_t RXCLKCDLYTG1_U1_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x322 */
  __IO uint16_t RXCLKCDLYTG2_U1_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x324 */
       uint8_t RESERVED_26[2];
  __IO uint16_t RXCLKCDLYTG3_U1_P0;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x328 */
       uint8_t RESERVED_27[86];
  __IO uint16_t TXDQDLYTG0_R1_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x380 */
  __IO uint16_t TXDQDLYTG1_R1_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x382 */
  __IO uint16_t TXDQDLYTG2_R1_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x384 */
  __IO uint16_t TXDQDLYTG3_R1_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x386 */
       uint8_t RESERVED_28[24];
  __IO uint16_t TXDQSDLYTG0_U1_P0;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x3A0 */
  __IO uint16_t TXDQSDLYTG1_U1_P0;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x3A2 */
  __IO uint16_t TXDQSDLYTG2_U1_P0;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x3A4 */
  __IO uint16_t TXDQSDLYTG3_U1_P0;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x3A6 */
       uint8_t RESERVED_29[184];
  __IO uint16_t VREFDAC1_R2;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0x460 */
       uint8_t RESERVED_30[30];
  __IO uint16_t VREFDAC0_R2;                       /**< VrefDAC0 control for DQ Receiver, offset: 0x480 */
       uint8_t RESERVED_31[78];
  __IO uint16_t RXPBDLYTG0_R2;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0x4D0 */
  __IO uint16_t RXPBDLYTG1_R2;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0x4D2 */
  __IO uint16_t RXPBDLYTG2_R2;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0x4D4 */
  __IO uint16_t RXPBDLYTG3_R2;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0x4D6 */
       uint8_t RESERVED_32[168];
  __IO uint16_t TXDQDLYTG0_R2_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x580 */
  __IO uint16_t TXDQDLYTG1_R2_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x582 */
  __IO uint16_t TXDQDLYTG2_R2_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x584 */
  __IO uint16_t TXDQDLYTG3_R2_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x586 */
       uint8_t RESERVED_33[216];
  __IO uint16_t VREFDAC1_R3;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0x660 */
       uint8_t RESERVED_34[30];
  __IO uint16_t VREFDAC0_R3;                       /**< VrefDAC0 control for DQ Receiver, offset: 0x680 */
       uint8_t RESERVED_35[78];
  __IO uint16_t RXPBDLYTG0_R3;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0x6D0 */
  __IO uint16_t RXPBDLYTG1_R3;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0x6D2 */
  __IO uint16_t RXPBDLYTG2_R3;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0x6D4 */
  __IO uint16_t RXPBDLYTG3_R3;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0x6D6 */
       uint8_t RESERVED_36[168];
  __IO uint16_t TXDQDLYTG0_R3_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x780 */
  __IO uint16_t TXDQDLYTG1_R3_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x782 */
  __IO uint16_t TXDQDLYTG2_R3_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x784 */
  __IO uint16_t TXDQDLYTG3_R3_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x786 */
       uint8_t RESERVED_37[216];
  __IO uint16_t VREFDAC1_R4;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0x860 */
       uint8_t RESERVED_38[30];
  __IO uint16_t VREFDAC0_R4;                       /**< VrefDAC0 control for DQ Receiver, offset: 0x880 */
       uint8_t RESERVED_39[78];
  __IO uint16_t RXPBDLYTG0_R4;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0x8D0 */
  __IO uint16_t RXPBDLYTG1_R4;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0x8D2 */
  __IO uint16_t RXPBDLYTG2_R4;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0x8D4 */
  __IO uint16_t RXPBDLYTG3_R4;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0x8D6 */
       uint8_t RESERVED_40[168];
  __IO uint16_t TXDQDLYTG0_R4_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x980 */
  __IO uint16_t TXDQDLYTG1_R4_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x982 */
  __IO uint16_t TXDQDLYTG2_R4_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x984 */
  __IO uint16_t TXDQDLYTG3_R4_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x986 */
       uint8_t RESERVED_41[216];
  __IO uint16_t VREFDAC1_R5;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0xA60 */
       uint8_t RESERVED_42[30];
  __IO uint16_t VREFDAC0_R5;                       /**< VrefDAC0 control for DQ Receiver, offset: 0xA80 */
       uint8_t RESERVED_43[78];
  __IO uint16_t RXPBDLYTG0_R5;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0xAD0 */
  __IO uint16_t RXPBDLYTG1_R5;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0xAD2 */
  __IO uint16_t RXPBDLYTG2_R5;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0xAD4 */
  __IO uint16_t RXPBDLYTG3_R5;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0xAD6 */
       uint8_t RESERVED_44[168];
  __IO uint16_t TXDQDLYTG0_R5_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0xB80 */
  __IO uint16_t TXDQDLYTG1_R5_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0xB82 */
  __IO uint16_t TXDQDLYTG2_R5_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0xB84 */
  __IO uint16_t TXDQDLYTG3_R5_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0xB86 */
       uint8_t RESERVED_45[216];
  __IO uint16_t VREFDAC1_R6;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0xC60 */
       uint8_t RESERVED_46[30];
  __IO uint16_t VREFDAC0_R6;                       /**< VrefDAC0 control for DQ Receiver, offset: 0xC80 */
       uint8_t RESERVED_47[78];
  __IO uint16_t RXPBDLYTG0_R6;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0xCD0 */
  __IO uint16_t RXPBDLYTG1_R6;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0xCD2 */
  __IO uint16_t RXPBDLYTG2_R6;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0xCD4 */
  __IO uint16_t RXPBDLYTG3_R6;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0xCD6 */
       uint8_t RESERVED_48[168];
  __IO uint16_t TXDQDLYTG0_R6_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0xD80 */
  __IO uint16_t TXDQDLYTG1_R6_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0xD82 */
  __IO uint16_t TXDQDLYTG2_R6_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0xD84 */
  __IO uint16_t TXDQDLYTG3_R6_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0xD86 */
       uint8_t RESERVED_49[216];
  __IO uint16_t VREFDAC1_R7;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0xE60 */
       uint8_t RESERVED_50[30];
  __IO uint16_t VREFDAC0_R7;                       /**< VrefDAC0 control for DQ Receiver, offset: 0xE80 */
       uint8_t RESERVED_51[78];
  __IO uint16_t RXPBDLYTG0_R7;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0xED0 */
  __IO uint16_t RXPBDLYTG1_R7;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0xED2 */
  __IO uint16_t RXPBDLYTG2_R7;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0xED4 */
  __IO uint16_t RXPBDLYTG3_R7;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0xED6 */
       uint8_t RESERVED_52[168];
  __IO uint16_t TXDQDLYTG0_R7_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0xF80 */
  __IO uint16_t TXDQDLYTG1_R7_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0xF82 */
  __IO uint16_t TXDQDLYTG2_R7_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0xF84 */
  __IO uint16_t TXDQDLYTG3_R7_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0xF86 */
       uint8_t RESERVED_53[216];
  __IO uint16_t VREFDAC1_R8;                       /**< VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4), offset: 0x1060 */
       uint8_t RESERVED_54[30];
  __IO uint16_t VREFDAC0_R8;                       /**< VrefDAC0 control for DQ Receiver, offset: 0x1080 */
       uint8_t RESERVED_55[78];
  __IO uint16_t RXPBDLYTG0_R8;                     /**< Read DQ per-bit BDL delay (Timing Group 0)., offset: 0x10D0 */
  __IO uint16_t RXPBDLYTG1_R8;                     /**< Read DQ per-bit BDL delay (Timing Group 1)., offset: 0x10D2 */
  __IO uint16_t RXPBDLYTG2_R8;                     /**< Read DQ per-bit BDL delay (Timing Group 2)., offset: 0x10D4 */
  __IO uint16_t RXPBDLYTG3_R8;                     /**< Read DQ per-bit BDL delay (Timing Group 3)., offset: 0x10D6 */
       uint8_t RESERVED_56[168];
  __IO uint16_t TXDQDLYTG0_R8_P0;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x1180 */
  __IO uint16_t TXDQDLYTG1_R8_P0;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x1182 */
  __IO uint16_t TXDQDLYTG2_R8_P0;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x1184 */
  __IO uint16_t TXDQDLYTG3_R8_P0;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x1186 */
       uint8_t RESERVED_57[2092728];
  __IO uint16_t DFIMRL_P1;                         /**< DFI MaxReadLatency, offset: 0x200040 */
       uint8_t RESERVED_58[64];
  __IO uint16_t TXIMPEDANCECTRL0_B0_P1;            /**< Data TX impedance controls, offset: 0x200082 */
       uint8_t RESERVED_59[2];
  __IO uint16_t DQDQSRCVCNTRL_B0_P1;               /**< Dq/Dqs receiver control, offset: 0x200086 */
       uint8_t RESERVED_60[8];
  __IO uint16_t TXEQUALIZATIONMODE_P1;             /**< Tx dq driver equalization mode controls., offset: 0x200090 */
  __IO uint16_t TXIMPEDANCECTRL1_B0_P1;            /**< TX impedance controls, offset: 0x200092 */
       uint8_t RESERVED_61[2];
  __IO uint16_t TXIMPEDANCECTRL2_B0_P1;            /**< TX equalization impedance controls, offset: 0x200096 */
  __IO uint16_t DQDQSRCVCNTRL2_P1;                 /**< Dq/Dqs receiver control, offset: 0x200098 */
  __IO uint16_t TXODTDRVSTREN_B0_P1;               /**< TX ODT driver strength control, offset: 0x20009A */
       uint8_t RESERVED_62[34];
  __IO uint16_t TXSLEWRATE_B0_P1;                  /**< TX slew rate controls, offset: 0x2000BE */
       uint8_t RESERVED_63[64];
  __IO uint16_t RXENDLYTG0_U0_P1;                  /**< Trained Receive Enable Delay (For Timing Group 0), offset: 0x200100 */
  __IO uint16_t RXENDLYTG1_U0_P1;                  /**< Trained Receive Enable Delay (For Timing Group 1), offset: 0x200102 */
  __IO uint16_t RXENDLYTG2_U0_P1;                  /**< Trained Receive Enable Delay (For Timing Group 2), offset: 0x200104 */
  __IO uint16_t RXENDLYTG3_U0_P1;                  /**< Trained Receive Enable Delay (For Timing Group 3), offset: 0x200106 */
       uint8_t RESERVED_64[16];
  __IO uint16_t RXCLKDLYTG0_U0_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x200118 */
  __IO uint16_t RXCLKDLYTG1_U0_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x20011A */
  __IO uint16_t RXCLKDLYTG2_U0_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x20011C */
  __IO uint16_t RXCLKDLYTG3_U0_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x20011E */
  __IO uint16_t RXCLKCDLYTG0_U0_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x200120 */
  __IO uint16_t RXCLKCDLYTG1_U0_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x200122 */
  __IO uint16_t RXCLKCDLYTG2_U0_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x200124 */
       uint8_t RESERVED_65[2];
  __IO uint16_t RXCLKCDLYTG3_U0_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x200128 */
       uint8_t RESERVED_66[86];
  __IO uint16_t TXDQDLYTG0_R0_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200180 */
  __IO uint16_t TXDQDLYTG1_R0_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200182 */
  __IO uint16_t TXDQDLYTG2_R0_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200184 */
  __IO uint16_t TXDQDLYTG3_R0_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200186 */
       uint8_t RESERVED_67[24];
  __IO uint16_t TXDQSDLYTG0_U0_P1;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x2001A0 */
  __IO uint16_t TXDQSDLYTG1_U0_P1;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x2001A2 */
  __IO uint16_t TXDQSDLYTG2_U0_P1;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x2001A4 */
  __IO uint16_t TXDQSDLYTG3_U0_P1;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x2001A6 */
       uint8_t RESERVED_68[218];
  __IO uint16_t TXIMPEDANCECTRL0_B1_P1;            /**< Data TX impedance controls, offset: 0x200282 */
       uint8_t RESERVED_69[2];
  __IO uint16_t DQDQSRCVCNTRL_B1_P1;               /**< Dq/Dqs receiver control, offset: 0x200286 */
       uint8_t RESERVED_70[10];
  __IO uint16_t TXIMPEDANCECTRL1_B1_P1;            /**< TX impedance controls, offset: 0x200292 */
       uint8_t RESERVED_71[2];
  __IO uint16_t TXIMPEDANCECTRL2_B1_P1;            /**< TX equalization impedance controls, offset: 0x200296 */
       uint8_t RESERVED_72[2];
  __IO uint16_t TXODTDRVSTREN_B1_P1;               /**< TX ODT driver strength control, offset: 0x20029A */
       uint8_t RESERVED_73[34];
  __IO uint16_t TXSLEWRATE_B1_P1;                  /**< TX slew rate controls, offset: 0x2002BE */
       uint8_t RESERVED_74[64];
  __IO uint16_t RXENDLYTG0_U1_P1;                  /**< Trained Receive Enable Delay (For Timing Group 0), offset: 0x200300 */
  __IO uint16_t RXENDLYTG1_U1_P1;                  /**< Trained Receive Enable Delay (For Timing Group 1), offset: 0x200302 */
  __IO uint16_t RXENDLYTG2_U1_P1;                  /**< Trained Receive Enable Delay (For Timing Group 2), offset: 0x200304 */
  __IO uint16_t RXENDLYTG3_U1_P1;                  /**< Trained Receive Enable Delay (For Timing Group 3), offset: 0x200306 */
       uint8_t RESERVED_75[16];
  __IO uint16_t RXCLKDLYTG0_U1_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x200318 */
  __IO uint16_t RXCLKDLYTG1_U1_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x20031A */
  __IO uint16_t RXCLKDLYTG2_U1_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x20031C */
  __IO uint16_t RXCLKDLYTG3_U1_P1;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x20031E */
  __IO uint16_t RXCLKCDLYTG0_U1_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x200320 */
  __IO uint16_t RXCLKCDLYTG1_U1_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x200322 */
  __IO uint16_t RXCLKCDLYTG2_U1_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x200324 */
       uint8_t RESERVED_76[2];
  __IO uint16_t RXCLKCDLYTG3_U1_P1;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x200328 */
       uint8_t RESERVED_77[86];
  __IO uint16_t TXDQDLYTG0_R1_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200380 */
  __IO uint16_t TXDQDLYTG1_R1_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200382 */
  __IO uint16_t TXDQDLYTG2_R1_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200384 */
  __IO uint16_t TXDQDLYTG3_R1_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200386 */
       uint8_t RESERVED_78[24];
  __IO uint16_t TXDQSDLYTG0_U1_P1;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x2003A0 */
  __IO uint16_t TXDQSDLYTG1_U1_P1;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x2003A2 */
  __IO uint16_t TXDQSDLYTG2_U1_P1;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x2003A4 */
  __IO uint16_t TXDQSDLYTG3_U1_P1;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x2003A6 */
       uint8_t RESERVED_79[472];
  __IO uint16_t TXDQDLYTG0_R2_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200580 */
  __IO uint16_t TXDQDLYTG1_R2_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200582 */
  __IO uint16_t TXDQDLYTG2_R2_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200584 */
  __IO uint16_t TXDQDLYTG3_R2_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200586 */
       uint8_t RESERVED_80[504];
  __IO uint16_t TXDQDLYTG0_R3_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200780 */
  __IO uint16_t TXDQDLYTG1_R3_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200782 */
  __IO uint16_t TXDQDLYTG2_R3_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200784 */
  __IO uint16_t TXDQDLYTG3_R3_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200786 */
       uint8_t RESERVED_81[504];
  __IO uint16_t TXDQDLYTG0_R4_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200980 */
  __IO uint16_t TXDQDLYTG1_R4_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200982 */
  __IO uint16_t TXDQDLYTG2_R4_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200984 */
  __IO uint16_t TXDQDLYTG3_R4_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200986 */
       uint8_t RESERVED_82[504];
  __IO uint16_t TXDQDLYTG0_R5_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200B80 */
  __IO uint16_t TXDQDLYTG1_R5_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200B82 */
  __IO uint16_t TXDQDLYTG2_R5_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200B84 */
  __IO uint16_t TXDQDLYTG3_R5_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200B86 */
       uint8_t RESERVED_83[504];
  __IO uint16_t TXDQDLYTG0_R6_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200D80 */
  __IO uint16_t TXDQDLYTG1_R6_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200D82 */
  __IO uint16_t TXDQDLYTG2_R6_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200D84 */
  __IO uint16_t TXDQDLYTG3_R6_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200D86 */
       uint8_t RESERVED_84[504];
  __IO uint16_t TXDQDLYTG0_R7_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x200F80 */
  __IO uint16_t TXDQDLYTG1_R7_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x200F82 */
  __IO uint16_t TXDQDLYTG2_R7_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x200F84 */
  __IO uint16_t TXDQDLYTG3_R7_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x200F86 */
       uint8_t RESERVED_85[504];
  __IO uint16_t TXDQDLYTG0_R8_P1;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x201180 */
  __IO uint16_t TXDQDLYTG1_R8_P1;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x201182 */
  __IO uint16_t TXDQDLYTG2_R8_P1;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x201184 */
  __IO uint16_t TXDQDLYTG3_R8_P1;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x201186 */
       uint8_t RESERVED_86[2092728];
  __IO uint16_t DFIMRL_P2;                         /**< DFI MaxReadLatency, offset: 0x400040 */
       uint8_t RESERVED_87[64];
  __IO uint16_t TXIMPEDANCECTRL0_B0_P2;            /**< Data TX impedance controls, offset: 0x400082 */
       uint8_t RESERVED_88[2];
  __IO uint16_t DQDQSRCVCNTRL_B0_P2;               /**< Dq/Dqs receiver control, offset: 0x400086 */
       uint8_t RESERVED_89[8];
  __IO uint16_t TXEQUALIZATIONMODE_P2;             /**< Tx dq driver equalization mode controls., offset: 0x400090 */
  __IO uint16_t TXIMPEDANCECTRL1_B0_P2;            /**< TX impedance controls, offset: 0x400092 */
       uint8_t RESERVED_90[2];
  __IO uint16_t TXIMPEDANCECTRL2_B0_P2;            /**< TX equalization impedance controls, offset: 0x400096 */
  __IO uint16_t DQDQSRCVCNTRL2_P2;                 /**< Dq/Dqs receiver control, offset: 0x400098 */
  __IO uint16_t TXODTDRVSTREN_B0_P2;               /**< TX ODT driver strength control, offset: 0x40009A */
       uint8_t RESERVED_91[34];
  __IO uint16_t TXSLEWRATE_B0_P2;                  /**< TX slew rate controls, offset: 0x4000BE */
       uint8_t RESERVED_92[64];
  __IO uint16_t RXENDLYTG0_U0_P2;                  /**< Trained Receive Enable Delay (For Timing Group 0), offset: 0x400100 */
  __IO uint16_t RXENDLYTG1_U0_P2;                  /**< Trained Receive Enable Delay (For Timing Group 1), offset: 0x400102 */
  __IO uint16_t RXENDLYTG2_U0_P2;                  /**< Trained Receive Enable Delay (For Timing Group 2), offset: 0x400104 */
  __IO uint16_t RXENDLYTG3_U0_P2;                  /**< Trained Receive Enable Delay (For Timing Group 3), offset: 0x400106 */
       uint8_t RESERVED_93[16];
  __IO uint16_t RXCLKDLYTG0_U0_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x400118 */
  __IO uint16_t RXCLKDLYTG1_U0_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x40011A */
  __IO uint16_t RXCLKDLYTG2_U0_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x40011C */
  __IO uint16_t RXCLKDLYTG3_U0_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x40011E */
  __IO uint16_t RXCLKCDLYTG0_U0_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x400120 */
  __IO uint16_t RXCLKCDLYTG1_U0_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x400122 */
  __IO uint16_t RXCLKCDLYTG2_U0_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x400124 */
       uint8_t RESERVED_94[2];
  __IO uint16_t RXCLKCDLYTG3_U0_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x400128 */
       uint8_t RESERVED_95[50];
  __IO uint16_t PPTDQSCNTINVTRNTG0_P2;             /**< DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation, offset: 0x40015C */
  __IO uint16_t PPTDQSCNTINVTRNTG1_P2;             /**< DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation, offset: 0x40015E */
       uint8_t RESERVED_96[32];
  __IO uint16_t TXDQDLYTG0_R0_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400180 */
  __IO uint16_t TXDQDLYTG1_R0_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400182 */
  __IO uint16_t TXDQDLYTG2_R0_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400184 */
  __IO uint16_t TXDQDLYTG3_R0_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400186 */
       uint8_t RESERVED_97[24];
  __IO uint16_t TXDQSDLYTG0_U0_P2;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x4001A0 */
  __IO uint16_t TXDQSDLYTG1_U0_P2;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x4001A2 */
  __IO uint16_t TXDQSDLYTG2_U0_P2;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x4001A4 */
  __IO uint16_t TXDQSDLYTG3_U0_P2;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x4001A6 */
       uint8_t RESERVED_98[218];
  __IO uint16_t TXIMPEDANCECTRL0_B1_P2;            /**< Data TX impedance controls, offset: 0x400282 */
       uint8_t RESERVED_99[2];
  __IO uint16_t DQDQSRCVCNTRL_B1_P2;               /**< Dq/Dqs receiver control, offset: 0x400286 */
       uint8_t RESERVED_100[10];
  __IO uint16_t TXIMPEDANCECTRL1_B1_P2;            /**< TX impedance controls, offset: 0x400292 */
       uint8_t RESERVED_101[2];
  __IO uint16_t TXIMPEDANCECTRL2_B1_P2;            /**< TX equalization impedance controls, offset: 0x400296 */
       uint8_t RESERVED_102[2];
  __IO uint16_t TXODTDRVSTREN_B1_P2;               /**< TX ODT driver strength control, offset: 0x40029A */
       uint8_t RESERVED_103[34];
  __IO uint16_t TXSLEWRATE_B1_P2;                  /**< TX slew rate controls, offset: 0x4002BE */
       uint8_t RESERVED_104[64];
  __IO uint16_t RXENDLYTG0_U1_P2;                  /**< Trained Receive Enable Delay (For Timing Group 0), offset: 0x400300 */
  __IO uint16_t RXENDLYTG1_U1_P2;                  /**< Trained Receive Enable Delay (For Timing Group 1), offset: 0x400302 */
  __IO uint16_t RXENDLYTG2_U1_P2;                  /**< Trained Receive Enable Delay (For Timing Group 2), offset: 0x400304 */
  __IO uint16_t RXENDLYTG3_U1_P2;                  /**< Trained Receive Enable Delay (For Timing Group 3), offset: 0x400306 */
       uint8_t RESERVED_105[16];
  __IO uint16_t RXCLKDLYTG0_U1_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x400318 */
  __IO uint16_t RXCLKDLYTG1_U1_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x40031A */
  __IO uint16_t RXCLKDLYTG2_U1_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x40031C */
  __IO uint16_t RXCLKDLYTG3_U1_P2;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x40031E */
  __IO uint16_t RXCLKCDLYTG0_U1_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x400320 */
  __IO uint16_t RXCLKCDLYTG1_U1_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x400322 */
  __IO uint16_t RXCLKCDLYTG2_U1_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x400324 */
       uint8_t RESERVED_106[2];
  __IO uint16_t RXCLKCDLYTG3_U1_P2;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x400328 */
       uint8_t RESERVED_107[86];
  __IO uint16_t TXDQDLYTG0_R1_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400380 */
  __IO uint16_t TXDQDLYTG1_R1_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400382 */
  __IO uint16_t TXDQDLYTG2_R1_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400384 */
  __IO uint16_t TXDQDLYTG3_R1_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400386 */
       uint8_t RESERVED_108[24];
  __IO uint16_t TXDQSDLYTG0_U1_P2;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x4003A0 */
  __IO uint16_t TXDQSDLYTG1_U1_P2;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x4003A2 */
  __IO uint16_t TXDQSDLYTG2_U1_P2;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x4003A4 */
  __IO uint16_t TXDQSDLYTG3_U1_P2;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x4003A6 */
       uint8_t RESERVED_109[472];
  __IO uint16_t TXDQDLYTG0_R2_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400580 */
  __IO uint16_t TXDQDLYTG1_R2_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400582 */
  __IO uint16_t TXDQDLYTG2_R2_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400584 */
  __IO uint16_t TXDQDLYTG3_R2_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400586 */
       uint8_t RESERVED_110[504];
  __IO uint16_t TXDQDLYTG0_R3_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400780 */
  __IO uint16_t TXDQDLYTG1_R3_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400782 */
  __IO uint16_t TXDQDLYTG2_R3_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400784 */
  __IO uint16_t TXDQDLYTG3_R3_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400786 */
       uint8_t RESERVED_111[504];
  __IO uint16_t TXDQDLYTG0_R4_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400980 */
  __IO uint16_t TXDQDLYTG1_R4_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400982 */
  __IO uint16_t TXDQDLYTG2_R4_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400984 */
  __IO uint16_t TXDQDLYTG3_R4_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400986 */
       uint8_t RESERVED_112[504];
  __IO uint16_t TXDQDLYTG0_R5_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400B80 */
  __IO uint16_t TXDQDLYTG1_R5_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400B82 */
  __IO uint16_t TXDQDLYTG2_R5_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400B84 */
  __IO uint16_t TXDQDLYTG3_R5_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400B86 */
       uint8_t RESERVED_113[504];
  __IO uint16_t TXDQDLYTG0_R6_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400D80 */
  __IO uint16_t TXDQDLYTG1_R6_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400D82 */
  __IO uint16_t TXDQDLYTG2_R6_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400D84 */
  __IO uint16_t TXDQDLYTG3_R6_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400D86 */
       uint8_t RESERVED_114[504];
  __IO uint16_t TXDQDLYTG0_R7_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x400F80 */
  __IO uint16_t TXDQDLYTG1_R7_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x400F82 */
  __IO uint16_t TXDQDLYTG2_R7_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x400F84 */
  __IO uint16_t TXDQDLYTG3_R7_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x400F86 */
       uint8_t RESERVED_115[504];
  __IO uint16_t TXDQDLYTG0_R8_P2;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x401180 */
  __IO uint16_t TXDQDLYTG1_R8_P2;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x401182 */
  __IO uint16_t TXDQDLYTG2_R8_P2;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x401184 */
  __IO uint16_t TXDQDLYTG3_R8_P2;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x401186 */
       uint8_t RESERVED_116[2092728];
  __IO uint16_t DFIMRL_P3;                         /**< DFI MaxReadLatency, offset: 0x600040 */
       uint8_t RESERVED_117[64];
  __IO uint16_t TXIMPEDANCECTRL0_B0_P3;            /**< Data TX impedance controls, offset: 0x600082 */
       uint8_t RESERVED_118[2];
  __IO uint16_t DQDQSRCVCNTRL_B0_P3;               /**< Dq/Dqs receiver control, offset: 0x600086 */
       uint8_t RESERVED_119[8];
  __IO uint16_t TXEQUALIZATIONMODE_P3;             /**< Tx dq driver equalization mode controls., offset: 0x600090 */
  __IO uint16_t TXIMPEDANCECTRL1_B0_P3;            /**< TX impedance controls, offset: 0x600092 */
       uint8_t RESERVED_120[2];
  __IO uint16_t TXIMPEDANCECTRL2_B0_P3;            /**< TX equalization impedance controls, offset: 0x600096 */
  __IO uint16_t DQDQSRCVCNTRL2_P3;                 /**< Dq/Dqs receiver control, offset: 0x600098 */
  __IO uint16_t TXODTDRVSTREN_B0_P3;               /**< TX ODT driver strength control, offset: 0x60009A */
       uint8_t RESERVED_121[34];
  __IO uint16_t TXSLEWRATE_B0_P3;                  /**< TX slew rate controls, offset: 0x6000BE */
       uint8_t RESERVED_122[64];
  __IO uint16_t RXENDLYTG0_U0_P3;                  /**< Trained Receive Enable Delay (For Timing Group 0), offset: 0x600100 */
  __IO uint16_t RXENDLYTG1_U0_P3;                  /**< Trained Receive Enable Delay (For Timing Group 1), offset: 0x600102 */
  __IO uint16_t RXENDLYTG2_U0_P3;                  /**< Trained Receive Enable Delay (For Timing Group 2), offset: 0x600104 */
  __IO uint16_t RXENDLYTG3_U0_P3;                  /**< Trained Receive Enable Delay (For Timing Group 3), offset: 0x600106 */
       uint8_t RESERVED_123[16];
  __IO uint16_t RXCLKDLYTG0_U0_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x600118 */
  __IO uint16_t RXCLKDLYTG1_U0_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x60011A */
  __IO uint16_t RXCLKDLYTG2_U0_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x60011C */
  __IO uint16_t RXCLKDLYTG3_U0_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x60011E */
  __IO uint16_t RXCLKCDLYTG0_U0_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x600120 */
  __IO uint16_t RXCLKCDLYTG1_U0_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x600122 */
  __IO uint16_t RXCLKCDLYTG2_U0_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x600124 */
       uint8_t RESERVED_124[2];
  __IO uint16_t RXCLKCDLYTG3_U0_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x600128 */
       uint8_t RESERVED_125[50];
  __IO uint16_t PPTDQSCNTINVTRNTG0_P3;             /**< DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation, offset: 0x60015C */
  __IO uint16_t PPTDQSCNTINVTRNTG1_P3;             /**< DQS Oscillator Count inverse at time of training in LPDDR4 drift compensation, offset: 0x60015E */
       uint8_t RESERVED_126[32];
  __IO uint16_t TXDQDLYTG0_R0_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600180 */
  __IO uint16_t TXDQDLYTG1_R0_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600182 */
  __IO uint16_t TXDQDLYTG2_R0_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600184 */
  __IO uint16_t TXDQDLYTG3_R0_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600186 */
       uint8_t RESERVED_127[24];
  __IO uint16_t TXDQSDLYTG0_U0_P3;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x6001A0 */
  __IO uint16_t TXDQSDLYTG1_U0_P3;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x6001A2 */
  __IO uint16_t TXDQSDLYTG2_U0_P3;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x6001A4 */
  __IO uint16_t TXDQSDLYTG3_U0_P3;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x6001A6 */
       uint8_t RESERVED_128[218];
  __IO uint16_t TXIMPEDANCECTRL0_B1_P3;            /**< Data TX impedance controls, offset: 0x600282 */
       uint8_t RESERVED_129[2];
  __IO uint16_t DQDQSRCVCNTRL_B1_P3;               /**< Dq/Dqs receiver control, offset: 0x600286 */
       uint8_t RESERVED_130[10];
  __IO uint16_t TXIMPEDANCECTRL1_B1_P3;            /**< TX impedance controls, offset: 0x600292 */
       uint8_t RESERVED_131[2];
  __IO uint16_t TXIMPEDANCECTRL2_B1_P3;            /**< TX equalization impedance controls, offset: 0x600296 */
       uint8_t RESERVED_132[2];
  __IO uint16_t TXODTDRVSTREN_B1_P3;               /**< TX ODT driver strength control, offset: 0x60029A */
       uint8_t RESERVED_133[34];
  __IO uint16_t TXSLEWRATE_B1_P3;                  /**< TX slew rate controls, offset: 0x6002BE */
       uint8_t RESERVED_134[64];
  __IO uint16_t RXENDLYTG0_U1_P3;                  /**< Trained Receive Enable Delay (For Timing Group 0), offset: 0x600300 */
  __IO uint16_t RXENDLYTG1_U1_P3;                  /**< Trained Receive Enable Delay (For Timing Group 1), offset: 0x600302 */
  __IO uint16_t RXENDLYTG2_U1_P3;                  /**< Trained Receive Enable Delay (For Timing Group 2), offset: 0x600304 */
  __IO uint16_t RXENDLYTG3_U1_P3;                  /**< Trained Receive Enable Delay (For Timing Group 3), offset: 0x600306 */
       uint8_t RESERVED_135[16];
  __IO uint16_t RXCLKDLYTG0_U1_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=0)., offset: 0x600318 */
  __IO uint16_t RXCLKDLYTG1_U1_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=1)., offset: 0x60031A */
  __IO uint16_t RXCLKDLYTG2_U1_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=2)., offset: 0x60031C */
  __IO uint16_t RXCLKDLYTG3_U1_P3;                 /**< Trained Read DQS to RxClk Delay (Timing Group DEST=3)., offset: 0x60031E */
  __IO uint16_t RXCLKCDLYTG0_U1_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x600320 */
  __IO uint16_t RXCLKCDLYTG1_U1_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0)., offset: 0x600322 */
  __IO uint16_t RXCLKCDLYTG2_U1_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2)., offset: 0x600324 */
       uint8_t RESERVED_136[2];
  __IO uint16_t RXCLKCDLYTG3_U1_P3;                /**< Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3)., offset: 0x600328 */
       uint8_t RESERVED_137[86];
  __IO uint16_t TXDQDLYTG0_R1_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600380 */
  __IO uint16_t TXDQDLYTG1_R1_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600382 */
  __IO uint16_t TXDQDLYTG2_R1_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600384 */
  __IO uint16_t TXDQDLYTG3_R1_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600386 */
       uint8_t RESERVED_138[24];
  __IO uint16_t TXDQSDLYTG0_U1_P3;                 /**< Write DQS Delay (Timing Group DEST=0)., offset: 0x6003A0 */
  __IO uint16_t TXDQSDLYTG1_U1_P3;                 /**< Write DQS Delay (Timing Group DEST=1)., offset: 0x6003A2 */
  __IO uint16_t TXDQSDLYTG2_U1_P3;                 /**< Write DQS Delay (Timing Group DEST=2)., offset: 0x6003A4 */
  __IO uint16_t TXDQSDLYTG3_U1_P3;                 /**< Write DQS Delay (Timing Group DEST=3)., offset: 0x6003A6 */
       uint8_t RESERVED_139[472];
  __IO uint16_t TXDQDLYTG0_R2_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600580 */
  __IO uint16_t TXDQDLYTG1_R2_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600582 */
  __IO uint16_t TXDQDLYTG2_R2_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600584 */
  __IO uint16_t TXDQDLYTG3_R2_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600586 */
       uint8_t RESERVED_140[504];
  __IO uint16_t TXDQDLYTG0_R3_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600780 */
  __IO uint16_t TXDQDLYTG1_R3_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600782 */
  __IO uint16_t TXDQDLYTG2_R3_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600784 */
  __IO uint16_t TXDQDLYTG3_R3_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600786 */
       uint8_t RESERVED_141[504];
  __IO uint16_t TXDQDLYTG0_R4_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600980 */
  __IO uint16_t TXDQDLYTG1_R4_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600982 */
  __IO uint16_t TXDQDLYTG2_R4_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600984 */
  __IO uint16_t TXDQDLYTG3_R4_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600986 */
       uint8_t RESERVED_142[504];
  __IO uint16_t TXDQDLYTG0_R5_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600B80 */
  __IO uint16_t TXDQDLYTG1_R5_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600B82 */
  __IO uint16_t TXDQDLYTG2_R5_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600B84 */
  __IO uint16_t TXDQDLYTG3_R5_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600B86 */
       uint8_t RESERVED_143[504];
  __IO uint16_t TXDQDLYTG0_R6_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600D80 */
  __IO uint16_t TXDQDLYTG1_R6_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600D82 */
  __IO uint16_t TXDQDLYTG2_R6_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600D84 */
  __IO uint16_t TXDQDLYTG3_R6_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600D86 */
       uint8_t RESERVED_144[504];
  __IO uint16_t TXDQDLYTG0_R7_P3;                  /**< Write DQ Delay (Timing Group 0)., offset: 0x600F80 */
  __IO uint16_t TXDQDLYTG1_R7_P3;                  /**< Write DQ Delay (Timing Group 1)., offset: 0x600F82 */
  __IO uint16_t TXDQDLYTG2_R7_P3;                  /**< Write DQ Delay (Timing Group 2)., offset: 0x600F84 */
  __IO uint16_t TXDQDLYTG3_R7_P3;                  /**< Write DQ Delay (Timing Group 3)., offset: 0x600F86 */
       uint8_t RESERVED_145[504];
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

/*! @name MTESTMUXSEL - Digital Observation Pin control */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_MTESTMUXSEL_MtestMuxSel_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_MTESTMUXSEL_MtestMuxSel_SHIFT (0U)
/*! MtestMuxSel - Controls for the 64-1 mux for asynchronous data to the Digital Observation Pin. */
#define DWC_DDRPHYA_DBYTE_MTESTMUXSEL_MtestMuxSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_MTESTMUXSEL_MtestMuxSel_SHIFT)) & DWC_DDRPHYA_DBYTE_MTESTMUXSEL_MtestMuxSel_MASK)
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

/*! @name VREFDAC1_R0 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R0_VrefDAC1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R0_VrefDAC1_rx_SHIFT (0U)
/*! VrefDAC1_rx - VrefDAC1 controls the alternate VREF setting for DFE (used only when DFE is
 *    enabled in DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The VREF generators
 *    have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 011,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R0_VrefDAC1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R0_VrefDAC1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R0_VrefDAC1_rx_MASK)
/*! @} */

/*! @name VREFDAC0_R0 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R0_VrefDAC0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R0_VrefDAC0_rx_SHIFT (0U)
/*! VrefDAC0_rx - PHY RX VREF DAC control for rxdq cell internal VREF, (used only when 2D training
 *    is enabled in LPDDR4,DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The
 *    VREF generators have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 000,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R0_VrefDAC0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R0_VrefDAC0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R0_VrefDAC0_rx_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL0_B0_P0 - Data TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P0_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
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
/*! DfeCtrl - DFE may be used with MajorModeDbyte=011 only 00 - DFE off 01 - DFE on 10 - Train DFE0
 *    Amplifier 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
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
#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P0_TxEqMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P0_TxEqMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P0_TxEqMode_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL1_B0_P0 - TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqP_SHIFT (0U)
/*! DrvStrenFSDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P0_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
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

/*! @name TXIMPEDANCECTRL2_B0_P0 - TX equalization impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P0_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull down output impedance used in equalization.
 */
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

#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoRdLocErr_MASK (0x1U)
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoRdLocErr_SHIFT (0U)
/*! RxFifoRdLocErr - If set, the read pointer (DFI side) on the read FIFO associated with data bits [3:0] had a non-zero value at least once. */
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoRdLocErr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoRdLocErr_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoRdLocErr_MASK)

#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoWrLocErr_MASK (0x2U)
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoWrLocErr_SHIFT (1U)
/*! RxFifoWrLocErr - If set, the write pointer (DQS side) on the read FIFO associated with data bits
 *    [3:0] has a non-zero value at least once.
 */
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoWrLocErr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoWrLocErr_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoWrLocErr_MASK)

#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoRdLocUErr_MASK (0x4U)
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoRdLocUErr_SHIFT (2U)
/*! RxFifoRdLocUErr - If set, the read pointer (DFI side) on the read FIFO associated with data bits [7:4] has a non-zero value at least once. */
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoRdLocUErr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoRdLocUErr_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoRdLocUErr_MASK)

#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoWrLocUErr_MASK (0x8U)
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoWrLocUErr_SHIFT (3U)
/*! RxFifoWrLocUErr - If set, the write pointer (DQS side) on the read FIFO associated with data
 *    bits [7:4] has a non-zero value at least once.
 */
#define DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoWrLocUErr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoWrLocUErr_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCHECKSTATUS_RxFifoWrLocUErr_MASK)
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
/*! RxFifoRdPtr - If CSR RxFifoRdPtrOVr is set, then this CSR selects the rxfifo entry is visible in
 *    CSR This 3b field addresses 4b units of the 8x4b (32entry) fifo; that is,
 *    rdfifo_nibble_address[2:0]=csrRxFifoRdPtr[2:0] For example, Register RxFifoRdPtr[2:0]=2 will enable reading
 *    bit-entries 11.
 */
#define DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtr_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtr_MASK)

#define DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtrOvr_MASK (0x8U)
#define DWC_DDRPHYA_DBYTE_RXFIFOVISIBILITY_RxFifoRdPtrOvr_SHIFT (3U)
/*! RxFifoRdPtrOvr - 0 : Normal operation - mission mode read pointer is enabled 1 : Override -
 *    Control of the rx fifo read pointer is ceded to CSR RxFifoRdPtr.
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
/*! RxFifoContentsDQ3210 - A window into the contents of the RxFifo, as controlled by CSR
 *    RxFifoVisibility This register reads 4b at a time from lane0.
 */
#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ3210_RxFifoContentsDQ3210(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ3210_RxFifoContentsDQ3210_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ3210_RxFifoContentsDQ3210_MASK)
/*! @} */

/*! @name RXFIFOCONTENTSDQ7654 - RX FIFO contents, lane[7:4] */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ7654_RxFifoContentsDQ7654_MASK (0xFFFFU)
#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ7654_RxFifoContentsDQ7654_SHIFT (0U)
/*! RxFifoContentsDQ7654 - A window into the contents of the RxFifo, as controlled by CSR
 *    RxFifoVisibility This register reads 4b at a time from lane4.
 */
#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ7654_RxFifoContentsDQ7654(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ7654_RxFifoContentsDQ7654_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDQ7654_RxFifoContentsDQ7654_MASK)
/*! @} */

/*! @name RXFIFOCONTENTSDBI - RX FIFO contents, dbi */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDBI_RxFifoContentsDBI_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDBI_RxFifoContentsDBI_SHIFT (0U)
/*! RxFifoContentsDBI - A window into the contents of the RxFifo, as controlled by CSR
 *    RxFifoVisibility This register reads 4b at a time from DBI from the four fifo entries addressed by
 *    rdfifo_nibble_address[2:0]=RxFifoRdPtr[2:0] Register [ 3: 0] = dbi_ui3,dbi_ui2,dbi_ui1,dbi_ui0 Note
 *    that the DBYTE DBI lane is the same as the memory DBI; it is not subject to mapping using csr
 *    Dq<7.
 */
#define DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDBI_RxFifoContentsDBI(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDBI_RxFifoContentsDBI_SHIFT)) & DWC_DDRPHYA_DBYTE_RXFIFOCONTENTSDBI_RxFifoContentsDBI_MASK)
/*! @} */

/*! @name TXSLEWRATE_B0_P0 - TX slew rate controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreP_MASK (0xFU)
#define DWC_DDRPHYA_DBYTE_TXSLEWRATE_B0_P0_TxPreP_SHIFT (0U)
/*! TxPreP - 4 bit binary trim for the driver pull up slew rate. */
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

/*! @name RXPBDLYTG0_R0 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R0_RxPBDlyTg0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R0_RxPBDlyTg0_rx_SHIFT (0U)
/*! RxPBDlyTg0_rx - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R0_RxPBDlyTg0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R0_RxPBDlyTg0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R0_RxPBDlyTg0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R0 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R0_RxPBDlyTg1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R0_RxPBDlyTg1_rx_SHIFT (0U)
/*! RxPBDlyTg1_rx - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R0_RxPBDlyTg1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R0_RxPBDlyTg1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R0_RxPBDlyTg1_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R0 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R0_RxPBDlyTg2_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R0_RxPBDlyTg2_rx_SHIFT (0U)
/*! RxPBDlyTg2_rx - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R0_RxPBDlyTg2_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R0_RxPBDlyTg2_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R0_RxPBDlyTg2_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R0 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R0_RxPBDlyTg3_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R0_RxPBDlyTg3_rx_SHIFT (0U)
/*! RxPBDlyTg3_rx - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R0_RxPBDlyTg3_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R0_RxPBDlyTg3_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R0_RxPBDlyTg3_rx_MASK)
/*! @} */

/*! @name RXENDLYTG0_U0_P0 - Trained Receive Enable Delay (For Timing Group 0) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P0_RxEnDlyTg0_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P0_RxEnDlyTg0_un_px_SHIFT (0U)
/*! RxEnDlyTg0_un_px - Trained Receive Enable Delay (For Timing Group 0) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P0_RxEnDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P0_RxEnDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P0_RxEnDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG1_U0_P0 - Trained Receive Enable Delay (For Timing Group 1) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P0_RxEnDlyTg1_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P0_RxEnDlyTg1_un_px_SHIFT (0U)
/*! RxEnDlyTg1_un_px - Trained Receive Enable Delay (For Timing Group 1) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P0_RxEnDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P0_RxEnDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P0_RxEnDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG2_U0_P0 - Trained Receive Enable Delay (For Timing Group 2) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P0_RxEnDlyTg2_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P0_RxEnDlyTg2_un_px_SHIFT (0U)
/*! RxEnDlyTg2_un_px - Trained Receive Enable Delay (For Timing Group 2) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P0_RxEnDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P0_RxEnDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P0_RxEnDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG3_U0_P0 - Trained Receive Enable Delay (For Timing Group 3) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P0_RxEnDlyTg3_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P0_RxEnDlyTg3_un_px_SHIFT (0U)
/*! RxEnDlyTg3_un_px - Trained Receive Enable Delay (For Timing Group 3) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P0_RxEnDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P0_RxEnDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P0_RxEnDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U0_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P0_RxClkDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P0_RxClkDlyTg0_un_px_SHIFT (0U)
/*! RxClkDlyTg0_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P0_RxClkDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P0_RxClkDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P0_RxClkDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U0_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P0_RxClkDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P0_RxClkDlyTg1_un_px_SHIFT (0U)
/*! RxClkDlyTg1_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P0_RxClkDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P0_RxClkDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P0_RxClkDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U0_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P0_RxClkDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P0_RxClkDlyTg2_un_px_SHIFT (0U)
/*! RxClkDlyTg2_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P0_RxClkDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P0_RxClkDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P0_RxClkDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U0_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P0_RxClkDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P0_RxClkDlyTg3_un_px_SHIFT (0U)
/*! RxClkDlyTg3_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P0_RxClkDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P0_RxClkDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P0_RxClkDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U0_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P0_RxClkcDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P0_RxClkcDlyTg0_un_px_SHIFT (0U)
/*! RxClkcDlyTg0_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P0_RxClkcDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P0_RxClkcDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P0_RxClkcDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U0_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P0_RxClkcDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P0_RxClkcDlyTg1_un_px_SHIFT (0U)
/*! RxClkcDlyTg1_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P0_RxClkcDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P0_RxClkcDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P0_RxClkcDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U0_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P0_RxClkcDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P0_RxClkcDlyTg2_un_px_SHIFT (0U)
/*! RxClkcDlyTg2_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P0_RxClkcDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P0_RxClkcDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P0_RxClkcDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U0_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P0_RxClkcDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P0_RxClkcDlyTg3_un_px_SHIFT (0U)
/*! RxClkcDlyTg3_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P0_RxClkcDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P0_RxClkcDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P0_RxClkcDlyTg3_un_px_MASK)
/*! @} */

/*! @name DQLNSEL - Maps Phy DQ lane to memory DQ0 */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_DQLNSEL_DqLnSel_MASK   (0x7U)
#define DWC_DDRPHYA_DBYTE_DQLNSEL_DqLnSel_SHIFT  (0U)
/*! DqLnSel - Supports mapping of PHY dq to dram dq within a byte (swizzle). */
#define DWC_DDRPHYA_DBYTE_DQLNSEL_DqLnSel(x)     (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DQLNSEL_DqLnSel_SHIFT)) & DWC_DDRPHYA_DBYTE_DQLNSEL_DqLnSel_MASK)
/*! @} */

/* The count of DWC_DDRPHYA_DBYTE_DQLNSEL */
#define DWC_DDRPHYA_DBYTE_DQLNSEL_COUNT          (8U)

/*! @name TXDQDLYTG0_R0_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P0_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P0_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P0_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P0_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P0_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R0_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P0_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P0_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P0_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P0_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P0_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R0_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P0_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P0_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P0_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P0_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P0_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R0_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P0_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P0_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P0_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P0_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P0_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U0_P0 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P0_TxDqsDlyTg0_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P0_TxDqsDlyTg0_un_px_SHIFT (0U)
/*! TxDqsDlyTg0_un_px - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P0_TxDqsDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P0_TxDqsDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P0_TxDqsDlyTg0_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U0_P0 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P0_TxDqsDlyTg1_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P0_TxDqsDlyTg1_un_px_SHIFT (0U)
/*! TxDqsDlyTg1_un_px - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P0_TxDqsDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P0_TxDqsDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P0_TxDqsDlyTg1_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U0_P0 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P0_TxDqsDlyTg2_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P0_TxDqsDlyTg2_un_px_SHIFT (0U)
/*! TxDqsDlyTg2_un_px - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P0_TxDqsDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P0_TxDqsDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P0_TxDqsDlyTg2_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U0_P0 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P0_TxDqsDlyTg3_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P0_TxDqsDlyTg3_un_px_SHIFT (0U)
/*! TxDqsDlyTg3_un_px - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P0_TxDqsDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P0_TxDqsDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P0_TxDqsDlyTg3_un_px_MASK)
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
/*! DxLcdlStickyLock - latched value of whether the LCDL ever achieved lock after the assertion of LcdlTstEnable. */
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyLock(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyLock_SHIFT)) & DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyLock_MASK)

#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyUnlock_MASK (0x1000U)
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyUnlock_SHIFT (12U)
/*! DxLcdlStickyUnlock - latched value of whether the LCDL ever lost lock after the assertion of LcdlTstEnable. */
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyUnlock(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyUnlock_SHIFT)) & DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlStickyUnlock_MASK)

#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlLiveLock_MASK (0x2000U)
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlLiveLock_SHIFT (13U)
/*! DxLcdlLiveLock - present value of whether the LCDL is locked, valid when LcdlTstEnable=1. */
#define DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlLiveLock(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlLiveLock_SHIFT)) & DWC_DDRPHYA_DBYTE_DXLCDLSTATUS_DxLcdlLiveLock_MASK)
/*! @} */

/*! @name VREFDAC1_R1 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R1_VrefDAC1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R1_VrefDAC1_rx_SHIFT (0U)
/*! VrefDAC1_rx - VrefDAC1 controls the alternate VREF setting for DFE (used only when DFE is
 *    enabled in DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The VREF generators
 *    have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 011,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R1_VrefDAC1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R1_VrefDAC1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R1_VrefDAC1_rx_MASK)
/*! @} */

/*! @name VREFDAC0_R1 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R1_VrefDAC0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R1_VrefDAC0_rx_SHIFT (0U)
/*! VrefDAC0_rx - PHY RX VREF DAC control for rxdq cell internal VREF, (used only when 2D training
 *    is enabled in LPDDR4,DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The
 *    VREF generators have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 000,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R1_VrefDAC0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R1_VrefDAC0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R1_VrefDAC0_rx_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL0_B1_P0 - Data TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P0_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
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
/*! DfeCtrl - DFE may be used with MajorModeDbyte=011 only 00 - DFE off 01 - DFE on 10 - Train DFE0
 *    Amplifier 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
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
/*! DrvStrenFSDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P0_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B1_P0 - TX equalization impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P0_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull down output impedance used in equalization.
 */
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
/*! TxPreP - 4 bit binary trim for the driver pull up slew rate. */
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

/*! @name RXPBDLYTG0_R1 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R1_RxPBDlyTg0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R1_RxPBDlyTg0_rx_SHIFT (0U)
/*! RxPBDlyTg0_rx - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R1_RxPBDlyTg0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R1_RxPBDlyTg0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R1_RxPBDlyTg0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R1 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R1_RxPBDlyTg1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R1_RxPBDlyTg1_rx_SHIFT (0U)
/*! RxPBDlyTg1_rx - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R1_RxPBDlyTg1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R1_RxPBDlyTg1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R1_RxPBDlyTg1_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R1 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R1_RxPBDlyTg2_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R1_RxPBDlyTg2_rx_SHIFT (0U)
/*! RxPBDlyTg2_rx - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R1_RxPBDlyTg2_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R1_RxPBDlyTg2_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R1_RxPBDlyTg2_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R1 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R1_RxPBDlyTg3_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R1_RxPBDlyTg3_rx_SHIFT (0U)
/*! RxPBDlyTg3_rx - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R1_RxPBDlyTg3_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R1_RxPBDlyTg3_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R1_RxPBDlyTg3_rx_MASK)
/*! @} */

/*! @name RXENDLYTG0_U1_P0 - Trained Receive Enable Delay (For Timing Group 0) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P0_RxEnDlyTg0_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P0_RxEnDlyTg0_un_px_SHIFT (0U)
/*! RxEnDlyTg0_un_px - Trained Receive Enable Delay (For Timing Group 0) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P0_RxEnDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P0_RxEnDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P0_RxEnDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG1_U1_P0 - Trained Receive Enable Delay (For Timing Group 1) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P0_RxEnDlyTg1_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P0_RxEnDlyTg1_un_px_SHIFT (0U)
/*! RxEnDlyTg1_un_px - Trained Receive Enable Delay (For Timing Group 1) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P0_RxEnDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P0_RxEnDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P0_RxEnDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG2_U1_P0 - Trained Receive Enable Delay (For Timing Group 2) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P0_RxEnDlyTg2_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P0_RxEnDlyTg2_un_px_SHIFT (0U)
/*! RxEnDlyTg2_un_px - Trained Receive Enable Delay (For Timing Group 2) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P0_RxEnDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P0_RxEnDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P0_RxEnDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG3_U1_P0 - Trained Receive Enable Delay (For Timing Group 3) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P0_RxEnDlyTg3_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P0_RxEnDlyTg3_un_px_SHIFT (0U)
/*! RxEnDlyTg3_un_px - Trained Receive Enable Delay (For Timing Group 3) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P0_RxEnDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P0_RxEnDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P0_RxEnDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U1_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P0_RxClkDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P0_RxClkDlyTg0_un_px_SHIFT (0U)
/*! RxClkDlyTg0_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P0_RxClkDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P0_RxClkDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P0_RxClkDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U1_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P0_RxClkDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P0_RxClkDlyTg1_un_px_SHIFT (0U)
/*! RxClkDlyTg1_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P0_RxClkDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P0_RxClkDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P0_RxClkDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U1_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P0_RxClkDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P0_RxClkDlyTg2_un_px_SHIFT (0U)
/*! RxClkDlyTg2_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P0_RxClkDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P0_RxClkDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P0_RxClkDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U1_P0 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P0_RxClkDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P0_RxClkDlyTg3_un_px_SHIFT (0U)
/*! RxClkDlyTg3_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P0_RxClkDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P0_RxClkDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P0_RxClkDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U1_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P0_RxClkcDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P0_RxClkcDlyTg0_un_px_SHIFT (0U)
/*! RxClkcDlyTg0_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P0_RxClkcDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P0_RxClkcDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P0_RxClkcDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U1_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P0_RxClkcDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P0_RxClkcDlyTg1_un_px_SHIFT (0U)
/*! RxClkcDlyTg1_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P0_RxClkcDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P0_RxClkcDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P0_RxClkcDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U1_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P0_RxClkcDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P0_RxClkcDlyTg2_un_px_SHIFT (0U)
/*! RxClkcDlyTg2_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P0_RxClkcDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P0_RxClkcDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P0_RxClkcDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U1_P0 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P0_RxClkcDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P0_RxClkcDlyTg3_un_px_SHIFT (0U)
/*! RxClkcDlyTg3_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P0_RxClkcDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P0_RxClkcDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P0_RxClkcDlyTg3_un_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R1_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P0_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P0_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P0_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P0_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P0_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R1_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P0_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P0_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P0_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P0_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P0_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R1_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P0_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P0_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P0_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P0_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P0_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R1_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P0_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P0_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P0_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P0_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P0_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U1_P0 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P0_TxDqsDlyTg0_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P0_TxDqsDlyTg0_un_px_SHIFT (0U)
/*! TxDqsDlyTg0_un_px - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P0_TxDqsDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P0_TxDqsDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P0_TxDqsDlyTg0_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U1_P0 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P0_TxDqsDlyTg1_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P0_TxDqsDlyTg1_un_px_SHIFT (0U)
/*! TxDqsDlyTg1_un_px - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P0_TxDqsDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P0_TxDqsDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P0_TxDqsDlyTg1_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U1_P0 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P0_TxDqsDlyTg2_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P0_TxDqsDlyTg2_un_px_SHIFT (0U)
/*! TxDqsDlyTg2_un_px - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P0_TxDqsDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P0_TxDqsDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P0_TxDqsDlyTg2_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U1_P0 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P0_TxDqsDlyTg3_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P0_TxDqsDlyTg3_un_px_SHIFT (0U)
/*! TxDqsDlyTg3_un_px - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P0_TxDqsDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P0_TxDqsDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P0_TxDqsDlyTg3_un_px_MASK)
/*! @} */

/*! @name VREFDAC1_R2 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R2_VrefDAC1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R2_VrefDAC1_rx_SHIFT (0U)
/*! VrefDAC1_rx - VrefDAC1 controls the alternate VREF setting for DFE (used only when DFE is
 *    enabled in DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The VREF generators
 *    have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 011,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R2_VrefDAC1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R2_VrefDAC1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R2_VrefDAC1_rx_MASK)
/*! @} */

/*! @name VREFDAC0_R2 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R2_VrefDAC0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R2_VrefDAC0_rx_SHIFT (0U)
/*! VrefDAC0_rx - PHY RX VREF DAC control for rxdq cell internal VREF, (used only when 2D training
 *    is enabled in LPDDR4,DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The
 *    VREF generators have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 000,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R2_VrefDAC0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R2_VrefDAC0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R2_VrefDAC0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R2 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R2_RxPBDlyTg0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R2_RxPBDlyTg0_rx_SHIFT (0U)
/*! RxPBDlyTg0_rx - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R2_RxPBDlyTg0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R2_RxPBDlyTg0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R2_RxPBDlyTg0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R2 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R2_RxPBDlyTg1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R2_RxPBDlyTg1_rx_SHIFT (0U)
/*! RxPBDlyTg1_rx - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R2_RxPBDlyTg1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R2_RxPBDlyTg1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R2_RxPBDlyTg1_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R2 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R2_RxPBDlyTg2_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R2_RxPBDlyTg2_rx_SHIFT (0U)
/*! RxPBDlyTg2_rx - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R2_RxPBDlyTg2_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R2_RxPBDlyTg2_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R2_RxPBDlyTg2_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R2 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R2_RxPBDlyTg3_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R2_RxPBDlyTg3_rx_SHIFT (0U)
/*! RxPBDlyTg3_rx - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R2_RxPBDlyTg3_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R2_RxPBDlyTg3_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R2_RxPBDlyTg3_rx_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R2_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P0_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P0_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P0_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P0_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P0_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R2_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P0_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P0_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P0_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P0_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P0_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R2_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P0_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P0_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P0_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P0_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P0_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R2_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P0_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P0_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P0_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P0_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P0_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name VREFDAC1_R3 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R3_VrefDAC1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R3_VrefDAC1_rx_SHIFT (0U)
/*! VrefDAC1_rx - VrefDAC1 controls the alternate VREF setting for DFE (used only when DFE is
 *    enabled in DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The VREF generators
 *    have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 011,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R3_VrefDAC1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R3_VrefDAC1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R3_VrefDAC1_rx_MASK)
/*! @} */

/*! @name VREFDAC0_R3 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R3_VrefDAC0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R3_VrefDAC0_rx_SHIFT (0U)
/*! VrefDAC0_rx - PHY RX VREF DAC control for rxdq cell internal VREF, (used only when 2D training
 *    is enabled in LPDDR4,DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The
 *    VREF generators have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 000,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R3_VrefDAC0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R3_VrefDAC0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R3_VrefDAC0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R3 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R3_RxPBDlyTg0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R3_RxPBDlyTg0_rx_SHIFT (0U)
/*! RxPBDlyTg0_rx - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R3_RxPBDlyTg0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R3_RxPBDlyTg0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R3_RxPBDlyTg0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R3 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R3_RxPBDlyTg1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R3_RxPBDlyTg1_rx_SHIFT (0U)
/*! RxPBDlyTg1_rx - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R3_RxPBDlyTg1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R3_RxPBDlyTg1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R3_RxPBDlyTg1_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R3 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R3_RxPBDlyTg2_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R3_RxPBDlyTg2_rx_SHIFT (0U)
/*! RxPBDlyTg2_rx - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R3_RxPBDlyTg2_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R3_RxPBDlyTg2_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R3_RxPBDlyTg2_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R3 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R3_RxPBDlyTg3_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R3_RxPBDlyTg3_rx_SHIFT (0U)
/*! RxPBDlyTg3_rx - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R3_RxPBDlyTg3_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R3_RxPBDlyTg3_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R3_RxPBDlyTg3_rx_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R3_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P0_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P0_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P0_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P0_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P0_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R3_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P0_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P0_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P0_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P0_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P0_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R3_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P0_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P0_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P0_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P0_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P0_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R3_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P0_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P0_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P0_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P0_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P0_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name VREFDAC1_R4 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R4_VrefDAC1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R4_VrefDAC1_rx_SHIFT (0U)
/*! VrefDAC1_rx - VrefDAC1 controls the alternate VREF setting for DFE (used only when DFE is
 *    enabled in DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The VREF generators
 *    have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 011,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R4_VrefDAC1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R4_VrefDAC1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R4_VrefDAC1_rx_MASK)
/*! @} */

/*! @name VREFDAC0_R4 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R4_VrefDAC0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R4_VrefDAC0_rx_SHIFT (0U)
/*! VrefDAC0_rx - PHY RX VREF DAC control for rxdq cell internal VREF, (used only when 2D training
 *    is enabled in LPDDR4,DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The
 *    VREF generators have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 000,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R4_VrefDAC0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R4_VrefDAC0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R4_VrefDAC0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R4 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R4_RxPBDlyTg0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R4_RxPBDlyTg0_rx_SHIFT (0U)
/*! RxPBDlyTg0_rx - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R4_RxPBDlyTg0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R4_RxPBDlyTg0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R4_RxPBDlyTg0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R4 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R4_RxPBDlyTg1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R4_RxPBDlyTg1_rx_SHIFT (0U)
/*! RxPBDlyTg1_rx - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R4_RxPBDlyTg1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R4_RxPBDlyTg1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R4_RxPBDlyTg1_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R4 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R4_RxPBDlyTg2_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R4_RxPBDlyTg2_rx_SHIFT (0U)
/*! RxPBDlyTg2_rx - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R4_RxPBDlyTg2_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R4_RxPBDlyTg2_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R4_RxPBDlyTg2_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R4 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R4_RxPBDlyTg3_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R4_RxPBDlyTg3_rx_SHIFT (0U)
/*! RxPBDlyTg3_rx - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R4_RxPBDlyTg3_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R4_RxPBDlyTg3_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R4_RxPBDlyTg3_rx_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R4_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P0_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P0_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P0_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P0_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P0_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R4_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P0_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P0_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P0_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P0_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P0_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R4_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P0_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P0_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P0_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P0_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P0_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R4_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P0_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P0_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P0_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P0_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P0_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name VREFDAC1_R5 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R5_VrefDAC1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R5_VrefDAC1_rx_SHIFT (0U)
/*! VrefDAC1_rx - VrefDAC1 controls the alternate VREF setting for DFE (used only when DFE is
 *    enabled in DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The VREF generators
 *    have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 011,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R5_VrefDAC1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R5_VrefDAC1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R5_VrefDAC1_rx_MASK)
/*! @} */

/*! @name VREFDAC0_R5 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R5_VrefDAC0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R5_VrefDAC0_rx_SHIFT (0U)
/*! VrefDAC0_rx - PHY RX VREF DAC control for rxdq cell internal VREF, (used only when 2D training
 *    is enabled in LPDDR4,DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The
 *    VREF generators have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 000,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R5_VrefDAC0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R5_VrefDAC0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R5_VrefDAC0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R5 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R5_RxPBDlyTg0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R5_RxPBDlyTg0_rx_SHIFT (0U)
/*! RxPBDlyTg0_rx - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R5_RxPBDlyTg0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R5_RxPBDlyTg0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R5_RxPBDlyTg0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R5 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R5_RxPBDlyTg1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R5_RxPBDlyTg1_rx_SHIFT (0U)
/*! RxPBDlyTg1_rx - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R5_RxPBDlyTg1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R5_RxPBDlyTg1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R5_RxPBDlyTg1_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R5 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R5_RxPBDlyTg2_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R5_RxPBDlyTg2_rx_SHIFT (0U)
/*! RxPBDlyTg2_rx - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R5_RxPBDlyTg2_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R5_RxPBDlyTg2_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R5_RxPBDlyTg2_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R5 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R5_RxPBDlyTg3_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R5_RxPBDlyTg3_rx_SHIFT (0U)
/*! RxPBDlyTg3_rx - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R5_RxPBDlyTg3_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R5_RxPBDlyTg3_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R5_RxPBDlyTg3_rx_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R5_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P0_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P0_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P0_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P0_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P0_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R5_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P0_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P0_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P0_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P0_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P0_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R5_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P0_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P0_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P0_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P0_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P0_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R5_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P0_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P0_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P0_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P0_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P0_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name VREFDAC1_R6 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R6_VrefDAC1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R6_VrefDAC1_rx_SHIFT (0U)
/*! VrefDAC1_rx - VrefDAC1 controls the alternate VREF setting for DFE (used only when DFE is
 *    enabled in DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The VREF generators
 *    have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 011,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R6_VrefDAC1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R6_VrefDAC1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R6_VrefDAC1_rx_MASK)
/*! @} */

/*! @name VREFDAC0_R6 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R6_VrefDAC0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R6_VrefDAC0_rx_SHIFT (0U)
/*! VrefDAC0_rx - PHY RX VREF DAC control for rxdq cell internal VREF, (used only when 2D training
 *    is enabled in LPDDR4,DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The
 *    VREF generators have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 000,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R6_VrefDAC0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R6_VrefDAC0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R6_VrefDAC0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R6 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R6_RxPBDlyTg0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R6_RxPBDlyTg0_rx_SHIFT (0U)
/*! RxPBDlyTg0_rx - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R6_RxPBDlyTg0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R6_RxPBDlyTg0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R6_RxPBDlyTg0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R6 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R6_RxPBDlyTg1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R6_RxPBDlyTg1_rx_SHIFT (0U)
/*! RxPBDlyTg1_rx - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R6_RxPBDlyTg1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R6_RxPBDlyTg1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R6_RxPBDlyTg1_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R6 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R6_RxPBDlyTg2_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R6_RxPBDlyTg2_rx_SHIFT (0U)
/*! RxPBDlyTg2_rx - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R6_RxPBDlyTg2_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R6_RxPBDlyTg2_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R6_RxPBDlyTg2_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R6 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R6_RxPBDlyTg3_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R6_RxPBDlyTg3_rx_SHIFT (0U)
/*! RxPBDlyTg3_rx - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R6_RxPBDlyTg3_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R6_RxPBDlyTg3_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R6_RxPBDlyTg3_rx_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R6_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P0_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P0_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P0_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P0_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P0_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R6_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P0_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P0_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P0_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P0_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P0_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R6_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P0_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P0_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P0_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P0_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P0_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R6_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P0_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P0_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P0_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P0_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P0_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name VREFDAC1_R7 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R7_VrefDAC1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R7_VrefDAC1_rx_SHIFT (0U)
/*! VrefDAC1_rx - VrefDAC1 controls the alternate VREF setting for DFE (used only when DFE is
 *    enabled in DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The VREF generators
 *    have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 011,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R7_VrefDAC1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R7_VrefDAC1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R7_VrefDAC1_rx_MASK)
/*! @} */

/*! @name VREFDAC0_R7 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R7_VrefDAC0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R7_VrefDAC0_rx_SHIFT (0U)
/*! VrefDAC0_rx - PHY RX VREF DAC control for rxdq cell internal VREF, (used only when 2D training
 *    is enabled in LPDDR4,DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The
 *    VREF generators have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 000,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R7_VrefDAC0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R7_VrefDAC0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R7_VrefDAC0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R7 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R7_RxPBDlyTg0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R7_RxPBDlyTg0_rx_SHIFT (0U)
/*! RxPBDlyTg0_rx - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R7_RxPBDlyTg0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R7_RxPBDlyTg0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R7_RxPBDlyTg0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R7 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R7_RxPBDlyTg1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R7_RxPBDlyTg1_rx_SHIFT (0U)
/*! RxPBDlyTg1_rx - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R7_RxPBDlyTg1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R7_RxPBDlyTg1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R7_RxPBDlyTg1_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R7 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R7_RxPBDlyTg2_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R7_RxPBDlyTg2_rx_SHIFT (0U)
/*! RxPBDlyTg2_rx - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R7_RxPBDlyTg2_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R7_RxPBDlyTg2_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R7_RxPBDlyTg2_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R7 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R7_RxPBDlyTg3_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R7_RxPBDlyTg3_rx_SHIFT (0U)
/*! RxPBDlyTg3_rx - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R7_RxPBDlyTg3_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R7_RxPBDlyTg3_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R7_RxPBDlyTg3_rx_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R7_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P0_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P0_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P0_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P0_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P0_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R7_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P0_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P0_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P0_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P0_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P0_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R7_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P0_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P0_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P0_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P0_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P0_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R7_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P0_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P0_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P0_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P0_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P0_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name VREFDAC1_R8 - VrefDAC1 control for DQ Receiver (used only when DFE is enabled in DDR4) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC1_R8_VrefDAC1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R8_VrefDAC1_rx_SHIFT (0U)
/*! VrefDAC1_rx - VrefDAC1 controls the alternate VREF setting for DFE (used only when DFE is
 *    enabled in DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The VREF generators
 *    have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 011,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC1_R8_VrefDAC1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC1_R8_VrefDAC1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC1_R8_VrefDAC1_rx_MASK)
/*! @} */

/*! @name VREFDAC0_R8 - VrefDAC0 control for DQ Receiver */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_VREFDAC0_R8_VrefDAC0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R8_VrefDAC0_rx_SHIFT (0U)
/*! VrefDAC0_rx - PHY RX VREF DAC control for rxdq cell internal VREF, (used only when 2D training
 *    is enabled in LPDDR4,DDR4) DAC control for rxdq cell internal VREF, trained by Firmware The
 *    VREF generators have different ranges, depending on the Mission Mode settings for
 *    DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange 000,0 :: VREF = VDDQ*(0.
 */
#define DWC_DDRPHYA_DBYTE_VREFDAC0_R8_VrefDAC0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_VREFDAC0_R8_VrefDAC0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_VREFDAC0_R8_VrefDAC0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG0_R8 - Read DQ per-bit BDL delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R8_RxPBDlyTg0_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R8_RxPBDlyTg0_rx_SHIFT (0U)
/*! RxPBDlyTg0_rx - Read DQ per-bit BDL delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R8_RxPBDlyTg0_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R8_RxPBDlyTg0_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG0_R8_RxPBDlyTg0_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG1_R8 - Read DQ per-bit BDL delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R8_RxPBDlyTg1_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R8_RxPBDlyTg1_rx_SHIFT (0U)
/*! RxPBDlyTg1_rx - Read DQ per-bit BDL delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R8_RxPBDlyTg1_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R8_RxPBDlyTg1_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG1_R8_RxPBDlyTg1_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG2_R8 - Read DQ per-bit BDL delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R8_RxPBDlyTg2_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R8_RxPBDlyTg2_rx_SHIFT (0U)
/*! RxPBDlyTg2_rx - Read DQ per-bit BDL delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R8_RxPBDlyTg2_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R8_RxPBDlyTg2_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG2_R8_RxPBDlyTg2_rx_MASK)
/*! @} */

/*! @name RXPBDLYTG3_R8 - Read DQ per-bit BDL delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R8_RxPBDlyTg3_rx_MASK (0x7FU)
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R8_RxPBDlyTg3_rx_SHIFT (0U)
/*! RxPBDlyTg3_rx - Read DQ per-bit BDL delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R8_RxPBDlyTg3_rx(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R8_RxPBDlyTg3_rx_SHIFT)) & DWC_DDRPHYA_DBYTE_RXPBDLYTG3_R8_RxPBDlyTg3_rx_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R8_P0 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P0_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P0_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P0_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P0_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P0_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R8_P0 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P0_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P0_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P0_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P0_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P0_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R8_P0 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P0_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P0_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P0_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P0_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P0_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R8_P0 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P0_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P0_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P0_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P0_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P0_TxDqDlyTg3_rn_px_MASK)
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

/*! @name TXIMPEDANCECTRL0_B0_P1 - Data TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P1_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
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
/*! DfeCtrl - DFE may be used with MajorModeDbyte=011 only 00 - DFE off 01 - DFE on 10 - Train DFE0
 *    Amplifier 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
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
#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P1_TxEqMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P1_TxEqMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P1_TxEqMode_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL1_B0_P1 - TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqP_SHIFT (0U)
/*! DrvStrenFSDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P1_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B0_P1 - TX equalization impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P1_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull down output impedance used in equalization.
 */
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
/*! TxPreP - 4 bit binary trim for the driver pull up slew rate. */
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

/*! @name RXENDLYTG0_U0_P1 - Trained Receive Enable Delay (For Timing Group 0) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P1_RxEnDlyTg0_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P1_RxEnDlyTg0_un_px_SHIFT (0U)
/*! RxEnDlyTg0_un_px - Trained Receive Enable Delay (For Timing Group 0) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P1_RxEnDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P1_RxEnDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P1_RxEnDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG1_U0_P1 - Trained Receive Enable Delay (For Timing Group 1) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P1_RxEnDlyTg1_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P1_RxEnDlyTg1_un_px_SHIFT (0U)
/*! RxEnDlyTg1_un_px - Trained Receive Enable Delay (For Timing Group 1) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P1_RxEnDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P1_RxEnDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P1_RxEnDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG2_U0_P1 - Trained Receive Enable Delay (For Timing Group 2) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P1_RxEnDlyTg2_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P1_RxEnDlyTg2_un_px_SHIFT (0U)
/*! RxEnDlyTg2_un_px - Trained Receive Enable Delay (For Timing Group 2) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P1_RxEnDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P1_RxEnDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P1_RxEnDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG3_U0_P1 - Trained Receive Enable Delay (For Timing Group 3) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P1_RxEnDlyTg3_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P1_RxEnDlyTg3_un_px_SHIFT (0U)
/*! RxEnDlyTg3_un_px - Trained Receive Enable Delay (For Timing Group 3) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P1_RxEnDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P1_RxEnDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P1_RxEnDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U0_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P1_RxClkDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P1_RxClkDlyTg0_un_px_SHIFT (0U)
/*! RxClkDlyTg0_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P1_RxClkDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P1_RxClkDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P1_RxClkDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U0_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P1_RxClkDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P1_RxClkDlyTg1_un_px_SHIFT (0U)
/*! RxClkDlyTg1_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P1_RxClkDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P1_RxClkDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P1_RxClkDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U0_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P1_RxClkDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P1_RxClkDlyTg2_un_px_SHIFT (0U)
/*! RxClkDlyTg2_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P1_RxClkDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P1_RxClkDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P1_RxClkDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U0_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P1_RxClkDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P1_RxClkDlyTg3_un_px_SHIFT (0U)
/*! RxClkDlyTg3_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P1_RxClkDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P1_RxClkDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P1_RxClkDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U0_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P1_RxClkcDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P1_RxClkcDlyTg0_un_px_SHIFT (0U)
/*! RxClkcDlyTg0_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P1_RxClkcDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P1_RxClkcDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P1_RxClkcDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U0_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P1_RxClkcDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P1_RxClkcDlyTg1_un_px_SHIFT (0U)
/*! RxClkcDlyTg1_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P1_RxClkcDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P1_RxClkcDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P1_RxClkcDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U0_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P1_RxClkcDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P1_RxClkcDlyTg2_un_px_SHIFT (0U)
/*! RxClkcDlyTg2_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P1_RxClkcDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P1_RxClkcDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P1_RxClkcDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U0_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P1_RxClkcDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P1_RxClkcDlyTg3_un_px_SHIFT (0U)
/*! RxClkcDlyTg3_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P1_RxClkcDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P1_RxClkcDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P1_RxClkcDlyTg3_un_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R0_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P1_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P1_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P1_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P1_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P1_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R0_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P1_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P1_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P1_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P1_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P1_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R0_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P1_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P1_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P1_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P1_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P1_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R0_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P1_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P1_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P1_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P1_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P1_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U0_P1 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P1_TxDqsDlyTg0_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P1_TxDqsDlyTg0_un_px_SHIFT (0U)
/*! TxDqsDlyTg0_un_px - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P1_TxDqsDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P1_TxDqsDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P1_TxDqsDlyTg0_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U0_P1 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P1_TxDqsDlyTg1_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P1_TxDqsDlyTg1_un_px_SHIFT (0U)
/*! TxDqsDlyTg1_un_px - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P1_TxDqsDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P1_TxDqsDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P1_TxDqsDlyTg1_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U0_P1 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P1_TxDqsDlyTg2_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P1_TxDqsDlyTg2_un_px_SHIFT (0U)
/*! TxDqsDlyTg2_un_px - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P1_TxDqsDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P1_TxDqsDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P1_TxDqsDlyTg2_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U0_P1 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P1_TxDqsDlyTg3_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P1_TxDqsDlyTg3_un_px_SHIFT (0U)
/*! TxDqsDlyTg3_un_px - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P1_TxDqsDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P1_TxDqsDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P1_TxDqsDlyTg3_un_px_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL0_B1_P1 - Data TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P1_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
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
/*! DfeCtrl - DFE may be used with MajorModeDbyte=011 only 00 - DFE off 01 - DFE on 10 - Train DFE0
 *    Amplifier 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
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
/*! DrvStrenFSDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P1_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B1_P1 - TX equalization impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P1_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull down output impedance used in equalization.
 */
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
/*! TxPreP - 4 bit binary trim for the driver pull up slew rate. */
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

/*! @name RXENDLYTG0_U1_P1 - Trained Receive Enable Delay (For Timing Group 0) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P1_RxEnDlyTg0_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P1_RxEnDlyTg0_un_px_SHIFT (0U)
/*! RxEnDlyTg0_un_px - Trained Receive Enable Delay (For Timing Group 0) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P1_RxEnDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P1_RxEnDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P1_RxEnDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG1_U1_P1 - Trained Receive Enable Delay (For Timing Group 1) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P1_RxEnDlyTg1_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P1_RxEnDlyTg1_un_px_SHIFT (0U)
/*! RxEnDlyTg1_un_px - Trained Receive Enable Delay (For Timing Group 1) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P1_RxEnDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P1_RxEnDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P1_RxEnDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG2_U1_P1 - Trained Receive Enable Delay (For Timing Group 2) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P1_RxEnDlyTg2_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P1_RxEnDlyTg2_un_px_SHIFT (0U)
/*! RxEnDlyTg2_un_px - Trained Receive Enable Delay (For Timing Group 2) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P1_RxEnDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P1_RxEnDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P1_RxEnDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG3_U1_P1 - Trained Receive Enable Delay (For Timing Group 3) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P1_RxEnDlyTg3_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P1_RxEnDlyTg3_un_px_SHIFT (0U)
/*! RxEnDlyTg3_un_px - Trained Receive Enable Delay (For Timing Group 3) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P1_RxEnDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P1_RxEnDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P1_RxEnDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U1_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P1_RxClkDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P1_RxClkDlyTg0_un_px_SHIFT (0U)
/*! RxClkDlyTg0_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P1_RxClkDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P1_RxClkDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P1_RxClkDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U1_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P1_RxClkDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P1_RxClkDlyTg1_un_px_SHIFT (0U)
/*! RxClkDlyTg1_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P1_RxClkDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P1_RxClkDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P1_RxClkDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U1_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P1_RxClkDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P1_RxClkDlyTg2_un_px_SHIFT (0U)
/*! RxClkDlyTg2_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P1_RxClkDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P1_RxClkDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P1_RxClkDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U1_P1 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P1_RxClkDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P1_RxClkDlyTg3_un_px_SHIFT (0U)
/*! RxClkDlyTg3_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P1_RxClkDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P1_RxClkDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P1_RxClkDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U1_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P1_RxClkcDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P1_RxClkcDlyTg0_un_px_SHIFT (0U)
/*! RxClkcDlyTg0_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P1_RxClkcDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P1_RxClkcDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P1_RxClkcDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U1_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P1_RxClkcDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P1_RxClkcDlyTg1_un_px_SHIFT (0U)
/*! RxClkcDlyTg1_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P1_RxClkcDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P1_RxClkcDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P1_RxClkcDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U1_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P1_RxClkcDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P1_RxClkcDlyTg2_un_px_SHIFT (0U)
/*! RxClkcDlyTg2_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P1_RxClkcDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P1_RxClkcDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P1_RxClkcDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U1_P1 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P1_RxClkcDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P1_RxClkcDlyTg3_un_px_SHIFT (0U)
/*! RxClkcDlyTg3_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P1_RxClkcDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P1_RxClkcDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P1_RxClkcDlyTg3_un_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R1_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P1_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P1_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P1_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P1_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P1_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R1_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P1_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P1_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P1_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P1_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P1_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R1_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P1_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P1_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P1_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P1_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P1_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R1_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P1_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P1_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P1_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P1_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P1_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U1_P1 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P1_TxDqsDlyTg0_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P1_TxDqsDlyTg0_un_px_SHIFT (0U)
/*! TxDqsDlyTg0_un_px - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P1_TxDqsDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P1_TxDqsDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P1_TxDqsDlyTg0_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U1_P1 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P1_TxDqsDlyTg1_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P1_TxDqsDlyTg1_un_px_SHIFT (0U)
/*! TxDqsDlyTg1_un_px - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P1_TxDqsDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P1_TxDqsDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P1_TxDqsDlyTg1_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U1_P1 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P1_TxDqsDlyTg2_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P1_TxDqsDlyTg2_un_px_SHIFT (0U)
/*! TxDqsDlyTg2_un_px - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P1_TxDqsDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P1_TxDqsDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P1_TxDqsDlyTg2_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U1_P1 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P1_TxDqsDlyTg3_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P1_TxDqsDlyTg3_un_px_SHIFT (0U)
/*! TxDqsDlyTg3_un_px - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P1_TxDqsDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P1_TxDqsDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P1_TxDqsDlyTg3_un_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R2_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P1_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P1_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P1_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P1_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P1_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R2_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P1_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P1_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P1_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P1_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P1_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R2_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P1_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P1_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P1_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P1_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P1_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R2_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P1_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P1_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P1_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P1_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P1_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R3_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P1_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P1_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P1_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P1_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P1_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R3_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P1_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P1_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P1_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P1_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P1_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R3_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P1_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P1_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P1_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P1_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P1_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R3_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P1_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P1_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P1_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P1_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P1_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R4_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P1_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P1_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P1_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P1_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P1_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R4_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P1_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P1_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P1_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P1_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P1_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R4_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P1_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P1_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P1_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P1_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P1_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R4_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P1_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P1_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P1_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P1_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P1_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R5_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P1_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P1_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P1_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P1_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P1_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R5_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P1_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P1_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P1_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P1_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P1_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R5_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P1_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P1_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P1_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P1_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P1_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R5_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P1_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P1_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P1_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P1_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P1_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R6_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P1_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P1_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P1_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P1_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P1_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R6_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P1_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P1_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P1_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P1_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P1_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R6_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P1_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P1_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P1_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P1_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P1_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R6_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P1_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P1_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P1_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P1_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P1_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R7_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P1_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P1_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P1_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P1_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P1_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R7_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P1_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P1_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P1_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P1_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P1_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R7_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P1_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P1_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P1_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P1_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P1_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R7_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P1_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P1_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P1_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P1_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P1_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R8_P1 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P1_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P1_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P1_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P1_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P1_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R8_P1 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P1_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P1_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P1_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P1_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P1_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R8_P1 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P1_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P1_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P1_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P1_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P1_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R8_P1 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P1_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P1_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P1_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P1_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P1_TxDqDlyTg3_rn_px_MASK)
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

/*! @name TXIMPEDANCECTRL0_B0_P2 - Data TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P2_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
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
/*! DfeCtrl - DFE may be used with MajorModeDbyte=011 only 00 - DFE off 01 - DFE on 10 - Train DFE0
 *    Amplifier 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
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
#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P2_TxEqMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P2_TxEqMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P2_TxEqMode_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL1_B0_P2 - TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqP_SHIFT (0U)
/*! DrvStrenFSDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P2_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B0_P2 - TX equalization impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P2_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull down output impedance used in equalization.
 */
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
/*! TxPreP - 4 bit binary trim for the driver pull up slew rate. */
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

/*! @name RXENDLYTG0_U0_P2 - Trained Receive Enable Delay (For Timing Group 0) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P2_RxEnDlyTg0_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P2_RxEnDlyTg0_un_px_SHIFT (0U)
/*! RxEnDlyTg0_un_px - Trained Receive Enable Delay (For Timing Group 0) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P2_RxEnDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P2_RxEnDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P2_RxEnDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG1_U0_P2 - Trained Receive Enable Delay (For Timing Group 1) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P2_RxEnDlyTg1_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P2_RxEnDlyTg1_un_px_SHIFT (0U)
/*! RxEnDlyTg1_un_px - Trained Receive Enable Delay (For Timing Group 1) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P2_RxEnDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P2_RxEnDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P2_RxEnDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG2_U0_P2 - Trained Receive Enable Delay (For Timing Group 2) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P2_RxEnDlyTg2_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P2_RxEnDlyTg2_un_px_SHIFT (0U)
/*! RxEnDlyTg2_un_px - Trained Receive Enable Delay (For Timing Group 2) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P2_RxEnDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P2_RxEnDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P2_RxEnDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG3_U0_P2 - Trained Receive Enable Delay (For Timing Group 3) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P2_RxEnDlyTg3_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P2_RxEnDlyTg3_un_px_SHIFT (0U)
/*! RxEnDlyTg3_un_px - Trained Receive Enable Delay (For Timing Group 3) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P2_RxEnDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P2_RxEnDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P2_RxEnDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U0_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P2_RxClkDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P2_RxClkDlyTg0_un_px_SHIFT (0U)
/*! RxClkDlyTg0_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P2_RxClkDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P2_RxClkDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P2_RxClkDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U0_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P2_RxClkDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P2_RxClkDlyTg1_un_px_SHIFT (0U)
/*! RxClkDlyTg1_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P2_RxClkDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P2_RxClkDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P2_RxClkDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U0_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P2_RxClkDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P2_RxClkDlyTg2_un_px_SHIFT (0U)
/*! RxClkDlyTg2_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P2_RxClkDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P2_RxClkDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P2_RxClkDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U0_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P2_RxClkDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P2_RxClkDlyTg3_un_px_SHIFT (0U)
/*! RxClkDlyTg3_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P2_RxClkDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P2_RxClkDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P2_RxClkDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U0_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P2_RxClkcDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P2_RxClkcDlyTg0_un_px_SHIFT (0U)
/*! RxClkcDlyTg0_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P2_RxClkcDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P2_RxClkcDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P2_RxClkcDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U0_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P2_RxClkcDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P2_RxClkcDlyTg1_un_px_SHIFT (0U)
/*! RxClkcDlyTg1_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P2_RxClkcDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P2_RxClkcDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P2_RxClkcDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U0_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P2_RxClkcDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P2_RxClkcDlyTg2_un_px_SHIFT (0U)
/*! RxClkcDlyTg2_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P2_RxClkcDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P2_RxClkcDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P2_RxClkcDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U0_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P2_RxClkcDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P2_RxClkcDlyTg3_un_px_SHIFT (0U)
/*! RxClkcDlyTg3_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P2_RxClkcDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P2_RxClkcDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P2_RxClkcDlyTg3_un_px_MASK)
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

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P2_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P2_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P2_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P2_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P2_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R0_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P2_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P2_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P2_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P2_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P2_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R0_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P2_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P2_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P2_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P2_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P2_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R0_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P2_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P2_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P2_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P2_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P2_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U0_P2 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P2_TxDqsDlyTg0_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P2_TxDqsDlyTg0_un_px_SHIFT (0U)
/*! TxDqsDlyTg0_un_px - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P2_TxDqsDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P2_TxDqsDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P2_TxDqsDlyTg0_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U0_P2 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P2_TxDqsDlyTg1_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P2_TxDqsDlyTg1_un_px_SHIFT (0U)
/*! TxDqsDlyTg1_un_px - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P2_TxDqsDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P2_TxDqsDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P2_TxDqsDlyTg1_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U0_P2 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P2_TxDqsDlyTg2_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P2_TxDqsDlyTg2_un_px_SHIFT (0U)
/*! TxDqsDlyTg2_un_px - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P2_TxDqsDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P2_TxDqsDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P2_TxDqsDlyTg2_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U0_P2 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P2_TxDqsDlyTg3_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P2_TxDqsDlyTg3_un_px_SHIFT (0U)
/*! TxDqsDlyTg3_un_px - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P2_TxDqsDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P2_TxDqsDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P2_TxDqsDlyTg3_un_px_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL0_B1_P2 - Data TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P2_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
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
/*! DfeCtrl - DFE may be used with MajorModeDbyte=011 only 00 - DFE off 01 - DFE on 10 - Train DFE0
 *    Amplifier 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
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
/*! DrvStrenFSDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P2_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B1_P2 - TX equalization impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P2_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull down output impedance used in equalization.
 */
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
/*! TxPreP - 4 bit binary trim for the driver pull up slew rate. */
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

/*! @name RXENDLYTG0_U1_P2 - Trained Receive Enable Delay (For Timing Group 0) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P2_RxEnDlyTg0_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P2_RxEnDlyTg0_un_px_SHIFT (0U)
/*! RxEnDlyTg0_un_px - Trained Receive Enable Delay (For Timing Group 0) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P2_RxEnDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P2_RxEnDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P2_RxEnDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG1_U1_P2 - Trained Receive Enable Delay (For Timing Group 1) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P2_RxEnDlyTg1_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P2_RxEnDlyTg1_un_px_SHIFT (0U)
/*! RxEnDlyTg1_un_px - Trained Receive Enable Delay (For Timing Group 1) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P2_RxEnDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P2_RxEnDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P2_RxEnDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG2_U1_P2 - Trained Receive Enable Delay (For Timing Group 2) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P2_RxEnDlyTg2_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P2_RxEnDlyTg2_un_px_SHIFT (0U)
/*! RxEnDlyTg2_un_px - Trained Receive Enable Delay (For Timing Group 2) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P2_RxEnDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P2_RxEnDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P2_RxEnDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG3_U1_P2 - Trained Receive Enable Delay (For Timing Group 3) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P2_RxEnDlyTg3_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P2_RxEnDlyTg3_un_px_SHIFT (0U)
/*! RxEnDlyTg3_un_px - Trained Receive Enable Delay (For Timing Group 3) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P2_RxEnDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P2_RxEnDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P2_RxEnDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U1_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P2_RxClkDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P2_RxClkDlyTg0_un_px_SHIFT (0U)
/*! RxClkDlyTg0_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P2_RxClkDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P2_RxClkDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P2_RxClkDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U1_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P2_RxClkDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P2_RxClkDlyTg1_un_px_SHIFT (0U)
/*! RxClkDlyTg1_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P2_RxClkDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P2_RxClkDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P2_RxClkDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U1_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P2_RxClkDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P2_RxClkDlyTg2_un_px_SHIFT (0U)
/*! RxClkDlyTg2_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P2_RxClkDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P2_RxClkDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P2_RxClkDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U1_P2 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P2_RxClkDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P2_RxClkDlyTg3_un_px_SHIFT (0U)
/*! RxClkDlyTg3_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P2_RxClkDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P2_RxClkDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P2_RxClkDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U1_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P2_RxClkcDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P2_RxClkcDlyTg0_un_px_SHIFT (0U)
/*! RxClkcDlyTg0_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P2_RxClkcDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P2_RxClkcDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P2_RxClkcDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U1_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P2_RxClkcDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P2_RxClkcDlyTg1_un_px_SHIFT (0U)
/*! RxClkcDlyTg1_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P2_RxClkcDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P2_RxClkcDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P2_RxClkcDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U1_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P2_RxClkcDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P2_RxClkcDlyTg2_un_px_SHIFT (0U)
/*! RxClkcDlyTg2_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P2_RxClkcDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P2_RxClkcDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P2_RxClkcDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U1_P2 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P2_RxClkcDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P2_RxClkcDlyTg3_un_px_SHIFT (0U)
/*! RxClkcDlyTg3_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P2_RxClkcDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P2_RxClkcDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P2_RxClkcDlyTg3_un_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R1_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P2_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P2_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P2_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P2_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P2_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R1_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P2_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P2_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P2_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P2_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P2_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R1_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P2_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P2_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P2_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P2_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P2_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R1_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P2_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P2_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P2_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P2_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P2_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U1_P2 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P2_TxDqsDlyTg0_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P2_TxDqsDlyTg0_un_px_SHIFT (0U)
/*! TxDqsDlyTg0_un_px - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P2_TxDqsDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P2_TxDqsDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P2_TxDqsDlyTg0_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U1_P2 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P2_TxDqsDlyTg1_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P2_TxDqsDlyTg1_un_px_SHIFT (0U)
/*! TxDqsDlyTg1_un_px - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P2_TxDqsDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P2_TxDqsDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P2_TxDqsDlyTg1_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U1_P2 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P2_TxDqsDlyTg2_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P2_TxDqsDlyTg2_un_px_SHIFT (0U)
/*! TxDqsDlyTg2_un_px - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P2_TxDqsDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P2_TxDqsDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P2_TxDqsDlyTg2_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U1_P2 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P2_TxDqsDlyTg3_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P2_TxDqsDlyTg3_un_px_SHIFT (0U)
/*! TxDqsDlyTg3_un_px - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P2_TxDqsDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P2_TxDqsDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P2_TxDqsDlyTg3_un_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R2_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P2_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P2_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P2_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P2_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P2_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R2_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P2_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P2_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P2_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P2_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P2_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R2_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P2_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P2_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P2_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P2_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P2_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R2_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P2_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P2_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P2_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P2_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P2_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R3_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P2_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P2_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P2_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P2_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P2_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R3_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P2_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P2_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P2_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P2_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P2_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R3_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P2_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P2_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P2_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P2_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P2_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R3_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P2_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P2_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P2_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P2_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P2_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R4_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P2_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P2_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P2_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P2_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P2_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R4_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P2_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P2_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P2_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P2_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P2_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R4_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P2_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P2_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P2_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P2_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P2_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R4_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P2_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P2_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P2_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P2_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P2_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R5_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P2_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P2_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P2_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P2_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P2_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R5_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P2_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P2_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P2_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P2_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P2_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R5_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P2_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P2_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P2_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P2_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P2_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R5_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P2_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P2_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P2_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P2_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P2_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R6_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P2_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P2_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P2_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P2_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P2_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R6_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P2_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P2_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P2_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P2_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P2_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R6_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P2_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P2_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P2_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P2_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P2_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R6_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P2_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P2_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P2_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P2_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P2_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R7_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P2_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P2_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P2_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P2_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P2_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R7_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P2_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P2_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P2_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P2_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P2_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R7_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P2_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P2_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P2_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P2_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P2_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R7_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P2_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P2_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P2_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P2_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P2_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R8_P2 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P2_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P2_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P2_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P2_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P2_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R8_P2 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P2_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P2_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P2_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P2_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P2_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R8_P2 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P2_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P2_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P2_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P2_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P2_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R8_P2 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P2_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P2_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P2_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P2_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P2_TxDqDlyTg3_rn_px_MASK)
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

/*! @name TXIMPEDANCECTRL0_B0_P3 - Data TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B0_P3_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
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
/*! DfeCtrl - DFE may be used with MajorModeDbyte=011 only 00 - DFE off 01 - DFE on 10 - Train DFE0
 *    Amplifier 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
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
#define DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P3_TxEqMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P3_TxEqMode_SHIFT)) & DWC_DDRPHYA_DBYTE_TXEQUALIZATIONMODE_P3_TxEqMode_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL1_B0_P3 - TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqP_SHIFT (0U)
/*! DrvStrenFSDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B0_P3_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B0_P3 - TX equalization impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B0_P3_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull down output impedance used in equalization.
 */
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
/*! TxPreP - 4 bit binary trim for the driver pull up slew rate. */
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

/*! @name RXENDLYTG0_U0_P3 - Trained Receive Enable Delay (For Timing Group 0) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P3_RxEnDlyTg0_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P3_RxEnDlyTg0_un_px_SHIFT (0U)
/*! RxEnDlyTg0_un_px - Trained Receive Enable Delay (For Timing Group 0) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P3_RxEnDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P3_RxEnDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U0_P3_RxEnDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG1_U0_P3 - Trained Receive Enable Delay (For Timing Group 1) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P3_RxEnDlyTg1_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P3_RxEnDlyTg1_un_px_SHIFT (0U)
/*! RxEnDlyTg1_un_px - Trained Receive Enable Delay (For Timing Group 1) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P3_RxEnDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P3_RxEnDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U0_P3_RxEnDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG2_U0_P3 - Trained Receive Enable Delay (For Timing Group 2) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P3_RxEnDlyTg2_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P3_RxEnDlyTg2_un_px_SHIFT (0U)
/*! RxEnDlyTg2_un_px - Trained Receive Enable Delay (For Timing Group 2) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P3_RxEnDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P3_RxEnDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U0_P3_RxEnDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG3_U0_P3 - Trained Receive Enable Delay (For Timing Group 3) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P3_RxEnDlyTg3_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P3_RxEnDlyTg3_un_px_SHIFT (0U)
/*! RxEnDlyTg3_un_px - Trained Receive Enable Delay (For Timing Group 3) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P3_RxEnDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P3_RxEnDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U0_P3_RxEnDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U0_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P3_RxClkDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P3_RxClkDlyTg0_un_px_SHIFT (0U)
/*! RxClkDlyTg0_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P3_RxClkDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P3_RxClkDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U0_P3_RxClkDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U0_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P3_RxClkDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P3_RxClkDlyTg1_un_px_SHIFT (0U)
/*! RxClkDlyTg1_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P3_RxClkDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P3_RxClkDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U0_P3_RxClkDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U0_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P3_RxClkDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P3_RxClkDlyTg2_un_px_SHIFT (0U)
/*! RxClkDlyTg2_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P3_RxClkDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P3_RxClkDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U0_P3_RxClkDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U0_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P3_RxClkDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P3_RxClkDlyTg3_un_px_SHIFT (0U)
/*! RxClkDlyTg3_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P3_RxClkDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P3_RxClkDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U0_P3_RxClkDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U0_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P3_RxClkcDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P3_RxClkcDlyTg0_un_px_SHIFT (0U)
/*! RxClkcDlyTg0_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P3_RxClkcDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P3_RxClkcDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U0_P3_RxClkcDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U0_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P3_RxClkcDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P3_RxClkcDlyTg1_un_px_SHIFT (0U)
/*! RxClkcDlyTg1_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P3_RxClkcDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P3_RxClkcDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U0_P3_RxClkcDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U0_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P3_RxClkcDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P3_RxClkcDlyTg2_un_px_SHIFT (0U)
/*! RxClkcDlyTg2_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P3_RxClkcDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P3_RxClkcDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U0_P3_RxClkcDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U0_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P3_RxClkcDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P3_RxClkcDlyTg3_un_px_SHIFT (0U)
/*! RxClkcDlyTg3_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P3_RxClkcDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P3_RxClkcDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U0_P3_RxClkcDlyTg3_un_px_MASK)
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

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P3_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P3_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P3_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P3_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R0_P3_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R0_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P3_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P3_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P3_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P3_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R0_P3_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R0_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P3_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P3_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P3_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P3_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R0_P3_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R0_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P3_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P3_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P3_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P3_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R0_P3_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U0_P3 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P3_TxDqsDlyTg0_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P3_TxDqsDlyTg0_un_px_SHIFT (0U)
/*! TxDqsDlyTg0_un_px - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P3_TxDqsDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P3_TxDqsDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U0_P3_TxDqsDlyTg0_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U0_P3 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P3_TxDqsDlyTg1_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P3_TxDqsDlyTg1_un_px_SHIFT (0U)
/*! TxDqsDlyTg1_un_px - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P3_TxDqsDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P3_TxDqsDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U0_P3_TxDqsDlyTg1_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U0_P3 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P3_TxDqsDlyTg2_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P3_TxDqsDlyTg2_un_px_SHIFT (0U)
/*! TxDqsDlyTg2_un_px - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P3_TxDqsDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P3_TxDqsDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U0_P3_TxDqsDlyTg2_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U0_P3 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P3_TxDqsDlyTg3_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P3_TxDqsDlyTg3_un_px_SHIFT (0U)
/*! TxDqsDlyTg3_un_px - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P3_TxDqsDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P3_TxDqsDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U0_P3_TxDqsDlyTg3_un_px_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL0_B1_P3 - Data TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqP_SHIFT (0U)
/*! DrvStrenDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL0_B1_P3_DrvStrenDqN_SHIFT (6U)
/*! DrvStrenDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull down output impedance.
 */
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
/*! DfeCtrl - DFE may be used with MajorModeDbyte=011 only 00 - DFE off 01 - DFE on 10 - Train DFE0
 *    Amplifier 11 - Train DFE1 Amplifier These settings are determined by PHY Training FW and
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
/*! DrvStrenFSDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqN_SHIFT (6U)
/*! DrvStrenFSDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit bus
 *    used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqN_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL1_B1_P3_DrvStrenFSDqN_MASK)
/*! @} */

/*! @name TXIMPEDANCECTRL2_B1_P3 - TX equalization impedance controls */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQHiDqP_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQHiDqP_SHIFT (0U)
/*! DrvStrenEQHiDqP - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull up output impedance used in equalization.
 */
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQHiDqP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQHiDqP_SHIFT)) & DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQHiDqP_MASK)

#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQLoDqN_MASK (0xFC0U)
#define DWC_DDRPHYA_DBYTE_TXIMPEDANCECTRL2_B1_P3_DrvStrenEQLoDqN_SHIFT (6U)
/*! DrvStrenEQLoDqN - Please Refer to Technology specific PHY DATABOOK for supported options 6 bit
 *    bus used to select the target pull down output impedance used in equalization.
 */
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
/*! TxPreP - 4 bit binary trim for the driver pull up slew rate. */
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

/*! @name RXENDLYTG0_U1_P3 - Trained Receive Enable Delay (For Timing Group 0) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P3_RxEnDlyTg0_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P3_RxEnDlyTg0_un_px_SHIFT (0U)
/*! RxEnDlyTg0_un_px - Trained Receive Enable Delay (For Timing Group 0) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P3_RxEnDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P3_RxEnDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG0_U1_P3_RxEnDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG1_U1_P3 - Trained Receive Enable Delay (For Timing Group 1) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P3_RxEnDlyTg1_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P3_RxEnDlyTg1_un_px_SHIFT (0U)
/*! RxEnDlyTg1_un_px - Trained Receive Enable Delay (For Timing Group 1) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P3_RxEnDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P3_RxEnDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG1_U1_P3_RxEnDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG2_U1_P3 - Trained Receive Enable Delay (For Timing Group 2) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P3_RxEnDlyTg2_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P3_RxEnDlyTg2_un_px_SHIFT (0U)
/*! RxEnDlyTg2_un_px - Trained Receive Enable Delay (For Timing Group 2) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P3_RxEnDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P3_RxEnDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG2_U1_P3_RxEnDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXENDLYTG3_U1_P3 - Trained Receive Enable Delay (For Timing Group 3) */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P3_RxEnDlyTg3_un_px_MASK (0x7FFU)
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P3_RxEnDlyTg3_un_px_SHIFT (0U)
/*! RxEnDlyTg3_un_px - Trained Receive Enable Delay (For Timing Group 3) Trained to set the delay
 *    from the memory-read command to the signal enabling the read DQS to generate read-data strobes.
 */
#define DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P3_RxEnDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P3_RxEnDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXENDLYTG3_U1_P3_RxEnDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG0_U1_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P3_RxClkDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P3_RxClkDlyTg0_un_px_SHIFT (0U)
/*! RxClkDlyTg0_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P3_RxClkDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P3_RxClkDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG0_U1_P3_RxClkDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG1_U1_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P3_RxClkDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P3_RxClkDlyTg1_un_px_SHIFT (0U)
/*! RxClkDlyTg1_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P3_RxClkDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P3_RxClkDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG1_U1_P3_RxClkDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG2_U1_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P3_RxClkDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P3_RxClkDlyTg2_un_px_SHIFT (0U)
/*! RxClkDlyTg2_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P3_RxClkDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P3_RxClkDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG2_U1_P3_RxClkDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKDLYTG3_U1_P3 - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P3_RxClkDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P3_RxClkDlyTg3_un_px_SHIFT (0U)
/*! RxClkDlyTg3_un_px - Trained Read DQS to RxClk Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P3_RxClkDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P3_RxClkDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKDLYTG3_U1_P3_RxClkDlyTg3_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG0_U1_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P3_RxClkcDlyTg0_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P3_RxClkcDlyTg0_un_px_SHIFT (0U)
/*! RxClkcDlyTg0_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P3_RxClkcDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P3_RxClkcDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG0_U1_P3_RxClkcDlyTg0_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG1_U1_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P3_RxClkcDlyTg1_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P3_RxClkcDlyTg1_un_px_SHIFT (0U)
/*! RxClkcDlyTg1_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P3_RxClkcDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P3_RxClkcDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG1_U1_P3_RxClkcDlyTg1_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG2_U1_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P3_RxClkcDlyTg2_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P3_RxClkcDlyTg2_un_px_SHIFT (0U)
/*! RxClkcDlyTg2_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P3_RxClkcDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P3_RxClkcDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG2_U1_P3_RxClkcDlyTg2_un_px_MASK)
/*! @} */

/*! @name RXCLKCDLYTG3_U1_P3 - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P3_RxClkcDlyTg3_un_px_MASK (0x3FU)
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P3_RxClkcDlyTg3_un_px_SHIFT (0U)
/*! RxClkcDlyTg3_un_px - Trained Read DQS_c to RxClkc Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P3_RxClkcDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P3_RxClkcDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_RXCLKCDLYTG3_U1_P3_RxClkcDlyTg3_un_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R1_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P3_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P3_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P3_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P3_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R1_P3_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R1_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P3_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P3_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P3_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P3_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R1_P3_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R1_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P3_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P3_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P3_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P3_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R1_P3_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R1_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P3_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P3_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P3_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P3_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R1_P3_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG0_U1_P3 - Write DQS Delay (Timing Group DEST=0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P3_TxDqsDlyTg0_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P3_TxDqsDlyTg0_un_px_SHIFT (0U)
/*! TxDqsDlyTg0_un_px - Write DQS Delay (Timing Group DEST=0). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P3_TxDqsDlyTg0_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P3_TxDqsDlyTg0_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG0_U1_P3_TxDqsDlyTg0_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG1_U1_P3 - Write DQS Delay (Timing Group DEST=1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P3_TxDqsDlyTg1_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P3_TxDqsDlyTg1_un_px_SHIFT (0U)
/*! TxDqsDlyTg1_un_px - Write DQS Delay (Timing Group DEST=1). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P3_TxDqsDlyTg1_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P3_TxDqsDlyTg1_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG1_U1_P3_TxDqsDlyTg1_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG2_U1_P3 - Write DQS Delay (Timing Group DEST=2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P3_TxDqsDlyTg2_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P3_TxDqsDlyTg2_un_px_SHIFT (0U)
/*! TxDqsDlyTg2_un_px - Write DQS Delay (Timing Group DEST=2). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P3_TxDqsDlyTg2_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P3_TxDqsDlyTg2_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG2_U1_P3_TxDqsDlyTg2_un_px_MASK)
/*! @} */

/*! @name TXDQSDLYTG3_U1_P3 - Write DQS Delay (Timing Group DEST=3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P3_TxDqsDlyTg3_un_px_MASK (0x3FFU)
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P3_TxDqsDlyTg3_un_px_SHIFT (0U)
/*! TxDqsDlyTg3_un_px - Write DQS Delay (Timing Group DEST=3). */
#define DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P3_TxDqsDlyTg3_un_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P3_TxDqsDlyTg3_un_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQSDLYTG3_U1_P3_TxDqsDlyTg3_un_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R2_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P3_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P3_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P3_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P3_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R2_P3_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R2_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P3_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P3_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P3_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P3_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R2_P3_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R2_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P3_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P3_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P3_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P3_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R2_P3_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R2_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P3_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P3_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P3_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P3_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R2_P3_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R3_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P3_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P3_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P3_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P3_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R3_P3_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R3_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P3_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P3_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P3_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P3_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R3_P3_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R3_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P3_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P3_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P3_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P3_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R3_P3_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R3_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P3_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P3_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P3_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P3_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R3_P3_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R4_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P3_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P3_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P3_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P3_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R4_P3_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R4_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P3_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P3_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P3_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P3_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R4_P3_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R4_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P3_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P3_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P3_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P3_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R4_P3_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R4_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P3_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P3_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P3_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P3_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R4_P3_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R5_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P3_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P3_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P3_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P3_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R5_P3_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R5_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P3_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P3_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P3_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P3_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R5_P3_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R5_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P3_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P3_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P3_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P3_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R5_P3_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R5_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P3_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P3_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P3_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P3_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R5_P3_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R6_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P3_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P3_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P3_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P3_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R6_P3_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R6_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P3_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P3_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P3_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P3_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R6_P3_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R6_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P3_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P3_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P3_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P3_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R6_P3_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R6_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P3_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P3_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P3_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P3_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R6_P3_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R7_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P3_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P3_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P3_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P3_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R7_P3_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R7_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P3_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P3_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P3_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P3_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R7_P3_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R7_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P3_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P3_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P3_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P3_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R7_P3_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R7_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P3_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P3_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P3_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P3_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R7_P3_TxDqDlyTg3_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG0_R8_P3 - Write DQ Delay (Timing Group 0). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P3_TxDqDlyTg0_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P3_TxDqDlyTg0_rn_px_SHIFT (0U)
/*! TxDqDlyTg0_rn_px - Write DQ Delay (Timing Group 0). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P3_TxDqDlyTg0_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P3_TxDqDlyTg0_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG0_R8_P3_TxDqDlyTg0_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG1_R8_P3 - Write DQ Delay (Timing Group 1). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P3_TxDqDlyTg1_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P3_TxDqDlyTg1_rn_px_SHIFT (0U)
/*! TxDqDlyTg1_rn_px - Write DQ Delay (Timing Group 1). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P3_TxDqDlyTg1_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P3_TxDqDlyTg1_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG1_R8_P3_TxDqDlyTg1_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG2_R8_P3 - Write DQ Delay (Timing Group 2). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P3_TxDqDlyTg2_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P3_TxDqDlyTg2_rn_px_SHIFT (0U)
/*! TxDqDlyTg2_rn_px - Write DQ Delay (Timing Group 2). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P3_TxDqDlyTg2_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P3_TxDqDlyTg2_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG2_R8_P3_TxDqDlyTg2_rn_px_MASK)
/*! @} */

/*! @name TXDQDLYTG3_R8_P3 - Write DQ Delay (Timing Group 3). */
/*! @{ */

#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P3_TxDqDlyTg3_rn_px_MASK (0x1FFU)
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P3_TxDqDlyTg3_rn_px_SHIFT (0U)
/*! TxDqDlyTg3_rn_px - Write DQ Delay (Timing Group 3). */
#define DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P3_TxDqDlyTg3_rn_px(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P3_TxDqDlyTg3_rn_px_SHIFT)) & DWC_DDRPHYA_DBYTE_TXDQDLYTG3_R8_P3_TxDqDlyTg3_rn_px_MASK)
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

