/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AXBS
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_AXBS.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for AXBS
 *
 * CMSIS Peripheral Access Layer for AXBS
 */

#if !defined(PERI_AXBS_H_)
#define PERI_AXBS_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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

/** AXBS - Size of Registers Arrays */
#define AXBS_SLAVE_COUNT                          6u

/** AXBS - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x100 */
    __IO uint32_t PRS;                               /**< Priority Target Registers, array offset: 0x0, array step: 0x100 */
         uint8_t RESERVED_0[12];
    __IO uint32_t CRS;                               /**< Control Register, array offset: 0x10, array step: 0x100 */
         uint8_t RESERVED_1[236];
  } SLAVE[AXBS_SLAVE_COUNT];
} AXBS_Type;

/* ----------------------------------------------------------------------------
   -- AXBS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AXBS_Register_Masks AXBS Register Masks
 * @{
 */

/*! @name PRS - Priority Target Registers */
/*! @{ */

#define AXBS_PRS_M0_MASK                         (0x7U)
#define AXBS_PRS_M0_SHIFT                        (0U)
/*! M0 - Initiator 0 Priority
 *  0b000..This initiator has level 1 or highest priority when accessing the target port.
 *  0b001..This initiator has level 2 priority when accessing the target port.
 *  0b010..This initiator has level 3 priority when accessing the target port.
 *  0b011..This initiator has level 4 priority when accessing the target port.
 *  0b100..This initiator has level 5 priority when accessing the target port.
 *  0b101..This initiator has level 6 priority when accessing the target port.
 *  0b110..This initiator has level 7 priority when accessing the target port.
 *  0b111..This initiator has level 8 or the lowest priority when accessing the target port.
 */
#define AXBS_PRS_M0(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M0_SHIFT)) & AXBS_PRS_M0_MASK)

#define AXBS_PRS_M1_MASK                         (0x70U)
#define AXBS_PRS_M1_SHIFT                        (4U)
/*! M1 - Initiator 1 Priority
 *  0b000..This initiator has level 1 or highest priority when accessing the target port.
 *  0b001..This initiator has level 2 priority when accessing the target port.
 *  0b010..This initiator has level 3 priority when accessing the target port.
 *  0b011..This initiator has level 4 priority when accessing the target port.
 *  0b100..This initiator has level 5 priority when accessing the target port.
 *  0b101..This initiator has level 6 priority when accessing the target port.
 *  0b110..This initiator has level 7 priority when accessing the target port.
 *  0b111..This initiator has level 8 or lowest priority when accessing the target port.
 */
#define AXBS_PRS_M1(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M1_SHIFT)) & AXBS_PRS_M1_MASK)

#define AXBS_PRS_M2_MASK                         (0x700U)
#define AXBS_PRS_M2_SHIFT                        (8U)
/*! M2 - Initiator 2 Priority
 *  0b000..This initiator has level 1 or highest priority when accessing the target port.
 *  0b001..This initiator has level 2 priority when accessing the target port.
 *  0b010..This initiator has level 3 priority when accessing the target port.
 *  0b011..This initiator has level 4 priority when accessing the target port.
 *  0b100..This initiator has level 5 priority when accessing the target port.
 *  0b101..This initiator has level 6 priority when accessing the target port.
 *  0b110..This initiator has level 7 priority when accessing the target port.
 *  0b111..This initiator has level 8 or the lowest priority when accessing the target port.
 */
#define AXBS_PRS_M2(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M2_SHIFT)) & AXBS_PRS_M2_MASK)

#define AXBS_PRS_M3_MASK                         (0x7000U)
#define AXBS_PRS_M3_SHIFT                        (12U)
/*! M3 - Initiator 3 Priority
 *  0b000..This initiator has level 1 or highest priority when accessing the target port.
 *  0b001..This initiator has level 2 priority when accessing the target port.
 *  0b010..This initiator has level 3 priority when accessing the target port.
 *  0b011..This initiator has level 4 priority when accessing the target port.
 *  0b100..This initiator has level 5 priority when accessing the target port.
 *  0b101..This initiator has level 6 priority when accessing the target port.
 *  0b110..This initiator has level 7 priority when accessing the target port.
 *  0b111..This initiator has level 8 or the lowest priority when accessing the target port.
 */
