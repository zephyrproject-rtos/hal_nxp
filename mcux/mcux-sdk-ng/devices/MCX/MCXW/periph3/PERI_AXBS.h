/*
** ###################################################################
**     Processors:          MCXW727AMFTA_cm33_core0
**                          MCXW727AMFTA_cm33_core1
**                          MCXW727CMFTA_cm33_core0
**                          MCXW727CMFTA_cm33_core1
**                          MCXW727DMFTA_cm33_core0
**                          MCXW727DMFTA_cm33_core1
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250522
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AXBS
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-10-13)
**         Rev. 1, 2024-10-13
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_AXBS.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AXBS
 *
 * CMSIS Peripheral Access Layer for AXBS
 */

#if !defined(PERI_AXBS_H_)
#define PERI_AXBS_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW727AMFTA_cm33_core0))
#include "MCXW727A_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727AMFTA_cm33_core1))
#include "MCXW727A_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXW727CMFTA_cm33_core0))
#include "MCXW727C_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727CMFTA_cm33_core1))
#include "MCXW727C_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXW727DMFTA_cm33_core0))
#include "MCXW727D_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727DMFTA_cm33_core1))
#include "MCXW727D_cm33_core1_COMMON.h"
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
   -- AXBS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AXBS_Peripheral_Access_Layer AXBS Peripheral Access Layer
 * @{
 */

/** AXBS - Register Layout Typedef */
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
} AXBS_Type;

/* ----------------------------------------------------------------------------
   -- AXBS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AXBS_Register_Masks AXBS Register Masks
 * @{
 */

/*! @name PRS0 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS0_M0_MASK                        (0x7U)
#define AXBS_PRS0_M0_SHIFT                       (0U)
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
#define AXBS_PRS0_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS0_M0_SHIFT)) & AXBS_PRS0_M0_MASK)

#define AXBS_PRS0_M1_MASK                        (0x70U)
#define AXBS_PRS0_M1_SHIFT                       (4U)
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
#define AXBS_PRS0_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS0_M1_SHIFT)) & AXBS_PRS0_M1_MASK)

#define AXBS_PRS0_M2_MASK                        (0x700U)
#define AXBS_PRS0_M2_SHIFT                       (8U)
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
#define AXBS_PRS0_M2(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS0_M2_SHIFT)) & AXBS_PRS0_M2_MASK)

#define AXBS_PRS0_M3_MASK                        (0x7000U)
#define AXBS_PRS0_M3_SHIFT                       (12U)
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
#define AXBS_PRS0_M3(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS0_M3_SHIFT)) & AXBS_PRS0_M3_MASK)

#define AXBS_PRS0_M4_MASK                        (0x70000U)
#define AXBS_PRS0_M4_SHIFT                       (16U)
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
#define AXBS_PRS0_M4(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS0_M4_SHIFT)) & AXBS_PRS0_M4_MASK)

#define AXBS_PRS0_M5_MASK                        (0x700000U)
#define AXBS_PRS0_M5_SHIFT                       (20U)
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
#define AXBS_PRS0_M5(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS0_M5_SHIFT)) & AXBS_PRS0_M5_MASK)

#define AXBS_PRS0_M6_MASK                        (0x7000000U)
#define AXBS_PRS0_M6_SHIFT                       (24U)
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
#define AXBS_PRS0_M6(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS0_M6_SHIFT)) & AXBS_PRS0_M6_MASK)
/*! @} */

/*! @name CRS0 - Control Register */
/*! @{ */

#define AXBS_CRS0_PARK_MASK                      (0x7U)
#define AXBS_CRS0_PARK_SHIFT                     (0U)
/*! PARK - Park
 *  0b000..Park on master port M0.
 *  0b001..Park on master port M1.
 *  0b010..Park on master port M2.
 *  0b011..Park on master port M3.
 *  0b100..Park on master port M4.
 *  0b101..Park on master port M5.
 *  0b110..Park on master port M6.
 *  0b111..Park on master port M7.
 */
#define AXBS_CRS0_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS0_PARK_SHIFT)) & AXBS_CRS0_PARK_MASK)

#define AXBS_CRS0_PCTL_MASK                      (0x30U)
#define AXBS_CRS0_PCTL_SHIFT                     (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..When no master makes a request, the slave port is not parked on a master and the arbiter drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_CRS0_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS0_PCTL_SHIFT)) & AXBS_CRS0_PCTL_MASK)

