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
 * @file PERI_TMU.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TMU
 *
 * CMSIS Peripheral Access Layer for TMU
 */

#if !defined(PERI_TMU_H_)
#define PERI_TMU_H_                              /**< Symbol preventing repeated inclusion */

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
   -- TMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMU_Peripheral_Access_Layer TMU Peripheral Access Layer
 * @{
 */

/** TMU - Size of Registers Arrays */
#define TMU_TRTSR_COUNT                           16u
#define TMU_TTRCR_COUNT                           4u

/** TMU - Register Layout Typedef */
typedef struct {
  __IO uint32_t TMR;                               /**< TMU Mode register, offset: 0x0 */
  __I  uint32_t TSR;                               /**< TMU Status register, offset: 0x4 */
  __IO uint32_t TMTMIR;                            /**< TMU Monitor Temperature Measurement Interval register, offset: 0x8 */
       uint8_t RESERVED_0[20];
  __IO uint32_t TIER;                              /**< TMU Interrupt Enable register, offset: 0x20 */
  __IO uint32_t TIDR;                              /**< TMU Interrupt Detect register, offset: 0x24 */
  __IO uint32_t TISCR;                             /**< TMU Interrupt Site Capture register, offset: 0x28 */
  __IO uint32_t TICSCR;                            /**< TMU Interrupt Critical Site Capture register, offset: 0x2C */
       uint8_t RESERVED_1[16];
  __I  uint32_t TMHTCRH;                           /**< TMU Monitor High Temperature Capture register, offset: 0x40 */
  __I  uint32_t TMHTCRL;                           /**< TMU Monitor Low Temperature Capture register, offset: 0x44 */
       uint8_t RESERVED_2[8];
  __IO uint32_t TMHTITR;                           /**< TMU Monitor High Temperature Immediate Threshold register, offset: 0x50 */
  __IO uint32_t TMHTATR;                           /**< TMU Monitor High Temperature Average threshold register, offset: 0x54 */
  __IO uint32_t TMHTACTR;                          /**< TMU Monitor High Temperature Average Critical Threshold register, offset: 0x58 */
       uint8_t RESERVED_3[36];
  __IO uint32_t TTCFGR;                            /**< TMU Temperature Configuration register, offset: 0x80 */
  __IO uint32_t TSCFGR;                            /**< TMU Sensor Configuration register, offset: 0x84 */
       uint8_t RESERVED_4[120];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    __I  uint32_t TRITSR;                            /**< TMU Report Immediate Temperature Site register n, array offset: 0x100, array step: 0x10 */
    __I  uint32_t TRATSR;                            /**< TMU Report Average Temperature Site register n, array offset: 0x104, array step: 0x10 */
         uint8_t RESERVED_0[8];
  } TRTSR[TMU_TRTSR_COUNT];
       uint8_t RESERVED_5[2552];
  __I  uint32_t IPBRR0;                            /**< IP Block Revision register 0, offset: 0xBF8 */
       uint8_t RESERVED_6[788];
  __IO uint32_t TTRCR[TMU_TTRCR_COUNT];            /**< TMU Temperature Range n Control register, array offset: 0xF10, array step: 0x4 */
} TMU_Type;

/* ----------------------------------------------------------------------------
   -- TMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TMU_Register_Masks TMU Register Masks
 * @{
 */

/*! @name TMR - TMU Mode register */
/*! @{ */

#define TMU_TMR_MSITE_MASK                       (0xFFFFU)
#define TMU_TMR_MSITE_SHIFT                      (0U)
#define TMU_TMR_MSITE(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TMR_MSITE_SHIFT)) & TMU_TMR_MSITE_MASK)

#define TMU_TMR_ALPF_MASK                        (0xC000000U)
#define TMU_TMR_ALPF_SHIFT                       (26U)
/*! ALPF
 *  0b00..1.0
 *  0b01..0.5
 *  0b10..0.25
 *  0b11..0.125
 */
#define TMU_TMR_ALPF(x)                          (((uint32_t)(((uint32_t)(x)) << TMU_TMR_ALPF_SHIFT)) & TMU_TMR_ALPF_MASK)

#define TMU_TMR_ME_MASK                          (0x80000000U)
#define TMU_TMR_ME_SHIFT                         (31U)
/*! ME
 *  0b0..No monitoring. Power saving mode.
 *  0b1..Monitoring of sites as defined by MSITE.
 */
#define TMU_TMR_ME(x)                            (((uint32_t)(((uint32_t)(x)) << TMU_TMR_ME_SHIFT)) & TMU_TMR_ME_MASK)
/*! @} */

/*! @name TSR - TMU Status register */
/*! @{ */

#define TMU_TSR_ORH_MASK                         (0x10000000U)
#define TMU_TSR_ORH_SHIFT                        (28U)
#define TMU_TSR_ORH(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TSR_ORH_SHIFT)) & TMU_TSR_ORH_MASK)

#define TMU_TSR_ORL_MASK                         (0x20000000U)
#define TMU_TSR_ORL_SHIFT                        (29U)
#define TMU_TSR_ORL(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TSR_ORL_SHIFT)) & TMU_TSR_ORL_MASK)

