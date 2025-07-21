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
**         CMSIS Peripheral Access Layer for PMC
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
 * @file PERI_PMC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PMC
 *
 * CMSIS Peripheral Access Layer for PMC
 */

#if !defined(PERI_PMC_H_)
#define PERI_PMC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< PMC Version and Feature ID, offset: 0x0 */
  __I  uint32_t STATUS;                            /**< PMC Status, offset: 0x4 */
  __IO uint32_t FLAGS;                             /**< PMC Flags in Compute Domain, offset: 0x8 */
  __IO uint32_t CTRL;                              /**< Control, offset: 0xC */
  __IO uint32_t INTRCTRL;                          /**< Interrupt Control in Compute Domain, offset: 0x10 */
       uint8_t RESERVED_0[12];
  __IO uint32_t DCDCVSEL;                          /**< DCDC Voltage Selection, offset: 0x20 */
  __IO uint32_t LDOVDD2VSEL;                       /**< LDO VDD2 Voltage Selection, offset: 0x24 */
  __IO uint32_t LDOVDD1VSEL;                       /**< LDO VDD1 Voltage Selection, offset: 0x28 */
  __IO uint32_t LVDVDDNCTRL;                       /**< VDDN LVD Control, offset: 0x2C */
  __IO uint32_t LVDVDD2CTRL;                       /**< VDD2 LVD Control, offset: 0x30 */
  __IO uint32_t LVDVDD1CTRL;                       /**< VDD1 LVD Control, offset: 0x34 */
  __IO uint32_t PORCTRL;                           /**< Power-on Reset Control, offset: 0x38 */
       uint8_t RESERVED_1[4];
  __IO uint32_t BBCTRL;                            /**< Body Bias Control, offset: 0x40 */
  __IO uint32_t TSENSOR;                           /**< Temperature Sensor Control, offset: 0x44 */
       uint8_t RESERVED_2[8];
  __IO uint32_t WAKEUP;                            /**< Wake-up Configuration for Compute Domain, offset: 0x50 */
       uint8_t RESERVED_3[16];
  __IO uint32_t POWERCFG;                          /**< Power Configuration, offset: 0x64 */
  __IO uint32_t PADVRANGE;                         /**< 3 V Capable VDDIO Range Select, offset: 0x68 */
  __IO uint32_t PADCFG;                            /**< IO Bank State Configuration, offset: 0x6C */
       uint8_t RESERVED_4[48];
  __IO uint32_t PDRUNCFG0;                         /**< PD Run Configuration 0 in Compute Domain, offset: 0xA0 */
  __IO uint32_t PDRUNCFG1;                         /**< PD Run Configuration 1 in Compute Domain, offset: 0xA4 */
  __IO uint32_t PDRUNCFG2;                         /**< PD Run Configuration 2 in Compute Domain, offset: 0xA8 */
  __IO uint32_t PDRUNCFG3;                         /**< PD Run Configuration 3 in Compute Domain, offset: 0xAC */
  __IO uint32_t PDRUNCFG4;                         /**< PD Run Configuration 4 in Compute Domain, offset: 0xB0 */
  __IO uint32_t PDRUNCFG5;                         /**< PD Run Configuration 5 in Compute Domain, offset: 0xB4 */
  __IO uint32_t PDSLEEPCFG0;                       /**< PD Sleep Configuration 0 in Compute Domain, offset: 0xB8 */
  __IO uint32_t PDSLEEPCFG1;                       /**< PD Sleep Configuration 1 in Compute Domain, offset: 0xBC */
  __IO uint32_t PDSLEEPCFG2;                       /**< PD Sleep Configuration 2 in Compute Domain, offset: 0xC0 */
  __IO uint32_t PDSLEEPCFG3;                       /**< PD Sleep Configuration 3 in Compute Domain, offset: 0xC4 */
  __IO uint32_t PDSLEEPCFG4;                       /**< PD Sleep Configuration 4 in Compute Domain, offset: 0xC8 */
  __IO uint32_t PDSLEEPCFG5;                       /**< PD Sleep Configuration 5 in Compute Domain, offset: 0xCC */
  __I  uint32_t PDCFGSTATUS0;                      /**< PD Configuration Status 0, offset: 0xD0 */
  __I  uint32_t PDCFGSTATUS1;                      /**< PD Configuration Status 1, offset: 0xD4 */
  __I  uint32_t PDCFGSTATUS2;                      /**< PD Configuration Status 2, offset: 0xD8 */
  __I  uint32_t PDCFGSTATUS3;                      /**< PD Configuration Status 3, offset: 0xDC */
  __I  uint32_t PDCFGSTATUS4;                      /**< PD Configuration Status 4, offset: 0xE0 */
  __I  uint32_t PDCFGSTATUS5;                      /**< PD Configuration Status 5, offset: 0xE4 */
  __IO uint32_t PDWAKECFG;                         /**< PD Wake-up Configuration for Compute Domain, offset: 0xE8 */
  __IO uint32_t PWRFLAGS;                          /**< Power Domain Flags for Compute Domain, offset: 0xEC */
} PMC_Type;

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/*! @name VERID - PMC Version and Feature ID */
/*! @{ */

#define PMC_VERID_FEATURE_MASK                   (0xFFFFU)
#define PMC_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Identification Number */
#define PMC_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_VERID_FEATURE_SHIFT)) & PMC_VERID_FEATURE_MASK)

#define PMC_VERID_MINOR_MASK                     (0xFF0000U)
#define PMC_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define PMC_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_VERID_MINOR_SHIFT)) & PMC_VERID_MINOR_MASK)

#define PMC_VERID_MAJOR_MASK                     (0xFF000000U)
#define PMC_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define PMC_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_VERID_MAJOR_SHIFT)) & PMC_VERID_MAJOR_MASK)
/*! @} */

/*! @name STATUS - PMC Status */
/*! @{ */

#define PMC_STATUS_BUSY_MASK                     (0x1U)
#define PMC_STATUS_BUSY_SHIFT                    (0U)
/*! BUSY - Finite State Machine Status
 *  0b0..PMC state machines are idle
 *  0b1..PMC state machine is busy
 */
#define PMC_STATUS_BUSY(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_BUSY_SHIFT)) & PMC_STATUS_BUSY_MASK)

#define PMC_STATUS_LVDVDD1_MASK                  (0x40000U)
#define PMC_STATUS_LVDVDD1_SHIFT                 (18U)
/*! LVDVDD1 - VDD1 Low-Voltage Detector
 *  0b0..Detector is not tripped
 *  0b1..Detector is tripped
 */
#define PMC_STATUS_LVDVDD1(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_LVDVDD1_SHIFT)) & PMC_STATUS_LVDVDD1_MASK)

#define PMC_STATUS_LVDVDD2_MASK                  (0x80000U)
#define PMC_STATUS_LVDVDD2_SHIFT                 (19U)
/*! LVDVDD2 - VDD2 Low-Voltage Detector
 *  0b0..Detector is not tripped
 *  0b1..Detector is tripped
 */
#define PMC_STATUS_LVDVDD2(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_LVDVDD2_SHIFT)) & PMC_STATUS_LVDVDD2_MASK)

#define PMC_STATUS_LVDVDDN_MASK                  (0x100000U)
#define PMC_STATUS_LVDVDDN_SHIFT                 (20U)
/*! LVDVDDN - VDDN Low-Voltage Detector
 *  0b0..Detector is not tripped
 *  0b1..Detector is tripped
 */
#define PMC_STATUS_LVDVDDN(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_LVDVDDN_SHIFT)) & PMC_STATUS_LVDVDDN_MASK)

#define PMC_STATUS_HVDVDD1_MASK                  (0x200000U)
#define PMC_STATUS_HVDVDD1_SHIFT                 (21U)
/*! HVDVDD1 - VDD1 High-Voltage Detector
 *  0b0..Detector is not tripped
 *  0b1..Detector is tripped
 */
#define PMC_STATUS_HVDVDD1(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_HVDVDD1_SHIFT)) & PMC_STATUS_HVDVDD1_MASK)

#define PMC_STATUS_HVDVDD2_MASK                  (0x400000U)
#define PMC_STATUS_HVDVDD2_SHIFT                 (22U)
/*! HVDVDD2 - VDD2 High-Voltage Detector
 *  0b0..Detector is not tripped
 *  0b1..Detector is tripped
 */
#define PMC_STATUS_HVDVDD2(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_HVDVDD2_SHIFT)) & PMC_STATUS_HVDVDD2_MASK)

#define PMC_STATUS_HVDVDDN_MASK                  (0x800000U)
#define PMC_STATUS_HVDVDDN_SHIFT                 (23U)
/*! HVDVDDN - VDDN High-Voltage Detector
 *  0b0..Detector is not tripped
 *  0b1..Detector is tripped
 */
#define PMC_STATUS_HVDVDDN(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_HVDVDDN_SHIFT)) & PMC_STATUS_HVDVDDN_MASK)

#define PMC_STATUS_HVD1V8_MASK                   (0x1000000U)
#define PMC_STATUS_HVD1V8_SHIFT                  (24U)
/*! HVD1V8 - VDD1V8 High-Voltage Detector
 *  0b0..Detector is not tripped
 *  0b1..Detector is tripped
 */
#define PMC_STATUS_HVD1V8(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_HVD1V8_SHIFT)) & PMC_STATUS_HVD1V8_MASK)

#define PMC_STATUS_RTCWKUP_MASK                  (0x2000000U)
#define PMC_STATUS_RTCWKUP_SHIFT                 (25U)
/*! RTCWKUP - RTC Wake-up
 *  0b0..Compute RTC wake-up is not active
 *  0b1..Compute RTC wake-up is asserted
 */
#define PMC_STATUS_RTCWKUP(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_RTCWKUP_SHIFT)) & PMC_STATUS_RTCWKUP_MASK)

#define PMC_STATUS_INTN_MASK                     (0x8000000U)
#define PMC_STATUS_INTN_SHIFT                    (27U)
/*! INTN - PMIC_IRQN Interrupt Input
 *  0b0..Negated. Pin is high
 *  0b1..Asserted. Pin is low
 */
#define PMC_STATUS_INTN(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_INTN_SHIFT)) & PMC_STATUS_INTN_MASK)

#define PMC_STATUS_DSSENS_MASK                   (0x20000000U)
#define PMC_STATUS_DSSENS_SHIFT                  (29U)
/*! DSSENS - CPU1 Deep Sleep
 *  0b0..CPU1 is in Active mode
 *  0b1..CPU1 is in Deep Sleep mode
 */
#define PMC_STATUS_DSSENS(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_DSSENS_SHIFT)) & PMC_STATUS_DSSENS_MASK)

#define PMC_STATUS_DSCOMP_MASK                   (0x40000000U)
#define PMC_STATUS_DSCOMP_SHIFT                  (30U)
/*! DSCOMP - CPU0 Deep Sleep
 *  0b0..CPU0 is in Active mode
 *  0b1..CPU0 is in Deep Sleep mode
 */
#define PMC_STATUS_DSCOMP(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_STATUS_DSCOMP_SHIFT)) & PMC_STATUS_DSCOMP_MASK)
/*! @} */

/*! @name FLAGS - PMC Flags in Compute Domain */
/*! @{ */

#define PMC_FLAGS_DSALLF_MASK                    (0x1U)
#define PMC_FLAGS_DSALLF_SHIFT                   (0U)
/*! DSALLF - Deep Sleep Flag
 *  0b0..CPU0 and CPU1 are not in Deep Sleep mode at the same time
 *  0b1..CPU0 and CPU1 have both been in Deep Sleep mode at the same time
 */
#define PMC_FLAGS_DSALLF(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_DSALLF_SHIFT)) & PMC_FLAGS_DSALLF_MASK)

#define PMC_FLAGS_ITRCRF_MASK                    (0x2U)
#define PMC_FLAGS_ITRCRF_SHIFT                   (1U)
/*! ITRCRF - ITRC RAM ZEROIZE Flag
 *  0b0..Not detected
 *  0b1..ITRC RAM ZEROIZE detected
 */
#define PMC_FLAGS_ITRCRF(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_ITRCRF_SHIFT)) & PMC_FLAGS_ITRCRF_MASK)

#define PMC_FLAGS_BBSR1EF_MASK                   (0x4U)
#define PMC_FLAGS_BBSR1EF_SHIFT                  (2U)
/*! BBSR1EF - VDD1 SRAM Body Bias Error Flag
 *  0b0..No SRAM body bias error
 *  0b1..SRAM body bias error detected
 */
#define PMC_FLAGS_BBSR1EF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_BBSR1EF_SHIFT)) & PMC_FLAGS_BBSR1EF_MASK)

#define PMC_FLAGS_BBSR2EF_MASK                   (0x8U)
#define PMC_FLAGS_BBSR2EF_SHIFT                  (3U)
/*! BBSR2EF - VDD2 SRAM Body Bias Error Flag
 *  0b0..No SRAM body bias error
 *  0b1..SRAM body bias error detected
 */
#define PMC_FLAGS_BBSR2EF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_BBSR2EF_SHIFT)) & PMC_FLAGS_BBSR2EF_MASK)

#define PMC_FLAGS_BB1EF_MASK                     (0x10U)
#define PMC_FLAGS_BB1EF_SHIFT                    (4U)
/*! BB1EF - VDD1 Body Bias Error Flag
 *  0b0..No body bias error
 *  0b1..Body bias error detected
 */
#define PMC_FLAGS_BB1EF(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_BB1EF_SHIFT)) & PMC_FLAGS_BB1EF_MASK)

#define PMC_FLAGS_BB2EF_MASK                     (0x20U)
#define PMC_FLAGS_BB2EF_SHIFT                    (5U)
/*! BB2EF - VDD2 Body Bias Error Flag
 *  0b0..No body bias error
 *  0b1..Body bias error detected
 */
#define PMC_FLAGS_BB2EF(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_BB2EF_SHIFT)) & PMC_FLAGS_BB2EF_MASK)

#define PMC_FLAGS_BBNEF_MASK                     (0x40U)
#define PMC_FLAGS_BBNEF_SHIFT                    (6U)
/*! BBNEF - VDDN Body Bias Error Flag
 *  0b0..No body bias error
 *  0b1..Body bias error detected
 */
#define PMC_FLAGS_BBNEF(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_BBNEF_SHIFT)) & PMC_FLAGS_BBNEF_MASK)

#define PMC_FLAGS_SCP1OCF_MASK                   (0x80U)
#define PMC_FLAGS_SCP1OCF_SHIFT                  (7U)
/*! SCP1OCF - SCPC VDD1 Overcurrent Flag
 *  0b0..No overcurrent event detected
 *  0b1..Overcurrent event detected
 */
#define PMC_FLAGS_SCP1OCF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_SCP1OCF_SHIFT)) & PMC_FLAGS_SCP1OCF_MASK)

#define PMC_FLAGS_SCP2OCF_MASK                   (0x100U)
#define PMC_FLAGS_SCP2OCF_SHIFT                  (8U)
/*! SCP2OCF - SCPC VDD2 Overcurrent Flag
 *  0b0..No overcurrent event detected
 *  0b1..Overcurrent event detected
 */
#define PMC_FLAGS_SCP2OCF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_SCP2OCF_SHIFT)) & PMC_FLAGS_SCP2OCF_MASK)

#define PMC_FLAGS_DCHPOCF_MASK                   (0x200U)
#define PMC_FLAGS_DCHPOCF_SHIFT                  (9U)
/*! DCHPOCF - DCDC High-Power Mode Overcurrent Flag
 *  0b0..No overcurrent event detected
 *  0b1..Overcurrent event detected
 */
#define PMC_FLAGS_DCHPOCF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_DCHPOCF_SHIFT)) & PMC_FLAGS_DCHPOCF_MASK)

#define PMC_FLAGS_DCLPOCF_MASK                   (0x400U)
#define PMC_FLAGS_DCLPOCF_SHIFT                  (10U)
/*! DCLPOCF - DCDC Low-Power Mode Overcurrent Flag
 *  0b0..No overcurrent event detected
 *  0b1..Overcurrent event detected
 */
#define PMC_FLAGS_DCLPOCF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_DCLPOCF_SHIFT)) & PMC_FLAGS_DCLPOCF_MASK)

#define PMC_FLAGS_PORVDD1F_MASK                  (0x800U)
#define PMC_FLAGS_PORVDD1F_SHIFT                 (11U)
/*! PORVDD1F - VDD1 Power-on Reset Flag
 *  0b0..POR status cleared
 *  0b1..POR status asserted
 */
#define PMC_FLAGS_PORVDD1F(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_PORVDD1F_SHIFT)) & PMC_FLAGS_PORVDD1F_MASK)

#define PMC_FLAGS_PORVDD2F_MASK                  (0x1000U)
#define PMC_FLAGS_PORVDD2F_SHIFT                 (12U)
/*! PORVDD2F - VDD2 Power-on Reset Flag
 *  0b0..POR status cleared
 *  0b1..POR status asserted
 */
#define PMC_FLAGS_PORVDD2F(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_PORVDD2F_SHIFT)) & PMC_FLAGS_PORVDD2F_MASK)

#define PMC_FLAGS_PORVDDNF_MASK                  (0x2000U)
#define PMC_FLAGS_PORVDDNF_SHIFT                 (13U)
/*! PORVDDNF - VDDN Power-on Reset Flag
 *  0b0..POR status cleared
 *  0b1..POR status asserted
 */
#define PMC_FLAGS_PORVDDNF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_PORVDDNF_SHIFT)) & PMC_FLAGS_PORVDDNF_MASK)

#define PMC_FLAGS_POR1V8F_MASK                   (0x4000U)
#define PMC_FLAGS_POR1V8F_SHIFT                  (14U)
/*! POR1V8F - VDD1V8 Power-on Reset Flag
 *  0b0..POR status cleared
 *  0b1..POR status asserted
 */
#define PMC_FLAGS_POR1V8F(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_POR1V8F_SHIFT)) & PMC_FLAGS_POR1V8F_MASK)

#define PMC_FLAGS_PORAO18F_MASK                  (0x8000U)
#define PMC_FLAGS_PORAO18F_SHIFT                 (15U)
/*! PORAO18F - VDD1V8_AO Power-on Reset Flag
 *  0b0..POR status cleared
 *  0b1..POR status asserted
 */
#define PMC_FLAGS_PORAO18F(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_PORAO18F_SHIFT)) & PMC_FLAGS_PORAO18F_MASK)

#define PMC_FLAGS_AGDET1F_MASK                   (0x10000U)
#define PMC_FLAGS_AGDET1F_SHIFT                  (16U)
/*! AGDET1F - VDD1 Glitch Detector Flag
 *  0b0..Glitch detector status cleared
 *  0b1..Glitch detector status asserted
 */
#define PMC_FLAGS_AGDET1F(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_AGDET1F_SHIFT)) & PMC_FLAGS_AGDET1F_MASK)

#define PMC_FLAGS_AGDET2F_MASK                   (0x20000U)
#define PMC_FLAGS_AGDET2F_SHIFT                  (17U)
/*! AGDET2F - VDD2 Glitch Detector Flag
 *  0b0..Glitch detector status cleared
 *  0b1..Glitch detector status asserted
 */
#define PMC_FLAGS_AGDET2F(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_AGDET2F_SHIFT)) & PMC_FLAGS_AGDET2F_MASK)

#define PMC_FLAGS_LVDVDD1F_MASK                  (0x40000U)
#define PMC_FLAGS_LVDVDD1F_SHIFT                 (18U)
/*! LVDVDD1F - VDD1 Low-Voltage Detector Flag
 *  0b0..Low-voltage detector status cleared
 *  0b1..Low-voltage detector status asserted
 */
#define PMC_FLAGS_LVDVDD1F(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_LVDVDD1F_SHIFT)) & PMC_FLAGS_LVDVDD1F_MASK)

#define PMC_FLAGS_LVDVDD2F_MASK                  (0x80000U)
#define PMC_FLAGS_LVDVDD2F_SHIFT                 (19U)
/*! LVDVDD2F - VDD2 Low-Voltage Detector Flag
 *  0b0..Low-voltage detector status cleared
 *  0b1..Low-voltage detector status asserted
 */
#define PMC_FLAGS_LVDVDD2F(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_LVDVDD2F_SHIFT)) & PMC_FLAGS_LVDVDD2F_MASK)

#define PMC_FLAGS_LVDVDDNF_MASK                  (0x100000U)
#define PMC_FLAGS_LVDVDDNF_SHIFT                 (20U)
/*! LVDVDDNF - VDDN Low-Voltage Detector Flag
 *  0b0..Low-voltage detector status cleared
 *  0b1..Low-voltage detector status asserted
 */
#define PMC_FLAGS_LVDVDDNF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_LVDVDDNF_SHIFT)) & PMC_FLAGS_LVDVDDNF_MASK)

#define PMC_FLAGS_HVDVDD1F_MASK                  (0x200000U)
#define PMC_FLAGS_HVDVDD1F_SHIFT                 (21U)
/*! HVDVDD1F - VDD1 High-Voltage Detector Flag
 *  0b0..High-voltage detector status cleared
 *  0b1..High-voltage detector status asserted
 */
#define PMC_FLAGS_HVDVDD1F(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_HVDVDD1F_SHIFT)) & PMC_FLAGS_HVDVDD1F_MASK)

#define PMC_FLAGS_HVDVDD2F_MASK                  (0x400000U)
#define PMC_FLAGS_HVDVDD2F_SHIFT                 (22U)
/*! HVDVDD2F - VDD2 High-Voltage Detector Flag
 *  0b0..High-voltage detector status cleared
 *  0b1..High-voltage detector status asserted
 */
#define PMC_FLAGS_HVDVDD2F(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_HVDVDD2F_SHIFT)) & PMC_FLAGS_HVDVDD2F_MASK)

#define PMC_FLAGS_HVDVDDNF_MASK                  (0x800000U)
#define PMC_FLAGS_HVDVDDNF_SHIFT                 (23U)
/*! HVDVDDNF - VDDN High-Voltage Detector Flag
 *  0b0..High-voltage detector status cleared
 *  0b1..High-voltage detector status asserted
 */
#define PMC_FLAGS_HVDVDDNF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_HVDVDDNF_SHIFT)) & PMC_FLAGS_HVDVDDNF_MASK)

#define PMC_FLAGS_HVD1V8F_MASK                   (0x1000000U)
#define PMC_FLAGS_HVD1V8F_SHIFT                  (24U)
/*! HVD1V8F - VDD1V8 High-Voltage Detector Flag
 *  0b0..High-voltage detector status cleared
 *  0b1..High-voltage detector status asserted
 */
#define PMC_FLAGS_HVD1V8F(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_HVD1V8F_SHIFT)) & PMC_FLAGS_HVD1V8F_MASK)

#define PMC_FLAGS_RTCF_MASK                      (0x2000000U)
#define PMC_FLAGS_RTCF_SHIFT                     (25U)
/*! RTCF - RTC Flag
 *  0b0..RTC status cleared
 *  0b1..RTC status asserted
 */
#define PMC_FLAGS_RTCF(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_RTCF_SHIFT)) & PMC_FLAGS_RTCF_MASK)

#define PMC_FLAGS_AUTOWKF_MASK                   (0x4000000U)
#define PMC_FLAGS_AUTOWKF_SHIFT                  (26U)
/*! AUTOWKF - Auto Wake-up Flag
 *  0b0..Auto wake-up status cleared
 *  0b1..Auto wake-up status asserted
 */
#define PMC_FLAGS_AUTOWKF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_AUTOWKF_SHIFT)) & PMC_FLAGS_AUTOWKF_MASK)

#define PMC_FLAGS_INTNF_MASK                     (0x8000000U)
#define PMC_FLAGS_INTNF_SHIFT                    (27U)
/*! INTNF - PMIC_IRQN Interrupt Pin Flag
 *  0b0..Interrupt pin status cleared
 *  0b1..Interrupt pin status asserted
 */
#define PMC_FLAGS_INTNF(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_INTNF_SHIFT)) & PMC_FLAGS_INTNF_MASK)

#define PMC_FLAGS_RESETNF_MASK                   (0x10000000U)
#define PMC_FLAGS_RESETNF_SHIFT                  (28U)
/*! RESETNF - Reset Pin Flag
 *  0b0..Reset pin status cleared
 *  0b1..Reset pin status asserted
 */
#define PMC_FLAGS_RESETNF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_RESETNF_SHIFT)) & PMC_FLAGS_RESETNF_MASK)

#define PMC_FLAGS_DSSENSF_MASK                   (0x20000000U)
#define PMC_FLAGS_DSSENSF_SHIFT                  (29U)
/*! DSSENSF - CPU1 Deep Sleep Mode Flag
 *  0b0..CPU1 Deep Sleep cleared
 *  0b1..CPU1 Deep Sleep asserted
 */
#define PMC_FLAGS_DSSENSF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_DSSENSF_SHIFT)) & PMC_FLAGS_DSSENSF_MASK)

#define PMC_FLAGS_DSCOMPF_MASK                   (0x40000000U)
#define PMC_FLAGS_DSCOMPF_SHIFT                  (30U)
/*! DSCOMPF - CPU0 Deep Sleep Flag
 *  0b0..CPU0 Deep Sleep cleared
 *  0b1..CPU0 Deep Sleep asserted
 */
#define PMC_FLAGS_DSCOMPF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_DSCOMPF_SHIFT)) & PMC_FLAGS_DSCOMPF_MASK)

#define PMC_FLAGS_DEEPPDF_MASK                   (0x80000000U)
#define PMC_FLAGS_DEEPPDF_SHIFT                  (31U)
/*! DEEPPDF - DPD Wake-up Flag
 *  0b0..DPD wake-up cleared
 *  0b1..DPD wake-up asserted
 */
#define PMC_FLAGS_DEEPPDF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_FLAGS_DEEPPDF_SHIFT)) & PMC_FLAGS_DEEPPDF_MASK)
/*! @} */

/*! @name CTRL - Control */
/*! @{ */

#define PMC_CTRL_APPLYCFG_MASK                   (0x1U)
#define PMC_CTRL_APPLYCFG_SHIFT                  (0U)
/*! APPLYCFG - Apply Configure for PMC1
 *  0b0..Operation is done
 *  0b1..Start configuration change, or operation has not completed
 */
#define PMC_CTRL_APPLYCFG(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_APPLYCFG_SHIFT)) & PMC_CTRL_APPLYCFG_MASK)

#define PMC_CTRL_AGDET1RE_MASK                   (0x10000U)
#define PMC_CTRL_AGDET1RE_SHIFT                  (16U)
/*! AGDET1RE - VDD1 Glitch Detector Reset Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PMC_CTRL_AGDET1RE(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_AGDET1RE_SHIFT)) & PMC_CTRL_AGDET1RE_MASK)

#define PMC_CTRL_AGDET2RE_MASK                   (0x20000U)
#define PMC_CTRL_AGDET2RE_SHIFT                  (17U)
/*! AGDET2RE - VDD2 Glitch Detector Reset Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PMC_CTRL_AGDET2RE(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_AGDET2RE_SHIFT)) & PMC_CTRL_AGDET2RE_MASK)

#define PMC_CTRL_LVD1RE_MASK                     (0x40000U)
#define PMC_CTRL_LVD1RE_SHIFT                    (18U)
/*! LVD1RE - VDD1 Low-Voltage Detector Reset Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PMC_CTRL_LVD1RE(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_LVD1RE_SHIFT)) & PMC_CTRL_LVD1RE_MASK)

#define PMC_CTRL_LVD2RE_MASK                     (0x80000U)
#define PMC_CTRL_LVD2RE_SHIFT                    (19U)
/*! LVD2RE - VDD2 Low-Voltage Detector Reset Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PMC_CTRL_LVD2RE(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_LVD2RE_SHIFT)) & PMC_CTRL_LVD2RE_MASK)

#define PMC_CTRL_LVDNRE_MASK                     (0x100000U)
#define PMC_CTRL_LVDNRE_SHIFT                    (20U)
/*! LVDNRE - VDDN Low-Voltage Detector Reset Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PMC_CTRL_LVDNRE(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_LVDNRE_SHIFT)) & PMC_CTRL_LVDNRE_MASK)

#define PMC_CTRL_HVDV1RE_MASK                    (0x200000U)
#define PMC_CTRL_HVDV1RE_SHIFT                   (21U)
/*! HVDV1RE - VDD1 High-Voltage Detector Reset Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PMC_CTRL_HVDV1RE(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_HVDV1RE_SHIFT)) & PMC_CTRL_HVDV1RE_MASK)

#define PMC_CTRL_HVDV2RE_MASK                    (0x400000U)
#define PMC_CTRL_HVDV2RE_SHIFT                   (22U)
/*! HVDV2RE - VDD2 High-Voltage Detector Reset Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PMC_CTRL_HVDV2RE(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_HVDV2RE_SHIFT)) & PMC_CTRL_HVDV2RE_MASK)

#define PMC_CTRL_HVDVNRE_MASK                    (0x800000U)
#define PMC_CTRL_HVDVNRE_SHIFT                   (23U)
/*! HVDVNRE - VDDN High-Voltage Detector Reset Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PMC_CTRL_HVDVNRE(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_HVDVNRE_SHIFT)) & PMC_CTRL_HVDVNRE_MASK)

#define PMC_CTRL_HVD1V8RE_MASK                   (0x1000000U)
#define PMC_CTRL_HVD1V8RE_SHIFT                  (24U)
/*! HVD1V8RE - VDD1V8 High-Voltage Detector Reset Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PMC_CTRL_HVD1V8RE(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CTRL_HVD1V8RE_SHIFT)) & PMC_CTRL_HVD1V8RE_MASK)
/*! @} */

/*! @name INTRCTRL - Interrupt Control in Compute Domain */
/*! @{ */

