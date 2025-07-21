/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ADC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ADC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ADC
 *
 * CMSIS Peripheral Access Layer for ADC
 */

#if !defined(PERI_ADC_H_)
#define PERI_ADC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
  __IO uint32_t CTRL;                              /**< LPADC Control Register, offset: 0x10 */
  __IO uint32_t STAT;                              /**< LPADC Status Register, offset: 0x14 */
  __IO uint32_t IE;                                /**< Interrupt Enable Register, offset: 0x18 */
  __IO uint32_t DE;                                /**< DMA Enable Register, offset: 0x1C */
  __IO uint32_t CFG;                               /**< LPADC Configuration Register, offset: 0x20 */
  __IO uint32_t PAUSE;                             /**< LPADC Pause Register, offset: 0x24 */
       uint8_t RESERVED_1[8];
  __IO uint32_t FCTRL;                             /**< LPADC FIFO Control Register, offset: 0x30 */
  __IO uint32_t SWTRIG;                            /**< Software Trigger Register, offset: 0x34 */
       uint8_t RESERVED_2[8];
  __IO uint32_t OFSTRIM;                           /**< LPADC Offset Trim Register, offset: 0x40 */
       uint8_t RESERVED_3[124];
  __IO uint32_t TCTRL[ADC_TCTRL_COUNT];            /**< Trigger Control Register, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_4[48];
  struct {                                         /* offset: 0x100, array step: 0x8 */
    __IO uint32_t CMDL;                              /**< LPADC Command Low Buffer Register, array offset: 0x100, array step: 0x8 */
    __IO uint32_t CMDH;                              /**< LPADC Command High Buffer Register, array offset: 0x104, array step: 0x8 */
  } CMD[ADC_CMD_COUNT];
       uint8_t RESERVED_5[136];
  __IO uint32_t CV[ADC_CV_COUNT];                  /**< Compare Value Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_6[240];
  __I  uint32_t RESFIFO;                           /**< LPADC Data Result FIFO Register, offset: 0x300 */
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
 *  0b0..Up to 13-bit differential/12-bit single ended resolution supported.
 *  0b1..Up to 16-bit differential/15-bit single ended resolution supported.
 */
#define ADC_VERID_RES(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_VERID_RES_SHIFT)) & ADC_VERID_RES_MASK)

#define ADC_VERID_DIFFEN_MASK                    (0x2U)
#define ADC_VERID_DIFFEN_SHIFT                   (1U)
/*! DIFFEN - Differential Supported
 *  0b0..Differential operation not supported.
 *  0b1..Differential operation supported. CMDLa[DIFF] and CMDLa[ABSEL] control fields implemented.
 */
#define ADC_VERID_DIFFEN(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_VERID_DIFFEN_SHIFT)) & ADC_VERID_DIFFEN_MASK)

#define ADC_VERID_MVI_MASK                       (0x8U)
#define ADC_VERID_MVI_SHIFT                      (3U)
/*! MVI - Multi Vref Implemented
 *  0b0..Single voltage reference high (VREFH) input supported.
 *  0b1..Multiple voltage reference high (VREFH) inputs supported.
 */
#define ADC_VERID_MVI(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_VERID_MVI_SHIFT)) & ADC_VERID_MVI_MASK)

#define ADC_VERID_CSW_MASK                       (0x70U)
#define ADC_VERID_CSW_SHIFT                      (4U)
/*! CSW - Channel Scale Width
 *  0b000..Channel scaling not supported.
 *  0b001..Channel scaling supported. 1-bit CSCALE control field.
 *  0b110..Channel scaling supported. 6-bit CSCALE control field.
 */
#define ADC_VERID_CSW(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_VERID_CSW_SHIFT)) & ADC_VERID_CSW_MASK)

#define ADC_VERID_VR1RNGI_MASK                   (0x100U)
#define ADC_VERID_VR1RNGI_SHIFT                  (8U)
/*! VR1RNGI - Voltage Reference 1 Range Control Bit Implemented
 *  0b0..Range control not required. CFG[VREF1RNG] is not implemented.
 *  0b1..Range control required. CFG[VREF1RNG] is implemented.
 */
#define ADC_VERID_VR1RNGI(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_VERID_VR1RNGI_SHIFT)) & ADC_VERID_VR1RNGI_MASK)

