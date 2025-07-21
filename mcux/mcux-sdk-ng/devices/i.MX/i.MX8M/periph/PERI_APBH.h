/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for APBH
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_APBH.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for APBH
 *
 * CMSIS Peripheral Access Layer for APBH
 */

#if !defined(PERI_APBH_H_)
#define PERI_APBH_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- APBH Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup APBH_Peripheral_Access_Layer APBH Peripheral Access Layer
 * @{
 */

/** APBH - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL0;                             /**< AHB to APBH Bridge Control and Status Register 0, offset: 0x0 */
  __IO uint32_t CTRL0_SET;                         /**< AHB to APBH Bridge Control and Status Register 0, offset: 0x4 */
  __IO uint32_t CTRL0_CLR;                         /**< AHB to APBH Bridge Control and Status Register 0, offset: 0x8 */
  __IO uint32_t CTRL0_TOG;                         /**< AHB to APBH Bridge Control and Status Register 0, offset: 0xC */
  __IO uint32_t CTRL1;                             /**< AHB to APBH Bridge Control and Status Register 1, offset: 0x10 */
  __IO uint32_t CTRL1_SET;                         /**< AHB to APBH Bridge Control and Status Register 1, offset: 0x14 */
  __IO uint32_t CTRL1_CLR;                         /**< AHB to APBH Bridge Control and Status Register 1, offset: 0x18 */
  __IO uint32_t CTRL1_TOG;                         /**< AHB to APBH Bridge Control and Status Register 1, offset: 0x1C */
  __IO uint32_t CTRL2;                             /**< AHB to APBH Bridge Control and Status Register 2, offset: 0x20 */
  __IO uint32_t CTRL2_SET;                         /**< AHB to APBH Bridge Control and Status Register 2, offset: 0x24 */
  __IO uint32_t CTRL2_CLR;                         /**< AHB to APBH Bridge Control and Status Register 2, offset: 0x28 */
  __IO uint32_t CTRL2_TOG;                         /**< AHB to APBH Bridge Control and Status Register 2, offset: 0x2C */
  __IO uint32_t CHANNEL_CTRL;                      /**< AHB to APBH Bridge Channel Register, offset: 0x30 */
  __IO uint32_t CHANNEL_CTRL_SET;                  /**< AHB to APBH Bridge Channel Register, offset: 0x34 */
  __IO uint32_t CHANNEL_CTRL_CLR;                  /**< AHB to APBH Bridge Channel Register, offset: 0x38 */
  __IO uint32_t CHANNEL_CTRL_TOG;                  /**< AHB to APBH Bridge Channel Register, offset: 0x3C */
       uint32_t DEVSEL;                            /**< AHB to APBH DMA Device Assignment Register, offset: 0x40 */
       uint8_t RESERVED_0[12];
  __IO uint32_t DMA_BURST_SIZE;                    /**< AHB to APBH DMA burst size, offset: 0x50 */
       uint8_t RESERVED_1[12];
  __IO uint32_t DEBUGr;                            /**< AHB to APBH DMA Debug Register, offset: 0x60, 'r' suffix has been added to avoid clash with DEBUG symbolic constant */
       uint8_t RESERVED_2[156];
  __I  uint32_t CH0_CURCMDAR;                      /**< APBH DMA Channel n Current Command Address Register, offset: 0x100 */
       uint8_t RESERVED_3[12];
  __IO uint32_t CH0_NXTCMDAR;                      /**< APBH DMA Channel n Next Command Address Register, offset: 0x110 */
       uint8_t RESERVED_4[12];
  __I  uint32_t CH0_CMD;                           /**< APBH DMA Channel n Command Register, offset: 0x120 */
       uint8_t RESERVED_5[12];
  __I  uint32_t CH0_BAR;                           /**< APBH DMA Channel n Buffer Address Register, offset: 0x130 */
       uint8_t RESERVED_6[12];
  __IO uint32_t CH0_SEMA;                          /**< APBH DMA Channel n Semaphore Register, offset: 0x140 */
       uint8_t RESERVED_7[12];
  __I  uint32_t CH0_DEBUG1;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x150 */
       uint8_t RESERVED_8[12];
  __I  uint32_t CH0_DEBUG2;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x160 */
       uint8_t RESERVED_9[12];
  __I  uint32_t CH1_CURCMDAR;                      /**< APBH DMA Channel n Current Command Address Register, offset: 0x170 */
       uint8_t RESERVED_10[12];
  __IO uint32_t CH1_NXTCMDAR;                      /**< APBH DMA Channel n Next Command Address Register, offset: 0x180 */
       uint8_t RESERVED_11[12];
  __I  uint32_t CH1_CMD;                           /**< APBH DMA Channel n Command Register, offset: 0x190 */
       uint8_t RESERVED_12[12];
  __I  uint32_t CH1_BAR;                           /**< APBH DMA Channel n Buffer Address Register, offset: 0x1A0 */
       uint8_t RESERVED_13[12];
  __IO uint32_t CH1_SEMA;                          /**< APBH DMA Channel n Semaphore Register, offset: 0x1B0 */
       uint8_t RESERVED_14[12];
  __I  uint32_t CH1_DEBUG1;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x1C0 */
       uint8_t RESERVED_15[12];
  __I  uint32_t CH1_DEBUG2;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x1D0 */
       uint8_t RESERVED_16[12];
  __I  uint32_t CH2_CURCMDAR;                      /**< APBH DMA Channel n Current Command Address Register, offset: 0x1E0 */
       uint8_t RESERVED_17[12];
  __IO uint32_t CH2_NXTCMDAR;                      /**< APBH DMA Channel n Next Command Address Register, offset: 0x1F0 */
       uint8_t RESERVED_18[12];
  __I  uint32_t CH2_CMD;                           /**< APBH DMA Channel n Command Register, offset: 0x200 */
       uint8_t RESERVED_19[12];
  __I  uint32_t CH2_BAR;                           /**< APBH DMA Channel n Buffer Address Register, offset: 0x210 */
       uint8_t RESERVED_20[12];
  __IO uint32_t CH2_SEMA;                          /**< APBH DMA Channel n Semaphore Register, offset: 0x220 */
       uint8_t RESERVED_21[12];
  __I  uint32_t CH2_DEBUG1;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x230 */
       uint8_t RESERVED_22[12];
  __I  uint32_t CH2_DEBUG2;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x240 */
       uint8_t RESERVED_23[12];
  __I  uint32_t CH3_CURCMDAR;                      /**< APBH DMA Channel n Current Command Address Register, offset: 0x250 */
       uint8_t RESERVED_24[12];
  __IO uint32_t CH3_NXTCMDAR;                      /**< APBH DMA Channel n Next Command Address Register, offset: 0x260 */
       uint8_t RESERVED_25[12];
  __I  uint32_t CH3_CMD;                           /**< APBH DMA Channel n Command Register, offset: 0x270 */
       uint8_t RESERVED_26[12];
  __I  uint32_t CH3_BAR;                           /**< APBH DMA Channel n Buffer Address Register, offset: 0x280 */
       uint8_t RESERVED_27[12];
  __IO uint32_t CH3_SEMA;                          /**< APBH DMA Channel n Semaphore Register, offset: 0x290 */
       uint8_t RESERVED_28[12];
  __I  uint32_t CH3_DEBUG1;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x2A0 */
       uint8_t RESERVED_29[12];
  __I  uint32_t CH3_DEBUG2;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x2B0 */
       uint8_t RESERVED_30[12];
  __I  uint32_t CH4_CURCMDAR;                      /**< APBH DMA Channel n Current Command Address Register, offset: 0x2C0 */
       uint8_t RESERVED_31[12];
  __IO uint32_t CH4_NXTCMDAR;                      /**< APBH DMA Channel n Next Command Address Register, offset: 0x2D0 */
       uint8_t RESERVED_32[12];
  __I  uint32_t CH4_CMD;                           /**< APBH DMA Channel n Command Register, offset: 0x2E0 */
       uint8_t RESERVED_33[12];
  __I  uint32_t CH4_BAR;                           /**< APBH DMA Channel n Buffer Address Register, offset: 0x2F0 */
       uint8_t RESERVED_34[12];
  __IO uint32_t CH4_SEMA;                          /**< APBH DMA Channel n Semaphore Register, offset: 0x300 */
       uint8_t RESERVED_35[12];
  __I  uint32_t CH4_DEBUG1;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x310 */
       uint8_t RESERVED_36[12];
  __I  uint32_t CH4_DEBUG2;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x320 */
       uint8_t RESERVED_37[12];
  __I  uint32_t CH5_CURCMDAR;                      /**< APBH DMA Channel n Current Command Address Register, offset: 0x330 */
       uint8_t RESERVED_38[12];
  __IO uint32_t CH5_NXTCMDAR;                      /**< APBH DMA Channel n Next Command Address Register, offset: 0x340 */
       uint8_t RESERVED_39[12];
  __I  uint32_t CH5_CMD;                           /**< APBH DMA Channel n Command Register, offset: 0x350 */
       uint8_t RESERVED_40[12];
  __I  uint32_t CH5_BAR;                           /**< APBH DMA Channel n Buffer Address Register, offset: 0x360 */
       uint8_t RESERVED_41[12];
  __IO uint32_t CH5_SEMA;                          /**< APBH DMA Channel n Semaphore Register, offset: 0x370 */
       uint8_t RESERVED_42[12];
  __I  uint32_t CH5_DEBUG1;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x380 */
       uint8_t RESERVED_43[12];
  __I  uint32_t CH5_DEBUG2;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x390 */
       uint8_t RESERVED_44[12];
  __I  uint32_t CH6_CURCMDAR;                      /**< APBH DMA Channel n Current Command Address Register, offset: 0x3A0 */
       uint8_t RESERVED_45[12];
  __IO uint32_t CH6_NXTCMDAR;                      /**< APBH DMA Channel n Next Command Address Register, offset: 0x3B0 */
       uint8_t RESERVED_46[12];
  __I  uint32_t CH6_CMD;                           /**< APBH DMA Channel n Command Register, offset: 0x3C0 */
       uint8_t RESERVED_47[12];
  __I  uint32_t CH6_BAR;                           /**< APBH DMA Channel n Buffer Address Register, offset: 0x3D0 */
       uint8_t RESERVED_48[12];
  __IO uint32_t CH6_SEMA;                          /**< APBH DMA Channel n Semaphore Register, offset: 0x3E0 */
       uint8_t RESERVED_49[12];
  __I  uint32_t CH6_DEBUG1;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x3F0 */
       uint8_t RESERVED_50[12];
  __I  uint32_t CH6_DEBUG2;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x400 */
       uint8_t RESERVED_51[12];
  __I  uint32_t CH7_CURCMDAR;                      /**< APBH DMA Channel n Current Command Address Register, offset: 0x410 */
       uint8_t RESERVED_52[12];
  __IO uint32_t CH7_NXTCMDAR;                      /**< APBH DMA Channel n Next Command Address Register, offset: 0x420 */
       uint8_t RESERVED_53[12];
  __I  uint32_t CH7_CMD;                           /**< APBH DMA Channel n Command Register, offset: 0x430 */
       uint8_t RESERVED_54[12];
  __I  uint32_t CH7_BAR;                           /**< APBH DMA Channel n Buffer Address Register, offset: 0x440 */
       uint8_t RESERVED_55[12];
  __IO uint32_t CH7_SEMA;                          /**< APBH DMA Channel n Semaphore Register, offset: 0x450 */
       uint8_t RESERVED_56[12];
  __I  uint32_t CH7_DEBUG1;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x460 */
       uint8_t RESERVED_57[12];
  __I  uint32_t CH7_DEBUG2;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x470 */
       uint8_t RESERVED_58[12];
  __I  uint32_t CH8_CURCMDAR;                      /**< APBH DMA Channel n Current Command Address Register, offset: 0x480 */
       uint8_t RESERVED_59[12];
  __IO uint32_t CH8_NXTCMDAR;                      /**< APBH DMA Channel n Next Command Address Register, offset: 0x490 */
       uint8_t RESERVED_60[12];
  __I  uint32_t CH8_CMD;                           /**< APBH DMA Channel n Command Register, offset: 0x4A0 */
       uint8_t RESERVED_61[12];
  __I  uint32_t CH8_BAR;                           /**< APBH DMA Channel n Buffer Address Register, offset: 0x4B0 */
       uint8_t RESERVED_62[12];
  __IO uint32_t CH8_SEMA;                          /**< APBH DMA Channel n Semaphore Register, offset: 0x4C0 */
       uint8_t RESERVED_63[12];
  __I  uint32_t CH8_DEBUG1;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x4D0 */
       uint8_t RESERVED_64[12];
  __I  uint32_t CH8_DEBUG2;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x4E0 */
       uint8_t RESERVED_65[12];
  __I  uint32_t CH9_CURCMDAR;                      /**< APBH DMA Channel n Current Command Address Register, offset: 0x4F0 */
       uint8_t RESERVED_66[12];
  __IO uint32_t CH9_NXTCMDAR;                      /**< APBH DMA Channel n Next Command Address Register, offset: 0x500 */
       uint8_t RESERVED_67[12];
  __I  uint32_t CH9_CMD;                           /**< APBH DMA Channel n Command Register, offset: 0x510 */
       uint8_t RESERVED_68[12];
  __I  uint32_t CH9_BAR;                           /**< APBH DMA Channel n Buffer Address Register, offset: 0x520 */
       uint8_t RESERVED_69[12];
  __IO uint32_t CH9_SEMA;                          /**< APBH DMA Channel n Semaphore Register, offset: 0x530 */
       uint8_t RESERVED_70[12];
  __I  uint32_t CH9_DEBUG1;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x540 */
       uint8_t RESERVED_71[12];
  __I  uint32_t CH9_DEBUG2;                        /**< AHB to APBH DMA Channel n Debug Information, offset: 0x550 */
       uint8_t RESERVED_72[12];
  __I  uint32_t CH10_CURCMDAR;                     /**< APBH DMA Channel n Current Command Address Register, offset: 0x560 */
       uint8_t RESERVED_73[12];
  __IO uint32_t CH10_NXTCMDAR;                     /**< APBH DMA Channel n Next Command Address Register, offset: 0x570 */
       uint8_t RESERVED_74[12];
  __I  uint32_t CH10_CMD;                          /**< APBH DMA Channel n Command Register, offset: 0x580 */
       uint8_t RESERVED_75[12];
  __I  uint32_t CH10_BAR;                          /**< APBH DMA Channel n Buffer Address Register, offset: 0x590 */
       uint8_t RESERVED_76[12];
  __IO uint32_t CH10_SEMA;                         /**< APBH DMA Channel n Semaphore Register, offset: 0x5A0 */
       uint8_t RESERVED_77[12];
  __I  uint32_t CH10_DEBUG1;                       /**< AHB to APBH DMA Channel n Debug Information, offset: 0x5B0 */
       uint8_t RESERVED_78[12];
  __I  uint32_t CH10_DEBUG2;                       /**< AHB to APBH DMA Channel n Debug Information, offset: 0x5C0 */
       uint8_t RESERVED_79[12];
  __I  uint32_t CH11_CURCMDAR;                     /**< APBH DMA Channel n Current Command Address Register, offset: 0x5D0 */
       uint8_t RESERVED_80[12];
  __IO uint32_t CH11_NXTCMDAR;                     /**< APBH DMA Channel n Next Command Address Register, offset: 0x5E0 */
       uint8_t RESERVED_81[12];
  __I  uint32_t CH11_CMD;                          /**< APBH DMA Channel n Command Register, offset: 0x5F0 */
       uint8_t RESERVED_82[12];
  __I  uint32_t CH11_BAR;                          /**< APBH DMA Channel n Buffer Address Register, offset: 0x600 */
       uint8_t RESERVED_83[12];
  __IO uint32_t CH11_SEMA;                         /**< APBH DMA Channel n Semaphore Register, offset: 0x610 */
       uint8_t RESERVED_84[12];
  __I  uint32_t CH11_DEBUG1;                       /**< AHB to APBH DMA Channel n Debug Information, offset: 0x620 */
       uint8_t RESERVED_85[12];
  __I  uint32_t CH11_DEBUG2;                       /**< AHB to APBH DMA Channel n Debug Information, offset: 0x630 */
       uint8_t RESERVED_86[12];
  __I  uint32_t CH12_CURCMDAR;                     /**< APBH DMA Channel n Current Command Address Register, offset: 0x640 */
       uint8_t RESERVED_87[12];
  __IO uint32_t CH12_NXTCMDAR;                     /**< APBH DMA Channel n Next Command Address Register, offset: 0x650 */
       uint8_t RESERVED_88[12];
  __I  uint32_t CH12_CMD;                          /**< APBH DMA Channel n Command Register, offset: 0x660 */
       uint8_t RESERVED_89[12];
  __I  uint32_t CH12_BAR;                          /**< APBH DMA Channel n Buffer Address Register, offset: 0x670 */
       uint8_t RESERVED_90[12];
  __IO uint32_t CH12_SEMA;                         /**< APBH DMA Channel n Semaphore Register, offset: 0x680 */
       uint8_t RESERVED_91[12];
  __I  uint32_t CH12_DEBUG1;                       /**< AHB to APBH DMA Channel n Debug Information, offset: 0x690 */
       uint8_t RESERVED_92[12];
  __I  uint32_t CH12_DEBUG2;                       /**< AHB to APBH DMA Channel n Debug Information, offset: 0x6A0 */
       uint8_t RESERVED_93[12];
  __I  uint32_t CH13_CURCMDAR;                     /**< APBH DMA Channel n Current Command Address Register, offset: 0x6B0 */
       uint8_t RESERVED_94[12];
  __IO uint32_t CH13_NXTCMDAR;                     /**< APBH DMA Channel n Next Command Address Register, offset: 0x6C0 */
       uint8_t RESERVED_95[12];
  __I  uint32_t CH13_CMD;                          /**< APBH DMA Channel n Command Register, offset: 0x6D0 */
       uint8_t RESERVED_96[12];
  __I  uint32_t CH13_BAR;                          /**< APBH DMA Channel n Buffer Address Register, offset: 0x6E0 */
       uint8_t RESERVED_97[12];
  __IO uint32_t CH13_SEMA;                         /**< APBH DMA Channel n Semaphore Register, offset: 0x6F0 */
       uint8_t RESERVED_98[12];
  __I  uint32_t CH13_DEBUG1;                       /**< AHB to APBH DMA Channel n Debug Information, offset: 0x700 */
       uint8_t RESERVED_99[12];
  __I  uint32_t CH13_DEBUG2;                       /**< AHB to APBH DMA Channel n Debug Information, offset: 0x710 */
       uint8_t RESERVED_100[12];
  __I  uint32_t CH14_CURCMDAR;                     /**< APBH DMA Channel n Current Command Address Register, offset: 0x720 */
       uint8_t RESERVED_101[12];
  __IO uint32_t CH14_NXTCMDAR;                     /**< APBH DMA Channel n Next Command Address Register, offset: 0x730 */
       uint8_t RESERVED_102[12];
  __I  uint32_t CH14_CMD;                          /**< APBH DMA Channel n Command Register, offset: 0x740 */
       uint8_t RESERVED_103[12];
  __I  uint32_t CH14_BAR;                          /**< APBH DMA Channel n Buffer Address Register, offset: 0x750 */
       uint8_t RESERVED_104[12];
  __IO uint32_t CH14_SEMA;                         /**< APBH DMA Channel n Semaphore Register, offset: 0x760 */
       uint8_t RESERVED_105[12];
  __I  uint32_t CH14_DEBUG1;                       /**< AHB to APBH DMA Channel n Debug Information, offset: 0x770 */
       uint8_t RESERVED_106[12];
  __I  uint32_t CH14_DEBUG2;                       /**< AHB to APBH DMA Channel n Debug Information, offset: 0x780 */
       uint8_t RESERVED_107[12];
  __I  uint32_t CH15_CURCMDAR;                     /**< APBH DMA Channel n Current Command Address Register, offset: 0x790 */
       uint8_t RESERVED_108[12];
  __IO uint32_t CH15_NXTCMDAR;                     /**< APBH DMA Channel n Next Command Address Register, offset: 0x7A0 */
       uint8_t RESERVED_109[12];
  __I  uint32_t CH15_CMD;                          /**< APBH DMA Channel n Command Register, offset: 0x7B0 */
       uint8_t RESERVED_110[12];
  __I  uint32_t CH15_BAR;                          /**< APBH DMA Channel n Buffer Address Register, offset: 0x7C0 */
       uint8_t RESERVED_111[12];
  __IO uint32_t CH15_SEMA;                         /**< APBH DMA Channel n Semaphore Register, offset: 0x7D0 */
       uint8_t RESERVED_112[12];
  __I  uint32_t CH15_DEBUG1;                       /**< AHB to APBH DMA Channel n Debug Information, offset: 0x7E0 */
       uint8_t RESERVED_113[12];
  __I  uint32_t CH15_DEBUG2;                       /**< AHB to APBH DMA Channel n Debug Information, offset: 0x7F0 */
       uint8_t RESERVED_114[12];
  __I  uint32_t VERSION;                           /**< APBH Bridge Version Register, offset: 0x800 */
} APBH_Type;

/* ----------------------------------------------------------------------------
   -- APBH Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup APBH_Register_Masks APBH Register Masks
 * @{
 */

/*! @name CTRL0 - AHB to APBH Bridge Control and Status Register 0 */
/*! @{ */

#define APBH_CTRL0_CLKGATE_CHANNEL_MASK          (0xFFFFU)
#define APBH_CTRL0_CLKGATE_CHANNEL_SHIFT         (0U)
/*! CLKGATE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CTRL0_CLKGATE_CHANNEL(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLKGATE_CHANNEL_SHIFT)) & APBH_CTRL0_CLKGATE_CHANNEL_MASK)

#define APBH_CTRL0_RSVD0_MASK                    (0xFFF0000U)
#define APBH_CTRL0_RSVD0_SHIFT                   (16U)
#define APBH_CTRL0_RSVD0(x)                      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_RSVD0_SHIFT)) & APBH_CTRL0_RSVD0_MASK)

#define APBH_CTRL0_APB_BURST_EN_MASK             (0x10000000U)
#define APBH_CTRL0_APB_BURST_EN_SHIFT            (28U)
#define APBH_CTRL0_APB_BURST_EN(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_APB_BURST_EN_SHIFT)) & APBH_CTRL0_APB_BURST_EN_MASK)

#define APBH_CTRL0_AHB_BURST8_EN_MASK            (0x20000000U)
#define APBH_CTRL0_AHB_BURST8_EN_SHIFT           (29U)
#define APBH_CTRL0_AHB_BURST8_EN(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_AHB_BURST8_EN_SHIFT)) & APBH_CTRL0_AHB_BURST8_EN_MASK)

#define APBH_CTRL0_CLKGATE_MASK                  (0x40000000U)
#define APBH_CTRL0_CLKGATE_SHIFT                 (30U)
#define APBH_CTRL0_CLKGATE(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLKGATE_SHIFT)) & APBH_CTRL0_CLKGATE_MASK)

#define APBH_CTRL0_SFTRST_MASK                   (0x80000000U)
#define APBH_CTRL0_SFTRST_SHIFT                  (31U)
#define APBH_CTRL0_SFTRST(x)                     (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_SFTRST_SHIFT)) & APBH_CTRL0_SFTRST_MASK)
/*! @} */

/*! @name CTRL0_SET - AHB to APBH Bridge Control and Status Register 0 */
/*! @{ */

#define APBH_CTRL0_SET_CLKGATE_CHANNEL_MASK      (0xFFFFU)
#define APBH_CTRL0_SET_CLKGATE_CHANNEL_SHIFT     (0U)
/*! CLKGATE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CTRL0_SET_CLKGATE_CHANNEL(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_SET_CLKGATE_CHANNEL_SHIFT)) & APBH_CTRL0_SET_CLKGATE_CHANNEL_MASK)

#define APBH_CTRL0_SET_RSVD0_MASK                (0xFFF0000U)
#define APBH_CTRL0_SET_RSVD0_SHIFT               (16U)
#define APBH_CTRL0_SET_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_SET_RSVD0_SHIFT)) & APBH_CTRL0_SET_RSVD0_MASK)

#define APBH_CTRL0_SET_APB_BURST_EN_MASK         (0x10000000U)
#define APBH_CTRL0_SET_APB_BURST_EN_SHIFT        (28U)
#define APBH_CTRL0_SET_APB_BURST_EN(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_SET_APB_BURST_EN_SHIFT)) & APBH_CTRL0_SET_APB_BURST_EN_MASK)

#define APBH_CTRL0_SET_AHB_BURST8_EN_MASK        (0x20000000U)
#define APBH_CTRL0_SET_AHB_BURST8_EN_SHIFT       (29U)
#define APBH_CTRL0_SET_AHB_BURST8_EN(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_SET_AHB_BURST8_EN_SHIFT)) & APBH_CTRL0_SET_AHB_BURST8_EN_MASK)

#define APBH_CTRL0_SET_CLKGATE_MASK              (0x40000000U)
#define APBH_CTRL0_SET_CLKGATE_SHIFT             (30U)
#define APBH_CTRL0_SET_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_SET_CLKGATE_SHIFT)) & APBH_CTRL0_SET_CLKGATE_MASK)

#define APBH_CTRL0_SET_SFTRST_MASK               (0x80000000U)
#define APBH_CTRL0_SET_SFTRST_SHIFT              (31U)
#define APBH_CTRL0_SET_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_SET_SFTRST_SHIFT)) & APBH_CTRL0_SET_SFTRST_MASK)
/*! @} */

/*! @name CTRL0_CLR - AHB to APBH Bridge Control and Status Register 0 */
/*! @{ */

#define APBH_CTRL0_CLR_CLKGATE_CHANNEL_MASK      (0xFFFFU)
#define APBH_CTRL0_CLR_CLKGATE_CHANNEL_SHIFT     (0U)
/*! CLKGATE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CTRL0_CLR_CLKGATE_CHANNEL(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLR_CLKGATE_CHANNEL_SHIFT)) & APBH_CTRL0_CLR_CLKGATE_CHANNEL_MASK)

#define APBH_CTRL0_CLR_RSVD0_MASK                (0xFFF0000U)
#define APBH_CTRL0_CLR_RSVD0_SHIFT               (16U)
#define APBH_CTRL0_CLR_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLR_RSVD0_SHIFT)) & APBH_CTRL0_CLR_RSVD0_MASK)

#define APBH_CTRL0_CLR_APB_BURST_EN_MASK         (0x10000000U)
#define APBH_CTRL0_CLR_APB_BURST_EN_SHIFT        (28U)
#define APBH_CTRL0_CLR_APB_BURST_EN(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLR_APB_BURST_EN_SHIFT)) & APBH_CTRL0_CLR_APB_BURST_EN_MASK)

#define APBH_CTRL0_CLR_AHB_BURST8_EN_MASK        (0x20000000U)
#define APBH_CTRL0_CLR_AHB_BURST8_EN_SHIFT       (29U)
#define APBH_CTRL0_CLR_AHB_BURST8_EN(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLR_AHB_BURST8_EN_SHIFT)) & APBH_CTRL0_CLR_AHB_BURST8_EN_MASK)

#define APBH_CTRL0_CLR_CLKGATE_MASK              (0x40000000U)
#define APBH_CTRL0_CLR_CLKGATE_SHIFT             (30U)
#define APBH_CTRL0_CLR_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLR_CLKGATE_SHIFT)) & APBH_CTRL0_CLR_CLKGATE_MASK)

#define APBH_CTRL0_CLR_SFTRST_MASK               (0x80000000U)
#define APBH_CTRL0_CLR_SFTRST_SHIFT              (31U)
#define APBH_CTRL0_CLR_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLR_SFTRST_SHIFT)) & APBH_CTRL0_CLR_SFTRST_MASK)
/*! @} */

/*! @name CTRL0_TOG - AHB to APBH Bridge Control and Status Register 0 */
/*! @{ */

