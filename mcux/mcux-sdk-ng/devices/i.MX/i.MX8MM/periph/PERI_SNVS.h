/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SNVS
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SNVS.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SNVS
 *
 * CMSIS Peripheral Access Layer for SNVS
 */

#if !defined(PERI_SNVS_H_)
#define PERI_SNVS_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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
   -- SNVS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SNVS_Peripheral_Access_Layer SNVS Peripheral Access Layer
 * @{
 */

/** SNVS - Size of Registers Arrays */
#define SNVS_LPGPR0_LPGPR3_COUNT                  4u
#define SNVS_LPGPR0_LPGPR7_COUNT                  4u

/** SNVS - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t HPCOMR;                            /**< SNVS_HP Command Register, offset: 0x4 */
  __IO uint32_t HPCR;                              /**< SNVS_HP Control Register, offset: 0x8 */
       uint8_t RESERVED_1[8];
  __IO uint32_t HPSR;                              /**< SNVS_HP Status Register, offset: 0x14 */
       uint8_t RESERVED_2[12];
  __IO uint32_t HPRTCMR;                           /**< SNVS_HP Real Time Counter MSB Register, offset: 0x24 */
  __IO uint32_t HPRTCLR;                           /**< SNVS_HP Real Time Counter LSB Register, offset: 0x28 */
  __IO uint32_t HPTAMR;                            /**< SNVS_HP Time Alarm MSB Register, offset: 0x2C */
  __IO uint32_t HPTALR;                            /**< SNVS_HP Time Alarm LSB Register, offset: 0x30 */
  __IO uint32_t LPLR;                              /**< SNVS_LP Lock Register, offset: 0x34 */
  __IO uint32_t LPCR;                              /**< SNVS_LP Control Register, offset: 0x38 */
       uint8_t RESERVED_3[16];
  __IO uint32_t LPSR;                              /**< SNVS_LP Status Register, offset: 0x4C */
       uint8_t RESERVED_4[12];
  __IO uint32_t LPSMCMR;                           /**< SNVS_LP Secure Monotonic Counter MSB Register, offset: 0x5C */
  __IO uint32_t LPSMCLR;                           /**< SNVS_LP Secure Monotonic Counter LSB Register, offset: 0x60 */
  __IO uint32_t LPPGDR;                            /**< SNVS_LP Power Glitch Detector Register, offset: 0x64 */
  __IO uint32_t LPGPR0_LEGACY_ALIAS;               /**< SNVS_LP General Purpose Register 0 (legacy alias), offset: 0x68 */
       uint8_t RESERVED_5[36];
  __IO uint32_t LPGPR_ALIAS[SNVS_LPGPR0_LPGPR3_COUNT]; /**< SNVS_LP General Purpose Registers 0 .. 3, array offset: 0x90, array step: 0x4 */
       uint8_t RESERVED_6[96];
  __IO uint32_t LPGPR[SNVS_LPGPR0_LPGPR7_COUNT];   /**< SNVS_LP General Purpose Registers 0 .. 3, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_7[2792];
  __I  uint32_t HPVIDR1;                           /**< SNVS_HP Version ID Register 1, offset: 0xBF8 */
  __I  uint32_t HPVIDR2;                           /**< SNVS_HP Version ID Register 2, offset: 0xBFC */
} SNVS_Type;

/* ----------------------------------------------------------------------------
   -- SNVS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SNVS_Register_Masks SNVS Register Masks
 * @{
 */

/*! @name HPCOMR - SNVS_HP Command Register */
/*! @{ */

#define SNVS_HPCOMR_LP_SWR_MASK                  (0x10U)
#define SNVS_HPCOMR_LP_SWR_SHIFT                 (4U)
/*! LP_SWR
 *  0b0..No Action
 *  0b1..Reset LP section
 */
#define SNVS_HPCOMR_LP_SWR(x)                    (((uint32_t)(((uint32_t)(x)) << SNVS_HPCOMR_LP_SWR_SHIFT)) & SNVS_HPCOMR_LP_SWR_MASK)

#define SNVS_HPCOMR_LP_SWR_DIS_MASK              (0x20U)
#define SNVS_HPCOMR_LP_SWR_DIS_SHIFT             (5U)
/*! LP_SWR_DIS
 *  0b0..LP software reset is enabled
 *  0b1..LP software reset is disabled
 */
#define SNVS_HPCOMR_LP_SWR_DIS(x)                (((uint32_t)(((uint32_t)(x)) << SNVS_HPCOMR_LP_SWR_DIS_SHIFT)) & SNVS_HPCOMR_LP_SWR_DIS_MASK)

