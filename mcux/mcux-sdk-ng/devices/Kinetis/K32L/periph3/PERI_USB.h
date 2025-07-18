/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2019-04-22)
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

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
       uint8_t RESERVED_3[15];
  __IO uint8_t OTGCTL;                             /**< OTG Control register, offset: 0x1C */
       uint8_t RESERVED_4[99];
  __IO uint8_t ISTAT;                              /**< Interrupt Status register, offset: 0x80 */
       uint8_t RESERVED_5[3];
  __IO uint8_t INTEN;                              /**< Interrupt Enable register, offset: 0x84 */
       uint8_t RESERVED_6[3];
  __IO uint8_t ERRSTAT;                            /**< Error Interrupt Status register, offset: 0x88 */
       uint8_t RESERVED_7[3];
  __IO uint8_t ERREN;                              /**< Error Interrupt Enable register, offset: 0x8C */
       uint8_t RESERVED_8[3];
  __I  uint8_t STAT;                               /**< Status register, offset: 0x90 */
       uint8_t RESERVED_9[3];
  __IO uint8_t CTL;                                /**< Control register, offset: 0x94 */
       uint8_t RESERVED_10[3];
  __IO uint8_t ADDR;                               /**< Address register, offset: 0x98 */
       uint8_t RESERVED_11[3];
  __IO uint8_t BDTPAGE1;                           /**< BDT Page register 1, offset: 0x9C */
       uint8_t RESERVED_12[3];
  __IO uint8_t FRMNUML;                            /**< Frame Number register Low, offset: 0xA0 */
       uint8_t RESERVED_13[3];
  __IO uint8_t FRMNUMH;                            /**< Frame Number register High, offset: 0xA4 */
       uint8_t RESERVED_14[11];
  __IO uint8_t BDTPAGE2;                           /**< BDT Page Register 2, offset: 0xB0 */
       uint8_t RESERVED_15[3];
  __IO uint8_t BDTPAGE3;                           /**< BDT Page Register 3, offset: 0xB4 */
       uint8_t RESERVED_16[11];
  struct {                                         /* offset: 0xC0, array step: 0x4 */
    __IO uint8_t ENDPT;                              /**< Endpoint Control register, array offset: 0xC0, array step: 0x4 */
         uint8_t RESERVED_0[3];
  } ENDPOINT[USB_ENDPOINT_COUNT];
  __IO uint8_t USBCTRL;                            /**< USB Control register, offset: 0x100 */
       uint8_t RESERVED_17[3];
  __I  uint8_t OBSERVE;                            /**< USB OTG Observe register, offset: 0x104 */
       uint8_t RESERVED_18[3];
  __IO uint8_t CONTROL;                            /**< USB OTG Control register, offset: 0x108 */
       uint8_t RESERVED_19[3];
  __IO uint8_t USBTRC0;                            /**< USB Transceiver Control register 0, offset: 0x10C */
       uint8_t RESERVED_20[23];
  __IO uint8_t KEEP_ALIVE_CTRL;                    /**< Keep Alive mode control, offset: 0x124 */
       uint8_t RESERVED_21[3];
  __IO uint8_t KEEP_ALIVE_WKCTRL;                  /**< Keep Alive mode wakeup control, offset: 0x128 */
       uint8_t RESERVED_22[3];
  __IO uint8_t MISCCTRL;                           /**< Miscellaneous Control register, offset: 0x12C */
       uint8_t RESERVED_23[3];
  __IO uint8_t STALL_IL_DIS;                       /**< Peripheral mode stall disable for endpoints 7 to 0 in IN direction, offset: 0x130 */
       uint8_t RESERVED_24[3];
  __IO uint8_t STALL_IH_DIS;                       /**< Peripheral mode stall disable for endpoints 15 to 8 in IN direction, offset: 0x134 */
       uint8_t RESERVED_25[3];
  __IO uint8_t STALL_OL_DIS;                       /**< Peripheral mode stall disable for endpoints 7 to 0 in OUT direction, offset: 0x138 */
       uint8_t RESERVED_26[3];
  __IO uint8_t STALL_OH_DIS;                       /**< Peripheral mode stall disable for endpoints 15 to 8 in OUT direction, offset: 0x13C */
       uint8_t RESERVED_27[3];
  __IO uint8_t CLK_RECOVER_CTRL;                   /**< USB Clock recovery control, offset: 0x140 */
       uint8_t RESERVED_28[3];
  __IO uint8_t CLK_RECOVER_IRC_EN;                 /**< IRC48MFIRC oscillator enable register, offset: 0x144 */
       uint8_t RESERVED_29[15];
  __IO uint8_t CLK_RECOVER_INT_EN;                 /**< Clock recovery combined interrupt enable, offset: 0x154 */
       uint8_t RESERVED_30[7];
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
/*! NID - NID */
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
/*! IEHOST - Host mode enable bit */
#define USB_ADDINFO_IEHOST(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ADDINFO_IEHOST_SHIFT)) & USB_ADDINFO_IEHOST_MASK)
/*! @} */

/*! @name OTGCTL - OTG Control register */
/*! @{ */

#define USB_OTGCTL_DPHIGH_MASK                   (0x80U)
#define USB_OTGCTL_DPHIGH_SHIFT                  (7U)
/*! DPHIGH - D+ Data Line pullup resistor enable
 *  0b0..D+ pullup resistor is not enabled
 *  0b1..D+ pullup resistor is enabled
 */
#define USB_OTGCTL_DPHIGH(x)                     (((uint8_t)(((uint8_t)(x)) << USB_OTGCTL_DPHIGH_SHIFT)) & USB_OTGCTL_DPHIGH_MASK)
/*! @} */

/*! @name ISTAT - Interrupt Status register */
/*! @{ */

#define USB_ISTAT_USBRST_MASK                    (0x1U)
#define USB_ISTAT_USBRST_SHIFT                   (0U)
/*! USBRST - USB Reset */
#define USB_ISTAT_USBRST(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_USBRST_SHIFT)) & USB_ISTAT_USBRST_MASK)

#define USB_ISTAT_ERROR_MASK                     (0x2U)
#define USB_ISTAT_ERROR_SHIFT                    (1U)
/*! ERROR - Error */
#define USB_ISTAT_ERROR(x)                       (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_ERROR_SHIFT)) & USB_ISTAT_ERROR_MASK)

#define USB_ISTAT_SOFTOK_MASK                    (0x4U)
#define USB_ISTAT_SOFTOK_SHIFT                   (2U)
/*! SOFTOK - Start Of Frame (SOF) token */
#define USB_ISTAT_SOFTOK(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_SOFTOK_SHIFT)) & USB_ISTAT_SOFTOK_MASK)

