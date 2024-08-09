/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CORESIGHT_PROGRAMMING_MODEL.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CORESIGHT_PROGRAMMING_MODEL
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
#if !defined(S32Z2_CORESIGHT_PROGRAMMING_MODEL_H_)  /* Check if memory map has not been already included */
#define S32Z2_CORESIGHT_PROGRAMMING_MODEL_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CORESIGHT_PROGRAMMING_MODEL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CORESIGHT_PROGRAMMING_MODEL_Peripheral_Access_Layer CORESIGHT_PROGRAMMING_MODEL Peripheral Access Layer
 * @{
 */

/** CORESIGHT_PROGRAMMING_MODEL - Register Layout Typedef */
typedef struct {
  __I  uint32_t P_ID4;                             /**< PMSS ID4 Register, offset: 0x0 */
  uint8_t RESERVED_0[12];
  __I  uint32_t P_ID0;                             /**< PMSS ID0 Register, offset: 0x10 */
  __I  uint32_t P_ID1;                             /**< PMSS ID1 Register, offset: 0x14 */
  __I  uint32_t P_ID2;                             /**< PMSS ID2 Register, offset: 0x18 */
  __I  uint32_t P_ID3;                             /**< PMSS ID3 Register, offset: 0x1C */
  __I  uint32_t C_ID0;                             /**< Core ID0 Register, offset: 0x20 */
  __I  uint32_t C_ID1;                             /**< Core ID1 Register, offset: 0x24 */
  __I  uint32_t C_ID2;                             /**< Core ID2 Register, offset: 0x28 */
  __I  uint32_t C_ID3;                             /**< Core ID3 Register, offset: 0x2C */
} CORESIGHT_PROGRAMMING_MODEL_Type, *CORESIGHT_PROGRAMMING_MODEL_MemMapPtr;

/** Number of instances of the CORESIGHT_PROGRAMMING_MODEL module. */
#define CORESIGHT_PROGRAMMING_MODEL_INSTANCE_COUNT (1u)

/* CORESIGHT_PROGRAMMING_MODEL - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2_APB__CORESIGHT_PROGRAMMING_MODEL base address */
#define IP_CEVA_SPF2_APB__CORESIGHT_PROGRAMMING_MODEL_BASE (0x4D180FD0u)
/** Peripheral CEVA_SPF2_APB__CORESIGHT_PROGRAMMING_MODEL base pointer */
#define IP_CEVA_SPF2_APB__CORESIGHT_PROGRAMMING_MODEL ((CORESIGHT_PROGRAMMING_MODEL_Type *)IP_CEVA_SPF2_APB__CORESIGHT_PROGRAMMING_MODEL_BASE)
/** Array initializer of CORESIGHT_PROGRAMMING_MODEL peripheral base addresses */
#define IP_CORESIGHT_PROGRAMMING_MODEL_BASE_ADDRS { IP_CEVA_SPF2_APB__CORESIGHT_PROGRAMMING_MODEL_BASE }
/** Array initializer of CORESIGHT_PROGRAMMING_MODEL peripheral base pointers */
#define IP_CORESIGHT_PROGRAMMING_MODEL_BASE_PTRS { IP_CEVA_SPF2_APB__CORESIGHT_PROGRAMMING_MODEL }

/* ----------------------------------------------------------------------------
   -- CORESIGHT_PROGRAMMING_MODEL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CORESIGHT_PROGRAMMING_MODEL_Register_Masks CORESIGHT_PROGRAMMING_MODEL Register Masks
 * @{
 */

/*! @name P_ID4 - PMSS ID4 Register */
/*! @{ */

#define CORESIGHT_PROGRAMMING_MODEL_P_ID4_JEP106_CC_MASK (0xFU)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID4_JEP106_CC_SHIFT (0U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID4_JEP106_CC_WIDTH (4U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID4_JEP106_CC(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_P_ID4_JEP106_CC_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_P_ID4_JEP106_CC_MASK)

#define CORESIGHT_PROGRAMMING_MODEL_P_ID4_FOURKB_C_MASK (0xF0U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID4_FOURKB_C_SHIFT (4U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID4_FOURKB_C_WIDTH (4U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID4_FOURKB_C(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_P_ID4_FOURKB_C_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_P_ID4_FOURKB_C_MASK)
/*! @} */

/*! @name P_ID0 - PMSS ID0 Register */
/*! @{ */

#define CORESIGHT_PROGRAMMING_MODEL_P_ID0_PN_L_MASK (0xFFU)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID0_PN_L_SHIFT (0U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID0_PN_L_WIDTH (8U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID0_PN_L(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_P_ID0_PN_L_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_P_ID0_PN_L_MASK)
/*! @} */

/*! @name P_ID1 - PMSS ID1 Register */
/*! @{ */

#define CORESIGHT_PROGRAMMING_MODEL_P_ID1_PN_M_MASK (0xFU)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID1_PN_M_SHIFT (0U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID1_PN_M_WIDTH (4U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID1_PN_M(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_P_ID1_PN_M_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_P_ID1_PN_M_MASK)

#define CORESIGHT_PROGRAMMING_MODEL_P_ID1_JEP106_ICL_MASK (0xF0U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID1_JEP106_ICL_SHIFT (4U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID1_JEP106_ICL_WIDTH (4U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID1_JEP106_ICL(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_P_ID1_JEP106_ICL_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_P_ID1_JEP106_ICL_MASK)
/*! @} */

/*! @name P_ID2 - PMSS ID2 Register */
/*! @{ */

#define CORESIGHT_PROGRAMMING_MODEL_P_ID2_JEP106_ICH_MASK (0x3U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID2_JEP106_ICH_SHIFT (0U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID2_JEP106_ICH_WIDTH (2U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID2_JEP106_ICH(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_P_ID2_JEP106_ICH_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_P_ID2_JEP106_ICH_MASK)

#define CORESIGHT_PROGRAMMING_MODEL_P_ID2_JEDEC_A_MASK (0x8U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID2_JEDEC_A_SHIFT (3U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID2_JEDEC_A_WIDTH (1U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID2_JEDEC_A(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_P_ID2_JEDEC_A_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_P_ID2_JEDEC_A_MASK)

#define CORESIGHT_PROGRAMMING_MODEL_P_ID2_REV_MASK (0xF0U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID2_REV_SHIFT (4U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID2_REV_WIDTH (4U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID2_REV(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_P_ID2_REV_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_P_ID2_REV_MASK)
/*! @} */

/*! @name P_ID3 - PMSS ID3 Register */
/*! @{ */

#define CORESIGHT_PROGRAMMING_MODEL_P_ID3_CU_MO_MASK (0xFU)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID3_CU_MO_SHIFT (0U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID3_CU_MO_WIDTH (4U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID3_CU_MO(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_P_ID3_CU_MO_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_P_ID3_CU_MO_MASK)

#define CORESIGHT_PROGRAMMING_MODEL_P_ID3_RE_AN_MASK (0xF0U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID3_RE_AN_SHIFT (4U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID3_RE_AN_WIDTH (4U)
#define CORESIGHT_PROGRAMMING_MODEL_P_ID3_RE_AN(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_P_ID3_RE_AN_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_P_ID3_RE_AN_MASK)
/*! @} */

/*! @name C_ID0 - Core ID0 Register */
/*! @{ */

#define CORESIGHT_PROGRAMMING_MODEL_C_ID0_ID0_VAL_MASK (0xFFU)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID0_ID0_VAL_SHIFT (0U)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID0_ID0_VAL_WIDTH (8U)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID0_ID0_VAL(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_C_ID0_ID0_VAL_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_C_ID0_ID0_VAL_MASK)
/*! @} */

/*! @name C_ID1 - Core ID1 Register */
/*! @{ */

#define CORESIGHT_PROGRAMMING_MODEL_C_ID1_ID1_VAL_MASK (0xFU)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID1_ID1_VAL_SHIFT (0U)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID1_ID1_VAL_WIDTH (4U)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID1_ID1_VAL(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_C_ID1_ID1_VAL_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_C_ID1_ID1_VAL_MASK)

#define CORESIGHT_PROGRAMMING_MODEL_C_ID1_CCLA_MASK (0xF0U)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID1_CCLA_SHIFT (4U)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID1_CCLA_WIDTH (4U)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID1_CCLA(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_C_ID1_CCLA_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_C_ID1_CCLA_MASK)
/*! @} */

/*! @name C_ID2 - Core ID2 Register */
/*! @{ */

#define CORESIGHT_PROGRAMMING_MODEL_C_ID2_ID2_VAL_MASK (0xFFU)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID2_ID2_VAL_SHIFT (0U)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID2_ID2_VAL_WIDTH (8U)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID2_ID2_VAL(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_C_ID2_ID2_VAL_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_C_ID2_ID2_VAL_MASK)
/*! @} */

/*! @name C_ID3 - Core ID3 Register */
/*! @{ */

#define CORESIGHT_PROGRAMMING_MODEL_C_ID3_ID3_VAL_MASK (0xFFU)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID3_ID3_VAL_SHIFT (0U)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID3_ID3_VAL_WIDTH (8U)
#define CORESIGHT_PROGRAMMING_MODEL_C_ID3_ID3_VAL(x) (((uint32_t)(((uint32_t)(x)) << CORESIGHT_PROGRAMMING_MODEL_C_ID3_ID3_VAL_SHIFT)) & CORESIGHT_PROGRAMMING_MODEL_C_ID3_ID3_VAL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CORESIGHT_PROGRAMMING_MODEL_Register_Masks */

/*!
 * @}
 */ /* end of group CORESIGHT_PROGRAMMING_MODEL_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CORESIGHT_PROGRAMMING_MODEL_H_) */