#define AXBS_CRS0_ARB_MASK                       (0x300U)
#define AXBS_CRS0_ARB_SHIFT                      (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin(RR) or rotating priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_CRS0_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS0_ARB_SHIFT)) & AXBS_CRS0_ARB_MASK)

#define AXBS_CRS0_HLP_MASK                       (0x40000000U)
#define AXBS_CRS0_HLP_SHIFT                      (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_CRS0_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS0_HLP_SHIFT)) & AXBS_CRS0_HLP_MASK)

#define AXBS_CRS0_RO_MASK                        (0x80000000U)
#define AXBS_CRS0_RO_SHIFT                       (31U)
/*! RO - Read Only
 *  0b0..The slave port's registers are writeable.
 *  0b1..The slave port's registers are read-only and cannot be written. Attempted writes do not affect the
 *       registers and result in a bus error response.
 */
#define AXBS_CRS0_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS0_RO_SHIFT)) & AXBS_CRS0_RO_MASK)
/*! @} */

/*! @name PRS1 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS1_M0_MASK                        (0x7U)
#define AXBS_PRS1_M0_SHIFT                       (0U)
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
#define AXBS_PRS1_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS1_M0_SHIFT)) & AXBS_PRS1_M0_MASK)

#define AXBS_PRS1_M1_MASK                        (0x70U)
#define AXBS_PRS1_M1_SHIFT                       (4U)
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
#define AXBS_PRS1_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS1_M1_SHIFT)) & AXBS_PRS1_M1_MASK)

#define AXBS_PRS1_M2_MASK                        (0x700U)
#define AXBS_PRS1_M2_SHIFT                       (8U)
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
#define AXBS_PRS1_M2(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS1_M2_SHIFT)) & AXBS_PRS1_M2_MASK)

#define AXBS_PRS1_M3_MASK                        (0x7000U)
#define AXBS_PRS1_M3_SHIFT                       (12U)
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
#define AXBS_PRS1_M3(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS1_M3_SHIFT)) & AXBS_PRS1_M3_MASK)

#define AXBS_PRS1_M4_MASK                        (0x70000U)
#define AXBS_PRS1_M4_SHIFT                       (16U)
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
#define AXBS_PRS1_M4(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS1_M4_SHIFT)) & AXBS_PRS1_M4_MASK)

#define AXBS_PRS1_M5_MASK                        (0x700000U)
#define AXBS_PRS1_M5_SHIFT                       (20U)
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
#define AXBS_PRS1_M5(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS1_M5_SHIFT)) & AXBS_PRS1_M5_MASK)

#define AXBS_PRS1_M6_MASK                        (0x7000000U)
#define AXBS_PRS1_M6_SHIFT                       (24U)
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
#define AXBS_PRS1_M6(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS1_M6_SHIFT)) & AXBS_PRS1_M6_MASK)
/*! @} */

/*! @name CRS1 - Control Register */
/*! @{ */

#define AXBS_CRS1_PARK_MASK                      (0x7U)
#define AXBS_CRS1_PARK_SHIFT                     (0U)
/*! PARK - Park
 *  0b000..Park on master port M0.
 *  0b001..Park on master port M1.
 *  0b010..Park on master port M2.
 *  0b011..Park on master port M3.
 *  0b100..Park on master port M4.
 *  0b101..Park on master port M5.
 *  0b110..Park on master port M6.
 *  0b111..Park on master port M7.
 */
#define AXBS_CRS1_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS1_PARK_SHIFT)) & AXBS_CRS1_PARK_MASK)

#define AXBS_CRS1_PCTL_MASK                      (0x30U)
#define AXBS_CRS1_PCTL_SHIFT                     (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..When no master makes a request, the slave port is not parked on a master and the arbiter drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_CRS1_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS1_PCTL_SHIFT)) & AXBS_CRS1_PCTL_MASK)

#define AXBS_CRS1_ARB_MASK                       (0x300U)
#define AXBS_CRS1_ARB_SHIFT                      (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin(RR) or rotating priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_CRS1_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS1_ARB_SHIFT)) & AXBS_CRS1_ARB_MASK)

#define AXBS_CRS1_HLP_MASK                       (0x40000000U)
#define AXBS_CRS1_HLP_SHIFT                      (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_CRS1_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS1_HLP_SHIFT)) & AXBS_CRS1_HLP_MASK)

#define AXBS_CRS1_RO_MASK                        (0x80000000U)
#define AXBS_CRS1_RO_SHIFT                       (31U)
/*! RO - Read Only
 *  0b0..The slave port's registers are writeable.
 *  0b1..The slave port's registers are read-only and cannot be written. Attempted writes do not affect the
 *       registers and result in a bus error response.
 */
