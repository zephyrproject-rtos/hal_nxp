/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TEMPSENSE
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_TEMPSENSE.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for TEMPSENSE
 *
 * CMSIS Peripheral Access Layer for TEMPSENSE
 */

#if !defined(PERI_TEMPSENSE_H_)
#define PERI_TEMPSENSE_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
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
   -- TEMPSENSE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TEMPSENSE_Peripheral_Access_Layer TEMPSENSE Peripheral Access Layer
 * @{
 */

/** TEMPSENSE - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< Control 0, offset: 0x0 */
    __IO uint32_t SET;                               /**< Control 0, offset: 0x4 */
    __IO uint32_t CLR;                               /**< Control 0, offset: 0x8 */
    __IO uint32_t TOG;                               /**< Control 0, offset: 0xC */
  } CTRL0;
  struct {                                         /* offset: 0x10 */
    __IO uint32_t RW;                                /**< Status 0, offset: 0x10 */
    __IO uint32_t SET;                               /**< Status 0, offset: 0x14 */
    __IO uint32_t CLR;                               /**< Status 0, offset: 0x18 */
    __IO uint32_t TOG;                               /**< Status 0, offset: 0x1C */
  } STAT0;
  struct {                                         /* offset: 0x20 */
    __IO uint32_t RW;                                /**< Data 0, offset: 0x20 */
    __IO uint32_t SET;                               /**< Data 0, offset: 0x24 */
    __IO uint32_t CLR;                               /**< Data 0, offset: 0x28 */
    __IO uint32_t TOG;                               /**< Data 0, offset: 0x2C */
  } DATA0;
  struct {                                         /* offset: 0x30 */
    __IO uint32_t RW;                                /**< Threshold Control 01, offset: 0x30 */
    __IO uint32_t SET;                               /**< Threshold Control 01, offset: 0x34 */
    __IO uint32_t CLR;                               /**< Threshold Control 01, offset: 0x38 */
    __IO uint32_t TOG;                               /**< Threshold Control 01, offset: 0x3C */
  } THR_CTRL01;
  struct {                                         /* offset: 0x40 */
    __IO uint32_t RW;                                /**< Threshold Control 23, offset: 0x40 */
    __IO uint32_t SET;                               /**< Threshold Control 23, offset: 0x44 */
    __IO uint32_t CLR;                               /**< Threshold Control 23, offset: 0x48 */
    __IO uint32_t TOG;                               /**< Threshold Control 23, offset: 0x4C */
  } THR_CTRL23;
       uint8_t RESERVED_0[432];
  struct {                                         /* offset: 0x200 */
    __IO uint32_t RW;                                /**< Control 1, offset: 0x200 */
    __IO uint32_t SET;                               /**< Control 1, offset: 0x204 */
    __IO uint32_t CLR;                               /**< Control 1, offset: 0x208 */
    __IO uint32_t TOG;                               /**< Control 1, offset: 0x20C */
  } CTRL1;
  struct {                                         /* offset: 0x210 */
    __IO uint32_t RW;                                /**< Status 1, offset: 0x210 */
    __IO uint32_t SET;                               /**< Status 1, offset: 0x214 */
    __IO uint32_t CLR;                               /**< Status 1, offset: 0x218 */
    __IO uint32_t TOG;                               /**< Status 1, offset: 0x21C */
  } STAT1;
  struct {                                         /* offset: 0x220 */
    __IO uint32_t RW;                                /**< Data 1, offset: 0x220 */
    __IO uint32_t SET;                               /**< Data 1, offset: 0x224 */
    __IO uint32_t CLR;                               /**< Data 1, offset: 0x228 */
    __IO uint32_t TOG;                               /**< Data 1, offset: 0x22C */
  } DATA1;
       uint8_t RESERVED_1[32];
  struct {                                         /* offset: 0x250 */
    __IO uint32_t RW;                                /**< Threshold Control 45, offset: 0x250 */
    __IO uint32_t SET;                               /**< Threshold Control 45, offset: 0x254 */
    __IO uint32_t CLR;                               /**< Threshold Control 45, offset: 0x258 */
    __IO uint32_t TOG;                               /**< Threshold Control 45, offset: 0x25C */
  } THR_CTRL45;
       uint8_t RESERVED_2[16];
  struct {                                         /* offset: 0x270 */
    __IO uint32_t RW;                                /**< Measurement Period Control, offset: 0x270 */
    __IO uint32_t SET;                               /**< Measurement Period Control, offset: 0x274 */
    __IO uint32_t CLR;                               /**< Measurement Period Control, offset: 0x278 */
    __IO uint32_t TOG;                               /**< Measurement Period Control, offset: 0x27C */
  } PERIOD_CTRL;
  __IO uint32_t REF_DIV;                           /**< Reference Clock Divider Control, offset: 0x280 */
       uint8_t RESERVED_3[44];
  struct {                                         /* offset: 0x2B0 */
    __IO uint32_t RW;                                /**< Power-Up Delay Control, offset: 0x2B0 */
    __IO uint32_t SET;                               /**< Power-Up Delay Control, offset: 0x2B4 */
    __IO uint32_t CLR;                               /**< Power-Up Delay Control, offset: 0x2B8 */
    __IO uint32_t TOG;                               /**< Power-Up Delay Control, offset: 0x2BC */
  } PUD_ST_CTRL;
       uint8_t RESERVED_4[32];
  struct {                                         /* offset: 0x2E0 */
    __IO uint32_t RW;                                /**< Trim Control 1, offset: 0x2E0 */
    __IO uint32_t SET;                               /**< Trim Control 1, offset: 0x2E4 */
    __IO uint32_t CLR;                               /**< Trim Control 1, offset: 0x2E8 */
    __IO uint32_t TOG;                               /**< Trim Control 1, offset: 0x2EC */
  } TRIM1;
  struct {                                         /* offset: 0x2F0 */
    __IO uint32_t RW;                                /**< Trim Control 2, offset: 0x2F0 */
    __IO uint32_t SET;                               /**< Trim Control 2, offset: 0x2F4 */
    __IO uint32_t CLR;                               /**< Trim Control 2, offset: 0x2F8 */
    __IO uint32_t TOG;                               /**< Trim Control 2, offset: 0x2FC */
  } TRIM2;
} TEMPSENSE_Type;