#define PMC_INTRCTRL_BBSR1EIE_MASK               (0x4U)
#define PMC_INTRCTRL_BBSR1EIE_SHIFT              (2U)
/*! BBSR1EIE - VDD1 SRAM Body Bias Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_BBSR1EIE(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_BBSR1EIE_SHIFT)) & PMC_INTRCTRL_BBSR1EIE_MASK)

#define PMC_INTRCTRL_BBSR2EIE_MASK               (0x8U)
#define PMC_INTRCTRL_BBSR2EIE_SHIFT              (3U)
/*! BBSR2EIE - VDD2 SRAM Body Bias Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_BBSR2EIE(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_BBSR2EIE_SHIFT)) & PMC_INTRCTRL_BBSR2EIE_MASK)

#define PMC_INTRCTRL_BB1EIE_MASK                 (0x10U)
#define PMC_INTRCTRL_BB1EIE_SHIFT                (4U)
/*! BB1EIE - VDD1 Body Bias Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_BB1EIE(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_BB1EIE_SHIFT)) & PMC_INTRCTRL_BB1EIE_MASK)

#define PMC_INTRCTRL_BB2EIE_MASK                 (0x20U)
#define PMC_INTRCTRL_BB2EIE_SHIFT                (5U)
/*! BB2EIE - VDD2 Body Bias Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_BB2EIE(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_BB2EIE_SHIFT)) & PMC_INTRCTRL_BB2EIE_MASK)

#define PMC_INTRCTRL_BBNEIE_MASK                 (0x40U)
#define PMC_INTRCTRL_BBNEIE_SHIFT                (6U)
/*! BBNEIE - VDDN Body Bias Error Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_BBNEIE(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_BBNEIE_SHIFT)) & PMC_INTRCTRL_BBNEIE_MASK)

#define PMC_INTRCTRL_SCP1OCIE_MASK               (0x80U)
#define PMC_INTRCTRL_SCP1OCIE_SHIFT              (7U)
/*! SCP1OCIE - SCPC VDD1 Overcurrent Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_SCP1OCIE(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_SCP1OCIE_SHIFT)) & PMC_INTRCTRL_SCP1OCIE_MASK)

#define PMC_INTRCTRL_SCP2OCIE_MASK               (0x100U)
#define PMC_INTRCTRL_SCP2OCIE_SHIFT              (8U)
/*! SCP2OCIE - SCPC VDD2 Overcurrent Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_SCP2OCIE(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_SCP2OCIE_SHIFT)) & PMC_INTRCTRL_SCP2OCIE_MASK)

#define PMC_INTRCTRL_DCHPOCIE_MASK               (0x200U)
#define PMC_INTRCTRL_DCHPOCIE_SHIFT              (9U)
/*! DCHPOCIE - DCDC High-Power Overcurrent Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_DCHPOCIE(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_DCHPOCIE_SHIFT)) & PMC_INTRCTRL_DCHPOCIE_MASK)

#define PMC_INTRCTRL_DCLPOCIE_MASK               (0x400U)
#define PMC_INTRCTRL_DCLPOCIE_SHIFT              (10U)
/*! DCLPOCIE - DCDC Low-Power Overcurrent Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_DCLPOCIE(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_DCLPOCIE_SHIFT)) & PMC_INTRCTRL_DCLPOCIE_MASK)

#define PMC_INTRCTRL_AGDET1IE_MASK               (0x10000U)
#define PMC_INTRCTRL_AGDET1IE_SHIFT              (16U)
/*! AGDET1IE - VDD1 Glitch Detector Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_AGDET1IE(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_AGDET1IE_SHIFT)) & PMC_INTRCTRL_AGDET1IE_MASK)

#define PMC_INTRCTRL_AGDET2IE_MASK               (0x20000U)
#define PMC_INTRCTRL_AGDET2IE_SHIFT              (17U)
/*! AGDET2IE - VDD2 Glitch Detector Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_AGDET2IE(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_AGDET2IE_SHIFT)) & PMC_INTRCTRL_AGDET2IE_MASK)

#define PMC_INTRCTRL_LVD1IE_MASK                 (0x40000U)
#define PMC_INTRCTRL_LVD1IE_SHIFT                (18U)
/*! LVD1IE - VDD1 Low-Voltage Detector Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_LVD1IE(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_LVD1IE_SHIFT)) & PMC_INTRCTRL_LVD1IE_MASK)

#define PMC_INTRCTRL_LVD2IE_MASK                 (0x80000U)
#define PMC_INTRCTRL_LVD2IE_SHIFT                (19U)
/*! LVD2IE - VDD2 Low-Voltage Detector Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_LVD2IE(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_LVD2IE_SHIFT)) & PMC_INTRCTRL_LVD2IE_MASK)

#define PMC_INTRCTRL_LVDNIE_MASK                 (0x100000U)
#define PMC_INTRCTRL_LVDNIE_SHIFT                (20U)
/*! LVDNIE - VDDN Low-Voltage Detector Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_LVDNIE(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_LVDNIE_SHIFT)) & PMC_INTRCTRL_LVDNIE_MASK)

#define PMC_INTRCTRL_HVD1IE_MASK                 (0x200000U)
#define PMC_INTRCTRL_HVD1IE_SHIFT                (21U)
/*! HVD1IE - VDD1 High-Voltage Detector Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_HVD1IE(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_HVD1IE_SHIFT)) & PMC_INTRCTRL_HVD1IE_MASK)

#define PMC_INTRCTRL_HVD2IE_MASK                 (0x400000U)
#define PMC_INTRCTRL_HVD2IE_SHIFT                (22U)
/*! HVD2IE - VDD2 High-Voltage Detector Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_HVD2IE(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_HVD2IE_SHIFT)) & PMC_INTRCTRL_HVD2IE_MASK)

#define PMC_INTRCTRL_HVDNIE_MASK                 (0x800000U)
#define PMC_INTRCTRL_HVDNIE_SHIFT                (23U)
/*! HVDNIE - VDDN High-Voltage Detector Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_HVDNIE(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_HVDNIE_SHIFT)) & PMC_INTRCTRL_HVDNIE_MASK)

#define PMC_INTRCTRL_HVD1V8IE_MASK               (0x1000000U)
#define PMC_INTRCTRL_HVD1V8IE_SHIFT              (24U)
/*! HVD1V8IE - VDD1V8 High-Voltage Detector Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_HVD1V8IE(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_HVD1V8IE_SHIFT)) & PMC_INTRCTRL_HVD1V8IE_MASK)

#define PMC_INTRCTRL_AUTOWKIE_MASK               (0x4000000U)
#define PMC_INTRCTRL_AUTOWKIE_SHIFT              (26U)
/*! AUTOWKIE - Auto Wake-up Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_AUTOWKIE(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_AUTOWKIE_SHIFT)) & PMC_INTRCTRL_AUTOWKIE_MASK)

#define PMC_INTRCTRL_INTNIE_MASK                 (0x8000000U)
#define PMC_INTRCTRL_INTNIE_SHIFT                (27U)
/*! INTNIE - PMIC_IRQN PAD Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_INTNIE(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_INTNIE_SHIFT)) & PMC_INTRCTRL_INTNIE_MASK)

#define PMC_INTRCTRL_DSSENSIE_MASK               (0x20000000U)
#define PMC_INTRCTRL_DSSENSIE_SHIFT              (29U)
/*! DSSENSIE - CPU1 Deep Sleep Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_DSSENSIE(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_DSSENSIE_SHIFT)) & PMC_INTRCTRL_DSSENSIE_MASK)

#define PMC_INTRCTRL_DSCOMPIE_MASK               (0x40000000U)
#define PMC_INTRCTRL_DSCOMPIE_SHIFT              (30U)
/*! DSCOMPIE - CPU0 Deep Sleep Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PMC_INTRCTRL_DSCOMPIE(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_INTRCTRL_DSCOMPIE_SHIFT)) & PMC_INTRCTRL_DSCOMPIE_MASK)
/*! @} */

/*! @name DCDCVSEL - DCDC Voltage Selection */
/*! @{ */

#define PMC_DCDCVSEL_VSEL0_MASK                  (0x7FU)
#define PMC_DCDCVSEL_VSEL0_SHIFT                 (0U)
/*! VSEL0 - DCDC Voltage Level 0
 *  0b0000000..0.50 V
 *  0b0100000..0.70 V
 *  0b1000000..0.90 V
 *  0b1100000..1.10 V
 *  0b1101000..1.15 V (maximum)
 *  0b1111111..1.15 V (clipped)
 */
#define PMC_DCDCVSEL_VSEL0(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_DCDCVSEL_VSEL0_SHIFT)) & PMC_DCDCVSEL_VSEL0_MASK)

#define PMC_DCDCVSEL_VSEL1_MASK                  (0x7F00U)
#define PMC_DCDCVSEL_VSEL1_SHIFT                 (8U)
/*! VSEL1 - DCDC Voltage Level 1
 *  0b0000000..0.50 V
 *  0b0100000..0.70 V
 *  0b1000000..0.90 V
 *  0b1100000..1.10 V
 *  0b1101000..1.15 V (maximum)
 *  0b1111111..1.15 V (clipped)
 */
#define PMC_DCDCVSEL_VSEL1(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_DCDCVSEL_VSEL1_SHIFT)) & PMC_DCDCVSEL_VSEL1_MASK)
/*! @} */

/*! @name LDOVDD2VSEL - LDO VDD2 Voltage Selection */
/*! @{ */

#define PMC_LDOVDD2VSEL_VSEL0_MASK               (0x3FU)
#define PMC_LDOVDD2VSEL_VSEL0_SHIFT              (0U)
/*! VSEL0 - LDO VDD2 Voltage Level 0
 *  0b000000..0.45 V
 *  0b010000..0.65 V
 *  0b100000..0.85 V
 *  0b110000..1.05 V
 *  0b111000..1.15 V (maximum)
 *  0b111111..1.15 V (clipped)
 */
#define PMC_LDOVDD2VSEL_VSEL0(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_LDOVDD2VSEL_VSEL0_SHIFT)) & PMC_LDOVDD2VSEL_VSEL0_MASK)

#define PMC_LDOVDD2VSEL_VSEL1_MASK               (0x3F00U)
#define PMC_LDOVDD2VSEL_VSEL1_SHIFT              (8U)
/*! VSEL1 - LDO VDD2 Voltage Level 1
 *  0b000000..0.45 V
 *  0b010000..0.65 V
 *  0b100000..0.85 V
 *  0b110000..1.05 V
 *  0b111000..1.15 V (maximum)
 *  0b111111..1.15 V (clipped)
 */
#define PMC_LDOVDD2VSEL_VSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_LDOVDD2VSEL_VSEL1_SHIFT)) & PMC_LDOVDD2VSEL_VSEL1_MASK)

#define PMC_LDOVDD2VSEL_VSEL2_MASK               (0x3F0000U)
#define PMC_LDOVDD2VSEL_VSEL2_SHIFT              (16U)
/*! VSEL2 - LDO VDD2 Voltage Level 2
 *  0b000000..0.45 V
 *  0b010000..0.65 V
 *  0b100000..0.85 V
 *  0b110000..1.05 V
 *  0b111000..1.15 V (maximum)
 *  0b111111..1.15 V (clipped)
 */
#define PMC_LDOVDD2VSEL_VSEL2(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_LDOVDD2VSEL_VSEL2_SHIFT)) & PMC_LDOVDD2VSEL_VSEL2_MASK)

#define PMC_LDOVDD2VSEL_VSEL3_MASK               (0x3F000000U)
#define PMC_LDOVDD2VSEL_VSEL3_SHIFT              (24U)
/*! VSEL3 - LDO VDD2 Voltage Level 3
 *  0b000000..0.45 V
 *  0b010000..0.65 V
 *  0b100000..0.85 V
 *  0b110000..1.05 V
 *  0b111000..1.15 V (maximum)
 *  0b111111..1.15 V (clipped)
 */
#define PMC_LDOVDD2VSEL_VSEL3(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_LDOVDD2VSEL_VSEL3_SHIFT)) & PMC_LDOVDD2VSEL_VSEL3_MASK)
/*! @} */

/*! @name LDOVDD1VSEL - LDO VDD1 Voltage Selection */
/*! @{ */

#define PMC_LDOVDD1VSEL_VSEL0_MASK               (0x3FU)
#define PMC_LDOVDD1VSEL_VSEL0_SHIFT              (0U)
/*! VSEL0 - LDO VDD1 Voltage Level 0
 *  0b000000..0.45 V
 *  0b010000..0.65 V
 *  0b100000..0.85 V
 *  0b110000..1.05 V
 *  0b111000..1.15 V (maximum)
 *  0b111111..1.15 V (clipped)
 */
#define PMC_LDOVDD1VSEL_VSEL0(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_LDOVDD1VSEL_VSEL0_SHIFT)) & PMC_LDOVDD1VSEL_VSEL0_MASK)

#define PMC_LDOVDD1VSEL_VSEL1_MASK               (0x3F00U)
#define PMC_LDOVDD1VSEL_VSEL1_SHIFT              (8U)
/*! VSEL1 - LDO VDD1 Voltage Level 1
 *  0b000000..0.45 V
 *  0b010000..0.65 V
 *  0b100000..0.85 V
 *  0b110000..1.05 V
 *  0b111000..1.15 V (maximum)
 *  0b111111..1.15 V (clipped)
 */
#define PMC_LDOVDD1VSEL_VSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_LDOVDD1VSEL_VSEL1_SHIFT)) & PMC_LDOVDD1VSEL_VSEL1_MASK)

#define PMC_LDOVDD1VSEL_VSEL2_MASK               (0x3F0000U)
#define PMC_LDOVDD1VSEL_VSEL2_SHIFT              (16U)
/*! VSEL2 - LDO VDD1 Voltage Level 2
 *  0b000000..0.45 V
 *  0b010000..0.65 V
 *  0b100000..0.85 V
 *  0b110000..1.05 V
 *  0b111000..1.15 V (maximum)
 *  0b111111..1.15 V (clipped)
 */
#define PMC_LDOVDD1VSEL_VSEL2(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_LDOVDD1VSEL_VSEL2_SHIFT)) & PMC_LDOVDD1VSEL_VSEL2_MASK)

#define PMC_LDOVDD1VSEL_VSEL3_MASK               (0x3F000000U)
#define PMC_LDOVDD1VSEL_VSEL3_SHIFT              (24U)
/*! VSEL3 - LDO VDD1 Voltage Level 3
 *  0b000000..0.45 V
 *  0b010000..0.65 V
 *  0b100000..0.85 V
 *  0b110000..1.05 V
 *  0b111000..1.15 V (maximum)
 *  0b111111..1.15 V (clipped)
 */
#define PMC_LDOVDD1VSEL_VSEL3(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_LDOVDD1VSEL_VSEL3_SHIFT)) & PMC_LDOVDD1VSEL_VSEL3_MASK)
/*! @} */

/*! @name LVDVDDNCTRL - VDDN LVD Control */
/*! @{ */

#define PMC_LVDVDDNCTRL_LVL0_MASK                (0x3FU)
#define PMC_LVDVDDNCTRL_LVL0_SHIFT               (0U)
/*! LVL0 - LVD Level 0 Voltage
 *  0b000000..0.50 V
 *  0b010000..0.66 V
 *  0b100000..0.82 V
 *  0b110000..0.98 V
 *  0b111111..1.13 V
 */
#define PMC_LVDVDDNCTRL_LVL0(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_LVDVDDNCTRL_LVL0_SHIFT)) & PMC_LVDVDDNCTRL_LVL0_MASK)

#define PMC_LVDVDDNCTRL_LVL1_MASK                (0x3F00U)
#define PMC_LVDVDDNCTRL_LVL1_SHIFT               (8U)
/*! LVL1 - LVD Level 1 Voltage
 *  0b000000..0.50 V
 *  0b010000..0.66 V
 *  0b100000..0.82 V
 *  0b110000..0.98 V
 *  0b111111..1.13 V
 */
#define PMC_LVDVDDNCTRL_LVL1(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_LVDVDDNCTRL_LVL1_SHIFT)) & PMC_LVDVDDNCTRL_LVL1_MASK)
/*! @} */

/*! @name LVDVDD2CTRL - VDD2 LVD Control */
/*! @{ */

#define PMC_LVDVDD2CTRL_LVL0_MASK                (0x3FU)
#define PMC_LVDVDD2CTRL_LVL0_SHIFT               (0U)
/*! LVL0 - LVD Level 0 Voltage
 *  0b000000..0.50 V
 *  0b010000..0.66 V
 *  0b100000..0.82 V
 *  0b110000..0.98 V
 *  0b111111..1.13 V
 */
#define PMC_LVDVDD2CTRL_LVL0(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_LVDVDD2CTRL_LVL0_SHIFT)) & PMC_LVDVDD2CTRL_LVL0_MASK)

#define PMC_LVDVDD2CTRL_LVL1_MASK                (0x3F00U)
#define PMC_LVDVDD2CTRL_LVL1_SHIFT               (8U)
/*! LVL1 - LVD Level 1 Voltage
 *  0b000000..0.50 V
 *  0b010000..0.66 V
 *  0b100000..0.82 V
 *  0b110000..0.98 V
 *  0b111111..1.13 V
 */
#define PMC_LVDVDD2CTRL_LVL1(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_LVDVDD2CTRL_LVL1_SHIFT)) & PMC_LVDVDD2CTRL_LVL1_MASK)

#define PMC_LVDVDD2CTRL_LVL2_MASK                (0x3F0000U)
#define PMC_LVDVDD2CTRL_LVL2_SHIFT               (16U)
/*! LVL2 - LVD Level 2 Voltage
 *  0b000000..0.50 V
 *  0b010000..0.66 V
 *  0b100000..0.82 V
 *  0b110000..0.98 V
 *  0b111111..1.13 V
 */
#define PMC_LVDVDD2CTRL_LVL2(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_LVDVDD2CTRL_LVL2_SHIFT)) & PMC_LVDVDD2CTRL_LVL2_MASK)

#define PMC_LVDVDD2CTRL_LVL3_MASK                (0x3F000000U)
#define PMC_LVDVDD2CTRL_LVL3_SHIFT               (24U)
/*! LVL3 - LVD Level 3 Voltage
 *  0b000000..0.50 V
 *  0b010000..0.66 V
 *  0b100000..0.82 V
 *  0b110000..0.98 V
 *  0b111111..1.13 V
 */
#define PMC_LVDVDD2CTRL_LVL3(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_LVDVDD2CTRL_LVL3_SHIFT)) & PMC_LVDVDD2CTRL_LVL3_MASK)
/*! @} */

/*! @name LVDVDD1CTRL - VDD1 LVD Control */
/*! @{ */

#define PMC_LVDVDD1CTRL_LVL0_MASK                (0x3FU)
#define PMC_LVDVDD1CTRL_LVL0_SHIFT               (0U)
/*! LVL0 - Level 0 Voltage
 *  0b000000..0.50 V
 *  0b010000..0.66 V
 *  0b100000..0.82 V
 *  0b110000..0.98 V
 *  0b111111..1.13 V
 */
#define PMC_LVDVDD1CTRL_LVL0(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_LVDVDD1CTRL_LVL0_SHIFT)) & PMC_LVDVDD1CTRL_LVL0_MASK)

#define PMC_LVDVDD1CTRL_LVL1_MASK                (0x3F00U)
#define PMC_LVDVDD1CTRL_LVL1_SHIFT               (8U)
/*! LVL1 - Level 1 Voltage */
#define PMC_LVDVDD1CTRL_LVL1(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_LVDVDD1CTRL_LVL1_SHIFT)) & PMC_LVDVDD1CTRL_LVL1_MASK)

#define PMC_LVDVDD1CTRL_LVL2_MASK                (0x3F0000U)
#define PMC_LVDVDD1CTRL_LVL2_SHIFT               (16U)
/*! LVL2 - Level 2 Voltage
 *  0b000000..0.50 V
 *  0b010000..0.66 V
 *  0b100000..0.82 V
 *  0b110000..0.98 V
 *  0b111111..1.13 V
 */
#define PMC_LVDVDD1CTRL_LVL2(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_LVDVDD1CTRL_LVL2_SHIFT)) & PMC_LVDVDD1CTRL_LVL2_MASK)

#define PMC_LVDVDD1CTRL_LVL3_MASK                (0x3F000000U)
#define PMC_LVDVDD1CTRL_LVL3_SHIFT               (24U)
/*! LVL3 - Level 3 Voltage
 *  0b000000..0.50 V
 *  0b010000..0.66 V
 *  0b100000..0.82 V
 *  0b110000..0.98 V
 *  0b111111..1.13 V
 */
#define PMC_LVDVDD1CTRL_LVL3(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_LVDVDD1CTRL_LVL3_SHIFT)) & PMC_LVDVDD1CTRL_LVL3_MASK)
/*! @} */

/*! @name PORCTRL - Power-on Reset Control */
/*! @{ */

#define PMC_PORCTRL_VDD1LVL_MASK                 (0x1FU)
#define PMC_PORCTRL_VDD1LVL_SHIFT                (0U)
/*! VDD1LVL - POR Level in VDD1 Domain
 *  0b00000..0.40 V
 *  0b01000..0.48 V
 *  0b10000..0.56 V
 *  0b11000..0.64 V
 *  0b11111..0.72 V
 */
#define PMC_PORCTRL_VDD1LVL(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PORCTRL_VDD1LVL_SHIFT)) & PMC_PORCTRL_VDD1LVL_MASK)

#define PMC_PORCTRL_VDD2LVL_MASK                 (0x1F00U)
#define PMC_PORCTRL_VDD2LVL_SHIFT                (8U)
/*! VDD2LVL - POR Level in VDD2 Domain
 *  0b00000..0.40 V
 *  0b01000..0.48 V
 *  0b10000..0.56 V
 *  0b11000..0.64 V
 *  0b11111..0.72 V
 */
#define PMC_PORCTRL_VDD2LVL(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PORCTRL_VDD2LVL_SHIFT)) & PMC_PORCTRL_VDD2LVL_MASK)

#define PMC_PORCTRL_VDDNLVL_MASK                 (0x1F0000U)
#define PMC_PORCTRL_VDDNLVL_SHIFT                (16U)
/*! VDDNLVL - POR Level in VDDN Domain
 *  0b00000..0.40 V
 *  0b01000..0.48 V
 *  0b10000..0.56 V
 *  0b11000..0.64 V
 *  0b11111..0.72 V
 */
#define PMC_PORCTRL_VDDNLVL(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PORCTRL_VDDNLVL_SHIFT)) & PMC_PORCTRL_VDDNLVL_MASK)
/*! @} */

/*! @name BBCTRL - Body Bias Control */
/*! @{ */

#define PMC_BBCTRL_RBB1LVL_MASK                  (0x1U)
#define PMC_BBCTRL_RBB1LVL_SHIFT                 (0U)
/*! RBB1LVL - Reverse Body Bias Voltage for VDD1 Domain
 *  0b0..Voltage is set to 1.0 V
 *  0b1..Voltage is set to 1.3 V
 */
#define PMC_BBCTRL_RBB1LVL(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_BBCTRL_RBB1LVL_SHIFT)) & PMC_BBCTRL_RBB1LVL_MASK)

#define PMC_BBCTRL_RBB2LVL_MASK                  (0x100U)
#define PMC_BBCTRL_RBB2LVL_SHIFT                 (8U)
/*! RBB2LVL - Reverse Body Bias Voltage for VDD2 Domain
 *  0b0..Voltage is set to 1.0 V
 *  0b1..Voltage is set to 1.3 V
 */
#define PMC_BBCTRL_RBB2LVL(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_BBCTRL_RBB2LVL_SHIFT)) & PMC_BBCTRL_RBB2LVL_MASK)

#define PMC_BBCTRL_RBBNLVL_MASK                  (0x10000U)
#define PMC_BBCTRL_RBBNLVL_SHIFT                 (16U)
/*! RBBNLVL - Reverse Body Bias Voltage for VDDN Domain
 *  0b0..Voltage is set to 1.0 V
 *  0b1..Voltage is set to 1.3 V
 */
#define PMC_BBCTRL_RBBNLVL(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_BBCTRL_RBBNLVL_SHIFT)) & PMC_BBCTRL_RBBNLVL_MASK)
/*! @} */

/*! @name TSENSOR - Temperature Sensor Control */
/*! @{ */

#define PMC_TSENSOR_TSENSM_MASK                  (0xFU)
#define PMC_TSENSOR_TSENSM_SHIFT                 (0U)
/*! TSENSM - Temperature Sensor Mode Select
 *  0b0000..Perform AD conversion and record C*_000
 *  0b0001..Perform AD conversion and record C*_001
 *  0b0010..Perform AD conversion and record C*_010
 *  0b0011..Perform AD conversion and record C*_011
 *  0b0100..Perform AD conversion and record CM_100
 *  0b0101..Perform AD conversion and record C*_101
 *  0b0110..Perform AD conversion and record C*_110
 *  0b0111..Perform AD conversion and record C*_111
 */
#define PMC_TSENSOR_TSENSM(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_TSENSOR_TSENSM_SHIFT)) & PMC_TSENSOR_TSENSM_MASK)
/*! @} */

/*! @name WAKEUP - Wake-up Configuration for Compute Domain */
/*! @{ */

#define PMC_WAKEUP_WAKETIME_MASK                 (0xFFFFU)
#define PMC_WAKEUP_WAKETIME_SHIFT                (0U)
/*! WAKETIME - Wake-up Timer */
#define PMC_WAKEUP_WAKETIME(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUP_WAKETIME_SHIFT)) & PMC_WAKEUP_WAKETIME_MASK)

#define PMC_WAKEUP_WKSRCEN_MASK                  (0x3F0000U)
#define PMC_WAKEUP_WKSRCEN_SHIFT                 (16U)
/*! WKSRCEN - Wake-up Source Enable
 *  0b000000..Wake-up disabled
 *  0b000001..Wake-up enabled
 */
#define PMC_WAKEUP_WKSRCEN(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUP_WKSRCEN_SHIFT)) & PMC_WAKEUP_WKSRCEN_MASK)

#define PMC_WAKEUP_WKSRCF_MASK                   (0x3F000000U)
#define PMC_WAKEUP_WKSRCF_SHIFT                  (24U)
/*! WKSRCF - Wake-up Source Flags
 *  0b000000..No wake-up from source
 *  0b000001..Source has triggered a wake-up
 */
#define PMC_WAKEUP_WKSRCF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_WAKEUP_WKSRCF_SHIFT)) & PMC_WAKEUP_WKSRCF_MASK)
/*! @} */

/*! @name POWERCFG - Power Configuration */
/*! @{ */

#define PMC_POWERCFG_FDSCP1PD_MASK               (0x1U)
#define PMC_POWERCFG_FDSCP1PD_SHIFT              (0U)
/*! FDSCP1PD - SCPC VDD1 Power Down in FDSR Mode
 *  0b0..Not powered down
 *  0b1..Powered down
 */
#define PMC_POWERCFG_FDSCP1PD(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_POWERCFG_FDSCP1PD_SHIFT)) & PMC_POWERCFG_FDSCP1PD_MASK)

#define PMC_POWERCFG_FDSCP2PD_MASK               (0x2U)
#define PMC_POWERCFG_FDSCP2PD_SHIFT              (1U)
/*! FDSCP2PD - SCPC VDD2 Power Down in FDSR Mode
 *  0b0..Not powered down
 *  0b1..Powered down
 */
#define PMC_POWERCFG_FDSCP2PD(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_POWERCFG_FDSCP2PD_SHIFT)) & PMC_POWERCFG_FDSCP2PD_MASK)

#define PMC_POWERCFG_FDLDO1PD_MASK               (0x10U)
#define PMC_POWERCFG_FDLDO1PD_SHIFT              (4U)
/*! FDLDO1PD - LDO VDD1 Power Down in FDSR Mode
 *  0b0..Not powered down
 *  0b1..Powered down
 */
#define PMC_POWERCFG_FDLDO1PD(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_POWERCFG_FDLDO1PD_SHIFT)) & PMC_POWERCFG_FDLDO1PD_MASK)

#define PMC_POWERCFG_FDLDO2PD_MASK               (0x20U)
#define PMC_POWERCFG_FDLDO2PD_SHIFT              (5U)
/*! FDLDO2PD - LDO VDD2 Power Down in FDSR Mode
 *  0b0..Not powered down
 *  0b1..Powered down
 */
#define PMC_POWERCFG_FDLDO2PD(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_POWERCFG_FDLDO2PD_SHIFT)) & PMC_POWERCFG_FDLDO2PD_MASK)

#define PMC_POWERCFG_FDDCPD_MASK                 (0x40U)
#define PMC_POWERCFG_FDDCPD_SHIFT                (6U)
/*! FDDCPD - DCDC Power Down in FDSR Mode
 *  0b0..Not powered down
 *  0b1..Powered down
 */
#define PMC_POWERCFG_FDDCPD(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_POWERCFG_FDDCPD_SHIFT)) & PMC_POWERCFG_FDDCPD_MASK)

#define PMC_POWERCFG_SCPCPD_MASK                 (0x80U)
#define PMC_POWERCFG_SCPCPD_SHIFT                (7U)
/*! SCPCPD - SCPC Power Down
 *  0b0..Not powered down in FDSR mode, except in FDSR mode when [FDSCPnPD] = 1
 *  0b1..Powered down (until the next cold reset)
 */
#define PMC_POWERCFG_SCPCPD(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_POWERCFG_SCPCPD_SHIFT)) & PMC_POWERCFG_SCPCPD_MASK)

#define PMC_POWERCFG_LDO1PD_MASK                 (0x100U)
#define PMC_POWERCFG_LDO1PD_SHIFT                (8U)
/*! LDO1PD - LDO VDD1 Power Down
 *  0b0..Not powered down, except in FDSR mode when [FDLDO1PD] = 1, or in DPD or FDPD mode
 *  0b1..Powered down (until the next cold reset)
 */
#define PMC_POWERCFG_LDO1PD(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_POWERCFG_LDO1PD_SHIFT)) & PMC_POWERCFG_LDO1PD_MASK)

#define PMC_POWERCFG_LDO2PD_MASK                 (0x200U)
#define PMC_POWERCFG_LDO2PD_SHIFT                (9U)
/*! LDO2PD - LDO VDD2 Power Down
 *  0b0..Not powered down, except in FDSR mode when [FDLDO2PD] = 1, or in DPD or FDPD mode
 *  0b1..Powered down (until the next cold reset)
 */
#define PMC_POWERCFG_LDO2PD(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_POWERCFG_LDO2PD_SHIFT)) & PMC_POWERCFG_LDO2PD_MASK)

#define PMC_POWERCFG_DCDCPD_MASK                 (0x1000U)
#define PMC_POWERCFG_DCDCPD_SHIFT                (12U)
/*! DCDCPD - DCDC Power Down
 *  0b0..Not powered down, except in FDSR mode when [FDDCPD] = 1, or in DPD or FDPD mode
 *  0b1..Powered down (until the next cold reset)
 */
#define PMC_POWERCFG_DCDCPD(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_POWERCFG_DCDCPD_SHIFT)) & PMC_POWERCFG_DCDCPD_MASK)

#define PMC_POWERCFG_FDPDBGLP_MASK               (0x1000000U)
#define PMC_POWERCFG_FDPDBGLP_SHIFT              (24U)
/*! FDPDBGLP - Force Band Gap during FDPD Mode to LP Mode
 *  0b0..Enables band gap to high-power mode during FDPD mode and wakes up if VDD1V8 POR is asserted then negated
 *  0b1..Enables band gap to low-power mode during FDPD mode and will not wake up on VDD1V8 POR negation. RTC, PMIC_IRQN, or reset is used as wake-up
 */
#define PMC_POWERCFG_FDPDBGLP(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_POWERCFG_FDPDBGLP_SHIFT)) & PMC_POWERCFG_FDPDBGLP_MASK)

#define PMC_POWERCFG_MODEDLY_MASK                (0xF0000000U)
#define PMC_POWERCFG_MODEDLY_SHIFT               (28U)
/*! MODEDLY - Mode Delay
 *  0b0000..250 ns
 *  0b0001..500 ns
 *  0b0010..1000 ns
 *  0b0011..2000 ns
 *  0b0100..4000 ns
 *  0b0101..8000 ns
 *  0b0110..16 us
 *  0b0111..32 us
 *  0b1000..64 us
 *  0b1001..128 us
 *  0b1010..256 us
 *  0b1011..512 us
 *  0b1100..1024 us
 *  0b1101..2048 us
 *  0b1110..4096 us
 *  0b1111..8192 us
 */
#define PMC_POWERCFG_MODEDLY(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_POWERCFG_MODEDLY_SHIFT)) & PMC_POWERCFG_MODEDLY_MASK)
/*! @} */

/*! @name PADVRANGE - 3 V Capable VDDIO Range Select */
/*! @{ */

#define PMC_PADVRANGE_VRANGE_MASK                (0x3U)
#define PMC_PADVRANGE_VRANGE_SHIFT               (0U)
/*! VRANGE - 3 V Capable IO Bank VDDIO Range Select
 *  0b00..Continuous mode. Allows 1.71 - 3.6 V range but consumes static current.
 *  0b01..1.71 - 1.98 V, supply detector off
 *  0b10..3.00 - 3.6 V, supply detector off
 *  0b11..Reserved
 */
#define PMC_PADVRANGE_VRANGE(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PADVRANGE_VRANGE_SHIFT)) & PMC_PADVRANGE_VRANGE_MASK)
/*! @} */

/*! @name PADCFG - IO Bank State Configuration */
/*! @{ */