#define AXBS_CRS1_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS1_RO_SHIFT)) & AXBS_CRS1_RO_MASK)
/*! @} */

/*! @name PRS2 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS2_M0_MASK                        (0x7U)
#define AXBS_PRS2_M0_SHIFT                       (0U)
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
#define AXBS_PRS2_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS2_M0_SHIFT)) & AXBS_PRS2_M0_MASK)

#define AXBS_PRS2_M1_MASK                        (0x70U)
#define AXBS_PRS2_M1_SHIFT                       (4U)
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
#define AXBS_PRS2_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS2_M1_SHIFT)) & AXBS_PRS2_M1_MASK)

#define AXBS_PRS2_M2_MASK                        (0x700U)
#define AXBS_PRS2_M2_SHIFT                       (8U)
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
#define AXBS_PRS2_M2(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS2_M2_SHIFT)) & AXBS_PRS2_M2_MASK)

#define AXBS_PRS2_M3_MASK                        (0x7000U)
#define AXBS_PRS2_M3_SHIFT                       (12U)
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
#define AXBS_PRS2_M3(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS2_M3_SHIFT)) & AXBS_PRS2_M3_MASK)

#define AXBS_PRS2_M4_MASK                        (0x70000U)
#define AXBS_PRS2_M4_SHIFT                       (16U)
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
#define AXBS_PRS2_M4(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS2_M4_SHIFT)) & AXBS_PRS2_M4_MASK)

#define AXBS_PRS2_M5_MASK                        (0x700000U)
#define AXBS_PRS2_M5_SHIFT                       (20U)
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
#define AXBS_PRS2_M5(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS2_M5_SHIFT)) & AXBS_PRS2_M5_MASK)

#define AXBS_PRS2_M6_MASK                        (0x7000000U)
#define AXBS_PRS2_M6_SHIFT                       (24U)
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
#define AXBS_PRS2_M6(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS2_M6_SHIFT)) & AXBS_PRS2_M6_MASK)
/*! @} */

/*! @name CRS2 - Control Register */
/*! @{ */

#define AXBS_CRS2_PARK_MASK                      (0x7U)
#define AXBS_CRS2_PARK_SHIFT                     (0U)
/*! PARK - Park
 *  0b000..Park on master port M0.
 *  0b001..Park on master port M1.
 *  0b010..Park on master port M2.
 *  0b011..Park on master port M3.
 *  0b100..Park on master port M4.
 *  0b101..Park on master port M5.
 *  0b110..Park on master port M6.
 *  0b111..Park on master port M7.
 */
#define AXBS_CRS2_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS2_PARK_SHIFT)) & AXBS_CRS2_PARK_MASK)

#define AXBS_CRS2_PCTL_MASK                      (0x30U)
#define AXBS_CRS2_PCTL_SHIFT                     (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..When no master makes a request, the slave port is not parked on a master and the arbiter drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_CRS2_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS2_PCTL_SHIFT)) & AXBS_CRS2_PCTL_MASK)

#define AXBS_CRS2_ARB_MASK                       (0x300U)
#define AXBS_CRS2_ARB_SHIFT                      (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin(RR) or rotating priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_CRS2_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS2_ARB_SHIFT)) & AXBS_CRS2_ARB_MASK)

#define AXBS_CRS2_HLP_MASK                       (0x40000000U)
#define AXBS_CRS2_HLP_SHIFT                      (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_CRS2_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS2_HLP_SHIFT)) & AXBS_CRS2_HLP_MASK)

#define AXBS_CRS2_RO_MASK                        (0x80000000U)
#define AXBS_CRS2_RO_SHIFT                       (31U)
/*! RO - Read Only
 *  0b0..The slave port's registers are writeable.
 *  0b1..The slave port's registers are read-only and cannot be written. Attempted writes do not affect the
 *       registers and result in a bus error response.
 */
#define AXBS_CRS2_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS2_RO_SHIFT)) & AXBS_CRS2_RO_MASK)
/*! @} */

