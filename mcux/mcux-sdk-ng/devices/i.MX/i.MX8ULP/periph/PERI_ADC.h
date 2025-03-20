/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 5.0, 2023-04-27
**     Build:               b240823
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ADC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**
** ###################################################################
*/

/*!
 * @file ADC.h
 * @version 5.0
 * @date 2023-04-27
 * @brief CMSIS Peripheral Access Layer for ADC
 *
 * CMSIS Peripheral Access Layer for ADC
 */

#if !defined(ADC_H_)
#define ADC_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */

/** ADC - Size of Registers Arrays */
#define ADC_TCTRL_COUNT                           4u
#define ADC_CMD_COUNT                             15u
#define ADC_CV_COUNT                              4u

/** ADC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t CTRL;                              /**< Control Register, offset: 0x10 */
  __IO uint32_t STAT;                              /**< Status Register, offset: 0x14 */
  __IO uint32_t IE;                                /**< Interrupt Enable Register, offset: 0x18 */
  __IO uint32_t DE;                                /**< DMA Enable Register, offset: 0x1C */
  __IO uint32_t CFG;                               /**< Configuration Register, offset: 0x20 */
  __IO uint32_t PAUSE;                             /**< Pause Register, offset: 0x24 */
       uint8_t RESERVED_1[12];
  __O  uint32_t SWTRIG;                            /**< Software Trigger Register, offset: 0x34 */
  __IO uint32_t TSTAT;                             /**< Trigger Status Register, offset: 0x38 */
       uint8_t RESERVED_2[100];
  __IO uint32_t TCTRL[ADC_TCTRL_COUNT];            /**< Trigger Control Register, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_3[48];
  __IO uint32_t FCTRL;                             /**< FIFO Control Register, offset: 0xE0 */
       uint8_t RESERVED_4[28];
  struct {                                         /* offset: 0x100, array step: 0x8 */
    __IO uint32_t CMDL;                              /**< Command Low Buffer Register, array offset: 0x100, array step: 0x8 */
    __IO uint32_t CMDH;                              /**< Command High Buffer Register, array offset: 0x104, array step: 0x8 */
  } CMD[ADC_CMD_COUNT];
       uint8_t RESERVED_5[136];
  __IO uint32_t CV[ADC_CV_COUNT];                  /**< Compare Value Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_6[240];
  __I  uint32_t RESFIFO;                           /**< Data Result FIFO Register, offset: 0x300 */
} ADC_Type;

/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define ADC_VERID_RES_MASK                       (0x1U)
#define ADC_VERID_RES_SHIFT                      (0U)
/*! RES - Resolution
 *  0b0..Up to 13-bit differential or 12-bit single-ended resolution supported.
 *  0b1..Up to 16-bit differential or 15-bit single-ended resolution supported. CMDLn[MODE] available for
 *       selecting the resolution of conversions for the associated command.
 */
#define ADC_VERID_RES(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_VERID_RES_SHIFT)) & ADC_VERID_RES_MASK)

#define ADC_VERID_DIFFEN_MASK                    (0x2U)
#define ADC_VERID_DIFFEN_SHIFT                   (1U)
/*! DIFFEN - Differential Supported
 *  0b0..Not supported
 *  0b1..Supported. CMDLn[DIFF] and CMDLn[ABSEL] control fields implemented.
 */
#define ADC_VERID_DIFFEN(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_VERID_DIFFEN_SHIFT)) & ADC_VERID_DIFFEN_MASK)

#define ADC_VERID_MVI_MASK                       (0x8U)
#define ADC_VERID_MVI_SHIFT                      (3U)
/*! MVI - Multiple Vref Implemented
 *  0b0..Single VREFH input supported.
 *  0b1..Multiple VREFH inputs supported.
 */
#define ADC_VERID_MVI(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_VERID_MVI_SHIFT)) & ADC_VERID_MVI_MASK)

#define ADC_VERID_CSW_MASK                       (0x70U)
#define ADC_VERID_CSW_SHIFT                      (4U)
/*! CSW - Channel Scale Width
 *  0b000..Not supported.
 *  0b001..Supported with one-bit CSCALE control field.
 *  0b110..Supported with six-bit CSCALE control field.
 */
#define ADC_VERID_CSW(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_VERID_CSW_SHIFT)) & ADC_VERID_CSW_MASK)

#define ADC_VERID_VR1RNGI_MASK                   (0x100U)
#define ADC_VERID_VR1RNGI_SHIFT                  (8U)
/*! VR1RNGI - Voltage Reference 1 Range Control Bit Implemented
 *  0b0..Range control not required.
 *  0b1..Range control required.
 */
#define ADC_VERID_VR1RNGI(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_VERID_VR1RNGI_SHIFT)) & ADC_VERID_VR1RNGI_MASK)

#define ADC_VERID_IADCKI_MASK                    (0x200U)
#define ADC_VERID_IADCKI_SHIFT                   (9U)
/*! IADCKI - Internal ADC Clock Implemented
 *  0b0..Not implemented
 *  0b1..Implemented
 */
