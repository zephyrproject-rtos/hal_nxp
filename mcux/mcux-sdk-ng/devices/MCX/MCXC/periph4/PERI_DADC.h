/*
** ###################################################################
**     Processors:          MCXC352GAMFM
**                          MCXC352GAMFT
**                          MCXC352MLF
**                          MCXC353GAMFM
**                          MCXC353GAMFT
**                          MCXC353MLF
**
**     Version:             rev. 1.0, 2025-11-26
**     Build:               b260826
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DADC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-11-26)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DADC.h
 * @version 1.0
 * @date 2025-11-26
 * @brief CMSIS Peripheral Access Layer for DADC
 *
 * CMSIS Peripheral Access Layer for DADC
 */

#if !defined(PERI_DADC_H_)
#define PERI_DADC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC352GAMFM) || defined(CPU_MCXC352GAMFT) || defined(CPU_MCXC352MLF))
#include "MCXC352_COMMON.h"
#elif (defined(CPU_MCXC353GAMFM) || defined(CPU_MCXC353GAMFT) || defined(CPU_MCXC353MLF))
#include "MCXC353_COMMON.h"
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
   -- DADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DADC_Peripheral_Access_Layer DADC Peripheral Access Layer
 * @{
 */

/** DADC - Size of Registers Arrays */
#define DADC_CMD_COUNT                            20u
#define DADC_CV_COUNT                             20u
#define DADC_RSLT_RSLT_16B_RSLT_16B_COUNT         20u
#define DADC_RSLT_RSLT_32B_RSLT_COUNT             20u
#define DADC_GCC_COUNT                            2u
#define DADC_GCR_COUNT                            2u
#define DADC_CAL_GAR_COUNT                        33u
#define DADC_CAL_GBR_COUNT                        33u

/** DADC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t CTRL;                              /**< Control Register, offset: 0x8 */
  __IO uint32_t CFG0;                              /**< Configuration 0 Register, offset: 0xC */
  __IO uint32_t CFG1;                              /**< Configuration 1 Register, offset: 0x10 */
  __IO uint32_t DE;                                /**< DMA Enable Register, offset: 0x14 */
       uint8_t RESERVED_0[8];
  __IO uint32_t CMP_IE;                            /**< Compare Interrupt Enable Register, offset: 0x20 */
  __IO uint32_t RSLTRDY_IE;                        /**< Result Ready Interrupt Enable Register, offset: 0x24 */
  __IO uint32_t IE;                                /**< Interrupt Enable Register, offset: 0x28 */
  __IO uint32_t PAUSE;                             /**< Pause Register, offset: 0x2C */
  __IO uint32_t SWTRIG;                            /**< Software Trigger Register, offset: 0x30 */
  __IO uint32_t TCTRL;                             /**< Trigger Control Register, offset: 0x34 */
  __IO uint32_t AVGT_CTRL;                         /**< Average with Timer Control Register, offset: 0x38 */
  __IO uint32_t ITCFG;                             /**< Average Interval Time Configuration Register, offset: 0x3C */
       uint8_t RESERVED_1[16];
  __IO uint32_t CMD[DADC_CMD_COUNT];               /**< Command Buffer Register, array offset: 0x50, array step: 0x4 */
       uint8_t RESERVED_2[32];
  __IO uint32_t CV[DADC_CV_COUNT];                 /**< Compare Value Register, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_3[32];
  __I  uint32_t STAT0;                             /**< Status 0 Register, offset: 0x130 */
  __IO uint32_t CMP_STAT;                          /**< Compare Status Register, offset: 0x134 */
  __I  uint32_t RSLTRDY_STAT;                      /**< Result Ready Status Register, offset: 0x138 */
  __IO uint32_t STAT1;                             /**< Status 1 Register, offset: 0x13C */
  __IO uint32_t STAT2;                             /**< Status 2 Register, offset: 0x140 */
       uint8_t RESERVED_4[12];
  union {                                          /* offset: 0x150 */
    struct {                                         /* offset: 0x150, array step: 0x4 */
      __I  uint16_t RSLT_H;                            /**< Digital Result of the Conversion (Higher 16-Bit), array offset: 0x150, array step: 0x4 */
      __I  uint16_t RSLT_L;                            /**< Digital Result of the Conversion (Lower 16-Bit), array offset: 0x152, array step: 0x4 */
    } RSLT_16B[DADC_RSLT_RSLT_16B_RSLT_16B_COUNT];
    __I  uint32_t RSLT[DADC_RSLT_RSLT_32B_RSLT_COUNT];   /**< Digital Result of the Conversion, array offset: 0x150, array step: 0x4 */
  };
       uint8_t RESERVED_5[32];
  __IO uint32_t OFSTRIM;                           /**< Offset Trim Register, offset: 0x1C0 */
  __IO uint32_t HSTRIM;                            /**< High Speed Trim Register, offset: 0x1C4 */
  __I  uint32_t GCC[DADC_GCC_COUNT];               /**< Gain Calibration Control, array offset: 0x1C8, array step: 0x4 */
  __IO uint32_t GCR[DADC_GCR_COUNT];               /**< Gain Calculation Result, array offset: 0x1D0, array step: 0x4 */
       uint8_t RESERVED_6[40];
  __IO uint32_t CAL_GAR[DADC_CAL_GAR_COUNT];       /**< Calibration A-side Registers, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_7[124];
  __IO uint32_t CAL_GBR[DADC_CAL_GBR_COUNT];       /**< Calibration B-side Registers, array offset: 0x300, array step: 0x4 */
} DADC_Type;

/* ----------------------------------------------------------------------------
   -- DADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DADC_Register_Masks DADC Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define DADC_VERID_MINOR_MASK                    (0xFF0000U)
#define DADC_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number */
#define DADC_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << DADC_VERID_MINOR_SHIFT)) & DADC_VERID_MINOR_MASK)

#define DADC_VERID_MAJOR_MASK                    (0xFF000000U)
#define DADC_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number */
#define DADC_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << DADC_VERID_MAJOR_SHIFT)) & DADC_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define DADC_PARAM_TRIG_NUM_MASK                 (0xFFU)
#define DADC_PARAM_TRIG_NUM_SHIFT                (0U)
/*! TRIG_NUM - Trigger Number */
#define DADC_PARAM_TRIG_NUM(x)                   (((uint32_t)(((uint32_t)(x)) << DADC_PARAM_TRIG_NUM_SHIFT)) & DADC_PARAM_TRIG_NUM_MASK)

#define DADC_PARAM_CV_NUM_MASK                   (0xFF0000U)
#define DADC_PARAM_CV_NUM_SHIFT                  (16U)
/*! CV_NUM - Compare Value Number */
#define DADC_PARAM_CV_NUM(x)                     (((uint32_t)(((uint32_t)(x)) << DADC_PARAM_CV_NUM_SHIFT)) & DADC_PARAM_CV_NUM_MASK)

#define DADC_PARAM_CMD_NUM_MASK                  (0xFF000000U)
#define DADC_PARAM_CMD_NUM_SHIFT                 (24U)
/*! CMD_NUM - Command Buffer Number */
#define DADC_PARAM_CMD_NUM(x)                    (((uint32_t)(((uint32_t)(x)) << DADC_PARAM_CMD_NUM_SHIFT)) & DADC_PARAM_CMD_NUM_MASK)
/*! @} */

/*! @name CTRL - Control Register */
/*! @{ */

#define DADC_CTRL_ADCEN_MASK                     (0x1U)
#define DADC_CTRL_ADCEN_SHIFT                    (0U)
/*! ADCEN - DUALADC Enable
 *  0b0..DUALADC is disabled.
 *  0b1..DUALADC is enabled.
 */
#define DADC_CTRL_ADCEN(x)                       (((uint32_t)(((uint32_t)(x)) << DADC_CTRL_ADCEN_SHIFT)) & DADC_CTRL_ADCEN_MASK)

