/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AXBS_LITE
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_AXBS_LITE.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for AXBS_LITE
 *
 * CMSIS Peripheral Access Layer for AXBS_LITE
 */

#if !defined(PERI_AXBS_LITE_H_)
#define PERI_AXBS_LITE_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
   -- AXBS_LITE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AXBS_LITE_Peripheral_Access_Layer AXBS_LITE Peripheral Access Layer
 * @{
 */

/** AXBS_LITE - Register Layout Typedef */
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
} AXBS_LITE_Type;

/* ----------------------------------------------------------------------------
   -- AXBS_LITE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AXBS_LITE_Register_Masks AXBS_LITE Register Masks
 * @{
 */

/*! @name PRS0 - Priority Slave Registers */
/*! @{ */

#define AXBS_LITE_PRS0_M0_MASK                   (0x7U)
#define AXBS_LITE_PRS0_M0_SHIFT                  (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS0_M0(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS0_M0_SHIFT)) & AXBS_LITE_PRS0_M0_MASK)

#define AXBS_LITE_PRS0_M1_MASK                   (0x70U)
#define AXBS_LITE_PRS0_M1_SHIFT                  (4U)
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
#define AXBS_LITE_PRS0_M1(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS0_M1_SHIFT)) & AXBS_LITE_PRS0_M1_MASK)

#define AXBS_LITE_PRS0_M2_MASK                   (0x700U)
#define AXBS_LITE_PRS0_M2_SHIFT                  (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS0_M2(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS0_M2_SHIFT)) & AXBS_LITE_PRS0_M2_MASK)

#define AXBS_LITE_PRS0_M3_MASK                   (0x7000U)
#define AXBS_LITE_PRS0_M3_SHIFT                  (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS0_M3(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS0_M3_SHIFT)) & AXBS_LITE_PRS0_M3_MASK)
/*! @} */

/*! @name CRS0 - Control Register */
/*! @{ */

#define AXBS_LITE_CRS0_PARK_MASK                 (0x7U)
#define AXBS_LITE_CRS0_PARK_SHIFT                (0U)
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
#define AXBS_LITE_CRS0_PARK(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS0_PARK_SHIFT)) & AXBS_LITE_CRS0_PARK_MASK)

#define AXBS_LITE_CRS0_PCTL_MASK                 (0x30U)
#define AXBS_LITE_CRS0_PCTL_SHIFT                (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_LITE_CRS0_PCTL(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS0_PCTL_SHIFT)) & AXBS_LITE_CRS0_PCTL_MASK)

#define AXBS_LITE_CRS0_ARB_MASK                  (0x300U)
#define AXBS_LITE_CRS0_ARB_SHIFT                 (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_LITE_CRS0_ARB(x)                    (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS0_ARB_SHIFT)) & AXBS_LITE_CRS0_ARB_MASK)

#define AXBS_LITE_CRS0_HPE0_MASK                 (0x10000U)
#define AXBS_LITE_CRS0_HPE0_SHIFT                (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AXBS_LITE_CRS0_HPE0(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS0_HPE0_SHIFT)) & AXBS_LITE_CRS0_HPE0_MASK)

#define AXBS_LITE_CRS0_HPE1_MASK                 (0x20000U)
#define AXBS_LITE_CRS0_HPE1_SHIFT                (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AXBS_LITE_CRS0_HPE1(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS0_HPE1_SHIFT)) & AXBS_LITE_CRS0_HPE1_MASK)

#define AXBS_LITE_CRS0_HPE2_MASK                 (0x40000U)
#define AXBS_LITE_CRS0_HPE2_SHIFT                (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AXBS_LITE_CRS0_HPE2(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS0_HPE2_SHIFT)) & AXBS_LITE_CRS0_HPE2_MASK)

#define AXBS_LITE_CRS0_HPE3_MASK                 (0x80000U)
#define AXBS_LITE_CRS0_HPE3_SHIFT                (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AXBS_LITE_CRS0_HPE3(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS0_HPE3_SHIFT)) & AXBS_LITE_CRS0_HPE3_MASK)

#define AXBS_LITE_CRS0_HLP_MASK                  (0x40000000U)
#define AXBS_LITE_CRS0_HLP_SHIFT                 (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_LITE_CRS0_HLP(x)                    (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS0_HLP_SHIFT)) & AXBS_LITE_CRS0_HLP_MASK)