#define PMC_PADCFG_ISOCTRL_MASK                  (0xFFU)
#define PMC_PADCFG_ISOCTRL_SHIFT                 (0U)
/*! ISOCTRL - IO bank State Retain Control
 *  0b00000000..IO bank is controllable
 *  0b1xxxxxxx..PMIC_I2C is in retain mode
 *  0bx1xxxxxx..Port 8/9/10 is in retain mode
 *  0bxx1xxxxx..Port 7 is in retain mode
 *  0bxxx1xxxx..Port 6 is in retain mode
 *  0bxxxx1xxx..Port 5 is in retain mode
 *  0bxxxxx1xx..Port 4 is in retain mode
 *  0bxxxxxx1x..Port 2 is in retain mode
 *  0bxxxxxxx1..Port 0/1/3 is in retain mode
 */
#define PMC_PADCFG_ISOCTRL(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_PADCFG_ISOCTRL_SHIFT)) & PMC_PADCFG_ISOCTRL_MASK)

#define PMC_PADCFG_ISOHOLD_MASK                  (0xFF00U)
#define PMC_PADCFG_ISOHOLD_SHIFT                 (8U)
/*! ISOHOLD - IO Bank Isolation Hold
 *  0b00000000..IO bank is controllable on wake-up from FDSR/DPD mode
 *  0b1xxxxxxx..PMIC_I2C is retained/isolated on wake-up from FDSR/DPD mode. Software must clear [ISOCTRL] bit 7 to regain control
 *  0bx1xxxxxx..Port 8/9/10 is retained/isolated on wake-up from FDSR/DPD mode. Software must clear [ISOCTRL] bit 6 to regain control
 *  0bxx1xxxxx..Port 7 is retained/isolated on wake-up from FDSR/DPD mode. Software must clear [ISOCTRL] bit 5 to regain control
 *  0bxxx1xxxx..Port 6 is retained/isolated on wake-up from FDSR/DPD mode. Software must clear [ISOCTRL] bit 4 to regain control
 *  0bxxxx1xxx..Port 5 is retained/isolated on wake-up from FDSR/DPD mode. Software must clear [ISOCTRL] bit 3 to regain control
 *  0bxxxxx1xx..Port 4 is retained/isolated on wake-up from FDSR/DPD mode. Software must clear [ISOCTRL] bit 2 to regain control
 *  0bxxxxxx1x..Port 2 is retained/isolated on wake-up from FDSR/DPD mode. Software must clear [ISOCTRL] bit 1 to regain control
 *  0bxxxxxxx1..Port 0/1/3 is retained/isolated on wake-up from FDSR/DPD mode. Software must clear [ISOCTRL] bit 0 to regain control
 */
#define PMC_PADCFG_ISOHOLD(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_PADCFG_ISOHOLD_SHIFT)) & PMC_PADCFG_ISOHOLD_MASK)

#define PMC_PADCFG_RSTCTRL_MASK                  (0xFF0000U)
#define PMC_PADCFG_RSTCTRL_SHIFT                 (16U)
/*! RSTCTRL - Reset Control
 *  0b00000000..IO banks are not reset
 *  0b1xxxxxxx..PMIC_I2C reset = tristate
 *  0bx1xxxxxx..Port 8/9/10 reset = tristate
 *  0bxx1xxxxx..Port 7 reset = tristate
 *  0bxxx1xxxx..Port 6 reset = tristate
 *  0bxxxx1xxx..Port 5 reset = tristate
 *  0bxxxxx1xx..Port 4 reset = tristate
 *  0bxxxxxx1x..Port 2 reset = tristate
 *  0bxxxxxxx1..Port 0/1/3 reset = tristate
 */
#define PMC_PADCFG_RSTCTRL(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_PADCFG_RSTCTRL_SHIFT)) & PMC_PADCFG_RSTCTRL_MASK)
/*! @} */

/*! @name PDRUNCFG0 - PD Run Configuration 0 in Compute Domain */
/*! @{ */

#define PMC_PDRUNCFG0_PMICMODE_MASK              (0x3U)
#define PMC_PDRUNCFG0_PMICMODE_SHIFT             (0U)
/*! PMICMODE - PMIC Power Mode Select
 *  0b00..Drives PMIC_MODE pins to 0h
 *  0b01..Drives PMIC_MODE pins to 1h
 *  0b10..Drives PMIC_MODE pins to 2h
 *  0b11..Drives PMIC_MODE pins to 3h
 */
#define PMC_PDRUNCFG0_PMICMODE(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_PMICMODE_SHIFT)) & PMC_PDRUNCFG0_PMICMODE_MASK)

#define PMC_PDRUNCFG0_FDSR_MASK                  (0x4U)
#define PMC_PDRUNCFG0_FDSR_SHIFT                 (2U)
/*! FDSR - Full Deep Sleep Retention (FDSR) Mode
 *  0b0..All power switch states controlled by their respective PD*CFG bits
 *  0b1..All core domains in DSR or Power Down mode
 */
#define PMC_PDRUNCFG0_FDSR(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_FDSR_SHIFT)) & PMC_PDRUNCFG0_FDSR_MASK)

#define PMC_PDRUNCFG0_DPD_MASK                   (0x8U)
#define PMC_PDRUNCFG0_DPD_SHIFT                  (3U)
/*! DPD - Deep Power Down (DPD) Mode
 *  0b0..Disables
 *  0b1..Enables DPD mode
 */
#define PMC_PDRUNCFG0_DPD(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_DPD_SHIFT)) & PMC_PDRUNCFG0_DPD_MASK)

#define PMC_PDRUNCFG0_FDPD_MASK                  (0x10U)
#define PMC_PDRUNCFG0_FDPD_SHIFT                 (4U)
/*! FDPD - Full Deep Power Down (FDPD) Mode
 *  0b0..Disables
 *  0b1..Enables FDPD mode
 */
#define PMC_PDRUNCFG0_FDPD(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_FDPD_SHIFT)) & PMC_PDRUNCFG0_FDPD_MASK)

#define PMC_PDRUNCFG0_V2COMP_DSR_MASK            (0x20U)
#define PMC_PDRUNCFG0_V2COMP_DSR_SHIFT           (5U)
/*! V2COMP_DSR - Power Switch and DSR Enable in VDD2_COMP Domain
 *  0b0..Powers on VDD2_COMP
 *  0b1..Enables DSR mode in VDD2_COMP
 */
#define PMC_PDRUNCFG0_V2COMP_DSR(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_V2COMP_DSR_SHIFT)) & PMC_PDRUNCFG0_V2COMP_DSR_MASK)

#define PMC_PDRUNCFG0_V2NMED_DSR_MASK            (0x40U)
#define PMC_PDRUNCFG0_V2NMED_DSR_SHIFT           (6U)
/*! V2NMED_DSR - Power Switch and DSR for VDD2 and VDDN Media
 *  0b0..Powers on VDD2 and VDDN media domains
 *  0b1..Enables VDD2 and VDDN media domains in DSR mode
 */
#define PMC_PDRUNCFG0_V2NMED_DSR(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_V2NMED_DSR_SHIFT)) & PMC_PDRUNCFG0_V2NMED_DSR_MASK)

#define PMC_PDRUNCFG0_V2COM_DSR_MASK             (0x80U)
#define PMC_PDRUNCFG0_V2COM_DSR_SHIFT            (7U)
/*! V2COM_DSR - Power Switch and DSR Enable for VDD2_COM
 *  0b0..Powers on VDD2_COM
 *  0b1..Enables DSR mode in VDD2_COM
 */
#define PMC_PDRUNCFG0_V2COM_DSR(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_V2COM_DSR_SHIFT)) & PMC_PDRUNCFG0_V2COM_DSR_MASK)

#define PMC_PDRUNCFG0_VNCOM_DSR_MASK             (0x100U)
#define PMC_PDRUNCFG0_VNCOM_DSR_SHIFT            (8U)
/*! VNCOM_DSR - Power Switch and DSR for VDDN_COM
 *  0b0..Powers on VDDN_COM domain
 *  0b1..Enables VDDN_COM domain in DSR mode
 */
#define PMC_PDRUNCFG0_VNCOM_DSR(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_VNCOM_DSR_SHIFT)) & PMC_PDRUNCFG0_VNCOM_DSR_MASK)

#define PMC_PDRUNCFG0_V2DSP_PD_MASK              (0x200U)
#define PMC_PDRUNCFG0_V2DSP_PD_SHIFT             (9U)
/*! V2DSP_PD - Power Down VDD2_DSP
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG0_V2DSP_PD(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_V2DSP_PD_SHIFT)) & PMC_PDRUNCFG0_V2DSP_PD_MASK)

#define PMC_PDRUNCFG0_V2MIPI_PD_MASK             (0x400U)
#define PMC_PDRUNCFG0_V2MIPI_PD_SHIFT            (10U)
/*! V2MIPI_PD - Power Down MIPI PHY in VDD2 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG0_V2MIPI_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_V2MIPI_PD_SHIFT)) & PMC_PDRUNCFG0_V2MIPI_PD_MASK)

#define PMC_PDRUNCFG0_DCDC_LP_MASK               (0x1000U)
#define PMC_PDRUNCFG0_DCDC_LP_SHIFT              (12U)
/*! DCDC_LP - DCDC Low-Power Mode
 *  0b0..Enables DCDC in high-power mode
 *  0b1..Enables DCDC in low-power mode
 */
#define PMC_PDRUNCFG0_DCDC_LP(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_DCDC_LP_SHIFT)) & PMC_PDRUNCFG0_DCDC_LP_MASK)

#define PMC_PDRUNCFG0_DCDC_VSEL_MASK             (0x2000U)
#define PMC_PDRUNCFG0_DCDC_VSEL_SHIFT            (13U)
/*! DCDC_VSEL - Select DCDC Voltage
 *  0b0..Selects DCDCVSEL[VSEL0] level
 *  0b1..Selects DCDCVSEL[VSEL1] level
 */
#define PMC_PDRUNCFG0_DCDC_VSEL(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_DCDC_VSEL_SHIFT)) & PMC_PDRUNCFG0_DCDC_VSEL_MASK)

#define PMC_PDRUNCFG0_LDO1_MODE_MASK             (0xC000U)
#define PMC_PDRUNCFG0_LDO1_MODE_SHIFT            (14U)
/*! LDO1_MODE - LDO VDD1 Mode
 *  0b00..Bypass mode
 *  0b01..High-power mode
 *  0b10, 0b11..Low-power mode
 */
#define PMC_PDRUNCFG0_LDO1_MODE(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_LDO1_MODE_SHIFT)) & PMC_PDRUNCFG0_LDO1_MODE_MASK)

#define PMC_PDRUNCFG0_LDO1_VSEL_MASK             (0x30000U)
#define PMC_PDRUNCFG0_LDO1_VSEL_SHIFT            (16U)
/*! LDO1_VSEL - LDO VDD1 Voltage Select
 *  0b00..Selects LDOVDD1VSEL[VSEL0] and LVDVDD1CTRL[LVL0] level
 *  0b01..Selects LDOVDD1VSEL[VSEL1] and LVDVDD1CTRL[LVL1] level
 *  0b10..Selects LDOVDD1VSEL[VSEL2] and LVDVDD1CTRL[LVL2] level
 *  0b11..Selects LDOVDD1VSEL[VSEL3] and LVDVDD1CTRL[LVL3] level
 */
#define PMC_PDRUNCFG0_LDO1_VSEL(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_LDO1_VSEL_SHIFT)) & PMC_PDRUNCFG0_LDO1_VSEL_MASK)

#define PMC_PDRUNCFG0_LDO2_MODE_MASK             (0xC0000U)
#define PMC_PDRUNCFG0_LDO2_MODE_SHIFT            (18U)
/*! LDO2_MODE - LDO VDD2 Mode
 *  0b00..Bypass mode
 *  0b01..High-power mode
 *  0b10, 0b11..Low-power mode
 */
#define PMC_PDRUNCFG0_LDO2_MODE(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_LDO2_MODE_SHIFT)) & PMC_PDRUNCFG0_LDO2_MODE_MASK)

#define PMC_PDRUNCFG0_LDO2_VSEL_MASK             (0x300000U)
#define PMC_PDRUNCFG0_LDO2_VSEL_SHIFT            (20U)
/*! LDO2_VSEL - Select LDO VDD2 Voltage
 *  0b00..Selects LDOVDD2VSEL[VSEL0] and LVDVDD2CTRL[LVL0] level
 *  0b01..Selects LDOVDD2VSEL[VSEL1] and LVDVDD2CTRL[LVL1] level
 *  0b10..Selects LDOVDD2VSEL[VSEL2] and LVDVDD2CTRL[LVL2] level
 *  0b11..Selects LDOVDD2VSEL[VSEL3] and LVDVDD2CTRL[LVL3] level
 */
#define PMC_PDRUNCFG0_LDO2_VSEL(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_LDO2_VSEL_SHIFT)) & PMC_PDRUNCFG0_LDO2_VSEL_MASK)

#define PMC_PDRUNCFG0_RBB1_PD_MASK               (0x400000U)
#define PMC_PDRUNCFG0_RBB1_PD_SHIFT              (22U)
/*! RBB1_PD - Power Down RBB in VDD1
 *  0b0..If PDRUNCFG0[AFBB1_PD] = 1, power on. Else power down
 *  0b1..Power down
 */
#define PMC_PDRUNCFG0_RBB1_PD(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_RBB1_PD_SHIFT)) & PMC_PDRUNCFG0_RBB1_PD_MASK)

#define PMC_PDRUNCFG0_AFBB1_PD_MASK              (0x800000U)
#define PMC_PDRUNCFG0_AFBB1_PD_SHIFT             (23U)
/*! AFBB1_PD - Power Down AFBB in VDD1 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG0_AFBB1_PD(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_AFBB1_PD_SHIFT)) & PMC_PDRUNCFG0_AFBB1_PD_MASK)

#define PMC_PDRUNCFG0_RBB2_PD_MASK               (0x1000000U)
#define PMC_PDRUNCFG0_RBB2_PD_SHIFT              (24U)
/*! RBB2_PD - Power Down RBB in VDD2 Domain
 *  0b0..If PDRUNCFG0[AFBB2_PD] = 1, power on. Else power down
 *  0b1..Power down
 */
#define PMC_PDRUNCFG0_RBB2_PD(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_RBB2_PD_SHIFT)) & PMC_PDRUNCFG0_RBB2_PD_MASK)

#define PMC_PDRUNCFG0_AFBB2_PD_MASK              (0x2000000U)
#define PMC_PDRUNCFG0_AFBB2_PD_SHIFT             (25U)
/*! AFBB2_PD - Power Down AFBB in VDD2 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG0_AFBB2_PD(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_AFBB2_PD_SHIFT)) & PMC_PDRUNCFG0_AFBB2_PD_MASK)

#define PMC_PDRUNCFG0_RBBN_PD_MASK               (0x4000000U)
#define PMC_PDRUNCFG0_RBBN_PD_SHIFT              (26U)
/*! RBBN_PD - Power Down RBB in VDDN Domain
 *  0b0..If PDRUNCFG0[AFBBN_PD] = 1, power on. Else power down
 *  0b1..Power down
 */
#define PMC_PDRUNCFG0_RBBN_PD(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_RBBN_PD_SHIFT)) & PMC_PDRUNCFG0_RBBN_PD_MASK)

#define PMC_PDRUNCFG0_AFBBN_PD_MASK              (0x8000000U)
#define PMC_PDRUNCFG0_AFBBN_PD_SHIFT             (27U)
/*! AFBBN_PD - Power Down AFBB in VDDN Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG0_AFBBN_PD(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_AFBBN_PD_SHIFT)) & PMC_PDRUNCFG0_AFBBN_PD_MASK)

#define PMC_PDRUNCFG0_RBBSR1_PD_MASK             (0x10000000U)
#define PMC_PDRUNCFG0_RBBSR1_PD_SHIFT            (28U)
/*! RBBSR1_PD - Power Down SRAM RBB in VDD1 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG0_RBBSR1_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_RBBSR1_PD_SHIFT)) & PMC_PDRUNCFG0_RBBSR1_PD_MASK)

#define PMC_PDRUNCFG0_RBBSR2_PD_MASK             (0x20000000U)
#define PMC_PDRUNCFG0_RBBSR2_PD_SHIFT            (29U)
/*! RBBSR2_PD - Power Down SRAM RBB in VDD2 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG0_RBBSR2_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG0_RBBSR2_PD_SHIFT)) & PMC_PDRUNCFG0_RBBSR2_PD_MASK)
/*! @} */

/*! @name PDRUNCFG1 - PD Run Configuration 1 in Compute Domain */
/*! @{ */

#define PMC_PDRUNCFG1_TEMP_PD_MASK               (0x1U)
#define PMC_PDRUNCFG1_TEMP_PD_SHIFT              (0U)
/*! TEMP_PD - Power Down PMC Temperature Sensor
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG1_TEMP_PD(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_TEMP_PD_SHIFT)) & PMC_PDRUNCFG1_TEMP_PD_MASK)

#define PMC_PDRUNCFG1_PMCREF_LP_MASK             (0x2U)
#define PMC_PDRUNCFG1_PMCREF_LP_SHIFT            (1U)
/*! PMCREF_LP - PMC References in Low-Power Mode
 *  0b0..Sets PMC references in high-power mode
 *  0b1..Sets PMC references in low-power mode if not overridden by any *_PD bits
 */
#define PMC_PDRUNCFG1_PMCREF_LP(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_PMCREF_LP_SHIFT)) & PMC_PDRUNCFG1_PMCREF_LP_MASK)

#define PMC_PDRUNCFG1_HVD1V8_PD_MASK             (0x4U)
#define PMC_PDRUNCFG1_HVD1V8_PD_SHIFT            (2U)
/*! HVD1V8_PD - HVD Power Down
 *  0b0..Power on. In this case, PMC references will be in high-power mode
 *  0b1..Power down
 */
#define PMC_PDRUNCFG1_HVD1V8_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_HVD1V8_PD_SHIFT)) & PMC_PDRUNCFG1_HVD1V8_PD_MASK)

#define PMC_PDRUNCFG1_POR1_LP_MASK               (0x8U)
#define PMC_PDRUNCFG1_POR1_LP_SHIFT              (3U)
/*! POR1_LP - POR Low-Power Mode in VDD1 Domain
 *  0b0..Sets POR in high-power mode. In this case, PMC references will be in high-power mode
 *  0b1..Sets POR in low-power mode
 */
#define PMC_PDRUNCFG1_POR1_LP(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_POR1_LP_SHIFT)) & PMC_PDRUNCFG1_POR1_LP_MASK)

#define PMC_PDRUNCFG1_LVD1_LP_MASK               (0x10U)
#define PMC_PDRUNCFG1_LVD1_LP_SHIFT              (4U)
/*! LVD1_LP - LVD Low-Power Mode in VDD1 Domain
 *  0b0..Sets LVD in high-power mode. In this case, PMC references will be in high-power mode
 *  0b1..Sets LVD in low-power mode
 */
#define PMC_PDRUNCFG1_LVD1_LP(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_LVD1_LP_SHIFT)) & PMC_PDRUNCFG1_LVD1_LP_MASK)

#define PMC_PDRUNCFG1_HVD1_PD_MASK               (0x20U)
#define PMC_PDRUNCFG1_HVD1_PD_SHIFT              (5U)
/*! HVD1_PD - Power Down HVD in VDD1 Domain
 *  0b0..Power on. In this case, PMC references will be in high-power mode
 *  0b1..Power down
 */
#define PMC_PDRUNCFG1_HVD1_PD(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_HVD1_PD_SHIFT)) & PMC_PDRUNCFG1_HVD1_PD_MASK)

#define PMC_PDRUNCFG1_AGDET1_PD_MASK             (0x40U)
#define PMC_PDRUNCFG1_AGDET1_PD_SHIFT            (6U)
/*! AGDET1_PD - Power Down aGDET in VDD1 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG1_AGDET1_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_AGDET1_PD_SHIFT)) & PMC_PDRUNCFG1_AGDET1_PD_MASK)

#define PMC_PDRUNCFG1_POR2_LP_MASK               (0x80U)
#define PMC_PDRUNCFG1_POR2_LP_SHIFT              (7U)
/*! POR2_LP - POR Low-Power Mode in VDD2 Domain
 *  0b0..Sets POR in high-power mode. In this case, PMC references will be in high-power mode
 *  0b1..Sets POR in low-power mode
 */
#define PMC_PDRUNCFG1_POR2_LP(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_POR2_LP_SHIFT)) & PMC_PDRUNCFG1_POR2_LP_MASK)

#define PMC_PDRUNCFG1_LVD2_LP_MASK               (0x100U)
#define PMC_PDRUNCFG1_LVD2_LP_SHIFT              (8U)
/*! LVD2_LP - LVD Low-Power Mode in VDD2 Domain
 *  0b0..Sets LVD in high-power mode. In this case, PMC references will be in high-power mode
 *  0b1..Sets LVD in low-power mode
 */
#define PMC_PDRUNCFG1_LVD2_LP(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_LVD2_LP_SHIFT)) & PMC_PDRUNCFG1_LVD2_LP_MASK)

#define PMC_PDRUNCFG1_HVD2_PD_MASK               (0x200U)
#define PMC_PDRUNCFG1_HVD2_PD_SHIFT              (9U)
/*! HVD2_PD - Power Down HVD in VDD2 Domain
 *  0b0..Power on. In this case, PMC references will be in high-power mode
 *  0b1..Power down
 */
#define PMC_PDRUNCFG1_HVD2_PD(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_HVD2_PD_SHIFT)) & PMC_PDRUNCFG1_HVD2_PD_MASK)

#define PMC_PDRUNCFG1_AGDET2_PD_MASK             (0x400U)
#define PMC_PDRUNCFG1_AGDET2_PD_SHIFT            (10U)
/*! AGDET2_PD - Power Down aGDET in VDD2 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG1_AGDET2_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_AGDET2_PD_SHIFT)) & PMC_PDRUNCFG1_AGDET2_PD_MASK)

#define PMC_PDRUNCFG1_PORN_LP_MASK               (0x800U)
#define PMC_PDRUNCFG1_PORN_LP_SHIFT              (11U)
/*! PORN_LP - POR Low-Power Mode in VDDN Domain
 *  0b0..Sets POR in high-power mode. In this case, PMC references will be in high-power mode
 *  0b1..Sets POR in low-power mode
 */
#define PMC_PDRUNCFG1_PORN_LP(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_PORN_LP_SHIFT)) & PMC_PDRUNCFG1_PORN_LP_MASK)

#define PMC_PDRUNCFG1_LVDN_LP_MASK               (0x1000U)
#define PMC_PDRUNCFG1_LVDN_LP_SHIFT              (12U)
/*! LVDN_LP - LVD Low-Power Mode in VDDN Domain
 *  0b0..Sets LVD in high-power mode. In this case, PMC references will be in high-power mode
 *  0b1..Sets LVD in low-power mode
 */
#define PMC_PDRUNCFG1_LVDN_LP(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_LVDN_LP_SHIFT)) & PMC_PDRUNCFG1_LVDN_LP_MASK)

#define PMC_PDRUNCFG1_HVDN_PD_MASK               (0x2000U)
#define PMC_PDRUNCFG1_HVDN_PD_SHIFT              (13U)
/*! HVDN_PD - Power Down HVD in VDDN Domain
 *  0b0..Power on. In this case, PMC references will be in high-power mode
 *  0b1..Power down
 */
#define PMC_PDRUNCFG1_HVDN_PD(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_HVDN_PD_SHIFT)) & PMC_PDRUNCFG1_HVDN_PD_MASK)

#define PMC_PDRUNCFG1_OTP_PD_MASK                (0x8000U)
#define PMC_PDRUNCFG1_OTP_PD_SHIFT               (15U)
/*! OTP_PD - Power Down OTP
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG1_OTP_PD(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_OTP_PD_SHIFT)) & PMC_PDRUNCFG1_OTP_PD_MASK)

#define PMC_PDRUNCFG1_ROM_PD_MASK                (0x10000U)
#define PMC_PDRUNCFG1_ROM_PD_SHIFT               (16U)
/*! ROM_PD - Power Down ROM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG1_ROM_PD(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG1_ROM_PD_SHIFT)) & PMC_PDRUNCFG1_ROM_PD_MASK)
/*! @} */

/*! @name PDRUNCFG2 - PD Run Configuration 2 in Compute Domain */
/*! @{ */

#define PMC_PDRUNCFG2_SRAM0_MASK                 (0x1U)
#define PMC_PDRUNCFG2_SRAM0_SHIFT                (0U)
/*! SRAM0 - Power Down RAM Partition 0 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM0(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM0_SHIFT)) & PMC_PDRUNCFG2_SRAM0_MASK)

#define PMC_PDRUNCFG2_SRAM1_MASK                 (0x2U)
#define PMC_PDRUNCFG2_SRAM1_SHIFT                (1U)
/*! SRAM1 - Power Down RAM Partition 1 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM1(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM1_SHIFT)) & PMC_PDRUNCFG2_SRAM1_MASK)

#define PMC_PDRUNCFG2_SRAM2_MASK                 (0x4U)
#define PMC_PDRUNCFG2_SRAM2_SHIFT                (2U)
/*! SRAM2 - Power Down RAM Partition 2 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM2(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM2_SHIFT)) & PMC_PDRUNCFG2_SRAM2_MASK)

#define PMC_PDRUNCFG2_SRAM3_MASK                 (0x8U)
#define PMC_PDRUNCFG2_SRAM3_SHIFT                (3U)
/*! SRAM3 - Power Down RAM Partition 3 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM3(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM3_SHIFT)) & PMC_PDRUNCFG2_SRAM3_MASK)

#define PMC_PDRUNCFG2_SRAM4_MASK                 (0x10U)
#define PMC_PDRUNCFG2_SRAM4_SHIFT                (4U)
/*! SRAM4 - Power Down RAM Partition 4 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM4(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM4_SHIFT)) & PMC_PDRUNCFG2_SRAM4_MASK)

#define PMC_PDRUNCFG2_SRAM5_MASK                 (0x20U)
#define PMC_PDRUNCFG2_SRAM5_SHIFT                (5U)
/*! SRAM5 - Power Down RAM Partition 5 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM5(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM5_SHIFT)) & PMC_PDRUNCFG2_SRAM5_MASK)

#define PMC_PDRUNCFG2_SRAM6_MASK                 (0x40U)
#define PMC_PDRUNCFG2_SRAM6_SHIFT                (6U)
/*! SRAM6 - Power Down RAM Partition 6 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM6(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM6_SHIFT)) & PMC_PDRUNCFG2_SRAM6_MASK)

#define PMC_PDRUNCFG2_SRAM7_MASK                 (0x80U)
#define PMC_PDRUNCFG2_SRAM7_SHIFT                (7U)
/*! SRAM7 - Power Down RAM Partition 7 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM7(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM7_SHIFT)) & PMC_PDRUNCFG2_SRAM7_MASK)

#define PMC_PDRUNCFG2_SRAM8_MASK                 (0x100U)
#define PMC_PDRUNCFG2_SRAM8_SHIFT                (8U)
/*! SRAM8 - Power Down RAM Partition 8 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM8(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM8_SHIFT)) & PMC_PDRUNCFG2_SRAM8_MASK)

#define PMC_PDRUNCFG2_SRAM9_MASK                 (0x200U)
#define PMC_PDRUNCFG2_SRAM9_SHIFT                (9U)
/*! SRAM9 - Power Down RAM Partition 9 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM9(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM9_SHIFT)) & PMC_PDRUNCFG2_SRAM9_MASK)

#define PMC_PDRUNCFG2_SRAM10_MASK                (0x400U)
#define PMC_PDRUNCFG2_SRAM10_SHIFT               (10U)
/*! SRAM10 - Power Down RAM Partition 10 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM10(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM10_SHIFT)) & PMC_PDRUNCFG2_SRAM10_MASK)

#define PMC_PDRUNCFG2_SRAM11_MASK                (0x800U)
#define PMC_PDRUNCFG2_SRAM11_SHIFT               (11U)
/*! SRAM11 - Power Down RAM Partition 11 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM11(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM11_SHIFT)) & PMC_PDRUNCFG2_SRAM11_MASK)

#define PMC_PDRUNCFG2_SRAM12_MASK                (0x1000U)
#define PMC_PDRUNCFG2_SRAM12_SHIFT               (12U)
/*! SRAM12 - Power Down RAM Partition 12 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM12(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM12_SHIFT)) & PMC_PDRUNCFG2_SRAM12_MASK)

#define PMC_PDRUNCFG2_SRAM13_MASK                (0x2000U)
#define PMC_PDRUNCFG2_SRAM13_SHIFT               (13U)
/*! SRAM13 - Power Down RAM Partition 13 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM13(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM13_SHIFT)) & PMC_PDRUNCFG2_SRAM13_MASK)

#define PMC_PDRUNCFG2_SRAM14_MASK                (0x4000U)
#define PMC_PDRUNCFG2_SRAM14_SHIFT               (14U)
/*! SRAM14 - Power Down RAM Partition 14 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM14(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM14_SHIFT)) & PMC_PDRUNCFG2_SRAM14_MASK)

#define PMC_PDRUNCFG2_SRAM15_MASK                (0x8000U)
#define PMC_PDRUNCFG2_SRAM15_SHIFT               (15U)
/*! SRAM15 - Power Down RAM Partition 15 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM15(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM15_SHIFT)) & PMC_PDRUNCFG2_SRAM15_MASK)

#define PMC_PDRUNCFG2_SRAM16_MASK                (0x10000U)
#define PMC_PDRUNCFG2_SRAM16_SHIFT               (16U)
/*! SRAM16 - Power Down RAM Partition 16 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM16(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM16_SHIFT)) & PMC_PDRUNCFG2_SRAM16_MASK)

#define PMC_PDRUNCFG2_SRAM17_MASK                (0x20000U)
#define PMC_PDRUNCFG2_SRAM17_SHIFT               (17U)
/*! SRAM17 - Power Down RAM Partition 17 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM17(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM17_SHIFT)) & PMC_PDRUNCFG2_SRAM17_MASK)

#define PMC_PDRUNCFG2_SRAM18_MASK                (0x40000U)
#define PMC_PDRUNCFG2_SRAM18_SHIFT               (18U)
/*! SRAM18 - Power Down RAM Partition 18 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM18(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM18_SHIFT)) & PMC_PDRUNCFG2_SRAM18_MASK)

#define PMC_PDRUNCFG2_SRAM19_MASK                (0x80000U)
#define PMC_PDRUNCFG2_SRAM19_SHIFT               (19U)
/*! SRAM19 - Power Down RAM Partition 19 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM19(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM19_SHIFT)) & PMC_PDRUNCFG2_SRAM19_MASK)

#define PMC_PDRUNCFG2_SRAM20_MASK                (0x100000U)
#define PMC_PDRUNCFG2_SRAM20_SHIFT               (20U)
/*! SRAM20 - Power Down RAM Partition 20 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM20(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM20_SHIFT)) & PMC_PDRUNCFG2_SRAM20_MASK)

#define PMC_PDRUNCFG2_SRAM21_MASK                (0x200000U)
#define PMC_PDRUNCFG2_SRAM21_SHIFT               (21U)
/*! SRAM21 - Power Down RAM Partition 21 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM21(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM21_SHIFT)) & PMC_PDRUNCFG2_SRAM21_MASK)

#define PMC_PDRUNCFG2_SRAM22_MASK                (0x400000U)
#define PMC_PDRUNCFG2_SRAM22_SHIFT               (22U)
/*! SRAM22 - Power Down RAM Partition 22 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM22(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM22_SHIFT)) & PMC_PDRUNCFG2_SRAM22_MASK)

#define PMC_PDRUNCFG2_SRAM23_MASK                (0x800000U)
#define PMC_PDRUNCFG2_SRAM23_SHIFT               (23U)
/*! SRAM23 - Power Down RAM Partition 23 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM23(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM23_SHIFT)) & PMC_PDRUNCFG2_SRAM23_MASK)

#define PMC_PDRUNCFG2_SRAM24_MASK                (0x1000000U)
#define PMC_PDRUNCFG2_SRAM24_SHIFT               (24U)
/*! SRAM24 - Power Down RAM Partition 24 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM24(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM24_SHIFT)) & PMC_PDRUNCFG2_SRAM24_MASK)

#define PMC_PDRUNCFG2_SRAM25_MASK                (0x2000000U)
#define PMC_PDRUNCFG2_SRAM25_SHIFT               (25U)
/*! SRAM25 - Power Down RAM Partition 25 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM25(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM25_SHIFT)) & PMC_PDRUNCFG2_SRAM25_MASK)

#define PMC_PDRUNCFG2_SRAM26_MASK                (0x4000000U)
#define PMC_PDRUNCFG2_SRAM26_SHIFT               (26U)
/*! SRAM26 - Power Down RAM Partition 26 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM26(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM26_SHIFT)) & PMC_PDRUNCFG2_SRAM26_MASK)

#define PMC_PDRUNCFG2_SRAM27_MASK                (0x8000000U)
#define PMC_PDRUNCFG2_SRAM27_SHIFT               (27U)
/*! SRAM27 - Power Down RAM Partition 27 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM27(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM27_SHIFT)) & PMC_PDRUNCFG2_SRAM27_MASK)

#define PMC_PDRUNCFG2_SRAM28_MASK                (0x10000000U)
#define PMC_PDRUNCFG2_SRAM28_SHIFT               (28U)
/*! SRAM28 - Power Down RAM Partition 28 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM28(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM28_SHIFT)) & PMC_PDRUNCFG2_SRAM28_MASK)

#define PMC_PDRUNCFG2_SRAM29_MASK                (0x20000000U)
#define PMC_PDRUNCFG2_SRAM29_SHIFT               (29U)
/*! SRAM29 - Power Down RAM Partition 29 Array
 *  0b0..Array power on, periphery power controlled by PD*CFG3
 *  0b1..Power down
 */
