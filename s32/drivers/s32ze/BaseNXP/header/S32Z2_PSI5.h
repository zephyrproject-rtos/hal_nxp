/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_PSI5.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_PSI5
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
#if !defined(S32Z2_PSI5_H_)  /* Check if memory map has not been already included */
#define S32Z2_PSI5_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PSI5 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PSI5_Peripheral_Access_Layer PSI5 Peripheral Access Layer
 * @{
 */

/** PSI5 - Size of Registers Arrays */
#define PSI5_CHANNEL_CH_PMR_COUNT                 32u
#define PSI5_CHANNEL_CH_SFR_COUNT                 6u
#define PSI5_CHANNEL_CH_SFCR_COUNT                6
#define PSI5_CHANNEL_COUNT                        4

/** PSI5 - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[2];
  __IO uint16_t GCR;                               /**< Global Control Register, offset: 0x2 */
  uint8_t RESERVED_1[4];
  struct PSI5_CHANNEL {                            /* offset: 0x8, array step: 0x1C0 */
    __IO uint32_t CH_PCCR;                           /**< PSI5 Channel Control Register, array offset: 0x8, array step: 0x1C0 */
    __IO uint32_t CH_DCR;                            /**< DMA Control Register, array offset: 0xC, array step: 0x1C0 */
    __IO uint32_t CH_DSR;                            /**< DMA Status Register, array offset: 0x10, array step: 0x1C0 */
    __IO uint32_t CH_GICR;                           /**< General Interrupt Control Register, array offset: 0x14, array step: 0x1C0 */
    __IO uint32_t CH_NDICR;                          /**< New Data Interrupt Control Register, array offset: 0x18, array step: 0x1C0 */
    __IO uint32_t CH_OWICR;                          /**< Overwrite Interrupt Control Register, array offset: 0x1C, array step: 0x1C0 */
    __IO uint32_t CH_EICR;                           /**< Error Interrupt Control Register, array offset: 0x20, array step: 0x1C0 */
    __IO uint32_t CH_GISR;                           /**< General Interrupt Status Register, array offset: 0x24, array step: 0x1C0 */
    __I  uint32_t CH_DPMR;                           /**< DMA PSI5 Message Register, array offset: 0x28, array step: 0x1C0 */
    __I  uint32_t CH_DSFR;                           /**< DMA SMC Frame Register, array offset: 0x2C, array step: 0x1C0 */
    __I  uint32_t CH_DDSR;                           /**< DMA Diagnostic Status Register, array offset: 0x30, array step: 0x1C0 */
    __I  uint32_t CH_PMRRL;                          /**< PSI5 Message Receive Register Low, array offset: 0x34, array step: 0x1C0 */
    __I  uint32_t CH_PMRRH;                          /**< PSI5 Message Receive Register High, array offset: 0x38, array step: 0x1C0 */
    struct PSI5_CHANNEL_CH_PMR {                     /* offset: 0x3C, array step: index*0x1C0, index2*0x8 */
      __IO uint32_t CH_PMRL;                           /**< PSI5 Message Register Low i, array offset: 0x3C, array step: index*0x1C0, index2*0x8 */
      __IO uint32_t CH_PMRH;                           /**< PSI5 Message Register High i, array offset: 0x40, array step: index*0x1C0, index2*0x8 */
    } CH_PMR[PSI5_CHANNEL_CH_PMR_COUNT];
    __IO uint32_t CH_SFR[PSI5_CHANNEL_CH_SFR_COUNT];   /**< SMC Frame Register n, array offset: 0x13C, array step: index*0x1C0, index2*0x4 */
    __IO uint32_t CH_NDSR;                           /**< New Data Status Register, array offset: 0x154, array step: 0x1C0 */
    __IO uint32_t CH_OWSR;                           /**< Overwrite Status Register, array offset: 0x158, array step: 0x1C0 */
    __IO uint32_t CH_EISR;                           /**< Error Indication Status Register, array offset: 0x15C, array step: 0x1C0 */
    __O  uint32_t CH_SNDSR;                          /**< Set New Data Status Register, array offset: 0x160, array step: 0x1C0 */
    __O  uint32_t CH_SOWSR;                          /**< Set Overwrite Status Register, array offset: 0x164, array step: 0x1C0 */
    __O  uint32_t CH_SEISR;                          /**< Set Error Status Register, array offset: 0x168, array step: 0x1C0 */
    __O  uint32_t CH_SSESR;                          /**< Set SMC Error Status Register, array offset: 0x16C, array step: 0x1C0 */
    __I  uint32_t CH_STSRR;                          /**< Sync Time Stamp Read Register, array offset: 0x170, array step: 0x1C0 */
    __I  uint32_t CH_DTSRR;                          /**< Data Time Stamp Read Register, array offset: 0x174, array step: 0x1C0 */
    __IO uint32_t CH_SFCR[PSI5_CHANNEL_CH_SFCR_COUNT];   /**< Slot n Frame Configuration Register, array offset: 0x178, array step: index*0x1C0, index2*0x4 */
    __IO uint16_t CH_S2SBR;                          /**< Slot 2 Start Boundary Register, array offset: 0x190, array step: 0x1C0 */
    __IO uint16_t CH_S1SBR;                          /**< Slot 1 Start Boundary Register, array offset: 0x192, array step: 0x1C0 */
    __IO uint16_t CH_S4SBR;                          /**< Slot 4 Start Boundary Register, array offset: 0x194, array step: 0x1C0 */
    __IO uint16_t CH_S3SBR;                          /**< Slot 3 Start Boundary Register, array offset: 0x196, array step: 0x1C0 */
    __IO uint16_t CH_S6SBR;                          /**< Slot 6 Start Boundary Register, array offset: 0x198, array step: 0x1C0 */
    __IO uint16_t CH_S5SBR;                          /**< Slot 5 Start Boundary Register, array offset: 0x19A, array step: 0x1C0 */
    __IO uint32_t CH_SNEBR;                          /**< Slot n End Boundary Register, array offset: 0x19C, array step: 0x1C0 */
    __IO uint16_t CH_MDDIS_OFF;                      /**< Manchestor Decoder Disable Offset, array offset: 0x1A0, array step: 0x1C0 */
    __IO uint16_t CH_DOBCR;                          /**< Data Output Block Configuration Register, array offset: 0x1A2, array step: 0x1C0 */
    __IO uint16_t CH_PW1D;                           /**< Pulse Width for Data Bit Value 1, array offset: 0x1A4, array step: 0x1C0 */
    __IO uint16_t CH_PW0D;                           /**< Pulse Width for Data Bit Value 0, array offset: 0x1A6, array step: 0x1C0 */
    __IO uint16_t CH_CIPR;                           /**< Counter Initialize Pulse Register, array offset: 0x1A8, array step: 0x1C0 */
    __IO uint16_t CH_CTPR;                           /**< Counter Target Pulse Register, array offset: 0x1AA, array step: 0x1C0 */
    __IO uint32_t CH_DPRL;                           /**< Data Preparation Register Low, array offset: 0x1AC, array step: 0x1C0 */
         uint32_t CH_DPRH;                           /**< Data Preparation Register High, array offset: 0x1B0, array step: 0x1C0 */
    __IO uint32_t CH_DBRL;                           /**< Data Buffer Register Low, array offset: 0x1B4, array step: 0x1C0 */
    __IO uint32_t CH_DBRH;                           /**< Data Buffer Register High, array offset: 0x1B8, array step: 0x1C0 */
    __IO uint32_t CH_DSRL;                           /**< Data Shift Register Low, array offset: 0x1BC, array step: 0x1C0 */
    __IO uint32_t CH_DSRH;                           /**< Data Shift Register High, array offset: 0x1C0, array step: 0x1C0 */
    uint8_t RESERVED_0[4];
  } CHANNEL[PSI5_CHANNEL_COUNT];
} PSI5_Type, *PSI5_MemMapPtr;

/** Number of instances of the PSI5 module. */
#define PSI5_INSTANCE_COUNT                      2

/* PSI5 - Peripheral instance base addresses */
/** Peripheral PSI5_0 base address */
#define IP_PSI5_0_BASE                           (0x401E0000u)
/** Peripheral PSI5_0 base pointer */
#define IP_PSI5_0                                ((PSI5_Type *)IP_PSI5_0_BASE)
/** Peripheral PSI5_1 base address */
#define IP_PSI5_1_BASE                           (0x421E0000u)
/** Peripheral PSI5_1 base pointer */
#define IP_PSI5_1                                ((PSI5_Type *)IP_PSI5_1_BASE)
/** Array initializer of PSI5 peripheral base addresses */
#define IP_PSI5_BASE_ADDRS                       { IP_PSI5_0_BASE, IP_PSI5_1_BASE }
/** Array initializer of PSI5 peripheral base pointers */
#define IP_PSI5_BASE_PTRS                        { IP_PSI5_0, IP_PSI5_1 }

/* ----------------------------------------------------------------------------
   -- PSI5 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PSI5_Register_Masks PSI5 Register Masks
 * @{
 */

