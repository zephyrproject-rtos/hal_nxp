/*
** ###################################################################
**     Processors:          MIMX9522xxVTx_ca55
**                          MIMX9522xxVTx_cm33
**                          MIMX9522xxVTx_cm7
**                          MIMX9522xxVZx_ca55
**                          MIMX9522xxVZx_cm33
**                          MIMX9522xxVZx_cm7
**                          MIMX9523xxVTx_ca55
**                          MIMX9523xxVTx_cm33
**                          MIMX9523xxVTx_cm7
**                          MIMX9523xxVZx_ca55
**                          MIMX9523xxVZx_cm33
**                          MIMX9523xxVZx_cm7
**                          MIMX9524xxVTx_ca55
**                          MIMX9524xxVTx_cm33
**                          MIMX9524xxVTx_cm7
**                          MIMX9524xxVZx_ca55
**                          MIMX9524xxVZx_cm33
**                          MIMX9524xxVZx_cm7
**                          MIMX9525xxVTx_ca55
**                          MIMX9525xxVTx_cm33
**                          MIMX9525xxVTx_cm7
**                          MIMX9525xxVZx_ca55
**                          MIMX9525xxVZx_cm33
**                          MIMX9525xxVZx_cm7
**                          MIMX9528xxVTx_ca55
**                          MIMX9528xxVTx_cm33
**                          MIMX9528xxVTx_cm7
**                          MIMX9528xxVZx_ca55
**                          MIMX9528xxVZx_cm33
**                          MIMX9528xxVZx_cm7
**                          MIMX9529xxVTx_ca55
**                          MIMX9529xxVTx_cm33
**                          MIMX9529xxVTx_cm7
**                          MIMX9529xxVZx_ca55
**                          MIMX9529xxVZx_cm33
**                          MIMX9529xxVZx_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260324
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FSB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
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
 * @file PERI_FSB.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FSB
 *
 * CMSIS Peripheral Access Layer for FSB
 */

#if !defined(PERI_FSB_H_)
#define PERI_FSB_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9522xxVTx_ca55) || defined(CPU_MIMX9522xxVZx_ca55))
#include "MIMX9522_ca55_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm33) || defined(CPU_MIMX9522xxVZx_cm33))
#include "MIMX9522_cm33_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm7) || defined(CPU_MIMX9522xxVZx_cm7))
#include "MIMX9522_cm7_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_ca55) || defined(CPU_MIMX9523xxVZx_ca55))
#include "MIMX9523_ca55_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm33) || defined(CPU_MIMX9523xxVZx_cm33))
#include "MIMX9523_cm33_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm7) || defined(CPU_MIMX9523xxVZx_cm7))
#include "MIMX9523_cm7_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_ca55) || defined(CPU_MIMX9524xxVZx_ca55))
#include "MIMX9524_ca55_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm33) || defined(CPU_MIMX9524xxVZx_cm33))
#include "MIMX9524_cm33_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm7) || defined(CPU_MIMX9524xxVZx_cm7))
#include "MIMX9524_cm7_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_ca55) || defined(CPU_MIMX9525xxVZx_ca55))
#include "MIMX9525_ca55_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm33) || defined(CPU_MIMX9525xxVZx_cm33))
#include "MIMX9525_cm33_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm7) || defined(CPU_MIMX9525xxVZx_cm7))
#include "MIMX9525_cm7_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_ca55) || defined(CPU_MIMX9528xxVZx_ca55))
#include "MIMX9528_ca55_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm33) || defined(CPU_MIMX9528xxVZx_cm33))
#include "MIMX9528_cm33_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm7) || defined(CPU_MIMX9528xxVZx_cm7))
#include "MIMX9528_cm7_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_ca55) || defined(CPU_MIMX9529xxVZx_ca55))
#include "MIMX9529_ca55_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm33) || defined(CPU_MIMX9529xxVZx_cm33))
#include "MIMX9529_cm33_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm7) || defined(CPU_MIMX9529xxVZx_cm7))
#include "MIMX9529_cm7_COMMON.h"
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
   -- FSB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSB_Peripheral_Access_Layer FSB Peripheral Access Layer
 * @{
 */

/** FSB - Size of Registers Arrays */
#define FSB_FUSE_ARRAY_COUNT                      8192u

/** FSB - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< FSB Version ID Register, offset: 0x0 */
       uint8_t RESERVED_0[24];
  __I  uint32_t FSB_STATUS;                        /**< FSB Status Register, offset: 0x1C */
       uint8_t RESERVED_1[68];
  __IO uint32_t ACCESS_COUNT;                      /**< Access Count Register, offset: 0x64 */
       uint8_t RESERVED_2[920];
  __I  uint32_t STAT_0;                            /**< Status Register 0, offset: 0x400 */
  __I  uint32_t STAT_1;                            /**< Status Register 1, offset: 0x404 */
       uint8_t RESERVED_3[12];
  __I  uint32_t STAT_5;                            /**< Status Register 5, offset: 0x414 */
  __I  uint32_t STAT_6;                            /**< Status Register 6, offset: 0x418 */
  __I  uint32_t STAT_7;                            /**< Status Register 7, offset: 0x41C */
       uint8_t RESERVED_4[4];
  __I  uint32_t TROUT_STATUS_0;                    /**< TROUT Status, offset: 0x424 */
  __I  uint32_t TROUT_STATUS_1;                    /**< TROUT Status, offset: 0x428 */
       uint8_t RESERVED_5[3028];
  __IO uint32_t FUSE_STAT;                         /**< Fuse Status Register, offset: 0x1000 */
  __IO uint32_t FUSE_EVNT;                         /**< Fuse Event Register, offset: 0x1004 */
  __IO uint32_t FUSE_INT_EN;                       /**< Fuse Interrupt Enable Register, offset: 0x1008 */
  __I  uint32_t FUSE_INT;                          /**< Fuse Interrupt Register, offset: 0x100C */
       uint8_t RESERVED_6[28656];
  __I  uint32_t FUSE[FSB_FUSE_ARRAY_COUNT];        /**< Fuse Value Registers, array offset: 0x8000, array step: 0x4 */
} FSB_Type;

/* ----------------------------------------------------------------------------
   -- FSB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSB_Register_Masks FSB Register Masks
 * @{
 */

