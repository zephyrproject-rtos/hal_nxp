/*
** ###################################################################
**     Processors:          MC56F81643LVLC
**                          MC56F81646LVLF
**                          MC56F81648LVLH
**                          MC56F81663LVLC
**                          MC56F81666LVLF
**                          MC56F81668LVLH
**                          MC56F81743LVLC
**                          MC56F81746LMLF
**                          MC56F81746LVLF
**                          MC56F81748LMLH
**                          MC56F81748LVLH
**                          MC56F81763LVLC
**                          MC56F81766AMLFA
**                          MC56F81766LMLF
**                          MC56F81766LVLF
**                          MC56F81768AMLHA
**                          MC56F81768LMLH
**                          MC56F81768LVLH
**                          MC56F81866AMLFA
**                          MC56F81866LVLF
**                          MC56F81868AMLHA
**                          MC56F81868LVLH
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
**     - rev. 0.1 (2019-12-10)
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

#if (defined(CPU_MC56F81643LVLC))
#include "MC56F81643_COMMON.h"
#elif (defined(CPU_MC56F81646LVLF))
#include "MC56F81646_COMMON.h"
#elif (defined(CPU_MC56F81648LVLH))
#include "MC56F81648_COMMON.h"
#elif (defined(CPU_MC56F81663LVLC))
#include "MC56F81663_COMMON.h"
#elif (defined(CPU_MC56F81666LVLF))
#include "MC56F81666_COMMON.h"
#elif (defined(CPU_MC56F81668LVLH))
#include "MC56F81668_COMMON.h"
#elif (defined(CPU_MC56F81743LVLC))
#include "MC56F81743_COMMON.h"
#elif (defined(CPU_MC56F81746LMLF) || defined(CPU_MC56F81746LVLF))
#include "MC56F81746_COMMON.h"
#elif (defined(CPU_MC56F81748LMLH) || defined(CPU_MC56F81748LVLH))
#include "MC56F81748_COMMON.h"
#elif (defined(CPU_MC56F81763LVLC))
#include "MC56F81763_COMMON.h"
#elif (defined(CPU_MC56F81766AMLFA) || defined(CPU_MC56F81766LMLF) || defined(CPU_MC56F81766LVLF))
#include "MC56F81766_COMMON.h"
#elif (defined(CPU_MC56F81768AMLHA) || defined(CPU_MC56F81768LMLH) || defined(CPU_MC56F81768LVLH))
#include "MC56F81768_COMMON.h"
#elif (defined(CPU_MC56F81866AMLFA) || defined(CPU_MC56F81866LVLF))
#include "MC56F81866_COMMON.h"
#elif (defined(CPU_MC56F81868AMLHA) || defined(CPU_MC56F81868LVLH))
#include "MC56F81868_COMMON.h"
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
  __IO uint16_t COMPARE;                           /**< Compare Register, offset: 0x7 */
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
 *  0b0..Data words are right-justified (default)
 *  0b1..Data words are left-justified
 */
#define DAC_CTRL0_FORMAT(x)                      (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_FORMAT_SHIFT)) & DAC_CTRL0_FORMAT_MASK)

#define DAC_CTRL0_SYNC_EN_MASK                   (0x4U)
#define DAC_CTRL0_SYNC_EN_SHIFT                  (2U)
/*! SYNC_EN - Sync Enable
 *  0b0..Asynchronous mode. Data written to the buffered registers is used on the next clock cycle.
 *  0b1..Synchronous mode. SYNC_IN signal updates data in the buffered registers.
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
 *  0b0..Disable down-counting
 *  0b1..Enable down-counting
 */
#define DAC_CTRL0_DOWN(x)                        (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_DOWN_SHIFT)) & DAC_CTRL0_DOWN_MASK)

#define DAC_CTRL0_UP_MASK                        (0x20U)
#define DAC_CTRL0_UP_SHIFT                       (5U)
/*! UP - Enable Up-Counting
 *  0b0..Disable up-counting
 *  0b1..Enable up-counting
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
 *  0b0..Disable DMA support (default)
 *  0b1..Enable DMA support
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

#define DAC_CTRL0_SYNCEDGE_MASK                  (0xC00U)
#define DAC_CTRL0_SYNCEDGE_SHIFT                 (10U)
/*! SYNCEDGE - Sync edge
 *  0b00..No active edge is selected, therefore the SYNC input is ignored
 *  0b01..Updates occur on the falling edge of the SYNC input
 *  0b10..Updates occur on the rising edge of the SYNC input
 *  0b11..Updates occur on both edges of the SYNC input
 */