#define PMC_PDRUNCFG2_SRAM29(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG2_SRAM29_SHIFT)) & PMC_PDRUNCFG2_SRAM29_MASK)
/*! @} */

/*! @name PDRUNCFG3 - PD Run Configuration 3 in Compute Domain */
/*! @{ */

#define PMC_PDRUNCFG3_SRAM0_MASK                 (0x1U)
#define PMC_PDRUNCFG3_SRAM0_SHIFT                (0U)
/*! SRAM0 - Power Down RAM Partition 0 Periphery
 *  0b0..Power on when the corresponding array SRAM 0 is 0
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM0(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM0_SHIFT)) & PMC_PDRUNCFG3_SRAM0_MASK)

#define PMC_PDRUNCFG3_SRAM1_MASK                 (0x2U)
#define PMC_PDRUNCFG3_SRAM1_SHIFT                (1U)
/*! SRAM1 - Power Down RAM Partition 1 Periphery
 *  0b0..Power on when the corresponding array SRAM 1 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM1(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM1_SHIFT)) & PMC_PDRUNCFG3_SRAM1_MASK)

#define PMC_PDRUNCFG3_SRAM2_MASK                 (0x4U)
#define PMC_PDRUNCFG3_SRAM2_SHIFT                (2U)
/*! SRAM2 - Power Down RAM Partition 2 Periphery
 *  0b0..Power on when the corresponding array SRAM 2 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM2(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM2_SHIFT)) & PMC_PDRUNCFG3_SRAM2_MASK)

#define PMC_PDRUNCFG3_SRAM3_MASK                 (0x8U)
#define PMC_PDRUNCFG3_SRAM3_SHIFT                (3U)
/*! SRAM3 - Power Down RAM Partition 3 Periphery
 *  0b0..Power on when the corresponding array SRAM 3 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM3(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM3_SHIFT)) & PMC_PDRUNCFG3_SRAM3_MASK)

#define PMC_PDRUNCFG3_SRAM4_MASK                 (0x10U)
#define PMC_PDRUNCFG3_SRAM4_SHIFT                (4U)
/*! SRAM4 - Power Down RAM Partition 4 Periphery
 *  0b0..Power on when the corresponding array SRAM 4 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM4(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM4_SHIFT)) & PMC_PDRUNCFG3_SRAM4_MASK)

#define PMC_PDRUNCFG3_SRAM5_MASK                 (0x20U)
#define PMC_PDRUNCFG3_SRAM5_SHIFT                (5U)
/*! SRAM5 - Power Down RAM Partition 5 Periphery
 *  0b0..Power on when the corresponding array SRAM 5 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM5(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM5_SHIFT)) & PMC_PDRUNCFG3_SRAM5_MASK)

#define PMC_PDRUNCFG3_SRAM6_MASK                 (0x40U)
#define PMC_PDRUNCFG3_SRAM6_SHIFT                (6U)
/*! SRAM6 - Power Down RAM Partition 6 Periphery
 *  0b0..Power on when the corresponding array SRAM 6 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM6(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM6_SHIFT)) & PMC_PDRUNCFG3_SRAM6_MASK)

#define PMC_PDRUNCFG3_SRAM7_MASK                 (0x80U)
#define PMC_PDRUNCFG3_SRAM7_SHIFT                (7U)
/*! SRAM7 - Power Down RAM Partition 7 Periphery
 *  0b0..Power on when the corresponding array SRAM 7 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM7(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM7_SHIFT)) & PMC_PDRUNCFG3_SRAM7_MASK)

#define PMC_PDRUNCFG3_SRAM8_MASK                 (0x100U)
#define PMC_PDRUNCFG3_SRAM8_SHIFT                (8U)
/*! SRAM8 - Power Down RAM Partition 8 Periphery
 *  0b0..Power on when the corresponding array SRAM 8 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM8(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM8_SHIFT)) & PMC_PDRUNCFG3_SRAM8_MASK)

#define PMC_PDRUNCFG3_SRAM9_MASK                 (0x200U)
#define PMC_PDRUNCFG3_SRAM9_SHIFT                (9U)
/*! SRAM9 - Power Down RAM Partition 9 Periphery
 *  0b0..Power on when the corresponding array SRAM 9 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM9(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM9_SHIFT)) & PMC_PDRUNCFG3_SRAM9_MASK)

#define PMC_PDRUNCFG3_SRAM10_MASK                (0x400U)
#define PMC_PDRUNCFG3_SRAM10_SHIFT               (10U)
/*! SRAM10 - Power Down RAM Partition 10 Periphery
 *  0b0..Power on when the corresponding array SRAM 10 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM10(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM10_SHIFT)) & PMC_PDRUNCFG3_SRAM10_MASK)

#define PMC_PDRUNCFG3_SRAM11_MASK                (0x800U)
#define PMC_PDRUNCFG3_SRAM11_SHIFT               (11U)
/*! SRAM11 - Power Down RAM Partition 11 Periphery
 *  0b0..Power on when the corresponding array SRAM 11 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM11(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM11_SHIFT)) & PMC_PDRUNCFG3_SRAM11_MASK)

#define PMC_PDRUNCFG3_SRAM12_MASK                (0x1000U)
#define PMC_PDRUNCFG3_SRAM12_SHIFT               (12U)
/*! SRAM12 - Power Down RAM Partition 12 Periphery
 *  0b0..Power on when the corresponding array SRAM 12 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM12(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM12_SHIFT)) & PMC_PDRUNCFG3_SRAM12_MASK)

#define PMC_PDRUNCFG3_SRAM13_MASK                (0x2000U)
#define PMC_PDRUNCFG3_SRAM13_SHIFT               (13U)
/*! SRAM13 - Power Down RAM Partition 13 Periphery
 *  0b0..Power on when the corresponding array SRAM 13 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM13(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM13_SHIFT)) & PMC_PDRUNCFG3_SRAM13_MASK)

#define PMC_PDRUNCFG3_SRAM14_MASK                (0x4000U)
#define PMC_PDRUNCFG3_SRAM14_SHIFT               (14U)
/*! SRAM14 - Power Down RAM Partition 14 Periphery
 *  0b0..Power on when the corresponding array SRAM 14 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM14(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM14_SHIFT)) & PMC_PDRUNCFG3_SRAM14_MASK)

#define PMC_PDRUNCFG3_SRAM15_MASK                (0x8000U)
#define PMC_PDRUNCFG3_SRAM15_SHIFT               (15U)
/*! SRAM15 - Power Down RAM Partition 15 Periphery
 *  0b0..Power on when the corresponding array SRAM 15 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM15(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM15_SHIFT)) & PMC_PDRUNCFG3_SRAM15_MASK)

#define PMC_PDRUNCFG3_SRAM16_MASK                (0x10000U)
#define PMC_PDRUNCFG3_SRAM16_SHIFT               (16U)
/*! SRAM16 - Power Down RAM Partition 16 Periphery
 *  0b0..Power on when the corresponding array SRAM 16 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM16(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM16_SHIFT)) & PMC_PDRUNCFG3_SRAM16_MASK)

#define PMC_PDRUNCFG3_SRAM17_MASK                (0x20000U)
#define PMC_PDRUNCFG3_SRAM17_SHIFT               (17U)
/*! SRAM17 - Power Down RAM Partition 17 Periphery
 *  0b0..Power on when the corresponding array SRAM 17 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM17(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM17_SHIFT)) & PMC_PDRUNCFG3_SRAM17_MASK)

#define PMC_PDRUNCFG3_SRAM18_MASK                (0x40000U)
#define PMC_PDRUNCFG3_SRAM18_SHIFT               (18U)
/*! SRAM18 - Power Down RAM Partition 18 Periphery
 *  0b0..Power on when the corresponding array SRAM 18 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM18(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM18_SHIFT)) & PMC_PDRUNCFG3_SRAM18_MASK)

#define PMC_PDRUNCFG3_SRAM19_MASK                (0x80000U)
#define PMC_PDRUNCFG3_SRAM19_SHIFT               (19U)
/*! SRAM19 - Power Down RAM Partition 19 Periphery
 *  0b0..Power on when the corresponding array SRAM 19 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM19(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM19_SHIFT)) & PMC_PDRUNCFG3_SRAM19_MASK)

#define PMC_PDRUNCFG3_SRAM20_MASK                (0x100000U)
#define PMC_PDRUNCFG3_SRAM20_SHIFT               (20U)
/*! SRAM20 - Power Down RAM Partition 20 Periphery
 *  0b0..Power on when the corresponding array SRAM 20 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM20(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM20_SHIFT)) & PMC_PDRUNCFG3_SRAM20_MASK)

#define PMC_PDRUNCFG3_SRAM21_MASK                (0x200000U)
#define PMC_PDRUNCFG3_SRAM21_SHIFT               (21U)
/*! SRAM21 - Power Down RAM Partition 21 Periphery
 *  0b0..Power on when the corresponding array SRAM 21 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM21(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM21_SHIFT)) & PMC_PDRUNCFG3_SRAM21_MASK)

#define PMC_PDRUNCFG3_SRAM22_MASK                (0x400000U)
#define PMC_PDRUNCFG3_SRAM22_SHIFT               (22U)
/*! SRAM22 - Power Down RAM Partition 22 Periphery
 *  0b0..Power on when the corresponding array SRAM 22 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM22(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM22_SHIFT)) & PMC_PDRUNCFG3_SRAM22_MASK)

#define PMC_PDRUNCFG3_SRAM23_MASK                (0x800000U)
#define PMC_PDRUNCFG3_SRAM23_SHIFT               (23U)
/*! SRAM23 - Power Down RAM Partition 23 Periphery
 *  0b0..Power on when the corresponding array SRAM 23 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM23(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM23_SHIFT)) & PMC_PDRUNCFG3_SRAM23_MASK)

#define PMC_PDRUNCFG3_SRAM24_MASK                (0x1000000U)
#define PMC_PDRUNCFG3_SRAM24_SHIFT               (24U)
/*! SRAM24 - Power Down RAM Partition 24 Periphery
 *  0b0..Power on when the corresponding array SRAM 24 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM24(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM24_SHIFT)) & PMC_PDRUNCFG3_SRAM24_MASK)

#define PMC_PDRUNCFG3_SRAM25_MASK                (0x2000000U)
#define PMC_PDRUNCFG3_SRAM25_SHIFT               (25U)
/*! SRAM25 - Power Down RAM Partition 25 Periphery
 *  0b0..Power on when the corresponding array SRAM 25 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM25(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM25_SHIFT)) & PMC_PDRUNCFG3_SRAM25_MASK)

#define PMC_PDRUNCFG3_SRAM26_MASK                (0x4000000U)
#define PMC_PDRUNCFG3_SRAM26_SHIFT               (26U)
/*! SRAM26 - Power Down RAM Partition 26 Periphery
 *  0b0..Power on when the corresponding array SRAM 26 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM26(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM26_SHIFT)) & PMC_PDRUNCFG3_SRAM26_MASK)

#define PMC_PDRUNCFG3_SRAM27_MASK                (0x8000000U)
#define PMC_PDRUNCFG3_SRAM27_SHIFT               (27U)
/*! SRAM27 - Power Down RAM Partition 27 Periphery
 *  0b0..Power on when the corresponding array SRAM 27 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM27(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM27_SHIFT)) & PMC_PDRUNCFG3_SRAM27_MASK)

#define PMC_PDRUNCFG3_SRAM28_MASK                (0x10000000U)
#define PMC_PDRUNCFG3_SRAM28_SHIFT               (28U)
/*! SRAM28 - Power Down RAM Partition 28 Periphery
 *  0b0..Power on when the corresponding array SRAM 28 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM28(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM28_SHIFT)) & PMC_PDRUNCFG3_SRAM28_MASK)

#define PMC_PDRUNCFG3_SRAM29_MASK                (0x20000000U)
#define PMC_PDRUNCFG3_SRAM29_SHIFT               (29U)
/*! SRAM29 - Power Down RAM Partition 29 Periphery
 *  0b0..Power on when the corresponding array SRAM 29 is 0.
 *  0b1..Power down
 */
#define PMC_PDRUNCFG3_SRAM29(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG3_SRAM29_SHIFT)) & PMC_PDRUNCFG3_SRAM29_MASK)
/*! @} */

/*! @name PDRUNCFG4 - PD Run Configuration 4 in Compute Domain */
/*! @{ */

#define PMC_PDRUNCFG4_SDHC0_SRAM_MASK            (0x1U)
#define PMC_PDRUNCFG4_SDHC0_SRAM_SHIFT           (0U)
/*! SDHC0_SRAM - uSDHC0 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_SDHC0_SRAM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_SDHC0_SRAM_SHIFT)) & PMC_PDRUNCFG4_SDHC0_SRAM_MASK)

#define PMC_PDRUNCFG4_SDHC1_SRAM_MASK            (0x2U)
#define PMC_PDRUNCFG4_SDHC1_SRAM_SHIFT           (1U)
/*! SDHC1_SRAM - uSDHC1 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_SDHC1_SRAM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_SDHC1_SRAM_SHIFT)) & PMC_PDRUNCFG4_SDHC1_SRAM_MASK)

#define PMC_PDRUNCFG4_USB0_SRAM_MASK             (0x4U)
#define PMC_PDRUNCFG4_USB0_SRAM_SHIFT            (2U)
/*! USB0_SRAM - USB0 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_USB0_SRAM(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_USB0_SRAM_SHIFT)) & PMC_PDRUNCFG4_USB0_SRAM_MASK)

#define PMC_PDRUNCFG4_USB1_SRAM_MASK             (0x8U)
#define PMC_PDRUNCFG4_USB1_SRAM_SHIFT            (3U)
/*! USB1_SRAM - USB1 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_USB1_SRAM(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_USB1_SRAM_SHIFT)) & PMC_PDRUNCFG4_USB1_SRAM_MASK)

#define PMC_PDRUNCFG4_JPEG_MASK                  (0x10U)
#define PMC_PDRUNCFG4_JPEG_SHIFT                 (4U)
/*! JPEG - JPEGDEC
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_JPEG(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_JPEG_SHIFT)) & PMC_PDRUNCFG4_JPEG_MASK)

#define PMC_PDRUNCFG4_PNG_MASK                   (0x20U)
#define PMC_PDRUNCFG4_PNG_SHIFT                  (5U)
/*! PNG - PNGDEC
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_PNG(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_PNG_SHIFT)) & PMC_PDRUNCFG4_PNG_MASK)

#define PMC_PDRUNCFG4_MIPI_MASK                  (0x40U)
#define PMC_PDRUNCFG4_MIPI_SHIFT                 (6U)
/*! MIPI - MIPI PHY
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_MIPI(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_MIPI_SHIFT)) & PMC_PDRUNCFG4_MIPI_MASK)

#define PMC_PDRUNCFG4_GPU_MASK                   (0x80U)
#define PMC_PDRUNCFG4_GPU_SHIFT                  (7U)
/*! GPU - VGPU
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_GPU(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_GPU_SHIFT)) & PMC_PDRUNCFG4_GPU_MASK)

#define PMC_PDRUNCFG4_DMA2_3_MASK                (0x100U)
#define PMC_PDRUNCFG4_DMA2_3_SHIFT               (8U)
/*! DMA2_3 - DMA2 and DMA3
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_DMA2_3(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_DMA2_3_SHIFT)) & PMC_PDRUNCFG4_DMA2_3_MASK)

#define PMC_PDRUNCFG4_DMA0_1_P_E_MASK            (0x200U)
#define PMC_PDRUNCFG4_DMA0_1_P_E_SHIFT           (9U)
/*! DMA0_1_P_E - DMA0-1, PKC, and ETF
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_DMA0_1_P_E(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_DMA0_1_P_E_SHIFT)) & PMC_PDRUNCFG4_DMA0_1_P_E_MASK)

#define PMC_PDRUNCFG4_CPU0_CCACHE_MASK           (0x400U)
#define PMC_PDRUNCFG4_CPU0_CCACHE_SHIFT          (10U)
/*! CPU0_CCACHE - CPU0 Code Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_CPU0_CCACHE(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_CPU0_CCACHE_SHIFT)) & PMC_PDRUNCFG4_CPU0_CCACHE_MASK)

#define PMC_PDRUNCFG4_CPU0_SCACHE_MASK           (0x800U)
#define PMC_PDRUNCFG4_CPU0_SCACHE_SHIFT          (11U)
/*! CPU0_SCACHE - CPU0 System Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_CPU0_SCACHE(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_CPU0_SCACHE_SHIFT)) & PMC_PDRUNCFG4_CPU0_SCACHE_MASK)

#define PMC_PDRUNCFG4_DSP_ICACHE_MASK            (0x1000U)
#define PMC_PDRUNCFG4_DSP_ICACHE_SHIFT           (12U)
/*! DSP_ICACHE - HiFi4 Instruction Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_DSP_ICACHE(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_DSP_ICACHE_SHIFT)) & PMC_PDRUNCFG4_DSP_ICACHE_MASK)

#define PMC_PDRUNCFG4_DSP_DCACHE_MASK            (0x2000U)
#define PMC_PDRUNCFG4_DSP_DCACHE_SHIFT           (13U)
/*! DSP_DCACHE - HiFi4 Data Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_DSP_DCACHE(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_DSP_DCACHE_SHIFT)) & PMC_PDRUNCFG4_DSP_DCACHE_MASK)

#define PMC_PDRUNCFG4_DSP_ITCM_MASK              (0x4000U)
#define PMC_PDRUNCFG4_DSP_ITCM_SHIFT             (14U)
/*! DSP_ITCM - HiFi4 Instruction TCM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_DSP_ITCM(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_DSP_ITCM_SHIFT)) & PMC_PDRUNCFG4_DSP_ITCM_MASK)

#define PMC_PDRUNCFG4_DSP_DTCM_MASK              (0x8000U)
#define PMC_PDRUNCFG4_DSP_DTCM_SHIFT             (15U)
/*! DSP_DTCM - HiFi4 Data TCM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_DSP_DTCM(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_DSP_DTCM_SHIFT)) & PMC_PDRUNCFG4_DSP_DTCM_MASK)

#define PMC_PDRUNCFG4_EZH_TCM_MASK               (0x10000U)
#define PMC_PDRUNCFG4_EZH_TCM_SHIFT              (16U)
/*! EZH_TCM - EZH-V TCM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_EZH_TCM(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_EZH_TCM_SHIFT)) & PMC_PDRUNCFG4_EZH_TCM_MASK)

#define PMC_PDRUNCFG4_NPU_MASK                   (0x20000U)
#define PMC_PDRUNCFG4_NPU_SHIFT                  (17U)
/*! NPU - NPU
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_NPU(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_NPU_SHIFT)) & PMC_PDRUNCFG4_NPU_MASK)

#define PMC_PDRUNCFG4_XSPI0_MASK                 (0x40000U)
#define PMC_PDRUNCFG4_XSPI0_SHIFT                (18U)
/*! XSPI0 - XSPI0, MMU0, and Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_XSPI0(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_XSPI0_SHIFT)) & PMC_PDRUNCFG4_XSPI0_MASK)

#define PMC_PDRUNCFG4_XSPI1_MASK                 (0x80000U)
#define PMC_PDRUNCFG4_XSPI1_SHIFT                (19U)
/*! XSPI1 - XSPI1, MMU1, and Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_XSPI1(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_XSPI1_SHIFT)) & PMC_PDRUNCFG4_XSPI1_MASK)

#define PMC_PDRUNCFG4_XSPI2_MASK                 (0x100000U)
#define PMC_PDRUNCFG4_XSPI2_SHIFT                (20U)
/*! XSPI2 - XSPI2 and MMU2
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_XSPI2(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_XSPI2_SHIFT)) & PMC_PDRUNCFG4_XSPI2_MASK)

#define PMC_PDRUNCFG4_LCD_MASK                   (0x200000U)
#define PMC_PDRUNCFG4_LCD_SHIFT                  (21U)
/*! LCD - LCDIF
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_LCD(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_LCD_SHIFT)) & PMC_PDRUNCFG4_LCD_MASK)

#define PMC_PDRUNCFG4_OCOTP_MASK                 (0x400000U)
#define PMC_PDRUNCFG4_OCOTP_SHIFT                (22U)
/*! OCOTP - OCOTP Shadow SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG4_OCOTP(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG4_OCOTP_SHIFT)) & PMC_PDRUNCFG4_OCOTP_MASK)
/*! @} */

/*! @name PDRUNCFG5 - PD Run Configuration 5 in Compute Domain */
/*! @{ */

#define PMC_PDRUNCFG5_SDHC0_SRAM_MASK            (0x1U)
#define PMC_PDRUNCFG5_SDHC0_SRAM_SHIFT           (0U)
/*! SDHC0_SRAM - uSDHC0 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_SDHC0_SRAM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_SDHC0_SRAM_SHIFT)) & PMC_PDRUNCFG5_SDHC0_SRAM_MASK)

#define PMC_PDRUNCFG5_SDHC1_SRAM_MASK            (0x2U)
#define PMC_PDRUNCFG5_SDHC1_SRAM_SHIFT           (1U)
/*! SDHC1_SRAM - uSDHC1 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_SDHC1_SRAM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_SDHC1_SRAM_SHIFT)) & PMC_PDRUNCFG5_SDHC1_SRAM_MASK)

#define PMC_PDRUNCFG5_USB0_SRAM_MASK             (0x4U)
#define PMC_PDRUNCFG5_USB0_SRAM_SHIFT            (2U)
/*! USB0_SRAM - USB0 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_USB0_SRAM(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_USB0_SRAM_SHIFT)) & PMC_PDRUNCFG5_USB0_SRAM_MASK)

#define PMC_PDRUNCFG5_USB1_SRAM_MASK             (0x8U)
#define PMC_PDRUNCFG5_USB1_SRAM_SHIFT            (3U)
/*! USB1_SRAM - USB1 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_USB1_SRAM(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_USB1_SRAM_SHIFT)) & PMC_PDRUNCFG5_USB1_SRAM_MASK)

#define PMC_PDRUNCFG5_JPEG_MASK                  (0x10U)
#define PMC_PDRUNCFG5_JPEG_SHIFT                 (4U)
/*! JPEG - JPEGDEC
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_JPEG(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_JPEG_SHIFT)) & PMC_PDRUNCFG5_JPEG_MASK)

#define PMC_PDRUNCFG5_PNG_MASK                   (0x20U)
#define PMC_PDRUNCFG5_PNG_SHIFT                  (5U)
/*! PNG - PNGDEC
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_PNG(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_PNG_SHIFT)) & PMC_PDRUNCFG5_PNG_MASK)

#define PMC_PDRUNCFG5_MIPI_MASK                  (0x40U)
#define PMC_PDRUNCFG5_MIPI_SHIFT                 (6U)
/*! MIPI - MIPI PHY
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_MIPI(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_MIPI_SHIFT)) & PMC_PDRUNCFG5_MIPI_MASK)

#define PMC_PDRUNCFG5_GPU_MASK                   (0x80U)
#define PMC_PDRUNCFG5_GPU_SHIFT                  (7U)
/*! GPU - VGPU
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_GPU(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_GPU_SHIFT)) & PMC_PDRUNCFG5_GPU_MASK)

#define PMC_PDRUNCFG5_DMA2_3_MASK                (0x100U)
#define PMC_PDRUNCFG5_DMA2_3_SHIFT               (8U)
/*! DMA2_3 - DMA2 and DMA3
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_DMA2_3(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_DMA2_3_SHIFT)) & PMC_PDRUNCFG5_DMA2_3_MASK)

#define PMC_PDRUNCFG5_DMA0_1_P_E_MASK            (0x200U)
#define PMC_PDRUNCFG5_DMA0_1_P_E_SHIFT           (9U)
/*! DMA0_1_P_E - DMA0-1, PKC, and ETF
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_DMA0_1_P_E(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_DMA0_1_P_E_SHIFT)) & PMC_PDRUNCFG5_DMA0_1_P_E_MASK)

#define PMC_PDRUNCFG5_CPU0_CCACHE_MASK           (0x400U)
#define PMC_PDRUNCFG5_CPU0_CCACHE_SHIFT          (10U)
/*! CPU0_CCACHE - CPU0 Code Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_CPU0_CCACHE(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_CPU0_CCACHE_SHIFT)) & PMC_PDRUNCFG5_CPU0_CCACHE_MASK)

#define PMC_PDRUNCFG5_CPU0_SCACHE_MASK           (0x800U)
#define PMC_PDRUNCFG5_CPU0_SCACHE_SHIFT          (11U)
/*! CPU0_SCACHE - CPU0 System Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_CPU0_SCACHE(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_CPU0_SCACHE_SHIFT)) & PMC_PDRUNCFG5_CPU0_SCACHE_MASK)

#define PMC_PDRUNCFG5_DSP_ICACHE_MASK            (0x1000U)
#define PMC_PDRUNCFG5_DSP_ICACHE_SHIFT           (12U)
/*! DSP_ICACHE - HiFi4 Instruction Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_DSP_ICACHE(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_DSP_ICACHE_SHIFT)) & PMC_PDRUNCFG5_DSP_ICACHE_MASK)

#define PMC_PDRUNCFG5_DSP_DCACHE_MASK            (0x2000U)
#define PMC_PDRUNCFG5_DSP_DCACHE_SHIFT           (13U)
/*! DSP_DCACHE - HiFi4 Data Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_DSP_DCACHE(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_DSP_DCACHE_SHIFT)) & PMC_PDRUNCFG5_DSP_DCACHE_MASK)

#define PMC_PDRUNCFG5_DSP_ITCM_MASK              (0x4000U)
#define PMC_PDRUNCFG5_DSP_ITCM_SHIFT             (14U)
/*! DSP_ITCM - HiFi4 Instruction TCM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_DSP_ITCM(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_DSP_ITCM_SHIFT)) & PMC_PDRUNCFG5_DSP_ITCM_MASK)

#define PMC_PDRUNCFG5_DSP_DTCM_MASK              (0x8000U)
#define PMC_PDRUNCFG5_DSP_DTCM_SHIFT             (15U)
/*! DSP_DTCM - HiFi4 Data TCM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_DSP_DTCM(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_DSP_DTCM_SHIFT)) & PMC_PDRUNCFG5_DSP_DTCM_MASK)

#define PMC_PDRUNCFG5_EZH_TCM_MASK               (0x10000U)
#define PMC_PDRUNCFG5_EZH_TCM_SHIFT              (16U)
/*! EZH_TCM - EZH-V TCM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_EZH_TCM(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_EZH_TCM_SHIFT)) & PMC_PDRUNCFG5_EZH_TCM_MASK)

#define PMC_PDRUNCFG5_NPU_MASK                   (0x20000U)
#define PMC_PDRUNCFG5_NPU_SHIFT                  (17U)
/*! NPU - NPU
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_NPU(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_NPU_SHIFT)) & PMC_PDRUNCFG5_NPU_MASK)

#define PMC_PDRUNCFG5_XSPI0_MASK                 (0x40000U)
#define PMC_PDRUNCFG5_XSPI0_SHIFT                (18U)
/*! XSPI0 - XSPI0, MMU0, and Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_XSPI0(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_XSPI0_SHIFT)) & PMC_PDRUNCFG5_XSPI0_MASK)

#define PMC_PDRUNCFG5_XSPI1_MASK                 (0x80000U)
#define PMC_PDRUNCFG5_XSPI1_SHIFT                (19U)
/*! XSPI1 - XSPI1, MMU1, and Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_XSPI1(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_XSPI1_SHIFT)) & PMC_PDRUNCFG5_XSPI1_MASK)

#define PMC_PDRUNCFG5_XSPI2_MASK                 (0x100000U)
#define PMC_PDRUNCFG5_XSPI2_SHIFT                (20U)
/*! XSPI2 - XSPI2 and MMU2
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_XSPI2(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_XSPI2_SHIFT)) & PMC_PDRUNCFG5_XSPI2_MASK)

#define PMC_PDRUNCFG5_LCD_MASK                   (0x200000U)
#define PMC_PDRUNCFG5_LCD_SHIFT                  (21U)
/*! LCD - LCDIF
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_LCD(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_LCD_SHIFT)) & PMC_PDRUNCFG5_LCD_MASK)

#define PMC_PDRUNCFG5_OCOTP_MASK                 (0x400000U)
#define PMC_PDRUNCFG5_OCOTP_SHIFT                (22U)
/*! OCOTP - OCOTP Shadow SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDRUNCFG5_OCOTP(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDRUNCFG5_OCOTP_SHIFT)) & PMC_PDRUNCFG5_OCOTP_MASK)
/*! @} */

/*! @name PDSLEEPCFG0 - PD Sleep Configuration 0 in Compute Domain */
/*! @{ */

#define PMC_PDSLEEPCFG0_PMICMODE_MASK            (0x3U)
#define PMC_PDSLEEPCFG0_PMICMODE_SHIFT           (0U)
/*! PMICMODE - PMIC Mode
 *  0b00..Drives PMIC_MODE pins to 0h
 *  0b01..Drives PMIC_MODE pins to 1h
 *  0b10..Drives PMIC_MODE pins to 2h
 *  0b11..Drives PMIC_MODE pins to 3h
 */
#define PMC_PDSLEEPCFG0_PMICMODE(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_PMICMODE_SHIFT)) & PMC_PDSLEEPCFG0_PMICMODE_MASK)