#define DADC_CTRL_DOZEN_MASK                     (0x4U)
#define DADC_CTRL_DOZEN_SHIFT                    (2U)
/*! DOZEN - Doze Enable
 *  0b0..DUALADC is enabled in low power mode.
 *  0b1..DUALADC is disabled in low power mode.
 */
#define DADC_CTRL_DOZEN(x)                       (((uint32_t)(((uint32_t)(x)) << DADC_CTRL_DOZEN_SHIFT)) & DADC_CTRL_DOZEN_MASK)

#define DADC_CTRL_CST_LONG_MASK                  (0x80U)
#define DADC_CTRL_CST_LONG_SHIFT                 (7U)
/*! CST_LONG - Calibration Sample Time Long
 *  0b0..Normal sample time. Minimum sample time of 3.5 ADCK cycles.
 *  0b1..Increased sample time. 67.5 ADCK cycles total sample time.
 */
#define DADC_CTRL_CST_LONG(x)                    (((uint32_t)(((uint32_t)(x)) << DADC_CTRL_CST_LONG_SHIFT)) & DADC_CTRL_CST_LONG_MASK)

#define DADC_CTRL_CAL_REQ_MASK                   (0x100U)
#define DADC_CTRL_CAL_REQ_SHIFT                  (8U)
/*! CAL_REQ - Auto-Calibration Request
 *  0b0..No request for hardware calibration has been made
 *  0b1..A request for hardware calibration has been made
 */
#define DADC_CTRL_CAL_REQ(x)                     (((uint32_t)(((uint32_t)(x)) << DADC_CTRL_CAL_REQ_SHIFT)) & DADC_CTRL_CAL_REQ_MASK)

#define DADC_CTRL_CALOFS_MASK                    (0x200U)
#define DADC_CTRL_CALOFS_SHIFT                   (9U)
/*! CALOFS - Offset Calibration Request
 *  0b0..No request for offset calibration has been made
 *  0b1..Request for offset calibration function
 */
#define DADC_CTRL_CALOFS(x)                      (((uint32_t)(((uint32_t)(x)) << DADC_CTRL_CALOFS_SHIFT)) & DADC_CTRL_CALOFS_MASK)

#define DADC_CTRL_CALHS_MASK                     (0x400U)
#define DADC_CTRL_CALHS_SHIFT                    (10U)
/*! CALHS - High Speed Mode Trim Request
 *  0b0..No request for high speed mode trim has been made
 *  0b1..Request for high speed mode trim has been made
 */
#define DADC_CTRL_CALHS(x)                       (((uint32_t)(((uint32_t)(x)) << DADC_CTRL_CALHS_SHIFT)) & DADC_CTRL_CALHS_MASK)

#define DADC_CTRL_CAL_AVGS_MASK                  (0xF000U)
#define DADC_CTRL_CAL_AVGS_SHIFT                 (12U)
/*! CAL_AVGS - Auto-Calibration Averages
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
 *  0b1010-0b1111..1024 conversions averaged.
 */
#define DADC_CTRL_CAL_AVGS(x)                    (((uint32_t)(((uint32_t)(x)) << DADC_CTRL_CAL_AVGS_SHIFT)) & DADC_CTRL_CAL_AVGS_MASK)

#define DADC_CTRL_RSTA_MASK                      (0x10000U)
#define DADC_CTRL_RSTA_SHIFT                     (16U)
/*! RSTA - Software Reset for ADCA
 *  0b0..Logic is not reset.
 *  0b1..Logic is reset.
 */
#define DADC_CTRL_RSTA(x)                        (((uint32_t)(((uint32_t)(x)) << DADC_CTRL_RSTA_SHIFT)) & DADC_CTRL_RSTA_MASK)

#define DADC_CTRL_RSTB_MASK                      (0x20000U)
#define DADC_CTRL_RSTB_SHIFT                     (17U)
/*! RSTB - Software Reset for ADCB
 *  0b0..Logic is not reset.
 *  0b1..Logic is reset.
 */
#define DADC_CTRL_RSTB(x)                        (((uint32_t)(((uint32_t)(x)) << DADC_CTRL_RSTB_SHIFT)) & DADC_CTRL_RSTB_MASK)
/*! @} */

/*! @name CFG0 - Configuration 0 Register */
/*! @{ */

#define DADC_CFG0_INDEP_MASK                     (0x1U)
#define DADC_CFG0_INDEP_SHIFT                    (0U)
/*! INDEP - Conversion Mode Select
 *  0b0..Cooperation mode.
 *  0b1..Independence mode.
 */
#define DADC_CFG0_INDEP(x)                       (((uint32_t)(((uint32_t)(x)) << DADC_CFG0_INDEP_SHIFT)) & DADC_CFG0_INDEP_MASK)

#define DADC_CFG0_TRIGSEL_MASK                   (0x2U)
#define DADC_CFG0_TRIGSEL_SHIFT                  (1U)
/*! TRIGSEL - Trigger Source Select for ADCA
 *  0b0..Select Trigger0 as trigger source.
 *  0b1..Select Trigger_sync_in as trigger source.
 */
#define DADC_CFG0_TRIGSEL(x)                     (((uint32_t)(((uint32_t)(x)) << DADC_CFG0_TRIGSEL_SHIFT)) & DADC_CFG0_TRIGSEL_MASK)

#define DADC_CFG0_PWRSEL_MASK                    (0x10U)
#define DADC_CFG0_PWRSEL_SHIFT                   (4U)
/*! PWRSEL - Power Configuration Select
 *  0b0..Low power
 *  0b1..High power
 */
#define DADC_CFG0_PWRSEL(x)                      (((uint32_t)(((uint32_t)(x)) << DADC_CFG0_PWRSEL_SHIFT)) & DADC_CFG0_PWRSEL_MASK)

#define DADC_CFG0_PWREN_MASK                     (0x20U)
#define DADC_CFG0_PWREN_SHIFT                    (5U)
/*! PWREN - DUALADC Analog Pre-Enable
 *  0b0..DUALADC analog circuits are only enabled while conversions are active. Performance is affected due to analog startup delays.
 *  0b1..DUALADC analog circuits are pre-enabled and ready to execute conversions without startup delays (at the
 *       cost of higher DC current consumption). Note that a single power up delay (CFG0[PUDLY]) is executed
 *       immediately once PWREN is set, and any detected trigger does not begin DUALADC operation until the power up delay
 *       time has passed. After this initial delay expires the analog remains pre-enabled and no additional delays
 *       are executed.
 */
#define DADC_CFG0_PWREN(x)                       (((uint32_t)(((uint32_t)(x)) << DADC_CFG0_PWREN_SHIFT)) & DADC_CFG0_PWREN_MASK)

#define DADC_CFG0_REFSEL_MASK                    (0xC0U)
#define DADC_CFG0_REFSEL_SHIFT                   (6U)
/*! REFSEL - Voltage Reference Selection
 *  0b00..(Default) VREFH0x
 *  0b01..VREFH1x
 *  0b10..VREFH2x
 *  0b11..Reserved
 */
#define DADC_CFG0_REFSEL(x)                      (((uint32_t)(((uint32_t)(x)) << DADC_CFG0_REFSEL_SHIFT)) & DADC_CFG0_REFSEL_MASK)

#define DADC_CFG0_PUDLY_MASK                     (0xFF0000U)
#define DADC_CFG0_PUDLY_SHIFT                    (16U)
/*! PUDLY - Power Up Delay */
#define DADC_CFG0_PUDLY(x)                       (((uint32_t)(((uint32_t)(x)) << DADC_CFG0_PUDLY_SHIFT)) & DADC_CFG0_PUDLY_MASK)
/*! @} */

/*! @name CFG1 - Configuration 1 Register */
/*! @{ */

#define DADC_CFG1_JLEFT_MASK                     (0x100U)
#define DADC_CFG1_JLEFT_SHIFT                    (8U)
/*! JLEFT - Justified Left Enable register
 *  0b0..12bit result is placed in bit14~bit3. Bit15 and bit2~bit0 are filled with 0.
 *  0b1..12bit result is placed in bit15~bit4. Bit3~bit0 are filled with 0.
 */