#define SNVS_HPCOMR_NPSWA_EN_MASK                (0x80000000U)
#define SNVS_HPCOMR_NPSWA_EN_SHIFT               (31U)
#define SNVS_HPCOMR_NPSWA_EN(x)                  (((uint32_t)(((uint32_t)(x)) << SNVS_HPCOMR_NPSWA_EN_SHIFT)) & SNVS_HPCOMR_NPSWA_EN_MASK)
/*! @} */

/*! @name HPCR - SNVS_HP Control Register */
/*! @{ */

#define SNVS_HPCR_RTC_EN_MASK                    (0x1U)
#define SNVS_HPCR_RTC_EN_SHIFT                   (0U)
/*! RTC_EN
 *  0b0..RTC is disabled
 *  0b1..RTC is enabled
 */
#define SNVS_HPCR_RTC_EN(x)                      (((uint32_t)(((uint32_t)(x)) << SNVS_HPCR_RTC_EN_SHIFT)) & SNVS_HPCR_RTC_EN_MASK)

#define SNVS_HPCR_HPTA_EN_MASK                   (0x2U)
#define SNVS_HPCR_HPTA_EN_SHIFT                  (1U)
/*! HPTA_EN
 *  0b0..HP Time Alarm Interrupt is disabled
 *  0b1..HP Time Alarm Interrupt is enabled
 */
#define SNVS_HPCR_HPTA_EN(x)                     (((uint32_t)(((uint32_t)(x)) << SNVS_HPCR_HPTA_EN_SHIFT)) & SNVS_HPCR_HPTA_EN_MASK)

#define SNVS_HPCR_HPCALB_EN_MASK                 (0x100U)
#define SNVS_HPCR_HPCALB_EN_SHIFT                (8U)
/*! HPCALB_EN
 *  0b0..HP Timer calibration disabled
 *  0b1..HP Timer calibration enabled
 */
#define SNVS_HPCR_HPCALB_EN(x)                   (((uint32_t)(((uint32_t)(x)) << SNVS_HPCR_HPCALB_EN_SHIFT)) & SNVS_HPCR_HPCALB_EN_MASK)

#define SNVS_HPCR_HPCALB_VAL_MASK                (0x7C00U)
#define SNVS_HPCR_HPCALB_VAL_SHIFT               (10U)
/*! HPCALB_VAL
 *  0b00000..+0 counts per each 32768 ticks of the counter
 *  0b00001..+1 counts per each 32768 ticks of the counter
 *  0b00010..+2 counts per each 32768 ticks of the counter
 *  0b01111..+15 counts per each 32768 ticks of the counter
 *  0b10000..-16 counts per each 32768 ticks of the counter
 *  0b10001..-15 counts per each 32768 ticks of the counter
 *  0b11110..-2 counts per each 32768 ticks of the counter
 *  0b11111..-1 counts per each 32768 ticks of the counter
 */
#define SNVS_HPCR_HPCALB_VAL(x)                  (((uint32_t)(((uint32_t)(x)) << SNVS_HPCR_HPCALB_VAL_SHIFT)) & SNVS_HPCR_HPCALB_VAL_MASK)

#define SNVS_HPCR_BTN_CONFIG_MASK                (0x7000000U)
#define SNVS_HPCR_BTN_CONFIG_SHIFT               (24U)
#define SNVS_HPCR_BTN_CONFIG(x)                  (((uint32_t)(((uint32_t)(x)) << SNVS_HPCR_BTN_CONFIG_SHIFT)) & SNVS_HPCR_BTN_CONFIG_MASK)

#define SNVS_HPCR_BTN_MASK_MASK                  (0x8000000U)
#define SNVS_HPCR_BTN_MASK_SHIFT                 (27U)
#define SNVS_HPCR_BTN_MASK(x)                    (((uint32_t)(((uint32_t)(x)) << SNVS_HPCR_BTN_MASK_SHIFT)) & SNVS_HPCR_BTN_MASK_MASK)
/*! @} */

/*! @name HPSR - SNVS_HP Status Register */
/*! @{ */

#define SNVS_HPSR_HPTA_MASK                      (0x1U)
#define SNVS_HPSR_HPTA_SHIFT                     (0U)
/*! HPTA
 *  0b0..No time alarm interrupt occurred.
 *  0b1..A time alarm interrupt occurred.
 */
