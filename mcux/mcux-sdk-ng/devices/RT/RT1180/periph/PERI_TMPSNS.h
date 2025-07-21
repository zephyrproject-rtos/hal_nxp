/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TMPSNS
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_TMPSNS.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TMPSNS
 *
 * CMSIS Peripheral Access Layer for TMPSNS
 */

#if !defined(PERI_TMPSNS_H_)
#define PERI_TMPSNS_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- TMPSNS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMPSNS_Peripheral_Access_Layer TMPSNS Peripheral Access Layer
 * @{
 */

/** TMPSNS - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t CTRL1;                             /**< Control 1, offset: 0x10 */
  __IO uint32_t CTRL1_SET;                         /**< Control 1, offset: 0x14 */
  __IO uint32_t CTRL1_CLR;                         /**< Control 1, offset: 0x18 */
  __IO uint32_t CTRL1_TOG;                         /**< Control 1, offset: 0x1C */
  __IO uint32_t RANGE0;                            /**< Range 0, offset: 0x20 */
  __IO uint32_t RANGE0_SET;                        /**< Range 0, offset: 0x24 */
  __IO uint32_t RANGE0_CLR;                        /**< Range 0, offset: 0x28 */
  __IO uint32_t RANGE0_TOG;                        /**< Range 0, offset: 0x2C */
  __IO uint32_t RANGE1;                            /**< Range 1, offset: 0x30 */
  __IO uint32_t RANGE1_SET;                        /**< Range 1, offset: 0x34 */
  __IO uint32_t RANGE1_CLR;                        /**< Range 1, offset: 0x38 */
  __IO uint32_t RANGE1_TOG;                        /**< Range 1, offset: 0x3C */
       uint8_t RESERVED_1[16];
  __IO uint32_t STATUS0;                           /**< Status 0, offset: 0x50 */
} TMPSNS_Type;

/* ----------------------------------------------------------------------------
   -- TMPSNS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMPSNS_Register_Masks TMPSNS Register Masks
 * @{
 */

/*! @name CTRL1 - Control 1 */
/*! @{ */

#define TMPSNS_CTRL1_FREQ_MASK                   (0xFFFFU)
#define TMPSNS_CTRL1_FREQ_SHIFT                  (0U)
/*! FREQ - Temperature Measurement Frequency
 *  0b0000000000000000..Single Reading Mode. A new reading is available every time you change START from 0 to 1.
 *  0b0000000000000001-0b1111111111111111..Continuous Reading Mode. TMPSNS takes the next temperature reading when
 *                                         it completes the programmed number of cycles after the current reading.
 */
#define TMPSNS_CTRL1_FREQ(x)                     (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_FREQ_SHIFT)) & TMPSNS_CTRL1_FREQ_MASK)

#define TMPSNS_CTRL1_FINISH_IE_MASK              (0x10000U)
#define TMPSNS_CTRL1_FINISH_IE_SHIFT             (16U)
/*! FINISH_IE - Measurement Finished Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TMPSNS_CTRL1_FINISH_IE(x)                (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_FINISH_IE_SHIFT)) & TMPSNS_CTRL1_FINISH_IE_MASK)

#define TMPSNS_CTRL1_LOW_TEMP_IE_MASK            (0x20000U)
#define TMPSNS_CTRL1_LOW_TEMP_IE_SHIFT           (17U)
/*! LOW_TEMP_IE - Low Temperature Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TMPSNS_CTRL1_LOW_TEMP_IE(x)              (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_LOW_TEMP_IE_SHIFT)) & TMPSNS_CTRL1_LOW_TEMP_IE_MASK)

#define TMPSNS_CTRL1_HIGH_TEMP_IE_MASK           (0x40000U)
#define TMPSNS_CTRL1_HIGH_TEMP_IE_SHIFT          (18U)
/*! HIGH_TEMP_IE - High Temperature Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TMPSNS_CTRL1_HIGH_TEMP_IE(x)             (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_HIGH_TEMP_IE_SHIFT)) & TMPSNS_CTRL1_HIGH_TEMP_IE_MASK)

#define TMPSNS_CTRL1_PANIC_TEMP_IE_MASK          (0x80000U)
#define TMPSNS_CTRL1_PANIC_TEMP_IE_SHIFT         (19U)
/*! PANIC_TEMP_IE - Panic Temperature Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define TMPSNS_CTRL1_PANIC_TEMP_IE(x)            (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_PANIC_TEMP_IE_SHIFT)) & TMPSNS_CTRL1_PANIC_TEMP_IE_MASK)

#define TMPSNS_CTRL1_START_MASK                  (0x400000U)
#define TMPSNS_CTRL1_START_SHIFT                 (22U)
/*! START - Start Temperature Measurement
 *  0b0..No read
 *  0b1..New read
 */