#define USB_ISTAT_TOKDNE_MASK                    (0x8U)
#define USB_ISTAT_TOKDNE_SHIFT                   (3U)
/*! TOKDNE - Current token processing */
#define USB_ISTAT_TOKDNE(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_TOKDNE_SHIFT)) & USB_ISTAT_TOKDNE_MASK)

#define USB_ISTAT_SLEEP_MASK                     (0x10U)
#define USB_ISTAT_SLEEP_SHIFT                    (4U)
/*! SLEEP - Sleep */
#define USB_ISTAT_SLEEP(x)                       (((uint8_t)(((uint8_t)(x)) << USB_ISTAT_SLEEP_SHIFT)) & USB_ISTAT_SLEEP_MASK)

#define USB_ISTAT_RESUME_MASK                    (0x20U)
#define USB_ISTAT_RESUME_SHIFT                   (5U)
/*! RESUME - RESUME */
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
/*! PIDERR - PID error */
#define USB_ERRSTAT_PIDERR(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_PIDERR_SHIFT)) & USB_ERRSTAT_PIDERR_MASK)

#define USB_ERRSTAT_CRC5EOF_MASK                 (0x2U)
#define USB_ERRSTAT_CRC5EOF_SHIFT                (1U)
/*! CRC5EOF - CRC5 error or end of frame error */
#define USB_ERRSTAT_CRC5EOF(x)                   (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_CRC5EOF_SHIFT)) & USB_ERRSTAT_CRC5EOF_MASK)

#define USB_ERRSTAT_CRC16_MASK                   (0x4U)
#define USB_ERRSTAT_CRC16_SHIFT                  (2U)
/*! CRC16 - CRC16 error */
#define USB_ERRSTAT_CRC16(x)                     (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_CRC16_SHIFT)) & USB_ERRSTAT_CRC16_MASK)

#define USB_ERRSTAT_DFN8_MASK                    (0x8U)
#define USB_ERRSTAT_DFN8_SHIFT                   (3U)
/*! DFN8 - Data field not 8 bits (in length) */
#define USB_ERRSTAT_DFN8(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_DFN8_SHIFT)) & USB_ERRSTAT_DFN8_MASK)

#define USB_ERRSTAT_BTOERR_MASK                  (0x10U)
#define USB_ERRSTAT_BTOERR_SHIFT                 (4U)
/*! BTOERR - Bus turnaround timeout error */
#define USB_ERRSTAT_BTOERR(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_BTOERR_SHIFT)) & USB_ERRSTAT_BTOERR_MASK)

#define USB_ERRSTAT_DMAERR_MASK                  (0x20U)
#define USB_ERRSTAT_DMAERR_SHIFT                 (5U)
/*! DMAERR - DMAERR */
#define USB_ERRSTAT_DMAERR(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_DMAERR_SHIFT)) & USB_ERRSTAT_DMAERR_MASK)

#define USB_ERRSTAT_OWNERR_MASK                  (0x40U)
#define USB_ERRSTAT_OWNERR_SHIFT                 (6U)
/*! OWNERR - OWNERR */
#define USB_ERRSTAT_OWNERR(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERRSTAT_OWNERR_SHIFT)) & USB_ERRSTAT_OWNERR_MASK)

#define USB_ERRSTAT_BTSERR_MASK                  (0x80U)
#define USB_ERRSTAT_BTSERR_SHIFT                 (7U)
/*! BTSERR - Bit stuff error */
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

#define USB_ERREN_OWNERREN_MASK                  (0x40U)
#define USB_ERREN_OWNERREN_SHIFT                 (6U)
/*! OWNERREN - OWNERR Interrupt Enable
 *  0b0..Disables the OWNERR interrupt.
 *  0b1..Enables the OWNERR interrupt.
 */
#define USB_ERREN_OWNERREN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ERREN_OWNERREN_SHIFT)) & USB_ERREN_OWNERREN_MASK)

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
/*! ODD - Odd bank */
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
/*! ENDP - ENDP */
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
/*! ODDRST - ODDRST */
#define USB_CTL_ODDRST(x)                        (((uint8_t)(((uint8_t)(x)) << USB_CTL_ODDRST_SHIFT)) & USB_CTL_ODDRST_MASK)

#define USB_CTL_RESUME_MASK                      (0x4U)
#define USB_CTL_RESUME_SHIFT                     (2U)
/*! RESUME - Resume */
#define USB_CTL_RESUME(x)                        (((uint8_t)(((uint8_t)(x)) << USB_CTL_RESUME_SHIFT)) & USB_CTL_RESUME_MASK)

#define USB_CTL_HOSTMODEEN_MASK                  (0x8U)
#define USB_CTL_HOSTMODEEN_SHIFT                 (3U)
/*! HOSTMODEEN - Host mode enable
 *  0b0..USB Module operates in Device mode.
 *  0b1..USB Module operates in Host mode. In Host mode, the USB module performs USB transactions under the programmed control of the host processor.
 */
#define USB_CTL_HOSTMODEEN(x)                    (((uint8_t)(((uint8_t)(x)) << USB_CTL_HOSTMODEEN_SHIFT)) & USB_CTL_HOSTMODEEN_MASK)

#define USB_CTL_TXSUSPENDTOKENBUSY_MASK          (0x20U)
#define USB_CTL_TXSUSPENDTOKENBUSY_SHIFT         (5U)
/*! TXSUSPENDTOKENBUSY - TXSUSPEND or TOKENBUSY */
#define USB_CTL_TXSUSPENDTOKENBUSY(x)            (((uint8_t)(((uint8_t)(x)) << USB_CTL_TXSUSPENDTOKENBUSY_SHIFT)) & USB_CTL_TXSUSPENDTOKENBUSY_MASK)

#define USB_CTL_SE0_MASK                         (0x40U)
#define USB_CTL_SE0_SHIFT                        (6U)
/*! SE0 - Live USB Single-Ended Zero signal */
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
/*! BDTBA - BDTBA */
#define USB_BDTPAGE1_BDTBA(x)                    (((uint8_t)(((uint8_t)(x)) << USB_BDTPAGE1_BDTBA_SHIFT)) & USB_BDTPAGE1_BDTBA_MASK)
/*! @} */

/*! @name FRMNUML - Frame Number register Low */
/*! @{ */

