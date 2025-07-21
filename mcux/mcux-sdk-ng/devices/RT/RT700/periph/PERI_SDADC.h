/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SDADC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SDADC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SDADC
 *
 * CMSIS Peripheral Access Layer for SDADC
 */

#if !defined(PERI_SDADC_H_)
#define PERI_SDADC_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
   -- SDADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDADC_Peripheral_Access_Layer SDADC Peripheral Access Layer
 * @{
 */

/** SDADC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __IO uint32_t ADC_CTL_0;                         /**< ADC Control 0, offset: 0x4 */
  __IO uint32_t ADC_CTL_1;                         /**< ADC Control 1, offset: 0x8 */
  __IO uint32_t ADC_CTL_2;                         /**< ADC Control 2, offset: 0xC */
  __IO uint32_t LDO_CTL;                           /**< LDO Control, offset: 0x10 */
  __IO uint32_t REF_CTL;                           /**< Reference Control, offset: 0x14 */
       uint8_t RESERVED_0[4];
  __IO uint32_t DECIMATOR_CTL_0;                   /**< Decimator Control 0, offset: 0x1C */
  __IO uint32_t DECIMATOR_CTL_1;                   /**< Decimator Control 1, offset: 0x20 */
  __IO uint32_t DECIMATOR_CTL_2;                   /**< Decimator Control 2, offset: 0x24 */
  __IO uint32_t DECIMATOR_CTL_3;                   /**< Decimator Control 3, offset: 0x28 */
  __IO uint32_t DECIMATOR_CTL_4;                   /**< Decimator Control 4, offset: 0x2C */
  __IO uint32_t DC_LOOP_CTL_0;                     /**< DC Loop Control 0, offset: 0x30 */
  __IO uint32_t DC_LOOP_CTL_1;                     /**< DC Loop Control 1, offset: 0x34 */
  __IO uint32_t FIFO_WR_RD_CTL;                    /**< FIFO Write Read Control, offset: 0x38 */
  __IO uint32_t FIFO_WATERMARK_CTL;                /**< FIFO Watermark Control, offset: 0x3C */
  __IO uint32_t FIFO_WATERMARK_ERROR_CTL;          /**< FIFO Watermark Error Control, offset: 0x40 */
  __I  uint32_t FIFO_WATERMARK_ERROR_ST;           /**< FIFO Watermark Error Status, offset: 0x44 */
  __I  uint32_t FIFO_0_P;                          /**< FIFO 0 P, offset: 0x48 */
  __I  uint32_t FIFO_0_N;                          /**< FIFO 0 N, offset: 0x4C */
  __I  uint32_t FIFO_1_P;                          /**< FIFO 1 P, offset: 0x50 */
  __I  uint32_t FIFO_1_N;                          /**< FIFO 1 N, offset: 0x54 */
  __I  uint32_t FIFO_2_P;                          /**< FIFO 2 P, offset: 0x58 */
  __I  uint32_t FIFO_2_N;                          /**< FIFO 2 N, offset: 0x5C */
  __I  uint32_t FIFO_3_P;                          /**< FIFO 3 P, offset: 0x60 */
  __I  uint32_t FIFO_3_N;                          /**< FIFO 3 N, offset: 0x64 */
       uint8_t RESERVED_1[4];
  __I  uint32_t FIFO_ENTRIES_AVAIL_0;              /**< FIFO Entries Availability 0, offset: 0x6C */
  __I  uint32_t FIFO_ENTRIES_AVAIL_1;              /**< FIFO Entries Availability 1, offset: 0x70 */
  __IO uint32_t FIFO_INTERRUPT;                    /**< FIFO Interrupt, offset: 0x74 */
} SDADC_Type;

/* ----------------------------------------------------------------------------
   -- SDADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDADC_Register_Masks SDADC Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define SDADC_VERID_MINOR_MASK                   (0xFF0000U)
#define SDADC_VERID_MINOR_SHIFT                  (16U)
/*! MINOR - Minor Version Number */
#define SDADC_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << SDADC_VERID_MINOR_SHIFT)) & SDADC_VERID_MINOR_MASK)

#define SDADC_VERID_MAJOR_MASK                   (0xFF000000U)
#define SDADC_VERID_MAJOR_SHIFT                  (24U)
/*! MAJOR - Major Version Number */
#define SDADC_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << SDADC_VERID_MAJOR_SHIFT)) & SDADC_VERID_MAJOR_MASK)
/*! @} */

/*! @name ADC_CTL_0 - ADC Control 0 */
/*! @{ */

#define SDADC_ADC_CTL_0_COMP_ADCN_ENABLE_MASK    (0xFU)
#define SDADC_ADC_CTL_0_COMP_ADCN_ENABLE_SHIFT   (0U)
/*! COMP_ADCN_ENABLE - Compensation ADCn Enable
 *  0b0xxx..Disables for ADCn[3]
 *  0b1xxx..Enables for ADCn[3]
 *  0bx0xx..Disables for ADCn[2]
 *  0bx1xx..Enables for ADCn[2]
 *  0bxx0x..Disables for ADCn[1]
 *  0bxx1x..Enables for ADCn[1]
 *  0bxxx0..Disables for ADCn[0]
 *  0bxxx1..Enables for ADCn[0]
 */
#define SDADC_ADC_CTL_0_COMP_ADCN_ENABLE(x)      (((uint32_t)(((uint32_t)(x)) << SDADC_ADC_CTL_0_COMP_ADCN_ENABLE_SHIFT)) & SDADC_ADC_CTL_0_COMP_ADCN_ENABLE_MASK)

#define SDADC_ADC_CTL_0_COMP_ADCP_ENABLE_MASK    (0xF0U)
#define SDADC_ADC_CTL_0_COMP_ADCP_ENABLE_SHIFT   (4U)
/*! COMP_ADCP_ENABLE - Compensation ADCp Enable
 *  0b0xxx..Disables for ADCp[3]
 *  0b1xxx..Enables for ADCp[3]
 *  0bx0xx..Disables for ADCp[2]
 *  0bx1xx..Enables for ADCp[2]
 *  0bxx0x..Disables for ADCp[1]
 *  0bxx1x..Enables for ADCp[1]
 *  0bxxx0..Disables for ADCp[0]
 *  0bxxx1..Enables for ADCp[0]
 */
#define SDADC_ADC_CTL_0_COMP_ADCP_ENABLE(x)      (((uint32_t)(((uint32_t)(x)) << SDADC_ADC_CTL_0_COMP_ADCP_ENABLE_SHIFT)) & SDADC_ADC_CTL_0_COMP_ADCP_ENABLE_MASK)

#define SDADC_ADC_CTL_0_RST_AN_ADCN_MASK         (0xF00U)
#define SDADC_ADC_CTL_0_RST_AN_ADCN_SHIFT        (8U)
/*! RST_AN_ADCN - Reset ADCn
 *  0b0xxx..Reset for ADCn[3]
 *  0b1xxx..Operational for ADCn[3]
 *  0bx0xx..Reset for ADCn[2]
 *  0bx1xx..Operational for ADCn[2]
 *  0bxx0x..Reset for ADCn[1]
 *  0bxx1x..Operational for ADCn[1]
 *  0bxxx0..Reset for ADCn[0]
 *  0bxxx1..Operational for ADCn[0]
 */
#define SDADC_ADC_CTL_0_RST_AN_ADCN(x)           (((uint32_t)(((uint32_t)(x)) << SDADC_ADC_CTL_0_RST_AN_ADCN_SHIFT)) & SDADC_ADC_CTL_0_RST_AN_ADCN_MASK)

#define SDADC_ADC_CTL_0_RST_AN_ADCP_MASK         (0xF000U)
#define SDADC_ADC_CTL_0_RST_AN_ADCP_SHIFT        (12U)
/*! RST_AN_ADCP - Reset ADCp
 *  0b0xxx..Reset for ADCp[3]
 *  0b1xxx..Operational for ADCp[3]
 *  0bx0xx..Reset for ADCp[2]
 *  0bx1xx..Operational for ADCp[2]
 *  0bxx0x..Reset for ADCp[1]
 *  0bxx1x..Operational for ADCp[1]
 *  0bxxx0..Reset for ADCp[0]
 *  0bxxx1..Operational for ADCp[0]
 */
#define SDADC_ADC_CTL_0_RST_AN_ADCP(x)           (((uint32_t)(((uint32_t)(x)) << SDADC_ADC_CTL_0_RST_AN_ADCP_SHIFT)) & SDADC_ADC_CTL_0_RST_AN_ADCP_MASK)