#define ADC_VERID_IADCKI_MASK                    (0x200U)
#define ADC_VERID_IADCKI_SHIFT                   (9U)
/*! IADCKI - Internal LPADC Clock implemented
 *  0b0..Internal clock source not implemented.
 *  0b1..Internal clock source (and CFG[ADCKEN]) implemented.
 */
#define ADC_VERID_IADCKI(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_VERID_IADCKI_SHIFT)) & ADC_VERID_IADCKI_MASK)

#define ADC_VERID_CALOFSI_MASK                   (0x400U)
#define ADC_VERID_CALOFSI_SHIFT                  (10U)
/*! CALOFSI - Calibration Offset Function Implemented
 *  0b0..Offset calibration and offset trimming not implemented.
 *  0b1..Offset calibration and offset trimming implemented.
 */
#define ADC_VERID_CALOFSI(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_VERID_CALOFSI_SHIFT)) & ADC_VERID_CALOFSI_MASK)

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
 *  0b00000001..Result FIFO depth = 1 dataword.
 *  0b00000100..Result FIFO depth = 4 datawords.
 *  0b00001000..Result FIFO depth = 8 datawords.
 *  0b00010000..Result FIFO depth = 16 datawords.
 *  0b00100000..Result FIFO depth = 32 datawords.
 *  0b01000000..Result FIFO depth = 64 datawords.
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

/*! @name CTRL - LPADC Control Register */
/*! @{ */

#define ADC_CTRL_ADCEN_MASK                      (0x1U)
#define ADC_CTRL_ADCEN_SHIFT                     (0U)
/*! ADCEN - LPADC Enable
 *  0b0..LPADC is disabled.
 *  0b1..LPADC is enabled.
 */
#define ADC_CTRL_ADCEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CTRL_ADCEN_SHIFT)) & ADC_CTRL_ADCEN_MASK)

#define ADC_CTRL_RST_MASK                        (0x2U)
#define ADC_CTRL_RST_SHIFT                       (1U)
/*! RST - Software Reset
 *  0b0..LPADC logic is not reset.
 *  0b1..LPADC logic is reset.
 */
#define ADC_CTRL_RST(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_CTRL_RST_SHIFT)) & ADC_CTRL_RST_MASK)

#define ADC_CTRL_DOZEN_MASK                      (0x4U)
#define ADC_CTRL_DOZEN_SHIFT                     (2U)
/*! DOZEN - Doze Enable
 *  0b0..LPADC is enabled in Doze mode.
 *  0b1..LPADC is disabled in Doze mode.
 */
#define ADC_CTRL_DOZEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CTRL_DOZEN_SHIFT)) & ADC_CTRL_DOZEN_MASK)

#define ADC_CTRL_RSTFIFO_MASK                    (0x100U)
#define ADC_CTRL_RSTFIFO_SHIFT                   (8U)
/*! RSTFIFO - Reset FIFO
 *  0b0..No effect.
 *  0b1..FIFO is reset.
 */
#define ADC_CTRL_RSTFIFO(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CTRL_RSTFIFO_SHIFT)) & ADC_CTRL_RSTFIFO_MASK)
/*! @} */

/*! @name STAT - LPADC Status Register */
/*! @{ */

#define ADC_STAT_RDY_MASK                        (0x1U)
#define ADC_STAT_RDY_SHIFT                       (0U)
/*! RDY - Result FIFO Ready Flag
 *  0b0..Result FIFO data level not above watermark level.
 *  0b1..Result FIFO holding data above watermark level.
 */
#define ADC_STAT_RDY(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_STAT_RDY_SHIFT)) & ADC_STAT_RDY_MASK)

#define ADC_STAT_FOF_MASK                        (0x2U)
#define ADC_STAT_FOF_SHIFT                       (1U)
/*! FOF - Result FIFO Overflow Flag
 *  0b0..No result FIFO overflow has occurred since the last time the flag was cleared.
 *  0b1..At least one result FIFO overflow has occurred since the last time the flag was cleared.
 */
#define ADC_STAT_FOF(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_STAT_FOF_SHIFT)) & ADC_STAT_FOF_MASK)

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
 *  0b0000..No command is currently in progress.
 *  0b0001..Command 1 currently being executed.
 *  0b0010..Command 2 currently being executed.
 *  0b0011-0b1111..Associated command number is currently being executed.
 */
