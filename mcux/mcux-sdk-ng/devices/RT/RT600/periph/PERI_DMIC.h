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
 * @file PERI_DMIC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DMIC
 *
 * CMSIS Peripheral Access Layer for DMIC
 */

#if !defined(PERI_DMIC_H_)
#define PERI_DMIC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- DMIC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMIC_Peripheral_Access_Layer DMIC Peripheral Access Layer
 * @{
 */

/** DMIC - Size of Registers Arrays */
#define DMIC_CHANNEL_COUNT                        8u

/** DMIC - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x100 */
    __IO uint32_t OSR;                               /**< CIC Filter decimation rate, array offset: 0x0, array step: 0x100 */
    __IO uint32_t DIVHFCLK;                          /**< Divider for generating PDM clock from DMIC clock input, array offset: 0x4, array step: 0x100 */
    __IO uint32_t PREAC2FSCOEF;                      /**< Compensation filter for 2FS, array offset: 0x8, array step: 0x100 */
    __IO uint32_t PREAC4FSCOEF;                      /**< Compensation filter for 4FS, array offset: 0xC, array step: 0x100 */
    __IO uint32_t GAINSHIFT;                         /**< Decimator output gain adjustment, array offset: 0x10, array step: 0x100 */
         uint8_t RESERVED_0[108];
    __IO uint32_t FIFO_CTRL;                         /**< FIFO Control, array offset: 0x80, array step: 0x100 */
    __IO uint32_t FIFO_STATUS;                       /**< FIFO Status, array offset: 0x84, array step: 0x100 */
    __I  uint32_t FIFO_DATA;                         /**< FIFO Data, array offset: 0x88, array step: 0x100 */
    __IO uint32_t PHY_CTRL;                          /**< Phy Ctrl, array offset: 0x8C, array step: 0x100 */
    __IO uint32_t DC_CTRL;                           /**< DC Filter Control, array offset: 0x90, array step: 0x100 */
         uint8_t RESERVED_1[108];
  } CHANNEL[DMIC_CHANNEL_COUNT];
       uint8_t RESERVED_0[1792];
  __IO uint32_t CHANEN;                            /**< Channel Enable register, offset: 0xF00 */
       uint8_t RESERVED_1[12];
  __IO uint32_t USE2FS;                            /**< Use 2FS register, offset: 0xF10 */
  __IO uint32_t GLOBAL_SYNC_EN;                    /**< global sync enable, offset: 0xF14 */
  __IO uint32_t GLOBAL_COUNT_VAL;                  /**< offset: 0xF18 */
  __IO uint32_t DECRESET;                          /**< offset: 0xF1C */
       uint8_t RESERVED_2[96];
  __IO uint32_t HWVADGAIN;                         /**< HWVAD input gain register, offset: 0xF80 */
  __IO uint32_t HWVADHPFS;                         /**< HWVAD filter control register, offset: 0xF84 */
  __IO uint32_t HWVADST10;                         /**< HWVAD control register, offset: 0xF88 */
  __IO uint32_t HWVADRSTT;                         /**< HWVAD filter reset register, offset: 0xF8C */
  __IO uint32_t HWVADTHGN;                         /**< HWVAD noise estimator gain register, offset: 0xF90 */
  __IO uint32_t HWVADTHGS;                         /**< HWVAD signal estimator gain register, offset: 0xF94 */
  __I  uint32_t HWVADLOWZ;                         /**< HWVAD noise envelope estimator register, offset: 0xF98 */
} DMIC_Type;

/* ----------------------------------------------------------------------------
   -- DMIC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMIC_Register_Masks DMIC Register Masks
 * @{
 */

/*! @name CHANNEL_OSR - CIC Filter decimation rate */
/*! @{ */

#define DMIC_CHANNEL_OSR_OSR_MASK                (0xFFU)
#define DMIC_CHANNEL_OSR_OSR_SHIFT               (0U)
/*! OSR - Selects the oversample rate for the related input channel. */
#define DMIC_CHANNEL_OSR_OSR(x)                  (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_OSR_OSR_SHIFT)) & DMIC_CHANNEL_OSR_OSR_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_OSR */
#define DMIC_CHANNEL_OSR_COUNT                   (8U)

/*! @name CHANNEL_DIVHFCLK - Divider for generating PDM clock from DMIC clock input */
/*! @{ */

