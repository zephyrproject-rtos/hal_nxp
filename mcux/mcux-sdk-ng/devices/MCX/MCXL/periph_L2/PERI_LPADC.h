/*
** ###################################################################
**     Processors:          MCXL253VDF_cm0plus
**                          MCXL253VDF_cm33
**                          MCXL253VLL_cm0plus
**                          MCXL253VLL_cm33
**                          MCXL254VDF_cm0plus
**                          MCXL254VDF_cm33
**                          MCXL254VLL_cm0plus
**                          MCXL254VLL_cm33
**                          MCXL255VDF_cm0plus
**                          MCXL255VDF_cm33
**                          MCXL255VLL_cm0plus
**                          MCXL255VLL_cm33
**
**     Version:             rev. 1.0, 2023-01-09
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPADC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-09)
**         Generated based on Rev1 DraftI.
**
** ###################################################################
*/

/*!
 * @file PERI_LPADC.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for LPADC
 *
 * CMSIS Peripheral Access Layer for LPADC
 */

#if !defined(PERI_LPADC_H_)
#define PERI_LPADC_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXL253VDF_cm0plus) || defined(CPU_MCXL253VLL_cm0plus))
#include "MCXL253_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL253VDF_cm33) || defined(CPU_MCXL253VLL_cm33))
#include "MCXL253_cm33_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm0plus) || defined(CPU_MCXL254VLL_cm0plus))
#include "MCXL254_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm33) || defined(CPU_MCXL254VLL_cm33))
#include "MCXL254_cm33_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm0plus) || defined(CPU_MCXL255VLL_cm0plus))
#include "MCXL255_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm33) || defined(CPU_MCXL255VLL_cm33))
#include "MCXL255_cm33_COMMON.h"
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
   -- LPADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPADC_Peripheral_Access_Layer LPADC Peripheral Access Layer
 * @{
 */

/** LPADC - Size of Registers Arrays */
#define LPADC_TCTRL_COUNT                         4u
#define LPADC_CV_COUNT                            4u

/** LPADC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __I  uint32_t PARAM2;                            /**< Parameter 2 Register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t CTRL;                              /**< Control Register, offset: 0x10 */
  __IO uint32_t STAT;                              /**< Status Register, offset: 0x14 */
  __IO uint32_t IE;                                /**< Interrupt Enable Register, offset: 0x18 */
  __IO uint32_t DE;                                /**< DMA Enable Register, offset: 0x1C */
  __IO uint32_t CFG;                               /**< Configuration Register, offset: 0x20 */
  __IO uint32_t PAUSE;                             /**< Pause Register, offset: 0x24 */
       uint8_t RESERVED_1[12];
  __IO uint32_t SWTRIG;                            /**< Software Trigger Register, offset: 0x34 */
  __IO uint32_t TSTAT;                             /**< Trigger Status Register, offset: 0x38 */
  __IO uint32_t CFG2;                              /**< Configuration 2 Register, offset: 0x3C */
  __IO uint32_t OFSTRIM;                           /**< Offset Trim Register, offset: 0x40 */
       uint8_t RESERVED_2[92];
  __IO uint32_t TCTRL[LPADC_TCTRL_COUNT];          /**< Trigger Control Register, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_3[48];
  __IO uint32_t FCTRL0;                            /**< FIFO0 Control Register, offset: 0xE0 */
  __I  uint32_t FCTRL1;                            /**< FIFO1 Control Register, offset: 0xE4 */
       uint8_t RESERVED_4[24];
  __IO uint32_t CMDL1;                             /**< Command Low Buffer Register, offset: 0x100 */
  __IO uint32_t CMDH1;                             /**< Command High Buffer Register, offset: 0x104 */
  __IO uint32_t CMDL2;                             /**< Command Low Buffer Register, offset: 0x108 */
  __IO uint32_t CMDH2;                             /**< Command High Buffer Register, offset: 0x10C */
  __IO uint32_t CMDL3;                             /**< Command Low Buffer Register, offset: 0x110 */
  __IO uint32_t CMDH3;                             /**< Command High Buffer Register, offset: 0x114 */
  __IO uint32_t CMDL4;                             /**< Command Low Buffer Register, offset: 0x118 */
  __IO uint32_t CMDH4;                             /**< Command High Buffer Register, offset: 0x11C */
  __IO uint32_t CMDL5;                             /**< Command Low Buffer Register, offset: 0x120 */
  __IO uint32_t CMDH5;                             /**< Command High Buffer Register, offset: 0x124 */
  __IO uint32_t CMDL6;                             /**< Command Low Buffer Register, offset: 0x128 */
  __IO uint32_t CMDH6;                             /**< Command High Buffer Register, offset: 0x12C */
  __IO uint32_t CMDL7;                             /**< Command Low Buffer Register, offset: 0x130 */
  __IO uint32_t CMDH7;                             /**< Command High Buffer Register, offset: 0x134 */
       uint8_t RESERVED_5[200];
  __IO uint32_t CV[LPADC_CV_COUNT];                /**< Compare Value Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_6[240];
  __I  uint32_t RESFIFO0;                          /**< Data Result FIFO0 Register, offset: 0x300 */
  __I  uint32_t RESFIFO1;                          /**< Data Result FIFO1 Register, offset: 0x304 */
} LPADC_Type;

/* ----------------------------------------------------------------------------
   -- LPADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPADC_Register_Masks LPADC Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define LPADC_VERID_RES_MASK                     (0x1U)
#define LPADC_VERID_RES_SHIFT                    (0U)
/*! RES - Resolution
 *  0b0..Up to 12-bit single ended resolution supported.
 *  0b1..Up to 16-bit single ended resolution supported.
 */
#define LPADC_VERID_RES(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_VERID_RES_SHIFT)) & LPADC_VERID_RES_MASK)

#define LPADC_VERID_DIFFEN_MASK                  (0x2U)
#define LPADC_VERID_DIFFEN_SHIFT                 (1U)
/*! DIFFEN - Differential Supported
 *  0b0..Differential operation not supported.
 *  0b1..Differential operation supported.
 */
#define LPADC_VERID_DIFFEN(x)                    (((uint32_t)(((uint32_t)(x)) << LPADC_VERID_DIFFEN_SHIFT)) & LPADC_VERID_DIFFEN_MASK)

#define LPADC_VERID_MVI_MASK                     (0x8U)
#define LPADC_VERID_MVI_SHIFT                    (3U)
/*! MVI - Multi Vref Implemented
 *  0b0..Single VREFH input supported.
 *  0b1..Multiple VREFH inputs supported.
 */
#define LPADC_VERID_MVI(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_VERID_MVI_SHIFT)) & LPADC_VERID_MVI_MASK)

#define LPADC_VERID_CALOFSI_MASK                 (0x400U)
#define LPADC_VERID_CALOFSI_SHIFT                (10U)
/*! CALOFSI - Offset Calibration Function Implemented
 *  0b0..Offset Calibration Not Implemented.
 *  0b1..Offset Calibration Implemented.
 */
#define LPADC_VERID_CALOFSI(x)                   (((uint32_t)(((uint32_t)(x)) << LPADC_VERID_CALOFSI_SHIFT)) & LPADC_VERID_CALOFSI_MASK)

#define LPADC_VERID_NUM_SEC_MASK                 (0x800U)
#define LPADC_VERID_NUM_SEC_SHIFT                (11U)
/*! NUM_SEC - Number of Single Ended Outputs Supported
 *  0b0..This design supports one single ended conversion at a time.
 *  0b1..This design supports two simultanious single ended conversions.
 */
#define LPADC_VERID_NUM_SEC(x)                   (((uint32_t)(((uint32_t)(x)) << LPADC_VERID_NUM_SEC_SHIFT)) & LPADC_VERID_NUM_SEC_MASK)

#define LPADC_VERID_NUM_FIFO_MASK                (0x7000U)
#define LPADC_VERID_NUM_FIFO_SHIFT               (12U)
/*! NUM_FIFO - Number of FIFOs
 *  0b000..N/A
 *  0b001..This design supports one result FIFO.
 *  0b010..This design supports two result FIFOs.
 */
#define LPADC_VERID_NUM_FIFO(x)                  (((uint32_t)(((uint32_t)(x)) << LPADC_VERID_NUM_FIFO_SHIFT)) & LPADC_VERID_NUM_FIFO_MASK)

#define LPADC_VERID_MINOR_MASK                   (0xFF0000U)
#define LPADC_VERID_MINOR_SHIFT                  (16U)
/*! MINOR - Minor Version Number */
#define LPADC_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_VERID_MINOR_SHIFT)) & LPADC_VERID_MINOR_MASK)

#define LPADC_VERID_MAJOR_MASK                   (0xFF000000U)
#define LPADC_VERID_MAJOR_SHIFT                  (24U)
/*! MAJOR - Major Version Number */
#define LPADC_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_VERID_MAJOR_SHIFT)) & LPADC_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define LPADC_PARAM_TRIG_NUM_MASK                (0xFFU)
#define LPADC_PARAM_TRIG_NUM_SHIFT               (0U)
/*! TRIG_NUM - Trigger Number */
#define LPADC_PARAM_TRIG_NUM(x)                  (((uint32_t)(((uint32_t)(x)) << LPADC_PARAM_TRIG_NUM_SHIFT)) & LPADC_PARAM_TRIG_NUM_MASK)

#define LPADC_PARAM_FIFO0SIZE_MASK               (0xFF00U)
#define LPADC_PARAM_FIFO0SIZE_SHIFT              (8U)
/*! FIFO0SIZE - Result FIFO0 Depth
 *  0b00000001..Result FIFO depth = 1 dataword.
 *  0b00000010..Result FIFO depth = 2 datawords.
 *  0b00000100..Result FIFO depth = 4 datawords.
 *  0b00001000..Result FIFO depth = 8 datawords.
 *  0b00010000..Result FIFO depth = 16 datawords.
 *  0b00100000..Result FIFO depth = 32 datawords.
 *  0b01000000..Result FIFO depth = 64 datawords.
 */
#define LPADC_PARAM_FIFO0SIZE(x)                 (((uint32_t)(((uint32_t)(x)) << LPADC_PARAM_FIFO0SIZE_SHIFT)) & LPADC_PARAM_FIFO0SIZE_MASK)

#define LPADC_PARAM_CV_NUM_MASK                  (0xFF0000U)
#define LPADC_PARAM_CV_NUM_SHIFT                 (16U)
/*! CV_NUM - Compare Value Number */
#define LPADC_PARAM_CV_NUM(x)                    (((uint32_t)(((uint32_t)(x)) << LPADC_PARAM_CV_NUM_SHIFT)) & LPADC_PARAM_CV_NUM_MASK)