/*! @name PRS3 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS3_M0_MASK                        (0x7U)
#define AXBS_PRS3_M0_SHIFT                       (0U)
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
#define AXBS_PRS3_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS3_M0_SHIFT)) & AXBS_PRS3_M0_MASK)

#define AXBS_PRS3_M1_MASK                        (0x70U)
#define AXBS_PRS3_M1_SHIFT                       (4U)
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
#define AXBS_PRS3_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS3_M1_SHIFT)) & AXBS_PRS3_M1_MASK)

#define AXBS_PRS3_M2_MASK                        (0x700U)
#define AXBS_PRS3_M2_SHIFT                       (8U)
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
#define AXBS_PRS3_M2(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS3_M2_SHIFT)) & AXBS_PRS3_M2_MASK)

#define AXBS_PRS3_M3_MASK                        (0x7000U)
#define AXBS_PRS3_M3_SHIFT                       (12U)
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
#define AXBS_PRS3_M3(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS3_M3_SHIFT)) & AXBS_PRS3_M3_MASK)

#define AXBS_PRS3_M4_MASK                        (0x70000U)
#define AXBS_PRS3_M4_SHIFT                       (16U)
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
#define AXBS_PRS3_M4(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS3_M4_SHIFT)) & AXBS_PRS3_M4_MASK)

#define AXBS_PRS3_M5_MASK                        (0x700000U)
#define AXBS_PRS3_M5_SHIFT                       (20U)
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
#define AXBS_PRS3_M5(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS3_M5_SHIFT)) & AXBS_PRS3_M5_MASK)

#define AXBS_PRS3_M6_MASK                        (0x7000000U)
#define AXBS_PRS3_M6_SHIFT                       (24U)
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
#define AXBS_PRS3_M6(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS3_M6_SHIFT)) & AXBS_PRS3_M6_MASK)
/*! @} */

/*! @name CRS3 - Control Register */
/*! @{ */

#define AXBS_CRS3_PARK_MASK                      (0x7U)
#define AXBS_CRS3_PARK_SHIFT                     (0U)
/*! PARK - Park
 *  0b000..Park on master port M0.
 *  0b001..Park on master port M1.
 *  0b010..Park on master port M2.
 *  0b011..Park on master port M3.
 *  0b100..Park on master port M4.
 *  0b101..Park on master port M5.
 *  0b110..Park on master port M6.
 *  0b111..Park on master port M7.
 */
#define AXBS_CRS3_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS3_PARK_SHIFT)) & AXBS_CRS3_PARK_MASK)

#define AXBS_CRS3_PCTL_MASK                      (0x30U)
#define AXBS_CRS3_PCTL_SHIFT                     (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..When no master makes a request, the slave port is not parked on a master and the arbiter drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_CRS3_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS3_PCTL_SHIFT)) & AXBS_CRS3_PCTL_MASK)

#define AXBS_CRS3_ARB_MASK                       (0x300U)
#define AXBS_CRS3_ARB_SHIFT                      (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin(RR) or rotating priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_CRS3_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS3_ARB_SHIFT)) & AXBS_CRS3_ARB_MASK)

#define AXBS_CRS3_HLP_MASK                       (0x40000000U)
#define AXBS_CRS3_HLP_SHIFT                      (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_CRS3_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS3_HLP_SHIFT)) & AXBS_CRS3_HLP_MASK)

#define AXBS_CRS3_RO_MASK                        (0x80000000U)
#define AXBS_CRS3_RO_SHIFT                       (31U)
/*! RO - Read Only
 *  0b0..The slave port's registers are writeable.
 *  0b1..The slave port's registers are read-only and cannot be written. Attempted writes do not affect the
 *       registers and result in a bus error response.
 */
#define AXBS_CRS3_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS3_RO_SHIFT)) & AXBS_CRS3_RO_MASK)
/*! @} */

/*! @name PRS4 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS4_M0_MASK                        (0x7U)
#define AXBS_PRS4_M0_SHIFT                       (0U)
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
#define AXBS_PRS4_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS4_M0_SHIFT)) & AXBS_PRS4_M0_MASK)

#define AXBS_PRS4_M1_MASK                        (0x70U)
#define AXBS_PRS4_M1_SHIFT                       (4U)
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
#define AXBS_PRS4_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS4_M1_SHIFT)) & AXBS_PRS4_M1_MASK)

#define AXBS_PRS4_M2_MASK                        (0x700U)
#define AXBS_PRS4_M2_SHIFT                       (8U)
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
#define AXBS_PRS4_M2(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS4_M2_SHIFT)) & AXBS_PRS4_M2_MASK)

#define AXBS_PRS4_M3_MASK                        (0x7000U)
#define AXBS_PRS4_M3_SHIFT                       (12U)
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
#define AXBS_PRS4_M3(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS4_M3_SHIFT)) & AXBS_PRS4_M3_MASK)

#define AXBS_PRS4_M4_MASK                        (0x70000U)
#define AXBS_PRS4_M4_SHIFT                       (16U)
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
#define AXBS_PRS4_M4(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS4_M4_SHIFT)) & AXBS_PRS4_M4_MASK)

#define AXBS_PRS4_M5_MASK                        (0x700000U)
#define AXBS_PRS4_M5_SHIFT                       (20U)
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
#define AXBS_PRS4_M5(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS4_M5_SHIFT)) & AXBS_PRS4_M5_MASK)

#define AXBS_PRS4_M6_MASK                        (0x7000000U)
#define AXBS_PRS4_M6_SHIFT                       (24U)
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
#define AXBS_PRS4_M6(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS4_M6_SHIFT)) & AXBS_PRS4_M6_MASK)
/*! @} */

