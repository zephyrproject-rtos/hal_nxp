/*
** ###################################################################
**     Processors:          MCXC143VFM
**                          MCXC143VFT
**                          MCXC144VFM
**                          MCXC144VFT
**                          MCXC243VFT
**                          MCXC244VFM
**                          MCXC244VFT
**                          MCXC443VLH
**                          MCXC443VMP
**                          MCXC444VLH
**                          MCXC444VMP
**
**     Version:             rev. 2.0, 2024-10-29
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
**     - rev. 1.0 (2024-03-11)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_USB.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USB
 *
 * CMSIS Peripheral Access Layer for USB
 */

#if !defined(PERI_USB_H_)
#define PERI_USB_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC143VFM) || defined(CPU_MCXC143VFT))
#include "MCXC143_COMMON.h"
#elif (defined(CPU_MCXC144VFM) || defined(CPU_MCXC144VFT))
#include "MCXC144_COMMON.h"
#elif (defined(CPU_MCXC243VFT))
#include "MCXC243_COMMON.h"
#elif (defined(CPU_MCXC244VFM) || defined(CPU_MCXC244VFT))
#include "MCXC244_COMMON.h"
#elif (defined(CPU_MCXC443VLH) || defined(CPU_MCXC443VMP))
#include "MCXC443_COMMON.h"
#elif (defined(CPU_MCXC444VLH) || defined(CPU_MCXC444VMP))
#include "MCXC444_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
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
#define USB_ENDPOINT_COUNT                        16u

/** USB - Register Layout Typedef */
typedef struct {
  __I  uint8_t PERID;                              /**< Peripheral ID register, offset: 0x0 */
       uint8_t RESERVED_0[3];
  __I  uint8_t IDCOMP;                             /**< Peripheral ID Complement register, offset: 0x4 */
       uint8_t RESERVED_1[3];
  __I  uint8_t REV;                                /**< Peripheral Revision register, offset: 0x8 */
       uint8_t RESERVED_2[3];
  __I  uint8_t ADDINFO;                            /**< Peripheral Additional Info register, offset: 0xC */
       uint8_t RESERVED_3[115];
  __IO uint8_t ISTAT;                              /**< Interrupt Status register, offset: 0x80 */
       uint8_t RESERVED_4[3];
  __IO uint8_t INTEN;                              /**< Interrupt Enable register, offset: 0x84 */
       uint8_t RESERVED_5[3];
  __IO uint8_t ERRSTAT;                            /**< Error Interrupt Status register, offset: 0x88 */
       uint8_t RESERVED_6[3];
  __IO uint8_t ERREN;                              /**< Error Interrupt Enable register, offset: 0x8C */
       uint8_t RESERVED_7[3];
  __I  uint8_t STAT;                               /**< Status register, offset: 0x90 */
       uint8_t RESERVED_8[3];
  __IO uint8_t CTL;                                /**< Control register, offset: 0x94 */
       uint8_t RESERVED_9[3];
  __IO uint8_t ADDR;                               /**< Address register, offset: 0x98 */
       uint8_t RESERVED_10[3];
  __IO uint8_t BDTPAGE1;                           /**< BDT Page register 1, offset: 0x9C */
       uint8_t RESERVED_11[3];
  __IO uint8_t FRMNUML;                            /**< Frame Number register Low, offset: 0xA0 */
       uint8_t RESERVED_12[3];
  __IO uint8_t FRMNUMH;                            /**< Frame Number register High, offset: 0xA4 */
       uint8_t RESERVED_13[11];
  __IO uint8_t BDTPAGE2;                           /**< BDT Page Register 2, offset: 0xB0 */
       uint8_t RESERVED_14[3];
  __IO uint8_t BDTPAGE3;                           /**< BDT Page Register 3, offset: 0xB4 */
       uint8_t RESERVED_15[11];
  struct {                                         /* offset: 0xC0, array step: 0x4 */
    __IO uint8_t ENDPT;                              /**< Endpoint Control register, array offset: 0xC0, array step: 0x4 */
         uint8_t RESERVED_0[3];
  } ENDPOINT[USB_ENDPOINT_COUNT];
  __IO uint8_t USBCTRL;                            /**< USB Control register, offset: 0x100 */
       uint8_t RESERVED_16[3];
  __I  uint8_t OBSERVE;                            /**< USB OTG Observe register, offset: 0x104 */
       uint8_t RESERVED_17[3];
  __IO uint8_t CONTROL;                            /**< USB OTG Control register, offset: 0x108 */
       uint8_t RESERVED_18[3];
  __IO uint8_t USBTRC0;                            /**< USB Transceiver Control register 0, offset: 0x10C */
       uint8_t RESERVED_19[7];
  __IO uint8_t USBFRMADJUST;                       /**< Frame Adjust Register, offset: 0x114 */
       uint8_t RESERVED_20[43];
  __IO uint8_t CLK_RECOVER_CTRL;                   /**< USB Clock recovery control, offset: 0x140 */
       uint8_t RESERVED_21[3];
  __IO uint8_t CLK_RECOVER_IRC_EN;                 /**< IRC48M oscillator enable register, offset: 0x144 */
       uint8_t RESERVED_22[15];
  __IO uint8_t CLK_RECOVER_INT_EN;                 /**< Clock recovery combined interrupt enable, offset: 0x154 */
       uint8_t RESERVED_23[7];
  __IO uint8_t CLK_RECOVER_INT_STATUS;             /**< Clock recovery separated interrupt status, offset: 0x15C */
} USB_Type;