#define AXBS_PRS_M3(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M3_SHIFT)) & AXBS_PRS_M3_MASK)

#define AXBS_PRS_M4_MASK                         (0x70000U)
#define AXBS_PRS_M4_SHIFT                        (16U)
/*! M4 - Initiator 4 Priority
 *  0b000..This initiator has level 1 or highest priority when accessing the target port.
 *  0b001..This initiator has level 2 priority when accessing the target port.
 *  0b010..This initiator has level 3 priority when accessing the target port.
 *  0b011..This initiator has level 4 priority when accessing the target port.
 *  0b100..This initiator has level 5 priority when accessing the target port.
 *  0b101..This initiator has level 6 priority when accessing the target port.
 *  0b110..This initiator has level 7 priority when accessing the target port.
 *  0b111..This initiator has level 8 or the lowest priority when accessing the target port.
 */
#define AXBS_PRS_M4(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M4_SHIFT)) & AXBS_PRS_M4_MASK)

#define AXBS_PRS_M5_MASK                         (0x700000U)
#define AXBS_PRS_M5_SHIFT                        (20U)
/*! M5 - Initiator 5 Priority
 *  0b000..This initiator has level 1 or highest priority when accessing the target port.
 *  0b001..This initiator has level 2 priority when accessing the target port.
 *  0b010..This initiator has level 3 priority when accessing the target port.
 *  0b011..This initiator has level 4 priority when accessing the target port.
 *  0b100..This initiator has level 5 priority when accessing the target port.
 *  0b101..This initiator has level 6 priority when accessing the target port.
 *  0b110..This initiator has level 7 priority when accessing the target port.
 *  0b111..This initiator has level 8 or the lowest priority when accessing the target port.
 */
#define AXBS_PRS_M5(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M5_SHIFT)) & AXBS_PRS_M5_MASK)

#define AXBS_PRS_M6_MASK                         (0x7000000U)
#define AXBS_PRS_M6_SHIFT                        (24U)
/*! M6 - Initiator 6 Priority
 *  0b000..This initiator has level 1 or highest priority when accessing the target port.
 *  0b001..This initiator has level 2 priority when accessing the target port.
 *  0b010..This initiator has level 3 priority when accessing the target port.
 *  0b011..This initiator has level 4 priority when accessing the target port.
 *  0b100..This initiator has level 5 priority when accessing the target port.
 *  0b101..This initiator has level 6 priority when accessing the target port.
 *  0b110..This initiator has level 7 priority when accessing the target port.
 *  0b111..This initiator has level 8 or the lowest priority when accessing the target port.
 */
#define AXBS_PRS_M6(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M6_SHIFT)) & AXBS_PRS_M6_MASK)
/*! @} */

/* The count of AXBS_PRS */
#define AXBS_PRS_COUNT                           (6U)

/*! @name CRS - Control Register */
/*! @{ */

#define AXBS_CRS_PARK_MASK                       (0x7U)
#define AXBS_CRS_PARK_SHIFT                      (0U)
/*! PARK - Park
 *  0b000..Park on initiator port M0
 *  0b001..Park on initiator port M1
 *  0b010..Park on initiator port M2
 *  0b011..Park on initiator port M3
 *  0b100..Park on initiator port M4
 *  0b101..Park on initiator port M5
 *  0b110..Park on initiator port M6
 *  0b111..Park on initiator port M7
 */
#define AXBS_CRS_PARK(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_PARK_SHIFT)) & AXBS_CRS_PARK_MASK)

#define AXBS_CRS_PCTL_MASK                       (0x30U)
#define AXBS_CRS_PCTL_SHIFT                      (4U)
/*! PCTL - Parking Control
 *  0b00..When no initiator makes a request, the arbiter parks the target port on the initiator port defined by the PARK bit field.
 *  0b01..When no initiator makes a request, the arbiter parks the target port on the last initiator to be in control of the target port.
 *  0b10..Low-power park. When no initiator makes a request, the target port is not parked on a initiator and the
 *        arbiter drives all outputs to a constant safe state.
 *  0b11..Reserved
 */
#define AXBS_CRS_PCTL(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_PCTL_SHIFT)) & AXBS_CRS_PCTL_MASK)