#define LPADC_PARAM_CMD_NUM_MASK                 (0xFF000000U)
#define LPADC_PARAM_CMD_NUM_SHIFT                (24U)
/*! CMD_NUM - Command Buffer Number */
#define LPADC_PARAM_CMD_NUM(x)                   (((uint32_t)(((uint32_t)(x)) << LPADC_PARAM_CMD_NUM_SHIFT)) & LPADC_PARAM_CMD_NUM_MASK)
/*! @} */

/*! @name PARAM2 - Parameter 2 Register */
/*! @{ */

#define LPADC_PARAM2_FIFO1SIZE_MASK              (0xFF00U)
#define LPADC_PARAM2_FIFO1SIZE_SHIFT             (8U)
/*! FIFO1SIZE - Result FIFO1 Depth
 *  0b00000000..FIFO1 Not implemented. 0 datawords.
 *  0b00000001..Result FIFO depth = 1 dataword.
 *  0b00000010..Result FIFO depth = 2 datawords.
 *  0b00000100..Result FIFO depth = 4 datawords.
 *  0b00001000..Result FIFO depth = 8 datawords.
 *  0b00010000..Result FIFO depth = 16 datawords.
 *  0b00100000..Result FIFO depth = 32 datawords.
 *  0b01000000..Result FIFO depth = 64 datawords.
 */
#define LPADC_PARAM2_FIFO1SIZE(x)                (((uint32_t)(((uint32_t)(x)) << LPADC_PARAM2_FIFO1SIZE_SHIFT)) & LPADC_PARAM2_FIFO1SIZE_MASK)
/*! @} */

/*! @name CTRL - Control Register */
/*! @{ */

#define LPADC_CTRL_ADCEN_MASK                    (0x1U)
#define LPADC_CTRL_ADCEN_SHIFT                   (0U)
/*! ADCEN - LPADC Enable
 *  0b0..LPADC is disabled.
 *  0b1..LPADC is enabled.
 */
#define LPADC_CTRL_ADCEN(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CTRL_ADCEN_SHIFT)) & LPADC_CTRL_ADCEN_MASK)

#define LPADC_CTRL_RST_MASK                      (0x2U)
#define LPADC_CTRL_RST_SHIFT                     (1U)
/*! RST - Software Reset
 *  0b0..Do not reset LPADC logic
 *  0b1..Reset LPADC logic.
 */
#define LPADC_CTRL_RST(x)                        (((uint32_t)(((uint32_t)(x)) << LPADC_CTRL_RST_SHIFT)) & LPADC_CTRL_RST_MASK)

#define LPADC_CTRL_DOZEN_MASK                    (0x4U)
#define LPADC_CTRL_DOZEN_SHIFT                   (2U)
/*! DOZEN - Doze Enable
 *  0b0..LPADC is enabled in low power mode.
 *  0b1..LPADC is disabled in low power mode.
 */
#define LPADC_CTRL_DOZEN(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CTRL_DOZEN_SHIFT)) & LPADC_CTRL_DOZEN_MASK)

#define LPADC_CTRL_CALOFS_MASK                   (0x10U)
#define LPADC_CTRL_CALOFS_SHIFT                  (4U)
/*! CALOFS - Offset Calibration Request
 *  0b0..No request for offset calibration has been made
 *  0b1..Request for offset calibration function
 */
#define LPADC_CTRL_CALOFS(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_CTRL_CALOFS_SHIFT)) & LPADC_CTRL_CALOFS_MASK)

#define LPADC_CTRL_RSTFIFO0_MASK                 (0x100U)
#define LPADC_CTRL_RSTFIFO0_SHIFT                (8U)
/*! RSTFIFO0 - Reset FIFO0
 *  0b0..No effect.
 *  0b1..FIFO0 is reset.
 */
#define LPADC_CTRL_RSTFIFO0(x)                   (((uint32_t)(((uint32_t)(x)) << LPADC_CTRL_RSTFIFO0_SHIFT)) & LPADC_CTRL_RSTFIFO0_MASK)

#define LPADC_CTRL_RSTFIFO1_MASK                 (0x200U)
#define LPADC_CTRL_RSTFIFO1_SHIFT                (9U)
/*! RSTFIFO1 - Reset FIFO1
 *  0b0..No effect.
 *  0b1..FIFO1 is reset.
 */
#define LPADC_CTRL_RSTFIFO1(x)                   (((uint32_t)(((uint32_t)(x)) << LPADC_CTRL_RSTFIFO1_SHIFT)) & LPADC_CTRL_RSTFIFO1_MASK)

#define LPADC_CTRL_CAL_AVGS_MASK                 (0xF0000U)
#define LPADC_CTRL_CAL_AVGS_SHIFT                (16U)
/*! CAL_AVGS - Calibration Averages
 *  0b0000..Single conversion.
 *  0b0001..2 conversions averaged.
 *  0b0010..4 conversions averaged.
 *  0b0011..8 conversions averaged.
 *  0b0100..16 conversions averaged.
 *  0b0101..32 conversions averaged.
 *  0b0110..64 conversions averaged.
 *  0b0111..128 conversions averaged.
 *  0b1000..256 conversions averaged.
 *  0b1001..512 conversions averaged.
 *  0b1010..1024 conversions averaged.
 */
#define LPADC_CTRL_CAL_AVGS(x)                   (((uint32_t)(((uint32_t)(x)) << LPADC_CTRL_CAL_AVGS_SHIFT)) & LPADC_CTRL_CAL_AVGS_MASK)

#define LPADC_CTRL_CAL_STS_MASK                  (0x700000U)
#define LPADC_CTRL_CAL_STS_SHIFT                 (20U)
/*! CAL_STS - Calibration Sample Time Select
 *  0b000..Sample time set to 1 ADCK cycles.
 *  0b001..Sample time set to 2 ADCK cycles.
 *  0b010..Sample time set to 3 ADCK cycles.
 *  0b011..Sample time set to 4 ADCK cycles.
 *  0b100..Sample time set to 5 ADCK cycles.
 *  0b101..Sample time set to 6 ADCK cycles.
 *  0b110..Sample time set to 7 ADCK cycles.
 *  0b111..Sample time set to 8 ADCK cycles.
 */
#define LPADC_CTRL_CAL_STS(x)                    (((uint32_t)(((uint32_t)(x)) << LPADC_CTRL_CAL_STS_SHIFT)) & LPADC_CTRL_CAL_STS_MASK)
/*! @} */

/*! @name STAT - Status Register */
/*! @{ */

#define LPADC_STAT_RDY0_MASK                     (0x1U)
#define LPADC_STAT_RDY0_SHIFT                    (0U)
/*! RDY0 - Result FIFO0 Ready Flag
 *  0b0..Result FIFO0 data level not above watermark level.
 *  0b1..Result FIFO0 holding data above watermark level.
 */
#define LPADC_STAT_RDY0(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_STAT_RDY0_SHIFT)) & LPADC_STAT_RDY0_MASK)

#define LPADC_STAT_FOF0_MASK                     (0x2U)
#define LPADC_STAT_FOF0_SHIFT                    (1U)
/*! FOF0 - Result FIFO0 Overflow Flag
 *  0b0..No result FIFO0 overflow has occurred since the last time the flag was cleared.
 *  0b1..At least one result FIFO0 overflow has occurred since the last time the flag was cleared.
 */
#define LPADC_STAT_FOF0(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_STAT_FOF0_SHIFT)) & LPADC_STAT_FOF0_MASK)

#define LPADC_STAT_RDY1_MASK                     (0x4U)
#define LPADC_STAT_RDY1_SHIFT                    (2U)
/*! RDY1 - Result FIFO1 Ready Flag
 *  0b0..Result FIFO1 data below watermark level.
 *  0b1..Result FIFO1 holding data above watermark level.
 */
#define LPADC_STAT_RDY1(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_STAT_RDY1_SHIFT)) & LPADC_STAT_RDY1_MASK)

#define LPADC_STAT_FOF1_MASK                     (0x8U)
#define LPADC_STAT_FOF1_SHIFT                    (3U)
/*! FOF1 - Result FIFO1 Overflow Flag
 *  0b0..No result FIFO1 overflow has occurred since the last time the flag was cleared.
 *  0b1..At least one result FIFO1 overflow has occurred since the last time the flag was cleared.
 */
#define LPADC_STAT_FOF1(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_STAT_FOF1_SHIFT)) & LPADC_STAT_FOF1_MASK)

#define LPADC_STAT_TEXC_INT_MASK                 (0x100U)
#define LPADC_STAT_TEXC_INT_SHIFT                (8U)
/*! TEXC_INT - Interrupt Flag For High Priority Trigger Exception
 *  0b0..No trigger exceptions have occurred.
 *  0b1..A trigger exception has occurred and is pending acknowledgement.
 */
#define LPADC_STAT_TEXC_INT(x)                   (((uint32_t)(((uint32_t)(x)) << LPADC_STAT_TEXC_INT_SHIFT)) & LPADC_STAT_TEXC_INT_MASK)

#define LPADC_STAT_TCOMP_INT_MASK                (0x200U)
#define LPADC_STAT_TCOMP_INT_SHIFT               (9U)
/*! TCOMP_INT - Interrupt Flag For Trigger Completion
 *  0b0..Either IE[TCOMP_IE] is set to 0 or no trigger sequences have run to completion.
 *  0b1..Trigger sequence completed; all data is stored in the associated FIFO.
 */
#define LPADC_STAT_TCOMP_INT(x)                  (((uint32_t)(((uint32_t)(x)) << LPADC_STAT_TCOMP_INT_SHIFT)) & LPADC_STAT_TCOMP_INT_MASK)

#define LPADC_STAT_CAL_RDY_MASK                  (0x400U)
#define LPADC_STAT_CAL_RDY_SHIFT                 (10U)
/*! CAL_RDY - Calibration Ready
 *  0b0..Calibration is incomplete or has not been requested.
 *  0b1..The LPADC is calibrated.
 */
#define LPADC_STAT_CAL_RDY(x)                    (((uint32_t)(((uint32_t)(x)) << LPADC_STAT_CAL_RDY_SHIFT)) & LPADC_STAT_CAL_RDY_MASK)

#define LPADC_STAT_ADC_ACTIVE_MASK               (0x800U)
#define LPADC_STAT_ADC_ACTIVE_SHIFT              (11U)
/*! ADC_ACTIVE - ADC Active
 *  0b0..The LPADC is IDLE. There are no pending triggers to service and no active commands are being processed.
 *  0b1..The LPADC is processing a conversion or servicing a trigger.
 */