/*! @name GCR - Global Control Register */
/*! @{ */

#define PSI5_GCR_GLOBAL_DISABLE_REQ_MASK         (0x1U)
#define PSI5_GCR_GLOBAL_DISABLE_REQ_SHIFT        (0U)
#define PSI5_GCR_GLOBAL_DISABLE_REQ_WIDTH        (1U)
#define PSI5_GCR_GLOBAL_DISABLE_REQ(x)           (((uint16_t)(((uint16_t)(x)) << PSI5_GCR_GLOBAL_DISABLE_REQ_SHIFT)) & PSI5_GCR_GLOBAL_DISABLE_REQ_MASK)

#define PSI5_GCR_CTC_GED_MASK                    (0x2U)
#define PSI5_GCR_CTC_GED_SHIFT                   (1U)
#define PSI5_GCR_CTC_GED_WIDTH                   (1U)
#define PSI5_GCR_CTC_GED(x)                      (((uint16_t)(((uint16_t)(x)) << PSI5_GCR_CTC_GED_SHIFT)) & PSI5_GCR_CTC_GED_MASK)
/*! @} */

/*! @name CH_PCCR - PSI5 Channel Control Register */
/*! @{ */

#define PSI5_CH_PCCR_PSI5_CH_EN_MASK             (0x1U)
#define PSI5_CH_PCCR_PSI5_CH_EN_SHIFT            (0U)
#define PSI5_CH_PCCR_PSI5_CH_EN_WIDTH            (1U)
#define PSI5_CH_PCCR_PSI5_CH_EN(x)               (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_PSI5_CH_EN_SHIFT)) & PSI5_CH_PCCR_PSI5_CH_EN_MASK)

#define PSI5_CH_PCCR_PSI5_CH_CONFIG_MASK         (0x2U)
#define PSI5_CH_PCCR_PSI5_CH_CONFIG_SHIFT        (1U)
#define PSI5_CH_PCCR_PSI5_CH_CONFIG_WIDTH        (1U)
#define PSI5_CH_PCCR_PSI5_CH_CONFIG(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_PSI5_CH_CONFIG_SHIFT)) & PSI5_CH_PCCR_PSI5_CH_CONFIG_MASK)

#define PSI5_CH_PCCR_MODE_MASK                   (0x4U)
#define PSI5_CH_PCCR_MODE_SHIFT                  (2U)
#define PSI5_CH_PCCR_MODE_WIDTH                  (1U)
#define PSI5_CH_PCCR_MODE(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_MODE_SHIFT)) & PSI5_CH_PCCR_MODE_MASK)

#define PSI5_CH_PCCR_BIT_RATE_MASK               (0x8U)
#define PSI5_CH_PCCR_BIT_RATE_SHIFT              (3U)
#define PSI5_CH_PCCR_BIT_RATE_WIDTH              (1U)
#define PSI5_CH_PCCR_BIT_RATE(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_BIT_RATE_SHIFT)) & PSI5_CH_PCCR_BIT_RATE_MASK)

#define PSI5_CH_PCCR_FAST_CLR_PSI5_MASK          (0x10U)
#define PSI5_CH_PCCR_FAST_CLR_PSI5_SHIFT         (4U)
#define PSI5_CH_PCCR_FAST_CLR_PSI5_WIDTH         (1U)
#define PSI5_CH_PCCR_FAST_CLR_PSI5(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_FAST_CLR_PSI5_SHIFT)) & PSI5_CH_PCCR_FAST_CLR_PSI5_MASK)

#define PSI5_CH_PCCR_FAST_CLR_SMC_MASK           (0x20U)
#define PSI5_CH_PCCR_FAST_CLR_SMC_SHIFT          (5U)
#define PSI5_CH_PCCR_FAST_CLR_SMC_WIDTH          (1U)
#define PSI5_CH_PCCR_FAST_CLR_SMC(x)             (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_FAST_CLR_SMC_SHIFT)) & PSI5_CH_PCCR_FAST_CLR_SMC_MASK)

#define PSI5_CH_PCCR_SP_TS_CLK_SEL_MASK          (0x100U)
#define PSI5_CH_PCCR_SP_TS_CLK_SEL_SHIFT         (8U)
#define PSI5_CH_PCCR_SP_TS_CLK_SEL_WIDTH         (1U)
#define PSI5_CH_PCCR_SP_TS_CLK_SEL(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_SP_TS_CLK_SEL_SHIFT)) & PSI5_CH_PCCR_SP_TS_CLK_SEL_MASK)

#define PSI5_CH_PCCR_DEBUG_FREEZE_CTRL_MASK      (0x200U)
#define PSI5_CH_PCCR_DEBUG_FREEZE_CTRL_SHIFT     (9U)
#define PSI5_CH_PCCR_DEBUG_FREEZE_CTRL_WIDTH     (1U)
#define PSI5_CH_PCCR_DEBUG_FREEZE_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_DEBUG_FREEZE_CTRL_SHIFT)) & PSI5_CH_PCCR_DEBUG_FREEZE_CTRL_MASK)

#define PSI5_CH_PCCR_DEBUG_EN_MASK               (0x400U)
#define PSI5_CH_PCCR_DEBUG_EN_SHIFT              (10U)
#define PSI5_CH_PCCR_DEBUG_EN_WIDTH              (1U)
#define PSI5_CH_PCCR_DEBUG_EN(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_DEBUG_EN_SHIFT)) & PSI5_CH_PCCR_DEBUG_EN_MASK)

#define PSI5_CH_PCCR_GTM_RESET_ASYNC_EN_MASK     (0x4000U)
#define PSI5_CH_PCCR_GTM_RESET_ASYNC_EN_SHIFT    (14U)
#define PSI5_CH_PCCR_GTM_RESET_ASYNC_EN_WIDTH    (1U)
#define PSI5_CH_PCCR_GTM_RESET_ASYNC_EN(x)       (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_GTM_RESET_ASYNC_EN_SHIFT)) & PSI5_CH_PCCR_GTM_RESET_ASYNC_EN_MASK)

#define PSI5_CH_PCCR_ERROR_SELECT0_MASK          (0x10000U)
#define PSI5_CH_PCCR_ERROR_SELECT0_SHIFT         (16U)
#define PSI5_CH_PCCR_ERROR_SELECT0_WIDTH         (1U)
#define PSI5_CH_PCCR_ERROR_SELECT0(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_ERROR_SELECT0_SHIFT)) & PSI5_CH_PCCR_ERROR_SELECT0_MASK)

#define PSI5_CH_PCCR_ERROR_SELECT1_MASK          (0x20000U)
#define PSI5_CH_PCCR_ERROR_SELECT1_SHIFT         (17U)
#define PSI5_CH_PCCR_ERROR_SELECT1_WIDTH         (1U)
#define PSI5_CH_PCCR_ERROR_SELECT1(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_ERROR_SELECT1_SHIFT)) & PSI5_CH_PCCR_ERROR_SELECT1_MASK)

#define PSI5_CH_PCCR_ERROR_SELECT2_MASK          (0x40000U)
#define PSI5_CH_PCCR_ERROR_SELECT2_SHIFT         (18U)
#define PSI5_CH_PCCR_ERROR_SELECT2_WIDTH         (1U)
#define PSI5_CH_PCCR_ERROR_SELECT2(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_ERROR_SELECT2_SHIFT)) & PSI5_CH_PCCR_ERROR_SELECT2_MASK)

#define PSI5_CH_PCCR_ERROR_SELECT3_MASK          (0x80000U)
#define PSI5_CH_PCCR_ERROR_SELECT3_SHIFT         (19U)
#define PSI5_CH_PCCR_ERROR_SELECT3_WIDTH         (1U)
#define PSI5_CH_PCCR_ERROR_SELECT3(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_ERROR_SELECT3_SHIFT)) & PSI5_CH_PCCR_ERROR_SELECT3_MASK)

#define PSI5_CH_PCCR_ERROR_SELECT4_MASK          (0x100000U)
#define PSI5_CH_PCCR_ERROR_SELECT4_SHIFT         (20U)
#define PSI5_CH_PCCR_ERROR_SELECT4_WIDTH         (1U)
#define PSI5_CH_PCCR_ERROR_SELECT4(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_ERROR_SELECT4_SHIFT)) & PSI5_CH_PCCR_ERROR_SELECT4_MASK)

#define PSI5_CH_PCCR_MEM_DEPTH_MASK              (0x1F000000U)
#define PSI5_CH_PCCR_MEM_DEPTH_SHIFT             (24U)
#define PSI5_CH_PCCR_MEM_DEPTH_WIDTH             (5U)
#define PSI5_CH_PCCR_MEM_DEPTH(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_MEM_DEPTH_SHIFT)) & PSI5_CH_PCCR_MEM_DEPTH_MASK)

