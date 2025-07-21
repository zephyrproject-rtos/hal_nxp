/*
** ###################################################################
**     Processors:          MIMXRT633SFAWBR
**                          MIMXRT633SFFOB
**                          MIMXRT633SFVKB
**                          MIMXRT685SFAWBR_cm33
**                          MIMXRT685SFAWBR_dsp
**                          MIMXRT685SFFOB_cm33
**                          MIMXRT685SFFOB_dsp
**                          MIMXRT685SFVKB_cm33
**                          MIMXRT685SFVKB_dsp
**                          MIMXRT685SVFVKB_cm33
**                          MIMXRT685SVFVKB_dsp
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DMA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-06-19)
**         Initial version.
**     - rev. 2.0 (2019-11-12)
**         Base on rev 0.95 RM (B0 Header)
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DMA.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DMA
 *
 * CMSIS Peripheral Access Layer for DMA
 */

#if !defined(PERI_DMA_H_)
#define PERI_DMA_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT633SFAWBR) || defined(CPU_MIMXRT633SFFOB) || defined(CPU_MIMXRT633SFVKB))
#include "MIMXRT633S_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_cm33) || defined(CPU_MIMXRT685SFFOB_cm33) || defined(CPU_MIMXRT685SFVKB_cm33) || defined(CPU_MIMXRT685SVFVKB_cm33))
#include "MIMXRT685S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_dsp) || defined(CPU_MIMXRT685SFFOB_dsp) || defined(CPU_MIMXRT685SFVKB_dsp) || defined(CPU_MIMXRT685SVFVKB_dsp))
#include "MIMXRT685S_dsp_COMMON.h"
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
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Size of Registers Arrays */
#define DMA_COMMON_COUNT                          1u
#define DMA_CHANNEL_COUNT                         33u