#define APBH_CTRL0_TOG_CLKGATE_CHANNEL_MASK      (0xFFFFU)
#define APBH_CTRL0_TOG_CLKGATE_CHANNEL_SHIFT     (0U)
/*! CLKGATE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CTRL0_TOG_CLKGATE_CHANNEL(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_TOG_CLKGATE_CHANNEL_SHIFT)) & APBH_CTRL0_TOG_CLKGATE_CHANNEL_MASK)

#define APBH_CTRL0_TOG_RSVD0_MASK                (0xFFF0000U)
#define APBH_CTRL0_TOG_RSVD0_SHIFT               (16U)
#define APBH_CTRL0_TOG_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_TOG_RSVD0_SHIFT)) & APBH_CTRL0_TOG_RSVD0_MASK)

#define APBH_CTRL0_TOG_APB_BURST_EN_MASK         (0x10000000U)
#define APBH_CTRL0_TOG_APB_BURST_EN_SHIFT        (28U)
#define APBH_CTRL0_TOG_APB_BURST_EN(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_TOG_APB_BURST_EN_SHIFT)) & APBH_CTRL0_TOG_APB_BURST_EN_MASK)

#define APBH_CTRL0_TOG_AHB_BURST8_EN_MASK        (0x20000000U)
#define APBH_CTRL0_TOG_AHB_BURST8_EN_SHIFT       (29U)
#define APBH_CTRL0_TOG_AHB_BURST8_EN(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_TOG_AHB_BURST8_EN_SHIFT)) & APBH_CTRL0_TOG_AHB_BURST8_EN_MASK)

#define APBH_CTRL0_TOG_CLKGATE_MASK              (0x40000000U)
#define APBH_CTRL0_TOG_CLKGATE_SHIFT             (30U)
#define APBH_CTRL0_TOG_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_TOG_CLKGATE_SHIFT)) & APBH_CTRL0_TOG_CLKGATE_MASK)

#define APBH_CTRL0_TOG_SFTRST_MASK               (0x80000000U)
#define APBH_CTRL0_TOG_SFTRST_SHIFT              (31U)
#define APBH_CTRL0_TOG_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_TOG_SFTRST_SHIFT)) & APBH_CTRL0_TOG_SFTRST_MASK)
/*! @} */

/*! @name CTRL1 - AHB to APBH Bridge Control and Status Register 1 */
/*! @{ */

#define APBH_CTRL1_CH0_CMDCMPLT_IRQ_MASK         (0x1U)
#define APBH_CTRL1_CH0_CMDCMPLT_IRQ_SHIFT        (0U)
#define APBH_CTRL1_CH0_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH0_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH0_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH1_CMDCMPLT_IRQ_MASK         (0x2U)
#define APBH_CTRL1_CH1_CMDCMPLT_IRQ_SHIFT        (1U)
#define APBH_CTRL1_CH1_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH1_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH1_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH2_CMDCMPLT_IRQ_MASK         (0x4U)
#define APBH_CTRL1_CH2_CMDCMPLT_IRQ_SHIFT        (2U)
#define APBH_CTRL1_CH2_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH2_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH2_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH3_CMDCMPLT_IRQ_MASK         (0x8U)
#define APBH_CTRL1_CH3_CMDCMPLT_IRQ_SHIFT        (3U)
#define APBH_CTRL1_CH3_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH3_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH3_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH4_CMDCMPLT_IRQ_MASK         (0x10U)
#define APBH_CTRL1_CH4_CMDCMPLT_IRQ_SHIFT        (4U)
#define APBH_CTRL1_CH4_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH4_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH4_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH5_CMDCMPLT_IRQ_MASK         (0x20U)
#define APBH_CTRL1_CH5_CMDCMPLT_IRQ_SHIFT        (5U)
#define APBH_CTRL1_CH5_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH5_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH5_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH6_CMDCMPLT_IRQ_MASK         (0x40U)
#define APBH_CTRL1_CH6_CMDCMPLT_IRQ_SHIFT        (6U)
#define APBH_CTRL1_CH6_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH6_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH6_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH7_CMDCMPLT_IRQ_MASK         (0x80U)
#define APBH_CTRL1_CH7_CMDCMPLT_IRQ_SHIFT        (7U)
#define APBH_CTRL1_CH7_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH7_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH7_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH8_CMDCMPLT_IRQ_MASK         (0x100U)
#define APBH_CTRL1_CH8_CMDCMPLT_IRQ_SHIFT        (8U)
#define APBH_CTRL1_CH8_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH8_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH8_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH9_CMDCMPLT_IRQ_MASK         (0x200U)
#define APBH_CTRL1_CH9_CMDCMPLT_IRQ_SHIFT        (9U)
#define APBH_CTRL1_CH9_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH9_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH9_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH10_CMDCMPLT_IRQ_MASK        (0x400U)
#define APBH_CTRL1_CH10_CMDCMPLT_IRQ_SHIFT       (10U)
#define APBH_CTRL1_CH10_CMDCMPLT_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH10_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH10_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH11_CMDCMPLT_IRQ_MASK        (0x800U)
#define APBH_CTRL1_CH11_CMDCMPLT_IRQ_SHIFT       (11U)
#define APBH_CTRL1_CH11_CMDCMPLT_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH11_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH11_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH12_CMDCMPLT_IRQ_MASK        (0x1000U)
#define APBH_CTRL1_CH12_CMDCMPLT_IRQ_SHIFT       (12U)
#define APBH_CTRL1_CH12_CMDCMPLT_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH12_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH12_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH13_CMDCMPLT_IRQ_MASK        (0x2000U)
#define APBH_CTRL1_CH13_CMDCMPLT_IRQ_SHIFT       (13U)
#define APBH_CTRL1_CH13_CMDCMPLT_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH13_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH13_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH14_CMDCMPLT_IRQ_MASK        (0x4000U)
#define APBH_CTRL1_CH14_CMDCMPLT_IRQ_SHIFT       (14U)
#define APBH_CTRL1_CH14_CMDCMPLT_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH14_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH14_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH15_CMDCMPLT_IRQ_MASK        (0x8000U)
#define APBH_CTRL1_CH15_CMDCMPLT_IRQ_SHIFT       (15U)
#define APBH_CTRL1_CH15_CMDCMPLT_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH15_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH15_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH0_CMDCMPLT_IRQ_EN_MASK      (0x10000U)
#define APBH_CTRL1_CH0_CMDCMPLT_IRQ_EN_SHIFT     (16U)
#define APBH_CTRL1_CH0_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH0_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH0_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH1_CMDCMPLT_IRQ_EN_MASK      (0x20000U)
#define APBH_CTRL1_CH1_CMDCMPLT_IRQ_EN_SHIFT     (17U)
#define APBH_CTRL1_CH1_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH1_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH1_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH2_CMDCMPLT_IRQ_EN_MASK      (0x40000U)
#define APBH_CTRL1_CH2_CMDCMPLT_IRQ_EN_SHIFT     (18U)
#define APBH_CTRL1_CH2_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH2_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH2_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH3_CMDCMPLT_IRQ_EN_MASK      (0x80000U)
#define APBH_CTRL1_CH3_CMDCMPLT_IRQ_EN_SHIFT     (19U)
#define APBH_CTRL1_CH3_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH3_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH3_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH4_CMDCMPLT_IRQ_EN_MASK      (0x100000U)
#define APBH_CTRL1_CH4_CMDCMPLT_IRQ_EN_SHIFT     (20U)
#define APBH_CTRL1_CH4_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH4_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH4_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH5_CMDCMPLT_IRQ_EN_MASK      (0x200000U)
#define APBH_CTRL1_CH5_CMDCMPLT_IRQ_EN_SHIFT     (21U)
#define APBH_CTRL1_CH5_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH5_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH5_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH6_CMDCMPLT_IRQ_EN_MASK      (0x400000U)
#define APBH_CTRL1_CH6_CMDCMPLT_IRQ_EN_SHIFT     (22U)
#define APBH_CTRL1_CH6_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH6_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH6_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH7_CMDCMPLT_IRQ_EN_MASK      (0x800000U)
#define APBH_CTRL1_CH7_CMDCMPLT_IRQ_EN_SHIFT     (23U)
#define APBH_CTRL1_CH7_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH7_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH7_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH8_CMDCMPLT_IRQ_EN_MASK      (0x1000000U)
#define APBH_CTRL1_CH8_CMDCMPLT_IRQ_EN_SHIFT     (24U)
#define APBH_CTRL1_CH8_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH8_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH8_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH9_CMDCMPLT_IRQ_EN_MASK      (0x2000000U)
#define APBH_CTRL1_CH9_CMDCMPLT_IRQ_EN_SHIFT     (25U)
#define APBH_CTRL1_CH9_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH9_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH9_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH10_CMDCMPLT_IRQ_EN_MASK     (0x4000000U)
#define APBH_CTRL1_CH10_CMDCMPLT_IRQ_EN_SHIFT    (26U)
#define APBH_CTRL1_CH10_CMDCMPLT_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH10_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH10_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH11_CMDCMPLT_IRQ_EN_MASK     (0x8000000U)
#define APBH_CTRL1_CH11_CMDCMPLT_IRQ_EN_SHIFT    (27U)
#define APBH_CTRL1_CH11_CMDCMPLT_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH11_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH11_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH12_CMDCMPLT_IRQ_EN_MASK     (0x10000000U)
#define APBH_CTRL1_CH12_CMDCMPLT_IRQ_EN_SHIFT    (28U)
#define APBH_CTRL1_CH12_CMDCMPLT_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH12_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH12_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH13_CMDCMPLT_IRQ_EN_MASK     (0x20000000U)
#define APBH_CTRL1_CH13_CMDCMPLT_IRQ_EN_SHIFT    (29U)
#define APBH_CTRL1_CH13_CMDCMPLT_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH13_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH13_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH14_CMDCMPLT_IRQ_EN_MASK     (0x40000000U)
#define APBH_CTRL1_CH14_CMDCMPLT_IRQ_EN_SHIFT    (30U)
#define APBH_CTRL1_CH14_CMDCMPLT_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH14_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH14_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH15_CMDCMPLT_IRQ_EN_MASK     (0x80000000U)
#define APBH_CTRL1_CH15_CMDCMPLT_IRQ_EN_SHIFT    (31U)
#define APBH_CTRL1_CH15_CMDCMPLT_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH15_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH15_CMDCMPLT_IRQ_EN_MASK)
/*! @} */

/*! @name CTRL1_SET - AHB to APBH Bridge Control and Status Register 1 */
/*! @{ */

#define APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_MASK     (0x1U)
#define APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_SHIFT    (0U)
#define APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_MASK     (0x2U)
#define APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_SHIFT    (1U)
#define APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_MASK     (0x4U)
#define APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_SHIFT    (2U)
#define APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_MASK     (0x8U)
#define APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_SHIFT    (3U)
#define APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_MASK     (0x10U)
#define APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_SHIFT    (4U)
#define APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_MASK     (0x20U)
#define APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_SHIFT    (5U)
#define APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_MASK     (0x40U)
#define APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_SHIFT    (6U)
#define APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_MASK     (0x80U)
#define APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_SHIFT    (7U)
#define APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_MASK     (0x100U)
#define APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_SHIFT    (8U)
#define APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_MASK     (0x200U)
#define APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_SHIFT    (9U)
#define APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_MASK    (0x400U)
#define APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_SHIFT   (10U)
#define APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_MASK    (0x800U)
#define APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_SHIFT   (11U)
#define APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_MASK    (0x1000U)
#define APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_SHIFT   (12U)
#define APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_MASK    (0x2000U)
#define APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_SHIFT   (13U)
#define APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_MASK    (0x4000U)
#define APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_SHIFT   (14U)
#define APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_MASK    (0x8000U)
#define APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_SHIFT   (15U)
#define APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_EN_MASK  (0x10000U)
#define APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_EN_SHIFT (16U)
#define APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_EN_MASK  (0x20000U)
#define APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_EN_SHIFT (17U)
#define APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_EN_MASK  (0x40000U)
#define APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_EN_SHIFT (18U)
#define APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_EN_MASK  (0x80000U)
#define APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_EN_SHIFT (19U)
#define APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_EN_MASK  (0x100000U)
#define APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_EN_SHIFT (20U)
#define APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_EN_MASK  (0x200000U)
#define APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_EN_SHIFT (21U)
#define APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_EN_MASK  (0x400000U)
#define APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_EN_SHIFT (22U)
#define APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_EN_MASK  (0x800000U)
#define APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_EN_SHIFT (23U)
#define APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_EN_MASK  (0x1000000U)
#define APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_EN_SHIFT (24U)
#define APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_EN_MASK  (0x2000000U)
#define APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_EN_SHIFT (25U)
#define APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_EN_MASK (0x4000000U)
#define APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_EN_SHIFT (26U)
#define APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_EN_MASK (0x8000000U)
#define APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_EN_SHIFT (27U)
#define APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_EN_MASK (0x10000000U)
#define APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_EN_SHIFT (28U)
#define APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_EN_MASK (0x20000000U)
#define APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_EN_SHIFT (29U)
#define APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_EN_MASK (0x40000000U)
#define APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_EN_SHIFT (30U)
#define APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_EN_MASK (0x80000000U)
#define APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_EN_SHIFT (31U)
#define APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_EN_MASK)
/*! @} */

/*! @name CTRL1_CLR - AHB to APBH Bridge Control and Status Register 1 */
/*! @{ */

#define APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_MASK     (0x1U)
#define APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_SHIFT    (0U)
#define APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_MASK     (0x2U)
#define APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_SHIFT    (1U)
#define APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_MASK     (0x4U)
#define APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_SHIFT    (2U)
#define APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_MASK     (0x8U)
#define APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_SHIFT    (3U)
#define APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_MASK     (0x10U)
#define APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_SHIFT    (4U)
#define APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_MASK     (0x20U)
#define APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_SHIFT    (5U)
#define APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_MASK     (0x40U)
#define APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_SHIFT    (6U)
#define APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_MASK     (0x80U)
#define APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_SHIFT    (7U)
#define APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_MASK     (0x100U)
#define APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_SHIFT    (8U)
#define APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_MASK     (0x200U)
#define APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_SHIFT    (9U)
#define APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_MASK    (0x400U)
#define APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_SHIFT   (10U)
#define APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_MASK    (0x800U)
#define APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_SHIFT   (11U)
#define APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_MASK    (0x1000U)
#define APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_SHIFT   (12U)
#define APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_MASK    (0x2000U)
#define APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_SHIFT   (13U)
#define APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_MASK    (0x4000U)
#define APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_SHIFT   (14U)
#define APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_MASK    (0x8000U)
#define APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_SHIFT   (15U)
#define APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_EN_MASK  (0x10000U)
#define APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_EN_SHIFT (16U)
#define APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_EN_MASK  (0x20000U)
#define APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_EN_SHIFT (17U)
#define APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_EN_MASK  (0x40000U)
#define APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_EN_SHIFT (18U)
#define APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_EN_MASK  (0x80000U)
#define APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_EN_SHIFT (19U)
#define APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_EN_MASK  (0x100000U)
#define APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_EN_SHIFT (20U)
#define APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_EN_MASK  (0x200000U)
#define APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_EN_SHIFT (21U)
#define APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_EN_MASK  (0x400000U)
#define APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_EN_SHIFT (22U)
#define APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_EN_MASK  (0x800000U)
#define APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_EN_SHIFT (23U)
#define APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_EN_MASK  (0x1000000U)
#define APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_EN_SHIFT (24U)
#define APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_EN_MASK  (0x2000000U)
#define APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_EN_SHIFT (25U)
#define APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_EN_MASK (0x4000000U)
#define APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_EN_SHIFT (26U)
#define APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_EN_MASK (0x8000000U)
#define APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_EN_SHIFT (27U)
#define APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_EN_MASK (0x10000000U)
#define APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_EN_SHIFT (28U)
#define APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_EN_MASK (0x20000000U)
#define APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_EN_SHIFT (29U)
#define APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_EN_MASK (0x40000000U)
#define APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_EN_SHIFT (30U)
#define APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_EN_MASK (0x80000000U)
#define APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_EN_SHIFT (31U)
#define APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_EN_MASK)
/*! @} */

/*! @name CTRL1_TOG - AHB to APBH Bridge Control and Status Register 1 */
/*! @{ */

#define APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_MASK     (0x1U)
#define APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_SHIFT    (0U)
#define APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_MASK     (0x2U)
#define APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_SHIFT    (1U)
#define APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_MASK     (0x4U)
#define APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_SHIFT    (2U)
#define APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_MASK     (0x8U)
#define APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_SHIFT    (3U)
#define APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_MASK     (0x10U)
#define APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_SHIFT    (4U)
#define APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_MASK     (0x20U)
#define APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_SHIFT    (5U)
#define APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_MASK     (0x40U)
#define APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_SHIFT    (6U)
#define APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_MASK     (0x80U)
#define APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_SHIFT    (7U)
#define APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_MASK     (0x100U)
#define APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_SHIFT    (8U)
#define APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_MASK     (0x200U)
#define APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_SHIFT    (9U)
#define APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_MASK    (0x400U)
#define APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_SHIFT   (10U)
#define APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_MASK    (0x800U)
#define APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_SHIFT   (11U)
#define APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_MASK    (0x1000U)
#define APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_SHIFT   (12U)
#define APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_MASK    (0x2000U)
#define APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_SHIFT   (13U)
#define APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_MASK    (0x4000U)
#define APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_SHIFT   (14U)
#define APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_MASK    (0x8000U)
#define APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_SHIFT   (15U)
#define APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_EN_MASK  (0x10000U)
#define APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_EN_SHIFT (16U)
#define APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_EN_MASK  (0x20000U)
#define APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_EN_SHIFT (17U)
#define APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_EN_MASK  (0x40000U)
#define APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_EN_SHIFT (18U)
#define APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_EN_MASK  (0x80000U)
#define APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_EN_SHIFT (19U)
#define APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_EN_MASK  (0x100000U)
#define APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_EN_SHIFT (20U)
#define APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_EN_MASK  (0x200000U)
#define APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_EN_SHIFT (21U)
#define APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_EN_MASK  (0x400000U)
#define APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_EN_SHIFT (22U)
#define APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_EN_MASK  (0x800000U)
#define APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_EN_SHIFT (23U)
#define APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_EN_MASK  (0x1000000U)
#define APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_EN_SHIFT (24U)
#define APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_EN_MASK  (0x2000000U)
#define APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_EN_SHIFT (25U)
#define APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_EN_MASK (0x4000000U)
#define APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_EN_SHIFT (26U)
#define APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_EN_MASK (0x8000000U)
#define APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_EN_SHIFT (27U)
#define APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_EN_MASK (0x10000000U)
#define APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_EN_SHIFT (28U)
#define APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_EN_MASK (0x20000000U)
#define APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_EN_SHIFT (29U)
#define APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_EN_MASK (0x40000000U)
#define APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_EN_SHIFT (30U)
#define APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_EN_MASK (0x80000000U)
#define APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_EN_SHIFT (31U)
#define APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_EN_MASK)
/*! @} */

/*! @name CTRL2 - AHB to APBH Bridge Control and Status Register 2 */
/*! @{ */

#define APBH_CTRL2_CH0_ERROR_IRQ_MASK            (0x1U)
#define APBH_CTRL2_CH0_ERROR_IRQ_SHIFT           (0U)
#define APBH_CTRL2_CH0_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH0_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH0_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH1_ERROR_IRQ_MASK            (0x2U)
#define APBH_CTRL2_CH1_ERROR_IRQ_SHIFT           (1U)
#define APBH_CTRL2_CH1_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH1_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH1_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH2_ERROR_IRQ_MASK            (0x4U)
#define APBH_CTRL2_CH2_ERROR_IRQ_SHIFT           (2U)
#define APBH_CTRL2_CH2_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH2_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH2_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH3_ERROR_IRQ_MASK            (0x8U)
#define APBH_CTRL2_CH3_ERROR_IRQ_SHIFT           (3U)
#define APBH_CTRL2_CH3_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH3_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH3_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH4_ERROR_IRQ_MASK            (0x10U)
#define APBH_CTRL2_CH4_ERROR_IRQ_SHIFT           (4U)
#define APBH_CTRL2_CH4_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH4_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH4_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH5_ERROR_IRQ_MASK            (0x20U)
#define APBH_CTRL2_CH5_ERROR_IRQ_SHIFT           (5U)
#define APBH_CTRL2_CH5_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH5_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH5_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH6_ERROR_IRQ_MASK            (0x40U)
#define APBH_CTRL2_CH6_ERROR_IRQ_SHIFT           (6U)
#define APBH_CTRL2_CH6_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH6_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH6_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH7_ERROR_IRQ_MASK            (0x80U)
#define APBH_CTRL2_CH7_ERROR_IRQ_SHIFT           (7U)
#define APBH_CTRL2_CH7_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH7_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH7_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH8_ERROR_IRQ_MASK            (0x100U)
#define APBH_CTRL2_CH8_ERROR_IRQ_SHIFT           (8U)
#define APBH_CTRL2_CH8_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH8_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH8_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH9_ERROR_IRQ_MASK            (0x200U)
#define APBH_CTRL2_CH9_ERROR_IRQ_SHIFT           (9U)
#define APBH_CTRL2_CH9_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH9_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH9_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH10_ERROR_IRQ_MASK           (0x400U)
#define APBH_CTRL2_CH10_ERROR_IRQ_SHIFT          (10U)
#define APBH_CTRL2_CH10_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH10_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH10_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH11_ERROR_IRQ_MASK           (0x800U)
#define APBH_CTRL2_CH11_ERROR_IRQ_SHIFT          (11U)
#define APBH_CTRL2_CH11_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH11_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH11_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH12_ERROR_IRQ_MASK           (0x1000U)
#define APBH_CTRL2_CH12_ERROR_IRQ_SHIFT          (12U)
#define APBH_CTRL2_CH12_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH12_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH12_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH13_ERROR_IRQ_MASK           (0x2000U)
#define APBH_CTRL2_CH13_ERROR_IRQ_SHIFT          (13U)
#define APBH_CTRL2_CH13_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH13_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH13_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH14_ERROR_IRQ_MASK           (0x4000U)
#define APBH_CTRL2_CH14_ERROR_IRQ_SHIFT          (14U)
#define APBH_CTRL2_CH14_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH14_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH14_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH15_ERROR_IRQ_MASK           (0x8000U)
#define APBH_CTRL2_CH15_ERROR_IRQ_SHIFT          (15U)
#define APBH_CTRL2_CH15_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH15_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH15_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH0_ERROR_STATUS_MASK         (0x10000U)
#define APBH_CTRL2_CH0_ERROR_STATUS_SHIFT        (16U)
/*! CH0_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH0_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH0_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH0_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH1_ERROR_STATUS_MASK         (0x20000U)
#define APBH_CTRL2_CH1_ERROR_STATUS_SHIFT        (17U)
/*! CH1_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH1_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH1_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH1_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH2_ERROR_STATUS_MASK         (0x40000U)
#define APBH_CTRL2_CH2_ERROR_STATUS_SHIFT        (18U)
/*! CH2_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH2_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH2_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH2_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH3_ERROR_STATUS_MASK         (0x80000U)
#define APBH_CTRL2_CH3_ERROR_STATUS_SHIFT        (19U)
/*! CH3_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH3_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH3_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH3_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH4_ERROR_STATUS_MASK         (0x100000U)
#define APBH_CTRL2_CH4_ERROR_STATUS_SHIFT        (20U)
/*! CH4_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH4_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH4_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH4_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH5_ERROR_STATUS_MASK         (0x200000U)
#define APBH_CTRL2_CH5_ERROR_STATUS_SHIFT        (21U)
/*! CH5_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH5_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH5_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH5_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH6_ERROR_STATUS_MASK         (0x400000U)
#define APBH_CTRL2_CH6_ERROR_STATUS_SHIFT        (22U)
/*! CH6_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH6_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH6_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH6_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH7_ERROR_STATUS_MASK         (0x800000U)
#define APBH_CTRL2_CH7_ERROR_STATUS_SHIFT        (23U)
/*! CH7_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH7_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH7_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH7_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH8_ERROR_STATUS_MASK         (0x1000000U)
#define APBH_CTRL2_CH8_ERROR_STATUS_SHIFT        (24U)
/*! CH8_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH8_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH8_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH8_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH9_ERROR_STATUS_MASK         (0x2000000U)
#define APBH_CTRL2_CH9_ERROR_STATUS_SHIFT        (25U)
/*! CH9_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH9_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH9_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH9_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH10_ERROR_STATUS_MASK        (0x4000000U)
#define APBH_CTRL2_CH10_ERROR_STATUS_SHIFT       (26U)
/*! CH10_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH10_ERROR_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH10_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH10_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH11_ERROR_STATUS_MASK        (0x8000000U)
#define APBH_CTRL2_CH11_ERROR_STATUS_SHIFT       (27U)
/*! CH11_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH11_ERROR_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH11_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH11_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH12_ERROR_STATUS_MASK        (0x10000000U)
#define APBH_CTRL2_CH12_ERROR_STATUS_SHIFT       (28U)
/*! CH12_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH12_ERROR_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH12_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH12_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH13_ERROR_STATUS_MASK        (0x20000000U)
#define APBH_CTRL2_CH13_ERROR_STATUS_SHIFT       (29U)
/*! CH13_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH13_ERROR_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH13_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH13_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH14_ERROR_STATUS_MASK        (0x40000000U)
#define APBH_CTRL2_CH14_ERROR_STATUS_SHIFT       (30U)
/*! CH14_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH14_ERROR_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH14_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH14_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH15_ERROR_STATUS_MASK        (0x80000000U)
#define APBH_CTRL2_CH15_ERROR_STATUS_SHIFT       (31U)
/*! CH15_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH15_ERROR_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH15_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH15_ERROR_STATUS_MASK)
/*! @} */

/*! @name CTRL2_SET - AHB to APBH Bridge Control and Status Register 2 */
/*! @{ */

