/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XBIC
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
 * @file PERI_XBIC.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for XBIC
 *
 * CMSIS Peripheral Access Layer for XBIC
 */

#if !defined(PERI_XBIC_H_)
#define PERI_XBIC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- XBIC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBIC_Peripheral_Access_Layer XBIC Peripheral Access Layer
 * @{
 */

/** XBIC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< XBIC Module Control, offset: 0x0 */
  __IO uint32_t EIR;                               /**< XBIC Error Injection, offset: 0x4 */
  __I  uint32_t ESR;                               /**< XBIC Error Status, offset: 0x8 */
  __I  uint32_t EAR;                               /**< XBIC Error Address, offset: 0xC */
} XBIC_Type;

/* ----------------------------------------------------------------------------
   -- XBIC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBIC_Register_Masks XBIC Register Masks
 * @{
 */

/*! @name MCR - XBIC Module Control */
/*! @{ */

#define XBIC_MCR_ME7_MASK                        (0x10000U)
#define XBIC_MCR_ME7_SHIFT                       (16U)
/*! ME7
 *  0b0..Feedback integrity checking disabled for master port 7
 *  0b1..Feedback integrity checking enabled for master port 7
 */
#define XBIC_MCR_ME7(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_ME7_SHIFT)) & XBIC_MCR_ME7_MASK)

#define XBIC_MCR_ME6_MASK                        (0x20000U)
#define XBIC_MCR_ME6_SHIFT                       (17U)
/*! ME6
 *  0b0..Feedback integrity checking disabled for master port 6
 *  0b1..Feedback integrity checking enabled for master port 6
 */
#define XBIC_MCR_ME6(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_ME6_SHIFT)) & XBIC_MCR_ME6_MASK)

#define XBIC_MCR_ME5_MASK                        (0x40000U)
#define XBIC_MCR_ME5_SHIFT                       (18U)
/*! ME5
 *  0b0..Feedback integrity checking disabled for master port 5
 *  0b1..Feedback integrity checking enabled for master port 5
 */
#define XBIC_MCR_ME5(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_ME5_SHIFT)) & XBIC_MCR_ME5_MASK)

#define XBIC_MCR_ME4_MASK                        (0x80000U)
#define XBIC_MCR_ME4_SHIFT                       (19U)
/*! ME4
 *  0b0..Feedback integrity checking disabled for master port 4
 *  0b1..Feedback integrity checking enabled for master port 4
 */
#define XBIC_MCR_ME4(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_ME4_SHIFT)) & XBIC_MCR_ME4_MASK)

#define XBIC_MCR_ME3_MASK                        (0x100000U)
#define XBIC_MCR_ME3_SHIFT                       (20U)
/*! ME3
 *  0b0..Feedback integrity checking disabled for master port 3
 *  0b1..Feedback integrity checking enabled for master port 3
 */
#define XBIC_MCR_ME3(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_ME3_SHIFT)) & XBIC_MCR_ME3_MASK)

#define XBIC_MCR_ME2_MASK                        (0x200000U)
#define XBIC_MCR_ME2_SHIFT                       (21U)
/*! ME2
 *  0b0..Feedback integrity checking disabled for master port 2
 *  0b1..Feedback integrity checking enabled for master port 2
 */
#define XBIC_MCR_ME2(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_ME2_SHIFT)) & XBIC_MCR_ME2_MASK)

#define XBIC_MCR_ME1_MASK                        (0x400000U)
#define XBIC_MCR_ME1_SHIFT                       (22U)
/*! ME1
 *  0b0..Feedback integrity checking disabled for master port 1
 *  0b1..Feedback integrity checking enabled for master port 1
 */
#define XBIC_MCR_ME1(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_ME1_SHIFT)) & XBIC_MCR_ME1_MASK)

#define XBIC_MCR_ME0_MASK                        (0x800000U)
#define XBIC_MCR_ME0_SHIFT                       (23U)
/*! ME0
 *  0b0..Feedback integrity checking disabled for master port 0
 *  0b1..Feedback integrity checking enabled for master port 0
 */
#define XBIC_MCR_ME0(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_ME0_SHIFT)) & XBIC_MCR_ME0_MASK)

#define XBIC_MCR_SE7_MASK                        (0x1000000U)
#define XBIC_MCR_SE7_SHIFT                       (24U)
/*! SE7
 *  0b0..Attribute integrity checking disabled for slave port 7
 *  0b1..Attribute integrity checking enabled for slave port 7
 */
