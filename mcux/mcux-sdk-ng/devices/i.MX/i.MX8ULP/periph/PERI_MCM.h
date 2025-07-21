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
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
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
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MCM.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MCM
 *
 * CMSIS Peripheral Access Layer for MCM
 */

#if !defined(PERI_MCM_H_)
#define PERI_MCM_H_                              /**< Symbol preventing repeated inclusion */

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
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Peripheral_Access_Layer MCM Peripheral Access Layer
 * @{
 */

/** MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[12];
  __IO uint32_t CPCR;                              /**< Core Platform Control, offset: 0xC */
       uint8_t RESERVED_1[36];
  __I  uint32_t CPCR2;                             /**< Core Platform Control 2, offset: 0x34 */
       uint8_t RESERVED_2[968];
  __IO uint32_t LMDR0;                             /**< Local Memory Descriptor 0, offset: 0x400 */
  __IO uint32_t LMDR1;                             /**< Local Memory Descriptor 1, offset: 0x404 */
  __IO uint32_t LMDR2;                             /**< Local Memory Descriptor 2, offset: 0x408 */
  __IO uint32_t LMDR3;                             /**< Local Memory Descriptor 3, offset: 0x40C */
} MCM_Type;

/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/*! @name CPCR - Core Platform Control */
/*! @{ */

#define MCM_CPCR_CBRR_MASK                       (0x200U)
#define MCM_CPCR_CBRR_SHIFT                      (9U)
/*! CBRR - Crossbar Round-robin Arbitration Enable
 *  0b0..Fixed-priority arbitration
 *  0b1..Round-robin arbitration
 */
#define MCM_CPCR_CBRR(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_CBRR_SHIFT)) & MCM_CPCR_CBRR_MASK)
/*! @} */

/*! @name CPCR2 - Core Platform Control 2 */
/*! @{ */

#define MCM_CPCR2_CBCS_MASK                      (0xF0U)
#define MCM_CPCR2_CBCS_SHIFT                     (4U)
/*! CBCS - Code Bus Cache Size
 *  0b0000..0 KB
 *  0b0001..1 KB
 *  0b0010..2 KB
 *  0b0011..4 KB
 *  0b0100..8 KB
 *  0b0101..16 KB
 *  0b0110..32 KB
 */
#define MCM_CPCR2_CBCS(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_CBCS_SHIFT)) & MCM_CPCR2_CBCS_MASK)

#define MCM_CPCR2_SBCS_MASK                      (0xF000U)
#define MCM_CPCR2_SBCS_SHIFT                     (12U)
/*! SBCS - System Bus Cache Size
 *  0b0000..0 KB
 *  0b0001..1 KB
 *  0b0010..2 KB
 *  0b0011..4 KB
 *  0b0100..8 KB
 *  0b0101..16 KB
 *  0b0110..32 KB
 */
#define MCM_CPCR2_SBCS(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_SBCS_SHIFT)) & MCM_CPCR2_SBCS_MASK)
/*! @} */

/*! @name LMDR0 - Local Memory Descriptor 0 */
/*! @{ */

#define MCM_LMDR0_MT_MASK                        (0xE000U)
#define MCM_LMDR0_MT_SHIFT                       (13U)
/*! MT - Memory Type
 *  0b000..SRAM_L
 *  0b001..SRAM_U
 *  0b010..PC Cache
 *  0b011..PS Cache
 */
#define MCM_LMDR0_MT(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_MT_SHIFT)) & MCM_LMDR0_MT_MASK)

#define MCM_LMDR0_RO_MASK                        (0x10000U)
#define MCM_LMDR0_RO_SHIFT                       (16U)
/*! RO - Read-Only
 *  0b0..Writes allowed
 *  0b1..Writes ignored
 */
#define MCM_LMDR0_RO(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_RO_SHIFT)) & MCM_LMDR0_RO_MASK)

#define MCM_LMDR0_DPW_MASK                       (0xE0000U)
#define MCM_LMDR0_DPW_SHIFT                      (17U)
/*! DPW - LMEM Data Path Width
 *  0b000-0b001..
 *  0b010..32 bits
 *  0b011..64 bits
 *  0b100-0b111..
 */
