/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_PMC.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_PMC
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
#if !defined(S32K566_PMC_H_)  /* Check if memory map has not been already included */
#define S32K566_PMC_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct PMC_Struct {
  __IO uint32_t MONFLAG;                           /**< Monitor Flags, offset: 0x0 */
  __I  uint32_t MONSTAT;                           /**< Monitor Status, offset: 0x4 */
  __IO uint32_t CONFIG;                            /**< PMC Configuration, offset: 0x8 */
  __I  uint32_t VERID;                             /**< Version ID, offset: 0xC */
  __IO uint32_t GNGFLAG;                           /**< Go/No-Go Flags, offset: 0x10 */
  __IO uint32_t MONSELF;                           /**< Monitor Self-Test, offset: 0x14 */
} PMC_Type, *PMC_MemMapPtr;

/** Number of instances of the PMC module. */
#define PMC_INSTANCE_COUNT                       (1u)

/* PMC - Peripheral instance base addresses */
/** Peripheral LPE_PMC base address */
#define IP_LPE_PMC_BASE                          (0x42070000u)
/** Peripheral LPE_PMC base pointer */
#define IP_LPE_PMC                               ((PMC_Type *)IP_LPE_PMC_BASE)
/** Array initializer of PMC peripheral base addresses */
#define IP_PMC_BASE_ADDRS                        { IP_LPE_PMC_BASE }
/** Array initializer of PMC peripheral base pointers */
#define IP_PMC_BASE_PTRS                         { IP_LPE_PMC }

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/*! @name MONFLAG - Monitor Flags */
/*! @{ */

#define PMC_MONFLAG_LVDB18F_MASK                 (0x1U)
#define PMC_MONFLAG_LVDB18F_SHIFT                (0U)
#define PMC_MONFLAG_LVDB18F_WIDTH                (1U)
#define PMC_MONFLAG_LVDB18F(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_LVDB18F_SHIFT)) & PMC_MONFLAG_LVDB18F_MASK)

#define PMC_MONFLAG_LVDB33F_MASK                 (0x2U)
#define PMC_MONFLAG_LVDB33F_SHIFT                (1U)
#define PMC_MONFLAG_LVDB33F_WIDTH                (1U)
#define PMC_MONFLAG_LVDB33F(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_LVDB33F_SHIFT)) & PMC_MONFLAG_LVDB33F_MASK)

#define PMC_MONFLAG_LVDLVDSF_MASK                (0x4U)
#define PMC_MONFLAG_LVDLVDSF_SHIFT               (2U)
#define PMC_MONFLAG_LVDLVDSF_WIDTH               (1U)
#define PMC_MONFLAG_LVDLVDSF(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_LVDLVDSF_SHIFT)) & PMC_MONFLAG_LVDLVDSF_MASK)

#define PMC_MONFLAG_HVD1F_MASK                   (0x100U)
#define PMC_MONFLAG_HVD1F_SHIFT                  (8U)
#define PMC_MONFLAG_HVD1F_WIDTH                  (1U)
#define PMC_MONFLAG_HVD1F(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_HVD1F_SHIFT)) & PMC_MONFLAG_HVD1F_MASK)

#define PMC_MONFLAG_HVD2F_MASK                   (0x200U)
#define PMC_MONFLAG_HVD2F_SHIFT                  (9U)
#define PMC_MONFLAG_HVD2F_WIDTH                  (1U)
#define PMC_MONFLAG_HVD2F(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_HVD2F_SHIFT)) & PMC_MONFLAG_HVD2F_MASK)

#define PMC_MONFLAG_HVD18_0F_MASK                (0x400U)
#define PMC_MONFLAG_HVD18_0F_SHIFT               (10U)
#define PMC_MONFLAG_HVD18_0F_WIDTH               (1U)
#define PMC_MONFLAG_HVD18_0F(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_HVD18_0F_SHIFT)) & PMC_MONFLAG_HVD18_0F_MASK)

#define PMC_MONFLAG_HVD18_1F_MASK                (0x800U)
#define PMC_MONFLAG_HVD18_1F_SHIFT               (11U)
#define PMC_MONFLAG_HVD18_1F_WIDTH               (1U)
#define PMC_MONFLAG_HVD18_1F(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_HVD18_1F_SHIFT)) & PMC_MONFLAG_HVD18_1F_MASK)