#define TMPSNS_CTRL1_START(x)                    (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_START_SHIFT)) & TMPSNS_CTRL1_START_MASK)

#define TMPSNS_CTRL1_PWD_MASK                    (0x800000U)
#define TMPSNS_CTRL1_PWD_SHIFT                   (23U)
/*! PWD - Power Down Except Bias Current
 *  0b0..Active
 *  0b1..Inactive
 */
#define TMPSNS_CTRL1_PWD(x)                      (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_PWD_SHIFT)) & TMPSNS_CTRL1_PWD_MASK)

#define TMPSNS_CTRL1_PWD_FULL_MASK               (0x80000000U)
#define TMPSNS_CTRL1_PWD_FULL_SHIFT              (31U)
/*! PWD_FULL - Power Down
 *  0b0..Active
 *  0b1..Inactive
 */
#define TMPSNS_CTRL1_PWD_FULL(x)                 (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_PWD_FULL_SHIFT)) & TMPSNS_CTRL1_PWD_FULL_MASK)
/*! @} */

/*! @name CTRL1_SET - Control 1 */
/*! @{ */

#define TMPSNS_CTRL1_SET_FREQ_MASK               (0xFFFFU)
#define TMPSNS_CTRL1_SET_FREQ_SHIFT              (0U)
/*! FREQ - Temperature Measurement Frequency */
#define TMPSNS_CTRL1_SET_FREQ(x)                 (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_SET_FREQ_SHIFT)) & TMPSNS_CTRL1_SET_FREQ_MASK)

#define TMPSNS_CTRL1_SET_FINISH_IE_MASK          (0x10000U)
#define TMPSNS_CTRL1_SET_FINISH_IE_SHIFT         (16U)
/*! FINISH_IE - Measurement Finished Interrupt Enable */
#define TMPSNS_CTRL1_SET_FINISH_IE(x)            (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_SET_FINISH_IE_SHIFT)) & TMPSNS_CTRL1_SET_FINISH_IE_MASK)

#define TMPSNS_CTRL1_SET_LOW_TEMP_IE_MASK        (0x20000U)
#define TMPSNS_CTRL1_SET_LOW_TEMP_IE_SHIFT       (17U)
/*! LOW_TEMP_IE - Low Temperature Interrupt Enable */
#define TMPSNS_CTRL1_SET_LOW_TEMP_IE(x)          (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_SET_LOW_TEMP_IE_SHIFT)) & TMPSNS_CTRL1_SET_LOW_TEMP_IE_MASK)

#define TMPSNS_CTRL1_SET_HIGH_TEMP_IE_MASK       (0x40000U)
#define TMPSNS_CTRL1_SET_HIGH_TEMP_IE_SHIFT      (18U)
/*! HIGH_TEMP_IE - High Temperature Interrupt Enable */
#define TMPSNS_CTRL1_SET_HIGH_TEMP_IE(x)         (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_SET_HIGH_TEMP_IE_SHIFT)) & TMPSNS_CTRL1_SET_HIGH_TEMP_IE_MASK)

#define TMPSNS_CTRL1_SET_PANIC_TEMP_IE_MASK      (0x80000U)
#define TMPSNS_CTRL1_SET_PANIC_TEMP_IE_SHIFT     (19U)
/*! PANIC_TEMP_IE - Panic Temperature Interrupt Enable */
#define TMPSNS_CTRL1_SET_PANIC_TEMP_IE(x)        (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_SET_PANIC_TEMP_IE_SHIFT)) & TMPSNS_CTRL1_SET_PANIC_TEMP_IE_MASK)