#define USB_FRMNUML_FRM_MASK                     (0xFFU)
#define USB_FRMNUML_FRM_SHIFT                    (0U)
/*! FRM - FRM */
#define USB_FRMNUML_FRM(x)                       (((uint8_t)(((uint8_t)(x)) << USB_FRMNUML_FRM_SHIFT)) & USB_FRMNUML_FRM_MASK)
/*! @} */

/*! @name FRMNUMH - Frame Number register High */
/*! @{ */

#define USB_FRMNUMH_FRM_MASK                     (0x7U)
#define USB_FRMNUMH_FRM_SHIFT                    (0U)
/*! FRM - FRM */
#define USB_FRMNUMH_FRM(x)                       (((uint8_t)(((uint8_t)(x)) << USB_FRMNUMH_FRM_SHIFT)) & USB_FRMNUMH_FRM_MASK)
/*! @} */

/*! @name BDTPAGE2 - BDT Page Register 2 */
/*! @{ */

#define USB_BDTPAGE2_BDTBA_MASK                  (0xFFU)
#define USB_BDTPAGE2_BDTBA_SHIFT                 (0U)
/*! BDTBA - BDTBA */
#define USB_BDTPAGE2_BDTBA(x)                    (((uint8_t)(((uint8_t)(x)) << USB_BDTPAGE2_BDTBA_SHIFT)) & USB_BDTPAGE2_BDTBA_MASK)
/*! @} */

/*! @name BDTPAGE3 - BDT Page Register 3 */
/*! @{ */

#define USB_BDTPAGE3_BDTBA_MASK                  (0xFFU)
#define USB_BDTPAGE3_BDTBA_SHIFT                 (0U)
/*! BDTBA - BDTBA */
#define USB_BDTPAGE3_BDTBA(x)                    (((uint8_t)(((uint8_t)(x)) << USB_BDTPAGE3_BDTBA_SHIFT)) & USB_BDTPAGE3_BDTBA_MASK)
/*! @} */

/*! @name ENDPT - Endpoint Control register */
/*! @{ */

#define USB_ENDPT_EPHSHK_MASK                    (0x1U)
#define USB_ENDPT_EPHSHK_SHIFT                   (0U)
/*! EPHSHK - Endpoint handshaking enable */
#define USB_ENDPT_EPHSHK(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPHSHK_SHIFT)) & USB_ENDPT_EPHSHK_MASK)

#define USB_ENDPT_EPSTALL_MASK                   (0x2U)
#define USB_ENDPT_EPSTALL_SHIFT                  (1U)
/*! EPSTALL - Endpoint stalled */
#define USB_ENDPT_EPSTALL(x)                     (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPSTALL_SHIFT)) & USB_ENDPT_EPSTALL_MASK)

#define USB_ENDPT_EPTXEN_MASK                    (0x4U)
#define USB_ENDPT_EPTXEN_SHIFT                   (2U)
/*! EPTXEN - Endpoint for TX transfers enable */
#define USB_ENDPT_EPTXEN(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPTXEN_SHIFT)) & USB_ENDPT_EPTXEN_MASK)

#define USB_ENDPT_EPRXEN_MASK                    (0x8U)
#define USB_ENDPT_EPRXEN_SHIFT                   (3U)
/*! EPRXEN - Endpoint for RX transfers enable */
#define USB_ENDPT_EPRXEN(x)                      (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPRXEN_SHIFT)) & USB_ENDPT_EPRXEN_MASK)

#define USB_ENDPT_EPCTLDIS_MASK                  (0x10U)
#define USB_ENDPT_EPCTLDIS_SHIFT                 (4U)
/*! EPCTLDIS - Control (SETUP) transfer disable */
#define USB_ENDPT_EPCTLDIS(x)                    (((uint8_t)(((uint8_t)(x)) << USB_ENDPT_EPCTLDIS_SHIFT)) & USB_ENDPT_EPCTLDIS_MASK)
/*! @} */

/* The count of USB_ENDPT */
#define USB_ENDPT_COUNT                          (16U)

/*! @name USBCTRL - USB Control register */
/*! @{ */

#define USB_USBCTRL_UARTSEL_MASK                 (0x10U)
#define USB_USBCTRL_UARTSEL_SHIFT                (4U)
/*! UARTSEL - UART Select
 *  0b0..USB signals are not used as UART signals.
 *  0b1..USB signals are used as UART signals.
 */
#define USB_USBCTRL_UARTSEL(x)                   (((uint8_t)(((uint8_t)(x)) << USB_USBCTRL_UARTSEL_SHIFT)) & USB_USBCTRL_UARTSEL_MASK)

#define USB_USBCTRL_UARTCHLS_MASK                (0x20U)
#define USB_USBCTRL_UARTCHLS_SHIFT               (5U)
/*! UARTCHLS - UART Signal Channel Select
 *  0b0..USB DP/DM signals are used as UART TX/RX.
 *  0b1..USB DP/DM signals are used as UART RX/TX.
 */
#define USB_USBCTRL_UARTCHLS(x)                  (((uint8_t)(((uint8_t)(x)) << USB_USBCTRL_UARTCHLS_SHIFT)) & USB_USBCTRL_UARTCHLS_MASK)

#define USB_USBCTRL_PDE_MASK                     (0x40U)
#define USB_USBCTRL_PDE_SHIFT                    (6U)
/*! PDE - Pulldown enable
 *  0b0..Weak pulldowns are disabled on D+ and D-.
 *  0b1..Weak pulldowns are enabled on D+ and D-.
 */
#define USB_USBCTRL_PDE(x)                       (((uint8_t)(((uint8_t)(x)) << USB_USBCTRL_PDE_SHIFT)) & USB_USBCTRL_PDE_MASK)

#define USB_USBCTRL_SUSP_MASK                    (0x80U)
#define USB_USBCTRL_SUSP_SHIFT                   (7U)
/*! SUSP - Suspend
 *  0b0..USB transceiver is not in the Suspend state.
 *  0b1..USB transceiver is in the Suspend state.
 */
#define USB_USBCTRL_SUSP(x)                      (((uint8_t)(((uint8_t)(x)) << USB_USBCTRL_SUSP_SHIFT)) & USB_USBCTRL_SUSP_MASK)
/*! @} */

/*! @name OBSERVE - USB OTG Observe register */
/*! @{ */

#define USB_OBSERVE_DMPD_MASK                    (0x10U)
#define USB_OBSERVE_DMPD_SHIFT                   (4U)
/*! DMPD - DMPD
 *  0b0..D- pulldown is disabled.
 *  0b1..D- pulldown is enabled.
 */
