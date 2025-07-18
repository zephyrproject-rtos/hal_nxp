/*
** ###################################################################
**     Processors:          MC56F84441VLF
**                          MC56F84442VLH
**                          MC56F84451VLF
**                          MC56F84452VLH
**                          MC56F84462VLH
**                          MC56F84540VLF
**                          MC56F84543VLH
**                          MC56F84550VLF
**                          MC56F84553VLH
**                          MC56F84565VLK
**                          MC56F84567VLL
**                          MC56F84587VLL
**                          MC56F84763VLH
**                          MC56F84766VLK
**                          MC56F84769VLL
**                          MC56F84786VLK
**                          MC56F84789VLL
**
**     Version:             rev. 3.0, 2024-10-29
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
**     - rev. 2.0 (2021-02-06)
**         Initial version.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CRC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CRC
 *
 * CMSIS Peripheral Access Layer for CRC
 */

#if !defined(PERI_CRC_H_)
#define PERI_CRC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F84441VLF))
#include "MC56F84441_COMMON.h"
#elif (defined(CPU_MC56F84442VLH))
#include "MC56F84442_COMMON.h"
#elif (defined(CPU_MC56F84451VLF))
#include "MC56F84451_COMMON.h"
#elif (defined(CPU_MC56F84452VLH))
#include "MC56F84452_COMMON.h"
#elif (defined(CPU_MC56F84462VLH))
#include "MC56F84462_COMMON.h"
#elif (defined(CPU_MC56F84540VLF))
#include "MC56F84540_COMMON.h"
#elif (defined(CPU_MC56F84543VLH))
#include "MC56F84543_COMMON.h"
#elif (defined(CPU_MC56F84550VLF))
#include "MC56F84550_COMMON.h"
#elif (defined(CPU_MC56F84553VLH))
#include "MC56F84553_COMMON.h"
#elif (defined(CPU_MC56F84565VLK))
#include "MC56F84565_COMMON.h"
#elif (defined(CPU_MC56F84567VLL))
#include "MC56F84567_COMMON.h"
#elif (defined(CPU_MC56F84587VLL))
#include "MC56F84587_COMMON.h"
#elif (defined(CPU_MC56F84763VLH))
#include "MC56F84763_COMMON.h"
#elif (defined(CPU_MC56F84766VLK))
#include "MC56F84766_COMMON.h"
#elif (defined(CPU_MC56F84769VLL))
#include "MC56F84769_COMMON.h"
#elif (defined(CPU_MC56F84786VLK))
#include "MC56F84786_COMMON.h"
#elif (defined(CPU_MC56F84789VLL))
#include "MC56F84789_COMMON.h"
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
    __IO uint8_t CRC8;                               /**< Low lower byte of CRC_CRC register., offset: 0x0 */
    __IO uint16_t CRC16;                             /**< Low word of CRC_CRC register., offset: 0x0 */
    __IO uint32_t CRC32;                             /**< CRC Data Register, offset: 0x0 */
  };
  __IO uint32_t GPOLY;                             /**< CRC Polynomial Register, offset: 0x2 */
  __IO uint32_t CTRL;                              /**< CRC Control Register, offset: 0x4 */
} CRC_Type;

