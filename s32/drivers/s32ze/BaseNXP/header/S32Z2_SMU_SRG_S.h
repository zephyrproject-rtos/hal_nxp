/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_SMU_SRG_S.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_SMU_SRG_S
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
#if !defined(S32Z2_SMU_SRG_S_H_)  /* Check if memory map has not been already included */
#define S32Z2_SMU_SRG_S_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SMU_SRG_S Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMU_SRG_S_Peripheral_Access_Layer SMU_SRG_S Peripheral Access Layer
 * @{
 */

/** SMU_SRG_S - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR0;                               /**< Control 0, offset: 0x0 */
  uint8_t RESERVED_0[252];
  __IO uint32_t LCR0;                              /**< Lock Control 0, offset: 0x100 */
  uint8_t RESERVED_1[4];
  __IO uint32_t LCR2;                              /**< Lock Control 2, offset: 0x108 */
  __IO uint32_t LCR3;                              /**< Lock Control 3, offset: 0x10C */
  __IO uint32_t LCR4;                              /**< Lock Control 4, offset: 0x110 */
  uint8_t RESERVED_2[8];
  __IO uint32_t LCR7;                              /**< Lock Control 7, offset: 0x11C */
  uint8_t RESERVED_3[224];
  __IO uint32_t SR0;                               /**< Status 0, offset: 0x200 */
} SMU_SRG_S_Type, *SMU_SRG_S_MemMapPtr;

/** Number of instances of the SMU_SRG_S module. */
#define SMU_SRG_S_INSTANCE_COUNT                 (1u)

/* SMU_SRG_S - Peripheral instance base addresses */
/** Peripheral SMU__SRG_S base address */
#define IP_SMU__SRG_S_BASE                       (0x45064000u)
/** Peripheral SMU__SRG_S base pointer */
#define IP_SMU__SRG_S                            ((SMU_SRG_S_Type *)IP_SMU__SRG_S_BASE)
/** Array initializer of SMU_SRG_S peripheral base addresses */
#define IP_SMU_SRG_S_BASE_ADDRS                  { IP_SMU__SRG_S_BASE }
/** Array initializer of SMU_SRG_S peripheral base pointers */
#define IP_SMU_SRG_S_BASE_PTRS                   { IP_SMU__SRG_S }

/* ----------------------------------------------------------------------------
   -- SMU_SRG_S Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMU_SRG_S_Register_Masks SMU_SRG_S Register Masks
 * @{
 */

/*! @name CR0 - Control 0 */
/*! @{ */

#define SMU_SRG_S_CR0_MSTR0DOW_MASK              (0x1U)
#define SMU_SRG_S_CR0_MSTR0DOW_SHIFT             (0U)
#define SMU_SRG_S_CR0_MSTR0DOW_WIDTH             (1U)
#define SMU_SRG_S_CR0_MSTR0DOW(x)                (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_CR0_MSTR0DOW_SHIFT)) & SMU_SRG_S_CR0_MSTR0DOW_MASK)

#define SMU_SRG_S_CR0_CCMDOW_MASK                (0x2U)
#define SMU_SRG_S_CR0_CCMDOW_SHIFT               (1U)
#define SMU_SRG_S_CR0_CCMDOW_WIDTH               (1U)
#define SMU_SRG_S_CR0_CCMDOW(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_CR0_CCMDOW_SHIFT)) & SMU_SRG_S_CR0_CCMDOW_MASK)

#define SMU_SRG_S_CR0_CSMDOW_MASK                (0x4U)
#define SMU_SRG_S_CR0_CSMDOW_SHIFT               (2U)
#define SMU_SRG_S_CR0_CSMDOW_WIDTH               (1U)
#define SMU_SRG_S_CR0_CSMDOW(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_CR0_CSMDOW_SHIFT)) & SMU_SRG_S_CR0_CSMDOW_MASK)