#define ADC_VERID_IADCKI(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_VERID_IADCKI_SHIFT)) & ADC_VERID_IADCKI_MASK)

#define ADC_VERID_CALOFSI_MASK                   (0x400U)
#define ADC_VERID_CALOFSI_SHIFT                  (10U)
/*! CALOFSI - Calibration Function Implemented
 *  0b0..Not implemented
 *  0b1..Implemented
 */
#define ADC_VERID_CALOFSI(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_VERID_CALOFSI_SHIFT)) & ADC_VERID_CALOFSI_MASK)

#define ADC_VERID_NUM_SEC_MASK                   (0x800U)
#define ADC_VERID_NUM_SEC_SHIFT                  (11U)
/*! NUM_SEC - Number of Single-Ended Outputs Supported
 *  0b0..One
 *  0b1..Two
 */
#define ADC_VERID_NUM_SEC(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_VERID_NUM_SEC_SHIFT)) & ADC_VERID_NUM_SEC_MASK)

#define ADC_VERID_NUM_FIFO_MASK                  (0x7000U)
#define ADC_VERID_NUM_FIFO_SHIFT                 (12U)
/*! NUM_FIFO - Number of FIFOs
 *  0b000..N/A
 *  0b001..One
 *  0b010..Two
 *  0b011..Three
 *  0b100..Four
 */
#define ADC_VERID_NUM_FIFO(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_VERID_NUM_FIFO_SHIFT)) & ADC_VERID_NUM_FIFO_MASK)

#define ADC_VERID_MINOR_MASK                     (0xFF0000U)
#define ADC_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define ADC_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_VERID_MINOR_SHIFT)) & ADC_VERID_MINOR_MASK)

#define ADC_VERID_MAJOR_MASK                     (0xFF000000U)
#define ADC_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define ADC_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_VERID_MAJOR_SHIFT)) & ADC_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define ADC_PARAM_TRIG_NUM_MASK                  (0xFFU)
#define ADC_PARAM_TRIG_NUM_SHIFT                 (0U)
/*! TRIG_NUM - Trigger Number */
#define ADC_PARAM_TRIG_NUM(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_PARAM_TRIG_NUM_SHIFT)) & ADC_PARAM_TRIG_NUM_MASK)

#define ADC_PARAM_FIFOSIZE_MASK                  (0xFF00U)
#define ADC_PARAM_FIFOSIZE_SHIFT                 (8U)
/*! FIFOSIZE - Result FIFO Depth
 *  0b00000001..2
 *  0b00000100..4
 *  0b00001000..8
 *  0b00010000..16
 *  0b00100000..32
 *  0b01000000..64
 */
#define ADC_PARAM_FIFOSIZE(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_PARAM_FIFOSIZE_SHIFT)) & ADC_PARAM_FIFOSIZE_MASK)

#define ADC_PARAM_CV_NUM_MASK                    (0xFF0000U)
#define ADC_PARAM_CV_NUM_SHIFT                   (16U)
/*! CV_NUM - Compare Value Number */
#define ADC_PARAM_CV_NUM(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_PARAM_CV_NUM_SHIFT)) & ADC_PARAM_CV_NUM_MASK)

#define ADC_PARAM_CMD_NUM_MASK                   (0xFF000000U)
#define ADC_PARAM_CMD_NUM_SHIFT                  (24U)
/*! CMD_NUM - Command Buffer Number */
#define ADC_PARAM_CMD_NUM(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_PARAM_CMD_NUM_SHIFT)) & ADC_PARAM_CMD_NUM_MASK)
/*! @} */

/*! @name CTRL - Control Register */
/*! @{ */

#define ADC_CTRL_ADCEN_MASK                      (0x1U)
#define ADC_CTRL_ADCEN_SHIFT                     (0U)
/*! ADCEN - ADC Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ADC_CTRL_ADCEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CTRL_ADCEN_SHIFT)) & ADC_CTRL_ADCEN_MASK)

#define ADC_CTRL_RST_MASK                        (0x2U)
#define ADC_CTRL_RST_SHIFT                       (1U)
/*! RST - Software Reset
 *  0b0..ADC logic is not reset.
 *  0b1..ADC logic is reset.
 */
#define ADC_CTRL_RST(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_CTRL_RST_SHIFT)) & ADC_CTRL_RST_MASK)

#define ADC_CTRL_DOZEN_MASK                      (0x4U)
#define ADC_CTRL_DOZEN_SHIFT                     (2U)
/*! DOZEN - Doze Enable
 *  0b0..ADC is enabled in low-power mode.
 *  0b1..ADC is disabled in low-power mode.
 */
#define ADC_CTRL_DOZEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CTRL_DOZEN_SHIFT)) & ADC_CTRL_DOZEN_MASK)