#define PSI5_CH_PCCR_CTC_ED_MASK                 (0x40000000U)
#define PSI5_CH_PCCR_CTC_ED_SHIFT                (30U)
#define PSI5_CH_PCCR_CTC_ED_WIDTH                (1U)
#define PSI5_CH_PCCR_CTC_ED(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_CTC_ED_SHIFT)) & PSI5_CH_PCCR_CTC_ED_MASK)

#define PSI5_CH_PCCR_CTC_GED_SEL_MASK            (0x80000000U)
#define PSI5_CH_PCCR_CTC_GED_SEL_SHIFT           (31U)
#define PSI5_CH_PCCR_CTC_GED_SEL_WIDTH           (1U)
#define PSI5_CH_PCCR_CTC_GED_SEL(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PCCR_CTC_GED_SEL_SHIFT)) & PSI5_CH_PCCR_CTC_GED_SEL_MASK)
/*! @} */

/*! @name CH_DCR - DMA Control Register */
/*! @{ */

#define PSI5_CH_DCR_DMA_PM_DS_CONFIG_MASK        (0x3U)
#define PSI5_CH_DCR_DMA_PM_DS_CONFIG_SHIFT       (0U)
#define PSI5_CH_DCR_DMA_PM_DS_CONFIG_WIDTH       (2U)
#define PSI5_CH_DCR_DMA_PM_DS_CONFIG(x)          (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DCR_DMA_PM_DS_CONFIG_SHIFT)) & PSI5_CH_DCR_DMA_PM_DS_CONFIG_MASK)

#define PSI5_CH_DCR_DMA_EN_SF_MASK               (0x4U)
#define PSI5_CH_DCR_DMA_EN_SF_SHIFT              (2U)
#define PSI5_CH_DCR_DMA_EN_SF_WIDTH              (1U)
#define PSI5_CH_DCR_DMA_EN_SF(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DCR_DMA_EN_SF_SHIFT)) & PSI5_CH_DCR_DMA_EN_SF_MASK)

#define PSI5_CH_DCR_IE_DMA_PM_DS_UF_MASK         (0x100U)
#define PSI5_CH_DCR_IE_DMA_PM_DS_UF_SHIFT        (8U)
#define PSI5_CH_DCR_IE_DMA_PM_DS_UF_WIDTH        (1U)
#define PSI5_CH_DCR_IE_DMA_PM_DS_UF(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DCR_IE_DMA_PM_DS_UF_SHIFT)) & PSI5_CH_DCR_IE_DMA_PM_DS_UF_MASK)

#define PSI5_CH_DCR_IE_DMA_SFUF_MASK             (0x400U)
#define PSI5_CH_DCR_IE_DMA_SFUF_SHIFT            (10U)
#define PSI5_CH_DCR_IE_DMA_SFUF_WIDTH            (1U)
#define PSI5_CH_DCR_IE_DMA_SFUF(x)               (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DCR_IE_DMA_SFUF_SHIFT)) & PSI5_CH_DCR_IE_DMA_SFUF_MASK)

#define PSI5_CH_DCR_IE_DMA_PM_DS_FIFO_FULL_MASK  (0x800U)
#define PSI5_CH_DCR_IE_DMA_PM_DS_FIFO_FULL_SHIFT (11U)
#define PSI5_CH_DCR_IE_DMA_PM_DS_FIFO_FULL_WIDTH (1U)
#define PSI5_CH_DCR_IE_DMA_PM_DS_FIFO_FULL(x)    (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DCR_IE_DMA_PM_DS_FIFO_FULL_SHIFT)) & PSI5_CH_DCR_IE_DMA_PM_DS_FIFO_FULL_MASK)

#define PSI5_CH_DCR_IE_DMA_TF_PM_DS_MASK         (0x20000U)
#define PSI5_CH_DCR_IE_DMA_TF_PM_DS_SHIFT        (17U)
#define PSI5_CH_DCR_IE_DMA_TF_PM_DS_WIDTH        (1U)
#define PSI5_CH_DCR_IE_DMA_TF_PM_DS(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DCR_IE_DMA_TF_PM_DS_SHIFT)) & PSI5_CH_DCR_IE_DMA_TF_PM_DS_MASK)

#define PSI5_CH_DCR_IE_DMA_TF_SF_MASK            (0x40000U)
#define PSI5_CH_DCR_IE_DMA_TF_SF_SHIFT           (18U)
#define PSI5_CH_DCR_IE_DMA_TF_SF_WIDTH           (1U)
#define PSI5_CH_DCR_IE_DMA_TF_SF(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DCR_IE_DMA_TF_SF_SHIFT)) & PSI5_CH_DCR_IE_DMA_TF_SF_MASK)

#define PSI5_CH_DCR_DMA_PM_DS_WM_MASK            (0x1F000000U)
#define PSI5_CH_DCR_DMA_PM_DS_WM_SHIFT           (24U)
#define PSI5_CH_DCR_DMA_PM_DS_WM_WIDTH           (5U)
#define PSI5_CH_DCR_DMA_PM_DS_WM(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DCR_DMA_PM_DS_WM_SHIFT)) & PSI5_CH_DCR_DMA_PM_DS_WM_MASK)
/*! @} */

/*! @name CH_DSR - DMA Status Register */
/*! @{ */

#define PSI5_CH_DSR_IS_DMA_PM_DS_UF_MASK         (0x100U)
#define PSI5_CH_DSR_IS_DMA_PM_DS_UF_SHIFT        (8U)
#define PSI5_CH_DSR_IS_DMA_PM_DS_UF_WIDTH        (1U)
#define PSI5_CH_DSR_IS_DMA_PM_DS_UF(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DSR_IS_DMA_PM_DS_UF_SHIFT)) & PSI5_CH_DSR_IS_DMA_PM_DS_UF_MASK)

#define PSI5_CH_DSR_IS_DMA_SFUF_MASK             (0x400U)
#define PSI5_CH_DSR_IS_DMA_SFUF_SHIFT            (10U)
#define PSI5_CH_DSR_IS_DMA_SFUF_WIDTH            (1U)
#define PSI5_CH_DSR_IS_DMA_SFUF(x)               (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DSR_IS_DMA_SFUF_SHIFT)) & PSI5_CH_DSR_IS_DMA_SFUF_MASK)

#define PSI5_CH_DSR_IS_DMA_PM_DS_FIFO_FULL_MASK  (0x800U)
#define PSI5_CH_DSR_IS_DMA_PM_DS_FIFO_FULL_SHIFT (11U)
#define PSI5_CH_DSR_IS_DMA_PM_DS_FIFO_FULL_WIDTH (1U)
#define PSI5_CH_DSR_IS_DMA_PM_DS_FIFO_FULL(x)    (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DSR_IS_DMA_PM_DS_FIFO_FULL_SHIFT)) & PSI5_CH_DSR_IS_DMA_PM_DS_FIFO_FULL_MASK)

#define PSI5_CH_DSR_IS_DMA_TF_PM_DS_MASK         (0x20000U)
#define PSI5_CH_DSR_IS_DMA_TF_PM_DS_SHIFT        (17U)
#define PSI5_CH_DSR_IS_DMA_TF_PM_DS_WIDTH        (1U)
#define PSI5_CH_DSR_IS_DMA_TF_PM_DS(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DSR_IS_DMA_TF_PM_DS_SHIFT)) & PSI5_CH_DSR_IS_DMA_TF_PM_DS_MASK)

#define PSI5_CH_DSR_IS_DMA_TF_SF_MASK            (0x40000U)
#define PSI5_CH_DSR_IS_DMA_TF_SF_SHIFT           (18U)
#define PSI5_CH_DSR_IS_DMA_TF_SF_WIDTH           (1U)
#define PSI5_CH_DSR_IS_DMA_TF_SF(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DSR_IS_DMA_TF_SF_SHIFT)) & PSI5_CH_DSR_IS_DMA_TF_SF_MASK)
/*! @} */

/*! @name CH_GICR - General Interrupt Control Register */
/*! @{ */

#define PSI5_CH_GICR_IE_PRR_MASK                 (0x10000U)
#define PSI5_CH_GICR_IE_PRR_SHIFT                (16U)
#define PSI5_CH_GICR_IE_PRR_WIDTH                (1U)
#define PSI5_CH_GICR_IE_PRR(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GICR_IE_PRR_SHIFT)) & PSI5_CH_GICR_IE_PRR_MASK)

#define PSI5_CH_GICR_IE_BRR_MASK                 (0x20000U)
#define PSI5_CH_GICR_IE_BRR_SHIFT                (17U)
#define PSI5_CH_GICR_IE_BRR_WIDTH                (1U)
#define PSI5_CH_GICR_IE_BRR(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GICR_IE_BRR_SHIFT)) & PSI5_CH_GICR_IE_BRR_MASK)

#define PSI5_CH_GICR_IE_DSRR_MASK                (0x40000U)
#define PSI5_CH_GICR_IE_DSRR_SHIFT               (18U)
#define PSI5_CH_GICR_IE_DSRR_WIDTH               (1U)
#define PSI5_CH_GICR_IE_DSRR(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GICR_IE_DSRR_SHIFT)) & PSI5_CH_GICR_IE_DSRR_MASK)

