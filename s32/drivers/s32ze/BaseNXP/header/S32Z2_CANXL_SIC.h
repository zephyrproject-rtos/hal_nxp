/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CANXL_SIC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CANXL_SIC
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
#if !defined(S32Z2_CANXL_SIC_H_)  /* Check if memory map has not been already included */
#define S32Z2_CANXL_SIC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CANXL_SIC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CANXL_SIC_Peripheral_Access_Layer CANXL_SIC Peripheral Access Layer
 * @{
 */

/** CANXL_SIC - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[64];
  __IO uint32_t SYSMC;                             /**< System Module Control, offset: 0x40 */
  __IO uint32_t SYSMCFG;                           /**< System Module Configuration, offset: 0x44 */
  __IO uint32_t SYSIE;                             /**< System Interrupt Enable, offset: 0x48 */
  __IO uint32_t SYSS;                              /**< System Status, offset: 0x4C */
  __I  uint32_t SYSFRTL;                           /**< System Free Running Timer Low, offset: 0x50 */
  __I  uint32_t SYSFRTH;                           /**< System Free Running Timer High, offset: 0x54 */
  __IO uint32_t SYSMDHICFG;                        /**< System Message Descriptor Host Interrupt Configuration, offset: 0x58 */
  uint8_t RESERVED_1[36];
  __IO uint32_t BCFG1;                             /**< BCANXL Configuration 1, offset: 0x80 */
  __IO uint32_t BCFG2;                             /**< BCANXL Configuration 2, offset: 0x84 */
  uint8_t RESERVED_2[4];
  __IO uint32_t BBPRS;                             /**< BCANXL Bit Time Quanta Prescaler, offset: 0x8C */
  __IO uint32_t BNCBT;                             /**< BCANXL Nominal Bit Timing, offset: 0x90 */
  __IO uint32_t BFDCBT;                            /**< BCANXL FD Data Phase Bit Timing, offset: 0x94 */
  __IO uint32_t BXDCBT;                            /**< BCANXL XL Data Phase Bit Timing, offset: 0x98 */
  __IO uint32_t BTDCC;                             /**< BCANXL Transceiver Delay Compensation Control, offset: 0x9C */
  __IO uint32_t BMICI;                             /**< BCANXL PWM Configuration, offset: 0xA0 */
} CANXL_SIC_Type, *CANXL_SIC_MemMapPtr;

/** Number of instances of the CANXL_SIC module. */
#define CANXL_SIC_INSTANCE_COUNT                 (2)

/* CANXL_SIC - Peripheral instance base addresses */
/** Peripheral CANXL_0__SIC base address */
#define IP_CANXL_0__SIC_BASE                     (0x4741B000u)
/** Peripheral CANXL_0__SIC base pointer */
#define IP_CANXL_0__SIC                          ((CANXL_SIC_Type *)IP_CANXL_0__SIC_BASE)
/** Peripheral CANXL_1__SIC base address */
#define IP_CANXL_1__SIC_BASE                     (0x4751B000u)
/** Peripheral CANXL_1__SIC base pointer */
#define IP_CANXL_1__SIC                          ((CANXL_SIC_Type *)IP_CANXL_1__SIC_BASE)
/** Array initializer of CANXL_SIC peripheral base addresses */
#define IP_CANXL_SIC_BASE_ADDRS                  { IP_CANXL_0__SIC_BASE, IP_CANXL_1__SIC_BASE }
/** Array initializer of CANXL_SIC peripheral base pointers */
#define IP_CANXL_SIC_BASE_PTRS                   { IP_CANXL_0__SIC, IP_CANXL_1__SIC }

/* ----------------------------------------------------------------------------
   -- CANXL_SIC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CANXL_SIC_Register_Masks CANXL_SIC Register Masks
 * @{
 */

/*! @name SYSMC - System Module Control */
/*! @{ */

#define CANXL_SIC_SYSMC_FRZREQ_MASK              (0x1U)
#define CANXL_SIC_SYSMC_FRZREQ_SHIFT             (0U)
#define CANXL_SIC_SYSMC_FRZREQ_WIDTH             (1U)
#define CANXL_SIC_SYSMC_FRZREQ(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMC_FRZREQ_SHIFT)) & CANXL_SIC_SYSMC_FRZREQ_MASK)

#define CANXL_SIC_SYSMC_LPMREQ_MASK              (0x2U)
#define CANXL_SIC_SYSMC_LPMREQ_SHIFT             (1U)
#define CANXL_SIC_SYSMC_LPMREQ_WIDTH             (1U)
#define CANXL_SIC_SYSMC_LPMREQ(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMC_LPMREQ_SHIFT)) & CANXL_SIC_SYSMC_LPMREQ_MASK)

#define CANXL_SIC_SYSMC_SOFRST_MASK              (0x80000000U)
#define CANXL_SIC_SYSMC_SOFRST_SHIFT             (31U)
#define CANXL_SIC_SYSMC_SOFRST_WIDTH             (1U)
#define CANXL_SIC_SYSMC_SOFRST(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMC_SOFRST_SHIFT)) & CANXL_SIC_SYSMC_SOFRST_MASK)
/*! @} */

/*! @name SYSMCFG - System Module Configuration */
/*! @{ */

#define CANXL_SIC_SYSMCFG_FB1EN_MASK             (0x1U)
#define CANXL_SIC_SYSMCFG_FB1EN_SHIFT            (0U)
#define CANXL_SIC_SYSMCFG_FB1EN_WIDTH            (1U)
#define CANXL_SIC_SYSMCFG_FB1EN(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMCFG_FB1EN_SHIFT)) & CANXL_SIC_SYSMCFG_FB1EN_MASK)