/*! @name VERID - FSB Version ID Register */
/*! @{ */

#define FSB_VERID_MISC_MASK                      (0xFFU)
#define FSB_VERID_MISC_SHIFT                     (0U)
/*! MISC - Feature Specification
 *  0bxxxxxx1x..MU IRQ steering is enabled.
 *  0bxxxxxxx1..Support for stopped transfers to OCOTP fuse space on the FSB target APB is enabled.
 */
#define FSB_VERID_MISC(x)                        (((uint32_t)(((uint32_t)(x)) << FSB_VERID_MISC_SHIFT)) & FSB_VERID_MISC_MASK)

#define FSB_VERID_ECO_MASK                       (0xFF00U)
#define FSB_VERID_ECO_SHIFT                      (8U)
/*! ECO - ECO Version Number */
#define FSB_VERID_ECO(x)                         (((uint32_t)(((uint32_t)(x)) << FSB_VERID_ECO_SHIFT)) & FSB_VERID_ECO_MASK)

#define FSB_VERID_MINOR_MASK                     (0xFF0000U)
#define FSB_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define FSB_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << FSB_VERID_MINOR_SHIFT)) & FSB_VERID_MINOR_MASK)

#define FSB_VERID_MAJOR_MASK                     (0xFF000000U)
#define FSB_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define FSB_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << FSB_VERID_MAJOR_SHIFT)) & FSB_VERID_MAJOR_MASK)
/*! @} */

/*! @name FSB_STATUS - FSB Status Register */
/*! @{ */

#define FSB_FSB_STATUS_VMTR_MASK                 (0x1U)
#define FSB_FSB_STATUS_VMTR_SHIFT                (0U)
/*! VMTR - MTR Trim fuses valid. */
#define FSB_FSB_STATUS_VMTR(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_VMTR_SHIFT)) & FSB_FSB_STATUS_VMTR_MASK)

#define FSB_FSB_STATUS_VERL_MASK                 (0x2U)
#define FSB_FSB_STATUS_VERL_SHIFT                (1U)
/*! VERL - Early fuses valid. */
#define FSB_FSB_STATUS_VERL(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_VERL_SHIFT)) & FSB_FSB_STATUS_VERL_MASK)

#define FSB_FSB_STATUS_VMED_MASK                 (0x4U)
#define FSB_FSB_STATUS_VMED_SHIFT                (2U)
/*! VMED - Medium fuses valid. */
#define FSB_FSB_STATUS_VMED(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_VMED_SHIFT)) & FSB_FSB_STATUS_VMED_MASK)

#define FSB_FSB_STATUS_VALL_MASK                 (0x8U)
#define FSB_FSB_STATUS_VALL_SHIFT                (3U)
/*! VALL - All fuses valid. */
#define FSB_FSB_STATUS_VALL(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_VALL_SHIFT)) & FSB_FSB_STATUS_VALL_MASK)

#define FSB_FSB_STATUS_LMTR_MASK                 (0x10U)
#define FSB_FSB_STATUS_LMTR_SHIFT                (4U)
/*! LMTR - MTR Trim fuses loaded. */
#define FSB_FSB_STATUS_LMTR(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_LMTR_SHIFT)) & FSB_FSB_STATUS_LMTR_MASK)

#define FSB_FSB_STATUS_LERL_MASK                 (0x20U)
#define FSB_FSB_STATUS_LERL_SHIFT                (5U)
/*! LERL - Early fuses loaded. */
#define FSB_FSB_STATUS_LERL(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_LERL_SHIFT)) & FSB_FSB_STATUS_LERL_MASK)

#define FSB_FSB_STATUS_LMED_MASK                 (0x40U)
#define FSB_FSB_STATUS_LMED_SHIFT                (6U)
/*! LMED - Medium fuses loaded. */
#define FSB_FSB_STATUS_LMED(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_LMED_SHIFT)) & FSB_FSB_STATUS_LMED_MASK)

#define FSB_FSB_STATUS_LALL_MASK                 (0x80U)
#define FSB_FSB_STATUS_LALL_SHIFT                (7U)
/*! LALL - All fuses loaded. */
#define FSB_FSB_STATUS_LALL(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_LALL_SHIFT)) & FSB_FSB_STATUS_LALL_MASK)
/*! @} */

/*! @name ACCESS_COUNT - Access Count Register */
/*! @{ */

#define FSB_ACCESS_COUNT_COUNT_MASK              (0xFFFFFFFFU)
#define FSB_ACCESS_COUNT_COUNT_SHIFT             (0U)
/*! COUNT - Access Count Register. */
#define FSB_ACCESS_COUNT_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << FSB_ACCESS_COUNT_COUNT_SHIFT)) & FSB_ACCESS_COUNT_COUNT_MASK)
/*! @} */

/*! @name STAT_0 - Status Register 0 */
/*! @{ */

