/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_SDADC.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_SDADC
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
#if !defined(S32K39_SDADC_H_)  /* Check if memory map has not been already included */
#define S32K39_SDADC_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SDADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDADC_Peripheral_Access_Layer SDADC Peripheral Access Layer
 * @{
 */

/** SDADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration Register, offset: 0x0 */
  __IO uint32_t CSR;                               /**< Channel Selection Register, offset: 0x4 */
  __IO uint32_t RKR;                               /**< Reset Key Register, offset: 0x8 */
  __IO uint32_t SFR;                               /**< Status Flag Register, offset: 0xC */
  __IO uint32_t RSER;                              /**< Request Select and Enable Register, offset: 0x10 */
  __IO uint32_t OSDR;                              /**< Output Settling Delay Register, offset: 0x14 */
  __IO uint32_t FCR;                               /**< FIFO Control Register, offset: 0x18 */
  __IO uint32_t STKR;                              /**< Software Trigger Key Register, offset: 0x1C */
  __I  uint32_t CDR;                               /**< Converted Data Register, offset: 0x20 */
  __IO uint32_t WTHHLR;                            /**< WDG Threshold Register, offset: 0x24 */
  uint8_t RESERVED_0[8];
  __IO uint32_t TCR;                               /**< Test Configuration Register, offset: 0x30 */
} SDADC_Type, *SDADC_MemMapPtr;

/** Number of instances of the SDADC module. */
#define SDADC_INSTANCE_COUNT                     (4u)

/* SDADC - Peripheral instance base addresses */
/** Peripheral SDADC_0 base address */
#define IP_SDADC_0_BASE                          (0x406F4000u)
/** Peripheral SDADC_0 base pointer */
#define IP_SDADC_0                               ((SDADC_Type *)IP_SDADC_0_BASE)
/** Peripheral SDADC_1 base address */
#define IP_SDADC_1_BASE                          (0x406F8000u)
/** Peripheral SDADC_1 base pointer */
#define IP_SDADC_1                               ((SDADC_Type *)IP_SDADC_1_BASE)
/** Peripheral SDADC_2 base address */
#define IP_SDADC_2_BASE                          (0x406FC000u)
/** Peripheral SDADC_2 base pointer */
#define IP_SDADC_2                               ((SDADC_Type *)IP_SDADC_2_BASE)
/** Peripheral SDADC_3 base address */
#define IP_SDADC_3_BASE                          (0x40700000u)
/** Peripheral SDADC_3 base pointer */
#define IP_SDADC_3                               ((SDADC_Type *)IP_SDADC_3_BASE)
/** Array initializer of SDADC peripheral base addresses */
#define IP_SDADC_BASE_ADDRS                      { IP_SDADC_0_BASE, IP_SDADC_1_BASE, IP_SDADC_2_BASE, IP_SDADC_3_BASE }
/** Array initializer of SDADC peripheral base pointers */
#define IP_SDADC_BASE_PTRS                       { IP_SDADC_0, IP_SDADC_1, IP_SDADC_2, IP_SDADC_3 }

/* ----------------------------------------------------------------------------
   -- SDADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDADC_Register_Masks SDADC Register Masks
 * @{
 */

/*! @name MCR - Module Configuration Register */
/*! @{ */

#define SDADC_MCR_EN_MASK                        (0x1U)
#define SDADC_MCR_EN_SHIFT                       (0U)
#define SDADC_MCR_EN_WIDTH                       (1U)
#define SDADC_MCR_EN(x)                          (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_EN_SHIFT)) & SDADC_MCR_EN_MASK)

#define SDADC_MCR_MODE_MASK                      (0x2U)
#define SDADC_MCR_MODE_SHIFT                     (1U)
#define SDADC_MCR_MODE_WIDTH                     (1U)
#define SDADC_MCR_MODE(x)                        (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_MODE_SHIFT)) & SDADC_MCR_MODE_MASK)

