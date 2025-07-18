/*
** ###################################################################
**     Processors:          MC56F83663VLH
**                          MC56F83683VLH
**                          MC56F83686VLK
**                          MC56F83689VLL
**                          MC56F83763AVLH
**                          MC56F83763VLH
**                          MC56F83766VLK
**                          MC56F83769AVLL
**                          MC56F83769VLL
**                          MC56F83783AVLH
**                          MC56F83783VLH
**                          MC56F83786VLK
**                          MC56F83789AVLL
**                          MC56F83789VLL
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CRC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2019-09-23)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CRC.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CRC
 *
 * CMSIS Peripheral Access Layer for CRC
 */

#if !defined(PERI_CRC_H_)
#define PERI_CRC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F83663VLH))
#include "MC56F83663_COMMON.h"
#elif (defined(CPU_MC56F83683VLH))
#include "MC56F83683_COMMON.h"
#elif (defined(CPU_MC56F83686VLK))
#include "MC56F83686_COMMON.h"
#elif (defined(CPU_MC56F83689VLL))
#include "MC56F83689_COMMON.h"
#elif (defined(CPU_MC56F83763AVLH) || defined(CPU_MC56F83763VLH))
#include "MC56F83763_COMMON.h"
#elif (defined(CPU_MC56F83766VLK))
#include "MC56F83766_COMMON.h"
#elif (defined(CPU_MC56F83769AVLL) || defined(CPU_MC56F83769VLL))
#include "MC56F83769_COMMON.h"
#elif (defined(CPU_MC56F83783AVLH) || defined(CPU_MC56F83783VLH))
#include "MC56F83783_COMMON.h"
#elif (defined(CPU_MC56F83786VLK))
#include "MC56F83786_COMMON.h"
#elif (defined(CPU_MC56F83789AVLL) || defined(CPU_MC56F83789VLL))
#include "MC56F83789_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- CRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Peripheral_Access_Layer CRC Peripheral Access Layer
 * @{
 */

/** CRC - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    __IO uint8_t DATA8;                              /**< Low lower byte of CRC_DATA register., offset: 0x0 */
    __IO uint16_t DATA16;                            /**< Low word of CRC_DATA register., offset: 0x0 */
    __IO uint32_t DATA32;                            /**< CRC Data register, offset: 0x0 */
  };
  __IO uint32_t GPOLY;                             /**< CRC Polynomial register, offset: 0x2 */
  __IO uint32_t CTRL;                              /**< CRC Control register, offset: 0x4 */
} CRC_Type;

/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Masks CRC Register Masks
 * @{
 */

/*! @name DATA8 - Low lower byte of CRC_DATA register. */
/*! @{ */

#define CRC_DATA8_DATA8_MASK                     (0xFFU)
#define CRC_DATA8_DATA8_SHIFT                    (0U)
/*! DATA8 - DATALL stores the lowest 8 bits of the 32 bit DATA */
#define CRC_DATA8_DATA8(x)                       (((uint8_t)(((uint8_t)(x)) << CRC_DATA8_DATA8_SHIFT)) & CRC_DATA8_DATA8_MASK)
/*! @} */

/*! @name DATA16 - Low word of CRC_DATA register. */
/*! @{ */

#define CRC_DATA16_DATA16_MASK                   (0xFFFFU)
#define CRC_DATA16_DATA16_SHIFT                  (0U)
/*! DATA16 - DATAL stores the lower 16 bits of the 16/32 bit DATA */
#define CRC_DATA16_DATA16(x)                     (((uint16_t)(((uint16_t)(x)) << CRC_DATA16_DATA16_SHIFT)) & CRC_DATA16_DATA16_MASK)
/*! @} */

/*! @name DATA32 - CRC Data register */
/*! @{ */

#define CRC_DATA32_LL_MASK                       (0xFFUL)
#define CRC_DATA32_LL_SHIFT                      (0UL)
/*! LL - CRC Low Lower Byte */
#define CRC_DATA32_LL(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_DATA32_LL_SHIFT)) & CRC_DATA32_LL_MASK)

#define CRC_DATA32_LU_MASK                       (0xFF00UL)
#define CRC_DATA32_LU_SHIFT                      (8UL)
/*! LU - CRC Low Upper Byte */
#define CRC_DATA32_LU(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_DATA32_LU_SHIFT)) & CRC_DATA32_LU_MASK)

#define CRC_DATA32_HL_MASK                       (0xFF0000UL)
#define CRC_DATA32_HL_SHIFT                      (16UL)
/*! HL - CRC High Lower Byte */
#define CRC_DATA32_HL(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_DATA32_HL_SHIFT)) & CRC_DATA32_HL_MASK)

#define CRC_DATA32_HU_MASK                       (0xFF000000UL)
#define CRC_DATA32_HU_SHIFT                      (24UL)
/*! HU - CRC High Upper Byte */
#define CRC_DATA32_HU(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_DATA32_HU_SHIFT)) & CRC_DATA32_HU_MASK)
/*! @} */

/*! @name GPOLY - CRC Polynomial register */
/*! @{ */

#define CRC_GPOLY_LOW_MASK                       (0xFFFFUL)
#define CRC_GPOLY_LOW_SHIFT                      (0UL)
/*! LOW - Low Polynominal Half-word */
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_GPOLY_LOW_SHIFT)) & CRC_GPOLY_LOW_MASK)