#define PMC_PDSLEEPCFG0_FDSR_MASK                (0x4U)
#define PMC_PDSLEEPCFG0_FDSR_SHIFT               (2U)
/*! FDSR - Full Deep Sleep Retention (FDSR) Mode
 *  0b0..All power switch states controlled by their respective PD*CFG bits
 *  0b1..All core domains in DSR or Power Down mode
 */
#define PMC_PDSLEEPCFG0_FDSR(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_FDSR_SHIFT)) & PMC_PDSLEEPCFG0_FDSR_MASK)

#define PMC_PDSLEEPCFG0_DPD_MASK                 (0x8U)
#define PMC_PDSLEEPCFG0_DPD_SHIFT                (3U)
/*! DPD - Deep Power Down (DPD) Mode
 *  0b0..Disables
 *  0b1..Enables DPD mode
 */
#define PMC_PDSLEEPCFG0_DPD(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_DPD_SHIFT)) & PMC_PDSLEEPCFG0_DPD_MASK)

#define PMC_PDSLEEPCFG0_FDPD_MASK                (0x10U)
#define PMC_PDSLEEPCFG0_FDPD_SHIFT               (4U)
/*! FDPD - Full Deep Power Down (FDPD) Mode
 *  0b0..Disables
 *  0b1..Enables FDPD mode
 */
#define PMC_PDSLEEPCFG0_FDPD(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_FDPD_SHIFT)) & PMC_PDSLEEPCFG0_FDPD_MASK)

#define PMC_PDSLEEPCFG0_V2COMP_DSR_MASK          (0x20U)
#define PMC_PDSLEEPCFG0_V2COMP_DSR_SHIFT         (5U)
/*! V2COMP_DSR - Power Switch and DSR Enable in VDD2_COMP Domain
 *  0b0..Powers on VDD2_COMP
 *  0b1..Enables DSR mode in VDD2_COMP
 */
#define PMC_PDSLEEPCFG0_V2COMP_DSR(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_V2COMP_DSR_SHIFT)) & PMC_PDSLEEPCFG0_V2COMP_DSR_MASK)

#define PMC_PDSLEEPCFG0_V2NMED_DSR_MASK          (0x40U)
#define PMC_PDSLEEPCFG0_V2NMED_DSR_SHIFT         (6U)
/*! V2NMED_DSR - Power Switch and DSR Enable in VDD2_MEDIA and VDDN_MEDIA Domains
 *  0b0..Powers on VDD2_MEDIA and VDDN_MEDIA
 *  0b1..Enables DSR mode in VDD2_MEDIA and VDDN_MEDIA
 */
#define PMC_PDSLEEPCFG0_V2NMED_DSR(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_V2NMED_DSR_SHIFT)) & PMC_PDSLEEPCFG0_V2NMED_DSR_MASK)

#define PMC_PDSLEEPCFG0_V2COM_DSR_MASK           (0x80U)
#define PMC_PDSLEEPCFG0_V2COM_DSR_SHIFT          (7U)
/*! V2COM_DSR - Power Switch and DSR Enable in VDD2_COM Domain
 *  0b0..Powers on VDD2_COM
 *  0b1..Enables DSR mode in VDD2_COM
 */
#define PMC_PDSLEEPCFG0_V2COM_DSR(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_V2COM_DSR_SHIFT)) & PMC_PDSLEEPCFG0_V2COM_DSR_MASK)

#define PMC_PDSLEEPCFG0_VNCOM_DSR_MASK           (0x100U)
#define PMC_PDSLEEPCFG0_VNCOM_DSR_SHIFT          (8U)
/*! VNCOM_DSR - Power Switch and DSR Enable in VDDN_COM Domain
 *  0b0..Powers on VDDN_COM
 *  0b1..Enables DSR mode in VDDN_COM
 */
#define PMC_PDSLEEPCFG0_VNCOM_DSR(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_VNCOM_DSR_SHIFT)) & PMC_PDSLEEPCFG0_VNCOM_DSR_MASK)

#define PMC_PDSLEEPCFG0_V2DSP_PD_MASK            (0x200U)
#define PMC_PDSLEEPCFG0_V2DSP_PD_SHIFT           (9U)
/*! V2DSP_PD - Power Down VDD2_DSP
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG0_V2DSP_PD(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_V2DSP_PD_SHIFT)) & PMC_PDSLEEPCFG0_V2DSP_PD_MASK)

#define PMC_PDSLEEPCFG0_V2MIPI_PD_MASK           (0x400U)
#define PMC_PDSLEEPCFG0_V2MIPI_PD_SHIFT          (10U)
/*! V2MIPI_PD - Power Down MIPI PHY in VDD2 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG0_V2MIPI_PD(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_V2MIPI_PD_SHIFT)) & PMC_PDSLEEPCFG0_V2MIPI_PD_MASK)

#define PMC_PDSLEEPCFG0_DCDC_LP_MASK             (0x1000U)
#define PMC_PDSLEEPCFG0_DCDC_LP_SHIFT            (12U)
/*! DCDC_LP - DCDC Low-Power Mode
 *  0b0..Enables DCDC in high-power mode
 *  0b1..Enables DCDC in low-power mode
 */
#define PMC_PDSLEEPCFG0_DCDC_LP(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_DCDC_LP_SHIFT)) & PMC_PDSLEEPCFG0_DCDC_LP_MASK)

#define PMC_PDSLEEPCFG0_DCDC_VSEL_MASK           (0x2000U)
#define PMC_PDSLEEPCFG0_DCDC_VSEL_SHIFT          (13U)
/*! DCDC_VSEL - DCDC Voltage Select
 *  0b0..Selects DCDCVSEL[VSEL0] level
 *  0b1..Selects DCDCVSEL[VSEL1] level
 */
#define PMC_PDSLEEPCFG0_DCDC_VSEL(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_DCDC_VSEL_SHIFT)) & PMC_PDSLEEPCFG0_DCDC_VSEL_MASK)

#define PMC_PDSLEEPCFG0_LDO1_MODE_MASK           (0xC000U)
#define PMC_PDSLEEPCFG0_LDO1_MODE_SHIFT          (14U)
/*! LDO1_MODE - LDO VDD1 Regulator Mode
 *  0b00..Bypass mode
 *  0b01..High-power mode
 *  0b10, 0b11..Low-power mode
 */
#define PMC_PDSLEEPCFG0_LDO1_MODE(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_LDO1_MODE_SHIFT)) & PMC_PDSLEEPCFG0_LDO1_MODE_MASK)

#define PMC_PDSLEEPCFG0_LDO1_VSEL_MASK           (0x30000U)
#define PMC_PDSLEEPCFG0_LDO1_VSEL_SHIFT          (16U)
/*! LDO1_VSEL - LDO VDD1 Voltage Select
 *  0b00..Selects LDOVDD1VSEL[VSEL0] and LVDVDD1CTRL[LVL0] level
 *  0b01..Selects LDOVDD1VSEL[VSEL1] and LVDVDD1CTRL[LVL1] level
 *  0b10..Selects LDOVDD1VSEL[VSEL2] and LVDVDD1CTRL[LVL2] level
 *  0b11..Selects LDOVDD1VSEL[VSEL3] and LVDVDD1CTRL[LVL3] level
 */
#define PMC_PDSLEEPCFG0_LDO1_VSEL(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_LDO1_VSEL_SHIFT)) & PMC_PDSLEEPCFG0_LDO1_VSEL_MASK)

#define PMC_PDSLEEPCFG0_LDO2_MODE_MASK           (0xC0000U)
#define PMC_PDSLEEPCFG0_LDO2_MODE_SHIFT          (18U)
/*! LDO2_MODE - LDO VDD2 Regulator Mode
 *  0b00..Bypass mode
 *  0b01..High-power mode
 *  0b10, 0b11..Low-power mode
 */
#define PMC_PDSLEEPCFG0_LDO2_MODE(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_LDO2_MODE_SHIFT)) & PMC_PDSLEEPCFG0_LDO2_MODE_MASK)

#define PMC_PDSLEEPCFG0_LDO2_VSEL_MASK           (0x300000U)
#define PMC_PDSLEEPCFG0_LDO2_VSEL_SHIFT          (20U)
/*! LDO2_VSEL - LDO VDD2 Voltage Select
 *  0b00..Selects LDOVDD2VSEL[VSEL0] and LVDVDD2CTRL[LVL0] level
 *  0b01..Selects LDOVDD2VSEL[VSEL1] and LVDVDD2CTRL[LVL1] level
 *  0b10..Selects LDOVDD2VSEL[VSEL2] and LVDVDD2CTRL[LVL2] level
 *  0b11..Selects LDOVDD2VSEL[VSEL3] and LVDVDD2CTRL[LVL3] level
 */
#define PMC_PDSLEEPCFG0_LDO2_VSEL(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_LDO2_VSEL_SHIFT)) & PMC_PDSLEEPCFG0_LDO2_VSEL_MASK)

#define PMC_PDSLEEPCFG0_RBB1_PD_MASK             (0x400000U)
#define PMC_PDSLEEPCFG0_RBB1_PD_SHIFT            (22U)
/*! RBB1_PD - Power Down RBB in VDD1 Domain
 *  0b0..If PDSLEEPCFG0[AFBB1_PD] = 1, power on. Else power down
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG0_RBB1_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_RBB1_PD_SHIFT)) & PMC_PDSLEEPCFG0_RBB1_PD_MASK)

#define PMC_PDSLEEPCFG0_AFBB1_PD_MASK            (0x800000U)
#define PMC_PDSLEEPCFG0_AFBB1_PD_SHIFT           (23U)
/*! AFBB1_PD - Power Down AFBB in VDD1 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG0_AFBB1_PD(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_AFBB1_PD_SHIFT)) & PMC_PDSLEEPCFG0_AFBB1_PD_MASK)

#define PMC_PDSLEEPCFG0_RBB2_PD_MASK             (0x1000000U)
#define PMC_PDSLEEPCFG0_RBB2_PD_SHIFT            (24U)
/*! RBB2_PD - Power Down RBB in VDD2 Domain
 *  0b0..If PDSLEEPCFG0[AFBB2_PD] = 1, power on. Else power down
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG0_RBB2_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_RBB2_PD_SHIFT)) & PMC_PDSLEEPCFG0_RBB2_PD_MASK)

#define PMC_PDSLEEPCFG0_AFBB2_PD_MASK            (0x2000000U)
#define PMC_PDSLEEPCFG0_AFBB2_PD_SHIFT           (25U)
/*! AFBB2_PD - Power Down AFBB in VDD2 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG0_AFBB2_PD(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_AFBB2_PD_SHIFT)) & PMC_PDSLEEPCFG0_AFBB2_PD_MASK)

#define PMC_PDSLEEPCFG0_RBBN_PD_MASK             (0x4000000U)
#define PMC_PDSLEEPCFG0_RBBN_PD_SHIFT            (26U)
/*! RBBN_PD - Power Down RBB in VDDN Domain
 *  0b0..If PDSLEEPCFG0[AFBBN_PD] = 1, power on. Else power down
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG0_RBBN_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_RBBN_PD_SHIFT)) & PMC_PDSLEEPCFG0_RBBN_PD_MASK)

#define PMC_PDSLEEPCFG0_AFBBN_PD_MASK            (0x8000000U)
#define PMC_PDSLEEPCFG0_AFBBN_PD_SHIFT           (27U)
/*! AFBBN_PD - Power Down AFBB in VDDN Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG0_AFBBN_PD(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_AFBBN_PD_SHIFT)) & PMC_PDSLEEPCFG0_AFBBN_PD_MASK)

#define PMC_PDSLEEPCFG0_RBBSR1_PD_MASK           (0x10000000U)
#define PMC_PDSLEEPCFG0_RBBSR1_PD_SHIFT          (28U)
/*! RBBSR1_PD - Power Down SRAM RBB in VDD1 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG0_RBBSR1_PD(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_RBBSR1_PD_SHIFT)) & PMC_PDSLEEPCFG0_RBBSR1_PD_MASK)

#define PMC_PDSLEEPCFG0_RBBSR2_PD_MASK           (0x20000000U)
#define PMC_PDSLEEPCFG0_RBBSR2_PD_SHIFT          (29U)
/*! RBBSR2_PD - Power Down SRAM RBB in VDD2 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG0_RBBSR2_PD(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG0_RBBSR2_PD_SHIFT)) & PMC_PDSLEEPCFG0_RBBSR2_PD_MASK)
/*! @} */

/*! @name PDSLEEPCFG1 - PD Sleep Configuration 1 in Compute Domain */
/*! @{ */

#define PMC_PDSLEEPCFG1_TEMP_PD_MASK             (0x1U)
#define PMC_PDSLEEPCFG1_TEMP_PD_SHIFT            (0U)
/*! TEMP_PD - PMC Temperature Sensor Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG1_TEMP_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_TEMP_PD_SHIFT)) & PMC_PDSLEEPCFG1_TEMP_PD_MASK)

#define PMC_PDSLEEPCFG1_PMCREF_LP_MASK           (0x2U)
#define PMC_PDSLEEPCFG1_PMCREF_LP_SHIFT          (1U)
/*! PMCREF_LP - PMC References Low Power
 *  0b0..High-power mode
 *  0b1..Low-power mode if not overridden by any *_PD bits
 */
#define PMC_PDSLEEPCFG1_PMCREF_LP(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_PMCREF_LP_SHIFT)) & PMC_PDSLEEPCFG1_PMCREF_LP_MASK)

#define PMC_PDSLEEPCFG1_HVD1V8_PD_MASK           (0x4U)
#define PMC_PDSLEEPCFG1_HVD1V8_PD_SHIFT          (2U)
/*! HVD1V8_PD - HVD VDD1V8 Power Down
 *  0b0..Power on. In this case the aggregated PDCFGSTATUS1[PMCREF_LP] bit will be in high-power mode
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG1_HVD1V8_PD(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_HVD1V8_PD_SHIFT)) & PMC_PDSLEEPCFG1_HVD1V8_PD_MASK)

#define PMC_PDSLEEPCFG1_POR1_LP_MASK             (0x8U)
#define PMC_PDSLEEPCFG1_POR1_LP_SHIFT            (3U)
/*! POR1_LP - POR Low Power in VDD1 Domain
 *  0b0..High-power mode. In this case the aggregated PDCFGSTATUS1[PMCREF_LP] bit will be in high-power mode
 *  0b1..Low-power mode
 */
#define PMC_PDSLEEPCFG1_POR1_LP(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_POR1_LP_SHIFT)) & PMC_PDSLEEPCFG1_POR1_LP_MASK)

#define PMC_PDSLEEPCFG1_LVD1_LP_MASK             (0x10U)
#define PMC_PDSLEEPCFG1_LVD1_LP_SHIFT            (4U)
/*! LVD1_LP - LVD Low power in VDD1 Domain
 *  0b0..High-power mode. In this case the aggregated PDCFGSTATUS1[PMCREF_LP] bit will be in high-power mode
 *  0b1..Low-power mode
 */
#define PMC_PDSLEEPCFG1_LVD1_LP(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_LVD1_LP_SHIFT)) & PMC_PDSLEEPCFG1_LVD1_LP_MASK)

#define PMC_PDSLEEPCFG1_HVD1_PD_MASK             (0x20U)
#define PMC_PDSLEEPCFG1_HVD1_PD_SHIFT            (5U)
/*! HVD1_PD - HVD Power Down in VDD1 Domain
 *  0b0..Power on. In this case the aggregated PDCFGSTATUS1[PMCREF_LP] bit will be in high-power mode
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG1_HVD1_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_HVD1_PD_SHIFT)) & PMC_PDSLEEPCFG1_HVD1_PD_MASK)

#define PMC_PDSLEEPCFG1_AGDET1_PD_MASK           (0x40U)
#define PMC_PDSLEEPCFG1_AGDET1_PD_SHIFT          (6U)
/*! AGDET1_PD - aGDET Power Down in VDD1 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG1_AGDET1_PD(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_AGDET1_PD_SHIFT)) & PMC_PDSLEEPCFG1_AGDET1_PD_MASK)

#define PMC_PDSLEEPCFG1_POR2_LP_MASK             (0x80U)
#define PMC_PDSLEEPCFG1_POR2_LP_SHIFT            (7U)
/*! POR2_LP - POR Low power in VDD2 Domain
 *  0b0..High-power mode. In this case the aggregated PDCFGSTATUS1[PMCREF_LP] bit will be in high-power mode
 *  0b1..Low-power mode
 */
#define PMC_PDSLEEPCFG1_POR2_LP(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_POR2_LP_SHIFT)) & PMC_PDSLEEPCFG1_POR2_LP_MASK)

#define PMC_PDSLEEPCFG1_LVD2_LP_MASK             (0x100U)
#define PMC_PDSLEEPCFG1_LVD2_LP_SHIFT            (8U)
/*! LVD2_LP - LVD Low power in VDD2 Domain
 *  0b0..High-power mode. In this case the aggregated PDCFGSTATUS1[PMCREF_LP] bit will be in high-power mode
 *  0b1..Low-power mode
 */
#define PMC_PDSLEEPCFG1_LVD2_LP(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_LVD2_LP_SHIFT)) & PMC_PDSLEEPCFG1_LVD2_LP_MASK)

#define PMC_PDSLEEPCFG1_HVD2_PD_MASK             (0x200U)
#define PMC_PDSLEEPCFG1_HVD2_PD_SHIFT            (9U)
/*! HVD2_PD - HVD Power Down in VDD2 Domain
 *  0b0..Power on. In this case the aggregated PDCFGSTATUS1[PMCREF_LP] bit will be in high-power mode
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG1_HVD2_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_HVD2_PD_SHIFT)) & PMC_PDSLEEPCFG1_HVD2_PD_MASK)

#define PMC_PDSLEEPCFG1_AGDET2_PD_MASK           (0x400U)
#define PMC_PDSLEEPCFG1_AGDET2_PD_SHIFT          (10U)
/*! AGDET2_PD - aGDET Power Down in VDD2 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG1_AGDET2_PD(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_AGDET2_PD_SHIFT)) & PMC_PDSLEEPCFG1_AGDET2_PD_MASK)

#define PMC_PDSLEEPCFG1_PORN_LP_MASK             (0x800U)
#define PMC_PDSLEEPCFG1_PORN_LP_SHIFT            (11U)
/*! PORN_LP - POR Low Power in VDDN Domain
 *  0b0..High-power mode. In this case the aggregated PDCFGSTATUS1[PMCREF_LP] bit will be in high-power mode
 *  0b1..Low-power mode
 */
#define PMC_PDSLEEPCFG1_PORN_LP(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_PORN_LP_SHIFT)) & PMC_PDSLEEPCFG1_PORN_LP_MASK)

#define PMC_PDSLEEPCFG1_LVDN_LP_MASK             (0x1000U)
#define PMC_PDSLEEPCFG1_LVDN_LP_SHIFT            (12U)
/*! LVDN_LP - LVD Low power in VDDN Domain
 *  0b0..High-power mode. In this case the aggregated PDCFGSTATUS1[PMCREF_LP] bit will be in high-power mode
 *  0b1..Low-power mode
 */
#define PMC_PDSLEEPCFG1_LVDN_LP(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_LVDN_LP_SHIFT)) & PMC_PDSLEEPCFG1_LVDN_LP_MASK)

#define PMC_PDSLEEPCFG1_HVDN_PD_MASK             (0x2000U)
#define PMC_PDSLEEPCFG1_HVDN_PD_SHIFT            (13U)
/*! HVDN_PD - HVD Power Down in VDDN Domain
 *  0b0..Power on. In this case the aggregated PDCFGSTATUS1[PMCREF_LP] bit will be in high-power mode
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG1_HVDN_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_HVDN_PD_SHIFT)) & PMC_PDSLEEPCFG1_HVDN_PD_MASK)

#define PMC_PDSLEEPCFG1_OTP_PD_MASK              (0x8000U)
#define PMC_PDSLEEPCFG1_OTP_PD_SHIFT             (15U)
/*! OTP_PD - OTP Power Down in VDD2 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG1_OTP_PD(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_OTP_PD_SHIFT)) & PMC_PDSLEEPCFG1_OTP_PD_MASK)

#define PMC_PDSLEEPCFG1_ROM_PD_MASK              (0x10000U)
#define PMC_PDSLEEPCFG1_ROM_PD_SHIFT             (16U)
/*! ROM_PD - ROM Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG1_ROM_PD(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_ROM_PD_SHIFT)) & PMC_PDSLEEPCFG1_ROM_PD_MASK)

#define PMC_PDSLEEPCFG1_SRAMSLEEP_MASK           (0x80000000U)
#define PMC_PDSLEEPCFG1_SRAMSLEEP_SHIFT          (31U)
/*! SRAMSLEEP - SRAM Sleep Mode
 *  0b0..Normal
 *  0b1..Sleep
 */
#define PMC_PDSLEEPCFG1_SRAMSLEEP(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG1_SRAMSLEEP_SHIFT)) & PMC_PDSLEEPCFG1_SRAMSLEEP_MASK)
/*! @} */

/*! @name PDSLEEPCFG2 - PD Sleep Configuration 2 in Compute Domain */
/*! @{ */

#define PMC_PDSLEEPCFG2_SRAM0_MASK               (0x1U)
#define PMC_PDSLEEPCFG2_SRAM0_SHIFT              (0U)
/*! SRAM0 - RAM Partition 0 Array Power Down
 *  0b0..Powers on RAM Partition 0 array
 *  0b1..Powers down RAM Partition 0 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM0(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM0_SHIFT)) & PMC_PDSLEEPCFG2_SRAM0_MASK)

#define PMC_PDSLEEPCFG2_SRAM1_MASK               (0x2U)
#define PMC_PDSLEEPCFG2_SRAM1_SHIFT              (1U)
/*! SRAM1 - RAM Partition 1 Array Power Down
 *  0b0..Powers on RAM Partition 1 array
 *  0b1..Powers down RAM Partition 1 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM1(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM1_SHIFT)) & PMC_PDSLEEPCFG2_SRAM1_MASK)

#define PMC_PDSLEEPCFG2_SRAM2_MASK               (0x4U)
#define PMC_PDSLEEPCFG2_SRAM2_SHIFT              (2U)
/*! SRAM2 - RAM Partition 2 Array Power Down
 *  0b0..Powers on RAM Partition 2 array
 *  0b1..Powers down RAM Partition 2 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM2(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM2_SHIFT)) & PMC_PDSLEEPCFG2_SRAM2_MASK)

#define PMC_PDSLEEPCFG2_SRAM3_MASK               (0x8U)
#define PMC_PDSLEEPCFG2_SRAM3_SHIFT              (3U)
/*! SRAM3 - RAM Partition 3 Array Power Down
 *  0b0..Powers on RAM Partition 3 array
 *  0b1..Powers down RAM Partition 3 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM3(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM3_SHIFT)) & PMC_PDSLEEPCFG2_SRAM3_MASK)

#define PMC_PDSLEEPCFG2_SRAM4_MASK               (0x10U)
#define PMC_PDSLEEPCFG2_SRAM4_SHIFT              (4U)
/*! SRAM4 - RAM Partition 4 Array Power Down
 *  0b0..Powers on RAM Partition 4 array
 *  0b1..Powers down RAM Partition 4 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM4(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM4_SHIFT)) & PMC_PDSLEEPCFG2_SRAM4_MASK)

#define PMC_PDSLEEPCFG2_SRAM5_MASK               (0x20U)
#define PMC_PDSLEEPCFG2_SRAM5_SHIFT              (5U)
/*! SRAM5 - RAM Partition 5 Array Power Down
 *  0b0..Powers on RAM Partition 5 array
 *  0b1..Powers down RAM Partition 5 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM5(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM5_SHIFT)) & PMC_PDSLEEPCFG2_SRAM5_MASK)

#define PMC_PDSLEEPCFG2_SRAM6_MASK               (0x40U)
#define PMC_PDSLEEPCFG2_SRAM6_SHIFT              (6U)
/*! SRAM6 - RAM Partition 6 Array Power Down
 *  0b0..Powers on RAM Partition 6 array
 *  0b1..Powers down RAM Partition 6 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM6(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM6_SHIFT)) & PMC_PDSLEEPCFG2_SRAM6_MASK)

#define PMC_PDSLEEPCFG2_SRAM7_MASK               (0x80U)
#define PMC_PDSLEEPCFG2_SRAM7_SHIFT              (7U)
/*! SRAM7 - RAM Partition 7 Array Power Down
 *  0b0..Powers on RAM Partition 7 array
 *  0b1..Powers down RAM Partition 7 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM7(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM7_SHIFT)) & PMC_PDSLEEPCFG2_SRAM7_MASK)

#define PMC_PDSLEEPCFG2_SRAM8_MASK               (0x100U)
#define PMC_PDSLEEPCFG2_SRAM8_SHIFT              (8U)
/*! SRAM8 - RAM Partition 8 Array Power Down
 *  0b0..Powers on RAM Partition 8 array
 *  0b1..Powers down RAM Partition 8 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM8(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM8_SHIFT)) & PMC_PDSLEEPCFG2_SRAM8_MASK)

#define PMC_PDSLEEPCFG2_SRAM9_MASK               (0x200U)
#define PMC_PDSLEEPCFG2_SRAM9_SHIFT              (9U)
/*! SRAM9 - RAM Partition 9 Array Power Down
 *  0b0..Powers on RAM Partition 9 array
 *  0b1..Powers down RAM Partition 9 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM9(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM9_SHIFT)) & PMC_PDSLEEPCFG2_SRAM9_MASK)

#define PMC_PDSLEEPCFG2_SRAM10_MASK              (0x400U)
#define PMC_PDSLEEPCFG2_SRAM10_SHIFT             (10U)
/*! SRAM10 - RAM Partition 10 Array Power Down
 *  0b0..Powers on RAM Partition 10 array
 *  0b1..Powers down RAM Partition 10 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM10(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM10_SHIFT)) & PMC_PDSLEEPCFG2_SRAM10_MASK)

#define PMC_PDSLEEPCFG2_SRAM11_MASK              (0x800U)
#define PMC_PDSLEEPCFG2_SRAM11_SHIFT             (11U)
/*! SRAM11 - RAM Partition 11 Array Power Down
 *  0b0..Powers on RAM Partition 11 array
 *  0b1..Powers down RAM Partition 11 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM11(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM11_SHIFT)) & PMC_PDSLEEPCFG2_SRAM11_MASK)

#define PMC_PDSLEEPCFG2_SRAM12_MASK              (0x1000U)
#define PMC_PDSLEEPCFG2_SRAM12_SHIFT             (12U)
/*! SRAM12 - RAM Partition 12 Array Power Down
 *  0b0..Powers on RAM Partition 12 array
 *  0b1..Powers down RAM Partition 12 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM12(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM12_SHIFT)) & PMC_PDSLEEPCFG2_SRAM12_MASK)

#define PMC_PDSLEEPCFG2_SRAM13_MASK              (0x2000U)
#define PMC_PDSLEEPCFG2_SRAM13_SHIFT             (13U)
/*! SRAM13 - RAM Partition 13 Array Power Down
 *  0b0..Powers on RAM Partition 13 array
 *  0b1..Powers down RAM Partition 13 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM13(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM13_SHIFT)) & PMC_PDSLEEPCFG2_SRAM13_MASK)

#define PMC_PDSLEEPCFG2_SRAM14_MASK              (0x4000U)
#define PMC_PDSLEEPCFG2_SRAM14_SHIFT             (14U)
/*! SRAM14 - RAM Partition 14 Array Power Down
 *  0b0..Powers on RAM Partition 14 array
 *  0b1..Powers down RAM Partition 14 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM14(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM14_SHIFT)) & PMC_PDSLEEPCFG2_SRAM14_MASK)

#define PMC_PDSLEEPCFG2_SRAM15_MASK              (0x8000U)
#define PMC_PDSLEEPCFG2_SRAM15_SHIFT             (15U)
/*! SRAM15 - RAM Partition 15 Array Power Down
 *  0b0..Powers on RAM Partition 15 array
 *  0b1..Powers down RAM Partition 15 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM15(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM15_SHIFT)) & PMC_PDSLEEPCFG2_SRAM15_MASK)

#define PMC_PDSLEEPCFG2_SRAM16_MASK              (0x10000U)
#define PMC_PDSLEEPCFG2_SRAM16_SHIFT             (16U)
/*! SRAM16 - RAM Partition 16 Array Power Down
 *  0b0..Powers on RAM Partition 16 array
 *  0b1..Powers down RAM Partition 16 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM16(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM16_SHIFT)) & PMC_PDSLEEPCFG2_SRAM16_MASK)

#define PMC_PDSLEEPCFG2_SRAM17_MASK              (0x20000U)
#define PMC_PDSLEEPCFG2_SRAM17_SHIFT             (17U)
/*! SRAM17 - RAM Partition 17 Array Power Down
 *  0b0..Powers on RAM Partition 17 array
 *  0b1..Powers down RAM Partition 17 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM17(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM17_SHIFT)) & PMC_PDSLEEPCFG2_SRAM17_MASK)

#define PMC_PDSLEEPCFG2_SRAM18_MASK              (0x40000U)
#define PMC_PDSLEEPCFG2_SRAM18_SHIFT             (18U)
/*! SRAM18 - RAM Partition 18 Array Power Down
 *  0b0..Powers on RAM Partition 18 array
 *  0b1..Powers down RAM Partition 18 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM18(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM18_SHIFT)) & PMC_PDSLEEPCFG2_SRAM18_MASK)

#define PMC_PDSLEEPCFG2_SRAM19_MASK              (0x80000U)
#define PMC_PDSLEEPCFG2_SRAM19_SHIFT             (19U)
/*! SRAM19 - RAM Partition 19 Array Power Down
 *  0b0..Powers on RAM Partition 19 array
 *  0b1..Powers down RAM Partition 19 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM19(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM19_SHIFT)) & PMC_PDSLEEPCFG2_SRAM19_MASK)

#define PMC_PDSLEEPCFG2_SRAM20_MASK              (0x100000U)
#define PMC_PDSLEEPCFG2_SRAM20_SHIFT             (20U)
/*! SRAM20 - RAM Partition 20 Array Power Down
 *  0b0..Powers on RAM Partition 20 array
 *  0b1..Powers down RAM Partition 20 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM20(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM20_SHIFT)) & PMC_PDSLEEPCFG2_SRAM20_MASK)

#define PMC_PDSLEEPCFG2_SRAM21_MASK              (0x200000U)
#define PMC_PDSLEEPCFG2_SRAM21_SHIFT             (21U)
/*! SRAM21 - RAM Partition 21 Array Power Down
 *  0b0..Powers on RAM Partition 21 array
 *  0b1..Powers down RAM Partition 21 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM21(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM21_SHIFT)) & PMC_PDSLEEPCFG2_SRAM21_MASK)

#define PMC_PDSLEEPCFG2_SRAM22_MASK              (0x400000U)
#define PMC_PDSLEEPCFG2_SRAM22_SHIFT             (22U)
/*! SRAM22 - RAM Partition 22 Array Power Down
 *  0b0..Powers on RAM Partition 22 array
 *  0b1..Powers down RAM Partition 22 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM22(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM22_SHIFT)) & PMC_PDSLEEPCFG2_SRAM22_MASK)

#define PMC_PDSLEEPCFG2_SRAM23_MASK              (0x800000U)
#define PMC_PDSLEEPCFG2_SRAM23_SHIFT             (23U)
/*! SRAM23 - RAM Partition 23 Array Power Down
 *  0b0..Powers on RAM Partition 23 array
 *  0b1..Powers down RAM Partition 23 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM23(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM23_SHIFT)) & PMC_PDSLEEPCFG2_SRAM23_MASK)

#define PMC_PDSLEEPCFG2_SRAM24_MASK              (0x1000000U)
#define PMC_PDSLEEPCFG2_SRAM24_SHIFT             (24U)
/*! SRAM24 - RAM Partition 24 Array Power Down
 *  0b0..Powers on RAM Partition 24 array
 *  0b1..Powers down RAM Partition 24 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM24(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM24_SHIFT)) & PMC_PDSLEEPCFG2_SRAM24_MASK)

#define PMC_PDSLEEPCFG2_SRAM25_MASK              (0x2000000U)
#define PMC_PDSLEEPCFG2_SRAM25_SHIFT             (25U)
/*! SRAM25 - RAM Partition 25 Array Power Down
 *  0b0..Powers on RAM Partition 25 array
 *  0b1..Powers down RAM Partition 25 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM25(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM25_SHIFT)) & PMC_PDSLEEPCFG2_SRAM25_MASK)

#define PMC_PDSLEEPCFG2_SRAM26_MASK              (0x4000000U)
#define PMC_PDSLEEPCFG2_SRAM26_SHIFT             (26U)
/*! SRAM26 - RAM Partition 26 Array Power Down
 *  0b0..Powers on RAM Partition 26 array
 *  0b1..Powers down RAM Partition 26 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM26(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM26_SHIFT)) & PMC_PDSLEEPCFG2_SRAM26_MASK)

#define PMC_PDSLEEPCFG2_SRAM27_MASK              (0x8000000U)
#define PMC_PDSLEEPCFG2_SRAM27_SHIFT             (27U)
/*! SRAM27 - RAM Partition 27 Array Power Down
 *  0b0..Powers on RAM Partition 27 array
 *  0b1..Powers down RAM Partition 27 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM27(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM27_SHIFT)) & PMC_PDSLEEPCFG2_SRAM27_MASK)

#define PMC_PDSLEEPCFG2_SRAM28_MASK              (0x10000000U)
#define PMC_PDSLEEPCFG2_SRAM28_SHIFT             (28U)
/*! SRAM28 - RAM Partition 28 Array Power Down
 *  0b0..Powers on RAM Partition 28 array
 *  0b1..Powers down RAM Partition 28 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM28(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM28_SHIFT)) & PMC_PDSLEEPCFG2_SRAM28_MASK)

#define PMC_PDSLEEPCFG2_SRAM29_MASK              (0x20000000U)
#define PMC_PDSLEEPCFG2_SRAM29_SHIFT             (29U)
/*! SRAM29 - RAM Partition 29 Array Power Down
 *  0b0..Powers on RAM Partition 29 array
 *  0b1..Powers down RAM Partition 29 array and periphery
 */