#define USB_OBSERVE_DMPD(x)                      (((uint8_t)(((uint8_t)(x)) << USB_OBSERVE_DMPD_SHIFT)) & USB_OBSERVE_DMPD_MASK)

#define USB_OBSERVE_DPPD_MASK                    (0x40U)
#define USB_OBSERVE_DPPD_SHIFT                   (6U)
/*! DPPD - DPPD
 *  0b0..D+ pulldown is disabled.
 *  0b1..D+ pulldown is enabled.
 */
#define USB_OBSERVE_DPPD(x)                      (((uint8_t)(((uint8_t)(x)) << USB_OBSERVE_DPPD_SHIFT)) & USB_OBSERVE_DPPD_MASK)

#define USB_OBSERVE_DPPU_MASK                    (0x80U)
#define USB_OBSERVE_DPPU_SHIFT                   (7U)
/*! DPPU - DPPU
 *  0b0..D+ pullup disabled.
 *  0b1..D+ pullup enabled.
 */
#define USB_OBSERVE_DPPU(x)                      (((uint8_t)(((uint8_t)(x)) << USB_OBSERVE_DPPU_SHIFT)) & USB_OBSERVE_DPPU_MASK)
/*! @} */

/*! @name CONTROL - USB OTG Control register */
/*! @{ */

#define USB_CONTROL_DPPULLUPNONOTG_MASK          (0x10U)
#define USB_CONTROL_DPPULLUPNONOTG_SHIFT         (4U)
/*! DPPULLUPNONOTG - DPPULLUPNONOTG
 *  0b0..DP Pullup in non-OTG Device mode is not enabled.
 *  0b1..DP Pullup in non-OTG Device mode is enabled.
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

#define USB_USBTRC0_VREDG_DET_MASK               (0x8U)
#define USB_USBTRC0_VREDG_DET_SHIFT              (3U)
/*! VREDG_DET - VREGIN Rising Edge Interrupt Detect
 *  0b0..VREGIN rising edge interrupt has not been detected.
 *  0b1..VREGIN rising edge interrupt has been detected.
 */
#define USB_USBTRC0_VREDG_DET(x)                 (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_VREDG_DET_SHIFT)) & USB_USBTRC0_VREDG_DET_MASK)

#define USB_USBTRC0_VFEDG_DET_MASK               (0x10U)
#define USB_USBTRC0_VFEDG_DET_SHIFT              (4U)
/*! VFEDG_DET - VREGIN Falling Edge Interrupt Detect
 *  0b0..VREGIN falling edge interrupt has not been detected.
 *  0b1..VREGIN falling edge interrupt has been detected.
 */
#define USB_USBTRC0_VFEDG_DET(x)                 (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_VFEDG_DET_SHIFT)) & USB_USBTRC0_VFEDG_DET_MASK)

#define USB_USBTRC0_USBRESMEN_MASK               (0x20U)
#define USB_USBTRC0_USBRESMEN_SHIFT              (5U)
/*! USBRESMEN - Asynchronous Resume Interrupt Enable
 *  0b0..USB asynchronous wakeup from Suspend mode is disabled.
 *  0b1..USB asynchronous wakeup from Suspend mode is enabled.
 */
#define USB_USBTRC0_USBRESMEN(x)                 (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_USBRESMEN_SHIFT)) & USB_USBTRC0_USBRESMEN_MASK)

#define USB_USBTRC0_VREGIN_STS_MASK              (0x40U)
#define USB_USBTRC0_VREGIN_STS_SHIFT             (6U)
/*! VREGIN_STS - VREGIN_STS */
#define USB_USBTRC0_VREGIN_STS(x)                (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_VREGIN_STS_SHIFT)) & USB_USBTRC0_VREGIN_STS_MASK)

#define USB_USBTRC0_USBRESET_MASK                (0x80U)
#define USB_USBTRC0_USBRESET_SHIFT               (7U)
/*! USBRESET - USB Reset
 *  0b0..Normal USB module operation.
 *  0b1..Returns the USB module to its reset state.
 */
#define USB_USBTRC0_USBRESET(x)                  (((uint8_t)(((uint8_t)(x)) << USB_USBTRC0_USBRESET_SHIFT)) & USB_USBTRC0_USBRESET_MASK)
/*! @} */

/*! @name KEEP_ALIVE_CTRL - Keep Alive mode control */
/*! @{ */

#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_MASK   (0x1U)
#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_SHIFT  (0U)
/*! KEEP_ALIVE_EN - Keep Alive mode enable */
#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN(x)     (((uint8_t)(((uint8_t)(x)) << USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_SHIFT)) & USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_EN_MASK)

#define USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_MASK   (0x2U)
#define USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_SHIFT  (1U)
/*! OWN_OVERRD_EN - OWN bit override enable */
#define USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN(x)     (((uint8_t)(((uint8_t)(x)) << USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_SHIFT)) & USB_KEEP_ALIVE_CTRL_OWN_OVERRD_EN_MASK)

#define USB_KEEP_ALIVE_CTRL_STOP_ACK_DLY_EN_MASK (0x4U)
#define USB_KEEP_ALIVE_CTRL_STOP_ACK_DLY_EN_SHIFT (2U)
/*! STOP_ACK_DLY_EN - STOP_ACK_DLY_EN
 *  0b0..Enter KEEP_ALIVE mode until the USB core is idle and there is no USB AHB transfer.
 *  0b1..Enter KEEP_ALIVE mode immediately when there is no USB AHB transfer.
 */
#define USB_KEEP_ALIVE_CTRL_STOP_ACK_DLY_EN(x)   (((uint8_t)(((uint8_t)(x)) << USB_KEEP_ALIVE_CTRL_STOP_ACK_DLY_EN_SHIFT)) & USB_KEEP_ALIVE_CTRL_STOP_ACK_DLY_EN_MASK)

#define USB_KEEP_ALIVE_CTRL_WAKE_REQ_EN_MASK     (0x8U)
#define USB_KEEP_ALIVE_CTRL_WAKE_REQ_EN_SHIFT    (3U)
/*! WAKE_REQ_EN - WAKE_REQ_EN
 *  0b0..USB bus wakeup request is disabled
 *  0b1..USB bus wakeup request is enabled
 */
#define USB_KEEP_ALIVE_CTRL_WAKE_REQ_EN(x)       (((uint8_t)(((uint8_t)(x)) << USB_KEEP_ALIVE_CTRL_WAKE_REQ_EN_SHIFT)) & USB_KEEP_ALIVE_CTRL_WAKE_REQ_EN_MASK)