#define PSI5_CH_GICR_IE_PROW_MASK                (0x80000U)
#define PSI5_CH_GICR_IE_PROW_SHIFT               (19U)
#define PSI5_CH_GICR_IE_PROW_WIDTH               (1U)
#define PSI5_CH_GICR_IE_PROW(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GICR_IE_PROW_SHIFT)) & PSI5_CH_GICR_IE_PROW_MASK)

#define PSI5_CH_GICR_IE_BROW_MASK                (0x100000U)
#define PSI5_CH_GICR_IE_BROW_SHIFT               (20U)
#define PSI5_CH_GICR_IE_BROW_WIDTH               (1U)
#define PSI5_CH_GICR_IE_BROW(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GICR_IE_BROW_SHIFT)) & PSI5_CH_GICR_IE_BROW_MASK)

#define PSI5_CH_GICR_IE_DSROW_MASK               (0x200000U)
#define PSI5_CH_GICR_IE_DSROW_SHIFT              (21U)
#define PSI5_CH_GICR_IE_DSROW_WIDTH              (1U)
#define PSI5_CH_GICR_IE_DSROW(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GICR_IE_DSROW_SHIFT)) & PSI5_CH_GICR_IE_DSROW_MASK)

#define PSI5_CH_GICR_IE_DTS_MASK                 (0x400000U)
#define PSI5_CH_GICR_IE_DTS_SHIFT                (22U)
#define PSI5_CH_GICR_IE_DTS_WIDTH                (1U)
#define PSI5_CH_GICR_IE_DTS(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GICR_IE_DTS_SHIFT)) & PSI5_CH_GICR_IE_DTS_MASK)

#define PSI5_CH_GICR_IE_STS_MASK                 (0x800000U)
#define PSI5_CH_GICR_IE_STS_SHIFT                (23U)
#define PSI5_CH_GICR_IE_STS_WIDTH                (1U)
#define PSI5_CH_GICR_IE_STS(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GICR_IE_STS_SHIFT)) & PSI5_CH_GICR_IE_STS_MASK)
/*! @} */

/*! @name CH_NDICR - New Data Interrupt Control Register */
/*! @{ */

#define PSI5_CH_NDICR_IE_ND_MASK                 (0xFFFFFFFFU)
#define PSI5_CH_NDICR_IE_ND_SHIFT                (0U)
#define PSI5_CH_NDICR_IE_ND_WIDTH                (32U)
#define PSI5_CH_NDICR_IE_ND(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_CH_NDICR_IE_ND_SHIFT)) & PSI5_CH_NDICR_IE_ND_MASK)
/*! @} */

/*! @name CH_OWICR - Overwrite Interrupt Control Register */
/*! @{ */

#define PSI5_CH_OWICR_IE_OW_MASK                 (0xFFFFFFFFU)
#define PSI5_CH_OWICR_IE_OW_SHIFT                (0U)
#define PSI5_CH_OWICR_IE_OW_WIDTH                (32U)
#define PSI5_CH_OWICR_IE_OW(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_CH_OWICR_IE_OW_SHIFT)) & PSI5_CH_OWICR_IE_OW_MASK)
/*! @} */

/*! @name CH_EICR - Error Interrupt Control Register */
/*! @{ */

#define PSI5_CH_EICR_IE_ERROR_MASK               (0xFFFFFFFFU)
#define PSI5_CH_EICR_IE_ERROR_SHIFT              (0U)
#define PSI5_CH_EICR_IE_ERROR_WIDTH              (32U)
#define PSI5_CH_EICR_IE_ERROR(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_CH_EICR_IE_ERROR_SHIFT)) & PSI5_CH_EICR_IE_ERROR_MASK)
/*! @} */

/*! @name CH_GISR - General Interrupt Status Register */
/*! @{ */

#define PSI5_CH_GISR_IS_NVSM_MASK                (0x3FU)
#define PSI5_CH_GISR_IS_NVSM_SHIFT               (0U)
#define PSI5_CH_GISR_IS_NVSM_WIDTH               (6U)
#define PSI5_CH_GISR_IS_NVSM(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GISR_IS_NVSM_SHIFT)) & PSI5_CH_GISR_IS_NVSM_MASK)

#define PSI5_CH_GISR_IS_OWSM_MASK                (0x3F00U)
#define PSI5_CH_GISR_IS_OWSM_SHIFT               (8U)
#define PSI5_CH_GISR_IS_OWSM_WIDTH               (6U)
#define PSI5_CH_GISR_IS_OWSM(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GISR_IS_OWSM_SHIFT)) & PSI5_CH_GISR_IS_OWSM_MASK)

#define PSI5_CH_GISR_DPR_RDY_MASK                (0x10000U)
#define PSI5_CH_GISR_DPR_RDY_SHIFT               (16U)
#define PSI5_CH_GISR_DPR_RDY_WIDTH               (1U)
#define PSI5_CH_GISR_DPR_RDY(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GISR_DPR_RDY_SHIFT)) & PSI5_CH_GISR_DPR_RDY_MASK)

#define PSI5_CH_GISR_DBR_RDY_MASK                (0x20000U)
#define PSI5_CH_GISR_DBR_RDY_SHIFT               (17U)
#define PSI5_CH_GISR_DBR_RDY_WIDTH               (1U)
#define PSI5_CH_GISR_DBR_RDY(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GISR_DBR_RDY_SHIFT)) & PSI5_CH_GISR_DBR_RDY_MASK)

#define PSI5_CH_GISR_DSR_RDY_MASK                (0x40000U)
#define PSI5_CH_GISR_DSR_RDY_SHIFT               (18U)
#define PSI5_CH_GISR_DSR_RDY_WIDTH               (1U)
#define PSI5_CH_GISR_DSR_RDY(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GISR_DSR_RDY_SHIFT)) & PSI5_CH_GISR_DSR_RDY_MASK)

#define PSI5_CH_GISR_IS_PROW_MASK                (0x80000U)
#define PSI5_CH_GISR_IS_PROW_SHIFT               (19U)
#define PSI5_CH_GISR_IS_PROW_WIDTH               (1U)
#define PSI5_CH_GISR_IS_PROW(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GISR_IS_PROW_SHIFT)) & PSI5_CH_GISR_IS_PROW_MASK)

#define PSI5_CH_GISR_IS_BROW_MASK                (0x100000U)
#define PSI5_CH_GISR_IS_BROW_SHIFT               (20U)
#define PSI5_CH_GISR_IS_BROW_WIDTH               (1U)
#define PSI5_CH_GISR_IS_BROW(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GISR_IS_BROW_SHIFT)) & PSI5_CH_GISR_IS_BROW_MASK)

#define PSI5_CH_GISR_IS_DSROW_MASK               (0x200000U)
#define PSI5_CH_GISR_IS_DSROW_SHIFT              (21U)
#define PSI5_CH_GISR_IS_DSROW_WIDTH              (1U)
#define PSI5_CH_GISR_IS_DSROW(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GISR_IS_DSROW_SHIFT)) & PSI5_CH_GISR_IS_DSROW_MASK)

#define PSI5_CH_GISR_IS_DTS_MASK                 (0x400000U)
#define PSI5_CH_GISR_IS_DTS_SHIFT                (22U)
#define PSI5_CH_GISR_IS_DTS_WIDTH                (1U)
#define PSI5_CH_GISR_IS_DTS(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GISR_IS_DTS_SHIFT)) & PSI5_CH_GISR_IS_DTS_MASK)

#define PSI5_CH_GISR_IS_STS_MASK                 (0x800000U)
#define PSI5_CH_GISR_IS_STS_SHIFT                (23U)
#define PSI5_CH_GISR_IS_STS_WIDTH                (1U)
#define PSI5_CH_GISR_IS_STS(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GISR_IS_STS_SHIFT)) & PSI5_CH_GISR_IS_STS_MASK)

#define PSI5_CH_GISR_IS_CESM_MASK                (0x3F000000U)
#define PSI5_CH_GISR_IS_CESM_SHIFT               (24U)
#define PSI5_CH_GISR_IS_CESM_WIDTH               (6U)
#define PSI5_CH_GISR_IS_CESM(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GISR_IS_CESM_SHIFT)) & PSI5_CH_GISR_IS_CESM_MASK)

#define PSI5_CH_GISR_IS_DB_FR_MASK               (0x80000000U)
#define PSI5_CH_GISR_IS_DB_FR_SHIFT              (31U)
#define PSI5_CH_GISR_IS_DB_FR_WIDTH              (1U)
#define PSI5_CH_GISR_IS_DB_FR(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_CH_GISR_IS_DB_FR_SHIFT)) & PSI5_CH_GISR_IS_DB_FR_MASK)
/*! @} */

/*! @name CH_DPMR - DMA PSI5 Message Register */
/*! @{ */