#define TMU_TSR_MIE_MASK                         (0x40000000U)
#define TMU_TSR_MIE_SHIFT                        (30U)
/*! MIE
 *  0b0..Monitoring interval not exceeded.
 *  0b1..Monitoring interval exceeded. The time required to perform measurement of all monitored sites has
 *       exceeded the monitoring interval as defined by TMTMIR.
 */
#define TMU_TSR_MIE(x)                           (((uint32_t)(((uint32_t)(x)) << TMU_TSR_MIE_SHIFT)) & TMU_TSR_MIE_MASK)
/*! @} */

/*! @name TMTMIR - TMU Monitor Temperature Measurement Interval register */
/*! @{ */

#define TMU_TMTMIR_TMI_MASK                      (0xFU)
#define TMU_TMTMIR_TMI_SHIFT                     (0U)
#define TMU_TMTMIR_TMI(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TMTMIR_TMI_SHIFT)) & TMU_TMTMIR_TMI_MASK)
/*! @} */

/*! @name TIER - TMU Interrupt Enable register */
/*! @{ */

#define TMU_TIER_ATCTEIE_MASK                    (0x20000000U)
#define TMU_TIER_ATCTEIE_SHIFT                   (29U)
/*! ATCTEIE
 *  0b0..Disabled.
 *  0b1..Interrupt enabled. Generate an interrupt if TIDR[ATCTE] is set.
 */
#define TMU_TIER_ATCTEIE(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ATCTEIE_SHIFT)) & TMU_TIER_ATCTEIE_MASK)

#define TMU_TIER_ATTEIE_MASK                     (0x40000000U)
#define TMU_TIER_ATTEIE_SHIFT                    (30U)
/*! ATTEIE
 *  0b0..Disabled.
 *  0b1..Interrupt enabled. Generate an interrupt if TIDR[ATTE] is set.
 */
#define TMU_TIER_ATTEIE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ATTEIE_SHIFT)) & TMU_TIER_ATTEIE_MASK)

#define TMU_TIER_ITTEIE_MASK                     (0x80000000U)
#define TMU_TIER_ITTEIE_SHIFT                    (31U)
/*! ITTEIE
 *  0b0..Disabled.
 *  0b1..Interrupt enabled. Generate an interrupt if TIDR[ITTE] is set.
 */
#define TMU_TIER_ITTEIE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TIER_ITTEIE_SHIFT)) & TMU_TIER_ITTEIE_MASK)
/*! @} */

/*! @name TIDR - TMU Interrupt Detect register */
/*! @{ */

#define TMU_TIDR_ATCTE_MASK                      (0x20000000U)
#define TMU_TIDR_ATCTE_SHIFT                     (29U)
/*! ATCTE
 *  0b0..No threshold exceeded.
 *  0b1..Average temperature critical threshold, as defined by TMHTACTR, has been exceeded by one or more
 *       monitored sites. The sites which has exceeded the threshold are captured in TICSCR[CASITE].
 */
#define TMU_TIDR_ATCTE(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ATCTE_SHIFT)) & TMU_TIDR_ATCTE_MASK)

#define TMU_TIDR_ATTE_MASK                       (0x40000000U)
#define TMU_TIDR_ATTE_SHIFT                      (30U)
/*! ATTE
 *  0b0..No threshold exceeded.
 *  0b1..Average temperature threshold, as defined by TMHTATR, has been exceeded by one or more monitored sites.
 *       The sites which has exceeded the threshold are captured in TISCR[ASITE].
 */
#define TMU_TIDR_ATTE(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ATTE_SHIFT)) & TMU_TIDR_ATTE_MASK)

#define TMU_TIDR_ITTE_MASK                       (0x80000000U)
#define TMU_TIDR_ITTE_SHIFT                      (31U)
/*! ITTE
 *  0b0..No threshold exceeded.
 *  0b1..Immediate temperature threshold, as defined by TMHTITR, has been exceeded by one or more monitored sites.
 *       This includes an out-of-range measured temperature above 125degree C. The sites which has exceeded the
 *       threshold are captured in TISCR[ISITE].
 */
#define TMU_TIDR_ITTE(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TIDR_ITTE_SHIFT)) & TMU_TIDR_ITTE_MASK)
/*! @} */

/*! @name TISCR - TMU Interrupt Site Capture register */
/*! @{ */

#define TMU_TISCR_ASITE_MASK                     (0xFFFFU)
#define TMU_TISCR_ASITE_SHIFT                    (0U)
#define TMU_TISCR_ASITE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TISCR_ASITE_SHIFT)) & TMU_TISCR_ASITE_MASK)

#define TMU_TISCR_ISITE_MASK                     (0xFFFF0000U)
#define TMU_TISCR_ISITE_SHIFT                    (16U)
#define TMU_TISCR_ISITE(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TISCR_ISITE_SHIFT)) & TMU_TISCR_ISITE_MASK)
/*! @} */

/*! @name TICSCR - TMU Interrupt Critical Site Capture register */
/*! @{ */

