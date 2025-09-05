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
**         CMSIS Peripheral Access Layer for USB
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
 * @file PERI_USB.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USB
 *
 * CMSIS Peripheral Access Layer for USB
 */

#if !defined(PERI_USB_H_)
#define PERI_USB_H_                              /**< Symbol preventing repeated inclusion */

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
   -- USB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Peripheral_Access_Layer USB Peripheral Access Layer
 * @{
 */

/** USB - Size of Registers Arrays */
#define USB_GTXFIFOSIZX_COUNT                     8u
#define USB_GRXFIFOSIZY_COUNT                     3u

/** USB - Register Layout Typedef */
typedef struct {
  __I  uint32_t CAPLENGTH;                         /**< Capability registers length and Host Controller Operational Registers, offset: 0x0 */
  __I  uint32_t HCSPARAMS1;                        /**< Structural Parameters 1 Register, offset: 0x4 */
  __I  uint32_t HCSPARAMS2;                        /**< Structural Parameters 2 Register, offset: 0x8 */
  __I  uint32_t HCSPARAMS3;                        /**< Structural Parameters 3 Register, offset: 0xC */
  __I  uint32_t HCCPARAMS1;                        /**< Capability Parameters 1 Register, offset: 0x10 */
  __I  uint32_t DBOFF;                             /**< Doorbell Offset Register, offset: 0x14 */
  __I  uint32_t RTSOFF;                            /**< Runtime Register Space Offset Register, offset: 0x18 */
  __I  uint32_t HCCPARAMS2;                        /**< Host Controller Capability Parameters 2, offset: 0x1C */
  __IO uint32_t USBCMD;                            /**< USB Command Register, offset: 0x20 */
  __IO uint32_t USBSTS;                            /**< USB Status Register, offset: 0x24 */
#undef PAGESIZE
  __I  uint32_t PAGESIZE;                          /**< Page Size Register, offset: 0x28 */
       uint8_t RESERVED_0[8];
  __IO uint32_t DNCTRL;                            /**< Device Notification Register, offset: 0x34 */
  __IO uint32_t CRCR_LO;                           /**< CRCR_LO, offset: 0x38 */
  __IO uint32_t CRCR_HI;                           /**< offset: 0x3C */
       uint8_t RESERVED_1[16];
  __IO uint32_t DCBAAP_LO;                         /**< DCBAAP_LO, offset: 0x50 */
  __IO uint32_t DCBAAP_HI;                         /**< DCBAAP_HI, offset: 0x54 */
  __IO uint32_t CONFIG;                            /**< Configuration Register, offset: 0x58 */
       uint8_t RESERVED_2[964];
  __IO uint32_t PORTSC_20;                         /**< Port Status and Control Register, offset: 0x420 */
  __IO uint32_t PORTPMSC_20;                       /**< USB3 Port Power Management Status and Control Register, offset: 0x424 */
       uint32_t PORTLI_20;                         /**< offset: 0x428 */
  __IO uint32_t PORTHLPMC_20;                      /**< offset: 0x42C */
  __IO uint32_t PORTSC_30;                         /**< offset: 0x430 */
  __IO uint32_t PORTPMSC_30;                       /**< USB3 Port Power Management Status and Control Register, offset: 0x434 */
  __I  uint32_t PORTLI_30;                         /**< Port Link Info Register, offset: 0x438 */
       uint32_t PORTHLPMC_30;                      /**< USB2 Port Hardware LPM Control Register, offset: 0x43C */
  __I  uint32_t MFINDEX;                           /**< Microframe Index Register, offset: 0x440 */
       uint8_t RESERVED_3[28];
  __IO uint32_t IMAN;                              /**< Interrupter Management Register, offset: 0x460 */
  __IO uint32_t IMOD;                              /**< Interrupter Moderation Register, offset: 0x464 */
  __IO uint32_t ERSTSZ;                            /**< ERSTSZ, offset: 0x468 */
       uint8_t RESERVED_4[4];
  __IO uint32_t ERSTBA_LO;                         /**< ERSTBA_LO, offset: 0x470 */
  __IO uint32_t ERSTBA_HI;                         /**< ERSTBA_HI, offset: 0x474 */
  __IO uint32_t ERDP_LO;                           /**< ERDP_LO, offset: 0x478 */
  __IO uint32_t ERDP_HI;                           /**< ERDP_HI, offset: 0x47C */
  __IO uint32_t DB;                                /**< Doorbell Register, offset: 0x480 */
       uint8_t RESERVED_5[1020];
  __IO uint32_t USBLEGSUP;                         /**< USBLEGSUP, offset: 0x880 */
  __IO uint32_t USBLEGCTLSTS;                      /**< USBLEGCTLSTS, offset: 0x884 */
       uint8_t RESERVED_6[8];
  __I  uint32_t SUPTPRT2_DW0;                      /**< SUPTPRT2_DW0, offset: 0x890 */
  __I  uint32_t SUPTPRT2_DW1;                      /**< SUPTPRT2_DW1 Register, offset: 0x894 */
  __I  uint32_t SUPTPRT2_DW2;                      /**< xHCI Supported Protocol Capability_ Data Word 2, offset: 0x898 */
  __I  uint32_t SUPTPRT2_DW3;                      /**< SUPTPRT2_DW3 Register, offset: 0x89C */
  __I  uint32_t SUPTPRT3_DW0;                      /**< offset: 0x8A0 */
  __I  uint32_t SUPTPRT3_DW1;                      /**< SUPTPRT3_DW1 Register, offset: 0x8A4 */
  __I  uint32_t SUPTPRT3_DW2;                      /**< SUPTPRT3_DW2, offset: 0x8A8 */
  __I  uint32_t SUPTPRT3_DW3;                      /**< SUPTPRT3_DW3, offset: 0x8AC */
       uint8_t RESERVED_7[47184];
  __IO uint32_t GSBUSCFG0;                         /**< Global SoC Bus Configuration Register 0, offset: 0xC100 */
  __IO uint32_t GSBUSCFG1;                         /**< Global SoC Bus Configuration Register 1, offset: 0xC104 */
  __IO uint32_t GTXTHRCFG;                         /**< Global Tx Threshold Control Register, offset: 0xC108 */
  __IO uint32_t GRXTHRCFG;                         /**< Global Rx Threshold Control Register, offset: 0xC10C */
  __IO uint32_t GCTL;                              /**< Global Core Control Register, offset: 0xC110 */
       uint8_t RESERVED_8[4];
  __IO uint32_t GSTS;                              /**< Global Status Register, offset: 0xC118 */
  __IO uint32_t GUCTL1;                            /**< offset: 0xC11C */
       uint8_t RESERVED_9[8];
  __IO uint32_t GUID;                              /**< Global User ID Register, offset: 0xC128 */
  __IO uint32_t GUCTL;                             /**< Global User Control Register, offset: 0xC12C */
  __I  uint32_t GBUSERRADDRLO;                     /**< Gobal SoC Bus Error Address Register - Low, offset: 0xC130 */
  __I  uint32_t GBUSERRADDRHI;                     /**< Gobal SoC Bus Error Address Register - High, offset: 0xC134 */
  __IO uint32_t GPRTBIMAPLO;                       /**< Global SS Port to Bus Instance Mapping Register - Low, offset: 0xC138 */
  __IO uint32_t GPRTBIMAPHI;                       /**< Global SS Port to Bus Instance Mapping Register - High, offset: 0xC13C */
  __I  uint32_t GHWPARAMS0;                        /**< Global Hardware Parameters Register 0, offset: 0xC140 */
  __I  uint32_t GHWPARAMS1;                        /**< Global Hardware Parameters Register 1, offset: 0xC144 */
  __I  uint32_t GHWPARAMS2;                        /**< Global Hardware Parameters Register 2, offset: 0xC148 */
  __I  uint32_t GHWPARAMS3;                        /**< Global Hardware Parameters Register 3, offset: 0xC14C */
  __I  uint32_t GHWPARAMS4;                        /**< Global Hardware Parameters Register 4, offset: 0xC150 */
  __I  uint32_t GHWPARAMS5;                        /**< Global Hardware Parameters Register 5, offset: 0xC154 */
  __I  uint32_t GHWPARAMS6;                        /**< Global Hardware Parameters Register 6, offset: 0xC158 */
  __I  uint32_t GHWPARAMS7;                        /**< Global Hardware Parameters Register 7, offset: 0xC15C */
       uint8_t RESERVED_10[32];
  __IO uint32_t GPRTBIMAP_HSLO;                    /**< Global High-Speed Port to Bus Instance Mapping Register - Low, offset: 0xC180 */
  __IO uint32_t GPRTBIMAP_HSHI;                    /**< Global High-Speed Port to Bus Instance Mapping Register - High, offset: 0xC184 */
  __IO uint32_t GPRTBIMAP_FSLO;                    /**< Global Full-Speed Port to Bus Instance Mapping Register - Low, offset: 0xC188 */
  __IO uint32_t GPRTBIMAP_FSHI;                    /**< Global Full-Speed Port to Bus Instance Mapping Register - High, offset: 0xC18C */
       uint8_t RESERVED_11[12];
  __IO uint32_t GUCTL2;                            /**< Global User Control Register 2, offset: 0xC19C */
       uint8_t RESERVED_12[96];
  __IO uint32_t GUSB2PHYCFG;                       /**< Global USB2 PHY Configuration Register, offset: 0xC200 */
       uint8_t RESERVED_13[124];
  __I  uint32_t GUSB2PHYACC_ULPI;                  /**< Global USB 2.0 UTMI PHY vendor control register, offset: 0xC280 */
       uint8_t RESERVED_14[60];
  __IO uint32_t GUSB3PIPECTL;                      /**< Global USB 3.0 PIPE control register, offset: 0xC2C0 */
       uint8_t RESERVED_15[60];
  __IO uint32_t GTXFIFOSIZ[USB_GTXFIFOSIZX_COUNT]; /**< Global transmit FIFO size register, array offset: 0xC300, array step: 0x4 */
       uint8_t RESERVED_16[96];
  __IO uint32_t GRXFIFOSIZ[USB_GRXFIFOSIZY_COUNT]; /**< Global receive FIFO size register, array offset: 0xC380, array step: 0x4 */
       uint8_t RESERVED_17[116];
  __IO uint32_t GEVNTADRLO;                        /**< Global Event Buffer Address (Low) Register, offset: 0xC400 */
  __IO uint32_t GEVNTADRHI;                        /**< Global Event Buffer Address (High) Register, offset: 0xC404 */
  __IO uint32_t GEVNTSIZ;                          /**< Global event buffer size register, offset: 0xC408 */
  __IO uint32_t GEVNTCOUNT;                        /**< Global event buffer count register, offset: 0xC40C */
       uint8_t RESERVED_18[496];
  __I  uint32_t GHWPARAMS8;                        /**< Global Hardware Parameters Register 8, offset: 0xC600 */
       uint8_t RESERVED_19[12];
  __IO uint32_t GTXFIFOPRIDEV;                     /**< Global Device TX FIFO DMA Priority Register, offset: 0xC610 */
       uint8_t RESERVED_20[4];
  __IO uint32_t GTXFIFOPRIHST;                     /**< Global Host TX FIFO DMA Priority Register, offset: 0xC618 */
  __IO uint32_t GRXFIFOPRIHST;                     /**< Global Host RX FIFO DMA Priority Register, offset: 0xC61C */
  __IO uint32_t GFIFOPRIDBC;                       /**< Global Host Debug Capability DMA Priority Register, offset: 0xC620 */
  __IO uint32_t GDMAHLRATIO;                       /**< offset: 0xC624 */
       uint8_t RESERVED_21[8];
  __IO uint32_t GFLADJ;                            /**< Global Frame Length Adjustment Register, offset: 0xC630 */
       uint8_t RESERVED_22[204];
  __IO uint32_t DCFG;                              /**< Device Configuration Register, offset: 0xC700 */
  __IO uint32_t DCTL;                              /**< Device control register, offset: 0xC704 */
  __IO uint32_t DEVTEN;                            /**< Device Event Enable Register, offset: 0xC708 */
  __IO uint32_t DSTS;                              /**< Device Status Register, offset: 0xC70C */
  __IO uint32_t DGCMDPAR;                          /**< Device Generic Command Parameter Register, offset: 0xC710 */
  __IO uint32_t DGCMD;                             /**< offset: 0xC714 */
       uint8_t RESERVED_23[8];
  __IO uint32_t DALEPENA;                          /**< Device Active USB Endpoint Enable Register, offset: 0xC720 */
       uint8_t RESERVED_24[220];
  __IO uint32_t DEPCMDPAR2;                        /**< Device physical endpoint-n command parameter 2 register, offset: 0xC800 */
  __IO uint32_t DEPCMDPAR1;                        /**< Device Physical Endpoint-n Command Parameter 1 Register, offset: 0xC804 */
  __IO uint32_t DEPCMDPAR0;                        /**< Device Physical Endpoint-n Command Parameter 0 Register, offset: 0xC808 */
  __IO uint32_t DEPCMD;                            /**< Device Physical Endpoint-n Command Register, offset: 0xC80C */
       uint8_t RESERVED_25[496];
  __IO uint32_t DEV_IMOD;                          /**< Device Interrupt Moderation Register, offset: 0xCA00 */
       uint8_t RESERVED_26[556];
  __IO uint32_t BCFG;                              /**< BCFG, offset: 0xCC30 */
       uint8_t RESERVED_27[4];
  __IO uint32_t BCEVT;                             /**< BCEVT, offset: 0xCC38 */
  __IO uint32_t BCEVTEN;                           /**< BCEVTEN, offset: 0xCC3C */
} USB_Type;

/* ----------------------------------------------------------------------------
   -- USB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Register_Masks USB Register Masks
 * @{
 */

/*! @name CAPLENGTH - Capability registers length and Host Controller Operational Registers */
/*! @{ */

#define USB_CAPLENGTH_CAPLENGTH_MASK             (0xFFU)
#define USB_CAPLENGTH_CAPLENGTH_SHIFT            (0U)
#define USB_CAPLENGTH_CAPLENGTH(x)               (((uint32_t)(((uint32_t)(x)) << USB_CAPLENGTH_CAPLENGTH_SHIFT)) & USB_CAPLENGTH_CAPLENGTH_MASK)

#define USB_CAPLENGTH_HCIVERSION_MASK            (0xFFFF0000U)
#define USB_CAPLENGTH_HCIVERSION_SHIFT           (16U)
#define USB_CAPLENGTH_HCIVERSION(x)              (((uint32_t)(((uint32_t)(x)) << USB_CAPLENGTH_HCIVERSION_SHIFT)) & USB_CAPLENGTH_HCIVERSION_MASK)
/*! @} */

/*! @name HCSPARAMS1 - Structural Parameters 1 Register */
/*! @{ */

#define USB_HCSPARAMS1_MAXSLOTS_MASK             (0xFFU)
#define USB_HCSPARAMS1_MAXSLOTS_SHIFT            (0U)
#define USB_HCSPARAMS1_MAXSLOTS(x)               (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS1_MAXSLOTS_SHIFT)) & USB_HCSPARAMS1_MAXSLOTS_MASK)

#define USB_HCSPARAMS1_MAXINTRS_MASK             (0x7FF00U)
#define USB_HCSPARAMS1_MAXINTRS_SHIFT            (8U)
#define USB_HCSPARAMS1_MAXINTRS(x)               (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS1_MAXINTRS_SHIFT)) & USB_HCSPARAMS1_MAXINTRS_MASK)

#define USB_HCSPARAMS1_MAXPORTS_MASK             (0xFF000000U)
#define USB_HCSPARAMS1_MAXPORTS_SHIFT            (24U)
#define USB_HCSPARAMS1_MAXPORTS(x)               (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS1_MAXPORTS_SHIFT)) & USB_HCSPARAMS1_MAXPORTS_MASK)
/*! @} */

/*! @name HCSPARAMS2 - Structural Parameters 2 Register */
/*! @{ */

#define USB_HCSPARAMS2_IST_MASK                  (0xFU)
#define USB_HCSPARAMS2_IST_SHIFT                 (0U)
#define USB_HCSPARAMS2_IST(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS2_IST_SHIFT)) & USB_HCSPARAMS2_IST_MASK)

#define USB_HCSPARAMS2_ERSTMAX_MASK              (0xF0U)
#define USB_HCSPARAMS2_ERSTMAX_SHIFT             (4U)
#define USB_HCSPARAMS2_ERSTMAX(x)                (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS2_ERSTMAX_SHIFT)) & USB_HCSPARAMS2_ERSTMAX_MASK)

#define USB_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_MASK (0x3E00000U)
#define USB_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_SHIFT (21U)
#define USB_HCSPARAMS2_MAXSCRATCHPADBUFS_HI(x)   (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_SHIFT)) & USB_HCSPARAMS2_MAXSCRATCHPADBUFS_HI_MASK)

#define USB_HCSPARAMS2_SPR_MASK                  (0x4000000U)
#define USB_HCSPARAMS2_SPR_SHIFT                 (26U)
#define USB_HCSPARAMS2_SPR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS2_SPR_SHIFT)) & USB_HCSPARAMS2_SPR_MASK)

#define USB_HCSPARAMS2_MAXSCRATCHPADBUFS_MASK    (0xF8000000U)
#define USB_HCSPARAMS2_MAXSCRATCHPADBUFS_SHIFT   (27U)
#define USB_HCSPARAMS2_MAXSCRATCHPADBUFS(x)      (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS2_MAXSCRATCHPADBUFS_SHIFT)) & USB_HCSPARAMS2_MAXSCRATCHPADBUFS_MASK)
/*! @} */

/*! @name HCSPARAMS3 - Structural Parameters 3 Register */
/*! @{ */

#define USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_MASK   (0xFFU)
#define USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_SHIFT  (0U)
#define USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT(x)     (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_SHIFT)) & USB_HCSPARAMS3_U1_DEVICE_EXIT_LAT_MASK)

#define USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_MASK   (0xFFFF0000U)
#define USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_SHIFT  (16U)
#define USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT(x)     (((uint32_t)(((uint32_t)(x)) << USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_SHIFT)) & USB_HCSPARAMS3_U2_DEVICE_EXIT_LAT_MASK)
/*! @} */

/*! @name HCCPARAMS1 - Capability Parameters 1 Register */
/*! @{ */

#define USB_HCCPARAMS1_AC64_MASK                 (0x1U)
#define USB_HCCPARAMS1_AC64_SHIFT                (0U)
#define USB_HCCPARAMS1_AC64(x)                   (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS1_AC64_SHIFT)) & USB_HCCPARAMS1_AC64_MASK)

#define USB_HCCPARAMS1_BNC_MASK                  (0x2U)
#define USB_HCCPARAMS1_BNC_SHIFT                 (1U)
#define USB_HCCPARAMS1_BNC(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS1_BNC_SHIFT)) & USB_HCCPARAMS1_BNC_MASK)

#define USB_HCCPARAMS1_CSZ_MASK                  (0x4U)
#define USB_HCCPARAMS1_CSZ_SHIFT                 (2U)
#define USB_HCCPARAMS1_CSZ(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS1_CSZ_SHIFT)) & USB_HCCPARAMS1_CSZ_MASK)

#define USB_HCCPARAMS1_PPC_MASK                  (0x8U)
#define USB_HCCPARAMS1_PPC_SHIFT                 (3U)
#define USB_HCCPARAMS1_PPC(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS1_PPC_SHIFT)) & USB_HCCPARAMS1_PPC_MASK)

#define USB_HCCPARAMS1_PIND_MASK                 (0x10U)
#define USB_HCCPARAMS1_PIND_SHIFT                (4U)
#define USB_HCCPARAMS1_PIND(x)                   (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS1_PIND_SHIFT)) & USB_HCCPARAMS1_PIND_MASK)

#define USB_HCCPARAMS1_LHRC_MASK                 (0x20U)
#define USB_HCCPARAMS1_LHRC_SHIFT                (5U)
#define USB_HCCPARAMS1_LHRC(x)                   (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS1_LHRC_SHIFT)) & USB_HCCPARAMS1_LHRC_MASK)

#define USB_HCCPARAMS1_LTC_MASK                  (0x40U)
#define USB_HCCPARAMS1_LTC_SHIFT                 (6U)
#define USB_HCCPARAMS1_LTC(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS1_LTC_SHIFT)) & USB_HCCPARAMS1_LTC_MASK)

#define USB_HCCPARAMS1_NSS_MASK                  (0x80U)
#define USB_HCCPARAMS1_NSS_SHIFT                 (7U)
#define USB_HCCPARAMS1_NSS(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS1_NSS_SHIFT)) & USB_HCCPARAMS1_NSS_MASK)

#define USB_HCCPARAMS1_PAE_MASK                  (0x100U)
#define USB_HCCPARAMS1_PAE_SHIFT                 (8U)
#define USB_HCCPARAMS1_PAE(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS1_PAE_SHIFT)) & USB_HCCPARAMS1_PAE_MASK)

#define USB_HCCPARAMS1_SPC_MASK                  (0x200U)
#define USB_HCCPARAMS1_SPC_SHIFT                 (9U)
#define USB_HCCPARAMS1_SPC(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS1_SPC_SHIFT)) & USB_HCCPARAMS1_SPC_MASK)

#define USB_HCCPARAMS1_SEC_MASK                  (0x400U)
#define USB_HCCPARAMS1_SEC_SHIFT                 (10U)
#define USB_HCCPARAMS1_SEC(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS1_SEC_SHIFT)) & USB_HCCPARAMS1_SEC_MASK)

#define USB_HCCPARAMS1_CFC_MASK                  (0x800U)
#define USB_HCCPARAMS1_CFC_SHIFT                 (11U)
#define USB_HCCPARAMS1_CFC(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS1_CFC_SHIFT)) & USB_HCCPARAMS1_CFC_MASK)

#define USB_HCCPARAMS1_MAXPSASIZE_MASK           (0xF000U)
#define USB_HCCPARAMS1_MAXPSASIZE_SHIFT          (12U)
#define USB_HCCPARAMS1_MAXPSASIZE(x)             (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS1_MAXPSASIZE_SHIFT)) & USB_HCCPARAMS1_MAXPSASIZE_MASK)

#define USB_HCCPARAMS1_XECP_MASK                 (0xFFFF0000U)
#define USB_HCCPARAMS1_XECP_SHIFT                (16U)
#define USB_HCCPARAMS1_XECP(x)                   (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS1_XECP_SHIFT)) & USB_HCCPARAMS1_XECP_MASK)
/*! @} */

/*! @name DBOFF - Doorbell Offset Register */
/*! @{ */

#define USB_DBOFF_DOORBELL_ARRAY_OFFSET_MASK     (0xFFFFFFFCU)
#define USB_DBOFF_DOORBELL_ARRAY_OFFSET_SHIFT    (2U)
#define USB_DBOFF_DOORBELL_ARRAY_OFFSET(x)       (((uint32_t)(((uint32_t)(x)) << USB_DBOFF_DOORBELL_ARRAY_OFFSET_SHIFT)) & USB_DBOFF_DOORBELL_ARRAY_OFFSET_MASK)
/*! @} */

/*! @name RTSOFF - Runtime Register Space Offset Register */
/*! @{ */

#define USB_RTSOFF_RUNTIME_REG_SPACE_OFFSET_MASK (0xFFFFFFE0U)
#define USB_RTSOFF_RUNTIME_REG_SPACE_OFFSET_SHIFT (5U)
#define USB_RTSOFF_RUNTIME_REG_SPACE_OFFSET(x)   (((uint32_t)(((uint32_t)(x)) << USB_RTSOFF_RUNTIME_REG_SPACE_OFFSET_SHIFT)) & USB_RTSOFF_RUNTIME_REG_SPACE_OFFSET_MASK)
/*! @} */

/*! @name HCCPARAMS2 - Host Controller Capability Parameters 2 */
/*! @{ */

#define USB_HCCPARAMS2_U3C_MASK                  (0x1U)
#define USB_HCCPARAMS2_U3C_SHIFT                 (0U)
#define USB_HCCPARAMS2_U3C(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS2_U3C_SHIFT)) & USB_HCCPARAMS2_U3C_MASK)

#define USB_HCCPARAMS2_CMC_MASK                  (0x2U)
#define USB_HCCPARAMS2_CMC_SHIFT                 (1U)
#define USB_HCCPARAMS2_CMC(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS2_CMC_SHIFT)) & USB_HCCPARAMS2_CMC_MASK)

#define USB_HCCPARAMS2_FSC_MASK                  (0x4U)
#define USB_HCCPARAMS2_FSC_SHIFT                 (2U)
#define USB_HCCPARAMS2_FSC(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS2_FSC_SHIFT)) & USB_HCCPARAMS2_FSC_MASK)

#define USB_HCCPARAMS2_CTC_MASK                  (0x8U)
#define USB_HCCPARAMS2_CTC_SHIFT                 (3U)
#define USB_HCCPARAMS2_CTC(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS2_CTC_SHIFT)) & USB_HCCPARAMS2_CTC_MASK)

#define USB_HCCPARAMS2_LEC_MASK                  (0x10U)
#define USB_HCCPARAMS2_LEC_SHIFT                 (4U)
#define USB_HCCPARAMS2_LEC(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS2_LEC_SHIFT)) & USB_HCCPARAMS2_LEC_MASK)

#define USB_HCCPARAMS2_CIC_MASK                  (0x20U)
#define USB_HCCPARAMS2_CIC_SHIFT                 (5U)
#define USB_HCCPARAMS2_CIC(x)                    (((uint32_t)(((uint32_t)(x)) << USB_HCCPARAMS2_CIC_SHIFT)) & USB_HCCPARAMS2_CIC_MASK)
/*! @} */

/*! @name USBCMD - USB Command Register */
/*! @{ */

#define USB_USBCMD_R_S_MASK                      (0x1U)
#define USB_USBCMD_R_S_SHIFT                     (0U)
#define USB_USBCMD_R_S(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_R_S_SHIFT)) & USB_USBCMD_R_S_MASK)

#define USB_USBCMD_HCRST_MASK                    (0x2U)
#define USB_USBCMD_HCRST_SHIFT                   (1U)
#define USB_USBCMD_HCRST(x)                      (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_HCRST_SHIFT)) & USB_USBCMD_HCRST_MASK)

#define USB_USBCMD_INTE_MASK                     (0x4U)
#define USB_USBCMD_INTE_SHIFT                    (2U)
#define USB_USBCMD_INTE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_INTE_SHIFT)) & USB_USBCMD_INTE_MASK)

#define USB_USBCMD_HSEE_MASK                     (0x8U)
#define USB_USBCMD_HSEE_SHIFT                    (3U)
#define USB_USBCMD_HSEE(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_HSEE_SHIFT)) & USB_USBCMD_HSEE_MASK)

#define USB_USBCMD_LHCRST_MASK                   (0x80U)
#define USB_USBCMD_LHCRST_SHIFT                  (7U)
#define USB_USBCMD_LHCRST(x)                     (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_LHCRST_SHIFT)) & USB_USBCMD_LHCRST_MASK)

#define USB_USBCMD_CSS_MASK                      (0x100U)
#define USB_USBCMD_CSS_SHIFT                     (8U)
#define USB_USBCMD_CSS(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_CSS_SHIFT)) & USB_USBCMD_CSS_MASK)

#define USB_USBCMD_CRS_MASK                      (0x200U)
#define USB_USBCMD_CRS_SHIFT                     (9U)
#define USB_USBCMD_CRS(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_CRS_SHIFT)) & USB_USBCMD_CRS_MASK)

#define USB_USBCMD_EWE_MASK                      (0x400U)
#define USB_USBCMD_EWE_SHIFT                     (10U)
#define USB_USBCMD_EWE(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_EWE_SHIFT)) & USB_USBCMD_EWE_MASK)

#define USB_USBCMD_EU3S_MASK                     (0x800U)
#define USB_USBCMD_EU3S_SHIFT                    (11U)
#define USB_USBCMD_EU3S(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_EU3S_SHIFT)) & USB_USBCMD_EU3S_MASK)

#define USB_USBCMD_CME_MASK                      (0x2000U)
#define USB_USBCMD_CME_SHIFT                     (13U)
#define USB_USBCMD_CME(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBCMD_CME_SHIFT)) & USB_USBCMD_CME_MASK)
/*! @} */

/*! @name USBSTS - USB Status Register */
/*! @{ */

#define USB_USBSTS_HCH_MASK                      (0x1U)
#define USB_USBSTS_HCH_SHIFT                     (0U)
#define USB_USBSTS_HCH(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_HCH_SHIFT)) & USB_USBSTS_HCH_MASK)

#define USB_USBSTS_HSE_MASK                      (0x4U)
#define USB_USBSTS_HSE_SHIFT                     (2U)
#define USB_USBSTS_HSE(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_HSE_SHIFT)) & USB_USBSTS_HSE_MASK)

#define USB_USBSTS_EINT_MASK                     (0x8U)
#define USB_USBSTS_EINT_SHIFT                    (3U)
#define USB_USBSTS_EINT(x)                       (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_EINT_SHIFT)) & USB_USBSTS_EINT_MASK)

#define USB_USBSTS_PCD_MASK                      (0x10U)
#define USB_USBSTS_PCD_SHIFT                     (4U)
#define USB_USBSTS_PCD(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_PCD_SHIFT)) & USB_USBSTS_PCD_MASK)

#define USB_USBSTS_SSS_MASK                      (0x100U)
#define USB_USBSTS_SSS_SHIFT                     (8U)
#define USB_USBSTS_SSS(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_SSS_SHIFT)) & USB_USBSTS_SSS_MASK)

#define USB_USBSTS_RSS_MASK                      (0x200U)
#define USB_USBSTS_RSS_SHIFT                     (9U)
#define USB_USBSTS_RSS(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_RSS_SHIFT)) & USB_USBSTS_RSS_MASK)

#define USB_USBSTS_SRE_MASK                      (0x400U)
#define USB_USBSTS_SRE_SHIFT                     (10U)
#define USB_USBSTS_SRE(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_SRE_SHIFT)) & USB_USBSTS_SRE_MASK)

#define USB_USBSTS_CNR_MASK                      (0x800U)
#define USB_USBSTS_CNR_SHIFT                     (11U)
#define USB_USBSTS_CNR(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_CNR_SHIFT)) & USB_USBSTS_CNR_MASK)

#define USB_USBSTS_HCE_MASK                      (0x1000U)
#define USB_USBSTS_HCE_SHIFT                     (12U)
#define USB_USBSTS_HCE(x)                        (((uint32_t)(((uint32_t)(x)) << USB_USBSTS_HCE_SHIFT)) & USB_USBSTS_HCE_MASK)
/*! @} */

/*! @name PAGESIZE - Page Size Register */
/*! @{ */

#define USB_PAGESIZE_PAGE_SIZE_MASK              (0xFFFFU)
#define USB_PAGESIZE_PAGE_SIZE_SHIFT             (0U)
#define USB_PAGESIZE_PAGE_SIZE(x)                (((uint32_t)(((uint32_t)(x)) << USB_PAGESIZE_PAGE_SIZE_SHIFT)) & USB_PAGESIZE_PAGE_SIZE_MASK)
/*! @} */

/*! @name DNCTRL - Device Notification Register */
/*! @{ */

#define USB_DNCTRL_N0_N15_MASK                   (0xFFFFU)
#define USB_DNCTRL_N0_N15_SHIFT                  (0U)
#define USB_DNCTRL_N0_N15(x)                     (((uint32_t)(((uint32_t)(x)) << USB_DNCTRL_N0_N15_SHIFT)) & USB_DNCTRL_N0_N15_MASK)
/*! @} */

/*! @name CRCR_LO - CRCR_LO */
/*! @{ */

#define USB_CRCR_LO_RCS_MASK                     (0x1U)
#define USB_CRCR_LO_RCS_SHIFT                    (0U)
#define USB_CRCR_LO_RCS(x)                       (((uint32_t)(((uint32_t)(x)) << USB_CRCR_LO_RCS_SHIFT)) & USB_CRCR_LO_RCS_MASK)

#define USB_CRCR_LO_CS_MASK                      (0x2U)
#define USB_CRCR_LO_CS_SHIFT                     (1U)
#define USB_CRCR_LO_CS(x)                        (((uint32_t)(((uint32_t)(x)) << USB_CRCR_LO_CS_SHIFT)) & USB_CRCR_LO_CS_MASK)

#define USB_CRCR_LO_CA_MASK                      (0x4U)
#define USB_CRCR_LO_CA_SHIFT                     (2U)
#define USB_CRCR_LO_CA(x)                        (((uint32_t)(((uint32_t)(x)) << USB_CRCR_LO_CA_SHIFT)) & USB_CRCR_LO_CA_MASK)

#define USB_CRCR_LO_CRR_MASK                     (0x8U)
#define USB_CRCR_LO_CRR_SHIFT                    (3U)
#define USB_CRCR_LO_CRR(x)                       (((uint32_t)(((uint32_t)(x)) << USB_CRCR_LO_CRR_SHIFT)) & USB_CRCR_LO_CRR_MASK)

#define USB_CRCR_LO_CMD_RING_PNTR_MASK           (0xFFFFFFC0U)
#define USB_CRCR_LO_CMD_RING_PNTR_SHIFT          (6U)
#define USB_CRCR_LO_CMD_RING_PNTR(x)             (((uint32_t)(((uint32_t)(x)) << USB_CRCR_LO_CMD_RING_PNTR_SHIFT)) & USB_CRCR_LO_CMD_RING_PNTR_MASK)
/*! @} */

/*! @name CRCR_HI -  */
/*! @{ */

#define USB_CRCR_HI_CMD_RING_PNTR_MASK           (0xFFFFFFFFU)
#define USB_CRCR_HI_CMD_RING_PNTR_SHIFT          (0U)
#define USB_CRCR_HI_CMD_RING_PNTR(x)             (((uint32_t)(((uint32_t)(x)) << USB_CRCR_HI_CMD_RING_PNTR_SHIFT)) & USB_CRCR_HI_CMD_RING_PNTR_MASK)
/*! @} */

/*! @name DCBAAP_LO - DCBAAP_LO */
/*! @{ */

#define USB_DCBAAP_LO_DEVICE_CONTEXT_BAAP_MASK   (0xFFFFFFC0U)
#define USB_DCBAAP_LO_DEVICE_CONTEXT_BAAP_SHIFT  (6U)
#define USB_DCBAAP_LO_DEVICE_CONTEXT_BAAP(x)     (((uint32_t)(((uint32_t)(x)) << USB_DCBAAP_LO_DEVICE_CONTEXT_BAAP_SHIFT)) & USB_DCBAAP_LO_DEVICE_CONTEXT_BAAP_MASK)
/*! @} */

/*! @name DCBAAP_HI - DCBAAP_HI */
/*! @{ */

#define USB_DCBAAP_HI_DEVICE_CONTEXT_BAAP_MASK   (0xFFFFFFFFU)
#define USB_DCBAAP_HI_DEVICE_CONTEXT_BAAP_SHIFT  (0U)
#define USB_DCBAAP_HI_DEVICE_CONTEXT_BAAP(x)     (((uint32_t)(((uint32_t)(x)) << USB_DCBAAP_HI_DEVICE_CONTEXT_BAAP_SHIFT)) & USB_DCBAAP_HI_DEVICE_CONTEXT_BAAP_MASK)
/*! @} */

/*! @name CONFIG - Configuration Register */
/*! @{ */

#define USB_CONFIG_MAXSLOTSEN_MASK               (0xFFU)
#define USB_CONFIG_MAXSLOTSEN_SHIFT              (0U)
#define USB_CONFIG_MAXSLOTSEN(x)                 (((uint32_t)(((uint32_t)(x)) << USB_CONFIG_MAXSLOTSEN_SHIFT)) & USB_CONFIG_MAXSLOTSEN_MASK)

#define USB_CONFIG_U3E_MASK                      (0x100U)
#define USB_CONFIG_U3E_SHIFT                     (8U)
#define USB_CONFIG_U3E(x)                        (((uint32_t)(((uint32_t)(x)) << USB_CONFIG_U3E_SHIFT)) & USB_CONFIG_U3E_MASK)

#define USB_CONFIG_CIE_MASK                      (0x200U)
#define USB_CONFIG_CIE_SHIFT                     (9U)
#define USB_CONFIG_CIE(x)                        (((uint32_t)(((uint32_t)(x)) << USB_CONFIG_CIE_SHIFT)) & USB_CONFIG_CIE_MASK)
/*! @} */

/*! @name PORTSC_20 - Port Status and Control Register */
/*! @{ */

#define USB_PORTSC_20_CCS_MASK                   (0x1U)
#define USB_PORTSC_20_CCS_SHIFT                  (0U)
#define USB_PORTSC_20_CCS(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_CCS_SHIFT)) & USB_PORTSC_20_CCS_MASK)

#define USB_PORTSC_20_PED_MASK                   (0x2U)
#define USB_PORTSC_20_PED_SHIFT                  (1U)
/*! PED - PED */
#define USB_PORTSC_20_PED(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_PED_SHIFT)) & USB_PORTSC_20_PED_MASK)

#define USB_PORTSC_20_OCA_MASK                   (0x8U)
#define USB_PORTSC_20_OCA_SHIFT                  (3U)
/*! OCA - OCA */
#define USB_PORTSC_20_OCA(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_OCA_SHIFT)) & USB_PORTSC_20_OCA_MASK)

#define USB_PORTSC_20_PR_MASK                    (0x10U)
#define USB_PORTSC_20_PR_SHIFT                   (4U)
/*! PR - PR */
#define USB_PORTSC_20_PR(x)                      (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_PR_SHIFT)) & USB_PORTSC_20_PR_MASK)

#define USB_PORTSC_20_PLS_MASK                   (0x1E0U)
#define USB_PORTSC_20_PLS_SHIFT                  (5U)
/*! PLS - PLS */
#define USB_PORTSC_20_PLS(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_PLS_SHIFT)) & USB_PORTSC_20_PLS_MASK)

#define USB_PORTSC_20_PP_MASK                    (0x200U)
#define USB_PORTSC_20_PP_SHIFT                   (9U)
/*! PP - PP */
#define USB_PORTSC_20_PP(x)                      (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_PP_SHIFT)) & USB_PORTSC_20_PP_MASK)

#define USB_PORTSC_20_PORTSPEED_MASK             (0x3C00U)
#define USB_PORTSC_20_PORTSPEED_SHIFT            (10U)
/*! PORTSPEED - PORTSPEED */
#define USB_PORTSC_20_PORTSPEED(x)               (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_PORTSPEED_SHIFT)) & USB_PORTSC_20_PORTSPEED_MASK)

#define USB_PORTSC_20_PIC_MASK                   (0xC000U)
#define USB_PORTSC_20_PIC_SHIFT                  (14U)
/*! PIC - PIC */
#define USB_PORTSC_20_PIC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_PIC_SHIFT)) & USB_PORTSC_20_PIC_MASK)

#define USB_PORTSC_20_LWS_MASK                   (0x10000U)
#define USB_PORTSC_20_LWS_SHIFT                  (16U)
/*! LWS - LWS */
#define USB_PORTSC_20_LWS(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_LWS_SHIFT)) & USB_PORTSC_20_LWS_MASK)

#define USB_PORTSC_20_CSC_MASK                   (0x20000U)
#define USB_PORTSC_20_CSC_SHIFT                  (17U)
/*! CSC - CSC */
#define USB_PORTSC_20_CSC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_CSC_SHIFT)) & USB_PORTSC_20_CSC_MASK)

#define USB_PORTSC_20_PEC_MASK                   (0x40000U)
#define USB_PORTSC_20_PEC_SHIFT                  (18U)
#define USB_PORTSC_20_PEC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_PEC_SHIFT)) & USB_PORTSC_20_PEC_MASK)

#define USB_PORTSC_20_OCC_MASK                   (0x100000U)
#define USB_PORTSC_20_OCC_SHIFT                  (20U)
/*! OCC - OCC */
#define USB_PORTSC_20_OCC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_OCC_SHIFT)) & USB_PORTSC_20_OCC_MASK)

#define USB_PORTSC_20_PRC_MASK                   (0x200000U)
#define USB_PORTSC_20_PRC_SHIFT                  (21U)
/*! PRC - PRC */
#define USB_PORTSC_20_PRC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_PRC_SHIFT)) & USB_PORTSC_20_PRC_MASK)

#define USB_PORTSC_20_PLC_MASK                   (0x400000U)
#define USB_PORTSC_20_PLC_SHIFT                  (22U)
/*! PLC - PLC */
#define USB_PORTSC_20_PLC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_PLC_SHIFT)) & USB_PORTSC_20_PLC_MASK)

#define USB_PORTSC_20_CAS_MASK                   (0x1000000U)
#define USB_PORTSC_20_CAS_SHIFT                  (24U)
/*! CAS - CAS */
#define USB_PORTSC_20_CAS(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_CAS_SHIFT)) & USB_PORTSC_20_CAS_MASK)

#define USB_PORTSC_20_WCE_MASK                   (0x2000000U)
#define USB_PORTSC_20_WCE_SHIFT                  (25U)
/*! WCE - WCE */
#define USB_PORTSC_20_WCE(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_WCE_SHIFT)) & USB_PORTSC_20_WCE_MASK)

#define USB_PORTSC_20_WDE_MASK                   (0x4000000U)
#define USB_PORTSC_20_WDE_SHIFT                  (26U)
/*! WDE - WDE */
#define USB_PORTSC_20_WDE(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_WDE_SHIFT)) & USB_PORTSC_20_WDE_MASK)

#define USB_PORTSC_20_WOE_MASK                   (0x8000000U)
#define USB_PORTSC_20_WOE_SHIFT                  (27U)
/*! WOE - WOE */
#define USB_PORTSC_20_WOE(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_WOE_SHIFT)) & USB_PORTSC_20_WOE_MASK)

#define USB_PORTSC_20_DR_MASK                    (0x40000000U)
#define USB_PORTSC_20_DR_SHIFT                   (30U)
/*! DR - Reset value */
#define USB_PORTSC_20_DR(x)                      (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_20_DR_SHIFT)) & USB_PORTSC_20_DR_MASK)
/*! @} */

/*! @name PORTPMSC_20 - USB3 Port Power Management Status and Control Register */
/*! @{ */

#define USB_PORTPMSC_20_L1S_MASK                 (0x7U)
#define USB_PORTPMSC_20_L1S_SHIFT                (0U)
/*! L1S - L1 Status (L1S) */
#define USB_PORTPMSC_20_L1S(x)                   (((uint32_t)(((uint32_t)(x)) << USB_PORTPMSC_20_L1S_SHIFT)) & USB_PORTPMSC_20_L1S_MASK)

#define USB_PORTPMSC_20_RWE_MASK                 (0x8U)
#define USB_PORTPMSC_20_RWE_SHIFT                (3U)
/*! RWE - RWE Port Test Control */
#define USB_PORTPMSC_20_RWE(x)                   (((uint32_t)(((uint32_t)(x)) << USB_PORTPMSC_20_RWE_SHIFT)) & USB_PORTPMSC_20_RWE_MASK)

#define USB_PORTPMSC_20_HIRD_MASK                (0xF0U)
#define USB_PORTPMSC_20_HIRD_SHIFT               (4U)
#define USB_PORTPMSC_20_HIRD(x)                  (((uint32_t)(((uint32_t)(x)) << USB_PORTPMSC_20_HIRD_SHIFT)) & USB_PORTPMSC_20_HIRD_MASK)

#define USB_PORTPMSC_20_L1DSLOT_MASK             (0xFF00U)
#define USB_PORTPMSC_20_L1DSLOT_SHIFT            (8U)
#define USB_PORTPMSC_20_L1DSLOT(x)               (((uint32_t)(((uint32_t)(x)) << USB_PORTPMSC_20_L1DSLOT_SHIFT)) & USB_PORTPMSC_20_L1DSLOT_MASK)

#define USB_PORTPMSC_20_HLE_MASK                 (0x10000U)
#define USB_PORTPMSC_20_HLE_SHIFT                (16U)
#define USB_PORTPMSC_20_HLE(x)                   (((uint32_t)(((uint32_t)(x)) << USB_PORTPMSC_20_HLE_SHIFT)) & USB_PORTPMSC_20_HLE_MASK)

#define USB_PORTPMSC_20_PRTTSTCTRL_MASK          (0xF0000000U)
#define USB_PORTPMSC_20_PRTTSTCTRL_SHIFT         (28U)
#define USB_PORTPMSC_20_PRTTSTCTRL(x)            (((uint32_t)(((uint32_t)(x)) << USB_PORTPMSC_20_PRTTSTCTRL_SHIFT)) & USB_PORTPMSC_20_PRTTSTCTRL_MASK)
/*! @} */

/*! @name PORTHLPMC_20 -  */
/*! @{ */

#define USB_PORTHLPMC_20_HIRDM_MASK              (0x3U)
#define USB_PORTHLPMC_20_HIRDM_SHIFT             (0U)
#define USB_PORTHLPMC_20_HIRDM(x)                (((uint32_t)(((uint32_t)(x)) << USB_PORTHLPMC_20_HIRDM_SHIFT)) & USB_PORTHLPMC_20_HIRDM_MASK)

#define USB_PORTHLPMC_20_L1_TIMEOUT_MASK         (0x3FCU)
#define USB_PORTHLPMC_20_L1_TIMEOUT_SHIFT        (2U)
#define USB_PORTHLPMC_20_L1_TIMEOUT(x)           (((uint32_t)(((uint32_t)(x)) << USB_PORTHLPMC_20_L1_TIMEOUT_SHIFT)) & USB_PORTHLPMC_20_L1_TIMEOUT_MASK)

#define USB_PORTHLPMC_20_HIRDD_MASK              (0x3C00U)
#define USB_PORTHLPMC_20_HIRDD_SHIFT             (10U)
#define USB_PORTHLPMC_20_HIRDD(x)                (((uint32_t)(((uint32_t)(x)) << USB_PORTHLPMC_20_HIRDD_SHIFT)) & USB_PORTHLPMC_20_HIRDD_MASK)
/*! @} */

/*! @name PORTSC_30 -  */
/*! @{ */

#define USB_PORTSC_30_CCS_MASK                   (0x1U)
#define USB_PORTSC_30_CCS_SHIFT                  (0U)
#define USB_PORTSC_30_CCS(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_CCS_SHIFT)) & USB_PORTSC_30_CCS_MASK)

#define USB_PORTSC_30_PED_MASK                   (0x2U)
#define USB_PORTSC_30_PED_SHIFT                  (1U)
#define USB_PORTSC_30_PED(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_PED_SHIFT)) & USB_PORTSC_30_PED_MASK)

#define USB_PORTSC_30_OCA_MASK                   (0x8U)
#define USB_PORTSC_30_OCA_SHIFT                  (3U)
#define USB_PORTSC_30_OCA(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_OCA_SHIFT)) & USB_PORTSC_30_OCA_MASK)

#define USB_PORTSC_30_PR_MASK                    (0x10U)
#define USB_PORTSC_30_PR_SHIFT                   (4U)
#define USB_PORTSC_30_PR(x)                      (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_PR_SHIFT)) & USB_PORTSC_30_PR_MASK)

#define USB_PORTSC_30_PLS_MASK                   (0x1E0U)
#define USB_PORTSC_30_PLS_SHIFT                  (5U)
#define USB_PORTSC_30_PLS(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_PLS_SHIFT)) & USB_PORTSC_30_PLS_MASK)

#define USB_PORTSC_30_PP_MASK                    (0x200U)
#define USB_PORTSC_30_PP_SHIFT                   (9U)
#define USB_PORTSC_30_PP(x)                      (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_PP_SHIFT)) & USB_PORTSC_30_PP_MASK)

#define USB_PORTSC_30_PORTSPEED_MASK             (0x3C00U)
#define USB_PORTSC_30_PORTSPEED_SHIFT            (10U)
#define USB_PORTSC_30_PORTSPEED(x)               (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_PORTSPEED_SHIFT)) & USB_PORTSC_30_PORTSPEED_MASK)

#define USB_PORTSC_30_PIC_MASK                   (0xC000U)
#define USB_PORTSC_30_PIC_SHIFT                  (14U)
#define USB_PORTSC_30_PIC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_PIC_SHIFT)) & USB_PORTSC_30_PIC_MASK)

#define USB_PORTSC_30_LWS_MASK                   (0x10000U)
#define USB_PORTSC_30_LWS_SHIFT                  (16U)
#define USB_PORTSC_30_LWS(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_LWS_SHIFT)) & USB_PORTSC_30_LWS_MASK)

#define USB_PORTSC_30_CSC_MASK                   (0x20000U)
#define USB_PORTSC_30_CSC_SHIFT                  (17U)
#define USB_PORTSC_30_CSC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_CSC_SHIFT)) & USB_PORTSC_30_CSC_MASK)

#define USB_PORTSC_30_PEC_MASK                   (0x40000U)
#define USB_PORTSC_30_PEC_SHIFT                  (18U)
#define USB_PORTSC_30_PEC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_PEC_SHIFT)) & USB_PORTSC_30_PEC_MASK)

#define USB_PORTSC_30_WRC_MASK                   (0x80000U)
#define USB_PORTSC_30_WRC_SHIFT                  (19U)
#define USB_PORTSC_30_WRC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_WRC_SHIFT)) & USB_PORTSC_30_WRC_MASK)

#define USB_PORTSC_30_OCC_MASK                   (0x100000U)
#define USB_PORTSC_30_OCC_SHIFT                  (20U)
#define USB_PORTSC_30_OCC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_OCC_SHIFT)) & USB_PORTSC_30_OCC_MASK)

#define USB_PORTSC_30_PRC_MASK                   (0x200000U)
#define USB_PORTSC_30_PRC_SHIFT                  (21U)
/*! PRC - PRC */
#define USB_PORTSC_30_PRC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_PRC_SHIFT)) & USB_PORTSC_30_PRC_MASK)

#define USB_PORTSC_30_PLC_MASK                   (0x400000U)
#define USB_PORTSC_30_PLC_SHIFT                  (22U)
/*! PLC - PLC */
#define USB_PORTSC_30_PLC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_PLC_SHIFT)) & USB_PORTSC_30_PLC_MASK)

#define USB_PORTSC_30_CEC_MASK                   (0x800000U)
#define USB_PORTSC_30_CEC_SHIFT                  (23U)
/*! CEC - CEC */
#define USB_PORTSC_30_CEC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_CEC_SHIFT)) & USB_PORTSC_30_CEC_MASK)

#define USB_PORTSC_30_CAS_MASK                   (0x1000000U)
#define USB_PORTSC_30_CAS_SHIFT                  (24U)
/*! CAS - Cold Attach Status */
#define USB_PORTSC_30_CAS(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_CAS_SHIFT)) & USB_PORTSC_30_CAS_MASK)

#define USB_PORTSC_30_WCE_MASK                   (0x2000000U)
#define USB_PORTSC_30_WCE_SHIFT                  (25U)
/*! WCE - WCE */
#define USB_PORTSC_30_WCE(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_WCE_SHIFT)) & USB_PORTSC_30_WCE_MASK)

#define USB_PORTSC_30_WDE_MASK                   (0x4000000U)
#define USB_PORTSC_30_WDE_SHIFT                  (26U)
/*! WDE - WDE */
#define USB_PORTSC_30_WDE(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_WDE_SHIFT)) & USB_PORTSC_30_WDE_MASK)

#define USB_PORTSC_30_WOE_MASK                   (0x8000000U)
#define USB_PORTSC_30_WOE_SHIFT                  (27U)
/*! WOE - WOE */
#define USB_PORTSC_30_WOE(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_WOE_SHIFT)) & USB_PORTSC_30_WOE_MASK)

#define USB_PORTSC_30_DR_MASK                    (0x40000000U)
#define USB_PORTSC_30_DR_SHIFT                   (30U)
#define USB_PORTSC_30_DR(x)                      (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_DR_SHIFT)) & USB_PORTSC_30_DR_MASK)

#define USB_PORTSC_30_WPR_MASK                   (0x80000000U)
#define USB_PORTSC_30_WPR_SHIFT                  (31U)
#define USB_PORTSC_30_WPR(x)                     (((uint32_t)(((uint32_t)(x)) << USB_PORTSC_30_WPR_SHIFT)) & USB_PORTSC_30_WPR_MASK)
/*! @} */

/*! @name PORTPMSC_30 - USB3 Port Power Management Status and Control Register */
/*! @{ */

#define USB_PORTPMSC_30_U1_TIMEOUT_MASK          (0xFFU)
#define USB_PORTPMSC_30_U1_TIMEOUT_SHIFT         (0U)
/*! U1_TIMEOUT - U1_TIMEOUT */
#define USB_PORTPMSC_30_U1_TIMEOUT(x)            (((uint32_t)(((uint32_t)(x)) << USB_PORTPMSC_30_U1_TIMEOUT_SHIFT)) & USB_PORTPMSC_30_U1_TIMEOUT_MASK)

#define USB_PORTPMSC_30_U2_TIMEOUT_MASK          (0xFF00U)
#define USB_PORTPMSC_30_U2_TIMEOUT_SHIFT         (8U)
/*! U2_TIMEOUT - U2_TIMEOUT */
#define USB_PORTPMSC_30_U2_TIMEOUT(x)            (((uint32_t)(((uint32_t)(x)) << USB_PORTPMSC_30_U2_TIMEOUT_SHIFT)) & USB_PORTPMSC_30_U2_TIMEOUT_MASK)

#define USB_PORTPMSC_30_FLA_MASK                 (0x10000U)
#define USB_PORTPMSC_30_FLA_SHIFT                (16U)
#define USB_PORTPMSC_30_FLA(x)                   (((uint32_t)(((uint32_t)(x)) << USB_PORTPMSC_30_FLA_SHIFT)) & USB_PORTPMSC_30_FLA_MASK)
/*! @} */

/*! @name PORTLI_30 - Port Link Info Register */
/*! @{ */

#define USB_PORTLI_30_LINK_ERROR_COUNT_MASK      (0xFFFFU)
#define USB_PORTLI_30_LINK_ERROR_COUNT_SHIFT     (0U)
/*! LINK_ERROR_COUNT - LINK_ERROR_COUNT */
#define USB_PORTLI_30_LINK_ERROR_COUNT(x)        (((uint32_t)(((uint32_t)(x)) << USB_PORTLI_30_LINK_ERROR_COUNT_SHIFT)) & USB_PORTLI_30_LINK_ERROR_COUNT_MASK)
/*! @} */

/*! @name MFINDEX - Microframe Index Register */
/*! @{ */

#define USB_MFINDEX_MICROFRAME_INDEX_MASK        (0x3FFFU)
#define USB_MFINDEX_MICROFRAME_INDEX_SHIFT       (0U)
#define USB_MFINDEX_MICROFRAME_INDEX(x)          (((uint32_t)(((uint32_t)(x)) << USB_MFINDEX_MICROFRAME_INDEX_SHIFT)) & USB_MFINDEX_MICROFRAME_INDEX_MASK)
/*! @} */

/*! @name IMAN - Interrupter Management Register */
/*! @{ */

#define USB_IMAN_IP_MASK                         (0x1U)
#define USB_IMAN_IP_SHIFT                        (0U)
/*! IP - IP Interrupt Pending */
#define USB_IMAN_IP(x)                           (((uint32_t)(((uint32_t)(x)) << USB_IMAN_IP_SHIFT)) & USB_IMAN_IP_MASK)

#define USB_IMAN_IE_MASK                         (0x2U)
#define USB_IMAN_IE_SHIFT                        (1U)
#define USB_IMAN_IE(x)                           (((uint32_t)(((uint32_t)(x)) << USB_IMAN_IE_SHIFT)) & USB_IMAN_IE_MASK)
/*! @} */

/*! @name IMOD - Interrupter Moderation Register */
/*! @{ */

#define USB_IMOD_IMODI_MASK                      (0xFFFFU)
#define USB_IMOD_IMODI_SHIFT                     (0U)
#define USB_IMOD_IMODI(x)                        (((uint32_t)(((uint32_t)(x)) << USB_IMOD_IMODI_SHIFT)) & USB_IMOD_IMODI_MASK)

#define USB_IMOD_IMODC_MASK                      (0xFFFF0000U)
#define USB_IMOD_IMODC_SHIFT                     (16U)
#define USB_IMOD_IMODC(x)                        (((uint32_t)(((uint32_t)(x)) << USB_IMOD_IMODC_SHIFT)) & USB_IMOD_IMODC_MASK)
/*! @} */

/*! @name ERSTSZ - ERSTSZ */
/*! @{ */

#define USB_ERSTSZ_ERS_TABLE_SIZE_MASK           (0xFFFFU)
#define USB_ERSTSZ_ERS_TABLE_SIZE_SHIFT          (0U)
#define USB_ERSTSZ_ERS_TABLE_SIZE(x)             (((uint32_t)(((uint32_t)(x)) << USB_ERSTSZ_ERS_TABLE_SIZE_SHIFT)) & USB_ERSTSZ_ERS_TABLE_SIZE_MASK)
/*! @} */

/*! @name ERSTBA_LO - ERSTBA_LO */
/*! @{ */

#define USB_ERSTBA_LO_ERS_TABLE_BAR_MASK         (0xFFFFFFC0U)
#define USB_ERSTBA_LO_ERS_TABLE_BAR_SHIFT        (6U)
#define USB_ERSTBA_LO_ERS_TABLE_BAR(x)           (((uint32_t)(((uint32_t)(x)) << USB_ERSTBA_LO_ERS_TABLE_BAR_SHIFT)) & USB_ERSTBA_LO_ERS_TABLE_BAR_MASK)
/*! @} */

/*! @name ERSTBA_HI - ERSTBA_HI */
/*! @{ */

#define USB_ERSTBA_HI_ERS_TABLE_BAR_MASK         (0xFFFFFFFFU)
#define USB_ERSTBA_HI_ERS_TABLE_BAR_SHIFT        (0U)
#define USB_ERSTBA_HI_ERS_TABLE_BAR(x)           (((uint32_t)(((uint32_t)(x)) << USB_ERSTBA_HI_ERS_TABLE_BAR_SHIFT)) & USB_ERSTBA_HI_ERS_TABLE_BAR_MASK)
/*! @} */

/*! @name ERDP_LO - ERDP_LO */
/*! @{ */

#define USB_ERDP_LO_DESI_MASK                    (0x7U)
#define USB_ERDP_LO_DESI_SHIFT                   (0U)
#define USB_ERDP_LO_DESI(x)                      (((uint32_t)(((uint32_t)(x)) << USB_ERDP_LO_DESI_SHIFT)) & USB_ERDP_LO_DESI_MASK)

#define USB_ERDP_LO_EHB_MASK                     (0x8U)
#define USB_ERDP_LO_EHB_SHIFT                    (3U)
/*! EHB - EHB */
#define USB_ERDP_LO_EHB(x)                       (((uint32_t)(((uint32_t)(x)) << USB_ERDP_LO_EHB_SHIFT)) & USB_ERDP_LO_EHB_MASK)

#define USB_ERDP_LO_ERD_PNTR_MASK                (0xFFFFFFF0U)
#define USB_ERDP_LO_ERD_PNTR_SHIFT               (4U)
/*! ERD_PNTR - ERD_PNTR */
#define USB_ERDP_LO_ERD_PNTR(x)                  (((uint32_t)(((uint32_t)(x)) << USB_ERDP_LO_ERD_PNTR_SHIFT)) & USB_ERDP_LO_ERD_PNTR_MASK)
/*! @} */

/*! @name ERDP_HI - ERDP_HI */
/*! @{ */

#define USB_ERDP_HI_ERD_PNTR_MASK                (0xFFFFFFFFU)
#define USB_ERDP_HI_ERD_PNTR_SHIFT               (0U)
#define USB_ERDP_HI_ERD_PNTR(x)                  (((uint32_t)(((uint32_t)(x)) << USB_ERDP_HI_ERD_PNTR_SHIFT)) & USB_ERDP_HI_ERD_PNTR_MASK)
/*! @} */

/*! @name DB - Doorbell Register */
/*! @{ */

#define USB_DB_DB_TARGET_MASK                    (0xFFU)
#define USB_DB_DB_TARGET_SHIFT                   (0U)
#define USB_DB_DB_TARGET(x)                      (((uint32_t)(((uint32_t)(x)) << USB_DB_DB_TARGET_SHIFT)) & USB_DB_DB_TARGET_MASK)

#define USB_DB_DB_STREAM_ID_MASK                 (0xFFFF0000U)
#define USB_DB_DB_STREAM_ID_SHIFT                (16U)
#define USB_DB_DB_STREAM_ID(x)                   (((uint32_t)(((uint32_t)(x)) << USB_DB_DB_STREAM_ID_SHIFT)) & USB_DB_DB_STREAM_ID_MASK)
/*! @} */

/*! @name USBLEGSUP - USBLEGSUP */
/*! @{ */

#define USB_USBLEGSUP_CAPABILITY_ID_MASK         (0xFFU)
#define USB_USBLEGSUP_CAPABILITY_ID_SHIFT        (0U)
#define USB_USBLEGSUP_CAPABILITY_ID(x)           (((uint32_t)(((uint32_t)(x)) << USB_USBLEGSUP_CAPABILITY_ID_SHIFT)) & USB_USBLEGSUP_CAPABILITY_ID_MASK)

#define USB_USBLEGSUP_NEXT_CAPABILITY_POINTER_MASK (0xFF00U)
#define USB_USBLEGSUP_NEXT_CAPABILITY_POINTER_SHIFT (8U)
#define USB_USBLEGSUP_NEXT_CAPABILITY_POINTER(x) (((uint32_t)(((uint32_t)(x)) << USB_USBLEGSUP_NEXT_CAPABILITY_POINTER_SHIFT)) & USB_USBLEGSUP_NEXT_CAPABILITY_POINTER_MASK)

#define USB_USBLEGSUP_HC_BIOS_OWNED_MASK         (0x10000U)
#define USB_USBLEGSUP_HC_BIOS_OWNED_SHIFT        (16U)
#define USB_USBLEGSUP_HC_BIOS_OWNED(x)           (((uint32_t)(((uint32_t)(x)) << USB_USBLEGSUP_HC_BIOS_OWNED_SHIFT)) & USB_USBLEGSUP_HC_BIOS_OWNED_MASK)

#define USB_USBLEGSUP_HC_OS_OWNED_MASK           (0x1000000U)
#define USB_USBLEGSUP_HC_OS_OWNED_SHIFT          (24U)
#define USB_USBLEGSUP_HC_OS_OWNED(x)             (((uint32_t)(((uint32_t)(x)) << USB_USBLEGSUP_HC_OS_OWNED_SHIFT)) & USB_USBLEGSUP_HC_OS_OWNED_MASK)
/*! @} */

/*! @name USBLEGCTLSTS - USBLEGCTLSTS */
/*! @{ */

#define USB_USBLEGCTLSTS_USB_SMI_ENABLE_MASK     (0x1U)
#define USB_USBLEGCTLSTS_USB_SMI_ENABLE_SHIFT    (0U)
#define USB_USBLEGCTLSTS_USB_SMI_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << USB_USBLEGCTLSTS_USB_SMI_ENABLE_SHIFT)) & USB_USBLEGCTLSTS_USB_SMI_ENABLE_MASK)

#define USB_USBLEGCTLSTS_SMI_ON_HOST_E_MASK      (0x10U)
#define USB_USBLEGCTLSTS_SMI_ON_HOST_E_SHIFT     (4U)
#define USB_USBLEGCTLSTS_SMI_ON_HOST_E(x)        (((uint32_t)(((uint32_t)(x)) << USB_USBLEGCTLSTS_SMI_ON_HOST_E_SHIFT)) & USB_USBLEGCTLSTS_SMI_ON_HOST_E_MASK)

#define USB_USBLEGCTLSTS_SMI_ON_OS_E_MASK        (0x2000U)
#define USB_USBLEGCTLSTS_SMI_ON_OS_E_SHIFT       (13U)
#define USB_USBLEGCTLSTS_SMI_ON_OS_E(x)          (((uint32_t)(((uint32_t)(x)) << USB_USBLEGCTLSTS_SMI_ON_OS_E_SHIFT)) & USB_USBLEGCTLSTS_SMI_ON_OS_E_MASK)

#define USB_USBLEGCTLSTS_SMI_ON_PCI_E_MASK       (0x4000U)
#define USB_USBLEGCTLSTS_SMI_ON_PCI_E_SHIFT      (14U)
#define USB_USBLEGCTLSTS_SMI_ON_PCI_E(x)         (((uint32_t)(((uint32_t)(x)) << USB_USBLEGCTLSTS_SMI_ON_PCI_E_SHIFT)) & USB_USBLEGCTLSTS_SMI_ON_PCI_E_MASK)

#define USB_USBLEGCTLSTS_SMI_ON_BAR_E_MASK       (0x8000U)
#define USB_USBLEGCTLSTS_SMI_ON_BAR_E_SHIFT      (15U)
#define USB_USBLEGCTLSTS_SMI_ON_BAR_E(x)         (((uint32_t)(((uint32_t)(x)) << USB_USBLEGCTLSTS_SMI_ON_BAR_E_SHIFT)) & USB_USBLEGCTLSTS_SMI_ON_BAR_E_MASK)

#define USB_USBLEGCTLSTS_SMI_ON_EVENT_MASK       (0x10000U)
#define USB_USBLEGCTLSTS_SMI_ON_EVENT_SHIFT      (16U)
#define USB_USBLEGCTLSTS_SMI_ON_EVENT(x)         (((uint32_t)(((uint32_t)(x)) << USB_USBLEGCTLSTS_SMI_ON_EVENT_SHIFT)) & USB_USBLEGCTLSTS_SMI_ON_EVENT_MASK)

#define USB_USBLEGCTLSTS_SMI_ON_HOST_MASK        (0x100000U)
#define USB_USBLEGCTLSTS_SMI_ON_HOST_SHIFT       (20U)
#define USB_USBLEGCTLSTS_SMI_ON_HOST(x)          (((uint32_t)(((uint32_t)(x)) << USB_USBLEGCTLSTS_SMI_ON_HOST_SHIFT)) & USB_USBLEGCTLSTS_SMI_ON_HOST_MASK)

#define USB_USBLEGCTLSTS_SMI_ON_OS_MASK          (0x20000000U)
#define USB_USBLEGCTLSTS_SMI_ON_OS_SHIFT         (29U)
#define USB_USBLEGCTLSTS_SMI_ON_OS(x)            (((uint32_t)(((uint32_t)(x)) << USB_USBLEGCTLSTS_SMI_ON_OS_SHIFT)) & USB_USBLEGCTLSTS_SMI_ON_OS_MASK)

#define USB_USBLEGCTLSTS_SMI_ON_PCI_MASK         (0x40000000U)
#define USB_USBLEGCTLSTS_SMI_ON_PCI_SHIFT        (30U)
#define USB_USBLEGCTLSTS_SMI_ON_PCI(x)           (((uint32_t)(((uint32_t)(x)) << USB_USBLEGCTLSTS_SMI_ON_PCI_SHIFT)) & USB_USBLEGCTLSTS_SMI_ON_PCI_MASK)

#define USB_USBLEGCTLSTS_SMI_ON_BAR_MASK         (0x80000000U)
#define USB_USBLEGCTLSTS_SMI_ON_BAR_SHIFT        (31U)
#define USB_USBLEGCTLSTS_SMI_ON_BAR(x)           (((uint32_t)(((uint32_t)(x)) << USB_USBLEGCTLSTS_SMI_ON_BAR_SHIFT)) & USB_USBLEGCTLSTS_SMI_ON_BAR_MASK)
/*! @} */

/*! @name SUPTPRT2_DW0 - SUPTPRT2_DW0 */
/*! @{ */

#define USB_SUPTPRT2_DW0_CAPABILITY_ID_MASK      (0xFFU)
#define USB_SUPTPRT2_DW0_CAPABILITY_ID_SHIFT     (0U)
#define USB_SUPTPRT2_DW0_CAPABILITY_ID(x)        (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT2_DW0_CAPABILITY_ID_SHIFT)) & USB_SUPTPRT2_DW0_CAPABILITY_ID_MASK)

#define USB_SUPTPRT2_DW0_NEXT_CAPABILITY_POINTER_MASK (0xFF00U)
#define USB_SUPTPRT2_DW0_NEXT_CAPABILITY_POINTER_SHIFT (8U)
#define USB_SUPTPRT2_DW0_NEXT_CAPABILITY_POINTER(x) (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT2_DW0_NEXT_CAPABILITY_POINTER_SHIFT)) & USB_SUPTPRT2_DW0_NEXT_CAPABILITY_POINTER_MASK)

#define USB_SUPTPRT2_DW0_MINOR_REVISION_MASK     (0xFF0000U)
#define USB_SUPTPRT2_DW0_MINOR_REVISION_SHIFT    (16U)
#define USB_SUPTPRT2_DW0_MINOR_REVISION(x)       (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT2_DW0_MINOR_REVISION_SHIFT)) & USB_SUPTPRT2_DW0_MINOR_REVISION_MASK)

#define USB_SUPTPRT2_DW0_MAJOR_REVISION_MASK     (0xFF000000U)
#define USB_SUPTPRT2_DW0_MAJOR_REVISION_SHIFT    (24U)
#define USB_SUPTPRT2_DW0_MAJOR_REVISION(x)       (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT2_DW0_MAJOR_REVISION_SHIFT)) & USB_SUPTPRT2_DW0_MAJOR_REVISION_MASK)
/*! @} */

/*! @name SUPTPRT2_DW1 - SUPTPRT2_DW1 Register */
/*! @{ */

#define USB_SUPTPRT2_DW1_NAME_STRING_MASK        (0xFFFFFFFFU)
#define USB_SUPTPRT2_DW1_NAME_STRING_SHIFT       (0U)
#define USB_SUPTPRT2_DW1_NAME_STRING(x)          (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT2_DW1_NAME_STRING_SHIFT)) & USB_SUPTPRT2_DW1_NAME_STRING_MASK)
/*! @} */

/*! @name SUPTPRT2_DW2 - xHCI Supported Protocol Capability_ Data Word 2 */
/*! @{ */

#define USB_SUPTPRT2_DW2_COMPATIBLE_PORT_OFFSET_MASK (0xFFU)
#define USB_SUPTPRT2_DW2_COMPATIBLE_PORT_OFFSET_SHIFT (0U)
#define USB_SUPTPRT2_DW2_COMPATIBLE_PORT_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT2_DW2_COMPATIBLE_PORT_OFFSET_SHIFT)) & USB_SUPTPRT2_DW2_COMPATIBLE_PORT_OFFSET_MASK)

#define USB_SUPTPRT2_DW2_COMPATIBLE_PORT_COUNT_MASK (0xFF00U)
#define USB_SUPTPRT2_DW2_COMPATIBLE_PORT_COUNT_SHIFT (8U)
#define USB_SUPTPRT2_DW2_COMPATIBLE_PORT_COUNT(x) (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT2_DW2_COMPATIBLE_PORT_COUNT_SHIFT)) & USB_SUPTPRT2_DW2_COMPATIBLE_PORT_COUNT_MASK)

#define USB_SUPTPRT2_DW2_HSO_MASK                (0x20000U)
#define USB_SUPTPRT2_DW2_HSO_SHIFT               (17U)
#define USB_SUPTPRT2_DW2_HSO(x)                  (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT2_DW2_HSO_SHIFT)) & USB_SUPTPRT2_DW2_HSO_MASK)

#define USB_SUPTPRT2_DW2_IHI_MASK                (0x40000U)
#define USB_SUPTPRT2_DW2_IHI_SHIFT               (18U)
#define USB_SUPTPRT2_DW2_IHI(x)                  (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT2_DW2_IHI_SHIFT)) & USB_SUPTPRT2_DW2_IHI_MASK)

#define USB_SUPTPRT2_DW2_HLC_MASK                (0x80000U)
#define USB_SUPTPRT2_DW2_HLC_SHIFT               (19U)
#define USB_SUPTPRT2_DW2_HLC(x)                  (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT2_DW2_HLC_SHIFT)) & USB_SUPTPRT2_DW2_HLC_MASK)

#define USB_SUPTPRT2_DW2_BLC_MASK                (0x100000U)
#define USB_SUPTPRT2_DW2_BLC_SHIFT               (20U)
/*! BLC - BESL LPM Capability */
#define USB_SUPTPRT2_DW2_BLC(x)                  (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT2_DW2_BLC_SHIFT)) & USB_SUPTPRT2_DW2_BLC_MASK)

#define USB_SUPTPRT2_DW2_MHD_MASK                (0xE000000U)
#define USB_SUPTPRT2_DW2_MHD_SHIFT               (25U)
/*! MHD - Hub Depth */
#define USB_SUPTPRT2_DW2_MHD(x)                  (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT2_DW2_MHD_SHIFT)) & USB_SUPTPRT2_DW2_MHD_MASK)

#define USB_SUPTPRT2_DW2_PSIC_MASK               (0xF0000000U)
#define USB_SUPTPRT2_DW2_PSIC_SHIFT              (28U)
#define USB_SUPTPRT2_DW2_PSIC(x)                 (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT2_DW2_PSIC_SHIFT)) & USB_SUPTPRT2_DW2_PSIC_MASK)
/*! @} */

/*! @name SUPTPRT2_DW3 - SUPTPRT2_DW3 Register */
/*! @{ */

#define USB_SUPTPRT2_DW3_PROTCL_SLT_TY_MASK      (0x1FU)
#define USB_SUPTPRT2_DW3_PROTCL_SLT_TY_SHIFT     (0U)
#define USB_SUPTPRT2_DW3_PROTCL_SLT_TY(x)        (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT2_DW3_PROTCL_SLT_TY_SHIFT)) & USB_SUPTPRT2_DW3_PROTCL_SLT_TY_MASK)
/*! @} */

/*! @name SUPTPRT3_DW0 -  */
/*! @{ */

#define USB_SUPTPRT3_DW0_CAPABILITY_ID_MASK      (0xFFU)
#define USB_SUPTPRT3_DW0_CAPABILITY_ID_SHIFT     (0U)
#define USB_SUPTPRT3_DW0_CAPABILITY_ID(x)        (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT3_DW0_CAPABILITY_ID_SHIFT)) & USB_SUPTPRT3_DW0_CAPABILITY_ID_MASK)

#define USB_SUPTPRT3_DW0_NEXT_CAPABILITY_POINTER_MASK (0xFF00U)
#define USB_SUPTPRT3_DW0_NEXT_CAPABILITY_POINTER_SHIFT (8U)
#define USB_SUPTPRT3_DW0_NEXT_CAPABILITY_POINTER(x) (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT3_DW0_NEXT_CAPABILITY_POINTER_SHIFT)) & USB_SUPTPRT3_DW0_NEXT_CAPABILITY_POINTER_MASK)

#define USB_SUPTPRT3_DW0_MINOR_REVISION_MASK     (0xFF0000U)
#define USB_SUPTPRT3_DW0_MINOR_REVISION_SHIFT    (16U)
#define USB_SUPTPRT3_DW0_MINOR_REVISION(x)       (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT3_DW0_MINOR_REVISION_SHIFT)) & USB_SUPTPRT3_DW0_MINOR_REVISION_MASK)

#define USB_SUPTPRT3_DW0_MAJOR_REVISION_MASK     (0xFF000000U)
#define USB_SUPTPRT3_DW0_MAJOR_REVISION_SHIFT    (24U)
#define USB_SUPTPRT3_DW0_MAJOR_REVISION(x)       (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT3_DW0_MAJOR_REVISION_SHIFT)) & USB_SUPTPRT3_DW0_MAJOR_REVISION_MASK)
/*! @} */

/*! @name SUPTPRT3_DW1 - SUPTPRT3_DW1 Register */
/*! @{ */

#define USB_SUPTPRT3_DW1_NAME_STRING_MASK        (0xFFFFFFFFU)
#define USB_SUPTPRT3_DW1_NAME_STRING_SHIFT       (0U)
/*! NAME_STRING - NAME_STRING */
#define USB_SUPTPRT3_DW1_NAME_STRING(x)          (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT3_DW1_NAME_STRING_SHIFT)) & USB_SUPTPRT3_DW1_NAME_STRING_MASK)
/*! @} */

/*! @name SUPTPRT3_DW2 - SUPTPRT3_DW2 */
/*! @{ */

#define USB_SUPTPRT3_DW2_COMPATIBLE_PORT_OFFSET_MASK (0xFFU)
#define USB_SUPTPRT3_DW2_COMPATIBLE_PORT_OFFSET_SHIFT (0U)
/*! COMPATIBLE_PORT_OFFSET - COMPATIBLE_PORT_OFFSET */
#define USB_SUPTPRT3_DW2_COMPATIBLE_PORT_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT3_DW2_COMPATIBLE_PORT_OFFSET_SHIFT)) & USB_SUPTPRT3_DW2_COMPATIBLE_PORT_OFFSET_MASK)

#define USB_SUPTPRT3_DW2_COMPATIBLE_PORT_COUNT_MASK (0xFF00U)
#define USB_SUPTPRT3_DW2_COMPATIBLE_PORT_COUNT_SHIFT (8U)
/*! COMPATIBLE_PORT_COUNT - COMPATIBLE_PORT_COUNT */
#define USB_SUPTPRT3_DW2_COMPATIBLE_PORT_COUNT(x) (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT3_DW2_COMPATIBLE_PORT_COUNT_SHIFT)) & USB_SUPTPRT3_DW2_COMPATIBLE_PORT_COUNT_MASK)

#define USB_SUPTPRT3_DW2_MHD_MASK                (0xE000000U)
#define USB_SUPTPRT3_DW2_MHD_SHIFT               (25U)
/*! MHD - Hub Depth */
#define USB_SUPTPRT3_DW2_MHD(x)                  (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT3_DW2_MHD_SHIFT)) & USB_SUPTPRT3_DW2_MHD_MASK)

#define USB_SUPTPRT3_DW2_PSIC_MASK               (0xF0000000U)
#define USB_SUPTPRT3_DW2_PSIC_SHIFT              (28U)
#define USB_SUPTPRT3_DW2_PSIC(x)                 (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT3_DW2_PSIC_SHIFT)) & USB_SUPTPRT3_DW2_PSIC_MASK)
/*! @} */

/*! @name SUPTPRT3_DW3 - SUPTPRT3_DW3 */
/*! @{ */

#define USB_SUPTPRT3_DW3_PROTCL_SLT_TY_MASK      (0x1FU)
#define USB_SUPTPRT3_DW3_PROTCL_SLT_TY_SHIFT     (0U)
/*! PROTCL_SLT_TY - Protocol Slot Type */
#define USB_SUPTPRT3_DW3_PROTCL_SLT_TY(x)        (((uint32_t)(((uint32_t)(x)) << USB_SUPTPRT3_DW3_PROTCL_SLT_TY_SHIFT)) & USB_SUPTPRT3_DW3_PROTCL_SLT_TY_MASK)
/*! @} */

/*! @name GSBUSCFG0 - Global SoC Bus Configuration Register 0 */
/*! @{ */

#define USB_GSBUSCFG0_INCRBRSTENA_MASK           (0x1U)
#define USB_GSBUSCFG0_INCRBRSTENA_SHIFT          (0U)
/*! INCRBRSTENA - INCRBRSTENA */
#define USB_GSBUSCFG0_INCRBRSTENA(x)             (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG0_INCRBRSTENA_SHIFT)) & USB_GSBUSCFG0_INCRBRSTENA_MASK)

#define USB_GSBUSCFG0_INCR4BRSTENA_MASK          (0x2U)
#define USB_GSBUSCFG0_INCR4BRSTENA_SHIFT         (1U)
/*! INCR4BRSTENA - INCR4BRSTENA */
#define USB_GSBUSCFG0_INCR4BRSTENA(x)            (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG0_INCR4BRSTENA_SHIFT)) & USB_GSBUSCFG0_INCR4BRSTENA_MASK)

#define USB_GSBUSCFG0_INCR8BRSTENA_MASK          (0x4U)
#define USB_GSBUSCFG0_INCR8BRSTENA_SHIFT         (2U)
/*! INCR8BRSTENA - INCR8BRSTENA */
#define USB_GSBUSCFG0_INCR8BRSTENA(x)            (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG0_INCR8BRSTENA_SHIFT)) & USB_GSBUSCFG0_INCR8BRSTENA_MASK)

#define USB_GSBUSCFG0_INCR16BRSTENA_MASK         (0x8U)
#define USB_GSBUSCFG0_INCR16BRSTENA_SHIFT        (3U)
/*! INCR16BRSTENA - INCR16BRSTENA */
#define USB_GSBUSCFG0_INCR16BRSTENA(x)           (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG0_INCR16BRSTENA_SHIFT)) & USB_GSBUSCFG0_INCR16BRSTENA_MASK)

#define USB_GSBUSCFG0_INCR32BRSTENA_MASK         (0x10U)
#define USB_GSBUSCFG0_INCR32BRSTENA_SHIFT        (4U)
/*! INCR32BRSTENA - INCR32BRSTENA */
#define USB_GSBUSCFG0_INCR32BRSTENA(x)           (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG0_INCR32BRSTENA_SHIFT)) & USB_GSBUSCFG0_INCR32BRSTENA_MASK)

#define USB_GSBUSCFG0_INCR64BRSTENA_MASK         (0x20U)
#define USB_GSBUSCFG0_INCR64BRSTENA_SHIFT        (5U)
#define USB_GSBUSCFG0_INCR64BRSTENA(x)           (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG0_INCR64BRSTENA_SHIFT)) & USB_GSBUSCFG0_INCR64BRSTENA_MASK)

#define USB_GSBUSCFG0_INCR128BRSTENA_MASK        (0x40U)
#define USB_GSBUSCFG0_INCR128BRSTENA_SHIFT       (6U)
#define USB_GSBUSCFG0_INCR128BRSTENA(x)          (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG0_INCR128BRSTENA_SHIFT)) & USB_GSBUSCFG0_INCR128BRSTENA_MASK)

#define USB_GSBUSCFG0_INCR256BRSTENA_MASK        (0x80U)
#define USB_GSBUSCFG0_INCR256BRSTENA_SHIFT       (7U)
#define USB_GSBUSCFG0_INCR256BRSTENA(x)          (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG0_INCR256BRSTENA_SHIFT)) & USB_GSBUSCFG0_INCR256BRSTENA_MASK)

#define USB_GSBUSCFG0_DESBIGEND_MASK             (0x400U)
#define USB_GSBUSCFG0_DESBIGEND_SHIFT            (10U)
#define USB_GSBUSCFG0_DESBIGEND(x)               (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG0_DESBIGEND_SHIFT)) & USB_GSBUSCFG0_DESBIGEND_MASK)

#define USB_GSBUSCFG0_DATBIGEND_MASK             (0x800U)
#define USB_GSBUSCFG0_DATBIGEND_SHIFT            (11U)
#define USB_GSBUSCFG0_DATBIGEND(x)               (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG0_DATBIGEND_SHIFT)) & USB_GSBUSCFG0_DATBIGEND_MASK)

#define USB_GSBUSCFG0_DESWRREQINFO_MASK          (0xF0000U)
#define USB_GSBUSCFG0_DESWRREQINFO_SHIFT         (16U)
#define USB_GSBUSCFG0_DESWRREQINFO(x)            (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG0_DESWRREQINFO_SHIFT)) & USB_GSBUSCFG0_DESWRREQINFO_MASK)

#define USB_GSBUSCFG0_DATWRREQINFO_MASK          (0xF00000U)
#define USB_GSBUSCFG0_DATWRREQINFO_SHIFT         (20U)
#define USB_GSBUSCFG0_DATWRREQINFO(x)            (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG0_DATWRREQINFO_SHIFT)) & USB_GSBUSCFG0_DATWRREQINFO_MASK)

#define USB_GSBUSCFG0_DESRDREQINFO_MASK          (0xF000000U)
#define USB_GSBUSCFG0_DESRDREQINFO_SHIFT         (24U)
#define USB_GSBUSCFG0_DESRDREQINFO(x)            (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG0_DESRDREQINFO_SHIFT)) & USB_GSBUSCFG0_DESRDREQINFO_MASK)

#define USB_GSBUSCFG0_DATRDREQINFO_MASK          (0xF0000000U)
#define USB_GSBUSCFG0_DATRDREQINFO_SHIFT         (28U)
#define USB_GSBUSCFG0_DATRDREQINFO(x)            (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG0_DATRDREQINFO_SHIFT)) & USB_GSBUSCFG0_DATRDREQINFO_MASK)
/*! @} */

/*! @name GSBUSCFG1 - Global SoC Bus Configuration Register 1 */
/*! @{ */

#define USB_GSBUSCFG1_PIPETRANSLIMIT_MASK        (0xF00U)
#define USB_GSBUSCFG1_PIPETRANSLIMIT_SHIFT       (8U)
#define USB_GSBUSCFG1_PIPETRANSLIMIT(x)          (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG1_PIPETRANSLIMIT_SHIFT)) & USB_GSBUSCFG1_PIPETRANSLIMIT_MASK)

#define USB_GSBUSCFG1_EN1KPAGE_MASK              (0x1000U)
#define USB_GSBUSCFG1_EN1KPAGE_SHIFT             (12U)
#define USB_GSBUSCFG1_EN1KPAGE(x)                (((uint32_t)(((uint32_t)(x)) << USB_GSBUSCFG1_EN1KPAGE_SHIFT)) & USB_GSBUSCFG1_EN1KPAGE_MASK)
/*! @} */

/*! @name GTXTHRCFG - Global Tx Threshold Control Register */
/*! @{ */

#define USB_GTXTHRCFG_USBMAXTXBURSTSIZE_MASK     (0xFF0000U)
#define USB_GTXTHRCFG_USBMAXTXBURSTSIZE_SHIFT    (16U)
#define USB_GTXTHRCFG_USBMAXTXBURSTSIZE(x)       (((uint32_t)(((uint32_t)(x)) << USB_GTXTHRCFG_USBMAXTXBURSTSIZE_SHIFT)) & USB_GTXTHRCFG_USBMAXTXBURSTSIZE_MASK)

#define USB_GTXTHRCFG_USBTXPKTCNT_MASK           (0xF000000U)
#define USB_GTXTHRCFG_USBTXPKTCNT_SHIFT          (24U)
#define USB_GTXTHRCFG_USBTXPKTCNT(x)             (((uint32_t)(((uint32_t)(x)) << USB_GTXTHRCFG_USBTXPKTCNT_SHIFT)) & USB_GTXTHRCFG_USBTXPKTCNT_MASK)

#define USB_GTXTHRCFG_USBTXPKTCNTSEL_MASK        (0x20000000U)
#define USB_GTXTHRCFG_USBTXPKTCNTSEL_SHIFT       (29U)
#define USB_GTXTHRCFG_USBTXPKTCNTSEL(x)          (((uint32_t)(((uint32_t)(x)) << USB_GTXTHRCFG_USBTXPKTCNTSEL_SHIFT)) & USB_GTXTHRCFG_USBTXPKTCNTSEL_MASK)
/*! @} */

/*! @name GRXTHRCFG - Global Rx Threshold Control Register */
/*! @{ */

#define USB_GRXTHRCFG_RESVISOCOUTSPC_MASK        (0x1FFFU)
#define USB_GRXTHRCFG_RESVISOCOUTSPC_SHIFT       (0U)
#define USB_GRXTHRCFG_RESVISOCOUTSPC(x)          (((uint32_t)(((uint32_t)(x)) << USB_GRXTHRCFG_RESVISOCOUTSPC_SHIFT)) & USB_GRXTHRCFG_RESVISOCOUTSPC_MASK)

#define USB_GRXTHRCFG_USBMAXRXBURSTSIZE_MASK     (0xF80000U)
#define USB_GRXTHRCFG_USBMAXRXBURSTSIZE_SHIFT    (19U)
#define USB_GRXTHRCFG_USBMAXRXBURSTSIZE(x)       (((uint32_t)(((uint32_t)(x)) << USB_GRXTHRCFG_USBMAXRXBURSTSIZE_SHIFT)) & USB_GRXTHRCFG_USBMAXRXBURSTSIZE_MASK)

#define USB_GRXTHRCFG_USBRXPKTCNT_MASK           (0xF000000U)
#define USB_GRXTHRCFG_USBRXPKTCNT_SHIFT          (24U)
#define USB_GRXTHRCFG_USBRXPKTCNT(x)             (((uint32_t)(((uint32_t)(x)) << USB_GRXTHRCFG_USBRXPKTCNT_SHIFT)) & USB_GRXTHRCFG_USBRXPKTCNT_MASK)

#define USB_GRXTHRCFG_USBRXPKTCNTSEL_MASK        (0x20000000U)
#define USB_GRXTHRCFG_USBRXPKTCNTSEL_SHIFT       (29U)
#define USB_GRXTHRCFG_USBRXPKTCNTSEL(x)          (((uint32_t)(((uint32_t)(x)) << USB_GRXTHRCFG_USBRXPKTCNTSEL_SHIFT)) & USB_GRXTHRCFG_USBRXPKTCNTSEL_MASK)
/*! @} */

/*! @name GCTL - Global Core Control Register */
/*! @{ */

#define USB_GCTL_DSBLCLKGTNG_MASK                (0x1U)
#define USB_GCTL_DSBLCLKGTNG_SHIFT               (0U)
#define USB_GCTL_DSBLCLKGTNG(x)                  (((uint32_t)(((uint32_t)(x)) << USB_GCTL_DSBLCLKGTNG_SHIFT)) & USB_GCTL_DSBLCLKGTNG_MASK)

#define USB_GCTL_GBLHIBERNATIONEN_MASK           (0x2U)
#define USB_GCTL_GBLHIBERNATIONEN_SHIFT          (1U)
#define USB_GCTL_GBLHIBERNATIONEN(x)             (((uint32_t)(((uint32_t)(x)) << USB_GCTL_GBLHIBERNATIONEN_SHIFT)) & USB_GCTL_GBLHIBERNATIONEN_MASK)

#define USB_GCTL_U2EXIT_LFPS_MASK                (0x4U)
#define USB_GCTL_U2EXIT_LFPS_SHIFT               (2U)
#define USB_GCTL_U2EXIT_LFPS(x)                  (((uint32_t)(((uint32_t)(x)) << USB_GCTL_U2EXIT_LFPS_SHIFT)) & USB_GCTL_U2EXIT_LFPS_MASK)

#define USB_GCTL_DISSCRAMBLE_MASK                (0x8U)
#define USB_GCTL_DISSCRAMBLE_SHIFT               (3U)
#define USB_GCTL_DISSCRAMBLE(x)                  (((uint32_t)(((uint32_t)(x)) << USB_GCTL_DISSCRAMBLE_SHIFT)) & USB_GCTL_DISSCRAMBLE_MASK)

#define USB_GCTL_SCALEDOWN_MASK                  (0x30U)
#define USB_GCTL_SCALEDOWN_SHIFT                 (4U)
#define USB_GCTL_SCALEDOWN(x)                    (((uint32_t)(((uint32_t)(x)) << USB_GCTL_SCALEDOWN_SHIFT)) & USB_GCTL_SCALEDOWN_MASK)

#define USB_GCTL_RAMCLKSEL_MASK                  (0xC0U)
#define USB_GCTL_RAMCLKSEL_SHIFT                 (6U)
#define USB_GCTL_RAMCLKSEL(x)                    (((uint32_t)(((uint32_t)(x)) << USB_GCTL_RAMCLKSEL_SHIFT)) & USB_GCTL_RAMCLKSEL_MASK)

#define USB_GCTL_DEBUGATTACH_MASK                (0x100U)
#define USB_GCTL_DEBUGATTACH_SHIFT               (8U)
#define USB_GCTL_DEBUGATTACH(x)                  (((uint32_t)(((uint32_t)(x)) << USB_GCTL_DEBUGATTACH_SHIFT)) & USB_GCTL_DEBUGATTACH_MASK)

#define USB_GCTL_U1U2TIMERSCALE_MASK             (0x200U)
#define USB_GCTL_U1U2TIMERSCALE_SHIFT            (9U)
#define USB_GCTL_U1U2TIMERSCALE(x)               (((uint32_t)(((uint32_t)(x)) << USB_GCTL_U1U2TIMERSCALE_SHIFT)) & USB_GCTL_U1U2TIMERSCALE_MASK)

#define USB_GCTL_SOFITPSYNC_MASK                 (0x400U)
#define USB_GCTL_SOFITPSYNC_SHIFT                (10U)
#define USB_GCTL_SOFITPSYNC(x)                   (((uint32_t)(((uint32_t)(x)) << USB_GCTL_SOFITPSYNC_SHIFT)) & USB_GCTL_SOFITPSYNC_MASK)

#define USB_GCTL_CORESOFTRESET_MASK              (0x800U)
#define USB_GCTL_CORESOFTRESET_SHIFT             (11U)
#define USB_GCTL_CORESOFTRESET(x)                (((uint32_t)(((uint32_t)(x)) << USB_GCTL_CORESOFTRESET_SHIFT)) & USB_GCTL_CORESOFTRESET_MASK)

#define USB_GCTL_PRTCAPDIR_MASK                  (0x3000U)
#define USB_GCTL_PRTCAPDIR_SHIFT                 (12U)
#define USB_GCTL_PRTCAPDIR(x)                    (((uint32_t)(((uint32_t)(x)) << USB_GCTL_PRTCAPDIR_SHIFT)) & USB_GCTL_PRTCAPDIR_MASK)

#define USB_GCTL_FRMSCLDWN_MASK                  (0xC000U)
#define USB_GCTL_FRMSCLDWN_SHIFT                 (14U)
#define USB_GCTL_FRMSCLDWN(x)                    (((uint32_t)(((uint32_t)(x)) << USB_GCTL_FRMSCLDWN_SHIFT)) & USB_GCTL_FRMSCLDWN_MASK)

#define USB_GCTL_U2RSTECN_MASK                   (0x10000U)
#define USB_GCTL_U2RSTECN_SHIFT                  (16U)
#define USB_GCTL_U2RSTECN(x)                     (((uint32_t)(((uint32_t)(x)) << USB_GCTL_U2RSTECN_SHIFT)) & USB_GCTL_U2RSTECN_MASK)

#define USB_GCTL_BYPSSETADDR_MASK                (0x20000U)
#define USB_GCTL_BYPSSETADDR_SHIFT               (17U)
#define USB_GCTL_BYPSSETADDR(x)                  (((uint32_t)(((uint32_t)(x)) << USB_GCTL_BYPSSETADDR_SHIFT)) & USB_GCTL_BYPSSETADDR_MASK)

#define USB_GCTL_MASTERFILTBYPASS_MASK           (0x40000U)
#define USB_GCTL_MASTERFILTBYPASS_SHIFT          (18U)
#define USB_GCTL_MASTERFILTBYPASS(x)             (((uint32_t)(((uint32_t)(x)) << USB_GCTL_MASTERFILTBYPASS_SHIFT)) & USB_GCTL_MASTERFILTBYPASS_MASK)

#define USB_GCTL_PWRDNSCALE_MASK                 (0xFFF80000U)
#define USB_GCTL_PWRDNSCALE_SHIFT                (19U)
#define USB_GCTL_PWRDNSCALE(x)                   (((uint32_t)(((uint32_t)(x)) << USB_GCTL_PWRDNSCALE_SHIFT)) & USB_GCTL_PWRDNSCALE_MASK)
/*! @} */

/*! @name GSTS - Global Status Register */
/*! @{ */

#define USB_GSTS_CURMOD_MASK                     (0x3U)
#define USB_GSTS_CURMOD_SHIFT                    (0U)
#define USB_GSTS_CURMOD(x)                       (((uint32_t)(((uint32_t)(x)) << USB_GSTS_CURMOD_SHIFT)) & USB_GSTS_CURMOD_MASK)

#define USB_GSTS_BUSERRADDRVLD_MASK              (0x10U)
#define USB_GSTS_BUSERRADDRVLD_SHIFT             (4U)
#define USB_GSTS_BUSERRADDRVLD(x)                (((uint32_t)(((uint32_t)(x)) << USB_GSTS_BUSERRADDRVLD_SHIFT)) & USB_GSTS_BUSERRADDRVLD_MASK)

#define USB_GSTS_CSRTIMEOUT_MASK                 (0x20U)
#define USB_GSTS_CSRTIMEOUT_SHIFT                (5U)
#define USB_GSTS_CSRTIMEOUT(x)                   (((uint32_t)(((uint32_t)(x)) << USB_GSTS_CSRTIMEOUT_SHIFT)) & USB_GSTS_CSRTIMEOUT_MASK)

#define USB_GSTS_DEVICE_IP_MASK                  (0x40U)
#define USB_GSTS_DEVICE_IP_SHIFT                 (6U)
#define USB_GSTS_DEVICE_IP(x)                    (((uint32_t)(((uint32_t)(x)) << USB_GSTS_DEVICE_IP_SHIFT)) & USB_GSTS_DEVICE_IP_MASK)

#define USB_GSTS_HOST_IP_MASK                    (0x80U)
#define USB_GSTS_HOST_IP_SHIFT                   (7U)
#define USB_GSTS_HOST_IP(x)                      (((uint32_t)(((uint32_t)(x)) << USB_GSTS_HOST_IP_SHIFT)) & USB_GSTS_HOST_IP_MASK)

#define USB_GSTS_BC_IP_MASK                      (0x200U)
#define USB_GSTS_BC_IP_SHIFT                     (9U)
#define USB_GSTS_BC_IP(x)                        (((uint32_t)(((uint32_t)(x)) << USB_GSTS_BC_IP_SHIFT)) & USB_GSTS_BC_IP_MASK)

#define USB_GSTS_SSIC_IP_MASK                    (0x800U)
#define USB_GSTS_SSIC_IP_SHIFT                   (11U)
#define USB_GSTS_SSIC_IP(x)                      (((uint32_t)(((uint32_t)(x)) << USB_GSTS_SSIC_IP_SHIFT)) & USB_GSTS_SSIC_IP_MASK)

#define USB_GSTS_CBELT_MASK                      (0xFFF00000U)
#define USB_GSTS_CBELT_SHIFT                     (20U)
#define USB_GSTS_CBELT(x)                        (((uint32_t)(((uint32_t)(x)) << USB_GSTS_CBELT_SHIFT)) & USB_GSTS_CBELT_MASK)
/*! @} */

/*! @name GUCTL1 -  */
/*! @{ */

#define USB_GUCTL1_LOA_FILTER_EN_MASK            (0x1U)
#define USB_GUCTL1_LOA_FILTER_EN_SHIFT           (0U)
#define USB_GUCTL1_LOA_FILTER_EN(x)              (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_LOA_FILTER_EN_SHIFT)) & USB_GUCTL1_LOA_FILTER_EN_MASK)

#define USB_GUCTL1_OVRLD_L1_SUSP_COM_MASK        (0x2U)
#define USB_GUCTL1_OVRLD_L1_SUSP_COM_SHIFT       (1U)
#define USB_GUCTL1_OVRLD_L1_SUSP_COM(x)          (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_OVRLD_L1_SUSP_COM_SHIFT)) & USB_GUCTL1_OVRLD_L1_SUSP_COM_MASK)

#define USB_GUCTL1_HC_PARCHK_DISABLE_MASK        (0x4U)
#define USB_GUCTL1_HC_PARCHK_DISABLE_SHIFT       (2U)
#define USB_GUCTL1_HC_PARCHK_DISABLE(x)          (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_HC_PARCHK_DISABLE_SHIFT)) & USB_GUCTL1_HC_PARCHK_DISABLE_MASK)

#define USB_GUCTL1_HC_ERRATA_ENABLE_MASK         (0x8U)
#define USB_GUCTL1_HC_ERRATA_ENABLE_SHIFT        (3U)
#define USB_GUCTL1_HC_ERRATA_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_HC_ERRATA_ENABLE_SHIFT)) & USB_GUCTL1_HC_ERRATA_ENABLE_MASK)

#define USB_GUCTL1_L1_SUSP_THRLD_FOR_HOST_MASK   (0xF0U)
#define USB_GUCTL1_L1_SUSP_THRLD_FOR_HOST_SHIFT  (4U)
#define USB_GUCTL1_L1_SUSP_THRLD_FOR_HOST(x)     (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_L1_SUSP_THRLD_FOR_HOST_SHIFT)) & USB_GUCTL1_L1_SUSP_THRLD_FOR_HOST_MASK)

#define USB_GUCTL1_L1_SUSP_THRLD_EN_FOR_HOST_MASK (0x100U)
#define USB_GUCTL1_L1_SUSP_THRLD_EN_FOR_HOST_SHIFT (8U)
#define USB_GUCTL1_L1_SUSP_THRLD_EN_FOR_HOST(x)  (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_L1_SUSP_THRLD_EN_FOR_HOST_SHIFT)) & USB_GUCTL1_L1_SUSP_THRLD_EN_FOR_HOST_MASK)

#define USB_GUCTL1_DEV_HS_NYET_BULK_SPR_MASK     (0x200U)
#define USB_GUCTL1_DEV_HS_NYET_BULK_SPR_SHIFT    (9U)
#define USB_GUCTL1_DEV_HS_NYET_BULK_SPR(x)       (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_DEV_HS_NYET_BULK_SPR_SHIFT)) & USB_GUCTL1_DEV_HS_NYET_BULK_SPR_MASK)

#define USB_GUCTL1_RESUME_OPMODE_HS_HOST_MASK    (0x400U)
#define USB_GUCTL1_RESUME_OPMODE_HS_HOST_SHIFT   (10U)
#define USB_GUCTL1_RESUME_OPMODE_HS_HOST(x)      (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_RESUME_OPMODE_HS_HOST_SHIFT)) & USB_GUCTL1_RESUME_OPMODE_HS_HOST_MASK)

#define USB_GUCTL1_PARKMODE_DISABLE_FSLS_MASK    (0x8000U)
#define USB_GUCTL1_PARKMODE_DISABLE_FSLS_SHIFT   (15U)
#define USB_GUCTL1_PARKMODE_DISABLE_FSLS(x)      (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_PARKMODE_DISABLE_FSLS_SHIFT)) & USB_GUCTL1_PARKMODE_DISABLE_FSLS_MASK)

#define USB_GUCTL1_PARKMODE_DISABLE_HS_MASK      (0x10000U)
#define USB_GUCTL1_PARKMODE_DISABLE_HS_SHIFT     (16U)
#define USB_GUCTL1_PARKMODE_DISABLE_HS(x)        (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_PARKMODE_DISABLE_HS_SHIFT)) & USB_GUCTL1_PARKMODE_DISABLE_HS_MASK)

#define USB_GUCTL1_PARKMODE_DISABLE_SS_MASK      (0x20000U)
#define USB_GUCTL1_PARKMODE_DISABLE_SS_SHIFT     (17U)
#define USB_GUCTL1_PARKMODE_DISABLE_SS(x)        (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_PARKMODE_DISABLE_SS_SHIFT)) & USB_GUCTL1_PARKMODE_DISABLE_SS_MASK)

#define USB_GUCTL1_NAK_PER_ENH_HS_MASK           (0x40000U)
#define USB_GUCTL1_NAK_PER_ENH_HS_SHIFT          (18U)
#define USB_GUCTL1_NAK_PER_ENH_HS(x)             (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_NAK_PER_ENH_HS_SHIFT)) & USB_GUCTL1_NAK_PER_ENH_HS_MASK)

#define USB_GUCTL1_NAK_PER_ENH_FS_MASK           (0x80000U)
#define USB_GUCTL1_NAK_PER_ENH_FS_SHIFT          (19U)
#define USB_GUCTL1_NAK_PER_ENH_FS(x)             (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_NAK_PER_ENH_FS_SHIFT)) & USB_GUCTL1_NAK_PER_ENH_FS_MASK)

#define USB_GUCTL1_DEV_LSP_TAIL_LOCK_DIS_MASK    (0x100000U)
#define USB_GUCTL1_DEV_LSP_TAIL_LOCK_DIS_SHIFT   (20U)
#define USB_GUCTL1_DEV_LSP_TAIL_LOCK_DIS(x)      (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_DEV_LSP_TAIL_LOCK_DIS_SHIFT)) & USB_GUCTL1_DEV_LSP_TAIL_LOCK_DIS_MASK)

#define USB_GUCTL1_IP_GAP_ADD_ON_MASK            (0xE00000U)
#define USB_GUCTL1_IP_GAP_ADD_ON_SHIFT           (21U)
#define USB_GUCTL1_IP_GAP_ADD_ON(x)              (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_IP_GAP_ADD_ON_SHIFT)) & USB_GUCTL1_IP_GAP_ADD_ON_MASK)

#define USB_GUCTL1_DEV_L1_EXIT_BY_HW_MASK        (0x1000000U)
#define USB_GUCTL1_DEV_L1_EXIT_BY_HW_SHIFT       (24U)
#define USB_GUCTL1_DEV_L1_EXIT_BY_HW(x)          (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_DEV_L1_EXIT_BY_HW_SHIFT)) & USB_GUCTL1_DEV_L1_EXIT_BY_HW_MASK)

#define USB_GUCTL1_P3_IN_U2_MASK                 (0x2000000U)
#define USB_GUCTL1_P3_IN_U2_SHIFT                (25U)
#define USB_GUCTL1_P3_IN_U2(x)                   (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_P3_IN_U2_SHIFT)) & USB_GUCTL1_P3_IN_U2_MASK)

#define USB_GUCTL1_DEV_FORCE_20_CLK_FOR_30_CLK_MASK (0x4000000U)
#define USB_GUCTL1_DEV_FORCE_20_CLK_FOR_30_CLK_SHIFT (26U)
#define USB_GUCTL1_DEV_FORCE_20_CLK_FOR_30_CLK(x) (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_DEV_FORCE_20_CLK_FOR_30_CLK_SHIFT)) & USB_GUCTL1_DEV_FORCE_20_CLK_FOR_30_CLK_MASK)

#define USB_GUCTL1_DEV_TRB_OUT_SPR_IND_MASK      (0x8000000U)
#define USB_GUCTL1_DEV_TRB_OUT_SPR_IND_SHIFT     (27U)
#define USB_GUCTL1_DEV_TRB_OUT_SPR_IND(x)        (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_DEV_TRB_OUT_SPR_IND_SHIFT)) & USB_GUCTL1_DEV_TRB_OUT_SPR_IND_MASK)

#define USB_GUCTL1_TX_IPGAP_LINECHECK_DIS_MASK   (0x10000000U)
#define USB_GUCTL1_TX_IPGAP_LINECHECK_DIS_SHIFT  (28U)
#define USB_GUCTL1_TX_IPGAP_LINECHECK_DIS(x)     (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_TX_IPGAP_LINECHECK_DIS_SHIFT)) & USB_GUCTL1_TX_IPGAP_LINECHECK_DIS_MASK)

#define USB_GUCTL1_FILTER_SE0_FSLS_EOP_MASK      (0x20000000U)
#define USB_GUCTL1_FILTER_SE0_FSLS_EOP_SHIFT     (29U)
#define USB_GUCTL1_FILTER_SE0_FSLS_EOP(x)        (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_FILTER_SE0_FSLS_EOP_SHIFT)) & USB_GUCTL1_FILTER_SE0_FSLS_EOP_MASK)

#define USB_GUCTL1_DS_RXDET_MAX_TOUT_CTRL_MASK   (0x40000000U)
#define USB_GUCTL1_DS_RXDET_MAX_TOUT_CTRL_SHIFT  (30U)
#define USB_GUCTL1_DS_RXDET_MAX_TOUT_CTRL(x)     (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_DS_RXDET_MAX_TOUT_CTRL_SHIFT)) & USB_GUCTL1_DS_RXDET_MAX_TOUT_CTRL_MASK)

#define USB_GUCTL1_DEV_DECOUPLE_L1L2_EVT_MASK    (0x80000000U)
#define USB_GUCTL1_DEV_DECOUPLE_L1L2_EVT_SHIFT   (31U)
#define USB_GUCTL1_DEV_DECOUPLE_L1L2_EVT(x)      (((uint32_t)(((uint32_t)(x)) << USB_GUCTL1_DEV_DECOUPLE_L1L2_EVT_SHIFT)) & USB_GUCTL1_DEV_DECOUPLE_L1L2_EVT_MASK)
/*! @} */

/*! @name GUID - Global User ID Register */
/*! @{ */

#define USB_GUID_USERID_MASK                     (0xFFFFFFFFU)
#define USB_GUID_USERID_SHIFT                    (0U)
#define USB_GUID_USERID(x)                       (((uint32_t)(((uint32_t)(x)) << USB_GUID_USERID_SHIFT)) & USB_GUID_USERID_MASK)
/*! @} */

/*! @name GUCTL - Global User Control Register */
/*! @{ */

#define USB_GUCTL_DTFT_MASK                      (0x1FFU)
#define USB_GUCTL_DTFT_SHIFT                     (0U)
#define USB_GUCTL_DTFT(x)                        (((uint32_t)(((uint32_t)(x)) << USB_GUCTL_DTFT_SHIFT)) & USB_GUCTL_DTFT_MASK)

#define USB_GUCTL_DTCT_MASK                      (0x600U)
#define USB_GUCTL_DTCT_SHIFT                     (9U)
#define USB_GUCTL_DTCT(x)                        (((uint32_t)(((uint32_t)(x)) << USB_GUCTL_DTCT_SHIFT)) & USB_GUCTL_DTCT_MASK)

#define USB_GUCTL_INSRTEXTRFSBODI_MASK           (0x800U)
#define USB_GUCTL_INSRTEXTRFSBODI_SHIFT          (11U)
#define USB_GUCTL_INSRTEXTRFSBODI(x)             (((uint32_t)(((uint32_t)(x)) << USB_GUCTL_INSRTEXTRFSBODI_SHIFT)) & USB_GUCTL_INSRTEXTRFSBODI_MASK)

#define USB_GUCTL_EXTCAPSUPPTEN_MASK             (0x1000U)
#define USB_GUCTL_EXTCAPSUPPTEN_SHIFT            (12U)
#define USB_GUCTL_EXTCAPSUPPTEN(x)               (((uint32_t)(((uint32_t)(x)) << USB_GUCTL_EXTCAPSUPPTEN_SHIFT)) & USB_GUCTL_EXTCAPSUPPTEN_MASK)

#define USB_GUCTL_ENOVERLAPCHK_MASK              (0x2000U)
#define USB_GUCTL_ENOVERLAPCHK_SHIFT             (13U)
#define USB_GUCTL_ENOVERLAPCHK(x)                (((uint32_t)(((uint32_t)(x)) << USB_GUCTL_ENOVERLAPCHK_SHIFT)) & USB_GUCTL_ENOVERLAPCHK_MASK)

#define USB_GUCTL_USBHSTINAUTORETRYEN_MASK       (0x4000U)
#define USB_GUCTL_USBHSTINAUTORETRYEN_SHIFT      (14U)
#define USB_GUCTL_USBHSTINAUTORETRYEN(x)         (((uint32_t)(((uint32_t)(x)) << USB_GUCTL_USBHSTINAUTORETRYEN_SHIFT)) & USB_GUCTL_USBHSTINAUTORETRYEN_MASK)

#define USB_GUCTL_RESBWHSEPS_MASK                (0x10000U)
#define USB_GUCTL_RESBWHSEPS_SHIFT               (16U)
#define USB_GUCTL_RESBWHSEPS(x)                  (((uint32_t)(((uint32_t)(x)) << USB_GUCTL_RESBWHSEPS_SHIFT)) & USB_GUCTL_RESBWHSEPS_MASK)

#define USB_GUCTL_SPRSCTRLTRANSEN_MASK           (0x20000U)
#define USB_GUCTL_SPRSCTRLTRANSEN_SHIFT          (17U)
#define USB_GUCTL_SPRSCTRLTRANSEN(x)             (((uint32_t)(((uint32_t)(x)) << USB_GUCTL_SPRSCTRLTRANSEN_SHIFT)) & USB_GUCTL_SPRSCTRLTRANSEN_MASK)

#define USB_GUCTL_NOEXTRDL_MASK                  (0x200000U)
#define USB_GUCTL_NOEXTRDL_SHIFT                 (21U)
#define USB_GUCTL_NOEXTRDL(x)                    (((uint32_t)(((uint32_t)(x)) << USB_GUCTL_NOEXTRDL_SHIFT)) & USB_GUCTL_NOEXTRDL_MASK)

#define USB_GUCTL_REFCLKPER_MASK                 (0xFFC00000U)
#define USB_GUCTL_REFCLKPER_SHIFT                (22U)
#define USB_GUCTL_REFCLKPER(x)                   (((uint32_t)(((uint32_t)(x)) << USB_GUCTL_REFCLKPER_SHIFT)) & USB_GUCTL_REFCLKPER_MASK)
/*! @} */

/*! @name GBUSERRADDRLO - Gobal SoC Bus Error Address Register - Low */
/*! @{ */

#define USB_GBUSERRADDRLO_BUSERRADDR_MASK        (0xFFFFFFFFU)
#define USB_GBUSERRADDRLO_BUSERRADDR_SHIFT       (0U)
#define USB_GBUSERRADDRLO_BUSERRADDR(x)          (((uint32_t)(((uint32_t)(x)) << USB_GBUSERRADDRLO_BUSERRADDR_SHIFT)) & USB_GBUSERRADDRLO_BUSERRADDR_MASK)
/*! @} */

/*! @name GBUSERRADDRHI - Gobal SoC Bus Error Address Register - High */
/*! @{ */

#define USB_GBUSERRADDRHI_BUSERRADDR_MASK        (0xFFFFFFFFU)
#define USB_GBUSERRADDRHI_BUSERRADDR_SHIFT       (0U)
#define USB_GBUSERRADDRHI_BUSERRADDR(x)          (((uint32_t)(((uint32_t)(x)) << USB_GBUSERRADDRHI_BUSERRADDR_SHIFT)) & USB_GBUSERRADDRHI_BUSERRADDR_MASK)
/*! @} */

/*! @name GPRTBIMAPLO - Global SS Port to Bus Instance Mapping Register - Low */
/*! @{ */

#define USB_GPRTBIMAPLO_BINUM1_MASK              (0xFU)
#define USB_GPRTBIMAPLO_BINUM1_SHIFT             (0U)
#define USB_GPRTBIMAPLO_BINUM1(x)                (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPLO_BINUM1_SHIFT)) & USB_GPRTBIMAPLO_BINUM1_MASK)

#define USB_GPRTBIMAPLO_BINUM2_MASK              (0xF0U)
#define USB_GPRTBIMAPLO_BINUM2_SHIFT             (4U)
#define USB_GPRTBIMAPLO_BINUM2(x)                (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPLO_BINUM2_SHIFT)) & USB_GPRTBIMAPLO_BINUM2_MASK)

#define USB_GPRTBIMAPLO_BINUM3_MASK              (0xF00U)
#define USB_GPRTBIMAPLO_BINUM3_SHIFT             (8U)
#define USB_GPRTBIMAPLO_BINUM3(x)                (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPLO_BINUM3_SHIFT)) & USB_GPRTBIMAPLO_BINUM3_MASK)

#define USB_GPRTBIMAPLO_BINUM4_MASK              (0xF000U)
#define USB_GPRTBIMAPLO_BINUM4_SHIFT             (12U)
#define USB_GPRTBIMAPLO_BINUM4(x)                (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPLO_BINUM4_SHIFT)) & USB_GPRTBIMAPLO_BINUM4_MASK)

#define USB_GPRTBIMAPLO_BINUM5_MASK              (0xF0000U)
#define USB_GPRTBIMAPLO_BINUM5_SHIFT             (16U)
#define USB_GPRTBIMAPLO_BINUM5(x)                (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPLO_BINUM5_SHIFT)) & USB_GPRTBIMAPLO_BINUM5_MASK)

#define USB_GPRTBIMAPLO_BINUM6_MASK              (0xF00000U)
#define USB_GPRTBIMAPLO_BINUM6_SHIFT             (20U)
#define USB_GPRTBIMAPLO_BINUM6(x)                (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPLO_BINUM6_SHIFT)) & USB_GPRTBIMAPLO_BINUM6_MASK)

#define USB_GPRTBIMAPLO_BINUM7_MASK              (0xF000000U)
#define USB_GPRTBIMAPLO_BINUM7_SHIFT             (24U)
#define USB_GPRTBIMAPLO_BINUM7(x)                (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPLO_BINUM7_SHIFT)) & USB_GPRTBIMAPLO_BINUM7_MASK)

#define USB_GPRTBIMAPLO_BINUM8_MASK              (0xF0000000U)
#define USB_GPRTBIMAPLO_BINUM8_SHIFT             (28U)
#define USB_GPRTBIMAPLO_BINUM8(x)                (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPLO_BINUM8_SHIFT)) & USB_GPRTBIMAPLO_BINUM8_MASK)
/*! @} */

/*! @name GPRTBIMAPHI - Global SS Port to Bus Instance Mapping Register - High */
/*! @{ */

#define USB_GPRTBIMAPHI_BINUM9_MASK              (0xFU)
#define USB_GPRTBIMAPHI_BINUM9_SHIFT             (0U)
#define USB_GPRTBIMAPHI_BINUM9(x)                (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPHI_BINUM9_SHIFT)) & USB_GPRTBIMAPHI_BINUM9_MASK)

#define USB_GPRTBIMAPHI_BINUM10_MASK             (0xF0U)
#define USB_GPRTBIMAPHI_BINUM10_SHIFT            (4U)
#define USB_GPRTBIMAPHI_BINUM10(x)               (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPHI_BINUM10_SHIFT)) & USB_GPRTBIMAPHI_BINUM10_MASK)

#define USB_GPRTBIMAPHI_BINUM11_MASK             (0xF00U)
#define USB_GPRTBIMAPHI_BINUM11_SHIFT            (8U)
#define USB_GPRTBIMAPHI_BINUM11(x)               (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPHI_BINUM11_SHIFT)) & USB_GPRTBIMAPHI_BINUM11_MASK)

#define USB_GPRTBIMAPHI_BINUM12_MASK             (0xF000U)
#define USB_GPRTBIMAPHI_BINUM12_SHIFT            (12U)
#define USB_GPRTBIMAPHI_BINUM12(x)               (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPHI_BINUM12_SHIFT)) & USB_GPRTBIMAPHI_BINUM12_MASK)

#define USB_GPRTBIMAPHI_BINUM13_MASK             (0xF0000U)
#define USB_GPRTBIMAPHI_BINUM13_SHIFT            (16U)
#define USB_GPRTBIMAPHI_BINUM13(x)               (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPHI_BINUM13_SHIFT)) & USB_GPRTBIMAPHI_BINUM13_MASK)

#define USB_GPRTBIMAPHI_BINUM14_MASK             (0xF00000U)
#define USB_GPRTBIMAPHI_BINUM14_SHIFT            (20U)
#define USB_GPRTBIMAPHI_BINUM14(x)               (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPHI_BINUM14_SHIFT)) & USB_GPRTBIMAPHI_BINUM14_MASK)

#define USB_GPRTBIMAPHI_BINUM15_MASK             (0xF000000U)
#define USB_GPRTBIMAPHI_BINUM15_SHIFT            (24U)
#define USB_GPRTBIMAPHI_BINUM15(x)               (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAPHI_BINUM15_SHIFT)) & USB_GPRTBIMAPHI_BINUM15_MASK)
/*! @} */

/*! @name GHWPARAMS0 - Global Hardware Parameters Register 0 */
/*! @{ */

#define USB_GHWPARAMS0_GHWPARAMS0_2_0_MASK       (0x7U)
#define USB_GHWPARAMS0_GHWPARAMS0_2_0_SHIFT      (0U)
#define USB_GHWPARAMS0_GHWPARAMS0_2_0(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS0_GHWPARAMS0_2_0_SHIFT)) & USB_GHWPARAMS0_GHWPARAMS0_2_0_MASK)

#define USB_GHWPARAMS0_GHWPARAMS0_5_3_MASK       (0x38U)
#define USB_GHWPARAMS0_GHWPARAMS0_5_3_SHIFT      (3U)
#define USB_GHWPARAMS0_GHWPARAMS0_5_3(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS0_GHWPARAMS0_5_3_SHIFT)) & USB_GHWPARAMS0_GHWPARAMS0_5_3_MASK)

#define USB_GHWPARAMS0_GHWPARAMS0_7_6_MASK       (0xC0U)
#define USB_GHWPARAMS0_GHWPARAMS0_7_6_SHIFT      (6U)
#define USB_GHWPARAMS0_GHWPARAMS0_7_6(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS0_GHWPARAMS0_7_6_SHIFT)) & USB_GHWPARAMS0_GHWPARAMS0_7_6_MASK)

#define USB_GHWPARAMS0_GHWPARAMS0_15_8_MASK      (0xFF00U)
#define USB_GHWPARAMS0_GHWPARAMS0_15_8_SHIFT     (8U)
#define USB_GHWPARAMS0_GHWPARAMS0_15_8(x)        (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS0_GHWPARAMS0_15_8_SHIFT)) & USB_GHWPARAMS0_GHWPARAMS0_15_8_MASK)

#define USB_GHWPARAMS0_GHWPARAMS0_23_16_MASK     (0xFF0000U)
#define USB_GHWPARAMS0_GHWPARAMS0_23_16_SHIFT    (16U)
#define USB_GHWPARAMS0_GHWPARAMS0_23_16(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS0_GHWPARAMS0_23_16_SHIFT)) & USB_GHWPARAMS0_GHWPARAMS0_23_16_MASK)

#define USB_GHWPARAMS0_GHWPARAMS0_31_24_MASK     (0xFF000000U)
#define USB_GHWPARAMS0_GHWPARAMS0_31_24_SHIFT    (24U)
#define USB_GHWPARAMS0_GHWPARAMS0_31_24(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS0_GHWPARAMS0_31_24_SHIFT)) & USB_GHWPARAMS0_GHWPARAMS0_31_24_MASK)
/*! @} */

/*! @name GHWPARAMS1 - Global Hardware Parameters Register 1 */
/*! @{ */

#define USB_GHWPARAMS1_GHWPARAMS1_2_0_MASK       (0x7U)
#define USB_GHWPARAMS1_GHWPARAMS1_2_0_SHIFT      (0U)
#define USB_GHWPARAMS1_GHWPARAMS1_2_0(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS1_GHWPARAMS1_2_0_SHIFT)) & USB_GHWPARAMS1_GHWPARAMS1_2_0_MASK)

#define USB_GHWPARAMS1_GHWPARAMS1_5_3_MASK       (0x38U)
#define USB_GHWPARAMS1_GHWPARAMS1_5_3_SHIFT      (3U)
#define USB_GHWPARAMS1_GHWPARAMS1_5_3(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS1_GHWPARAMS1_5_3_SHIFT)) & USB_GHWPARAMS1_GHWPARAMS1_5_3_MASK)

#define USB_GHWPARAMS1_GHWPARAMS1_8_6_MASK       (0x1C0U)
#define USB_GHWPARAMS1_GHWPARAMS1_8_6_SHIFT      (6U)
#define USB_GHWPARAMS1_GHWPARAMS1_8_6(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS1_GHWPARAMS1_8_6_SHIFT)) & USB_GHWPARAMS1_GHWPARAMS1_8_6_MASK)

#define USB_GHWPARAMS1_GHWPARAMS1_11_9_MASK      (0xE00U)
#define USB_GHWPARAMS1_GHWPARAMS1_11_9_SHIFT     (9U)
#define USB_GHWPARAMS1_GHWPARAMS1_11_9(x)        (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS1_GHWPARAMS1_11_9_SHIFT)) & USB_GHWPARAMS1_GHWPARAMS1_11_9_MASK)

#define USB_GHWPARAMS1_GHWPARAMS1_14_12_MASK     (0x7000U)
#define USB_GHWPARAMS1_GHWPARAMS1_14_12_SHIFT    (12U)
#define USB_GHWPARAMS1_GHWPARAMS1_14_12(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS1_GHWPARAMS1_14_12_SHIFT)) & USB_GHWPARAMS1_GHWPARAMS1_14_12_MASK)

#define USB_GHWPARAMS1_GHWPARAMS1_20_15_MASK     (0x1F8000U)
#define USB_GHWPARAMS1_GHWPARAMS1_20_15_SHIFT    (15U)
#define USB_GHWPARAMS1_GHWPARAMS1_20_15(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS1_GHWPARAMS1_20_15_SHIFT)) & USB_GHWPARAMS1_GHWPARAMS1_20_15_MASK)

#define USB_GHWPARAMS1_GHWPARAMS1_22_21_MASK     (0x600000U)
#define USB_GHWPARAMS1_GHWPARAMS1_22_21_SHIFT    (21U)
#define USB_GHWPARAMS1_GHWPARAMS1_22_21(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS1_GHWPARAMS1_22_21_SHIFT)) & USB_GHWPARAMS1_GHWPARAMS1_22_21_MASK)

#define USB_GHWPARAMS1_GHWPARAMS1_23_MASK        (0x800000U)
#define USB_GHWPARAMS1_GHWPARAMS1_23_SHIFT       (23U)
#define USB_GHWPARAMS1_GHWPARAMS1_23(x)          (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS1_GHWPARAMS1_23_SHIFT)) & USB_GHWPARAMS1_GHWPARAMS1_23_MASK)

#define USB_GHWPARAMS1_GHWPARAMS1_25_24_MASK     (0x3000000U)
#define USB_GHWPARAMS1_GHWPARAMS1_25_24_SHIFT    (24U)
#define USB_GHWPARAMS1_GHWPARAMS1_25_24(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS1_GHWPARAMS1_25_24_SHIFT)) & USB_GHWPARAMS1_GHWPARAMS1_25_24_MASK)

#define USB_GHWPARAMS1_GHWPARAMS1_26_MASK        (0x4000000U)
#define USB_GHWPARAMS1_GHWPARAMS1_26_SHIFT       (26U)
#define USB_GHWPARAMS1_GHWPARAMS1_26(x)          (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS1_GHWPARAMS1_26_SHIFT)) & USB_GHWPARAMS1_GHWPARAMS1_26_MASK)

#define USB_GHWPARAMS1_GHWPARAMS1_27_MASK        (0x8000000U)
#define USB_GHWPARAMS1_GHWPARAMS1_27_SHIFT       (27U)
#define USB_GHWPARAMS1_GHWPARAMS1_27(x)          (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS1_GHWPARAMS1_27_SHIFT)) & USB_GHWPARAMS1_GHWPARAMS1_27_MASK)

#define USB_GHWPARAMS1_GHWPARAMS1_28_MASK        (0x10000000U)
#define USB_GHWPARAMS1_GHWPARAMS1_28_SHIFT       (28U)
#define USB_GHWPARAMS1_GHWPARAMS1_28(x)          (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS1_GHWPARAMS1_28_SHIFT)) & USB_GHWPARAMS1_GHWPARAMS1_28_MASK)

#define USB_GHWPARAMS1_GHWPARAMS1_30_MASK        (0x40000000U)
#define USB_GHWPARAMS1_GHWPARAMS1_30_SHIFT       (30U)
#define USB_GHWPARAMS1_GHWPARAMS1_30(x)          (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS1_GHWPARAMS1_30_SHIFT)) & USB_GHWPARAMS1_GHWPARAMS1_30_MASK)

#define USB_GHWPARAMS1_GHWPARAMS1_31_MASK        (0x80000000U)
#define USB_GHWPARAMS1_GHWPARAMS1_31_SHIFT       (31U)
#define USB_GHWPARAMS1_GHWPARAMS1_31(x)          (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS1_GHWPARAMS1_31_SHIFT)) & USB_GHWPARAMS1_GHWPARAMS1_31_MASK)
/*! @} */

/*! @name GHWPARAMS2 - Global Hardware Parameters Register 2 */
/*! @{ */

#define USB_GHWPARAMS2_GHWPARAMS2_31_0_MASK      (0xFFFFFFFFU)
#define USB_GHWPARAMS2_GHWPARAMS2_31_0_SHIFT     (0U)
#define USB_GHWPARAMS2_GHWPARAMS2_31_0(x)        (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS2_GHWPARAMS2_31_0_SHIFT)) & USB_GHWPARAMS2_GHWPARAMS2_31_0_MASK)
/*! @} */

/*! @name GHWPARAMS3 - Global Hardware Parameters Register 3 */
/*! @{ */

#define USB_GHWPARAMS3_GHWPARAMS3_1_0_MASK       (0x3U)
#define USB_GHWPARAMS3_GHWPARAMS3_1_0_SHIFT      (0U)
#define USB_GHWPARAMS3_GHWPARAMS3_1_0(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS3_GHWPARAMS3_1_0_SHIFT)) & USB_GHWPARAMS3_GHWPARAMS3_1_0_MASK)

#define USB_GHWPARAMS3_GHWPARAMS3_3_2_MASK       (0xCU)
#define USB_GHWPARAMS3_GHWPARAMS3_3_2_SHIFT      (2U)
#define USB_GHWPARAMS3_GHWPARAMS3_3_2(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS3_GHWPARAMS3_3_2_SHIFT)) & USB_GHWPARAMS3_GHWPARAMS3_3_2_MASK)

#define USB_GHWPARAMS3_GHWPARAMS3_5_4_MASK       (0x30U)
#define USB_GHWPARAMS3_GHWPARAMS3_5_4_SHIFT      (4U)
#define USB_GHWPARAMS3_GHWPARAMS3_5_4(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS3_GHWPARAMS3_5_4_SHIFT)) & USB_GHWPARAMS3_GHWPARAMS3_5_4_MASK)

#define USB_GHWPARAMS3_GHWPARAMS3_7_6_MASK       (0xC0U)
#define USB_GHWPARAMS3_GHWPARAMS3_7_6_SHIFT      (6U)
#define USB_GHWPARAMS3_GHWPARAMS3_7_6(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS3_GHWPARAMS3_7_6_SHIFT)) & USB_GHWPARAMS3_GHWPARAMS3_7_6_MASK)

#define USB_GHWPARAMS3_GHWPARAMS3_10_MASK        (0x400U)
#define USB_GHWPARAMS3_GHWPARAMS3_10_SHIFT       (10U)
#define USB_GHWPARAMS3_GHWPARAMS3_10(x)          (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS3_GHWPARAMS3_10_SHIFT)) & USB_GHWPARAMS3_GHWPARAMS3_10_MASK)

#define USB_GHWPARAMS3_GHWPARAMS3_11_MASK        (0x800U)
#define USB_GHWPARAMS3_GHWPARAMS3_11_SHIFT       (11U)
#define USB_GHWPARAMS3_GHWPARAMS3_11(x)          (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS3_GHWPARAMS3_11_SHIFT)) & USB_GHWPARAMS3_GHWPARAMS3_11_MASK)

#define USB_GHWPARAMS3_GHWPARAMS3_17_12_MASK     (0x3F000U)
#define USB_GHWPARAMS3_GHWPARAMS3_17_12_SHIFT    (12U)
#define USB_GHWPARAMS3_GHWPARAMS3_17_12(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS3_GHWPARAMS3_17_12_SHIFT)) & USB_GHWPARAMS3_GHWPARAMS3_17_12_MASK)

#define USB_GHWPARAMS3_GHWPARAMS3_22_18_MASK     (0x7C0000U)
#define USB_GHWPARAMS3_GHWPARAMS3_22_18_SHIFT    (18U)
#define USB_GHWPARAMS3_GHWPARAMS3_22_18(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS3_GHWPARAMS3_22_18_SHIFT)) & USB_GHWPARAMS3_GHWPARAMS3_22_18_MASK)

#define USB_GHWPARAMS3_GHWPARAMS3_30_23_MASK     (0x7F800000U)
#define USB_GHWPARAMS3_GHWPARAMS3_30_23_SHIFT    (23U)
#define USB_GHWPARAMS3_GHWPARAMS3_30_23(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS3_GHWPARAMS3_30_23_SHIFT)) & USB_GHWPARAMS3_GHWPARAMS3_30_23_MASK)
/*! @} */

/*! @name GHWPARAMS4 - Global Hardware Parameters Register 4 */
/*! @{ */

#define USB_GHWPARAMS4_GHWPARAMS4_5_0_MASK       (0x3FU)
#define USB_GHWPARAMS4_GHWPARAMS4_5_0_SHIFT      (0U)
#define USB_GHWPARAMS4_GHWPARAMS4_5_0(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS4_GHWPARAMS4_5_0_SHIFT)) & USB_GHWPARAMS4_GHWPARAMS4_5_0_MASK)

#define USB_GHWPARAMS4_GHWPARAMS4_8_7_MASK       (0x180U)
#define USB_GHWPARAMS4_GHWPARAMS4_8_7_SHIFT      (7U)
#define USB_GHWPARAMS4_GHWPARAMS4_8_7(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS4_GHWPARAMS4_8_7_SHIFT)) & USB_GHWPARAMS4_GHWPARAMS4_8_7_MASK)

#define USB_GHWPARAMS4_GHWPARAMS4_10_9_MASK      (0x600U)
#define USB_GHWPARAMS4_GHWPARAMS4_10_9_SHIFT     (9U)
#define USB_GHWPARAMS4_GHWPARAMS4_10_9(x)        (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS4_GHWPARAMS4_10_9_SHIFT)) & USB_GHWPARAMS4_GHWPARAMS4_10_9_MASK)

#define USB_GHWPARAMS4_GHWPARAMS4_11_MASK        (0x800U)
#define USB_GHWPARAMS4_GHWPARAMS4_11_SHIFT       (11U)
#define USB_GHWPARAMS4_GHWPARAMS4_11(x)          (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS4_GHWPARAMS4_11_SHIFT)) & USB_GHWPARAMS4_GHWPARAMS4_11_MASK)

#define USB_GHWPARAMS4_GHWPARAMS4_12_MASK        (0x1000U)
#define USB_GHWPARAMS4_GHWPARAMS4_12_SHIFT       (12U)
#define USB_GHWPARAMS4_GHWPARAMS4_12(x)          (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS4_GHWPARAMS4_12_SHIFT)) & USB_GHWPARAMS4_GHWPARAMS4_12_MASK)

#define USB_GHWPARAMS4_GHWPARAMS4_16_13_MASK     (0x1E000U)
#define USB_GHWPARAMS4_GHWPARAMS4_16_13_SHIFT    (13U)
#define USB_GHWPARAMS4_GHWPARAMS4_16_13(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS4_GHWPARAMS4_16_13_SHIFT)) & USB_GHWPARAMS4_GHWPARAMS4_16_13_MASK)

#define USB_GHWPARAMS4_GHWPARAMS4_20_17_MASK     (0x1E0000U)
#define USB_GHWPARAMS4_GHWPARAMS4_20_17_SHIFT    (17U)
#define USB_GHWPARAMS4_GHWPARAMS4_20_17(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS4_GHWPARAMS4_20_17_SHIFT)) & USB_GHWPARAMS4_GHWPARAMS4_20_17_MASK)

#define USB_GHWPARAMS4_GHWPARAMS4_21_MASK        (0x200000U)
#define USB_GHWPARAMS4_GHWPARAMS4_21_SHIFT       (21U)
#define USB_GHWPARAMS4_GHWPARAMS4_21(x)          (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS4_GHWPARAMS4_21_SHIFT)) & USB_GHWPARAMS4_GHWPARAMS4_21_MASK)

#define USB_GHWPARAMS4_GHWPARAMS4_23_MASK        (0x800000U)
#define USB_GHWPARAMS4_GHWPARAMS4_23_SHIFT       (23U)
#define USB_GHWPARAMS4_GHWPARAMS4_23(x)          (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS4_GHWPARAMS4_23_SHIFT)) & USB_GHWPARAMS4_GHWPARAMS4_23_MASK)

#define USB_GHWPARAMS4_GHWPARAMS4_27_24_MASK     (0xF000000U)
#define USB_GHWPARAMS4_GHWPARAMS4_27_24_SHIFT    (24U)
#define USB_GHWPARAMS4_GHWPARAMS4_27_24(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS4_GHWPARAMS4_27_24_SHIFT)) & USB_GHWPARAMS4_GHWPARAMS4_27_24_MASK)

#define USB_GHWPARAMS4_GHWPARAMS4_31_28_MASK     (0xF0000000U)
#define USB_GHWPARAMS4_GHWPARAMS4_31_28_SHIFT    (28U)
#define USB_GHWPARAMS4_GHWPARAMS4_31_28(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS4_GHWPARAMS4_31_28_SHIFT)) & USB_GHWPARAMS4_GHWPARAMS4_31_28_MASK)
/*! @} */

/*! @name GHWPARAMS5 - Global Hardware Parameters Register 5 */
/*! @{ */

#define USB_GHWPARAMS5_GHWPARAMS5_3_0_MASK       (0xFU)
#define USB_GHWPARAMS5_GHWPARAMS5_3_0_SHIFT      (0U)
#define USB_GHWPARAMS5_GHWPARAMS5_3_0(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS5_GHWPARAMS5_3_0_SHIFT)) & USB_GHWPARAMS5_GHWPARAMS5_3_0_MASK)

#define USB_GHWPARAMS5_GHWPARAMS5_9_4_MASK       (0x3F0U)
#define USB_GHWPARAMS5_GHWPARAMS5_9_4_SHIFT      (4U)
#define USB_GHWPARAMS5_GHWPARAMS5_9_4(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS5_GHWPARAMS5_9_4_SHIFT)) & USB_GHWPARAMS5_GHWPARAMS5_9_4_MASK)

#define USB_GHWPARAMS5_GHWPARAMS5_15_10_MASK     (0xFC00U)
#define USB_GHWPARAMS5_GHWPARAMS5_15_10_SHIFT    (10U)
#define USB_GHWPARAMS5_GHWPARAMS5_15_10(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS5_GHWPARAMS5_15_10_SHIFT)) & USB_GHWPARAMS5_GHWPARAMS5_15_10_MASK)

#define USB_GHWPARAMS5_GHWPARAMS5_21_16_MASK     (0x3F0000U)
#define USB_GHWPARAMS5_GHWPARAMS5_21_16_SHIFT    (16U)
#define USB_GHWPARAMS5_GHWPARAMS5_21_16(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS5_GHWPARAMS5_21_16_SHIFT)) & USB_GHWPARAMS5_GHWPARAMS5_21_16_MASK)

#define USB_GHWPARAMS5_GHWPARAMS5_27_22_MASK     (0xFC00000U)
#define USB_GHWPARAMS5_GHWPARAMS5_27_22_SHIFT    (22U)
#define USB_GHWPARAMS5_GHWPARAMS5_27_22(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS5_GHWPARAMS5_27_22_SHIFT)) & USB_GHWPARAMS5_GHWPARAMS5_27_22_MASK)
/*! @} */

/*! @name GHWPARAMS6 - Global Hardware Parameters Register 6 */
/*! @{ */

#define USB_GHWPARAMS6_GHWPARAMS6_5_0_MASK       (0x3FU)
#define USB_GHWPARAMS6_GHWPARAMS6_5_0_SHIFT      (0U)
#define USB_GHWPARAMS6_GHWPARAMS6_5_0(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS6_GHWPARAMS6_5_0_SHIFT)) & USB_GHWPARAMS6_GHWPARAMS6_5_0_MASK)

#define USB_GHWPARAMS6_GHWPARAMS6_6_MASK         (0x40U)
#define USB_GHWPARAMS6_GHWPARAMS6_6_SHIFT        (6U)
#define USB_GHWPARAMS6_GHWPARAMS6_6(x)           (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS6_GHWPARAMS6_6_SHIFT)) & USB_GHWPARAMS6_GHWPARAMS6_6_MASK)

#define USB_GHWPARAMS6_GHWPARAMS6_7_MASK         (0x80U)
#define USB_GHWPARAMS6_GHWPARAMS6_7_SHIFT        (7U)
#define USB_GHWPARAMS6_GHWPARAMS6_7(x)           (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS6_GHWPARAMS6_7_SHIFT)) & USB_GHWPARAMS6_GHWPARAMS6_7_MASK)

#define USB_GHWPARAMS6_GHWPARAMS6_9_8_MASK       (0x300U)
#define USB_GHWPARAMS6_GHWPARAMS6_9_8_SHIFT      (8U)
#define USB_GHWPARAMS6_GHWPARAMS6_9_8(x)         (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS6_GHWPARAMS6_9_8_SHIFT)) & USB_GHWPARAMS6_GHWPARAMS6_9_8_MASK)

#define USB_GHWPARAMS6_BCSUPPORT_MASK            (0x4000U)
#define USB_GHWPARAMS6_BCSUPPORT_SHIFT           (14U)
#define USB_GHWPARAMS6_BCSUPPORT(x)              (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS6_BCSUPPORT_SHIFT)) & USB_GHWPARAMS6_BCSUPPORT_MASK)

#define USB_GHWPARAMS6_BUSFLTRSSUPPORT_MASK      (0x8000U)
#define USB_GHWPARAMS6_BUSFLTRSSUPPORT_SHIFT     (15U)
#define USB_GHWPARAMS6_BUSFLTRSSUPPORT(x)        (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS6_BUSFLTRSSUPPORT_SHIFT)) & USB_GHWPARAMS6_BUSFLTRSSUPPORT_MASK)

#define USB_GHWPARAMS6_GHWPARAMS6_31_16_MASK     (0xFFFF0000U)
#define USB_GHWPARAMS6_GHWPARAMS6_31_16_SHIFT    (16U)
#define USB_GHWPARAMS6_GHWPARAMS6_31_16(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS6_GHWPARAMS6_31_16_SHIFT)) & USB_GHWPARAMS6_GHWPARAMS6_31_16_MASK)
/*! @} */

/*! @name GHWPARAMS7 - Global Hardware Parameters Register 7 */
/*! @{ */

#define USB_GHWPARAMS7_GHWPARAMS7_15_0_MASK      (0xFFFFU)
#define USB_GHWPARAMS7_GHWPARAMS7_15_0_SHIFT     (0U)
#define USB_GHWPARAMS7_GHWPARAMS7_15_0(x)        (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS7_GHWPARAMS7_15_0_SHIFT)) & USB_GHWPARAMS7_GHWPARAMS7_15_0_MASK)

#define USB_GHWPARAMS7_GHWPARAMS7_31_16_MASK     (0xFFFF0000U)
#define USB_GHWPARAMS7_GHWPARAMS7_31_16_SHIFT    (16U)
#define USB_GHWPARAMS7_GHWPARAMS7_31_16(x)       (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS7_GHWPARAMS7_31_16_SHIFT)) & USB_GHWPARAMS7_GHWPARAMS7_31_16_MASK)
/*! @} */

/*! @name GPRTBIMAP_HSLO - Global High-Speed Port to Bus Instance Mapping Register - Low */
/*! @{ */

#define USB_GPRTBIMAP_HSLO_BINUM1_MASK           (0xFU)
#define USB_GPRTBIMAP_HSLO_BINUM1_SHIFT          (0U)
#define USB_GPRTBIMAP_HSLO_BINUM1(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSLO_BINUM1_SHIFT)) & USB_GPRTBIMAP_HSLO_BINUM1_MASK)

#define USB_GPRTBIMAP_HSLO_BINUM2_MASK           (0xF0U)
#define USB_GPRTBIMAP_HSLO_BINUM2_SHIFT          (4U)
#define USB_GPRTBIMAP_HSLO_BINUM2(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSLO_BINUM2_SHIFT)) & USB_GPRTBIMAP_HSLO_BINUM2_MASK)

#define USB_GPRTBIMAP_HSLO_BINUM3_MASK           (0xF00U)
#define USB_GPRTBIMAP_HSLO_BINUM3_SHIFT          (8U)
#define USB_GPRTBIMAP_HSLO_BINUM3(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSLO_BINUM3_SHIFT)) & USB_GPRTBIMAP_HSLO_BINUM3_MASK)

#define USB_GPRTBIMAP_HSLO_BINUM4_MASK           (0xF000U)
#define USB_GPRTBIMAP_HSLO_BINUM4_SHIFT          (12U)
#define USB_GPRTBIMAP_HSLO_BINUM4(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSLO_BINUM4_SHIFT)) & USB_GPRTBIMAP_HSLO_BINUM4_MASK)

#define USB_GPRTBIMAP_HSLO_BINUM5_MASK           (0xF0000U)
#define USB_GPRTBIMAP_HSLO_BINUM5_SHIFT          (16U)
#define USB_GPRTBIMAP_HSLO_BINUM5(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSLO_BINUM5_SHIFT)) & USB_GPRTBIMAP_HSLO_BINUM5_MASK)

#define USB_GPRTBIMAP_HSLO_BINUM6_MASK           (0xF00000U)
#define USB_GPRTBIMAP_HSLO_BINUM6_SHIFT          (20U)
#define USB_GPRTBIMAP_HSLO_BINUM6(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSLO_BINUM6_SHIFT)) & USB_GPRTBIMAP_HSLO_BINUM6_MASK)

#define USB_GPRTBIMAP_HSLO_BINUM7_MASK           (0xF000000U)
#define USB_GPRTBIMAP_HSLO_BINUM7_SHIFT          (24U)
#define USB_GPRTBIMAP_HSLO_BINUM7(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSLO_BINUM7_SHIFT)) & USB_GPRTBIMAP_HSLO_BINUM7_MASK)

#define USB_GPRTBIMAP_HSLO_BINUM8_MASK           (0xF0000000U)
#define USB_GPRTBIMAP_HSLO_BINUM8_SHIFT          (28U)
#define USB_GPRTBIMAP_HSLO_BINUM8(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSLO_BINUM8_SHIFT)) & USB_GPRTBIMAP_HSLO_BINUM8_MASK)
/*! @} */

/*! @name GPRTBIMAP_HSHI - Global High-Speed Port to Bus Instance Mapping Register - High */
/*! @{ */

#define USB_GPRTBIMAP_HSHI_BINUM9_MASK           (0xFU)
#define USB_GPRTBIMAP_HSHI_BINUM9_SHIFT          (0U)
#define USB_GPRTBIMAP_HSHI_BINUM9(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSHI_BINUM9_SHIFT)) & USB_GPRTBIMAP_HSHI_BINUM9_MASK)

#define USB_GPRTBIMAP_HSHI_BINUM10_MASK          (0xF0U)
#define USB_GPRTBIMAP_HSHI_BINUM10_SHIFT         (4U)
#define USB_GPRTBIMAP_HSHI_BINUM10(x)            (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSHI_BINUM10_SHIFT)) & USB_GPRTBIMAP_HSHI_BINUM10_MASK)

#define USB_GPRTBIMAP_HSHI_BINUM11_MASK          (0xF00U)
#define USB_GPRTBIMAP_HSHI_BINUM11_SHIFT         (8U)
#define USB_GPRTBIMAP_HSHI_BINUM11(x)            (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSHI_BINUM11_SHIFT)) & USB_GPRTBIMAP_HSHI_BINUM11_MASK)

#define USB_GPRTBIMAP_HSHI_BINUM12_MASK          (0xF000U)
#define USB_GPRTBIMAP_HSHI_BINUM12_SHIFT         (12U)
#define USB_GPRTBIMAP_HSHI_BINUM12(x)            (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSHI_BINUM12_SHIFT)) & USB_GPRTBIMAP_HSHI_BINUM12_MASK)

#define USB_GPRTBIMAP_HSHI_BINUM13_MASK          (0xF0000U)
#define USB_GPRTBIMAP_HSHI_BINUM13_SHIFT         (16U)
#define USB_GPRTBIMAP_HSHI_BINUM13(x)            (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSHI_BINUM13_SHIFT)) & USB_GPRTBIMAP_HSHI_BINUM13_MASK)

#define USB_GPRTBIMAP_HSHI_BINUM14_MASK          (0xF00000U)
#define USB_GPRTBIMAP_HSHI_BINUM14_SHIFT         (20U)
#define USB_GPRTBIMAP_HSHI_BINUM14(x)            (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSHI_BINUM14_SHIFT)) & USB_GPRTBIMAP_HSHI_BINUM14_MASK)

#define USB_GPRTBIMAP_HSHI_BINUM15_MASK          (0xF000000U)
#define USB_GPRTBIMAP_HSHI_BINUM15_SHIFT         (24U)
#define USB_GPRTBIMAP_HSHI_BINUM15(x)            (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_HSHI_BINUM15_SHIFT)) & USB_GPRTBIMAP_HSHI_BINUM15_MASK)
/*! @} */

/*! @name GPRTBIMAP_FSLO - Global Full-Speed Port to Bus Instance Mapping Register - Low */
/*! @{ */

#define USB_GPRTBIMAP_FSLO_BINUM1_MASK           (0xFU)
#define USB_GPRTBIMAP_FSLO_BINUM1_SHIFT          (0U)
#define USB_GPRTBIMAP_FSLO_BINUM1(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSLO_BINUM1_SHIFT)) & USB_GPRTBIMAP_FSLO_BINUM1_MASK)

#define USB_GPRTBIMAP_FSLO_BINUM2_MASK           (0xF0U)
#define USB_GPRTBIMAP_FSLO_BINUM2_SHIFT          (4U)
#define USB_GPRTBIMAP_FSLO_BINUM2(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSLO_BINUM2_SHIFT)) & USB_GPRTBIMAP_FSLO_BINUM2_MASK)

#define USB_GPRTBIMAP_FSLO_BINUM3_MASK           (0xF00U)
#define USB_GPRTBIMAP_FSLO_BINUM3_SHIFT          (8U)
#define USB_GPRTBIMAP_FSLO_BINUM3(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSLO_BINUM3_SHIFT)) & USB_GPRTBIMAP_FSLO_BINUM3_MASK)

#define USB_GPRTBIMAP_FSLO_BINUM4_MASK           (0xF000U)
#define USB_GPRTBIMAP_FSLO_BINUM4_SHIFT          (12U)
#define USB_GPRTBIMAP_FSLO_BINUM4(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSLO_BINUM4_SHIFT)) & USB_GPRTBIMAP_FSLO_BINUM4_MASK)

#define USB_GPRTBIMAP_FSLO_BINUM5_MASK           (0xF0000U)
#define USB_GPRTBIMAP_FSLO_BINUM5_SHIFT          (16U)
#define USB_GPRTBIMAP_FSLO_BINUM5(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSLO_BINUM5_SHIFT)) & USB_GPRTBIMAP_FSLO_BINUM5_MASK)

#define USB_GPRTBIMAP_FSLO_BINUM6_MASK           (0xF00000U)
#define USB_GPRTBIMAP_FSLO_BINUM6_SHIFT          (20U)
#define USB_GPRTBIMAP_FSLO_BINUM6(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSLO_BINUM6_SHIFT)) & USB_GPRTBIMAP_FSLO_BINUM6_MASK)

#define USB_GPRTBIMAP_FSLO_BINUM7_MASK           (0xF000000U)
#define USB_GPRTBIMAP_FSLO_BINUM7_SHIFT          (24U)
#define USB_GPRTBIMAP_FSLO_BINUM7(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSLO_BINUM7_SHIFT)) & USB_GPRTBIMAP_FSLO_BINUM7_MASK)

#define USB_GPRTBIMAP_FSLO_BINUM8_MASK           (0xF0000000U)
#define USB_GPRTBIMAP_FSLO_BINUM8_SHIFT          (28U)
#define USB_GPRTBIMAP_FSLO_BINUM8(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSLO_BINUM8_SHIFT)) & USB_GPRTBIMAP_FSLO_BINUM8_MASK)
/*! @} */

/*! @name GPRTBIMAP_FSHI - Global Full-Speed Port to Bus Instance Mapping Register - High */
/*! @{ */

#define USB_GPRTBIMAP_FSHI_BINUM9_MASK           (0xFU)
#define USB_GPRTBIMAP_FSHI_BINUM9_SHIFT          (0U)
#define USB_GPRTBIMAP_FSHI_BINUM9(x)             (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSHI_BINUM9_SHIFT)) & USB_GPRTBIMAP_FSHI_BINUM9_MASK)

#define USB_GPRTBIMAP_FSHI_BINUM10_MASK          (0xF0U)
#define USB_GPRTBIMAP_FSHI_BINUM10_SHIFT         (4U)
#define USB_GPRTBIMAP_FSHI_BINUM10(x)            (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSHI_BINUM10_SHIFT)) & USB_GPRTBIMAP_FSHI_BINUM10_MASK)

#define USB_GPRTBIMAP_FSHI_BINUM11_MASK          (0xF00U)
#define USB_GPRTBIMAP_FSHI_BINUM11_SHIFT         (8U)
#define USB_GPRTBIMAP_FSHI_BINUM11(x)            (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSHI_BINUM11_SHIFT)) & USB_GPRTBIMAP_FSHI_BINUM11_MASK)

#define USB_GPRTBIMAP_FSHI_BINUM12_MASK          (0xF000U)
#define USB_GPRTBIMAP_FSHI_BINUM12_SHIFT         (12U)
#define USB_GPRTBIMAP_FSHI_BINUM12(x)            (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSHI_BINUM12_SHIFT)) & USB_GPRTBIMAP_FSHI_BINUM12_MASK)

#define USB_GPRTBIMAP_FSHI_BINUM13_MASK          (0xF0000U)
#define USB_GPRTBIMAP_FSHI_BINUM13_SHIFT         (16U)
#define USB_GPRTBIMAP_FSHI_BINUM13(x)            (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSHI_BINUM13_SHIFT)) & USB_GPRTBIMAP_FSHI_BINUM13_MASK)

#define USB_GPRTBIMAP_FSHI_BINUM14_MASK          (0xF00000U)
#define USB_GPRTBIMAP_FSHI_BINUM14_SHIFT         (20U)
#define USB_GPRTBIMAP_FSHI_BINUM14(x)            (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSHI_BINUM14_SHIFT)) & USB_GPRTBIMAP_FSHI_BINUM14_MASK)

#define USB_GPRTBIMAP_FSHI_BINUM15_MASK          (0xF000000U)
#define USB_GPRTBIMAP_FSHI_BINUM15_SHIFT         (24U)
#define USB_GPRTBIMAP_FSHI_BINUM15(x)            (((uint32_t)(((uint32_t)(x)) << USB_GPRTBIMAP_FSHI_BINUM15_SHIFT)) & USB_GPRTBIMAP_FSHI_BINUM15_MASK)
/*! @} */

/*! @name GUCTL2 - Global User Control Register 2 */
/*! @{ */

#define USB_GUCTL2_TXPINGDURATION_MASK           (0x1FU)
#define USB_GUCTL2_TXPINGDURATION_SHIFT          (0U)
#define USB_GUCTL2_TXPINGDURATION(x)             (((uint32_t)(((uint32_t)(x)) << USB_GUCTL2_TXPINGDURATION_SHIFT)) & USB_GUCTL2_TXPINGDURATION_MASK)

#define USB_GUCTL2_RXPINGDURATION_MASK           (0x7E0U)
#define USB_GUCTL2_RXPINGDURATION_SHIFT          (5U)
#define USB_GUCTL2_RXPINGDURATION(x)             (((uint32_t)(((uint32_t)(x)) << USB_GUCTL2_RXPINGDURATION_SHIFT)) & USB_GUCTL2_RXPINGDURATION_MASK)

#define USB_GUCTL2_DISABLECFC_MASK               (0x800U)
#define USB_GUCTL2_DISABLECFC_SHIFT              (11U)
#define USB_GUCTL2_DISABLECFC(x)                 (((uint32_t)(((uint32_t)(x)) << USB_GUCTL2_DISABLECFC_SHIFT)) & USB_GUCTL2_DISABLECFC_MASK)

#define USB_GUCTL2_ENABLEEPCACHEEVICT_MASK       (0x1000U)
#define USB_GUCTL2_ENABLEEPCACHEEVICT_SHIFT      (12U)
#define USB_GUCTL2_ENABLEEPCACHEEVICT(x)         (((uint32_t)(((uint32_t)(x)) << USB_GUCTL2_ENABLEEPCACHEEVICT_SHIFT)) & USB_GUCTL2_ENABLEEPCACHEEVICT_MASK)

#define USB_GUCTL2_RST_ACTBITLATER_MASK          (0x4000U)
#define USB_GUCTL2_RST_ACTBITLATER_SHIFT         (14U)
#define USB_GUCTL2_RST_ACTBITLATER(x)            (((uint32_t)(((uint32_t)(x)) << USB_GUCTL2_RST_ACTBITLATER_SHIFT)) & USB_GUCTL2_RST_ACTBITLATER_MASK)

#define USB_GUCTL2_NOLOWPWRDUR_MASK              (0x78000U)
#define USB_GUCTL2_NOLOWPWRDUR_SHIFT             (15U)
#define USB_GUCTL2_NOLOWPWRDUR(x)                (((uint32_t)(((uint32_t)(x)) << USB_GUCTL2_NOLOWPWRDUR_SHIFT)) & USB_GUCTL2_NOLOWPWRDUR_MASK)

#define USB_GUCTL2_EN_HP_PM_TIMER_MASK           (0x3F80000U)
#define USB_GUCTL2_EN_HP_PM_TIMER_SHIFT          (19U)
#define USB_GUCTL2_EN_HP_PM_TIMER(x)             (((uint32_t)(((uint32_t)(x)) << USB_GUCTL2_EN_HP_PM_TIMER_SHIFT)) & USB_GUCTL2_EN_HP_PM_TIMER_MASK)
/*! @} */

/*! @name GUSB2PHYCFG - Global USB2 PHY Configuration Register */
/*! @{ */

#define USB_GUSB2PHYCFG_TOUTCAL_MASK             (0x7U)
#define USB_GUSB2PHYCFG_TOUTCAL_SHIFT            (0U)
#define USB_GUSB2PHYCFG_TOUTCAL(x)               (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_TOUTCAL_SHIFT)) & USB_GUSB2PHYCFG_TOUTCAL_MASK)

#define USB_GUSB2PHYCFG_PHYIF_MASK               (0x8U)
#define USB_GUSB2PHYCFG_PHYIF_SHIFT              (3U)
#define USB_GUSB2PHYCFG_PHYIF(x)                 (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_PHYIF_SHIFT)) & USB_GUSB2PHYCFG_PHYIF_MASK)

#define USB_GUSB2PHYCFG_ULPI_UTMI_SEL_MASK       (0x10U)
#define USB_GUSB2PHYCFG_ULPI_UTMI_SEL_SHIFT      (4U)
#define USB_GUSB2PHYCFG_ULPI_UTMI_SEL(x)         (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_ULPI_UTMI_SEL_SHIFT)) & USB_GUSB2PHYCFG_ULPI_UTMI_SEL_MASK)

#define USB_GUSB2PHYCFG_FSINTF_MASK              (0x20U)
#define USB_GUSB2PHYCFG_FSINTF_SHIFT             (5U)
#define USB_GUSB2PHYCFG_FSINTF(x)                (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_FSINTF_SHIFT)) & USB_GUSB2PHYCFG_FSINTF_MASK)

#define USB_GUSB2PHYCFG_SUSPENDUSB20_MASK        (0x40U)
#define USB_GUSB2PHYCFG_SUSPENDUSB20_SHIFT       (6U)
#define USB_GUSB2PHYCFG_SUSPENDUSB20(x)          (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_SUSPENDUSB20_SHIFT)) & USB_GUSB2PHYCFG_SUSPENDUSB20_MASK)

#define USB_GUSB2PHYCFG_PHYSEL_MASK              (0x80U)
#define USB_GUSB2PHYCFG_PHYSEL_SHIFT             (7U)
#define USB_GUSB2PHYCFG_PHYSEL(x)                (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_PHYSEL_SHIFT)) & USB_GUSB2PHYCFG_PHYSEL_MASK)

#define USB_GUSB2PHYCFG_ENBLSLPM_MASK            (0x100U)
#define USB_GUSB2PHYCFG_ENBLSLPM_SHIFT           (8U)
#define USB_GUSB2PHYCFG_ENBLSLPM(x)              (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_ENBLSLPM_SHIFT)) & USB_GUSB2PHYCFG_ENBLSLPM_MASK)

#define USB_GUSB2PHYCFG_XCVRDLY_MASK             (0x200U)
#define USB_GUSB2PHYCFG_XCVRDLY_SHIFT            (9U)
#define USB_GUSB2PHYCFG_XCVRDLY(x)               (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_XCVRDLY_SHIFT)) & USB_GUSB2PHYCFG_XCVRDLY_MASK)

#define USB_GUSB2PHYCFG_USBTRDTIM_MASK           (0x3C00U)
#define USB_GUSB2PHYCFG_USBTRDTIM_SHIFT          (10U)
#define USB_GUSB2PHYCFG_USBTRDTIM(x)             (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_USBTRDTIM_SHIFT)) & USB_GUSB2PHYCFG_USBTRDTIM_MASK)

#define USB_GUSB2PHYCFG_ULPIAUTORES_MASK         (0x8000U)
#define USB_GUSB2PHYCFG_ULPIAUTORES_SHIFT        (15U)
#define USB_GUSB2PHYCFG_ULPIAUTORES(x)           (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_ULPIAUTORES_SHIFT)) & USB_GUSB2PHYCFG_ULPIAUTORES_MASK)

#define USB_GUSB2PHYCFG_ULPIEXTVBUSDRV_MASK      (0x20000U)
#define USB_GUSB2PHYCFG_ULPIEXTVBUSDRV_SHIFT     (17U)
#define USB_GUSB2PHYCFG_ULPIEXTVBUSDRV(x)        (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_ULPIEXTVBUSDRV_SHIFT)) & USB_GUSB2PHYCFG_ULPIEXTVBUSDRV_MASK)

#define USB_GUSB2PHYCFG_ULPIEXTVBUSINDIACTOR_MASK (0x40000U)
#define USB_GUSB2PHYCFG_ULPIEXTVBUSINDIACTOR_SHIFT (18U)
#define USB_GUSB2PHYCFG_ULPIEXTVBUSINDIACTOR(x)  (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_ULPIEXTVBUSINDIACTOR_SHIFT)) & USB_GUSB2PHYCFG_ULPIEXTVBUSINDIACTOR_MASK)

#define USB_GUSB2PHYCFG_LSIPD_MASK               (0x380000U)
#define USB_GUSB2PHYCFG_LSIPD_SHIFT              (19U)
#define USB_GUSB2PHYCFG_LSIPD(x)                 (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_LSIPD_SHIFT)) & USB_GUSB2PHYCFG_LSIPD_MASK)

#define USB_GUSB2PHYCFG_LSTRD_MASK               (0x1C00000U)
#define USB_GUSB2PHYCFG_LSTRD_SHIFT              (22U)
#define USB_GUSB2PHYCFG_LSTRD(x)                 (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_LSTRD_SHIFT)) & USB_GUSB2PHYCFG_LSTRD_MASK)

#define USB_GUSB2PHYCFG_INV_SEL_HSIC_MASK        (0x4000000U)
#define USB_GUSB2PHYCFG_INV_SEL_HSIC_SHIFT       (26U)
#define USB_GUSB2PHYCFG_INV_SEL_HSIC(x)          (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_INV_SEL_HSIC_SHIFT)) & USB_GUSB2PHYCFG_INV_SEL_HSIC_MASK)

#define USB_GUSB2PHYCFG_HSIC_CON_WIDTH_ADJ_MASK  (0x18000000U)
#define USB_GUSB2PHYCFG_HSIC_CON_WIDTH_ADJ_SHIFT (27U)
#define USB_GUSB2PHYCFG_HSIC_CON_WIDTH_ADJ(x)    (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_HSIC_CON_WIDTH_ADJ_SHIFT)) & USB_GUSB2PHYCFG_HSIC_CON_WIDTH_ADJ_MASK)

#define USB_GUSB2PHYCFG_ULPI_LPM_WITH_OPMODE_CHK_MASK (0x20000000U)
#define USB_GUSB2PHYCFG_ULPI_LPM_WITH_OPMODE_CHK_SHIFT (29U)
#define USB_GUSB2PHYCFG_ULPI_LPM_WITH_OPMODE_CHK(x) (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_ULPI_LPM_WITH_OPMODE_CHK_SHIFT)) & USB_GUSB2PHYCFG_ULPI_LPM_WITH_OPMODE_CHK_MASK)

#define USB_GUSB2PHYCFG_U2_FREECLK_EXISTS_MASK   (0x40000000U)
#define USB_GUSB2PHYCFG_U2_FREECLK_EXISTS_SHIFT  (30U)
#define USB_GUSB2PHYCFG_U2_FREECLK_EXISTS(x)     (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_U2_FREECLK_EXISTS_SHIFT)) & USB_GUSB2PHYCFG_U2_FREECLK_EXISTS_MASK)

#define USB_GUSB2PHYCFG_PHYSOFTRST_MASK          (0x80000000U)
#define USB_GUSB2PHYCFG_PHYSOFTRST_SHIFT         (31U)
#define USB_GUSB2PHYCFG_PHYSOFTRST(x)            (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYCFG_PHYSOFTRST_SHIFT)) & USB_GUSB2PHYCFG_PHYSOFTRST_MASK)
/*! @} */

/*! @name GUSB2PHYACC_ULPI - Global USB 2.0 UTMI PHY vendor control register */
/*! @{ */

#define USB_GUSB2PHYACC_ULPI_REGDATA_MASK        (0xFFU)
#define USB_GUSB2PHYACC_ULPI_REGDATA_SHIFT       (0U)
#define USB_GUSB2PHYACC_ULPI_REGDATA(x)          (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYACC_ULPI_REGDATA_SHIFT)) & USB_GUSB2PHYACC_ULPI_REGDATA_MASK)

#define USB_GUSB2PHYACC_ULPI_EXTREGADDR_MASK     (0xFF00U)
#define USB_GUSB2PHYACC_ULPI_EXTREGADDR_SHIFT    (8U)
#define USB_GUSB2PHYACC_ULPI_EXTREGADDR(x)       (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYACC_ULPI_EXTREGADDR_SHIFT)) & USB_GUSB2PHYACC_ULPI_EXTREGADDR_MASK)

#define USB_GUSB2PHYACC_ULPI_REGADDR_MASK        (0x3F0000U)
#define USB_GUSB2PHYACC_ULPI_REGADDR_SHIFT       (16U)
#define USB_GUSB2PHYACC_ULPI_REGADDR(x)          (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYACC_ULPI_REGADDR_SHIFT)) & USB_GUSB2PHYACC_ULPI_REGADDR_MASK)

#define USB_GUSB2PHYACC_ULPI_REGWR_MASK          (0x400000U)
#define USB_GUSB2PHYACC_ULPI_REGWR_SHIFT         (22U)
#define USB_GUSB2PHYACC_ULPI_REGWR(x)            (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYACC_ULPI_REGWR_SHIFT)) & USB_GUSB2PHYACC_ULPI_REGWR_MASK)

#define USB_GUSB2PHYACC_ULPI_VSTSBSY_MASK        (0x800000U)
#define USB_GUSB2PHYACC_ULPI_VSTSBSY_SHIFT       (23U)
#define USB_GUSB2PHYACC_ULPI_VSTSBSY(x)          (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYACC_ULPI_VSTSBSY_SHIFT)) & USB_GUSB2PHYACC_ULPI_VSTSBSY_MASK)

#define USB_GUSB2PHYACC_ULPI_VSTSDONE_MASK       (0x1000000U)
#define USB_GUSB2PHYACC_ULPI_VSTSDONE_SHIFT      (24U)
#define USB_GUSB2PHYACC_ULPI_VSTSDONE(x)         (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYACC_ULPI_VSTSDONE_SHIFT)) & USB_GUSB2PHYACC_ULPI_VSTSDONE_MASK)

#define USB_GUSB2PHYACC_ULPI_NEWREGREQ_MASK      (0x2000000U)
#define USB_GUSB2PHYACC_ULPI_NEWREGREQ_SHIFT     (25U)
#define USB_GUSB2PHYACC_ULPI_NEWREGREQ(x)        (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYACC_ULPI_NEWREGREQ_SHIFT)) & USB_GUSB2PHYACC_ULPI_NEWREGREQ_MASK)

#define USB_GUSB2PHYACC_ULPI_DISUIPIDRVR_MASK    (0x4000000U)
#define USB_GUSB2PHYACC_ULPI_DISUIPIDRVR_SHIFT   (26U)
#define USB_GUSB2PHYACC_ULPI_DISUIPIDRVR(x)      (((uint32_t)(((uint32_t)(x)) << USB_GUSB2PHYACC_ULPI_DISUIPIDRVR_SHIFT)) & USB_GUSB2PHYACC_ULPI_DISUIPIDRVR_MASK)
/*! @} */

/*! @name GUSB3PIPECTL - Global USB 3.0 PIPE control register */
/*! @{ */

#define USB_GUSB3PIPECTL_ELASTIC_BUFFER_MODE_MASK (0x1U)
#define USB_GUSB3PIPECTL_ELASTIC_BUFFER_MODE_SHIFT (0U)
#define USB_GUSB3PIPECTL_ELASTIC_BUFFER_MODE(x)  (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_ELASTIC_BUFFER_MODE_SHIFT)) & USB_GUSB3PIPECTL_ELASTIC_BUFFER_MODE_MASK)

#define USB_GUSB3PIPECTL_SS_TX_DE_EMPHASIS_MASK  (0x6U)
#define USB_GUSB3PIPECTL_SS_TX_DE_EMPHASIS_SHIFT (1U)
#define USB_GUSB3PIPECTL_SS_TX_DE_EMPHASIS(x)    (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_SS_TX_DE_EMPHASIS_SHIFT)) & USB_GUSB3PIPECTL_SS_TX_DE_EMPHASIS_MASK)

#define USB_GUSB3PIPECTL_TX_MARGIN_MASK          (0x38U)
#define USB_GUSB3PIPECTL_TX_MARGIN_SHIFT         (3U)
#define USB_GUSB3PIPECTL_TX_MARGIN(x)            (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_TX_MARGIN_SHIFT)) & USB_GUSB3PIPECTL_TX_MARGIN_MASK)

#define USB_GUSB3PIPECTL_TX_SWING_MASK           (0x40U)
#define USB_GUSB3PIPECTL_TX_SWING_SHIFT          (6U)
#define USB_GUSB3PIPECTL_TX_SWING(x)             (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_TX_SWING_SHIFT)) & USB_GUSB3PIPECTL_TX_SWING_MASK)

#define USB_GUSB3PIPECTL_SSICEN_MASK             (0x80U)
#define USB_GUSB3PIPECTL_SSICEN_SHIFT            (7U)
#define USB_GUSB3PIPECTL_SSICEN(x)               (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_SSICEN_SHIFT)) & USB_GUSB3PIPECTL_SSICEN_MASK)

#define USB_GUSB3PIPECTL_RX_DETECT_TO_POLLING_LFPS_CONTROL_MASK (0x100U)
#define USB_GUSB3PIPECTL_RX_DETECT_TO_POLLING_LFPS_CONTROL_SHIFT (8U)
#define USB_GUSB3PIPECTL_RX_DETECT_TO_POLLING_LFPS_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_RX_DETECT_TO_POLLING_LFPS_CONTROL_SHIFT)) & USB_GUSB3PIPECTL_RX_DETECT_TO_POLLING_LFPS_CONTROL_MASK)

#define USB_GUSB3PIPECTL_LFPSFILTER_MASK         (0x200U)
#define USB_GUSB3PIPECTL_LFPSFILTER_SHIFT        (9U)
#define USB_GUSB3PIPECTL_LFPSFILTER(x)           (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_LFPSFILTER_SHIFT)) & USB_GUSB3PIPECTL_LFPSFILTER_MASK)

#define USB_GUSB3PIPECTL_P3EXSIGP2_MASK          (0x400U)
#define USB_GUSB3PIPECTL_P3EXSIGP2_SHIFT         (10U)
#define USB_GUSB3PIPECTL_P3EXSIGP2(x)            (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_P3EXSIGP2_SHIFT)) & USB_GUSB3PIPECTL_P3EXSIGP2_MASK)

#define USB_GUSB3PIPECTL_P3P2TRANOK_MASK         (0x800U)
#define USB_GUSB3PIPECTL_P3P2TRANOK_SHIFT        (11U)
#define USB_GUSB3PIPECTL_P3P2TRANOK(x)           (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_P3P2TRANOK_SHIFT)) & USB_GUSB3PIPECTL_P3P2TRANOK_MASK)

#define USB_GUSB3PIPECTL_LFPSP0ALGN_MASK         (0x1000U)
#define USB_GUSB3PIPECTL_LFPSP0ALGN_SHIFT        (12U)
#define USB_GUSB3PIPECTL_LFPSP0ALGN(x)           (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_LFPSP0ALGN_SHIFT)) & USB_GUSB3PIPECTL_LFPSP0ALGN_MASK)

#define USB_GUSB3PIPECTL_SKIPRXDET_MASK          (0x2000U)
#define USB_GUSB3PIPECTL_SKIPRXDET_SHIFT         (13U)
#define USB_GUSB3PIPECTL_SKIPRXDET(x)            (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_SKIPRXDET_SHIFT)) & USB_GUSB3PIPECTL_SKIPRXDET_MASK)

#define USB_GUSB3PIPECTL_ABORTRXDETINU2_MASK     (0x4000U)
#define USB_GUSB3PIPECTL_ABORTRXDETINU2_SHIFT    (14U)
#define USB_GUSB3PIPECTL_ABORTRXDETINU2(x)       (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_ABORTRXDETINU2_SHIFT)) & USB_GUSB3PIPECTL_ABORTRXDETINU2_MASK)

#define USB_GUSB3PIPECTL_DATWIDTH_MASK           (0x18000U)
#define USB_GUSB3PIPECTL_DATWIDTH_SHIFT          (15U)
#define USB_GUSB3PIPECTL_DATWIDTH(x)             (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_DATWIDTH_SHIFT)) & USB_GUSB3PIPECTL_DATWIDTH_MASK)

#define USB_GUSB3PIPECTL_SUSPENDENABLE_MASK      (0x20000U)
#define USB_GUSB3PIPECTL_SUSPENDENABLE_SHIFT     (17U)
#define USB_GUSB3PIPECTL_SUSPENDENABLE(x)        (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_SUSPENDENABLE_SHIFT)) & USB_GUSB3PIPECTL_SUSPENDENABLE_MASK)

#define USB_GUSB3PIPECTL_DELAYP1TRANS_MASK       (0x40000U)
#define USB_GUSB3PIPECTL_DELAYP1TRANS_SHIFT      (18U)
#define USB_GUSB3PIPECTL_DELAYP1TRANS(x)         (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_DELAYP1TRANS_SHIFT)) & USB_GUSB3PIPECTL_DELAYP1TRANS_MASK)

#define USB_GUSB3PIPECTL_DELAYP1P2P3_MASK        (0x380000U)
#define USB_GUSB3PIPECTL_DELAYP1P2P3_SHIFT       (19U)
#define USB_GUSB3PIPECTL_DELAYP1P2P3(x)          (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_DELAYP1P2P3_SHIFT)) & USB_GUSB3PIPECTL_DELAYP1P2P3_MASK)

#define USB_GUSB3PIPECTL_DISRXDETU3RXDET_MASK    (0x400000U)
#define USB_GUSB3PIPECTL_DISRXDETU3RXDET_SHIFT   (22U)
#define USB_GUSB3PIPECTL_DISRXDETU3RXDET(x)      (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_DISRXDETU3RXDET_SHIFT)) & USB_GUSB3PIPECTL_DISRXDETU3RXDET_MASK)

#define USB_GUSB3PIPECTL_STARTRXDETU3RXDET_MASK  (0x800000U)
#define USB_GUSB3PIPECTL_STARTRXDETU3RXDET_SHIFT (23U)
#define USB_GUSB3PIPECTL_STARTRXDETU3RXDET(x)    (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_STARTRXDETU3RXDET_SHIFT)) & USB_GUSB3PIPECTL_STARTRXDETU3RXDET_MASK)

#define USB_GUSB3PIPECTL_REQUEST_P1P2P3_MASK     (0x1000000U)
#define USB_GUSB3PIPECTL_REQUEST_P1P2P3_SHIFT    (24U)
#define USB_GUSB3PIPECTL_REQUEST_P1P2P3(x)       (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_REQUEST_P1P2P3_SHIFT)) & USB_GUSB3PIPECTL_REQUEST_P1P2P3_MASK)

#define USB_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_MASK (0x2000000U)
#define USB_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_SHIFT (25U)
#define USB_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV(x) (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_SHIFT)) & USB_GUSB3PIPECTL_U1U2EXITFAIL_TO_RECOV_MASK)

#define USB_GUSB3PIPECTL_PING_ENHANCEMENT_EN_MASK (0x4000000U)
#define USB_GUSB3PIPECTL_PING_ENHANCEMENT_EN_SHIFT (26U)
#define USB_GUSB3PIPECTL_PING_ENHANCEMENT_EN(x)  (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_PING_ENHANCEMENT_EN_SHIFT)) & USB_GUSB3PIPECTL_PING_ENHANCEMENT_EN_MASK)

#define USB_GUSB3PIPECTL_UX_EXIT_IN_PX_MASK      (0x8000000U)
#define USB_GUSB3PIPECTL_UX_EXIT_IN_PX_SHIFT     (27U)
#define USB_GUSB3PIPECTL_UX_EXIT_IN_PX(x)        (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_UX_EXIT_IN_PX_SHIFT)) & USB_GUSB3PIPECTL_UX_EXIT_IN_PX_MASK)

#define USB_GUSB3PIPECTL_DISRXDETP3_MASK         (0x10000000U)
#define USB_GUSB3PIPECTL_DISRXDETP3_SHIFT        (28U)
#define USB_GUSB3PIPECTL_DISRXDETP3(x)           (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_DISRXDETP3_SHIFT)) & USB_GUSB3PIPECTL_DISRXDETP3_MASK)

#define USB_GUSB3PIPECTL_U2P3OK_MASK             (0x20000000U)
#define USB_GUSB3PIPECTL_U2P3OK_SHIFT            (29U)
#define USB_GUSB3PIPECTL_U2P3OK(x)               (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_U2P3OK_SHIFT)) & USB_GUSB3PIPECTL_U2P3OK_MASK)

#define USB_GUSB3PIPECTL_HSTPRTCMPL_MASK         (0x40000000U)
#define USB_GUSB3PIPECTL_HSTPRTCMPL_SHIFT        (30U)
#define USB_GUSB3PIPECTL_HSTPRTCMPL(x)           (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_HSTPRTCMPL_SHIFT)) & USB_GUSB3PIPECTL_HSTPRTCMPL_MASK)

#define USB_GUSB3PIPECTL_PHYSOFTRST_MASK         (0x80000000U)
#define USB_GUSB3PIPECTL_PHYSOFTRST_SHIFT        (31U)
#define USB_GUSB3PIPECTL_PHYSOFTRST(x)           (((uint32_t)(((uint32_t)(x)) << USB_GUSB3PIPECTL_PHYSOFTRST_SHIFT)) & USB_GUSB3PIPECTL_PHYSOFTRST_MASK)
/*! @} */

/*! @name GTXFIFOSIZ - Global transmit FIFO size register */
/*! @{ */

#define USB_GTXFIFOSIZ_TXFDEP_N_MASK             (0xFFFFU)
#define USB_GTXFIFOSIZ_TXFDEP_N_SHIFT            (0U)
/*! TXFDEP_N - TXFIFO depth */
#define USB_GTXFIFOSIZ_TXFDEP_N(x)               (((uint32_t)(((uint32_t)(x)) << USB_GTXFIFOSIZ_TXFDEP_N_SHIFT)) & USB_GTXFIFOSIZ_TXFDEP_N_MASK)

#define USB_GTXFIFOSIZ_TXFSTADDR_N_MASK          (0xFFFF0000U)
#define USB_GTXFIFOSIZ_TXFSTADDR_N_SHIFT         (16U)
#define USB_GTXFIFOSIZ_TXFSTADDR_N(x)            (((uint32_t)(((uint32_t)(x)) << USB_GTXFIFOSIZ_TXFSTADDR_N_SHIFT)) & USB_GTXFIFOSIZ_TXFSTADDR_N_MASK)
/*! @} */

/* The count of USB_GTXFIFOSIZ */
#define USB_GTXFIFOSIZ_COUNT                     (8U)

/*! @name GRXFIFOSIZ - Global receive FIFO size register */
/*! @{ */

#define USB_GRXFIFOSIZ_RXFDEP_N_MASK             (0xFFFFU)
#define USB_GRXFIFOSIZ_RXFDEP_N_SHIFT            (0U)
#define USB_GRXFIFOSIZ_RXFDEP_N(x)               (((uint32_t)(((uint32_t)(x)) << USB_GRXFIFOSIZ_RXFDEP_N_SHIFT)) & USB_GRXFIFOSIZ_RXFDEP_N_MASK)

#define USB_GRXFIFOSIZ_RXFSTADDR_N_MASK          (0xFFFF0000U)
#define USB_GRXFIFOSIZ_RXFSTADDR_N_SHIFT         (16U)
#define USB_GRXFIFOSIZ_RXFSTADDR_N(x)            (((uint32_t)(((uint32_t)(x)) << USB_GRXFIFOSIZ_RXFSTADDR_N_SHIFT)) & USB_GRXFIFOSIZ_RXFSTADDR_N_MASK)
/*! @} */

/* The count of USB_GRXFIFOSIZ */
#define USB_GRXFIFOSIZ_COUNT                     (3U)

/*! @name GEVNTADRLO - Global Event Buffer Address (Low) Register */
/*! @{ */

#define USB_GEVNTADRLO_EVNTADRLO_MASK            (0xFFFFFFFFU)
#define USB_GEVNTADRLO_EVNTADRLO_SHIFT           (0U)
#define USB_GEVNTADRLO_EVNTADRLO(x)              (((uint32_t)(((uint32_t)(x)) << USB_GEVNTADRLO_EVNTADRLO_SHIFT)) & USB_GEVNTADRLO_EVNTADRLO_MASK)
/*! @} */

/*! @name GEVNTADRHI - Global Event Buffer Address (High) Register */
/*! @{ */

#define USB_GEVNTADRHI_EVNTADRHI_MASK            (0xFFFFFFFFU)
#define USB_GEVNTADRHI_EVNTADRHI_SHIFT           (0U)
#define USB_GEVNTADRHI_EVNTADRHI(x)              (((uint32_t)(((uint32_t)(x)) << USB_GEVNTADRHI_EVNTADRHI_SHIFT)) & USB_GEVNTADRHI_EVNTADRHI_MASK)
/*! @} */

/*! @name GEVNTSIZ - Global event buffer size register */
/*! @{ */

#define USB_GEVNTSIZ_EVENTSIZ_MASK               (0xFFFFU)
#define USB_GEVNTSIZ_EVENTSIZ_SHIFT              (0U)
#define USB_GEVNTSIZ_EVENTSIZ(x)                 (((uint32_t)(((uint32_t)(x)) << USB_GEVNTSIZ_EVENTSIZ_SHIFT)) & USB_GEVNTSIZ_EVENTSIZ_MASK)

#define USB_GEVNTSIZ_EVNTINTRPTMASK_MASK         (0x80000000U)
#define USB_GEVNTSIZ_EVNTINTRPTMASK_SHIFT        (31U)
#define USB_GEVNTSIZ_EVNTINTRPTMASK(x)           (((uint32_t)(((uint32_t)(x)) << USB_GEVNTSIZ_EVNTINTRPTMASK_SHIFT)) & USB_GEVNTSIZ_EVNTINTRPTMASK_MASK)
/*! @} */

/*! @name GEVNTCOUNT - Global event buffer count register */
/*! @{ */

#define USB_GEVNTCOUNT_EVNTCOUNT_MASK            (0xFFFFU)
#define USB_GEVNTCOUNT_EVNTCOUNT_SHIFT           (0U)
#define USB_GEVNTCOUNT_EVNTCOUNT(x)              (((uint32_t)(((uint32_t)(x)) << USB_GEVNTCOUNT_EVNTCOUNT_SHIFT)) & USB_GEVNTCOUNT_EVNTCOUNT_MASK)

#define USB_GEVNTCOUNT_EVNT_HANDLER_BUSY_MASK    (0x80000000U)
#define USB_GEVNTCOUNT_EVNT_HANDLER_BUSY_SHIFT   (31U)
#define USB_GEVNTCOUNT_EVNT_HANDLER_BUSY(x)      (((uint32_t)(((uint32_t)(x)) << USB_GEVNTCOUNT_EVNT_HANDLER_BUSY_SHIFT)) & USB_GEVNTCOUNT_EVNT_HANDLER_BUSY_MASK)
/*! @} */

/*! @name GHWPARAMS8 - Global Hardware Parameters Register 8 */
/*! @{ */

#define USB_GHWPARAMS8_GHWPARAMS8_32_0_MASK      (0xFFFFFFFFU)
#define USB_GHWPARAMS8_GHWPARAMS8_32_0_SHIFT     (0U)
#define USB_GHWPARAMS8_GHWPARAMS8_32_0(x)        (((uint32_t)(((uint32_t)(x)) << USB_GHWPARAMS8_GHWPARAMS8_32_0_SHIFT)) & USB_GHWPARAMS8_GHWPARAMS8_32_0_MASK)
/*! @} */

/*! @name GTXFIFOPRIDEV - Global Device TX FIFO DMA Priority Register */
/*! @{ */

#define USB_GTXFIFOPRIDEV_GTXFIFOPRIDEV_MASK     (0xFFU)
#define USB_GTXFIFOPRIDEV_GTXFIFOPRIDEV_SHIFT    (0U)
#define USB_GTXFIFOPRIDEV_GTXFIFOPRIDEV(x)       (((uint32_t)(((uint32_t)(x)) << USB_GTXFIFOPRIDEV_GTXFIFOPRIDEV_SHIFT)) & USB_GTXFIFOPRIDEV_GTXFIFOPRIDEV_MASK)
/*! @} */

/*! @name GTXFIFOPRIHST - Global Host TX FIFO DMA Priority Register */
/*! @{ */

#define USB_GTXFIFOPRIHST_GTXFIFOPRIHST_MASK     (0xFU)
#define USB_GTXFIFOPRIHST_GTXFIFOPRIHST_SHIFT    (0U)
#define USB_GTXFIFOPRIHST_GTXFIFOPRIHST(x)       (((uint32_t)(((uint32_t)(x)) << USB_GTXFIFOPRIHST_GTXFIFOPRIHST_SHIFT)) & USB_GTXFIFOPRIHST_GTXFIFOPRIHST_MASK)
/*! @} */

/*! @name GRXFIFOPRIHST - Global Host RX FIFO DMA Priority Register */
/*! @{ */

#define USB_GRXFIFOPRIHST_GRXFIFOPRIHST_MASK     (0x7U)
#define USB_GRXFIFOPRIHST_GRXFIFOPRIHST_SHIFT    (0U)
#define USB_GRXFIFOPRIHST_GRXFIFOPRIHST(x)       (((uint32_t)(((uint32_t)(x)) << USB_GRXFIFOPRIHST_GRXFIFOPRIHST_SHIFT)) & USB_GRXFIFOPRIHST_GRXFIFOPRIHST_MASK)
/*! @} */

/*! @name GFIFOPRIDBC - Global Host Debug Capability DMA Priority Register */
/*! @{ */

#define USB_GFIFOPRIDBC_GFIFOPRIDBC_MASK         (0x3U)
#define USB_GFIFOPRIDBC_GFIFOPRIDBC_SHIFT        (0U)
#define USB_GFIFOPRIDBC_GFIFOPRIDBC(x)           (((uint32_t)(((uint32_t)(x)) << USB_GFIFOPRIDBC_GFIFOPRIDBC_SHIFT)) & USB_GFIFOPRIDBC_GFIFOPRIDBC_MASK)
/*! @} */

/*! @name GDMAHLRATIO -  */
/*! @{ */

#define USB_GDMAHLRATIO_HSTTXFIFO_MASK           (0x1FU)
#define USB_GDMAHLRATIO_HSTTXFIFO_SHIFT          (0U)
#define USB_GDMAHLRATIO_HSTTXFIFO(x)             (((uint32_t)(((uint32_t)(x)) << USB_GDMAHLRATIO_HSTTXFIFO_SHIFT)) & USB_GDMAHLRATIO_HSTTXFIFO_MASK)

#define USB_GDMAHLRATIO_HSTRXFIFO_MASK           (0x1F00U)
#define USB_GDMAHLRATIO_HSTRXFIFO_SHIFT          (8U)
#define USB_GDMAHLRATIO_HSTRXFIFO(x)             (((uint32_t)(((uint32_t)(x)) << USB_GDMAHLRATIO_HSTRXFIFO_SHIFT)) & USB_GDMAHLRATIO_HSTRXFIFO_MASK)
/*! @} */

/*! @name GFLADJ - Global Frame Length Adjustment Register */
/*! @{ */

#define USB_GFLADJ_GFLADJ_30MHZ_MASK             (0x3FU)
#define USB_GFLADJ_GFLADJ_30MHZ_SHIFT            (0U)
#define USB_GFLADJ_GFLADJ_30MHZ(x)               (((uint32_t)(((uint32_t)(x)) << USB_GFLADJ_GFLADJ_30MHZ_SHIFT)) & USB_GFLADJ_GFLADJ_30MHZ_MASK)

#define USB_GFLADJ_GFLADJ_30MHZ_SDBND_SEL_MASK   (0x80U)
#define USB_GFLADJ_GFLADJ_30MHZ_SDBND_SEL_SHIFT  (7U)
#define USB_GFLADJ_GFLADJ_30MHZ_SDBND_SEL(x)     (((uint32_t)(((uint32_t)(x)) << USB_GFLADJ_GFLADJ_30MHZ_SDBND_SEL_SHIFT)) & USB_GFLADJ_GFLADJ_30MHZ_SDBND_SEL_MASK)

#define USB_GFLADJ_GFLADJ_REFCLK_FLADJ_MASK      (0x3FFF00U)
#define USB_GFLADJ_GFLADJ_REFCLK_FLADJ_SHIFT     (8U)
#define USB_GFLADJ_GFLADJ_REFCLK_FLADJ(x)        (((uint32_t)(((uint32_t)(x)) << USB_GFLADJ_GFLADJ_REFCLK_FLADJ_SHIFT)) & USB_GFLADJ_GFLADJ_REFCLK_FLADJ_MASK)

#define USB_GFLADJ_GFLADJ_REFCLK_LPM_SEL_MASK    (0x800000U)
#define USB_GFLADJ_GFLADJ_REFCLK_LPM_SEL_SHIFT   (23U)
#define USB_GFLADJ_GFLADJ_REFCLK_LPM_SEL(x)      (((uint32_t)(((uint32_t)(x)) << USB_GFLADJ_GFLADJ_REFCLK_LPM_SEL_SHIFT)) & USB_GFLADJ_GFLADJ_REFCLK_LPM_SEL_MASK)

#define USB_GFLADJ_GFLADJ_REFCLK_240MHZ_DECR_MASK (0x7F000000U)
#define USB_GFLADJ_GFLADJ_REFCLK_240MHZ_DECR_SHIFT (24U)
#define USB_GFLADJ_GFLADJ_REFCLK_240MHZ_DECR(x)  (((uint32_t)(((uint32_t)(x)) << USB_GFLADJ_GFLADJ_REFCLK_240MHZ_DECR_SHIFT)) & USB_GFLADJ_GFLADJ_REFCLK_240MHZ_DECR_MASK)

#define USB_GFLADJ_GFLADJ_REFCLK_240MHZDECR_PLS1_MASK (0x80000000U)
#define USB_GFLADJ_GFLADJ_REFCLK_240MHZDECR_PLS1_SHIFT (31U)
#define USB_GFLADJ_GFLADJ_REFCLK_240MHZDECR_PLS1(x) (((uint32_t)(((uint32_t)(x)) << USB_GFLADJ_GFLADJ_REFCLK_240MHZDECR_PLS1_SHIFT)) & USB_GFLADJ_GFLADJ_REFCLK_240MHZDECR_PLS1_MASK)
/*! @} */

/*! @name DCFG - Device Configuration Register */
/*! @{ */

#define USB_DCFG_DEVSPD_MASK                     (0x7U)
#define USB_DCFG_DEVSPD_SHIFT                    (0U)
/*! DEVSPD
 *  0b000..
 *  0b001..
 *  0b100..
 */
#define USB_DCFG_DEVSPD(x)                       (((uint32_t)(((uint32_t)(x)) << USB_DCFG_DEVSPD_SHIFT)) & USB_DCFG_DEVSPD_MASK)

#define USB_DCFG_DEVADDR_MASK                    (0x3F8U)
#define USB_DCFG_DEVADDR_SHIFT                   (3U)
#define USB_DCFG_DEVADDR(x)                      (((uint32_t)(((uint32_t)(x)) << USB_DCFG_DEVADDR_SHIFT)) & USB_DCFG_DEVADDR_MASK)

#define USB_DCFG_INTRNUM_MASK                    (0x1F000U)
#define USB_DCFG_INTRNUM_SHIFT                   (12U)
#define USB_DCFG_INTRNUM(x)                      (((uint32_t)(((uint32_t)(x)) << USB_DCFG_INTRNUM_SHIFT)) & USB_DCFG_INTRNUM_MASK)

#define USB_DCFG_NUMP_MASK                       (0x3E0000U)
#define USB_DCFG_NUMP_SHIFT                      (17U)
#define USB_DCFG_NUMP(x)                         (((uint32_t)(((uint32_t)(x)) << USB_DCFG_NUMP_SHIFT)) & USB_DCFG_NUMP_MASK)

#define USB_DCFG_LPMCAP_MASK                     (0x400000U)
#define USB_DCFG_LPMCAP_SHIFT                    (22U)
#define USB_DCFG_LPMCAP(x)                       (((uint32_t)(((uint32_t)(x)) << USB_DCFG_LPMCAP_SHIFT)) & USB_DCFG_LPMCAP_MASK)

#define USB_DCFG_IGNSTRMPP_MASK                  (0x800000U)
#define USB_DCFG_IGNSTRMPP_SHIFT                 (23U)
#define USB_DCFG_IGNSTRMPP(x)                    (((uint32_t)(((uint32_t)(x)) << USB_DCFG_IGNSTRMPP_SHIFT)) & USB_DCFG_IGNSTRMPP_MASK)
/*! @} */

/*! @name DCTL - Device control register */
/*! @{ */

#define USB_DCTL_TSTCTL_MASK                     (0x1EU)
#define USB_DCTL_TSTCTL_SHIFT                    (1U)
#define USB_DCTL_TSTCTL(x)                       (((uint32_t)(((uint32_t)(x)) << USB_DCTL_TSTCTL_SHIFT)) & USB_DCTL_TSTCTL_MASK)

#define USB_DCTL_ULSTCHNGREQ_MASK                (0x1E0U)
#define USB_DCTL_ULSTCHNGREQ_SHIFT               (5U)
#define USB_DCTL_ULSTCHNGREQ(x)                  (((uint32_t)(((uint32_t)(x)) << USB_DCTL_ULSTCHNGREQ_SHIFT)) & USB_DCTL_ULSTCHNGREQ_MASK)

#define USB_DCTL_ACCEPTU1ENA_MASK                (0x200U)
#define USB_DCTL_ACCEPTU1ENA_SHIFT               (9U)
#define USB_DCTL_ACCEPTU1ENA(x)                  (((uint32_t)(((uint32_t)(x)) << USB_DCTL_ACCEPTU1ENA_SHIFT)) & USB_DCTL_ACCEPTU1ENA_MASK)

#define USB_DCTL_INITU1ENA_MASK                  (0x400U)
#define USB_DCTL_INITU1ENA_SHIFT                 (10U)
#define USB_DCTL_INITU1ENA(x)                    (((uint32_t)(((uint32_t)(x)) << USB_DCTL_INITU1ENA_SHIFT)) & USB_DCTL_INITU1ENA_MASK)

#define USB_DCTL_ACCEPTU2ENA_MASK                (0x800U)
#define USB_DCTL_ACCEPTU2ENA_SHIFT               (11U)
#define USB_DCTL_ACCEPTU2ENA(x)                  (((uint32_t)(((uint32_t)(x)) << USB_DCTL_ACCEPTU2ENA_SHIFT)) & USB_DCTL_ACCEPTU2ENA_MASK)

#define USB_DCTL_INITU2ENA_MASK                  (0x1000U)
#define USB_DCTL_INITU2ENA_SHIFT                 (12U)
#define USB_DCTL_INITU2ENA(x)                    (((uint32_t)(((uint32_t)(x)) << USB_DCTL_INITU2ENA_SHIFT)) & USB_DCTL_INITU2ENA_MASK)

#define USB_DCTL_CSS_MASK                        (0x10000U)
#define USB_DCTL_CSS_SHIFT                       (16U)
#define USB_DCTL_CSS(x)                          (((uint32_t)(((uint32_t)(x)) << USB_DCTL_CSS_SHIFT)) & USB_DCTL_CSS_MASK)

#define USB_DCTL_CRS_MASK                        (0x20000U)
#define USB_DCTL_CRS_SHIFT                       (17U)
#define USB_DCTL_CRS(x)                          (((uint32_t)(((uint32_t)(x)) << USB_DCTL_CRS_SHIFT)) & USB_DCTL_CRS_MASK)

#define USB_DCTL_L1HIBERNATIONEN_MASK            (0x40000U)
#define USB_DCTL_L1HIBERNATIONEN_SHIFT           (18U)
#define USB_DCTL_L1HIBERNATIONEN(x)              (((uint32_t)(((uint32_t)(x)) << USB_DCTL_L1HIBERNATIONEN_SHIFT)) & USB_DCTL_L1HIBERNATIONEN_MASK)

#define USB_DCTL_KEEPCONNECT_MASK                (0x80000U)
#define USB_DCTL_KEEPCONNECT_SHIFT               (19U)
#define USB_DCTL_KEEPCONNECT(x)                  (((uint32_t)(((uint32_t)(x)) << USB_DCTL_KEEPCONNECT_SHIFT)) & USB_DCTL_KEEPCONNECT_MASK)

#define USB_DCTL_LPM_NYET_THRES_MASK             (0xF00000U)
#define USB_DCTL_LPM_NYET_THRES_SHIFT            (20U)
#define USB_DCTL_LPM_NYET_THRES(x)               (((uint32_t)(((uint32_t)(x)) << USB_DCTL_LPM_NYET_THRES_SHIFT)) & USB_DCTL_LPM_NYET_THRES_MASK)

#define USB_DCTL_HIRDTHRES_MASK                  (0x1F000000U)
#define USB_DCTL_HIRDTHRES_SHIFT                 (24U)
#define USB_DCTL_HIRDTHRES(x)                    (((uint32_t)(((uint32_t)(x)) << USB_DCTL_HIRDTHRES_SHIFT)) & USB_DCTL_HIRDTHRES_MASK)

#define USB_DCTL_CSFTRST_MASK                    (0x40000000U)
#define USB_DCTL_CSFTRST_SHIFT                   (30U)
#define USB_DCTL_CSFTRST(x)                      (((uint32_t)(((uint32_t)(x)) << USB_DCTL_CSFTRST_SHIFT)) & USB_DCTL_CSFTRST_MASK)

#define USB_DCTL_RUN_STOP_MASK                   (0x80000000U)
#define USB_DCTL_RUN_STOP_SHIFT                  (31U)
#define USB_DCTL_RUN_STOP(x)                     (((uint32_t)(((uint32_t)(x)) << USB_DCTL_RUN_STOP_SHIFT)) & USB_DCTL_RUN_STOP_MASK)
/*! @} */

/*! @name DEVTEN - Device Event Enable Register */
/*! @{ */

#define USB_DEVTEN_DISSCONNEVTEN_MASK            (0x1U)
#define USB_DEVTEN_DISSCONNEVTEN_SHIFT           (0U)
#define USB_DEVTEN_DISSCONNEVTEN(x)              (((uint32_t)(((uint32_t)(x)) << USB_DEVTEN_DISSCONNEVTEN_SHIFT)) & USB_DEVTEN_DISSCONNEVTEN_MASK)

#define USB_DEVTEN_USBRSTEVTEN_MASK              (0x2U)
#define USB_DEVTEN_USBRSTEVTEN_SHIFT             (1U)
#define USB_DEVTEN_USBRSTEVTEN(x)                (((uint32_t)(((uint32_t)(x)) << USB_DEVTEN_USBRSTEVTEN_SHIFT)) & USB_DEVTEN_USBRSTEVTEN_MASK)

#define USB_DEVTEN_CONNECTDONEEVTEN_MASK         (0x4U)
#define USB_DEVTEN_CONNECTDONEEVTEN_SHIFT        (2U)
#define USB_DEVTEN_CONNECTDONEEVTEN(x)           (((uint32_t)(((uint32_t)(x)) << USB_DEVTEN_CONNECTDONEEVTEN_SHIFT)) & USB_DEVTEN_CONNECTDONEEVTEN_MASK)

#define USB_DEVTEN_ULSTCNGEN_MASK                (0x8U)
#define USB_DEVTEN_ULSTCNGEN_SHIFT               (3U)
#define USB_DEVTEN_ULSTCNGEN(x)                  (((uint32_t)(((uint32_t)(x)) << USB_DEVTEN_ULSTCNGEN_SHIFT)) & USB_DEVTEN_ULSTCNGEN_MASK)

#define USB_DEVTEN_WKUPEVTEN_MASK                (0x10U)
#define USB_DEVTEN_WKUPEVTEN_SHIFT               (4U)
#define USB_DEVTEN_WKUPEVTEN(x)                  (((uint32_t)(((uint32_t)(x)) << USB_DEVTEN_WKUPEVTEN_SHIFT)) & USB_DEVTEN_WKUPEVTEN_MASK)

#define USB_DEVTEN_HIBERNATIONREQEVTEN_MASK      (0x20U)
#define USB_DEVTEN_HIBERNATIONREQEVTEN_SHIFT     (5U)
#define USB_DEVTEN_HIBERNATIONREQEVTEN(x)        (((uint32_t)(((uint32_t)(x)) << USB_DEVTEN_HIBERNATIONREQEVTEN_SHIFT)) & USB_DEVTEN_HIBERNATIONREQEVTEN_MASK)

#define USB_DEVTEN_U3L2L1SUSPEN_MASK             (0x40U)
#define USB_DEVTEN_U3L2L1SUSPEN_SHIFT            (6U)
#define USB_DEVTEN_U3L2L1SUSPEN(x)               (((uint32_t)(((uint32_t)(x)) << USB_DEVTEN_U3L2L1SUSPEN_SHIFT)) & USB_DEVTEN_U3L2L1SUSPEN_MASK)

#define USB_DEVTEN_SOFTEVTEN_MASK                (0x80U)
#define USB_DEVTEN_SOFTEVTEN_SHIFT               (7U)
#define USB_DEVTEN_SOFTEVTEN(x)                  (((uint32_t)(((uint32_t)(x)) << USB_DEVTEN_SOFTEVTEN_SHIFT)) & USB_DEVTEN_SOFTEVTEN_MASK)

#define USB_DEVTEN_L1SUSPEN_MASK                 (0x100U)
#define USB_DEVTEN_L1SUSPEN_SHIFT                (8U)
#define USB_DEVTEN_L1SUSPEN(x)                   (((uint32_t)(((uint32_t)(x)) << USB_DEVTEN_L1SUSPEN_SHIFT)) & USB_DEVTEN_L1SUSPEN_MASK)

#define USB_DEVTEN_ERRTICERREVTEN_MASK           (0x200U)
#define USB_DEVTEN_ERRTICERREVTEN_SHIFT          (9U)
#define USB_DEVTEN_ERRTICERREVTEN(x)             (((uint32_t)(((uint32_t)(x)) << USB_DEVTEN_ERRTICERREVTEN_SHIFT)) & USB_DEVTEN_ERRTICERREVTEN_MASK)

#define USB_DEVTEN_VENDEVTSTRCVDEN_MASK          (0x1000U)
#define USB_DEVTEN_VENDEVTSTRCVDEN_SHIFT         (12U)
#define USB_DEVTEN_VENDEVTSTRCVDEN(x)            (((uint32_t)(((uint32_t)(x)) << USB_DEVTEN_VENDEVTSTRCVDEN_SHIFT)) & USB_DEVTEN_VENDEVTSTRCVDEN_MASK)

#define USB_DEVTEN_L1WKUPEVTEN_MASK              (0x4000U)
#define USB_DEVTEN_L1WKUPEVTEN_SHIFT             (14U)
#define USB_DEVTEN_L1WKUPEVTEN(x)                (((uint32_t)(((uint32_t)(x)) << USB_DEVTEN_L1WKUPEVTEN_SHIFT)) & USB_DEVTEN_L1WKUPEVTEN_MASK)

#define USB_DEVTEN_ECCERREN_MASK                 (0x10000U)
#define USB_DEVTEN_ECCERREN_SHIFT                (16U)
#define USB_DEVTEN_ECCERREN(x)                   (((uint32_t)(((uint32_t)(x)) << USB_DEVTEN_ECCERREN_SHIFT)) & USB_DEVTEN_ECCERREN_MASK)
/*! @} */

/*! @name DSTS - Device Status Register */
/*! @{ */

#define USB_DSTS_CONNECTSPD_MASK                 (0x7U)
#define USB_DSTS_CONNECTSPD_SHIFT                (0U)
/*! CONNECTSPD
 *  0b000..
 *  0b001..
 *  0b100..
 */
#define USB_DSTS_CONNECTSPD(x)                   (((uint32_t)(((uint32_t)(x)) << USB_DSTS_CONNECTSPD_SHIFT)) & USB_DSTS_CONNECTSPD_MASK)

#define USB_DSTS_SOFFN_MASK                      (0x1FFF8U)
#define USB_DSTS_SOFFN_SHIFT                     (3U)
#define USB_DSTS_SOFFN(x)                        (((uint32_t)(((uint32_t)(x)) << USB_DSTS_SOFFN_SHIFT)) & USB_DSTS_SOFFN_MASK)

#define USB_DSTS_RXFIFOEMPTY_MASK                (0x20000U)
#define USB_DSTS_RXFIFOEMPTY_SHIFT               (17U)
#define USB_DSTS_RXFIFOEMPTY(x)                  (((uint32_t)(((uint32_t)(x)) << USB_DSTS_RXFIFOEMPTY_SHIFT)) & USB_DSTS_RXFIFOEMPTY_MASK)

#define USB_DSTS_USBLNKST_MASK                   (0x3C0000U)
#define USB_DSTS_USBLNKST_SHIFT                  (18U)
#define USB_DSTS_USBLNKST(x)                     (((uint32_t)(((uint32_t)(x)) << USB_DSTS_USBLNKST_SHIFT)) & USB_DSTS_USBLNKST_MASK)

#define USB_DSTS_DEVCTRLHLT_MASK                 (0x400000U)
#define USB_DSTS_DEVCTRLHLT_SHIFT                (22U)
#define USB_DSTS_DEVCTRLHLT(x)                   (((uint32_t)(((uint32_t)(x)) << USB_DSTS_DEVCTRLHLT_SHIFT)) & USB_DSTS_DEVCTRLHLT_MASK)

#define USB_DSTS_COREIDLE_MASK                   (0x800000U)
#define USB_DSTS_COREIDLE_SHIFT                  (23U)
#define USB_DSTS_COREIDLE(x)                     (((uint32_t)(((uint32_t)(x)) << USB_DSTS_COREIDLE_SHIFT)) & USB_DSTS_COREIDLE_MASK)

#define USB_DSTS_SSS_MASK                        (0x1000000U)
#define USB_DSTS_SSS_SHIFT                       (24U)
#define USB_DSTS_SSS(x)                          (((uint32_t)(((uint32_t)(x)) << USB_DSTS_SSS_SHIFT)) & USB_DSTS_SSS_MASK)

#define USB_DSTS_RSS_MASK                        (0x2000000U)
#define USB_DSTS_RSS_SHIFT                       (25U)
#define USB_DSTS_RSS(x)                          (((uint32_t)(((uint32_t)(x)) << USB_DSTS_RSS_SHIFT)) & USB_DSTS_RSS_MASK)

#define USB_DSTS_SRE_MASK                        (0x10000000U)
#define USB_DSTS_SRE_SHIFT                       (28U)
#define USB_DSTS_SRE(x)                          (((uint32_t)(((uint32_t)(x)) << USB_DSTS_SRE_SHIFT)) & USB_DSTS_SRE_MASK)

#define USB_DSTS_DCNRD_MASK                      (0x20000000U)
#define USB_DSTS_DCNRD_SHIFT                     (29U)
#define USB_DSTS_DCNRD(x)                        (((uint32_t)(((uint32_t)(x)) << USB_DSTS_DCNRD_SHIFT)) & USB_DSTS_DCNRD_MASK)
/*! @} */

/*! @name DGCMDPAR - Device Generic Command Parameter Register */
/*! @{ */

#define USB_DGCMDPAR_PARAMETER_MASK              (0xFFFFFFFFU)
#define USB_DGCMDPAR_PARAMETER_SHIFT             (0U)
#define USB_DGCMDPAR_PARAMETER(x)                (((uint32_t)(((uint32_t)(x)) << USB_DGCMDPAR_PARAMETER_SHIFT)) & USB_DGCMDPAR_PARAMETER_MASK)
/*! @} */

/*! @name DGCMD -  */
/*! @{ */

#define USB_DGCMD_CMDTYP_MASK                    (0xFFU)
#define USB_DGCMD_CMDTYP_SHIFT                   (0U)
#define USB_DGCMD_CMDTYP(x)                      (((uint32_t)(((uint32_t)(x)) << USB_DGCMD_CMDTYP_SHIFT)) & USB_DGCMD_CMDTYP_MASK)

#define USB_DGCMD_CMDIOC_MASK                    (0x100U)
#define USB_DGCMD_CMDIOC_SHIFT                   (8U)
#define USB_DGCMD_CMDIOC(x)                      (((uint32_t)(((uint32_t)(x)) << USB_DGCMD_CMDIOC_SHIFT)) & USB_DGCMD_CMDIOC_MASK)

#define USB_DGCMD_CMDACT_MASK                    (0x400U)
#define USB_DGCMD_CMDACT_SHIFT                   (10U)
#define USB_DGCMD_CMDACT(x)                      (((uint32_t)(((uint32_t)(x)) << USB_DGCMD_CMDACT_SHIFT)) & USB_DGCMD_CMDACT_MASK)

#define USB_DGCMD_CMDSTATUS_MASK                 (0xF000U)
#define USB_DGCMD_CMDSTATUS_SHIFT                (12U)
#define USB_DGCMD_CMDSTATUS(x)                   (((uint32_t)(((uint32_t)(x)) << USB_DGCMD_CMDSTATUS_SHIFT)) & USB_DGCMD_CMDSTATUS_MASK)
/*! @} */

/*! @name DALEPENA - Device Active USB Endpoint Enable Register */
/*! @{ */

#define USB_DALEPENA_USBACTEP_MASK               (0xFFFFFFFFU)
#define USB_DALEPENA_USBACTEP_SHIFT              (0U)
#define USB_DALEPENA_USBACTEP(x)                 (((uint32_t)(((uint32_t)(x)) << USB_DALEPENA_USBACTEP_SHIFT)) & USB_DALEPENA_USBACTEP_MASK)
/*! @} */

/*! @name DEPCMDPAR2 - Device physical endpoint-n command parameter 2 register */
/*! @{ */

#define USB_DEPCMDPAR2_PARAMETER_MASK            (0xFFFFFFFFU)
#define USB_DEPCMDPAR2_PARAMETER_SHIFT           (0U)
#define USB_DEPCMDPAR2_PARAMETER(x)              (((uint32_t)(((uint32_t)(x)) << USB_DEPCMDPAR2_PARAMETER_SHIFT)) & USB_DEPCMDPAR2_PARAMETER_MASK)
/*! @} */

/*! @name DEPCMDPAR1 - Device Physical Endpoint-n Command Parameter 1 Register */
/*! @{ */

#define USB_DEPCMDPAR1_PARAMETER_MASK            (0xFFFFFFFFU)
#define USB_DEPCMDPAR1_PARAMETER_SHIFT           (0U)
#define USB_DEPCMDPAR1_PARAMETER(x)              (((uint32_t)(((uint32_t)(x)) << USB_DEPCMDPAR1_PARAMETER_SHIFT)) & USB_DEPCMDPAR1_PARAMETER_MASK)
/*! @} */

/*! @name DEPCMDPAR0 - Device Physical Endpoint-n Command Parameter 0 Register */
/*! @{ */

#define USB_DEPCMDPAR0_PARAMETER_MASK            (0xFFFFFFFFU)
#define USB_DEPCMDPAR0_PARAMETER_SHIFT           (0U)
#define USB_DEPCMDPAR0_PARAMETER(x)              (((uint32_t)(((uint32_t)(x)) << USB_DEPCMDPAR0_PARAMETER_SHIFT)) & USB_DEPCMDPAR0_PARAMETER_MASK)
/*! @} */

/*! @name DEPCMD - Device Physical Endpoint-n Command Register */
/*! @{ */

#define USB_DEPCMD_CMDTYP_MASK                   (0xFU)
#define USB_DEPCMD_CMDTYP_SHIFT                  (0U)
#define USB_DEPCMD_CMDTYP(x)                     (((uint32_t)(((uint32_t)(x)) << USB_DEPCMD_CMDTYP_SHIFT)) & USB_DEPCMD_CMDTYP_MASK)

#define USB_DEPCMD_CMDIOC_MASK                   (0x100U)
#define USB_DEPCMD_CMDIOC_SHIFT                  (8U)
#define USB_DEPCMD_CMDIOC(x)                     (((uint32_t)(((uint32_t)(x)) << USB_DEPCMD_CMDIOC_SHIFT)) & USB_DEPCMD_CMDIOC_MASK)

#define USB_DEPCMD_CMDACT_MASK                   (0x400U)
#define USB_DEPCMD_CMDACT_SHIFT                  (10U)
#define USB_DEPCMD_CMDACT(x)                     (((uint32_t)(((uint32_t)(x)) << USB_DEPCMD_CMDACT_SHIFT)) & USB_DEPCMD_CMDACT_MASK)

#define USB_DEPCMD_HIPRI_FORCERM_MASK            (0x800U)
#define USB_DEPCMD_HIPRI_FORCERM_SHIFT           (11U)
#define USB_DEPCMD_HIPRI_FORCERM(x)              (((uint32_t)(((uint32_t)(x)) << USB_DEPCMD_HIPRI_FORCERM_SHIFT)) & USB_DEPCMD_HIPRI_FORCERM_MASK)

#define USB_DEPCMD_CMDSTATUS_MASK                (0xF000U)
#define USB_DEPCMD_CMDSTATUS_SHIFT               (12U)
#define USB_DEPCMD_CMDSTATUS(x)                  (((uint32_t)(((uint32_t)(x)) << USB_DEPCMD_CMDSTATUS_SHIFT)) & USB_DEPCMD_CMDSTATUS_MASK)

#define USB_DEPCMD_COMMANDPARAM_MASK             (0xFFFF0000U)
#define USB_DEPCMD_COMMANDPARAM_SHIFT            (16U)
#define USB_DEPCMD_COMMANDPARAM(x)               (((uint32_t)(((uint32_t)(x)) << USB_DEPCMD_COMMANDPARAM_SHIFT)) & USB_DEPCMD_COMMANDPARAM_MASK)
/*! @} */

/*! @name DEV_IMOD - Device Interrupt Moderation Register */
/*! @{ */

#define USB_DEV_IMOD_DEVICE_IMODI_MASK           (0xFFFFU)
#define USB_DEV_IMOD_DEVICE_IMODI_SHIFT          (0U)
#define USB_DEV_IMOD_DEVICE_IMODI(x)             (((uint32_t)(((uint32_t)(x)) << USB_DEV_IMOD_DEVICE_IMODI_SHIFT)) & USB_DEV_IMOD_DEVICE_IMODI_MASK)

#define USB_DEV_IMOD_DEVICE_IMODC_MASK           (0xFFFF0000U)
#define USB_DEV_IMOD_DEVICE_IMODC_SHIFT          (16U)
#define USB_DEV_IMOD_DEVICE_IMODC(x)             (((uint32_t)(((uint32_t)(x)) << USB_DEV_IMOD_DEVICE_IMODC_SHIFT)) & USB_DEV_IMOD_DEVICE_IMODC_MASK)
/*! @} */

/*! @name BCFG - BCFG */
/*! @{ */

#define USB_BCFG_CHIRP_EN_MASK                   (0x1U)
#define USB_BCFG_CHIRP_EN_SHIFT                  (0U)
#define USB_BCFG_CHIRP_EN(x)                     (((uint32_t)(((uint32_t)(x)) << USB_BCFG_CHIRP_EN_SHIFT)) & USB_BCFG_CHIRP_EN_MASK)

#define USB_BCFG_IDDIG_SEL_MASK                  (0x2U)
#define USB_BCFG_IDDIG_SEL_SHIFT                 (1U)
#define USB_BCFG_IDDIG_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << USB_BCFG_IDDIG_SEL_SHIFT)) & USB_BCFG_IDDIG_SEL_MASK)
/*! @} */

/*! @name BCEVT - BCEVT */
/*! @{ */

#define USB_BCEVT_MULTVALIDBC_MASK               (0x1FU)
#define USB_BCEVT_MULTVALIDBC_SHIFT              (0U)
#define USB_BCEVT_MULTVALIDBC(x)                 (((uint32_t)(((uint32_t)(x)) << USB_BCEVT_MULTVALIDBC_SHIFT)) & USB_BCEVT_MULTVALIDBC_MASK)

#define USB_BCEVT_MV_CHNGEVNT_MASK               (0x1000000U)
#define USB_BCEVT_MV_CHNGEVNT_SHIFT              (24U)
#define USB_BCEVT_MV_CHNGEVNT(x)                 (((uint32_t)(((uint32_t)(x)) << USB_BCEVT_MV_CHNGEVNT_SHIFT)) & USB_BCEVT_MV_CHNGEVNT_MASK)
/*! @} */

/*! @name BCEVTEN - BCEVTEN */
/*! @{ */

#define USB_BCEVTEN_MV_CHNGEVNTENA_MASK          (0x1000000U)
#define USB_BCEVTEN_MV_CHNGEVNTENA_SHIFT         (24U)
#define USB_BCEVTEN_MV_CHNGEVNTENA(x)            (((uint32_t)(((uint32_t)(x)) << USB_BCEVTEN_MV_CHNGEVNTENA_SHIFT)) & USB_BCEVTEN_MV_CHNGEVNTENA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USB_Register_Masks */


/*!
 * @}
 */ /* end of group USB_Peripheral_Access_Layer */


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


#endif  /* PERI_USB_H_ */

