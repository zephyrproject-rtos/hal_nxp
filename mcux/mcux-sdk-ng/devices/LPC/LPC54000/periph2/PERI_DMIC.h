/*
** ###################################################################
**     Processors:          LPC54018J2MET180
**                          LPC54018J4MET180
**                          LPC54S018J2MET180
**                          LPC54S018J4MET180
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DMIC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DMIC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DMIC
 *
 * CMSIS Peripheral Access Layer for DMIC
 */

#if !defined(PERI_DMIC_H_)
#define PERI_DMIC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54018J2MET180) || defined(CPU_LPC54018J4MET180))
#include "LPC54018M_COMMON.h"
#elif (defined(CPU_LPC54S018J2MET180) || defined(CPU_LPC54S018J4MET180))
#include "LPC54S018M_COMMON.h"
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
   -- DMIC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMIC_Peripheral_Access_Layer DMIC Peripheral Access Layer
 * @{
 */

/** DMIC - Size of Registers Arrays */
#define DMIC_CHANNEL_COUNT                        2u

/** DMIC - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x100 */
    __IO uint32_t OSR;                               /**< Oversample Rate register 0, array offset: 0x0, array step: 0x100 */
    __IO uint32_t DIVHFCLK;                          /**< DMIC Clock Register 0, array offset: 0x4, array step: 0x100 */
    __IO uint32_t PREAC2FSCOEF;                      /**< Pre-Emphasis Filter Coefficient for 2 FS register, array offset: 0x8, array step: 0x100 */
    __IO uint32_t PREAC4FSCOEF;                      /**< Pre-Emphasis Filter Coefficient for 4 FS register, array offset: 0xC, array step: 0x100 */
    __IO uint32_t GAINSHIFT;                         /**< Decimator Gain Shift register, array offset: 0x10, array step: 0x100 */
         uint8_t RESERVED_0[108];
    __IO uint32_t FIFO_CTRL;                         /**< FIFO Control register 0, array offset: 0x80, array step: 0x100 */
    __IO uint32_t FIFO_STATUS;                       /**< FIFO Status register 0, array offset: 0x84, array step: 0x100 */
    __IO uint32_t FIFO_DATA;                         /**< FIFO Data Register 0, array offset: 0x88, array step: 0x100 */
    __IO uint32_t PHY_CTRL;                          /**< PDM Source Configuration register 0, array offset: 0x8C, array step: 0x100 */
    __IO uint32_t DC_CTRL;                           /**< DC Control register 0, array offset: 0x90, array step: 0x100 */
         uint8_t RESERVED_1[108];
  } CHANNEL[DMIC_CHANNEL_COUNT];
       uint8_t RESERVED_0[3328];
  __IO uint32_t CHANEN;                            /**< Channel Enable register, offset: 0xF00 */
       uint8_t RESERVED_1[8];
  __IO uint32_t IOCFG;                             /**< I/O Configuration register, offset: 0xF0C */
  __IO uint32_t USE2FS;                            /**< Use 2FS register, offset: 0xF10 */
       uint8_t RESERVED_2[108];
  __IO uint32_t HWVADGAIN;                         /**< HWVAD input gain register, offset: 0xF80 */
  __IO uint32_t HWVADHPFS;                         /**< HWVAD filter control register, offset: 0xF84 */
  __IO uint32_t HWVADST10;                         /**< HWVAD control register, offset: 0xF88 */
  __IO uint32_t HWVADRSTT;                         /**< HWVAD filter reset register, offset: 0xF8C */
  __IO uint32_t HWVADTHGN;                         /**< HWVAD noise estimator gain register, offset: 0xF90 */
  __IO uint32_t HWVADTHGS;                         /**< HWVAD signal estimator gain register, offset: 0xF94 */
  __I  uint32_t HWVADLOWZ;                         /**< HWVAD noise envelope estimator register, offset: 0xF98 */
       uint8_t RESERVED_3[96];
  __I  uint32_t ID;                                /**< Module Identification register, offset: 0xFFC */
} DMIC_Type;