#define ADC_CTRL_RSTFIFO0_MASK                   (0x100U)
#define ADC_CTRL_RSTFIFO0_SHIFT                  (8U)
/*! RSTFIFO0 - Reset FIFO 0
 *  0b0..No effect.
 *  0b1..FIFO 0 is reset.
 */
#define ADC_CTRL_RSTFIFO0(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CTRL_RSTFIFO0_SHIFT)) & ADC_CTRL_RSTFIFO0_MASK)
/*! @} */

/*! @name STAT - Status Register */
/*! @{ */

#define ADC_STAT_RDY0_MASK                       (0x1U)
#define ADC_STAT_RDY0_SHIFT                      (0U)
/*! RDY0 - Result FIFO 0 Ready Flag
 *  0b0..Not above watermark
 *  0b1..Above watermark
 */
#define ADC_STAT_RDY0(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_STAT_RDY0_SHIFT)) & ADC_STAT_RDY0_MASK)

#define ADC_STAT_FOF0_MASK                       (0x2U)
#define ADC_STAT_FOF0_SHIFT                      (1U)
/*! FOF0 - Result FIFO 0 Overflow Flag
 *  0b0..No result FIFO 0 overflow has occurred since the last time that the flag was cleared.
 *  0b1..At least one result FIFO 0 overflow has occurred since the last time that the flag was cleared.
 */
#define ADC_STAT_FOF0(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_STAT_FOF0_SHIFT)) & ADC_STAT_FOF0_MASK)

#define ADC_STAT_TEXC_INT_MASK                   (0x100U)
#define ADC_STAT_TEXC_INT_SHIFT                  (8U)
/*! TEXC_INT - Interrupt Flag For High-Priority Trigger Exception
 *  0b0..No trigger exceptions have occurred.
 *  0b1..A trigger exception has occurred and is pending acknowledgment.
 */
#define ADC_STAT_TEXC_INT(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_STAT_TEXC_INT_SHIFT)) & ADC_STAT_TEXC_INT_MASK)

#define ADC_STAT_TCOMP_INT_MASK                  (0x200U)
#define ADC_STAT_TCOMP_INT_SHIFT                 (9U)
/*! TCOMP_INT - Interrupt Flag For Trigger Completion
 *  0b0..Either IE[TCOMP_IE] = 0, or no trigger sequences have run to completion.
 *  0b1..Trigger sequence has been completed and all data is stored in the associated FIFO.
 */
#define ADC_STAT_TCOMP_INT(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_STAT_TCOMP_INT_SHIFT)) & ADC_STAT_TCOMP_INT_MASK)

#define ADC_STAT_ADC_ACTIVE_MASK                 (0x800U)
#define ADC_STAT_ADC_ACTIVE_SHIFT                (11U)
/*! ADC_ACTIVE - ADC Active
 *  0b0..ADC is idle. There are no pending triggers to service and no active commands are being processed.
 *  0b1..ADC is processing a conversion, running through the power-up delay, or servicing a trigger.
 */
#define ADC_STAT_ADC_ACTIVE(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_STAT_ADC_ACTIVE_SHIFT)) & ADC_STAT_ADC_ACTIVE_MASK)

#define ADC_STAT_TRGACT_MASK                     (0x30000U)
#define ADC_STAT_TRGACT_SHIFT                    (16U)
/*! TRGACT - Trigger Active
 *  0b00..Command (sequence) associated with Trigger 0 currently being executed.
 *  0b01..Command (sequence) associated with Trigger 1 currently being executed.
 *  0b10..Command (sequence) associated with Trigger 2 currently being executed.
 *  0b11..Command (sequence) associated with Trigger 3 currently being executed.
 */
#define ADC_STAT_TRGACT(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAT_TRGACT_SHIFT)) & ADC_STAT_TRGACT_MASK)

#define ADC_STAT_CMDACT_MASK                     (0xF000000U)
#define ADC_STAT_CMDACT_SHIFT                    (24U)
/*! CMDACT - Command Active
 *  0b0000..No command currently in progress.
 *  0b0001..Command 1 currently being executed.
 *  0b0010..Command 2 currently being executed.
 *  0b0011-0b1111..Associated command number currently being executed.
 */
#define ADC_STAT_CMDACT(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAT_CMDACT_SHIFT)) & ADC_STAT_CMDACT_MASK)
/*! @} */

/*! @name IE - Interrupt Enable Register */
/*! @{ */