#define SMU_SRG_S_CR0_DEDOW_MASK                 (0x8U)
#define SMU_SRG_S_CR0_DEDOW_SHIFT                (3U)
#define SMU_SRG_S_CR0_DEDOW_WIDTH                (1U)
#define SMU_SRG_S_CR0_DEDOW(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_CR0_DEDOW_SHIFT)) & SMU_SRG_S_CR0_DEDOW_MASK)

#define SMU_SRG_S_CR0_MSTR0HPE_MASK              (0x100U)
#define SMU_SRG_S_CR0_MSTR0HPE_SHIFT             (8U)
#define SMU_SRG_S_CR0_MSTR0HPE_WIDTH             (1U)
#define SMU_SRG_S_CR0_MSTR0HPE(x)                (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_CR0_MSTR0HPE_SHIFT)) & SMU_SRG_S_CR0_MSTR0HPE_MASK)

#define SMU_SRG_S_CR0_CCMHPE_MASK                (0x200U)
#define SMU_SRG_S_CR0_CCMHPE_SHIFT               (9U)
#define SMU_SRG_S_CR0_CCMHPE_WIDTH               (1U)
#define SMU_SRG_S_CR0_CCMHPE(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_CR0_CCMHPE_SHIFT)) & SMU_SRG_S_CR0_CCMHPE_MASK)

#define SMU_SRG_S_CR0_CSMHPE_MASK                (0x400U)
#define SMU_SRG_S_CR0_CSMHPE_SHIFT               (10U)
#define SMU_SRG_S_CR0_CSMHPE_WIDTH               (1U)
#define SMU_SRG_S_CR0_CSMHPE(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_CR0_CSMHPE_SHIFT)) & SMU_SRG_S_CR0_CSMHPE_MASK)

#define SMU_SRG_S_CR0_SLV0SBE_MASK               (0x10000U)
#define SMU_SRG_S_CR0_SLV0SBE_SHIFT              (16U)
#define SMU_SRG_S_CR0_SLV0SBE_WIDTH              (1U)
#define SMU_SRG_S_CR0_SLV0SBE(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_CR0_SLV0SBE_SHIFT)) & SMU_SRG_S_CR0_SLV0SBE_MASK)

#define SMU_SRG_S_CR0_AIPS0SBE_MASK              (0x20000U)
#define SMU_SRG_S_CR0_AIPS0SBE_SHIFT             (17U)
#define SMU_SRG_S_CR0_AIPS0SBE_WIDTH             (1U)
#define SMU_SRG_S_CR0_AIPS0SBE(x)                (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_CR0_AIPS0SBE_SHIFT)) & SMU_SRG_S_CR0_AIPS0SBE_MASK)

#define SMU_SRG_S_CR0_AIPS1SBE_MASK              (0x40000U)
#define SMU_SRG_S_CR0_AIPS1SBE_SHIFT             (18U)
#define SMU_SRG_S_CR0_AIPS1SBE_WIDTH             (1U)
#define SMU_SRG_S_CR0_AIPS1SBE(x)                (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_CR0_AIPS1SBE_SHIFT)) & SMU_SRG_S_CR0_AIPS1SBE_MASK)
/*! @} */

/*! @name LCR0 - Lock Control 0 */
/*! @{ */

#define SMU_SRG_S_LCR0_LNSMPU_MASK               (0x10000U)
#define SMU_SRG_S_LCR0_LNSMPU_SHIFT              (16U)
#define SMU_SRG_S_LCR0_LNSMPU_WIDTH              (1U)
#define SMU_SRG_S_LCR0_LNSMPU(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR0_LNSMPU_SHIFT)) & SMU_SRG_S_LCR0_LNSMPU_MASK)

#define SMU_SRG_S_LCR0_LNSVTOR_MASK              (0x40000U)
#define SMU_SRG_S_LCR0_LNSVTOR_SHIFT             (18U)
#define SMU_SRG_S_LCR0_LNSVTOR_WIDTH             (1U)
#define SMU_SRG_S_LCR0_LNSVTOR(x)                (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR0_LNSVTOR_SHIFT)) & SMU_SRG_S_LCR0_LNSVTOR_MASK)