#define PMC_MONFLAG_HVDAF_MASK                   (0x1000U)
#define PMC_MONFLAG_HVDAF_SHIFT                  (12U)
#define PMC_MONFLAG_HVDAF_WIDTH                  (1U)
#define PMC_MONFLAG_HVDAF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_HVDAF_SHIFT)) & PMC_MONFLAG_HVDAF_MASK)

#define PMC_MONFLAG_HVDBF_MASK                   (0x2000U)
#define PMC_MONFLAG_HVDBF_SHIFT                  (13U)
#define PMC_MONFLAG_HVDBF_WIDTH                  (1U)
#define PMC_MONFLAG_HVDBF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_HVDBF_SHIFT)) & PMC_MONFLAG_HVDBF_MASK)

#define PMC_MONFLAG_HVDLVDSF_MASK                (0x4000U)
#define PMC_MONFLAG_HVDLVDSF_SHIFT               (14U)
#define PMC_MONFLAG_HVDLVDSF_WIDTH               (1U)
#define PMC_MONFLAG_HVDLVDSF(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_HVDLVDSF_SHIFT)) & PMC_MONFLAG_HVDLVDSF_MASK)

#define PMC_MONFLAG_LVR0RF_MASK                  (0x10000U)
#define PMC_MONFLAG_LVR0RF_SHIFT                 (16U)
#define PMC_MONFLAG_LVR0RF_WIDTH                 (1U)
#define PMC_MONFLAG_LVR0RF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_LVR0RF_SHIFT)) & PMC_MONFLAG_LVR0RF_MASK)

#define PMC_MONFLAG_LVR1FF_MASK                  (0x20000U)
#define PMC_MONFLAG_LVR1FF_SHIFT                 (17U)
#define PMC_MONFLAG_LVR1FF_WIDTH                 (1U)
#define PMC_MONFLAG_LVR1FF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_LVR1FF_SHIFT)) & PMC_MONFLAG_LVR1FF_MASK)

#define PMC_MONFLAG_LVR2FF_MASK                  (0x40000U)
#define PMC_MONFLAG_LVR2FF_SHIFT                 (18U)
#define PMC_MONFLAG_LVR2FF_WIDTH                 (1U)
#define PMC_MONFLAG_LVR2FF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_LVR2FF_SHIFT)) & PMC_MONFLAG_LVR2FF_MASK)

#define PMC_MONFLAG_LVR2RF_MASK                  (0x80000U)
#define PMC_MONFLAG_LVR2RF_SHIFT                 (19U)
#define PMC_MONFLAG_LVR2RF_WIDTH                 (1U)
#define PMC_MONFLAG_LVR2RF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_LVR2RF_SHIFT)) & PMC_MONFLAG_LVR2RF_MASK)

#define PMC_MONFLAG_LVR18_0FF_MASK               (0x100000U)
#define PMC_MONFLAG_LVR18_0FF_SHIFT              (20U)
#define PMC_MONFLAG_LVR18_0FF_WIDTH              (1U)
#define PMC_MONFLAG_LVR18_0FF(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_LVR18_0FF_SHIFT)) & PMC_MONFLAG_LVR18_0FF_MASK)

#define PMC_MONFLAG_LVR18_0RF_MASK               (0x200000U)
#define PMC_MONFLAG_LVR18_0RF_SHIFT              (21U)
#define PMC_MONFLAG_LVR18_0RF_WIDTH              (1U)
#define PMC_MONFLAG_LVR18_0RF(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_LVR18_0RF_SHIFT)) & PMC_MONFLAG_LVR18_0RF_MASK)

#define PMC_MONFLAG_LVR18_1FF_MASK               (0x400000U)
#define PMC_MONFLAG_LVR18_1FF_SHIFT              (22U)
#define PMC_MONFLAG_LVR18_1FF_WIDTH              (1U)
#define PMC_MONFLAG_LVR18_1FF(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_LVR18_1FF_SHIFT)) & PMC_MONFLAG_LVR18_1FF_MASK)