#define SDADC_ADC_CTL_0_ADCN_POWER_ENABLE_MASK   (0xF000000U)
#define SDADC_ADC_CTL_0_ADCN_POWER_ENABLE_SHIFT  (24U)
/*! ADCN_POWER_ENABLE - ADCn Power Enable
 *  0b0xxx..Disables ADCn[3] and vin_n[3]
 *  0b1xxx..Enables ADCn[3] and vin_n[3]
 *  0bx0xx..Disables ADCn[2] and vin_n[2]
 *  0bx1xx..Enables ADCn[2] and vin_n[2]
 *  0bxx0x..Disables ADCn[1] and vin_n[1]
 *  0bxx1x..Enables ADCn[1] and vin_n[1]
 *  0bxxx0..Disables ADCn[0] and vin_n[0]
 *  0bxxx1..Enables ADCn[0] and vin_n[0]
 */
#define SDADC_ADC_CTL_0_ADCN_POWER_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << SDADC_ADC_CTL_0_ADCN_POWER_ENABLE_SHIFT)) & SDADC_ADC_CTL_0_ADCN_POWER_ENABLE_MASK)

#define SDADC_ADC_CTL_0_ADCP_POWER_ENABLE_MASK   (0xF0000000U)
#define SDADC_ADC_CTL_0_ADCP_POWER_ENABLE_SHIFT  (28U)
/*! ADCP_POWER_ENABLE - ADCp Power Enable
 *  0b0xxx..Disables ADCp[3] and vin_p[3]
 *  0b1xxx..Enables ADCp[3] and vin_p[3]
 *  0bx0xx..Disables ADCp[2] and vin_p[2]
 *  0bx1xx..Enables ADCp[2] and vin_p[2]
 *  0bxx0x..Disables ADCp[1] and vin_p[1]
 *  0bxx1x..Enables ADCp[1] and vin_p[1]
 *  0bxxx0..Disables ADCp[0] and vin_p[0]
 *  0bxxx1..Enables ADCp[0] and vin_p[0]
 */
#define SDADC_ADC_CTL_0_ADCP_POWER_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << SDADC_ADC_CTL_0_ADCP_POWER_ENABLE_SHIFT)) & SDADC_ADC_CTL_0_ADCP_POWER_ENABLE_MASK)
/*! @} */

/*! @name ADC_CTL_1 - ADC Control 1 */
/*! @{ */

#define SDADC_ADC_CTL_1_DCLOOP_N_ANA_ENABLE_MASK (0xF00U)
#define SDADC_ADC_CTL_1_DCLOOP_N_ANA_ENABLE_SHIFT (8U)
/*! DCLOOP_N_ANA_ENABLE - DC Loop N Analog Enable
 *  0b0xxx..Disables for ADCn[3]
 *  0b1xxx..Enables for ADCn[3]
 *  0bx0xx..Disables for ADCn[2]
 *  0bx1xx..Enables for ADCn[2]
 *  0bxx0x..Disables for ADCn[1]
 *  0bxx1x..Enables for ADCn[1]
 *  0bxxx0..Disables for ADCn[0]
 *  0bxxx1..Enables for ADCn[0]
 */
#define SDADC_ADC_CTL_1_DCLOOP_N_ANA_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << SDADC_ADC_CTL_1_DCLOOP_N_ANA_ENABLE_SHIFT)) & SDADC_ADC_CTL_1_DCLOOP_N_ANA_ENABLE_MASK)

#define SDADC_ADC_CTL_1_DCLOOP_P_ANA_ENABLE_MASK (0xF000U)
#define SDADC_ADC_CTL_1_DCLOOP_P_ANA_ENABLE_SHIFT (12U)
/*! DCLOOP_P_ANA_ENABLE - DC Loop P Analog Enable
 *  0b0xxx..Disables for ADCp[3]
 *  0b1xxx..Enables for ADCp[3]
 *  0bx0xx..Disables for ADCp[2]
 *  0bx1xx..Enables for ADCp[2]
 *  0bxx0x..Disables for ADCp[1]
 *  0bxx1x..Enables for ADCp[1]
 *  0bxxx0..Disables for ADCp[0]
 *  0bxxx1..Enables for ADCp[0]
 */
#define SDADC_ADC_CTL_1_DCLOOP_P_ANA_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << SDADC_ADC_CTL_1_DCLOOP_P_ANA_ENABLE_SHIFT)) & SDADC_ADC_CTL_1_DCLOOP_P_ANA_ENABLE_MASK)

#define SDADC_ADC_CTL_1_DIFF_ENABLE_MASK         (0xF000000U)
#define SDADC_ADC_CTL_1_DIFF_ENABLE_SHIFT        (24U)
/*! DIFF_ENABLE - Diff Enable
 *  0b0xxx..ADCp[3] and ADCn[3] in SE mode
 *  0b1xxx..Configures ADCp[3] and ADCn[3] as differential pair input
 *  0bx0xx..ADCp[2] and ADCn[2] in SE mode
 *  0bx1xx..Configures ADCp[2] and ADCn[2] as differential pair input
 *  0bxx0x..ADCp[1] and ADCn[1] in SE mode
 *  0bxx1x..Configures ADCp[1] and ADCn[1] as differential pair input
 *  0bxxx0..ADCp[0] and ADCn[0] in SE mode
 *  0bxxx1..Configures ADCp[0] and ADCn[0] as differential pair input
 */
#define SDADC_ADC_CTL_1_DIFF_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << SDADC_ADC_CTL_1_DIFF_ENABLE_SHIFT)) & SDADC_ADC_CTL_1_DIFF_ENABLE_MASK)
/*! @} */

/*! @name ADC_CTL_2 - ADC Control 2 */
/*! @{ */

#define SDADC_ADC_CTL_2_SET_DITHER3_MASK         (0x70000U)
#define SDADC_ADC_CTL_2_SET_DITHER3_SHIFT        (16U)
/*! SET_DITHER3 - Set Dither 3
 *  0b000..Disables dither of ADCp[3] and ADCn[3].
 *  0b001-0b110..The higher the value, the stronger the dither
 *  0b111..Maximum dither amplitude for ADCp[3] and ADCn[3]
 */
#define SDADC_ADC_CTL_2_SET_DITHER3(x)           (((uint32_t)(((uint32_t)(x)) << SDADC_ADC_CTL_2_SET_DITHER3_SHIFT)) & SDADC_ADC_CTL_2_SET_DITHER3_MASK)

#define SDADC_ADC_CTL_2_SET_DITHER2_MASK         (0x700000U)
#define SDADC_ADC_CTL_2_SET_DITHER2_SHIFT        (20U)
/*! SET_DITHER2 - Set Dither 2
 *  0b000..Disables dither of ADCp[2] and ADCn[2]
 *  0b001-0b110..The higher the value, the stronger the dither
 *  0b111..Maximum dither amplitude for ADCp[2] and ADCn[2]
 */
#define SDADC_ADC_CTL_2_SET_DITHER2(x)           (((uint32_t)(((uint32_t)(x)) << SDADC_ADC_CTL_2_SET_DITHER2_SHIFT)) & SDADC_ADC_CTL_2_SET_DITHER2_MASK)

#define SDADC_ADC_CTL_2_SET_DITHER1_MASK         (0x7000000U)
#define SDADC_ADC_CTL_2_SET_DITHER1_SHIFT        (24U)
/*! SET_DITHER1 - Set Dither 1
 *  0b000..Disables dither of ADCp[1] and ADCn[1]
 *  0b001-0b110..The higher the value, the stronger the dither
 *  0b111..Maximum dither amplitude for ADCp[1] and ADCn[1]
 */
#define SDADC_ADC_CTL_2_SET_DITHER1(x)           (((uint32_t)(((uint32_t)(x)) << SDADC_ADC_CTL_2_SET_DITHER1_SHIFT)) & SDADC_ADC_CTL_2_SET_DITHER1_MASK)

#define SDADC_ADC_CTL_2_SET_DITHER0_MASK         (0x70000000U)
#define SDADC_ADC_CTL_2_SET_DITHER0_SHIFT        (28U)
/*! SET_DITHER0 - Set Dither 0
 *  0b000..Disables dither of ADCp[0] and ADCn[0]
 *  0b001-0b110..The higher the value, the stronger the dither
 *  0b111..Maximum dither amplitude for ADCp[0] and ADCn[0]
 */