#define SMU_SRG_S_LCR0_DID_MASK                  (0xF000000U)
#define SMU_SRG_S_LCR0_DID_SHIFT                 (24U)
#define SMU_SRG_S_LCR0_DID_WIDTH                 (4U)
#define SMU_SRG_S_LCR0_DID(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR0_DID_SHIFT)) & SMU_SRG_S_LCR0_DID_MASK)

#define SMU_SRG_S_LCR0_LKR_MASK                  (0xC0000000U)
#define SMU_SRG_S_LCR0_LKR_SHIFT                 (30U)
#define SMU_SRG_S_LCR0_LKR_WIDTH                 (2U)
#define SMU_SRG_S_LCR0_LKR(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR0_LKR_SHIFT)) & SMU_SRG_S_LCR0_LKR_MASK)
/*! @} */

/*! @name LCR2 - Lock Control 2 */
/*! @{ */

#define SMU_SRG_S_LCR2_REMAP_EN_MASK             (0x1U)
#define SMU_SRG_S_LCR2_REMAP_EN_SHIFT            (0U)
#define SMU_SRG_S_LCR2_REMAP_EN_WIDTH            (1U)
#define SMU_SRG_S_LCR2_REMAP_EN(x)               (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR2_REMAP_EN_SHIFT)) & SMU_SRG_S_LCR2_REMAP_EN_MASK)

#define SMU_SRG_S_LCR2_REMAP0_MASK               (0x100U)
#define SMU_SRG_S_LCR2_REMAP0_SHIFT              (8U)
#define SMU_SRG_S_LCR2_REMAP0_WIDTH              (1U)
#define SMU_SRG_S_LCR2_REMAP0(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR2_REMAP0_SHIFT)) & SMU_SRG_S_LCR2_REMAP0_MASK)

#define SMU_SRG_S_LCR2_REMAP1_MASK               (0x200U)
#define SMU_SRG_S_LCR2_REMAP1_SHIFT              (9U)
#define SMU_SRG_S_LCR2_REMAP1_WIDTH              (1U)
#define SMU_SRG_S_LCR2_REMAP1(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR2_REMAP1_SHIFT)) & SMU_SRG_S_LCR2_REMAP1_MASK)

#define SMU_SRG_S_LCR2_REMAP2_MASK               (0x400U)
#define SMU_SRG_S_LCR2_REMAP2_SHIFT              (10U)
#define SMU_SRG_S_LCR2_REMAP2_WIDTH              (1U)
#define SMU_SRG_S_LCR2_REMAP2(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR2_REMAP2_SHIFT)) & SMU_SRG_S_LCR2_REMAP2_MASK)

#define SMU_SRG_S_LCR2_REMAP3_MASK               (0x800U)
#define SMU_SRG_S_LCR2_REMAP3_SHIFT              (11U)
#define SMU_SRG_S_LCR2_REMAP3_WIDTH              (1U)
#define SMU_SRG_S_LCR2_REMAP3(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR2_REMAP3_SHIFT)) & SMU_SRG_S_LCR2_REMAP3_MASK)

#define SMU_SRG_S_LCR2_DID_MASK                  (0xF000000U)
#define SMU_SRG_S_LCR2_DID_SHIFT                 (24U)
#define SMU_SRG_S_LCR2_DID_WIDTH                 (4U)
#define SMU_SRG_S_LCR2_DID(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR2_DID_SHIFT)) & SMU_SRG_S_LCR2_DID_MASK)

#define SMU_SRG_S_LCR2_LKR_MASK                  (0xC0000000U)
#define SMU_SRG_S_LCR2_LKR_SHIFT                 (30U)
#define SMU_SRG_S_LCR2_LKR_WIDTH                 (2U)
#define SMU_SRG_S_LCR2_LKR(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR2_LKR_SHIFT)) & SMU_SRG_S_LCR2_LKR_MASK)
/*! @} */