#define XBIC_MCR_SE7(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE7_SHIFT)) & XBIC_MCR_SE7_MASK)

#define XBIC_MCR_SE6_MASK                        (0x2000000U)
#define XBIC_MCR_SE6_SHIFT                       (25U)
/*! SE6
 *  0b0..Attribute integrity checking disabled for slave port 6
 *  0b1..Attribute integrity checking enabled for slave port 6
 */
#define XBIC_MCR_SE6(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE6_SHIFT)) & XBIC_MCR_SE6_MASK)

#define XBIC_MCR_SE5_MASK                        (0x4000000U)
#define XBIC_MCR_SE5_SHIFT                       (26U)
/*! SE5
 *  0b0..Attribute integrity checking disabled for slave port 5
 *  0b1..Attribute integrity checking enabled for slave port 5
 */
#define XBIC_MCR_SE5(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE5_SHIFT)) & XBIC_MCR_SE5_MASK)

#define XBIC_MCR_SE4_MASK                        (0x8000000U)
#define XBIC_MCR_SE4_SHIFT                       (27U)
/*! SE4
 *  0b0..Attribute integrity checking disabled for slave port 4
 *  0b1..Attribute integrity checking enabled for slave port 4
 */
#define XBIC_MCR_SE4(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE4_SHIFT)) & XBIC_MCR_SE4_MASK)

#define XBIC_MCR_SE3_MASK                        (0x10000000U)
#define XBIC_MCR_SE3_SHIFT                       (28U)
/*! SE3
 *  0b0..Attribute integrity checking disabled for slave port 3
 *  0b1..Attribute integrity checking enabled for slave port 3
 */
#define XBIC_MCR_SE3(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE3_SHIFT)) & XBIC_MCR_SE3_MASK)

#define XBIC_MCR_SE2_MASK                        (0x20000000U)
#define XBIC_MCR_SE2_SHIFT                       (29U)
/*! SE2
 *  0b0..Attribute integrity checking disabled for slave port 2
 *  0b1..Attribute integrity checking enabled for slave port 2
 */
#define XBIC_MCR_SE2(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE2_SHIFT)) & XBIC_MCR_SE2_MASK)

#define XBIC_MCR_SE1_MASK                        (0x40000000U)
#define XBIC_MCR_SE1_SHIFT                       (30U)
/*! SE1
 *  0b0..Attribute integrity checking disabled for slave port 1
 *  0b1..Attribute integrity checking enabled for slave port 1
 */
#define XBIC_MCR_SE1(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE1_SHIFT)) & XBIC_MCR_SE1_MASK)

#define XBIC_MCR_SE0_MASK                        (0x80000000U)
#define XBIC_MCR_SE0_SHIFT                       (31U)
/*! SE0
 *  0b0..Attribute integrity checking disabled for slave port 0
 *  0b1..Attribute integrity checking enabled for slave port 0
 */
#define XBIC_MCR_SE0(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_MCR_SE0_SHIFT)) & XBIC_MCR_SE0_MASK)
/*! @} */

/*! @name EIR - XBIC Error Injection */
/*! @{ */

#define XBIC_EIR_SYN_MASK                        (0xFFU)
#define XBIC_EIR_SYN_SHIFT                       (0U)
/*! SYN - Syndrome */
#define XBIC_EIR_SYN(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_EIR_SYN_SHIFT)) & XBIC_EIR_SYN_MASK)

#define XBIC_EIR_MST_MASK                        (0xF00U)
#define XBIC_EIR_MST_SHIFT                       (8U)
/*! MST - Target Master ID */
#define XBIC_EIR_MST(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_EIR_MST_SHIFT)) & XBIC_EIR_MST_MASK)

#define XBIC_EIR_SLV_MASK                        (0x7000U)
#define XBIC_EIR_SLV_SHIFT                       (12U)
/*! SLV - Target Slave Port */
#define XBIC_EIR_SLV(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_EIR_SLV_SHIFT)) & XBIC_EIR_SLV_MASK)

#define XBIC_EIR_EIE_MASK                        (0x80000000U)
#define XBIC_EIR_EIE_SHIFT                       (31U)
/*! EIE
 *  0b0..Error injection disabled
 *  0b1..Error injection enabled
 */
#define XBIC_EIR_EIE(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_EIR_EIE_SHIFT)) & XBIC_EIR_EIE_MASK)
/*! @} */

