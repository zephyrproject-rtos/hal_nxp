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
**         CMSIS Peripheral Access Layer for IOMUXC0
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
 * @file PERI_IOMUXC0.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOMUXC0
 *
 * CMSIS Peripheral Access Layer for IOMUXC0
 */

#if !defined(PERI_IOMUXC0_H_)
#define PERI_IOMUXC0_H_                          /**< Symbol preventing repeated inclusion */

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
   -- IOMUXC0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC0_Peripheral_Access_Layer IOMUXC0 Peripheral Access Layer
 * @{
 */

/** IOMUXC0 - Size of Registers Arrays */
#define IOMUXC0_PCR0_IOMUXCARRAY0_COUNT           25u
#define IOMUXC0_PCR0_IOMUXCARRAY1_COUNT           16u
#define IOMUXC0_PCR0_IOMUXCARRAY2_COUNT           24u
#define IOMUXC0_PCR0_IOMUXCARRAY3_COUNT           2u
#define IOMUXC0_PSMI0_IOMUXCARRAY0_COUNT          5u
#define IOMUXC0_PSMI0_IOMUXCARRAY1_COUNT          3u
#define IOMUXC0_PSMI0_IOMUXCARRAY2_COUNT          4u
#define IOMUXC0_PSMI0_IOMUXCARRAY3_COUNT          3u
#define IOMUXC0_PSMI0_IOMUXCARRAY4_COUNT          1u
#define IOMUXC0_PSMI0_IOMUXCARRAY5_COUNT          10u
#define IOMUXC0_PSMI0_IOMUXCARRAY6_COUNT          3u
#define IOMUXC0_PSMI0_IOMUXCARRAY7_COUNT          15u
#define IOMUXC0_PSMI0_IOMUXCARRAY8_COUNT          15u
#define IOMUXC0_PSMI0_IOMUXCARRAY9_COUNT          11u
#define IOMUXC0_PSMI0_IOMUXCARRAY10_COUNT         24u
#define IOMUXC0_PSMI0_IOMUXCARRAY11_COUNT         6u

/** IOMUXC0 - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCR0_IOMUXCARRAY0[IOMUXC0_PCR0_IOMUXCARRAY0_COUNT]; /**< Pad Control Register, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[28];
  __IO uint32_t PCR0_IOMUXCARRAY1[IOMUXC0_PCR0_IOMUXCARRAY1_COUNT]; /**< Pad Control Register, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_1[64];
  __IO uint32_t PCR0_IOMUXCARRAY2[IOMUXC0_PCR0_IOMUXCARRAY2_COUNT]; /**< Pad Control Register, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_2[672];
  __IO uint32_t PCR0_IOMUXCARRAY3[IOMUXC0_PCR0_IOMUXCARRAY3_COUNT]; /**< Pad Control Register, array offset: 0x400, array step: 0x4 */
       uint8_t RESERVED_3[1016];
  __IO uint32_t PSMI0_IOMUXCARRAY0[IOMUXC0_PSMI0_IOMUXCARRAY0_COUNT]; /**< Module Input Source Selection Register, array offset: 0x800, array step: 0x4 */
       uint8_t RESERVED_4[132];
  __IO uint32_t PSMI0_IOMUXCARRAY1[IOMUXC0_PSMI0_IOMUXCARRAY1_COUNT]; /**< Module Input Source Selection Register, array offset: 0x898, array step: 0x4 */
       uint8_t RESERVED_5[12];
  __IO uint32_t PSMI0_IOMUXCARRAY2[IOMUXC0_PSMI0_IOMUXCARRAY2_COUNT]; /**< Module Input Source Selection Register, array offset: 0x8B0, array step: 0x4 */
       uint8_t RESERVED_6[12];
  __IO uint32_t PSMI0_IOMUXCARRAY3[IOMUXC0_PSMI0_IOMUXCARRAY3_COUNT]; /**< Module Input Source Selection Register, array offset: 0x8CC, array step: 0x4 */
       uint8_t RESERVED_7[36];
  __IO uint32_t PSMI0_IOMUXCARRAY4[IOMUXC0_PSMI0_IOMUXCARRAY4_COUNT]; /**< Module Input Source Selection Register, array offset: 0x8FC, array step: 0x4 */
       uint8_t RESERVED_8[40];
  __IO uint32_t PSMI0_IOMUXCARRAY5[IOMUXC0_PSMI0_IOMUXCARRAY5_COUNT]; /**< Module Input Source Selection Register, array offset: 0x928, array step: 0x4 */
       uint8_t RESERVED_9[8];
  __IO uint32_t PSMI0_IOMUXCARRAY6[IOMUXC0_PSMI0_IOMUXCARRAY6_COUNT]; /**< Module Input Source Selection Register, array offset: 0x958, array step: 0x4 */
       uint8_t RESERVED_10[16];
  __IO uint32_t PSMI0_IOMUXCARRAY7[IOMUXC0_PSMI0_IOMUXCARRAY7_COUNT]; /**< Module Input Source Selection Register, array offset: 0x974, array step: 0x4 */
       uint8_t RESERVED_11[8];
  __IO uint32_t PSMI0_IOMUXCARRAY8[IOMUXC0_PSMI0_IOMUXCARRAY8_COUNT]; /**< Module Input Source Selection Register, array offset: 0x9B8, array step: 0x4 */
       uint8_t RESERVED_12[16];
  __IO uint32_t PSMI0_IOMUXCARRAY9[IOMUXC0_PSMI0_IOMUXCARRAY9_COUNT]; /**< Module Input Source Selection Register, array offset: 0xA04, array step: 0x4 */
       uint8_t RESERVED_13[4];
  __IO uint32_t PSMI0_IOMUXCARRAY10[IOMUXC0_PSMI0_IOMUXCARRAY10_COUNT]; /**< Module Input Source Selection Register, array offset: 0xA34, array step: 0x4 */
       uint8_t RESERVED_14[64];
  __IO uint32_t PSMI0_IOMUXCARRAY11[IOMUXC0_PSMI0_IOMUXCARRAY11_COUNT]; /**< Module Input Source Selection Register, array offset: 0xAD4, array step: 0x4 */
} IOMUXC0_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC0_Register_Masks IOMUXC0 Register Masks
 * @{
 */

/*! @name PCR0_IOMUXCARRAY0 - Pad Control Register */
/*! @{ */

#define IOMUXC0_PCR0_IOMUXCARRAY0_PS_MASK        (0x1U)
#define IOMUXC0_PCR0_IOMUXCARRAY0_PS_SHIFT       (0U)
/*! PS - Pull Select
 *  0b0..Pull-down selected
 *  0b1..Pull-up selected
 */
#define IOMUXC0_PCR0_IOMUXCARRAY0_PS(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY0_PS_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY0_PS_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY0_PE_MASK        (0x2U)
#define IOMUXC0_PCR0_IOMUXCARRAY0_PE_SHIFT       (1U)
/*! PE - Pull-up Enable
 *  0b0..pull disabled
 *  0b1..pull enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY0_PE(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY0_PE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY0_PE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY0_SRE_MASK       (0x4U)
#define IOMUXC0_PCR0_IOMUXCARRAY0_SRE_SHIFT      (2U)
/*! SRE - Slew Rate Enable
 *  0b0..Standard Slew Rate
 *  0b1..Slow Slew Rate
 */
#define IOMUXC0_PCR0_IOMUXCARRAY0_SRE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY0_SRE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY0_SRE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY0_ODE_MASK       (0x20U)
#define IOMUXC0_PCR0_IOMUXCARRAY0_ODE_SHIFT      (5U)
/*! ODE - Open-drain Enable
 *  0b0..Push-pull Output
 *  0b1..Open-drain Output
 */
#define IOMUXC0_PCR0_IOMUXCARRAY0_ODE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY0_ODE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY0_ODE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY0_DSE_MASK       (0x40U)
#define IOMUXC0_PCR0_IOMUXCARRAY0_DSE_SHIFT      (6U)
/*! DSE - Drive Strength Enable
 *  0b0..Standard Drive Strength
 *  0b1..Hi Drive Strength
 */
#define IOMUXC0_PCR0_IOMUXCARRAY0_DSE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY0_DSE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY0_DSE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY0_MUX_MASK       (0xF00U)
#define IOMUXC0_PCR0_IOMUXCARRAY0_MUX_SHIFT      (8U)
/*! MUX - PAD Mux Selector
 *  0b0000..Alternate function 0 ; Analog / Hiz
 *  0b0001..Refer to "IO Signal Table" for availabre functions and SS values for each PAD.
 */
#define IOMUXC0_PCR0_IOMUXCARRAY0_MUX(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY0_MUX_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY0_MUX_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY0_LK_MASK        (0x8000U)
#define IOMUXC0_PCR0_IOMUXCARRAY0_LK_SHIFT       (15U)
/*! LK - Lock
 *  0b0..Register Unlocked
 *  0b1..Register Locked for write
 */
#define IOMUXC0_PCR0_IOMUXCARRAY0_LK(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY0_LK_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY0_LK_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY0_IBE_MASK       (0x10000U)
#define IOMUXC0_PCR0_IOMUXCARRAY0_IBE_SHIFT      (16U)
/*! IBE - Input Buffer Enable
 *  0b0..Input Buffer enable depends on selected function
 *  0b1..Input buffer forced enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY0_IBE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY0_IBE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY0_IBE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY0_OBE_MASK       (0x20000U)
#define IOMUXC0_PCR0_IOMUXCARRAY0_OBE_SHIFT      (17U)
/*! OBE - Output Buffer Enable
 *  0b0..Output Buffer enable depends on selected function
 *  0b1..Output buffer forced enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY0_OBE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY0_OBE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY0_OBE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY0_DFE_MASK       (0x100000U)
#define IOMUXC0_PCR0_IOMUXCARRAY0_DFE_SHIFT      (20U)
/*! DFE - Digital Filter Enable
 *  0b0..Digital filter disabled
 *  0b1..Digital filter enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY0_DFE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY0_DFE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY0_DFE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY0_DFCS_MASK      (0x200000U)
#define IOMUXC0_PCR0_IOMUXCARRAY0_DFCS_SHIFT     (21U)
/*! DFCS - Digital Filter Clock Select
 *  0b0..Digital filter is running out of PCTL* Bus clock
 *  0b1..Digital filter is running out RTC 1kHz clock
 */
#define IOMUXC0_PCR0_IOMUXCARRAY0_DFCS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY0_DFCS_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY0_DFCS_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY0_DFD_MASK       (0x7C00000U)
#define IOMUXC0_PCR0_IOMUXCARRAY0_DFD_SHIFT      (22U)
/*! DFD - Digital Filter Duration
 *  0b00000..Digital filter is disabled
 *  0b00001..Filter window count value
 */
#define IOMUXC0_PCR0_IOMUXCARRAY0_DFD(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY0_DFD_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY0_DFD_MASK)
/*! @} */

/*! @name PCR0_IOMUXCARRAY1 - Pad Control Register */
/*! @{ */

#define IOMUXC0_PCR0_IOMUXCARRAY1_PS_MASK        (0x1U)
#define IOMUXC0_PCR0_IOMUXCARRAY1_PS_SHIFT       (0U)
/*! PS - Pull Select
 *  0b0..Pull-down selected
 *  0b1..Pull-up selected
 */
#define IOMUXC0_PCR0_IOMUXCARRAY1_PS(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY1_PS_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY1_PS_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY1_PE_MASK        (0x2U)
#define IOMUXC0_PCR0_IOMUXCARRAY1_PE_SHIFT       (1U)
/*! PE - Pull-up Enable
 *  0b0..pull disabled
 *  0b1..pull enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY1_PE(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY1_PE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY1_PE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY1_SRE_MASK       (0x4U)
#define IOMUXC0_PCR0_IOMUXCARRAY1_SRE_SHIFT      (2U)
/*! SRE - Slew Rate Enable
 *  0b0..Standard Slew Rate
 *  0b1..Slow Slew Rate
 */
#define IOMUXC0_PCR0_IOMUXCARRAY1_SRE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY1_SRE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY1_SRE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY1_ODE_MASK       (0x20U)
#define IOMUXC0_PCR0_IOMUXCARRAY1_ODE_SHIFT      (5U)
/*! ODE - Open-drain Enable
 *  0b0..Push-pull Output
 *  0b1..Open-drain Output
 */
#define IOMUXC0_PCR0_IOMUXCARRAY1_ODE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY1_ODE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY1_ODE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY1_DSE_MASK       (0x40U)
#define IOMUXC0_PCR0_IOMUXCARRAY1_DSE_SHIFT      (6U)
/*! DSE - Drive Strength Enable
 *  0b0..Standard Drive Strength
 *  0b1..Hi Drive Strength
 */
#define IOMUXC0_PCR0_IOMUXCARRAY1_DSE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY1_DSE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY1_DSE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY1_MUX_MASK       (0xF00U)
#define IOMUXC0_PCR0_IOMUXCARRAY1_MUX_SHIFT      (8U)
/*! MUX - PAD Mux Selector
 *  0b0000..Alternate function 0 ; Analog / Hiz
 *  0b0001..Refer to "IO Signal Table" for availabre functions and SS values for each PAD.
 */
#define IOMUXC0_PCR0_IOMUXCARRAY1_MUX(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY1_MUX_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY1_MUX_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY1_LK_MASK        (0x8000U)
#define IOMUXC0_PCR0_IOMUXCARRAY1_LK_SHIFT       (15U)
/*! LK - Lock
 *  0b0..Register Unlocked
 *  0b1..Register Locked for write
 */
#define IOMUXC0_PCR0_IOMUXCARRAY1_LK(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY1_LK_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY1_LK_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY1_IBE_MASK       (0x10000U)
#define IOMUXC0_PCR0_IOMUXCARRAY1_IBE_SHIFT      (16U)
/*! IBE - Input Buffer Enable
 *  0b0..Input Buffer enable depends on selected function
 *  0b1..Input buffer forced enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY1_IBE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY1_IBE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY1_IBE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY1_OBE_MASK       (0x20000U)
#define IOMUXC0_PCR0_IOMUXCARRAY1_OBE_SHIFT      (17U)
/*! OBE - Output Buffer Enable
 *  0b0..Output Buffer enable depends on selected function
 *  0b1..Output buffer forced enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY1_OBE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY1_OBE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY1_OBE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY1_DFE_MASK       (0x100000U)
#define IOMUXC0_PCR0_IOMUXCARRAY1_DFE_SHIFT      (20U)
/*! DFE - Digital Filter Enable
 *  0b0..Digital filter disabled
 *  0b1..Digital filter enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY1_DFE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY1_DFE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY1_DFE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY1_DFCS_MASK      (0x200000U)
#define IOMUXC0_PCR0_IOMUXCARRAY1_DFCS_SHIFT     (21U)
/*! DFCS - Digital Filter Clock Select
 *  0b0..Digital filter is running out of PCTL* Bus clock
 *  0b1..Digital filter is running out RTC 1kHz clock
 */
#define IOMUXC0_PCR0_IOMUXCARRAY1_DFCS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY1_DFCS_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY1_DFCS_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY1_DFD_MASK       (0x7C00000U)
#define IOMUXC0_PCR0_IOMUXCARRAY1_DFD_SHIFT      (22U)
/*! DFD - Digital Filter Duration
 *  0b00000..Digital filter is disabled
 *  0b00001..Filter window count value
 */
#define IOMUXC0_PCR0_IOMUXCARRAY1_DFD(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY1_DFD_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY1_DFD_MASK)
/*! @} */

/*! @name PCR0_IOMUXCARRAY2 - Pad Control Register */
/*! @{ */

#define IOMUXC0_PCR0_IOMUXCARRAY2_PS_MASK        (0x1U)
#define IOMUXC0_PCR0_IOMUXCARRAY2_PS_SHIFT       (0U)
/*! PS - Pull Select
 *  0b0..Pull-down selected
 *  0b1..Pull-up selected
 */
#define IOMUXC0_PCR0_IOMUXCARRAY2_PS(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY2_PS_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY2_PS_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY2_PE_MASK        (0x2U)
#define IOMUXC0_PCR0_IOMUXCARRAY2_PE_SHIFT       (1U)
/*! PE - Pull-up Enable
 *  0b0..pull disabled
 *  0b1..pull enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY2_PE(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY2_PE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY2_PE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY2_SRE_MASK       (0x4U)
#define IOMUXC0_PCR0_IOMUXCARRAY2_SRE_SHIFT      (2U)
/*! SRE - Slew Rate Enable
 *  0b0..Standard Slew Rate
 *  0b1..Slow Slew Rate
 */
#define IOMUXC0_PCR0_IOMUXCARRAY2_SRE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY2_SRE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY2_SRE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY2_ODE_MASK       (0x20U)
#define IOMUXC0_PCR0_IOMUXCARRAY2_ODE_SHIFT      (5U)
/*! ODE - Open-drain Enable
 *  0b0..Push-pull Output
 *  0b1..Open-drain Output
 */
#define IOMUXC0_PCR0_IOMUXCARRAY2_ODE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY2_ODE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY2_ODE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY2_DSE_MASK       (0x40U)
#define IOMUXC0_PCR0_IOMUXCARRAY2_DSE_SHIFT      (6U)
/*! DSE - Drive Strength Enable
 *  0b0..Standard Drive Strength
 *  0b1..Hi Drive Strength
 */
#define IOMUXC0_PCR0_IOMUXCARRAY2_DSE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY2_DSE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY2_DSE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY2_MUX_MASK       (0xF00U)
#define IOMUXC0_PCR0_IOMUXCARRAY2_MUX_SHIFT      (8U)
/*! MUX - PAD Mux Selector
 *  0b0000..Alternate function 0 ; Analog / Hiz
 *  0b0001..Refer to "IO Signal Table" for availabre functions and SS values for each PAD.
 */
#define IOMUXC0_PCR0_IOMUXCARRAY2_MUX(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY2_MUX_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY2_MUX_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY2_LK_MASK        (0x8000U)
#define IOMUXC0_PCR0_IOMUXCARRAY2_LK_SHIFT       (15U)
/*! LK - Lock
 *  0b0..Register Unlocked
 *  0b1..Register Locked for write
 */
#define IOMUXC0_PCR0_IOMUXCARRAY2_LK(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY2_LK_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY2_LK_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY2_IBE_MASK       (0x10000U)
#define IOMUXC0_PCR0_IOMUXCARRAY2_IBE_SHIFT      (16U)
/*! IBE - Input Buffer Enable
 *  0b0..Input Buffer enable depends on selected function
 *  0b1..Input buffer forced enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY2_IBE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY2_IBE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY2_IBE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY2_OBE_MASK       (0x20000U)
#define IOMUXC0_PCR0_IOMUXCARRAY2_OBE_SHIFT      (17U)
/*! OBE - Output Buffer Enable
 *  0b0..Output Buffer enable depends on selected function
 *  0b1..Output buffer forced enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY2_OBE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY2_OBE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY2_OBE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY2_DFE_MASK       (0x100000U)
#define IOMUXC0_PCR0_IOMUXCARRAY2_DFE_SHIFT      (20U)
/*! DFE - Digital Filter Enable
 *  0b0..Digital filter disabled
 *  0b1..Digital filter enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY2_DFE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY2_DFE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY2_DFE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY2_DFCS_MASK      (0x200000U)
#define IOMUXC0_PCR0_IOMUXCARRAY2_DFCS_SHIFT     (21U)
/*! DFCS - Digital Filter Clock Select
 *  0b0..Digital filter is running out of PCTL* Bus clock
 *  0b1..Digital filter is running out RTC 1kHz clock
 */
#define IOMUXC0_PCR0_IOMUXCARRAY2_DFCS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY2_DFCS_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY2_DFCS_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY2_DFD_MASK       (0x7C00000U)
#define IOMUXC0_PCR0_IOMUXCARRAY2_DFD_SHIFT      (22U)
/*! DFD - Digital Filter Duration
 *  0b00000..Digital filter is disabled
 *  0b00001..Filter window count value
 */
#define IOMUXC0_PCR0_IOMUXCARRAY2_DFD(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY2_DFD_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY2_DFD_MASK)
/*! @} */

/*! @name PCR0_IOMUXCARRAY3 - Pad Control Register */
/*! @{ */

#define IOMUXC0_PCR0_IOMUXCARRAY3_PS_MASK        (0x1U)
#define IOMUXC0_PCR0_IOMUXCARRAY3_PS_SHIFT       (0U)
/*! PS - Pull Select
 *  0b0..Pull-down selected
 *  0b1..Pull-up selected
 */
#define IOMUXC0_PCR0_IOMUXCARRAY3_PS(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY3_PS_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY3_PS_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY3_PE_MASK        (0x2U)
#define IOMUXC0_PCR0_IOMUXCARRAY3_PE_SHIFT       (1U)
/*! PE - Pull-up Enable
 *  0b0..pull disabled
 *  0b1..pull enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY3_PE(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY3_PE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY3_PE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY3_SRE_MASK       (0x4U)
#define IOMUXC0_PCR0_IOMUXCARRAY3_SRE_SHIFT      (2U)
/*! SRE - Slew Rate Enable
 *  0b0..Standard Slew Rate
 *  0b1..Slow Slew Rate
 */
#define IOMUXC0_PCR0_IOMUXCARRAY3_SRE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY3_SRE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY3_SRE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY3_ODE_MASK       (0x20U)
#define IOMUXC0_PCR0_IOMUXCARRAY3_ODE_SHIFT      (5U)
/*! ODE - Open-drain Enable
 *  0b0..Push-pull Output
 *  0b1..Open-drain Output
 */
#define IOMUXC0_PCR0_IOMUXCARRAY3_ODE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY3_ODE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY3_ODE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY3_DSE_MASK       (0x40U)
#define IOMUXC0_PCR0_IOMUXCARRAY3_DSE_SHIFT      (6U)
/*! DSE - Drive Strength Enable
 *  0b0..Standard Drive Strength
 *  0b1..Hi Drive Strength
 */
#define IOMUXC0_PCR0_IOMUXCARRAY3_DSE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY3_DSE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY3_DSE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY3_MUX_MASK       (0xF00U)
#define IOMUXC0_PCR0_IOMUXCARRAY3_MUX_SHIFT      (8U)
/*! MUX - PAD Mux Selector
 *  0b0000..Alternate function 0 ; Analog / Hiz
 *  0b0001..Refer to "IO Signal Table" for availabre functions and SS values for each PAD.
 */
#define IOMUXC0_PCR0_IOMUXCARRAY3_MUX(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY3_MUX_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY3_MUX_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY3_LK_MASK        (0x8000U)
#define IOMUXC0_PCR0_IOMUXCARRAY3_LK_SHIFT       (15U)
/*! LK - Lock
 *  0b0..Register Unlocked
 *  0b1..Register Locked for write
 */
#define IOMUXC0_PCR0_IOMUXCARRAY3_LK(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY3_LK_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY3_LK_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY3_IBE_MASK       (0x10000U)
#define IOMUXC0_PCR0_IOMUXCARRAY3_IBE_SHIFT      (16U)
/*! IBE - Input Buffer Enable
 *  0b0..Input Buffer enable depends on selected function
 *  0b1..Input buffer forced enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY3_IBE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY3_IBE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY3_IBE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY3_OBE_MASK       (0x20000U)
#define IOMUXC0_PCR0_IOMUXCARRAY3_OBE_SHIFT      (17U)
/*! OBE - Output Buffer Enable
 *  0b0..Output Buffer enable depends on selected function
 *  0b1..Output buffer forced enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY3_OBE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY3_OBE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY3_OBE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY3_DFE_MASK       (0x100000U)
#define IOMUXC0_PCR0_IOMUXCARRAY3_DFE_SHIFT      (20U)
/*! DFE - Digital Filter Enable
 *  0b0..Digital filter disabled
 *  0b1..Digital filter enabled
 */
#define IOMUXC0_PCR0_IOMUXCARRAY3_DFE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY3_DFE_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY3_DFE_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY3_DFCS_MASK      (0x200000U)
#define IOMUXC0_PCR0_IOMUXCARRAY3_DFCS_SHIFT     (21U)
/*! DFCS - Digital Filter Clock Select
 *  0b0..Digital filter is running out of PCTL* Bus clock
 *  0b1..Digital filter is running out RTC 1kHz clock
 */
#define IOMUXC0_PCR0_IOMUXCARRAY3_DFCS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY3_DFCS_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY3_DFCS_MASK)

#define IOMUXC0_PCR0_IOMUXCARRAY3_DFD_MASK       (0x7C00000U)
#define IOMUXC0_PCR0_IOMUXCARRAY3_DFD_SHIFT      (22U)
/*! DFD - Digital Filter Duration
 *  0b00000..Digital filter is disabled
 *  0b00001..Filter window count value
 */
#define IOMUXC0_PCR0_IOMUXCARRAY3_DFD(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PCR0_IOMUXCARRAY3_DFD_SHIFT)) & IOMUXC0_PCR0_IOMUXCARRAY3_DFD_MASK)
/*! @} */

/*! @name PSMI0_IOMUXCARRAY0 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC0_PSMI0_IOMUXCARRAY0_SSS_MASK      (0xFU)
#define IOMUXC0_PSMI0_IOMUXCARRAY0_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY0_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY0_SSS_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY0_SSS_MASK)

#define IOMUXC0_PSMI0_IOMUXCARRAY0_INV_MASK      (0x8000U)
#define IOMUXC0_PSMI0_IOMUXCARRAY0_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY0_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY0_INV_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY0_INV_MASK)
/*! @} */

/*! @name PSMI0_IOMUXCARRAY1 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC0_PSMI0_IOMUXCARRAY1_SSS_MASK      (0xFU)
#define IOMUXC0_PSMI0_IOMUXCARRAY1_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY1_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY1_SSS_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY1_SSS_MASK)

#define IOMUXC0_PSMI0_IOMUXCARRAY1_INV_MASK      (0x8000U)
#define IOMUXC0_PSMI0_IOMUXCARRAY1_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY1_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY1_INV_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY1_INV_MASK)
/*! @} */

/*! @name PSMI0_IOMUXCARRAY2 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC0_PSMI0_IOMUXCARRAY2_SSS_MASK      (0xFU)
#define IOMUXC0_PSMI0_IOMUXCARRAY2_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY2_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY2_SSS_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY2_SSS_MASK)

#define IOMUXC0_PSMI0_IOMUXCARRAY2_INV_MASK      (0x8000U)
#define IOMUXC0_PSMI0_IOMUXCARRAY2_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY2_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY2_INV_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY2_INV_MASK)
/*! @} */

/*! @name PSMI0_IOMUXCARRAY3 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC0_PSMI0_IOMUXCARRAY3_SSS_MASK      (0xFU)
#define IOMUXC0_PSMI0_IOMUXCARRAY3_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY3_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY3_SSS_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY3_SSS_MASK)

#define IOMUXC0_PSMI0_IOMUXCARRAY3_INV_MASK      (0x8000U)
#define IOMUXC0_PSMI0_IOMUXCARRAY3_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY3_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY3_INV_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY3_INV_MASK)
/*! @} */

/*! @name PSMI0_IOMUXCARRAY4 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC0_PSMI0_IOMUXCARRAY4_SSS_MASK      (0xFU)
#define IOMUXC0_PSMI0_IOMUXCARRAY4_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY4_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY4_SSS_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY4_SSS_MASK)

#define IOMUXC0_PSMI0_IOMUXCARRAY4_INV_MASK      (0x8000U)
#define IOMUXC0_PSMI0_IOMUXCARRAY4_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY4_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY4_INV_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY4_INV_MASK)
/*! @} */

/*! @name PSMI0_IOMUXCARRAY5 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC0_PSMI0_IOMUXCARRAY5_SSS_MASK      (0xFU)
#define IOMUXC0_PSMI0_IOMUXCARRAY5_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY5_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY5_SSS_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY5_SSS_MASK)

#define IOMUXC0_PSMI0_IOMUXCARRAY5_INV_MASK      (0x8000U)
#define IOMUXC0_PSMI0_IOMUXCARRAY5_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY5_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY5_INV_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY5_INV_MASK)
/*! @} */

/*! @name PSMI0_IOMUXCARRAY6 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC0_PSMI0_IOMUXCARRAY6_SSS_MASK      (0xFU)
#define IOMUXC0_PSMI0_IOMUXCARRAY6_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY6_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY6_SSS_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY6_SSS_MASK)

#define IOMUXC0_PSMI0_IOMUXCARRAY6_INV_MASK      (0x8000U)
#define IOMUXC0_PSMI0_IOMUXCARRAY6_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY6_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY6_INV_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY6_INV_MASK)
/*! @} */

/*! @name PSMI0_IOMUXCARRAY7 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC0_PSMI0_IOMUXCARRAY7_SSS_MASK      (0xFU)
#define IOMUXC0_PSMI0_IOMUXCARRAY7_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY7_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY7_SSS_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY7_SSS_MASK)

#define IOMUXC0_PSMI0_IOMUXCARRAY7_INV_MASK      (0x8000U)
#define IOMUXC0_PSMI0_IOMUXCARRAY7_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY7_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY7_INV_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY7_INV_MASK)
/*! @} */

/*! @name PSMI0_IOMUXCARRAY8 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC0_PSMI0_IOMUXCARRAY8_SSS_MASK      (0xFU)
#define IOMUXC0_PSMI0_IOMUXCARRAY8_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY8_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY8_SSS_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY8_SSS_MASK)

#define IOMUXC0_PSMI0_IOMUXCARRAY8_INV_MASK      (0x8000U)
#define IOMUXC0_PSMI0_IOMUXCARRAY8_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY8_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY8_INV_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY8_INV_MASK)
/*! @} */

/*! @name PSMI0_IOMUXCARRAY9 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC0_PSMI0_IOMUXCARRAY9_SSS_MASK      (0xFU)
#define IOMUXC0_PSMI0_IOMUXCARRAY9_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY9_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY9_SSS_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY9_SSS_MASK)

#define IOMUXC0_PSMI0_IOMUXCARRAY9_INV_MASK      (0x8000U)
#define IOMUXC0_PSMI0_IOMUXCARRAY9_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY9_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY9_INV_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY9_INV_MASK)
/*! @} */

/*! @name PSMI0_IOMUXCARRAY10 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC0_PSMI0_IOMUXCARRAY10_SSS_MASK     (0xFU)
#define IOMUXC0_PSMI0_IOMUXCARRAY10_SSS_SHIFT    (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY10_SSS(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY10_SSS_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY10_SSS_MASK)

#define IOMUXC0_PSMI0_IOMUXCARRAY10_INV_MASK     (0x8000U)
#define IOMUXC0_PSMI0_IOMUXCARRAY10_INV_SHIFT    (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY10_INV(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY10_INV_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY10_INV_MASK)
/*! @} */

/*! @name PSMI0_IOMUXCARRAY11 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC0_PSMI0_IOMUXCARRAY11_SSS_MASK     (0xFU)
#define IOMUXC0_PSMI0_IOMUXCARRAY11_SSS_SHIFT    (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY11_SSS(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY11_SSS_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY11_SSS_MASK)

#define IOMUXC0_PSMI0_IOMUXCARRAY11_INV_MASK     (0x8000U)
#define IOMUXC0_PSMI0_IOMUXCARRAY11_INV_SHIFT    (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC0_PSMI0_IOMUXCARRAY11_INV(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC0_PSMI0_IOMUXCARRAY11_INV_SHIFT)) & IOMUXC0_PSMI0_IOMUXCARRAY11_INV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC0_Register_Masks */


/*!
 * @}
 */ /* end of group IOMUXC0_Peripheral_Access_Layer */


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


#endif  /* PERI_IOMUXC0_H_ */