/* ----------------------------------------------------------------------------
   -- TEMPSENSE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TEMPSENSE_Register_Masks TEMPSENSE Register Masks
 * @{
 */

/*! @name CTRL0 - Control 0 */
/*! @{ */

#define TEMPSENSE_CTRL0_THR0_MODE_MASK           (0x3U)
#define TEMPSENSE_CTRL0_THR0_MODE_SHIFT          (0U)
/*! THR0_MODE - Threshold0 Comparator Mode
 *  0b00..Less than or equal to threshold
 *  0b01..Greater than threshold
 *  0b10..High to low temperature data transition at threshold
 *  0b11..Low to high temperature data transition at threshold
 */
#define TEMPSENSE_CTRL0_THR0_MODE(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_THR0_MODE_SHIFT)) & TEMPSENSE_CTRL0_THR0_MODE_MASK)

#define TEMPSENSE_CTRL0_THR1_MODE_MASK           (0xCU)
#define TEMPSENSE_CTRL0_THR1_MODE_SHIFT          (2U)
/*! THR1_MODE - Threshold1 Comparator Mode
 *  0b00..Less than or equal to threshold
 *  0b01..Greater than threshold
 *  0b10..High to low temperature data transition at threshold
 *  0b11..Low to high temperature data transition at threshold
 */
#define TEMPSENSE_CTRL0_THR1_MODE(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_THR1_MODE_SHIFT)) & TEMPSENSE_CTRL0_THR1_MODE_MASK)

#define TEMPSENSE_CTRL0_THR2_MODE_MASK           (0x30U)
#define TEMPSENSE_CTRL0_THR2_MODE_SHIFT          (4U)
/*! THR2_MODE - Threshold2 Comparator Mode
 *  0b00..Less than or equal to threshold
 *  0b01..Greater than threshold
 *  0b10..High to low temperature data transition at threshold
 *  0b11..Low to high temperature data transition at threshold
 */
