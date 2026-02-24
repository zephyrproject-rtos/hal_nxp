/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for HSIO_ATU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_HSIO_ATU.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for HSIO_ATU
 *
 * CMSIS Peripheral Access Layer for HSIO_ATU
 */

#if !defined(PERI_HSIO_ATU_H_)
#define PERI_HSIO_ATU_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- HSIO_ATU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HSIO_ATU_Peripheral_Access_Layer HSIO_ATU Peripheral Access Layer
 * @{
 */

/** HSIO_ATU - Register Layout Typedef */
typedef struct {
  __IO uint32_t ATUCR;                             /**< ATU Control, offset: 0x0 */
  __IO uint32_t ATUSR;                             /**< ATU Status, offset: 0x4 */
  __I  uint32_t IP_REV_1;                          /**< IP Block Revision 1, offset: 0x8 */
  __I  uint32_t IP_REV_2;                          /**< IP Block Revision 2, offset: 0xC */
       uint8_t RESERVED_0[12];
  __IO uint32_t PMCR;                              /**< Performance Monitor, offset: 0x1C */
       uint8_t RESERVED_1[228];
  __I  uint32_t ACORE_OWAR0;                       /**< Outbound Window Attributes 0, offset: 0x104 */
  __IO uint32_t ACORE_OTEAR0;                      /**< Outbound Translated Extended Address 0, offset: 0x108 */
       uint8_t RESERVED_2[4];
  __IO uint32_t ACORE_OWBAR1;                      /**< Outbound Window Base Address 1, offset: 0x110 */
  __IO uint32_t ACORE_OWAR1;                       /**< Outbound Window Attributes 1, offset: 0x114 */
  __IO uint32_t ACORE_OTEAR1;                      /**< Outbound Translated Extended Address 1, offset: 0x118 */
  __IO uint32_t ACORE_OTAR1;                       /**< Outbound Translated Address 1, offset: 0x11C */
  __IO uint32_t ACORE_OWBAR2;                      /**< Outbound Window Base Address 2, offset: 0x120 */
  __IO uint32_t ACORE_OWAR2;                       /**< Outbound Window Attributes 2, offset: 0x124 */
  __IO uint32_t ACORE_OTEAR2;                      /**< Outbound Translated Extended Address 2, offset: 0x128 */
  __IO uint32_t ACORE_OTAR2;                       /**< Outbound Translated Address 2, offset: 0x12C */
  __IO uint32_t ACORE_OWBAR3;                      /**< Outbound Window Base Address 3, offset: 0x130 */
  __IO uint32_t ACORE_OWAR3;                       /**< Outbound Window Attributes 3, offset: 0x134 */
  __IO uint32_t ACORE_OTEAR3;                      /**< Outbound Translated Extended Address 3, offset: 0x138 */
  __IO uint32_t ACORE_OTAR3;                       /**< Outbound Translated Address 3, offset: 0x13C */
  __IO uint32_t ACORE_OWBAR4;                      /**< Outbound Window Base Address 4, offset: 0x140 */
  __IO uint32_t ACORE_OWAR4;                       /**< Outbound Window Attributes 4, offset: 0x144 */
  __IO uint32_t ACORE_OTEAR4;                      /**< Outbound Translated Extended Address 4, offset: 0x148 */
  __IO uint32_t ACORE_OTAR4;                       /**< Outbound Translated Address 4, offset: 0x14C */
  __IO uint32_t ACORE_OWBAR5;                      /**< Outbound Window Base Address 5, offset: 0x150 */
  __IO uint32_t ACORE_OWAR5;                       /**< Outbound Window Attributes 5, offset: 0x154 */
  __IO uint32_t ACORE_OTEAR5;                      /**< Outbound Translated Extended Address 5, offset: 0x158 */
  __IO uint32_t ACORE_OTAR5;                       /**< Outbound Translated Address 5, offset: 0x15C */
  __IO uint32_t ACORE_OWBAR6;                      /**< Outbound Window Base Address 6, offset: 0x160 */
  __IO uint32_t ACORE_OWAR6;                       /**< Outbound Window Attributes 6, offset: 0x164 */
  __IO uint32_t ACORE_OTEAR6;                      /**< Outbound Translated Extended Address 6, offset: 0x168 */
  __IO uint32_t ACORE_OTAR6;                       /**< Outbound Translated Address 6, offset: 0x16C */
  __IO uint32_t ACORE_OWBAR7;                      /**< Outbound Window Base Address 7, offset: 0x170 */
       uint8_t RESERVED_3[4];
  __IO uint32_t ACORE_OTEAR7;                      /**< Outbound Translated Extended Address 7, offset: 0x178 */
  __IO uint32_t ACORE_OTAR7;                       /**< Outbound Translated Address 7, offset: 0x17C */
} HSIO_ATU_Type;

/* ----------------------------------------------------------------------------
   -- HSIO_ATU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HSIO_ATU_Register_Masks HSIO_ATU Register Masks
 * @{
 */

/*! @name ATUCR - ATU Control */
/*! @{ */

#define HSIO_ATU_ATUCR_Spare4_MASK               (0x1U)
#define HSIO_ATU_ATUCR_Spare4_SHIFT              (0U)
/*! Spare4 - Spare 4 */
#define HSIO_ATU_ATUCR_Spare4(x)                 (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ATUCR_Spare4_SHIFT)) & HSIO_ATU_ATUCR_Spare4_MASK)

#define HSIO_ATU_ATUCR_Spare3_MASK               (0x2U)
#define HSIO_ATU_ATUCR_Spare3_SHIFT              (1U)
/*! Spare3 - Spare 3 */
#define HSIO_ATU_ATUCR_Spare3(x)                 (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ATUCR_Spare3_SHIFT)) & HSIO_ATU_ATUCR_Spare3_MASK)

#define HSIO_ATU_ATUCR_Spare2_MASK               (0x4U)
#define HSIO_ATU_ATUCR_Spare2_SHIFT              (2U)
/*! Spare2 - Spare 2 */
#define HSIO_ATU_ATUCR_Spare2(x)                 (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ATUCR_Spare2_SHIFT)) & HSIO_ATU_ATUCR_Spare2_MASK)

#define HSIO_ATU_ATUCR_Spare1_MASK               (0x8U)
#define HSIO_ATU_ATUCR_Spare1_SHIFT              (3U)
/*! Spare1 - Spare 1 */
#define HSIO_ATU_ATUCR_Spare1(x)                 (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ATUCR_Spare1_SHIFT)) & HSIO_ATU_ATUCR_Spare1_MASK)
/*! @} */

/*! @name ATUSR - ATU Status */
/*! @{ */

#define HSIO_ATU_ATUSR_MISS_ALL_MASK             (0x1U)
#define HSIO_ATU_ATUSR_MISS_ALL_SHIFT            (0U)
/*! MISS_ALL - Miss all
 *  0b0..No window misses have been detected
 *  0b1..At least one transaction has been received which missed all windows (sticky)
 */
#define HSIO_ATU_ATUSR_MISS_ALL(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ATUSR_MISS_ALL_SHIFT)) & HSIO_ATU_ATUSR_MISS_ALL_MASK)

#define HSIO_ATU_ATUSR_PGERR_W1_MASK             (0x2U)
#define HSIO_ATU_ATUSR_PGERR_W1_SHIFT            (1U)
/*! PGERR_W1 - Programming Error on Window 1
 *  0b0..No programming error detected
 *  0b1..Programming error detected
 */
#define HSIO_ATU_ATUSR_PGERR_W1(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ATUSR_PGERR_W1_SHIFT)) & HSIO_ATU_ATUSR_PGERR_W1_MASK)

#define HSIO_ATU_ATUSR_PGERR_W2_MASK             (0x4U)
#define HSIO_ATU_ATUSR_PGERR_W2_SHIFT            (2U)
/*! PGERR_W2 - Programming Error on Window 2
 *  0b0..No programming error detected
 *  0b1..Programming error detected
 */
#define HSIO_ATU_ATUSR_PGERR_W2(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ATUSR_PGERR_W2_SHIFT)) & HSIO_ATU_ATUSR_PGERR_W2_MASK)

#define HSIO_ATU_ATUSR_PGERR_W3_MASK             (0x8U)
#define HSIO_ATU_ATUSR_PGERR_W3_SHIFT            (3U)
/*! PGERR_W3 - Programming Error on Window 3
 *  0b0..No programming error detected
 *  0b1..Programming error detected
 */
#define HSIO_ATU_ATUSR_PGERR_W3(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ATUSR_PGERR_W3_SHIFT)) & HSIO_ATU_ATUSR_PGERR_W3_MASK)

#define HSIO_ATU_ATUSR_PGERR_W4_MASK             (0x10U)
#define HSIO_ATU_ATUSR_PGERR_W4_SHIFT            (4U)
/*! PGERR_W4 - Programming Error on Window 4
 *  0b0..No programming error detected
 *  0b1..Programming error detected
 */
#define HSIO_ATU_ATUSR_PGERR_W4(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ATUSR_PGERR_W4_SHIFT)) & HSIO_ATU_ATUSR_PGERR_W4_MASK)

#define HSIO_ATU_ATUSR_PGERR_W5_MASK             (0x20U)
#define HSIO_ATU_ATUSR_PGERR_W5_SHIFT            (5U)
/*! PGERR_W5 - Programming Error on Window 5
 *  0b0..No programming error detected
 *  0b1..Programming error detected
 */
#define HSIO_ATU_ATUSR_PGERR_W5(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ATUSR_PGERR_W5_SHIFT)) & HSIO_ATU_ATUSR_PGERR_W5_MASK)

#define HSIO_ATU_ATUSR_PGERR_W6_MASK             (0x40U)
#define HSIO_ATU_ATUSR_PGERR_W6_SHIFT            (6U)
/*! PGERR_W6 - Programming Error on Window 6
 *  0b0..No programming error detected
 *  0b1..Programming error detected
 */
#define HSIO_ATU_ATUSR_PGERR_W6(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ATUSR_PGERR_W6_SHIFT)) & HSIO_ATU_ATUSR_PGERR_W6_MASK)

#define HSIO_ATU_ATUSR_PGERR_W7_MASK             (0x80U)
#define HSIO_ATU_ATUSR_PGERR_W7_SHIFT            (7U)
/*! PGERR_W7 - Programming Error on Window 7
 *  0b0..No programming error detected
 *  0b1..Programming error detected
 */
#define HSIO_ATU_ATUSR_PGERR_W7(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ATUSR_PGERR_W7_SHIFT)) & HSIO_ATU_ATUSR_PGERR_W7_MASK)
/*! @} */

/*! @name IP_REV_1 - IP Block Revision 1 */
/*! @{ */

#define HSIO_ATU_IP_REV_1_IP_MN_MASK             (0xFFU)
#define HSIO_ATU_IP_REV_1_IP_MN_SHIFT            (0U)
/*! IP_MN - Minor revision */
#define HSIO_ATU_IP_REV_1_IP_MN(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_IP_REV_1_IP_MN_SHIFT)) & HSIO_ATU_IP_REV_1_IP_MN_MASK)

#define HSIO_ATU_IP_REV_1_IP_MJ_MASK             (0xFF00U)
#define HSIO_ATU_IP_REV_1_IP_MJ_SHIFT            (8U)
/*! IP_MJ - Major revision */
#define HSIO_ATU_IP_REV_1_IP_MJ(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_IP_REV_1_IP_MJ_SHIFT)) & HSIO_ATU_IP_REV_1_IP_MJ_MASK)

#define HSIO_ATU_IP_REV_1_IP_ID_MASK             (0xFFFF0000U)
#define HSIO_ATU_IP_REV_1_IP_ID_SHIFT            (16U)
/*! IP_ID - IP Block ID */
#define HSIO_ATU_IP_REV_1_IP_ID(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_IP_REV_1_IP_ID_SHIFT)) & HSIO_ATU_IP_REV_1_IP_ID_MASK)
/*! @} */

/*! @name IP_REV_2 - IP Block Revision 2 */
/*! @{ */

#define HSIO_ATU_IP_REV_2_IP_CFG_MASK            (0xFFU)
#define HSIO_ATU_IP_REV_2_IP_CFG_SHIFT           (0U)
/*! IP_CFG - Configuration options */
#define HSIO_ATU_IP_REV_2_IP_CFG(x)              (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_IP_REV_2_IP_CFG_SHIFT)) & HSIO_ATU_IP_REV_2_IP_CFG_MASK)

#define HSIO_ATU_IP_REV_2_IP_ERR_MASK            (0xFF00U)
#define HSIO_ATU_IP_REV_2_IP_ERR_SHIFT           (8U)
/*! IP_ERR - Errata revision level */
#define HSIO_ATU_IP_REV_2_IP_ERR(x)              (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_IP_REV_2_IP_ERR_SHIFT)) & HSIO_ATU_IP_REV_2_IP_ERR_MASK)

#define HSIO_ATU_IP_REV_2_IP_INT_MASK            (0xFF0000U)
#define HSIO_ATU_IP_REV_2_IP_INT_SHIFT           (16U)
/*! IP_INT - Integration options */
#define HSIO_ATU_IP_REV_2_IP_INT(x)              (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_IP_REV_2_IP_INT_SHIFT)) & HSIO_ATU_IP_REV_2_IP_INT_MASK)
/*! @} */

/*! @name PMCR - Performance Monitor */
/*! @{ */

#define HSIO_ATU_PMCR_PM2_SEL_MASK               (0xFFU)
#define HSIO_ATU_PMCR_PM2_SEL_SHIFT              (0U)
/*! PM2_SEL - Programmable Performance Monitor 2 Selection */
#define HSIO_ATU_PMCR_PM2_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_PMCR_PM2_SEL_SHIFT)) & HSIO_ATU_PMCR_PM2_SEL_MASK)

#define HSIO_ATU_PMCR_TM2_MSK_MASK               (0x700U)
#define HSIO_ATU_PMCR_TM2_MSK_SHIFT              (8U)
/*! TM2_MSK - Task Mark 2 Mask */
#define HSIO_ATU_PMCR_TM2_MSK(x)                 (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_PMCR_TM2_MSK_SHIFT)) & HSIO_ATU_PMCR_TM2_MSK_MASK)

#define HSIO_ATU_PMCR_TM2_VAL_MASK               (0x3800U)
#define HSIO_ATU_PMCR_TM2_VAL_SHIFT              (11U)
/*! TM2_VAL - Task Mark 2 Value */
#define HSIO_ATU_PMCR_TM2_VAL(x)                 (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_PMCR_TM2_VAL_SHIFT)) & HSIO_ATU_PMCR_TM2_VAL_MASK)

#define HSIO_ATU_PMCR_PM2_TYP_MASK               (0xC000U)
#define HSIO_ATU_PMCR_PM2_TYP_SHIFT              (14U)
/*! PM2_TYP - Programmable Performance Monitor 2 Type */
#define HSIO_ATU_PMCR_PM2_TYP(x)                 (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_PMCR_PM2_TYP_SHIFT)) & HSIO_ATU_PMCR_PM2_TYP_MASK)

#define HSIO_ATU_PMCR_PM1_SEL_MASK               (0xFF0000U)
#define HSIO_ATU_PMCR_PM1_SEL_SHIFT              (16U)
/*! PM1_SEL - Programmable Performance Monitor 1 Selection */
#define HSIO_ATU_PMCR_PM1_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_PMCR_PM1_SEL_SHIFT)) & HSIO_ATU_PMCR_PM1_SEL_MASK)

#define HSIO_ATU_PMCR_TM1_MSK_MASK               (0x7000000U)
#define HSIO_ATU_PMCR_TM1_MSK_SHIFT              (24U)
/*! TM1_MSK - Task Mark 1 Mask */
#define HSIO_ATU_PMCR_TM1_MSK(x)                 (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_PMCR_TM1_MSK_SHIFT)) & HSIO_ATU_PMCR_TM1_MSK_MASK)

#define HSIO_ATU_PMCR_TM1_VAL_MASK               (0x38000000U)
#define HSIO_ATU_PMCR_TM1_VAL_SHIFT              (27U)
/*! TM1_VAL - Task Mark 1 Value */
#define HSIO_ATU_PMCR_TM1_VAL(x)                 (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_PMCR_TM1_VAL_SHIFT)) & HSIO_ATU_PMCR_TM1_VAL_MASK)

#define HSIO_ATU_PMCR_PM1_TYP_MASK               (0xC0000000U)
#define HSIO_ATU_PMCR_PM1_TYP_SHIFT              (30U)
/*! PM1_TYP - Programmable Performance Monitor 1 Type
 *  0b00..This performance monitor event is disabled
 *  0b01..This performance monitor event is enabled for data read transactions only
 *  0b10..This performance monitor event is enabled for data write transactions only
 *  0b11..This performance monitor event is enabled for instruction fetch transactions only
 */
#define HSIO_ATU_PMCR_PM1_TYP(x)                 (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_PMCR_PM1_TYP_SHIFT)) & HSIO_ATU_PMCR_PM1_TYP_MASK)
/*! @} */

/*! @name ACORE_OWAR0 - Outbound Window Attributes 0 */
/*! @{ */

#define HSIO_ATU_ACORE_OWAR0_EN_MASK             (0x80000000U)
#define HSIO_ATU_ACORE_OWAR0_EN_SHIFT            (31U)
/*! EN - Enable
 *  0b0..Disable outbound translation window
 *  0b1..Enable outbound translation window
 */
#define HSIO_ATU_ACORE_OWAR0_EN(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWAR0_EN_SHIFT)) & HSIO_ATU_ACORE_OWAR0_EN_MASK)
/*! @} */

/*! @name ACORE_OTEAR0 - Outbound Translated Extended Address 0 */
/*! @{ */

#define HSIO_ATU_ACORE_OTEAR0_TEA_MASK           (0xFFFFFFFFU)
#define HSIO_ATU_ACORE_OTEAR0_TEA_SHIFT          (0U)
/*! TEA - Translated Extended Address */
#define HSIO_ATU_ACORE_OTEAR0_TEA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTEAR0_TEA_SHIFT)) & HSIO_ATU_ACORE_OTEAR0_TEA_MASK)
/*! @} */

/*! @name ACORE_OWBAR1 - Outbound Window Base Address 1 */
/*! @{ */

#define HSIO_ATU_ACORE_OWBAR1_OWS_MASK           (0x1FU)
#define HSIO_ATU_ACORE_OWBAR1_OWS_SHIFT          (0U)
/*! OWS - Outbound Window Size
 *  0b00000..1 MB window size
 *  0b00001..2 MB window size
 *  0b00010..4 MB window size
 *  0b00011..8 MB window size
 *  0b00100..16 MB window size
 *  0b00101..32 MB window size
 *  0b00110..64 MB window size
 *  0b00111..128 MB window size
 *  0b01000..256 MB window size
 *  0b01001..512 MB window size
 *  0b01010..1 GB window size
 *  0b01011..2 GB window size
 *  0b01100..Reserved
 *  0b01101..Reserved
 *  0b01110..Reserved
 *  0b01111..Reserved
 *  0b1xxxx..Reserved
 */
#define HSIO_ATU_ACORE_OWBAR1_OWS(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR1_OWS_SHIFT)) & HSIO_ATU_ACORE_OWBAR1_OWS_MASK)

#define HSIO_ATU_ACORE_OWBAR1_WBA_MASK           (0xFFF0000U)
#define HSIO_ATU_ACORE_OWBAR1_WBA_SHIFT          (16U)
/*! WBA - Window Base Address */
#define HSIO_ATU_ACORE_OWBAR1_WBA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR1_WBA_SHIFT)) & HSIO_ATU_ACORE_OWBAR1_WBA_MASK)

#define HSIO_ATU_ACORE_OWBAR1_DOMAIN_ID_MASK     (0xF0000000U)
#define HSIO_ATU_ACORE_OWBAR1_DOMAIN_ID_SHIFT    (28U)
/*! DOMAIN_ID - Domain Identifier */
#define HSIO_ATU_ACORE_OWBAR1_DOMAIN_ID(x)       (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR1_DOMAIN_ID_SHIFT)) & HSIO_ATU_ACORE_OWBAR1_DOMAIN_ID_MASK)
/*! @} */

/*! @name ACORE_OWAR1 - Outbound Window Attributes 1 */
/*! @{ */

#define HSIO_ATU_ACORE_OWAR1_EN_MASK             (0x80000000U)
#define HSIO_ATU_ACORE_OWAR1_EN_SHIFT            (31U)
/*! EN - Enable
 *  0b0..Disable outbound translation window
 *  0b1..Enable outbound translation window
 */
#define HSIO_ATU_ACORE_OWAR1_EN(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWAR1_EN_SHIFT)) & HSIO_ATU_ACORE_OWAR1_EN_MASK)
/*! @} */

/*! @name ACORE_OTEAR1 - Outbound Translated Extended Address 1 */
/*! @{ */

#define HSIO_ATU_ACORE_OTEAR1_TEA_MASK           (0xFFFFFFFFU)
#define HSIO_ATU_ACORE_OTEAR1_TEA_SHIFT          (0U)
/*! TEA - Translated Extended Address */
#define HSIO_ATU_ACORE_OTEAR1_TEA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTEAR1_TEA_SHIFT)) & HSIO_ATU_ACORE_OTEAR1_TEA_MASK)
/*! @} */

/*! @name ACORE_OTAR1 - Outbound Translated Address 1 */
/*! @{ */

#define HSIO_ATU_ACORE_OTAR1_TA_MASK             (0xFFFF0000U)
#define HSIO_ATU_ACORE_OTAR1_TA_SHIFT            (16U)
/*! TA - Translated Address */
#define HSIO_ATU_ACORE_OTAR1_TA(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTAR1_TA_SHIFT)) & HSIO_ATU_ACORE_OTAR1_TA_MASK)
/*! @} */

/*! @name ACORE_OWBAR2 - Outbound Window Base Address 2 */
/*! @{ */

#define HSIO_ATU_ACORE_OWBAR2_OWS_MASK           (0x1FU)
#define HSIO_ATU_ACORE_OWBAR2_OWS_SHIFT          (0U)
/*! OWS - Outbound Window Size
 *  0b00000..1 MB window size
 *  0b00001..2 MB window size
 *  0b00010..4 MB window size
 *  0b00011..8 MB window size
 *  0b00100..16 MB window size
 *  0b00101..32 MB window size
 *  0b00110..64 MB window size
 *  0b00111..128 MB window size
 *  0b01000..256 MB window size
 *  0b01001..512 MB window size
 *  0b01010..1 GB window size
 *  0b01011..2 GB window size
 *  0b01100..Reserved
 *  0b01101..Reserved
 *  0b01110..Reserved
 *  0b01111..Reserved
 *  0b1xxxx..Reserved
 */
#define HSIO_ATU_ACORE_OWBAR2_OWS(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR2_OWS_SHIFT)) & HSIO_ATU_ACORE_OWBAR2_OWS_MASK)

#define HSIO_ATU_ACORE_OWBAR2_WBA_MASK           (0xFFF0000U)
#define HSIO_ATU_ACORE_OWBAR2_WBA_SHIFT          (16U)
/*! WBA - Window Base Address */
#define HSIO_ATU_ACORE_OWBAR2_WBA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR2_WBA_SHIFT)) & HSIO_ATU_ACORE_OWBAR2_WBA_MASK)

#define HSIO_ATU_ACORE_OWBAR2_DOMAIN_ID_MASK     (0xF0000000U)
#define HSIO_ATU_ACORE_OWBAR2_DOMAIN_ID_SHIFT    (28U)
/*! DOMAIN_ID - Domain Identifier */
#define HSIO_ATU_ACORE_OWBAR2_DOMAIN_ID(x)       (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR2_DOMAIN_ID_SHIFT)) & HSIO_ATU_ACORE_OWBAR2_DOMAIN_ID_MASK)
/*! @} */

/*! @name ACORE_OWAR2 - Outbound Window Attributes 2 */
/*! @{ */

#define HSIO_ATU_ACORE_OWAR2_EN_MASK             (0x80000000U)
#define HSIO_ATU_ACORE_OWAR2_EN_SHIFT            (31U)
/*! EN - Enable
 *  0b0..Disable outbound translation window
 *  0b1..Enable outbound translation window
 */
#define HSIO_ATU_ACORE_OWAR2_EN(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWAR2_EN_SHIFT)) & HSIO_ATU_ACORE_OWAR2_EN_MASK)
/*! @} */

/*! @name ACORE_OTEAR2 - Outbound Translated Extended Address 2 */
/*! @{ */

#define HSIO_ATU_ACORE_OTEAR2_TEA_MASK           (0xFFFFFFFFU)
#define HSIO_ATU_ACORE_OTEAR2_TEA_SHIFT          (0U)
/*! TEA - Translated Extended Address */
#define HSIO_ATU_ACORE_OTEAR2_TEA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTEAR2_TEA_SHIFT)) & HSIO_ATU_ACORE_OTEAR2_TEA_MASK)
/*! @} */

/*! @name ACORE_OTAR2 - Outbound Translated Address 2 */
/*! @{ */

#define HSIO_ATU_ACORE_OTAR2_TA_MASK             (0xFFFF0000U)
#define HSIO_ATU_ACORE_OTAR2_TA_SHIFT            (16U)
/*! TA - Translated Address */
#define HSIO_ATU_ACORE_OTAR2_TA(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTAR2_TA_SHIFT)) & HSIO_ATU_ACORE_OTAR2_TA_MASK)
/*! @} */

/*! @name ACORE_OWBAR3 - Outbound Window Base Address 3 */
/*! @{ */

#define HSIO_ATU_ACORE_OWBAR3_OWS_MASK           (0x1FU)
#define HSIO_ATU_ACORE_OWBAR3_OWS_SHIFT          (0U)
/*! OWS - Outbound Window Size
 *  0b00000..1 MB window size
 *  0b00001..2 MB window size
 *  0b00010..4 MB window size
 *  0b00011..8 MB window size
 *  0b00100..16 MB window size
 *  0b00101..32 MB window size
 *  0b00110..64 MB window size
 *  0b00111..128 MB window size
 *  0b01000..256 MB window size
 *  0b01001..512 MB window size
 *  0b01010..1 GB window size
 *  0b01011..2 GB window size
 *  0b01100..Reserved
 *  0b01101..Reserved
 *  0b01110..Reserved
 *  0b01111..Reserved
 *  0b1xxxx..Reserved
 */
#define HSIO_ATU_ACORE_OWBAR3_OWS(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR3_OWS_SHIFT)) & HSIO_ATU_ACORE_OWBAR3_OWS_MASK)

#define HSIO_ATU_ACORE_OWBAR3_WBA_MASK           (0xFFF0000U)
#define HSIO_ATU_ACORE_OWBAR3_WBA_SHIFT          (16U)
/*! WBA - Window Base Address */
#define HSIO_ATU_ACORE_OWBAR3_WBA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR3_WBA_SHIFT)) & HSIO_ATU_ACORE_OWBAR3_WBA_MASK)

#define HSIO_ATU_ACORE_OWBAR3_DOMAIN_ID_MASK     (0xF0000000U)
#define HSIO_ATU_ACORE_OWBAR3_DOMAIN_ID_SHIFT    (28U)
/*! DOMAIN_ID - Domain Identifier */
#define HSIO_ATU_ACORE_OWBAR3_DOMAIN_ID(x)       (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR3_DOMAIN_ID_SHIFT)) & HSIO_ATU_ACORE_OWBAR3_DOMAIN_ID_MASK)
/*! @} */

/*! @name ACORE_OWAR3 - Outbound Window Attributes 3 */
/*! @{ */

#define HSIO_ATU_ACORE_OWAR3_EN_MASK             (0x80000000U)
#define HSIO_ATU_ACORE_OWAR3_EN_SHIFT            (31U)
/*! EN - Enable
 *  0b0..Disable outbound translation window
 *  0b1..Enable outbound translation window
 */
#define HSIO_ATU_ACORE_OWAR3_EN(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWAR3_EN_SHIFT)) & HSIO_ATU_ACORE_OWAR3_EN_MASK)
/*! @} */

/*! @name ACORE_OTEAR3 - Outbound Translated Extended Address 3 */
/*! @{ */

#define HSIO_ATU_ACORE_OTEAR3_TEA_MASK           (0xFFFFFFFFU)
#define HSIO_ATU_ACORE_OTEAR3_TEA_SHIFT          (0U)
/*! TEA - Translated Extended Address */
#define HSIO_ATU_ACORE_OTEAR3_TEA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTEAR3_TEA_SHIFT)) & HSIO_ATU_ACORE_OTEAR3_TEA_MASK)
/*! @} */

/*! @name ACORE_OTAR3 - Outbound Translated Address 3 */
/*! @{ */

#define HSIO_ATU_ACORE_OTAR3_TA_MASK             (0xFFFF0000U)
#define HSIO_ATU_ACORE_OTAR3_TA_SHIFT            (16U)
/*! TA - Translated Address */
#define HSIO_ATU_ACORE_OTAR3_TA(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTAR3_TA_SHIFT)) & HSIO_ATU_ACORE_OTAR3_TA_MASK)
/*! @} */

/*! @name ACORE_OWBAR4 - Outbound Window Base Address 4 */
/*! @{ */

#define HSIO_ATU_ACORE_OWBAR4_OWS_MASK           (0x1FU)
#define HSIO_ATU_ACORE_OWBAR4_OWS_SHIFT          (0U)
/*! OWS - Outbound Window Size
 *  0b00000..1 MB window size
 *  0b00001..2 MB window size
 *  0b00010..4 MB window size
 *  0b00011..8 MB window size
 *  0b00100..16 MB window size
 *  0b00101..32 MB window size
 *  0b00110..64 MB window size
 *  0b00111..128 MB window size
 *  0b01000..256 MB window size
 *  0b01001..512 MB window size
 *  0b01010..1 GB window size
 *  0b01011..2 GB window size
 *  0b01100..Reserved
 *  0b01101..Reserved
 *  0b01110..Reserved
 *  0b01111..Reserved
 *  0b1xxxx..Reserved
 */
#define HSIO_ATU_ACORE_OWBAR4_OWS(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR4_OWS_SHIFT)) & HSIO_ATU_ACORE_OWBAR4_OWS_MASK)

#define HSIO_ATU_ACORE_OWBAR4_WBA_MASK           (0xFFF0000U)
#define HSIO_ATU_ACORE_OWBAR4_WBA_SHIFT          (16U)
/*! WBA - Window Base Address */
#define HSIO_ATU_ACORE_OWBAR4_WBA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR4_WBA_SHIFT)) & HSIO_ATU_ACORE_OWBAR4_WBA_MASK)

#define HSIO_ATU_ACORE_OWBAR4_DOMAIN_ID_MASK     (0xF0000000U)
#define HSIO_ATU_ACORE_OWBAR4_DOMAIN_ID_SHIFT    (28U)
/*! DOMAIN_ID - Domain Identifier */
#define HSIO_ATU_ACORE_OWBAR4_DOMAIN_ID(x)       (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR4_DOMAIN_ID_SHIFT)) & HSIO_ATU_ACORE_OWBAR4_DOMAIN_ID_MASK)
/*! @} */

/*! @name ACORE_OWAR4 - Outbound Window Attributes 4 */
/*! @{ */

#define HSIO_ATU_ACORE_OWAR4_EN_MASK             (0x80000000U)
#define HSIO_ATU_ACORE_OWAR4_EN_SHIFT            (31U)
/*! EN - Enable
 *  0b0..Disable outbound translation window
 *  0b1..Enable outbound translation window
 */
#define HSIO_ATU_ACORE_OWAR4_EN(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWAR4_EN_SHIFT)) & HSIO_ATU_ACORE_OWAR4_EN_MASK)
/*! @} */

/*! @name ACORE_OTEAR4 - Outbound Translated Extended Address 4 */
/*! @{ */

#define HSIO_ATU_ACORE_OTEAR4_TEA_MASK           (0xFFFFFFFFU)
#define HSIO_ATU_ACORE_OTEAR4_TEA_SHIFT          (0U)
/*! TEA - Translated Extended Address */
#define HSIO_ATU_ACORE_OTEAR4_TEA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTEAR4_TEA_SHIFT)) & HSIO_ATU_ACORE_OTEAR4_TEA_MASK)
/*! @} */

/*! @name ACORE_OTAR4 - Outbound Translated Address 4 */
/*! @{ */

#define HSIO_ATU_ACORE_OTAR4_TA_MASK             (0xFFFF0000U)
#define HSIO_ATU_ACORE_OTAR4_TA_SHIFT            (16U)
/*! TA - Translated Address */
#define HSIO_ATU_ACORE_OTAR4_TA(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTAR4_TA_SHIFT)) & HSIO_ATU_ACORE_OTAR4_TA_MASK)
/*! @} */

/*! @name ACORE_OWBAR5 - Outbound Window Base Address 5 */
/*! @{ */

#define HSIO_ATU_ACORE_OWBAR5_OWS_MASK           (0x1FU)
#define HSIO_ATU_ACORE_OWBAR5_OWS_SHIFT          (0U)
/*! OWS - Outbound Window Size
 *  0b00000..1 MB window size
 *  0b00001..2 MB window size
 *  0b00010..4 MB window size
 *  0b00011..8 MB window size
 *  0b00100..16 MB window size
 *  0b00101..32 MB window size
 *  0b00110..64 MB window size
 *  0b00111..128 MB window size
 *  0b01000..256 MB window size
 *  0b01001..512 MB window size
 *  0b01010..1 GB window size
 *  0b01011..2 GB window size
 *  0b01100..Reserved
 *  0b01101..Reserved
 *  0b01110..Reserved
 *  0b01111..Reserved
 *  0b1xxxx..Reserved
 */
#define HSIO_ATU_ACORE_OWBAR5_OWS(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR5_OWS_SHIFT)) & HSIO_ATU_ACORE_OWBAR5_OWS_MASK)

#define HSIO_ATU_ACORE_OWBAR5_WBA_MASK           (0xFFF0000U)
#define HSIO_ATU_ACORE_OWBAR5_WBA_SHIFT          (16U)
/*! WBA - Window Base Address */
#define HSIO_ATU_ACORE_OWBAR5_WBA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR5_WBA_SHIFT)) & HSIO_ATU_ACORE_OWBAR5_WBA_MASK)

#define HSIO_ATU_ACORE_OWBAR5_DOMAIN_ID_MASK     (0xF0000000U)
#define HSIO_ATU_ACORE_OWBAR5_DOMAIN_ID_SHIFT    (28U)
/*! DOMAIN_ID - Domain Identifier */
#define HSIO_ATU_ACORE_OWBAR5_DOMAIN_ID(x)       (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR5_DOMAIN_ID_SHIFT)) & HSIO_ATU_ACORE_OWBAR5_DOMAIN_ID_MASK)
/*! @} */

/*! @name ACORE_OWAR5 - Outbound Window Attributes 5 */
/*! @{ */

#define HSIO_ATU_ACORE_OWAR5_EN_MASK             (0x80000000U)
#define HSIO_ATU_ACORE_OWAR5_EN_SHIFT            (31U)
/*! EN - Enable
 *  0b0..Disable outbound translation window
 *  0b1..Enable outbound translation window
 */
#define HSIO_ATU_ACORE_OWAR5_EN(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWAR5_EN_SHIFT)) & HSIO_ATU_ACORE_OWAR5_EN_MASK)
/*! @} */

/*! @name ACORE_OTEAR5 - Outbound Translated Extended Address 5 */
/*! @{ */

#define HSIO_ATU_ACORE_OTEAR5_TEA_MASK           (0xFFFFFFFFU)
#define HSIO_ATU_ACORE_OTEAR5_TEA_SHIFT          (0U)
/*! TEA - Translated Extended Address */
#define HSIO_ATU_ACORE_OTEAR5_TEA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTEAR5_TEA_SHIFT)) & HSIO_ATU_ACORE_OTEAR5_TEA_MASK)
/*! @} */

/*! @name ACORE_OTAR5 - Outbound Translated Address 5 */
/*! @{ */

#define HSIO_ATU_ACORE_OTAR5_TA_MASK             (0xFFFF0000U)
#define HSIO_ATU_ACORE_OTAR5_TA_SHIFT            (16U)
/*! TA - Translated Address */
#define HSIO_ATU_ACORE_OTAR5_TA(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTAR5_TA_SHIFT)) & HSIO_ATU_ACORE_OTAR5_TA_MASK)
/*! @} */

/*! @name ACORE_OWBAR6 - Outbound Window Base Address 6 */
/*! @{ */

#define HSIO_ATU_ACORE_OWBAR6_OWS_MASK           (0x1FU)
#define HSIO_ATU_ACORE_OWBAR6_OWS_SHIFT          (0U)
/*! OWS - Outbound Window Size
 *  0b00000..1 MB window size
 *  0b00001..2 MB window size
 *  0b00010..4 MB window size
 *  0b00011..8 MB window size
 *  0b00100..16 MB window size
 *  0b00101..32 MB window size
 *  0b00110..64 MB window size
 *  0b00111..128 MB window size
 *  0b01000..256 MB window size
 *  0b01001..512 MB window size
 *  0b01010..1 GB window size
 *  0b01011..2 GB window size
 *  0b01100..Reserved
 *  0b01101..Reserved
 *  0b01110..Reserved
 *  0b01111..Reserved
 *  0b1xxxx..Reserved
 */
#define HSIO_ATU_ACORE_OWBAR6_OWS(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR6_OWS_SHIFT)) & HSIO_ATU_ACORE_OWBAR6_OWS_MASK)

#define HSIO_ATU_ACORE_OWBAR6_WBA_MASK           (0xFFF0000U)
#define HSIO_ATU_ACORE_OWBAR6_WBA_SHIFT          (16U)
/*! WBA - Window Base Address */
#define HSIO_ATU_ACORE_OWBAR6_WBA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR6_WBA_SHIFT)) & HSIO_ATU_ACORE_OWBAR6_WBA_MASK)

#define HSIO_ATU_ACORE_OWBAR6_DOMAIN_ID_MASK     (0xF0000000U)
#define HSIO_ATU_ACORE_OWBAR6_DOMAIN_ID_SHIFT    (28U)
/*! DOMAIN_ID - Domain Identifier */
#define HSIO_ATU_ACORE_OWBAR6_DOMAIN_ID(x)       (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR6_DOMAIN_ID_SHIFT)) & HSIO_ATU_ACORE_OWBAR6_DOMAIN_ID_MASK)
/*! @} */

/*! @name ACORE_OWAR6 - Outbound Window Attributes 6 */
/*! @{ */

#define HSIO_ATU_ACORE_OWAR6_EN_MASK             (0x80000000U)
#define HSIO_ATU_ACORE_OWAR6_EN_SHIFT            (31U)
/*! EN - Enable
 *  0b0..Disable outbound translation window
 *  0b1..Enable outbound translation window
 */
#define HSIO_ATU_ACORE_OWAR6_EN(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWAR6_EN_SHIFT)) & HSIO_ATU_ACORE_OWAR6_EN_MASK)
/*! @} */

/*! @name ACORE_OTEAR6 - Outbound Translated Extended Address 6 */
/*! @{ */

#define HSIO_ATU_ACORE_OTEAR6_TEA_MASK           (0xFFFFFFFFU)
#define HSIO_ATU_ACORE_OTEAR6_TEA_SHIFT          (0U)
/*! TEA - Translated Extended Address */
#define HSIO_ATU_ACORE_OTEAR6_TEA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTEAR6_TEA_SHIFT)) & HSIO_ATU_ACORE_OTEAR6_TEA_MASK)
/*! @} */

/*! @name ACORE_OTAR6 - Outbound Translated Address 6 */
/*! @{ */

#define HSIO_ATU_ACORE_OTAR6_TA_MASK             (0xFFFF0000U)
#define HSIO_ATU_ACORE_OTAR6_TA_SHIFT            (16U)
/*! TA - Translated Address */
#define HSIO_ATU_ACORE_OTAR6_TA(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTAR6_TA_SHIFT)) & HSIO_ATU_ACORE_OTAR6_TA_MASK)
/*! @} */

/*! @name ACORE_OWBAR7 - Outbound Window Base Address 7 */
/*! @{ */

#define HSIO_ATU_ACORE_OWBAR7_OWS_MASK           (0x1FU)
#define HSIO_ATU_ACORE_OWBAR7_OWS_SHIFT          (0U)
/*! OWS - Outbound Window Size
 *  0b00000..1 MB window size
 *  0b00001..2 MB window size
 *  0b00010..4 MB window size
 *  0b00011..8 MB window size
 *  0b00100..16 MB window size
 *  0b00101..32 MB window size
 *  0b00110..64 MB window size
 *  0b00111..128 MB window size
 *  0b01000..256 MB window size
 *  0b01001..512 MB window size
 *  0b01010..1 GB window size
 *  0b01011..2 GB window size
 *  0b01100..Reserved
 *  0b01101..Reserved
 *  0b01110..Reserved
 *  0b01111..Reserved
 *  0b1xxxx..Reserved
 */
#define HSIO_ATU_ACORE_OWBAR7_OWS(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR7_OWS_SHIFT)) & HSIO_ATU_ACORE_OWBAR7_OWS_MASK)

#define HSIO_ATU_ACORE_OWBAR7_WBA_MASK           (0xFFF0000U)
#define HSIO_ATU_ACORE_OWBAR7_WBA_SHIFT          (16U)
/*! WBA - Window Base Address */
#define HSIO_ATU_ACORE_OWBAR7_WBA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR7_WBA_SHIFT)) & HSIO_ATU_ACORE_OWBAR7_WBA_MASK)

#define HSIO_ATU_ACORE_OWBAR7_DOMAIN_ID_MASK     (0xF0000000U)
#define HSIO_ATU_ACORE_OWBAR7_DOMAIN_ID_SHIFT    (28U)
/*! DOMAIN_ID - Domain Identifier */
#define HSIO_ATU_ACORE_OWBAR7_DOMAIN_ID(x)       (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OWBAR7_DOMAIN_ID_SHIFT)) & HSIO_ATU_ACORE_OWBAR7_DOMAIN_ID_MASK)
/*! @} */

/*! @name ACORE_OTEAR7 - Outbound Translated Extended Address 7 */
/*! @{ */

#define HSIO_ATU_ACORE_OTEAR7_TEA_MASK           (0xFFFFFFFFU)
#define HSIO_ATU_ACORE_OTEAR7_TEA_SHIFT          (0U)
/*! TEA - Translated Extended Address */
#define HSIO_ATU_ACORE_OTEAR7_TEA(x)             (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTEAR7_TEA_SHIFT)) & HSIO_ATU_ACORE_OTEAR7_TEA_MASK)
/*! @} */

/*! @name ACORE_OTAR7 - Outbound Translated Address 7 */
/*! @{ */

#define HSIO_ATU_ACORE_OTAR7_TA_MASK             (0xFFFF0000U)
#define HSIO_ATU_ACORE_OTAR7_TA_SHIFT            (16U)
/*! TA - Translated Address */
#define HSIO_ATU_ACORE_OTAR7_TA(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_ATU_ACORE_OTAR7_TA_SHIFT)) & HSIO_ATU_ACORE_OTAR7_TA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group HSIO_ATU_Register_Masks */


/*!
 * @}
 */ /* end of group HSIO_ATU_Peripheral_Access_Layer */


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


#endif  /* PERI_HSIO_ATU_H_ */

