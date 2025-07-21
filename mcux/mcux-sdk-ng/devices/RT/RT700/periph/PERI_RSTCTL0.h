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
**         CMSIS Peripheral Access Layer for RSTCTL0
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
 * @file PERI_RSTCTL0.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RSTCTL0
 *
 * CMSIS Peripheral Access Layer for RSTCTL0
 */

#if !defined(PERI_RSTCTL0_H_)
#define PERI_RSTCTL0_H_                          /**< Symbol preventing repeated inclusion */

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
   -- RSTCTL0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL0_Peripheral_Access_Layer RSTCTL0 Peripheral Access Layer
 * @{
 */

/** RSTCTL0 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __I  uint32_t DOMRSTSTAT;                        /**< Domain Reset Status, offset: 0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t PRSTCTL0;                          /**< Common Domain Peripheral Reset Control 0, offset: 0x10 */
  __IO uint32_t PRSTCTL1;                          /**< Compute Domain Peripheral Reset Control 1, offset: 0x14 */
  __IO uint32_t PRSTCTL2;                          /**< Compute Domain Peripheral Reset Control 2, offset: 0x18 */
  __IO uint32_t PRSTCTL3;                          /**< Compute Domain Peripheral Reset Control 3, offset: 0x1C */
  __IO uint32_t PRSTCTL4;                          /**< Compute Domain Peripheral Reset Control 4, offset: 0x20 */
  __IO uint32_t PRSTCTL5;                          /**< DSP Domain Peripheral Reset Control 5, offset: 0x24 */
       uint8_t RESERVED_2[24];
  __O  uint32_t PRSTCTL0_SET;                      /**< Common Domain Peripheral Reset Control 0 SET, offset: 0x40 */
  __O  uint32_t PRSTCTL1_SET;                      /**< Compute Domain Peripheral Reset Control 1 SET, offset: 0x44 */
  __O  uint32_t PRSTCTL2_SET;                      /**< Compute Domain Peripheral Reset Control 2 SET, offset: 0x48 */
  __O  uint32_t PRSTCTL3_SET;                      /**< Compute Domain Peripheral Reset Control 3 SET, offset: 0x4C */
  __O  uint32_t PRSTCTL4_SET;                      /**< Compute Domain Peripheral Reset Control 4 SET, offset: 0x50 */
  __O  uint32_t PRSTCTL5_SET;                      /**< DSP Domain Peripheral Reset Control 5 SET, offset: 0x54 */
       uint8_t RESERVED_3[24];
  __O  uint32_t PRSTCTL0_CLR;                      /**< Common Domain Peripheral Reset Control 0 CLR, offset: 0x70 */
  __O  uint32_t PRSTCTL1_CLR;                      /**< Compute Domain Peripheral Reset Control 1 CLR, offset: 0x74 */
  __O  uint32_t PRSTCTL2_CLR;                      /**< Compute Domain Peripheral Reset Control 2 CLR, offset: 0x78 */
  __O  uint32_t PRSTCTL3_CLR;                      /**< Compute Domain Peripheral Reset Control 3 CLR, offset: 0x7C */
  __O  uint32_t PRSTCTL4_CLR;                      /**< Compute Domain Peripheral Reset Control 4 CLR, offset: 0x80 */
  __O  uint32_t PRSTCTL5_CLR;                      /**< DSP Domain Peripheral Reset Control 5 CLR, offset: 0x84 */
} RSTCTL0_Type;

/* ----------------------------------------------------------------------------
   -- RSTCTL0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL0_Register_Masks RSTCTL0 Register Masks
 * @{
 */

/*! @name DOMRSTSTAT - Domain Reset Status */
/*! @{ */

#define RSTCTL0_DOMRSTSTAT_SENSE_STAT_MASK       (0x1U)
#define RSTCTL0_DOMRSTSTAT_SENSE_STAT_SHIFT      (0U)
/*! SENSE_STAT - VDD1_SENSE Domain Reset State
 *  0b0..The domain is in reset state.
 *  0b1..The domain is in normal run state.
 */
#define RSTCTL0_DOMRSTSTAT_SENSE_STAT(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_DOMRSTSTAT_SENSE_STAT_SHIFT)) & RSTCTL0_DOMRSTSTAT_SENSE_STAT_MASK)

#define RSTCTL0_DOMRSTSTAT_COM2_STAT_MASK        (0x2U)
#define RSTCTL0_DOMRSTSTAT_COM2_STAT_SHIFT       (1U)
/*! COM2_STAT - VDD2_COM (Main) Domain Reset State
 *  0b0..The domain is in reset state.
 *  0b1..The domain is in normal run state.
 */
#define RSTCTL0_DOMRSTSTAT_COM2_STAT(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_DOMRSTSTAT_COM2_STAT_SHIFT)) & RSTCTL0_DOMRSTSTAT_COM2_STAT_MASK)

#define RSTCTL0_DOMRSTSTAT_COMN_STAT_MASK        (0x4U)
#define RSTCTL0_DOMRSTSTAT_COMN_STAT_SHIFT       (2U)
/*! COMN_STAT - VDDN_COM Domain Reset State
 *  0b0..The domain is in reset state.
 *  0b1..The domain is in normal run state.
 */
#define RSTCTL0_DOMRSTSTAT_COMN_STAT(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_DOMRSTSTAT_COMN_STAT_SHIFT)) & RSTCTL0_DOMRSTSTAT_COMN_STAT_MASK)

#define RSTCTL0_DOMRSTSTAT_COMP_STAT_MASK        (0x8U)
#define RSTCTL0_DOMRSTSTAT_COMP_STAT_SHIFT       (3U)
/*! COMP_STAT - VDD2_COMP Domain Reset State
 *  0b0..The domain is in reset state.
 *  0b1..The domain is in normal run state.
 */
#define RSTCTL0_DOMRSTSTAT_COMP_STAT(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_DOMRSTSTAT_COMP_STAT_SHIFT)) & RSTCTL0_DOMRSTSTAT_COMP_STAT_MASK)

#define RSTCTL0_DOMRSTSTAT_DSP_STAT_MASK         (0x10U)
#define RSTCTL0_DOMRSTSTAT_DSP_STAT_SHIFT        (4U)
/*! DSP_STAT - VDD2_DSP Domain Reset State
 *  0b0..The domain is in reset state.
 *  0b1..The domain is in normal run state.
 */
#define RSTCTL0_DOMRSTSTAT_DSP_STAT(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_DOMRSTSTAT_DSP_STAT_SHIFT)) & RSTCTL0_DOMRSTSTAT_DSP_STAT_MASK)

#define RSTCTL0_DOMRSTSTAT_MEDIA_STAT_MASK       (0x20U)
#define RSTCTL0_DOMRSTSTAT_MEDIA_STAT_SHIFT      (5U)
/*! MEDIA_STAT - VDD2_MEDIA Domain Reset State
 *  0b0..The domain is in reset state.
 *  0b1..The domain is in normal run state.
 */
#define RSTCTL0_DOMRSTSTAT_MEDIA_STAT(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_DOMRSTSTAT_MEDIA_STAT_SHIFT)) & RSTCTL0_DOMRSTSTAT_MEDIA_STAT_MASK)
/*! @} */

/*! @name PRSTCTL0 - Common Domain Peripheral Reset Control 0 */
/*! @{ */

#define RSTCTL0_PRSTCTL0_IOPCTL0_MASK            (0x40U)
#define RSTCTL0_PRSTCTL0_IOPCTL0_SHIFT           (6U)
/*! IOPCTL0 - IOPCTL0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL0_IOPCTL0(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_IOPCTL0_SHIFT)) & RSTCTL0_PRSTCTL0_IOPCTL0_MASK)
/*! @} */

/*! @name PRSTCTL1 - Compute Domain Peripheral Reset Control 1 */
/*! @{ */

#define RSTCTL0_PRSTCTL1_ELS_MASK                (0x1U)
#define RSTCTL0_PRSTCTL1_ELS_SHIFT               (0U)
/*! ELS - ELS Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL1_ELS(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_ELS_SHIFT)) & RSTCTL0_PRSTCTL1_ELS_MASK)
/*! @} */

/*! @name PRSTCTL2 - Compute Domain Peripheral Reset Control 2 */
/*! @{ */