/** DMA - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< DMA control., offset: 0x0 */
  __I  uint32_t INTSTAT;                           /**< Interrupt status., offset: 0x4 */
  __IO uint32_t SRAMBASE;                          /**< SRAM address of the channel configuration table., offset: 0x8 */
       uint8_t RESERVED_0[20];
  struct {                                         /* offset: 0x20, array step: 0x60 */
    __IO uint32_t ENABLESET;                         /**< Channel Enable read and Set for all DMA channels., array offset: 0x20, array step: 0x60 */
    __IO uint32_t ENABLESET1;                        /**< Channel Enable read and Set for all DMA channels., array offset: 0x24, array step: 0x60 */
    __O  uint32_t ENABLECLR;                         /**< Channel Enable Clear for all DMA channels., array offset: 0x28, array step: 0x60 */
    __O  uint32_t ENABLECLR1;                        /**< Channel Enable Clear for all DMA channels., array offset: 0x2C, array step: 0x60 */
    __I  uint32_t ACTIVE;                            /**< Channel Active status for all DMA channels., array offset: 0x30, array step: 0x60 */
    __I  uint32_t ACTIVE1;                           /**< Channel Active status for all DMA channels., array offset: 0x34, array step: 0x60 */
    __I  uint32_t BUSY;                              /**< Channel Busy status for all DMA channels., array offset: 0x38, array step: 0x60 */
    __I  uint32_t BUSY1;                             /**< Channel Busy status for all DMA channels., array offset: 0x3C, array step: 0x60 */
    __IO uint32_t ERRINT;                            /**< Error Interrupt status for all DMA channels., array offset: 0x40, array step: 0x60 */
    __IO uint32_t ERRINT1;                           /**< Error Interrupt status for all DMA channels., array offset: 0x44, array step: 0x60 */
    __IO uint32_t INTENSET;                          /**< Interrupt Enable read and Set for all DMA channels., array offset: 0x48, array step: 0x60 */
    __IO uint32_t INTENSET1;                         /**< Interrupt Enable read and Set for all DMA channels., array offset: 0x4C, array step: 0x60 */
    __O  uint32_t INTENCLR;                          /**< Interrupt Enable Clear for all DMA channels., array offset: 0x50, array step: 0x60 */
    __O  uint32_t INTENCLR1;                         /**< Interrupt Enable Clear for all DMA channels., array offset: 0x54, array step: 0x60 */
    __IO uint32_t INTA;                              /**< Interrupt A status for all DMA channels., array offset: 0x58, array step: 0x60 */
    __IO uint32_t INTA1;                             /**< Interrupt A status for all DMA channels., array offset: 0x5C, array step: 0x60 */
    __IO uint32_t INTB;                              /**< Interrupt B status for all DMA channels., array offset: 0x60, array step: 0x60 */
    __IO uint32_t INTB1;                             /**< Interrupt B status for all DMA channels., array offset: 0x64, array step: 0x60 */
    __O  uint32_t SETVALID;                          /**< Set ValidPending control bits for all DMA channels., array offset: 0x68, array step: 0x60 */
    __O  uint32_t SETVALID1;                         /**< Set ValidPending control bits for all DMA channels., array offset: 0x6C, array step: 0x60 */
    __O  uint32_t SETTRIG;                           /**< Set Trigger control bits for all DMA channels., array offset: 0x70, array step: 0x60 */
    __O  uint32_t SETTRIG1;                          /**< Set Trigger control bits for all DMA channels., array offset: 0x74, array step: 0x60 */
    __O  uint32_t ABORT;                             /**< Channel Abort control for all DMA channels., array offset: 0x78, array step: 0x60 */
    __O  uint32_t ABORT1;                            /**< Channel Abort control for all DMA channels., array offset: 0x7C, array step: 0x60 */
  } COMMON[DMA_COMMON_COUNT];
       uint8_t RESERVED_1[896];
  struct {                                         /* offset: 0x400, array step: 0x10 */
    __IO uint32_t CFG;                               /**< Configuration register for DMA channel ., array offset: 0x400, array step: 0x10 */
    __I  uint32_t CTLSTAT;                           /**< Control and status register for DMA channel ., array offset: 0x404, array step: 0x10 */
    __IO uint32_t XFERCFG;                           /**< Transfer configuration register for DMA channel ., array offset: 0x408, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } CHANNEL[DMA_CHANNEL_COUNT];
} DMA_Type;

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/*! @name CTRL - DMA control. */
/*! @{ */

#define DMA_CTRL_ENABLE_MASK                     (0x1U)
#define DMA_CTRL_ENABLE_SHIFT                    (0U)
/*! ENABLE - DMA controller master enable.
 *  0b0..Disabled. The DMA controller is disabled. This clears any triggers that were asserted at the point when
 *       disabled, but does not prevent re-triggering when the DMA controller is re-enabled.
 *  0b1..Enabled. The DMA controller is enabled.
 */
#define DMA_CTRL_ENABLE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CTRL_ENABLE_SHIFT)) & DMA_CTRL_ENABLE_MASK)
/*! @} */

/*! @name INTSTAT - Interrupt status. */
/*! @{ */

#define DMA_INTSTAT_ACTIVEINT_MASK               (0x2U)
#define DMA_INTSTAT_ACTIVEINT_SHIFT              (1U)
/*! ACTIVEINT - Summarizes whether any enabled interrupts (other than error interrupts) are pending.
 *  0b0..Not pending. No enabled interrupts are pending.
 *  0b1..Pending. At least one enabled interrupt is pending.
 */
#define DMA_INTSTAT_ACTIVEINT(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_INTSTAT_ACTIVEINT_SHIFT)) & DMA_INTSTAT_ACTIVEINT_MASK)

#define DMA_INTSTAT_ACTIVEERRINT_MASK            (0x4U)
#define DMA_INTSTAT_ACTIVEERRINT_SHIFT           (2U)
/*! ACTIVEERRINT - Summarizes whether any error interrupts are pending.
 *  0b0..Not pending. No error interrupts are pending.
 *  0b1..Pending. At least one error interrupt is pending.
 */
#define DMA_INTSTAT_ACTIVEERRINT(x)              (((uint32_t)(((uint32_t)(x)) << DMA_INTSTAT_ACTIVEERRINT_SHIFT)) & DMA_INTSTAT_ACTIVEERRINT_MASK)
/*! @} */

/*! @name SRAMBASE - SRAM address of the channel configuration table. */
/*! @{ */

#define DMA_SRAMBASE_OFFSET_MASK                 (0xFFFFFE00U)
#define DMA_SRAMBASE_OFFSET_SHIFT                (9U)
/*! OFFSET - Address bits 31:9 of the beginning of the DMA descriptor table. For 18 channels, the
 *    table must begin on a 512 byte boundary.
 */
#define DMA_SRAMBASE_OFFSET(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_SRAMBASE_OFFSET_SHIFT)) & DMA_SRAMBASE_OFFSET_MASK)
/*! @} */

/*! @name COMMON_ENABLESET - Channel Enable read and Set for all DMA channels. */
/*! @{ */

#define DMA_COMMON_ENABLESET_ENA_MASK            (0xFFFFFFFFU)
#define DMA_COMMON_ENABLESET_ENA_SHIFT           (0U)
/*! ENA - Enable for DMA channel 0
 *  0b00000000000000000000000000000000..DMAchannel 0 is disabled.
 *  0b00000000000000000000000000000001..DMAchannel 0 is enabled.
 */
#define DMA_COMMON_ENABLESET_ENA(x)              (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_ENABLESET_ENA_SHIFT)) & DMA_COMMON_ENABLESET_ENA_MASK)
/*! @} */

/* The count of DMA_COMMON_ENABLESET */
#define DMA_COMMON_ENABLESET_COUNT               (1U)

/*! @name COMMON_ENABLESET1 - Channel Enable read and Set for all DMA channels. */
/*! @{ */

#define DMA_COMMON_ENABLESET1_ENABLE32_MASK      (0x1U)
#define DMA_COMMON_ENABLESET1_ENABLE32_SHIFT     (0U)
/*! ENABLE32 - Enable for DMA channel 32
 *  0b0..DMAchannel 32 is disabled.
 *  0b1..DMAchannel 32 is enabled.
 */
#define DMA_COMMON_ENABLESET1_ENABLE32(x)        (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_ENABLESET1_ENABLE32_SHIFT)) & DMA_COMMON_ENABLESET1_ENABLE32_MASK)

#define DMA_COMMON_ENABLESET1_ENABLE63_33_MASK   (0xFFFFFFFEU)
#define DMA_COMMON_ENABLESET1_ENABLE63_33_SHIFT  (1U)
/*! ENABLE63_33 - Additional enables for remaining DMA channels in the range 63 to 33.
 *  0b0000000000000000000000000000000..The relevant DMA channel is disabled.
 *  0b0000000000000000000000000000001..The relevant DMA channel is enabled.
 */
#define DMA_COMMON_ENABLESET1_ENABLE63_33(x)     (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_ENABLESET1_ENABLE63_33_SHIFT)) & DMA_COMMON_ENABLESET1_ENABLE63_33_MASK)
/*! @} */

/* The count of DMA_COMMON_ENABLESET1 */
#define DMA_COMMON_ENABLESET1_COUNT              (1U)

/*! @name COMMON_ENABLECLR - Channel Enable Clear for all DMA channels. */
/*! @{ */

#define DMA_COMMON_ENABLECLR_CLR_MASK            (0xFFFFFFFFU)
#define DMA_COMMON_ENABLECLR_CLR_SHIFT           (0U)
/*! CLR - Writing ones to this register clears the corresponding bits in ENABLESET0. */
#define DMA_COMMON_ENABLECLR_CLR(x)              (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_ENABLECLR_CLR_SHIFT)) & DMA_COMMON_ENABLECLR_CLR_MASK)
/*! @} */

/* The count of DMA_COMMON_ENABLECLR */
#define DMA_COMMON_ENABLECLR_COUNT               (1U)

/*! @name COMMON_ENABLECLR1 - Channel Enable Clear for all DMA channels. */
/*! @{ */

#define DMA_COMMON_ENABLECLR1_CLR_MASK           (0xFFFFFFFFU)
#define DMA_COMMON_ENABLECLR1_CLR_SHIFT          (0U)
/*! CLR - Writing ones to this register clears the corresponding bits in ENABLESET1. */
#define DMA_COMMON_ENABLECLR1_CLR(x)             (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_ENABLECLR1_CLR_SHIFT)) & DMA_COMMON_ENABLECLR1_CLR_MASK)
/*! @} */

/* The count of DMA_COMMON_ENABLECLR1 */
#define DMA_COMMON_ENABLECLR1_COUNT              (1U)

/*! @name COMMON_ACTIVE - Channel Active status for all DMA channels. */
/*! @{ */

#define DMA_COMMON_ACTIVE_ACT_MASK               (0xFFFFFFFFU)
#define DMA_COMMON_ACTIVE_ACT_SHIFT              (0U)
/*! ACT - Active flag for DMA channel 0.
 *  0b00000000000000000000000000000000..DMAchannel 0 is not active.
 *  0b00000000000000000000000000000001..DMAchannel 0 is active.
 */
#define DMA_COMMON_ACTIVE_ACT(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_ACTIVE_ACT_SHIFT)) & DMA_COMMON_ACTIVE_ACT_MASK)
/*! @} */

/* The count of DMA_COMMON_ACTIVE */
#define DMA_COMMON_ACTIVE_COUNT                  (1U)

/*! @name COMMON_ACTIVE1 - Channel Active status for all DMA channels. */
/*! @{ */

#define DMA_COMMON_ACTIVE1_ACTIVE32_MASK         (0x1U)
#define DMA_COMMON_ACTIVE1_ACTIVE32_SHIFT        (0U)
/*! ACTIVE32 - Active flag for DMA channel 32.
 *  0b0..DMAchannel 32 is not active.
 *  0b1..DMAchannel 32 is active.
 */
#define DMA_COMMON_ACTIVE1_ACTIVE32(x)           (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_ACTIVE1_ACTIVE32_SHIFT)) & DMA_COMMON_ACTIVE1_ACTIVE32_MASK)

#define DMA_COMMON_ACTIVE1_ACTIVE63_33_MASK      (0xFFFFFFFEU)
#define DMA_COMMON_ACTIVE1_ACTIVE63_33_SHIFT     (1U)
/*! ACTIVE63_33 - Additional Active flags for remaining DMA channels in the range 63 to 33. Any bits
 *    above the actually implemented channels are reserved.
 *  0b0000000000000000000000000000000..The relevant DMA channel is not active.
 *  0b0000000000000000000000000000001..The relevant DMA channel is active.
 */
#define DMA_COMMON_ACTIVE1_ACTIVE63_33(x)        (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_ACTIVE1_ACTIVE63_33_SHIFT)) & DMA_COMMON_ACTIVE1_ACTIVE63_33_MASK)
/*! @} */

/* The count of DMA_COMMON_ACTIVE1 */
#define DMA_COMMON_ACTIVE1_COUNT                 (1U)

/*! @name COMMON_BUSY - Channel Busy status for all DMA channels. */
/*! @{ */

#define DMA_COMMON_BUSY_BSY_MASK                 (0xFFFFFFFFU)
#define DMA_COMMON_BUSY_BSY_SHIFT                (0U)
/*! BSY - Busy flag for DMA channel 0.
 *  0b00000000000000000000000000000000..DMAchannel 0 is not busy.
 *  0b00000000000000000000000000000001..DMAchannel 0 is busy.
 */
#define DMA_COMMON_BUSY_BSY(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_BUSY_BSY_SHIFT)) & DMA_COMMON_BUSY_BSY_MASK)
/*! @} */

/* The count of DMA_COMMON_BUSY */
#define DMA_COMMON_BUSY_COUNT                    (1U)

/*! @name COMMON_BUSY1 - Channel Busy status for all DMA channels. */
/*! @{ */

#define DMA_COMMON_BUSY1_BUSY32_MASK             (0x1U)
#define DMA_COMMON_BUSY1_BUSY32_SHIFT            (0U)
/*! BUSY32 - Busy flag for DMA channel 32.
 *  0b0..DMAchannel 32 is not busy.
 *  0b1..DMAchannel 0 is busy.
 */
#define DMA_COMMON_BUSY1_BUSY32(x)               (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_BUSY1_BUSY32_SHIFT)) & DMA_COMMON_BUSY1_BUSY32_MASK)

#define DMA_COMMON_BUSY1_BUSY63_33_MASK          (0xFFFFFFFEU)
#define DMA_COMMON_BUSY1_BUSY63_33_SHIFT         (1U)
/*! BUSY63_33 - Additional Active flags for remaining DMA channels in the range 63 to 33. Any bits
 *    above the actually implemented channels are reserved.
 *  0b0000000000000000000000000000000..The relevant DMA channel is not busy.
 *  0b0000000000000000000000000000001..The relevant DMA channel is busy.
 */
#define DMA_COMMON_BUSY1_BUSY63_33(x)            (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_BUSY1_BUSY63_33_SHIFT)) & DMA_COMMON_BUSY1_BUSY63_33_MASK)
/*! @} */

/* The count of DMA_COMMON_BUSY1 */
#define DMA_COMMON_BUSY1_COUNT                   (1U)

/*! @name COMMON_ERRINT - Error Interrupt status for all DMA channels. */
/*! @{ */

#define DMA_COMMON_ERRINT_ERR_MASK               (0xFFFFFFFFU)
#define DMA_COMMON_ERRINT_ERR_SHIFT              (0U)
/*! ERR - Error Interrupt flag for DMA channel 0.
 *  0b00000000000000000000000000000000..The Error Interrupt is not active for DMA channel 0.
 *  0b00000000000000000000000000000001..The Error Interrupt is pending for DMA channel 0.
 */
#define DMA_COMMON_ERRINT_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_ERRINT_ERR_SHIFT)) & DMA_COMMON_ERRINT_ERR_MASK)
/*! @} */

/* The count of DMA_COMMON_ERRINT */
#define DMA_COMMON_ERRINT_COUNT                  (1U)

/*! @name COMMON_ERRINT1 - Error Interrupt status for all DMA channels. */
/*! @{ */

#define DMA_COMMON_ERRINT1_ERR32_MASK            (0x1U)
#define DMA_COMMON_ERRINT1_ERR32_SHIFT           (0U)
/*! ERR32 - Error Interrupt flag for DMA channel 32.
 *  0b0..The Error Interrupt is not active for DMA channel 32.
 *  0b1..The Error Interrupt is pending for DMA channel 32.
 */
#define DMA_COMMON_ERRINT1_ERR32(x)              (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_ERRINT1_ERR32_SHIFT)) & DMA_COMMON_ERRINT1_ERR32_MASK)

#define DMA_COMMON_ERRINT1_ERR63_33_MASK         (0xFFFFFFFEU)
#define DMA_COMMON_ERRINT1_ERR63_33_SHIFT        (1U)
/*! ERR63_33 - Additional error Interrupt flags for remaining DMA channels in the range 63 to 33.
 *    Any bits above the actually implemented channels are reserved.
 *  0b0000000000000000000000000000000..The Error Interrupt is not active for the relevant DMA channel.
 *  0b0000000000000000000000000000001..The Error Interrupt is pending for the relevant DMA channel.
 */
#define DMA_COMMON_ERRINT1_ERR63_33(x)           (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_ERRINT1_ERR63_33_SHIFT)) & DMA_COMMON_ERRINT1_ERR63_33_MASK)
/*! @} */

/* The count of DMA_COMMON_ERRINT1 */
#define DMA_COMMON_ERRINT1_COUNT                 (1U)

/*! @name COMMON_INTENSET - Interrupt Enable read and Set for all DMA channels. */
/*! @{ */

#define DMA_COMMON_INTENSET_INTEN_MASK           (0xFFFFFFFFU)
#define DMA_COMMON_INTENSET_INTEN_SHIFT          (0U)
/*! INTEN - Interrupt Enable read and set for DMA channel 0.
 *  0b00000000000000000000000000000000..The Interrupt for DMA channel 0 is disabled.
 *  0b00000000000000000000000000000001..The Interrupt for DMA channel 0 is enabled.
 */
#define DMA_COMMON_INTENSET_INTEN(x)             (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_INTENSET_INTEN_SHIFT)) & DMA_COMMON_INTENSET_INTEN_MASK)
/*! @} */

/* The count of DMA_COMMON_INTENSET */
#define DMA_COMMON_INTENSET_COUNT                (1U)

/*! @name COMMON_INTENSET1 - Interrupt Enable read and Set for all DMA channels. */
/*! @{ */

#define DMA_COMMON_INTENSET1_INTEN32_MASK        (0x1U)
#define DMA_COMMON_INTENSET1_INTEN32_SHIFT       (0U)
/*! INTEN32 - Interrupt Enable read and set for DMA channel 32.
 *  0b0..The Interrupt for DMA channel 32 is disabled.
 *  0b1..The Interrupt for DMA channel 32 is enabled.
 */
#define DMA_COMMON_INTENSET1_INTEN32(x)          (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_INTENSET1_INTEN32_SHIFT)) & DMA_COMMON_INTENSET1_INTEN32_MASK)

#define DMA_COMMON_INTENSET1_INTEN63_33_MASK     (0xFFFFFFFEU)
#define DMA_COMMON_INTENSET1_INTEN63_33_SHIFT    (1U)
/*! INTEN63_33 - Additional Interrupt Enable read and set bits for remaining DMA channels in the
 *    range 63 to 33. Any bits above the actually implemented channels are reserved.
 *  0b0000000000000000000000000000000..The Interrupt for the relevant DMA channel is disabled.
 *  0b0000000000000000000000000000001..The Interrupt for the relevant DMA channel is enabled.
 */
#define DMA_COMMON_INTENSET1_INTEN63_33(x)       (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_INTENSET1_INTEN63_33_SHIFT)) & DMA_COMMON_INTENSET1_INTEN63_33_MASK)
/*! @} */

/* The count of DMA_COMMON_INTENSET1 */
#define DMA_COMMON_INTENSET1_COUNT               (1U)

/*! @name COMMON_INTENCLR - Interrupt Enable Clear for all DMA channels. */
/*! @{ */

#define DMA_COMMON_INTENCLR_CLR_MASK             (0xFFFFFFFFU)
#define DMA_COMMON_INTENCLR_CLR_SHIFT            (0U)
/*! CLR - Writing ones to this register clears corresponding bits in the DMAIntEnSet0. */
#define DMA_COMMON_INTENCLR_CLR(x)               (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_INTENCLR_CLR_SHIFT)) & DMA_COMMON_INTENCLR_CLR_MASK)
/*! @} */

/* The count of DMA_COMMON_INTENCLR */
#define DMA_COMMON_INTENCLR_COUNT                (1U)

/*! @name COMMON_INTENCLR1 - Interrupt Enable Clear for all DMA channels. */
/*! @{ */

#define DMA_COMMON_INTENCLR1_CLR_MASK            (0xFFFFFFFFU)
#define DMA_COMMON_INTENCLR1_CLR_SHIFT           (0U)
/*! CLR - Writing ones to this register clears corresponding bits in the DMAIntEnSet1. */
#define DMA_COMMON_INTENCLR1_CLR(x)              (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_INTENCLR1_CLR_SHIFT)) & DMA_COMMON_INTENCLR1_CLR_MASK)
/*! @} */

/* The count of DMA_COMMON_INTENCLR1 */
#define DMA_COMMON_INTENCLR1_COUNT               (1U)

/*! @name COMMON_INTA - Interrupt A status for all DMA channels. */
/*! @{ */

#define DMA_COMMON_INTA_IA_MASK                  (0xFFFFFFFFU)
#define DMA_COMMON_INTA_IA_SHIFT                 (0U)
/*! IA - Interrupt A status for DMA channel 0.
 *  0b00000000000000000000000000000000..The DMAchannel 0 interrupt A is not active.
 *  0b00000000000000000000000000000001..The DMAchannel 0 interrupt A is active.
 */
#define DMA_COMMON_INTA_IA(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_INTA_IA_SHIFT)) & DMA_COMMON_INTA_IA_MASK)
/*! @} */

/* The count of DMA_COMMON_INTA */
#define DMA_COMMON_INTA_COUNT                    (1U)

/*! @name COMMON_INTA1 - Interrupt A status for all DMA channels. */
/*! @{ */

#define DMA_COMMON_INTA1_INTA32_MASK             (0x1U)
#define DMA_COMMON_INTA1_INTA32_SHIFT            (0U)
/*! INTA32 - Interrupt A status for DMA channel 32.
 *  0b0..The DMAchannel 32 interrupt A is not active.
 *  0b1..The DMAchannel 0 interrupt A is active.
 */
#define DMA_COMMON_INTA1_INTA32(x)               (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_INTA1_INTA32_SHIFT)) & DMA_COMMON_INTA1_INTA32_MASK)

#define DMA_COMMON_INTA1_INTA63_33_MASK          (0xFFFFFFFEU)
#define DMA_COMMON_INTA1_INTA63_33_SHIFT         (1U)
/*! INTA63_33 - Additional Interrupt A status bits for remaining DMA channels in the range 63 to 33.
 *    Any bits above the actually implemented channels are reserved.
 *  0b0000000000000000000000000000000..Interrupt A is not active for the relevant DMA channel.
 *  0b0000000000000000000000000000001..Interrupt A is active for the relevant DMA channel.
 */
#define DMA_COMMON_INTA1_INTA63_33(x)            (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_INTA1_INTA63_33_SHIFT)) & DMA_COMMON_INTA1_INTA63_33_MASK)
/*! @} */

/* The count of DMA_COMMON_INTA1 */
#define DMA_COMMON_INTA1_COUNT                   (1U)

/*! @name COMMON_INTB - Interrupt B status for all DMA channels. */
/*! @{ */

#define DMA_COMMON_INTB_IB_MASK                  (0xFFFFFFFFU)
#define DMA_COMMON_INTB_IB_SHIFT                 (0U)
/*! IB - Interrupt B status for DMA channel 0.
 *  0b00000000000000000000000000000000..The DMAchannel 0 interrupt B is not active.
 *  0b00000000000000000000000000000001..The DMAchannel 0 interrupt B is active.
 */
#define DMA_COMMON_INTB_IB(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_INTB_IB_SHIFT)) & DMA_COMMON_INTB_IB_MASK)
/*! @} */

/* The count of DMA_COMMON_INTB */
#define DMA_COMMON_INTB_COUNT                    (1U)

/*! @name COMMON_INTB1 - Interrupt B status for all DMA channels. */
/*! @{ */

#define DMA_COMMON_INTB1_INTB32_MASK             (0x1U)
#define DMA_COMMON_INTB1_INTB32_SHIFT            (0U)
/*! INTB32 - Interrupt B status for DMA channel 32.
 *  0b0..The DMAchannel 32 interrupt B is not active.
 *  0b1..The DMAchannel 32 interrupt B is active.
 */
#define DMA_COMMON_INTB1_INTB32(x)               (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_INTB1_INTB32_SHIFT)) & DMA_COMMON_INTB1_INTB32_MASK)

#define DMA_COMMON_INTB1_INTB63_33_MASK          (0xFFFFFFFEU)
#define DMA_COMMON_INTB1_INTB63_33_SHIFT         (1U)
/*! INTB63_33 - Additional Interrupt B status bits for remaining DMA channels in the range 63 to 33.
 *    Any bits above the actually implemented channels are reserved.
 *  0b0000000000000000000000000000000..Interrupt B is not active for the relevant DMA channel.
 *  0b0000000000000000000000000000001..Interrupt B is active for the relevant DMA channel.
 */
#define DMA_COMMON_INTB1_INTB63_33(x)            (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_INTB1_INTB63_33_SHIFT)) & DMA_COMMON_INTB1_INTB63_33_MASK)
/*! @} */

/* The count of DMA_COMMON_INTB1 */
#define DMA_COMMON_INTB1_COUNT                   (1U)

/*! @name COMMON_SETVALID - Set ValidPending control bits for all DMA channels. */
/*! @{ */

#define DMA_COMMON_SETVALID_SV_MASK              (0xFFFFFFFFU)
#define DMA_COMMON_SETVALID_SV_SHIFT             (0U)
/*! SV - SetValid control for DMA channel 0.
 *  0b00000000000000000000000000000000..No effect.
 *  0b00000000000000000000000000000001..Sets the ValidPending control bit for DMA channel 0.
 */
#define DMA_COMMON_SETVALID_SV(x)                (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_SETVALID_SV_SHIFT)) & DMA_COMMON_SETVALID_SV_MASK)
/*! @} */

/* The count of DMA_COMMON_SETVALID */
#define DMA_COMMON_SETVALID_COUNT                (1U)

/*! @name COMMON_SETVALID1 - Set ValidPending control bits for all DMA channels. */
/*! @{ */

#define DMA_COMMON_SETVALID1_SETVALID32_MASK     (0x1U)
#define DMA_COMMON_SETVALID1_SETVALID32_SHIFT    (0U)
/*! SETVALID32 - SetValid control for DMA channel 32.
 *  0b0..No effect.
 *  0b1..Sets the ValidPending control bit for DMA channel 32.
 */
#define DMA_COMMON_SETVALID1_SETVALID32(x)       (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_SETVALID1_SETVALID32_SHIFT)) & DMA_COMMON_SETVALID1_SETVALID32_MASK)

#define DMA_COMMON_SETVALID1_SETVALID63_33_MASK  (0xFFFFFFFEU)
#define DMA_COMMON_SETVALID1_SETVALID63_33_SHIFT (1U)
/*! SETVALID63_33 - Additional SetValid controls for remaining DMA channels in the range 63 to 33.
 *    Any bits above the actually implemented channels are reserved.
 *  0b0000000000000000000000000000000..No effect.
 *  0b0000000000000000000000000000001..Sets the ValidPending control bit for the relevant DMA channel.
 */
#define DMA_COMMON_SETVALID1_SETVALID63_33(x)    (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_SETVALID1_SETVALID63_33_SHIFT)) & DMA_COMMON_SETVALID1_SETVALID63_33_MASK)
/*! @} */

/* The count of DMA_COMMON_SETVALID1 */
#define DMA_COMMON_SETVALID1_COUNT               (1U)

/*! @name COMMON_SETTRIG - Set Trigger control bits for all DMA channels. */
/*! @{ */

#define DMA_COMMON_SETTRIG_TRIG_MASK             (0xFFFFFFFFU)
#define DMA_COMMON_SETTRIG_TRIG_SHIFT            (0U)
/*! TRIG - Set Trigger control bit for DMA channel 0.
 *  0b00000000000000000000000000000000..No effect.
 *  0b00000000000000000000000000000001..Sets the Trig bit for DMA channel 0.
 */
#define DMA_COMMON_SETTRIG_TRIG(x)               (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_SETTRIG_TRIG_SHIFT)) & DMA_COMMON_SETTRIG_TRIG_MASK)
/*! @} */

/* The count of DMA_COMMON_SETTRIG */
#define DMA_COMMON_SETTRIG_COUNT                 (1U)

/*! @name COMMON_SETTRIG1 - Set Trigger control bits for all DMA channels. */
/*! @{ */

#define DMA_COMMON_SETTRIG1_SETTRIG32_MASK       (0x1U)
#define DMA_COMMON_SETTRIG1_SETTRIG32_SHIFT      (0U)
/*! SETTRIG32 - Set Trigger control bit for DMA channel 32.
 *  0b0..No effect.
 *  0b1..Sets the Trig bit for DMA channel 32.
 */
#define DMA_COMMON_SETTRIG1_SETTRIG32(x)         (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_SETTRIG1_SETTRIG32_SHIFT)) & DMA_COMMON_SETTRIG1_SETTRIG32_MASK)

#define DMA_COMMON_SETTRIG1_SETTRIG63_33_MASK    (0xFFFFFFFEU)
#define DMA_COMMON_SETTRIG1_SETTRIG63_33_SHIFT   (1U)
/*! SETTRIG63_33 - Additional Set Trigger control bits for remaining DMA channels in the range 63 to
 *    33. Any bits above the actually implemented channels are reserved.
 *  0b0000000000000000000000000000000..No effect.
 *  0b0000000000000000000000000000001..Sets the Trig bit for DMA channel for the relevant DMA channel.
 */
#define DMA_COMMON_SETTRIG1_SETTRIG63_33(x)      (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_SETTRIG1_SETTRIG63_33_SHIFT)) & DMA_COMMON_SETTRIG1_SETTRIG63_33_MASK)
/*! @} */

/* The count of DMA_COMMON_SETTRIG1 */
#define DMA_COMMON_SETTRIG1_COUNT                (1U)

/*! @name COMMON_ABORT - Channel Abort control for all DMA channels. */
/*! @{ */

#define DMA_COMMON_ABORT_ABORTCTRL_MASK          (0xFFFFFFFFU)
#define DMA_COMMON_ABORT_ABORTCTRL_SHIFT         (0U)
/*! ABORTCTRL - Abort control for DMA channel 0.
 *  0b00000000000000000000000000000000..No effect.
 *  0b00000000000000000000000000000001..Aborts DMA operations on channel 0.
 */
#define DMA_COMMON_ABORT_ABORTCTRL(x)            (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_ABORT_ABORTCTRL_SHIFT)) & DMA_COMMON_ABORT_ABORTCTRL_MASK)
/*! @} */

/* The count of DMA_COMMON_ABORT */
#define DMA_COMMON_ABORT_COUNT                   (1U)

/*! @name COMMON_ABORT1 - Channel Abort control for all DMA channels. */
/*! @{ */

#define DMA_COMMON_ABORT1_ABORT32_MASK           (0x1U)
#define DMA_COMMON_ABORT1_ABORT32_SHIFT          (0U)
/*! ABORT32 - Abort control for DMA channel 32.
 *  0b0..No effect.
 *  0b1..Aborts DMA operations on channel 32.
 */
#define DMA_COMMON_ABORT1_ABORT32(x)             (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_ABORT1_ABORT32_SHIFT)) & DMA_COMMON_ABORT1_ABORT32_MASK)

#define DMA_COMMON_ABORT1_ABORT63_33_MASK        (0xFFFFFFFEU)
#define DMA_COMMON_ABORT1_ABORT63_33_SHIFT       (1U)
/*! ABORT63_33 - Additional Abort controls for remaining DMA channels in the range 63 to 33. Any
 *    bits above the actually implemented channels are reserved.
 *  0b0000000000000000000000000000000..No effect.
 *  0b0000000000000000000000000000001..Aborts DMA operations on the relevant channel.
 */
#define DMA_COMMON_ABORT1_ABORT63_33(x)          (((uint32_t)(((uint32_t)(x)) << DMA_COMMON_ABORT1_ABORT63_33_SHIFT)) & DMA_COMMON_ABORT1_ABORT63_33_MASK)
/*! @} */

/* The count of DMA_COMMON_ABORT1 */
#define DMA_COMMON_ABORT1_COUNT                  (1U)

/*! @name CHANNEL_CFG - Configuration register for DMA channel . */
/*! @{ */

#define DMA_CHANNEL_CFG_PERIPHREQEN_MASK         (0x1U)
#define DMA_CHANNEL_CFG_PERIPHREQEN_SHIFT        (0U)
/*! PERIPHREQEN - Peripheral request Enable. If a DMA channel is used to perform a memory-to-memory
 *    move, any peripheral DMA request associated with that channel can be disabled to prevent any
 *    interaction between the peripheral and the DMA controller.
 *  0b0..Disabled. Peripheral DMA requests are disabled.
 *  0b1..Enabled. Peripheral DMA requests are enabled.
 */
#define DMA_CHANNEL_CFG_PERIPHREQEN(x)           (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_CFG_PERIPHREQEN_SHIFT)) & DMA_CHANNEL_CFG_PERIPHREQEN_MASK)

#define DMA_CHANNEL_CFG_HWTRIGEN_MASK            (0x2U)
#define DMA_CHANNEL_CFG_HWTRIGEN_SHIFT           (1U)
/*! HWTRIGEN - Hardware Triggering Enable for this channel.
 *  0b0..Disabled. Hardware triggering is not used.
 *  0b1..Enabled. Use hardware triggering.
 */
#define DMA_CHANNEL_CFG_HWTRIGEN(x)              (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_CFG_HWTRIGEN_SHIFT)) & DMA_CHANNEL_CFG_HWTRIGEN_MASK)

#define DMA_CHANNEL_CFG_TRIGPOL_MASK             (0x10U)
#define DMA_CHANNEL_CFG_TRIGPOL_SHIFT            (4U)
/*! TRIGPOL - Trigger Polarity. Selects the polarity of a hardware trigger for this channel.
 *  0b0..Active low - falling edge. Hardware trigger is active low or falling edge triggered, based on TRIGTYPE.
 *  0b1..Active high - rising edge. Hardware trigger is active high or rising edge triggered, based on TRIGTYPE.
 */
#define DMA_CHANNEL_CFG_TRIGPOL(x)               (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_CFG_TRIGPOL_SHIFT)) & DMA_CHANNEL_CFG_TRIGPOL_MASK)

#define DMA_CHANNEL_CFG_TRIGTYPE_MASK            (0x20U)
#define DMA_CHANNEL_CFG_TRIGTYPE_SHIFT           (5U)
/*! TRIGTYPE - Trigger Type. Selects hardware trigger as edge triggered or level triggered.
 *  0b0..Edge. Hardware trigger is edge triggered. Transfers will be initiated and completed, as specified for a single trigger.
 *  0b1..Level. Hardware trigger is level triggered. Note that when level triggering without burst (BURSTPOWER =
 *       0) is selected, only hardware triggers should be used on that channel. Transfers continue as long as the
 *       trigger level is asserted. Once the trigger is de-asserted, the transfer will be paused until the trigger
 *       is, again, asserted. However, the transfer will not be paused until any remaining transfers within the
 *       current BURSTPOWER length are completed.
 */
#define DMA_CHANNEL_CFG_TRIGTYPE(x)              (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_CFG_TRIGTYPE_SHIFT)) & DMA_CHANNEL_CFG_TRIGTYPE_MASK)

#define DMA_CHANNEL_CFG_TRIGBURST_MASK           (0x40U)
#define DMA_CHANNEL_CFG_TRIGBURST_SHIFT          (6U)
/*! TRIGBURST - Trigger Burst. Selects whether hardware triggers cause a single or burst transfer.
 *  0b0..Single transfer. Hardware trigger causes a single transfer.
 *  0b1..Burst transfer. When the trigger for this channel is set to edge triggered, a hardware trigger causes a
 *       burst transfer, as defined by BURSTPOWER. When the trigger for this channel is set to level triggered, a
 *       hardware trigger causes transfers to continue as long as the trigger is asserted, unless the transfer is
 *       complete.
 */
#define DMA_CHANNEL_CFG_TRIGBURST(x)             (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_CFG_TRIGBURST_SHIFT)) & DMA_CHANNEL_CFG_TRIGBURST_MASK)

#define DMA_CHANNEL_CFG_BURSTPOWER_MASK          (0xF00U)
#define DMA_CHANNEL_CFG_BURSTPOWER_SHIFT         (8U)
/*! BURSTPOWER - Burst Power is used in two ways. It always selects the address wrap size when
 *    SRCBURSTWRAP and/or DSTBURSTWRAP modes are selected (see descriptions elsewhere in this register).
 *    When the TRIGBURST field elsewhere in this register = 1, Burst Power selects how many
 *    transfers are performed for each DMA trigger. This can be used, for example, with peripherals that
 *    contain a FIFO that can initiate a DMA operation when the FIFO reaches a certain level. 0000:
 *    Burst size = 1 (20). 0001: Burst size = 2 (21). 0010: Burst size = 4 (22). 1010: Burst size =
 *    1024 (210). This corresponds to the maximum supported transfer count. others: not supported. The
 *    total transfer length as defined in the XFERCOUNT bits in the XFERCFG register must be an even
 *    multiple of the burst size.
 */
#define DMA_CHANNEL_CFG_BURSTPOWER(x)            (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_CFG_BURSTPOWER_SHIFT)) & DMA_CHANNEL_CFG_BURSTPOWER_MASK)

#define DMA_CHANNEL_CFG_SRCBURSTWRAP_MASK        (0x4000U)
#define DMA_CHANNEL_CFG_SRCBURSTWRAP_SHIFT       (14U)
/*! SRCBURSTWRAP - Source Burst Wrap. When enabled, the source data address for the DMA is
 *    'wrapped', meaning that the source address range for each burst will be the same. As an example, this
 *    could be used to read several sequential registers from a peripheral for each DMA burst,
 *    reading the same registers again for each burst.
 *  0b0..Disabled. Source burst wrapping is not enabled for this DMA channel.
 *  0b1..Enabled. Source burst wrapping is enabled for this DMA channel.
 */
#define DMA_CHANNEL_CFG_SRCBURSTWRAP(x)          (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_CFG_SRCBURSTWRAP_SHIFT)) & DMA_CHANNEL_CFG_SRCBURSTWRAP_MASK)

#define DMA_CHANNEL_CFG_DSTBURSTWRAP_MASK        (0x8000U)
#define DMA_CHANNEL_CFG_DSTBURSTWRAP_SHIFT       (15U)
/*! DSTBURSTWRAP - Destination Burst Wrap. When enabled, the destination data address for the DMA is
 *    'wrapped', meaning that the destination address range for each burst will be the same. As an
 *    example, this could be used to write several sequential registers to a peripheral for each DMA
 *    burst, writing the same registers again for each burst.
 *  0b0..Disabled. Destination burst wrapping is not enabled for this DMA channel.
 *  0b1..Enabled. Destination burst wrapping is enabled for this DMA channel.
 */
#define DMA_CHANNEL_CFG_DSTBURSTWRAP(x)          (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_CFG_DSTBURSTWRAP_SHIFT)) & DMA_CHANNEL_CFG_DSTBURSTWRAP_MASK)

#define DMA_CHANNEL_CFG_CHPRIORITY_MASK          (0x70000U)
#define DMA_CHANNEL_CFG_CHPRIORITY_SHIFT         (16U)
/*! CHPRIORITY - Priority of this channel when multiple DMA requests are pending. Eight priority
 *    levels are supported: 0x0 = highest priority. 0x7 = lowest priority.
 */
#define DMA_CHANNEL_CFG_CHPRIORITY(x)            (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_CFG_CHPRIORITY_SHIFT)) & DMA_CHANNEL_CFG_CHPRIORITY_MASK)
/*! @} */

/* The count of DMA_CHANNEL_CFG */
#define DMA_CHANNEL_CFG_COUNT                    (33U)

/*! @name CHANNEL_CTLSTAT - Control and status register for DMA channel . */
/*! @{ */

#define DMA_CHANNEL_CTLSTAT_VALIDPENDING_MASK    (0x1U)
#define DMA_CHANNEL_CTLSTAT_VALIDPENDING_SHIFT   (0U)
/*! VALIDPENDING - Valid pending flag for this channel. This bit is set when a 1 is written to the
 *    corresponding bit in the related SETVALID register when CFGVALID = 1 for the same channel.
 *  0b0..No effect. No effect on DMA operation.
 *  0b1..Valid pending.
 */
#define DMA_CHANNEL_CTLSTAT_VALIDPENDING(x)      (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_CTLSTAT_VALIDPENDING_SHIFT)) & DMA_CHANNEL_CTLSTAT_VALIDPENDING_MASK)

#define DMA_CHANNEL_CTLSTAT_TRIG_MASK            (0x4U)
#define DMA_CHANNEL_CTLSTAT_TRIG_SHIFT           (2U)
/*! TRIG - Trigger flag. Indicates that the trigger for this channel is currently set. This bit is
 *    cleared at the end of an entire transfer or upon reload when CLRTRIG = 1.
 *  0b0..Not triggered. The trigger for this DMA channel is not set. DMA operations will not be carried out.
 *  0b1..Triggered. The trigger for this DMA channel is set. DMA operations will be carried out.
 */
#define DMA_CHANNEL_CTLSTAT_TRIG(x)              (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_CTLSTAT_TRIG_SHIFT)) & DMA_CHANNEL_CTLSTAT_TRIG_MASK)
/*! @} */

/* The count of DMA_CHANNEL_CTLSTAT */
#define DMA_CHANNEL_CTLSTAT_COUNT                (33U)

/*! @name CHANNEL_XFERCFG - Transfer configuration register for DMA channel . */
/*! @{ */

#define DMA_CHANNEL_XFERCFG_CFGVALID_MASK        (0x1U)
#define DMA_CHANNEL_XFERCFG_CFGVALID_SHIFT       (0U)
/*! CFGVALID - Configuration Valid flag. This bit indicates whether the current channel descriptor
 *    is valid and can potentially be acted upon, if all other activation criteria are fulfilled.
 *  0b0..Not valid. The channel descriptor is not considered valid until validated by an associated SETVALID0 setting.
 *  0b1..Valid. The current channel descriptor is considered valid.
 */
#define DMA_CHANNEL_XFERCFG_CFGVALID(x)          (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_XFERCFG_CFGVALID_SHIFT)) & DMA_CHANNEL_XFERCFG_CFGVALID_MASK)

#define DMA_CHANNEL_XFERCFG_RELOAD_MASK          (0x2U)
#define DMA_CHANNEL_XFERCFG_RELOAD_SHIFT         (1U)
/*! RELOAD - Indicates whether the channel's control structure will be reloaded when the current
 *    descriptor is exhausted. Reloading allows ping-pong and linked transfers.
 *  0b0..Disabled. Do not reload the channels' control structure when the current descriptor is exhausted.
 *  0b1..Enabled. Reload the channels' control structure when the current descriptor is exhausted.
 */
#define DMA_CHANNEL_XFERCFG_RELOAD(x)            (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_XFERCFG_RELOAD_SHIFT)) & DMA_CHANNEL_XFERCFG_RELOAD_MASK)

#define DMA_CHANNEL_XFERCFG_SWTRIG_MASK          (0x4U)
#define DMA_CHANNEL_XFERCFG_SWTRIG_SHIFT         (2U)
/*! SWTRIG - Software Trigger.
 *  0b0..Not set. When written by software, the trigger for this channel is not set. A new trigger, as defined by
 *       the HWTRIGEN, TRIGPOL, and TRIGTYPE will be needed to start the channel.
 *  0b1..Set. When written by software, the trigger for this channel is set immediately. This feature should not
 *       be used with level triggering when TRIGBURST = 0.
 */
#define DMA_CHANNEL_XFERCFG_SWTRIG(x)            (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_XFERCFG_SWTRIG_SHIFT)) & DMA_CHANNEL_XFERCFG_SWTRIG_MASK)

#define DMA_CHANNEL_XFERCFG_CLRTRIG_MASK         (0x8U)
#define DMA_CHANNEL_XFERCFG_CLRTRIG_SHIFT        (3U)
/*! CLRTRIG - Clear Trigger.
 *  0b0..Not cleared. The trigger is not cleared when this descriptor is exhausted. If there is a reload, the next descriptor will be started.
 *  0b1..Cleared. The trigger is cleared when this descriptor is exhausted
 */
#define DMA_CHANNEL_XFERCFG_CLRTRIG(x)           (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_XFERCFG_CLRTRIG_SHIFT)) & DMA_CHANNEL_XFERCFG_CLRTRIG_MASK)

#define DMA_CHANNEL_XFERCFG_SETINTA_MASK         (0x10U)
#define DMA_CHANNEL_XFERCFG_SETINTA_SHIFT        (4U)
/*! SETINTA - Set Interrupt flag A for this channel. There is no hardware distinction between
 *    interrupt A and B. They can be used by software to assist with more complex descriptor usage. By
 *    convention, interrupt A may be used when only one interrupt flag is needed.
 *  0b0..No effect.
 *  0b1..Set. The INTA flag for this channel will be set when the current descriptor is exhausted.
 */
#define DMA_CHANNEL_XFERCFG_SETINTA(x)           (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_XFERCFG_SETINTA_SHIFT)) & DMA_CHANNEL_XFERCFG_SETINTA_MASK)

#define DMA_CHANNEL_XFERCFG_SETINTB_MASK         (0x20U)
#define DMA_CHANNEL_XFERCFG_SETINTB_SHIFT        (5U)
/*! SETINTB - Set Interrupt flag B for this channel. There is no hardware distinction between
 *    interrupt A and B. They can be used by software to assist with more complex descriptor usage. By
 *    convention, interrupt A may be used when only one interrupt flag is needed.
 *  0b0..No effect.
 *  0b1..Set. The INTB flag for this channel will be set when the current descriptor is exhausted.
 */
#define DMA_CHANNEL_XFERCFG_SETINTB(x)           (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_XFERCFG_SETINTB_SHIFT)) & DMA_CHANNEL_XFERCFG_SETINTB_MASK)

#define DMA_CHANNEL_XFERCFG_WIDTH_MASK           (0x300U)
#define DMA_CHANNEL_XFERCFG_WIDTH_SHIFT          (8U)
/*! WIDTH - Transfer width used for this DMA channel.
 *  0b00..8-bit. 8-bit transfers are performed (8-bit source reads and destination writes).
 *  0b01..16-bit. 6-bit transfers are performed (16-bit source reads and destination writes).
 *  0b10..32-bit. 32-bit transfers are performed (32-bit source reads and destination writes).
 *  0b11..Reserved. Reserved setting, do not use.
 */
#define DMA_CHANNEL_XFERCFG_WIDTH(x)             (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_XFERCFG_WIDTH_SHIFT)) & DMA_CHANNEL_XFERCFG_WIDTH_MASK)

#define DMA_CHANNEL_XFERCFG_SRCINC_MASK          (0x3000U)
#define DMA_CHANNEL_XFERCFG_SRCINC_SHIFT         (12U)
/*! SRCINC - Determines whether the source address is incremented for each DMA transfer.
 *  0b00..No increment. The source address is not incremented for each transfer. This is the usual case when the source is a peripheral device.
 *  0b01..1 x width. The source address is incremented by the amount specified by Width for each transfer. This is
 *        the usual case when the source is memory.
 *  0b10..2 x width. The source address is incremented by 2 times the amount specified by Width for each transfer.
 *  0b11..4 x width. The source address is incremented by 4 times the amount specified by Width for each transfer.
 */
#define DMA_CHANNEL_XFERCFG_SRCINC(x)            (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_XFERCFG_SRCINC_SHIFT)) & DMA_CHANNEL_XFERCFG_SRCINC_MASK)

#define DMA_CHANNEL_XFERCFG_DSTINC_MASK          (0xC000U)
#define DMA_CHANNEL_XFERCFG_DSTINC_SHIFT         (14U)
/*! DSTINC - Determines whether the destination address is incremented for each DMA transfer.
 *  0b00..No increment. The destination address is not incremented for each transfer. This is the usual case when
 *        the destination is a peripheral device.
 *  0b01..1 x width. The destination address is incremented by the amount specified by Width for each transfer.
 *        This is the usual case when the destination is memory.
 *  0b10..2 x width. The destination address is incremented by 2 times the amount specified by Width for each transfer.
 *  0b11..4 x width. The destination address is incremented by 4 times the amount specified by Width for each transfer.
 */
#define DMA_CHANNEL_XFERCFG_DSTINC(x)            (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_XFERCFG_DSTINC_SHIFT)) & DMA_CHANNEL_XFERCFG_DSTINC_MASK)

#define DMA_CHANNEL_XFERCFG_XFERCOUNT_MASK       (0x3FF0000U)
#define DMA_CHANNEL_XFERCFG_XFERCOUNT_SHIFT      (16U)
/*! XFERCOUNT - Total number of transfers to be performed, minus 1 encoded. The number of bytes
 *    transferred is: (XFERCOUNT + 1) x data width (as defined by the WIDTH field). The DMA controller
 *    uses this bit field during transfer to count down. Hence, it cannot be used by software to read
 *    back the size of the transfer, for instance, in an interrupt handler. 0x0 = a total of 1
 *    transfer will be performed. 0x1 = a total of 2 transfers will be performed. 0x3FF = a total of
 *    1,024 transfers will be performed.
 */
#define DMA_CHANNEL_XFERCFG_XFERCOUNT(x)         (((uint32_t)(((uint32_t)(x)) << DMA_CHANNEL_XFERCFG_XFERCOUNT_SHIFT)) & DMA_CHANNEL_XFERCFG_XFERCOUNT_MASK)
/*! @} */

/* The count of DMA_CHANNEL_XFERCFG */
#define DMA_CHANNEL_XFERCFG_COUNT                (33U)


/*!
 * @}
 */ /* end of group DMA_Register_Masks */


/*!
 * @}
 */ /* end of group DMA_Peripheral_Access_Layer */


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


#endif  /* PERI_DMA_H_ */

