/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_NETC_F2_GLOBAL.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_NETC_F2_GLOBAL
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
#if !defined(S32Z2_NETC_F2_GLOBAL_H_)  /* Check if memory map has not been already included */
#define S32Z2_NETC_F2_GLOBAL_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- NETC_F2_GLOBAL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_F2_GLOBAL_Peripheral_Access_Layer NETC_F2_GLOBAL Peripheral Access Layer
 * @{
 */

/** NETC_F2_GLOBAL - Size of Registers Arrays */
#define NETC_F2_GLOBAL_PCE_SL_COUNT               1u
#define NETC_F2_GLOBAL_HTA_LOOP_COUNT             1u
#define NETC_F2_GLOBAL_ARRAY_NUM_RC_COUNT         1u
#define NETC_F2_GLOBAL_G_BOOT_COUNT               2u

/** NETC_F2_GLOBAL - Register Layout Typedef */
typedef struct {
  __I  uint32_t SMCAPR;                            /**< Shared memory capability register, offset: 0x0 */
  __I  uint32_t SMDTR;                             /**< Shared memory depletion threshold register, offset: 0x4 */
  __I  uint32_t SMACR;                             /**< Shared memory available count register, offset: 0x8 */
  uint8_t RESERVED_0[4];
  __I  uint32_t SMCLWMR;                           /**< Shared memory count low watermark register, offset: 0x10 */
  __I  uint32_t SMBUCR;                            /**< Shared memory buffer unassigned count register, offset: 0x14 */
  __I  uint32_t SMBUCHWMR;                         /**< Shared memory buffer unassigned count high watermark register, offset: 0x18 */
  __I  uint32_t SMLCR;                             /**< Shared memory loss count register, offset: 0x1C */
  __I  uint32_t HBTCAPR;                           /**< Hash bucket table capability register, offset: 0x20 */
  __I  uint32_t HBTOR0;                            /**< Hash bucket table operational register 0, offset: 0x24 */
  uint8_t RESERVED_1[4];
  __I  uint32_t HBTOR2;                            /**< Hash bucket table operational register 2, offset: 0x2C */
  uint8_t RESERVED_2[16];
  __I  uint32_t SMERBCAPR;                         /**< Shared memory ENETC receive buffer capability register, offset: 0x40 */
  __I  uint32_t SMERBOR0;                          /**< Shared memory ENETC receive buffer operational register 0, offset: 0x44 */
  __I  uint32_t SMERBOR1;                          /**< Shared memory ENETC receive buffer operational 1, offset: 0x48 */
  uint8_t RESERVED_3[180];
  struct NETC_F2_GLOBAL_PCE_SL {                   /* offset: 0x100, array step: 0x8 */
    __I  uint32_t PCEOR;                             /**< PCE 0 operational register, array offset: 0x100, array step: 0x8 */
    __I  uint32_t RFEOR;                             /**< Replication Forwarding Engine 0 operational register, array offset: 0x104, array step: 0x8 */
  } PCE_SL[NETC_F2_GLOBAL_PCE_SL_COUNT];
  uint8_t RESERVED_4[92];
  __I  uint32_t NETCCLKR;                          /**< NETC clock register, offset: 0x164 */
  uint8_t RESERVED_5[152];
  struct NETC_F2_GLOBAL_HTA_LOOP {                 /* offset: 0x200, array step: 0x28 */
    __I  uint32_t HTACAPR;                           /**< HTA 0 capability register, array offset: 0x200, array step: 0x28 */
    __I  uint32_t HTARFCOR;                          /**< HTA 0 receive frame count operational register, array offset: 0x204, array step: 0x28 */
    __I  uint32_t HTAHPBCOR;                         /**< HTA 0 high priority byte count operational register, array offset: 0x208, array step: 0x28 */
    __I  uint32_t HTALPBCOR;                         /**< HTA 0 low priority byte count operational register, array offset: 0x20C, array step: 0x28 */
    uint8_t RESERVED_0[20];
    __I  uint32_t HTATFCOR;                          /**< HTA 0 transmit frame count operational register, array offset: 0x224, array step: 0x28 */
  } HTA_LOOP[NETC_F2_GLOBAL_HTA_LOOP_COUNT];
  uint8_t RESERVED_6[216];
  struct NETC_F2_GLOBAL_ARRAY_NUM_RC {             /* offset: 0x300, array step: 0x10 */
    __IO uint32_t RCSBRLAR;                          /**< Root complex 0 system bus read latency average register, array offset: 0x300, array step: 0x10 */
    __I  uint32_t RCSBRLHWMR;                        /**< Root complex 0 system bus read latency high watermark register, array offset: 0x304, array step: 0x10 */
    __IO uint32_t RCSBWLAR;                          /**< Root complex 0 system bus write latency average register, array offset: 0x308, array step: 0x10 */
    __I  uint32_t RCSBWLHWMR;                        /**< Root complex 0 system bus write latency high watermark register, array offset: 0x30C, array step: 0x10 */
  } ARRAY_NUM_RC[NETC_F2_GLOBAL_ARRAY_NUM_RC_COUNT];
  uint8_t RESERVED_7[2280];
  __I  uint32_t IPBRR0;                            /**< IP block revision register 0, offset: 0xBF8 */
  __I  uint32_t IPBRR1;                            /**< IP block revision register 1, offset: 0xBFC */
  uint8_t RESERVED_8[256];
  __I  uint32_t FBLPR[NETC_F2_GLOBAL_G_BOOT_COUNT]; /**< Function boot loader parameter register 0..Function boot loader parameter register 1, array offset: 0xD00, array step: 0x4 */
} NETC_F2_GLOBAL_Type, *NETC_F2_GLOBAL_MemMapPtr;

/** Number of instances of the NETC_F2_GLOBAL module. */
#define NETC_F2_GLOBAL_INSTANCE_COUNT            (1u)

/* NETC_F2_GLOBAL - Peripheral instance base addresses */
/** Peripheral NETC__SW0_GLOBAL base address */
#define IP_NETC__SW0_GLOBAL_BASE                 (0x74A80000u)
/** Peripheral NETC__SW0_GLOBAL base pointer */
#define IP_NETC__SW0_GLOBAL                      ((NETC_F2_GLOBAL_Type *)IP_NETC__SW0_GLOBAL_BASE)
/** Array initializer of NETC_F2_GLOBAL peripheral base addresses */
#define IP_NETC_F2_GLOBAL_BASE_ADDRS             { IP_NETC__SW0_GLOBAL_BASE }
/** Array initializer of NETC_F2_GLOBAL peripheral base pointers */
#define IP_NETC_F2_GLOBAL_BASE_PTRS              { IP_NETC__SW0_GLOBAL }

/* ----------------------------------------------------------------------------
   -- NETC_F2_GLOBAL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_F2_GLOBAL_Register_Masks NETC_F2_GLOBAL Register Masks
 * @{
 */

/*! @name SMCAPR - Shared memory capability register */
/*! @{ */

#define NETC_F2_GLOBAL_SMCAPR_NUM_WORDS_MASK     (0xFFFFFFU)
#define NETC_F2_GLOBAL_SMCAPR_NUM_WORDS_SHIFT    (0U)
#define NETC_F2_GLOBAL_SMCAPR_NUM_WORDS_WIDTH    (24U)
#define NETC_F2_GLOBAL_SMCAPR_NUM_WORDS(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_SMCAPR_NUM_WORDS_SHIFT)) & NETC_F2_GLOBAL_SMCAPR_NUM_WORDS_MASK)
/*! @} */

/*! @name SMDTR - Shared memory depletion threshold register */
/*! @{ */

#define NETC_F2_GLOBAL_SMDTR_THRESH_MASK         (0xFFFFFFU)
#define NETC_F2_GLOBAL_SMDTR_THRESH_SHIFT        (0U)
#define NETC_F2_GLOBAL_SMDTR_THRESH_WIDTH        (24U)
#define NETC_F2_GLOBAL_SMDTR_THRESH(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_SMDTR_THRESH_SHIFT)) & NETC_F2_GLOBAL_SMDTR_THRESH_MASK)
/*! @} */

/*! @name SMACR - Shared memory available count register */
/*! @{ */

#define NETC_F2_GLOBAL_SMACR_COUNT_MASK          (0xFFFFFFU)
#define NETC_F2_GLOBAL_SMACR_COUNT_SHIFT         (0U)
#define NETC_F2_GLOBAL_SMACR_COUNT_WIDTH         (24U)
#define NETC_F2_GLOBAL_SMACR_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_SMACR_COUNT_SHIFT)) & NETC_F2_GLOBAL_SMACR_COUNT_MASK)
/*! @} */

/*! @name SMCLWMR - Shared memory count low watermark register */
/*! @{ */

#define NETC_F2_GLOBAL_SMCLWMR_WATERMARK_MASK    (0xFFFFFFU)
#define NETC_F2_GLOBAL_SMCLWMR_WATERMARK_SHIFT   (0U)
#define NETC_F2_GLOBAL_SMCLWMR_WATERMARK_WIDTH   (24U)
#define NETC_F2_GLOBAL_SMCLWMR_WATERMARK(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_SMCLWMR_WATERMARK_SHIFT)) & NETC_F2_GLOBAL_SMCLWMR_WATERMARK_MASK)
/*! @} */

/*! @name SMBUCR - Shared memory buffer unassigned count register */
/*! @{ */

#define NETC_F2_GLOBAL_SMBUCR_COUNT_MASK         (0xFFFFFFU)
#define NETC_F2_GLOBAL_SMBUCR_COUNT_SHIFT        (0U)
#define NETC_F2_GLOBAL_SMBUCR_COUNT_WIDTH        (24U)
#define NETC_F2_GLOBAL_SMBUCR_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_SMBUCR_COUNT_SHIFT)) & NETC_F2_GLOBAL_SMBUCR_COUNT_MASK)
/*! @} */

/*! @name SMBUCHWMR - Shared memory buffer unassigned count high watermark register */
/*! @{ */

#define NETC_F2_GLOBAL_SMBUCHWMR_WATERMARK_MASK  (0xFFFFFFU)
#define NETC_F2_GLOBAL_SMBUCHWMR_WATERMARK_SHIFT (0U)
#define NETC_F2_GLOBAL_SMBUCHWMR_WATERMARK_WIDTH (24U)
#define NETC_F2_GLOBAL_SMBUCHWMR_WATERMARK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_SMBUCHWMR_WATERMARK_SHIFT)) & NETC_F2_GLOBAL_SMBUCHWMR_WATERMARK_MASK)
/*! @} */

/*! @name SMLCR - Shared memory loss count register */
/*! @{ */

#define NETC_F2_GLOBAL_SMLCR_COUNT_MASK          (0xFFFFFFU)
#define NETC_F2_GLOBAL_SMLCR_COUNT_SHIFT         (0U)
#define NETC_F2_GLOBAL_SMLCR_COUNT_WIDTH         (24U)
#define NETC_F2_GLOBAL_SMLCR_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_SMLCR_COUNT_SHIFT)) & NETC_F2_GLOBAL_SMLCR_COUNT_MASK)

#define NETC_F2_GLOBAL_SMLCR_IFLC_MASK           (0x40000000U)
#define NETC_F2_GLOBAL_SMLCR_IFLC_SHIFT          (30U)
#define NETC_F2_GLOBAL_SMLCR_IFLC_WIDTH          (1U)
#define NETC_F2_GLOBAL_SMLCR_IFLC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_SMLCR_IFLC_SHIFT)) & NETC_F2_GLOBAL_SMLCR_IFLC_MASK)

#define NETC_F2_GLOBAL_SMLCR_IFDC_MASK           (0x80000000U)
#define NETC_F2_GLOBAL_SMLCR_IFDC_SHIFT          (31U)
#define NETC_F2_GLOBAL_SMLCR_IFDC_WIDTH          (1U)
#define NETC_F2_GLOBAL_SMLCR_IFDC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_SMLCR_IFDC_SHIFT)) & NETC_F2_GLOBAL_SMLCR_IFDC_MASK)
/*! @} */

/*! @name HBTCAPR - Hash bucket table capability register */
/*! @{ */

#define NETC_F2_GLOBAL_HBTCAPR_NUM_ENTRIES_MASK  (0xFFFFU)
#define NETC_F2_GLOBAL_HBTCAPR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_GLOBAL_HBTCAPR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_GLOBAL_HBTCAPR_NUM_ENTRIES(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HBTCAPR_NUM_ENTRIES_SHIFT)) & NETC_F2_GLOBAL_HBTCAPR_NUM_ENTRIES_MASK)

#define NETC_F2_GLOBAL_HBTCAPR_MAX_COL_MASK      (0x7000000U)
#define NETC_F2_GLOBAL_HBTCAPR_MAX_COL_SHIFT     (24U)
#define NETC_F2_GLOBAL_HBTCAPR_MAX_COL_WIDTH     (3U)
#define NETC_F2_GLOBAL_HBTCAPR_MAX_COL(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HBTCAPR_MAX_COL_SHIFT)) & NETC_F2_GLOBAL_HBTCAPR_MAX_COL_MASK)

#define NETC_F2_GLOBAL_HBTCAPR_MAX_VISITS_MASK   (0xF0000000U)
#define NETC_F2_GLOBAL_HBTCAPR_MAX_VISITS_SHIFT  (28U)
#define NETC_F2_GLOBAL_HBTCAPR_MAX_VISITS_WIDTH  (4U)
#define NETC_F2_GLOBAL_HBTCAPR_MAX_VISITS(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HBTCAPR_MAX_VISITS_SHIFT)) & NETC_F2_GLOBAL_HBTCAPR_MAX_VISITS_MASK)
/*! @} */

/*! @name HBTOR0 - Hash bucket table operational register 0 */
/*! @{ */

#define NETC_F2_GLOBAL_HBTOR0_NUM_ENTRIES_MASK   (0xFFFFU)
#define NETC_F2_GLOBAL_HBTOR0_NUM_ENTRIES_SHIFT  (0U)
#define NETC_F2_GLOBAL_HBTOR0_NUM_ENTRIES_WIDTH  (16U)
#define NETC_F2_GLOBAL_HBTOR0_NUM_ENTRIES(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HBTOR0_NUM_ENTRIES_SHIFT)) & NETC_F2_GLOBAL_HBTOR0_NUM_ENTRIES_MASK)

#define NETC_F2_GLOBAL_HBTOR0_HWM_ENTRIES_MASK   (0xFFFF0000U)
#define NETC_F2_GLOBAL_HBTOR0_HWM_ENTRIES_SHIFT  (16U)
#define NETC_F2_GLOBAL_HBTOR0_HWM_ENTRIES_WIDTH  (16U)
#define NETC_F2_GLOBAL_HBTOR0_HWM_ENTRIES(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HBTOR0_HWM_ENTRIES_SHIFT)) & NETC_F2_GLOBAL_HBTOR0_HWM_ENTRIES_MASK)
/*! @} */

/*! @name HBTOR2 - Hash bucket table operational register 2 */
/*! @{ */

#define NETC_F2_GLOBAL_HBTOR2_RUN_AVG_FRACT_MASK (0xFFU)
#define NETC_F2_GLOBAL_HBTOR2_RUN_AVG_FRACT_SHIFT (0U)
#define NETC_F2_GLOBAL_HBTOR2_RUN_AVG_FRACT_WIDTH (8U)
#define NETC_F2_GLOBAL_HBTOR2_RUN_AVG_FRACT(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HBTOR2_RUN_AVG_FRACT_SHIFT)) & NETC_F2_GLOBAL_HBTOR2_RUN_AVG_FRACT_MASK)

#define NETC_F2_GLOBAL_HBTOR2_RUN_AVG_INT_MASK   (0xFF00U)
#define NETC_F2_GLOBAL_HBTOR2_RUN_AVG_INT_SHIFT  (8U)
#define NETC_F2_GLOBAL_HBTOR2_RUN_AVG_INT_WIDTH  (8U)
#define NETC_F2_GLOBAL_HBTOR2_RUN_AVG_INT(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HBTOR2_RUN_AVG_INT_SHIFT)) & NETC_F2_GLOBAL_HBTOR2_RUN_AVG_INT_MASK)

#define NETC_F2_GLOBAL_HBTOR2_HWM_COL_MASK       (0xF0000U)
#define NETC_F2_GLOBAL_HBTOR2_HWM_COL_SHIFT      (16U)
#define NETC_F2_GLOBAL_HBTOR2_HWM_COL_WIDTH      (4U)
#define NETC_F2_GLOBAL_HBTOR2_HWM_COL(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HBTOR2_HWM_COL_SHIFT)) & NETC_F2_GLOBAL_HBTOR2_HWM_COL_MASK)
/*! @} */

/*! @name SMERBCAPR - Shared memory ENETC receive buffer capability register */
/*! @{ */

#define NETC_F2_GLOBAL_SMERBCAPR_THRESH_MASK     (0xFFFFFFU)
#define NETC_F2_GLOBAL_SMERBCAPR_THRESH_SHIFT    (0U)
#define NETC_F2_GLOBAL_SMERBCAPR_THRESH_WIDTH    (24U)
#define NETC_F2_GLOBAL_SMERBCAPR_THRESH(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_SMERBCAPR_THRESH_SHIFT)) & NETC_F2_GLOBAL_SMERBCAPR_THRESH_MASK)

#define NETC_F2_GLOBAL_SMERBCAPR_WORD_SIZE_MASK  (0x30000000U)
#define NETC_F2_GLOBAL_SMERBCAPR_WORD_SIZE_SHIFT (28U)
#define NETC_F2_GLOBAL_SMERBCAPR_WORD_SIZE_WIDTH (2U)
#define NETC_F2_GLOBAL_SMERBCAPR_WORD_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_SMERBCAPR_WORD_SIZE_SHIFT)) & NETC_F2_GLOBAL_SMERBCAPR_WORD_SIZE_MASK)

#define NETC_F2_GLOBAL_SMERBCAPR_MLOC_MASK       (0xC0000000U)
#define NETC_F2_GLOBAL_SMERBCAPR_MLOC_SHIFT      (30U)
#define NETC_F2_GLOBAL_SMERBCAPR_MLOC_WIDTH      (2U)
#define NETC_F2_GLOBAL_SMERBCAPR_MLOC(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_SMERBCAPR_MLOC_SHIFT)) & NETC_F2_GLOBAL_SMERBCAPR_MLOC_MASK)
/*! @} */

/*! @name SMERBOR0 - Shared memory ENETC receive buffer operational register 0 */
/*! @{ */

#define NETC_F2_GLOBAL_SMERBOR0_AMOUNT_MASK      (0xFFFFFFU)
#define NETC_F2_GLOBAL_SMERBOR0_AMOUNT_SHIFT     (0U)
#define NETC_F2_GLOBAL_SMERBOR0_AMOUNT_WIDTH     (24U)
#define NETC_F2_GLOBAL_SMERBOR0_AMOUNT(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_SMERBOR0_AMOUNT_SHIFT)) & NETC_F2_GLOBAL_SMERBOR0_AMOUNT_MASK)
/*! @} */

/*! @name SMERBOR1 - Shared memory ENETC receive buffer operational 1 */
/*! @{ */

#define NETC_F2_GLOBAL_SMERBOR1_WATERMARK_MASK   (0xFFFFFFU)
#define NETC_F2_GLOBAL_SMERBOR1_WATERMARK_SHIFT  (0U)
#define NETC_F2_GLOBAL_SMERBOR1_WATERMARK_WIDTH  (24U)
#define NETC_F2_GLOBAL_SMERBOR1_WATERMARK(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_SMERBOR1_WATERMARK_SHIFT)) & NETC_F2_GLOBAL_SMERBOR1_WATERMARK_MASK)
/*! @} */

/*! @name PCEOR - PCE 0 operational register */
/*! @{ */

#define NETC_F2_GLOBAL_PCEOR_NUM_FRAMES_MASK     (0x3FU)
#define NETC_F2_GLOBAL_PCEOR_NUM_FRAMES_SHIFT    (0U)
#define NETC_F2_GLOBAL_PCEOR_NUM_FRAMES_WIDTH    (6U)
#define NETC_F2_GLOBAL_PCEOR_NUM_FRAMES(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_PCEOR_NUM_FRAMES_SHIFT)) & NETC_F2_GLOBAL_PCEOR_NUM_FRAMES_MASK)

#define NETC_F2_GLOBAL_PCEOR_HWM_FRAMES_MASK     (0x3F00U)
#define NETC_F2_GLOBAL_PCEOR_HWM_FRAMES_SHIFT    (8U)
#define NETC_F2_GLOBAL_PCEOR_HWM_FRAMES_WIDTH    (6U)
#define NETC_F2_GLOBAL_PCEOR_HWM_FRAMES(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_PCEOR_HWM_FRAMES_SHIFT)) & NETC_F2_GLOBAL_PCEOR_HWM_FRAMES_MASK)

#define NETC_F2_GLOBAL_PCEOR_MAX_FRAMES_MASK     (0x3F0000U)
#define NETC_F2_GLOBAL_PCEOR_MAX_FRAMES_SHIFT    (16U)
#define NETC_F2_GLOBAL_PCEOR_MAX_FRAMES_WIDTH    (6U)
#define NETC_F2_GLOBAL_PCEOR_MAX_FRAMES(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_PCEOR_MAX_FRAMES_SHIFT)) & NETC_F2_GLOBAL_PCEOR_MAX_FRAMES_MASK)
/*! @} */

/*! @name RFEOR - Replication Forwarding Engine 0 operational register */
/*! @{ */

#define NETC_F2_GLOBAL_RFEOR_NUM_FRAMES_MASK     (0x3FU)
#define NETC_F2_GLOBAL_RFEOR_NUM_FRAMES_SHIFT    (0U)
#define NETC_F2_GLOBAL_RFEOR_NUM_FRAMES_WIDTH    (6U)
#define NETC_F2_GLOBAL_RFEOR_NUM_FRAMES(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_RFEOR_NUM_FRAMES_SHIFT)) & NETC_F2_GLOBAL_RFEOR_NUM_FRAMES_MASK)

#define NETC_F2_GLOBAL_RFEOR_HWM_FRAMES_MASK     (0x3F00U)
#define NETC_F2_GLOBAL_RFEOR_HWM_FRAMES_SHIFT    (8U)
#define NETC_F2_GLOBAL_RFEOR_HWM_FRAMES_WIDTH    (6U)
#define NETC_F2_GLOBAL_RFEOR_HWM_FRAMES(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_RFEOR_HWM_FRAMES_SHIFT)) & NETC_F2_GLOBAL_RFEOR_HWM_FRAMES_MASK)

#define NETC_F2_GLOBAL_RFEOR_MAX_FRAMES_MASK     (0x3F0000U)
#define NETC_F2_GLOBAL_RFEOR_MAX_FRAMES_SHIFT    (16U)
#define NETC_F2_GLOBAL_RFEOR_MAX_FRAMES_WIDTH    (6U)
#define NETC_F2_GLOBAL_RFEOR_MAX_FRAMES(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_RFEOR_MAX_FRAMES_SHIFT)) & NETC_F2_GLOBAL_RFEOR_MAX_FRAMES_MASK)
/*! @} */

/*! @name NETCCLKR - NETC clock register */
/*! @{ */

#define NETC_F2_GLOBAL_NETCCLKR_FREQ_MASK        (0x7FFU)
#define NETC_F2_GLOBAL_NETCCLKR_FREQ_SHIFT       (0U)
#define NETC_F2_GLOBAL_NETCCLKR_FREQ_WIDTH       (11U)
#define NETC_F2_GLOBAL_NETCCLKR_FREQ(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_NETCCLKR_FREQ_SHIFT)) & NETC_F2_GLOBAL_NETCCLKR_FREQ_MASK)
/*! @} */

/*! @name HTACAPR - HTA 0 capability register */
/*! @{ */

#define NETC_F2_GLOBAL_HTACAPR_MAX_RX_FRAMES_MASK (0xFFU)
#define NETC_F2_GLOBAL_HTACAPR_MAX_RX_FRAMES_SHIFT (0U)
#define NETC_F2_GLOBAL_HTACAPR_MAX_RX_FRAMES_WIDTH (8U)
#define NETC_F2_GLOBAL_HTACAPR_MAX_RX_FRAMES(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HTACAPR_MAX_RX_FRAMES_SHIFT)) & NETC_F2_GLOBAL_HTACAPR_MAX_RX_FRAMES_MASK)

#define NETC_F2_GLOBAL_HTACAPR_MAX_TX_FRAMES_MASK (0xFF00U)
#define NETC_F2_GLOBAL_HTACAPR_MAX_TX_FRAMES_SHIFT (8U)
#define NETC_F2_GLOBAL_HTACAPR_MAX_TX_FRAMES_WIDTH (8U)
#define NETC_F2_GLOBAL_HTACAPR_MAX_TX_FRAMES(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HTACAPR_MAX_TX_FRAMES_SHIFT)) & NETC_F2_GLOBAL_HTACAPR_MAX_TX_FRAMES_MASK)
/*! @} */

/*! @name HTARFCOR - HTA 0 receive frame count operational register */
/*! @{ */

#define NETC_F2_GLOBAL_HTARFCOR_HP_COUNT_MASK    (0xFFU)
#define NETC_F2_GLOBAL_HTARFCOR_HP_COUNT_SHIFT   (0U)
#define NETC_F2_GLOBAL_HTARFCOR_HP_COUNT_WIDTH   (8U)
#define NETC_F2_GLOBAL_HTARFCOR_HP_COUNT(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HTARFCOR_HP_COUNT_SHIFT)) & NETC_F2_GLOBAL_HTARFCOR_HP_COUNT_MASK)

#define NETC_F2_GLOBAL_HTARFCOR_HP_HWM_MASK      (0xFF00U)
#define NETC_F2_GLOBAL_HTARFCOR_HP_HWM_SHIFT     (8U)
#define NETC_F2_GLOBAL_HTARFCOR_HP_HWM_WIDTH     (8U)
#define NETC_F2_GLOBAL_HTARFCOR_HP_HWM(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HTARFCOR_HP_HWM_SHIFT)) & NETC_F2_GLOBAL_HTARFCOR_HP_HWM_MASK)

#define NETC_F2_GLOBAL_HTARFCOR_LP_COUNT_MASK    (0xFF0000U)
#define NETC_F2_GLOBAL_HTARFCOR_LP_COUNT_SHIFT   (16U)
#define NETC_F2_GLOBAL_HTARFCOR_LP_COUNT_WIDTH   (8U)
#define NETC_F2_GLOBAL_HTARFCOR_LP_COUNT(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HTARFCOR_LP_COUNT_SHIFT)) & NETC_F2_GLOBAL_HTARFCOR_LP_COUNT_MASK)

#define NETC_F2_GLOBAL_HTARFCOR_LP_HWM_MASK      (0xFF000000U)
#define NETC_F2_GLOBAL_HTARFCOR_LP_HWM_SHIFT     (24U)
#define NETC_F2_GLOBAL_HTARFCOR_LP_HWM_WIDTH     (8U)
#define NETC_F2_GLOBAL_HTARFCOR_LP_HWM(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HTARFCOR_LP_HWM_SHIFT)) & NETC_F2_GLOBAL_HTARFCOR_LP_HWM_MASK)
/*! @} */

/*! @name HTAHPBCOR - HTA 0 high priority byte count operational register */
/*! @{ */

#define NETC_F2_GLOBAL_HTAHPBCOR_HP_COUNT_MASK   (0xFFFFU)
#define NETC_F2_GLOBAL_HTAHPBCOR_HP_COUNT_SHIFT  (0U)
#define NETC_F2_GLOBAL_HTAHPBCOR_HP_COUNT_WIDTH  (16U)
#define NETC_F2_GLOBAL_HTAHPBCOR_HP_COUNT(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HTAHPBCOR_HP_COUNT_SHIFT)) & NETC_F2_GLOBAL_HTAHPBCOR_HP_COUNT_MASK)

#define NETC_F2_GLOBAL_HTAHPBCOR_HWM_MASK        (0xFFFF0000U)
#define NETC_F2_GLOBAL_HTAHPBCOR_HWM_SHIFT       (16U)
#define NETC_F2_GLOBAL_HTAHPBCOR_HWM_WIDTH       (16U)
#define NETC_F2_GLOBAL_HTAHPBCOR_HWM(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HTAHPBCOR_HWM_SHIFT)) & NETC_F2_GLOBAL_HTAHPBCOR_HWM_MASK)
/*! @} */

/*! @name HTALPBCOR - HTA 0 low priority byte count operational register */
/*! @{ */

#define NETC_F2_GLOBAL_HTALPBCOR_LP_COUNT_MASK   (0xFFFFU)
#define NETC_F2_GLOBAL_HTALPBCOR_LP_COUNT_SHIFT  (0U)
#define NETC_F2_GLOBAL_HTALPBCOR_LP_COUNT_WIDTH  (16U)
#define NETC_F2_GLOBAL_HTALPBCOR_LP_COUNT(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HTALPBCOR_LP_COUNT_SHIFT)) & NETC_F2_GLOBAL_HTALPBCOR_LP_COUNT_MASK)

#define NETC_F2_GLOBAL_HTALPBCOR_HWM_MASK        (0xFFFF0000U)
#define NETC_F2_GLOBAL_HTALPBCOR_HWM_SHIFT       (16U)
#define NETC_F2_GLOBAL_HTALPBCOR_HWM_WIDTH       (16U)
#define NETC_F2_GLOBAL_HTALPBCOR_HWM(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HTALPBCOR_HWM_SHIFT)) & NETC_F2_GLOBAL_HTALPBCOR_HWM_MASK)
/*! @} */

/*! @name HTATFCOR - HTA 0 transmit frame count operational register */
/*! @{ */

#define NETC_F2_GLOBAL_HTATFCOR_HP_COUNT_MASK    (0xFFU)
#define NETC_F2_GLOBAL_HTATFCOR_HP_COUNT_SHIFT   (0U)
#define NETC_F2_GLOBAL_HTATFCOR_HP_COUNT_WIDTH   (8U)
#define NETC_F2_GLOBAL_HTATFCOR_HP_COUNT(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HTATFCOR_HP_COUNT_SHIFT)) & NETC_F2_GLOBAL_HTATFCOR_HP_COUNT_MASK)

#define NETC_F2_GLOBAL_HTATFCOR_HP_HWM_MASK      (0xFF00U)
#define NETC_F2_GLOBAL_HTATFCOR_HP_HWM_SHIFT     (8U)
#define NETC_F2_GLOBAL_HTATFCOR_HP_HWM_WIDTH     (8U)
#define NETC_F2_GLOBAL_HTATFCOR_HP_HWM(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HTATFCOR_HP_HWM_SHIFT)) & NETC_F2_GLOBAL_HTATFCOR_HP_HWM_MASK)

#define NETC_F2_GLOBAL_HTATFCOR_LP_COUNT_MASK    (0xFF0000U)
#define NETC_F2_GLOBAL_HTATFCOR_LP_COUNT_SHIFT   (16U)
#define NETC_F2_GLOBAL_HTATFCOR_LP_COUNT_WIDTH   (8U)
#define NETC_F2_GLOBAL_HTATFCOR_LP_COUNT(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HTATFCOR_LP_COUNT_SHIFT)) & NETC_F2_GLOBAL_HTATFCOR_LP_COUNT_MASK)

#define NETC_F2_GLOBAL_HTATFCOR_LP_HWM_MASK      (0xFF000000U)
#define NETC_F2_GLOBAL_HTATFCOR_LP_HWM_SHIFT     (24U)
#define NETC_F2_GLOBAL_HTATFCOR_LP_HWM_WIDTH     (8U)
#define NETC_F2_GLOBAL_HTATFCOR_LP_HWM(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_HTATFCOR_LP_HWM_SHIFT)) & NETC_F2_GLOBAL_HTATFCOR_LP_HWM_MASK)
/*! @} */

/*! @name RCSBRLAR - Root complex 0 system bus read latency average register */
/*! @{ */

#define NETC_F2_GLOBAL_RCSBRLAR_FRACT_MASK       (0xFFU)
#define NETC_F2_GLOBAL_RCSBRLAR_FRACT_SHIFT      (0U)
#define NETC_F2_GLOBAL_RCSBRLAR_FRACT_WIDTH      (8U)
#define NETC_F2_GLOBAL_RCSBRLAR_FRACT(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_RCSBRLAR_FRACT_SHIFT)) & NETC_F2_GLOBAL_RCSBRLAR_FRACT_MASK)

#define NETC_F2_GLOBAL_RCSBRLAR_INT_MASK         (0xFFF00U)
#define NETC_F2_GLOBAL_RCSBRLAR_INT_SHIFT        (8U)
#define NETC_F2_GLOBAL_RCSBRLAR_INT_WIDTH        (12U)
#define NETC_F2_GLOBAL_RCSBRLAR_INT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_RCSBRLAR_INT_SHIFT)) & NETC_F2_GLOBAL_RCSBRLAR_INT_MASK)
/*! @} */

/*! @name RCSBRLHWMR - Root complex 0 system bus read latency high watermark register */
/*! @{ */

#define NETC_F2_GLOBAL_RCSBRLHWMR_FRACT_MASK     (0xFFU)
#define NETC_F2_GLOBAL_RCSBRLHWMR_FRACT_SHIFT    (0U)
#define NETC_F2_GLOBAL_RCSBRLHWMR_FRACT_WIDTH    (8U)
#define NETC_F2_GLOBAL_RCSBRLHWMR_FRACT(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_RCSBRLHWMR_FRACT_SHIFT)) & NETC_F2_GLOBAL_RCSBRLHWMR_FRACT_MASK)

#define NETC_F2_GLOBAL_RCSBRLHWMR_INT_MASK       (0xFFF00U)
#define NETC_F2_GLOBAL_RCSBRLHWMR_INT_SHIFT      (8U)
#define NETC_F2_GLOBAL_RCSBRLHWMR_INT_WIDTH      (12U)
#define NETC_F2_GLOBAL_RCSBRLHWMR_INT(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_RCSBRLHWMR_INT_SHIFT)) & NETC_F2_GLOBAL_RCSBRLHWMR_INT_MASK)
/*! @} */

/*! @name RCSBWLAR - Root complex 0 system bus write latency average register */
/*! @{ */

#define NETC_F2_GLOBAL_RCSBWLAR_FRACT_MASK       (0xFFU)
#define NETC_F2_GLOBAL_RCSBWLAR_FRACT_SHIFT      (0U)
#define NETC_F2_GLOBAL_RCSBWLAR_FRACT_WIDTH      (8U)
#define NETC_F2_GLOBAL_RCSBWLAR_FRACT(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_RCSBWLAR_FRACT_SHIFT)) & NETC_F2_GLOBAL_RCSBWLAR_FRACT_MASK)

#define NETC_F2_GLOBAL_RCSBWLAR_INT_MASK         (0xFFF00U)
#define NETC_F2_GLOBAL_RCSBWLAR_INT_SHIFT        (8U)
#define NETC_F2_GLOBAL_RCSBWLAR_INT_WIDTH        (12U)
#define NETC_F2_GLOBAL_RCSBWLAR_INT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_RCSBWLAR_INT_SHIFT)) & NETC_F2_GLOBAL_RCSBWLAR_INT_MASK)
/*! @} */

/*! @name RCSBWLHWMR - Root complex 0 system bus write latency high watermark register */
/*! @{ */

#define NETC_F2_GLOBAL_RCSBWLHWMR_FRACT_MASK     (0xFFU)
#define NETC_F2_GLOBAL_RCSBWLHWMR_FRACT_SHIFT    (0U)
#define NETC_F2_GLOBAL_RCSBWLHWMR_FRACT_WIDTH    (8U)
#define NETC_F2_GLOBAL_RCSBWLHWMR_FRACT(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_RCSBWLHWMR_FRACT_SHIFT)) & NETC_F2_GLOBAL_RCSBWLHWMR_FRACT_MASK)

#define NETC_F2_GLOBAL_RCSBWLHWMR_INT_MASK       (0xFFF00U)
#define NETC_F2_GLOBAL_RCSBWLHWMR_INT_SHIFT      (8U)
#define NETC_F2_GLOBAL_RCSBWLHWMR_INT_WIDTH      (12U)
#define NETC_F2_GLOBAL_RCSBWLHWMR_INT(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_RCSBWLHWMR_INT_SHIFT)) & NETC_F2_GLOBAL_RCSBWLHWMR_INT_MASK)
/*! @} */

/*! @name IPBRR0 - IP block revision register 0 */
/*! @{ */

#define NETC_F2_GLOBAL_IPBRR0_IP_MN_MASK         (0xFFU)
#define NETC_F2_GLOBAL_IPBRR0_IP_MN_SHIFT        (0U)
#define NETC_F2_GLOBAL_IPBRR0_IP_MN_WIDTH        (8U)
#define NETC_F2_GLOBAL_IPBRR0_IP_MN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_IPBRR0_IP_MN_SHIFT)) & NETC_F2_GLOBAL_IPBRR0_IP_MN_MASK)

#define NETC_F2_GLOBAL_IPBRR0_IP_MJ_MASK         (0xFF00U)
#define NETC_F2_GLOBAL_IPBRR0_IP_MJ_SHIFT        (8U)
#define NETC_F2_GLOBAL_IPBRR0_IP_MJ_WIDTH        (8U)
#define NETC_F2_GLOBAL_IPBRR0_IP_MJ(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_IPBRR0_IP_MJ_SHIFT)) & NETC_F2_GLOBAL_IPBRR0_IP_MJ_MASK)

#define NETC_F2_GLOBAL_IPBRR0_IP_ID_MASK         (0xFFFF0000U)
#define NETC_F2_GLOBAL_IPBRR0_IP_ID_SHIFT        (16U)
#define NETC_F2_GLOBAL_IPBRR0_IP_ID_WIDTH        (16U)
#define NETC_F2_GLOBAL_IPBRR0_IP_ID(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_IPBRR0_IP_ID_SHIFT)) & NETC_F2_GLOBAL_IPBRR0_IP_ID_MASK)
/*! @} */

/*! @name IPBRR1 - IP block revision register 1 */
/*! @{ */

#define NETC_F2_GLOBAL_IPBRR1_IP_CFG_MASK        (0xFFU)
#define NETC_F2_GLOBAL_IPBRR1_IP_CFG_SHIFT       (0U)
#define NETC_F2_GLOBAL_IPBRR1_IP_CFG_WIDTH       (8U)
#define NETC_F2_GLOBAL_IPBRR1_IP_CFG(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_IPBRR1_IP_CFG_SHIFT)) & NETC_F2_GLOBAL_IPBRR1_IP_CFG_MASK)

#define NETC_F2_GLOBAL_IPBRR1_IP_MNT_MASK        (0xFF00U)
#define NETC_F2_GLOBAL_IPBRR1_IP_MNT_SHIFT       (8U)
#define NETC_F2_GLOBAL_IPBRR1_IP_MNT_WIDTH       (8U)
#define NETC_F2_GLOBAL_IPBRR1_IP_MNT(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_IPBRR1_IP_MNT_SHIFT)) & NETC_F2_GLOBAL_IPBRR1_IP_MNT_MASK)

#define NETC_F2_GLOBAL_IPBRR1_IP_INT_MASK        (0xFF0000U)
#define NETC_F2_GLOBAL_IPBRR1_IP_INT_SHIFT       (16U)
#define NETC_F2_GLOBAL_IPBRR1_IP_INT_WIDTH       (8U)
#define NETC_F2_GLOBAL_IPBRR1_IP_INT(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_IPBRR1_IP_INT_SHIFT)) & NETC_F2_GLOBAL_IPBRR1_IP_INT_MASK)
/*! @} */

/*! @name FBLPR - Function boot loader parameter register 0..Function boot loader parameter register 1 */
/*! @{ */

#define NETC_F2_GLOBAL_FBLPR_PARAM_VAL_MASK      (0xFFFFFFFFU)
#define NETC_F2_GLOBAL_FBLPR_PARAM_VAL_SHIFT     (0U)
#define NETC_F2_GLOBAL_FBLPR_PARAM_VAL_WIDTH     (32U)
#define NETC_F2_GLOBAL_FBLPR_PARAM_VAL(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_GLOBAL_FBLPR_PARAM_VAL_SHIFT)) & NETC_F2_GLOBAL_FBLPR_PARAM_VAL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group NETC_F2_GLOBAL_Register_Masks */

/*!
 * @}
 */ /* end of group NETC_F2_GLOBAL_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_NETC_F2_GLOBAL_H_) */