#define LPADC_STAT_ADC_ACTIVE(x)                 (((uint32_t)(((uint32_t)(x)) << LPADC_STAT_ADC_ACTIVE_SHIFT)) & LPADC_STAT_ADC_ACTIVE_MASK)

#define LPADC_STAT_TRGACT_MASK                   (0x30000U)
#define LPADC_STAT_TRGACT_SHIFT                  (16U)
/*! TRGACT - Trigger Active
 *  0b00..Command (sequence) associated with Trigger 0 currently being executed.
 *  0b01..Command (sequence) associated with Trigger 1 currently being executed.
 *  0b10..Command (sequence) associated with Trigger 2 currently being executed.
 *  0b11..Command (sequence) associated with Trigger 3 currently being executed.
 */
#define LPADC_STAT_TRGACT(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_STAT_TRGACT_SHIFT)) & LPADC_STAT_TRGACT_MASK)

#define LPADC_STAT_CMDACT_MASK                   (0x7000000U)
#define LPADC_STAT_CMDACT_SHIFT                  (24U)
/*! CMDACT - Command Active
 *  0b000..No command is currently in progress.
 *  0b001..Command 1 currently being executed.
 *  0b010..Command 2 currently being executed.
 *  0b011-0b111..Associated command number is currently being executed.
 */
#define LPADC_STAT_CMDACT(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_STAT_CMDACT_SHIFT)) & LPADC_STAT_CMDACT_MASK)
/*! @} */

/*! @name IE - Interrupt Enable Register */
/*! @{ */

#define LPADC_IE_FWMIE0_MASK                     (0x1U)
#define LPADC_IE_FWMIE0_SHIFT                    (0U)
/*! FWMIE0 - FIFO0 Watermark Interrupt Enable
 *  0b0..FIFO0 watermark interrupts are not enabled.
 *  0b1..FIFO0 watermark interrupts are enabled.
 */
#define LPADC_IE_FWMIE0(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_IE_FWMIE0_SHIFT)) & LPADC_IE_FWMIE0_MASK)

#define LPADC_IE_FOFIE0_MASK                     (0x2U)
#define LPADC_IE_FOFIE0_SHIFT                    (1U)
/*! FOFIE0 - Result FIFO0 Overflow Interrupt Enable
 *  0b0..FIFO0 overflow interrupts are not enabled.
 *  0b1..FIFO0 overflow interrupts are enabled.
 */
#define LPADC_IE_FOFIE0(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_IE_FOFIE0_SHIFT)) & LPADC_IE_FOFIE0_MASK)

#define LPADC_IE_FWMIE1_MASK                     (0x4U)
#define LPADC_IE_FWMIE1_SHIFT                    (2U)
/*! FWMIE1 - FIFO1 Watermark Interrupt Enable
 *  0b0..FIFO1 watermark interrupts are not enabled.
 *  0b1..FIFO1 watermark interrupts are enabled.
 */
#define LPADC_IE_FWMIE1(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_IE_FWMIE1_SHIFT)) & LPADC_IE_FWMIE1_MASK)

#define LPADC_IE_FOFIE1_MASK                     (0x8U)
#define LPADC_IE_FOFIE1_SHIFT                    (3U)
/*! FOFIE1 - Result FIFO1 Overflow Interrupt Enable
 *  0b0..FIFO1 overflow interrupts are not enabled.
 *  0b1..FIFO1 overflow interrupts are enabled.
 */
#define LPADC_IE_FOFIE1(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_IE_FOFIE1_SHIFT)) & LPADC_IE_FOFIE1_MASK)

#define LPADC_IE_TEXC_IE_MASK                    (0x100U)
#define LPADC_IE_TEXC_IE_SHIFT                   (8U)
/*! TEXC_IE - Trigger Exception Interrupt Enable
 *  0b0..Trigger exception interrupts are disabled.
 *  0b1..Trigger exception interrupts are enabled.
 */
#define LPADC_IE_TEXC_IE(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_IE_TEXC_IE_SHIFT)) & LPADC_IE_TEXC_IE_MASK)

#define LPADC_IE_TCOMP_IE_MASK                   (0xF0000U)
#define LPADC_IE_TCOMP_IE_SHIFT                  (16U)
/*! TCOMP_IE - Trigger Completion Interrupt Enable
 *  0b0000..Trigger completion interrupts are disabled.
 *  0b0001..Trigger completion interrupts are enabled for trigger source 0 only.
 *  0b0010..Trigger completion interrupts are enabled for trigger source 1 only.
 *  0b0011-0b1110..Associated trigger completion interrupts are enabled.
 *  0b1111..Trigger completion interrupts are enabled for every trigger source.
 */
#define LPADC_IE_TCOMP_IE(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_IE_TCOMP_IE_SHIFT)) & LPADC_IE_TCOMP_IE_MASK)
/*! @} */

/*! @name DE - DMA Enable Register */
/*! @{ */

#define LPADC_DE_FWMDE0_MASK                     (0x1U)
#define LPADC_DE_FWMDE0_SHIFT                    (0U)
/*! FWMDE0 - FIFO0 Watermark DMA Enable
 *  0b0..DMA request disabled.
 *  0b1..DMA request enabled.
 */
#define LPADC_DE_FWMDE0(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_DE_FWMDE0_SHIFT)) & LPADC_DE_FWMDE0_MASK)

#define LPADC_DE_FWMDE1_MASK                     (0x2U)
#define LPADC_DE_FWMDE1_SHIFT                    (1U)
/*! FWMDE1 - FIFO1 Watermark DMA Enable
 *  0b0..DMA request disabled.
 *  0b1..DMA request enabled.
 */
#define LPADC_DE_FWMDE1(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_DE_FWMDE1_SHIFT)) & LPADC_DE_FWMDE1_MASK)
/*! @} */

/*! @name CFG - Configuration Register */
/*! @{ */

#define LPADC_CFG_TPRICTRL_MASK                  (0x3U)
#define LPADC_CFG_TPRICTRL_SHIFT                 (0U)
/*! TPRICTRL - LPADC Trigger Priority Control
 *  0b00..If a higher priority trigger is detected during command processing, the current conversion is aborted
 *        and the new command specified by the trigger is started.
 *  0b01..If a higher priority trigger is received during command processing, the current command is stopped after
 *        completing the current conversion. If averaging is enabled, the averaging iterations are completed.
 *        However, CMDHn[LOOP] is ignored and the higher priority trigger will be serviced.
 *  0b10..If a higher priority trigger is received during command processing, the current command is completed
 *        (averaging, looping, compare) before servicing the higher priority trigger.
 *  0b11..
 */
#define LPADC_CFG_TPRICTRL(x)                    (((uint32_t)(((uint32_t)(x)) << LPADC_CFG_TPRICTRL_SHIFT)) & LPADC_CFG_TPRICTRL_MASK)

#define LPADC_CFG_PWRSEL_MASK                    (0x20U)
#define LPADC_CFG_PWRSEL_SHIFT                   (5U)
/*! PWRSEL - Power Configuration Select */
#define LPADC_CFG_PWRSEL(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CFG_PWRSEL_SHIFT)) & LPADC_CFG_PWRSEL_MASK)

#define LPADC_CFG_REFSEL_MASK                    (0x40U)
#define LPADC_CFG_REFSEL_SHIFT                   (6U)
/*! REFSEL - Voltage Reference Selection
 *  0b0..(Default) Option 1 setting.
 *  0b1..Option 2 setting.
 */
#define LPADC_CFG_REFSEL(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CFG_REFSEL_SHIFT)) & LPADC_CFG_REFSEL_MASK)

#define LPADC_CFG_TRES_MASK                      (0x100U)
#define LPADC_CFG_TRES_SHIFT                     (8U)
/*! TRES - Trigger Resume Enable
 *  0b0..Trigger sequences interrupted by a high priority trigger exception are not automatically resumed or restarted.
 *  0b1..Trigger sequences interrupted by a high priority trigger exception are automatically resumed or restarted.
 */
#define LPADC_CFG_TRES(x)                        (((uint32_t)(((uint32_t)(x)) << LPADC_CFG_TRES_SHIFT)) & LPADC_CFG_TRES_MASK)

#define LPADC_CFG_TCMDRES_MASK                   (0x200U)
#define LPADC_CFG_TCMDRES_SHIFT                  (9U)
/*! TCMDRES - Trigger Command Resume
 *  0b0..Trigger sequences interrupted by a high priority trigger exception is automatically restarted.
 *  0b1..Trigger sequences interrupted by a high priority trigger exception is resumed from the command executing before the exception.
 */
#define LPADC_CFG_TCMDRES(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_CFG_TCMDRES_SHIFT)) & LPADC_CFG_TCMDRES_MASK)

#define LPADC_CFG_HPT_EXDI_MASK                  (0x400U)
#define LPADC_CFG_HPT_EXDI_SHIFT                 (10U)
/*! HPT_EXDI - High Priority Trigger Exception Disable
 *  0b0..High priority trigger exceptions are enabled.
 *  0b1..High priority trigger exceptions are disabled.
 */
#define LPADC_CFG_HPT_EXDI(x)                    (((uint32_t)(((uint32_t)(x)) << LPADC_CFG_HPT_EXDI_SHIFT)) & LPADC_CFG_HPT_EXDI_MASK)
/*! @} */

/*! @name PAUSE - Pause Register */
/*! @{ */

#define LPADC_PAUSE_PAUSEDLY_MASK                (0x1FFU)
#define LPADC_PAUSE_PAUSEDLY_SHIFT               (0U)
/*! PAUSEDLY - Pause Delay */
#define LPADC_PAUSE_PAUSEDLY(x)                  (((uint32_t)(((uint32_t)(x)) << LPADC_PAUSE_PAUSEDLY_SHIFT)) & LPADC_PAUSE_PAUSEDLY_MASK)

#define LPADC_PAUSE_PAUSEEN_MASK                 (0x80000000U)
#define LPADC_PAUSE_PAUSEEN_SHIFT                (31U)
/*! PAUSEEN - PAUSE Option Enable
 *  0b0..Pause operation disabled
 *  0b1..Pause operation enabled
 */
#define LPADC_PAUSE_PAUSEEN(x)                   (((uint32_t)(((uint32_t)(x)) << LPADC_PAUSE_PAUSEEN_SHIFT)) & LPADC_PAUSE_PAUSEEN_MASK)
/*! @} */

/*! @name SWTRIG - Software Trigger Register */
/*! @{ */

#define LPADC_SWTRIG_SWT0_MASK                   (0x1U)
#define LPADC_SWTRIG_SWT0_SHIFT                  (0U)
/*! SWT0 - Software Trigger 0 Event
 *  0b0..No trigger 0 event generated.
 *  0b1..Trigger 0 event generated.
 */