/*! @name CRS4 - Control Register */
/*! @{ */

#define AXBS_CRS4_PARK_MASK                      (0x7U)
#define AXBS_CRS4_PARK_SHIFT                     (0U)
/*! PARK - Park
 *  0b000..Park on master port M0.
 *  0b001..Park on master port M1.
 *  0b010..Park on master port M2.
 *  0b011..Park on master port M3.
 *  0b100..Park on master port M4.
 *  0b101..Park on master port M5.
 *  0b110..Park on master port M6.
 *  0b111..Park on master port M7.
 */
#define AXBS_CRS4_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS4_PARK_SHIFT)) & AXBS_CRS4_PARK_MASK)

#define AXBS_CRS4_PCTL_MASK                      (0x30U)
#define AXBS_CRS4_PCTL_SHIFT                     (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..When no master makes a request, the slave port is not parked on a master and the arbiter drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_CRS4_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS4_PCTL_SHIFT)) & AXBS_CRS4_PCTL_MASK)

#define AXBS_CRS4_ARB_MASK                       (0x300U)
#define AXBS_CRS4_ARB_SHIFT                      (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin(RR) or rotating priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_CRS4_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS4_ARB_SHIFT)) & AXBS_CRS4_ARB_MASK)

#define AXBS_CRS4_HLP_MASK                       (0x40000000U)
#define AXBS_CRS4_HLP_SHIFT                      (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_CRS4_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS4_HLP_SHIFT)) & AXBS_CRS4_HLP_MASK)

#define AXBS_CRS4_RO_MASK                        (0x80000000U)
#define AXBS_CRS4_RO_SHIFT                       (31U)
/*! RO - Read Only
 *  0b0..The slave port's registers are writeable.
 *  0b1..The slave port's registers are read-only and cannot be written. Attempted writes do not affect the
 *       registers and result in a bus error response.
 */
#define AXBS_CRS4_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS4_RO_SHIFT)) & AXBS_CRS4_RO_MASK)
/*! @} */

/*! @name PRS5 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS5_M0_MASK                        (0x7U)
#define AXBS_PRS5_M0_SHIFT                       (0U)
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
#define AXBS_PRS5_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS5_M0_SHIFT)) & AXBS_PRS5_M0_MASK)

#define AXBS_PRS5_M1_MASK                        (0x70U)
#define AXBS_PRS5_M1_SHIFT                       (4U)
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
#define AXBS_PRS5_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS5_M1_SHIFT)) & AXBS_PRS5_M1_MASK)

#define AXBS_PRS5_M2_MASK                        (0x700U)
#define AXBS_PRS5_M2_SHIFT                       (8U)
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
#define AXBS_PRS5_M2(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS5_M2_SHIFT)) & AXBS_PRS5_M2_MASK)

#define AXBS_PRS5_M3_MASK                        (0x7000U)
#define AXBS_PRS5_M3_SHIFT                       (12U)
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
#define AXBS_PRS5_M3(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS5_M3_SHIFT)) & AXBS_PRS5_M3_MASK)

#define AXBS_PRS5_M4_MASK                        (0x70000U)
#define AXBS_PRS5_M4_SHIFT                       (16U)
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
#define AXBS_PRS5_M4(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS5_M4_SHIFT)) & AXBS_PRS5_M4_MASK)

#define AXBS_PRS5_M5_MASK                        (0x700000U)
#define AXBS_PRS5_M5_SHIFT                       (20U)
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
#define AXBS_PRS5_M5(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS5_M5_SHIFT)) & AXBS_PRS5_M5_MASK)

#define AXBS_PRS5_M6_MASK                        (0x7000000U)
#define AXBS_PRS5_M6_SHIFT                       (24U)
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
#define AXBS_PRS5_M6(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS5_M6_SHIFT)) & AXBS_PRS5_M6_MASK)
/*! @} */