#define USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_MASK     (0x10U)
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_SHIFT    (4U)
/*! WAKE_INT_EN - Wakeup Interrupt Enable */
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_EN(x)       (((uint8_t)(((uint8_t)(x)) << USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_SHIFT)) & USB_KEEP_ALIVE_CTRL_WAKE_INT_EN_MASK)

#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_STS_MASK  (0x40U)
#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_STS_SHIFT (6U)
/*! KEEP_ALIVE_STS - Keep Alive Status
 *  0b0..USB is not in Keep Alive mode.
 *  0b1..USB is in Keep Alive mode.
 */
#define USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_STS(x)    (((uint8_t)(((uint8_t)(x)) << USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_STS_SHIFT)) & USB_KEEP_ALIVE_CTRL_KEEP_ALIVE_STS_MASK)

#define USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_MASK    (0x80U)
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_SHIFT   (7U)
/*! WAKE_INT_STS - Wakeup Interrupt Status */
#define USB_KEEP_ALIVE_CTRL_WAKE_INT_STS(x)      (((uint8_t)(((uint8_t)(x)) << USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_SHIFT)) & USB_KEEP_ALIVE_CTRL_WAKE_INT_STS_MASK)
/*! @} */

/*! @name KEEP_ALIVE_WKCTRL - Keep Alive mode wakeup control */
/*! @{ */

#define USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_MASK  (0xFU)
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_SHIFT (0U)
/*! WAKE_ON_THIS - WAKE_ON_THIS
 *  0b0001..Wake up after receiving OUT/SETUP token packet.
 *  0b1101..Wake up after receiving SETUP token packet. All other values are reserved.
 */
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS(x)    (((uint8_t)(((uint8_t)(x)) << USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_SHIFT)) & USB_KEEP_ALIVE_WKCTRL_WAKE_ON_THIS_MASK)

#define USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_MASK    (0xF0U)
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_SHIFT   (4U)
/*! WAKE_ENDPT - WAKE_ENDPT */
#define USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT(x)      (((uint8_t)(((uint8_t)(x)) << USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_SHIFT)) & USB_KEEP_ALIVE_WKCTRL_WAKE_ENDPT_MASK)
/*! @} */

/*! @name MISCCTRL - Miscellaneous Control register */
/*! @{ */

#define USB_MISCCTRL_SOFDYNTHLD_MASK             (0x1U)
#define USB_MISCCTRL_SOFDYNTHLD_SHIFT            (0U)
/*! SOFDYNTHLD - Dynamic SOF Threshold Compare mode
 *  0b0..SOF_TOK interrupt is set when byte times SOF threshold is reached.
 *  0b1..SOF_TOK interrupt is set when 8 byte times SOF threshold is reached or overstepped.
 */
#define USB_MISCCTRL_SOFDYNTHLD(x)               (((uint8_t)(((uint8_t)(x)) << USB_MISCCTRL_SOFDYNTHLD_SHIFT)) & USB_MISCCTRL_SOFDYNTHLD_MASK)

#define USB_MISCCTRL_SOFBUSSET_MASK              (0x2U)
#define USB_MISCCTRL_SOFBUSSET_SHIFT             (1U)
/*! SOFBUSSET - SOF_TOK Interrupt Generation Mode Select
 *  0b0..SOF_TOK interrupt is set according to SOF threshold value.
 *  0b1..SOF_TOK interrupt is set when SOF counter reaches 0.
 */
#define USB_MISCCTRL_SOFBUSSET(x)                (((uint8_t)(((uint8_t)(x)) << USB_MISCCTRL_SOFBUSSET_SHIFT)) & USB_MISCCTRL_SOFBUSSET_MASK)

#define USB_MISCCTRL_OWNERRISODIS_MASK           (0x4U)
#define USB_MISCCTRL_OWNERRISODIS_SHIFT          (2U)
/*! OWNERRISODIS - OWN Error Detect for ISO IN / ISO OUT Disable
 *  0b0..OWN error detect for ISO IN / ISO OUT is not disabled.
 *  0b1..OWN error detect for ISO IN / ISO OUT is disabled.
 */
#define USB_MISCCTRL_OWNERRISODIS(x)             (((uint8_t)(((uint8_t)(x)) << USB_MISCCTRL_OWNERRISODIS_SHIFT)) & USB_MISCCTRL_OWNERRISODIS_MASK)

#define USB_MISCCTRL_VREDG_EN_MASK               (0x8U)
#define USB_MISCCTRL_VREDG_EN_SHIFT              (3U)
/*! VREDG_EN - VREGIN Rising Edge Interrupt Enable
 *  0b0..VREGIN rising edge interrupt disabled.
 *  0b1..VREGIN rising edge interrupt enabled.
 */
#define USB_MISCCTRL_VREDG_EN(x)                 (((uint8_t)(((uint8_t)(x)) << USB_MISCCTRL_VREDG_EN_SHIFT)) & USB_MISCCTRL_VREDG_EN_MASK)

#define USB_MISCCTRL_VFEDG_EN_MASK               (0x10U)
#define USB_MISCCTRL_VFEDG_EN_SHIFT              (4U)
/*! VFEDG_EN - VREGIN Falling Edge Interrupt Enable
 *  0b0..VREGIN falling edge interrupt disabled.
 *  0b1..VREGIN falling edge interrupt enabled.
 */
#define USB_MISCCTRL_VFEDG_EN(x)                 (((uint8_t)(((uint8_t)(x)) << USB_MISCCTRL_VFEDG_EN_SHIFT)) & USB_MISCCTRL_VFEDG_EN_MASK)

#define USB_MISCCTRL_STL_ADJ_EN_MASK             (0x80U)
#define USB_MISCCTRL_STL_ADJ_EN_SHIFT            (7U)
/*! STL_ADJ_EN - USB Peripheral mode Stall Adjust Enable
 *  0b0..If USB_ENDPTn[END_STALL] = 1, both IN and OUT directions for the associated endpoint will be stalled
 *  0b1..If USB_ENDPTn[END_STALL] = 1, the USB_STALL_xx_DIS registers control which directions for the associated endpoint will be stalled.
 */
#define USB_MISCCTRL_STL_ADJ_EN(x)               (((uint8_t)(((uint8_t)(x)) << USB_MISCCTRL_STL_ADJ_EN_SHIFT)) & USB_MISCCTRL_STL_ADJ_EN_MASK)
/*! @} */