#define TEMPSENSE_CTRL0_THR2_MODE(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_THR2_MODE_SHIFT)) & TEMPSENSE_CTRL0_THR2_MODE_MASK)

#define TEMPSENSE_CTRL0_THR0_IE_MASK             (0x100U)
#define TEMPSENSE_CTRL0_THR0_IE_SHIFT            (8U)
/*! THR0_IE - Threshold0 Comparator Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TEMPSENSE_CTRL0_THR0_IE(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_THR0_IE_SHIFT)) & TEMPSENSE_CTRL0_THR0_IE_MASK)

#define TEMPSENSE_CTRL0_THR1_IE_MASK             (0x200U)
#define TEMPSENSE_CTRL0_THR1_IE_SHIFT            (9U)
/*! THR1_IE - Threshold1 Comparator Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TEMPSENSE_CTRL0_THR1_IE(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_THR1_IE_SHIFT)) & TEMPSENSE_CTRL0_THR1_IE_MASK)

#define TEMPSENSE_CTRL0_THR2_IE_MASK             (0x400U)
#define TEMPSENSE_CTRL0_THR2_IE_SHIFT            (10U)
/*! THR2_IE - Threshold2 Comparator Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TEMPSENSE_CTRL0_THR2_IE(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_THR2_IE_SHIFT)) & TEMPSENSE_CTRL0_THR2_IE_MASK)

#define TEMPSENSE_CTRL0_N_FILT_0_MASK            (0xF000U)
#define TEMPSENSE_CTRL0_N_FILT_0_SHIFT           (12U)
/*! N_FILT_0 - Filter Length for Threshold Flag */
#define TEMPSENSE_CTRL0_N_FILT_0(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_N_FILT_0_SHIFT)) & TEMPSENSE_CTRL0_N_FILT_0_MASK)

#define TEMPSENSE_CTRL0_DRDY0_IE_MASK            (0x10000U)
#define TEMPSENSE_CTRL0_DRDY0_IE_SHIFT           (16U)
/*! DRDY0_IE - Data-Ready Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TEMPSENSE_CTRL0_DRDY0_IE(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_DRDY0_IE_SHIFT)) & TEMPSENSE_CTRL0_DRDY0_IE_MASK)

#define TEMPSENSE_CTRL0_FILT0_CNT_CLR_MASK       (0x100000U)
#define TEMPSENSE_CTRL0_FILT0_CNT_CLR_SHIFT      (20U)
/*! FILT0_CNT_CLR - Filter 0 Counter Clear
 *  0b0..Settle to 0 after clearing the counter
 *  0b1..Clear the internal counter
 */
#define TEMPSENSE_CTRL0_FILT0_CNT_CLR(x)         (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_FILT0_CNT_CLR_SHIFT)) & TEMPSENSE_CTRL0_FILT0_CNT_CLR_MASK)

#define TEMPSENSE_CTRL0_FILT1_CNT_CLR_MASK       (0x200000U)
#define TEMPSENSE_CTRL0_FILT1_CNT_CLR_SHIFT      (21U)
/*! FILT1_CNT_CLR - Filter 1 Counter Clear
 *  0b0..Settle to 0 after clearing the counter
 *  0b1..Clear the internal counter
 */
#define TEMPSENSE_CTRL0_FILT1_CNT_CLR(x)         (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_FILT1_CNT_CLR_SHIFT)) & TEMPSENSE_CTRL0_FILT1_CNT_CLR_MASK)

#define TEMPSENSE_CTRL0_FILT2_CNT_CLR_MASK       (0x400000U)
#define TEMPSENSE_CTRL0_FILT2_CNT_CLR_SHIFT      (22U)
/*! FILT2_CNT_CLR - Filter 2 Counter Clear
 *  0b0..Settle to 0 after clearing the counter
 *  0b1..Clear the internal counter
 */
#define TEMPSENSE_CTRL0_FILT2_CNT_CLR(x)         (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_FILT2_CNT_CLR_SHIFT)) & TEMPSENSE_CTRL0_FILT2_CNT_CLR_MASK)
/*! @} */

