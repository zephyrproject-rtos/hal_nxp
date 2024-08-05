/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_MEW.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_MEW
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
#if !defined(S32Z2_MEW_H_)  /* Check if memory map has not been already included */
#define S32Z2_MEW_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MEW Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MEW_Peripheral_Access_Layer MEW Peripheral Access Layer
 * @{
 */

/** MEW - Size of Registers Arrays */
#define MEW_ECC_EERDSR_COUNT                      4u

/** MEW - Register Layout Typedef */
typedef struct {
  __IO uint32_t ECC_GLBL_CTRL;                     /**< AXI ECC Global Control, offset: 0x0 */
  __IO uint32_t ECC_MX_EPA;                        /**< AXI ECC Maximum ECC Protected Address, offset: 0x4 */
  __IO uint32_t ECC_MN_EPA;                        /**< AXI ECC Minimum ECC Protected Address, offset: 0x8 */
  __IO uint32_t ECC_LK_PTN;                        /**< AXI ECC Lock Pattern, offset: 0xC */
  __IO uint32_t ECC_ULK_PTN;                       /**< AXI ECC Unlock Pattern, offset: 0x10 */
  uint8_t RESERVED_0[4];
  __I  uint32_t ECC_EERAR;                         /**< ECC Error Report Address, offset: 0x18 */
  __I  uint32_t ECC_EERDSR[MEW_ECC_EERDSR_COUNT];  /**< AXI ECC Error Report Data And Syndrome, array offset: 0x1C, array step: 0x4 */
  __IO uint32_t ECC_ERR_IE;                        /**< AXI ECC Error Interrupt Enable, offset: 0x2C */
  __IO uint32_t ECC_ERR_IN_STCLR;                  /**< AXI ECC Error Interupt Status And Clear, offset: 0x30 */
  __IO uint32_t EDC_ERR_IE;                        /**< AXI EDC Error Interrupt Enable, offset: 0x34 */
  __IO uint32_t EDC_ERR_IN_STCLR;                  /**< AXI EDC Error Interrupt Status And Clear, offset: 0x38 */
  uint8_t RESERVED_1[4];
  __IO uint32_t ECC_SHD_STAT_CTRL;                 /**< Shadow Control, RW Path Status And Status Clear, offset: 0x40 */
  __I  uint32_t ECC_CBL_UNCBL_BIT_EC;              /**< Correctable And Uncorrectable Bit Error Counter, offset: 0x44 */
  __I  uint32_t ECC_CBL_UCBL_BEAT_EC;              /**< Correctable And Uncorrectable Beat Error Counter, offset: 0x48 */
  uint8_t RESERVED_2[52];
  __IO uint32_t ECC_DBG_CTRL;                      /**< Debug And Debug Control, offset: 0x80 */
} MEW_Type, *MEW_MemMapPtr;

/** Number of instances of the MEW module. */
#define MEW_INSTANCE_COUNT                       (2u)

/* MEW - Peripheral instance base addresses */
/** Peripheral MEW_0_AXI base address */
#define IP_MEW_0_AXI_BASE                        (0x42380000u)
/** Peripheral MEW_0_AXI base pointer */
#define IP_MEW_0_AXI                             ((MEW_Type *)IP_MEW_0_AXI_BASE)
/** Peripheral MEW_1_AXI base address */
#define IP_MEW_1_AXI_BASE                        (0x42390000u)
/** Peripheral MEW_1_AXI base pointer */
#define IP_MEW_1_AXI                             ((MEW_Type *)IP_MEW_1_AXI_BASE)
/** Array initializer of MEW peripheral base addresses */
#define IP_MEW_BASE_ADDRS                        { IP_MEW_0_AXI_BASE, IP_MEW_1_AXI_BASE }
/** Array initializer of MEW peripheral base pointers */
#define IP_MEW_BASE_PTRS                         { IP_MEW_0_AXI, IP_MEW_1_AXI }

/* ----------------------------------------------------------------------------
   -- MEW Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MEW_Register_Masks MEW Register Masks
 * @{
 */

/*! @name ECC_GLBL_CTRL - AXI ECC Global Control */
/*! @{ */

#define MEW_ECC_GLBL_CTRL_RD_EN_MASK             (0x1U)
#define MEW_ECC_GLBL_CTRL_RD_EN_SHIFT            (0U)
#define MEW_ECC_GLBL_CTRL_RD_EN_WIDTH            (1U)
#define MEW_ECC_GLBL_CTRL_RD_EN(x)               (((uint32_t)(((uint32_t)(x)) << MEW_ECC_GLBL_CTRL_RD_EN_SHIFT)) & MEW_ECC_GLBL_CTRL_RD_EN_MASK)

#define MEW_ECC_GLBL_CTRL_RD_EDCEN_MASK          (0x8U)
#define MEW_ECC_GLBL_CTRL_RD_EDCEN_SHIFT         (3U)
#define MEW_ECC_GLBL_CTRL_RD_EDCEN_WIDTH         (1U)
#define MEW_ECC_GLBL_CTRL_RD_EDCEN(x)            (((uint32_t)(((uint32_t)(x)) << MEW_ECC_GLBL_CTRL_RD_EDCEN_SHIFT)) & MEW_ECC_GLBL_CTRL_RD_EDCEN_MASK)

#define MEW_ECC_GLBL_CTRL_WR_EN_MASK             (0x10000U)
#define MEW_ECC_GLBL_CTRL_WR_EN_SHIFT            (16U)
#define MEW_ECC_GLBL_CTRL_WR_EN_WIDTH            (1U)
#define MEW_ECC_GLBL_CTRL_WR_EN(x)               (((uint32_t)(((uint32_t)(x)) << MEW_ECC_GLBL_CTRL_WR_EN_SHIFT)) & MEW_ECC_GLBL_CTRL_WR_EN_MASK)

#define MEW_ECC_GLBL_CTRL_WR_EDCEN_MASK          (0x80000U)
#define MEW_ECC_GLBL_CTRL_WR_EDCEN_SHIFT         (19U)
#define MEW_ECC_GLBL_CTRL_WR_EDCEN_WIDTH         (1U)
#define MEW_ECC_GLBL_CTRL_WR_EDCEN(x)            (((uint32_t)(((uint32_t)(x)) << MEW_ECC_GLBL_CTRL_WR_EDCEN_SHIFT)) & MEW_ECC_GLBL_CTRL_WR_EDCEN_MASK)
/*! @} */

/*! @name ECC_MX_EPA - AXI ECC Maximum ECC Protected Address */
/*! @{ */

#define MEW_ECC_MX_EPA_MX_EPA_MASK               (0xFFFFFFFFU)
#define MEW_ECC_MX_EPA_MX_EPA_SHIFT              (0U)
#define MEW_ECC_MX_EPA_MX_EPA_WIDTH              (32U)
#define MEW_ECC_MX_EPA_MX_EPA(x)                 (((uint32_t)(((uint32_t)(x)) << MEW_ECC_MX_EPA_MX_EPA_SHIFT)) & MEW_ECC_MX_EPA_MX_EPA_MASK)
/*! @} */

/*! @name ECC_MN_EPA - AXI ECC Minimum ECC Protected Address */
/*! @{ */

#define MEW_ECC_MN_EPA_MN_EPA_MASK               (0xFFFFFFFFU)
#define MEW_ECC_MN_EPA_MN_EPA_SHIFT              (0U)
#define MEW_ECC_MN_EPA_MN_EPA_WIDTH              (32U)
#define MEW_ECC_MN_EPA_MN_EPA(x)                 (((uint32_t)(((uint32_t)(x)) << MEW_ECC_MN_EPA_MN_EPA_SHIFT)) & MEW_ECC_MN_EPA_MN_EPA_MASK)
/*! @} */

/*! @name ECC_LK_PTN - AXI ECC Lock Pattern */
/*! @{ */

#define MEW_ECC_LK_PTN_LK_PTN_MASK               (0xFFFFFFFFU)
#define MEW_ECC_LK_PTN_LK_PTN_SHIFT              (0U)
#define MEW_ECC_LK_PTN_LK_PTN_WIDTH              (32U)
#define MEW_ECC_LK_PTN_LK_PTN(x)                 (((uint32_t)(((uint32_t)(x)) << MEW_ECC_LK_PTN_LK_PTN_SHIFT)) & MEW_ECC_LK_PTN_LK_PTN_MASK)
/*! @} */

/*! @name ECC_ULK_PTN - AXI ECC Unlock Pattern */
/*! @{ */

#define MEW_ECC_ULK_PTN_ULK_PTN_MASK             (0xFFFFFFFFU)
#define MEW_ECC_ULK_PTN_ULK_PTN_SHIFT            (0U)
#define MEW_ECC_ULK_PTN_ULK_PTN_WIDTH            (32U)
#define MEW_ECC_ULK_PTN_ULK_PTN(x)               (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ULK_PTN_ULK_PTN_SHIFT)) & MEW_ECC_ULK_PTN_ULK_PTN_MASK)
/*! @} */

/*! @name ECC_EERAR - ECC Error Report Address */
/*! @{ */

#define MEW_ECC_EERAR_EERA_MASK                  (0xFFFFFFFFU)
#define MEW_ECC_EERAR_EERA_SHIFT                 (0U)
#define MEW_ECC_EERAR_EERA_WIDTH                 (32U)
#define MEW_ECC_EERAR_EERA(x)                    (((uint32_t)(((uint32_t)(x)) << MEW_ECC_EERAR_EERA_SHIFT)) & MEW_ECC_EERAR_EERA_MASK)
/*! @} */

/*! @name ECC_EERDSR - AXI ECC Error Report Data And Syndrome */
/*! @{ */

#define MEW_ECC_EERDSR_EERD_MASK                 (0xFFU)
#define MEW_ECC_EERDSR_EERD_SHIFT                (0U)
#define MEW_ECC_EERDSR_EERD_WIDTH                (8U)
#define MEW_ECC_EERDSR_EERD(x)                   (((uint32_t)(((uint32_t)(x)) << MEW_ECC_EERDSR_EERD_SHIFT)) & MEW_ECC_EERDSR_EERD_MASK)

#define MEW_ECC_EERDSR_EECC_MASK                 (0xFF00U)
#define MEW_ECC_EERDSR_EECC_SHIFT                (8U)
#define MEW_ECC_EERDSR_EECC_WIDTH                (8U)
#define MEW_ECC_EERDSR_EECC(x)                   (((uint32_t)(((uint32_t)(x)) << MEW_ECC_EERDSR_EECC_SHIFT)) & MEW_ECC_EERDSR_EECC_MASK)

#define MEW_ECC_EERDSR_EERS_MASK                 (0xFF0000U)
#define MEW_ECC_EERDSR_EERS_SHIFT                (16U)
#define MEW_ECC_EERDSR_EERS_WIDTH                (8U)
#define MEW_ECC_EERDSR_EERS(x)                   (((uint32_t)(((uint32_t)(x)) << MEW_ECC_EERDSR_EERS_SHIFT)) & MEW_ECC_EERDSR_EERS_MASK)
/*! @} */

/*! @name ECC_ERR_IE - AXI ECC Error Interrupt Enable */
/*! @{ */

#define MEW_ECC_ERR_IE_NCE_IE1_MASK              (0x1U)
#define MEW_ECC_ERR_IE_NCE_IE1_SHIFT             (0U)
#define MEW_ECC_ERR_IE_NCE_IE1_WIDTH             (1U)
#define MEW_ECC_ERR_IE_NCE_IE1(x)                (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IE_NCE_IE1_SHIFT)) & MEW_ECC_ERR_IE_NCE_IE1_MASK)

#define MEW_ECC_ERR_IE_NCE_IE2_MASK              (0x2U)
#define MEW_ECC_ERR_IE_NCE_IE2_SHIFT             (1U)
#define MEW_ECC_ERR_IE_NCE_IE2_WIDTH             (1U)
#define MEW_ECC_ERR_IE_NCE_IE2(x)                (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IE_NCE_IE2_SHIFT)) & MEW_ECC_ERR_IE_NCE_IE2_MASK)

#define MEW_ECC_ERR_IE_NCE_IE3_MASK              (0x4U)
#define MEW_ECC_ERR_IE_NCE_IE3_SHIFT             (2U)
#define MEW_ECC_ERR_IE_NCE_IE3_WIDTH             (1U)
#define MEW_ECC_ERR_IE_NCE_IE3(x)                (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IE_NCE_IE3_SHIFT)) & MEW_ECC_ERR_IE_NCE_IE3_MASK)

#define MEW_ECC_ERR_IE_NCE_IE4_MASK              (0x8U)
#define MEW_ECC_ERR_IE_NCE_IE4_SHIFT             (3U)
#define MEW_ECC_ERR_IE_NCE_IE4_WIDTH             (1U)
#define MEW_ECC_ERR_IE_NCE_IE4(x)                (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IE_NCE_IE4_SHIFT)) & MEW_ECC_ERR_IE_NCE_IE4_MASK)

#define MEW_ECC_ERR_IE_CE_IE1_MASK               (0x10000U)
#define MEW_ECC_ERR_IE_CE_IE1_SHIFT              (16U)
#define MEW_ECC_ERR_IE_CE_IE1_WIDTH              (1U)
#define MEW_ECC_ERR_IE_CE_IE1(x)                 (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IE_CE_IE1_SHIFT)) & MEW_ECC_ERR_IE_CE_IE1_MASK)

#define MEW_ECC_ERR_IE_CE_IE2_MASK               (0x20000U)
#define MEW_ECC_ERR_IE_CE_IE2_SHIFT              (17U)
#define MEW_ECC_ERR_IE_CE_IE2_WIDTH              (1U)
#define MEW_ECC_ERR_IE_CE_IE2(x)                 (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IE_CE_IE2_SHIFT)) & MEW_ECC_ERR_IE_CE_IE2_MASK)

#define MEW_ECC_ERR_IE_CE_IE3_MASK               (0x40000U)
#define MEW_ECC_ERR_IE_CE_IE3_SHIFT              (18U)
#define MEW_ECC_ERR_IE_CE_IE3_WIDTH              (1U)
#define MEW_ECC_ERR_IE_CE_IE3(x)                 (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IE_CE_IE3_SHIFT)) & MEW_ECC_ERR_IE_CE_IE3_MASK)

#define MEW_ECC_ERR_IE_CE_IE4_MASK               (0x80000U)
#define MEW_ECC_ERR_IE_CE_IE4_SHIFT              (19U)
#define MEW_ECC_ERR_IE_CE_IE4_WIDTH              (1U)
#define MEW_ECC_ERR_IE_CE_IE4(x)                 (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IE_CE_IE4_SHIFT)) & MEW_ECC_ERR_IE_CE_IE4_MASK)
/*! @} */

/*! @name ECC_ERR_IN_STCLR - AXI ECC Error Interupt Status And Clear */
/*! @{ */

#define MEW_ECC_ERR_IN_STCLR_NCE_IF1_MASK        (0x1U)
#define MEW_ECC_ERR_IN_STCLR_NCE_IF1_SHIFT       (0U)
#define MEW_ECC_ERR_IN_STCLR_NCE_IF1_WIDTH       (1U)
#define MEW_ECC_ERR_IN_STCLR_NCE_IF1(x)          (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IN_STCLR_NCE_IF1_SHIFT)) & MEW_ECC_ERR_IN_STCLR_NCE_IF1_MASK)

#define MEW_ECC_ERR_IN_STCLR_NCE_IF2_MASK        (0x2U)
#define MEW_ECC_ERR_IN_STCLR_NCE_IF2_SHIFT       (1U)
#define MEW_ECC_ERR_IN_STCLR_NCE_IF2_WIDTH       (1U)
#define MEW_ECC_ERR_IN_STCLR_NCE_IF2(x)          (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IN_STCLR_NCE_IF2_SHIFT)) & MEW_ECC_ERR_IN_STCLR_NCE_IF2_MASK)

#define MEW_ECC_ERR_IN_STCLR_NCE_IF3_MASK        (0x4U)
#define MEW_ECC_ERR_IN_STCLR_NCE_IF3_SHIFT       (2U)
#define MEW_ECC_ERR_IN_STCLR_NCE_IF3_WIDTH       (1U)
#define MEW_ECC_ERR_IN_STCLR_NCE_IF3(x)          (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IN_STCLR_NCE_IF3_SHIFT)) & MEW_ECC_ERR_IN_STCLR_NCE_IF3_MASK)

#define MEW_ECC_ERR_IN_STCLR_NCE_IF4_MASK        (0x8U)
#define MEW_ECC_ERR_IN_STCLR_NCE_IF4_SHIFT       (3U)
#define MEW_ECC_ERR_IN_STCLR_NCE_IF4_WIDTH       (1U)
#define MEW_ECC_ERR_IN_STCLR_NCE_IF4(x)          (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IN_STCLR_NCE_IF4_SHIFT)) & MEW_ECC_ERR_IN_STCLR_NCE_IF4_MASK)

#define MEW_ECC_ERR_IN_STCLR_CE_IF1_MASK         (0x10000U)
#define MEW_ECC_ERR_IN_STCLR_CE_IF1_SHIFT        (16U)
#define MEW_ECC_ERR_IN_STCLR_CE_IF1_WIDTH        (1U)
#define MEW_ECC_ERR_IN_STCLR_CE_IF1(x)           (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IN_STCLR_CE_IF1_SHIFT)) & MEW_ECC_ERR_IN_STCLR_CE_IF1_MASK)

#define MEW_ECC_ERR_IN_STCLR_CE_IF2_MASK         (0x20000U)
#define MEW_ECC_ERR_IN_STCLR_CE_IF2_SHIFT        (17U)
#define MEW_ECC_ERR_IN_STCLR_CE_IF2_WIDTH        (1U)
#define MEW_ECC_ERR_IN_STCLR_CE_IF2(x)           (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IN_STCLR_CE_IF2_SHIFT)) & MEW_ECC_ERR_IN_STCLR_CE_IF2_MASK)

#define MEW_ECC_ERR_IN_STCLR_CE_IF3_MASK         (0x40000U)
#define MEW_ECC_ERR_IN_STCLR_CE_IF3_SHIFT        (18U)
#define MEW_ECC_ERR_IN_STCLR_CE_IF3_WIDTH        (1U)
#define MEW_ECC_ERR_IN_STCLR_CE_IF3(x)           (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IN_STCLR_CE_IF3_SHIFT)) & MEW_ECC_ERR_IN_STCLR_CE_IF3_MASK)

#define MEW_ECC_ERR_IN_STCLR_CE_IF4_MASK         (0x80000U)
#define MEW_ECC_ERR_IN_STCLR_CE_IF4_SHIFT        (19U)
#define MEW_ECC_ERR_IN_STCLR_CE_IF4_WIDTH        (1U)
#define MEW_ECC_ERR_IN_STCLR_CE_IF4(x)           (((uint32_t)(((uint32_t)(x)) << MEW_ECC_ERR_IN_STCLR_CE_IF4_SHIFT)) & MEW_ECC_ERR_IN_STCLR_CE_IF4_MASK)
/*! @} */

/*! @name EDC_ERR_IE - AXI EDC Error Interrupt Enable */
/*! @{ */

#define MEW_EDC_ERR_IE_EDC_EIE1_MASK             (0x1U)
#define MEW_EDC_ERR_IE_EDC_EIE1_SHIFT            (0U)
#define MEW_EDC_ERR_IE_EDC_EIE1_WIDTH            (1U)
#define MEW_EDC_ERR_IE_EDC_EIE1(x)               (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IE_EDC_EIE1_SHIFT)) & MEW_EDC_ERR_IE_EDC_EIE1_MASK)

#define MEW_EDC_ERR_IE_EDC_EIE2_MASK             (0x2U)
#define MEW_EDC_ERR_IE_EDC_EIE2_SHIFT            (1U)
#define MEW_EDC_ERR_IE_EDC_EIE2_WIDTH            (1U)
#define MEW_EDC_ERR_IE_EDC_EIE2(x)               (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IE_EDC_EIE2_SHIFT)) & MEW_EDC_ERR_IE_EDC_EIE2_MASK)

#define MEW_EDC_ERR_IE_EDC_EIE3_MASK             (0x4U)
#define MEW_EDC_ERR_IE_EDC_EIE3_SHIFT            (2U)
#define MEW_EDC_ERR_IE_EDC_EIE3_WIDTH            (1U)
#define MEW_EDC_ERR_IE_EDC_EIE3(x)               (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IE_EDC_EIE3_SHIFT)) & MEW_EDC_ERR_IE_EDC_EIE3_MASK)

#define MEW_EDC_ERR_IE_EDC_EIE4_MASK             (0x8U)
#define MEW_EDC_ERR_IE_EDC_EIE4_SHIFT            (3U)
#define MEW_EDC_ERR_IE_EDC_EIE4_WIDTH            (1U)
#define MEW_EDC_ERR_IE_EDC_EIE4(x)               (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IE_EDC_EIE4_SHIFT)) & MEW_EDC_ERR_IE_EDC_EIE4_MASK)

#define MEW_EDC_ERR_IE_EDC_DIE1_MASK             (0x10000U)
#define MEW_EDC_ERR_IE_EDC_DIE1_SHIFT            (16U)
#define MEW_EDC_ERR_IE_EDC_DIE1_WIDTH            (1U)
#define MEW_EDC_ERR_IE_EDC_DIE1(x)               (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IE_EDC_DIE1_SHIFT)) & MEW_EDC_ERR_IE_EDC_DIE1_MASK)

#define MEW_EDC_ERR_IE_EDC_DIE2_MASK             (0x20000U)
#define MEW_EDC_ERR_IE_EDC_DIE2_SHIFT            (17U)
#define MEW_EDC_ERR_IE_EDC_DIE2_WIDTH            (1U)
#define MEW_EDC_ERR_IE_EDC_DIE2(x)               (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IE_EDC_DIE2_SHIFT)) & MEW_EDC_ERR_IE_EDC_DIE2_MASK)

#define MEW_EDC_ERR_IE_EDC_DIE3_MASK             (0x40000U)
#define MEW_EDC_ERR_IE_EDC_DIE3_SHIFT            (18U)
#define MEW_EDC_ERR_IE_EDC_DIE3_WIDTH            (1U)
#define MEW_EDC_ERR_IE_EDC_DIE3(x)               (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IE_EDC_DIE3_SHIFT)) & MEW_EDC_ERR_IE_EDC_DIE3_MASK)

#define MEW_EDC_ERR_IE_EDC_DIE4_MASK             (0x80000U)
#define MEW_EDC_ERR_IE_EDC_DIE4_SHIFT            (19U)
#define MEW_EDC_ERR_IE_EDC_DIE4_WIDTH            (1U)
#define MEW_EDC_ERR_IE_EDC_DIE4(x)               (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IE_EDC_DIE4_SHIFT)) & MEW_EDC_ERR_IE_EDC_DIE4_MASK)
/*! @} */

/*! @name EDC_ERR_IN_STCLR - AXI EDC Error Interrupt Status And Clear */
/*! @{ */

#define MEW_EDC_ERR_IN_STCLR_EDC_ENC1_MASK       (0x1U)
#define MEW_EDC_ERR_IN_STCLR_EDC_ENC1_SHIFT      (0U)
#define MEW_EDC_ERR_IN_STCLR_EDC_ENC1_WIDTH      (1U)
#define MEW_EDC_ERR_IN_STCLR_EDC_ENC1(x)         (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IN_STCLR_EDC_ENC1_SHIFT)) & MEW_EDC_ERR_IN_STCLR_EDC_ENC1_MASK)

#define MEW_EDC_ERR_IN_STCLR_EDC_ENC2_MASK       (0x2U)
#define MEW_EDC_ERR_IN_STCLR_EDC_ENC2_SHIFT      (1U)
#define MEW_EDC_ERR_IN_STCLR_EDC_ENC2_WIDTH      (1U)
#define MEW_EDC_ERR_IN_STCLR_EDC_ENC2(x)         (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IN_STCLR_EDC_ENC2_SHIFT)) & MEW_EDC_ERR_IN_STCLR_EDC_ENC2_MASK)

#define MEW_EDC_ERR_IN_STCLR_EDC_ENC3_MASK       (0x4U)
#define MEW_EDC_ERR_IN_STCLR_EDC_ENC3_SHIFT      (2U)
#define MEW_EDC_ERR_IN_STCLR_EDC_ENC3_WIDTH      (1U)
#define MEW_EDC_ERR_IN_STCLR_EDC_ENC3(x)         (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IN_STCLR_EDC_ENC3_SHIFT)) & MEW_EDC_ERR_IN_STCLR_EDC_ENC3_MASK)

#define MEW_EDC_ERR_IN_STCLR_EDC_ENC4_MASK       (0x8U)
#define MEW_EDC_ERR_IN_STCLR_EDC_ENC4_SHIFT      (3U)
#define MEW_EDC_ERR_IN_STCLR_EDC_ENC4_WIDTH      (1U)
#define MEW_EDC_ERR_IN_STCLR_EDC_ENC4(x)         (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IN_STCLR_EDC_ENC4_SHIFT)) & MEW_EDC_ERR_IN_STCLR_EDC_ENC4_MASK)

#define MEW_EDC_ERR_IN_STCLR_EDC_DEC1_MASK       (0x10000U)
#define MEW_EDC_ERR_IN_STCLR_EDC_DEC1_SHIFT      (16U)
#define MEW_EDC_ERR_IN_STCLR_EDC_DEC1_WIDTH      (1U)
#define MEW_EDC_ERR_IN_STCLR_EDC_DEC1(x)         (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IN_STCLR_EDC_DEC1_SHIFT)) & MEW_EDC_ERR_IN_STCLR_EDC_DEC1_MASK)

#define MEW_EDC_ERR_IN_STCLR_EDC_DEC2_MASK       (0x20000U)
#define MEW_EDC_ERR_IN_STCLR_EDC_DEC2_SHIFT      (17U)
#define MEW_EDC_ERR_IN_STCLR_EDC_DEC2_WIDTH      (1U)
#define MEW_EDC_ERR_IN_STCLR_EDC_DEC2(x)         (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IN_STCLR_EDC_DEC2_SHIFT)) & MEW_EDC_ERR_IN_STCLR_EDC_DEC2_MASK)

#define MEW_EDC_ERR_IN_STCLR_EDC_DEC3_MASK       (0x40000U)
#define MEW_EDC_ERR_IN_STCLR_EDC_DEC3_SHIFT      (18U)
#define MEW_EDC_ERR_IN_STCLR_EDC_DEC3_WIDTH      (1U)
#define MEW_EDC_ERR_IN_STCLR_EDC_DEC3(x)         (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IN_STCLR_EDC_DEC3_SHIFT)) & MEW_EDC_ERR_IN_STCLR_EDC_DEC3_MASK)

#define MEW_EDC_ERR_IN_STCLR_EDC_DEC4_MASK       (0x80000U)
#define MEW_EDC_ERR_IN_STCLR_EDC_DEC4_SHIFT      (19U)
#define MEW_EDC_ERR_IN_STCLR_EDC_DEC4_WIDTH      (1U)
#define MEW_EDC_ERR_IN_STCLR_EDC_DEC4(x)         (((uint32_t)(((uint32_t)(x)) << MEW_EDC_ERR_IN_STCLR_EDC_DEC4_SHIFT)) & MEW_EDC_ERR_IN_STCLR_EDC_DEC4_MASK)
/*! @} */

/*! @name ECC_SHD_STAT_CTRL - Shadow Control, RW Path Status And Status Clear */
/*! @{ */

#define MEW_ECC_SHD_STAT_CTRL_STAT_CLR_MASK      (0x1U)
#define MEW_ECC_SHD_STAT_CTRL_STAT_CLR_SHIFT     (0U)
#define MEW_ECC_SHD_STAT_CTRL_STAT_CLR_WIDTH     (1U)
#define MEW_ECC_SHD_STAT_CTRL_STAT_CLR(x)        (((uint32_t)(((uint32_t)(x)) << MEW_ECC_SHD_STAT_CTRL_STAT_CLR_SHIFT)) & MEW_ECC_SHD_STAT_CTRL_STAT_CLR_MASK)

#define MEW_ECC_SHD_STAT_CTRL_COUNT_CLR_MASK     (0x2U)
#define MEW_ECC_SHD_STAT_CTRL_COUNT_CLR_SHIFT    (1U)
#define MEW_ECC_SHD_STAT_CTRL_COUNT_CLR_WIDTH    (1U)
#define MEW_ECC_SHD_STAT_CTRL_COUNT_CLR(x)       (((uint32_t)(((uint32_t)(x)) << MEW_ECC_SHD_STAT_CTRL_COUNT_CLR_SHIFT)) & MEW_ECC_SHD_STAT_CTRL_COUNT_CLR_MASK)

#define MEW_ECC_SHD_STAT_CTRL_RD_TX_FULL_MASK    (0x100U)
#define MEW_ECC_SHD_STAT_CTRL_RD_TX_FULL_SHIFT   (8U)
#define MEW_ECC_SHD_STAT_CTRL_RD_TX_FULL_WIDTH   (1U)
#define MEW_ECC_SHD_STAT_CTRL_RD_TX_FULL(x)      (((uint32_t)(((uint32_t)(x)) << MEW_ECC_SHD_STAT_CTRL_RD_TX_FULL_SHIFT)) & MEW_ECC_SHD_STAT_CTRL_RD_TX_FULL_MASK)

#define MEW_ECC_SHD_STAT_CTRL_WR_TX_FULL_MASK    (0x200U)
#define MEW_ECC_SHD_STAT_CTRL_WR_TX_FULL_SHIFT   (9U)
#define MEW_ECC_SHD_STAT_CTRL_WR_TX_FULL_WIDTH   (1U)
#define MEW_ECC_SHD_STAT_CTRL_WR_TX_FULL(x)      (((uint32_t)(((uint32_t)(x)) << MEW_ECC_SHD_STAT_CTRL_WR_TX_FULL_SHIFT)) & MEW_ECC_SHD_STAT_CTRL_WR_TX_FULL_MASK)

#define MEW_ECC_SHD_STAT_CTRL_WR_RES_FULL_MASK   (0x400U)
#define MEW_ECC_SHD_STAT_CTRL_WR_RES_FULL_SHIFT  (10U)
#define MEW_ECC_SHD_STAT_CTRL_WR_RES_FULL_WIDTH  (1U)
#define MEW_ECC_SHD_STAT_CTRL_WR_RES_FULL(x)     (((uint32_t)(((uint32_t)(x)) << MEW_ECC_SHD_STAT_CTRL_WR_RES_FULL_SHIFT)) & MEW_ECC_SHD_STAT_CTRL_WR_RES_FULL_MASK)

#define MEW_ECC_SHD_STAT_CTRL_RD_TX_EMP_MASK     (0x10000U)
#define MEW_ECC_SHD_STAT_CTRL_RD_TX_EMP_SHIFT    (16U)
#define MEW_ECC_SHD_STAT_CTRL_RD_TX_EMP_WIDTH    (1U)
#define MEW_ECC_SHD_STAT_CTRL_RD_TX_EMP(x)       (((uint32_t)(((uint32_t)(x)) << MEW_ECC_SHD_STAT_CTRL_RD_TX_EMP_SHIFT)) & MEW_ECC_SHD_STAT_CTRL_RD_TX_EMP_MASK)

#define MEW_ECC_SHD_STAT_CTRL_WR_TX_EMP_MASK     (0x20000U)
#define MEW_ECC_SHD_STAT_CTRL_WR_TX_EMP_SHIFT    (17U)
#define MEW_ECC_SHD_STAT_CTRL_WR_TX_EMP_WIDTH    (1U)
#define MEW_ECC_SHD_STAT_CTRL_WR_TX_EMP(x)       (((uint32_t)(((uint32_t)(x)) << MEW_ECC_SHD_STAT_CTRL_WR_TX_EMP_SHIFT)) & MEW_ECC_SHD_STAT_CTRL_WR_TX_EMP_MASK)

#define MEW_ECC_SHD_STAT_CTRL_WR_RES_EMP_MASK    (0x40000U)
#define MEW_ECC_SHD_STAT_CTRL_WR_RES_EMP_SHIFT   (18U)
#define MEW_ECC_SHD_STAT_CTRL_WR_RES_EMP_WIDTH   (1U)
#define MEW_ECC_SHD_STAT_CTRL_WR_RES_EMP(x)      (((uint32_t)(((uint32_t)(x)) << MEW_ECC_SHD_STAT_CTRL_WR_RES_EMP_SHIFT)) & MEW_ECC_SHD_STAT_CTRL_WR_RES_EMP_MASK)

#define MEW_ECC_SHD_STAT_CTRL_SHD_RGN_SLT_MASK   (0x1000000U)
#define MEW_ECC_SHD_STAT_CTRL_SHD_RGN_SLT_SHIFT  (24U)
#define MEW_ECC_SHD_STAT_CTRL_SHD_RGN_SLT_WIDTH  (1U)
#define MEW_ECC_SHD_STAT_CTRL_SHD_RGN_SLT(x)     (((uint32_t)(((uint32_t)(x)) << MEW_ECC_SHD_STAT_CTRL_SHD_RGN_SLT_SHIFT)) & MEW_ECC_SHD_STAT_CTRL_SHD_RGN_SLT_MASK)
/*! @} */

/*! @name ECC_CBL_UNCBL_BIT_EC - Correctable And Uncorrectable Bit Error Counter */
/*! @{ */

#define MEW_ECC_CBL_UNCBL_BIT_EC_CLB_BIT_EC_MASK (0x7FFFU)
#define MEW_ECC_CBL_UNCBL_BIT_EC_CLB_BIT_EC_SHIFT (0U)
#define MEW_ECC_CBL_UNCBL_BIT_EC_CLB_BIT_EC_WIDTH (15U)
#define MEW_ECC_CBL_UNCBL_BIT_EC_CLB_BIT_EC(x)   (((uint32_t)(((uint32_t)(x)) << MEW_ECC_CBL_UNCBL_BIT_EC_CLB_BIT_EC_SHIFT)) & MEW_ECC_CBL_UNCBL_BIT_EC_CLB_BIT_EC_MASK)

#define MEW_ECC_CBL_UNCBL_BIT_EC_CBL_BIT_OF_MASK (0x8000U)
#define MEW_ECC_CBL_UNCBL_BIT_EC_CBL_BIT_OF_SHIFT (15U)
#define MEW_ECC_CBL_UNCBL_BIT_EC_CBL_BIT_OF_WIDTH (1U)
#define MEW_ECC_CBL_UNCBL_BIT_EC_CBL_BIT_OF(x)   (((uint32_t)(((uint32_t)(x)) << MEW_ECC_CBL_UNCBL_BIT_EC_CBL_BIT_OF_SHIFT)) & MEW_ECC_CBL_UNCBL_BIT_EC_CBL_BIT_OF_MASK)

#define MEW_ECC_CBL_UNCBL_BIT_EC_UCBL_BIT_EC_MASK (0x7FFF0000U)
#define MEW_ECC_CBL_UNCBL_BIT_EC_UCBL_BIT_EC_SHIFT (16U)
#define MEW_ECC_CBL_UNCBL_BIT_EC_UCBL_BIT_EC_WIDTH (15U)
#define MEW_ECC_CBL_UNCBL_BIT_EC_UCBL_BIT_EC(x)  (((uint32_t)(((uint32_t)(x)) << MEW_ECC_CBL_UNCBL_BIT_EC_UCBL_BIT_EC_SHIFT)) & MEW_ECC_CBL_UNCBL_BIT_EC_UCBL_BIT_EC_MASK)

#define MEW_ECC_CBL_UNCBL_BIT_EC_UCBL_BIT_OF_MASK (0x80000000U)
#define MEW_ECC_CBL_UNCBL_BIT_EC_UCBL_BIT_OF_SHIFT (31U)
#define MEW_ECC_CBL_UNCBL_BIT_EC_UCBL_BIT_OF_WIDTH (1U)
#define MEW_ECC_CBL_UNCBL_BIT_EC_UCBL_BIT_OF(x)  (((uint32_t)(((uint32_t)(x)) << MEW_ECC_CBL_UNCBL_BIT_EC_UCBL_BIT_OF_SHIFT)) & MEW_ECC_CBL_UNCBL_BIT_EC_UCBL_BIT_OF_MASK)
/*! @} */

/*! @name ECC_CBL_UCBL_BEAT_EC - Correctable And Uncorrectable Beat Error Counter */
/*! @{ */

#define MEW_ECC_CBL_UCBL_BEAT_EC_CBL_BEAT_EC_MASK (0x7FFFU)
#define MEW_ECC_CBL_UCBL_BEAT_EC_CBL_BEAT_EC_SHIFT (0U)
#define MEW_ECC_CBL_UCBL_BEAT_EC_CBL_BEAT_EC_WIDTH (15U)
#define MEW_ECC_CBL_UCBL_BEAT_EC_CBL_BEAT_EC(x)  (((uint32_t)(((uint32_t)(x)) << MEW_ECC_CBL_UCBL_BEAT_EC_CBL_BEAT_EC_SHIFT)) & MEW_ECC_CBL_UCBL_BEAT_EC_CBL_BEAT_EC_MASK)

#define MEW_ECC_CBL_UCBL_BEAT_EC_CBL_BEAT_OF_MASK (0x8000U)
#define MEW_ECC_CBL_UCBL_BEAT_EC_CBL_BEAT_OF_SHIFT (15U)
#define MEW_ECC_CBL_UCBL_BEAT_EC_CBL_BEAT_OF_WIDTH (1U)
#define MEW_ECC_CBL_UCBL_BEAT_EC_CBL_BEAT_OF(x)  (((uint32_t)(((uint32_t)(x)) << MEW_ECC_CBL_UCBL_BEAT_EC_CBL_BEAT_OF_SHIFT)) & MEW_ECC_CBL_UCBL_BEAT_EC_CBL_BEAT_OF_MASK)

#define MEW_ECC_CBL_UCBL_BEAT_EC_UCBL_BEAT_EC_MASK (0x7FFF0000U)
#define MEW_ECC_CBL_UCBL_BEAT_EC_UCBL_BEAT_EC_SHIFT (16U)
#define MEW_ECC_CBL_UCBL_BEAT_EC_UCBL_BEAT_EC_WIDTH (15U)
#define MEW_ECC_CBL_UCBL_BEAT_EC_UCBL_BEAT_EC(x) (((uint32_t)(((uint32_t)(x)) << MEW_ECC_CBL_UCBL_BEAT_EC_UCBL_BEAT_EC_SHIFT)) & MEW_ECC_CBL_UCBL_BEAT_EC_UCBL_BEAT_EC_MASK)

#define MEW_ECC_CBL_UCBL_BEAT_EC_UCBL_BEAT_OF_MASK (0x80000000U)
#define MEW_ECC_CBL_UCBL_BEAT_EC_UCBL_BEAT_OF_SHIFT (31U)
#define MEW_ECC_CBL_UCBL_BEAT_EC_UCBL_BEAT_OF_WIDTH (1U)
#define MEW_ECC_CBL_UCBL_BEAT_EC_UCBL_BEAT_OF(x) (((uint32_t)(((uint32_t)(x)) << MEW_ECC_CBL_UCBL_BEAT_EC_UCBL_BEAT_OF_SHIFT)) & MEW_ECC_CBL_UCBL_BEAT_EC_UCBL_BEAT_OF_MASK)
/*! @} */

/*! @name ECC_DBG_CTRL - Debug And Debug Control */
/*! @{ */

#define MEW_ECC_DBG_CTRL_ADD_EN_ECC_DIS_MASK     (0x1U)
#define MEW_ECC_DBG_CTRL_ADD_EN_ECC_DIS_SHIFT    (0U)
#define MEW_ECC_DBG_CTRL_ADD_EN_ECC_DIS_WIDTH    (1U)
#define MEW_ECC_DBG_CTRL_ADD_EN_ECC_DIS(x)       (((uint32_t)(((uint32_t)(x)) << MEW_ECC_DBG_CTRL_ADD_EN_ECC_DIS_SHIFT)) & MEW_ECC_DBG_CTRL_ADD_EN_ECC_DIS_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MEW_Register_Masks */

/*!
 * @}
 */ /* end of group MEW_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_MEW_H_) */