#define ADC_STAT_CMDACT(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_STAT_CMDACT_SHIFT)) & ADC_STAT_CMDACT_MASK)
/*! @} */

/*! @name IE - Interrupt Enable Register */
/*! @{ */

#define ADC_IE_FWMIE_MASK                        (0x1U)
#define ADC_IE_FWMIE_SHIFT                       (0U)
/*! FWMIE - FIFO Watermark Interrupt Enable
 *  0b0..FIFO watermark interrupts are not enabled.
 *  0b1..FIFO watermark interrupts are enabled.
 */
#define ADC_IE_FWMIE(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_IE_FWMIE_SHIFT)) & ADC_IE_FWMIE_MASK)

#define ADC_IE_FOFIE_MASK                        (0x2U)
#define ADC_IE_FOFIE_SHIFT                       (1U)
/*! FOFIE - Result FIFO Overflow Interrupt Enable
 *  0b0..FIFO overflow interrupts are not enabled.
 *  0b1..FIFO overflow interrupts are enabled.
 */
#define ADC_IE_FOFIE(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_IE_FOFIE_SHIFT)) & ADC_IE_FOFIE_MASK)
/*! @} */

/*! @name DE - DMA Enable Register */
/*! @{ */

#define ADC_DE_FWMDE_MASK                        (0x1U)
#define ADC_DE_FWMDE_SHIFT                       (0U)
/*! FWMDE - FIFO Watermark DMA Enable
 *  0b0..DMA request disabled.
 *  0b1..DMA request enabled.
 */
#define ADC_DE_FWMDE(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_DE_FWMDE_SHIFT)) & ADC_DE_FWMDE_MASK)
/*! @} */

/*! @name CFG - LPADC Configuration Register */
/*! @{ */

#define ADC_CFG_TPRICTRL_MASK                    (0x1U)
#define ADC_CFG_TPRICTRL_SHIFT                   (0U)
/*! TPRICTRL - LPADC trigger priority control
 *  0b0..If a higher priority trigger is detected during command processing, the current conversion is aborted and
 *       the new command specified by the trigger is started.
 *  0b1..If a higher priority trigger is received during command processing, the current conversion is completed
 *       (including averaging iterations if enabled) and stored to the RESFIFO before the higher priority
 *       trigger/command is initiated. Note that compare until true commands can be interrupted prior to resulting in a true
 *       conversion.
 */
#define ADC_CFG_TPRICTRL(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CFG_TPRICTRL_SHIFT)) & ADC_CFG_TPRICTRL_MASK)

#define ADC_CFG_PWRSEL_MASK                      (0x30U)
#define ADC_CFG_PWRSEL_SHIFT                     (4U)
/*! PWRSEL - Power Configuration Select
 *  0b00..Level 1 (Lowest power setting)
 *  0b01..Level 2
 *  0b10..Level 3
 *  0b11..Level 4 (Highest power setting)
 */
#define ADC_CFG_PWRSEL(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CFG_PWRSEL_SHIFT)) & ADC_CFG_PWRSEL_MASK)

#define ADC_CFG_REFSEL_MASK                      (0xC0U)
#define ADC_CFG_REFSEL_SHIFT                     (6U)
/*! REFSEL - Voltage Reference Selection
 *  0b00..(Default) Option 1 setting.
 *  0b01..Option 2 setting.
 *  0b10..Option 3 setting.
 *  0b11..Reserved
 */
#define ADC_CFG_REFSEL(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CFG_REFSEL_SHIFT)) & ADC_CFG_REFSEL_MASK)

#define ADC_CFG_CALOFS_MASK                      (0x8000U)
#define ADC_CFG_CALOFS_SHIFT                     (15U)
/*! CALOFS - Configure for offset calibration function
 *  0b0..Calibration function disabled
 *  0b1..Configure for offset calibration function
 */
#define ADC_CFG_CALOFS(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CFG_CALOFS_SHIFT)) & ADC_CFG_CALOFS_MASK)

#define ADC_CFG_PUDLY_MASK                       (0xFF0000U)
#define ADC_CFG_PUDLY_SHIFT                      (16U)
/*! PUDLY - Power Up Delay */
#define ADC_CFG_PUDLY(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CFG_PUDLY_SHIFT)) & ADC_CFG_PUDLY_MASK)