#define FSB_STAT_0_CS_NI2_MASK                   (0x1U)
#define FSB_STAT_0_CS_NI2_SHIFT                  (0U)
/*! CS_NI2 - niden [2] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_NI2(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_NI2_SHIFT)) & FSB_STAT_0_CS_NI2_MASK)

#define FSB_STAT_0_CS_DB2_MASK                   (0x2U)
#define FSB_STAT_0_CS_DB2_SHIFT                  (1U)
/*! CS_DB2 - dbgen [2] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_DB2(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_DB2_SHIFT)) & FSB_STAT_0_CS_DB2_MASK)

#define FSB_STAT_0_CS_HN3_MASK                   (0x4U)
#define FSB_STAT_0_CS_HN3_SHIFT                  (2U)
/*! CS_HN3 - hniden [3] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_HN3(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_HN3_SHIFT)) & FSB_STAT_0_CS_HN3_MASK)

#define FSB_STAT_0_CS_HD3_MASK                   (0x8U)
#define FSB_STAT_0_CS_HD3_SHIFT                  (3U)
/*! CS_HD3 - hiden [3] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_HD3(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_HD3_SHIFT)) & FSB_STAT_0_CS_HD3_MASK)

#define FSB_STAT_0_CS_SN3_MASK                   (0x10U)
#define FSB_STAT_0_CS_SN3_SHIFT                  (4U)
/*! CS_SN3 - spniden [3] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_SN3(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_SN3_SHIFT)) & FSB_STAT_0_CS_SN3_MASK)

#define FSB_STAT_0_CS_SP3_MASK                   (0x20U)
#define FSB_STAT_0_CS_SP3_SHIFT                  (5U)
/*! CS_SP3 - spiden [3] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_SP3(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_SP3_SHIFT)) & FSB_STAT_0_CS_SP3_MASK)

#define FSB_STAT_0_CS_NI3_MASK                   (0x40U)
#define FSB_STAT_0_CS_NI3_SHIFT                  (6U)
/*! CS_NI3 - niden [3] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_NI3(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_NI3_SHIFT)) & FSB_STAT_0_CS_NI3_MASK)

#define FSB_STAT_0_CS_DB3_MASK                   (0x80U)
#define FSB_STAT_0_CS_DB3_SHIFT                  (7U)
/*! CS_DB3 - dbgen [3] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_DB3(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_DB3_SHIFT)) & FSB_STAT_0_CS_DB3_MASK)

#define FSB_STAT_0_CS_HN4_MASK                   (0x100U)
#define FSB_STAT_0_CS_HN4_SHIFT                  (8U)
/*! CS_HN4 - hniden [4] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_HN4(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_HN4_SHIFT)) & FSB_STAT_0_CS_HN4_MASK)

#define FSB_STAT_0_CS_HD4_MASK                   (0x200U)
#define FSB_STAT_0_CS_HD4_SHIFT                  (9U)
/*! CS_HD4 - hiden [4] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_HD4(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_HD4_SHIFT)) & FSB_STAT_0_CS_HD4_MASK)

#define FSB_STAT_0_CS_SN4_MASK                   (0x400U)
#define FSB_STAT_0_CS_SN4_SHIFT                  (10U)
/*! CS_SN4 - spniden [4] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_SN4(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_SN4_SHIFT)) & FSB_STAT_0_CS_SN4_MASK)

#define FSB_STAT_0_CS_SP4_MASK                   (0x800U)
#define FSB_STAT_0_CS_SP4_SHIFT                  (11U)
/*! CS_SP4 - spiden [4] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_SP4(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_SP4_SHIFT)) & FSB_STAT_0_CS_SP4_MASK)

#define FSB_STAT_0_CS_NI4_MASK                   (0x1000U)
#define FSB_STAT_0_CS_NI4_SHIFT                  (12U)
/*! CS_NI4 - niden [4] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_NI4(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_NI4_SHIFT)) & FSB_STAT_0_CS_NI4_MASK)

#define FSB_STAT_0_CS_DB4_MASK                   (0x2000U)
#define FSB_STAT_0_CS_DB4_SHIFT                  (13U)
/*! CS_DB4 - dbgen [4] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_DB4(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_DB4_SHIFT)) & FSB_STAT_0_CS_DB4_MASK)

#define FSB_STAT_0_CS_HN5_MASK                   (0x4000U)
#define FSB_STAT_0_CS_HN5_SHIFT                  (14U)
/*! CS_HN5 - hniden [5] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_HN5(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_HN5_SHIFT)) & FSB_STAT_0_CS_HN5_MASK)

#define FSB_STAT_0_CS_HD5_MASK                   (0x8000U)
#define FSB_STAT_0_CS_HD5_SHIFT                  (15U)
/*! CS_HD5 - hiden [5] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_HD5(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_HD5_SHIFT)) & FSB_STAT_0_CS_HD5_MASK)

#define FSB_STAT_0_CS_SN5_MASK                   (0x10000U)
#define FSB_STAT_0_CS_SN5_SHIFT                  (16U)
/*! CS_SN5 - spniden [5] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_SN5(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_SN5_SHIFT)) & FSB_STAT_0_CS_SN5_MASK)

#define FSB_STAT_0_CS_SP5_MASK                   (0x20000U)
#define FSB_STAT_0_CS_SP5_SHIFT                  (17U)
/*! CS_SP5 - spiden [5] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_SP5(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_SP5_SHIFT)) & FSB_STAT_0_CS_SP5_MASK)

#define FSB_STAT_0_CS_NI5_MASK                   (0x40000U)
#define FSB_STAT_0_CS_NI5_SHIFT                  (18U)
/*! CS_NI5 - niden [5] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_NI5(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_NI5_SHIFT)) & FSB_STAT_0_CS_NI5_MASK)

#define FSB_STAT_0_CS_DB5_MASK                   (0x80000U)
#define FSB_STAT_0_CS_DB5_SHIFT                  (19U)
/*! CS_DB5 - dbgen [5] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_DB5(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_DB5_SHIFT)) & FSB_STAT_0_CS_DB5_MASK)

#define FSB_STAT_0_CS_HN6_MASK                   (0x100000U)
#define FSB_STAT_0_CS_HN6_SHIFT                  (20U)
/*! CS_HN6 - hniden [6] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_HN6(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_HN6_SHIFT)) & FSB_STAT_0_CS_HN6_MASK)

#define FSB_STAT_0_CS_HD6_MASK                   (0x200000U)
#define FSB_STAT_0_CS_HD6_SHIFT                  (21U)
/*! CS_HD6 - hiden [6] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_HD6(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_HD6_SHIFT)) & FSB_STAT_0_CS_HD6_MASK)

#define FSB_STAT_0_CS_SN6_MASK                   (0x400000U)
#define FSB_STAT_0_CS_SN6_SHIFT                  (22U)
/*! CS_SN6 - spniden [6] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_SN6(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_SN6_SHIFT)) & FSB_STAT_0_CS_SN6_MASK)

#define FSB_STAT_0_CS_SP6_MASK                   (0x800000U)
#define FSB_STAT_0_CS_SP6_SHIFT                  (23U)
/*! CS_SP6 - spiden [6] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_SP6(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_SP6_SHIFT)) & FSB_STAT_0_CS_SP6_MASK)

#define FSB_STAT_0_CS_NI6_MASK                   (0x1000000U)
#define FSB_STAT_0_CS_NI6_SHIFT                  (24U)
/*! CS_NI6 - niden [6] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_NI6(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_NI6_SHIFT)) & FSB_STAT_0_CS_NI6_MASK)

#define FSB_STAT_0_CS_DB6_MASK                   (0x2000000U)
#define FSB_STAT_0_CS_DB6_SHIFT                  (25U)
/*! CS_DB6 - dbgen [6] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_DB6(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_DB6_SHIFT)) & FSB_STAT_0_CS_DB6_MASK)

#define FSB_STAT_0_CS_HN7_MASK                   (0x4000000U)
#define FSB_STAT_0_CS_HN7_SHIFT                  (26U)
/*! CS_HN7 - hniden [7] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_HN7(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_HN7_SHIFT)) & FSB_STAT_0_CS_HN7_MASK)

#define FSB_STAT_0_CS_HD7_MASK                   (0x8000000U)
#define FSB_STAT_0_CS_HD7_SHIFT                  (27U)
/*! CS_HD7 - hiden [7] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_HD7(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_HD7_SHIFT)) & FSB_STAT_0_CS_HD7_MASK)

#define FSB_STAT_0_CS_SN7_MASK                   (0x10000000U)
#define FSB_STAT_0_CS_SN7_SHIFT                  (28U)
/*! CS_SN7 - spniden [7] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_SN7(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_SN7_SHIFT)) & FSB_STAT_0_CS_SN7_MASK)

#define FSB_STAT_0_CS_SP7_MASK                   (0x20000000U)
#define FSB_STAT_0_CS_SP7_SHIFT                  (29U)
/*! CS_SP7 - spiden [7] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_SP7(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_SP7_SHIFT)) & FSB_STAT_0_CS_SP7_MASK)

#define FSB_STAT_0_CS_NI7_MASK                   (0x40000000U)
#define FSB_STAT_0_CS_NI7_SHIFT                  (30U)
/*! CS_NI7 - niden [7] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_NI7(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_NI7_SHIFT)) & FSB_STAT_0_CS_NI7_MASK)

#define FSB_STAT_0_CS_DB7_MASK                   (0x80000000U)
#define FSB_STAT_0_CS_DB7_SHIFT                  (31U)
/*! CS_DB7 - dbgen [7] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_0_CS_DB7(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_0_CS_DB7_SHIFT)) & FSB_STAT_0_CS_DB7_MASK)
/*! @} */

