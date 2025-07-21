/*
** ###################################################################
**     Processors:          MCXE247VLL
**                          MCXE247VLQ
**
**     Version:             rev. 1.0, 2025-02-21
**     Build:               b250417
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ELA_CSEC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-02-21)
**         Generated based on Rev1 Draft RM..
**
** ###################################################################
*/

/*!
 * @file PERI_ELA_CSEC.h
 * @version 1.0
 * @date 2025-02-21
 * @brief CMSIS Peripheral Access Layer for ELA_CSEC
 *
 * CMSIS Peripheral Access Layer for ELA_CSEC
 */

#if !defined(PERI_ELA_CSEC_H_)
#define PERI_ELA_CSEC_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE247VLL) || defined(CPU_MCXE247VLQ))
#include "MCXE247_COMMON.h"
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
   -- ELA_CSEC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ELA_CSEC_Peripheral_Access_Layer ELA_CSEC Peripheral Access Layer
 * @{
 */

/** ELA_CSEC - Size of Registers Arrays */
#define ELA_CSEC_RAMn_COUNT                       32u

/** ELA_CSEC - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0, array step: 0x4 */
    struct {                                         /* offset: 0x0, array step: 0x4 */
      __IO uint8_t DATA_8LL;                           /**< ELA_CSEC_DATA_8LL register, array offset: 0x0, array step: 0x4 */
      __IO uint8_t DATA_8LU;                           /**< ELA_CSEC_DATA_8LU register, array offset: 0x1, array step: 0x4 */
      __IO uint8_t DATA_8HL;                           /**< ELA_CSEC_DATA_8HL register, array offset: 0x2, array step: 0x4 */
      __IO uint8_t DATA_8HU;                           /**< ELA_CSEC_DATA_8HU register, array offset: 0x3, array step: 0x4 */
    } ACCESS8BIT[ELA_CSEC_RAMn_COUNT];
    __IO uint32_t DATA_32[ELA_CSEC_RAMn_COUNT];      /**< Embedded RAM, array offset: 0x0, array step: 0x4 */
  };
} ELA_CSEC_Type;

/* ----------------------------------------------------------------------------
   -- ELA_CSEC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ELA_CSEC_Register_Masks ELA_CSEC Register Masks
 * @{
 */

/*! @name DATA_8LL - ELA_CSEC_DATA_8LL register */
/*! @{ */

#define ELA_CSEC_DATA_8LL_DATA_8LL_MASK          (0xFFU)
#define ELA_CSEC_DATA_8LL_DATA_8LL_SHIFT         (0U)
#define ELA_CSEC_DATA_8LL_DATA_8LL(x)            (((uint8_t)(((uint8_t)(x)) << ELA_CSEC_DATA_8LL_DATA_8LL_SHIFT)) & ELA_CSEC_DATA_8LL_DATA_8LL_MASK)
/*! @} */

/* The count of ELA_CSEC_DATA_8LL */
#define ELA_CSEC_DATA_8LL_COUNT                  (32U)

/*! @name DATA_8LU - ELA_CSEC_DATA_8LU register */
/*! @{ */

#define ELA_CSEC_DATA_8LU_DATA_8LU_MASK          (0xFFU)
#define ELA_CSEC_DATA_8LU_DATA_8LU_SHIFT         (0U)
#define ELA_CSEC_DATA_8LU_DATA_8LU(x)            (((uint8_t)(((uint8_t)(x)) << ELA_CSEC_DATA_8LU_DATA_8LU_SHIFT)) & ELA_CSEC_DATA_8LU_DATA_8LU_MASK)
/*! @} */

/* The count of ELA_CSEC_DATA_8LU */
#define ELA_CSEC_DATA_8LU_COUNT                  (32U)

/*! @name DATA_8HL - ELA_CSEC_DATA_8HL register */
/*! @{ */

