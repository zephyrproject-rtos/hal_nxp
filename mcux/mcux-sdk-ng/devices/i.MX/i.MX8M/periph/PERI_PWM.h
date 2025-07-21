/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PWM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PWM.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PWM
 *
 * CMSIS Peripheral Access Layer for PWM
 */

#if !defined(PERI_PWM_H_)
#define PERI_PWM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- PWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWM_Peripheral_Access_Layer PWM Peripheral Access Layer
 * @{
 */

/** PWM - Register Layout Typedef */
typedef struct {
  __IO uint32_t PWMCR;                             /**< PWM Control Register, offset: 0x0 */
  __IO uint32_t PWMSR;                             /**< PWM Status Register, offset: 0x4 */
  __IO uint32_t PWMIR;                             /**< PWM Interrupt Register, offset: 0x8 */
  __IO uint32_t PWMSAR;                            /**< PWM Sample Register, offset: 0xC */
  __IO uint32_t PWMPR;                             /**< PWM Period Register, offset: 0x10 */
  __I  uint32_t PWMCNR;                            /**< PWM Counter Register, offset: 0x14 */
} PWM_Type;

/* ----------------------------------------------------------------------------
   -- PWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWM_Register_Masks PWM Register Masks
 * @{
 */

/*! @name PWMCR - PWM Control Register */
/*! @{ */

#define PWM_PWMCR_EN_MASK                        (0x1U)
#define PWM_PWMCR_EN_SHIFT                       (0U)
/*! EN
 *  0b0..PWM disabled
 *  0b1..PWM enabled
 */
#define PWM_PWMCR_EN(x)                          (((uint32_t)(((uint32_t)(x)) << PWM_PWMCR_EN_SHIFT)) & PWM_PWMCR_EN_MASK)

#define PWM_PWMCR_REPEAT_MASK                    (0x6U)
#define PWM_PWMCR_REPEAT_SHIFT                   (1U)
/*! REPEAT
 *  0b00..Use each sample once
 *  0b01..Use each sample twice
 *  0b10..Use each sample four times
 *  0b11..Use each sample eight times
 */
#define PWM_PWMCR_REPEAT(x)                      (((uint32_t)(((uint32_t)(x)) << PWM_PWMCR_REPEAT_SHIFT)) & PWM_PWMCR_REPEAT_MASK)

#define PWM_PWMCR_SWR_MASK                       (0x8U)
#define PWM_PWMCR_SWR_SHIFT                      (3U)
/*! SWR
 *  0b0..PWM is out of reset
 *  0b1..PWM is undergoing reset
 */
#define PWM_PWMCR_SWR(x)                         (((uint32_t)(((uint32_t)(x)) << PWM_PWMCR_SWR_SHIFT)) & PWM_PWMCR_SWR_MASK)

#define PWM_PWMCR_PRESCALER_MASK                 (0xFFF0U)
#define PWM_PWMCR_PRESCALER_SHIFT                (4U)
/*! PRESCALER
 *  0b000000000000..Divide by 1
 *  0b000000000001..Divide by 2
 *  0b111111111111..Divide by 4096
 */
#define PWM_PWMCR_PRESCALER(x)                   (((uint32_t)(((uint32_t)(x)) << PWM_PWMCR_PRESCALER_SHIFT)) & PWM_PWMCR_PRESCALER_MASK)

#define PWM_PWMCR_CLKSRC_MASK                    (0x30000U)
#define PWM_PWMCR_CLKSRC_SHIFT                   (16U)
/*! CLKSRC
 *  0b00..Clock is off
 *  0b01..ipg_clk
 *  0b10..ipg_clk_highfreq
 *  0b11..ipg_clk_32k
 */
#define PWM_PWMCR_CLKSRC(x)                      (((uint32_t)(((uint32_t)(x)) << PWM_PWMCR_CLKSRC_SHIFT)) & PWM_PWMCR_CLKSRC_MASK)

#define PWM_PWMCR_POUTC_MASK                     (0xC0000U)
#define PWM_PWMCR_POUTC_SHIFT                    (18U)
/*! POUTC
 *  0b00..Output pin is set at rollover and cleared at comparison
 *  0b01..Output pin is cleared at rollover and set at comparison
 *  0b10..PWM output is disconnected
 *  0b11..PWM output is disconnected
 */
#define PWM_PWMCR_POUTC(x)                       (((uint32_t)(((uint32_t)(x)) << PWM_PWMCR_POUTC_SHIFT)) & PWM_PWMCR_POUTC_MASK)

#define PWM_PWMCR_HCTR_MASK                      (0x100000U)
#define PWM_PWMCR_HCTR_SHIFT                     (20U)
/*! HCTR
 *  0b0..Half word swapping does not take place
 *  0b1..Half words from write data bus are swapped
 */
#define PWM_PWMCR_HCTR(x)                        (((uint32_t)(((uint32_t)(x)) << PWM_PWMCR_HCTR_SHIFT)) & PWM_PWMCR_HCTR_MASK)

#define PWM_PWMCR_BCTR_MASK                      (0x200000U)
#define PWM_PWMCR_BCTR_SHIFT                     (21U)
/*! BCTR
 *  0b0..byte ordering remains the same
 *  0b1..byte ordering is reversed
 */
#define PWM_PWMCR_BCTR(x)                        (((uint32_t)(((uint32_t)(x)) << PWM_PWMCR_BCTR_SHIFT)) & PWM_PWMCR_BCTR_MASK)

#define PWM_PWMCR_DBGEN_MASK                     (0x400000U)
#define PWM_PWMCR_DBGEN_SHIFT                    (22U)
/*! DBGEN
 *  0b0..Inactive in debug mode
 *  0b1..Active in debug mode
 */
#define PWM_PWMCR_DBGEN(x)                       (((uint32_t)(((uint32_t)(x)) << PWM_PWMCR_DBGEN_SHIFT)) & PWM_PWMCR_DBGEN_MASK)

#define PWM_PWMCR_WAITEN_MASK                    (0x800000U)
#define PWM_PWMCR_WAITEN_SHIFT                   (23U)
/*! WAITEN
 *  0b0..Inactive in wait mode
 *  0b1..Active in wait mode
 */
#define PWM_PWMCR_WAITEN(x)                      (((uint32_t)(((uint32_t)(x)) << PWM_PWMCR_WAITEN_SHIFT)) & PWM_PWMCR_WAITEN_MASK)

#define PWM_PWMCR_DOZEN_MASK                     (0x1000000U)
#define PWM_PWMCR_DOZEN_SHIFT                    (24U)
/*! DOZEN
 *  0b0..Inactive in doze mode
 *  0b1..Active in doze mode
 */
#define PWM_PWMCR_DOZEN(x)                       (((uint32_t)(((uint32_t)(x)) << PWM_PWMCR_DOZEN_SHIFT)) & PWM_PWMCR_DOZEN_MASK)

#define PWM_PWMCR_STOPEN_MASK                    (0x2000000U)
#define PWM_PWMCR_STOPEN_SHIFT                   (25U)
/*! STOPEN
 *  0b0..Inactive in stop mode
 *  0b1..Active in stop mode
 */
#define PWM_PWMCR_STOPEN(x)                      (((uint32_t)(((uint32_t)(x)) << PWM_PWMCR_STOPEN_SHIFT)) & PWM_PWMCR_STOPEN_MASK)

#define PWM_PWMCR_FWM_MASK                       (0xC000000U)
#define PWM_PWMCR_FWM_SHIFT                      (26U)
/*! FWM
 *  0b00..FIFO empty flag is set when there are more than or equal to 1 empty slots in FIFO
 *  0b01..FIFO empty flag is set when there are more than or equal to 2 empty slots in FIFO
 *  0b10..FIFO empty flag is set when there are more than or equal to 3 empty slots in FIFO
 *  0b11..FIFO empty flag is set when there are more than or equal to 4 empty slots in FIFO
 */
#define PWM_PWMCR_FWM(x)                         (((uint32_t)(((uint32_t)(x)) << PWM_PWMCR_FWM_SHIFT)) & PWM_PWMCR_FWM_MASK)
/*! @} */

/*! @name PWMSR - PWM Status Register */
/*! @{ */

#define PWM_PWMSR_FIFOAV_MASK                    (0x7U)
#define PWM_PWMSR_FIFOAV_SHIFT                   (0U)
/*! FIFOAV
 *  0b000..No data available
 *  0b001..1 word of data in FIFO
 *  0b010..2 words of data in FIFO
 *  0b011..3 words of data in FIFO
 *  0b100..4 words of data in FIFO
 *  0b101..unused
 *  0b110..unused
 *  0b111..unused
 */
#define PWM_PWMSR_FIFOAV(x)                      (((uint32_t)(((uint32_t)(x)) << PWM_PWMSR_FIFOAV_SHIFT)) & PWM_PWMSR_FIFOAV_MASK)

#define PWM_PWMSR_FE_MASK                        (0x8U)
#define PWM_PWMSR_FE_SHIFT                       (3U)
/*! FE
 *  0b0..Data level is above water mark
 *  0b1..When the data level falls below the mark set by FWM field
 */
#define PWM_PWMSR_FE(x)                          (((uint32_t)(((uint32_t)(x)) << PWM_PWMSR_FE_SHIFT)) & PWM_PWMSR_FE_MASK)

#define PWM_PWMSR_ROV_MASK                       (0x10U)
#define PWM_PWMSR_ROV_SHIFT                      (4U)
/*! ROV
 *  0b0..Roll-over event not occurred
 *  0b1..Roll-over event occurred
 */
#define PWM_PWMSR_ROV(x)                         (((uint32_t)(((uint32_t)(x)) << PWM_PWMSR_ROV_SHIFT)) & PWM_PWMSR_ROV_MASK)

#define PWM_PWMSR_CMP_MASK                       (0x20U)
#define PWM_PWMSR_CMP_SHIFT                      (5U)
/*! CMP
 *  0b0..Compare event not occurred
 *  0b1..Compare event occurred
 */
#define PWM_PWMSR_CMP(x)                         (((uint32_t)(((uint32_t)(x)) << PWM_PWMSR_CMP_SHIFT)) & PWM_PWMSR_CMP_MASK)

#define PWM_PWMSR_FWE_MASK                       (0x40U)
#define PWM_PWMSR_FWE_SHIFT                      (6U)
/*! FWE
 *  0b0..FIFO write error not occurred
 *  0b1..FIFO write error occurred
 */
#define PWM_PWMSR_FWE(x)                         (((uint32_t)(((uint32_t)(x)) << PWM_PWMSR_FWE_SHIFT)) & PWM_PWMSR_FWE_MASK)
/*! @} */

/*! @name PWMIR - PWM Interrupt Register */
/*! @{ */

#define PWM_PWMIR_FIE_MASK                       (0x1U)
#define PWM_PWMIR_FIE_SHIFT                      (0U)
/*! FIE
 *  0b0..FIFO Empty interrupt disabled
 *  0b1..FIFO Empty interrupt enabled
 */
#define PWM_PWMIR_FIE(x)                         (((uint32_t)(((uint32_t)(x)) << PWM_PWMIR_FIE_SHIFT)) & PWM_PWMIR_FIE_MASK)

#define PWM_PWMIR_RIE_MASK                       (0x2U)
#define PWM_PWMIR_RIE_SHIFT                      (1U)
/*! RIE
 *  0b0..Roll-over interrupt not enabled
 *  0b1..Roll-over Interrupt enabled
 */
#define PWM_PWMIR_RIE(x)                         (((uint32_t)(((uint32_t)(x)) << PWM_PWMIR_RIE_SHIFT)) & PWM_PWMIR_RIE_MASK)

#define PWM_PWMIR_CIE_MASK                       (0x4U)
#define PWM_PWMIR_CIE_SHIFT                      (2U)
/*! CIE
 *  0b0..Compare Interrupt not enabled
 *  0b1..Compare Interrupt enabled
 */
#define PWM_PWMIR_CIE(x)                         (((uint32_t)(((uint32_t)(x)) << PWM_PWMIR_CIE_SHIFT)) & PWM_PWMIR_CIE_MASK)
/*! @} */

/*! @name PWMSAR - PWM Sample Register */
/*! @{ */

#define PWM_PWMSAR_SAMPLE_MASK                   (0xFFFFU)
#define PWM_PWMSAR_SAMPLE_SHIFT                  (0U)
#define PWM_PWMSAR_SAMPLE(x)                     (((uint32_t)(((uint32_t)(x)) << PWM_PWMSAR_SAMPLE_SHIFT)) & PWM_PWMSAR_SAMPLE_MASK)
/*! @} */

/*! @name PWMPR - PWM Period Register */
/*! @{ */

#define PWM_PWMPR_PERIOD_MASK                    (0xFFFFU)
#define PWM_PWMPR_PERIOD_SHIFT                   (0U)
#define PWM_PWMPR_PERIOD(x)                      (((uint32_t)(((uint32_t)(x)) << PWM_PWMPR_PERIOD_SHIFT)) & PWM_PWMPR_PERIOD_MASK)
/*! @} */

/*! @name PWMCNR - PWM Counter Register */
/*! @{ */

#define PWM_PWMCNR_COUNT_MASK                    (0xFFFFU)
#define PWM_PWMCNR_COUNT_SHIFT                   (0U)
#define PWM_PWMCNR_COUNT(x)                      (((uint32_t)(((uint32_t)(x)) << PWM_PWMCNR_COUNT_SHIFT)) & PWM_PWMCNR_COUNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PWM_Register_Masks */


/*!
 * @}
 */ /* end of group PWM_Peripheral_Access_Layer */


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


#endif  /* PERI_PWM_H_ */