#define DADC_CFG1_JLEFT(x)                       (((uint32_t)(((uint32_t)(x)) << DADC_CFG1_JLEFT_SHIFT)) & DADC_CFG1_JLEFT_MASK)

#define DADC_CFG1_HS_MASK                        (0x200U)
#define DADC_CFG1_HS_SHIFT                       (9U)
/*! HS - High Speed Enable register
 *  0b0..High speed conversion mode disabled
 *  0b1..High speed conversion mode enabled
 */
#define DADC_CFG1_HS(x)                          (((uint32_t)(((uint32_t)(x)) << DADC_CFG1_HS_SHIFT)) & DADC_CFG1_HS_MASK)

#define DADC_CFG1_HSEXTRA_MASK                   (0x400U)
#define DADC_CFG1_HSEXTRA_SHIFT                  (10U)
/*! HSEXTRA - High Speed Extra register
 *  0b0..No extra cycle added
 *  0b1..Extra cycle added
 */
#define DADC_CFG1_HSEXTRA(x)                     (((uint32_t)(((uint32_t)(x)) << DADC_CFG1_HSEXTRA_SHIFT)) & DADC_CFG1_HSEXTRA_MASK)

#define DADC_CFG1_TUNE_MASK                      (0x3000U)
#define DADC_CFG1_TUNE_SHIFT                     (12U)
/*! TUNE - Tune Mode register */
#define DADC_CFG1_TUNE(x)                        (((uint32_t)(((uint32_t)(x)) << DADC_CFG1_TUNE_SHIFT)) & DADC_CFG1_TUNE_MASK)
/*! @} */

/*! @name DE - DMA Enable Register */
/*! @{ */

#define DADC_DE_DMAENAA_MASK                     (0x1U)
#define DADC_DE_DMAENAA_SHIFT                    (0U)
/*! DMAENAA - DMA enable for ADCA
 *  0b0..DMA disable.
 *  0b1..DMA enable.
 */
#define DADC_DE_DMAENAA(x)                       (((uint32_t)(((uint32_t)(x)) << DADC_DE_DMAENAA_SHIFT)) & DADC_DE_DMAENAA_MASK)

#define DADC_DE_DMAENAB_MASK                     (0x2U)
#define DADC_DE_DMAENAB_SHIFT                    (1U)
/*! DMAENAB - DMA enable for ADCB
 *  0b0..DMA disable.
 *  0b1..DMA enable.
 */
#define DADC_DE_DMAENAB(x)                       (((uint32_t)(((uint32_t)(x)) << DADC_DE_DMAENAB_SHIFT)) & DADC_DE_DMAENAB_MASK)

#define DADC_DE_DMASRCA_MASK                     (0x10000U)
#define DADC_DE_DMASRCA_SHIFT                    (16U)
/*! DMASRCA - DMA Trigger Source for ADCA
 *  0b0..DMA trigger source is EOSIA
 *  0b1..DMA trigger source is RDYn bits
 */
#define DADC_DE_DMASRCA(x)                       (((uint32_t)(((uint32_t)(x)) << DADC_DE_DMASRCA_SHIFT)) & DADC_DE_DMASRCA_MASK)

#define DADC_DE_DMASRCB_MASK                     (0x20000U)
#define DADC_DE_DMASRCB_SHIFT                    (17U)
/*! DMASRCB - DMA Trigger Source for ADCB
 *  0b0..DMA trigger source is EOSIB
 *  0b1..DMA trigger source is RDYn bits
 */
#define DADC_DE_DMASRCB(x)                       (((uint32_t)(((uint32_t)(x)) << DADC_DE_DMASRCB_SHIFT)) & DADC_DE_DMASRCB_MASK)
/*! @} */

/*! @name CMP_IE - Compare Interrupt Enable Register */
/*! @{ */

#define DADC_CMP_IE_CMPn_IE_MASK                 (0xFFFFFU)
#define DADC_CMP_IE_CMPn_IE_SHIFT                (0U)
/*! CMPn_IE - Compare Interrupt Enable
 *  0b00000000000000000000..All of CMDs compare interrupt is disabled.
 *  0b00000000000000000001..CMD1 compare interrupt is enabled.
 *  0b00000000000000000010..CMD2 compare interrupt is enabled.
 *  0b00000000000000000100..CMD3 compare interrupt is enabled.
 *  0b01000000000000000000..Corresponding bit indicates the compare interrupts are enabled, When bit n equals 1, it means CMDn+1 compare interrupt is enabled.
 */
#define DADC_CMP_IE_CMPn_IE(x)                   (((uint32_t)(((uint32_t)(x)) << DADC_CMP_IE_CMPn_IE_SHIFT)) & DADC_CMP_IE_CMPn_IE_MASK)
/*! @} */

/*! @name RSLTRDY_IE - Result Ready Interrupt Enable Register */
/*! @{ */

#define DADC_RSLTRDY_IE_RDYn_IE_MASK             (0xFFFFFU)
#define DADC_RSLTRDY_IE_RDYn_IE_SHIFT            (0U)
/*! RDYn_IE - Result Ready Interrupt Enable
 *  0b00000000000000000000..The result ready of CMDs interrupt is disabled.
 *  0b00000000000000000001..The result ready of CMD1 interrupt is enabled.
 *  0b00000000000000000010..The result ready of CMD2 interrupt is enabled.
 *  0b00000000000000000100..The result ready of CMD3 interrupt is enabled.
 *  0b01000000000000000000..Corresponding bit indicates the result ready interrupt is enable, When bit n equals 1,
 *                          it means the result ready of CMDn+1 interrupt is enabled.
 */
#define DADC_RSLTRDY_IE_RDYn_IE(x)               (((uint32_t)(((uint32_t)(x)) << DADC_RSLTRDY_IE_RDYn_IE_SHIFT)) & DADC_RSLTRDY_IE_RDYn_IE_MASK)
/*! @} */

/*! @name IE - Interrupt Enable Register */
/*! @{ */

#define DADC_IE_EOSIEA_MASK                      (0x1U)
#define DADC_IE_EOSIEA_SHIFT                     (0U)
/*! EOSIEA - End of Scan Interrupt Enable for ADCA
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define DADC_IE_EOSIEA(x)                        (((uint32_t)(((uint32_t)(x)) << DADC_IE_EOSIEA_SHIFT)) & DADC_IE_EOSIEA_MASK)

#define DADC_IE_OVERLAPIEA_MASK                  (0x100U)
#define DADC_IE_OVERLAPIEA_SHIFT                 (8U)
/*! OVERLAPIEA - Over Lap Interrupt Enable for ADCA
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define DADC_IE_OVERLAPIEA(x)                    (((uint32_t)(((uint32_t)(x)) << DADC_IE_OVERLAPIEA_SHIFT)) & DADC_IE_OVERLAPIEA_MASK)

#define DADC_IE_INTVTIMEERRIEA_MASK              (0x200U)
#define DADC_IE_INTVTIMEERRIEA_SHIFT             (9U)
/*! INTVTIMEERRIEA - Interval Time Error Interrupt Enable for ADCA
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define DADC_IE_INTVTIMEERRIEA(x)                (((uint32_t)(((uint32_t)(x)) << DADC_IE_INTVTIMEERRIEA_SHIFT)) & DADC_IE_INTVTIMEERRIEA_MASK)

#define DADC_IE_EOSIEB_MASK                      (0x10000U)
#define DADC_IE_EOSIEB_SHIFT                     (16U)
/*! EOSIEB - End of Scan Interrupt Enable for ADCB
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define DADC_IE_EOSIEB(x)                        (((uint32_t)(((uint32_t)(x)) << DADC_IE_EOSIEB_SHIFT)) & DADC_IE_EOSIEB_MASK)

#define DADC_IE_OVERLAPIEB_MASK                  (0x1000000U)
#define DADC_IE_OVERLAPIEB_SHIFT                 (24U)
/*! OVERLAPIEB - Over Lap Interrupt Enable for ADCB
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define DADC_IE_OVERLAPIEB(x)                    (((uint32_t)(((uint32_t)(x)) << DADC_IE_OVERLAPIEB_SHIFT)) & DADC_IE_OVERLAPIEB_MASK)

#define DADC_IE_INTVTIMEERRIEB_MASK              (0x2000000U)
#define DADC_IE_INTVTIMEERRIEB_SHIFT             (25U)
/*! INTVTIMEERRIEB - Interval Time Error Interrupt Enable for ADCB
 *  0b0..Interrupt disabled.
 *  0b1..Interrupt enabled.
 */
