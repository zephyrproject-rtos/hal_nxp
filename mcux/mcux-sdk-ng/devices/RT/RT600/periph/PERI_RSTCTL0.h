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
 * @file PERI_RSTCTL0.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RSTCTL0
 *
 * CMSIS Peripheral Access Layer for RSTCTL0
 */

#if !defined(PERI_RSTCTL0_H_)
#define PERI_RSTCTL0_H_                          /**< Symbol preventing repeated inclusion */

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
   -- RSTCTL0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL0_Peripheral_Access_Layer RSTCTL0 Peripheral Access Layer
 * @{
 */

/** RSTCTL0 - Register Layout Typedef */
typedef struct {
  __IO uint32_t SYSRSTSTAT;                        /**< system reset status register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t PRSTCTL0;                          /**< peripheral reset control register 0, offset: 0x10 */
  __IO uint32_t PRSTCTL1;                          /**< peripheral reset control register 1, offset: 0x14 */
  __IO uint32_t PRSTCTL2;                          /**< peripheral reset control register 2, offset: 0x18 */
       uint8_t RESERVED_1[36];
  __O  uint32_t PRSTCTL0_SET;                      /**< peripheral reset set register 0, offset: 0x40 */
  __O  uint32_t PRSTCTL1_SET;                      /**< peripheral reset set register 1, offset: 0x44 */
  __O  uint32_t PRSTCTL2_SET;                      /**< peripheral reset set register 2, offset: 0x48 */
       uint8_t RESERVED_2[36];
  __O  uint32_t PRSTCTL0_CLR;                      /**< peripheral reset clear register 0, offset: 0x70 */
  __O  uint32_t PRSTCTL1_CLR;                      /**< peripheral reset clear register 1, offset: 0x74 */
  __O  uint32_t PRSTCTL2_CLR;                      /**< peripheral reset clear register 2, offset: 0x78 */
} RSTCTL0_Type;

/* ----------------------------------------------------------------------------
   -- RSTCTL0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL0_Register_Masks RSTCTL0 Register Masks
 * @{
 */

/*! @name SYSRSTSTAT - system reset status register */
/*! @{ */

#define RSTCTL0_SYSRSTSTAT_VDD_POR_MASK          (0x1U)
#define RSTCTL0_SYSRSTSTAT_VDD_POR_SHIFT         (0U)
/*! VDD_POR - VDD POR Event Detected:
 *  0b0..No event detected.
 *  0b1..VDD POR event detected. (Writing a '1' to this bit clears this status).
 */
#define RSTCTL0_SYSRSTSTAT_VDD_POR(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_SYSRSTSTAT_VDD_POR_SHIFT)) & RSTCTL0_SYSRSTSTAT_VDD_POR_MASK)

#define RSTCTL0_SYSRSTSTAT_PAD_RESET_MASK        (0x10U)
#define RSTCTL0_SYSRSTSTAT_PAD_RESET_SHIFT       (4U)
/*! PAD_RESET - PAD RESET Event Detected:
 *  0b0..No EVENT Detected.
 *  0b1..RESET Detected. (Write 1 to CLR),
 */
#define RSTCTL0_SYSRSTSTAT_PAD_RESET(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_SYSRSTSTAT_PAD_RESET_SHIFT)) & RSTCTL0_SYSRSTSTAT_PAD_RESET_MASK)

#define RSTCTL0_SYSRSTSTAT_ARM_APD_RESET_MASK    (0x20U)
#define RSTCTL0_SYSRSTSTAT_ARM_APD_RESET_SHIFT   (5U)
/*! ARM_APD_RESET - ARM RESET Event Detected:
 *  0b0..No event detected.
 *  0b1..ARM reset event detected. (Writing a '1' to this bit clears this status).
 */
#define RSTCTL0_SYSRSTSTAT_ARM_APD_RESET(x)      (((uint32_t)(((uint32_t)(x)) << RSTCTL0_SYSRSTSTAT_ARM_APD_RESET_SHIFT)) & RSTCTL0_SYSRSTSTAT_ARM_APD_RESET_MASK)

#define RSTCTL0_SYSRSTSTAT_WDT0_RESET_MASK       (0x40U)
#define RSTCTL0_SYSRSTSTAT_WDT0_RESET_SHIFT      (6U)
/*! WDT0_RESET - WDT0 RESET Event Detected:
 *  0b0..No EVENT Detected.
 *  0b1..WDT0 reset event detected. (Writing a '1' to this bit clears this status).
 */
#define RSTCTL0_SYSRSTSTAT_WDT0_RESET(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_SYSRSTSTAT_WDT0_RESET_SHIFT)) & RSTCTL0_SYSRSTSTAT_WDT0_RESET_MASK)

#define RSTCTL0_SYSRSTSTAT_WDT1_RESET_MASK       (0x80U)
#define RSTCTL0_SYSRSTSTAT_WDT1_RESET_SHIFT      (7U)
/*! WDT1_RESET - WDT1 RESET Event Detected:
 *  0b0..No EVENT Detected.
 *  0b1..WDT1 reset event detected. (Writing a 1 to this bit clears this status).
 */
#define RSTCTL0_SYSRSTSTAT_WDT1_RESET(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_SYSRSTSTAT_WDT1_RESET_SHIFT)) & RSTCTL0_SYSRSTSTAT_WDT1_RESET_MASK)
/*! @} */

/*! @name PRSTCTL0 - peripheral reset control register 0 */
/*! @{ */

#define RSTCTL0_PRSTCTL0_HIFI_DSP_MASK           (0x2U)
#define RSTCTL0_PRSTCTL0_HIFI_DSP_SHIFT          (1U)
/*! HIFI_DSP - HIFI DSP reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL0_HIFI_DSP(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_HIFI_DSP_SHIFT)) & RSTCTL0_PRSTCTL0_HIFI_DSP_MASK)

#define RSTCTL0_PRSTCTL0_POWERQUAD_MASK          (0x100U)
#define RSTCTL0_PRSTCTL0_POWERQUAD_SHIFT         (8U)
/*! POWERQUAD - powerquad reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL0_POWERQUAD(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_POWERQUAD_SHIFT)) & RSTCTL0_PRSTCTL0_POWERQUAD_MASK)

#define RSTCTL0_PRSTCTL0_CASPER_MASK             (0x200U)
#define RSTCTL0_PRSTCTL0_CASPER_SHIFT            (9U)
/*! CASPER - CAPSER reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL0_CASPER(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CASPER_SHIFT)) & RSTCTL0_PRSTCTL0_CASPER_MASK)

#define RSTCTL0_PRSTCTL0_HASHCRYPT_MASK          (0x400U)
#define RSTCTL0_PRSTCTL0_HASHCRYPT_SHIFT         (10U)
/*! HASHCRYPT - HASHCRYPT reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL0_HASHCRYPT(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_HASHCRYPT_SHIFT)) & RSTCTL0_PRSTCTL0_HASHCRYPT_MASK)

#define RSTCTL0_PRSTCTL0_PUF_MASK                (0x800U)
#define RSTCTL0_PRSTCTL0_PUF_SHIFT               (11U)
/*! PUF - PUF reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL0_PUF(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_PUF_SHIFT)) & RSTCTL0_PRSTCTL0_PUF_MASK)

#define RSTCTL0_PRSTCTL0_RNG_MASK                (0x1000U)
#define RSTCTL0_PRSTCTL0_RNG_SHIFT               (12U)
/*! RNG - RNG reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL0_RNG(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_RNG_SHIFT)) & RSTCTL0_PRSTCTL0_RNG_MASK)

#define RSTCTL0_PRSTCTL0_FLEXSPI_OTFAD_MASK      (0x10000U)
#define RSTCTL0_PRSTCTL0_FLEXSPI_OTFAD_SHIFT     (16U)
/*! FLEXSPI_OTFAD - FLEXSPI reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL0_FLEXSPI_OTFAD(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_FLEXSPI_OTFAD_SHIFT)) & RSTCTL0_PRSTCTL0_FLEXSPI_OTFAD_MASK)

#define RSTCTL0_PRSTCTL0_USBHS_PHY_MASK          (0x100000U)
#define RSTCTL0_PRSTCTL0_USBHS_PHY_SHIFT         (20U)
/*! USBHS_PHY - USB PHY reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL0_USBHS_PHY(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_USBHS_PHY_SHIFT)) & RSTCTL0_PRSTCTL0_USBHS_PHY_MASK)

#define RSTCTL0_PRSTCTL0_USBHS_DEVICE_MASK       (0x200000U)
#define RSTCTL0_PRSTCTL0_USBHS_DEVICE_SHIFT      (21U)
/*! USBHS_DEVICE - USB DEVICE reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL0_USBHS_DEVICE(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_USBHS_DEVICE_SHIFT)) & RSTCTL0_PRSTCTL0_USBHS_DEVICE_MASK)

#define RSTCTL0_PRSTCTL0_USBHS_HOST_MASK         (0x400000U)
#define RSTCTL0_PRSTCTL0_USBHS_HOST_SHIFT        (22U)
/*! USBHS_HOST - USB HOST reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL0_USBHS_HOST(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_USBHS_HOST_SHIFT)) & RSTCTL0_PRSTCTL0_USBHS_HOST_MASK)

#define RSTCTL0_PRSTCTL0_USBHS_SRAM_MASK         (0x800000U)
#define RSTCTL0_PRSTCTL0_USBHS_SRAM_SHIFT        (23U)
/*! USBHS_SRAM - USBHS RAM reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL0_USBHS_SRAM(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_USBHS_SRAM_SHIFT)) & RSTCTL0_PRSTCTL0_USBHS_SRAM_MASK)

#define RSTCTL0_PRSTCTL0_SCT_MASK                (0x1000000U)
#define RSTCTL0_PRSTCTL0_SCT_SHIFT               (24U)
/*! SCT - SCT reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL0_SCT(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SCT_SHIFT)) & RSTCTL0_PRSTCTL0_SCT_MASK)
/*! @} */

/*! @name PRSTCTL1 - peripheral reset control register 1 */
/*! @{ */

#define RSTCTL0_PRSTCTL1_SDIO0_MASK              (0x4U)
#define RSTCTL0_PRSTCTL1_SDIO0_SHIFT             (2U)
/*! SDIO0 - SDIO0 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL1_SDIO0(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SDIO0_SHIFT)) & RSTCTL0_PRSTCTL1_SDIO0_MASK)

#define RSTCTL0_PRSTCTL1_SDIO1_MASK              (0x8U)
#define RSTCTL0_PRSTCTL1_SDIO1_SHIFT             (3U)
/*! SDIO1 - SDIO1 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL1_SDIO1(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SDIO1_SHIFT)) & RSTCTL0_PRSTCTL1_SDIO1_MASK)

#define RSTCTL0_PRSTCTL1_ACMP0_MASK              (0x8000U)
#define RSTCTL0_PRSTCTL1_ACMP0_SHIFT             (15U)
/*! ACMP0 - Analog comparator reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL1_ACMP0(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_ACMP0_SHIFT)) & RSTCTL0_PRSTCTL1_ACMP0_MASK)

#define RSTCTL0_PRSTCTL1_ADC0_MASK               (0x10000U)
#define RSTCTL0_PRSTCTL1_ADC0_SHIFT              (16U)
/*! ADC0 - ADC reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL1_ADC0(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_ADC0_SHIFT)) & RSTCTL0_PRSTCTL1_ADC0_MASK)

#define RSTCTL0_PRSTCTL1_SHSGPIO0_MASK           (0x1000000U)
#define RSTCTL0_PRSTCTL1_SHSGPIO0_SHIFT          (24U)
/*! SHSGPIO0 - SHSGPIO0 reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL1_SHSGPIO0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SHSGPIO0_SHIFT)) & RSTCTL0_PRSTCTL1_SHSGPIO0_MASK)
/*! @} */

/*! @name PRSTCTL2 - peripheral reset control register 2 */
/*! @{ */

#define RSTCTL0_PRSTCTL2_UTICK0_MASK             (0x1U)
#define RSTCTL0_PRSTCTL2_UTICK0_SHIFT            (0U)
/*! UTICK0 - utick reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL2_UTICK0(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_UTICK0_SHIFT)) & RSTCTL0_PRSTCTL2_UTICK0_MASK)

#define RSTCTL0_PRSTCTL2_WWDT0_MASK              (0x2U)
#define RSTCTL0_PRSTCTL2_WWDT0_SHIFT             (1U)
/*! WWDT0 - wdt reset control
 *  0b0..clear reset
 *  0b1..set reset
 */
#define RSTCTL0_PRSTCTL2_WWDT0(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_WWDT0_SHIFT)) & RSTCTL0_PRSTCTL2_WWDT0_MASK)
/*! @} */

/*! @name PRSTCTL0_SET - peripheral reset set register 0 */
/*! @{ */

#define RSTCTL0_PRSTCTL0_SET_HIFI_DSP_MASK       (0x2U)
#define RSTCTL0_PRSTCTL0_SET_HIFI_DSP_SHIFT      (1U)
/*! HIFI_DSP - HIFI DSP reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_HIFI_DSP(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_HIFI_DSP_SHIFT)) & RSTCTL0_PRSTCTL0_SET_HIFI_DSP_MASK)

#define RSTCTL0_PRSTCTL0_SET_POWERQUAD_MASK      (0x100U)
#define RSTCTL0_PRSTCTL0_SET_POWERQUAD_SHIFT     (8U)
/*! POWERQUAD - powerquad reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_POWERQUAD(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_POWERQUAD_SHIFT)) & RSTCTL0_PRSTCTL0_SET_POWERQUAD_MASK)

#define RSTCTL0_PRSTCTL0_SET_CASPER_MASK         (0x200U)
#define RSTCTL0_PRSTCTL0_SET_CASPER_SHIFT        (9U)
/*! CASPER - CAPSER reset set
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

#define RSTCTL0_PRSTCTL0_SET_FLEXSPI_OTFAD_MASK  (0x10000U)
#define RSTCTL0_PRSTCTL0_SET_FLEXSPI_OTFAD_SHIFT (16U)
/*! FLEXSPI_OTFAD - FLEXSPI reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_FLEXSPI_OTFAD(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_FLEXSPI_OTFAD_SHIFT)) & RSTCTL0_PRSTCTL0_SET_FLEXSPI_OTFAD_MASK)

#define RSTCTL0_PRSTCTL0_SET_USBHS_PHY_MASK      (0x100000U)
#define RSTCTL0_PRSTCTL0_SET_USBHS_PHY_SHIFT     (20U)
/*! USBHS_PHY - USB PHY reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_USBHS_PHY(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_USBHS_PHY_SHIFT)) & RSTCTL0_PRSTCTL0_SET_USBHS_PHY_MASK)

#define RSTCTL0_PRSTCTL0_SET_USBHS_DEVICE_MASK   (0x200000U)
#define RSTCTL0_PRSTCTL0_SET_USBHS_DEVICE_SHIFT  (21U)
/*! USBHS_DEVICE - USB DEVICE reset set
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
/*! USBHS_SRAM - USBHS RAM reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_USBHS_SRAM(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_USBHS_SRAM_SHIFT)) & RSTCTL0_PRSTCTL0_SET_USBHS_SRAM_MASK)

#define RSTCTL0_PRSTCTL0_SET_SCT_MASK            (0x1000000U)
#define RSTCTL0_PRSTCTL0_SET_SCT_SHIFT           (24U)
/*! SCT - SCT reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_SET_SCT(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_SCT_SHIFT)) & RSTCTL0_PRSTCTL0_SET_SCT_MASK)
/*! @} */

/*! @name PRSTCTL1_SET - peripheral reset set register 1 */
/*! @{ */

#define RSTCTL0_PRSTCTL1_SET_SDIO0_MASK          (0x4U)
#define RSTCTL0_PRSTCTL1_SET_SDIO0_SHIFT         (2U)
/*! SDIO0 - SDIO0 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_SET_SDIO0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SET_SDIO0_SHIFT)) & RSTCTL0_PRSTCTL1_SET_SDIO0_MASK)

#define RSTCTL0_PRSTCTL1_SET_SDIO1_MASK          (0x8U)
#define RSTCTL0_PRSTCTL1_SET_SDIO1_SHIFT         (3U)
/*! SDIO1 - SDIO1 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_SET_SDIO1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SET_SDIO1_SHIFT)) & RSTCTL0_PRSTCTL1_SET_SDIO1_MASK)

#define RSTCTL0_PRSTCTL1_SET_ACMP0_MASK          (0x8000U)
#define RSTCTL0_PRSTCTL1_SET_ACMP0_SHIFT         (15U)
/*! ACMP0 - Analog comparator reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_SET_ACMP0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SET_ACMP0_SHIFT)) & RSTCTL0_PRSTCTL1_SET_ACMP0_MASK)

#define RSTCTL0_PRSTCTL1_SET_ADC0_MASK           (0x10000U)
#define RSTCTL0_PRSTCTL1_SET_ADC0_SHIFT          (16U)
/*! ADC0 - ADC reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_SET_ADC0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SET_ADC0_SHIFT)) & RSTCTL0_PRSTCTL1_SET_ADC0_MASK)

#define RSTCTL0_PRSTCTL1_SET_SHSGPIO0_MASK       (0x1000000U)
#define RSTCTL0_PRSTCTL1_SET_SHSGPIO0_SHIFT      (24U)
/*! SHSGPIO0 - SHSGPIO0 reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_SET_SHSGPIO0(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SET_SHSGPIO0_SHIFT)) & RSTCTL0_PRSTCTL1_SET_SHSGPIO0_MASK)
/*! @} */

/*! @name PRSTCTL2_SET - peripheral reset set register 2 */
/*! @{ */

#define RSTCTL0_PRSTCTL2_SET_UTICK0_MASK         (0x1U)
#define RSTCTL0_PRSTCTL2_SET_UTICK0_SHIFT        (0U)
/*! UTICK0 - utick reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL0_PRSTCTL2_SET_UTICK0(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_UTICK0_SHIFT)) & RSTCTL0_PRSTCTL2_SET_UTICK0_MASK)

#define RSTCTL0_PRSTCTL2_SET_WWDT0_MASK          (0x2U)
#define RSTCTL0_PRSTCTL2_SET_WWDT0_SHIFT         (1U)
/*! WWDT0 - wdt reset set
 *  0b0..No Effect
 *  0b1..Sets the PRSTCTL2 Bit
 */
#define RSTCTL0_PRSTCTL2_SET_WWDT0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_WWDT0_SHIFT)) & RSTCTL0_PRSTCTL2_SET_WWDT0_MASK)
/*! @} */

/*! @name PRSTCTL0_CLR - peripheral reset clear register 0 */
/*! @{ */

#define RSTCTL0_PRSTCTL0_CLR_HIFI_DSP_MASK       (0x2U)
#define RSTCTL0_PRSTCTL0_CLR_HIFI_DSP_SHIFT      (1U)
/*! HIFI_DSP - HIFI DSP reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_HIFI_DSP(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_HIFI_DSP_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_HIFI_DSP_MASK)

#define RSTCTL0_PRSTCTL0_CLR_POWERQUAD_MASK      (0x100U)
#define RSTCTL0_PRSTCTL0_CLR_POWERQUAD_SHIFT     (8U)
/*! POWERQUAD - powerquad reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_POWERQUAD(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_POWERQUAD_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_POWERQUAD_MASK)

#define RSTCTL0_PRSTCTL0_CLR_CASPER_MASK         (0x200U)
#define RSTCTL0_PRSTCTL0_CLR_CASPER_SHIFT        (9U)
/*! CASPER - CAPSER reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_CASPER(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_CASPER_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_CASPER_MASK)

#define RSTCTL0_PRSTCTL0_CLR_HASHCRYPT_MASK      (0x400U)
#define RSTCTL0_PRSTCTL0_CLR_HASHCRYPT_SHIFT     (10U)
/*! HASHCRYPT - HASHCRYPT reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_HASHCRYPT(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_HASHCRYPT_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_HASHCRYPT_MASK)

#define RSTCTL0_PRSTCTL0_CLR_PUF_MASK            (0x800U)
#define RSTCTL0_PRSTCTL0_CLR_PUF_SHIFT           (11U)
/*! PUF - PUF reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_PUF(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_PUF_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_PUF_MASK)

#define RSTCTL0_PRSTCTL0_CLR_RNG_MASK            (0x1000U)
#define RSTCTL0_PRSTCTL0_CLR_RNG_SHIFT           (12U)
/*! RNG - RNG reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_RNG(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_RNG_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_RNG_MASK)

#define RSTCTL0_PRSTCTL0_CLR_FLEXSPI_OTFAD_MASK  (0x10000U)
#define RSTCTL0_PRSTCTL0_CLR_FLEXSPI_OTFAD_SHIFT (16U)
/*! FLEXSPI_OTFAD - FLEXSPI reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_FLEXSPI_OTFAD(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_FLEXSPI_OTFAD_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_FLEXSPI_OTFAD_MASK)

#define RSTCTL0_PRSTCTL0_CLR_USBHS_PHY_MASK      (0x100000U)
#define RSTCTL0_PRSTCTL0_CLR_USBHS_PHY_SHIFT     (20U)
/*! USBHS_PHY - USB PHY reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_USBHS_PHY(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_USBHS_PHY_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_USBHS_PHY_MASK)

#define RSTCTL0_PRSTCTL0_CLR_USBHS_DEVICE_MASK   (0x200000U)
#define RSTCTL0_PRSTCTL0_CLR_USBHS_DEVICE_SHIFT  (21U)
/*! USBHS_DEVICE - USB DEVICE reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_USBHS_DEVICE(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_USBHS_DEVICE_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_USBHS_DEVICE_MASK)

#define RSTCTL0_PRSTCTL0_CLR_USBHS_HOST_MASK     (0x400000U)
#define RSTCTL0_PRSTCTL0_CLR_USBHS_HOST_SHIFT    (22U)
/*! USBHS_HOST - USB HOST reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_USBHS_HOST(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_USBHS_HOST_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_USBHS_HOST_MASK)

#define RSTCTL0_PRSTCTL0_CLR_USBHS_SRAM_MASK     (0x800000U)
#define RSTCTL0_PRSTCTL0_CLR_USBHS_SRAM_SHIFT    (23U)
/*! USBHS_SRAM - USBHS RAM reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_USBHS_SRAM(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_USBHS_SRAM_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_USBHS_SRAM_MASK)

#define RSTCTL0_PRSTCTL0_CLR_SCT_MASK            (0x1000000U)
#define RSTCTL0_PRSTCTL0_CLR_SCT_SHIFT           (24U)
/*! SCT - SCT reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL0 Bit
 */
#define RSTCTL0_PRSTCTL0_CLR_SCT(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_SCT_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_SCT_MASK)
/*! @} */

/*! @name PRSTCTL1_CLR - peripheral reset clear register 1 */
/*! @{ */

#define RSTCTL0_PRSTCTL1_CLR_SDIO0_MASK          (0x4U)
#define RSTCTL0_PRSTCTL1_CLR_SDIO0_SHIFT         (2U)
/*! SDIO0 - SDIO0 reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_CLR_SDIO0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_CLR_SDIO0_SHIFT)) & RSTCTL0_PRSTCTL1_CLR_SDIO0_MASK)

#define RSTCTL0_PRSTCTL1_CLR_SDIO1_MASK          (0x8U)
#define RSTCTL0_PRSTCTL1_CLR_SDIO1_SHIFT         (3U)
/*! SDIO1 - SDIO1 reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_CLR_SDIO1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_CLR_SDIO1_SHIFT)) & RSTCTL0_PRSTCTL1_CLR_SDIO1_MASK)

#define RSTCTL0_PRSTCTL1_CLR_ACMP0_MASK          (0x8000U)
#define RSTCTL0_PRSTCTL1_CLR_ACMP0_SHIFT         (15U)
/*! ACMP0 - Analog comparator reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_CLR_ACMP0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_CLR_ACMP0_SHIFT)) & RSTCTL0_PRSTCTL1_CLR_ACMP0_MASK)

#define RSTCTL0_PRSTCTL1_CLR_ADC0_MASK           (0x10000U)
#define RSTCTL0_PRSTCTL1_CLR_ADC0_SHIFT          (16U)
/*! ADC0 - ADC reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_CLR_ADC0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_CLR_ADC0_SHIFT)) & RSTCTL0_PRSTCTL1_CLR_ADC0_MASK)

#define RSTCTL0_PRSTCTL1_CLR_SHSGPIO0_MASK       (0x1000000U)
#define RSTCTL0_PRSTCTL1_CLR_SHSGPIO0_SHIFT      (24U)
/*! SHSGPIO0 - SHSGPIO0 reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL1 Bit
 */
#define RSTCTL0_PRSTCTL1_CLR_SHSGPIO0(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_CLR_SHSGPIO0_SHIFT)) & RSTCTL0_PRSTCTL1_CLR_SHSGPIO0_MASK)
/*! @} */

/*! @name PRSTCTL2_CLR - peripheral reset clear register 2 */
/*! @{ */

#define RSTCTL0_PRSTCTL2_CLR_UTICK0_MASK         (0x1U)
#define RSTCTL0_PRSTCTL2_CLR_UTICK0_SHIFT        (0U)
/*! UTICK0 - utick reset clear
 *  0b0..No Effect
 *  0b1..Clears the PRSTCTL2 Bit
 */
#define RSTCTL0_PRSTCTL2_CLR_UTICK0(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_UTICK0_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_UTICK0_MASK)

#define RSTCTL0_PRSTCTL2_CLR_WWDT0_MASK          (0x2U)
#define RSTCTL0_PRSTCTL2_CLR_WWDT0_SHIFT         (1U)
/*! WWDT0 - wdt reset clear
 *  0b0..No Effect
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