/*! @name STAT_1 - Status Register 1 */
/*! @{ */

#define FSB_STAT_1_SOC_ACD_MASK                  (0x1000U)
#define FSB_STAT_1_SOC_ACD_SHIFT                 (12U)
/*! SOC_ACD - ARM Crypto Disable (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_SOC_ACD(x)                    (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_SOC_ACD_SHIFT)) & FSB_STAT_1_SOC_ACD_MASK)

#define FSB_STAT_1_SOC_ABTCM_MASK                (0x2000U)
#define FSB_STAT_1_SOC_ABTCM_SHIFT               (13U)
/*! SOC_ABTCM - Allow Host Boot TCM (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_SOC_ABTCM(x)                  (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_SOC_ABTCM_SHIFT)) & FSB_STAT_1_SOC_ABTCM_MASK)

#define FSB_STAT_1_SOC_BTCMW_MASK                (0x4000U)
#define FSB_STAT_1_SOC_BTCMW_SHIFT               (14U)
/*! SOC_BTCMW - Block TCM Writes (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_SOC_BTCMW(x)                  (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_SOC_BTCMW_SHIFT)) & FSB_STAT_1_SOC_BTCMW_MASK)

#define FSB_STAT_1_CS_HN0_MASK                   (0x10000U)
#define FSB_STAT_1_CS_HN0_SHIFT                  (16U)
/*! CS_HN0 - hniden [0] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_HN0(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_HN0_SHIFT)) & FSB_STAT_1_CS_HN0_MASK)

#define FSB_STAT_1_CS_HD0_MASK                   (0x20000U)
#define FSB_STAT_1_CS_HD0_SHIFT                  (17U)
/*! CS_HD0 - hiden [0] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_HD0(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_HD0_SHIFT)) & FSB_STAT_1_CS_HD0_MASK)

#define FSB_STAT_1_CS_SN0_MASK                   (0x40000U)
#define FSB_STAT_1_CS_SN0_SHIFT                  (18U)
/*! CS_SN0 - spniden [0] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_SN0(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_SN0_SHIFT)) & FSB_STAT_1_CS_SN0_MASK)

#define FSB_STAT_1_CS_SP0_MASK                   (0x80000U)
#define FSB_STAT_1_CS_SP0_SHIFT                  (19U)
/*! CS_SP0 - spiden [0] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_SP0(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_SP0_SHIFT)) & FSB_STAT_1_CS_SP0_MASK)

#define FSB_STAT_1_CS_NI0_MASK                   (0x100000U)
#define FSB_STAT_1_CS_NI0_SHIFT                  (20U)
/*! CS_NI0 - niden [0] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_NI0(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_NI0_SHIFT)) & FSB_STAT_1_CS_NI0_MASK)

#define FSB_STAT_1_CS_DB0_MASK                   (0x200000U)
#define FSB_STAT_1_CS_DB0_SHIFT                  (21U)
/*! CS_DB0 - dbgen [0] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_DB0(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_DB0_SHIFT)) & FSB_STAT_1_CS_DB0_MASK)

#define FSB_STAT_1_CS_HN1_MASK                   (0x400000U)
#define FSB_STAT_1_CS_HN1_SHIFT                  (22U)
/*! CS_HN1 - hniden [1] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_HN1(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_HN1_SHIFT)) & FSB_STAT_1_CS_HN1_MASK)

#define FSB_STAT_1_CS_HD1_MASK                   (0x800000U)
#define FSB_STAT_1_CS_HD1_SHIFT                  (23U)
/*! CS_HD1 - hiden [1] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_HD1(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_HD1_SHIFT)) & FSB_STAT_1_CS_HD1_MASK)

#define FSB_STAT_1_CS_SN1_MASK                   (0x1000000U)
#define FSB_STAT_1_CS_SN1_SHIFT                  (24U)
/*! CS_SN1 - spniden [1] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_SN1(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_SN1_SHIFT)) & FSB_STAT_1_CS_SN1_MASK)

#define FSB_STAT_1_CS_SP1_MASK                   (0x2000000U)
#define FSB_STAT_1_CS_SP1_SHIFT                  (25U)
/*! CS_SP1 - spiden [1] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_SP1(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_SP1_SHIFT)) & FSB_STAT_1_CS_SP1_MASK)

#define FSB_STAT_1_CS_NI1_MASK                   (0x4000000U)
#define FSB_STAT_1_CS_NI1_SHIFT                  (26U)
/*! CS_NI1 - niden [1] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_NI1(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_NI1_SHIFT)) & FSB_STAT_1_CS_NI1_MASK)

#define FSB_STAT_1_CS_DB1_MASK                   (0x8000000U)
#define FSB_STAT_1_CS_DB1_SHIFT                  (27U)
/*! CS_DB1 - dbgen [1] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_DB1(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_DB1_SHIFT)) & FSB_STAT_1_CS_DB1_MASK)

#define FSB_STAT_1_CS_HN2_MASK                   (0x10000000U)
#define FSB_STAT_1_CS_HN2_SHIFT                  (28U)
/*! CS_HN2 - hniden [2] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_HN2(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_HN2_SHIFT)) & FSB_STAT_1_CS_HN2_MASK)

#define FSB_STAT_1_CS_HD2_MASK                   (0x20000000U)
#define FSB_STAT_1_CS_HD2_SHIFT                  (29U)
/*! CS_HD2 - hiden [2] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_HD2(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_HD2_SHIFT)) & FSB_STAT_1_CS_HD2_MASK)

#define FSB_STAT_1_CS_SN2_MASK                   (0x40000000U)
#define FSB_STAT_1_CS_SN2_SHIFT                  (30U)
/*! CS_SN2 - spniden [2] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_SN2(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_SN2_SHIFT)) & FSB_STAT_1_CS_SN2_MASK)

#define FSB_STAT_1_CS_SP2_MASK                   (0x80000000U)
#define FSB_STAT_1_CS_SP2_SHIFT                  (31U)
/*! CS_SP2 - spiden [2] (NXP or OEM custody LC or allowed by ELE programming) */
#define FSB_STAT_1_CS_SP2(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_1_CS_SP2_SHIFT)) & FSB_STAT_1_CS_SP2_MASK)
/*! @} */