#define SDADC_MCR_WRMODE_MASK                    (0x8U)
#define SDADC_MCR_WRMODE_SHIFT                   (3U)
#define SDADC_MCR_WRMODE_WIDTH                   (1U)
#define SDADC_MCR_WRMODE(x)                      (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_WRMODE_SHIFT)) & SDADC_MCR_WRMODE_MASK)

#define SDADC_MCR_VCOMSEL_MASK                   (0x30U)
#define SDADC_MCR_VCOMSEL_SHIFT                  (4U)
#define SDADC_MCR_VCOMSEL_WIDTH                  (2U)
#define SDADC_MCR_VCOMSEL(x)                     (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_VCOMSEL_SHIFT)) & SDADC_MCR_VCOMSEL_MASK)

#define SDADC_MCR_VCOM2EN_MASK                   (0x40U)
#define SDADC_MCR_VCOM2EN_SHIFT                  (6U)
#define SDADC_MCR_VCOM2EN_WIDTH                  (1U)
#define SDADC_MCR_VCOM2EN(x)                     (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_VCOM2EN_SHIFT)) & SDADC_MCR_VCOM2EN_MASK)

#define SDADC_MCR_FRZ_MASK                       (0x80U)
#define SDADC_MCR_FRZ_SHIFT                      (7U)
#define SDADC_MCR_FRZ_WIDTH                      (1U)
#define SDADC_MCR_FRZ(x)                         (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_FRZ_SHIFT)) & SDADC_MCR_FRZ_MASK)

#define SDADC_MCR_TRIGSEL_MASK                   (0xF00U)
#define SDADC_MCR_TRIGSEL_SHIFT                  (8U)
#define SDADC_MCR_TRIGSEL_WIDTH                  (4U)
#define SDADC_MCR_TRIGSEL(x)                     (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_TRIGSEL_SHIFT)) & SDADC_MCR_TRIGSEL_MASK)

#define SDADC_MCR_TRIGEN_MASK                    (0x1000U)
#define SDADC_MCR_TRIGEN_SHIFT                   (12U)
#define SDADC_MCR_TRIGEN_WIDTH                   (1U)
#define SDADC_MCR_TRIGEN(x)                      (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_TRIGEN_SHIFT)) & SDADC_MCR_TRIGEN_MASK)

#define SDADC_MCR_TRIGEDSEL_MASK                 (0x6000U)
#define SDADC_MCR_TRIGEDSEL_SHIFT                (13U)
#define SDADC_MCR_TRIGEDSEL_WIDTH                (2U)
#define SDADC_MCR_TRIGEDSEL(x)                   (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_TRIGEDSEL_SHIFT)) & SDADC_MCR_TRIGEDSEL_MASK)

#define SDADC_MCR_WDGEN_MASK                     (0x8000U)
#define SDADC_MCR_WDGEN_SHIFT                    (15U)
#define SDADC_MCR_WDGEN_WIDTH                    (1U)
#define SDADC_MCR_WDGEN(x)                       (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_WDGEN_SHIFT)) & SDADC_MCR_WDGEN_MASK)

#define SDADC_MCR_EMSEL_MASK                     (0x20000U)
#define SDADC_MCR_EMSEL_SHIFT                    (17U)
#define SDADC_MCR_EMSEL_WIDTH                    (1U)
#define SDADC_MCR_EMSEL(x)                       (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_EMSEL_SHIFT)) & SDADC_MCR_EMSEL_MASK)

#define SDADC_MCR_ODF_MASK                       (0x80000U)
#define SDADC_MCR_ODF_SHIFT                      (19U)
#define SDADC_MCR_ODF_WIDTH                      (1U)
#define SDADC_MCR_ODF(x)                         (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_ODF_SHIFT)) & SDADC_MCR_ODF_MASK)

