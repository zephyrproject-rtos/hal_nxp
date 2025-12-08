/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_CANXL.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_CANXL
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
#if !defined(S32K566_CANXL_H_)  /* Check if memory map has not been already included */
#define S32K566_CANXL_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CANXL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CANXL_Peripheral_Access_Layer CANXL Peripheral Access Layer
 * @{
 */

/** CANXL - Register Layout Typedef */
typedef struct CANXL_Struct {
  __IO uint32_t MCFG;                              /**< Module Configuration, offset: 0x0 */
  __IO uint32_t WCFG;                              /**< Window Configuration, offset: 0x4 */
  __IO uint32_t LTHCFG;                            /**< Lower Threshold Configuration, offset: 0x8 */
  __IO uint32_t UTHCFG;                            /**< Upper Threshold Configuration, offset: 0xC */
  __IO uint32_t CBLMS;                             /**< CBLM Status, offset: 0x10 */
  __IO uint32_t CBLMIE;                            /**< CBLM Interrupt Enable, offset: 0x14 */
  __I  uint32_t WLS;                               /**< Window Load Status, offset: 0x18 */
  __I  uint32_t ALS;                               /**< Average Load Status, offset: 0x1C */
} CANXL_Type, *CANXL_MemMapPtr;

/** Number of instances of the CANXL module. */
#define CANXL_INSTANCE_COUNT                     (1u)

/* CANXL - Peripheral instance base addresses */
/** Peripheral CANEXCEL__CBLM base address */
#define IP_CANEXCEL__CBLM_BASE                   (0x6A01A000u)
/** Peripheral CANEXCEL__CBLM base pointer */
#define IP_CANEXCEL__CBLM                        ((CANXL_Type *)IP_CANEXCEL__CBLM_BASE)
/** Array initializer of CANXL peripheral base addresses */
#define IP_CANXL_BASE_ADDRS                      { IP_CANEXCEL__CBLM_BASE }
/** Array initializer of CANXL peripheral base pointers */
#define IP_CANXL_BASE_PTRS                       { IP_CANEXCEL__CBLM }

/* ----------------------------------------------------------------------------
   -- CANXL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CANXL_Register_Masks CANXL Register Masks
 * @{
 */

/*! @name MCFG - Module Configuration */
/*! @{ */

#define CANXL_MCFG_CBLM_EN_MASK                  (0x1U)
#define CANXL_MCFG_CBLM_EN_SHIFT                 (0U)
#define CANXL_MCFG_CBLM_EN_WIDTH                 (1U)
#define CANXL_MCFG_CBLM_EN(x)                    (((uint32_t)(((uint32_t)(x)) << CANXL_MCFG_CBLM_EN_SHIFT)) & CANXL_MCFG_CBLM_EN_MASK)
/*! @} */

/*! @name WCFG - Window Configuration */
/*! @{ */

#define CANXL_WCFG_SMPW_MASK                     (0xFFFFFFFFU)
#define CANXL_WCFG_SMPW_SHIFT                    (0U)
#define CANXL_WCFG_SMPW_WIDTH                    (32U)
#define CANXL_WCFG_SMPW(x)                       (((uint32_t)(((uint32_t)(x)) << CANXL_WCFG_SMPW_SHIFT)) & CANXL_WCFG_SMPW_MASK)
/*! @} */

/*! @name LTHCFG - Lower Threshold Configuration */
/*! @{ */

#define CANXL_LTHCFG_LTH_MASK                    (0xFFFFFFFFU)
#define CANXL_LTHCFG_LTH_SHIFT                   (0U)
#define CANXL_LTHCFG_LTH_WIDTH                   (32U)
#define CANXL_LTHCFG_LTH(x)                      (((uint32_t)(((uint32_t)(x)) << CANXL_LTHCFG_LTH_SHIFT)) & CANXL_LTHCFG_LTH_MASK)
/*! @} */

/*! @name UTHCFG - Upper Threshold Configuration */
/*! @{ */

#define CANXL_UTHCFG_UTH_MASK                    (0xFFFFFFFFU)
#define CANXL_UTHCFG_UTH_SHIFT                   (0U)
#define CANXL_UTHCFG_UTH_WIDTH                   (32U)
#define CANXL_UTHCFG_UTH(x)                      (((uint32_t)(((uint32_t)(x)) << CANXL_UTHCFG_UTH_SHIFT)) & CANXL_UTHCFG_UTH_MASK)
/*! @} */

/*! @name CBLMS - CBLM Status */
/*! @{ */

#define CANXL_CBLMS_DONEF_MASK                   (0x1U)
#define CANXL_CBLMS_DONEF_SHIFT                  (0U)
#define CANXL_CBLMS_DONEF_WIDTH                  (1U)
#define CANXL_CBLMS_DONEF(x)                     (((uint32_t)(((uint32_t)(x)) << CANXL_CBLMS_DONEF_SHIFT)) & CANXL_CBLMS_DONEF_MASK)

#define CANXL_CBLMS_LTHF_MASK                    (0x100U)
#define CANXL_CBLMS_LTHF_SHIFT                   (8U)
#define CANXL_CBLMS_LTHF_WIDTH                   (1U)
#define CANXL_CBLMS_LTHF(x)                      (((uint32_t)(((uint32_t)(x)) << CANXL_CBLMS_LTHF_SHIFT)) & CANXL_CBLMS_LTHF_MASK)

#define CANXL_CBLMS_UTHF_MASK                    (0x200U)
#define CANXL_CBLMS_UTHF_SHIFT                   (9U)
#define CANXL_CBLMS_UTHF_WIDTH                   (1U)
#define CANXL_CBLMS_UTHF(x)                      (((uint32_t)(((uint32_t)(x)) << CANXL_CBLMS_UTHF_SHIFT)) & CANXL_CBLMS_UTHF_MASK)
/*! @} */

/*! @name CBLMIE - CBLM Interrupt Enable */
/*! @{ */

#define CANXL_CBLMIE_DONEIE_MASK                 (0x1U)
#define CANXL_CBLMIE_DONEIE_SHIFT                (0U)
#define CANXL_CBLMIE_DONEIE_WIDTH                (1U)
#define CANXL_CBLMIE_DONEIE(x)                   (((uint32_t)(((uint32_t)(x)) << CANXL_CBLMIE_DONEIE_SHIFT)) & CANXL_CBLMIE_DONEIE_MASK)

#define CANXL_CBLMIE_LTHIE_MASK                  (0x100U)
#define CANXL_CBLMIE_LTHIE_SHIFT                 (8U)
#define CANXL_CBLMIE_LTHIE_WIDTH                 (1U)
#define CANXL_CBLMIE_LTHIE(x)                    (((uint32_t)(((uint32_t)(x)) << CANXL_CBLMIE_LTHIE_SHIFT)) & CANXL_CBLMIE_LTHIE_MASK)

#define CANXL_CBLMIE_UTHIE_MASK                  (0x200U)
#define CANXL_CBLMIE_UTHIE_SHIFT                 (9U)
#define CANXL_CBLMIE_UTHIE_WIDTH                 (1U)
#define CANXL_CBLMIE_UTHIE(x)                    (((uint32_t)(((uint32_t)(x)) << CANXL_CBLMIE_UTHIE_SHIFT)) & CANXL_CBLMIE_UTHIE_MASK)
/*! @} */

/*! @name WLS - Window Load Status */
/*! @{ */

#define CANXL_WLS_WINLD_MASK                     (0xFFFFFFFFU)
#define CANXL_WLS_WINLD_SHIFT                    (0U)
#define CANXL_WLS_WINLD_WIDTH                    (32U)
#define CANXL_WLS_WINLD(x)                       (((uint32_t)(((uint32_t)(x)) << CANXL_WLS_WINLD_SHIFT)) & CANXL_WLS_WINLD_MASK)
/*! @} */

/*! @name ALS - Average Load Status */
/*! @{ */

#define CANXL_ALS_AVGLD_MASK                     (0xFFFFFFFFU)
#define CANXL_ALS_AVGLD_SHIFT                    (0U)
#define CANXL_ALS_AVGLD_WIDTH                    (32U)
#define CANXL_ALS_AVGLD(x)                       (((uint32_t)(((uint32_t)(x)) << CANXL_ALS_AVGLD_SHIFT)) & CANXL_ALS_AVGLD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CANXL_Register_Masks */

/*!
 * @}
 */ /* end of group CANXL_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_CANXL_H_) */