/* ----------------------------------------------------------------------------
   -- USB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Register_Masks USB Register Masks
 * @{
 */

/*! @name PERID - Peripheral ID register */
/*! @{ */

#define USB_PERID_ID_MASK                        (0x3FU)
#define USB_PERID_ID_SHIFT                       (0U)
/*! ID - Peripheral Identification */
#define USB_PERID_ID(x)                          (((uint8_t)(((uint8_t)(x)) << USB_PERID_ID_SHIFT)) & USB_PERID_ID_MASK)
/*! @} */

/*! @name IDCOMP - Peripheral ID Complement register */
/*! @{ */

#define USB_IDCOMP_NID_MASK                      (0x3FU)
#define USB_IDCOMP_NID_SHIFT                     (0U)
#define USB_IDCOMP_NID(x)                        (((uint8_t)(((uint8_t)(x)) << USB_IDCOMP_NID_SHIFT)) & USB_IDCOMP_NID_MASK)
/*! @} */

/*! @name REV - Peripheral Revision register */
/*! @{ */

#define USB_REV_REV_MASK                         (0xFFU)
#define USB_REV_REV_SHIFT                        (0U)
/*! REV - Revision */
#define USB_REV_REV(x)                           (((uint8_t)(((uint8_t)(x)) << USB_REV_REV_SHIFT)) & USB_REV_REV_MASK)
/*! @} */

/*! @name ADDINFO - Peripheral Additional Info register */
/*! @{ */

#define USB_ADDINFO_IEHOST_MASK                  (0x1U)
#define USB_ADDINFO_IEHOST_SHIFT                 (0U)
#define USB_ADDINFO_IEHOST(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ADDINFO_IEHOST_SHIFT)) & USB_ADDINFO_IEHOST_MASK)
/*! @} */

/*! @name ISTAT - Interrupt Status register */
/*! @{ */

#define USB_ISTAT_USBRST_MASK                    (0x1U)
#define USB_ISTAT_USBRST_SHIFT                   (0U)
#define USB_ISTAT_USBRST(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_USBRST_SHIFT)) & USB_ISTAT_USBRST_MASK)

#define USB_ISTAT_ERROR_MASK                     (0x2U)
#define USB_ISTAT_ERROR_SHIFT                    (1U)
#define USB_ISTAT_ERROR(x)                       (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_ERROR_SHIFT)) & USB_ISTAT_ERROR_MASK)

#define USB_ISTAT_SOFTOK_MASK                    (0x4U)
#define USB_ISTAT_SOFTOK_SHIFT                   (2U)
#define USB_ISTAT_SOFTOK(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_SOFTOK_SHIFT)) & USB_ISTAT_SOFTOK_MASK)

#define USB_ISTAT_TOKDNE_MASK                    (0x8U)
#define USB_ISTAT_TOKDNE_SHIFT                   (3U)
#define USB_ISTAT_TOKDNE(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_TOKDNE_SHIFT)) & USB_ISTAT_TOKDNE_MASK)

#define USB_ISTAT_SLEEP_MASK                     (0x10U)
#define USB_ISTAT_SLEEP_SHIFT                    (4U)
#define USB_ISTAT_SLEEP(x)                       (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_SLEEP_SHIFT)) & USB_ISTAT_SLEEP_MASK)

#define USB_ISTAT_RESUME_MASK                    (0x20U)
#define USB_ISTAT_RESUME_SHIFT                   (5U)
#define USB_ISTAT_RESUME(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_RESUME_SHIFT)) & USB_ISTAT_RESUME_MASK)