/*! @name STAT0 - Status 0 */
/*! @{ */

#define TEMPSENSE_STAT0_THR0_IF_MASK             (0x100U)
#define TEMPSENSE_STAT0_THR0_IF_SHIFT            (8U)
/*! THR0_IF - Threshold0 Status Flag
 *  0b0..Event did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event occurred
 */
#define TEMPSENSE_STAT0_THR0_IF(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_THR0_IF_SHIFT)) & TEMPSENSE_STAT0_THR0_IF_MASK)

#define TEMPSENSE_STAT0_THR1_IF_MASK             (0x200U)
#define TEMPSENSE_STAT0_THR1_IF_SHIFT            (9U)
/*! THR1_IF - Threshold1 Status Flag
 *  0b0..Event did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event occurred
 */
#define TEMPSENSE_STAT0_THR1_IF(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_THR1_IF_SHIFT)) & TEMPSENSE_STAT0_THR1_IF_MASK)

#define TEMPSENSE_STAT0_THR2_IF_MASK             (0x400U)
#define TEMPSENSE_STAT0_THR2_IF_SHIFT            (10U)
/*! THR2_IF - Threshold2 Status Flag
 *  0b0..Event did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event occurred
 */
#define TEMPSENSE_STAT0_THR2_IF(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_THR2_IF_SHIFT)) & TEMPSENSE_STAT0_THR2_IF_MASK)

#define TEMPSENSE_STAT0_THR0_STAT_MASK           (0x1000U)
#define TEMPSENSE_STAT0_THR0_STAT_SHIFT          (12U)
/*! THR0_STAT - Threshold0 State */
#define TEMPSENSE_STAT0_THR0_STAT(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_THR0_STAT_SHIFT)) & TEMPSENSE_STAT0_THR0_STAT_MASK)

#define TEMPSENSE_STAT0_THR1_STAT_MASK           (0x2000U)
#define TEMPSENSE_STAT0_THR1_STAT_SHIFT          (13U)
/*! THR1_STAT - Threshold1 State */
#define TEMPSENSE_STAT0_THR1_STAT(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_THR1_STAT_SHIFT)) & TEMPSENSE_STAT0_THR1_STAT_MASK)

#define TEMPSENSE_STAT0_THR2_STAT_MASK           (0x4000U)
#define TEMPSENSE_STAT0_THR2_STAT_SHIFT          (14U)
/*! THR2_STAT - Threshold2 State */
#define TEMPSENSE_STAT0_THR2_STAT(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_THR2_STAT_SHIFT)) & TEMPSENSE_STAT0_THR2_STAT_MASK)

#define TEMPSENSE_STAT0_DRDY0_IF_MASK            (0x10000U)
#define TEMPSENSE_STAT0_DRDY0_IF_SHIFT           (16U)
/*! DRDY0_IF - Data Ready Flag
 *  0b0..No new data available
 *  0b1..New data available
 */
#define TEMPSENSE_STAT0_DRDY0_IF(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_DRDY0_IF_SHIFT)) & TEMPSENSE_STAT0_DRDY0_IF_MASK)

#define TEMPSENSE_STAT0_IDLE_MASK                (0x80000000U)
#define TEMPSENSE_STAT0_IDLE_SHIFT               (31U)
/*! IDLE - Idle State
 *  0b0..Conversion
 *  0b1..Idle
 */
#define TEMPSENSE_STAT0_IDLE(x)                  (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_IDLE_SHIFT)) & TEMPSENSE_STAT0_IDLE_MASK)
/*! @} */

/*! @name DATA0 - Data 0 */
/*! @{ */

#define TEMPSENSE_DATA0_DATA_VAL_MASK            (0xFFFFU)
#define TEMPSENSE_DATA0_DATA_VAL_SHIFT           (0U)
/*! DATA_VAL - Temperature Data Value */
#define TEMPSENSE_DATA0_DATA_VAL(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_DATA0_DATA_VAL_SHIFT)) & TEMPSENSE_DATA0_DATA_VAL_MASK)
/*! @} */