#define ADC_IE_FWMIE0_MASK                       (0x1U)
#define ADC_IE_FWMIE0_SHIFT                      (0U)
/*! FWMIE0 - FIFO 0 Watermark Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ADC_IE_FWMIE0(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_IE_FWMIE0_SHIFT)) & ADC_IE_FWMIE0_MASK)

#define ADC_IE_FOFIE0_MASK                       (0x2U)
#define ADC_IE_FOFIE0_SHIFT                      (1U)
/*! FOFIE0 - Result FIFO 0 Overflow Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ADC_IE_FOFIE0(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_IE_FOFIE0_SHIFT)) & ADC_IE_FOFIE0_MASK)

#define ADC_IE_TEXC_IE_MASK                      (0x100U)
#define ADC_IE_TEXC_IE_SHIFT                     (8U)
/*! TEXC_IE - Trigger Exception Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ADC_IE_TEXC_IE(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_IE_TEXC_IE_SHIFT)) & ADC_IE_TEXC_IE_MASK)

#define ADC_IE_TCOMP_IE_MASK                     (0xF0000U)
#define ADC_IE_TCOMP_IE_SHIFT                    (16U)
/*! TCOMP_IE - Trigger Completion Interrupt Enable
 *  0b0000..All disabled
 *  0b0001..Trigger completion interrupts are enabled for trigger source 0 only.
 *  0b0010..Trigger completion interrupts are enabled for trigger source 1 only.
 *  0b0011-0b1110..Associated trigger completion interrupts are enabled.
 *  0b1111..All enabled
 */
#define ADC_IE_TCOMP_IE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_IE_TCOMP_IE_SHIFT)) & ADC_IE_TCOMP_IE_MASK)
/*! @} */

/*! @name DE - DMA Enable Register */
/*! @{ */

#define ADC_DE_FWMDE0_MASK                       (0x1U)
#define ADC_DE_FWMDE0_SHIFT                      (0U)
/*! FWMDE0 - FIFO 0 Watermark DMA Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ADC_DE_FWMDE0(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_DE_FWMDE0_SHIFT)) & ADC_DE_FWMDE0_MASK)
/*! @} */

/*! @name CFG - Configuration Register */
/*! @{ */

#define ADC_CFG_TPRICTRL_MASK                    (0x3U)
#define ADC_CFG_TPRICTRL_SHIFT                   (0U)
/*! TPRICTRL - ADC Trigger Priority Control
 *  0b00..Current conversion is aborted and the new command specified by the trigger is started.
 *  0b01..Current command is stopped after completing the current conversion. If averaging is enabled, the
 *        averaging loop is completed. CMDHn[LOOP] is ignored and the higher-priority trigger is serviced.
 *  0b10..Current command is completed (averaging, looping, compare) before servicing the higher-priority trigger.
 *  0b11..
 */
#define ADC_CFG_TPRICTRL(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CFG_TPRICTRL_SHIFT)) & ADC_CFG_TPRICTRL_MASK)

#define ADC_CFG_PWRSEL_MASK                      (0x30U)
#define ADC_CFG_PWRSEL_SHIFT                     (4U)
/*! PWRSEL - Power Configuration Select
 *  0b00..Lowest power
 *  0b01..Higher power than 00b
 *  0b10..Higher power than 01b
 *  0b11..Highest power
 */
#define ADC_CFG_PWRSEL(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CFG_PWRSEL_SHIFT)) & ADC_CFG_PWRSEL_MASK)

#define ADC_CFG_REFSEL_MASK                      (0xC0U)
#define ADC_CFG_REFSEL_SHIFT                     (6U)
/*! REFSEL - Voltage Reference Selection
 *  0b00..Option 1
 *  0b01..Option 2
 *  0b10..Option 3
 *  0b11..
 */
#define ADC_CFG_REFSEL(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CFG_REFSEL_SHIFT)) & ADC_CFG_REFSEL_MASK)

#define ADC_CFG_TRES_MASK                        (0x100U)
#define ADC_CFG_TRES_SHIFT                       (8U)
/*! TRES - Trigger Resume Enable
 *  0b0..Not automatically resumed or restarted
 *  0b1..Automatically resumed or restarted
 */
#define ADC_CFG_TRES(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_CFG_TRES_SHIFT)) & ADC_CFG_TRES_MASK)

#define ADC_CFG_TCMDRES_MASK                     (0x200U)
#define ADC_CFG_TCMDRES_SHIFT                    (9U)
/*! TCMDRES - Trigger Command Resume
 *  0b0..Trigger sequence automatically restarted.
 *  0b1..Trigger sequence resumed from the command that was executed prior to the exception.
 */
#define ADC_CFG_TCMDRES(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CFG_TCMDRES_SHIFT)) & ADC_CFG_TCMDRES_MASK)

#define ADC_CFG_HPT_EXDI_MASK                    (0x400U)
#define ADC_CFG_HPT_EXDI_SHIFT                   (10U)
/*! HPT_EXDI - High-Priority Trigger Exception Disable
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define ADC_CFG_HPT_EXDI(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CFG_HPT_EXDI_SHIFT)) & ADC_CFG_HPT_EXDI_MASK)

#define ADC_CFG_PUDLY_MASK                       (0xFF0000U)
#define ADC_CFG_PUDLY_SHIFT                      (16U)
/*! PUDLY - Power-up Delay */
#define ADC_CFG_PUDLY(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CFG_PUDLY_SHIFT)) & ADC_CFG_PUDLY_MASK)