#define PMC_PDSLEEPCFG2_SRAM29(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG2_SRAM29_SHIFT)) & PMC_PDSLEEPCFG2_SRAM29_MASK)
/*! @} */

/*! @name PDSLEEPCFG3 - PD Sleep Configuration 3 in Compute Domain */
/*! @{ */

#define PMC_PDSLEEPCFG3_SRAM0_MASK               (0x1U)
#define PMC_PDSLEEPCFG3_SRAM0_SHIFT              (0U)
/*! SRAM0 - RAM Partition 0 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM0(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM0_SHIFT)) & PMC_PDSLEEPCFG3_SRAM0_MASK)

#define PMC_PDSLEEPCFG3_SRAM1_MASK               (0x2U)
#define PMC_PDSLEEPCFG3_SRAM1_SHIFT              (1U)
/*! SRAM1 - RAM Partition 1 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM1(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM1_SHIFT)) & PMC_PDSLEEPCFG3_SRAM1_MASK)

#define PMC_PDSLEEPCFG3_SRAM2_MASK               (0x4U)
#define PMC_PDSLEEPCFG3_SRAM2_SHIFT              (2U)
/*! SRAM2 - RAM Partition 2 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM2(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM2_SHIFT)) & PMC_PDSLEEPCFG3_SRAM2_MASK)

#define PMC_PDSLEEPCFG3_SRAM3_MASK               (0x8U)
#define PMC_PDSLEEPCFG3_SRAM3_SHIFT              (3U)
/*! SRAM3 - RAM Partition 3 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM3(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM3_SHIFT)) & PMC_PDSLEEPCFG3_SRAM3_MASK)

#define PMC_PDSLEEPCFG3_SRAM4_MASK               (0x10U)
#define PMC_PDSLEEPCFG3_SRAM4_SHIFT              (4U)
/*! SRAM4 - RAM Partition 4 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM4(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM4_SHIFT)) & PMC_PDSLEEPCFG3_SRAM4_MASK)

#define PMC_PDSLEEPCFG3_SRAM5_MASK               (0x20U)
#define PMC_PDSLEEPCFG3_SRAM5_SHIFT              (5U)
/*! SRAM5 - RAM Partition 5 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM5(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM5_SHIFT)) & PMC_PDSLEEPCFG3_SRAM5_MASK)

#define PMC_PDSLEEPCFG3_SRAM6_MASK               (0x40U)
#define PMC_PDSLEEPCFG3_SRAM6_SHIFT              (6U)
/*! SRAM6 - RAM Partition 6 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM6(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM6_SHIFT)) & PMC_PDSLEEPCFG3_SRAM6_MASK)

#define PMC_PDSLEEPCFG3_SRAM7_MASK               (0x80U)
#define PMC_PDSLEEPCFG3_SRAM7_SHIFT              (7U)
/*! SRAM7 - RAM Partition 7 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM7(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM7_SHIFT)) & PMC_PDSLEEPCFG3_SRAM7_MASK)

#define PMC_PDSLEEPCFG3_SRAM8_MASK               (0x100U)
#define PMC_PDSLEEPCFG3_SRAM8_SHIFT              (8U)
/*! SRAM8 - RAM Partition 8 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM8(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM8_SHIFT)) & PMC_PDSLEEPCFG3_SRAM8_MASK)

#define PMC_PDSLEEPCFG3_SRAM9_MASK               (0x200U)
#define PMC_PDSLEEPCFG3_SRAM9_SHIFT              (9U)
/*! SRAM9 - RAM Partition 9 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM9(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM9_SHIFT)) & PMC_PDSLEEPCFG3_SRAM9_MASK)

#define PMC_PDSLEEPCFG3_SRAM10_MASK              (0x400U)
#define PMC_PDSLEEPCFG3_SRAM10_SHIFT             (10U)
/*! SRAM10 - RAM Partition 10 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM10(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM10_SHIFT)) & PMC_PDSLEEPCFG3_SRAM10_MASK)

#define PMC_PDSLEEPCFG3_SRAM11_MASK              (0x800U)
#define PMC_PDSLEEPCFG3_SRAM11_SHIFT             (11U)
/*! SRAM11 - RAM Partition 11 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM11(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM11_SHIFT)) & PMC_PDSLEEPCFG3_SRAM11_MASK)

#define PMC_PDSLEEPCFG3_SRAM12_MASK              (0x1000U)
#define PMC_PDSLEEPCFG3_SRAM12_SHIFT             (12U)
/*! SRAM12 - RAM Partition 12 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM12(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM12_SHIFT)) & PMC_PDSLEEPCFG3_SRAM12_MASK)

#define PMC_PDSLEEPCFG3_SRAM13_MASK              (0x2000U)
#define PMC_PDSLEEPCFG3_SRAM13_SHIFT             (13U)
/*! SRAM13 - RAM Partition 13 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM13(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM13_SHIFT)) & PMC_PDSLEEPCFG3_SRAM13_MASK)

#define PMC_PDSLEEPCFG3_SRAM14_MASK              (0x4000U)
#define PMC_PDSLEEPCFG3_SRAM14_SHIFT             (14U)
/*! SRAM14 - RAM Partition 14 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM14(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM14_SHIFT)) & PMC_PDSLEEPCFG3_SRAM14_MASK)

#define PMC_PDSLEEPCFG3_SRAM15_MASK              (0x8000U)
#define PMC_PDSLEEPCFG3_SRAM15_SHIFT             (15U)
/*! SRAM15 - RAM Partition 15 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM15(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM15_SHIFT)) & PMC_PDSLEEPCFG3_SRAM15_MASK)

#define PMC_PDSLEEPCFG3_SRAM16_MASK              (0x10000U)
#define PMC_PDSLEEPCFG3_SRAM16_SHIFT             (16U)
/*! SRAM16 - RAM Partition 16 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM16(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM16_SHIFT)) & PMC_PDSLEEPCFG3_SRAM16_MASK)

#define PMC_PDSLEEPCFG3_SRAM17_MASK              (0x20000U)
#define PMC_PDSLEEPCFG3_SRAM17_SHIFT             (17U)
/*! SRAM17 - RAM Partition 17 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM17(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM17_SHIFT)) & PMC_PDSLEEPCFG3_SRAM17_MASK)

#define PMC_PDSLEEPCFG3_SRAM18_MASK              (0x40000U)
#define PMC_PDSLEEPCFG3_SRAM18_SHIFT             (18U)
/*! SRAM18 - RAM Partition 18 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM18(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM18_SHIFT)) & PMC_PDSLEEPCFG3_SRAM18_MASK)

#define PMC_PDSLEEPCFG3_SRAM19_MASK              (0x80000U)
#define PMC_PDSLEEPCFG3_SRAM19_SHIFT             (19U)
/*! SRAM19 - RAM Partition 19 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM19(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM19_SHIFT)) & PMC_PDSLEEPCFG3_SRAM19_MASK)

#define PMC_PDSLEEPCFG3_SRAM20_MASK              (0x100000U)
#define PMC_PDSLEEPCFG3_SRAM20_SHIFT             (20U)
/*! SRAM20 - RAM Partition 20 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM20(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM20_SHIFT)) & PMC_PDSLEEPCFG3_SRAM20_MASK)

#define PMC_PDSLEEPCFG3_SRAM21_MASK              (0x200000U)
#define PMC_PDSLEEPCFG3_SRAM21_SHIFT             (21U)
/*! SRAM21 - RAM Partition 21 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM21(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM21_SHIFT)) & PMC_PDSLEEPCFG3_SRAM21_MASK)

#define PMC_PDSLEEPCFG3_SRAM22_MASK              (0x400000U)
#define PMC_PDSLEEPCFG3_SRAM22_SHIFT             (22U)
/*! SRAM22 - RAM Partition 22 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM22(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM22_SHIFT)) & PMC_PDSLEEPCFG3_SRAM22_MASK)

#define PMC_PDSLEEPCFG3_SRAM23_MASK              (0x800000U)
#define PMC_PDSLEEPCFG3_SRAM23_SHIFT             (23U)
/*! SRAM23 - RAM Partition 23 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM23(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM23_SHIFT)) & PMC_PDSLEEPCFG3_SRAM23_MASK)

#define PMC_PDSLEEPCFG3_SRAM24_MASK              (0x1000000U)
#define PMC_PDSLEEPCFG3_SRAM24_SHIFT             (24U)
/*! SRAM24 - RAM Partition 24 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM24(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM24_SHIFT)) & PMC_PDSLEEPCFG3_SRAM24_MASK)

#define PMC_PDSLEEPCFG3_SRAM25_MASK              (0x2000000U)
#define PMC_PDSLEEPCFG3_SRAM25_SHIFT             (25U)
/*! SRAM25 - RAM Partition 25 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM25(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM25_SHIFT)) & PMC_PDSLEEPCFG3_SRAM25_MASK)

#define PMC_PDSLEEPCFG3_SRAM26_MASK              (0x4000000U)
#define PMC_PDSLEEPCFG3_SRAM26_SHIFT             (26U)
/*! SRAM26 - RAM Partition 26 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM26(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM26_SHIFT)) & PMC_PDSLEEPCFG3_SRAM26_MASK)

#define PMC_PDSLEEPCFG3_SRAM27_MASK              (0x8000000U)
#define PMC_PDSLEEPCFG3_SRAM27_SHIFT             (27U)
/*! SRAM27 - RAM Partition 27 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM27(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM27_SHIFT)) & PMC_PDSLEEPCFG3_SRAM27_MASK)

#define PMC_PDSLEEPCFG3_SRAM28_MASK              (0x10000000U)
#define PMC_PDSLEEPCFG3_SRAM28_SHIFT             (28U)
/*! SRAM28 - RAM Partition 28 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM28(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM28_SHIFT)) & PMC_PDSLEEPCFG3_SRAM28_MASK)

#define PMC_PDSLEEPCFG3_SRAM29_MASK              (0x20000000U)
#define PMC_PDSLEEPCFG3_SRAM29_SHIFT             (29U)
/*! SRAM29 - RAM Partition 29 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG3_SRAM29(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG3_SRAM29_SHIFT)) & PMC_PDSLEEPCFG3_SRAM29_MASK)
/*! @} */

/*! @name PDSLEEPCFG4 - PD Sleep Configuration 4 in Compute Domain */
/*! @{ */

#define PMC_PDSLEEPCFG4_SDHC0_SRAM_MASK          (0x1U)
#define PMC_PDSLEEPCFG4_SDHC0_SRAM_SHIFT         (0U)
/*! SDHC0_SRAM - uSDHC0 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_SDHC0_SRAM(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_SDHC0_SRAM_SHIFT)) & PMC_PDSLEEPCFG4_SDHC0_SRAM_MASK)

#define PMC_PDSLEEPCFG4_SDHC1_SRAM_MASK          (0x2U)
#define PMC_PDSLEEPCFG4_SDHC1_SRAM_SHIFT         (1U)
/*! SDHC1_SRAM - uSDHC1 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_SDHC1_SRAM(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_SDHC1_SRAM_SHIFT)) & PMC_PDSLEEPCFG4_SDHC1_SRAM_MASK)

#define PMC_PDSLEEPCFG4_USB0_SRAM_MASK           (0x4U)
#define PMC_PDSLEEPCFG4_USB0_SRAM_SHIFT          (2U)
/*! USB0_SRAM - USB0 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_USB0_SRAM(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_USB0_SRAM_SHIFT)) & PMC_PDSLEEPCFG4_USB0_SRAM_MASK)

#define PMC_PDSLEEPCFG4_USB1_SRAM_MASK           (0x8U)
#define PMC_PDSLEEPCFG4_USB1_SRAM_SHIFT          (3U)
/*! USB1_SRAM - USB1 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_USB1_SRAM(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_USB1_SRAM_SHIFT)) & PMC_PDSLEEPCFG4_USB1_SRAM_MASK)

#define PMC_PDSLEEPCFG4_JPEG_MASK                (0x10U)
#define PMC_PDSLEEPCFG4_JPEG_SHIFT               (4U)
/*! JPEG - JPEGDEC
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_JPEG(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_JPEG_SHIFT)) & PMC_PDSLEEPCFG4_JPEG_MASK)

#define PMC_PDSLEEPCFG4_PNG_MASK                 (0x20U)
#define PMC_PDSLEEPCFG4_PNG_SHIFT                (5U)
/*! PNG - PNGDEC
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_PNG(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_PNG_SHIFT)) & PMC_PDSLEEPCFG4_PNG_MASK)

#define PMC_PDSLEEPCFG4_MIPI_MASK                (0x40U)
#define PMC_PDSLEEPCFG4_MIPI_SHIFT               (6U)
/*! MIPI - MIPI PHY
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_MIPI(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_MIPI_SHIFT)) & PMC_PDSLEEPCFG4_MIPI_MASK)

#define PMC_PDSLEEPCFG4_GPU_MASK                 (0x80U)
#define PMC_PDSLEEPCFG4_GPU_SHIFT                (7U)
/*! GPU - VGPU
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_GPU(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_GPU_SHIFT)) & PMC_PDSLEEPCFG4_GPU_MASK)

#define PMC_PDSLEEPCFG4_DMA2_3_MASK              (0x100U)
#define PMC_PDSLEEPCFG4_DMA2_3_SHIFT             (8U)
/*! DMA2_3 - DMA2 and DMA3
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_DMA2_3(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_DMA2_3_SHIFT)) & PMC_PDSLEEPCFG4_DMA2_3_MASK)

#define PMC_PDSLEEPCFG4_DMA0_1_P_E_MASK          (0x200U)
#define PMC_PDSLEEPCFG4_DMA0_1_P_E_SHIFT         (9U)
/*! DMA0_1_P_E - DMA0-1, PKC, and ETF
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_DMA0_1_P_E(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_DMA0_1_P_E_SHIFT)) & PMC_PDSLEEPCFG4_DMA0_1_P_E_MASK)

#define PMC_PDSLEEPCFG4_CPU0_CCACHE_MASK         (0x400U)
#define PMC_PDSLEEPCFG4_CPU0_CCACHE_SHIFT        (10U)
/*! CPU0_CCACHE - CPU0 Code Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_CPU0_CCACHE(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_CPU0_CCACHE_SHIFT)) & PMC_PDSLEEPCFG4_CPU0_CCACHE_MASK)

#define PMC_PDSLEEPCFG4_CPU0_SCACHE_MASK         (0x800U)
#define PMC_PDSLEEPCFG4_CPU0_SCACHE_SHIFT        (11U)
/*! CPU0_SCACHE - CPU0 System Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_CPU0_SCACHE(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_CPU0_SCACHE_SHIFT)) & PMC_PDSLEEPCFG4_CPU0_SCACHE_MASK)

#define PMC_PDSLEEPCFG4_DSP_ICACHE_MASK          (0x1000U)
#define PMC_PDSLEEPCFG4_DSP_ICACHE_SHIFT         (12U)
/*! DSP_ICACHE - HiFi4 Instruction Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_DSP_ICACHE(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_DSP_ICACHE_SHIFT)) & PMC_PDSLEEPCFG4_DSP_ICACHE_MASK)

#define PMC_PDSLEEPCFG4_DSP_DCACHE_MASK          (0x2000U)
#define PMC_PDSLEEPCFG4_DSP_DCACHE_SHIFT         (13U)
/*! DSP_DCACHE - HiFi4 Data Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_DSP_DCACHE(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_DSP_DCACHE_SHIFT)) & PMC_PDSLEEPCFG4_DSP_DCACHE_MASK)

#define PMC_PDSLEEPCFG4_DSP_ITCM_MASK            (0x4000U)
#define PMC_PDSLEEPCFG4_DSP_ITCM_SHIFT           (14U)
/*! DSP_ITCM - HiFi4 Instruction TCM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_DSP_ITCM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_DSP_ITCM_SHIFT)) & PMC_PDSLEEPCFG4_DSP_ITCM_MASK)

#define PMC_PDSLEEPCFG4_DSP_DTCM_MASK            (0x8000U)
#define PMC_PDSLEEPCFG4_DSP_DTCM_SHIFT           (15U)
/*! DSP_DTCM - HiFi4 Data TCM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_DSP_DTCM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_DSP_DTCM_SHIFT)) & PMC_PDSLEEPCFG4_DSP_DTCM_MASK)

#define PMC_PDSLEEPCFG4_EZH_TCM_MASK             (0x10000U)
#define PMC_PDSLEEPCFG4_EZH_TCM_SHIFT            (16U)
/*! EZH_TCM - EZH-V TCM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_EZH_TCM(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_EZH_TCM_SHIFT)) & PMC_PDSLEEPCFG4_EZH_TCM_MASK)

#define PMC_PDSLEEPCFG4_NPU_MASK                 (0x20000U)
#define PMC_PDSLEEPCFG4_NPU_SHIFT                (17U)
/*! NPU - NPU
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_NPU(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_NPU_SHIFT)) & PMC_PDSLEEPCFG4_NPU_MASK)

#define PMC_PDSLEEPCFG4_XSPI0_MASK               (0x40000U)
#define PMC_PDSLEEPCFG4_XSPI0_SHIFT              (18U)
/*! XSPI0 - XSPI0, MMU0, and Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_XSPI0(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_XSPI0_SHIFT)) & PMC_PDSLEEPCFG4_XSPI0_MASK)

#define PMC_PDSLEEPCFG4_XSPI1_MASK               (0x80000U)
#define PMC_PDSLEEPCFG4_XSPI1_SHIFT              (19U)
/*! XSPI1 - XSPI1, MMU1, and Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_XSPI1(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_XSPI1_SHIFT)) & PMC_PDSLEEPCFG4_XSPI1_MASK)

#define PMC_PDSLEEPCFG4_XSPI2_MASK               (0x100000U)
#define PMC_PDSLEEPCFG4_XSPI2_SHIFT              (20U)
/*! XSPI2 - XSPI2 and MMU2
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_XSPI2(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_XSPI2_SHIFT)) & PMC_PDSLEEPCFG4_XSPI2_MASK)

#define PMC_PDSLEEPCFG4_LCD_MASK                 (0x200000U)
#define PMC_PDSLEEPCFG4_LCD_SHIFT                (21U)
/*! LCD - LCDIF
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_LCD(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_LCD_SHIFT)) & PMC_PDSLEEPCFG4_LCD_MASK)

#define PMC_PDSLEEPCFG4_OCOTP_MASK               (0x400000U)
#define PMC_PDSLEEPCFG4_OCOTP_SHIFT              (22U)
/*! OCOTP - OCOTP Shadow SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG4_OCOTP(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG4_OCOTP_SHIFT)) & PMC_PDSLEEPCFG4_OCOTP_MASK)
/*! @} */

/*! @name PDSLEEPCFG5 - PD Sleep Configuration 5 in Compute Domain */
/*! @{ */

#define PMC_PDSLEEPCFG5_SDHC0_SRAM_MASK          (0x1U)
#define PMC_PDSLEEPCFG5_SDHC0_SRAM_SHIFT         (0U)
/*! SDHC0_SRAM - uSDHC0 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_SDHC0_SRAM(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_SDHC0_SRAM_SHIFT)) & PMC_PDSLEEPCFG5_SDHC0_SRAM_MASK)

#define PMC_PDSLEEPCFG5_SDHC1_SRAM_MASK          (0x2U)
#define PMC_PDSLEEPCFG5_SDHC1_SRAM_SHIFT         (1U)
/*! SDHC1_SRAM - uSDHC1 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_SDHC1_SRAM(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_SDHC1_SRAM_SHIFT)) & PMC_PDSLEEPCFG5_SDHC1_SRAM_MASK)

#define PMC_PDSLEEPCFG5_USB0_SRAM_MASK           (0x4U)
#define PMC_PDSLEEPCFG5_USB0_SRAM_SHIFT          (2U)
/*! USB0_SRAM - USB0 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_USB0_SRAM(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_USB0_SRAM_SHIFT)) & PMC_PDSLEEPCFG5_USB0_SRAM_MASK)

#define PMC_PDSLEEPCFG5_USB1_SRAM_MASK           (0x8U)
#define PMC_PDSLEEPCFG5_USB1_SRAM_SHIFT          (3U)
/*! USB1_SRAM - USB1 SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_USB1_SRAM(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_USB1_SRAM_SHIFT)) & PMC_PDSLEEPCFG5_USB1_SRAM_MASK)

#define PMC_PDSLEEPCFG5_JPEG_MASK                (0x10U)
#define PMC_PDSLEEPCFG5_JPEG_SHIFT               (4U)
/*! JPEG - JPEGDEC
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_JPEG(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_JPEG_SHIFT)) & PMC_PDSLEEPCFG5_JPEG_MASK)

#define PMC_PDSLEEPCFG5_PNG_MASK                 (0x20U)
#define PMC_PDSLEEPCFG5_PNG_SHIFT                (5U)
/*! PNG - PNGDEC
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_PNG(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_PNG_SHIFT)) & PMC_PDSLEEPCFG5_PNG_MASK)

#define PMC_PDSLEEPCFG5_MIPI_MASK                (0x40U)
#define PMC_PDSLEEPCFG5_MIPI_SHIFT               (6U)
/*! MIPI - MIPI PHY
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_MIPI(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_MIPI_SHIFT)) & PMC_PDSLEEPCFG5_MIPI_MASK)

#define PMC_PDSLEEPCFG5_GPU_MASK                 (0x80U)
#define PMC_PDSLEEPCFG5_GPU_SHIFT                (7U)
/*! GPU - VGPU
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_GPU(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_GPU_SHIFT)) & PMC_PDSLEEPCFG5_GPU_MASK)

#define PMC_PDSLEEPCFG5_DMA2_3_MASK              (0x100U)
#define PMC_PDSLEEPCFG5_DMA2_3_SHIFT             (8U)
/*! DMA2_3 - DMA2 and DMA3
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_DMA2_3(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_DMA2_3_SHIFT)) & PMC_PDSLEEPCFG5_DMA2_3_MASK)

#define PMC_PDSLEEPCFG5_DMA0_1_P_E_MASK          (0x200U)
#define PMC_PDSLEEPCFG5_DMA0_1_P_E_SHIFT         (9U)
/*! DMA0_1_P_E - DMA0-1, PKC, and ETF
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_DMA0_1_P_E(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_DMA0_1_P_E_SHIFT)) & PMC_PDSLEEPCFG5_DMA0_1_P_E_MASK)

#define PMC_PDSLEEPCFG5_CPU0_CCACHE_MASK         (0x400U)
#define PMC_PDSLEEPCFG5_CPU0_CCACHE_SHIFT        (10U)
/*! CPU0_CCACHE - CPU0 Code Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_CPU0_CCACHE(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_CPU0_CCACHE_SHIFT)) & PMC_PDSLEEPCFG5_CPU0_CCACHE_MASK)

#define PMC_PDSLEEPCFG5_CPU0_SCACHE_MASK         (0x800U)
#define PMC_PDSLEEPCFG5_CPU0_SCACHE_SHIFT        (11U)
/*! CPU0_SCACHE - CPU0 System Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_CPU0_SCACHE(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_CPU0_SCACHE_SHIFT)) & PMC_PDSLEEPCFG5_CPU0_SCACHE_MASK)

#define PMC_PDSLEEPCFG5_DSP_ICACHE_MASK          (0x1000U)
#define PMC_PDSLEEPCFG5_DSP_ICACHE_SHIFT         (12U)
/*! DSP_ICACHE - HiFi4 Instruction Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_DSP_ICACHE(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_DSP_ICACHE_SHIFT)) & PMC_PDSLEEPCFG5_DSP_ICACHE_MASK)

#define PMC_PDSLEEPCFG5_DSP_DCACHE_MASK          (0x2000U)
#define PMC_PDSLEEPCFG5_DSP_DCACHE_SHIFT         (13U)
/*! DSP_DCACHE - HiFi4 Data Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_DSP_DCACHE(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_DSP_DCACHE_SHIFT)) & PMC_PDSLEEPCFG5_DSP_DCACHE_MASK)

#define PMC_PDSLEEPCFG5_DSP_ITCM_MASK            (0x4000U)
#define PMC_PDSLEEPCFG5_DSP_ITCM_SHIFT           (14U)
/*! DSP_ITCM - HiFi4 Instruction TCM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_DSP_ITCM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_DSP_ITCM_SHIFT)) & PMC_PDSLEEPCFG5_DSP_ITCM_MASK)

#define PMC_PDSLEEPCFG5_DSP_DTCM_MASK            (0x8000U)
#define PMC_PDSLEEPCFG5_DSP_DTCM_SHIFT           (15U)
/*! DSP_DTCM - HiFi4 Data TCM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_DSP_DTCM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_DSP_DTCM_SHIFT)) & PMC_PDSLEEPCFG5_DSP_DTCM_MASK)

#define PMC_PDSLEEPCFG5_EZH_TCM_MASK             (0x10000U)
#define PMC_PDSLEEPCFG5_EZH_TCM_SHIFT            (16U)
/*! EZH_TCM - EZH-V TCM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_EZH_TCM(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_EZH_TCM_SHIFT)) & PMC_PDSLEEPCFG5_EZH_TCM_MASK)

#define PMC_PDSLEEPCFG5_NPU_MASK                 (0x20000U)
#define PMC_PDSLEEPCFG5_NPU_SHIFT                (17U)
/*! NPU - NPU
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_NPU(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_NPU_SHIFT)) & PMC_PDSLEEPCFG5_NPU_MASK)

#define PMC_PDSLEEPCFG5_XSPI0_MASK               (0x40000U)
#define PMC_PDSLEEPCFG5_XSPI0_SHIFT              (18U)
/*! XSPI0 - XSPI0, MMU0, and Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_XSPI0(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_XSPI0_SHIFT)) & PMC_PDSLEEPCFG5_XSPI0_MASK)

#define PMC_PDSLEEPCFG5_XSPI1_MASK               (0x80000U)
#define PMC_PDSLEEPCFG5_XSPI1_SHIFT              (19U)
/*! XSPI1 - XSPI1, MMU1, and Cache
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_XSPI1(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_XSPI1_SHIFT)) & PMC_PDSLEEPCFG5_XSPI1_MASK)

#define PMC_PDSLEEPCFG5_XSPI2_MASK               (0x100000U)
#define PMC_PDSLEEPCFG5_XSPI2_SHIFT              (20U)
/*! XSPI2 - XSPI2 and MMU2
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_XSPI2(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_XSPI2_SHIFT)) & PMC_PDSLEEPCFG5_XSPI2_MASK)

#define PMC_PDSLEEPCFG5_LCD_MASK                 (0x200000U)
#define PMC_PDSLEEPCFG5_LCD_SHIFT                (21U)
/*! LCD - LCDIF
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_LCD(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_LCD_SHIFT)) & PMC_PDSLEEPCFG5_LCD_MASK)

#define PMC_PDSLEEPCFG5_OCOTP_MASK               (0x400000U)
#define PMC_PDSLEEPCFG5_OCOTP_SHIFT              (22U)
/*! OCOTP - OCOTP Shadow SRAM
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDSLEEPCFG5_OCOTP(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDSLEEPCFG5_OCOTP_SHIFT)) & PMC_PDSLEEPCFG5_OCOTP_MASK)
/*! @} */

/*! @name PDCFGSTATUS0 - PD Configuration Status 0 */
/*! @{ */

#define PMC_PDCFGSTATUS0_PMICMODE_MASK           (0x3U)
#define PMC_PDCFGSTATUS0_PMICMODE_SHIFT          (0U)
/*! PMICMODE - PMIC_MODE Output Value
 *  0b00..PMIC_MODE[1:0] pins = 00
 *  0b01..PMIC_MODE[1:0] pins = 01
 *  0b10..PMIC_MODE[1:0] pins = 10
 *  0b11..PMIC_MODE[1:0] pins = 11
 */
#define PMC_PDCFGSTATUS0_PMICMODE(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_PMICMODE_SHIFT)) & PMC_PDCFGSTATUS0_PMICMODE_MASK)

#define PMC_PDCFGSTATUS0_FDSR_MASK               (0x4U)
#define PMC_PDCFGSTATUS0_FDSR_SHIFT              (2U)
/*! FDSR - FDSR Mode
 *  0b0..Power switches and DSR status are determined by the single power domain controls
 *  0b1..All core domains are in FDSR mode or power down
 */
#define PMC_PDCFGSTATUS0_FDSR(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_FDSR_SHIFT)) & PMC_PDCFGSTATUS0_FDSR_MASK)

#define PMC_PDCFGSTATUS0_DPD_MASK                (0x8U)
#define PMC_PDCFGSTATUS0_DPD_SHIFT               (3U)
/*! DPD - DPD Mode
 *  0b0..Enables
 *  0b1..Activates isolation and correct sequencing for DPD mode
 */
#define PMC_PDCFGSTATUS0_DPD(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_DPD_SHIFT)) & PMC_PDCFGSTATUS0_DPD_MASK)

#define PMC_PDCFGSTATUS0_FDPD_MASK               (0x10U)
#define PMC_PDCFGSTATUS0_FDPD_SHIFT              (4U)
/*! FDPD - FDPD Mode
 *  0b0..Enables
 *  0b1..Activates isolation and correct sequencing for FDPD mode
 */
