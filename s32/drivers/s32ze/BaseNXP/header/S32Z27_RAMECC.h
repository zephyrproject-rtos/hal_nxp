/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z27_RAMECC.h
 * @version 1.7
 * @date 2022-03-16
 * @brief Peripheral Access Layer for S32Z27_RAMECC
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
#if !defined(S32Z27_RAMECC_H_)  /* Check if memory map has not been already included */
#define S32Z27_RAMECC_H_

#include "S32Z27_COMMON.h"

/* ----------------------------------------------------------------------------
   -- RAMECC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RAMECC_Peripheral_Access_Layer RAMECC Peripheral Access Layer
 * @{
 */

/** RAMECC - Register Layout Typedef */
typedef struct {
  __IO uint32_t DRMEC;                             /**< Data RAM Memory Error Control, offset: 0x0 */
  __IO uint32_t DRERRIA;                           /**< Data RAM Error Injection Address, offset: 0x4 */
  __IO uint32_t DRERRIDP;                          /**< Data RAM Error Injection Data Pattern, offset: 0x8 */
  __IO uint32_t DRERRIPP;                          /**< Data RAM Error Injection Parity Pattern, offset: 0xC */
  __I  uint32_t DRRERRA;                           /**< Data RAM Error Report Address, offset: 0x10 */
  __I  uint32_t DRRERRD;                           /**< Data RAM Error Report Data, offset: 0x14 */
  __I  uint32_t DRRERRSYN;                         /**< Data RAM Error Report Syndrome, offset: 0x18 */
  __IO uint32_t DRERRS;                            /**< Data RAM Error Status, offset: 0x1C */
} RAMECC_Type, *RAMECC_MemMapPtr;

/** Number of instances of the RAMECC module. */
#define RAMECC_INSTANCE_COUNT                    (2u)

/* RAMECC - Peripheral instance base addresses */
/** Peripheral CANXL_0__RAMECC base address */
#define IP_CANXL_0__RAMECC_BASE                  (0x47460000u)
/** Peripheral CANXL_0__RAMECC base pointer */
#define IP_CANXL_0__RAMECC                       ((RAMECC_Type *)IP_CANXL_0__RAMECC_BASE)
/** Peripheral CANXL_1__RAMECC base address */
#define IP_CANXL_1__RAMECC_BASE                  (0x47560000u)
/** Peripheral CANXL_1__RAMECC base pointer */
#define IP_CANXL_1__RAMECC                       ((RAMECC_Type *)IP_CANXL_1__RAMECC_BASE)
/** Array initializer of RAMECC peripheral base addresses */
#define IP_RAMECC_BASE_ADDRS                     { IP_CANXL_0__RAMECC_BASE, IP_CANXL_1__RAMECC_BASE }
/** Array initializer of RAMECC peripheral base pointers */
#define IP_RAMECC_BASE_PTRS                      { IP_CANXL_0__RAMECC, IP_CANXL_1__RAMECC }

/* ----------------------------------------------------------------------------
   -- RAMECC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RAMECC_Register_Masks RAMECC Register Masks
 * @{
 */

/*! @name DRMEC - Data RAM Memory Error Control */
/*! @{ */

#define RAMECC_DRMEC_ECCDIS_MASK                 (0x100U)
#define RAMECC_DRMEC_ECCDIS_SHIFT                (8U)
#define RAMECC_DRMEC_ECCDIS_WIDTH                (1U)
#define RAMECC_DRMEC_ECCDIS(x)                   (((uint32_t)(((uint32_t)(x)) << RAMECC_DRMEC_ECCDIS_SHIFT)) & RAMECC_DRMEC_ECCDIS_MASK)

#define RAMECC_DRMEC_ERRRPTDIS_MASK              (0x200U)
#define RAMECC_DRMEC_ERRRPTDIS_SHIFT             (9U)
#define RAMECC_DRMEC_ERRRPTDIS_WIDTH             (1U)
#define RAMECC_DRMEC_ERRRPTDIS(x)                (((uint32_t)(((uint32_t)(x)) << RAMECC_DRMEC_ERRRPTDIS_SHIFT)) & RAMECC_DRMEC_ERRRPTDIS_MASK)

#define RAMECC_DRMEC_ERRINJEN_MASK               (0x4000U)
#define RAMECC_DRMEC_ERRINJEN_SHIFT              (14U)
#define RAMECC_DRMEC_ERRINJEN_WIDTH              (1U)
#define RAMECC_DRMEC_ERRINJEN(x)                 (((uint32_t)(((uint32_t)(x)) << RAMECC_DRMEC_ERRINJEN_SHIFT)) & RAMECC_DRMEC_ERRINJEN_MASK)