/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Masks CRC Register Masks
 * @{
 */

/*! @name CRC8 - Low lower byte of CRC_CRC register. */
/*! @{ */

#define CRC_CRC8_CRC8_MASK                       (0xFFU)
#define CRC_CRC8_CRC8_SHIFT                      (0U)
/*! CRC8 - CRCLL stores the lowest 8 bits of the 32 bit CRC */
#define CRC_CRC8_CRC8(x)                         (((uint8_t)(((uint8_t)(x)) << CRC_CRC8_CRC8_SHIFT)) & CRC_CRC8_CRC8_MASK)
/*! @} */

/*! @name CRC16 - Low word of CRC_CRC register. */
/*! @{ */

#define CRC_CRC16_CRC16_MASK                     (0xFFFFU)
#define CRC_CRC16_CRC16_SHIFT                    (0U)
/*! CRC16 - CRCL stores the lower 16 bits of the 16/32 bit CRC */
#define CRC_CRC16_CRC16(x)                       (((uint16_t)(((uint16_t)(x)) << CRC_CRC16_CRC16_SHIFT)) & CRC_CRC16_CRC16_MASK)
/*! @} */

/*! @name CRC32 - CRC Data Register */
/*! @{ */

#define CRC_CRC32_LL_MASK                        (0xFFUL)
#define CRC_CRC32_LL_SHIFT                       (0UL)
/*! LL - CRC Low Lower Byte */
#define CRC_CRC32_LL(x)                          (((uint32_t)(((uint32_t)(x)) << CRC_CRC32_LL_SHIFT)) & CRC_CRC32_LL_MASK)

#define CRC_CRC32_LU_MASK                        (0xFF00UL)
#define CRC_CRC32_LU_SHIFT                       (8UL)
/*! LU - CRC Low Upper Byte */
#define CRC_CRC32_LU(x)                          (((uint32_t)(((uint32_t)(x)) << CRC_CRC32_LU_SHIFT)) & CRC_CRC32_LU_MASK)

#define CRC_CRC32_HL_MASK                        (0xFF0000UL)
#define CRC_CRC32_HL_SHIFT                       (16UL)
/*! HL - CRC High Lower Byte */
#define CRC_CRC32_HL(x)                          (((uint32_t)(((uint32_t)(x)) << CRC_CRC32_HL_SHIFT)) & CRC_CRC32_HL_MASK)

#define CRC_CRC32_HU_MASK                        (0xFF000000UL)
#define CRC_CRC32_HU_SHIFT                       (24UL)
/*! HU - CRC High Upper Byte */
#define CRC_CRC32_HU(x)                          (((uint32_t)(((uint32_t)(x)) << CRC_CRC32_HU_SHIFT)) & CRC_CRC32_HU_MASK)
/*! @} */

/*! @name GPOLY - CRC Polynomial Register */
/*! @{ */

#define CRC_GPOLY_LOW_MASK                       (0xFFFFUL)
#define CRC_GPOLY_LOW_SHIFT                      (0UL)
/*! LOW - Low polynominal half-word */
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_GPOLY_LOW_SHIFT)) & CRC_GPOLY_LOW_MASK)

#define CRC_GPOLY_HIGH_MASK                      (0xFFFF0000UL)
#define CRC_GPOLY_HIGH_SHIFT                     (16UL)
/*! HIGH - High polynominal half-word */
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x)) << CRC_GPOLY_HIGH_SHIFT)) & CRC_GPOLY_HIGH_MASK)
/*! @} */

/*! @name CTRL - CRC Control Register */
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
/*! WAS - Write CRC data register as seed
 *  0b0..Writes to the CRC data register are data values.
 *  0b1..Writes to the CRC data register are seed values.
 */
#define CRC_CTRL_WAS(x)                          (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_WAS_SHIFT)) & CRC_CTRL_WAS_MASK)

#define CRC_CTRL_FXOR_MASK                       (0x4000000UL)
#define CRC_CTRL_FXOR_SHIFT                      (26UL)
/*! FXOR - Complement Read of CRC data register
 *  0b0..No XOR on reading.
 *  0b1..Invert or complement the read value of the CRC data register.
 */
#define CRC_CTRL_FXOR(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_FXOR_SHIFT)) & CRC_CTRL_FXOR_MASK)

#define CRC_CTRL_TOTR_MASK                       (0x30000000UL)
#define CRC_CTRL_TOTR_SHIFT                      (28UL)
/*! TOTR - Type of Transpose for Read
 *  0b00..No transposition.
 *  0b01..Bits in bytes are transposed; bytes are not transposed.
 *  0b10..Both bits in bytes and bytes are transposed.
 *  0b11..Only bytes are transposed; no bits in a byte are transposed.
 */
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x)) << CRC_CTRL_TOTR_SHIFT)) & CRC_CTRL_TOTR_MASK)

#define CRC_CTRL_TOT_MASK                        (0xC0000000UL)
#define CRC_CTRL_TOT_SHIFT                       (30UL)
/*! TOT - Type of Transpose for Writes
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