#define SDADC_ADC_CTL_2_SET_DITHER0(x)           (((uint32_t)(((uint32_t)(x)) << SDADC_ADC_CTL_2_SET_DITHER0_SHIFT)) & SDADC_ADC_CTL_2_SET_DITHER0_MASK)
/*! @} */

/*! @name LDO_CTL - LDO Control */
/*! @{ */

#define SDADC_LDO_CTL_LDO_SETTING_MASK           (0x3000U)
#define SDADC_LDO_CTL_LDO_SETTING_SHIFT          (12U)
/*! LDO_SETTING - LDO Setting
 *  0b00..To drive 1 SE or 1 Diff mode ADC (low power mode)
 *  0b01..To drive more than 1 ADCs
 *  0b10, 0b11..Not in use
 */
#define SDADC_LDO_CTL_LDO_SETTING(x)             (((uint32_t)(((uint32_t)(x)) << SDADC_LDO_CTL_LDO_SETTING_SHIFT)) & SDADC_LDO_CTL_LDO_SETTING_MASK)

#define SDADC_LDO_CTL_LDO_POWER_ENABLE_MASK      (0x100000U)
#define SDADC_LDO_CTL_LDO_POWER_ENABLE_SHIFT     (20U)
/*! LDO_POWER_ENABLE - LDO Power Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_LDO_CTL_LDO_POWER_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << SDADC_LDO_CTL_LDO_POWER_ENABLE_SHIFT)) & SDADC_LDO_CTL_LDO_POWER_ENABLE_MASK)
/*! @} */

/*! @name REF_CTL - Reference Control */
/*! @{ */

#define SDADC_REF_CTL_FAST_REF_ENABLE_MASK       (0x10000U)
#define SDADC_REF_CTL_FAST_REF_ENABLE_SHIFT      (16U)
/*! FAST_REF_ENABLE - Fast Reference Enable
 *  0b0..267 ms (retain mode) when bit20=0 | 38 ms (low noise) when bit20=1
 *  0b1..66.5 ms (low power) when bit20=0 | 1 ms (fast charging) when bit20=1
 */
#define SDADC_REF_CTL_FAST_REF_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << SDADC_REF_CTL_FAST_REF_ENABLE_SHIFT)) & SDADC_REF_CTL_FAST_REF_ENABLE_MASK)

#define SDADC_REF_CTL_PWR_FAST_REF_ENABLE_MASK   (0x100000U)
#define SDADC_REF_CTL_PWR_FAST_REF_ENABLE_SHIFT  (20U)
/*! PWR_FAST_REF_ENABLE - Power Fast Reference Enable
 *  0b0..267 ms (retain mode) when bit16=0 | 66.5 ms (low power) when bit16=1
 *  0b1..38 ms (low noise) when bit16=0 | 1 ms (fast charging) when bit16=1
 */
#define SDADC_REF_CTL_PWR_FAST_REF_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << SDADC_REF_CTL_PWR_FAST_REF_ENABLE_SHIFT)) & SDADC_REF_CTL_PWR_FAST_REF_ENABLE_MASK)

#define SDADC_REF_CTL_REF_POWER_ENABLE_MASK      (0x10000000U)
#define SDADC_REF_CTL_REF_POWER_ENABLE_SHIFT     (28U)
/*! REF_POWER_ENABLE - Reference Power Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_REF_CTL_REF_POWER_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << SDADC_REF_CTL_REF_POWER_ENABLE_SHIFT)) & SDADC_REF_CTL_REF_POWER_ENABLE_MASK)
/*! @} */

/*! @name DECIMATOR_CTL_0 - Decimator Control 0 */
/*! @{ */

#define SDADC_DECIMATOR_CTL_0_POL_INV_P_ENABLE_MASK (0xF00U)
#define SDADC_DECIMATOR_CTL_0_POL_INV_P_ENABLE_SHIFT (8U)
/*! POL_INV_P_ENABLE - Polarity Inverter P Enable
 *  0b0xxx..Disables at Decimator_p[3]
 *  0b1xxx..Enables at Decimator_p[3]
 *  0bx0xx..Disables at Decimator_p[2]
 *  0bx1xx..Enables at Decimator_p[2]
 *  0bxx0x..Disables at Decimator_p[1]
 *  0bxx1x..Enables at Decimator_p[1]
 *  0bxxx0..Disables at Decimator_p[0]
 *  0bxxx1..Enables at Decimator_p[0]
 */
#define SDADC_DECIMATOR_CTL_0_POL_INV_P_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_0_POL_INV_P_ENABLE_SHIFT)) & SDADC_DECIMATOR_CTL_0_POL_INV_P_ENABLE_MASK)

#define SDADC_DECIMATOR_CTL_0_POL_INV_N_ENABLE_MASK (0xF000U)
#define SDADC_DECIMATOR_CTL_0_POL_INV_N_ENABLE_SHIFT (12U)
/*! POL_INV_N_ENABLE - Polarity Inverter N Enable
 *  0b0xxx..Disables at Decimator_n[3]
 *  0b1xxx..Enables at Decimator_n[3]
 *  0bx0xx..Disables at Decimator_n[2]
 *  0bx1xx..Enables at Decimator_n[2]
 *  0bxx0x..Disables at Decimator_n[1]
 *  0bxx1x..Enables at Decimator_n[1]
 *  0bxxx0..Disables at Decimator_n[0]
 *  0bxxx1..Enables at Decimator_n[0]
 */
#define SDADC_DECIMATOR_CTL_0_POL_INV_N_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_0_POL_INV_N_ENABLE_SHIFT)) & SDADC_DECIMATOR_CTL_0_POL_INV_N_ENABLE_MASK)

#define SDADC_DECIMATOR_CTL_0_DCFILTI_P_ENABLE_MASK (0xF000000U)
#define SDADC_DECIMATOR_CTL_0_DCFILTI_P_ENABLE_SHIFT (24U)
/*! DCFILTI_P_ENABLE - Decimation Filter Input P Enable
 *  0b0xxx..Disables at Decimator_p[3]
 *  0b1xxx..Enables at Decimator_p[3]
 *  0bx0xx..Disables at Decimator_p[2]
 *  0bx1xx..Enables at Decimator_p[2]
 *  0bxx0x..Disables at Decimator_p[1]
 *  0bxx1x..Enables at Decimator_p[1]
 *  0bxxx0..Disables at Decimator_p[0]
 *  0bxxx1..Enables at Decimator_p[0]
 */
#define SDADC_DECIMATOR_CTL_0_DCFILTI_P_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_0_DCFILTI_P_ENABLE_SHIFT)) & SDADC_DECIMATOR_CTL_0_DCFILTI_P_ENABLE_MASK)

#define SDADC_DECIMATOR_CTL_0_DCFILTI_N_ENABLE_MASK (0xF0000000U)
#define SDADC_DECIMATOR_CTL_0_DCFILTI_N_ENABLE_SHIFT (28U)
/*! DCFILTI_N_ENABLE - Decimation Filter Input N Enable
 *  0b0xxx..Disables at Decimator_n[3]
 *  0b1xxx..Enables at Decimator_n[3]
 *  0bx0xx..Disables at Decimator_n[2]
 *  0bx1xx..Enables at Decimator_n[2]
 *  0bxx0x..Disables at Decimator_n[1]
 *  0bxx1x..Enables at Decimator_n[1]
 *  0bxxx0..Disables at Decimator_n[0]
 *  0bxxx1..Enables at Decimator_n[0]
 */
#define SDADC_DECIMATOR_CTL_0_DCFILTI_N_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_0_DCFILTI_N_ENABLE_SHIFT)) & SDADC_DECIMATOR_CTL_0_DCFILTI_N_ENABLE_MASK)
/*! @} */

/*! @name DECIMATOR_CTL_1 - Decimator Control 1 */
/*! @{ */

#define SDADC_DECIMATOR_CTL_1_FUNC_LOCAL_RST_AN_DEC_P_MASK (0xF00U)
#define SDADC_DECIMATOR_CTL_1_FUNC_LOCAL_RST_AN_DEC_P_SHIFT (8U)
/*! FUNC_LOCAL_RST_AN_DEC_P - Functional Local Reset for Decimator P
 *  0b0xxx..Reset for Decimator_p[3]
 *  0b1xxx..Operational for Decimator_p[3]
 *  0bx0xx..Reset for Decimator_p[2]
 *  0bx1xx..Operational for Decimator_p2]
 *  0bxx0x..Reset for Decimator_p[1]
 *  0bxx1x..Operational for Decimator_p[1]
 *  0bxxx0..Reset for Decimator_p[0]
 *  0bxxx1..Operational for Decimator_p[0]
 */