#define PMC_PDCFGSTATUS0_FDPD(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_FDPD_SHIFT)) & PMC_PDCFGSTATUS0_FDPD_MASK)

#define PMC_PDCFGSTATUS0_V2COMP_DSR_MASK         (0x20U)
#define PMC_PDCFGSTATUS0_V2COMP_DSR_SHIFT        (5U)
/*! V2COMP_DSR - DSR of VDD2_COMP Domain
 *  0b0..Power on
 *  0b1..DSR mode
 */
#define PMC_PDCFGSTATUS0_V2COMP_DSR(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_V2COMP_DSR_SHIFT)) & PMC_PDCFGSTATUS0_V2COMP_DSR_MASK)

#define PMC_PDCFGSTATUS0_V2NMED_DSR_MASK         (0x40U)
#define PMC_PDCFGSTATUS0_V2NMED_DSR_SHIFT        (6U)
/*! V2NMED_DSR - DSR of VDD2_MEDIA and VDDN_MEDIA Domains
 *  0b0..Power on
 *  0b1..DSR mode
 */
#define PMC_PDCFGSTATUS0_V2NMED_DSR(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_V2NMED_DSR_SHIFT)) & PMC_PDCFGSTATUS0_V2NMED_DSR_MASK)

#define PMC_PDCFGSTATUS0_V2COM_DSR_MASK          (0x80U)
#define PMC_PDCFGSTATUS0_V2COM_DSR_SHIFT         (7U)
/*! V2COM_DSR - DSR of VDD2_COM Domain
 *  0b0..Power on
 *  0b1..DSR mode
 */
#define PMC_PDCFGSTATUS0_V2COM_DSR(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_V2COM_DSR_SHIFT)) & PMC_PDCFGSTATUS0_V2COM_DSR_MASK)

#define PMC_PDCFGSTATUS0_VNCOM_DSR_MASK          (0x100U)
#define PMC_PDCFGSTATUS0_VNCOM_DSR_SHIFT         (8U)
/*! VNCOM_DSR - DSR of VDDN_COM Domain
 *  0b0..Power on
 *  0b1..DSR mode
 */
#define PMC_PDCFGSTATUS0_VNCOM_DSR(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_VNCOM_DSR_SHIFT)) & PMC_PDCFGSTATUS0_VNCOM_DSR_MASK)

#define PMC_PDCFGSTATUS0_V2DSP_PD_MASK           (0x200U)
#define PMC_PDCFGSTATUS0_V2DSP_PD_SHIFT          (9U)
/*! V2DSP_PD - HiFi4 Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS0_V2DSP_PD(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_V2DSP_PD_SHIFT)) & PMC_PDCFGSTATUS0_V2DSP_PD_MASK)

#define PMC_PDCFGSTATUS0_V2MIPI_PD_MASK          (0x400U)
#define PMC_PDCFGSTATUS0_V2MIPI_PD_SHIFT         (10U)
/*! V2MIPI_PD - MIPI PHY Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS0_V2MIPI_PD(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_V2MIPI_PD_SHIFT)) & PMC_PDCFGSTATUS0_V2MIPI_PD_MASK)

#define PMC_PDCFGSTATUS0_DCDC_LP_MASK            (0x1000U)
#define PMC_PDCFGSTATUS0_DCDC_LP_SHIFT           (12U)
/*! DCDC_LP - DCDC Low-Power Mode
 *  0b0..DCDC in high-power mode
 *  0b1..DCDC in low-power mode
 */
#define PMC_PDCFGSTATUS0_DCDC_LP(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_DCDC_LP_SHIFT)) & PMC_PDCFGSTATUS0_DCDC_LP_MASK)

#define PMC_PDCFGSTATUS0_DCDC_VSEL_MASK          (0x2000U)
#define PMC_PDCFGSTATUS0_DCDC_VSEL_SHIFT         (13U)
/*! DCDC_VSEL - DCDC Voltage Selection
 *  0b0..[VSEL0] level selected
 *  0b1..[VSEL1] level selected
 */
#define PMC_PDCFGSTATUS0_DCDC_VSEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_DCDC_VSEL_SHIFT)) & PMC_PDCFGSTATUS0_DCDC_VSEL_MASK)

#define PMC_PDCFGSTATUS0_LDO1_MODE_MASK          (0xC000U)
#define PMC_PDCFGSTATUS0_LDO1_MODE_SHIFT         (14U)
/*! LDO1_MODE - LDO VDD1 Regulator Mode
 *  0b00..LDO VDD1 is in bypass mode
 *  0b01..LDO VDD1 is in high-power mode
 *  0b10, 0b11..LDO VDD1 is in low-power mode
 */
#define PMC_PDCFGSTATUS0_LDO1_MODE(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_LDO1_MODE_SHIFT)) & PMC_PDCFGSTATUS0_LDO1_MODE_MASK)

#define PMC_PDCFGSTATUS0_LDO1_VSEL_MASK          (0x30000U)
#define PMC_PDCFGSTATUS0_LDO1_VSEL_SHIFT         (16U)
/*! LDO1_VSEL - LDO VDD1 Voltage Selection
 *  0b00..LDOVDD1VSEL[VSEL0] and LVDVDD1CTRL[LVL0] level selected (lowest voltage)
 *  0b01..LDOVDD1VSEL[VSEL1] and LVDVDD1CTRL[LVL1] level selected
 *  0b10..LDOVDD1VSEL[VSEL2] and LVDVDD1CTRL[LVL2] level selected
 *  0b11..LDOVDD1VSEL[VSEL3] and LVDVDD1CTRL[LVL3] level selected (highest voltage)
 */
#define PMC_PDCFGSTATUS0_LDO1_VSEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_LDO1_VSEL_SHIFT)) & PMC_PDCFGSTATUS0_LDO1_VSEL_MASK)

#define PMC_PDCFGSTATUS0_LDO2_MODE_MASK          (0xC0000U)
#define PMC_PDCFGSTATUS0_LDO2_MODE_SHIFT         (18U)
/*! LDO2_MODE - LDO VDD2 Regulator Mode
 *  0b00..LDO VDD1 is in bypass mode
 *  0b01..LDO VDD2 is in high-power mode
 *  0b10, 0b11..LDO VDD2 is in low-power mode
 */
#define PMC_PDCFGSTATUS0_LDO2_MODE(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_LDO2_MODE_SHIFT)) & PMC_PDCFGSTATUS0_LDO2_MODE_MASK)

#define PMC_PDCFGSTATUS0_LDO2_VSEL_MASK          (0x300000U)
#define PMC_PDCFGSTATUS0_LDO2_VSEL_SHIFT         (20U)
/*! LDO2_VSEL - LDO VDD2 Voltage Selection
 *  0b00..LDOVDD2VSEL[VSEL0] and LVDVDD2CTRL[LVL0] level selected (lowest voltage)
 *  0b01..LDOVDD2VSEL[VSEL1] and LVDVDD2CTRL[LVL1] level selected
 *  0b10..LDOVDD2VSEL[VSEL2] and LVDVDD2CTRL[LVL2] level selected
 *  0b11..LDOVDD2VSEL[VSEL3] and LVDVDD2CTRL[LVL3] level selected (highest voltage)
 */
#define PMC_PDCFGSTATUS0_LDO2_VSEL(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_LDO2_VSEL_SHIFT)) & PMC_PDCFGSTATUS0_LDO2_VSEL_MASK)

#define PMC_PDCFGSTATUS0_RBB1_PD_MASK            (0x400000U)
#define PMC_PDCFGSTATUS0_RBB1_PD_SHIFT           (22U)
/*! RBB1_PD - Power Down RBB in VDD1 domain
 *  0b0..Enables RBB if the aggregated value of [AFBB1_PD] = 1, otherwise RBB is disabled
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS0_RBB1_PD(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_RBB1_PD_SHIFT)) & PMC_PDCFGSTATUS0_RBB1_PD_MASK)

#define PMC_PDCFGSTATUS0_AFBB1_PD_MASK           (0x800000U)
#define PMC_PDCFGSTATUS0_AFBB1_PD_SHIFT          (23U)
/*! AFBB1_PD - AFBB Power Down in VDD1 domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS0_AFBB1_PD(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_AFBB1_PD_SHIFT)) & PMC_PDCFGSTATUS0_AFBB1_PD_MASK)

#define PMC_PDCFGSTATUS0_RBB2_PD_MASK            (0x1000000U)
#define PMC_PDCFGSTATUS0_RBB2_PD_SHIFT           (24U)
/*! RBB2_PD - RBB Power Down in VDD2 domain
 *  0b0..Enables RBB if the aggregated value of [AFBB2_PD] = 1, otherwise RBB is disabled
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS0_RBB2_PD(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_RBB2_PD_SHIFT)) & PMC_PDCFGSTATUS0_RBB2_PD_MASK)

#define PMC_PDCFGSTATUS0_AFBB2_PD_MASK           (0x2000000U)
#define PMC_PDCFGSTATUS0_AFBB2_PD_SHIFT          (25U)
/*! AFBB2_PD - AFBB Power Down in VDD2 domain
 *  0b0..Power
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS0_AFBB2_PD(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_AFBB2_PD_SHIFT)) & PMC_PDCFGSTATUS0_AFBB2_PD_MASK)

#define PMC_PDCFGSTATUS0_RBBN_PD_MASK            (0x4000000U)
#define PMC_PDCFGSTATUS0_RBBN_PD_SHIFT           (26U)
/*! RBBN_PD - RBB Power Down in VDDN domain
 *  0b0..Enables RBB if the aggregated value of [AFBBN_PD] = 1, otherwise RBB is disabled
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS0_RBBN_PD(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_RBBN_PD_SHIFT)) & PMC_PDCFGSTATUS0_RBBN_PD_MASK)

#define PMC_PDCFGSTATUS0_AFBBN_PD_MASK           (0x8000000U)
#define PMC_PDCFGSTATUS0_AFBBN_PD_SHIFT          (27U)
/*! AFBBN_PD - AFBB Power Down in VDDN domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS0_AFBBN_PD(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_AFBBN_PD_SHIFT)) & PMC_PDCFGSTATUS0_AFBBN_PD_MASK)

#define PMC_PDCFGSTATUS0_RBBSR1_PD_MASK          (0x10000000U)
#define PMC_PDCFGSTATUS0_RBBSR1_PD_SHIFT         (28U)
/*! RBBSR1_PD - Power Down SRAM RBB in VDD1 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS0_RBBSR1_PD(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_RBBSR1_PD_SHIFT)) & PMC_PDCFGSTATUS0_RBBSR1_PD_MASK)

#define PMC_PDCFGSTATUS0_RBBSR2_PD_MASK          (0x20000000U)
#define PMC_PDCFGSTATUS0_RBBSR2_PD_SHIFT         (29U)
/*! RBBSR2_PD - SRAM RBB Power Down in VDD2 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS0_RBBSR2_PD(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS0_RBBSR2_PD_SHIFT)) & PMC_PDCFGSTATUS0_RBBSR2_PD_MASK)
/*! @} */

/*! @name PDCFGSTATUS1 - PD Configuration Status 1 */
/*! @{ */

#define PMC_PDCFGSTATUS1_TEMP_PD_MASK            (0x1U)
#define PMC_PDCFGSTATUS1_TEMP_PD_SHIFT           (0U)
/*! TEMP_PD - PMC Temperature Sensor Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS1_TEMP_PD(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_TEMP_PD_SHIFT)) & PMC_PDCFGSTATUS1_TEMP_PD_MASK)

#define PMC_PDCFGSTATUS1_PMCREF_LP_MASK          (0x2U)
#define PMC_PDCFGSTATUS1_PMCREF_LP_SHIFT         (1U)
/*! PMCREF_LP - PMC References Low Power
 *  0b0..High-power mode
 *  0b1..Low-power mode
 */
#define PMC_PDCFGSTATUS1_PMCREF_LP(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_PMCREF_LP_SHIFT)) & PMC_PDCFGSTATUS1_PMCREF_LP_MASK)

#define PMC_PDCFGSTATUS1_HVD1V8_PD_MASK          (0x4U)
#define PMC_PDCFGSTATUS1_HVD1V8_PD_SHIFT         (2U)
/*! HVD1V8_PD - HVD Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS1_HVD1V8_PD(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_HVD1V8_PD_SHIFT)) & PMC_PDCFGSTATUS1_HVD1V8_PD_MASK)

#define PMC_PDCFGSTATUS1_POR1_LP_MASK            (0x8U)
#define PMC_PDCFGSTATUS1_POR1_LP_SHIFT           (3U)
/*! POR1_LP - POR Low Power in VDD1 Domain
 *  0b0..High power
 *  0b1..Low power
 */
#define PMC_PDCFGSTATUS1_POR1_LP(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_POR1_LP_SHIFT)) & PMC_PDCFGSTATUS1_POR1_LP_MASK)

#define PMC_PDCFGSTATUS1_LVD1_LP_MASK            (0x10U)
#define PMC_PDCFGSTATUS1_LVD1_LP_SHIFT           (4U)
/*! LVD1_LP - LVD Low Power in VDD1 Domain
 *  0b0..High power
 *  0b1..Low power
 */
#define PMC_PDCFGSTATUS1_LVD1_LP(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_LVD1_LP_SHIFT)) & PMC_PDCFGSTATUS1_LVD1_LP_MASK)

#define PMC_PDCFGSTATUS1_HVD1_PD_MASK            (0x20U)
#define PMC_PDCFGSTATUS1_HVD1_PD_SHIFT           (5U)
/*! HVD1_PD - HVD Power Down in VDD1 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS1_HVD1_PD(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_HVD1_PD_SHIFT)) & PMC_PDCFGSTATUS1_HVD1_PD_MASK)

#define PMC_PDCFGSTATUS1_AGDET1_PD_MASK          (0x40U)
#define PMC_PDCFGSTATUS1_AGDET1_PD_SHIFT         (6U)
/*! AGDET1_PD - aGDET Power Down in VDD1 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS1_AGDET1_PD(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_AGDET1_PD_SHIFT)) & PMC_PDCFGSTATUS1_AGDET1_PD_MASK)

#define PMC_PDCFGSTATUS1_POR2_LP_MASK            (0x80U)
#define PMC_PDCFGSTATUS1_POR2_LP_SHIFT           (7U)
/*! POR2_LP - POR Low Power in VDD2 Domain
 *  0b0..High power
 *  0b1..Low power
 */
#define PMC_PDCFGSTATUS1_POR2_LP(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_POR2_LP_SHIFT)) & PMC_PDCFGSTATUS1_POR2_LP_MASK)

#define PMC_PDCFGSTATUS1_LVD2_LP_MASK            (0x100U)
#define PMC_PDCFGSTATUS1_LVD2_LP_SHIFT           (8U)
/*! LVD2_LP - LVD Low Power in VDD2 Domain
 *  0b0..High power
 *  0b1..Low power
 */
#define PMC_PDCFGSTATUS1_LVD2_LP(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_LVD2_LP_SHIFT)) & PMC_PDCFGSTATUS1_LVD2_LP_MASK)

#define PMC_PDCFGSTATUS1_HVD2_PD_MASK            (0x200U)
#define PMC_PDCFGSTATUS1_HVD2_PD_SHIFT           (9U)
/*! HVD2_PD - HVD Power Down in VDD2 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS1_HVD2_PD(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_HVD2_PD_SHIFT)) & PMC_PDCFGSTATUS1_HVD2_PD_MASK)

#define PMC_PDCFGSTATUS1_AGDET2_PD_MASK          (0x400U)
#define PMC_PDCFGSTATUS1_AGDET2_PD_SHIFT         (10U)
/*! AGDET2_PD - aGDET Power Down in VDD2 Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS1_AGDET2_PD(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_AGDET2_PD_SHIFT)) & PMC_PDCFGSTATUS1_AGDET2_PD_MASK)

#define PMC_PDCFGSTATUS1_PORN_LP_MASK            (0x800U)
#define PMC_PDCFGSTATUS1_PORN_LP_SHIFT           (11U)
/*! PORN_LP - POR Low Power in VDDN Domain
 *  0b0..High power
 *  0b1..Low power
 */
#define PMC_PDCFGSTATUS1_PORN_LP(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_PORN_LP_SHIFT)) & PMC_PDCFGSTATUS1_PORN_LP_MASK)

#define PMC_PDCFGSTATUS1_LVDN_LP_MASK            (0x1000U)
#define PMC_PDCFGSTATUS1_LVDN_LP_SHIFT           (12U)
/*! LVDN_LP - LVD Low Power in VDDN Domain
 *  0b0..High power
 *  0b1..Low power
 */
#define PMC_PDCFGSTATUS1_LVDN_LP(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_LVDN_LP_SHIFT)) & PMC_PDCFGSTATUS1_LVDN_LP_MASK)

#define PMC_PDCFGSTATUS1_HVDN_PD_MASK            (0x2000U)
#define PMC_PDCFGSTATUS1_HVDN_PD_SHIFT           (13U)
/*! HVDN_PD - HVD Power Down in VDDN Domain
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS1_HVDN_PD(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_HVDN_PD_SHIFT)) & PMC_PDCFGSTATUS1_HVDN_PD_MASK)

#define PMC_PDCFGSTATUS1_OTP_PD_MASK             (0x8000U)
#define PMC_PDCFGSTATUS1_OTP_PD_SHIFT            (15U)
/*! OTP_PD - OTP Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS1_OTP_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_OTP_PD_SHIFT)) & PMC_PDCFGSTATUS1_OTP_PD_MASK)

#define PMC_PDCFGSTATUS1_ROM_PD_MASK             (0x10000U)
#define PMC_PDCFGSTATUS1_ROM_PD_SHIFT            (16U)
/*! ROM_PD - ROM Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS1_ROM_PD(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_ROM_PD_SHIFT)) & PMC_PDCFGSTATUS1_ROM_PD_MASK)

#define PMC_PDCFGSTATUS1_SRAMSLEEP_MASK          (0x80000000U)
#define PMC_PDCFGSTATUS1_SRAMSLEEP_SHIFT         (31U)
/*! SRAMSLEEP - SRAM Sleep Mode
 *  0b0..Normal
 *  0b1..Sleep
 */
#define PMC_PDCFGSTATUS1_SRAMSLEEP(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS1_SRAMSLEEP_SHIFT)) & PMC_PDCFGSTATUS1_SRAMSLEEP_MASK)
/*! @} */

/*! @name PDCFGSTATUS2 - PD Configuration Status 2 */
/*! @{ */

#define PMC_PDCFGSTATUS2_SRAM0_MASK              (0x1U)
#define PMC_PDCFGSTATUS2_SRAM0_SHIFT             (0U)
/*! SRAM0 - RAM Partition 0 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM0(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM0_SHIFT)) & PMC_PDCFGSTATUS2_SRAM0_MASK)

#define PMC_PDCFGSTATUS2_SRAM1_MASK              (0x2U)
#define PMC_PDCFGSTATUS2_SRAM1_SHIFT             (1U)
/*! SRAM1 - RAM Partition 1 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM1(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM1_SHIFT)) & PMC_PDCFGSTATUS2_SRAM1_MASK)

#define PMC_PDCFGSTATUS2_SRAM2_MASK              (0x4U)
#define PMC_PDCFGSTATUS2_SRAM2_SHIFT             (2U)
/*! SRAM2 - RAM Partition 2 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM2(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM2_SHIFT)) & PMC_PDCFGSTATUS2_SRAM2_MASK)

#define PMC_PDCFGSTATUS2_SRAM3_MASK              (0x8U)
#define PMC_PDCFGSTATUS2_SRAM3_SHIFT             (3U)
/*! SRAM3 - RAM Partition 3 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM3(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM3_SHIFT)) & PMC_PDCFGSTATUS2_SRAM3_MASK)

#define PMC_PDCFGSTATUS2_SRAM4_MASK              (0x10U)
#define PMC_PDCFGSTATUS2_SRAM4_SHIFT             (4U)
/*! SRAM4 - RAM Partition 4 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM4(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM4_SHIFT)) & PMC_PDCFGSTATUS2_SRAM4_MASK)

#define PMC_PDCFGSTATUS2_SRAM5_MASK              (0x20U)
#define PMC_PDCFGSTATUS2_SRAM5_SHIFT             (5U)
/*! SRAM5 - RAM Partition 5 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM5(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM5_SHIFT)) & PMC_PDCFGSTATUS2_SRAM5_MASK)

#define PMC_PDCFGSTATUS2_SRAM6_MASK              (0x40U)
#define PMC_PDCFGSTATUS2_SRAM6_SHIFT             (6U)
/*! SRAM6 - RAM Partition 6 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM6(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM6_SHIFT)) & PMC_PDCFGSTATUS2_SRAM6_MASK)

#define PMC_PDCFGSTATUS2_SRAM7_MASK              (0x80U)
#define PMC_PDCFGSTATUS2_SRAM7_SHIFT             (7U)
/*! SRAM7 - RAM Partition 7 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM7(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM7_SHIFT)) & PMC_PDCFGSTATUS2_SRAM7_MASK)

#define PMC_PDCFGSTATUS2_SRAM8_MASK              (0x100U)
#define PMC_PDCFGSTATUS2_SRAM8_SHIFT             (8U)
/*! SRAM8 - RAM Partition 8 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM8(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM8_SHIFT)) & PMC_PDCFGSTATUS2_SRAM8_MASK)

#define PMC_PDCFGSTATUS2_SRAM9_MASK              (0x200U)
#define PMC_PDCFGSTATUS2_SRAM9_SHIFT             (9U)
/*! SRAM9 - RAM Partition 9 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM9(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM9_SHIFT)) & PMC_PDCFGSTATUS2_SRAM9_MASK)

#define PMC_PDCFGSTATUS2_SRAM10_MASK             (0x400U)
#define PMC_PDCFGSTATUS2_SRAM10_SHIFT            (10U)
/*! SRAM10 - RAM Partition 10 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM10(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM10_SHIFT)) & PMC_PDCFGSTATUS2_SRAM10_MASK)

#define PMC_PDCFGSTATUS2_SRAM11_MASK             (0x800U)
#define PMC_PDCFGSTATUS2_SRAM11_SHIFT            (11U)
/*! SRAM11 - RAM Partition 11 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM11(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM11_SHIFT)) & PMC_PDCFGSTATUS2_SRAM11_MASK)

#define PMC_PDCFGSTATUS2_SRAM12_MASK             (0x1000U)
#define PMC_PDCFGSTATUS2_SRAM12_SHIFT            (12U)
/*! SRAM12 - RAM Partition 12 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM12(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM12_SHIFT)) & PMC_PDCFGSTATUS2_SRAM12_MASK)

#define PMC_PDCFGSTATUS2_SRAM13_MASK             (0x2000U)
#define PMC_PDCFGSTATUS2_SRAM13_SHIFT            (13U)
/*! SRAM13 - RAM Partition 13 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM13(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM13_SHIFT)) & PMC_PDCFGSTATUS2_SRAM13_MASK)

#define PMC_PDCFGSTATUS2_SRAM14_MASK             (0x4000U)
#define PMC_PDCFGSTATUS2_SRAM14_SHIFT            (14U)
/*! SRAM14 - RAM Partition 14 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM14(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM14_SHIFT)) & PMC_PDCFGSTATUS2_SRAM14_MASK)

#define PMC_PDCFGSTATUS2_SRAM15_MASK             (0x8000U)
#define PMC_PDCFGSTATUS2_SRAM15_SHIFT            (15U)
/*! SRAM15 - RAM Partition 15 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM15(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM15_SHIFT)) & PMC_PDCFGSTATUS2_SRAM15_MASK)

#define PMC_PDCFGSTATUS2_SRAM16_MASK             (0x10000U)
#define PMC_PDCFGSTATUS2_SRAM16_SHIFT            (16U)
/*! SRAM16 - RAM Partition 16 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM16(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM16_SHIFT)) & PMC_PDCFGSTATUS2_SRAM16_MASK)

#define PMC_PDCFGSTATUS2_SRAM17_MASK             (0x20000U)
#define PMC_PDCFGSTATUS2_SRAM17_SHIFT            (17U)
/*! SRAM17 - RAM Partition 17 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM17(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM17_SHIFT)) & PMC_PDCFGSTATUS2_SRAM17_MASK)

#define PMC_PDCFGSTATUS2_SRAM18_MASK             (0x40000U)
#define PMC_PDCFGSTATUS2_SRAM18_SHIFT            (18U)
/*! SRAM18 - RAM Partition 18 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM18(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM18_SHIFT)) & PMC_PDCFGSTATUS2_SRAM18_MASK)

#define PMC_PDCFGSTATUS2_SRAM19_MASK             (0x80000U)
#define PMC_PDCFGSTATUS2_SRAM19_SHIFT            (19U)
/*! SRAM19 - RAM Partition 19 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM19(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM19_SHIFT)) & PMC_PDCFGSTATUS2_SRAM19_MASK)

#define PMC_PDCFGSTATUS2_SRAM20_MASK             (0x100000U)
#define PMC_PDCFGSTATUS2_SRAM20_SHIFT            (20U)
/*! SRAM20 - RAM Partition 20 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM20(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM20_SHIFT)) & PMC_PDCFGSTATUS2_SRAM20_MASK)

#define PMC_PDCFGSTATUS2_SRAM21_MASK             (0x200000U)
#define PMC_PDCFGSTATUS2_SRAM21_SHIFT            (21U)
/*! SRAM21 - RAM Partition 21 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM21(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM21_SHIFT)) & PMC_PDCFGSTATUS2_SRAM21_MASK)

#define PMC_PDCFGSTATUS2_SRAM22_MASK             (0x400000U)
#define PMC_PDCFGSTATUS2_SRAM22_SHIFT            (22U)
/*! SRAM22 - RAM Partition 22 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM22(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM22_SHIFT)) & PMC_PDCFGSTATUS2_SRAM22_MASK)

#define PMC_PDCFGSTATUS2_SRAM23_MASK             (0x800000U)
#define PMC_PDCFGSTATUS2_SRAM23_SHIFT            (23U)
/*! SRAM23 - RAM Partition 23 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM23(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM23_SHIFT)) & PMC_PDCFGSTATUS2_SRAM23_MASK)

#define PMC_PDCFGSTATUS2_SRAM24_MASK             (0x1000000U)
#define PMC_PDCFGSTATUS2_SRAM24_SHIFT            (24U)
/*! SRAM24 - RAM Partition 24 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM24(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM24_SHIFT)) & PMC_PDCFGSTATUS2_SRAM24_MASK)

#define PMC_PDCFGSTATUS2_SRAM25_MASK             (0x2000000U)
#define PMC_PDCFGSTATUS2_SRAM25_SHIFT            (25U)
/*! SRAM25 - RAM Partition 25 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM25(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM25_SHIFT)) & PMC_PDCFGSTATUS2_SRAM25_MASK)

#define PMC_PDCFGSTATUS2_SRAM26_MASK             (0x4000000U)
#define PMC_PDCFGSTATUS2_SRAM26_SHIFT            (26U)
/*! SRAM26 - RAM Partition 26 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM26(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM26_SHIFT)) & PMC_PDCFGSTATUS2_SRAM26_MASK)

#define PMC_PDCFGSTATUS2_SRAM27_MASK             (0x8000000U)
#define PMC_PDCFGSTATUS2_SRAM27_SHIFT            (27U)
/*! SRAM27 - RAM Partition 27 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM27(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM27_SHIFT)) & PMC_PDCFGSTATUS2_SRAM27_MASK)

#define PMC_PDCFGSTATUS2_SRAM28_MASK             (0x10000000U)
#define PMC_PDCFGSTATUS2_SRAM28_SHIFT            (28U)
/*! SRAM28 - RAM Partition 28 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM28(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM28_SHIFT)) & PMC_PDCFGSTATUS2_SRAM28_MASK)

#define PMC_PDCFGSTATUS2_SRAM29_MASK             (0x20000000U)
#define PMC_PDCFGSTATUS2_SRAM29_SHIFT            (29U)
/*! SRAM29 - RAM Partition 29 Array Power Down
 *  0b0..Array was powered on
 *  0b1..Array and periphery were powered down
 */
#define PMC_PDCFGSTATUS2_SRAM29(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS2_SRAM29_SHIFT)) & PMC_PDCFGSTATUS2_SRAM29_MASK)
/*! @} */

/*! @name PDCFGSTATUS3 - PD Configuration Status 3 */
/*! @{ */