#define DADC_IE_INTVTIMEERRIEB(x)                (((uint32_t)(((uint32_t)(x)) << DADC_IE_INTVTIMEERRIEB_SHIFT)) & DADC_IE_INTVTIMEERRIEB_MASK)
/*! @} */

/*! @name PAUSE - Pause Register */
/*! @{ */

#define DADC_PAUSE_PAUSEDLY_MASK                 (0x1FFU)
#define DADC_PAUSE_PAUSEDLY_SHIFT                (0U)
/*! PAUSEDLY - Pause Delay */
#define DADC_PAUSE_PAUSEDLY(x)                   (((uint32_t)(((uint32_t)(x)) << DADC_PAUSE_PAUSEDLY_SHIFT)) & DADC_PAUSE_PAUSEDLY_MASK)

#define DADC_PAUSE_PAUSEEN_MASK                  (0x80000000U)
#define DADC_PAUSE_PAUSEEN_SHIFT                 (31U)
/*! PAUSEEN - PAUSE Option Enable
 *  0b0..Pause operation disabled
 *  0b1..Pause operation enabled
 */
#define DADC_PAUSE_PAUSEEN(x)                    (((uint32_t)(((uint32_t)(x)) << DADC_PAUSE_PAUSEEN_SHIFT)) & DADC_PAUSE_PAUSEEN_MASK)
/*! @} */

/*! @name SWTRIG - Software Trigger Register */
/*! @{ */

#define DADC_SWTRIG_SWT0_MASK                    (0x1U)
#define DADC_SWTRIG_SWT0_SHIFT                   (0U)
/*! SWT0 - Software Trigger 0 Event
 *  0b0..No trigger 0 event generated.
 *  0b1..Trigger 0 event generated.
 */
#define DADC_SWTRIG_SWT0(x)                      (((uint32_t)(((uint32_t)(x)) << DADC_SWTRIG_SWT0_SHIFT)) & DADC_SWTRIG_SWT0_MASK)

#define DADC_SWTRIG_SWT1_MASK                    (0x2U)
#define DADC_SWTRIG_SWT1_SHIFT                   (1U)
/*! SWT1 - Software Trigger 1 Event
 *  0b0..No trigger 1 event generated.
 *  0b1..Trigger 1 event generated.
 */
#define DADC_SWTRIG_SWT1(x)                      (((uint32_t)(((uint32_t)(x)) << DADC_SWTRIG_SWT1_SHIFT)) & DADC_SWTRIG_SWT1_MASK)
/*! @} */

/*! @name TCTRL - Trigger Control Register */
/*! @{ */

#define DADC_TCTRL_HTEN0_MASK                    (0x1U)
#define DADC_TCTRL_HTEN0_SHIFT                   (0U)
/*! HTEN0 - Trigger Enable for Hard Trigger 0
 *  0b0..Hardware trigger source disabled
 *  0b1..Hardware trigger source enabled
 */
#define DADC_TCTRL_HTEN0(x)                      (((uint32_t)(((uint32_t)(x)) << DADC_TCTRL_HTEN0_SHIFT)) & DADC_TCTRL_HTEN0_MASK)

#define DADC_TCTRL_TDLY0_MASK                    (0xF00U)
#define DADC_TCTRL_TDLY0_SHIFT                   (8U)
/*! TDLY0 - Trigger Delay Select for Trigger 0 */
#define DADC_TCTRL_TDLY0(x)                      (((uint32_t)(((uint32_t)(x)) << DADC_TCTRL_TDLY0_SHIFT)) & DADC_TCTRL_TDLY0_MASK)

#define DADC_TCTRL_HTEN1_MASK                    (0x10000U)
#define DADC_TCTRL_HTEN1_SHIFT                   (16U)
/*! HTEN1 - Trigger Enable for Hard Trigger 1
 *  0b0..Hardware trigger source disabled
 *  0b1..Hardware trigger source enabled
 */
#define DADC_TCTRL_HTEN1(x)                      (((uint32_t)(((uint32_t)(x)) << DADC_TCTRL_HTEN1_SHIFT)) & DADC_TCTRL_HTEN1_MASK)

#define DADC_TCTRL_TDLY1_MASK                    (0xF000000U)
#define DADC_TCTRL_TDLY1_SHIFT                   (24U)
/*! TDLY1 - Trigger Delay Select for Trigger 1 */
#define DADC_TCTRL_TDLY1(x)                      (((uint32_t)(((uint32_t)(x)) << DADC_TCTRL_TDLY1_SHIFT)) & DADC_TCTRL_TDLY1_MASK)
/*! @} */

/*! @name AVGT_CTRL - Average with Timer Control Register */
/*! @{ */

#define DADC_AVGT_CTRL_AVGTA_TIMES_MASK          (0x1FFU)
#define DADC_AVGT_CTRL_AVGTA_TIMES_SHIFT         (0U)
/*! AVGTA_TIMES - Sequence Conversion Times for ADCA
 *  0b000000000..The actual number of times that the conversion sequence must be executed to get the averaged
 *               results is AVGTA_TIMES+1.The maximum number is 512.
 */
#define DADC_AVGT_CTRL_AVGTA_TIMES(x)            (((uint32_t)(((uint32_t)(x)) << DADC_AVGT_CTRL_AVGTA_TIMES_SHIFT)) & DADC_AVGT_CTRL_AVGTA_TIMES_MASK)

#define DADC_AVGT_CTRL_AVGTA_EN_MASK             (0x8000U)
#define DADC_AVGT_CTRL_AVGTA_EN_SHIFT            (15U)
/*! AVGTA_EN - "Average with Timer" Feature Enable for ADCA
 *  0b0..Disable average with timer for ADCA in independence mode, or for both ADCA and ADCB in cooperation mode.
 *  0b1..Enable average with timer for ADCA in independence mode, or for both ADCA and ADCB in cooperation mode.
 */
#define DADC_AVGT_CTRL_AVGTA_EN(x)               (((uint32_t)(((uint32_t)(x)) << DADC_AVGT_CTRL_AVGTA_EN_SHIFT)) & DADC_AVGT_CTRL_AVGTA_EN_MASK)

#define DADC_AVGT_CTRL_AVGTB_TIMES_MASK          (0x1FF0000U)
#define DADC_AVGT_CTRL_AVGTB_TIMES_SHIFT         (16U)
/*! AVGTB_TIMES - Sequence Conversion Times for ADCB
 *  0b000000000..The actual number of times that the conversion sequence must be executed to get the averaged
 *               results is AVGTB_TIMES+1.The maximum number is 512.
 */
#define DADC_AVGT_CTRL_AVGTB_TIMES(x)            (((uint32_t)(((uint32_t)(x)) << DADC_AVGT_CTRL_AVGTB_TIMES_SHIFT)) & DADC_AVGT_CTRL_AVGTB_TIMES_MASK)

#define DADC_AVGT_CTRL_AVGTB_EN_MASK             (0x80000000U)
#define DADC_AVGT_CTRL_AVGTB_EN_SHIFT            (31U)
/*! AVGTB_EN - "Average with timer" Feature Enable for ADCB
 *  0b0..Disable average with timer for ADCB in independence mode.
 *  0b1..Enable average with timer for ADCB in independence mode.
 */