#define SDADC_DECIMATOR_CTL_1_FUNC_LOCAL_RST_AN_DEC_P(x) (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_1_FUNC_LOCAL_RST_AN_DEC_P_SHIFT)) & SDADC_DECIMATOR_CTL_1_FUNC_LOCAL_RST_AN_DEC_P_MASK)

#define SDADC_DECIMATOR_CTL_1_FUNC_LOCAL_RST_AN_DEC_N_MASK (0xF000U)
#define SDADC_DECIMATOR_CTL_1_FUNC_LOCAL_RST_AN_DEC_N_SHIFT (12U)
/*! FUNC_LOCAL_RST_AN_DEC_N - Functional Local Reset for Decimator N
 *  0b0xxx..Reset for Decimator_n[3]
 *  0b1xxx..Operational for Decimator_n[3]
 *  0bx0xx..Reset for Decimator_n[2]
 *  0bx1xx..Operational for Decimator_n[2]
 *  0bxx0x..Reset for Decimator_n[1]
 *  0bxx1x..Operational for Decimator_n[1]
 *  0bxxx0..Reset for Decimator_n[0]
 *  0bxxx1..Operational for Decimator_n[0]
 */
#define SDADC_DECIMATOR_CTL_1_FUNC_LOCAL_RST_AN_DEC_N(x) (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_1_FUNC_LOCAL_RST_AN_DEC_N_SHIFT)) & SDADC_DECIMATOR_CTL_1_FUNC_LOCAL_RST_AN_DEC_N_MASK)
/*! @} */

/*! @name DECIMATOR_CTL_2 - Decimator Control 2 */
/*! @{ */

#define SDADC_DECIMATOR_CTL_2_VOL_CTRL_P_0_MASK  (0xFFU)
#define SDADC_DECIMATOR_CTL_2_VOL_CTRL_P_0_SHIFT (0U)
/*! VOL_CTRL_P_0 - Volume Control P 0 */
#define SDADC_DECIMATOR_CTL_2_VOL_CTRL_P_0(x)    (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_2_VOL_CTRL_P_0_SHIFT)) & SDADC_DECIMATOR_CTL_2_VOL_CTRL_P_0_MASK)

#define SDADC_DECIMATOR_CTL_2_VOL_CTRL_N_0_MASK  (0xFF00U)
#define SDADC_DECIMATOR_CTL_2_VOL_CTRL_N_0_SHIFT (8U)
/*! VOL_CTRL_N_0 - Volume Control N 0 */
#define SDADC_DECIMATOR_CTL_2_VOL_CTRL_N_0(x)    (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_2_VOL_CTRL_N_0_SHIFT)) & SDADC_DECIMATOR_CTL_2_VOL_CTRL_N_0_MASK)

#define SDADC_DECIMATOR_CTL_2_VOL_CTRL_P_1_MASK  (0xFF0000U)
#define SDADC_DECIMATOR_CTL_2_VOL_CTRL_P_1_SHIFT (16U)
/*! VOL_CTRL_P_1 - Volume Control P 1 */
#define SDADC_DECIMATOR_CTL_2_VOL_CTRL_P_1(x)    (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_2_VOL_CTRL_P_1_SHIFT)) & SDADC_DECIMATOR_CTL_2_VOL_CTRL_P_1_MASK)

#define SDADC_DECIMATOR_CTL_2_VOL_CTRL_N_1_MASK  (0xFF000000U)
#define SDADC_DECIMATOR_CTL_2_VOL_CTRL_N_1_SHIFT (24U)
/*! VOL_CTRL_N_1 - Volume Control N 1 */
#define SDADC_DECIMATOR_CTL_2_VOL_CTRL_N_1(x)    (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_2_VOL_CTRL_N_1_SHIFT)) & SDADC_DECIMATOR_CTL_2_VOL_CTRL_N_1_MASK)
/*! @} */

/*! @name DECIMATOR_CTL_3 - Decimator Control 3 */
/*! @{ */

#define SDADC_DECIMATOR_CTL_3_VOL_CTRL_P_2_MASK  (0xFFU)
#define SDADC_DECIMATOR_CTL_3_VOL_CTRL_P_2_SHIFT (0U)
/*! VOL_CTRL_P_2 - Volume Control P 2 */
#define SDADC_DECIMATOR_CTL_3_VOL_CTRL_P_2(x)    (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_3_VOL_CTRL_P_2_SHIFT)) & SDADC_DECIMATOR_CTL_3_VOL_CTRL_P_2_MASK)

#define SDADC_DECIMATOR_CTL_3_VOL_CTRL_N_2_MASK  (0xFF00U)
#define SDADC_DECIMATOR_CTL_3_VOL_CTRL_N_2_SHIFT (8U)
/*! VOL_CTRL_N_2 - Volume Control N 2 */
#define SDADC_DECIMATOR_CTL_3_VOL_CTRL_N_2(x)    (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_3_VOL_CTRL_N_2_SHIFT)) & SDADC_DECIMATOR_CTL_3_VOL_CTRL_N_2_MASK)

#define SDADC_DECIMATOR_CTL_3_VOL_CTRL_P_3_MASK  (0xFF0000U)
#define SDADC_DECIMATOR_CTL_3_VOL_CTRL_P_3_SHIFT (16U)
/*! VOL_CTRL_P_3 - Volume Control P 3 */
#define SDADC_DECIMATOR_CTL_3_VOL_CTRL_P_3(x)    (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_3_VOL_CTRL_P_3_SHIFT)) & SDADC_DECIMATOR_CTL_3_VOL_CTRL_P_3_MASK)

#define SDADC_DECIMATOR_CTL_3_VOL_CTRL_N_3_MASK  (0xFF000000U)
#define SDADC_DECIMATOR_CTL_3_VOL_CTRL_N_3_SHIFT (24U)
/*! VOL_CTRL_N_3 - Volume Control N 3 */
#define SDADC_DECIMATOR_CTL_3_VOL_CTRL_N_3(x)    (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_3_VOL_CTRL_N_3_SHIFT)) & SDADC_DECIMATOR_CTL_3_VOL_CTRL_N_3_MASK)
/*! @} */

/*! @name DECIMATOR_CTL_4 - Decimator Control 4 */
/*! @{ */

#define SDADC_DECIMATOR_CTL_4_SET_SPEED_P_0_MASK (0x3U)
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_P_0_SHIFT (0U)
/*! SET_SPEED_P_0 - Set Speed P 0
 *  0b00..48 kHz
 *  0b01..32 kHz
 *  0b10..16 kHz
 *  0b11..48 kHz
 */
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_P_0(x)   (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_4_SET_SPEED_P_0_SHIFT)) & SDADC_DECIMATOR_CTL_4_SET_SPEED_P_0_MASK)

#define SDADC_DECIMATOR_CTL_4_SET_SPEED_N_0_MASK (0xCU)
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_N_0_SHIFT (2U)
/*! SET_SPEED_N_0 - Set Speed N 0
 *  0b00..48 kHz
 *  0b01..32 kHz
 *  0b10..16 kHz
 *  0b11..48 kHz
 */
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_N_0(x)   (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_4_SET_SPEED_N_0_SHIFT)) & SDADC_DECIMATOR_CTL_4_SET_SPEED_N_0_MASK)

#define SDADC_DECIMATOR_CTL_4_SET_SPEED_P_1_MASK (0x30U)
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_P_1_SHIFT (4U)
/*! SET_SPEED_P_1 - Set Speed P 1
 *  0b00..48 kHz
 *  0b01..32 kHz
 *  0b10..16 kHz
 *  0b11..48 kHz
 */
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_P_1(x)   (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_4_SET_SPEED_P_1_SHIFT)) & SDADC_DECIMATOR_CTL_4_SET_SPEED_P_1_MASK)

#define SDADC_DECIMATOR_CTL_4_SET_SPEED_N_1_MASK (0xC0U)
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_N_1_SHIFT (6U)
/*! SET_SPEED_N_1 - Set Speed N 1
 *  0b00..48 kHz
 *  0b01..32 kHz
 *  0b10..16 kHz
 *  0b11..48 kHz
 */
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_N_1(x)   (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_4_SET_SPEED_N_1_SHIFT)) & SDADC_DECIMATOR_CTL_4_SET_SPEED_N_1_MASK)