/*! @name THR_CTRL01 - Threshold Control 01 */
/*! @{ */

#define TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD0_MASK (0xFFFFU)
#define TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD0_SHIFT (0U)
/*! TEMPERATURE_THRESHOLD0 - Temperature Threshold0 */
#define TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD0(x) (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD0_SHIFT)) & TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD0_MASK)

#define TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD1_MASK (0xFFFF0000U)
#define TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD1_SHIFT (16U)
/*! TEMPERATURE_THRESHOLD1 - Temperature Threshold1 */
#define TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD1(x) (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD1_SHIFT)) & TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD1_MASK)
/*! @} */

/*! @name THR_CTRL23 - Threshold Control 23 */
/*! @{ */

#define TEMPSENSE_THR_CTRL23_TEMPERATURE_THRESHOLD2_MASK (0xFFFFU)
#define TEMPSENSE_THR_CTRL23_TEMPERATURE_THRESHOLD2_SHIFT (0U)
/*! TEMPERATURE_THRESHOLD2 - Temperature Threshold2 */
#define TEMPSENSE_THR_CTRL23_TEMPERATURE_THRESHOLD2(x) (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_THR_CTRL23_TEMPERATURE_THRESHOLD2_SHIFT)) & TEMPSENSE_THR_CTRL23_TEMPERATURE_THRESHOLD2_MASK)
/*! @} */

/*! @name CTRL1 - Control 1 */
/*! @{ */

#define TEMPSENSE_CTRL1_THR4_MODE_MASK           (0x3U)
#define TEMPSENSE_CTRL1_THR4_MODE_SHIFT          (0U)
/*! THR4_MODE - Threshold4 Comparator Mode
 *  0b00..Less than or equal to threshold
 *  0b01..Greater than threshold
 *  0b10..High to low temperature data transition at threshold
 *  0b11..Low to high temperature data transition at threshold
 */
#define TEMPSENSE_CTRL1_THR4_MODE(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_THR4_MODE_SHIFT)) & TEMPSENSE_CTRL1_THR4_MODE_MASK)

#define TEMPSENSE_CTRL1_THR5_MODE_MASK           (0xCU)
#define TEMPSENSE_CTRL1_THR5_MODE_SHIFT          (2U)
/*! THR5_MODE - Threshold5 Comparator Mode
 *  0b00..Less than or equal to threshold
 *  0b01..Greater than threshold
 *  0b10..High to low temperature data transition at threshold
 *  0b11..Low to high temperature data transition at threshold
 */
#define TEMPSENSE_CTRL1_THR5_MODE(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_THR5_MODE_SHIFT)) & TEMPSENSE_CTRL1_THR5_MODE_MASK)

#define TEMPSENSE_CTRL1_THR4_IE_MASK             (0x100U)
#define TEMPSENSE_CTRL1_THR4_IE_SHIFT            (8U)
/*! THR4_IE - Threshold Comparator4 Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TEMPSENSE_CTRL1_THR4_IE(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_THR4_IE_SHIFT)) & TEMPSENSE_CTRL1_THR4_IE_MASK)

#define TEMPSENSE_CTRL1_THR5_IE_MASK             (0x200U)
#define TEMPSENSE_CTRL1_THR5_IE_SHIFT            (9U)
/*! THR5_IE - Threshold Comparator5 Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TEMPSENSE_CTRL1_THR5_IE(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_THR5_IE_SHIFT)) & TEMPSENSE_CTRL1_THR5_IE_MASK)

#define TEMPSENSE_CTRL1_N_FILT_1_MASK            (0xF000U)
#define TEMPSENSE_CTRL1_N_FILT_1_SHIFT           (12U)
/*! N_FILT_1 - Filter Length for Threshold Flag */
#define TEMPSENSE_CTRL1_N_FILT_1(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_N_FILT_1_SHIFT)) & TEMPSENSE_CTRL1_N_FILT_1_MASK)