#define ADC_CFG_PWREN_MASK                       (0x10000000U)
#define ADC_CFG_PWREN_SHIFT                      (28U)
/*! PWREN - ADC Analog Pre-Enable
 *  0b0..ADC analog circuits are only enabled while conversions are active. Analog startup delays affect performance.
 *  0b1..ADC analog circuits are pre-enabled and ready to execute conversions without startup delays, at the cost
 *       of higher DC current consumption. A single power-up delay (CFG[PUDLY]) is executed immediately once PWREN
 *       is set. No detected triggers begin ADC operation until the power-up delay time has passed. After this
 *       initial delay expires, the analog circuits remain pre-enabled, and no additional delays are executed.
 */
#define ADC_CFG_PWREN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CFG_PWREN_SHIFT)) & ADC_CFG_PWREN_MASK)
/*! @} */

/*! @name PAUSE - Pause Register */
/*! @{ */

#define ADC_PAUSE_PAUSEDLY_MASK                  (0x1FFU)
#define ADC_PAUSE_PAUSEDLY_SHIFT                 (0U)
/*! PAUSEDLY - Pause Delay */
#define ADC_PAUSE_PAUSEDLY(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_PAUSE_PAUSEDLY_SHIFT)) & ADC_PAUSE_PAUSEDLY_MASK)

#define ADC_PAUSE_PAUSEEN_MASK                   (0x80000000U)
#define ADC_PAUSE_PAUSEEN_SHIFT                  (31U)
/*! PAUSEEN - Pause Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ADC_PAUSE_PAUSEEN(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_PAUSE_PAUSEEN_SHIFT)) & ADC_PAUSE_PAUSEEN_MASK)
/*! @} */

/*! @name SWTRIG - Software Trigger Register */
/*! @{ */

#define ADC_SWTRIG_SWT0_MASK                     (0x1U)
#define ADC_SWTRIG_SWT0_SHIFT                    (0U)
/*! SWT0 - Software Trigger 0
 *  0b0..No trigger 0 event generated.
 *  0b1..Trigger 0 event generated.
 */
#define ADC_SWTRIG_SWT0(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_SWTRIG_SWT0_SHIFT)) & ADC_SWTRIG_SWT0_MASK)

#define ADC_SWTRIG_SWT1_MASK                     (0x2U)
#define ADC_SWTRIG_SWT1_SHIFT                    (1U)
/*! SWT1 - Software Trigger 1
 *  0b0..No trigger 1 event generated.
 *  0b1..Trigger 1 event generated.
 */
#define ADC_SWTRIG_SWT1(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_SWTRIG_SWT1_SHIFT)) & ADC_SWTRIG_SWT1_MASK)

#define ADC_SWTRIG_SWT2_MASK                     (0x4U)
#define ADC_SWTRIG_SWT2_SHIFT                    (2U)
/*! SWT2 - Software Trigger 2
 *  0b0..No trigger 2 event generated.
 *  0b1..Trigger 2 event generated.
 */
#define ADC_SWTRIG_SWT2(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_SWTRIG_SWT2_SHIFT)) & ADC_SWTRIG_SWT2_MASK)

#define ADC_SWTRIG_SWT3_MASK                     (0x8U)
#define ADC_SWTRIG_SWT3_SHIFT                    (3U)
/*! SWT3 - Software Trigger 3
 *  0b0..No trigger 3 event generated.
 *  0b1..Trigger 3 event generated.
 */
#define ADC_SWTRIG_SWT3(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_SWTRIG_SWT3_SHIFT)) & ADC_SWTRIG_SWT3_MASK)
/*! @} */

/*! @name TSTAT - Trigger Status Register */
/*! @{ */

#define ADC_TSTAT_TEXC_NUM_MASK                  (0xFU)
#define ADC_TSTAT_TEXC_NUM_SHIFT                 (0U)
/*! TEXC_NUM - Trigger Exception Number
 *  0b0000..No triggers have been interrupted by a high-priority exception.
 *  0b0001..Trigger 0 has been interrupted by a high-priority exception.
 *  0b0010..Trigger 1 has been interrupted by a high-priority exception.
 *  0b0011-0b1110..Associated trigger sequence has interrupted by a high-priority exception.
 *  0b1111..Every trigger sequence has been interrupted by a high-priority exception.
 */
#define ADC_TSTAT_TEXC_NUM(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_TSTAT_TEXC_NUM_SHIFT)) & ADC_TSTAT_TEXC_NUM_MASK)

#define ADC_TSTAT_TCOMP_FLAG_MASK                (0xF0000U)
#define ADC_TSTAT_TCOMP_FLAG_SHIFT               (16U)
/*! TCOMP_FLAG - Trigger Completion Flag
 *  0b0000..No triggers have been completed. Trigger completion interrupts are disabled.
 *  0b0001..Trigger 0 has been completed and trigger 0 has enabled completion interrupts.
 *  0b0010..Trigger 1 has been completed and trigger 1 has enabled completion interrupts.
 *  0b0011-0b1110..Associated trigger sequence has completed and has enabled completion interrupts.
 *  0b1111..Every trigger sequence has been completed and every trigger has enabled completion interrupts.
 */