/*! @name ESR - XBIC Error Status */
/*! @{ */

#define XBIC_ESR_SYN_MASK                        (0xFFU)
#define XBIC_ESR_SYN_SHIFT                       (0U)
/*! SYN - Syndrome */
#define XBIC_ESR_SYN(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_SYN_SHIFT)) & XBIC_ESR_SYN_MASK)

#define XBIC_ESR_MST_MASK                        (0xF00U)
#define XBIC_ESR_MST_SHIFT                       (8U)
/*! MST - Master ID */
#define XBIC_ESR_MST(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_MST_SHIFT)) & XBIC_ESR_MST_MASK)

#define XBIC_ESR_SLV_MASK                        (0x7000U)
#define XBIC_ESR_SLV_SHIFT                       (12U)
/*! SLV - Slave Port */
#define XBIC_ESR_SLV(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_SLV_SHIFT)) & XBIC_ESR_SLV_MASK)

#define XBIC_ESR_DPME7_MASK                      (0x8000U)
#define XBIC_ESR_DPME7_SHIFT                     (15U)
/*! DPME7
 *  0b0..No feedback integrity error detected on master port 7
 *  0b1..Feedback integrity error detected on master port 7
 */
#define XBIC_ESR_DPME7(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME7_SHIFT)) & XBIC_ESR_DPME7_MASK)

#define XBIC_ESR_DPME6_MASK                      (0x10000U)
#define XBIC_ESR_DPME6_SHIFT                     (16U)
/*! DPME6
 *  0b0..No feedback integrity error detected on master port 6
 *  0b1..Feedback integrity error detected on master port 6
 */
#define XBIC_ESR_DPME6(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME6_SHIFT)) & XBIC_ESR_DPME6_MASK)

#define XBIC_ESR_DPME5_MASK                      (0x20000U)
#define XBIC_ESR_DPME5_SHIFT                     (17U)
/*! DPME5
 *  0b0..No feedback integrity error detected on master port 5
 *  0b1..Feedback integrity error detected on master port 5
 */
#define XBIC_ESR_DPME5(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME5_SHIFT)) & XBIC_ESR_DPME5_MASK)

#define XBIC_ESR_DPME4_MASK                      (0x40000U)
#define XBIC_ESR_DPME4_SHIFT                     (18U)
/*! DPME4
 *  0b0..No feedback integrity error detected on master port 4
 *  0b1..Feedback integrity error detected on master port 4
 */
#define XBIC_ESR_DPME4(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME4_SHIFT)) & XBIC_ESR_DPME4_MASK)

#define XBIC_ESR_DPME3_MASK                      (0x80000U)
#define XBIC_ESR_DPME3_SHIFT                     (19U)
/*! DPME3
 *  0b0..No feedback integrity error detected on master port 3
 *  0b1..Feedback integrity error detected on master port 3
 */
#define XBIC_ESR_DPME3(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME3_SHIFT)) & XBIC_ESR_DPME3_MASK)

#define XBIC_ESR_DPME2_MASK                      (0x100000U)
#define XBIC_ESR_DPME2_SHIFT                     (20U)
/*! DPME2
 *  0b0..No feedback integrity error detected on master port 2
 *  0b1..Feedback integrity error detected on master port 2
 */
#define XBIC_ESR_DPME2(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME2_SHIFT)) & XBIC_ESR_DPME2_MASK)

#define XBIC_ESR_DPME1_MASK                      (0x200000U)
#define XBIC_ESR_DPME1_SHIFT                     (21U)
/*! DPME1
 *  0b0..No feedback integrity error detected on master port 1
 *  0b1..Feedback integrity error detected on master port 1
 */
#define XBIC_ESR_DPME1(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME1_SHIFT)) & XBIC_ESR_DPME1_MASK)

#define XBIC_ESR_DPME0_MASK                      (0x400000U)
#define XBIC_ESR_DPME0_SHIFT                     (22U)
/*! DPME0
 *  0b0..No feedback integrity error detected on master port 0
 *  0b1..Feedback integrity error detected on master port 0
 */
#define XBIC_ESR_DPME0(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPME0_SHIFT)) & XBIC_ESR_DPME0_MASK)

#define XBIC_ESR_DPSE7_MASK                      (0x800000U)
#define XBIC_ESR_DPSE7_SHIFT                     (23U)
/*! DPSE7
 *  0b0..No feedback integrity error detected on slave port 7
 *  0b1..Feedback integrity error detected on slave port 7
 */