/* ----------------------------------------------------------------------------
   -- DMIC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMIC_Register_Masks DMIC Register Masks
 * @{
 */

/*! @name CHANNEL_OSR - Oversample Rate register 0 */
/*! @{ */

#define DMIC_CHANNEL_OSR_OSR_MASK                (0xFFU)
#define DMIC_CHANNEL_OSR_OSR_SHIFT               (0U)
/*! OSR - Selects the oversample rate for the related input channel. */
#define DMIC_CHANNEL_OSR_OSR(x)                  (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_OSR_OSR_SHIFT)) & DMIC_CHANNEL_OSR_OSR_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_OSR */
#define DMIC_CHANNEL_OSR_COUNT                   (2U)

/*! @name CHANNEL_DIVHFCLK - DMIC Clock Register 0 */
/*! @{ */

#define DMIC_CHANNEL_DIVHFCLK_PDMDIV_MASK        (0xFU)
#define DMIC_CHANNEL_DIVHFCLK_PDMDIV_SHIFT       (0U)
/*! PDMDIV - PDM clock divider value. 0 = divide by 1 1 = divide by 2 2 = divide by 3 3 = divide by
 *    4 4 = divide by 6 5 = divide by 8 6 = divide by 12 7 = divide by 16 8 = divide by 24 9 =
 *    divide by 32 10 = divide by 48 11 = divide by 64 12 = divide by 96 13 = divide by 128 others =
 *    reserved.
 */
#define DMIC_CHANNEL_DIVHFCLK_PDMDIV(x)          (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_DIVHFCLK_PDMDIV_SHIFT)) & DMIC_CHANNEL_DIVHFCLK_PDMDIV_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_DIVHFCLK */
#define DMIC_CHANNEL_DIVHFCLK_COUNT              (2U)

/*! @name CHANNEL_PREAC2FSCOEF - Pre-Emphasis Filter Coefficient for 2 FS register */
/*! @{ */

#define DMIC_CHANNEL_PREAC2FSCOEF_COMP_MASK      (0x3U)
#define DMIC_CHANNEL_PREAC2FSCOEF_COMP_SHIFT     (0U)
/*! COMP - Pre-emphasis filer coefficient for 2 FS mode. 0 = Compensation = 0 1 = Compensation = 16
 *    2 = Compensation = 15 3 = Compensation = 13
 */
#define DMIC_CHANNEL_PREAC2FSCOEF_COMP(x)        (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_PREAC2FSCOEF_COMP_SHIFT)) & DMIC_CHANNEL_PREAC2FSCOEF_COMP_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_PREAC2FSCOEF */
#define DMIC_CHANNEL_PREAC2FSCOEF_COUNT          (2U)

/*! @name CHANNEL_PREAC4FSCOEF - Pre-Emphasis Filter Coefficient for 4 FS register */
/*! @{ */

#define DMIC_CHANNEL_PREAC4FSCOEF_COMP_MASK      (0x3U)
#define DMIC_CHANNEL_PREAC4FSCOEF_COMP_SHIFT     (0U)
/*! COMP - Pre-emphasis filer coefficient for 4 FS mode. 0 = Compensation = 0 1 = Compensation = 16
 *    2 = Compensation = 15 3 = Compensation = 13
 */
#define DMIC_CHANNEL_PREAC4FSCOEF_COMP(x)        (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_PREAC4FSCOEF_COMP_SHIFT)) & DMIC_CHANNEL_PREAC4FSCOEF_COMP_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_PREAC4FSCOEF */
#define DMIC_CHANNEL_PREAC4FSCOEF_COUNT          (2U)

/*! @name CHANNEL_GAINSHIFT - Decimator Gain Shift register */
/*! @{ */

