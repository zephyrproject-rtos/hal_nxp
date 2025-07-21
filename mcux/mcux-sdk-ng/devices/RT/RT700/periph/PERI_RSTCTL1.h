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
**         CMSIS Peripheral Access Layer for RSTCTL1
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
 * @file PERI_RSTCTL1.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RSTCTL1
 *
 * CMSIS Peripheral Access Layer for RSTCTL1
 */

#if !defined(PERI_RSTCTL1_H_)
#define PERI_RSTCTL1_H_                          /**< Symbol preventing repeated inclusion */

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
   -- RSTCTL1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL1_Peripheral_Access_Layer RSTCTL1 Peripheral Access Layer
 * @{
 */

/** RSTCTL1 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t PRSTCTL0;                          /**< Sense Domain Private Peripheral Reset Control 0, offset: 0x10 */
       uint8_t RESERVED_1[44];
  __O  uint32_t PRSTCTL0_SET;                      /**< Sense Domain Private Peripheral Reset Control 0 SET, offset: 0x40 */
       uint8_t RESERVED_2[44];
  __O  uint32_t PRSTCTL0_CLR;                      /**< Sense Domain Private Peripheral Reset Control 0 CLR, offset: 0x70 */
} RSTCTL1_Type;

/* ----------------------------------------------------------------------------
   -- RSTCTL1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL1_Register_Masks RSTCTL1 Register Masks
 * @{
 */

/*! @name PRSTCTL0 - Sense Domain Private Peripheral Reset Control 0 */
/*! @{ */