#define AXBS_LITE_CRS0_RO_MASK                   (0x80000000U)
#define AXBS_LITE_CRS0_RO_SHIFT                  (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AXBS_LITE_CRS0_RO(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS0_RO_SHIFT)) & AXBS_LITE_CRS0_RO_MASK)
/*! @} */

/*! @name PRS1 - Priority Slave Registers */
/*! @{ */

#define AXBS_LITE_PRS1_M0_MASK                   (0x7U)
#define AXBS_LITE_PRS1_M0_SHIFT                  (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS1_M0(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS1_M0_SHIFT)) & AXBS_LITE_PRS1_M0_MASK)

#define AXBS_LITE_PRS1_M1_MASK                   (0x70U)
#define AXBS_LITE_PRS1_M1_SHIFT                  (4U)
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
#define AXBS_LITE_PRS1_M1(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS1_M1_SHIFT)) & AXBS_LITE_PRS1_M1_MASK)

#define AXBS_LITE_PRS1_M2_MASK                   (0x700U)
#define AXBS_LITE_PRS1_M2_SHIFT                  (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS1_M2(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS1_M2_SHIFT)) & AXBS_LITE_PRS1_M2_MASK)

#define AXBS_LITE_PRS1_M3_MASK                   (0x7000U)
#define AXBS_LITE_PRS1_M3_SHIFT                  (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS1_M3(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS1_M3_SHIFT)) & AXBS_LITE_PRS1_M3_MASK)
/*! @} */

/*! @name CRS1 - Control Register */
/*! @{ */

#define AXBS_LITE_CRS1_PARK_MASK                 (0x7U)
#define AXBS_LITE_CRS1_PARK_SHIFT                (0U)
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
#define AXBS_LITE_CRS1_PARK(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS1_PARK_SHIFT)) & AXBS_LITE_CRS1_PARK_MASK)

#define AXBS_LITE_CRS1_PCTL_MASK                 (0x30U)
#define AXBS_LITE_CRS1_PCTL_SHIFT                (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_LITE_CRS1_PCTL(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS1_PCTL_SHIFT)) & AXBS_LITE_CRS1_PCTL_MASK)

#define AXBS_LITE_CRS1_ARB_MASK                  (0x300U)
#define AXBS_LITE_CRS1_ARB_SHIFT                 (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_LITE_CRS1_ARB(x)                    (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS1_ARB_SHIFT)) & AXBS_LITE_CRS1_ARB_MASK)

#define AXBS_LITE_CRS1_HPE0_MASK                 (0x10000U)
#define AXBS_LITE_CRS1_HPE0_SHIFT                (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AXBS_LITE_CRS1_HPE0(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS1_HPE0_SHIFT)) & AXBS_LITE_CRS1_HPE0_MASK)

#define AXBS_LITE_CRS1_HPE1_MASK                 (0x20000U)
#define AXBS_LITE_CRS1_HPE1_SHIFT                (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AXBS_LITE_CRS1_HPE1(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS1_HPE1_SHIFT)) & AXBS_LITE_CRS1_HPE1_MASK)

#define AXBS_LITE_CRS1_HPE2_MASK                 (0x40000U)
#define AXBS_LITE_CRS1_HPE2_SHIFT                (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AXBS_LITE_CRS1_HPE2(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS1_HPE2_SHIFT)) & AXBS_LITE_CRS1_HPE2_MASK)

#define AXBS_LITE_CRS1_HPE3_MASK                 (0x80000U)
#define AXBS_LITE_CRS1_HPE3_SHIFT                (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AXBS_LITE_CRS1_HPE3(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS1_HPE3_SHIFT)) & AXBS_LITE_CRS1_HPE3_MASK)

#define AXBS_LITE_CRS1_HLP_MASK                  (0x40000000U)
#define AXBS_LITE_CRS1_HLP_SHIFT                 (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_LITE_CRS1_HLP(x)                    (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS1_HLP_SHIFT)) & AXBS_LITE_CRS1_HLP_MASK)