#define SNVS_HPSR_HPTA(x)                        (((uint32_t)(((uint32_t)(x)) << SNVS_HPSR_HPTA_SHIFT)) & SNVS_HPSR_HPTA_MASK)

#define SNVS_HPSR_LPDIS_MASK                     (0x10U)
#define SNVS_HPSR_LPDIS_SHIFT                    (4U)
#define SNVS_HPSR_LPDIS(x)                       (((uint32_t)(((uint32_t)(x)) << SNVS_HPSR_LPDIS_SHIFT)) & SNVS_HPSR_LPDIS_MASK)

#define SNVS_HPSR_BTN_MASK                       (0x40U)
#define SNVS_HPSR_BTN_SHIFT                      (6U)
#define SNVS_HPSR_BTN(x)                         (((uint32_t)(((uint32_t)(x)) << SNVS_HPSR_BTN_SHIFT)) & SNVS_HPSR_BTN_MASK)

#define SNVS_HPSR_BI_MASK                        (0x80U)
#define SNVS_HPSR_BI_SHIFT                       (7U)
#define SNVS_HPSR_BI(x)                          (((uint32_t)(((uint32_t)(x)) << SNVS_HPSR_BI_SHIFT)) & SNVS_HPSR_BI_MASK)
/*! @} */

/*! @name HPRTCMR - SNVS_HP Real Time Counter MSB Register */
/*! @{ */

#define SNVS_HPRTCMR_RTC_MASK                    (0x7FFFU)
#define SNVS_HPRTCMR_RTC_SHIFT                   (0U)
#define SNVS_HPRTCMR_RTC(x)                      (((uint32_t)(((uint32_t)(x)) << SNVS_HPRTCMR_RTC_SHIFT)) & SNVS_HPRTCMR_RTC_MASK)
/*! @} */

/*! @name HPRTCLR - SNVS_HP Real Time Counter LSB Register */
/*! @{ */

#define SNVS_HPRTCLR_RTC_MASK                    (0xFFFFFFFFU)
#define SNVS_HPRTCLR_RTC_SHIFT                   (0U)
#define SNVS_HPRTCLR_RTC(x)                      (((uint32_t)(((uint32_t)(x)) << SNVS_HPRTCLR_RTC_SHIFT)) & SNVS_HPRTCLR_RTC_MASK)
/*! @} */

/*! @name HPTAMR - SNVS_HP Time Alarm MSB Register */
/*! @{ */

#define SNVS_HPTAMR_HPTA_MS_MASK                 (0x7FFFU)
#define SNVS_HPTAMR_HPTA_MS_SHIFT                (0U)
#define SNVS_HPTAMR_HPTA_MS(x)                   (((uint32_t)(((uint32_t)(x)) << SNVS_HPTAMR_HPTA_MS_SHIFT)) & SNVS_HPTAMR_HPTA_MS_MASK)
/*! @} */

/*! @name HPTALR - SNVS_HP Time Alarm LSB Register */
/*! @{ */

#define SNVS_HPTALR_HPTA_LS_MASK                 (0xFFFFFFFFU)
#define SNVS_HPTALR_HPTA_LS_SHIFT                (0U)
#define SNVS_HPTALR_HPTA_LS(x)                   (((uint32_t)(((uint32_t)(x)) << SNVS_HPTALR_HPTA_LS_SHIFT)) & SNVS_HPTALR_HPTA_LS_MASK)
/*! @} */

/*! @name LPLR - SNVS_LP Lock Register */
/*! @{ */

#define SNVS_LPLR_MC_HL_MASK                     (0x10U)
#define SNVS_LPLR_MC_HL_SHIFT                    (4U)
/*! MC_HL
 *  0b0..Write access (increment) is allowed.
 *  0b1..Write access (increment) is not allowed.
 */
#define SNVS_LPLR_MC_HL(x)                       (((uint32_t)(((uint32_t)(x)) << SNVS_LPLR_MC_HL_SHIFT)) & SNVS_LPLR_MC_HL_MASK)

#define SNVS_LPLR_GPR_HL_MASK                    (0x20U)
#define SNVS_LPLR_GPR_HL_SHIFT                   (5U)
/*! GPR_HL
 *  0b0..Write access is allowed.
 *  0b1..Write access is not allowed.
 */
#define SNVS_LPLR_GPR_HL(x)                      (((uint32_t)(((uint32_t)(x)) << SNVS_LPLR_GPR_HL_SHIFT)) & SNVS_LPLR_GPR_HL_MASK)
/*! @} */

/*! @name LPCR - SNVS_LP Control Register */
/*! @{ */

