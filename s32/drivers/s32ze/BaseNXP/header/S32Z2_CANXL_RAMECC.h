/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CANXL_RAMECC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CANXL_RAMECC
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
#if !defined(S32Z2_CANXL_RAMECC_H_)  /* Check if memory map has not been already included */
#define S32Z2_CANXL_RAMECC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CANXL_RAMECC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CANXL_RAMECC_Peripheral_Access_Layer CANXL_RAMECC Peripheral Access Layer
 * @{
 */

/** CANXL_RAMECC - Register Layout Typedef */
typedef struct {
  __IO uint32_t DRMEC;                             /**< Data RAM Error Control, offset: 0x0 */
  __IO uint32_t DRERRIA;                           /**< Data RAM Error Injection Address, offset: 0x4 */
  __IO uint32_t DRERRIDP;                          /**< Data RAM Error Injection Data Pattern, offset: 0x8 */
  __IO uint32_t DRERRIPP;                          /**< Data RAM Error Injection Parity Pattern, offset: 0xC */
  __I  uint32_t DRRERRA;                           /**< Data RAM Error Report Address, offset: 0x10 */
  __I  uint32_t DRRERRD;                           /**< Data RAM Error Report Data, offset: 0x14 */
  __I  uint32_t DRRERRSYN;                         /**< Data RAM Error Report Syndrome, offset: 0x18 */
  __IO uint32_t DRERRS;                            /**< Data RAM Error Status, offset: 0x1C */
} CANXL_RAMECC_Type, *CANXL_RAMECC_MemMapPtr;

/** Number of instances of the CANXL_RAMECC module. */
#define CANXL_RAMECC_INSTANCE_COUNT              (2u)

/* CANXL_RAMECC - Peripheral instance base addresses */
/** Peripheral CANXL_0__RAMECC base address */
#define IP_CANXL_0__RAMECC_BASE                  (0x47460000u)
/** Peripheral CANXL_0__RAMECC base pointer */
#define IP_CANXL_0__RAMECC                       ((CANXL_RAMECC_Type *)IP_CANXL_0__RAMECC_BASE)
/** Peripheral CANXL_1__RAMECC base address */
#define IP_CANXL_1__RAMECC_BASE                  (0x47560000u)
/** Peripheral CANXL_1__RAMECC base pointer */
#define IP_CANXL_1__RAMECC                       ((CANXL_RAMECC_Type *)IP_CANXL_1__RAMECC_BASE)
/** Array initializer of CANXL_RAMECC peripheral base addresses */
#define IP_CANXL_RAMECC_BASE_ADDRS               { IP_CANXL_0__RAMECC_BASE, IP_CANXL_1__RAMECC_BASE }
/** Array initializer of CANXL_RAMECC peripheral base pointers */
#define IP_CANXL_RAMECC_BASE_PTRS                { IP_CANXL_0__RAMECC, IP_CANXL_1__RAMECC }

/* ----------------------------------------------------------------------------
   -- CANXL_RAMECC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CANXL_RAMECC_Register_Masks CANXL_RAMECC Register Masks
 * @{
 */

/*! @name DRMEC - Data RAM Error Control */
/*! @{ */

#define CANXL_RAMECC_DRMEC_ECCDIS_MASK           (0x100U)
#define CANXL_RAMECC_DRMEC_ECCDIS_SHIFT          (8U)
#define CANXL_RAMECC_DRMEC_ECCDIS_WIDTH          (1U)
#define CANXL_RAMECC_DRMEC_ECCDIS(x)             (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRMEC_ECCDIS_SHIFT)) & CANXL_RAMECC_DRMEC_ECCDIS_MASK)

#define CANXL_RAMECC_DRMEC_ERRRPTDIS_MASK        (0x200U)
#define CANXL_RAMECC_DRMEC_ERRRPTDIS_SHIFT       (9U)
#define CANXL_RAMECC_DRMEC_ERRRPTDIS_WIDTH       (1U)
#define CANXL_RAMECC_DRMEC_ERRRPTDIS(x)          (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRMEC_ERRRPTDIS_SHIFT)) & CANXL_RAMECC_DRMEC_ERRRPTDIS_MASK)

#define CANXL_RAMECC_DRMEC_ERRINJEN_MASK         (0x4000U)
#define CANXL_RAMECC_DRMEC_ERRINJEN_SHIFT        (14U)
#define CANXL_RAMECC_DRMEC_ERRINJEN_WIDTH        (1U)
#define CANXL_RAMECC_DRMEC_ERRINJEN(x)           (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRMEC_ERRINJEN_SHIFT)) & CANXL_RAMECC_DRMEC_ERRINJEN_MASK)

#define CANXL_RAMECC_DRMEC_CEIEN_MASK            (0x10000U)
#define CANXL_RAMECC_DRMEC_CEIEN_SHIFT           (16U)
#define CANXL_RAMECC_DRMEC_CEIEN_WIDTH           (1U)
#define CANXL_RAMECC_DRMEC_CEIEN(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRMEC_CEIEN_SHIFT)) & CANXL_RAMECC_DRMEC_CEIEN_MASK)

#define CANXL_RAMECC_DRMEC_NCEIEN_MASK           (0x40000U)
#define CANXL_RAMECC_DRMEC_NCEIEN_SHIFT          (18U)
#define CANXL_RAMECC_DRMEC_NCEIEN_WIDTH          (1U)
#define CANXL_RAMECC_DRMEC_NCEIEN(x)             (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRMEC_NCEIEN_SHIFT)) & CANXL_RAMECC_DRMEC_NCEIEN_MASK)

#define CANXL_RAMECC_DRMEC_ECRWRDIS_MASK         (0x80000000U)
#define CANXL_RAMECC_DRMEC_ECRWRDIS_SHIFT        (31U)
#define CANXL_RAMECC_DRMEC_ECRWRDIS_WIDTH        (1U)
#define CANXL_RAMECC_DRMEC_ECRWRDIS(x)           (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRMEC_ECRWRDIS_SHIFT)) & CANXL_RAMECC_DRMEC_ECRWRDIS_MASK)
/*! @} */

/*! @name DRERRIA - Data RAM Error Injection Address */
/*! @{ */

#define CANXL_RAMECC_DRERRIA_INJADDR_L_MASK      (0x3U)
#define CANXL_RAMECC_DRERRIA_INJADDR_L_SHIFT     (0U)
#define CANXL_RAMECC_DRERRIA_INJADDR_L_WIDTH     (2U)
#define CANXL_RAMECC_DRERRIA_INJADDR_L(x)        (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRERRIA_INJADDR_L_SHIFT)) & CANXL_RAMECC_DRERRIA_INJADDR_L_MASK)

#define CANXL_RAMECC_DRERRIA_INJADDR_H_MASK      (0x7FFCU)
#define CANXL_RAMECC_DRERRIA_INJADDR_H_SHIFT     (2U)
#define CANXL_RAMECC_DRERRIA_INJADDR_H_WIDTH     (13U)
#define CANXL_RAMECC_DRERRIA_INJADDR_H(x)        (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRERRIA_INJADDR_H_SHIFT)) & CANXL_RAMECC_DRERRIA_INJADDR_H_MASK)
/*! @} */

/*! @name DRERRIDP - Data RAM Error Injection Data Pattern */
/*! @{ */

#define CANXL_RAMECC_DRERRIDP_DFLIP_MASK         (0xFFFFFFFFU)
#define CANXL_RAMECC_DRERRIDP_DFLIP_SHIFT        (0U)
#define CANXL_RAMECC_DRERRIDP_DFLIP_WIDTH        (32U)
#define CANXL_RAMECC_DRERRIDP_DFLIP(x)           (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRERRIDP_DFLIP_SHIFT)) & CANXL_RAMECC_DRERRIDP_DFLIP_MASK)
/*! @} */

/*! @name DRERRIPP - Data RAM Error Injection Parity Pattern */
/*! @{ */

#define CANXL_RAMECC_DRERRIPP_PFLIP0_MASK        (0x1FU)
#define CANXL_RAMECC_DRERRIPP_PFLIP0_SHIFT       (0U)
#define CANXL_RAMECC_DRERRIPP_PFLIP0_WIDTH       (5U)
#define CANXL_RAMECC_DRERRIPP_PFLIP0(x)          (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRERRIPP_PFLIP0_SHIFT)) & CANXL_RAMECC_DRERRIPP_PFLIP0_MASK)

#define CANXL_RAMECC_DRERRIPP_PFLIP1_MASK        (0x1F00U)
#define CANXL_RAMECC_DRERRIPP_PFLIP1_SHIFT       (8U)
#define CANXL_RAMECC_DRERRIPP_PFLIP1_WIDTH       (5U)
#define CANXL_RAMECC_DRERRIPP_PFLIP1(x)          (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRERRIPP_PFLIP1_SHIFT)) & CANXL_RAMECC_DRERRIPP_PFLIP1_MASK)

#define CANXL_RAMECC_DRERRIPP_PFLIP2_MASK        (0x1F0000U)
#define CANXL_RAMECC_DRERRIPP_PFLIP2_SHIFT       (16U)
#define CANXL_RAMECC_DRERRIPP_PFLIP2_WIDTH       (5U)
#define CANXL_RAMECC_DRERRIPP_PFLIP2(x)          (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRERRIPP_PFLIP2_SHIFT)) & CANXL_RAMECC_DRERRIPP_PFLIP2_MASK)

#define CANXL_RAMECC_DRERRIPP_PFLIP3_MASK        (0x1F000000U)
#define CANXL_RAMECC_DRERRIPP_PFLIP3_SHIFT       (24U)
#define CANXL_RAMECC_DRERRIPP_PFLIP3_WIDTH       (5U)
#define CANXL_RAMECC_DRERRIPP_PFLIP3(x)          (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRERRIPP_PFLIP3_SHIFT)) & CANXL_RAMECC_DRERRIPP_PFLIP3_MASK)
/*! @} */

/*! @name DRRERRA - Data RAM Error Report Address */
/*! @{ */

#define CANXL_RAMECC_DRRERRA_ERRADDR_MASK        (0x7FFFU)
#define CANXL_RAMECC_DRRERRA_ERRADDR_SHIFT       (0U)
#define CANXL_RAMECC_DRRERRA_ERRADDR_WIDTH       (15U)
#define CANXL_RAMECC_DRRERRA_ERRADDR(x)          (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRRERRA_ERRADDR_SHIFT)) & CANXL_RAMECC_DRRERRA_ERRADDR_MASK)

#define CANXL_RAMECC_DRRERRA_NCE_MASK            (0x1000000U)
#define CANXL_RAMECC_DRRERRA_NCE_SHIFT           (24U)
#define CANXL_RAMECC_DRRERRA_NCE_WIDTH           (1U)
#define CANXL_RAMECC_DRRERRA_NCE(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRRERRA_NCE_SHIFT)) & CANXL_RAMECC_DRRERRA_NCE_MASK)
/*! @} */

/*! @name DRRERRD - Data RAM Error Report Data */
/*! @{ */

#define CANXL_RAMECC_DRRERRD_RDATA_MASK          (0xFFFFFFFFU)
#define CANXL_RAMECC_DRRERRD_RDATA_SHIFT         (0U)
#define CANXL_RAMECC_DRRERRD_RDATA_WIDTH         (32U)
#define CANXL_RAMECC_DRRERRD_RDATA(x)            (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRRERRD_RDATA_SHIFT)) & CANXL_RAMECC_DRRERRD_RDATA_MASK)
/*! @} */

/*! @name DRRERRSYN - Data RAM Error Report Syndrome */
/*! @{ */

#define CANXL_RAMECC_DRRERRSYN_SYND0_MASK        (0x1FU)
#define CANXL_RAMECC_DRRERRSYN_SYND0_SHIFT       (0U)
#define CANXL_RAMECC_DRRERRSYN_SYND0_WIDTH       (5U)
#define CANXL_RAMECC_DRRERRSYN_SYND0(x)          (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRRERRSYN_SYND0_SHIFT)) & CANXL_RAMECC_DRRERRSYN_SYND0_MASK)

#define CANXL_RAMECC_DRRERRSYN_BE0_MASK          (0x80U)
#define CANXL_RAMECC_DRRERRSYN_BE0_SHIFT         (7U)
#define CANXL_RAMECC_DRRERRSYN_BE0_WIDTH         (1U)
#define CANXL_RAMECC_DRRERRSYN_BE0(x)            (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRRERRSYN_BE0_SHIFT)) & CANXL_RAMECC_DRRERRSYN_BE0_MASK)

#define CANXL_RAMECC_DRRERRSYN_SYND1_MASK        (0x1F00U)
#define CANXL_RAMECC_DRRERRSYN_SYND1_SHIFT       (8U)
#define CANXL_RAMECC_DRRERRSYN_SYND1_WIDTH       (5U)
#define CANXL_RAMECC_DRRERRSYN_SYND1(x)          (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRRERRSYN_SYND1_SHIFT)) & CANXL_RAMECC_DRRERRSYN_SYND1_MASK)

#define CANXL_RAMECC_DRRERRSYN_BE1_MASK          (0x8000U)
#define CANXL_RAMECC_DRRERRSYN_BE1_SHIFT         (15U)
#define CANXL_RAMECC_DRRERRSYN_BE1_WIDTH         (1U)
#define CANXL_RAMECC_DRRERRSYN_BE1(x)            (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRRERRSYN_BE1_SHIFT)) & CANXL_RAMECC_DRRERRSYN_BE1_MASK)

#define CANXL_RAMECC_DRRERRSYN_SYND2_MASK        (0x1F0000U)
#define CANXL_RAMECC_DRRERRSYN_SYND2_SHIFT       (16U)
#define CANXL_RAMECC_DRRERRSYN_SYND2_WIDTH       (5U)
#define CANXL_RAMECC_DRRERRSYN_SYND2(x)          (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRRERRSYN_SYND2_SHIFT)) & CANXL_RAMECC_DRRERRSYN_SYND2_MASK)

#define CANXL_RAMECC_DRRERRSYN_BE2_MASK          (0x800000U)
#define CANXL_RAMECC_DRRERRSYN_BE2_SHIFT         (23U)
#define CANXL_RAMECC_DRRERRSYN_BE2_WIDTH         (1U)
#define CANXL_RAMECC_DRRERRSYN_BE2(x)            (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRRERRSYN_BE2_SHIFT)) & CANXL_RAMECC_DRRERRSYN_BE2_MASK)

#define CANXL_RAMECC_DRRERRSYN_SYND3_MASK        (0x1F000000U)
#define CANXL_RAMECC_DRRERRSYN_SYND3_SHIFT       (24U)
#define CANXL_RAMECC_DRRERRSYN_SYND3_WIDTH       (5U)
#define CANXL_RAMECC_DRRERRSYN_SYND3(x)          (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRRERRSYN_SYND3_SHIFT)) & CANXL_RAMECC_DRRERRSYN_SYND3_MASK)

#define CANXL_RAMECC_DRRERRSYN_BE3_MASK          (0x80000000U)
#define CANXL_RAMECC_DRRERRSYN_BE3_SHIFT         (31U)
#define CANXL_RAMECC_DRRERRSYN_BE3_WIDTH         (1U)
#define CANXL_RAMECC_DRRERRSYN_BE3(x)            (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRRERRSYN_BE3_SHIFT)) & CANXL_RAMECC_DRRERRSYN_BE3_MASK)
/*! @} */

/*! @name DRERRS - Data RAM Error Status */
/*! @{ */

#define CANXL_RAMECC_DRERRS_CEIOF_MASK           (0x1U)
#define CANXL_RAMECC_DRERRS_CEIOF_SHIFT          (0U)
#define CANXL_RAMECC_DRERRS_CEIOF_WIDTH          (1U)
#define CANXL_RAMECC_DRERRS_CEIOF(x)             (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRERRS_CEIOF_SHIFT)) & CANXL_RAMECC_DRERRS_CEIOF_MASK)

#define CANXL_RAMECC_DRERRS_NCEIOF_MASK          (0x4U)
#define CANXL_RAMECC_DRERRS_NCEIOF_SHIFT         (2U)
#define CANXL_RAMECC_DRERRS_NCEIOF_WIDTH         (1U)
#define CANXL_RAMECC_DRERRS_NCEIOF(x)            (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRERRS_NCEIOF_SHIFT)) & CANXL_RAMECC_DRERRS_NCEIOF_MASK)

#define CANXL_RAMECC_DRERRS_CEIF_MASK            (0x10000U)
#define CANXL_RAMECC_DRERRS_CEIF_SHIFT           (16U)
#define CANXL_RAMECC_DRERRS_CEIF_WIDTH           (1U)
#define CANXL_RAMECC_DRERRS_CEIF(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRERRS_CEIF_SHIFT)) & CANXL_RAMECC_DRERRS_CEIF_MASK)

#define CANXL_RAMECC_DRERRS_NCEIF_MASK           (0x40000U)
#define CANXL_RAMECC_DRERRS_NCEIF_SHIFT          (18U)
#define CANXL_RAMECC_DRERRS_NCEIF_WIDTH          (1U)
#define CANXL_RAMECC_DRERRS_NCEIF(x)             (((uint32_t)(((uint32_t)(x)) << CANXL_RAMECC_DRERRS_NCEIF_SHIFT)) & CANXL_RAMECC_DRERRS_NCEIF_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CANXL_RAMECC_Register_Masks */

/*!
 * @}
 */ /* end of group CANXL_RAMECC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CANXL_RAMECC_H_) */