#define RSTCTL0_PRSTCTL2_EDMA0_MASK              (0x20U)
#define RSTCTL0_PRSTCTL2_EDMA0_SHIFT             (5U)
/*! eDMA0 - eDMA0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_EDMA0(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_EDMA0_SHIFT)) & RSTCTL0_PRSTCTL2_EDMA0_MASK)

#define RSTCTL0_PRSTCTL2_EDMA1_MASK              (0x40U)
#define RSTCTL0_PRSTCTL2_EDMA1_SHIFT             (6U)
/*! eDMA1 - eDMA1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_EDMA1(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_EDMA1_SHIFT)) & RSTCTL0_PRSTCTL2_EDMA1_MASK)

#define RSTCTL0_PRSTCTL2_PKC_MASK                (0x100U)
#define RSTCTL0_PRSTCTL2_PKC_SHIFT               (8U)
/*! PKC - PKC Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_PKC(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_PKC_SHIFT)) & RSTCTL0_PRSTCTL2_PKC_MASK)

#define RSTCTL0_PRSTCTL2_XSPI0_MASK              (0x400U)
#define RSTCTL0_PRSTCTL2_XSPI0_SHIFT             (10U)
/*! XSPI0 - XSPI0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_XSPI0(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_XSPI0_SHIFT)) & RSTCTL0_PRSTCTL2_XSPI0_MASK)

#define RSTCTL0_PRSTCTL2_XSPI1_MASK              (0x800U)
#define RSTCTL0_PRSTCTL2_XSPI1_SHIFT             (11U)
/*! XSPI1 - XSPI1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_XSPI1(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_XSPI1_SHIFT)) & RSTCTL0_PRSTCTL2_XSPI1_MASK)

#define RSTCTL0_PRSTCTL2_GPIO0_MASK              (0x40000U)
#define RSTCTL0_PRSTCTL2_GPIO0_SHIFT             (18U)
/*! GPIO0 - GPIO0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_GPIO0(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_GPIO0_SHIFT)) & RSTCTL0_PRSTCTL2_GPIO0_MASK)

#define RSTCTL0_PRSTCTL2_GPIO1_MASK              (0x80000U)
#define RSTCTL0_PRSTCTL2_GPIO1_SHIFT             (19U)
/*! GPIO1 - GPIO1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_GPIO1(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_GPIO1_SHIFT)) & RSTCTL0_PRSTCTL2_GPIO1_MASK)

#define RSTCTL0_PRSTCTL2_GPIO2_MASK              (0x100000U)
#define RSTCTL0_PRSTCTL2_GPIO2_SHIFT             (20U)
/*! GPIO2 - GPIO2 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_GPIO2(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_GPIO2_SHIFT)) & RSTCTL0_PRSTCTL2_GPIO2_MASK)

#define RSTCTL0_PRSTCTL2_GPIO3_MASK              (0x200000U)
#define RSTCTL0_PRSTCTL2_GPIO3_SHIFT             (21U)
/*! GPIO3 - GPIO3 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_GPIO3(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_GPIO3_SHIFT)) & RSTCTL0_PRSTCTL2_GPIO3_MASK)

#define RSTCTL0_PRSTCTL2_GPIO4_MASK              (0x400000U)
#define RSTCTL0_PRSTCTL2_GPIO4_SHIFT             (22U)
/*! GPIO4 - GPIO4 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_GPIO4(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_GPIO4_SHIFT)) & RSTCTL0_PRSTCTL2_GPIO4_MASK)

#define RSTCTL0_PRSTCTL2_GPIO5_MASK              (0x800000U)
#define RSTCTL0_PRSTCTL2_GPIO5_SHIFT             (23U)
/*! GPIO5 - GPIO5 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_GPIO5(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_GPIO5_SHIFT)) & RSTCTL0_PRSTCTL2_GPIO5_MASK)

#define RSTCTL0_PRSTCTL2_GPIO6_MASK              (0x1000000U)
#define RSTCTL0_PRSTCTL2_GPIO6_SHIFT             (24U)
/*! GPIO6 - GPIO6 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_GPIO6(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_GPIO6_SHIFT)) & RSTCTL0_PRSTCTL2_GPIO6_MASK)

#define RSTCTL0_PRSTCTL2_GPIO7_MASK              (0x2000000U)
#define RSTCTL0_PRSTCTL2_GPIO7_SHIFT             (25U)
/*! GPIO7 - GPIO7 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_GPIO7(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_GPIO7_SHIFT)) & RSTCTL0_PRSTCTL2_GPIO7_MASK)

#define RSTCTL0_PRSTCTL2_SCT0_MASK               (0x4000000U)
#define RSTCTL0_PRSTCTL2_SCT0_SHIFT              (26U)
/*! SCT0 - SCT0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SCT0(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SCT0_SHIFT)) & RSTCTL0_PRSTCTL2_SCT0_MASK)

#define RSTCTL0_PRSTCTL2_LP_FLEXCOMM0_MASK       (0x40000000U)
#define RSTCTL0_PRSTCTL2_LP_FLEXCOMM0_SHIFT      (30U)
/*! LP_FLEXCOMM0 - LP_FLEXCOMM0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_LP_FLEXCOMM0(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_LP_FLEXCOMM0_SHIFT)) & RSTCTL0_PRSTCTL2_LP_FLEXCOMM0_MASK)

#define RSTCTL0_PRSTCTL2_LP_FLEXCOMM1_MASK       (0x80000000U)
#define RSTCTL0_PRSTCTL2_LP_FLEXCOMM1_SHIFT      (31U)
/*! LP_FLEXCOMM1 - LP_FLEXCOMM1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_LP_FLEXCOMM1(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_LP_FLEXCOMM1_SHIFT)) & RSTCTL0_PRSTCTL2_LP_FLEXCOMM1_MASK)
/*! @} */

/*! @name PRSTCTL3 - Compute Domain Peripheral Reset Control 3 */
/*! @{ */