#define TMPSNS_CTRL1_SET_START_MASK              (0x400000U)
#define TMPSNS_CTRL1_SET_START_SHIFT             (22U)
/*! START - Start Temperature Measurement */
#define TMPSNS_CTRL1_SET_START(x)                (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_SET_START_SHIFT)) & TMPSNS_CTRL1_SET_START_MASK)

#define TMPSNS_CTRL1_SET_PWD_MASK                (0x800000U)
#define TMPSNS_CTRL1_SET_PWD_SHIFT               (23U)
/*! PWD - Power Down Except Bias Current */
#define TMPSNS_CTRL1_SET_PWD(x)                  (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_SET_PWD_SHIFT)) & TMPSNS_CTRL1_SET_PWD_MASK)

#define TMPSNS_CTRL1_SET_PWD_FULL_MASK           (0x80000000U)
#define TMPSNS_CTRL1_SET_PWD_FULL_SHIFT          (31U)
/*! PWD_FULL - Power Down */
#define TMPSNS_CTRL1_SET_PWD_FULL(x)             (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_SET_PWD_FULL_SHIFT)) & TMPSNS_CTRL1_SET_PWD_FULL_MASK)
/*! @} */

/*! @name CTRL1_CLR - Control 1 */
/*! @{ */

#define TMPSNS_CTRL1_CLR_FREQ_MASK               (0xFFFFU)
#define TMPSNS_CTRL1_CLR_FREQ_SHIFT              (0U)
/*! FREQ - Temperature Measurement Frequency */
#define TMPSNS_CTRL1_CLR_FREQ(x)                 (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_CLR_FREQ_SHIFT)) & TMPSNS_CTRL1_CLR_FREQ_MASK)

#define TMPSNS_CTRL1_CLR_FINISH_IE_MASK          (0x10000U)
#define TMPSNS_CTRL1_CLR_FINISH_IE_SHIFT         (16U)
/*! FINISH_IE - Measurement Finished Interrupt Enable */
#define TMPSNS_CTRL1_CLR_FINISH_IE(x)            (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_CLR_FINISH_IE_SHIFT)) & TMPSNS_CTRL1_CLR_FINISH_IE_MASK)

#define TMPSNS_CTRL1_CLR_LOW_TEMP_IE_MASK        (0x20000U)
#define TMPSNS_CTRL1_CLR_LOW_TEMP_IE_SHIFT       (17U)
/*! LOW_TEMP_IE - Low Temperature Interrupt Enable */
#define TMPSNS_CTRL1_CLR_LOW_TEMP_IE(x)          (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_CLR_LOW_TEMP_IE_SHIFT)) & TMPSNS_CTRL1_CLR_LOW_TEMP_IE_MASK)

#define TMPSNS_CTRL1_CLR_HIGH_TEMP_IE_MASK       (0x40000U)
#define TMPSNS_CTRL1_CLR_HIGH_TEMP_IE_SHIFT      (18U)
/*! HIGH_TEMP_IE - High Temperature Interrupt Enable */
#define TMPSNS_CTRL1_CLR_HIGH_TEMP_IE(x)         (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_CLR_HIGH_TEMP_IE_SHIFT)) & TMPSNS_CTRL1_CLR_HIGH_TEMP_IE_MASK)

#define TMPSNS_CTRL1_CLR_PANIC_TEMP_IE_MASK      (0x80000U)
#define TMPSNS_CTRL1_CLR_PANIC_TEMP_IE_SHIFT     (19U)
/*! PANIC_TEMP_IE - Panic Temperature Interrupt Enable */
#define TMPSNS_CTRL1_CLR_PANIC_TEMP_IE(x)        (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_CLR_PANIC_TEMP_IE_SHIFT)) & TMPSNS_CTRL1_CLR_PANIC_TEMP_IE_MASK)