#define CANXL_SIC_SYSMCFG_DRWRDIS_MASK           (0x2U)
#define CANXL_SIC_SYSMCFG_DRWRDIS_SHIFT          (1U)
#define CANXL_SIC_SYSMCFG_DRWRDIS_WIDTH          (1U)
#define CANXL_SIC_SYSMCFG_DRWRDIS(x)             (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMCFG_DRWRDIS_SHIFT)) & CANXL_SIC_SYSMCFG_DRWRDIS_MASK)

#define CANXL_SIC_SYSMCFG_MRP_MASK               (0x8U)
#define CANXL_SIC_SYSMCFG_MRP_SHIFT              (3U)
#define CANXL_SIC_SYSMCFG_MRP_WIDTH              (1U)
#define CANXL_SIC_SYSMCFG_MRP(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMCFG_MRP_SHIFT)) & CANXL_SIC_SYSMCFG_MRP_MASK)

#define CANXL_SIC_SYSMCFG_MAXTXMB_MASK           (0x7F0000U)
#define CANXL_SIC_SYSMCFG_MAXTXMB_SHIFT          (16U)
#define CANXL_SIC_SYSMCFG_MAXTXMB_WIDTH          (7U)
#define CANXL_SIC_SYSMCFG_MAXTXMB(x)             (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMCFG_MAXTXMB_SHIFT)) & CANXL_SIC_SYSMCFG_MAXTXMB_MASK)

#define CANXL_SIC_SYSMCFG_MAXRXMB_MASK           (0x7F000000U)
#define CANXL_SIC_SYSMCFG_MAXRXMB_SHIFT          (24U)
#define CANXL_SIC_SYSMCFG_MAXRXMB_WIDTH          (7U)
#define CANXL_SIC_SYSMCFG_MAXRXMB(x)             (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMCFG_MAXRXMB_SHIFT)) & CANXL_SIC_SYSMCFG_MAXRXMB_MASK)
/*! @} */

/*! @name SYSIE - System Interrupt Enable */
/*! @{ */

#define CANXL_SIC_SYSIE_FRZACKIE_MASK            (0x1U)
#define CANXL_SIC_SYSIE_FRZACKIE_SHIFT           (0U)
#define CANXL_SIC_SYSIE_FRZACKIE_WIDTH           (1U)
#define CANXL_SIC_SYSIE_FRZACKIE(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_FRZACKIE_SHIFT)) & CANXL_SIC_SYSIE_FRZACKIE_MASK)

#define CANXL_SIC_SYSIE_LPMACKIE_MASK            (0x2U)
#define CANXL_SIC_SYSIE_LPMACKIE_SHIFT           (1U)
#define CANXL_SIC_SYSIE_LPMACKIE_WIDTH           (1U)
#define CANXL_SIC_SYSIE_LPMACKIE(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_LPMACKIE_SHIFT)) & CANXL_SIC_SYSIE_LPMACKIE_MASK)

#define CANXL_SIC_SYSIE_IERRIE_MASK              (0xF00U)
#define CANXL_SIC_SYSIE_IERRIE_SHIFT             (8U)
#define CANXL_SIC_SYSIE_IERRIE_WIDTH             (4U)
#define CANXL_SIC_SYSIE_IERRIE(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_IERRIE_SHIFT)) & CANXL_SIC_SYSIE_IERRIE_MASK)

#define CANXL_SIC_SYSIE_CERRIE_MASK              (0x10000U)
#define CANXL_SIC_SYSIE_CERRIE_SHIFT             (16U)
#define CANXL_SIC_SYSIE_CERRIE_WIDTH             (1U)
#define CANXL_SIC_SYSIE_CERRIE(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CERRIE_SHIFT)) & CANXL_SIC_SYSIE_CERRIE_MASK)

#define CANXL_SIC_SYSIE_CPERRIE_MASK             (0x20000U)
#define CANXL_SIC_SYSIE_CPERRIE_SHIFT            (17U)
#define CANXL_SIC_SYSIE_CPERRIE_WIDTH            (1U)
#define CANXL_SIC_SYSIE_CPERRIE(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CPERRIE_SHIFT)) & CANXL_SIC_SYSIE_CPERRIE_MASK)

#define CANXL_SIC_SYSIE_CBOFFIE_MASK             (0x40000U)
#define CANXL_SIC_SYSIE_CBOFFIE_SHIFT            (18U)
#define CANXL_SIC_SYSIE_CBOFFIE_WIDTH            (1U)
#define CANXL_SIC_SYSIE_CBOFFIE(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CBOFFIE_SHIFT)) & CANXL_SIC_SYSIE_CBOFFIE_MASK)

#define CANXL_SIC_SYSIE_CBDONEIE_MASK            (0x80000U)
#define CANXL_SIC_SYSIE_CBDONEIE_SHIFT           (19U)
#define CANXL_SIC_SYSIE_CBDONEIE_WIDTH           (1U)
#define CANXL_SIC_SYSIE_CBDONEIE(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CBDONEIE_SHIFT)) & CANXL_SIC_SYSIE_CBDONEIE_MASK)

#define CANXL_SIC_SYSIE_CRXWRNIE_MASK            (0x100000U)
#define CANXL_SIC_SYSIE_CRXWRNIE_SHIFT           (20U)
#define CANXL_SIC_SYSIE_CRXWRNIE_WIDTH           (1U)
#define CANXL_SIC_SYSIE_CRXWRNIE(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CRXWRNIE_SHIFT)) & CANXL_SIC_SYSIE_CRXWRNIE_MASK)