#define APBH_CTRL2_SET_CH0_ERROR_IRQ_MASK        (0x1U)
#define APBH_CTRL2_SET_CH0_ERROR_IRQ_SHIFT       (0U)
#define APBH_CTRL2_SET_CH0_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH0_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH0_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH1_ERROR_IRQ_MASK        (0x2U)
#define APBH_CTRL2_SET_CH1_ERROR_IRQ_SHIFT       (1U)
#define APBH_CTRL2_SET_CH1_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH1_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH1_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH2_ERROR_IRQ_MASK        (0x4U)
#define APBH_CTRL2_SET_CH2_ERROR_IRQ_SHIFT       (2U)
#define APBH_CTRL2_SET_CH2_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH2_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH2_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH3_ERROR_IRQ_MASK        (0x8U)
#define APBH_CTRL2_SET_CH3_ERROR_IRQ_SHIFT       (3U)
#define APBH_CTRL2_SET_CH3_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH3_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH3_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH4_ERROR_IRQ_MASK        (0x10U)
#define APBH_CTRL2_SET_CH4_ERROR_IRQ_SHIFT       (4U)
#define APBH_CTRL2_SET_CH4_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH4_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH4_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH5_ERROR_IRQ_MASK        (0x20U)
#define APBH_CTRL2_SET_CH5_ERROR_IRQ_SHIFT       (5U)
#define APBH_CTRL2_SET_CH5_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH5_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH5_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH6_ERROR_IRQ_MASK        (0x40U)
#define APBH_CTRL2_SET_CH6_ERROR_IRQ_SHIFT       (6U)
#define APBH_CTRL2_SET_CH6_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH6_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH6_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH7_ERROR_IRQ_MASK        (0x80U)
#define APBH_CTRL2_SET_CH7_ERROR_IRQ_SHIFT       (7U)
#define APBH_CTRL2_SET_CH7_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH7_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH7_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH8_ERROR_IRQ_MASK        (0x100U)
#define APBH_CTRL2_SET_CH8_ERROR_IRQ_SHIFT       (8U)
#define APBH_CTRL2_SET_CH8_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH8_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH8_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH9_ERROR_IRQ_MASK        (0x200U)
#define APBH_CTRL2_SET_CH9_ERROR_IRQ_SHIFT       (9U)
#define APBH_CTRL2_SET_CH9_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH9_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH9_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH10_ERROR_IRQ_MASK       (0x400U)
#define APBH_CTRL2_SET_CH10_ERROR_IRQ_SHIFT      (10U)
#define APBH_CTRL2_SET_CH10_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH10_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH10_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH11_ERROR_IRQ_MASK       (0x800U)
#define APBH_CTRL2_SET_CH11_ERROR_IRQ_SHIFT      (11U)
#define APBH_CTRL2_SET_CH11_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH11_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH11_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH12_ERROR_IRQ_MASK       (0x1000U)
#define APBH_CTRL2_SET_CH12_ERROR_IRQ_SHIFT      (12U)
#define APBH_CTRL2_SET_CH12_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH12_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH12_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH13_ERROR_IRQ_MASK       (0x2000U)
#define APBH_CTRL2_SET_CH13_ERROR_IRQ_SHIFT      (13U)
#define APBH_CTRL2_SET_CH13_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH13_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH13_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH14_ERROR_IRQ_MASK       (0x4000U)
#define APBH_CTRL2_SET_CH14_ERROR_IRQ_SHIFT      (14U)
#define APBH_CTRL2_SET_CH14_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH14_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH14_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH15_ERROR_IRQ_MASK       (0x8000U)
#define APBH_CTRL2_SET_CH15_ERROR_IRQ_SHIFT      (15U)
#define APBH_CTRL2_SET_CH15_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH15_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH15_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH0_ERROR_STATUS_MASK     (0x10000U)
#define APBH_CTRL2_SET_CH0_ERROR_STATUS_SHIFT    (16U)
/*! CH0_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH0_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH0_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH0_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH1_ERROR_STATUS_MASK     (0x20000U)
#define APBH_CTRL2_SET_CH1_ERROR_STATUS_SHIFT    (17U)
/*! CH1_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH1_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH1_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH1_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH2_ERROR_STATUS_MASK     (0x40000U)
#define APBH_CTRL2_SET_CH2_ERROR_STATUS_SHIFT    (18U)
/*! CH2_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH2_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH2_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH2_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH3_ERROR_STATUS_MASK     (0x80000U)
#define APBH_CTRL2_SET_CH3_ERROR_STATUS_SHIFT    (19U)
/*! CH3_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH3_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH3_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH3_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH4_ERROR_STATUS_MASK     (0x100000U)
#define APBH_CTRL2_SET_CH4_ERROR_STATUS_SHIFT    (20U)
/*! CH4_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH4_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH4_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH4_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH5_ERROR_STATUS_MASK     (0x200000U)
#define APBH_CTRL2_SET_CH5_ERROR_STATUS_SHIFT    (21U)
/*! CH5_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH5_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH5_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH5_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH6_ERROR_STATUS_MASK     (0x400000U)
#define APBH_CTRL2_SET_CH6_ERROR_STATUS_SHIFT    (22U)
/*! CH6_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH6_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH6_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH6_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH7_ERROR_STATUS_MASK     (0x800000U)
#define APBH_CTRL2_SET_CH7_ERROR_STATUS_SHIFT    (23U)
/*! CH7_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH7_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH7_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH7_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH8_ERROR_STATUS_MASK     (0x1000000U)
#define APBH_CTRL2_SET_CH8_ERROR_STATUS_SHIFT    (24U)
/*! CH8_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH8_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH8_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH8_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH9_ERROR_STATUS_MASK     (0x2000000U)
#define APBH_CTRL2_SET_CH9_ERROR_STATUS_SHIFT    (25U)
/*! CH9_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH9_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH9_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH9_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH10_ERROR_STATUS_MASK    (0x4000000U)
#define APBH_CTRL2_SET_CH10_ERROR_STATUS_SHIFT   (26U)
/*! CH10_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH10_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH10_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH10_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH11_ERROR_STATUS_MASK    (0x8000000U)
#define APBH_CTRL2_SET_CH11_ERROR_STATUS_SHIFT   (27U)
/*! CH11_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH11_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH11_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH11_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH12_ERROR_STATUS_MASK    (0x10000000U)
#define APBH_CTRL2_SET_CH12_ERROR_STATUS_SHIFT   (28U)
/*! CH12_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH12_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH12_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH12_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH13_ERROR_STATUS_MASK    (0x20000000U)
#define APBH_CTRL2_SET_CH13_ERROR_STATUS_SHIFT   (29U)
/*! CH13_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH13_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH13_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH13_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH14_ERROR_STATUS_MASK    (0x40000000U)
#define APBH_CTRL2_SET_CH14_ERROR_STATUS_SHIFT   (30U)
/*! CH14_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH14_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH14_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH14_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH15_ERROR_STATUS_MASK    (0x80000000U)
#define APBH_CTRL2_SET_CH15_ERROR_STATUS_SHIFT   (31U)
/*! CH15_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH15_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH15_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH15_ERROR_STATUS_MASK)
/*! @} */

/*! @name CTRL2_CLR - AHB to APBH Bridge Control and Status Register 2 */
/*! @{ */

#define APBH_CTRL2_CLR_CH0_ERROR_IRQ_MASK        (0x1U)
#define APBH_CTRL2_CLR_CH0_ERROR_IRQ_SHIFT       (0U)
#define APBH_CTRL2_CLR_CH0_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH0_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH0_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH1_ERROR_IRQ_MASK        (0x2U)
#define APBH_CTRL2_CLR_CH1_ERROR_IRQ_SHIFT       (1U)
#define APBH_CTRL2_CLR_CH1_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH1_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH1_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH2_ERROR_IRQ_MASK        (0x4U)
#define APBH_CTRL2_CLR_CH2_ERROR_IRQ_SHIFT       (2U)
#define APBH_CTRL2_CLR_CH2_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH2_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH2_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH3_ERROR_IRQ_MASK        (0x8U)
#define APBH_CTRL2_CLR_CH3_ERROR_IRQ_SHIFT       (3U)
#define APBH_CTRL2_CLR_CH3_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH3_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH3_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH4_ERROR_IRQ_MASK        (0x10U)
#define APBH_CTRL2_CLR_CH4_ERROR_IRQ_SHIFT       (4U)
#define APBH_CTRL2_CLR_CH4_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH4_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH4_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH5_ERROR_IRQ_MASK        (0x20U)
#define APBH_CTRL2_CLR_CH5_ERROR_IRQ_SHIFT       (5U)
#define APBH_CTRL2_CLR_CH5_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH5_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH5_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH6_ERROR_IRQ_MASK        (0x40U)
#define APBH_CTRL2_CLR_CH6_ERROR_IRQ_SHIFT       (6U)
#define APBH_CTRL2_CLR_CH6_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH6_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH6_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH7_ERROR_IRQ_MASK        (0x80U)
#define APBH_CTRL2_CLR_CH7_ERROR_IRQ_SHIFT       (7U)
#define APBH_CTRL2_CLR_CH7_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH7_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH7_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH8_ERROR_IRQ_MASK        (0x100U)
#define APBH_CTRL2_CLR_CH8_ERROR_IRQ_SHIFT       (8U)
#define APBH_CTRL2_CLR_CH8_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH8_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH8_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH9_ERROR_IRQ_MASK        (0x200U)
#define APBH_CTRL2_CLR_CH9_ERROR_IRQ_SHIFT       (9U)
#define APBH_CTRL2_CLR_CH9_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH9_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH9_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH10_ERROR_IRQ_MASK       (0x400U)
#define APBH_CTRL2_CLR_CH10_ERROR_IRQ_SHIFT      (10U)
#define APBH_CTRL2_CLR_CH10_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH10_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH10_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH11_ERROR_IRQ_MASK       (0x800U)
#define APBH_CTRL2_CLR_CH11_ERROR_IRQ_SHIFT      (11U)
#define APBH_CTRL2_CLR_CH11_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH11_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH11_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH12_ERROR_IRQ_MASK       (0x1000U)
#define APBH_CTRL2_CLR_CH12_ERROR_IRQ_SHIFT      (12U)
#define APBH_CTRL2_CLR_CH12_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH12_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH12_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH13_ERROR_IRQ_MASK       (0x2000U)
#define APBH_CTRL2_CLR_CH13_ERROR_IRQ_SHIFT      (13U)
#define APBH_CTRL2_CLR_CH13_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH13_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH13_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH14_ERROR_IRQ_MASK       (0x4000U)
#define APBH_CTRL2_CLR_CH14_ERROR_IRQ_SHIFT      (14U)
#define APBH_CTRL2_CLR_CH14_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH14_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH14_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH15_ERROR_IRQ_MASK       (0x8000U)
#define APBH_CTRL2_CLR_CH15_ERROR_IRQ_SHIFT      (15U)
#define APBH_CTRL2_CLR_CH15_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH15_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH15_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH0_ERROR_STATUS_MASK     (0x10000U)
#define APBH_CTRL2_CLR_CH0_ERROR_STATUS_SHIFT    (16U)
/*! CH0_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH0_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH0_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH0_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH1_ERROR_STATUS_MASK     (0x20000U)
#define APBH_CTRL2_CLR_CH1_ERROR_STATUS_SHIFT    (17U)
/*! CH1_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH1_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH1_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH1_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH2_ERROR_STATUS_MASK     (0x40000U)
#define APBH_CTRL2_CLR_CH2_ERROR_STATUS_SHIFT    (18U)
/*! CH2_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH2_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH2_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH2_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH3_ERROR_STATUS_MASK     (0x80000U)
#define APBH_CTRL2_CLR_CH3_ERROR_STATUS_SHIFT    (19U)
/*! CH3_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH3_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH3_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH3_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH4_ERROR_STATUS_MASK     (0x100000U)
#define APBH_CTRL2_CLR_CH4_ERROR_STATUS_SHIFT    (20U)
/*! CH4_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH4_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH4_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH4_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH5_ERROR_STATUS_MASK     (0x200000U)
#define APBH_CTRL2_CLR_CH5_ERROR_STATUS_SHIFT    (21U)
/*! CH5_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH5_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH5_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH5_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH6_ERROR_STATUS_MASK     (0x400000U)
#define APBH_CTRL2_CLR_CH6_ERROR_STATUS_SHIFT    (22U)
/*! CH6_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH6_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH6_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH6_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH7_ERROR_STATUS_MASK     (0x800000U)
#define APBH_CTRL2_CLR_CH7_ERROR_STATUS_SHIFT    (23U)
/*! CH7_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH7_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH7_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH7_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH8_ERROR_STATUS_MASK     (0x1000000U)
#define APBH_CTRL2_CLR_CH8_ERROR_STATUS_SHIFT    (24U)
/*! CH8_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH8_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH8_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH8_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH9_ERROR_STATUS_MASK     (0x2000000U)
#define APBH_CTRL2_CLR_CH9_ERROR_STATUS_SHIFT    (25U)
/*! CH9_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH9_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH9_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH9_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH10_ERROR_STATUS_MASK    (0x4000000U)
#define APBH_CTRL2_CLR_CH10_ERROR_STATUS_SHIFT   (26U)
/*! CH10_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH10_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH10_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH10_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH11_ERROR_STATUS_MASK    (0x8000000U)
#define APBH_CTRL2_CLR_CH11_ERROR_STATUS_SHIFT   (27U)
/*! CH11_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH11_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH11_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH11_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH12_ERROR_STATUS_MASK    (0x10000000U)
#define APBH_CTRL2_CLR_CH12_ERROR_STATUS_SHIFT   (28U)
/*! CH12_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH12_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH12_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH12_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH13_ERROR_STATUS_MASK    (0x20000000U)
#define APBH_CTRL2_CLR_CH13_ERROR_STATUS_SHIFT   (29U)
/*! CH13_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH13_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH13_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH13_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH14_ERROR_STATUS_MASK    (0x40000000U)
#define APBH_CTRL2_CLR_CH14_ERROR_STATUS_SHIFT   (30U)
/*! CH14_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH14_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH14_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH14_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH15_ERROR_STATUS_MASK    (0x80000000U)
#define APBH_CTRL2_CLR_CH15_ERROR_STATUS_SHIFT   (31U)
/*! CH15_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH15_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH15_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH15_ERROR_STATUS_MASK)
/*! @} */

/*! @name CTRL2_TOG - AHB to APBH Bridge Control and Status Register 2 */
/*! @{ */

#define APBH_CTRL2_TOG_CH0_ERROR_IRQ_MASK        (0x1U)
#define APBH_CTRL2_TOG_CH0_ERROR_IRQ_SHIFT       (0U)
#define APBH_CTRL2_TOG_CH0_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH0_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH0_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH1_ERROR_IRQ_MASK        (0x2U)
#define APBH_CTRL2_TOG_CH1_ERROR_IRQ_SHIFT       (1U)
#define APBH_CTRL2_TOG_CH1_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH1_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH1_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH2_ERROR_IRQ_MASK        (0x4U)
#define APBH_CTRL2_TOG_CH2_ERROR_IRQ_SHIFT       (2U)
#define APBH_CTRL2_TOG_CH2_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH2_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH2_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH3_ERROR_IRQ_MASK        (0x8U)
#define APBH_CTRL2_TOG_CH3_ERROR_IRQ_SHIFT       (3U)
#define APBH_CTRL2_TOG_CH3_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH3_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH3_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH4_ERROR_IRQ_MASK        (0x10U)
#define APBH_CTRL2_TOG_CH4_ERROR_IRQ_SHIFT       (4U)
#define APBH_CTRL2_TOG_CH4_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH4_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH4_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH5_ERROR_IRQ_MASK        (0x20U)
#define APBH_CTRL2_TOG_CH5_ERROR_IRQ_SHIFT       (5U)
#define APBH_CTRL2_TOG_CH5_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH5_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH5_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH6_ERROR_IRQ_MASK        (0x40U)
#define APBH_CTRL2_TOG_CH6_ERROR_IRQ_SHIFT       (6U)
#define APBH_CTRL2_TOG_CH6_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH6_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH6_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH7_ERROR_IRQ_MASK        (0x80U)
#define APBH_CTRL2_TOG_CH7_ERROR_IRQ_SHIFT       (7U)
#define APBH_CTRL2_TOG_CH7_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH7_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH7_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH8_ERROR_IRQ_MASK        (0x100U)
#define APBH_CTRL2_TOG_CH8_ERROR_IRQ_SHIFT       (8U)
#define APBH_CTRL2_TOG_CH8_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH8_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH8_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH9_ERROR_IRQ_MASK        (0x200U)
#define APBH_CTRL2_TOG_CH9_ERROR_IRQ_SHIFT       (9U)
#define APBH_CTRL2_TOG_CH9_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH9_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH9_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH10_ERROR_IRQ_MASK       (0x400U)
#define APBH_CTRL2_TOG_CH10_ERROR_IRQ_SHIFT      (10U)
#define APBH_CTRL2_TOG_CH10_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH10_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH10_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH11_ERROR_IRQ_MASK       (0x800U)
#define APBH_CTRL2_TOG_CH11_ERROR_IRQ_SHIFT      (11U)
#define APBH_CTRL2_TOG_CH11_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH11_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH11_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH12_ERROR_IRQ_MASK       (0x1000U)
#define APBH_CTRL2_TOG_CH12_ERROR_IRQ_SHIFT      (12U)
#define APBH_CTRL2_TOG_CH12_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH12_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH12_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH13_ERROR_IRQ_MASK       (0x2000U)
#define APBH_CTRL2_TOG_CH13_ERROR_IRQ_SHIFT      (13U)
#define APBH_CTRL2_TOG_CH13_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH13_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH13_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH14_ERROR_IRQ_MASK       (0x4000U)
#define APBH_CTRL2_TOG_CH14_ERROR_IRQ_SHIFT      (14U)
#define APBH_CTRL2_TOG_CH14_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH14_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH14_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH15_ERROR_IRQ_MASK       (0x8000U)
#define APBH_CTRL2_TOG_CH15_ERROR_IRQ_SHIFT      (15U)
#define APBH_CTRL2_TOG_CH15_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH15_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH15_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH0_ERROR_STATUS_MASK     (0x10000U)
#define APBH_CTRL2_TOG_CH0_ERROR_STATUS_SHIFT    (16U)
/*! CH0_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH0_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH0_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH0_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH1_ERROR_STATUS_MASK     (0x20000U)
#define APBH_CTRL2_TOG_CH1_ERROR_STATUS_SHIFT    (17U)
/*! CH1_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH1_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH1_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH1_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH2_ERROR_STATUS_MASK     (0x40000U)
#define APBH_CTRL2_TOG_CH2_ERROR_STATUS_SHIFT    (18U)
/*! CH2_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH2_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH2_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH2_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH3_ERROR_STATUS_MASK     (0x80000U)
#define APBH_CTRL2_TOG_CH3_ERROR_STATUS_SHIFT    (19U)
/*! CH3_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH3_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH3_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH3_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH4_ERROR_STATUS_MASK     (0x100000U)
#define APBH_CTRL2_TOG_CH4_ERROR_STATUS_SHIFT    (20U)
/*! CH4_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH4_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH4_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH4_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH5_ERROR_STATUS_MASK     (0x200000U)
#define APBH_CTRL2_TOG_CH5_ERROR_STATUS_SHIFT    (21U)
/*! CH5_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH5_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH5_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH5_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH6_ERROR_STATUS_MASK     (0x400000U)
#define APBH_CTRL2_TOG_CH6_ERROR_STATUS_SHIFT    (22U)
/*! CH6_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH6_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH6_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH6_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH7_ERROR_STATUS_MASK     (0x800000U)
#define APBH_CTRL2_TOG_CH7_ERROR_STATUS_SHIFT    (23U)
/*! CH7_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH7_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH7_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH7_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH8_ERROR_STATUS_MASK     (0x1000000U)
#define APBH_CTRL2_TOG_CH8_ERROR_STATUS_SHIFT    (24U)
/*! CH8_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH8_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH8_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH8_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH9_ERROR_STATUS_MASK     (0x2000000U)
#define APBH_CTRL2_TOG_CH9_ERROR_STATUS_SHIFT    (25U)
/*! CH9_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH9_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH9_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH9_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH10_ERROR_STATUS_MASK    (0x4000000U)
#define APBH_CTRL2_TOG_CH10_ERROR_STATUS_SHIFT   (26U)
/*! CH10_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH10_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH10_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH10_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH11_ERROR_STATUS_MASK    (0x8000000U)
#define APBH_CTRL2_TOG_CH11_ERROR_STATUS_SHIFT   (27U)
/*! CH11_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH11_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH11_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH11_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH12_ERROR_STATUS_MASK    (0x10000000U)
#define APBH_CTRL2_TOG_CH12_ERROR_STATUS_SHIFT   (28U)
/*! CH12_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH12_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH12_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH12_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH13_ERROR_STATUS_MASK    (0x20000000U)
#define APBH_CTRL2_TOG_CH13_ERROR_STATUS_SHIFT   (29U)
/*! CH13_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH13_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH13_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH13_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH14_ERROR_STATUS_MASK    (0x40000000U)
#define APBH_CTRL2_TOG_CH14_ERROR_STATUS_SHIFT   (30U)
/*! CH14_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH14_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH14_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH14_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH15_ERROR_STATUS_MASK    (0x80000000U)
#define APBH_CTRL2_TOG_CH15_ERROR_STATUS_SHIFT   (31U)
/*! CH15_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH15_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH15_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH15_ERROR_STATUS_MASK)
/*! @} */

/*! @name CHANNEL_CTRL - AHB to APBH Bridge Channel Register */
/*! @{ */

#define APBH_CHANNEL_CTRL_FREEZE_CHANNEL_MASK    (0xFFFFU)
#define APBH_CHANNEL_CTRL_FREEZE_CHANNEL_SHIFT   (0U)
/*! FREEZE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_FREEZE_CHANNEL(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_FREEZE_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_FREEZE_CHANNEL_MASK)

#define APBH_CHANNEL_CTRL_RESET_CHANNEL_MASK     (0xFFFF0000U)
#define APBH_CHANNEL_CTRL_RESET_CHANNEL_SHIFT    (16U)
/*! RESET_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_RESET_CHANNEL(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_RESET_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_RESET_CHANNEL_MASK)
/*! @} */

/*! @name CHANNEL_CTRL_SET - AHB to APBH Bridge Channel Register */
/*! @{ */

#define APBH_CHANNEL_CTRL_SET_FREEZE_CHANNEL_MASK (0xFFFFU)
#define APBH_CHANNEL_CTRL_SET_FREEZE_CHANNEL_SHIFT (0U)
/*! FREEZE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_SET_FREEZE_CHANNEL(x)  (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_SET_FREEZE_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_SET_FREEZE_CHANNEL_MASK)

#define APBH_CHANNEL_CTRL_SET_RESET_CHANNEL_MASK (0xFFFF0000U)
#define APBH_CHANNEL_CTRL_SET_RESET_CHANNEL_SHIFT (16U)
/*! RESET_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_SET_RESET_CHANNEL(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_SET_RESET_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_SET_RESET_CHANNEL_MASK)
/*! @} */

/*! @name CHANNEL_CTRL_CLR - AHB to APBH Bridge Channel Register */
/*! @{ */

#define APBH_CHANNEL_CTRL_CLR_FREEZE_CHANNEL_MASK (0xFFFFU)
#define APBH_CHANNEL_CTRL_CLR_FREEZE_CHANNEL_SHIFT (0U)
/*! FREEZE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_CLR_FREEZE_CHANNEL(x)  (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_CLR_FREEZE_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_CLR_FREEZE_CHANNEL_MASK)

#define APBH_CHANNEL_CTRL_CLR_RESET_CHANNEL_MASK (0xFFFF0000U)
#define APBH_CHANNEL_CTRL_CLR_RESET_CHANNEL_SHIFT (16U)
/*! RESET_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_CLR_RESET_CHANNEL(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_CLR_RESET_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_CLR_RESET_CHANNEL_MASK)
/*! @} */

/*! @name CHANNEL_CTRL_TOG - AHB to APBH Bridge Channel Register */
/*! @{ */

#define APBH_CHANNEL_CTRL_TOG_FREEZE_CHANNEL_MASK (0xFFFFU)
#define APBH_CHANNEL_CTRL_TOG_FREEZE_CHANNEL_SHIFT (0U)
/*! FREEZE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_TOG_FREEZE_CHANNEL(x)  (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_TOG_FREEZE_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_TOG_FREEZE_CHANNEL_MASK)

#define APBH_CHANNEL_CTRL_TOG_RESET_CHANNEL_MASK (0xFFFF0000U)
#define APBH_CHANNEL_CTRL_TOG_RESET_CHANNEL_SHIFT (16U)
/*! RESET_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_TOG_RESET_CHANNEL(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_TOG_RESET_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_TOG_RESET_CHANNEL_MASK)
/*! @} */

/*! @name DEVSEL - AHB to APBH DMA Device Assignment Register */
/*! @{ */

#define APBH_DEVSEL_CH0_MASK                     (0x3U)
#define APBH_DEVSEL_CH0_SHIFT                    (0U)
#define APBH_DEVSEL_CH0(x)                       (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH0_SHIFT)) & APBH_DEVSEL_CH0_MASK)

#define APBH_DEVSEL_CH1_MASK                     (0xCU)
#define APBH_DEVSEL_CH1_SHIFT                    (2U)
#define APBH_DEVSEL_CH1(x)                       (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH1_SHIFT)) & APBH_DEVSEL_CH1_MASK)

#define APBH_DEVSEL_CH2_MASK                     (0x30U)
#define APBH_DEVSEL_CH2_SHIFT                    (4U)
#define APBH_DEVSEL_CH2(x)                       (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH2_SHIFT)) & APBH_DEVSEL_CH2_MASK)

#define APBH_DEVSEL_CH3_MASK                     (0xC0U)
#define APBH_DEVSEL_CH3_SHIFT                    (6U)
#define APBH_DEVSEL_CH3(x)                       (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH3_SHIFT)) & APBH_DEVSEL_CH3_MASK)

#define APBH_DEVSEL_CH4_MASK                     (0x300U)
#define APBH_DEVSEL_CH4_SHIFT                    (8U)
#define APBH_DEVSEL_CH4(x)                       (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH4_SHIFT)) & APBH_DEVSEL_CH4_MASK)

#define APBH_DEVSEL_CH5_MASK                     (0xC00U)
#define APBH_DEVSEL_CH5_SHIFT                    (10U)
#define APBH_DEVSEL_CH5(x)                       (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH5_SHIFT)) & APBH_DEVSEL_CH5_MASK)

#define APBH_DEVSEL_CH6_MASK                     (0x3000U)
#define APBH_DEVSEL_CH6_SHIFT                    (12U)
#define APBH_DEVSEL_CH6(x)                       (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH6_SHIFT)) & APBH_DEVSEL_CH6_MASK)

#define APBH_DEVSEL_CH7_MASK                     (0xC000U)
#define APBH_DEVSEL_CH7_SHIFT                    (14U)
#define APBH_DEVSEL_CH7(x)                       (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH7_SHIFT)) & APBH_DEVSEL_CH7_MASK)

#define APBH_DEVSEL_CH8_MASK                     (0x30000U)
#define APBH_DEVSEL_CH8_SHIFT                    (16U)
#define APBH_DEVSEL_CH8(x)                       (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH8_SHIFT)) & APBH_DEVSEL_CH8_MASK)

#define APBH_DEVSEL_CH9_MASK                     (0xC0000U)
#define APBH_DEVSEL_CH9_SHIFT                    (18U)
#define APBH_DEVSEL_CH9(x)                       (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH9_SHIFT)) & APBH_DEVSEL_CH9_MASK)

#define APBH_DEVSEL_CH10_MASK                    (0x300000U)
#define APBH_DEVSEL_CH10_SHIFT                   (20U)
#define APBH_DEVSEL_CH10(x)                      (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH10_SHIFT)) & APBH_DEVSEL_CH10_MASK)

#define APBH_DEVSEL_CH11_MASK                    (0xC00000U)
#define APBH_DEVSEL_CH11_SHIFT                   (22U)
#define APBH_DEVSEL_CH11(x)                      (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH11_SHIFT)) & APBH_DEVSEL_CH11_MASK)

#define APBH_DEVSEL_CH12_MASK                    (0x3000000U)
#define APBH_DEVSEL_CH12_SHIFT                   (24U)
#define APBH_DEVSEL_CH12(x)                      (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH12_SHIFT)) & APBH_DEVSEL_CH12_MASK)

#define APBH_DEVSEL_CH13_MASK                    (0xC000000U)
#define APBH_DEVSEL_CH13_SHIFT                   (26U)
#define APBH_DEVSEL_CH13(x)                      (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH13_SHIFT)) & APBH_DEVSEL_CH13_MASK)

#define APBH_DEVSEL_CH14_MASK                    (0x30000000U)
#define APBH_DEVSEL_CH14_SHIFT                   (28U)
#define APBH_DEVSEL_CH14(x)                      (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH14_SHIFT)) & APBH_DEVSEL_CH14_MASK)

#define APBH_DEVSEL_CH15_MASK                    (0xC0000000U)
#define APBH_DEVSEL_CH15_SHIFT                   (30U)
#define APBH_DEVSEL_CH15(x)                      (((uint32_t)(((uint32_t)(x)) << APBH_DEVSEL_CH15_SHIFT)) & APBH_DEVSEL_CH15_MASK)
/*! @} */

/*! @name DMA_BURST_SIZE - AHB to APBH DMA burst size */
/*! @{ */

#define APBH_DMA_BURST_SIZE_CH0_MASK             (0x3U)
#define APBH_DMA_BURST_SIZE_CH0_SHIFT            (0U)
#define APBH_DMA_BURST_SIZE_CH0(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH0_SHIFT)) & APBH_DMA_BURST_SIZE_CH0_MASK)

#define APBH_DMA_BURST_SIZE_CH1_MASK             (0xCU)
#define APBH_DMA_BURST_SIZE_CH1_SHIFT            (2U)
#define APBH_DMA_BURST_SIZE_CH1(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH1_SHIFT)) & APBH_DMA_BURST_SIZE_CH1_MASK)

#define APBH_DMA_BURST_SIZE_CH2_MASK             (0x30U)
#define APBH_DMA_BURST_SIZE_CH2_SHIFT            (4U)
#define APBH_DMA_BURST_SIZE_CH2(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH2_SHIFT)) & APBH_DMA_BURST_SIZE_CH2_MASK)

#define APBH_DMA_BURST_SIZE_CH3_MASK             (0xC0U)
#define APBH_DMA_BURST_SIZE_CH3_SHIFT            (6U)
#define APBH_DMA_BURST_SIZE_CH3(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH3_SHIFT)) & APBH_DMA_BURST_SIZE_CH3_MASK)

#define APBH_DMA_BURST_SIZE_CH4_MASK             (0x300U)
#define APBH_DMA_BURST_SIZE_CH4_SHIFT            (8U)
#define APBH_DMA_BURST_SIZE_CH4(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH4_SHIFT)) & APBH_DMA_BURST_SIZE_CH4_MASK)

#define APBH_DMA_BURST_SIZE_CH5_MASK             (0xC00U)
#define APBH_DMA_BURST_SIZE_CH5_SHIFT            (10U)
#define APBH_DMA_BURST_SIZE_CH5(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH5_SHIFT)) & APBH_DMA_BURST_SIZE_CH5_MASK)

#define APBH_DMA_BURST_SIZE_CH6_MASK             (0x3000U)
#define APBH_DMA_BURST_SIZE_CH6_SHIFT            (12U)
#define APBH_DMA_BURST_SIZE_CH6(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH6_SHIFT)) & APBH_DMA_BURST_SIZE_CH6_MASK)

#define APBH_DMA_BURST_SIZE_CH7_MASK             (0xC000U)
#define APBH_DMA_BURST_SIZE_CH7_SHIFT            (14U)
#define APBH_DMA_BURST_SIZE_CH7(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH7_SHIFT)) & APBH_DMA_BURST_SIZE_CH7_MASK)