#define PSI5_CH_DPMR_PSI5_RXDATA_MASK            (0xFFFFFFFFU)
#define PSI5_CH_DPMR_PSI5_RXDATA_SHIFT           (0U)
#define PSI5_CH_DPMR_PSI5_RXDATA_WIDTH           (32U)
#define PSI5_CH_DPMR_PSI5_RXDATA(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DPMR_PSI5_RXDATA_SHIFT)) & PSI5_CH_DPMR_PSI5_RXDATA_MASK)
/*! @} */

/*! @name CH_DSFR - DMA SMC Frame Register */
/*! @{ */

#define PSI5_CH_DSFR_SMC_RXDATA_MASK             (0xFFFFFFFFU)
#define PSI5_CH_DSFR_SMC_RXDATA_SHIFT            (0U)
#define PSI5_CH_DSFR_SMC_RXDATA_WIDTH            (32U)
#define PSI5_CH_DSFR_SMC_RXDATA(x)               (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DSFR_SMC_RXDATA_SHIFT)) & PSI5_CH_DSFR_SMC_RXDATA_MASK)
/*! @} */

/*! @name CH_DDSR - DMA Diagnostic Status Register */
/*! @{ */

#define PSI5_CH_DDSR_DDS_MASK                    (0xFFFFFFFFU)
#define PSI5_CH_DDSR_DDS_SHIFT                   (0U)
#define PSI5_CH_DDSR_DDS_WIDTH                   (32U)
#define PSI5_CH_DDSR_DDS(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DDSR_DDS_SHIFT)) & PSI5_CH_DDSR_DDS_MASK)
/*! @} */

/*! @name CH_PMRRL - PSI5 Message Receive Register Low */
/*! @{ */

#define PSI5_CH_PMRRL_C_MASK                     (0x1U)
#define PSI5_CH_PMRRL_C_SHIFT                    (0U)
#define PSI5_CH_PMRRL_C_WIDTH                    (1U)
#define PSI5_CH_PMRRL_C(x)                       (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRRL_C_SHIFT)) & PSI5_CH_PMRRL_C_MASK)

#define PSI5_CH_PMRRL_CRC_MASK                   (0xEU)
#define PSI5_CH_PMRRL_CRC_SHIFT                  (1U)
#define PSI5_CH_PMRRL_CRC_WIDTH                  (3U)
#define PSI5_CH_PMRRL_CRC(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRRL_CRC_SHIFT)) & PSI5_CH_PMRRL_CRC_MASK)

#define PSI5_CH_PMRRL_DATA_REGION_MASK           (0xFFFFFFF0U)
#define PSI5_CH_PMRRL_DATA_REGION_SHIFT          (4U)
#define PSI5_CH_PMRRL_DATA_REGION_WIDTH          (28U)
#define PSI5_CH_PMRRL_DATA_REGION(x)             (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRRL_DATA_REGION_SHIFT)) & PSI5_CH_PMRRL_DATA_REGION_MASK)
/*! @} */

/*! @name CH_PMRRH - PSI5 Message Receive Register High */
/*! @{ */

#define PSI5_CH_PMRRH_TimeStampValue_MASK        (0xFFFFFFU)
#define PSI5_CH_PMRRH_TimeStampValue_SHIFT       (0U)
#define PSI5_CH_PMRRH_TimeStampValue_WIDTH       (24U)
#define PSI5_CH_PMRRH_TimeStampValue(x)          (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRRH_TimeStampValue_SHIFT)) & PSI5_CH_PMRRH_TimeStampValue_MASK)

#define PSI5_CH_PMRRH_SlotCounter_MASK           (0x7000000U)
#define PSI5_CH_PMRRH_SlotCounter_SHIFT          (24U)
#define PSI5_CH_PMRRH_SlotCounter_WIDTH          (3U)
#define PSI5_CH_PMRRH_SlotCounter(x)             (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRRH_SlotCounter_SHIFT)) & PSI5_CH_PMRRH_SlotCounter_MASK)

#define PSI5_CH_PMRRH_T_MASK                     (0x8000000U)
#define PSI5_CH_PMRRH_T_SHIFT                    (27U)
#define PSI5_CH_PMRRH_T_WIDTH                    (1U)
#define PSI5_CH_PMRRH_T(x)                       (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRRH_T_SHIFT)) & PSI5_CH_PMRRH_T_MASK)

#define PSI5_CH_PMRRH_E_MASK                     (0x10000000U)
#define PSI5_CH_PMRRH_E_SHIFT                    (28U)
#define PSI5_CH_PMRRH_E_WIDTH                    (1U)
#define PSI5_CH_PMRRH_E(x)                       (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRRH_E_SHIFT)) & PSI5_CH_PMRRH_E_MASK)

#define PSI5_CH_PMRRH_EM_MASK                    (0x20000000U)
#define PSI5_CH_PMRRH_EM_SHIFT                   (29U)
#define PSI5_CH_PMRRH_EM_WIDTH                   (1U)
#define PSI5_CH_PMRRH_EM(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRRH_EM_SHIFT)) & PSI5_CH_PMRRH_EM_MASK)

#define PSI5_CH_PMRRH_F_MASK                     (0x40000000U)
#define PSI5_CH_PMRRH_F_SHIFT                    (30U)
#define PSI5_CH_PMRRH_F_WIDTH                    (1U)
#define PSI5_CH_PMRRH_F(x)                       (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRRH_F_SHIFT)) & PSI5_CH_PMRRH_F_MASK)
/*! @} */

/*! @name CH_PMRL - PSI5 Message Register Low i */
/*! @{ */

#define PSI5_CH_PMRL_C_MASK                      (0x1U)
#define PSI5_CH_PMRL_C_SHIFT                     (0U)
#define PSI5_CH_PMRL_C_WIDTH                     (1U)
#define PSI5_CH_PMRL_C(x)                        (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRL_C_SHIFT)) & PSI5_CH_PMRL_C_MASK)

#define PSI5_CH_PMRL_CRCP_MASK                   (0xEU)
#define PSI5_CH_PMRL_CRCP_SHIFT                  (1U)
#define PSI5_CH_PMRL_CRCP_WIDTH                  (3U)
#define PSI5_CH_PMRL_CRCP(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRL_CRCP_SHIFT)) & PSI5_CH_PMRL_CRCP_MASK)

#define PSI5_CH_PMRL_DATA_REGION_MASK            (0xFFFFFFF0U)
#define PSI5_CH_PMRL_DATA_REGION_SHIFT           (4U)
#define PSI5_CH_PMRL_DATA_REGION_WIDTH           (28U)
#define PSI5_CH_PMRL_DATA_REGION(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRL_DATA_REGION_SHIFT)) & PSI5_CH_PMRL_DATA_REGION_MASK)
/*! @} */

/*! @name CH_PMRH - PSI5 Message Register High i */
/*! @{ */

#define PSI5_CH_PMRH_TimeStampValue_MASK         (0xFFFFFFU)
#define PSI5_CH_PMRH_TimeStampValue_SHIFT        (0U)
#define PSI5_CH_PMRH_TimeStampValue_WIDTH        (24U)
#define PSI5_CH_PMRH_TimeStampValue(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRH_TimeStampValue_SHIFT)) & PSI5_CH_PMRH_TimeStampValue_MASK)

#define PSI5_CH_PMRH_Slot_Counter_MASK           (0x7000000U)
#define PSI5_CH_PMRH_Slot_Counter_SHIFT          (24U)
#define PSI5_CH_PMRH_Slot_Counter_WIDTH          (3U)
#define PSI5_CH_PMRH_Slot_Counter(x)             (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRH_Slot_Counter_SHIFT)) & PSI5_CH_PMRH_Slot_Counter_MASK)

#define PSI5_CH_PMRH_T_MASK                      (0x8000000U)
#define PSI5_CH_PMRH_T_SHIFT                     (27U)
#define PSI5_CH_PMRH_T_WIDTH                     (1U)
#define PSI5_CH_PMRH_T(x)                        (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRH_T_SHIFT)) & PSI5_CH_PMRH_T_MASK)

#define PSI5_CH_PMRH_E_MASK                      (0x10000000U)
#define PSI5_CH_PMRH_E_SHIFT                     (28U)
#define PSI5_CH_PMRH_E_WIDTH                     (1U)
#define PSI5_CH_PMRH_E(x)                        (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRH_E_SHIFT)) & PSI5_CH_PMRH_E_MASK)

#define PSI5_CH_PMRH_EM_MASK                     (0x20000000U)
#define PSI5_CH_PMRH_EM_SHIFT                    (29U)
#define PSI5_CH_PMRH_EM_WIDTH                    (1U)
#define PSI5_CH_PMRH_EM(x)                       (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRH_EM_SHIFT)) & PSI5_CH_PMRH_EM_MASK)

#define PSI5_CH_PMRH_F_MASK                      (0x40000000U)
#define PSI5_CH_PMRH_F_SHIFT                     (30U)
#define PSI5_CH_PMRH_F_WIDTH                     (1U)
#define PSI5_CH_PMRH_F(x)                        (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRH_F_SHIFT)) & PSI5_CH_PMRH_F_MASK)