#define ADC_CFG_PWREN_MASK                       (0x10000000U)
#define ADC_CFG_PWREN_SHIFT                      (28U)
/*! PWREN - LPADC Analog Pre-Enable
 *  0b0..LPADC analog circuits are only enabled while conversions are active. Performance is affected due to analog startup delays.
 *  0b1..LPADC analog circuits are pre-enabled and ready to execute conversions without startup delays (at the
 *       cost of higher DC current consumption). When PWREN is set, the power up delay is enforced such that any
 *       detected trigger does not begin ADC operation until the power up delay time has passed.
 */
#define ADC_CFG_PWREN(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CFG_PWREN_SHIFT)) & ADC_CFG_PWREN_MASK)

#define ADC_CFG_VREF1RNG_MASK                    (0x20000000U)
#define ADC_CFG_VREF1RNG_SHIFT                   (29U)
/*! VREF1RNG - Enable support for low voltage reference on Option 1 Reference
 *  0b0..Configuration required when Voltage Reference Option 1 input is in high voltage range
 *  0b1..Configuration required when Voltage Reference Option 1 input is in low voltage range
 */
#define ADC_CFG_VREF1RNG(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CFG_VREF1RNG_SHIFT)) & ADC_CFG_VREF1RNG_MASK)

#define ADC_CFG_ADCKEN_MASK                      (0x80000000U)
#define ADC_CFG_ADCKEN_SHIFT                     (31U)
/*! ADCKEN - LPADC asynchronous clock enable
 *  0b0..LPADC internal clock is disabled
 *  0b1..LPADC internal clock is enabled
 */
#define ADC_CFG_ADCKEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CFG_ADCKEN_SHIFT)) & ADC_CFG_ADCKEN_MASK)
/*! @} */

/*! @name PAUSE - LPADC Pause Register */
/*! @{ */

#define ADC_PAUSE_PAUSEDLY_MASK                  (0x1FFU)
#define ADC_PAUSE_PAUSEDLY_SHIFT                 (0U)
/*! PAUSEDLY - Pause Delay */
#define ADC_PAUSE_PAUSEDLY(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_PAUSE_PAUSEDLY_SHIFT)) & ADC_PAUSE_PAUSEDLY_MASK)

#define ADC_PAUSE_PAUSEEN_MASK                   (0x80000000U)
#define ADC_PAUSE_PAUSEEN_SHIFT                  (31U)
/*! PAUSEEN - PAUSE Option Enable
 *  0b0..Pause operation disabled
 *  0b1..Pause operation enabled
 */
#define ADC_PAUSE_PAUSEEN(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_PAUSE_PAUSEEN_SHIFT)) & ADC_PAUSE_PAUSEEN_MASK)
/*! @} */

/*! @name FCTRL - LPADC FIFO Control Register */
/*! @{ */

#define ADC_FCTRL_FCOUNT_MASK                    (0x1FU)
#define ADC_FCTRL_FCOUNT_SHIFT                   (0U)
/*! FCOUNT - Result FIFO counter */
#define ADC_FCTRL_FCOUNT(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FCTRL_FCOUNT_SHIFT)) & ADC_FCTRL_FCOUNT_MASK)

#define ADC_FCTRL_FWMARK_MASK                    (0xF0000U)
#define ADC_FCTRL_FWMARK_SHIFT                   (16U)
/*! FWMARK - Watermark level selection */
#define ADC_FCTRL_FWMARK(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FCTRL_FWMARK_SHIFT)) & ADC_FCTRL_FWMARK_MASK)
/*! @} */

/*! @name SWTRIG - Software Trigger Register */
/*! @{ */

#define ADC_SWTRIG_SWT0_MASK                     (0x1U)
#define ADC_SWTRIG_SWT0_SHIFT                    (0U)
/*! SWT0 - Software trigger 0 event
 *  0b0..No trigger 0 event generated.
 *  0b1..Trigger 0 event generated.
 */
#define ADC_SWTRIG_SWT0(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_SWTRIG_SWT0_SHIFT)) & ADC_SWTRIG_SWT0_MASK)

#define ADC_SWTRIG_SWT1_MASK                     (0x2U)
#define ADC_SWTRIG_SWT1_SHIFT                    (1U)
/*! SWT1 - Software trigger 1 event
 *  0b0..No trigger 1 event generated.
 *  0b1..Trigger 1 event generated.
 */