#define TMPSNS_CTRL1_CLR_START_MASK              (0x400000U)
#define TMPSNS_CTRL1_CLR_START_SHIFT             (22U)
/*! START - Start Temperature Measurement */
#define TMPSNS_CTRL1_CLR_START(x)                (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_CLR_START_SHIFT)) & TMPSNS_CTRL1_CLR_START_MASK)

#define TMPSNS_CTRL1_CLR_PWD_MASK                (0x800000U)
#define TMPSNS_CTRL1_CLR_PWD_SHIFT               (23U)
/*! PWD - Power Down Except Bias Current */
#define TMPSNS_CTRL1_CLR_PWD(x)                  (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_CLR_PWD_SHIFT)) & TMPSNS_CTRL1_CLR_PWD_MASK)

#define TMPSNS_CTRL1_CLR_PWD_FULL_MASK           (0x80000000U)
#define TMPSNS_CTRL1_CLR_PWD_FULL_SHIFT          (31U)
/*! PWD_FULL - Power Down */
#define TMPSNS_CTRL1_CLR_PWD_FULL(x)             (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_CLR_PWD_FULL_SHIFT)) & TMPSNS_CTRL1_CLR_PWD_FULL_MASK)
/*! @} */

/*! @name CTRL1_TOG - Control 1 */
/*! @{ */

#define TMPSNS_CTRL1_TOG_FREQ_MASK               (0xFFFFU)
#define TMPSNS_CTRL1_TOG_FREQ_SHIFT              (0U)
/*! FREQ - Temperature Measurement Frequency */
#define TMPSNS_CTRL1_TOG_FREQ(x)                 (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_TOG_FREQ_SHIFT)) & TMPSNS_CTRL1_TOG_FREQ_MASK)

#define TMPSNS_CTRL1_TOG_FINISH_IE_MASK          (0x10000U)
#define TMPSNS_CTRL1_TOG_FINISH_IE_SHIFT         (16U)
/*! FINISH_IE - Measurement Finished Interrupt Enable */
#define TMPSNS_CTRL1_TOG_FINISH_IE(x)            (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_TOG_FINISH_IE_SHIFT)) & TMPSNS_CTRL1_TOG_FINISH_IE_MASK)

#define TMPSNS_CTRL1_TOG_LOW_TEMP_IE_MASK        (0x20000U)
#define TMPSNS_CTRL1_TOG_LOW_TEMP_IE_SHIFT       (17U)
/*! LOW_TEMP_IE - Low Temperature Interrupt Enable */
#define TMPSNS_CTRL1_TOG_LOW_TEMP_IE(x)          (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_TOG_LOW_TEMP_IE_SHIFT)) & TMPSNS_CTRL1_TOG_LOW_TEMP_IE_MASK)

#define TMPSNS_CTRL1_TOG_HIGH_TEMP_IE_MASK       (0x40000U)
#define TMPSNS_CTRL1_TOG_HIGH_TEMP_IE_SHIFT      (18U)
/*! HIGH_TEMP_IE - High Temperature Interrupt Enable */
#define TMPSNS_CTRL1_TOG_HIGH_TEMP_IE(x)         (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_TOG_HIGH_TEMP_IE_SHIFT)) & TMPSNS_CTRL1_TOG_HIGH_TEMP_IE_MASK)

#define TMPSNS_CTRL1_TOG_PANIC_TEMP_IE_MASK      (0x80000U)
#define TMPSNS_CTRL1_TOG_PANIC_TEMP_IE_SHIFT     (19U)
/*! PANIC_TEMP_IE - Panic Temperature Interrupt Enable */
#define TMPSNS_CTRL1_TOG_PANIC_TEMP_IE(x)        (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_TOG_PANIC_TEMP_IE_SHIFT)) & TMPSNS_CTRL1_TOG_PANIC_TEMP_IE_MASK)

#define TMPSNS_CTRL1_TOG_START_MASK              (0x400000U)
#define TMPSNS_CTRL1_TOG_START_SHIFT             (22U)
/*! START - Start Temperature Measurement */
#define TMPSNS_CTRL1_TOG_START(x)                (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_TOG_START_SHIFT)) & TMPSNS_CTRL1_TOG_START_MASK)