#define SDADC_MCR_PGAN_MASK                      (0x300000U)
#define SDADC_MCR_PGAN_SHIFT                     (20U)
#define SDADC_MCR_PGAN_WIDTH                     (2U)
#define SDADC_MCR_PGAN(x)                        (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_PGAN_SHIFT)) & SDADC_MCR_PGAN_MASK)

#define SDADC_MCR_PDR_MASK                       (0x1F000000U)
#define SDADC_MCR_PDR_SHIFT                      (24U)
#define SDADC_MCR_PDR_WIDTH                      (5U)
#define SDADC_MCR_PDR(x)                         (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_PDR_SHIFT)) & SDADC_MCR_PDR_MASK)

#define SDADC_MCR_BIASGEN_EN_MASK                (0x80000000U)
#define SDADC_MCR_BIASGEN_EN_SHIFT               (31U)
#define SDADC_MCR_BIASGEN_EN_WIDTH               (1U)
#define SDADC_MCR_BIASGEN_EN(x)                  (((uint32_t)(((uint32_t)(x)) << SDADC_MCR_BIASGEN_EN_SHIFT)) & SDADC_MCR_BIASGEN_EN_MASK)
/*! @} */

/*! @name CSR - Channel Selection Register */
/*! @{ */

#define SDADC_CSR_ANCHSEL_MASK                   (0x7U)
#define SDADC_CSR_ANCHSEL_SHIFT                  (0U)
#define SDADC_CSR_ANCHSEL_WIDTH                  (3U)
#define SDADC_CSR_ANCHSEL(x)                     (((uint32_t)(((uint32_t)(x)) << SDADC_CSR_ANCHSEL_SHIFT)) & SDADC_CSR_ANCHSEL_MASK)

#define SDADC_CSR_ANCHSEL_WRAP_MASK              (0x700U)
#define SDADC_CSR_ANCHSEL_WRAP_SHIFT             (8U)
#define SDADC_CSR_ANCHSEL_WRAP_WIDTH             (3U)
#define SDADC_CSR_ANCHSEL_WRAP(x)                (((uint32_t)(((uint32_t)(x)) << SDADC_CSR_ANCHSEL_WRAP_SHIFT)) & SDADC_CSR_ANCHSEL_WRAP_MASK)

#define SDADC_CSR_BIASEN_MASK                    (0xFF0000U)
#define SDADC_CSR_BIASEN_SHIFT                   (16U)
#define SDADC_CSR_BIASEN_WIDTH                   (8U)
#define SDADC_CSR_BIASEN(x)                      (((uint32_t)(((uint32_t)(x)) << SDADC_CSR_BIASEN_SHIFT)) & SDADC_CSR_BIASEN_MASK)
/*! @} */

/*! @name RKR - Reset Key Register */
/*! @{ */

#define SDADC_RKR_RESET_KEY_MASK                 (0xFFFFU)
#define SDADC_RKR_RESET_KEY_SHIFT                (0U)
#define SDADC_RKR_RESET_KEY_WIDTH                (16U)
#define SDADC_RKR_RESET_KEY(x)                   (((uint32_t)(((uint32_t)(x)) << SDADC_RKR_RESET_KEY_SHIFT)) & SDADC_RKR_RESET_KEY_MASK)
/*! @} */

/*! @name SFR - Status Flag Register */
/*! @{ */

#define SDADC_SFR_DFFF_MASK                      (0x1U)
#define SDADC_SFR_DFFF_SHIFT                     (0U)
#define SDADC_SFR_DFFF_WIDTH                     (1U)
#define SDADC_SFR_DFFF(x)                        (((uint32_t)(((uint32_t)(x)) << SDADC_SFR_DFFF_SHIFT)) & SDADC_SFR_DFFF_MASK)