#define SDADC_DECIMATOR_CTL_4_SET_SPEED_P_2_MASK (0x300U)
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_P_2_SHIFT (8U)
/*! SET_SPEED_P_2 - Set Speed P 2
 *  0b00..48 kHz
 *  0b01..32 kHz
 *  0b10..16 kHz
 *  0b11..48 kHz
 */
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_P_2(x)   (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_4_SET_SPEED_P_2_SHIFT)) & SDADC_DECIMATOR_CTL_4_SET_SPEED_P_2_MASK)

#define SDADC_DECIMATOR_CTL_4_SET_SPEED_N_2_MASK (0xC00U)
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_N_2_SHIFT (10U)
/*! SET_SPEED_N_2 - Set Speed N 2
 *  0b00..48 kHz
 *  0b01..32 kHz
 *  0b10..16 kHz
 *  0b11..48 kHz
 */
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_N_2(x)   (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_4_SET_SPEED_N_2_SHIFT)) & SDADC_DECIMATOR_CTL_4_SET_SPEED_N_2_MASK)

#define SDADC_DECIMATOR_CTL_4_SET_SPEED_P_3_MASK (0x3000U)
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_P_3_SHIFT (12U)
/*! SET_SPEED_P_3 - Set Speed P 3
 *  0b00..48 kHz
 *  0b01..32 kHz
 *  0b10..16 kHz
 *  0b11..48 kHz
 */
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_P_3(x)   (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_4_SET_SPEED_P_3_SHIFT)) & SDADC_DECIMATOR_CTL_4_SET_SPEED_P_3_MASK)

#define SDADC_DECIMATOR_CTL_4_SET_SPEED_N_3_MASK (0xC000U)
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_N_3_SHIFT (14U)
/*! SET_SPEED_N_3 - Set Speed N 3
 *  0b00..48 kHz
 *  0b01..32 kHz
 *  0b10..16 kHz
 *  0b11..48 kHz
 */
#define SDADC_DECIMATOR_CTL_4_SET_SPEED_N_3(x)   (((uint32_t)(((uint32_t)(x)) << SDADC_DECIMATOR_CTL_4_SET_SPEED_N_3_SHIFT)) & SDADC_DECIMATOR_CTL_4_SET_SPEED_N_3_MASK)
/*! @} */

/*! @name DC_LOOP_CTL_0 - DC Loop Control 0 */
/*! @{ */

#define SDADC_DC_LOOP_CTL_0_DCLOOP_P_ENABLE_MASK (0xFU)
#define SDADC_DC_LOOP_CTL_0_DCLOOP_P_ENABLE_SHIFT (0U)
/*! DCLOOP_P_ENABLE - DC Loop P Enable
 *  0b0xxx..Disables filter_p[3]
 *  0b1xxx..Enables filter_p[3]
 *  0bx0xx..Disables filter_p[2]
 *  0bx1xx..Enables filter_p[2]
 *  0bxx0x..Disables filter_p[1]
 *  0bxx1x..Enables filter_p[1]
 *  0bxxx0..Disables filter_p[0]
 *  0bxxx1..Enables filter_p[0]
 */
#define SDADC_DC_LOOP_CTL_0_DCLOOP_P_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << SDADC_DC_LOOP_CTL_0_DCLOOP_P_ENABLE_SHIFT)) & SDADC_DC_LOOP_CTL_0_DCLOOP_P_ENABLE_MASK)

#define SDADC_DC_LOOP_CTL_0_DCLOOP_N_ENABLE_MASK (0xF0U)
#define SDADC_DC_LOOP_CTL_0_DCLOOP_N_ENABLE_SHIFT (4U)
/*! DCLOOP_N_ENABLE - DC Loop N Enable
 *  0b0xxx..Disables filter_n[3]
 *  0b1xxx..Enables filter_n[3]
 *  0bx0xx..Disables filter_n[2]
 *  0bx1xx..Enables filter_n[2]
 *  0bxx0x..Disables filter_n[1]
 *  0bxx1x..Enables filter_n[1]
 *  0bxxx0..Disables filter_n[0]
 *  0bxxx1..Enables filter_n[0]
 */
#define SDADC_DC_LOOP_CTL_0_DCLOOP_N_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << SDADC_DC_LOOP_CTL_0_DCLOOP_N_ENABLE_SHIFT)) & SDADC_DC_LOOP_CTL_0_DCLOOP_N_ENABLE_MASK)
/*! @} */

/*! @name DC_LOOP_CTL_1 - DC Loop Control 1 */
/*! @{ */

#define SDADC_DC_LOOP_CTL_1_FUNC_LOCAL_RST_AN_DCLOOP_P_MASK (0xFU)
#define SDADC_DC_LOOP_CTL_1_FUNC_LOCAL_RST_AN_DCLOOP_P_SHIFT (0U)
/*! FUNC_LOCAL_RST_AN_DCLOOP_P - Functional Local Reset DCloop_p
 *  0b0xxx..Reset for ADCp[3]
 *  0b1xxx..Operational for ADCp[3]
 *  0bx0xx..Reset for ADCp[2]
 *  0bx1xx..Operational for ADCp[2]
 *  0bxx0x..Reset for ADCp[1]
 *  0bxx1x..Operational for ADCp[1]
 *  0bxxx0..Reset for ADCp[0]
 *  0bxxx1..Operational for ADCp[0]
 */
#define SDADC_DC_LOOP_CTL_1_FUNC_LOCAL_RST_AN_DCLOOP_P(x) (((uint32_t)(((uint32_t)(x)) << SDADC_DC_LOOP_CTL_1_FUNC_LOCAL_RST_AN_DCLOOP_P_SHIFT)) & SDADC_DC_LOOP_CTL_1_FUNC_LOCAL_RST_AN_DCLOOP_P_MASK)

#define SDADC_DC_LOOP_CTL_1_FUNC_LOCAL_RST_AN_DCLOOP_N_MASK (0xF0U)
#define SDADC_DC_LOOP_CTL_1_FUNC_LOCAL_RST_AN_DCLOOP_N_SHIFT (4U)
/*! FUNC_LOCAL_RST_AN_DCLOOP_N - Functional Local Reset DCloop_n
 *  0b0xxx..Reset for ADCn[3]
 *  0b1xxx..Operational for ADCn[3]
 *  0bx0xx..Reset for ADCn[2]
 *  0bx1xx..Operational for ADCn[2]
 *  0bxx0x..Reset for ADCn[1]
 *  0bxx1x..Operational for ADCn[1]
 *  0bxxx0..Reset for ADCn[0]
 *  0bxxx1..Operational for ADCn[0]
 */
#define SDADC_DC_LOOP_CTL_1_FUNC_LOCAL_RST_AN_DCLOOP_N(x) (((uint32_t)(((uint32_t)(x)) << SDADC_DC_LOOP_CTL_1_FUNC_LOCAL_RST_AN_DCLOOP_N_SHIFT)) & SDADC_DC_LOOP_CTL_1_FUNC_LOCAL_RST_AN_DCLOOP_N_MASK)
/*! @} */

/*! @name FIFO_WR_RD_CTL - FIFO Write Read Control */
/*! @{ */