#define TEMPSENSE_CTRL1_DRDY1_IE_MASK            (0x10000U)
#define TEMPSENSE_CTRL1_DRDY1_IE_SHIFT           (16U)
/*! DRDY1_IE - Data-Ready Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TEMPSENSE_CTRL1_DRDY1_IE(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_DRDY1_IE_SHIFT)) & TEMPSENSE_CTRL1_DRDY1_IE_MASK)

#define TEMPSENSE_CTRL1_RESOLUTION_MASK          (0xC0000U)
#define TEMPSENSE_CTRL1_RESOLUTION_SHIFT         (18U)
/*! RESOLUTION - Resolution Mode
 *  0b00..0.59325 ms
 *  0b01..1.10525 ms
 *  0b10..2.12925 ms
 *  0b11..4.17725 ms
 */
#define TEMPSENSE_CTRL1_RESOLUTION(x)            (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_RESOLUTION_SHIFT)) & TEMPSENSE_CTRL1_RESOLUTION_MASK)

#define TEMPSENSE_CTRL1_FILT4_CNT_CLR_MASK       (0x100000U)
#define TEMPSENSE_CTRL1_FILT4_CNT_CLR_SHIFT      (20U)
/*! FILT4_CNT_CLR - Filter 4 Counter Clear
 *  0b0..Settle to 0 after clearing the counter
 *  0b1..Clear the internal counter
 */
#define TEMPSENSE_CTRL1_FILT4_CNT_CLR(x)         (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_FILT4_CNT_CLR_SHIFT)) & TEMPSENSE_CTRL1_FILT4_CNT_CLR_MASK)

#define TEMPSENSE_CTRL1_FILT5_CNT_CLR_MASK       (0x200000U)
#define TEMPSENSE_CTRL1_FILT5_CNT_CLR_SHIFT      (21U)
/*! FILT5_CNT_CLR - Filter 5 Counter Clear
 *  0b0..Settle to 0 after clearing the counter
 *  0b1..Clear the internal counter
 */
#define TEMPSENSE_CTRL1_FILT5_CNT_CLR(x)         (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_FILT5_CNT_CLR_SHIFT)) & TEMPSENSE_CTRL1_FILT5_CNT_CLR_MASK)

#define TEMPSENSE_CTRL1_MEAS_MODE_MASK           (0x3000000U)
#define TEMPSENSE_CTRL1_MEAS_MODE_SHIFT          (24U)
/*! MEAS_MODE - Measurement Mode
 *  0b00..Single One-Shot Measurement
 *  0b01..Continuous Measurement
 *  0b10..Periodic One-Shot Measurement
 *  0b11..Reserved
 */
#define TEMPSENSE_CTRL1_MEAS_MODE(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_MEAS_MODE_SHIFT)) & TEMPSENSE_CTRL1_MEAS_MODE_MASK)

#define TEMPSENSE_CTRL1_STOP_MASK                (0x20000000U)
#define TEMPSENSE_CTRL1_STOP_SHIFT               (29U)
/*! STOP - Stop Measurement
 *  0b0..Clear after conversion is over
 *  0b1..Stop the conversion
 */
#define TEMPSENSE_CTRL1_STOP(x)                  (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_STOP_SHIFT)) & TEMPSENSE_CTRL1_STOP_MASK)

#define TEMPSENSE_CTRL1_START_MASK               (0x40000000U)
#define TEMPSENSE_CTRL1_START_SHIFT              (30U)
/*! START - Start Measurement
 *  0b0..No effect
 *  0b1..Start the measurement
 */
#define TEMPSENSE_CTRL1_START(x)                 (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_START_SHIFT)) & TEMPSENSE_CTRL1_START_MASK)

#define TEMPSENSE_CTRL1_ENABLE_MASK              (0x80000000U)
#define TEMPSENSE_CTRL1_ENABLE_SHIFT             (31U)
/*! ENABLE - TEMPSENSE Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TEMPSENSE_CTRL1_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_ENABLE_SHIFT)) & TEMPSENSE_CTRL1_ENABLE_MASK)
/*! @} */

/*! @name STAT1 - Status 1 */
/*! @{ */