#define MCM_LMDR0_DPW(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_DPW_SHIFT)) & MCM_LMDR0_DPW_MASK)

#define MCM_LMDR0_LMSZ_MASK                      (0xF000000U)
#define MCM_LMDR0_LMSZ_SHIFT                     (24U)
/*! LMSZ - LMEM Size
 *  0b0000..No memory
 *  0b0001..1 KB
 *  0b0010..2 KB
 *  0b0011..4 KB
 *  0b0100..8 KB
 *  0b0101..16 KB
 *  0b0110..32 KB
 *  0b0111..64 KB
 *  0b1000..128 KB
 *  0b1001..256 KB
 *  0b1010..512 KB
 *  0b1011..1024 KB
 *  0b1100..2048 KB
 *  0b1101..4096 KB
 *  0b1110..8192 KB
 *  0b1111..16384 KB
 */
#define MCM_LMDR0_LMSZ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_LMSZ_SHIFT)) & MCM_LMDR0_LMSZ_MASK)

#define MCM_LMDR0_LMSZH_MASK                     (0x10000000U)
#define MCM_LMDR0_LMSZH_SHIFT                    (28U)
/*! LMSZH - LMEM Size Hole
 *  0b0..LMEM has a power-of-2 capacity
 *  0b1..LMEM has a capacity of 0.75 * LMSZ
 */
#define MCM_LMDR0_LMSZH(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_LMSZH_SHIFT)) & MCM_LMDR0_LMSZH_MASK)

#define MCM_LMDR0_V_MASK                         (0x80000000U)
#define MCM_LMDR0_V_SHIFT                        (31U)
/*! V - Valid
 *  0b0..Not present
 *  0b1..Present
 */
#define MCM_LMDR0_V(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_LMDR0_V_SHIFT)) & MCM_LMDR0_V_MASK)
/*! @} */

/*! @name LMDR1 - Local Memory Descriptor 1 */
/*! @{ */

#define MCM_LMDR1_MT_MASK                        (0xE000U)
#define MCM_LMDR1_MT_SHIFT                       (13U)
/*! MT - Memory Type
 *  0b000..SRAM_L
 *  0b001..SRAM_U
 *  0b010..PC Cache
 *  0b011..PS Cache
 */
#define MCM_LMDR1_MT(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_MT_SHIFT)) & MCM_LMDR1_MT_MASK)

#define MCM_LMDR1_RO_MASK                        (0x10000U)
#define MCM_LMDR1_RO_SHIFT                       (16U)
/*! RO - Read-Only
 *  0b0..Writes allowed
 *  0b1..Writes ignored
 */
#define MCM_LMDR1_RO(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_RO_SHIFT)) & MCM_LMDR1_RO_MASK)

#define MCM_LMDR1_DPW_MASK                       (0xE0000U)
#define MCM_LMDR1_DPW_SHIFT                      (17U)
/*! DPW - LMEM Data Path Width
 *  0b000-0b001..
 *  0b010..32 bits
 *  0b011..64 bits
 *  0b100-0b111..
 */
#define MCM_LMDR1_DPW(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_DPW_SHIFT)) & MCM_LMDR1_DPW_MASK)

#define MCM_LMDR1_LMSZ_MASK                      (0xF000000U)
#define MCM_LMDR1_LMSZ_SHIFT                     (24U)
/*! LMSZ - LMEM Size
 *  0b0000..No memory
 *  0b0001..1 KB
 *  0b0010..2 KB
 *  0b0011..4 KB
 *  0b0100..8 KB
 *  0b0101..16 KB
 *  0b0110..32 KB
 *  0b0111..64 KB
 *  0b1000..128 KB
 *  0b1001..256 KB
 *  0b1010..512 KB
 *  0b1011..1024 KB
 *  0b1100..2048 KB
 *  0b1101..4096 KB
 *  0b1110..8192 KB
 *  0b1111..16384 KB
 */