#define ELA_CSEC_DATA_8HL_DATA_8HL_MASK          (0xFFU)
#define ELA_CSEC_DATA_8HL_DATA_8HL_SHIFT         (0U)
#define ELA_CSEC_DATA_8HL_DATA_8HL(x)            (((uint8_t)(((uint8_t)(x)) << ELA_CSEC_DATA_8HL_DATA_8HL_SHIFT)) & ELA_CSEC_DATA_8HL_DATA_8HL_MASK)
/*! @} */

/* The count of ELA_CSEC_DATA_8HL */
#define ELA_CSEC_DATA_8HL_COUNT                  (32U)

/*! @name DATA_8HU - ELA_CSEC_DATA_8HU register */
/*! @{ */

#define ELA_CSEC_DATA_8HU_DATA_8HU_MASK          (0xFFU)
#define ELA_CSEC_DATA_8HU_DATA_8HU_SHIFT         (0U)
#define ELA_CSEC_DATA_8HU_DATA_8HU(x)            (((uint8_t)(((uint8_t)(x)) << ELA_CSEC_DATA_8HU_DATA_8HU_SHIFT)) & ELA_CSEC_DATA_8HU_DATA_8HU_MASK)
/*! @} */

/* The count of ELA_CSEC_DATA_8HU */
#define ELA_CSEC_DATA_8HU_COUNT                  (32U)

/*! @name DATA_32 - Embedded RAM */
/*! @{ */

#define ELA_CSEC_DATA_32_DATA_BYTE_3_MASK        (0xFFU)
#define ELA_CSEC_DATA_32_DATA_BYTE_3_SHIFT       (0U)
/*! DATA_BYTE_3 - Data byte 3 of ELA_CSEC command. */
#define ELA_CSEC_DATA_32_DATA_BYTE_3(x)          (((uint32_t)(((uint32_t)(x)) << ELA_CSEC_DATA_32_DATA_BYTE_3_SHIFT)) & ELA_CSEC_DATA_32_DATA_BYTE_3_MASK)

#define ELA_CSEC_DATA_32_DATA_BYTE_2_MASK        (0xFF00U)
#define ELA_CSEC_DATA_32_DATA_BYTE_2_SHIFT       (8U)
/*! DATA_BYTE_2 - Data byte 2 of ELA_CSEC command. */
#define ELA_CSEC_DATA_32_DATA_BYTE_2(x)          (((uint32_t)(((uint32_t)(x)) << ELA_CSEC_DATA_32_DATA_BYTE_2_SHIFT)) & ELA_CSEC_DATA_32_DATA_BYTE_2_MASK)

#define ELA_CSEC_DATA_32_DATA_BYTE_1_MASK        (0xFF0000U)
#define ELA_CSEC_DATA_32_DATA_BYTE_1_SHIFT       (16U)
/*! DATA_BYTE_1 - Data byte 1 of ELA_CSEC command. */
#define ELA_CSEC_DATA_32_DATA_BYTE_1(x)          (((uint32_t)(((uint32_t)(x)) << ELA_CSEC_DATA_32_DATA_BYTE_1_SHIFT)) & ELA_CSEC_DATA_32_DATA_BYTE_1_MASK)

#define ELA_CSEC_DATA_32_DATA_BYTE_0_MASK        (0xFF000000U)
#define ELA_CSEC_DATA_32_DATA_BYTE_0_SHIFT       (24U)
/*! DATA_BYTE_0 - Data byte 0 of ELA_CSEC command. */
#define ELA_CSEC_DATA_32_DATA_BYTE_0(x)          (((uint32_t)(((uint32_t)(x)) << ELA_CSEC_DATA_32_DATA_BYTE_0_SHIFT)) & ELA_CSEC_DATA_32_DATA_BYTE_0_MASK)
/*! @} */

/* The count of ELA_CSEC_DATA_32 */
#define ELA_CSEC_DATA_32_COUNT                   (32U)


/*!
 * @}
 */ /* end of group ELA_CSEC_Register_Masks */


/*!
 * @}
 */ /* end of group ELA_CSEC_Peripheral_Access_Layer */


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


#endif  /* PERI_ELA_CSEC_H_ */