#define SNVS_LPCR_MC_ENV_MASK                    (0x4U)
#define SNVS_LPCR_MC_ENV_SHIFT                   (2U)
/*! MC_ENV
 *  0b0..MC is disabled or invalid.
 *  0b1..MC is enabled and valid.
 */
#define SNVS_LPCR_MC_ENV(x)                      (((uint32_t)(((uint32_t)(x)) << SNVS_LPCR_MC_ENV_SHIFT)) & SNVS_LPCR_MC_ENV_MASK)

#define SNVS_LPCR_LPWUI_EN_MASK                  (0x8U)
#define SNVS_LPCR_LPWUI_EN_SHIFT                 (3U)
#define SNVS_LPCR_LPWUI_EN(x)                    (((uint32_t)(((uint32_t)(x)) << SNVS_LPCR_LPWUI_EN_SHIFT)) & SNVS_LPCR_LPWUI_EN_MASK)

#define SNVS_LPCR_DP_EN_MASK                     (0x20U)
#define SNVS_LPCR_DP_EN_SHIFT                    (5U)
/*! DP_EN
 *  0b0..Smart PMIC enabled.
 *  0b1..Dumb PMIC enabled.
 */
#define SNVS_LPCR_DP_EN(x)                       (((uint32_t)(((uint32_t)(x)) << SNVS_LPCR_DP_EN_SHIFT)) & SNVS_LPCR_DP_EN_MASK)

#define SNVS_LPCR_TOP_MASK                       (0x40U)
#define SNVS_LPCR_TOP_SHIFT                      (6U)
/*! TOP
 *  0b0..Leave system power on.
 *  0b1..Turn off system power.
 */
#define SNVS_LPCR_TOP(x)                         (((uint32_t)(((uint32_t)(x)) << SNVS_LPCR_TOP_SHIFT)) & SNVS_LPCR_TOP_MASK)

#define SNVS_LPCR_PWR_GLITCH_EN_MASK             (0x80U)
#define SNVS_LPCR_PWR_GLITCH_EN_SHIFT            (7U)
#define SNVS_LPCR_PWR_GLITCH_EN(x)               (((uint32_t)(((uint32_t)(x)) << SNVS_LPCR_PWR_GLITCH_EN_SHIFT)) & SNVS_LPCR_PWR_GLITCH_EN_MASK)

#define SNVS_LPCR_BTN_PRESS_TIME_MASK            (0x30000U)
#define SNVS_LPCR_BTN_PRESS_TIME_SHIFT           (16U)
#define SNVS_LPCR_BTN_PRESS_TIME(x)              (((uint32_t)(((uint32_t)(x)) << SNVS_LPCR_BTN_PRESS_TIME_SHIFT)) & SNVS_LPCR_BTN_PRESS_TIME_MASK)

#define SNVS_LPCR_DEBOUNCE_MASK                  (0xC0000U)
#define SNVS_LPCR_DEBOUNCE_SHIFT                 (18U)
#define SNVS_LPCR_DEBOUNCE(x)                    (((uint32_t)(((uint32_t)(x)) << SNVS_LPCR_DEBOUNCE_SHIFT)) & SNVS_LPCR_DEBOUNCE_MASK)

#define SNVS_LPCR_ON_TIME_MASK                   (0x300000U)
#define SNVS_LPCR_ON_TIME_SHIFT                  (20U)
#define SNVS_LPCR_ON_TIME(x)                     (((uint32_t)(((uint32_t)(x)) << SNVS_LPCR_ON_TIME_SHIFT)) & SNVS_LPCR_ON_TIME_MASK)

#define SNVS_LPCR_PK_EN_MASK                     (0x400000U)
#define SNVS_LPCR_PK_EN_SHIFT                    (22U)
#define SNVS_LPCR_PK_EN(x)                       (((uint32_t)(((uint32_t)(x)) << SNVS_LPCR_PK_EN_SHIFT)) & SNVS_LPCR_PK_EN_MASK)

#define SNVS_LPCR_PK_OVERRIDE_MASK               (0x800000U)
#define SNVS_LPCR_PK_OVERRIDE_SHIFT              (23U)
#define SNVS_LPCR_PK_OVERRIDE(x)                 (((uint32_t)(((uint32_t)(x)) << SNVS_LPCR_PK_OVERRIDE_SHIFT)) & SNVS_LPCR_PK_OVERRIDE_MASK)
/*! @} */

/*! @name LPSR - SNVS_LP Status Register */
/*! @{ */