#define DMIC_CHANNEL_GAINSHIFT_GAIN_MASK         (0x3FU)
#define DMIC_CHANNEL_GAINSHIFT_GAIN_SHIFT        (0U)
/*! GAIN - Gain control, as a positive or negative (two's complement) number of bits to shift. */
#define DMIC_CHANNEL_GAINSHIFT_GAIN(x)           (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_GAINSHIFT_GAIN_SHIFT)) & DMIC_CHANNEL_GAINSHIFT_GAIN_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_GAINSHIFT */
#define DMIC_CHANNEL_GAINSHIFT_COUNT             (2U)

/*! @name CHANNEL_FIFO_CTRL - FIFO Control register 0 */
/*! @{ */

#define DMIC_CHANNEL_FIFO_CTRL_ENABLE_MASK       (0x1U)
#define DMIC_CHANNEL_FIFO_CTRL_ENABLE_SHIFT      (0U)
/*! ENABLE - FIFO enable.
 *  0b0..FIFO is not enabled. Enabling a DMIC channel with the FIFO disabled could be useful while data is being
 *       streamed to the I2S, or in order to avoid a filter settling delay when a channel is re-enabled after a
 *       period when the data was not needed.
 *  0b1..FIFO is enabled. The FIFO must be enabled in order for the CPU or DMA to read data from the DMIC via the FIFODATA register.
 */
#define DMIC_CHANNEL_FIFO_CTRL_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_FIFO_CTRL_ENABLE_SHIFT)) & DMIC_CHANNEL_FIFO_CTRL_ENABLE_MASK)

#define DMIC_CHANNEL_FIFO_CTRL_RESETN_MASK       (0x2U)
#define DMIC_CHANNEL_FIFO_CTRL_RESETN_SHIFT      (1U)
/*! RESETN - FIFO reset.
 *  0b0..Reset the FIFO.
 *  0b1..Normal operation
 */
#define DMIC_CHANNEL_FIFO_CTRL_RESETN(x)         (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_FIFO_CTRL_RESETN_SHIFT)) & DMIC_CHANNEL_FIFO_CTRL_RESETN_MASK)

#define DMIC_CHANNEL_FIFO_CTRL_INTEN_MASK        (0x4U)
#define DMIC_CHANNEL_FIFO_CTRL_INTEN_SHIFT       (2U)
/*! INTEN - Interrupt enable.
 *  0b0..FIFO level interrupts are not enabled.
 *  0b1..FIFO level interrupts are enabled.
 */
#define DMIC_CHANNEL_FIFO_CTRL_INTEN(x)          (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_FIFO_CTRL_INTEN_SHIFT)) & DMIC_CHANNEL_FIFO_CTRL_INTEN_MASK)

#define DMIC_CHANNEL_FIFO_CTRL_DMAEN_MASK        (0x8U)
#define DMIC_CHANNEL_FIFO_CTRL_DMAEN_SHIFT       (3U)
/*! DMAEN - DMA enable
 *  0b0..DMA requests are not enabled.
 *  0b1..DMA requests based on FIFO level are enabled.
 */
#define DMIC_CHANNEL_FIFO_CTRL_DMAEN(x)          (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_FIFO_CTRL_DMAEN_SHIFT)) & DMIC_CHANNEL_FIFO_CTRL_DMAEN_MASK)

#define DMIC_CHANNEL_FIFO_CTRL_TRIGLVL_MASK      (0x1F0000U)
#define DMIC_CHANNEL_FIFO_CTRL_TRIGLVL_SHIFT     (16U)
/*! TRIGLVL - FIFO trigger level. Selects the data trigger level for interrupt or DMA operation. If
 *    enabled to do so, the FIFO level can wake up the device just enough to perform DMA, then
 *    return to the reduced power mode See Section 4.5.66 'Hardware Wake-up control register'. 0 =
 *    trigger when the FIFO has received one entry (is no longer empty). 1 = trigger when the FIFO has
 *    received two entries. 15 = trigger when the FIFO has received 16 entries (has become full).
 */