#define SDADC_FIFO_WR_RD_CTL_WR_0_P_RST_MASK     (0x10000U)
#define SDADC_FIFO_WR_RD_CTL_WR_0_P_RST_SHIFT    (16U)
/*! WR_0_P_RST - Write Reset for FIFO_0_P */
#define SDADC_FIFO_WR_RD_CTL_WR_0_P_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_WR_0_P_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_WR_0_P_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_RD_0_P_RST_MASK     (0x20000U)
#define SDADC_FIFO_WR_RD_CTL_RD_0_P_RST_SHIFT    (17U)
/*! RD_0_P_RST - Read Reset for FIFO_0_P */
#define SDADC_FIFO_WR_RD_CTL_RD_0_P_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_RD_0_P_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_RD_0_P_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_WR_0_N_RST_MASK     (0x40000U)
#define SDADC_FIFO_WR_RD_CTL_WR_0_N_RST_SHIFT    (18U)
/*! WR_0_N_RST - Write Reset for FIFO_0_N */
#define SDADC_FIFO_WR_RD_CTL_WR_0_N_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_WR_0_N_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_WR_0_N_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_RD_0_N_RST_MASK     (0x80000U)
#define SDADC_FIFO_WR_RD_CTL_RD_0_N_RST_SHIFT    (19U)
/*! RD_0_N_RST - Read Reset for FIFO_0_N */
#define SDADC_FIFO_WR_RD_CTL_RD_0_N_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_RD_0_N_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_RD_0_N_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_WR_1_P_RST_MASK     (0x100000U)
#define SDADC_FIFO_WR_RD_CTL_WR_1_P_RST_SHIFT    (20U)
/*! WR_1_P_RST - Write Reset for FIFO_1_P */
#define SDADC_FIFO_WR_RD_CTL_WR_1_P_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_WR_1_P_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_WR_1_P_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_RD_1_P_RST_MASK     (0x200000U)
#define SDADC_FIFO_WR_RD_CTL_RD_1_P_RST_SHIFT    (21U)
/*! RD_1_P_RST - Read Reset for FIFO_1_P */
#define SDADC_FIFO_WR_RD_CTL_RD_1_P_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_RD_1_P_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_RD_1_P_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_WR_1_N_RST_MASK     (0x400000U)
#define SDADC_FIFO_WR_RD_CTL_WR_1_N_RST_SHIFT    (22U)
/*! WR_1_N_RST - Write Reset for FIFO_1_N */
#define SDADC_FIFO_WR_RD_CTL_WR_1_N_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_WR_1_N_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_WR_1_N_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_RD_1_N_RST_MASK     (0x800000U)
#define SDADC_FIFO_WR_RD_CTL_RD_1_N_RST_SHIFT    (23U)
/*! RD_1_N_RST - Read Reset for FIFO_1_N */
#define SDADC_FIFO_WR_RD_CTL_RD_1_N_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_RD_1_N_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_RD_1_N_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_WR_2_P_RST_MASK     (0x1000000U)
#define SDADC_FIFO_WR_RD_CTL_WR_2_P_RST_SHIFT    (24U)
/*! WR_2_P_RST - Write Reset for FIFO_2_P */
#define SDADC_FIFO_WR_RD_CTL_WR_2_P_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_WR_2_P_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_WR_2_P_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_RD_2_P_RST_MASK     (0x2000000U)
#define SDADC_FIFO_WR_RD_CTL_RD_2_P_RST_SHIFT    (25U)
/*! RD_2_P_RST - Read Reset for FIFO_2_P */
#define SDADC_FIFO_WR_RD_CTL_RD_2_P_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_RD_2_P_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_RD_2_P_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_WR_2_N_RST_MASK     (0x4000000U)
#define SDADC_FIFO_WR_RD_CTL_WR_2_N_RST_SHIFT    (26U)
/*! WR_2_N_RST - Write Reset for FIFO_2_N */
#define SDADC_FIFO_WR_RD_CTL_WR_2_N_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_WR_2_N_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_WR_2_N_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_RD_2_N_RST_MASK     (0x8000000U)
#define SDADC_FIFO_WR_RD_CTL_RD_2_N_RST_SHIFT    (27U)
/*! RD_2_N_RST - Read Reset for FIFO_2_N */
#define SDADC_FIFO_WR_RD_CTL_RD_2_N_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_RD_2_N_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_RD_2_N_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_WR_3_P_RST_MASK     (0x10000000U)
#define SDADC_FIFO_WR_RD_CTL_WR_3_P_RST_SHIFT    (28U)
/*! WR_3_P_RST - Write Reset for FIFO_3_P */
#define SDADC_FIFO_WR_RD_CTL_WR_3_P_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_WR_3_P_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_WR_3_P_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_RD_3_P_RST_MASK     (0x20000000U)
#define SDADC_FIFO_WR_RD_CTL_RD_3_P_RST_SHIFT    (29U)
/*! RD_3_P_RST - Read Reset for FIFO_3_P */
#define SDADC_FIFO_WR_RD_CTL_RD_3_P_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_RD_3_P_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_RD_3_P_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_WR_3_N_RST_MASK     (0x40000000U)
#define SDADC_FIFO_WR_RD_CTL_WR_3_N_RST_SHIFT    (30U)
/*! WR_3_N_RST - Write Reset for FIFO_3_N */
#define SDADC_FIFO_WR_RD_CTL_WR_3_N_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_WR_3_N_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_WR_3_N_RST_MASK)

#define SDADC_FIFO_WR_RD_CTL_RD_3_N_RST_MASK     (0x80000000U)
#define SDADC_FIFO_WR_RD_CTL_RD_3_N_RST_SHIFT    (31U)
/*! RD_3_N_RST - Read Reset for FIFO_3_N */
#define SDADC_FIFO_WR_RD_CTL_RD_3_N_RST(x)       (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WR_RD_CTL_RD_3_N_RST_SHIFT)) & SDADC_FIFO_WR_RD_CTL_RD_3_N_RST_MASK)
/*! @} */

/*! @name FIFO_WATERMARK_CTL - FIFO Watermark Control */
/*! @{ */

#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_0_P_MASK (0xFU)
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_0_P_SHIFT (0U)
/*! WATERMARK_0_P - Watermark for FIFO_0_P */
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_0_P(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_CTL_WATERMARK_0_P_SHIFT)) & SDADC_FIFO_WATERMARK_CTL_WATERMARK_0_P_MASK)

#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_0_N_MASK (0xF0U)
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_0_N_SHIFT (4U)
/*! WATERMARK_0_N - Watermark for FIFO_0_N */
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_0_N(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_CTL_WATERMARK_0_N_SHIFT)) & SDADC_FIFO_WATERMARK_CTL_WATERMARK_0_N_MASK)

#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_1_P_MASK (0xF00U)
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_1_P_SHIFT (8U)
/*! WATERMARK_1_P - Watermark for FIFO_1_P */
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_1_P(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_CTL_WATERMARK_1_P_SHIFT)) & SDADC_FIFO_WATERMARK_CTL_WATERMARK_1_P_MASK)

#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_1_N_MASK (0xF000U)
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_1_N_SHIFT (12U)
/*! WATERMARK_1_N - Watermark for FIFO_1_N */
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_1_N(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_CTL_WATERMARK_1_N_SHIFT)) & SDADC_FIFO_WATERMARK_CTL_WATERMARK_1_N_MASK)

#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_2_P_MASK (0xF0000U)
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_2_P_SHIFT (16U)
/*! WATERMARK_2_P - Watermark for FIFO_2_P */
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_2_P(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_CTL_WATERMARK_2_P_SHIFT)) & SDADC_FIFO_WATERMARK_CTL_WATERMARK_2_P_MASK)

#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_2_N_MASK (0xF00000U)
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_2_N_SHIFT (20U)
/*! WATERMARK_2_N - Watermark for FIFO_2_N */
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_2_N(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_CTL_WATERMARK_2_N_SHIFT)) & SDADC_FIFO_WATERMARK_CTL_WATERMARK_2_N_MASK)

#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_3_P_MASK (0xF000000U)
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_3_P_SHIFT (24U)
/*! WATERMARK_3_P - Watermark for FIFO_3_P */
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_3_P(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_CTL_WATERMARK_3_P_SHIFT)) & SDADC_FIFO_WATERMARK_CTL_WATERMARK_3_P_MASK)

#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_3_N_MASK (0xF0000000U)
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_3_N_SHIFT (28U)
/*! WATERMARK_3_N - Watermark for FIFO_3_N */
#define SDADC_FIFO_WATERMARK_CTL_WATERMARK_3_N(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_CTL_WATERMARK_3_N_SHIFT)) & SDADC_FIFO_WATERMARK_CTL_WATERMARK_3_N_MASK)
/*! @} */

/*! @name FIFO_WATERMARK_ERROR_CTL - FIFO Watermark Error Control */
/*! @{ */

