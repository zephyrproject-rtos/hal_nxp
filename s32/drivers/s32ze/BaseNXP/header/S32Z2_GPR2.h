/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_GPR2.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_GPR2
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32Z2_GPR2_H_)  /* Check if memory map has not been already included */
#define S32Z2_GPR2_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- GPR2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPR2_Peripheral_Access_Layer GPR2 Peripheral Access Layer
 * @{
 */

/** GPR2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LVFCCUGD2;                         /**< VFCCU Global DID register 2, offset: 0x0 */
  __IO uint32_t LVFCCULD6;                         /**< VFCCU Local DID register 6, offset: 0x4 */
  __IO uint32_t LVFCCULD7;                         /**< VFCCU Local DID register 7, offset: 0x8 */
  __IO uint32_t LVFCCULD8;                         /**< VFCCU Local DID register 8, offset: 0xC */
  __IO uint32_t SPF2C;                             /**< CEVA_SPF2 Control, offset: 0x10 */
  uint8_t RESERVED_0[36];
  __IO uint32_t FUNCC4;                            /**< Miscellaneous Control, offset: 0x38 */
  uint8_t RESERVED_1[12];
  __I  uint32_t INITM2;                            /**< NoC Initiator NIU Timeout Status, offset: 0x48 */
  __I  uint32_t TARGTMS2;                          /**< NoC Target NIU Timeout Status, offset: 0x4C */
  __IO uint32_t TARGTMC2;                          /**< NoC Target NIU Timeout Control, offset: 0x50 */
  uint8_t RESERVED_2[4];
  __IO uint32_t SMURSTCNT;                         /**< SMU Cortex-M33 Core Reset Counter, offset: 0x58 */
  uint8_t RESERVED_3[4];
  __I  uint32_t SMUS;                              /**< SMU Cortex-M33 Core Status, offset: 0x60 */
  uint8_t RESERVED_4[28];
  __IO uint32_t XPAR2;                             /**< Interface parity control and status register, offset: 0x80 */
} GPR2_Type, *GPR2_MemMapPtr;

/** Number of instances of the GPR2 module. */
#define GPR2_INSTANCE_COUNT                      (1u)

/* GPR2 - Peripheral instance base addresses */
/** Peripheral GPR2 base address */
#define IP_GPR2_BASE                             (0x41060000u)
/** Peripheral GPR2 base pointer */
#define IP_GPR2                                  ((GPR2_Type *)IP_GPR2_BASE)
/** Array initializer of GPR2 peripheral base addresses */
#define IP_GPR2_BASE_ADDRS                       { IP_GPR2_BASE }
/** Array initializer of GPR2 peripheral base pointers */
#define IP_GPR2_BASE_PTRS                        { IP_GPR2 }

/* ----------------------------------------------------------------------------
   -- GPR2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPR2_Register_Masks GPR2 Register Masks
 * @{
 */

/*! @name LVFCCUGD2 - VFCCU Global DID register 2 */
/*! @{ */

#define GPR2_LVFCCUGD2_FHID_MASK                 (0xFU)
#define GPR2_LVFCCUGD2_FHID_SHIFT                (0U)
#define GPR2_LVFCCUGD2_FHID_WIDTH                (4U)
#define GPR2_LVFCCUGD2_FHID(x)                   (((uint32_t)(((uint32_t)(x)) << GPR2_LVFCCUGD2_FHID_SHIFT)) & GPR2_LVFCCUGD2_FHID_MASK)
/*! @} */

/*! @name LVFCCULD6 - VFCCU Local DID register 6 */
/*! @{ */

#define GPR2_LVFCCULD6_FHID_MASK                 (0xFFFFFFFFU)
#define GPR2_LVFCCULD6_FHID_SHIFT                (0U)
#define GPR2_LVFCCULD6_FHID_WIDTH                (32U)
#define GPR2_LVFCCULD6_FHID(x)                   (((uint32_t)(((uint32_t)(x)) << GPR2_LVFCCULD6_FHID_SHIFT)) & GPR2_LVFCCULD6_FHID_MASK)
/*! @} */

