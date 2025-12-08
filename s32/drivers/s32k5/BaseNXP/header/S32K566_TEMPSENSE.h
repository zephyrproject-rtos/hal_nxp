/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_TEMPSENSE.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_TEMPSENSE
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32K566_TEMPSENSE_H_)  /* Check if memory map has not been already included */
#define S32K566_TEMPSENSE_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- TEMPSENSE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TEMPSENSE_Peripheral_Access_Layer TEMPSENSE Peripheral Access Layer
 * @{
 */

/** TEMPSENSE - Register Layout Typedef */
typedef struct TEMPSENSE_Struct {
  __IO uint32_t CTRL0;                             /**< Control 0, offset: 0x0 */
  uint8_t RESERVED_0[12];
  struct TEMPSENSE_STAT0 {                         /* offset: 0x10 */
    __IO uint32_t RW;                                /**< Status 0, offset: 0x10 */
    __IO uint32_t SET;                               /**< Status 0, offset: 0x14 */
    __IO uint32_t CLR;                               /**< Status 0, offset: 0x18 */
    __IO uint32_t TOG;                               /**< Status 0, offset: 0x1C */
  } STAT0;
  __IO uint32_t DATA0;                             /**< Data 0, offset: 0x20 */
  uint8_t RESERVED_1[12];
  __IO uint32_t THR_CTRL01;                        /**< Threshold Control 01, offset: 0x30 */
  uint8_t RESERVED_2[12];
  __IO uint32_t THR_CTRL23;                        /**< Threshold Control 23, offset: 0x40 */
  uint8_t RESERVED_3[444];
  __IO uint32_t CTRL1;                             /**< Control 1, offset: 0x200 */
  uint8_t RESERVED_4[12];
  struct TEMPSENSE_STAT1 {                         /* offset: 0x210 */
    __IO uint32_t RW;                                /**< Status 1, offset: 0x210 */
    __IO uint32_t SET;                               /**< Status 1, offset: 0x214 */
    __IO uint32_t CLR;                               /**< Status 1, offset: 0x218 */
    __IO uint32_t TOG;                               /**< Status 1, offset: 0x21C */
  } STAT1;
  __IO uint32_t DATA1;                             /**< Data 1, offset: 0x220 */
  uint8_t RESERVED_5[44];
  __IO uint32_t THR_CTRL45;                        /**< Threshold Control 45, offset: 0x250 */
  uint8_t RESERVED_6[28];
  __IO uint32_t PERIOD_CTRL;                       /**< Measurement Period Control, offset: 0x270 */
  uint8_t RESERVED_7[12];
  __IO uint32_t REF_DIV;                           /**< Reference Clock Divider Control, offset: 0x280 */
  uint8_t RESERVED_8[44];
  __IO uint32_t PUD_ST_CTRL;                       /**< Power-Up Delay Control, offset: 0x2B0 */
} TEMPSENSE_Type, *TEMPSENSE_MemMapPtr;

/** Number of instances of the TEMPSENSE module. */
#define TEMPSENSE_INSTANCE_COUNT                 (1u)

/* TEMPSENSE - Peripheral instance base addresses */
/** Peripheral LPE_TEMPSENSE base address */
#define IP_LPE_TEMPSENSE_BASE                    (0x4214C000u)
/** Peripheral LPE_TEMPSENSE base pointer */
#define IP_LPE_TEMPSENSE                         ((TEMPSENSE_Type *)IP_LPE_TEMPSENSE_BASE)
/** Array initializer of TEMPSENSE peripheral base addresses */
#define IP_TEMPSENSE_BASE_ADDRS                  { IP_LPE_TEMPSENSE_BASE }
/** Array initializer of TEMPSENSE peripheral base pointers */
#define IP_TEMPSENSE_BASE_PTRS                   { IP_LPE_TEMPSENSE }

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
#define TEMPSENSE_CTRL0_THR0_MODE_WIDTH          (2U)
#define TEMPSENSE_CTRL0_THR0_MODE(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_THR0_MODE_SHIFT)) & TEMPSENSE_CTRL0_THR0_MODE_MASK)

#define TEMPSENSE_CTRL0_THR1_MODE_MASK           (0xCU)
#define TEMPSENSE_CTRL0_THR1_MODE_SHIFT          (2U)
#define TEMPSENSE_CTRL0_THR1_MODE_WIDTH          (2U)
#define TEMPSENSE_CTRL0_THR1_MODE(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_THR1_MODE_SHIFT)) & TEMPSENSE_CTRL0_THR1_MODE_MASK)

#define TEMPSENSE_CTRL0_THR2_MODE_MASK           (0x30U)
#define TEMPSENSE_CTRL0_THR2_MODE_SHIFT          (4U)
#define TEMPSENSE_CTRL0_THR2_MODE_WIDTH          (2U)
#define TEMPSENSE_CTRL0_THR2_MODE(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_THR2_MODE_SHIFT)) & TEMPSENSE_CTRL0_THR2_MODE_MASK)

#define TEMPSENSE_CTRL0_THR0_IE_MASK             (0x100U)
#define TEMPSENSE_CTRL0_THR0_IE_SHIFT            (8U)
#define TEMPSENSE_CTRL0_THR0_IE_WIDTH            (1U)
#define TEMPSENSE_CTRL0_THR0_IE(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_THR0_IE_SHIFT)) & TEMPSENSE_CTRL0_THR0_IE_MASK)

#define TEMPSENSE_CTRL0_THR1_IE_MASK             (0x200U)
#define TEMPSENSE_CTRL0_THR1_IE_SHIFT            (9U)
#define TEMPSENSE_CTRL0_THR1_IE_WIDTH            (1U)
#define TEMPSENSE_CTRL0_THR1_IE(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_THR1_IE_SHIFT)) & TEMPSENSE_CTRL0_THR1_IE_MASK)

#define TEMPSENSE_CTRL0_THR2_IE_MASK             (0x400U)
#define TEMPSENSE_CTRL0_THR2_IE_SHIFT            (10U)
#define TEMPSENSE_CTRL0_THR2_IE_WIDTH            (1U)
#define TEMPSENSE_CTRL0_THR2_IE(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_THR2_IE_SHIFT)) & TEMPSENSE_CTRL0_THR2_IE_MASK)

#define TEMPSENSE_CTRL0_N_FILT_0_MASK            (0xF000U)
#define TEMPSENSE_CTRL0_N_FILT_0_SHIFT           (12U)
#define TEMPSENSE_CTRL0_N_FILT_0_WIDTH           (4U)
#define TEMPSENSE_CTRL0_N_FILT_0(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_N_FILT_0_SHIFT)) & TEMPSENSE_CTRL0_N_FILT_0_MASK)

#define TEMPSENSE_CTRL0_DRDY0_IE_MASK            (0x10000U)
#define TEMPSENSE_CTRL0_DRDY0_IE_SHIFT           (16U)
#define TEMPSENSE_CTRL0_DRDY0_IE_WIDTH           (1U)
#define TEMPSENSE_CTRL0_DRDY0_IE(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_DRDY0_IE_SHIFT)) & TEMPSENSE_CTRL0_DRDY0_IE_MASK)

#define TEMPSENSE_CTRL0_FILT0_CNT_CLR_MASK       (0x100000U)
#define TEMPSENSE_CTRL0_FILT0_CNT_CLR_SHIFT      (20U)
#define TEMPSENSE_CTRL0_FILT0_CNT_CLR_WIDTH      (1U)
#define TEMPSENSE_CTRL0_FILT0_CNT_CLR(x)         (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_FILT0_CNT_CLR_SHIFT)) & TEMPSENSE_CTRL0_FILT0_CNT_CLR_MASK)

#define TEMPSENSE_CTRL0_FILT1_CNT_CLR_MASK       (0x200000U)
#define TEMPSENSE_CTRL0_FILT1_CNT_CLR_SHIFT      (21U)
#define TEMPSENSE_CTRL0_FILT1_CNT_CLR_WIDTH      (1U)
#define TEMPSENSE_CTRL0_FILT1_CNT_CLR(x)         (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_FILT1_CNT_CLR_SHIFT)) & TEMPSENSE_CTRL0_FILT1_CNT_CLR_MASK)

#define TEMPSENSE_CTRL0_FILT2_CNT_CLR_MASK       (0x400000U)
#define TEMPSENSE_CTRL0_FILT2_CNT_CLR_SHIFT      (22U)
#define TEMPSENSE_CTRL0_FILT2_CNT_CLR_WIDTH      (1U)
#define TEMPSENSE_CTRL0_FILT2_CNT_CLR(x)         (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL0_FILT2_CNT_CLR_SHIFT)) & TEMPSENSE_CTRL0_FILT2_CNT_CLR_MASK)
/*! @} */

/*! @name STAT0 - Status 0 */
/*! @{ */

#define TEMPSENSE_STAT0_THR0_IF_MASK             (0x100U)
#define TEMPSENSE_STAT0_THR0_IF_SHIFT            (8U)
#define TEMPSENSE_STAT0_THR0_IF_WIDTH            (1U)
#define TEMPSENSE_STAT0_THR0_IF(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_THR0_IF_SHIFT)) & TEMPSENSE_STAT0_THR0_IF_MASK)

#define TEMPSENSE_STAT0_THR1_IF_MASK             (0x200U)
#define TEMPSENSE_STAT0_THR1_IF_SHIFT            (9U)
#define TEMPSENSE_STAT0_THR1_IF_WIDTH            (1U)
#define TEMPSENSE_STAT0_THR1_IF(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_THR1_IF_SHIFT)) & TEMPSENSE_STAT0_THR1_IF_MASK)

#define TEMPSENSE_STAT0_THR2_IF_MASK             (0x400U)
#define TEMPSENSE_STAT0_THR2_IF_SHIFT            (10U)
#define TEMPSENSE_STAT0_THR2_IF_WIDTH            (1U)
#define TEMPSENSE_STAT0_THR2_IF(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_THR2_IF_SHIFT)) & TEMPSENSE_STAT0_THR2_IF_MASK)

#define TEMPSENSE_STAT0_THR0_STAT_MASK           (0x1000U)
#define TEMPSENSE_STAT0_THR0_STAT_SHIFT          (12U)
#define TEMPSENSE_STAT0_THR0_STAT_WIDTH          (1U)
#define TEMPSENSE_STAT0_THR0_STAT(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_THR0_STAT_SHIFT)) & TEMPSENSE_STAT0_THR0_STAT_MASK)

#define TEMPSENSE_STAT0_THR1_STAT_MASK           (0x2000U)
#define TEMPSENSE_STAT0_THR1_STAT_SHIFT          (13U)
#define TEMPSENSE_STAT0_THR1_STAT_WIDTH          (1U)
#define TEMPSENSE_STAT0_THR1_STAT(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_THR1_STAT_SHIFT)) & TEMPSENSE_STAT0_THR1_STAT_MASK)

#define TEMPSENSE_STAT0_THR2_STAT_MASK           (0x4000U)
#define TEMPSENSE_STAT0_THR2_STAT_SHIFT          (14U)
#define TEMPSENSE_STAT0_THR2_STAT_WIDTH          (1U)
#define TEMPSENSE_STAT0_THR2_STAT(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_THR2_STAT_SHIFT)) & TEMPSENSE_STAT0_THR2_STAT_MASK)

#define TEMPSENSE_STAT0_DRDY0_IF_MASK            (0x10000U)
#define TEMPSENSE_STAT0_DRDY0_IF_SHIFT           (16U)
#define TEMPSENSE_STAT0_DRDY0_IF_WIDTH           (1U)
#define TEMPSENSE_STAT0_DRDY0_IF(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_DRDY0_IF_SHIFT)) & TEMPSENSE_STAT0_DRDY0_IF_MASK)

#define TEMPSENSE_STAT0_IDLE_MASK                (0x80000000U)
#define TEMPSENSE_STAT0_IDLE_SHIFT               (31U)
#define TEMPSENSE_STAT0_IDLE_WIDTH               (1U)
#define TEMPSENSE_STAT0_IDLE(x)                  (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT0_IDLE_SHIFT)) & TEMPSENSE_STAT0_IDLE_MASK)
/*! @} */

/*! @name DATA0 - Data 0 */
/*! @{ */

#define TEMPSENSE_DATA0_DATA_VAL_MASK            (0xFFFFU)
#define TEMPSENSE_DATA0_DATA_VAL_SHIFT           (0U)
#define TEMPSENSE_DATA0_DATA_VAL_WIDTH           (16U)
#define TEMPSENSE_DATA0_DATA_VAL(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_DATA0_DATA_VAL_SHIFT)) & TEMPSENSE_DATA0_DATA_VAL_MASK)
/*! @} */

/*! @name THR_CTRL01 - Threshold Control 01 */
/*! @{ */

#define TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD0_MASK (0xFFFFU)
#define TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD0_SHIFT (0U)
#define TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD0_WIDTH (16U)
#define TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD0(x) (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD0_SHIFT)) & TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD0_MASK)

#define TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD1_MASK (0xFFFF0000U)
#define TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD1_SHIFT (16U)
#define TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD1_WIDTH (16U)
#define TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD1(x) (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD1_SHIFT)) & TEMPSENSE_THR_CTRL01_TEMPERATURE_THRESHOLD1_MASK)
/*! @} */

/*! @name THR_CTRL23 - Threshold Control 23 */
/*! @{ */

#define TEMPSENSE_THR_CTRL23_TEMPERATURE_THRESHOLD2_MASK (0xFFFFU)
#define TEMPSENSE_THR_CTRL23_TEMPERATURE_THRESHOLD2_SHIFT (0U)
#define TEMPSENSE_THR_CTRL23_TEMPERATURE_THRESHOLD2_WIDTH (16U)
#define TEMPSENSE_THR_CTRL23_TEMPERATURE_THRESHOLD2(x) (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_THR_CTRL23_TEMPERATURE_THRESHOLD2_SHIFT)) & TEMPSENSE_THR_CTRL23_TEMPERATURE_THRESHOLD2_MASK)
/*! @} */

/*! @name CTRL1 - Control 1 */
/*! @{ */

#define TEMPSENSE_CTRL1_THR4_MODE_MASK           (0x3U)
#define TEMPSENSE_CTRL1_THR4_MODE_SHIFT          (0U)
#define TEMPSENSE_CTRL1_THR4_MODE_WIDTH          (2U)
#define TEMPSENSE_CTRL1_THR4_MODE(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_THR4_MODE_SHIFT)) & TEMPSENSE_CTRL1_THR4_MODE_MASK)

#define TEMPSENSE_CTRL1_THR5_MODE_MASK           (0xCU)
#define TEMPSENSE_CTRL1_THR5_MODE_SHIFT          (2U)
#define TEMPSENSE_CTRL1_THR5_MODE_WIDTH          (2U)
#define TEMPSENSE_CTRL1_THR5_MODE(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_THR5_MODE_SHIFT)) & TEMPSENSE_CTRL1_THR5_MODE_MASK)

#define TEMPSENSE_CTRL1_THR4_IE_MASK             (0x100U)
#define TEMPSENSE_CTRL1_THR4_IE_SHIFT            (8U)
#define TEMPSENSE_CTRL1_THR4_IE_WIDTH            (1U)
#define TEMPSENSE_CTRL1_THR4_IE(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_THR4_IE_SHIFT)) & TEMPSENSE_CTRL1_THR4_IE_MASK)

#define TEMPSENSE_CTRL1_THR5_IE_MASK             (0x200U)
#define TEMPSENSE_CTRL1_THR5_IE_SHIFT            (9U)
#define TEMPSENSE_CTRL1_THR5_IE_WIDTH            (1U)
#define TEMPSENSE_CTRL1_THR5_IE(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_THR5_IE_SHIFT)) & TEMPSENSE_CTRL1_THR5_IE_MASK)

#define TEMPSENSE_CTRL1_N_FILT_1_MASK            (0xF000U)
#define TEMPSENSE_CTRL1_N_FILT_1_SHIFT           (12U)
#define TEMPSENSE_CTRL1_N_FILT_1_WIDTH           (4U)
#define TEMPSENSE_CTRL1_N_FILT_1(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_N_FILT_1_SHIFT)) & TEMPSENSE_CTRL1_N_FILT_1_MASK)

#define TEMPSENSE_CTRL1_DRDY1_IE_MASK            (0x10000U)
#define TEMPSENSE_CTRL1_DRDY1_IE_SHIFT           (16U)
#define TEMPSENSE_CTRL1_DRDY1_IE_WIDTH           (1U)
#define TEMPSENSE_CTRL1_DRDY1_IE(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_DRDY1_IE_SHIFT)) & TEMPSENSE_CTRL1_DRDY1_IE_MASK)

#define TEMPSENSE_CTRL1_RESOLUTION_MASK          (0xC0000U)
#define TEMPSENSE_CTRL1_RESOLUTION_SHIFT         (18U)
#define TEMPSENSE_CTRL1_RESOLUTION_WIDTH         (2U)
#define TEMPSENSE_CTRL1_RESOLUTION(x)            (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_RESOLUTION_SHIFT)) & TEMPSENSE_CTRL1_RESOLUTION_MASK)

#define TEMPSENSE_CTRL1_FILT4_CNT_CLR_MASK       (0x100000U)
#define TEMPSENSE_CTRL1_FILT4_CNT_CLR_SHIFT      (20U)
#define TEMPSENSE_CTRL1_FILT4_CNT_CLR_WIDTH      (1U)
#define TEMPSENSE_CTRL1_FILT4_CNT_CLR(x)         (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_FILT4_CNT_CLR_SHIFT)) & TEMPSENSE_CTRL1_FILT4_CNT_CLR_MASK)

#define TEMPSENSE_CTRL1_FILT5_CNT_CLR_MASK       (0x200000U)
#define TEMPSENSE_CTRL1_FILT5_CNT_CLR_SHIFT      (21U)
#define TEMPSENSE_CTRL1_FILT5_CNT_CLR_WIDTH      (1U)
#define TEMPSENSE_CTRL1_FILT5_CNT_CLR(x)         (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_FILT5_CNT_CLR_SHIFT)) & TEMPSENSE_CTRL1_FILT5_CNT_CLR_MASK)

#define TEMPSENSE_CTRL1_MEAS_MODE_MASK           (0x3000000U)
#define TEMPSENSE_CTRL1_MEAS_MODE_SHIFT          (24U)
#define TEMPSENSE_CTRL1_MEAS_MODE_WIDTH          (2U)
#define TEMPSENSE_CTRL1_MEAS_MODE(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_MEAS_MODE_SHIFT)) & TEMPSENSE_CTRL1_MEAS_MODE_MASK)

#define TEMPSENSE_CTRL1_STOP_MASK                (0x20000000U)
#define TEMPSENSE_CTRL1_STOP_SHIFT               (29U)
#define TEMPSENSE_CTRL1_STOP_WIDTH               (1U)
#define TEMPSENSE_CTRL1_STOP(x)                  (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_STOP_SHIFT)) & TEMPSENSE_CTRL1_STOP_MASK)

#define TEMPSENSE_CTRL1_START_MASK               (0x40000000U)
#define TEMPSENSE_CTRL1_START_SHIFT              (30U)
#define TEMPSENSE_CTRL1_START_WIDTH              (1U)
#define TEMPSENSE_CTRL1_START(x)                 (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_START_SHIFT)) & TEMPSENSE_CTRL1_START_MASK)

#define TEMPSENSE_CTRL1_ENABLE_MASK              (0x80000000U)
#define TEMPSENSE_CTRL1_ENABLE_SHIFT             (31U)
#define TEMPSENSE_CTRL1_ENABLE_WIDTH             (1U)
#define TEMPSENSE_CTRL1_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_CTRL1_ENABLE_SHIFT)) & TEMPSENSE_CTRL1_ENABLE_MASK)
/*! @} */

/*! @name STAT1 - Status 1 */
/*! @{ */

#define TEMPSENSE_STAT1_THR4_IF_MASK             (0x100U)
#define TEMPSENSE_STAT1_THR4_IF_SHIFT            (8U)
#define TEMPSENSE_STAT1_THR4_IF_WIDTH            (1U)
#define TEMPSENSE_STAT1_THR4_IF(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT1_THR4_IF_SHIFT)) & TEMPSENSE_STAT1_THR4_IF_MASK)

#define TEMPSENSE_STAT1_THR5_IF_MASK             (0x200U)
#define TEMPSENSE_STAT1_THR5_IF_SHIFT            (9U)
#define TEMPSENSE_STAT1_THR5_IF_WIDTH            (1U)
#define TEMPSENSE_STAT1_THR5_IF(x)               (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT1_THR5_IF_SHIFT)) & TEMPSENSE_STAT1_THR5_IF_MASK)

#define TEMPSENSE_STAT1_THR4_STAT_MASK           (0x1000U)
#define TEMPSENSE_STAT1_THR4_STAT_SHIFT          (12U)
#define TEMPSENSE_STAT1_THR4_STAT_WIDTH          (1U)
#define TEMPSENSE_STAT1_THR4_STAT(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT1_THR4_STAT_SHIFT)) & TEMPSENSE_STAT1_THR4_STAT_MASK)

#define TEMPSENSE_STAT1_THR5_STAT_MASK           (0x2000U)
#define TEMPSENSE_STAT1_THR5_STAT_SHIFT          (13U)
#define TEMPSENSE_STAT1_THR5_STAT_WIDTH          (1U)
#define TEMPSENSE_STAT1_THR5_STAT(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT1_THR5_STAT_SHIFT)) & TEMPSENSE_STAT1_THR5_STAT_MASK)

#define TEMPSENSE_STAT1_DRDY1_IF_MASK            (0x10000U)
#define TEMPSENSE_STAT1_DRDY1_IF_SHIFT           (16U)
#define TEMPSENSE_STAT1_DRDY1_IF_WIDTH           (1U)
#define TEMPSENSE_STAT1_DRDY1_IF(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT1_DRDY1_IF_SHIFT)) & TEMPSENSE_STAT1_DRDY1_IF_MASK)

#define TEMPSENSE_STAT1_IDLE_MASK                (0x80000000U)
#define TEMPSENSE_STAT1_IDLE_SHIFT               (31U)
#define TEMPSENSE_STAT1_IDLE_WIDTH               (1U)
#define TEMPSENSE_STAT1_IDLE(x)                  (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_STAT1_IDLE_SHIFT)) & TEMPSENSE_STAT1_IDLE_MASK)
/*! @} */

/*! @name DATA1 - Data 1 */
/*! @{ */

#define TEMPSENSE_DATA1_DATA_VAL_MASK            (0xFFFFU)
#define TEMPSENSE_DATA1_DATA_VAL_SHIFT           (0U)
#define TEMPSENSE_DATA1_DATA_VAL_WIDTH           (16U)
#define TEMPSENSE_DATA1_DATA_VAL(x)              (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_DATA1_DATA_VAL_SHIFT)) & TEMPSENSE_DATA1_DATA_VAL_MASK)
/*! @} */

/*! @name THR_CTRL45 - Threshold Control 45 */
/*! @{ */

#define TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD4_MASK (0xFFFFU)
#define TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD4_SHIFT (0U)
#define TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD4_WIDTH (16U)
#define TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD4(x) (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD4_SHIFT)) & TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD4_MASK)

#define TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD5_MASK (0xFFFF0000U)
#define TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD5_SHIFT (16U)
#define TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD5_WIDTH (16U)
#define TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD5(x) (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD5_SHIFT)) & TEMPSENSE_THR_CTRL45_TEMPERATURE_THRESHOLD5_MASK)
/*! @} */

/*! @name PERIOD_CTRL - Measurement Period Control */
/*! @{ */

#define TEMPSENSE_PERIOD_CTRL_MEAS_FREQ_MASK     (0xFFFFFFU)
#define TEMPSENSE_PERIOD_CTRL_MEAS_FREQ_SHIFT    (0U)
#define TEMPSENSE_PERIOD_CTRL_MEAS_FREQ_WIDTH    (24U)
#define TEMPSENSE_PERIOD_CTRL_MEAS_FREQ(x)       (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_PERIOD_CTRL_MEAS_FREQ_SHIFT)) & TEMPSENSE_PERIOD_CTRL_MEAS_FREQ_MASK)
/*! @} */

/*! @name REF_DIV - Reference Clock Divider Control */
/*! @{ */

#define TEMPSENSE_REF_DIV_DIV_MASK               (0xFF0000U)
#define TEMPSENSE_REF_DIV_DIV_SHIFT              (16U)
#define TEMPSENSE_REF_DIV_DIV_WIDTH              (8U)
#define TEMPSENSE_REF_DIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_REF_DIV_DIV_SHIFT)) & TEMPSENSE_REF_DIV_DIV_MASK)

#define TEMPSENSE_REF_DIV_DE_MASK                (0x80000000U)
#define TEMPSENSE_REF_DIV_DE_SHIFT               (31U)
#define TEMPSENSE_REF_DIV_DE_WIDTH               (1U)
#define TEMPSENSE_REF_DIV_DE(x)                  (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_REF_DIV_DE_SHIFT)) & TEMPSENSE_REF_DIV_DE_MASK)
/*! @} */

/*! @name PUD_ST_CTRL - Power-Up Delay Control */
/*! @{ */

#define TEMPSENSE_PUD_ST_CTRL_PUD_MASK           (0xFF0000U)
#define TEMPSENSE_PUD_ST_CTRL_PUD_SHIFT          (16U)
#define TEMPSENSE_PUD_ST_CTRL_PUD_WIDTH          (8U)
#define TEMPSENSE_PUD_ST_CTRL_PUD(x)             (((uint32_t)(((uint32_t)(x)) << TEMPSENSE_PUD_ST_CTRL_PUD_SHIFT)) & TEMPSENSE_PUD_ST_CTRL_PUD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group TEMPSENSE_Register_Masks */

/*!
 * @}
 */ /* end of group TEMPSENSE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_TEMPSENSE_H_) */