#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM2_MASK       (0x1U)
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM2_SHIFT      (0U)
/*! LP_FLEXCOMM2 - LP_FLEXCOMM2 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM2(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_LP_FLEXCOMM2_SHIFT)) & RSTCTL0_PRSTCTL3_LP_FLEXCOMM2_MASK)

#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM3_MASK       (0x2U)
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM3_SHIFT      (1U)
/*! LP_FLEXCOMM3 - LP_FLEXCOMM3 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM3(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_LP_FLEXCOMM3_SHIFT)) & RSTCTL0_PRSTCTL3_LP_FLEXCOMM3_MASK)

#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM4_MASK       (0x4U)
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM4_SHIFT      (2U)
/*! LP_FLEXCOMM4 - LP_FLEXCOMM4 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM4(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_LP_FLEXCOMM4_SHIFT)) & RSTCTL0_PRSTCTL3_LP_FLEXCOMM4_MASK)

#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM5_MASK       (0x8U)
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM5_SHIFT      (3U)
/*! LP_FLEXCOMM5 - LP_FLEXCOMM5 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM5(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_LP_FLEXCOMM5_SHIFT)) & RSTCTL0_PRSTCTL3_LP_FLEXCOMM5_MASK)

#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM6_MASK       (0x10U)
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM6_SHIFT      (4U)
/*! LP_FLEXCOMM6 - LP_FLEXCOMM6 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM6(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_LP_FLEXCOMM6_SHIFT)) & RSTCTL0_PRSTCTL3_LP_FLEXCOMM6_MASK)

#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM7_MASK       (0x20U)
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM7_SHIFT      (5U)
/*! LP_FLEXCOMM7 - LP_FLEXCOMM7 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM7(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_LP_FLEXCOMM7_SHIFT)) & RSTCTL0_PRSTCTL3_LP_FLEXCOMM7_MASK)

#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM8_MASK       (0x40U)
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM8_SHIFT      (6U)
/*! LP_FLEXCOMM8 - LP_FLEXCOMM8 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM8(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_LP_FLEXCOMM8_SHIFT)) & RSTCTL0_PRSTCTL3_LP_FLEXCOMM8_MASK)

#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM9_MASK       (0x80U)
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM9_SHIFT      (7U)
/*! LP_FLEXCOMM9 - LP_FLEXCOMM9 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM9(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_LP_FLEXCOMM9_SHIFT)) & RSTCTL0_PRSTCTL3_LP_FLEXCOMM9_MASK)

#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM10_MASK      (0x100U)
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM10_SHIFT     (8U)
/*! LP_FLEXCOMM10 - LP_FLEXCOMM10 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM10(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_LP_FLEXCOMM10_SHIFT)) & RSTCTL0_PRSTCTL3_LP_FLEXCOMM10_MASK)

#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM11_MASK      (0x200U)
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM11_SHIFT     (9U)
/*! LP_FLEXCOMM11 - LP_FLEXCOMM11 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM11(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_LP_FLEXCOMM11_SHIFT)) & RSTCTL0_PRSTCTL3_LP_FLEXCOMM11_MASK)

#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM12_MASK      (0x400U)
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM12_SHIFT     (10U)
/*! LP_FLEXCOMM12 - LP_FLEXCOMM12 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM12(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_LP_FLEXCOMM12_SHIFT)) & RSTCTL0_PRSTCTL3_LP_FLEXCOMM12_MASK)

#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM13_MASK      (0x800U)
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM13_SHIFT     (11U)
/*! LP_FLEXCOMM13 - LP_FLEXCOMM13 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_LP_FLEXCOMM13(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_LP_FLEXCOMM13_SHIFT)) & RSTCTL0_PRSTCTL3_LP_FLEXCOMM13_MASK)

#define RSTCTL0_PRSTCTL3_SAI0_MASK               (0x2000U)
#define RSTCTL0_PRSTCTL3_SAI0_SHIFT              (13U)
/*! SAI0 - SAI0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SAI0(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SAI0_SHIFT)) & RSTCTL0_PRSTCTL3_SAI0_MASK)

#define RSTCTL0_PRSTCTL3_SAI1_MASK               (0x4000U)
#define RSTCTL0_PRSTCTL3_SAI1_SHIFT              (14U)
/*! SAI1 - SAI1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SAI1(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SAI1_SHIFT)) & RSTCTL0_PRSTCTL3_SAI1_MASK)

#define RSTCTL0_PRSTCTL3_SAI2_MASK               (0x8000U)
#define RSTCTL0_PRSTCTL3_SAI2_SHIFT              (15U)
/*! SAI2 - SAI2 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SAI2(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SAI2_SHIFT)) & RSTCTL0_PRSTCTL3_SAI2_MASK)

#define RSTCTL0_PRSTCTL3_I3C0_MASK               (0x10000U)
#define RSTCTL0_PRSTCTL3_I3C0_SHIFT              (16U)
/*! I3C0 - I3C0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_I3C0(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_I3C0_SHIFT)) & RSTCTL0_PRSTCTL3_I3C0_MASK)

#define RSTCTL0_PRSTCTL3_I3C1_MASK               (0x20000U)
#define RSTCTL0_PRSTCTL3_I3C1_SHIFT              (17U)
/*! I3C1 - I3C1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_I3C1(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_I3C1_SHIFT)) & RSTCTL0_PRSTCTL3_I3C1_MASK)

#define RSTCTL0_PRSTCTL3_CRC0_MASK               (0x40000U)
#define RSTCTL0_PRSTCTL3_CRC0_SHIFT              (18U)
/*! CRC0 - CRC0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_CRC0(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CRC0_SHIFT)) & RSTCTL0_PRSTCTL3_CRC0_MASK)

#define RSTCTL0_PRSTCTL3_CTIMER0_MASK            (0x200000U)
#define RSTCTL0_PRSTCTL3_CTIMER0_SHIFT           (21U)
/*! CTIMER0 - CTIMER0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_CTIMER0(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CTIMER0_SHIFT)) & RSTCTL0_PRSTCTL3_CTIMER0_MASK)

#define RSTCTL0_PRSTCTL3_CTIMER1_MASK            (0x400000U)
#define RSTCTL0_PRSTCTL3_CTIMER1_SHIFT           (22U)
/*! CTIMER1 - CTIMER1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_CTIMER1(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CTIMER1_SHIFT)) & RSTCTL0_PRSTCTL3_CTIMER1_MASK)

#define RSTCTL0_PRSTCTL3_CTIMER2_MASK            (0x800000U)
#define RSTCTL0_PRSTCTL3_CTIMER2_SHIFT           (23U)
/*! CTIMER2 - CTIMER2 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_CTIMER2(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CTIMER2_SHIFT)) & RSTCTL0_PRSTCTL3_CTIMER2_MASK)

#define RSTCTL0_PRSTCTL3_CTIMER3_MASK            (0x1000000U)
#define RSTCTL0_PRSTCTL3_CTIMER3_SHIFT           (24U)
/*! CTIMER3 - CTIMER3 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_CTIMER3(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CTIMER3_SHIFT)) & RSTCTL0_PRSTCTL3_CTIMER3_MASK)

#define RSTCTL0_PRSTCTL3_CTIMER4_MASK            (0x2000000U)
#define RSTCTL0_PRSTCTL3_CTIMER4_SHIFT           (25U)
/*! CTIMER4 - CTIMER4 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_CTIMER4(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CTIMER4_SHIFT)) & RSTCTL0_PRSTCTL3_CTIMER4_MASK)

#define RSTCTL0_PRSTCTL3_MRT0_MASK               (0x4000000U)
#define RSTCTL0_PRSTCTL3_MRT0_SHIFT              (26U)
/*! MRT0 - MRT0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_MRT0(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_MRT0_SHIFT)) & RSTCTL0_PRSTCTL3_MRT0_MASK)

#define RSTCTL0_PRSTCTL3_UTICK0_MASK             (0x8000000U)
#define RSTCTL0_PRSTCTL3_UTICK0_SHIFT            (27U)
/*! UTICK0 - UTICK0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_UTICK0(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_UTICK0_SHIFT)) & RSTCTL0_PRSTCTL3_UTICK0_MASK)

#define RSTCTL0_PRSTCTL3_SEMA42_4_MASK           (0x40000000U)
#define RSTCTL0_PRSTCTL3_SEMA42_4_SHIFT          (30U)
/*! SEMA42_4 - SEMA42_4 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SEMA42_4(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SEMA42_4_SHIFT)) & RSTCTL0_PRSTCTL3_SEMA42_4_MASK)

#define RSTCTL0_PRSTCTL3_MU4_MASK                (0x80000000U)
#define RSTCTL0_PRSTCTL3_MU4_SHIFT               (31U)
/*! MU4 - MU4 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_MU4(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_MU4_SHIFT)) & RSTCTL0_PRSTCTL3_MU4_MASK)
/*! @} */

/*! @name PRSTCTL4 - Compute Domain Peripheral Reset Control 4 */
/*! @{ */

#define RSTCTL0_PRSTCTL4_CMX_PERFMON2_MASK       (0x1U)
#define RSTCTL0_PRSTCTL4_CMX_PERFMON2_SHIFT      (0U)
/*! CMX_PERFMON2 - CMX_PERFMON2 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_CMX_PERFMON2(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_CMX_PERFMON2_SHIFT)) & RSTCTL0_PRSTCTL4_CMX_PERFMON2_MASK)

#define RSTCTL0_PRSTCTL4_CMX_PERFMON3_MASK       (0x2U)
#define RSTCTL0_PRSTCTL4_CMX_PERFMON3_SHIFT      (1U)
/*! CMX_PERFMON3 - CMX_PERFMON3 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_CMX_PERFMON3(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_CMX_PERFMON3_SHIFT)) & RSTCTL0_PRSTCTL4_CMX_PERFMON3_MASK)

#define RSTCTL0_PRSTCTL4_SAFO_SGI_MASK           (0x4U)
#define RSTCTL0_PRSTCTL4_SAFO_SGI_SHIFT          (2U)
/*! SAFO_SGI - SAFO_SGI Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_SAFO_SGI(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_SAFO_SGI_SHIFT)) & RSTCTL0_PRSTCTL4_SAFO_SGI_MASK)

#define RSTCTL0_PRSTCTL4_PINT0_MASK              (0x20U)
#define RSTCTL0_PRSTCTL4_PINT0_SHIFT             (5U)
/*! PINT0 - PINT0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_PINT0(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_PINT0_SHIFT)) & RSTCTL0_PRSTCTL4_PINT0_MASK)

#define RSTCTL0_PRSTCTL4_INPUTMUX0_MASK          (0x80U)
#define RSTCTL0_PRSTCTL4_INPUTMUX0_SHIFT         (7U)
/*! INPUTMUX0 - INPUTMUX0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_INPUTMUX0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_INPUTMUX0_SHIFT)) & RSTCTL0_PRSTCTL4_INPUTMUX0_MASK)

#define RSTCTL0_PRSTCTL4_FREQME0_MASK            (0x100U)
#define RSTCTL0_PRSTCTL4_FREQME0_SHIFT           (8U)
/*! FREQME0 - FREQME Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_FREQME0(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_FREQME0_SHIFT)) & RSTCTL0_PRSTCTL4_FREQME0_MASK)

#define RSTCTL0_PRSTCTL4_CMX_PERFMON0_MASK       (0x400U)
#define RSTCTL0_PRSTCTL4_CMX_PERFMON0_SHIFT      (10U)
/*! CMX_PERFMON0 - CMX_PERFMON0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_CMX_PERFMON0(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_CMX_PERFMON0_SHIFT)) & RSTCTL0_PRSTCTL4_CMX_PERFMON0_MASK)

#define RSTCTL0_PRSTCTL4_CMX_PERFMON1_MASK       (0x800U)
#define RSTCTL0_PRSTCTL4_CMX_PERFMON1_SHIFT      (11U)
/*! CMX_PERFMON1 - CMX_PERFMON1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_CMX_PERFMON1(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_CMX_PERFMON1_SHIFT)) & RSTCTL0_PRSTCTL4_CMX_PERFMON1_MASK)

#define RSTCTL0_PRSTCTL4_NPU0_MASK               (0x1000U)
#define RSTCTL0_PRSTCTL4_NPU0_SHIFT              (12U)
/*! NPU0 - NPU0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_NPU0(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_NPU0_SHIFT)) & RSTCTL0_PRSTCTL4_NPU0_MASK)
/*! @} */