/*! @name LVFCCULD7 - VFCCU Local DID register 7 */
/*! @{ */

#define GPR2_LVFCCULD7_FHID_MASK                 (0xFFFFFFFFU)
#define GPR2_LVFCCULD7_FHID_SHIFT                (0U)
#define GPR2_LVFCCULD7_FHID_WIDTH                (32U)
#define GPR2_LVFCCULD7_FHID(x)                   (((uint32_t)(((uint32_t)(x)) << GPR2_LVFCCULD7_FHID_SHIFT)) & GPR2_LVFCCULD7_FHID_MASK)
/*! @} */

/*! @name LVFCCULD8 - VFCCU Local DID register 8 */
/*! @{ */

#define GPR2_LVFCCULD8_FHID_MASK                 (0xFFFFFFFFU)
#define GPR2_LVFCCULD8_FHID_SHIFT                (0U)
#define GPR2_LVFCCULD8_FHID_WIDTH                (32U)
#define GPR2_LVFCCULD8_FHID(x)                   (((uint32_t)(((uint32_t)(x)) << GPR2_LVFCCULD8_FHID_SHIFT)) & GPR2_LVFCCULD8_FHID_MASK)
/*! @} */

/*! @name SPF2C - CEVA_SPF2 Control */
/*! @{ */

#define GPR2_SPF2C_PGEN_MASK                     (0x1U)
#define GPR2_SPF2C_PGEN_SHIFT                    (0U)
#define GPR2_SPF2C_PGEN_WIDTH                    (1U)
#define GPR2_SPF2C_PGEN(x)                       (((uint32_t)(((uint32_t)(x)) << GPR2_SPF2C_PGEN_SHIFT)) & GPR2_SPF2C_PGEN_MASK)

#define GPR2_SPF2C_RET1N_MASK                    (0x2U)
#define GPR2_SPF2C_RET1N_SHIFT                   (1U)
#define GPR2_SPF2C_RET1N_WIDTH                   (1U)
#define GPR2_SPF2C_RET1N(x)                      (((uint32_t)(((uint32_t)(x)) << GPR2_SPF2C_RET1N_SHIFT)) & GPR2_SPF2C_RET1N_MASK)

#define GPR2_SPF2C_RET2N_MASK                    (0x4U)
#define GPR2_SPF2C_RET2N_SHIFT                   (2U)
#define GPR2_SPF2C_RET2N_WIDTH                   (1U)
#define GPR2_SPF2C_RET2N(x)                      (((uint32_t)(((uint32_t)(x)) << GPR2_SPF2C_RET2N_SHIFT)) & GPR2_SPF2C_RET2N_MASK)

#define GPR2_SPF2C_ACULOCK_MASK                  (0x8U)
#define GPR2_SPF2C_ACULOCK_SHIFT                 (3U)
#define GPR2_SPF2C_ACULOCK_WIDTH                 (1U)
#define GPR2_SPF2C_ACULOCK(x)                    (((uint32_t)(((uint32_t)(x)) << GPR2_SPF2C_ACULOCK_SHIFT)) & GPR2_SPF2C_ACULOCK_MASK)

#define GPR2_SPF2C_ICULOCK_MASK                  (0x10U)
#define GPR2_SPF2C_ICULOCK_SHIFT                 (4U)
#define GPR2_SPF2C_ICULOCK_WIDTH                 (1U)
#define GPR2_SPF2C_ICULOCK(x)                    (((uint32_t)(((uint32_t)(x)) << GPR2_SPF2C_ICULOCK_SHIFT)) & GPR2_SPF2C_ICULOCK_MASK)
/*! @} */

/*! @name FUNCC4 - Miscellaneous Control */
/*! @{ */