#define LPADC_SWTRIG_SWT0(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_SWTRIG_SWT0_SHIFT)) & LPADC_SWTRIG_SWT0_MASK)

#define LPADC_SWTRIG_SWT1_MASK                   (0x2U)
#define LPADC_SWTRIG_SWT1_SHIFT                  (1U)
/*! SWT1 - Software Trigger 1 Event
 *  0b0..No trigger 1 event generated.
 *  0b1..Trigger 1 event generated.
 */
#define LPADC_SWTRIG_SWT1(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_SWTRIG_SWT1_SHIFT)) & LPADC_SWTRIG_SWT1_MASK)

#define LPADC_SWTRIG_SWT2_MASK                   (0x4U)
#define LPADC_SWTRIG_SWT2_SHIFT                  (2U)
/*! SWT2 - Software Trigger 2 Event
 *  0b0..No trigger 2 event generated.
 *  0b1..Trigger 2 event generated.
 */
#define LPADC_SWTRIG_SWT2(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_SWTRIG_SWT2_SHIFT)) & LPADC_SWTRIG_SWT2_MASK)

#define LPADC_SWTRIG_SWT3_MASK                   (0x8U)
#define LPADC_SWTRIG_SWT3_SHIFT                  (3U)
/*! SWT3 - Software Trigger 3 Event
 *  0b0..No trigger 3 event generated.
 *  0b1..Trigger 3 event generated.
 */
#define LPADC_SWTRIG_SWT3(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_SWTRIG_SWT3_SHIFT)) & LPADC_SWTRIG_SWT3_MASK)
/*! @} */

/*! @name TSTAT - Trigger Status Register */
/*! @{ */

#define LPADC_TSTAT_TEXC_NUM_MASK                (0xFU)
#define LPADC_TSTAT_TEXC_NUM_SHIFT               (0U)
/*! TEXC_NUM - Trigger Exception Number
 *  0b0000..No triggers have been interrupted by a high priority exception. Or CFG[TRES] = 1.
 *  0b0001..Trigger 0 has been interrupted by a high priority exception.
 *  0b0010..Trigger 1 has been interrupted by a high priority exception.
 *  0b0011-0b1110..Associated trigger sequence has been interrupted by a high priority exception.
 *  0b1111..Every trigger sequence has been interrupted by a high priority exception.
 */
#define LPADC_TSTAT_TEXC_NUM(x)                  (((uint32_t)(((uint32_t)(x)) << LPADC_TSTAT_TEXC_NUM_SHIFT)) & LPADC_TSTAT_TEXC_NUM_MASK)

#define LPADC_TSTAT_TCOMP_FLAG_MASK              (0xF0000U)
#define LPADC_TSTAT_TCOMP_FLAG_SHIFT             (16U)
/*! TCOMP_FLAG - Trigger Completion Flag
 *  0b0000..No triggers have been completed. Trigger completion interrupts are disabled.
 *  0b0001..Trigger 0 has been completed and trigger 0 has enabled completion interrupts.
 *  0b0010..Trigger 1 has been completed and trigger 1 has enabled completion interrupts.
 *  0b0011-0b1110..Associated trigger sequence has completed and has enabled completion interrupts.
 *  0b1111..Every trigger sequence has been completed and every trigger has enabled completion interrupts.
 */
#define LPADC_TSTAT_TCOMP_FLAG(x)                (((uint32_t)(((uint32_t)(x)) << LPADC_TSTAT_TCOMP_FLAG_SHIFT)) & LPADC_TSTAT_TCOMP_FLAG_MASK)
/*! @} */

/*! @name CFG2 - Configuration 2 Register */
/*! @{ */

#define LPADC_CFG2_DAC_SETTLE_DLY_MASK           (0x3U)
#define LPADC_CFG2_DAC_SETTLE_DLY_SHIFT          (0U)
/*! DAC_SETTLE_DLY - Dac Settle Delay
 *  0b00..Fastest settling
 *  0b11..Slowest settling
 */
#define LPADC_CFG2_DAC_SETTLE_DLY(x)             (((uint32_t)(((uint32_t)(x)) << LPADC_CFG2_DAC_SETTLE_DLY_SHIFT)) & LPADC_CFG2_DAC_SETTLE_DLY_MASK)

#define LPADC_CFG2_CTS_MASK                      (0xF000U)
#define LPADC_CFG2_CTS_SHIFT                     (12U)
/*! CTS - Compare Time Select */
#define LPADC_CFG2_CTS(x)                        (((uint32_t)(((uint32_t)(x)) << LPADC_CFG2_CTS_SHIFT)) & LPADC_CFG2_CTS_MASK)

#define LPADC_CFG2_DEM_EN_MASK                   (0x10000U)
#define LPADC_CFG2_DEM_EN_SHIFT                  (16U)
/*! DEM_EN - Enable Dynamic Element Matching
 *  0b0..Dynamic Element Matching Disabled
 *  0b1..Dynamic Element Matching Enabled when CMDHn[AVGS] equal to non-zero.
 */
#define LPADC_CFG2_DEM_EN(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_CFG2_DEM_EN_SHIFT)) & LPADC_CFG2_DEM_EN_MASK)
/*! @} */

/*! @name OFSTRIM - Offset Trim Register */
/*! @{ */

#define LPADC_OFSTRIM_OFSTRIM_MASK               (0xFFU)
#define LPADC_OFSTRIM_OFSTRIM_SHIFT              (0U)
/*! OFSTRIM - Trim for Offset */
#define LPADC_OFSTRIM_OFSTRIM(x)                 (((uint32_t)(((uint32_t)(x)) << LPADC_OFSTRIM_OFSTRIM_SHIFT)) & LPADC_OFSTRIM_OFSTRIM_MASK)
/*! @} */

/*! @name TCTRL - Trigger Control Register */
/*! @{ */

#define LPADC_TCTRL_HTEN_MASK                    (0x1U)
#define LPADC_TCTRL_HTEN_SHIFT                   (0U)
/*! HTEN - Trigger Enable
 *  0b0..Hardware trigger source disabled
 *  0b1..Hardware trigger source enabled
 */
#define LPADC_TCTRL_HTEN(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_TCTRL_HTEN_SHIFT)) & LPADC_TCTRL_HTEN_MASK)

#define LPADC_TCTRL_FIFO_SEL_MASK                (0x2U)
#define LPADC_TCTRL_FIFO_SEL_SHIFT               (1U)
/*! FIFO_SEL - SAR Result Destination
 *  0b0..Conversion results stored to FIFO0
 *  0b1..Conversion results stored to FIFO1
 */
#define LPADC_TCTRL_FIFO_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << LPADC_TCTRL_FIFO_SEL_SHIFT)) & LPADC_TCTRL_FIFO_SEL_MASK)

#define LPADC_TCTRL_TPRI_MASK                    (0x300U)
#define LPADC_TCTRL_TPRI_SHIFT                   (8U)
/*! TPRI - Trigger Priority Setting
 *  0b00..Set to highest priority, Level 1
 *  0b01-0b10..Set to corresponding priority level
 *  0b11..Set to lowest priority, Level 4
 */
#define LPADC_TCTRL_TPRI(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_TCTRL_TPRI_SHIFT)) & LPADC_TCTRL_TPRI_MASK)

#define LPADC_TCTRL_TDLY_MASK                    (0xF0000U)
#define LPADC_TCTRL_TDLY_SHIFT                   (16U)
/*! TDLY - Trigger Delay Select */
#define LPADC_TCTRL_TDLY(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_TCTRL_TDLY_SHIFT)) & LPADC_TCTRL_TDLY_MASK)

#define LPADC_TCTRL_TCMD_MASK                    (0x7000000U)
#define LPADC_TCTRL_TCMD_SHIFT                   (24U)
/*! TCMD - Trigger Command Select
 *  0b000..Not a valid selection from the command buffer. Trigger event is ignored.
 *  0b001..CMD1 is executed
 *  0b010-0b110..Corresponding CMD is executed
 *  0b111..CMD7 is executed
 */
#define LPADC_TCTRL_TCMD(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_TCTRL_TCMD_SHIFT)) & LPADC_TCTRL_TCMD_MASK)
/*! @} */

/*! @name FCTRL0 - FIFO0 Control Register */
/*! @{ */

#define LPADC_FCTRL0_FCOUNT_MASK                 (0x1FU)
#define LPADC_FCTRL0_FCOUNT_SHIFT                (0U)
/*! FCOUNT - Result FIFO Counter */
#define LPADC_FCTRL0_FCOUNT(x)                   (((uint32_t)(((uint32_t)(x)) << LPADC_FCTRL0_FCOUNT_SHIFT)) & LPADC_FCTRL0_FCOUNT_MASK)

#define LPADC_FCTRL0_FWMARK_MASK                 (0xF0000U)
#define LPADC_FCTRL0_FWMARK_SHIFT                (16U)
/*! FWMARK - Watermark Level Selection */
#define LPADC_FCTRL0_FWMARK(x)                   (((uint32_t)(((uint32_t)(x)) << LPADC_FCTRL0_FWMARK_SHIFT)) & LPADC_FCTRL0_FWMARK_MASK)
/*! @} */

/*! @name FCTRL1 - FIFO1 Control Register */
/*! @{ */

#define LPADC_FCTRL1_FCOUNT_MASK                 (0x1U)
#define LPADC_FCTRL1_FCOUNT_SHIFT                (0U)
/*! FCOUNT - Result FIFO Counter */
#define LPADC_FCTRL1_FCOUNT(x)                   (((uint32_t)(((uint32_t)(x)) << LPADC_FCTRL1_FCOUNT_SHIFT)) & LPADC_FCTRL1_FCOUNT_MASK)

#define LPADC_FCTRL1_FWMARK_MASK                 (0x10000U)
#define LPADC_FCTRL1_FWMARK_SHIFT                (16U)
/*! FWMARK - Watermark Level Selection */
#define LPADC_FCTRL1_FWMARK(x)                   (((uint32_t)(((uint32_t)(x)) << LPADC_FCTRL1_FWMARK_SHIFT)) & LPADC_FCTRL1_FWMARK_MASK)
/*! @} */

/*! @name CMDL1 - Command Low Buffer Register */
/*! @{ */

#define LPADC_CMDL1_ADCH_MASK                    (0x1FU)
#define LPADC_CMDL1_ADCH_SHIFT                   (0U)
/*! ADCH - Input Channel Select
 *  0b00000..Select CH0A.
 *  0b00001..Select CH1A.
 *  0b00010..Select CH2A.
 *  0b00011..Select CH3A.
 *  0b00100-0b11101..Select corresponding channel CHnA.
 *  0b11110..Select CH30A.
 *  0b11111..Select CH31A.
 */
