/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_ADC_BIST_FIR.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_ADC_BIST_FIR
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
#if !defined(S32K39_ADC_BIST_FIR_H_)  /* Check if memory map has not been already included */
#define S32K39_ADC_BIST_FIR_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ADC_BIST_FIR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_BIST_FIR_Peripheral_Access_Layer ADC_BIST_FIR Peripheral Access Layer
 * @{
 */

/** ADC_BIST_FIR - Register Layout Typedef */
typedef struct {
  __IO uint32_t FIR_CNTRL;                         /**< Finite Impulse Response Filter Control, offset: 0x0 */
  __IO uint32_t GEC_PRGRM_FACTOR;                  /**< Gain Error Correction Programmable Factor, offset: 0x4 */
  uint8_t RESERVED_0[52];
  __IO uint32_t SFR;                               /**< Status Flag Register, offset: 0x3C */
  __IO uint32_t RSER;                              /**< Request Select and Enable Register, offset: 0x40 */
  __IO uint32_t OSDR;                              /**< Output Settling Delay Register, offset: 0x44 */
  __IO uint32_t FCR;                               /**< FIFO Control Register, offset: 0x48 */
  __I  uint32_t CDR;                               /**< Converted Data Register, offset: 0x4C */
} ADC_BIST_FIR_Type, *ADC_BIST_FIR_MemMapPtr;

/** Number of instances of the ADC_BIST_FIR module. */
#define ADC_BIST_FIR_INSTANCE_COUNT              (1u)

/* ADC_BIST_FIR - Peripheral instance base addresses */
/** Peripheral ADC_BIST_FIR base address */
#define IP_ADC_BIST_FIR_BASE                     (0x40704800u)
/** Peripheral ADC_BIST_FIR base pointer */
#define IP_ADC_BIST_FIR                          ((ADC_BIST_FIR_Type *)IP_ADC_BIST_FIR_BASE)
/** Array initializer of ADC_BIST_FIR peripheral base addresses */
#define IP_ADC_BIST_FIR_BASE_ADDRS               { IP_ADC_BIST_FIR_BASE }
/** Array initializer of ADC_BIST_FIR peripheral base pointers */
#define IP_ADC_BIST_FIR_BASE_PTRS                { IP_ADC_BIST_FIR }

/* ----------------------------------------------------------------------------
   -- ADC_BIST_FIR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_BIST_FIR_Register_Masks ADC_BIST_FIR Register Masks
 * @{
 */

/*! @name FIR_CNTRL - Finite Impulse Response Filter Control */
/*! @{ */

#define ADC_BIST_FIR_FIR_CNTRL_GEC_EN_MASK       (0x1U)
#define ADC_BIST_FIR_FIR_CNTRL_GEC_EN_SHIFT      (0U)
#define ADC_BIST_FIR_FIR_CNTRL_GEC_EN_WIDTH      (1U)
#define ADC_BIST_FIR_FIR_CNTRL_GEC_EN(x)         (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_FIR_CNTRL_GEC_EN_SHIFT)) & ADC_BIST_FIR_FIR_CNTRL_GEC_EN_MASK)

#define ADC_BIST_FIR_FIR_CNTRL_PGA2_EN_MASK      (0x2U)
#define ADC_BIST_FIR_FIR_CNTRL_PGA2_EN_SHIFT     (1U)
#define ADC_BIST_FIR_FIR_CNTRL_PGA2_EN_WIDTH     (1U)
#define ADC_BIST_FIR_FIR_CNTRL_PGA2_EN(x)        (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_FIR_CNTRL_PGA2_EN_SHIFT)) & ADC_BIST_FIR_FIR_CNTRL_PGA2_EN_MASK)
/*! @} */

/*! @name GEC_PRGRM_FACTOR - Gain Error Correction Programmable Factor */
/*! @{ */

#define ADC_BIST_FIR_GEC_PRGRM_FACTOR_GEC_PRGRM_MASK (0x3FFFFU)
#define ADC_BIST_FIR_GEC_PRGRM_FACTOR_GEC_PRGRM_SHIFT (0U)
#define ADC_BIST_FIR_GEC_PRGRM_FACTOR_GEC_PRGRM_WIDTH (18U)
#define ADC_BIST_FIR_GEC_PRGRM_FACTOR_GEC_PRGRM(x) (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_GEC_PRGRM_FACTOR_GEC_PRGRM_SHIFT)) & ADC_BIST_FIR_GEC_PRGRM_FACTOR_GEC_PRGRM_MASK)
/*! @} */

/*! @name SFR - Status Flag Register */
/*! @{ */

#define ADC_BIST_FIR_SFR_DFFF_MASK               (0x1U)
#define ADC_BIST_FIR_SFR_DFFF_SHIFT              (0U)
#define ADC_BIST_FIR_SFR_DFFF_WIDTH              (1U)
#define ADC_BIST_FIR_SFR_DFFF(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_SFR_DFFF_SHIFT)) & ADC_BIST_FIR_SFR_DFFF_MASK)

#define ADC_BIST_FIR_SFR_DFORF_MASK              (0x2U)
#define ADC_BIST_FIR_SFR_DFORF_SHIFT             (1U)
#define ADC_BIST_FIR_SFR_DFORF_WIDTH             (1U)
#define ADC_BIST_FIR_SFR_DFORF(x)                (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_SFR_DFORF_SHIFT)) & ADC_BIST_FIR_SFR_DFORF_MASK)

#define ADC_BIST_FIR_SFR_CDVF_MASK               (0x4U)
#define ADC_BIST_FIR_SFR_CDVF_SHIFT              (2U)
#define ADC_BIST_FIR_SFR_CDVF_WIDTH              (1U)
#define ADC_BIST_FIR_SFR_CDVF(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_SFR_CDVF_SHIFT)) & ADC_BIST_FIR_SFR_CDVF_MASK)

#define ADC_BIST_FIR_SFR_DFEF_MASK               (0x100U)
#define ADC_BIST_FIR_SFR_DFEF_SHIFT              (8U)
#define ADC_BIST_FIR_SFR_DFEF_WIDTH              (1U)
#define ADC_BIST_FIR_SFR_DFEF(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_SFR_DFEF_SHIFT)) & ADC_BIST_FIR_SFR_DFEF_MASK)
/*! @} */

/*! @name RSER - Request Select and Enable Register */
/*! @{ */

#define ADC_BIST_FIR_RSER_DFFDIRE_MASK           (0x1U)
#define ADC_BIST_FIR_RSER_DFFDIRE_SHIFT          (0U)
#define ADC_BIST_FIR_RSER_DFFDIRE_WIDTH          (1U)
#define ADC_BIST_FIR_RSER_DFFDIRE(x)             (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_RSER_DFFDIRE_SHIFT)) & ADC_BIST_FIR_RSER_DFFDIRE_MASK)

#define ADC_BIST_FIR_RSER_DFORIE_MASK            (0x2U)
#define ADC_BIST_FIR_RSER_DFORIE_SHIFT           (1U)
#define ADC_BIST_FIR_RSER_DFORIE_WIDTH           (1U)
#define ADC_BIST_FIR_RSER_DFORIE(x)              (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_RSER_DFORIE_SHIFT)) & ADC_BIST_FIR_RSER_DFORIE_MASK)

#define ADC_BIST_FIR_RSER_DFFDIRS_MASK           (0x10000U)
#define ADC_BIST_FIR_RSER_DFFDIRS_SHIFT          (16U)
#define ADC_BIST_FIR_RSER_DFFDIRS_WIDTH          (1U)
#define ADC_BIST_FIR_RSER_DFFDIRS(x)             (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_RSER_DFFDIRS_SHIFT)) & ADC_BIST_FIR_RSER_DFFDIRS_MASK)
/*! @} */

/*! @name OSDR - Output Settling Delay Register */
/*! @{ */

#define ADC_BIST_FIR_OSDR_OSD_MASK               (0xFFU)
#define ADC_BIST_FIR_OSDR_OSD_SHIFT              (0U)
#define ADC_BIST_FIR_OSDR_OSD_WIDTH              (8U)
#define ADC_BIST_FIR_OSDR_OSD(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_OSDR_OSD_SHIFT)) & ADC_BIST_FIR_OSDR_OSD_MASK)
/*! @} */

/*! @name FCR - FIFO Control Register */
/*! @{ */

#define ADC_BIST_FIR_FCR_FE_MASK                 (0x1U)
#define ADC_BIST_FIR_FCR_FE_SHIFT                (0U)
#define ADC_BIST_FIR_FCR_FE_WIDTH                (1U)
#define ADC_BIST_FIR_FCR_FE(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_FCR_FE_SHIFT)) & ADC_BIST_FIR_FCR_FE_MASK)

#define ADC_BIST_FIR_FCR_FSIZE_MASK              (0x6U)
#define ADC_BIST_FIR_FCR_FSIZE_SHIFT             (1U)
#define ADC_BIST_FIR_FCR_FSIZE_WIDTH             (2U)
#define ADC_BIST_FIR_FCR_FSIZE(x)                (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_FCR_FSIZE_SHIFT)) & ADC_BIST_FIR_FCR_FSIZE_MASK)

#define ADC_BIST_FIR_FCR_FOWEN_MASK              (0x8U)
#define ADC_BIST_FIR_FCR_FOWEN_SHIFT             (3U)
#define ADC_BIST_FIR_FCR_FOWEN_WIDTH             (1U)
#define ADC_BIST_FIR_FCR_FOWEN(x)                (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_FCR_FOWEN_SHIFT)) & ADC_BIST_FIR_FCR_FOWEN_MASK)

#define ADC_BIST_FIR_FCR_FTHLD_MASK              (0xF00U)
#define ADC_BIST_FIR_FCR_FTHLD_SHIFT             (8U)
#define ADC_BIST_FIR_FCR_FTHLD_WIDTH             (4U)
#define ADC_BIST_FIR_FCR_FTHLD(x)                (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_FCR_FTHLD_SHIFT)) & ADC_BIST_FIR_FCR_FTHLD_MASK)

#define ADC_BIST_FIR_FCR_FRST_MASK               (0x10000U)
#define ADC_BIST_FIR_FCR_FRST_SHIFT              (16U)
#define ADC_BIST_FIR_FCR_FRST_WIDTH              (1U)
#define ADC_BIST_FIR_FCR_FRST(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_FCR_FRST_SHIFT)) & ADC_BIST_FIR_FCR_FRST_MASK)
/*! @} */

/*! @name CDR - Converted Data Register */
/*! @{ */

#define ADC_BIST_FIR_CDR_CDATA_MASK              (0xFFFFU)
#define ADC_BIST_FIR_CDR_CDATA_SHIFT             (0U)
#define ADC_BIST_FIR_CDR_CDATA_WIDTH             (16U)
#define ADC_BIST_FIR_CDR_CDATA(x)                (((uint32_t)(((uint32_t)(x)) << ADC_BIST_FIR_CDR_CDATA_SHIFT)) & ADC_BIST_FIR_CDR_CDATA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ADC_BIST_FIR_Register_Masks */

/*!
 * @}
 */ /* end of group ADC_BIST_FIR_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_ADC_BIST_FIR_H_) */