#define GPR2_FUNCC4_CTRL_MASK                    (0xFFFFFFFFU)
#define GPR2_FUNCC4_CTRL_SHIFT                   (0U)
#define GPR2_FUNCC4_CTRL_WIDTH                   (32U)
#define GPR2_FUNCC4_CTRL(x)                      (((uint32_t)(((uint32_t)(x)) << GPR2_FUNCC4_CTRL_SHIFT)) & GPR2_FUNCC4_CTRL_MASK)
/*! @} */

/*! @name INITM2 - NoC Initiator NIU Timeout Status */
/*! @{ */

#define GPR2_INITM2_STAT_MASK                    (0xFFFFFFFFU)
#define GPR2_INITM2_STAT_SHIFT                   (0U)
#define GPR2_INITM2_STAT_WIDTH                   (32U)
#define GPR2_INITM2_STAT(x)                      (((uint32_t)(((uint32_t)(x)) << GPR2_INITM2_STAT_SHIFT)) & GPR2_INITM2_STAT_MASK)
/*! @} */

/*! @name TARGTMS2 - NoC Target NIU Timeout Status */
/*! @{ */

#define GPR2_TARGTMS2_STAT_MASK                  (0xFFFFFFFFU)
#define GPR2_TARGTMS2_STAT_SHIFT                 (0U)
#define GPR2_TARGTMS2_STAT_WIDTH                 (32U)
#define GPR2_TARGTMS2_STAT(x)                    (((uint32_t)(((uint32_t)(x)) << GPR2_TARGTMS2_STAT_SHIFT)) & GPR2_TARGTMS2_STAT_MASK)
/*! @} */

/*! @name TARGTMC2 - NoC Target NIU Timeout Control */
/*! @{ */

#define GPR2_TARGTMC2_EN_MASK                    (0xFFFFFFFFU)
#define GPR2_TARGTMC2_EN_SHIFT                   (0U)
#define GPR2_TARGTMC2_EN_WIDTH                   (32U)
#define GPR2_TARGTMC2_EN(x)                      (((uint32_t)(((uint32_t)(x)) << GPR2_TARGTMC2_EN_SHIFT)) & GPR2_TARGTMC2_EN_MASK)
/*! @} */

/*! @name SMURSTCNT - SMU Cortex-M33 Core Reset Counter */
/*! @{ */

#define GPR2_SMURSTCNT_CNTVAL_MASK               (0x3FU)
#define GPR2_SMURSTCNT_CNTVAL_SHIFT              (0U)
#define GPR2_SMURSTCNT_CNTVAL_WIDTH              (6U)
#define GPR2_SMURSTCNT_CNTVAL(x)                 (((uint32_t)(((uint32_t)(x)) << GPR2_SMURSTCNT_CNTVAL_SHIFT)) & GPR2_SMURSTCNT_CNTVAL_MASK)
/*! @} */

/*! @name SMUS - SMU Cortex-M33 Core Status */
/*! @{ */

#define GPR2_SMUS_SLEEPDEEP_MASK                 (0x1U)
#define GPR2_SMUS_SLEEPDEEP_SHIFT                (0U)
#define GPR2_SMUS_SLEEPDEEP_WIDTH                (1U)
#define GPR2_SMUS_SLEEPDEEP(x)                   (((uint32_t)(((uint32_t)(x)) << GPR2_SMUS_SLEEPDEEP_SHIFT)) & GPR2_SMUS_SLEEPDEEP_MASK)

#define GPR2_SMUS_SLEEPHOLDAn_MASK               (0x2U)
#define GPR2_SMUS_SLEEPHOLDAn_SHIFT              (1U)
#define GPR2_SMUS_SLEEPHOLDAn_WIDTH              (1U)
#define GPR2_SMUS_SLEEPHOLDAn(x)                 (((uint32_t)(((uint32_t)(x)) << GPR2_SMUS_SLEEPHOLDAn_SHIFT)) & GPR2_SMUS_SLEEPHOLDAn_MASK)