/*! @name PRSTCTL5 - DSP Domain Peripheral Reset Control 5 */
/*! @{ */

#define RSTCTL0_PRSTCTL5_HIFI4_MASK              (0x1U)
#define RSTCTL0_PRSTCTL5_HIFI4_SHIFT             (0U)
/*! HiFi4 - HiFi4 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL5_HIFI4(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL5_HIFI4_SHIFT)) & RSTCTL0_PRSTCTL5_HIFI4_MASK)

#define RSTCTL0_PRSTCTL5_HIFI4_DEBUG_MASK        (0x4U)
#define RSTCTL0_PRSTCTL5_HIFI4_DEBUG_SHIFT       (2U)
/*! HiFi4_DEBUG - HiFi4 Debug Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL5_HIFI4_DEBUG(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL5_HIFI4_DEBUG_SHIFT)) & RSTCTL0_PRSTCTL5_HIFI4_DEBUG_MASK)
/*! @} */

/*! @name PRSTCTL0_SET - Common Domain Peripheral Reset Control 0 SET */
/*! @{ */

#define RSTCTL0_PRSTCTL0_SET_IOPCTL0_MASK        (0x40U)
#define RSTCTL0_PRSTCTL0_SET_IOPCTL0_SHIFT       (6U)
/*! IOPCTL0 - IOPCTL0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL0_SET_IOPCTL0(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_SET_IOPCTL0_SHIFT)) & RSTCTL0_PRSTCTL0_SET_IOPCTL0_MASK)
/*! @} */

/*! @name PRSTCTL1_SET - Compute Domain Peripheral Reset Control 1 SET */
/*! @{ */

#define RSTCTL0_PRSTCTL1_SET_ELS_MASK            (0x1U)
#define RSTCTL0_PRSTCTL1_SET_ELS_SHIFT           (0U)
/*! ELS - ELS Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL1_SET_ELS(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_SET_ELS_SHIFT)) & RSTCTL0_PRSTCTL1_SET_ELS_MASK)
/*! @} */

/*! @name PRSTCTL2_SET - Compute Domain Peripheral Reset Control 2 SET */
/*! @{ */

#define RSTCTL0_PRSTCTL2_SET_EDMA0_MASK          (0x20U)
#define RSTCTL0_PRSTCTL2_SET_EDMA0_SHIFT         (5U)
/*! eDMA0 - eDMA0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_EDMA0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_EDMA0_SHIFT)) & RSTCTL0_PRSTCTL2_SET_EDMA0_MASK)

#define RSTCTL0_PRSTCTL2_SET_EDMA1_MASK          (0x40U)
#define RSTCTL0_PRSTCTL2_SET_EDMA1_SHIFT         (6U)
/*! eDMA1 - eDMA1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_EDMA1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_EDMA1_SHIFT)) & RSTCTL0_PRSTCTL2_SET_EDMA1_MASK)

#define RSTCTL0_PRSTCTL2_SET_PKC_MASK            (0x100U)
#define RSTCTL0_PRSTCTL2_SET_PKC_SHIFT           (8U)
/*! PKC - PKC Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_PKC(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_PKC_SHIFT)) & RSTCTL0_PRSTCTL2_SET_PKC_MASK)

#define RSTCTL0_PRSTCTL2_SET_XSPI0_MASK          (0x400U)
#define RSTCTL0_PRSTCTL2_SET_XSPI0_SHIFT         (10U)
/*! XSPI0 - XSPI0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_XSPI0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_XSPI0_SHIFT)) & RSTCTL0_PRSTCTL2_SET_XSPI0_MASK)

#define RSTCTL0_PRSTCTL2_SET_XSPI1_MASK          (0x800U)
#define RSTCTL0_PRSTCTL2_SET_XSPI1_SHIFT         (11U)
/*! XSPI1 - XSPI1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_XSPI1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_XSPI1_SHIFT)) & RSTCTL0_PRSTCTL2_SET_XSPI1_MASK)

#define RSTCTL0_PRSTCTL2_SET_GPIO0_MASK          (0x40000U)
#define RSTCTL0_PRSTCTL2_SET_GPIO0_SHIFT         (18U)
/*! GPIO0 - GPIO0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_GPIO0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_GPIO0_SHIFT)) & RSTCTL0_PRSTCTL2_SET_GPIO0_MASK)

#define RSTCTL0_PRSTCTL2_SET_GPIO1_MASK          (0x80000U)
#define RSTCTL0_PRSTCTL2_SET_GPIO1_SHIFT         (19U)
/*! GPIO1 - GPIO1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_GPIO1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_GPIO1_SHIFT)) & RSTCTL0_PRSTCTL2_SET_GPIO1_MASK)

#define RSTCTL0_PRSTCTL2_SET_GPIO2_MASK          (0x100000U)
#define RSTCTL0_PRSTCTL2_SET_GPIO2_SHIFT         (20U)
/*! GPIO2 - GPIO2 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_GPIO2(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_GPIO2_SHIFT)) & RSTCTL0_PRSTCTL2_SET_GPIO2_MASK)

#define RSTCTL0_PRSTCTL2_SET_GPIO3_MASK          (0x200000U)
#define RSTCTL0_PRSTCTL2_SET_GPIO3_SHIFT         (21U)
/*! GPIO3 - GPIO3 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_GPIO3(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_GPIO3_SHIFT)) & RSTCTL0_PRSTCTL2_SET_GPIO3_MASK)

#define RSTCTL0_PRSTCTL2_SET_GPIO4_MASK          (0x400000U)
#define RSTCTL0_PRSTCTL2_SET_GPIO4_SHIFT         (22U)
/*! GPIO4 - GPIO4 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_GPIO4(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_GPIO4_SHIFT)) & RSTCTL0_PRSTCTL2_SET_GPIO4_MASK)

#define RSTCTL0_PRSTCTL2_SET_GPIO5_MASK          (0x800000U)
#define RSTCTL0_PRSTCTL2_SET_GPIO5_SHIFT         (23U)
/*! GPIO5 - GPIO5 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_GPIO5(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_GPIO5_SHIFT)) & RSTCTL0_PRSTCTL2_SET_GPIO5_MASK)

#define RSTCTL0_PRSTCTL2_SET_GPIO6_MASK          (0x1000000U)
#define RSTCTL0_PRSTCTL2_SET_GPIO6_SHIFT         (24U)
/*! GPIO6 - GPIO6 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_GPIO6(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_GPIO6_SHIFT)) & RSTCTL0_PRSTCTL2_SET_GPIO6_MASK)

#define RSTCTL0_PRSTCTL2_SET_GPIO7_MASK          (0x2000000U)
#define RSTCTL0_PRSTCTL2_SET_GPIO7_SHIFT         (25U)
/*! GPIO7 - GPIO7 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_GPIO7(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_GPIO7_SHIFT)) & RSTCTL0_PRSTCTL2_SET_GPIO7_MASK)

#define RSTCTL0_PRSTCTL2_SET_SCT0_MASK           (0x4000000U)
#define RSTCTL0_PRSTCTL2_SET_SCT0_SHIFT          (26U)
/*! SCT0 - SCT0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_SCT0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_SCT0_SHIFT)) & RSTCTL0_PRSTCTL2_SET_SCT0_MASK)

#define RSTCTL0_PRSTCTL2_SET_LP_FLEXCOMM0_MASK   (0x40000000U)
#define RSTCTL0_PRSTCTL2_SET_LP_FLEXCOMM0_SHIFT  (30U)
/*! LP_FLEXCOMM0 - LP_FLEXCOMM0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_LP_FLEXCOMM0(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_LP_FLEXCOMM0_SHIFT)) & RSTCTL0_PRSTCTL2_SET_LP_FLEXCOMM0_MASK)

#define RSTCTL0_PRSTCTL2_SET_LP_FLEXCOMM1_MASK   (0x80000000U)
#define RSTCTL0_PRSTCTL2_SET_LP_FLEXCOMM1_SHIFT  (31U)
/*! LP_FLEXCOMM1 - LP_FLEXCOMM1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL2_SET_LP_FLEXCOMM1(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_SET_LP_FLEXCOMM1_SHIFT)) & RSTCTL0_PRSTCTL2_SET_LP_FLEXCOMM1_MASK)
/*! @} */