#define CANXL_SIC_SYSIE_CTXWRNIE_MASK            (0x200000U)
#define CANXL_SIC_SYSIE_CTXWRNIE_SHIFT           (21U)
#define CANXL_SIC_SYSIE_CTXWRNIE_WIDTH           (1U)
#define CANXL_SIC_SYSIE_CTXWRNIE(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CTXWRNIE_SHIFT)) & CANXL_SIC_SYSIE_CTXWRNIE_MASK)

#define CANXL_SIC_SYSIE_CFDPERRIE_MASK           (0x400000U)
#define CANXL_SIC_SYSIE_CFDPERRIE_SHIFT          (22U)
#define CANXL_SIC_SYSIE_CFDPERRIE_WIDTH          (1U)
#define CANXL_SIC_SYSIE_CFDPERRIE(x)             (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CFDPERRIE_SHIFT)) & CANXL_SIC_SYSIE_CFDPERRIE_MASK)

#define CANXL_SIC_SYSIE_CPREXCIE_MASK            (0x800000U)
#define CANXL_SIC_SYSIE_CPREXCIE_SHIFT           (23U)
#define CANXL_SIC_SYSIE_CPREXCIE_WIDTH           (1U)
#define CANXL_SIC_SYSIE_CPREXCIE(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CPREXCIE_SHIFT)) & CANXL_SIC_SYSIE_CPREXCIE_MASK)

#define CANXL_SIC_SYSIE_CDPERRIE_MASK            (0x1000000U)
#define CANXL_SIC_SYSIE_CDPERRIE_SHIFT           (24U)
#define CANXL_SIC_SYSIE_CDPERRIE_WIDTH           (1U)
#define CANXL_SIC_SYSIE_CDPERRIE(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CDPERRIE_SHIFT)) & CANXL_SIC_SYSIE_CDPERRIE_MASK)

#define CANXL_SIC_SYSIE_CTFUERRIR_MASK           (0x2000000U)
#define CANXL_SIC_SYSIE_CTFUERRIR_SHIFT          (25U)
#define CANXL_SIC_SYSIE_CTFUERRIR_WIDTH          (1U)
#define CANXL_SIC_SYSIE_CTFUERRIR(x)             (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CTFUERRIR_SHIFT)) & CANXL_SIC_SYSIE_CTFUERRIR_MASK)

#define CANXL_SIC_SYSIE_CRFOERRIR_MASK           (0x4000000U)
#define CANXL_SIC_SYSIE_CRFOERRIR_SHIFT          (26U)
#define CANXL_SIC_SYSIE_CRFOERRIR_WIDTH          (1U)
#define CANXL_SIC_SYSIE_CRFOERRIR(x)             (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CRFOERRIR_SHIFT)) & CANXL_SIC_SYSIE_CRFOERRIR_MASK)

#define CANXL_SIC_SYSIE_CLSERRIE_MASK            (0x8000000U)
#define CANXL_SIC_SYSIE_CLSERRIE_SHIFT           (27U)
#define CANXL_SIC_SYSIE_CLSERRIE_WIDTH           (1U)
#define CANXL_SIC_SYSIE_CLSERRIE(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CLSERRIE_SHIFT)) & CANXL_SIC_SYSIE_CLSERRIE_MASK)

#define CANXL_SIC_SYSIE_CMDOERRIE_MASK           (0x10000000U)
#define CANXL_SIC_SYSIE_CMDOERRIE_SHIFT          (28U)
#define CANXL_SIC_SYSIE_CMDOERRIE_WIDTH          (1U)
#define CANXL_SIC_SYSIE_CMDOERRIE(x)             (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CMDOERRIE_SHIFT)) & CANXL_SIC_SYSIE_CMDOERRIE_MASK)

#define CANXL_SIC_SYSIE_CMDUERRIE_MASK           (0x20000000U)
#define CANXL_SIC_SYSIE_CMDUERRIE_SHIFT          (29U)
#define CANXL_SIC_SYSIE_CMDUERRIE_WIDTH          (1U)
#define CANXL_SIC_SYSIE_CMDUERRIE(x)             (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CMDUERRIE_SHIFT)) & CANXL_SIC_SYSIE_CMDUERRIE_MASK)

#define CANXL_SIC_SYSIE_CRXSOERRIE_MASK          (0x40000000U)
#define CANXL_SIC_SYSIE_CRXSOERRIE_SHIFT         (30U)
#define CANXL_SIC_SYSIE_CRXSOERRIE_WIDTH         (1U)
#define CANXL_SIC_SYSIE_CRXSOERRIE(x)            (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSIE_CRXSOERRIE_SHIFT)) & CANXL_SIC_SYSIE_CRXSOERRIE_MASK)
/*! @} */

/*! @name SYSS - System Status */
/*! @{ */

#define CANXL_SIC_SYSS_FRZACKF_MASK              (0x1U)
#define CANXL_SIC_SYSS_FRZACKF_SHIFT             (0U)
#define CANXL_SIC_SYSS_FRZACKF_WIDTH             (1U)
#define CANXL_SIC_SYSS_FRZACKF(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_FRZACKF_SHIFT)) & CANXL_SIC_SYSS_FRZACKF_MASK)

#define CANXL_SIC_SYSS_LPMACKF_MASK              (0x2U)
#define CANXL_SIC_SYSS_LPMACKF_SHIFT             (1U)
#define CANXL_SIC_SYSS_LPMACKF_WIDTH             (1U)
#define CANXL_SIC_SYSS_LPMACKF(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_LPMACKF_SHIFT)) & CANXL_SIC_SYSS_LPMACKF_MASK)

#define CANXL_SIC_SYSS_NTRDY_MASK                (0x4U)
#define CANXL_SIC_SYSS_NTRDY_SHIFT               (2U)
#define CANXL_SIC_SYSS_NTRDY_WIDTH               (1U)
#define CANXL_SIC_SYSS_NTRDY(x)                  (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_NTRDY_SHIFT)) & CANXL_SIC_SYSS_NTRDY_MASK)