#define ADC_TSTAT_TCOMP_FLAG(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_TSTAT_TCOMP_FLAG_SHIFT)) & ADC_TSTAT_TCOMP_FLAG_MASK)
/*! @} */

/*! @name TCTRL - Trigger Control Register */
/*! @{ */

#define ADC_TCTRL_HTEN_MASK                      (0x1U)
#define ADC_TCTRL_HTEN_SHIFT                     (0U)
/*! HTEN - Trigger Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ADC_TCTRL_HTEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_TCTRL_HTEN_SHIFT)) & ADC_TCTRL_HTEN_MASK)

#define ADC_TCTRL_TPRI_MASK                      (0x300U)
#define ADC_TCTRL_TPRI_SHIFT                     (8U)
/*! TPRI - Trigger Priority Setting
 *  0b00..Highest priority, Level 1
 *  0b01-0b10..Set to corresponding priority level.
 *  0b11..Lowest priority, Level 4
 */
#define ADC_TCTRL_TPRI(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_TCTRL_TPRI_SHIFT)) & ADC_TCTRL_TPRI_MASK)

#define ADC_TCTRL_TDLY_MASK                      (0xF0000U)
#define ADC_TCTRL_TDLY_SHIFT                     (16U)
/*! TDLY - Trigger Delay Select */
#define ADC_TCTRL_TDLY(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_TCTRL_TDLY_SHIFT)) & ADC_TCTRL_TDLY_MASK)

#define ADC_TCTRL_TCMD_MASK                      (0xF000000U)
#define ADC_TCTRL_TCMD_SHIFT                     (24U)
/*! TCMD - Trigger Command Select
 *  0b0000..Not a valid selection from the command buffer. Trigger event is ignored.
 *  0b0001..CMD1
 *  0b0010-0b1110..Corresponding CMD is executed
 *  0b1111..CMD15
 */
#define ADC_TCTRL_TCMD(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_TCTRL_TCMD_SHIFT)) & ADC_TCTRL_TCMD_MASK)
/*! @} */

/*! @name FCTRL - FIFO Control Register */
/*! @{ */

#define ADC_FCTRL_FCOUNT_MASK                    (0x1FU)
#define ADC_FCTRL_FCOUNT_SHIFT                   (0U)
/*! FCOUNT - Result FIFO Counter */
#define ADC_FCTRL_FCOUNT(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FCTRL_FCOUNT_SHIFT)) & ADC_FCTRL_FCOUNT_MASK)

#define ADC_FCTRL_FWMARK_MASK                    (0xF0000U)
#define ADC_FCTRL_FWMARK_SHIFT                   (16U)
/*! FWMARK - Watermark Level Selection */
#define ADC_FCTRL_FWMARK(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FCTRL_FWMARK_SHIFT)) & ADC_FCTRL_FWMARK_MASK)
/*! @} */

/*! @name CMDL - Command Low Buffer Register */
/*! @{ */

#define ADC_CMDL_ADCH_MASK                       (0x1FU)
#define ADC_CMDL_ADCH_SHIFT                      (0U)
/*! ADCH - Input Channel Select
 *  0b00000..CH0A or CH0B or CH0A/CH0B pair.
 *  0b00001..CH1A or CH1B or CH1A/CH1B pair.
 *  0b00010..CH2A or CH2B or CH2A/CH2B pair.
 *  0b00011..CH3A or CH3B or CH3A/CH3B pair.
 *  0b00100-0b11101..Select corresponding channel CHnA or CHnB or CHnA/CHnB pair.
 *  0b11110..CH30A or CH30B or CH30A/CH30B pair.
 *  0b11111..CH31A or CH31B or CH31A/CH31B pair.
 */
#define ADC_CMDL_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CMDL_ADCH_SHIFT)) & ADC_CMDL_ADCH_MASK)

#define ADC_CMDL_ABSEL_MASK                      (0x20U)
#define ADC_CMDL_ABSEL_SHIFT                     (5U)
/*! ABSEL - A-side or B-side Select
 *  0b0..When CMDLn[DIFF] = 0b, the associated A-side channel is converted as single-ended. When CMDLn[DIFF] = 1b, the ADC result is (CHnA - CHnB).
 *  0b1..When CMDLn[DIFF] = 0b, the associated B-side channel is converted as single-ended. When CMDLn[DIFF] = 1b, the ADC result is (CHnB - CHnA).
 */
#define ADC_CMDL_ABSEL(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CMDL_ABSEL_SHIFT)) & ADC_CMDL_ABSEL_MASK)

#define ADC_CMDL_DIFF_MASK                       (0x40U)
#define ADC_CMDL_DIFF_SHIFT                      (6U)
/*! DIFF - Differential Mode Enable
 *  0b0..Dual-single-ended mode
 *  0b1..Differential mode
 */
#define ADC_CMDL_DIFF(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CMDL_DIFF_SHIFT)) & ADC_CMDL_DIFF_MASK)