#define AXBS_LITE_CRS1_RO_MASK                   (0x80000000U)
#define AXBS_LITE_CRS1_RO_SHIFT                  (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AXBS_LITE_CRS1_RO(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS1_RO_SHIFT)) & AXBS_LITE_CRS1_RO_MASK)
/*! @} */

/*! @name PRS2 - Priority Slave Registers */
/*! @{ */

#define AXBS_LITE_PRS2_M0_MASK                   (0x7U)
#define AXBS_LITE_PRS2_M0_SHIFT                  (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS2_M0(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS2_M0_SHIFT)) & AXBS_LITE_PRS2_M0_MASK)

#define AXBS_LITE_PRS2_M1_MASK                   (0x70U)
#define AXBS_LITE_PRS2_M1_SHIFT                  (4U)
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
#define AXBS_LITE_PRS2_M1(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS2_M1_SHIFT)) & AXBS_LITE_PRS2_M1_MASK)

#define AXBS_LITE_PRS2_M2_MASK                   (0x700U)
#define AXBS_LITE_PRS2_M2_SHIFT                  (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS2_M2(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS2_M2_SHIFT)) & AXBS_LITE_PRS2_M2_MASK)

#define AXBS_LITE_PRS2_M3_MASK                   (0x7000U)
#define AXBS_LITE_PRS2_M3_SHIFT                  (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS2_M3(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS2_M3_SHIFT)) & AXBS_LITE_PRS2_M3_MASK)
/*! @} */

/*! @name CRS2 - Control Register */
/*! @{ */

#define AXBS_LITE_CRS2_PARK_MASK                 (0x7U)
#define AXBS_LITE_CRS2_PARK_SHIFT                (0U)
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
#define AXBS_LITE_CRS2_PARK(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS2_PARK_SHIFT)) & AXBS_LITE_CRS2_PARK_MASK)

#define AXBS_LITE_CRS2_PCTL_MASK                 (0x30U)
#define AXBS_LITE_CRS2_PCTL_SHIFT                (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_LITE_CRS2_PCTL(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS2_PCTL_SHIFT)) & AXBS_LITE_CRS2_PCTL_MASK)

#define AXBS_LITE_CRS2_ARB_MASK                  (0x300U)
#define AXBS_LITE_CRS2_ARB_SHIFT                 (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_LITE_CRS2_ARB(x)                    (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS2_ARB_SHIFT)) & AXBS_LITE_CRS2_ARB_MASK)

#define AXBS_LITE_CRS2_HPE0_MASK                 (0x10000U)
#define AXBS_LITE_CRS2_HPE0_SHIFT                (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AXBS_LITE_CRS2_HPE0(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS2_HPE0_SHIFT)) & AXBS_LITE_CRS2_HPE0_MASK)

#define AXBS_LITE_CRS2_HPE1_MASK                 (0x20000U)
#define AXBS_LITE_CRS2_HPE1_SHIFT                (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AXBS_LITE_CRS2_HPE1(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS2_HPE1_SHIFT)) & AXBS_LITE_CRS2_HPE1_MASK)

#define AXBS_LITE_CRS2_HPE2_MASK                 (0x40000U)
#define AXBS_LITE_CRS2_HPE2_SHIFT                (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AXBS_LITE_CRS2_HPE2(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS2_HPE2_SHIFT)) & AXBS_LITE_CRS2_HPE2_MASK)

#define AXBS_LITE_CRS2_HPE3_MASK                 (0x80000U)
#define AXBS_LITE_CRS2_HPE3_SHIFT                (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AXBS_LITE_CRS2_HPE3(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS2_HPE3_SHIFT)) & AXBS_LITE_CRS2_HPE3_MASK)

#define AXBS_LITE_CRS2_HLP_MASK                  (0x40000000U)
#define AXBS_LITE_CRS2_HLP_SHIFT                 (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_LITE_CRS2_HLP(x)                    (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS2_HLP_SHIFT)) & AXBS_LITE_CRS2_HLP_MASK)

#define AXBS_LITE_CRS2_RO_MASK                   (0x80000000U)
#define AXBS_LITE_CRS2_RO_SHIFT                  (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AXBS_LITE_CRS2_RO(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS2_RO_SHIFT)) & AXBS_LITE_CRS2_RO_MASK)
/*! @} */

/*! @name PRS3 - Priority Slave Registers */
/*! @{ */