/*! @name STALL_IL_DIS - Peripheral mode stall disable for endpoints 7 to 0 in IN direction */
/*! @{ */

#define USB_STALL_IL_DIS_STALL_I_DIS0_MASK       (0x1U)
#define USB_STALL_IL_DIS_STALL_I_DIS0_SHIFT      (0U)
/*! STALL_I_DIS0 - STALL_I_DIS0
 *  0b0..Endpoint 0 IN direction stall is enabled.
 *  0b1..Endpoint 0 IN direction stall is disabled.
 */
#define USB_STALL_IL_DIS_STALL_I_DIS0(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS0_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS0_MASK)

#define USB_STALL_IL_DIS_STALL_I_DIS1_MASK       (0x2U)
#define USB_STALL_IL_DIS_STALL_I_DIS1_SHIFT      (1U)
/*! STALL_I_DIS1 - STALL_I_DIS1
 *  0b0..Endpoint 1 IN direction stall is enabled.
 *  0b1..Endpoint 1 IN direction stall is disabled.
 */
#define USB_STALL_IL_DIS_STALL_I_DIS1(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS1_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS1_MASK)

#define USB_STALL_IL_DIS_STALL_I_DIS2_MASK       (0x4U)
#define USB_STALL_IL_DIS_STALL_I_DIS2_SHIFT      (2U)
/*! STALL_I_DIS2 - STALL_I_DIS2
 *  0b0..Endpoint 2 IN direction stall is enabled.
 *  0b1..Endpoint 2 IN direction stall is disabled.
 */
#define USB_STALL_IL_DIS_STALL_I_DIS2(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS2_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS2_MASK)

#define USB_STALL_IL_DIS_STALL_I_DIS3_MASK       (0x8U)
#define USB_STALL_IL_DIS_STALL_I_DIS3_SHIFT      (3U)
/*! STALL_I_DIS3 - STALL_I_DIS3
 *  0b0..Endpoint 3 IN direction stall is enabled.
 *  0b1..Endpoint 3 IN direction stall is disabled.
 */
#define USB_STALL_IL_DIS_STALL_I_DIS3(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS3_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS3_MASK)

#define USB_STALL_IL_DIS_STALL_I_DIS4_MASK       (0x10U)
#define USB_STALL_IL_DIS_STALL_I_DIS4_SHIFT      (4U)
/*! STALL_I_DIS4 - STALL_I_DIS4
 *  0b0..Endpoint 4 IN direction stall is enabled.
 *  0b1..Endpoint 4 IN direction stall is disabled.
 */
#define USB_STALL_IL_DIS_STALL_I_DIS4(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS4_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS4_MASK)

#define USB_STALL_IL_DIS_STALL_I_DIS5_MASK       (0x20U)
#define USB_STALL_IL_DIS_STALL_I_DIS5_SHIFT      (5U)
/*! STALL_I_DIS5 - STALL_I_DIS5
 *  0b0..Endpoint 5 IN direction stall is enabled.
 *  0b1..Endpoint 5 IN direction stall is disabled.
 */
#define USB_STALL_IL_DIS_STALL_I_DIS5(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS5_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS5_MASK)

#define USB_STALL_IL_DIS_STALL_I_DIS6_MASK       (0x40U)
#define USB_STALL_IL_DIS_STALL_I_DIS6_SHIFT      (6U)
/*! STALL_I_DIS6 - STALL_I_DIS6
 *  0b0..Endpoint 6 IN direction stall is enabled.
 *  0b1..Endpoint 6 IN direction stall is disabled.
 */
#define USB_STALL_IL_DIS_STALL_I_DIS6(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS6_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS6_MASK)

#define USB_STALL_IL_DIS_STALL_I_DIS7_MASK       (0x80U)
#define USB_STALL_IL_DIS_STALL_I_DIS7_SHIFT      (7U)
/*! STALL_I_DIS7 - STALL_I_DIS7
 *  0b0..Endpoint 7 IN direction stall is enabled.
 *  0b1..Endpoint 7 IN direction stall is disabled.
 */
#define USB_STALL_IL_DIS_STALL_I_DIS7(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IL_DIS_STALL_I_DIS7_SHIFT)) & USB_STALL_IL_DIS_STALL_I_DIS7_MASK)
/*! @} */

/*! @name STALL_IH_DIS - Peripheral mode stall disable for endpoints 15 to 8 in IN direction */
/*! @{ */

#define USB_STALL_IH_DIS_STALL_I_DIS8_MASK       (0x1U)
#define USB_STALL_IH_DIS_STALL_I_DIS8_SHIFT      (0U)
/*! STALL_I_DIS8 - STALL_I_DIS8
 *  0b0..Endpoint 8 IN direction stall is enabled.
 *  0b1..Endpoint 8 IN direction stall is disabled.
 */
#define USB_STALL_IH_DIS_STALL_I_DIS8(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS8_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS8_MASK)

#define USB_STALL_IH_DIS_STALL_I_DIS9_MASK       (0x2U)
#define USB_STALL_IH_DIS_STALL_I_DIS9_SHIFT      (1U)
/*! STALL_I_DIS9 - STALL_I_DIS9
 *  0b0..Endpoint 9 IN direction stall is enabled.
 *  0b1..Endpoint 9 IN direction stall is disabled.
 */
#define USB_STALL_IH_DIS_STALL_I_DIS9(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS9_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS9_MASK)

#define USB_STALL_IH_DIS_STALL_I_DIS10_MASK      (0x4U)
#define USB_STALL_IH_DIS_STALL_I_DIS10_SHIFT     (2U)
/*! STALL_I_DIS10 - STALL_I_DIS10
 *  0b0..Endpoint 10 IN direction stall is enabled.
 *  0b1..Endpoint 10 IN direction stall is disabled.
 */
#define USB_STALL_IH_DIS_STALL_I_DIS10(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS10_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS10_MASK)

#define USB_STALL_IH_DIS_STALL_I_DIS11_MASK      (0x8U)
#define USB_STALL_IH_DIS_STALL_I_DIS11_SHIFT     (3U)
/*! STALL_I_DIS11 - STALL_I_DIS11
 *  0b0..Endpoint 11 IN direction stall is enabled.
 *  0b1..Endpoint 11 IN direction stall is disabled.
 */
#define USB_STALL_IH_DIS_STALL_I_DIS11(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS11_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS11_MASK)

#define USB_STALL_IH_DIS_STALL_I_DIS12_MASK      (0x10U)
#define USB_STALL_IH_DIS_STALL_I_DIS12_SHIFT     (4U)
/*! STALL_I_DIS12 - STALL_I_DIS12
 *  0b0..Endpoint 12 IN direction stall is enabled.
 *  0b1..Endpoint 12 IN direction stall is disabled.
 */