#define CANXL_SIC_SYSS_IERR_MASK                 (0xF00U)
#define CANXL_SIC_SYSS_IERR_SHIFT                (8U)
#define CANXL_SIC_SYSS_IERR_WIDTH                (4U)
#define CANXL_SIC_SYSS_IERR(x)                   (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_IERR_SHIFT)) & CANXL_SIC_SYSS_IERR_MASK)

#define CANXL_SIC_SYSS_CERR_MASK                 (0x10000U)
#define CANXL_SIC_SYSS_CERR_SHIFT                (16U)
#define CANXL_SIC_SYSS_CERR_WIDTH                (1U)
#define CANXL_SIC_SYSS_CERR(x)                   (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CERR_SHIFT)) & CANXL_SIC_SYSS_CERR_MASK)

#define CANXL_SIC_SYSS_CPASERR_MASK              (0x20000U)
#define CANXL_SIC_SYSS_CPASERR_SHIFT             (17U)
#define CANXL_SIC_SYSS_CPASERR_WIDTH             (1U)
#define CANXL_SIC_SYSS_CPASERR(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CPASERR_SHIFT)) & CANXL_SIC_SYSS_CPASERR_MASK)

#define CANXL_SIC_SYSS_CBOFF_MASK                (0x40000U)
#define CANXL_SIC_SYSS_CBOFF_SHIFT               (18U)
#define CANXL_SIC_SYSS_CBOFF_WIDTH               (1U)
#define CANXL_SIC_SYSS_CBOFF(x)                  (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CBOFF_SHIFT)) & CANXL_SIC_SYSS_CBOFF_MASK)

#define CANXL_SIC_SYSS_CBDONE_MASK               (0x80000U)
#define CANXL_SIC_SYSS_CBDONE_SHIFT              (19U)
#define CANXL_SIC_SYSS_CBDONE_WIDTH              (1U)
#define CANXL_SIC_SYSS_CBDONE(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CBDONE_SHIFT)) & CANXL_SIC_SYSS_CBDONE_MASK)

#define CANXL_SIC_SYSS_CRXWRN_MASK               (0x100000U)
#define CANXL_SIC_SYSS_CRXWRN_SHIFT              (20U)
#define CANXL_SIC_SYSS_CRXWRN_WIDTH              (1U)
#define CANXL_SIC_SYSS_CRXWRN(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CRXWRN_SHIFT)) & CANXL_SIC_SYSS_CRXWRN_MASK)

#define CANXL_SIC_SYSS_CTXWRN_MASK               (0x200000U)
#define CANXL_SIC_SYSS_CTXWRN_SHIFT              (21U)
#define CANXL_SIC_SYSS_CTXWRN_WIDTH              (1U)
#define CANXL_SIC_SYSS_CTXWRN(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CTXWRN_SHIFT)) & CANXL_SIC_SYSS_CTXWRN_MASK)

#define CANXL_SIC_SYSS_CFDPERR_MASK              (0x400000U)
#define CANXL_SIC_SYSS_CFDPERR_SHIFT             (22U)
#define CANXL_SIC_SYSS_CFDPERR_WIDTH             (1U)
#define CANXL_SIC_SYSS_CFDPERR(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CFDPERR_SHIFT)) & CANXL_SIC_SYSS_CFDPERR_MASK)

#define CANXL_SIC_SYSS_CPREXC_MASK               (0x800000U)
#define CANXL_SIC_SYSS_CPREXC_SHIFT              (23U)
#define CANXL_SIC_SYSS_CPREXC_WIDTH              (1U)
#define CANXL_SIC_SYSS_CPREXC(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CPREXC_SHIFT)) & CANXL_SIC_SYSS_CPREXC_MASK)

#define CANXL_SIC_SYSS_CXDPERR_MASK              (0x1000000U)
#define CANXL_SIC_SYSS_CXDPERR_SHIFT             (24U)
#define CANXL_SIC_SYSS_CXDPERR_WIDTH             (1U)
#define CANXL_SIC_SYSS_CXDPERR(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CXDPERR_SHIFT)) & CANXL_SIC_SYSS_CXDPERR_MASK)

#define CANXL_SIC_SYSS_CTFUFLW_MASK              (0x2000000U)
#define CANXL_SIC_SYSS_CTFUFLW_SHIFT             (25U)
#define CANXL_SIC_SYSS_CTFUFLW_WIDTH             (1U)
#define CANXL_SIC_SYSS_CTFUFLW(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CTFUFLW_SHIFT)) & CANXL_SIC_SYSS_CTFUFLW_MASK)

#define CANXL_SIC_SYSS_CRFOVR_MASK               (0x4000000U)
#define CANXL_SIC_SYSS_CRFOVR_SHIFT              (26U)
#define CANXL_SIC_SYSS_CRFOVR_WIDTH              (1U)
#define CANXL_SIC_SYSS_CRFOVR(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CRFOVR_SHIFT)) & CANXL_SIC_SYSS_CRFOVR_MASK)

#define CANXL_SIC_SYSS_CLOMSERR_MASK             (0x8000000U)
#define CANXL_SIC_SYSS_CLOMSERR_SHIFT            (27U)
#define CANXL_SIC_SYSS_CLOMSERR_WIDTH            (1U)
#define CANXL_SIC_SYSS_CLOMSERR(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CLOMSERR_SHIFT)) & CANXL_SIC_SYSS_CLOMSERR_MASK)

