/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_SRAMCTL_2.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_SRAMCTL_2
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
#if !defined(S32K566_SRAMCTL_2_H_)  /* Check if memory map has not been already included */
#define S32K566_SRAMCTL_2_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SRAMCTL_2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRAMCTL_2_Peripheral_Access_Layer SRAMCTL_2 Peripheral Access Layer
 * @{
 */

/** SRAMCTL_2 - Register Layout Typedef */
typedef struct SRAMCTL_2_Struct {
  __IO uint32_t RAMCR;                             /**< RAM Control, offset: 0x0 */
  __IO uint32_t RAMIAS;                            /**< RAM Initialization Address Start, offset: 0x4 */
  __IO uint32_t RAMIAE;                            /**< RAM Initialization Address End, offset: 0x8 */
  __IO uint32_t RAMSR;                             /**< RAM Status, offset: 0xC */
  __I  uint32_t RAMMEMA;                           /**< RAM ECC Address, offset: 0x10 */
  uint8_t RESERVED_0[4];
  __I  uint32_t RAMSYSA;                           /**< RAM System Address, offset: 0x18 */
  __IO uint32_t RAMECCNT;                          /**< RAM Correctable Error Count, offset: 0x1C */
  __IO uint32_t RAMEID0;                           /**< RAM Error Injection Data 0, offset: 0x20 */
  __IO uint32_t RAMEID1;                           /**< RAM Error Injection Data 1, offset: 0x24 */
  __IO uint32_t RAMEIDC;                           /**< RAM Error Injection Data Control, offset: 0x28 */
  uint8_t RESERVED_1[4];
  __IO uint32_t RAMEIA;                            /**< RAM Error Injection Base Address, offset: 0x30 */
  __IO uint32_t RAMEIAM;                           /**< RAM Error Injection Address Mask, offset: 0x34 */
  uint8_t RESERVED_2[8];
  __IO uint32_t RAMMAXA;                           /**< RAM Maximum-Value Address, offset: 0x40 */
  uint8_t RESERVED_3[60];
  __IO uint32_t RAMCR2;                            /**< RAM Control 2, offset: 0x80 */
} SRAMCTL_2_Type, *SRAMCTL_2_MemMapPtr;

/** Number of instances of the SRAMCTL_2 module. */
#define SRAMCTL_2_INSTANCE_COUNT                 (1u)

/* SRAMCTL_2 - Peripheral instance base addresses */
/** Peripheral SRAMCTL_2 base address */
#define IP_SRAMCTL_2_BASE                        (0x40B34000u)
/** Peripheral SRAMCTL_2 base pointer */
#define IP_SRAMCTL_2                             ((SRAMCTL_2_Type *)IP_SRAMCTL_2_BASE)
/** Array initializer of SRAMCTL_2 peripheral base addresses */
#define IP_SRAMCTL_2_BASE_ADDRS                  { IP_SRAMCTL_2_BASE }
/** Array initializer of SRAMCTL_2 peripheral base pointers */
#define IP_SRAMCTL_2_BASE_PTRS                   { IP_SRAMCTL_2 }

/* ----------------------------------------------------------------------------
   -- SRAMCTL_2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRAMCTL_2_Register_Masks SRAMCTL_2 Register Masks
 * @{
 */

/*! @name RAMCR - RAM Control */
/*! @{ */

#define SRAMCTL_2_RAMCR_INIT_MASK                (0x1U)
#define SRAMCTL_2_RAMCR_INIT_SHIFT               (0U)
#define SRAMCTL_2_RAMCR_INIT_WIDTH               (1U)
#define SRAMCTL_2_RAMCR_INIT(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMCR_INIT_SHIFT)) & SRAMCTL_2_RAMCR_INIT_MASK)

#define SRAMCTL_2_RAMCR_IWS_MASK                 (0x6U)
#define SRAMCTL_2_RAMCR_IWS_SHIFT                (1U)
#define SRAMCTL_2_RAMCR_IWS_WIDTH                (2U)
#define SRAMCTL_2_RAMCR_IWS(x)                   (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMCR_IWS_SHIFT)) & SRAMCTL_2_RAMCR_IWS_MASK)

#define SRAMCTL_2_RAMCR_INIT_SYSA_MASK           (0x100U)
#define SRAMCTL_2_RAMCR_INIT_SYSA_SHIFT          (8U)
#define SRAMCTL_2_RAMCR_INIT_SYSA_WIDTH          (1U)
#define SRAMCTL_2_RAMCR_INIT_SYSA(x)             (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMCR_INIT_SYSA_SHIFT)) & SRAMCTL_2_RAMCR_INIT_SYSA_MASK)
/*! @} */

/*! @name RAMIAS - RAM Initialization Address Start */
/*! @{ */

#define SRAMCTL_2_RAMIAS_IAS_MASK                (0xFFFFFFFFU)
#define SRAMCTL_2_RAMIAS_IAS_SHIFT               (0U)
#define SRAMCTL_2_RAMIAS_IAS_WIDTH               (32U)
#define SRAMCTL_2_RAMIAS_IAS(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMIAS_IAS_SHIFT)) & SRAMCTL_2_RAMIAS_IAS_MASK)
/*! @} */

/*! @name RAMIAE - RAM Initialization Address End */
/*! @{ */

#define SRAMCTL_2_RAMIAE_IAE_MASK                (0xFFFFFFFFU)
#define SRAMCTL_2_RAMIAE_IAE_SHIFT               (0U)
#define SRAMCTL_2_RAMIAE_IAE_WIDTH               (32U)
#define SRAMCTL_2_RAMIAE_IAE(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMIAE_IAE_SHIFT)) & SRAMCTL_2_RAMIAE_IAE_MASK)
/*! @} */

/*! @name RAMSR - RAM Status */
/*! @{ */

#define SRAMCTL_2_RAMSR_IDONE_MASK               (0x1U)
#define SRAMCTL_2_RAMSR_IDONE_SHIFT              (0U)
#define SRAMCTL_2_RAMSR_IDONE_WIDTH              (1U)
#define SRAMCTL_2_RAMSR_IDONE(x)                 (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMSR_IDONE_SHIFT)) & SRAMCTL_2_RAMSR_IDONE_MASK)

#define SRAMCTL_2_RAMSR_BUSERR_MASK              (0x2U)
#define SRAMCTL_2_RAMSR_BUSERR_SHIFT             (1U)
#define SRAMCTL_2_RAMSR_BUSERR_WIDTH             (1U)
#define SRAMCTL_2_RAMSR_BUSERR(x)                (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMSR_BUSERR_SHIFT)) & SRAMCTL_2_RAMSR_BUSERR_MASK)

#define SRAMCTL_2_RAMSR_IPEND_MASK               (0x4U)
#define SRAMCTL_2_RAMSR_IPEND_SHIFT              (2U)
#define SRAMCTL_2_RAMSR_IPEND_WIDTH              (1U)
#define SRAMCTL_2_RAMSR_IPEND(x)                 (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMSR_IPEND_SHIFT)) & SRAMCTL_2_RAMSR_IPEND_MASK)

#define SRAMCTL_2_RAMSR_AVALID_MASK              (0x8U)
#define SRAMCTL_2_RAMSR_AVALID_SHIFT             (3U)
#define SRAMCTL_2_RAMSR_AVALID_WIDTH             (1U)
#define SRAMCTL_2_RAMSR_AVALID(x)                (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMSR_AVALID_SHIFT)) & SRAMCTL_2_RAMSR_AVALID_MASK)

#define SRAMCTL_2_RAMSR_AERR_MASK                (0x20U)
#define SRAMCTL_2_RAMSR_AERR_SHIFT               (5U)
#define SRAMCTL_2_RAMSR_AERR_WIDTH               (1U)
#define SRAMCTL_2_RAMSR_AERR(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMSR_AERR_SHIFT)) & SRAMCTL_2_RAMSR_AERR_MASK)

#define SRAMCTL_2_RAMSR_MLTERR_MASK              (0x40U)
#define SRAMCTL_2_RAMSR_MLTERR_SHIFT             (6U)
#define SRAMCTL_2_RAMSR_MLTERR_WIDTH             (1U)
#define SRAMCTL_2_RAMSR_MLTERR(x)                (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMSR_MLTERR_SHIFT)) & SRAMCTL_2_RAMSR_MLTERR_MASK)

#define SRAMCTL_2_RAMSR_SGLERR_MASK              (0x80U)
#define SRAMCTL_2_RAMSR_SGLERR_SHIFT             (7U)
#define SRAMCTL_2_RAMSR_SGLERR_WIDTH             (1U)
#define SRAMCTL_2_RAMSR_SGLERR(x)                (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMSR_SGLERR_SHIFT)) & SRAMCTL_2_RAMSR_SGLERR_MASK)

#define SRAMCTL_2_RAMSR_SYND_MASK                (0xFF00U)
#define SRAMCTL_2_RAMSR_SYND_SHIFT               (8U)
#define SRAMCTL_2_RAMSR_SYND_WIDTH               (8U)
#define SRAMCTL_2_RAMSR_SYND(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMSR_SYND_SHIFT)) & SRAMCTL_2_RAMSR_SYND_MASK)

#define SRAMCTL_2_RAMSR_EINFO_MASK               (0xFF0000U)
#define SRAMCTL_2_RAMSR_EINFO_SHIFT              (16U)
#define SRAMCTL_2_RAMSR_EINFO_WIDTH              (8U)
#define SRAMCTL_2_RAMSR_EINFO(x)                 (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMSR_EINFO_SHIFT)) & SRAMCTL_2_RAMSR_EINFO_MASK)

#define SRAMCTL_2_RAMSR_ERW_MASK                 (0x2000000U)
#define SRAMCTL_2_RAMSR_ERW_SHIFT                (25U)
#define SRAMCTL_2_RAMSR_ERW_WIDTH                (1U)
#define SRAMCTL_2_RAMSR_ERW(x)                   (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMSR_ERW_SHIFT)) & SRAMCTL_2_RAMSR_ERW_MASK)
/*! @} */

/*! @name RAMMEMA - RAM ECC Address */
/*! @{ */

#define SRAMCTL_2_RAMMEMA_MEMA_MASK              (0x1FFFFU)
#define SRAMCTL_2_RAMMEMA_MEMA_SHIFT             (0U)
#define SRAMCTL_2_RAMMEMA_MEMA_WIDTH             (17U)
#define SRAMCTL_2_RAMMEMA_MEMA(x)                (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMMEMA_MEMA_SHIFT)) & SRAMCTL_2_RAMMEMA_MEMA_MASK)

#define SRAMCTL_2_RAMMEMA_BANK_MASK              (0x1F00000U)
#define SRAMCTL_2_RAMMEMA_BANK_SHIFT             (20U)
#define SRAMCTL_2_RAMMEMA_BANK_WIDTH             (5U)
#define SRAMCTL_2_RAMMEMA_BANK(x)                (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMMEMA_BANK_SHIFT)) & SRAMCTL_2_RAMMEMA_BANK_MASK)
/*! @} */

/*! @name RAMSYSA - RAM System Address */
/*! @{ */

#define SRAMCTL_2_RAMSYSA_SYSA_MASK              (0xFFFFFFFFU)
#define SRAMCTL_2_RAMSYSA_SYSA_SHIFT             (0U)
#define SRAMCTL_2_RAMSYSA_SYSA_WIDTH             (32U)
#define SRAMCTL_2_RAMSYSA_SYSA(x)                (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMSYSA_SYSA_SHIFT)) & SRAMCTL_2_RAMSYSA_SYSA_MASK)
/*! @} */

/*! @name RAMECCNT - RAM Correctable Error Count */
/*! @{ */

#define SRAMCTL_2_RAMECCNT_ECCNT_MASK            (0xFFU)
#define SRAMCTL_2_RAMECCNT_ECCNT_SHIFT           (0U)
#define SRAMCTL_2_RAMECCNT_ECCNT_WIDTH           (8U)
#define SRAMCTL_2_RAMECCNT_ECCNT(x)              (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMECCNT_ECCNT_SHIFT)) & SRAMCTL_2_RAMECCNT_ECCNT_MASK)
/*! @} */

/*! @name RAMEID0 - RAM Error Injection Data 0 */
/*! @{ */

#define SRAMCTL_2_RAMEID0_EID_W0_MASK            (0xFFFFFFFFU)
#define SRAMCTL_2_RAMEID0_EID_W0_SHIFT           (0U)
#define SRAMCTL_2_RAMEID0_EID_W0_WIDTH           (32U)
#define SRAMCTL_2_RAMEID0_EID_W0(x)              (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMEID0_EID_W0_SHIFT)) & SRAMCTL_2_RAMEID0_EID_W0_MASK)
/*! @} */

/*! @name RAMEID1 - RAM Error Injection Data 1 */
/*! @{ */

#define SRAMCTL_2_RAMEID1_EID_W1_MASK            (0xFFFFFFFFU)
#define SRAMCTL_2_RAMEID1_EID_W1_SHIFT           (0U)
#define SRAMCTL_2_RAMEID1_EID_W1_WIDTH           (32U)
#define SRAMCTL_2_RAMEID1_EID_W1(x)              (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMEID1_EID_W1_SHIFT)) & SRAMCTL_2_RAMEID1_EID_W1_MASK)
/*! @} */

/*! @name RAMEIDC - RAM Error Injection Data Control */
/*! @{ */

#define SRAMCTL_2_RAMEIDC_EID_CKB_MASK           (0xFFU)
#define SRAMCTL_2_RAMEIDC_EID_CKB_SHIFT          (0U)
#define SRAMCTL_2_RAMEIDC_EID_CKB_WIDTH          (8U)
#define SRAMCTL_2_RAMEIDC_EID_CKB(x)             (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMEIDC_EID_CKB_SHIFT)) & SRAMCTL_2_RAMEIDC_EID_CKB_MASK)

#define SRAMCTL_2_RAMEIDC_EI_EN_MASK             (0x1000000U)
#define SRAMCTL_2_RAMEIDC_EI_EN_SHIFT            (24U)
#define SRAMCTL_2_RAMEIDC_EI_EN_WIDTH            (1U)
#define SRAMCTL_2_RAMEIDC_EI_EN(x)               (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMEIDC_EI_EN_SHIFT)) & SRAMCTL_2_RAMEIDC_EI_EN_MASK)

#define SRAMCTL_2_RAMEIDC_EIA_EN_MASK            (0x40000000U)
#define SRAMCTL_2_RAMEIDC_EIA_EN_SHIFT           (30U)
#define SRAMCTL_2_RAMEIDC_EIA_EN_WIDTH           (1U)
#define SRAMCTL_2_RAMEIDC_EIA_EN(x)              (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMEIDC_EIA_EN_SHIFT)) & SRAMCTL_2_RAMEIDC_EIA_EN_MASK)

#define SRAMCTL_2_RAMEIDC_EID_EN_MASK            (0x80000000U)
#define SRAMCTL_2_RAMEIDC_EID_EN_SHIFT           (31U)
#define SRAMCTL_2_RAMEIDC_EID_EN_WIDTH           (1U)
#define SRAMCTL_2_RAMEIDC_EID_EN(x)              (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMEIDC_EID_EN_SHIFT)) & SRAMCTL_2_RAMEIDC_EID_EN_MASK)
/*! @} */

/*! @name RAMEIA - RAM Error Injection Base Address */
/*! @{ */

#define SRAMCTL_2_RAMEIA_EIA_MASK                (0xFFFFFFFFU)
#define SRAMCTL_2_RAMEIA_EIA_SHIFT               (0U)
#define SRAMCTL_2_RAMEIA_EIA_WIDTH               (32U)
#define SRAMCTL_2_RAMEIA_EIA(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMEIA_EIA_SHIFT)) & SRAMCTL_2_RAMEIA_EIA_MASK)
/*! @} */

/*! @name RAMEIAM - RAM Error Injection Address Mask */
/*! @{ */

#define SRAMCTL_2_RAMEIAM_EIAM_MASK              (0xFFFFFFFFU)
#define SRAMCTL_2_RAMEIAM_EIAM_SHIFT             (0U)
#define SRAMCTL_2_RAMEIAM_EIAM_WIDTH             (32U)
#define SRAMCTL_2_RAMEIAM_EIAM(x)                (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMEIAM_EIAM_SHIFT)) & SRAMCTL_2_RAMEIAM_EIAM_MASK)
/*! @} */

/*! @name RAMMAXA - RAM Maximum-Value Address */
/*! @{ */

#define SRAMCTL_2_RAMMAXA_MAXA_MASK              (0xFFFFFFFFU)
#define SRAMCTL_2_RAMMAXA_MAXA_SHIFT             (0U)
#define SRAMCTL_2_RAMMAXA_MAXA_WIDTH             (32U)
#define SRAMCTL_2_RAMMAXA_MAXA(x)                (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMMAXA_MAXA_SHIFT)) & SRAMCTL_2_RAMMAXA_MAXA_MASK)
/*! @} */

/*! @name RAMCR2 - RAM Control 2 */
/*! @{ */

#define SRAMCTL_2_RAMCR2_DEM_MASK                (0x8U)
#define SRAMCTL_2_RAMCR2_DEM_SHIFT               (3U)
#define SRAMCTL_2_RAMCR2_DEM_WIDTH               (1U)
#define SRAMCTL_2_RAMCR2_DEM(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_2_RAMCR2_DEM_SHIFT)) & SRAMCTL_2_RAMCR2_DEM_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SRAMCTL_2_Register_Masks */

/*!
 * @}
 */ /* end of group SRAMCTL_2_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_SRAMCTL_2_H_) */