#define LPADC_CMDL1_ADCH(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDL1_ADCH_SHIFT)) & LPADC_CMDL1_ADCH_MASK)

#define LPADC_CMDL1_CTYPE_MASK                   (0x60U)
#define LPADC_CMDL1_CTYPE_SHIFT                  (5U)
/*! CTYPE - Conversion Type
 *  0b00..Single-Ended Mode. Only A side channel is converted.
 *  0b01-0b11..Reserved.
 */
#define LPADC_CMDL1_CTYPE(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_CMDL1_CTYPE_SHIFT)) & LPADC_CMDL1_CTYPE_MASK)
/*! @} */

/*! @name CMDH1 - Command High Buffer Register */
/*! @{ */

#define LPADC_CMDH1_CMPEN_MASK                   (0x3U)
#define LPADC_CMDH1_CMPEN_SHIFT                  (0U)
/*! CMPEN - Compare Function Enable
 *  0b00..Compare disabled.
 *  0b01..Reserved
 *  0b10..Compare enabled. Store on true.
 *  0b11..Compare enabled. Repeat channel acquisition (sample, convert, compare) until true.
 */
#define LPADC_CMDH1_CMPEN(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH1_CMPEN_SHIFT)) & LPADC_CMDH1_CMPEN_MASK)

#define LPADC_CMDH1_WAIT_TRIG_MASK               (0x4U)
#define LPADC_CMDH1_WAIT_TRIG_SHIFT              (2U)
/*! WAIT_TRIG - Wait for Trigger Assertion before Execution.
 *  0b0..This command automatically executes.
 *  0b1..The active trigger must be asserted again before executing this command.
 */
#define LPADC_CMDH1_WAIT_TRIG(x)                 (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH1_WAIT_TRIG_SHIFT)) & LPADC_CMDH1_WAIT_TRIG_MASK)

#define LPADC_CMDH1_LWI_MASK                     (0x80U)
#define LPADC_CMDH1_LWI_SHIFT                    (7U)
/*! LWI - Loop with Increment
 *  0b0..Auto channel increment disabled
 *  0b1..Auto channel increment enabled
 */
#define LPADC_CMDH1_LWI(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH1_LWI_SHIFT)) & LPADC_CMDH1_LWI_MASK)

#define LPADC_CMDH1_STS_MASK                     (0xF00U)
#define LPADC_CMDH1_STS_SHIFT                    (8U)
/*! STS - Sample Time Select */
#define LPADC_CMDH1_STS(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH1_STS_SHIFT)) & LPADC_CMDH1_STS_MASK)

#define LPADC_CMDH1_AVGS_MASK                    (0xF000U)
#define LPADC_CMDH1_AVGS_SHIFT                   (12U)
/*! AVGS - Hardware Average Select
 *  0b0000..Single conversion.
 *  0b0001..2 conversions averaged.
 *  0b0010..4 conversions averaged.
 *  0b0011..8 conversions averaged.
 *  0b0100..16 conversions averaged.
 *  0b0101..32 conversions averaged.
 *  0b0110..64 conversions averaged.
 *  0b0111..128 conversions averaged.
 *  0b1000..256 conversions averaged.
 *  0b1001..512 conversions averaged.
 *  0b1010..1024 conversions averaged.
 */
#define LPADC_CMDH1_AVGS(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH1_AVGS_SHIFT)) & LPADC_CMDH1_AVGS_MASK)

#define LPADC_CMDH1_LOOP_MASK                    (0xF0000U)
#define LPADC_CMDH1_LOOP_SHIFT                   (16U)
/*! LOOP - Loop Count Select
 *  0b0000..Looping not enabled; command executes 1 time.
 *  0b0001..Loop 1 time; command executes 2 times.
 *  0b0010..Loop 2 times; command executes 3 times.
 *  0b0011-0b1110..Loop corresponding number of times; command executes LOOP + 1 times.
 *  0b1111..Loop 15 times; command executes 16 times.
 */
#define LPADC_CMDH1_LOOP(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH1_LOOP_SHIFT)) & LPADC_CMDH1_LOOP_MASK)

#define LPADC_CMDH1_NEXT_MASK                    (0x7000000U)
#define LPADC_CMDH1_NEXT_SHIFT                   (24U)
/*! NEXT - Next Command Select
 *  0b000..No next command defined. Terminate conversions at completion of current command. If lower priority
 *         trigger pending, begin command associated with lower priority trigger.
 *  0b001..Select CMD1 command buffer register as next command.
 *  0b010-0b110..Select corresponding CMD command buffer register as next command
 *  0b111..Select CMD7 command buffer register as next command.
 */
#define LPADC_CMDH1_NEXT(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH1_NEXT_SHIFT)) & LPADC_CMDH1_NEXT_MASK)
/*! @} */

/*! @name CMDL2 - Command Low Buffer Register */
/*! @{ */

#define LPADC_CMDL2_ADCH_MASK                    (0x1FU)
#define LPADC_CMDL2_ADCH_SHIFT                   (0U)
/*! ADCH - Input Channel Select
 *  0b00000..Select CH0A.
 *  0b00001..Select CH1A.
 *  0b00010..Select CH2A.
 *  0b00011..Select CH3A.
 *  0b00100-0b11101..Select corresponding channel CHnA.
 *  0b11110..Select CH30A.
 *  0b11111..Select CH31A.
 */
#define LPADC_CMDL2_ADCH(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDL2_ADCH_SHIFT)) & LPADC_CMDL2_ADCH_MASK)

#define LPADC_CMDL2_CTYPE_MASK                   (0x60U)
#define LPADC_CMDL2_CTYPE_SHIFT                  (5U)
/*! CTYPE - Conversion Type
 *  0b00..Single-Ended Mode. Only A side channel is converted.
 *  0b01-0b11..Reserved.
 */
#define LPADC_CMDL2_CTYPE(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_CMDL2_CTYPE_SHIFT)) & LPADC_CMDL2_CTYPE_MASK)
/*! @} */

/*! @name CMDH2 - Command High Buffer Register */
/*! @{ */

#define LPADC_CMDH2_CMPEN_MASK                   (0x3U)
#define LPADC_CMDH2_CMPEN_SHIFT                  (0U)
/*! CMPEN - Compare Function Enable
 *  0b00..Compare disabled.
 *  0b01..Reserved
 *  0b10..Compare enabled. Store on true.
 *  0b11..Compare enabled. Repeat channel acquisition (sample, convert, compare) until true.
 */
#define LPADC_CMDH2_CMPEN(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH2_CMPEN_SHIFT)) & LPADC_CMDH2_CMPEN_MASK)

#define LPADC_CMDH2_WAIT_TRIG_MASK               (0x4U)
#define LPADC_CMDH2_WAIT_TRIG_SHIFT              (2U)
/*! WAIT_TRIG - Wait for Trigger Assertion before Execution.
 *  0b0..This command automatically executes.
 *  0b1..The active trigger must be asserted again before executing this command.
 */
#define LPADC_CMDH2_WAIT_TRIG(x)                 (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH2_WAIT_TRIG_SHIFT)) & LPADC_CMDH2_WAIT_TRIG_MASK)

#define LPADC_CMDH2_LWI_MASK                     (0x80U)
#define LPADC_CMDH2_LWI_SHIFT                    (7U)
/*! LWI - Loop with Increment
 *  0b0..Auto channel increment disabled
 *  0b1..Auto channel increment enabled
 */
#define LPADC_CMDH2_LWI(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH2_LWI_SHIFT)) & LPADC_CMDH2_LWI_MASK)

#define LPADC_CMDH2_STS_MASK                     (0xF00U)
#define LPADC_CMDH2_STS_SHIFT                    (8U)
/*! STS - Sample Time Select */
#define LPADC_CMDH2_STS(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH2_STS_SHIFT)) & LPADC_CMDH2_STS_MASK)

#define LPADC_CMDH2_AVGS_MASK                    (0xF000U)
#define LPADC_CMDH2_AVGS_SHIFT                   (12U)
/*! AVGS - Hardware Average Select
 *  0b0000..Single conversion.
 *  0b0001..2 conversions averaged.
 *  0b0010..4 conversions averaged.
 *  0b0011..8 conversions averaged.
 *  0b0100..16 conversions averaged.
 *  0b0101..32 conversions averaged.
 *  0b0110..64 conversions averaged.
 *  0b0111..128 conversions averaged.
 *  0b1000..256 conversions averaged.
 *  0b1001..512 conversions averaged.
 *  0b1010..1024 conversions averaged.
 */
#define LPADC_CMDH2_AVGS(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH2_AVGS_SHIFT)) & LPADC_CMDH2_AVGS_MASK)

#define LPADC_CMDH2_LOOP_MASK                    (0xF0000U)
#define LPADC_CMDH2_LOOP_SHIFT                   (16U)
/*! LOOP - Loop Count Select
 *  0b0000..Looping not enabled; command executes 1 time.
 *  0b0001..Loop 1 time; command executes 2 times.
 *  0b0010..Loop 2 times; command executes 3 times.
 *  0b0011-0b1110..Loop corresponding number of times; command executes LOOP + 1 times.
 *  0b1111..Loop 15 times; command executes 16 times.
 */
#define LPADC_CMDH2_LOOP(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH2_LOOP_SHIFT)) & LPADC_CMDH2_LOOP_MASK)

#define LPADC_CMDH2_NEXT_MASK                    (0x7000000U)
#define LPADC_CMDH2_NEXT_SHIFT                   (24U)
/*! NEXT - Next Command Select
 *  0b000..No next command defined. Terminate conversions at completion of current command. If lower priority
 *         trigger pending, begin command associated with lower priority trigger.
 *  0b001..Select CMD1 command buffer register as next command.
 *  0b010-0b110..Select corresponding CMD command buffer register as next command
 *  0b111..Select CMD7 command buffer register as next command.
 */
#define LPADC_CMDH2_NEXT(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH2_NEXT_SHIFT)) & LPADC_CMDH2_NEXT_MASK)
/*! @} */

/*! @name CMDL3 - Command Low Buffer Register */
/*! @{ */

#define LPADC_CMDL3_ADCH_MASK                    (0x1FU)
#define LPADC_CMDL3_ADCH_SHIFT                   (0U)
/*! ADCH - Input Channel Select
 *  0b00000..Select CH0A.
 *  0b00001..Select CH1A.
 *  0b00010..Select CH2A.
 *  0b00011..Select CH3A.
 *  0b00100-0b11101..Select corresponding channel CHnA.
 *  0b11110..Select CH30A.
 *  0b11111..Select CH31A.
 */
