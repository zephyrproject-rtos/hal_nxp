/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_LLC_FSC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_LLC_FSC
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
#if !defined(S32Z2_LLC_FSC_H_)  /* Check if memory map has not been already included */
#define S32Z2_LLC_FSC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LLC_FSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLC_FSC_Peripheral_Access_Layer LLC_FSC Peripheral Access Layer
 * @{
 */

/** LLC_FSC - Size of Registers Arrays */
#define LLC_FSC_FSCLF_COUNT                       3u
#define LLC_FSC_FSCMF_COUNT                       3u
#define LLC_FSC_FSCCETHF_COUNT                    3u

/** LLC_FSC - Register Layout Typedef */
typedef struct {
  __O  uint32_t FSCBISTCR;                         /**< FSC BIST Control, offset: 0x0 */
  __I  uint32_t FSCBISTAR;                         /**< FSC BIST Activity, offset: 0x4 */
  uint8_t RESERVED_0[8];
  __I  uint32_t FSCLF0;                            /**< FSC Latent Fault Inputs 0, offset: 0x10 */
  __I  uint32_t FSCLF[LLC_FSC_FSCLF_COUNT];        /**< FSC Latent Fault Inputs, array offset: 0x14, array step: 0x4 */
  __I  uint32_t FSCMF0;                            /**< FSC Mission Fault 0, offset: 0x20 */
  __I  uint32_t FSCMF[LLC_FSC_FSCMF_COUNT];        /**< FSC Mission Fault Inputs, array offset: 0x24, array step: 0x4 */
  __I  uint32_t FSCCETHF0;                         /**< FSC Correctable Error Over Theshold 0, offset: 0x30 */
  __I  uint32_t FSCCETHF[LLC_FSC_FSCCETHF_COUNT];  /**< FSC Correctable Error Over Threshold 1..FSC Correctable Error Over Threshold 3, array offset: 0x34, array step: 0x4 */
} LLC_FSC_Type, *LLC_FSC_MemMapPtr;

/** Number of instances of the LLC_FSC module. */
#define LLC_FSC_INSTANCE_COUNT                   (2u)

/* LLC_FSC - Peripheral instance base addresses */
/** Peripheral RTU0__LLC_FSC base address */
#define IP_RTU0__LLC_FSC_BASE                    (0x76040000u)
/** Peripheral RTU0__LLC_FSC base pointer */
#define IP_RTU0__LLC_FSC                         ((LLC_FSC_Type *)IP_RTU0__LLC_FSC_BASE)
/** Peripheral RTU1__LLC_FSC base address */
#define IP_RTU1__LLC_FSC_BASE                    (0x76840000u)
/** Peripheral RTU1__LLC_FSC base pointer */
#define IP_RTU1__LLC_FSC                         ((LLC_FSC_Type *)IP_RTU1__LLC_FSC_BASE)
/** Array initializer of LLC_FSC peripheral base addresses */
#define IP_LLC_FSC_BASE_ADDRS                    { IP_RTU0__LLC_FSC_BASE, IP_RTU1__LLC_FSC_BASE }
/** Array initializer of LLC_FSC peripheral base pointers */
#define IP_LLC_FSC_BASE_PTRS                     { IP_RTU0__LLC_FSC, IP_RTU1__LLC_FSC }

/* ----------------------------------------------------------------------------
   -- LLC_FSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLC_FSC_Register_Masks LLC_FSC Register Masks
 * @{
 */

/*! @name FSCBISTCR - FSC BIST Control */
/*! @{ */

#define LLC_FSC_FSCBISTCR_bist_start_MASK        (0x1U)
#define LLC_FSC_FSCBISTCR_bist_start_SHIFT       (0U)
#define LLC_FSC_FSCBISTCR_bist_start_WIDTH       (1U)
#define LLC_FSC_FSCBISTCR_bist_start(x)          (((uint32_t)(((uint32_t)(x)) << LLC_FSC_FSCBISTCR_bist_start_SHIFT)) & LLC_FSC_FSCBISTCR_bist_start_MASK)

#define LLC_FSC_FSCBISTCR_bist_step_MASK         (0x2U)
#define LLC_FSC_FSCBISTCR_bist_step_SHIFT        (1U)
#define LLC_FSC_FSCBISTCR_bist_step_WIDTH        (1U)
#define LLC_FSC_FSCBISTCR_bist_step(x)           (((uint32_t)(((uint32_t)(x)) << LLC_FSC_FSCBISTCR_bist_step_SHIFT)) & LLC_FSC_FSCBISTCR_bist_step_MASK)
/*! @} */

/*! @name FSCBISTAR - FSC BIST Activity */
/*! @{ */

#define LLC_FSC_FSCBISTAR_bist_done_MASK         (0x1FU)
#define LLC_FSC_FSCBISTAR_bist_done_SHIFT        (0U)
#define LLC_FSC_FSCBISTAR_bist_done_WIDTH        (5U)
#define LLC_FSC_FSCBISTAR_bist_done(x)           (((uint32_t)(((uint32_t)(x)) << LLC_FSC_FSCBISTAR_bist_done_SHIFT)) & LLC_FSC_FSCBISTAR_bist_done_MASK)

#define LLC_FSC_FSCBISTAR_bist_err_MASK          (0x3E0U)
#define LLC_FSC_FSCBISTAR_bist_err_SHIFT         (5U)
#define LLC_FSC_FSCBISTAR_bist_err_WIDTH         (5U)
#define LLC_FSC_FSCBISTAR_bist_err(x)            (((uint32_t)(((uint32_t)(x)) << LLC_FSC_FSCBISTAR_bist_err_SHIFT)) & LLC_FSC_FSCBISTAR_bist_err_MASK)
/*! @} */

/*! @name FSCLF0 - FSC Latent Fault Inputs 0 */
/*! @{ */

#define LLC_FSC_FSCLF0_latent_fault_MASK         (0xFFFFFFFFU)
#define LLC_FSC_FSCLF0_latent_fault_SHIFT        (0U)
#define LLC_FSC_FSCLF0_latent_fault_WIDTH        (32U)
#define LLC_FSC_FSCLF0_latent_fault(x)           (((uint32_t)(((uint32_t)(x)) << LLC_FSC_FSCLF0_latent_fault_SHIFT)) & LLC_FSC_FSCLF0_latent_fault_MASK)
/*! @} */

/*! @name FSCLF - FSC Latent Fault Inputs */
/*! @{ */

#define LLC_FSC_FSCLF_latent_fault_MASK          (0xFFFFFFFFU)
#define LLC_FSC_FSCLF_latent_fault_SHIFT         (0U)
#define LLC_FSC_FSCLF_latent_fault_WIDTH         (32U)
#define LLC_FSC_FSCLF_latent_fault(x)            (((uint32_t)(((uint32_t)(x)) << LLC_FSC_FSCLF_latent_fault_SHIFT)) & LLC_FSC_FSCLF_latent_fault_MASK)
/*! @} */

/*! @name FSCMF0 - FSC Mission Fault 0 */
/*! @{ */

#define LLC_FSC_FSCMF0_mission_fault_MASK        (0xFFFFFFFFU)
#define LLC_FSC_FSCMF0_mission_fault_SHIFT       (0U)
#define LLC_FSC_FSCMF0_mission_fault_WIDTH       (32U)
#define LLC_FSC_FSCMF0_mission_fault(x)          (((uint32_t)(((uint32_t)(x)) << LLC_FSC_FSCMF0_mission_fault_SHIFT)) & LLC_FSC_FSCMF0_mission_fault_MASK)
/*! @} */

/*! @name FSCMF - FSC Mission Fault Inputs */
/*! @{ */

#define LLC_FSC_FSCMF_mission_fault_MASK         (0xFFFFFFFFU)
#define LLC_FSC_FSCMF_mission_fault_SHIFT        (0U)
#define LLC_FSC_FSCMF_mission_fault_WIDTH        (32U)
#define LLC_FSC_FSCMF_mission_fault(x)           (((uint32_t)(((uint32_t)(x)) << LLC_FSC_FSCMF_mission_fault_SHIFT)) & LLC_FSC_FSCMF_mission_fault_MASK)
/*! @} */

/*! @name FSCCETHF0 - FSC Correctable Error Over Theshold 0 */
/*! @{ */

#define LLC_FSC_FSCCETHF0_cerr_over_thresh_MASK  (0xFFFFFFFFU)
#define LLC_FSC_FSCCETHF0_cerr_over_thresh_SHIFT (0U)
#define LLC_FSC_FSCCETHF0_cerr_over_thresh_WIDTH (32U)
#define LLC_FSC_FSCCETHF0_cerr_over_thresh(x)    (((uint32_t)(((uint32_t)(x)) << LLC_FSC_FSCCETHF0_cerr_over_thresh_SHIFT)) & LLC_FSC_FSCCETHF0_cerr_over_thresh_MASK)
/*! @} */

/*! @name FSCCETHF - FSC Correctable Error Over Threshold 1..FSC Correctable Error Over Threshold 3 */
/*! @{ */

#define LLC_FSC_FSCCETHF_cerr_over_thresh_MASK   (0xFFFFFFFFU)
#define LLC_FSC_FSCCETHF_cerr_over_thresh_SHIFT  (0U)
#define LLC_FSC_FSCCETHF_cerr_over_thresh_WIDTH  (32U)
#define LLC_FSC_FSCCETHF_cerr_over_thresh(x)     (((uint32_t)(((uint32_t)(x)) << LLC_FSC_FSCCETHF_cerr_over_thresh_SHIFT)) & LLC_FSC_FSCCETHF_cerr_over_thresh_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LLC_FSC_Register_Masks */

/*!
 * @}
 */ /* end of group LLC_FSC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_LLC_FSC_H_) */