#define RSTCTL1_PRSTCTL0_HIFI1_MASK              (0x2U)
#define RSTCTL1_PRSTCTL0_HIFI1_SHIFT             (1U)
/*! HiFi1 - HiFi1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_HIFI1(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_HIFI1_SHIFT)) & RSTCTL1_PRSTCTL0_HIFI1_MASK)

#define RSTCTL1_PRSTCTL0_HIFI1_DEBUG_MASK        (0x4U)
#define RSTCTL1_PRSTCTL0_HIFI1_DEBUG_SHIFT       (2U)
/*! HiFi1_DEBUG - HiFi1 Debug Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_HIFI1_DEBUG(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_HIFI1_DEBUG_SHIFT)) & RSTCTL1_PRSTCTL0_HIFI1_DEBUG_MASK)

#define RSTCTL1_PRSTCTL0_EDMA2_MASK              (0x10U)
#define RSTCTL1_PRSTCTL0_EDMA2_SHIFT             (4U)
/*! eDMA2 - eDMA2 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_EDMA2(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_EDMA2_SHIFT)) & RSTCTL1_PRSTCTL0_EDMA2_MASK)

#define RSTCTL1_PRSTCTL0_EDMA3_MASK              (0x20U)
#define RSTCTL1_PRSTCTL0_EDMA3_SHIFT             (5U)
/*! eDMA3 - eDMA3 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_EDMA3(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_EDMA3_SHIFT)) & RSTCTL1_PRSTCTL0_EDMA3_MASK)

#define RSTCTL1_PRSTCTL0_LP_FLEXCOMM17_MASK      (0x40U)
#define RSTCTL1_PRSTCTL0_LP_FLEXCOMM17_SHIFT     (6U)
/*! LP_FLEXCOMM17 - LP_FLEXCOMM17 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_LP_FLEXCOMM17(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_LP_FLEXCOMM17_SHIFT)) & RSTCTL1_PRSTCTL0_LP_FLEXCOMM17_MASK)

#define RSTCTL1_PRSTCTL0_LP_FLEXCOMM18_MASK      (0x80U)
#define RSTCTL1_PRSTCTL0_LP_FLEXCOMM18_SHIFT     (7U)
/*! LP_FLEXCOMM18 - LP_FLEXCOMM18 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_LP_FLEXCOMM18(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_LP_FLEXCOMM18_SHIFT)) & RSTCTL1_PRSTCTL0_LP_FLEXCOMM18_MASK)

#define RSTCTL1_PRSTCTL0_LP_FLEXCOMM19_MASK      (0x100U)
#define RSTCTL1_PRSTCTL0_LP_FLEXCOMM19_SHIFT     (8U)
/*! LP_FLEXCOMM19 - LP_FLEXCOMM19 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_LP_FLEXCOMM19(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_LP_FLEXCOMM19_SHIFT)) & RSTCTL1_PRSTCTL0_LP_FLEXCOMM19_MASK)

#define RSTCTL1_PRSTCTL0_LP_FLEXCOMM20_MASK      (0x200U)
#define RSTCTL1_PRSTCTL0_LP_FLEXCOMM20_SHIFT     (9U)
/*! LP_FLEXCOMM20 - LP_FLEXCOMM20 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_LP_FLEXCOMM20(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_LP_FLEXCOMM20_SHIFT)) & RSTCTL1_PRSTCTL0_LP_FLEXCOMM20_MASK)

#define RSTCTL1_PRSTCTL0_SAI3_MASK               (0x400U)
#define RSTCTL1_PRSTCTL0_SAI3_SHIFT              (10U)
/*! SAI3 - SAI3 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SAI3(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SAI3_SHIFT)) & RSTCTL1_PRSTCTL0_SAI3_MASK)

#define RSTCTL1_PRSTCTL0_I3C2_MASK               (0x800U)
#define RSTCTL1_PRSTCTL0_I3C2_SHIFT              (11U)
/*! I3C2 - I3C2 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_I3C2(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_I3C2_SHIFT)) & RSTCTL1_PRSTCTL0_I3C2_MASK)

#define RSTCTL1_PRSTCTL0_I3C3_MASK               (0x1000U)
#define RSTCTL1_PRSTCTL0_I3C3_SHIFT              (12U)
/*! I3C3 - I3C3 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_I3C3(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_I3C3_SHIFT)) & RSTCTL1_PRSTCTL0_I3C3_MASK)

#define RSTCTL1_PRSTCTL0_GPIO8_MASK              (0x2000U)
#define RSTCTL1_PRSTCTL0_GPIO8_SHIFT             (13U)
/*! GPIO8 - GPIO8 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_GPIO8(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_GPIO8_SHIFT)) & RSTCTL1_PRSTCTL0_GPIO8_MASK)

#define RSTCTL1_PRSTCTL0_GPIO9_MASK              (0x4000U)
#define RSTCTL1_PRSTCTL0_GPIO9_SHIFT             (14U)
/*! GPIO9 - GPIO9 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_GPIO9(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_GPIO9_SHIFT)) & RSTCTL1_PRSTCTL0_GPIO9_MASK)

#define RSTCTL1_PRSTCTL0_GPIO10_MASK             (0x8000U)
#define RSTCTL1_PRSTCTL0_GPIO10_SHIFT            (15U)
/*! GPIO10 - GPIO10 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_GPIO10(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_GPIO10_SHIFT)) & RSTCTL1_PRSTCTL0_GPIO10_MASK)

#define RSTCTL1_PRSTCTL0_PINT1_MASK              (0x10000U)
#define RSTCTL1_PRSTCTL0_PINT1_SHIFT             (16U)
/*! PINT1 - PINT1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_PINT1(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_PINT1_SHIFT)) & RSTCTL1_PRSTCTL0_PINT1_MASK)

#define RSTCTL1_PRSTCTL0_CTIMER5_MASK            (0x20000U)
#define RSTCTL1_PRSTCTL0_CTIMER5_SHIFT           (17U)
/*! CTIMER5 - CTIMER5 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_CTIMER5(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CTIMER5_SHIFT)) & RSTCTL1_PRSTCTL0_CTIMER5_MASK)

#define RSTCTL1_PRSTCTL0_CTIMER6_MASK            (0x40000U)
#define RSTCTL1_PRSTCTL0_CTIMER6_SHIFT           (18U)
/*! CTIMER6 - CTIMER6 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_CTIMER6(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CTIMER6_SHIFT)) & RSTCTL1_PRSTCTL0_CTIMER6_MASK)

#define RSTCTL1_PRSTCTL0_CTIMER7_MASK            (0x80000U)
#define RSTCTL1_PRSTCTL0_CTIMER7_SHIFT           (19U)
/*! CTIMER7 - CTIMER7 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_CTIMER7(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CTIMER7_SHIFT)) & RSTCTL1_PRSTCTL0_CTIMER7_MASK)

#define RSTCTL1_PRSTCTL0_MRT1_MASK               (0x100000U)
#define RSTCTL1_PRSTCTL0_MRT1_SHIFT              (20U)
/*! MRT1 - MRT1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_MRT1(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_MRT1_SHIFT)) & RSTCTL1_PRSTCTL0_MRT1_MASK)

#define RSTCTL1_PRSTCTL0_UTICK1_MASK             (0x200000U)
#define RSTCTL1_PRSTCTL0_UTICK1_SHIFT            (21U)
/*! UTICK1 - UTICK1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_UTICK1(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_UTICK1_SHIFT)) & RSTCTL1_PRSTCTL0_UTICK1_MASK)

#define RSTCTL1_PRSTCTL0_MU3_MASK                (0x1000000U)
#define RSTCTL1_PRSTCTL0_MU3_SHIFT               (24U)
/*! MU3 - MU3 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_MU3(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_MU3_SHIFT)) & RSTCTL1_PRSTCTL0_MU3_MASK)

#define RSTCTL1_PRSTCTL0_SEMA42_3_MASK           (0x2000000U)
#define RSTCTL1_PRSTCTL0_SEMA42_3_SHIFT          (25U)
/*! SEMA42_3 - SEMA42_3 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SEMA42_3(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SEMA42_3_SHIFT)) & RSTCTL1_PRSTCTL0_SEMA42_3_MASK)

#define RSTCTL1_PRSTCTL0_PVT1_MASK               (0x10000000U)
#define RSTCTL1_PRSTCTL0_PVT1_SHIFT              (28U)
/*! PVT1 - PVT1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_PVT1(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_PVT1_SHIFT)) & RSTCTL1_PRSTCTL0_PVT1_MASK)
/*! @} */