#define XBIC_ESR_DPSE7(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE7_SHIFT)) & XBIC_ESR_DPSE7_MASK)

#define XBIC_ESR_DPSE6_MASK                      (0x1000000U)
#define XBIC_ESR_DPSE6_SHIFT                     (24U)
/*! DPSE6
 *  0b0..No feedback integrity error detected on slave port 6
 *  0b1..Feedback integrity error detected on slave port 6
 */
#define XBIC_ESR_DPSE6(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE6_SHIFT)) & XBIC_ESR_DPSE6_MASK)

#define XBIC_ESR_DPSE5_MASK                      (0x2000000U)
#define XBIC_ESR_DPSE5_SHIFT                     (25U)
/*! DPSE5
 *  0b0..No feedback integrity error detected on slave port 5
 *  0b1..Feedback integrity error detected on slave port 5
 */
#define XBIC_ESR_DPSE5(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE5_SHIFT)) & XBIC_ESR_DPSE5_MASK)

#define XBIC_ESR_DPSE4_MASK                      (0x4000000U)
#define XBIC_ESR_DPSE4_SHIFT                     (26U)
/*! DPSE4
 *  0b0..No feedback integrity error detected on slave port 4
 *  0b1..Feedback integrity error detected on slave port 4
 */
#define XBIC_ESR_DPSE4(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE4_SHIFT)) & XBIC_ESR_DPSE4_MASK)

#define XBIC_ESR_DPSE3_MASK                      (0x8000000U)
#define XBIC_ESR_DPSE3_SHIFT                     (27U)
/*! DPSE3
 *  0b0..No feedback integrity error detected on slave port 3
 *  0b1..Feedback integrity error detected on slave port 3
 */
#define XBIC_ESR_DPSE3(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE3_SHIFT)) & XBIC_ESR_DPSE3_MASK)

#define XBIC_ESR_DPSE2_MASK                      (0x10000000U)
#define XBIC_ESR_DPSE2_SHIFT                     (28U)
/*! DPSE2
 *  0b0..No feedback integrity error detected on slave port 2
 *  0b1..Feedback integrity error detected on slave port 2
 */
#define XBIC_ESR_DPSE2(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE2_SHIFT)) & XBIC_ESR_DPSE2_MASK)

#define XBIC_ESR_DPSE1_MASK                      (0x20000000U)
#define XBIC_ESR_DPSE1_SHIFT                     (29U)
/*! DPSE1
 *  0b0..No feedback integrity error detected on slave port 1
 *  0b1..Feedback integrity error detected on slave port 1
 */
#define XBIC_ESR_DPSE1(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE1_SHIFT)) & XBIC_ESR_DPSE1_MASK)

#define XBIC_ESR_DPSE0_MASK                      (0x40000000U)
#define XBIC_ESR_DPSE0_SHIFT                     (30U)
/*! DPSE0
 *  0b0..No feedback integrity error detected on slave port 0
 *  0b1..Feedback integrity error detected on slave port 0
 */
#define XBIC_ESR_DPSE0(x)                        (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_DPSE0_SHIFT)) & XBIC_ESR_DPSE0_MASK)

#define XBIC_ESR_VLD_MASK                        (0x80000000U)
#define XBIC_ESR_VLD_SHIFT                       (31U)
/*! VLD
 *  0b0..No error detected-other fields of the ESR and EAR registers are invalid
 *  0b1..Error detected-all fields of the ESR and EAR registers are valid
 */
#define XBIC_ESR_VLD(x)                          (((uint32_t)(((uint32_t)(x)) << XBIC_ESR_VLD_SHIFT)) & XBIC_ESR_VLD_MASK)
/*! @} */

/*! @name EAR - XBIC Error Address */
/*! @{ */

#define XBIC_EAR_ADDR_MASK                       (0xFFFFFFFFU)
#define XBIC_EAR_ADDR_SHIFT                      (0U)
/*! ADDR - Error Address */
#define XBIC_EAR_ADDR(x)                         (((uint32_t)(((uint32_t)(x)) << XBIC_EAR_ADDR_SHIFT)) & XBIC_EAR_ADDR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XBIC_Register_Masks */


/*!
 * @}
 */ /* end of group XBIC_Peripheral_Access_Layer */


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


#endif  /* PERI_XBIC_H_ */