#define MCM_LMDR1_LMSZ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_LMSZ_SHIFT)) & MCM_LMDR1_LMSZ_MASK)

#define MCM_LMDR1_LMSZH_MASK                     (0x10000000U)
#define MCM_LMDR1_LMSZH_SHIFT                    (28U)
/*! LMSZH - LMEM Size Hole
 *  0b0..LMEM has a power-of-2 capacity
 *  0b1..LMEM has a capacity of 0.75 * LMSZ
 */
#define MCM_LMDR1_LMSZH(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_LMSZH_SHIFT)) & MCM_LMDR1_LMSZH_MASK)

#define MCM_LMDR1_V_MASK                         (0x80000000U)
#define MCM_LMDR1_V_SHIFT                        (31U)
/*! V - Valid
 *  0b0..Not present
 *  0b1..Present
 */
#define MCM_LMDR1_V(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_LMDR1_V_SHIFT)) & MCM_LMDR1_V_MASK)
/*! @} */

/*! @name LMDR2 - Local Memory Descriptor 2 */
/*! @{ */

#define MCM_LMDR2_MT_MASK                        (0xE000U)
#define MCM_LMDR2_MT_SHIFT                       (13U)
/*! MT - Memory Type
 *  0b000..SRAM_L
 *  0b001..SRAM_U
 *  0b010..PC Cache
 *  0b011..PS Cache
 */
#define MCM_LMDR2_MT(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_MT_SHIFT)) & MCM_LMDR2_MT_MASK)

#define MCM_LMDR2_RO_MASK                        (0x10000U)
#define MCM_LMDR2_RO_SHIFT                       (16U)
/*! RO - Read-Only
 *  0b0..Writes allowed
 *  0b1..Writes ignored
 */
#define MCM_LMDR2_RO(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_RO_SHIFT)) & MCM_LMDR2_RO_MASK)

#define MCM_LMDR2_DPW_MASK                       (0xE0000U)
#define MCM_LMDR2_DPW_SHIFT                      (17U)
/*! DPW - LMEM Data Path Width
 *  0b000-0b001..
 *  0b010..32 bits
 *  0b011..64 bits
 *  0b100-0b111..
 */
#define MCM_LMDR2_DPW(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_DPW_SHIFT)) & MCM_LMDR2_DPW_MASK)

#define MCM_LMDR2_WY_MASK                        (0xF00000U)
#define MCM_LMDR2_WY_SHIFT                       (20U)
/*! WY - Level 1 Cache Ways
 *  0b0000..No cache
 *  0b0010..2-way set associative
 *  0b0100..4-way set associative
 *  0b1000..8-way set associative
 */
#define MCM_LMDR2_WY(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_WY_SHIFT)) & MCM_LMDR2_WY_MASK)

#define MCM_LMDR2_LMSZ_MASK                      (0xF000000U)
#define MCM_LMDR2_LMSZ_SHIFT                     (24U)
/*! LMSZ - LMEM Size
 *  0b0000..No memory
 *  0b0001..1 KB
 *  0b0010..2 KB
 *  0b0011..4 KB
 *  0b0100..8 KB
 *  0b0101..16 KB
 *  0b0110..32 KB
 *  0b0111..64 KB
 *  0b1000..128 KB
 *  0b1001..256 KB
 *  0b1010..512 KB
 *  0b1011..1024 KB
 *  0b1100..2048 KB
 *  0b1101..4096 KB
 *  0b1110..8192 KB
 *  0b1111..16384 KB
 */
#define MCM_LMDR2_LMSZ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_LMSZ_SHIFT)) & MCM_LMDR2_LMSZ_MASK)

#define MCM_LMDR2_LMSZH_MASK                     (0x10000000U)
#define MCM_LMDR2_LMSZH_SHIFT                    (28U)
/*! LMSZH - LMEM Size Hole
 *  0b0..LMEM has a power-of-2 capacity
 *  0b1..LMEM has a capacity of 0.75 * LMSZ
 */