#define PSI5_CH_PMRH_O_MASK                      (0x80000000U)
#define PSI5_CH_PMRH_O_SHIFT                     (31U)
#define PSI5_CH_PMRH_O_WIDTH                     (1U)
#define PSI5_CH_PMRH_O(x)                        (((uint32_t)(((uint32_t)(x)) << PSI5_CH_PMRH_O_SHIFT)) & PSI5_CH_PMRH_O_MASK)
/*! @} */

/*! @name CH_SFR - SMC Frame Register n */
/*! @{ */

#define PSI5_CH_SFR_DATA_MASK                    (0xFFFU)
#define PSI5_CH_SFR_DATA_SHIFT                   (0U)
#define PSI5_CH_SFR_DATA_WIDTH                   (12U)
#define PSI5_CH_SFR_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SFR_DATA_SHIFT)) & PSI5_CH_SFR_DATA_MASK)

#define PSI5_CH_SFR_IDDATA_MASK                  (0xF000U)
#define PSI5_CH_SFR_IDDATA_SHIFT                 (12U)
#define PSI5_CH_SFR_IDDATA_WIDTH                 (4U)
#define PSI5_CH_SFR_IDDATA(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SFR_IDDATA_SHIFT)) & PSI5_CH_SFR_IDDATA_MASK)

#define PSI5_CH_SFR_ID_MASK                      (0xF0000U)
#define PSI5_CH_SFR_ID_SHIFT                     (16U)
#define PSI5_CH_SFR_ID_WIDTH                     (4U)
#define PSI5_CH_SFR_ID(x)                        (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SFR_ID_SHIFT)) & PSI5_CH_SFR_ID_MASK)

#define PSI5_CH_SFR_C_MASK                       (0x100000U)
#define PSI5_CH_SFR_C_SHIFT                      (20U)
#define PSI5_CH_SFR_C_WIDTH                      (1U)
#define PSI5_CH_SFR_C(x)                         (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SFR_C_SHIFT)) & PSI5_CH_SFR_C_MASK)

#define PSI5_CH_SFR_CRC_MASK                     (0x7E00000U)
#define PSI5_CH_SFR_CRC_SHIFT                    (21U)
#define PSI5_CH_SFR_CRC_WIDTH                    (6U)
#define PSI5_CH_SFR_CRC(x)                       (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SFR_CRC_SHIFT)) & PSI5_CH_SFR_CRC_MASK)

#define PSI5_CH_SFR_OW_MASK                      (0x8000000U)
#define PSI5_CH_SFR_OW_SHIFT                     (27U)
#define PSI5_CH_SFR_OW_WIDTH                     (1U)
#define PSI5_CH_SFR_OW(x)                        (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SFR_OW_SHIFT)) & PSI5_CH_SFR_OW_MASK)

#define PSI5_CH_SFR_CER_MASK                     (0x10000000U)
#define PSI5_CH_SFR_CER_SHIFT                    (28U)
#define PSI5_CH_SFR_CER_WIDTH                    (1U)
#define PSI5_CH_SFR_CER(x)                       (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SFR_CER_SHIFT)) & PSI5_CH_SFR_CER_MASK)

#define PSI5_CH_SFR_SLOT_NO_MASK                 (0xE0000000U)
#define PSI5_CH_SFR_SLOT_NO_SHIFT                (29U)
#define PSI5_CH_SFR_SLOT_NO_WIDTH                (3U)
#define PSI5_CH_SFR_SLOT_NO(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SFR_SLOT_NO_SHIFT)) & PSI5_CH_SFR_SLOT_NO_MASK)
/*! @} */

/*! @name CH_NDSR - New Data Status Register */
/*! @{ */

#define PSI5_CH_NDSR_NDS_MASK                    (0xFFFFFFFFU)
#define PSI5_CH_NDSR_NDS_SHIFT                   (0U)
#define PSI5_CH_NDSR_NDS_WIDTH                   (32U)
#define PSI5_CH_NDSR_NDS(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_CH_NDSR_NDS_SHIFT)) & PSI5_CH_NDSR_NDS_MASK)
/*! @} */

/*! @name CH_OWSR - Overwrite Status Register */
/*! @{ */

#define PSI5_CH_OWSR_OWS_MASK                    (0xFFFFFFFFU)
#define PSI5_CH_OWSR_OWS_SHIFT                   (0U)
#define PSI5_CH_OWSR_OWS_WIDTH                   (32U)
#define PSI5_CH_OWSR_OWS(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_CH_OWSR_OWS_SHIFT)) & PSI5_CH_OWSR_OWS_MASK)
/*! @} */

/*! @name CH_EISR - Error Indication Status Register */
/*! @{ */

#define PSI5_CH_EISR_ERROR_MASK                  (0xFFFFFFFFU)
#define PSI5_CH_EISR_ERROR_SHIFT                 (0U)
#define PSI5_CH_EISR_ERROR_WIDTH                 (32U)
#define PSI5_CH_EISR_ERROR(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_CH_EISR_ERROR_SHIFT)) & PSI5_CH_EISR_ERROR_MASK)
/*! @} */

/*! @name CH_SNDSR - Set New Data Status Register */
/*! @{ */

#define PSI5_CH_SNDSR_SNDS_MASK                  (0xFFFFFFFFU)
#define PSI5_CH_SNDSR_SNDS_SHIFT                 (0U)
#define PSI5_CH_SNDSR_SNDS_WIDTH                 (32U)
#define PSI5_CH_SNDSR_SNDS(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SNDSR_SNDS_SHIFT)) & PSI5_CH_SNDSR_SNDS_MASK)
/*! @} */

/*! @name CH_SOWSR - Set Overwrite Status Register */
/*! @{ */

#define PSI5_CH_SOWSR_SOWS_MASK                  (0xFFFFFFFFU)
#define PSI5_CH_SOWSR_SOWS_SHIFT                 (0U)
#define PSI5_CH_SOWSR_SOWS_WIDTH                 (32U)
#define PSI5_CH_SOWSR_SOWS(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SOWSR_SOWS_SHIFT)) & PSI5_CH_SOWSR_SOWS_MASK)
/*! @} */

/*! @name CH_SEISR - Set Error Status Register */
/*! @{ */

#define PSI5_CH_SEISR_SERROR_MASK                (0xFFFFFFFFU)
#define PSI5_CH_SEISR_SERROR_SHIFT               (0U)
#define PSI5_CH_SEISR_SERROR_WIDTH               (32U)
#define PSI5_CH_SEISR_SERROR(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SEISR_SERROR_SHIFT)) & PSI5_CH_SEISR_SERROR_MASK)
/*! @} */

/*! @name CH_SSESR - Set SMC Error Status Register */
/*! @{ */

#define PSI5_CH_SSESR_SNVSM_MASK                 (0x3FU)
#define PSI5_CH_SSESR_SNVSM_SHIFT                (0U)
#define PSI5_CH_SSESR_SNVSM_WIDTH                (6U)
#define PSI5_CH_SSESR_SNVSM(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SSESR_SNVSM_SHIFT)) & PSI5_CH_SSESR_SNVSM_MASK)

#define PSI5_CH_SSESR_SOWSM_MASK                 (0x3F00U)
#define PSI5_CH_SSESR_SOWSM_SHIFT                (8U)
#define PSI5_CH_SSESR_SOWSM_WIDTH                (6U)
#define PSI5_CH_SSESR_SOWSM(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SSESR_SOWSM_SHIFT)) & PSI5_CH_SSESR_SOWSM_MASK)

#define PSI5_CH_SSESR_SCESM_MASK                 (0x3F000000U)
#define PSI5_CH_SSESR_SCESM_SHIFT                (24U)
#define PSI5_CH_SSESR_SCESM_WIDTH                (6U)
#define PSI5_CH_SSESR_SCESM(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SSESR_SCESM_SHIFT)) & PSI5_CH_SSESR_SCESM_MASK)
/*! @} */

/*! @name CH_STSRR - Sync Time Stamp Read Register */
/*! @{ */

#define PSI5_CH_STSRR_STSV_MASK                  (0xFFFFFFU)
#define PSI5_CH_STSRR_STSV_SHIFT                 (0U)
#define PSI5_CH_STSRR_STSV_WIDTH                 (24U)
#define PSI5_CH_STSRR_STSV(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_CH_STSRR_STSV_SHIFT)) & PSI5_CH_STSRR_STSV_MASK)
/*! @} */

/*! @name CH_DTSRR - Data Time Stamp Read Register */
/*! @{ */

#define PSI5_CH_DTSRR_DTSV_MASK                  (0xFFFFFFU)
#define PSI5_CH_DTSRR_DTSV_SHIFT                 (0U)
#define PSI5_CH_DTSRR_DTSV_WIDTH                 (24U)
#define PSI5_CH_DTSRR_DTSV(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DTSRR_DTSV_SHIFT)) & PSI5_CH_DTSRR_DTSV_MASK)