#define TMU_TICSCR_CASITE_MASK                   (0xFFFFU)
#define TMU_TICSCR_CASITE_SHIFT                  (0U)
#define TMU_TICSCR_CASITE(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TICSCR_CASITE_SHIFT)) & TMU_TICSCR_CASITE_MASK)
/*! @} */

/*! @name TMHTCRH - TMU Monitor High Temperature Capture register */
/*! @{ */

#define TMU_TMHTCRH_TEMP_MASK                    (0xFFU)
#define TMU_TMHTCRH_TEMP_SHIFT                   (0U)
#define TMU_TMHTCRH_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMHTCRH_TEMP_SHIFT)) & TMU_TMHTCRH_TEMP_MASK)

#define TMU_TMHTCRH_V_MASK                       (0x80000000U)
#define TMU_TMHTCRH_V_SHIFT                      (31U)
/*! V
 *  0b0..Temperature reading is not valid due to no measured temperature within the sensor range of 0-125 degree C for an enabled monitored site.
 *  0b1..Temperature reading is valid.
 */
#define TMU_TMHTCRH_V(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TMHTCRH_V_SHIFT)) & TMU_TMHTCRH_V_MASK)
/*! @} */

/*! @name TMHTCRL - TMU Monitor Low Temperature Capture register */
/*! @{ */

#define TMU_TMHTCRL_TEMP_MASK                    (0xFFU)
#define TMU_TMHTCRL_TEMP_SHIFT                   (0U)
#define TMU_TMHTCRL_TEMP(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_TMHTCRL_TEMP_SHIFT)) & TMU_TMHTCRL_TEMP_MASK)

#define TMU_TMHTCRL_V_MASK                       (0x80000000U)
#define TMU_TMHTCRL_V_SHIFT                      (31U)
/*! V
 *  0b0..Temperature reading is not valid due to no measured temperature within the sensor range of 0-125 degree C for an enabled monitored site.
 *  0b1..Temperature reading is valid.
 */
#define TMU_TMHTCRL_V(x)                         (((uint32_t)(((uint32_t)(x)) << TMU_TMHTCRL_V_SHIFT)) & TMU_TMHTCRL_V_MASK)
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

/*! @name TTCFGR - TMU Temperature Configuration register */
/*! @{ */

#define TMU_TTCFGR_DATA_MASK                     (0xFFFFFFFFU)
#define TMU_TTCFGR_DATA_SHIFT                    (0U)
#define TMU_TTCFGR_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TTCFGR_DATA_SHIFT)) & TMU_TTCFGR_DATA_MASK)
/*! @} */

/*! @name TSCFGR - TMU Sensor Configuration register */
/*! @{ */

#define TMU_TSCFGR_DATA_MASK                     (0xFFFFFFFFU)
#define TMU_TSCFGR_DATA_SHIFT                    (0U)
#define TMU_TSCFGR_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << TMU_TSCFGR_DATA_SHIFT)) & TMU_TSCFGR_DATA_MASK)
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

/* The count of TMU_TRITSR */
#define TMU_TRITSR_COUNT                         (16U)

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

/* The count of TMU_TRATSR */
#define TMU_TRATSR_COUNT                         (16U)

/*! @name IPBRR0 - IP Block Revision register 0 */
/*! @{ */

#define TMU_IPBRR0_IP_MN_MASK                    (0xFFU)
#define TMU_IPBRR0_IP_MN_SHIFT                   (0U)
#define TMU_IPBRR0_IP_MN(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_IPBRR0_IP_MN_SHIFT)) & TMU_IPBRR0_IP_MN_MASK)

#define TMU_IPBRR0_IP_MJ_MASK                    (0xFF00U)
#define TMU_IPBRR0_IP_MJ_SHIFT                   (8U)
#define TMU_IPBRR0_IP_MJ(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_IPBRR0_IP_MJ_SHIFT)) & TMU_IPBRR0_IP_MJ_MASK)

#define TMU_IPBRR0_IP_ID_MASK                    (0xFFFF0000U)
#define TMU_IPBRR0_IP_ID_SHIFT                   (16U)
#define TMU_IPBRR0_IP_ID(x)                      (((uint32_t)(((uint32_t)(x)) << TMU_IPBRR0_IP_ID_SHIFT)) & TMU_IPBRR0_IP_ID_MASK)
/*! @} */

/*! @name TTRCR - TMU Temperature Range n Control register */
/*! @{ */

#define TMU_TTRCR_TEMP_MASK                      (0xFFU)
#define TMU_TTRCR_TEMP_SHIFT                     (0U)
#define TMU_TTRCR_TEMP(x)                        (((uint32_t)(((uint32_t)(x)) << TMU_TTRCR_TEMP_SHIFT)) & TMU_TTRCR_TEMP_MASK)

#define TMU_TTRCR_CAL_PTS_MASK                   (0xF0000U)
#define TMU_TTRCR_CAL_PTS_SHIFT                  (16U)
#define TMU_TTRCR_CAL_PTS(x)                     (((uint32_t)(((uint32_t)(x)) << TMU_TTRCR_CAL_PTS_SHIFT)) & TMU_TTRCR_CAL_PTS_MASK)
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

