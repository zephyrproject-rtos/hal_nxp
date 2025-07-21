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
**         CMSIS Peripheral Access Layer for IOMUXC1
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
 * @file PERI_IOMUXC1.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOMUXC1
 *
 * CMSIS Peripheral Access Layer for IOMUXC1
 */

#if !defined(PERI_IOMUXC1_H_)
#define PERI_IOMUXC1_H_                          /**< Symbol preventing repeated inclusion */

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
   -- IOMUXC1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC1_Peripheral_Access_Layer IOMUXC1 Peripheral Access Layer
 * @{
 */

/** IOMUXC1 - Size of Registers Arrays */
#define IOMUXC1_PCR1_IOMUXCARRAY0_COUNT           24u
#define IOMUXC1_PCR1_IOMUXCARRAY1_COUNT           24u
#define IOMUXC1_PCR1_IOMUXCARRAY2_COUNT           32u
#define IOMUXC1_PSMI1_IOMUXCARRAY0_COUNT          10u
#define IOMUXC1_PSMI1_IOMUXCARRAY1_COUNT          61u
#define IOMUXC1_PSMI1_IOMUXCARRAY2_COUNT          12u
#define IOMUXC1_PSMI1_IOMUXCARRAY3_COUNT          20u
#define IOMUXC1_PSMI1_IOMUXCARRAY4_COUNT          75u

/** IOMUXC1 - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCR1_IOMUXCARRAY0[IOMUXC1_PCR1_IOMUXCARRAY0_COUNT]; /**< Pad Control Register, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[32];
  __IO uint32_t PCR1_IOMUXCARRAY1[IOMUXC1_PCR1_IOMUXCARRAY1_COUNT]; /**< Pad Control Register, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_1[32];
  __IO uint32_t PCR1_IOMUXCARRAY2[IOMUXC1_PCR1_IOMUXCARRAY2_COUNT]; /**< Pad Control Register, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_2[1664];
  __IO uint32_t PSMI1_IOMUXCARRAY0[IOMUXC1_PSMI1_IOMUXCARRAY0_COUNT]; /**< Module Input Source Selection Register, array offset: 0x800, array step: 0x4 */
       uint8_t RESERVED_3[16];
  __IO uint32_t PSMI1_IOMUXCARRAY1[IOMUXC1_PSMI1_IOMUXCARRAY1_COUNT]; /**< Module Input Source Selection Register, array offset: 0x838, array step: 0x4 */
       uint8_t RESERVED_4[40];
  __IO uint32_t PSMI1_IOMUXCARRAY2[IOMUXC1_PSMI1_IOMUXCARRAY2_COUNT]; /**< Module Input Source Selection Register, array offset: 0x954, array step: 0x4 */
       uint8_t RESERVED_5[16];
  __IO uint32_t PSMI1_IOMUXCARRAY3[IOMUXC1_PSMI1_IOMUXCARRAY3_COUNT]; /**< Module Input Source Selection Register, array offset: 0x994, array step: 0x4 */
       uint8_t RESERVED_6[116];
  __IO uint32_t PSMI1_IOMUXCARRAY4[IOMUXC1_PSMI1_IOMUXCARRAY4_COUNT]; /**< Module Input Source Selection Register, array offset: 0xA58, array step: 0x4 */
} IOMUXC1_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC1_Register_Masks IOMUXC1 Register Masks
 * @{
 */

/*! @name PCR1_IOMUXCARRAY0 - Pad Control Register */
/*! @{ */

#define IOMUXC1_PCR1_IOMUXCARRAY0_PS_MASK        (0x1U)
#define IOMUXC1_PCR1_IOMUXCARRAY0_PS_SHIFT       (0U)
/*! PS - Pull Select
 *  0b0..Pull-down selected
 *  0b1..Pull-up selected
 */
#define IOMUXC1_PCR1_IOMUXCARRAY0_PS(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY0_PS_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY0_PS_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY0_PE_MASK        (0x2U)
#define IOMUXC1_PCR1_IOMUXCARRAY0_PE_SHIFT       (1U)
/*! PE - Pull-up Enable
 *  0b0..pull disabled
 *  0b1..pull enabled
 */
#define IOMUXC1_PCR1_IOMUXCARRAY0_PE(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY0_PE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY0_PE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY0_SRE_MASK       (0x4U)
#define IOMUXC1_PCR1_IOMUXCARRAY0_SRE_SHIFT      (2U)
/*! SRE - Slew Rate Enable
 *  0b0..Standard Slew Rate
 *  0b1..Slow Slew Rate
 */
#define IOMUXC1_PCR1_IOMUXCARRAY0_SRE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY0_SRE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY0_SRE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY0_ODE_MASK       (0x20U)
#define IOMUXC1_PCR1_IOMUXCARRAY0_ODE_SHIFT      (5U)
/*! ODE - Open-drain Enable
 *  0b0..Push-pull Output
 *  0b1..Open-drain Output
 */
#define IOMUXC1_PCR1_IOMUXCARRAY0_ODE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY0_ODE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY0_ODE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY0_DSE_MASK       (0x40U)
#define IOMUXC1_PCR1_IOMUXCARRAY0_DSE_SHIFT      (6U)
/*! DSE - Drive Strength Enable
 *  0b0..Standard Drive Strength
 *  0b1..Hi Drive Strength
 */
#define IOMUXC1_PCR1_IOMUXCARRAY0_DSE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY0_DSE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY0_DSE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY0_MUX_MASK       (0xF00U)
#define IOMUXC1_PCR1_IOMUXCARRAY0_MUX_SHIFT      (8U)
/*! MUX - PAD Mux Selector
 *  0b0000..Alternate function 0 ; Analog / Hiz
 *  0b0001..Refer to "IO Signal Table" for availabre functions and SS values for each PAD.
 */
#define IOMUXC1_PCR1_IOMUXCARRAY0_MUX(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY0_MUX_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY0_MUX_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY0_LK_MASK        (0x8000U)
#define IOMUXC1_PCR1_IOMUXCARRAY0_LK_SHIFT       (15U)
/*! LK - Lock
 *  0b0..Register Unlocked
 *  0b1..Register Locked for write
 */
#define IOMUXC1_PCR1_IOMUXCARRAY0_LK(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY0_LK_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY0_LK_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY0_IBE_MASK       (0x10000U)
#define IOMUXC1_PCR1_IOMUXCARRAY0_IBE_SHIFT      (16U)
/*! IBE - Input Buffer Enable
 *  0b0..Input Buffer enable depends on selected function
 *  0b1..Input buffer forced enabled
 */
#define IOMUXC1_PCR1_IOMUXCARRAY0_IBE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY0_IBE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY0_IBE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY0_OBE_MASK       (0x20000U)
#define IOMUXC1_PCR1_IOMUXCARRAY0_OBE_SHIFT      (17U)
/*! OBE - Output Buffer Enable
 *  0b0..Output Buffer enable depends on selected function
 *  0b1..Output buffer forced enabled
 */
#define IOMUXC1_PCR1_IOMUXCARRAY0_OBE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY0_OBE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY0_OBE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY0_DFE_MASK       (0x100000U)
#define IOMUXC1_PCR1_IOMUXCARRAY0_DFE_SHIFT      (20U)
/*! DFE - Digital Filter Enable
 *  0b0..Digital filter disabled
 *  0b1..Digital filter enabled
 */
#define IOMUXC1_PCR1_IOMUXCARRAY0_DFE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY0_DFE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY0_DFE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY0_DFCS_MASK      (0x200000U)
#define IOMUXC1_PCR1_IOMUXCARRAY0_DFCS_SHIFT     (21U)
/*! DFCS - Digital Filter Clock Select
 *  0b0..Digital filter is running out of PCTL* Bus clock
 *  0b1..Digital filter is running out RTC 1kHz clock
 */
#define IOMUXC1_PCR1_IOMUXCARRAY0_DFCS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY0_DFCS_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY0_DFCS_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY0_DFD_MASK       (0x7C00000U)
#define IOMUXC1_PCR1_IOMUXCARRAY0_DFD_SHIFT      (22U)
/*! DFD - Digital Filter Duration
 *  0b00000..Digital filter is disabled
 *  0b00001..Filter window count value
 */
#define IOMUXC1_PCR1_IOMUXCARRAY0_DFD(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY0_DFD_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY0_DFD_MASK)
/*! @} */

/*! @name PCR1_IOMUXCARRAY1 - Pad Control Register */
/*! @{ */

#define IOMUXC1_PCR1_IOMUXCARRAY1_PS_MASK        (0x1U)
#define IOMUXC1_PCR1_IOMUXCARRAY1_PS_SHIFT       (0U)
/*! PS - Pull Select
 *  0b0..Pull-down selected
 *  0b1..Pull-up selected
 */
#define IOMUXC1_PCR1_IOMUXCARRAY1_PS(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY1_PS_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY1_PS_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY1_PE_MASK        (0x2U)
#define IOMUXC1_PCR1_IOMUXCARRAY1_PE_SHIFT       (1U)
/*! PE - Pull-up Enable
 *  0b0..pull disabled
 *  0b1..pull enabled
 */
#define IOMUXC1_PCR1_IOMUXCARRAY1_PE(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY1_PE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY1_PE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY1_SRE_MASK       (0x4U)
#define IOMUXC1_PCR1_IOMUXCARRAY1_SRE_SHIFT      (2U)
/*! SRE - Slew Rate Enable
 *  0b0..Standard Slew Rate
 *  0b1..Slow Slew Rate
 */
#define IOMUXC1_PCR1_IOMUXCARRAY1_SRE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY1_SRE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY1_SRE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY1_ODE_MASK       (0x20U)
#define IOMUXC1_PCR1_IOMUXCARRAY1_ODE_SHIFT      (5U)
/*! ODE - Open-drain Enable
 *  0b0..Push-pull Output
 *  0b1..Open-drain Output
 */
#define IOMUXC1_PCR1_IOMUXCARRAY1_ODE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY1_ODE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY1_ODE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY1_DSE_MASK       (0x40U)
#define IOMUXC1_PCR1_IOMUXCARRAY1_DSE_SHIFT      (6U)
/*! DSE - Drive Strength Enable
 *  0b0..Standard Drive Strength
 *  0b1..Hi Drive Strength
 */
#define IOMUXC1_PCR1_IOMUXCARRAY1_DSE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY1_DSE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY1_DSE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY1_MUX_MASK       (0xF00U)
#define IOMUXC1_PCR1_IOMUXCARRAY1_MUX_SHIFT      (8U)
/*! MUX - PAD Mux Selector
 *  0b0000..Alternate function 0 ; Analog / Hiz
 *  0b0001..Refer to "IO Signal Table" for availabre functions and SS values for each PAD.
 */
#define IOMUXC1_PCR1_IOMUXCARRAY1_MUX(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY1_MUX_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY1_MUX_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY1_LK_MASK        (0x8000U)
#define IOMUXC1_PCR1_IOMUXCARRAY1_LK_SHIFT       (15U)
/*! LK - Lock
 *  0b0..Register Unlocked
 *  0b1..Register Locked for write
 */
#define IOMUXC1_PCR1_IOMUXCARRAY1_LK(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY1_LK_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY1_LK_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY1_IBE_MASK       (0x10000U)
#define IOMUXC1_PCR1_IOMUXCARRAY1_IBE_SHIFT      (16U)
/*! IBE - Input Buffer Enable
 *  0b0..Input Buffer enable depends on selected function
 *  0b1..Input buffer forced enabled
 */
#define IOMUXC1_PCR1_IOMUXCARRAY1_IBE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY1_IBE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY1_IBE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY1_OBE_MASK       (0x20000U)
#define IOMUXC1_PCR1_IOMUXCARRAY1_OBE_SHIFT      (17U)
/*! OBE - Output Buffer Enable
 *  0b0..Output Buffer enable depends on selected function
 *  0b1..Output buffer forced enabled
 */
#define IOMUXC1_PCR1_IOMUXCARRAY1_OBE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY1_OBE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY1_OBE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY1_DFE_MASK       (0x100000U)
#define IOMUXC1_PCR1_IOMUXCARRAY1_DFE_SHIFT      (20U)
/*! DFE - Digital Filter Enable
 *  0b0..Digital filter disabled
 *  0b1..Digital filter enabled
 */
#define IOMUXC1_PCR1_IOMUXCARRAY1_DFE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY1_DFE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY1_DFE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY1_DFCS_MASK      (0x200000U)
#define IOMUXC1_PCR1_IOMUXCARRAY1_DFCS_SHIFT     (21U)
/*! DFCS - Digital Filter Clock Select
 *  0b0..Digital filter is running out of PCTL* Bus clock
 *  0b1..Digital filter is running out RTC 1kHz clock
 */
#define IOMUXC1_PCR1_IOMUXCARRAY1_DFCS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY1_DFCS_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY1_DFCS_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY1_DFD_MASK       (0x7C00000U)
#define IOMUXC1_PCR1_IOMUXCARRAY1_DFD_SHIFT      (22U)
/*! DFD - Digital Filter Duration
 *  0b00000..Digital filter is disabled
 *  0b00001..Filter window count value
 */
#define IOMUXC1_PCR1_IOMUXCARRAY1_DFD(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY1_DFD_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY1_DFD_MASK)
/*! @} */

/*! @name PCR1_IOMUXCARRAY2 - Pad Control Register */
/*! @{ */

#define IOMUXC1_PCR1_IOMUXCARRAY2_PS_MASK        (0x1U)
#define IOMUXC1_PCR1_IOMUXCARRAY2_PS_SHIFT       (0U)
/*! PS - Pull Select
 *  0b0..Pull-down selected
 *  0b1..Pull-up selected
 */
#define IOMUXC1_PCR1_IOMUXCARRAY2_PS(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY2_PS_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY2_PS_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY2_PE_MASK        (0x2U)
#define IOMUXC1_PCR1_IOMUXCARRAY2_PE_SHIFT       (1U)
/*! PE - Pull-up Enable
 *  0b0..pull disabled
 *  0b1..pull enabled
 */
#define IOMUXC1_PCR1_IOMUXCARRAY2_PE(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY2_PE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY2_PE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY2_SRE_MASK       (0x4U)
#define IOMUXC1_PCR1_IOMUXCARRAY2_SRE_SHIFT      (2U)
/*! SRE - Slew Rate Enable
 *  0b0..Standard Slew Rate
 *  0b1..Slow Slew Rate
 */
#define IOMUXC1_PCR1_IOMUXCARRAY2_SRE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY2_SRE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY2_SRE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY2_ODE_MASK       (0x20U)
#define IOMUXC1_PCR1_IOMUXCARRAY2_ODE_SHIFT      (5U)
/*! ODE - Open-drain Enable
 *  0b0..Push-pull Output
 *  0b1..Open-drain Output
 */
#define IOMUXC1_PCR1_IOMUXCARRAY2_ODE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY2_ODE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY2_ODE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY2_DSE_MASK       (0x40U)
#define IOMUXC1_PCR1_IOMUXCARRAY2_DSE_SHIFT      (6U)
/*! DSE - Drive Strength Enable
 *  0b0..Standard Drive Strength
 *  0b1..Hi Drive Strength
 */
#define IOMUXC1_PCR1_IOMUXCARRAY2_DSE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY2_DSE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY2_DSE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY2_MUX_MASK       (0xF00U)
#define IOMUXC1_PCR1_IOMUXCARRAY2_MUX_SHIFT      (8U)
/*! MUX - PAD Mux Selector
 *  0b0000..Alternate function 0 ; Analog / Hiz
 *  0b0001..Refer to "IO Signal Table" for availabre functions and SS values for each PAD.
 */
#define IOMUXC1_PCR1_IOMUXCARRAY2_MUX(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY2_MUX_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY2_MUX_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY2_LK_MASK        (0x8000U)
#define IOMUXC1_PCR1_IOMUXCARRAY2_LK_SHIFT       (15U)
/*! LK - Lock
 *  0b0..Register Unlocked
 *  0b1..Register Locked for write
 */
#define IOMUXC1_PCR1_IOMUXCARRAY2_LK(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY2_LK_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY2_LK_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY2_IBE_MASK       (0x10000U)
#define IOMUXC1_PCR1_IOMUXCARRAY2_IBE_SHIFT      (16U)
/*! IBE - Input Buffer Enable
 *  0b0..Input Buffer enable depends on selected function
 *  0b1..Input buffer forced enabled
 */
#define IOMUXC1_PCR1_IOMUXCARRAY2_IBE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY2_IBE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY2_IBE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY2_OBE_MASK       (0x20000U)
#define IOMUXC1_PCR1_IOMUXCARRAY2_OBE_SHIFT      (17U)
/*! OBE - Output Buffer Enable
 *  0b0..Output Buffer enable depends on selected function
 *  0b1..Output buffer forced enabled
 */
#define IOMUXC1_PCR1_IOMUXCARRAY2_OBE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY2_OBE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY2_OBE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY2_DFE_MASK       (0x100000U)
#define IOMUXC1_PCR1_IOMUXCARRAY2_DFE_SHIFT      (20U)
/*! DFE - Digital Filter Enable
 *  0b0..Digital filter disabled
 *  0b1..Digital filter enabled
 */
#define IOMUXC1_PCR1_IOMUXCARRAY2_DFE(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY2_DFE_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY2_DFE_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY2_DFCS_MASK      (0x200000U)
#define IOMUXC1_PCR1_IOMUXCARRAY2_DFCS_SHIFT     (21U)
/*! DFCS - Digital Filter Clock Select
 *  0b0..Digital filter is running out of PCTL* Bus clock
 *  0b1..Digital filter is running out RTC 1kHz clock
 */
#define IOMUXC1_PCR1_IOMUXCARRAY2_DFCS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY2_DFCS_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY2_DFCS_MASK)

#define IOMUXC1_PCR1_IOMUXCARRAY2_DFD_MASK       (0x7C00000U)
#define IOMUXC1_PCR1_IOMUXCARRAY2_DFD_SHIFT      (22U)
/*! DFD - Digital Filter Duration
 *  0b00000..Digital filter is disabled
 *  0b00001..Filter window count value
 */
#define IOMUXC1_PCR1_IOMUXCARRAY2_DFD(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PCR1_IOMUXCARRAY2_DFD_SHIFT)) & IOMUXC1_PCR1_IOMUXCARRAY2_DFD_MASK)
/*! @} */

/*! @name PSMI1_IOMUXCARRAY0 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC1_PSMI1_IOMUXCARRAY0_SSS_MASK      (0xFU)
#define IOMUXC1_PSMI1_IOMUXCARRAY0_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC1_PSMI1_IOMUXCARRAY0_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PSMI1_IOMUXCARRAY0_SSS_SHIFT)) & IOMUXC1_PSMI1_IOMUXCARRAY0_SSS_MASK)

#define IOMUXC1_PSMI1_IOMUXCARRAY0_INV_MASK      (0x8000U)
#define IOMUXC1_PSMI1_IOMUXCARRAY0_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC1_PSMI1_IOMUXCARRAY0_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PSMI1_IOMUXCARRAY0_INV_SHIFT)) & IOMUXC1_PSMI1_IOMUXCARRAY0_INV_MASK)
/*! @} */

/*! @name PSMI1_IOMUXCARRAY1 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC1_PSMI1_IOMUXCARRAY1_SSS_MASK      (0xFU)
#define IOMUXC1_PSMI1_IOMUXCARRAY1_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC1_PSMI1_IOMUXCARRAY1_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PSMI1_IOMUXCARRAY1_SSS_SHIFT)) & IOMUXC1_PSMI1_IOMUXCARRAY1_SSS_MASK)

#define IOMUXC1_PSMI1_IOMUXCARRAY1_INV_MASK      (0x8000U)
#define IOMUXC1_PSMI1_IOMUXCARRAY1_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC1_PSMI1_IOMUXCARRAY1_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PSMI1_IOMUXCARRAY1_INV_SHIFT)) & IOMUXC1_PSMI1_IOMUXCARRAY1_INV_MASK)
/*! @} */

/*! @name PSMI1_IOMUXCARRAY2 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC1_PSMI1_IOMUXCARRAY2_SSS_MASK      (0xFU)
#define IOMUXC1_PSMI1_IOMUXCARRAY2_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC1_PSMI1_IOMUXCARRAY2_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PSMI1_IOMUXCARRAY2_SSS_SHIFT)) & IOMUXC1_PSMI1_IOMUXCARRAY2_SSS_MASK)

#define IOMUXC1_PSMI1_IOMUXCARRAY2_INV_MASK      (0x8000U)
#define IOMUXC1_PSMI1_IOMUXCARRAY2_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC1_PSMI1_IOMUXCARRAY2_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PSMI1_IOMUXCARRAY2_INV_SHIFT)) & IOMUXC1_PSMI1_IOMUXCARRAY2_INV_MASK)
/*! @} */

/*! @name PSMI1_IOMUXCARRAY3 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC1_PSMI1_IOMUXCARRAY3_SSS_MASK      (0xFU)
#define IOMUXC1_PSMI1_IOMUXCARRAY3_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC1_PSMI1_IOMUXCARRAY3_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PSMI1_IOMUXCARRAY3_SSS_SHIFT)) & IOMUXC1_PSMI1_IOMUXCARRAY3_SSS_MASK)

#define IOMUXC1_PSMI1_IOMUXCARRAY3_INV_MASK      (0x8000U)
#define IOMUXC1_PSMI1_IOMUXCARRAY3_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC1_PSMI1_IOMUXCARRAY3_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PSMI1_IOMUXCARRAY3_INV_SHIFT)) & IOMUXC1_PSMI1_IOMUXCARRAY3_INV_MASK)
/*! @} */

/*! @name PSMI1_IOMUXCARRAY4 - Module Input Source Selection Register */
/*! @{ */

#define IOMUXC1_PSMI1_IOMUXCARRAY4_SSS_MASK      (0xFU)
#define IOMUXC1_PSMI1_IOMUXCARRAY4_SSS_SHIFT     (0U)
/*! SSS - Source Selection
 *  0b0000..No input Pad is selected. Module input is in safe state
 *  0b0001..Defines Pad source
 */
#define IOMUXC1_PSMI1_IOMUXCARRAY4_SSS(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PSMI1_IOMUXCARRAY4_SSS_SHIFT)) & IOMUXC1_PSMI1_IOMUXCARRAY4_SSS_MASK)

#define IOMUXC1_PSMI1_IOMUXCARRAY4_INV_MASK      (0x8000U)
#define IOMUXC1_PSMI1_IOMUXCARRAY4_INV_SHIFT     (15U)
/*! INV - Input path inversion
 *  0b0..Do not inverts signal polarity
 *  0b1..Inverts signal polarity
 */
#define IOMUXC1_PSMI1_IOMUXCARRAY4_INV(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC1_PSMI1_IOMUXCARRAY4_INV_SHIFT)) & IOMUXC1_PSMI1_IOMUXCARRAY4_INV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC1_Register_Masks */


/*!
 * @}
 */ /* end of group IOMUXC1_Peripheral_Access_Layer */


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


#endif  /* PERI_IOMUXC1_H_ */

