/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for USBHSD
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_USBHSD.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBHSD
 *
 * CMSIS Peripheral Access Layer for USBHSD
 */

#if !defined(PERI_USBHSD_H_)
#define PERI_USBHSD_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
   -- USBHSD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBHSD_Peripheral_Access_Layer USBHSD Peripheral Access Layer
 * @{
 */

/** USBHSD - Register Layout Typedef */
typedef struct {
  __IO uint32_t DEVCMDSTAT;                        /**< USB Device Command/Status, offset: 0x0 */
  __IO uint32_t INFO;                              /**< USB Info, offset: 0x4 */
  __IO uint32_t EPLISTSTART;                       /**< USB EP Command/Status List Start Address, offset: 0x8 */
  __IO uint32_t DATABUFSTART;                      /**< USB Data Buffer List Start Address, offset: 0xC */
  __IO uint32_t LPM;                               /**< USB Link Power Management, offset: 0x10 */
  __IO uint32_t EPSKIP;                            /**< USB Endpoint Skip, offset: 0x14 */
  __IO uint32_t EPINUSE;                           /**< USB Endpoint Buffer in use, offset: 0x18 */
  __IO uint32_t EPBUFCFG;                          /**< USB Endpoint Buffer Configuration, offset: 0x1C */
  __IO uint32_t INTSTAT;                           /**< USB Interrupt Status, offset: 0x20 */
  __IO uint32_t INTEN;                             /**< USB Interrupt Enable, offset: 0x24 */
  __IO uint32_t INTSETSTAT;                        /**< USB Set Interrupt Status, offset: 0x28 */
       uint8_t RESERVED_0[8];
  __I  uint32_t EPTOGGLE;                          /**< USB Endpoint Toggle, offset: 0x34 */
} USBHSD_Type;

/* ----------------------------------------------------------------------------
   -- USBHSD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBHSD_Register_Masks USBHSD Register Masks
 * @{
 */

/*! @name DEVCMDSTAT - USB Device Command/Status */
/*! @{ */

#define USBHSD_DEVCMDSTAT_DEV_ADDR_MASK          (0x7FU)
#define USBHSD_DEVCMDSTAT_DEV_ADDR_SHIFT         (0U)
/*! DEV_ADDR - USB Device Address */
#define USBHSD_DEVCMDSTAT_DEV_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_DEV_ADDR_SHIFT)) & USBHSD_DEVCMDSTAT_DEV_ADDR_MASK)

#define USBHSD_DEVCMDSTAT_DEV_EN_MASK            (0x80U)
#define USBHSD_DEVCMDSTAT_DEV_EN_SHIFT           (7U)
/*! DEV_EN - USB device enable */
#define USBHSD_DEVCMDSTAT_DEV_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_DEV_EN_SHIFT)) & USBHSD_DEVCMDSTAT_DEV_EN_MASK)

#define USBHSD_DEVCMDSTAT_SETUP_MASK             (0x100U)
#define USBHSD_DEVCMDSTAT_SETUP_SHIFT            (8U)
/*! SETUP - SETUP token received. */
#define USBHSD_DEVCMDSTAT_SETUP(x)               (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_SETUP_SHIFT)) & USBHSD_DEVCMDSTAT_SETUP_MASK)

#define USBHSD_DEVCMDSTAT_FORCE_NEEDCLK_MASK     (0x200U)
#define USBHSD_DEVCMDSTAT_FORCE_NEEDCLK_SHIFT    (9U)
/*! FORCE_NEEDCLK - Force the NEEDCLK output to always be on.
 *  0b0..USB_NEEDCLK has normal function.
 *  0b1..USB_NEEDCLK always 1. Clock will not be stopped in case of suspend.
 */
#define USBHSD_DEVCMDSTAT_FORCE_NEEDCLK(x)       (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_FORCE_NEEDCLK_SHIFT)) & USBHSD_DEVCMDSTAT_FORCE_NEEDCLK_MASK)

#define USBHSD_DEVCMDSTAT_FORCE_VBUS_MASK        (0x400U)
#define USBHSD_DEVCMDSTAT_FORCE_VBUS_SHIFT       (10U)
/*! FORCE_VBUS - Force VBUS */
#define USBHSD_DEVCMDSTAT_FORCE_VBUS(x)          (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_FORCE_VBUS_SHIFT)) & USBHSD_DEVCMDSTAT_FORCE_VBUS_MASK)

#define USBHSD_DEVCMDSTAT_LPM_SUP_MASK           (0x800U)
#define USBHSD_DEVCMDSTAT_LPM_SUP_SHIFT          (11U)
/*! LPM_SUP - LPM Support
 *  0b0..LPM not supported.
 *  0b1..LPM supported.
 */
#define USBHSD_DEVCMDSTAT_LPM_SUP(x)             (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_LPM_SUP_SHIFT)) & USBHSD_DEVCMDSTAT_LPM_SUP_MASK)

#define USBHSD_DEVCMDSTAT_INTONNAK_AO_MASK       (0x1000U)
#define USBHSD_DEVCMDSTAT_INTONNAK_AO_SHIFT      (12U)
/*! INTONNAK_AO - Interrupt on NAK for interrupt and bulk OUT EP
 *  0b0..Only acknowledged packets generate an interrupt
 *  0b1..Both acknowledged and NAKed packets generate interrupts.
 */
#define USBHSD_DEVCMDSTAT_INTONNAK_AO(x)         (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_INTONNAK_AO_SHIFT)) & USBHSD_DEVCMDSTAT_INTONNAK_AO_MASK)

#define USBHSD_DEVCMDSTAT_INTONNAK_AI_MASK       (0x2000U)
#define USBHSD_DEVCMDSTAT_INTONNAK_AI_SHIFT      (13U)
/*! INTONNAK_AI - Interrupt on NAK for interrupt and bulk IN EP
 *  0b0..Only acknowledged packets generate an interrupt
 *  0b1..Both acknowledged and NAKed packets generate interrupts.
 */
#define USBHSD_DEVCMDSTAT_INTONNAK_AI(x)         (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_INTONNAK_AI_SHIFT)) & USBHSD_DEVCMDSTAT_INTONNAK_AI_MASK)

#define USBHSD_DEVCMDSTAT_INTONNAK_CO_MASK       (0x4000U)
#define USBHSD_DEVCMDSTAT_INTONNAK_CO_SHIFT      (14U)
/*! INTONNAK_CO - Interrupt on NAK for interrupt and bulk OUT EP
 *  0b0..Only acknowledged packets generate an interrupt
 *  0b1..Both acknowledged and NAKed packets generate interrupts.
 */
#define USBHSD_DEVCMDSTAT_INTONNAK_CO(x)         (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_INTONNAK_CO_SHIFT)) & USBHSD_DEVCMDSTAT_INTONNAK_CO_MASK)

#define USBHSD_DEVCMDSTAT_INTONNAK_CI_MASK       (0x8000U)
#define USBHSD_DEVCMDSTAT_INTONNAK_CI_SHIFT      (15U)
/*! INTONNAK_CI - Interrupt on NAK for interrupt and bulk OUT EP
 *  0b0..Only acknowledged packets generate an interrupt
 *  0b1..Both acknowledged and NAKed packets generate interrupts.
 */
#define USBHSD_DEVCMDSTAT_INTONNAK_CI(x)         (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_INTONNAK_CI_SHIFT)) & USBHSD_DEVCMDSTAT_INTONNAK_CI_MASK)

#define USBHSD_DEVCMDSTAT_DCON_MASK              (0x10000U)
#define USBHSD_DEVCMDSTAT_DCON_SHIFT             (16U)
/*! DCON - Device status - connect. */
#define USBHSD_DEVCMDSTAT_DCON(x)                (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_DCON_SHIFT)) & USBHSD_DEVCMDSTAT_DCON_MASK)

#define USBHSD_DEVCMDSTAT_DSUS_MASK              (0x20000U)
#define USBHSD_DEVCMDSTAT_DSUS_SHIFT             (17U)
/*! DSUS - Device status suspend.
 *  0b0..When the device is not connected or not suspended, a writing a 0 has no effect. Writing a 1 never has an effect.
 *  0b1..It is set to 1 when the device has not seen any activity on its upstream port for more than 3 ms. It is
 *       reset to 0 on any activity. When the device is suspended (Suspend bit DSUS = 1) and the software writes a 0
 *       to it, the device will generate a remote wake-up. This will only happen when the device is connected
 *       (Connect bit = 1).
 */
#define USBHSD_DEVCMDSTAT_DSUS(x)                (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_DSUS_SHIFT)) & USBHSD_DEVCMDSTAT_DSUS_MASK)

#define USBHSD_DEVCMDSTAT_LPM_SUS_MASK           (0x80000U)
#define USBHSD_DEVCMDSTAT_LPM_SUS_SHIFT          (19U)
/*! LPM_SUS - Device status - LPM Suspend.
 *  0b0..Software can only write a 0 to this bit when the LPM_REWP bit is set to 1. Hardware resets this bit when
 *       it receives a host initiated resume. Hardware only updates the LPM_SUS bit when the LPM_SUPP bit is equal
 *       to 1.
 *  0b1..When the device is in the LPM suspended state (LPM suspend bit = 1) and the software writes a 0 to this
 *       bit, the device will generate a remote walk-up.
 */
#define USBHSD_DEVCMDSTAT_LPM_SUS(x)             (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_LPM_SUS_SHIFT)) & USBHSD_DEVCMDSTAT_LPM_SUS_MASK)

#define USBHSD_DEVCMDSTAT_LPM_REWP_MASK          (0x100000U)
#define USBHSD_DEVCMDSTAT_LPM_REWP_SHIFT         (20U)
/*! LPM_REWP - LPM Remote Wake-up Enabled by USB host. */
#define USBHSD_DEVCMDSTAT_LPM_REWP(x)            (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_LPM_REWP_SHIFT)) & USBHSD_DEVCMDSTAT_LPM_REWP_MASK)

#define USBHSD_DEVCMDSTAT_SPEED_MASK             (0xC00000U)
#define USBHSD_DEVCMDSTAT_SPEED_SHIFT            (22U)
/*! SPEED - This field indicates the speed at which the device operates.
 *  0b00..Reserved
 *  0b01..Full-speed
 *  0b10..High-speed
 *  0b11..Reserved
 */
#define USBHSD_DEVCMDSTAT_SPEED(x)               (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_SPEED_SHIFT)) & USBHSD_DEVCMDSTAT_SPEED_MASK)

#define USBHSD_DEVCMDSTAT_DCON_C_MASK            (0x1000000U)
#define USBHSD_DEVCMDSTAT_DCON_C_SHIFT           (24U)
/*! DCON_C - Device status - connect change. */
#define USBHSD_DEVCMDSTAT_DCON_C(x)              (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_DCON_C_SHIFT)) & USBHSD_DEVCMDSTAT_DCON_C_MASK)

#define USBHSD_DEVCMDSTAT_DSUS_C_MASK            (0x2000000U)
#define USBHSD_DEVCMDSTAT_DSUS_C_SHIFT           (25U)
/*! DSUS_C - Device status - suspend change. */
#define USBHSD_DEVCMDSTAT_DSUS_C(x)              (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_DSUS_C_SHIFT)) & USBHSD_DEVCMDSTAT_DSUS_C_MASK)

#define USBHSD_DEVCMDSTAT_DRES_C_MASK            (0x4000000U)
#define USBHSD_DEVCMDSTAT_DRES_C_SHIFT           (26U)
/*! DRES_C - Device status - reset change. */
#define USBHSD_DEVCMDSTAT_DRES_C(x)              (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_DRES_C_SHIFT)) & USBHSD_DEVCMDSTAT_DRES_C_MASK)

#define USBHSD_DEVCMDSTAT_VBUS_DEBOUNCED_MASK    (0x10000000U)
#define USBHSD_DEVCMDSTAT_VBUS_DEBOUNCED_SHIFT   (28U)
/*! VBUS_DEBOUNCED - VBUS detect. */
#define USBHSD_DEVCMDSTAT_VBUS_DEBOUNCED(x)      (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_VBUS_DEBOUNCED_SHIFT)) & USBHSD_DEVCMDSTAT_VBUS_DEBOUNCED_MASK)

#define USBHSD_DEVCMDSTAT_PHY_TEST_MODE_MASK     (0xE0000000U)
#define USBHSD_DEVCMDSTAT_PHY_TEST_MODE_SHIFT    (29U)
/*! PHY_TEST_MODE - PHY test mode
 *  0b000..Test mode disabled
 *  0b001..Test_J
 *  0b010..Test_K
 *  0b011..Test_SE0_NAK
 *  0b100..Test_Packet
 *  0b101..Test_Force_Enable
 */
#define USBHSD_DEVCMDSTAT_PHY_TEST_MODE(x)       (((uint32_t)(((uint32_t)(x)) << USBHSD_DEVCMDSTAT_PHY_TEST_MODE_SHIFT)) & USBHSD_DEVCMDSTAT_PHY_TEST_MODE_MASK)
/*! @} */

/*! @name INFO - USB Info */
/*! @{ */

#define USBHSD_INFO_FRAME_NR_MASK                (0x7FFU)
#define USBHSD_INFO_FRAME_NR_SHIFT               (0U)
/*! FRAME_NR - Frame number. */
#define USBHSD_INFO_FRAME_NR(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSD_INFO_FRAME_NR_SHIFT)) & USBHSD_INFO_FRAME_NR_MASK)

#define USBHSD_INFO_ERR_CODE_MASK                (0x7800U)
#define USBHSD_INFO_ERR_CODE_SHIFT               (11U)
/*! ERR_CODE - The error code which last occurred */
#define USBHSD_INFO_ERR_CODE(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSD_INFO_ERR_CODE_SHIFT)) & USBHSD_INFO_ERR_CODE_MASK)

#define USBHSD_INFO_MINREV_MASK                  (0xFF0000U)
#define USBHSD_INFO_MINREV_SHIFT                 (16U)
/*! MINREV - Minor revision */
#define USBHSD_INFO_MINREV(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSD_INFO_MINREV_SHIFT)) & USBHSD_INFO_MINREV_MASK)

#define USBHSD_INFO_MAJREV_MASK                  (0xFF000000U)
#define USBHSD_INFO_MAJREV_SHIFT                 (24U)
/*! MAJREV - Major revision */
#define USBHSD_INFO_MAJREV(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSD_INFO_MAJREV_SHIFT)) & USBHSD_INFO_MAJREV_MASK)
/*! @} */

/*! @name EPLISTSTART - USB EP Command/Status List Start Address */
/*! @{ */

#define USBHSD_EPLISTSTART_EP_LIST_PRG_MASK      (0xFFF00U)
#define USBHSD_EPLISTSTART_EP_LIST_PRG_SHIFT     (8U)
#define USBHSD_EPLISTSTART_EP_LIST_PRG(x)        (((uint32_t)(((uint32_t)(x)) << USBHSD_EPLISTSTART_EP_LIST_PRG_SHIFT)) & USBHSD_EPLISTSTART_EP_LIST_PRG_MASK)

#define USBHSD_EPLISTSTART_EP_LIST_FIXED_MASK    (0xFFF00000U)
#define USBHSD_EPLISTSTART_EP_LIST_FIXED_SHIFT   (20U)
#define USBHSD_EPLISTSTART_EP_LIST_FIXED(x)      (((uint32_t)(((uint32_t)(x)) << USBHSD_EPLISTSTART_EP_LIST_FIXED_SHIFT)) & USBHSD_EPLISTSTART_EP_LIST_FIXED_MASK)
/*! @} */

/*! @name DATABUFSTART - USB Data Buffer List Start Address */
/*! @{ */

#define USBHSD_DATABUFSTART_DA_BUF_FIXED_MASK    (0x3FFFFU)
#define USBHSD_DATABUFSTART_DA_BUF_FIXED_SHIFT   (0U)
#define USBHSD_DATABUFSTART_DA_BUF_FIXED(x)      (((uint32_t)(((uint32_t)(x)) << USBHSD_DATABUFSTART_DA_BUF_FIXED_SHIFT)) & USBHSD_DATABUFSTART_DA_BUF_FIXED_MASK)

#define USBHSD_DATABUFSTART_DA_BUF_MASK          (0xFFFC0000U)
#define USBHSD_DATABUFSTART_DA_BUF_SHIFT         (18U)
#define USBHSD_DATABUFSTART_DA_BUF(x)            (((uint32_t)(((uint32_t)(x)) << USBHSD_DATABUFSTART_DA_BUF_SHIFT)) & USBHSD_DATABUFSTART_DA_BUF_MASK)
/*! @} */

/*! @name LPM - USB Link Power Management */
/*! @{ */

#define USBHSD_LPM_HIRD_HW_MASK                  (0xFU)
#define USBHSD_LPM_HIRD_HW_SHIFT                 (0U)
/*! HIRD_HW - Host Initiated Resume Duration - HW. */
#define USBHSD_LPM_HIRD_HW(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSD_LPM_HIRD_HW_SHIFT)) & USBHSD_LPM_HIRD_HW_MASK)

#define USBHSD_LPM_HIRD_SW_MASK                  (0xF0U)
#define USBHSD_LPM_HIRD_SW_SHIFT                 (4U)
/*! HIRD_SW - Host Initiated Resume Duration - SW. */
#define USBHSD_LPM_HIRD_SW(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSD_LPM_HIRD_SW_SHIFT)) & USBHSD_LPM_HIRD_SW_MASK)

#define USBHSD_LPM_DATA_PENDING_MASK             (0x100U)
#define USBHSD_LPM_DATA_PENDING_SHIFT            (8U)
/*! DATA_PENDING - Data pending */
#define USBHSD_LPM_DATA_PENDING(x)               (((uint32_t)(((uint32_t)(x)) << USBHSD_LPM_DATA_PENDING_SHIFT)) & USBHSD_LPM_DATA_PENDING_MASK)
/*! @} */

/*! @name EPSKIP - USB Endpoint Skip */
/*! @{ */

#define USBHSD_EPSKIP_SKIP_MASK                  (0xFFFU)
#define USBHSD_EPSKIP_SKIP_SHIFT                 (0U)
/*! SKIP - Endpoint skip. */
#define USBHSD_EPSKIP_SKIP(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSD_EPSKIP_SKIP_SHIFT)) & USBHSD_EPSKIP_SKIP_MASK)
/*! @} */

/*! @name EPINUSE - USB Endpoint Buffer in use */
/*! @{ */

#define USBHSD_EPINUSE_BUF_MASK                  (0xFFCU)
#define USBHSD_EPINUSE_BUF_SHIFT                 (2U)
/*! BUF - Buffer in use.
 *  0b0000000000..HW is accessing buffer 0.
 *  0b0000000001..HW is accessing buffer 1.
 */
#define USBHSD_EPINUSE_BUF(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSD_EPINUSE_BUF_SHIFT)) & USBHSD_EPINUSE_BUF_MASK)
/*! @} */

/*! @name EPBUFCFG - USB Endpoint Buffer Configuration */
/*! @{ */

#define USBHSD_EPBUFCFG_BUF_SB_MASK              (0xFFCU)
#define USBHSD_EPBUFCFG_BUF_SB_SHIFT             (2U)
/*! BUF_SB - Buffer in use.
 *  0b0000000000..Single buffer.
 *  0b0000000001..Double buffer.
 */
#define USBHSD_EPBUFCFG_BUF_SB(x)                (((uint32_t)(((uint32_t)(x)) << USBHSD_EPBUFCFG_BUF_SB_SHIFT)) & USBHSD_EPBUFCFG_BUF_SB_MASK)
/*! @} */

/*! @name INTSTAT - USB Interrupt Status */
/*! @{ */

#define USBHSD_INTSTAT_EP0OUT_MASK               (0x1U)
#define USBHSD_INTSTAT_EP0OUT_SHIFT              (0U)
/*! EP0OUT - Control EP0 OUT direction. */
#define USBHSD_INTSTAT_EP0OUT(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSTAT_EP0OUT_SHIFT)) & USBHSD_INTSTAT_EP0OUT_MASK)

#define USBHSD_INTSTAT_EP0IN_MASK                (0x2U)
#define USBHSD_INTSTAT_EP0IN_SHIFT               (1U)
/*! EP0IN - Control EP0 IN direction. */
#define USBHSD_INTSTAT_EP0IN(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSTAT_EP0IN_SHIFT)) & USBHSD_INTSTAT_EP0IN_MASK)

#define USBHSD_INTSTAT_EP1OUT_MASK               (0x4U)
#define USBHSD_INTSTAT_EP1OUT_SHIFT              (2U)
/*! EP1OUT - Control EP1 OUT direction. */
#define USBHSD_INTSTAT_EP1OUT(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSTAT_EP1OUT_SHIFT)) & USBHSD_INTSTAT_EP1OUT_MASK)

#define USBHSD_INTSTAT_EP1IN_MASK                (0x8U)
#define USBHSD_INTSTAT_EP1IN_SHIFT               (3U)
/*! EP1IN - Control EP1 IN direction. */
#define USBHSD_INTSTAT_EP1IN(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSTAT_EP1IN_SHIFT)) & USBHSD_INTSTAT_EP1IN_MASK)

#define USBHSD_INTSTAT_EP2OUT_MASK               (0x10U)
#define USBHSD_INTSTAT_EP2OUT_SHIFT              (4U)
/*! EP2OUT - Control EP2 OUT direction. */
#define USBHSD_INTSTAT_EP2OUT(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSTAT_EP2OUT_SHIFT)) & USBHSD_INTSTAT_EP2OUT_MASK)

#define USBHSD_INTSTAT_EP2IN_MASK                (0x20U)
#define USBHSD_INTSTAT_EP2IN_SHIFT               (5U)
/*! EP2IN - Control EP2 IN direction. */
#define USBHSD_INTSTAT_EP2IN(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSTAT_EP2IN_SHIFT)) & USBHSD_INTSTAT_EP2IN_MASK)

#define USBHSD_INTSTAT_EP3OUT_MASK               (0x40U)
#define USBHSD_INTSTAT_EP3OUT_SHIFT              (6U)
/*! EP3OUT - Control EP3 OUT direction. */
#define USBHSD_INTSTAT_EP3OUT(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSTAT_EP3OUT_SHIFT)) & USBHSD_INTSTAT_EP3OUT_MASK)

#define USBHSD_INTSTAT_EP3IN_MASK                (0x80U)
#define USBHSD_INTSTAT_EP3IN_SHIFT               (7U)
/*! EP3IN - Control EP3 IN direction. */
#define USBHSD_INTSTAT_EP3IN(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSTAT_EP3IN_SHIFT)) & USBHSD_INTSTAT_EP3IN_MASK)

#define USBHSD_INTSTAT_EP4OUT_MASK               (0x100U)
#define USBHSD_INTSTAT_EP4OUT_SHIFT              (8U)
/*! EP4OUT - Control EP4 OUT direction. */
#define USBHSD_INTSTAT_EP4OUT(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSTAT_EP4OUT_SHIFT)) & USBHSD_INTSTAT_EP4OUT_MASK)

#define USBHSD_INTSTAT_EP4IN_MASK                (0x200U)
#define USBHSD_INTSTAT_EP4IN_SHIFT               (9U)
/*! EP4IN - Control EP4 IN direction. */
#define USBHSD_INTSTAT_EP4IN(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSTAT_EP4IN_SHIFT)) & USBHSD_INTSTAT_EP4IN_MASK)

#define USBHSD_INTSTAT_EP5OUT_MASK               (0x400U)
#define USBHSD_INTSTAT_EP5OUT_SHIFT              (10U)
/*! EP5OUT - Control EP5 OUT direction. */
#define USBHSD_INTSTAT_EP5OUT(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSTAT_EP5OUT_SHIFT)) & USBHSD_INTSTAT_EP5OUT_MASK)

#define USBHSD_INTSTAT_EP5IN_MASK                (0x800U)
#define USBHSD_INTSTAT_EP5IN_SHIFT               (11U)
/*! EP5IN - Control EP5 IN direction. */
#define USBHSD_INTSTAT_EP5IN(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSTAT_EP5IN_SHIFT)) & USBHSD_INTSTAT_EP5IN_MASK)

#define USBHSD_INTSTAT_FRAME_INT_MASK            (0x40000000U)
#define USBHSD_INTSTAT_FRAME_INT_SHIFT           (30U)
/*! FRAME_INT - Frame interrupt. */
#define USBHSD_INTSTAT_FRAME_INT(x)              (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSTAT_FRAME_INT_SHIFT)) & USBHSD_INTSTAT_FRAME_INT_MASK)

#define USBHSD_INTSTAT_DEV_INT_MASK              (0x80000000U)
#define USBHSD_INTSTAT_DEV_INT_SHIFT             (31U)
/*! DEV_INT - Device status interrupt. */
#define USBHSD_INTSTAT_DEV_INT(x)                (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSTAT_DEV_INT_SHIFT)) & USBHSD_INTSTAT_DEV_INT_MASK)
/*! @} */

/*! @name INTEN - USB Interrupt Enable */
/*! @{ */

#define USBHSD_INTEN_EP_INT_EN_MASK              (0xFFFU)
#define USBHSD_INTEN_EP_INT_EN_SHIFT             (0U)
/*! EP_INT_EN - End Point Interrupt Enable. */
#define USBHSD_INTEN_EP_INT_EN(x)                (((uint32_t)(((uint32_t)(x)) << USBHSD_INTEN_EP_INT_EN_SHIFT)) & USBHSD_INTEN_EP_INT_EN_MASK)

#define USBHSD_INTEN_FRAME_INT_EN_MASK           (0x40000000U)
#define USBHSD_INTEN_FRAME_INT_EN_SHIFT          (30U)
/*! FRAME_INT_EN - Frame interrupt. */
#define USBHSD_INTEN_FRAME_INT_EN(x)             (((uint32_t)(((uint32_t)(x)) << USBHSD_INTEN_FRAME_INT_EN_SHIFT)) & USBHSD_INTEN_FRAME_INT_EN_MASK)

#define USBHSD_INTEN_DEV_INT_EN_MASK             (0x80000000U)
#define USBHSD_INTEN_DEV_INT_EN_SHIFT            (31U)
/*! DEV_INT_EN - Device status interrupt. */
#define USBHSD_INTEN_DEV_INT_EN(x)               (((uint32_t)(((uint32_t)(x)) << USBHSD_INTEN_DEV_INT_EN_SHIFT)) & USBHSD_INTEN_DEV_INT_EN_MASK)
/*! @} */

/*! @name INTSETSTAT - USB Set Interrupt Status */
/*! @{ */

#define USBHSD_INTSETSTAT_EP_SET_INT_MASK        (0xFFFU)
#define USBHSD_INTSETSTAT_EP_SET_INT_SHIFT       (0U)
/*! EP_SET_INT - End Point Set Interrupt Enable. */
#define USBHSD_INTSETSTAT_EP_SET_INT(x)          (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSETSTAT_EP_SET_INT_SHIFT)) & USBHSD_INTSETSTAT_EP_SET_INT_MASK)

#define USBHSD_INTSETSTAT_FRAME_SET_INT_MASK     (0x40000000U)
#define USBHSD_INTSETSTAT_FRAME_SET_INT_SHIFT    (30U)
/*! FRAME_SET_INT - Frame interrupt. */
#define USBHSD_INTSETSTAT_FRAME_SET_INT(x)       (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSETSTAT_FRAME_SET_INT_SHIFT)) & USBHSD_INTSETSTAT_FRAME_SET_INT_MASK)

#define USBHSD_INTSETSTAT_DEV_SET_INT_MASK       (0x80000000U)
#define USBHSD_INTSETSTAT_DEV_SET_INT_SHIFT      (31U)
/*! DEV_SET_INT - Device status interrupt. */
#define USBHSD_INTSETSTAT_DEV_SET_INT(x)         (((uint32_t)(((uint32_t)(x)) << USBHSD_INTSETSTAT_DEV_SET_INT_SHIFT)) & USBHSD_INTSETSTAT_DEV_SET_INT_MASK)
/*! @} */

/*! @name EPTOGGLE - USB Endpoint Toggle */
/*! @{ */

#define USBHSD_EPTOGGLE_TOGGLE_MASK              (0x3FFFFFFFU)
#define USBHSD_EPTOGGLE_TOGGLE_SHIFT             (0U)
/*! TOGGLE - Endpoint data toggle. */
#define USBHSD_EPTOGGLE_TOGGLE(x)                (((uint32_t)(((uint32_t)(x)) << USBHSD_EPTOGGLE_TOGGLE_SHIFT)) & USBHSD_EPTOGGLE_TOGGLE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBHSD_Register_Masks */

/* Backward compatibility */
#define USBHSD_DEVCMDSTAT_Speed_MASK (USBHSD_DEVCMDSTAT_SPEED_MASK)
#define USBHSD_DEVCMDSTAT_Speed_SHIFT (USBHSD_DEVCMDSTAT_SPEED_SHIFT)
#define USBHSD_DEVCMDSTAT_Speed(x) (USBHSD_DEVCMDSTAT_SPEED(x))


/*!
 * @}
 */ /* end of group USBHSD_Peripheral_Access_Layer */


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


#endif  /* PERI_USBHSD_H_ */