#define DMIC_CHANNEL_FIFO_CTRL_TRIGLVL(x)        (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_FIFO_CTRL_TRIGLVL_SHIFT)) & DMIC_CHANNEL_FIFO_CTRL_TRIGLVL_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_FIFO_CTRL */
#define DMIC_CHANNEL_FIFO_CTRL_COUNT             (2U)

/*! @name CHANNEL_FIFO_STATUS - FIFO Status register 0 */
/*! @{ */

#define DMIC_CHANNEL_FIFO_STATUS_INT_MASK        (0x1U)
#define DMIC_CHANNEL_FIFO_STATUS_INT_SHIFT       (0U)
/*! INT - Interrupt flag. Asserted when FIFO data reaches the level specified in the FIFOCTRL
 *    register. Writing a one to this bit clears the flag. Remark: note that the bus clock to the DMIC
 *    subsystem must be running in order for an interrupt to occur.
 */
#define DMIC_CHANNEL_FIFO_STATUS_INT(x)          (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_FIFO_STATUS_INT_SHIFT)) & DMIC_CHANNEL_FIFO_STATUS_INT_MASK)

#define DMIC_CHANNEL_FIFO_STATUS_OVERRUN_MASK    (0x2U)
#define DMIC_CHANNEL_FIFO_STATUS_OVERRUN_SHIFT   (1U)
/*! OVERRUN - Overrun flag. Indicates that a FIFO overflow has occurred at some point. Writing a one
 *    to this bit clears the flag. This flag does not cause an interrupt.
 */
#define DMIC_CHANNEL_FIFO_STATUS_OVERRUN(x)      (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_FIFO_STATUS_OVERRUN_SHIFT)) & DMIC_CHANNEL_FIFO_STATUS_OVERRUN_MASK)

#define DMIC_CHANNEL_FIFO_STATUS_UNDERRUN_MASK   (0x4U)
#define DMIC_CHANNEL_FIFO_STATUS_UNDERRUN_SHIFT  (2U)
/*! UNDERRUN - Underrun flag. Indicates that a FIFO underflow has occurred at some point. Writing a one to this bit clears the flag. */
#define DMIC_CHANNEL_FIFO_STATUS_UNDERRUN(x)     (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_FIFO_STATUS_UNDERRUN_SHIFT)) & DMIC_CHANNEL_FIFO_STATUS_UNDERRUN_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_FIFO_STATUS */
#define DMIC_CHANNEL_FIFO_STATUS_COUNT           (2U)

/*! @name CHANNEL_FIFO_DATA - FIFO Data Register 0 */
/*! @{ */

#define DMIC_CHANNEL_FIFO_DATA_DATA_MASK         (0xFFFFFFU)
#define DMIC_CHANNEL_FIFO_DATA_DATA_SHIFT        (0U)
/*! DATA - Data from the top of the input filter FIFO. */
#define DMIC_CHANNEL_FIFO_DATA_DATA(x)           (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_FIFO_DATA_DATA_SHIFT)) & DMIC_CHANNEL_FIFO_DATA_DATA_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_FIFO_DATA */
#define DMIC_CHANNEL_FIFO_DATA_COUNT             (2U)

/*! @name CHANNEL_PHY_CTRL - PDM Source Configuration register 0 */
/*! @{ */

#define DMIC_CHANNEL_PHY_CTRL_PHY_FALL_MASK      (0x1U)
#define DMIC_CHANNEL_PHY_CTRL_PHY_FALL_SHIFT     (0U)
/*! PHY_FALL - Capture PDM_DATA
 *  0b0..Capture PDM_DATA on the rising edge of PDM_CLK.
 *  0b1..Capture PDM_DATA on the falling edge of PDM_CLK.
 */
#define DMIC_CHANNEL_PHY_CTRL_PHY_FALL(x)        (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_PHY_CTRL_PHY_FALL_SHIFT)) & DMIC_CHANNEL_PHY_CTRL_PHY_FALL_MASK)