/*! @name PRSTCTL0_SET - Sense Domain Private Peripheral Reset Control 0 SET */
/*! @{ */

#define RSTCTL1_PRSTCTL0_SET_HIFI1_MASK          (0x2U)
#define RSTCTL1_PRSTCTL0_SET_HIFI1_SHIFT         (1U)
/*! HiFi1 - HiFi1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_HIFI1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_HIFI1_SHIFT)) & RSTCTL1_PRSTCTL0_SET_HIFI1_MASK)

#define RSTCTL1_PRSTCTL0_SET_HIFI1_DEBUG_MASK    (0x4U)
#define RSTCTL1_PRSTCTL0_SET_HIFI1_DEBUG_SHIFT   (2U)
/*! HiFi1_DEBUG - HiFi1 Debug Reset
 *  0b0..No effect.
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_HIFI1_DEBUG(x)      (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_HIFI1_DEBUG_SHIFT)) & RSTCTL1_PRSTCTL0_SET_HIFI1_DEBUG_MASK)

#define RSTCTL1_PRSTCTL0_SET_EDMA2_MASK          (0x10U)
#define RSTCTL1_PRSTCTL0_SET_EDMA2_SHIFT         (4U)
/*! eDMA2 - eDMA2 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_EDMA2(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_EDMA2_SHIFT)) & RSTCTL1_PRSTCTL0_SET_EDMA2_MASK)

#define RSTCTL1_PRSTCTL0_SET_EDMA3_MASK          (0x20U)
#define RSTCTL1_PRSTCTL0_SET_EDMA3_SHIFT         (5U)
/*! eDMA3 - eDMA3 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_EDMA3(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_EDMA3_SHIFT)) & RSTCTL1_PRSTCTL0_SET_EDMA3_MASK)

#define RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM17_MASK  (0x40U)
#define RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM17_SHIFT (6U)
/*! LP_FLEXCOMM17 - LP_FLEXCOMM17 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM17(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM17_SHIFT)) & RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM17_MASK)

#define RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM18_MASK  (0x80U)
#define RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM18_SHIFT (7U)
/*! LP_FLEXCOMM18 - LP_FLEXCOMM18 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM18(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM18_SHIFT)) & RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM18_MASK)

#define RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM19_MASK  (0x100U)
#define RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM19_SHIFT (8U)
/*! LP_FLEXCOMM19 - LP_FLEXCOMM19 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM19(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM19_SHIFT)) & RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM19_MASK)

#define RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM20_MASK  (0x200U)
#define RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM20_SHIFT (9U)
/*! LP_FLEXCOMM20 - LP_FLEXCOMM20 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM20(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM20_SHIFT)) & RSTCTL1_PRSTCTL0_SET_LP_FLEXCOMM20_MASK)

#define RSTCTL1_PRSTCTL0_SET_SAI3_MASK           (0x400U)
#define RSTCTL1_PRSTCTL0_SET_SAI3_SHIFT          (10U)
/*! SAI3 - SAI3 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_SAI3(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_SAI3_SHIFT)) & RSTCTL1_PRSTCTL0_SET_SAI3_MASK)

#define RSTCTL1_PRSTCTL0_SET_I3C2_MASK           (0x800U)
#define RSTCTL1_PRSTCTL0_SET_I3C2_SHIFT          (11U)
/*! I3C2 - I3C2 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_I3C2(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_I3C2_SHIFT)) & RSTCTL1_PRSTCTL0_SET_I3C2_MASK)

#define RSTCTL1_PRSTCTL0_SET_I3C3_MASK           (0x1000U)
#define RSTCTL1_PRSTCTL0_SET_I3C3_SHIFT          (12U)
/*! I3C3 - I3C3 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_I3C3(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_I3C3_SHIFT)) & RSTCTL1_PRSTCTL0_SET_I3C3_MASK)

#define RSTCTL1_PRSTCTL0_SET_GPIO8_MASK          (0x2000U)
#define RSTCTL1_PRSTCTL0_SET_GPIO8_SHIFT         (13U)
/*! GPIO8 - GPIO8 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_GPIO8(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_GPIO8_SHIFT)) & RSTCTL1_PRSTCTL0_SET_GPIO8_MASK)

#define RSTCTL1_PRSTCTL0_SET_GPIO9_MASK          (0x4000U)
#define RSTCTL1_PRSTCTL0_SET_GPIO9_SHIFT         (14U)
/*! GPIO9 - GPIO9 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_GPIO9(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_GPIO9_SHIFT)) & RSTCTL1_PRSTCTL0_SET_GPIO9_MASK)

#define RSTCTL1_PRSTCTL0_SET_GPIO10_MASK         (0x8000U)
#define RSTCTL1_PRSTCTL0_SET_GPIO10_SHIFT        (15U)
/*! GPIO10 - GPIO10 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_GPIO10(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_GPIO10_SHIFT)) & RSTCTL1_PRSTCTL0_SET_GPIO10_MASK)

#define RSTCTL1_PRSTCTL0_SET_PINT1_MASK          (0x10000U)
#define RSTCTL1_PRSTCTL0_SET_PINT1_SHIFT         (16U)
/*! PINT1 - PINT1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_PINT1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_PINT1_SHIFT)) & RSTCTL1_PRSTCTL0_SET_PINT1_MASK)

#define RSTCTL1_PRSTCTL0_SET_CTIMER5_MASK        (0x20000U)
#define RSTCTL1_PRSTCTL0_SET_CTIMER5_SHIFT       (17U)
/*! CTIMER5 - CTIMER5 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_CTIMER5(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_CTIMER5_SHIFT)) & RSTCTL1_PRSTCTL0_SET_CTIMER5_MASK)

#define RSTCTL1_PRSTCTL0_SET_CTIMER6_MASK        (0x40000U)
#define RSTCTL1_PRSTCTL0_SET_CTIMER6_SHIFT       (18U)
/*! CTIMER6 - CTIMER6 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_CTIMER6(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_CTIMER6_SHIFT)) & RSTCTL1_PRSTCTL0_SET_CTIMER6_MASK)

#define RSTCTL1_PRSTCTL0_SET_CTIMER7_MASK        (0x80000U)
#define RSTCTL1_PRSTCTL0_SET_CTIMER7_SHIFT       (19U)
/*! CTIMER7 - CTIMER7 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_CTIMER7(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_CTIMER7_SHIFT)) & RSTCTL1_PRSTCTL0_SET_CTIMER7_MASK)

#define RSTCTL1_PRSTCTL0_SET_MRT1_MASK           (0x100000U)
#define RSTCTL1_PRSTCTL0_SET_MRT1_SHIFT          (20U)
/*! MRT1 - MRT1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_MRT1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_MRT1_SHIFT)) & RSTCTL1_PRSTCTL0_SET_MRT1_MASK)

#define RSTCTL1_PRSTCTL0_SET_UTICK1_MASK         (0x200000U)
#define RSTCTL1_PRSTCTL0_SET_UTICK1_SHIFT        (21U)
/*! UTICK1 - UTICK1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_UTICK1(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_UTICK1_SHIFT)) & RSTCTL1_PRSTCTL0_SET_UTICK1_MASK)

#define RSTCTL1_PRSTCTL0_SET_MU3_MASK            (0x1000000U)
#define RSTCTL1_PRSTCTL0_SET_MU3_SHIFT           (24U)
/*! MU3 - MU3 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_MU3(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_MU3_SHIFT)) & RSTCTL1_PRSTCTL0_SET_MU3_MASK)

#define RSTCTL1_PRSTCTL0_SET_SEMA42_3_MASK       (0x2000000U)
#define RSTCTL1_PRSTCTL0_SET_SEMA42_3_SHIFT      (25U)
/*! SEMA42_3 - SEMA42_3 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_SEMA42_3(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_SEMA42_3_SHIFT)) & RSTCTL1_PRSTCTL0_SET_SEMA42_3_MASK)

#define RSTCTL1_PRSTCTL0_SET_PVT1_MASK           (0x10000000U)
#define RSTCTL1_PRSTCTL0_SET_PVT1_SHIFT          (28U)
/*! PVT1 - PVT1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL1_PRSTCTL0_SET_PVT1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_SET_PVT1_SHIFT)) & RSTCTL1_PRSTCTL0_SET_PVT1_MASK)
/*! @} */