#define DMIC_CHANNEL_DIVHFCLK_PDMDIV_MASK        (0xFU)
#define DMIC_CHANNEL_DIVHFCLK_PDMDIV_SHIFT       (0U)
/*! PDMDIV - Divide by factor to create PDM Clock (enumerated type) */
#define DMIC_CHANNEL_DIVHFCLK_PDMDIV(x)          (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_DIVHFCLK_PDMDIV_SHIFT)) & DMIC_CHANNEL_DIVHFCLK_PDMDIV_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_DIVHFCLK */
#define DMIC_CHANNEL_DIVHFCLK_COUNT              (8U)

/*! @name CHANNEL_PREAC2FSCOEF - Compensation filter for 2FS */
/*! @{ */

#define DMIC_CHANNEL_PREAC2FSCOEF_COMP_MASK      (0x3U)
#define DMIC_CHANNEL_PREAC2FSCOEF_COMP_SHIFT     (0U)
/*! COMP - Co-efficient choice for CIC droop compensation droop filter */
#define DMIC_CHANNEL_PREAC2FSCOEF_COMP(x)        (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_PREAC2FSCOEF_COMP_SHIFT)) & DMIC_CHANNEL_PREAC2FSCOEF_COMP_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_PREAC2FSCOEF */
#define DMIC_CHANNEL_PREAC2FSCOEF_COUNT          (8U)

/*! @name CHANNEL_PREAC4FSCOEF - Compensation filter for 4FS */
/*! @{ */

#define DMIC_CHANNEL_PREAC4FSCOEF_COMP_MASK      (0x3U)
#define DMIC_CHANNEL_PREAC4FSCOEF_COMP_SHIFT     (0U)
/*! COMP - Co-efficient choice for CIC droop compensation droop filter */
#define DMIC_CHANNEL_PREAC4FSCOEF_COMP(x)        (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_PREAC4FSCOEF_COMP_SHIFT)) & DMIC_CHANNEL_PREAC4FSCOEF_COMP_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_PREAC4FSCOEF */
#define DMIC_CHANNEL_PREAC4FSCOEF_COUNT          (8U)

/*! @name CHANNEL_GAINSHIFT - Decimator output gain adjustment */
/*! @{ */

#define DMIC_CHANNEL_GAINSHIFT_GAIN_MASK         (0x3FU)
#define DMIC_CHANNEL_GAINSHIFT_GAIN_SHIFT        (0U)
/*! GAIN - Gain shift for decimator output (can be positive or negative number) */
#define DMIC_CHANNEL_GAINSHIFT_GAIN(x)           (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_GAINSHIFT_GAIN_SHIFT)) & DMIC_CHANNEL_GAINSHIFT_GAIN_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_GAINSHIFT */
#define DMIC_CHANNEL_GAINSHIFT_COUNT             (8U)

/*! @name CHANNEL_FIFO_CTRL - FIFO Control */
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
/*! TRIGLVL - Trigger level for interrupt */
#define DMIC_CHANNEL_FIFO_CTRL_TRIGLVL(x)        (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_FIFO_CTRL_TRIGLVL_SHIFT)) & DMIC_CHANNEL_FIFO_CTRL_TRIGLVL_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_FIFO_CTRL */
#define DMIC_CHANNEL_FIFO_CTRL_COUNT             (8U)

/*! @name CHANNEL_FIFO_STATUS - FIFO Status */
/*! @{ */

#define DMIC_CHANNEL_FIFO_STATUS_INT_MASK        (0x1U)
#define DMIC_CHANNEL_FIFO_STATUS_INT_SHIFT       (0U)
/*! INT - Status of Interrupt (write 1 to clear) */
#define DMIC_CHANNEL_FIFO_STATUS_INT(x)          (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_FIFO_STATUS_INT_SHIFT)) & DMIC_CHANNEL_FIFO_STATUS_INT_MASK)

#define DMIC_CHANNEL_FIFO_STATUS_OVERRUN_MASK    (0x2U)
#define DMIC_CHANNEL_FIFO_STATUS_OVERRUN_SHIFT   (1U)
/*! OVERRUN - Overrun Detected (write 1 to clear) */
#define DMIC_CHANNEL_FIFO_STATUS_OVERRUN(x)      (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_FIFO_STATUS_OVERRUN_SHIFT)) & DMIC_CHANNEL_FIFO_STATUS_OVERRUN_MASK)