#define CANXL_SIC_SYSS_CMDOERR_MASK              (0x10000000U)
#define CANXL_SIC_SYSS_CMDOERR_SHIFT             (28U)
#define CANXL_SIC_SYSS_CMDOERR_WIDTH             (1U)
#define CANXL_SIC_SYSS_CMDOERR(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CMDOERR_SHIFT)) & CANXL_SIC_SYSS_CMDOERR_MASK)

#define CANXL_SIC_SYSS_CMDUERR_MASK              (0x20000000U)
#define CANXL_SIC_SYSS_CMDUERR_SHIFT             (29U)
#define CANXL_SIC_SYSS_CMDUERR_WIDTH             (1U)
#define CANXL_SIC_SYSS_CMDUERR(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CMDUERR_SHIFT)) & CANXL_SIC_SYSS_CMDUERR_MASK)

#define CANXL_SIC_SYSS_CRXOERR_MASK              (0x40000000U)
#define CANXL_SIC_SYSS_CRXOERR_SHIFT             (30U)
#define CANXL_SIC_SYSS_CRXOERR_WIDTH             (1U)
#define CANXL_SIC_SYSS_CRXOERR(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSS_CRXOERR_SHIFT)) & CANXL_SIC_SYSS_CRXOERR_MASK)
/*! @} */

/*! @name SYSFRTL - System Free Running Timer Low */
/*! @{ */

#define CANXL_SIC_SYSFRTL_FRTL_MASK              (0xFFFFFFFFU)
#define CANXL_SIC_SYSFRTL_FRTL_SHIFT             (0U)
#define CANXL_SIC_SYSFRTL_FRTL_WIDTH             (32U)
#define CANXL_SIC_SYSFRTL_FRTL(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSFRTL_FRTL_SHIFT)) & CANXL_SIC_SYSFRTL_FRTL_MASK)
/*! @} */

/*! @name SYSFRTH - System Free Running Timer High */
/*! @{ */

#define CANXL_SIC_SYSFRTH_FRTH_MASK              (0xFFFFFFFFU)
#define CANXL_SIC_SYSFRTH_FRTH_SHIFT             (0U)
#define CANXL_SIC_SYSFRTH_FRTH_WIDTH             (32U)
#define CANXL_SIC_SYSFRTH_FRTH(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSFRTH_FRTH_SHIFT)) & CANXL_SIC_SYSFRTH_FRTH_MASK)
/*! @} */

/*! @name SYSMDHICFG - System Message Descriptor Host Interrupt Configuration */
/*! @{ */

#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_0_MASK    (0x1U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_0_SHIFT   (0U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_0_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_0(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_TXDCFGHI0_0_SHIFT)) & CANXL_SIC_SYSMDHICFG_TXDCFGHI0_0_MASK)

#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_1_MASK    (0x2U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_1_SHIFT   (1U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_1_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_1(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_TXDCFGHI0_1_SHIFT)) & CANXL_SIC_SYSMDHICFG_TXDCFGHI0_1_MASK)

#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_2_MASK    (0x4U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_2_SHIFT   (2U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_2_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_2(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_TXDCFGHI0_2_SHIFT)) & CANXL_SIC_SYSMDHICFG_TXDCFGHI0_2_MASK)

#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_3_MASK    (0x8U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_3_SHIFT   (3U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_3_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI0_3(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_TXDCFGHI0_3_SHIFT)) & CANXL_SIC_SYSMDHICFG_TXDCFGHI0_3_MASK)

#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_0_MASK    (0x100U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_0_SHIFT   (8U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_0_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_0(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_TXDCFGHI1_0_SHIFT)) & CANXL_SIC_SYSMDHICFG_TXDCFGHI1_0_MASK)

#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_1_MASK    (0x200U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_1_SHIFT   (9U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_1_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_1(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_TXDCFGHI1_1_SHIFT)) & CANXL_SIC_SYSMDHICFG_TXDCFGHI1_1_MASK)

#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_2_MASK    (0x400U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_2_SHIFT   (10U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_2_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_2(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_TXDCFGHI1_2_SHIFT)) & CANXL_SIC_SYSMDHICFG_TXDCFGHI1_2_MASK)

#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_3_MASK    (0x800U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_3_SHIFT   (11U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_3_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_TXDCFGHI1_3(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_TXDCFGHI1_3_SHIFT)) & CANXL_SIC_SYSMDHICFG_TXDCFGHI1_3_MASK)

#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_0_MASK    (0x10000U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_0_SHIFT   (16U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_0_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_0(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_RXDCFGHI0_0_SHIFT)) & CANXL_SIC_SYSMDHICFG_RXDCFGHI0_0_MASK)

#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_1_MASK    (0x20000U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_1_SHIFT   (17U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_1_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_1(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_RXDCFGHI0_1_SHIFT)) & CANXL_SIC_SYSMDHICFG_RXDCFGHI0_1_MASK)

#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_2_MASK    (0x40000U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_2_SHIFT   (18U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_2_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_2(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_RXDCFGHI0_2_SHIFT)) & CANXL_SIC_SYSMDHICFG_RXDCFGHI0_2_MASK)

#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_3_MASK    (0x80000U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_3_SHIFT   (19U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_3_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI0_3(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_RXDCFGHI0_3_SHIFT)) & CANXL_SIC_SYSMDHICFG_RXDCFGHI0_3_MASK)

#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_0_MASK    (0x1000000U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_0_SHIFT   (24U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_0_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_0(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_RXDCFGHI1_0_SHIFT)) & CANXL_SIC_SYSMDHICFG_RXDCFGHI1_0_MASK)

#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_1_MASK    (0x2000000U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_1_SHIFT   (25U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_1_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_1(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_RXDCFGHI1_1_SHIFT)) & CANXL_SIC_SYSMDHICFG_RXDCFGHI1_1_MASK)