#define TEMPSENSE_STAT1_THR4_IF_MASK             (0x100U)
#define TEMPSENSE_STAT1_THR4_IF_SHIFT            (8U)
/*! THR4_IF - Threshold4 Status Flag
 *  0b0..Event did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event occurred
 */
#define TEMPSENSE_STAT1_THR4_IF(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT1_THR4_IF_SHIFT)) & TEMPSENSE_STAT1_THR4_IF_MASK)

#define TEMPSENSE_STAT1_THR5_IF_MASK             (0x200U)
#define TEMPSENSE_STAT1_THR5_IF_SHIFT            (9U)
/*! THR5_IF - Threshold5 Status Flag
 *  0b0..Event did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event occurred
 */
#define TEMPSENSE_STAT1_THR5_IF(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT1_THR5_IF_SHIFT)) & TEMPSENSE_STAT1_THR5_IF_MASK)

#define TEMPSENSE_STAT1_THR4_STAT_MASK           (0x1000U)
#define TEMPSENSE_STAT1_THR4_STAT_SHIFT          (12U)
/*! THR4_STAT - Threshold4 State */
#define TEMPSENSE_STAT1_THR4_STAT(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT1_THR4_STAT_SHIFT)) & TEMPSENSE_STAT1_THR4_STAT_MASK)

#define TEMPSENSE_STAT1_THR5_STAT_MASK           (0x2000U)
#define TEMPSENSE_STAT1_THR5_STAT_SHIFT          (13U)
/*! THR5_STAT - Threshold5 State */
#define TEMPSENSE_STAT1_THR5_STAT(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT1_THR5_STAT_SHIFT)) & TEMPSENSE_STAT1_THR5_STAT_MASK)

#define TEMPSENSE_STAT1_DRDY1_IF_MASK            (0x10000U)
#define TEMPSENSE_STAT1_DRDY1_IF_SHIFT           (16U)
/*! DRDY1_IF - Data Ready Flag
 *  0b0..No new data
 *  0b1..New data
 */
#define TEMPSENSE_STAT1_DRDY1_IF(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT1_DRDY1_IF_SHIFT)) & TEMPSENSE_STAT1_DRDY1_IF_MASK)

#define TEMPSENSE_STAT1_IDLE_MASK                (0x80000000U)
#define TEMPSENSE_STAT1_IDLE_SHIFT               (31U)
/*! IDLE - Idle State
 *  0b0..Conversion
 *  0b1..Idle
 */
#define TEMPSENSE_STAT1_IDLE(x)                  (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT1_IDLE_SHIFT)) & TEMPSENSE_STAT1_IDLE_MASK)
/*! @} */

/*! @name DATA1 - Data 1 */
/*! @{ */

#define TEMPSENSE_DATA1_DATA_VAL_MASK            (0xFFFFU)
#define TEMPSENSE_DATA1_DATA_VAL_SHIFT           (0U)
/*! DATA_VAL - Temperature Data Value */
#define TEMPSENSE_DATA1_DATA_VAL(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_DATA1_DATA_VAL_SHIFT)) & TEMPSENSE_DATA1_DATA_VAL_MASK)
/*! @} */

/*! @name THR_CTRL45 - Threshold Control 45 */
/*! @{ */

#define TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD4_MASK (0xFFFFU)
#define TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD4_SHIFT (0U)
/*! TEMPERATURE_THRESHOLD4 - Temperature Threshold4 */
#define TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD4(x) (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD4_SHIFT)) & TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD4_MASK)

#define TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD5_MASK (0xFFFF0000U)
#define TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD5_SHIFT (16U)
/*! TEMPERATURE_THRESHOLD5 - Temperature Threshold5 */
#define TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD5(x) (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD5_SHIFT)) & TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD5_MASK)
/*! @} */

/*! @name PERIOD_CTRL - Measurement Period Control */
/*! @{ */

#define TEMPSENSE_PERIOD_CTRL_MEAS_FREQ_MASK     (0xFFFFFFU)
#define TEMPSENSE_PERIOD_CTRL_MEAS_FREQ_SHIFT    (0U)
/*! MEAS_FREQ - TEMPSENSE Periodic Measurement Frequency */
#define TEMPSENSE_PERIOD_CTRL_MEAS_FREQ(x)       (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_PERIOD_CTRL_MEAS_FREQ_SHIFT)) & TEMPSENSE_PERIOD_CTRL_MEAS_FREQ_MASK)
/*! @} */

