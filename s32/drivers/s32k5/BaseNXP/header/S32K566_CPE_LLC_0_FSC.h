/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_CPE_LLC_0_FSC.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_CPE_LLC_0_FSC
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
#if !defined(S32K566_CPE_LLC_0_FSC_H_)  /* Check if memory map has not been already included */
#define S32K566_CPE_LLC_0_FSC_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CPE_LLC_0_FSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CPE_LLC_0_FSC_Peripheral_Access_Layer CPE_LLC_0_FSC Peripheral Access Layer
 * @{
 */

/** CPE_LLC_0_FSC - Size of Registers Arrays */
#define CPE_LLC_0_FSC_FSCLFN_COUNT                4u
#define CPE_LLC_0_FSC_FSCMFN_COUNT                4u
#define CPE_LLC_0_FSC_FSCCETHFN_COUNT             4u

/** CPE_LLC_0_FSC - Register Layout Typedef */
typedef struct CPE_LLC_0_FSC_Struct {
  __IO uint32_t FSCBISTCR;                         /**< FSC BIST Control, offset: 0x0 */
  __I  uint32_t FSCBISTAR;                         /**< FSC BIST Activity, offset: 0x4 */
  uint8_t RESERVED_0[8];
  __I  uint32_t FSCLF[CPE_LLC_0_FSC_FSCLFN_COUNT]; /**< FSC Latent Fault Inputs 0..FSC Latent Fault Inputs 3, array offset: 0x10, array step: 0x4 */
  __I  uint32_t FSCMF[CPE_LLC_0_FSC_FSCMFN_COUNT]; /**< FSC Mission Fault 0..FSC Mission Fault 3, array offset: 0x20, array step: 0x4 */
  __I  uint32_t FSCCETHF[CPE_LLC_0_FSC_FSCCETHFN_COUNT]; /**< FSC Correctable Error Over Threshold 0..FSC Correctable Error Over Threshold 3, array offset: 0x30, array step: 0x4 */
} CPE_LLC_0_FSC_Type, *CPE_LLC_0_FSC_MemMapPtr;

/** Number of instances of the CPE_LLC_0_FSC module. */
#define CPE_LLC_0_FSC_INSTANCE_COUNT             (1u)

/* CPE_LLC_0_FSC - Peripheral instance base addresses */
/** Peripheral CPE_LLC_0__CPE_LLC_0_FSC base address */
#define IP_CPE_LLC_0__CPE_LLC_0_FSC_BASE         (0x41014000u)
/** Peripheral CPE_LLC_0__CPE_LLC_0_FSC base pointer */
#define IP_CPE_LLC_0__CPE_LLC_0_FSC              ((CPE_LLC_0_FSC_Type *)IP_CPE_LLC_0__CPE_LLC_0_FSC_BASE)
/** Array initializer of CPE_LLC_0_FSC peripheral base addresses */
#define IP_CPE_LLC_0_FSC_BASE_ADDRS              { IP_CPE_LLC_0__CPE_LLC_0_FSC_BASE }
/** Array initializer of CPE_LLC_0_FSC peripheral base pointers */
#define IP_CPE_LLC_0_FSC_BASE_PTRS               { IP_CPE_LLC_0__CPE_LLC_0_FSC }

/* ----------------------------------------------------------------------------
   -- CPE_LLC_0_FSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CPE_LLC_0_FSC_Register_Masks CPE_LLC_0_FSC Register Masks
 * @{
 */

/*! @name FSCBISTCR - FSC BIST Control */
/*! @{ */

#define CPE_LLC_0_FSC_FSCBISTCR_BIST_START_MASK  (0x1U)
#define CPE_LLC_0_FSC_FSCBISTCR_BIST_START_SHIFT (0U)
#define CPE_LLC_0_FSC_FSCBISTCR_BIST_START_WIDTH (1U)
#define CPE_LLC_0_FSC_FSCBISTCR_BIST_START(x)    (((uint32_t)(((uint32_t)(x)) << CPE_LLC_0_FSC_FSCBISTCR_BIST_START_SHIFT)) & CPE_LLC_0_FSC_FSCBISTCR_BIST_START_MASK)

#define CPE_LLC_0_FSC_FSCBISTCR_BIST_STEP_MASK   (0x2U)
#define CPE_LLC_0_FSC_FSCBISTCR_BIST_STEP_SHIFT  (1U)
#define CPE_LLC_0_FSC_FSCBISTCR_BIST_STEP_WIDTH  (1U)
#define CPE_LLC_0_FSC_FSCBISTCR_BIST_STEP(x)     (((uint32_t)(((uint32_t)(x)) << CPE_LLC_0_FSC_FSCBISTCR_BIST_STEP_SHIFT)) & CPE_LLC_0_FSC_FSCBISTCR_BIST_STEP_MASK)
/*! @} */

/*! @name FSCBISTAR - FSC BIST Activity */
/*! @{ */

#define CPE_LLC_0_FSC_FSCBISTAR_BIST_DONE_MASK   (0x1FU)
#define CPE_LLC_0_FSC_FSCBISTAR_BIST_DONE_SHIFT  (0U)
#define CPE_LLC_0_FSC_FSCBISTAR_BIST_DONE_WIDTH  (5U)
#define CPE_LLC_0_FSC_FSCBISTAR_BIST_DONE(x)     (((uint32_t)(((uint32_t)(x)) << CPE_LLC_0_FSC_FSCBISTAR_BIST_DONE_SHIFT)) & CPE_LLC_0_FSC_FSCBISTAR_BIST_DONE_MASK)

#define CPE_LLC_0_FSC_FSCBISTAR_BIST_ERR_MASK    (0x3E0U)
#define CPE_LLC_0_FSC_FSCBISTAR_BIST_ERR_SHIFT   (5U)
#define CPE_LLC_0_FSC_FSCBISTAR_BIST_ERR_WIDTH   (5U)
#define CPE_LLC_0_FSC_FSCBISTAR_BIST_ERR(x)      (((uint32_t)(((uint32_t)(x)) << CPE_LLC_0_FSC_FSCBISTAR_BIST_ERR_SHIFT)) & CPE_LLC_0_FSC_FSCBISTAR_BIST_ERR_MASK)
/*! @} */

/*! @name FSCLF - FSC Latent Fault Inputs 0..FSC Latent Fault Inputs 3 */
/*! @{ */

#define CPE_LLC_0_FSC_FSCLF_LATENT_FAULT_MASK    (0xFFFFFFFFU)
#define CPE_LLC_0_FSC_FSCLF_LATENT_FAULT_SHIFT   (0U)
#define CPE_LLC_0_FSC_FSCLF_LATENT_FAULT_WIDTH   (32U)
#define CPE_LLC_0_FSC_FSCLF_LATENT_FAULT(x)      (((uint32_t)(((uint32_t)(x)) << CPE_LLC_0_FSC_FSCLF_LATENT_FAULT_SHIFT)) & CPE_LLC_0_FSC_FSCLF_LATENT_FAULT_MASK)
/*! @} */

/*! @name FSCMF - FSC Mission Fault 0..FSC Mission Fault 3 */
/*! @{ */

#define CPE_LLC_0_FSC_FSCMF_MISSION_FAULT_MASK   (0xFFFFFFFFU)
#define CPE_LLC_0_FSC_FSCMF_MISSION_FAULT_SHIFT  (0U)
#define CPE_LLC_0_FSC_FSCMF_MISSION_FAULT_WIDTH  (32U)
#define CPE_LLC_0_FSC_FSCMF_MISSION_FAULT(x)     (((uint32_t)(((uint32_t)(x)) << CPE_LLC_0_FSC_FSCMF_MISSION_FAULT_SHIFT)) & CPE_LLC_0_FSC_FSCMF_MISSION_FAULT_MASK)
/*! @} */

/*! @name FSCCETHF - FSC Correctable Error Over Threshold 0..FSC Correctable Error Over Threshold 3 */
/*! @{ */

#define CPE_LLC_0_FSC_FSCCETHF_CERR_OVER_THRESH_MASK (0xFFFFFFFFU)
#define CPE_LLC_0_FSC_FSCCETHF_CERR_OVER_THRESH_SHIFT (0U)
#define CPE_LLC_0_FSC_FSCCETHF_CERR_OVER_THRESH_WIDTH (32U)
#define CPE_LLC_0_FSC_FSCCETHF_CERR_OVER_THRESH(x) (((uint32_t)(((uint32_t)(x)) << CPE_LLC_0_FSC_FSCCETHF_CERR_OVER_THRESH_SHIFT)) & CPE_LLC_0_FSC_FSCCETHF_CERR_OVER_THRESH_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CPE_LLC_0_FSC_Register_Masks */

/*!
 * @}
 */ /* end of group CPE_LLC_0_FSC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_CPE_LLC_0_FSC_H_) */