#define USB_ISTAT_STALL_MASK                     (0x80U)
#define USB_ISTAT_STALL_SHIFT                    (7U)
/*! STALL - Stall Interrupt */
#define USB_ISTAT_STALL(x)                       (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_STALL_SHIFT)) & USB_ISTAT_STALL_MASK)
/*! @} */

/*! @name INTEN - Interrupt Enable register */
/*! @{ */

#define USB_INTEN_USBRSTEN_MASK                  (0x1U)
#define USB_INTEN_USBRSTEN_SHIFT                 (0U)
/*! USBRSTEN - USBRST Interrupt Enable
 *  0b0..Disables the USBRST interrupt.
 *  0b1..Enables the USBRST interrupt.
 */
#define USB_INTEN_USBRSTEN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_INTEN_USBRSTEN_SHIFT)) & USB_INTEN_USBRSTEN_MASK)

#define USB_INTEN_ERROREN_MASK                   (0x2U)
#define USB_INTEN_ERROREN_SHIFT                  (1U)
/*! ERROREN - ERROR Interrupt Enable
 *  0b0..Disables the ERROR interrupt.
 *  0b1..Enables the ERROR interrupt.
 */
#define USB_INTEN_ERROREN(x)                     (((uint8_t)(((uint8_t)(x)) << USB_INTEN_ERROREN_SHIFT)) & USB_INTEN_ERROREN_MASK)

#define USB_INTEN_SOFTOKEN_MASK                  (0x4U)
#define USB_INTEN_SOFTOKEN_SHIFT                 (2U)
/*! SOFTOKEN - SOFTOK Interrupt Enable
 *  0b0..Disbles the SOFTOK interrupt.
 *  0b1..Enables the SOFTOK interrupt.
 */
#define USB_INTEN_SOFTOKEN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_INTEN_SOFTOKEN_SHIFT)) & USB_INTEN_SOFTOKEN_MASK)

#define USB_INTEN_TOKDNEEN_MASK                  (0x8U)
#define USB_INTEN_TOKDNEEN_SHIFT                 (3U)
/*! TOKDNEEN - TOKDNE Interrupt Enable
 *  0b0..Disables the TOKDNE interrupt.
 *  0b1..Enables the TOKDNE interrupt.
 */
#define USB_INTEN_TOKDNEEN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_INTEN_TOKDNEEN_SHIFT)) & USB_INTEN_TOKDNEEN_MASK)

#define USB_INTEN_SLEEPEN_MASK                   (0x10U)
#define USB_INTEN_SLEEPEN_SHIFT                  (4U)
/*! SLEEPEN - SLEEP Interrupt Enable
 *  0b0..Disables the SLEEP interrupt.
 *  0b1..Enables the SLEEP interrupt.
 */
#define USB_INTEN_SLEEPEN(x)                     (((uint8_t)(((uint8_t)(x)) << USB_INTEN_SLEEPEN_SHIFT)) & USB_INTEN_SLEEPEN_MASK)

#define USB_INTEN_RESUMEEN_MASK                  (0x20U)
#define USB_INTEN_RESUMEEN_SHIFT                 (5U)
/*! RESUMEEN - RESUME Interrupt Enable
 *  0b0..Disables the RESUME interrupt.
 *  0b1..Enables the RESUME interrupt.
 */
#define USB_INTEN_RESUMEEN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_INTEN_RESUMEEN_SHIFT)) & USB_INTEN_RESUMEEN_MASK)

#define USB_INTEN_STALLEN_MASK                   (0x80U)
#define USB_INTEN_STALLEN_SHIFT                  (7U)
/*! STALLEN - STALL Interrupt Enable
 *  0b0..Diasbles the STALL interrupt.
 *  0b1..Enables the STALL interrupt.
 */
#define USB_INTEN_STALLEN(x)                     (((uint8_t)(((uint8_t)(x)) << USB_INTEN_STALLEN_SHIFT)) & USB_INTEN_STALLEN_MASK)
/*! @} */

/*! @name ERRSTAT - Error Interrupt Status register */
/*! @{ */

#define USB_ERRSTAT_PIDERR_MASK                  (0x1U)
#define USB_ERRSTAT_PIDERR_SHIFT                 (0U)
#define USB_ERRSTAT_PIDERR(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_PIDERR_SHIFT)) & USB_ERRSTAT_PIDERR_MASK)