#define MCM_LMDR2_LMSZH(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_LMSZH_SHIFT)) & MCM_LMDR2_LMSZH_MASK)

#define MCM_LMDR2_V_MASK                         (0x80000000U)
#define MCM_LMDR2_V_SHIFT                        (31U)
/*! V - Valid
 *  0b0..Not present
 *  0b1..Present
 */
#define MCM_LMDR2_V(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_V_SHIFT)) & MCM_LMDR2_V_MASK)
/*! @} */

/*! @name LMDR3 - Local Memory Descriptor 3 */
/*! @{ */

#define MCM_LMDR3_MT_MASK                        (0xE000U)
#define MCM_LMDR3_MT_SHIFT                       (13U)
/*! MT - Memory Type
 *  0b000..SRAM_L
 *  0b001..SRAM_U
 *  0b010..PC Cache
 *  0b011..PS Cache
 */
#define MCM_LMDR3_MT(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR3_MT_SHIFT)) & MCM_LMDR3_MT_MASK)

#define MCM_LMDR3_RO_MASK                        (0x10000U)
#define MCM_LMDR3_RO_SHIFT                       (16U)
/*! RO - Read-Only
 *  0b0..Writes allowed
 *  0b1..Writes ignored
 */
#define MCM_LMDR3_RO(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR3_RO_SHIFT)) & MCM_LMDR3_RO_MASK)

#define MCM_LMDR3_DPW_MASK                       (0xE0000U)
#define MCM_LMDR3_DPW_SHIFT                      (17U)
/*! DPW - LMEM Data Path Width
 *  0b000-0b001..
 *  0b010..32 bits
 *  0b011..64 bits
 *  0b100-0b111..
 */
#define MCM_LMDR3_DPW(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMDR3_DPW_SHIFT)) & MCM_LMDR3_DPW_MASK)

#define MCM_LMDR3_WY_MASK                        (0xF00000U)
#define MCM_LMDR3_WY_SHIFT                       (20U)
/*! WY - Level 1 Cache Ways
 *  0b0000..No cache
 *  0b0010..2-way set associative
 *  0b0100..4-way set associative
 *  0b1000..8-way set associative
 */
#define MCM_LMDR3_WY(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR3_WY_SHIFT)) & MCM_LMDR3_WY_MASK)

#define MCM_LMDR3_LMSZ_MASK                      (0xF000000U)
#define MCM_LMDR3_LMSZ_SHIFT                     (24U)
/*! LMSZ - LMEM Size
 *  0b0000..No memory
 *  0b0001..1 KB
 *  0b0010..2 KB
 *  0b0011..4 KB
 *  0b0100..8 KB
 *  0b0101..16 KB
 *  0b0110..32 KB
 *  0b0111..64 KB
 *  0b1000..128 KB
 *  0b1001..256 KB
 *  0b1010..512 KB
 *  0b1011..1024 KB
 *  0b1100..2048 KB
 *  0b1101..4096 KB
 *  0b1110..8192 KB
 *  0b1111..16384 KB
 */
#define MCM_LMDR3_LMSZ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR3_LMSZ_SHIFT)) & MCM_LMDR3_LMSZ_MASK)

#define MCM_LMDR3_LMSZH_MASK                     (0x10000000U)
#define MCM_LMDR3_LMSZH_SHIFT                    (28U)
/*! LMSZH - LMEM Size Hole
 *  0b0..LMEM has a power-of-2 capacity
 *  0b1..LMEM has a capacity of 0.75 * LMSZ
 */
#define MCM_LMDR3_LMSZH(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMDR3_LMSZH_SHIFT)) & MCM_LMDR3_LMSZH_MASK)

#define MCM_LMDR3_V_MASK                         (0x80000000U)
#define MCM_LMDR3_V_SHIFT                        (31U)
/*! V - Valid
 *  0b0..Not present
 *  0b1..Present
 */
#define MCM_LMDR3_V(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_LMDR3_V_SHIFT)) & MCM_LMDR3_V_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MCM_Register_Masks */


/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */


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


#endif  /* PERI_MCM_H_ */