/*! @name PRSTCTL3_SET - Compute Domain Peripheral Reset Control 3 SET */
/*! @{ */

#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM2_MASK   (0x1U)
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM2_SHIFT  (0U)
/*! LP_FLEXCOMM2 - LP_FLEXCOMM2 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM2(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM2_SHIFT)) & RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM2_MASK)

#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM3_MASK   (0x2U)
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM3_SHIFT  (1U)
/*! LP_FLEXCOMM3 - LP_FLEXCOMM3 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM3(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM3_SHIFT)) & RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM3_MASK)

#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM4_MASK   (0x4U)
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM4_SHIFT  (2U)
/*! LP_FLEXCOMM4 - LP_FLEXCOMM4 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM4(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM4_SHIFT)) & RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM4_MASK)

#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM5_MASK   (0x8U)
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM5_SHIFT  (3U)
/*! LP_FLEXCOMM5 - LP_FLEXCOMM5 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM5(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM5_SHIFT)) & RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM5_MASK)

#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM6_MASK   (0x10U)
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM6_SHIFT  (4U)
/*! LP_FLEXCOMM6 - LP_FLEXCOMM6 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM6(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM6_SHIFT)) & RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM6_MASK)

#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM7_MASK   (0x20U)
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM7_SHIFT  (5U)
/*! LP_FLEXCOMM7 - LP_FLEXCOMM7 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM7(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM7_SHIFT)) & RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM7_MASK)

#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM8_MASK   (0x40U)
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM8_SHIFT  (6U)
/*! LP_FLEXCOMM8 - LP_FLEXCOMM8 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM8(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM8_SHIFT)) & RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM8_MASK)

#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM9_MASK   (0x80U)
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM9_SHIFT  (7U)
/*! LP_FLEXCOMM9 - LP_FLEXCOMM9 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM9(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM9_SHIFT)) & RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM9_MASK)

#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM10_MASK  (0x100U)
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM10_SHIFT (8U)
/*! LP_FLEXCOMM10 - LP_FLEXCOMM10 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM10(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM10_SHIFT)) & RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM10_MASK)

#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM11_MASK  (0x200U)
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM11_SHIFT (9U)
/*! LP_FLEXCOMM11 - LP_FLEXCOMM11 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM11(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM11_SHIFT)) & RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM11_MASK)

#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM12_MASK  (0x400U)
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM12_SHIFT (10U)
/*! LP_FLEXCOMM12 - LP_FLEXCOMM12 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM12(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM12_SHIFT)) & RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM12_MASK)

#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM13_MASK  (0x800U)
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM13_SHIFT (11U)
/*! LP_FLEXCOMM13 - LP_FLEXCOMM13 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM13(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM13_SHIFT)) & RSTCTL0_PRSTCTL3_SET_LP_FLEXCOMM13_MASK)

#define RSTCTL0_PRSTCTL3_SET_SAI0_MASK           (0x2000U)
#define RSTCTL0_PRSTCTL3_SET_SAI0_SHIFT          (13U)
/*! SAI0 - SAI0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_SAI0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_SAI0_SHIFT)) & RSTCTL0_PRSTCTL3_SET_SAI0_MASK)

#define RSTCTL0_PRSTCTL3_SET_SAI1_MASK           (0x4000U)
#define RSTCTL0_PRSTCTL3_SET_SAI1_SHIFT          (14U)
/*! SAI1 - SAI1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_SAI1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_SAI1_SHIFT)) & RSTCTL0_PRSTCTL3_SET_SAI1_MASK)

#define RSTCTL0_PRSTCTL3_SET_SAI2_MASK           (0x8000U)
#define RSTCTL0_PRSTCTL3_SET_SAI2_SHIFT          (15U)
/*! SAI2 - SAI2 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_SAI2(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_SAI2_SHIFT)) & RSTCTL0_PRSTCTL3_SET_SAI2_MASK)

#define RSTCTL0_PRSTCTL3_SET_I3C0_MASK           (0x10000U)
#define RSTCTL0_PRSTCTL3_SET_I3C0_SHIFT          (16U)
/*! I3C0 - I3C0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_I3C0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_I3C0_SHIFT)) & RSTCTL0_PRSTCTL3_SET_I3C0_MASK)

#define RSTCTL0_PRSTCTL3_SET_I3C1_MASK           (0x20000U)
#define RSTCTL0_PRSTCTL3_SET_I3C1_SHIFT          (17U)
/*! I3C1 - I3C1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_I3C1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_I3C1_SHIFT)) & RSTCTL0_PRSTCTL3_SET_I3C1_MASK)

#define RSTCTL0_PRSTCTL3_SET_CRC0_MASK           (0x40000U)
#define RSTCTL0_PRSTCTL3_SET_CRC0_SHIFT          (18U)
/*! CRC0 - CRC0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_CRC0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_CRC0_SHIFT)) & RSTCTL0_PRSTCTL3_SET_CRC0_MASK)

#define RSTCTL0_PRSTCTL3_SET_CTIMER0_MASK        (0x200000U)
#define RSTCTL0_PRSTCTL3_SET_CTIMER0_SHIFT       (21U)
/*! CTIMER0 - CTIMER0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_CTIMER0(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_CTIMER0_SHIFT)) & RSTCTL0_PRSTCTL3_SET_CTIMER0_MASK)

#define RSTCTL0_PRSTCTL3_SET_CTIMER1_MASK        (0x400000U)
#define RSTCTL0_PRSTCTL3_SET_CTIMER1_SHIFT       (22U)
/*! CTIMER1 - CTIMER1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_CTIMER1(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_CTIMER1_SHIFT)) & RSTCTL0_PRSTCTL3_SET_CTIMER1_MASK)

#define RSTCTL0_PRSTCTL3_SET_CTIMER2_MASK        (0x800000U)
#define RSTCTL0_PRSTCTL3_SET_CTIMER2_SHIFT       (23U)
/*! CTIMER2 - CTIMER2 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_CTIMER2(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_CTIMER2_SHIFT)) & RSTCTL0_PRSTCTL3_SET_CTIMER2_MASK)

#define RSTCTL0_PRSTCTL3_SET_CTIMER3_MASK        (0x1000000U)
#define RSTCTL0_PRSTCTL3_SET_CTIMER3_SHIFT       (24U)
/*! CTIMER3 - CTIMER3 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_CTIMER3(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_CTIMER3_SHIFT)) & RSTCTL0_PRSTCTL3_SET_CTIMER3_MASK)

#define RSTCTL0_PRSTCTL3_SET_CTIMER4_MASK        (0x2000000U)
#define RSTCTL0_PRSTCTL3_SET_CTIMER4_SHIFT       (25U)
/*! CTIMER4 - CTIMER4 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_CTIMER4(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_CTIMER4_SHIFT)) & RSTCTL0_PRSTCTL3_SET_CTIMER4_MASK)

#define RSTCTL0_PRSTCTL3_SET_MRT0_MASK           (0x4000000U)
#define RSTCTL0_PRSTCTL3_SET_MRT0_SHIFT          (26U)
/*! MRT0 - MRT0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_MRT0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_MRT0_SHIFT)) & RSTCTL0_PRSTCTL3_SET_MRT0_MASK)

#define RSTCTL0_PRSTCTL3_SET_UTICK0_MASK         (0x8000000U)
#define RSTCTL0_PRSTCTL3_SET_UTICK0_SHIFT        (27U)
/*! UTICK0 - UTICK0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_UTICK0(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_UTICK0_SHIFT)) & RSTCTL0_PRSTCTL3_SET_UTICK0_MASK)

#define RSTCTL0_PRSTCTL3_SET_SEMA42_4_MASK       (0x40000000U)
#define RSTCTL0_PRSTCTL3_SET_SEMA42_4_SHIFT      (30U)
/*! SEMA42_4 - SEMA42_4 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_SEMA42_4(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_SEMA42_4_SHIFT)) & RSTCTL0_PRSTCTL3_SET_SEMA42_4_MASK)

#define RSTCTL0_PRSTCTL3_SET_MU4_MASK            (0x80000000U)
#define RSTCTL0_PRSTCTL3_SET_MU4_SHIFT           (31U)
/*! MU4 - MU4 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL3_SET_MU4(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_SET_MU4_SHIFT)) & RSTCTL0_PRSTCTL3_SET_MU4_MASK)
/*! @} */

