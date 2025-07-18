/*
** ###################################################################
**     Processors:          MC56F82313VLC
**                          MC56F82316VLF
**                          MC56F82323VFM
**                          MC56F82623VLC
**                          MC56F82643VLC
**                          MC56F82646VLF
**                          MC56F82723VFM
**                          MC56F82723VLC
**                          MC56F82726VLF
**                          MC56F82728VLH
**                          MC56F82733MFM
**                          MC56F82733VFM
**                          MC56F82733VLC
**                          MC56F82736VLF
**                          MC56F82738VLH
**                          MC56F82743VFM
**                          MC56F82743VLC
**                          MC56F82746MLF
**                          MC56F82746VLF
**                          MC56F82748MLH
**                          MC56F82748VLH
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DAC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2020-12-11)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DAC.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DAC
 *
 * CMSIS Peripheral Access Layer for DAC
 */

#if !defined(PERI_DAC_H_)
#define PERI_DAC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F82313VLC))
#include "MC56F82313_COMMON.h"
#elif (defined(CPU_MC56F82316VLF))
#include "MC56F82316_COMMON.h"
#elif (defined(CPU_MC56F82323VFM))
#include "MC56F82323_COMMON.h"
#elif (defined(CPU_MC56F82623VLC))
#include "MC56F82623_COMMON.h"
#elif (defined(CPU_MC56F82643VLC))
#include "MC56F82643_COMMON.h"
#elif (defined(CPU_MC56F82646VLF))
#include "MC56F82646_COMMON.h"
#elif (defined(CPU_MC56F82723VFM) || defined(CPU_MC56F82723VLC))
#include "MC56F82723_COMMON.h"
#elif (defined(CPU_MC56F82726VLF))
#include "MC56F82726_COMMON.h"
#elif (defined(CPU_MC56F82728VLH))
#include "MC56F82728_COMMON.h"
#elif (defined(CPU_MC56F82733MFM) || defined(CPU_MC56F82733VFM) || defined(CPU_MC56F82733VLC))
#include "MC56F82733_COMMON.h"
#elif (defined(CPU_MC56F82736VLF))
#include "MC56F82736_COMMON.h"
#elif (defined(CPU_MC56F82738VLH))
#include "MC56F82738_COMMON.h"
#elif (defined(CPU_MC56F82743VFM) || defined(CPU_MC56F82743VLC))
#include "MC56F82743_COMMON.h"
#elif (defined(CPU_MC56F82746MLF) || defined(CPU_MC56F82746VLF))
#include "MC56F82746_COMMON.h"
#elif (defined(CPU_MC56F82748MLH) || defined(CPU_MC56F82748VLH))
#include "MC56F82748_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- DAC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Peripheral_Access_Layer DAC Peripheral Access Layer
 * @{
 */

/** DAC - Register Layout Typedef */
typedef struct {
  __IO uint16_t CTRL0;                             /**< Control Register 0, offset: 0x0 */
  union {                                          /* offset: 0x1 */
    struct {                                         /* offset: 0x1 */
      __IO uint16_t DATAREG_FMT0;                      /**< Buffered Data Register, offset: 0x1 */
      __IO uint16_t STEPVAL_FMT0;                      /**< Step Size Register, offset: 0x2 */
      __IO uint16_t MINVAL_FMT0;                       /**< Minimum Value Register, offset: 0x3 */
      __IO uint16_t MAXVAL_FMT0;                       /**< Maximum Value Register, offset: 0x4 */
    } FMT0;
    struct {                                         /* offset: 0x1 */
      __IO uint16_t DATAREG_FMT1;                      /**< Buffered Data Register, offset: 0x1 */
      __IO uint16_t STEPVAL_FMT1;                      /**< Step Size Register, offset: 0x2 */
      __IO uint16_t MINVAL_FMT1;                       /**< Minimum Value Register, offset: 0x3 */
      __IO uint16_t MAXVAL_FMT1;                       /**< Maximum Value Register, offset: 0x4 */
    } FMT1;
  };
  __I  uint16_t STATUS;                            /**< Status Register, offset: 0x5 */
  __IO uint16_t CTRL1;                             /**< Control Register 1, offset: 0x6 */
} DAC_Type;

/* ----------------------------------------------------------------------------
   -- DAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Register_Masks DAC Register Masks
 * @{
 */

/*! @name CTRL0 - Control Register 0 */
/*! @{ */

#define DAC_CTRL0_PDN_MASK                       (0x1U)
#define DAC_CTRL0_PDN_SHIFT                      (0U)
/*! PDN - Power Down
 *  0b0..DAC is operational.
 *  0b1..DAC is powered down. (default)
 */
#define DAC_CTRL0_PDN(x)                         (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_PDN_SHIFT)) & DAC_CTRL0_PDN_MASK)

#define DAC_CTRL0_FORMAT_MASK                    (0x2U)
#define DAC_CTRL0_FORMAT_SHIFT                   (1U)
/*! FORMAT - Data Format
 *  0b0..Data words are right justified. (default)
 *  0b1..Data words are left justified.
 */
#define DAC_CTRL0_FORMAT(x)                      (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_FORMAT_SHIFT)) & DAC_CTRL0_FORMAT_MASK)

#define DAC_CTRL0_SYNC_EN_MASK                   (0x4U)
#define DAC_CTRL0_SYNC_EN_SHIFT                  (2U)
/*! SYNC_EN - Sync Enable
 *  0b0..Asynchronous mode. Data written to the buffered data register is presented to DAC inputs on the next clock cycle.
 *  0b1..Synchronous mode. Rising edge of SYNC_IN updates data in the buffered data register presented to the DAC input.
 */
#define DAC_CTRL0_SYNC_EN(x)                     (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_SYNC_EN_SHIFT)) & DAC_CTRL0_SYNC_EN_MASK)

#define DAC_CTRL0_AUTO_MASK                      (0x8U)
#define DAC_CTRL0_AUTO_SHIFT                     (3U)
/*! AUTO - Automatic Mode
 *  0b0..Normal mode. Automatic waveform generation disabled.
 *  0b1..Automatic waveform generation enabled.
 */
#define DAC_CTRL0_AUTO(x)                        (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_AUTO_SHIFT)) & DAC_CTRL0_AUTO_MASK)

#define DAC_CTRL0_DOWN_MASK                      (0x10U)
#define DAC_CTRL0_DOWN_SHIFT                     (4U)
/*! DOWN - Enable Down Counting
 *  0b0..Down counting disabled.
 *  0b1..Down counting enabled.
 */
#define DAC_CTRL0_DOWN(x)                        (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_DOWN_SHIFT)) & DAC_CTRL0_DOWN_MASK)

#define DAC_CTRL0_UP_MASK                        (0x20U)
#define DAC_CTRL0_UP_SHIFT                       (5U)
/*! UP - Enable Up Counting
 *  0b0..Up counting disabled.
 *  0b1..Up counting enabled.
 */
#define DAC_CTRL0_UP(x)                          (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_UP_SHIFT)) & DAC_CTRL0_UP_MASK)

#define DAC_CTRL0_HSLS_MASK                      (0x40U)
#define DAC_CTRL0_HSLS_SHIFT                     (6U)
/*! HSLS - High/Low Speed
 *  0b0..High speed mode (default)
 *  0b1..Low speed mode
 */
#define DAC_CTRL0_HSLS(x)                        (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_HSLS_SHIFT)) & DAC_CTRL0_HSLS_MASK)

#define DAC_CTRL0_DMA_EN_MASK                    (0x80U)
#define DAC_CTRL0_DMA_EN_SHIFT                   (7U)
/*! DMA_EN - Enable DMA Support
 *  0b0..DMA support disabled (default)
 *  0b1..DMA support enabled
 */
#define DAC_CTRL0_DMA_EN(x)                      (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_DMA_EN_SHIFT)) & DAC_CTRL0_DMA_EN_MASK)

#define DAC_CTRL0_WTMK_LVL_MASK                  (0x300U)
#define DAC_CTRL0_WTMK_LVL_SHIFT                 (8U)
/*! WTMK_LVL - Watermark Level
 *  0b00..Watermark value is 0
 *  0b01..Watermark value is 2 (default)
 *  0b10..Watermark value is 4
 *  0b11..Watermark value is 6
 */
#define DAC_CTRL0_WTMK_LVL(x)                    (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_WTMK_LVL_SHIFT)) & DAC_CTRL0_WTMK_LVL_MASK)

#define DAC_CTRL0_FILT_EN_MASK                   (0x1000U)
#define DAC_CTRL0_FILT_EN_SHIFT                  (12U)
/*! FILT_EN - Glitch Filter Enable
 *  0b0..Filter disabled.
 *  0b1..Filter enabled.
 */
#define DAC_CTRL0_FILT_EN(x)                     (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_FILT_EN_SHIFT)) & DAC_CTRL0_FILT_EN_MASK)
/*! @} */

/*! @name DATAREG_FMT0 - Buffered Data Register */
/*! @{ */

#define DAC_DATAREG_FMT0_DATA_MASK               (0xFFFU)
#define DAC_DATAREG_FMT0_DATA_SHIFT              (0U)
/*! DATA - DAC data (right justified) */
#define DAC_DATAREG_FMT0_DATA(x)                 (((uint16_t)(((uint16_t)(x)) << DAC_DATAREG_FMT0_DATA_SHIFT)) & DAC_DATAREG_FMT0_DATA_MASK)
/*! @} */

/*! @name STEPVAL_FMT0 - Step Size Register */
/*! @{ */

#define DAC_STEPVAL_FMT0_STEP_MASK               (0xFFFU)
#define DAC_STEPVAL_FMT0_STEP_SHIFT              (0U)
/*! STEP - STEP size (right justified) */
#define DAC_STEPVAL_FMT0_STEP(x)                 (((uint16_t)(((uint16_t)(x)) << DAC_STEPVAL_FMT0_STEP_SHIFT)) & DAC_STEPVAL_FMT0_STEP_MASK)
/*! @} */

/*! @name MINVAL_FMT0 - Minimum Value Register */
/*! @{ */

#define DAC_MINVAL_FMT0_MINVAL_MASK              (0xFFFU)
#define DAC_MINVAL_FMT0_MINVAL_SHIFT             (0U)
/*! MINVAL - Minimum value (right justified) */
#define DAC_MINVAL_FMT0_MINVAL(x)                (((uint16_t)(((uint16_t)(x)) << DAC_MINVAL_FMT0_MINVAL_SHIFT)) & DAC_MINVAL_FMT0_MINVAL_MASK)
/*! @} */

/*! @name MAXVAL_FMT0 - Maximum Value Register */
/*! @{ */

#define DAC_MAXVAL_FMT0_MAXVAL_MASK              (0xFFFU)
#define DAC_MAXVAL_FMT0_MAXVAL_SHIFT             (0U)
/*! MAXVAL - Maximum value (right justified) */
#define DAC_MAXVAL_FMT0_MAXVAL(x)                (((uint16_t)(((uint16_t)(x)) << DAC_MAXVAL_FMT0_MAXVAL_SHIFT)) & DAC_MAXVAL_FMT0_MAXVAL_MASK)
/*! @} */

/*! @name DATAREG_FMT1 - Buffered Data Register */
/*! @{ */

#define DAC_DATAREG_FMT1_DATA_MASK               (0xFFF0U)
#define DAC_DATAREG_FMT1_DATA_SHIFT              (4U)
/*! DATA - DAC data (left justified) */
#define DAC_DATAREG_FMT1_DATA(x)                 (((uint16_t)(((uint16_t)(x)) << DAC_DATAREG_FMT1_DATA_SHIFT)) & DAC_DATAREG_FMT1_DATA_MASK)
/*! @} */

/*! @name STEPVAL_FMT1 - Step Size Register */
/*! @{ */

#define DAC_STEPVAL_FMT1_STEP_MASK               (0xFFF0U)
#define DAC_STEPVAL_FMT1_STEP_SHIFT              (4U)
/*! STEP - STEP size (left justified) */
#define DAC_STEPVAL_FMT1_STEP(x)                 (((uint16_t)(((uint16_t)(x)) << DAC_STEPVAL_FMT1_STEP_SHIFT)) & DAC_STEPVAL_FMT1_STEP_MASK)
/*! @} */

/*! @name MINVAL_FMT1 - Minimum Value Register */
/*! @{ */

#define DAC_MINVAL_FMT1_MINVAL_MASK              (0xFFF0U)
#define DAC_MINVAL_FMT1_MINVAL_SHIFT             (4U)
/*! MINVAL - Minimum value (left justified) */
#define DAC_MINVAL_FMT1_MINVAL(x)                (((uint16_t)(((uint16_t)(x)) << DAC_MINVAL_FMT1_MINVAL_SHIFT)) & DAC_MINVAL_FMT1_MINVAL_MASK)
/*! @} */

/*! @name MAXVAL_FMT1 - Maximum Value Register */
/*! @{ */

#define DAC_MAXVAL_FMT1_MAXVAL_MASK              (0xFFF0U)
#define DAC_MAXVAL_FMT1_MAXVAL_SHIFT             (4U)
/*! MAXVAL - Maximum value (left justified) */
#define DAC_MAXVAL_FMT1_MAXVAL(x)                (((uint16_t)(((uint16_t)(x)) << DAC_MAXVAL_FMT1_MAXVAL_SHIFT)) & DAC_MAXVAL_FMT1_MAXVAL_MASK)
/*! @} */

/*! @name STATUS - Status Register */
/*! @{ */

#define DAC_STATUS_EMPTY_MASK                    (0x1U)
#define DAC_STATUS_EMPTY_SHIFT                   (0U)
/*! EMPTY - Indicates empty status of FIFO
 *  0b0..FIFO is not empty.
 *  0b1..FIFO is empty (on reset).
 */
#define DAC_STATUS_EMPTY(x)                      (((uint16_t)(((uint16_t)(x)) << DAC_STATUS_EMPTY_SHIFT)) & DAC_STATUS_EMPTY_MASK)

#define DAC_STATUS_FULL_MASK                     (0x2U)
#define DAC_STATUS_FULL_SHIFT                    (1U)
/*! FULL - Indicates full status of FIFO
 *  0b0..FIFO is not full (on reset).
 *  0b1..FIFO is full.
 */
#define DAC_STATUS_FULL(x)                       (((uint16_t)(((uint16_t)(x)) << DAC_STATUS_FULL_SHIFT)) & DAC_STATUS_FULL_MASK)
/*! @} */

/*! @name CTRL1 - Control Register 1 */
/*! @{ */

#define DAC_CTRL1_FILT_CNT_MASK                  (0x3FU)
#define DAC_CTRL1_FILT_CNT_SHIFT                 (0U)
/*! FILT_CNT - Glitch Filter Count */
#define DAC_CTRL1_FILT_CNT(x)                    (((uint16_t)(((uint16_t)(x)) << DAC_CTRL1_FILT_CNT_SHIFT)) & DAC_CTRL1_FILT_CNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DAC_Register_Masks */


/*!
 * @}
 */ /* end of group DAC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_DAC_H_ */