#define PMC_MONFLAG_LVR18_1RF_MASK               (0x800000U)
#define PMC_MONFLAG_LVR18_1RF_SHIFT              (23U)
#define PMC_MONFLAG_LVR18_1RF_WIDTH              (1U)
#define PMC_MONFLAG_LVR18_1RF(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_LVR18_1RF_SHIFT)) & PMC_MONFLAG_LVR18_1RF_MASK)

#define PMC_MONFLAG_LVRAFF_MASK                  (0x1000000U)
#define PMC_MONFLAG_LVRAFF_SHIFT                 (24U)
#define PMC_MONFLAG_LVRAFF_WIDTH                 (1U)
#define PMC_MONFLAG_LVRAFF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_LVRAFF_SHIFT)) & PMC_MONFLAG_LVRAFF_MASK)

#define PMC_MONFLAG_LVRARF_MASK                  (0x2000000U)
#define PMC_MONFLAG_LVRARF_SHIFT                 (25U)
#define PMC_MONFLAG_LVRARF_WIDTH                 (1U)
#define PMC_MONFLAG_LVRARF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_LVRARF_SHIFT)) & PMC_MONFLAG_LVRARF_MASK)

#define PMC_MONFLAG_PORF_MASK                    (0x80000000U)
#define PMC_MONFLAG_PORF_SHIFT                   (31U)
#define PMC_MONFLAG_PORF_WIDTH                   (1U)
#define PMC_MONFLAG_PORF(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_MONFLAG_PORF_SHIFT)) & PMC_MONFLAG_PORF_MASK)
/*! @} */

/*! @name MONSTAT - Monitor Status */
/*! @{ */

#define PMC_MONSTAT_LVDB18S_MASK                 (0x1U)
#define PMC_MONSTAT_LVDB18S_SHIFT                (0U)
#define PMC_MONSTAT_LVDB18S_WIDTH                (1U)
#define PMC_MONSTAT_LVDB18S(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_MONSTAT_LVDB18S_SHIFT)) & PMC_MONSTAT_LVDB18S_MASK)

#define PMC_MONSTAT_LVDB33S_MASK                 (0x2U)
#define PMC_MONSTAT_LVDB33S_SHIFT                (1U)
#define PMC_MONSTAT_LVDB33S_WIDTH                (1U)
#define PMC_MONSTAT_LVDB33S(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_MONSTAT_LVDB33S_SHIFT)) & PMC_MONSTAT_LVDB33S_MASK)

#define PMC_MONSTAT_LVDLVDSS_MASK                (0x4U)
#define PMC_MONSTAT_LVDLVDSS_SHIFT               (2U)
#define PMC_MONSTAT_LVDLVDSS_WIDTH               (1U)
#define PMC_MONSTAT_LVDLVDSS(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_MONSTAT_LVDLVDSS_SHIFT)) & PMC_MONSTAT_LVDLVDSS_MASK)

#define PMC_MONSTAT_HVD1S_MASK                   (0x100U)
#define PMC_MONSTAT_HVD1S_SHIFT                  (8U)
#define PMC_MONSTAT_HVD1S_WIDTH                  (1U)
#define PMC_MONSTAT_HVD1S(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_MONSTAT_HVD1S_SHIFT)) & PMC_MONSTAT_HVD1S_MASK)

#define PMC_MONSTAT_HVD2S_MASK                   (0x200U)
#define PMC_MONSTAT_HVD2S_SHIFT                  (9U)
#define PMC_MONSTAT_HVD2S_WIDTH                  (1U)
#define PMC_MONSTAT_HVD2S(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_MONSTAT_HVD2S_SHIFT)) & PMC_MONSTAT_HVD2S_MASK)

#define PMC_MONSTAT_HVD18_0S_MASK                (0x400U)
#define PMC_MONSTAT_HVD18_0S_SHIFT               (10U)
#define PMC_MONSTAT_HVD18_0S_WIDTH               (1U)
#define PMC_MONSTAT_HVD18_0S(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_MONSTAT_HVD18_0S_SHIFT)) & PMC_MONSTAT_HVD18_0S_MASK)

