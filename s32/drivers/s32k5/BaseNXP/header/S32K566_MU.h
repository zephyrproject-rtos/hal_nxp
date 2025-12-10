/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_MU.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_MU
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
#if !defined(S32K566_MU_H_)  /* Check if memory map has not been already included */
#define S32K566_MU_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MU_Peripheral_Access_Layer MU Peripheral Access Layer
 * @{
 */

/** MU - Size of Registers Arrays */
#define MU_TR_COUNT                               4u
#define MU_RR_COUNT                               4u

/** MU - Register Layout Typedef */
typedef struct MU_Struct {
  __I  uint32_t VER;                               /**< Version ID, offset: 0x0 */
  __I  uint32_t PAR;                               /**< Parameter, offset: 0x4 */
  __IO uint32_t CR;                                /**< Control, offset: 0x8 */
  __IO uint32_t SR;                                /**< Status, offset: 0xC */
  __IO uint32_t CCR0;                              /**< Core Control 0, offset: 0x10 */
  __IO uint32_t CIER0;                             /**< Core Interrupt Enable 0, offset: 0x14 */
  __IO uint32_t CSSR0;                             /**< Core Sticky Status 0, offset: 0x18 */
  __I  uint32_t CSR0;                              /**< Core Status 0, offset: 0x1C, not available in all instances (available on 4 out of 8) */
  uint8_t RESERVED_0[224];
  __IO uint32_t FCR;                               /**< Flag Control, offset: 0x100 */
  __I  uint32_t FSR;                               /**< Flag Status, offset: 0x104 */
  uint8_t RESERVED_1[8];
  __IO uint32_t GIER;                              /**< General-Purpose Interrupt Enable, offset: 0x110 */
  __IO uint32_t GCR;                               /**< General-Purpose Control, offset: 0x114 */
  __IO uint32_t GSR;                               /**< General-purpose Status, offset: 0x118 */
  uint8_t RESERVED_2[4];
  __IO uint32_t TCR;                               /**< Transmit Control, offset: 0x120 */
  __I  uint32_t TSR;                               /**< Transmit Status, offset: 0x124 */
  __IO uint32_t RCR;                               /**< Receive Control, offset: 0x128 */
  __I  uint32_t RSR;                               /**< Receive Status, offset: 0x12C */
  uint8_t RESERVED_3[208];
  __IO uint32_t TR[MU_TR_COUNT];                   /**< Transmit, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_4[112];
  __I  uint32_t RR[MU_RR_COUNT];                   /**< Receive, array offset: 0x280, array step: 0x4 */
} MU_Type, *MU_MemMapPtr;

/** Number of instances of the MU module. */
#define MU_INSTANCE_COUNT                        (8u)

/* MU - Peripheral instance base addresses */
/** Peripheral DSP4__MU0__MUA base address */
#define IP_DSP4__MU0__MUA_BASE                   (0x40A0C000u)
/** Peripheral DSP4__MU0__MUA base pointer */
#define IP_DSP4__MU0__MUA                        ((MU_Type *)IP_DSP4__MU0__MUA_BASE)
/** Peripheral DSP4__MU0__MUB base address */
#define IP_DSP4__MU0__MUB_BASE                   (0x42604000u)
/** Peripheral DSP4__MU0__MUB base pointer */
#define IP_DSP4__MU0__MUB                        ((MU_Type *)IP_DSP4__MU0__MUB_BASE)
/** Peripheral DSP4__MU1__MUA base address */
#define IP_DSP4__MU1__MUA_BASE                   (0x40A10000u)
/** Peripheral DSP4__MU1__MUA base pointer */
#define IP_DSP4__MU1__MUA                        ((MU_Type *)IP_DSP4__MU1__MUA_BASE)
/** Peripheral DSP4__MU1__MUB base address */
#define IP_DSP4__MU1__MUB_BASE                   (0x42608000u)
/** Peripheral DSP4__MU1__MUB base pointer */
#define IP_DSP4__MU1__MUB                        ((MU_Type *)IP_DSP4__MU1__MUB_BASE)
/** Peripheral DSP4__MU2__MUA base address */
#define IP_DSP4__MU2__MUA_BASE                   (0x40A14000u)
/** Peripheral DSP4__MU2__MUA base pointer */
#define IP_DSP4__MU2__MUA                        ((MU_Type *)IP_DSP4__MU2__MUA_BASE)
/** Peripheral DSP4__MU2__MUB base address */
#define IP_DSP4__MU2__MUB_BASE                   (0x4260C000u)
/** Peripheral DSP4__MU2__MUB base pointer */
#define IP_DSP4__MU2__MUB                        ((MU_Type *)IP_DSP4__MU2__MUB_BASE)
/** Peripheral DSP4__MU3__MUA base address */
#define IP_DSP4__MU3__MUA_BASE                   (0x40A18000u)
/** Peripheral DSP4__MU3__MUA base pointer */
#define IP_DSP4__MU3__MUA                        ((MU_Type *)IP_DSP4__MU3__MUA_BASE)
/** Peripheral DSP4__MU3__MUB base address */
#define IP_DSP4__MU3__MUB_BASE                   (0x42610000u)
/** Peripheral DSP4__MU3__MUB base pointer */
#define IP_DSP4__MU3__MUB                        ((MU_Type *)IP_DSP4__MU3__MUB_BASE)
/** Array initializer of MU peripheral base addresses */
#define IP_MU_BASE_ADDRS                         { IP_DSP4__MU0__MUA_BASE, IP_DSP4__MU0__MUB_BASE, IP_DSP4__MU1__MUA_BASE, IP_DSP4__MU1__MUB_BASE, IP_DSP4__MU2__MUA_BASE, IP_DSP4__MU2__MUB_BASE, IP_DSP4__MU3__MUA_BASE, IP_DSP4__MU3__MUB_BASE }
/** Array initializer of MU peripheral base pointers */
#define IP_MU_BASE_PTRS                          { IP_DSP4__MU0__MUA, IP_DSP4__MU0__MUB, IP_DSP4__MU1__MUA, IP_DSP4__MU1__MUB, IP_DSP4__MU2__MUA, IP_DSP4__MU2__MUB, IP_DSP4__MU3__MUA, IP_DSP4__MU3__MUB }

/* ----------------------------------------------------------------------------
   -- MU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MU_Register_Masks MU Register Masks
 * @{
 */

/*! @name VER - Version ID */
/*! @{ */

#define MU_VER_FEATURE_MASK                      (0xFFFFU)
#define MU_VER_FEATURE_SHIFT                     (0U)
#define MU_VER_FEATURE_WIDTH                     (16U)
#define MU_VER_FEATURE(x)                        (((uint32_t)(((uint32_t)(x)) << MU_VER_FEATURE_SHIFT)) & MU_VER_FEATURE_MASK)

#define MU_VER_MINOR_MASK                        (0xFF0000U)
#define MU_VER_MINOR_SHIFT                       (16U)
#define MU_VER_MINOR_WIDTH                       (8U)
#define MU_VER_MINOR(x)                          (((uint32_t)(((uint32_t)(x)) << MU_VER_MINOR_SHIFT)) & MU_VER_MINOR_MASK)

#define MU_VER_MAJOR_MASK                        (0xFF000000U)
#define MU_VER_MAJOR_SHIFT                       (24U)
#define MU_VER_MAJOR_WIDTH                       (8U)
#define MU_VER_MAJOR(x)                          (((uint32_t)(((uint32_t)(x)) << MU_VER_MAJOR_SHIFT)) & MU_VER_MAJOR_MASK)
/*! @} */

/*! @name PAR - Parameter */
/*! @{ */

#define MU_PAR_TR_NUM_MASK                       (0xFFU)
#define MU_PAR_TR_NUM_SHIFT                      (0U)
#define MU_PAR_TR_NUM_WIDTH                      (8U)
#define MU_PAR_TR_NUM(x)                         (((uint32_t)(((uint32_t)(x)) << MU_PAR_TR_NUM_SHIFT)) & MU_PAR_TR_NUM_MASK)

#define MU_PAR_RR_NUM_MASK                       (0xFF00U)
#define MU_PAR_RR_NUM_SHIFT                      (8U)
#define MU_PAR_RR_NUM_WIDTH                      (8U)
#define MU_PAR_RR_NUM(x)                         (((uint32_t)(((uint32_t)(x)) << MU_PAR_RR_NUM_SHIFT)) & MU_PAR_RR_NUM_MASK)

#define MU_PAR_GIR_NUM_MASK                      (0xFF0000U)
#define MU_PAR_GIR_NUM_SHIFT                     (16U)
#define MU_PAR_GIR_NUM_WIDTH                     (8U)
#define MU_PAR_GIR_NUM(x)                        (((uint32_t)(((uint32_t)(x)) << MU_PAR_GIR_NUM_SHIFT)) & MU_PAR_GIR_NUM_MASK)

#define MU_PAR_FLAG_WIDTH_MASK                   (0xFF000000U)
#define MU_PAR_FLAG_WIDTH_SHIFT                  (24U)
#define MU_PAR_FLAG_WIDTH_WIDTH                  (8U)
#define MU_PAR_FLAG_WIDTH(x)                     (((uint32_t)(((uint32_t)(x)) << MU_PAR_FLAG_WIDTH_SHIFT)) & MU_PAR_FLAG_WIDTH_MASK)
/*! @} */

/*! @name CR - Control */
/*! @{ */

#define MU_CR_MUR_MASK                           (0x1U)
#define MU_CR_MUR_SHIFT                          (0U)
#define MU_CR_MUR_WIDTH                          (1U)
#define MU_CR_MUR(x)                             (((uint32_t)(((uint32_t)(x)) << MU_CR_MUR_SHIFT)) & MU_CR_MUR_MASK)

#define MU_CR_MURIE_MASK                         (0x2U)
#define MU_CR_MURIE_SHIFT                        (1U)
#define MU_CR_MURIE_WIDTH                        (1U)
#define MU_CR_MURIE(x)                           (((uint32_t)(((uint32_t)(x)) << MU_CR_MURIE_SHIFT)) & MU_CR_MURIE_MASK)
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define MU_SR_MURS_MASK                          (0x1U)
#define MU_SR_MURS_SHIFT                         (0U)
#define MU_SR_MURS_WIDTH                         (1U)
#define MU_SR_MURS(x)                            (((uint32_t)(((uint32_t)(x)) << MU_SR_MURS_SHIFT)) & MU_SR_MURS_MASK)

#define MU_SR_MURIP_MASK                         (0x2U)
#define MU_SR_MURIP_SHIFT                        (1U)
#define MU_SR_MURIP_WIDTH                        (1U)
#define MU_SR_MURIP(x)                           (((uint32_t)(((uint32_t)(x)) << MU_SR_MURIP_SHIFT)) & MU_SR_MURIP_MASK)

#define MU_SR_EP_MASK                            (0x4U)
#define MU_SR_EP_SHIFT                           (2U)
#define MU_SR_EP_WIDTH                           (1U)
#define MU_SR_EP(x)                              (((uint32_t)(((uint32_t)(x)) << MU_SR_EP_SHIFT)) & MU_SR_EP_MASK)

#define MU_SR_FUP_MASK                           (0x8U)
#define MU_SR_FUP_SHIFT                          (3U)
#define MU_SR_FUP_WIDTH                          (1U)
#define MU_SR_FUP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_FUP_SHIFT)) & MU_SR_FUP_MASK)

#define MU_SR_GIRP_MASK                          (0x10U)
#define MU_SR_GIRP_SHIFT                         (4U)
#define MU_SR_GIRP_WIDTH                         (1U)
#define MU_SR_GIRP(x)                            (((uint32_t)(((uint32_t)(x)) << MU_SR_GIRP_SHIFT)) & MU_SR_GIRP_MASK)

#define MU_SR_TEP_MASK                           (0x20U)
#define MU_SR_TEP_SHIFT                          (5U)
#define MU_SR_TEP_WIDTH                          (1U)
#define MU_SR_TEP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_TEP_SHIFT)) & MU_SR_TEP_MASK)

#define MU_SR_RFP_MASK                           (0x40U)
#define MU_SR_RFP_SHIFT                          (6U)
#define MU_SR_RFP_WIDTH                          (1U)
#define MU_SR_RFP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_RFP_SHIFT)) & MU_SR_RFP_MASK)

#define MU_SR_CEP_MASK                           (0x80U)
#define MU_SR_CEP_SHIFT                          (7U)
#define MU_SR_CEP_WIDTH                          (1U)
#define MU_SR_CEP(x)                             (((uint32_t)(((uint32_t)(x)) << MU_SR_CEP_SHIFT)) & MU_SR_CEP_MASK)
/*! @} */

/*! @name CCR0 - Core Control 0 */
/*! @{ */

#define MU_CCR0_NMI_MASK                         (0x1U)
#define MU_CCR0_NMI_SHIFT                        (0U)
#define MU_CCR0_NMI_WIDTH                        (1U)
#define MU_CCR0_NMI(x)                           (((uint32_t)(((uint32_t)(x)) << MU_CCR0_NMI_SHIFT)) & MU_CCR0_NMI_MASK)
/*! @} */

/*! @name CIER0 - Core Interrupt Enable 0 */
/*! @{ */

#define MU_CIER0_RUNIE_MASK                      (0x4U)
#define MU_CIER0_RUNIE_SHIFT                     (2U)
#define MU_CIER0_RUNIE_WIDTH                     (1U)
#define MU_CIER0_RUNIE(x)                        (((uint32_t)(((uint32_t)(x)) << MU_CIER0_RUNIE_SHIFT)) & MU_CIER0_RUNIE_MASK)

#define MU_CIER0_RAIE_MASK                       (0x8U)
#define MU_CIER0_RAIE_SHIFT                      (3U)
#define MU_CIER0_RAIE_WIDTH                      (1U)
#define MU_CIER0_RAIE(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CIER0_RAIE_SHIFT)) & MU_CIER0_RAIE_MASK)

#define MU_CIER0_HALTIE_MASK                     (0x10U)
#define MU_CIER0_HALTIE_SHIFT                    (4U)
#define MU_CIER0_HALTIE_WIDTH                    (1U)
#define MU_CIER0_HALTIE(x)                       (((uint32_t)(((uint32_t)(x)) << MU_CIER0_HALTIE_SHIFT)) & MU_CIER0_HALTIE_MASK)

#define MU_CIER0_WAITIE_MASK                     (0x20U)
#define MU_CIER0_WAITIE_SHIFT                    (5U)
#define MU_CIER0_WAITIE_WIDTH                    (1U)
#define MU_CIER0_WAITIE(x)                       (((uint32_t)(((uint32_t)(x)) << MU_CIER0_WAITIE_SHIFT)) & MU_CIER0_WAITIE_MASK)

#define MU_CIER0_STOPIE_MASK                     (0x40U)
#define MU_CIER0_STOPIE_SHIFT                    (6U)
#define MU_CIER0_STOPIE_WIDTH                    (1U)
#define MU_CIER0_STOPIE(x)                       (((uint32_t)(((uint32_t)(x)) << MU_CIER0_STOPIE_SHIFT)) & MU_CIER0_STOPIE_MASK)

#define MU_CIER0_PDIE_MASK                       (0x80U)
#define MU_CIER0_PDIE_SHIFT                      (7U)
#define MU_CIER0_PDIE_WIDTH                      (1U)
#define MU_CIER0_PDIE(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CIER0_PDIE_SHIFT)) & MU_CIER0_PDIE_MASK)
/*! @} */

/*! @name CSSR0 - Core Sticky Status 0 */
/*! @{ */

#define MU_CSSR0_NMIC_MASK                       (0x1U)
#define MU_CSSR0_NMIC_SHIFT                      (0U)
#define MU_CSSR0_NMIC_WIDTH                      (1U)
#define MU_CSSR0_NMIC(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_NMIC_SHIFT)) & MU_CSSR0_NMIC_MASK)

#define MU_CSSR0_RUN_MASK                        (0x4U)
#define MU_CSSR0_RUN_SHIFT                       (2U)
#define MU_CSSR0_RUN_WIDTH                       (1U)
#define MU_CSSR0_RUN(x)                          (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_RUN_SHIFT)) & MU_CSSR0_RUN_MASK)

#define MU_CSSR0_RAIP_MASK                       (0x8U)
#define MU_CSSR0_RAIP_SHIFT                      (3U)
#define MU_CSSR0_RAIP_WIDTH                      (1U)
#define MU_CSSR0_RAIP(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_RAIP_SHIFT)) & MU_CSSR0_RAIP_MASK)

#define MU_CSSR0_HALT_MASK                       (0x10U)
#define MU_CSSR0_HALT_SHIFT                      (4U)
#define MU_CSSR0_HALT_WIDTH                      (1U)
#define MU_CSSR0_HALT(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_HALT_SHIFT)) & MU_CSSR0_HALT_MASK)

#define MU_CSSR0_WAIT_MASK                       (0x20U)
#define MU_CSSR0_WAIT_SHIFT                      (5U)
#define MU_CSSR0_WAIT_WIDTH                      (1U)
#define MU_CSSR0_WAIT(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_WAIT_SHIFT)) & MU_CSSR0_WAIT_MASK)

#define MU_CSSR0_STOP_MASK                       (0x40U)
#define MU_CSSR0_STOP_SHIFT                      (6U)
#define MU_CSSR0_STOP_WIDTH                      (1U)
#define MU_CSSR0_STOP(x)                         (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_STOP_SHIFT)) & MU_CSSR0_STOP_MASK)

#define MU_CSSR0_PD_MASK                         (0x80U)
#define MU_CSSR0_PD_SHIFT                        (7U)
#define MU_CSSR0_PD_WIDTH                        (1U)
#define MU_CSSR0_PD(x)                           (((uint32_t)(((uint32_t)(x)) << MU_CSSR0_PD_SHIFT)) & MU_CSSR0_PD_MASK)
/*! @} */

/*! @name CSR0 - Core Status 0 */
/*! @{ */

#define MU_CSR0_RUN_MASK                         (0x4U)
#define MU_CSR0_RUN_SHIFT                        (2U)
#define MU_CSR0_RUN_WIDTH                        (1U)
#define MU_CSR0_RUN(x)                           (((uint32_t)(((uint32_t)(x)) << MU_CSR0_RUN_SHIFT)) & MU_CSR0_RUN_MASK)

#define MU_CSR0_RAIP_MASK                        (0x8U)
#define MU_CSR0_RAIP_SHIFT                       (3U)
#define MU_CSR0_RAIP_WIDTH                       (1U)
#define MU_CSR0_RAIP(x)                          (((uint32_t)(((uint32_t)(x)) << MU_CSR0_RAIP_SHIFT)) & MU_CSR0_RAIP_MASK)

#define MU_CSR0_HALT_MASK                        (0x10U)
#define MU_CSR0_HALT_SHIFT                       (4U)
#define MU_CSR0_HALT_WIDTH                       (1U)
#define MU_CSR0_HALT(x)                          (((uint32_t)(((uint32_t)(x)) << MU_CSR0_HALT_SHIFT)) & MU_CSR0_HALT_MASK)

#define MU_CSR0_WAIT_MASK                        (0x20U)
#define MU_CSR0_WAIT_SHIFT                       (5U)
#define MU_CSR0_WAIT_WIDTH                       (1U)
#define MU_CSR0_WAIT(x)                          (((uint32_t)(((uint32_t)(x)) << MU_CSR0_WAIT_SHIFT)) & MU_CSR0_WAIT_MASK)

#define MU_CSR0_STOP_MASK                        (0x40U)
#define MU_CSR0_STOP_SHIFT                       (6U)
#define MU_CSR0_STOP_WIDTH                       (1U)
#define MU_CSR0_STOP(x)                          (((uint32_t)(((uint32_t)(x)) << MU_CSR0_STOP_SHIFT)) & MU_CSR0_STOP_MASK)

#define MU_CSR0_PD_MASK                          (0x80U)
#define MU_CSR0_PD_SHIFT                         (7U)
#define MU_CSR0_PD_WIDTH                         (1U)
#define MU_CSR0_PD(x)                            (((uint32_t)(((uint32_t)(x)) << MU_CSR0_PD_SHIFT)) & MU_CSR0_PD_MASK)
/*! @} */

/*! @name FCR - Flag Control */
/*! @{ */

#define MU_FCR_F0_MASK                           (0x1U)
#define MU_FCR_F0_SHIFT                          (0U)
#define MU_FCR_F0_WIDTH                          (1U)
#define MU_FCR_F0(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FCR_F0_SHIFT)) & MU_FCR_F0_MASK)

#define MU_FCR_F1_MASK                           (0x2U)
#define MU_FCR_F1_SHIFT                          (1U)
#define MU_FCR_F1_WIDTH                          (1U)
#define MU_FCR_F1(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FCR_F1_SHIFT)) & MU_FCR_F1_MASK)

#define MU_FCR_F2_MASK                           (0x4U)
#define MU_FCR_F2_SHIFT                          (2U)
#define MU_FCR_F2_WIDTH                          (1U)
#define MU_FCR_F2(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FCR_F2_SHIFT)) & MU_FCR_F2_MASK)
/*! @} */

/*! @name FSR - Flag Status */
/*! @{ */

#define MU_FSR_F0_MASK                           (0x1U)
#define MU_FSR_F0_SHIFT                          (0U)
#define MU_FSR_F0_WIDTH                          (1U)
#define MU_FSR_F0(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FSR_F0_SHIFT)) & MU_FSR_F0_MASK)

#define MU_FSR_F1_MASK                           (0x2U)
#define MU_FSR_F1_SHIFT                          (1U)
#define MU_FSR_F1_WIDTH                          (1U)
#define MU_FSR_F1(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FSR_F1_SHIFT)) & MU_FSR_F1_MASK)

#define MU_FSR_F2_MASK                           (0x4U)
#define MU_FSR_F2_SHIFT                          (2U)
#define MU_FSR_F2_WIDTH                          (1U)
#define MU_FSR_F2(x)                             (((uint32_t)(((uint32_t)(x)) << MU_FSR_F2_SHIFT)) & MU_FSR_F2_MASK)
/*! @} */

/*! @name GIER - General-Purpose Interrupt Enable */
/*! @{ */

#define MU_GIER_GIE0_MASK                        (0x1U)
#define MU_GIER_GIE0_SHIFT                       (0U)
#define MU_GIER_GIE0_WIDTH                       (1U)
#define MU_GIER_GIE0(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE0_SHIFT)) & MU_GIER_GIE0_MASK)

#define MU_GIER_GIE1_MASK                        (0x2U)
#define MU_GIER_GIE1_SHIFT                       (1U)
#define MU_GIER_GIE1_WIDTH                       (1U)
#define MU_GIER_GIE1(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE1_SHIFT)) & MU_GIER_GIE1_MASK)

#define MU_GIER_GIE2_MASK                        (0x4U)
#define MU_GIER_GIE2_SHIFT                       (2U)
#define MU_GIER_GIE2_WIDTH                       (1U)
#define MU_GIER_GIE2(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE2_SHIFT)) & MU_GIER_GIE2_MASK)

#define MU_GIER_GIE3_MASK                        (0x8U)
#define MU_GIER_GIE3_SHIFT                       (3U)
#define MU_GIER_GIE3_WIDTH                       (1U)
#define MU_GIER_GIE3(x)                          (((uint32_t)(((uint32_t)(x)) << MU_GIER_GIE3_SHIFT)) & MU_GIER_GIE3_MASK)
/*! @} */

/*! @name GCR - General-Purpose Control */
/*! @{ */

#define MU_GCR_GIR0_MASK                         (0x1U)
#define MU_GCR_GIR0_SHIFT                        (0U)
#define MU_GCR_GIR0_WIDTH                        (1U)
#define MU_GCR_GIR0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR0_SHIFT)) & MU_GCR_GIR0_MASK)

#define MU_GCR_GIR1_MASK                         (0x2U)
#define MU_GCR_GIR1_SHIFT                        (1U)
#define MU_GCR_GIR1_WIDTH                        (1U)
#define MU_GCR_GIR1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR1_SHIFT)) & MU_GCR_GIR1_MASK)

#define MU_GCR_GIR2_MASK                         (0x4U)
#define MU_GCR_GIR2_SHIFT                        (2U)
#define MU_GCR_GIR2_WIDTH                        (1U)
#define MU_GCR_GIR2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR2_SHIFT)) & MU_GCR_GIR2_MASK)

#define MU_GCR_GIR3_MASK                         (0x8U)
#define MU_GCR_GIR3_SHIFT                        (3U)
#define MU_GCR_GIR3_WIDTH                        (1U)
#define MU_GCR_GIR3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GCR_GIR3_SHIFT)) & MU_GCR_GIR3_MASK)
/*! @} */

/*! @name GSR - General-purpose Status */
/*! @{ */

#define MU_GSR_GIP0_MASK                         (0x1U)
#define MU_GSR_GIP0_SHIFT                        (0U)
#define MU_GSR_GIP0_WIDTH                        (1U)
#define MU_GSR_GIP0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP0_SHIFT)) & MU_GSR_GIP0_MASK)

#define MU_GSR_GIP1_MASK                         (0x2U)
#define MU_GSR_GIP1_SHIFT                        (1U)
#define MU_GSR_GIP1_WIDTH                        (1U)
#define MU_GSR_GIP1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP1_SHIFT)) & MU_GSR_GIP1_MASK)

#define MU_GSR_GIP2_MASK                         (0x4U)
#define MU_GSR_GIP2_SHIFT                        (2U)
#define MU_GSR_GIP2_WIDTH                        (1U)
#define MU_GSR_GIP2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP2_SHIFT)) & MU_GSR_GIP2_MASK)

#define MU_GSR_GIP3_MASK                         (0x8U)
#define MU_GSR_GIP3_SHIFT                        (3U)
#define MU_GSR_GIP3_WIDTH                        (1U)
#define MU_GSR_GIP3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_GSR_GIP3_SHIFT)) & MU_GSR_GIP3_MASK)
/*! @} */

/*! @name TCR - Transmit Control */
/*! @{ */

#define MU_TCR_TIE0_MASK                         (0x1U)
#define MU_TCR_TIE0_SHIFT                        (0U)
#define MU_TCR_TIE0_WIDTH                        (1U)
#define MU_TCR_TIE0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE0_SHIFT)) & MU_TCR_TIE0_MASK)

#define MU_TCR_TIE1_MASK                         (0x2U)
#define MU_TCR_TIE1_SHIFT                        (1U)
#define MU_TCR_TIE1_WIDTH                        (1U)
#define MU_TCR_TIE1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE1_SHIFT)) & MU_TCR_TIE1_MASK)

#define MU_TCR_TIE2_MASK                         (0x4U)
#define MU_TCR_TIE2_SHIFT                        (2U)
#define MU_TCR_TIE2_WIDTH                        (1U)
#define MU_TCR_TIE2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE2_SHIFT)) & MU_TCR_TIE2_MASK)

#define MU_TCR_TIE3_MASK                         (0x8U)
#define MU_TCR_TIE3_SHIFT                        (3U)
#define MU_TCR_TIE3_WIDTH                        (1U)
#define MU_TCR_TIE3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_TCR_TIE3_SHIFT)) & MU_TCR_TIE3_MASK)
/*! @} */

/*! @name TSR - Transmit Status */
/*! @{ */

#define MU_TSR_TE0_MASK                          (0x1U)
#define MU_TSR_TE0_SHIFT                         (0U)
#define MU_TSR_TE0_WIDTH                         (1U)
#define MU_TSR_TE0(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE0_SHIFT)) & MU_TSR_TE0_MASK)

#define MU_TSR_TE1_MASK                          (0x2U)
#define MU_TSR_TE1_SHIFT                         (1U)
#define MU_TSR_TE1_WIDTH                         (1U)
#define MU_TSR_TE1(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE1_SHIFT)) & MU_TSR_TE1_MASK)

#define MU_TSR_TE2_MASK                          (0x4U)
#define MU_TSR_TE2_SHIFT                         (2U)
#define MU_TSR_TE2_WIDTH                         (1U)
#define MU_TSR_TE2(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE2_SHIFT)) & MU_TSR_TE2_MASK)

#define MU_TSR_TE3_MASK                          (0x8U)
#define MU_TSR_TE3_SHIFT                         (3U)
#define MU_TSR_TE3_WIDTH                         (1U)
#define MU_TSR_TE3(x)                            (((uint32_t)(((uint32_t)(x)) << MU_TSR_TE3_SHIFT)) & MU_TSR_TE3_MASK)
/*! @} */

/*! @name RCR - Receive Control */
/*! @{ */

#define MU_RCR_RIE0_MASK                         (0x1U)
#define MU_RCR_RIE0_SHIFT                        (0U)
#define MU_RCR_RIE0_WIDTH                        (1U)
#define MU_RCR_RIE0(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE0_SHIFT)) & MU_RCR_RIE0_MASK)

#define MU_RCR_RIE1_MASK                         (0x2U)
#define MU_RCR_RIE1_SHIFT                        (1U)
#define MU_RCR_RIE1_WIDTH                        (1U)
#define MU_RCR_RIE1(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE1_SHIFT)) & MU_RCR_RIE1_MASK)

#define MU_RCR_RIE2_MASK                         (0x4U)
#define MU_RCR_RIE2_SHIFT                        (2U)
#define MU_RCR_RIE2_WIDTH                        (1U)
#define MU_RCR_RIE2(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE2_SHIFT)) & MU_RCR_RIE2_MASK)

#define MU_RCR_RIE3_MASK                         (0x8U)
#define MU_RCR_RIE3_SHIFT                        (3U)
#define MU_RCR_RIE3_WIDTH                        (1U)
#define MU_RCR_RIE3(x)                           (((uint32_t)(((uint32_t)(x)) << MU_RCR_RIE3_SHIFT)) & MU_RCR_RIE3_MASK)
/*! @} */

/*! @name RSR - Receive Status */
/*! @{ */

#define MU_RSR_RF0_MASK                          (0x1U)
#define MU_RSR_RF0_SHIFT                         (0U)
#define MU_RSR_RF0_WIDTH                         (1U)
#define MU_RSR_RF0(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF0_SHIFT)) & MU_RSR_RF0_MASK)

#define MU_RSR_RF1_MASK                          (0x2U)
#define MU_RSR_RF1_SHIFT                         (1U)
#define MU_RSR_RF1_WIDTH                         (1U)
#define MU_RSR_RF1(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF1_SHIFT)) & MU_RSR_RF1_MASK)

#define MU_RSR_RF2_MASK                          (0x4U)
#define MU_RSR_RF2_SHIFT                         (2U)
#define MU_RSR_RF2_WIDTH                         (1U)
#define MU_RSR_RF2(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF2_SHIFT)) & MU_RSR_RF2_MASK)

#define MU_RSR_RF3_MASK                          (0x8U)
#define MU_RSR_RF3_SHIFT                         (3U)
#define MU_RSR_RF3_WIDTH                         (1U)
#define MU_RSR_RF3(x)                            (((uint32_t)(((uint32_t)(x)) << MU_RSR_RF3_SHIFT)) & MU_RSR_RF3_MASK)
/*! @} */

/*! @name TR - Transmit */
/*! @{ */

#define MU_TR_TR_DATA_MASK                       (0xFFFFFFFFU)
#define MU_TR_TR_DATA_SHIFT                      (0U)
#define MU_TR_TR_DATA_WIDTH                      (32U)
#define MU_TR_TR_DATA(x)                         (((uint32_t)(((uint32_t)(x)) << MU_TR_TR_DATA_SHIFT)) & MU_TR_TR_DATA_MASK)
/*! @} */

/*! @name RR - Receive */
/*! @{ */

#define MU_RR_RR_DATA_MASK                       (0xFFFFFFFFU)
#define MU_RR_RR_DATA_SHIFT                      (0U)
#define MU_RR_RR_DATA_WIDTH                      (32U)
#define MU_RR_RR_DATA(x)                         (((uint32_t)(((uint32_t)(x)) << MU_RR_RR_DATA_SHIFT)) & MU_RR_RR_DATA_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MU_Register_Masks */

/*!
 * @}
 */ /* end of group MU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_MU_H_) */