#define AXBS_CRS_ARB_MASK                        (0x300U)
#define AXBS_CRS_ARB_SHIFT                       (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin (rotating) priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_CRS_ARB(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_ARB_SHIFT)) & AXBS_CRS_ARB_MASK)

#define AXBS_CRS_HPE0_MASK                       (0x10000U)
#define AXBS_CRS_HPE0_SHIFT                      (16U)
/*! HPE0 - High Priority Elevation 0
 *  0b0..Initiator high-priority elevation for initiator 0 is disabled on this target port.
 *  0b1..Initiator high-priority elevation for initiator 0 is enabled on this target port.
 */
#define AXBS_CRS_HPE0(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE0_SHIFT)) & AXBS_CRS_HPE0_MASK)

#define AXBS_CRS_HPE1_MASK                       (0x20000U)
#define AXBS_CRS_HPE1_SHIFT                      (17U)
/*! HPE1 - High Priority Elevation 1
 *  0b0..Initiator high-priority elevation for initiator 1 is disabled on this target port.
 *  0b1..Initiator high-priority elevation for initiator 1 is enabled on this target port.
 */
#define AXBS_CRS_HPE1(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE1_SHIFT)) & AXBS_CRS_HPE1_MASK)

#define AXBS_CRS_HPE2_MASK                       (0x40000U)
#define AXBS_CRS_HPE2_SHIFT                      (18U)
/*! HPE2 - High Priority Elevation 2
 *  0b0..Initiator high-priority elevation for initiator 2 is disabled on this target port.
 *  0b1..Initiator high-priority elevation for initiator 2 is enabled on this target port.
 */
#define AXBS_CRS_HPE2(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE2_SHIFT)) & AXBS_CRS_HPE2_MASK)

#define AXBS_CRS_HPE3_MASK                       (0x80000U)
#define AXBS_CRS_HPE3_SHIFT                      (19U)
/*! HPE3 - High Priority Elevation 3
 *  0b0..Initiator high-priority elevation for initiator 3 is disabled on this target port.
 *  0b1..Initiator high-priority elevation for initiator 3 is enabled on this target port.
 */
#define AXBS_CRS_HPE3(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE3_SHIFT)) & AXBS_CRS_HPE3_MASK)

#define AXBS_CRS_HPE4_MASK                       (0x100000U)
#define AXBS_CRS_HPE4_SHIFT                      (20U)
/*! HPE4 - High Priority Elevation 4
 *  0b0..Initiator high-priority elevation for initiator 4 is disabled on this target port.
 *  0b1..Initiator high-priority elevation for initiator 4 is enabled on this target port.
 */
#define AXBS_CRS_HPE4(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE4_SHIFT)) & AXBS_CRS_HPE4_MASK)

#define AXBS_CRS_HPE5_MASK                       (0x200000U)
#define AXBS_CRS_HPE5_SHIFT                      (21U)
/*! HPE5 - High Priority Elevation 5
 *  0b0..Initiator high-priority elevation for initiator 5 is disabled on this target port.
 *  0b1..Initiator high-priority elevation for initiator 5 is enabled on this target port.
 */
#define AXBS_CRS_HPE5(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE5_SHIFT)) & AXBS_CRS_HPE5_MASK)

#define AXBS_CRS_HPE6_MASK                       (0x400000U)
#define AXBS_CRS_HPE6_SHIFT                      (22U)
/*! HPE6 - High Priority Elevation 6
 *  0b0..Initiator high-priority elevation for initiator 6 is disabled on this target port.
 *  0b1..Initiator high-priority elevation for initiator 6 is enabled on this target port.
 */
#define AXBS_CRS_HPE6(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HPE6_SHIFT)) & AXBS_CRS_HPE6_MASK)

#define AXBS_CRS_RO_MASK                         (0x80000000U)
#define AXBS_CRS_RO_SHIFT                        (31U)
/*! RO - Read Only
 *  0b0..The CRSn and PRSn registers are writeable
 *  0b1..The CRSn and PRSn registers are read-only and cannot be written (attempted writes have no effect on the
 *       registers and result in a bus error response).
 */
#define AXBS_CRS_RO(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_RO_SHIFT)) & AXBS_CRS_RO_MASK)
/*! @} */

/* The count of AXBS_CRS */
#define AXBS_CRS_COUNT                           (6U)


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