/*! @name LCR3 - Lock Control 3 */
/*! @{ */

#define SMU_SRG_S_LCR3_R0RO_MASK                 (0xF8U)
#define SMU_SRG_S_LCR3_R0RO_SHIFT                (3U)
#define SMU_SRG_S_LCR3_R0RO_WIDTH                (5U)
#define SMU_SRG_S_LCR3_R0RO(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR3_R0RO_SHIFT)) & SMU_SRG_S_LCR3_R0RO_MASK)

#define SMU_SRG_S_LCR3_R1RO_MASK                 (0xF800U)
#define SMU_SRG_S_LCR3_R1RO_SHIFT                (11U)
#define SMU_SRG_S_LCR3_R1RO_WIDTH                (5U)
#define SMU_SRG_S_LCR3_R1RO(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR3_R1RO_SHIFT)) & SMU_SRG_S_LCR3_R1RO_MASK)

#define SMU_SRG_S_LCR3_DID_MASK                  (0xF000000U)
#define SMU_SRG_S_LCR3_DID_SHIFT                 (24U)
#define SMU_SRG_S_LCR3_DID_WIDTH                 (4U)
#define SMU_SRG_S_LCR3_DID(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR3_DID_SHIFT)) & SMU_SRG_S_LCR3_DID_MASK)

#define SMU_SRG_S_LCR3_LKR_MASK                  (0xC0000000U)
#define SMU_SRG_S_LCR3_LKR_SHIFT                 (30U)
#define SMU_SRG_S_LCR3_LKR_WIDTH                 (2U)
#define SMU_SRG_S_LCR3_LKR(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR3_LKR_SHIFT)) & SMU_SRG_S_LCR3_LKR_MASK)
/*! @} */

/*! @name LCR4 - Lock Control 4 */
/*! @{ */

#define SMU_SRG_S_LCR4_R2RO_MASK                 (0xF8U)
#define SMU_SRG_S_LCR4_R2RO_SHIFT                (3U)
#define SMU_SRG_S_LCR4_R2RO_WIDTH                (5U)
#define SMU_SRG_S_LCR4_R2RO(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR4_R2RO_SHIFT)) & SMU_SRG_S_LCR4_R2RO_MASK)

#define SMU_SRG_S_LCR4_R3RO_MASK                 (0xF800U)
#define SMU_SRG_S_LCR4_R3RO_SHIFT                (11U)
#define SMU_SRG_S_LCR4_R3RO_WIDTH                (5U)
#define SMU_SRG_S_LCR4_R3RO(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR4_R3RO_SHIFT)) & SMU_SRG_S_LCR4_R3RO_MASK)

#define SMU_SRG_S_LCR4_DID_MASK                  (0xF000000U)
#define SMU_SRG_S_LCR4_DID_SHIFT                 (24U)
#define SMU_SRG_S_LCR4_DID_WIDTH                 (4U)
#define SMU_SRG_S_LCR4_DID(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR4_DID_SHIFT)) & SMU_SRG_S_LCR4_DID_MASK)

#define SMU_SRG_S_LCR4_LKR_MASK                  (0xC0000000U)
#define SMU_SRG_S_LCR4_LKR_SHIFT                 (30U)
#define SMU_SRG_S_LCR4_LKR_WIDTH                 (2U)
#define SMU_SRG_S_LCR4_LKR(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR4_LKR_SHIFT)) & SMU_SRG_S_LCR4_LKR_MASK)
/*! @} */

/*! @name LCR7 - Lock Control 7 */
/*! @{ */

