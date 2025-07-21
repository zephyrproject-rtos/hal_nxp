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
**         CMSIS Peripheral Access Layer for RSTCTL3
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
 * @file PERI_RSTCTL3.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RSTCTL3
 *
 * CMSIS Peripheral Access Layer for RSTCTL3
 */

#if !defined(PERI_RSTCTL3_H_)
#define PERI_RSTCTL3_H_                          /**< Symbol preventing repeated inclusion */

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
   -- RSTCTL3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL3_Peripheral_Access_Layer RSTCTL3 Peripheral Access Layer
 * @{
 */

/** RSTCTL3 - Register Layout Typedef */
typedef struct {
  __IO uint32_t SYSRSTSTAT;                        /**< System Reset Status, offset: 0x0 */
  __I  uint32_t DOMRSTSTAT;                        /**< Domain Reset Status, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t PRSTCTL0;                          /**< Sense Domain Peripheral Reset Control 0, offset: 0x10 */
  __IO uint32_t PRSTCTL1;                          /**< Sense Domain Peripheral Reset Control 1, offset: 0x14 */
       uint8_t RESERVED_1[40];
  __O  uint32_t PRSTCTL0_SET;                      /**< Sense Domain Peripheral Reset Control 0 SET, offset: 0x40 */
  __O  uint32_t PRSTCTL1_SET;                      /**< Sense Domain Peripheral Reset Control 1 SET, offset: 0x44 */
       uint8_t RESERVED_2[40];
  __O  uint32_t PRSTCTL0_CLR;                      /**< Sense Domain Peripheral Reset Control 0 CLR, offset: 0x70 */
  __O  uint32_t PRSTCTL1_CLR;                      /**< Sense Peripheral Reset Control 1 CLR, offset: 0x74 */
} RSTCTL3_Type;

/* ----------------------------------------------------------------------------
   -- RSTCTL3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL3_Register_Masks RSTCTL3 Register Masks
 * @{
 */

/*! @name SYSRSTSTAT - System Reset Status */
/*! @{ */

#define RSTCTL3_SYSRSTSTAT_VDD_POR_MASK          (0x1U)
#define RSTCTL3_SYSRSTSTAT_VDD_POR_SHIFT         (0U)
/*! VDD_POR - VDD Power-On Reset (POR)
 *  0b0..No VDD POR event is detected.
 *  0b1..VDD POR event is detected.
 */
#define RSTCTL3_SYSRSTSTAT_VDD_POR(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_VDD_POR_SHIFT)) & RSTCTL3_SYSRSTSTAT_VDD_POR_MASK)

#define RSTCTL3_SYSRSTSTAT_RESETN_RESET_MASK     (0x2U)
#define RSTCTL3_SYSRSTSTAT_RESETN_RESET_SHIFT    (1U)
/*! RESETN_RESET - RESETN Reset
 *  0b0..No RESETN event is detected
 *  0b1..RESETN event is detected.
 */
#define RSTCTL3_SYSRSTSTAT_RESETN_RESET(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_RESETN_RESET_SHIFT)) & RSTCTL3_SYSRSTSTAT_RESETN_RESET_MASK)

#define RSTCTL3_SYSRSTSTAT_ISP_AP_RESET_MASK     (0x4U)
#define RSTCTL3_SYSRSTSTAT_ISP_AP_RESET_SHIFT    (2U)
/*! ISP_AP_RESET - ISP_AP (Debug Mailbox) Reset
 *  0b0..No ISP_AP reset event is detected.
 *  0b1..ISP_AP reset is detected.
 */
#define RSTCTL3_SYSRSTSTAT_ISP_AP_RESET(x)       (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_ISP_AP_RESET_SHIFT)) & RSTCTL3_SYSRSTSTAT_ISP_AP_RESET_MASK)

#define RSTCTL3_SYSRSTSTAT_ITRC_SW_RESET_MASK    (0x8U)
#define RSTCTL3_SYSRSTSTAT_ITRC_SW_RESET_SHIFT   (3U)
/*! ITRC_SW_RESET - ITRC_SW (Intrusion and Tamper Response Controller SW) Reset
 *  0b0..No ITRC_SW reset event is detected.
 *  0b1..ITRC_SW reset is detected.
 */
#define RSTCTL3_SYSRSTSTAT_ITRC_SW_RESET(x)      (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_ITRC_SW_RESET_SHIFT)) & RSTCTL3_SYSRSTSTAT_ITRC_SW_RESET_MASK)

#define RSTCTL3_SYSRSTSTAT_CPU0_RESET_MASK       (0x10U)
#define RSTCTL3_SYSRSTSTAT_CPU0_RESET_SHIFT      (4U)
/*! CPU0_RESET - CPU0 Reset
 *  0b0..No CPU0 reset event is detected.
 *  0b1..CPU0 reset is detected.
 */
#define RSTCTL3_SYSRSTSTAT_CPU0_RESET(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_CPU0_RESET_SHIFT)) & RSTCTL3_SYSRSTSTAT_CPU0_RESET_MASK)

#define RSTCTL3_SYSRSTSTAT_CPU1_RESET_MASK       (0x20U)
#define RSTCTL3_SYSRSTSTAT_CPU1_RESET_SHIFT      (5U)
/*! CPU1_RESET - CPU1 Reset
 *  0b0..No CPU1 reset event is detected.
 *  0b1..CPU1 reset is detected.
 */
#define RSTCTL3_SYSRSTSTAT_CPU1_RESET(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_CPU1_RESET_SHIFT)) & RSTCTL3_SYSRSTSTAT_CPU1_RESET_MASK)

#define RSTCTL3_SYSRSTSTAT_WWDT0_RESET_MASK      (0x40U)
#define RSTCTL3_SYSRSTSTAT_WWDT0_RESET_SHIFT     (6U)
/*! WWDT0_RESET - WWDT0 Reset
 *  0b0..No WWDT0 reset event is detected.
 *  0b1..WWDT0 reset event is detected.
 */
#define RSTCTL3_SYSRSTSTAT_WWDT0_RESET(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_WWDT0_RESET_SHIFT)) & RSTCTL3_SYSRSTSTAT_WWDT0_RESET_MASK)

#define RSTCTL3_SYSRSTSTAT_WWDT1_RESET_MASK      (0x80U)
#define RSTCTL3_SYSRSTSTAT_WWDT1_RESET_SHIFT     (7U)
/*! WWDT1_RESET - WWDT1 Reset
 *  0b0..No WWDT1 reset event is detected
 *  0b1..WWDT1 reset event is detected.
 */
#define RSTCTL3_SYSRSTSTAT_WWDT1_RESET(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_WWDT1_RESET_SHIFT)) & RSTCTL3_SYSRSTSTAT_WWDT1_RESET_MASK)

#define RSTCTL3_SYSRSTSTAT_WWDT2_RESET_MASK      (0x100U)
#define RSTCTL3_SYSRSTSTAT_WWDT2_RESET_SHIFT     (8U)
/*! WWDT2_RESET - WWDT2 Reset
 *  0b0..No WWDT2 reset event is detected.
 *  0b1..WWDT2 reset event is detected.
 */
#define RSTCTL3_SYSRSTSTAT_WWDT2_RESET(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_WWDT2_RESET_SHIFT)) & RSTCTL3_SYSRSTSTAT_WWDT2_RESET_MASK)

#define RSTCTL3_SYSRSTSTAT_WWDT3_RESET_MASK      (0x200U)
#define RSTCTL3_SYSRSTSTAT_WWDT3_RESET_SHIFT     (9U)
/*! WWDT3_RESET - WWDT3 Reset
 *  0b0..No WWDT3 reset event is detected.
 *  0b1..WWDT3 reset event is detected.
 */
#define RSTCTL3_SYSRSTSTAT_WWDT3_RESET(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_WWDT3_RESET_SHIFT)) & RSTCTL3_SYSRSTSTAT_WWDT3_RESET_MASK)

#define RSTCTL3_SYSRSTSTAT_CDOG0_RESET_MASK      (0x400U)
#define RSTCTL3_SYSRSTSTAT_CDOG0_RESET_SHIFT     (10U)
/*! CDOG0_RESET - CDOG0 Reset
 *  0b0..No CDOG0 reset event is detected.
 *  0b1..CDOG0 reset event is detected.
 */
#define RSTCTL3_SYSRSTSTAT_CDOG0_RESET(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_CDOG0_RESET_SHIFT)) & RSTCTL3_SYSRSTSTAT_CDOG0_RESET_MASK)

#define RSTCTL3_SYSRSTSTAT_CDOG1_RESET_MASK      (0x800U)
#define RSTCTL3_SYSRSTSTAT_CDOG1_RESET_SHIFT     (11U)
/*! CDOG1_RESET - CDOG1 Reset
 *  0b0..No CDOG1 reset event is detected.
 *  0b1..CDOG1 reset event is detected.
 */
#define RSTCTL3_SYSRSTSTAT_CDOG1_RESET(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_CDOG1_RESET_SHIFT)) & RSTCTL3_SYSRSTSTAT_CDOG1_RESET_MASK)

#define RSTCTL3_SYSRSTSTAT_CDOG2_RESET_MASK      (0x1000U)
#define RSTCTL3_SYSRSTSTAT_CDOG2_RESET_SHIFT     (12U)
/*! CDOG2_RESET - CDOG2 Reset
 *  0b0..No CDOG2 reset event is detected.
 *  0b1..CDOG2 reset event is detected.
 */
#define RSTCTL3_SYSRSTSTAT_CDOG2_RESET(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_CDOG2_RESET_SHIFT)) & RSTCTL3_SYSRSTSTAT_CDOG2_RESET_MASK)

#define RSTCTL3_SYSRSTSTAT_CDOG3_RESET_MASK      (0x2000U)
#define RSTCTL3_SYSRSTSTAT_CDOG3_RESET_SHIFT     (13U)
/*! CDOG3_RESET - CDOG3 Reset
 *  0b0..No CDOG3 reset event is detected.
 *  0b1..CDOG3 reset event is detected.
 */
#define RSTCTL3_SYSRSTSTAT_CDOG3_RESET(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_CDOG3_RESET_SHIFT)) & RSTCTL3_SYSRSTSTAT_CDOG3_RESET_MASK)

#define RSTCTL3_SYSRSTSTAT_CDOG4_RESET_MASK      (0x4000U)
#define RSTCTL3_SYSRSTSTAT_CDOG4_RESET_SHIFT     (14U)
/*! CDOG4_RESET - CDOG4 Reset
 *  0b0..No CDOG4 reset event is detected.
 *  0b1..CDOG4 reset event is detected.
 */
#define RSTCTL3_SYSRSTSTAT_CDOG4_RESET(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL3_SYSRSTSTAT_CDOG4_RESET_SHIFT)) & RSTCTL3_SYSRSTSTAT_CDOG4_RESET_MASK)
/*! @} */

/*! @name DOMRSTSTAT - Domain Reset Status */
/*! @{ */

#define RSTCTL3_DOMRSTSTAT_VDD1_SENSE_STAT_MASK  (0x1U)
#define RSTCTL3_DOMRSTSTAT_VDD1_SENSE_STAT_SHIFT (0U)
/*! VDD1_SENSE_STAT - VDD1_SENSE Domain Reset State
 *  0b0..The domain is in reset state.
 *  0b1..The domain is in normal run state.
 */
#define RSTCTL3_DOMRSTSTAT_VDD1_SENSE_STAT(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL3_DOMRSTSTAT_VDD1_SENSE_STAT_SHIFT)) & RSTCTL3_DOMRSTSTAT_VDD1_SENSE_STAT_MASK)

#define RSTCTL3_DOMRSTSTAT_COM2_STAT_MASK        (0x2U)
#define RSTCTL3_DOMRSTSTAT_COM2_STAT_SHIFT       (1U)
/*! COM2_STAT - VDD2_COM (Main) Domain Reset State
 *  0b0..The domain is in reset state.
 *  0b1..The domain is in normal run state.
 */
#define RSTCTL3_DOMRSTSTAT_COM2_STAT(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL3_DOMRSTSTAT_COM2_STAT_SHIFT)) & RSTCTL3_DOMRSTSTAT_COM2_STAT_MASK)

#define RSTCTL3_DOMRSTSTAT_COMN_STAT_MASK        (0x4U)
#define RSTCTL3_DOMRSTSTAT_COMN_STAT_SHIFT       (2U)
/*! COMN_STAT - VDDN_COM Domain Reset State
 *  0b0..The domain is in reset state.
 *  0b1..The domain is in normal run state.
 */
#define RSTCTL3_DOMRSTSTAT_COMN_STAT(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL3_DOMRSTSTAT_COMN_STAT_SHIFT)) & RSTCTL3_DOMRSTSTAT_COMN_STAT_MASK)

#define RSTCTL3_DOMRSTSTAT_COMP_STAT_MASK        (0x8U)
#define RSTCTL3_DOMRSTSTAT_COMP_STAT_SHIFT       (3U)
/*! COMP_STAT - VDD2_COMP Domain Reset State
 *  0b0..The domain is in reset state.
 *  0b1..The domain is in normal run state.
 */
#define RSTCTL3_DOMRSTSTAT_COMP_STAT(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL3_DOMRSTSTAT_COMP_STAT_SHIFT)) & RSTCTL3_DOMRSTSTAT_COMP_STAT_MASK)

#define RSTCTL3_DOMRSTSTAT_DSP_STAT_MASK         (0x10U)
#define RSTCTL3_DOMRSTSTAT_DSP_STAT_SHIFT        (4U)
/*! DSP_STAT - VDD2_DSP Domain Reset State
 *  0b0..The domain is in reset state.
 *  0b1..The domain is in normal run state.
 */
#define RSTCTL3_DOMRSTSTAT_DSP_STAT(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL3_DOMRSTSTAT_DSP_STAT_SHIFT)) & RSTCTL3_DOMRSTSTAT_DSP_STAT_MASK)

#define RSTCTL3_DOMRSTSTAT_MEDIA_STAT_MASK       (0x20U)
#define RSTCTL3_DOMRSTSTAT_MEDIA_STAT_SHIFT      (5U)
/*! MEDIA_STAT - VDD2_MEDIA Domain Reset State
 *  0b0..The domain is in reset state.
 *  0b1..The domain is in normal run state.
 */
#define RSTCTL3_DOMRSTSTAT_MEDIA_STAT(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL3_DOMRSTSTAT_MEDIA_STAT_SHIFT)) & RSTCTL3_DOMRSTSTAT_MEDIA_STAT_MASK)
/*! @} */

/*! @name PRSTCTL0 - Sense Domain Peripheral Reset Control 0 */
/*! @{ */

#define RSTCTL3_PRSTCTL0_IOPCTL1_MASK            (0x1U)
#define RSTCTL3_PRSTCTL0_IOPCTL1_SHIFT           (0U)
/*! IOPCTL1 - IOPCTL1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL0_IOPCTL1(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL0_IOPCTL1_SHIFT)) & RSTCTL3_PRSTCTL0_IOPCTL1_MASK)

#define RSTCTL3_PRSTCTL0_CPU1_MASK               (0x80000000U)
#define RSTCTL3_PRSTCTL0_CPU1_SHIFT              (31U)
/*! CPU1 - CPU1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL0_CPU1(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL0_CPU1_SHIFT)) & RSTCTL3_PRSTCTL0_CPU1_MASK)
/*! @} */

/*! @name PRSTCTL1 - Sense Domain Peripheral Reset Control 1 */
/*! @{ */

#define RSTCTL3_PRSTCTL1_MU0_MASK                (0x2U)
#define RSTCTL3_PRSTCTL1_MU0_SHIFT               (1U)
/*! MU0 - MU0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_MU0(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_MU0_SHIFT)) & RSTCTL3_PRSTCTL1_MU0_MASK)

#define RSTCTL3_PRSTCTL1_MU1_MASK                (0x4U)
#define RSTCTL3_PRSTCTL1_MU1_SHIFT               (2U)
/*! MU1 - MU1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_MU1(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_MU1_SHIFT)) & RSTCTL3_PRSTCTL1_MU1_MASK)

#define RSTCTL3_PRSTCTL1_MU2_MASK                (0x8U)
#define RSTCTL3_PRSTCTL1_MU2_SHIFT               (3U)
/*! MU2 - MU2 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_MU2(x)                  (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_MU2_SHIFT)) & RSTCTL3_PRSTCTL1_MU2_MASK)

#define RSTCTL3_PRSTCTL1_SEMA42_0_MASK           (0x20U)
#define RSTCTL3_PRSTCTL1_SEMA42_0_SHIFT          (5U)
/*! SEMA42_0 - SEMA42_0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_SEMA42_0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_SEMA42_0_SHIFT)) & RSTCTL3_PRSTCTL1_SEMA42_0_MASK)

#define RSTCTL3_PRSTCTL1_ADC0_MASK               (0x40U)
#define RSTCTL3_PRSTCTL1_ADC0_SHIFT              (6U)
/*! ADC0 - ADC0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_ADC0(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_ADC0_SHIFT)) & RSTCTL3_PRSTCTL1_ADC0_MASK)

#define RSTCTL3_PRSTCTL1_SDADC_MASK              (0x80U)
#define RSTCTL3_PRSTCTL1_SDADC_SHIFT             (7U)
/*! SDADC - SDADC Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_SDADC(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_SDADC_SHIFT)) & RSTCTL3_PRSTCTL1_SDADC_MASK)

#define RSTCTL3_PRSTCTL1_ACMP0_MASK              (0x100U)
#define RSTCTL3_PRSTCTL1_ACMP0_SHIFT             (8U)
/*! ACMP0 - ACMP0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_ACMP0(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_ACMP0_SHIFT)) & RSTCTL3_PRSTCTL1_ACMP0_MASK)

#define RSTCTL3_PRSTCTL1_MICFIL_MASK             (0x200U)
#define RSTCTL3_PRSTCTL1_MICFIL_SHIFT            (9U)
/*! MICFIL - MICFIL Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_MICFIL(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_MICFIL_SHIFT)) & RSTCTL3_PRSTCTL1_MICFIL_MASK)

#define RSTCTL3_PRSTCTL1_INPUTMUX1_MASK          (0x4000U)
#define RSTCTL3_PRSTCTL1_INPUTMUX1_SHIFT         (14U)
/*! INPUTMUX1 - INPUTMUX1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_INPUTMUX1(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_INPUTMUX1_SHIFT)) & RSTCTL3_PRSTCTL1_INPUTMUX1_MASK)

#define RSTCTL3_PRSTCTL1_LPI2C15_MASK            (0x40000U)
#define RSTCTL3_PRSTCTL1_LPI2C15_SHIFT           (18U)
/*! LPI2C15 - LPI2C15 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_LPI2C15(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_LPI2C15_SHIFT)) & RSTCTL3_PRSTCTL1_LPI2C15_MASK)
/*! @} */

/*! @name PRSTCTL0_SET - Sense Domain Peripheral Reset Control 0 SET */
/*! @{ */

#define RSTCTL3_PRSTCTL0_SET_IOPCTL1_MASK        (0x1U)
#define RSTCTL3_PRSTCTL0_SET_IOPCTL1_SHIFT       (0U)
/*! IOPCTL1 - IOPCTL1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL0_SET_IOPCTL1(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL0_SET_IOPCTL1_SHIFT)) & RSTCTL3_PRSTCTL0_SET_IOPCTL1_MASK)

#define RSTCTL3_PRSTCTL0_SET_CPU1_MASK           (0x80000000U)
#define RSTCTL3_PRSTCTL0_SET_CPU1_SHIFT          (31U)
/*! CPU1 - CPU1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL0_SET_CPU1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL0_SET_CPU1_SHIFT)) & RSTCTL3_PRSTCTL0_SET_CPU1_MASK)
/*! @} */

/*! @name PRSTCTL1_SET - Sense Domain Peripheral Reset Control 1 SET */
/*! @{ */

#define RSTCTL3_PRSTCTL1_SET_MU0_MASK            (0x2U)
#define RSTCTL3_PRSTCTL1_SET_MU0_SHIFT           (1U)
/*! MU0 - MU0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_SET_MU0(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_SET_MU0_SHIFT)) & RSTCTL3_PRSTCTL1_SET_MU0_MASK)

#define RSTCTL3_PRSTCTL1_SET_MU1_MASK            (0x4U)
#define RSTCTL3_PRSTCTL1_SET_MU1_SHIFT           (2U)
/*! MU1 - MU1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_SET_MU1(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_SET_MU1_SHIFT)) & RSTCTL3_PRSTCTL1_SET_MU1_MASK)

#define RSTCTL3_PRSTCTL1_SET_MU2_MASK            (0x8U)
#define RSTCTL3_PRSTCTL1_SET_MU2_SHIFT           (3U)
/*! MU2 - MU2 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_SET_MU2(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_SET_MU2_SHIFT)) & RSTCTL3_PRSTCTL1_SET_MU2_MASK)

#define RSTCTL3_PRSTCTL1_SET_SEMA42_0_MASK       (0x20U)
#define RSTCTL3_PRSTCTL1_SET_SEMA42_0_SHIFT      (5U)
/*! SEMA42_0 - SEMA42_0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_SET_SEMA42_0(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_SET_SEMA42_0_SHIFT)) & RSTCTL3_PRSTCTL1_SET_SEMA42_0_MASK)

#define RSTCTL3_PRSTCTL1_SET_ADC0_MASK           (0x40U)
#define RSTCTL3_PRSTCTL1_SET_ADC0_SHIFT          (6U)
/*! ADC0 - ADC0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_SET_ADC0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_SET_ADC0_SHIFT)) & RSTCTL3_PRSTCTL1_SET_ADC0_MASK)

#define RSTCTL3_PRSTCTL1_SET_SDADC_MASK          (0x80U)
#define RSTCTL3_PRSTCTL1_SET_SDADC_SHIFT         (7U)
/*! SDADC - SDADC Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_SET_SDADC(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_SET_SDADC_SHIFT)) & RSTCTL3_PRSTCTL1_SET_SDADC_MASK)

#define RSTCTL3_PRSTCTL1_SET_ACMP0_MASK          (0x100U)
#define RSTCTL3_PRSTCTL1_SET_ACMP0_SHIFT         (8U)
/*! ACMP0 - ACMP0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_SET_ACMP0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_SET_ACMP0_SHIFT)) & RSTCTL3_PRSTCTL1_SET_ACMP0_MASK)

#define RSTCTL3_PRSTCTL1_SET_MICFIL_MASK         (0x200U)
#define RSTCTL3_PRSTCTL1_SET_MICFIL_SHIFT        (9U)
/*! MICFIL - MICFIL Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_SET_MICFIL(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_SET_MICFIL_SHIFT)) & RSTCTL3_PRSTCTL1_SET_MICFIL_MASK)

#define RSTCTL3_PRSTCTL1_SET_INPUTMUX1_MASK      (0x4000U)
#define RSTCTL3_PRSTCTL1_SET_INPUTMUX1_SHIFT     (14U)
/*! INPUTMUX1 - INPUTMUX1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_SET_INPUTMUX1(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_SET_INPUTMUX1_SHIFT)) & RSTCTL3_PRSTCTL1_SET_INPUTMUX1_MASK)

#define RSTCTL3_PRSTCTL1_SET_LPI2C15_MASK        (0x40000U)
#define RSTCTL3_PRSTCTL1_SET_LPI2C15_SHIFT       (18U)
/*! LPI2C15 - LPI2C15 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL3_PRSTCTL1_SET_LPI2C15(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_SET_LPI2C15_SHIFT)) & RSTCTL3_PRSTCTL1_SET_LPI2C15_MASK)
/*! @} */

/*! @name PRSTCTL0_CLR - Sense Domain Peripheral Reset Control 0 CLR */
/*! @{ */

#define RSTCTL3_PRSTCTL0_CLR_IOPCTL1_MASK        (0x1U)
#define RSTCTL3_PRSTCTL0_CLR_IOPCTL1_SHIFT       (0U)
/*! IOPCTL1 - IOPCTL1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL3_PRSTCTL0_CLR_IOPCTL1(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL0_CLR_IOPCTL1_SHIFT)) & RSTCTL3_PRSTCTL0_CLR_IOPCTL1_MASK)

#define RSTCTL3_PRSTCTL0_CLR_CPU1_MASK           (0x80000000U)
#define RSTCTL3_PRSTCTL0_CLR_CPU1_SHIFT          (31U)
/*! CPU1 - CPU1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL3_PRSTCTL0_CLR_CPU1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL0_CLR_CPU1_SHIFT)) & RSTCTL3_PRSTCTL0_CLR_CPU1_MASK)
/*! @} */

/*! @name PRSTCTL1_CLR - Sense Peripheral Reset Control 1 CLR */
/*! @{ */

#define RSTCTL3_PRSTCTL1_CLR_MU0_MASK            (0x2U)
#define RSTCTL3_PRSTCTL1_CLR_MU0_SHIFT           (1U)
/*! MU0 - MU0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL3_PRSTCTL1_CLR_MU0(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_CLR_MU0_SHIFT)) & RSTCTL3_PRSTCTL1_CLR_MU0_MASK)

#define RSTCTL3_PRSTCTL1_CLR_MU1_MASK            (0x4U)
#define RSTCTL3_PRSTCTL1_CLR_MU1_SHIFT           (2U)
/*! MU1 - MU1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL3_PRSTCTL1_CLR_MU1(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_CLR_MU1_SHIFT)) & RSTCTL3_PRSTCTL1_CLR_MU1_MASK)

#define RSTCTL3_PRSTCTL1_CLR_MU2_MASK            (0x8U)
#define RSTCTL3_PRSTCTL1_CLR_MU2_SHIFT           (3U)
/*! MU2 - MU2 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL3_PRSTCTL1_CLR_MU2(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_CLR_MU2_SHIFT)) & RSTCTL3_PRSTCTL1_CLR_MU2_MASK)

#define RSTCTL3_PRSTCTL1_CLR_SEMA42_0_MASK       (0x20U)
#define RSTCTL3_PRSTCTL1_CLR_SEMA42_0_SHIFT      (5U)
/*! SEMA42_0 - SEMA42_0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL3_PRSTCTL1_CLR_SEMA42_0(x)         (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_CLR_SEMA42_0_SHIFT)) & RSTCTL3_PRSTCTL1_CLR_SEMA42_0_MASK)

#define RSTCTL3_PRSTCTL1_CLR_ADC0_MASK           (0x40U)
#define RSTCTL3_PRSTCTL1_CLR_ADC0_SHIFT          (6U)
/*! ADC0 - ADC0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL3_PRSTCTL1_CLR_ADC0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_CLR_ADC0_SHIFT)) & RSTCTL3_PRSTCTL1_CLR_ADC0_MASK)

#define RSTCTL3_PRSTCTL1_CLR_SDADC_MASK          (0x80U)
#define RSTCTL3_PRSTCTL1_CLR_SDADC_SHIFT         (7U)
/*! SDADC - SDADC Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL3_PRSTCTL1_CLR_SDADC(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_CLR_SDADC_SHIFT)) & RSTCTL3_PRSTCTL1_CLR_SDADC_MASK)

#define RSTCTL3_PRSTCTL1_CLR_ACMP0_MASK          (0x100U)
#define RSTCTL3_PRSTCTL1_CLR_ACMP0_SHIFT         (8U)
/*! ACMP0 - ACMP0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL3_PRSTCTL1_CLR_ACMP0(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_CLR_ACMP0_SHIFT)) & RSTCTL3_PRSTCTL1_CLR_ACMP0_MASK)

#define RSTCTL3_PRSTCTL1_CLR_MICFIL_MASK         (0x200U)
#define RSTCTL3_PRSTCTL1_CLR_MICFIL_SHIFT        (9U)
/*! MICFIL - MICFIL Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL3_PRSTCTL1_CLR_MICFIL(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_CLR_MICFIL_SHIFT)) & RSTCTL3_PRSTCTL1_CLR_MICFIL_MASK)

#define RSTCTL3_PRSTCTL1_CLR_INPUTMUX1_MASK      (0x4000U)
#define RSTCTL3_PRSTCTL1_CLR_INPUTMUX1_SHIFT     (14U)
/*! INPUTMUX1 - INPUTMUX1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL3_PRSTCTL1_CLR_INPUTMUX1(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_CLR_INPUTMUX1_SHIFT)) & RSTCTL3_PRSTCTL1_CLR_INPUTMUX1_MASK)

#define RSTCTL3_PRSTCTL1_CLR_LPI2C15_MASK        (0x40000U)
#define RSTCTL3_PRSTCTL1_CLR_LPI2C15_SHIFT       (18U)
/*! LPI2C15 - LPI2C15 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL3_PRSTCTL1_CLR_LPI2C15(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL3_PRSTCTL1_CLR_LPI2C15_SHIFT)) & RSTCTL3_PRSTCTL1_CLR_LPI2C15_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RSTCTL3_Register_Masks */


/*!
 * @}
 */ /* end of group RSTCTL3_Peripheral_Access_Layer */


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


#endif  /* PERI_RSTCTL3_H_ */