/*! @name STAT_5 - Status Register 5 */
/*! @{ */

#define FSB_STAT_5_LC_BLANK_MASK                 (0x1U)
#define FSB_STAT_5_LC_BLANK_SHIFT                (0U)
/*! LC_BLANK - Lifecycle is in BLANK */
#define FSB_STAT_5_LC_BLANK(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_LC_BLANK_SHIFT)) & FSB_STAT_5_LC_BLANK_MASK)

#define FSB_STAT_5_LC_FAB_DEFAULT_MASK           (0x2U)
#define FSB_STAT_5_LC_FAB_DEFAULT_SHIFT          (1U)
/*! LC_FAB_DEFAULT - In Lifecycle FAB with minimal fuse programming complete */
#define FSB_STAT_5_LC_FAB_DEFAULT(x)             (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_LC_FAB_DEFAULT_SHIFT)) & FSB_STAT_5_LC_FAB_DEFAULT_MASK)

#define FSB_STAT_5_LC_FAB_MASK                   (0x4U)
#define FSB_STAT_5_LC_FAB_SHIFT                  (2U)
/*! LC_FAB - In Lifecycle FAB with more than minimal fuse programming complete */
#define FSB_STAT_5_LC_FAB(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_LC_FAB_SHIFT)) & FSB_STAT_5_LC_FAB_MASK)

#define FSB_STAT_5_LC_PROV_MASK                  (0x8U)
#define FSB_STAT_5_LC_PROV_SHIFT                 (3U)
/*! LC_PROV - Lifecycle is in NXP Provisioned */
#define FSB_STAT_5_LC_PROV(x)                    (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_LC_PROV_SHIFT)) & FSB_STAT_5_LC_PROV_MASK)

#define FSB_STAT_5_LC_OEM_OPEN_MASK              (0x10U)
#define FSB_STAT_5_LC_OEM_OPEN_SHIFT             (4U)
/*! LC_OEM_OPEN - Lifecycle is in OEM_OPEN */
#define FSB_STAT_5_LC_OEM_OPEN(x)                (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_LC_OEM_OPEN_SHIFT)) & FSB_STAT_5_LC_OEM_OPEN_MASK)

#define FSB_STAT_5_LC_OEM_SWC_MASK               (0x20U)
#define FSB_STAT_5_LC_OEM_SWC_SHIFT              (5U)
/*! LC_OEM_SWC - Lifecycle is in OEM-Secure-World-Closed */
#define FSB_STAT_5_LC_OEM_SWC(x)                 (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_LC_OEM_SWC_SHIFT)) & FSB_STAT_5_LC_OEM_SWC_MASK)

#define FSB_STAT_5_LC_OEM_CLSD_MASK              (0x40U)
#define FSB_STAT_5_LC_OEM_CLSD_SHIFT             (6U)
/*! LC_OEM_CLSD - Lifecycle is in OEM_CLOSED */
#define FSB_STAT_5_LC_OEM_CLSD(x)                (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_LC_OEM_CLSD_SHIFT)) & FSB_STAT_5_LC_OEM_CLSD_MASK)

#define FSB_STAT_5_LC_OEM_LCKD_MASK              (0x80U)
#define FSB_STAT_5_LC_OEM_LCKD_SHIFT             (7U)
/*! LC_OEM_LCKD - Lifecycle is in OEM_LOCKED */
#define FSB_STAT_5_LC_OEM_LCKD(x)                (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_LC_OEM_LCKD_SHIFT)) & FSB_STAT_5_LC_OEM_LCKD_MASK)

#define FSB_STAT_5_LC_FRO_MASK                   (0x100U)
#define FSB_STAT_5_LC_FRO_SHIFT                  (8U)
/*! LC_FRO - Lifecycle is in Field Return OEM */
#define FSB_STAT_5_LC_FRO(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_LC_FRO_SHIFT)) & FSB_STAT_5_LC_FRO_MASK)

#define FSB_STAT_5_LC_FRN_MASK                   (0x200U)
#define FSB_STAT_5_LC_FRN_SHIFT                  (9U)
/*! LC_FRN - Lifecycle is in Field Return NXP */
#define FSB_STAT_5_LC_FRN(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_LC_FRN_SHIFT)) & FSB_STAT_5_LC_FRN_MASK)