/*! @name PRSTCTL0_CLR - Sense Domain Private Peripheral Reset Control 0 CLR */
/*! @{ */

#define RSTCTL1_PRSTCTL0_CLR_HIFI1_MASK          (0x2U)
#define RSTCTL1_PRSTCTL0_CLR_HIFI1_SHIFT         (1U)
/*! HiFi1 - HiFi1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_HIFI1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_HIFI1_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_HIFI1_MASK)

#define RSTCTL1_PRSTCTL0_CLR_HIFI1_DEBUG_MASK    (0x4U)
#define RSTCTL1_PRSTCTL0_CLR_HIFI1_DEBUG_SHIFT   (2U)
/*! HiFi1_DEBUG - HiFi1 Debug Reset
 *  0b0..No effect.
 *  0b1..Clears reset
 */
#define RSTCTL1_PRSTCTL0_CLR_HIFI1_DEBUG(x)      (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_HIFI1_DEBUG_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_HIFI1_DEBUG_MASK)

#define RSTCTL1_PRSTCTL0_CLR_EDMA2_MASK          (0x10U)
#define RSTCTL1_PRSTCTL0_CLR_EDMA2_SHIFT         (4U)
/*! eDMA2 - eDMA2 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_EDMA2(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_EDMA2_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_EDMA2_MASK)

#define RSTCTL1_PRSTCTL0_CLR_EDMA3_MASK          (0x20U)
#define RSTCTL1_PRSTCTL0_CLR_EDMA3_SHIFT         (5U)
/*! eDMA3 - eDMA3 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_EDMA3(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_EDMA3_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_EDMA3_MASK)

#define RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM17_MASK  (0x40U)
#define RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM17_SHIFT (6U)
/*! LP_FLEXCOMM17 - LP_FLEXCOMM17 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM17(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM17_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM17_MASK)

#define RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM18_MASK  (0x80U)
#define RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM18_SHIFT (7U)
/*! LP_FLEXCOMM18 - LP_FLEXCOMM18 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM18(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM18_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM18_MASK)

#define RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM19_MASK  (0x100U)
#define RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM19_SHIFT (8U)
/*! LP_FLEXCOMM19 - LP_FLEXCOMM19 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM19(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM19_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM19_MASK)

#define RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM20_MASK  (0x200U)
#define RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM20_SHIFT (9U)
/*! LP_FLEXCOMM20 - LP_FLEXCOMM20 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM20(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM20_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_LP_FLEXCOMM20_MASK)

#define RSTCTL1_PRSTCTL0_CLR_SAI3_MASK           (0x400U)
#define RSTCTL1_PRSTCTL0_CLR_SAI3_SHIFT          (10U)
/*! SAI3 - SAI3 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_SAI3(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_SAI3_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_SAI3_MASK)

#define RSTCTL1_PRSTCTL0_CLR_I3C2_MASK           (0x800U)
#define RSTCTL1_PRSTCTL0_CLR_I3C2_SHIFT          (11U)
/*! I3C2 - I3C2 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_I3C2(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_I3C2_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_I3C2_MASK)

#define RSTCTL1_PRSTCTL0_CLR_I3C3_MASK           (0x1000U)
#define RSTCTL1_PRSTCTL0_CLR_I3C3_SHIFT          (12U)
/*! I3C3 - I3C3 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_I3C3(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_I3C3_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_I3C3_MASK)

#define RSTCTL1_PRSTCTL0_CLR_GPIO8_MASK          (0x2000U)
#define RSTCTL1_PRSTCTL0_CLR_GPIO8_SHIFT         (13U)
/*! GPIO8 - GPIO8 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_GPIO8(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_GPIO8_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_GPIO8_MASK)

#define RSTCTL1_PRSTCTL0_CLR_GPIO9_MASK          (0x4000U)
#define RSTCTL1_PRSTCTL0_CLR_GPIO9_SHIFT         (14U)
/*! GPIO9 - GPIO9 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_GPIO9(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_GPIO9_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_GPIO9_MASK)

#define RSTCTL1_PRSTCTL0_CLR_GPIO10_MASK         (0x8000U)
#define RSTCTL1_PRSTCTL0_CLR_GPIO10_SHIFT        (15U)
/*! GPIO10 - GPIO10 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_GPIO10(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_GPIO10_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_GPIO10_MASK)

#define RSTCTL1_PRSTCTL0_CLR_PINT1_MASK          (0x10000U)
#define RSTCTL1_PRSTCTL0_CLR_PINT1_SHIFT         (16U)
/*! PINT1 - PINT1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_PINT1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_PINT1_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_PINT1_MASK)

#define RSTCTL1_PRSTCTL0_CLR_CTIMER5_MASK        (0x20000U)
#define RSTCTL1_PRSTCTL0_CLR_CTIMER5_SHIFT       (17U)
/*! CTIMER5 - CTIMER5 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_CTIMER5(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_CTIMER5_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_CTIMER5_MASK)

#define RSTCTL1_PRSTCTL0_CLR_CTIMER6_MASK        (0x40000U)
#define RSTCTL1_PRSTCTL0_CLR_CTIMER6_SHIFT       (18U)
/*! CTIMER6 - CTIMER6 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_CTIMER6(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_CTIMER6_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_CTIMER6_MASK)

#define RSTCTL1_PRSTCTL0_CLR_CTIMER7_MASK        (0x80000U)
#define RSTCTL1_PRSTCTL0_CLR_CTIMER7_SHIFT       (19U)
/*! CTIMER7 - CTIMER7 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_CTIMER7(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_CTIMER7_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_CTIMER7_MASK)

#define RSTCTL1_PRSTCTL0_CLR_MRT1_MASK           (0x100000U)
#define RSTCTL1_PRSTCTL0_CLR_MRT1_SHIFT          (20U)
/*! MRT1 - MRT1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_MRT1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_MRT1_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_MRT1_MASK)

#define RSTCTL1_PRSTCTL0_CLR_UTICK1_MASK         (0x200000U)
#define RSTCTL1_PRSTCTL0_CLR_UTICK1_SHIFT        (21U)
/*! UTICK1 - UTICK1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_UTICK1(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_UTICK1_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_UTICK1_MASK)

#define RSTCTL1_PRSTCTL0_CLR_MU3_MASK            (0x1000000U)
#define RSTCTL1_PRSTCTL0_CLR_MU3_SHIFT           (24U)
/*! MU3 - MU3 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_MU3(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_MU3_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_MU3_MASK)

#define RSTCTL1_PRSTCTL0_CLR_SEMA42_3_MASK       (0x2000000U)
#define RSTCTL1_PRSTCTL0_CLR_SEMA42_3_SHIFT      (25U)
/*! SEMA42_3 - SEMA42_3 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_SEMA42_3(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_SEMA42_3_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_SEMA42_3_MASK)

#define RSTCTL1_PRSTCTL0_CLR_PVT1_MASK           (0x10000000U)
#define RSTCTL1_PRSTCTL0_CLR_PVT1_SHIFT          (28U)
/*! PVT1 - PVT1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL1_PRSTCTL0_CLR_PVT1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL1_PRSTCTL0_CLR_PVT1_SHIFT)) & RSTCTL1_PRSTCTL0_CLR_PVT1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RSTCTL1_Register_Masks */


/*!
 * @}
 */ /* end of group RSTCTL1_Peripheral_Access_Layer */


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


#endif  /* PERI_RSTCTL1_H_ */