#define DMIC_CHANNEL_PHY_CTRL_PHY_HALF_MASK      (0x2U)
#define DMIC_CHANNEL_PHY_CTRL_PHY_HALF_SHIFT     (1U)
/*! PHY_HALF - Half rate sampling
 *  0b0..Standard half rate sampling. The clock to the DMIC is sent at the same rate as the decimator is providing.
 *  0b1..Use half rate sampling. The clock to the DMIC is sent at half the rate as the decimator is providing.
 */
#define DMIC_CHANNEL_PHY_CTRL_PHY_HALF(x)        (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_PHY_CTRL_PHY_HALF_SHIFT)) & DMIC_CHANNEL_PHY_CTRL_PHY_HALF_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_PHY_CTRL */
#define DMIC_CHANNEL_PHY_CTRL_COUNT              (2U)

/*! @name CHANNEL_DC_CTRL - DC Control register 0 */
/*! @{ */

#define DMIC_CHANNEL_DC_CTRL_DCPOLE_MASK         (0x3U)
#define DMIC_CHANNEL_DC_CTRL_DCPOLE_SHIFT        (0U)
/*! DCPOLE - DC block filter
 *  0b00..Flat response, no filter.
 *  0b01..155 Hz.
 *  0b10..78 Hz.
 *  0b11..39 Hz
 */
#define DMIC_CHANNEL_DC_CTRL_DCPOLE(x)           (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_DC_CTRL_DCPOLE_SHIFT)) & DMIC_CHANNEL_DC_CTRL_DCPOLE_MASK)

#define DMIC_CHANNEL_DC_CTRL_DCGAIN_MASK         (0xF0U)
#define DMIC_CHANNEL_DC_CTRL_DCGAIN_SHIFT        (4U)
/*! DCGAIN - Fine gain adjustment in the form of a number of bits to downshift. */
#define DMIC_CHANNEL_DC_CTRL_DCGAIN(x)           (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_DC_CTRL_DCGAIN_SHIFT)) & DMIC_CHANNEL_DC_CTRL_DCGAIN_MASK)

#define DMIC_CHANNEL_DC_CTRL_SATURATEAT16BIT_MASK (0x100U)
#define DMIC_CHANNEL_DC_CTRL_SATURATEAT16BIT_SHIFT (8U)
/*! SATURATEAT16BIT - Selects 16-bit saturation.
 *  0b0..Results roll over if out range and do not saturate.
 *  0b1..If the result overflows, it saturates at 0xFFFF for positive overflow and 0x8000 for negative overflow.
 */
#define DMIC_CHANNEL_DC_CTRL_SATURATEAT16BIT(x)  (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_DC_CTRL_SATURATEAT16BIT_SHIFT)) & DMIC_CHANNEL_DC_CTRL_SATURATEAT16BIT_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_DC_CTRL */
#define DMIC_CHANNEL_DC_CTRL_COUNT               (2U)

/*! @name CHANEN - Channel Enable register */
/*! @{ */

#define DMIC_CHANEN_EN_CH0_MASK                  (0x1U)
#define DMIC_CHANEN_EN_CH0_SHIFT                 (0U)
/*! EN_CH0 - Enable channel 0. When 1, PDM channel 0 is enabled. */
#define DMIC_CHANEN_EN_CH0(x)                    (((uint32_t)(((uint32_t)(x)) << DMIC_CHANEN_EN_CH0_SHIFT)) & DMIC_CHANEN_EN_CH0_MASK)

#define DMIC_CHANEN_EN_CH1_MASK                  (0x2U)
#define DMIC_CHANEN_EN_CH1_SHIFT                 (1U)
/*! EN_CH1 - Enable channel 1. When 1, PDM channel 1 is enabled. */
#define DMIC_CHANEN_EN_CH1(x)                    (((uint32_t)(((uint32_t)(x)) << DMIC_CHANEN_EN_CH1_SHIFT)) & DMIC_CHANEN_EN_CH1_MASK)
/*! @} */

/*! @name IOCFG - I/O Configuration register */
/*! @{ */