/*! @name PRSTCTL4_SET - Compute Domain Peripheral Reset Control 4 SET */
/*! @{ */

#define RSTCTL0_PRSTCTL4_SET_CMX_PERFMON2_MASK   (0x1U)
#define RSTCTL0_PRSTCTL4_SET_CMX_PERFMON2_SHIFT  (0U)
/*! CMX_PERFMON2 - CMX_PERFMON2 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_SET_CMX_PERFMON2(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_SET_CMX_PERFMON2_SHIFT)) & RSTCTL0_PRSTCTL4_SET_CMX_PERFMON2_MASK)

#define RSTCTL0_PRSTCTL4_SET_CMX_PERFMON3_MASK   (0x2U)
#define RSTCTL0_PRSTCTL4_SET_CMX_PERFMON3_SHIFT  (1U)
/*! CMX_PERFMON3 - CMX_PERFMON3 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_SET_CMX_PERFMON3(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_SET_CMX_PERFMON3_SHIFT)) & RSTCTL0_PRSTCTL4_SET_CMX_PERFMON3_MASK)

#define RSTCTL0_PRSTCTL4_SET_SAFO_SGI_MASK       (0x4U)
#define RSTCTL0_PRSTCTL4_SET_SAFO_SGI_SHIFT      (2U)
/*! SAFO_SGI - SAFO_SGI Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_SET_SAFO_SGI(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_SET_SAFO_SGI_SHIFT)) & RSTCTL0_PRSTCTL4_SET_SAFO_SGI_MASK)

#define RSTCTL0_PRSTCTL4_SET_PINT0_MASK          (0x20U)
#define RSTCTL0_PRSTCTL4_SET_PINT0_SHIFT         (5U)
/*! PINT0 - PINT0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_SET_PINT0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_SET_PINT0_SHIFT)) & RSTCTL0_PRSTCTL4_SET_PINT0_MASK)

#define RSTCTL0_PRSTCTL4_SET_INPUTMUX0_MASK      (0x80U)
#define RSTCTL0_PRSTCTL4_SET_INPUTMUX0_SHIFT     (7U)
/*! INPUTMUX0 - INPUTMUX0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_SET_INPUTMUX0(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_SET_INPUTMUX0_SHIFT)) & RSTCTL0_PRSTCTL4_SET_INPUTMUX0_MASK)

#define RSTCTL0_PRSTCTL4_SET_FREQME0_MASK        (0x100U)
#define RSTCTL0_PRSTCTL4_SET_FREQME0_SHIFT       (8U)
/*! FREQME0 - FREQME0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_SET_FREQME0(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_SET_FREQME0_SHIFT)) & RSTCTL0_PRSTCTL4_SET_FREQME0_MASK)

#define RSTCTL0_PRSTCTL4_SET_CMX_PERFMON0_MASK   (0x400U)
#define RSTCTL0_PRSTCTL4_SET_CMX_PERFMON0_SHIFT  (10U)
/*! CMX_PERFMON0 - CMX_PERFMON0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_SET_CMX_PERFMON0(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_SET_CMX_PERFMON0_SHIFT)) & RSTCTL0_PRSTCTL4_SET_CMX_PERFMON0_MASK)

#define RSTCTL0_PRSTCTL4_SET_CMX_PERFMON1_MASK   (0x800U)
#define RSTCTL0_PRSTCTL4_SET_CMX_PERFMON1_SHIFT  (11U)
/*! CMX_PERFMON1 - CMX_PERFMON1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_SET_CMX_PERFMON1(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_SET_CMX_PERFMON1_SHIFT)) & RSTCTL0_PRSTCTL4_SET_CMX_PERFMON1_MASK)

#define RSTCTL0_PRSTCTL4_SET_NPU0_MASK           (0x1000U)
#define RSTCTL0_PRSTCTL4_SET_NPU0_SHIFT          (12U)
/*! NPU0 - NPU0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL4_SET_NPU0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_SET_NPU0_SHIFT)) & RSTCTL0_PRSTCTL4_SET_NPU0_MASK)
/*! @} */

/*! @name PRSTCTL5_SET - DSP Domain Peripheral Reset Control 5 SET */
/*! @{ */

#define RSTCTL0_PRSTCTL5_SET_HIFI4_MASK          (0x1U)
#define RSTCTL0_PRSTCTL5_SET_HIFI4_SHIFT         (0U)
/*! HiFi4 - HiFi4 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL5_SET_HIFI4(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL5_SET_HIFI4_SHIFT)) & RSTCTL0_PRSTCTL5_SET_HIFI4_MASK)

#define RSTCTL0_PRSTCTL5_SET_HIFI4_DEBUG_MASK    (0x4U)
#define RSTCTL0_PRSTCTL5_SET_HIFI4_DEBUG_SHIFT   (2U)
/*! HiFi4_DEBUG - HiFi4 Debug Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL0_PRSTCTL5_SET_HIFI4_DEBUG(x)      (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL5_SET_HIFI4_DEBUG_SHIFT)) & RSTCTL0_PRSTCTL5_SET_HIFI4_DEBUG_MASK)
/*! @} */

/*! @name PRSTCTL0_CLR - Common Domain Peripheral Reset Control 0 CLR */
/*! @{ */

#define RSTCTL0_PRSTCTL0_CLR_IOPCTL0_MASK        (0x40U)
#define RSTCTL0_PRSTCTL0_CLR_IOPCTL0_SHIFT       (6U)
/*! IOPCTL0 - IOPCTL0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL0_CLR_IOPCTL0(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL0_CLR_IOPCTL0_SHIFT)) & RSTCTL0_PRSTCTL0_CLR_IOPCTL0_MASK)
/*! @} */

/*! @name PRSTCTL1_CLR - Compute Domain Peripheral Reset Control 1 CLR */
/*! @{ */

#define RSTCTL0_PRSTCTL1_CLR_ELS_MASK            (0x1U)
#define RSTCTL0_PRSTCTL1_CLR_ELS_SHIFT           (0U)
/*! ELS - ELS Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL1_CLR_ELS(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL1_CLR_ELS_SHIFT)) & RSTCTL0_PRSTCTL1_CLR_ELS_MASK)
/*! @} */

/*! @name PRSTCTL2_CLR - Compute Domain Peripheral Reset Control 2 CLR */
/*! @{ */