#define APBH_DMA_BURST_SIZE_CH8_MASK             (0x30000U)
#define APBH_DMA_BURST_SIZE_CH8_SHIFT            (16U)
/*! CH8
 *  0b00..BURST0
 *  0b01..BURST4
 *  0b10..BURST8
 */
#define APBH_DMA_BURST_SIZE_CH8(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH8_SHIFT)) & APBH_DMA_BURST_SIZE_CH8_MASK)

#define APBH_DMA_BURST_SIZE_CH9_MASK             (0xC0000U)
#define APBH_DMA_BURST_SIZE_CH9_SHIFT            (18U)
#define APBH_DMA_BURST_SIZE_CH9(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH9_SHIFT)) & APBH_DMA_BURST_SIZE_CH9_MASK)

#define APBH_DMA_BURST_SIZE_CH10_MASK            (0x300000U)
#define APBH_DMA_BURST_SIZE_CH10_SHIFT           (20U)
#define APBH_DMA_BURST_SIZE_CH10(x)              (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH10_SHIFT)) & APBH_DMA_BURST_SIZE_CH10_MASK)

#define APBH_DMA_BURST_SIZE_CH11_MASK            (0xC00000U)
#define APBH_DMA_BURST_SIZE_CH11_SHIFT           (22U)
#define APBH_DMA_BURST_SIZE_CH11(x)              (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH11_SHIFT)) & APBH_DMA_BURST_SIZE_CH11_MASK)

#define APBH_DMA_BURST_SIZE_CH12_MASK            (0x3000000U)
#define APBH_DMA_BURST_SIZE_CH12_SHIFT           (24U)
#define APBH_DMA_BURST_SIZE_CH12(x)              (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH12_SHIFT)) & APBH_DMA_BURST_SIZE_CH12_MASK)

#define APBH_DMA_BURST_SIZE_CH13_MASK            (0xC000000U)
#define APBH_DMA_BURST_SIZE_CH13_SHIFT           (26U)
#define APBH_DMA_BURST_SIZE_CH13(x)              (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH13_SHIFT)) & APBH_DMA_BURST_SIZE_CH13_MASK)

#define APBH_DMA_BURST_SIZE_CH14_MASK            (0x30000000U)
#define APBH_DMA_BURST_SIZE_CH14_SHIFT           (28U)
#define APBH_DMA_BURST_SIZE_CH14(x)              (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH14_SHIFT)) & APBH_DMA_BURST_SIZE_CH14_MASK)

#define APBH_DMA_BURST_SIZE_CH15_MASK            (0xC0000000U)
#define APBH_DMA_BURST_SIZE_CH15_SHIFT           (30U)
#define APBH_DMA_BURST_SIZE_CH15(x)              (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH15_SHIFT)) & APBH_DMA_BURST_SIZE_CH15_MASK)
/*! @} */

/*! @name DEBUG - AHB to APBH DMA Debug Register */
/*! @{ */

#define APBH_DEBUG_GPMI_ONE_FIFO_MASK            (0x1U)
#define APBH_DEBUG_GPMI_ONE_FIFO_SHIFT           (0U)
#define APBH_DEBUG_GPMI_ONE_FIFO(x)              (((uint32_t)(((uint32_t)(x)) << APBH_DEBUG_GPMI_ONE_FIFO_SHIFT)) & APBH_DEBUG_GPMI_ONE_FIFO_MASK)
/*! @} */