#define DADC_AVGT_CTRL_AVGTB_EN(x)               (((uint32_t)(((uint32_t)(x)) << DADC_AVGT_CTRL_AVGTB_EN_SHIFT)) & DADC_AVGT_CTRL_AVGTB_EN_MASK)
/*! @} */

/*! @name ITCFG - Average Interval Time Configuration Register */
/*! @{ */

#define DADC_ITCFG_PRESCALERA_MASK               (0x7U)
#define DADC_ITCFG_PRESCALERA_SHIFT              (0U)
/*! PRESCALERA - Interval timer prescaler for ADCA */
#define DADC_ITCFG_PRESCALERA(x)                 (((uint32_t)(((uint32_t)(x)) << DADC_ITCFG_PRESCALERA_SHIFT)) & DADC_ITCFG_PRESCALERA_MASK)

#define DADC_ITCFG_INTERVALA_MASK                (0xFF8U)
#define DADC_ITCFG_INTERVALA_SHIFT               (3U)
/*! INTERVALA - Time interval for ADCA */
#define DADC_ITCFG_INTERVALA(x)                  (((uint32_t)(((uint32_t)(x)) << DADC_ITCFG_INTERVALA_SHIFT)) & DADC_ITCFG_INTERVALA_MASK)

#define DADC_ITCFG_PRESCALERB_MASK               (0x70000U)
#define DADC_ITCFG_PRESCALERB_SHIFT              (16U)
/*! PRESCALERB - Interval timer prescaler for ADCB */
#define DADC_ITCFG_PRESCALERB(x)                 (((uint32_t)(((uint32_t)(x)) << DADC_ITCFG_PRESCALERB_SHIFT)) & DADC_ITCFG_PRESCALERB_MASK)

#define DADC_ITCFG_INTERVALB_MASK                (0xFF80000U)
#define DADC_ITCFG_INTERVALB_SHIFT               (19U)
/*! INTERVALB - Time interval for ADCB */
#define DADC_ITCFG_INTERVALB(x)                  (((uint32_t)(((uint32_t)(x)) << DADC_ITCFG_INTERVALB_SHIFT)) & DADC_ITCFG_INTERVALB_MASK)
/*! @} */

/*! @name CMD - Command Buffer Register */
/*! @{ */

#define DADC_CMD_CMPEN_MASK                      (0x1U)
#define DADC_CMD_CMPEN_SHIFT                     (0U)
/*! CMPEN - Compare Function Enable
 *  0b0..Compare disabled.
 *  0b1..Compare enabled.
 */
#define DADC_CMD_CMPEN(x)                        (((uint32_t)(((uint32_t)(x)) << DADC_CMD_CMPEN_SHIFT)) & DADC_CMD_CMPEN_MASK)

#define DADC_CMD_WAIT_TRIG_MASK                  (0x2U)
#define DADC_CMD_WAIT_TRIG_SHIFT                 (1U)
/*! WAIT_TRIG - Wait for Trigger Assertion before Execution.
 *  0b0..This command will be automatically executed.
 *  0b1..The active trigger must be asserted again before executing this command.
 */
#define DADC_CMD_WAIT_TRIG(x)                    (((uint32_t)(((uint32_t)(x)) << DADC_CMD_WAIT_TRIG_SHIFT)) & DADC_CMD_WAIT_TRIG_MASK)

#define DADC_CMD_CTYPE_MASK                      (0x30U)
#define DADC_CMD_CTYPE_SHIFT                     (4U)
/*! CTYPE - Conversion Type
 *  0b00..Single-Ended Mode. Only A side channel is converted.
 *  0b01..Single-Ended Mode. Only B side channel is converted.
 *  0b10..Differential Mode. A-B.
 *  0b11..Dual-Single-Ended Mode. Both A side and B side channels are converted independently.
 */
#define DADC_CMD_CTYPE(x)                        (((uint32_t)(((uint32_t)(x)) << DADC_CMD_CTYPE_SHIFT)) & DADC_CMD_CTYPE_MASK)

#define DADC_CMD_MODE_MASK                       (0x40U)
#define DADC_CMD_MODE_SHIFT                      (6U)
/*! MODE - Select Resolution of Conversions
 *  0b0..Standard resolution. Single-ended 12-bit conversion or differential 13-bit conversion with 2's complement output.
 *  0b1..High resolution. Single-ended 16-bit conversion or differential 16-bit conversion with 2's complement output.
 */
#define DADC_CMD_MODE(x)                         (((uint32_t)(((uint32_t)(x)) << DADC_CMD_MODE_SHIFT)) & DADC_CMD_MODE_MASK)

#define DADC_CMD_CDIS_MASK                       (0x80U)
#define DADC_CMD_CDIS_SHIFT                      (7U)
/*! CDIS - Command Disable
 *  0b0..Enable current command buffer register, the conversion sequence will continue.
 *  0b1..Disable current command buffer. the conversion sequence is ended when previous command buffer is executed.
 */
#define DADC_CMD_CDIS(x)                         (((uint32_t)(((uint32_t)(x)) << DADC_CMD_CDIS_SHIFT)) & DADC_CMD_CDIS_MASK)

#define DADC_CMD_STS_MASK                        (0x700U)
#define DADC_CMD_STS_SHIFT                       (8U)
/*! STS - Sample Time Select
 *  0b000..Minimum sample time of 3.5 ADCK cycles.
 *  0b001..3.5 + 2 1 ADCK cycles; 5.5 ADCK cycles total sample time.
 *  0b010..3.5 + 2 2 ADCK cycles; 7.5 ADCK cycles total sample time.
 *  0b011..3.5 + 2 3 ADCK cycles; 11.5 ADCK cycles total sample time.
 *  0b100..3.5 + 2 4 ADCK cycles; 19.5 ADCK cycles total sample time.
 *  0b101..3.5 + 2 5 ADCK cycles; 35.5 ADCK cycles total sample time.
 *  0b110..3.5 + 2 6 ADCK cycles; 67.5 ADCK cycles total sample time.
 *  0b111..3.5 + 2 7 ADCK cycles; 131.5 ADCK cycles total sample time.
 */
#define DADC_CMD_STS(x)                          (((uint32_t)(((uint32_t)(x)) << DADC_CMD_STS_SHIFT)) & DADC_CMD_STS_MASK)

#define DADC_CMD_AVGS_MASK                       (0xF000U)
#define DADC_CMD_AVGS_SHIFT                      (12U)
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
 *  0b1010-0b1111..1024 conversions averaged.
 */
#define DADC_CMD_AVGS(x)                         (((uint32_t)(((uint32_t)(x)) << DADC_CMD_AVGS_SHIFT)) & DADC_CMD_AVGS_MASK)

#define DADC_CMD_ADCH_MASK                       (0x1F0000U)
#define DADC_CMD_ADCH_SHIFT                      (16U)
/*! ADCH - Input Channel Select
 *  0b00000..Select CH0A or CH0B or CH0A/CH0B pair.
 *  0b00001..Select CH1A or CH1B or CH1A/CH1B pair.
 *  0b00010..Select CH2A or CH2B or CH2A/CH2B pair.
 *  0b00011..Select CH3A or CH3B or CH3A/CH3B pair.
 *  0b00100-0b11101..Select corresponding channel CHnA or CHnB or CHnA/CHnB pair.
 *  0b11110..Select CH30A or CH30B or CH30A/CH30B pair.
 *  0b11111..Select CH31A or CH31B or CH31A/CH31B pair.
 */
#define DADC_CMD_ADCH(x)                         (((uint32_t)(((uint32_t)(x)) << DADC_CMD_ADCH_SHIFT)) & DADC_CMD_ADCH_MASK)

#define DADC_CMD_ALTB_ADCH_MASK                  (0x1F000000U)
#define DADC_CMD_ALTB_ADCH_SHIFT                 (24U)
/*! ALTB_ADCH - Alternate Channel B Input channel select
 *  0b00000..Select CH0B
 *  0b00001..Select CH1B
 *  0b00010..Select CH2B
 *  0b00011..Select CH3B
 *  0b00100-0b11101..Select corresponding channel CHnB
 *  0b11110..Select CH30B
 *  0b11111..Select CH31B
 */