#define USB_ERRSTAT_CRC5_MASK                    (0x2U)
#define USB_ERRSTAT_CRC5_SHIFT                   (1U)
#define USB_ERRSTAT_CRC5(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_CRC5_SHIFT)) & USB_ERRSTAT_CRC5_MASK)

#define USB_ERRSTAT_CRC16_MASK                   (0x4U)
#define USB_ERRSTAT_CRC16_SHIFT                  (2U)
#define USB_ERRSTAT_CRC16(x)                     (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_CRC16_SHIFT)) & USB_ERRSTAT_CRC16_MASK)

#define USB_ERRSTAT_DFN8_MASK                    (0x8U)
#define USB_ERRSTAT_DFN8_SHIFT                   (3U)
#define USB_ERRSTAT_DFN8(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_DFN8_SHIFT)) & USB_ERRSTAT_DFN8_MASK)

#define USB_ERRSTAT_BTOERR_MASK                  (0x10U)
#define USB_ERRSTAT_BTOERR_SHIFT                 (4U)
#define USB_ERRSTAT_BTOERR(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_BTOERR_SHIFT)) & USB_ERRSTAT_BTOERR_MASK)

#define USB_ERRSTAT_DMAERR_MASK                  (0x20U)
#define USB_ERRSTAT_DMAERR_SHIFT                 (5U)
#define USB_ERRSTAT_DMAERR(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_DMAERR_SHIFT)) & USB_ERRSTAT_DMAERR_MASK)

#define USB_ERRSTAT_BTSERR_MASK                  (0x80U)
#define USB_ERRSTAT_BTSERR_SHIFT                 (7U)
#define USB_ERRSTAT_BTSERR(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_BTSERR_SHIFT)) & USB_ERRSTAT_BTSERR_MASK)
/*! @} */

/*! @name ERREN - Error Interrupt Enable register */
/*! @{ */

#define USB_ERREN_PIDERREN_MASK                  (0x1U)
#define USB_ERREN_PIDERREN_SHIFT                 (0U)
/*! PIDERREN - PIDERR Interrupt Enable
 *  0b0..Disables the PIDERR interrupt.
 *  0b1..Enters the PIDERR interrupt.
 */
#define USB_ERREN_PIDERREN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERREN_PIDERREN_SHIFT)) & USB_ERREN_PIDERREN_MASK)

#define USB_ERREN_CRC5EOFEN_MASK                 (0x2U)
#define USB_ERREN_CRC5EOFEN_SHIFT                (1U)
/*! CRC5EOFEN - CRC5/EOF Interrupt Enable
 *  0b0..Disables the CRC5/EOF interrupt.
 *  0b1..Enables the CRC5/EOF interrupt.
 */
#define USB_ERREN_CRC5EOFEN(x)                   (((uint8_t)(((uint8_t)(x)) << USB_ERREN_CRC5EOFEN_SHIFT)) & USB_ERREN_CRC5EOFEN_MASK)

#define USB_ERREN_CRC16EN_MASK                   (0x4U)
#define USB_ERREN_CRC16EN_SHIFT                  (2U)
/*! CRC16EN - CRC16 Interrupt Enable
 *  0b0..Disables the CRC16 interrupt.
 *  0b1..Enables the CRC16 interrupt.
 */
#define USB_ERREN_CRC16EN(x)                     (((uint8_t)(((uint8_t)(x)) << USB_ERREN_CRC16EN_SHIFT)) & USB_ERREN_CRC16EN_MASK)

#define USB_ERREN_DFN8EN_MASK                    (0x8U)
#define USB_ERREN_DFN8EN_SHIFT                   (3U)
/*! DFN8EN - DFN8 Interrupt Enable
 *  0b0..Disables the DFN8 interrupt.
 *  0b1..Enables the DFN8 interrupt.
 */
#define USB_ERREN_DFN8EN(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ERREN_DFN8EN_SHIFT)) & USB_ERREN_DFN8EN_MASK)

#define USB_ERREN_BTOERREN_MASK                  (0x10U)
#define USB_ERREN_BTOERREN_SHIFT                 (4U)
/*! BTOERREN - BTOERR Interrupt Enable
 *  0b0..Disables the BTOERR interrupt.
 *  0b1..Enables the BTOERR interrupt.
 */
#define USB_ERREN_BTOERREN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERREN_BTOERREN_SHIFT)) & USB_ERREN_BTOERREN_MASK)

#define USB_ERREN_DMAERREN_MASK                  (0x20U)
#define USB_ERREN_DMAERREN_SHIFT                 (5U)
/*! DMAERREN - DMAERR Interrupt Enable
 *  0b0..Disables the DMAERR interrupt.
 *  0b1..Enables the DMAERR interrupt.
 */