#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_2_MASK    (0x4000000U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_2_SHIFT   (26U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_2_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_2(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_RXDCFGHI1_2_SHIFT)) & CANXL_SIC_SYSMDHICFG_RXDCFGHI1_2_MASK)

#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_3_MASK    (0x8000000U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_3_SHIFT   (27U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_3_WIDTH   (1U)
#define CANXL_SIC_SYSMDHICFG_RXDCFGHI1_3(x)      (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_SYSMDHICFG_RXDCFGHI1_3_SHIFT)) & CANXL_SIC_SYSMDHICFG_RXDCFGHI1_3_MASK)
/*! @} */

/*! @name BCFG1 - BCANXL Configuration 1 */
/*! @{ */

#define CANXL_SIC_BCFG1_ABRDIS_MASK              (0x1U)
#define CANXL_SIC_BCFG1_ABRDIS_SHIFT             (0U)
#define CANXL_SIC_BCFG1_ABRDIS_WIDTH             (1U)
#define CANXL_SIC_BCFG1_ABRDIS(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG1_ABRDIS_SHIFT)) & CANXL_SIC_BCFG1_ABRDIS_MASK)

#define CANXL_SIC_BCFG1_FDRSDIS_MASK             (0x2U)
#define CANXL_SIC_BCFG1_FDRSDIS_SHIFT            (1U)
#define CANXL_SIC_BCFG1_FDRSDIS_WIDTH            (1U)
#define CANXL_SIC_BCFG1_FDRSDIS(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG1_FDRSDIS_SHIFT)) & CANXL_SIC_BCFG1_FDRSDIS_MASK)
/*! @} */

/*! @name BCFG2 - BCANXL Configuration 2 */
/*! @{ */

#define CANXL_SIC_BCFG2_LPB_MASK                 (0x1U)
#define CANXL_SIC_BCFG2_LPB_SHIFT                (0U)
#define CANXL_SIC_BCFG2_LPB_WIDTH                (1U)
#define CANXL_SIC_BCFG2_LPB(x)                   (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG2_LPB_SHIFT)) & CANXL_SIC_BCFG2_LPB_MASK)

#define CANXL_SIC_BCFG2_LOM_MASK                 (0x2U)
#define CANXL_SIC_BCFG2_LOM_SHIFT                (1U)
#define CANXL_SIC_BCFG2_LOM_WIDTH                (1U)
#define CANXL_SIC_BCFG2_LOM(x)                   (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG2_LOM_SHIFT)) & CANXL_SIC_BCFG2_LOM_MASK)

#define CANXL_SIC_BCFG2_TSCAP_MASK               (0xCU)
#define CANXL_SIC_BCFG2_TSCAP_SHIFT              (2U)
#define CANXL_SIC_BCFG2_TSCAP_WIDTH              (2U)
#define CANXL_SIC_BCFG2_TSCAP(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG2_TSCAP_SHIFT)) & CANXL_SIC_BCFG2_TSCAP_MASK)

#define CANXL_SIC_BCFG2_SRXEN_MASK               (0x10U)
#define CANXL_SIC_BCFG2_SRXEN_SHIFT              (4U)
#define CANXL_SIC_BCFG2_SRXEN_WIDTH              (1U)
#define CANXL_SIC_BCFG2_SRXEN(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG2_SRXEN_SHIFT)) & CANXL_SIC_BCFG2_SRXEN_MASK)

#define CANXL_SIC_BCFG2_FDEN_MASK                (0x20U)
#define CANXL_SIC_BCFG2_FDEN_SHIFT               (5U)
#define CANXL_SIC_BCFG2_FDEN_WIDTH               (1U)
#define CANXL_SIC_BCFG2_FDEN(x)                  (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG2_FDEN_SHIFT)) & CANXL_SIC_BCFG2_FDEN_MASK)

#define CANXL_SIC_BCFG2_PEXCE_MASK               (0x40U)
#define CANXL_SIC_BCFG2_PEXCE_SHIFT              (6U)
#define CANXL_SIC_BCFG2_PEXCE_WIDTH              (1U)
#define CANXL_SIC_BCFG2_PEXCE(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG2_PEXCE_SHIFT)) & CANXL_SIC_BCFG2_PEXCE_MASK)

#define CANXL_SIC_BCFG2_EDFLTDIS_MASK            (0x80U)
#define CANXL_SIC_BCFG2_EDFLTDIS_SHIFT           (7U)
#define CANXL_SIC_BCFG2_EDFLTDIS_WIDTH           (1U)
#define CANXL_SIC_BCFG2_EDFLTDIS(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG2_EDFLTDIS_SHIFT)) & CANXL_SIC_BCFG2_EDFLTDIS_MASK)

#define CANXL_SIC_BCFG2_ROM_MASK                 (0x100U)
#define CANXL_SIC_BCFG2_ROM_SHIFT                (8U)
#define CANXL_SIC_BCFG2_ROM_WIDTH                (1U)
#define CANXL_SIC_BCFG2_ROM(x)                   (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG2_ROM_SHIFT)) & CANXL_SIC_BCFG2_ROM_MASK)

#define CANXL_SIC_BCFG2_XLEN_MASK                (0x200U)
#define CANXL_SIC_BCFG2_XLEN_SHIFT               (9U)
#define CANXL_SIC_BCFG2_XLEN_WIDTH               (1U)
#define CANXL_SIC_BCFG2_XLEN(x)                  (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG2_XLEN_SHIFT)) & CANXL_SIC_BCFG2_XLEN_MASK)