#define PSI5_CH_DTSRR_SLOT_COUNTER_MASK          (0x7000000U)
#define PSI5_CH_DTSRR_SLOT_COUNTER_SHIFT         (24U)
#define PSI5_CH_DTSRR_SLOT_COUNTER_WIDTH         (3U)
#define PSI5_CH_DTSRR_SLOT_COUNTER(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DTSRR_SLOT_COUNTER_SHIFT)) & PSI5_CH_DTSRR_SLOT_COUNTER_MASK)
/*! @} */

/*! @name CH_SFCR - Slot n Frame Configuration Register */
/*! @{ */

#define PSI5_CH_SFCR_CRCP_MASK                   (0x1U)
#define PSI5_CH_SFCR_CRCP_SHIFT                  (0U)
#define PSI5_CH_SFCR_CRCP_WIDTH                  (1U)
#define PSI5_CH_SFCR_CRCP(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SFCR_CRCP_SHIFT)) & PSI5_CH_SFCR_CRCP_MASK)

#define PSI5_CH_SFCR_DRL_MASK                    (0x3EU)
#define PSI5_CH_SFCR_DRL_SHIFT                   (1U)
#define PSI5_CH_SFCR_DRL_WIDTH                   (5U)
#define PSI5_CH_SFCR_DRL(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SFCR_DRL_SHIFT)) & PSI5_CH_SFCR_DRL_MASK)

#define PSI5_CH_SFCR_SMCL_MASK                   (0x8000U)
#define PSI5_CH_SFCR_SMCL_SHIFT                  (15U)
#define PSI5_CH_SFCR_SMCL_WIDTH                  (1U)
#define PSI5_CH_SFCR_SMCL(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SFCR_SMCL_SHIFT)) & PSI5_CH_SFCR_SMCL_MASK)

#define PSI5_CH_SFCR_TS_CAPT_MASK                (0x20000U)
#define PSI5_CH_SFCR_TS_CAPT_SHIFT               (17U)
#define PSI5_CH_SFCR_TS_CAPT_WIDTH               (1U)
#define PSI5_CH_SFCR_TS_CAPT(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SFCR_TS_CAPT_SHIFT)) & PSI5_CH_SFCR_TS_CAPT_MASK)

#define PSI5_CH_SFCR_SLOT_EN_MASK                (0x40000U)
#define PSI5_CH_SFCR_SLOT_EN_SHIFT               (18U)
#define PSI5_CH_SFCR_SLOT_EN_WIDTH               (1U)
#define PSI5_CH_SFCR_SLOT_EN(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SFCR_SLOT_EN_SHIFT)) & PSI5_CH_SFCR_SLOT_EN_MASK)
/*! @} */

/*! @name CH_S2SBR - Slot 2 Start Boundary Register */
/*! @{ */

#define PSI5_CH_S2SBR_S2SBT_MASK                 (0x7FFFU)
#define PSI5_CH_S2SBR_S2SBT_SHIFT                (0U)
#define PSI5_CH_S2SBR_S2SBT_WIDTH                (15U)
#define PSI5_CH_S2SBR_S2SBT(x)                   (((uint16_t)(((uint16_t)(x)) << PSI5_CH_S2SBR_S2SBT_SHIFT)) & PSI5_CH_S2SBR_S2SBT_MASK)
/*! @} */

/*! @name CH_S1SBR - Slot 1 Start Boundary Register */
/*! @{ */

#define PSI5_CH_S1SBR_S1SBT_MASK                 (0x7FFFU)
#define PSI5_CH_S1SBR_S1SBT_SHIFT                (0U)
#define PSI5_CH_S1SBR_S1SBT_WIDTH                (15U)
#define PSI5_CH_S1SBR_S1SBT(x)                   (((uint16_t)(((uint16_t)(x)) << PSI5_CH_S1SBR_S1SBT_SHIFT)) & PSI5_CH_S1SBR_S1SBT_MASK)
/*! @} */

/*! @name CH_S4SBR - Slot 4 Start Boundary Register */
/*! @{ */

#define PSI5_CH_S4SBR_S4SBT_MASK                 (0x7FFFU)
#define PSI5_CH_S4SBR_S4SBT_SHIFT                (0U)
#define PSI5_CH_S4SBR_S4SBT_WIDTH                (15U)
#define PSI5_CH_S4SBR_S4SBT(x)                   (((uint16_t)(((uint16_t)(x)) << PSI5_CH_S4SBR_S4SBT_SHIFT)) & PSI5_CH_S4SBR_S4SBT_MASK)
/*! @} */

/*! @name CH_S3SBR - Slot 3 Start Boundary Register */
/*! @{ */

#define PSI5_CH_S3SBR_S3SBT_MASK                 (0x7FFFU)
#define PSI5_CH_S3SBR_S3SBT_SHIFT                (0U)
#define PSI5_CH_S3SBR_S3SBT_WIDTH                (15U)
#define PSI5_CH_S3SBR_S3SBT(x)                   (((uint16_t)(((uint16_t)(x)) << PSI5_CH_S3SBR_S3SBT_SHIFT)) & PSI5_CH_S3SBR_S3SBT_MASK)
/*! @} */

/*! @name CH_S6SBR - Slot 6 Start Boundary Register */
/*! @{ */

#define PSI5_CH_S6SBR_S6SBT_MASK                 (0x7FFFU)
#define PSI5_CH_S6SBR_S6SBT_SHIFT                (0U)
#define PSI5_CH_S6SBR_S6SBT_WIDTH                (15U)
#define PSI5_CH_S6SBR_S6SBT(x)                   (((uint16_t)(((uint16_t)(x)) << PSI5_CH_S6SBR_S6SBT_SHIFT)) & PSI5_CH_S6SBR_S6SBT_MASK)
/*! @} */

/*! @name CH_S5SBR - Slot 5 Start Boundary Register */
/*! @{ */

#define PSI5_CH_S5SBR_S5SBT_MASK                 (0x7FFFU)
#define PSI5_CH_S5SBR_S5SBT_SHIFT                (0U)
#define PSI5_CH_S5SBR_S5SBT_WIDTH                (15U)
#define PSI5_CH_S5SBR_S5SBT(x)                   (((uint16_t)(((uint16_t)(x)) << PSI5_CH_S5SBR_S5SBT_SHIFT)) & PSI5_CH_S5SBR_S5SBT_MASK)
/*! @} */

/*! @name CH_SNEBR - Slot n End Boundary Register */
/*! @{ */

#define PSI5_CH_SNEBR_SnEBT_MASK                 (0x7FFFU)
#define PSI5_CH_SNEBR_SnEBT_SHIFT                (0U)
#define PSI5_CH_SNEBR_SnEBT_WIDTH                (15U)
#define PSI5_CH_SNEBR_SnEBT(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SNEBR_SnEBT_SHIFT)) & PSI5_CH_SNEBR_SnEBT_MASK)

#define PSI5_CH_SNEBR_SLOT_NO_MASK               (0x70000U)
#define PSI5_CH_SNEBR_SLOT_NO_SHIFT              (16U)
#define PSI5_CH_SNEBR_SLOT_NO_WIDTH              (3U)
#define PSI5_CH_SNEBR_SLOT_NO(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_CH_SNEBR_SLOT_NO_SHIFT)) & PSI5_CH_SNEBR_SLOT_NO_MASK)
/*! @} */

/*! @name CH_MDDIS_OFF - Manchestor Decoder Disable Offset */
/*! @{ */

#define PSI5_CH_MDDIS_OFF_MDDIS_OFF_MASK         (0x7FU)
#define PSI5_CH_MDDIS_OFF_MDDIS_OFF_SHIFT        (0U)
#define PSI5_CH_MDDIS_OFF_MDDIS_OFF_WIDTH        (7U)
#define PSI5_CH_MDDIS_OFF_MDDIS_OFF(x)           (((uint16_t)(((uint16_t)(x)) << PSI5_CH_MDDIS_OFF_MDDIS_OFF_SHIFT)) & PSI5_CH_MDDIS_OFF_MDDIS_OFF_MASK)
/*! @} */

/*! @name CH_DOBCR - Data Output Block Configuration Register */
/*! @{ */

#define PSI5_CH_DOBCR_SW_READY_MASK              (0x1U)
#define PSI5_CH_DOBCR_SW_READY_SHIFT             (0U)
#define PSI5_CH_DOBCR_SW_READY_WIDTH             (1U)
#define PSI5_CH_DOBCR_SW_READY(x)                (((uint16_t)(((uint16_t)(x)) << PSI5_CH_DOBCR_SW_READY_SHIFT)) & PSI5_CH_DOBCR_SW_READY_MASK)

#define PSI5_CH_DOBCR_OP_SEL_MASK                (0x2U)
#define PSI5_CH_DOBCR_OP_SEL_SHIFT               (1U)
#define PSI5_CH_DOBCR_OP_SEL_WIDTH               (1U)
#define PSI5_CH_DOBCR_OP_SEL(x)                  (((uint16_t)(((uint16_t)(x)) << PSI5_CH_DOBCR_OP_SEL_SHIFT)) & PSI5_CH_DOBCR_OP_SEL_MASK)