#define TMPSNS_CTRL1_TOG_PWD_MASK                (0x800000U)
#define TMPSNS_CTRL1_TOG_PWD_SHIFT               (23U)
/*! PWD - Power Down Except Bias Current */
#define TMPSNS_CTRL1_TOG_PWD(x)                  (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_TOG_PWD_SHIFT)) & TMPSNS_CTRL1_TOG_PWD_MASK)

#define TMPSNS_CTRL1_TOG_PWD_FULL_MASK           (0x80000000U)
#define TMPSNS_CTRL1_TOG_PWD_FULL_SHIFT          (31U)
/*! PWD_FULL - Power Down */
#define TMPSNS_CTRL1_TOG_PWD_FULL(x)             (((uint32_t)(((uint32_t)(x)) << TMPSNS_CTRL1_TOG_PWD_FULL_SHIFT)) & TMPSNS_CTRL1_TOG_PWD_FULL_MASK)
/*! @} */

/*! @name RANGE0 - Range 0 */
/*! @{ */

#define TMPSNS_RANGE0_LOW_TEMP_VAL_MASK          (0xFFFU)
#define TMPSNS_RANGE0_LOW_TEMP_VAL_SHIFT         (0U)
/*! LOW_TEMP_VAL - Low Temperature Threshold Value */
#define TMPSNS_RANGE0_LOW_TEMP_VAL(x)            (((uint32_t)(((uint32_t)(x)) << TMPSNS_RANGE0_LOW_TEMP_VAL_SHIFT)) & TMPSNS_RANGE0_LOW_TEMP_VAL_MASK)

#define TMPSNS_RANGE0_HIGH_TEMP_VAL_MASK         (0xFFF0000U)
#define TMPSNS_RANGE0_HIGH_TEMP_VAL_SHIFT        (16U)
/*! HIGH_TEMP_VAL - High Temperature Threshold Value */
#define TMPSNS_RANGE0_HIGH_TEMP_VAL(x)           (((uint32_t)(((uint32_t)(x)) << TMPSNS_RANGE0_HIGH_TEMP_VAL_SHIFT)) & TMPSNS_RANGE0_HIGH_TEMP_VAL_MASK)
/*! @} */

/*! @name RANGE0_SET - Range 0 */
/*! @{ */

#define TMPSNS_RANGE0_SET_LOW_TEMP_VAL_MASK      (0xFFFU)
#define TMPSNS_RANGE0_SET_LOW_TEMP_VAL_SHIFT     (0U)
/*! LOW_TEMP_VAL - Low Temperature Threshold Value */
#define TMPSNS_RANGE0_SET_LOW_TEMP_VAL(x)        (((uint32_t)(((uint32_t)(x)) << TMPSNS_RANGE0_SET_LOW_TEMP_VAL_SHIFT)) & TMPSNS_RANGE0_SET_LOW_TEMP_VAL_MASK)

#define TMPSNS_RANGE0_SET_HIGH_TEMP_VAL_MASK     (0xFFF0000U)
#define TMPSNS_RANGE0_SET_HIGH_TEMP_VAL_SHIFT    (16U)
/*! HIGH_TEMP_VAL - High Temperature Threshold Value */
#define TMPSNS_RANGE0_SET_HIGH_TEMP_VAL(x)       (((uint32_t)(((uint32_t)(x)) << TMPSNS_RANGE0_SET_HIGH_TEMP_VAL_SHIFT)) & TMPSNS_RANGE0_SET_HIGH_TEMP_VAL_MASK)
/*! @} */

/*! @name RANGE0_CLR - Range 0 */
/*! @{ */

#define TMPSNS_RANGE0_CLR_LOW_TEMP_VAL_MASK      (0xFFFU)
#define TMPSNS_RANGE0_CLR_LOW_TEMP_VAL_SHIFT     (0U)
/*! LOW_TEMP_VAL - Low Temperature Threshold Value */
#define TMPSNS_RANGE0_CLR_LOW_TEMP_VAL(x)        (((uint32_t)(((uint32_t)(x)) << TMPSNS_RANGE0_CLR_LOW_TEMP_VAL_SHIFT)) & TMPSNS_RANGE0_CLR_LOW_TEMP_VAL_MASK)