#define LPADC_CMDL3_ADCH(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDL3_ADCH_SHIFT)) & LPADC_CMDL3_ADCH_MASK)

#define LPADC_CMDL3_CTYPE_MASK                   (0x60U)
#define LPADC_CMDL3_CTYPE_SHIFT                  (5U)
/*! CTYPE - Conversion Type
 *  0b00..Single-Ended Mode. Only A side channel is converted.
 *  0b01-0b11..Reserved.
 */
#define LPADC_CMDL3_CTYPE(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_CMDL3_CTYPE_SHIFT)) & LPADC_CMDL3_CTYPE_MASK)
/*! @} */

/*! @name CMDH3 - Command High Buffer Register */
/*! @{ */

#define LPADC_CMDH3_CMPEN_MASK                   (0x3U)
#define LPADC_CMDH3_CMPEN_SHIFT                  (0U)
/*! CMPEN - Compare Function Enable
 *  0b00..Compare disabled.
 *  0b01..Reserved
 *  0b10..Compare enabled. Store on true.
 *  0b11..Compare enabled. Repeat channel acquisition (sample, convert, compare) until true.
 */
#define LPADC_CMDH3_CMPEN(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH3_CMPEN_SHIFT)) & LPADC_CMDH3_CMPEN_MASK)

#define LPADC_CMDH3_WAIT_TRIG_MASK               (0x4U)
#define LPADC_CMDH3_WAIT_TRIG_SHIFT              (2U)
/*! WAIT_TRIG - Wait for Trigger Assertion before Execution.
 *  0b0..This command automatically executes.
 *  0b1..The active trigger must be asserted again before executing this command.
 */
#define LPADC_CMDH3_WAIT_TRIG(x)                 (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH3_WAIT_TRIG_SHIFT)) & LPADC_CMDH3_WAIT_TRIG_MASK)

#define LPADC_CMDH3_LWI_MASK                     (0x80U)
#define LPADC_CMDH3_LWI_SHIFT                    (7U)
/*! LWI - Loop with Increment
 *  0b0..Auto channel increment disabled
 *  0b1..Auto channel increment enabled
 */
#define LPADC_CMDH3_LWI(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH3_LWI_SHIFT)) & LPADC_CMDH3_LWI_MASK)

#define LPADC_CMDH3_STS_MASK                     (0xF00U)
#define LPADC_CMDH3_STS_SHIFT                    (8U)
/*! STS - Sample Time Select */
#define LPADC_CMDH3_STS(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH3_STS_SHIFT)) & LPADC_CMDH3_STS_MASK)

#define LPADC_CMDH3_AVGS_MASK                    (0xF000U)
#define LPADC_CMDH3_AVGS_SHIFT                   (12U)
/*! AVGS - Hardware Average Select
 *  0b0000..Single conversion.
 *  0b0001..2 conversions averaged.
 *  0b0010..4 conversions averaged.
 *  0b0011..8 conversions averaged.
 *  0b0100..16 conversions averaged.
 *  0b0101..32 conversions averaged.
 *  0b0110..64 conversions averaged.
 *  0b0111..128 conversions averaged.
 *  0b1000..256 conversions averaged.
 *  0b1001..512 conversions averaged.
 *  0b1010..1024 conversions averaged.
 */
#define LPADC_CMDH3_AVGS(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH3_AVGS_SHIFT)) & LPADC_CMDH3_AVGS_MASK)

#define LPADC_CMDH3_LOOP_MASK                    (0xF0000U)
#define LPADC_CMDH3_LOOP_SHIFT                   (16U)
/*! LOOP - Loop Count Select
 *  0b0000..Looping not enabled; command executes 1 time.
 *  0b0001..Loop 1 time; command executes 2 times.
 *  0b0010..Loop 2 times; command executes 3 times.
 *  0b0011-0b1110..Loop corresponding number of times; command executes LOOP + 1 times.
 *  0b1111..Loop 15 times; command executes 16 times.
 */
#define LPADC_CMDH3_LOOP(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH3_LOOP_SHIFT)) & LPADC_CMDH3_LOOP_MASK)

#define LPADC_CMDH3_NEXT_MASK                    (0x7000000U)
#define LPADC_CMDH3_NEXT_SHIFT                   (24U)
/*! NEXT - Next Command Select
 *  0b000..No next command defined. Terminate conversions at completion of current command. If lower priority
 *         trigger pending, begin command associated with lower priority trigger.
 *  0b001..Select CMD1 command buffer register as next command.
 *  0b010-0b110..Select corresponding CMD command buffer register as next command
 *  0b111..Select CMD7 command buffer register as next command.
 */
#define LPADC_CMDH3_NEXT(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH3_NEXT_SHIFT)) & LPADC_CMDH3_NEXT_MASK)
/*! @} */

/*! @name CMDL4 - Command Low Buffer Register */
/*! @{ */

#define LPADC_CMDL4_ADCH_MASK                    (0x1FU)
#define LPADC_CMDL4_ADCH_SHIFT                   (0U)
/*! ADCH - Input Channel Select
 *  0b00000..Select CH0A.
 *  0b00001..Select CH1A.
 *  0b00010..Select CH2A.
 *  0b00011..Select CH3A.
 *  0b00100-0b11101..Select corresponding channel CHnA.
 *  0b11110..Select CH30A.
 *  0b11111..Select CH31A.
 */
#define LPADC_CMDL4_ADCH(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDL4_ADCH_SHIFT)) & LPADC_CMDL4_ADCH_MASK)

#define LPADC_CMDL4_CTYPE_MASK                   (0x60U)
#define LPADC_CMDL4_CTYPE_SHIFT                  (5U)
/*! CTYPE - Conversion Type
 *  0b00..Single-Ended Mode. Only A side channel is converted.
 *  0b01-0b11..Reserved.
 */
#define LPADC_CMDL4_CTYPE(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_CMDL4_CTYPE_SHIFT)) & LPADC_CMDL4_CTYPE_MASK)
/*! @} */

/*! @name CMDH4 - Command High Buffer Register */
/*! @{ */

#define LPADC_CMDH4_CMPEN_MASK                   (0x3U)
#define LPADC_CMDH4_CMPEN_SHIFT                  (0U)
/*! CMPEN - Compare Function Enable
 *  0b00..Compare disabled.
 *  0b01..Reserved
 *  0b10..Compare enabled. Store on true.
 *  0b11..Compare enabled. Repeat channel acquisition (sample, convert, compare) until true.
 */
#define LPADC_CMDH4_CMPEN(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH4_CMPEN_SHIFT)) & LPADC_CMDH4_CMPEN_MASK)

#define LPADC_CMDH4_WAIT_TRIG_MASK               (0x4U)
#define LPADC_CMDH4_WAIT_TRIG_SHIFT              (2U)
/*! WAIT_TRIG - Wait for Trigger Assertion before Execution.
 *  0b0..This command automatically executes.
 *  0b1..The active trigger must be asserted again before executing this command.
 */
#define LPADC_CMDH4_WAIT_TRIG(x)                 (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH4_WAIT_TRIG_SHIFT)) & LPADC_CMDH4_WAIT_TRIG_MASK)

#define LPADC_CMDH4_LWI_MASK                     (0x80U)
#define LPADC_CMDH4_LWI_SHIFT                    (7U)
/*! LWI - Loop with Increment
 *  0b0..Auto channel increment disabled
 *  0b1..Auto channel increment enabled
 */
#define LPADC_CMDH4_LWI(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH4_LWI_SHIFT)) & LPADC_CMDH4_LWI_MASK)

#define LPADC_CMDH4_STS_MASK                     (0xF00U)
#define LPADC_CMDH4_STS_SHIFT                    (8U)
/*! STS - Sample Time Select */
#define LPADC_CMDH4_STS(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH4_STS_SHIFT)) & LPADC_CMDH4_STS_MASK)

#define LPADC_CMDH4_AVGS_MASK                    (0xF000U)
#define LPADC_CMDH4_AVGS_SHIFT                   (12U)
/*! AVGS - Hardware Average Select
 *  0b0000..Single conversion.
 *  0b0001..2 conversions averaged.
 *  0b0010..4 conversions averaged.
 *  0b0011..8 conversions averaged.
 *  0b0100..16 conversions averaged.
 *  0b0101..32 conversions averaged.
 *  0b0110..64 conversions averaged.
 *  0b0111..128 conversions averaged.
 *  0b1000..256 conversions averaged.
 *  0b1001..512 conversions averaged.
 *  0b1010..1024 conversions averaged.
 */
#define LPADC_CMDH4_AVGS(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH4_AVGS_SHIFT)) & LPADC_CMDH4_AVGS_MASK)

#define LPADC_CMDH4_LOOP_MASK                    (0xF0000U)
#define LPADC_CMDH4_LOOP_SHIFT                   (16U)
/*! LOOP - Loop Count Select
 *  0b0000..Looping not enabled; command executes 1 time.
 *  0b0001..Loop 1 time; command executes 2 times.
 *  0b0010..Loop 2 times; command executes 3 times.
 *  0b0011-0b1110..Loop corresponding number of times; command executes LOOP + 1 times.
 *  0b1111..Loop 15 times; command executes 16 times.
 */
#define LPADC_CMDH4_LOOP(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH4_LOOP_SHIFT)) & LPADC_CMDH4_LOOP_MASK)

#define LPADC_CMDH4_NEXT_MASK                    (0x7000000U)
#define LPADC_CMDH4_NEXT_SHIFT                   (24U)
/*! NEXT - Next Command Select
 *  0b000..No next command defined. Terminate conversions at completion of current command. If lower priority
 *         trigger pending, begin command associated with lower priority trigger.
 *  0b001..Select CMD1 command buffer register as next command.
 *  0b010-0b110..Select corresponding CMD command buffer register as next command
 *  0b111..Select CMD7 command buffer register as next command.
 */
#define LPADC_CMDH4_NEXT(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH4_NEXT_SHIFT)) & LPADC_CMDH4_NEXT_MASK)
/*! @} */

/*! @name CMDL5 - Command Low Buffer Register */
/*! @{ */

#define LPADC_CMDL5_ADCH_MASK                    (0x1FU)
#define LPADC_CMDL5_ADCH_SHIFT                   (0U)
/*! ADCH - Input Channel Select
 *  0b00000..Select CH0A.
 *  0b00001..Select CH1A.
 *  0b00010..Select CH2A.
 *  0b00011..Select CH3A.
 *  0b00100-0b11101..Select corresponding channel CHnA.
 *  0b11110..Select CH30A.
 *  0b11111..Select CH31A.
 */