#define SNVS_LPSR_MCR_MASK                       (0x4U)
#define SNVS_LPSR_MCR_SHIFT                      (2U)
/*! MCR
 *  0b0..MC has not reached its maximum value.
 *  0b1..MC has reached its maximum value.
 */
#define SNVS_LPSR_MCR(x)                         (((uint32_t)(((uint32_t)(x)) << SNVS_LPSR_MCR_SHIFT)) & SNVS_LPSR_MCR_MASK)

#define SNVS_LPSR_EO_MASK                        (0x20000U)
#define SNVS_LPSR_EO_SHIFT                       (17U)
/*! EO
 *  0b0..Emergency off was not detected.
 *  0b1..Emergency off was detected.
 */
#define SNVS_LPSR_EO(x)                          (((uint32_t)(((uint32_t)(x)) << SNVS_LPSR_EO_SHIFT)) & SNVS_LPSR_EO_MASK)

#define SNVS_LPSR_SPO_MASK                       (0x40000U)
#define SNVS_LPSR_SPO_SHIFT                      (18U)
/*! SPO
 *  0b0..Set Power Off was not detected.
 *  0b1..Set Power Off was detected.
 */
#define SNVS_LPSR_SPO(x)                         (((uint32_t)(((uint32_t)(x)) << SNVS_LPSR_SPO_SHIFT)) & SNVS_LPSR_SPO_MASK)
/*! @} */

/*! @name LPSMCMR - SNVS_LP Secure Monotonic Counter MSB Register */
/*! @{ */

#define SNVS_LPSMCMR_MON_COUNTER_MASK            (0xFFFFU)
#define SNVS_LPSMCMR_MON_COUNTER_SHIFT           (0U)
#define SNVS_LPSMCMR_MON_COUNTER(x)              (((uint32_t)(((uint32_t)(x)) << SNVS_LPSMCMR_MON_COUNTER_SHIFT)) & SNVS_LPSMCMR_MON_COUNTER_MASK)

#define SNVS_LPSMCMR_MC_ERA_BITS_MASK            (0xFFFF0000U)
#define SNVS_LPSMCMR_MC_ERA_BITS_SHIFT           (16U)
#define SNVS_LPSMCMR_MC_ERA_BITS(x)              (((uint32_t)(((uint32_t)(x)) << SNVS_LPSMCMR_MC_ERA_BITS_SHIFT)) & SNVS_LPSMCMR_MC_ERA_BITS_MASK)
/*! @} */

/*! @name LPSMCLR - SNVS_LP Secure Monotonic Counter LSB Register */
/*! @{ */

#define SNVS_LPSMCLR_MON_COUNTER_MASK            (0xFFFFFFFFU)
#define SNVS_LPSMCLR_MON_COUNTER_SHIFT           (0U)
#define SNVS_LPSMCLR_MON_COUNTER(x)              (((uint32_t)(((uint32_t)(x)) << SNVS_LPSMCLR_MON_COUNTER_SHIFT)) & SNVS_LPSMCLR_MON_COUNTER_MASK)
/*! @} */

/*! @name LPPGDR - SNVS_LP Power Glitch Detector Register */
/*! @{ */

#define SNVS_LPPGDR_PGD_MASK                     (0xFFFFFFFFU)
#define SNVS_LPPGDR_PGD_SHIFT                    (0U)
#define SNVS_LPPGDR_PGD(x)                       (((uint32_t)(((uint32_t)(x)) << SNVS_LPPGDR_PGD_SHIFT)) & SNVS_LPPGDR_PGD_MASK)
/*! @} */

/*! @name LPGPR0_LEGACY_ALIAS - SNVS_LP General Purpose Register 0 (legacy alias) */
/*! @{ */

#define SNVS_LPGPR0_LEGACY_ALIAS_GPR_MASK        (0xFFFFFFFFU)
#define SNVS_LPGPR0_LEGACY_ALIAS_GPR_SHIFT       (0U)
#define SNVS_LPGPR0_LEGACY_ALIAS_GPR(x)          (((uint32_t)(((uint32_t)(x)) << SNVS_LPGPR0_LEGACY_ALIAS_GPR_SHIFT)) & SNVS_LPGPR0_LEGACY_ALIAS_GPR_MASK)
/*! @} */

/*! @name LPGPR_ALIAS - SNVS_LP General Purpose Registers 0 .. 3 */
/*! @{ */