#define RSTCTL0_PRSTCTL2_CLR_EDMA0_MASK          (0x20U)
#define RSTCTL0_PRSTCTL2_CLR_EDMA0_SHIFT         (5U)
/*! eDMA0 - eDMA0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_EDMA0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_EDMA0_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_EDMA0_MASK)

#define RSTCTL0_PRSTCTL2_CLR_EDMA1_MASK          (0x40U)
#define RSTCTL0_PRSTCTL2_CLR_EDMA1_SHIFT         (6U)
/*! eDMA1 - eDMA1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_EDMA1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_EDMA1_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_EDMA1_MASK)

#define RSTCTL0_PRSTCTL2_CLR_PKC_MASK            (0x100U)
#define RSTCTL0_PRSTCTL2_CLR_PKC_SHIFT           (8U)
/*! PKC - PKC Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_PKC(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_PKC_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_PKC_MASK)

#define RSTCTL0_PRSTCTL2_CLR_XSPI0_MASK          (0x400U)
#define RSTCTL0_PRSTCTL2_CLR_XSPI0_SHIFT         (10U)
/*! XSPI0 - XSPI0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_XSPI0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_XSPI0_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_XSPI0_MASK)

#define RSTCTL0_PRSTCTL2_CLR_XSPI1_MASK          (0x800U)
#define RSTCTL0_PRSTCTL2_CLR_XSPI1_SHIFT         (11U)
/*! XSPI1 - XSPI1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_XSPI1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_XSPI1_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_XSPI1_MASK)

#define RSTCTL0_PRSTCTL2_CLR_GPIO0_MASK          (0x40000U)
#define RSTCTL0_PRSTCTL2_CLR_GPIO0_SHIFT         (18U)
/*! GPIO0 - GPIO0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_GPIO0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_GPIO0_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_GPIO0_MASK)

#define RSTCTL0_PRSTCTL2_CLR_GPIO1_MASK          (0x80000U)
#define RSTCTL0_PRSTCTL2_CLR_GPIO1_SHIFT         (19U)
/*! GPIO1 - GPIO1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_GPIO1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_GPIO1_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_GPIO1_MASK)

#define RSTCTL0_PRSTCTL2_CLR_GPIO2_MASK          (0x100000U)
#define RSTCTL0_PRSTCTL2_CLR_GPIO2_SHIFT         (20U)
/*! GPIO2 - GPIO2 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_GPIO2(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_GPIO2_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_GPIO2_MASK)

#define RSTCTL0_PRSTCTL2_CLR_GPIO3_MASK          (0x200000U)
#define RSTCTL0_PRSTCTL2_CLR_GPIO3_SHIFT         (21U)
/*! GPIO3 - GPIO3 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_GPIO3(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_GPIO3_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_GPIO3_MASK)

#define RSTCTL0_PRSTCTL2_CLR_GPIO4_MASK          (0x400000U)
#define RSTCTL0_PRSTCTL2_CLR_GPIO4_SHIFT         (22U)
/*! GPIO4 - GPIO4 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_GPIO4(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_GPIO4_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_GPIO4_MASK)

#define RSTCTL0_PRSTCTL2_CLR_GPIO5_MASK          (0x800000U)
#define RSTCTL0_PRSTCTL2_CLR_GPIO5_SHIFT         (23U)
/*! GPIO5 - GPIO5 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_GPIO5(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_GPIO5_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_GPIO5_MASK)

#define RSTCTL0_PRSTCTL2_CLR_GPIO6_MASK          (0x1000000U)
#define RSTCTL0_PRSTCTL2_CLR_GPIO6_SHIFT         (24U)
/*! GPIO6 - GPIO6 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_GPIO6(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_GPIO6_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_GPIO6_MASK)

#define RSTCTL0_PRSTCTL2_CLR_GPIO7_MASK          (0x2000000U)
#define RSTCTL0_PRSTCTL2_CLR_GPIO7_SHIFT         (25U)
/*! GPIO7 - GPIO7 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_GPIO7(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_GPIO7_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_GPIO7_MASK)

#define RSTCTL0_PRSTCTL2_CLR_SCT0_MASK           (0x4000000U)
#define RSTCTL0_PRSTCTL2_CLR_SCT0_SHIFT          (26U)
/*! SCT0 - SCT0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_SCT0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_SCT0_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_SCT0_MASK)

#define RSTCTL0_PRSTCTL2_CLR_LP_FLEXCOMM0_MASK   (0x40000000U)
#define RSTCTL0_PRSTCTL2_CLR_LP_FLEXCOMM0_SHIFT  (30U)
/*! LP_FLEXCOMM0 - LP_FLEXCOMM0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_LP_FLEXCOMM0(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_LP_FLEXCOMM0_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_LP_FLEXCOMM0_MASK)

#define RSTCTL0_PRSTCTL2_CLR_LP_FLEXCOMM1_MASK   (0x80000000U)
#define RSTCTL0_PRSTCTL2_CLR_LP_FLEXCOMM1_SHIFT  (31U)
/*! LP_FLEXCOMM1 - LP_FLEXCOMM1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL2_CLR_LP_FLEXCOMM1(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL2_CLR_LP_FLEXCOMM1_SHIFT)) & RSTCTL0_PRSTCTL2_CLR_LP_FLEXCOMM1_MASK)
/*! @} */

/*! @name PRSTCTL3_CLR - Compute Domain Peripheral Reset Control 3 CLR */
/*! @{ */