#define DMIC_CHANNEL_FIFO_STATUS_UNDERRUN_MASK   (0x4U)
#define DMIC_CHANNEL_FIFO_STATUS_UNDERRUN_SHIFT  (2U)
/*! UNDERRUN - Underrun Detected (write 1 to clear) */
#define DMIC_CHANNEL_FIFO_STATUS_UNDERRUN(x)     (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_FIFO_STATUS_UNDERRUN_SHIFT)) & DMIC_CHANNEL_FIFO_STATUS_UNDERRUN_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_FIFO_STATUS */
#define DMIC_CHANNEL_FIFO_STATUS_COUNT           (8U)

/*! @name CHANNEL_FIFO_DATA - FIFO Data */
/*! @{ */

#define DMIC_CHANNEL_FIFO_DATA_DATA_MASK         (0xFFFFFFU)
#define DMIC_CHANNEL_FIFO_DATA_DATA_SHIFT        (0U)
/*! DATA - PCM Data */
#define DMIC_CHANNEL_FIFO_DATA_DATA(x)           (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_FIFO_DATA_DATA_SHIFT)) & DMIC_CHANNEL_FIFO_DATA_DATA_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_FIFO_DATA */
#define DMIC_CHANNEL_FIFO_DATA_COUNT             (8U)

/*! @name CHANNEL_PHY_CTRL - Phy Ctrl */
/*! @{ */

#define DMIC_CHANNEL_PHY_CTRL_PHY_FALL_MASK      (0x1U)
#define DMIC_CHANNEL_PHY_CTRL_PHY_FALL_SHIFT     (0U)
/*! PHY_FALL - Capture DMIC on Falling edge (0 means on rising)
 *  0b0..Capture PDM_DATA on the rising edge of PDM_CLK.
 *  0b1..Capture PDM_DATA on the falling edge of PDM_CLK.
 */
#define DMIC_CHANNEL_PHY_CTRL_PHY_FALL(x)        (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_PHY_CTRL_PHY_FALL_SHIFT)) & DMIC_CHANNEL_PHY_CTRL_PHY_FALL_MASK)

#define DMIC_CHANNEL_PHY_CTRL_PHY_HALF_MASK      (0x2U)
#define DMIC_CHANNEL_PHY_CTRL_PHY_HALF_SHIFT     (1U)
/*! PHY_HALF - Use Half rate sampling (ie Clock to dmic is sent at half the speed than the decimator is providing)
 *  0b0..Standard half rate sampling. The clock to the DMIC is sent at the same rate as the decimator is providing.
 *  0b1..Use half rate sampling. The clock to the DMIC is sent at half the rate as the decimator is providing.
 */
#define DMIC_CHANNEL_PHY_CTRL_PHY_HALF(x)        (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_PHY_CTRL_PHY_HALF_SHIFT)) & DMIC_CHANNEL_PHY_CTRL_PHY_HALF_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_PHY_CTRL */
#define DMIC_CHANNEL_PHY_CTRL_COUNT              (8U)

/*! @name CHANNEL_DC_CTRL - DC Filter Control */
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

#define DMIC_CHANNEL_DC_CTRL_SIGNEXTEND_MASK     (0x200U)
#define DMIC_CHANNEL_DC_CTRL_SIGNEXTEND_SHIFT    (9U)
/*! SIGNEXTEND - Sign extend.
 *  0b0..The top byte of the FIFODATA register is always 0.
 *  0b1..The top byte of the FIFODATA register is sign extended. This allows processing of 24-bit audio data on 32-bit machines.
 */
#define DMIC_CHANNEL_DC_CTRL_SIGNEXTEND(x)       (((uint32_t)(((uint32_t)(x)) << DMIC_CHANNEL_DC_CTRL_SIGNEXTEND_SHIFT)) & DMIC_CHANNEL_DC_CTRL_SIGNEXTEND_MASK)
/*! @} */

/* The count of DMIC_CHANNEL_DC_CTRL */
#define DMIC_CHANNEL_DC_CTRL_COUNT               (8U)

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

#define DMIC_CHANEN_EN_CH2_MASK                  (0x4U)
#define DMIC_CHANEN_EN_CH2_SHIFT                 (2U)
/*! EN_CH2 - Enable channel 2. When 1, PDM channel 2 is enabled. */
#define DMIC_CHANEN_EN_CH2(x)                    (((uint32_t)(((uint32_t)(x)) << DMIC_CHANEN_EN_CH2_SHIFT)) & DMIC_CHANEN_EN_CH2_MASK)