#define AXBS_LITE_PRS3_M0_MASK                   (0x7U)
#define AXBS_LITE_PRS3_M0_SHIFT                  (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS3_M0(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS3_M0_SHIFT)) & AXBS_LITE_PRS3_M0_MASK)

#define AXBS_LITE_PRS3_M1_MASK                   (0x70U)
#define AXBS_LITE_PRS3_M1_SHIFT                  (4U)
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
#define AXBS_LITE_PRS3_M1(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS3_M1_SHIFT)) & AXBS_LITE_PRS3_M1_MASK)

#define AXBS_LITE_PRS3_M2_MASK                   (0x700U)
#define AXBS_LITE_PRS3_M2_SHIFT                  (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS3_M2(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS3_M2_SHIFT)) & AXBS_LITE_PRS3_M2_MASK)

#define AXBS_LITE_PRS3_M3_MASK                   (0x7000U)
#define AXBS_LITE_PRS3_M3_SHIFT                  (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS3_M3(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS3_M3_SHIFT)) & AXBS_LITE_PRS3_M3_MASK)
/*! @} */

/*! @name CRS3 - Control Register */
/*! @{ */

#define AXBS_LITE_CRS3_PARK_MASK                 (0x7U)
#define AXBS_LITE_CRS3_PARK_SHIFT                (0U)
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
#define AXBS_LITE_CRS3_PARK(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS3_PARK_SHIFT)) & AXBS_LITE_CRS3_PARK_MASK)

#define AXBS_LITE_CRS3_PCTL_MASK                 (0x30U)
#define AXBS_LITE_CRS3_PCTL_SHIFT                (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_LITE_CRS3_PCTL(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS3_PCTL_SHIFT)) & AXBS_LITE_CRS3_PCTL_MASK)

#define AXBS_LITE_CRS3_ARB_MASK                  (0x300U)
#define AXBS_LITE_CRS3_ARB_SHIFT                 (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_LITE_CRS3_ARB(x)                    (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS3_ARB_SHIFT)) & AXBS_LITE_CRS3_ARB_MASK)

#define AXBS_LITE_CRS3_HPE0_MASK                 (0x10000U)
#define AXBS_LITE_CRS3_HPE0_SHIFT                (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AXBS_LITE_CRS3_HPE0(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS3_HPE0_SHIFT)) & AXBS_LITE_CRS3_HPE0_MASK)

#define AXBS_LITE_CRS3_HPE1_MASK                 (0x20000U)
#define AXBS_LITE_CRS3_HPE1_SHIFT                (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AXBS_LITE_CRS3_HPE1(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS3_HPE1_SHIFT)) & AXBS_LITE_CRS3_HPE1_MASK)

#define AXBS_LITE_CRS3_HPE2_MASK                 (0x40000U)
#define AXBS_LITE_CRS3_HPE2_SHIFT                (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AXBS_LITE_CRS3_HPE2(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS3_HPE2_SHIFT)) & AXBS_LITE_CRS3_HPE2_MASK)

#define AXBS_LITE_CRS3_HPE3_MASK                 (0x80000U)
#define AXBS_LITE_CRS3_HPE3_SHIFT                (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AXBS_LITE_CRS3_HPE3(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS3_HPE3_SHIFT)) & AXBS_LITE_CRS3_HPE3_MASK)

#define AXBS_LITE_CRS3_HLP_MASK                  (0x40000000U)
#define AXBS_LITE_CRS3_HLP_SHIFT                 (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_LITE_CRS3_HLP(x)                    (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS3_HLP_SHIFT)) & AXBS_LITE_CRS3_HLP_MASK)

#define AXBS_LITE_CRS3_RO_MASK                   (0x80000000U)
#define AXBS_LITE_CRS3_RO_SHIFT                  (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AXBS_LITE_CRS3_RO(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS3_RO_SHIFT)) & AXBS_LITE_CRS3_RO_MASK)
/*! @} */

/*! @name PRS4 - Priority Slave Registers */
/*! @{ */

#define AXBS_LITE_PRS4_M0_MASK                   (0x7U)
#define AXBS_LITE_PRS4_M0_SHIFT                  (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS4_M0(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS4_M0_SHIFT)) & AXBS_LITE_PRS4_M0_MASK)