#define DADC_CMD_ALTB_ADCH(x)                    (((uint32_t)(((uint32_t)(x)) << DADC_CMD_ALTB_ADCH_SHIFT)) & DADC_CMD_ALTB_ADCH_MASK)

#define DADC_CMD_ALTB_EN_MASK                    (0x80000000U)
#define DADC_CMD_ALTB_EN_SHIFT                   (31U)
/*! ALTB_EN - Alternate Channel B Select Enable
 *  0b0..ALTB_ADCH disabled. Channel A and Channel B inputs are selected based on ADCH settings.
 *  0b1..ALTB_ADCH enabled. Channel A inputs selected by ADCH setting and Channel B inputs selected by ALTB_ADCH setting.
 */
#define DADC_CMD_ALTB_EN(x)                      (((uint32_t)(((uint32_t)(x)) << DADC_CMD_ALTB_EN_SHIFT)) & DADC_CMD_ALTB_EN_MASK)
/*! @} */

/*! @name CV - Compare Value Register */
/*! @{ */

#define DADC_CV_CVL_MASK                         (0xFFFFU)
#define DADC_CV_CVL_SHIFT                        (0U)
/*! CVL - Compare Value Low */
#define DADC_CV_CVL(x)                           (((uint32_t)(((uint32_t)(x)) << DADC_CV_CVL_SHIFT)) & DADC_CV_CVL_MASK)

#define DADC_CV_CVH_MASK                         (0xFFFF0000U)
#define DADC_CV_CVH_SHIFT                        (16U)
/*! CVH - Compare Value High */
#define DADC_CV_CVH(x)                           (((uint32_t)(((uint32_t)(x)) << DADC_CV_CVH_SHIFT)) & DADC_CV_CVH_MASK)
/*! @} */

/*! @name STAT0 - Status 0 Register */
/*! @{ */

#define DADC_STAT0_CAL_RDY_MASK                  (0x1U)
#define DADC_STAT0_CAL_RDY_SHIFT                 (0U)
/*! CAL_RDY - Status of Calibration Ready
 *  0b0..Calibration is incomplete or hasn't been ran.
 *  0b1..Calibrated is complete.
 */
#define DADC_STAT0_CAL_RDY(x)                    (((uint32_t)(((uint32_t)(x)) << DADC_STAT0_CAL_RDY_SHIFT)) & DADC_STAT0_CAL_RDY_MASK)

#define DADC_STAT0_ADC_ACTIVEA_MASK              (0x2U)
#define DADC_STAT0_ADC_ACTIVEA_SHIFT             (1U)
/*! ADC_ACTIVEA - ADC Active for ADCA
 *  0b0..The DUALADC is IDLE.
 *  0b1..The DUALADC is processing a conversion, running through the power up delay, or servicing a trigger.
 */
#define DADC_STAT0_ADC_ACTIVEA(x)                (((uint32_t)(((uint32_t)(x)) << DADC_STAT0_ADC_ACTIVEA_SHIFT)) & DADC_STAT0_ADC_ACTIVEA_MASK)

#define DADC_STAT0_CMDACTA_MASK                  (0x7CU)
#define DADC_STAT0_CMDACTA_SHIFT                 (2U)
/*! CMDACTA - Command Active for ADCA
 *  0b00000..No command is currently in progress.
 *  0b00001..Command 1 currently being executed.
 *  0b00010..Command 2 currently being executed.
 *  0b00011-0b10100..Associated command number is currently being executed.
 */
#define DADC_STAT0_CMDACTA(x)                    (((uint32_t)(((uint32_t)(x)) << DADC_STAT0_CMDACTA_SHIFT)) & DADC_STAT0_CMDACTA_MASK)

#define DADC_STAT0_AVGTSTSA_MASK                 (0xFF80U)
#define DADC_STAT0_AVGTSTSA_SHIFT                (7U)
/*! AVGTSTSA - Status of "Average with Timer" for ADCA */
#define DADC_STAT0_AVGTSTSA(x)                   (((uint32_t)(((uint32_t)(x)) << DADC_STAT0_AVGTSTSA_SHIFT)) & DADC_STAT0_AVGTSTSA_MASK)

#define DADC_STAT0_ADC_ACTIVEB_MASK              (0x20000U)
#define DADC_STAT0_ADC_ACTIVEB_SHIFT             (17U)
/*! ADC_ACTIVEB - ADCB Active
 *  0b0..The ADCB is IDLE.
 *  0b1..The ADCB is processing a conversion, running through the power up delay, or servicing a trigger.
 */
#define DADC_STAT0_ADC_ACTIVEB(x)                (((uint32_t)(((uint32_t)(x)) << DADC_STAT0_ADC_ACTIVEB_SHIFT)) & DADC_STAT0_ADC_ACTIVEB_MASK)

#define DADC_STAT0_CMDACTB_MASK                  (0x7C0000U)
#define DADC_STAT0_CMDACTB_SHIFT                 (18U)
/*! CMDACTB - Command Active for ADCB
 *  0b00000..No command is currently in progress.
 *  0b01011..Command 11 currently being executed.
 *  0b01100..Command 12 currently being executed.
 *  0b01101-0b10100..Associated command number is currently being executed.
 */
#define DADC_STAT0_CMDACTB(x)                    (((uint32_t)(((uint32_t)(x)) << DADC_STAT0_CMDACTB_SHIFT)) & DADC_STAT0_CMDACTB_MASK)

#define DADC_STAT0_AVGTSTSB_MASK                 (0xFF800000U)
#define DADC_STAT0_AVGTSTSB_SHIFT                (23U)
/*! AVGTSTSB - Status of "Average with Timer" for ADCB */
#define DADC_STAT0_AVGTSTSB(x)                   (((uint32_t)(((uint32_t)(x)) << DADC_STAT0_AVGTSTSB_SHIFT)) & DADC_STAT0_AVGTSTSB_MASK)
/*! @} */

/*! @name CMP_STAT - Compare Status Register */
/*! @{ */

#define DADC_CMP_STAT_CMPIn_MASK                 (0xFFFFFU)
#define DADC_CMP_STAT_CMPIn_SHIFT                (0U)
/*! CMPIn - Compare Interrupt Status
 *  0b00000000000000000000..All compare results are false.
 *  0b00000000000000000001..Compare result of CMD1 is true.
 *  0b00000000000000000010..Compare result of CMD2 is true.
 *  0b00000000000000000100-0b00100000000000000000..Compare result of CMDn is true, where n=3...19.
 *  0b01000000000000000000..Compare result of CMD20 is true.
 */
#define DADC_CMP_STAT_CMPIn(x)                   (((uint32_t)(((uint32_t)(x)) << DADC_CMP_STAT_CMPIn_SHIFT)) & DADC_CMP_STAT_CMPIn_MASK)
/*! @} */

/*! @name RSLTRDY_STAT - Result Ready Status Register */
/*! @{ */

#define DADC_RSLTRDY_STAT_RDYn_MASK              (0xFFFFFU)
#define DADC_RSLTRDY_STAT_RDYn_SHIFT             (0U)
/*! RDYn - Result Ready Status
 *  0b00000000000000000000..Corresponding bit indicates the result is not ready or has been read.
 *  0b00000000000000000001..The result of CMD1 is ready to be read from RSLT1 register. Clear this bit by reading the corresponding RSLT1 register.
 *  0b00000000000000000010..The result of CMD2 is ready to be read from RSLT2 register. Clear this bit by reading the corresponding RSLT2 register.
 *  0b00000000000000000100-0b00100000000000000000..The result of CMDn is ready to be read from RSLTn register. Clear this bit by reading the corresponding RSLTn register.where n=3...19.
 *  0b01000000000000000000..The result of CMD20 is ready to be read from RSLT20 register. Clear this bit by reading the corresponding RSLT20 register.
 */
