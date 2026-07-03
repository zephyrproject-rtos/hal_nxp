/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GICP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_GICP.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for GICP
 *
 * CMSIS Peripheral Access Layer for GICP
 */

#if !defined(PERI_GICP_H_)
#define PERI_GICP_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
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
   -- GICP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GICP_Peripheral_Access_Layer GICP Peripheral Access Layer
 * @{
 */

/** GICP - Register Layout Typedef */
typedef struct {
  __IO uint32_t GICP_EVCNTR0;                      /**< GICP_EVCNTR0, offset: 0x0 */
  __IO uint32_t GICP_EVCNTR1;                      /**< GICP_EVCNTR1, offset: 0x4 */
  __IO uint32_t GICP_EVCNTR2;                      /**< GICP_EVCNTR2, offset: 0x8 */
  __IO uint32_t GICP_EVCNTR3;                      /**< GICP_EVCNTR3, offset: 0xC */
  __IO uint32_t GICP_EVCNTR4;                      /**< GICP_EVCNTR4, offset: 0x10 */
       uint8_t RESERVED_0[1004];
  __IO uint32_t GICP_EVTYPER0;                     /**< GICP_EVTYPER0, offset: 0x400 */
  __IO uint32_t GICP_EVTYPER1;                     /**< GICP_EVTYPER1, offset: 0x404 */
  __IO uint32_t GICP_EVTYPER2;                     /**< GICP_EVTYPER2, offset: 0x408 */
  __IO uint32_t GICP_EVTYPER3;                     /**< GICP_EVTYPER3, offset: 0x40C */
  __IO uint32_t GICP_EVTYPER4;                     /**< GICP_EVTYPER4, offset: 0x410 */
       uint8_t RESERVED_1[492];
  __I  uint32_t GICP_SVR0;                         /**< GICP_SVR0, offset: 0x600 */
  __I  uint32_t GICP_SVR1;                         /**< GICP_SVR1, offset: 0x604 */
  __I  uint32_t GICP_SVR2;                         /**< GICP_SVR2, offset: 0x608 */
  __I  uint32_t GICP_SVR3;                         /**< GICP_SVR3, offset: 0x60C */
  __I  uint32_t GICP_SVR4;                         /**< GICP_SVR4, offset: 0x610 */
       uint8_t RESERVED_2[1004];
  __IO uint32_t GICP_FR0;                          /**< GICP_FR0, offset: 0xA00 */
  __IO uint32_t GICP_FR1;                          /**< GICP_FR1, offset: 0xA04 */
  __IO uint32_t GICP_FR2;                          /**< GICP_FR2, offset: 0xA08 */
  __IO uint32_t GICP_FR3;                          /**< GICP_FR3, offset: 0xA0C */
  __IO uint32_t GICP_FR4;                          /**< GICP_FR4, offset: 0xA10 */
       uint8_t RESERVED_3[492];
  __IO uint64_t GICP_CNTENSET0;                    /**< GICP_CNTENSET0, offset: 0xC00 */
       uint8_t RESERVED_4[24];
  __IO uint64_t GICP_CNTENCLR0;                    /**< GICP_CNTENCLR0, offset: 0xC20 */
       uint8_t RESERVED_5[24];
  __IO uint64_t GICP_INTENSET0;                    /**< GICP_INTENSET0, offset: 0xC40 */
       uint8_t RESERVED_6[24];
  __IO uint64_t GICP_INTENCLR0;                    /**< GICP_INTENCLR0, offset: 0xC60 */
       uint8_t RESERVED_7[24];
  __IO uint64_t GICP_OVSCLR0;                      /**< GICP_OVSCLR0, offset: 0xC80 */
       uint8_t RESERVED_8[56];
  __IO uint64_t GICP_OVSSET0;                      /**< GICP_OVSSET0, offset: 0xCC0 */
       uint8_t RESERVED_9[192];
  __O  uint32_t GICP_CAPR;                         /**< GICP_CAPR, offset: 0xD88 */
       uint8_t RESERVED_10[116];
  __I  uint32_t GICP_CFGR;                         /**< GICP_CFGR, offset: 0xE00 */
  __IO uint32_t GICP_CR;                           /**< GICP_CR, offset: 0xE04 */
       uint8_t RESERVED_11[72];
  __IO uint32_t GICP_IRQCR;                        /**< GICP_IRQCR, offset: 0xE50 */
       uint8_t RESERVED_12[356];
  __I  uint32_t GICP_PMAUTHSTATUS;                 /**< GICP_PMAUTHSTATUS, offset: 0xFB8 */
  __I  uint32_t GICP_PMDEVARCH;                    /**< GICP_PMDEVARCH, offset: 0xFBC */
       uint8_t RESERVED_13[12];
  __I  uint32_t GICP_PMDEVTYPE;                    /**< GICP_PMDEVTYPE, offset: 0xFCC */
  __I  uint32_t GICP_PIDR4;                        /**< GICP_PIDR4, offset: 0xFD0 */
  __I  uint32_t GICP_PIDR5;                        /**< GICP_PIDR5, offset: 0xFD4 */
  __I  uint32_t GICP_PIDR6;                        /**< GICP_PIDR6, offset: 0xFD8 */
  __I  uint32_t GICP_PIDR7;                        /**< GICP_PIDR7, offset: 0xFDC */
  __I  uint32_t GICP_PIDR0;                        /**< GICP_PIDR0, offset: 0xFE0 */
  __I  uint32_t GICP_PIDR1;                        /**< GICP_PIDR1, offset: 0xFE4 */
  __I  uint32_t GICP_PIDR2;                        /**< GICP_PIDR2, offset: 0xFE8 */
  __I  uint32_t GICP_PIDR3;                        /**< GICP_PIDR3, offset: 0xFEC */
  __I  uint32_t GICP_CIDR0;                        /**< GICP_CIDR0, offset: 0xFF0 */
  __I  uint32_t GICP_CIDR1;                        /**< GICP_CIDR1, offset: 0xFF4 */
  __I  uint32_t GICP_CIDR2;                        /**< GICP_CIDR2, offset: 0xFF8 */
  __I  uint32_t GICP_CIDR3;                        /**< GICP_CIDR3, offset: 0xFFC */
} GICP_Type;

/* ----------------------------------------------------------------------------
   -- GICP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GICP_Register_Masks GICP Register Masks
 * @{
 */

/*! @name GICP_EVCNTR0 - GICP_EVCNTR0 */
/*! @{ */

#define GICP_GICP_EVCNTR0_COUNT_MASK             (0xFFFFFFFFU)
#define GICP_GICP_EVCNTR0_COUNT_SHIFT            (0U)
/*! COUNT - COUNT */
#define GICP_GICP_EVCNTR0_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVCNTR0_COUNT_SHIFT)) & GICP_GICP_EVCNTR0_COUNT_MASK)
/*! @} */

/*! @name GICP_EVCNTR1 - GICP_EVCNTR1 */
/*! @{ */

#define GICP_GICP_EVCNTR1_COUNT_MASK             (0xFFFFFFFFU)
#define GICP_GICP_EVCNTR1_COUNT_SHIFT            (0U)
/*! COUNT - COUNT */
#define GICP_GICP_EVCNTR1_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVCNTR1_COUNT_SHIFT)) & GICP_GICP_EVCNTR1_COUNT_MASK)
/*! @} */

/*! @name GICP_EVCNTR2 - GICP_EVCNTR2 */
/*! @{ */

#define GICP_GICP_EVCNTR2_COUNT_MASK             (0xFFFFFFFFU)
#define GICP_GICP_EVCNTR2_COUNT_SHIFT            (0U)
/*! COUNT - COUNT */
#define GICP_GICP_EVCNTR2_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVCNTR2_COUNT_SHIFT)) & GICP_GICP_EVCNTR2_COUNT_MASK)
/*! @} */

/*! @name GICP_EVCNTR3 - GICP_EVCNTR3 */
/*! @{ */

#define GICP_GICP_EVCNTR3_COUNT_MASK             (0xFFFFFFFFU)
#define GICP_GICP_EVCNTR3_COUNT_SHIFT            (0U)
/*! COUNT - COUNT */
#define GICP_GICP_EVCNTR3_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVCNTR3_COUNT_SHIFT)) & GICP_GICP_EVCNTR3_COUNT_MASK)
/*! @} */

/*! @name GICP_EVCNTR4 - GICP_EVCNTR4 */
/*! @{ */

#define GICP_GICP_EVCNTR4_COUNT_MASK             (0xFFFFFFFFU)
#define GICP_GICP_EVCNTR4_COUNT_SHIFT            (0U)
/*! COUNT - COUNT */
#define GICP_GICP_EVCNTR4_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVCNTR4_COUNT_SHIFT)) & GICP_GICP_EVCNTR4_COUNT_MASK)
/*! @} */

/*! @name GICP_EVTYPER0 - GICP_EVTYPER0 */
/*! @{ */

#define GICP_GICP_EVTYPER0_EVENT_MASK            (0xFFU)
#define GICP_GICP_EVTYPER0_EVENT_SHIFT           (0U)
/*! EVENT - EVENT */
#define GICP_GICP_EVTYPER0_EVENT(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER0_EVENT_SHIFT)) & GICP_GICP_EVTYPER0_EVENT_MASK)

#define GICP_GICP_EVTYPER0_RESERVED0_MASK        (0xFF00U)
#define GICP_GICP_EVTYPER0_RESERVED0_SHIFT       (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_EVTYPER0_RESERVED0(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER0_RESERVED0_SHIFT)) & GICP_GICP_EVTYPER0_RESERVED0_MASK)

#define GICP_GICP_EVTYPER0_EVENT_TYPE_MASK       (0x30000U)
#define GICP_GICP_EVTYPER0_EVENT_TYPE_SHIFT      (16U)
/*! EVENT_TYPE - EVENT_TYPE */
#define GICP_GICP_EVTYPER0_EVENT_TYPE(x)         (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER0_EVENT_TYPE_SHIFT)) & GICP_GICP_EVTYPER0_EVENT_TYPE_MASK)

#define GICP_GICP_EVTYPER0_RESERVED1_MASK        (0x7FFC0000U)
#define GICP_GICP_EVTYPER0_RESERVED1_SHIFT       (18U)
/*! RESERVED1 - RESERVED1 */
#define GICP_GICP_EVTYPER0_RESERVED1(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER0_RESERVED1_SHIFT)) & GICP_GICP_EVTYPER0_RESERVED1_MASK)

#define GICP_GICP_EVTYPER0_OVCAP_MASK            (0x80000000U)
#define GICP_GICP_EVTYPER0_OVCAP_SHIFT           (31U)
/*! OVCAP - OVCAP */
#define GICP_GICP_EVTYPER0_OVCAP(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER0_OVCAP_SHIFT)) & GICP_GICP_EVTYPER0_OVCAP_MASK)
/*! @} */

/*! @name GICP_EVTYPER1 - GICP_EVTYPER1 */
/*! @{ */

#define GICP_GICP_EVTYPER1_EVENT_MASK            (0xFFU)
#define GICP_GICP_EVTYPER1_EVENT_SHIFT           (0U)
/*! EVENT - EVENT */
#define GICP_GICP_EVTYPER1_EVENT(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER1_EVENT_SHIFT)) & GICP_GICP_EVTYPER1_EVENT_MASK)

#define GICP_GICP_EVTYPER1_RESERVED0_MASK        (0xFF00U)
#define GICP_GICP_EVTYPER1_RESERVED0_SHIFT       (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_EVTYPER1_RESERVED0(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER1_RESERVED0_SHIFT)) & GICP_GICP_EVTYPER1_RESERVED0_MASK)

#define GICP_GICP_EVTYPER1_EVENT_TYPE_MASK       (0x30000U)
#define GICP_GICP_EVTYPER1_EVENT_TYPE_SHIFT      (16U)
/*! EVENT_TYPE - EVENT_TYPE */
#define GICP_GICP_EVTYPER1_EVENT_TYPE(x)         (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER1_EVENT_TYPE_SHIFT)) & GICP_GICP_EVTYPER1_EVENT_TYPE_MASK)

#define GICP_GICP_EVTYPER1_RESERVED1_MASK        (0x7FFC0000U)
#define GICP_GICP_EVTYPER1_RESERVED1_SHIFT       (18U)
/*! RESERVED1 - RESERVED1 */
#define GICP_GICP_EVTYPER1_RESERVED1(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER1_RESERVED1_SHIFT)) & GICP_GICP_EVTYPER1_RESERVED1_MASK)

#define GICP_GICP_EVTYPER1_OVCAP_MASK            (0x80000000U)
#define GICP_GICP_EVTYPER1_OVCAP_SHIFT           (31U)
/*! OVCAP - OVCAP */
#define GICP_GICP_EVTYPER1_OVCAP(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER1_OVCAP_SHIFT)) & GICP_GICP_EVTYPER1_OVCAP_MASK)
/*! @} */

/*! @name GICP_EVTYPER2 - GICP_EVTYPER2 */
/*! @{ */

#define GICP_GICP_EVTYPER2_EVENT_MASK            (0xFFU)
#define GICP_GICP_EVTYPER2_EVENT_SHIFT           (0U)
/*! EVENT - EVENT */
#define GICP_GICP_EVTYPER2_EVENT(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER2_EVENT_SHIFT)) & GICP_GICP_EVTYPER2_EVENT_MASK)

#define GICP_GICP_EVTYPER2_RESERVED0_MASK        (0xFF00U)
#define GICP_GICP_EVTYPER2_RESERVED0_SHIFT       (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_EVTYPER2_RESERVED0(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER2_RESERVED0_SHIFT)) & GICP_GICP_EVTYPER2_RESERVED0_MASK)

#define GICP_GICP_EVTYPER2_EVENT_TYPE_MASK       (0x30000U)
#define GICP_GICP_EVTYPER2_EVENT_TYPE_SHIFT      (16U)
/*! EVENT_TYPE - EVENT_TYPE */
#define GICP_GICP_EVTYPER2_EVENT_TYPE(x)         (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER2_EVENT_TYPE_SHIFT)) & GICP_GICP_EVTYPER2_EVENT_TYPE_MASK)

#define GICP_GICP_EVTYPER2_RESERVED1_MASK        (0x7FFC0000U)
#define GICP_GICP_EVTYPER2_RESERVED1_SHIFT       (18U)
/*! RESERVED1 - RESERVED1 */
#define GICP_GICP_EVTYPER2_RESERVED1(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER2_RESERVED1_SHIFT)) & GICP_GICP_EVTYPER2_RESERVED1_MASK)

#define GICP_GICP_EVTYPER2_OVCAP_MASK            (0x80000000U)
#define GICP_GICP_EVTYPER2_OVCAP_SHIFT           (31U)
/*! OVCAP - OVCAP */
#define GICP_GICP_EVTYPER2_OVCAP(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER2_OVCAP_SHIFT)) & GICP_GICP_EVTYPER2_OVCAP_MASK)
/*! @} */

/*! @name GICP_EVTYPER3 - GICP_EVTYPER3 */
/*! @{ */

#define GICP_GICP_EVTYPER3_EVENT_MASK            (0xFFU)
#define GICP_GICP_EVTYPER3_EVENT_SHIFT           (0U)
/*! EVENT - EVENT */
#define GICP_GICP_EVTYPER3_EVENT(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER3_EVENT_SHIFT)) & GICP_GICP_EVTYPER3_EVENT_MASK)

#define GICP_GICP_EVTYPER3_RESERVED0_MASK        (0xFF00U)
#define GICP_GICP_EVTYPER3_RESERVED0_SHIFT       (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_EVTYPER3_RESERVED0(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER3_RESERVED0_SHIFT)) & GICP_GICP_EVTYPER3_RESERVED0_MASK)

#define GICP_GICP_EVTYPER3_EVENT_TYPE_MASK       (0x30000U)
#define GICP_GICP_EVTYPER3_EVENT_TYPE_SHIFT      (16U)
/*! EVENT_TYPE - EVENT_TYPE */
#define GICP_GICP_EVTYPER3_EVENT_TYPE(x)         (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER3_EVENT_TYPE_SHIFT)) & GICP_GICP_EVTYPER3_EVENT_TYPE_MASK)

#define GICP_GICP_EVTYPER3_RESERVED1_MASK        (0x7FFC0000U)
#define GICP_GICP_EVTYPER3_RESERVED1_SHIFT       (18U)
/*! RESERVED1 - RESERVED1 */
#define GICP_GICP_EVTYPER3_RESERVED1(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER3_RESERVED1_SHIFT)) & GICP_GICP_EVTYPER3_RESERVED1_MASK)

#define GICP_GICP_EVTYPER3_OVCAP_MASK            (0x80000000U)
#define GICP_GICP_EVTYPER3_OVCAP_SHIFT           (31U)
/*! OVCAP - OVCAP */
#define GICP_GICP_EVTYPER3_OVCAP(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER3_OVCAP_SHIFT)) & GICP_GICP_EVTYPER3_OVCAP_MASK)
/*! @} */

/*! @name GICP_EVTYPER4 - GICP_EVTYPER4 */
/*! @{ */

#define GICP_GICP_EVTYPER4_EVENT_MASK            (0xFFU)
#define GICP_GICP_EVTYPER4_EVENT_SHIFT           (0U)
/*! EVENT - EVENT */
#define GICP_GICP_EVTYPER4_EVENT(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER4_EVENT_SHIFT)) & GICP_GICP_EVTYPER4_EVENT_MASK)

#define GICP_GICP_EVTYPER4_RESERVED0_MASK        (0xFF00U)
#define GICP_GICP_EVTYPER4_RESERVED0_SHIFT       (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_EVTYPER4_RESERVED0(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER4_RESERVED0_SHIFT)) & GICP_GICP_EVTYPER4_RESERVED0_MASK)

#define GICP_GICP_EVTYPER4_EVENT_TYPE_MASK       (0x30000U)
#define GICP_GICP_EVTYPER4_EVENT_TYPE_SHIFT      (16U)
/*! EVENT_TYPE - EVENT_TYPE */
#define GICP_GICP_EVTYPER4_EVENT_TYPE(x)         (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER4_EVENT_TYPE_SHIFT)) & GICP_GICP_EVTYPER4_EVENT_TYPE_MASK)

#define GICP_GICP_EVTYPER4_RESERVED1_MASK        (0x7FFC0000U)
#define GICP_GICP_EVTYPER4_RESERVED1_SHIFT       (18U)
/*! RESERVED1 - RESERVED1 */
#define GICP_GICP_EVTYPER4_RESERVED1(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER4_RESERVED1_SHIFT)) & GICP_GICP_EVTYPER4_RESERVED1_MASK)

#define GICP_GICP_EVTYPER4_OVCAP_MASK            (0x80000000U)
#define GICP_GICP_EVTYPER4_OVCAP_SHIFT           (31U)
/*! OVCAP - OVCAP */
#define GICP_GICP_EVTYPER4_OVCAP(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_EVTYPER4_OVCAP_SHIFT)) & GICP_GICP_EVTYPER4_OVCAP_MASK)
/*! @} */

/*! @name GICP_SVR0 - GICP_SVR0 */
/*! @{ */

#define GICP_GICP_SVR0_COUNT_MASK                (0xFFFFFFFFU)
#define GICP_GICP_SVR0_COUNT_SHIFT               (0U)
/*! COUNT - COUNT */
#define GICP_GICP_SVR0_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << GICP_GICP_SVR0_COUNT_SHIFT)) & GICP_GICP_SVR0_COUNT_MASK)
/*! @} */

/*! @name GICP_SVR1 - GICP_SVR1 */
/*! @{ */

#define GICP_GICP_SVR1_COUNT_MASK                (0xFFFFFFFFU)
#define GICP_GICP_SVR1_COUNT_SHIFT               (0U)
/*! COUNT - COUNT */
#define GICP_GICP_SVR1_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << GICP_GICP_SVR1_COUNT_SHIFT)) & GICP_GICP_SVR1_COUNT_MASK)
/*! @} */

/*! @name GICP_SVR2 - GICP_SVR2 */
/*! @{ */

#define GICP_GICP_SVR2_COUNT_MASK                (0xFFFFFFFFU)
#define GICP_GICP_SVR2_COUNT_SHIFT               (0U)
/*! COUNT - COUNT */
#define GICP_GICP_SVR2_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << GICP_GICP_SVR2_COUNT_SHIFT)) & GICP_GICP_SVR2_COUNT_MASK)
/*! @} */

/*! @name GICP_SVR3 - GICP_SVR3 */
/*! @{ */

#define GICP_GICP_SVR3_COUNT_MASK                (0xFFFFFFFFU)
#define GICP_GICP_SVR3_COUNT_SHIFT               (0U)
/*! COUNT - COUNT */
#define GICP_GICP_SVR3_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << GICP_GICP_SVR3_COUNT_SHIFT)) & GICP_GICP_SVR3_COUNT_MASK)
/*! @} */

/*! @name GICP_SVR4 - GICP_SVR4 */
/*! @{ */

#define GICP_GICP_SVR4_COUNT_MASK                (0xFFFFFFFFU)
#define GICP_GICP_SVR4_COUNT_SHIFT               (0U)
/*! COUNT - COUNT */
#define GICP_GICP_SVR4_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << GICP_GICP_SVR4_COUNT_SHIFT)) & GICP_GICP_SVR4_COUNT_MASK)
/*! @} */

/*! @name GICP_FR0 - GICP_FR0 */
/*! @{ */

#define GICP_GICP_FR0_Filter_MASK                (0xFFFFU)
#define GICP_GICP_FR0_Filter_SHIFT               (0U)
/*! Filter - Filter */
#define GICP_GICP_FR0_Filter(x)                  (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR0_Filter_SHIFT)) & GICP_GICP_FR0_Filter_MASK)

#define GICP_GICP_FR0_RESERVED0_MASK             (0x1FFF0000U)
#define GICP_GICP_FR0_RESERVED0_SHIFT            (16U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_FR0_RESERVED0(x)               (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR0_RESERVED0_SHIFT)) & GICP_GICP_FR0_RESERVED0_MASK)

#define GICP_GICP_FR0_FilterEncoding_MASK        (0x20000000U)
#define GICP_GICP_FR0_FilterEncoding_SHIFT       (29U)
/*! FilterEncoding - FilterEncoding */
#define GICP_GICP_FR0_FilterEncoding(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR0_FilterEncoding_SHIFT)) & GICP_GICP_FR0_FilterEncoding_MASK)

#define GICP_GICP_FR0_FilterType_MASK            (0xC0000000U)
#define GICP_GICP_FR0_FilterType_SHIFT           (30U)
/*! FilterType - FilterType */
#define GICP_GICP_FR0_FilterType(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR0_FilterType_SHIFT)) & GICP_GICP_FR0_FilterType_MASK)
/*! @} */

/*! @name GICP_FR1 - GICP_FR1 */
/*! @{ */

#define GICP_GICP_FR1_Filter_MASK                (0xFFFFU)
#define GICP_GICP_FR1_Filter_SHIFT               (0U)
/*! Filter - Filter */
#define GICP_GICP_FR1_Filter(x)                  (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR1_Filter_SHIFT)) & GICP_GICP_FR1_Filter_MASK)

#define GICP_GICP_FR1_RESERVED0_MASK             (0x1FFF0000U)
#define GICP_GICP_FR1_RESERVED0_SHIFT            (16U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_FR1_RESERVED0(x)               (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR1_RESERVED0_SHIFT)) & GICP_GICP_FR1_RESERVED0_MASK)

#define GICP_GICP_FR1_FilterEncoding_MASK        (0x20000000U)
#define GICP_GICP_FR1_FilterEncoding_SHIFT       (29U)
/*! FilterEncoding - FilterEncoding */
#define GICP_GICP_FR1_FilterEncoding(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR1_FilterEncoding_SHIFT)) & GICP_GICP_FR1_FilterEncoding_MASK)

#define GICP_GICP_FR1_FilterType_MASK            (0xC0000000U)
#define GICP_GICP_FR1_FilterType_SHIFT           (30U)
/*! FilterType - FilterType */
#define GICP_GICP_FR1_FilterType(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR1_FilterType_SHIFT)) & GICP_GICP_FR1_FilterType_MASK)
/*! @} */

/*! @name GICP_FR2 - GICP_FR2 */
/*! @{ */

#define GICP_GICP_FR2_Filter_MASK                (0xFFFFU)
#define GICP_GICP_FR2_Filter_SHIFT               (0U)
/*! Filter - Filter */
#define GICP_GICP_FR2_Filter(x)                  (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR2_Filter_SHIFT)) & GICP_GICP_FR2_Filter_MASK)

#define GICP_GICP_FR2_RESERVED0_MASK             (0x1FFF0000U)
#define GICP_GICP_FR2_RESERVED0_SHIFT            (16U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_FR2_RESERVED0(x)               (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR2_RESERVED0_SHIFT)) & GICP_GICP_FR2_RESERVED0_MASK)

#define GICP_GICP_FR2_FilterEncoding_MASK        (0x20000000U)
#define GICP_GICP_FR2_FilterEncoding_SHIFT       (29U)
/*! FilterEncoding - FilterEncoding */
#define GICP_GICP_FR2_FilterEncoding(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR2_FilterEncoding_SHIFT)) & GICP_GICP_FR2_FilterEncoding_MASK)

#define GICP_GICP_FR2_FilterType_MASK            (0xC0000000U)
#define GICP_GICP_FR2_FilterType_SHIFT           (30U)
/*! FilterType - FilterType */
#define GICP_GICP_FR2_FilterType(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR2_FilterType_SHIFT)) & GICP_GICP_FR2_FilterType_MASK)
/*! @} */

/*! @name GICP_FR3 - GICP_FR3 */
/*! @{ */

#define GICP_GICP_FR3_Filter_MASK                (0xFFFFU)
#define GICP_GICP_FR3_Filter_SHIFT               (0U)
/*! Filter - Filter */
#define GICP_GICP_FR3_Filter(x)                  (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR3_Filter_SHIFT)) & GICP_GICP_FR3_Filter_MASK)

#define GICP_GICP_FR3_RESERVED0_MASK             (0x1FFF0000U)
#define GICP_GICP_FR3_RESERVED0_SHIFT            (16U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_FR3_RESERVED0(x)               (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR3_RESERVED0_SHIFT)) & GICP_GICP_FR3_RESERVED0_MASK)

#define GICP_GICP_FR3_FilterEncoding_MASK        (0x20000000U)
#define GICP_GICP_FR3_FilterEncoding_SHIFT       (29U)
/*! FilterEncoding - FilterEncoding */
#define GICP_GICP_FR3_FilterEncoding(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR3_FilterEncoding_SHIFT)) & GICP_GICP_FR3_FilterEncoding_MASK)

#define GICP_GICP_FR3_FilterType_MASK            (0xC0000000U)
#define GICP_GICP_FR3_FilterType_SHIFT           (30U)
/*! FilterType - FilterType */
#define GICP_GICP_FR3_FilterType(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR3_FilterType_SHIFT)) & GICP_GICP_FR3_FilterType_MASK)
/*! @} */

/*! @name GICP_FR4 - GICP_FR4 */
/*! @{ */

#define GICP_GICP_FR4_Filter_MASK                (0xFFFFU)
#define GICP_GICP_FR4_Filter_SHIFT               (0U)
/*! Filter - Filter */
#define GICP_GICP_FR4_Filter(x)                  (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR4_Filter_SHIFT)) & GICP_GICP_FR4_Filter_MASK)

#define GICP_GICP_FR4_RESERVED0_MASK             (0x1FFF0000U)
#define GICP_GICP_FR4_RESERVED0_SHIFT            (16U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_FR4_RESERVED0(x)               (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR4_RESERVED0_SHIFT)) & GICP_GICP_FR4_RESERVED0_MASK)

#define GICP_GICP_FR4_FilterEncoding_MASK        (0x20000000U)
#define GICP_GICP_FR4_FilterEncoding_SHIFT       (29U)
/*! FilterEncoding - FilterEncoding */
#define GICP_GICP_FR4_FilterEncoding(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR4_FilterEncoding_SHIFT)) & GICP_GICP_FR4_FilterEncoding_MASK)

#define GICP_GICP_FR4_FilterType_MASK            (0xC0000000U)
#define GICP_GICP_FR4_FilterType_SHIFT           (30U)
/*! FilterType - FilterType */
#define GICP_GICP_FR4_FilterType(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_FR4_FilterType_SHIFT)) & GICP_GICP_FR4_FilterType_MASK)
/*! @} */

/*! @name GICP_CNTENSET0 - GICP_CNTENSET0 */
/*! @{ */

#define GICP_GICP_CNTENSET0_CNTEN0_MASK          (0x1U)
#define GICP_GICP_CNTENSET0_CNTEN0_SHIFT         (0U)
/*! CNTEN0 - CNTEN0 */
#define GICP_GICP_CNTENSET0_CNTEN0(x)            (((uint64_t)(((uint64_t)(x)) << GICP_GICP_CNTENSET0_CNTEN0_SHIFT)) & GICP_GICP_CNTENSET0_CNTEN0_MASK)

#define GICP_GICP_CNTENSET0_CNTEN1_MASK          (0x2U)
#define GICP_GICP_CNTENSET0_CNTEN1_SHIFT         (1U)
/*! CNTEN1 - CNTEN1 */
#define GICP_GICP_CNTENSET0_CNTEN1(x)            (((uint64_t)(((uint64_t)(x)) << GICP_GICP_CNTENSET0_CNTEN1_SHIFT)) & GICP_GICP_CNTENSET0_CNTEN1_MASK)

#define GICP_GICP_CNTENSET0_CNTEN2_MASK          (0x4U)
#define GICP_GICP_CNTENSET0_CNTEN2_SHIFT         (2U)
/*! CNTEN2 - CNTEN2 */
#define GICP_GICP_CNTENSET0_CNTEN2(x)            (((uint64_t)(((uint64_t)(x)) << GICP_GICP_CNTENSET0_CNTEN2_SHIFT)) & GICP_GICP_CNTENSET0_CNTEN2_MASK)

#define GICP_GICP_CNTENSET0_CNTEN3_MASK          (0x8U)
#define GICP_GICP_CNTENSET0_CNTEN3_SHIFT         (3U)
/*! CNTEN3 - CNTEN3 */
#define GICP_GICP_CNTENSET0_CNTEN3(x)            (((uint64_t)(((uint64_t)(x)) << GICP_GICP_CNTENSET0_CNTEN3_SHIFT)) & GICP_GICP_CNTENSET0_CNTEN3_MASK)

#define GICP_GICP_CNTENSET0_CNTEN4_MASK          (0x10U)
#define GICP_GICP_CNTENSET0_CNTEN4_SHIFT         (4U)
/*! CNTEN4 - CNTEN4 */
#define GICP_GICP_CNTENSET0_CNTEN4(x)            (((uint64_t)(((uint64_t)(x)) << GICP_GICP_CNTENSET0_CNTEN4_SHIFT)) & GICP_GICP_CNTENSET0_CNTEN4_MASK)

#define GICP_GICP_CNTENSET0_RESERVED0_MASK       (0xFFFFFFFFFFFFFFE0U)
#define GICP_GICP_CNTENSET0_RESERVED0_SHIFT      (5U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_CNTENSET0_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICP_GICP_CNTENSET0_RESERVED0_SHIFT)) & GICP_GICP_CNTENSET0_RESERVED0_MASK)
/*! @} */

/*! @name GICP_CNTENCLR0 - GICP_CNTENCLR0 */
/*! @{ */

#define GICP_GICP_CNTENCLR0_CNTEN0_MASK          (0x1U)
#define GICP_GICP_CNTENCLR0_CNTEN0_SHIFT         (0U)
/*! CNTEN0 - CNTEN0 */
#define GICP_GICP_CNTENCLR0_CNTEN0(x)            (((uint64_t)(((uint64_t)(x)) << GICP_GICP_CNTENCLR0_CNTEN0_SHIFT)) & GICP_GICP_CNTENCLR0_CNTEN0_MASK)

#define GICP_GICP_CNTENCLR0_CNTEN1_MASK          (0x2U)
#define GICP_GICP_CNTENCLR0_CNTEN1_SHIFT         (1U)
/*! CNTEN1 - CNTEN1 */
#define GICP_GICP_CNTENCLR0_CNTEN1(x)            (((uint64_t)(((uint64_t)(x)) << GICP_GICP_CNTENCLR0_CNTEN1_SHIFT)) & GICP_GICP_CNTENCLR0_CNTEN1_MASK)

#define GICP_GICP_CNTENCLR0_CNTEN2_MASK          (0x4U)
#define GICP_GICP_CNTENCLR0_CNTEN2_SHIFT         (2U)
/*! CNTEN2 - CNTEN2 */
#define GICP_GICP_CNTENCLR0_CNTEN2(x)            (((uint64_t)(((uint64_t)(x)) << GICP_GICP_CNTENCLR0_CNTEN2_SHIFT)) & GICP_GICP_CNTENCLR0_CNTEN2_MASK)

#define GICP_GICP_CNTENCLR0_CNTEN3_MASK          (0x8U)
#define GICP_GICP_CNTENCLR0_CNTEN3_SHIFT         (3U)
/*! CNTEN3 - CNTEN3 */
#define GICP_GICP_CNTENCLR0_CNTEN3(x)            (((uint64_t)(((uint64_t)(x)) << GICP_GICP_CNTENCLR0_CNTEN3_SHIFT)) & GICP_GICP_CNTENCLR0_CNTEN3_MASK)

#define GICP_GICP_CNTENCLR0_CNTEN4_MASK          (0x10U)
#define GICP_GICP_CNTENCLR0_CNTEN4_SHIFT         (4U)
/*! CNTEN4 - CNTEN4 */
#define GICP_GICP_CNTENCLR0_CNTEN4(x)            (((uint64_t)(((uint64_t)(x)) << GICP_GICP_CNTENCLR0_CNTEN4_SHIFT)) & GICP_GICP_CNTENCLR0_CNTEN4_MASK)

#define GICP_GICP_CNTENCLR0_RESERVED0_MASK       (0xFFFFFFFFFFFFFFE0U)
#define GICP_GICP_CNTENCLR0_RESERVED0_SHIFT      (5U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_CNTENCLR0_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICP_GICP_CNTENCLR0_RESERVED0_SHIFT)) & GICP_GICP_CNTENCLR0_RESERVED0_MASK)
/*! @} */

/*! @name GICP_INTENSET0 - GICP_INTENSET0 */
/*! @{ */

#define GICP_GICP_INTENSET0_INTEN_MASK           (0x1FU)
#define GICP_GICP_INTENSET0_INTEN_SHIFT          (0U)
/*! INTEN - INTEN */
#define GICP_GICP_INTENSET0_INTEN(x)             (((uint64_t)(((uint64_t)(x)) << GICP_GICP_INTENSET0_INTEN_SHIFT)) & GICP_GICP_INTENSET0_INTEN_MASK)

#define GICP_GICP_INTENSET0_RESERVED0_MASK       (0xFFFFFFFFFFFFFFE0U)
#define GICP_GICP_INTENSET0_RESERVED0_SHIFT      (5U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_INTENSET0_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICP_GICP_INTENSET0_RESERVED0_SHIFT)) & GICP_GICP_INTENSET0_RESERVED0_MASK)
/*! @} */

/*! @name GICP_INTENCLR0 - GICP_INTENCLR0 */
/*! @{ */

#define GICP_GICP_INTENCLR0_INTEN_MASK           (0x1FU)
#define GICP_GICP_INTENCLR0_INTEN_SHIFT          (0U)
/*! INTEN - INTEN */
#define GICP_GICP_INTENCLR0_INTEN(x)             (((uint64_t)(((uint64_t)(x)) << GICP_GICP_INTENCLR0_INTEN_SHIFT)) & GICP_GICP_INTENCLR0_INTEN_MASK)

#define GICP_GICP_INTENCLR0_RESERVED0_MASK       (0xFFFFFFFFFFFFFFE0U)
#define GICP_GICP_INTENCLR0_RESERVED0_SHIFT      (5U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_INTENCLR0_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICP_GICP_INTENCLR0_RESERVED0_SHIFT)) & GICP_GICP_INTENCLR0_RESERVED0_MASK)
/*! @} */

/*! @name GICP_OVSCLR0 - GICP_OVSCLR0 */
/*! @{ */

#define GICP_GICP_OVSCLR0_OVS_MASK               (0x1FU)
#define GICP_GICP_OVSCLR0_OVS_SHIFT              (0U)
/*! OVS - OVS */
#define GICP_GICP_OVSCLR0_OVS(x)                 (((uint64_t)(((uint64_t)(x)) << GICP_GICP_OVSCLR0_OVS_SHIFT)) & GICP_GICP_OVSCLR0_OVS_MASK)

#define GICP_GICP_OVSCLR0_RESERVED0_MASK         (0xFFFFFFFFFFFFFFE0U)
#define GICP_GICP_OVSCLR0_RESERVED0_SHIFT        (5U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_OVSCLR0_RESERVED0(x)           (((uint64_t)(((uint64_t)(x)) << GICP_GICP_OVSCLR0_RESERVED0_SHIFT)) & GICP_GICP_OVSCLR0_RESERVED0_MASK)
/*! @} */

/*! @name GICP_OVSSET0 - GICP_OVSSET0 */
/*! @{ */

#define GICP_GICP_OVSSET0_OVS_MASK               (0x1FU)
#define GICP_GICP_OVSSET0_OVS_SHIFT              (0U)
/*! OVS - OVS */
#define GICP_GICP_OVSSET0_OVS(x)                 (((uint64_t)(((uint64_t)(x)) << GICP_GICP_OVSSET0_OVS_SHIFT)) & GICP_GICP_OVSSET0_OVS_MASK)

#define GICP_GICP_OVSSET0_RESERVED0_MASK         (0xFFFFFFFFFFFFFFE0U)
#define GICP_GICP_OVSSET0_RESERVED0_SHIFT        (5U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_OVSSET0_RESERVED0(x)           (((uint64_t)(((uint64_t)(x)) << GICP_GICP_OVSSET0_RESERVED0_SHIFT)) & GICP_GICP_OVSSET0_RESERVED0_MASK)
/*! @} */

/*! @name GICP_CAPR - GICP_CAPR */
/*! @{ */

#define GICP_GICP_CAPR_CAPTURE_MASK              (0x1U)
#define GICP_GICP_CAPR_CAPTURE_SHIFT             (0U)
/*! CAPTURE - CAPTURE */
#define GICP_GICP_CAPR_CAPTURE(x)                (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CAPR_CAPTURE_SHIFT)) & GICP_GICP_CAPR_CAPTURE_MASK)

#define GICP_GICP_CAPR_RESERVED0_MASK            (0xFFFFFFFEU)
#define GICP_GICP_CAPR_RESERVED0_SHIFT           (1U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_CAPR_RESERVED0(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CAPR_RESERVED0_SHIFT)) & GICP_GICP_CAPR_RESERVED0_MASK)
/*! @} */

/*! @name GICP_CFGR - GICP_CFGR */
/*! @{ */

#define GICP_GICP_CFGR_NCTR_MASK                 (0x3FU)
#define GICP_GICP_CFGR_NCTR_SHIFT                (0U)
/*! NCTR - NCTR */
#define GICP_GICP_CFGR_NCTR(x)                   (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CFGR_NCTR_SHIFT)) & GICP_GICP_CFGR_NCTR_MASK)

#define GICP_GICP_CFGR_RESERVED0_MASK            (0xC0U)
#define GICP_GICP_CFGR_RESERVED0_SHIFT           (6U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_CFGR_RESERVED0(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CFGR_RESERVED0_SHIFT)) & GICP_GICP_CFGR_RESERVED0_MASK)

#define GICP_GICP_CFGR_SIZE_MASK                 (0x3F00U)
#define GICP_GICP_CFGR_SIZE_SHIFT                (8U)
/*! SIZE - SIZE */
#define GICP_GICP_CFGR_SIZE(x)                   (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CFGR_SIZE_SHIFT)) & GICP_GICP_CFGR_SIZE_MASK)

#define GICP_GICP_CFGR_RESERVED1_MASK            (0x3FC000U)
#define GICP_GICP_CFGR_RESERVED1_SHIFT           (14U)
/*! RESERVED1 - RESERVED1 */
#define GICP_GICP_CFGR_RESERVED1(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CFGR_RESERVED1_SHIFT)) & GICP_GICP_CFGR_RESERVED1_MASK)

#define GICP_GICP_CFGR_CAPTURE_MASK              (0x400000U)
#define GICP_GICP_CFGR_CAPTURE_SHIFT             (22U)
/*! CAPTURE - CAPTURE */
#define GICP_GICP_CFGR_CAPTURE(x)                (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CFGR_CAPTURE_SHIFT)) & GICP_GICP_CFGR_CAPTURE_MASK)

#define GICP_GICP_CFGR_RESERVED2_MASK            (0xFF800000U)
#define GICP_GICP_CFGR_RESERVED2_SHIFT           (23U)
/*! RESERVED2 - RESERVED2 */
#define GICP_GICP_CFGR_RESERVED2(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CFGR_RESERVED2_SHIFT)) & GICP_GICP_CFGR_RESERVED2_MASK)
/*! @} */

/*! @name GICP_CR - GICP_CR */
/*! @{ */

#define GICP_GICP_CR_E_MASK                      (0x1U)
#define GICP_GICP_CR_E_SHIFT                     (0U)
/*! E - E */
#define GICP_GICP_CR_E(x)                        (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CR_E_SHIFT)) & GICP_GICP_CR_E_MASK)

#define GICP_GICP_CR_RESERVED0_MASK              (0xFFFFFFFEU)
#define GICP_GICP_CR_RESERVED0_SHIFT             (1U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_CR_RESERVED0(x)                (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CR_RESERVED0_SHIFT)) & GICP_GICP_CR_RESERVED0_MASK)
/*! @} */

/*! @name GICP_IRQCR - GICP_IRQCR */
/*! @{ */

#define GICP_GICP_IRQCR_SPIID_MASK               (0x3FFU)
#define GICP_GICP_IRQCR_SPIID_SHIFT              (0U)
/*! SPIID - SPIID */
#define GICP_GICP_IRQCR_SPIID(x)                 (((uint32_t)(((uint32_t)(x)) << GICP_GICP_IRQCR_SPIID_SHIFT)) & GICP_GICP_IRQCR_SPIID_MASK)

#define GICP_GICP_IRQCR_RESERVED0_MASK           (0xFFFFFC00U)
#define GICP_GICP_IRQCR_RESERVED0_SHIFT          (10U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_IRQCR_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_IRQCR_RESERVED0_SHIFT)) & GICP_GICP_IRQCR_RESERVED0_MASK)
/*! @} */

/*! @name GICP_PMAUTHSTATUS - GICP_PMAUTHSTATUS */
/*! @{ */

#define GICP_GICP_PMAUTHSTATUS_NSE_MASK          (0x1U)
#define GICP_GICP_PMAUTHSTATUS_NSE_SHIFT         (0U)
/*! NSE - NSE */
#define GICP_GICP_PMAUTHSTATUS_NSE(x)            (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMAUTHSTATUS_NSE_SHIFT)) & GICP_GICP_PMAUTHSTATUS_NSE_MASK)

#define GICP_GICP_PMAUTHSTATUS_NSI_MASK          (0x2U)
#define GICP_GICP_PMAUTHSTATUS_NSI_SHIFT         (1U)
/*! NSI - NSI */
#define GICP_GICP_PMAUTHSTATUS_NSI(x)            (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMAUTHSTATUS_NSI_SHIFT)) & GICP_GICP_PMAUTHSTATUS_NSI_MASK)

#define GICP_GICP_PMAUTHSTATUS_NSNE_MASK         (0x4U)
#define GICP_GICP_PMAUTHSTATUS_NSNE_SHIFT        (2U)
/*! NSNE - NSNE */
#define GICP_GICP_PMAUTHSTATUS_NSNE(x)           (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMAUTHSTATUS_NSNE_SHIFT)) & GICP_GICP_PMAUTHSTATUS_NSNE_MASK)

#define GICP_GICP_PMAUTHSTATUS_NSNI_MASK         (0x8U)
#define GICP_GICP_PMAUTHSTATUS_NSNI_SHIFT        (3U)
/*! NSNI - NSNI */
#define GICP_GICP_PMAUTHSTATUS_NSNI(x)           (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMAUTHSTATUS_NSNI_SHIFT)) & GICP_GICP_PMAUTHSTATUS_NSNI_MASK)

#define GICP_GICP_PMAUTHSTATUS_SE_MASK           (0x10U)
#define GICP_GICP_PMAUTHSTATUS_SE_SHIFT          (4U)
/*! SE - SE */
#define GICP_GICP_PMAUTHSTATUS_SE(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMAUTHSTATUS_SE_SHIFT)) & GICP_GICP_PMAUTHSTATUS_SE_MASK)

#define GICP_GICP_PMAUTHSTATUS_SI_MASK           (0x20U)
#define GICP_GICP_PMAUTHSTATUS_SI_SHIFT          (5U)
/*! SI - SI */
#define GICP_GICP_PMAUTHSTATUS_SI(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMAUTHSTATUS_SI_SHIFT)) & GICP_GICP_PMAUTHSTATUS_SI_MASK)

#define GICP_GICP_PMAUTHSTATUS_SNE_MASK          (0x40U)
#define GICP_GICP_PMAUTHSTATUS_SNE_SHIFT         (6U)
/*! SNE - SNE */
#define GICP_GICP_PMAUTHSTATUS_SNE(x)            (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMAUTHSTATUS_SNE_SHIFT)) & GICP_GICP_PMAUTHSTATUS_SNE_MASK)

#define GICP_GICP_PMAUTHSTATUS_SNI_MASK          (0x80U)
#define GICP_GICP_PMAUTHSTATUS_SNI_SHIFT         (7U)
/*! SNI - SNI */
#define GICP_GICP_PMAUTHSTATUS_SNI(x)            (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMAUTHSTATUS_SNI_SHIFT)) & GICP_GICP_PMAUTHSTATUS_SNI_MASK)

#define GICP_GICP_PMAUTHSTATUS_RESERVED0_MASK    (0xFFFFFF00U)
#define GICP_GICP_PMAUTHSTATUS_RESERVED0_SHIFT   (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_PMAUTHSTATUS_RESERVED0(x)      (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMAUTHSTATUS_RESERVED0_SHIFT)) & GICP_GICP_PMAUTHSTATUS_RESERVED0_MASK)
/*! @} */

/*! @name GICP_PMDEVARCH - GICP_PMDEVARCH */
/*! @{ */

#define GICP_GICP_PMDEVARCH_ARCHID_MASK          (0xFFFFU)
#define GICP_GICP_PMDEVARCH_ARCHID_SHIFT         (0U)
/*! ARCHID - ARCHID */
#define GICP_GICP_PMDEVARCH_ARCHID(x)            (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMDEVARCH_ARCHID_SHIFT)) & GICP_GICP_PMDEVARCH_ARCHID_MASK)

#define GICP_GICP_PMDEVARCH_REVISION_MASK        (0xF0000U)
#define GICP_GICP_PMDEVARCH_REVISION_SHIFT       (16U)
/*! REVISION - REVISION */
#define GICP_GICP_PMDEVARCH_REVISION(x)          (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMDEVARCH_REVISION_SHIFT)) & GICP_GICP_PMDEVARCH_REVISION_MASK)

#define GICP_GICP_PMDEVARCH_PRESENT_MASK         (0x100000U)
#define GICP_GICP_PMDEVARCH_PRESENT_SHIFT        (20U)
/*! PRESENT - PRESENT */
#define GICP_GICP_PMDEVARCH_PRESENT(x)           (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMDEVARCH_PRESENT_SHIFT)) & GICP_GICP_PMDEVARCH_PRESENT_MASK)

#define GICP_GICP_PMDEVARCH_ARCHITECT_MASK       (0xFFE00000U)
#define GICP_GICP_PMDEVARCH_ARCHITECT_SHIFT      (21U)
/*! ARCHITECT - ARCHITECT */
#define GICP_GICP_PMDEVARCH_ARCHITECT(x)         (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMDEVARCH_ARCHITECT_SHIFT)) & GICP_GICP_PMDEVARCH_ARCHITECT_MASK)
/*! @} */

/*! @name GICP_PMDEVTYPE - GICP_PMDEVTYPE */
/*! @{ */

#define GICP_GICP_PMDEVTYPE_Class_MASK           (0xFU)
#define GICP_GICP_PMDEVTYPE_Class_SHIFT          (0U)
/*! Class - Class */
#define GICP_GICP_PMDEVTYPE_Class(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMDEVTYPE_Class_SHIFT)) & GICP_GICP_PMDEVTYPE_Class_MASK)

#define GICP_GICP_PMDEVTYPE_SubType_MASK         (0xF0U)
#define GICP_GICP_PMDEVTYPE_SubType_SHIFT        (4U)
/*! SubType - SubType */
#define GICP_GICP_PMDEVTYPE_SubType(x)           (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMDEVTYPE_SubType_SHIFT)) & GICP_GICP_PMDEVTYPE_SubType_MASK)

#define GICP_GICP_PMDEVTYPE_RESERVED0_MASK       (0xFFFFFF00U)
#define GICP_GICP_PMDEVTYPE_RESERVED0_SHIFT      (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_PMDEVTYPE_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PMDEVTYPE_RESERVED0_SHIFT)) & GICP_GICP_PMDEVTYPE_RESERVED0_MASK)
/*! @} */

/*! @name GICP_PIDR4 - GICP_PIDR4 */
/*! @{ */

#define GICP_GICP_PIDR4_DES_2_MASK               (0xFU)
#define GICP_GICP_PIDR4_DES_2_SHIFT              (0U)
/*! DES_2 - DES_2 */
#define GICP_GICP_PIDR4_DES_2(x)                 (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR4_DES_2_SHIFT)) & GICP_GICP_PIDR4_DES_2_MASK)

#define GICP_GICP_PIDR4_SIZE_MASK                (0xF0U)
#define GICP_GICP_PIDR4_SIZE_SHIFT               (4U)
/*! SIZE - SIZE */
#define GICP_GICP_PIDR4_SIZE(x)                  (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR4_SIZE_SHIFT)) & GICP_GICP_PIDR4_SIZE_MASK)

#define GICP_GICP_PIDR4_RESERVED0_MASK           (0xFFFFFF00U)
#define GICP_GICP_PIDR4_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_PIDR4_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR4_RESERVED0_SHIFT)) & GICP_GICP_PIDR4_RESERVED0_MASK)
/*! @} */

/*! @name GICP_PIDR5 - GICP_PIDR5 */
/*! @{ */

#define GICP_GICP_PIDR5_RESERVED_MASK            (0xFFU)
#define GICP_GICP_PIDR5_RESERVED_SHIFT           (0U)
/*! RESERVED - RESERVED */
#define GICP_GICP_PIDR5_RESERVED(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR5_RESERVED_SHIFT)) & GICP_GICP_PIDR5_RESERVED_MASK)

#define GICP_GICP_PIDR5_RESERVED0_MASK           (0xFFFFFF00U)
#define GICP_GICP_PIDR5_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_PIDR5_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR5_RESERVED0_SHIFT)) & GICP_GICP_PIDR5_RESERVED0_MASK)
/*! @} */

/*! @name GICP_PIDR6 - GICP_PIDR6 */
/*! @{ */

#define GICP_GICP_PIDR6_RESERVED_MASK            (0xFFU)
#define GICP_GICP_PIDR6_RESERVED_SHIFT           (0U)
/*! RESERVED - RESERVED */
#define GICP_GICP_PIDR6_RESERVED(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR6_RESERVED_SHIFT)) & GICP_GICP_PIDR6_RESERVED_MASK)

#define GICP_GICP_PIDR6_RESERVED0_MASK           (0xFFFFFF00U)
#define GICP_GICP_PIDR6_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_PIDR6_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR6_RESERVED0_SHIFT)) & GICP_GICP_PIDR6_RESERVED0_MASK)
/*! @} */

/*! @name GICP_PIDR7 - GICP_PIDR7 */
/*! @{ */

#define GICP_GICP_PIDR7_RESERVED_MASK            (0xFFU)
#define GICP_GICP_PIDR7_RESERVED_SHIFT           (0U)
/*! RESERVED - RESERVED */
#define GICP_GICP_PIDR7_RESERVED(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR7_RESERVED_SHIFT)) & GICP_GICP_PIDR7_RESERVED_MASK)

#define GICP_GICP_PIDR7_RESERVED0_MASK           (0xFFFFFF00U)
#define GICP_GICP_PIDR7_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_PIDR7_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR7_RESERVED0_SHIFT)) & GICP_GICP_PIDR7_RESERVED0_MASK)
/*! @} */

/*! @name GICP_PIDR0 - GICP_PIDR0 */
/*! @{ */

#define GICP_GICP_PIDR0_PART_0_MASK              (0xFFU)
#define GICP_GICP_PIDR0_PART_0_SHIFT             (0U)
/*! PART_0 - PART_0 */
#define GICP_GICP_PIDR0_PART_0(x)                (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR0_PART_0_SHIFT)) & GICP_GICP_PIDR0_PART_0_MASK)

#define GICP_GICP_PIDR0_RESERVED0_MASK           (0xFFFFFF00U)
#define GICP_GICP_PIDR0_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_PIDR0_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR0_RESERVED0_SHIFT)) & GICP_GICP_PIDR0_RESERVED0_MASK)
/*! @} */

/*! @name GICP_PIDR1 - GICP_PIDR1 */
/*! @{ */

#define GICP_GICP_PIDR1_PART_1_MASK              (0xFU)
#define GICP_GICP_PIDR1_PART_1_SHIFT             (0U)
/*! PART_1 - PART_1 */
#define GICP_GICP_PIDR1_PART_1(x)                (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR1_PART_1_SHIFT)) & GICP_GICP_PIDR1_PART_1_MASK)

#define GICP_GICP_PIDR1_DES_0_MASK               (0xF0U)
#define GICP_GICP_PIDR1_DES_0_SHIFT              (4U)
/*! DES_0 - DES_0 */
#define GICP_GICP_PIDR1_DES_0(x)                 (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR1_DES_0_SHIFT)) & GICP_GICP_PIDR1_DES_0_MASK)

#define GICP_GICP_PIDR1_RESERVED0_MASK           (0xFFFFFF00U)
#define GICP_GICP_PIDR1_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_PIDR1_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR1_RESERVED0_SHIFT)) & GICP_GICP_PIDR1_RESERVED0_MASK)
/*! @} */

/*! @name GICP_PIDR2 - GICP_PIDR2 */
/*! @{ */

#define GICP_GICP_PIDR2_DES_1_MASK               (0x7U)
#define GICP_GICP_PIDR2_DES_1_SHIFT              (0U)
/*! DES_1 - DES_1 */
#define GICP_GICP_PIDR2_DES_1(x)                 (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR2_DES_1_SHIFT)) & GICP_GICP_PIDR2_DES_1_MASK)

#define GICP_GICP_PIDR2_JEDEC_MASK               (0x8U)
#define GICP_GICP_PIDR2_JEDEC_SHIFT              (3U)
/*! JEDEC - JEDEC */
#define GICP_GICP_PIDR2_JEDEC(x)                 (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR2_JEDEC_SHIFT)) & GICP_GICP_PIDR2_JEDEC_MASK)

#define GICP_GICP_PIDR2_REVISION_MASK            (0xF0U)
#define GICP_GICP_PIDR2_REVISION_SHIFT           (4U)
/*! REVISION - REVISION */
#define GICP_GICP_PIDR2_REVISION(x)              (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR2_REVISION_SHIFT)) & GICP_GICP_PIDR2_REVISION_MASK)

#define GICP_GICP_PIDR2_RESERVED0_MASK           (0xFFFFFF00U)
#define GICP_GICP_PIDR2_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_PIDR2_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR2_RESERVED0_SHIFT)) & GICP_GICP_PIDR2_RESERVED0_MASK)
/*! @} */

/*! @name GICP_PIDR3 - GICP_PIDR3 */
/*! @{ */

#define GICP_GICP_PIDR3_CMOD_MASK                (0x7U)
#define GICP_GICP_PIDR3_CMOD_SHIFT               (0U)
/*! CMOD - CMOD */
#define GICP_GICP_PIDR3_CMOD(x)                  (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR3_CMOD_SHIFT)) & GICP_GICP_PIDR3_CMOD_MASK)

#define GICP_GICP_PIDR3_RESERVED1_MASK           (0x8U)
#define GICP_GICP_PIDR3_RESERVED1_SHIFT          (3U)
/*! RESERVED1 - RESERVED1 */
#define GICP_GICP_PIDR3_RESERVED1(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR3_RESERVED1_SHIFT)) & GICP_GICP_PIDR3_RESERVED1_MASK)

#define GICP_GICP_PIDR3_REVAND_MASK              (0xF0U)
#define GICP_GICP_PIDR3_REVAND_SHIFT             (4U)
/*! REVAND - REVAND */
#define GICP_GICP_PIDR3_REVAND(x)                (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR3_REVAND_SHIFT)) & GICP_GICP_PIDR3_REVAND_MASK)

#define GICP_GICP_PIDR3_RESERVED0_MASK           (0xFFFFFF00U)
#define GICP_GICP_PIDR3_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_PIDR3_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_PIDR3_RESERVED0_SHIFT)) & GICP_GICP_PIDR3_RESERVED0_MASK)
/*! @} */

/*! @name GICP_CIDR0 - GICP_CIDR0 */
/*! @{ */

#define GICP_GICP_CIDR0_PRMBL_0_MASK             (0xFFU)
#define GICP_GICP_CIDR0_PRMBL_0_SHIFT            (0U)
/*! PRMBL_0 - PRMBL_0 */
#define GICP_GICP_CIDR0_PRMBL_0(x)               (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CIDR0_PRMBL_0_SHIFT)) & GICP_GICP_CIDR0_PRMBL_0_MASK)

#define GICP_GICP_CIDR0_RESERVED0_MASK           (0xFFFFFF00U)
#define GICP_GICP_CIDR0_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_CIDR0_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CIDR0_RESERVED0_SHIFT)) & GICP_GICP_CIDR0_RESERVED0_MASK)
/*! @} */

/*! @name GICP_CIDR1 - GICP_CIDR1 */
/*! @{ */

#define GICP_GICP_CIDR1_PRMBL_1_MASK             (0xFU)
#define GICP_GICP_CIDR1_PRMBL_1_SHIFT            (0U)
/*! PRMBL_1 - PRMBL_1 */
#define GICP_GICP_CIDR1_PRMBL_1(x)               (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CIDR1_PRMBL_1_SHIFT)) & GICP_GICP_CIDR1_PRMBL_1_MASK)

#define GICP_GICP_CIDR1_CLASS_MASK               (0xF0U)
#define GICP_GICP_CIDR1_CLASS_SHIFT              (4U)
/*! CLASS - CLASS */
#define GICP_GICP_CIDR1_CLASS(x)                 (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CIDR1_CLASS_SHIFT)) & GICP_GICP_CIDR1_CLASS_MASK)

#define GICP_GICP_CIDR1_RESERVED0_MASK           (0xFFFFFF00U)
#define GICP_GICP_CIDR1_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_CIDR1_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CIDR1_RESERVED0_SHIFT)) & GICP_GICP_CIDR1_RESERVED0_MASK)
/*! @} */

/*! @name GICP_CIDR2 - GICP_CIDR2 */
/*! @{ */

#define GICP_GICP_CIDR2_PRMBL_2_MASK             (0xFFU)
#define GICP_GICP_CIDR2_PRMBL_2_SHIFT            (0U)
/*! PRMBL_2 - PRMBL_2 */
#define GICP_GICP_CIDR2_PRMBL_2(x)               (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CIDR2_PRMBL_2_SHIFT)) & GICP_GICP_CIDR2_PRMBL_2_MASK)

#define GICP_GICP_CIDR2_RESERVED0_MASK           (0xFFFFFF00U)
#define GICP_GICP_CIDR2_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_CIDR2_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CIDR2_RESERVED0_SHIFT)) & GICP_GICP_CIDR2_RESERVED0_MASK)
/*! @} */

/*! @name GICP_CIDR3 - GICP_CIDR3 */
/*! @{ */

#define GICP_GICP_CIDR3_PRMBL_3_MASK             (0xFFU)
#define GICP_GICP_CIDR3_PRMBL_3_SHIFT            (0U)
/*! PRMBL_3 - PRMBL_3 */
#define GICP_GICP_CIDR3_PRMBL_3(x)               (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CIDR3_PRMBL_3_SHIFT)) & GICP_GICP_CIDR3_PRMBL_3_MASK)

#define GICP_GICP_CIDR3_RESERVED0_MASK           (0xFFFFFF00U)
#define GICP_GICP_CIDR3_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICP_GICP_CIDR3_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICP_GICP_CIDR3_RESERVED0_SHIFT)) & GICP_GICP_CIDR3_RESERVED0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GICP_Register_Masks */


/*!
 * @}
 */ /* end of group GICP_Peripheral_Access_Layer */


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


#endif  /* PERI_GICP_H_ */