#define AXBS_LITE_PRS4_M1_MASK                   (0x70U)
#define AXBS_LITE_PRS4_M1_SHIFT                  (4U)
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
#define AXBS_LITE_PRS4_M1(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS4_M1_SHIFT)) & AXBS_LITE_PRS4_M1_MASK)

#define AXBS_LITE_PRS4_M2_MASK                   (0x700U)
#define AXBS_LITE_PRS4_M2_SHIFT                  (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS4_M2(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS4_M2_SHIFT)) & AXBS_LITE_PRS4_M2_MASK)

#define AXBS_LITE_PRS4_M3_MASK                   (0x7000U)
#define AXBS_LITE_PRS4_M3_SHIFT                  (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS4_M3(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS4_M3_SHIFT)) & AXBS_LITE_PRS4_M3_MASK)
/*! @} */

/*! @name CRS4 - Control Register */
/*! @{ */

#define AXBS_LITE_CRS4_PARK_MASK                 (0x7U)
#define AXBS_LITE_CRS4_PARK_SHIFT                (0U)
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
#define AXBS_LITE_CRS4_PARK(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS4_PARK_SHIFT)) & AXBS_LITE_CRS4_PARK_MASK)

#define AXBS_LITE_CRS4_PCTL_MASK                 (0x30U)
#define AXBS_LITE_CRS4_PCTL_SHIFT                (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_LITE_CRS4_PCTL(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS4_PCTL_SHIFT)) & AXBS_LITE_CRS4_PCTL_MASK)

#define AXBS_LITE_CRS4_ARB_MASK                  (0x300U)
#define AXBS_LITE_CRS4_ARB_SHIFT                 (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_LITE_CRS4_ARB(x)                    (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS4_ARB_SHIFT)) & AXBS_LITE_CRS4_ARB_MASK)

#define AXBS_LITE_CRS4_HPE0_MASK                 (0x10000U)
#define AXBS_LITE_CRS4_HPE0_SHIFT                (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AXBS_LITE_CRS4_HPE0(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS4_HPE0_SHIFT)) & AXBS_LITE_CRS4_HPE0_MASK)

#define AXBS_LITE_CRS4_HPE1_MASK                 (0x20000U)
#define AXBS_LITE_CRS4_HPE1_SHIFT                (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AXBS_LITE_CRS4_HPE1(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS4_HPE1_SHIFT)) & AXBS_LITE_CRS4_HPE1_MASK)

#define AXBS_LITE_CRS4_HPE2_MASK                 (0x40000U)
#define AXBS_LITE_CRS4_HPE2_SHIFT                (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AXBS_LITE_CRS4_HPE2(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS4_HPE2_SHIFT)) & AXBS_LITE_CRS4_HPE2_MASK)

#define AXBS_LITE_CRS4_HPE3_MASK                 (0x80000U)
#define AXBS_LITE_CRS4_HPE3_SHIFT                (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AXBS_LITE_CRS4_HPE3(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS4_HPE3_SHIFT)) & AXBS_LITE_CRS4_HPE3_MASK)

#define AXBS_LITE_CRS4_HLP_MASK                  (0x40000000U)
#define AXBS_LITE_CRS4_HLP_SHIFT                 (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_LITE_CRS4_HLP(x)                    (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS4_HLP_SHIFT)) & AXBS_LITE_CRS4_HLP_MASK)

#define AXBS_LITE_CRS4_RO_MASK                   (0x80000000U)
#define AXBS_LITE_CRS4_RO_SHIFT                  (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AXBS_LITE_CRS4_RO(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS4_RO_SHIFT)) & AXBS_LITE_CRS4_RO_MASK)
/*! @} */

/*! @name PRS5 - Priority Slave Registers */
/*! @{ */

#define AXBS_LITE_PRS5_M0_MASK                   (0x7U)
#define AXBS_LITE_PRS5_M0_SHIFT                  (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS5_M0(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS5_M0_SHIFT)) & AXBS_LITE_PRS5_M0_MASK)

#define AXBS_LITE_PRS5_M1_MASK                   (0x70U)
#define AXBS_LITE_PRS5_M1_SHIFT                  (4U)
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
#define AXBS_LITE_PRS5_M1(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS5_M1_SHIFT)) & AXBS_LITE_PRS5_M1_MASK)

