/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2019-04-22)
**         Initial version.
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

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
#define AXBS_SLAVE_COUNT                          5u

/** AXBS - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x100 */
    __IO uint32_t PRS;                               /**< Priority Slave Registers, array offset: 0x0, array step: 0x100 */
         uint8_t RESERVED_0[12];
    __IO uint32_t CRS;                               /**< Control Register, array offset: 0x10, array step: 0x100 */
         uint8_t RESERVED_1[236];
  } SLAVE[AXBS_SLAVE_COUNT];
       uint8_t RESERVED_0[768];
  __IO uint32_t MGPCR0;                            /**< Master General Purpose Control Register, offset: 0x800 */
       uint8_t RESERVED_1[252];
  __IO uint32_t MGPCR1;                            /**< Master General Purpose Control Register, offset: 0x900 */
       uint8_t RESERVED_2[252];
  __IO uint32_t MGPCR2;                            /**< Master General Purpose Control Register, offset: 0xA00 */
       uint8_t RESERVED_3[252];
  __IO uint32_t MGPCR3;                            /**< Master General Purpose Control Register, offset: 0xB00 */
       uint8_t RESERVED_4[252];
  __IO uint32_t MGPCR4;                            /**< Master General Purpose Control Register, offset: 0xC00 */
       uint8_t RESERVED_5[252];
  __IO uint32_t MGPCR5;                            /**< Master General Purpose Control Register, offset: 0xD00 */
} AXBS_Type;

/* ----------------------------------------------------------------------------
   -- AXBS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AXBS_Register_Masks AXBS Register Masks
 * @{
 */

/*! @name PRS - Priority Slave Registers */
/*! @{ */

#define AXBS_PRS_M0_MASK                         (0x7U)
#define AXBS_PRS_M0_SHIFT                        (0U)
/*! M0 - Master 0 Priority. Sets the arbitration priority for this port on the associated slave port.
 *  0b000..This master has level 1, or highest, priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8, or lowest, priority when accessing the slave port.
 */
#define AXBS_PRS_M0(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M0_SHIFT)) & AXBS_PRS_M0_MASK)

#define AXBS_PRS_M1_MASK                         (0x70U)
#define AXBS_PRS_M1_SHIFT                        (4U)
/*! M1 - Master 1 Priority. Sets the arbitration priority for this port on the associated slave port.
 *  0b000..This master has level 1, or highest, priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8, or lowest, priority when accessing the slave port.
 */
#define AXBS_PRS_M1(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M1_SHIFT)) & AXBS_PRS_M1_MASK)

#define AXBS_PRS_M2_MASK                         (0x700U)
#define AXBS_PRS_M2_SHIFT                        (8U)
/*! M2 - Master 2 Priority. Sets the arbitration priority for this port on the associated slave port.
 *  0b000..This master has level 1, or highest, priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8, or lowest, priority when accessing the slave port.
 */
#define AXBS_PRS_M2(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M2_SHIFT)) & AXBS_PRS_M2_MASK)

#define AXBS_PRS_M3_MASK                         (0x7000U)
#define AXBS_PRS_M3_SHIFT                        (12U)
/*! M3 - Master 3 Priority. Sets the arbitration priority for this port on the associated slave port.
 *  0b000..This master has level 1, or highest, priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8, or lowest, priority when accessing the slave port.
 */
#define AXBS_PRS_M3(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M3_SHIFT)) & AXBS_PRS_M3_MASK)

#define AXBS_PRS_M4_MASK                         (0x70000U)
#define AXBS_PRS_M4_SHIFT                        (16U)
/*! M4 - Master 4 Priority. Sets the arbitration priority for this port on the associated slave port.
 *  0b000..This master has level 1, or highest, priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8, or lowest, priority when accessing the slave port.
 */
#define AXBS_PRS_M4(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M4_SHIFT)) & AXBS_PRS_M4_MASK)

#define AXBS_PRS_M5_MASK                         (0x700000U)
#define AXBS_PRS_M5_SHIFT                        (20U)
/*! M5 - Master 5 Priority. Sets the arbitration priority for this port on the associated slave port.
 *  0b000..This master has level 1, or highest, priority when accessing the slave port.
 *  0b001..This master has level 2 priority when accessing the slave port.
 *  0b010..This master has level 3 priority when accessing the slave port.
 *  0b011..This master has level 4 priority when accessing the slave port.
 *  0b100..This master has level 5 priority when accessing the slave port.
 *  0b101..This master has level 6 priority when accessing the slave port.
 *  0b110..This master has level 7 priority when accessing the slave port.
 *  0b111..This master has level 8, or lowest, priority when accessing the slave port.
 */
#define AXBS_PRS_M5(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_PRS_M5_SHIFT)) & AXBS_PRS_M5_MASK)
/*! @} */

/* The count of AXBS_PRS */
#define AXBS_PRS_COUNT                           (5U)

/*! @name CRS - Control Register */
/*! @{ */

