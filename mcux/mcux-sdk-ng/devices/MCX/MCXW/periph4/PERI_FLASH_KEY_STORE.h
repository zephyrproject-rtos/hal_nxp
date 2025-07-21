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
**         CMSIS Peripheral Access Layer for FLASH_KEY_STORE
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
 * @file PERI_FLASH_KEY_STORE.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FLASH_KEY_STORE
 *
 * CMSIS Peripheral Access Layer for FLASH_KEY_STORE
 */

#if !defined(PERI_FLASH_KEY_STORE_H_)
#define PERI_FLASH_KEY_STORE_H_                  /**< Symbol preventing repeated inclusion */

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
   -- FLASH_KEY_STORE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_KEY_STORE_Peripheral_Access_Layer FLASH_KEY_STORE Peripheral Access Layer
 * @{
 */

/** FLASH_KEY_STORE - Size of Registers Arrays */
#define FLASH_KEY_STORE_SBKEY_KEY_CODE_SBKEY_KEY_CODE_SBKEY_KEY_CODE_COUNT 14u
#define FLASH_KEY_STORE_SBKEY_KEY_CODE_SBKEY_KEY_CODE_CORE_SBKEY_BODY_COUNT 12u
#define FLASH_KEY_STORE_USER_KEK_KEY_CODE_USER_KEK_KEY_CODE_USER_KEK_KEY_CODE_COUNT 14u
#define FLASH_KEY_STORE_USER_KEK_KEY_CODE_USER_KEK_KEY_CODE_CORE_USER_KEK_BODY_COUNT 12u

/** FLASH_KEY_STORE - Register Layout Typedef */
typedef struct {
  __IO uint32_t HEADER;                            /**< Valid Key Store Header : 0x95959595, offset: 0x0 */
       uint8_t RESERVED_0[12];
  union {                                          /* offset: 0x10 */
    __IO uint32_t SBKEY_KEY_CODE[FLASH_KEY_STORE_SBKEY_KEY_CODE_SBKEY_KEY_CODE_SBKEY_KEY_CODE_COUNT];   /**< ., array offset: 0x10, array step: 0x4 */
    struct {                                         /* offset: 0x10 */
      __IO uint32_t SBKEY_HEADER0;                     /**< ., offset: 0x10 */
      __IO uint32_t SBKEY_HEADER1;                     /**< ., offset: 0x14 */
      __IO uint32_t SBKEY_BODY[FLASH_KEY_STORE_SBKEY_KEY_CODE_SBKEY_KEY_CODE_CORE_SBKEY_BODY_COUNT];     /**< ., array offset: 0x18, array step: 0x4 */
    } SBKEY_KEY_CODE_CORE;
  };
  union {                                          /* offset: 0x48 */
    __IO uint32_t USER_KEK_KEY_CODE[FLASH_KEY_STORE_USER_KEK_KEY_CODE_USER_KEK_KEY_CODE_USER_KEK_KEY_CODE_COUNT];   /**< ., array offset: 0x48, array step: 0x4 */
    struct {                                         /* offset: 0x48 */
      __IO uint32_t USER_KEK_HEADER0;                  /**< ., offset: 0x48 */
      __IO uint32_t USER_KEK_HEADER1;                  /**< ., offset: 0x4C */
      __IO uint32_t USER_KEK_BODY[FLASH_KEY_STORE_USER_KEK_KEY_CODE_USER_KEK_KEY_CODE_CORE_USER_KEK_BODY_COUNT];     /**< ., array offset: 0x50, array step: 0x4 */
    } USER_KEK_KEY_CODE_CORE;
  };
} FLASH_KEY_STORE_Type;

/* ----------------------------------------------------------------------------
   -- FLASH_KEY_STORE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_KEY_STORE_Register_Masks FLASH_KEY_STORE Register Masks
 * @{
 */

/*! @name HEADER - Valid Key Store Header : 0x95959595 */
/*! @{ */

#define FLASH_KEY_STORE_HEADER_FIELD_MASK        (0xFFFFFFFFU)
#define FLASH_KEY_STORE_HEADER_FIELD_SHIFT       (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_HEADER_FIELD(x)          (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_HEADER_FIELD_SHIFT)) & FLASH_KEY_STORE_HEADER_FIELD_MASK)
/*! @} */

/*! @name SBKEY_KEY_CODE - . */
/*! @{ */

#define FLASH_KEY_STORE_SBKEY_KEY_CODE_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_SBKEY_KEY_CODE_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_SBKEY_KEY_CODE_FIELD(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_SBKEY_KEY_CODE_FIELD_SHIFT)) & FLASH_KEY_STORE_SBKEY_KEY_CODE_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_SBKEY_KEY_CODE */
#define FLASH_KEY_STORE_SBKEY_KEY_CODE_COUNT     (14U)

/*! @name SBKEY_HEADER0 - . */
/*! @{ */

#define FLASH_KEY_STORE_SBKEY_HEADER0_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_SBKEY_HEADER0_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_SBKEY_HEADER0_FIELD(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_SBKEY_HEADER0_FIELD_SHIFT)) & FLASH_KEY_STORE_SBKEY_HEADER0_FIELD_MASK)
/*! @} */

/*! @name SBKEY_HEADER1 - . */
/*! @{ */

#define FLASH_KEY_STORE_SBKEY_HEADER1_TYPE_MASK  (0x3U)
#define FLASH_KEY_STORE_SBKEY_HEADER1_TYPE_SHIFT (0U)
/*! TYPE - . */
#define FLASH_KEY_STORE_SBKEY_HEADER1_TYPE(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_SBKEY_HEADER1_TYPE_SHIFT)) & FLASH_KEY_STORE_SBKEY_HEADER1_TYPE_MASK)

#define FLASH_KEY_STORE_SBKEY_HEADER1_INDEX_MASK (0xF00U)
#define FLASH_KEY_STORE_SBKEY_HEADER1_INDEX_SHIFT (8U)
/*! INDEX - . */
#define FLASH_KEY_STORE_SBKEY_HEADER1_INDEX(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_SBKEY_HEADER1_INDEX_SHIFT)) & FLASH_KEY_STORE_SBKEY_HEADER1_INDEX_MASK)

#define FLASH_KEY_STORE_SBKEY_HEADER1_SIZE_MASK  (0x3F000000U)
#define FLASH_KEY_STORE_SBKEY_HEADER1_SIZE_SHIFT (24U)
/*! SIZE - . */
#define FLASH_KEY_STORE_SBKEY_HEADER1_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_SBKEY_HEADER1_SIZE_SHIFT)) & FLASH_KEY_STORE_SBKEY_HEADER1_SIZE_MASK)
/*! @} */

/*! @name SBKEY_BODY - . */
/*! @{ */

#define FLASH_KEY_STORE_SBKEY_BODY_FIELD_MASK    (0xFFFFFFFFU)
#define FLASH_KEY_STORE_SBKEY_BODY_FIELD_SHIFT   (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_SBKEY_BODY_FIELD(x)      (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_SBKEY_BODY_FIELD_SHIFT)) & FLASH_KEY_STORE_SBKEY_BODY_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_SBKEY_BODY */
#define FLASH_KEY_STORE_SBKEY_BODY_COUNT         (12U)

/*! @name USER_KEK_KEY_CODE - . */
/*! @{ */

#define FLASH_KEY_STORE_USER_KEK_KEY_CODE_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_USER_KEK_KEY_CODE_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_USER_KEK_KEY_CODE_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_USER_KEK_KEY_CODE_FIELD_SHIFT)) & FLASH_KEY_STORE_USER_KEK_KEY_CODE_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_USER_KEK_KEY_CODE */
#define FLASH_KEY_STORE_USER_KEK_KEY_CODE_COUNT  (14U)

/*! @name USER_KEK_HEADER0 - . */
/*! @{ */

#define FLASH_KEY_STORE_USER_KEK_HEADER0_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_USER_KEK_HEADER0_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_USER_KEK_HEADER0_FIELD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_USER_KEK_HEADER0_FIELD_SHIFT)) & FLASH_KEY_STORE_USER_KEK_HEADER0_FIELD_MASK)
/*! @} */

/*! @name USER_KEK_HEADER1 - . */
/*! @{ */

#define FLASH_KEY_STORE_USER_KEK_HEADER1_TYPE_MASK (0x3U)
#define FLASH_KEY_STORE_USER_KEK_HEADER1_TYPE_SHIFT (0U)
/*! TYPE - . */
#define FLASH_KEY_STORE_USER_KEK_HEADER1_TYPE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_USER_KEK_HEADER1_TYPE_SHIFT)) & FLASH_KEY_STORE_USER_KEK_HEADER1_TYPE_MASK)

#define FLASH_KEY_STORE_USER_KEK_HEADER1_INDEX_MASK (0xF00U)
#define FLASH_KEY_STORE_USER_KEK_HEADER1_INDEX_SHIFT (8U)
/*! INDEX - . */
#define FLASH_KEY_STORE_USER_KEK_HEADER1_INDEX(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_USER_KEK_HEADER1_INDEX_SHIFT)) & FLASH_KEY_STORE_USER_KEK_HEADER1_INDEX_MASK)

#define FLASH_KEY_STORE_USER_KEK_HEADER1_SIZE_MASK (0x3F000000U)
#define FLASH_KEY_STORE_USER_KEK_HEADER1_SIZE_SHIFT (24U)
/*! SIZE - . */
#define FLASH_KEY_STORE_USER_KEK_HEADER1_SIZE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_USER_KEK_HEADER1_SIZE_SHIFT)) & FLASH_KEY_STORE_USER_KEK_HEADER1_SIZE_MASK)
/*! @} */

/*! @name USER_KEK_BODY - . */
/*! @{ */

#define FLASH_KEY_STORE_USER_KEK_BODY_FIELD_MASK (0xFFFFFFFFU)
#define FLASH_KEY_STORE_USER_KEK_BODY_FIELD_SHIFT (0U)
/*! FIELD - . */
#define FLASH_KEY_STORE_USER_KEK_BODY_FIELD(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_KEY_STORE_USER_KEK_BODY_FIELD_SHIFT)) & FLASH_KEY_STORE_USER_KEK_BODY_FIELD_MASK)
/*! @} */

/* The count of FLASH_KEY_STORE_USER_KEK_BODY */
#define FLASH_KEY_STORE_USER_KEK_BODY_COUNT      (12U)


/*!
 * @}
 */ /* end of group FLASH_KEY_STORE_Register_Masks */


/*!
 * @}
 */ /* end of group FLASH_KEY_STORE_Peripheral_Access_Layer */


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


#endif  /* PERI_FLASH_KEY_STORE_H_ */