#define SDADC_SFR_DFORF_MASK                     (0x2U)
#define SDADC_SFR_DFORF_SHIFT                    (1U)
#define SDADC_SFR_DFORF_WIDTH                    (1U)
#define SDADC_SFR_DFORF(x)                       (((uint32_t)(((uint32_t)(x)) << SDADC_SFR_DFORF_SHIFT)) & SDADC_SFR_DFORF_MASK)

#define SDADC_SFR_CDVF_MASK                      (0x4U)
#define SDADC_SFR_CDVF_SHIFT                     (2U)
#define SDADC_SFR_CDVF_WIDTH                     (1U)
#define SDADC_SFR_CDVF(x)                        (((uint32_t)(((uint32_t)(x)) << SDADC_SFR_CDVF_SHIFT)) & SDADC_SFR_CDVF_MASK)

#define SDADC_SFR_WTHL_MASK                      (0x8U)
#define SDADC_SFR_WTHL_SHIFT                     (3U)
#define SDADC_SFR_WTHL_WIDTH                     (1U)
#define SDADC_SFR_WTHL(x)                        (((uint32_t)(((uint32_t)(x)) << SDADC_SFR_WTHL_SHIFT)) & SDADC_SFR_WTHL_MASK)

#define SDADC_SFR_WTHH_MASK                      (0x10U)
#define SDADC_SFR_WTHH_SHIFT                     (4U)
#define SDADC_SFR_WTHH_WIDTH                     (1U)
#define SDADC_SFR_WTHH(x)                        (((uint32_t)(((uint32_t)(x)) << SDADC_SFR_WTHH_SHIFT)) & SDADC_SFR_WTHH_MASK)

#define SDADC_SFR_DFEF_MASK                      (0x100U)
#define SDADC_SFR_DFEF_SHIFT                     (8U)
#define SDADC_SFR_DFEF_WIDTH                     (1U)
#define SDADC_SFR_DFEF(x)                        (((uint32_t)(((uint32_t)(x)) << SDADC_SFR_DFEF_SHIFT)) & SDADC_SFR_DFEF_MASK)

#define SDADC_SFR_ANCHSEL_CNT_MASK               (0x70000U)
#define SDADC_SFR_ANCHSEL_CNT_SHIFT              (16U)
#define SDADC_SFR_ANCHSEL_CNT_WIDTH              (3U)
#define SDADC_SFR_ANCHSEL_CNT(x)                 (((uint32_t)(((uint32_t)(x)) << SDADC_SFR_ANCHSEL_CNT_SHIFT)) & SDADC_SFR_ANCHSEL_CNT_MASK)
/*! @} */

/*! @name RSER - Request Select and Enable Register */
/*! @{ */

#define SDADC_RSER_DFFDIRE_MASK                  (0x1U)
#define SDADC_RSER_DFFDIRE_SHIFT                 (0U)
#define SDADC_RSER_DFFDIRE_WIDTH                 (1U)
#define SDADC_RSER_DFFDIRE(x)                    (((uint32_t)(((uint32_t)(x)) << SDADC_RSER_DFFDIRE_SHIFT)) & SDADC_RSER_DFFDIRE_MASK)

#define SDADC_RSER_DFORIE_MASK                   (0x2U)
#define SDADC_RSER_DFORIE_SHIFT                  (1U)
#define SDADC_RSER_DFORIE_WIDTH                  (1U)
#define SDADC_RSER_DFORIE(x)                     (((uint32_t)(((uint32_t)(x)) << SDADC_RSER_DFORIE_SHIFT)) & SDADC_RSER_DFORIE_MASK)

#define SDADC_RSER_WTHDIRE_MASK                  (0x8U)
#define SDADC_RSER_WTHDIRE_SHIFT                 (3U)
#define SDADC_RSER_WTHDIRE_WIDTH                 (1U)
#define SDADC_RSER_WTHDIRE(x)                    (((uint32_t)(((uint32_t)(x)) << SDADC_RSER_WTHDIRE_SHIFT)) & SDADC_RSER_WTHDIRE_MASK)