#define AXBS_CRS_PARK_MASK                       (0x7U)
#define AXBS_CRS_PARK_SHIFT                      (0U)
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
#define AXBS_CRS_PARK(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_PARK_SHIFT)) & AXBS_CRS_PARK_MASK)

#define AXBS_CRS_PCTL_MASK                       (0x30U)
#define AXBS_CRS_PCTL_SHIFT                      (4U)
/*! PCTL - Parking Control
 *  0b00..When no master makes a request, the arbiter parks the slave port on the master port defined by the PARK field
 *  0b01..When no master makes a request, the arbiter parks the slave port on the last master to be in control of the slave port
 *  0b10..When no master makes a request, the slave port is not parked on a master and the arbiter drives all outputs to a constant safe state
 *  0b11..Reserved
 */
#define AXBS_CRS_PCTL(x)                         (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_PCTL_SHIFT)) & AXBS_CRS_PCTL_MASK)

#define AXBS_CRS_ARB_MASK                        (0x300U)
#define AXBS_CRS_ARB_SHIFT                       (8U)
/*! ARB - Arbitration Mode
 *  0b00..Fixed priority
 *  0b01..Round-robin, or rotating, priority
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define AXBS_CRS_ARB(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_ARB_SHIFT)) & AXBS_CRS_ARB_MASK)

#define AXBS_CRS_HLP_MASK                        (0x40000000U)
#define AXBS_CRS_HLP_SHIFT                       (30U)
/*! HLP - Halt Low Priority
 *  0b0..The low power mode request has the highest priority for arbitration on this slave port
 *  0b1..The low power mode request has the lowest initial priority for arbitration on this slave port
 */
#define AXBS_CRS_HLP(x)                          (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_HLP_SHIFT)) & AXBS_CRS_HLP_MASK)

#define AXBS_CRS_RO_MASK                         (0x80000000U)
#define AXBS_CRS_RO_SHIFT                        (31U)
/*! RO - Read Only
 *  0b0..The slave port's registers are writeable
 *  0b1..The slave port's registers are read-only and cannot be written. Attempted writes have no effect on the
 *       registers and result in a bus error response.
 */
#define AXBS_CRS_RO(x)                           (((uint32_t)(((uint32_t)(x)) << AXBS_CRS_RO_SHIFT)) & AXBS_CRS_RO_MASK)
/*! @} */

/* The count of AXBS_CRS */
#define AXBS_CRS_COUNT                           (5U)

/*! @name MGPCR0 - Master General Purpose Control Register */
/*! @{ */

#define AXBS_MGPCR0_AULB_MASK                    (0x7U)
#define AXBS_MGPCR0_AULB_SHIFT                   (0U)
/*! AULB - Arbitrates On Undefined Length Bursts
 *  0b000..No arbitration is allowed during an undefined length burst
 *  0b001..Arbitration is allowed at any time during an undefined length burst
 *  0b010..Arbitration is allowed after four beats of an undefined length burst
 *  0b011..Arbitration is allowed after eight beats of an undefined length burst
 *  0b100..Arbitration is allowed after 16 beats of an undefined length burst
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
 *  0b000..No arbitration is allowed during an undefined length burst
 *  0b001..Arbitration is allowed at any time during an undefined length burst
 *  0b010..Arbitration is allowed after four beats of an undefined length burst
 *  0b011..Arbitration is allowed after eight beats of an undefined length burst
 *  0b100..Arbitration is allowed after 16 beats of an undefined length burst
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
 *  0b000..No arbitration is allowed during an undefined length burst
 *  0b001..Arbitration is allowed at any time during an undefined length burst
 *  0b010..Arbitration is allowed after four beats of an undefined length burst
 *  0b011..Arbitration is allowed after eight beats of an undefined length burst
 *  0b100..Arbitration is allowed after 16 beats of an undefined length burst
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
 *  0b000..No arbitration is allowed during an undefined length burst
 *  0b001..Arbitration is allowed at any time during an undefined length burst
 *  0b010..Arbitration is allowed after four beats of an undefined length burst
 *  0b011..Arbitration is allowed after eight beats of an undefined length burst
 *  0b100..Arbitration is allowed after 16 beats of an undefined length burst
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
 *  0b000..No arbitration is allowed during an undefined length burst
 *  0b001..Arbitration is allowed at any time during an undefined length burst
 *  0b010..Arbitration is allowed after four beats of an undefined length burst
 *  0b011..Arbitration is allowed after eight beats of an undefined length burst
 *  0b100..Arbitration is allowed after 16 beats of an undefined length burst
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
 *  0b000..No arbitration is allowed during an undefined length burst
 *  0b001..Arbitration is allowed at any time during an undefined length burst
 *  0b010..Arbitration is allowed after four beats of an undefined length burst
 *  0b011..Arbitration is allowed after eight beats of an undefined length burst
 *  0b100..Arbitration is allowed after 16 beats of an undefined length burst
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define AXBS_MGPCR5_AULB(x)                      (((uint32_t)(((uint32_t)(x)) << AXBS_MGPCR5_AULB_SHIFT)) & AXBS_MGPCR5_AULB_MASK)
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