#define LPADC_CMDL5_ADCH(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDL5_ADCH_SHIFT)) & LPADC_CMDL5_ADCH_MASK)

#define LPADC_CMDL5_CTYPE_MASK                   (0x60U)
#define LPADC_CMDL5_CTYPE_SHIFT                  (5U)
/*! CTYPE - Conversion Type
 *  0b00..Single-Ended Mode. Only A side channel is converted.
 *  0b01-0b11..Reserved.
 */
#define LPADC_CMDL5_CTYPE(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_CMDL5_CTYPE_SHIFT)) & LPADC_CMDL5_CTYPE_MASK)
/*! @} */

/*! @name CMDH5 - Command High Buffer Register */
/*! @{ */

#define LPADC_CMDH5_WAIT_TRIG_MASK               (0x4U)
#define LPADC_CMDH5_WAIT_TRIG_SHIFT              (2U)
/*! WAIT_TRIG - Wait for Trigger Assertion before Execution.
 *  0b0..This command automatically executes.
 *  0b1..The active trigger must be asserted again before executing this command.
 */
#define LPADC_CMDH5_WAIT_TRIG(x)                 (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH5_WAIT_TRIG_SHIFT)) & LPADC_CMDH5_WAIT_TRIG_MASK)

#define LPADC_CMDH5_LWI_MASK                     (0x80U)
#define LPADC_CMDH5_LWI_SHIFT                    (7U)
/*! LWI - Loop with Increment
 *  0b0..Auto channel increment disabled
 *  0b1..Auto channel increment enabled
 */
#define LPADC_CMDH5_LWI(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH5_LWI_SHIFT)) & LPADC_CMDH5_LWI_MASK)

#define LPADC_CMDH5_STS_MASK                     (0xF00U)
#define LPADC_CMDH5_STS_SHIFT                    (8U)
/*! STS - Sample Time Select */
#define LPADC_CMDH5_STS(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH5_STS_SHIFT)) & LPADC_CMDH5_STS_MASK)

#define LPADC_CMDH5_AVGS_MASK                    (0xF000U)
#define LPADC_CMDH5_AVGS_SHIFT                   (12U)
/*! AVGS - Hardware Average Select
 *  0b0000..Single conversion.
 *  0b0001..2 conversions averaged.
 *  0b0010..4 conversions averaged.
 *  0b0011..8 conversions averaged.
 *  0b0100..16 conversions averaged.
 *  0b0101..32 conversions averaged.
 *  0b0110..64 conversions averaged.
 *  0b0111..128 conversions averaged.
 *  0b1000..256 conversions averaged.
 *  0b1001..512 conversions averaged.
 *  0b1010..1024 conversions averaged.
 */
#define LPADC_CMDH5_AVGS(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH5_AVGS_SHIFT)) & LPADC_CMDH5_AVGS_MASK)

#define LPADC_CMDH5_LOOP_MASK                    (0xF0000U)
#define LPADC_CMDH5_LOOP_SHIFT                   (16U)
/*! LOOP - Loop Count Select
 *  0b0000..Looping not enabled; command executes 1 time.
 *  0b0001..Loop 1 time; command executes 2 times.
 *  0b0010..Loop 2 times; command executes 3 times.
 *  0b0011-0b1110..Loop corresponding number of times; command executes LOOP + 1 times.
 *  0b1111..Loop 15 times; command executes 16 times.
 */
#define LPADC_CMDH5_LOOP(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH5_LOOP_SHIFT)) & LPADC_CMDH5_LOOP_MASK)

#define LPADC_CMDH5_NEXT_MASK                    (0x7000000U)
#define LPADC_CMDH5_NEXT_SHIFT                   (24U)
/*! NEXT - Next Command Select
 *  0b000..No next command defined. Terminate conversions at completion of current command. If lower priority
 *         trigger pending, begin command associated with lower priority trigger.
 *  0b001..Select CMD1 command buffer register as next command.
 *  0b010-0b110..Select corresponding CMD command buffer register as next command
 *  0b111..Select CMD7 command buffer register as next command.
 */
#define LPADC_CMDH5_NEXT(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH5_NEXT_SHIFT)) & LPADC_CMDH5_NEXT_MASK)
/*! @} */

/*! @name CMDL6 - Command Low Buffer Register */
/*! @{ */

#define LPADC_CMDL6_ADCH_MASK                    (0x1FU)
#define LPADC_CMDL6_ADCH_SHIFT                   (0U)
/*! ADCH - Input Channel Select
 *  0b00000..Select CH0A.
 *  0b00001..Select CH1A.
 *  0b00010..Select CH2A.
 *  0b00011..Select CH3A.
 *  0b00100-0b11101..Select corresponding channel CHnA.
 *  0b11110..Select CH30A.
 *  0b11111..Select CH31A.
 */
#define LPADC_CMDL6_ADCH(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDL6_ADCH_SHIFT)) & LPADC_CMDL6_ADCH_MASK)

#define LPADC_CMDL6_CTYPE_MASK                   (0x60U)
#define LPADC_CMDL6_CTYPE_SHIFT                  (5U)
/*! CTYPE - Conversion Type
 *  0b00..Single-Ended Mode. Only A side channel is converted.
 *  0b01-0b11..Reserved.
 */
#define LPADC_CMDL6_CTYPE(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_CMDL6_CTYPE_SHIFT)) & LPADC_CMDL6_CTYPE_MASK)
/*! @} */

/*! @name CMDH6 - Command High Buffer Register */
/*! @{ */

#define LPADC_CMDH6_WAIT_TRIG_MASK               (0x4U)
#define LPADC_CMDH6_WAIT_TRIG_SHIFT              (2U)
/*! WAIT_TRIG - Wait for Trigger Assertion before Execution.
 *  0b0..This command automatically executes.
 *  0b1..The active trigger must be asserted again before executing this command.
 */
#define LPADC_CMDH6_WAIT_TRIG(x)                 (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH6_WAIT_TRIG_SHIFT)) & LPADC_CMDH6_WAIT_TRIG_MASK)

#define LPADC_CMDH6_LWI_MASK                     (0x80U)
#define LPADC_CMDH6_LWI_SHIFT                    (7U)
/*! LWI - Loop with Increment
 *  0b0..Auto channel increment disabled
 *  0b1..Auto channel increment enabled
 */
#define LPADC_CMDH6_LWI(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH6_LWI_SHIFT)) & LPADC_CMDH6_LWI_MASK)

#define LPADC_CMDH6_STS_MASK                     (0xF00U)
#define LPADC_CMDH6_STS_SHIFT                    (8U)
/*! STS - Sample Time Select */
#define LPADC_CMDH6_STS(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH6_STS_SHIFT)) & LPADC_CMDH6_STS_MASK)

#define LPADC_CMDH6_AVGS_MASK                    (0xF000U)
#define LPADC_CMDH6_AVGS_SHIFT                   (12U)
/*! AVGS - Hardware Average Select
 *  0b0000..Single conversion.
 *  0b0001..2 conversions averaged.
 *  0b0010..4 conversions averaged.
 *  0b0011..8 conversions averaged.
 *  0b0100..16 conversions averaged.
 *  0b0101..32 conversions averaged.
 *  0b0110..64 conversions averaged.
 *  0b0111..128 conversions averaged.
 *  0b1000..256 conversions averaged.
 *  0b1001..512 conversions averaged.
 *  0b1010..1024 conversions averaged.
 */
#define LPADC_CMDH6_AVGS(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH6_AVGS_SHIFT)) & LPADC_CMDH6_AVGS_MASK)

#define LPADC_CMDH6_LOOP_MASK                    (0xF0000U)
#define LPADC_CMDH6_LOOP_SHIFT                   (16U)
/*! LOOP - Loop Count Select
 *  0b0000..Looping not enabled; command executes 1 time.
 *  0b0001..Loop 1 time; command executes 2 times.
 *  0b0010..Loop 2 times; command executes 3 times.
 *  0b0011-0b1110..Loop corresponding number of times; command executes LOOP + 1 times.
 *  0b1111..Loop 15 times; command executes 16 times.
 */
#define LPADC_CMDH6_LOOP(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH6_LOOP_SHIFT)) & LPADC_CMDH6_LOOP_MASK)

#define LPADC_CMDH6_NEXT_MASK                    (0x7000000U)
#define LPADC_CMDH6_NEXT_SHIFT                   (24U)
/*! NEXT - Next Command Select
 *  0b000..No next command defined. Terminate conversions at completion of current command. If lower priority
 *         trigger pending, begin command associated with lower priority trigger.
 *  0b001..Select CMD1 command buffer register as next command.
 *  0b010-0b110..Select corresponding CMD command buffer register as next command
 *  0b111..Select CMD7 command buffer register as next command.
 */
#define LPADC_CMDH6_NEXT(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH6_NEXT_SHIFT)) & LPADC_CMDH6_NEXT_MASK)
/*! @} */

/*! @name CMDL7 - Command Low Buffer Register */
/*! @{ */

#define LPADC_CMDL7_ADCH_MASK                    (0x1FU)
#define LPADC_CMDL7_ADCH_SHIFT                   (0U)
/*! ADCH - Input Channel Select
 *  0b00000..Select CH0A.
 *  0b00001..Select CH1A.
 *  0b00010..Select CH2A.
 *  0b00011..Select CH3A.
 *  0b00100-0b11101..Select corresponding channel CHnA.
 *  0b11110..Select CH30A.
 *  0b11111..Select CH31A.
 */
#define LPADC_CMDL7_ADCH(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDL7_ADCH_SHIFT)) & LPADC_CMDL7_ADCH_MASK)

#define LPADC_CMDL7_CTYPE_MASK                   (0x60U)
#define LPADC_CMDL7_CTYPE_SHIFT                  (5U)
/*! CTYPE - Conversion Type
 *  0b00..Single-Ended Mode. Only A side channel is converted.
 *  0b01-0b11..Reserved.
 */
#define LPADC_CMDL7_CTYPE(x)                     (((uint32_t)(((uint32_t)(x)) << LPADC_CMDL7_CTYPE_SHIFT)) & LPADC_CMDL7_CTYPE_MASK)
/*! @} */

/*! @name CMDH7 - Command High Buffer Register */
/*! @{ */

#define LPADC_CMDH7_WAIT_TRIG_MASK               (0x4U)
#define LPADC_CMDH7_WAIT_TRIG_SHIFT              (2U)
/*! WAIT_TRIG - Wait for Trigger Assertion before Execution.
 *  0b0..This command automatically executes.
 *  0b1..The active trigger must be asserted again before executing this command.
 */