#define FSB_STAT_5_LC_BRICKED_MASK               (0x400U)
#define FSB_STAT_5_LC_BRICKED_SHIFT              (10U)
/*! LC_BRICKED - Lifecycle is in BRICKED */
#define FSB_STAT_5_LC_BRICKED(x)                 (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_LC_BRICKED_SHIFT)) & FSB_STAT_5_LC_BRICKED_MASK)

#define FSB_STAT_5_ST_AFV_MASK                   (0x800U)
#define FSB_STAT_5_ST_AFV_SHIFT                  (11U)
/*! ST_AFV - All Fuses Valid signal is asserted */
#define FSB_STAT_5_ST_AFV(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_ST_AFV_SHIFT)) & FSB_STAT_5_ST_AFV_MASK)

#define FSB_STAT_5_ST_EFV_MASK                   (0x1000U)
#define FSB_STAT_5_ST_EFV_SHIFT                  (12U)
/*! ST_EFV - Early Fuses Valid signal is asserted */
#define FSB_STAT_5_ST_EFV(x)                     (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_ST_EFV_SHIFT)) & FSB_STAT_5_ST_EFV_MASK)

#define FSB_STAT_5_ST_LC_CONF_MASK               (0x2000U)
#define FSB_STAT_5_ST_LC_CONF_SHIFT              (13U)
/*! ST_LC_CONF - Lifecycle is Confirmed */
#define FSB_STAT_5_ST_LC_CONF(x)                 (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_ST_LC_CONF_SHIFT)) & FSB_STAT_5_ST_LC_CONF_MASK)

#define FSB_STAT_5_ST_LC_MISMATCHED_MASK         (0x4000U)
#define FSB_STAT_5_ST_LC_MISMATCHED_SHIFT        (14U)
/*! ST_LC_MISMATCHED - Lifecycle is undetermined due to a mismatch */
#define FSB_STAT_5_ST_LC_MISMATCHED(x)           (((uint32_t)(((uint32_t)(x)) << FSB_STAT_5_ST_LC_MISMATCHED_SHIFT)) & FSB_STAT_5_ST_LC_MISMATCHED_MASK)
/*! @} */

/*! @name STAT_6 - Status Register 6 */
/*! @{ */

#define FSB_STAT_6_ELE_VER_L_MASK                (0xFFFFFFFFU)
#define FSB_STAT_6_ELE_VER_L_SHIFT               (0U)
/*! ELE_VER_L - ELE RTL Config Register */
#define FSB_STAT_6_ELE_VER_L(x)                  (((uint32_t)(((uint32_t)(x)) << FSB_STAT_6_ELE_VER_L_SHIFT)) & FSB_STAT_6_ELE_VER_L_MASK)
/*! @} */

/*! @name STAT_7 - Status Register 7 */
/*! @{ */

#define FSB_STAT_7_ELE_VER_H_MASK                (0xFFFFFFFFU)
#define FSB_STAT_7_ELE_VER_H_SHIFT               (0U)
/*! ELE_VER_H - ELE RTL Version ID Register */
#define FSB_STAT_7_ELE_VER_H(x)                  (((uint32_t)(((uint32_t)(x)) << FSB_STAT_7_ELE_VER_H_SHIFT)) & FSB_STAT_7_ELE_VER_H_MASK)
/*! @} */

/*! @name TROUT_STATUS_0 - TROUT Status */
/*! @{ */

#define FSB_TROUT_STATUS_0_TROUT_0_MASK          (0xFU)
#define FSB_TROUT_STATUS_0_TROUT_0_SHIFT         (0U)
/*! TROUT_0 - TROUT status */
#define FSB_TROUT_STATUS_0_TROUT_0(x)            (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_0_TROUT_0_SHIFT)) & FSB_TROUT_STATUS_0_TROUT_0_MASK)

#define FSB_TROUT_STATUS_0_TROUT_1_MASK          (0xF0U)
#define FSB_TROUT_STATUS_0_TROUT_1_SHIFT         (4U)
/*! TROUT_1 - TROUT status */
#define FSB_TROUT_STATUS_0_TROUT_1(x)            (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_0_TROUT_1_SHIFT)) & FSB_TROUT_STATUS_0_TROUT_1_MASK)

#define FSB_TROUT_STATUS_0_TROUT_2_MASK          (0xF00U)
#define FSB_TROUT_STATUS_0_TROUT_2_SHIFT         (8U)
/*! TROUT_2 - TROUT status */
#define FSB_TROUT_STATUS_0_TROUT_2(x)            (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_0_TROUT_2_SHIFT)) & FSB_TROUT_STATUS_0_TROUT_2_MASK)

#define FSB_TROUT_STATUS_0_TROUT_3_MASK          (0xF000U)
#define FSB_TROUT_STATUS_0_TROUT_3_SHIFT         (12U)
/*! TROUT_3 - TROUT status */
#define FSB_TROUT_STATUS_0_TROUT_3(x)            (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_0_TROUT_3_SHIFT)) & FSB_TROUT_STATUS_0_TROUT_3_MASK)

#define FSB_TROUT_STATUS_0_TROUT_4_MASK          (0xF0000U)
#define FSB_TROUT_STATUS_0_TROUT_4_SHIFT         (16U)
/*! TROUT_4 - TROUT status */
#define FSB_TROUT_STATUS_0_TROUT_4(x)            (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_0_TROUT_4_SHIFT)) & FSB_TROUT_STATUS_0_TROUT_4_MASK)

#define FSB_TROUT_STATUS_0_TROUT_5_MASK          (0xF00000U)
#define FSB_TROUT_STATUS_0_TROUT_5_SHIFT         (20U)
/*! TROUT_5 - TROUT status */
#define FSB_TROUT_STATUS_0_TROUT_5(x)            (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_0_TROUT_5_SHIFT)) & FSB_TROUT_STATUS_0_TROUT_5_MASK)