/*! @name CRS5 - Control Register */
/*! @{ */

#define AXBS_CRS5_PARK_MASK                      (0x7U)
#define AXBS_CRS5_PARK_SHIFT                     (0U)
/*! PARK - Park
 *  0b000..Park on master port M0.
 *  0b001..Park on master port M1.
 *  0b010..Park on master port M2.
 *  0b011..Park on master port M3.
 *  0b100..Park on master port M4.
 *  0b101..Park on master port M5.
 *  0b110..Park on master port M6.
 *  0b111..Park on master port M7.
 */
#define AXBS_CRS5_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS5_PARK_SHIFT)) & AXBS_CRS5_PARK_MASK)

#define AXBS_CRS5_PCTL_MASK                      (0x30U)
#define AXBS_CRS5_PCTL_SHIFT                     (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..When no master makes a request, the slave port is not parked on a master and the arbiter drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_CRS5_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS5_PCTL_SHIFT)) & AXBS_CRS5_PCTL_MASK)

#define AXBS_CRS5_ARB_MASK                       (0x300U)
#define AXBS_CRS5_ARB_SHIFT                      (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin(RR) or rotating priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_CRS5_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS5_ARB_SHIFT)) & AXBS_CRS5_ARB_MASK)

#define AXBS_CRS5_HLP_MASK                       (0x40000000U)
#define AXBS_CRS5_HLP_SHIFT                      (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_CRS5_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS5_HLP_SHIFT)) & AXBS_CRS5_HLP_MASK)

#define AXBS_CRS5_RO_MASK                        (0x80000000U)
#define AXBS_CRS5_RO_SHIFT                       (31U)
/*! RO - Read Only
 *  0b0..The slave port's registers are writeable.
 *  0b1..The slave port's registers are read-only and cannot be written. Attempted writes do not affect the
 *       registers and result in a bus error response.
 */
#define AXBS_CRS5_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS5_RO_SHIFT)) & AXBS_CRS5_RO_MASK)
/*! @} */

/*! @name PRS6 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS6_M0_MASK                        (0x7U)
#define AXBS_PRS6_M0_SHIFT                       (0U)
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
#define AXBS_PRS6_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS6_M0_SHIFT)) & AXBS_PRS6_M0_MASK)

#define AXBS_PRS6_M1_MASK                        (0x70U)
#define AXBS_PRS6_M1_SHIFT                       (4U)
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
#define AXBS_PRS6_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS6_M1_SHIFT)) & AXBS_PRS6_M1_MASK)

#define AXBS_PRS6_M2_MASK                        (0x700U)
#define AXBS_PRS6_M2_SHIFT                       (8U)
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
#define AXBS_PRS6_M2(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS6_M2_SHIFT)) & AXBS_PRS6_M2_MASK)

#define AXBS_PRS6_M3_MASK                        (0x7000U)
#define AXBS_PRS6_M3_SHIFT                       (12U)
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
#define AXBS_PRS6_M3(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS6_M3_SHIFT)) & AXBS_PRS6_M3_MASK)

#define AXBS_PRS6_M4_MASK                        (0x70000U)
#define AXBS_PRS6_M4_SHIFT                       (16U)
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
#define AXBS_PRS6_M4(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS6_M4_SHIFT)) & AXBS_PRS6_M4_MASK)

#define AXBS_PRS6_M5_MASK                        (0x700000U)
#define AXBS_PRS6_M5_SHIFT                       (20U)
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
#define AXBS_PRS6_M5(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS6_M5_SHIFT)) & AXBS_PRS6_M5_MASK)

#define AXBS_PRS6_M6_MASK                        (0x7000000U)
#define AXBS_PRS6_M6_SHIFT                       (24U)
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
#define AXBS_PRS6_M6(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS6_M6_SHIFT)) & AXBS_PRS6_M6_MASK)
/*! @} */

/*! @name CRS6 - Control Register */
/*! @{ */

#define AXBS_CRS6_PARK_MASK                      (0x7U)
#define AXBS_CRS6_PARK_SHIFT                     (0U)
/*! PARK - Park
 *  0b000..Park on master port M0.
 *  0b001..Park on master port M1.
 *  0b010..Park on master port M2.
 *  0b011..Park on master port M3.
 *  0b100..Park on master port M4.
 *  0b101..Park on master port M5.
 *  0b110..Park on master port M6.
 *  0b111..Park on master port M7.
 */
#define AXBS_CRS6_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS6_PARK_SHIFT)) & AXBS_CRS6_PARK_MASK)

