/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AON_AXBS
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file AON_AXBS.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for AON_AXBS
 *
 * CMSIS Peripheral Access Layer for AON_AXBS
 */

#if !defined(AON_AXBS_H_)
#define AON_AXBS_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- AON_AXBS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_AXBS_Peripheral_Access_Layer AON_AXBS Peripheral Access Layer
 * @{
 */

/** AON_AXBS - Register Layout Typedef */
typedef struct {
  __IO uint32_t PRS0;                              /**< Priority Slave Registers, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t CRS0;                              /**< Control Register, offset: 0x10 */
       uint8_t RESERVED_1[236];
  __IO uint32_t PRS1;                              /**< Priority Slave Registers, offset: 0x100 */
       uint8_t RESERVED_2[12];
  __IO uint32_t CRS1;                              /**< Control Register, offset: 0x110 */
       uint8_t RESERVED_3[236];
  __IO uint32_t PRS2;                              /**< Priority Slave Registers, offset: 0x200 */
       uint8_t RESERVED_4[12];
  __IO uint32_t CRS2;                              /**< Control Register, offset: 0x210 */
       uint8_t RESERVED_5[236];
  __IO uint32_t PRS3;                              /**< Priority Slave Registers, offset: 0x300 */
       uint8_t RESERVED_6[12];
  __IO uint32_t CRS3;                              /**< Control Register, offset: 0x310 */
       uint8_t RESERVED_7[236];
  __IO uint32_t PRS4;                              /**< Priority Slave Registers, offset: 0x400 */
       uint8_t RESERVED_8[12];
  __IO uint32_t CRS4;                              /**< Control Register, offset: 0x410 */
       uint8_t RESERVED_9[236];
  __IO uint32_t PRS5;                              /**< Priority Slave Registers, offset: 0x500 */
       uint8_t RESERVED_10[12];
  __IO uint32_t CRS5;                              /**< Control Register, offset: 0x510 */
       uint8_t RESERVED_11[236];
  __IO uint32_t PRS6;                              /**< Priority Slave Registers, offset: 0x600 */
       uint8_t RESERVED_12[12];
  __IO uint32_t CRS6;                              /**< Control Register, offset: 0x610 */
       uint8_t RESERVED_13[236];
  __IO uint32_t PRS7;                              /**< Priority Slave Registers, offset: 0x700 */
       uint8_t RESERVED_14[12];
  __IO uint32_t CRS7;                              /**< Control Register, offset: 0x710 */
       uint8_t RESERVED_15[236];
  __IO uint32_t MGPCR0;                            /**< Master General Purpose Control Register, offset: 0x800 */
       uint8_t RESERVED_16[252];
  __IO uint32_t MGPCR1;                            /**< Master General Purpose Control Register, offset: 0x900 */
       uint8_t RESERVED_17[252];
  __IO uint32_t MGPCR2;                            /**< Master General Purpose Control Register, offset: 0xA00 */
       uint8_t RESERVED_18[252];
  __IO uint32_t MGPCR3;                            /**< Master General Purpose Control Register, offset: 0xB00 */
       uint8_t RESERVED_19[252];
  __IO uint32_t MGPCR4;                            /**< Master General Purpose Control Register, offset: 0xC00 */
       uint8_t RESERVED_20[252];
  __IO uint32_t MGPCR5;                            /**< Master General Purpose Control Register, offset: 0xD00 */
       uint8_t RESERVED_21[252];
  __IO uint32_t MGPCR6;                            /**< Master General Purpose Control Register, offset: 0xE00 */
       uint8_t RESERVED_22[252];
  __IO uint32_t MGPCR7;                            /**< Master General Purpose Control Register, offset: 0xF00 */
} AON_AXBS_Type;

/* ----------------------------------------------------------------------------
   -- AON_AXBS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_AXBS_Register_Masks AON_AXBS Register Masks
 * @{
 */

/*! @name PRS0 - Priority Slave Registers */
/*! @{ */

#define AON_AXBS_PRS0_M0_MASK                    (0x7U)
#define AON_AXBS_PRS0_M0_SHIFT                   (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or the lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS0_M0(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS0_M0_SHIFT)) & AON_AXBS_PRS0_M0_MASK)

#define AON_AXBS_PRS0_M1_MASK                    (0x70U)
#define AON_AXBS_PRS0_M1_SHIFT                   (4U)
/*! M1 - Master 1 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS0_M1(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS0_M1_SHIFT)) & AON_AXBS_PRS0_M1_MASK)

#define AON_AXBS_PRS0_M2_MASK                    (0x700U)
#define AON_AXBS_PRS0_M2_SHIFT                   (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS0_M2(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS0_M2_SHIFT)) & AON_AXBS_PRS0_M2_MASK)

#define AON_AXBS_PRS0_M3_MASK                    (0x7000U)
#define AON_AXBS_PRS0_M3_SHIFT                   (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS0_M3(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS0_M3_SHIFT)) & AON_AXBS_PRS0_M3_MASK)

#define AON_AXBS_PRS0_M4_MASK                    (0x70000U)
#define AON_AXBS_PRS0_M4_SHIFT                   (16U)
/*! M4 - Master 4 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS0_M4(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS0_M4_SHIFT)) & AON_AXBS_PRS0_M4_MASK)

#define AON_AXBS_PRS0_M5_MASK                    (0x700000U)
#define AON_AXBS_PRS0_M5_SHIFT                   (20U)
/*! M5 - Master 5 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS0_M5(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS0_M5_SHIFT)) & AON_AXBS_PRS0_M5_MASK)

#define AON_AXBS_PRS0_M6_MASK                    (0x7000000U)
#define AON_AXBS_PRS0_M6_SHIFT                   (24U)
/*! M6 - Master 6 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS0_M6(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS0_M6_SHIFT)) & AON_AXBS_PRS0_M6_MASK)

#define AON_AXBS_PRS0_M7_MASK                    (0x70000000U)
#define AON_AXBS_PRS0_M7_SHIFT                   (28U)
/*! M7 - Master 7 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS0_M7(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS0_M7_SHIFT)) & AON_AXBS_PRS0_M7_MASK)
/*! @} */

/*! @name CRS0 - Control Register */
/*! @{ */

#define AON_AXBS_CRS0_PARK_MASK                  (0x7U)
#define AON_AXBS_CRS0_PARK_SHIFT                 (0U)
/*! PARK - Park
 *  0b000..Park on master port M0
 *  0b001..Park on master port M1
 *  0b010..Park on master port M2
 *  0b011..Park on master port M3
 *  0b100..Park on master port M4
 *  0b101..Park on master port M5
 *  0b110..Park on master port M6
 *  0b111..Park on master port M7
 */
#define AON_AXBS_CRS0_PARK(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS0_PARK_SHIFT)) & AON_AXBS_CRS0_PARK_MASK)

#define AON_AXBS_CRS0_PCTL_MASK                  (0x30U)
#define AON_AXBS_CRS0_PCTL_SHIFT                 (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AON_AXBS_CRS0_PCTL(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS0_PCTL_SHIFT)) & AON_AXBS_CRS0_PCTL_MASK)

#define AON_AXBS_CRS0_ARB_MASK                   (0x300U)
#define AON_AXBS_CRS0_ARB_SHIFT                  (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AON_AXBS_CRS0_ARB(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS0_ARB_SHIFT)) & AON_AXBS_CRS0_ARB_MASK)

#define AON_AXBS_CRS0_HPE0_MASK                  (0x10000U)
#define AON_AXBS_CRS0_HPE0_SHIFT                 (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AON_AXBS_CRS0_HPE0(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS0_HPE0_SHIFT)) & AON_AXBS_CRS0_HPE0_MASK)

#define AON_AXBS_CRS0_HPE1_MASK                  (0x20000U)
#define AON_AXBS_CRS0_HPE1_SHIFT                 (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AON_AXBS_CRS0_HPE1(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS0_HPE1_SHIFT)) & AON_AXBS_CRS0_HPE1_MASK)

#define AON_AXBS_CRS0_HPE2_MASK                  (0x40000U)
#define AON_AXBS_CRS0_HPE2_SHIFT                 (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AON_AXBS_CRS0_HPE2(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS0_HPE2_SHIFT)) & AON_AXBS_CRS0_HPE2_MASK)

#define AON_AXBS_CRS0_HPE3_MASK                  (0x80000U)
#define AON_AXBS_CRS0_HPE3_SHIFT                 (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AON_AXBS_CRS0_HPE3(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS0_HPE3_SHIFT)) & AON_AXBS_CRS0_HPE3_MASK)

#define AON_AXBS_CRS0_HPE4_MASK                  (0x100000U)
#define AON_AXBS_CRS0_HPE4_SHIFT                 (20U)
/*! HPE4 - High Priority Elevation 4
 *  0b0..Master high-priority elevation for master 4. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 4. is enabled on this slave port.
 */
#define AON_AXBS_CRS0_HPE4(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS0_HPE4_SHIFT)) & AON_AXBS_CRS0_HPE4_MASK)

#define AON_AXBS_CRS0_HPE5_MASK                  (0x200000U)
#define AON_AXBS_CRS0_HPE5_SHIFT                 (21U)
/*! HPE5 - High Priority Elevation 5
 *  0b0..Master high-priority elevation for master 5. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 5. is enabled on this slave port.
 */
#define AON_AXBS_CRS0_HPE5(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS0_HPE5_SHIFT)) & AON_AXBS_CRS0_HPE5_MASK)

#define AON_AXBS_CRS0_HPE6_MASK                  (0x400000U)
#define AON_AXBS_CRS0_HPE6_SHIFT                 (22U)
/*! HPE6 - High Priority Elevation 6
 *  0b0..Master high-priority elevation for master 6. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 6. is enabled on this slave port.
 */
#define AON_AXBS_CRS0_HPE6(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS0_HPE6_SHIFT)) & AON_AXBS_CRS0_HPE6_MASK)

#define AON_AXBS_CRS0_HPE7_MASK                  (0x800000U)
#define AON_AXBS_CRS0_HPE7_SHIFT                 (23U)
/*! HPE7 - High Priority Elevation 7
 *  0b0..Master high-priority elevation for master 7. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 7. is enabled on this slave port.
 */
#define AON_AXBS_CRS0_HPE7(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS0_HPE7_SHIFT)) & AON_AXBS_CRS0_HPE7_MASK)

#define AON_AXBS_CRS0_HLP_MASK                   (0x40000000U)
#define AON_AXBS_CRS0_HLP_SHIFT                  (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AON_AXBS_CRS0_HLP(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS0_HLP_SHIFT)) & AON_AXBS_CRS0_HLP_MASK)

#define AON_AXBS_CRS0_RO_MASK                    (0x80000000U)
#define AON_AXBS_CRS0_RO_SHIFT                   (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AON_AXBS_CRS0_RO(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS0_RO_SHIFT)) & AON_AXBS_CRS0_RO_MASK)
/*! @} */

/*! @name PRS1 - Priority Slave Registers */
/*! @{ */

#define AON_AXBS_PRS1_M0_MASK                    (0x7U)
#define AON_AXBS_PRS1_M0_SHIFT                   (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or the lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS1_M0(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS1_M0_SHIFT)) & AON_AXBS_PRS1_M0_MASK)

#define AON_AXBS_PRS1_M1_MASK                    (0x70U)
#define AON_AXBS_PRS1_M1_SHIFT                   (4U)
/*! M1 - Master 1 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS1_M1(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS1_M1_SHIFT)) & AON_AXBS_PRS1_M1_MASK)

#define AON_AXBS_PRS1_M2_MASK                    (0x700U)
#define AON_AXBS_PRS1_M2_SHIFT                   (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS1_M2(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS1_M2_SHIFT)) & AON_AXBS_PRS1_M2_MASK)

#define AON_AXBS_PRS1_M3_MASK                    (0x7000U)
#define AON_AXBS_PRS1_M3_SHIFT                   (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS1_M3(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS1_M3_SHIFT)) & AON_AXBS_PRS1_M3_MASK)

#define AON_AXBS_PRS1_M4_MASK                    (0x70000U)
#define AON_AXBS_PRS1_M4_SHIFT                   (16U)
/*! M4 - Master 4 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS1_M4(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS1_M4_SHIFT)) & AON_AXBS_PRS1_M4_MASK)

#define AON_AXBS_PRS1_M5_MASK                    (0x700000U)
#define AON_AXBS_PRS1_M5_SHIFT                   (20U)
/*! M5 - Master 5 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS1_M5(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS1_M5_SHIFT)) & AON_AXBS_PRS1_M5_MASK)

#define AON_AXBS_PRS1_M6_MASK                    (0x7000000U)
#define AON_AXBS_PRS1_M6_SHIFT                   (24U)
/*! M6 - Master 6 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS1_M6(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS1_M6_SHIFT)) & AON_AXBS_PRS1_M6_MASK)

#define AON_AXBS_PRS1_M7_MASK                    (0x70000000U)
#define AON_AXBS_PRS1_M7_SHIFT                   (28U)
/*! M7 - Master 7 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS1_M7(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS1_M7_SHIFT)) & AON_AXBS_PRS1_M7_MASK)
/*! @} */

/*! @name CRS1 - Control Register */
/*! @{ */

#define AON_AXBS_CRS1_PARK_MASK                  (0x7U)
#define AON_AXBS_CRS1_PARK_SHIFT                 (0U)
/*! PARK - Park
 *  0b000..Park on master port M0
 *  0b001..Park on master port M1
 *  0b010..Park on master port M2
 *  0b011..Park on master port M3
 *  0b100..Park on master port M4
 *  0b101..Park on master port M5
 *  0b110..Park on master port M6
 *  0b111..Park on master port M7
 */
#define AON_AXBS_CRS1_PARK(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS1_PARK_SHIFT)) & AON_AXBS_CRS1_PARK_MASK)

#define AON_AXBS_CRS1_PCTL_MASK                  (0x30U)
#define AON_AXBS_CRS1_PCTL_SHIFT                 (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AON_AXBS_CRS1_PCTL(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS1_PCTL_SHIFT)) & AON_AXBS_CRS1_PCTL_MASK)

#define AON_AXBS_CRS1_ARB_MASK                   (0x300U)
#define AON_AXBS_CRS1_ARB_SHIFT                  (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AON_AXBS_CRS1_ARB(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS1_ARB_SHIFT)) & AON_AXBS_CRS1_ARB_MASK)

#define AON_AXBS_CRS1_HPE0_MASK                  (0x10000U)
#define AON_AXBS_CRS1_HPE0_SHIFT                 (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AON_AXBS_CRS1_HPE0(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS1_HPE0_SHIFT)) & AON_AXBS_CRS1_HPE0_MASK)

#define AON_AXBS_CRS1_HPE1_MASK                  (0x20000U)
#define AON_AXBS_CRS1_HPE1_SHIFT                 (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AON_AXBS_CRS1_HPE1(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS1_HPE1_SHIFT)) & AON_AXBS_CRS1_HPE1_MASK)

#define AON_AXBS_CRS1_HPE2_MASK                  (0x40000U)
#define AON_AXBS_CRS1_HPE2_SHIFT                 (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AON_AXBS_CRS1_HPE2(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS1_HPE2_SHIFT)) & AON_AXBS_CRS1_HPE2_MASK)

#define AON_AXBS_CRS1_HPE3_MASK                  (0x80000U)
#define AON_AXBS_CRS1_HPE3_SHIFT                 (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AON_AXBS_CRS1_HPE3(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS1_HPE3_SHIFT)) & AON_AXBS_CRS1_HPE3_MASK)

#define AON_AXBS_CRS1_HPE4_MASK                  (0x100000U)
#define AON_AXBS_CRS1_HPE4_SHIFT                 (20U)
/*! HPE4 - High Priority Elevation 4
 *  0b0..Master high-priority elevation for master 4. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 4. is enabled on this slave port.
 */
#define AON_AXBS_CRS1_HPE4(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS1_HPE4_SHIFT)) & AON_AXBS_CRS1_HPE4_MASK)

#define AON_AXBS_CRS1_HPE5_MASK                  (0x200000U)
#define AON_AXBS_CRS1_HPE5_SHIFT                 (21U)
/*! HPE5 - High Priority Elevation 5
 *  0b0..Master high-priority elevation for master 5. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 5. is enabled on this slave port.
 */
#define AON_AXBS_CRS1_HPE5(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS1_HPE5_SHIFT)) & AON_AXBS_CRS1_HPE5_MASK)

#define AON_AXBS_CRS1_HPE6_MASK                  (0x400000U)
#define AON_AXBS_CRS1_HPE6_SHIFT                 (22U)
/*! HPE6 - High Priority Elevation 6
 *  0b0..Master high-priority elevation for master 6. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 6. is enabled on this slave port.
 */
#define AON_AXBS_CRS1_HPE6(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS1_HPE6_SHIFT)) & AON_AXBS_CRS1_HPE6_MASK)

#define AON_AXBS_CRS1_HPE7_MASK                  (0x800000U)
#define AON_AXBS_CRS1_HPE7_SHIFT                 (23U)
/*! HPE7 - High Priority Elevation 7
 *  0b0..Master high-priority elevation for master 7. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 7. is enabled on this slave port.
 */
#define AON_AXBS_CRS1_HPE7(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS1_HPE7_SHIFT)) & AON_AXBS_CRS1_HPE7_MASK)

#define AON_AXBS_CRS1_HLP_MASK                   (0x40000000U)
#define AON_AXBS_CRS1_HLP_SHIFT                  (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AON_AXBS_CRS1_HLP(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS1_HLP_SHIFT)) & AON_AXBS_CRS1_HLP_MASK)

#define AON_AXBS_CRS1_RO_MASK                    (0x80000000U)
#define AON_AXBS_CRS1_RO_SHIFT                   (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AON_AXBS_CRS1_RO(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS1_RO_SHIFT)) & AON_AXBS_CRS1_RO_MASK)
/*! @} */

/*! @name PRS2 - Priority Slave Registers */
/*! @{ */

#define AON_AXBS_PRS2_M0_MASK                    (0x7U)
#define AON_AXBS_PRS2_M0_SHIFT                   (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or the lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS2_M0(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS2_M0_SHIFT)) & AON_AXBS_PRS2_M0_MASK)

#define AON_AXBS_PRS2_M1_MASK                    (0x70U)
#define AON_AXBS_PRS2_M1_SHIFT                   (4U)
/*! M1 - Master 1 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS2_M1(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS2_M1_SHIFT)) & AON_AXBS_PRS2_M1_MASK)

#define AON_AXBS_PRS2_M2_MASK                    (0x700U)
#define AON_AXBS_PRS2_M2_SHIFT                   (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS2_M2(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS2_M2_SHIFT)) & AON_AXBS_PRS2_M2_MASK)

#define AON_AXBS_PRS2_M3_MASK                    (0x7000U)
#define AON_AXBS_PRS2_M3_SHIFT                   (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS2_M3(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS2_M3_SHIFT)) & AON_AXBS_PRS2_M3_MASK)

#define AON_AXBS_PRS2_M4_MASK                    (0x70000U)
#define AON_AXBS_PRS2_M4_SHIFT                   (16U)
/*! M4 - Master 4 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS2_M4(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS2_M4_SHIFT)) & AON_AXBS_PRS2_M4_MASK)

#define AON_AXBS_PRS2_M5_MASK                    (0x700000U)
#define AON_AXBS_PRS2_M5_SHIFT                   (20U)
/*! M5 - Master 5 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS2_M5(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS2_M5_SHIFT)) & AON_AXBS_PRS2_M5_MASK)

#define AON_AXBS_PRS2_M6_MASK                    (0x7000000U)
#define AON_AXBS_PRS2_M6_SHIFT                   (24U)
/*! M6 - Master 6 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS2_M6(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS2_M6_SHIFT)) & AON_AXBS_PRS2_M6_MASK)

#define AON_AXBS_PRS2_M7_MASK                    (0x70000000U)
#define AON_AXBS_PRS2_M7_SHIFT                   (28U)
/*! M7 - Master 7 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS2_M7(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS2_M7_SHIFT)) & AON_AXBS_PRS2_M7_MASK)
/*! @} */

/*! @name CRS2 - Control Register */
/*! @{ */

#define AON_AXBS_CRS2_PARK_MASK                  (0x7U)
#define AON_AXBS_CRS2_PARK_SHIFT                 (0U)
/*! PARK - Park
 *  0b000..Park on master port M0
 *  0b001..Park on master port M1
 *  0b010..Park on master port M2
 *  0b011..Park on master port M3
 *  0b100..Park on master port M4
 *  0b101..Park on master port M5
 *  0b110..Park on master port M6
 *  0b111..Park on master port M7
 */
#define AON_AXBS_CRS2_PARK(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS2_PARK_SHIFT)) & AON_AXBS_CRS2_PARK_MASK)

#define AON_AXBS_CRS2_PCTL_MASK                  (0x30U)
#define AON_AXBS_CRS2_PCTL_SHIFT                 (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AON_AXBS_CRS2_PCTL(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS2_PCTL_SHIFT)) & AON_AXBS_CRS2_PCTL_MASK)

#define AON_AXBS_CRS2_ARB_MASK                   (0x300U)
#define AON_AXBS_CRS2_ARB_SHIFT                  (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AON_AXBS_CRS2_ARB(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS2_ARB_SHIFT)) & AON_AXBS_CRS2_ARB_MASK)

#define AON_AXBS_CRS2_HPE0_MASK                  (0x10000U)
#define AON_AXBS_CRS2_HPE0_SHIFT                 (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AON_AXBS_CRS2_HPE0(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS2_HPE0_SHIFT)) & AON_AXBS_CRS2_HPE0_MASK)

#define AON_AXBS_CRS2_HPE1_MASK                  (0x20000U)
#define AON_AXBS_CRS2_HPE1_SHIFT                 (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AON_AXBS_CRS2_HPE1(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS2_HPE1_SHIFT)) & AON_AXBS_CRS2_HPE1_MASK)

#define AON_AXBS_CRS2_HPE2_MASK                  (0x40000U)
#define AON_AXBS_CRS2_HPE2_SHIFT                 (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AON_AXBS_CRS2_HPE2(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS2_HPE2_SHIFT)) & AON_AXBS_CRS2_HPE2_MASK)

#define AON_AXBS_CRS2_HPE3_MASK                  (0x80000U)
#define AON_AXBS_CRS2_HPE3_SHIFT                 (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AON_AXBS_CRS2_HPE3(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS2_HPE3_SHIFT)) & AON_AXBS_CRS2_HPE3_MASK)

#define AON_AXBS_CRS2_HPE4_MASK                  (0x100000U)
#define AON_AXBS_CRS2_HPE4_SHIFT                 (20U)
/*! HPE4 - High Priority Elevation 4
 *  0b0..Master high-priority elevation for master 4. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 4. is enabled on this slave port.
 */
#define AON_AXBS_CRS2_HPE4(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS2_HPE4_SHIFT)) & AON_AXBS_CRS2_HPE4_MASK)

#define AON_AXBS_CRS2_HPE5_MASK                  (0x200000U)
#define AON_AXBS_CRS2_HPE5_SHIFT                 (21U)
/*! HPE5 - High Priority Elevation 5
 *  0b0..Master high-priority elevation for master 5. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 5. is enabled on this slave port.
 */
#define AON_AXBS_CRS2_HPE5(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS2_HPE5_SHIFT)) & AON_AXBS_CRS2_HPE5_MASK)

#define AON_AXBS_CRS2_HPE6_MASK                  (0x400000U)
#define AON_AXBS_CRS2_HPE6_SHIFT                 (22U)
/*! HPE6 - High Priority Elevation 6
 *  0b0..Master high-priority elevation for master 6. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 6. is enabled on this slave port.
 */
#define AON_AXBS_CRS2_HPE6(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS2_HPE6_SHIFT)) & AON_AXBS_CRS2_HPE6_MASK)

#define AON_AXBS_CRS2_HPE7_MASK                  (0x800000U)
#define AON_AXBS_CRS2_HPE7_SHIFT                 (23U)
/*! HPE7 - High Priority Elevation 7
 *  0b0..Master high-priority elevation for master 7. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 7. is enabled on this slave port.
 */
#define AON_AXBS_CRS2_HPE7(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS2_HPE7_SHIFT)) & AON_AXBS_CRS2_HPE7_MASK)

#define AON_AXBS_CRS2_HLP_MASK                   (0x40000000U)
#define AON_AXBS_CRS2_HLP_SHIFT                  (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AON_AXBS_CRS2_HLP(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS2_HLP_SHIFT)) & AON_AXBS_CRS2_HLP_MASK)

#define AON_AXBS_CRS2_RO_MASK                    (0x80000000U)
#define AON_AXBS_CRS2_RO_SHIFT                   (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AON_AXBS_CRS2_RO(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS2_RO_SHIFT)) & AON_AXBS_CRS2_RO_MASK)
/*! @} */

/*! @name PRS3 - Priority Slave Registers */
/*! @{ */

#define AON_AXBS_PRS3_M0_MASK                    (0x7U)
#define AON_AXBS_PRS3_M0_SHIFT                   (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or the lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS3_M0(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS3_M0_SHIFT)) & AON_AXBS_PRS3_M0_MASK)

#define AON_AXBS_PRS3_M1_MASK                    (0x70U)
#define AON_AXBS_PRS3_M1_SHIFT                   (4U)
/*! M1 - Master 1 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS3_M1(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS3_M1_SHIFT)) & AON_AXBS_PRS3_M1_MASK)

#define AON_AXBS_PRS3_M2_MASK                    (0x700U)
#define AON_AXBS_PRS3_M2_SHIFT                   (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS3_M2(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS3_M2_SHIFT)) & AON_AXBS_PRS3_M2_MASK)

#define AON_AXBS_PRS3_M3_MASK                    (0x7000U)
#define AON_AXBS_PRS3_M3_SHIFT                   (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS3_M3(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS3_M3_SHIFT)) & AON_AXBS_PRS3_M3_MASK)

#define AON_AXBS_PRS3_M4_MASK                    (0x70000U)
#define AON_AXBS_PRS3_M4_SHIFT                   (16U)
/*! M4 - Master 4 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS3_M4(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS3_M4_SHIFT)) & AON_AXBS_PRS3_M4_MASK)

#define AON_AXBS_PRS3_M5_MASK                    (0x700000U)
#define AON_AXBS_PRS3_M5_SHIFT                   (20U)
/*! M5 - Master 5 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS3_M5(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS3_M5_SHIFT)) & AON_AXBS_PRS3_M5_MASK)

#define AON_AXBS_PRS3_M6_MASK                    (0x7000000U)
#define AON_AXBS_PRS3_M6_SHIFT                   (24U)
/*! M6 - Master 6 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS3_M6(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS3_M6_SHIFT)) & AON_AXBS_PRS3_M6_MASK)

#define AON_AXBS_PRS3_M7_MASK                    (0x70000000U)
#define AON_AXBS_PRS3_M7_SHIFT                   (28U)
/*! M7 - Master 7 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS3_M7(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS3_M7_SHIFT)) & AON_AXBS_PRS3_M7_MASK)
/*! @} */

/*! @name CRS3 - Control Register */
/*! @{ */

#define AON_AXBS_CRS3_PARK_MASK                  (0x7U)
#define AON_AXBS_CRS3_PARK_SHIFT                 (0U)
/*! PARK - Park
 *  0b000..Park on master port M0
 *  0b001..Park on master port M1
 *  0b010..Park on master port M2
 *  0b011..Park on master port M3
 *  0b100..Park on master port M4
 *  0b101..Park on master port M5
 *  0b110..Park on master port M6
 *  0b111..Park on master port M7
 */
#define AON_AXBS_CRS3_PARK(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS3_PARK_SHIFT)) & AON_AXBS_CRS3_PARK_MASK)

#define AON_AXBS_CRS3_PCTL_MASK                  (0x30U)
#define AON_AXBS_CRS3_PCTL_SHIFT                 (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AON_AXBS_CRS3_PCTL(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS3_PCTL_SHIFT)) & AON_AXBS_CRS3_PCTL_MASK)

#define AON_AXBS_CRS3_ARB_MASK                   (0x300U)
#define AON_AXBS_CRS3_ARB_SHIFT                  (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AON_AXBS_CRS3_ARB(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS3_ARB_SHIFT)) & AON_AXBS_CRS3_ARB_MASK)

#define AON_AXBS_CRS3_HPE0_MASK                  (0x10000U)
#define AON_AXBS_CRS3_HPE0_SHIFT                 (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AON_AXBS_CRS3_HPE0(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS3_HPE0_SHIFT)) & AON_AXBS_CRS3_HPE0_MASK)

#define AON_AXBS_CRS3_HPE1_MASK                  (0x20000U)
#define AON_AXBS_CRS3_HPE1_SHIFT                 (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AON_AXBS_CRS3_HPE1(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS3_HPE1_SHIFT)) & AON_AXBS_CRS3_HPE1_MASK)

#define AON_AXBS_CRS3_HPE2_MASK                  (0x40000U)
#define AON_AXBS_CRS3_HPE2_SHIFT                 (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AON_AXBS_CRS3_HPE2(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS3_HPE2_SHIFT)) & AON_AXBS_CRS3_HPE2_MASK)

#define AON_AXBS_CRS3_HPE3_MASK                  (0x80000U)
#define AON_AXBS_CRS3_HPE3_SHIFT                 (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AON_AXBS_CRS3_HPE3(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS3_HPE3_SHIFT)) & AON_AXBS_CRS3_HPE3_MASK)

#define AON_AXBS_CRS3_HPE4_MASK                  (0x100000U)
#define AON_AXBS_CRS3_HPE4_SHIFT                 (20U)
/*! HPE4 - High Priority Elevation 4
 *  0b0..Master high-priority elevation for master 4. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 4. is enabled on this slave port.
 */
#define AON_AXBS_CRS3_HPE4(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS3_HPE4_SHIFT)) & AON_AXBS_CRS3_HPE4_MASK)

#define AON_AXBS_CRS3_HPE5_MASK                  (0x200000U)
#define AON_AXBS_CRS3_HPE5_SHIFT                 (21U)
/*! HPE5 - High Priority Elevation 5
 *  0b0..Master high-priority elevation for master 5. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 5. is enabled on this slave port.
 */
#define AON_AXBS_CRS3_HPE5(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS3_HPE5_SHIFT)) & AON_AXBS_CRS3_HPE5_MASK)

#define AON_AXBS_CRS3_HPE6_MASK                  (0x400000U)
#define AON_AXBS_CRS3_HPE6_SHIFT                 (22U)
/*! HPE6 - High Priority Elevation 6
 *  0b0..Master high-priority elevation for master 6. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 6. is enabled on this slave port.
 */
#define AON_AXBS_CRS3_HPE6(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS3_HPE6_SHIFT)) & AON_AXBS_CRS3_HPE6_MASK)

#define AON_AXBS_CRS3_HPE7_MASK                  (0x800000U)
#define AON_AXBS_CRS3_HPE7_SHIFT                 (23U)
/*! HPE7 - High Priority Elevation 7
 *  0b0..Master high-priority elevation for master 7. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 7. is enabled on this slave port.
 */
#define AON_AXBS_CRS3_HPE7(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS3_HPE7_SHIFT)) & AON_AXBS_CRS3_HPE7_MASK)

#define AON_AXBS_CRS3_HLP_MASK                   (0x40000000U)
#define AON_AXBS_CRS3_HLP_SHIFT                  (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AON_AXBS_CRS3_HLP(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS3_HLP_SHIFT)) & AON_AXBS_CRS3_HLP_MASK)

#define AON_AXBS_CRS3_RO_MASK                    (0x80000000U)
#define AON_AXBS_CRS3_RO_SHIFT                   (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AON_AXBS_CRS3_RO(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS3_RO_SHIFT)) & AON_AXBS_CRS3_RO_MASK)
/*! @} */

/*! @name PRS4 - Priority Slave Registers */
/*! @{ */

#define AON_AXBS_PRS4_M0_MASK                    (0x7U)
#define AON_AXBS_PRS4_M0_SHIFT                   (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or the lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS4_M0(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS4_M0_SHIFT)) & AON_AXBS_PRS4_M0_MASK)

#define AON_AXBS_PRS4_M1_MASK                    (0x70U)
#define AON_AXBS_PRS4_M1_SHIFT                   (4U)
/*! M1 - Master 1 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS4_M1(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS4_M1_SHIFT)) & AON_AXBS_PRS4_M1_MASK)

#define AON_AXBS_PRS4_M2_MASK                    (0x700U)
#define AON_AXBS_PRS4_M2_SHIFT                   (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS4_M2(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS4_M2_SHIFT)) & AON_AXBS_PRS4_M2_MASK)

#define AON_AXBS_PRS4_M3_MASK                    (0x7000U)
#define AON_AXBS_PRS4_M3_SHIFT                   (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS4_M3(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS4_M3_SHIFT)) & AON_AXBS_PRS4_M3_MASK)

#define AON_AXBS_PRS4_M4_MASK                    (0x70000U)
#define AON_AXBS_PRS4_M4_SHIFT                   (16U)
/*! M4 - Master 4 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS4_M4(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS4_M4_SHIFT)) & AON_AXBS_PRS4_M4_MASK)

#define AON_AXBS_PRS4_M5_MASK                    (0x700000U)
#define AON_AXBS_PRS4_M5_SHIFT                   (20U)
/*! M5 - Master 5 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS4_M5(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS4_M5_SHIFT)) & AON_AXBS_PRS4_M5_MASK)

#define AON_AXBS_PRS4_M6_MASK                    (0x7000000U)
#define AON_AXBS_PRS4_M6_SHIFT                   (24U)
/*! M6 - Master 6 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS4_M6(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS4_M6_SHIFT)) & AON_AXBS_PRS4_M6_MASK)

#define AON_AXBS_PRS4_M7_MASK                    (0x70000000U)
#define AON_AXBS_PRS4_M7_SHIFT                   (28U)
/*! M7 - Master 7 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS4_M7(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS4_M7_SHIFT)) & AON_AXBS_PRS4_M7_MASK)
/*! @} */

/*! @name CRS4 - Control Register */
/*! @{ */

#define AON_AXBS_CRS4_PARK_MASK                  (0x7U)
#define AON_AXBS_CRS4_PARK_SHIFT                 (0U)
/*! PARK - Park
 *  0b000..Park on master port M0
 *  0b001..Park on master port M1
 *  0b010..Park on master port M2
 *  0b011..Park on master port M3
 *  0b100..Park on master port M4
 *  0b101..Park on master port M5
 *  0b110..Park on master port M6
 *  0b111..Park on master port M7
 */
#define AON_AXBS_CRS4_PARK(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS4_PARK_SHIFT)) & AON_AXBS_CRS4_PARK_MASK)

#define AON_AXBS_CRS4_PCTL_MASK                  (0x30U)
#define AON_AXBS_CRS4_PCTL_SHIFT                 (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AON_AXBS_CRS4_PCTL(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS4_PCTL_SHIFT)) & AON_AXBS_CRS4_PCTL_MASK)

#define AON_AXBS_CRS4_ARB_MASK                   (0x300U)
#define AON_AXBS_CRS4_ARB_SHIFT                  (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AON_AXBS_CRS4_ARB(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS4_ARB_SHIFT)) & AON_AXBS_CRS4_ARB_MASK)

#define AON_AXBS_CRS4_HPE0_MASK                  (0x10000U)
#define AON_AXBS_CRS4_HPE0_SHIFT                 (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AON_AXBS_CRS4_HPE0(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS4_HPE0_SHIFT)) & AON_AXBS_CRS4_HPE0_MASK)

#define AON_AXBS_CRS4_HPE1_MASK                  (0x20000U)
#define AON_AXBS_CRS4_HPE1_SHIFT                 (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AON_AXBS_CRS4_HPE1(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS4_HPE1_SHIFT)) & AON_AXBS_CRS4_HPE1_MASK)

#define AON_AXBS_CRS4_HPE2_MASK                  (0x40000U)
#define AON_AXBS_CRS4_HPE2_SHIFT                 (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AON_AXBS_CRS4_HPE2(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS4_HPE2_SHIFT)) & AON_AXBS_CRS4_HPE2_MASK)

#define AON_AXBS_CRS4_HPE3_MASK                  (0x80000U)
#define AON_AXBS_CRS4_HPE3_SHIFT                 (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AON_AXBS_CRS4_HPE3(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS4_HPE3_SHIFT)) & AON_AXBS_CRS4_HPE3_MASK)

#define AON_AXBS_CRS4_HPE4_MASK                  (0x100000U)
#define AON_AXBS_CRS4_HPE4_SHIFT                 (20U)
/*! HPE4 - High Priority Elevation 4
 *  0b0..Master high-priority elevation for master 4. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 4. is enabled on this slave port.
 */
#define AON_AXBS_CRS4_HPE4(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS4_HPE4_SHIFT)) & AON_AXBS_CRS4_HPE4_MASK)

#define AON_AXBS_CRS4_HPE5_MASK                  (0x200000U)
#define AON_AXBS_CRS4_HPE5_SHIFT                 (21U)
/*! HPE5 - High Priority Elevation 5
 *  0b0..Master high-priority elevation for master 5. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 5. is enabled on this slave port.
 */
#define AON_AXBS_CRS4_HPE5(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS4_HPE5_SHIFT)) & AON_AXBS_CRS4_HPE5_MASK)

#define AON_AXBS_CRS4_HPE6_MASK                  (0x400000U)
#define AON_AXBS_CRS4_HPE6_SHIFT                 (22U)
/*! HPE6 - High Priority Elevation 6
 *  0b0..Master high-priority elevation for master 6. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 6. is enabled on this slave port.
 */
#define AON_AXBS_CRS4_HPE6(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS4_HPE6_SHIFT)) & AON_AXBS_CRS4_HPE6_MASK)

#define AON_AXBS_CRS4_HPE7_MASK                  (0x800000U)
#define AON_AXBS_CRS4_HPE7_SHIFT                 (23U)
/*! HPE7 - High Priority Elevation 7
 *  0b0..Master high-priority elevation for master 7. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 7. is enabled on this slave port.
 */
#define AON_AXBS_CRS4_HPE7(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS4_HPE7_SHIFT)) & AON_AXBS_CRS4_HPE7_MASK)

#define AON_AXBS_CRS4_HLP_MASK                   (0x40000000U)
#define AON_AXBS_CRS4_HLP_SHIFT                  (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AON_AXBS_CRS4_HLP(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS4_HLP_SHIFT)) & AON_AXBS_CRS4_HLP_MASK)

#define AON_AXBS_CRS4_RO_MASK                    (0x80000000U)
#define AON_AXBS_CRS4_RO_SHIFT                   (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AON_AXBS_CRS4_RO(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS4_RO_SHIFT)) & AON_AXBS_CRS4_RO_MASK)
/*! @} */

/*! @name PRS5 - Priority Slave Registers */
/*! @{ */

#define AON_AXBS_PRS5_M0_MASK                    (0x7U)
#define AON_AXBS_PRS5_M0_SHIFT                   (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or the lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS5_M0(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS5_M0_SHIFT)) & AON_AXBS_PRS5_M0_MASK)

#define AON_AXBS_PRS5_M1_MASK                    (0x70U)
#define AON_AXBS_PRS5_M1_SHIFT                   (4U)
/*! M1 - Master 1 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS5_M1(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS5_M1_SHIFT)) & AON_AXBS_PRS5_M1_MASK)

#define AON_AXBS_PRS5_M2_MASK                    (0x700U)
#define AON_AXBS_PRS5_M2_SHIFT                   (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS5_M2(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS5_M2_SHIFT)) & AON_AXBS_PRS5_M2_MASK)

#define AON_AXBS_PRS5_M3_MASK                    (0x7000U)
#define AON_AXBS_PRS5_M3_SHIFT                   (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS5_M3(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS5_M3_SHIFT)) & AON_AXBS_PRS5_M3_MASK)

#define AON_AXBS_PRS5_M4_MASK                    (0x70000U)
#define AON_AXBS_PRS5_M4_SHIFT                   (16U)
/*! M4 - Master 4 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS5_M4(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS5_M4_SHIFT)) & AON_AXBS_PRS5_M4_MASK)

#define AON_AXBS_PRS5_M5_MASK                    (0x700000U)
#define AON_AXBS_PRS5_M5_SHIFT                   (20U)
/*! M5 - Master 5 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS5_M5(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS5_M5_SHIFT)) & AON_AXBS_PRS5_M5_MASK)

#define AON_AXBS_PRS5_M6_MASK                    (0x7000000U)
#define AON_AXBS_PRS5_M6_SHIFT                   (24U)
/*! M6 - Master 6 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS5_M6(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS5_M6_SHIFT)) & AON_AXBS_PRS5_M6_MASK)

#define AON_AXBS_PRS5_M7_MASK                    (0x70000000U)
#define AON_AXBS_PRS5_M7_SHIFT                   (28U)
/*! M7 - Master 7 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS5_M7(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS5_M7_SHIFT)) & AON_AXBS_PRS5_M7_MASK)
/*! @} */

/*! @name CRS5 - Control Register */
/*! @{ */

#define AON_AXBS_CRS5_PARK_MASK                  (0x7U)
#define AON_AXBS_CRS5_PARK_SHIFT                 (0U)
/*! PARK - Park
 *  0b000..Park on master port M0
 *  0b001..Park on master port M1
 *  0b010..Park on master port M2
 *  0b011..Park on master port M3
 *  0b100..Park on master port M4
 *  0b101..Park on master port M5
 *  0b110..Park on master port M6
 *  0b111..Park on master port M7
 */
#define AON_AXBS_CRS5_PARK(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS5_PARK_SHIFT)) & AON_AXBS_CRS5_PARK_MASK)

#define AON_AXBS_CRS5_PCTL_MASK                  (0x30U)
#define AON_AXBS_CRS5_PCTL_SHIFT                 (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AON_AXBS_CRS5_PCTL(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS5_PCTL_SHIFT)) & AON_AXBS_CRS5_PCTL_MASK)

#define AON_AXBS_CRS5_ARB_MASK                   (0x300U)
#define AON_AXBS_CRS5_ARB_SHIFT                  (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AON_AXBS_CRS5_ARB(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS5_ARB_SHIFT)) & AON_AXBS_CRS5_ARB_MASK)

#define AON_AXBS_CRS5_HPE0_MASK                  (0x10000U)
#define AON_AXBS_CRS5_HPE0_SHIFT                 (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AON_AXBS_CRS5_HPE0(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS5_HPE0_SHIFT)) & AON_AXBS_CRS5_HPE0_MASK)

#define AON_AXBS_CRS5_HPE1_MASK                  (0x20000U)
#define AON_AXBS_CRS5_HPE1_SHIFT                 (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AON_AXBS_CRS5_HPE1(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS5_HPE1_SHIFT)) & AON_AXBS_CRS5_HPE1_MASK)

#define AON_AXBS_CRS5_HPE2_MASK                  (0x40000U)
#define AON_AXBS_CRS5_HPE2_SHIFT                 (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AON_AXBS_CRS5_HPE2(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS5_HPE2_SHIFT)) & AON_AXBS_CRS5_HPE2_MASK)

#define AON_AXBS_CRS5_HPE3_MASK                  (0x80000U)
#define AON_AXBS_CRS5_HPE3_SHIFT                 (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AON_AXBS_CRS5_HPE3(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS5_HPE3_SHIFT)) & AON_AXBS_CRS5_HPE3_MASK)

#define AON_AXBS_CRS5_HPE4_MASK                  (0x100000U)
#define AON_AXBS_CRS5_HPE4_SHIFT                 (20U)
/*! HPE4 - High Priority Elevation 4
 *  0b0..Master high-priority elevation for master 4. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 4. is enabled on this slave port.
 */
#define AON_AXBS_CRS5_HPE4(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS5_HPE4_SHIFT)) & AON_AXBS_CRS5_HPE4_MASK)

#define AON_AXBS_CRS5_HPE5_MASK                  (0x200000U)
#define AON_AXBS_CRS5_HPE5_SHIFT                 (21U)
/*! HPE5 - High Priority Elevation 5
 *  0b0..Master high-priority elevation for master 5. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 5. is enabled on this slave port.
 */
#define AON_AXBS_CRS5_HPE5(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS5_HPE5_SHIFT)) & AON_AXBS_CRS5_HPE5_MASK)

#define AON_AXBS_CRS5_HPE6_MASK                  (0x400000U)
#define AON_AXBS_CRS5_HPE6_SHIFT                 (22U)
/*! HPE6 - High Priority Elevation 6
 *  0b0..Master high-priority elevation for master 6. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 6. is enabled on this slave port.
 */
#define AON_AXBS_CRS5_HPE6(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS5_HPE6_SHIFT)) & AON_AXBS_CRS5_HPE6_MASK)

#define AON_AXBS_CRS5_HPE7_MASK                  (0x800000U)
#define AON_AXBS_CRS5_HPE7_SHIFT                 (23U)
/*! HPE7 - High Priority Elevation 7
 *  0b0..Master high-priority elevation for master 7. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 7. is enabled on this slave port.
 */
#define AON_AXBS_CRS5_HPE7(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS5_HPE7_SHIFT)) & AON_AXBS_CRS5_HPE7_MASK)

#define AON_AXBS_CRS5_HLP_MASK                   (0x40000000U)
#define AON_AXBS_CRS5_HLP_SHIFT                  (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AON_AXBS_CRS5_HLP(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS5_HLP_SHIFT)) & AON_AXBS_CRS5_HLP_MASK)

#define AON_AXBS_CRS5_RO_MASK                    (0x80000000U)
#define AON_AXBS_CRS5_RO_SHIFT                   (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AON_AXBS_CRS5_RO(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS5_RO_SHIFT)) & AON_AXBS_CRS5_RO_MASK)
/*! @} */

/*! @name PRS6 - Priority Slave Registers */
/*! @{ */

#define AON_AXBS_PRS6_M0_MASK                    (0x7U)
#define AON_AXBS_PRS6_M0_SHIFT                   (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or the lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS6_M0(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS6_M0_SHIFT)) & AON_AXBS_PRS6_M0_MASK)

#define AON_AXBS_PRS6_M1_MASK                    (0x70U)
#define AON_AXBS_PRS6_M1_SHIFT                   (4U)
/*! M1 - Master 1 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS6_M1(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS6_M1_SHIFT)) & AON_AXBS_PRS6_M1_MASK)

#define AON_AXBS_PRS6_M2_MASK                    (0x700U)
#define AON_AXBS_PRS6_M2_SHIFT                   (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS6_M2(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS6_M2_SHIFT)) & AON_AXBS_PRS6_M2_MASK)

#define AON_AXBS_PRS6_M3_MASK                    (0x7000U)
#define AON_AXBS_PRS6_M3_SHIFT                   (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS6_M3(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS6_M3_SHIFT)) & AON_AXBS_PRS6_M3_MASK)

#define AON_AXBS_PRS6_M4_MASK                    (0x70000U)
#define AON_AXBS_PRS6_M4_SHIFT                   (16U)
/*! M4 - Master 4 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS6_M4(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS6_M4_SHIFT)) & AON_AXBS_PRS6_M4_MASK)

#define AON_AXBS_PRS6_M5_MASK                    (0x700000U)
#define AON_AXBS_PRS6_M5_SHIFT                   (20U)
/*! M5 - Master 5 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS6_M5(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS6_M5_SHIFT)) & AON_AXBS_PRS6_M5_MASK)

#define AON_AXBS_PRS6_M6_MASK                    (0x7000000U)
#define AON_AXBS_PRS6_M6_SHIFT                   (24U)
/*! M6 - Master 6 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS6_M6(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS6_M6_SHIFT)) & AON_AXBS_PRS6_M6_MASK)

#define AON_AXBS_PRS6_M7_MASK                    (0x70000000U)
#define AON_AXBS_PRS6_M7_SHIFT                   (28U)
/*! M7 - Master 7 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS6_M7(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS6_M7_SHIFT)) & AON_AXBS_PRS6_M7_MASK)
/*! @} */

/*! @name CRS6 - Control Register */
/*! @{ */

#define AON_AXBS_CRS6_PARK_MASK                  (0x7U)
#define AON_AXBS_CRS6_PARK_SHIFT                 (0U)
/*! PARK - Park
 *  0b000..Park on master port M0
 *  0b001..Park on master port M1
 *  0b010..Park on master port M2
 *  0b011..Park on master port M3
 *  0b100..Park on master port M4
 *  0b101..Park on master port M5
 *  0b110..Park on master port M6
 *  0b111..Park on master port M7
 */
#define AON_AXBS_CRS6_PARK(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS6_PARK_SHIFT)) & AON_AXBS_CRS6_PARK_MASK)

#define AON_AXBS_CRS6_PCTL_MASK                  (0x30U)
#define AON_AXBS_CRS6_PCTL_SHIFT                 (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AON_AXBS_CRS6_PCTL(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS6_PCTL_SHIFT)) & AON_AXBS_CRS6_PCTL_MASK)

#define AON_AXBS_CRS6_ARB_MASK                   (0x300U)
#define AON_AXBS_CRS6_ARB_SHIFT                  (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AON_AXBS_CRS6_ARB(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS6_ARB_SHIFT)) & AON_AXBS_CRS6_ARB_MASK)

#define AON_AXBS_CRS6_HPE0_MASK                  (0x10000U)
#define AON_AXBS_CRS6_HPE0_SHIFT                 (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AON_AXBS_CRS6_HPE0(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS6_HPE0_SHIFT)) & AON_AXBS_CRS6_HPE0_MASK)

#define AON_AXBS_CRS6_HPE1_MASK                  (0x20000U)
#define AON_AXBS_CRS6_HPE1_SHIFT                 (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AON_AXBS_CRS6_HPE1(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS6_HPE1_SHIFT)) & AON_AXBS_CRS6_HPE1_MASK)

#define AON_AXBS_CRS6_HPE2_MASK                  (0x40000U)
#define AON_AXBS_CRS6_HPE2_SHIFT                 (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AON_AXBS_CRS6_HPE2(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS6_HPE2_SHIFT)) & AON_AXBS_CRS6_HPE2_MASK)

#define AON_AXBS_CRS6_HPE3_MASK                  (0x80000U)
#define AON_AXBS_CRS6_HPE3_SHIFT                 (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AON_AXBS_CRS6_HPE3(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS6_HPE3_SHIFT)) & AON_AXBS_CRS6_HPE3_MASK)

#define AON_AXBS_CRS6_HPE4_MASK                  (0x100000U)
#define AON_AXBS_CRS6_HPE4_SHIFT                 (20U)
/*! HPE4 - High Priority Elevation 4
 *  0b0..Master high-priority elevation for master 4. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 4. is enabled on this slave port.
 */
#define AON_AXBS_CRS6_HPE4(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS6_HPE4_SHIFT)) & AON_AXBS_CRS6_HPE4_MASK)

#define AON_AXBS_CRS6_HPE5_MASK                  (0x200000U)
#define AON_AXBS_CRS6_HPE5_SHIFT                 (21U)
/*! HPE5 - High Priority Elevation 5
 *  0b0..Master high-priority elevation for master 5. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 5. is enabled on this slave port.
 */
#define AON_AXBS_CRS6_HPE5(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS6_HPE5_SHIFT)) & AON_AXBS_CRS6_HPE5_MASK)

#define AON_AXBS_CRS6_HPE6_MASK                  (0x400000U)
#define AON_AXBS_CRS6_HPE6_SHIFT                 (22U)
/*! HPE6 - High Priority Elevation 6
 *  0b0..Master high-priority elevation for master 6. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 6. is enabled on this slave port.
 */
#define AON_AXBS_CRS6_HPE6(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS6_HPE6_SHIFT)) & AON_AXBS_CRS6_HPE6_MASK)

#define AON_AXBS_CRS6_HPE7_MASK                  (0x800000U)
#define AON_AXBS_CRS6_HPE7_SHIFT                 (23U)
/*! HPE7 - High Priority Elevation 7
 *  0b0..Master high-priority elevation for master 7. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 7. is enabled on this slave port.
 */
#define AON_AXBS_CRS6_HPE7(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS6_HPE7_SHIFT)) & AON_AXBS_CRS6_HPE7_MASK)

#define AON_AXBS_CRS6_HLP_MASK                   (0x40000000U)
#define AON_AXBS_CRS6_HLP_SHIFT                  (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AON_AXBS_CRS6_HLP(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS6_HLP_SHIFT)) & AON_AXBS_CRS6_HLP_MASK)

#define AON_AXBS_CRS6_RO_MASK                    (0x80000000U)
#define AON_AXBS_CRS6_RO_SHIFT                   (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AON_AXBS_CRS6_RO(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS6_RO_SHIFT)) & AON_AXBS_CRS6_RO_MASK)
/*! @} */

/*! @name PRS7 - Priority Slave Registers */
/*! @{ */

#define AON_AXBS_PRS7_M0_MASK                    (0x7U)
#define AON_AXBS_PRS7_M0_SHIFT                   (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or the lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS7_M0(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS7_M0_SHIFT)) & AON_AXBS_PRS7_M0_MASK)

#define AON_AXBS_PRS7_M1_MASK                    (0x70U)
#define AON_AXBS_PRS7_M1_SHIFT                   (4U)
/*! M1 - Master 1 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS7_M1(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS7_M1_SHIFT)) & AON_AXBS_PRS7_M1_MASK)

#define AON_AXBS_PRS7_M2_MASK                    (0x700U)
#define AON_AXBS_PRS7_M2_SHIFT                   (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS7_M2(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS7_M2_SHIFT)) & AON_AXBS_PRS7_M2_MASK)

#define AON_AXBS_PRS7_M3_MASK                    (0x7000U)
#define AON_AXBS_PRS7_M3_SHIFT                   (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS7_M3(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS7_M3_SHIFT)) & AON_AXBS_PRS7_M3_MASK)

#define AON_AXBS_PRS7_M4_MASK                    (0x70000U)
#define AON_AXBS_PRS7_M4_SHIFT                   (16U)
/*! M4 - Master 4 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS7_M4(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS7_M4_SHIFT)) & AON_AXBS_PRS7_M4_MASK)

#define AON_AXBS_PRS7_M5_MASK                    (0x700000U)
#define AON_AXBS_PRS7_M5_SHIFT                   (20U)
/*! M5 - Master 5 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS7_M5(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS7_M5_SHIFT)) & AON_AXBS_PRS7_M5_MASK)

#define AON_AXBS_PRS7_M6_MASK                    (0x7000000U)
#define AON_AXBS_PRS7_M6_SHIFT                   (24U)
/*! M6 - Master 6 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8the or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS7_M6(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS7_M6_SHIFT)) & AON_AXBS_PRS7_M6_MASK)

#define AON_AXBS_PRS7_M7_MASK                    (0x70000000U)
#define AON_AXBS_PRS7_M7_SHIFT                   (28U)
/*! M7 - Master 7 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AON_AXBS_PRS7_M7(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_PRS7_M7_SHIFT)) & AON_AXBS_PRS7_M7_MASK)
/*! @} */

/*! @name CRS7 - Control Register */
/*! @{ */

#define AON_AXBS_CRS7_PARK_MASK                  (0x7U)
#define AON_AXBS_CRS7_PARK_SHIFT                 (0U)
/*! PARK - Park
 *  0b000..Park on master port M0
 *  0b001..Park on master port M1
 *  0b010..Park on master port M2
 *  0b011..Park on master port M3
 *  0b100..Park on master port M4
 *  0b101..Park on master port M5
 *  0b110..Park on master port M6
 *  0b111..Park on master port M7
 */
#define AON_AXBS_CRS7_PARK(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS7_PARK_SHIFT)) & AON_AXBS_CRS7_PARK_MASK)

#define AON_AXBS_CRS7_PCTL_MASK                  (0x30U)
#define AON_AXBS_CRS7_PCTL_SHIFT                 (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AON_AXBS_CRS7_PCTL(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS7_PCTL_SHIFT)) & AON_AXBS_CRS7_PCTL_MASK)

#define AON_AXBS_CRS7_ARB_MASK                   (0x300U)
#define AON_AXBS_CRS7_ARB_SHIFT                  (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AON_AXBS_CRS7_ARB(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS7_ARB_SHIFT)) & AON_AXBS_CRS7_ARB_MASK)

#define AON_AXBS_CRS7_HPE0_MASK                  (0x10000U)
#define AON_AXBS_CRS7_HPE0_SHIFT                 (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AON_AXBS_CRS7_HPE0(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS7_HPE0_SHIFT)) & AON_AXBS_CRS7_HPE0_MASK)

#define AON_AXBS_CRS7_HPE1_MASK                  (0x20000U)
#define AON_AXBS_CRS7_HPE1_SHIFT                 (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AON_AXBS_CRS7_HPE1(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS7_HPE1_SHIFT)) & AON_AXBS_CRS7_HPE1_MASK)

#define AON_AXBS_CRS7_HPE2_MASK                  (0x40000U)
#define AON_AXBS_CRS7_HPE2_SHIFT                 (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AON_AXBS_CRS7_HPE2(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS7_HPE2_SHIFT)) & AON_AXBS_CRS7_HPE2_MASK)

#define AON_AXBS_CRS7_HPE3_MASK                  (0x80000U)
#define AON_AXBS_CRS7_HPE3_SHIFT                 (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AON_AXBS_CRS7_HPE3(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS7_HPE3_SHIFT)) & AON_AXBS_CRS7_HPE3_MASK)

#define AON_AXBS_CRS7_HPE4_MASK                  (0x100000U)
#define AON_AXBS_CRS7_HPE4_SHIFT                 (20U)
/*! HPE4 - High Priority Elevation 4
 *  0b0..Master high-priority elevation for master 4. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 4. is enabled on this slave port.
 */
#define AON_AXBS_CRS7_HPE4(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS7_HPE4_SHIFT)) & AON_AXBS_CRS7_HPE4_MASK)

#define AON_AXBS_CRS7_HPE5_MASK                  (0x200000U)
#define AON_AXBS_CRS7_HPE5_SHIFT                 (21U)
/*! HPE5 - High Priority Elevation 5
 *  0b0..Master high-priority elevation for master 5. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 5. is enabled on this slave port.
 */
#define AON_AXBS_CRS7_HPE5(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS7_HPE5_SHIFT)) & AON_AXBS_CRS7_HPE5_MASK)

#define AON_AXBS_CRS7_HPE6_MASK                  (0x400000U)
#define AON_AXBS_CRS7_HPE6_SHIFT                 (22U)
/*! HPE6 - High Priority Elevation 6
 *  0b0..Master high-priority elevation for master 6. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 6. is enabled on this slave port.
 */
#define AON_AXBS_CRS7_HPE6(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS7_HPE6_SHIFT)) & AON_AXBS_CRS7_HPE6_MASK)

#define AON_AXBS_CRS7_HPE7_MASK                  (0x800000U)
#define AON_AXBS_CRS7_HPE7_SHIFT                 (23U)
/*! HPE7 - High Priority Elevation 7
 *  0b0..Master high-priority elevation for master 7. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 7. is enabled on this slave port.
 */
#define AON_AXBS_CRS7_HPE7(x)                    (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS7_HPE7_SHIFT)) & AON_AXBS_CRS7_HPE7_MASK)

#define AON_AXBS_CRS7_HLP_MASK                   (0x40000000U)
#define AON_AXBS_CRS7_HLP_SHIFT                  (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AON_AXBS_CRS7_HLP(x)                     (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS7_HLP_SHIFT)) & AON_AXBS_CRS7_HLP_MASK)

#define AON_AXBS_CRS7_RO_MASK                    (0x80000000U)
#define AON_AXBS_CRS7_RO_SHIFT                   (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AON_AXBS_CRS7_RO(x)                      (((uint32_t)(((uint32_t)(x)) << AON_AXBS_CRS7_RO_SHIFT)) & AON_AXBS_CRS7_RO_MASK)
/*! @} */

/*! @name MGPCR0 - Master General Purpose Control Register */
/*! @{ */

#define AON_AXBS_MGPCR0_AULB_MASK                (0x7U)
#define AON_AXBS_MGPCR0_AULB_SHIFT               (0U)
/*! AULB - Arbitrates On Undefined Length Bursts
 *  0b000..No arbitration is allowed during an undefined length burst.
 *  0b001..Arbitration is allowed at any time during an undefined length burst.
 *  0b010..Arbitration is allowed after four beats of an undefined length burst.
 *  0b011..Arbitration is allowed after eight beats of an undefined length burst.
 *  0b100..Arbitration is allowed after 16 beats of an undefined length burst.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define AON_AXBS_MGPCR0_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << AON_AXBS_MGPCR0_AULB_SHIFT)) & AON_AXBS_MGPCR0_AULB_MASK)
/*! @} */

/*! @name MGPCR1 - Master General Purpose Control Register */
/*! @{ */

#define AON_AXBS_MGPCR1_AULB_MASK                (0x7U)
#define AON_AXBS_MGPCR1_AULB_SHIFT               (0U)
/*! AULB - Arbitrates On Undefined Length Bursts
 *  0b000..No arbitration is allowed during an undefined length burst.
 *  0b001..Arbitration is allowed at any time during an undefined length burst.
 *  0b010..Arbitration is allowed after four beats of an undefined length burst.
 *  0b011..Arbitration is allowed after eight beats of an undefined length burst.
 *  0b100..Arbitration is allowed after 16 beats of an undefined length burst.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define AON_AXBS_MGPCR1_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << AON_AXBS_MGPCR1_AULB_SHIFT)) & AON_AXBS_MGPCR1_AULB_MASK)
/*! @} */

/*! @name MGPCR2 - Master General Purpose Control Register */
/*! @{ */

#define AON_AXBS_MGPCR2_AULB_MASK                (0x7U)
#define AON_AXBS_MGPCR2_AULB_SHIFT               (0U)
/*! AULB - Arbitrates On Undefined Length Bursts
 *  0b000..No arbitration is allowed during an undefined length burst.
 *  0b001..Arbitration is allowed at any time during an undefined length burst.
 *  0b010..Arbitration is allowed after four beats of an undefined length burst.
 *  0b011..Arbitration is allowed after eight beats of an undefined length burst.
 *  0b100..Arbitration is allowed after 16 beats of an undefined length burst.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define AON_AXBS_MGPCR2_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << AON_AXBS_MGPCR2_AULB_SHIFT)) & AON_AXBS_MGPCR2_AULB_MASK)
/*! @} */

/*! @name MGPCR3 - Master General Purpose Control Register */
/*! @{ */

#define AON_AXBS_MGPCR3_AULB_MASK                (0x7U)
#define AON_AXBS_MGPCR3_AULB_SHIFT               (0U)
/*! AULB - Arbitrates On Undefined Length Bursts
 *  0b000..No arbitration is allowed during an undefined length burst.
 *  0b001..Arbitration is allowed at any time during an undefined length burst.
 *  0b010..Arbitration is allowed after four beats of an undefined length burst.
 *  0b011..Arbitration is allowed after eight beats of an undefined length burst.
 *  0b100..Arbitration is allowed after 16 beats of an undefined length burst.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define AON_AXBS_MGPCR3_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << AON_AXBS_MGPCR3_AULB_SHIFT)) & AON_AXBS_MGPCR3_AULB_MASK)
/*! @} */

/*! @name MGPCR4 - Master General Purpose Control Register */
/*! @{ */

#define AON_AXBS_MGPCR4_AULB_MASK                (0x7U)
#define AON_AXBS_MGPCR4_AULB_SHIFT               (0U)
/*! AULB - Arbitrates On Undefined Length Bursts
 *  0b000..No arbitration is allowed during an undefined length burst.
 *  0b001..Arbitration is allowed at any time during an undefined length burst.
 *  0b010..Arbitration is allowed after four beats of an undefined length burst.
 *  0b011..Arbitration is allowed after eight beats of an undefined length burst.
 *  0b100..Arbitration is allowed after 16 beats of an undefined length burst.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define AON_AXBS_MGPCR4_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << AON_AXBS_MGPCR4_AULB_SHIFT)) & AON_AXBS_MGPCR4_AULB_MASK)
/*! @} */

/*! @name MGPCR5 - Master General Purpose Control Register */
/*! @{ */

#define AON_AXBS_MGPCR5_AULB_MASK                (0x7U)
#define AON_AXBS_MGPCR5_AULB_SHIFT               (0U)
/*! AULB - Arbitrates On Undefined Length Bursts
 *  0b000..No arbitration is allowed during an undefined length burst.
 *  0b001..Arbitration is allowed at any time during an undefined length burst.
 *  0b010..Arbitration is allowed after four beats of an undefined length burst.
 *  0b011..Arbitration is allowed after eight beats of an undefined length burst.
 *  0b100..Arbitration is allowed after 16 beats of an undefined length burst.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define AON_AXBS_MGPCR5_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << AON_AXBS_MGPCR5_AULB_SHIFT)) & AON_AXBS_MGPCR5_AULB_MASK)
/*! @} */

/*! @name MGPCR6 - Master General Purpose Control Register */
/*! @{ */

#define AON_AXBS_MGPCR6_AULB_MASK                (0x7U)
#define AON_AXBS_MGPCR6_AULB_SHIFT               (0U)
/*! AULB - Arbitrates On Undefined Length Bursts
 *  0b000..No arbitration is allowed during an undefined length burst.
 *  0b001..Arbitration is allowed at any time during an undefined length burst.
 *  0b010..Arbitration is allowed after four beats of an undefined length burst.
 *  0b011..Arbitration is allowed after eight beats of an undefined length burst.
 *  0b100..Arbitration is allowed after 16 beats of an undefined length burst.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define AON_AXBS_MGPCR6_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << AON_AXBS_MGPCR6_AULB_SHIFT)) & AON_AXBS_MGPCR6_AULB_MASK)
/*! @} */

/*! @name MGPCR7 - Master General Purpose Control Register */
/*! @{ */

#define AON_AXBS_MGPCR7_AULB_MASK                (0x7U)
#define AON_AXBS_MGPCR7_AULB_SHIFT               (0U)
/*! AULB - Arbitrates On Undefined Length Bursts
 *  0b000..No arbitration is allowed during an undefined length burst.
 *  0b001..Arbitration is allowed at any time during an undefined length burst.
 *  0b010..Arbitration is allowed after four beats of an undefined length burst.
 *  0b011..Arbitration is allowed after eight beats of an undefined length burst.
 *  0b100..Arbitration is allowed after 16 beats of an undefined length burst.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define AON_AXBS_MGPCR7_AULB(x)                  (((uint32_t)(((uint32_t)(x)) << AON_AXBS_MGPCR7_AULB_SHIFT)) & AON_AXBS_MGPCR7_AULB_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AON_AXBS_Register_Masks */


/*!
 * @}
 */ /* end of group AON_AXBS_Peripheral_Access_Layer */


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


#endif  /* AON_AXBS_H_ */

