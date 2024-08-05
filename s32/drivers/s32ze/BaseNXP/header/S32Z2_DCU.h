/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_DCU.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_DCU
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
#if !defined(S32Z2_DCU_H_)  /* Check if memory map has not been already included */
#define S32Z2_DCU_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- DCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCU_Peripheral_Access_Layer DCU Peripheral Access Layer
 * @{
 */

/** DCU - Register Layout Typedef */
typedef struct {
  __IO uint32_t OCM_PADD1;                         /**< OCM PADD1 Register, offset: 0x0 */
  __IO uint32_t OCM_PADD2;                         /**< OCM PADD2 Register, offset: 0x4 */
  uint8_t RESERVED_0[8];
  __IO uint32_t OCM_PCOUNT1;                       /**< OCM PCOUNT1 Register, offset: 0x10 */
  __IO uint32_t OCM_PCOUNT2;                       /**< OCM PCOUNT2 Register, offset: 0x14 */
  uint8_t RESERVED_1[8];
  __I  uint32_t CEVAX_A_PC;                        /**< CEVAX A PC Register, offset: 0x20 */
  __IO uint32_t OCM_DADD_LOW;                      /**< OCM DDD Low Register, offset: 0x24 */
  __IO uint32_t OCM_DADD_HIGH;                     /**< OCM DADD HIGH Register, offset: 0x28 */
  uint8_t RESERVED_2[4];
  __IO uint32_t OCM_ACOUNT;                        /**< OCM ACOUNT Register, offset: 0x30 */
  __IO uint32_t OCM_DCOUNT;                        /**< OCM DCOUNT Register, offset: 0x34 */
  __IO uint32_t OCM_DVM;                           /**< OCM DVM Register, offset: 0x38 */
  uint8_t RESERVED_3[4];
  __IO uint32_t OCM_CONTROL;                       /**< OCM CONTROL Register, offset: 0x40 */
  __IO uint32_t OCM_SA_BP_EN;                      /**< OCM SA BP EN Register, offset: 0x44 */
  __I  uint32_t MEM_CONFIG;                        /**< MEM CONFIG Register, offset: 0x48 */
  __I  uint32_t MSS_CONFIG;                        /**< MSS CONFIG Register, offset: 0x4C */
  __I  uint32_t OCM_STATUS;                        /**< OCM STATUS Register, offset: 0x50 */
  __I  uint32_t OCM_SA_BP_ST;                      /**< OCM SA BP ST Register, offset: 0x54 */
  __I  uint32_t M_CONFIG;                          /**< M CONFIG Register, offset: 0x58 */
  __I  uint32_t S_CONFIG;                          /**< S_CONFIG Register, offset: 0x5C */
  __I  uint32_t DEBUG_CONFIG;                      /**< DEBUG CONFIG Register, offset: 0x60 */
  __I  uint32_t CORE_VERSION;                      /**< CORE VERSION Register, offset: 0x64 */
  __I  uint32_t CORE_ID;                           /**< CORE ID Register, offset: 0x68 */
  __I  uint32_t CORE_CONFIG;                       /**< CORE CONFIG Register, offset: 0x6C */
} DCU_Type, *DCU_MemMapPtr;

/** Number of instances of the DCU module. */
#define DCU_INSTANCE_COUNT                       (1u)

/* DCU - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__DCU base address */
#define IP_CEVA_SPF2__DCU_BASE                   (0x24400110u)
/** Peripheral CEVA_SPF2__DCU base pointer */
#define IP_CEVA_SPF2__DCU                        ((DCU_Type *)IP_CEVA_SPF2__DCU_BASE)
/** Array initializer of DCU peripheral base addresses */
#define IP_DCU_BASE_ADDRS                        { IP_CEVA_SPF2__DCU_BASE }
/** Array initializer of DCU peripheral base pointers */
#define IP_DCU_BASE_PTRS                         { IP_CEVA_SPF2__DCU }

/* ----------------------------------------------------------------------------
   -- DCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCU_Register_Masks DCU Register Masks
 * @{
 */

/*! @name OCM_PADD1 - OCM PADD1 Register */
/*! @{ */

#define DCU_OCM_PADD1_OCM_PADD1_MASK             (0xFFFFFFFFU)
#define DCU_OCM_PADD1_OCM_PADD1_SHIFT            (0U)
#define DCU_OCM_PADD1_OCM_PADD1_WIDTH            (32U)
#define DCU_OCM_PADD1_OCM_PADD1(x)               (((uint32_t)(((uint32_t)(x)) << DCU_OCM_PADD1_OCM_PADD1_SHIFT)) & DCU_OCM_PADD1_OCM_PADD1_MASK)
/*! @} */

/*! @name OCM_PADD2 - OCM PADD2 Register */
/*! @{ */

#define DCU_OCM_PADD2_OCM_PADD2_MASK             (0xFFFFFFFFU)
#define DCU_OCM_PADD2_OCM_PADD2_SHIFT            (0U)
#define DCU_OCM_PADD2_OCM_PADD2_WIDTH            (32U)
#define DCU_OCM_PADD2_OCM_PADD2(x)               (((uint32_t)(((uint32_t)(x)) << DCU_OCM_PADD2_OCM_PADD2_SHIFT)) & DCU_OCM_PADD2_OCM_PADD2_MASK)
/*! @} */

/*! @name OCM_PCOUNT1 - OCM PCOUNT1 Register */
/*! @{ */

#define DCU_OCM_PCOUNT1_OCM_PCOUNT1_MASK         (0xFFFFU)
#define DCU_OCM_PCOUNT1_OCM_PCOUNT1_SHIFT        (0U)
#define DCU_OCM_PCOUNT1_OCM_PCOUNT1_WIDTH        (16U)
#define DCU_OCM_PCOUNT1_OCM_PCOUNT1(x)           (((uint32_t)(((uint32_t)(x)) << DCU_OCM_PCOUNT1_OCM_PCOUNT1_SHIFT)) & DCU_OCM_PCOUNT1_OCM_PCOUNT1_MASK)
/*! @} */

/*! @name OCM_PCOUNT2 - OCM PCOUNT2 Register */
/*! @{ */

#define DCU_OCM_PCOUNT2_OCM_PCOUNT2_MASK         (0xFFFFU)
#define DCU_OCM_PCOUNT2_OCM_PCOUNT2_SHIFT        (0U)
#define DCU_OCM_PCOUNT2_OCM_PCOUNT2_WIDTH        (16U)
#define DCU_OCM_PCOUNT2_OCM_PCOUNT2(x)           (((uint32_t)(((uint32_t)(x)) << DCU_OCM_PCOUNT2_OCM_PCOUNT2_SHIFT)) & DCU_OCM_PCOUNT2_OCM_PCOUNT2_MASK)
/*! @} */

/*! @name CEVAX_A_PC - CEVAX A PC Register */
/*! @{ */

#define DCU_CEVAX_A_PC_CEVAX_A_PC_MASK           (0xFFFFFFFFU)
#define DCU_CEVAX_A_PC_CEVAX_A_PC_SHIFT          (0U)
#define DCU_CEVAX_A_PC_CEVAX_A_PC_WIDTH          (32U)
#define DCU_CEVAX_A_PC_CEVAX_A_PC(x)             (((uint32_t)(((uint32_t)(x)) << DCU_CEVAX_A_PC_CEVAX_A_PC_SHIFT)) & DCU_CEVAX_A_PC_CEVAX_A_PC_MASK)
/*! @} */

/*! @name OCM_DADD_LOW - OCM DDD Low Register */
/*! @{ */

#define DCU_OCM_DADD_LOW_OCM_DADD_LOW_MASK       (0xFFFFFFFFU)
#define DCU_OCM_DADD_LOW_OCM_DADD_LOW_SHIFT      (0U)
#define DCU_OCM_DADD_LOW_OCM_DADD_LOW_WIDTH      (32U)
#define DCU_OCM_DADD_LOW_OCM_DADD_LOW(x)         (((uint32_t)(((uint32_t)(x)) << DCU_OCM_DADD_LOW_OCM_DADD_LOW_SHIFT)) & DCU_OCM_DADD_LOW_OCM_DADD_LOW_MASK)
/*! @} */

/*! @name OCM_DADD_HIGH - OCM DADD HIGH Register */
/*! @{ */

#define DCU_OCM_DADD_HIGH_OCM_DADD_HIGH_MASK     (0xFFFFFFFFU)
#define DCU_OCM_DADD_HIGH_OCM_DADD_HIGH_SHIFT    (0U)
#define DCU_OCM_DADD_HIGH_OCM_DADD_HIGH_WIDTH    (32U)
#define DCU_OCM_DADD_HIGH_OCM_DADD_HIGH(x)       (((uint32_t)(((uint32_t)(x)) << DCU_OCM_DADD_HIGH_OCM_DADD_HIGH_SHIFT)) & DCU_OCM_DADD_HIGH_OCM_DADD_HIGH_MASK)
/*! @} */

/*! @name OCM_ACOUNT - OCM ACOUNT Register */
/*! @{ */

#define DCU_OCM_ACOUNT_OCM_ACOUNT_MASK           (0xFFFFU)
#define DCU_OCM_ACOUNT_OCM_ACOUNT_SHIFT          (0U)
#define DCU_OCM_ACOUNT_OCM_ACOUNT_WIDTH          (16U)
#define DCU_OCM_ACOUNT_OCM_ACOUNT(x)             (((uint32_t)(((uint32_t)(x)) << DCU_OCM_ACOUNT_OCM_ACOUNT_SHIFT)) & DCU_OCM_ACOUNT_OCM_ACOUNT_MASK)
/*! @} */

/*! @name OCM_DCOUNT - OCM DCOUNT Register */
/*! @{ */

#define DCU_OCM_DCOUNT_OCM_DCOUNT_MASK           (0xFFFFU)
#define DCU_OCM_DCOUNT_OCM_DCOUNT_SHIFT          (0U)
#define DCU_OCM_DCOUNT_OCM_DCOUNT_WIDTH          (16U)
#define DCU_OCM_DCOUNT_OCM_DCOUNT(x)             (((uint32_t)(((uint32_t)(x)) << DCU_OCM_DCOUNT_OCM_DCOUNT_SHIFT)) & DCU_OCM_DCOUNT_OCM_DCOUNT_MASK)
/*! @} */

/*! @name OCM_DVM - OCM DVM Register */
/*! @{ */

#define DCU_OCM_DVM_OCM_DVM_MASK                 (0xFFFFFFFFU)
#define DCU_OCM_DVM_OCM_DVM_SHIFT                (0U)
#define DCU_OCM_DVM_OCM_DVM_WIDTH                (32U)
#define DCU_OCM_DVM_OCM_DVM(x)                   (((uint32_t)(((uint32_t)(x)) << DCU_OCM_DVM_OCM_DVM_SHIFT)) & DCU_OCM_DVM_OCM_DVM_MASK)
/*! @} */

/*! @name OCM_CONTROL - OCM CONTROL Register */
/*! @{ */

#define DCU_OCM_CONTROL_DEBUG_ENABLE_MASK        (0x1U)
#define DCU_OCM_CONTROL_DEBUG_ENABLE_SHIFT       (0U)
#define DCU_OCM_CONTROL_DEBUG_ENABLE_WIDTH       (1U)
#define DCU_OCM_CONTROL_DEBUG_ENABLE(x)          (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_DEBUG_ENABLE_SHIFT)) & DCU_OCM_CONTROL_DEBUG_ENABLE_MASK)

#define DCU_OCM_CONTROL_BP_DETECT_EN_MASK        (0x2U)
#define DCU_OCM_CONTROL_BP_DETECT_EN_SHIFT       (1U)
#define DCU_OCM_CONTROL_BP_DETECT_EN_WIDTH       (1U)
#define DCU_OCM_CONTROL_BP_DETECT_EN(x)          (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_BP_DETECT_EN_SHIFT)) & DCU_OCM_CONTROL_BP_DETECT_EN_MASK)

#define DCU_OCM_CONTROL_CORE_RST_MASK            (0x4U)
#define DCU_OCM_CONTROL_CORE_RST_SHIFT           (2U)
#define DCU_OCM_CONTROL_CORE_RST_WIDTH           (1U)
#define DCU_OCM_CONTROL_CORE_RST(x)              (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_CORE_RST_SHIFT)) & DCU_OCM_CONTROL_CORE_RST_MASK)

#define DCU_OCM_CONTROL_MSS_RST_MASK             (0x8U)
#define DCU_OCM_CONTROL_MSS_RST_SHIFT            (3U)
#define DCU_OCM_CONTROL_MSS_RST_WIDTH            (1U)
#define DCU_OCM_CONTROL_MSS_RST(x)               (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_MSS_RST_SHIFT)) & DCU_OCM_CONTROL_MSS_RST_MASK)

#define DCU_OCM_CONTROL_TRAPE_EN_MASK            (0x10U)
#define DCU_OCM_CONTROL_TRAPE_EN_SHIFT           (4U)
#define DCU_OCM_CONTROL_TRAPE_EN_WIDTH           (1U)
#define DCU_OCM_CONTROL_TRAPE_EN(x)              (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_TRAPE_EN_SHIFT)) & DCU_OCM_CONTROL_TRAPE_EN_MASK)

#define DCU_OCM_CONTROL_STOP_MASK                (0x20U)
#define DCU_OCM_CONTROL_STOP_SHIFT               (5U)
#define DCU_OCM_CONTROL_STOP_WIDTH               (1U)
#define DCU_OCM_CONTROL_STOP(x)                  (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_STOP_SHIFT)) & DCU_OCM_CONTROL_STOP_MASK)

#define DCU_OCM_CONTROL_STEP_MASK                (0x40U)
#define DCU_OCM_CONTROL_STEP_SHIFT               (6U)
#define DCU_OCM_CONTROL_STEP_WIDTH               (1U)
#define DCU_OCM_CONTROL_STEP(x)                  (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_STEP_SHIFT)) & DCU_OCM_CONTROL_STEP_MASK)

#define DCU_OCM_CONTROL_PADD_INC_MASK            (0x80U)
#define DCU_OCM_CONTROL_PADD_INC_SHIFT           (7U)
#define DCU_OCM_CONTROL_PADD_INC_WIDTH           (1U)
#define DCU_OCM_CONTROL_PADD_INC(x)              (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_PADD_INC_SHIFT)) & DCU_OCM_CONTROL_PADD_INC_MASK)

#define DCU_OCM_CONTROL_NIDIS_MASK               (0x100U)
#define DCU_OCM_CONTROL_NIDIS_SHIFT              (8U)
#define DCU_OCM_CONTROL_NIDIS_WIDTH              (1U)
#define DCU_OCM_CONTROL_NIDIS(x)                 (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_NIDIS_SHIFT)) & DCU_OCM_CONTROL_NIDIS_MASK)

#define DCU_OCM_CONTROL_CIDIS_MASK               (0x200U)
#define DCU_OCM_CONTROL_CIDIS_SHIFT              (9U)
#define DCU_OCM_CONTROL_CIDIS_WIDTH              (1U)
#define DCU_OCM_CONTROL_CIDIS(x)                 (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_CIDIS_SHIFT)) & DCU_OCM_CONTROL_CIDIS_MASK)

#define DCU_OCM_CONTROL_TINIS_MASK               (0x400U)
#define DCU_OCM_CONTROL_TINIS_SHIFT              (10U)
#define DCU_OCM_CONTROL_TINIS_WIDTH              (1U)
#define DCU_OCM_CONTROL_TINIS(x)                 (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_TINIS_SHIFT)) & DCU_OCM_CONTROL_TINIS_MASK)

#define DCU_OCM_CONTROL_GP_OUT_MASK              (0xF000U)
#define DCU_OCM_CONTROL_GP_OUT_SHIFT             (12U)
#define DCU_OCM_CONTROL_GP_OUT_WIDTH             (4U)
#define DCU_OCM_CONTROL_GP_OUT(x)                (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_GP_OUT_SHIFT)) & DCU_OCM_CONTROL_GP_OUT_MASK)

#define DCU_OCM_CONTROL_DVM_TYPE_MASK            (0x30000U)
#define DCU_OCM_CONTROL_DVM_TYPE_SHIFT           (16U)
#define DCU_OCM_CONTROL_DVM_TYPE_WIDTH           (2U)
#define DCU_OCM_CONTROL_DVM_TYPE(x)              (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_DVM_TYPE_SHIFT)) & DCU_OCM_CONTROL_DVM_TYPE_MASK)

#define DCU_OCM_CONTROL_RST_STATUS_MASK          (0x100000U)
#define DCU_OCM_CONTROL_RST_STATUS_SHIFT         (20U)
#define DCU_OCM_CONTROL_RST_STATUS_WIDTH         (1U)
#define DCU_OCM_CONTROL_RST_STATUS(x)            (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_RST_STATUS_SHIFT)) & DCU_OCM_CONTROL_RST_STATUS_MASK)

#define DCU_OCM_CONTROL_AUTO_CLK_MASK            (0x200000U)
#define DCU_OCM_CONTROL_AUTO_CLK_SHIFT           (21U)
#define DCU_OCM_CONTROL_AUTO_CLK_WIDTH           (1U)
#define DCU_OCM_CONTROL_AUTO_CLK(x)              (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_AUTO_CLK_SHIFT)) & DCU_OCM_CONTROL_AUTO_CLK_MASK)

#define DCU_OCM_CONTROL_BOOT_MASK_MASK           (0x800000U)
#define DCU_OCM_CONTROL_BOOT_MASK_SHIFT          (23U)
#define DCU_OCM_CONTROL_BOOT_MASK_WIDTH          (1U)
#define DCU_OCM_CONTROL_BOOT_MASK(x)             (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_BOOT_MASK_SHIFT)) & DCU_OCM_CONTROL_BOOT_MASK_MASK)

#define DCU_OCM_CONTROL_APB_ERROR_MASK           (0x1000000U)
#define DCU_OCM_CONTROL_APB_ERROR_SHIFT          (24U)
#define DCU_OCM_CONTROL_APB_ERROR_WIDTH          (1U)
#define DCU_OCM_CONTROL_APB_ERROR(x)             (((uint32_t)(((uint32_t)(x)) << DCU_OCM_CONTROL_APB_ERROR_SHIFT)) & DCU_OCM_CONTROL_APB_ERROR_MASK)
/*! @} */

/*! @name OCM_SA_BP_EN - OCM SA BP EN Register */
/*! @{ */

#define DCU_OCM_SA_BP_EN_SA_EXT_MASK             (0x3U)
#define DCU_OCM_SA_BP_EN_SA_EXT_SHIFT            (0U)
#define DCU_OCM_SA_BP_EN_SA_EXT_WIDTH            (2U)
#define DCU_OCM_SA_BP_EN_SA_EXT(x)               (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_EN_SA_EXT_SHIFT)) & DCU_OCM_SA_BP_EN_SA_EXT_MASK)

#define DCU_OCM_SA_BP_EN_DMA_DA_E_MASK           (0x8U)
#define DCU_OCM_SA_BP_EN_DMA_DA_E_SHIFT          (3U)
#define DCU_OCM_SA_BP_EN_DMA_DA_E_WIDTH          (1U)
#define DCU_OCM_SA_BP_EN_DMA_DA_E(x)             (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_EN_DMA_DA_E_SHIFT)) & DCU_OCM_SA_BP_EN_DMA_DA_E_MASK)

#define DCU_OCM_SA_BP_EN_SA_PA_MASK              (0x30U)
#define DCU_OCM_SA_BP_EN_SA_PA_SHIFT             (4U)
#define DCU_OCM_SA_BP_EN_SA_PA_WIDTH             (2U)
#define DCU_OCM_SA_BP_EN_SA_PA(x)                (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_EN_SA_PA_SHIFT)) & DCU_OCM_SA_BP_EN_SA_PA_MASK)

#define DCU_OCM_SA_BP_EN_SA_DA_RD_MASK           (0x100U)
#define DCU_OCM_SA_BP_EN_SA_DA_RD_SHIFT          (8U)
#define DCU_OCM_SA_BP_EN_SA_DA_RD_WIDTH          (1U)
#define DCU_OCM_SA_BP_EN_SA_DA_RD(x)             (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_EN_SA_DA_RD_SHIFT)) & DCU_OCM_SA_BP_EN_SA_DA_RD_MASK)

#define DCU_OCM_SA_BP_EN_SA_DA_WR_MASK           (0x1000U)
#define DCU_OCM_SA_BP_EN_SA_DA_WR_SHIFT          (12U)
#define DCU_OCM_SA_BP_EN_SA_DA_WR_WIDTH          (1U)
#define DCU_OCM_SA_BP_EN_SA_DA_WR(x)             (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_EN_SA_DA_WR_SHIFT)) & DCU_OCM_SA_BP_EN_SA_DA_WR_MASK)

#define DCU_OCM_SA_BP_EN_CO_A_EN_MASK            (0x2000U)
#define DCU_OCM_SA_BP_EN_CO_A_EN_SHIFT           (13U)
#define DCU_OCM_SA_BP_EN_CO_A_EN_WIDTH           (1U)
#define DCU_OCM_SA_BP_EN_CO_A_EN(x)              (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_EN_CO_A_EN_SHIFT)) & DCU_OCM_SA_BP_EN_CO_A_EN_MASK)

#define DCU_OCM_SA_BP_EN_CO_D_EN_MASK            (0x4000U)
#define DCU_OCM_SA_BP_EN_CO_D_EN_SHIFT           (14U)
#define DCU_OCM_SA_BP_EN_CO_D_EN_WIDTH           (1U)
#define DCU_OCM_SA_BP_EN_CO_D_EN(x)              (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_EN_CO_D_EN_SHIFT)) & DCU_OCM_SA_BP_EN_CO_D_EN_MASK)

#define DCU_OCM_SA_BP_EN_SA_DVM_MASK             (0x20000U)
#define DCU_OCM_SA_BP_EN_SA_DVM_SHIFT            (17U)
#define DCU_OCM_SA_BP_EN_SA_DVM_WIDTH            (1U)
#define DCU_OCM_SA_BP_EN_SA_DVM(x)               (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_EN_SA_DVM_SHIFT)) & DCU_OCM_SA_BP_EN_SA_DVM_MASK)

#define DCU_OCM_SA_BP_EN_SA_COMB_RD_MASK         (0x40000U)
#define DCU_OCM_SA_BP_EN_SA_COMB_RD_SHIFT        (18U)
#define DCU_OCM_SA_BP_EN_SA_COMB_RD_WIDTH        (1U)
#define DCU_OCM_SA_BP_EN_SA_COMB_RD(x)           (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_EN_SA_COMB_RD_SHIFT)) & DCU_OCM_SA_BP_EN_SA_COMB_RD_MASK)

#define DCU_OCM_SA_BP_EN_SA_COMB_WR_MASK         (0x80000U)
#define DCU_OCM_SA_BP_EN_SA_COMB_WR_SHIFT        (19U)
#define DCU_OCM_SA_BP_EN_SA_COMB_WR_WIDTH        (1U)
#define DCU_OCM_SA_BP_EN_SA_COMB_WR(x)           (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_EN_SA_COMB_WR_SHIFT)) & DCU_OCM_SA_BP_EN_SA_COMB_WR_MASK)
/*! @} */

/*! @name MEM_CONFIG - MEM CONFIG Register */
/*! @{ */

#define DCU_MEM_CONFIG_PMEM_TCM_SIZE_MASK        (0xF0U)
#define DCU_MEM_CONFIG_PMEM_TCM_SIZE_SHIFT       (4U)
#define DCU_MEM_CONFIG_PMEM_TCM_SIZE_WIDTH       (4U)
#define DCU_MEM_CONFIG_PMEM_TCM_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << DCU_MEM_CONFIG_PMEM_TCM_SIZE_SHIFT)) & DCU_MEM_CONFIG_PMEM_TCM_SIZE_MASK)

#define DCU_MEM_CONFIG_PMEM_CAC_SIZE_MASK        (0xF00U)
#define DCU_MEM_CONFIG_PMEM_CAC_SIZE_SHIFT       (8U)
#define DCU_MEM_CONFIG_PMEM_CAC_SIZE_WIDTH       (4U)
#define DCU_MEM_CONFIG_PMEM_CAC_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << DCU_MEM_CONFIG_PMEM_CAC_SIZE_SHIFT)) & DCU_MEM_CONFIG_PMEM_CAC_SIZE_MASK)

#define DCU_MEM_CONFIG_PMEM_CAC_WAY_MASK         (0x1000U)
#define DCU_MEM_CONFIG_PMEM_CAC_WAY_SHIFT        (12U)
#define DCU_MEM_CONFIG_PMEM_CAC_WAY_WIDTH        (1U)
#define DCU_MEM_CONFIG_PMEM_CAC_WAY(x)           (((uint32_t)(((uint32_t)(x)) << DCU_MEM_CONFIG_PMEM_CAC_WAY_SHIFT)) & DCU_MEM_CONFIG_PMEM_CAC_WAY_MASK)

#define DCU_MEM_CONFIG_DMEM_TCM_SIZE_MASK        (0xF0000U)
#define DCU_MEM_CONFIG_DMEM_TCM_SIZE_SHIFT       (16U)
#define DCU_MEM_CONFIG_DMEM_TCM_SIZE_WIDTH       (4U)
#define DCU_MEM_CONFIG_DMEM_TCM_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << DCU_MEM_CONFIG_DMEM_TCM_SIZE_SHIFT)) & DCU_MEM_CONFIG_DMEM_TCM_SIZE_MASK)

#define DCU_MEM_CONFIG_DMEM_CAC_SIZE_MASK        (0xF00000U)
#define DCU_MEM_CONFIG_DMEM_CAC_SIZE_SHIFT       (20U)
#define DCU_MEM_CONFIG_DMEM_CAC_SIZE_WIDTH       (4U)
#define DCU_MEM_CONFIG_DMEM_CAC_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << DCU_MEM_CONFIG_DMEM_CAC_SIZE_SHIFT)) & DCU_MEM_CONFIG_DMEM_CAC_SIZE_MASK)

#define DCU_MEM_CONFIG_DMSS_BLK_MASK             (0x3000000U)
#define DCU_MEM_CONFIG_DMSS_BLK_SHIFT            (24U)
#define DCU_MEM_CONFIG_DMSS_BLK_WIDTH            (2U)
#define DCU_MEM_CONFIG_DMSS_BLK(x)               (((uint32_t)(((uint32_t)(x)) << DCU_MEM_CONFIG_DMSS_BLK_SHIFT)) & DCU_MEM_CONFIG_DMSS_BLK_MASK)

#define DCU_MEM_CONFIG_DMEM_CAC_WAY_MASK         (0x8000000U)
#define DCU_MEM_CONFIG_DMEM_CAC_WAY_SHIFT        (27U)
#define DCU_MEM_CONFIG_DMEM_CAC_WAY_WIDTH        (1U)
#define DCU_MEM_CONFIG_DMEM_CAC_WAY(x)           (((uint32_t)(((uint32_t)(x)) << DCU_MEM_CONFIG_DMEM_CAC_WAY_SHIFT)) & DCU_MEM_CONFIG_DMEM_CAC_WAY_MASK)

#define DCU_MEM_CONFIG_PECC_MASK                 (0x30000000U)
#define DCU_MEM_CONFIG_PECC_SHIFT                (28U)
#define DCU_MEM_CONFIG_PECC_WIDTH                (2U)
#define DCU_MEM_CONFIG_PECC(x)                   (((uint32_t)(((uint32_t)(x)) << DCU_MEM_CONFIG_PECC_SHIFT)) & DCU_MEM_CONFIG_PECC_MASK)

#define DCU_MEM_CONFIG_DECC_MASK                 (0xC0000000U)
#define DCU_MEM_CONFIG_DECC_SHIFT                (30U)
#define DCU_MEM_CONFIG_DECC_WIDTH                (2U)
#define DCU_MEM_CONFIG_DECC(x)                   (((uint32_t)(((uint32_t)(x)) << DCU_MEM_CONFIG_DECC_SHIFT)) & DCU_MEM_CONFIG_DECC_MASK)
/*! @} */

/*! @name MSS_CONFIG - MSS CONFIG Register */
/*! @{ */

#define DCU_MSS_CONFIG_NUM_QMAN_MASK             (0x1FU)
#define DCU_MSS_CONFIG_NUM_QMAN_SHIFT            (0U)
#define DCU_MSS_CONFIG_NUM_QMAN_WIDTH            (5U)
#define DCU_MSS_CONFIG_NUM_QMAN(x)               (((uint32_t)(((uint32_t)(x)) << DCU_MSS_CONFIG_NUM_QMAN_SHIFT)) & DCU_MSS_CONFIG_NUM_QMAN_MASK)

#define DCU_MSS_CONFIG_NUM_ICU_GRP_MASK          (0xF0000U)
#define DCU_MSS_CONFIG_NUM_ICU_GRP_SHIFT         (16U)
#define DCU_MSS_CONFIG_NUM_ICU_GRP_WIDTH         (4U)
#define DCU_MSS_CONFIG_NUM_ICU_GRP(x)            (((uint32_t)(((uint32_t)(x)) << DCU_MSS_CONFIG_NUM_ICU_GRP_SHIFT)) & DCU_MSS_CONFIG_NUM_ICU_GRP_MASK)

#define DCU_MSS_CONFIG_NUM_TIMER_MASK            (0x300000U)
#define DCU_MSS_CONFIG_NUM_TIMER_SHIFT           (20U)
#define DCU_MSS_CONFIG_NUM_TIMER_WIDTH           (2U)
#define DCU_MSS_CONFIG_NUM_TIMER(x)              (((uint32_t)(((uint32_t)(x)) << DCU_MSS_CONFIG_NUM_TIMER_SHIFT)) & DCU_MSS_CONFIG_NUM_TIMER_MASK)
/*! @} */

/*! @name OCM_STATUS - OCM STATUS Register */
/*! @{ */

#define DCU_OCM_STATUS_DBG_MODE_MASK             (0x1U)
#define DCU_OCM_STATUS_DBG_MODE_SHIFT            (0U)
#define DCU_OCM_STATUS_DBG_MODE_WIDTH            (1U)
#define DCU_OCM_STATUS_DBG_MODE(x)               (((uint32_t)(((uint32_t)(x)) << DCU_OCM_STATUS_DBG_MODE_SHIFT)) & DCU_OCM_STATUS_DBG_MODE_MASK)

#define DCU_OCM_STATUS_RST_DUR_DEBUG_MASK        (0x2U)
#define DCU_OCM_STATUS_RST_DUR_DEBUG_SHIFT       (1U)
#define DCU_OCM_STATUS_RST_DUR_DEBUG_WIDTH       (1U)
#define DCU_OCM_STATUS_RST_DUR_DEBUG(x)          (((uint32_t)(((uint32_t)(x)) << DCU_OCM_STATUS_RST_DUR_DEBUG_SHIFT)) & DCU_OCM_STATUS_RST_DUR_DEBUG_MASK)

#define DCU_OCM_STATUS_PMEM_WR_MASK              (0x4U)
#define DCU_OCM_STATUS_PMEM_WR_SHIFT             (2U)
#define DCU_OCM_STATUS_PMEM_WR_WIDTH             (1U)
#define DCU_OCM_STATUS_PMEM_WR(x)                (((uint32_t)(((uint32_t)(x)) << DCU_OCM_STATUS_PMEM_WR_SHIFT)) & DCU_OCM_STATUS_PMEM_WR_MASK)

#define DCU_OCM_STATUS_PCACHE_WR_MASK            (0x8U)
#define DCU_OCM_STATUS_PCACHE_WR_SHIFT           (3U)
#define DCU_OCM_STATUS_PCACHE_WR_WIDTH           (1U)
#define DCU_OCM_STATUS_PCACHE_WR(x)              (((uint32_t)(((uint32_t)(x)) << DCU_OCM_STATUS_PCACHE_WR_SHIFT)) & DCU_OCM_STATUS_PCACHE_WR_MASK)

#define DCU_OCM_STATUS_CORE_NOT_IDLE_MASK        (0x20U)
#define DCU_OCM_STATUS_CORE_NOT_IDLE_SHIFT       (5U)
#define DCU_OCM_STATUS_CORE_NOT_IDLE_WIDTH       (1U)
#define DCU_OCM_STATUS_CORE_NOT_IDLE(x)          (((uint32_t)(((uint32_t)(x)) << DCU_OCM_STATUS_CORE_NOT_IDLE_SHIFT)) & DCU_OCM_STATUS_CORE_NOT_IDLE_MASK)

#define DCU_OCM_STATUS_PACTIVE_TRANS_MASK        (0x80U)
#define DCU_OCM_STATUS_PACTIVE_TRANS_SHIFT       (7U)
#define DCU_OCM_STATUS_PACTIVE_TRANS_WIDTH       (1U)
#define DCU_OCM_STATUS_PACTIVE_TRANS(x)          (((uint32_t)(((uint32_t)(x)) << DCU_OCM_STATUS_PACTIVE_TRANS_SHIFT)) & DCU_OCM_STATUS_PACTIVE_TRANS_MASK)

#define DCU_OCM_STATUS_TRAPE_INST_MASK           (0x100U)
#define DCU_OCM_STATUS_TRAPE_INST_SHIFT          (8U)
#define DCU_OCM_STATUS_TRAPE_INST_WIDTH          (1U)
#define DCU_OCM_STATUS_TRAPE_INST(x)             (((uint32_t)(((uint32_t)(x)) << DCU_OCM_STATUS_TRAPE_INST_SHIFT)) & DCU_OCM_STATUS_TRAPE_INST_MASK)

#define DCU_OCM_STATUS_PMSS_IDLE_MASK            (0x200U)
#define DCU_OCM_STATUS_PMSS_IDLE_SHIFT           (9U)
#define DCU_OCM_STATUS_PMSS_IDLE_WIDTH           (1U)
#define DCU_OCM_STATUS_PMSS_IDLE(x)              (((uint32_t)(((uint32_t)(x)) << DCU_OCM_STATUS_PMSS_IDLE_SHIFT)) & DCU_OCM_STATUS_PMSS_IDLE_MASK)

#define DCU_OCM_STATUS_DACTIVE_TRANS_MASK        (0x1000U)
#define DCU_OCM_STATUS_DACTIVE_TRANS_SHIFT       (12U)
#define DCU_OCM_STATUS_DACTIVE_TRANS_WIDTH       (1U)
#define DCU_OCM_STATUS_DACTIVE_TRANS(x)          (((uint32_t)(((uint32_t)(x)) << DCU_OCM_STATUS_DACTIVE_TRANS_SHIFT)) & DCU_OCM_STATUS_DACTIVE_TRANS_MASK)

#define DCU_OCM_STATUS_DMSS_IDLE_OCEM_MASK       (0x2000U)
#define DCU_OCM_STATUS_DMSS_IDLE_OCEM_SHIFT      (13U)
#define DCU_OCM_STATUS_DMSS_IDLE_OCEM_WIDTH      (1U)
#define DCU_OCM_STATUS_DMSS_IDLE_OCEM(x)         (((uint32_t)(((uint32_t)(x)) << DCU_OCM_STATUS_DMSS_IDLE_OCEM_SHIFT)) & DCU_OCM_STATUS_DMSS_IDLE_OCEM_MASK)

#define DCU_OCM_STATUS_DMSS_SLAVE_ACT_MASK       (0x8000U)
#define DCU_OCM_STATUS_DMSS_SLAVE_ACT_SHIFT      (15U)
#define DCU_OCM_STATUS_DMSS_SLAVE_ACT_WIDTH      (1U)
#define DCU_OCM_STATUS_DMSS_SLAVE_ACT(x)         (((uint32_t)(((uint32_t)(x)) << DCU_OCM_STATUS_DMSS_SLAVE_ACT_SHIFT)) & DCU_OCM_STATUS_DMSS_SLAVE_ACT_MASK)

#define DCU_OCM_STATUS_WAIT_MASK                 (0x40000U)
#define DCU_OCM_STATUS_WAIT_SHIFT                (18U)
#define DCU_OCM_STATUS_WAIT_WIDTH                (1U)
#define DCU_OCM_STATUS_WAIT(x)                   (((uint32_t)(((uint32_t)(x)) << DCU_OCM_STATUS_WAIT_SHIFT)) & DCU_OCM_STATUS_WAIT_MASK)

#define DCU_OCM_STATUS_AUTH_IF_MASK              (0xF0000000U)
#define DCU_OCM_STATUS_AUTH_IF_SHIFT             (28U)
#define DCU_OCM_STATUS_AUTH_IF_WIDTH             (4U)
#define DCU_OCM_STATUS_AUTH_IF(x)                (((uint32_t)(((uint32_t)(x)) << DCU_OCM_STATUS_AUTH_IF_SHIFT)) & DCU_OCM_STATUS_AUTH_IF_MASK)
/*! @} */

/*! @name OCM_SA_BP_ST - OCM SA BP ST Register */
/*! @{ */

#define DCU_OCM_SA_BP_ST_SA_EXT_ST_MASK          (0x3U)
#define DCU_OCM_SA_BP_ST_SA_EXT_ST_SHIFT         (0U)
#define DCU_OCM_SA_BP_ST_SA_EXT_ST_WIDTH         (2U)
#define DCU_OCM_SA_BP_ST_SA_EXT_ST(x)            (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_ST_SA_EXT_ST_SHIFT)) & DCU_OCM_SA_BP_ST_SA_EXT_ST_MASK)

#define DCU_OCM_SA_BP_ST_DMA_DA_ST_MASK          (0x8U)
#define DCU_OCM_SA_BP_ST_DMA_DA_ST_SHIFT         (3U)
#define DCU_OCM_SA_BP_ST_DMA_DA_ST_WIDTH         (1U)
#define DCU_OCM_SA_BP_ST_DMA_DA_ST(x)            (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_ST_DMA_DA_ST_SHIFT)) & DCU_OCM_SA_BP_ST_DMA_DA_ST_MASK)

#define DCU_OCM_SA_BP_ST_SA_PA_ST_MASK           (0x30U)
#define DCU_OCM_SA_BP_ST_SA_PA_ST_SHIFT          (4U)
#define DCU_OCM_SA_BP_ST_SA_PA_ST_WIDTH          (2U)
#define DCU_OCM_SA_BP_ST_SA_PA_ST(x)             (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_ST_SA_PA_ST_SHIFT)) & DCU_OCM_SA_BP_ST_SA_PA_ST_MASK)

#define DCU_OCM_SA_BP_ST_SA_DA_RD_ST_MASK        (0x100U)
#define DCU_OCM_SA_BP_ST_SA_DA_RD_ST_SHIFT       (8U)
#define DCU_OCM_SA_BP_ST_SA_DA_RD_ST_WIDTH       (1U)
#define DCU_OCM_SA_BP_ST_SA_DA_RD_ST(x)          (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_ST_SA_DA_RD_ST_SHIFT)) & DCU_OCM_SA_BP_ST_SA_DA_RD_ST_MASK)

#define DCU_OCM_SA_BP_ST_SA_DA_WR_ST_MASK        (0x1000U)
#define DCU_OCM_SA_BP_ST_SA_DA_WR_ST_SHIFT       (12U)
#define DCU_OCM_SA_BP_ST_SA_DA_WR_ST_WIDTH       (1U)
#define DCU_OCM_SA_BP_ST_SA_DA_WR_ST(x)          (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_ST_SA_DA_WR_ST_SHIFT)) & DCU_OCM_SA_BP_ST_SA_DA_WR_ST_MASK)

#define DCU_OCM_SA_BP_ST_SA_DVM_ST_MASK          (0x20000U)
#define DCU_OCM_SA_BP_ST_SA_DVM_ST_SHIFT         (17U)
#define DCU_OCM_SA_BP_ST_SA_DVM_ST_WIDTH         (1U)
#define DCU_OCM_SA_BP_ST_SA_DVM_ST(x)            (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_ST_SA_DVM_ST_SHIFT)) & DCU_OCM_SA_BP_ST_SA_DVM_ST_MASK)

#define DCU_OCM_SA_BP_ST_SA_COMB_RD_ST_MASK      (0x40000U)
#define DCU_OCM_SA_BP_ST_SA_COMB_RD_ST_SHIFT     (18U)
#define DCU_OCM_SA_BP_ST_SA_COMB_RD_ST_WIDTH     (1U)
#define DCU_OCM_SA_BP_ST_SA_COMB_RD_ST(x)        (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_ST_SA_COMB_RD_ST_SHIFT)) & DCU_OCM_SA_BP_ST_SA_COMB_RD_ST_MASK)

#define DCU_OCM_SA_BP_ST_SA_COMB_WR_ST_MASK      (0x80000U)
#define DCU_OCM_SA_BP_ST_SA_COMB_WR_ST_SHIFT     (19U)
#define DCU_OCM_SA_BP_ST_SA_COMB_WR_ST_WIDTH     (1U)
#define DCU_OCM_SA_BP_ST_SA_COMB_WR_ST(x)        (((uint32_t)(((uint32_t)(x)) << DCU_OCM_SA_BP_ST_SA_COMB_WR_ST_SHIFT)) & DCU_OCM_SA_BP_ST_SA_COMB_WR_ST_MASK)
/*! @} */

/*! @name M_CONFIG - M CONFIG Register */
/*! @{ */

#define DCU_M_CONFIG_M0_WIDTH_MASK               (0x7U)
#define DCU_M_CONFIG_M0_WIDTH_SHIFT              (0U)
#define DCU_M_CONFIG_M0_WIDTH_WIDTH              (3U)
#define DCU_M_CONFIG_M0_WIDTH(x)                 (((uint32_t)(((uint32_t)(x)) << DCU_M_CONFIG_M0_WIDTH_SHIFT)) & DCU_M_CONFIG_M0_WIDTH_MASK)

#define DCU_M_CONFIG_M1_WIDTH_MASK               (0x70U)
#define DCU_M_CONFIG_M1_WIDTH_SHIFT              (4U)
#define DCU_M_CONFIG_M1_WIDTH_WIDTH              (3U)
#define DCU_M_CONFIG_M1_WIDTH(x)                 (((uint32_t)(((uint32_t)(x)) << DCU_M_CONFIG_M1_WIDTH_SHIFT)) & DCU_M_CONFIG_M1_WIDTH_MASK)

#define DCU_M_CONFIG_EDP_WIDTH_MASK              (0x700U)
#define DCU_M_CONFIG_EDP_WIDTH_SHIFT             (8U)
#define DCU_M_CONFIG_EDP_WIDTH_WIDTH             (3U)
#define DCU_M_CONFIG_EDP_WIDTH(x)                (((uint32_t)(((uint32_t)(x)) << DCU_M_CONFIG_EDP_WIDTH_SHIFT)) & DCU_M_CONFIG_EDP_WIDTH_MASK)

#define DCU_M_CONFIG_EPP_WIDTH_MASK              (0x7000U)
#define DCU_M_CONFIG_EPP_WIDTH_SHIFT             (12U)
#define DCU_M_CONFIG_EPP_WIDTH_WIDTH             (3U)
#define DCU_M_CONFIG_EPP_WIDTH(x)                (((uint32_t)(((uint32_t)(x)) << DCU_M_CONFIG_EPP_WIDTH_SHIFT)) & DCU_M_CONFIG_EPP_WIDTH_MASK)
/*! @} */

/*! @name S_CONFIG - S_CONFIG Register */
/*! @{ */

#define DCU_S_CONFIG_S0_WIDTH_MASK               (0x7U)
#define DCU_S_CONFIG_S0_WIDTH_SHIFT              (0U)
#define DCU_S_CONFIG_S0_WIDTH_WIDTH              (3U)
#define DCU_S_CONFIG_S0_WIDTH(x)                 (((uint32_t)(((uint32_t)(x)) << DCU_S_CONFIG_S0_WIDTH_SHIFT)) & DCU_S_CONFIG_S0_WIDTH_MASK)

#define DCU_S_CONFIG_S1_WIDTH_MASK               (0x70U)
#define DCU_S_CONFIG_S1_WIDTH_SHIFT              (4U)
#define DCU_S_CONFIG_S1_WIDTH_WIDTH              (3U)
#define DCU_S_CONFIG_S1_WIDTH(x)                 (((uint32_t)(((uint32_t)(x)) << DCU_S_CONFIG_S1_WIDTH_SHIFT)) & DCU_S_CONFIG_S1_WIDTH_MASK)

#define DCU_S_CONFIG_S2_WIDTH_MASK               (0x700U)
#define DCU_S_CONFIG_S2_WIDTH_SHIFT              (8U)
#define DCU_S_CONFIG_S2_WIDTH_WIDTH              (3U)
#define DCU_S_CONFIG_S2_WIDTH(x)                 (((uint32_t)(((uint32_t)(x)) << DCU_S_CONFIG_S2_WIDTH_SHIFT)) & DCU_S_CONFIG_S2_WIDTH_MASK)

#define DCU_S_CONFIG_EDAP_WIDTH_MASK             (0x7000U)
#define DCU_S_CONFIG_EDAP_WIDTH_SHIFT            (12U)
#define DCU_S_CONFIG_EDAP_WIDTH_WIDTH            (3U)
#define DCU_S_CONFIG_EDAP_WIDTH(x)               (((uint32_t)(((uint32_t)(x)) << DCU_S_CONFIG_EDAP_WIDTH_SHIFT)) & DCU_S_CONFIG_EDAP_WIDTH_MASK)
/*! @} */

/*! @name DEBUG_CONFIG - DEBUG CONFIG Register */
/*! @{ */

#define DCU_DEBUG_CONFIG_DVBP_MASK               (0x6U)
#define DCU_DEBUG_CONFIG_DVBP_SHIFT              (1U)
#define DCU_DEBUG_CONFIG_DVBP_WIDTH              (2U)
#define DCU_DEBUG_CONFIG_DVBP(x)                 (((uint32_t)(((uint32_t)(x)) << DCU_DEBUG_CONFIG_DVBP_SHIFT)) & DCU_DEBUG_CONFIG_DVBP_MASK)

#define DCU_DEBUG_CONFIG_PROFILER_MASK           (0x300U)
#define DCU_DEBUG_CONFIG_PROFILER_SHIFT          (8U)
#define DCU_DEBUG_CONFIG_PROFILER_WIDTH          (2U)
#define DCU_DEBUG_CONFIG_PROFILER(x)             (((uint32_t)(((uint32_t)(x)) << DCU_DEBUG_CONFIG_PROFILER_SHIFT)) & DCU_DEBUG_CONFIG_PROFILER_MASK)

#define DCU_DEBUG_CONFIG_RTT_MASK                (0x3000U)
#define DCU_DEBUG_CONFIG_RTT_SHIFT               (12U)
#define DCU_DEBUG_CONFIG_RTT_WIDTH               (2U)
#define DCU_DEBUG_CONFIG_RTT(x)                  (((uint32_t)(((uint32_t)(x)) << DCU_DEBUG_CONFIG_RTT_SHIFT)) & DCU_DEBUG_CONFIG_RTT_MASK)

#define DCU_DEBUG_CONFIG_APB_MASK                (0x10000U)
#define DCU_DEBUG_CONFIG_APB_SHIFT               (16U)
#define DCU_DEBUG_CONFIG_APB_WIDTH               (1U)
#define DCU_DEBUG_CONFIG_APB(x)                  (((uint32_t)(((uint32_t)(x)) << DCU_DEBUG_CONFIG_APB_SHIFT)) & DCU_DEBUG_CONFIG_APB_MASK)
/*! @} */

/*! @name CORE_VERSION - CORE VERSION Register */
/*! @{ */

#define DCU_CORE_VERSION_DSP_RTL_REVISION_MASK   (0xFU)
#define DCU_CORE_VERSION_DSP_RTL_REVISION_SHIFT  (0U)
#define DCU_CORE_VERSION_DSP_RTL_REVISION_WIDTH  (4U)
#define DCU_CORE_VERSION_DSP_RTL_REVISION(x)     (((uint32_t)(((uint32_t)(x)) << DCU_CORE_VERSION_DSP_RTL_REVISION_SHIFT)) & DCU_CORE_VERSION_DSP_RTL_REVISION_MASK)

#define DCU_CORE_VERSION_DSP_RTL_VERSION_MASK    (0xFFF0U)
#define DCU_CORE_VERSION_DSP_RTL_VERSION_SHIFT   (4U)
#define DCU_CORE_VERSION_DSP_RTL_VERSION_WIDTH   (12U)
#define DCU_CORE_VERSION_DSP_RTL_VERSION(x)      (((uint32_t)(((uint32_t)(x)) << DCU_CORE_VERSION_DSP_RTL_VERSION_SHIFT)) & DCU_CORE_VERSION_DSP_RTL_VERSION_MASK)

#define DCU_CORE_VERSION_DSP_CORE_TYPE_MASK      (0xFFFF0000U)
#define DCU_CORE_VERSION_DSP_CORE_TYPE_SHIFT     (16U)
#define DCU_CORE_VERSION_DSP_CORE_TYPE_WIDTH     (16U)
#define DCU_CORE_VERSION_DSP_CORE_TYPE(x)        (((uint32_t)(((uint32_t)(x)) << DCU_CORE_VERSION_DSP_CORE_TYPE_SHIFT)) & DCU_CORE_VERSION_DSP_CORE_TYPE_MASK)
/*! @} */

/*! @name CORE_ID - CORE ID Register */
/*! @{ */

#define DCU_CORE_ID_CORE_ID_MASK                 (0xFFFFFFFFU)
#define DCU_CORE_ID_CORE_ID_SHIFT                (0U)
#define DCU_CORE_ID_CORE_ID_WIDTH                (32U)
#define DCU_CORE_ID_CORE_ID(x)                   (((uint32_t)(((uint32_t)(x)) << DCU_CORE_ID_CORE_ID_SHIFT)) & DCU_CORE_ID_CORE_ID_MASK)
/*! @} */

/*! @name CORE_CONFIG - CORE CONFIG Register */
/*! @{ */

#define DCU_CORE_CONFIG_SPU_XTEND_MASK           (0x1U)
#define DCU_CORE_CONFIG_SPU_XTEND_SHIFT          (0U)
#define DCU_CORE_CONFIG_SPU_XTEND_WIDTH          (1U)
#define DCU_CORE_CONFIG_SPU_XTEND(x)             (((uint32_t)(((uint32_t)(x)) << DCU_CORE_CONFIG_SPU_XTEND_SHIFT)) & DCU_CORE_CONFIG_SPU_XTEND_MASK)

#define DCU_CORE_CONFIG_VPU_XTEND_MASK           (0x2U)
#define DCU_CORE_CONFIG_VPU_XTEND_SHIFT          (1U)
#define DCU_CORE_CONFIG_VPU_XTEND_WIDTH          (1U)
#define DCU_CORE_CONFIG_VPU_XTEND(x)             (((uint32_t)(((uint32_t)(x)) << DCU_CORE_CONFIG_VPU_XTEND_SHIFT)) & DCU_CORE_CONFIG_VPU_XTEND_MASK)

#define DCU_CORE_CONFIG_BTB_ENTRIES_MASK         (0x30U)
#define DCU_CORE_CONFIG_BTB_ENTRIES_SHIFT        (4U)
#define DCU_CORE_CONFIG_BTB_ENTRIES_WIDTH        (2U)
#define DCU_CORE_CONFIG_BTB_ENTRIES(x)           (((uint32_t)(((uint32_t)(x)) << DCU_CORE_CONFIG_BTB_ENTRIES_SHIFT)) & DCU_CORE_CONFIG_BTB_ENTRIES_MASK)

#define DCU_CORE_CONFIG_BTB_WAYS_MASK            (0x80U)
#define DCU_CORE_CONFIG_BTB_WAYS_SHIFT           (7U)
#define DCU_CORE_CONFIG_BTB_WAYS_WIDTH           (1U)
#define DCU_CORE_CONFIG_BTB_WAYS(x)              (((uint32_t)(((uint32_t)(x)) << DCU_CORE_CONFIG_BTB_WAYS_SHIFT)) & DCU_CORE_CONFIG_BTB_WAYS_MASK)

#define DCU_CORE_CONFIG_SFP_MASK                 (0x200U)
#define DCU_CORE_CONFIG_SFP_SHIFT                (9U)
#define DCU_CORE_CONFIG_SFP_WIDTH                (1U)
#define DCU_CORE_CONFIG_SFP(x)                   (((uint32_t)(((uint32_t)(x)) << DCU_CORE_CONFIG_SFP_SHIFT)) & DCU_CORE_CONFIG_SFP_MASK)

#define DCU_CORE_CONFIG_HPF_MASK                 (0x400U)
#define DCU_CORE_CONFIG_HPF_SHIFT                (10U)
#define DCU_CORE_CONFIG_HPF_WIDTH                (1U)
#define DCU_CORE_CONFIG_HPF(x)                   (((uint32_t)(((uint32_t)(x)) << DCU_CORE_CONFIG_HPF_SHIFT)) & DCU_CORE_CONFIG_HPF_MASK)

#define DCU_CORE_CONFIG_NUM_VCU_MASK             (0x10000U)
#define DCU_CORE_CONFIG_NUM_VCU_SHIFT            (16U)
#define DCU_CORE_CONFIG_NUM_VCU_WIDTH            (1U)
#define DCU_CORE_CONFIG_NUM_VCU(x)               (((uint32_t)(((uint32_t)(x)) << DCU_CORE_CONFIG_NUM_VCU_SHIFT)) & DCU_CORE_CONFIG_NUM_VCU_MASK)

#define DCU_CORE_CONFIG_LVPU_MASK                (0x20000U)
#define DCU_CORE_CONFIG_LVPU_SHIFT               (17U)
#define DCU_CORE_CONFIG_LVPU_WIDTH               (1U)
#define DCU_CORE_CONFIG_LVPU(x)                  (((uint32_t)(((uint32_t)(x)) << DCU_CORE_CONFIG_LVPU_SHIFT)) & DCU_CORE_CONFIG_LVPU_MASK)

#define DCU_CORE_CONFIG_VEC_MPY_MASK             (0x100000U)
#define DCU_CORE_CONFIG_VEC_MPY_SHIFT            (20U)
#define DCU_CORE_CONFIG_VEC_MPY_WIDTH            (1U)
#define DCU_CORE_CONFIG_VEC_MPY(x)               (((uint32_t)(((uint32_t)(x)) << DCU_CORE_CONFIG_VEC_MPY_SHIFT)) & DCU_CORE_CONFIG_VEC_MPY_MASK)

#define DCU_CORE_CONFIG_VEC_MPY_XTD_MASK         (0x200000U)
#define DCU_CORE_CONFIG_VEC_MPY_XTD_SHIFT        (21U)
#define DCU_CORE_CONFIG_VEC_MPY_XTD_WIDTH        (1U)
#define DCU_CORE_CONFIG_VEC_MPY_XTD(x)           (((uint32_t)(((uint32_t)(x)) << DCU_CORE_CONFIG_VEC_MPY_XTD_SHIFT)) & DCU_CORE_CONFIG_VEC_MPY_XTD_MASK)

#define DCU_CORE_CONFIG_VSP_FP_MASK              (0xC00000U)
#define DCU_CORE_CONFIG_VSP_FP_SHIFT             (22U)
#define DCU_CORE_CONFIG_VSP_FP_WIDTH             (2U)
#define DCU_CORE_CONFIG_VSP_FP(x)                (((uint32_t)(((uint32_t)(x)) << DCU_CORE_CONFIG_VSP_FP_SHIFT)) & DCU_CORE_CONFIG_VSP_FP_MASK)

#define DCU_CORE_CONFIG_VHP_FP_MASK              (0x1000000U)
#define DCU_CORE_CONFIG_VHP_FP_SHIFT             (24U)
#define DCU_CORE_CONFIG_VHP_FP_WIDTH             (1U)
#define DCU_CORE_CONFIG_VHP_FP(x)                (((uint32_t)(((uint32_t)(x)) << DCU_CORE_CONFIG_VHP_FP_SHIFT)) & DCU_CORE_CONFIG_VHP_FP_MASK)

#define DCU_CORE_CONFIG_NL_MASK                  (0x2000000U)
#define DCU_CORE_CONFIG_NL_SHIFT                 (25U)
#define DCU_CORE_CONFIG_NL_WIDTH                 (1U)
#define DCU_CORE_CONFIG_NL(x)                    (((uint32_t)(((uint32_t)(x)) << DCU_CORE_CONFIG_NL_SHIFT)) & DCU_CORE_CONFIG_NL_MASK)

#define DCU_CORE_CONFIG_BNN_MASK                 (0x4000000U)
#define DCU_CORE_CONFIG_BNN_SHIFT                (26U)
#define DCU_CORE_CONFIG_BNN_WIDTH                (1U)
#define DCU_CORE_CONFIG_BNN(x)                   (((uint32_t)(((uint32_t)(x)) << DCU_CORE_CONFIG_BNN_SHIFT)) & DCU_CORE_CONFIG_BNN_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group DCU_Register_Masks */

/*!
 * @}
 */ /* end of group DCU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_DCU_H_) */
