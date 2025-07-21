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
**         CMSIS Peripheral Access Layer for FRAMECOMPOSER
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
 * @file PERI_FRAMECOMPOSER.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FRAMECOMPOSER
 *
 * CMSIS Peripheral Access Layer for FRAMECOMPOSER
 */

#if !defined(PERI_FRAMECOMPOSER_H_)
#define PERI_FRAMECOMPOSER_H_                    /**< Symbol preventing repeated inclusion */

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
   -- FRAMECOMPOSER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FRAMECOMPOSER_Peripheral_Access_Layer FRAMECOMPOSER Peripheral Access Layer
 * @{
 */

/** FRAMECOMPOSER - Register Layout Typedef */
typedef struct {
  __IO uint8_t FC_INVIDCONF;                       /**< Frame Composer Input Video Configuration and HDCP Keepout Register, offset: 0x0 */
  __IO uint8_t FC_INHACTIV0;                       /**< Frame Composer Input Video HActive Pixels Register 0, offset: 0x1 */
  __IO uint8_t FC_INHACTIV1;                       /**< Frame Composer Input Video HActive Pixels Register 1, offset: 0x2 */
  __IO uint8_t FC_INHBLANK0;                       /**< Frame Composer Input Video HBlank Pixels Register 0, offset: 0x3 */
  __IO uint8_t FC_INHBLANK1;                       /**< Frame Composer Input Video HBlank Pixels Register 1, offset: 0x4 */
  __IO uint8_t FC_INVACTIV0;                       /**< Frame Composer Input Video VActive Pixels Register 0, offset: 0x5 */
  __IO uint8_t FC_INVACTIV1;                       /**< Frame Composer Input Video VActive Pixels Register 1, offset: 0x6 */
  __IO uint8_t FC_INVBLANK;                        /**< Frame Composer Input Video VBlank Pixels Register, offset: 0x7 */
  __IO uint8_t FC_HSYNCINDELAY0;                   /**< Frame Composer Input Video HSync Front Porch Register 0, offset: 0x8 */
  __IO uint8_t FC_HSYNCINDELAY1;                   /**< Frame Composer Input Video HSync Front Porch Register 1, offset: 0x9 */
  __IO uint8_t FC_HSYNCINWIDTH0;                   /**< Frame Composer Input Video HSync Width Register 0, offset: 0xA */
  __IO uint8_t FC_HSYNCINWIDTH1;                   /**< Frame Composer Input Video HSync Width Register 1, offset: 0xB */
  __IO uint8_t FC_VSYNCINDELAY;                    /**< Frame Composer Input Video VSync Front Porch Register, offset: 0xC */
  __IO uint8_t FC_VSYNCINWIDTH;                    /**< Frame Composer Input Video VSync Width Register, offset: 0xD */
  __IO uint8_t FC_INFREQ0;                         /**< Frame Composer Input Video Refresh Rate Register 0, offset: 0xE */
  __IO uint8_t FC_INFREQ1;                         /**< Frame Composer Input Video Refresh Rate Register 1, offset: 0xF */
  __IO uint8_t FC_INFREQ2;                         /**< Frame Composer Input Video Refresh Rate Register 2, offset: 0x10 */
  __IO uint8_t FC_CTRLDUR;                         /**< Frame Composer Control Period Duration Register, offset: 0x11 */
  __IO uint8_t FC_EXCTRLDUR;                       /**< Frame Composer Extended Control Period Duration Register, offset: 0x12 */
  __IO uint8_t FC_EXCTRLSPAC;                      /**< Frame Composer Extended Control Period Maximum Spacing Register, offset: 0x13 */
  __IO uint8_t FC_CH0PREAM;                        /**< Frame Composer Channel 0 Non-Preamble Data Register, offset: 0x14 */
  __IO uint8_t FC_CH1PREAM;                        /**< Frame Composer Channel 1 Non-Preamble Data Register, offset: 0x15 */
  __IO uint8_t FC_CH2PREAM;                        /**< Frame Composer Channel 2 Non-Preamble Data Register, offset: 0x16 */
  __IO uint8_t FC_AVICONF3;                        /**< Frame Composer AVI Packet Configuration Register 3, offset: 0x17 */
  __IO uint8_t FC_GCP;                             /**< Frame Composer GCP Packet Configuration Register, offset: 0x18 */
  __IO uint8_t FC_AVICONF0;                        /**< Frame Composer AVI Packet Configuration Register 0, offset: 0x19 */
  __IO uint8_t FC_AVICONF1;                        /**< Frame Composer AVI Packet Configuration Register 1, offset: 0x1A */
  __IO uint8_t FC_AVICONF2;                        /**< Frame Composer AVI Packet Configuration Register 2, offset: 0x1B */
  __IO uint8_t FC_AVIVID;                          /**< Frame Composer AVI Packet VIC Register, offset: 0x1C */
       uint8_t RESERVED_0[8];
  __IO uint8_t FC_AUDICONF0;                       /**< Frame Composer AUD Packet Configuration Register 0, offset: 0x25 */
  __IO uint8_t FC_AUDICONF1;                       /**< Frame Composer AUD Packet Configuration Register 1, offset: 0x26 */
  __IO uint8_t FC_AUDICONF2;                       /**< Frame Composer AUD Packet Configuration Register 2, offset: 0x27 */
  __IO uint8_t FC_AUDICONF3;                       /**< Frame Composer AUD Packet Configuration Register 3, offset: 0x28 */
  __IO uint8_t FC_VSDIEEEID0;                      /**< Frame Composer VSI Packet Data IEEE Register 0, offset: 0x29 */
  __IO uint8_t FC_VSDSIZE;                         /**< Frame Composer VSI Packet Data Size Register, offset: 0x2A */
       uint8_t RESERVED_1[5];
  __IO uint8_t FC_VSDIEEEID1;                      /**< Frame Composer VSI Packet Data IEEE Register 1, offset: 0x30 */
  __IO uint8_t FC_VSDIEEEID2;                      /**< Frame Composer VSI Packet Data IEEE Register 2, offset: 0x31 */
       uint8_t RESERVED_2[48];
  __IO uint8_t FC_SPDDEVICEINF;                    /**< Frame Composer SPD Packet Data Source Product Descriptor Register, offset: 0x62 */
  __IO uint8_t FC_AUDSCONF;                        /**< Frame Composer Audio Sample Flat and Layout Configuration Register, offset: 0x63 */
  __I  uint8_t FC_AUDSSTAT;                        /**< Frame Composer Audio Sample Flat and Layout Status Register, offset: 0x64 */
  __IO uint8_t FC_AUDSV;                           /**< Frame Composer Audio Sample Validity Flag Register, offset: 0x65 */
  __IO uint8_t FC_AUDSU;                           /**< Frame Composer Audio Sample User Flag Register, offset: 0x66 */
  __IO uint8_t FC_AUDSCHNL0;                       /**< Frame Composer Audio Sample Channel Status Configuration Register 0, offset: 0x67 */
  __IO uint8_t FC_AUDSCHNL1;                       /**< Frame Composer Audio Sample Channel Status Configuration Register 1, offset: 0x68 */
  __IO uint8_t FC_AUDSCHNL2;                       /**< Frame Composer Audio Sample Channel Status Configuration Register 2, offset: 0x69 */
  __IO uint8_t FC_AUDSCHNL3;                       /**< Frame Composer Audio Sample Channel Status Configuration Register 3, offset: 0x6A */
  __IO uint8_t FC_AUDSCHNL4;                       /**< Frame Composer Audio Sample Channel Status Configuration Register 4, offset: 0x6B */
  __IO uint8_t FC_AUDSCHNL5;                       /**< Frame Composer Audio Sample Channel Status Configuration Register 5, offset: 0x6C */
  __IO uint8_t FC_AUDSCHNL6;                       /**< Frame Composer Audio Sample Channel Status Configuration Register 6, offset: 0x6D */
  __IO uint8_t FC_AUDSCHNL7;                       /**< Frame Composer Audio Sample Channel Status Configuration Register 7, offset: 0x6E */
  __IO uint8_t FC_AUDSCHNL8;                       /**< Frame Composer Audio Sample Channel Status Configuration Register 8, offset: 0x6F */
       uint8_t RESERVED_3[3];
  __IO uint8_t FC_CTRLQHIGH;                       /**< Frame Composer Number of High Priority Packets Attended Configuration Register, offset: 0x73 */
  __IO uint8_t FC_CTRLQLOW;                        /**< Frame Composer Number of Low Priority Packets Attended Configuration Register, offset: 0x74 */
  __IO uint8_t FC_ACP0;                            /**< Frame Composer ACP Packet Type Configuration Register 0, offset: 0x75 */
       uint8_t RESERVED_4[12];
  __IO uint8_t FC_ACP16;                           /**< Frame Composer ACP Packet Body Configuration Register 16, offset: 0x82 */
  __IO uint8_t FC_ACP15;                           /**< Frame Composer ACP Packet Body Configuration Register 15, offset: 0x83 */
  __IO uint8_t FC_ACP14;                           /**< Frame Composer ACP Packet Body Configuration Register 14, offset: 0x84 */
  __IO uint8_t FC_ACP13;                           /**< Frame Composer ACP Packet Body Configuration Register 13, offset: 0x85 */
  __IO uint8_t FC_ACP12;                           /**< Frame Composer ACP Packet Body Configuration Register 12, offset: 0x86 */
  __IO uint8_t FC_ACP11;                           /**< Frame Composer ACP Packet Body Configuration Register 11, offset: 0x87 */
  __IO uint8_t FC_ACP10;                           /**< Frame Composer ACP Packet Body Configuration Register 10, offset: 0x88 */
  __IO uint8_t FC_ACP9;                            /**< Frame Composer ACP Packet Body Configuration Register 9, offset: 0x89 */
  __IO uint8_t FC_ACP8;                            /**< Frame Composer ACP Packet Body Configuration Register 8, offset: 0x8A */
  __IO uint8_t FC_ACP7;                            /**< Frame Composer ACP Packet Body Configuration Register 7, offset: 0x8B */
  __IO uint8_t FC_ACP6;                            /**< Frame Composer ACP Packet Body Configuration Register 6, offset: 0x8C */
  __IO uint8_t FC_ACP5;                            /**< Frame Composer ACP Packet Body Configuration Register 5, offset: 0x8D */
  __IO uint8_t FC_ACP4;                            /**< Frame Composer ACP Packet Body Configuration Register 4, offset: 0x8E */
  __IO uint8_t FC_ACP3;                            /**< Frame Composer ACP Packet Body Configuration Register 3, offset: 0x8F */
  __IO uint8_t FC_ACP2;                            /**< Frame Composer ACP Packet Body Configuration Register 2, offset: 0x90 */
  __IO uint8_t FC_ACP1;                            /**< Frame Composer ACP Packet Body Configuration Register 1, offset: 0x91 */
  __IO uint8_t FC_ISCR1_0;                         /**< Frame Composer ISRC1 Packet Status, Valid, and Continue Configuration Register, offset: 0x92 */
  __IO uint8_t FC_ISCR1_16;                        /**< Frame Composer ISRC1 Packet Body Register 16, offset: 0x93 */
  __IO uint8_t FC_ISCR1_15;                        /**< Frame Composer ISRC1 Packet Body Register 15, offset: 0x94 */
  __IO uint8_t FC_ISCR1_14;                        /**< Frame Composer ISRC1 Packet Body Register 14, offset: 0x95 */
  __IO uint8_t FC_ISCR1_13;                        /**< Frame Composer ISRC1 Packet Body Register 13, offset: 0x96 */
  __IO uint8_t FC_ISCR1_12;                        /**< Frame Composer ISRC1 Packet Body Register 12, offset: 0x97 */
  __IO uint8_t FC_ISCR1_11;                        /**< Frame Composer ISRC1 Packet Body Register 11, offset: 0x98 */
  __IO uint8_t FC_ISCR1_10;                        /**< Frame Composer ISRC1 Packet Body Register 10, offset: 0x99 */
  __IO uint8_t FC_ISCR1_9;                         /**< Frame Composer ISRC1 Packet Body Register 9, offset: 0x9A */
  __IO uint8_t FC_ISCR1_8;                         /**< Frame Composer ISRC1 Packet Body Register 8, offset: 0x9B */
  __IO uint8_t FC_ISCR1_7;                         /**< Frame Composer ISRC1 Packet Body Register 7, offset: 0x9C */
  __IO uint8_t FC_ISCR1_6;                         /**< Frame Composer ISRC1 Packet Body Register 6, offset: 0x9D */
  __IO uint8_t FC_ISCR1_5;                         /**< Frame Composer ISRC1 Packet Body Register 5, offset: 0x9E */
  __IO uint8_t FC_ISCR1_4;                         /**< Frame Composer ISRC1 Packet Body Register 4, offset: 0x9F */
  __IO uint8_t FC_ISCR1_3;                         /**< Frame Composer ISRC1 Packet Body Register 3, offset: 0xA0 */
  __IO uint8_t FC_ISCR1_2;                         /**< Frame Composer ISRC1 Packet Body Register 2, offset: 0xA1 */
  __IO uint8_t FC_ISCR1_1;                         /**< Frame Composer ISRC1 Packet Body Register 1, offset: 0xA2 */
  __IO uint8_t FC_ISCR2_15;                        /**< Frame Composer ISRC2 Packet Body Register 15, offset: 0xA3 */
  __IO uint8_t FC_ISCR2_14;                        /**< Frame Composer ISRC2 Packet Body Register 14, offset: 0xA4 */
  __IO uint8_t FC_ISCR2_13;                        /**< Frame Composer ISRC2 Packet Body Register 13, offset: 0xA5 */
  __IO uint8_t FC_ISCR2_12;                        /**< Frame Composer ISRC2 Packet Body Register 12, offset: 0xA6 */
  __IO uint8_t FC_ISCR2_11;                        /**< Frame Composer ISRC2 Packet Body Register 11, offset: 0xA7 */
  __IO uint8_t FC_ISCR2_10;                        /**< Frame Composer ISRC2 Packet Body Register 10, offset: 0xA8 */
  __IO uint8_t FC_ISCR2_9;                         /**< Frame Composer ISRC2 Packet Body Register 9, offset: 0xA9 */
  __IO uint8_t FC_ISCR2_8;                         /**< Frame Composer ISRC2 Packet Body Register 8, offset: 0xAA */
  __IO uint8_t FC_ISCR2_7;                         /**< Frame Composer ISRC2 Packet Body Register 7, offset: 0xAB */
  __IO uint8_t FC_ISCR2_6;                         /**< Frame Composer ISRC2 Packet Body Register 6, offset: 0xAC */
  __IO uint8_t FC_ISCR2_5;                         /**< Frame Composer ISRC2 Packet Body Register 5, offset: 0xAD */
  __IO uint8_t FC_ISCR2_4;                         /**< Frame Composer ISRC2 Packet Body Register 4, offset: 0xAE */
  __IO uint8_t FC_ISCR2_3;                         /**< Frame Composer ISRC2 Packet Body Register 3, offset: 0xAF */
  __IO uint8_t FC_ISCR2_2;                         /**< Frame Composer ISRC2 Packet Body Register 2, offset: 0xB0 */
  __IO uint8_t FC_ISCR2_1;                         /**< Frame Composer ISRC2 Packet Body Register 1, offset: 0xB1 */
  __IO uint8_t FC_ISCR2_0;                         /**< Frame Composer ISRC2 Packet Body Register 0, offset: 0xB2 */
  __IO uint8_t FC_DATAUTO0;                        /**< Frame Composer Data Island Auto Packet Scheduling Register 0 Configures the Frame Composer RDRB(1)/Manual(0) data island packet insertion for SPD, VSD, ISRC2, ISRC1 and ACP packets., offset: 0xB3 */
  __IO uint8_t FC_DATAUTO1;                        /**< Frame Composer Data Island Auto Packet Scheduling Register 1 Configures the Frame Composer (FC) RDRB frame interpolation for SPD, VSD, ISRC2, ISRC1 and ACP packet insertion on data island when FC is on RDRB mode for the listed packets., offset: 0xB4 */
  __IO uint8_t FC_DATAUTO2;                        /**< Frame Composer Data Island Auto packet scheduling Register 2 Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for SPD, VSD, ISRC2, ISRC1 and ACP packet insertion on data island when FC is on RDRB mode for the listed packets., offset: 0xB5 */
  __O  uint8_t FC_DATMAN;                          /**< Frame Composer Data Island Manual Packet Request Register Requests to the Frame Composer the data island packet insertion for NULL, SPD, VSD, ISRC2, ISRC1 and ACP packets when FC_DATAUTO0 bit is in manual mode for the packet requested., offset: 0xB6 */
  __IO uint8_t FC_DATAUTO3;                        /**< Frame Composer Data Island Auto Packet Scheduling Register 3 Configures the Frame Composer Automatic(1)/RDRB(0) data island packet insertion for AVI, GCP, AUDI and ACR packets., offset: 0xB7 */
  __IO uint8_t FC_RDRB0;                           /**< Frame Composer Round Robin ACR Packet Insertion Register 0 Configures the Frame Composer (FC) RDRB frame interpolation for ACR packet insertion on data island when FC is on RDRB mode for this packet., offset: 0xB8 */
  __IO uint8_t FC_RDRB1;                           /**< Frame Composer Round Robin ACR Packet Insertion Register 1 Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for the ACR packet insertion on data island when FC is on RDRB mode this packet., offset: 0xB9 */
  __IO uint8_t FC_RDRB2;                           /**< Frame Composer Round Robin AUDI Packet Insertion Register 2 Configures the Frame Composer (FC) RDRB frame interpolation for AUDI packet insertion on data island when FC is on RDRB mode for this packet., offset: 0xBA */
  __IO uint8_t FC_RDRB3;                           /**< Frame Composer Round Robin AUDI Packet Insertion Register 3 Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for the AUDI packet insertion on data island when FC is on RDRB mode this packet., offset: 0xBB */
  __IO uint8_t FC_RDRB4;                           /**< Frame Composer Round Robin GCP Packet Insertion Register 4 Configures the Frame Composer (FC) RDRB frame interpolation for GCP packet insertion on data island when FC is on RDRB mode for this packet., offset: 0xBC */
  __IO uint8_t FC_RDRB5;                           /**< Frame Composer Round Robin GCP Packet Insertion Register 5 Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for the GCP packet insertion on data island when FC is on RDRB mode this packet., offset: 0xBD */
  __IO uint8_t FC_RDRB6;                           /**< Frame Composer Round Robin AVI Packet Insertion Register 6 Configures the Frame Composer (FC) RDRB frame interpolation for AVI packet insertion on data island when FC is on RDRB mode for this packet., offset: 0xBE */
  __IO uint8_t FC_RDRB7;                           /**< Frame Composer Round Robin AVI Packet Insertion Register 7 Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for the AVI packet insertion on data island when FC is on RDRB mode this packet., offset: 0xBF */
  __IO uint8_t FC_RDRB8;                           /**< Frame Composer Round Robin AMP Packet Insertion Register 8, offset: 0xC0 */
  __IO uint8_t FC_RDRB9;                           /**< Frame Composer Round Robin AMP Packet Insertion Register 9, offset: 0xC1 */
  __IO uint8_t FC_RDRB10;                          /**< Frame Composer Round Robin NTSC VBI Packet Insertion Register 10, offset: 0xC2 */
  __IO uint8_t FC_RDRB11;                          /**< Frame Composer Round Robin NTSC VBI Packet Insertion Register 11, offset: 0xC3 */
  __IO uint8_t FC_RDRB12;                          /**< Frame Composer Round Robin DRM Packet Insertion Register 12, offset: 0xC4 */
  __IO uint8_t FC_RDRB13;                          /**< Frame Composer Round Robin DRM Packet Insertion Register 13, offset: 0xC5 */
       uint8_t RESERVED_5[12];
  __IO uint8_t FC_MASK0;                           /**< Frame Composer Packet Interrupt Mask Register 0, offset: 0xD2 */
       uint8_t RESERVED_6[3];
  __IO uint8_t FC_MASK1;                           /**< Frame Composer Packet Interrupt Mask Register 1, offset: 0xD6 */
       uint8_t RESERVED_7[3];
  __IO uint8_t FC_MASK2;                           /**< Frame Composer High/Low Priority Overflow and DRM Interrupt Mask Register 2, offset: 0xDA */
       uint8_t RESERVED_8[5];
  __IO uint8_t FC_PRCONF;                          /**< Frame Composer Pixel Repetition Configuration Register, offset: 0xE0 */
  __IO uint8_t FC_SCRAMBLER_CTRL;                  /**< Frame Composer Scrambler Control, offset: 0xE1 */
  __IO uint8_t FC_MULTISTREAM_CTRL;                /**< Frame Composer Multi-Stream Audio Control, offset: 0xE2 */
  __IO uint8_t FC_PACKET_TX_EN;                    /**< Frame Composer Packet Transmission Control, offset: 0xE3 */
       uint8_t RESERVED_9[4];
  __IO uint8_t FC_ACTSPC_HDLR_CFG;                 /**< Frame Composer Active Space Control, offset: 0xE8 */
  __IO uint8_t FC_INVACT_2D_0;                     /**< Frame Composer Input Video 2D VActive Pixels Register 0, offset: 0xE9 */
  __IO uint8_t FC_INVACT_2D_1;                     /**< Frame Composer Input Video VActive pixels Register 1, offset: 0xEA */
       uint8_t RESERVED_10[21];
  __I  uint8_t FC_GMD_STAT;                        /**< Frame Composer GMD Packet Status Register Gamut metadata packet status bit information for no_current_gmd, next_gmd_field, gmd_packet_sequence and current_gamut_seq_num., offset: 0x100 */
  __IO uint8_t FC_GMD_EN;                          /**< Frame Composer GMD Packet Enable Register This register enables Gamut metadata (GMD) packet transmission., offset: 0x101 */
  __O  uint8_t FC_GMD_UP;                          /**< Frame Composer GMD Packet Update Register This register performs an GMD packet content update according to the configured packet body (FC_GMD_PB0 to FC_GMD_PB27) and packet header (FC_GMD_HB)., offset: 0x102 */
  __IO uint8_t FC_GMD_CONF;                        /**< Frame Composer GMD Packet Schedule Configuration Register This register configures the number of GMD packets to be inserted per frame (starting always in the line where the active Vsync appears) and the line spacing between the transmitted GMD packets., offset: 0x103 */
  __IO uint8_t FC_GMD_HB;                          /**< Frame Composer GMD Packet Profile and Gamut Sequence Configuration Register This register configures the GMD packet header affected_gamut_seq_num and gmd_profile bits., offset: 0x104 */
       uint8_t RESERVED_11[35];
  __IO uint8_t FC_AMP_HB1;                         /**< Frame Composer AMP Packet Header Register 1, offset: 0x128 */
  __IO uint8_t FC_AMP_HB2;                         /**< Frame Composer AMP Packet Header Register 2, offset: 0x129 */
       uint8_t RESERVED_12[30];
  __IO uint8_t FC_NVBI_HB1;                        /**< Frame Composer NTSC VBI Packet Header Register 1, offset: 0x148 */
  __IO uint8_t FC_NVBI_HB2;                        /**< Frame Composer NTSC VBI Packet Header Register 2, offset: 0x149 */
       uint8_t RESERVED_13[29];
  __O  uint8_t FC_DRM_UP;                          /**< Frame Composer DRM Packet Update Register This register performs an DRM packet content update according to the configured packet body (FC_DRM_PB0 to FC_DRM_PB27) and packet header (FC_DRM_HB)., offset: 0x167 */
       uint8_t RESERVED_14[152];
  __IO uint8_t FC_DBGFORCE;                        /**< Frame Composer video/audio Force Enable Register This register allows to force the controller to output audio and video data the values configured in the FC_DBGAUD and FC_DBGTMDS registers., offset: 0x200 */
  __IO uint8_t FC_DBGAUD0CH0;                      /**< Frame Composer Audio Data Channel 0 Register 0 Configures the audio fixed data to be used in channel 0 when in fixed audio selection., offset: 0x201 */
  __IO uint8_t FC_DBGAUD1CH0;                      /**< Frame Composer Audio Data Channel 0 Register 1 Configures the audio fixed data to be used in channel 0 when in fixed audio selection., offset: 0x202 */
  __IO uint8_t FC_DBGAUD2CH0;                      /**< Frame Composer Audio Data Channel 0 Register 2 Configures the audio fixed data to be used in channel 0 when in fixed audio selection., offset: 0x203 */
  __IO uint8_t FC_DBGAUD0CH1;                      /**< Frame Composer Audio Data Channel 1 Register 0 Configures the audio fixed data to be used in channel 1 when in fixed audio selection., offset: 0x204 */
  __IO uint8_t FC_DBGAUD1CH1;                      /**< Frame Composer Audio Data Channel 1 Register 1 Configures the audio fixed data to be used in channel 1 when in fixed audio selection., offset: 0x205 */
  __IO uint8_t FC_DBGAUD2CH1;                      /**< Frame Composer Audio Data Channel 1 Register 2 Configures the audio fixed data to be used in channel 1 when in fixed audio selection., offset: 0x206 */
  __IO uint8_t FC_DBGAUD0CH2;                      /**< Frame Composer Audio Data Channel 2 Register 0 Configures the audio fixed data to be used in channel 2 when in fixed audio selection., offset: 0x207 */
  __IO uint8_t FC_DBGAUD1CH2;                      /**< Frame Composer Audio Data Channel 2 Register 1 Configures the audio fixed data to be used in channel 2 when in fixed audio selection., offset: 0x208 */
  __IO uint8_t FC_DBGAUD2CH2;                      /**< Frame Composer Audio Data Channel 2 Register 2 Configures the audio fixed data to be used in channel 2 when in fixed audio selection., offset: 0x209 */
  __IO uint8_t FC_DBGAUD0CH3;                      /**< Frame Composer Audio Data Channel 3 Register 0 Configures the audio fixed data to be used in channel 3 when in fixed audio selection., offset: 0x20A */
  __IO uint8_t FC_DBGAUD1CH3;                      /**< Frame Composer Audio Data Channel 3 Register 1 Configures the audio fixed data to be used in channel 3 when in fixed audio selection., offset: 0x20B */
  __IO uint8_t FC_DBGAUD2CH3;                      /**< Frame Composer Audio Data Channel 3 Register 2 Configures the audio fixed data to be used in channel 3 when in fixed audio selection., offset: 0x20C */
  __IO uint8_t FC_DBGAUD0CH4;                      /**< Frame Composer Audio Data Channel 4 Register 0 Configures the audio fixed data to be used in channel 4 when in fixed audio selection., offset: 0x20D */
  __IO uint8_t FC_DBGAUD1CH4;                      /**< Frame Composer Audio Data Channel 4 Register 1 Configures the audio fixed data to be used in channel 4 when in fixed audio selection., offset: 0x20E */
  __IO uint8_t FC_DBGAUD2CH4;                      /**< Frame Composer Audio Data Channel 4 Register 2 Configures the audio fixed data to be used in channel 4 when in fixed audio selection., offset: 0x20F */
  __IO uint8_t FC_DBGAUD0CH5;                      /**< Frame Composer Audio Data Channel 5 Register 0 Configures the audio fixed data to be used in channel 5 when in fixed audio selection., offset: 0x210 */
  __IO uint8_t FC_DBGAUD1CH5;                      /**< Frame Composer Audio Data Channel 5 Register 1 Configures the audio fixed data to be used in channel 5 when in fixed audio selection., offset: 0x211 */
  __IO uint8_t FC_DBGAUD2CH5;                      /**< Frame Composer Audio Data Channel 5 Register 2 Configures the audio fixed data to be used in channel 5 when in fixed audio selection., offset: 0x212 */
  __IO uint8_t FC_DBGAUD0CH6;                      /**< Frame Composer Audio Data Channel 6 Register 0 Configures the audio fixed data to be used in channel 6 when in fixed audio selection., offset: 0x213 */
  __IO uint8_t FC_DBGAUD1CH6;                      /**< Frame Composer Audio Data Channel 6 Register 1 Configures the audio fixed data to be used in channel 6 when in fixed audio selection., offset: 0x214 */
  __IO uint8_t FC_DBGAUD2CH6;                      /**< Frame Composer Audio Data Channel 6 Register 2 Configures the audio fixed data to be used in channel 6 when in fixed audio selection., offset: 0x215 */
  __IO uint8_t FC_DBGAUD0CH7;                      /**< Frame Composer Audio Data Channel 7 Register 0 Configures the audio fixed data to be used in channel 7 when in fixed audio selection., offset: 0x216 */
  __IO uint8_t FC_DBGAUD1CH7;                      /**< Frame Composer Audio Data Channel 7 Register 1 Configures the audio fixed data to be used in channel 7 when in fixed audio selection., offset: 0x217 */
  __IO uint8_t FC_DBGAUD2CH7;                      /**< Frame Composer Audio Data Channel 7 Register 2 Configures the audio fixed data to be used in channel 7 when in fixed audio selection., offset: 0x218 */
} FRAMECOMPOSER_Type;

/* ----------------------------------------------------------------------------
   -- FRAMECOMPOSER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FRAMECOMPOSER_Register_Masks FRAMECOMPOSER Register Masks
 * @{
 */

/*! @name FC_INVIDCONF - Frame Composer Input Video Configuration and HDCP Keepout Register */
/*! @{ */

#define FRAMECOMPOSER_FC_INVIDCONF_IN_I_P_MASK   (0x1U)
#define FRAMECOMPOSER_FC_INVIDCONF_IN_I_P_SHIFT  (0U)
/*! in_I_P - Input video mode: 1b: Interlaced 0b: Progressive */
#define FRAMECOMPOSER_FC_INVIDCONF_IN_I_P(x)     (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INVIDCONF_IN_I_P_SHIFT)) & FRAMECOMPOSER_FC_INVIDCONF_IN_I_P_MASK)

#define FRAMECOMPOSER_FC_INVIDCONF_R_V_BLANK_IN_OSC_MASK (0x2U)
#define FRAMECOMPOSER_FC_INVIDCONF_R_V_BLANK_IN_OSC_SHIFT (1U)
/*! r_v_blank_in_osc - Used for CEA861-D modes with fractional Vblank (for example, modes 5, 6, 7, 10, 11, 20, 21, and 22). */
#define FRAMECOMPOSER_FC_INVIDCONF_R_V_BLANK_IN_OSC(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INVIDCONF_R_V_BLANK_IN_OSC_SHIFT)) & FRAMECOMPOSER_FC_INVIDCONF_R_V_BLANK_IN_OSC_MASK)

#define FRAMECOMPOSER_FC_INVIDCONF_DVI_MODEZ_MASK (0x8U)
#define FRAMECOMPOSER_FC_INVIDCONF_DVI_MODEZ_SHIFT (3U)
/*! DVI_modez - Active low 0b: DVI mode selected 1b: HDMI mode selected */
#define FRAMECOMPOSER_FC_INVIDCONF_DVI_MODEZ(x)  (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INVIDCONF_DVI_MODEZ_SHIFT)) & FRAMECOMPOSER_FC_INVIDCONF_DVI_MODEZ_MASK)

#define FRAMECOMPOSER_FC_INVIDCONF_DE_IN_POLARITY_MASK (0x10U)
#define FRAMECOMPOSER_FC_INVIDCONF_DE_IN_POLARITY_SHIFT (4U)
/*! de_in_polarity - Data enable input polarity 1b: Active high 0b: Active low */
#define FRAMECOMPOSER_FC_INVIDCONF_DE_IN_POLARITY(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INVIDCONF_DE_IN_POLARITY_SHIFT)) & FRAMECOMPOSER_FC_INVIDCONF_DE_IN_POLARITY_MASK)

#define FRAMECOMPOSER_FC_INVIDCONF_HSYNC_IN_POLARITY_MASK (0x20U)
#define FRAMECOMPOSER_FC_INVIDCONF_HSYNC_IN_POLARITY_SHIFT (5U)
/*! hsync_in_polarity - Hsync input polarity 1b: Active high 0b: Active low */
#define FRAMECOMPOSER_FC_INVIDCONF_HSYNC_IN_POLARITY(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INVIDCONF_HSYNC_IN_POLARITY_SHIFT)) & FRAMECOMPOSER_FC_INVIDCONF_HSYNC_IN_POLARITY_MASK)

#define FRAMECOMPOSER_FC_INVIDCONF_VSYNC_IN_POLARITY_MASK (0x40U)
#define FRAMECOMPOSER_FC_INVIDCONF_VSYNC_IN_POLARITY_SHIFT (6U)
/*! vsync_in_polarity - Vsync input polarity 1b: Active high 0b: Active low */
#define FRAMECOMPOSER_FC_INVIDCONF_VSYNC_IN_POLARITY(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INVIDCONF_VSYNC_IN_POLARITY_SHIFT)) & FRAMECOMPOSER_FC_INVIDCONF_VSYNC_IN_POLARITY_MASK)

#define FRAMECOMPOSER_FC_INVIDCONF_HDCP_KEEPOUT_MASK (0x80U)
#define FRAMECOMPOSER_FC_INVIDCONF_HDCP_KEEPOUT_SHIFT (7U)
/*! HDCP_keepout - Start/stop HDCP keepout window generation 1b: Active */
#define FRAMECOMPOSER_FC_INVIDCONF_HDCP_KEEPOUT(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INVIDCONF_HDCP_KEEPOUT_SHIFT)) & FRAMECOMPOSER_FC_INVIDCONF_HDCP_KEEPOUT_MASK)
/*! @} */

/*! @name FC_INHACTIV0 - Frame Composer Input Video HActive Pixels Register 0 */
/*! @{ */

#define FRAMECOMPOSER_FC_INHACTIV0_H_IN_ACTIV_MASK (0xFFU)
#define FRAMECOMPOSER_FC_INHACTIV0_H_IN_ACTIV_SHIFT (0U)
/*! H_in_activ - Input video Horizontal active pixel region width. */
#define FRAMECOMPOSER_FC_INHACTIV0_H_IN_ACTIV(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INHACTIV0_H_IN_ACTIV_SHIFT)) & FRAMECOMPOSER_FC_INHACTIV0_H_IN_ACTIV_MASK)
/*! @} */

/*! @name FC_INHACTIV1 - Frame Composer Input Video HActive Pixels Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV_MASK (0xFU)
#define FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV_SHIFT (0U)
/*! H_in_activ - Input video Horizontal active pixel region width */
#define FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV_SHIFT)) & FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV_MASK)

#define FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV_12_MASK (0x10U)
#define FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV_12_SHIFT (4U)
/*! H_in_activ_12 - Input video Horizontal active pixel region width (0 . */
#define FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV_12(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV_12_SHIFT)) & FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV_12_MASK)

#define FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV_13_MASK (0x20U)
#define FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV_13_SHIFT (5U)
/*! H_in_activ_13 - Input video Horizontal active pixel region width (0 . */
#define FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV_13(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV_13_SHIFT)) & FRAMECOMPOSER_FC_INHACTIV1_H_IN_ACTIV_13_MASK)
/*! @} */

/*! @name FC_INHBLANK0 - Frame Composer Input Video HBlank Pixels Register 0 */
/*! @{ */

#define FRAMECOMPOSER_FC_INHBLANK0_H_IN_BLANK_MASK (0xFFU)
#define FRAMECOMPOSER_FC_INHBLANK0_H_IN_BLANK_SHIFT (0U)
/*! H_in_blank - Input video Horizontal blanking pixel region width. */
#define FRAMECOMPOSER_FC_INHBLANK0_H_IN_BLANK(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INHBLANK0_H_IN_BLANK_SHIFT)) & FRAMECOMPOSER_FC_INHBLANK0_H_IN_BLANK_MASK)
/*! @} */

/*! @name FC_INHBLANK1 - Frame Composer Input Video HBlank Pixels Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_INHBLANK1_H_IN_BLANK_MASK (0x3U)
#define FRAMECOMPOSER_FC_INHBLANK1_H_IN_BLANK_SHIFT (0U)
/*! H_in_blank - Input video Horizontal blanking pixel region width this bit field holds bits 9:8 of
 *    number of Horizontal blanking pixels.
 */
#define FRAMECOMPOSER_FC_INHBLANK1_H_IN_BLANK(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INHBLANK1_H_IN_BLANK_SHIFT)) & FRAMECOMPOSER_FC_INHBLANK1_H_IN_BLANK_MASK)

#define FRAMECOMPOSER_FC_INHBLANK1_H_IN_BLANK_12_MASK (0x1CU)
#define FRAMECOMPOSER_FC_INHBLANK1_H_IN_BLANK_12_SHIFT (2U)
/*! H_in_blank_12 - Input video Horizontal blanking pixel region width If configuration parameter
 *    DWC_HDMI_TX_14 = True (1), this bit field holds bit 12:10 of number of horizontal blanking
 *    pixels.
 */
#define FRAMECOMPOSER_FC_INHBLANK1_H_IN_BLANK_12(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INHBLANK1_H_IN_BLANK_12_SHIFT)) & FRAMECOMPOSER_FC_INHBLANK1_H_IN_BLANK_12_MASK)
/*! @} */

/*! @name FC_INVACTIV0 - Frame Composer Input Video VActive Pixels Register 0 */
/*! @{ */

#define FRAMECOMPOSER_FC_INVACTIV0_V_IN_ACTIV_MASK (0xFFU)
#define FRAMECOMPOSER_FC_INVACTIV0_V_IN_ACTIV_SHIFT (0U)
/*! V_in_activ - Input video Vertical active pixel region width. */
#define FRAMECOMPOSER_FC_INVACTIV0_V_IN_ACTIV(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INVACTIV0_V_IN_ACTIV_SHIFT)) & FRAMECOMPOSER_FC_INVACTIV0_V_IN_ACTIV_MASK)
/*! @} */

/*! @name FC_INVACTIV1 - Frame Composer Input Video VActive Pixels Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_INVACTIV1_V_IN_ACTIV_MASK (0x7U)
#define FRAMECOMPOSER_FC_INVACTIV1_V_IN_ACTIV_SHIFT (0U)
/*! V_in_activ - Input video Vertical active pixel region width. */
#define FRAMECOMPOSER_FC_INVACTIV1_V_IN_ACTIV(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INVACTIV1_V_IN_ACTIV_SHIFT)) & FRAMECOMPOSER_FC_INVACTIV1_V_IN_ACTIV_MASK)

#define FRAMECOMPOSER_FC_INVACTIV1_V_IN_ACTIV_12_11_MASK (0x18U)
#define FRAMECOMPOSER_FC_INVACTIV1_V_IN_ACTIV_12_11_SHIFT (3U)
/*! V_in_activ_12_11 - Input video Vertical active pixel region width. */
#define FRAMECOMPOSER_FC_INVACTIV1_V_IN_ACTIV_12_11(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INVACTIV1_V_IN_ACTIV_12_11_SHIFT)) & FRAMECOMPOSER_FC_INVACTIV1_V_IN_ACTIV_12_11_MASK)
/*! @} */

/*! @name FC_INVBLANK - Frame Composer Input Video VBlank Pixels Register */
/*! @{ */

#define FRAMECOMPOSER_FC_INVBLANK_V_IN_BLANK_MASK (0xFFU)
#define FRAMECOMPOSER_FC_INVBLANK_V_IN_BLANK_SHIFT (0U)
/*! V_in_blank - Input video Vertical blanking pixel region width. */
#define FRAMECOMPOSER_FC_INVBLANK_V_IN_BLANK(x)  (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INVBLANK_V_IN_BLANK_SHIFT)) & FRAMECOMPOSER_FC_INVBLANK_V_IN_BLANK_MASK)
/*! @} */

/*! @name FC_HSYNCINDELAY0 - Frame Composer Input Video HSync Front Porch Register 0 */
/*! @{ */

#define FRAMECOMPOSER_FC_HSYNCINDELAY0_H_IN_DELAY_MASK (0xFFU)
#define FRAMECOMPOSER_FC_HSYNCINDELAY0_H_IN_DELAY_SHIFT (0U)
/*! H_in_delay - Input video Hsync active edge delay. */
#define FRAMECOMPOSER_FC_HSYNCINDELAY0_H_IN_DELAY(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_HSYNCINDELAY0_H_IN_DELAY_SHIFT)) & FRAMECOMPOSER_FC_HSYNCINDELAY0_H_IN_DELAY_MASK)
/*! @} */

/*! @name FC_HSYNCINDELAY1 - Frame Composer Input Video HSync Front Porch Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_HSYNCINDELAY1_H_IN_DELAY_MASK (0x7U)
#define FRAMECOMPOSER_FC_HSYNCINDELAY1_H_IN_DELAY_SHIFT (0U)
/*! H_in_delay - Input video Horizontal active edge delay. */
#define FRAMECOMPOSER_FC_HSYNCINDELAY1_H_IN_DELAY(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_HSYNCINDELAY1_H_IN_DELAY_SHIFT)) & FRAMECOMPOSER_FC_HSYNCINDELAY1_H_IN_DELAY_MASK)

#define FRAMECOMPOSER_FC_HSYNCINDELAY1_H_IN_DELAY_12_MASK (0x18U)
#define FRAMECOMPOSER_FC_HSYNCINDELAY1_H_IN_DELAY_12_SHIFT (3U)
/*! H_in_delay_12 - Input video Horizontal active edge delay. */
#define FRAMECOMPOSER_FC_HSYNCINDELAY1_H_IN_DELAY_12(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_HSYNCINDELAY1_H_IN_DELAY_12_SHIFT)) & FRAMECOMPOSER_FC_HSYNCINDELAY1_H_IN_DELAY_12_MASK)
/*! @} */

/*! @name FC_HSYNCINWIDTH0 - Frame Composer Input Video HSync Width Register 0 */
/*! @{ */

#define FRAMECOMPOSER_FC_HSYNCINWIDTH0_H_IN_WIDTH_MASK (0xFFU)
#define FRAMECOMPOSER_FC_HSYNCINWIDTH0_H_IN_WIDTH_SHIFT (0U)
/*! H_in_width - Input video Hsync active pulse width. */
#define FRAMECOMPOSER_FC_HSYNCINWIDTH0_H_IN_WIDTH(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_HSYNCINWIDTH0_H_IN_WIDTH_SHIFT)) & FRAMECOMPOSER_FC_HSYNCINWIDTH0_H_IN_WIDTH_MASK)
/*! @} */

/*! @name FC_HSYNCINWIDTH1 - Frame Composer Input Video HSync Width Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_HSYNCINWIDTH1_H_IN_WIDTH_MASK (0x1U)
#define FRAMECOMPOSER_FC_HSYNCINWIDTH1_H_IN_WIDTH_SHIFT (0U)
/*! H_in_width - Input video Hsync active pulse width. */
#define FRAMECOMPOSER_FC_HSYNCINWIDTH1_H_IN_WIDTH(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_HSYNCINWIDTH1_H_IN_WIDTH_SHIFT)) & FRAMECOMPOSER_FC_HSYNCINWIDTH1_H_IN_WIDTH_MASK)

#define FRAMECOMPOSER_FC_HSYNCINWIDTH1_H_IN_WIDTH_9_MASK (0x2U)
#define FRAMECOMPOSER_FC_HSYNCINWIDTH1_H_IN_WIDTH_9_SHIFT (1U)
/*! H_in_width_9 - Input video Hsync active pulse width. */
#define FRAMECOMPOSER_FC_HSYNCINWIDTH1_H_IN_WIDTH_9(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_HSYNCINWIDTH1_H_IN_WIDTH_9_SHIFT)) & FRAMECOMPOSER_FC_HSYNCINWIDTH1_H_IN_WIDTH_9_MASK)
/*! @} */

/*! @name FC_VSYNCINDELAY - Frame Composer Input Video VSync Front Porch Register */
/*! @{ */

#define FRAMECOMPOSER_FC_VSYNCINDELAY_V_IN_DELAY_MASK (0xFFU)
#define FRAMECOMPOSER_FC_VSYNCINDELAY_V_IN_DELAY_SHIFT (0U)
/*! V_in_delay - Input video Vsync active edge delay. */
#define FRAMECOMPOSER_FC_VSYNCINDELAY_V_IN_DELAY(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_VSYNCINDELAY_V_IN_DELAY_SHIFT)) & FRAMECOMPOSER_FC_VSYNCINDELAY_V_IN_DELAY_MASK)
/*! @} */

/*! @name FC_VSYNCINWIDTH - Frame Composer Input Video VSync Width Register */
/*! @{ */

#define FRAMECOMPOSER_FC_VSYNCINWIDTH_V_IN_WIDTH_MASK (0x3FU)
#define FRAMECOMPOSER_FC_VSYNCINWIDTH_V_IN_WIDTH_SHIFT (0U)
/*! V_in_width - Input video Vsync active pulse width. */
#define FRAMECOMPOSER_FC_VSYNCINWIDTH_V_IN_WIDTH(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_VSYNCINWIDTH_V_IN_WIDTH_SHIFT)) & FRAMECOMPOSER_FC_VSYNCINWIDTH_V_IN_WIDTH_MASK)
/*! @} */

/*! @name FC_INFREQ0 - Frame Composer Input Video Refresh Rate Register 0 */
/*! @{ */

#define FRAMECOMPOSER_FC_INFREQ0_INFREQ_MASK     (0xFFU)
#define FRAMECOMPOSER_FC_INFREQ0_INFREQ_SHIFT    (0U)
/*! infreq - Video refresh rate in Hz*1E3 format. */
#define FRAMECOMPOSER_FC_INFREQ0_INFREQ(x)       (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INFREQ0_INFREQ_SHIFT)) & FRAMECOMPOSER_FC_INFREQ0_INFREQ_MASK)
/*! @} */

/*! @name FC_INFREQ1 - Frame Composer Input Video Refresh Rate Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_INFREQ1_INFREQ_MASK     (0xFFU)
#define FRAMECOMPOSER_FC_INFREQ1_INFREQ_SHIFT    (0U)
/*! infreq - Video refresh rate in Hz*1E3 format. */
#define FRAMECOMPOSER_FC_INFREQ1_INFREQ(x)       (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INFREQ1_INFREQ_SHIFT)) & FRAMECOMPOSER_FC_INFREQ1_INFREQ_MASK)
/*! @} */

/*! @name FC_INFREQ2 - Frame Composer Input Video Refresh Rate Register 2 */
/*! @{ */

#define FRAMECOMPOSER_FC_INFREQ2_INFREQ_MASK     (0xFU)
#define FRAMECOMPOSER_FC_INFREQ2_INFREQ_SHIFT    (0U)
/*! infreq - Video refresh rate in Hz*1E3 format. */
#define FRAMECOMPOSER_FC_INFREQ2_INFREQ(x)       (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INFREQ2_INFREQ_SHIFT)) & FRAMECOMPOSER_FC_INFREQ2_INFREQ_MASK)
/*! @} */

/*! @name FC_CTRLDUR - Frame Composer Control Period Duration Register */
/*! @{ */

#define FRAMECOMPOSER_FC_CTRLDUR_CTRLPERIODDURATION_MASK (0xFFU)
#define FRAMECOMPOSER_FC_CTRLDUR_CTRLPERIODDURATION_SHIFT (0U)
/*! ctrlperiodduration - Configuration of the control period minimum duration (minimum of 12 pixel clock cycles; refer to HDMI 1. */
#define FRAMECOMPOSER_FC_CTRLDUR_CTRLPERIODDURATION(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_CTRLDUR_CTRLPERIODDURATION_SHIFT)) & FRAMECOMPOSER_FC_CTRLDUR_CTRLPERIODDURATION_MASK)
/*! @} */

/*! @name FC_EXCTRLDUR - Frame Composer Extended Control Period Duration Register */
/*! @{ */

#define FRAMECOMPOSER_FC_EXCTRLDUR_EXCTRLPERIODDURATION_MASK (0xFFU)
#define FRAMECOMPOSER_FC_EXCTRLDUR_EXCTRLPERIODDURATION_SHIFT (0U)
/*! exctrlperiodduration - Configuration of the extended control period minimum duration (minimum of 32 pixel clock cycles; refer to HDMI 1. */
#define FRAMECOMPOSER_FC_EXCTRLDUR_EXCTRLPERIODDURATION(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_EXCTRLDUR_EXCTRLPERIODDURATION_SHIFT)) & FRAMECOMPOSER_FC_EXCTRLDUR_EXCTRLPERIODDURATION_MASK)
/*! @} */

/*! @name FC_EXCTRLSPAC - Frame Composer Extended Control Period Maximum Spacing Register */
/*! @{ */

#define FRAMECOMPOSER_FC_EXCTRLSPAC_EXCTRLPERIODSPACING_MASK (0xFFU)
#define FRAMECOMPOSER_FC_EXCTRLSPAC_EXCTRLPERIODSPACING_SHIFT (0U)
/*! exctrlperiodspacing - Configuration of the maximum spacing between consecutive extended control
 *    periods (maximum of 50ms; refer to the applicable HDMI specification).
 */
#define FRAMECOMPOSER_FC_EXCTRLSPAC_EXCTRLPERIODSPACING(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_EXCTRLSPAC_EXCTRLPERIODSPACING_SHIFT)) & FRAMECOMPOSER_FC_EXCTRLSPAC_EXCTRLPERIODSPACING_MASK)
/*! @} */

/*! @name FC_CH0PREAM - Frame Composer Channel 0 Non-Preamble Data Register */
/*! @{ */

#define FRAMECOMPOSER_FC_CH0PREAM_CH0_PREAMBLE_FILTER_MASK (0xFFU)
#define FRAMECOMPOSER_FC_CH0PREAM_CH0_PREAMBLE_FILTER_SHIFT (0U)
/*! ch0_preamble_filter - When in control mode, configures 8 bits that fill the channel 0 data lines
 *    not used to transmit the preamble (for more clarification, refer to the HDMI 1.
 */
#define FRAMECOMPOSER_FC_CH0PREAM_CH0_PREAMBLE_FILTER(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_CH0PREAM_CH0_PREAMBLE_FILTER_SHIFT)) & FRAMECOMPOSER_FC_CH0PREAM_CH0_PREAMBLE_FILTER_MASK)
/*! @} */

/*! @name FC_CH1PREAM - Frame Composer Channel 1 Non-Preamble Data Register */
/*! @{ */

#define FRAMECOMPOSER_FC_CH1PREAM_CH1_PREAMBLE_FILTER_MASK (0x3FU)
#define FRAMECOMPOSER_FC_CH1PREAM_CH1_PREAMBLE_FILTER_SHIFT (0U)
/*! ch1_preamble_filter - When in control mode, configures 6 bits that fill the channel 1 data lines
 *    not used to transmit the preamble (for more clarification, refer to the HDMI 1.
 */
#define FRAMECOMPOSER_FC_CH1PREAM_CH1_PREAMBLE_FILTER(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_CH1PREAM_CH1_PREAMBLE_FILTER_SHIFT)) & FRAMECOMPOSER_FC_CH1PREAM_CH1_PREAMBLE_FILTER_MASK)
/*! @} */

/*! @name FC_CH2PREAM - Frame Composer Channel 2 Non-Preamble Data Register */
/*! @{ */

#define FRAMECOMPOSER_FC_CH2PREAM_CH2_PREAMBLE_FILTER_MASK (0x3FU)
#define FRAMECOMPOSER_FC_CH2PREAM_CH2_PREAMBLE_FILTER_SHIFT (0U)
/*! ch2_preamble_filter - When in control mode, configures 6 bits that fill the channel 2 data lines
 *    not used to transmit the preamble (for more clarification, refer to the HDMI 1.
 */
#define FRAMECOMPOSER_FC_CH2PREAM_CH2_PREAMBLE_FILTER(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_CH2PREAM_CH2_PREAMBLE_FILTER_SHIFT)) & FRAMECOMPOSER_FC_CH2PREAM_CH2_PREAMBLE_FILTER_MASK)
/*! @} */

/*! @name FC_AVICONF3 - Frame Composer AVI Packet Configuration Register 3 */
/*! @{ */

#define FRAMECOMPOSER_FC_AVICONF3_CN_MASK        (0x3U)
#define FRAMECOMPOSER_FC_AVICONF3_CN_SHIFT       (0U)
/*! CN - IT content type according to CEA the specification */
#define FRAMECOMPOSER_FC_AVICONF3_CN(x)          (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVICONF3_CN_SHIFT)) & FRAMECOMPOSER_FC_AVICONF3_CN_MASK)

#define FRAMECOMPOSER_FC_AVICONF3_YQ_MASK        (0xCU)
#define FRAMECOMPOSER_FC_AVICONF3_YQ_SHIFT       (2U)
/*! YQ - YCbCr Quantization range according to the CEA specification */
#define FRAMECOMPOSER_FC_AVICONF3_YQ(x)          (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVICONF3_YQ_SHIFT)) & FRAMECOMPOSER_FC_AVICONF3_YQ_MASK)
/*! @} */

/*! @name FC_GCP - Frame Composer GCP Packet Configuration Register */
/*! @{ */

#define FRAMECOMPOSER_FC_GCP_CLEAR_AVMUTE_MASK   (0x1U)
#define FRAMECOMPOSER_FC_GCP_CLEAR_AVMUTE_SHIFT  (0U)
/*! clear_avmute - Value of "clear_avmute" in the GCP packet */
#define FRAMECOMPOSER_FC_GCP_CLEAR_AVMUTE(x)     (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_GCP_CLEAR_AVMUTE_SHIFT)) & FRAMECOMPOSER_FC_GCP_CLEAR_AVMUTE_MASK)

#define FRAMECOMPOSER_FC_GCP_SET_AVMUTE_MASK     (0x2U)
#define FRAMECOMPOSER_FC_GCP_SET_AVMUTE_SHIFT    (1U)
/*! set_avmute - Value of "set_avmute" in the GCP packet Once the AVmute is set, the frame composer
 *    schedules the GCP packet with AVmute set in the packet scheduler to be sent once (may only be
 *    transmitted between the active edge of VSYNC and 384 pixels following this edge).
 */
#define FRAMECOMPOSER_FC_GCP_SET_AVMUTE(x)       (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_GCP_SET_AVMUTE_SHIFT)) & FRAMECOMPOSER_FC_GCP_SET_AVMUTE_MASK)

#define FRAMECOMPOSER_FC_GCP_DEFAULT_PHASE_MASK  (0x4U)
#define FRAMECOMPOSER_FC_GCP_DEFAULT_PHASE_SHIFT (2U)
/*! default_phase - Value of "default_phase" in the GCP packet. */
#define FRAMECOMPOSER_FC_GCP_DEFAULT_PHASE(x)    (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_GCP_DEFAULT_PHASE_SHIFT)) & FRAMECOMPOSER_FC_GCP_DEFAULT_PHASE_MASK)
/*! @} */

/*! @name FC_AVICONF0 - Frame Composer AVI Packet Configuration Register 0 */
/*! @{ */

#define FRAMECOMPOSER_FC_AVICONF0_RGC_YCC_INDICATION_MASK (0x3U)
#define FRAMECOMPOSER_FC_AVICONF0_RGC_YCC_INDICATION_SHIFT (0U)
/*! rgc_ycc_indication - Y1,Y0 RGB or YCbCr indicator */
#define FRAMECOMPOSER_FC_AVICONF0_RGC_YCC_INDICATION(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVICONF0_RGC_YCC_INDICATION_SHIFT)) & FRAMECOMPOSER_FC_AVICONF0_RGC_YCC_INDICATION_MASK)

#define FRAMECOMPOSER_FC_AVICONF0_BAR_INFORMATION_MASK (0xCU)
#define FRAMECOMPOSER_FC_AVICONF0_BAR_INFORMATION_SHIFT (2U)
/*! bar_information - Bar information data valid */
#define FRAMECOMPOSER_FC_AVICONF0_BAR_INFORMATION(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVICONF0_BAR_INFORMATION_SHIFT)) & FRAMECOMPOSER_FC_AVICONF0_BAR_INFORMATION_MASK)

#define FRAMECOMPOSER_FC_AVICONF0_SCAN_INFORMATION_MASK (0x30U)
#define FRAMECOMPOSER_FC_AVICONF0_SCAN_INFORMATION_SHIFT (4U)
/*! scan_information - Scan information */
#define FRAMECOMPOSER_FC_AVICONF0_SCAN_INFORMATION(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVICONF0_SCAN_INFORMATION_SHIFT)) & FRAMECOMPOSER_FC_AVICONF0_SCAN_INFORMATION_MASK)

#define FRAMECOMPOSER_FC_AVICONF0_ACTIVE_FORMAT_PRESENT_MASK (0x40U)
#define FRAMECOMPOSER_FC_AVICONF0_ACTIVE_FORMAT_PRESENT_SHIFT (6U)
/*! active_format_present - Active format present */
#define FRAMECOMPOSER_FC_AVICONF0_ACTIVE_FORMAT_PRESENT(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVICONF0_ACTIVE_FORMAT_PRESENT_SHIFT)) & FRAMECOMPOSER_FC_AVICONF0_ACTIVE_FORMAT_PRESENT_MASK)

#define FRAMECOMPOSER_FC_AVICONF0_RGC_YCC_INDICATION_2_MASK (0x80U)
#define FRAMECOMPOSER_FC_AVICONF0_RGC_YCC_INDICATION_2_SHIFT (7U)
/*! rgc_ycc_indication_2 - Y2, Bit 2 of rgc_ycc_indication */
#define FRAMECOMPOSER_FC_AVICONF0_RGC_YCC_INDICATION_2(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVICONF0_RGC_YCC_INDICATION_2_SHIFT)) & FRAMECOMPOSER_FC_AVICONF0_RGC_YCC_INDICATION_2_MASK)
/*! @} */

/*! @name FC_AVICONF1 - Frame Composer AVI Packet Configuration Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_AVICONF1_ACTIVE_ASPECT_RATIO_MASK (0xFU)
#define FRAMECOMPOSER_FC_AVICONF1_ACTIVE_ASPECT_RATIO_SHIFT (0U)
/*! active_aspect_ratio - Active aspect ratio */
#define FRAMECOMPOSER_FC_AVICONF1_ACTIVE_ASPECT_RATIO(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVICONF1_ACTIVE_ASPECT_RATIO_SHIFT)) & FRAMECOMPOSER_FC_AVICONF1_ACTIVE_ASPECT_RATIO_MASK)

#define FRAMECOMPOSER_FC_AVICONF1_PICTURE_ASPECT_RATIO_MASK (0x30U)
#define FRAMECOMPOSER_FC_AVICONF1_PICTURE_ASPECT_RATIO_SHIFT (4U)
/*! picture_aspect_ratio - Picture aspect ratio */
#define FRAMECOMPOSER_FC_AVICONF1_PICTURE_ASPECT_RATIO(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVICONF1_PICTURE_ASPECT_RATIO_SHIFT)) & FRAMECOMPOSER_FC_AVICONF1_PICTURE_ASPECT_RATIO_MASK)

#define FRAMECOMPOSER_FC_AVICONF1_COLORIMETRY_MASK (0xC0U)
#define FRAMECOMPOSER_FC_AVICONF1_COLORIMETRY_SHIFT (6U)
/*! Colorimetry - Colorimetry */
#define FRAMECOMPOSER_FC_AVICONF1_COLORIMETRY(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVICONF1_COLORIMETRY_SHIFT)) & FRAMECOMPOSER_FC_AVICONF1_COLORIMETRY_MASK)
/*! @} */

/*! @name FC_AVICONF2 - Frame Composer AVI Packet Configuration Register 2 */
/*! @{ */

#define FRAMECOMPOSER_FC_AVICONF2_NON_UNIFORM_PICTURE_SCALING_MASK (0x3U)
#define FRAMECOMPOSER_FC_AVICONF2_NON_UNIFORM_PICTURE_SCALING_SHIFT (0U)
/*! non_uniform_picture_scaling - Non-uniform picture scaling */
#define FRAMECOMPOSER_FC_AVICONF2_NON_UNIFORM_PICTURE_SCALING(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVICONF2_NON_UNIFORM_PICTURE_SCALING_SHIFT)) & FRAMECOMPOSER_FC_AVICONF2_NON_UNIFORM_PICTURE_SCALING_MASK)

#define FRAMECOMPOSER_FC_AVICONF2_QUANTIZATION_RANGE_MASK (0xCU)
#define FRAMECOMPOSER_FC_AVICONF2_QUANTIZATION_RANGE_SHIFT (2U)
/*! quantization_range - Quantization range */
#define FRAMECOMPOSER_FC_AVICONF2_QUANTIZATION_RANGE(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVICONF2_QUANTIZATION_RANGE_SHIFT)) & FRAMECOMPOSER_FC_AVICONF2_QUANTIZATION_RANGE_MASK)

#define FRAMECOMPOSER_FC_AVICONF2_EXTENDED_COLORIMETRY_MASK (0x70U)
#define FRAMECOMPOSER_FC_AVICONF2_EXTENDED_COLORIMETRY_SHIFT (4U)
/*! extended_colorimetry - Extended colorimetry */
#define FRAMECOMPOSER_FC_AVICONF2_EXTENDED_COLORIMETRY(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVICONF2_EXTENDED_COLORIMETRY_SHIFT)) & FRAMECOMPOSER_FC_AVICONF2_EXTENDED_COLORIMETRY_MASK)

#define FRAMECOMPOSER_FC_AVICONF2_IT_CONTENT_MASK (0x80U)
#define FRAMECOMPOSER_FC_AVICONF2_IT_CONTENT_SHIFT (7U)
/*! it_content - IT content */
#define FRAMECOMPOSER_FC_AVICONF2_IT_CONTENT(x)  (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVICONF2_IT_CONTENT_SHIFT)) & FRAMECOMPOSER_FC_AVICONF2_IT_CONTENT_MASK)
/*! @} */

/*! @name FC_AVIVID - Frame Composer AVI Packet VIC Register */
/*! @{ */

#define FRAMECOMPOSER_FC_AVIVID_FC_AVIVID_MASK   (0x7FU)
#define FRAMECOMPOSER_FC_AVIVID_FC_AVIVID_SHIFT  (0U)
/*! fc_avivid - Configures the AVI InfoFrame Video Identification code. */
#define FRAMECOMPOSER_FC_AVIVID_FC_AVIVID(x)     (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVIVID_FC_AVIVID_SHIFT)) & FRAMECOMPOSER_FC_AVIVID_FC_AVIVID_MASK)

#define FRAMECOMPOSER_FC_AVIVID_FC_AVIVID_7_MASK (0x80U)
#define FRAMECOMPOSER_FC_AVIVID_FC_AVIVID_7_SHIFT (7U)
/*! fc_avivid_7 - Bit 7 of fc_avivid register */
#define FRAMECOMPOSER_FC_AVIVID_FC_AVIVID_7(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AVIVID_FC_AVIVID_7_SHIFT)) & FRAMECOMPOSER_FC_AVIVID_FC_AVIVID_7_MASK)
/*! @} */

/*! @name FC_AUDICONF0 - Frame Composer AUD Packet Configuration Register 0 */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDICONF0_CT_MASK       (0xFU)
#define FRAMECOMPOSER_FC_AUDICONF0_CT_SHIFT      (0U)
/*! CT - Coding Type */
#define FRAMECOMPOSER_FC_AUDICONF0_CT(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDICONF0_CT_SHIFT)) & FRAMECOMPOSER_FC_AUDICONF0_CT_MASK)

#define FRAMECOMPOSER_FC_AUDICONF0_CC_MASK       (0x70U)
#define FRAMECOMPOSER_FC_AUDICONF0_CC_SHIFT      (4U)
/*! CC - Channel count */
#define FRAMECOMPOSER_FC_AUDICONF0_CC(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDICONF0_CC_SHIFT)) & FRAMECOMPOSER_FC_AUDICONF0_CC_MASK)
/*! @} */

/*! @name FC_AUDICONF1 - Frame Composer AUD Packet Configuration Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDICONF1_SF_MASK       (0x7U)
#define FRAMECOMPOSER_FC_AUDICONF1_SF_SHIFT      (0U)
/*! SF - Sampling frequency */
#define FRAMECOMPOSER_FC_AUDICONF1_SF(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDICONF1_SF_SHIFT)) & FRAMECOMPOSER_FC_AUDICONF1_SF_MASK)

#define FRAMECOMPOSER_FC_AUDICONF1_SS_MASK       (0x30U)
#define FRAMECOMPOSER_FC_AUDICONF1_SS_SHIFT      (4U)
/*! SS - Sampling size */
#define FRAMECOMPOSER_FC_AUDICONF1_SS(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDICONF1_SS_SHIFT)) & FRAMECOMPOSER_FC_AUDICONF1_SS_MASK)
/*! @} */

/*! @name FC_AUDICONF2 - Frame Composer AUD Packet Configuration Register 2 */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDICONF2_CA_MASK       (0xFFU)
#define FRAMECOMPOSER_FC_AUDICONF2_CA_SHIFT      (0U)
/*! CA - Channel allocation */
#define FRAMECOMPOSER_FC_AUDICONF2_CA(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDICONF2_CA_SHIFT)) & FRAMECOMPOSER_FC_AUDICONF2_CA_MASK)
/*! @} */

/*! @name FC_AUDICONF3 - Frame Composer AUD Packet Configuration Register 3 */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDICONF3_LSV_MASK      (0xFU)
#define FRAMECOMPOSER_FC_AUDICONF3_LSV_SHIFT     (0U)
/*! LSV - Level shift value (for down mixing) */
#define FRAMECOMPOSER_FC_AUDICONF3_LSV(x)        (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDICONF3_LSV_SHIFT)) & FRAMECOMPOSER_FC_AUDICONF3_LSV_MASK)

#define FRAMECOMPOSER_FC_AUDICONF3_DM_INH_MASK   (0x10U)
#define FRAMECOMPOSER_FC_AUDICONF3_DM_INH_SHIFT  (4U)
/*! DM_INH - Down mix enable */
#define FRAMECOMPOSER_FC_AUDICONF3_DM_INH(x)     (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDICONF3_DM_INH_SHIFT)) & FRAMECOMPOSER_FC_AUDICONF3_DM_INH_MASK)

#define FRAMECOMPOSER_FC_AUDICONF3_LFEPBL_MASK   (0x60U)
#define FRAMECOMPOSER_FC_AUDICONF3_LFEPBL_SHIFT  (5U)
/*! LFEPBL - LFE playback information LFEPBL1, LFEPBL0 LFE playback level as compared to the other channels. */
#define FRAMECOMPOSER_FC_AUDICONF3_LFEPBL(x)     (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDICONF3_LFEPBL_SHIFT)) & FRAMECOMPOSER_FC_AUDICONF3_LFEPBL_MASK)
/*! @} */

/*! @name FC_VSDIEEEID0 - Frame Composer VSI Packet Data IEEE Register 0 */
/*! @{ */

#define FRAMECOMPOSER_FC_VSDIEEEID0_IEEE_MASK    (0xFFU)
#define FRAMECOMPOSER_FC_VSDIEEEID0_IEEE_SHIFT   (0U)
/*! IEEE - This register configures the Vendor Specific InfoFrame IEEE registration identifier. */
#define FRAMECOMPOSER_FC_VSDIEEEID0_IEEE(x)      (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_VSDIEEEID0_IEEE_SHIFT)) & FRAMECOMPOSER_FC_VSDIEEEID0_IEEE_MASK)
/*! @} */

/*! @name FC_VSDSIZE - Frame Composer VSI Packet Data Size Register */
/*! @{ */

#define FRAMECOMPOSER_FC_VSDSIZE_VSDSIZE_MASK    (0x1FU)
#define FRAMECOMPOSER_FC_VSDSIZE_VSDSIZE_SHIFT   (0U)
/*! VSDSIZE - Packet size as described in the HDMI Vendor Specific InfoFrame (from the HDMI specification). */
#define FRAMECOMPOSER_FC_VSDSIZE_VSDSIZE(x)      (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_VSDSIZE_VSDSIZE_SHIFT)) & FRAMECOMPOSER_FC_VSDSIZE_VSDSIZE_MASK)
/*! @} */

/*! @name FC_VSDIEEEID1 - Frame Composer VSI Packet Data IEEE Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_VSDIEEEID1_IEEE_MASK    (0xFFU)
#define FRAMECOMPOSER_FC_VSDIEEEID1_IEEE_SHIFT   (0U)
/*! IEEE - This register configures the Vendor Specific InfoFrame IEEE registration identifier. */
#define FRAMECOMPOSER_FC_VSDIEEEID1_IEEE(x)      (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_VSDIEEEID1_IEEE_SHIFT)) & FRAMECOMPOSER_FC_VSDIEEEID1_IEEE_MASK)
/*! @} */

/*! @name FC_VSDIEEEID2 - Frame Composer VSI Packet Data IEEE Register 2 */
/*! @{ */

#define FRAMECOMPOSER_FC_VSDIEEEID2_IEEE_MASK    (0xFFU)
#define FRAMECOMPOSER_FC_VSDIEEEID2_IEEE_SHIFT   (0U)
/*! IEEE - This register configures the Vendor Specific InfoFrame IEEE registration identifier. */
#define FRAMECOMPOSER_FC_VSDIEEEID2_IEEE(x)      (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_VSDIEEEID2_IEEE_SHIFT)) & FRAMECOMPOSER_FC_VSDIEEEID2_IEEE_MASK)
/*! @} */

/*! @name FC_SPDDEVICEINF - Frame Composer SPD Packet Data Source Product Descriptor Register */
/*! @{ */

#define FRAMECOMPOSER_FC_SPDDEVICEINF_FC_SPDDEVICEINF_MASK (0xFFU)
#define FRAMECOMPOSER_FC_SPDDEVICEINF_FC_SPDDEVICEINF_SHIFT (0U)
/*! fc_spddeviceinf - Frame Composer SPD Packet Data Source Product Descriptor Register */
#define FRAMECOMPOSER_FC_SPDDEVICEINF_FC_SPDDEVICEINF(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_SPDDEVICEINF_FC_SPDDEVICEINF_SHIFT)) & FRAMECOMPOSER_FC_SPDDEVICEINF_FC_SPDDEVICEINF_MASK)
/*! @} */

/*! @name FC_AUDSCONF - Frame Composer Audio Sample Flat and Layout Configuration Register */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDSCONF_AUD_PACKET_LAYOUT_MASK (0x1U)
#define FRAMECOMPOSER_FC_AUDSCONF_AUD_PACKET_LAYOUT_SHIFT (0U)
/*! aud_packet_layout - Set the audio packet layout to be sent in the packet: 1b: layout 1 0b:
 *    layout 0 If DWC_HDMI_TX_20 is defined and register field fc_multistream_ctrl.
 */
#define FRAMECOMPOSER_FC_AUDSCONF_AUD_PACKET_LAYOUT(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCONF_AUD_PACKET_LAYOUT_SHIFT)) & FRAMECOMPOSER_FC_AUDSCONF_AUD_PACKET_LAYOUT_MASK)

#define FRAMECOMPOSER_FC_AUDSCONF_AUD_PACKET_SAMPFLT_MASK (0xF0U)
#define FRAMECOMPOSER_FC_AUDSCONF_AUD_PACKET_SAMPFLT_SHIFT (4U)
/*! aud_packet_sampflt - Set the audio packet sample flat value to be sent on the packet. */
#define FRAMECOMPOSER_FC_AUDSCONF_AUD_PACKET_SAMPFLT(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCONF_AUD_PACKET_SAMPFLT_SHIFT)) & FRAMECOMPOSER_FC_AUDSCONF_AUD_PACKET_SAMPFLT_MASK)
/*! @} */

/*! @name FC_AUDSSTAT - Frame Composer Audio Sample Flat and Layout Status Register */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDSSTAT_PACKET_SAMPPRS_MASK (0xFU)
#define FRAMECOMPOSER_FC_AUDSSTAT_PACKET_SAMPPRS_SHIFT (0U)
/*! packet_sampprs - Shows the data sample present indication of the last Audio sample packet sent by the HDMI TX Controller. */
#define FRAMECOMPOSER_FC_AUDSSTAT_PACKET_SAMPPRS(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSSTAT_PACKET_SAMPPRS_SHIFT)) & FRAMECOMPOSER_FC_AUDSSTAT_PACKET_SAMPPRS_MASK)
/*! @} */

/*! @name FC_AUDSV - Frame Composer Audio Sample Validity Flag Register */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDSV_V0L_MASK          (0x1U)
#define FRAMECOMPOSER_FC_AUDSV_V0L_SHIFT         (0U)
/*! V0l - Set validity bit "V" for Channel 0, Left */
#define FRAMECOMPOSER_FC_AUDSV_V0L(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSV_V0L_SHIFT)) & FRAMECOMPOSER_FC_AUDSV_V0L_MASK)

#define FRAMECOMPOSER_FC_AUDSV_V1L_MASK          (0x2U)
#define FRAMECOMPOSER_FC_AUDSV_V1L_SHIFT         (1U)
/*! V1l - Set validity bit "V" for Channel 1, Left */
#define FRAMECOMPOSER_FC_AUDSV_V1L(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSV_V1L_SHIFT)) & FRAMECOMPOSER_FC_AUDSV_V1L_MASK)

#define FRAMECOMPOSER_FC_AUDSV_V2L_MASK          (0x4U)
#define FRAMECOMPOSER_FC_AUDSV_V2L_SHIFT         (2U)
/*! V2l - Set validity bit "V" for Channel 2, Left */
#define FRAMECOMPOSER_FC_AUDSV_V2L(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSV_V2L_SHIFT)) & FRAMECOMPOSER_FC_AUDSV_V2L_MASK)

#define FRAMECOMPOSER_FC_AUDSV_V3L_MASK          (0x8U)
#define FRAMECOMPOSER_FC_AUDSV_V3L_SHIFT         (3U)
/*! V3l - Set validity bit "V" for Channel 3, Left */
#define FRAMECOMPOSER_FC_AUDSV_V3L(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSV_V3L_SHIFT)) & FRAMECOMPOSER_FC_AUDSV_V3L_MASK)

#define FRAMECOMPOSER_FC_AUDSV_V0R_MASK          (0x10U)
#define FRAMECOMPOSER_FC_AUDSV_V0R_SHIFT         (4U)
/*! V0r - Set validity bit "V" for Channel 0, Right */
#define FRAMECOMPOSER_FC_AUDSV_V0R(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSV_V0R_SHIFT)) & FRAMECOMPOSER_FC_AUDSV_V0R_MASK)

#define FRAMECOMPOSER_FC_AUDSV_V1R_MASK          (0x20U)
#define FRAMECOMPOSER_FC_AUDSV_V1R_SHIFT         (5U)
/*! V1r - Set validity bit "V" for Channel 1, Right */
#define FRAMECOMPOSER_FC_AUDSV_V1R(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSV_V1R_SHIFT)) & FRAMECOMPOSER_FC_AUDSV_V1R_MASK)

#define FRAMECOMPOSER_FC_AUDSV_V2R_MASK          (0x40U)
#define FRAMECOMPOSER_FC_AUDSV_V2R_SHIFT         (6U)
/*! V2r - Set validity bit "V" for Channel 2, Right */
#define FRAMECOMPOSER_FC_AUDSV_V2R(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSV_V2R_SHIFT)) & FRAMECOMPOSER_FC_AUDSV_V2R_MASK)

#define FRAMECOMPOSER_FC_AUDSV_V3R_MASK          (0x80U)
#define FRAMECOMPOSER_FC_AUDSV_V3R_SHIFT         (7U)
/*! V3r - Set validity bit "V" for Channel 3, Right */
#define FRAMECOMPOSER_FC_AUDSV_V3R(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSV_V3R_SHIFT)) & FRAMECOMPOSER_FC_AUDSV_V3R_MASK)
/*! @} */

/*! @name FC_AUDSU - Frame Composer Audio Sample User Flag Register */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDSU_U0L_MASK          (0x1U)
#define FRAMECOMPOSER_FC_AUDSU_U0L_SHIFT         (0U)
/*! U0l - Set user bit "U" for Channel 0, Left */
#define FRAMECOMPOSER_FC_AUDSU_U0L(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSU_U0L_SHIFT)) & FRAMECOMPOSER_FC_AUDSU_U0L_MASK)

#define FRAMECOMPOSER_FC_AUDSU_U1L_MASK          (0x2U)
#define FRAMECOMPOSER_FC_AUDSU_U1L_SHIFT         (1U)
/*! U1l - Set user bit "U" for Channel 1, Left */
#define FRAMECOMPOSER_FC_AUDSU_U1L(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSU_U1L_SHIFT)) & FRAMECOMPOSER_FC_AUDSU_U1L_MASK)

#define FRAMECOMPOSER_FC_AUDSU_U2L_MASK          (0x4U)
#define FRAMECOMPOSER_FC_AUDSU_U2L_SHIFT         (2U)
/*! U2l - Set user bit "U" for Channel 2, Left */
#define FRAMECOMPOSER_FC_AUDSU_U2L(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSU_U2L_SHIFT)) & FRAMECOMPOSER_FC_AUDSU_U2L_MASK)

#define FRAMECOMPOSER_FC_AUDSU_U3L_MASK          (0x8U)
#define FRAMECOMPOSER_FC_AUDSU_U3L_SHIFT         (3U)
/*! U3l - Set user bit "U" for Channel 3, Left */
#define FRAMECOMPOSER_FC_AUDSU_U3L(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSU_U3L_SHIFT)) & FRAMECOMPOSER_FC_AUDSU_U3L_MASK)

#define FRAMECOMPOSER_FC_AUDSU_U0R_MASK          (0x10U)
#define FRAMECOMPOSER_FC_AUDSU_U0R_SHIFT         (4U)
/*! U0r - Set user bit "U" for Channel 0, Right */
#define FRAMECOMPOSER_FC_AUDSU_U0R(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSU_U0R_SHIFT)) & FRAMECOMPOSER_FC_AUDSU_U0R_MASK)

#define FRAMECOMPOSER_FC_AUDSU_U1R_MASK          (0x20U)
#define FRAMECOMPOSER_FC_AUDSU_U1R_SHIFT         (5U)
/*! U1r - Set user bit "U" for Channel 1, Right */
#define FRAMECOMPOSER_FC_AUDSU_U1R(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSU_U1R_SHIFT)) & FRAMECOMPOSER_FC_AUDSU_U1R_MASK)

#define FRAMECOMPOSER_FC_AUDSU_U2R_MASK          (0x40U)
#define FRAMECOMPOSER_FC_AUDSU_U2R_SHIFT         (6U)
/*! U2r - Set user bit "U" for Channel 2, Right */
#define FRAMECOMPOSER_FC_AUDSU_U2R(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSU_U2R_SHIFT)) & FRAMECOMPOSER_FC_AUDSU_U2R_MASK)

#define FRAMECOMPOSER_FC_AUDSU_U3R_MASK          (0x80U)
#define FRAMECOMPOSER_FC_AUDSU_U3R_SHIFT         (7U)
/*! U3r - Set user bit "U" for Channel 3, Right */
#define FRAMECOMPOSER_FC_AUDSU_U3R(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSU_U3R_SHIFT)) & FRAMECOMPOSER_FC_AUDSU_U3R_MASK)
/*! @} */

/*! @name FC_AUDSCHNL0 - Frame Composer Audio Sample Channel Status Configuration Register 0 */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDSCHNL0_OIEC_COPYRIGHT_MASK (0x1U)
#define FRAMECOMPOSER_FC_AUDSCHNL0_OIEC_COPYRIGHT_SHIFT (0U)
/*! oiec_copyright - IEC Copyright indication */
#define FRAMECOMPOSER_FC_AUDSCHNL0_OIEC_COPYRIGHT(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL0_OIEC_COPYRIGHT_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL0_OIEC_COPYRIGHT_MASK)

#define FRAMECOMPOSER_FC_AUDSCHNL0_OIEC_CGMSA_MASK (0x30U)
#define FRAMECOMPOSER_FC_AUDSCHNL0_OIEC_CGMSA_SHIFT (4U)
/*! oiec_cgmsa - CGMS-A */
#define FRAMECOMPOSER_FC_AUDSCHNL0_OIEC_CGMSA(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL0_OIEC_CGMSA_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL0_OIEC_CGMSA_MASK)
/*! @} */

/*! @name FC_AUDSCHNL1 - Frame Composer Audio Sample Channel Status Configuration Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDSCHNL1_OIEC_CATEGORYCODE_MASK (0xFFU)
#define FRAMECOMPOSER_FC_AUDSCHNL1_OIEC_CATEGORYCODE_SHIFT (0U)
/*! oiec_categorycode - Category code */
#define FRAMECOMPOSER_FC_AUDSCHNL1_OIEC_CATEGORYCODE(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL1_OIEC_CATEGORYCODE_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL1_OIEC_CATEGORYCODE_MASK)
/*! @} */

/*! @name FC_AUDSCHNL2 - Frame Composer Audio Sample Channel Status Configuration Register 2 */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDSCHNL2_OIEC_SOURCENUMBER_MASK (0xFU)
#define FRAMECOMPOSER_FC_AUDSCHNL2_OIEC_SOURCENUMBER_SHIFT (0U)
/*! oiec_sourcenumber - Source number */
#define FRAMECOMPOSER_FC_AUDSCHNL2_OIEC_SOURCENUMBER(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL2_OIEC_SOURCENUMBER_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL2_OIEC_SOURCENUMBER_MASK)

#define FRAMECOMPOSER_FC_AUDSCHNL2_OIEC_PCMAUDIOMODE_MASK (0x70U)
#define FRAMECOMPOSER_FC_AUDSCHNL2_OIEC_PCMAUDIOMODE_SHIFT (4U)
/*! oiec_pcmaudiomode - PCM audio mode */
#define FRAMECOMPOSER_FC_AUDSCHNL2_OIEC_PCMAUDIOMODE(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL2_OIEC_PCMAUDIOMODE_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL2_OIEC_PCMAUDIOMODE_MASK)
/*! @} */

/*! @name FC_AUDSCHNL3 - Frame Composer Audio Sample Channel Status Configuration Register 3 */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDSCHNL3_OIEC_CHANNELNUMCR0_MASK (0xFU)
#define FRAMECOMPOSER_FC_AUDSCHNL3_OIEC_CHANNELNUMCR0_SHIFT (0U)
/*! oiec_channelnumcr0 - Channel number for first right sample */
#define FRAMECOMPOSER_FC_AUDSCHNL3_OIEC_CHANNELNUMCR0(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL3_OIEC_CHANNELNUMCR0_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL3_OIEC_CHANNELNUMCR0_MASK)

#define FRAMECOMPOSER_FC_AUDSCHNL3_OIEC_CHANNELNUMCR1_MASK (0xF0U)
#define FRAMECOMPOSER_FC_AUDSCHNL3_OIEC_CHANNELNUMCR1_SHIFT (4U)
/*! oiec_channelnumcr1 - Channel number for second right sample */
#define FRAMECOMPOSER_FC_AUDSCHNL3_OIEC_CHANNELNUMCR1(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL3_OIEC_CHANNELNUMCR1_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL3_OIEC_CHANNELNUMCR1_MASK)
/*! @} */

/*! @name FC_AUDSCHNL4 - Frame Composer Audio Sample Channel Status Configuration Register 4 */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDSCHNL4_OIEC_CHANNELNUMCR2_MASK (0xFU)
#define FRAMECOMPOSER_FC_AUDSCHNL4_OIEC_CHANNELNUMCR2_SHIFT (0U)
/*! oiec_channelnumcr2 - Channel number for third right sample */
#define FRAMECOMPOSER_FC_AUDSCHNL4_OIEC_CHANNELNUMCR2(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL4_OIEC_CHANNELNUMCR2_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL4_OIEC_CHANNELNUMCR2_MASK)

#define FRAMECOMPOSER_FC_AUDSCHNL4_OIEC_CHANNELNUMCR3_MASK (0xF0U)
#define FRAMECOMPOSER_FC_AUDSCHNL4_OIEC_CHANNELNUMCR3_SHIFT (4U)
/*! oiec_channelnumcr3 - Channel number for fourth right sample */
#define FRAMECOMPOSER_FC_AUDSCHNL4_OIEC_CHANNELNUMCR3(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL4_OIEC_CHANNELNUMCR3_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL4_OIEC_CHANNELNUMCR3_MASK)
/*! @} */

/*! @name FC_AUDSCHNL5 - Frame Composer Audio Sample Channel Status Configuration Register 5 */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDSCHNL5_OIEC_CHANNELNUMCL0_MASK (0xFU)
#define FRAMECOMPOSER_FC_AUDSCHNL5_OIEC_CHANNELNUMCL0_SHIFT (0U)
/*! oiec_channelnumcl0 - Channel number for first left sample */
#define FRAMECOMPOSER_FC_AUDSCHNL5_OIEC_CHANNELNUMCL0(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL5_OIEC_CHANNELNUMCL0_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL5_OIEC_CHANNELNUMCL0_MASK)

#define FRAMECOMPOSER_FC_AUDSCHNL5_OIEC_CHANNELNUMCL1_MASK (0xF0U)
#define FRAMECOMPOSER_FC_AUDSCHNL5_OIEC_CHANNELNUMCL1_SHIFT (4U)
/*! oiec_channelnumcl1 - Channel number for second left sample */
#define FRAMECOMPOSER_FC_AUDSCHNL5_OIEC_CHANNELNUMCL1(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL5_OIEC_CHANNELNUMCL1_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL5_OIEC_CHANNELNUMCL1_MASK)
/*! @} */

/*! @name FC_AUDSCHNL6 - Frame Composer Audio Sample Channel Status Configuration Register 6 */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDSCHNL6_OIEC_CHANNELNUMCL2_MASK (0xFU)
#define FRAMECOMPOSER_FC_AUDSCHNL6_OIEC_CHANNELNUMCL2_SHIFT (0U)
/*! oiec_channelnumcl2 - Channel number for third left sample */
#define FRAMECOMPOSER_FC_AUDSCHNL6_OIEC_CHANNELNUMCL2(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL6_OIEC_CHANNELNUMCL2_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL6_OIEC_CHANNELNUMCL2_MASK)

#define FRAMECOMPOSER_FC_AUDSCHNL6_OIEC_CHANNELNUMCL3_MASK (0xF0U)
#define FRAMECOMPOSER_FC_AUDSCHNL6_OIEC_CHANNELNUMCL3_SHIFT (4U)
/*! oiec_channelnumcl3 - Channel number for fourth left sample */
#define FRAMECOMPOSER_FC_AUDSCHNL6_OIEC_CHANNELNUMCL3(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL6_OIEC_CHANNELNUMCL3_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL6_OIEC_CHANNELNUMCL3_MASK)
/*! @} */

/*! @name FC_AUDSCHNL7 - Frame Composer Audio Sample Channel Status Configuration Register 7 */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_SAMPFREQ_MASK (0xFU)
#define FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_SAMPFREQ_SHIFT (0U)
/*! oiec_sampfreq - Sampling frequency */
#define FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_SAMPFREQ(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_SAMPFREQ_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_SAMPFREQ_MASK)

#define FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_CLKACCURACY_MASK (0x30U)
#define FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_CLKACCURACY_SHIFT (4U)
/*! oiec_clkaccuracy - Clock accuracy */
#define FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_CLKACCURACY(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_CLKACCURACY_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_CLKACCURACY_MASK)

#define FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_SAMPFREQ_EXT_MASK (0xC0U)
#define FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_SAMPFREQ_EXT_SHIFT (6U)
/*! oiec_sampfreq_ext - Sampling frequency (channel status bits 31 and 30) */
#define FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_SAMPFREQ_EXT(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_SAMPFREQ_EXT_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL7_OIEC_SAMPFREQ_EXT_MASK)
/*! @} */

/*! @name FC_AUDSCHNL8 - Frame Composer Audio Sample Channel Status Configuration Register 8 */
/*! @{ */

#define FRAMECOMPOSER_FC_AUDSCHNL8_OIEC_WORDLENGTH_MASK (0xFU)
#define FRAMECOMPOSER_FC_AUDSCHNL8_OIEC_WORDLENGTH_SHIFT (0U)
/*! oiec_wordlength - Word length configuration */
#define FRAMECOMPOSER_FC_AUDSCHNL8_OIEC_WORDLENGTH(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL8_OIEC_WORDLENGTH_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL8_OIEC_WORDLENGTH_MASK)

#define FRAMECOMPOSER_FC_AUDSCHNL8_OIEC_ORIGSAMPFREQ_MASK (0xF0U)
#define FRAMECOMPOSER_FC_AUDSCHNL8_OIEC_ORIGSAMPFREQ_SHIFT (4U)
/*! oiec_origsampfreq - Original sampling frequency */
#define FRAMECOMPOSER_FC_AUDSCHNL8_OIEC_ORIGSAMPFREQ(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AUDSCHNL8_OIEC_ORIGSAMPFREQ_SHIFT)) & FRAMECOMPOSER_FC_AUDSCHNL8_OIEC_ORIGSAMPFREQ_MASK)
/*! @} */

/*! @name FC_CTRLQHIGH - Frame Composer Number of High Priority Packets Attended Configuration Register */
/*! @{ */

#define FRAMECOMPOSER_FC_CTRLQHIGH_ONHIGHATTENDED_MASK (0x1FU)
#define FRAMECOMPOSER_FC_CTRLQHIGH_ONHIGHATTENDED_SHIFT (0U)
/*! onhighattended - Configures the number of high priority packets or audio sample packets
 *    consecutively attended before checking low priority queue status.
 */
#define FRAMECOMPOSER_FC_CTRLQHIGH_ONHIGHATTENDED(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_CTRLQHIGH_ONHIGHATTENDED_SHIFT)) & FRAMECOMPOSER_FC_CTRLQHIGH_ONHIGHATTENDED_MASK)
/*! @} */

/*! @name FC_CTRLQLOW - Frame Composer Number of Low Priority Packets Attended Configuration Register */
/*! @{ */

#define FRAMECOMPOSER_FC_CTRLQLOW_ONLOWATTENDED_MASK (0x1FU)
#define FRAMECOMPOSER_FC_CTRLQLOW_ONLOWATTENDED_SHIFT (0U)
/*! onlowattended - Configures the number of low priority packets or null packets consecutively
 *    attended before checking high priority queue status or audio samples availability.
 */
#define FRAMECOMPOSER_FC_CTRLQLOW_ONLOWATTENDED(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_CTRLQLOW_ONLOWATTENDED_SHIFT)) & FRAMECOMPOSER_FC_CTRLQLOW_ONLOWATTENDED_MASK)
/*! @} */

/*! @name FC_ACP0 - Frame Composer ACP Packet Type Configuration Register 0 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP0_ACPTYPE_MASK       (0xFFU)
#define FRAMECOMPOSER_FC_ACP0_ACPTYPE_SHIFT      (0U)
/*! acptype - Configures the ACP packet type. */
#define FRAMECOMPOSER_FC_ACP0_ACPTYPE(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP0_ACPTYPE_SHIFT)) & FRAMECOMPOSER_FC_ACP0_ACPTYPE_MASK)
/*! @} */

/*! @name FC_ACP16 - Frame Composer ACP Packet Body Configuration Register 16 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP16_FC_ACP16_MASK     (0xFFU)
#define FRAMECOMPOSER_FC_ACP16_FC_ACP16_SHIFT    (0U)
/*! fc_acp16 - Frame Composer ACP Packet Body Configuration Register 16 */
#define FRAMECOMPOSER_FC_ACP16_FC_ACP16(x)       (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP16_FC_ACP16_SHIFT)) & FRAMECOMPOSER_FC_ACP16_FC_ACP16_MASK)
/*! @} */

/*! @name FC_ACP15 - Frame Composer ACP Packet Body Configuration Register 15 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP15_FC_ACP15_MASK     (0xFFU)
#define FRAMECOMPOSER_FC_ACP15_FC_ACP15_SHIFT    (0U)
/*! fc_acp15 - Frame Composer ACP Packet Body Configuration Register 15 */
#define FRAMECOMPOSER_FC_ACP15_FC_ACP15(x)       (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP15_FC_ACP15_SHIFT)) & FRAMECOMPOSER_FC_ACP15_FC_ACP15_MASK)
/*! @} */

/*! @name FC_ACP14 - Frame Composer ACP Packet Body Configuration Register 14 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP14_FC_ACP14_MASK     (0xFFU)
#define FRAMECOMPOSER_FC_ACP14_FC_ACP14_SHIFT    (0U)
/*! fc_acp14 - Frame Composer ACP Packet Body Configuration Register 14 */
#define FRAMECOMPOSER_FC_ACP14_FC_ACP14(x)       (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP14_FC_ACP14_SHIFT)) & FRAMECOMPOSER_FC_ACP14_FC_ACP14_MASK)
/*! @} */

/*! @name FC_ACP13 - Frame Composer ACP Packet Body Configuration Register 13 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP13_FC_ACP13_MASK     (0xFFU)
#define FRAMECOMPOSER_FC_ACP13_FC_ACP13_SHIFT    (0U)
/*! fc_acp13 - Frame Composer ACP Packet Body Configuration Register 13 */
#define FRAMECOMPOSER_FC_ACP13_FC_ACP13(x)       (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP13_FC_ACP13_SHIFT)) & FRAMECOMPOSER_FC_ACP13_FC_ACP13_MASK)
/*! @} */

/*! @name FC_ACP12 - Frame Composer ACP Packet Body Configuration Register 12 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP12_FC_ACP12_MASK     (0xFFU)
#define FRAMECOMPOSER_FC_ACP12_FC_ACP12_SHIFT    (0U)
/*! fc_acp12 - Frame Composer ACP Packet Body Configuration Register 12 */
#define FRAMECOMPOSER_FC_ACP12_FC_ACP12(x)       (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP12_FC_ACP12_SHIFT)) & FRAMECOMPOSER_FC_ACP12_FC_ACP12_MASK)
/*! @} */

/*! @name FC_ACP11 - Frame Composer ACP Packet Body Configuration Register 11 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP11_FC_ACP11_MASK     (0xFFU)
#define FRAMECOMPOSER_FC_ACP11_FC_ACP11_SHIFT    (0U)
/*! fc_acp11 - Frame Composer ACP Packet Body Configuration Register 11 */
#define FRAMECOMPOSER_FC_ACP11_FC_ACP11(x)       (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP11_FC_ACP11_SHIFT)) & FRAMECOMPOSER_FC_ACP11_FC_ACP11_MASK)
/*! @} */

/*! @name FC_ACP10 - Frame Composer ACP Packet Body Configuration Register 10 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP10_FC_ACP10_MASK     (0xFFU)
#define FRAMECOMPOSER_FC_ACP10_FC_ACP10_SHIFT    (0U)
/*! fc_acp10 - Frame Composer ACP Packet Body Configuration Register 10 */
#define FRAMECOMPOSER_FC_ACP10_FC_ACP10(x)       (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP10_FC_ACP10_SHIFT)) & FRAMECOMPOSER_FC_ACP10_FC_ACP10_MASK)
/*! @} */

/*! @name FC_ACP9 - Frame Composer ACP Packet Body Configuration Register 9 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP9_FC_ACP9_MASK       (0xFFU)
#define FRAMECOMPOSER_FC_ACP9_FC_ACP9_SHIFT      (0U)
/*! fc_acp9 - Frame Composer ACP Packet Body Configuration Register 9 */
#define FRAMECOMPOSER_FC_ACP9_FC_ACP9(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP9_FC_ACP9_SHIFT)) & FRAMECOMPOSER_FC_ACP9_FC_ACP9_MASK)
/*! @} */

/*! @name FC_ACP8 - Frame Composer ACP Packet Body Configuration Register 8 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP8_FC_ACP8_MASK       (0xFFU)
#define FRAMECOMPOSER_FC_ACP8_FC_ACP8_SHIFT      (0U)
/*! fc_acp8 - Frame Composer ACP Packet Body Configuration Register 8 */
#define FRAMECOMPOSER_FC_ACP8_FC_ACP8(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP8_FC_ACP8_SHIFT)) & FRAMECOMPOSER_FC_ACP8_FC_ACP8_MASK)
/*! @} */

/*! @name FC_ACP7 - Frame Composer ACP Packet Body Configuration Register 7 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP7_FC_ACP7_MASK       (0xFFU)
#define FRAMECOMPOSER_FC_ACP7_FC_ACP7_SHIFT      (0U)
/*! fc_acp7 - Frame Composer ACP Packet Body Configuration Register 7 */
#define FRAMECOMPOSER_FC_ACP7_FC_ACP7(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP7_FC_ACP7_SHIFT)) & FRAMECOMPOSER_FC_ACP7_FC_ACP7_MASK)
/*! @} */

/*! @name FC_ACP6 - Frame Composer ACP Packet Body Configuration Register 6 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP6_FC_ACP6_MASK       (0xFFU)
#define FRAMECOMPOSER_FC_ACP6_FC_ACP6_SHIFT      (0U)
/*! fc_acp6 - Frame Composer ACP Packet Body Configuration Register 6 */
#define FRAMECOMPOSER_FC_ACP6_FC_ACP6(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP6_FC_ACP6_SHIFT)) & FRAMECOMPOSER_FC_ACP6_FC_ACP6_MASK)
/*! @} */

/*! @name FC_ACP5 - Frame Composer ACP Packet Body Configuration Register 5 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP5_FC_ACP5_MASK       (0xFFU)
#define FRAMECOMPOSER_FC_ACP5_FC_ACP5_SHIFT      (0U)
/*! fc_acp5 - Frame Composer ACP Packet Body Configuration Register 5 */
#define FRAMECOMPOSER_FC_ACP5_FC_ACP5(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP5_FC_ACP5_SHIFT)) & FRAMECOMPOSER_FC_ACP5_FC_ACP5_MASK)
/*! @} */

/*! @name FC_ACP4 - Frame Composer ACP Packet Body Configuration Register 4 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP4_FC_ACP4_MASK       (0xFFU)
#define FRAMECOMPOSER_FC_ACP4_FC_ACP4_SHIFT      (0U)
/*! fc_acp4 - Frame Composer ACP Packet Body Configuration Register 4 */
#define FRAMECOMPOSER_FC_ACP4_FC_ACP4(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP4_FC_ACP4_SHIFT)) & FRAMECOMPOSER_FC_ACP4_FC_ACP4_MASK)
/*! @} */

/*! @name FC_ACP3 - Frame Composer ACP Packet Body Configuration Register 3 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP3_FC_ACP3_MASK       (0xFFU)
#define FRAMECOMPOSER_FC_ACP3_FC_ACP3_SHIFT      (0U)
/*! fc_acp3 - Frame Composer ACP Packet Body Configuration Register 3 */
#define FRAMECOMPOSER_FC_ACP3_FC_ACP3(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP3_FC_ACP3_SHIFT)) & FRAMECOMPOSER_FC_ACP3_FC_ACP3_MASK)
/*! @} */

/*! @name FC_ACP2 - Frame Composer ACP Packet Body Configuration Register 2 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP2_FC_ACP2_MASK       (0xFFU)
#define FRAMECOMPOSER_FC_ACP2_FC_ACP2_SHIFT      (0U)
/*! fc_acp2 - Frame Composer ACP Packet Body Configuration Register 2 */
#define FRAMECOMPOSER_FC_ACP2_FC_ACP2(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP2_FC_ACP2_SHIFT)) & FRAMECOMPOSER_FC_ACP2_FC_ACP2_MASK)
/*! @} */

/*! @name FC_ACP1 - Frame Composer ACP Packet Body Configuration Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_ACP1_FC_ACP1_MASK       (0xFFU)
#define FRAMECOMPOSER_FC_ACP1_FC_ACP1_SHIFT      (0U)
/*! fc_acp1 - Frame Composer ACP Packet Body Configuration Register 1 */
#define FRAMECOMPOSER_FC_ACP1_FC_ACP1(x)         (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACP1_FC_ACP1_SHIFT)) & FRAMECOMPOSER_FC_ACP1_FC_ACP1_MASK)
/*! @} */

/*! @name FC_ISCR1_0 - Frame Composer ISRC1 Packet Status, Valid, and Continue Configuration Register */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_0_ISRC_CONT_MASK  (0x1U)
#define FRAMECOMPOSER_FC_ISCR1_0_ISRC_CONT_SHIFT (0U)
/*! isrc_cont - ISRC1 Indication of packet continuation (ISRC2 will be transmitted) */
#define FRAMECOMPOSER_FC_ISCR1_0_ISRC_CONT(x)    (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_0_ISRC_CONT_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_0_ISRC_CONT_MASK)

#define FRAMECOMPOSER_FC_ISCR1_0_ISRC_VALID_MASK (0x2U)
#define FRAMECOMPOSER_FC_ISCR1_0_ISRC_VALID_SHIFT (1U)
/*! isrc_valid - ISRC1 Valid control signal */
#define FRAMECOMPOSER_FC_ISCR1_0_ISRC_VALID(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_0_ISRC_VALID_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_0_ISRC_VALID_MASK)

#define FRAMECOMPOSER_FC_ISCR1_0_ISRC_STATUS_MASK (0x1CU)
#define FRAMECOMPOSER_FC_ISCR1_0_ISRC_STATUS_SHIFT (2U)
/*! isrc_status - ISRC1 Status signal */
#define FRAMECOMPOSER_FC_ISCR1_0_ISRC_STATUS(x)  (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_0_ISRC_STATUS_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_0_ISRC_STATUS_MASK)
/*! @} */

/*! @name FC_ISCR1_16 - Frame Composer ISRC1 Packet Body Register 16 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_16_FC_ISCR1_16_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_16_FC_ISCR1_16_SHIFT (0U)
/*! fc_iscr1_16 - Frame Composer ISRC1 Packet Body Register 16; configures ISRC1 packet body of the ISRC1 packet */
#define FRAMECOMPOSER_FC_ISCR1_16_FC_ISCR1_16(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_16_FC_ISCR1_16_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_16_FC_ISCR1_16_MASK)
/*! @} */

/*! @name FC_ISCR1_15 - Frame Composer ISRC1 Packet Body Register 15 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_15_FC_ISCR1_15_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_15_FC_ISCR1_15_SHIFT (0U)
/*! fc_iscr1_15 - Frame Composer ISRC1 Packet Body Register 15 */
#define FRAMECOMPOSER_FC_ISCR1_15_FC_ISCR1_15(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_15_FC_ISCR1_15_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_15_FC_ISCR1_15_MASK)
/*! @} */

/*! @name FC_ISCR1_14 - Frame Composer ISRC1 Packet Body Register 14 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_14_FC_ISCR1_14_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_14_FC_ISCR1_14_SHIFT (0U)
/*! fc_iscr1_14 - Frame Composer ISRC1 Packet Body Register 14 */
#define FRAMECOMPOSER_FC_ISCR1_14_FC_ISCR1_14(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_14_FC_ISCR1_14_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_14_FC_ISCR1_14_MASK)
/*! @} */

/*! @name FC_ISCR1_13 - Frame Composer ISRC1 Packet Body Register 13 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_13_FC_ISCR1_13_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_13_FC_ISCR1_13_SHIFT (0U)
/*! fc_iscr1_13 - Frame Composer ISRC1 Packet Body Register 13 */
#define FRAMECOMPOSER_FC_ISCR1_13_FC_ISCR1_13(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_13_FC_ISCR1_13_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_13_FC_ISCR1_13_MASK)
/*! @} */

/*! @name FC_ISCR1_12 - Frame Composer ISRC1 Packet Body Register 12 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_12_FC_ISCR1_12_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_12_FC_ISCR1_12_SHIFT (0U)
/*! fc_iscr1_12 - Frame Composer ISRC1 Packet Body Register 12 */
#define FRAMECOMPOSER_FC_ISCR1_12_FC_ISCR1_12(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_12_FC_ISCR1_12_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_12_FC_ISCR1_12_MASK)
/*! @} */

/*! @name FC_ISCR1_11 - Frame Composer ISRC1 Packet Body Register 11 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_11_FC_ISCR1_11_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_11_FC_ISCR1_11_SHIFT (0U)
/*! fc_iscr1_11 - Frame Composer ISRC1 Packet Body Register 11 */
#define FRAMECOMPOSER_FC_ISCR1_11_FC_ISCR1_11(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_11_FC_ISCR1_11_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_11_FC_ISCR1_11_MASK)
/*! @} */

/*! @name FC_ISCR1_10 - Frame Composer ISRC1 Packet Body Register 10 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_10_FC_ISCR1_10_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_10_FC_ISCR1_10_SHIFT (0U)
/*! fc_iscr1_10 - Frame Composer ISRC1 Packet Body Register 10 */
#define FRAMECOMPOSER_FC_ISCR1_10_FC_ISCR1_10(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_10_FC_ISCR1_10_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_10_FC_ISCR1_10_MASK)
/*! @} */

/*! @name FC_ISCR1_9 - Frame Composer ISRC1 Packet Body Register 9 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_9_FC_ISCR1_9_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_9_FC_ISCR1_9_SHIFT (0U)
/*! fc_iscr1_9 - Frame Composer ISRC1 Packet Body Register 9 */
#define FRAMECOMPOSER_FC_ISCR1_9_FC_ISCR1_9(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_9_FC_ISCR1_9_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_9_FC_ISCR1_9_MASK)
/*! @} */

/*! @name FC_ISCR1_8 - Frame Composer ISRC1 Packet Body Register 8 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_8_FC_ISCR1_8_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_8_FC_ISCR1_8_SHIFT (0U)
/*! fc_iscr1_8 - Frame Composer ISRC1 Packet Body Register 8 */
#define FRAMECOMPOSER_FC_ISCR1_8_FC_ISCR1_8(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_8_FC_ISCR1_8_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_8_FC_ISCR1_8_MASK)
/*! @} */

/*! @name FC_ISCR1_7 - Frame Composer ISRC1 Packet Body Register 7 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_7_FC_ISCR1_7_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_7_FC_ISCR1_7_SHIFT (0U)
/*! fc_iscr1_7 - Frame Composer ISRC1 Packet Body Register 7 */
#define FRAMECOMPOSER_FC_ISCR1_7_FC_ISCR1_7(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_7_FC_ISCR1_7_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_7_FC_ISCR1_7_MASK)
/*! @} */

/*! @name FC_ISCR1_6 - Frame Composer ISRC1 Packet Body Register 6 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_6_FC_ISCR1_6_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_6_FC_ISCR1_6_SHIFT (0U)
/*! fc_iscr1_6 - Frame Composer ISRC1 Packet Body Register 6 */
#define FRAMECOMPOSER_FC_ISCR1_6_FC_ISCR1_6(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_6_FC_ISCR1_6_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_6_FC_ISCR1_6_MASK)
/*! @} */

/*! @name FC_ISCR1_5 - Frame Composer ISRC1 Packet Body Register 5 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_5_FC_ISCR1_5_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_5_FC_ISCR1_5_SHIFT (0U)
/*! fc_iscr1_5 - Frame Composer ISRC1 Packet Body Register 5 */
#define FRAMECOMPOSER_FC_ISCR1_5_FC_ISCR1_5(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_5_FC_ISCR1_5_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_5_FC_ISCR1_5_MASK)
/*! @} */

/*! @name FC_ISCR1_4 - Frame Composer ISRC1 Packet Body Register 4 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_4_FC_ISCR1_4_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_4_FC_ISCR1_4_SHIFT (0U)
/*! fc_iscr1_4 - Frame Composer ISRC1 Packet Body Register 4 */
#define FRAMECOMPOSER_FC_ISCR1_4_FC_ISCR1_4(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_4_FC_ISCR1_4_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_4_FC_ISCR1_4_MASK)
/*! @} */

/*! @name FC_ISCR1_3 - Frame Composer ISRC1 Packet Body Register 3 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_3_FC_ISCR1_3_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_3_FC_ISCR1_3_SHIFT (0U)
/*! fc_iscr1_3 - Frame Composer ISRC1 Packet Body Register 3 */
#define FRAMECOMPOSER_FC_ISCR1_3_FC_ISCR1_3(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_3_FC_ISCR1_3_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_3_FC_ISCR1_3_MASK)
/*! @} */

/*! @name FC_ISCR1_2 - Frame Composer ISRC1 Packet Body Register 2 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_2_FC_ISCR1_2_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_2_FC_ISCR1_2_SHIFT (0U)
/*! fc_iscr1_2 - Frame Composer ISRC1 Packet Body Register 2 */
#define FRAMECOMPOSER_FC_ISCR1_2_FC_ISCR1_2(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_2_FC_ISCR1_2_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_2_FC_ISCR1_2_MASK)
/*! @} */

/*! @name FC_ISCR1_1 - Frame Composer ISRC1 Packet Body Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR1_1_FC_ISCR1_1_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR1_1_FC_ISCR1_1_SHIFT (0U)
/*! fc_iscr1_1 - Frame Composer ISRC1 Packet Body Register 1 */
#define FRAMECOMPOSER_FC_ISCR1_1_FC_ISCR1_1(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR1_1_FC_ISCR1_1_SHIFT)) & FRAMECOMPOSER_FC_ISCR1_1_FC_ISCR1_1_MASK)
/*! @} */

/*! @name FC_ISCR2_15 - Frame Composer ISRC2 Packet Body Register 15 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_15_FC_ISCR2_15_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_15_FC_ISCR2_15_SHIFT (0U)
/*! fc_iscr2_15 - Frame Composer ISRC2 Packet Body Register 15; configures the ISRC2 packet body of the ISRC2 packet */
#define FRAMECOMPOSER_FC_ISCR2_15_FC_ISCR2_15(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_15_FC_ISCR2_15_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_15_FC_ISCR2_15_MASK)
/*! @} */

/*! @name FC_ISCR2_14 - Frame Composer ISRC2 Packet Body Register 14 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_14_FC_ISCR2_14_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_14_FC_ISCR2_14_SHIFT (0U)
/*! fc_iscr2_14 - Frame Composer ISRC2 Packet Body Register 14 */
#define FRAMECOMPOSER_FC_ISCR2_14_FC_ISCR2_14(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_14_FC_ISCR2_14_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_14_FC_ISCR2_14_MASK)
/*! @} */

/*! @name FC_ISCR2_13 - Frame Composer ISRC2 Packet Body Register 13 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_13_FC_ISCR2_13_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_13_FC_ISCR2_13_SHIFT (0U)
/*! fc_iscr2_13 - Frame Composer ISRC2 Packet Body Register 13 */
#define FRAMECOMPOSER_FC_ISCR2_13_FC_ISCR2_13(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_13_FC_ISCR2_13_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_13_FC_ISCR2_13_MASK)
/*! @} */

/*! @name FC_ISCR2_12 - Frame Composer ISRC2 Packet Body Register 12 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_12_FC_ISCR2_12_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_12_FC_ISCR2_12_SHIFT (0U)
/*! fc_iscr2_12 - Frame Composer ISRC2 Packet Body Register 12 */
#define FRAMECOMPOSER_FC_ISCR2_12_FC_ISCR2_12(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_12_FC_ISCR2_12_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_12_FC_ISCR2_12_MASK)
/*! @} */

/*! @name FC_ISCR2_11 - Frame Composer ISRC2 Packet Body Register 11 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_11_FC_ISCR2_11_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_11_FC_ISCR2_11_SHIFT (0U)
/*! fc_iscr2_11 - Frame Composer ISRC2 Packet Body Register 11 */
#define FRAMECOMPOSER_FC_ISCR2_11_FC_ISCR2_11(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_11_FC_ISCR2_11_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_11_FC_ISCR2_11_MASK)
/*! @} */

/*! @name FC_ISCR2_10 - Frame Composer ISRC2 Packet Body Register 10 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_10_FC_ISCR2_10_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_10_FC_ISCR2_10_SHIFT (0U)
/*! fc_iscr2_10 - Frame Composer ISRC2 Packet Body Register 10 */
#define FRAMECOMPOSER_FC_ISCR2_10_FC_ISCR2_10(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_10_FC_ISCR2_10_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_10_FC_ISCR2_10_MASK)
/*! @} */

/*! @name FC_ISCR2_9 - Frame Composer ISRC2 Packet Body Register 9 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_9_FC_ISCR2_9_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_9_FC_ISCR2_9_SHIFT (0U)
/*! fc_iscr2_9 - Frame Composer ISRC2 Packet Body Register 9 */
#define FRAMECOMPOSER_FC_ISCR2_9_FC_ISCR2_9(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_9_FC_ISCR2_9_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_9_FC_ISCR2_9_MASK)
/*! @} */

/*! @name FC_ISCR2_8 - Frame Composer ISRC2 Packet Body Register 8 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_8_FC_ISCR2_8_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_8_FC_ISCR2_8_SHIFT (0U)
/*! fc_iscr2_8 - Frame Composer ISRC2 Packet Body Register 8 */
#define FRAMECOMPOSER_FC_ISCR2_8_FC_ISCR2_8(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_8_FC_ISCR2_8_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_8_FC_ISCR2_8_MASK)
/*! @} */

/*! @name FC_ISCR2_7 - Frame Composer ISRC2 Packet Body Register 7 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_7_FC_ISCR2_7_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_7_FC_ISCR2_7_SHIFT (0U)
/*! fc_iscr2_7 - Frame Composer ISRC2 Packet Body Register 7 */
#define FRAMECOMPOSER_FC_ISCR2_7_FC_ISCR2_7(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_7_FC_ISCR2_7_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_7_FC_ISCR2_7_MASK)
/*! @} */

/*! @name FC_ISCR2_6 - Frame Composer ISRC2 Packet Body Register 6 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_6_FC_ISCR2_6_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_6_FC_ISCR2_6_SHIFT (0U)
/*! fc_iscr2_6 - Frame Composer ISRC2 Packet Body Register 6 */
#define FRAMECOMPOSER_FC_ISCR2_6_FC_ISCR2_6(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_6_FC_ISCR2_6_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_6_FC_ISCR2_6_MASK)
/*! @} */

/*! @name FC_ISCR2_5 - Frame Composer ISRC2 Packet Body Register 5 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_5_FC_ISCR2_5_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_5_FC_ISCR2_5_SHIFT (0U)
/*! fc_iscr2_5 - Frame Composer ISRC2 Packet Body Register 5 */
#define FRAMECOMPOSER_FC_ISCR2_5_FC_ISCR2_5(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_5_FC_ISCR2_5_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_5_FC_ISCR2_5_MASK)
/*! @} */

/*! @name FC_ISCR2_4 - Frame Composer ISRC2 Packet Body Register 4 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_4_FC_ISCR2_4_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_4_FC_ISCR2_4_SHIFT (0U)
/*! fc_iscr2_4 - Frame Composer ISRC2 Packet Body Register 4 */
#define FRAMECOMPOSER_FC_ISCR2_4_FC_ISCR2_4(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_4_FC_ISCR2_4_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_4_FC_ISCR2_4_MASK)
/*! @} */

/*! @name FC_ISCR2_3 - Frame Composer ISRC2 Packet Body Register 3 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_3_FC_ISCR2_3_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_3_FC_ISCR2_3_SHIFT (0U)
/*! fc_iscr2_3 - Frame Composer ISRC2 Packet Body Register 3 */
#define FRAMECOMPOSER_FC_ISCR2_3_FC_ISCR2_3(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_3_FC_ISCR2_3_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_3_FC_ISCR2_3_MASK)
/*! @} */

/*! @name FC_ISCR2_2 - Frame Composer ISRC2 Packet Body Register 2 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_2_FC_ISCR2_2_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_2_FC_ISCR2_2_SHIFT (0U)
/*! fc_iscr2_2 - Frame Composer ISRC2 Packet Body Register 2 */
#define FRAMECOMPOSER_FC_ISCR2_2_FC_ISCR2_2(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_2_FC_ISCR2_2_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_2_FC_ISCR2_2_MASK)
/*! @} */

/*! @name FC_ISCR2_1 - Frame Composer ISRC2 Packet Body Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_1_FC_ISCR2_1_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_1_FC_ISCR2_1_SHIFT (0U)
/*! fc_iscr2_1 - Frame Composer ISRC2 Packet Body Register 1 */
#define FRAMECOMPOSER_FC_ISCR2_1_FC_ISCR2_1(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_1_FC_ISCR2_1_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_1_FC_ISCR2_1_MASK)
/*! @} */

/*! @name FC_ISCR2_0 - Frame Composer ISRC2 Packet Body Register 0 */
/*! @{ */

#define FRAMECOMPOSER_FC_ISCR2_0_FC_ISCR2_0_MASK (0xFFU)
#define FRAMECOMPOSER_FC_ISCR2_0_FC_ISCR2_0_SHIFT (0U)
/*! fc_iscr2_0 - Frame Composer ISRC2 Packet Body Register 0 */
#define FRAMECOMPOSER_FC_ISCR2_0_FC_ISCR2_0(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ISCR2_0_FC_ISCR2_0_SHIFT)) & FRAMECOMPOSER_FC_ISCR2_0_FC_ISCR2_0_MASK)
/*! @} */

/*! @name FC_DATAUTO0 - Frame Composer Data Island Auto Packet Scheduling Register 0 Configures the Frame Composer RDRB(1)/Manual(0) data island packet insertion for SPD, VSD, ISRC2, ISRC1 and ACP packets. */
/*! @{ */

#define FRAMECOMPOSER_FC_DATAUTO0_ACP_AUTO_MASK  (0x1U)
#define FRAMECOMPOSER_FC_DATAUTO0_ACP_AUTO_SHIFT (0U)
/*! acp_auto - Enables ACP automatic packet scheduling */
#define FRAMECOMPOSER_FC_DATAUTO0_ACP_AUTO(x)    (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO0_ACP_AUTO_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO0_ACP_AUTO_MASK)

#define FRAMECOMPOSER_FC_DATAUTO0_ISCR1_AUTO_MASK (0x2U)
#define FRAMECOMPOSER_FC_DATAUTO0_ISCR1_AUTO_SHIFT (1U)
/*! iscr1_auto - Enables ISRC1 automatic packet scheduling */
#define FRAMECOMPOSER_FC_DATAUTO0_ISCR1_AUTO(x)  (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO0_ISCR1_AUTO_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO0_ISCR1_AUTO_MASK)

#define FRAMECOMPOSER_FC_DATAUTO0_ISCR2_AUTO_MASK (0x4U)
#define FRAMECOMPOSER_FC_DATAUTO0_ISCR2_AUTO_SHIFT (2U)
/*! iscr2_auto - Enables ISRC2 automatic packet scheduling */
#define FRAMECOMPOSER_FC_DATAUTO0_ISCR2_AUTO(x)  (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO0_ISCR2_AUTO_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO0_ISCR2_AUTO_MASK)

#define FRAMECOMPOSER_FC_DATAUTO0_VSD_AUTO_MASK  (0x8U)
#define FRAMECOMPOSER_FC_DATAUTO0_VSD_AUTO_SHIFT (3U)
/*! vsd_auto - Enables VSD automatic packet scheduling */
#define FRAMECOMPOSER_FC_DATAUTO0_VSD_AUTO(x)    (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO0_VSD_AUTO_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO0_VSD_AUTO_MASK)

#define FRAMECOMPOSER_FC_DATAUTO0_SPD_AUTO_MASK  (0x10U)
#define FRAMECOMPOSER_FC_DATAUTO0_SPD_AUTO_SHIFT (4U)
/*! spd_auto - Enables SPD automatic packet scheduling */
#define FRAMECOMPOSER_FC_DATAUTO0_SPD_AUTO(x)    (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO0_SPD_AUTO_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO0_SPD_AUTO_MASK)
/*! @} */

/*! @name FC_DATAUTO1 - Frame Composer Data Island Auto Packet Scheduling Register 1 Configures the Frame Composer (FC) RDRB frame interpolation for SPD, VSD, ISRC2, ISRC1 and ACP packet insertion on data island when FC is on RDRB mode for the listed packets. */
/*! @{ */

#define FRAMECOMPOSER_FC_DATAUTO1_AUTO_FRAME_INTERPOLATION_MASK (0xFU)
#define FRAMECOMPOSER_FC_DATAUTO1_AUTO_FRAME_INTERPOLATION_SHIFT (0U)
/*! auto_frame_interpolation - Packet frame interpolation for automatic packet scheduling */
#define FRAMECOMPOSER_FC_DATAUTO1_AUTO_FRAME_INTERPOLATION(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO1_AUTO_FRAME_INTERPOLATION_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO1_AUTO_FRAME_INTERPOLATION_MASK)
/*! @} */

/*! @name FC_DATAUTO2 - Frame Composer Data Island Auto packet scheduling Register 2 Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for SPD, VSD, ISRC2, ISRC1 and ACP packet insertion on data island when FC is on RDRB mode for the listed packets. */
/*! @{ */

#define FRAMECOMPOSER_FC_DATAUTO2_AUTO_LINE_SPACING_MASK (0xFU)
#define FRAMECOMPOSER_FC_DATAUTO2_AUTO_LINE_SPACING_SHIFT (0U)
/*! auto_line_spacing - Packets line spacing, for automatic packet scheduling */
#define FRAMECOMPOSER_FC_DATAUTO2_AUTO_LINE_SPACING(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO2_AUTO_LINE_SPACING_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO2_AUTO_LINE_SPACING_MASK)

#define FRAMECOMPOSER_FC_DATAUTO2_AUTO_FRAME_PACKETS_MASK (0xF0U)
#define FRAMECOMPOSER_FC_DATAUTO2_AUTO_FRAME_PACKETS_SHIFT (4U)
/*! auto_frame_packets - Packets per frame, for automatic packet scheduling */
#define FRAMECOMPOSER_FC_DATAUTO2_AUTO_FRAME_PACKETS(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO2_AUTO_FRAME_PACKETS_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO2_AUTO_FRAME_PACKETS_MASK)
/*! @} */

/*! @name FC_DATMAN - Frame Composer Data Island Manual Packet Request Register Requests to the Frame Composer the data island packet insertion for NULL, SPD, VSD, ISRC2, ISRC1 and ACP packets when FC_DATAUTO0 bit is in manual mode for the packet requested. */
/*! @{ */

#define FRAMECOMPOSER_FC_DATMAN_ACP_TX_MASK      (0x1U)
#define FRAMECOMPOSER_FC_DATMAN_ACP_TX_SHIFT     (0U)
/*! acp_tx - ACP packet */
#define FRAMECOMPOSER_FC_DATMAN_ACP_TX(x)        (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATMAN_ACP_TX_SHIFT)) & FRAMECOMPOSER_FC_DATMAN_ACP_TX_MASK)

#define FRAMECOMPOSER_FC_DATMAN_ISCR1_TX_MASK    (0x2U)
#define FRAMECOMPOSER_FC_DATMAN_ISCR1_TX_SHIFT   (1U)
/*! iscr1_tx - ISRC1 packet */
#define FRAMECOMPOSER_FC_DATMAN_ISCR1_TX(x)      (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATMAN_ISCR1_TX_SHIFT)) & FRAMECOMPOSER_FC_DATMAN_ISCR1_TX_MASK)

#define FRAMECOMPOSER_FC_DATMAN_ISCR2_TX_MASK    (0x4U)
#define FRAMECOMPOSER_FC_DATMAN_ISCR2_TX_SHIFT   (2U)
/*! iscr2_tx - ISRC2 packet */
#define FRAMECOMPOSER_FC_DATMAN_ISCR2_TX(x)      (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATMAN_ISCR2_TX_SHIFT)) & FRAMECOMPOSER_FC_DATMAN_ISCR2_TX_MASK)

#define FRAMECOMPOSER_FC_DATMAN_VSD_TX_MASK      (0x8U)
#define FRAMECOMPOSER_FC_DATMAN_VSD_TX_SHIFT     (3U)
/*! vsd_tx - VSD packet */
#define FRAMECOMPOSER_FC_DATMAN_VSD_TX(x)        (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATMAN_VSD_TX_SHIFT)) & FRAMECOMPOSER_FC_DATMAN_VSD_TX_MASK)

#define FRAMECOMPOSER_FC_DATMAN_SPD_TX_MASK      (0x10U)
#define FRAMECOMPOSER_FC_DATMAN_SPD_TX_SHIFT     (4U)
/*! spd_tx - SPD packet */
#define FRAMECOMPOSER_FC_DATMAN_SPD_TX(x)        (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATMAN_SPD_TX_SHIFT)) & FRAMECOMPOSER_FC_DATMAN_SPD_TX_MASK)

#define FRAMECOMPOSER_FC_DATMAN_NULL_TX_MASK     (0x20U)
#define FRAMECOMPOSER_FC_DATMAN_NULL_TX_SHIFT    (5U)
/*! null_tx - Null packet */
#define FRAMECOMPOSER_FC_DATMAN_NULL_TX(x)       (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATMAN_NULL_TX_SHIFT)) & FRAMECOMPOSER_FC_DATMAN_NULL_TX_MASK)
/*! @} */

/*! @name FC_DATAUTO3 - Frame Composer Data Island Auto Packet Scheduling Register 3 Configures the Frame Composer Automatic(1)/RDRB(0) data island packet insertion for AVI, GCP, AUDI and ACR packets. */
/*! @{ */

#define FRAMECOMPOSER_FC_DATAUTO3_ACR_AUTO_MASK  (0x1U)
#define FRAMECOMPOSER_FC_DATAUTO3_ACR_AUTO_SHIFT (0U)
/*! acr_auto - Enables ACR packet insertion */
#define FRAMECOMPOSER_FC_DATAUTO3_ACR_AUTO(x)    (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO3_ACR_AUTO_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO3_ACR_AUTO_MASK)

#define FRAMECOMPOSER_FC_DATAUTO3_AUDI_AUTO_MASK (0x2U)
#define FRAMECOMPOSER_FC_DATAUTO3_AUDI_AUTO_SHIFT (1U)
/*! audi_auto - Enables AUDI packet insertion */
#define FRAMECOMPOSER_FC_DATAUTO3_AUDI_AUTO(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO3_AUDI_AUTO_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO3_AUDI_AUTO_MASK)

#define FRAMECOMPOSER_FC_DATAUTO3_GCP_AUTO_MASK  (0x4U)
#define FRAMECOMPOSER_FC_DATAUTO3_GCP_AUTO_SHIFT (2U)
/*! gcp_auto - Enables GCP packet insertion */
#define FRAMECOMPOSER_FC_DATAUTO3_GCP_AUTO(x)    (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO3_GCP_AUTO_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO3_GCP_AUTO_MASK)

#define FRAMECOMPOSER_FC_DATAUTO3_AVI_AUTO_MASK  (0x8U)
#define FRAMECOMPOSER_FC_DATAUTO3_AVI_AUTO_SHIFT (3U)
/*! avi_auto - Enables AVI packet insertion */
#define FRAMECOMPOSER_FC_DATAUTO3_AVI_AUTO(x)    (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO3_AVI_AUTO_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO3_AVI_AUTO_MASK)

#define FRAMECOMPOSER_FC_DATAUTO3_AMP_AUTO_MASK  (0x10U)
#define FRAMECOMPOSER_FC_DATAUTO3_AMP_AUTO_SHIFT (4U)
/*! amp_auto - Enables AMP packet insertion */
#define FRAMECOMPOSER_FC_DATAUTO3_AMP_AUTO(x)    (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO3_AMP_AUTO_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO3_AMP_AUTO_MASK)

#define FRAMECOMPOSER_FC_DATAUTO3_NVBI_AUTO_MASK (0x20U)
#define FRAMECOMPOSER_FC_DATAUTO3_NVBI_AUTO_SHIFT (5U)
/*! nvbi_auto - Enables NTSC VBI packet insertion */
#define FRAMECOMPOSER_FC_DATAUTO3_NVBI_AUTO(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO3_NVBI_AUTO_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO3_NVBI_AUTO_MASK)

#define FRAMECOMPOSER_FC_DATAUTO3_DRM_AUTO_MASK  (0x40U)
#define FRAMECOMPOSER_FC_DATAUTO3_DRM_AUTO_SHIFT (6U)
/*! drm_auto - Enables DRM packet insertion */
#define FRAMECOMPOSER_FC_DATAUTO3_DRM_AUTO(x)    (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DATAUTO3_DRM_AUTO_SHIFT)) & FRAMECOMPOSER_FC_DATAUTO3_DRM_AUTO_MASK)
/*! @} */

/*! @name FC_RDRB0 - Frame Composer Round Robin ACR Packet Insertion Register 0 Configures the Frame Composer (FC) RDRB frame interpolation for ACR packet insertion on data island when FC is on RDRB mode for this packet. */
/*! @{ */

#define FRAMECOMPOSER_FC_RDRB0_ACRFRAMEINTERPOLATION_MASK (0xFU)
#define FRAMECOMPOSER_FC_RDRB0_ACRFRAMEINTERPOLATION_SHIFT (0U)
/*! ACRframeinterpolation - ACR Frame interpolation */
#define FRAMECOMPOSER_FC_RDRB0_ACRFRAMEINTERPOLATION(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB0_ACRFRAMEINTERPOLATION_SHIFT)) & FRAMECOMPOSER_FC_RDRB0_ACRFRAMEINTERPOLATION_MASK)
/*! @} */

/*! @name FC_RDRB1 - Frame Composer Round Robin ACR Packet Insertion Register 1 Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for the ACR packet insertion on data island when FC is on RDRB mode this packet. */
/*! @{ */

#define FRAMECOMPOSER_FC_RDRB1_ACRPACKETLINESPACING_MASK (0xFU)
#define FRAMECOMPOSER_FC_RDRB1_ACRPACKETLINESPACING_SHIFT (0U)
/*! ACRpacketlinespacing - ACR packet line spacing */
#define FRAMECOMPOSER_FC_RDRB1_ACRPACKETLINESPACING(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB1_ACRPACKETLINESPACING_SHIFT)) & FRAMECOMPOSER_FC_RDRB1_ACRPACKETLINESPACING_MASK)

#define FRAMECOMPOSER_FC_RDRB1_ACRPACKETSINFRAME_MASK (0xF0U)
#define FRAMECOMPOSER_FC_RDRB1_ACRPACKETSINFRAME_SHIFT (4U)
/*! ACRpacketsinframe - ACR packets in frame */
#define FRAMECOMPOSER_FC_RDRB1_ACRPACKETSINFRAME(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB1_ACRPACKETSINFRAME_SHIFT)) & FRAMECOMPOSER_FC_RDRB1_ACRPACKETSINFRAME_MASK)
/*! @} */

/*! @name FC_RDRB2 - Frame Composer Round Robin AUDI Packet Insertion Register 2 Configures the Frame Composer (FC) RDRB frame interpolation for AUDI packet insertion on data island when FC is on RDRB mode for this packet. */
/*! @{ */

#define FRAMECOMPOSER_FC_RDRB2_AUDIFRAMEINTERPOLATION_MASK (0xFU)
#define FRAMECOMPOSER_FC_RDRB2_AUDIFRAMEINTERPOLATION_SHIFT (0U)
/*! AUDIframeinterpolation - Audio frame interpolation */
#define FRAMECOMPOSER_FC_RDRB2_AUDIFRAMEINTERPOLATION(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB2_AUDIFRAMEINTERPOLATION_SHIFT)) & FRAMECOMPOSER_FC_RDRB2_AUDIFRAMEINTERPOLATION_MASK)
/*! @} */

/*! @name FC_RDRB3 - Frame Composer Round Robin AUDI Packet Insertion Register 3 Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for the AUDI packet insertion on data island when FC is on RDRB mode this packet. */
/*! @{ */

#define FRAMECOMPOSER_FC_RDRB3_AUDIPACKETLINESPACING_MASK (0xFU)
#define FRAMECOMPOSER_FC_RDRB3_AUDIPACKETLINESPACING_SHIFT (0U)
/*! AUDIpacketlinespacing - Audio packets line spacing */
#define FRAMECOMPOSER_FC_RDRB3_AUDIPACKETLINESPACING(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB3_AUDIPACKETLINESPACING_SHIFT)) & FRAMECOMPOSER_FC_RDRB3_AUDIPACKETLINESPACING_MASK)

#define FRAMECOMPOSER_FC_RDRB3_AUDIPACKETSINFRAME_MASK (0xF0U)
#define FRAMECOMPOSER_FC_RDRB3_AUDIPACKETSINFRAME_SHIFT (4U)
/*! AUDIpacketsinframe - Audio packets per frame */
#define FRAMECOMPOSER_FC_RDRB3_AUDIPACKETSINFRAME(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB3_AUDIPACKETSINFRAME_SHIFT)) & FRAMECOMPOSER_FC_RDRB3_AUDIPACKETSINFRAME_MASK)
/*! @} */

/*! @name FC_RDRB4 - Frame Composer Round Robin GCP Packet Insertion Register 4 Configures the Frame Composer (FC) RDRB frame interpolation for GCP packet insertion on data island when FC is on RDRB mode for this packet. */
/*! @{ */

#define FRAMECOMPOSER_FC_RDRB4_GCPFRAMEINTERPOLATION_MASK (0xFU)
#define FRAMECOMPOSER_FC_RDRB4_GCPFRAMEINTERPOLATION_SHIFT (0U)
/*! GCPframeinterpolation - Frames interpolated between GCP packets */
#define FRAMECOMPOSER_FC_RDRB4_GCPFRAMEINTERPOLATION(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB4_GCPFRAMEINTERPOLATION_SHIFT)) & FRAMECOMPOSER_FC_RDRB4_GCPFRAMEINTERPOLATION_MASK)
/*! @} */

/*! @name FC_RDRB5 - Frame Composer Round Robin GCP Packet Insertion Register 5 Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for the GCP packet insertion on data island when FC is on RDRB mode this packet. */
/*! @{ */

#define FRAMECOMPOSER_FC_RDRB5_GCPPACKETLINESPACING_MASK (0xFU)
#define FRAMECOMPOSER_FC_RDRB5_GCPPACKETLINESPACING_SHIFT (0U)
/*! GCPpacketlinespacing - GCP packets line spacing */
#define FRAMECOMPOSER_FC_RDRB5_GCPPACKETLINESPACING(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB5_GCPPACKETLINESPACING_SHIFT)) & FRAMECOMPOSER_FC_RDRB5_GCPPACKETLINESPACING_MASK)

#define FRAMECOMPOSER_FC_RDRB5_GCPPACKETSINFRAME_MASK (0xF0U)
#define FRAMECOMPOSER_FC_RDRB5_GCPPACKETSINFRAME_SHIFT (4U)
/*! GCPpacketsinframe - GCP packets per frame */
#define FRAMECOMPOSER_FC_RDRB5_GCPPACKETSINFRAME(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB5_GCPPACKETSINFRAME_SHIFT)) & FRAMECOMPOSER_FC_RDRB5_GCPPACKETSINFRAME_MASK)
/*! @} */

/*! @name FC_RDRB6 - Frame Composer Round Robin AVI Packet Insertion Register 6 Configures the Frame Composer (FC) RDRB frame interpolation for AVI packet insertion on data island when FC is on RDRB mode for this packet. */
/*! @{ */

#define FRAMECOMPOSER_FC_RDRB6_AVIFRAMEINTERPOLATION_MASK (0xFU)
#define FRAMECOMPOSER_FC_RDRB6_AVIFRAMEINTERPOLATION_SHIFT (0U)
/*! AVIframeinterpolation - Frames interpolated between AVI packets */
#define FRAMECOMPOSER_FC_RDRB6_AVIFRAMEINTERPOLATION(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB6_AVIFRAMEINTERPOLATION_SHIFT)) & FRAMECOMPOSER_FC_RDRB6_AVIFRAMEINTERPOLATION_MASK)
/*! @} */

/*! @name FC_RDRB7 - Frame Composer Round Robin AVI Packet Insertion Register 7 Configures the Frame Composer (FC) RDRB line interpolation and number of packets in frame for the AVI packet insertion on data island when FC is on RDRB mode this packet. */
/*! @{ */

#define FRAMECOMPOSER_FC_RDRB7_AVIPACKETLINESPACING_MASK (0xFU)
#define FRAMECOMPOSER_FC_RDRB7_AVIPACKETLINESPACING_SHIFT (0U)
/*! AVIpacketlinespacing - AVI packets line spacing */
#define FRAMECOMPOSER_FC_RDRB7_AVIPACKETLINESPACING(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB7_AVIPACKETLINESPACING_SHIFT)) & FRAMECOMPOSER_FC_RDRB7_AVIPACKETLINESPACING_MASK)

#define FRAMECOMPOSER_FC_RDRB7_AVIPACKETSINFRAME_MASK (0xF0U)
#define FRAMECOMPOSER_FC_RDRB7_AVIPACKETSINFRAME_SHIFT (4U)
/*! AVIpacketsinframe - AVI packets per frame */
#define FRAMECOMPOSER_FC_RDRB7_AVIPACKETSINFRAME(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB7_AVIPACKETSINFRAME_SHIFT)) & FRAMECOMPOSER_FC_RDRB7_AVIPACKETSINFRAME_MASK)
/*! @} */

/*! @name FC_RDRB8 - Frame Composer Round Robin AMP Packet Insertion Register 8 */
/*! @{ */

#define FRAMECOMPOSER_FC_RDRB8_AMPFRAMEINTERPOLATION_MASK (0xFU)
#define FRAMECOMPOSER_FC_RDRB8_AMPFRAMEINTERPOLATION_SHIFT (0U)
/*! AMPframeinterpolation - AMP frame interpolation */
#define FRAMECOMPOSER_FC_RDRB8_AMPFRAMEINTERPOLATION(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB8_AMPFRAMEINTERPOLATION_SHIFT)) & FRAMECOMPOSER_FC_RDRB8_AMPFRAMEINTERPOLATION_MASK)
/*! @} */

/*! @name FC_RDRB9 - Frame Composer Round Robin AMP Packet Insertion Register 9 */
/*! @{ */

#define FRAMECOMPOSER_FC_RDRB9_AMPPACKETLINESPACING_MASK (0xFU)
#define FRAMECOMPOSER_FC_RDRB9_AMPPACKETLINESPACING_SHIFT (0U)
/*! AMPpacketlinespacing - AMP packets line spacing */
#define FRAMECOMPOSER_FC_RDRB9_AMPPACKETLINESPACING(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB9_AMPPACKETLINESPACING_SHIFT)) & FRAMECOMPOSER_FC_RDRB9_AMPPACKETLINESPACING_MASK)

#define FRAMECOMPOSER_FC_RDRB9_AMPPACKETSINFRAME_MASK (0xF0U)
#define FRAMECOMPOSER_FC_RDRB9_AMPPACKETSINFRAME_SHIFT (4U)
/*! AMPpacketsinframe - AMP packets per frame */
#define FRAMECOMPOSER_FC_RDRB9_AMPPACKETSINFRAME(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB9_AMPPACKETSINFRAME_SHIFT)) & FRAMECOMPOSER_FC_RDRB9_AMPPACKETSINFRAME_MASK)
/*! @} */

/*! @name FC_RDRB10 - Frame Composer Round Robin NTSC VBI Packet Insertion Register 10 */
/*! @{ */

#define FRAMECOMPOSER_FC_RDRB10_NVBIFRAMEINTERPOLATION_MASK (0xFU)
#define FRAMECOMPOSER_FC_RDRB10_NVBIFRAMEINTERPOLATION_SHIFT (0U)
/*! NVBIframeinterpolation - NTSC VBI frame interpolation */
#define FRAMECOMPOSER_FC_RDRB10_NVBIFRAMEINTERPOLATION(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB10_NVBIFRAMEINTERPOLATION_SHIFT)) & FRAMECOMPOSER_FC_RDRB10_NVBIFRAMEINTERPOLATION_MASK)
/*! @} */

/*! @name FC_RDRB11 - Frame Composer Round Robin NTSC VBI Packet Insertion Register 11 */
/*! @{ */

#define FRAMECOMPOSER_FC_RDRB11_NVBIPACKETLINESPACING_MASK (0xFU)
#define FRAMECOMPOSER_FC_RDRB11_NVBIPACKETLINESPACING_SHIFT (0U)
/*! NVBIpacketlinespacing - NTSC VBI packets line spacing */
#define FRAMECOMPOSER_FC_RDRB11_NVBIPACKETLINESPACING(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB11_NVBIPACKETLINESPACING_SHIFT)) & FRAMECOMPOSER_FC_RDRB11_NVBIPACKETLINESPACING_MASK)

#define FRAMECOMPOSER_FC_RDRB11_NVBIPACKETSINFRAME_MASK (0xF0U)
#define FRAMECOMPOSER_FC_RDRB11_NVBIPACKETSINFRAME_SHIFT (4U)
/*! NVBIpacketsinframe - NTSC VBI packets per frame */
#define FRAMECOMPOSER_FC_RDRB11_NVBIPACKETSINFRAME(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB11_NVBIPACKETSINFRAME_SHIFT)) & FRAMECOMPOSER_FC_RDRB11_NVBIPACKETSINFRAME_MASK)
/*! @} */

/*! @name FC_RDRB12 - Frame Composer Round Robin DRM Packet Insertion Register 12 */
/*! @{ */

#define FRAMECOMPOSER_FC_RDRB12_DRMFRAMEINTERPOLATION_MASK (0xFU)
#define FRAMECOMPOSER_FC_RDRB12_DRMFRAMEINTERPOLATION_SHIFT (0U)
/*! DRMframeinterpolation - DRM frame interpolation */
#define FRAMECOMPOSER_FC_RDRB12_DRMFRAMEINTERPOLATION(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB12_DRMFRAMEINTERPOLATION_SHIFT)) & FRAMECOMPOSER_FC_RDRB12_DRMFRAMEINTERPOLATION_MASK)
/*! @} */

/*! @name FC_RDRB13 - Frame Composer Round Robin DRM Packet Insertion Register 13 */
/*! @{ */

#define FRAMECOMPOSER_FC_RDRB13_DRMPACKETLINESPACING_MASK (0xFU)
#define FRAMECOMPOSER_FC_RDRB13_DRMPACKETLINESPACING_SHIFT (0U)
/*! DRMpacketlinespacing - DRM packets line spacing */
#define FRAMECOMPOSER_FC_RDRB13_DRMPACKETLINESPACING(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB13_DRMPACKETLINESPACING_SHIFT)) & FRAMECOMPOSER_FC_RDRB13_DRMPACKETLINESPACING_MASK)

#define FRAMECOMPOSER_FC_RDRB13_DRMPACKETSINFRAME_MASK (0xF0U)
#define FRAMECOMPOSER_FC_RDRB13_DRMPACKETSINFRAME_SHIFT (4U)
/*! DRMpacketsinframe - DRM packets per frame */
#define FRAMECOMPOSER_FC_RDRB13_DRMPACKETSINFRAME(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_RDRB13_DRMPACKETSINFRAME_SHIFT)) & FRAMECOMPOSER_FC_RDRB13_DRMPACKETSINFRAME_MASK)
/*! @} */

/*! @name FC_MASK0 - Frame Composer Packet Interrupt Mask Register 0 */
/*! @{ */

#define FRAMECOMPOSER_FC_MASK0_NULL_MASK         (0x1U)
#define FRAMECOMPOSER_FC_MASK0_NULL_SHIFT        (0U)
/*! NULL - Mask bit for FC_INT0. */
#define FRAMECOMPOSER_FC_MASK0_NULL(x)           (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK0_NULL_SHIFT)) & FRAMECOMPOSER_FC_MASK0_NULL_MASK)

#define FRAMECOMPOSER_FC_MASK0_ACR_MASK          (0x2U)
#define FRAMECOMPOSER_FC_MASK0_ACR_SHIFT         (1U)
/*! ACR - Mask bit for FC_INT0. */
#define FRAMECOMPOSER_FC_MASK0_ACR(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK0_ACR_SHIFT)) & FRAMECOMPOSER_FC_MASK0_ACR_MASK)

#define FRAMECOMPOSER_FC_MASK0_AUDS_MASK         (0x4U)
#define FRAMECOMPOSER_FC_MASK0_AUDS_SHIFT        (2U)
/*! AUDS - Mask bit for FC_INT0. */
#define FRAMECOMPOSER_FC_MASK0_AUDS(x)           (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK0_AUDS_SHIFT)) & FRAMECOMPOSER_FC_MASK0_AUDS_MASK)

#define FRAMECOMPOSER_FC_MASK0_NVBI_MASK         (0x8U)
#define FRAMECOMPOSER_FC_MASK0_NVBI_SHIFT        (3U)
/*! NVBI - Mask bit for FC_INT0. */
#define FRAMECOMPOSER_FC_MASK0_NVBI(x)           (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK0_NVBI_SHIFT)) & FRAMECOMPOSER_FC_MASK0_NVBI_MASK)

#define FRAMECOMPOSER_FC_MASK0_MAS_MASK          (0x10U)
#define FRAMECOMPOSER_FC_MASK0_MAS_SHIFT         (4U)
/*! MAS - Mask bit for FC_INT0. */
#define FRAMECOMPOSER_FC_MASK0_MAS(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK0_MAS_SHIFT)) & FRAMECOMPOSER_FC_MASK0_MAS_MASK)

#define FRAMECOMPOSER_FC_MASK0_HBR_MASK          (0x20U)
#define FRAMECOMPOSER_FC_MASK0_HBR_SHIFT         (5U)
/*! HBR - Mask bit for FC_INT0. */
#define FRAMECOMPOSER_FC_MASK0_HBR(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK0_HBR_SHIFT)) & FRAMECOMPOSER_FC_MASK0_HBR_MASK)

#define FRAMECOMPOSER_FC_MASK0_ACP_MASK          (0x40U)
#define FRAMECOMPOSER_FC_MASK0_ACP_SHIFT         (6U)
/*! ACP - Mask bit for FC_INT0. */
#define FRAMECOMPOSER_FC_MASK0_ACP(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK0_ACP_SHIFT)) & FRAMECOMPOSER_FC_MASK0_ACP_MASK)

#define FRAMECOMPOSER_FC_MASK0_AUDI_MASK         (0x80U)
#define FRAMECOMPOSER_FC_MASK0_AUDI_SHIFT        (7U)
/*! AUDI - Mask bit for FC_INT0. */
#define FRAMECOMPOSER_FC_MASK0_AUDI(x)           (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK0_AUDI_SHIFT)) & FRAMECOMPOSER_FC_MASK0_AUDI_MASK)
/*! @} */

/*! @name FC_MASK1 - Frame Composer Packet Interrupt Mask Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_MASK1_GCP_MASK          (0x1U)
#define FRAMECOMPOSER_FC_MASK1_GCP_SHIFT         (0U)
/*! GCP - Mask bit for FC_INT1. */
#define FRAMECOMPOSER_FC_MASK1_GCP(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK1_GCP_SHIFT)) & FRAMECOMPOSER_FC_MASK1_GCP_MASK)

#define FRAMECOMPOSER_FC_MASK1_AVI_MASK          (0x2U)
#define FRAMECOMPOSER_FC_MASK1_AVI_SHIFT         (1U)
/*! AVI - Mask bit for FC_INT1. */
#define FRAMECOMPOSER_FC_MASK1_AVI(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK1_AVI_SHIFT)) & FRAMECOMPOSER_FC_MASK1_AVI_MASK)

#define FRAMECOMPOSER_FC_MASK1_AMP_MASK          (0x4U)
#define FRAMECOMPOSER_FC_MASK1_AMP_SHIFT         (2U)
/*! AMP - Mask bit for FC_INT1. */
#define FRAMECOMPOSER_FC_MASK1_AMP(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK1_AMP_SHIFT)) & FRAMECOMPOSER_FC_MASK1_AMP_MASK)

#define FRAMECOMPOSER_FC_MASK1_SPD_MASK          (0x8U)
#define FRAMECOMPOSER_FC_MASK1_SPD_SHIFT         (3U)
/*! SPD - Mask bit for FC_INT1. */
#define FRAMECOMPOSER_FC_MASK1_SPD(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK1_SPD_SHIFT)) & FRAMECOMPOSER_FC_MASK1_SPD_MASK)

#define FRAMECOMPOSER_FC_MASK1_VSD_MASK          (0x10U)
#define FRAMECOMPOSER_FC_MASK1_VSD_SHIFT         (4U)
/*! VSD - Mask bit for FC_INT1. */
#define FRAMECOMPOSER_FC_MASK1_VSD(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK1_VSD_SHIFT)) & FRAMECOMPOSER_FC_MASK1_VSD_MASK)

#define FRAMECOMPOSER_FC_MASK1_ISCR2_MASK        (0x20U)
#define FRAMECOMPOSER_FC_MASK1_ISCR2_SHIFT       (5U)
/*! ISCR2 - Mask bit for FC_INT1. */
#define FRAMECOMPOSER_FC_MASK1_ISCR2(x)          (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK1_ISCR2_SHIFT)) & FRAMECOMPOSER_FC_MASK1_ISCR2_MASK)

#define FRAMECOMPOSER_FC_MASK1_ISCR1_MASK        (0x40U)
#define FRAMECOMPOSER_FC_MASK1_ISCR1_SHIFT       (6U)
/*! ISCR1 - Mask bit for FC_INT1. */
#define FRAMECOMPOSER_FC_MASK1_ISCR1(x)          (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK1_ISCR1_SHIFT)) & FRAMECOMPOSER_FC_MASK1_ISCR1_MASK)

#define FRAMECOMPOSER_FC_MASK1_GMD_MASK          (0x80U)
#define FRAMECOMPOSER_FC_MASK1_GMD_SHIFT         (7U)
/*! GMD - Mask bit for FC_INT1. */
#define FRAMECOMPOSER_FC_MASK1_GMD(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK1_GMD_SHIFT)) & FRAMECOMPOSER_FC_MASK1_GMD_MASK)
/*! @} */

/*! @name FC_MASK2 - Frame Composer High/Low Priority Overflow and DRM Interrupt Mask Register 2 */
/*! @{ */

#define FRAMECOMPOSER_FC_MASK2_HIGHPRIORITY_OVERFLOW_MASK (0x1U)
#define FRAMECOMPOSER_FC_MASK2_HIGHPRIORITY_OVERFLOW_SHIFT (0U)
/*! HighPriority_overflow - Mask bit for FC_INT2. */
#define FRAMECOMPOSER_FC_MASK2_HIGHPRIORITY_OVERFLOW(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK2_HIGHPRIORITY_OVERFLOW_SHIFT)) & FRAMECOMPOSER_FC_MASK2_HIGHPRIORITY_OVERFLOW_MASK)

#define FRAMECOMPOSER_FC_MASK2_LOWPRIORITY_OVERFLOW_MASK (0x2U)
#define FRAMECOMPOSER_FC_MASK2_LOWPRIORITY_OVERFLOW_SHIFT (1U)
/*! LowPriority_overflow - Mask bit for FC_INT2. */
#define FRAMECOMPOSER_FC_MASK2_LOWPRIORITY_OVERFLOW(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK2_LOWPRIORITY_OVERFLOW_SHIFT)) & FRAMECOMPOSER_FC_MASK2_LOWPRIORITY_OVERFLOW_MASK)

#define FRAMECOMPOSER_FC_MASK2_DRM_MASK          (0x10U)
#define FRAMECOMPOSER_FC_MASK2_DRM_SHIFT         (4U)
/*! DRM - Mask bit for FC_INT2. */
#define FRAMECOMPOSER_FC_MASK2_DRM(x)            (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MASK2_DRM_SHIFT)) & FRAMECOMPOSER_FC_MASK2_DRM_MASK)
/*! @} */

/*! @name FC_PRCONF - Frame Composer Pixel Repetition Configuration Register */
/*! @{ */

#define FRAMECOMPOSER_FC_PRCONF_OUTPUT_PR_FACTOR_MASK (0xFU)
#define FRAMECOMPOSER_FC_PRCONF_OUTPUT_PR_FACTOR_SHIFT (0U)
/*! output_pr_factor - Configures the video pixel repetition ratio to be sent on the AVI InfoFrame. */
#define FRAMECOMPOSER_FC_PRCONF_OUTPUT_PR_FACTOR(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_PRCONF_OUTPUT_PR_FACTOR_SHIFT)) & FRAMECOMPOSER_FC_PRCONF_OUTPUT_PR_FACTOR_MASK)

#define FRAMECOMPOSER_FC_PRCONF_INCOMING_PR_FACTOR_MASK (0xF0U)
#define FRAMECOMPOSER_FC_PRCONF_INCOMING_PR_FACTOR_SHIFT (4U)
/*! incoming_pr_factor - Configures the input video pixel repetition. */
#define FRAMECOMPOSER_FC_PRCONF_INCOMING_PR_FACTOR(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_PRCONF_INCOMING_PR_FACTOR_SHIFT)) & FRAMECOMPOSER_FC_PRCONF_INCOMING_PR_FACTOR_MASK)
/*! @} */

/*! @name FC_SCRAMBLER_CTRL - Frame Composer Scrambler Control */
/*! @{ */

#define FRAMECOMPOSER_FC_SCRAMBLER_CTRL_SCRAMBLER_ON_MASK (0x1U)
#define FRAMECOMPOSER_FC_SCRAMBLER_CTRL_SCRAMBLER_ON_SHIFT (0U)
/*! scrambler_on - When set (1'b1), this field activates the HDMI 2. */
#define FRAMECOMPOSER_FC_SCRAMBLER_CTRL_SCRAMBLER_ON(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_SCRAMBLER_CTRL_SCRAMBLER_ON_SHIFT)) & FRAMECOMPOSER_FC_SCRAMBLER_CTRL_SCRAMBLER_ON_MASK)

#define FRAMECOMPOSER_FC_SCRAMBLER_CTRL_SCRAMBLER_UCP_LINE_MASK (0x10U)
#define FRAMECOMPOSER_FC_SCRAMBLER_CTRL_SCRAMBLER_UCP_LINE_SHIFT (4U)
/*! scrambler_ucp_line - Debug register. */
#define FRAMECOMPOSER_FC_SCRAMBLER_CTRL_SCRAMBLER_UCP_LINE(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_SCRAMBLER_CTRL_SCRAMBLER_UCP_LINE_SHIFT)) & FRAMECOMPOSER_FC_SCRAMBLER_CTRL_SCRAMBLER_UCP_LINE_MASK)
/*! @} */

/*! @name FC_MULTISTREAM_CTRL - Frame Composer Multi-Stream Audio Control */
/*! @{ */

#define FRAMECOMPOSER_FC_MULTISTREAM_CTRL_FC_MAS_PACKET_EN_MASK (0x1U)
#define FRAMECOMPOSER_FC_MULTISTREAM_CTRL_FC_MAS_PACKET_EN_SHIFT (0U)
/*! fc_mas_packet_en - This field, when set (1'b1), activates the HDMI 2. */
#define FRAMECOMPOSER_FC_MULTISTREAM_CTRL_FC_MAS_PACKET_EN(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_MULTISTREAM_CTRL_FC_MAS_PACKET_EN_SHIFT)) & FRAMECOMPOSER_FC_MULTISTREAM_CTRL_FC_MAS_PACKET_EN_MASK)
/*! @} */

/*! @name FC_PACKET_TX_EN - Frame Composer Packet Transmission Control */
/*! @{ */

#define FRAMECOMPOSER_FC_PACKET_TX_EN_ACR_TX_EN_MASK (0x1U)
#define FRAMECOMPOSER_FC_PACKET_TX_EN_ACR_TX_EN_SHIFT (0U)
/*! acr_tx_en - ACR packet transmission control 1b: Transmission enabled 0b: Transmission disabled */
#define FRAMECOMPOSER_FC_PACKET_TX_EN_ACR_TX_EN(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_PACKET_TX_EN_ACR_TX_EN_SHIFT)) & FRAMECOMPOSER_FC_PACKET_TX_EN_ACR_TX_EN_MASK)

#define FRAMECOMPOSER_FC_PACKET_TX_EN_GCP_TX_EN_MASK (0x2U)
#define FRAMECOMPOSER_FC_PACKET_TX_EN_GCP_TX_EN_SHIFT (1U)
/*! gcp_tx_en - GCP transmission control 1b: Transmission enabled 0b: Transmission disabled */
#define FRAMECOMPOSER_FC_PACKET_TX_EN_GCP_TX_EN(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_PACKET_TX_EN_GCP_TX_EN_SHIFT)) & FRAMECOMPOSER_FC_PACKET_TX_EN_GCP_TX_EN_MASK)

#define FRAMECOMPOSER_FC_PACKET_TX_EN_AVI_TX_EN_MASK (0x4U)
#define FRAMECOMPOSER_FC_PACKET_TX_EN_AVI_TX_EN_SHIFT (2U)
/*! avi_tx_en - AVI packet transmission control 1b: Transmission enabled 0b: Transmission disabled */
#define FRAMECOMPOSER_FC_PACKET_TX_EN_AVI_TX_EN(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_PACKET_TX_EN_AVI_TX_EN_SHIFT)) & FRAMECOMPOSER_FC_PACKET_TX_EN_AVI_TX_EN_MASK)

#define FRAMECOMPOSER_FC_PACKET_TX_EN_AUDI_TX_EN_MASK (0x8U)
#define FRAMECOMPOSER_FC_PACKET_TX_EN_AUDI_TX_EN_SHIFT (3U)
/*! audi_tx_en - AUDI packet transmission control 1b: Transmission enabled 0b: Transmission disabled */
#define FRAMECOMPOSER_FC_PACKET_TX_EN_AUDI_TX_EN(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_PACKET_TX_EN_AUDI_TX_EN_SHIFT)) & FRAMECOMPOSER_FC_PACKET_TX_EN_AUDI_TX_EN_MASK)

#define FRAMECOMPOSER_FC_PACKET_TX_EN_AUT_TX_EN_MASK (0x10U)
#define FRAMECOMPOSER_FC_PACKET_TX_EN_AUT_TX_EN_SHIFT (4U)
/*! aut_tx_en - ACP, SPD, VSIF, ISRC1, and SRC2 packet transmission control 1b: Transmission enabled 0b: Transmission disabled */
#define FRAMECOMPOSER_FC_PACKET_TX_EN_AUT_TX_EN(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_PACKET_TX_EN_AUT_TX_EN_SHIFT)) & FRAMECOMPOSER_FC_PACKET_TX_EN_AUT_TX_EN_MASK)

#define FRAMECOMPOSER_FC_PACKET_TX_EN_AMP_TX_EN_MASK (0x20U)
#define FRAMECOMPOSER_FC_PACKET_TX_EN_AMP_TX_EN_SHIFT (5U)
/*! amp_tx_en - AMP transmission control 1b: Transmission enabled 0b: Transmission disabled */
#define FRAMECOMPOSER_FC_PACKET_TX_EN_AMP_TX_EN(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_PACKET_TX_EN_AMP_TX_EN_SHIFT)) & FRAMECOMPOSER_FC_PACKET_TX_EN_AMP_TX_EN_MASK)

#define FRAMECOMPOSER_FC_PACKET_TX_EN_NVBI_TX_EN_MASK (0x40U)
#define FRAMECOMPOSER_FC_PACKET_TX_EN_NVBI_TX_EN_SHIFT (6U)
/*! nvbi_tx_en - NTSC VBI transmission control 1b: Transmission enabled 0b: Transmission disabled */
#define FRAMECOMPOSER_FC_PACKET_TX_EN_NVBI_TX_EN(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_PACKET_TX_EN_NVBI_TX_EN_SHIFT)) & FRAMECOMPOSER_FC_PACKET_TX_EN_NVBI_TX_EN_MASK)

#define FRAMECOMPOSER_FC_PACKET_TX_EN_DRM_TX_EN_MASK (0x80U)
#define FRAMECOMPOSER_FC_PACKET_TX_EN_DRM_TX_EN_SHIFT (7U)
/*! drm_tx_en - DRM transmission control 1b: Transmission enabled 0b: Transmission disabled */
#define FRAMECOMPOSER_FC_PACKET_TX_EN_DRM_TX_EN(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_PACKET_TX_EN_DRM_TX_EN_SHIFT)) & FRAMECOMPOSER_FC_PACKET_TX_EN_DRM_TX_EN_MASK)
/*! @} */

/*! @name FC_ACTSPC_HDLR_CFG - Frame Composer Active Space Control */
/*! @{ */

#define FRAMECOMPOSER_FC_ACTSPC_HDLR_CFG_ACTSPC_HDLR_EN_MASK (0x1U)
#define FRAMECOMPOSER_FC_ACTSPC_HDLR_CFG_ACTSPC_HDLR_EN_SHIFT (0U)
/*! actspc_hdlr_en - Active Space Handler Control 1b: Fixed active space value mode enabled. */
#define FRAMECOMPOSER_FC_ACTSPC_HDLR_CFG_ACTSPC_HDLR_EN(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACTSPC_HDLR_CFG_ACTSPC_HDLR_EN_SHIFT)) & FRAMECOMPOSER_FC_ACTSPC_HDLR_CFG_ACTSPC_HDLR_EN_MASK)

#define FRAMECOMPOSER_FC_ACTSPC_HDLR_CFG_ACTSPC_HDLR_TGL_MASK (0x2U)
#define FRAMECOMPOSER_FC_ACTSPC_HDLR_CFG_ACTSPC_HDLR_TGL_SHIFT (1U)
/*! actspc_hdlr_tgl - Active Space handler control 1b: Active space 1 value is different from Active Space 2 value. */
#define FRAMECOMPOSER_FC_ACTSPC_HDLR_CFG_ACTSPC_HDLR_TGL(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_ACTSPC_HDLR_CFG_ACTSPC_HDLR_TGL_SHIFT)) & FRAMECOMPOSER_FC_ACTSPC_HDLR_CFG_ACTSPC_HDLR_TGL_MASK)
/*! @} */

/*! @name FC_INVACT_2D_0 - Frame Composer Input Video 2D VActive Pixels Register 0 */
/*! @{ */

#define FRAMECOMPOSER_FC_INVACT_2D_0_FC_INVACT_2D_0_MASK (0xFFU)
#define FRAMECOMPOSER_FC_INVACT_2D_0_FC_INVACT_2D_0_SHIFT (0U)
/*! fc_invact_2d_0 - 2D Input video vertical active pixel region width. */
#define FRAMECOMPOSER_FC_INVACT_2D_0_FC_INVACT_2D_0(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INVACT_2D_0_FC_INVACT_2D_0_SHIFT)) & FRAMECOMPOSER_FC_INVACT_2D_0_FC_INVACT_2D_0_MASK)
/*! @} */

/*! @name FC_INVACT_2D_1 - Frame Composer Input Video VActive pixels Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_INVACT_2D_1_FC_INVACT_2D_1_MASK (0xFU)
#define FRAMECOMPOSER_FC_INVACT_2D_1_FC_INVACT_2D_1_SHIFT (0U)
/*! fc_invact_2d_1 - 2D Input video vertical active pixel region width. */
#define FRAMECOMPOSER_FC_INVACT_2D_1_FC_INVACT_2D_1(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_INVACT_2D_1_FC_INVACT_2D_1_SHIFT)) & FRAMECOMPOSER_FC_INVACT_2D_1_FC_INVACT_2D_1_MASK)
/*! @} */

/*! @name FC_GMD_STAT - Frame Composer GMD Packet Status Register Gamut metadata packet status bit information for no_current_gmd, next_gmd_field, gmd_packet_sequence and current_gamut_seq_num. */
/*! @{ */

#define FRAMECOMPOSER_FC_GMD_STAT_IGMDCURRENT_GAMUT_SEQ_NUM_MASK (0xFU)
#define FRAMECOMPOSER_FC_GMD_STAT_IGMDCURRENT_GAMUT_SEQ_NUM_SHIFT (0U)
/*! igmdcurrent_gamut_seq_num - Gamut scheduling: Current Gamut packet sequence number */
#define FRAMECOMPOSER_FC_GMD_STAT_IGMDCURRENT_GAMUT_SEQ_NUM(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_GMD_STAT_IGMDCURRENT_GAMUT_SEQ_NUM_SHIFT)) & FRAMECOMPOSER_FC_GMD_STAT_IGMDCURRENT_GAMUT_SEQ_NUM_MASK)

#define FRAMECOMPOSER_FC_GMD_STAT_IGMDPACKET_SEQ_MASK (0x30U)
#define FRAMECOMPOSER_FC_GMD_STAT_IGMDPACKET_SEQ_SHIFT (4U)
/*! igmdpacket_seq - Gamut scheduling: Gamut packet sequence */
#define FRAMECOMPOSER_FC_GMD_STAT_IGMDPACKET_SEQ(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_GMD_STAT_IGMDPACKET_SEQ_SHIFT)) & FRAMECOMPOSER_FC_GMD_STAT_IGMDPACKET_SEQ_MASK)

#define FRAMECOMPOSER_FC_GMD_STAT_IGMDDNEXT_FIELD_MASK (0x40U)
#define FRAMECOMPOSER_FC_GMD_STAT_IGMDDNEXT_FIELD_SHIFT (6U)
/*! igmddnext_field - Gamut scheduling: Gamut Next field */
#define FRAMECOMPOSER_FC_GMD_STAT_IGMDDNEXT_FIELD(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_GMD_STAT_IGMDDNEXT_FIELD_SHIFT)) & FRAMECOMPOSER_FC_GMD_STAT_IGMDDNEXT_FIELD_MASK)

#define FRAMECOMPOSER_FC_GMD_STAT_IGMDNO_CRNT_GBD_MASK (0x80U)
#define FRAMECOMPOSER_FC_GMD_STAT_IGMDNO_CRNT_GBD_SHIFT (7U)
/*! igmdno_crnt_gbd - Gamut scheduling: No current gamut data */
#define FRAMECOMPOSER_FC_GMD_STAT_IGMDNO_CRNT_GBD(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_GMD_STAT_IGMDNO_CRNT_GBD_SHIFT)) & FRAMECOMPOSER_FC_GMD_STAT_IGMDNO_CRNT_GBD_MASK)
/*! @} */

/*! @name FC_GMD_EN - Frame Composer GMD Packet Enable Register This register enables Gamut metadata (GMD) packet transmission. */
/*! @{ */

#define FRAMECOMPOSER_FC_GMD_EN_GMDENABLETX_MASK (0x1U)
#define FRAMECOMPOSER_FC_GMD_EN_GMDENABLETX_SHIFT (0U)
/*! gmdenabletx - Gamut Metadata packet transmission enable (1b) */
#define FRAMECOMPOSER_FC_GMD_EN_GMDENABLETX(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_GMD_EN_GMDENABLETX_SHIFT)) & FRAMECOMPOSER_FC_GMD_EN_GMDENABLETX_MASK)
/*! @} */

/*! @name FC_GMD_UP - Frame Composer GMD Packet Update Register This register performs an GMD packet content update according to the configured packet body (FC_GMD_PB0 to FC_GMD_PB27) and packet header (FC_GMD_HB). */
/*! @{ */

#define FRAMECOMPOSER_FC_GMD_UP_GMDUPDATEPACKET_MASK (0x1U)
#define FRAMECOMPOSER_FC_GMD_UP_GMDUPDATEPACKET_SHIFT (0U)
/*! gmdupdatepacket - Gamut Metadata packet update */
#define FRAMECOMPOSER_FC_GMD_UP_GMDUPDATEPACKET(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_GMD_UP_GMDUPDATEPACKET_SHIFT)) & FRAMECOMPOSER_FC_GMD_UP_GMDUPDATEPACKET_MASK)
/*! @} */

/*! @name FC_GMD_CONF - Frame Composer GMD Packet Schedule Configuration Register This register configures the number of GMD packets to be inserted per frame (starting always in the line where the active Vsync appears) and the line spacing between the transmitted GMD packets. */
/*! @{ */

#define FRAMECOMPOSER_FC_GMD_CONF_GMDPACKETLINESPACING_MASK (0xFU)
#define FRAMECOMPOSER_FC_GMD_CONF_GMDPACKETLINESPACING_SHIFT (0U)
/*! gmdpacketlinespacing - Number of line spacing between the transmitted GMD packets */
#define FRAMECOMPOSER_FC_GMD_CONF_GMDPACKETLINESPACING(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_GMD_CONF_GMDPACKETLINESPACING_SHIFT)) & FRAMECOMPOSER_FC_GMD_CONF_GMDPACKETLINESPACING_MASK)

#define FRAMECOMPOSER_FC_GMD_CONF_GMDPACKETSINFRAME_MASK (0xF0U)
#define FRAMECOMPOSER_FC_GMD_CONF_GMDPACKETSINFRAME_SHIFT (4U)
/*! gmdpacketsinframe - Number of GMD packets per frame or video field (profile P0) */
#define FRAMECOMPOSER_FC_GMD_CONF_GMDPACKETSINFRAME(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_GMD_CONF_GMDPACKETSINFRAME_SHIFT)) & FRAMECOMPOSER_FC_GMD_CONF_GMDPACKETSINFRAME_MASK)
/*! @} */

/*! @name FC_GMD_HB - Frame Composer GMD Packet Profile and Gamut Sequence Configuration Register This register configures the GMD packet header affected_gamut_seq_num and gmd_profile bits. */
/*! @{ */

#define FRAMECOMPOSER_FC_GMD_HB_GMDAFFECTED_GAMUT_SEQ_NUM_MASK (0xFU)
#define FRAMECOMPOSER_FC_GMD_HB_GMDAFFECTED_GAMUT_SEQ_NUM_SHIFT (0U)
/*! gmdaffected_gamut_seq_num - Affected gamut sequence number */
#define FRAMECOMPOSER_FC_GMD_HB_GMDAFFECTED_GAMUT_SEQ_NUM(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_GMD_HB_GMDAFFECTED_GAMUT_SEQ_NUM_SHIFT)) & FRAMECOMPOSER_FC_GMD_HB_GMDAFFECTED_GAMUT_SEQ_NUM_MASK)

#define FRAMECOMPOSER_FC_GMD_HB_GMDGBD_PROFILE_MASK (0x70U)
#define FRAMECOMPOSER_FC_GMD_HB_GMDGBD_PROFILE_SHIFT (4U)
/*! gmdgbd_profile - GMD profile bits. */
#define FRAMECOMPOSER_FC_GMD_HB_GMDGBD_PROFILE(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_GMD_HB_GMDGBD_PROFILE_SHIFT)) & FRAMECOMPOSER_FC_GMD_HB_GMDGBD_PROFILE_MASK)
/*! @} */

/*! @name FC_AMP_HB1 - Frame Composer AMP Packet Header Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_AMP_HB1_FC_AMP_HB0_MASK (0xFFU)
#define FRAMECOMPOSER_FC_AMP_HB1_FC_AMP_HB0_SHIFT (0U)
/*! fc_amp_hb0 - Frame Composer AMP Packet Header Register 1 */
#define FRAMECOMPOSER_FC_AMP_HB1_FC_AMP_HB0(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AMP_HB1_FC_AMP_HB0_SHIFT)) & FRAMECOMPOSER_FC_AMP_HB1_FC_AMP_HB0_MASK)
/*! @} */

/*! @name FC_AMP_HB2 - Frame Composer AMP Packet Header Register 2 */
/*! @{ */

#define FRAMECOMPOSER_FC_AMP_HB2_FC_AMP_HB1_MASK (0xFFU)
#define FRAMECOMPOSER_FC_AMP_HB2_FC_AMP_HB1_SHIFT (0U)
/*! fc_amp_hb1 - Frame Composer AMP Packet Header Register 2 */
#define FRAMECOMPOSER_FC_AMP_HB2_FC_AMP_HB1(x)   (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_AMP_HB2_FC_AMP_HB1_SHIFT)) & FRAMECOMPOSER_FC_AMP_HB2_FC_AMP_HB1_MASK)
/*! @} */

/*! @name FC_NVBI_HB1 - Frame Composer NTSC VBI Packet Header Register 1 */
/*! @{ */

#define FRAMECOMPOSER_FC_NVBI_HB1_FC_NVBI_HB0_MASK (0xFFU)
#define FRAMECOMPOSER_FC_NVBI_HB1_FC_NVBI_HB0_SHIFT (0U)
/*! fc_nvbi_hb0 - Frame Composer NTSC VBI Packet Header Register 1 */
#define FRAMECOMPOSER_FC_NVBI_HB1_FC_NVBI_HB0(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_NVBI_HB1_FC_NVBI_HB0_SHIFT)) & FRAMECOMPOSER_FC_NVBI_HB1_FC_NVBI_HB0_MASK)
/*! @} */

/*! @name FC_NVBI_HB2 - Frame Composer NTSC VBI Packet Header Register 2 */
/*! @{ */

#define FRAMECOMPOSER_FC_NVBI_HB2_FC_NVBI_HB1_MASK (0xFFU)
#define FRAMECOMPOSER_FC_NVBI_HB2_FC_NVBI_HB1_SHIFT (0U)
/*! fc_nvbi_hb1 - Frame Composer NTSC VBI Packet Header Register 2 */
#define FRAMECOMPOSER_FC_NVBI_HB2_FC_NVBI_HB1(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_NVBI_HB2_FC_NVBI_HB1_SHIFT)) & FRAMECOMPOSER_FC_NVBI_HB2_FC_NVBI_HB1_MASK)
/*! @} */

/*! @name FC_DRM_UP - Frame Composer DRM Packet Update Register This register performs an DRM packet content update according to the configured packet body (FC_DRM_PB0 to FC_DRM_PB27) and packet header (FC_DRM_HB). */
/*! @{ */

#define FRAMECOMPOSER_FC_DRM_UP_DRMPACKETUPDATE_MASK (0x1U)
#define FRAMECOMPOSER_FC_DRM_UP_DRMPACKETUPDATE_SHIFT (0U)
/*! drmpacketupdate - DRM packet update */
#define FRAMECOMPOSER_FC_DRM_UP_DRMPACKETUPDATE(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DRM_UP_DRMPACKETUPDATE_SHIFT)) & FRAMECOMPOSER_FC_DRM_UP_DRMPACKETUPDATE_MASK)
/*! @} */

/*! @name FC_DBGFORCE - Frame Composer video/audio Force Enable Register This register allows to force the controller to output audio and video data the values configured in the FC_DBGAUD and FC_DBGTMDS registers. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGFORCE_FORCEVIDEO_MASK (0x1U)
#define FRAMECOMPOSER_FC_DBGFORCE_FORCEVIDEO_SHIFT (0U)
/*! forcevideo - Force fixed video output with FC_DBGTMDSx register contents. */
#define FRAMECOMPOSER_FC_DBGFORCE_FORCEVIDEO(x)  (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGFORCE_FORCEVIDEO_SHIFT)) & FRAMECOMPOSER_FC_DBGFORCE_FORCEVIDEO_MASK)

#define FRAMECOMPOSER_FC_DBGFORCE_FORCEAUDIO_MASK (0x10U)
#define FRAMECOMPOSER_FC_DBGFORCE_FORCEAUDIO_SHIFT (4U)
/*! forceaudio - Force fixed audio output with FC_DBGAUDxCHx register contents. */
#define FRAMECOMPOSER_FC_DBGFORCE_FORCEAUDIO(x)  (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGFORCE_FORCEAUDIO_SHIFT)) & FRAMECOMPOSER_FC_DBGFORCE_FORCEAUDIO_MASK)
/*! @} */

/*! @name FC_DBGAUD0CH0 - Frame Composer Audio Data Channel 0 Register 0 Configures the audio fixed data to be used in channel 0 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD0CH0_FC_DBGAUD0CH0_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD0CH0_FC_DBGAUD0CH0_SHIFT (0U)
/*! fc_dbgaud0ch0 - Frame Composer Audio Data Channel 0 Register 0 */
#define FRAMECOMPOSER_FC_DBGAUD0CH0_FC_DBGAUD0CH0(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD0CH0_FC_DBGAUD0CH0_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD0CH0_FC_DBGAUD0CH0_MASK)
/*! @} */

/*! @name FC_DBGAUD1CH0 - Frame Composer Audio Data Channel 0 Register 1 Configures the audio fixed data to be used in channel 0 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD1CH0_FC_DBGAUD1CH0_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD1CH0_FC_DBGAUD1CH0_SHIFT (0U)
/*! fc_dbgaud1ch0 - Frame Composer Audio Data Channel 0 Register 1 */
#define FRAMECOMPOSER_FC_DBGAUD1CH0_FC_DBGAUD1CH0(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD1CH0_FC_DBGAUD1CH0_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD1CH0_FC_DBGAUD1CH0_MASK)
/*! @} */

/*! @name FC_DBGAUD2CH0 - Frame Composer Audio Data Channel 0 Register 2 Configures the audio fixed data to be used in channel 0 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD2CH0_FC_DBGAUD2CH0_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD2CH0_FC_DBGAUD2CH0_SHIFT (0U)
/*! fc_dbgaud2ch0 - Frame Composer Audio Data Channel 0 Register 2 */
#define FRAMECOMPOSER_FC_DBGAUD2CH0_FC_DBGAUD2CH0(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD2CH0_FC_DBGAUD2CH0_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD2CH0_FC_DBGAUD2CH0_MASK)
/*! @} */

/*! @name FC_DBGAUD0CH1 - Frame Composer Audio Data Channel 1 Register 0 Configures the audio fixed data to be used in channel 1 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD0CH1_FC_DBGAUD0CH1_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD0CH1_FC_DBGAUD0CH1_SHIFT (0U)
/*! fc_dbgaud0ch1 - Frame Composer Audio Data Channel 1 Register 0 */
#define FRAMECOMPOSER_FC_DBGAUD0CH1_FC_DBGAUD0CH1(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD0CH1_FC_DBGAUD0CH1_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD0CH1_FC_DBGAUD0CH1_MASK)
/*! @} */

/*! @name FC_DBGAUD1CH1 - Frame Composer Audio Data Channel 1 Register 1 Configures the audio fixed data to be used in channel 1 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD1CH1_FC_DBGAUD1CH1_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD1CH1_FC_DBGAUD1CH1_SHIFT (0U)
/*! fc_dbgaud1ch1 - Frame Composer Audio Data Channel 1 Register 1 */
#define FRAMECOMPOSER_FC_DBGAUD1CH1_FC_DBGAUD1CH1(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD1CH1_FC_DBGAUD1CH1_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD1CH1_FC_DBGAUD1CH1_MASK)
/*! @} */

/*! @name FC_DBGAUD2CH1 - Frame Composer Audio Data Channel 1 Register 2 Configures the audio fixed data to be used in channel 1 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD2CH1_FC_DBGAUD2CH1_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD2CH1_FC_DBGAUD2CH1_SHIFT (0U)
/*! fc_dbgaud2ch1 - Frame Composer Audio Data Channel 1 Register 2 */
#define FRAMECOMPOSER_FC_DBGAUD2CH1_FC_DBGAUD2CH1(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD2CH1_FC_DBGAUD2CH1_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD2CH1_FC_DBGAUD2CH1_MASK)
/*! @} */

/*! @name FC_DBGAUD0CH2 - Frame Composer Audio Data Channel 2 Register 0 Configures the audio fixed data to be used in channel 2 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD0CH2_FC_DBGAUD0CH2_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD0CH2_FC_DBGAUD0CH2_SHIFT (0U)
/*! fc_dbgaud0ch2 - Frame Composer Audio Data Channel 2 Register 0 */
#define FRAMECOMPOSER_FC_DBGAUD0CH2_FC_DBGAUD0CH2(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD0CH2_FC_DBGAUD0CH2_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD0CH2_FC_DBGAUD0CH2_MASK)
/*! @} */

/*! @name FC_DBGAUD1CH2 - Frame Composer Audio Data Channel 2 Register 1 Configures the audio fixed data to be used in channel 2 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD1CH2_FC_DBGAUD1CH2_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD1CH2_FC_DBGAUD1CH2_SHIFT (0U)
/*! fc_dbgaud1ch2 - Frame Composer Audio Data Channel 2 Register 1 */
#define FRAMECOMPOSER_FC_DBGAUD1CH2_FC_DBGAUD1CH2(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD1CH2_FC_DBGAUD1CH2_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD1CH2_FC_DBGAUD1CH2_MASK)
/*! @} */

/*! @name FC_DBGAUD2CH2 - Frame Composer Audio Data Channel 2 Register 2 Configures the audio fixed data to be used in channel 2 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD2CH2_FC_DBGAUD2CH2_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD2CH2_FC_DBGAUD2CH2_SHIFT (0U)
/*! fc_dbgaud2ch2 - Frame Composer Audio Data Channel 2 Register 2 */
#define FRAMECOMPOSER_FC_DBGAUD2CH2_FC_DBGAUD2CH2(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD2CH2_FC_DBGAUD2CH2_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD2CH2_FC_DBGAUD2CH2_MASK)
/*! @} */

/*! @name FC_DBGAUD0CH3 - Frame Composer Audio Data Channel 3 Register 0 Configures the audio fixed data to be used in channel 3 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD0CH3_FC_DBGAUD0CH3_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD0CH3_FC_DBGAUD0CH3_SHIFT (0U)
/*! fc_dbgaud0ch3 - Frame Composer Audio Data Channel 3 Register 0 */
#define FRAMECOMPOSER_FC_DBGAUD0CH3_FC_DBGAUD0CH3(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD0CH3_FC_DBGAUD0CH3_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD0CH3_FC_DBGAUD0CH3_MASK)
/*! @} */

/*! @name FC_DBGAUD1CH3 - Frame Composer Audio Data Channel 3 Register 1 Configures the audio fixed data to be used in channel 3 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD1CH3_FC_DBGAUD1CH3_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD1CH3_FC_DBGAUD1CH3_SHIFT (0U)
/*! fc_dbgaud1ch3 - Frame Composer Audio Data Channel 3 Register 1 */
#define FRAMECOMPOSER_FC_DBGAUD1CH3_FC_DBGAUD1CH3(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD1CH3_FC_DBGAUD1CH3_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD1CH3_FC_DBGAUD1CH3_MASK)
/*! @} */

/*! @name FC_DBGAUD2CH3 - Frame Composer Audio Data Channel 3 Register 2 Configures the audio fixed data to be used in channel 3 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD2CH3_FC_DBGAUD2CH3_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD2CH3_FC_DBGAUD2CH3_SHIFT (0U)
/*! fc_dbgaud2ch3 - Frame Composer Audio Data Channel 3 Register 2 */
#define FRAMECOMPOSER_FC_DBGAUD2CH3_FC_DBGAUD2CH3(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD2CH3_FC_DBGAUD2CH3_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD2CH3_FC_DBGAUD2CH3_MASK)
/*! @} */

/*! @name FC_DBGAUD0CH4 - Frame Composer Audio Data Channel 4 Register 0 Configures the audio fixed data to be used in channel 4 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD0CH4_FC_DBGAUD0CH4_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD0CH4_FC_DBGAUD0CH4_SHIFT (0U)
/*! fc_dbgaud0ch4 - Frame Composer Audio Data Channel 4 Register 0 */
#define FRAMECOMPOSER_FC_DBGAUD0CH4_FC_DBGAUD0CH4(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD0CH4_FC_DBGAUD0CH4_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD0CH4_FC_DBGAUD0CH4_MASK)
/*! @} */

/*! @name FC_DBGAUD1CH4 - Frame Composer Audio Data Channel 4 Register 1 Configures the audio fixed data to be used in channel 4 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD1CH4_FC_DBGAUD1CH4_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD1CH4_FC_DBGAUD1CH4_SHIFT (0U)
/*! fc_dbgaud1ch4 - Frame Composer Audio Data Channel 4 Register 1 */
#define FRAMECOMPOSER_FC_DBGAUD1CH4_FC_DBGAUD1CH4(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD1CH4_FC_DBGAUD1CH4_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD1CH4_FC_DBGAUD1CH4_MASK)
/*! @} */

/*! @name FC_DBGAUD2CH4 - Frame Composer Audio Data Channel 4 Register 2 Configures the audio fixed data to be used in channel 4 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD2CH4_FC_DBGAUD2CH4_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD2CH4_FC_DBGAUD2CH4_SHIFT (0U)
/*! fc_dbgaud2ch4 - Frame Composer Audio Data Channel 4 Register 2 */
#define FRAMECOMPOSER_FC_DBGAUD2CH4_FC_DBGAUD2CH4(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD2CH4_FC_DBGAUD2CH4_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD2CH4_FC_DBGAUD2CH4_MASK)
/*! @} */

/*! @name FC_DBGAUD0CH5 - Frame Composer Audio Data Channel 5 Register 0 Configures the audio fixed data to be used in channel 5 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD0CH5_FC_DBGAUD0CH5_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD0CH5_FC_DBGAUD0CH5_SHIFT (0U)
/*! fc_dbgaud0ch5 - Frame Composer Audio Data Channel 5 Register 0 */
#define FRAMECOMPOSER_FC_DBGAUD0CH5_FC_DBGAUD0CH5(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD0CH5_FC_DBGAUD0CH5_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD0CH5_FC_DBGAUD0CH5_MASK)
/*! @} */

/*! @name FC_DBGAUD1CH5 - Frame Composer Audio Data Channel 5 Register 1 Configures the audio fixed data to be used in channel 5 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD1CH5_FC_DBGAUD1CH5_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD1CH5_FC_DBGAUD1CH5_SHIFT (0U)
/*! fc_dbgaud1ch5 - Frame Composer Audio Data Channel 5 Register 1 */
#define FRAMECOMPOSER_FC_DBGAUD1CH5_FC_DBGAUD1CH5(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD1CH5_FC_DBGAUD1CH5_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD1CH5_FC_DBGAUD1CH5_MASK)
/*! @} */

/*! @name FC_DBGAUD2CH5 - Frame Composer Audio Data Channel 5 Register 2 Configures the audio fixed data to be used in channel 5 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD2CH5_FC_DBGAUD2CH5_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD2CH5_FC_DBGAUD2CH5_SHIFT (0U)
/*! fc_dbgaud2ch5 - Frame Composer Audio Data Channel 5 Register 2 */
#define FRAMECOMPOSER_FC_DBGAUD2CH5_FC_DBGAUD2CH5(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD2CH5_FC_DBGAUD2CH5_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD2CH5_FC_DBGAUD2CH5_MASK)
/*! @} */

/*! @name FC_DBGAUD0CH6 - Frame Composer Audio Data Channel 6 Register 0 Configures the audio fixed data to be used in channel 6 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD0CH6_FC_DBGAUD0CH6_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD0CH6_FC_DBGAUD0CH6_SHIFT (0U)
/*! fc_dbgaud0ch6 - Frame Composer Audio Data Channel 6 Register 0 */
#define FRAMECOMPOSER_FC_DBGAUD0CH6_FC_DBGAUD0CH6(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD0CH6_FC_DBGAUD0CH6_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD0CH6_FC_DBGAUD0CH6_MASK)
/*! @} */

/*! @name FC_DBGAUD1CH6 - Frame Composer Audio Data Channel 6 Register 1 Configures the audio fixed data to be used in channel 6 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD1CH6_FC_DBGAUD1CH6_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD1CH6_FC_DBGAUD1CH6_SHIFT (0U)
/*! fc_dbgaud1ch6 - Frame Composer Audio Data Channel 6 Register 1 */
#define FRAMECOMPOSER_FC_DBGAUD1CH6_FC_DBGAUD1CH6(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD1CH6_FC_DBGAUD1CH6_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD1CH6_FC_DBGAUD1CH6_MASK)
/*! @} */

/*! @name FC_DBGAUD2CH6 - Frame Composer Audio Data Channel 6 Register 2 Configures the audio fixed data to be used in channel 6 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD2CH6_FC_DBGAUD2CH6_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD2CH6_FC_DBGAUD2CH6_SHIFT (0U)
/*! fc_dbgaud2ch6 - Frame Composer Audio Data Channel 6 Register 2 */
#define FRAMECOMPOSER_FC_DBGAUD2CH6_FC_DBGAUD2CH6(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD2CH6_FC_DBGAUD2CH6_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD2CH6_FC_DBGAUD2CH6_MASK)
/*! @} */

/*! @name FC_DBGAUD0CH7 - Frame Composer Audio Data Channel 7 Register 0 Configures the audio fixed data to be used in channel 7 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD0CH7_FC_DBGAUD0CH7_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD0CH7_FC_DBGAUD0CH7_SHIFT (0U)
/*! fc_dbgaud0ch7 - Frame Composer Audio Data Channel 7 Register 0 */
#define FRAMECOMPOSER_FC_DBGAUD0CH7_FC_DBGAUD0CH7(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD0CH7_FC_DBGAUD0CH7_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD0CH7_FC_DBGAUD0CH7_MASK)
/*! @} */

/*! @name FC_DBGAUD1CH7 - Frame Composer Audio Data Channel 7 Register 1 Configures the audio fixed data to be used in channel 7 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD1CH7_FC_DBGAUD1CH7_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD1CH7_FC_DBGAUD1CH7_SHIFT (0U)
/*! fc_dbgaud1ch7 - Frame Composer Audio Data Channel 7 Register 1 */
#define FRAMECOMPOSER_FC_DBGAUD1CH7_FC_DBGAUD1CH7(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD1CH7_FC_DBGAUD1CH7_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD1CH7_FC_DBGAUD1CH7_MASK)
/*! @} */

/*! @name FC_DBGAUD2CH7 - Frame Composer Audio Data Channel 7 Register 2 Configures the audio fixed data to be used in channel 7 when in fixed audio selection. */
/*! @{ */

#define FRAMECOMPOSER_FC_DBGAUD2CH7_FC_DBGAUD2CH7_MASK (0xFFU)
#define FRAMECOMPOSER_FC_DBGAUD2CH7_FC_DBGAUD2CH7_SHIFT (0U)
/*! fc_dbgaud2ch7 - Frame Composer Audio Data Channel 7 Register 2 */
#define FRAMECOMPOSER_FC_DBGAUD2CH7_FC_DBGAUD2CH7(x) (((uint8_t)(((uint8_t)(x)) << FRAMECOMPOSER_FC_DBGAUD2CH7_FC_DBGAUD2CH7_SHIFT)) & FRAMECOMPOSER_FC_DBGAUD2CH7_FC_DBGAUD2CH7_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FRAMECOMPOSER_Register_Masks */


/*!
 * @}
 */ /* end of group FRAMECOMPOSER_Peripheral_Access_Layer */


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


#endif  /* PERI_FRAMECOMPOSER_H_ */