#define TMPSNS_RANGE0_CLR_HIGH_TEMP_VAL_MASK     (0xFFF0000U)
#define TMPSNS_RANGE0_CLR_HIGH_TEMP_VAL_SHIFT    (16U)
/*! HIGH_TEMP_VAL - High Temperature Threshold Value */
#define TMPSNS_RANGE0_CLR_HIGH_TEMP_VAL(x)       (((uint32_t)(((uint32_t)(x)) << TMPSNS_RANGE0_CLR_HIGH_TEMP_VAL_SHIFT)) & TMPSNS_RANGE0_CLR_HIGH_TEMP_VAL_MASK)
/*! @} */

/*! @name RANGE0_TOG - Range 0 */
/*! @{ */

#define TMPSNS_RANGE0_TOG_LOW_TEMP_VAL_MASK      (0xFFFU)
#define TMPSNS_RANGE0_TOG_LOW_TEMP_VAL_SHIFT     (0U)
/*! LOW_TEMP_VAL - Low Temperature Threshold Value */
#define TMPSNS_RANGE0_TOG_LOW_TEMP_VAL(x)        (((uint32_t)(((uint32_t)(x)) << TMPSNS_RANGE0_TOG_LOW_TEMP_VAL_SHIFT)) & TMPSNS_RANGE0_TOG_LOW_TEMP_VAL_MASK)

#define TMPSNS_RANGE0_TOG_HIGH_TEMP_VAL_MASK     (0xFFF0000U)
#define TMPSNS_RANGE0_TOG_HIGH_TEMP_VAL_SHIFT    (16U)
/*! HIGH_TEMP_VAL - High Temperature Threshold Value */
#define TMPSNS_RANGE0_TOG_HIGH_TEMP_VAL(x)       (((uint32_t)(((uint32_t)(x)) << TMPSNS_RANGE0_TOG_HIGH_TEMP_VAL_SHIFT)) & TMPSNS_RANGE0_TOG_HIGH_TEMP_VAL_MASK)
/*! @} */

/*! @name RANGE1 - Range 1 */
/*! @{ */

#define TMPSNS_RANGE1_PANIC_TEMP_VAL_MASK        (0xFFFU)
#define TMPSNS_RANGE1_PANIC_TEMP_VAL_SHIFT       (0U)
/*! PANIC_TEMP_VAL - Panic Temperature Threshold Value */
#define TMPSNS_RANGE1_PANIC_TEMP_VAL(x)          (((uint32_t)(((uint32_t)(x)) << TMPSNS_RANGE1_PANIC_TEMP_VAL_SHIFT)) & TMPSNS_RANGE1_PANIC_TEMP_VAL_MASK)
/*! @} */

/*! @name RANGE1_SET - Range 1 */
/*! @{ */

#define TMPSNS_RANGE1_SET_PANIC_TEMP_VAL_MASK    (0xFFFU)
#define TMPSNS_RANGE1_SET_PANIC_TEMP_VAL_SHIFT   (0U)
/*! PANIC_TEMP_VAL - Panic Temperature Threshold Value */
#define TMPSNS_RANGE1_SET_PANIC_TEMP_VAL(x)      (((uint32_t)(((uint32_t)(x)) << TMPSNS_RANGE1_SET_PANIC_TEMP_VAL_SHIFT)) & TMPSNS_RANGE1_SET_PANIC_TEMP_VAL_MASK)
/*! @} */

/*! @name RANGE1_CLR - Range 1 */
/*! @{ */