#define ADC_SWTRIG_SWT1(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_SWTRIG_SWT1_SHIFT)) & ADC_SWTRIG_SWT1_MASK)

#define ADC_SWTRIG_SWT2_MASK                     (0x4U)
#define ADC_SWTRIG_SWT2_SHIFT                    (2U)
/*! SWT2 - Software trigger 2 event
 *  0b0..No trigger 2 event generated.
 *  0b1..Trigger 2 event generated.
 */
#define ADC_SWTRIG_SWT2(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_SWTRIG_SWT2_SHIFT)) & ADC_SWTRIG_SWT2_MASK)

#define ADC_SWTRIG_SWT3_MASK                     (0x8U)
#define ADC_SWTRIG_SWT3_SHIFT                    (3U)
/*! SWT3 - Software trigger 3 event
 *  0b0..No trigger 3 event generated.
 *  0b1..Trigger 3 event generated.
 */
#define ADC_SWTRIG_SWT3(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_SWTRIG_SWT3_SHIFT)) & ADC_SWTRIG_SWT3_MASK)
/*! @} */

/*! @name OFSTRIM - LPADC Offset Trim Register */
/*! @{ */

#define ADC_OFSTRIM_OFSTRIM_MASK                 (0x3FU)
#define ADC_OFSTRIM_OFSTRIM_SHIFT                (0U)
/*! OFSTRIM - Trim for offset */
#define ADC_OFSTRIM_OFSTRIM(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_OFSTRIM_OFSTRIM_SHIFT)) & ADC_OFSTRIM_OFSTRIM_MASK)
/*! @} */

/*! @name TCTRL - Trigger Control Register */
/*! @{ */

#define ADC_TCTRL_HTEN_MASK                      (0x1U)
#define ADC_TCTRL_HTEN_SHIFT                     (0U)
/*! HTEN - Trigger enable
 *  0b0..Hardware trigger source disabled
 *  0b1..Hardware trigger source enabled
 */
#define ADC_TCTRL_HTEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_TCTRL_HTEN_SHIFT)) & ADC_TCTRL_HTEN_MASK)

#define ADC_TCTRL_TPRI_MASK                      (0x300U)
#define ADC_TCTRL_TPRI_SHIFT                     (8U)
/*! TPRI - Trigger priority setting
 *  0b00..Set to highest priority, Level 1
 *  0b01-0b10..Set to corresponding priority level
 *  0b11..Set to lowest priority, Level 4
 */
#define ADC_TCTRL_TPRI(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_TCTRL_TPRI_SHIFT)) & ADC_TCTRL_TPRI_MASK)

#define ADC_TCTRL_TDLY_MASK                      (0xF0000U)
#define ADC_TCTRL_TDLY_SHIFT                     (16U)
/*! TDLY - Trigger delay select */
#define ADC_TCTRL_TDLY(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_TCTRL_TDLY_SHIFT)) & ADC_TCTRL_TDLY_MASK)

#define ADC_TCTRL_TCMD_MASK                      (0xF000000U)
#define ADC_TCTRL_TCMD_SHIFT                     (24U)
/*! TCMD - Trigger command select
 *  0b0000..Not a valid selection from the command buffer. Trigger event is ignored.
 *  0b0001..CMD1 is executed
 *  0b0010-0b1110..Corresponding CMD is executed
 *  0b1111..CMD15 is executed
 */
#define ADC_TCTRL_TCMD(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_TCTRL_TCMD_SHIFT)) & ADC_TCTRL_TCMD_MASK)
/*! @} */

/*! @name CMDL - LPADC Command Low Buffer Register */
/*! @{ */

#define ADC_CMDL_ADCH_MASK                       (0x1FU)
#define ADC_CMDL_ADCH_SHIFT                      (0U)
/*! ADCH - Input channel select
 *  0b00000..Select CH0A or CH0B
 *  0b00001..Select CH1A or CH1B
 *  0b00010..Select CH2A or CH2B
 *  0b00011..Select CH3A or CH3B
 *  0b00100-0b11101..Select corresponding channel CHnA or CHnB
 *  0b11110..Select CH30A or CH30B
 *  0b11111..Select CH31A or CH31B
 */
#define ADC_CMDL_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CMDL_ADCH_SHIFT)) & ADC_CMDL_ADCH_MASK)