#define AXBS_LITE_PRS5_M2_MASK                   (0x700U)
#define AXBS_LITE_PRS5_M2_SHIFT                  (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS5_M2(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS5_M2_SHIFT)) & AXBS_LITE_PRS5_M2_MASK)

#define AXBS_LITE_PRS5_M3_MASK                   (0x7000U)
#define AXBS_LITE_PRS5_M3_SHIFT                  (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS5_M3(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS5_M3_SHIFT)) & AXBS_LITE_PRS5_M3_MASK)
/*! @} */

/*! @name CRS5 - Control Register */
/*! @{ */

#define AXBS_LITE_CRS5_PARK_MASK                 (0x7U)
#define AXBS_LITE_CRS5_PARK_SHIFT                (0U)
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
#define AXBS_LITE_CRS5_PARK(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS5_PARK_SHIFT)) & AXBS_LITE_CRS5_PARK_MASK)

#define AXBS_LITE_CRS5_PCTL_MASK                 (0x30U)
#define AXBS_LITE_CRS5_PCTL_SHIFT                (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_LITE_CRS5_PCTL(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS5_PCTL_SHIFT)) & AXBS_LITE_CRS5_PCTL_MASK)

#define AXBS_LITE_CRS5_ARB_MASK                  (0x300U)
#define AXBS_LITE_CRS5_ARB_SHIFT                 (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_LITE_CRS5_ARB(x)                    (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS5_ARB_SHIFT)) & AXBS_LITE_CRS5_ARB_MASK)

#define AXBS_LITE_CRS5_HPE0_MASK                 (0x10000U)
#define AXBS_LITE_CRS5_HPE0_SHIFT                (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AXBS_LITE_CRS5_HPE0(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS5_HPE0_SHIFT)) & AXBS_LITE_CRS5_HPE0_MASK)

#define AXBS_LITE_CRS5_HPE1_MASK                 (0x20000U)
#define AXBS_LITE_CRS5_HPE1_SHIFT                (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AXBS_LITE_CRS5_HPE1(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS5_HPE1_SHIFT)) & AXBS_LITE_CRS5_HPE1_MASK)

#define AXBS_LITE_CRS5_HPE2_MASK                 (0x40000U)
#define AXBS_LITE_CRS5_HPE2_SHIFT                (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AXBS_LITE_CRS5_HPE2(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS5_HPE2_SHIFT)) & AXBS_LITE_CRS5_HPE2_MASK)

#define AXBS_LITE_CRS5_HPE3_MASK                 (0x80000U)
#define AXBS_LITE_CRS5_HPE3_SHIFT                (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AXBS_LITE_CRS5_HPE3(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS5_HPE3_SHIFT)) & AXBS_LITE_CRS5_HPE3_MASK)

#define AXBS_LITE_CRS5_HLP_MASK                  (0x40000000U)
#define AXBS_LITE_CRS5_HLP_SHIFT                 (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_LITE_CRS5_HLP(x)                    (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS5_HLP_SHIFT)) & AXBS_LITE_CRS5_HLP_MASK)

#define AXBS_LITE_CRS5_RO_MASK                   (0x80000000U)
#define AXBS_LITE_CRS5_RO_SHIFT                  (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AXBS_LITE_CRS5_RO(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS5_RO_SHIFT)) & AXBS_LITE_CRS5_RO_MASK)
/*! @} */

/*! @name PRS6 - Priority Slave Registers */
/*! @{ */

#define AXBS_LITE_PRS6_M0_MASK                   (0x7U)
#define AXBS_LITE_PRS6_M0_SHIFT                  (0U)
/*! M0 - Master 0 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS6_M0(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS6_M0_SHIFT)) & AXBS_LITE_PRS6_M0_MASK)

#define AXBS_LITE_PRS6_M1_MASK                   (0x70U)
#define AXBS_LITE_PRS6_M1_SHIFT                  (4U)
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
#define AXBS_LITE_PRS6_M1(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS6_M1_SHIFT)) & AXBS_LITE_PRS6_M1_MASK)

#define AXBS_LITE_PRS6_M2_MASK                   (0x700U)
#define AXBS_LITE_PRS6_M2_SHIFT                  (8U)
/*! M2 - Master 2 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS6_M2(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS6_M2_SHIFT)) & AXBS_LITE_PRS6_M2_MASK)

#define AXBS_LITE_PRS6_M3_MASK                   (0x7000U)
#define AXBS_LITE_PRS6_M3_SHIFT                  (12U)
/*! M3 - Master 3 Priority
 *  0b000..This master has level 1 or highest priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8 or lowest priority when accessing the slave port.
 */