#define DADC_RSLTRDY_STAT_RDYn(x)                (((uint32_t)(((uint32_t)(x)) << DADC_RSLTRDY_STAT_RDYn_SHIFT)) & DADC_RSLTRDY_STAT_RDYn_MASK)
/*! @} */

/*! @name STAT1 - Status 1 Register */
/*! @{ */

#define DADC_STAT1_OVERLAP_CMDA_MASK             (0x1FU)
#define DADC_STAT1_OVERLAP_CMDA_SHIFT            (0U)
/*! OVERLAP_CMDA - Overlap Command for ADCA */
#define DADC_STAT1_OVERLAP_CMDA(x)               (((uint32_t)(((uint32_t)(x)) << DADC_STAT1_OVERLAP_CMDA_SHIFT)) & DADC_STAT1_OVERLAP_CMDA_MASK)

#define DADC_STAT1_OVERLAP_FLAGA_MASK            (0x80U)
#define DADC_STAT1_OVERLAP_FLAGA_SHIFT           (7U)
/*! OVERLAP_FLAGA - Overlap Interrupt Flag for ADCA
 *  0b0..No trigger occurs on Trigger0 while the corresponding conversion process is ongoing.
 *  0b1..A trigger occurs on Trigger0 while the corresponding conversion process is ongoing. This trigger is
 *       ignored. Clear this bit by writing 1 to it.
 */
#define DADC_STAT1_OVERLAP_FLAGA(x)              (((uint32_t)(((uint32_t)(x)) << DADC_STAT1_OVERLAP_FLAGA_SHIFT)) & DADC_STAT1_OVERLAP_FLAGA_MASK)

#define DADC_STAT1_INTVTIMEERR_CMDA_MASK         (0x1F00U)
#define DADC_STAT1_INTVTIMEERR_CMDA_SHIFT        (8U)
/*! INTVTIMEERR_CMDA - Interval Time Configuration Error Command for ADCA */
#define DADC_STAT1_INTVTIMEERR_CMDA(x)           (((uint32_t)(((uint32_t)(x)) << DADC_STAT1_INTVTIMEERR_CMDA_SHIFT)) & DADC_STAT1_INTVTIMEERR_CMDA_MASK)

#define DADC_STAT1_INTVTIMEERR_FLAGA_MASK        (0x8000U)
#define DADC_STAT1_INTVTIMEERR_FLAGA_SHIFT       (15U)
/*! INTVTIMEERR_FLAGA - Interval Time Error Interrupt Flag for ADCA
 *  0b0..A interval time configuration error doesn't occur in ADCA "Average with timer" session in independence
 *       mode, or an interval time configuration error doesn't occur in an "Average with timer" session in
 *       cooperation mode.
 *  0b1..A interval time configuration error occur in ADCA "Average with timer" session in independence mode, or
 *       an interval time configuration error occurs in an "Average with timer" session in cooperation mode. Clear
 *       this bit by writing 1 to it.
 */
#define DADC_STAT1_INTVTIMEERR_FLAGA(x)          (((uint32_t)(((uint32_t)(x)) << DADC_STAT1_INTVTIMEERR_FLAGA_SHIFT)) & DADC_STAT1_INTVTIMEERR_FLAGA_MASK)

#define DADC_STAT1_OVERLAP_CMDB_MASK             (0x1F0000U)
#define DADC_STAT1_OVERLAP_CMDB_SHIFT            (16U)
/*! OVERLAP_CMDB - Overlap Command for ADCB */
#define DADC_STAT1_OVERLAP_CMDB(x)               (((uint32_t)(((uint32_t)(x)) << DADC_STAT1_OVERLAP_CMDB_SHIFT)) & DADC_STAT1_OVERLAP_CMDB_MASK)

#define DADC_STAT1_OVERLAP_FLAGB_MASK            (0x800000U)
#define DADC_STAT1_OVERLAP_FLAGB_SHIFT           (23U)
/*! OVERLAP_FLAGB - Overlap Interrupt Statuse for ADCB
 *  0b0..No trigger occurs on Trigger1 while the corresponding conversion process is ongoing.
 *  0b1..A trigger occurs for on Trigger1 while the corresponding conversion process is ongoing. This trigger is
 *       ignored. Clear this bit by writing 1 to it.
 */
#define DADC_STAT1_OVERLAP_FLAGB(x)              (((uint32_t)(((uint32_t)(x)) << DADC_STAT1_OVERLAP_FLAGB_SHIFT)) & DADC_STAT1_OVERLAP_FLAGB_MASK)

#define DADC_STAT1_INTVTIMEERR_CMDB_MASK         (0x1F000000U)
#define DADC_STAT1_INTVTIMEERR_CMDB_SHIFT        (24U)
/*! INTVTIMEERR_CMDB - Interval Time Configuration Error Command for ADCB */
#define DADC_STAT1_INTVTIMEERR_CMDB(x)           (((uint32_t)(((uint32_t)(x)) << DADC_STAT1_INTVTIMEERR_CMDB_SHIFT)) & DADC_STAT1_INTVTIMEERR_CMDB_MASK)

#define DADC_STAT1_INTVTIMEERR_FLAGB_MASK        (0x80000000U)
#define DADC_STAT1_INTVTIMEERR_FLAGB_SHIFT       (31U)
/*! INTVTIMEERR_FLAGB - Interval Time Error Interrupt Flag for ADCB
 *  0b0..A interval time configuration error doesn't occour in ADCB "Average with timer" session.
 *  0b1..A interval time configuration error occours in ADCB "Average with timer" session. Clear this bit by writing 1 to it.
 */
#define DADC_STAT1_INTVTIMEERR_FLAGB(x)          (((uint32_t)(((uint32_t)(x)) << DADC_STAT1_INTVTIMEERR_FLAGB_SHIFT)) & DADC_STAT1_INTVTIMEERR_FLAGB_MASK)
/*! @} */

/*! @name STAT2 - Status 2 Register */
/*! @{ */

#define DADC_STAT2_EOSIA_MASK                    (0x1U)
#define DADC_STAT2_EOSIA_SHIFT                   (0U)
/*! EOSIA - End of Scan Interrupt for ADCA
 *  0b0..No end of conversion scan interrupt pending.
 *  0b1..End of conversion scan interrupt pending. Clear this bit by writing 1 to it.
 */
#define DADC_STAT2_EOSIA(x)                      (((uint32_t)(((uint32_t)(x)) << DADC_STAT2_EOSIA_SHIFT)) & DADC_STAT2_EOSIA_MASK)

#define DADC_STAT2_STARTUPSTSB_MASK              (0x8000U)
#define DADC_STAT2_STARTUPSTSB_SHIFT             (15U)
/*! STARTUPSTSB - ADC Startup Status for ADCB
 *  0b0..ADC hasn't startup completed.
 *  0b1..ADC startup completed.
 */
#define DADC_STAT2_STARTUPSTSB(x)                (((uint32_t)(((uint32_t)(x)) << DADC_STAT2_STARTUPSTSB_SHIFT)) & DADC_STAT2_STARTUPSTSB_MASK)

#define DADC_STAT2_EOSIB_MASK                    (0x10000U)
#define DADC_STAT2_EOSIB_SHIFT                   (16U)
/*! EOSIB - End of Scan Interrupt for ADCB
 *  0b0..No end of conversion scan interrupt pending.
 *  0b1..End of conversion scan interrupt pending.Clear this bit by writing 1 to it.
 */
#define DADC_STAT2_EOSIB(x)                      (((uint32_t)(((uint32_t)(x)) << DADC_STAT2_EOSIB_SHIFT)) & DADC_STAT2_EOSIB_MASK)

#define DADC_STAT2_STARTUPSTSA_MASK              (0x80000000U)
#define DADC_STAT2_STARTUPSTSA_SHIFT             (31U)
/*! STARTUPSTSA - ADC Startup Status for ADCA
 *  0b0..ADC hasn't startup completed.
 *  0b1..ADC startup completed.
 */