#define SNVS_LPGPR_ALIAS_GPR_MASK                (0xFFFFFFFFU)
#define SNVS_LPGPR_ALIAS_GPR_SHIFT               (0U)
#define SNVS_LPGPR_ALIAS_GPR(x)                  (((uint32_t)(((uint32_t)(x)) << SNVS_LPGPR_ALIAS_GPR_SHIFT)) & SNVS_LPGPR_ALIAS_GPR_MASK)
/*! @} */

/* The count of SNVS_LPGPR_ALIAS */
#define SNVS_LPGPR_ALIAS_COUNT                   (4U)

/*! @name LPGPR - SNVS_LP General Purpose Registers 0 .. 3 */
/*! @{ */

#define SNVS_LPGPR_GPR_MASK                      (0xFFFFFFFFU)
#define SNVS_LPGPR_GPR_SHIFT                     (0U)
#define SNVS_LPGPR_GPR(x)                        (((uint32_t)(((uint32_t)(x)) << SNVS_LPGPR_GPR_SHIFT)) & SNVS_LPGPR_GPR_MASK)
/*! @} */

/* The count of SNVS_LPGPR */
#define SNVS_LPGPR_COUNT                         (4U)

/*! @name HPVIDR1 - SNVS_HP Version ID Register 1 */
/*! @{ */

#define SNVS_HPVIDR1_MINOR_REV_MASK              (0xFFU)
#define SNVS_HPVIDR1_MINOR_REV_SHIFT             (0U)
#define SNVS_HPVIDR1_MINOR_REV(x)                (((uint32_t)(((uint32_t)(x)) << SNVS_HPVIDR1_MINOR_REV_SHIFT)) & SNVS_HPVIDR1_MINOR_REV_MASK)

#define SNVS_HPVIDR1_MAJOR_REV_MASK              (0xFF00U)
#define SNVS_HPVIDR1_MAJOR_REV_SHIFT             (8U)
#define SNVS_HPVIDR1_MAJOR_REV(x)                (((uint32_t)(((uint32_t)(x)) << SNVS_HPVIDR1_MAJOR_REV_SHIFT)) & SNVS_HPVIDR1_MAJOR_REV_MASK)

#define SNVS_HPVIDR1_IP_ID_MASK                  (0xFFFF0000U)
#define SNVS_HPVIDR1_IP_ID_SHIFT                 (16U)
#define SNVS_HPVIDR1_IP_ID(x)                    (((uint32_t)(((uint32_t)(x)) << SNVS_HPVIDR1_IP_ID_SHIFT)) & SNVS_HPVIDR1_IP_ID_MASK)
/*! @} */

/*! @name HPVIDR2 - SNVS_HP Version ID Register 2 */
/*! @{ */

#define SNVS_HPVIDR2_CONFIG_OPT_MASK             (0xFFU)
#define SNVS_HPVIDR2_CONFIG_OPT_SHIFT            (0U)
#define SNVS_HPVIDR2_CONFIG_OPT(x)               (((uint32_t)(((uint32_t)(x)) << SNVS_HPVIDR2_CONFIG_OPT_SHIFT)) & SNVS_HPVIDR2_CONFIG_OPT_MASK)

#define SNVS_HPVIDR2_ECO_REV_MASK                (0xFF00U)
#define SNVS_HPVIDR2_ECO_REV_SHIFT               (8U)
#define SNVS_HPVIDR2_ECO_REV(x)                  (((uint32_t)(((uint32_t)(x)) << SNVS_HPVIDR2_ECO_REV_SHIFT)) & SNVS_HPVIDR2_ECO_REV_MASK)

#define SNVS_HPVIDR2_INTG_OPT_MASK               (0xFF0000U)
#define SNVS_HPVIDR2_INTG_OPT_SHIFT              (16U)
#define SNVS_HPVIDR2_INTG_OPT(x)                 (((uint32_t)(((uint32_t)(x)) << SNVS_HPVIDR2_INTG_OPT_SHIFT)) & SNVS_HPVIDR2_INTG_OPT_MASK)

#define SNVS_HPVIDR2_IP_ERA_MASK                 (0xFF000000U)
#define SNVS_HPVIDR2_IP_ERA_SHIFT                (24U)
#define SNVS_HPVIDR2_IP_ERA(x)                   (((uint32_t)(((uint32_t)(x)) << SNVS_HPVIDR2_IP_ERA_SHIFT)) & SNVS_HPVIDR2_IP_ERA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SNVS_Register_Masks */


/*!
 * @}
 */ /* end of group SNVS_Peripheral_Access_Layer */


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


#endif  /* PERI_SNVS_H_ */