#define FSB_TROUT_STATUS_0_TROUT_6_MASK          (0xF000000U)
#define FSB_TROUT_STATUS_0_TROUT_6_SHIFT         (24U)
/*! TROUT_6 - TROUT status */
#define FSB_TROUT_STATUS_0_TROUT_6(x)            (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_0_TROUT_6_SHIFT)) & FSB_TROUT_STATUS_0_TROUT_6_MASK)

#define FSB_TROUT_STATUS_0_TROUT_7_MASK          (0xF0000000U)
#define FSB_TROUT_STATUS_0_TROUT_7_SHIFT         (28U)
/*! TROUT_7 - TROUT status */
#define FSB_TROUT_STATUS_0_TROUT_7(x)            (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_0_TROUT_7_SHIFT)) & FSB_TROUT_STATUS_0_TROUT_7_MASK)
/*! @} */

/*! @name TROUT_STATUS_1 - TROUT Status */
/*! @{ */

#define FSB_TROUT_STATUS_1_TROUT_8_MASK          (0xFU)
#define FSB_TROUT_STATUS_1_TROUT_8_SHIFT         (0U)
/*! TROUT_8 - TROUT status */
#define FSB_TROUT_STATUS_1_TROUT_8(x)            (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_1_TROUT_8_SHIFT)) & FSB_TROUT_STATUS_1_TROUT_8_MASK)

#define FSB_TROUT_STATUS_1_TROUT_9_MASK          (0xF0U)
#define FSB_TROUT_STATUS_1_TROUT_9_SHIFT         (4U)
/*! TROUT_9 - TROUT status */
#define FSB_TROUT_STATUS_1_TROUT_9(x)            (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_1_TROUT_9_SHIFT)) & FSB_TROUT_STATUS_1_TROUT_9_MASK)

#define FSB_TROUT_STATUS_1_TROUT_10_MASK         (0xF00U)
#define FSB_TROUT_STATUS_1_TROUT_10_SHIFT        (8U)
/*! TROUT_10 - TROUT status */
#define FSB_TROUT_STATUS_1_TROUT_10(x)           (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_1_TROUT_10_SHIFT)) & FSB_TROUT_STATUS_1_TROUT_10_MASK)

#define FSB_TROUT_STATUS_1_TROUT_11_MASK         (0xF000U)
#define FSB_TROUT_STATUS_1_TROUT_11_SHIFT        (12U)
/*! TROUT_11 - TROUT status */
#define FSB_TROUT_STATUS_1_TROUT_11(x)           (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_1_TROUT_11_SHIFT)) & FSB_TROUT_STATUS_1_TROUT_11_MASK)

#define FSB_TROUT_STATUS_1_TROUT_12_MASK         (0xF0000U)
#define FSB_TROUT_STATUS_1_TROUT_12_SHIFT        (16U)
/*! TROUT_12 - TROUT status */
#define FSB_TROUT_STATUS_1_TROUT_12(x)           (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_1_TROUT_12_SHIFT)) & FSB_TROUT_STATUS_1_TROUT_12_MASK)

#define FSB_TROUT_STATUS_1_TROUT_13_MASK         (0xF00000U)
#define FSB_TROUT_STATUS_1_TROUT_13_SHIFT        (20U)
/*! TROUT_13 - TROUT status */
#define FSB_TROUT_STATUS_1_TROUT_13(x)           (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_1_TROUT_13_SHIFT)) & FSB_TROUT_STATUS_1_TROUT_13_MASK)

#define FSB_TROUT_STATUS_1_TROUT_14_MASK         (0xF000000U)
#define FSB_TROUT_STATUS_1_TROUT_14_SHIFT        (24U)
/*! TROUT_14 - TROUT status */
#define FSB_TROUT_STATUS_1_TROUT_14(x)           (((uint32_t)(((uint32_t)(x)) << FSB_TROUT_STATUS_1_TROUT_14_SHIFT)) & FSB_TROUT_STATUS_1_TROUT_14_MASK)
/*! @} */

/*! @name FUSE_STAT - Fuse Status Register */
/*! @{ */

#define FSB_FUSE_STAT_FUSE_ADDR_MASK             (0xFFFFU)
#define FSB_FUSE_STAT_FUSE_ADDR_SHIFT            (0U)
/*! FUSE_ADDR - Fuse address */
#define FSB_FUSE_STAT_FUSE_ADDR(x)               (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_FUSE_ADDR_SHIFT)) & FSB_FUSE_STAT_FUSE_ADDR_MASK)

#define FSB_FUSE_STAT_SHDW_ZERO_MASK             (0x1000000U)
#define FSB_FUSE_STAT_SHDW_ZERO_SHIFT            (24U)
/*! SHDW_ZERO - Shadow zeroized */
#define FSB_FUSE_STAT_SHDW_ZERO(x)               (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_SHDW_ZERO_SHIFT)) & FSB_FUSE_STAT_SHDW_ZERO_MASK)

#define FSB_FUSE_STAT_SHDW_UNPROG_MASK           (0x2000000U)
#define FSB_FUSE_STAT_SHDW_UNPROG_SHIFT          (25U)
/*! SHDW_UNPROG - Shadow unprogrammed */
#define FSB_FUSE_STAT_SHDW_UNPROG(x)             (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_SHDW_UNPROG_SHIFT)) & FSB_FUSE_STAT_SHDW_UNPROG_MASK)

#define FSB_FUSE_STAT_FUSE_ERR_MASK              (0x4000000U)
#define FSB_FUSE_STAT_FUSE_ERR_SHIFT             (26U)
/*! FUSE_ERR - Fuse error */
#define FSB_FUSE_STAT_FUSE_ERR(x)                (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_FUSE_ERR_SHIFT)) & FSB_FUSE_STAT_FUSE_ERR_MASK)

#define FSB_FUSE_STAT_LOADING_MASK               (0x8000000U)
#define FSB_FUSE_STAT_LOADING_SHIFT              (27U)
/*! LOADING - Shadow loading */
#define FSB_FUSE_STAT_LOADING(x)                 (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_LOADING_SHIFT)) & FSB_FUSE_STAT_LOADING_MASK)

#define FSB_FUSE_STAT_RLD_ERR_MASK               (0x10000000U)
#define FSB_FUSE_STAT_RLD_ERR_SHIFT              (28U)
/*! RLD_ERR - Reload error */
#define FSB_FUSE_STAT_RLD_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_RLD_ERR_SHIFT)) & FSB_FUSE_STAT_RLD_ERR_MASK)