#define AXBS_CRS6_PCTL_MASK                      (0x30U)
#define AXBS_CRS6_PCTL_SHIFT                     (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..When no master makes a request, the slave port is not parked on a master and the arbiter drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_CRS6_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS6_PCTL_SHIFT)) & AXBS_CRS6_PCTL_MASK)

#define AXBS_CRS6_ARB_MASK                       (0x300U)
#define AXBS_CRS6_ARB_SHIFT                      (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin(RR) or rotating priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_CRS6_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS6_ARB_SHIFT)) & AXBS_CRS6_ARB_MASK)

#define AXBS_CRS6_HLP_MASK                       (0x40000000U)
#define AXBS_CRS6_HLP_SHIFT                      (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_CRS6_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS6_HLP_SHIFT)) & AXBS_CRS6_HLP_MASK)

#define AXBS_CRS6_RO_MASK                        (0x80000000U)
#define AXBS_CRS6_RO_SHIFT                       (31U)
/*! RO - Read Only
 *  0b0..The slave port's registers are writeable.
 *  0b1..The slave port's registers are read-only and cannot be written. Attempted writes do not affect the
 *       registers and result in a bus error response.
 */
#define AXBS_CRS6_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS6_RO_SHIFT)) & AXBS_CRS6_RO_MASK)
/*! @} */

/*! @name PRS7 - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS7_M0_MASK                        (0x7U)
#define AXBS_PRS7_M0_SHIFT                       (0U)
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
#define AXBS_PRS7_M0(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS7_M0_SHIFT)) & AXBS_PRS7_M0_MASK)

#define AXBS_PRS7_M1_MASK                        (0x70U)
#define AXBS_PRS7_M1_SHIFT                       (4U)
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
#define AXBS_PRS7_M1(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS7_M1_SHIFT)) & AXBS_PRS7_M1_MASK)

#define AXBS_PRS7_M2_MASK                        (0x700U)
#define AXBS_PRS7_M2_SHIFT                       (8U)
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
#define AXBS_PRS7_M2(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS7_M2_SHIFT)) & AXBS_PRS7_M2_MASK)

#define AXBS_PRS7_M3_MASK                        (0x7000U)
#define AXBS_PRS7_M3_SHIFT                       (12U)
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
#define AXBS_PRS7_M3(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS7_M3_SHIFT)) & AXBS_PRS7_M3_MASK)

#define AXBS_PRS7_M4_MASK                        (0x70000U)
#define AXBS_PRS7_M4_SHIFT                       (16U)
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
#define AXBS_PRS7_M4(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS7_M4_SHIFT)) & AXBS_PRS7_M4_MASK)

#define AXBS_PRS7_M5_MASK                        (0x700000U)
#define AXBS_PRS7_M5_SHIFT                       (20U)
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
#define AXBS_PRS7_M5(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS7_M5_SHIFT)) & AXBS_PRS7_M5_MASK)

#define AXBS_PRS7_M6_MASK                        (0x7000000U)
#define AXBS_PRS7_M6_SHIFT                       (24U)
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
#define AXBS_PRS7_M6(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_PRS7_M6_SHIFT)) & AXBS_PRS7_M6_MASK)
/*! @} */

/*! @name CRS7 - Control Register */
/*! @{ */

#define AXBS_CRS7_PARK_MASK                      (0x7U)
#define AXBS_CRS7_PARK_SHIFT                     (0U)
/*! PARK - Park
 *  0b000..Park on master port M0.
 *  0b001..Park on master port M1.
 *  0b010..Park on master port M2.
 *  0b011..Park on master port M3.
 *  0b100..Park on master port M4.
 *  0b101..Park on master port M5.
 *  0b110..Park on master port M6.
 *  0b111..Park on master port M7.
 */
#define AXBS_CRS7_PARK(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS7_PARK_SHIFT)) & AXBS_CRS7_PARK_MASK)

#define AXBS_CRS7_PCTL_MASK                      (0x30U)
#define AXBS_CRS7_PCTL_SHIFT                     (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK field.
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port.
 *  0b10..When no master makes a request, the slave port is not parked on a master and the arbiter drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_CRS7_PCTL(x)                        (((uint32_t)(((uint32_t)(x)) << AXBS_CRS7_PCTL_SHIFT)) & AXBS_CRS7_PCTL_MASK)

#define AXBS_CRS7_ARB_MASK                       (0x300U)
#define AXBS_CRS7_ARB_SHIFT                      (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin(RR) or rotating priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_CRS7_ARB(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS7_ARB_SHIFT)) & AXBS_CRS7_ARB_MASK)