#define DMIC_CHANEN_EN_CH3_MASK                  (0x8U)
#define DMIC_CHANEN_EN_CH3_SHIFT                 (3U)
/*! EN_CH3 - Enable channel 3. When 1, PDM channel 3 is enabled. */
#define DMIC_CHANEN_EN_CH3(x)                    (((uint32_t)(((uint32_t)(x)) << DMIC_CHANEN_EN_CH3_SHIFT)) & DMIC_CHANEN_EN_CH3_MASK)

#define DMIC_CHANEN_EN_CH4_MASK                  (0x10U)
#define DMIC_CHANEN_EN_CH4_SHIFT                 (4U)
/*! EN_CH4 - Enable channel 4. When 1, PDM channel 4 is enabled. */
#define DMIC_CHANEN_EN_CH4(x)                    (((uint32_t)(((uint32_t)(x)) << DMIC_CHANEN_EN_CH4_SHIFT)) & DMIC_CHANEN_EN_CH4_MASK)

#define DMIC_CHANEN_EN_CH5_MASK                  (0x20U)
#define DMIC_CHANEN_EN_CH5_SHIFT                 (5U)
/*! EN_CH5 - Enable channel 5. When 1, PDM channel 5 is enabled. */
#define DMIC_CHANEN_EN_CH5(x)                    (((uint32_t)(((uint32_t)(x)) << DMIC_CHANEN_EN_CH5_SHIFT)) & DMIC_CHANEN_EN_CH5_MASK)

#define DMIC_CHANEN_EN_CH6_MASK                  (0x40U)
#define DMIC_CHANEN_EN_CH6_SHIFT                 (6U)
/*! EN_CH6 - Enable channel 6. When 1, PDM channel 6 is enabled. */
#define DMIC_CHANEN_EN_CH6(x)                    (((uint32_t)(((uint32_t)(x)) << DMIC_CHANEN_EN_CH6_SHIFT)) & DMIC_CHANEN_EN_CH6_MASK)

#define DMIC_CHANEN_EN_CH7_MASK                  (0x80U)
#define DMIC_CHANEN_EN_CH7_SHIFT                 (7U)
/*! EN_CH7 - Enable channel 7. When 1, PDM channel 7 is enabled. */
#define DMIC_CHANEN_EN_CH7(x)                    (((uint32_t)(((uint32_t)(x)) << DMIC_CHANEN_EN_CH7_SHIFT)) & DMIC_CHANEN_EN_CH7_MASK)
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

/*! @name GLOBAL_SYNC_EN - global sync enable */
/*! @{ */

#define DMIC_GLOBAL_SYNC_EN_CH_SYNC_EN_MASK      (0xFFU)
#define DMIC_GLOBAL_SYNC_EN_CH_SYNC_EN_SHIFT     (0U)
#define DMIC_GLOBAL_SYNC_EN_CH_SYNC_EN(x)        (((uint32_t)(((uint32_t)(x)) << DMIC_GLOBAL_SYNC_EN_CH_SYNC_EN_SHIFT)) & DMIC_GLOBAL_SYNC_EN_CH_SYNC_EN_MASK)
/*! @} */

/*! @name GLOBAL_COUNT_VAL -  */
/*! @{ */

#define DMIC_GLOBAL_COUNT_VAL_CCOUNTVAL_MASK     (0xFFFFFFFFU)
#define DMIC_GLOBAL_COUNT_VAL_CCOUNTVAL_SHIFT    (0U)
#define DMIC_GLOBAL_COUNT_VAL_CCOUNTVAL(x)       (((uint32_t)(((uint32_t)(x)) << DMIC_GLOBAL_COUNT_VAL_CCOUNTVAL_SHIFT)) & DMIC_GLOBAL_COUNT_VAL_CCOUNTVAL_MASK)
/*! @} */

/*! @name DECRESET -  */
/*! @{ */

#define DMIC_DECRESET_DECRESET_MASK              (0xFFU)
#define DMIC_DECRESET_DECRESET_SHIFT             (0U)
/*! DECRESET
 *  0b00000000..release reset to decimator
 *  0b00000001..assert reset to decimator Note : resets are applied in pairs. So bit 0 corresponds to channels
 *              0/1, bit1 corresponds to channels 2/3, bit2 to channel 4/5 and bit3 to channel 6/7
 */
