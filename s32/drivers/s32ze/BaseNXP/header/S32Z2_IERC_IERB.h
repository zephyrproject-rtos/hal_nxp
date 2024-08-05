/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_ierc_ierb.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_ierc_ierb
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
#if !defined(S32Z2_ierc_ierb_H_)  /* Check if memory map has not been already included */
#define S32Z2_ierc_ierb_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ierc_ierb Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ierc_ierb_Peripheral_Access_Layer ierc_ierb Peripheral Access Layer
 * @{
 */

/** ierc_ierb - Register Layout Typedef */
typedef struct {
  __IO uint32_t F0_EC_CFH_DIDVID;                  /**< Function 0 EC config header device ID and vendor ID register, offset: 0x0 */
  __IO uint32_t F0_EC_CFH_SIDSVID;                 /**< Function 0 EC config header subsystem ID and subsystem vendor ID register, offset: 0x4 */
} ierc_ierb_Type, *ierc_ierb_MemMapPtr;

/** Number of instances of the ierc_ierb module. */
#define ierc_ierb_INSTANCE_COUNT                 (1u)

/* ierc_ierb - Peripheral instance base addresses */
/** Peripheral NETC__IERC_IERB base address */
#define IP_NETC__IERC_IERB_BASE                  (0x74810000u)
/** Peripheral NETC__IERC_IERB base pointer */
#define IP_NETC__IERC_IERB                       ((ierc_ierb_Type *)IP_NETC__IERC_IERB_BASE)
/** Array initializer of ierc_ierb peripheral base addresses */
#define IP_ierc_ierb_BASE_ADDRS                  { IP_NETC__IERC_IERB_BASE }
/** Array initializer of ierc_ierb peripheral base pointers */
#define IP_ierc_ierb_BASE_PTRS                   { IP_NETC__IERC_IERB }

/* ----------------------------------------------------------------------------
   -- ierc_ierb Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ierc_ierb_Register_Masks ierc_ierb Register Masks
 * @{
 */

/*! @name F0_EC_CFH_DIDVID - Function 0 EC config header device ID and vendor ID register */
/*! @{ */

#define ierc_ierb_F0_EC_CFH_DIDVID_VENDOR_ID_MASK (0xFFFFU)
#define ierc_ierb_F0_EC_CFH_DIDVID_VENDOR_ID_SHIFT (0U)
#define ierc_ierb_F0_EC_CFH_DIDVID_VENDOR_ID_WIDTH (16U)
#define ierc_ierb_F0_EC_CFH_DIDVID_VENDOR_ID(x)  (((uint32_t)(((uint32_t)(x)) << ierc_ierb_F0_EC_CFH_DIDVID_VENDOR_ID_SHIFT)) & ierc_ierb_F0_EC_CFH_DIDVID_VENDOR_ID_MASK)

#define ierc_ierb_F0_EC_CFH_DIDVID_DEVICE_ID_MASK (0xFFFF0000U)
#define ierc_ierb_F0_EC_CFH_DIDVID_DEVICE_ID_SHIFT (16U)
#define ierc_ierb_F0_EC_CFH_DIDVID_DEVICE_ID_WIDTH (16U)
#define ierc_ierb_F0_EC_CFH_DIDVID_DEVICE_ID(x)  (((uint32_t)(((uint32_t)(x)) << ierc_ierb_F0_EC_CFH_DIDVID_DEVICE_ID_SHIFT)) & ierc_ierb_F0_EC_CFH_DIDVID_DEVICE_ID_MASK)
/*! @} */

/*! @name F0_EC_CFH_SIDSVID - Function 0 EC config header subsystem ID and subsystem vendor ID register */
/*! @{ */

#define ierc_ierb_F0_EC_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define ierc_ierb_F0_EC_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define ierc_ierb_F0_EC_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_WIDTH (16U)
#define ierc_ierb_F0_EC_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << ierc_ierb_F0_EC_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT)) & ierc_ierb_F0_EC_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK)

#define ierc_ierb_F0_EC_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK (0xFFFF0000U)
#define ierc_ierb_F0_EC_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT (16U)
#define ierc_ierb_F0_EC_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_WIDTH (16U)
#define ierc_ierb_F0_EC_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << ierc_ierb_F0_EC_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT)) & ierc_ierb_F0_EC_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ierc_ierb_Register_Masks */

/*!
 * @}
 */ /* end of group ierc_ierb_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_ierc_ierb_H_) */