#define LPADC_CMDH7_WAIT_TRIG(x)                 (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH7_WAIT_TRIG_SHIFT)) & LPADC_CMDH7_WAIT_TRIG_MASK)

#define LPADC_CMDH7_LWI_MASK                     (0x80U)
#define LPADC_CMDH7_LWI_SHIFT                    (7U)
/*! LWI - Loop with Increment
 *  0b0..Auto channel increment disabled
 *  0b1..Auto channel increment enabled
 */
#define LPADC_CMDH7_LWI(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH7_LWI_SHIFT)) & LPADC_CMDH7_LWI_MASK)

#define LPADC_CMDH7_STS_MASK                     (0xF00U)
#define LPADC_CMDH7_STS_SHIFT                    (8U)
/*! STS - Sample Time Select */
#define LPADC_CMDH7_STS(x)                       (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH7_STS_SHIFT)) & LPADC_CMDH7_STS_MASK)

#define LPADC_CMDH7_AVGS_MASK                    (0xF000U)
#define LPADC_CMDH7_AVGS_SHIFT                   (12U)
/*! AVGS - Hardware Average Select
 *  0b0000..Single conversion.
 *  0b0001..2 conversions averaged.
 *  0b0010..4 conversions averaged.
 *  0b0011..8 conversions averaged.
 *  0b0100..16 conversions averaged.
 *  0b0101..32 conversions averaged.
 *  0b0110..64 conversions averaged.
 *  0b0111..128 conversions averaged.
 *  0b1000..256 conversions averaged.
 *  0b1001..512 conversions averaged.
 *  0b1010..1024 conversions averaged.
 */
#define LPADC_CMDH7_AVGS(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH7_AVGS_SHIFT)) & LPADC_CMDH7_AVGS_MASK)

#define LPADC_CMDH7_LOOP_MASK                    (0xF0000U)
#define LPADC_CMDH7_LOOP_SHIFT                   (16U)
/*! LOOP - Loop Count Select
 *  0b0000..Looping not enabled; command executes 1 time.
 *  0b0001..Loop 1 time; command executes 2 times.
 *  0b0010..Loop 2 times; command executes 3 times.
 *  0b0011-0b1110..Loop corresponding number of times; command executes LOOP + 1 times.
 *  0b1111..Loop 15 times; command executes 16 times.
 */
#define LPADC_CMDH7_LOOP(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH7_LOOP_SHIFT)) & LPADC_CMDH7_LOOP_MASK)

#define LPADC_CMDH7_NEXT_MASK                    (0x7000000U)
#define LPADC_CMDH7_NEXT_SHIFT                   (24U)
/*! NEXT - Next Command Select
 *  0b000..No next command defined. Terminate conversions at completion of current command. If lower priority
 *         trigger pending, begin command associated with lower priority trigger.
 *  0b001..Select CMD1 command buffer register as next command.
 *  0b010-0b110..Select corresponding CMD command buffer register as next command
 *  0b111..Select CMD7 command buffer register as next command.
 */
#define LPADC_CMDH7_NEXT(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_CMDH7_NEXT_SHIFT)) & LPADC_CMDH7_NEXT_MASK)
/*! @} */

/*! @name CV - Compare Value Register */
/*! @{ */

#define LPADC_CV_CVL_MASK                        (0xFFFFU)
#define LPADC_CV_CVL_SHIFT                       (0U)
/*! CVL - Compare Value Low */
#define LPADC_CV_CVL(x)                          (((uint32_t)(((uint32_t)(x)) << LPADC_CV_CVL_SHIFT)) & LPADC_CV_CVL_MASK)

#define LPADC_CV_CVH_MASK                        (0xFFFF0000U)
#define LPADC_CV_CVH_SHIFT                       (16U)
/*! CVH - Compare Value High */
#define LPADC_CV_CVH(x)                          (((uint32_t)(((uint32_t)(x)) << LPADC_CV_CVH_SHIFT)) & LPADC_CV_CVH_MASK)
/*! @} */

/*! @name RESFIFO0 - Data Result FIFO0 Register */
/*! @{ */

#define LPADC_RESFIFO0_D_MASK                    (0xFFFFU)
#define LPADC_RESFIFO0_D_SHIFT                   (0U)
/*! D - Data Result */
#define LPADC_RESFIFO0_D(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_RESFIFO0_D_SHIFT)) & LPADC_RESFIFO0_D_MASK)

#define LPADC_RESFIFO0_TSRC_MASK                 (0x30000U)
#define LPADC_RESFIFO0_TSRC_SHIFT                (16U)
/*! TSRC - Trigger Source
 *  0b00..Trigger source 0
 *  0b01..Trigger source 1
 *  0b10..Trigger source 2
 *  0b11..Trigger source 3
 */
#define LPADC_RESFIFO0_TSRC(x)                   (((uint32_t)(((uint32_t)(x)) << LPADC_RESFIFO0_TSRC_SHIFT)) & LPADC_RESFIFO0_TSRC_MASK)

#define LPADC_RESFIFO0_LOOPCNT_MASK              (0xF00000U)
#define LPADC_RESFIFO0_LOOPCNT_SHIFT             (20U)
/*! LOOPCNT - Loop Count Value
 *  0b0000..Result is from initial conversion in command.
 *  0b0001..Result is from second conversion in command.
 *  0b0010-0b1110..Result is from LOOPCNT + 1 conversion in command.
 *  0b1111..Result is from 16th conversion in command.
 */
#define LPADC_RESFIFO0_LOOPCNT(x)                (((uint32_t)(((uint32_t)(x)) << LPADC_RESFIFO0_LOOPCNT_SHIFT)) & LPADC_RESFIFO0_LOOPCNT_MASK)

#define LPADC_RESFIFO0_CMDSRC_MASK               (0x7000000U)
#define LPADC_RESFIFO0_CMDSRC_SHIFT              (24U)
/*! CMDSRC - Command Buffer Source
 *  0b000..Not a valid value for a dataword in RESFIFO. 0h is only found in initial FIFO state prior to an ADC
 *         conversion result dataword being stored to a RESFIFO buffer.
 *  0b001..CMD1 buffer used as control settings for this conversion.
 *  0b010-0b110..Corresponding command buffer used as control settings for this conversion.
 *  0b111..CMD7 buffer used as control settings for this conversion.
 */
#define LPADC_RESFIFO0_CMDSRC(x)                 (((uint32_t)(((uint32_t)(x)) << LPADC_RESFIFO0_CMDSRC_SHIFT)) & LPADC_RESFIFO0_CMDSRC_MASK)

#define LPADC_RESFIFO0_VALID_MASK                (0x80000000U)
#define LPADC_RESFIFO0_VALID_SHIFT               (31U)
/*! VALID - FIFO Entry is Valid
 *  0b0..FIFO is empty. Discard any read from RESFIFO.
 *  0b1..FIFO record read from RESFIFO is valid.
 */
#define LPADC_RESFIFO0_VALID(x)                  (((uint32_t)(((uint32_t)(x)) << LPADC_RESFIFO0_VALID_SHIFT)) & LPADC_RESFIFO0_VALID_MASK)
/*! @} */

/*! @name RESFIFO1 - Data Result FIFO1 Register */
/*! @{ */

#define LPADC_RESFIFO1_D_MASK                    (0xFFFFU)
#define LPADC_RESFIFO1_D_SHIFT                   (0U)
/*! D - Data Result */
#define LPADC_RESFIFO1_D(x)                      (((uint32_t)(((uint32_t)(x)) << LPADC_RESFIFO1_D_SHIFT)) & LPADC_RESFIFO1_D_MASK)

#define LPADC_RESFIFO1_TSRC_MASK                 (0x30000U)
#define LPADC_RESFIFO1_TSRC_SHIFT                (16U)
/*! TSRC - Trigger Source
 *  0b00..Trigger source 0 initiated this conversion.
 *  0b01..Trigger source 1 initiated this conversion.
 *  0b10..Trigger source 2 initiated this conversion.
 *  0b11..Trigger source 3 initiated this conversion.
 */
#define LPADC_RESFIFO1_TSRC(x)                   (((uint32_t)(((uint32_t)(x)) << LPADC_RESFIFO1_TSRC_SHIFT)) & LPADC_RESFIFO1_TSRC_MASK)

#define LPADC_RESFIFO1_LOOPCNT_MASK              (0xF00000U)
#define LPADC_RESFIFO1_LOOPCNT_SHIFT             (20U)
/*! LOOPCNT - Loop Count Value
 *  0b0000..Result is from initial conversion in command.
 *  0b0001..Result is from second conversion in command.
 *  0b0010-0b1110..Result is from LOOPCNT+1 conversion in command.
 *  0b1111..Result is from 16 th conversion in command.
 */
#define LPADC_RESFIFO1_LOOPCNT(x)                (((uint32_t)(((uint32_t)(x)) << LPADC_RESFIFO1_LOOPCNT_SHIFT)) & LPADC_RESFIFO1_LOOPCNT_MASK)

#define LPADC_RESFIFO1_CMDSRC_MASK               (0x7000000U)
#define LPADC_RESFIFO1_CMDSRC_SHIFT              (24U)
/*! CMDSRC - Command Buffer Source
 *  0b000..Not a valid value for a dataword in RESFIFO. 0h is only found in initial FIFO state prior to an ADC
 *         conversion result dataword being stored to a RESFIFO buffer.
 *  0b001..CMD1 buffer used as control settings for this conversion.
 *  0b010-0b110..Corresponding command buffer used as control settings for this conversion.
 *  0b111..CMD7 buffer used as control settings for this conversion.
 */
#define LPADC_RESFIFO1_CMDSRC(x)                 (((uint32_t)(((uint32_t)(x)) << LPADC_RESFIFO1_CMDSRC_SHIFT)) & LPADC_RESFIFO1_CMDSRC_MASK)

#define LPADC_RESFIFO1_VALID_MASK                (0x80000000U)
#define LPADC_RESFIFO1_VALID_SHIFT               (31U)
/*! VALID - FIFO Entry is Valid
 *  0b0..FIFO is empty. Discard any read from RESFIFO.
 *  0b1..FIFO record read from RESFIFO is valid.
 */
#define LPADC_RESFIFO1_VALID(x)                  (((uint32_t)(((uint32_t)(x)) << LPADC_RESFIFO1_VALID_SHIFT)) & LPADC_RESFIFO1_VALID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LPADC_Register_Masks */


/*!
 * @}
 */ /* end of group LPADC_Peripheral_Access_Layer */


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


#endif  /* PERI_LPADC_H_ */