/*! @name CH0_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH0_CURCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH0_CURCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH0_CURCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH0_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH0_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH0_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH0_NXTCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH0_NXTCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH0_NXTCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH0_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH0_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH0_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH0_CMD_COMMAND_MASK                (0x3U)
#define APBH_CH0_CMD_COMMAND_SHIFT               (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH0_CMD_COMMAND(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH0_CMD_COMMAND_SHIFT)) & APBH_CH0_CMD_COMMAND_MASK)

#define APBH_CH0_CMD_CHAIN_MASK                  (0x4U)
#define APBH_CH0_CMD_CHAIN_SHIFT                 (2U)
#define APBH_CH0_CMD_CHAIN(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CH0_CMD_CHAIN_SHIFT)) & APBH_CH0_CMD_CHAIN_MASK)

#define APBH_CH0_CMD_IRQONCMPLT_MASK             (0x8U)
#define APBH_CH0_CMD_IRQONCMPLT_SHIFT            (3U)
#define APBH_CH0_CMD_IRQONCMPLT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH0_CMD_IRQONCMPLT_SHIFT)) & APBH_CH0_CMD_IRQONCMPLT_MASK)

#define APBH_CH0_CMD_NANDLOCK_MASK               (0x10U)
#define APBH_CH0_CMD_NANDLOCK_SHIFT              (4U)
#define APBH_CH0_CMD_NANDLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH0_CMD_NANDLOCK_SHIFT)) & APBH_CH0_CMD_NANDLOCK_MASK)

#define APBH_CH0_CMD_NANDWAIT4READY_MASK         (0x20U)
#define APBH_CH0_CMD_NANDWAIT4READY_SHIFT        (5U)
#define APBH_CH0_CMD_NANDWAIT4READY(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH0_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH0_CMD_NANDWAIT4READY_MASK)

#define APBH_CH0_CMD_SEMAPHORE_MASK              (0x40U)
#define APBH_CH0_CMD_SEMAPHORE_SHIFT             (6U)
#define APBH_CH0_CMD_SEMAPHORE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH0_CMD_SEMAPHORE_SHIFT)) & APBH_CH0_CMD_SEMAPHORE_MASK)

#define APBH_CH0_CMD_WAIT4ENDCMD_MASK            (0x80U)
#define APBH_CH0_CMD_WAIT4ENDCMD_SHIFT           (7U)
#define APBH_CH0_CMD_WAIT4ENDCMD(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH0_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH0_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH0_CMD_HALTONTERMINATE_MASK        (0x100U)
#define APBH_CH0_CMD_HALTONTERMINATE_SHIFT       (8U)
#define APBH_CH0_CMD_HALTONTERMINATE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH0_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH0_CMD_HALTONTERMINATE_MASK)

#define APBH_CH0_CMD_CMDWORDS_MASK               (0xF000U)
#define APBH_CH0_CMD_CMDWORDS_SHIFT              (12U)
#define APBH_CH0_CMD_CMDWORDS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH0_CMD_CMDWORDS_SHIFT)) & APBH_CH0_CMD_CMDWORDS_MASK)

#define APBH_CH0_CMD_XFER_COUNT_MASK             (0xFFFF0000U)
#define APBH_CH0_CMD_XFER_COUNT_SHIFT            (16U)
#define APBH_CH0_CMD_XFER_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH0_CMD_XFER_COUNT_SHIFT)) & APBH_CH0_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH0_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH0_BAR_ADDRESS_MASK                (0xFFFFFFFFU)
#define APBH_CH0_BAR_ADDRESS_SHIFT               (0U)
#define APBH_CH0_BAR_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH0_BAR_ADDRESS_SHIFT)) & APBH_CH0_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH0_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH0_SEMA_INCREMENT_SEMA_MASK        (0xFFU)
#define APBH_CH0_SEMA_INCREMENT_SEMA_SHIFT       (0U)
#define APBH_CH0_SEMA_INCREMENT_SEMA(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH0_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH0_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH0_SEMA_PHORE_MASK                 (0xFF0000U)
#define APBH_CH0_SEMA_PHORE_SHIFT                (16U)
#define APBH_CH0_SEMA_PHORE(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH0_SEMA_PHORE_SHIFT)) & APBH_CH0_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH0_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH0_DEBUG1_STATEMACHINE_MASK        (0x1FU)
#define APBH_CH0_DEBUG1_STATEMACHINE_SHIFT       (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH0_DEBUG1_STATEMACHINE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH0_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH0_DEBUG1_RSVD1_MASK               (0xFFFE0U)
#define APBH_CH0_DEBUG1_RSVD1_SHIFT              (5U)
#define APBH_CH0_DEBUG1_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG1_RSVD1_SHIFT)) & APBH_CH0_DEBUG1_RSVD1_MASK)

#define APBH_CH0_DEBUG1_WR_FIFO_FULL_MASK        (0x100000U)
#define APBH_CH0_DEBUG1_WR_FIFO_FULL_SHIFT       (20U)
#define APBH_CH0_DEBUG1_WR_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH0_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH0_DEBUG1_WR_FIFO_EMPTY_MASK       (0x200000U)
#define APBH_CH0_DEBUG1_WR_FIFO_EMPTY_SHIFT      (21U)
#define APBH_CH0_DEBUG1_WR_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH0_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH0_DEBUG1_RD_FIFO_FULL_MASK        (0x400000U)
#define APBH_CH0_DEBUG1_RD_FIFO_FULL_SHIFT       (22U)
#define APBH_CH0_DEBUG1_RD_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH0_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH0_DEBUG1_RD_FIFO_EMPTY_MASK       (0x800000U)
#define APBH_CH0_DEBUG1_RD_FIFO_EMPTY_SHIFT      (23U)
#define APBH_CH0_DEBUG1_RD_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH0_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH0_DEBUG1_NEXTCMDADDRVALID_MASK    (0x1000000U)
#define APBH_CH0_DEBUG1_NEXTCMDADDRVALID_SHIFT   (24U)
#define APBH_CH0_DEBUG1_NEXTCMDADDRVALID(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH0_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH0_DEBUG1_LOCK_MASK                (0x2000000U)
#define APBH_CH0_DEBUG1_LOCK_SHIFT               (25U)
#define APBH_CH0_DEBUG1_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG1_LOCK_SHIFT)) & APBH_CH0_DEBUG1_LOCK_MASK)

#define APBH_CH0_DEBUG1_READY_MASK               (0x4000000U)
#define APBH_CH0_DEBUG1_READY_SHIFT              (26U)
#define APBH_CH0_DEBUG1_READY(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG1_READY_SHIFT)) & APBH_CH0_DEBUG1_READY_MASK)

#define APBH_CH0_DEBUG1_SENSE_MASK               (0x8000000U)
#define APBH_CH0_DEBUG1_SENSE_SHIFT              (27U)
#define APBH_CH0_DEBUG1_SENSE(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG1_SENSE_SHIFT)) & APBH_CH0_DEBUG1_SENSE_MASK)

#define APBH_CH0_DEBUG1_END_MASK                 (0x10000000U)
#define APBH_CH0_DEBUG1_END_SHIFT                (28U)
#define APBH_CH0_DEBUG1_END(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG1_END_SHIFT)) & APBH_CH0_DEBUG1_END_MASK)

#define APBH_CH0_DEBUG1_KICK_MASK                (0x20000000U)
#define APBH_CH0_DEBUG1_KICK_SHIFT               (29U)
#define APBH_CH0_DEBUG1_KICK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG1_KICK_SHIFT)) & APBH_CH0_DEBUG1_KICK_MASK)

#define APBH_CH0_DEBUG1_BURST_MASK               (0x40000000U)
#define APBH_CH0_DEBUG1_BURST_SHIFT              (30U)
#define APBH_CH0_DEBUG1_BURST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG1_BURST_SHIFT)) & APBH_CH0_DEBUG1_BURST_MASK)

#define APBH_CH0_DEBUG1_REQ_MASK                 (0x80000000U)
#define APBH_CH0_DEBUG1_REQ_SHIFT                (31U)
#define APBH_CH0_DEBUG1_REQ(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG1_REQ_SHIFT)) & APBH_CH0_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH0_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH0_DEBUG2_AHB_BYTES_MASK           (0xFFFFU)
#define APBH_CH0_DEBUG2_AHB_BYTES_SHIFT          (0U)
#define APBH_CH0_DEBUG2_AHB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH0_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH0_DEBUG2_APB_BYTES_MASK           (0xFFFF0000U)
#define APBH_CH0_DEBUG2_APB_BYTES_SHIFT          (16U)
#define APBH_CH0_DEBUG2_APB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH0_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH0_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH1_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH1_CURCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH1_CURCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH1_CURCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH1_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH1_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH1_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH1_NXTCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH1_NXTCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH1_NXTCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH1_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH1_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH1_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH1_CMD_COMMAND_MASK                (0x3U)
#define APBH_CH1_CMD_COMMAND_SHIFT               (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH1_CMD_COMMAND(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH1_CMD_COMMAND_SHIFT)) & APBH_CH1_CMD_COMMAND_MASK)

#define APBH_CH1_CMD_CHAIN_MASK                  (0x4U)
#define APBH_CH1_CMD_CHAIN_SHIFT                 (2U)
#define APBH_CH1_CMD_CHAIN(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CH1_CMD_CHAIN_SHIFT)) & APBH_CH1_CMD_CHAIN_MASK)

#define APBH_CH1_CMD_IRQONCMPLT_MASK             (0x8U)
#define APBH_CH1_CMD_IRQONCMPLT_SHIFT            (3U)
#define APBH_CH1_CMD_IRQONCMPLT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH1_CMD_IRQONCMPLT_SHIFT)) & APBH_CH1_CMD_IRQONCMPLT_MASK)

#define APBH_CH1_CMD_NANDLOCK_MASK               (0x10U)
#define APBH_CH1_CMD_NANDLOCK_SHIFT              (4U)
#define APBH_CH1_CMD_NANDLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH1_CMD_NANDLOCK_SHIFT)) & APBH_CH1_CMD_NANDLOCK_MASK)

#define APBH_CH1_CMD_NANDWAIT4READY_MASK         (0x20U)
#define APBH_CH1_CMD_NANDWAIT4READY_SHIFT        (5U)
#define APBH_CH1_CMD_NANDWAIT4READY(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH1_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH1_CMD_NANDWAIT4READY_MASK)

#define APBH_CH1_CMD_SEMAPHORE_MASK              (0x40U)
#define APBH_CH1_CMD_SEMAPHORE_SHIFT             (6U)
#define APBH_CH1_CMD_SEMAPHORE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH1_CMD_SEMAPHORE_SHIFT)) & APBH_CH1_CMD_SEMAPHORE_MASK)

#define APBH_CH1_CMD_WAIT4ENDCMD_MASK            (0x80U)
#define APBH_CH1_CMD_WAIT4ENDCMD_SHIFT           (7U)
#define APBH_CH1_CMD_WAIT4ENDCMD(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH1_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH1_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH1_CMD_HALTONTERMINATE_MASK        (0x100U)
#define APBH_CH1_CMD_HALTONTERMINATE_SHIFT       (8U)
#define APBH_CH1_CMD_HALTONTERMINATE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH1_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH1_CMD_HALTONTERMINATE_MASK)

#define APBH_CH1_CMD_CMDWORDS_MASK               (0xF000U)
#define APBH_CH1_CMD_CMDWORDS_SHIFT              (12U)
#define APBH_CH1_CMD_CMDWORDS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH1_CMD_CMDWORDS_SHIFT)) & APBH_CH1_CMD_CMDWORDS_MASK)

#define APBH_CH1_CMD_XFER_COUNT_MASK             (0xFFFF0000U)
#define APBH_CH1_CMD_XFER_COUNT_SHIFT            (16U)
#define APBH_CH1_CMD_XFER_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH1_CMD_XFER_COUNT_SHIFT)) & APBH_CH1_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH1_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH1_BAR_ADDRESS_MASK                (0xFFFFFFFFU)
#define APBH_CH1_BAR_ADDRESS_SHIFT               (0U)
#define APBH_CH1_BAR_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH1_BAR_ADDRESS_SHIFT)) & APBH_CH1_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH1_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH1_SEMA_INCREMENT_SEMA_MASK        (0xFFU)
#define APBH_CH1_SEMA_INCREMENT_SEMA_SHIFT       (0U)
#define APBH_CH1_SEMA_INCREMENT_SEMA(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH1_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH1_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH1_SEMA_PHORE_MASK                 (0xFF0000U)
#define APBH_CH1_SEMA_PHORE_SHIFT                (16U)
#define APBH_CH1_SEMA_PHORE(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH1_SEMA_PHORE_SHIFT)) & APBH_CH1_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH1_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH1_DEBUG1_STATEMACHINE_MASK        (0x1FU)
#define APBH_CH1_DEBUG1_STATEMACHINE_SHIFT       (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH1_DEBUG1_STATEMACHINE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH1_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH1_DEBUG1_RSVD1_MASK               (0xFFFE0U)
#define APBH_CH1_DEBUG1_RSVD1_SHIFT              (5U)
#define APBH_CH1_DEBUG1_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG1_RSVD1_SHIFT)) & APBH_CH1_DEBUG1_RSVD1_MASK)

#define APBH_CH1_DEBUG1_WR_FIFO_FULL_MASK        (0x100000U)
#define APBH_CH1_DEBUG1_WR_FIFO_FULL_SHIFT       (20U)
#define APBH_CH1_DEBUG1_WR_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH1_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH1_DEBUG1_WR_FIFO_EMPTY_MASK       (0x200000U)
#define APBH_CH1_DEBUG1_WR_FIFO_EMPTY_SHIFT      (21U)
#define APBH_CH1_DEBUG1_WR_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH1_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH1_DEBUG1_RD_FIFO_FULL_MASK        (0x400000U)
#define APBH_CH1_DEBUG1_RD_FIFO_FULL_SHIFT       (22U)
#define APBH_CH1_DEBUG1_RD_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH1_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH1_DEBUG1_RD_FIFO_EMPTY_MASK       (0x800000U)
#define APBH_CH1_DEBUG1_RD_FIFO_EMPTY_SHIFT      (23U)
#define APBH_CH1_DEBUG1_RD_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH1_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH1_DEBUG1_NEXTCMDADDRVALID_MASK    (0x1000000U)
#define APBH_CH1_DEBUG1_NEXTCMDADDRVALID_SHIFT   (24U)
#define APBH_CH1_DEBUG1_NEXTCMDADDRVALID(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH1_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH1_DEBUG1_LOCK_MASK                (0x2000000U)
#define APBH_CH1_DEBUG1_LOCK_SHIFT               (25U)
#define APBH_CH1_DEBUG1_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG1_LOCK_SHIFT)) & APBH_CH1_DEBUG1_LOCK_MASK)

#define APBH_CH1_DEBUG1_READY_MASK               (0x4000000U)
#define APBH_CH1_DEBUG1_READY_SHIFT              (26U)
#define APBH_CH1_DEBUG1_READY(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG1_READY_SHIFT)) & APBH_CH1_DEBUG1_READY_MASK)

#define APBH_CH1_DEBUG1_SENSE_MASK               (0x8000000U)
#define APBH_CH1_DEBUG1_SENSE_SHIFT              (27U)
#define APBH_CH1_DEBUG1_SENSE(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG1_SENSE_SHIFT)) & APBH_CH1_DEBUG1_SENSE_MASK)

#define APBH_CH1_DEBUG1_END_MASK                 (0x10000000U)
#define APBH_CH1_DEBUG1_END_SHIFT                (28U)
#define APBH_CH1_DEBUG1_END(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG1_END_SHIFT)) & APBH_CH1_DEBUG1_END_MASK)

#define APBH_CH1_DEBUG1_KICK_MASK                (0x20000000U)
#define APBH_CH1_DEBUG1_KICK_SHIFT               (29U)
#define APBH_CH1_DEBUG1_KICK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG1_KICK_SHIFT)) & APBH_CH1_DEBUG1_KICK_MASK)

#define APBH_CH1_DEBUG1_BURST_MASK               (0x40000000U)
#define APBH_CH1_DEBUG1_BURST_SHIFT              (30U)
#define APBH_CH1_DEBUG1_BURST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG1_BURST_SHIFT)) & APBH_CH1_DEBUG1_BURST_MASK)

#define APBH_CH1_DEBUG1_REQ_MASK                 (0x80000000U)
#define APBH_CH1_DEBUG1_REQ_SHIFT                (31U)
#define APBH_CH1_DEBUG1_REQ(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG1_REQ_SHIFT)) & APBH_CH1_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH1_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH1_DEBUG2_AHB_BYTES_MASK           (0xFFFFU)
#define APBH_CH1_DEBUG2_AHB_BYTES_SHIFT          (0U)
#define APBH_CH1_DEBUG2_AHB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH1_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH1_DEBUG2_APB_BYTES_MASK           (0xFFFF0000U)
#define APBH_CH1_DEBUG2_APB_BYTES_SHIFT          (16U)
#define APBH_CH1_DEBUG2_APB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH1_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH1_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH2_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH2_CURCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH2_CURCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH2_CURCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH2_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH2_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH2_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH2_NXTCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH2_NXTCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH2_NXTCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH2_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH2_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH2_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH2_CMD_COMMAND_MASK                (0x3U)
#define APBH_CH2_CMD_COMMAND_SHIFT               (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH2_CMD_COMMAND(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH2_CMD_COMMAND_SHIFT)) & APBH_CH2_CMD_COMMAND_MASK)

#define APBH_CH2_CMD_CHAIN_MASK                  (0x4U)
#define APBH_CH2_CMD_CHAIN_SHIFT                 (2U)
#define APBH_CH2_CMD_CHAIN(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CH2_CMD_CHAIN_SHIFT)) & APBH_CH2_CMD_CHAIN_MASK)

#define APBH_CH2_CMD_IRQONCMPLT_MASK             (0x8U)
#define APBH_CH2_CMD_IRQONCMPLT_SHIFT            (3U)
#define APBH_CH2_CMD_IRQONCMPLT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH2_CMD_IRQONCMPLT_SHIFT)) & APBH_CH2_CMD_IRQONCMPLT_MASK)

#define APBH_CH2_CMD_NANDLOCK_MASK               (0x10U)
#define APBH_CH2_CMD_NANDLOCK_SHIFT              (4U)
#define APBH_CH2_CMD_NANDLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH2_CMD_NANDLOCK_SHIFT)) & APBH_CH2_CMD_NANDLOCK_MASK)

#define APBH_CH2_CMD_NANDWAIT4READY_MASK         (0x20U)
#define APBH_CH2_CMD_NANDWAIT4READY_SHIFT        (5U)
#define APBH_CH2_CMD_NANDWAIT4READY(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH2_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH2_CMD_NANDWAIT4READY_MASK)

#define APBH_CH2_CMD_SEMAPHORE_MASK              (0x40U)
#define APBH_CH2_CMD_SEMAPHORE_SHIFT             (6U)
#define APBH_CH2_CMD_SEMAPHORE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH2_CMD_SEMAPHORE_SHIFT)) & APBH_CH2_CMD_SEMAPHORE_MASK)

#define APBH_CH2_CMD_WAIT4ENDCMD_MASK            (0x80U)
#define APBH_CH2_CMD_WAIT4ENDCMD_SHIFT           (7U)
#define APBH_CH2_CMD_WAIT4ENDCMD(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH2_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH2_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH2_CMD_HALTONTERMINATE_MASK        (0x100U)
#define APBH_CH2_CMD_HALTONTERMINATE_SHIFT       (8U)
#define APBH_CH2_CMD_HALTONTERMINATE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH2_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH2_CMD_HALTONTERMINATE_MASK)

#define APBH_CH2_CMD_CMDWORDS_MASK               (0xF000U)
#define APBH_CH2_CMD_CMDWORDS_SHIFT              (12U)
#define APBH_CH2_CMD_CMDWORDS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH2_CMD_CMDWORDS_SHIFT)) & APBH_CH2_CMD_CMDWORDS_MASK)

#define APBH_CH2_CMD_XFER_COUNT_MASK             (0xFFFF0000U)
#define APBH_CH2_CMD_XFER_COUNT_SHIFT            (16U)
#define APBH_CH2_CMD_XFER_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH2_CMD_XFER_COUNT_SHIFT)) & APBH_CH2_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH2_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH2_BAR_ADDRESS_MASK                (0xFFFFFFFFU)
#define APBH_CH2_BAR_ADDRESS_SHIFT               (0U)
#define APBH_CH2_BAR_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH2_BAR_ADDRESS_SHIFT)) & APBH_CH2_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH2_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH2_SEMA_INCREMENT_SEMA_MASK        (0xFFU)
#define APBH_CH2_SEMA_INCREMENT_SEMA_SHIFT       (0U)
#define APBH_CH2_SEMA_INCREMENT_SEMA(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH2_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH2_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH2_SEMA_PHORE_MASK                 (0xFF0000U)
#define APBH_CH2_SEMA_PHORE_SHIFT                (16U)
#define APBH_CH2_SEMA_PHORE(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH2_SEMA_PHORE_SHIFT)) & APBH_CH2_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH2_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH2_DEBUG1_STATEMACHINE_MASK        (0x1FU)
#define APBH_CH2_DEBUG1_STATEMACHINE_SHIFT       (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH2_DEBUG1_STATEMACHINE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH2_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH2_DEBUG1_RSVD1_MASK               (0xFFFE0U)
#define APBH_CH2_DEBUG1_RSVD1_SHIFT              (5U)
#define APBH_CH2_DEBUG1_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG1_RSVD1_SHIFT)) & APBH_CH2_DEBUG1_RSVD1_MASK)

#define APBH_CH2_DEBUG1_WR_FIFO_FULL_MASK        (0x100000U)
#define APBH_CH2_DEBUG1_WR_FIFO_FULL_SHIFT       (20U)
#define APBH_CH2_DEBUG1_WR_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH2_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH2_DEBUG1_WR_FIFO_EMPTY_MASK       (0x200000U)
#define APBH_CH2_DEBUG1_WR_FIFO_EMPTY_SHIFT      (21U)
#define APBH_CH2_DEBUG1_WR_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH2_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH2_DEBUG1_RD_FIFO_FULL_MASK        (0x400000U)
#define APBH_CH2_DEBUG1_RD_FIFO_FULL_SHIFT       (22U)
#define APBH_CH2_DEBUG1_RD_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH2_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH2_DEBUG1_RD_FIFO_EMPTY_MASK       (0x800000U)
#define APBH_CH2_DEBUG1_RD_FIFO_EMPTY_SHIFT      (23U)
#define APBH_CH2_DEBUG1_RD_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH2_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH2_DEBUG1_NEXTCMDADDRVALID_MASK    (0x1000000U)
#define APBH_CH2_DEBUG1_NEXTCMDADDRVALID_SHIFT   (24U)
#define APBH_CH2_DEBUG1_NEXTCMDADDRVALID(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH2_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH2_DEBUG1_LOCK_MASK                (0x2000000U)
#define APBH_CH2_DEBUG1_LOCK_SHIFT               (25U)
#define APBH_CH2_DEBUG1_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG1_LOCK_SHIFT)) & APBH_CH2_DEBUG1_LOCK_MASK)

#define APBH_CH2_DEBUG1_READY_MASK               (0x4000000U)
#define APBH_CH2_DEBUG1_READY_SHIFT              (26U)
#define APBH_CH2_DEBUG1_READY(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG1_READY_SHIFT)) & APBH_CH2_DEBUG1_READY_MASK)

#define APBH_CH2_DEBUG1_SENSE_MASK               (0x8000000U)
#define APBH_CH2_DEBUG1_SENSE_SHIFT              (27U)
#define APBH_CH2_DEBUG1_SENSE(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG1_SENSE_SHIFT)) & APBH_CH2_DEBUG1_SENSE_MASK)

#define APBH_CH2_DEBUG1_END_MASK                 (0x10000000U)
#define APBH_CH2_DEBUG1_END_SHIFT                (28U)
#define APBH_CH2_DEBUG1_END(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG1_END_SHIFT)) & APBH_CH2_DEBUG1_END_MASK)

#define APBH_CH2_DEBUG1_KICK_MASK                (0x20000000U)
#define APBH_CH2_DEBUG1_KICK_SHIFT               (29U)
#define APBH_CH2_DEBUG1_KICK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG1_KICK_SHIFT)) & APBH_CH2_DEBUG1_KICK_MASK)

#define APBH_CH2_DEBUG1_BURST_MASK               (0x40000000U)
#define APBH_CH2_DEBUG1_BURST_SHIFT              (30U)
#define APBH_CH2_DEBUG1_BURST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG1_BURST_SHIFT)) & APBH_CH2_DEBUG1_BURST_MASK)

#define APBH_CH2_DEBUG1_REQ_MASK                 (0x80000000U)
#define APBH_CH2_DEBUG1_REQ_SHIFT                (31U)
#define APBH_CH2_DEBUG1_REQ(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG1_REQ_SHIFT)) & APBH_CH2_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH2_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH2_DEBUG2_AHB_BYTES_MASK           (0xFFFFU)
#define APBH_CH2_DEBUG2_AHB_BYTES_SHIFT          (0U)
#define APBH_CH2_DEBUG2_AHB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH2_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH2_DEBUG2_APB_BYTES_MASK           (0xFFFF0000U)
#define APBH_CH2_DEBUG2_APB_BYTES_SHIFT          (16U)
#define APBH_CH2_DEBUG2_APB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH2_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH2_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH3_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH3_CURCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH3_CURCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH3_CURCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH3_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH3_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH3_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH3_NXTCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH3_NXTCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH3_NXTCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH3_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH3_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH3_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH3_CMD_COMMAND_MASK                (0x3U)
#define APBH_CH3_CMD_COMMAND_SHIFT               (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH3_CMD_COMMAND(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH3_CMD_COMMAND_SHIFT)) & APBH_CH3_CMD_COMMAND_MASK)

#define APBH_CH3_CMD_CHAIN_MASK                  (0x4U)
#define APBH_CH3_CMD_CHAIN_SHIFT                 (2U)
#define APBH_CH3_CMD_CHAIN(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CH3_CMD_CHAIN_SHIFT)) & APBH_CH3_CMD_CHAIN_MASK)

#define APBH_CH3_CMD_IRQONCMPLT_MASK             (0x8U)
#define APBH_CH3_CMD_IRQONCMPLT_SHIFT            (3U)
#define APBH_CH3_CMD_IRQONCMPLT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH3_CMD_IRQONCMPLT_SHIFT)) & APBH_CH3_CMD_IRQONCMPLT_MASK)

#define APBH_CH3_CMD_NANDLOCK_MASK               (0x10U)
#define APBH_CH3_CMD_NANDLOCK_SHIFT              (4U)
#define APBH_CH3_CMD_NANDLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH3_CMD_NANDLOCK_SHIFT)) & APBH_CH3_CMD_NANDLOCK_MASK)

#define APBH_CH3_CMD_NANDWAIT4READY_MASK         (0x20U)
#define APBH_CH3_CMD_NANDWAIT4READY_SHIFT        (5U)
#define APBH_CH3_CMD_NANDWAIT4READY(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH3_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH3_CMD_NANDWAIT4READY_MASK)

#define APBH_CH3_CMD_SEMAPHORE_MASK              (0x40U)
#define APBH_CH3_CMD_SEMAPHORE_SHIFT             (6U)
#define APBH_CH3_CMD_SEMAPHORE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH3_CMD_SEMAPHORE_SHIFT)) & APBH_CH3_CMD_SEMAPHORE_MASK)

#define APBH_CH3_CMD_WAIT4ENDCMD_MASK            (0x80U)
#define APBH_CH3_CMD_WAIT4ENDCMD_SHIFT           (7U)
#define APBH_CH3_CMD_WAIT4ENDCMD(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH3_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH3_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH3_CMD_HALTONTERMINATE_MASK        (0x100U)
#define APBH_CH3_CMD_HALTONTERMINATE_SHIFT       (8U)
#define APBH_CH3_CMD_HALTONTERMINATE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH3_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH3_CMD_HALTONTERMINATE_MASK)

#define APBH_CH3_CMD_CMDWORDS_MASK               (0xF000U)
#define APBH_CH3_CMD_CMDWORDS_SHIFT              (12U)
#define APBH_CH3_CMD_CMDWORDS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH3_CMD_CMDWORDS_SHIFT)) & APBH_CH3_CMD_CMDWORDS_MASK)

#define APBH_CH3_CMD_XFER_COUNT_MASK             (0xFFFF0000U)
#define APBH_CH3_CMD_XFER_COUNT_SHIFT            (16U)
#define APBH_CH3_CMD_XFER_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH3_CMD_XFER_COUNT_SHIFT)) & APBH_CH3_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH3_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH3_BAR_ADDRESS_MASK                (0xFFFFFFFFU)
#define APBH_CH3_BAR_ADDRESS_SHIFT               (0U)
#define APBH_CH3_BAR_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH3_BAR_ADDRESS_SHIFT)) & APBH_CH3_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH3_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH3_SEMA_INCREMENT_SEMA_MASK        (0xFFU)
#define APBH_CH3_SEMA_INCREMENT_SEMA_SHIFT       (0U)
#define APBH_CH3_SEMA_INCREMENT_SEMA(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH3_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH3_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH3_SEMA_PHORE_MASK                 (0xFF0000U)
#define APBH_CH3_SEMA_PHORE_SHIFT                (16U)
#define APBH_CH3_SEMA_PHORE(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH3_SEMA_PHORE_SHIFT)) & APBH_CH3_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH3_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH3_DEBUG1_STATEMACHINE_MASK        (0x1FU)
#define APBH_CH3_DEBUG1_STATEMACHINE_SHIFT       (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH3_DEBUG1_STATEMACHINE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH3_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH3_DEBUG1_RSVD1_MASK               (0xFFFE0U)
#define APBH_CH3_DEBUG1_RSVD1_SHIFT              (5U)
#define APBH_CH3_DEBUG1_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG1_RSVD1_SHIFT)) & APBH_CH3_DEBUG1_RSVD1_MASK)

#define APBH_CH3_DEBUG1_WR_FIFO_FULL_MASK        (0x100000U)
#define APBH_CH3_DEBUG1_WR_FIFO_FULL_SHIFT       (20U)
#define APBH_CH3_DEBUG1_WR_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH3_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH3_DEBUG1_WR_FIFO_EMPTY_MASK       (0x200000U)
#define APBH_CH3_DEBUG1_WR_FIFO_EMPTY_SHIFT      (21U)
#define APBH_CH3_DEBUG1_WR_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH3_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH3_DEBUG1_RD_FIFO_FULL_MASK        (0x400000U)
#define APBH_CH3_DEBUG1_RD_FIFO_FULL_SHIFT       (22U)
#define APBH_CH3_DEBUG1_RD_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH3_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH3_DEBUG1_RD_FIFO_EMPTY_MASK       (0x800000U)
#define APBH_CH3_DEBUG1_RD_FIFO_EMPTY_SHIFT      (23U)
#define APBH_CH3_DEBUG1_RD_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH3_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH3_DEBUG1_NEXTCMDADDRVALID_MASK    (0x1000000U)
#define APBH_CH3_DEBUG1_NEXTCMDADDRVALID_SHIFT   (24U)
#define APBH_CH3_DEBUG1_NEXTCMDADDRVALID(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH3_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH3_DEBUG1_LOCK_MASK                (0x2000000U)
#define APBH_CH3_DEBUG1_LOCK_SHIFT               (25U)
#define APBH_CH3_DEBUG1_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG1_LOCK_SHIFT)) & APBH_CH3_DEBUG1_LOCK_MASK)

#define APBH_CH3_DEBUG1_READY_MASK               (0x4000000U)
#define APBH_CH3_DEBUG1_READY_SHIFT              (26U)
#define APBH_CH3_DEBUG1_READY(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG1_READY_SHIFT)) & APBH_CH3_DEBUG1_READY_MASK)

#define APBH_CH3_DEBUG1_SENSE_MASK               (0x8000000U)
#define APBH_CH3_DEBUG1_SENSE_SHIFT              (27U)
#define APBH_CH3_DEBUG1_SENSE(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG1_SENSE_SHIFT)) & APBH_CH3_DEBUG1_SENSE_MASK)

#define APBH_CH3_DEBUG1_END_MASK                 (0x10000000U)
#define APBH_CH3_DEBUG1_END_SHIFT                (28U)
#define APBH_CH3_DEBUG1_END(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG1_END_SHIFT)) & APBH_CH3_DEBUG1_END_MASK)

#define APBH_CH3_DEBUG1_KICK_MASK                (0x20000000U)
#define APBH_CH3_DEBUG1_KICK_SHIFT               (29U)
#define APBH_CH3_DEBUG1_KICK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG1_KICK_SHIFT)) & APBH_CH3_DEBUG1_KICK_MASK)

#define APBH_CH3_DEBUG1_BURST_MASK               (0x40000000U)
#define APBH_CH3_DEBUG1_BURST_SHIFT              (30U)
#define APBH_CH3_DEBUG1_BURST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG1_BURST_SHIFT)) & APBH_CH3_DEBUG1_BURST_MASK)

#define APBH_CH3_DEBUG1_REQ_MASK                 (0x80000000U)
#define APBH_CH3_DEBUG1_REQ_SHIFT                (31U)
#define APBH_CH3_DEBUG1_REQ(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG1_REQ_SHIFT)) & APBH_CH3_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH3_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH3_DEBUG2_AHB_BYTES_MASK           (0xFFFFU)
#define APBH_CH3_DEBUG2_AHB_BYTES_SHIFT          (0U)
#define APBH_CH3_DEBUG2_AHB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH3_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH3_DEBUG2_APB_BYTES_MASK           (0xFFFF0000U)
#define APBH_CH3_DEBUG2_APB_BYTES_SHIFT          (16U)
#define APBH_CH3_DEBUG2_APB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH3_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH3_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH4_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH4_CURCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH4_CURCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH4_CURCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH4_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH4_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH4_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH4_NXTCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH4_NXTCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH4_NXTCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH4_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH4_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH4_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH4_CMD_COMMAND_MASK                (0x3U)
#define APBH_CH4_CMD_COMMAND_SHIFT               (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH4_CMD_COMMAND(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH4_CMD_COMMAND_SHIFT)) & APBH_CH4_CMD_COMMAND_MASK)

#define APBH_CH4_CMD_CHAIN_MASK                  (0x4U)
#define APBH_CH4_CMD_CHAIN_SHIFT                 (2U)
#define APBH_CH4_CMD_CHAIN(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CH4_CMD_CHAIN_SHIFT)) & APBH_CH4_CMD_CHAIN_MASK)

#define APBH_CH4_CMD_IRQONCMPLT_MASK             (0x8U)
#define APBH_CH4_CMD_IRQONCMPLT_SHIFT            (3U)
#define APBH_CH4_CMD_IRQONCMPLT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH4_CMD_IRQONCMPLT_SHIFT)) & APBH_CH4_CMD_IRQONCMPLT_MASK)

#define APBH_CH4_CMD_NANDLOCK_MASK               (0x10U)
#define APBH_CH4_CMD_NANDLOCK_SHIFT              (4U)
#define APBH_CH4_CMD_NANDLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH4_CMD_NANDLOCK_SHIFT)) & APBH_CH4_CMD_NANDLOCK_MASK)

#define APBH_CH4_CMD_NANDWAIT4READY_MASK         (0x20U)
#define APBH_CH4_CMD_NANDWAIT4READY_SHIFT        (5U)
#define APBH_CH4_CMD_NANDWAIT4READY(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH4_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH4_CMD_NANDWAIT4READY_MASK)

#define APBH_CH4_CMD_SEMAPHORE_MASK              (0x40U)
#define APBH_CH4_CMD_SEMAPHORE_SHIFT             (6U)
#define APBH_CH4_CMD_SEMAPHORE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH4_CMD_SEMAPHORE_SHIFT)) & APBH_CH4_CMD_SEMAPHORE_MASK)

#define APBH_CH4_CMD_WAIT4ENDCMD_MASK            (0x80U)
#define APBH_CH4_CMD_WAIT4ENDCMD_SHIFT           (7U)
#define APBH_CH4_CMD_WAIT4ENDCMD(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH4_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH4_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH4_CMD_HALTONTERMINATE_MASK        (0x100U)
#define APBH_CH4_CMD_HALTONTERMINATE_SHIFT       (8U)
#define APBH_CH4_CMD_HALTONTERMINATE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH4_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH4_CMD_HALTONTERMINATE_MASK)

#define APBH_CH4_CMD_CMDWORDS_MASK               (0xF000U)
#define APBH_CH4_CMD_CMDWORDS_SHIFT              (12U)
#define APBH_CH4_CMD_CMDWORDS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH4_CMD_CMDWORDS_SHIFT)) & APBH_CH4_CMD_CMDWORDS_MASK)

#define APBH_CH4_CMD_XFER_COUNT_MASK             (0xFFFF0000U)
#define APBH_CH4_CMD_XFER_COUNT_SHIFT            (16U)
#define APBH_CH4_CMD_XFER_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH4_CMD_XFER_COUNT_SHIFT)) & APBH_CH4_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH4_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH4_BAR_ADDRESS_MASK                (0xFFFFFFFFU)
#define APBH_CH4_BAR_ADDRESS_SHIFT               (0U)
#define APBH_CH4_BAR_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH4_BAR_ADDRESS_SHIFT)) & APBH_CH4_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH4_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH4_SEMA_INCREMENT_SEMA_MASK        (0xFFU)
#define APBH_CH4_SEMA_INCREMENT_SEMA_SHIFT       (0U)
#define APBH_CH4_SEMA_INCREMENT_SEMA(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH4_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH4_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH4_SEMA_PHORE_MASK                 (0xFF0000U)
#define APBH_CH4_SEMA_PHORE_SHIFT                (16U)
#define APBH_CH4_SEMA_PHORE(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH4_SEMA_PHORE_SHIFT)) & APBH_CH4_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH4_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH4_DEBUG1_STATEMACHINE_MASK        (0x1FU)
#define APBH_CH4_DEBUG1_STATEMACHINE_SHIFT       (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH4_DEBUG1_STATEMACHINE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH4_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH4_DEBUG1_RSVD1_MASK               (0xFFFE0U)
#define APBH_CH4_DEBUG1_RSVD1_SHIFT              (5U)
#define APBH_CH4_DEBUG1_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG1_RSVD1_SHIFT)) & APBH_CH4_DEBUG1_RSVD1_MASK)

#define APBH_CH4_DEBUG1_WR_FIFO_FULL_MASK        (0x100000U)
#define APBH_CH4_DEBUG1_WR_FIFO_FULL_SHIFT       (20U)
#define APBH_CH4_DEBUG1_WR_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH4_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH4_DEBUG1_WR_FIFO_EMPTY_MASK       (0x200000U)
#define APBH_CH4_DEBUG1_WR_FIFO_EMPTY_SHIFT      (21U)
#define APBH_CH4_DEBUG1_WR_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH4_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH4_DEBUG1_RD_FIFO_FULL_MASK        (0x400000U)
#define APBH_CH4_DEBUG1_RD_FIFO_FULL_SHIFT       (22U)
#define APBH_CH4_DEBUG1_RD_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH4_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH4_DEBUG1_RD_FIFO_EMPTY_MASK       (0x800000U)
#define APBH_CH4_DEBUG1_RD_FIFO_EMPTY_SHIFT      (23U)
#define APBH_CH4_DEBUG1_RD_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH4_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH4_DEBUG1_NEXTCMDADDRVALID_MASK    (0x1000000U)
#define APBH_CH4_DEBUG1_NEXTCMDADDRVALID_SHIFT   (24U)
#define APBH_CH4_DEBUG1_NEXTCMDADDRVALID(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH4_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH4_DEBUG1_LOCK_MASK                (0x2000000U)
#define APBH_CH4_DEBUG1_LOCK_SHIFT               (25U)
#define APBH_CH4_DEBUG1_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG1_LOCK_SHIFT)) & APBH_CH4_DEBUG1_LOCK_MASK)

#define APBH_CH4_DEBUG1_READY_MASK               (0x4000000U)
#define APBH_CH4_DEBUG1_READY_SHIFT              (26U)
#define APBH_CH4_DEBUG1_READY(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG1_READY_SHIFT)) & APBH_CH4_DEBUG1_READY_MASK)

#define APBH_CH4_DEBUG1_SENSE_MASK               (0x8000000U)
#define APBH_CH4_DEBUG1_SENSE_SHIFT              (27U)
#define APBH_CH4_DEBUG1_SENSE(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG1_SENSE_SHIFT)) & APBH_CH4_DEBUG1_SENSE_MASK)

#define APBH_CH4_DEBUG1_END_MASK                 (0x10000000U)
#define APBH_CH4_DEBUG1_END_SHIFT                (28U)
#define APBH_CH4_DEBUG1_END(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG1_END_SHIFT)) & APBH_CH4_DEBUG1_END_MASK)

#define APBH_CH4_DEBUG1_KICK_MASK                (0x20000000U)
#define APBH_CH4_DEBUG1_KICK_SHIFT               (29U)
#define APBH_CH4_DEBUG1_KICK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG1_KICK_SHIFT)) & APBH_CH4_DEBUG1_KICK_MASK)

#define APBH_CH4_DEBUG1_BURST_MASK               (0x40000000U)
#define APBH_CH4_DEBUG1_BURST_SHIFT              (30U)
#define APBH_CH4_DEBUG1_BURST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG1_BURST_SHIFT)) & APBH_CH4_DEBUG1_BURST_MASK)

#define APBH_CH4_DEBUG1_REQ_MASK                 (0x80000000U)
#define APBH_CH4_DEBUG1_REQ_SHIFT                (31U)
#define APBH_CH4_DEBUG1_REQ(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG1_REQ_SHIFT)) & APBH_CH4_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH4_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH4_DEBUG2_AHB_BYTES_MASK           (0xFFFFU)
#define APBH_CH4_DEBUG2_AHB_BYTES_SHIFT          (0U)
#define APBH_CH4_DEBUG2_AHB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH4_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH4_DEBUG2_APB_BYTES_MASK           (0xFFFF0000U)
#define APBH_CH4_DEBUG2_APB_BYTES_SHIFT          (16U)
#define APBH_CH4_DEBUG2_APB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH4_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH4_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH5_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH5_CURCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH5_CURCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH5_CURCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH5_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH5_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH5_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH5_NXTCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH5_NXTCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH5_NXTCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH5_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH5_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH5_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH5_CMD_COMMAND_MASK                (0x3U)
#define APBH_CH5_CMD_COMMAND_SHIFT               (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH5_CMD_COMMAND(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH5_CMD_COMMAND_SHIFT)) & APBH_CH5_CMD_COMMAND_MASK)

#define APBH_CH5_CMD_CHAIN_MASK                  (0x4U)
#define APBH_CH5_CMD_CHAIN_SHIFT                 (2U)
#define APBH_CH5_CMD_CHAIN(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CH5_CMD_CHAIN_SHIFT)) & APBH_CH5_CMD_CHAIN_MASK)

#define APBH_CH5_CMD_IRQONCMPLT_MASK             (0x8U)
#define APBH_CH5_CMD_IRQONCMPLT_SHIFT            (3U)
#define APBH_CH5_CMD_IRQONCMPLT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH5_CMD_IRQONCMPLT_SHIFT)) & APBH_CH5_CMD_IRQONCMPLT_MASK)

#define APBH_CH5_CMD_NANDLOCK_MASK               (0x10U)
#define APBH_CH5_CMD_NANDLOCK_SHIFT              (4U)
#define APBH_CH5_CMD_NANDLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH5_CMD_NANDLOCK_SHIFT)) & APBH_CH5_CMD_NANDLOCK_MASK)

#define APBH_CH5_CMD_NANDWAIT4READY_MASK         (0x20U)
#define APBH_CH5_CMD_NANDWAIT4READY_SHIFT        (5U)
#define APBH_CH5_CMD_NANDWAIT4READY(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH5_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH5_CMD_NANDWAIT4READY_MASK)

#define APBH_CH5_CMD_SEMAPHORE_MASK              (0x40U)
#define APBH_CH5_CMD_SEMAPHORE_SHIFT             (6U)
#define APBH_CH5_CMD_SEMAPHORE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH5_CMD_SEMAPHORE_SHIFT)) & APBH_CH5_CMD_SEMAPHORE_MASK)

#define APBH_CH5_CMD_WAIT4ENDCMD_MASK            (0x80U)
#define APBH_CH5_CMD_WAIT4ENDCMD_SHIFT           (7U)
#define APBH_CH5_CMD_WAIT4ENDCMD(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH5_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH5_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH5_CMD_HALTONTERMINATE_MASK        (0x100U)
#define APBH_CH5_CMD_HALTONTERMINATE_SHIFT       (8U)
#define APBH_CH5_CMD_HALTONTERMINATE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH5_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH5_CMD_HALTONTERMINATE_MASK)

#define APBH_CH5_CMD_CMDWORDS_MASK               (0xF000U)
#define APBH_CH5_CMD_CMDWORDS_SHIFT              (12U)
#define APBH_CH5_CMD_CMDWORDS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH5_CMD_CMDWORDS_SHIFT)) & APBH_CH5_CMD_CMDWORDS_MASK)

#define APBH_CH5_CMD_XFER_COUNT_MASK             (0xFFFF0000U)
#define APBH_CH5_CMD_XFER_COUNT_SHIFT            (16U)
#define APBH_CH5_CMD_XFER_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH5_CMD_XFER_COUNT_SHIFT)) & APBH_CH5_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH5_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH5_BAR_ADDRESS_MASK                (0xFFFFFFFFU)
#define APBH_CH5_BAR_ADDRESS_SHIFT               (0U)
#define APBH_CH5_BAR_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH5_BAR_ADDRESS_SHIFT)) & APBH_CH5_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH5_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH5_SEMA_INCREMENT_SEMA_MASK        (0xFFU)
#define APBH_CH5_SEMA_INCREMENT_SEMA_SHIFT       (0U)
#define APBH_CH5_SEMA_INCREMENT_SEMA(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH5_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH5_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH5_SEMA_PHORE_MASK                 (0xFF0000U)
#define APBH_CH5_SEMA_PHORE_SHIFT                (16U)
#define APBH_CH5_SEMA_PHORE(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH5_SEMA_PHORE_SHIFT)) & APBH_CH5_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH5_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH5_DEBUG1_STATEMACHINE_MASK        (0x1FU)
#define APBH_CH5_DEBUG1_STATEMACHINE_SHIFT       (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH5_DEBUG1_STATEMACHINE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH5_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH5_DEBUG1_RSVD1_MASK               (0xFFFE0U)
#define APBH_CH5_DEBUG1_RSVD1_SHIFT              (5U)
#define APBH_CH5_DEBUG1_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG1_RSVD1_SHIFT)) & APBH_CH5_DEBUG1_RSVD1_MASK)

#define APBH_CH5_DEBUG1_WR_FIFO_FULL_MASK        (0x100000U)
#define APBH_CH5_DEBUG1_WR_FIFO_FULL_SHIFT       (20U)
#define APBH_CH5_DEBUG1_WR_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH5_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH5_DEBUG1_WR_FIFO_EMPTY_MASK       (0x200000U)
#define APBH_CH5_DEBUG1_WR_FIFO_EMPTY_SHIFT      (21U)
#define APBH_CH5_DEBUG1_WR_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH5_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH5_DEBUG1_RD_FIFO_FULL_MASK        (0x400000U)
#define APBH_CH5_DEBUG1_RD_FIFO_FULL_SHIFT       (22U)
#define APBH_CH5_DEBUG1_RD_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH5_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH5_DEBUG1_RD_FIFO_EMPTY_MASK       (0x800000U)
#define APBH_CH5_DEBUG1_RD_FIFO_EMPTY_SHIFT      (23U)
#define APBH_CH5_DEBUG1_RD_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH5_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH5_DEBUG1_NEXTCMDADDRVALID_MASK    (0x1000000U)
#define APBH_CH5_DEBUG1_NEXTCMDADDRVALID_SHIFT   (24U)
#define APBH_CH5_DEBUG1_NEXTCMDADDRVALID(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH5_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH5_DEBUG1_LOCK_MASK                (0x2000000U)
#define APBH_CH5_DEBUG1_LOCK_SHIFT               (25U)
#define APBH_CH5_DEBUG1_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG1_LOCK_SHIFT)) & APBH_CH5_DEBUG1_LOCK_MASK)

#define APBH_CH5_DEBUG1_READY_MASK               (0x4000000U)
#define APBH_CH5_DEBUG1_READY_SHIFT              (26U)
#define APBH_CH5_DEBUG1_READY(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG1_READY_SHIFT)) & APBH_CH5_DEBUG1_READY_MASK)

#define APBH_CH5_DEBUG1_SENSE_MASK               (0x8000000U)
#define APBH_CH5_DEBUG1_SENSE_SHIFT              (27U)
#define APBH_CH5_DEBUG1_SENSE(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG1_SENSE_SHIFT)) & APBH_CH5_DEBUG1_SENSE_MASK)

#define APBH_CH5_DEBUG1_END_MASK                 (0x10000000U)
#define APBH_CH5_DEBUG1_END_SHIFT                (28U)
#define APBH_CH5_DEBUG1_END(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG1_END_SHIFT)) & APBH_CH5_DEBUG1_END_MASK)

#define APBH_CH5_DEBUG1_KICK_MASK                (0x20000000U)
#define APBH_CH5_DEBUG1_KICK_SHIFT               (29U)
#define APBH_CH5_DEBUG1_KICK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG1_KICK_SHIFT)) & APBH_CH5_DEBUG1_KICK_MASK)

#define APBH_CH5_DEBUG1_BURST_MASK               (0x40000000U)
#define APBH_CH5_DEBUG1_BURST_SHIFT              (30U)
#define APBH_CH5_DEBUG1_BURST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG1_BURST_SHIFT)) & APBH_CH5_DEBUG1_BURST_MASK)

#define APBH_CH5_DEBUG1_REQ_MASK                 (0x80000000U)
#define APBH_CH5_DEBUG1_REQ_SHIFT                (31U)
#define APBH_CH5_DEBUG1_REQ(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG1_REQ_SHIFT)) & APBH_CH5_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH5_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH5_DEBUG2_AHB_BYTES_MASK           (0xFFFFU)
#define APBH_CH5_DEBUG2_AHB_BYTES_SHIFT          (0U)
#define APBH_CH5_DEBUG2_AHB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH5_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH5_DEBUG2_APB_BYTES_MASK           (0xFFFF0000U)
#define APBH_CH5_DEBUG2_APB_BYTES_SHIFT          (16U)
#define APBH_CH5_DEBUG2_APB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH5_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH5_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH6_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH6_CURCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH6_CURCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH6_CURCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH6_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH6_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH6_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH6_NXTCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH6_NXTCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH6_NXTCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH6_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH6_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH6_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH6_CMD_COMMAND_MASK                (0x3U)
#define APBH_CH6_CMD_COMMAND_SHIFT               (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH6_CMD_COMMAND(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH6_CMD_COMMAND_SHIFT)) & APBH_CH6_CMD_COMMAND_MASK)

#define APBH_CH6_CMD_CHAIN_MASK                  (0x4U)
#define APBH_CH6_CMD_CHAIN_SHIFT                 (2U)
#define APBH_CH6_CMD_CHAIN(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CH6_CMD_CHAIN_SHIFT)) & APBH_CH6_CMD_CHAIN_MASK)

#define APBH_CH6_CMD_IRQONCMPLT_MASK             (0x8U)
#define APBH_CH6_CMD_IRQONCMPLT_SHIFT            (3U)
#define APBH_CH6_CMD_IRQONCMPLT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH6_CMD_IRQONCMPLT_SHIFT)) & APBH_CH6_CMD_IRQONCMPLT_MASK)

#define APBH_CH6_CMD_NANDLOCK_MASK               (0x10U)
#define APBH_CH6_CMD_NANDLOCK_SHIFT              (4U)
#define APBH_CH6_CMD_NANDLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH6_CMD_NANDLOCK_SHIFT)) & APBH_CH6_CMD_NANDLOCK_MASK)

#define APBH_CH6_CMD_NANDWAIT4READY_MASK         (0x20U)
#define APBH_CH6_CMD_NANDWAIT4READY_SHIFT        (5U)
#define APBH_CH6_CMD_NANDWAIT4READY(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH6_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH6_CMD_NANDWAIT4READY_MASK)

#define APBH_CH6_CMD_SEMAPHORE_MASK              (0x40U)
#define APBH_CH6_CMD_SEMAPHORE_SHIFT             (6U)
#define APBH_CH6_CMD_SEMAPHORE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH6_CMD_SEMAPHORE_SHIFT)) & APBH_CH6_CMD_SEMAPHORE_MASK)

#define APBH_CH6_CMD_WAIT4ENDCMD_MASK            (0x80U)
#define APBH_CH6_CMD_WAIT4ENDCMD_SHIFT           (7U)
#define APBH_CH6_CMD_WAIT4ENDCMD(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH6_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH6_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH6_CMD_HALTONTERMINATE_MASK        (0x100U)
#define APBH_CH6_CMD_HALTONTERMINATE_SHIFT       (8U)
#define APBH_CH6_CMD_HALTONTERMINATE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH6_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH6_CMD_HALTONTERMINATE_MASK)

#define APBH_CH6_CMD_CMDWORDS_MASK               (0xF000U)
#define APBH_CH6_CMD_CMDWORDS_SHIFT              (12U)
#define APBH_CH6_CMD_CMDWORDS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH6_CMD_CMDWORDS_SHIFT)) & APBH_CH6_CMD_CMDWORDS_MASK)

#define APBH_CH6_CMD_XFER_COUNT_MASK             (0xFFFF0000U)
#define APBH_CH6_CMD_XFER_COUNT_SHIFT            (16U)
#define APBH_CH6_CMD_XFER_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH6_CMD_XFER_COUNT_SHIFT)) & APBH_CH6_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH6_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH6_BAR_ADDRESS_MASK                (0xFFFFFFFFU)
#define APBH_CH6_BAR_ADDRESS_SHIFT               (0U)
#define APBH_CH6_BAR_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH6_BAR_ADDRESS_SHIFT)) & APBH_CH6_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH6_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH6_SEMA_INCREMENT_SEMA_MASK        (0xFFU)
#define APBH_CH6_SEMA_INCREMENT_SEMA_SHIFT       (0U)
#define APBH_CH6_SEMA_INCREMENT_SEMA(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH6_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH6_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH6_SEMA_PHORE_MASK                 (0xFF0000U)
#define APBH_CH6_SEMA_PHORE_SHIFT                (16U)
#define APBH_CH6_SEMA_PHORE(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH6_SEMA_PHORE_SHIFT)) & APBH_CH6_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH6_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH6_DEBUG1_STATEMACHINE_MASK        (0x1FU)
#define APBH_CH6_DEBUG1_STATEMACHINE_SHIFT       (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH6_DEBUG1_STATEMACHINE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH6_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH6_DEBUG1_RSVD1_MASK               (0xFFFE0U)
#define APBH_CH6_DEBUG1_RSVD1_SHIFT              (5U)
#define APBH_CH6_DEBUG1_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG1_RSVD1_SHIFT)) & APBH_CH6_DEBUG1_RSVD1_MASK)

#define APBH_CH6_DEBUG1_WR_FIFO_FULL_MASK        (0x100000U)
#define APBH_CH6_DEBUG1_WR_FIFO_FULL_SHIFT       (20U)
#define APBH_CH6_DEBUG1_WR_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH6_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH6_DEBUG1_WR_FIFO_EMPTY_MASK       (0x200000U)
#define APBH_CH6_DEBUG1_WR_FIFO_EMPTY_SHIFT      (21U)
#define APBH_CH6_DEBUG1_WR_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH6_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH6_DEBUG1_RD_FIFO_FULL_MASK        (0x400000U)
#define APBH_CH6_DEBUG1_RD_FIFO_FULL_SHIFT       (22U)
#define APBH_CH6_DEBUG1_RD_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH6_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH6_DEBUG1_RD_FIFO_EMPTY_MASK       (0x800000U)
#define APBH_CH6_DEBUG1_RD_FIFO_EMPTY_SHIFT      (23U)
#define APBH_CH6_DEBUG1_RD_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH6_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH6_DEBUG1_NEXTCMDADDRVALID_MASK    (0x1000000U)
#define APBH_CH6_DEBUG1_NEXTCMDADDRVALID_SHIFT   (24U)
#define APBH_CH6_DEBUG1_NEXTCMDADDRVALID(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH6_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH6_DEBUG1_LOCK_MASK                (0x2000000U)
#define APBH_CH6_DEBUG1_LOCK_SHIFT               (25U)
#define APBH_CH6_DEBUG1_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG1_LOCK_SHIFT)) & APBH_CH6_DEBUG1_LOCK_MASK)

#define APBH_CH6_DEBUG1_READY_MASK               (0x4000000U)
#define APBH_CH6_DEBUG1_READY_SHIFT              (26U)
#define APBH_CH6_DEBUG1_READY(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG1_READY_SHIFT)) & APBH_CH6_DEBUG1_READY_MASK)

#define APBH_CH6_DEBUG1_SENSE_MASK               (0x8000000U)
#define APBH_CH6_DEBUG1_SENSE_SHIFT              (27U)
#define APBH_CH6_DEBUG1_SENSE(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG1_SENSE_SHIFT)) & APBH_CH6_DEBUG1_SENSE_MASK)

#define APBH_CH6_DEBUG1_END_MASK                 (0x10000000U)
#define APBH_CH6_DEBUG1_END_SHIFT                (28U)
#define APBH_CH6_DEBUG1_END(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG1_END_SHIFT)) & APBH_CH6_DEBUG1_END_MASK)

#define APBH_CH6_DEBUG1_KICK_MASK                (0x20000000U)
#define APBH_CH6_DEBUG1_KICK_SHIFT               (29U)
#define APBH_CH6_DEBUG1_KICK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG1_KICK_SHIFT)) & APBH_CH6_DEBUG1_KICK_MASK)

#define APBH_CH6_DEBUG1_BURST_MASK               (0x40000000U)
#define APBH_CH6_DEBUG1_BURST_SHIFT              (30U)
#define APBH_CH6_DEBUG1_BURST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG1_BURST_SHIFT)) & APBH_CH6_DEBUG1_BURST_MASK)

#define APBH_CH6_DEBUG1_REQ_MASK                 (0x80000000U)
#define APBH_CH6_DEBUG1_REQ_SHIFT                (31U)
#define APBH_CH6_DEBUG1_REQ(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG1_REQ_SHIFT)) & APBH_CH6_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH6_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH6_DEBUG2_AHB_BYTES_MASK           (0xFFFFU)
#define APBH_CH6_DEBUG2_AHB_BYTES_SHIFT          (0U)
#define APBH_CH6_DEBUG2_AHB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH6_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH6_DEBUG2_APB_BYTES_MASK           (0xFFFF0000U)
#define APBH_CH6_DEBUG2_APB_BYTES_SHIFT          (16U)
#define APBH_CH6_DEBUG2_APB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH6_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH6_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH7_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH7_CURCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH7_CURCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH7_CURCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH7_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH7_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH7_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH7_NXTCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH7_NXTCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH7_NXTCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH7_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH7_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH7_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH7_CMD_COMMAND_MASK                (0x3U)
#define APBH_CH7_CMD_COMMAND_SHIFT               (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH7_CMD_COMMAND(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH7_CMD_COMMAND_SHIFT)) & APBH_CH7_CMD_COMMAND_MASK)

#define APBH_CH7_CMD_CHAIN_MASK                  (0x4U)
#define APBH_CH7_CMD_CHAIN_SHIFT                 (2U)
#define APBH_CH7_CMD_CHAIN(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CH7_CMD_CHAIN_SHIFT)) & APBH_CH7_CMD_CHAIN_MASK)

#define APBH_CH7_CMD_IRQONCMPLT_MASK             (0x8U)
#define APBH_CH7_CMD_IRQONCMPLT_SHIFT            (3U)
#define APBH_CH7_CMD_IRQONCMPLT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH7_CMD_IRQONCMPLT_SHIFT)) & APBH_CH7_CMD_IRQONCMPLT_MASK)

#define APBH_CH7_CMD_NANDLOCK_MASK               (0x10U)
#define APBH_CH7_CMD_NANDLOCK_SHIFT              (4U)
#define APBH_CH7_CMD_NANDLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH7_CMD_NANDLOCK_SHIFT)) & APBH_CH7_CMD_NANDLOCK_MASK)

#define APBH_CH7_CMD_NANDWAIT4READY_MASK         (0x20U)
#define APBH_CH7_CMD_NANDWAIT4READY_SHIFT        (5U)
#define APBH_CH7_CMD_NANDWAIT4READY(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH7_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH7_CMD_NANDWAIT4READY_MASK)

#define APBH_CH7_CMD_SEMAPHORE_MASK              (0x40U)
#define APBH_CH7_CMD_SEMAPHORE_SHIFT             (6U)
#define APBH_CH7_CMD_SEMAPHORE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH7_CMD_SEMAPHORE_SHIFT)) & APBH_CH7_CMD_SEMAPHORE_MASK)

#define APBH_CH7_CMD_WAIT4ENDCMD_MASK            (0x80U)
#define APBH_CH7_CMD_WAIT4ENDCMD_SHIFT           (7U)
#define APBH_CH7_CMD_WAIT4ENDCMD(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH7_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH7_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH7_CMD_HALTONTERMINATE_MASK        (0x100U)
#define APBH_CH7_CMD_HALTONTERMINATE_SHIFT       (8U)
#define APBH_CH7_CMD_HALTONTERMINATE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH7_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH7_CMD_HALTONTERMINATE_MASK)

#define APBH_CH7_CMD_CMDWORDS_MASK               (0xF000U)
#define APBH_CH7_CMD_CMDWORDS_SHIFT              (12U)
#define APBH_CH7_CMD_CMDWORDS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH7_CMD_CMDWORDS_SHIFT)) & APBH_CH7_CMD_CMDWORDS_MASK)

#define APBH_CH7_CMD_XFER_COUNT_MASK             (0xFFFF0000U)
#define APBH_CH7_CMD_XFER_COUNT_SHIFT            (16U)
#define APBH_CH7_CMD_XFER_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH7_CMD_XFER_COUNT_SHIFT)) & APBH_CH7_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH7_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH7_BAR_ADDRESS_MASK                (0xFFFFFFFFU)
#define APBH_CH7_BAR_ADDRESS_SHIFT               (0U)
#define APBH_CH7_BAR_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH7_BAR_ADDRESS_SHIFT)) & APBH_CH7_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH7_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH7_SEMA_INCREMENT_SEMA_MASK        (0xFFU)
#define APBH_CH7_SEMA_INCREMENT_SEMA_SHIFT       (0U)
#define APBH_CH7_SEMA_INCREMENT_SEMA(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH7_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH7_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH7_SEMA_PHORE_MASK                 (0xFF0000U)
#define APBH_CH7_SEMA_PHORE_SHIFT                (16U)
#define APBH_CH7_SEMA_PHORE(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH7_SEMA_PHORE_SHIFT)) & APBH_CH7_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH7_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH7_DEBUG1_STATEMACHINE_MASK        (0x1FU)
#define APBH_CH7_DEBUG1_STATEMACHINE_SHIFT       (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH7_DEBUG1_STATEMACHINE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH7_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH7_DEBUG1_RSVD1_MASK               (0xFFFE0U)
#define APBH_CH7_DEBUG1_RSVD1_SHIFT              (5U)
#define APBH_CH7_DEBUG1_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG1_RSVD1_SHIFT)) & APBH_CH7_DEBUG1_RSVD1_MASK)

#define APBH_CH7_DEBUG1_WR_FIFO_FULL_MASK        (0x100000U)
#define APBH_CH7_DEBUG1_WR_FIFO_FULL_SHIFT       (20U)
#define APBH_CH7_DEBUG1_WR_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH7_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH7_DEBUG1_WR_FIFO_EMPTY_MASK       (0x200000U)
#define APBH_CH7_DEBUG1_WR_FIFO_EMPTY_SHIFT      (21U)
#define APBH_CH7_DEBUG1_WR_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH7_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH7_DEBUG1_RD_FIFO_FULL_MASK        (0x400000U)
#define APBH_CH7_DEBUG1_RD_FIFO_FULL_SHIFT       (22U)
#define APBH_CH7_DEBUG1_RD_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH7_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH7_DEBUG1_RD_FIFO_EMPTY_MASK       (0x800000U)
#define APBH_CH7_DEBUG1_RD_FIFO_EMPTY_SHIFT      (23U)
#define APBH_CH7_DEBUG1_RD_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH7_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH7_DEBUG1_NEXTCMDADDRVALID_MASK    (0x1000000U)
#define APBH_CH7_DEBUG1_NEXTCMDADDRVALID_SHIFT   (24U)
#define APBH_CH7_DEBUG1_NEXTCMDADDRVALID(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH7_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH7_DEBUG1_LOCK_MASK                (0x2000000U)
#define APBH_CH7_DEBUG1_LOCK_SHIFT               (25U)
#define APBH_CH7_DEBUG1_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG1_LOCK_SHIFT)) & APBH_CH7_DEBUG1_LOCK_MASK)

#define APBH_CH7_DEBUG1_READY_MASK               (0x4000000U)
#define APBH_CH7_DEBUG1_READY_SHIFT              (26U)
#define APBH_CH7_DEBUG1_READY(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG1_READY_SHIFT)) & APBH_CH7_DEBUG1_READY_MASK)

#define APBH_CH7_DEBUG1_SENSE_MASK               (0x8000000U)
#define APBH_CH7_DEBUG1_SENSE_SHIFT              (27U)
#define APBH_CH7_DEBUG1_SENSE(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG1_SENSE_SHIFT)) & APBH_CH7_DEBUG1_SENSE_MASK)

#define APBH_CH7_DEBUG1_END_MASK                 (0x10000000U)
#define APBH_CH7_DEBUG1_END_SHIFT                (28U)
#define APBH_CH7_DEBUG1_END(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG1_END_SHIFT)) & APBH_CH7_DEBUG1_END_MASK)

#define APBH_CH7_DEBUG1_KICK_MASK                (0x20000000U)
#define APBH_CH7_DEBUG1_KICK_SHIFT               (29U)
#define APBH_CH7_DEBUG1_KICK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG1_KICK_SHIFT)) & APBH_CH7_DEBUG1_KICK_MASK)

#define APBH_CH7_DEBUG1_BURST_MASK               (0x40000000U)
#define APBH_CH7_DEBUG1_BURST_SHIFT              (30U)
#define APBH_CH7_DEBUG1_BURST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG1_BURST_SHIFT)) & APBH_CH7_DEBUG1_BURST_MASK)

#define APBH_CH7_DEBUG1_REQ_MASK                 (0x80000000U)
#define APBH_CH7_DEBUG1_REQ_SHIFT                (31U)
#define APBH_CH7_DEBUG1_REQ(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG1_REQ_SHIFT)) & APBH_CH7_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH7_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH7_DEBUG2_AHB_BYTES_MASK           (0xFFFFU)
#define APBH_CH7_DEBUG2_AHB_BYTES_SHIFT          (0U)
#define APBH_CH7_DEBUG2_AHB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH7_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH7_DEBUG2_APB_BYTES_MASK           (0xFFFF0000U)
#define APBH_CH7_DEBUG2_APB_BYTES_SHIFT          (16U)
#define APBH_CH7_DEBUG2_APB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH7_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH7_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH8_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH8_CURCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH8_CURCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH8_CURCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH8_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH8_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH8_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH8_NXTCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH8_NXTCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH8_NXTCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH8_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH8_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH8_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH8_CMD_COMMAND_MASK                (0x3U)
#define APBH_CH8_CMD_COMMAND_SHIFT               (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH8_CMD_COMMAND(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH8_CMD_COMMAND_SHIFT)) & APBH_CH8_CMD_COMMAND_MASK)

#define APBH_CH8_CMD_CHAIN_MASK                  (0x4U)
#define APBH_CH8_CMD_CHAIN_SHIFT                 (2U)
#define APBH_CH8_CMD_CHAIN(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CH8_CMD_CHAIN_SHIFT)) & APBH_CH8_CMD_CHAIN_MASK)

#define APBH_CH8_CMD_IRQONCMPLT_MASK             (0x8U)
#define APBH_CH8_CMD_IRQONCMPLT_SHIFT            (3U)
#define APBH_CH8_CMD_IRQONCMPLT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH8_CMD_IRQONCMPLT_SHIFT)) & APBH_CH8_CMD_IRQONCMPLT_MASK)

#define APBH_CH8_CMD_NANDLOCK_MASK               (0x10U)
#define APBH_CH8_CMD_NANDLOCK_SHIFT              (4U)
#define APBH_CH8_CMD_NANDLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH8_CMD_NANDLOCK_SHIFT)) & APBH_CH8_CMD_NANDLOCK_MASK)

#define APBH_CH8_CMD_NANDWAIT4READY_MASK         (0x20U)
#define APBH_CH8_CMD_NANDWAIT4READY_SHIFT        (5U)
#define APBH_CH8_CMD_NANDWAIT4READY(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH8_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH8_CMD_NANDWAIT4READY_MASK)

#define APBH_CH8_CMD_SEMAPHORE_MASK              (0x40U)
#define APBH_CH8_CMD_SEMAPHORE_SHIFT             (6U)
#define APBH_CH8_CMD_SEMAPHORE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH8_CMD_SEMAPHORE_SHIFT)) & APBH_CH8_CMD_SEMAPHORE_MASK)

#define APBH_CH8_CMD_WAIT4ENDCMD_MASK            (0x80U)
#define APBH_CH8_CMD_WAIT4ENDCMD_SHIFT           (7U)
#define APBH_CH8_CMD_WAIT4ENDCMD(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH8_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH8_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH8_CMD_HALTONTERMINATE_MASK        (0x100U)
#define APBH_CH8_CMD_HALTONTERMINATE_SHIFT       (8U)
#define APBH_CH8_CMD_HALTONTERMINATE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH8_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH8_CMD_HALTONTERMINATE_MASK)

#define APBH_CH8_CMD_CMDWORDS_MASK               (0xF000U)
#define APBH_CH8_CMD_CMDWORDS_SHIFT              (12U)
#define APBH_CH8_CMD_CMDWORDS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH8_CMD_CMDWORDS_SHIFT)) & APBH_CH8_CMD_CMDWORDS_MASK)

#define APBH_CH8_CMD_XFER_COUNT_MASK             (0xFFFF0000U)
#define APBH_CH8_CMD_XFER_COUNT_SHIFT            (16U)
#define APBH_CH8_CMD_XFER_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH8_CMD_XFER_COUNT_SHIFT)) & APBH_CH8_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH8_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH8_BAR_ADDRESS_MASK                (0xFFFFFFFFU)
#define APBH_CH8_BAR_ADDRESS_SHIFT               (0U)
#define APBH_CH8_BAR_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH8_BAR_ADDRESS_SHIFT)) & APBH_CH8_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH8_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH8_SEMA_INCREMENT_SEMA_MASK        (0xFFU)
#define APBH_CH8_SEMA_INCREMENT_SEMA_SHIFT       (0U)
#define APBH_CH8_SEMA_INCREMENT_SEMA(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH8_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH8_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH8_SEMA_PHORE_MASK                 (0xFF0000U)
#define APBH_CH8_SEMA_PHORE_SHIFT                (16U)
#define APBH_CH8_SEMA_PHORE(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH8_SEMA_PHORE_SHIFT)) & APBH_CH8_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH8_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH8_DEBUG1_STATEMACHINE_MASK        (0x1FU)
#define APBH_CH8_DEBUG1_STATEMACHINE_SHIFT       (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH8_DEBUG1_STATEMACHINE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH8_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH8_DEBUG1_RSVD1_MASK               (0xFFFE0U)
#define APBH_CH8_DEBUG1_RSVD1_SHIFT              (5U)
#define APBH_CH8_DEBUG1_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG1_RSVD1_SHIFT)) & APBH_CH8_DEBUG1_RSVD1_MASK)

#define APBH_CH8_DEBUG1_WR_FIFO_FULL_MASK        (0x100000U)
#define APBH_CH8_DEBUG1_WR_FIFO_FULL_SHIFT       (20U)
#define APBH_CH8_DEBUG1_WR_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH8_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH8_DEBUG1_WR_FIFO_EMPTY_MASK       (0x200000U)
#define APBH_CH8_DEBUG1_WR_FIFO_EMPTY_SHIFT      (21U)
#define APBH_CH8_DEBUG1_WR_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH8_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH8_DEBUG1_RD_FIFO_FULL_MASK        (0x400000U)
#define APBH_CH8_DEBUG1_RD_FIFO_FULL_SHIFT       (22U)
#define APBH_CH8_DEBUG1_RD_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH8_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH8_DEBUG1_RD_FIFO_EMPTY_MASK       (0x800000U)
#define APBH_CH8_DEBUG1_RD_FIFO_EMPTY_SHIFT      (23U)
#define APBH_CH8_DEBUG1_RD_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH8_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH8_DEBUG1_NEXTCMDADDRVALID_MASK    (0x1000000U)
#define APBH_CH8_DEBUG1_NEXTCMDADDRVALID_SHIFT   (24U)
#define APBH_CH8_DEBUG1_NEXTCMDADDRVALID(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH8_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH8_DEBUG1_LOCK_MASK                (0x2000000U)
#define APBH_CH8_DEBUG1_LOCK_SHIFT               (25U)
#define APBH_CH8_DEBUG1_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG1_LOCK_SHIFT)) & APBH_CH8_DEBUG1_LOCK_MASK)

#define APBH_CH8_DEBUG1_READY_MASK               (0x4000000U)
#define APBH_CH8_DEBUG1_READY_SHIFT              (26U)
#define APBH_CH8_DEBUG1_READY(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG1_READY_SHIFT)) & APBH_CH8_DEBUG1_READY_MASK)

#define APBH_CH8_DEBUG1_SENSE_MASK               (0x8000000U)
#define APBH_CH8_DEBUG1_SENSE_SHIFT              (27U)
#define APBH_CH8_DEBUG1_SENSE(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG1_SENSE_SHIFT)) & APBH_CH8_DEBUG1_SENSE_MASK)

#define APBH_CH8_DEBUG1_END_MASK                 (0x10000000U)
#define APBH_CH8_DEBUG1_END_SHIFT                (28U)
#define APBH_CH8_DEBUG1_END(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG1_END_SHIFT)) & APBH_CH8_DEBUG1_END_MASK)

#define APBH_CH8_DEBUG1_KICK_MASK                (0x20000000U)
#define APBH_CH8_DEBUG1_KICK_SHIFT               (29U)
#define APBH_CH8_DEBUG1_KICK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG1_KICK_SHIFT)) & APBH_CH8_DEBUG1_KICK_MASK)

#define APBH_CH8_DEBUG1_BURST_MASK               (0x40000000U)
#define APBH_CH8_DEBUG1_BURST_SHIFT              (30U)
#define APBH_CH8_DEBUG1_BURST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG1_BURST_SHIFT)) & APBH_CH8_DEBUG1_BURST_MASK)

#define APBH_CH8_DEBUG1_REQ_MASK                 (0x80000000U)
#define APBH_CH8_DEBUG1_REQ_SHIFT                (31U)
#define APBH_CH8_DEBUG1_REQ(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG1_REQ_SHIFT)) & APBH_CH8_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH8_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH8_DEBUG2_AHB_BYTES_MASK           (0xFFFFU)
#define APBH_CH8_DEBUG2_AHB_BYTES_SHIFT          (0U)
#define APBH_CH8_DEBUG2_AHB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH8_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH8_DEBUG2_APB_BYTES_MASK           (0xFFFF0000U)
#define APBH_CH8_DEBUG2_APB_BYTES_SHIFT          (16U)
#define APBH_CH8_DEBUG2_APB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH8_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH8_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH9_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH9_CURCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH9_CURCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH9_CURCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH9_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH9_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH9_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH9_NXTCMDAR_CMD_ADDR_MASK          (0xFFFFFFFFU)
#define APBH_CH9_NXTCMDAR_CMD_ADDR_SHIFT         (0U)
#define APBH_CH9_NXTCMDAR_CMD_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH9_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH9_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH9_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH9_CMD_COMMAND_MASK                (0x3U)
#define APBH_CH9_CMD_COMMAND_SHIFT               (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH9_CMD_COMMAND(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH9_CMD_COMMAND_SHIFT)) & APBH_CH9_CMD_COMMAND_MASK)

#define APBH_CH9_CMD_CHAIN_MASK                  (0x4U)
#define APBH_CH9_CMD_CHAIN_SHIFT                 (2U)
#define APBH_CH9_CMD_CHAIN(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CH9_CMD_CHAIN_SHIFT)) & APBH_CH9_CMD_CHAIN_MASK)

#define APBH_CH9_CMD_IRQONCMPLT_MASK             (0x8U)
#define APBH_CH9_CMD_IRQONCMPLT_SHIFT            (3U)
#define APBH_CH9_CMD_IRQONCMPLT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH9_CMD_IRQONCMPLT_SHIFT)) & APBH_CH9_CMD_IRQONCMPLT_MASK)

#define APBH_CH9_CMD_NANDLOCK_MASK               (0x10U)
#define APBH_CH9_CMD_NANDLOCK_SHIFT              (4U)
#define APBH_CH9_CMD_NANDLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH9_CMD_NANDLOCK_SHIFT)) & APBH_CH9_CMD_NANDLOCK_MASK)

#define APBH_CH9_CMD_NANDWAIT4READY_MASK         (0x20U)
#define APBH_CH9_CMD_NANDWAIT4READY_SHIFT        (5U)
#define APBH_CH9_CMD_NANDWAIT4READY(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH9_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH9_CMD_NANDWAIT4READY_MASK)

#define APBH_CH9_CMD_SEMAPHORE_MASK              (0x40U)
#define APBH_CH9_CMD_SEMAPHORE_SHIFT             (6U)
#define APBH_CH9_CMD_SEMAPHORE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH9_CMD_SEMAPHORE_SHIFT)) & APBH_CH9_CMD_SEMAPHORE_MASK)

#define APBH_CH9_CMD_WAIT4ENDCMD_MASK            (0x80U)
#define APBH_CH9_CMD_WAIT4ENDCMD_SHIFT           (7U)
#define APBH_CH9_CMD_WAIT4ENDCMD(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH9_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH9_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH9_CMD_HALTONTERMINATE_MASK        (0x100U)
#define APBH_CH9_CMD_HALTONTERMINATE_SHIFT       (8U)
#define APBH_CH9_CMD_HALTONTERMINATE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH9_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH9_CMD_HALTONTERMINATE_MASK)

#define APBH_CH9_CMD_CMDWORDS_MASK               (0xF000U)
#define APBH_CH9_CMD_CMDWORDS_SHIFT              (12U)
#define APBH_CH9_CMD_CMDWORDS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH9_CMD_CMDWORDS_SHIFT)) & APBH_CH9_CMD_CMDWORDS_MASK)

#define APBH_CH9_CMD_XFER_COUNT_MASK             (0xFFFF0000U)
#define APBH_CH9_CMD_XFER_COUNT_SHIFT            (16U)
#define APBH_CH9_CMD_XFER_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH9_CMD_XFER_COUNT_SHIFT)) & APBH_CH9_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH9_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH9_BAR_ADDRESS_MASK                (0xFFFFFFFFU)
#define APBH_CH9_BAR_ADDRESS_SHIFT               (0U)
#define APBH_CH9_BAR_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH9_BAR_ADDRESS_SHIFT)) & APBH_CH9_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH9_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH9_SEMA_INCREMENT_SEMA_MASK        (0xFFU)
#define APBH_CH9_SEMA_INCREMENT_SEMA_SHIFT       (0U)
#define APBH_CH9_SEMA_INCREMENT_SEMA(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH9_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH9_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH9_SEMA_PHORE_MASK                 (0xFF0000U)
#define APBH_CH9_SEMA_PHORE_SHIFT                (16U)
#define APBH_CH9_SEMA_PHORE(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH9_SEMA_PHORE_SHIFT)) & APBH_CH9_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH9_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH9_DEBUG1_STATEMACHINE_MASK        (0x1FU)
#define APBH_CH9_DEBUG1_STATEMACHINE_SHIFT       (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH9_DEBUG1_STATEMACHINE(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH9_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH9_DEBUG1_RSVD1_MASK               (0xFFFE0U)
#define APBH_CH9_DEBUG1_RSVD1_SHIFT              (5U)
#define APBH_CH9_DEBUG1_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG1_RSVD1_SHIFT)) & APBH_CH9_DEBUG1_RSVD1_MASK)

#define APBH_CH9_DEBUG1_WR_FIFO_FULL_MASK        (0x100000U)
#define APBH_CH9_DEBUG1_WR_FIFO_FULL_SHIFT       (20U)
#define APBH_CH9_DEBUG1_WR_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH9_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH9_DEBUG1_WR_FIFO_EMPTY_MASK       (0x200000U)
#define APBH_CH9_DEBUG1_WR_FIFO_EMPTY_SHIFT      (21U)
#define APBH_CH9_DEBUG1_WR_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH9_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH9_DEBUG1_RD_FIFO_FULL_MASK        (0x400000U)
#define APBH_CH9_DEBUG1_RD_FIFO_FULL_SHIFT       (22U)
#define APBH_CH9_DEBUG1_RD_FIFO_FULL(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH9_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH9_DEBUG1_RD_FIFO_EMPTY_MASK       (0x800000U)
#define APBH_CH9_DEBUG1_RD_FIFO_EMPTY_SHIFT      (23U)
#define APBH_CH9_DEBUG1_RD_FIFO_EMPTY(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH9_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH9_DEBUG1_NEXTCMDADDRVALID_MASK    (0x1000000U)
#define APBH_CH9_DEBUG1_NEXTCMDADDRVALID_SHIFT   (24U)
#define APBH_CH9_DEBUG1_NEXTCMDADDRVALID(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH9_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH9_DEBUG1_LOCK_MASK                (0x2000000U)
#define APBH_CH9_DEBUG1_LOCK_SHIFT               (25U)
#define APBH_CH9_DEBUG1_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG1_LOCK_SHIFT)) & APBH_CH9_DEBUG1_LOCK_MASK)

#define APBH_CH9_DEBUG1_READY_MASK               (0x4000000U)
#define APBH_CH9_DEBUG1_READY_SHIFT              (26U)
#define APBH_CH9_DEBUG1_READY(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG1_READY_SHIFT)) & APBH_CH9_DEBUG1_READY_MASK)

#define APBH_CH9_DEBUG1_SENSE_MASK               (0x8000000U)
#define APBH_CH9_DEBUG1_SENSE_SHIFT              (27U)
#define APBH_CH9_DEBUG1_SENSE(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG1_SENSE_SHIFT)) & APBH_CH9_DEBUG1_SENSE_MASK)

#define APBH_CH9_DEBUG1_END_MASK                 (0x10000000U)
#define APBH_CH9_DEBUG1_END_SHIFT                (28U)
#define APBH_CH9_DEBUG1_END(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG1_END_SHIFT)) & APBH_CH9_DEBUG1_END_MASK)

#define APBH_CH9_DEBUG1_KICK_MASK                (0x20000000U)
#define APBH_CH9_DEBUG1_KICK_SHIFT               (29U)
#define APBH_CH9_DEBUG1_KICK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG1_KICK_SHIFT)) & APBH_CH9_DEBUG1_KICK_MASK)

#define APBH_CH9_DEBUG1_BURST_MASK               (0x40000000U)
#define APBH_CH9_DEBUG1_BURST_SHIFT              (30U)
#define APBH_CH9_DEBUG1_BURST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG1_BURST_SHIFT)) & APBH_CH9_DEBUG1_BURST_MASK)

#define APBH_CH9_DEBUG1_REQ_MASK                 (0x80000000U)
#define APBH_CH9_DEBUG1_REQ_SHIFT                (31U)
#define APBH_CH9_DEBUG1_REQ(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG1_REQ_SHIFT)) & APBH_CH9_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH9_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH9_DEBUG2_AHB_BYTES_MASK           (0xFFFFU)
#define APBH_CH9_DEBUG2_AHB_BYTES_SHIFT          (0U)
#define APBH_CH9_DEBUG2_AHB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH9_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH9_DEBUG2_APB_BYTES_MASK           (0xFFFF0000U)
#define APBH_CH9_DEBUG2_APB_BYTES_SHIFT          (16U)
#define APBH_CH9_DEBUG2_APB_BYTES(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH9_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH9_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH10_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH10_CURCMDAR_CMD_ADDR_MASK         (0xFFFFFFFFU)
#define APBH_CH10_CURCMDAR_CMD_ADDR_SHIFT        (0U)
#define APBH_CH10_CURCMDAR_CMD_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH10_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH10_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH10_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH10_NXTCMDAR_CMD_ADDR_MASK         (0xFFFFFFFFU)
#define APBH_CH10_NXTCMDAR_CMD_ADDR_SHIFT        (0U)
#define APBH_CH10_NXTCMDAR_CMD_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH10_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH10_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH10_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH10_CMD_COMMAND_MASK               (0x3U)
#define APBH_CH10_CMD_COMMAND_SHIFT              (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH10_CMD_COMMAND(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH10_CMD_COMMAND_SHIFT)) & APBH_CH10_CMD_COMMAND_MASK)

#define APBH_CH10_CMD_CHAIN_MASK                 (0x4U)
#define APBH_CH10_CMD_CHAIN_SHIFT                (2U)
#define APBH_CH10_CMD_CHAIN(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH10_CMD_CHAIN_SHIFT)) & APBH_CH10_CMD_CHAIN_MASK)

#define APBH_CH10_CMD_IRQONCMPLT_MASK            (0x8U)
#define APBH_CH10_CMD_IRQONCMPLT_SHIFT           (3U)
#define APBH_CH10_CMD_IRQONCMPLT(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH10_CMD_IRQONCMPLT_SHIFT)) & APBH_CH10_CMD_IRQONCMPLT_MASK)

#define APBH_CH10_CMD_NANDLOCK_MASK              (0x10U)
#define APBH_CH10_CMD_NANDLOCK_SHIFT             (4U)
#define APBH_CH10_CMD_NANDLOCK(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH10_CMD_NANDLOCK_SHIFT)) & APBH_CH10_CMD_NANDLOCK_MASK)

#define APBH_CH10_CMD_NANDWAIT4READY_MASK        (0x20U)
#define APBH_CH10_CMD_NANDWAIT4READY_SHIFT       (5U)
#define APBH_CH10_CMD_NANDWAIT4READY(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH10_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH10_CMD_NANDWAIT4READY_MASK)

#define APBH_CH10_CMD_SEMAPHORE_MASK             (0x40U)
#define APBH_CH10_CMD_SEMAPHORE_SHIFT            (6U)
#define APBH_CH10_CMD_SEMAPHORE(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH10_CMD_SEMAPHORE_SHIFT)) & APBH_CH10_CMD_SEMAPHORE_MASK)

#define APBH_CH10_CMD_WAIT4ENDCMD_MASK           (0x80U)
#define APBH_CH10_CMD_WAIT4ENDCMD_SHIFT          (7U)
#define APBH_CH10_CMD_WAIT4ENDCMD(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH10_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH10_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH10_CMD_HALTONTERMINATE_MASK       (0x100U)
#define APBH_CH10_CMD_HALTONTERMINATE_SHIFT      (8U)
#define APBH_CH10_CMD_HALTONTERMINATE(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH10_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH10_CMD_HALTONTERMINATE_MASK)

#define APBH_CH10_CMD_CMDWORDS_MASK              (0xF000U)
#define APBH_CH10_CMD_CMDWORDS_SHIFT             (12U)
#define APBH_CH10_CMD_CMDWORDS(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH10_CMD_CMDWORDS_SHIFT)) & APBH_CH10_CMD_CMDWORDS_MASK)

#define APBH_CH10_CMD_XFER_COUNT_MASK            (0xFFFF0000U)
#define APBH_CH10_CMD_XFER_COUNT_SHIFT           (16U)
#define APBH_CH10_CMD_XFER_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH10_CMD_XFER_COUNT_SHIFT)) & APBH_CH10_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH10_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH10_BAR_ADDRESS_MASK               (0xFFFFFFFFU)
#define APBH_CH10_BAR_ADDRESS_SHIFT              (0U)
#define APBH_CH10_BAR_ADDRESS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH10_BAR_ADDRESS_SHIFT)) & APBH_CH10_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH10_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH10_SEMA_INCREMENT_SEMA_MASK       (0xFFU)
#define APBH_CH10_SEMA_INCREMENT_SEMA_SHIFT      (0U)
#define APBH_CH10_SEMA_INCREMENT_SEMA(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH10_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH10_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH10_SEMA_PHORE_MASK                (0xFF0000U)
#define APBH_CH10_SEMA_PHORE_SHIFT               (16U)
#define APBH_CH10_SEMA_PHORE(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH10_SEMA_PHORE_SHIFT)) & APBH_CH10_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH10_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH10_DEBUG1_STATEMACHINE_MASK       (0x1FU)
#define APBH_CH10_DEBUG1_STATEMACHINE_SHIFT      (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH10_DEBUG1_STATEMACHINE(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH10_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH10_DEBUG1_RSVD1_MASK              (0xFFFE0U)
#define APBH_CH10_DEBUG1_RSVD1_SHIFT             (5U)
#define APBH_CH10_DEBUG1_RSVD1(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG1_RSVD1_SHIFT)) & APBH_CH10_DEBUG1_RSVD1_MASK)

#define APBH_CH10_DEBUG1_WR_FIFO_FULL_MASK       (0x100000U)
#define APBH_CH10_DEBUG1_WR_FIFO_FULL_SHIFT      (20U)
#define APBH_CH10_DEBUG1_WR_FIFO_FULL(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH10_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH10_DEBUG1_WR_FIFO_EMPTY_MASK      (0x200000U)
#define APBH_CH10_DEBUG1_WR_FIFO_EMPTY_SHIFT     (21U)
#define APBH_CH10_DEBUG1_WR_FIFO_EMPTY(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH10_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH10_DEBUG1_RD_FIFO_FULL_MASK       (0x400000U)
#define APBH_CH10_DEBUG1_RD_FIFO_FULL_SHIFT      (22U)
#define APBH_CH10_DEBUG1_RD_FIFO_FULL(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH10_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH10_DEBUG1_RD_FIFO_EMPTY_MASK      (0x800000U)
#define APBH_CH10_DEBUG1_RD_FIFO_EMPTY_SHIFT     (23U)
#define APBH_CH10_DEBUG1_RD_FIFO_EMPTY(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH10_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH10_DEBUG1_NEXTCMDADDRVALID_MASK   (0x1000000U)
#define APBH_CH10_DEBUG1_NEXTCMDADDRVALID_SHIFT  (24U)
#define APBH_CH10_DEBUG1_NEXTCMDADDRVALID(x)     (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH10_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH10_DEBUG1_LOCK_MASK               (0x2000000U)
#define APBH_CH10_DEBUG1_LOCK_SHIFT              (25U)
#define APBH_CH10_DEBUG1_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG1_LOCK_SHIFT)) & APBH_CH10_DEBUG1_LOCK_MASK)

#define APBH_CH10_DEBUG1_READY_MASK              (0x4000000U)
#define APBH_CH10_DEBUG1_READY_SHIFT             (26U)
#define APBH_CH10_DEBUG1_READY(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG1_READY_SHIFT)) & APBH_CH10_DEBUG1_READY_MASK)

#define APBH_CH10_DEBUG1_SENSE_MASK              (0x8000000U)
#define APBH_CH10_DEBUG1_SENSE_SHIFT             (27U)
#define APBH_CH10_DEBUG1_SENSE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG1_SENSE_SHIFT)) & APBH_CH10_DEBUG1_SENSE_MASK)

#define APBH_CH10_DEBUG1_END_MASK                (0x10000000U)
#define APBH_CH10_DEBUG1_END_SHIFT               (28U)
#define APBH_CH10_DEBUG1_END(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG1_END_SHIFT)) & APBH_CH10_DEBUG1_END_MASK)

#define APBH_CH10_DEBUG1_KICK_MASK               (0x20000000U)
#define APBH_CH10_DEBUG1_KICK_SHIFT              (29U)
#define APBH_CH10_DEBUG1_KICK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG1_KICK_SHIFT)) & APBH_CH10_DEBUG1_KICK_MASK)

#define APBH_CH10_DEBUG1_BURST_MASK              (0x40000000U)
#define APBH_CH10_DEBUG1_BURST_SHIFT             (30U)
#define APBH_CH10_DEBUG1_BURST(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG1_BURST_SHIFT)) & APBH_CH10_DEBUG1_BURST_MASK)

#define APBH_CH10_DEBUG1_REQ_MASK                (0x80000000U)
#define APBH_CH10_DEBUG1_REQ_SHIFT               (31U)
#define APBH_CH10_DEBUG1_REQ(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG1_REQ_SHIFT)) & APBH_CH10_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH10_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH10_DEBUG2_AHB_BYTES_MASK          (0xFFFFU)
#define APBH_CH10_DEBUG2_AHB_BYTES_SHIFT         (0U)
#define APBH_CH10_DEBUG2_AHB_BYTES(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH10_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH10_DEBUG2_APB_BYTES_MASK          (0xFFFF0000U)
#define APBH_CH10_DEBUG2_APB_BYTES_SHIFT         (16U)
#define APBH_CH10_DEBUG2_APB_BYTES(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH10_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH10_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH11_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH11_CURCMDAR_CMD_ADDR_MASK         (0xFFFFFFFFU)
#define APBH_CH11_CURCMDAR_CMD_ADDR_SHIFT        (0U)
#define APBH_CH11_CURCMDAR_CMD_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH11_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH11_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH11_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH11_NXTCMDAR_CMD_ADDR_MASK         (0xFFFFFFFFU)
#define APBH_CH11_NXTCMDAR_CMD_ADDR_SHIFT        (0U)
#define APBH_CH11_NXTCMDAR_CMD_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH11_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH11_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH11_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH11_CMD_COMMAND_MASK               (0x3U)
#define APBH_CH11_CMD_COMMAND_SHIFT              (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH11_CMD_COMMAND(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH11_CMD_COMMAND_SHIFT)) & APBH_CH11_CMD_COMMAND_MASK)

#define APBH_CH11_CMD_CHAIN_MASK                 (0x4U)
#define APBH_CH11_CMD_CHAIN_SHIFT                (2U)
#define APBH_CH11_CMD_CHAIN(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH11_CMD_CHAIN_SHIFT)) & APBH_CH11_CMD_CHAIN_MASK)

#define APBH_CH11_CMD_IRQONCMPLT_MASK            (0x8U)
#define APBH_CH11_CMD_IRQONCMPLT_SHIFT           (3U)
#define APBH_CH11_CMD_IRQONCMPLT(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH11_CMD_IRQONCMPLT_SHIFT)) & APBH_CH11_CMD_IRQONCMPLT_MASK)

#define APBH_CH11_CMD_NANDLOCK_MASK              (0x10U)
#define APBH_CH11_CMD_NANDLOCK_SHIFT             (4U)
#define APBH_CH11_CMD_NANDLOCK(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH11_CMD_NANDLOCK_SHIFT)) & APBH_CH11_CMD_NANDLOCK_MASK)

#define APBH_CH11_CMD_NANDWAIT4READY_MASK        (0x20U)
#define APBH_CH11_CMD_NANDWAIT4READY_SHIFT       (5U)
#define APBH_CH11_CMD_NANDWAIT4READY(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH11_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH11_CMD_NANDWAIT4READY_MASK)

#define APBH_CH11_CMD_SEMAPHORE_MASK             (0x40U)
#define APBH_CH11_CMD_SEMAPHORE_SHIFT            (6U)
#define APBH_CH11_CMD_SEMAPHORE(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH11_CMD_SEMAPHORE_SHIFT)) & APBH_CH11_CMD_SEMAPHORE_MASK)

#define APBH_CH11_CMD_WAIT4ENDCMD_MASK           (0x80U)
#define APBH_CH11_CMD_WAIT4ENDCMD_SHIFT          (7U)
#define APBH_CH11_CMD_WAIT4ENDCMD(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH11_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH11_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH11_CMD_HALTONTERMINATE_MASK       (0x100U)
#define APBH_CH11_CMD_HALTONTERMINATE_SHIFT      (8U)
#define APBH_CH11_CMD_HALTONTERMINATE(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH11_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH11_CMD_HALTONTERMINATE_MASK)

#define APBH_CH11_CMD_CMDWORDS_MASK              (0xF000U)
#define APBH_CH11_CMD_CMDWORDS_SHIFT             (12U)
#define APBH_CH11_CMD_CMDWORDS(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH11_CMD_CMDWORDS_SHIFT)) & APBH_CH11_CMD_CMDWORDS_MASK)

#define APBH_CH11_CMD_XFER_COUNT_MASK            (0xFFFF0000U)
#define APBH_CH11_CMD_XFER_COUNT_SHIFT           (16U)
#define APBH_CH11_CMD_XFER_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH11_CMD_XFER_COUNT_SHIFT)) & APBH_CH11_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH11_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH11_BAR_ADDRESS_MASK               (0xFFFFFFFFU)
#define APBH_CH11_BAR_ADDRESS_SHIFT              (0U)
#define APBH_CH11_BAR_ADDRESS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH11_BAR_ADDRESS_SHIFT)) & APBH_CH11_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH11_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH11_SEMA_INCREMENT_SEMA_MASK       (0xFFU)
#define APBH_CH11_SEMA_INCREMENT_SEMA_SHIFT      (0U)
#define APBH_CH11_SEMA_INCREMENT_SEMA(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH11_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH11_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH11_SEMA_PHORE_MASK                (0xFF0000U)
#define APBH_CH11_SEMA_PHORE_SHIFT               (16U)
#define APBH_CH11_SEMA_PHORE(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH11_SEMA_PHORE_SHIFT)) & APBH_CH11_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH11_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH11_DEBUG1_STATEMACHINE_MASK       (0x1FU)
#define APBH_CH11_DEBUG1_STATEMACHINE_SHIFT      (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH11_DEBUG1_STATEMACHINE(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH11_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH11_DEBUG1_RSVD1_MASK              (0xFFFE0U)
#define APBH_CH11_DEBUG1_RSVD1_SHIFT             (5U)
#define APBH_CH11_DEBUG1_RSVD1(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG1_RSVD1_SHIFT)) & APBH_CH11_DEBUG1_RSVD1_MASK)

#define APBH_CH11_DEBUG1_WR_FIFO_FULL_MASK       (0x100000U)
#define APBH_CH11_DEBUG1_WR_FIFO_FULL_SHIFT      (20U)
#define APBH_CH11_DEBUG1_WR_FIFO_FULL(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH11_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH11_DEBUG1_WR_FIFO_EMPTY_MASK      (0x200000U)
#define APBH_CH11_DEBUG1_WR_FIFO_EMPTY_SHIFT     (21U)
#define APBH_CH11_DEBUG1_WR_FIFO_EMPTY(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH11_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH11_DEBUG1_RD_FIFO_FULL_MASK       (0x400000U)
#define APBH_CH11_DEBUG1_RD_FIFO_FULL_SHIFT      (22U)
#define APBH_CH11_DEBUG1_RD_FIFO_FULL(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH11_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH11_DEBUG1_RD_FIFO_EMPTY_MASK      (0x800000U)
#define APBH_CH11_DEBUG1_RD_FIFO_EMPTY_SHIFT     (23U)
#define APBH_CH11_DEBUG1_RD_FIFO_EMPTY(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH11_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH11_DEBUG1_NEXTCMDADDRVALID_MASK   (0x1000000U)
#define APBH_CH11_DEBUG1_NEXTCMDADDRVALID_SHIFT  (24U)
#define APBH_CH11_DEBUG1_NEXTCMDADDRVALID(x)     (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH11_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH11_DEBUG1_LOCK_MASK               (0x2000000U)
#define APBH_CH11_DEBUG1_LOCK_SHIFT              (25U)
#define APBH_CH11_DEBUG1_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG1_LOCK_SHIFT)) & APBH_CH11_DEBUG1_LOCK_MASK)

#define APBH_CH11_DEBUG1_READY_MASK              (0x4000000U)
#define APBH_CH11_DEBUG1_READY_SHIFT             (26U)
#define APBH_CH11_DEBUG1_READY(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG1_READY_SHIFT)) & APBH_CH11_DEBUG1_READY_MASK)

#define APBH_CH11_DEBUG1_SENSE_MASK              (0x8000000U)
#define APBH_CH11_DEBUG1_SENSE_SHIFT             (27U)
#define APBH_CH11_DEBUG1_SENSE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG1_SENSE_SHIFT)) & APBH_CH11_DEBUG1_SENSE_MASK)

#define APBH_CH11_DEBUG1_END_MASK                (0x10000000U)
#define APBH_CH11_DEBUG1_END_SHIFT               (28U)
#define APBH_CH11_DEBUG1_END(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG1_END_SHIFT)) & APBH_CH11_DEBUG1_END_MASK)

#define APBH_CH11_DEBUG1_KICK_MASK               (0x20000000U)
#define APBH_CH11_DEBUG1_KICK_SHIFT              (29U)
#define APBH_CH11_DEBUG1_KICK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG1_KICK_SHIFT)) & APBH_CH11_DEBUG1_KICK_MASK)

#define APBH_CH11_DEBUG1_BURST_MASK              (0x40000000U)
#define APBH_CH11_DEBUG1_BURST_SHIFT             (30U)
#define APBH_CH11_DEBUG1_BURST(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG1_BURST_SHIFT)) & APBH_CH11_DEBUG1_BURST_MASK)

#define APBH_CH11_DEBUG1_REQ_MASK                (0x80000000U)
#define APBH_CH11_DEBUG1_REQ_SHIFT               (31U)
#define APBH_CH11_DEBUG1_REQ(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG1_REQ_SHIFT)) & APBH_CH11_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH11_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH11_DEBUG2_AHB_BYTES_MASK          (0xFFFFU)
#define APBH_CH11_DEBUG2_AHB_BYTES_SHIFT         (0U)
#define APBH_CH11_DEBUG2_AHB_BYTES(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH11_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH11_DEBUG2_APB_BYTES_MASK          (0xFFFF0000U)
#define APBH_CH11_DEBUG2_APB_BYTES_SHIFT         (16U)
#define APBH_CH11_DEBUG2_APB_BYTES(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH11_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH11_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH12_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH12_CURCMDAR_CMD_ADDR_MASK         (0xFFFFFFFFU)
#define APBH_CH12_CURCMDAR_CMD_ADDR_SHIFT        (0U)
#define APBH_CH12_CURCMDAR_CMD_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH12_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH12_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH12_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH12_NXTCMDAR_CMD_ADDR_MASK         (0xFFFFFFFFU)
#define APBH_CH12_NXTCMDAR_CMD_ADDR_SHIFT        (0U)
#define APBH_CH12_NXTCMDAR_CMD_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH12_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH12_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH12_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH12_CMD_COMMAND_MASK               (0x3U)
#define APBH_CH12_CMD_COMMAND_SHIFT              (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH12_CMD_COMMAND(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH12_CMD_COMMAND_SHIFT)) & APBH_CH12_CMD_COMMAND_MASK)

#define APBH_CH12_CMD_CHAIN_MASK                 (0x4U)
#define APBH_CH12_CMD_CHAIN_SHIFT                (2U)
#define APBH_CH12_CMD_CHAIN(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH12_CMD_CHAIN_SHIFT)) & APBH_CH12_CMD_CHAIN_MASK)

#define APBH_CH12_CMD_IRQONCMPLT_MASK            (0x8U)
#define APBH_CH12_CMD_IRQONCMPLT_SHIFT           (3U)
#define APBH_CH12_CMD_IRQONCMPLT(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH12_CMD_IRQONCMPLT_SHIFT)) & APBH_CH12_CMD_IRQONCMPLT_MASK)

#define APBH_CH12_CMD_NANDLOCK_MASK              (0x10U)
#define APBH_CH12_CMD_NANDLOCK_SHIFT             (4U)
#define APBH_CH12_CMD_NANDLOCK(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH12_CMD_NANDLOCK_SHIFT)) & APBH_CH12_CMD_NANDLOCK_MASK)

#define APBH_CH12_CMD_NANDWAIT4READY_MASK        (0x20U)
#define APBH_CH12_CMD_NANDWAIT4READY_SHIFT       (5U)
#define APBH_CH12_CMD_NANDWAIT4READY(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH12_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH12_CMD_NANDWAIT4READY_MASK)

#define APBH_CH12_CMD_SEMAPHORE_MASK             (0x40U)
#define APBH_CH12_CMD_SEMAPHORE_SHIFT            (6U)
#define APBH_CH12_CMD_SEMAPHORE(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH12_CMD_SEMAPHORE_SHIFT)) & APBH_CH12_CMD_SEMAPHORE_MASK)

#define APBH_CH12_CMD_WAIT4ENDCMD_MASK           (0x80U)
#define APBH_CH12_CMD_WAIT4ENDCMD_SHIFT          (7U)
#define APBH_CH12_CMD_WAIT4ENDCMD(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH12_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH12_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH12_CMD_HALTONTERMINATE_MASK       (0x100U)
#define APBH_CH12_CMD_HALTONTERMINATE_SHIFT      (8U)
#define APBH_CH12_CMD_HALTONTERMINATE(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH12_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH12_CMD_HALTONTERMINATE_MASK)

#define APBH_CH12_CMD_CMDWORDS_MASK              (0xF000U)
#define APBH_CH12_CMD_CMDWORDS_SHIFT             (12U)
#define APBH_CH12_CMD_CMDWORDS(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH12_CMD_CMDWORDS_SHIFT)) & APBH_CH12_CMD_CMDWORDS_MASK)

#define APBH_CH12_CMD_XFER_COUNT_MASK            (0xFFFF0000U)
#define APBH_CH12_CMD_XFER_COUNT_SHIFT           (16U)
#define APBH_CH12_CMD_XFER_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH12_CMD_XFER_COUNT_SHIFT)) & APBH_CH12_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH12_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH12_BAR_ADDRESS_MASK               (0xFFFFFFFFU)
#define APBH_CH12_BAR_ADDRESS_SHIFT              (0U)
#define APBH_CH12_BAR_ADDRESS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH12_BAR_ADDRESS_SHIFT)) & APBH_CH12_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH12_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH12_SEMA_INCREMENT_SEMA_MASK       (0xFFU)
#define APBH_CH12_SEMA_INCREMENT_SEMA_SHIFT      (0U)
#define APBH_CH12_SEMA_INCREMENT_SEMA(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH12_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH12_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH12_SEMA_PHORE_MASK                (0xFF0000U)
#define APBH_CH12_SEMA_PHORE_SHIFT               (16U)
#define APBH_CH12_SEMA_PHORE(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH12_SEMA_PHORE_SHIFT)) & APBH_CH12_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH12_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH12_DEBUG1_STATEMACHINE_MASK       (0x1FU)
#define APBH_CH12_DEBUG1_STATEMACHINE_SHIFT      (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH12_DEBUG1_STATEMACHINE(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH12_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH12_DEBUG1_RSVD1_MASK              (0xFFFE0U)
#define APBH_CH12_DEBUG1_RSVD1_SHIFT             (5U)
#define APBH_CH12_DEBUG1_RSVD1(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG1_RSVD1_SHIFT)) & APBH_CH12_DEBUG1_RSVD1_MASK)

#define APBH_CH12_DEBUG1_WR_FIFO_FULL_MASK       (0x100000U)
#define APBH_CH12_DEBUG1_WR_FIFO_FULL_SHIFT      (20U)
#define APBH_CH12_DEBUG1_WR_FIFO_FULL(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH12_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH12_DEBUG1_WR_FIFO_EMPTY_MASK      (0x200000U)
#define APBH_CH12_DEBUG1_WR_FIFO_EMPTY_SHIFT     (21U)
#define APBH_CH12_DEBUG1_WR_FIFO_EMPTY(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH12_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH12_DEBUG1_RD_FIFO_FULL_MASK       (0x400000U)
#define APBH_CH12_DEBUG1_RD_FIFO_FULL_SHIFT      (22U)
#define APBH_CH12_DEBUG1_RD_FIFO_FULL(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH12_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH12_DEBUG1_RD_FIFO_EMPTY_MASK      (0x800000U)
#define APBH_CH12_DEBUG1_RD_FIFO_EMPTY_SHIFT     (23U)
#define APBH_CH12_DEBUG1_RD_FIFO_EMPTY(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH12_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH12_DEBUG1_NEXTCMDADDRVALID_MASK   (0x1000000U)
#define APBH_CH12_DEBUG1_NEXTCMDADDRVALID_SHIFT  (24U)
#define APBH_CH12_DEBUG1_NEXTCMDADDRVALID(x)     (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH12_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH12_DEBUG1_LOCK_MASK               (0x2000000U)
#define APBH_CH12_DEBUG1_LOCK_SHIFT              (25U)
#define APBH_CH12_DEBUG1_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG1_LOCK_SHIFT)) & APBH_CH12_DEBUG1_LOCK_MASK)

#define APBH_CH12_DEBUG1_READY_MASK              (0x4000000U)
#define APBH_CH12_DEBUG1_READY_SHIFT             (26U)
#define APBH_CH12_DEBUG1_READY(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG1_READY_SHIFT)) & APBH_CH12_DEBUG1_READY_MASK)

#define APBH_CH12_DEBUG1_SENSE_MASK              (0x8000000U)
#define APBH_CH12_DEBUG1_SENSE_SHIFT             (27U)
#define APBH_CH12_DEBUG1_SENSE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG1_SENSE_SHIFT)) & APBH_CH12_DEBUG1_SENSE_MASK)

#define APBH_CH12_DEBUG1_END_MASK                (0x10000000U)
#define APBH_CH12_DEBUG1_END_SHIFT               (28U)
#define APBH_CH12_DEBUG1_END(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG1_END_SHIFT)) & APBH_CH12_DEBUG1_END_MASK)

#define APBH_CH12_DEBUG1_KICK_MASK               (0x20000000U)
#define APBH_CH12_DEBUG1_KICK_SHIFT              (29U)
#define APBH_CH12_DEBUG1_KICK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG1_KICK_SHIFT)) & APBH_CH12_DEBUG1_KICK_MASK)

#define APBH_CH12_DEBUG1_BURST_MASK              (0x40000000U)
#define APBH_CH12_DEBUG1_BURST_SHIFT             (30U)
#define APBH_CH12_DEBUG1_BURST(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG1_BURST_SHIFT)) & APBH_CH12_DEBUG1_BURST_MASK)

#define APBH_CH12_DEBUG1_REQ_MASK                (0x80000000U)
#define APBH_CH12_DEBUG1_REQ_SHIFT               (31U)
#define APBH_CH12_DEBUG1_REQ(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG1_REQ_SHIFT)) & APBH_CH12_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH12_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH12_DEBUG2_AHB_BYTES_MASK          (0xFFFFU)
#define APBH_CH12_DEBUG2_AHB_BYTES_SHIFT         (0U)
#define APBH_CH12_DEBUG2_AHB_BYTES(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH12_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH12_DEBUG2_APB_BYTES_MASK          (0xFFFF0000U)
#define APBH_CH12_DEBUG2_APB_BYTES_SHIFT         (16U)
#define APBH_CH12_DEBUG2_APB_BYTES(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH12_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH12_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH13_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH13_CURCMDAR_CMD_ADDR_MASK         (0xFFFFFFFFU)
#define APBH_CH13_CURCMDAR_CMD_ADDR_SHIFT        (0U)
#define APBH_CH13_CURCMDAR_CMD_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH13_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH13_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH13_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH13_NXTCMDAR_CMD_ADDR_MASK         (0xFFFFFFFFU)
#define APBH_CH13_NXTCMDAR_CMD_ADDR_SHIFT        (0U)
#define APBH_CH13_NXTCMDAR_CMD_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH13_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH13_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH13_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH13_CMD_COMMAND_MASK               (0x3U)
#define APBH_CH13_CMD_COMMAND_SHIFT              (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH13_CMD_COMMAND(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH13_CMD_COMMAND_SHIFT)) & APBH_CH13_CMD_COMMAND_MASK)

#define APBH_CH13_CMD_CHAIN_MASK                 (0x4U)
#define APBH_CH13_CMD_CHAIN_SHIFT                (2U)
#define APBH_CH13_CMD_CHAIN(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH13_CMD_CHAIN_SHIFT)) & APBH_CH13_CMD_CHAIN_MASK)

#define APBH_CH13_CMD_IRQONCMPLT_MASK            (0x8U)
#define APBH_CH13_CMD_IRQONCMPLT_SHIFT           (3U)
#define APBH_CH13_CMD_IRQONCMPLT(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH13_CMD_IRQONCMPLT_SHIFT)) & APBH_CH13_CMD_IRQONCMPLT_MASK)

#define APBH_CH13_CMD_NANDLOCK_MASK              (0x10U)
#define APBH_CH13_CMD_NANDLOCK_SHIFT             (4U)
#define APBH_CH13_CMD_NANDLOCK(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH13_CMD_NANDLOCK_SHIFT)) & APBH_CH13_CMD_NANDLOCK_MASK)

#define APBH_CH13_CMD_NANDWAIT4READY_MASK        (0x20U)
#define APBH_CH13_CMD_NANDWAIT4READY_SHIFT       (5U)
#define APBH_CH13_CMD_NANDWAIT4READY(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH13_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH13_CMD_NANDWAIT4READY_MASK)

#define APBH_CH13_CMD_SEMAPHORE_MASK             (0x40U)
#define APBH_CH13_CMD_SEMAPHORE_SHIFT            (6U)
#define APBH_CH13_CMD_SEMAPHORE(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH13_CMD_SEMAPHORE_SHIFT)) & APBH_CH13_CMD_SEMAPHORE_MASK)

#define APBH_CH13_CMD_WAIT4ENDCMD_MASK           (0x80U)
#define APBH_CH13_CMD_WAIT4ENDCMD_SHIFT          (7U)
#define APBH_CH13_CMD_WAIT4ENDCMD(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH13_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH13_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH13_CMD_HALTONTERMINATE_MASK       (0x100U)
#define APBH_CH13_CMD_HALTONTERMINATE_SHIFT      (8U)
#define APBH_CH13_CMD_HALTONTERMINATE(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH13_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH13_CMD_HALTONTERMINATE_MASK)

#define APBH_CH13_CMD_CMDWORDS_MASK              (0xF000U)
#define APBH_CH13_CMD_CMDWORDS_SHIFT             (12U)
#define APBH_CH13_CMD_CMDWORDS(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH13_CMD_CMDWORDS_SHIFT)) & APBH_CH13_CMD_CMDWORDS_MASK)

#define APBH_CH13_CMD_XFER_COUNT_MASK            (0xFFFF0000U)
#define APBH_CH13_CMD_XFER_COUNT_SHIFT           (16U)
#define APBH_CH13_CMD_XFER_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH13_CMD_XFER_COUNT_SHIFT)) & APBH_CH13_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH13_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH13_BAR_ADDRESS_MASK               (0xFFFFFFFFU)
#define APBH_CH13_BAR_ADDRESS_SHIFT              (0U)
#define APBH_CH13_BAR_ADDRESS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH13_BAR_ADDRESS_SHIFT)) & APBH_CH13_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH13_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH13_SEMA_INCREMENT_SEMA_MASK       (0xFFU)
#define APBH_CH13_SEMA_INCREMENT_SEMA_SHIFT      (0U)
#define APBH_CH13_SEMA_INCREMENT_SEMA(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH13_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH13_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH13_SEMA_PHORE_MASK                (0xFF0000U)
#define APBH_CH13_SEMA_PHORE_SHIFT               (16U)
#define APBH_CH13_SEMA_PHORE(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH13_SEMA_PHORE_SHIFT)) & APBH_CH13_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH13_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH13_DEBUG1_STATEMACHINE_MASK       (0x1FU)
#define APBH_CH13_DEBUG1_STATEMACHINE_SHIFT      (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH13_DEBUG1_STATEMACHINE(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH13_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH13_DEBUG1_RSVD1_MASK              (0xFFFE0U)
#define APBH_CH13_DEBUG1_RSVD1_SHIFT             (5U)
#define APBH_CH13_DEBUG1_RSVD1(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG1_RSVD1_SHIFT)) & APBH_CH13_DEBUG1_RSVD1_MASK)

#define APBH_CH13_DEBUG1_WR_FIFO_FULL_MASK       (0x100000U)
#define APBH_CH13_DEBUG1_WR_FIFO_FULL_SHIFT      (20U)
#define APBH_CH13_DEBUG1_WR_FIFO_FULL(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH13_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH13_DEBUG1_WR_FIFO_EMPTY_MASK      (0x200000U)
#define APBH_CH13_DEBUG1_WR_FIFO_EMPTY_SHIFT     (21U)
#define APBH_CH13_DEBUG1_WR_FIFO_EMPTY(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH13_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH13_DEBUG1_RD_FIFO_FULL_MASK       (0x400000U)
#define APBH_CH13_DEBUG1_RD_FIFO_FULL_SHIFT      (22U)
#define APBH_CH13_DEBUG1_RD_FIFO_FULL(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH13_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH13_DEBUG1_RD_FIFO_EMPTY_MASK      (0x800000U)
#define APBH_CH13_DEBUG1_RD_FIFO_EMPTY_SHIFT     (23U)
#define APBH_CH13_DEBUG1_RD_FIFO_EMPTY(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH13_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH13_DEBUG1_NEXTCMDADDRVALID_MASK   (0x1000000U)
#define APBH_CH13_DEBUG1_NEXTCMDADDRVALID_SHIFT  (24U)
#define APBH_CH13_DEBUG1_NEXTCMDADDRVALID(x)     (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH13_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH13_DEBUG1_LOCK_MASK               (0x2000000U)
#define APBH_CH13_DEBUG1_LOCK_SHIFT              (25U)
#define APBH_CH13_DEBUG1_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG1_LOCK_SHIFT)) & APBH_CH13_DEBUG1_LOCK_MASK)

#define APBH_CH13_DEBUG1_READY_MASK              (0x4000000U)
#define APBH_CH13_DEBUG1_READY_SHIFT             (26U)
#define APBH_CH13_DEBUG1_READY(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG1_READY_SHIFT)) & APBH_CH13_DEBUG1_READY_MASK)

#define APBH_CH13_DEBUG1_SENSE_MASK              (0x8000000U)
#define APBH_CH13_DEBUG1_SENSE_SHIFT             (27U)
#define APBH_CH13_DEBUG1_SENSE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG1_SENSE_SHIFT)) & APBH_CH13_DEBUG1_SENSE_MASK)

#define APBH_CH13_DEBUG1_END_MASK                (0x10000000U)
#define APBH_CH13_DEBUG1_END_SHIFT               (28U)
#define APBH_CH13_DEBUG1_END(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG1_END_SHIFT)) & APBH_CH13_DEBUG1_END_MASK)

#define APBH_CH13_DEBUG1_KICK_MASK               (0x20000000U)
#define APBH_CH13_DEBUG1_KICK_SHIFT              (29U)
#define APBH_CH13_DEBUG1_KICK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG1_KICK_SHIFT)) & APBH_CH13_DEBUG1_KICK_MASK)

#define APBH_CH13_DEBUG1_BURST_MASK              (0x40000000U)
#define APBH_CH13_DEBUG1_BURST_SHIFT             (30U)
#define APBH_CH13_DEBUG1_BURST(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG1_BURST_SHIFT)) & APBH_CH13_DEBUG1_BURST_MASK)

#define APBH_CH13_DEBUG1_REQ_MASK                (0x80000000U)
#define APBH_CH13_DEBUG1_REQ_SHIFT               (31U)
#define APBH_CH13_DEBUG1_REQ(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG1_REQ_SHIFT)) & APBH_CH13_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH13_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH13_DEBUG2_AHB_BYTES_MASK          (0xFFFFU)
#define APBH_CH13_DEBUG2_AHB_BYTES_SHIFT         (0U)
#define APBH_CH13_DEBUG2_AHB_BYTES(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH13_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH13_DEBUG2_APB_BYTES_MASK          (0xFFFF0000U)
#define APBH_CH13_DEBUG2_APB_BYTES_SHIFT         (16U)
#define APBH_CH13_DEBUG2_APB_BYTES(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH13_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH13_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH14_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH14_CURCMDAR_CMD_ADDR_MASK         (0xFFFFFFFFU)
#define APBH_CH14_CURCMDAR_CMD_ADDR_SHIFT        (0U)
#define APBH_CH14_CURCMDAR_CMD_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH14_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH14_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH14_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH14_NXTCMDAR_CMD_ADDR_MASK         (0xFFFFFFFFU)
#define APBH_CH14_NXTCMDAR_CMD_ADDR_SHIFT        (0U)
#define APBH_CH14_NXTCMDAR_CMD_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH14_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH14_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH14_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH14_CMD_COMMAND_MASK               (0x3U)
#define APBH_CH14_CMD_COMMAND_SHIFT              (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH14_CMD_COMMAND(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH14_CMD_COMMAND_SHIFT)) & APBH_CH14_CMD_COMMAND_MASK)

#define APBH_CH14_CMD_CHAIN_MASK                 (0x4U)
#define APBH_CH14_CMD_CHAIN_SHIFT                (2U)
#define APBH_CH14_CMD_CHAIN(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH14_CMD_CHAIN_SHIFT)) & APBH_CH14_CMD_CHAIN_MASK)

#define APBH_CH14_CMD_IRQONCMPLT_MASK            (0x8U)
#define APBH_CH14_CMD_IRQONCMPLT_SHIFT           (3U)
#define APBH_CH14_CMD_IRQONCMPLT(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH14_CMD_IRQONCMPLT_SHIFT)) & APBH_CH14_CMD_IRQONCMPLT_MASK)

#define APBH_CH14_CMD_NANDLOCK_MASK              (0x10U)
#define APBH_CH14_CMD_NANDLOCK_SHIFT             (4U)
#define APBH_CH14_CMD_NANDLOCK(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH14_CMD_NANDLOCK_SHIFT)) & APBH_CH14_CMD_NANDLOCK_MASK)

#define APBH_CH14_CMD_NANDWAIT4READY_MASK        (0x20U)
#define APBH_CH14_CMD_NANDWAIT4READY_SHIFT       (5U)
#define APBH_CH14_CMD_NANDWAIT4READY(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH14_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH14_CMD_NANDWAIT4READY_MASK)

#define APBH_CH14_CMD_SEMAPHORE_MASK             (0x40U)
#define APBH_CH14_CMD_SEMAPHORE_SHIFT            (6U)
#define APBH_CH14_CMD_SEMAPHORE(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH14_CMD_SEMAPHORE_SHIFT)) & APBH_CH14_CMD_SEMAPHORE_MASK)

#define APBH_CH14_CMD_WAIT4ENDCMD_MASK           (0x80U)
#define APBH_CH14_CMD_WAIT4ENDCMD_SHIFT          (7U)
#define APBH_CH14_CMD_WAIT4ENDCMD(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH14_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH14_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH14_CMD_HALTONTERMINATE_MASK       (0x100U)
#define APBH_CH14_CMD_HALTONTERMINATE_SHIFT      (8U)
#define APBH_CH14_CMD_HALTONTERMINATE(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH14_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH14_CMD_HALTONTERMINATE_MASK)

#define APBH_CH14_CMD_CMDWORDS_MASK              (0xF000U)
#define APBH_CH14_CMD_CMDWORDS_SHIFT             (12U)
#define APBH_CH14_CMD_CMDWORDS(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH14_CMD_CMDWORDS_SHIFT)) & APBH_CH14_CMD_CMDWORDS_MASK)

#define APBH_CH14_CMD_XFER_COUNT_MASK            (0xFFFF0000U)
#define APBH_CH14_CMD_XFER_COUNT_SHIFT           (16U)
#define APBH_CH14_CMD_XFER_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH14_CMD_XFER_COUNT_SHIFT)) & APBH_CH14_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH14_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH14_BAR_ADDRESS_MASK               (0xFFFFFFFFU)
#define APBH_CH14_BAR_ADDRESS_SHIFT              (0U)
#define APBH_CH14_BAR_ADDRESS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH14_BAR_ADDRESS_SHIFT)) & APBH_CH14_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH14_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH14_SEMA_INCREMENT_SEMA_MASK       (0xFFU)
#define APBH_CH14_SEMA_INCREMENT_SEMA_SHIFT      (0U)
#define APBH_CH14_SEMA_INCREMENT_SEMA(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH14_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH14_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH14_SEMA_PHORE_MASK                (0xFF0000U)
#define APBH_CH14_SEMA_PHORE_SHIFT               (16U)
#define APBH_CH14_SEMA_PHORE(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH14_SEMA_PHORE_SHIFT)) & APBH_CH14_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH14_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH14_DEBUG1_STATEMACHINE_MASK       (0x1FU)
#define APBH_CH14_DEBUG1_STATEMACHINE_SHIFT      (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH14_DEBUG1_STATEMACHINE(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH14_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH14_DEBUG1_RSVD1_MASK              (0xFFFE0U)
#define APBH_CH14_DEBUG1_RSVD1_SHIFT             (5U)
#define APBH_CH14_DEBUG1_RSVD1(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG1_RSVD1_SHIFT)) & APBH_CH14_DEBUG1_RSVD1_MASK)

#define APBH_CH14_DEBUG1_WR_FIFO_FULL_MASK       (0x100000U)
#define APBH_CH14_DEBUG1_WR_FIFO_FULL_SHIFT      (20U)
#define APBH_CH14_DEBUG1_WR_FIFO_FULL(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH14_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH14_DEBUG1_WR_FIFO_EMPTY_MASK      (0x200000U)
#define APBH_CH14_DEBUG1_WR_FIFO_EMPTY_SHIFT     (21U)
#define APBH_CH14_DEBUG1_WR_FIFO_EMPTY(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH14_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH14_DEBUG1_RD_FIFO_FULL_MASK       (0x400000U)
#define APBH_CH14_DEBUG1_RD_FIFO_FULL_SHIFT      (22U)
#define APBH_CH14_DEBUG1_RD_FIFO_FULL(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH14_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH14_DEBUG1_RD_FIFO_EMPTY_MASK      (0x800000U)
#define APBH_CH14_DEBUG1_RD_FIFO_EMPTY_SHIFT     (23U)
#define APBH_CH14_DEBUG1_RD_FIFO_EMPTY(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH14_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH14_DEBUG1_NEXTCMDADDRVALID_MASK   (0x1000000U)
#define APBH_CH14_DEBUG1_NEXTCMDADDRVALID_SHIFT  (24U)
#define APBH_CH14_DEBUG1_NEXTCMDADDRVALID(x)     (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH14_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH14_DEBUG1_LOCK_MASK               (0x2000000U)
#define APBH_CH14_DEBUG1_LOCK_SHIFT              (25U)
#define APBH_CH14_DEBUG1_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG1_LOCK_SHIFT)) & APBH_CH14_DEBUG1_LOCK_MASK)

#define APBH_CH14_DEBUG1_READY_MASK              (0x4000000U)
#define APBH_CH14_DEBUG1_READY_SHIFT             (26U)
#define APBH_CH14_DEBUG1_READY(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG1_READY_SHIFT)) & APBH_CH14_DEBUG1_READY_MASK)

#define APBH_CH14_DEBUG1_SENSE_MASK              (0x8000000U)
#define APBH_CH14_DEBUG1_SENSE_SHIFT             (27U)
#define APBH_CH14_DEBUG1_SENSE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG1_SENSE_SHIFT)) & APBH_CH14_DEBUG1_SENSE_MASK)

#define APBH_CH14_DEBUG1_END_MASK                (0x10000000U)
#define APBH_CH14_DEBUG1_END_SHIFT               (28U)
#define APBH_CH14_DEBUG1_END(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG1_END_SHIFT)) & APBH_CH14_DEBUG1_END_MASK)

#define APBH_CH14_DEBUG1_KICK_MASK               (0x20000000U)
#define APBH_CH14_DEBUG1_KICK_SHIFT              (29U)
#define APBH_CH14_DEBUG1_KICK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG1_KICK_SHIFT)) & APBH_CH14_DEBUG1_KICK_MASK)

#define APBH_CH14_DEBUG1_BURST_MASK              (0x40000000U)
#define APBH_CH14_DEBUG1_BURST_SHIFT             (30U)
#define APBH_CH14_DEBUG1_BURST(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG1_BURST_SHIFT)) & APBH_CH14_DEBUG1_BURST_MASK)

#define APBH_CH14_DEBUG1_REQ_MASK                (0x80000000U)
#define APBH_CH14_DEBUG1_REQ_SHIFT               (31U)
#define APBH_CH14_DEBUG1_REQ(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG1_REQ_SHIFT)) & APBH_CH14_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH14_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH14_DEBUG2_AHB_BYTES_MASK          (0xFFFFU)
#define APBH_CH14_DEBUG2_AHB_BYTES_SHIFT         (0U)
#define APBH_CH14_DEBUG2_AHB_BYTES(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH14_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH14_DEBUG2_APB_BYTES_MASK          (0xFFFF0000U)
#define APBH_CH14_DEBUG2_APB_BYTES_SHIFT         (16U)
#define APBH_CH14_DEBUG2_APB_BYTES(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH14_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH14_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name CH15_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH15_CURCMDAR_CMD_ADDR_MASK         (0xFFFFFFFFU)
#define APBH_CH15_CURCMDAR_CMD_ADDR_SHIFT        (0U)
#define APBH_CH15_CURCMDAR_CMD_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH15_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH15_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH15_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH15_NXTCMDAR_CMD_ADDR_MASK         (0xFFFFFFFFU)
#define APBH_CH15_NXTCMDAR_CMD_ADDR_SHIFT        (0U)
#define APBH_CH15_NXTCMDAR_CMD_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH15_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH15_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/*! @name CH15_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH15_CMD_COMMAND_MASK               (0x3U)
#define APBH_CH15_CMD_COMMAND_SHIFT              (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH15_CMD_COMMAND(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH15_CMD_COMMAND_SHIFT)) & APBH_CH15_CMD_COMMAND_MASK)

#define APBH_CH15_CMD_CHAIN_MASK                 (0x4U)
#define APBH_CH15_CMD_CHAIN_SHIFT                (2U)
#define APBH_CH15_CMD_CHAIN(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH15_CMD_CHAIN_SHIFT)) & APBH_CH15_CMD_CHAIN_MASK)

#define APBH_CH15_CMD_IRQONCMPLT_MASK            (0x8U)
#define APBH_CH15_CMD_IRQONCMPLT_SHIFT           (3U)
#define APBH_CH15_CMD_IRQONCMPLT(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH15_CMD_IRQONCMPLT_SHIFT)) & APBH_CH15_CMD_IRQONCMPLT_MASK)

#define APBH_CH15_CMD_NANDLOCK_MASK              (0x10U)
#define APBH_CH15_CMD_NANDLOCK_SHIFT             (4U)
#define APBH_CH15_CMD_NANDLOCK(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH15_CMD_NANDLOCK_SHIFT)) & APBH_CH15_CMD_NANDLOCK_MASK)

#define APBH_CH15_CMD_NANDWAIT4READY_MASK        (0x20U)
#define APBH_CH15_CMD_NANDWAIT4READY_SHIFT       (5U)
#define APBH_CH15_CMD_NANDWAIT4READY(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH15_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH15_CMD_NANDWAIT4READY_MASK)

#define APBH_CH15_CMD_SEMAPHORE_MASK             (0x40U)
#define APBH_CH15_CMD_SEMAPHORE_SHIFT            (6U)
#define APBH_CH15_CMD_SEMAPHORE(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH15_CMD_SEMAPHORE_SHIFT)) & APBH_CH15_CMD_SEMAPHORE_MASK)

#define APBH_CH15_CMD_WAIT4ENDCMD_MASK           (0x80U)
#define APBH_CH15_CMD_WAIT4ENDCMD_SHIFT          (7U)
#define APBH_CH15_CMD_WAIT4ENDCMD(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH15_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH15_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH15_CMD_HALTONTERMINATE_MASK       (0x100U)
#define APBH_CH15_CMD_HALTONTERMINATE_SHIFT      (8U)
#define APBH_CH15_CMD_HALTONTERMINATE(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH15_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH15_CMD_HALTONTERMINATE_MASK)

#define APBH_CH15_CMD_CMDWORDS_MASK              (0xF000U)
#define APBH_CH15_CMD_CMDWORDS_SHIFT             (12U)
#define APBH_CH15_CMD_CMDWORDS(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH15_CMD_CMDWORDS_SHIFT)) & APBH_CH15_CMD_CMDWORDS_MASK)

#define APBH_CH15_CMD_XFER_COUNT_MASK            (0xFFFF0000U)
#define APBH_CH15_CMD_XFER_COUNT_SHIFT           (16U)
#define APBH_CH15_CMD_XFER_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH15_CMD_XFER_COUNT_SHIFT)) & APBH_CH15_CMD_XFER_COUNT_MASK)
/*! @} */