#define DMIC_IOCFG_CLK_BYPASS0_MASK              (0x1U)
#define DMIC_IOCFG_CLK_BYPASS0_SHIFT             (0U)
/*! CLK_BYPASS0 - Bypass CLK0. When 1, PDM_DATA1 becomes the clock for PDM channel 0. This provides
 *    for the possibility of an external codec taking over the PDM bus.
 */
#define DMIC_IOCFG_CLK_BYPASS0(x)                (((uint32_t)(((uint32_t)(x)) << DMIC_IOCFG_CLK_BYPASS0_SHIFT)) & DMIC_IOCFG_CLK_BYPASS0_MASK)

#define DMIC_IOCFG_CLK_BYPASS1_MASK              (0x2U)
#define DMIC_IOCFG_CLK_BYPASS1_SHIFT             (1U)
/*! CLK_BYPASS1 - Bypass CLK1. When 1, PDM_DATA1 becomes the clock for PDM channel 1. This provides
 *    for the possibility of an external codec taking over the PDM bus.
 */
#define DMIC_IOCFG_CLK_BYPASS1(x)                (((uint32_t)(((uint32_t)(x)) << DMIC_IOCFG_CLK_BYPASS1_SHIFT)) & DMIC_IOCFG_CLK_BYPASS1_MASK)

#define DMIC_IOCFG_STEREO_DATA0_MASK             (0x4U)
#define DMIC_IOCFG_STEREO_DATA0_SHIFT            (2U)
/*! STEREO_DATA0 - Stereo PDM select. When 1, PDM_DATA0 is routed to both PDM channels in a
 *    configuration that supports a single stereo digital microphone.
 */
#define DMIC_IOCFG_STEREO_DATA0(x)               (((uint32_t)(((uint32_t)(x)) << DMIC_IOCFG_STEREO_DATA0_SHIFT)) & DMIC_IOCFG_STEREO_DATA0_MASK)
/*! @} */

/*! @name USE2FS - Use 2FS register */
/*! @{ */

#define DMIC_USE2FS_USE2FS_MASK                  (0x1U)
#define DMIC_USE2FS_USE2FS_SHIFT                 (0U)
/*! USE2FS - Use 2FS register
 *  0b0..Use 1FS output for PCM data.
 *  0b1..Use 2FS output for PCM data.
 */
#define DMIC_USE2FS_USE2FS(x)                    (((uint32_t)(((uint32_t)(x)) << DMIC_USE2FS_USE2FS_SHIFT)) & DMIC_USE2FS_USE2FS_MASK)
/*! @} */

/*! @name HWVADGAIN - HWVAD input gain register */
/*! @{ */

#define DMIC_HWVADGAIN_INPUTGAIN_MASK            (0xFU)
#define DMIC_HWVADGAIN_INPUTGAIN_SHIFT           (0U)
/*! INPUTGAIN - Shift value for input bits 0x00 -10 bits 0x01 -8 bits 0x02 -6 bits 0x03 -4 bits 0x04
 *    -2 bits 0x05 0 bits (default) 0x06 +2 bits 0x07 +4 bits 0x08 +6 bits 0x09 +8 bits 0x0A +10
 *    bits 0x0B +12 bits 0x0C +14 bits 0x0D to 0x0F Reserved.
 */
#define DMIC_HWVADGAIN_INPUTGAIN(x)              (((uint32_t)(((uint32_t)(x)) << DMIC_HWVADGAIN_INPUTGAIN_SHIFT)) & DMIC_HWVADGAIN_INPUTGAIN_MASK)
/*! @} */

/*! @name HWVADHPFS - HWVAD filter control register */
/*! @{ */

#define DMIC_HWVADHPFS_HPFS_MASK                 (0x3U)
#define DMIC_HWVADHPFS_HPFS_SHIFT                (0U)
/*! HPFS - High pass filter
 *  0b00..First filter by-pass.
 *  0b01..High pass filter with -3dB cut-off at 1750Hz.
 *  0b10..High pass filter with -3dB cut-off at 215Hz.
 *  0b11..Reserved.
 */