#define SMU_SRG_S_LCR7_DBGSA_MASK                (0x10000U)
#define SMU_SRG_S_LCR7_DBGSA_SHIFT               (16U)
#define SMU_SRG_S_LCR7_DBGSA_WIDTH               (1U)
#define SMU_SRG_S_LCR7_DBGSA(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR7_DBGSA_SHIFT)) & SMU_SRG_S_LCR7_DBGSA_MASK)

#define SMU_SRG_S_LCR7_DID_MASK                  (0xF000000U)
#define SMU_SRG_S_LCR7_DID_SHIFT                 (24U)
#define SMU_SRG_S_LCR7_DID_WIDTH                 (4U)
#define SMU_SRG_S_LCR7_DID(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR7_DID_SHIFT)) & SMU_SRG_S_LCR7_DID_MASK)

#define SMU_SRG_S_LCR7_LKR_MASK                  (0xC0000000U)
#define SMU_SRG_S_LCR7_LKR_SHIFT                 (30U)
#define SMU_SRG_S_LCR7_LKR_WIDTH                 (2U)
#define SMU_SRG_S_LCR7_LKR(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_LCR7_LKR_SHIFT)) & SMU_SRG_S_LCR7_LKR_MASK)
/*! @} */

/*! @name SR0 - Status 0 */
/*! @{ */

#define SMU_SRG_S_SR0_R0EA_MASK                  (0x1U)
#define SMU_SRG_S_SR0_R0EA_SHIFT                 (0U)
#define SMU_SRG_S_SR0_R0EA_WIDTH                 (1U)
#define SMU_SRG_S_SR0_R0EA(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_R0EA_SHIFT)) & SMU_SRG_S_SR0_R0EA_MASK)

#define SMU_SRG_S_SR0_R1EA_MASK                  (0x2U)
#define SMU_SRG_S_SR0_R1EA_SHIFT                 (1U)
#define SMU_SRG_S_SR0_R1EA_WIDTH                 (1U)
#define SMU_SRG_S_SR0_R1EA(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_R1EA_SHIFT)) & SMU_SRG_S_SR0_R1EA_MASK)

#define SMU_SRG_S_SR0_R2EA_MASK                  (0x4U)
#define SMU_SRG_S_SR0_R2EA_SHIFT                 (2U)
#define SMU_SRG_S_SR0_R2EA_WIDTH                 (1U)
#define SMU_SRG_S_SR0_R2EA(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_R2EA_SHIFT)) & SMU_SRG_S_SR0_R2EA_MASK)

#define SMU_SRG_S_SR0_R3EA_MASK                  (0x8U)
#define SMU_SRG_S_SR0_R3EA_SHIFT                 (3U)
#define SMU_SRG_S_SR0_R3EA_WIDTH                 (1U)
#define SMU_SRG_S_SR0_R3EA(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_R3EA_SHIFT)) & SMU_SRG_S_SR0_R3EA_MASK)

#define SMU_SRG_S_SR0_R0WEA_MASK                 (0x10U)
#define SMU_SRG_S_SR0_R0WEA_SHIFT                (4U)
#define SMU_SRG_S_SR0_R0WEA_WIDTH                (1U)
#define SMU_SRG_S_SR0_R0WEA(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_R0WEA_SHIFT)) & SMU_SRG_S_SR0_R0WEA_MASK)

#define SMU_SRG_S_SR0_R1WEA_MASK                 (0x20U)
#define SMU_SRG_S_SR0_R1WEA_SHIFT                (5U)
#define SMU_SRG_S_SR0_R1WEA_WIDTH                (1U)
#define SMU_SRG_S_SR0_R1WEA(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_R1WEA_SHIFT)) & SMU_SRG_S_SR0_R1WEA_MASK)

#define SMU_SRG_S_SR0_R2WEA_MASK                 (0x40U)
#define SMU_SRG_S_SR0_R2WEA_SHIFT                (6U)
#define SMU_SRG_S_SR0_R2WEA_WIDTH                (1U)
#define SMU_SRG_S_SR0_R2WEA(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_R2WEA_SHIFT)) & SMU_SRG_S_SR0_R2WEA_MASK)