/*! @name CH15_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH15_BAR_ADDRESS_MASK               (0xFFFFFFFFU)
#define APBH_CH15_BAR_ADDRESS_SHIFT              (0U)
#define APBH_CH15_BAR_ADDRESS(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH15_BAR_ADDRESS_SHIFT)) & APBH_CH15_BAR_ADDRESS_MASK)
/*! @} */

/*! @name CH15_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH15_SEMA_INCREMENT_SEMA_MASK       (0xFFU)
#define APBH_CH15_SEMA_INCREMENT_SEMA_SHIFT      (0U)
#define APBH_CH15_SEMA_INCREMENT_SEMA(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH15_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH15_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH15_SEMA_PHORE_MASK                (0xFF0000U)
#define APBH_CH15_SEMA_PHORE_SHIFT               (16U)
#define APBH_CH15_SEMA_PHORE(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH15_SEMA_PHORE_SHIFT)) & APBH_CH15_SEMA_PHORE_MASK)
/*! @} */

/*! @name CH15_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH15_DEBUG1_STATEMACHINE_MASK       (0x1FU)
#define APBH_CH15_DEBUG1_STATEMACHINE_SHIFT      (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH15_DEBUG1_STATEMACHINE(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH15_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH15_DEBUG1_RSVD1_MASK              (0xFFFE0U)
#define APBH_CH15_DEBUG1_RSVD1_SHIFT             (5U)
#define APBH_CH15_DEBUG1_RSVD1(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG1_RSVD1_SHIFT)) & APBH_CH15_DEBUG1_RSVD1_MASK)

#define APBH_CH15_DEBUG1_WR_FIFO_FULL_MASK       (0x100000U)
#define APBH_CH15_DEBUG1_WR_FIFO_FULL_SHIFT      (20U)
#define APBH_CH15_DEBUG1_WR_FIFO_FULL(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH15_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH15_DEBUG1_WR_FIFO_EMPTY_MASK      (0x200000U)
#define APBH_CH15_DEBUG1_WR_FIFO_EMPTY_SHIFT     (21U)
#define APBH_CH15_DEBUG1_WR_FIFO_EMPTY(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH15_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH15_DEBUG1_RD_FIFO_FULL_MASK       (0x400000U)
#define APBH_CH15_DEBUG1_RD_FIFO_FULL_SHIFT      (22U)
#define APBH_CH15_DEBUG1_RD_FIFO_FULL(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH15_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH15_DEBUG1_RD_FIFO_EMPTY_MASK      (0x800000U)
#define APBH_CH15_DEBUG1_RD_FIFO_EMPTY_SHIFT     (23U)
#define APBH_CH15_DEBUG1_RD_FIFO_EMPTY(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH15_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH15_DEBUG1_NEXTCMDADDRVALID_MASK   (0x1000000U)
#define APBH_CH15_DEBUG1_NEXTCMDADDRVALID_SHIFT  (24U)
#define APBH_CH15_DEBUG1_NEXTCMDADDRVALID(x)     (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH15_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH15_DEBUG1_LOCK_MASK               (0x2000000U)
#define APBH_CH15_DEBUG1_LOCK_SHIFT              (25U)
#define APBH_CH15_DEBUG1_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG1_LOCK_SHIFT)) & APBH_CH15_DEBUG1_LOCK_MASK)

#define APBH_CH15_DEBUG1_READY_MASK              (0x4000000U)
#define APBH_CH15_DEBUG1_READY_SHIFT             (26U)
#define APBH_CH15_DEBUG1_READY(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG1_READY_SHIFT)) & APBH_CH15_DEBUG1_READY_MASK)

#define APBH_CH15_DEBUG1_SENSE_MASK              (0x8000000U)
#define APBH_CH15_DEBUG1_SENSE_SHIFT             (27U)
#define APBH_CH15_DEBUG1_SENSE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG1_SENSE_SHIFT)) & APBH_CH15_DEBUG1_SENSE_MASK)

#define APBH_CH15_DEBUG1_END_MASK                (0x10000000U)
#define APBH_CH15_DEBUG1_END_SHIFT               (28U)
#define APBH_CH15_DEBUG1_END(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG1_END_SHIFT)) & APBH_CH15_DEBUG1_END_MASK)

#define APBH_CH15_DEBUG1_KICK_MASK               (0x20000000U)
#define APBH_CH15_DEBUG1_KICK_SHIFT              (29U)
#define APBH_CH15_DEBUG1_KICK(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG1_KICK_SHIFT)) & APBH_CH15_DEBUG1_KICK_MASK)

#define APBH_CH15_DEBUG1_BURST_MASK              (0x40000000U)
#define APBH_CH15_DEBUG1_BURST_SHIFT             (30U)
#define APBH_CH15_DEBUG1_BURST(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG1_BURST_SHIFT)) & APBH_CH15_DEBUG1_BURST_MASK)

#define APBH_CH15_DEBUG1_REQ_MASK                (0x80000000U)
#define APBH_CH15_DEBUG1_REQ_SHIFT               (31U)
#define APBH_CH15_DEBUG1_REQ(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG1_REQ_SHIFT)) & APBH_CH15_DEBUG1_REQ_MASK)
/*! @} */