#define DAC_CTRL0_SYNCEDGE(x)                    (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_SYNCEDGE_SHIFT)) & DAC_CTRL0_SYNCEDGE_MASK)

#define DAC_CTRL0_FILT_EN_MASK                   (0x1000U)
#define DAC_CTRL0_FILT_EN_SHIFT                  (12U)
/*! FILT_EN - Glitch Filter Enable
 *  0b0..Disable glitch filter
 *  0b1..Enable glitch filter
 */
#define DAC_CTRL0_FILT_EN(x)                     (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_FILT_EN_SHIFT)) & DAC_CTRL0_FILT_EN_MASK)

#define DAC_CTRL0_LDOK_MASK                      (0x4000U)
#define DAC_CTRL0_LDOK_SHIFT                     (14U)
/*! LDOK - Load Okay
 *  0b0..Buffered values of STEPVAL, MINVAL, and MAXVAL will not be updated and the existing values will be reused.
 *  0b1..Buffered values of STEPVAL, MINVAL, and MAXVAL will be updated and used at active edge of SYNC_IN.
 */
#define DAC_CTRL0_LDOK(x)                        (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_LDOK_SHIFT)) & DAC_CTRL0_LDOK_MASK)

#define DAC_CTRL0_ONESHOT_MASK                   (0x8000U)
#define DAC_CTRL0_ONESHOT_SHIFT                  (15U)
/*! ONESHOT - One shot
 *  0b0..Automatic waveform generation logic will create a repeated (continuous) waveform upon receiving an active
 *       SYNC edge, otherwise the waveform repeats when it reaches its MIN or MAX value.
 *  0b1..Automatic waveform generation logic will create a single pattern and stop at the final value. It will
 *       remain at this final value until a new active edge occurs on the SYNC input, and then the waveform will be
 *       repeated.
 */
#define DAC_CTRL0_ONESHOT(x)                     (((uint16_t)(((uint16_t)(x)) << DAC_CTRL0_ONESHOT_SHIFT)) & DAC_CTRL0_ONESHOT_MASK)
/*! @} */

/*! @name DATAREG_FMT0 - Buffered Data Register */
/*! @{ */

#define DAC_DATAREG_FMT0_DATA_MASK               (0xFFFU)
#define DAC_DATAREG_FMT0_DATA_SHIFT              (0U)
/*! DATA - DAC data (right-justified) */
#define DAC_DATAREG_FMT0_DATA(x)                 (((uint16_t)(((uint16_t)(x)) << DAC_DATAREG_FMT0_DATA_SHIFT)) & DAC_DATAREG_FMT0_DATA_MASK)
/*! @} */

/*! @name STEPVAL_FMT0 - Step Size Register */
/*! @{ */

#define DAC_STEPVAL_FMT0_STEP_MASK               (0xFFFU)
#define DAC_STEPVAL_FMT0_STEP_SHIFT              (0U)
/*! STEP - STEP size (right-justified) */
#define DAC_STEPVAL_FMT0_STEP(x)                 (((uint16_t)(((uint16_t)(x)) << DAC_STEPVAL_FMT0_STEP_SHIFT)) & DAC_STEPVAL_FMT0_STEP_MASK)
/*! @} */

/*! @name MINVAL_FMT0 - Minimum Value Register */
/*! @{ */

#define DAC_MINVAL_FMT0_MINVAL_MASK              (0xFFFU)
#define DAC_MINVAL_FMT0_MINVAL_SHIFT             (0U)
/*! MINVAL - Minimum value (right-justified) */
#define DAC_MINVAL_FMT0_MINVAL(x)                (((uint16_t)(((uint16_t)(x)) << DAC_MINVAL_FMT0_MINVAL_SHIFT)) & DAC_MINVAL_FMT0_MINVAL_MASK)
/*! @} */