#define USB_ERREN_DMAERREN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERREN_DMAERREN_SHIFT)) & USB_ERREN_DMAERREN_MASK)

#define USB_ERREN_BTSERREN_MASK                  (0x80U)
#define USB_ERREN_BTSERREN_SHIFT                 (7U)
/*! BTSERREN - BTSERR Interrupt Enable
 *  0b0..Disables the BTSERR interrupt.
 *  0b1..Enables the BTSERR interrupt.
 */
#define USB_ERREN_BTSERREN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERREN_BTSERREN_SHIFT)) & USB_ERREN_BTSERREN_MASK)
/*! @} */

/*! @name STAT - Status register */
/*! @{ */

#define USB_STAT_ODD_MASK                        (0x4U)
#define USB_STAT_ODD_SHIFT                       (2U)
#define USB_STAT_ODD(x)                          (((uint8_t)(((uint8_t)(x)) << USB_STAT_ODD_SHIFT)) & USB_STAT_ODD_MASK)

#define USB_STAT_TX_MASK                         (0x8U)
#define USB_STAT_TX_SHIFT                        (3U)
/*! TX - Transmit Indicator
 *  0b0..The most recent transaction was a receive operation.
 *  0b1..The most recent transaction was a transmit operation.
 */
#define USB_STAT_TX(x)                           (((uint8_t)(((uint8_t)(x)) << USB_STAT_TX_SHIFT)) & USB_STAT_TX_MASK)

#define USB_STAT_ENDP_MASK                       (0xF0U)
#define USB_STAT_ENDP_SHIFT                      (4U)
#define USB_STAT_ENDP(x)                         (((uint8_t)(((uint8_t)(x)) << USB_STAT_ENDP_SHIFT)) & USB_STAT_ENDP_MASK)
/*! @} */

/*! @name CTL - Control register */
/*! @{ */

#define USB_CTL_USBENSOFEN_MASK                  (0x1U)
#define USB_CTL_USBENSOFEN_SHIFT                 (0U)
/*! USBENSOFEN - USB Enable
 *  0b0..Disables the USB Module.
 *  0b1..Enables the USB Module.
 */
#define USB_CTL_USBENSOFEN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_CTL_USBENSOFEN_SHIFT)) & USB_CTL_USBENSOFEN_MASK)

#define USB_CTL_ODDRST_MASK                      (0x2U)
#define USB_CTL_ODDRST_SHIFT                     (1U)
#define USB_CTL_ODDRST(x)                        (((uint8_t)(((uint8_t)(x)) << USB_CTL_ODDRST_SHIFT)) & USB_CTL_ODDRST_MASK)

#define USB_CTL_RESUME_MASK                      (0x4U)
#define USB_CTL_RESUME_SHIFT                     (2U)
#define USB_CTL_RESUME(x)                        (((uint8_t)(((uint8_t)(x)) << USB_CTL_RESUME_SHIFT)) & USB_CTL_RESUME_MASK)

#define USB_CTL_TXSUSPENDTOKENBUSY_MASK          (0x20U)
#define USB_CTL_TXSUSPENDTOKENBUSY_SHIFT         (5U)
#define USB_CTL_TXSUSPENDTOKENBUSY(x)            (((uint8_t)(((uint8_t)(x)) << USB_CTL_TXSUSPENDTOKENBUSY_SHIFT)) & USB_CTL_TXSUSPENDTOKENBUSY_MASK)

#define USB_CTL_SE0_MASK                         (0x40U)
#define USB_CTL_SE0_SHIFT                        (6U)
/*! SE0 - Live USB Single Ended Zero signal */
#define USB_CTL_SE0(x)                           (((uint8_t)(((uint8_t)(x)) << USB_CTL_SE0_SHIFT)) & USB_CTL_SE0_MASK)

#define USB_CTL_JSTATE_MASK                      (0x80U)
#define USB_CTL_JSTATE_SHIFT                     (7U)
/*! JSTATE - Live USB differential receiver JSTATE signal */
#define USB_CTL_JSTATE(x)                        (((uint8_t)(((uint8_t)(x)) << USB_CTL_JSTATE_SHIFT)) & USB_CTL_JSTATE_MASK)
/*! @} */

/*! @name ADDR - Address register */
/*! @{ */

