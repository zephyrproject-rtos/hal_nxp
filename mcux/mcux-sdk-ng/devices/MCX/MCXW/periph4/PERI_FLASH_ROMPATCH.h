/*
** ###################################################################
**     Processors:          MCXW235BIHNAR
**                          MCXW235BIUKAR
**                          MCXW236AIHNAR
**                          MCXW236AIUKAR
**                          MCXW236BIHNAR
**                          MCXW236BIUKAR
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FLASH_ROMPATCH
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-03-08)
**         Initial version based on v0.1UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FLASH_ROMPATCH.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FLASH_ROMPATCH
 *
 * CMSIS Peripheral Access Layer for FLASH_ROMPATCH
 */

#if !defined(PERI_FLASH_ROMPATCH_H_)
#define PERI_FLASH_ROMPATCH_H_                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW235BIHNAR) || defined(CPU_MCXW235BIUKAR))
#include "MCXW235_COMMON.h"
#elif (defined(CPU_MCXW236AIHNAR) || defined(CPU_MCXW236AIUKAR) || defined(CPU_MCXW236BIHNAR) || defined(CPU_MCXW236BIUKAR))
#include "MCXW236_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- FLASH_ROMPATCH Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_ROMPATCH_Peripheral_Access_Layer FLASH_ROMPATCH Peripheral Access Layer
 * @{
 */

/** FLASH_ROMPATCH - Size of Registers Arrays */
#define FLASH_ROMPATCH_PATCH_COUNT                639u

/** FLASH_ROMPATCH - Register Layout Typedef */
typedef struct {
  __IO uint32_t HEADER;                            /**< ., offset: 0x0 */
  __IO uint32_t PATCH[FLASH_ROMPATCH_PATCH_COUNT]; /**< ., array offset: 0x4, array step: 0x4 */
} FLASH_ROMPATCH_Type;

/* ----------------------------------------------------------------------------
   -- FLASH_ROMPATCH Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_ROMPATCH_Register_Masks FLASH_ROMPATCH Register Masks
 * @{
 */

/*! @name HEADER - . */
/*! @{ */

#define FLASH_ROMPATCH_HEADER_ENTRIES_MASK       (0xFFU)
#define FLASH_ROMPATCH_HEADER_ENTRIES_SHIFT      (0U)
/*! ENTRIES - . */
#define FLASH_ROMPATCH_HEADER_ENTRIES(x)         (((uint32_t)(((uint32_t)(x)) << FLASH_ROMPATCH_HEADER_ENTRIES_SHIFT)) & FLASH_ROMPATCH_HEADER_ENTRIES_MASK)

#define FLASH_ROMPATCH_HEADER_SUB_TYPE_MASK      (0xFF00U)
#define FLASH_ROMPATCH_HEADER_SUB_TYPE_SHIFT     (8U)
/*! SUB_TYPE - . */
#define FLASH_ROMPATCH_HEADER_SUB_TYPE(x)        (((uint32_t)(((uint32_t)(x)) << FLASH_ROMPATCH_HEADER_SUB_TYPE_SHIFT)) & FLASH_ROMPATCH_HEADER_SUB_TYPE_MASK)

#define FLASH_ROMPATCH_HEADER_TYPE_MASK          (0xFF0000U)
#define FLASH_ROMPATCH_HEADER_TYPE_SHIFT         (16U)
/*! TYPE - . */
#define FLASH_ROMPATCH_HEADER_TYPE(x)            (((uint32_t)(((uint32_t)(x)) << FLASH_ROMPATCH_HEADER_TYPE_SHIFT)) & FLASH_ROMPATCH_HEADER_TYPE_MASK)

#define FLASH_ROMPATCH_HEADER_IDENTIFIER_MASK    (0xFF000000U)
#define FLASH_ROMPATCH_HEADER_IDENTIFIER_SHIFT   (24U)
/*! IDENTIFIER - . */
#define FLASH_ROMPATCH_HEADER_IDENTIFIER(x)      (((uint32_t)(((uint32_t)(x)) << FLASH_ROMPATCH_HEADER_IDENTIFIER_SHIFT)) & FLASH_ROMPATCH_HEADER_IDENTIFIER_MASK)
/*! @} */

/*! @name PATCH - . */
/*! @{ */

#define FLASH_ROMPATCH_PATCH_PATCH_MASK          (0xFFFFFFFFU)
#define FLASH_ROMPATCH_PATCH_PATCH_SHIFT         (0U)
/*! PATCH - . */
#define FLASH_ROMPATCH_PATCH_PATCH(x)            (((uint32_t)(((uint32_t)(x)) << FLASH_ROMPATCH_PATCH_PATCH_SHIFT)) & FLASH_ROMPATCH_PATCH_PATCH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FLASH_ROMPATCH_Register_Masks */


/*!
 * @}
 */ /* end of group FLASH_ROMPATCH_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_FLASH_ROMPATCH_H_ */