#define PMC_MONSTAT_HVD18_1S_MASK                (0x800U)
#define PMC_MONSTAT_HVD18_1S_SHIFT               (11U)
#define PMC_MONSTAT_HVD18_1S_WIDTH               (1U)
#define PMC_MONSTAT_HVD18_1S(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_MONSTAT_HVD18_1S_SHIFT)) & PMC_MONSTAT_HVD18_1S_MASK)

#define PMC_MONSTAT_HVDAS_MASK                   (0x1000U)
#define PMC_MONSTAT_HVDAS_SHIFT                  (12U)
#define PMC_MONSTAT_HVDAS_WIDTH                  (1U)
#define PMC_MONSTAT_HVDAS(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_MONSTAT_HVDAS_SHIFT)) & PMC_MONSTAT_HVDAS_MASK)

#define PMC_MONSTAT_HVDBS_MASK                   (0x2000U)
#define PMC_MONSTAT_HVDBS_SHIFT                  (13U)
#define PMC_MONSTAT_HVDBS_WIDTH                  (1U)
#define PMC_MONSTAT_HVDBS(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_MONSTAT_HVDBS_SHIFT)) & PMC_MONSTAT_HVDBS_MASK)

#define PMC_MONSTAT_HVDLVDSS_MASK                (0x4000U)
#define PMC_MONSTAT_HVDLVDSS_SHIFT               (14U)
#define PMC_MONSTAT_HVDLVDSS_WIDTH               (1U)
#define PMC_MONSTAT_HVDLVDSS(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_MONSTAT_HVDLVDSS_SHIFT)) & PMC_MONSTAT_HVDLVDSS_MASK)
/*! @} */

/*! @name CONFIG - PMC Configuration */
/*! @{ */

#define PMC_CONFIG_VDDRAMEN_MASK                 (0x1U)
#define PMC_CONFIG_VDDRAMEN_SHIFT                (0U)
#define PMC_CONFIG_VDDRAMEN_WIDTH                (1U)
#define PMC_CONFIG_VDDRAMEN(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_VDDRAMEN_SHIFT)) & PMC_CONFIG_VDDRAMEN_MASK)

#define PMC_CONFIG_LVRAREC_MASK                  (0x2U)
#define PMC_CONFIG_LVRAREC_SHIFT                 (1U)
#define PMC_CONFIG_LVRAREC_WIDTH                 (1U)
#define PMC_CONFIG_LVRAREC(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_LVRAREC_SHIFT)) & PMC_CONFIG_LVRAREC_MASK)

#define PMC_CONFIG_HVDIE_MASK                    (0x100U)
#define PMC_CONFIG_HVDIE_SHIFT                   (8U)
#define PMC_CONFIG_HVDIE_WIDTH                   (1U)
#define PMC_CONFIG_HVDIE(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_HVDIE_SHIFT)) & PMC_CONFIG_HVDIE_MASK)

#define PMC_CONFIG_LVDBIE_MASK                   (0x200U)
#define PMC_CONFIG_LVDBIE_SHIFT                  (9U)
#define PMC_CONFIG_LVDBIE_WIDTH                  (1U)
#define PMC_CONFIG_LVDBIE(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_LVDBIE_SHIFT)) & PMC_CONFIG_LVDBIE_MASK)

#define PMC_CONFIG_LVDSIE_MASK                   (0x400U)
#define PMC_CONFIG_LVDSIE_SHIFT                  (10U)
#define PMC_CONFIG_LVDSIE_WIDTH                  (1U)
#define PMC_CONFIG_LVDSIE(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_LVDSIE_SHIFT)) & PMC_CONFIG_LVDSIE_MASK)

#define PMC_CONFIG_SELFEN_MASK                   (0x10000U)
#define PMC_CONFIG_SELFEN_SHIFT                  (16U)
#define PMC_CONFIG_SELFEN_WIDTH                  (1U)
#define PMC_CONFIG_SELFEN(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_SELFEN_SHIFT)) & PMC_CONFIG_SELFEN_MASK)

#define PMC_CONFIG_PGOODMASK_MASK                (0x1000000U)
#define PMC_CONFIG_PGOODMASK_SHIFT               (24U)
#define PMC_CONFIG_PGOODMASK_WIDTH               (1U)
#define PMC_CONFIG_PGOODMASK(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_PGOODMASK_SHIFT)) & PMC_CONFIG_PGOODMASK_MASK)
/*! @} */