#define SMU_SRG_S_SR0_R3WEA_MASK                 (0x80U)
#define SMU_SRG_S_SR0_R3WEA_SHIFT                (7U)
#define SMU_SRG_S_SR0_R3WEA_WIDTH                (1U)
#define SMU_SRG_S_SR0_R3WEA(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_R3WEA_SHIFT)) & SMU_SRG_S_SR0_R3WEA_MASK)

#define SMU_SRG_S_SR0_CTRE_MASK                  (0x100U)
#define SMU_SRG_S_SR0_CTRE_SHIFT                 (8U)
#define SMU_SRG_S_SR0_CTRE_WIDTH                 (1U)
#define SMU_SRG_S_SR0_CTRE(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_CTRE_SHIFT)) & SMU_SRG_S_SR0_CTRE_MASK)

#define SMU_SRG_S_SR0_CDRE_MASK                  (0x200U)
#define SMU_SRG_S_SR0_CDRE_SHIFT                 (9U)
#define SMU_SRG_S_SR0_CDRE_WIDTH                 (1U)
#define SMU_SRG_S_SR0_CDRE(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_CDRE_SHIFT)) & SMU_SRG_S_SR0_CDRE_MASK)

#define SMU_SRG_S_SR0_STRE_MASK                  (0x400U)
#define SMU_SRG_S_SR0_STRE_SHIFT                 (10U)
#define SMU_SRG_S_SR0_STRE_WIDTH                 (1U)
#define SMU_SRG_S_SR0_STRE(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_STRE_SHIFT)) & SMU_SRG_S_SR0_STRE_MASK)

#define SMU_SRG_S_SR0_SDRE_MASK                  (0x800U)
#define SMU_SRG_S_SR0_SDRE_SHIFT                 (11U)
#define SMU_SRG_S_SR0_SDRE_WIDTH                 (1U)
#define SMU_SRG_S_SR0_SDRE(x)                    (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_SDRE_SHIFT)) & SMU_SRG_S_SR0_SDRE_MASK)

#define SMU_SRG_S_SR0_CCCMCRE_MASK               (0x10000U)
#define SMU_SRG_S_SR0_CCCMCRE_SHIFT              (16U)
#define SMU_SRG_S_SR0_CCCMCRE_WIDTH              (1U)
#define SMU_SRG_S_SR0_CCCMCRE(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_CCCMCRE_SHIFT)) & SMU_SRG_S_SR0_CCCMCRE_MASK)

#define SMU_SRG_S_SR0_SCCMCRE_MASK               (0x20000U)
#define SMU_SRG_S_SR0_SCCMCRE_SHIFT              (17U)
#define SMU_SRG_S_SR0_SCCMCRE_WIDTH              (1U)
#define SMU_SRG_S_SR0_SCCMCRE(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_SCCMCRE_SHIFT)) & SMU_SRG_S_SR0_SCCMCRE_MASK)

#define SMU_SRG_S_SR0_COREH_MASK                 (0x100000U)
#define SMU_SRG_S_SR0_COREH_SHIFT                (20U)
#define SMU_SRG_S_SR0_COREH_WIDTH                (1U)
#define SMU_SRG_S_SR0_COREH(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_COREH_SHIFT)) & SMU_SRG_S_SR0_COREH_MASK)

#define SMU_SRG_S_SR0_CORETU_MASK                (0x200000U)
#define SMU_SRG_S_SR0_CORETU_SHIFT               (21U)
#define SMU_SRG_S_SR0_CORETU_WIDTH               (1U)
#define SMU_SRG_S_SR0_CORETU(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_SRG_S_SR0_CORETU_SHIFT)) & SMU_SRG_S_SR0_CORETU_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SMU_SRG_S_Register_Masks */

/*!
 * @}
 */ /* end of group SMU_SRG_S_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_SMU_SRG_S_H_) */