#define USB_ADDR_ADDR_MASK                       (0x7FU)
#define USB_ADDR_ADDR_SHIFT                      (0U)
/*! ADDR - USB Address */
#define USB_ADDR_ADDR(x)                         (((uint8_t)(((uint8_t)(x)) << USB_ADDR_ADDR_SHIFT)) & USB_ADDR_ADDR_MASK)
/*! @} */

/*! @name BDTPAGE1 - BDT Page register 1 */
/*! @{ */

#define USB_BDTPAGE1_BDTBA_MASK                  (0xFEU)
#define USB_BDTPAGE1_BDTBA_SHIFT                 (1U)
#define USB_BDTPAGE1_BDTBA(x)                    (((uint8_t)(((uint8_t)(x)) << USB_BDTPAGE1_BDTBA_SHIFT)) & USB_BDTPAGE1_BDTBA_MASK)
/*! @} */

/*! @name FRMNUML - Frame Number register Low */
/*! @{ */

#define USB_FRMNUML_FRM_MASK                     (0xFFU)
#define USB_FRMNUML_FRM_SHIFT                    (0U)
#define USB_FRMNUML_FRM(x)                       (((uint8_t)(((uint8_t)(x)) << USB_FRMNUML_FRM_SHIFT)) & USB_FRMNUML_FRM_MASK)
/*! @} */

/*! @name FRMNUMH - Frame Number register High */
/*! @{ */

#define USB_FRMNUMH_FRM_MASK                     (0x7U)
#define USB_FRMNUMH_FRM_SHIFT                    (0U)
#define USB_FRMNUMH_FRM(x)                       (((uint8_t)(((uint8_t)(x)) << USB_FRMNUMH_FRM_SHIFT)) & USB_FRMNUMH_FRM_MASK)
/*! @} */

/*! @name BDTPAGE2 - BDT Page Register 2 */
/*! @{ */

#define USB_BDTPAGE2_BDTBA_MASK                  (0xFFU)
#define USB_BDTPAGE2_BDTBA_SHIFT                 (0U)
#define USB_BDTPAGE2_BDTBA(x)                    (((uint8_t)(((uint8_t)(x)) << USB_BDTPAGE2_BDTBA_SHIFT)) & USB_BDTPAGE2_BDTBA_MASK)
/*! @} */

/*! @name BDTPAGE3 - BDT Page Register 3 */
/*! @{ */

#define USB_BDTPAGE3_BDTBA_MASK                  (0xFFU)
#define USB_BDTPAGE3_BDTBA_SHIFT                 (0U)
#define USB_BDTPAGE3_BDTBA(x)                    (((uint8_t)(((uint8_t)(x)) << USB_BDTPAGE3_BDTBA_SHIFT)) & USB_BDTPAGE3_BDTBA_MASK)
/*! @} */

/*! @name ENDPT - Endpoint Control register */
/*! @{ */

#define USB_ENDPT_EPHSHK_MASK                    (0x1U)
#define USB_ENDPT_EPHSHK_SHIFT                   (0U)
#define USB_ENDPT_EPHSHK(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPHSHK_SHIFT)) & USB_ENDPT_EPHSHK_MASK)

#define USB_ENDPT_EPSTALL_MASK                   (0x2U)
#define USB_ENDPT_EPSTALL_SHIFT                  (1U)
#define USB_ENDPT_EPSTALL(x)                     (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPSTALL_SHIFT)) & USB_ENDPT_EPSTALL_MASK)

#define USB_ENDPT_EPTXEN_MASK                    (0x4U)
#define USB_ENDPT_EPTXEN_SHIFT                   (2U)
#define USB_ENDPT_EPTXEN(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPTXEN_SHIFT)) & USB_ENDPT_EPTXEN_MASK)

#define USB_ENDPT_EPRXEN_MASK                    (0x8U)
#define USB_ENDPT_EPRXEN_SHIFT                   (3U)
#define USB_ENDPT_EPRXEN(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPRXEN_SHIFT)) & USB_ENDPT_EPRXEN_MASK)

#define USB_ENDPT_EPCTLDIS_MASK                  (0x10U)
#define USB_ENDPT_EPCTLDIS_SHIFT                 (4U)
#define USB_ENDPT_EPCTLDIS(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPCTLDIS_SHIFT)) & USB_ENDPT_EPCTLDIS_MASK)
/*! @} */

/* The count of USB_ENDPT */
#define USB_ENDPT_COUNT                          (16U)

/*! @name USBCTRL - USB Control register */
/*! @{ */