#define GPR2_SMUS_SLEEPING_MASK                  (0x4U)
#define GPR2_SMUS_SLEEPING_SHIFT                 (2U)
#define GPR2_SMUS_SLEEPING_WIDTH                 (1U)
#define GPR2_SMUS_SLEEPING(x)                    (((uint32_t)(((uint32_t)(x)) << GPR2_SMUS_SLEEPING_SHIFT)) & GPR2_SMUS_SLEEPING_MASK)

#define GPR2_SMUS_CORECLKEN_MASK                 (0x8U)
#define GPR2_SMUS_CORECLKEN_SHIFT                (3U)
#define GPR2_SMUS_CORECLKEN_WIDTH                (1U)
#define GPR2_SMUS_CORECLKEN(x)                   (((uint32_t)(((uint32_t)(x)) << GPR2_SMUS_CORECLKEN_SHIFT)) & GPR2_SMUS_CORECLKEN_MASK)

#define GPR2_SMUS_INTVFETCH_MASK                 (0x10U)
#define GPR2_SMUS_INTVFETCH_SHIFT                (4U)
#define GPR2_SMUS_INTVFETCH_WIDTH                (1U)
#define GPR2_SMUS_INTVFETCH(x)                   (((uint32_t)(((uint32_t)(x)) << GPR2_SMUS_INTVFETCH_SHIFT)) & GPR2_SMUS_INTVFETCH_MASK)

#define GPR2_SMUS_CPULOCKUP_MASK                 (0x20U)
#define GPR2_SMUS_CPULOCKUP_SHIFT                (5U)
#define GPR2_SMUS_CPULOCKUP_WIDTH                (1U)
#define GPR2_SMUS_CPULOCKUP(x)                   (((uint32_t)(((uint32_t)(x)) << GPR2_SMUS_CPULOCKUP_SHIFT)) & GPR2_SMUS_CPULOCKUP_MASK)

#define GPR2_SMUS_CURRNS_MASK                    (0x40U)
#define GPR2_SMUS_CURRNS_SHIFT                   (6U)
#define GPR2_SMUS_CURRNS_WIDTH                   (1U)
#define GPR2_SMUS_CURRNS(x)                      (((uint32_t)(((uint32_t)(x)) << GPR2_SMUS_CURRNS_SHIFT)) & GPR2_SMUS_CURRNS_MASK)

#define GPR2_SMUS_SYSRSTREQ_MASK                 (0x80U)
#define GPR2_SMUS_SYSRSTREQ_SHIFT                (7U)
#define GPR2_SMUS_SYSRSTREQ_WIDTH                (1U)
#define GPR2_SMUS_SYSRSTREQ(x)                   (((uint32_t)(((uint32_t)(x)) << GPR2_SMUS_SYSRSTREQ_SHIFT)) & GPR2_SMUS_SYSRSTREQ_MASK)
/*! @} */

/*! @name XPAR2 - Interface parity control and status register */
/*! @{ */

#define GPR2_XPAR2_DIS_MASK                      (0x1FU)
#define GPR2_XPAR2_DIS_SHIFT                     (0U)
#define GPR2_XPAR2_DIS_WIDTH                     (5U)
#define GPR2_XPAR2_DIS(x)                        (((uint32_t)(((uint32_t)(x)) << GPR2_XPAR2_DIS_SHIFT)) & GPR2_XPAR2_DIS_MASK)

#define GPR2_XPAR2_STAT_MASK                     (0x1F00U)
#define GPR2_XPAR2_STAT_SHIFT                    (8U)
#define GPR2_XPAR2_STAT_WIDTH                    (5U)
#define GPR2_XPAR2_STAT(x)                       (((uint32_t)(((uint32_t)(x)) << GPR2_XPAR2_STAT_SHIFT)) & GPR2_XPAR2_STAT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group GPR2_Register_Masks */

/*!
 * @}
 */ /* end of group GPR2_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_GPR2_H_) */