/*! @name MAXVAL_FMT0 - Maximum Value Register */
/*! @{ */

#define DAC_MAXVAL_FMT0_MAXVAL_MASK              (0xFFFU)
#define DAC_MAXVAL_FMT0_MAXVAL_SHIFT             (0U)
/*! MAXVAL - Maximum value (right-justified) */
#define DAC_MAXVAL_FMT0_MAXVAL(x)                (((uint16_t)(((uint16_t)(x)) << DAC_MAXVAL_FMT0_MAXVAL_SHIFT)) & DAC_MAXVAL_FMT0_MAXVAL_MASK)
/*! @} */

/*! @name DATAREG_FMT1 - Buffered Data Register */
/*! @{ */

#define DAC_DATAREG_FMT1_DATA_MASK               (0xFFF0U)
#define DAC_DATAREG_FMT1_DATA_SHIFT              (4U)
/*! DATA - DAC data (left-justified) */
#define DAC_DATAREG_FMT1_DATA(x)                 (((uint16_t)(((uint16_t)(x)) << DAC_DATAREG_FMT1_DATA_SHIFT)) & DAC_DATAREG_FMT1_DATA_MASK)
/*! @} */

/*! @name STEPVAL_FMT1 - Step Size Register */
/*! @{ */

#define DAC_STEPVAL_FMT1_STEP_MASK               (0xFFF0U)
#define DAC_STEPVAL_FMT1_STEP_SHIFT              (4U)
/*! STEP - STEP size (left-justified) */
#define DAC_STEPVAL_FMT1_STEP(x)                 (((uint16_t)(((uint16_t)(x)) << DAC_STEPVAL_FMT1_STEP_SHIFT)) & DAC_STEPVAL_FMT1_STEP_MASK)
/*! @} */

/*! @name MINVAL_FMT1 - Minimum Value Register */
/*! @{ */

#define DAC_MINVAL_FMT1_MINVAL_MASK              (0xFFF0U)
#define DAC_MINVAL_FMT1_MINVAL_SHIFT             (4U)
/*! MINVAL - Minimum value (left-justified) */
#define DAC_MINVAL_FMT1_MINVAL(x)                (((uint16_t)(((uint16_t)(x)) << DAC_MINVAL_FMT1_MINVAL_SHIFT)) & DAC_MINVAL_FMT1_MINVAL_MASK)
/*! @} */

/*! @name MAXVAL_FMT1 - Maximum Value Register */
/*! @{ */

#define DAC_MAXVAL_FMT1_MAXVAL_MASK              (0xFFF0U)
#define DAC_MAXVAL_FMT1_MAXVAL_SHIFT             (4U)
/*! MAXVAL - Maximum value (left-justified) */
#define DAC_MAXVAL_FMT1_MAXVAL(x)                (((uint16_t)(((uint16_t)(x)) << DAC_MAXVAL_FMT1_MAXVAL_SHIFT)) & DAC_MAXVAL_FMT1_MAXVAL_MASK)
/*! @} */

/*! @name STATUS - Status Register */
/*! @{ */

#define DAC_STATUS_EMPTY_MASK                    (0x1U)
#define DAC_STATUS_EMPTY_SHIFT                   (0U)
/*! EMPTY - Indicates that the FIFO is empty
 *  0b0..FIFO is not empty
 *  0b1..FIFO is empty (on reset)
 */
#define DAC_STATUS_EMPTY(x)                      (((uint16_t)(((uint16_t)(x)) << DAC_STATUS_EMPTY_SHIFT)) & DAC_STATUS_EMPTY_MASK)

#define DAC_STATUS_FULL_MASK                     (0x2U)
#define DAC_STATUS_FULL_SHIFT                    (1U)
/*! FULL - Indicates that the FIFO is full
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

/*! @name COMPARE - Compare Register */
/*! @{ */

#define DAC_COMPARE_COMPARE_MASK                 (0xFFFFU)
#define DAC_COMPARE_COMPARE_SHIFT                (0U)
/*! COMPARE - Compare value */
#define DAC_COMPARE_COMPARE(x)                   (((uint16_t)(((uint16_t)(x)) << DAC_COMPARE_COMPARE_SHIFT)) & DAC_COMPARE_COMPARE_MASK)
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