#define USB_USBCTRL_PDE_MASK                     (0x40U)
#define USB_USBCTRL_PDE_SHIFT                    (6U)
/*! PDE
 *  0b0..Weak pulldowns are disabled on D+ and D-.
 *  0b1..Weak pulldowns are enabled on D+ and D-.
 */
#define USB_USBCTRL_PDE(x)                       (((uint8_t)(((uint8_t)(x)) << USB_USBCTRL_PDE_SHIFT)) & USB_USBCTRL_PDE_MASK)

#define USB_USBCTRL_SUSP_MASK                    (0x80U)
#define USB_USBCTRL_SUSP_SHIFT                   (7U)
/*! SUSP
 *  0b0..USB transceiver is not in suspend state.
 *  0b1..USB transceiver is in suspend state.
 */
#define USB_USBCTRL_SUSP(x)                      (((uint8_t)(((uint8_t)(x)) << USB_USBCTRL_SUSP_SHIFT)) & USB_USBCTRL_SUSP_MASK)
/*! @} */

/*! @name OBSERVE - USB OTG Observe register */
/*! @{ */

#define USB_OBSERVE_DMPD_MASK                    (0x10U)
#define USB_OBSERVE_DMPD_SHIFT                   (4U)
/*! DMPD
 *  0b0..D- pulldown disabled.
 *  0b1..D- pulldown enabled.
 */
#define USB_OBSERVE_DMPD(x)                      (((uint8_t)(((uint8_t)(x)) << USB_OBSERVE_DMPD_SHIFT)) & USB_OBSERVE_DMPD_MASK)

#define USB_OBSERVE_DPPD_MASK                    (0x40U)
#define USB_OBSERVE_DPPD_SHIFT                   (6U)
/*! DPPD
 *  0b0..D+ pulldown disabled.
 *  0b1..D+ pulldown enabled.
 */
#define USB_OBSERVE_DPPD(x)                      (((uint8_t)(((uint8_t)(x)) << USB_OBSERVE_DPPD_SHIFT)) & USB_OBSERVE_DPPD_MASK)

#define USB_OBSERVE_DPPU_MASK                    (0x80U)
#define USB_OBSERVE_DPPU_SHIFT                   (7U)
/*! DPPU
 *  0b0..D+ pullup disabled.
 *  0b1..D+ pullup enabled.
 */
#define USB_OBSERVE_DPPU(x)                      (((uint8_t)(((uint8_t)(x)) << USB_OBSERVE_DPPU_SHIFT)) & USB_OBSERVE_DPPU_MASK)
/*! @} */

/*! @name CONTROL - USB OTG Control register */
/*! @{ */

#define USB_CONTROL_DPPULLUPNONOTG_MASK          (0x10U)
#define USB_CONTROL_DPPULLUPNONOTG_SHIFT         (4U)
/*! DPPULLUPNONOTG
 *  0b0..DP Pullup in non-OTG device mode is not enabled.
 *  0b1..DP Pullup in non-OTG device mode is enabled.
 */
#define USB_CONTROL_DPPULLUPNONOTG(x)            (((uint8_t)(((uint8_t)(x)) << USB_CONTROL_DPPULLUPNONOTG_SHIFT)) & USB_CONTROL_DPPULLUPNONOTG_MASK)
/*! @} */

/*! @name USBTRC0 - USB Transceiver Control register 0 */
/*! @{ */

#define USB_USBTRC0_USB_RESUME_INT_MASK          (0x1U)
#define USB_USBTRC0_USB_RESUME_INT_SHIFT         (0U)
/*! USB_RESUME_INT - USB Asynchronous Interrupt
 *  0b0..No interrupt was generated.
 *  0b1..Interrupt was generated because of the USB asynchronous interrupt.
 */
#define USB_USBTRC0_USB_RESUME_INT(x)            (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_USB_RESUME_INT_SHIFT)) & USB_USBTRC0_USB_RESUME_INT_MASK)

#define USB_USBTRC0_SYNC_DET_MASK                (0x2U)
#define USB_USBTRC0_SYNC_DET_SHIFT               (1U)
/*! SYNC_DET - Synchronous USB Interrupt Detect
 *  0b0..Synchronous interrupt has not been detected.
 *  0b1..Synchronous interrupt has been detected.
 */
#define USB_USBTRC0_SYNC_DET(x)                  (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_SYNC_DET_SHIFT)) & USB_USBTRC0_SYNC_DET_MASK)