#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM2_MASK   (0x1U)
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM2_SHIFT  (0U)
/*! LP_FLEXCOMM2 - LP_FLEXCOMM2 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM2(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM2_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM2_MASK)

#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM3_MASK   (0x2U)
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM3_SHIFT  (1U)
/*! LP_FLEXCOMM3 - LP_FLEXCOMM3 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM3(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM3_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM3_MASK)

#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM4_MASK   (0x4U)
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM4_SHIFT  (2U)
/*! LP_FLEXCOMM4 - LP_FLEXCOMM4 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM4(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM4_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM4_MASK)

#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM5_MASK   (0x8U)
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM5_SHIFT  (3U)
/*! LP_FLEXCOMM5 - LP_FLEXCOMM5 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM5(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM5_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM5_MASK)

#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM6_MASK   (0x10U)
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM6_SHIFT  (4U)
/*! LP_FLEXCOMM6 - LP_FLEXCOMM6 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM6(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM6_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM6_MASK)

#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM7_MASK   (0x20U)
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM7_SHIFT  (5U)
/*! LP_FLEXCOMM7 - LP_FLEXCOMM7 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM7(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM7_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM7_MASK)

#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM8_MASK   (0x40U)
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM8_SHIFT  (6U)
/*! LP_FLEXCOMM8 - LP_FLEXCOMM8 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM8(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM8_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM8_MASK)

#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM9_MASK   (0x80U)
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM9_SHIFT  (7U)
/*! LP_FLEXCOMM9 - LP_FLEXCOMM9 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM9(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM9_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM9_MASK)

#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM10_MASK  (0x100U)
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM10_SHIFT (8U)
/*! LP_FLEXCOMM10 - LP_FLEXCOMM10 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM10(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM10_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM10_MASK)

#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM11_MASK  (0x200U)
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM11_SHIFT (9U)
/*! LP_FLEXCOMM11 - LP_FLEXCOMM11 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM11(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM11_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM11_MASK)

#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM12_MASK  (0x400U)
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM12_SHIFT (10U)
/*! LP_FLEXCOMM12 - LP_FLEXCOMM12 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM12(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM12_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM12_MASK)

#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM13_MASK  (0x800U)
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM13_SHIFT (11U)
/*! LP_FLEXCOMM13 - LP_FLEXCOMM13 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM13(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM13_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_LP_FLEXCOMM13_MASK)

#define RSTCTL0_PRSTCTL3_CLR_SAI0_MASK           (0x2000U)
#define RSTCTL0_PRSTCTL3_CLR_SAI0_SHIFT          (13U)
/*! SAI0 - SAI0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_SAI0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_SAI0_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_SAI0_MASK)

#define RSTCTL0_PRSTCTL3_CLR_SAI1_MASK           (0x4000U)
#define RSTCTL0_PRSTCTL3_CLR_SAI1_SHIFT          (14U)
/*! SAI1 - SAI1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_SAI1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_SAI1_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_SAI1_MASK)

#define RSTCTL0_PRSTCTL3_CLR_SAI2_MASK           (0x8000U)
#define RSTCTL0_PRSTCTL3_CLR_SAI2_SHIFT          (15U)
/*! SAI2 - SAI2 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_SAI2(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_SAI2_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_SAI2_MASK)

#define RSTCTL0_PRSTCTL3_CLR_I3C0_MASK           (0x10000U)
#define RSTCTL0_PRSTCTL3_CLR_I3C0_SHIFT          (16U)
/*! I3C0 - I3C0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_I3C0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_I3C0_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_I3C0_MASK)

#define RSTCTL0_PRSTCTL3_CLR_I3C1_MASK           (0x20000U)
#define RSTCTL0_PRSTCTL3_CLR_I3C1_SHIFT          (17U)
/*! I3C1 - I3C1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_I3C1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_I3C1_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_I3C1_MASK)

#define RSTCTL0_PRSTCTL3_CLR_CRC0_MASK           (0x40000U)
#define RSTCTL0_PRSTCTL3_CLR_CRC0_SHIFT          (18U)
/*! CRC0 - CRC0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_CRC0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_CRC0_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_CRC0_MASK)

#define RSTCTL0_PRSTCTL3_CLR_CTIMER0_MASK        (0x200000U)
#define RSTCTL0_PRSTCTL3_CLR_CTIMER0_SHIFT       (21U)
/*! CTIMER0 - CTIMER0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_CTIMER0(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_CTIMER0_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_CTIMER0_MASK)

#define RSTCTL0_PRSTCTL3_CLR_CTIMER1_MASK        (0x400000U)
#define RSTCTL0_PRSTCTL3_CLR_CTIMER1_SHIFT       (22U)
/*! CTIMER1 - CTIMER1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_CTIMER1(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_CTIMER1_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_CTIMER1_MASK)

#define RSTCTL0_PRSTCTL3_CLR_CTIMER2_MASK        (0x800000U)
#define RSTCTL0_PRSTCTL3_CLR_CTIMER2_SHIFT       (23U)
/*! CTIMER2 - CTIMER2 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_CTIMER2(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_CTIMER2_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_CTIMER2_MASK)

#define RSTCTL0_PRSTCTL3_CLR_CTIMER3_MASK        (0x1000000U)
#define RSTCTL0_PRSTCTL3_CLR_CTIMER3_SHIFT       (24U)
/*! CTIMER3 - CTIMER3 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_CTIMER3(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_CTIMER3_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_CTIMER3_MASK)

#define RSTCTL0_PRSTCTL3_CLR_CTIMER4_MASK        (0x2000000U)
#define RSTCTL0_PRSTCTL3_CLR_CTIMER4_SHIFT       (25U)
/*! CTIMER4 - CTIMER4 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_CTIMER4(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_CTIMER4_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_CTIMER4_MASK)

#define RSTCTL0_PRSTCTL3_CLR_MRT0_MASK           (0x4000000U)
#define RSTCTL0_PRSTCTL3_CLR_MRT0_SHIFT          (26U)
/*! MRT0 - MRT0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_MRT0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_MRT0_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_MRT0_MASK)

#define RSTCTL0_PRSTCTL3_CLR_UTICK0_MASK         (0x8000000U)
#define RSTCTL0_PRSTCTL3_CLR_UTICK0_SHIFT        (27U)
/*! UTICK0 - UTICK0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_UTICK0(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_UTICK0_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_UTICK0_MASK)

#define RSTCTL0_PRSTCTL3_CLR_SEMA42_4_MASK       (0x40000000U)
#define RSTCTL0_PRSTCTL3_CLR_SEMA42_4_SHIFT      (30U)
/*! SEMA42_4 - SEMA42_4 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_SEMA42_4(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_SEMA42_4_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_SEMA42_4_MASK)

#define RSTCTL0_PRSTCTL3_CLR_MU4_MASK            (0x80000000U)
#define RSTCTL0_PRSTCTL3_CLR_MU4_SHIFT           (31U)
/*! MU4 - MU4 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL3_CLR_MU4(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL3_CLR_MU4_SHIFT)) & RSTCTL0_PRSTCTL3_CLR_MU4_MASK)
/*! @} */

/*! @name PRSTCTL4_CLR - Compute Domain Peripheral Reset Control 4 CLR */
/*! @{ */

#define RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON2_MASK   (0x1U)
#define RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON2_SHIFT  (0U)
/*! CMX_PERFMON2 - CMX_PERFMON2 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON2(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON2_SHIFT)) & RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON2_MASK)

#define RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON3_MASK   (0x2U)
#define RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON3_SHIFT  (1U)
/*! CMX_PERFMON3 - CMX_PERFMON3 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON3(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON3_SHIFT)) & RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON3_MASK)

#define RSTCTL0_PRSTCTL4_CLR_SAFO_SGI_MASK       (0x4U)
#define RSTCTL0_PRSTCTL4_CLR_SAFO_SGI_SHIFT      (2U)
/*! SAFO_SGI - SAFO_SGI Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL4_CLR_SAFO_SGI(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_CLR_SAFO_SGI_SHIFT)) & RSTCTL0_PRSTCTL4_CLR_SAFO_SGI_MASK)

#define RSTCTL0_PRSTCTL4_CLR_PINT0_MASK          (0x20U)
#define RSTCTL0_PRSTCTL4_CLR_PINT0_SHIFT         (5U)
/*! PINT0 - PINT0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL4_CLR_PINT0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_CLR_PINT0_SHIFT)) & RSTCTL0_PRSTCTL4_CLR_PINT0_MASK)

#define RSTCTL0_PRSTCTL4_CLR_INPUTMUX0_MASK      (0x80U)
#define RSTCTL0_PRSTCTL4_CLR_INPUTMUX0_SHIFT     (7U)
/*! INPUTMUX0 - INPUTMUX0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL4_CLR_INPUTMUX0(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_CLR_INPUTMUX0_SHIFT)) & RSTCTL0_PRSTCTL4_CLR_INPUTMUX0_MASK)

#define RSTCTL0_PRSTCTL4_CLR_FREQME0_MASK        (0x100U)
#define RSTCTL0_PRSTCTL4_CLR_FREQME0_SHIFT       (8U)
/*! FREQME0 - FREQME0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL4_CLR_FREQME0(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_CLR_FREQME0_SHIFT)) & RSTCTL0_PRSTCTL4_CLR_FREQME0_MASK)

#define RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON0_MASK   (0x400U)
#define RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON0_SHIFT  (10U)
/*! CMX_PERFMON0 - CMX_PERFMON0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON0(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON0_SHIFT)) & RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON0_MASK)

#define RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON1_MASK   (0x800U)
#define RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON1_SHIFT  (11U)
/*! CMX_PERFMON1 - CMX_PERFMON1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON1(x)     (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON1_SHIFT)) & RSTCTL0_PRSTCTL4_CLR_CMX_PERFMON1_MASK)

#define RSTCTL0_PRSTCTL4_CLR_NPU0_MASK           (0x1000U)
#define RSTCTL0_PRSTCTL4_CLR_NPU0_SHIFT          (12U)
/*! NPU0 - NPU0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL4_CLR_NPU0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL4_CLR_NPU0_SHIFT)) & RSTCTL0_PRSTCTL4_CLR_NPU0_MASK)
/*! @} */

/*! @name PRSTCTL5_CLR - DSP Domain Peripheral Reset Control 5 CLR */
/*! @{ */

#define RSTCTL0_PRSTCTL5_CLR_HIFI4_MASK          (0x1U)
#define RSTCTL0_PRSTCTL5_CLR_HIFI4_SHIFT         (0U)
/*! HiFi4 - HiFi4 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL5_CLR_HIFI4(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL5_CLR_HIFI4_SHIFT)) & RSTCTL0_PRSTCTL5_CLR_HIFI4_MASK)

#define RSTCTL0_PRSTCTL5_CLR_VDD2_DSP_DEBUG_MASK (0x4U)
#define RSTCTL0_PRSTCTL5_CLR_VDD2_DSP_DEBUG_SHIFT (2U)
/*! VDD2_DSP_DEBUG - HiFi4 Debug Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL0_PRSTCTL5_CLR_VDD2_DSP_DEBUG(x)   (((uint32_t)(((uint32_t)(x)) << RSTCTL0_PRSTCTL5_CLR_VDD2_DSP_DEBUG_SHIFT)) & RSTCTL0_PRSTCTL5_CLR_VDD2_DSP_DEBUG_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RSTCTL0_Register_Masks */


/*!
 * @}
 */ /* end of group RSTCTL0_Peripheral_Access_Layer */


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


#endif  /* PERI_RSTCTL0_H_ */