#define SDADC_RSER_DFFDIRS_MASK                  (0x10000U)
#define SDADC_RSER_DFFDIRS_SHIFT                 (16U)
#define SDADC_RSER_DFFDIRS_WIDTH                 (1U)
#define SDADC_RSER_DFFDIRS(x)                    (((uint32_t)(((uint32_t)(x)) << SDADC_RSER_DFFDIRS_SHIFT)) & SDADC_RSER_DFFDIRS_MASK)

#define SDADC_RSER_WTHDIRS_MASK                  (0x20000U)
#define SDADC_RSER_WTHDIRS_SHIFT                 (17U)
#define SDADC_RSER_WTHDIRS_WIDTH                 (1U)
#define SDADC_RSER_WTHDIRS(x)                    (((uint32_t)(((uint32_t)(x)) << SDADC_RSER_WTHDIRS_SHIFT)) & SDADC_RSER_WTHDIRS_MASK)
/*! @} */

/*! @name OSDR - Output Settling Delay Register */
/*! @{ */

#define SDADC_OSDR_OSD_MASK                      (0xFFU)
#define SDADC_OSDR_OSD_SHIFT                     (0U)
#define SDADC_OSDR_OSD_WIDTH                     (8U)
#define SDADC_OSDR_OSD(x)                        (((uint32_t)(((uint32_t)(x)) << SDADC_OSDR_OSD_SHIFT)) & SDADC_OSDR_OSD_MASK)
/*! @} */

/*! @name FCR - FIFO Control Register */
/*! @{ */

#define SDADC_FCR_FE_MASK                        (0x1U)
#define SDADC_FCR_FE_SHIFT                       (0U)
#define SDADC_FCR_FE_WIDTH                       (1U)
#define SDADC_FCR_FE(x)                          (((uint32_t)(((uint32_t)(x)) << SDADC_FCR_FE_SHIFT)) & SDADC_FCR_FE_MASK)

#define SDADC_FCR_FSIZE_MASK                     (0x6U)
#define SDADC_FCR_FSIZE_SHIFT                    (1U)
#define SDADC_FCR_FSIZE_WIDTH                    (2U)
#define SDADC_FCR_FSIZE(x)                       (((uint32_t)(((uint32_t)(x)) << SDADC_FCR_FSIZE_SHIFT)) & SDADC_FCR_FSIZE_MASK)

#define SDADC_FCR_FOWEN_MASK                     (0x8U)
#define SDADC_FCR_FOWEN_SHIFT                    (3U)
#define SDADC_FCR_FOWEN_WIDTH                    (1U)
#define SDADC_FCR_FOWEN(x)                       (((uint32_t)(((uint32_t)(x)) << SDADC_FCR_FOWEN_SHIFT)) & SDADC_FCR_FOWEN_MASK)

#define SDADC_FCR_FTHLD_MASK                     (0xF00U)
#define SDADC_FCR_FTHLD_SHIFT                    (8U)
#define SDADC_FCR_FTHLD_WIDTH                    (4U)
#define SDADC_FCR_FTHLD(x)                       (((uint32_t)(((uint32_t)(x)) << SDADC_FCR_FTHLD_SHIFT)) & SDADC_FCR_FTHLD_MASK)

#define SDADC_FCR_FRST_MASK                      (0x10000U)
#define SDADC_FCR_FRST_SHIFT                     (16U)
#define SDADC_FCR_FRST_WIDTH                     (1U)
#define SDADC_FCR_FRST(x)                        (((uint32_t)(((uint32_t)(x)) << SDADC_FCR_FRST_SHIFT)) & SDADC_FCR_FRST_MASK)
/*! @} */

/*! @name STKR - Software Trigger Key Register */
/*! @{ */