#define DMIC_HWVADHPFS_HPFS(x)                   (((uint32_t)(((uint32_t)(x)) << DMIC_HWVADHPFS_HPFS_SHIFT)) & DMIC_HWVADHPFS_HPFS_MASK)
/*! @} */

/*! @name HWVADST10 - HWVAD control register */
/*! @{ */

#define DMIC_HWVADST10_ST10_MASK                 (0x1U)
#define DMIC_HWVADST10_ST10_SHIFT                (0U)
/*! ST10 - Stage 0
 *  0b0..Normal operation, waiting for HWVAD trigger event (stage 0).
 *  0b1..Reset internal interrupt flag by writing a '1' pulse.
 */
#define DMIC_HWVADST10_ST10(x)                   (((uint32_t)(((uint32_t)(x)) << DMIC_HWVADST10_ST10_SHIFT)) & DMIC_HWVADST10_ST10_MASK)
/*! @} */

/*! @name HWVADRSTT - HWVAD filter reset register */
/*! @{ */

#define DMIC_HWVADRSTT_RSTT_MASK                 (0x1U)
#define DMIC_HWVADRSTT_RSTT_SHIFT                (0U)
/*! RSTT - Writing a 1 resets all filter values */
#define DMIC_HWVADRSTT_RSTT(x)                   (((uint32_t)(((uint32_t)(x)) << DMIC_HWVADRSTT_RSTT_SHIFT)) & DMIC_HWVADRSTT_RSTT_MASK)
/*! @} */

/*! @name HWVADTHGN - HWVAD noise estimator gain register */
/*! @{ */

#define DMIC_HWVADTHGN_THGN_MASK                 (0xFU)
#define DMIC_HWVADTHGN_THGN_SHIFT                (0U)
/*! THGN - Gain value for the noise estimator. Values 0 to 14. 0 corresponds to a gain of 1. */
#define DMIC_HWVADTHGN_THGN(x)                   (((uint32_t)(((uint32_t)(x)) << DMIC_HWVADTHGN_THGN_SHIFT)) & DMIC_HWVADTHGN_THGN_MASK)
/*! @} */

/*! @name HWVADTHGS - HWVAD signal estimator gain register */
/*! @{ */

#define DMIC_HWVADTHGS_THGS_MASK                 (0xFU)
#define DMIC_HWVADTHGS_THGS_SHIFT                (0U)
/*! THGS - Gain value for the signal estimator. Values 0 to 14. 0 corresponds to a gain of 1. */
#define DMIC_HWVADTHGS_THGS(x)                   (((uint32_t)(((uint32_t)(x)) << DMIC_HWVADTHGS_THGS_SHIFT)) & DMIC_HWVADTHGS_THGS_MASK)
/*! @} */

/*! @name HWVADLOWZ - HWVAD noise envelope estimator register */
/*! @{ */

#define DMIC_HWVADLOWZ_LOWZ_MASK                 (0xFFFFU)
#define DMIC_HWVADLOWZ_LOWZ_SHIFT                (0U)
/*! LOWZ - Noise envelope estimator value. */
#define DMIC_HWVADLOWZ_LOWZ(x)                   (((uint32_t)(((uint32_t)(x)) << DMIC_HWVADLOWZ_LOWZ_SHIFT)) & DMIC_HWVADLOWZ_LOWZ_MASK)
/*! @} */

/*! @name ID - Module Identification register */
/*! @{ */

#define DMIC_ID_ID_MASK                          (0xFFFFFFFFU)
#define DMIC_ID_ID_SHIFT                         (0U)
/*! ID - Indicates module ID and the number of channels in this DMIC interface. */
#define DMIC_ID_ID(x)                            (((uint32_t)(((uint32_t)(x)) << DMIC_ID_ID_SHIFT)) & DMIC_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DMIC_Register_Masks */


/*!
 * @}
 */ /* end of group DMIC_Peripheral_Access_Layer */


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


#endif  /* PERI_DMIC_H_ */