#define FSB_FUSE_STAT_RD_ERR_MASK                (0x20000000U)
#define FSB_FUSE_STAT_RD_ERR_SHIFT               (29U)
/*! RD_ERR - Read error */
#define FSB_FUSE_STAT_RD_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_RD_ERR_SHIFT)) & FSB_FUSE_STAT_RD_ERR_MASK)

#define FSB_FUSE_STAT_WR_ERR_MASK                (0x40000000U)
#define FSB_FUSE_STAT_WR_ERR_SHIFT               (30U)
/*! WR_ERR - Write Error */
#define FSB_FUSE_STAT_WR_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_WR_ERR_SHIFT)) & FSB_FUSE_STAT_WR_ERR_MASK)

#define FSB_FUSE_STAT_ADDR_ERR_MASK              (0x80000000U)
#define FSB_FUSE_STAT_ADDR_ERR_SHIFT             (31U)
/*! ADDR_ERR - Address error */
#define FSB_FUSE_STAT_ADDR_ERR(x)                (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_ADDR_ERR_SHIFT)) & FSB_FUSE_STAT_ADDR_ERR_MASK)
/*! @} */

/*! @name FUSE_EVNT - Fuse Event Register */
/*! @{ */

#define FSB_FUSE_EVNT_SHDW_ZERO_MASK             (0x1000000U)
#define FSB_FUSE_EVNT_SHDW_ZERO_SHIFT            (24U)
/*! SHDW_ZERO - Shadow zeroized */
#define FSB_FUSE_EVNT_SHDW_ZERO(x)               (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_SHDW_ZERO_SHIFT)) & FSB_FUSE_EVNT_SHDW_ZERO_MASK)

#define FSB_FUSE_EVNT_SHDW_UNPROG_MASK           (0x2000000U)
#define FSB_FUSE_EVNT_SHDW_UNPROG_SHIFT          (25U)
/*! SHDW_UNPROG - Shadow unprogrammed */
#define FSB_FUSE_EVNT_SHDW_UNPROG(x)             (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_SHDW_UNPROG_SHIFT)) & FSB_FUSE_EVNT_SHDW_UNPROG_MASK)

#define FSB_FUSE_EVNT_FUSE_ERR_MASK              (0x4000000U)
#define FSB_FUSE_EVNT_FUSE_ERR_SHIFT             (26U)
/*! FUSE_ERR - Fuse error */
#define FSB_FUSE_EVNT_FUSE_ERR(x)                (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_FUSE_ERR_SHIFT)) & FSB_FUSE_EVNT_FUSE_ERR_MASK)

#define FSB_FUSE_EVNT_LOADING_MASK               (0x8000000U)
#define FSB_FUSE_EVNT_LOADING_SHIFT              (27U)
/*! LOADING - Shadow loading */
#define FSB_FUSE_EVNT_LOADING(x)                 (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_LOADING_SHIFT)) & FSB_FUSE_EVNT_LOADING_MASK)

#define FSB_FUSE_EVNT_RLD_ERR_MASK               (0x10000000U)
#define FSB_FUSE_EVNT_RLD_ERR_SHIFT              (28U)
/*! RLD_ERR - Reload error */
#define FSB_FUSE_EVNT_RLD_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_RLD_ERR_SHIFT)) & FSB_FUSE_EVNT_RLD_ERR_MASK)

#define FSB_FUSE_EVNT_RD_ERR_MASK                (0x20000000U)
#define FSB_FUSE_EVNT_RD_ERR_SHIFT               (29U)
/*! RD_ERR - Read error */
#define FSB_FUSE_EVNT_RD_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_RD_ERR_SHIFT)) & FSB_FUSE_EVNT_RD_ERR_MASK)

#define FSB_FUSE_EVNT_WR_ERR_MASK                (0x40000000U)
#define FSB_FUSE_EVNT_WR_ERR_SHIFT               (30U)
/*! WR_ERR - Write Error */
#define FSB_FUSE_EVNT_WR_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_WR_ERR_SHIFT)) & FSB_FUSE_EVNT_WR_ERR_MASK)

#define FSB_FUSE_EVNT_ADDR_ERR_MASK              (0x80000000U)
#define FSB_FUSE_EVNT_ADDR_ERR_SHIFT             (31U)
/*! ADDR_ERR - Address error */
#define FSB_FUSE_EVNT_ADDR_ERR(x)                (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_ADDR_ERR_SHIFT)) & FSB_FUSE_EVNT_ADDR_ERR_MASK)
/*! @} */

/*! @name FUSE_INT_EN - Fuse Interrupt Enable Register */
/*! @{ */

#define FSB_FUSE_INT_EN_INT_EN_MASK              (0xFF000000U)
#define FSB_FUSE_INT_EN_INT_EN_SHIFT             (24U)
/*! INT_EN - Interrupt Enables */
#define FSB_FUSE_INT_EN_INT_EN(x)                (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_INT_EN_INT_EN_SHIFT)) & FSB_FUSE_INT_EN_INT_EN_MASK)
/*! @} */

/*! @name FUSE_INT - Fuse Interrupt Register */
/*! @{ */

#define FSB_FUSE_INT_INT_MASK                    (0xFF000000U)
#define FSB_FUSE_INT_INT_SHIFT                   (24U)
/*! INT - Interrupts */
#define FSB_FUSE_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_INT_INT_SHIFT)) & FSB_FUSE_INT_INT_MASK)
/*! @} */

/*! @name FUSE - Fuse Value Registers */
/*! @{ */

#define FSB_FUSE_FUSE_MASK                       (0xFFFFFFFFU)
#define FSB_FUSE_FUSE_SHIFT                      (0U)
/*! FUSE - Fuse Values */
#define FSB_FUSE_FUSE(x)                         (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_FUSE_SHIFT)) & FSB_FUSE_FUSE_MASK)
/*! @} */

/* The count of FSB_FUSE */
#define FSB_FUSE_COUNT                           (8192U)


/*!
 * @}
 */ /* end of group FSB_Register_Masks */


/*!
 * @}
 */ /* end of group FSB_Peripheral_Access_Layer */


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


#endif  /* PERI_FSB_H_ */