#define SDADC_STKR_ST_KEY_MASK                   (0xFFFFU)
#define SDADC_STKR_ST_KEY_SHIFT                  (0U)
#define SDADC_STKR_ST_KEY_WIDTH                  (16U)
#define SDADC_STKR_ST_KEY(x)                     (((uint32_t)(((uint32_t)(x)) << SDADC_STKR_ST_KEY_SHIFT)) & SDADC_STKR_ST_KEY_MASK)
/*! @} */

/*! @name CDR - Converted Data Register */
/*! @{ */

#define SDADC_CDR_CDATA_MASK                     (0xFFFFU)
#define SDADC_CDR_CDATA_SHIFT                    (0U)
#define SDADC_CDR_CDATA_WIDTH                    (16U)
#define SDADC_CDR_CDATA(x)                       (((uint32_t)(((uint32_t)(x)) << SDADC_CDR_CDATA_SHIFT)) & SDADC_CDR_CDATA_MASK)
/*! @} */

/*! @name WTHHLR - WDG Threshold Register */
/*! @{ */

#define SDADC_WTHHLR_THRL_MASK                   (0xFFFFU)
#define SDADC_WTHHLR_THRL_SHIFT                  (0U)
#define SDADC_WTHHLR_THRL_WIDTH                  (16U)
#define SDADC_WTHHLR_THRL(x)                     (((uint32_t)(((uint32_t)(x)) << SDADC_WTHHLR_THRL_SHIFT)) & SDADC_WTHHLR_THRL_MASK)

#define SDADC_WTHHLR_THRH_MASK                   (0xFFFF0000U)
#define SDADC_WTHHLR_THRH_SHIFT                  (16U)
#define SDADC_WTHHLR_THRH_WIDTH                  (16U)
#define SDADC_WTHHLR_THRH(x)                     (((uint32_t)(((uint32_t)(x)) << SDADC_WTHHLR_THRH_SHIFT)) & SDADC_WTHHLR_THRH_MASK)
/*! @} */

/*! @name TCR - Test Configuration Register */
/*! @{ */

#define SDADC_TCR_TEST_EN_MASK                   (0x1U)
#define SDADC_TCR_TEST_EN_SHIFT                  (0U)
#define SDADC_TCR_TEST_EN_WIDTH                  (1U)
#define SDADC_TCR_TEST_EN(x)                     (((uint32_t)(((uint32_t)(x)) << SDADC_TCR_TEST_EN_SHIFT)) & SDADC_TCR_TEST_EN_MASK)

#define SDADC_TCR_TEST_SDADC_EN_MASK             (0x2U)
#define SDADC_TCR_TEST_SDADC_EN_SHIFT            (1U)
#define SDADC_TCR_TEST_SDADC_EN_WIDTH            (1U)
#define SDADC_TCR_TEST_SDADC_EN(x)               (((uint32_t)(((uint32_t)(x)) << SDADC_TCR_TEST_SDADC_EN_SHIFT)) & SDADC_TCR_TEST_SDADC_EN_MASK)

#define SDADC_TCR_TESTMUX_EN_MASK                (0x4U)
#define SDADC_TCR_TESTMUX_EN_SHIFT               (2U)
#define SDADC_TCR_TESTMUX_EN_WIDTH               (1U)
#define SDADC_TCR_TESTMUX_EN(x)                  (((uint32_t)(((uint32_t)(x)) << SDADC_TCR_TESTMUX_EN_SHIFT)) & SDADC_TCR_TESTMUX_EN_MASK)

#define SDADC_TCR_INMUX_EN_MASK                  (0x8U)
#define SDADC_TCR_INMUX_EN_SHIFT                 (3U)
#define SDADC_TCR_INMUX_EN_WIDTH                 (1U)
#define SDADC_TCR_INMUX_EN(x)                    (((uint32_t)(((uint32_t)(x)) << SDADC_TCR_INMUX_EN_SHIFT)) & SDADC_TCR_INMUX_EN_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SDADC_Register_Masks */

/*!
 * @}
 */ /* end of group SDADC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_SDADC_H_) */