#define RAMECC_DRMEC_CEIEN_MASK                  (0x10000U)
#define RAMECC_DRMEC_CEIEN_SHIFT                 (16U)
#define RAMECC_DRMEC_CEIEN_WIDTH                 (1U)
#define RAMECC_DRMEC_CEIEN(x)                    (((uint32_t)(((uint32_t)(x)) << RAMECC_DRMEC_CEIEN_SHIFT)) & RAMECC_DRMEC_CEIEN_MASK)

#define RAMECC_DRMEC_NCEIEN_MASK                 (0x40000U)
#define RAMECC_DRMEC_NCEIEN_SHIFT                (18U)
#define RAMECC_DRMEC_NCEIEN_WIDTH                (1U)
#define RAMECC_DRMEC_NCEIEN(x)                   (((uint32_t)(((uint32_t)(x)) << RAMECC_DRMEC_NCEIEN_SHIFT)) & RAMECC_DRMEC_NCEIEN_MASK)

#define RAMECC_DRMEC_ECRWRDIS_MASK               (0x80000000U)
#define RAMECC_DRMEC_ECRWRDIS_SHIFT              (31U)
#define RAMECC_DRMEC_ECRWRDIS_WIDTH              (1U)
#define RAMECC_DRMEC_ECRWRDIS(x)                 (((uint32_t)(((uint32_t)(x)) << RAMECC_DRMEC_ECRWRDIS_SHIFT)) & RAMECC_DRMEC_ECRWRDIS_MASK)
/*! @} */

/*! @name DRERRIA - Data RAM Error Injection Address */
/*! @{ */

#define RAMECC_DRERRIA_INJADDR_L_MASK            (0x3U)
#define RAMECC_DRERRIA_INJADDR_L_SHIFT           (0U)
#define RAMECC_DRERRIA_INJADDR_L_WIDTH           (2U)
#define RAMECC_DRERRIA_INJADDR_L(x)              (((uint32_t)(((uint32_t)(x)) << RAMECC_DRERRIA_INJADDR_L_SHIFT)) & RAMECC_DRERRIA_INJADDR_L_MASK)

#define RAMECC_DRERRIA_INJADDR_H_MASK            (0x7FFCU)
#define RAMECC_DRERRIA_INJADDR_H_SHIFT           (2U)
#define RAMECC_DRERRIA_INJADDR_H_WIDTH           (13U)
#define RAMECC_DRERRIA_INJADDR_H(x)              (((uint32_t)(((uint32_t)(x)) << RAMECC_DRERRIA_INJADDR_H_SHIFT)) & RAMECC_DRERRIA_INJADDR_H_MASK)
/*! @} */

/*! @name DRERRIDP - Data RAM Error Injection Data Pattern */
/*! @{ */

#define RAMECC_DRERRIDP_DFLIP_MASK               (0xFFFFFFFFU)
#define RAMECC_DRERRIDP_DFLIP_SHIFT              (0U)
#define RAMECC_DRERRIDP_DFLIP_WIDTH              (32U)
#define RAMECC_DRERRIDP_DFLIP(x)                 (((uint32_t)(((uint32_t)(x)) << RAMECC_DRERRIDP_DFLIP_SHIFT)) & RAMECC_DRERRIDP_DFLIP_MASK)
/*! @} */

/*! @name DRERRIPP - Data RAM Error Injection Parity Pattern */
/*! @{ */

#define RAMECC_DRERRIPP_PFLIP0_MASK              (0x1FU)
#define RAMECC_DRERRIPP_PFLIP0_SHIFT             (0U)
#define RAMECC_DRERRIPP_PFLIP0_WIDTH             (5U)
#define RAMECC_DRERRIPP_PFLIP0(x)                (((uint32_t)(((uint32_t)(x)) << RAMECC_DRERRIPP_PFLIP0_SHIFT)) & RAMECC_DRERRIPP_PFLIP0_MASK)

#define RAMECC_DRERRIPP_PFLIP1_MASK              (0x1F00U)
#define RAMECC_DRERRIPP_PFLIP1_SHIFT             (8U)
#define RAMECC_DRERRIPP_PFLIP1_WIDTH             (5U)
#define RAMECC_DRERRIPP_PFLIP1(x)                (((uint32_t)(((uint32_t)(x)) << RAMECC_DRERRIPP_PFLIP1_SHIFT)) & RAMECC_DRERRIPP_PFLIP1_MASK)

