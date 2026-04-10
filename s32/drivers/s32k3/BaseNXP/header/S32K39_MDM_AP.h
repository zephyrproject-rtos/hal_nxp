/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_MDM_AP.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_MDM_AP
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
#if !defined(S32K39_MDM_AP_H_)  /* Check if memory map has not been already included */
#define S32K39_MDM_AP_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MDM_AP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MDM_AP_Peripheral_Access_Layer MDM_AP Peripheral Access Layer
 * @{
 */

/** MDM_AP - Register Layout Typedef */
typedef struct {
  __I  uint32_t MDMAPSTTS;                         /**< Status, offset: 0x0 */
  __IO uint32_t MDMAPCTL;                          /**< Control, offset: 0x4 */
  __IO uint32_t MDMAPDTSEN;                        /**< DTS Enable, offset: 0x8 */
  __IO uint32_t MDMAPDTSSTARTUP;                   /**< DTS Startup, offset: 0xC */
  __IO uint32_t MDMAPDTSSTARTUPB;                  /**< DTS Startup B, offset: 0x10 */
  __IO uint32_t MDMAPDTSSTARTUPC;                  /**< DTS Startup C, offset: 0x14 */
  __IO uint32_t MDMAPDTSSTARTUPD;                  /**< DTS Startup D, offset: 0x18 */
  __IO uint32_t MDMAPDTSSEMAPHORE;                 /**< DTS Semaphore, offset: 0x1C */
  __IO uint32_t MDMAPDTSSEMAPHOREB;                /**< DTS Semaphore B, offset: 0x20 */
  __IO uint32_t MDMAPDTSSEMAPHOREC;                /**< DTS Semaphore C, offset: 0x24 */
  __IO uint32_t MDMAPDTSSEMAPHORED;                /**< DTS Semaphore D, offset: 0x28 */
  uint8_t RESERVED_0[4];
  __IO uint32_t MDMAPWIREN;                        /**< WIR Enable, offset: 0x30 */
  __I  uint32_t MDMAPWIRSTTS;                      /**< WIR Status, offset: 0x34 */
  __IO uint32_t MDMAPWIRREL;                       /**< WIR Release, offset: 0x38 */
  uint8_t RESERVED_1[8];
  __IO uint32_t MDMAPETPUCTRLEN;                   /**< ETPU_CONTROL_ENABLE, offset: 0x44 */
  __I  uint32_t MDMAPETPUSTTSEN;                   /**< ETPU_STATUS_ENABLE, offset: 0x48 */
  uint8_t RESERVED_2[176];
  __I  uint32_t ID;                                /**< Identity, offset: 0xFC */
} MDM_AP_Type, *MDM_AP_MemMapPtr;

/** Number of instances of the MDM_AP module. */
#define MDM_AP_INSTANCE_COUNT                    (1u)

/* MDM_AP - Peripheral instance base addresses */
/** Peripheral MDM_AP base address */
#define IP_MDM_AP_BASE                           (0x40250600u)
/** Peripheral MDM_AP base pointer */
#define IP_MDM_AP                                ((MDM_AP_Type *)IP_MDM_AP_BASE)
/** Array initializer of MDM_AP peripheral base addresses */
#define IP_MDM_AP_BASE_ADDRS                     { IP_MDM_AP_BASE }
/** Array initializer of MDM_AP peripheral base pointers */
#define IP_MDM_AP_BASE_PTRS                      { IP_MDM_AP }

/* ----------------------------------------------------------------------------
   -- MDM_AP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MDM_AP_Register_Masks MDM_AP Register Masks
 * @{
 */

/*! @name MDMAPSTTS - Status */
/*! @{ */

#define MDM_AP_MDMAPSTTS_DESTRST_MASK            (0x2U)
#define MDM_AP_MDMAPSTTS_DESTRST_SHIFT           (1U)
#define MDM_AP_MDMAPSTTS_DESTRST_WIDTH           (1U)
#define MDM_AP_MDMAPSTTS_DESTRST(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_DESTRST_SHIFT)) & MDM_AP_MDMAPSTTS_DESTRST_MASK)

#define MDM_AP_MDMAPSTTS_FUNCRST_MASK            (0x4U)
#define MDM_AP_MDMAPSTTS_FUNCRST_SHIFT           (2U)
#define MDM_AP_MDMAPSTTS_FUNCRST_WIDTH           (1U)
#define MDM_AP_MDMAPSTTS_FUNCRST(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_FUNCRST_SHIFT)) & MDM_AP_MDMAPSTTS_FUNCRST_MASK)

#define MDM_AP_MDMAPSTTS_CM70HLT_MASK            (0x1000U)
#define MDM_AP_MDMAPSTTS_CM70HLT_SHIFT           (12U)
#define MDM_AP_MDMAPSTTS_CM70HLT_WIDTH           (1U)
#define MDM_AP_MDMAPSTTS_CM70HLT(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM70HLT_SHIFT)) & MDM_AP_MDMAPSTTS_CM70HLT_MASK)

#define MDM_AP_MDMAPSTTS_CM71HLT_MASK            (0x2000U)
#define MDM_AP_MDMAPSTTS_CM71HLT_SHIFT           (13U)
#define MDM_AP_MDMAPSTTS_CM71HLT_WIDTH           (1U)
#define MDM_AP_MDMAPSTTS_CM71HLT(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM71HLT_SHIFT)) & MDM_AP_MDMAPSTTS_CM71HLT_MASK)

#define MDM_AP_MDMAPSTTS_CM72HLT_MASK            (0x4000U)
#define MDM_AP_MDMAPSTTS_CM72HLT_SHIFT           (14U)
#define MDM_AP_MDMAPSTTS_CM72HLT_WIDTH           (1U)
#define MDM_AP_MDMAPSTTS_CM72HLT(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM72HLT_SHIFT)) & MDM_AP_MDMAPSTTS_CM72HLT_MASK)

#define MDM_AP_MDMAPSTTS_CM70DPSLP_MASK          (0x10000U)
#define MDM_AP_MDMAPSTTS_CM70DPSLP_SHIFT         (16U)
#define MDM_AP_MDMAPSTTS_CM70DPSLP_WIDTH         (1U)
#define MDM_AP_MDMAPSTTS_CM70DPSLP(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM70DPSLP_SHIFT)) & MDM_AP_MDMAPSTTS_CM70DPSLP_MASK)

#define MDM_AP_MDMAPSTTS_CM71DPSLP_MASK          (0x20000U)
#define MDM_AP_MDMAPSTTS_CM71DPSLP_SHIFT         (17U)
#define MDM_AP_MDMAPSTTS_CM71DPSLP_WIDTH         (1U)
#define MDM_AP_MDMAPSTTS_CM71DPSLP(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM71DPSLP_SHIFT)) & MDM_AP_MDMAPSTTS_CM71DPSLP_MASK)

#define MDM_AP_MDMAPSTTS_CM72DPSLP_MASK          (0x40000U)
#define MDM_AP_MDMAPSTTS_CM72DPSLP_SHIFT         (18U)
#define MDM_AP_MDMAPSTTS_CM72DPSLP_WIDTH         (1U)
#define MDM_AP_MDMAPSTTS_CM72DPSLP(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM72DPSLP_SHIFT)) & MDM_AP_MDMAPSTTS_CM72DPSLP_MASK)

#define MDM_AP_MDMAPSTTS_CM70SLPNG_MASK          (0x100000U)
#define MDM_AP_MDMAPSTTS_CM70SLPNG_SHIFT         (20U)
#define MDM_AP_MDMAPSTTS_CM70SLPNG_WIDTH         (1U)
#define MDM_AP_MDMAPSTTS_CM70SLPNG(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM70SLPNG_SHIFT)) & MDM_AP_MDMAPSTTS_CM70SLPNG_MASK)

#define MDM_AP_MDMAPSTTS_CM71SLPNG_MASK          (0x200000U)
#define MDM_AP_MDMAPSTTS_CM71SLPNG_SHIFT         (21U)
#define MDM_AP_MDMAPSTTS_CM71SLPNG_WIDTH         (1U)
#define MDM_AP_MDMAPSTTS_CM71SLPNG(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM71SLPNG_SHIFT)) & MDM_AP_MDMAPSTTS_CM71SLPNG_MASK)

#define MDM_AP_MDMAPSTTS_CM72SLPNG_MASK          (0x400000U)
#define MDM_AP_MDMAPSTTS_CM72SLPNG_SHIFT         (22U)
#define MDM_AP_MDMAPSTTS_CM72SLPNG_WIDTH         (1U)
#define MDM_AP_MDMAPSTTS_CM72SLPNG(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM72SLPNG_SHIFT)) & MDM_AP_MDMAPSTTS_CM72SLPNG_MASK)

#define MDM_AP_MDMAPSTTS_CM70DBGRSTRD_MASK       (0x10000000U)
#define MDM_AP_MDMAPSTTS_CM70DBGRSTRD_SHIFT      (28U)
#define MDM_AP_MDMAPSTTS_CM70DBGRSTRD_WIDTH      (1U)
#define MDM_AP_MDMAPSTTS_CM70DBGRSTRD(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM70DBGRSTRD_SHIFT)) & MDM_AP_MDMAPSTTS_CM70DBGRSTRD_MASK)

#define MDM_AP_MDMAPSTTS_CM71DBGRSTRD_MASK       (0x20000000U)
#define MDM_AP_MDMAPSTTS_CM71DBGRSTRD_SHIFT      (29U)
#define MDM_AP_MDMAPSTTS_CM71DBGRSTRD_WIDTH      (1U)
#define MDM_AP_MDMAPSTTS_CM71DBGRSTRD(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM71DBGRSTRD_SHIFT)) & MDM_AP_MDMAPSTTS_CM71DBGRSTRD_MASK)

#define MDM_AP_MDMAPSTTS_CM72DBGRSTRD_MASK       (0x80000000U)
#define MDM_AP_MDMAPSTTS_CM72DBGRSTRD_SHIFT      (31U)
#define MDM_AP_MDMAPSTTS_CM72DBGRSTRD_WIDTH      (1U)
#define MDM_AP_MDMAPSTTS_CM72DBGRSTRD(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM72DBGRSTRD_SHIFT)) & MDM_AP_MDMAPSTTS_CM72DBGRSTRD_MASK)
/*! @} */

/*! @name MDMAPCTL - Control */
/*! @{ */

#define MDM_AP_MDMAPCTL_SYSRESETREQ_MASK         (0x10U)
#define MDM_AP_MDMAPCTL_SYSRESETREQ_SHIFT        (4U)
#define MDM_AP_MDMAPCTL_SYSRESETREQ_WIDTH        (1U)
#define MDM_AP_MDMAPCTL_SYSRESETREQ(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_SYSRESETREQ_SHIFT)) & MDM_AP_MDMAPCTL_SYSRESETREQ_MASK)

#define MDM_AP_MDMAPCTL_SYSFUNCRST_MASK          (0x20U)
#define MDM_AP_MDMAPCTL_SYSFUNCRST_SHIFT         (5U)
#define MDM_AP_MDMAPCTL_SYSFUNCRST_WIDTH         (1U)
#define MDM_AP_MDMAPCTL_SYSFUNCRST(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_SYSFUNCRST_SHIFT)) & MDM_AP_MDMAPCTL_SYSFUNCRST_MASK)

#define MDM_AP_MDMAPCTL_CM70DBGREQ_MASK          (0x100U)
#define MDM_AP_MDMAPCTL_CM70DBGREQ_SHIFT         (8U)
#define MDM_AP_MDMAPCTL_CM70DBGREQ_WIDTH         (1U)
#define MDM_AP_MDMAPCTL_CM70DBGREQ(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_CM70DBGREQ_SHIFT)) & MDM_AP_MDMAPCTL_CM70DBGREQ_MASK)

#define MDM_AP_MDMAPCTL_CM71DBGREQ_MASK          (0x200U)
#define MDM_AP_MDMAPCTL_CM71DBGREQ_SHIFT         (9U)
#define MDM_AP_MDMAPCTL_CM71DBGREQ_WIDTH         (1U)
#define MDM_AP_MDMAPCTL_CM71DBGREQ(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_CM71DBGREQ_SHIFT)) & MDM_AP_MDMAPCTL_CM71DBGREQ_MASK)

#define MDM_AP_MDMAPCTL_CM72DBGREQ_MASK          (0x400U)
#define MDM_AP_MDMAPCTL_CM72DBGREQ_SHIFT         (10U)
#define MDM_AP_MDMAPCTL_CM72DBGREQ_WIDTH         (1U)
#define MDM_AP_MDMAPCTL_CM72DBGREQ(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_CM72DBGREQ_SHIFT)) & MDM_AP_MDMAPCTL_CM72DBGREQ_MASK)

#define MDM_AP_MDMAPCTL_DBGRSTSLOWPAD_MASK       (0x1000U)
#define MDM_AP_MDMAPCTL_DBGRSTSLOWPAD_SHIFT      (12U)
#define MDM_AP_MDMAPCTL_DBGRSTSLOWPAD_WIDTH      (1U)
#define MDM_AP_MDMAPCTL_DBGRSTSLOWPAD(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_DBGRSTSLOWPAD_SHIFT)) & MDM_AP_MDMAPCTL_DBGRSTSLOWPAD_MASK)

#define MDM_AP_MDMAPCTL_DBGRSTFASTPAD_MASK       (0x2000U)
#define MDM_AP_MDMAPCTL_DBGRSTFASTPAD_SHIFT      (13U)
#define MDM_AP_MDMAPCTL_DBGRSTFASTPAD_WIDTH      (1U)
#define MDM_AP_MDMAPCTL_DBGRSTFASTPAD(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_DBGRSTFASTPAD_SHIFT)) & MDM_AP_MDMAPCTL_DBGRSTFASTPAD_MASK)

#define MDM_AP_MDMAPCTL_POR_WDG_DIS_MASK         (0x8000U)
#define MDM_AP_MDMAPCTL_POR_WDG_DIS_SHIFT        (15U)
#define MDM_AP_MDMAPCTL_POR_WDG_DIS_WIDTH        (1U)
#define MDM_AP_MDMAPCTL_POR_WDG_DIS(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_POR_WDG_DIS_SHIFT)) & MDM_AP_MDMAPCTL_POR_WDG_DIS_MASK)

#define MDM_AP_MDMAPCTL_TRIUOVRD_MASK            (0x100000U)
#define MDM_AP_MDMAPCTL_TRIUOVRD_SHIFT           (20U)
#define MDM_AP_MDMAPCTL_TRIUOVRD_WIDTH           (1U)
#define MDM_AP_MDMAPCTL_TRIUOVRD(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_TRIUOVRD_SHIFT)) & MDM_AP_MDMAPCTL_TRIUOVRD_MASK)

#define MDM_AP_MDMAPCTL_SWOOVRD_MASK             (0x400000U)
#define MDM_AP_MDMAPCTL_SWOOVRD_SHIFT            (22U)
#define MDM_AP_MDMAPCTL_SWOOVRD_WIDTH            (1U)
#define MDM_AP_MDMAPCTL_SWOOVRD(x)               (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_SWOOVRD_SHIFT)) & MDM_AP_MDMAPCTL_SWOOVRD_MASK)

#define MDM_AP_MDMAPCTL_CM70DBGRSRT_MASK         (0x10000000U)
#define MDM_AP_MDMAPCTL_CM70DBGRSRT_SHIFT        (28U)
#define MDM_AP_MDMAPCTL_CM70DBGRSRT_WIDTH        (1U)
#define MDM_AP_MDMAPCTL_CM70DBGRSRT(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_CM70DBGRSRT_SHIFT)) & MDM_AP_MDMAPCTL_CM70DBGRSRT_MASK)

#define MDM_AP_MDMAPCTL_CM71DBGRSRT_MASK         (0x20000000U)
#define MDM_AP_MDMAPCTL_CM71DBGRSRT_SHIFT        (29U)
#define MDM_AP_MDMAPCTL_CM71DBGRSRT_WIDTH        (1U)
#define MDM_AP_MDMAPCTL_CM71DBGRSRT(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_CM71DBGRSRT_SHIFT)) & MDM_AP_MDMAPCTL_CM71DBGRSRT_MASK)

#define MDM_AP_MDMAPCTL_CM72DBGRSRT_MASK         (0x80000000U)
#define MDM_AP_MDMAPCTL_CM72DBGRSRT_SHIFT        (31U)
#define MDM_AP_MDMAPCTL_CM72DBGRSRT_WIDTH        (1U)
#define MDM_AP_MDMAPCTL_CM72DBGRSRT(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_CM72DBGRSRT_SHIFT)) & MDM_AP_MDMAPCTL_CM72DBGRSRT_MASK)
/*! @} */

/*! @name MDMAPDTSEN - DTS Enable */
/*! @{ */

#define MDM_AP_MDMAPDTSEN_DTSEN_MASK             (0x1U)
#define MDM_AP_MDMAPDTSEN_DTSEN_SHIFT            (0U)
#define MDM_AP_MDMAPDTSEN_DTSEN_WIDTH            (1U)
#define MDM_AP_MDMAPDTSEN_DTSEN(x)               (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPDTSEN_DTSEN_SHIFT)) & MDM_AP_MDMAPDTSEN_DTSEN_MASK)

#define MDM_AP_MDMAPDTSEN_DTSENB_MASK            (0x2U)
#define MDM_AP_MDMAPDTSEN_DTSENB_SHIFT           (1U)
#define MDM_AP_MDMAPDTSEN_DTSENB_WIDTH           (1U)
#define MDM_AP_MDMAPDTSEN_DTSENB(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPDTSEN_DTSENB_SHIFT)) & MDM_AP_MDMAPDTSEN_DTSENB_MASK)

#define MDM_AP_MDMAPDTSEN_DTSENC_MASK            (0x4U)
#define MDM_AP_MDMAPDTSEN_DTSENC_SHIFT           (2U)
#define MDM_AP_MDMAPDTSEN_DTSENC_WIDTH           (1U)
#define MDM_AP_MDMAPDTSEN_DTSENC(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPDTSEN_DTSENC_SHIFT)) & MDM_AP_MDMAPDTSEN_DTSENC_MASK)

#define MDM_AP_MDMAPDTSEN_DTSEND_MASK            (0x8U)
#define MDM_AP_MDMAPDTSEN_DTSEND_SHIFT           (3U)
#define MDM_AP_MDMAPDTSEN_DTSEND_WIDTH           (1U)
#define MDM_AP_MDMAPDTSEN_DTSEND(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPDTSEN_DTSEND_SHIFT)) & MDM_AP_MDMAPDTSEN_DTSEND_MASK)
/*! @} */

/*! @name MDMAPDTSSTARTUP - DTS Startup */
/*! @{ */

#define MDM_AP_MDMAPDTSSTARTUP_AD_MASK           (0xFFFFFFFFU)
#define MDM_AP_MDMAPDTSSTARTUP_AD_SHIFT          (0U)
#define MDM_AP_MDMAPDTSSTARTUP_AD_WIDTH          (32U)
#define MDM_AP_MDMAPDTSSTARTUP_AD(x)             (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPDTSSTARTUP_AD_SHIFT)) & MDM_AP_MDMAPDTSSTARTUP_AD_MASK)
/*! @} */

/*! @name MDMAPDTSSTARTUPB - DTS Startup B */
/*! @{ */

#define MDM_AP_MDMAPDTSSTARTUPB_AD_MASK          (0xFFFFFFFFU)
#define MDM_AP_MDMAPDTSSTARTUPB_AD_SHIFT         (0U)
#define MDM_AP_MDMAPDTSSTARTUPB_AD_WIDTH         (32U)
#define MDM_AP_MDMAPDTSSTARTUPB_AD(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPDTSSTARTUPB_AD_SHIFT)) & MDM_AP_MDMAPDTSSTARTUPB_AD_MASK)
/*! @} */

/*! @name MDMAPDTSSTARTUPC - DTS Startup C */
/*! @{ */

#define MDM_AP_MDMAPDTSSTARTUPC_AD_MASK          (0xFFFFFFFFU)
#define MDM_AP_MDMAPDTSSTARTUPC_AD_SHIFT         (0U)
#define MDM_AP_MDMAPDTSSTARTUPC_AD_WIDTH         (32U)
#define MDM_AP_MDMAPDTSSTARTUPC_AD(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPDTSSTARTUPC_AD_SHIFT)) & MDM_AP_MDMAPDTSSTARTUPC_AD_MASK)
/*! @} */

/*! @name MDMAPDTSSTARTUPD - DTS Startup D */
/*! @{ */

#define MDM_AP_MDMAPDTSSTARTUPD_AD_MASK          (0xFFFFFFFFU)
#define MDM_AP_MDMAPDTSSTARTUPD_AD_SHIFT         (0U)
#define MDM_AP_MDMAPDTSSTARTUPD_AD_WIDTH         (32U)
#define MDM_AP_MDMAPDTSSTARTUPD_AD(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPDTSSTARTUPD_AD_SHIFT)) & MDM_AP_MDMAPDTSSTARTUPD_AD_MASK)
/*! @} */

/*! @name MDMAPDTSSEMAPHORE - DTS Semaphore */
/*! @{ */

#define MDM_AP_MDMAPDTSSEMAPHORE_ST_MASK         (0xFFFFFFFFU)
#define MDM_AP_MDMAPDTSSEMAPHORE_ST_SHIFT        (0U)
#define MDM_AP_MDMAPDTSSEMAPHORE_ST_WIDTH        (32U)
#define MDM_AP_MDMAPDTSSEMAPHORE_ST(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPDTSSEMAPHORE_ST_SHIFT)) & MDM_AP_MDMAPDTSSEMAPHORE_ST_MASK)
/*! @} */

/*! @name MDMAPDTSSEMAPHOREB - DTS Semaphore B */
/*! @{ */

#define MDM_AP_MDMAPDTSSEMAPHOREB_ST_MASK        (0xFFFFFFFFU)
#define MDM_AP_MDMAPDTSSEMAPHOREB_ST_SHIFT       (0U)
#define MDM_AP_MDMAPDTSSEMAPHOREB_ST_WIDTH       (32U)
#define MDM_AP_MDMAPDTSSEMAPHOREB_ST(x)          (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPDTSSEMAPHOREB_ST_SHIFT)) & MDM_AP_MDMAPDTSSEMAPHOREB_ST_MASK)
/*! @} */

/*! @name MDMAPDTSSEMAPHOREC - DTS Semaphore C */
/*! @{ */

#define MDM_AP_MDMAPDTSSEMAPHOREC_ST_MASK        (0xFFFFFFFFU)
#define MDM_AP_MDMAPDTSSEMAPHOREC_ST_SHIFT       (0U)
#define MDM_AP_MDMAPDTSSEMAPHOREC_ST_WIDTH       (32U)
#define MDM_AP_MDMAPDTSSEMAPHOREC_ST(x)          (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPDTSSEMAPHOREC_ST_SHIFT)) & MDM_AP_MDMAPDTSSEMAPHOREC_ST_MASK)
/*! @} */

/*! @name MDMAPDTSSEMAPHORED - DTS Semaphore D */
/*! @{ */

#define MDM_AP_MDMAPDTSSEMAPHORED_ST_MASK        (0xFFFFFFFFU)
#define MDM_AP_MDMAPDTSSEMAPHORED_ST_SHIFT       (0U)
#define MDM_AP_MDMAPDTSSEMAPHORED_ST_WIDTH       (32U)
#define MDM_AP_MDMAPDTSSEMAPHORED_ST(x)          (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPDTSSEMAPHORED_ST_SHIFT)) & MDM_AP_MDMAPDTSSEMAPHORED_ST_MASK)
/*! @} */

/*! @name MDMAPWIREN - WIR Enable */
/*! @{ */

#define MDM_AP_MDMAPWIREN_LWPWREN_MASK           (0x1U)
#define MDM_AP_MDMAPWIREN_LWPWREN_SHIFT          (0U)
#define MDM_AP_MDMAPWIREN_LWPWREN_WIDTH          (1U)
#define MDM_AP_MDMAPWIREN_LWPWREN(x)             (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPWIREN_LWPWREN_SHIFT)) & MDM_AP_MDMAPWIREN_LWPWREN_MASK)

#define MDM_AP_MDMAPWIREN_LWPRSTPRVT_MASK        (0x2U)
#define MDM_AP_MDMAPWIREN_LWPRSTPRVT_SHIFT       (1U)
#define MDM_AP_MDMAPWIREN_LWPRSTPRVT_WIDTH       (1U)
#define MDM_AP_MDMAPWIREN_LWPRSTPRVT(x)          (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPWIREN_LWPRSTPRVT_SHIFT)) & MDM_AP_MDMAPWIREN_LWPRSTPRVT_MASK)
/*! @} */

/*! @name MDMAPWIRSTTS - WIR Status */
/*! @{ */

#define MDM_AP_MDMAPWIRSTTS_MDM_DAP_WIR_STATUS_MASK (0xFFFFFFFFU)
#define MDM_AP_MDMAPWIRSTTS_MDM_DAP_WIR_STATUS_SHIFT (0U)
#define MDM_AP_MDMAPWIRSTTS_MDM_DAP_WIR_STATUS_WIDTH (32U)
#define MDM_AP_MDMAPWIRSTTS_MDM_DAP_WIR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPWIRSTTS_MDM_DAP_WIR_STATUS_SHIFT)) & MDM_AP_MDMAPWIRSTTS_MDM_DAP_WIR_STATUS_MASK)
/*! @} */

/*! @name MDMAPWIRREL - WIR Release */
/*! @{ */

#define MDM_AP_MDMAPWIRREL_WTRSTRGM_MASK         (0x1U)
#define MDM_AP_MDMAPWIRREL_WTRSTRGM_SHIFT        (0U)
#define MDM_AP_MDMAPWIRREL_WTRSTRGM_WIDTH        (1U)
#define MDM_AP_MDMAPWIRREL_WTRSTRGM(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPWIRREL_WTRSTRGM_SHIFT)) & MDM_AP_MDMAPWIRREL_WTRSTRGM_MASK)

#define MDM_AP_MDMAPWIRREL_PRVNTRSTRGM_MASK      (0x2U)
#define MDM_AP_MDMAPWIRREL_PRVNTRSTRGM_SHIFT     (1U)
#define MDM_AP_MDMAPWIRREL_PRVNTRSTRGM_WIDTH     (1U)
#define MDM_AP_MDMAPWIRREL_PRVNTRSTRGM(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPWIRREL_PRVNTRSTRGM_SHIFT)) & MDM_AP_MDMAPWIRREL_PRVNTRSTRGM_MASK)
/*! @} */

/*! @name MDMAPETPUCTRLEN - ETPU_CONTROL_ENABLE */
/*! @{ */

#define MDM_AP_MDMAPETPUCTRLEN_ETPU_ATID_MASK    (0x7FU)
#define MDM_AP_MDMAPETPUCTRLEN_ETPU_ATID_SHIFT   (0U)
#define MDM_AP_MDMAPETPUCTRLEN_ETPU_ATID_WIDTH   (7U)
#define MDM_AP_MDMAPETPUCTRLEN_ETPU_ATID(x)      (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPETPUCTRLEN_ETPU_ATID_SHIFT)) & MDM_AP_MDMAPETPUCTRLEN_ETPU_ATID_MASK)

#define MDM_AP_MDMAPETPUCTRLEN_ETPU_SPACE_THRES_MASK (0x780U)
#define MDM_AP_MDMAPETPUCTRLEN_ETPU_SPACE_THRES_SHIFT (7U)
#define MDM_AP_MDMAPETPUCTRLEN_ETPU_SPACE_THRES_WIDTH (4U)
#define MDM_AP_MDMAPETPUCTRLEN_ETPU_SPACE_THRES(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPETPUCTRLEN_ETPU_SPACE_THRES_SHIFT)) & MDM_AP_MDMAPETPUCTRLEN_ETPU_SPACE_THRES_MASK)

#define MDM_AP_MDMAPETPUCTRLEN_APB_SLOT_SEL_MASK (0x800U)
#define MDM_AP_MDMAPETPUCTRLEN_APB_SLOT_SEL_SHIFT (11U)
#define MDM_AP_MDMAPETPUCTRLEN_APB_SLOT_SEL_WIDTH (1U)
#define MDM_AP_MDMAPETPUCTRLEN_APB_SLOT_SEL(x)   (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPETPUCTRLEN_APB_SLOT_SEL_SHIFT)) & MDM_AP_MDMAPETPUCTRLEN_APB_SLOT_SEL_MASK)
/*! @} */

/*! @name MDMAPETPUSTTSEN - ETPU_STATUS_ENABLE */
/*! @{ */

#define MDM_AP_MDMAPETPUSTTSEN_OVERFLOW_MASK     (0x1U)
#define MDM_AP_MDMAPETPUSTTSEN_OVERFLOW_SHIFT    (0U)
#define MDM_AP_MDMAPETPUSTTSEN_OVERFLOW_WIDTH    (1U)
#define MDM_AP_MDMAPETPUSTTSEN_OVERFLOW(x)       (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPETPUSTTSEN_OVERFLOW_SHIFT)) & MDM_AP_MDMAPETPUSTTSEN_OVERFLOW_MASK)

#define MDM_AP_MDMAPETPUSTTSEN_UNDERRUN_MASK     (0x2U)
#define MDM_AP_MDMAPETPUSTTSEN_UNDERRUN_SHIFT    (1U)
#define MDM_AP_MDMAPETPUSTTSEN_UNDERRUN_WIDTH    (1U)
#define MDM_AP_MDMAPETPUSTTSEN_UNDERRUN(x)       (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPETPUSTTSEN_UNDERRUN_SHIFT)) & MDM_AP_MDMAPETPUSTTSEN_UNDERRUN_MASK)

#define MDM_AP_MDMAPETPUSTTSEN_ETPU_EVTI_0_MASK  (0x4U)
#define MDM_AP_MDMAPETPUSTTSEN_ETPU_EVTI_0_SHIFT (2U)
#define MDM_AP_MDMAPETPUSTTSEN_ETPU_EVTI_0_WIDTH (1U)
#define MDM_AP_MDMAPETPUSTTSEN_ETPU_EVTI_0(x)    (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPETPUSTTSEN_ETPU_EVTI_0_SHIFT)) & MDM_AP_MDMAPETPUSTTSEN_ETPU_EVTI_0_MASK)

#define MDM_AP_MDMAPETPUSTTSEN_ETPU_EVTI_1_MASK  (0x8U)
#define MDM_AP_MDMAPETPUSTTSEN_ETPU_EVTI_1_SHIFT (3U)
#define MDM_AP_MDMAPETPUSTTSEN_ETPU_EVTI_1_WIDTH (1U)
#define MDM_AP_MDMAPETPUSTTSEN_ETPU_EVTI_1(x)    (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPETPUSTTSEN_ETPU_EVTI_1_SHIFT)) & MDM_AP_MDMAPETPUSTTSEN_ETPU_EVTI_1_MASK)
/*! @} */

/*! @name ID - Identity */
/*! @{ */

#define MDM_AP_ID_ID_MASK                        (0xFFFFFFFFU)
#define MDM_AP_ID_ID_SHIFT                       (0U)
#define MDM_AP_ID_ID_WIDTH                       (32U)
#define MDM_AP_ID_ID(x)                          (((uint32_t)(((uint32_t)(x)) << MDM_AP_ID_ID_SHIFT)) & MDM_AP_ID_ID_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MDM_AP_Register_Masks */

/*!
 * @}
 */ /* end of group MDM_AP_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_MDM_AP_H_) */