#define PSI5_CH_DOBCR_SP_PULSE_SEL_MASK          (0x4U)
#define PSI5_CH_DOBCR_SP_PULSE_SEL_SHIFT         (2U)
#define PSI5_CH_DOBCR_SP_PULSE_SEL_WIDTH         (1U)
#define PSI5_CH_DOBCR_SP_PULSE_SEL(x)            (((uint16_t)(((uint16_t)(x)) << PSI5_CH_DOBCR_SP_PULSE_SEL_SHIFT)) & PSI5_CH_DOBCR_SP_PULSE_SEL_MASK)

#define PSI5_CH_DOBCR_GTM_TRIG_SEL_MASK          (0x8U)
#define PSI5_CH_DOBCR_GTM_TRIG_SEL_SHIFT         (3U)
#define PSI5_CH_DOBCR_GTM_TRIG_SEL_WIDTH         (1U)
#define PSI5_CH_DOBCR_GTM_TRIG_SEL(x)            (((uint16_t)(((uint16_t)(x)) << PSI5_CH_DOBCR_GTM_TRIG_SEL_SHIFT)) & PSI5_CH_DOBCR_GTM_TRIG_SEL_MASK)

#define PSI5_CH_DOBCR_DEFAULT_SYNC_MASK          (0x10U)
#define PSI5_CH_DOBCR_DEFAULT_SYNC_SHIFT         (4U)
#define PSI5_CH_DOBCR_DEFAULT_SYNC_WIDTH         (1U)
#define PSI5_CH_DOBCR_DEFAULT_SYNC(x)            (((uint16_t)(((uint16_t)(x)) << PSI5_CH_DOBCR_DEFAULT_SYNC_SHIFT)) & PSI5_CH_DOBCR_DEFAULT_SYNC_MASK)

#define PSI5_CH_DOBCR_CMD_TYPE_MASK              (0xE0U)
#define PSI5_CH_DOBCR_CMD_TYPE_SHIFT             (5U)
#define PSI5_CH_DOBCR_CMD_TYPE_WIDTH             (3U)
#define PSI5_CH_DOBCR_CMD_TYPE(x)                (((uint16_t)(((uint16_t)(x)) << PSI5_CH_DOBCR_CMD_TYPE_SHIFT)) & PSI5_CH_DOBCR_CMD_TYPE_MASK)

#define PSI5_CH_DOBCR_DSR_RST_MASK               (0x100U)
#define PSI5_CH_DOBCR_DSR_RST_SHIFT              (8U)
#define PSI5_CH_DOBCR_DSR_RST_WIDTH              (1U)
#define PSI5_CH_DOBCR_DSR_RST(x)                 (((uint16_t)(((uint16_t)(x)) << PSI5_CH_DOBCR_DSR_RST_SHIFT)) & PSI5_CH_DOBCR_DSR_RST_MASK)

#define PSI5_CH_DOBCR_DBR_RST_MASK               (0x200U)
#define PSI5_CH_DOBCR_DBR_RST_SHIFT              (9U)
#define PSI5_CH_DOBCR_DBR_RST_WIDTH              (1U)
#define PSI5_CH_DOBCR_DBR_RST(x)                 (((uint16_t)(((uint16_t)(x)) << PSI5_CH_DOBCR_DBR_RST_SHIFT)) & PSI5_CH_DOBCR_DBR_RST_MASK)

#define PSI5_CH_DOBCR_DATA_LENGTH_MASK           (0xFC00U)
#define PSI5_CH_DOBCR_DATA_LENGTH_SHIFT          (10U)
#define PSI5_CH_DOBCR_DATA_LENGTH_WIDTH          (6U)
#define PSI5_CH_DOBCR_DATA_LENGTH(x)             (((uint16_t)(((uint16_t)(x)) << PSI5_CH_DOBCR_DATA_LENGTH_SHIFT)) & PSI5_CH_DOBCR_DATA_LENGTH_MASK)
/*! @} */

/*! @name CH_PW1D - Pulse Width for Data Bit Value 1 */
/*! @{ */

#define PSI5_CH_PW1D_Pulse_Width1_MASK           (0x7FU)
#define PSI5_CH_PW1D_Pulse_Width1_SHIFT          (0U)
#define PSI5_CH_PW1D_Pulse_Width1_WIDTH          (7U)
#define PSI5_CH_PW1D_Pulse_Width1(x)             (((uint16_t)(((uint16_t)(x)) << PSI5_CH_PW1D_Pulse_Width1_SHIFT)) & PSI5_CH_PW1D_Pulse_Width1_MASK)
/*! @} */

/*! @name CH_PW0D - Pulse Width for Data Bit Value 0 */
/*! @{ */

#define PSI5_CH_PW0D_Pulse_Width0_MASK           (0x7FU)
#define PSI5_CH_PW0D_Pulse_Width0_SHIFT          (0U)
#define PSI5_CH_PW0D_Pulse_Width0_WIDTH          (7U)
#define PSI5_CH_PW0D_Pulse_Width0(x)             (((uint16_t)(((uint16_t)(x)) << PSI5_CH_PW0D_Pulse_Width0_SHIFT)) & PSI5_CH_PW0D_Pulse_Width0_MASK)
/*! @} */

/*! @name CH_CIPR - Counter Initialize Pulse Register */
/*! @{ */

#define PSI5_CH_CIPR_CIPR_MASK                   (0xFFFFU)
#define PSI5_CH_CIPR_CIPR_SHIFT                  (0U)
#define PSI5_CH_CIPR_CIPR_WIDTH                  (16U)
#define PSI5_CH_CIPR_CIPR(x)                     (((uint16_t)(((uint16_t)(x)) << PSI5_CH_CIPR_CIPR_SHIFT)) & PSI5_CH_CIPR_CIPR_MASK)
/*! @} */

/*! @name CH_CTPR - Counter Target Pulse Register */
/*! @{ */

#define PSI5_CH_CTPR_CTPR_MASK                   (0xFFFFU)
#define PSI5_CH_CTPR_CTPR_SHIFT                  (0U)
#define PSI5_CH_CTPR_CTPR_WIDTH                  (16U)
#define PSI5_CH_CTPR_CTPR(x)                     (((uint16_t)(((uint16_t)(x)) << PSI5_CH_CTPR_CTPR_SHIFT)) & PSI5_CH_CTPR_CTPR_MASK)
/*! @} */

/*! @name CH_DPRL - Data Preparation Register Low */
/*! @{ */

#define PSI5_CH_DPRL_DPR_MASK                    (0xFFFFFFU)
#define PSI5_CH_DPRL_DPR_SHIFT                   (0U)
#define PSI5_CH_DPRL_DPR_WIDTH                   (24U)
#define PSI5_CH_DPRL_DPR(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DPRL_DPR_SHIFT)) & PSI5_CH_DPRL_DPR_MASK)
/*! @} */

/*! @name CH_DBRL - Data Buffer Register Low */
/*! @{ */

#define PSI5_CH_DBRL_DBR_MASK                    (0xFFFFFFFFU)
#define PSI5_CH_DBRL_DBR_SHIFT                   (0U)
#define PSI5_CH_DBRL_DBR_WIDTH                   (32U)
#define PSI5_CH_DBRL_DBR(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DBRL_DBR_SHIFT)) & PSI5_CH_DBRL_DBR_MASK)
/*! @} */

/*! @name CH_DBRH - Data Buffer Register High */
/*! @{ */

#define PSI5_CH_DBRH_DBR_MASK                    (0xFFFFFFFFU)
#define PSI5_CH_DBRH_DBR_SHIFT                   (0U)
#define PSI5_CH_DBRH_DBR_WIDTH                   (32U)
#define PSI5_CH_DBRH_DBR(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DBRH_DBR_SHIFT)) & PSI5_CH_DBRH_DBR_MASK)
/*! @} */

/*! @name CH_DSRL - Data Shift Register Low */
/*! @{ */

#define PSI5_CH_DSRL_DSR_MASK                    (0xFFFFFFFFU)
#define PSI5_CH_DSRL_DSR_SHIFT                   (0U)
#define PSI5_CH_DSRL_DSR_WIDTH                   (32U)
#define PSI5_CH_DSRL_DSR(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DSRL_DSR_SHIFT)) & PSI5_CH_DSRL_DSR_MASK)
/*! @} */

/*! @name CH_DSRH - Data Shift Register High */
/*! @{ */

#define PSI5_CH_DSRH_DSR_MASK                    (0xFFFFFFFFU)
#define PSI5_CH_DSRH_DSR_SHIFT                   (0U)
#define PSI5_CH_DSRH_DSR_WIDTH                   (32U)
#define PSI5_CH_DSRH_DSR(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_CH_DSRH_DSR_SHIFT)) & PSI5_CH_DSRH_DSR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PSI5_Register_Masks */

/*!
 * @}
 */ /* end of group PSI5_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_PSI5_H_) */