#define ADC_CMDL_ABSEL_MASK                      (0x20U)
#define ADC_CMDL_ABSEL_SHIFT                     (5U)
/*! ABSEL - A-side vs. B-side Select
 *  0b0..The associated A-side channel is converted.
 *  0b1..The associated B-side channel is converted.
 */
#define ADC_CMDL_ABSEL(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CMDL_ABSEL_SHIFT)) & ADC_CMDL_ABSEL_MASK)
/*! @} */

/* The count of ADC_CMDL */
#define ADC_CMDL_COUNT                           (15U)

/*! @name CMDH - LPADC Command High Buffer Register */
/*! @{ */

#define ADC_CMDH_CMPEN_MASK                      (0x3U)
#define ADC_CMDH_CMPEN_SHIFT                     (0U)
/*! CMPEN - Compare Function Enable
 *  0b00..Compare disabled.
 *  0b01..Reserved
 *  0b10..Compare enabled. Store on true.
 *  0b11..Compare enabled. Repeat channel acquisition (sample/convert/compare) until true.
 */
#define ADC_CMDH_CMPEN(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_CMDH_CMPEN_SHIFT)) & ADC_CMDH_CMPEN_MASK)

#define ADC_CMDH_LWI_MASK                        (0x80U)
#define ADC_CMDH_LWI_SHIFT                       (7U)
/*! LWI - Loop with Increment
 *  0b0..Auto channel increment disabled
 *  0b1..Auto channel increment enabled
 */
#define ADC_CMDH_LWI(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_CMDH_LWI_SHIFT)) & ADC_CMDH_LWI_MASK)

#define ADC_CMDH_STS_MASK                        (0x700U)
#define ADC_CMDH_STS_SHIFT                       (8U)
/*! STS - Sample Time Select
 *  0b000..Minimum sample time of 3 ADCK cycles.
 *  0b001..3 + 21 ADCK cycles; 5 ADCK cycles total sample time.
 *  0b010..3 + 22 ADCK cycles; 7 ADCK cycles total sample time.
 *  0b011..3 + 23 ADCK cycles; 11 ADCK cycles total sample time.
 *  0b100..3 + 24 ADCK cycles; 19 ADCK cycles total sample time.
 *  0b101..3 + 25 ADCK cycles; 35 ADCK cycles total sample time.
 *  0b110..3 + 26 ADCK cycles; 67 ADCK cycles total sample time.
 *  0b111..3 + 27 ADCK cycles; 131 ADCK cycles total sample time.
 */
#define ADC_CMDH_STS(x)                          (((uint32_t)(((uint32_t)(x)) << ADC_CMDH_STS_SHIFT)) & ADC_CMDH_STS_MASK)

#define ADC_CMDH_AVGS_MASK                       (0x7000U)
#define ADC_CMDH_AVGS_SHIFT                      (12U)
/*! AVGS - Hardware Average Select
 *  0b000..Single conversion.
 *  0b001..2 conversions averaged.
 *  0b010..4 conversions averaged.
 *  0b011..8 conversions averaged.
 *  0b100..16 conversions averaged.
 *  0b101..32 conversions averaged.
 *  0b110..64 conversions averaged.
 *  0b111..128 conversions averaged.
 */
#define ADC_CMDH_AVGS(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CMDH_AVGS_SHIFT)) & ADC_CMDH_AVGS_MASK)

#define ADC_CMDH_LOOP_MASK                       (0xF0000U)
#define ADC_CMDH_LOOP_SHIFT                      (16U)
/*! LOOP - Loop Count Select
 *  0b0000..Looping not enabled. Command executes 1 time.
 *  0b0001..Loop 1 time. Command executes 2 times.
 *  0b0010..Loop 2 times. Command executes 3 times.
 *  0b0011-0b1110..Loop corresponding number of times. Command executes LOOP+1 times.
 *  0b1111..Loop 15 times. Command executes 16 times.
 */
#define ADC_CMDH_LOOP(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CMDH_LOOP_SHIFT)) & ADC_CMDH_LOOP_MASK)

#define ADC_CMDH_NEXT_MASK                       (0xF000000U)
#define ADC_CMDH_NEXT_SHIFT                      (24U)
/*! NEXT - Next Command Select
 *  0b0000..No next command defined. Terminate conversions at completion of current command. If lower priority
 *          trigger pending, begin command associated with lower priority trigger.
 *  0b0001..Select CMD1 command buffer register as next command.
 *  0b0010-0b1110..Select corresponding CMD command buffer register as next command
 *  0b1111..Select CMD15 command buffer register as next command.
 */