/*! @name CH15_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH15_DEBUG2_AHB_BYTES_MASK          (0xFFFFU)
#define APBH_CH15_DEBUG2_AHB_BYTES_SHIFT         (0U)
#define APBH_CH15_DEBUG2_AHB_BYTES(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH15_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH15_DEBUG2_APB_BYTES_MASK          (0xFFFF0000U)
#define APBH_CH15_DEBUG2_APB_BYTES_SHIFT         (16U)
#define APBH_CH15_DEBUG2_APB_BYTES(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH15_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH15_DEBUG2_APB_BYTES_MASK)
/*! @} */

/*! @name VERSION - APBH Bridge Version Register */
/*! @{ */

#define APBH_VERSION_STEP_MASK                   (0xFFFFU)
#define APBH_VERSION_STEP_SHIFT                  (0U)
#define APBH_VERSION_STEP(x)                     (((uint32_t)(((uint32_t)(x)) << APBH_VERSION_STEP_SHIFT)) & APBH_VERSION_STEP_MASK)

#define APBH_VERSION_MINOR_MASK                  (0xFF0000U)
#define APBH_VERSION_MINOR_SHIFT                 (16U)
#define APBH_VERSION_MINOR(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_VERSION_MINOR_SHIFT)) & APBH_VERSION_MINOR_MASK)

#define APBH_VERSION_MAJOR_MASK                  (0xFF000000U)
#define APBH_VERSION_MAJOR_SHIFT                 (24U)
#define APBH_VERSION_MAJOR(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_VERSION_MAJOR_SHIFT)) & APBH_VERSION_MAJOR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group APBH_Register_Masks */


/*!
 * @}
 */ /* end of group APBH_Peripheral_Access_Layer */


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


#endif  /* PERI_APBH_H_ */

