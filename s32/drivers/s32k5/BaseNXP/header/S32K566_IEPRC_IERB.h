/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_ieprc_ierb.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_ieprc_ierb
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
#if !defined(S32K566_ieprc_ierb_H_)  /* Check if memory map has not been already included */
#define S32K566_ieprc_ierb_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ieprc_ierb Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ieprc_ierb_Peripheral_Access_Layer ieprc_ierb Peripheral Access Layer
 * @{
 */

/** ieprc_ierb - Size of Registers Arrays */
#define ieprc_ierb_BUSX_COUNT                     2u

/** ieprc_ierb - Register Layout Typedef */
typedef struct ieprc_ierb_Struct {
  struct ieprc_ierb_BUSX {                         /* offset: 0x0, array step: 0x20 */
    __IO uint32_t B_EC_F0_CFH_DIDVID;                /**< Bus n EC Function 0 config header device ID and vendor ID register, array offset: 0x0, array step: 0x20 */
    __IO uint32_t B_EC_F0_CFH_SIDSVID;               /**< Bus n EC Function 0 config header subsystem ID and subsystem vendor ID register, array offset: 0x4, array step: 0x20 */
    __IO uint32_t B_EC_F0_CFH_REVID;                 /**< Bus n EC Function 0 config header revision register, array offset: 0x8, array step: 0x20 */
    uint8_t RESERVED_0[20];
  } BUSX[ieprc_ierb_BUSX_COUNT];
  uint8_t RESERVED_0[8128];
  __I  uint32_t CAP0;                              /**< Capability 0 register, offset: 0x2000 */
  uint8_t RESERVED_1[12];
  __IO uint32_t EC_CFG;                            /**< EC Configuration register, offset: 0x2010 */
} ieprc_ierb_Type, *ieprc_ierb_MemMapPtr;

/** Number of instances of the ieprc_ierb module. */
#define ieprc_ierb_INSTANCE_COUNT                (1u)

/* ieprc_ierb - Peripheral instance base addresses */
/** Peripheral IEPRC_1__IEPRC_IERB base address */
#define IP_IEPRC_1__IEPRC_IERB_BASE              (0x40120000u)
/** Peripheral IEPRC_1__IEPRC_IERB base pointer */
#define IP_IEPRC_1__IEPRC_IERB                   ((ieprc_ierb_Type *)IP_IEPRC_1__IEPRC_IERB_BASE)
/** Array initializer of ieprc_ierb peripheral base addresses */
#define IP_ieprc_ierb_BASE_ADDRS                 { IP_IEPRC_1__IEPRC_IERB_BASE }
/** Array initializer of ieprc_ierb peripheral base pointers */
#define IP_ieprc_ierb_BASE_PTRS                  { IP_IEPRC_1__IEPRC_IERB }

/* ----------------------------------------------------------------------------
   -- ieprc_ierb Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ieprc_ierb_Register_Masks ieprc_ierb Register Masks
 * @{
 */

/*! @name B_EC_F0_CFH_DIDVID - Bus n EC Function 0 config header device ID and vendor ID register */
/*! @{ */

#define ieprc_ierb_B_EC_F0_CFH_DIDVID_VENDOR_ID_MASK (0xFFFFU)
#define ieprc_ierb_B_EC_F0_CFH_DIDVID_VENDOR_ID_SHIFT (0U)
#define ieprc_ierb_B_EC_F0_CFH_DIDVID_VENDOR_ID_WIDTH (16U)
#define ieprc_ierb_B_EC_F0_CFH_DIDVID_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_B_EC_F0_CFH_DIDVID_VENDOR_ID_SHIFT)) & ieprc_ierb_B_EC_F0_CFH_DIDVID_VENDOR_ID_MASK)

#define ieprc_ierb_B_EC_F0_CFH_DIDVID_DEVICE_ID_MASK (0xFFFF0000U)
#define ieprc_ierb_B_EC_F0_CFH_DIDVID_DEVICE_ID_SHIFT (16U)
#define ieprc_ierb_B_EC_F0_CFH_DIDVID_DEVICE_ID_WIDTH (16U)
#define ieprc_ierb_B_EC_F0_CFH_DIDVID_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_B_EC_F0_CFH_DIDVID_DEVICE_ID_SHIFT)) & ieprc_ierb_B_EC_F0_CFH_DIDVID_DEVICE_ID_MASK)
/*! @} */

/*! @name B_EC_F0_CFH_SIDSVID - Bus n EC Function 0 config header subsystem ID and subsystem vendor ID register */
/*! @{ */

#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_WIDTH (16U)
#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT)) & ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK)

#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK (0xFFFF0000U)
#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT (16U)
#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_WIDTH (16U)
#define ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT)) & ieprc_ierb_B_EC_F0_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK)
/*! @} */

/*! @name B_EC_F0_CFH_REVID - Bus n EC Function 0 config header revision register */
/*! @{ */

#define ieprc_ierb_B_EC_F0_CFH_REVID_REVISION_ID_MASK (0xFFU)
#define ieprc_ierb_B_EC_F0_CFH_REVID_REVISION_ID_SHIFT (0U)
#define ieprc_ierb_B_EC_F0_CFH_REVID_REVISION_ID_WIDTH (8U)
#define ieprc_ierb_B_EC_F0_CFH_REVID_REVISION_ID(x) (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_B_EC_F0_CFH_REVID_REVISION_ID_SHIFT)) & ieprc_ierb_B_EC_F0_CFH_REVID_REVISION_ID_MASK)
/*! @} */

/*! @name CAP0 - Capability 0 register */
/*! @{ */

#define ieprc_ierb_CAP0_NUM_EP_MASK              (0x7U)
#define ieprc_ierb_CAP0_NUM_EP_SHIFT             (0U)
#define ieprc_ierb_CAP0_NUM_EP_WIDTH             (3U)
#define ieprc_ierb_CAP0_NUM_EP(x)                (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_CAP0_NUM_EP_SHIFT)) & ieprc_ierb_CAP0_NUM_EP_MASK)

#define ieprc_ierb_CAP0_INT_TYPE_MASK            (0x8U)
#define ieprc_ierb_CAP0_INT_TYPE_SHIFT           (3U)
#define ieprc_ierb_CAP0_INT_TYPE_WIDTH           (1U)
#define ieprc_ierb_CAP0_INT_TYPE(x)              (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_CAP0_INT_TYPE_SHIFT)) & ieprc_ierb_CAP0_INT_TYPE_MASK)

#define ieprc_ierb_CAP0_NUM_PCI_BUS_MASK         (0x7F0000U)
#define ieprc_ierb_CAP0_NUM_PCI_BUS_SHIFT        (16U)
#define ieprc_ierb_CAP0_NUM_PCI_BUS_WIDTH        (7U)
#define ieprc_ierb_CAP0_NUM_PCI_BUS(x)           (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_CAP0_NUM_PCI_BUS_SHIFT)) & ieprc_ierb_CAP0_NUM_PCI_BUS_MASK)

#define ieprc_ierb_CAP0_NUM_RCEC_MASK            (0x7F000000U)
#define ieprc_ierb_CAP0_NUM_RCEC_SHIFT           (24U)
#define ieprc_ierb_CAP0_NUM_RCEC_WIDTH           (7U)
#define ieprc_ierb_CAP0_NUM_RCEC(x)              (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_CAP0_NUM_RCEC_SHIFT)) & ieprc_ierb_CAP0_NUM_RCEC_MASK)
/*! @} */

/*! @name EC_CFG - EC Configuration register */
/*! @{ */

#define ieprc_ierb_EC_CFG_FUNC_NUM_MASK          (0x7U)
#define ieprc_ierb_EC_CFG_FUNC_NUM_SHIFT         (0U)
#define ieprc_ierb_EC_CFG_FUNC_NUM_WIDTH         (3U)
#define ieprc_ierb_EC_CFG_FUNC_NUM(x)            (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_EC_CFG_FUNC_NUM_SHIFT)) & ieprc_ierb_EC_CFG_FUNC_NUM_MASK)

#define ieprc_ierb_EC_CFG_DEV_NUM_MASK           (0xF8U)
#define ieprc_ierb_EC_CFG_DEV_NUM_SHIFT          (3U)
#define ieprc_ierb_EC_CFG_DEV_NUM_WIDTH          (5U)
#define ieprc_ierb_EC_CFG_DEV_NUM(x)             (((uint32_t)(((uint32_t)(x)) << ieprc_ierb_EC_CFG_DEV_NUM_SHIFT)) & ieprc_ierb_EC_CFG_DEV_NUM_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ieprc_ierb_Register_Masks */

/*!
 * @}
 */ /* end of group ieprc_ierb_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_ieprc_ierb_H_) */