#define ADC_CMDL_CSCALE_MASK                     (0x2000U)
#define ADC_CMDL_CSCALE_SHIFT                    (13U)
/*! CSCALE - Channel Scale
 *  0b0..Scale selected analog channel (factor of 30/64)
 *  0b1..Full-scale (factor of 1)
 */
#define ADC_CMDL_CSCALE(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CMDL_CSCALE_SHIFT)) & ADC_CMDL_CSCALE_MASK)
/*! @} */

/* The count of ADC_CMDL */
#define ADC_CMDL_COUNT                           (15U)

/*! @name CMDH - Command High Buffer Register */
/*! @{ */

#define ADC_CMDH_CMPEN_MASK                      (0x3U)
#define ADC_CMDH_CMPEN_SHIFT                     (0U)
/*! CMPEN - Compare Function Enable
 *  0b00..Disabled
 *  0b01..
 *  0b10..Enabled. Store on true.
 *  0b11..Enabled. Repeat channel acquisition (sample, convert, and compare) until true.
 */
#define ADC_CMDH_CMPEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CMDH_CMPEN_SHIFT)) & ADC_CMDH_CMPEN_MASK)

#define ADC_CMDH_WAIT_TRIG_MASK                  (0x4U)
#define ADC_CMDH_WAIT_TRIG_SHIFT                 (2U)
/*! WAIT_TRIG - Wait for Trigger Assertion Before Execution
 *  0b0..Command executes automatically.
 *  0b1..Active trigger must be asserted again before executing this command.
 */
#define ADC_CMDH_WAIT_TRIG(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_CMDH_WAIT_TRIG_SHIFT)) & ADC_CMDH_WAIT_TRIG_MASK)

#define ADC_CMDH_LWI_MASK                        (0x80U)
#define ADC_CMDH_LWI_SHIFT                       (7U)
/*! LWI - Loop with Increment
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ADC_CMDH_LWI(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_CMDH_LWI_SHIFT)) & ADC_CMDH_LWI_MASK)

#define ADC_CMDH_STS_MASK                        (0x700U)
#define ADC_CMDH_STS_SHIFT                       (8U)
/*! STS - Sample Time Select
 *  0b000..Minimum sample time of 3.5 ADCK cycles.
 *  0b001..5.5 ADCK cycles
 *  0b010..7.5 ADCK cycles
 *  0b011..11.5 ADCK cycles
 *  0b100..19.5 ADCK cycles
 *  0b101..35.5 ADCK cycles
 *  0b110..67.5 ADCK cycles
 *  0b111..131.5 ADCK cycles
 */
#define ADC_CMDH_STS(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_CMDH_STS_SHIFT)) & ADC_CMDH_STS_MASK)

#define ADC_CMDH_AVGS_MASK                       (0x7000U)
#define ADC_CMDH_AVGS_SHIFT                      (12U)
/*! AVGS - Hardware Average Select
 *  0b000..Single conversion
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..128
 */
#define ADC_CMDH_AVGS(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CMDH_AVGS_SHIFT)) & ADC_CMDH_AVGS_MASK)

#define ADC_CMDH_LOOP_MASK                       (0xF0000U)
#define ADC_CMDH_LOOP_SHIFT                      (16U)
/*! LOOP - Loop Count Select
 *  0b0000..Looping not enabled. Command executes one time.
 *  0b0001..Loop one time. Command executes two times.
 *  0b0010..Loop two times. Command executes three times.
 *  0b0011-0b1110..Loop corresponding number of times. Command executes LOOP + 1 times.
 *  0b1111..Loop 15 times. Command executes 16 times.
 */
#define ADC_CMDH_LOOP(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CMDH_LOOP_SHIFT)) & ADC_CMDH_LOOP_MASK)

#define ADC_CMDH_NEXT_MASK                       (0xF000000U)
#define ADC_CMDH_NEXT_SHIFT                      (24U)
/*! NEXT - Next Command Select
 *  0b0000..No next command defined. Terminate conversions at completion of current command. If lower priority
 *          trigger pending, begin command associated with lower priority trigger.
 *  0b0001..CMD1
 *  0b0010-0b1110..Select corresponding CMD command buffer register as next command
 *  0b1111..CMD15
 */
#define ADC_CMDH_NEXT(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CMDH_NEXT_SHIFT)) & ADC_CMDH_NEXT_MASK)
/*! @} */

/* The count of ADC_CMDH */
#define ADC_CMDH_COUNT                           (15U)

/*! @name CV - Compare Value Register */
/*! @{ */

#define ADC_CV_CVL_MASK                          (0xFFFFU)
#define ADC_CV_CVL_SHIFT                         (0U)
/*! CVL - Compare Value Low */
#define ADC_CV_CVL(x)                            (((uint32_t)(((uint32_t)(x)) << ADC_CV_CVL_SHIFT)) & ADC_CV_CVL_MASK)