#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_0_P_EN_MASK (0x1U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_0_P_EN_SHIFT (0U)
/*! WM_0_P_EN - Watermark Enable for FIFO_0_P
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_0_P_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_WM_0_P_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_WM_0_P_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_0_N_EN_MASK (0x2U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_0_N_EN_SHIFT (1U)
/*! WM_0_N_EN - Watermark Enable for FIFO_0_N
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_0_N_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_WM_0_N_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_WM_0_N_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_1_P_EN_MASK (0x4U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_1_P_EN_SHIFT (2U)
/*! WM_1_P_EN - Watermark Enable for FIFO_1_P
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_1_P_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_WM_1_P_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_WM_1_P_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_1_N_EN_MASK (0x8U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_1_N_EN_SHIFT (3U)
/*! WM_1_N_EN - Watermark Enable for FIFO_1_N
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_1_N_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_WM_1_N_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_WM_1_N_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_2_P_EN_MASK (0x10U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_2_P_EN_SHIFT (4U)
/*! WM_2_P_EN - Watermark Enable for FIFO_2_P
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_2_P_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_WM_2_P_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_WM_2_P_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_2_N_EN_MASK (0x20U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_2_N_EN_SHIFT (5U)
/*! WM_2_N_EN - Watermark Enable for FIFO_2_N
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_2_N_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_WM_2_N_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_WM_2_N_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_3_P_EN_MASK (0x40U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_3_P_EN_SHIFT (6U)
/*! WM_3_P_EN - Watermark Enable for FIFO_3_P
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_3_P_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_WM_3_P_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_WM_3_P_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_3_N_EN_MASK (0x80U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_3_N_EN_SHIFT (7U)
/*! WM_3_N_EN - Watermark Enable for FIFO_3_N
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_WM_3_N_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_WM_3_N_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_WM_3_N_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_0_P_EN_MASK (0x100U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_0_P_EN_SHIFT (8U)
/*! ERR_0_P_EN - Interrupt Enable for FIFO_0_P
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_0_P_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_0_P_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_0_P_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_0_N_EN_MASK (0x200U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_0_N_EN_SHIFT (9U)
/*! ERR_0_N_EN - Interrupt Enable for FIFO_0_N
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_0_N_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_0_N_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_0_N_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_1_P_EN_MASK (0x400U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_1_P_EN_SHIFT (10U)
/*! ERR_1_P_EN - Interrupt Enable for FIFO_1_P
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_1_P_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_1_P_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_1_P_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_1_N_EN_MASK (0x800U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_1_N_EN_SHIFT (11U)
/*! ERR_1_N_EN - Interrupt Enable for FIFO_1_N
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_1_N_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_1_N_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_1_N_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_2_P_EN_MASK (0x1000U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_2_P_EN_SHIFT (12U)
/*! ERR_2_P_EN - Interrupt Enable for FIFO_2_P
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_2_P_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_2_P_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_2_P_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_2_N_EN_MASK (0x2000U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_2_N_EN_SHIFT (13U)
/*! ERR_2_N_EN - Interrupt Enable for FIFO_2_N
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_2_N_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_2_N_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_2_N_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_3_P_EN_MASK (0x4000U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_3_P_EN_SHIFT (14U)
/*! ERR_3_P_EN - Interrupt Enable for FIFO_3_P
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_3_P_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_3_P_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_3_P_EN_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_3_N_EN_MASK (0x8000U)
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_3_N_EN_SHIFT (15U)
/*! ERR_3_N_EN - Interrupt Enable for FIFO_3_N
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_3_N_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_3_N_EN_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_CTL_ERR_3_N_EN_MASK)
/*! @} */

/*! @name FIFO_WATERMARK_ERROR_ST - FIFO Watermark Error Status */
/*! @{ */

#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_0_P_ST_MASK (0x1U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_0_P_ST_SHIFT (0U)
/*! WM_0_P_ST - Watermark Status for FIFO_0_P
 *  0b0..No watermark error
 *  0b1..Watermark error
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_0_P_ST(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_WM_0_P_ST_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_WM_0_P_ST_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_0_N_ST_MASK (0x2U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_0_N_ST_SHIFT (1U)
/*! WM_0_N_ST - Watermark Status for FIFO_0_N
 *  0b0..No watermark error
 *  0b1..Watermark error
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_0_N_ST(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_WM_0_N_ST_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_WM_0_N_ST_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_1_P_ST_MASK (0x4U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_1_P_ST_SHIFT (2U)
/*! WM_1_P_ST - Watermark Status for FIFO_1_P.
 *  0b0..No watermark error
 *  0b1..Watermark error
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_1_P_ST(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_WM_1_P_ST_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_WM_1_P_ST_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_1_N_ST_MASK (0x8U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_1_N_ST_SHIFT (3U)
/*! WM_1_N_ST - Watermark Status for FIFO_1_N
 *  0b0..No watermark error
 *  0b1..Watermark error
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_1_N_ST(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_WM_1_N_ST_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_WM_1_N_ST_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_2_P_ST_MASK (0x10U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_2_P_ST_SHIFT (4U)
/*! WM_2_P_ST - Watermark Status for FIFO_2_P
 *  0b0..No watermark error
 *  0b1..Watermark error
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_2_P_ST(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_WM_2_P_ST_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_WM_2_P_ST_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_2_N_ST_MASK (0x20U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_2_N_ST_SHIFT (5U)
/*! WM_2_N_ST - Watermark Status for FIFO_2_N
 *  0b0..No watermark error
 *  0b1..Watermark error
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_2_N_ST(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_WM_2_N_ST_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_WM_2_N_ST_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_3_P_ST_MASK (0x40U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_3_P_ST_SHIFT (6U)
/*! WM_3_P_ST - Watermark Status for FIFO_3_P
 *  0b0..No watermark error
 *  0b1..Watermark error
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_3_P_ST(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_WM_3_P_ST_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_WM_3_P_ST_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_3_N_ST_MASK (0x80U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_3_N_ST_SHIFT (7U)
/*! WM_3_N_ST - Watermark Status for FIFO_3_N
 *  0b0..No watermark error
 *  0b1..Watermark error
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_WM_3_N_ST(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_WM_3_N_ST_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_WM_3_N_ST_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_0_P_MASK (0x100U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_0_P_SHIFT (8U)
/*! ERR_0_P - Interrupt from FIFO_0_P
 *  0b0..No interrupt
 *  0b1..Interrupt
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_0_P(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_ERR_0_P_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_ERR_0_P_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_0_N_MASK (0x200U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_0_N_SHIFT (9U)
/*! ERR_0_N - Interrupt from FIFO_0_N
 *  0b0..No interrupt
 *  0b1..Interrupt
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_0_N(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_ERR_0_N_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_ERR_0_N_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_1_P_MASK (0x400U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_1_P_SHIFT (10U)
/*! ERR_1_P - Interrupt from FIFO_1_P
 *  0b0..No interrupt
 *  0b1..Interrupt
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_1_P(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_ERR_1_P_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_ERR_1_P_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_1_N_MASK (0x800U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_1_N_SHIFT (11U)
/*! ERR_1_N - Interrupt from FIFO_1_N
 *  0b0..No interrupt
 *  0b1..Interrupt
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_1_N(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_ERR_1_N_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_ERR_1_N_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_2_P_MASK (0x1000U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_2_P_SHIFT (12U)
/*! ERR_2_P - Interrupt from FIFO_2_P
 *  0b0..No interrupt
 *  0b1..Interrupt
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_2_P(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_ERR_2_P_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_ERR_2_P_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_2_N_MASK (0x2000U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_2_N_SHIFT (13U)
/*! ERR_2_N - Interrupt from FIFO_2_N
 *  0b0..No interrupt
 *  0b1..Interrupt
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_2_N(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_ERR_2_N_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_ERR_2_N_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_3_P_MASK (0x4000U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_3_P_SHIFT (14U)
/*! ERR_3_P - Interrupt from FIFO_3_P
 *  0b0..No interrupt
 *  0b1..Interrupt
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_3_P(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_ERR_3_P_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_ERR_3_P_MASK)

#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_3_N_MASK (0x8000U)
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_3_N_SHIFT (15U)
/*! ERR_3_N - Interrupt from FIFO_3_N
 *  0b0..No interrupt
 *  0b1..Interrupt
 */
#define SDADC_FIFO_WATERMARK_ERROR_ST_ERR_3_N(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_WATERMARK_ERROR_ST_ERR_3_N_SHIFT)) & SDADC_FIFO_WATERMARK_ERROR_ST_ERR_3_N_MASK)
/*! @} */

/*! @name FIFO_0_P - FIFO 0 P */
/*! @{ */

#define SDADC_FIFO_0_P_FIFO_0_P_MASK             (0xFFFFFFU)
#define SDADC_FIFO_0_P_FIFO_0_P_SHIFT            (0U)
/*! FIFO_0_P - FIFO_0_P Output Data */
#define SDADC_FIFO_0_P_FIFO_0_P(x)               (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_0_P_FIFO_0_P_SHIFT)) & SDADC_FIFO_0_P_FIFO_0_P_MASK)
/*! @} */