#define DMIC_DECRESET_DECRESET(x)                (((uint32_t)(((uint32_t)(x)) << DMIC_DECRESET_DECRESET_SHIFT)) & DMIC_DECRESET_DECRESET_MASK)
/*! @} */

/*! @name HWVADGAIN - HWVAD input gain register */
/*! @{ */

#define DMIC_HWVADGAIN_INPUTGAIN_MASK            (0xFU)
#define DMIC_HWVADGAIN_INPUTGAIN_SHIFT           (0U)
/*! INPUTGAIN - Gain factor for input signal into HWVAD */
#define DMIC_HWVADGAIN_INPUTGAIN(x)              (((uint32_t)(((uint32_t)(x)) << DMIC_HWVADGAIN_INPUTGAIN_SHIFT)) & DMIC_HWVADGAIN_INPUTGAIN_MASK)
/*! @} */

/*! @name HWVADHPFS - HWVAD filter control register */
/*! @{ */

#define DMIC_HWVADHPFS_HPFS_MASK                 (0x3U)
#define DMIC_HWVADHPFS_HPFS_SHIFT                (0U)
/*! HPFS - This field chooses the High Pass filter in first part of HWVAD
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
/*! ST10 - 1' means enter stage 1 of VAD, ie a sound change has been detected and the HWVAD is being
 *    allowed to settle. Use 0 when changing back to detection mode. Allow several milliseconds in
 *    stage 1 for settling.
 *  0b0..Normal operation, waiting for HWVAD trigger event (stage 0).
 *  0b1..Reset internal interrupt flag by writing a '1' pulse.
 */
#define DMIC_HWVADST10_ST10(x)                   (((uint32_t)(((uint32_t)(x)) << DMIC_HWVADST10_ST10_SHIFT)) & DMIC_HWVADST10_ST10_MASK)
/*! @} */

/*! @name HWVADRSTT - HWVAD filter reset register */
/*! @{ */

#define DMIC_HWVADRSTT_RSTT_MASK                 (0x1U)
#define DMIC_HWVADRSTT_RSTT_SHIFT                (0U)
/*! RSTT - Reset HWVAD. Write back to 0 to release reset. */
#define DMIC_HWVADRSTT_RSTT(x)                   (((uint32_t)(((uint32_t)(x)) << DMIC_HWVADRSTT_RSTT_SHIFT)) & DMIC_HWVADRSTT_RSTT_MASK)
/*! @} */

/*! @name HWVADTHGN - HWVAD noise estimator gain register */
/*! @{ */

#define DMIC_HWVADTHGN_THGN_MASK                 (0xFU)
#define DMIC_HWVADTHGN_THGN_SHIFT                (0U)
/*! THGN - Gain Factor for Noise-floor - use a positive number to make average less sensitive to sudden changes */
#define DMIC_HWVADTHGN_THGN(x)                   (((uint32_t)(((uint32_t)(x)) << DMIC_HWVADTHGN_THGN_SHIFT)) & DMIC_HWVADTHGN_THGN_MASK)
/*! @} */

/*! @name HWVADTHGS - HWVAD signal estimator gain register */
/*! @{ */

#define DMIC_HWVADTHGS_THGS_MASK                 (0xFU)
#define DMIC_HWVADTHGS_THGS_SHIFT                (0U)
/*! THGS - Signal Gain factor - use a postive number to make current signal stand out more over longer term average */
#define DMIC_HWVADTHGS_THGS(x)                   (((uint32_t)(((uint32_t)(x)) << DMIC_HWVADTHGS_THGS_SHIFT)) & DMIC_HWVADTHGS_THGS_MASK)
/*! @} */

/*! @name HWVADLOWZ - HWVAD noise envelope estimator register */
/*! @{ */

#define DMIC_HWVADLOWZ_LOWZ_MASK                 (0xFFFFU)
#define DMIC_HWVADLOWZ_LOWZ_SHIFT                (0U)
/*! LOWZ - Average noise-floor value */
#define DMIC_HWVADLOWZ_LOWZ(x)                   (((uint32_t)(((uint32_t)(x)) << DMIC_HWVADLOWZ_LOWZ_SHIFT)) & DMIC_HWVADLOWZ_LOWZ_MASK)
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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_DMIC_H_ */