#define AXBS_CRS7_HLP_MASK                       (0x40000000U)
#define AXBS_CRS7_HLP_SHIFT                      (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low-power mode request has the highest priority for arbitration on this slave port.
 *  0b1..The low-power mode request has the lowest initial priority for arbitration on this slave port.
 */
#define AXBS_CRS7_HLP(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS7_HLP_SHIFT)) & AXBS_CRS7_HLP_MASK)

#define AXBS_CRS7_RO_MASK                        (0x80000000U)
#define AXBS_CRS7_RO_SHIFT                       (31U)
/*! RO - Read Only
 *  0b0..The slave port's registers are writeable.
 *  0b1..The slave port's registers are read-only and cannot be written. Attempted writes do not affect the
 *       registers and result in a bus error response.
 */
#define AXBS_CRS7_RO(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS7_RO_SHIFT)) & AXBS_CRS7_RO_MASK)
/*! @} */

/*! @name MGPCR0 - Master General Purpose Control Register */
/*! @{ */

#define AXBS_MGPCR0_AULB_MASK                    (0x7U)
#define AXBS_MGPCR0_AULB_SHIFT                   (0U)
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
#define AXBS_MGPCR0_AULB(x)                      (((uint32_t)(((uint32_t)(x)) << AXBS_MGPCR0_AULB_SHIFT)) & AXBS_MGPCR0_AULB_MASK)
/*! @} */

/*! @name MGPCR1 - Master General Purpose Control Register */
/*! @{ */

#define AXBS_MGPCR1_AULB_MASK                    (0x7U)
#define AXBS_MGPCR1_AULB_SHIFT                   (0U)
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
#define AXBS_MGPCR1_AULB(x)                      (((uint32_t)(((uint32_t)(x)) << AXBS_MGPCR1_AULB_SHIFT)) & AXBS_MGPCR1_AULB_MASK)
/*! @} */

/*! @name MGPCR2 - Master General Purpose Control Register */
/*! @{ */

#define AXBS_MGPCR2_AULB_MASK                    (0x7U)
#define AXBS_MGPCR2_AULB_SHIFT                   (0U)
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
#define AXBS_MGPCR2_AULB(x)                      (((uint32_t)(((uint32_t)(x)) << AXBS_MGPCR2_AULB_SHIFT)) & AXBS_MGPCR2_AULB_MASK)
/*! @} */

/*! @name MGPCR3 - Master General Purpose Control Register */
/*! @{ */

#define AXBS_MGPCR3_AULB_MASK                    (0x7U)
#define AXBS_MGPCR3_AULB_SHIFT                   (0U)
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
#define AXBS_MGPCR3_AULB(x)                      (((uint32_t)(((uint32_t)(x)) << AXBS_MGPCR3_AULB_SHIFT)) & AXBS_MGPCR3_AULB_MASK)
/*! @} */

/*! @name MGPCR4 - Master General Purpose Control Register */
/*! @{ */

#define AXBS_MGPCR4_AULB_MASK                    (0x7U)
#define AXBS_MGPCR4_AULB_SHIFT                   (0U)
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
#define AXBS_MGPCR4_AULB(x)                      (((uint32_t)(((uint32_t)(x)) << AXBS_MGPCR4_AULB_SHIFT)) & AXBS_MGPCR4_AULB_MASK)
/*! @} */

/*! @name MGPCR5 - Master General Purpose Control Register */
/*! @{ */

#define AXBS_MGPCR5_AULB_MASK                    (0x7U)
#define AXBS_MGPCR5_AULB_SHIFT                   (0U)
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
#define AXBS_MGPCR5_AULB(x)                      (((uint32_t)(((uint32_t)(x)) << AXBS_MGPCR5_AULB_SHIFT)) & AXBS_MGPCR5_AULB_MASK)
/*! @} */

/*! @name MGPCR6 - Master General Purpose Control Register */
/*! @{ */

#define AXBS_MGPCR6_AULB_MASK                    (0x7U)
#define AXBS_MGPCR6_AULB_SHIFT                   (0U)
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
#define AXBS_MGPCR6_AULB(x)                      (((uint32_t)(((uint32_t)(x)) << AXBS_MGPCR6_AULB_SHIFT)) & AXBS_MGPCR6_AULB_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AXBS_Register_Masks */


/*!
 * @}
 */ /* end of group AXBS_Peripheral_Access_Layer */


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


#endif  /* PERI_AXBS_H_ */

