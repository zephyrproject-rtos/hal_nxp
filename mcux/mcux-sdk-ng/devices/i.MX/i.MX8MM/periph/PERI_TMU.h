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
**         CMSIS Peripheral Access Layer for TMU
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
 * @file PERI_TMU.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TMU
 *
 * CMSIS Peripheral Access Layer for TMU
 */

#if !defined(PERI_TMU_H_)
#define PERI_TMU_H_                              /**< Symbol preventing repeated inclusion */

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
   -- TMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMU_Peripheral_Access_Layer TMU Peripheral Access Layer
 * @{
 */

/** TMU - Register Layout Typedef */
typedef struct {
  __IO uint32_t TER;                               /**< TMU Enable Register, offset: 0x0 */
  __I  uint32_t TSR;                               /**< TMU Status register, offset: 0x4 */
  __IO uint32_t TIER;                              /**< TMU Interrupt Enable register, offset: 0x8 */
  __IO uint32_t TIDR;                              /**< TMU Interrupt Detect register, offset: 0xC */
  __IO uint32_t TMHTITR;                           /**< TMU Monitor High Temperature Immediate Threshold register, offset: 0x10 */
  __IO uint32_t TMHTATR;                           /**< TMU Monitor High Temperature Average threshold register, offset: 0x14 */
  __IO uint32_t TMHTACTR;                          /**< TMU Monitor High Temperature Average Critical Threshold register, offset: 0x18 */
  __I  uint32_t TSCR;                              /**< TMU Sensor Calibration register, offset: 0x1C */
  __I  uint32_t TRITSR;                            /**< TMU Report Immediate Temperature Site register n, offset: 0x20 */
  __I  uint32_t TRATSR;                            /**< TMU Report Average Temperature Site register n, offset: 0x24 */
  __IO uint32_t TASR;                              /**< offset: 0x28 */
       uint8_t RESERVED_0[4];
  __IO uint32_t TCALIV;                            /**< offset: 0x30 */
} TMU_Type;

/* ----------------------------------------------------------------------------
   -- TMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMU_Register_Masks TMU Register Masks
 * @{
 */

/*! @name TER - TMU Enable Register */
/*! @{ */

#define TMU_TER_ALPF_MASK                        (0x3U)
#define TMU_TER_ALPF_SHIFT                       (0U)
/*! ALPF
 *  0b00..1.0
 *  0b01..0.5
 *  0b10..0.25
 *  0b11..0.125
 */
#define TMU_TER_ALPF(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TER_ALPF_SHIFT)) & TMU_TER_ALPF_MASK)

#define TMU_TER_EN_MASK                          (0x80000000U)
#define TMU_TER_EN_SHIFT                         (31U)
/*! EN
 *  0b0..No monitoring
 *  0b1..Enable monitoring
 */
#define TMU_TER_EN(x)                            (((uint32_t)(((uint32_t)(x)) << TMU_TER_EN_SHIFT)) & TMU_TER_EN_MASK)
/*! @} */

/*! @name TSR - TMU Status register */
/*! @{ */

#define TMU_TSR_TB_MASK                          (0x80000000U)
#define TMU_TSR_TB_SHIFT                         (31U)
/*! TB
 *  0b0..TMU idle.
 *  0b1..TMU busy. In monitoring mode this indicates a temperature measurement is pending. In calibration mode,
 *       sensor result has not yet been determined based on last given ambient temperature.
 */
#define TMU_TSR_TB(x)                            (((uint32_t)(((uint32_t)(x)) << TMU_TSR_TB_SHIFT)) & TMU_TSR_TB_MASK)
/*! @} */

/*! @name TIER - TMU Interrupt Enable register */
/*! @{ */

#define TMU_TIER_ATCTEIE_MASK                    (0x20000000U)
#define TMU_TIER_ATCTEIE_SHIFT                   (29U)
/*! ATCTEIE
 *  0b0..Disabled.
 *  0b1..Interrupt enabled. Generate an interrupt if TIDR[ATCTE] is set. Write 1 to this bit will clear bit TIDR[ATCTE].
 */
#define TMU_TIER_ATCTEIE(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ATCTEIE_SHIFT)) & TMU_TIER_ATCTEIE_MASK)

#define TMU_TIER_ATTEIE_MASK                     (0x40000000U)
#define TMU_TIER_ATTEIE_SHIFT                    (30U)
/*! ATTEIE
 *  0b0..Disabled.
 *  0b1..Interrupt enabled. Generate an interrupt if TIDR[ATTE] is set. Write 1 to this bit will clear bit TIDR[ATTE].
 */
#define TMU_TIER_ATTEIE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ATTEIE_SHIFT)) & TMU_TIER_ATTEIE_MASK)

#define TMU_TIER_ITTEIE_MASK                     (0x80000000U)
#define TMU_TIER_ITTEIE_SHIFT                    (31U)
/*! ITTEIE
 *  0b0..Disabled.
 *  0b1..Interrupt enabled. Generate an interrupt if TIDR[ITTE] is set. Write 1 to this bit will clear bit TIDR[ITTE].
 */
#define TMU_TIER_ITTEIE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ITTEIE_SHIFT)) & TMU_TIER_ITTEIE_MASK)
/*! @} */

/*! @name TIDR - TMU Interrupt Detect register */
/*! @{ */

#define TMU_TIDR_ATCTE_MASK                      (0x10000000U)
#define TMU_TIDR_ATCTE_SHIFT                     (28U)
/*! ATCTE
 *  0b0..No threshold exceeded.
 *  0b1..Average temperature critical threshold, as defined by TMHTACTR, has been exceeded.
 */
#define TMU_TIDR_ATCTE(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ATCTE_SHIFT)) & TMU_TIDR_ATCTE_MASK)

#define TMU_TIDR_ATTE_MASK                       (0x20000000U)
#define TMU_TIDR_ATTE_SHIFT                      (29U)
/*! ATTE
 *  0b0..No threshold exceeded.
 *  0b1..Average temperature threshold, as defined by TMHTATR, has been exceeded.
 */
#define TMU_TIDR_ATTE(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ATTE_SHIFT)) & TMU_TIDR_ATTE_MASK)

#define TMU_TIDR_ITTE_MASK                       (0x40000000U)
#define TMU_TIDR_ITTE_SHIFT                      (30U)
/*! ITTE
 *  0b0..No threshold exceeded.
 *  0b1..Immediate temperature threshold, as defined by TMHTITR, has been exceeded. This includes an out-of-range
 *       measured temperature above 125degree C.
 */
#define TMU_TIDR_ITTE(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ITTE_SHIFT)) & TMU_TIDR_ITTE_MASK)
/*! @} */

/*! @name TMHTITR - TMU Monitor High Temperature Immediate Threshold register */
/*! @{ */

#define TMU_TMHTITR_TEMP_MASK                    (0xFFU)
#define TMU_TMHTITR_TEMP_SHIFT                   (0U)
#define TMU_TMHTITR_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMHTITR_TEMP_SHIFT)) & TMU_TMHTITR_TEMP_MASK)

#define TMU_TMHTITR_EN_MASK                      (0x80000000U)
#define TMU_TMHTITR_EN_SHIFT                     (31U)
/*! EN
 *  0b0..Disabled.
 *  0b1..Threshold enabled.
 */
#define TMU_TMHTITR_EN(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMHTITR_EN_SHIFT)) & TMU_TMHTITR_EN_MASK)
/*! @} */

/*! @name TMHTATR - TMU Monitor High Temperature Average threshold register */
/*! @{ */

#define TMU_TMHTATR_TEMP_MASK                    (0xFFU)
#define TMU_TMHTATR_TEMP_SHIFT                   (0U)
#define TMU_TMHTATR_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMHTATR_TEMP_SHIFT)) & TMU_TMHTATR_TEMP_MASK)

#define TMU_TMHTATR_EN_MASK                      (0x80000000U)
#define TMU_TMHTATR_EN_SHIFT                     (31U)
/*! EN
 *  0b0..Disabled.
 *  0b1..Threshold enabled.
 */
#define TMU_TMHTATR_EN(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMHTATR_EN_SHIFT)) & TMU_TMHTATR_EN_MASK)
/*! @} */

/*! @name TMHTACTR - TMU Monitor High Temperature Average Critical Threshold register */
/*! @{ */

#define TMU_TMHTACTR_TEMP_MASK                   (0xFFU)
#define TMU_TMHTACTR_TEMP_SHIFT                  (0U)
#define TMU_TMHTACTR_TEMP(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TMHTACTR_TEMP_SHIFT)) & TMU_TMHTACTR_TEMP_MASK)

#define TMU_TMHTACTR_EN_MASK                     (0x80000000U)
#define TMU_TMHTACTR_EN_SHIFT                    (31U)
/*! EN
 *  0b0..Disabled.
 *  0b1..Threshold enabled.
 */
#define TMU_TMHTACTR_EN(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TMHTACTR_EN_SHIFT)) & TMU_TMHTACTR_EN_MASK)
/*! @} */

/*! @name TSCR - TMU Sensor Calibration register */
/*! @{ */

#define TMU_TSCR_SENSOR_MASK                     (0xFFU)
#define TMU_TSCR_SENSOR_SHIFT                    (0U)
#define TMU_TSCR_SENSOR(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TSCR_SENSOR_SHIFT)) & TMU_TSCR_SENSOR_MASK)

#define TMU_TSCR_BSR_MASK                        (0x80000000U)
#define TMU_TSCR_BSR_SHIFT                       (31U)
#define TMU_TSCR_BSR(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TSCR_BSR_SHIFT)) & TMU_TSCR_BSR_MASK)
/*! @} */

/*! @name TRITSR - TMU Report Immediate Temperature Site register n */
/*! @{ */

#define TMU_TRITSR_TEMP_MASK                     (0xFFU)
#define TMU_TRITSR_TEMP_SHIFT                    (0U)
#define TMU_TRITSR_TEMP(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TRITSR_TEMP_SHIFT)) & TMU_TRITSR_TEMP_MASK)

#define TMU_TRITSR_V_MASK                        (0x80000000U)
#define TMU_TRITSR_V_SHIFT                       (31U)
/*! V
 *  0b0..Not valid. Temperature out of sensor range or first measurement still pending.
 *  0b1..Valid.
 */
#define TMU_TRITSR_V(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TRITSR_V_SHIFT)) & TMU_TRITSR_V_MASK)
/*! @} */

/*! @name TRATSR - TMU Report Average Temperature Site register n */
/*! @{ */

#define TMU_TRATSR_TEMP_MASK                     (0xFFU)
#define TMU_TRATSR_TEMP_SHIFT                    (0U)
#define TMU_TRATSR_TEMP(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TRATSR_TEMP_SHIFT)) & TMU_TRATSR_TEMP_MASK)

#define TMU_TRATSR_V_MASK                        (0x80000000U)
#define TMU_TRATSR_V_SHIFT                       (31U)
/*! V
 *  0b0..Not valid. Temperature out of sensor range or first measurement still pending.
 *  0b1..Valid.
 */
#define TMU_TRATSR_V(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TRATSR_V_SHIFT)) & TMU_TRATSR_V_MASK)
/*! @} */

/*! @name TASR -  */
/*! @{ */

#define TMU_TASR_BUF_VERF_SEL_MASK               (0x1FU)
#define TMU_TASR_BUF_VERF_SEL_SHIFT              (0U)
#define TMU_TASR_BUF_VERF_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << TMU_TASR_BUF_VERF_SEL_SHIFT)) & TMU_TASR_BUF_VERF_SEL_MASK)

#define TMU_TASR_BUF_SLOP_SEL_MASK               (0xF0000U)
#define TMU_TASR_BUF_SLOP_SEL_SHIFT              (16U)
#define TMU_TASR_BUF_SLOP_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << TMU_TASR_BUF_SLOP_SEL_SHIFT)) & TMU_TASR_BUF_SLOP_SEL_MASK)
/*! @} */

/*! @name TCALIV -  */
/*! @{ */

#define TMU_TCALIV_SNSR25C_MASK                  (0xFFU)
#define TMU_TCALIV_SNSR25C_SHIFT                 (0U)
#define TMU_TCALIV_SNSR25C(x)                    (((uint32_t)(((uint32_t)(x)) << TMU_TCALIV_SNSR25C_SHIFT)) & TMU_TCALIV_SNSR25C_MASK)

#define TMU_TCALIV_SNSR85C_MASK                  (0xFF0000U)
#define TMU_TCALIV_SNSR85C_SHIFT                 (16U)
#define TMU_TCALIV_SNSR85C(x)                    (((uint32_t)(((uint32_t)(x)) << TMU_TCALIV_SNSR85C_SHIFT)) & TMU_TCALIV_SNSR85C_MASK)

#define TMU_TCALIV_EN_MASK                       (0x80000000U)
#define TMU_TCALIV_EN_SHIFT                      (31U)
#define TMU_TCALIV_EN(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TCALIV_EN_SHIFT)) & TMU_TCALIV_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TMU_Register_Masks */


/*!
 * @}
 */ /* end of group TMU_Peripheral_Access_Layer */


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


#endif  /* PERI_TMU_H_ */