/*! @name REF_DIV - Reference Clock Divider Control */
/*! @{ */

#define TEMPSENSE_REF_DIV_DIV_MASK               (0xFF0000U)
#define TEMPSENSE_REF_DIV_DIV_SHIFT              (16U)
/*! DIV - Divider Value
 *  0b00000000..Output clock frequency = input clock frequency
 *  0b00000001..Output clock frequency = input clock frequency / 2
 *  0b00000010..Output clock frequency = input clock frequency / 3
 *  0b00000011.....
 *  0b11111111..Output clock frequency = input clock frequency / 256
 */
#define TEMPSENSE_REF_DIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_REF_DIV_DIV_SHIFT)) & TEMPSENSE_REF_DIV_DIV_MASK)

#define TEMPSENSE_REF_DIV_DE_MASK                (0x80000000U)
#define TEMPSENSE_REF_DIV_DE_SHIFT               (31U)
/*! DE - Divider Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TEMPSENSE_REF_DIV_DE(x)                  (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_REF_DIV_DE_SHIFT)) & TEMPSENSE_REF_DIV_DE_MASK)
/*! @} */

/*! @name PUD_ST_CTRL - Power-Up Delay Control */
/*! @{ */

#define TEMPSENSE_PUD_ST_CTRL_PUD_MASK           (0xFF0000U)
#define TEMPSENSE_PUD_ST_CTRL_PUD_SHIFT          (16U)
/*! PUD - Power-Up Delay */
#define TEMPSENSE_PUD_ST_CTRL_PUD(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_PUD_ST_CTRL_PUD_SHIFT)) & TEMPSENSE_PUD_ST_CTRL_PUD_MASK)
/*! @} */

/*! @name TRIM1 - Trim Control 1 */
/*! @{ */

#define TEMPSENSE_TRIM1_VAL_A_MASK               (0xFFFFU)
#define TEMPSENSE_TRIM1_VAL_A_SHIFT              (0U)
/*! VAL_A - VAL_A */
#define TEMPSENSE_TRIM1_VAL_A(x)                 (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_TRIM1_VAL_A_SHIFT)) & TEMPSENSE_TRIM1_VAL_A_MASK)

#define TEMPSENSE_TRIM1_VAL_B_MASK               (0xFFFF0000U)
#define TEMPSENSE_TRIM1_VAL_B_SHIFT              (16U)
/*! VAL_B - VAL_B */
#define TEMPSENSE_TRIM1_VAL_B(x)                 (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_TRIM1_VAL_B_SHIFT)) & TEMPSENSE_TRIM1_VAL_B_MASK)
/*! @} */

/*! @name TRIM2 - Trim Control 2 */
/*! @{ */

#define TEMPSENSE_TRIM2_VAL_ALPHA_MASK           (0xFFFFU)
#define TEMPSENSE_TRIM2_VAL_ALPHA_SHIFT          (0U)
/*! VAL_ALPHA - VAL_ALPHA */
#define TEMPSENSE_TRIM2_VAL_ALPHA(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_TRIM2_VAL_ALPHA_SHIFT)) & TEMPSENSE_TRIM2_VAL_ALPHA_MASK)

#define TEMPSENSE_TRIM2_VAL_OFFSET_MASK          (0xFFFF0000U)
#define TEMPSENSE_TRIM2_VAL_OFFSET_SHIFT         (16U)
/*! VAL_OFFSET - VAL_OFFSET */
#define TEMPSENSE_TRIM2_VAL_OFFSET(x)            (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_TRIM2_VAL_OFFSET_SHIFT)) & TEMPSENSE_TRIM2_VAL_OFFSET_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TEMPSENSE_Register_Masks */


/*!
 * @}
 */ /* end of group TEMPSENSE_Peripheral_Access_Layer */


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


#endif  /* PERI_TEMPSENSE_H_ */