#define USB_STALL_IH_DIS_STALL_I_DIS12(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS12_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS12_MASK)

#define USB_STALL_IH_DIS_STALL_I_DIS13_MASK      (0x20U)
#define USB_STALL_IH_DIS_STALL_I_DIS13_SHIFT     (5U)
/*! STALL_I_DIS13 - STALL_I_DIS13
 *  0b0..Endpoint 13 IN direction stall is enabled.
 *  0b1..Endpoint 13 IN direction stall is disabled.
 */
#define USB_STALL_IH_DIS_STALL_I_DIS13(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS13_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS13_MASK)

#define USB_STALL_IH_DIS_STALL_I_DIS14_MASK      (0x40U)
#define USB_STALL_IH_DIS_STALL_I_DIS14_SHIFT     (6U)
/*! STALL_I_DIS14 - STALL_I_DIS14
 *  0b0..Endpoint 14 IN direction stall is enabled.
 *  0b1..Endpoint 14 IN direction stall is disabled.
 */
#define USB_STALL_IH_DIS_STALL_I_DIS14(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS14_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS14_MASK)

#define USB_STALL_IH_DIS_STALL_I_DIS15_MASK      (0x80U)
#define USB_STALL_IH_DIS_STALL_I_DIS15_SHIFT     (7U)
/*! STALL_I_DIS15 - STALL_I_DIS15
 *  0b0..Endpoint 15 IN direction stall is enabled.
 *  0b1..Endpoint 15 IN direction stall is disabled.
 */
#define USB_STALL_IH_DIS_STALL_I_DIS15(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_IH_DIS_STALL_I_DIS15_SHIFT)) & USB_STALL_IH_DIS_STALL_I_DIS15_MASK)
/*! @} */

/*! @name STALL_OL_DIS - Peripheral mode stall disable for endpoints 7 to 0 in OUT direction */
/*! @{ */

#define USB_STALL_OL_DIS_STALL_O_DIS0_MASK       (0x1U)
#define USB_STALL_OL_DIS_STALL_O_DIS0_SHIFT      (0U)
/*! STALL_O_DIS0 - STALL_O_DIS0
 *  0b0..Endpoint 0 OUT direction stall is enabled.
 *  0b1..Endpoint 0 OUT direction stall is disabled.
 */
#define USB_STALL_OL_DIS_STALL_O_DIS0(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS0_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS0_MASK)

#define USB_STALL_OL_DIS_STALL_O_DIS1_MASK       (0x2U)
#define USB_STALL_OL_DIS_STALL_O_DIS1_SHIFT      (1U)
/*! STALL_O_DIS1 - STALL_O_DIS1
 *  0b0..Endpoint 1 OUT direction stall is enabled.
 *  0b1..Endpoint 1 OUT direction stall is disabled.
 */
#define USB_STALL_OL_DIS_STALL_O_DIS1(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS1_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS1_MASK)

#define USB_STALL_OL_DIS_STALL_O_DIS2_MASK       (0x4U)
#define USB_STALL_OL_DIS_STALL_O_DIS2_SHIFT      (2U)
/*! STALL_O_DIS2 - STALL_O_DIS2
 *  0b0..Endpoint 2 OUT direction stall is enabled.
 *  0b1..Endpoint 2 OUT direction stall is disabled.
 */
#define USB_STALL_OL_DIS_STALL_O_DIS2(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS2_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS2_MASK)

#define USB_STALL_OL_DIS_STALL_O_DIS3_MASK       (0x8U)
#define USB_STALL_OL_DIS_STALL_O_DIS3_SHIFT      (3U)
/*! STALL_O_DIS3 - STALL_O_DIS3
 *  0b0..Endpoint 3 OUT direction stall is enabled.
 *  0b1..Endpoint 3 OUT direction stall is disabled.
 */
#define USB_STALL_OL_DIS_STALL_O_DIS3(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS3_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS3_MASK)

#define USB_STALL_OL_DIS_STALL_O_DIS4_MASK       (0x10U)
#define USB_STALL_OL_DIS_STALL_O_DIS4_SHIFT      (4U)
/*! STALL_O_DIS4 - STALL_O_DIS4
 *  0b0..Endpoint 4 OUT direction stall is enabled.
 *  0b1..Endpoint 4 OUT direction stall is disabled.
 */
#define USB_STALL_OL_DIS_STALL_O_DIS4(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS4_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS4_MASK)

#define USB_STALL_OL_DIS_STALL_O_DIS5_MASK       (0x20U)
#define USB_STALL_OL_DIS_STALL_O_DIS5_SHIFT      (5U)
/*! STALL_O_DIS5 - STALL_O_DIS5
 *  0b0..Endpoint 5 OUT direction stall is enabled.
 *  0b1..Endpoint 5 OUT direction stall is disabled.
 */
#define USB_STALL_OL_DIS_STALL_O_DIS5(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS5_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS5_MASK)

#define USB_STALL_OL_DIS_STALL_O_DIS6_MASK       (0x40U)
#define USB_STALL_OL_DIS_STALL_O_DIS6_SHIFT      (6U)
/*! STALL_O_DIS6 - STALL_O_DIS6
 *  0b0..Endpoint 6 OUT direction stall is enabled.
 *  0b1..Endpoint 6 OUT direction stall is disabled.
 */
#define USB_STALL_OL_DIS_STALL_O_DIS6(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS6_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS6_MASK)

#define USB_STALL_OL_DIS_STALL_O_DIS7_MASK       (0x80U)
#define USB_STALL_OL_DIS_STALL_O_DIS7_SHIFT      (7U)
/*! STALL_O_DIS7 - STALL_O_DIS7
 *  0b0..Endpoint 7 OUT direction stall is enabled.
 *  0b1..Endpoint 7 OUT direction stall is disabled.
 */
#define USB_STALL_OL_DIS_STALL_O_DIS7(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OL_DIS_STALL_O_DIS7_SHIFT)) & USB_STALL_OL_DIS_STALL_O_DIS7_MASK)
/*! @} */

/*! @name STALL_OH_DIS - Peripheral mode stall disable for endpoints 15 to 8 in OUT direction */
/*! @{ */

#define USB_STALL_OH_DIS_STALL_O_DIS8_MASK       (0x1U)
#define USB_STALL_OH_DIS_STALL_O_DIS8_SHIFT      (0U)
/*! STALL_O_DIS8 - STALL_O_DIS8
 *  0b0..Endpoint 8 OUT direction stall is enabled.
 *  0b1..Endpoint 8 OUT direction stall is disabled.
 */
