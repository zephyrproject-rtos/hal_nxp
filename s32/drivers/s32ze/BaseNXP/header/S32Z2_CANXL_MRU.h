/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_CANXL_MRU.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_CANXL_MRU
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
#if !defined(S32Z2_CANXL_MRU_H_)  /* Check if memory map has not been already included */
#define S32Z2_CANXL_MRU_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CANXL_MRU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CANXL_MRU_Peripheral_Access_Layer CANXL_MRU Peripheral Access Layer
 * @{
 */

/** CANXL_MRU - Size of Registers Arrays */
#define CANXL_MRU_CHXCONFIG_COUNT                 1u
#define CANXL_MRU_NOTIFY_COUNT                    2u

/** CANXL_MRU - Register Layout Typedef */
typedef struct {
  struct CANXL_MRU_CHXCONFIG {                     /* offset: 0x0, array step: 0xC */
    __IO uint32_t CH_CFG0;                           /**< Channel (x) Configuration 0, array offset: 0x0, array step: 0xC */
    __IO uint32_t CH_CFG1;                           /**< Channel (x) Configuration 1, array offset: 0x4, array step: 0xC */
    __IO uint32_t CH_MBSTAT;                         /**< Channel (x) Mailbox Status, array offset: 0x8, array step: 0xC */
  } CHXCONFIG[CANXL_MRU_CHXCONFIG_COUNT];
  uint8_t RESERVED_0[500];
  __I  uint32_t NOTIFY[CANXL_MRU_NOTIFY_COUNT];    /**< Notification 0 Status..Notification 1 Status, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_1[3576];
  __IO uint32_t CH1_MB0;                           /**< Channel (x) Mailbox (n), offset: 0x1000 */
  __IO uint32_t CH1_MB1;                           /**< Channel (x) Mailbox (n), offset: 0x1004 */
  __IO uint32_t CH1_MB2;                           /**< Channel (x) Mailbox (n), offset: 0x1008 */
  __IO uint32_t CH1_MB3;                           /**< Channel (x) Mailbox (n), offset: 0x100C */
} CANXL_MRU_Type, *CANXL_MRU_MemMapPtr;

/** Number of instances of the CANXL_MRU module. */
#define CANXL_MRU_INSTANCE_COUNT                 (2u)

/* CANXL_MRU - Peripheral instance base addresses */
/** Peripheral CANXL_0__MRU base address */
#define IP_CANXL_0__MRU_BASE                     (0x47427000u)
/** Peripheral CANXL_0__MRU base pointer */
#define IP_CANXL_0__MRU                          ((CANXL_MRU_Type *)IP_CANXL_0__MRU_BASE)
/** Peripheral CANXL_1__MRU base address */
#define IP_CANXL_1__MRU_BASE                     (0x47527000u)
/** Peripheral CANXL_1__MRU base pointer */
#define IP_CANXL_1__MRU                          ((CANXL_MRU_Type *)IP_CANXL_1__MRU_BASE)
/** Array initializer of CANXL_MRU peripheral base addresses */
#define IP_CANXL_MRU_BASE_ADDRS                  { IP_CANXL_0__MRU_BASE, IP_CANXL_1__MRU_BASE }
/** Array initializer of CANXL_MRU peripheral base pointers */
#define IP_CANXL_MRU_BASE_PTRS                   { IP_CANXL_0__MRU, IP_CANXL_1__MRU }

/* ----------------------------------------------------------------------------
   -- CANXL_MRU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CANXL_MRU_Register_Masks CANXL_MRU Register Masks
 * @{
 */

/*! @name CH_CFG0 - Channel (x) Configuration 0 */
/*! @{ */

#define CANXL_MRU_CH_CFG0_CHE_MASK               (0x1U)
#define CANXL_MRU_CH_CFG0_CHE_SHIFT              (0U)
#define CANXL_MRU_CH_CFG0_CHE_WIDTH              (1U)
#define CANXL_MRU_CH_CFG0_CHE(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_CFG0_CHE_SHIFT)) & CANXL_MRU_CH_CFG0_CHE_MASK)

#define CANXL_MRU_CH_CFG0_CHR_MASK               (0x2U)
#define CANXL_MRU_CH_CFG0_CHR_SHIFT              (1U)
#define CANXL_MRU_CH_CFG0_CHR_WIDTH              (1U)
#define CANXL_MRU_CH_CFG0_CHR(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_CFG0_CHR_SHIFT)) & CANXL_MRU_CH_CFG0_CHR_MASK)

#define CANXL_MRU_CH_CFG0_IE_MASK                (0x4U)
#define CANXL_MRU_CH_CFG0_IE_SHIFT               (2U)
#define CANXL_MRU_CH_CFG0_IE_WIDTH               (1U)
#define CANXL_MRU_CH_CFG0_IE(x)                  (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_CFG0_IE_SHIFT)) & CANXL_MRU_CH_CFG0_IE_MASK)

#define CANXL_MRU_CH_CFG0_MBE0_MASK              (0x10000U)
#define CANXL_MRU_CH_CFG0_MBE0_SHIFT             (16U)
#define CANXL_MRU_CH_CFG0_MBE0_WIDTH             (1U)
#define CANXL_MRU_CH_CFG0_MBE0(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_CFG0_MBE0_SHIFT)) & CANXL_MRU_CH_CFG0_MBE0_MASK)

#define CANXL_MRU_CH_CFG0_MBE1_MASK              (0x20000U)
#define CANXL_MRU_CH_CFG0_MBE1_SHIFT             (17U)
#define CANXL_MRU_CH_CFG0_MBE1_WIDTH             (1U)
#define CANXL_MRU_CH_CFG0_MBE1(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_CFG0_MBE1_SHIFT)) & CANXL_MRU_CH_CFG0_MBE1_MASK)

#define CANXL_MRU_CH_CFG0_MBE2_MASK              (0x40000U)
#define CANXL_MRU_CH_CFG0_MBE2_SHIFT             (18U)
#define CANXL_MRU_CH_CFG0_MBE2_WIDTH             (1U)
#define CANXL_MRU_CH_CFG0_MBE2(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_CFG0_MBE2_SHIFT)) & CANXL_MRU_CH_CFG0_MBE2_MASK)

#define CANXL_MRU_CH_CFG0_MBE3_MASK              (0x80000U)
#define CANXL_MRU_CH_CFG0_MBE3_SHIFT             (19U)
#define CANXL_MRU_CH_CFG0_MBE3_WIDTH             (1U)
#define CANXL_MRU_CH_CFG0_MBE3(x)                (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_CFG0_MBE3_SHIFT)) & CANXL_MRU_CH_CFG0_MBE3_MASK)
/*! @} */

/*! @name CH_CFG1 - Channel (x) Configuration 1 */
/*! @{ */

#define CANXL_MRU_CH_CFG1_MBIC0_MASK             (0x10000U)
#define CANXL_MRU_CH_CFG1_MBIC0_SHIFT            (16U)
#define CANXL_MRU_CH_CFG1_MBIC0_WIDTH            (1U)
#define CANXL_MRU_CH_CFG1_MBIC0(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_CFG1_MBIC0_SHIFT)) & CANXL_MRU_CH_CFG1_MBIC0_MASK)

#define CANXL_MRU_CH_CFG1_MBIC1_MASK             (0x20000U)
#define CANXL_MRU_CH_CFG1_MBIC1_SHIFT            (17U)
#define CANXL_MRU_CH_CFG1_MBIC1_WIDTH            (1U)
#define CANXL_MRU_CH_CFG1_MBIC1(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_CFG1_MBIC1_SHIFT)) & CANXL_MRU_CH_CFG1_MBIC1_MASK)

#define CANXL_MRU_CH_CFG1_MBIC2_MASK             (0x40000U)
#define CANXL_MRU_CH_CFG1_MBIC2_SHIFT            (18U)
#define CANXL_MRU_CH_CFG1_MBIC2_WIDTH            (1U)
#define CANXL_MRU_CH_CFG1_MBIC2(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_CFG1_MBIC2_SHIFT)) & CANXL_MRU_CH_CFG1_MBIC2_MASK)

#define CANXL_MRU_CH_CFG1_MBIC3_MASK             (0x80000U)
#define CANXL_MRU_CH_CFG1_MBIC3_SHIFT            (19U)
#define CANXL_MRU_CH_CFG1_MBIC3_WIDTH            (1U)
#define CANXL_MRU_CH_CFG1_MBIC3(x)               (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_CFG1_MBIC3_SHIFT)) & CANXL_MRU_CH_CFG1_MBIC3_MASK)
/*! @} */

/*! @name CH_MBSTAT - Channel (x) Mailbox Status */
/*! @{ */

#define CANXL_MRU_CH_MBSTAT_MBS0_MASK            (0x10000U)
#define CANXL_MRU_CH_MBSTAT_MBS0_SHIFT           (16U)
#define CANXL_MRU_CH_MBSTAT_MBS0_WIDTH           (1U)
#define CANXL_MRU_CH_MBSTAT_MBS0(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_MBSTAT_MBS0_SHIFT)) & CANXL_MRU_CH_MBSTAT_MBS0_MASK)

#define CANXL_MRU_CH_MBSTAT_MBS1_MASK            (0x20000U)
#define CANXL_MRU_CH_MBSTAT_MBS1_SHIFT           (17U)
#define CANXL_MRU_CH_MBSTAT_MBS1_WIDTH           (1U)
#define CANXL_MRU_CH_MBSTAT_MBS1(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_MBSTAT_MBS1_SHIFT)) & CANXL_MRU_CH_MBSTAT_MBS1_MASK)

#define CANXL_MRU_CH_MBSTAT_MBS2_MASK            (0x40000U)
#define CANXL_MRU_CH_MBSTAT_MBS2_SHIFT           (18U)
#define CANXL_MRU_CH_MBSTAT_MBS2_WIDTH           (1U)
#define CANXL_MRU_CH_MBSTAT_MBS2(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_MBSTAT_MBS2_SHIFT)) & CANXL_MRU_CH_MBSTAT_MBS2_MASK)

#define CANXL_MRU_CH_MBSTAT_MBS3_MASK            (0x80000U)
#define CANXL_MRU_CH_MBSTAT_MBS3_SHIFT           (19U)
#define CANXL_MRU_CH_MBSTAT_MBS3_WIDTH           (1U)
#define CANXL_MRU_CH_MBSTAT_MBS3(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH_MBSTAT_MBS3_SHIFT)) & CANXL_MRU_CH_MBSTAT_MBS3_MASK)
/*! @} */

/*! @name NOTIFY - Notification 0 Status..Notification 1 Status */
/*! @{ */

#define CANXL_MRU_NOTIFY_CH1_IS0_MASK            (0x1U)
#define CANXL_MRU_NOTIFY_CH1_IS0_SHIFT           (0U)
#define CANXL_MRU_NOTIFY_CH1_IS0_WIDTH           (1U)
#define CANXL_MRU_NOTIFY_CH1_IS0(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_NOTIFY_CH1_IS0_SHIFT)) & CANXL_MRU_NOTIFY_CH1_IS0_MASK)

#define CANXL_MRU_NOTIFY_CH1_IS1_MASK            (0x1U)
#define CANXL_MRU_NOTIFY_CH1_IS1_SHIFT           (0U)
#define CANXL_MRU_NOTIFY_CH1_IS1_WIDTH           (1U)
#define CANXL_MRU_NOTIFY_CH1_IS1(x)              (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_NOTIFY_CH1_IS1_SHIFT)) & CANXL_MRU_NOTIFY_CH1_IS1_MASK)
/*! @} */

/*! @name CH1_MB0 - Channel (x) Mailbox (n) */
/*! @{ */

#define CANXL_MRU_CH1_MB0_MBD_MASK               (0xFFFFFFFFU)
#define CANXL_MRU_CH1_MB0_MBD_SHIFT              (0U)
#define CANXL_MRU_CH1_MB0_MBD_WIDTH              (32U)
#define CANXL_MRU_CH1_MB0_MBD(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH1_MB0_MBD_SHIFT)) & CANXL_MRU_CH1_MB0_MBD_MASK)
/*! @} */

/*! @name CH1_MB1 - Channel (x) Mailbox (n) */
/*! @{ */

#define CANXL_MRU_CH1_MB1_MBD_MASK               (0xFFFFFFFFU)
#define CANXL_MRU_CH1_MB1_MBD_SHIFT              (0U)
#define CANXL_MRU_CH1_MB1_MBD_WIDTH              (32U)
#define CANXL_MRU_CH1_MB1_MBD(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH1_MB1_MBD_SHIFT)) & CANXL_MRU_CH1_MB1_MBD_MASK)
/*! @} */

/*! @name CH1_MB2 - Channel (x) Mailbox (n) */
/*! @{ */

#define CANXL_MRU_CH1_MB2_MBD_MASK               (0xFFFFFFFFU)
#define CANXL_MRU_CH1_MB2_MBD_SHIFT              (0U)
#define CANXL_MRU_CH1_MB2_MBD_WIDTH              (32U)
#define CANXL_MRU_CH1_MB2_MBD(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH1_MB2_MBD_SHIFT)) & CANXL_MRU_CH1_MB2_MBD_MASK)
/*! @} */

/*! @name CH1_MB3 - Channel (x) Mailbox (n) */
/*! @{ */

#define CANXL_MRU_CH1_MB3_MBD_MASK               (0xFFFFFFFFU)
#define CANXL_MRU_CH1_MB3_MBD_SHIFT              (0U)
#define CANXL_MRU_CH1_MB3_MBD_WIDTH              (32U)
#define CANXL_MRU_CH1_MB3_MBD(x)                 (((uint32_t)(((uint32_t)(x)) << CANXL_MRU_CH1_MB3_MBD_SHIFT)) & CANXL_MRU_CH1_MB3_MBD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CANXL_MRU_Register_Masks */

/*!
 * @}
 */ /* end of group CANXL_MRU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_CANXL_MRU_H_) */