#define AXBS_LITE_PRS6_M3(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_PRS6_M3_SHIFT)) & AXBS_LITE_PRS6_M3_MASK)
/*! @} */

/*! @name CRS6 - Control Register */
/*! @{ */

#define AXBS_LITE_CRS6_PARK_MASK                 (0x7U)
#define AXBS_LITE_CRS6_PARK_SHIFT                (0U)
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
#define AXBS_LITE_CRS6_PARK(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS6_PARK_SHIFT)) & AXBS_LITE_CRS6_PARK_MASK)

#define AXBS_LITE_CRS6_PCTL_MASK                 (0x30U)
#define AXBS_LITE_CRS6_PCTL_SHIFT                (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK bit field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..Low-power park. When no master makes a request, the slave port is not parked on a master and the arbiter
 *        drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_LITE_CRS6_PCTL(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS6_PCTL_SHIFT)) & AXBS_LITE_CRS6_PCTL_MASK)

#define AXBS_LITE_CRS6_ARB_MASK                  (0x300U)
#define AXBS_LITE_CRS6_ARB_SHIFT                 (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_LITE_CRS6_ARB(x)                    (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS6_ARB_SHIFT)) & AXBS_LITE_CRS6_ARB_MASK)

#define AXBS_LITE_CRS6_HPE0_MASK                 (0x10000U)
#define AXBS_LITE_CRS6_HPE0_SHIFT                (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Master high-priority elevation for master 0. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 0. is enabled on this slave port.
 */
#define AXBS_LITE_CRS6_HPE0(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS6_HPE0_SHIFT)) & AXBS_LITE_CRS6_HPE0_MASK)

#define AXBS_LITE_CRS6_HPE1_MASK                 (0x20000U)
#define AXBS_LITE_CRS6_HPE1_SHIFT                (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Master high-priority elevation for master 1. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 1. is enabled on this slave port.
 */
#define AXBS_LITE_CRS6_HPE1(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS6_HPE1_SHIFT)) & AXBS_LITE_CRS6_HPE1_MASK)

#define AXBS_LITE_CRS6_HPE2_MASK                 (0x40000U)
#define AXBS_LITE_CRS6_HPE2_SHIFT                (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Master high-priority elevation for master 2. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 2. is enabled on this slave port.
 */
#define AXBS_LITE_CRS6_HPE2(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS6_HPE2_SHIFT)) & AXBS_LITE_CRS6_HPE2_MASK)

#define AXBS_LITE_CRS6_HPE3_MASK                 (0x80000U)
#define AXBS_LITE_CRS6_HPE3_SHIFT                (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Master high-priority elevation for master 3. is disabled on this slave port.
 *  0b1..Master high-priority elevation for master 3. is enabled on this slave port.
 */
#define AXBS_LITE_CRS6_HPE3(x)                   (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS6_HPE3_SHIFT)) & AXBS_LITE_CRS6_HPE3_MASK)

#define AXBS_LITE_CRS6_HLP_MASK                  (0x40000000U)
#define AXBS_LITE_CRS6_HLP_SHIFT                 (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_LITE_CRS6_HLP(x)                    (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS6_HLP_SHIFT)) & AXBS_LITE_CRS6_HLP_MASK)

#define AXBS_LITE_CRS6_RO_MASK                   (0x80000000U)
#define AXBS_LITE_CRS6_RO_SHIFT                  (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AXBS_LITE_CRS6_RO(x)                     (((uint32_t)(((uint32_t)(x)) << AXBS_LITE_CRS6_RO_SHIFT)) & AXBS_LITE_CRS6_RO_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AXBS_LITE_Register_Masks */


/*!
 * @}
 */ /* end of group AXBS_LITE_Peripheral_Access_Layer */


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


#endif  /* PERI_AXBS_LITE_H_ */