#define RAMECC_DRERRIPP_PFLIP2_MASK              (0x1F0000U)
#define RAMECC_DRERRIPP_PFLIP2_SHIFT             (16U)
#define RAMECC_DRERRIPP_PFLIP2_WIDTH             (5U)
#define RAMECC_DRERRIPP_PFLIP2(x)                (((uint32_t)(((uint32_t)(x)) << RAMECC_DRERRIPP_PFLIP2_SHIFT)) & RAMECC_DRERRIPP_PFLIP2_MASK)

#define RAMECC_DRERRIPP_PFLIP3_MASK              (0x1F000000U)
#define RAMECC_DRERRIPP_PFLIP3_SHIFT             (24U)
#define RAMECC_DRERRIPP_PFLIP3_WIDTH             (5U)
#define RAMECC_DRERRIPP_PFLIP3(x)                (((uint32_t)(((uint32_t)(x)) << RAMECC_DRERRIPP_PFLIP3_SHIFT)) & RAMECC_DRERRIPP_PFLIP3_MASK)
/*! @} */

/*! @name DRRERRA - Data RAM Error Report Address */
/*! @{ */

#define RAMECC_DRRERRA_ERRADDR_MASK              (0x7FFFU)
#define RAMECC_DRRERRA_ERRADDR_SHIFT             (0U)
#define RAMECC_DRRERRA_ERRADDR_WIDTH             (15U)
#define RAMECC_DRRERRA_ERRADDR(x)                (((uint32_t)(((uint32_t)(x)) << RAMECC_DRRERRA_ERRADDR_SHIFT)) & RAMECC_DRRERRA_ERRADDR_MASK)

#define RAMECC_DRRERRA_NCE_MASK                  (0x1000000U)
#define RAMECC_DRRERRA_NCE_SHIFT                 (24U)
#define RAMECC_DRRERRA_NCE_WIDTH                 (1U)
#define RAMECC_DRRERRA_NCE(x)                    (((uint32_t)(((uint32_t)(x)) << RAMECC_DRRERRA_NCE_SHIFT)) & RAMECC_DRRERRA_NCE_MASK)
/*! @} */

/*! @name DRRERRD - Data RAM Error Report Data */
/*! @{ */

#define RAMECC_DRRERRD_RDATA_MASK                (0xFFFFFFFFU)
#define RAMECC_DRRERRD_RDATA_SHIFT               (0U)
#define RAMECC_DRRERRD_RDATA_WIDTH               (32U)
#define RAMECC_DRRERRD_RDATA(x)                  (((uint32_t)(((uint32_t)(x)) << RAMECC_DRRERRD_RDATA_SHIFT)) & RAMECC_DRRERRD_RDATA_MASK)
/*! @} */

/*! @name DRRERRSYN - Data RAM Error Report Syndrome */
/*! @{ */

#define RAMECC_DRRERRSYN_SYND0_MASK              (0x1FU)
#define RAMECC_DRRERRSYN_SYND0_SHIFT             (0U)
#define RAMECC_DRRERRSYN_SYND0_WIDTH             (5U)
#define RAMECC_DRRERRSYN_SYND0(x)                (((uint32_t)(((uint32_t)(x)) << RAMECC_DRRERRSYN_SYND0_SHIFT)) & RAMECC_DRRERRSYN_SYND0_MASK)

#define RAMECC_DRRERRSYN_BE0_MASK                (0x80U)
#define RAMECC_DRRERRSYN_BE0_SHIFT               (7U)
#define RAMECC_DRRERRSYN_BE0_WIDTH               (1U)
#define RAMECC_DRRERRSYN_BE0(x)                  (((uint32_t)(((uint32_t)(x)) << RAMECC_DRRERRSYN_BE0_SHIFT)) & RAMECC_DRRERRSYN_BE0_MASK)

#define RAMECC_DRRERRSYN_SYND1_MASK              (0x1F00U)
#define RAMECC_DRRERRSYN_SYND1_SHIFT             (8U)
#define RAMECC_DRRERRSYN_SYND1_WIDTH             (5U)
#define RAMECC_DRRERRSYN_SYND1(x)                (((uint32_t)(((uint32_t)(x)) << RAMECC_DRRERRSYN_SYND1_SHIFT)) & RAMECC_DRRERRSYN_SYND1_MASK)