#define CRC_GPOLY_HIGH_MASK                      (0xFFFF0000UL)
#define CRC_GPOLY_HIGH_SHIFT                     (16UL)
/*! HIGH - High Polynominal Half-word */
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x)) << CRC_GPOLY_HIGH_SHIFT)) & CRC_GPOLY_HIGH_MASK)
/*! @} */

/*! @name CTRL - CRC Control register */
/*! @{ */

#define CRC_CTRL_TCRC_MASK                       (0x1000000UL)
#define CRC_CTRL_TCRC_SHIFT                      (24UL)
/*! TCRC
 *  0b0..16-bit CRC protocol.
 *  0b1..32-bit CRC protocol.
 */
#define CRC_CTRL_TCRC(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_TCRC_SHIFT)) & CRC_CTRL_TCRC_MASK)

#define CRC_CTRL_WAS_MASK                        (0x2000000UL)
#define CRC_CTRL_WAS_SHIFT                       (25UL)
/*! WAS - Write CRC Data Register As Seed
 *  0b0..Writes to the CRC data register are data values.
 *  0b1..Writes to the CRC data register are seed values.
 */
#define CRC_CTRL_WAS(x)                          (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_WAS_SHIFT)) & CRC_CTRL_WAS_MASK)

#define CRC_CTRL_FXOR_MASK                       (0x4000000UL)
#define CRC_CTRL_FXOR_SHIFT                      (26UL)
/*! FXOR - Complement Read Of CRC Data Register
 *  0b0..No XOR on reading.
 *  0b1..Invert or complement the read value of the CRC Data register.
 */
#define CRC_CTRL_FXOR(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_FXOR_SHIFT)) & CRC_CTRL_FXOR_MASK)

#define CRC_CTRL_TOTR_MASK                       (0x30000000UL)
#define CRC_CTRL_TOTR_SHIFT                      (28UL)
/*! TOTR - Type Of Transpose For Read
 *  0b00..No transposition.
 *  0b01..Bits in bytes are transposed; bytes are not transposed.
 *  0b10..Both bits in bytes and bytes are transposed.
 *  0b11..Only bytes are transposed; no bits in a byte are transposed.
 */
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_TOTR_SHIFT)) & CRC_CTRL_TOTR_MASK)

#define CRC_CTRL_TOT_MASK                        (0xC0000000UL)
#define CRC_CTRL_TOT_SHIFT                       (30UL)
/*! TOT - Type Of Transpose For Writes
 *  0b00..No transposition.
 *  0b01..Bits in bytes are transposed; bytes are not transposed.
 *  0b10..Both bits in bytes and bytes are transposed.
 *  0b11..Only bytes are transposed; no bits in a byte are transposed.
 */
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_TOT_SHIFT)) & CRC_CTRL_TOT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CRC_Register_Masks */


/*!
 * @}
 */ /* end of group CRC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_CRC_H_ */