#define USB_USBTRC0_USB_CLK_RECOVERY_INT_MASK    (0x4U)
#define USB_USBTRC0_USB_CLK_RECOVERY_INT_SHIFT   (2U)
/*! USB_CLK_RECOVERY_INT - Combined USB Clock Recovery interrupt status */
#define USB_USBTRC0_USB_CLK_RECOVERY_INT(x)      (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_USB_CLK_RECOVERY_INT_SHIFT)) & USB_USBTRC0_USB_CLK_RECOVERY_INT_MASK)

#define USB_USBTRC0_USBRESMEN_MASK               (0x20U)
#define USB_USBTRC0_USBRESMEN_SHIFT              (5U)
/*! USBRESMEN - Asynchronous Resume Interrupt Enable
 *  0b0..USB asynchronous wakeup from suspend mode disabled.
 *  0b1..USB asynchronous wakeup from suspend mode enabled. The asynchronous resume interrupt differs from the
 *       synchronous resume interrupt in that it asynchronously detects K-state using the unfiltered state of the D+
 *       and D- pins. This interrupt should only be enabled when the Transceiver is suspended.
 */
#define USB_USBTRC0_USBRESMEN(x)                 (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_USBRESMEN_SHIFT)) & USB_USBTRC0_USBRESMEN_MASK)

#define USB_USBTRC0_USBRESET_MASK                (0x80U)
#define USB_USBTRC0_USBRESET_SHIFT               (7U)
/*! USBRESET - USB Reset
 *  0b0..Normal USB module operation.
 *  0b1..Returns the USB module to its reset state.
 */
#define USB_USBTRC0_USBRESET(x)                  (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_USBRESET_SHIFT)) & USB_USBTRC0_USBRESET_MASK)
/*! @} */

/*! @name USBFRMADJUST - Frame Adjust Register */
/*! @{ */

#define USB_USBFRMADJUST_ADJ_MASK                (0xFFU)
#define USB_USBFRMADJUST_ADJ_SHIFT               (0U)
/*! ADJ - Frame Adjustment */
#define USB_USBFRMADJUST_ADJ(x)                  (((uint8_t)(((uint8_t)(x)) << USB_USBFRMADJUST_ADJ_SHIFT)) & USB_USBFRMADJUST_ADJ_MASK)
/*! @} */

/*! @name CLK_RECOVER_CTRL - USB Clock recovery control */
/*! @{ */

#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK (0x20U)
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT (5U)
/*! RESTART_IFRTRIM_EN - Restart from IFR trim value
 *  0b0..Trim fine adjustment always works based on the previous updated trim fine value (default)
 *  0b1..Trim fine restarts from the IFR trim value whenever bus_reset/bus_resume is detected or module enable is desasserted
 */
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN(x) (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT)) & USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK)

#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_MASK (0x40U)
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_SHIFT (6U)
/*! RESET_RESUME_ROUGH_EN - Reset/resume to rough phase enable
 *  0b0..Always works in tracking phase after the first time rough to track transition (default)
 *  0b1..Go back to rough stage whenever bus reset or bus resume occurs
 */
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN(x) (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_SHIFT)) & USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_MASK)

#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_MASK (0x80U)
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_SHIFT (7U)
/*! CLOCK_RECOVER_EN - Crystal-less USB enable
 *  0b0..Disable clock recovery block (default)
 *  0b1..Enable clock recovery block
 */
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN(x) (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_SHIFT)) & USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_MASK)
/*! @} */

/*! @name CLK_RECOVER_IRC_EN - IRC48M oscillator enable register */
/*! @{ */

#define USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK       (0x2U)
#define USB_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT      (1U)
/*! IRC_EN - IRC48M enable
 *  0b0..Disable the IRC48M module (default)
 *  0b1..Enable the IRC48M module
 */
#define USB_CLK_RECOVER_IRC_EN_IRC_EN(x)         (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT)) & USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK)
/*! @} */

/*! @name CLK_RECOVER_INT_EN - Clock recovery combined interrupt enable */
/*! @{ */

#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK (0x10U)
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT (4U)
/*! OVF_ERROR_EN
 *  0b0..The interrupt will be masked
 *  0b1..The interrupt will be enabled (default)
 */
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN(x)   (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT)) & USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK)
/*! @} */

/*! @name CLK_RECOVER_INT_STATUS - Clock recovery separated interrupt status */
/*! @{ */

#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_MASK (0x10U)
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_SHIFT (4U)
/*! OVF_ERROR
 *  0b0..No interrupt is reported
 *  0b1..Unmasked interrupt has been generated
 */
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR(x)  (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_SHIFT)) & USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_MASK)
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
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_USB_H_ */