#define PMC_PDCFGSTATUS3_SRAM0_MASK              (0x1U)
#define PMC_PDCFGSTATUS3_SRAM0_SHIFT             (0U)
/*! SRAM0 - RAM Partition 0 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM0(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM0_SHIFT)) & PMC_PDCFGSTATUS3_SRAM0_MASK)

#define PMC_PDCFGSTATUS3_SRAM1_MASK              (0x2U)
#define PMC_PDCFGSTATUS3_SRAM1_SHIFT             (1U)
/*! SRAM1 - RAM Partition 1 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM1(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM1_SHIFT)) & PMC_PDCFGSTATUS3_SRAM1_MASK)

#define PMC_PDCFGSTATUS3_SRAM2_MASK              (0x4U)
#define PMC_PDCFGSTATUS3_SRAM2_SHIFT             (2U)
/*! SRAM2 - RAM Partition 2 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM2(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM2_SHIFT)) & PMC_PDCFGSTATUS3_SRAM2_MASK)

#define PMC_PDCFGSTATUS3_SRAM3_MASK              (0x8U)
#define PMC_PDCFGSTATUS3_SRAM3_SHIFT             (3U)
/*! SRAM3 - RAM Partition 3 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM3(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM3_SHIFT)) & PMC_PDCFGSTATUS3_SRAM3_MASK)

#define PMC_PDCFGSTATUS3_SRAM4_MASK              (0x10U)
#define PMC_PDCFGSTATUS3_SRAM4_SHIFT             (4U)
/*! SRAM4 - RAM Partition 4 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM4(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM4_SHIFT)) & PMC_PDCFGSTATUS3_SRAM4_MASK)

#define PMC_PDCFGSTATUS3_SRAM5_MASK              (0x20U)
#define PMC_PDCFGSTATUS3_SRAM5_SHIFT             (5U)
/*! SRAM5 - RAM Partition 5 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM5(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM5_SHIFT)) & PMC_PDCFGSTATUS3_SRAM5_MASK)

#define PMC_PDCFGSTATUS3_SRAM6_MASK              (0x40U)
#define PMC_PDCFGSTATUS3_SRAM6_SHIFT             (6U)
/*! SRAM6 - RAM Partition 6 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM6(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM6_SHIFT)) & PMC_PDCFGSTATUS3_SRAM6_MASK)

#define PMC_PDCFGSTATUS3_SRAM7_MASK              (0x80U)
#define PMC_PDCFGSTATUS3_SRAM7_SHIFT             (7U)
/*! SRAM7 - RAM Partition 7 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM7(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM7_SHIFT)) & PMC_PDCFGSTATUS3_SRAM7_MASK)

#define PMC_PDCFGSTATUS3_SRAM8_MASK              (0x100U)
#define PMC_PDCFGSTATUS3_SRAM8_SHIFT             (8U)
/*! SRAM8 - RAM Partition 8 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM8(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM8_SHIFT)) & PMC_PDCFGSTATUS3_SRAM8_MASK)

#define PMC_PDCFGSTATUS3_SRAM9_MASK              (0x200U)
#define PMC_PDCFGSTATUS3_SRAM9_SHIFT             (9U)
/*! SRAM9 - RAM Partition 9 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM9(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM9_SHIFT)) & PMC_PDCFGSTATUS3_SRAM9_MASK)

#define PMC_PDCFGSTATUS3_SRAM10_MASK             (0x400U)
#define PMC_PDCFGSTATUS3_SRAM10_SHIFT            (10U)
/*! SRAM10 - RAM Partition 10 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM10(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM10_SHIFT)) & PMC_PDCFGSTATUS3_SRAM10_MASK)

#define PMC_PDCFGSTATUS3_SRAM11_MASK             (0x800U)
#define PMC_PDCFGSTATUS3_SRAM11_SHIFT            (11U)
/*! SRAM11 - RAM Partition 11 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM11(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM11_SHIFT)) & PMC_PDCFGSTATUS3_SRAM11_MASK)

#define PMC_PDCFGSTATUS3_SRAM12_MASK             (0x1000U)
#define PMC_PDCFGSTATUS3_SRAM12_SHIFT            (12U)
/*! SRAM12 - RAM Partition 12 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM12(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM12_SHIFT)) & PMC_PDCFGSTATUS3_SRAM12_MASK)

#define PMC_PDCFGSTATUS3_SRAM13_MASK             (0x2000U)
#define PMC_PDCFGSTATUS3_SRAM13_SHIFT            (13U)
/*! SRAM13 - RAM Partition 13 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM13(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM13_SHIFT)) & PMC_PDCFGSTATUS3_SRAM13_MASK)

#define PMC_PDCFGSTATUS3_SRAM14_MASK             (0x4000U)
#define PMC_PDCFGSTATUS3_SRAM14_SHIFT            (14U)
/*! SRAM14 - RAM Partition 14 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM14(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM14_SHIFT)) & PMC_PDCFGSTATUS3_SRAM14_MASK)

#define PMC_PDCFGSTATUS3_SRAM15_MASK             (0x8000U)
#define PMC_PDCFGSTATUS3_SRAM15_SHIFT            (15U)
/*! SRAM15 - RAM Partition 15 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM15(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM15_SHIFT)) & PMC_PDCFGSTATUS3_SRAM15_MASK)

#define PMC_PDCFGSTATUS3_SRAM16_MASK             (0x10000U)
#define PMC_PDCFGSTATUS3_SRAM16_SHIFT            (16U)
/*! SRAM16 - RAM Partition 16 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM16(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM16_SHIFT)) & PMC_PDCFGSTATUS3_SRAM16_MASK)

#define PMC_PDCFGSTATUS3_SRAM17_MASK             (0x20000U)
#define PMC_PDCFGSTATUS3_SRAM17_SHIFT            (17U)
/*! SRAM17 - RAM Partition 17 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM17(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM17_SHIFT)) & PMC_PDCFGSTATUS3_SRAM17_MASK)

#define PMC_PDCFGSTATUS3_SRAM18_MASK             (0x40000U)
#define PMC_PDCFGSTATUS3_SRAM18_SHIFT            (18U)
/*! SRAM18 - RAM Partition 18 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM18(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM18_SHIFT)) & PMC_PDCFGSTATUS3_SRAM18_MASK)

#define PMC_PDCFGSTATUS3_SRAM19_MASK             (0x80000U)
#define PMC_PDCFGSTATUS3_SRAM19_SHIFT            (19U)
/*! SRAM19 - RAM Partition 19 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM19(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM19_SHIFT)) & PMC_PDCFGSTATUS3_SRAM19_MASK)

#define PMC_PDCFGSTATUS3_SRAM20_MASK             (0x100000U)
#define PMC_PDCFGSTATUS3_SRAM20_SHIFT            (20U)
/*! SRAM20 - RAM Partition 20 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM20(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM20_SHIFT)) & PMC_PDCFGSTATUS3_SRAM20_MASK)

#define PMC_PDCFGSTATUS3_SRAM21_MASK             (0x200000U)
#define PMC_PDCFGSTATUS3_SRAM21_SHIFT            (21U)
/*! SRAM21 - RAM Partition 21 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM21(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM21_SHIFT)) & PMC_PDCFGSTATUS3_SRAM21_MASK)

#define PMC_PDCFGSTATUS3_SRAM22_MASK             (0x400000U)
#define PMC_PDCFGSTATUS3_SRAM22_SHIFT            (22U)
/*! SRAM22 - RAM Partition 22 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM22(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM22_SHIFT)) & PMC_PDCFGSTATUS3_SRAM22_MASK)

#define PMC_PDCFGSTATUS3_SRAM23_MASK             (0x800000U)
#define PMC_PDCFGSTATUS3_SRAM23_SHIFT            (23U)
/*! SRAM23 - RAM Partition 23 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM23(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM23_SHIFT)) & PMC_PDCFGSTATUS3_SRAM23_MASK)

#define PMC_PDCFGSTATUS3_SRAM24_MASK             (0x1000000U)
#define PMC_PDCFGSTATUS3_SRAM24_SHIFT            (24U)
/*! SRAM24 - RAM Partition 24 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM24(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM24_SHIFT)) & PMC_PDCFGSTATUS3_SRAM24_MASK)

#define PMC_PDCFGSTATUS3_SRAM25_MASK             (0x2000000U)
#define PMC_PDCFGSTATUS3_SRAM25_SHIFT            (25U)
/*! SRAM25 - RAM Partition 25 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM25(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM25_SHIFT)) & PMC_PDCFGSTATUS3_SRAM25_MASK)

#define PMC_PDCFGSTATUS3_SRAM26_MASK             (0x4000000U)
#define PMC_PDCFGSTATUS3_SRAM26_SHIFT            (26U)
/*! SRAM26 - RAM Partition 26 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM26(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM26_SHIFT)) & PMC_PDCFGSTATUS3_SRAM26_MASK)

#define PMC_PDCFGSTATUS3_SRAM27_MASK             (0x8000000U)
#define PMC_PDCFGSTATUS3_SRAM27_SHIFT            (27U)
/*! SRAM27 - RAM Partition 27 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM27(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM27_SHIFT)) & PMC_PDCFGSTATUS3_SRAM27_MASK)

#define PMC_PDCFGSTATUS3_SRAM28_MASK             (0x10000000U)
#define PMC_PDCFGSTATUS3_SRAM28_SHIFT            (28U)
/*! SRAM28 - RAM Partition 28 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM28(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM28_SHIFT)) & PMC_PDCFGSTATUS3_SRAM28_MASK)

#define PMC_PDCFGSTATUS3_SRAM29_MASK             (0x20000000U)
#define PMC_PDCFGSTATUS3_SRAM29_SHIFT            (29U)
/*! SRAM29 - RAM Partition 29 Periphery Power Down
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS3_SRAM29(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS3_SRAM29_SHIFT)) & PMC_PDCFGSTATUS3_SRAM29_MASK)
/*! @} */

/*! @name PDCFGSTATUS4 - PD Configuration Status 4 */
/*! @{ */

#define PMC_PDCFGSTATUS4_SDHC0_SRAM_MASK         (0x1U)
#define PMC_PDCFGSTATUS4_SDHC0_SRAM_SHIFT        (0U)
/*! SDHC0_SRAM - uSDHC0 RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_SDHC0_SRAM(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_SDHC0_SRAM_SHIFT)) & PMC_PDCFGSTATUS4_SDHC0_SRAM_MASK)

#define PMC_PDCFGSTATUS4_SDHC1_SRAM_MASK         (0x2U)
#define PMC_PDCFGSTATUS4_SDHC1_SRAM_SHIFT        (1U)
/*! SDHC1_SRAM - uSDHC1 RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_SDHC1_SRAM(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_SDHC1_SRAM_SHIFT)) & PMC_PDCFGSTATUS4_SDHC1_SRAM_MASK)

#define PMC_PDCFGSTATUS4_USB0_SRAM_MASK          (0x4U)
#define PMC_PDCFGSTATUS4_USB0_SRAM_SHIFT         (2U)
/*! USB0_SRAM - USB0 RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_USB0_SRAM(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_USB0_SRAM_SHIFT)) & PMC_PDCFGSTATUS4_USB0_SRAM_MASK)

#define PMC_PDCFGSTATUS4_USB1_SRAM_MASK          (0x8U)
#define PMC_PDCFGSTATUS4_USB1_SRAM_SHIFT         (3U)
/*! USB1_SRAM - USB1 RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_USB1_SRAM(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_USB1_SRAM_SHIFT)) & PMC_PDCFGSTATUS4_USB1_SRAM_MASK)

#define PMC_PDCFGSTATUS4_JPEG_MASK               (0x10U)
#define PMC_PDCFGSTATUS4_JPEG_SHIFT              (4U)
/*! JPEG - JPEGDEC RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_JPEG(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_JPEG_SHIFT)) & PMC_PDCFGSTATUS4_JPEG_MASK)

#define PMC_PDCFGSTATUS4_PNG_MASK                (0x20U)
#define PMC_PDCFGSTATUS4_PNG_SHIFT               (5U)
/*! PNG - PNGDEC RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_PNG(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_PNG_SHIFT)) & PMC_PDCFGSTATUS4_PNG_MASK)

#define PMC_PDCFGSTATUS4_MIPI_MASK               (0x40U)
#define PMC_PDCFGSTATUS4_MIPI_SHIFT              (6U)
/*! MIPI - MIPI PHY RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_MIPI(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_MIPI_SHIFT)) & PMC_PDCFGSTATUS4_MIPI_MASK)

#define PMC_PDCFGSTATUS4_GPU_MASK                (0x80U)
#define PMC_PDCFGSTATUS4_GPU_SHIFT               (7U)
/*! GPU - VGPU RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_GPU(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_GPU_SHIFT)) & PMC_PDCFGSTATUS4_GPU_MASK)

#define PMC_PDCFGSTATUS4_DMA2_3_MASK             (0x100U)
#define PMC_PDCFGSTATUS4_DMA2_3_SHIFT            (8U)
/*! DMA2_3 - DMA2 and DMA3 RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_DMA2_3(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_DMA2_3_SHIFT)) & PMC_PDCFGSTATUS4_DMA2_3_MASK)

#define PMC_PDCFGSTATUS4_DMA0_1_P_E_MASK         (0x200U)
#define PMC_PDCFGSTATUS4_DMA0_1_P_E_SHIFT        (9U)
/*! DMA0_1_P_E - DMA0-1, PKC, and ETF RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_DMA0_1_P_E(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_DMA0_1_P_E_SHIFT)) & PMC_PDCFGSTATUS4_DMA0_1_P_E_MASK)

#define PMC_PDCFGSTATUS4_CPU0_CCACHE_MASK        (0x400U)
#define PMC_PDCFGSTATUS4_CPU0_CCACHE_SHIFT       (10U)
/*! CPU0_CCACHE - CPU0 Code Cache RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_CPU0_CCACHE(x)          (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_CPU0_CCACHE_SHIFT)) & PMC_PDCFGSTATUS4_CPU0_CCACHE_MASK)

#define PMC_PDCFGSTATUS4_CPU0_SCACHE_MASK        (0x800U)
#define PMC_PDCFGSTATUS4_CPU0_SCACHE_SHIFT       (11U)
/*! CPU0_SCACHE - CPU0 System Cache RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_CPU0_SCACHE(x)          (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_CPU0_SCACHE_SHIFT)) & PMC_PDCFGSTATUS4_CPU0_SCACHE_MASK)

#define PMC_PDCFGSTATUS4_DSP_ICACHE_MASK         (0x1000U)
#define PMC_PDCFGSTATUS4_DSP_ICACHE_SHIFT        (12U)
/*! DSP_ICACHE - HiFi4 Instruction Cache RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_DSP_ICACHE(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_DSP_ICACHE_SHIFT)) & PMC_PDCFGSTATUS4_DSP_ICACHE_MASK)

#define PMC_PDCFGSTATUS4_DSP_DCACHE_MASK         (0x2000U)
#define PMC_PDCFGSTATUS4_DSP_DCACHE_SHIFT        (13U)
/*! DSP_DCACHE - HiFi4 Data Cache RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_DSP_DCACHE(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_DSP_DCACHE_SHIFT)) & PMC_PDCFGSTATUS4_DSP_DCACHE_MASK)

#define PMC_PDCFGSTATUS4_DSP_ITCM_MASK           (0x4000U)
#define PMC_PDCFGSTATUS4_DSP_ITCM_SHIFT          (14U)
/*! DSP_ITCM - HiFi4 Instruction TCM RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_DSP_ITCM(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_DSP_ITCM_SHIFT)) & PMC_PDCFGSTATUS4_DSP_ITCM_MASK)

#define PMC_PDCFGSTATUS4_DSP_DTCM_MASK           (0x8000U)
#define PMC_PDCFGSTATUS4_DSP_DTCM_SHIFT          (15U)
/*! DSP_DTCM - HiFi4 Data TCM RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_DSP_DTCM(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_DSP_DTCM_SHIFT)) & PMC_PDCFGSTATUS4_DSP_DTCM_MASK)

#define PMC_PDCFGSTATUS4_EZH_TCM_MASK            (0x10000U)
#define PMC_PDCFGSTATUS4_EZH_TCM_SHIFT           (16U)
/*! EZH_TCM - EZH-V TCM RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_EZH_TCM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_EZH_TCM_SHIFT)) & PMC_PDCFGSTATUS4_EZH_TCM_MASK)

#define PMC_PDCFGSTATUS4_NPU_MASK                (0x20000U)
#define PMC_PDCFGSTATUS4_NPU_SHIFT               (17U)
/*! NPU - NPU RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_NPU(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_NPU_SHIFT)) & PMC_PDCFGSTATUS4_NPU_MASK)

#define PMC_PDCFGSTATUS4_XSPI0_MASK              (0x40000U)
#define PMC_PDCFGSTATUS4_XSPI0_SHIFT             (18U)
/*! XSPI0 - XSPI0, MMU0, and Cache RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_XSPI0(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_XSPI0_SHIFT)) & PMC_PDCFGSTATUS4_XSPI0_MASK)

#define PMC_PDCFGSTATUS4_XSPI1_MASK              (0x80000U)
#define PMC_PDCFGSTATUS4_XSPI1_SHIFT             (19U)
/*! XSPI1 - XSPI1, MMU1, and Cache RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_XSPI1(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_XSPI1_SHIFT)) & PMC_PDCFGSTATUS4_XSPI1_MASK)

#define PMC_PDCFGSTATUS4_XSPI2_MASK              (0x100000U)
#define PMC_PDCFGSTATUS4_XSPI2_SHIFT             (20U)
/*! XSPI2 - XSPI2 and MMU2 RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_XSPI2(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_XSPI2_SHIFT)) & PMC_PDCFGSTATUS4_XSPI2_MASK)

#define PMC_PDCFGSTATUS4_LCD_MASK                (0x200000U)
#define PMC_PDCFGSTATUS4_LCD_SHIFT               (21U)
/*! LCD - LCDIF Controller RAMs Array
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS4_LCD(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_LCD_SHIFT)) & PMC_PDCFGSTATUS4_LCD_MASK)

#define PMC_PDCFGSTATUS4_OCOTP_MASK              (0x400000U)
#define PMC_PDCFGSTATUS4_OCOTP_SHIFT             (22U)
/*! OCOTP - OCOTP Shadow SRAM
 *  0b0..Array Powered
 *  0b1..Array Power Down
 */
#define PMC_PDCFGSTATUS4_OCOTP(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS4_OCOTP_SHIFT)) & PMC_PDCFGSTATUS4_OCOTP_MASK)
/*! @} */

/*! @name PDCFGSTATUS5 - PD Configuration Status 5 */
/*! @{ */

#define PMC_PDCFGSTATUS5_SDHC0_SRAM_MASK         (0x1U)
#define PMC_PDCFGSTATUS5_SDHC0_SRAM_SHIFT        (0U)
/*! SDHC0_SRAM - uSDHC0 RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_SDHC0_SRAM(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_SDHC0_SRAM_SHIFT)) & PMC_PDCFGSTATUS5_SDHC0_SRAM_MASK)

#define PMC_PDCFGSTATUS5_SDHC1_SRAM_MASK         (0x2U)
#define PMC_PDCFGSTATUS5_SDHC1_SRAM_SHIFT        (1U)
/*! SDHC1_SRAM - uSDHC1 RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_SDHC1_SRAM(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_SDHC1_SRAM_SHIFT)) & PMC_PDCFGSTATUS5_SDHC1_SRAM_MASK)

#define PMC_PDCFGSTATUS5_USB0_SRAM_MASK          (0x4U)
#define PMC_PDCFGSTATUS5_USB0_SRAM_SHIFT         (2U)
/*! USB0_SRAM - USB0 RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_USB0_SRAM(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_USB0_SRAM_SHIFT)) & PMC_PDCFGSTATUS5_USB0_SRAM_MASK)

#define PMC_PDCFGSTATUS5_USB1_SRAM_MASK          (0x8U)
#define PMC_PDCFGSTATUS5_USB1_SRAM_SHIFT         (3U)
/*! USB1_SRAM - USB1 RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_USB1_SRAM(x)            (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_USB1_SRAM_SHIFT)) & PMC_PDCFGSTATUS5_USB1_SRAM_MASK)

#define PMC_PDCFGSTATUS5_JPEG_MASK               (0x10U)
#define PMC_PDCFGSTATUS5_JPEG_SHIFT              (4U)
/*! JPEG - JPEGDEC RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_JPEG(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_JPEG_SHIFT)) & PMC_PDCFGSTATUS5_JPEG_MASK)

#define PMC_PDCFGSTATUS5_PNG_MASK                (0x20U)
#define PMC_PDCFGSTATUS5_PNG_SHIFT               (5U)
/*! PNG - PNGDEC RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_PNG(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_PNG_SHIFT)) & PMC_PDCFGSTATUS5_PNG_MASK)

#define PMC_PDCFGSTATUS5_MIPI_MASK               (0x40U)
#define PMC_PDCFGSTATUS5_MIPI_SHIFT              (6U)
/*! MIPI - MIPI PHY RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_MIPI(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_MIPI_SHIFT)) & PMC_PDCFGSTATUS5_MIPI_MASK)

#define PMC_PDCFGSTATUS5_GPU_MASK                (0x80U)
#define PMC_PDCFGSTATUS5_GPU_SHIFT               (7U)
/*! GPU - VGPU RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_GPU(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_GPU_SHIFT)) & PMC_PDCFGSTATUS5_GPU_MASK)

#define PMC_PDCFGSTATUS5_DMA2_3_MASK             (0x100U)
#define PMC_PDCFGSTATUS5_DMA2_3_SHIFT            (8U)
/*! DMA2_3 - DMA2 and DMA3 RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_DMA2_3(x)               (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_DMA2_3_SHIFT)) & PMC_PDCFGSTATUS5_DMA2_3_MASK)

#define PMC_PDCFGSTATUS5_DMA0_1_P_E_MASK         (0x200U)
#define PMC_PDCFGSTATUS5_DMA0_1_P_E_SHIFT        (9U)
/*! DMA0_1_P_E - DMA0-1, PKC, and ETF RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_DMA0_1_P_E(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_DMA0_1_P_E_SHIFT)) & PMC_PDCFGSTATUS5_DMA0_1_P_E_MASK)

#define PMC_PDCFGSTATUS5_CPU0_CCACHE_MASK        (0x400U)
#define PMC_PDCFGSTATUS5_CPU0_CCACHE_SHIFT       (10U)
/*! CPU0_CCACHE - CPU0 Code Cache RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_CPU0_CCACHE(x)          (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_CPU0_CCACHE_SHIFT)) & PMC_PDCFGSTATUS5_CPU0_CCACHE_MASK)

#define PMC_PDCFGSTATUS5_CPU0_SCACHE_MASK        (0x800U)
#define PMC_PDCFGSTATUS5_CPU0_SCACHE_SHIFT       (11U)
/*! CPU0_SCACHE - CPU0 System Cache RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_CPU0_SCACHE(x)          (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_CPU0_SCACHE_SHIFT)) & PMC_PDCFGSTATUS5_CPU0_SCACHE_MASK)

#define PMC_PDCFGSTATUS5_DSP_ICACHE_MASK         (0x1000U)
#define PMC_PDCFGSTATUS5_DSP_ICACHE_SHIFT        (12U)
/*! DSP_ICACHE - HiFi4 Instruction Cache RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_DSP_ICACHE(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_DSP_ICACHE_SHIFT)) & PMC_PDCFGSTATUS5_DSP_ICACHE_MASK)

#define PMC_PDCFGSTATUS5_DSP_DCACHE_MASK         (0x2000U)
#define PMC_PDCFGSTATUS5_DSP_DCACHE_SHIFT        (13U)
/*! DSP_DCACHE - HiFi4 Data Cache RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_DSP_DCACHE(x)           (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_DSP_DCACHE_SHIFT)) & PMC_PDCFGSTATUS5_DSP_DCACHE_MASK)

#define PMC_PDCFGSTATUS5_DSP_ITCM_MASK           (0x4000U)
#define PMC_PDCFGSTATUS5_DSP_ITCM_SHIFT          (14U)
/*! DSP_ITCM - HiFi4 Instruction TCM RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_DSP_ITCM(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_DSP_ITCM_SHIFT)) & PMC_PDCFGSTATUS5_DSP_ITCM_MASK)

#define PMC_PDCFGSTATUS5_DSP_DTCM_MASK           (0x8000U)
#define PMC_PDCFGSTATUS5_DSP_DTCM_SHIFT          (15U)
/*! DSP_DTCM - HiFi4 Data TCM RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_DSP_DTCM(x)             (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_DSP_DTCM_SHIFT)) & PMC_PDCFGSTATUS5_DSP_DTCM_MASK)

#define PMC_PDCFGSTATUS5_EZH_TCM_MASK            (0x10000U)
#define PMC_PDCFGSTATUS5_EZH_TCM_SHIFT           (16U)
/*! EZH_TCM - EZH-V TCM RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_EZH_TCM(x)              (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_EZH_TCM_SHIFT)) & PMC_PDCFGSTATUS5_EZH_TCM_MASK)

#define PMC_PDCFGSTATUS5_NPU_MASK                (0x20000U)
#define PMC_PDCFGSTATUS5_NPU_SHIFT               (17U)
/*! NPU - NPU RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_NPU(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_NPU_SHIFT)) & PMC_PDCFGSTATUS5_NPU_MASK)

#define PMC_PDCFGSTATUS5_XSPI0_MASK              (0x40000U)
#define PMC_PDCFGSTATUS5_XSPI0_SHIFT             (18U)
/*! XSPI0 - XSPI0, MMU0, and Cache RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_XSPI0(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_XSPI0_SHIFT)) & PMC_PDCFGSTATUS5_XSPI0_MASK)

#define PMC_PDCFGSTATUS5_XSPI1_MASK              (0x80000U)
#define PMC_PDCFGSTATUS5_XSPI1_SHIFT             (19U)
/*! XSPI1 - XSPI1, MMU1, and Cache RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_XSPI1(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_XSPI1_SHIFT)) & PMC_PDCFGSTATUS5_XSPI1_MASK)

#define PMC_PDCFGSTATUS5_XSPI2_MASK              (0x100000U)
#define PMC_PDCFGSTATUS5_XSPI2_SHIFT             (20U)
/*! XSPI2 - XSPI2 and MMU2 RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_XSPI2(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_XSPI2_SHIFT)) & PMC_PDCFGSTATUS5_XSPI2_MASK)

#define PMC_PDCFGSTATUS5_LCD_MASK                (0x200000U)
#define PMC_PDCFGSTATUS5_LCD_SHIFT               (21U)
/*! LCD - LCDIF Controller RAMs Periphery
 *  0b0..Power on
 *  0b1..Power down
 */
#define PMC_PDCFGSTATUS5_LCD(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_LCD_SHIFT)) & PMC_PDCFGSTATUS5_LCD_MASK)

#define PMC_PDCFGSTATUS5_OCOTP_MASK              (0x400000U)
#define PMC_PDCFGSTATUS5_OCOTP_SHIFT             (22U)
/*! OCOTP - OCOTP Shadow SRAM
 *  0b0..Array Powered
 *  0b1..Array Power Down
 */
#define PMC_PDCFGSTATUS5_OCOTP(x)                (((uint32_t)(((uint32_t)(x)) << PMC_PDCFGSTATUS5_OCOTP_SHIFT)) & PMC_PDCFGSTATUS5_OCOTP_MASK)
/*! @} */

/*! @name PDWAKECFG - PD Wake-up Configuration for Compute Domain */
/*! @{ */

#define PMC_PDWAKECFG_RBB1KP_MASK                (0x1U)
#define PMC_PDWAKECFG_RBB1KP_SHIFT               (0U)
/*! RBB1KP - RBB Wake-up in VDD1 Domain
 *  0b0..Do not copy during Deep Sleep
 *  0b1..Copy during Deep Sleep
 */
#define PMC_PDWAKECFG_RBB1KP(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDWAKECFG_RBB1KP_SHIFT)) & PMC_PDWAKECFG_RBB1KP_MASK)

#define PMC_PDWAKECFG_RBB2KP_MASK                (0x2U)
#define PMC_PDWAKECFG_RBB2KP_SHIFT               (1U)
/*! RBB2KP - RBB Wake-up in VDD2 Domain
 *  0b0..Do not copy during Deep Sleep
 *  0b1..Copy during Deep Sleep
 */
#define PMC_PDWAKECFG_RBB2KP(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDWAKECFG_RBB2KP_SHIFT)) & PMC_PDWAKECFG_RBB2KP_MASK)

#define PMC_PDWAKECFG_RBBNKP_MASK                (0x4U)
#define PMC_PDWAKECFG_RBBNKP_SHIFT               (2U)
/*! RBBNKP - RBB Wake-up in VDDN Domain
 *  0b0..Do not copy during Deep Sleep
 *  0b1..Copy during Deep Sleep
 */
#define PMC_PDWAKECFG_RBBNKP(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PDWAKECFG_RBBNKP_SHIFT)) & PMC_PDWAKECFG_RBBNKP_MASK)

#define PMC_PDWAKECFG_AFBB1KP_MASK               (0x100U)
#define PMC_PDWAKECFG_AFBB1KP_SHIFT              (8U)
/*! AFBB1KP - AFBB Wake-up in VDD1 Domain
 *  0b0..Do not copy during Deep Sleep
 *  0b1..Copy during Deep Sleep
 */
#define PMC_PDWAKECFG_AFBB1KP(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDWAKECFG_AFBB1KP_SHIFT)) & PMC_PDWAKECFG_AFBB1KP_MASK)

#define PMC_PDWAKECFG_AFBB2KP_MASK               (0x200U)
#define PMC_PDWAKECFG_AFBB2KP_SHIFT              (9U)
/*! AFBB2KP - AFBB Wake-up in VDD2 Domain
 *  0b0..Do not copy during Deep Sleep
 *  0b1..Copy during Deep Sleep
 */
#define PMC_PDWAKECFG_AFBB2KP(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDWAKECFG_AFBB2KP_SHIFT)) & PMC_PDWAKECFG_AFBB2KP_MASK)

#define PMC_PDWAKECFG_AFBBNKP_MASK               (0x400U)
#define PMC_PDWAKECFG_AFBBNKP_SHIFT              (10U)
/*! AFBBNKP - AFBB Wake-up in VDDN Domain
 *  0b0..Do not copy during Deep Sleep
 *  0b1..Copy during Deep Sleep
 */
#define PMC_PDWAKECFG_AFBBNKP(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_PDWAKECFG_AFBBNKP_SHIFT)) & PMC_PDWAKECFG_AFBBNKP_MASK)
/*! @} */

/*! @name PWRFLAGS - Power Domain Flags for Compute Domain */
/*! @{ */

#define PMC_PWRFLAGS_V1SENSF_MASK                (0x1U)
#define PMC_PWRFLAGS_V1SENSF_SHIFT               (0U)
/*! V1SENSF - VDD1_SENSE Domain Flag
 *  0b0..No DSR event occurred
 *  0b1..DSR event occurred
 */
#define PMC_PWRFLAGS_V1SENSF(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PWRFLAGS_V1SENSF_SHIFT)) & PMC_PWRFLAGS_V1SENSF_MASK)

#define PMC_PWRFLAGS_V2COMPF_MASK                (0x2U)
#define PMC_PWRFLAGS_V2COMPF_SHIFT               (1U)
/*! V2COMPF - VDD2_COMP Domain Flag
 *  0b0..No DSR event occurred
 *  0b1..DSR event occurred
 */
#define PMC_PWRFLAGS_V2COMPF(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PWRFLAGS_V2COMPF_SHIFT)) & PMC_PWRFLAGS_V2COMPF_MASK)

#define PMC_PWRFLAGS_V2NMEDF_MASK                (0x4U)
#define PMC_PWRFLAGS_V2NMEDF_SHIFT               (2U)
/*! V2NMEDF - VDD2_MEDIA and VDDN_MEDIA Domain Flag
 *  0b0..No DSR event occurred
 *  0b1..DSR event occurred
 */
#define PMC_PWRFLAGS_V2NMEDF(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PWRFLAGS_V2NMEDF_SHIFT)) & PMC_PWRFLAGS_V2NMEDF_MASK)

#define PMC_PWRFLAGS_V2COMF_MASK                 (0x8U)
#define PMC_PWRFLAGS_V2COMF_SHIFT                (3U)
/*! V2COMF - VDD2_COM Domain Flag
 *  0b0..No DSR event occurred
 *  0b1..DSR event occurred
 */
#define PMC_PWRFLAGS_V2COMF(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PWRFLAGS_V2COMF_SHIFT)) & PMC_PWRFLAGS_V2COMF_MASK)

#define PMC_PWRFLAGS_VNCOMF_MASK                 (0x10U)
#define PMC_PWRFLAGS_VNCOMF_SHIFT                (4U)
/*! VNCOMF - VDDN_COM Domain Flag
 *  0b0..No DSR event occurred
 *  0b1..DSR event occurred
 */
#define PMC_PWRFLAGS_VNCOMF(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PWRFLAGS_VNCOMF_SHIFT)) & PMC_PWRFLAGS_VNCOMF_MASK)

#define PMC_PWRFLAGS_V2DSPF_MASK                 (0x20U)
#define PMC_PWRFLAGS_V2DSPF_SHIFT                (5U)
/*! V2DSPF - VDD2_DSP Domain Flag
 *  0b0..No power-down event occurred
 *  0b1..Power-down event occurred
 */
#define PMC_PWRFLAGS_V2DSPF(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PWRFLAGS_V2DSPF_SHIFT)) & PMC_PWRFLAGS_V2DSPF_MASK)

#define PMC_PWRFLAGS_V2MIPIF_MASK                (0x40U)
#define PMC_PWRFLAGS_V2MIPIF_SHIFT               (6U)
/*! V2MIPIF - VDD2_MIPI Domain Flag
 *  0b0..No power-down event occurred
 *  0b1..Power-down event occurred
 */
#define PMC_PWRFLAGS_V2MIPIF(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_PWRFLAGS_V2MIPIF_SHIFT)) & PMC_PWRFLAGS_V2MIPIF_MASK)

#define PMC_PWRFLAGS_V2OTPF_MASK                 (0x80U)
#define PMC_PWRFLAGS_V2OTPF_SHIFT                (7U)
/*! V2OTPF - VDD2_OTP Domain Flag
 *  0b0..No power-down event occurred
 *  0b1..Power-down event occurred
 */
#define PMC_PWRFLAGS_V2OTPF(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_PWRFLAGS_V2OTPF_SHIFT)) & PMC_PWRFLAGS_V2OTPF_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMC_Register_Masks */


/*!
 * @}
 */ /* end of group PMC_Peripheral_Access_Layer */


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


#endif  /* PERI_PMC_H_ */

