/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_MRAMC.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_MRAMC
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
#if !defined(S32K566_MRAMC_H_)  /* Check if memory map has not been already included */
#define S32K566_MRAMC_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MRAMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRAMC_Peripheral_Access_Layer MRAMC Peripheral Access Layer
 * @{
 */

/** MRAMC - Size of Registers Arrays */
#define MRAMC_PCI_COUNT                           3u
#define MRAMC_PLPLOCKN_COUNT                      1u
#define MRAMC_LLOCKOWNERN_COUNT                   8u
#define MRAMC_LOCKOWNERN_COUNT                    3u
#define MRAMC_WRL_WDATAL_PAGEI_WORD_COUNT         8u
#define MRAMC_WRL_WDATAL_PAGEI_WORD_WDATAL_PAGEI_WORDJ_COUNT 8u
#define MRAMC_WRL_WSTRBL_PAGEI_COUNT              8u
#define MRAMC_WRL_COUNT                           2u

/** MRAMC - Register Layout Typedef */
typedef struct MRAMC_Struct {
  uint8_t RESERVED_0[4];
  __IO uint32_t PC[MRAMC_PCI_COUNT];               /**< Port Configuration, array offset: 0x4, array step: 0x4 */
  uint8_t RESERVED_1[128];
  __IO uint32_t P1_RIA_W0;                         /**< Port i Read ID Assignment Word j, offset: 0x90 */
  __IO uint32_t P1_RIA_W1;                         /**< Port i Read ID Assignment Word j, offset: 0x94 */
  uint8_t RESERVED_2[8];
  __IO uint32_t P2_RIA_W0;                         /**< Port i Read ID Assignment Word j, offset: 0xA0 */
  __IO uint32_t P2_RIA_W1;                         /**< Port i Read ID Assignment Word j, offset: 0xA4 */
  uint8_t RESERVED_3[8];
  __IO uint32_t P3_RIA_W0;                         /**< Port i Read ID Assignment Word j, offset: 0xB0 */
  uint8_t RESERVED_4[76];
  __IO uint32_t LPLOCK;                            /**< Large Partition Lock, offset: 0x100 */
  uint8_t RESERVED_5[12];
  __IO uint32_t SPLOCK;                            /**< Small Partition Lock, offset: 0x110 */
  uint8_t RESERVED_6[4];
  __IO uint32_t LPOLOCK;                           /**< Large Partition OTP Lock, offset: 0x118 */
  __IO uint32_t UTLOCK;                            /**< UTest Lock, offset: 0x11C */
  uint8_t RESERVED_7[16];
  __IO uint32_t PLPLOCK[MRAMC_PLPLOCKN_COUNT];     /**< Protect Large Partition Lock, array offset: 0x130, array step: 0x4 */
  uint8_t RESERVED_8[12];
  __IO uint32_t PSPLOCK;                           /**< Protect Small Partition Lock, offset: 0x140 */
  uint8_t RESERVED_9[4];
  __IO uint32_t PLPOLOCK;                          /**< Protect Large Partition OTP Lock, offset: 0x148 */
  __IO uint32_t PUTLOCK;                           /**< Protect UTest Lock, offset: 0x14C */
  uint8_t RESERVED_10[176];
  __I  uint32_t LPLOCKOW[MRAMC_LLOCKOWNERN_COUNT]; /**< Large Partition Lock Owner, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_11[224];
  __I  uint32_t LOCKOW[MRAMC_LOCKOWNERN_COUNT];    /**< Small partition Lock Owner..UTest Lock Owner, array offset: 0x300, array step: 0x4 */
  uint8_t RESERVED_12[116];
  __IO uint32_t ERRINJCTL;                         /**< Error Injection Control, offset: 0x380 */
  uint8_t RESERVED_13[4];
  __IO uint32_t ERRSTAT0;                          /**< Error Status 0, offset: 0x388 */
  __I  uint32_t ERRSTAT1;                          /**< Error Status 1, offset: 0x38C */
  uint8_t RESERVED_14[16];
  __IO uint32_t ERRNTCTL0;                         /**< Error Notification Control 0, offset: 0x3A0 */
  uint8_t RESERVED_15[88];
  __IO uint32_t WWDOG;                             /**< Write Watchdog, offset: 0x3FC */
  struct MRAMC_WRL {                               /* offset: 0x400, array step: 0x200 */
    __IO uint32_t WDATA_PAGE_WORD[MRAMC_WRL_WDATAL_PAGEI_WORD_COUNT][MRAMC_WRL_WDATAL_PAGEI_WORD_WDATAL_PAGEI_WORDJ_COUNT];   /**< Write Data, array offset: 0x400, array step: index*0x200, index2*0x20, index3*0x4 */
    __IO uint32_t WSTRB_PAGE[MRAMC_WRL_WSTRBL_PAGEI_COUNT];   /**< Write Strobe, array offset: 0x500, array step: index*0x200, index2*0x4 */
    __IO uint32_t WADDR;                             /**< Write Address, array offset: 0x520, array step: 0x200 */
    __IO uint32_t WCTL;                              /**< Write Control, array offset: 0x524, array step: 0x200 */
    __IO uint32_t WSTAT;                             /**< Write Status, array offset: 0x528, array step: 0x200 */
    uint8_t RESERVED_0[212];
  } WRL[MRAMC_WRL_COUNT];
  uint8_t RESERVED_16[2032];
       uint32_t DBGSTAT0;                          /**< Debug Status 0, offset: 0xFF0 */
       uint32_t DBGSTAT1;                          /**< Debug Status 1, offset: 0xFF4 */
       uint32_t DBGSTAT2;                          /**< Debug Status 2, offset: 0xFF8 */
       uint32_t DBGSTAT3;                          /**< Debug Status 3, offset: 0xFFC */
} MRAMC_Type, *MRAMC_MemMapPtr;

/** Number of instances of the MRAMC module. */
#define MRAMC_INSTANCE_COUNT                     (1u)

/* MRAMC - Peripheral instance base addresses */
/** Peripheral MRAMC base address */
#define IP_MRAMC_BASE                            (0x4049C000u)
/** Peripheral MRAMC base pointer */
#define IP_MRAMC                                 ((MRAMC_Type *)IP_MRAMC_BASE)
/** Array initializer of MRAMC peripheral base addresses */
#define IP_MRAMC_BASE_ADDRS                      { IP_MRAMC_BASE }
/** Array initializer of MRAMC peripheral base pointers */
#define IP_MRAMC_BASE_PTRS                       { IP_MRAMC }

/* ----------------------------------------------------------------------------
   -- MRAMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRAMC_Register_Masks MRAMC Register Masks
 * @{
 */

/*! @name PC - Port Configuration */
/*! @{ */

#define MRAMC_PC_RCBFEN_MASK                     (0x1U)
#define MRAMC_PC_RCBFEN_SHIFT                    (0U)
#define MRAMC_PC_RCBFEN_WIDTH                    (1U)
#define MRAMC_PC_RCBFEN(x)                       (((uint32_t)(((uint32_t)(x)) << MRAMC_PC_RCBFEN_SHIFT)) & MRAMC_PC_RCBFEN_MASK)

#define MRAMC_PC_RDBFEN_MASK                     (0x2U)
#define MRAMC_PC_RDBFEN_SHIFT                    (1U)
#define MRAMC_PC_RDBFEN_WIDTH                    (1U)
#define MRAMC_PC_RDBFEN(x)                       (((uint32_t)(((uint32_t)(x)) << MRAMC_PC_RDBFEN_SHIFT)) & MRAMC_PC_RDBFEN_MASK)

#define MRAMC_PC_RCPFEN_MASK                     (0x10U)
#define MRAMC_PC_RCPFEN_SHIFT                    (4U)
#define MRAMC_PC_RCPFEN_WIDTH                    (1U)
#define MRAMC_PC_RCPFEN(x)                       (((uint32_t)(((uint32_t)(x)) << MRAMC_PC_RCPFEN_SHIFT)) & MRAMC_PC_RCPFEN_MASK)

#define MRAMC_PC_RDPFEN_MASK                     (0x20U)
#define MRAMC_PC_RDPFEN_SHIFT                    (5U)
#define MRAMC_PC_RDPFEN_WIDTH                    (1U)
#define MRAMC_PC_RDPFEN(x)                       (((uint32_t)(((uint32_t)(x)) << MRAMC_PC_RDPFEN_SHIFT)) & MRAMC_PC_RDPFEN_MASK)

#define MRAMC_PC_IB_MASK                         (0x100U)
#define MRAMC_PC_IB_SHIFT                        (8U)
#define MRAMC_PC_IB_WIDTH                        (1U)
#define MRAMC_PC_IB(x)                           (((uint32_t)(((uint32_t)(x)) << MRAMC_PC_IB_SHIFT)) & MRAMC_PC_IB_MASK)

#define MRAMC_PC_WRBFEN_MASK                     (0x1000U)
#define MRAMC_PC_WRBFEN_SHIFT                    (12U)
#define MRAMC_PC_WRBFEN_WIDTH                    (1U)
#define MRAMC_PC_WRBFEN(x)                       (((uint32_t)(((uint32_t)(x)) << MRAMC_PC_WRBFEN_SHIFT)) & MRAMC_PC_WRBFEN_MASK)
/*! @} */

/*! @name P1_RIA_W0 - Port i Read ID Assignment Word j */
/*! @{ */

#define MRAMC_P1_RIA_W0_MASK_ID_MASK             (0xFFFFU)
#define MRAMC_P1_RIA_W0_MASK_ID_SHIFT            (0U)
#define MRAMC_P1_RIA_W0_MASK_ID_WIDTH            (16U)
#define MRAMC_P1_RIA_W0_MASK_ID(x)               (((uint32_t)(((uint32_t)(x)) << MRAMC_P1_RIA_W0_MASK_ID_SHIFT)) & MRAMC_P1_RIA_W0_MASK_ID_MASK)

#define MRAMC_P1_RIA_W0_NUM_ENTRIES_MASK         (0xF0000U)
#define MRAMC_P1_RIA_W0_NUM_ENTRIES_SHIFT        (16U)
#define MRAMC_P1_RIA_W0_NUM_ENTRIES_WIDTH        (4U)
#define MRAMC_P1_RIA_W0_NUM_ENTRIES(x)           (((uint32_t)(((uint32_t)(x)) << MRAMC_P1_RIA_W0_NUM_ENTRIES_SHIFT)) & MRAMC_P1_RIA_W0_NUM_ENTRIES_MASK)

#define MRAMC_P1_RIA_W0_ENABLE_MASK              (0x8000000U)
#define MRAMC_P1_RIA_W0_ENABLE_SHIFT             (27U)
#define MRAMC_P1_RIA_W0_ENABLE_WIDTH             (1U)
#define MRAMC_P1_RIA_W0_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << MRAMC_P1_RIA_W0_ENABLE_SHIFT)) & MRAMC_P1_RIA_W0_ENABLE_MASK)

#define MRAMC_P1_RIA_W0_LOCK_MASK                (0x80000000U)
#define MRAMC_P1_RIA_W0_LOCK_SHIFT               (31U)
#define MRAMC_P1_RIA_W0_LOCK_WIDTH               (1U)
#define MRAMC_P1_RIA_W0_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << MRAMC_P1_RIA_W0_LOCK_SHIFT)) & MRAMC_P1_RIA_W0_LOCK_MASK)
/*! @} */

/*! @name P1_RIA_W1 - Port i Read ID Assignment Word j */
/*! @{ */

#define MRAMC_P1_RIA_W1_MASK_ID_MASK             (0xFFFFU)
#define MRAMC_P1_RIA_W1_MASK_ID_SHIFT            (0U)
#define MRAMC_P1_RIA_W1_MASK_ID_WIDTH            (16U)
#define MRAMC_P1_RIA_W1_MASK_ID(x)               (((uint32_t)(((uint32_t)(x)) << MRAMC_P1_RIA_W1_MASK_ID_SHIFT)) & MRAMC_P1_RIA_W1_MASK_ID_MASK)

#define MRAMC_P1_RIA_W1_NUM_ENTRIES_MASK         (0xF0000U)
#define MRAMC_P1_RIA_W1_NUM_ENTRIES_SHIFT        (16U)
#define MRAMC_P1_RIA_W1_NUM_ENTRIES_WIDTH        (4U)
#define MRAMC_P1_RIA_W1_NUM_ENTRIES(x)           (((uint32_t)(((uint32_t)(x)) << MRAMC_P1_RIA_W1_NUM_ENTRIES_SHIFT)) & MRAMC_P1_RIA_W1_NUM_ENTRIES_MASK)

#define MRAMC_P1_RIA_W1_ENABLE_MASK              (0x8000000U)
#define MRAMC_P1_RIA_W1_ENABLE_SHIFT             (27U)
#define MRAMC_P1_RIA_W1_ENABLE_WIDTH             (1U)
#define MRAMC_P1_RIA_W1_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << MRAMC_P1_RIA_W1_ENABLE_SHIFT)) & MRAMC_P1_RIA_W1_ENABLE_MASK)

#define MRAMC_P1_RIA_W1_LOCK_MASK                (0x80000000U)
#define MRAMC_P1_RIA_W1_LOCK_SHIFT               (31U)
#define MRAMC_P1_RIA_W1_LOCK_WIDTH               (1U)
#define MRAMC_P1_RIA_W1_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << MRAMC_P1_RIA_W1_LOCK_SHIFT)) & MRAMC_P1_RIA_W1_LOCK_MASK)
/*! @} */

/*! @name P2_RIA_W0 - Port i Read ID Assignment Word j */
/*! @{ */

#define MRAMC_P2_RIA_W0_MASK_ID_MASK             (0xFFFFU)
#define MRAMC_P2_RIA_W0_MASK_ID_SHIFT            (0U)
#define MRAMC_P2_RIA_W0_MASK_ID_WIDTH            (16U)
#define MRAMC_P2_RIA_W0_MASK_ID(x)               (((uint32_t)(((uint32_t)(x)) << MRAMC_P2_RIA_W0_MASK_ID_SHIFT)) & MRAMC_P2_RIA_W0_MASK_ID_MASK)

#define MRAMC_P2_RIA_W0_NUM_ENTRIES_MASK         (0xF0000U)
#define MRAMC_P2_RIA_W0_NUM_ENTRIES_SHIFT        (16U)
#define MRAMC_P2_RIA_W0_NUM_ENTRIES_WIDTH        (4U)
#define MRAMC_P2_RIA_W0_NUM_ENTRIES(x)           (((uint32_t)(((uint32_t)(x)) << MRAMC_P2_RIA_W0_NUM_ENTRIES_SHIFT)) & MRAMC_P2_RIA_W0_NUM_ENTRIES_MASK)

#define MRAMC_P2_RIA_W0_ENABLE_MASK              (0x8000000U)
#define MRAMC_P2_RIA_W0_ENABLE_SHIFT             (27U)
#define MRAMC_P2_RIA_W0_ENABLE_WIDTH             (1U)
#define MRAMC_P2_RIA_W0_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << MRAMC_P2_RIA_W0_ENABLE_SHIFT)) & MRAMC_P2_RIA_W0_ENABLE_MASK)

#define MRAMC_P2_RIA_W0_LOCK_MASK                (0x80000000U)
#define MRAMC_P2_RIA_W0_LOCK_SHIFT               (31U)
#define MRAMC_P2_RIA_W0_LOCK_WIDTH               (1U)
#define MRAMC_P2_RIA_W0_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << MRAMC_P2_RIA_W0_LOCK_SHIFT)) & MRAMC_P2_RIA_W0_LOCK_MASK)
/*! @} */

/*! @name P2_RIA_W1 - Port i Read ID Assignment Word j */
/*! @{ */

#define MRAMC_P2_RIA_W1_MASK_ID_MASK             (0xFFFFU)
#define MRAMC_P2_RIA_W1_MASK_ID_SHIFT            (0U)
#define MRAMC_P2_RIA_W1_MASK_ID_WIDTH            (16U)
#define MRAMC_P2_RIA_W1_MASK_ID(x)               (((uint32_t)(((uint32_t)(x)) << MRAMC_P2_RIA_W1_MASK_ID_SHIFT)) & MRAMC_P2_RIA_W1_MASK_ID_MASK)

#define MRAMC_P2_RIA_W1_NUM_ENTRIES_MASK         (0xF0000U)
#define MRAMC_P2_RIA_W1_NUM_ENTRIES_SHIFT        (16U)
#define MRAMC_P2_RIA_W1_NUM_ENTRIES_WIDTH        (4U)
#define MRAMC_P2_RIA_W1_NUM_ENTRIES(x)           (((uint32_t)(((uint32_t)(x)) << MRAMC_P2_RIA_W1_NUM_ENTRIES_SHIFT)) & MRAMC_P2_RIA_W1_NUM_ENTRIES_MASK)

#define MRAMC_P2_RIA_W1_ENABLE_MASK              (0x8000000U)
#define MRAMC_P2_RIA_W1_ENABLE_SHIFT             (27U)
#define MRAMC_P2_RIA_W1_ENABLE_WIDTH             (1U)
#define MRAMC_P2_RIA_W1_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << MRAMC_P2_RIA_W1_ENABLE_SHIFT)) & MRAMC_P2_RIA_W1_ENABLE_MASK)

#define MRAMC_P2_RIA_W1_LOCK_MASK                (0x80000000U)
#define MRAMC_P2_RIA_W1_LOCK_SHIFT               (31U)
#define MRAMC_P2_RIA_W1_LOCK_WIDTH               (1U)
#define MRAMC_P2_RIA_W1_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << MRAMC_P2_RIA_W1_LOCK_SHIFT)) & MRAMC_P2_RIA_W1_LOCK_MASK)
/*! @} */

/*! @name P3_RIA_W0 - Port i Read ID Assignment Word j */
/*! @{ */

#define MRAMC_P3_RIA_W0_MASK_ID_MASK             (0xFFFFU)
#define MRAMC_P3_RIA_W0_MASK_ID_SHIFT            (0U)
#define MRAMC_P3_RIA_W0_MASK_ID_WIDTH            (16U)
#define MRAMC_P3_RIA_W0_MASK_ID(x)               (((uint32_t)(((uint32_t)(x)) << MRAMC_P3_RIA_W0_MASK_ID_SHIFT)) & MRAMC_P3_RIA_W0_MASK_ID_MASK)

#define MRAMC_P3_RIA_W0_NUM_ENTRIES_MASK         (0x70000U)
#define MRAMC_P3_RIA_W0_NUM_ENTRIES_SHIFT        (16U)
#define MRAMC_P3_RIA_W0_NUM_ENTRIES_WIDTH        (3U)
#define MRAMC_P3_RIA_W0_NUM_ENTRIES(x)           (((uint32_t)(((uint32_t)(x)) << MRAMC_P3_RIA_W0_NUM_ENTRIES_SHIFT)) & MRAMC_P3_RIA_W0_NUM_ENTRIES_MASK)

#define MRAMC_P3_RIA_W0_ENABLE_MASK              (0x8000000U)
#define MRAMC_P3_RIA_W0_ENABLE_SHIFT             (27U)
#define MRAMC_P3_RIA_W0_ENABLE_WIDTH             (1U)
#define MRAMC_P3_RIA_W0_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << MRAMC_P3_RIA_W0_ENABLE_SHIFT)) & MRAMC_P3_RIA_W0_ENABLE_MASK)

#define MRAMC_P3_RIA_W0_LOCK_MASK                (0x80000000U)
#define MRAMC_P3_RIA_W0_LOCK_SHIFT               (31U)
#define MRAMC_P3_RIA_W0_LOCK_WIDTH               (1U)
#define MRAMC_P3_RIA_W0_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << MRAMC_P3_RIA_W0_LOCK_SHIFT)) & MRAMC_P3_RIA_W0_LOCK_MASK)
/*! @} */

/*! @name LPLOCK - Large Partition Lock */
/*! @{ */

#define MRAMC_LPLOCK_LCK0_MASK                   (0x1U)
#define MRAMC_LPLOCK_LCK0_SHIFT                  (0U)
#define MRAMC_LPLOCK_LCK0_WIDTH                  (1U)
#define MRAMC_LPLOCK_LCK0(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_LPLOCK_LCK0_SHIFT)) & MRAMC_LPLOCK_LCK0_MASK)

#define MRAMC_LPLOCK_LCK1_MASK                   (0x2U)
#define MRAMC_LPLOCK_LCK1_SHIFT                  (1U)
#define MRAMC_LPLOCK_LCK1_WIDTH                  (1U)
#define MRAMC_LPLOCK_LCK1(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_LPLOCK_LCK1_SHIFT)) & MRAMC_LPLOCK_LCK1_MASK)

#define MRAMC_LPLOCK_LCK2_MASK                   (0x4U)
#define MRAMC_LPLOCK_LCK2_SHIFT                  (2U)
#define MRAMC_LPLOCK_LCK2_WIDTH                  (1U)
#define MRAMC_LPLOCK_LCK2(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_LPLOCK_LCK2_SHIFT)) & MRAMC_LPLOCK_LCK2_MASK)

#define MRAMC_LPLOCK_LCK3_MASK                   (0x8U)
#define MRAMC_LPLOCK_LCK3_SHIFT                  (3U)
#define MRAMC_LPLOCK_LCK3_WIDTH                  (1U)
#define MRAMC_LPLOCK_LCK3(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_LPLOCK_LCK3_SHIFT)) & MRAMC_LPLOCK_LCK3_MASK)

#define MRAMC_LPLOCK_LCK4_MASK                   (0x10U)
#define MRAMC_LPLOCK_LCK4_SHIFT                  (4U)
#define MRAMC_LPLOCK_LCK4_WIDTH                  (1U)
#define MRAMC_LPLOCK_LCK4(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_LPLOCK_LCK4_SHIFT)) & MRAMC_LPLOCK_LCK4_MASK)

#define MRAMC_LPLOCK_LCK5_MASK                   (0x20U)
#define MRAMC_LPLOCK_LCK5_SHIFT                  (5U)
#define MRAMC_LPLOCK_LCK5_WIDTH                  (1U)
#define MRAMC_LPLOCK_LCK5(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_LPLOCK_LCK5_SHIFT)) & MRAMC_LPLOCK_LCK5_MASK)

#define MRAMC_LPLOCK_LCK6_MASK                   (0x40U)
#define MRAMC_LPLOCK_LCK6_SHIFT                  (6U)
#define MRAMC_LPLOCK_LCK6_WIDTH                  (1U)
#define MRAMC_LPLOCK_LCK6(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_LPLOCK_LCK6_SHIFT)) & MRAMC_LPLOCK_LCK6_MASK)

#define MRAMC_LPLOCK_LCK7_MASK                   (0x80U)
#define MRAMC_LPLOCK_LCK7_SHIFT                  (7U)
#define MRAMC_LPLOCK_LCK7_WIDTH                  (1U)
#define MRAMC_LPLOCK_LCK7(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_LPLOCK_LCK7_SHIFT)) & MRAMC_LPLOCK_LCK7_MASK)
/*! @} */

/*! @name SPLOCK - Small Partition Lock */
/*! @{ */

#define MRAMC_SPLOCK_LCK_MASK                    (0x1U)
#define MRAMC_SPLOCK_LCK_SHIFT                   (0U)
#define MRAMC_SPLOCK_LCK_WIDTH                   (1U)
#define MRAMC_SPLOCK_LCK(x)                      (((uint32_t)(((uint32_t)(x)) << MRAMC_SPLOCK_LCK_SHIFT)) & MRAMC_SPLOCK_LCK_MASK)
/*! @} */

/*! @name LPOLOCK - Large Partition OTP Lock */
/*! @{ */

#define MRAMC_LPOLOCK_LCK_MASK                   (0x1U)
#define MRAMC_LPOLOCK_LCK_SHIFT                  (0U)
#define MRAMC_LPOLOCK_LCK_WIDTH                  (1U)
#define MRAMC_LPOLOCK_LCK(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_LPOLOCK_LCK_SHIFT)) & MRAMC_LPOLOCK_LCK_MASK)
/*! @} */

/*! @name UTLOCK - UTest Lock */
/*! @{ */

#define MRAMC_UTLOCK_LCK_MASK                    (0x1U)
#define MRAMC_UTLOCK_LCK_SHIFT                   (0U)
#define MRAMC_UTLOCK_LCK_WIDTH                   (1U)
#define MRAMC_UTLOCK_LCK(x)                      (((uint32_t)(((uint32_t)(x)) << MRAMC_UTLOCK_LCK_SHIFT)) & MRAMC_UTLOCK_LCK_MASK)
/*! @} */

/*! @name PLPLOCK - Protect Large Partition Lock */
/*! @{ */

#define MRAMC_PLPLOCK_PLCK0_MASK                 (0x3U)
#define MRAMC_PLPLOCK_PLCK0_SHIFT                (0U)
#define MRAMC_PLPLOCK_PLCK0_WIDTH                (2U)
#define MRAMC_PLPLOCK_PLCK0(x)                   (((uint32_t)(((uint32_t)(x)) << MRAMC_PLPLOCK_PLCK0_SHIFT)) & MRAMC_PLPLOCK_PLCK0_MASK)

#define MRAMC_PLPLOCK_PLCK1_MASK                 (0xCU)
#define MRAMC_PLPLOCK_PLCK1_SHIFT                (2U)
#define MRAMC_PLPLOCK_PLCK1_WIDTH                (2U)
#define MRAMC_PLPLOCK_PLCK1(x)                   (((uint32_t)(((uint32_t)(x)) << MRAMC_PLPLOCK_PLCK1_SHIFT)) & MRAMC_PLPLOCK_PLCK1_MASK)

#define MRAMC_PLPLOCK_PLCK2_MASK                 (0x30U)
#define MRAMC_PLPLOCK_PLCK2_SHIFT                (4U)
#define MRAMC_PLPLOCK_PLCK2_WIDTH                (2U)
#define MRAMC_PLPLOCK_PLCK2(x)                   (((uint32_t)(((uint32_t)(x)) << MRAMC_PLPLOCK_PLCK2_SHIFT)) & MRAMC_PLPLOCK_PLCK2_MASK)

#define MRAMC_PLPLOCK_PLCK3_MASK                 (0xC0U)
#define MRAMC_PLPLOCK_PLCK3_SHIFT                (6U)
#define MRAMC_PLPLOCK_PLCK3_WIDTH                (2U)
#define MRAMC_PLPLOCK_PLCK3(x)                   (((uint32_t)(((uint32_t)(x)) << MRAMC_PLPLOCK_PLCK3_SHIFT)) & MRAMC_PLPLOCK_PLCK3_MASK)

#define MRAMC_PLPLOCK_PLCK4_MASK                 (0x300U)
#define MRAMC_PLPLOCK_PLCK4_SHIFT                (8U)
#define MRAMC_PLPLOCK_PLCK4_WIDTH                (2U)
#define MRAMC_PLPLOCK_PLCK4(x)                   (((uint32_t)(((uint32_t)(x)) << MRAMC_PLPLOCK_PLCK4_SHIFT)) & MRAMC_PLPLOCK_PLCK4_MASK)

#define MRAMC_PLPLOCK_PLCK5_MASK                 (0xC00U)
#define MRAMC_PLPLOCK_PLCK5_SHIFT                (10U)
#define MRAMC_PLPLOCK_PLCK5_WIDTH                (2U)
#define MRAMC_PLPLOCK_PLCK5(x)                   (((uint32_t)(((uint32_t)(x)) << MRAMC_PLPLOCK_PLCK5_SHIFT)) & MRAMC_PLPLOCK_PLCK5_MASK)

#define MRAMC_PLPLOCK_PLCK6_MASK                 (0x3000U)
#define MRAMC_PLPLOCK_PLCK6_SHIFT                (12U)
#define MRAMC_PLPLOCK_PLCK6_WIDTH                (2U)
#define MRAMC_PLPLOCK_PLCK6(x)                   (((uint32_t)(((uint32_t)(x)) << MRAMC_PLPLOCK_PLCK6_SHIFT)) & MRAMC_PLPLOCK_PLCK6_MASK)

#define MRAMC_PLPLOCK_PLCK7_MASK                 (0xC000U)
#define MRAMC_PLPLOCK_PLCK7_SHIFT                (14U)
#define MRAMC_PLPLOCK_PLCK7_WIDTH                (2U)
#define MRAMC_PLPLOCK_PLCK7(x)                   (((uint32_t)(((uint32_t)(x)) << MRAMC_PLPLOCK_PLCK7_SHIFT)) & MRAMC_PLPLOCK_PLCK7_MASK)
/*! @} */

/*! @name PSPLOCK - Protect Small Partition Lock */
/*! @{ */

#define MRAMC_PSPLOCK_PLCK_MASK                  (0x3U)
#define MRAMC_PSPLOCK_PLCK_SHIFT                 (0U)
#define MRAMC_PSPLOCK_PLCK_WIDTH                 (2U)
#define MRAMC_PSPLOCK_PLCK(x)                    (((uint32_t)(((uint32_t)(x)) << MRAMC_PSPLOCK_PLCK_SHIFT)) & MRAMC_PSPLOCK_PLCK_MASK)
/*! @} */

/*! @name PLPOLOCK - Protect Large Partition OTP Lock */
/*! @{ */

#define MRAMC_PLPOLOCK_PLCK_MASK                 (0x3U)
#define MRAMC_PLPOLOCK_PLCK_SHIFT                (0U)
#define MRAMC_PLPOLOCK_PLCK_WIDTH                (2U)
#define MRAMC_PLPOLOCK_PLCK(x)                   (((uint32_t)(((uint32_t)(x)) << MRAMC_PLPOLOCK_PLCK_SHIFT)) & MRAMC_PLPOLOCK_PLCK_MASK)
/*! @} */

/*! @name PUTLOCK - Protect UTest Lock */
/*! @{ */

#define MRAMC_PUTLOCK_PLCK_MASK                  (0x3U)
#define MRAMC_PUTLOCK_PLCK_SHIFT                 (0U)
#define MRAMC_PUTLOCK_PLCK_WIDTH                 (2U)
#define MRAMC_PUTLOCK_PLCK(x)                    (((uint32_t)(((uint32_t)(x)) << MRAMC_PUTLOCK_PLCK_SHIFT)) & MRAMC_PUTLOCK_PLCK_MASK)
/*! @} */

/*! @name LPLOCKOW - Large Partition Lock Owner */
/*! @{ */

#define MRAMC_LPLOCKOW_LOCKOWNER_MASK            (0x1FU)
#define MRAMC_LPLOCKOW_LOCKOWNER_SHIFT           (0U)
#define MRAMC_LPLOCKOW_LOCKOWNER_WIDTH           (5U)
#define MRAMC_LPLOCKOW_LOCKOWNER(x)              (((uint32_t)(((uint32_t)(x)) << MRAMC_LPLOCKOW_LOCKOWNER_SHIFT)) & MRAMC_LPLOCKOW_LOCKOWNER_MASK)
/*! @} */

/*! @name LOCKOW - Small partition Lock Owner..UTest Lock Owner */
/*! @{ */

#define MRAMC_LOCKOW_LOCKOWNER_MASK              (0x1FU)
#define MRAMC_LOCKOW_LOCKOWNER_SHIFT             (0U)
#define MRAMC_LOCKOW_LOCKOWNER_WIDTH             (5U)
#define MRAMC_LOCKOW_LOCKOWNER(x)                (((uint32_t)(((uint32_t)(x)) << MRAMC_LOCKOW_LOCKOWNER_SHIFT)) & MRAMC_LOCKOW_LOCKOWNER_MASK)
/*! @} */

/*! @name ERRINJCTL - Error Injection Control */
/*! @{ */

#define MRAMC_ERRINJCTL_IRE_MASK                 (0x1U)
#define MRAMC_ERRINJCTL_IRE_SHIFT                (0U)
#define MRAMC_ERRINJCTL_IRE_WIDTH                (1U)
#define MRAMC_ERRINJCTL_IRE(x)                   (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRINJCTL_IRE_SHIFT)) & MRAMC_ERRINJCTL_IRE_MASK)

#define MRAMC_ERRINJCTL_IWE_MASK                 (0x2U)
#define MRAMC_ERRINJCTL_IWE_SHIFT                (1U)
#define MRAMC_ERRINJCTL_IWE_WIDTH                (1U)
#define MRAMC_ERRINJCTL_IWE(x)                   (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRINJCTL_IWE_SHIFT)) & MRAMC_ERRINJCTL_IWE_MASK)

#define MRAMC_ERRINJCTL_ICPE_MASK                (0x8U)
#define MRAMC_ERRINJCTL_ICPE_SHIFT               (3U)
#define MRAMC_ERRINJCTL_ICPE_WIDTH               (1U)
#define MRAMC_ERRINJCTL_ICPE(x)                  (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRINJCTL_ICPE_SHIFT)) & MRAMC_ERRINJCTL_ICPE_MASK)

#define MRAMC_ERRINJCTL_ICEE_MASK                (0x10U)
#define MRAMC_ERRINJCTL_ICEE_SHIFT               (4U)
#define MRAMC_ERRINJCTL_ICEE_WIDTH               (1U)
#define MRAMC_ERRINJCTL_ICEE(x)                  (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRINJCTL_ICEE_SHIFT)) & MRAMC_ERRINJCTL_ICEE_MASK)

#define MRAMC_ERRINJCTL_IDEE_MASK                (0x20U)
#define MRAMC_ERRINJCTL_IDEE_SHIFT               (5U)
#define MRAMC_ERRINJCTL_IDEE_WIDTH               (1U)
#define MRAMC_ERRINJCTL_IDEE(x)                  (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRINJCTL_IDEE_SHIFT)) & MRAMC_ERRINJCTL_IDEE_MASK)

#define MRAMC_ERRINJCTL_IADEE_MASK               (0x40U)
#define MRAMC_ERRINJCTL_IADEE_SHIFT              (6U)
#define MRAMC_ERRINJCTL_IADEE_WIDTH              (1U)
#define MRAMC_ERRINJCTL_IADEE(x)                 (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRINJCTL_IADEE_SHIFT)) & MRAMC_ERRINJCTL_IADEE_MASK)

#define MRAMC_ERRINJCTL_IMDEE_MASK               (0x100U)
#define MRAMC_ERRINJCTL_IMDEE_SHIFT              (8U)
#define MRAMC_ERRINJCTL_IMDEE_WIDTH              (1U)
#define MRAMC_ERRINJCTL_IMDEE(x)                 (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRINJCTL_IMDEE_SHIFT)) & MRAMC_ERRINJCTL_IMDEE_MASK)

#define MRAMC_ERRINJCTL_MOD_ID_MASK              (0x7000000U)
#define MRAMC_ERRINJCTL_MOD_ID_SHIFT             (24U)
#define MRAMC_ERRINJCTL_MOD_ID_WIDTH             (3U)
#define MRAMC_ERRINJCTL_MOD_ID(x)                (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRINJCTL_MOD_ID_SHIFT)) & MRAMC_ERRINJCTL_MOD_ID_MASK)

#define MRAMC_ERRINJCTL_EIE_MASK                 (0x80000000U)
#define MRAMC_ERRINJCTL_EIE_SHIFT                (31U)
#define MRAMC_ERRINJCTL_EIE_WIDTH                (1U)
#define MRAMC_ERRINJCTL_EIE(x)                   (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRINJCTL_EIE_SHIFT)) & MRAMC_ERRINJCTL_EIE_MASK)
/*! @} */

/*! @name ERRSTAT0 - Error Status 0 */
/*! @{ */

#define MRAMC_ERRSTAT0_RE_MASK                   (0x1U)
#define MRAMC_ERRSTAT0_RE_SHIFT                  (0U)
#define MRAMC_ERRSTAT0_RE_WIDTH                  (1U)
#define MRAMC_ERRSTAT0_RE(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRSTAT0_RE_SHIFT)) & MRAMC_ERRSTAT0_RE_MASK)

#define MRAMC_ERRSTAT0_WE_MASK                   (0x2U)
#define MRAMC_ERRSTAT0_WE_SHIFT                  (1U)
#define MRAMC_ERRSTAT0_WE_WIDTH                  (1U)
#define MRAMC_ERRSTAT0_WE(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRSTAT0_WE_SHIFT)) & MRAMC_ERRSTAT0_WE_MASK)

#define MRAMC_ERRSTAT0_PWE_MASK                  (0x4U)
#define MRAMC_ERRSTAT0_PWE_SHIFT                 (2U)
#define MRAMC_ERRSTAT0_PWE_WIDTH                 (1U)
#define MRAMC_ERRSTAT0_PWE(x)                    (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRSTAT0_PWE_SHIFT)) & MRAMC_ERRSTAT0_PWE_MASK)

#define MRAMC_ERRSTAT0_CPE_MASK                  (0x8U)
#define MRAMC_ERRSTAT0_CPE_SHIFT                 (3U)
#define MRAMC_ERRSTAT0_CPE_WIDTH                 (1U)
#define MRAMC_ERRSTAT0_CPE(x)                    (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRSTAT0_CPE_SHIFT)) & MRAMC_ERRSTAT0_CPE_MASK)

#define MRAMC_ERRSTAT0_CEE_MASK                  (0x10U)
#define MRAMC_ERRSTAT0_CEE_SHIFT                 (4U)
#define MRAMC_ERRSTAT0_CEE_WIDTH                 (1U)
#define MRAMC_ERRSTAT0_CEE(x)                    (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRSTAT0_CEE_SHIFT)) & MRAMC_ERRSTAT0_CEE_MASK)

#define MRAMC_ERRSTAT0_DEE_MASK                  (0x20U)
#define MRAMC_ERRSTAT0_DEE_SHIFT                 (5U)
#define MRAMC_ERRSTAT0_DEE_WIDTH                 (1U)
#define MRAMC_ERRSTAT0_DEE(x)                    (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRSTAT0_DEE_SHIFT)) & MRAMC_ERRSTAT0_DEE_MASK)

#define MRAMC_ERRSTAT0_MCE_MASK                  (0x40U)
#define MRAMC_ERRSTAT0_MCE_SHIFT                 (6U)
#define MRAMC_ERRSTAT0_MCE_WIDTH                 (1U)
#define MRAMC_ERRSTAT0_MCE(x)                    (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRSTAT0_MCE_SHIFT)) & MRAMC_ERRSTAT0_MCE_MASK)

#define MRAMC_ERRSTAT0_ME_MASK                   (0x80U)
#define MRAMC_ERRSTAT0_ME_SHIFT                  (7U)
#define MRAMC_ERRSTAT0_ME_WIDTH                  (1U)
#define MRAMC_ERRSTAT0_ME(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRSTAT0_ME_SHIFT)) & MRAMC_ERRSTAT0_ME_MASK)

#define MRAMC_ERRSTAT0_MEEE_MASK                 (0x10000U)
#define MRAMC_ERRSTAT0_MEEE_SHIFT                (16U)
#define MRAMC_ERRSTAT0_MEEE_WIDTH                (1U)
#define MRAMC_ERRSTAT0_MEEE(x)                   (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRSTAT0_MEEE_SHIFT)) & MRAMC_ERRSTAT0_MEEE_MASK)

#define MRAMC_ERRSTAT0_UE_MASK                   (0x20000U)
#define MRAMC_ERRSTAT0_UE_SHIFT                  (17U)
#define MRAMC_ERRSTAT0_UE_WIDTH                  (1U)
#define MRAMC_ERRSTAT0_UE(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRSTAT0_UE_SHIFT)) & MRAMC_ERRSTAT0_UE_MASK)
/*! @} */

/*! @name ERRSTAT1 - Error Status 1 */
/*! @{ */

#define MRAMC_ERRSTAT1_ADDR_MASK                 (0xFFFFFFFFU)
#define MRAMC_ERRSTAT1_ADDR_SHIFT                (0U)
#define MRAMC_ERRSTAT1_ADDR_WIDTH                (32U)
#define MRAMC_ERRSTAT1_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRSTAT1_ADDR_SHIFT)) & MRAMC_ERRSTAT1_ADDR_MASK)
/*! @} */

/*! @name ERRNTCTL0 - Error Notification Control 0 */
/*! @{ */

#define MRAMC_ERRNTCTL0_PWENE_MASK               (0x4U)
#define MRAMC_ERRNTCTL0_PWENE_SHIFT              (2U)
#define MRAMC_ERRNTCTL0_PWENE_WIDTH              (1U)
#define MRAMC_ERRNTCTL0_PWENE(x)                 (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRNTCTL0_PWENE_SHIFT)) & MRAMC_ERRNTCTL0_PWENE_MASK)

#define MRAMC_ERRNTCTL0_CPENE_MASK               (0x8U)
#define MRAMC_ERRNTCTL0_CPENE_SHIFT              (3U)
#define MRAMC_ERRNTCTL0_CPENE_WIDTH              (1U)
#define MRAMC_ERRNTCTL0_CPENE(x)                 (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRNTCTL0_CPENE_SHIFT)) & MRAMC_ERRNTCTL0_CPENE_MASK)

#define MRAMC_ERRNTCTL0_CEENE_MASK               (0x10U)
#define MRAMC_ERRNTCTL0_CEENE_SHIFT              (4U)
#define MRAMC_ERRNTCTL0_CEENE_WIDTH              (1U)
#define MRAMC_ERRNTCTL0_CEENE(x)                 (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRNTCTL0_CEENE_SHIFT)) & MRAMC_ERRNTCTL0_CEENE_MASK)

#define MRAMC_ERRNTCTL0_DEENE_MASK               (0x20U)
#define MRAMC_ERRNTCTL0_DEENE_SHIFT              (5U)
#define MRAMC_ERRNTCTL0_DEENE_WIDTH              (1U)
#define MRAMC_ERRNTCTL0_DEENE(x)                 (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRNTCTL0_DEENE_SHIFT)) & MRAMC_ERRNTCTL0_DEENE_MASK)

#define MRAMC_ERRNTCTL0_MCENE_MASK               (0x40U)
#define MRAMC_ERRNTCTL0_MCENE_SHIFT              (6U)
#define MRAMC_ERRNTCTL0_MCENE_WIDTH              (1U)
#define MRAMC_ERRNTCTL0_MCENE(x)                 (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRNTCTL0_MCENE_SHIFT)) & MRAMC_ERRNTCTL0_MCENE_MASK)

#define MRAMC_ERRNTCTL0_MENE_MASK                (0x80U)
#define MRAMC_ERRNTCTL0_MENE_SHIFT               (7U)
#define MRAMC_ERRNTCTL0_MENE_WIDTH               (1U)
#define MRAMC_ERRNTCTL0_MENE(x)                  (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRNTCTL0_MENE_SHIFT)) & MRAMC_ERRNTCTL0_MENE_MASK)

#define MRAMC_ERRNTCTL0_Reserved_MASK            (0x100U)
#define MRAMC_ERRNTCTL0_Reserved_SHIFT           (8U)
#define MRAMC_ERRNTCTL0_Reserved_WIDTH           (1U)
#define MRAMC_ERRNTCTL0_Reserved(x)              (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRNTCTL0_Reserved_SHIFT)) & MRAMC_ERRNTCTL0_Reserved_MASK)

#define MRAMC_ERRNTCTL0_MEEENE_MASK              (0x10000U)
#define MRAMC_ERRNTCTL0_MEEENE_SHIFT             (16U)
#define MRAMC_ERRNTCTL0_MEEENE_WIDTH             (1U)
#define MRAMC_ERRNTCTL0_MEEENE(x)                (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRNTCTL0_MEEENE_SHIFT)) & MRAMC_ERRNTCTL0_MEEENE_MASK)

#define MRAMC_ERRNTCTL0_UENE_MASK                (0x20000U)
#define MRAMC_ERRNTCTL0_UENE_SHIFT               (17U)
#define MRAMC_ERRNTCTL0_UENE_WIDTH               (1U)
#define MRAMC_ERRNTCTL0_UENE(x)                  (((uint32_t)(((uint32_t)(x)) << MRAMC_ERRNTCTL0_UENE_SHIFT)) & MRAMC_ERRNTCTL0_UENE_MASK)
/*! @} */

/*! @name WWDOG - Write Watchdog */
/*! @{ */

#define MRAMC_WWDOG_WDD_MASK                     (0x8000000U)
#define MRAMC_WWDOG_WDD_SHIFT                    (27U)
#define MRAMC_WWDOG_WDD_WIDTH                    (1U)
#define MRAMC_WWDOG_WDD(x)                       (((uint32_t)(((uint32_t)(x)) << MRAMC_WWDOG_WDD_SHIFT)) & MRAMC_WWDOG_WDD_MASK)

#define MRAMC_WWDOG_WDT_MASK                     (0x30000000U)
#define MRAMC_WWDOG_WDT_SHIFT                    (28U)
#define MRAMC_WWDOG_WDT_WIDTH                    (2U)
#define MRAMC_WWDOG_WDT(x)                       (((uint32_t)(((uint32_t)(x)) << MRAMC_WWDOG_WDT_SHIFT)) & MRAMC_WWDOG_WDT_MASK)

#define MRAMC_WWDOG_WDL_MASK                     (0x80000000U)
#define MRAMC_WWDOG_WDL_SHIFT                    (31U)
#define MRAMC_WWDOG_WDL_WIDTH                    (1U)
#define MRAMC_WWDOG_WDL(x)                       (((uint32_t)(((uint32_t)(x)) << MRAMC_WWDOG_WDL_SHIFT)) & MRAMC_WWDOG_WDL_MASK)
/*! @} */

/*! @name WDATA_PAGE_WORD - Write Data */
/*! @{ */

#define MRAMC_WDATA_PAGE_WORD_WDATA_MASK         (0xFFFFFFFFU)
#define MRAMC_WDATA_PAGE_WORD_WDATA_SHIFT        (0U)
#define MRAMC_WDATA_PAGE_WORD_WDATA_WIDTH        (32U)
#define MRAMC_WDATA_PAGE_WORD_WDATA(x)           (((uint32_t)(((uint32_t)(x)) << MRAMC_WDATA_PAGE_WORD_WDATA_SHIFT)) & MRAMC_WDATA_PAGE_WORD_WDATA_MASK)
/*! @} */

/*! @name WSTRB_PAGE - Write Strobe */
/*! @{ */

#define MRAMC_WSTRB_PAGE_WSTRB0_MASK             (0xFU)
#define MRAMC_WSTRB_PAGE_WSTRB0_SHIFT            (0U)
#define MRAMC_WSTRB_PAGE_WSTRB0_WIDTH            (4U)
#define MRAMC_WSTRB_PAGE_WSTRB0(x)               (((uint32_t)(((uint32_t)(x)) << MRAMC_WSTRB_PAGE_WSTRB0_SHIFT)) & MRAMC_WSTRB_PAGE_WSTRB0_MASK)

#define MRAMC_WSTRB_PAGE_WSTRB1_MASK             (0xF0U)
#define MRAMC_WSTRB_PAGE_WSTRB1_SHIFT            (4U)
#define MRAMC_WSTRB_PAGE_WSTRB1_WIDTH            (4U)
#define MRAMC_WSTRB_PAGE_WSTRB1(x)               (((uint32_t)(((uint32_t)(x)) << MRAMC_WSTRB_PAGE_WSTRB1_SHIFT)) & MRAMC_WSTRB_PAGE_WSTRB1_MASK)

#define MRAMC_WSTRB_PAGE_WSTRB2_MASK             (0xF00U)
#define MRAMC_WSTRB_PAGE_WSTRB2_SHIFT            (8U)
#define MRAMC_WSTRB_PAGE_WSTRB2_WIDTH            (4U)
#define MRAMC_WSTRB_PAGE_WSTRB2(x)               (((uint32_t)(((uint32_t)(x)) << MRAMC_WSTRB_PAGE_WSTRB2_SHIFT)) & MRAMC_WSTRB_PAGE_WSTRB2_MASK)

#define MRAMC_WSTRB_PAGE_WSTRB3_MASK             (0xF000U)
#define MRAMC_WSTRB_PAGE_WSTRB3_SHIFT            (12U)
#define MRAMC_WSTRB_PAGE_WSTRB3_WIDTH            (4U)
#define MRAMC_WSTRB_PAGE_WSTRB3(x)               (((uint32_t)(((uint32_t)(x)) << MRAMC_WSTRB_PAGE_WSTRB3_SHIFT)) & MRAMC_WSTRB_PAGE_WSTRB3_MASK)

#define MRAMC_WSTRB_PAGE_WSTRB4_MASK             (0xF0000U)
#define MRAMC_WSTRB_PAGE_WSTRB4_SHIFT            (16U)
#define MRAMC_WSTRB_PAGE_WSTRB4_WIDTH            (4U)
#define MRAMC_WSTRB_PAGE_WSTRB4(x)               (((uint32_t)(((uint32_t)(x)) << MRAMC_WSTRB_PAGE_WSTRB4_SHIFT)) & MRAMC_WSTRB_PAGE_WSTRB4_MASK)

#define MRAMC_WSTRB_PAGE_WSTRB5_MASK             (0xF00000U)
#define MRAMC_WSTRB_PAGE_WSTRB5_SHIFT            (20U)
#define MRAMC_WSTRB_PAGE_WSTRB5_WIDTH            (4U)
#define MRAMC_WSTRB_PAGE_WSTRB5(x)               (((uint32_t)(((uint32_t)(x)) << MRAMC_WSTRB_PAGE_WSTRB5_SHIFT)) & MRAMC_WSTRB_PAGE_WSTRB5_MASK)

#define MRAMC_WSTRB_PAGE_WSTRB6_MASK             (0xF000000U)
#define MRAMC_WSTRB_PAGE_WSTRB6_SHIFT            (24U)
#define MRAMC_WSTRB_PAGE_WSTRB6_WIDTH            (4U)
#define MRAMC_WSTRB_PAGE_WSTRB6(x)               (((uint32_t)(((uint32_t)(x)) << MRAMC_WSTRB_PAGE_WSTRB6_SHIFT)) & MRAMC_WSTRB_PAGE_WSTRB6_MASK)

#define MRAMC_WSTRB_PAGE_WSTRB7_MASK             (0xF0000000U)
#define MRAMC_WSTRB_PAGE_WSTRB7_SHIFT            (28U)
#define MRAMC_WSTRB_PAGE_WSTRB7_WIDTH            (4U)
#define MRAMC_WSTRB_PAGE_WSTRB7(x)               (((uint32_t)(((uint32_t)(x)) << MRAMC_WSTRB_PAGE_WSTRB7_SHIFT)) & MRAMC_WSTRB_PAGE_WSTRB7_MASK)
/*! @} */

/*! @name WADDR - Write Address */
/*! @{ */

#define MRAMC_WADDR_WADDR_MASK                   (0xFFFFFFE0U)
#define MRAMC_WADDR_WADDR_SHIFT                  (5U)
#define MRAMC_WADDR_WADDR_WIDTH                  (27U)
#define MRAMC_WADDR_WADDR(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_WADDR_WADDR_SHIFT)) & MRAMC_WADDR_WADDR_MASK)
/*! @} */

/*! @name WCTL - Write Control */
/*! @{ */

#define MRAMC_WCTL_SMW_MASK                      (0x1U)
#define MRAMC_WCTL_SMW_SHIFT                     (0U)
#define MRAMC_WCTL_SMW_WIDTH                     (1U)
#define MRAMC_WCTL_SMW(x)                        (((uint32_t)(((uint32_t)(x)) << MRAMC_WCTL_SMW_SHIFT)) & MRAMC_WCTL_SMW_MASK)

#define MRAMC_WCTL_CWSL_MASK                     (0x2U)
#define MRAMC_WCTL_CWSL_SHIFT                    (1U)
#define MRAMC_WCTL_CWSL_WIDTH                    (1U)
#define MRAMC_WCTL_CWSL(x)                       (((uint32_t)(((uint32_t)(x)) << MRAMC_WCTL_CWSL_SHIFT)) & MRAMC_WCTL_CWSL_MASK)

#define MRAMC_WCTL_NUM_WP_MASK                   (0xF0000U)
#define MRAMC_WCTL_NUM_WP_SHIFT                  (16U)
#define MRAMC_WCTL_NUM_WP_WIDTH                  (4U)
#define MRAMC_WCTL_NUM_WP(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_WCTL_NUM_WP_SHIFT)) & MRAMC_WCTL_NUM_WP_MASK)

#define MRAMC_WCTL_WDCLR_MASK                    (0x1000000U)
#define MRAMC_WCTL_WDCLR_SHIFT                   (24U)
#define MRAMC_WCTL_WDCLR_WIDTH                   (1U)
#define MRAMC_WCTL_WDCLR(x)                      (((uint32_t)(((uint32_t)(x)) << MRAMC_WCTL_WDCLR_SHIFT)) & MRAMC_WCTL_WDCLR_MASK)
/*! @} */

/*! @name WSTAT - Write Status */
/*! @{ */

#define MRAMC_WSTAT_WBUSY_MASK                   (0x1U)
#define MRAMC_WSTAT_WBUSY_SHIFT                  (0U)
#define MRAMC_WSTAT_WBUSY_WIDTH                  (1U)
#define MRAMC_WSTAT_WBUSY(x)                     (((uint32_t)(((uint32_t)(x)) << MRAMC_WSTAT_WBUSY_SHIFT)) & MRAMC_WSTAT_WBUSY_MASK)

#define MRAMC_WSTAT_WERR_MASK                    (0x2U)
#define MRAMC_WSTAT_WERR_SHIFT                   (1U)
#define MRAMC_WSTAT_WERR_WIDTH                   (1U)
#define MRAMC_WSTAT_WERR(x)                      (((uint32_t)(((uint32_t)(x)) << MRAMC_WSTAT_WERR_SHIFT)) & MRAMC_WSTAT_WERR_MASK)

#define MRAMC_WSTAT_WDTE_MASK                    (0x4U)
#define MRAMC_WSTAT_WDTE_SHIFT                   (2U)
#define MRAMC_WSTAT_WDTE_WIDTH                   (1U)
#define MRAMC_WSTAT_WDTE(x)                      (((uint32_t)(((uint32_t)(x)) << MRAMC_WSTAT_WDTE_SHIFT)) & MRAMC_WSTAT_WDTE_MASK)

#define MRAMC_WSTAT_WID_MASK                     (0x1F0000U)
#define MRAMC_WSTAT_WID_SHIFT                    (16U)
#define MRAMC_WSTAT_WID_WIDTH                    (5U)
#define MRAMC_WSTAT_WID(x)                       (((uint32_t)(((uint32_t)(x)) << MRAMC_WSTAT_WID_SHIFT)) & MRAMC_WSTAT_WID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MRAMC_Register_Masks */

/*!
 * @}
 */ /* end of group MRAMC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_MRAMC_H_) */