#define DADC_STAT2_STARTUPSTSA(x)                (((uint32_t)(((uint32_t)(x)) << DADC_STAT2_STARTUPSTSA_SHIFT)) & DADC_STAT2_STARTUPSTSA_MASK)
/*! @} */

/*! @name RSLT_H - Digital Result of the Conversion (Higher 16-Bit) */
/*! @{ */

#define DADC_RSLT_H_RSLT_H_MASK                  (0xFFFFU)
#define DADC_RSLT_H_RSLT_H_SHIFT                 (0U)
/*! RSLT_H - Digital Result of the Conversion (Higher 16-Bit) */
#define DADC_RSLT_H_RSLT_H(x)                    (((uint16_t)(((uint16_t)(x)) << DADC_RSLT_H_RSLT_H_SHIFT)) & DADC_RSLT_H_RSLT_H_MASK)
/*! @} */

/* The count of DADC_RSLT_H */
#define DADC_RSLT_H_COUNT                        (20U)

/*! @name RSLT_L - Digital Result of the Conversion (Lower 16-Bit) */
/*! @{ */

#define DADC_RSLT_L_RSLT_L_MASK                  (0xFFFFU)
#define DADC_RSLT_L_RSLT_L_SHIFT                 (0U)
/*! RSLT_L - Digital Result of the Conversion (Lower 16-Bit) */
#define DADC_RSLT_L_RSLT_L(x)                    (((uint16_t)(((uint16_t)(x)) << DADC_RSLT_L_RSLT_L_SHIFT)) & DADC_RSLT_L_RSLT_L_MASK)
/*! @} */

/* The count of DADC_RSLT_L */
#define DADC_RSLT_L_COUNT                        (20U)

/*! @name RSLT - Digital Result of the Conversion */
/*! @{ */

#define DADC_RSLT_RSLT_MASK                      (0xFFFFFFFFU)
#define DADC_RSLT_RSLT_SHIFT                     (0U)
/*! RSLT - Digital Result of the Conversion */
#define DADC_RSLT_RSLT(x)                        (((uint32_t)(((uint32_t)(x)) << DADC_RSLT_RSLT_SHIFT)) & DADC_RSLT_RSLT_MASK)
/*! @} */

/* The count of DADC_RSLT */
#define DADC_RSLT_COUNT                          (20U)

/*! @name OFSTRIM - Offset Trim Register */
/*! @{ */

#define DADC_OFSTRIM_OFSTRIMA_MASK               (0x3FFU)
#define DADC_OFSTRIM_OFSTRIMA_SHIFT              (0U)
/*! OFSTRIMA - Trim for Offset for ADCA */
#define DADC_OFSTRIM_OFSTRIMA(x)                 (((uint32_t)(((uint32_t)(x)) << DADC_OFSTRIM_OFSTRIMA_SHIFT)) & DADC_OFSTRIM_OFSTRIMA_MASK)

#define DADC_OFSTRIM_OFSTRIMB_MASK               (0x3FF0000U)
#define DADC_OFSTRIM_OFSTRIMB_SHIFT              (16U)
/*! OFSTRIMB - Trim for Offset for ADCB */
#define DADC_OFSTRIM_OFSTRIMB(x)                 (((uint32_t)(((uint32_t)(x)) << DADC_OFSTRIM_OFSTRIMB_SHIFT)) & DADC_OFSTRIM_OFSTRIMB_MASK)
/*! @} */

/*! @name HSTRIM - High Speed Trim Register */
/*! @{ */

#define DADC_HSTRIM_HSTRIMA_MASK                 (0x1FU)
#define DADC_HSTRIM_HSTRIMA_SHIFT                (0U)
/*! HSTRIMA - Trim for High Speed ADCA */
#define DADC_HSTRIM_HSTRIMA(x)                   (((uint32_t)(((uint32_t)(x)) << DADC_HSTRIM_HSTRIMA_SHIFT)) & DADC_HSTRIM_HSTRIMA_MASK)

#define DADC_HSTRIM_HSTRIMB_MASK                 (0x1F0000U)
#define DADC_HSTRIM_HSTRIMB_SHIFT                (16U)
/*! HSTRIMB - Trim for High Speed ADCB */
#define DADC_HSTRIM_HSTRIMB(x)                   (((uint32_t)(((uint32_t)(x)) << DADC_HSTRIM_HSTRIMB_SHIFT)) & DADC_HSTRIM_HSTRIMB_MASK)
/*! @} */

/*! @name GCC - Gain Calibration Control */
/*! @{ */

#define DADC_GCC_GAIN_CAL_MASK                   (0x1FFFFU)
#define DADC_GCC_GAIN_CAL_SHIFT                  (0U)
/*! GAIN_CAL - Gain Calibration Value */
#define DADC_GCC_GAIN_CAL(x)                     (((uint32_t)(((uint32_t)(x)) << DADC_GCC_GAIN_CAL_SHIFT)) & DADC_GCC_GAIN_CAL_MASK)

#define DADC_GCC_RDY_MASK                        (0x1000000U)
#define DADC_GCC_RDY_SHIFT                       (24U)
/*! RDY - Gain Calibration Value Valid
 *  0b0..The GAIN_CAL value is invalid. Run the hardware calibration routine for this value to be set.
 *  0b1..The GAIN_CAL value is valid. GAIN_CAL should be used by software to derive GCRa[GCALR].
 */
#define DADC_GCC_RDY(x)                          (((uint32_t)(((uint32_t)(x)) << DADC_GCC_RDY_SHIFT)) & DADC_GCC_RDY_MASK)
/*! @} */

/*! @name GCR - Gain Calculation Result */
/*! @{ */

#define DADC_GCR_GCALR_MASK                      (0x1FFFFU)
#define DADC_GCR_GCALR_SHIFT                     (0U)
/*! GCALR - Gain Calculation Result */
#define DADC_GCR_GCALR(x)                        (((uint32_t)(((uint32_t)(x)) << DADC_GCR_GCALR_SHIFT)) & DADC_GCR_GCALR_MASK)

#define DADC_GCR_RDY_MASK                        (0x1000000U)
#define DADC_GCR_RDY_SHIFT                       (24U)
/*! RDY - Gain Calculation Ready
 *  0b0..The GCALR value is invalid.
 *  0b1..The GCALR value is valid.
 */
#define DADC_GCR_RDY(x)                          (((uint32_t)(((uint32_t)(x)) << DADC_GCR_RDY_SHIFT)) & DADC_GCR_RDY_MASK)
/*! @} */

/*! @name CAL_GAR - Calibration A-side Registers */
/*! @{ */

#define DADC_CAL_GAR_CAL_GAR_VAL_MASK            (0xFFFFU)
#define DADC_CAL_GAR_CAL_GAR_VAL_SHIFT           (0U)
/*! CAL_GAR_VAL - Calibration General ADCA Register Element */
#define DADC_CAL_GAR_CAL_GAR_VAL(x)              (((uint32_t)(((uint32_t)(x)) << DADC_CAL_GAR_CAL_GAR_VAL_SHIFT)) & DADC_CAL_GAR_CAL_GAR_VAL_MASK)
/*! @} */

/*! @name CAL_GBR - Calibration B-side Registers */
/*! @{ */

#define DADC_CAL_GBR_CAL_GBR_VAL_MASK            (0xFFFFU)
#define DADC_CAL_GBR_CAL_GBR_VAL_SHIFT           (0U)
/*! CAL_GBR_VAL - Calibration General ADCB Register Element */
#define DADC_CAL_GBR_CAL_GBR_VAL(x)              (((uint32_t)(((uint32_t)(x)) << DADC_CAL_GBR_CAL_GBR_VAL_SHIFT)) & DADC_CAL_GBR_CAL_GBR_VAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DADC_Register_Masks */


/*!
 * @}
 */ /* end of group DADC_Peripheral_Access_Layer */


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


#endif  /* PERI_DADC_H_ */

