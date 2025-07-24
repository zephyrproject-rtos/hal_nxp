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
**         CMSIS Peripheral Access Layer for RSTCTL0
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
 * @file PERI_RSTCTL0.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RSTCTL0
 *
 * CMSIS Peripheral Access Layer for RSTCTL0
 */

#if !defined(PERI_RSTCTL0_H_)
#define PERI_RSTCTL0_H_                          /**< Symbol preventing repeated inclusion */

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
   -- RSTCTL0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL0_Peripheral_Access_Layer RSTCTL0 Peripheral Access Layer
 * @{
 */

/** RSTCTL0 - Register Layout Typedef */
typedef struct {
  __IO uint32_t SYSRSTSTAT;                        /**< System Reset Status Register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t PRSTCTL0;                          /**< Peripheral Reset Control Register 0, offset: 0x10 */
  __IO uint32_t PRSTCTL1;                          /**< Peripheral Reset Control Register 1, offset: 0x14 */
  __IO uint32_t PRSTCTL2;                          /**< Peripheral Reset Control Register 2, offset: 0x18 */
       uint8_t RESERVED_1[36];
  __O  uint32_t PRSTCTL0_SET;                      /**< Peripheral Reset Control Register 0 SET, offset: 0x40 */
  __O  uint32_t PRSTCTL1_SET;                      /**< Peripheral Reset Control Register 1 SET, offset: 0x44 */
  __O  uint32_t PRSTCTL2_SET;                      /**< Peripheral Reset Control Register 2 SET, offset: 0x48 */
       uint8_t RESERVED_2[36];
  __O  uint32_t PRSTCTL0_CLR;                      /**< Peripheral Reset Control Register 0 CLR, offset: 0x70 */
  __O  uint32_t PRSTCTL1_CLR;                      /**< Peripheral Reset Control Register 1 CLR, offset: 0x74 */
  __O  uint32_t PRSTCTL2_CLR;                      /**< Peripheral Reset Control Register 2 CLR, offset: 0x78 */
} RSTCTL0_Type;

/* ----------------------------------------------------------------------------
   -- RSTCTL0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL0_Register_Masks RSTCTL0 Register Masks
 * @{
 */

/*! @name SYSRSTSTAT - System Reset Status Register */
/*! @{ */

#define RSTCTL0_SYSRSTSTAT_VDD_POR_MASK          (0x1U)
#define RSTCTL0_SYSRSTSTAT_VDD_POR_SHIFT         (0U)
/*! VDD_POR - VDD CORE Power-On Reset (POR) was detected
 *  0b0..No VDD CORE POR event is detected
 *  0b1..VDD CORE POR event was detected
 */
#define RSTCTL0_SYSRSTSTAT_VDD_POR(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_SYSRSTSTAT_VDD_POR_SHIFT)) & RSTCTL0_SYSRSTSTAT_VDD_POR_MASK)

#define RSTCTL0_SYSRSTSTAT_PAD_RESET_MASK        (0x10U)
#define RSTCTL0_SYSRSTSTAT_PAD_RESET_SHIFT       (4U)
/*! PAD_RESET - RESETN pin reset was detected
 *  0b0..No RESETN pin event is detected
 *  0b1..RESETN pin event was detected. Write '1' to clear this bit
 */
#define RSTCTL0_SYSRSTSTAT_PAD_RESET(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_SYSRSTSTAT_PAD_RESET_SHIFT)) & RSTCTL0_SYSRSTSTAT_PAD_RESET_MASK)

#define RSTCTL0_SYSRSTSTAT_ARM_RESET_MASK        (0x20U)
#define RSTCTL0_SYSRSTSTAT_ARM_RESET_SHIFT       (5U)
/*! ARM_RESET - ARM reset was detected
 *  0b0..No ARM reset event is detected
 *  0b1..ARM reset was detected. Write '1' to clear this bit
 */
#define RSTCTL0_SYSRSTSTAT_ARM_RESET(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_SYSRSTSTAT_ARM_RESET_SHIFT)) & RSTCTL0_SYSRSTSTAT_ARM_RESET_MASK)

#define RSTCTL0_SYSRSTSTAT_WDT0_RESET_MASK       (0x40U)
#define RSTCTL0_SYSRSTSTAT_WDT0_RESET_SHIFT      (6U)
/*! WDT0_RESET - WatchDog Timer 0 reset was detected
 *  0b0..No WDT0 reset event detected
 *  0b1..WDT0 reset event detected. Write '1' to clear this bit
 */
#define RSTCTL0_SYSRSTSTAT_WDT0_RESET(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_SYSRSTSTAT_WDT0_RESET_SHIFT)) & RSTCTL0_SYSRSTSTAT_WDT0_RESET_MASK)

#define RSTCTL0_SYSRSTSTAT_WDT1_RESET_MASK       (0x80U)
#define RSTCTL0_SYSRSTSTAT_WDT1_RESET_SHIFT      (7U)
/*! WDT1_RESET - WatchDog Timer 1 reset was detected
 *  0b0..No WDT1 reset event detected
 *  0b1..WDT1 reset event detected. Write '1' to clear this bit
 */
#define RSTCTL0_SYSRSTSTAT_WDT1_RESET(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_SYSRSTSTAT_WDT1_RESET_SHIFT)) & RSTCTL0_SYSRSTSTAT_WDT1_RESET_MASK)
/*! @} */

/*! @name PRSTCTL0 - Peripheral Reset Control Register 0 */
/*! @{ */

#define RSTCTL0_PRSTCTL0_DSP_MASK                (0x2U)
#define RSTCTL0_PRSTCTL0_DSP_SHIFT               (1U)
/*! DSP - Fusion F1 DSP reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_DSP(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_DSP_SHIFT)) & RSTCTL0_PRSTCTL0_DSP_MASK)

#define RSTCTL0_PRSTCTL0_AXI_SWITCH_MASK         (0x8U)
#define RSTCTL0_PRSTCTL0_AXI_SWITCH_SHIFT        (3U)
/*! AXI_SWITCH - AXI Switch reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_AXI_SWITCH(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_AXI_SWITCH_SHIFT)) & RSTCTL0_PRSTCTL0_AXI_SWITCH_MASK)

#define RSTCTL0_PRSTCTL0_POWERQUAD_MASK          (0x100U)
#define RSTCTL0_PRSTCTL0_POWERQUAD_SHIFT         (8U)
/*! POWERQUAD - POWERQUAD reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_POWERQUAD(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_POWERQUAD_SHIFT)) & RSTCTL0_PRSTCTL0_POWERQUAD_MASK)

#define RSTCTL0_PRSTCTL0_CASPER_MASK             (0x200U)
#define RSTCTL0_PRSTCTL0_CASPER_SHIFT            (9U)
/*! CASPER - CASPER reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_CASPER(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CASPER_SHIFT)) & RSTCTL0_PRSTCTL0_CASPER_MASK)

#define RSTCTL0_PRSTCTL0_HASHCRYPT_MASK          (0x400U)
#define RSTCTL0_PRSTCTL0_HASHCRYPT_SHIFT         (10U)
/*! HASHCRYPT - Hash-Crypt reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_HASHCRYPT(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_HASHCRYPT_SHIFT)) & RSTCTL0_PRSTCTL0_HASHCRYPT_MASK)

#define RSTCTL0_PRSTCTL0_PUF_MASK                (0x800U)
#define RSTCTL0_PRSTCTL0_PUF_SHIFT               (11U)
/*! PUF - PUF reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_PUF(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_PUF_SHIFT)) & RSTCTL0_PRSTCTL0_PUF_MASK)

#define RSTCTL0_PRSTCTL0_RNG_MASK                (0x1000U)
#define RSTCTL0_PRSTCTL0_RNG_SHIFT               (12U)
/*! RNG - RNG reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_RNG(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_RNG_SHIFT)) & RSTCTL0_PRSTCTL0_RNG_MASK)

#define RSTCTL0_PRSTCTL0_FLEXSPI0_OTFAD_MASK     (0x10000U)
#define RSTCTL0_PRSTCTL0_FLEXSPI0_OTFAD_SHIFT    (16U)
/*! FLEXSPI0_OTFAD - FLEXSPI0 and OTFAD reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_FLEXSPI0_OTFAD(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_FLEXSPI0_OTFAD_SHIFT)) & RSTCTL0_PRSTCTL0_FLEXSPI0_OTFAD_MASK)

#define RSTCTL0_PRSTCTL0_FLEXSPI1_MASK           (0x40000U)
#define RSTCTL0_PRSTCTL0_FLEXSPI1_SHIFT          (18U)
/*! FLEXSPI1 - FLEXSPI1 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_FLEXSPI1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_FLEXSPI1_SHIFT)) & RSTCTL0_PRSTCTL0_FLEXSPI1_MASK)

#define RSTCTL0_PRSTCTL0_USBHS_PHY_MASK          (0x100000U)
#define RSTCTL0_PRSTCTL0_USBHS_PHY_SHIFT         (20U)
/*! USBHS_PHY - USB PHY reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_USBHS_PHY(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_USBHS_PHY_SHIFT)) & RSTCTL0_PRSTCTL0_USBHS_PHY_MASK)

#define RSTCTL0_PRSTCTL0_USBHS_DEVICE_MASK       (0x200000U)
#define RSTCTL0_PRSTCTL0_USBHS_DEVICE_SHIFT      (21U)
/*! USBHS_DEVICE - USB HS Device reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_USBHS_DEVICE(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_USBHS_DEVICE_SHIFT)) & RSTCTL0_PRSTCTL0_USBHS_DEVICE_MASK)

#define RSTCTL0_PRSTCTL0_USBHS_HOST_MASK         (0x400000U)
#define RSTCTL0_PRSTCTL0_USBHS_HOST_SHIFT        (22U)
/*! USBHS_HOST - USB HOST reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_USBHS_HOST(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_USBHS_HOST_SHIFT)) & RSTCTL0_PRSTCTL0_USBHS_HOST_MASK)

#define RSTCTL0_PRSTCTL0_USBHS_SRAM_MASK         (0x800000U)
#define RSTCTL0_PRSTCTL0_USBHS_SRAM_SHIFT        (23U)
/*! USBHS_SRAM - USB RAM reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_USBHS_SRAM(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_USBHS_SRAM_SHIFT)) & RSTCTL0_PRSTCTL0_USBHS_SRAM_MASK)

#define RSTCTL0_PRSTCTL0_SCT_MASK                (0x1000000U)
#define RSTCTL0_PRSTCTL0_SCT_SHIFT               (24U)
/*! SCT - SCTimer reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_SCT(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SCT_SHIFT)) & RSTCTL0_PRSTCTL0_SCT_MASK)

#define RSTCTL0_PRSTCTL0_GPU_MASK                (0x4000000U)
#define RSTCTL0_PRSTCTL0_GPU_SHIFT               (26U)
/*! GPU - GPU reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_GPU(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_GPU_SHIFT)) & RSTCTL0_PRSTCTL0_GPU_MASK)

#define RSTCTL0_PRSTCTL0_DISPLAY_CONTROLLER_MASK (0x8000000U)
#define RSTCTL0_PRSTCTL0_DISPLAY_CONTROLLER_SHIFT (27U)
/*! DISPLAY_CONTROLLER - LCDIF Display Controller reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_DISPLAY_CONTROLLER(x)   (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_DISPLAY_CONTROLLER_SHIFT)) & RSTCTL0_PRSTCTL0_DISPLAY_CONTROLLER_MASK)

#define RSTCTL0_PRSTCTL0_MIPI_DSI_CONTROLLER_MASK (0x10000000U)
#define RSTCTL0_PRSTCTL0_MIPI_DSI_CONTROLLER_SHIFT (28U)
/*! MIPI_DSI_CONTROLLER - MIPI Digital serial Interface controller reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_MIPI_DSI_CONTROLLER(x)  (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_MIPI_DSI_CONTROLLER_SHIFT)) & RSTCTL0_PRSTCTL0_MIPI_DSI_CONTROLLER_MASK)

#define RSTCTL0_PRSTCTL0_MIPI_DSI_PHY_MASK       (0x20000000U)
#define RSTCTL0_PRSTCTL0_MIPI_DSI_PHY_SHIFT      (29U)
/*! MIPI_DSI_PHY - MIPI DSI PHY reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_MIPI_DSI_PHY(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_MIPI_DSI_PHY_SHIFT)) & RSTCTL0_PRSTCTL0_MIPI_DSI_PHY_MASK)

#define RSTCTL0_PRSTCTL0_SMARTDMA_MASK           (0x40000000U)
#define RSTCTL0_PRSTCTL0_SMARTDMA_SHIFT          (30U)
/*! SMARTDMA - SMARTDMA Event/Algorithm handler reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL0_SMARTDMA(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SMARTDMA_SHIFT)) & RSTCTL0_PRSTCTL0_SMARTDMA_MASK)
/*! @} */

/*! @name PRSTCTL1 - Peripheral Reset Control Register 1 */
/*! @{ */

#define RSTCTL0_PRSTCTL1_SDIO0_MASK              (0x4U)
#define RSTCTL0_PRSTCTL1_SDIO0_SHIFT             (2U)
/*! SDIO0 - SDIO0 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL1_SDIO0(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SDIO0_SHIFT)) & RSTCTL0_PRSTCTL1_SDIO0_MASK)

#define RSTCTL0_PRSTCTL1_SDIO1_MASK              (0x8U)
#define RSTCTL0_PRSTCTL1_SDIO1_SHIFT             (3U)
/*! SDIO1 - SDIO1 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL1_SDIO1(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SDIO1_SHIFT)) & RSTCTL0_PRSTCTL1_SDIO1_MASK)

#define RSTCTL0_PRSTCTL1_ACMP0_MASK              (0x8000U)
#define RSTCTL0_PRSTCTL1_ACMP0_SHIFT             (15U)
/*! ACMP0
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL1_ACMP0(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_ACMP0_SHIFT)) & RSTCTL0_PRSTCTL1_ACMP0_MASK)

#define RSTCTL0_PRSTCTL1_ADC0_MASK               (0x10000U)
#define RSTCTL0_PRSTCTL1_ADC0_SHIFT              (16U)
/*! ADC0
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL1_ADC0(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_ADC0_SHIFT)) & RSTCTL0_PRSTCTL1_ADC0_MASK)

#define RSTCTL0_PRSTCTL1_SHSGPIO0_MASK           (0x1000000U)
#define RSTCTL0_PRSTCTL1_SHSGPIO0_SHIFT          (24U)
/*! SHSGPIO0 - Secure GPIO 0 reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL1_SHSGPIO0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SHSGPIO0_SHIFT)) & RSTCTL0_PRSTCTL1_SHSGPIO0_MASK)
/*! @} */

/*! @name PRSTCTL2 - Peripheral Reset Control Register 2 */
/*! @{ */

#define RSTCTL0_PRSTCTL2_UTICK0_MASK             (0x1U)
#define RSTCTL0_PRSTCTL2_UTICK0_SHIFT            (0U)
/*! UTICK0 - Micro-tick timer reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL2_UTICK0(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_UTICK0_SHIFT)) & RSTCTL0_PRSTCTL2_UTICK0_MASK)

#define RSTCTL0_PRSTCTL2_WWDT0_MASK              (0x2U)
#define RSTCTL0_PRSTCTL2_WWDT0_SHIFT             (1U)
/*! WWDT0 - Watchdog timer reset control
 *  0b0..Clear Reset
 *  0b1..Set Reset
 */
#define RSTCTL0_PRSTCTL2_WWDT0(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_WWDT0_SHIFT)) & RSTCTL0_PRSTCTL2_WWDT0_MASK)
/*! @} */

/*! @name PRSTCTL0_SET - Peripheral Reset Control Register 0 SET */
/*! @{ */

#define RSTCTL0_PRSTCTL0_SET_DSP_MASK            (0x2U)
#define RSTCTL0_PRSTCTL0_SET_DSP_SHIFT           (1U)
/*! DSP - Fusion_ DSP reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_DSP(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_DSP_SHIFT)) & RSTCTL0_PRSTCTL0_SET_DSP_MASK)

#define RSTCTL0_PRSTCTL0_SET_AXI_SWITCH_MASK     (0x8U)
#define RSTCTL0_PRSTCTL0_SET_AXI_SWITCH_SHIFT    (3U)
/*! AXI_SWITCH - AXI SWITCH reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_AXI_SWITCH(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_AXI_SWITCH_SHIFT)) & RSTCTL0_PRSTCTL0_SET_AXI_SWITCH_MASK)

#define RSTCTL0_PRSTCTL0_SET_POWERQUAD_MASK      (0x100U)
#define RSTCTL0_PRSTCTL0_SET_POWERQUAD_SHIFT     (8U)
/*! POWERQUAD - POWERQUAD reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_POWERQUAD(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_POWERQUAD_SHIFT)) & RSTCTL0_PRSTCTL0_SET_POWERQUAD_MASK)

#define RSTCTL0_PRSTCTL0_SET_CASPER_MASK         (0x200U)
#define RSTCTL0_PRSTCTL0_SET_CASPER_SHIFT        (9U)
/*! CASPER - CASPER reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_CASPER(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_CASPER_SHIFT)) & RSTCTL0_PRSTCTL0_SET_CASPER_MASK)

#define RSTCTL0_PRSTCTL0_SET_HASHCRYPT_MASK      (0x400U)
#define RSTCTL0_PRSTCTL0_SET_HASHCRYPT_SHIFT     (10U)
/*! HASHCRYPT - HASHCRYPT reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_HASHCRYPT(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_HASHCRYPT_SHIFT)) & RSTCTL0_PRSTCTL0_SET_HASHCRYPT_MASK)

#define RSTCTL0_PRSTCTL0_SET_PUF_MASK            (0x800U)
#define RSTCTL0_PRSTCTL0_SET_PUF_SHIFT           (11U)
/*! PUF - PUF reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_PUF(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_PUF_SHIFT)) & RSTCTL0_PRSTCTL0_SET_PUF_MASK)

#define RSTCTL0_PRSTCTL0_SET_RNG_MASK            (0x1000U)
#define RSTCTL0_PRSTCTL0_SET_RNG_SHIFT           (12U)
/*! RNG - RNG reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_RNG(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_RNG_SHIFT)) & RSTCTL0_PRSTCTL0_SET_RNG_MASK)

#define RSTCTL0_PRSTCTL0_SET_FLEXSPI0_OTFAD_MASK (0x10000U)
#define RSTCTL0_PRSTCTL0_SET_FLEXSPI0_OTFAD_SHIFT (16U)
/*! FLEXSPI0_OTFAD - FLEXSPI0 and OTFAD reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_FLEXSPI0_OTFAD(x)   (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_FLEXSPI0_OTFAD_SHIFT)) & RSTCTL0_PRSTCTL0_SET_FLEXSPI0_OTFAD_MASK)

#define RSTCTL0_PRSTCTL0_SET_FLEXSPI1_MASK       (0x40000U)
#define RSTCTL0_PRSTCTL0_SET_FLEXSPI1_SHIFT      (18U)
/*! FLEXSPI1 - FLEXSPI1 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_FLEXSPI1(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_FLEXSPI1_SHIFT)) & RSTCTL0_PRSTCTL0_SET_FLEXSPI1_MASK)

#define RSTCTL0_PRSTCTL0_SET_USBHS_PHY_MASK      (0x100000U)
#define RSTCTL0_PRSTCTL0_SET_USBHS_PHY_SHIFT     (20U)
/*! USBHS_PHY - USB PHY reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_USBHS_PHY(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_USBHS_PHY_SHIFT)) & RSTCTL0_PRSTCTL0_SET_USBHS_PHY_MASK)

#define RSTCTL0_PRSTCTL0_SET_USBHS_DEVICE_MASK   (0x200000U)
#define RSTCTL0_PRSTCTL0_SET_USBHS_DEVICE_SHIFT  (21U)
/*! USBHS_DEVICE - USB Device reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_USBHS_DEVICE(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_USBHS_DEVICE_SHIFT)) & RSTCTL0_PRSTCTL0_SET_USBHS_DEVICE_MASK)

#define RSTCTL0_PRSTCTL0_SET_USBHS_HOST_MASK     (0x400000U)
#define RSTCTL0_PRSTCTL0_SET_USBHS_HOST_SHIFT    (22U)
/*! USBHS_HOST - USB HOST reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_USBHS_HOST(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_USBHS_HOST_SHIFT)) & RSTCTL0_PRSTCTL0_SET_USBHS_HOST_MASK)

#define RSTCTL0_PRSTCTL0_SET_USBHS_SRAM_MASK     (0x800000U)
#define RSTCTL0_PRSTCTL0_SET_USBHS_SRAM_SHIFT    (23U)
/*! USBHS_SRAM - USBHS SRAM reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_USBHS_SRAM(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_USBHS_SRAM_SHIFT)) & RSTCTL0_PRSTCTL0_SET_USBHS_SRAM_MASK)

#define RSTCTL0_PRSTCTL0_SET_SCT_MASK            (0x1000000U)
#define RSTCTL0_PRSTCTL0_SET_SCT_SHIFT           (24U)
/*! SCT - SCTimer reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_SCT(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_SCT_SHIFT)) & RSTCTL0_PRSTCTL0_SET_SCT_MASK)

#define RSTCTL0_PRSTCTL0_SET_GPU_MASK            (0x4000000U)
#define RSTCTL0_PRSTCTL0_SET_GPU_SHIFT           (26U)
/*! GPU - GPU reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_GPU(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_GPU_SHIFT)) & RSTCTL0_PRSTCTL0_SET_GPU_MASK)

#define RSTCTL0_PRSTCTL0_SET_DISPLAY_CONTROLLER_MASK (0x8000000U)
#define RSTCTL0_PRSTCTL0_SET_DISPLAY_CONTROLLER_SHIFT (27U)
/*! DISPLAY_CONTROLLER - LCDIF DISPLAY CONTROLLER reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_DISPLAY_CONTROLLER(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_DISPLAY_CONTROLLER_SHIFT)) & RSTCTL0_PRSTCTL0_SET_DISPLAY_CONTROLLER_MASK)

#define RSTCTL0_PRSTCTL0_SET_MIPI_DSI_CONTROLLER_MASK (0x10000000U)
#define RSTCTL0_PRSTCTL0_SET_MIPI_DSI_CONTROLLER_SHIFT (28U)
/*! MIPI_DSI_CONTROLLER - MIPI DSI controller reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_MIPI_DSI_CONTROLLER(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_MIPI_DSI_CONTROLLER_SHIFT)) & RSTCTL0_PRSTCTL0_SET_MIPI_DSI_CONTROLLER_MASK)

#define RSTCTL0_PRSTCTL0_SET_MIPI_DSI_PHY_MASK   (0x20000000U)
#define RSTCTL0_PRSTCTL0_SET_MIPI_DSI_PHY_SHIFT  (29U)
/*! MIPI_DSI_PHY - MIPI DSI PHY reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_MIPI_DSI_PHY(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_MIPI_DSI_PHY_SHIFT)) & RSTCTL0_PRSTCTL0_SET_MIPI_DSI_PHY_MASK)

#define RSTCTL0_PRSTCTL0_SET_SMARTDMA_MASK       (0x40000000U)
#define RSTCTL0_PRSTCTL0_SET_SMARTDMA_SHIFT      (30U)
/*! SMARTDMA - SMARTDMA Event/Algorithm handler reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_SMARTDMA(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_SMARTDMA_SHIFT)) & RSTCTL0_PRSTCTL0_SET_SMARTDMA_MASK)
/*! @} */

/*! @name PRSTCTL1_SET - Peripheral Reset Control Register 1 SET */
/*! @{ */

#define RSTCTL0_PRSTCTL1_SET_SDIO0_MASK          (0x4U)
#define RSTCTL0_PRSTCTL1_SET_SDIO0_SHIFT         (2U)
/*! SDIO0 - SDIO0 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_SET_SDIO0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SET_SDIO0_SHIFT)) & RSTCTL0_PRSTCTL1_SET_SDIO0_MASK)

#define RSTCTL0_PRSTCTL1_SET_SDIO1_MASK          (0x8U)
#define RSTCTL0_PRSTCTL1_SET_SDIO1_SHIFT         (3U)
/*! SDIO1 - SDIO1 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_SET_SDIO1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SET_SDIO1_SHIFT)) & RSTCTL0_PRSTCTL1_SET_SDIO1_MASK)

#define RSTCTL0_PRSTCTL1_SET_ACMP0_MASK          (0x8000U)
#define RSTCTL0_PRSTCTL1_SET_ACMP0_SHIFT         (15U)
/*! ACMP0 - ACMP0 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_SET_ACMP0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SET_ACMP0_SHIFT)) & RSTCTL0_PRSTCTL1_SET_ACMP0_MASK)

#define RSTCTL0_PRSTCTL1_SET_ADC0_MASK           (0x10000U)
#define RSTCTL0_PRSTCTL1_SET_ADC0_SHIFT          (16U)
/*! ADC0 - ADC0 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_SET_ADC0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SET_ADC0_SHIFT)) & RSTCTL0_PRSTCTL1_SET_ADC0_MASK)

#define RSTCTL0_PRSTCTL1_SET_SHSGPIO0_MASK       (0x1000000U)
#define RSTCTL0_PRSTCTL1_SET_SHSGPIO0_SHIFT      (24U)
/*! SHSGPIO0 - SHSGPIO0 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_SET_SHSGPIO0(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SET_SHSGPIO0_SHIFT)) & RSTCTL0_PRSTCTL1_SET_SHSGPIO0_MASK)
/*! @} */

/*! @name PRSTCTL2_SET - Peripheral Reset Control Register 2 SET */
/*! @{ */

#define RSTCTL0_PRSTCTL2_SET_UTICK0_MASK         (0x1U)
#define RSTCTL0_PRSTCTL2_SET_UTICK0_SHIFT        (0U)
/*! UTICK0 - Micro-tick timer 0 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL0_PRSTCTL2_SET_UTICK0(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_UTICK0_SHIFT)) & RSTCTL0_PRSTCTL2_SET_UTICK0_MASK)

#define RSTCTL0_PRSTCTL2_SET_WWDT0_MASK          (0x2U)
#define RSTCTL0_PRSTCTL2_SET_WWDT0_SHIFT         (1U)
/*! WWDT0 - WWDT0 reset set
 *  0b0..No effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL0_PRSTCTL2_SET_WWDT0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_WWDT0_SHIFT)) & RSTCTL0_PRSTCTL2_SET_WWDT0_MASK)
/*! @} */

/*! @name PRSTCTL0_CLR - Peripheral Reset Control Register 0 CLR */
/*! @{ */

#define RSTCTL0_PRSTCTL0_CLR_DSP_MASK            (0x2U)
#define RSTCTL0_PRSTCTL0_CLR_DSP_SHIFT           (1U)
/*! DSP
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_DSP(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_DSP_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_DSP_MASK)

#define RSTCTL0_PRSTCTL0_CLR_AXI_SWITCH_MASK     (0x8U)
#define RSTCTL0_PRSTCTL0_CLR_AXI_SWITCH_SHIFT    (3U)
/*! AXI_SWITCH - AXI SWITCH reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_AXI_SWITCH(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_AXI_SWITCH_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_AXI_SWITCH_MASK)

#define RSTCTL0_PRSTCTL0_CLR_POWERQUAD_MASK      (0x100U)
#define RSTCTL0_PRSTCTL0_CLR_POWERQUAD_SHIFT     (8U)
/*! POWERQUAD - POWERQUAD reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_POWERQUAD(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_POWERQUAD_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_POWERQUAD_MASK)

#define RSTCTL0_PRSTCTL0_CLR_CASPER_MASK         (0x200U)
#define RSTCTL0_PRSTCTL0_CLR_CASPER_SHIFT        (9U)
/*! CASPER - CASPER reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_CASPER(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_CASPER_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_CASPER_MASK)

#define RSTCTL0_PRSTCTL0_CLR_HASHCRYPT_MASK      (0x400U)
#define RSTCTL0_PRSTCTL0_CLR_HASHCRYPT_SHIFT     (10U)
/*! HASHCRYPT - HASHCRYPT reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_HASHCRYPT(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_HASHCRYPT_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_HASHCRYPT_MASK)

#define RSTCTL0_PRSTCTL0_CLR_PUF_MASK            (0x800U)
#define RSTCTL0_PRSTCTL0_CLR_PUF_SHIFT           (11U)
/*! PUF - PUF reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_PUF(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_PUF_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_PUF_MASK)

#define RSTCTL0_PRSTCTL0_CLR_RNG_MASK            (0x1000U)
#define RSTCTL0_PRSTCTL0_CLR_RNG_SHIFT           (12U)
/*! RNG - RNG reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_RNG(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_RNG_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_RNG_MASK)

#define RSTCTL0_PRSTCTL0_CLR_FLEXSPI0_OTFAD_MASK (0x10000U)
#define RSTCTL0_PRSTCTL0_CLR_FLEXSPI0_OTFAD_SHIFT (16U)
/*! FLEXSPI0_OTFAD - FLEXSPI0 and OTFAD reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_FLEXSPI0_OTFAD(x)   (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_FLEXSPI0_OTFAD_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_FLEXSPI0_OTFAD_MASK)

#define RSTCTL0_PRSTCTL0_CLR_FLEXSPI1_MASK       (0x40000U)
#define RSTCTL0_PRSTCTL0_CLR_FLEXSPI1_SHIFT      (18U)
/*! FLEXSPI1 - FLEXSPI1 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_FLEXSPI1(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_FLEXSPI1_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_FLEXSPI1_MASK)

#define RSTCTL0_PRSTCTL0_CLR_USBHS_PHY_MASK      (0x100000U)
#define RSTCTL0_PRSTCTL0_CLR_USBHS_PHY_SHIFT     (20U)
/*! USBHS_PHY - USB PHY reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_USBHS_PHY(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_USBHS_PHY_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_USBHS_PHY_MASK)

#define RSTCTL0_PRSTCTL0_CLR_USBHS_DEVICE_MASK   (0x200000U)
#define RSTCTL0_PRSTCTL0_CLR_USBHS_DEVICE_SHIFT  (21U)
/*! USBHS_DEVICE - USB DEVICE reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_USBHS_DEVICE(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_USBHS_DEVICE_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_USBHS_DEVICE_MASK)

#define RSTCTL0_PRSTCTL0_CLR_USBHS_HOST_MASK     (0x400000U)
#define RSTCTL0_PRSTCTL0_CLR_USBHS_HOST_SHIFT    (22U)
/*! USBHS_HOST - USB HOST reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_USBHS_HOST(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_USBHS_HOST_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_USBHS_HOST_MASK)

#define RSTCTL0_PRSTCTL0_CLR_USBHS_SRAM_MASK     (0x800000U)
#define RSTCTL0_PRSTCTL0_CLR_USBHS_SRAM_SHIFT    (23U)
/*! USBHS_SRAM - USBHS SRAM reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_USBHS_SRAM(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_USBHS_SRAM_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_USBHS_SRAM_MASK)

#define RSTCTL0_PRSTCTL0_CLR_SCT_MASK            (0x1000000U)
#define RSTCTL0_PRSTCTL0_CLR_SCT_SHIFT           (24U)
/*! SCT - SCT reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_SCT(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_SCT_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_SCT_MASK)

#define RSTCTL0_PRSTCTL0_CLR_GPU_MASK            (0x4000000U)
#define RSTCTL0_PRSTCTL0_CLR_GPU_SHIFT           (26U)
/*! GPU - GPU reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_GPU(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_GPU_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_GPU_MASK)

#define RSTCTL0_PRSTCTL0_CLR_DISPLAY_CONTROLLER_MASK (0x8000000U)
#define RSTCTL0_PRSTCTL0_CLR_DISPLAY_CONTROLLER_SHIFT (27U)
/*! DISPLAY_CONTROLLER - LCDIF DISPLAY CONTROLLER reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_DISPLAY_CONTROLLER(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_DISPLAY_CONTROLLER_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_DISPLAY_CONTROLLER_MASK)

#define RSTCTL0_PRSTCTL0_CLR_MIPI_DSI_CONTROLLER_MASK (0x10000000U)
#define RSTCTL0_PRSTCTL0_CLR_MIPI_DSI_CONTROLLER_SHIFT (28U)
/*! MIPI_DSI_CONTROLLER - MIPI DSI controller reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_MIPI_DSI_CONTROLLER(x) (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_MIPI_DSI_CONTROLLER_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_MIPI_DSI_CONTROLLER_MASK)

#define RSTCTL0_PRSTCTL0_CLR_MIPI_DSI_PHY_MASK   (0x20000000U)
#define RSTCTL0_PRSTCTL0_CLR_MIPI_DSI_PHY_SHIFT  (29U)
/*! MIPI_DSI_PHY - MIPI DSI PHY reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_MIPI_DSI_PHY(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_MIPI_DSI_PHY_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_MIPI_DSI_PHY_MASK)

#define RSTCTL0_PRSTCTL0_CLR_SMARTDMA_MASK       (0x40000000U)
#define RSTCTL0_PRSTCTL0_CLR_SMARTDMA_SHIFT      (30U)
/*! SMARTDMA - SMARTDMA Event/Algorithm handler reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_SMARTDMA(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_SMARTDMA_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_SMARTDMA_MASK)
/*! @} */

/*! @name PRSTCTL1_CLR - Peripheral Reset Control Register 1 CLR */
/*! @{ */

#define RSTCTL0_PRSTCTL1_CLR_SDIO0_MASK          (0x4U)
#define RSTCTL0_PRSTCTL1_CLR_SDIO0_SHIFT         (2U)
/*! SDIO0 - SDIO0 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_CLR_SDIO0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_CLR_SDIO0_SHIFT)) & RSTCTL0_PRSTCTL1_CLR_SDIO0_MASK)

#define RSTCTL0_PRSTCTL1_CLR_SDIO1_MASK          (0x8U)
#define RSTCTL0_PRSTCTL1_CLR_SDIO1_SHIFT         (3U)
/*! SDIO1 - SDIO1 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_CLR_SDIO1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_CLR_SDIO1_SHIFT)) & RSTCTL0_PRSTCTL1_CLR_SDIO1_MASK)

#define RSTCTL0_PRSTCTL1_CLR_ACMP0_MASK          (0x8000U)
#define RSTCTL0_PRSTCTL1_CLR_ACMP0_SHIFT         (15U)
/*! ACMP0 - ACMP0 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_CLR_ACMP0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_CLR_ACMP0_SHIFT)) & RSTCTL0_PRSTCTL1_CLR_ACMP0_MASK)

#define RSTCTL0_PRSTCTL1_CLR_ADC0_MASK           (0x10000U)
#define RSTCTL0_PRSTCTL1_CLR_ADC0_SHIFT          (16U)
/*! ADC0 - ADC0 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_CLR_ADC0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_CLR_ADC0_SHIFT)) & RSTCTL0_PRSTCTL1_CLR_ADC0_MASK)

#define RSTCTL0_PRSTCTL1_CLR_SHSGPIO0_MASK       (0x1000000U)
#define RSTCTL0_PRSTCTL1_CLR_SHSGPIO0_SHIFT      (24U)
/*! SHSGPIO0 - Secure HSGPIO0 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_CLR_SHSGPIO0(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_CLR_SHSGPIO0_SHIFT)) & RSTCTL0_PRSTCTL1_CLR_SHSGPIO0_MASK)
/*! @} */

/*! @name PRSTCTL2_CLR - Peripheral Reset Control Register 2 CLR */
/*! @{ */

#define RSTCTL0_PRSTCTL2_CLR_UTICK0_MASK         (0x1U)
#define RSTCTL0_PRSTCTL2_CLR_UTICK0_SHIFT        (0U)
/*! UTICK0 - Micro-tick timer 0 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL2 Bit
 */
#define RSTCTL0_PRSTCTL2_CLR_UTICK0(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_UTICK0_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_UTICK0_MASK)

#define RSTCTL0_PRSTCTL2_CLR_WWDT0_MASK          (0x2U)
#define RSTCTL0_PRSTCTL2_CLR_WWDT0_SHIFT         (1U)
/*! WWDT0 - WWDT0 reset clear
 *  0b0..No effect
 *  0b1..Clears the PRSTCTL2 Bit
 */
#define RSTCTL0_PRSTCTL2_CLR_WWDT0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_WWDT0_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_WWDT0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RSTCTL0_Register_Masks */


/*!
 * @}
 */ /* end of group RSTCTL0_Peripheral_Access_Layer */


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


#endif  /* PERI_RSTCTL0_H_ */