#define USB_STALL_OH_DIS_STALL_O_DIS8(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS8_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS8_MASK)

#define USB_STALL_OH_DIS_STALL_O_DIS9_MASK       (0x2U)
#define USB_STALL_OH_DIS_STALL_O_DIS9_SHIFT      (1U)
/*! STALL_O_DIS9 - STALL_O_DIS9
 *  0b0..Endpoint 9 OUT direction stall is enabled.
 *  0b1..Endpoint 9 OUT direction stall is disabled.
 */
#define USB_STALL_OH_DIS_STALL_O_DIS9(x)         (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS9_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS9_MASK)

#define USB_STALL_OH_DIS_STALL_O_DIS10_MASK      (0x4U)
#define USB_STALL_OH_DIS_STALL_O_DIS10_SHIFT     (2U)
/*! STALL_O_DIS10 - STALL_O_DIS10
 *  0b0..Endpoint 10 OUT direction stall is enabled.
 *  0b1..Endpoint 10 OUT direction stall is disabled.
 */
#define USB_STALL_OH_DIS_STALL_O_DIS10(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS10_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS10_MASK)

#define USB_STALL_OH_DIS_STALL_O_DIS11_MASK      (0x8U)
#define USB_STALL_OH_DIS_STALL_O_DIS11_SHIFT     (3U)
/*! STALL_O_DIS11 - STALL_O_DIS11
 *  0b0..Endpoint 11 OUT direction stall is enabled.
 *  0b1..Endpoint 11 OUT direction stall is disabled.
 */
#define USB_STALL_OH_DIS_STALL_O_DIS11(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS11_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS11_MASK)

#define USB_STALL_OH_DIS_STALL_O_DIS12_MASK      (0x10U)
#define USB_STALL_OH_DIS_STALL_O_DIS12_SHIFT     (4U)
/*! STALL_O_DIS12 - STALL_O_DIS12
 *  0b0..Endpoint 12 OUT direction stall is enabled.
 *  0b1..Endpoint 12 OUT direction stall is disabled.
 */
#define USB_STALL_OH_DIS_STALL_O_DIS12(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS12_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS12_MASK)

#define USB_STALL_OH_DIS_STALL_O_DIS13_MASK      (0x20U)
#define USB_STALL_OH_DIS_STALL_O_DIS13_SHIFT     (5U)
/*! STALL_O_DIS13 - STALL_O_DIS13
 *  0b0..Endpoint 13 OUT direction stall is enabled.
 *  0b1..Endpoint 13 OUT direction stall is disabled.
 */
#define USB_STALL_OH_DIS_STALL_O_DIS13(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS13_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS13_MASK)

#define USB_STALL_OH_DIS_STALL_O_DIS14_MASK      (0x40U)
#define USB_STALL_OH_DIS_STALL_O_DIS14_SHIFT     (6U)
/*! STALL_O_DIS14 - STALL_O_DIS14
 *  0b0..Endpoint 14 OUT direction stall is enabled.
 *  0b1..Endpoint 14 OUT direction stall is disabled.
 */
#define USB_STALL_OH_DIS_STALL_O_DIS14(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS14_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS14_MASK)

#define USB_STALL_OH_DIS_STALL_O_DIS15_MASK      (0x80U)
#define USB_STALL_OH_DIS_STALL_O_DIS15_SHIFT     (7U)
/*! STALL_O_DIS15 - STALL_O_DIS15
 *  0b0..Endpoint 15 OUT direction stall is enabled.
 *  0b1..Endpoint 15 OUT direction stall is disabled.
 */
#define USB_STALL_OH_DIS_STALL_O_DIS15(x)        (((uint8_t)(((uint8_t)(x)) << USB_STALL_OH_DIS_STALL_O_DIS15_SHIFT)) & USB_STALL_OH_DIS_STALL_O_DIS15_MASK)
/*! @} */

/*! @name CLK_RECOVER_CTRL - USB Clock recovery control */
/*! @{ */

#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK (0x20U)
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT (5U)
/*! RESTART_IFRTRIM_EN - Restart from IFR trim value
 *  0b0..Trim fine adjustment always works based on the previous updated trim fine value (default).
 *  0b1..Trim fine restarts from the IFR trim value, whenever bus_reset/bus_resume is detected or module enable is desasserted.
 */
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN(x) (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT)) & USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK)

#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_MASK (0x40U)
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_SHIFT (6U)
/*! RESET_RESUME_ROUGH_EN - Reset/resume to rough phase enable
 *  0b0..Always works in tracking phase after the first time rough phase, to track transition (default).
 *  0b1..Go back to rough stage whenever a bus reset or bus resume occurs.
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

/*! @name CLK_RECOVER_IRC_EN - IRC48MFIRC oscillator enable register */
/*! @{ */

#define USB_CLK_RECOVER_IRC_EN_REG_EN_MASK       (0x1U)
#define USB_CLK_RECOVER_IRC_EN_REG_EN_SHIFT      (0U)
/*! REG_EN - Regulator enable
 *  0b0..IRC48M local regulator is disabled
 *  0b1..IRC48M local regulator is enabled (default)
 */
#define USB_CLK_RECOVER_IRC_EN_REG_EN(x)         (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_IRC_EN_REG_EN_SHIFT)) & USB_CLK_RECOVER_IRC_EN_REG_EN_MASK)

#define USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK       (0x2U)
#define USB_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT      (1U)
/*! IRC_EN - IRC_EN
 *  0b0..Disable the IRC48M module (default)
 *  0b1..Enable the IRC48M module
 */
#define USB_CLK_RECOVER_IRC_EN_IRC_EN(x)         (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT)) & USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK)
/*! @} */

/*! @name CLK_RECOVER_INT_EN - Clock recovery combined interrupt enable */
/*! @{ */

#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK (0x10U)
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT (4U)
/*! OVF_ERROR_EN - OVF_ERROR_EN
 *  0b0..The interrupt will be masked
 *  0b1..The interrupt will be enabled (default)
 */
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN(x)   (((uint8_t)(((uint8_t)(x)) << USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT)) & USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK)
/*! @} */

/*! @name CLK_RECOVER_INT_STATUS - Clock recovery separated interrupt status */
/*! @{ */

#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_MASK (0x10U)
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_SHIFT (4U)
/*! OVF_ERROR - OVF_ERROR
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