#define CANXL_SIC_BCFG2_XLER_MASK                (0x400U)
#define CANXL_SIC_BCFG2_XLER_SHIFT               (10U)
#define CANXL_SIC_BCFG2_XLER_WIDTH               (1U)
#define CANXL_SIC_BCFG2_XLER(x)                  (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG2_XLER_SHIFT)) & CANXL_SIC_BCFG2_XLER_MASK)

#define CANXL_SIC_BCFG2_TMSE_MASK                (0x800U)
#define CANXL_SIC_BCFG2_TMSE_SHIFT               (11U)
#define CANXL_SIC_BCFG2_TMSE_WIDTH               (1U)
#define CANXL_SIC_BCFG2_TMSE(x)                  (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG2_TMSE_SHIFT)) & CANXL_SIC_BCFG2_TMSE_MASK)

#define CANXL_SIC_BCFG2_TFER_MASK                (0x1000U)
#define CANXL_SIC_BCFG2_TFER_SHIFT               (12U)
#define CANXL_SIC_BCFG2_TFER_WIDTH               (1U)
#define CANXL_SIC_BCFG2_TFER(x)                  (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG2_TFER_SHIFT)) & CANXL_SIC_BCFG2_TFER_MASK)

#define CANXL_SIC_BCFG2_TSS_MASK                 (0x2000U)
#define CANXL_SIC_BCFG2_TSS_SHIFT                (13U)
#define CANXL_SIC_BCFG2_TSS_WIDTH                (1U)
#define CANXL_SIC_BCFG2_TSS(x)                   (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG2_TSS_SHIFT)) & CANXL_SIC_BCFG2_TSS_MASK)

#define CANXL_SIC_BCFG2_FPES_MASK                (0x20000000U)
#define CANXL_SIC_BCFG2_FPES_SHIFT               (29U)
#define CANXL_SIC_BCFG2_FPES_WIDTH               (1U)
#define CANXL_SIC_BCFG2_FPES(x)                  (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BCFG2_FPES_SHIFT)) & CANXL_SIC_BCFG2_FPES_MASK)
/*! @} */

/*! @name BBPRS - BCANXL Bit Time Quanta Prescaler */
/*! @{ */

#define CANXL_SIC_BBPRS_PRESDIV_MASK             (0xFFU)
#define CANXL_SIC_BBPRS_PRESDIV_SHIFT            (0U)
#define CANXL_SIC_BBPRS_PRESDIV_WIDTH            (8U)
#define CANXL_SIC_BBPRS_PRESDIV(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BBPRS_PRESDIV_SHIFT)) & CANXL_SIC_BBPRS_PRESDIV_MASK)
/*! @} */

/*! @name BNCBT - BCANXL Nominal Bit Timing */
/*! @{ */

#define CANXL_SIC_BNCBT_NTSEG1_MASK              (0x1FFU)
#define CANXL_SIC_BNCBT_NTSEG1_SHIFT             (0U)
#define CANXL_SIC_BNCBT_NTSEG1_WIDTH             (9U)
#define CANXL_SIC_BNCBT_NTSEG1(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BNCBT_NTSEG1_SHIFT)) & CANXL_SIC_BNCBT_NTSEG1_MASK)

#define CANXL_SIC_BNCBT_NTSEG2_MASK              (0x7F000U)
#define CANXL_SIC_BNCBT_NTSEG2_SHIFT             (12U)
#define CANXL_SIC_BNCBT_NTSEG2_WIDTH             (7U)
#define CANXL_SIC_BNCBT_NTSEG2(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BNCBT_NTSEG2_SHIFT)) & CANXL_SIC_BNCBT_NTSEG2_MASK)

#define CANXL_SIC_BNCBT_NRJW_MASK                (0x1FC00000U)
#define CANXL_SIC_BNCBT_NRJW_SHIFT               (22U)
#define CANXL_SIC_BNCBT_NRJW_WIDTH               (7U)
#define CANXL_SIC_BNCBT_NRJW(x)                  (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BNCBT_NRJW_SHIFT)) & CANXL_SIC_BNCBT_NRJW_MASK)
/*! @} */

/*! @name BFDCBT - BCANXL FD Data Phase Bit Timing */
/*! @{ */

#define CANXL_SIC_BFDCBT_FTSEG1_MASK             (0xFFU)
#define CANXL_SIC_BFDCBT_FTSEG1_SHIFT            (0U)
#define CANXL_SIC_BFDCBT_FTSEG1_WIDTH            (8U)
#define CANXL_SIC_BFDCBT_FTSEG1(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BFDCBT_FTSEG1_SHIFT)) & CANXL_SIC_BFDCBT_FTSEG1_MASK)

#define CANXL_SIC_BFDCBT_FTSEG2_MASK             (0x7F000U)
#define CANXL_SIC_BFDCBT_FTSEG2_SHIFT            (12U)
#define CANXL_SIC_BFDCBT_FTSEG2_WIDTH            (7U)
#define CANXL_SIC_BFDCBT_FTSEG2(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BFDCBT_FTSEG2_SHIFT)) & CANXL_SIC_BFDCBT_FTSEG2_MASK)

#define CANXL_SIC_BFDCBT_FRJW_MASK               (0x1FC00000U)
#define CANXL_SIC_BFDCBT_FRJW_SHIFT              (22U)
#define CANXL_SIC_BFDCBT_FRJW_WIDTH              (7U)
#define CANXL_SIC_BFDCBT_FRJW(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BFDCBT_FRJW_SHIFT)) & CANXL_SIC_BFDCBT_FRJW_MASK)
/*! @} */

/*! @name BXDCBT - BCANXL XL Data Phase Bit Timing */
/*! @{ */