/*! @name VERID - Version ID */
/*! @{ */

#define PMC_VERID_MINOR_MASK                     (0xFF0000U)
#define PMC_VERID_MINOR_SHIFT                    (16U)
#define PMC_VERID_MINOR_WIDTH                    (8U)
#define PMC_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_VERID_MINOR_SHIFT)) & PMC_VERID_MINOR_MASK)

#define PMC_VERID_MAJOR_MASK                     (0xFF000000U)
#define PMC_VERID_MAJOR_SHIFT                    (24U)
#define PMC_VERID_MAJOR_WIDTH                    (8U)
#define PMC_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_VERID_MAJOR_SHIFT)) & PMC_VERID_MAJOR_MASK)
/*! @} */

/*! @name GNGFLAG - Go/No-Go Flags */
/*! @{ */

#define PMC_GNGFLAG_GNGVIOREFLOF_MASK            (0x1U)
#define PMC_GNGFLAG_GNGVIOREFLOF_SHIFT           (0U)
#define PMC_GNGFLAG_GNGVIOREFLOF_WIDTH           (1U)
#define PMC_GNGFLAG_GNGVIOREFLOF(x)              (((uint32_t)(((uint32_t)(x)) << PMC_GNGFLAG_GNGVIOREFLOF_SHIFT)) & PMC_GNGFLAG_GNGVIOREFLOF_MASK)

#define PMC_GNGFLAG_GNGVIOREFHIF_MASK            (0x2U)
#define PMC_GNGFLAG_GNGVIOREFHIF_SHIFT           (1U)
#define PMC_GNGFLAG_GNGVIOREFHIF_WIDTH           (1U)
#define PMC_GNGFLAG_GNGVIOREFHIF(x)              (((uint32_t)(((uint32_t)(x)) << PMC_GNGFLAG_GNGVIOREFHIF_SHIFT)) & PMC_GNGFLAG_GNGVIOREFHIF_MASK)

#define PMC_GNGFLAG_GNGFASTPLLF_MASK             (0x10U)
#define PMC_GNGFLAG_GNGFASTPLLF_SHIFT            (4U)
#define PMC_GNGFLAG_GNGFASTPLLF_WIDTH            (1U)
#define PMC_GNGFLAG_GNGFASTPLLF(x)               (((uint32_t)(((uint32_t)(x)) << PMC_GNGFLAG_GNGFASTPLLF_SHIFT)) & PMC_GNGFLAG_GNGFASTPLLF_MASK)

#define PMC_GNGFLAG_GNGV181XF_MASK               (0xFE0U)
#define PMC_GNGFLAG_GNGV181XF_SHIFT              (5U)
#define PMC_GNGFLAG_GNGV181XF_WIDTH              (7U)
#define PMC_GNGFLAG_GNGV181XF(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_GNGFLAG_GNGV181XF_SHIFT)) & PMC_GNGFLAG_GNGV181XF_MASK)
/*! @} */

/*! @name MONSELF - Monitor Self-Test */
/*! @{ */

#define PMC_MONSELF_SEL_MASK                     (0x1FU)
#define PMC_MONSELF_SEL_SHIFT                    (0U)
#define PMC_MONSELF_SEL_WIDTH                    (5U)
#define PMC_MONSELF_SEL(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_MONSELF_SEL_SHIFT)) & PMC_MONSELF_SEL_MASK)

#define PMC_MONSELF_MASK_MASK                    (0x200U)
#define PMC_MONSELF_MASK_SHIFT                   (9U)
#define PMC_MONSELF_MASK_WIDTH                   (1U)
#define PMC_MONSELF_MASK(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_MONSELF_MASK_SHIFT)) & PMC_MONSELF_MASK_MASK)

#define PMC_MONSELF_ON_MASK                      (0x80000U)
#define PMC_MONSELF_ON_SHIFT                     (19U)
#define PMC_MONSELF_ON_WIDTH                     (1U)
#define PMC_MONSELF_ON(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_MONSELF_ON_SHIFT)) & PMC_MONSELF_ON_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PMC_Register_Masks */

/*!
 * @}
 */ /* end of group PMC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_PMC_H_) */