#define ADC_CMDH_NEXT(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_CMDH_NEXT_SHIFT)) & ADC_CMDH_NEXT_MASK)
/*! @} */

/* The count of ADC_CMDH */
#define ADC_CMDH_COUNT                           (15U)

/*! @name CV - Compare Value Register */
/*! @{ */

#define ADC_CV_CVL_MASK                          (0xFFFFU)
#define ADC_CV_CVL_SHIFT                         (0U)
/*! CVL - Compare Value Low. */
#define ADC_CV_CVL(x)                            (((uint32_t)(((uint32_t)(x)) << ADC_CV_CVL_SHIFT)) & ADC_CV_CVL_MASK)

#define ADC_CV_CVH_MASK                          (0xFFFF0000U)
#define ADC_CV_CVH_SHIFT                         (16U)
/*! CVH - Compare Value High. */
#define ADC_CV_CVH(x)                            (((uint32_t)(((uint32_t)(x)) << ADC_CV_CVH_SHIFT)) & ADC_CV_CVH_MASK)
/*! @} */

/*! @name RESFIFO - LPADC Data Result FIFO Register */
/*! @{ */

#define ADC_RESFIFO_D_MASK                       (0xFFFFU)
#define ADC_RESFIFO_D_SHIFT                      (0U)
/*! D - Data result */
#define ADC_RESFIFO_D(x)                         (((uint32_t)(((uint32_t)(x)) << ADC_RESFIFO_D_SHIFT)) & ADC_RESFIFO_D_MASK)

#define ADC_RESFIFO_TSRC_MASK                    (0x30000U)
#define ADC_RESFIFO_TSRC_SHIFT                   (16U)
/*! TSRC - Trigger Source
 *  0b00..Trigger source 0 initiated this conversion.
 *  0b01..Trigger source 1 initiated this conversion.
 *  0b10..Trigger source 2 initiated this conversion.
 *  0b11..Trigger source 3 initiated this conversion.
 */
#define ADC_RESFIFO_TSRC(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_RESFIFO_TSRC_SHIFT)) & ADC_RESFIFO_TSRC_MASK)

#define ADC_RESFIFO_LOOPCNT_MASK                 (0xF00000U)
#define ADC_RESFIFO_LOOPCNT_SHIFT                (20U)
/*! LOOPCNT - Loop count value
 *  0b0000..Result is from initial conversion in command.
 *  0b0001..Result is from second conversion in command.
 *  0b0010-0b1110..Result is from LOOPCNT+1 conversion in command.
 *  0b1111..Result is from 16th conversion in command.
 */
#define ADC_RESFIFO_LOOPCNT(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_RESFIFO_LOOPCNT_SHIFT)) & ADC_RESFIFO_LOOPCNT_MASK)

#define ADC_RESFIFO_CMDSRC_MASK                  (0xF000000U)
#define ADC_RESFIFO_CMDSRC_SHIFT                 (24U)
/*! CMDSRC - Command Buffer Source
 *  0b0000..Not a valid value CMDSRC value for a dataword in RESFIFO. 0x0 is only found in initial FIFO state
 *          prior to an ADC conversion result dataword being stored to a RESFIFO buffer.
 *  0b0001..CMD1 buffer used as control settings for this conversion.
 *  0b0010-0b1110..Corresponding command buffer used as control settings for this conversion.
 *  0b1111..CMD15 buffer used as control settings for this conversion.
 */
#define ADC_RESFIFO_CMDSRC(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_RESFIFO_CMDSRC_SHIFT)) & ADC_RESFIFO_CMDSRC_MASK)

#define ADC_RESFIFO_VALID_MASK                   (0x80000000U)
#define ADC_RESFIFO_VALID_SHIFT                  (31U)
/*! VALID - FIFO entry is valid
 *  0b0..FIFO is empty. Discard any read from RESFIFO.
 *  0b1..FIFO record read from RESFIFO is valid.
 */
#define ADC_RESFIFO_VALID(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_RESFIFO_VALID_SHIFT)) & ADC_RESFIFO_VALID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ADC_Register_Masks */


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
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_ADC_H_ */