#define CANXL_SIC_BXDCBT_XTSEG1_MASK             (0xFFU)
#define CANXL_SIC_BXDCBT_XTSEG1_SHIFT            (0U)
#define CANXL_SIC_BXDCBT_XTSEG1_WIDTH            (8U)
#define CANXL_SIC_BXDCBT_XTSEG1(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BXDCBT_XTSEG1_SHIFT)) & CANXL_SIC_BXDCBT_XTSEG1_MASK)

#define CANXL_SIC_BXDCBT_XTSEG2_MASK             (0x7F000U)
#define CANXL_SIC_BXDCBT_XTSEG2_SHIFT            (12U)
#define CANXL_SIC_BXDCBT_XTSEG2_WIDTH            (7U)
#define CANXL_SIC_BXDCBT_XTSEG2(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BXDCBT_XTSEG2_SHIFT)) & CANXL_SIC_BXDCBT_XTSEG2_MASK)

#define CANXL_SIC_BXDCBT_XRJW_MASK               (0x1FC00000U)
#define CANXL_SIC_BXDCBT_XRJW_SHIFT              (22U)
#define CANXL_SIC_BXDCBT_XRJW_WIDTH              (7U)
#define CANXL_SIC_BXDCBT_XRJW(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BXDCBT_XRJW_SHIFT)) & CANXL_SIC_BXDCBT_XRJW_MASK)
/*! @} */

/*! @name BTDCC - BCANXL Transceiver Delay Compensation Control */
/*! @{ */

#define CANXL_SIC_BTDCC_FTDCOFF_MASK             (0x7FU)
#define CANXL_SIC_BTDCC_FTDCOFF_SHIFT            (0U)
#define CANXL_SIC_BTDCC_FTDCOFF_WIDTH            (7U)
#define CANXL_SIC_BTDCC_FTDCOFF(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BTDCC_FTDCOFF_SHIFT)) & CANXL_SIC_BTDCC_FTDCOFF_MASK)

#define CANXL_SIC_BTDCC_FTDMDIS_MASK             (0x4000U)
#define CANXL_SIC_BTDCC_FTDMDIS_SHIFT            (14U)
#define CANXL_SIC_BTDCC_FTDMDIS_WIDTH            (1U)
#define CANXL_SIC_BTDCC_FTDMDIS(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BTDCC_FTDMDIS_SHIFT)) & CANXL_SIC_BTDCC_FTDMDIS_MASK)

#define CANXL_SIC_BTDCC_FTDCEN_MASK              (0x8000U)
#define CANXL_SIC_BTDCC_FTDCEN_SHIFT             (15U)
#define CANXL_SIC_BTDCC_FTDCEN_WIDTH             (1U)
#define CANXL_SIC_BTDCC_FTDCEN(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BTDCC_FTDCEN_SHIFT)) & CANXL_SIC_BTDCC_FTDCEN_MASK)

#define CANXL_SIC_BTDCC_XTDCOFF_MASK             (0xFF0000U)
#define CANXL_SIC_BTDCC_XTDCOFF_SHIFT            (16U)
#define CANXL_SIC_BTDCC_XTDCOFF_WIDTH            (8U)
#define CANXL_SIC_BTDCC_XTDCOFF(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BTDCC_XTDCOFF_SHIFT)) & CANXL_SIC_BTDCC_XTDCOFF_MASK)

#define CANXL_SIC_BTDCC_XTDMDIS_MASK             (0x40000000U)
#define CANXL_SIC_BTDCC_XTDMDIS_SHIFT            (30U)
#define CANXL_SIC_BTDCC_XTDMDIS_WIDTH            (1U)
#define CANXL_SIC_BTDCC_XTDMDIS(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BTDCC_XTDMDIS_SHIFT)) & CANXL_SIC_BTDCC_XTDMDIS_MASK)

#define CANXL_SIC_BTDCC_XTDCEN_MASK              (0x80000000U)
#define CANXL_SIC_BTDCC_XTDCEN_SHIFT             (31U)
#define CANXL_SIC_BTDCC_XTDCEN_WIDTH             (1U)
#define CANXL_SIC_BTDCC_XTDCEN(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BTDCC_XTDCEN_SHIFT)) & CANXL_SIC_BTDCC_XTDCEN_MASK)
/*! @} */

/*! @name BMICI - BCANXL PWM Configuration */
/*! @{ */

#define CANXL_SIC_BMICI_PWMO_MASK                (0x3FU)
#define CANXL_SIC_BMICI_PWMO_SHIFT               (0U)
#define CANXL_SIC_BMICI_PWMO_WIDTH               (6U)
#define CANXL_SIC_BMICI_PWMO(x)                  (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BMICI_PWMO_SHIFT)) & CANXL_SIC_BMICI_PWMO_MASK)

#define CANXL_SIC_BMICI_PWML_MASK                (0x3F00U)
#define CANXL_SIC_BMICI_PWML_SHIFT               (8U)
#define CANXL_SIC_BMICI_PWML_WIDTH               (6U)
#define CANXL_SIC_BMICI_PWML(x)                  (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BMICI_PWML_SHIFT)) & CANXL_SIC_BMICI_PWML_MASK)

#define CANXL_SIC_BMICI_PWMS_MASK                (0x3F0000U)
#define CANXL_SIC_BMICI_PWMS_SHIFT               (16U)
#define CANXL_SIC_BMICI_PWMS_WIDTH               (6U)
#define CANXL_SIC_BMICI_PWMS(x)                  (((uint32_t)(((uint32_t)(x)) << CANXL_SIC_BMICI_PWMS_SHIFT)) & CANXL_SIC_BMICI_PWMS_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CANXL_SIC_Register_Masks */

/*!
 * @}
 */ /* end of group CANXL_SIC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CANXL_SIC_H_) */