#define ADC_CV_CVH_MASK                          (0xFFFF0000U)
#define ADC_CV_CVH_SHIFT                         (16U)
/*! CVH - Compare Value High */
#define ADC_CV_CVH(x)                            (((uint32_t)(((uint32_t)(x)) << ADC_CV_CVH_SHIFT)) & ADC_CV_CVH_MASK)
/*! @} */

/*! @name RESFIFO - Data Result FIFO Register */
/*! @{ */

#define ADC_RESFIFO_D_MASK                       (0xFFFFU)
#define ADC_RESFIFO_D_SHIFT                      (0U)
/*! D - Data Result */
#define ADC_RESFIFO_D(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_RESFIFO_D_SHIFT)) & ADC_RESFIFO_D_MASK)

#define ADC_RESFIFO_TSRC_MASK                    (0x30000U)
#define ADC_RESFIFO_TSRC_SHIFT                   (16U)
/*! TSRC - Trigger Source
 *  0b00..Trigger source 0
 *  0b01..Trigger source 1
 *  0b10..Trigger source 2
 *  0b11..Trigger source 3
 */
#define ADC_RESFIFO_TSRC(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_RESFIFO_TSRC_SHIFT)) & ADC_RESFIFO_TSRC_MASK)

#define ADC_RESFIFO_LOOPCNT_MASK                 (0xF00000U)
#define ADC_RESFIFO_LOOPCNT_SHIFT                (20U)
/*! LOOPCNT - Loop Count Value
 *  0b0000..Result is from initial conversion in command.
 *  0b0001..Result is from second conversion in command.
 *  0b0010-0b1110..Result is from (LOOPCNT + 1) conversion in command.
 *  0b1111..Result is from 16th conversion in command.
 */
#define ADC_RESFIFO_LOOPCNT(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_RESFIFO_LOOPCNT_SHIFT)) & ADC_RESFIFO_LOOPCNT_MASK)

#define ADC_RESFIFO_CMDSRC_MASK                  (0xF000000U)
#define ADC_RESFIFO_CMDSRC_SHIFT                 (24U)
/*! CMDSRC - Command Buffer Source
 *  0b0000..Not a valid value CMDSRC value for a data word in RESFIFO. 0h is only found in the initial FIFO state,
 *          prior to the storage of an ADC conversion result into a RESFIFO buffer.
 *  0b0001..CMD1
 *  0b0010-0b1110..Corresponding command buffer used as control settings for this conversion.
 *  0b1111..CMD15
 */
#define ADC_RESFIFO_CMDSRC(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_RESFIFO_CMDSRC_SHIFT)) & ADC_RESFIFO_CMDSRC_MASK)

#define ADC_RESFIFO_VALID_MASK                   (0x80000000U)
#define ADC_RESFIFO_VALID_SHIFT                  (31U)
/*! VALID - FIFO Entry is Valid
 *  0b0..FIFO is empty. Discard any read from RESFIFO.
 *  0b1..FIFO contains data. FIFO record read from RESFIFO is valid.
 */
#define ADC_RESFIFO_VALID(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_RESFIFO_VALID_SHIFT)) & ADC_RESFIFO_VALID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ADC_Register_Masks */

/* Backward compatibility */
 #define ADC_CTRL_RSTFIFO_MASK                     ADC_CTRL_RSTFIFO0_MASK
 #define ADC_CTRL_RSTFIFO_SHIFT                    ADC_CTRL_RSTFIFO0_SHIFT
 #define ADC_CTRL_RSTFIFO(x)                       ADC_CTRL_RSTFIFO0(x)
 #define ADC_STAT_RDY_MASK                         ADC_STAT_RDY0_MASK
 #define ADC_STAT_RDY_SHIFT                        ADC_STAT_RDY0_SHIFT
 #define ADC_STAT_RDY(x)                           ADC_STAT_RDY0(x)
 #define ADC_STAT_FOF_MASK                         ADC_STAT_FOF0_MASK
 #define ADC_STAT_FOF_SHIFT                        ADC_STAT_FOF0_SHIFT
 #define ADC_STAT_FOF(x)                           ADC_STAT_FOF0(x)
 #define ADC_IE_FWMIE_MASK                         ADC_IE_FWMIE0_MASK
 #define ADC_IE_FWMIE_SHIFT                        ADC_IE_FWMIE0_SHIFT
 #define ADC_IE_FWMIE(x)                           ADC_IE_FWMIE0(x)
 #define ADC_IE_FOFIE_MASK                         ADC_IE_FOFIE0_MASK
 #define ADC_IE_FOFIE_SHIFT                        ADC_IE_FOFIE0_SHIFT
 #define ADC_IE_FOFIE(x)                           ADC_IE_FOFIE0(x)
 #define ADC_DE_FWMDE_MASK                         ADC_DE_FWMDE0_MASK
 #define ADC_DE_FWMDE_SHIFT                        ADC_DE_FWMDE0_SHIFT
 #define ADC_DE_FWMDE(x)                           ADC_DE_FWMDE0(x)


/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */


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


#endif  /* ADC_H_ */