/*! @name FIFO_0_N - FIFO 0 N */
/*! @{ */

#define SDADC_FIFO_0_N_FIFO_0_N_MASK             (0xFFFFFFU)
#define SDADC_FIFO_0_N_FIFO_0_N_SHIFT            (0U)
/*! FIFO_0_N - FIFO_0_N Output Data */
#define SDADC_FIFO_0_N_FIFO_0_N(x)               (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_0_N_FIFO_0_N_SHIFT)) & SDADC_FIFO_0_N_FIFO_0_N_MASK)
/*! @} */

/*! @name FIFO_1_P - FIFO 1 P */
/*! @{ */

#define SDADC_FIFO_1_P_FIFO_1_P_MASK             (0xFFFFFFU)
#define SDADC_FIFO_1_P_FIFO_1_P_SHIFT            (0U)
/*! FIFO_1_P - FIFO_1_P Output Data */
#define SDADC_FIFO_1_P_FIFO_1_P(x)               (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_1_P_FIFO_1_P_SHIFT)) & SDADC_FIFO_1_P_FIFO_1_P_MASK)
/*! @} */

/*! @name FIFO_1_N - FIFO 1 N */
/*! @{ */

#define SDADC_FIFO_1_N_FIFO_1_N_MASK             (0xFFFFFFU)
#define SDADC_FIFO_1_N_FIFO_1_N_SHIFT            (0U)
/*! FIFO_1_N - FIFO_1_N Output Data */
#define SDADC_FIFO_1_N_FIFO_1_N(x)               (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_1_N_FIFO_1_N_SHIFT)) & SDADC_FIFO_1_N_FIFO_1_N_MASK)
/*! @} */

/*! @name FIFO_2_P - FIFO 2 P */
/*! @{ */

#define SDADC_FIFO_2_P_FIFO_2_P_MASK             (0xFFFFFFU)
#define SDADC_FIFO_2_P_FIFO_2_P_SHIFT            (0U)
/*! FIFO_2_P - FIFO_2_P Output Data */
#define SDADC_FIFO_2_P_FIFO_2_P(x)               (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_2_P_FIFO_2_P_SHIFT)) & SDADC_FIFO_2_P_FIFO_2_P_MASK)
/*! @} */

/*! @name FIFO_2_N - FIFO 2 N */
/*! @{ */

#define SDADC_FIFO_2_N_FIFO_2_N_MASK             (0xFFFFFFU)
#define SDADC_FIFO_2_N_FIFO_2_N_SHIFT            (0U)
/*! FIFO_2_N - FIFO_2_N Output Data */
#define SDADC_FIFO_2_N_FIFO_2_N(x)               (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_2_N_FIFO_2_N_SHIFT)) & SDADC_FIFO_2_N_FIFO_2_N_MASK)
/*! @} */

/*! @name FIFO_3_P - FIFO 3 P */
/*! @{ */

#define SDADC_FIFO_3_P_FIFO_3_P_MASK             (0xFFFFFFU)
#define SDADC_FIFO_3_P_FIFO_3_P_SHIFT            (0U)
/*! FIFO_3_P - FIFO_3_P Output Data */
#define SDADC_FIFO_3_P_FIFO_3_P(x)               (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_3_P_FIFO_3_P_SHIFT)) & SDADC_FIFO_3_P_FIFO_3_P_MASK)
/*! @} */

/*! @name FIFO_3_N - FIFO 3 N */
/*! @{ */

#define SDADC_FIFO_3_N_FIFO_3_N_MASK             (0xFFFFFFU)
#define SDADC_FIFO_3_N_FIFO_3_N_SHIFT            (0U)
/*! FIFO_3_N - FIFO_3_N Output Data */
#define SDADC_FIFO_3_N_FIFO_3_N(x)               (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_3_N_FIFO_3_N_SHIFT)) & SDADC_FIFO_3_N_FIFO_3_N_MASK)
/*! @} */

/*! @name FIFO_ENTRIES_AVAIL_0 - FIFO Entries Availability 0 */
/*! @{ */

#define SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_0_P_AVAIL_MASK (0x1FU)
#define SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_0_P_AVAIL_SHIFT (0U)
/*! FIFO_0_P_AVAIL - Entries Available for FIFO_0_P */
#define SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_0_P_AVAIL(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_0_P_AVAIL_SHIFT)) & SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_0_P_AVAIL_MASK)

#define SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_0_N_AVAIL_MASK (0x1F00U)
#define SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_0_N_AVAIL_SHIFT (8U)
/*! FIFO_0_N_AVAIL - Entries Available for FIFO_0_N */
#define SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_0_N_AVAIL(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_0_N_AVAIL_SHIFT)) & SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_0_N_AVAIL_MASK)

#define SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_1_P_AVAIL_MASK (0x1F0000U)
#define SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_1_P_AVAIL_SHIFT (16U)
/*! FIFO_1_P_AVAIL - Entries Available for FIFO_1_P */
#define SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_1_P_AVAIL(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_1_P_AVAIL_SHIFT)) & SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_1_P_AVAIL_MASK)

#define SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_1_N_AVAIL_MASK (0x1F000000U)
#define SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_1_N_AVAIL_SHIFT (24U)
/*! FIFO_1_N_AVAIL - Entries Available for FIFO_1_N */
#define SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_1_N_AVAIL(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_1_N_AVAIL_SHIFT)) & SDADC_FIFO_ENTRIES_AVAIL_0_FIFO_1_N_AVAIL_MASK)
/*! @} */

/*! @name FIFO_ENTRIES_AVAIL_1 - FIFO Entries Availability 1 */
/*! @{ */

#define SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_2_P_AVAIL_MASK (0x1FU)
#define SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_2_P_AVAIL_SHIFT (0U)
/*! FIFO_2_P_AVAIL - Entries Available for FIFO_2_P */
#define SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_2_P_AVAIL(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_2_P_AVAIL_SHIFT)) & SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_2_P_AVAIL_MASK)

#define SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_2_N_AVAIL_MASK (0x1F00U)
#define SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_2_N_AVAIL_SHIFT (8U)
/*! FIFO_2_N_AVAIL - Entries Available for FIFO_2_N */
#define SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_2_N_AVAIL(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_2_N_AVAIL_SHIFT)) & SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_2_N_AVAIL_MASK)

#define SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_3_P_AVAIL_MASK (0x1F0000U)
#define SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_3_P_AVAIL_SHIFT (16U)
/*! FIFO_3_P_AVAIL - Entries Available for FIFO_3_P */
#define SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_3_P_AVAIL(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_3_P_AVAIL_SHIFT)) & SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_3_P_AVAIL_MASK)

#define SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_3_N_AVAIL_MASK (0x1F000000U)
#define SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_3_N_AVAIL_SHIFT (24U)
/*! FIFO_3_N_AVAIL - Entries Available for FIFO_3_N */
#define SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_3_N_AVAIL(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_3_N_AVAIL_SHIFT)) & SDADC_FIFO_ENTRIES_AVAIL_1_FIFO_3_N_AVAIL_MASK)
/*! @} */

/*! @name FIFO_INTERRUPT - FIFO Interrupt */
/*! @{ */

#define SDADC_FIFO_INTERRUPT_FIFO_INTERRUPT_MASK (0x1U)
#define SDADC_FIFO_INTERRUPT_FIFO_INTERRUPT_SHIFT (0U)
/*! FIFO_INTERRUPT - FIFO Interrupt */
#define SDADC_FIFO_INTERRUPT_FIFO_INTERRUPT(x)   (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_INTERRUPT_FIFO_INTERRUPT_SHIFT)) & SDADC_FIFO_INTERRUPT_FIFO_INTERRUPT_MASK)

#define SDADC_FIFO_INTERRUPT_FIFO_INTERRUPT_EN_MASK (0x2U)
#define SDADC_FIFO_INTERRUPT_FIFO_INTERRUPT_EN_SHIFT (1U)
/*! FIFO_INTERRUPT_EN - FIFO Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SDADC_FIFO_INTERRUPT_FIFO_INTERRUPT_EN(x) (((uint32_t)(((uint32_t)(x)) << SDADC_FIFO_INTERRUPT_FIFO_INTERRUPT_EN_SHIFT)) & SDADC_FIFO_INTERRUPT_FIFO_INTERRUPT_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SDADC_Register_Masks */


/*!
 * @}
 */ /* end of group SDADC_Peripheral_Access_Layer */


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


#endif  /* PERI_SDADC_H_ */