#define TMPSNS_RANGE1_CLR_PANIC_TEMP_VAL_MASK    (0xFFFU)
#define TMPSNS_RANGE1_CLR_PANIC_TEMP_VAL_SHIFT   (0U)
/*! PANIC_TEMP_VAL - Panic Temperature Threshold Value */
#define TMPSNS_RANGE1_CLR_PANIC_TEMP_VAL(x)      (((uint32_t)(((uint32_t)(x)) << TMPSNS_RANGE1_CLR_PANIC_TEMP_VAL_SHIFT)) & TMPSNS_RANGE1_CLR_PANIC_TEMP_VAL_MASK)
/*! @} */

/*! @name RANGE1_TOG - Range 1 */
/*! @{ */

#define TMPSNS_RANGE1_TOG_PANIC_TEMP_VAL_MASK    (0xFFFU)
#define TMPSNS_RANGE1_TOG_PANIC_TEMP_VAL_SHIFT   (0U)
/*! PANIC_TEMP_VAL - Panic Temperature Threshold Value */
#define TMPSNS_RANGE1_TOG_PANIC_TEMP_VAL(x)      (((uint32_t)(((uint32_t)(x)) << TMPSNS_RANGE1_TOG_PANIC_TEMP_VAL_SHIFT)) & TMPSNS_RANGE1_TOG_PANIC_TEMP_VAL_MASK)
/*! @} */

/*! @name STATUS0 - Status 0 */
/*! @{ */

#define TMPSNS_STATUS0_TEMP_VAL_MASK             (0xFFFU)
#define TMPSNS_STATUS0_TEMP_VAL_SHIFT            (0U)
/*! TEMP_VAL - Measured Temperature Value */
#define TMPSNS_STATUS0_TEMP_VAL(x)               (((uint32_t)(((uint32_t)(x)) << TMPSNS_STATUS0_TEMP_VAL_SHIFT)) & TMPSNS_STATUS0_TEMP_VAL_MASK)

#define TMPSNS_STATUS0_FINISH_MASK               (0x10000U)
#define TMPSNS_STATUS0_FINISH_SHIFT              (16U)
/*! FINISH - Temperature Measurement Complete
 *  0b0..No read
 *  0b1..New read
 */
#define TMPSNS_STATUS0_FINISH(x)                 (((uint32_t)(((uint32_t)(x)) << TMPSNS_STATUS0_FINISH_SHIFT)) & TMPSNS_STATUS0_FINISH_MASK)

#define TMPSNS_STATUS0_LOW_TEMP_MASK             (0x20000U)
#define TMPSNS_STATUS0_LOW_TEMP_SHIFT            (17U)
/*! LOW_TEMP - Low Temperature Alarm
 *  0b0..No alert
 *  0b1..Alert
 */
#define TMPSNS_STATUS0_LOW_TEMP(x)               (((uint32_t)(((uint32_t)(x)) << TMPSNS_STATUS0_LOW_TEMP_SHIFT)) & TMPSNS_STATUS0_LOW_TEMP_MASK)

#define TMPSNS_STATUS0_HIGH_TEMP_MASK            (0x40000U)
#define TMPSNS_STATUS0_HIGH_TEMP_SHIFT           (18U)
/*! HIGH_TEMP - High Temperature Alarm
 *  0b0..No alert
 *  0b1..Alert
 */
#define TMPSNS_STATUS0_HIGH_TEMP(x)              (((uint32_t)(((uint32_t)(x)) << TMPSNS_STATUS0_HIGH_TEMP_SHIFT)) & TMPSNS_STATUS0_HIGH_TEMP_MASK)

#define TMPSNS_STATUS0_PANIC_TEMP_MASK           (0x80000U)
#define TMPSNS_STATUS0_PANIC_TEMP_SHIFT          (19U)
/*! PANIC_TEMP - Panic Temperature Alarm
 *  0b0..No alert
 *  0b1..Alert
 */
#define TMPSNS_STATUS0_PANIC_TEMP(x)             (((uint32_t)(((uint32_t)(x)) << TMPSNS_STATUS0_PANIC_TEMP_SHIFT)) & TMPSNS_STATUS0_PANIC_TEMP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TMPSNS_Register_Masks */


/*!
 * @}
 */ /* end of group TMPSNS_Peripheral_Access_Layer */


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


#endif  /* PERI_TMPSNS_H_ */