#define RAMECC_DRRERRSYN_BE1_MASK                (0x8000U)
#define RAMECC_DRRERRSYN_BE1_SHIFT               (15U)
#define RAMECC_DRRERRSYN_BE1_WIDTH               (1U)
#define RAMECC_DRRERRSYN_BE1(x)                  (((uint32_t)(((uint32_t)(x)) << RAMECC_DRRERRSYN_BE1_SHIFT)) & RAMECC_DRRERRSYN_BE1_MASK)

#define RAMECC_DRRERRSYN_SYND2_MASK              (0x1F0000U)
#define RAMECC_DRRERRSYN_SYND2_SHIFT             (16U)
#define RAMECC_DRRERRSYN_SYND2_WIDTH             (5U)
#define RAMECC_DRRERRSYN_SYND2(x)                (((uint32_t)(((uint32_t)(x)) << RAMECC_DRRERRSYN_SYND2_SHIFT)) & RAMECC_DRRERRSYN_SYND2_MASK)

#define RAMECC_DRRERRSYN_BE2_MASK                (0x800000U)
#define RAMECC_DRRERRSYN_BE2_SHIFT               (23U)
#define RAMECC_DRRERRSYN_BE2_WIDTH               (1U)
#define RAMECC_DRRERRSYN_BE2(x)                  (((uint32_t)(((uint32_t)(x)) << RAMECC_DRRERRSYN_BE2_SHIFT)) & RAMECC_DRRERRSYN_BE2_MASK)

#define RAMECC_DRRERRSYN_SYND3_MASK              (0x1F000000U)
#define RAMECC_DRRERRSYN_SYND3_SHIFT             (24U)
#define RAMECC_DRRERRSYN_SYND3_WIDTH             (5U)
#define RAMECC_DRRERRSYN_SYND3(x)                (((uint32_t)(((uint32_t)(x)) << RAMECC_DRRERRSYN_SYND3_SHIFT)) & RAMECC_DRRERRSYN_SYND3_MASK)

#define RAMECC_DRRERRSYN_BE3_MASK                (0x80000000U)
#define RAMECC_DRRERRSYN_BE3_SHIFT               (31U)
#define RAMECC_DRRERRSYN_BE3_WIDTH               (1U)
#define RAMECC_DRRERRSYN_BE3(x)                  (((uint32_t)(((uint32_t)(x)) << RAMECC_DRRERRSYN_BE3_SHIFT)) & RAMECC_DRRERRSYN_BE3_MASK)
/*! @} */

/*! @name DRERRS - Data RAM Error Status */
/*! @{ */

#define RAMECC_DRERRS_CEIOF_MASK                 (0x1U)
#define RAMECC_DRERRS_CEIOF_SHIFT                (0U)
#define RAMECC_DRERRS_CEIOF_WIDTH                (1U)
#define RAMECC_DRERRS_CEIOF(x)                   (((uint32_t)(((uint32_t)(x)) << RAMECC_DRERRS_CEIOF_SHIFT)) & RAMECC_DRERRS_CEIOF_MASK)

#define RAMECC_DRERRS_NCEIOF_MASK                (0x4U)
#define RAMECC_DRERRS_NCEIOF_SHIFT               (2U)
#define RAMECC_DRERRS_NCEIOF_WIDTH               (1U)
#define RAMECC_DRERRS_NCEIOF(x)                  (((uint32_t)(((uint32_t)(x)) << RAMECC_DRERRS_NCEIOF_SHIFT)) & RAMECC_DRERRS_NCEIOF_MASK)

#define RAMECC_DRERRS_CEIF_MASK                  (0x10000U)
#define RAMECC_DRERRS_CEIF_SHIFT                 (16U)
#define RAMECC_DRERRS_CEIF_WIDTH                 (1U)
#define RAMECC_DRERRS_CEIF(x)                    (((uint32_t)(((uint32_t)(x)) << RAMECC_DRERRS_CEIF_SHIFT)) & RAMECC_DRERRS_CEIF_MASK)

#define RAMECC_DRERRS_NCEIF_MASK                 (0x40000U)
#define RAMECC_DRERRS_NCEIF_SHIFT                (18U)
#define RAMECC_DRERRS_NCEIF_WIDTH                (1U)
#define RAMECC_DRERRS_NCEIF(x)                   (((uint32_t)(((uint32_t)(x)) << RAMECC_DRERRS_NCEIF_SHIFT)) & RAMECC_DRERRS_NCEIF_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group RAMECC_Register_Masks */

/*!
 * @}
 */ /* end of group RAMECC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z27_RAMECC_H_) */
