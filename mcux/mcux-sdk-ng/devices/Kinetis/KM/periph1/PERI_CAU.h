/*
** ###################################################################
**     Processors:          MKM34Z256VLL7
**                          MKM34Z256VLQ7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CAU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2014-10-17)
**         Initial version.
**     - rev. 1.1 (2015-01-27)
**         Update according to reference manual rev. 1, RC.
**     - rev. 1.2 (2015-03-06)
**         Update according to reference manual rev. 1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CAU.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CAU
 *
 * CMSIS Peripheral Access Layer for CAU
 */

#if !defined(PERI_CAU_H_)
#define PERI_CAU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKM34Z256VLL7) || defined(CPU_MKM34Z256VLQ7))
#include "MKM34Z7_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- CAU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAU_Peripheral_Access_Layer CAU Peripheral Access Layer
 * @{
 */

/** CAU - Size of Registers Arrays */
#define CAU_DIRECT_COUNT                          16u
#define CAU_LDR_CA_COUNT                          9u
#define CAU_STR_CA_COUNT                          9u
#define CAU_ADR_CA_COUNT                          9u
#define CAU_RADR_CA_COUNT                         9u
#define CAU_XOR_CA_COUNT                          9u
#define CAU_ROTL_CA_COUNT                         9u
#define CAU_AESC_CA_COUNT                         9u
#define CAU_AESIC_CA_COUNT                        9u

/** CAU - Register Layout Typedef */
typedef struct {
  __O  uint32_t DIRECT[CAU_DIRECT_COUNT];          /**< Direct access register 0..Direct access register 15, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[2048];
  __O  uint32_t LDR_CASR;                          /**< Status register - Load Register command, offset: 0x840 */
  __O  uint32_t LDR_CAA;                           /**< Accumulator register - Load Register command, offset: 0x844 */
  __O  uint32_t LDR_CA[CAU_LDR_CA_COUNT];          /**< General Purpose Register 0 - Load Register command..General Purpose Register 8 - Load Register command, array offset: 0x848, array step: 0x4 */
       uint8_t RESERVED_1[20];
  __I  uint32_t STR_CASR;                          /**< Status register - Store Register command, offset: 0x880 */
  __I  uint32_t STR_CAA;                           /**< Accumulator register - Store Register command, offset: 0x884 */
  __I  uint32_t STR_CA[CAU_STR_CA_COUNT];          /**< General Purpose Register 0 - Store Register command..General Purpose Register 8 - Store Register command, array offset: 0x888, array step: 0x4 */
       uint8_t RESERVED_2[20];
  __O  uint32_t ADR_CASR;                          /**< Status register - Add Register command, offset: 0x8C0 */
  __O  uint32_t ADR_CAA;                           /**< Accumulator register - Add to register command, offset: 0x8C4 */
  __O  uint32_t ADR_CA[CAU_ADR_CA_COUNT];          /**< General Purpose Register 0 - Add to register command..General Purpose Register 8 - Add to register command, array offset: 0x8C8, array step: 0x4 */
       uint8_t RESERVED_3[20];
  __O  uint32_t RADR_CASR;                         /**< Status register - Reverse and Add to Register command, offset: 0x900 */
  __O  uint32_t RADR_CAA;                          /**< Accumulator register - Reverse and Add to Register command, offset: 0x904 */
  __O  uint32_t RADR_CA[CAU_RADR_CA_COUNT];        /**< General Purpose Register 0 - Reverse and Add to Register command..General Purpose Register 8 - Reverse and Add to Register command, array offset: 0x908, array step: 0x4 */
       uint8_t RESERVED_4[84];
  __O  uint32_t XOR_CASR;                          /**< Status register - Exclusive Or command, offset: 0x980 */
  __O  uint32_t XOR_CAA;                           /**< Accumulator register - Exclusive Or command, offset: 0x984 */
  __O  uint32_t XOR_CA[CAU_XOR_CA_COUNT];          /**< General Purpose Register 0 - Exclusive Or command..General Purpose Register 8 - Exclusive Or command, array offset: 0x988, array step: 0x4 */
       uint8_t RESERVED_5[20];
  __O  uint32_t ROTL_CASR;                         /**< Status register - Rotate Left command, offset: 0x9C0 */
  __O  uint32_t ROTL_CAA;                          /**< Accumulator register - Rotate Left command, offset: 0x9C4 */
  __O  uint32_t ROTL_CA[CAU_ROTL_CA_COUNT];        /**< General Purpose Register 0 - Rotate Left command..General Purpose Register 8 - Rotate Left command, array offset: 0x9C8, array step: 0x4 */
       uint8_t RESERVED_6[276];
  __O  uint32_t AESC_CASR;                         /**< Status register - AES Column Operation command, offset: 0xB00 */
  __O  uint32_t AESC_CAA;                          /**< Accumulator register - AES Column Operation command, offset: 0xB04 */
  __O  uint32_t AESC_CA[CAU_AESC_CA_COUNT];        /**< General Purpose Register 0 - AES Column Operation command..General Purpose Register 8 - AES Column Operation command, array offset: 0xB08, array step: 0x4 */
       uint8_t RESERVED_7[20];
  __O  uint32_t AESIC_CASR;                        /**< Status register - AES Inverse Column Operation command, offset: 0xB40 */
  __O  uint32_t AESIC_CAA;                         /**< Accumulator register - AES Inverse Column Operation command, offset: 0xB44 */
  __O  uint32_t AESIC_CA[CAU_AESIC_CA_COUNT];      /**< General Purpose Register 0 - AES Inverse Column Operation command..General Purpose Register 8 - AES Inverse Column Operation command, array offset: 0xB48, array step: 0x4 */
} CAU_Type;

/* ----------------------------------------------------------------------------
   -- CAU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAU_Register_Masks CAU Register Masks
 * @{
 */

/*! @name DIRECT - Direct access register 0..Direct access register 15 */
/*! @{ */

#define CAU_DIRECT_CAU_DIRECT0_MASK              (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT0_SHIFT             (0U)
/*! CAU_DIRECT0 - Direct register 0 */
#define CAU_DIRECT_CAU_DIRECT0(x)                (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT0_SHIFT)) & CAU_DIRECT_CAU_DIRECT0_MASK)

#define CAU_DIRECT_CAU_DIRECT1_MASK              (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT1_SHIFT             (0U)
/*! CAU_DIRECT1 - Direct register 1 */
#define CAU_DIRECT_CAU_DIRECT1(x)                (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT1_SHIFT)) & CAU_DIRECT_CAU_DIRECT1_MASK)

#define CAU_DIRECT_CAU_DIRECT2_MASK              (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT2_SHIFT             (0U)
/*! CAU_DIRECT2 - Direct register 2 */
#define CAU_DIRECT_CAU_DIRECT2(x)                (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT2_SHIFT)) & CAU_DIRECT_CAU_DIRECT2_MASK)

#define CAU_DIRECT_CAU_DIRECT3_MASK              (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT3_SHIFT             (0U)
/*! CAU_DIRECT3 - Direct register 3 */
#define CAU_DIRECT_CAU_DIRECT3(x)                (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT3_SHIFT)) & CAU_DIRECT_CAU_DIRECT3_MASK)

#define CAU_DIRECT_CAU_DIRECT4_MASK              (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT4_SHIFT             (0U)
/*! CAU_DIRECT4 - Direct register 4 */
#define CAU_DIRECT_CAU_DIRECT4(x)                (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT4_SHIFT)) & CAU_DIRECT_CAU_DIRECT4_MASK)

#define CAU_DIRECT_CAU_DIRECT5_MASK              (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT5_SHIFT             (0U)
/*! CAU_DIRECT5 - Direct register 5 */
#define CAU_DIRECT_CAU_DIRECT5(x)                (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT5_SHIFT)) & CAU_DIRECT_CAU_DIRECT5_MASK)

#define CAU_DIRECT_CAU_DIRECT6_MASK              (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT6_SHIFT             (0U)
/*! CAU_DIRECT6 - Direct register 6 */
#define CAU_DIRECT_CAU_DIRECT6(x)                (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT6_SHIFT)) & CAU_DIRECT_CAU_DIRECT6_MASK)

#define CAU_DIRECT_CAU_DIRECT7_MASK              (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT7_SHIFT             (0U)
/*! CAU_DIRECT7 - Direct register 7 */
#define CAU_DIRECT_CAU_DIRECT7(x)                (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT7_SHIFT)) & CAU_DIRECT_CAU_DIRECT7_MASK)

#define CAU_DIRECT_CAU_DIRECT8_MASK              (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT8_SHIFT             (0U)
/*! CAU_DIRECT8 - Direct register 8 */
#define CAU_DIRECT_CAU_DIRECT8(x)                (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT8_SHIFT)) & CAU_DIRECT_CAU_DIRECT8_MASK)

#define CAU_DIRECT_CAU_DIRECT9_MASK              (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT9_SHIFT             (0U)
/*! CAU_DIRECT9 - Direct register 9 */
#define CAU_DIRECT_CAU_DIRECT9(x)                (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT9_SHIFT)) & CAU_DIRECT_CAU_DIRECT9_MASK)

#define CAU_DIRECT_CAU_DIRECT10_MASK             (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT10_SHIFT            (0U)
/*! CAU_DIRECT10 - Direct register 10 */
#define CAU_DIRECT_CAU_DIRECT10(x)               (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT10_SHIFT)) & CAU_DIRECT_CAU_DIRECT10_MASK)

#define CAU_DIRECT_CAU_DIRECT11_MASK             (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT11_SHIFT            (0U)
/*! CAU_DIRECT11 - Direct register 11 */
#define CAU_DIRECT_CAU_DIRECT11(x)               (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT11_SHIFT)) & CAU_DIRECT_CAU_DIRECT11_MASK)

#define CAU_DIRECT_CAU_DIRECT12_MASK             (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT12_SHIFT            (0U)
/*! CAU_DIRECT12 - Direct register 12 */
#define CAU_DIRECT_CAU_DIRECT12(x)               (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT12_SHIFT)) & CAU_DIRECT_CAU_DIRECT12_MASK)

#define CAU_DIRECT_CAU_DIRECT13_MASK             (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT13_SHIFT            (0U)
/*! CAU_DIRECT13 - Direct register 13 */
#define CAU_DIRECT_CAU_DIRECT13(x)               (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT13_SHIFT)) & CAU_DIRECT_CAU_DIRECT13_MASK)

#define CAU_DIRECT_CAU_DIRECT14_MASK             (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT14_SHIFT            (0U)
/*! CAU_DIRECT14 - Direct register 14 */
#define CAU_DIRECT_CAU_DIRECT14(x)               (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT14_SHIFT)) & CAU_DIRECT_CAU_DIRECT14_MASK)

#define CAU_DIRECT_CAU_DIRECT15_MASK             (0xFFFFFFFFU)
#define CAU_DIRECT_CAU_DIRECT15_SHIFT            (0U)
/*! CAU_DIRECT15 - Direct register 15 */
#define CAU_DIRECT_CAU_DIRECT15(x)               (((uint32_t)(((uint32_t)(x)) << CAU_DIRECT_CAU_DIRECT15_SHIFT)) & CAU_DIRECT_CAU_DIRECT15_MASK)
/*! @} */

/*! @name LDR_CASR - Status register - Load Register command */
/*! @{ */

#define CAU_LDR_CASR_IC_MASK                     (0x1U)
#define CAU_LDR_CASR_IC_SHIFT                    (0U)
/*! IC
 *  0b0..No illegal commands issued
 *  0b1..Illegal command issued
 */
#define CAU_LDR_CASR_IC(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_LDR_CASR_IC_SHIFT)) & CAU_LDR_CASR_IC_MASK)

#define CAU_LDR_CASR_DPE_MASK                    (0x2U)
#define CAU_LDR_CASR_DPE_SHIFT                   (1U)
/*! DPE
 *  0b0..No error detected
 *  0b1..DES key parity error detected
 */
#define CAU_LDR_CASR_DPE(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_LDR_CASR_DPE_SHIFT)) & CAU_LDR_CASR_DPE_MASK)

#define CAU_LDR_CASR_VER_MASK                    (0xF0000000U)
#define CAU_LDR_CASR_VER_SHIFT                   (28U)
/*! VER - CAU version
 *  0b0001..Initial CAU version
 *  0b0010..Second version, added support for SHA-256 algorithm.(This is the value on this device)
 */
#define CAU_LDR_CASR_VER(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_LDR_CASR_VER_SHIFT)) & CAU_LDR_CASR_VER_MASK)
/*! @} */

/*! @name LDR_CAA - Accumulator register - Load Register command */
/*! @{ */

#define CAU_LDR_CAA_ACC_MASK                     (0xFFFFFFFFU)
#define CAU_LDR_CAA_ACC_SHIFT                    (0U)
/*! ACC - ACC */
#define CAU_LDR_CAA_ACC(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_LDR_CAA_ACC_SHIFT)) & CAU_LDR_CAA_ACC_MASK)
/*! @} */

/*! @name LDR_CA - General Purpose Register 0 - Load Register command..General Purpose Register 8 - Load Register command */
/*! @{ */

#define CAU_LDR_CA_CA0_MASK                      (0xFFFFFFFFU)
#define CAU_LDR_CA_CA0_SHIFT                     (0U)
/*! CA0 - CA0 */
#define CAU_LDR_CA_CA0(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_LDR_CA_CA0_SHIFT)) & CAU_LDR_CA_CA0_MASK)

#define CAU_LDR_CA_CA1_MASK                      (0xFFFFFFFFU)
#define CAU_LDR_CA_CA1_SHIFT                     (0U)
/*! CA1 - CA1 */
#define CAU_LDR_CA_CA1(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_LDR_CA_CA1_SHIFT)) & CAU_LDR_CA_CA1_MASK)

#define CAU_LDR_CA_CA2_MASK                      (0xFFFFFFFFU)
#define CAU_LDR_CA_CA2_SHIFT                     (0U)
/*! CA2 - CA2 */
#define CAU_LDR_CA_CA2(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_LDR_CA_CA2_SHIFT)) & CAU_LDR_CA_CA2_MASK)

#define CAU_LDR_CA_CA3_MASK                      (0xFFFFFFFFU)
#define CAU_LDR_CA_CA3_SHIFT                     (0U)
/*! CA3 - CA3 */
#define CAU_LDR_CA_CA3(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_LDR_CA_CA3_SHIFT)) & CAU_LDR_CA_CA3_MASK)

#define CAU_LDR_CA_CA4_MASK                      (0xFFFFFFFFU)
#define CAU_LDR_CA_CA4_SHIFT                     (0U)
/*! CA4 - CA4 */
#define CAU_LDR_CA_CA4(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_LDR_CA_CA4_SHIFT)) & CAU_LDR_CA_CA4_MASK)

#define CAU_LDR_CA_CA5_MASK                      (0xFFFFFFFFU)
#define CAU_LDR_CA_CA5_SHIFT                     (0U)
/*! CA5 - CA5 */
#define CAU_LDR_CA_CA5(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_LDR_CA_CA5_SHIFT)) & CAU_LDR_CA_CA5_MASK)

#define CAU_LDR_CA_CA6_MASK                      (0xFFFFFFFFU)
#define CAU_LDR_CA_CA6_SHIFT                     (0U)
/*! CA6 - CA6 */
#define CAU_LDR_CA_CA6(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_LDR_CA_CA6_SHIFT)) & CAU_LDR_CA_CA6_MASK)

#define CAU_LDR_CA_CA7_MASK                      (0xFFFFFFFFU)
#define CAU_LDR_CA_CA7_SHIFT                     (0U)
/*! CA7 - CA7 */
#define CAU_LDR_CA_CA7(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_LDR_CA_CA7_SHIFT)) & CAU_LDR_CA_CA7_MASK)

#define CAU_LDR_CA_CA8_MASK                      (0xFFFFFFFFU)
#define CAU_LDR_CA_CA8_SHIFT                     (0U)
/*! CA8 - CA8 */
#define CAU_LDR_CA_CA8(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_LDR_CA_CA8_SHIFT)) & CAU_LDR_CA_CA8_MASK)
/*! @} */

/*! @name STR_CASR - Status register - Store Register command */
/*! @{ */

#define CAU_STR_CASR_IC_MASK                     (0x1U)
#define CAU_STR_CASR_IC_SHIFT                    (0U)
/*! IC
 *  0b0..No illegal commands issued
 *  0b1..Illegal command issued
 */
#define CAU_STR_CASR_IC(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_STR_CASR_IC_SHIFT)) & CAU_STR_CASR_IC_MASK)

#define CAU_STR_CASR_DPE_MASK                    (0x2U)
#define CAU_STR_CASR_DPE_SHIFT                   (1U)
/*! DPE
 *  0b0..No error detected
 *  0b1..DES key parity error detected
 */
#define CAU_STR_CASR_DPE(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_STR_CASR_DPE_SHIFT)) & CAU_STR_CASR_DPE_MASK)

#define CAU_STR_CASR_VER_MASK                    (0xF0000000U)
#define CAU_STR_CASR_VER_SHIFT                   (28U)
/*! VER - CAU version
 *  0b0001..Initial CAU version
 *  0b0010..Second version, added support for SHA-256 algorithm.(This is the value on this device)
 */
#define CAU_STR_CASR_VER(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_STR_CASR_VER_SHIFT)) & CAU_STR_CASR_VER_MASK)
/*! @} */

/*! @name STR_CAA - Accumulator register - Store Register command */
/*! @{ */

#define CAU_STR_CAA_ACC_MASK                     (0xFFFFFFFFU)
#define CAU_STR_CAA_ACC_SHIFT                    (0U)
/*! ACC - ACC */
#define CAU_STR_CAA_ACC(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_STR_CAA_ACC_SHIFT)) & CAU_STR_CAA_ACC_MASK)
/*! @} */

/*! @name STR_CA - General Purpose Register 0 - Store Register command..General Purpose Register 8 - Store Register command */
/*! @{ */

#define CAU_STR_CA_CA0_MASK                      (0xFFFFFFFFU)
#define CAU_STR_CA_CA0_SHIFT                     (0U)
/*! CA0 - CA0 */
#define CAU_STR_CA_CA0(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_STR_CA_CA0_SHIFT)) & CAU_STR_CA_CA0_MASK)

#define CAU_STR_CA_CA1_MASK                      (0xFFFFFFFFU)
#define CAU_STR_CA_CA1_SHIFT                     (0U)
/*! CA1 - CA1 */
#define CAU_STR_CA_CA1(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_STR_CA_CA1_SHIFT)) & CAU_STR_CA_CA1_MASK)

#define CAU_STR_CA_CA2_MASK                      (0xFFFFFFFFU)
#define CAU_STR_CA_CA2_SHIFT                     (0U)
/*! CA2 - CA2 */
#define CAU_STR_CA_CA2(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_STR_CA_CA2_SHIFT)) & CAU_STR_CA_CA2_MASK)

#define CAU_STR_CA_CA3_MASK                      (0xFFFFFFFFU)
#define CAU_STR_CA_CA3_SHIFT                     (0U)
/*! CA3 - CA3 */
#define CAU_STR_CA_CA3(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_STR_CA_CA3_SHIFT)) & CAU_STR_CA_CA3_MASK)

#define CAU_STR_CA_CA4_MASK                      (0xFFFFFFFFU)
#define CAU_STR_CA_CA4_SHIFT                     (0U)
/*! CA4 - CA4 */
#define CAU_STR_CA_CA4(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_STR_CA_CA4_SHIFT)) & CAU_STR_CA_CA4_MASK)

#define CAU_STR_CA_CA5_MASK                      (0xFFFFFFFFU)
#define CAU_STR_CA_CA5_SHIFT                     (0U)
/*! CA5 - CA5 */
#define CAU_STR_CA_CA5(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_STR_CA_CA5_SHIFT)) & CAU_STR_CA_CA5_MASK)

#define CAU_STR_CA_CA6_MASK                      (0xFFFFFFFFU)
#define CAU_STR_CA_CA6_SHIFT                     (0U)
/*! CA6 - CA6 */
#define CAU_STR_CA_CA6(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_STR_CA_CA6_SHIFT)) & CAU_STR_CA_CA6_MASK)

#define CAU_STR_CA_CA7_MASK                      (0xFFFFFFFFU)
#define CAU_STR_CA_CA7_SHIFT                     (0U)
/*! CA7 - CA7 */
#define CAU_STR_CA_CA7(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_STR_CA_CA7_SHIFT)) & CAU_STR_CA_CA7_MASK)

#define CAU_STR_CA_CA8_MASK                      (0xFFFFFFFFU)
#define CAU_STR_CA_CA8_SHIFT                     (0U)
/*! CA8 - CA8 */
#define CAU_STR_CA_CA8(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_STR_CA_CA8_SHIFT)) & CAU_STR_CA_CA8_MASK)
/*! @} */

/*! @name ADR_CASR - Status register - Add Register command */
/*! @{ */

#define CAU_ADR_CASR_IC_MASK                     (0x1U)
#define CAU_ADR_CASR_IC_SHIFT                    (0U)
/*! IC
 *  0b0..No illegal commands issued
 *  0b1..Illegal command issued
 */
#define CAU_ADR_CASR_IC(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_ADR_CASR_IC_SHIFT)) & CAU_ADR_CASR_IC_MASK)

#define CAU_ADR_CASR_DPE_MASK                    (0x2U)
#define CAU_ADR_CASR_DPE_SHIFT                   (1U)
/*! DPE
 *  0b0..No error detected
 *  0b1..DES key parity error detected
 */
#define CAU_ADR_CASR_DPE(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_ADR_CASR_DPE_SHIFT)) & CAU_ADR_CASR_DPE_MASK)

#define CAU_ADR_CASR_VER_MASK                    (0xF0000000U)
#define CAU_ADR_CASR_VER_SHIFT                   (28U)
/*! VER - CAU version
 *  0b0001..Initial CAU version
 *  0b0010..Second version, added support for SHA-256 algorithm.(This is the value on this device)
 */
#define CAU_ADR_CASR_VER(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_ADR_CASR_VER_SHIFT)) & CAU_ADR_CASR_VER_MASK)
/*! @} */

/*! @name ADR_CAA - Accumulator register - Add to register command */
/*! @{ */

#define CAU_ADR_CAA_ACC_MASK                     (0xFFFFFFFFU)
#define CAU_ADR_CAA_ACC_SHIFT                    (0U)
/*! ACC - ACC */
#define CAU_ADR_CAA_ACC(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_ADR_CAA_ACC_SHIFT)) & CAU_ADR_CAA_ACC_MASK)
/*! @} */

/*! @name ADR_CA - General Purpose Register 0 - Add to register command..General Purpose Register 8 - Add to register command */
/*! @{ */

#define CAU_ADR_CA_CA0_MASK                      (0xFFFFFFFFU)
#define CAU_ADR_CA_CA0_SHIFT                     (0U)
/*! CA0 - CA0 */
#define CAU_ADR_CA_CA0(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_ADR_CA_CA0_SHIFT)) & CAU_ADR_CA_CA0_MASK)

#define CAU_ADR_CA_CA1_MASK                      (0xFFFFFFFFU)
#define CAU_ADR_CA_CA1_SHIFT                     (0U)
/*! CA1 - CA1 */
#define CAU_ADR_CA_CA1(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_ADR_CA_CA1_SHIFT)) & CAU_ADR_CA_CA1_MASK)

#define CAU_ADR_CA_CA2_MASK                      (0xFFFFFFFFU)
#define CAU_ADR_CA_CA2_SHIFT                     (0U)
/*! CA2 - CA2 */
#define CAU_ADR_CA_CA2(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_ADR_CA_CA2_SHIFT)) & CAU_ADR_CA_CA2_MASK)

#define CAU_ADR_CA_CA3_MASK                      (0xFFFFFFFFU)
#define CAU_ADR_CA_CA3_SHIFT                     (0U)
/*! CA3 - CA3 */
#define CAU_ADR_CA_CA3(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_ADR_CA_CA3_SHIFT)) & CAU_ADR_CA_CA3_MASK)

#define CAU_ADR_CA_CA4_MASK                      (0xFFFFFFFFU)
#define CAU_ADR_CA_CA4_SHIFT                     (0U)
/*! CA4 - CA4 */
#define CAU_ADR_CA_CA4(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_ADR_CA_CA4_SHIFT)) & CAU_ADR_CA_CA4_MASK)

#define CAU_ADR_CA_CA5_MASK                      (0xFFFFFFFFU)
#define CAU_ADR_CA_CA5_SHIFT                     (0U)
/*! CA5 - CA5 */
#define CAU_ADR_CA_CA5(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_ADR_CA_CA5_SHIFT)) & CAU_ADR_CA_CA5_MASK)

#define CAU_ADR_CA_CA6_MASK                      (0xFFFFFFFFU)
#define CAU_ADR_CA_CA6_SHIFT                     (0U)
/*! CA6 - CA6 */
#define CAU_ADR_CA_CA6(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_ADR_CA_CA6_SHIFT)) & CAU_ADR_CA_CA6_MASK)

#define CAU_ADR_CA_CA7_MASK                      (0xFFFFFFFFU)
#define CAU_ADR_CA_CA7_SHIFT                     (0U)
/*! CA7 - CA7 */
#define CAU_ADR_CA_CA7(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_ADR_CA_CA7_SHIFT)) & CAU_ADR_CA_CA7_MASK)

#define CAU_ADR_CA_CA8_MASK                      (0xFFFFFFFFU)
#define CAU_ADR_CA_CA8_SHIFT                     (0U)
/*! CA8 - CA8 */
#define CAU_ADR_CA_CA8(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_ADR_CA_CA8_SHIFT)) & CAU_ADR_CA_CA8_MASK)
/*! @} */

/*! @name RADR_CASR - Status register - Reverse and Add to Register command */
/*! @{ */

#define CAU_RADR_CASR_IC_MASK                    (0x1U)
#define CAU_RADR_CASR_IC_SHIFT                   (0U)
/*! IC
 *  0b0..No illegal commands issued
 *  0b1..Illegal command issued
 */
#define CAU_RADR_CASR_IC(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_RADR_CASR_IC_SHIFT)) & CAU_RADR_CASR_IC_MASK)

#define CAU_RADR_CASR_DPE_MASK                   (0x2U)
#define CAU_RADR_CASR_DPE_SHIFT                  (1U)
/*! DPE
 *  0b0..No error detected
 *  0b1..DES key parity error detected
 */
#define CAU_RADR_CASR_DPE(x)                     (((uint32_t)(((uint32_t)(x)) << CAU_RADR_CASR_DPE_SHIFT)) & CAU_RADR_CASR_DPE_MASK)

#define CAU_RADR_CASR_VER_MASK                   (0xF0000000U)
#define CAU_RADR_CASR_VER_SHIFT                  (28U)
/*! VER - CAU version
 *  0b0001..Initial CAU version
 *  0b0010..Second version, added support for SHA-256 algorithm.(This is the value on this device)
 */
#define CAU_RADR_CASR_VER(x)                     (((uint32_t)(((uint32_t)(x)) << CAU_RADR_CASR_VER_SHIFT)) & CAU_RADR_CASR_VER_MASK)
/*! @} */

/*! @name RADR_CAA - Accumulator register - Reverse and Add to Register command */
/*! @{ */

#define CAU_RADR_CAA_ACC_MASK                    (0xFFFFFFFFU)
#define CAU_RADR_CAA_ACC_SHIFT                   (0U)
/*! ACC - ACC */
#define CAU_RADR_CAA_ACC(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_RADR_CAA_ACC_SHIFT)) & CAU_RADR_CAA_ACC_MASK)
/*! @} */

/*! @name RADR_CA - General Purpose Register 0 - Reverse and Add to Register command..General Purpose Register 8 - Reverse and Add to Register command */
/*! @{ */

#define CAU_RADR_CA_CA0_MASK                     (0xFFFFFFFFU)
#define CAU_RADR_CA_CA0_SHIFT                    (0U)
/*! CA0 - CA0 */
#define CAU_RADR_CA_CA0(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_RADR_CA_CA0_SHIFT)) & CAU_RADR_CA_CA0_MASK)

#define CAU_RADR_CA_CA1_MASK                     (0xFFFFFFFFU)
#define CAU_RADR_CA_CA1_SHIFT                    (0U)
/*! CA1 - CA1 */
#define CAU_RADR_CA_CA1(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_RADR_CA_CA1_SHIFT)) & CAU_RADR_CA_CA1_MASK)

#define CAU_RADR_CA_CA2_MASK                     (0xFFFFFFFFU)
#define CAU_RADR_CA_CA2_SHIFT                    (0U)
/*! CA2 - CA2 */
#define CAU_RADR_CA_CA2(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_RADR_CA_CA2_SHIFT)) & CAU_RADR_CA_CA2_MASK)

#define CAU_RADR_CA_CA3_MASK                     (0xFFFFFFFFU)
#define CAU_RADR_CA_CA3_SHIFT                    (0U)
/*! CA3 - CA3 */
#define CAU_RADR_CA_CA3(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_RADR_CA_CA3_SHIFT)) & CAU_RADR_CA_CA3_MASK)

#define CAU_RADR_CA_CA4_MASK                     (0xFFFFFFFFU)
#define CAU_RADR_CA_CA4_SHIFT                    (0U)
/*! CA4 - CA4 */
#define CAU_RADR_CA_CA4(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_RADR_CA_CA4_SHIFT)) & CAU_RADR_CA_CA4_MASK)

#define CAU_RADR_CA_CA5_MASK                     (0xFFFFFFFFU)
#define CAU_RADR_CA_CA5_SHIFT                    (0U)
/*! CA5 - CA5 */
#define CAU_RADR_CA_CA5(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_RADR_CA_CA5_SHIFT)) & CAU_RADR_CA_CA5_MASK)

#define CAU_RADR_CA_CA6_MASK                     (0xFFFFFFFFU)
#define CAU_RADR_CA_CA6_SHIFT                    (0U)
/*! CA6 - CA6 */
#define CAU_RADR_CA_CA6(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_RADR_CA_CA6_SHIFT)) & CAU_RADR_CA_CA6_MASK)

#define CAU_RADR_CA_CA7_MASK                     (0xFFFFFFFFU)
#define CAU_RADR_CA_CA7_SHIFT                    (0U)
/*! CA7 - CA7 */
#define CAU_RADR_CA_CA7(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_RADR_CA_CA7_SHIFT)) & CAU_RADR_CA_CA7_MASK)

#define CAU_RADR_CA_CA8_MASK                     (0xFFFFFFFFU)
#define CAU_RADR_CA_CA8_SHIFT                    (0U)
/*! CA8 - CA8 */
#define CAU_RADR_CA_CA8(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_RADR_CA_CA8_SHIFT)) & CAU_RADR_CA_CA8_MASK)
/*! @} */

/*! @name XOR_CASR - Status register - Exclusive Or command */
/*! @{ */

#define CAU_XOR_CASR_IC_MASK                     (0x1U)
#define CAU_XOR_CASR_IC_SHIFT                    (0U)
/*! IC
 *  0b0..No illegal commands issued
 *  0b1..Illegal command issued
 */
#define CAU_XOR_CASR_IC(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_XOR_CASR_IC_SHIFT)) & CAU_XOR_CASR_IC_MASK)

#define CAU_XOR_CASR_DPE_MASK                    (0x2U)
#define CAU_XOR_CASR_DPE_SHIFT                   (1U)
/*! DPE
 *  0b0..No error detected
 *  0b1..DES key parity error detected
 */
#define CAU_XOR_CASR_DPE(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_XOR_CASR_DPE_SHIFT)) & CAU_XOR_CASR_DPE_MASK)

#define CAU_XOR_CASR_VER_MASK                    (0xF0000000U)
#define CAU_XOR_CASR_VER_SHIFT                   (28U)
/*! VER - CAU version
 *  0b0001..Initial CAU version
 *  0b0010..Second version, added support for SHA-256 algorithm.(This is the value on this device)
 */
#define CAU_XOR_CASR_VER(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_XOR_CASR_VER_SHIFT)) & CAU_XOR_CASR_VER_MASK)
/*! @} */

/*! @name XOR_CAA - Accumulator register - Exclusive Or command */
/*! @{ */

#define CAU_XOR_CAA_ACC_MASK                     (0xFFFFFFFFU)
#define CAU_XOR_CAA_ACC_SHIFT                    (0U)
/*! ACC - ACC */
#define CAU_XOR_CAA_ACC(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_XOR_CAA_ACC_SHIFT)) & CAU_XOR_CAA_ACC_MASK)
/*! @} */

/*! @name XOR_CA - General Purpose Register 0 - Exclusive Or command..General Purpose Register 8 - Exclusive Or command */
/*! @{ */

#define CAU_XOR_CA_CA0_MASK                      (0xFFFFFFFFU)
#define CAU_XOR_CA_CA0_SHIFT                     (0U)
/*! CA0 - CA0 */
#define CAU_XOR_CA_CA0(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_XOR_CA_CA0_SHIFT)) & CAU_XOR_CA_CA0_MASK)

#define CAU_XOR_CA_CA1_MASK                      (0xFFFFFFFFU)
#define CAU_XOR_CA_CA1_SHIFT                     (0U)
/*! CA1 - CA1 */
#define CAU_XOR_CA_CA1(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_XOR_CA_CA1_SHIFT)) & CAU_XOR_CA_CA1_MASK)

#define CAU_XOR_CA_CA2_MASK                      (0xFFFFFFFFU)
#define CAU_XOR_CA_CA2_SHIFT                     (0U)
/*! CA2 - CA2 */
#define CAU_XOR_CA_CA2(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_XOR_CA_CA2_SHIFT)) & CAU_XOR_CA_CA2_MASK)

#define CAU_XOR_CA_CA3_MASK                      (0xFFFFFFFFU)
#define CAU_XOR_CA_CA3_SHIFT                     (0U)
/*! CA3 - CA3 */
#define CAU_XOR_CA_CA3(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_XOR_CA_CA3_SHIFT)) & CAU_XOR_CA_CA3_MASK)

#define CAU_XOR_CA_CA4_MASK                      (0xFFFFFFFFU)
#define CAU_XOR_CA_CA4_SHIFT                     (0U)
/*! CA4 - CA4 */
#define CAU_XOR_CA_CA4(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_XOR_CA_CA4_SHIFT)) & CAU_XOR_CA_CA4_MASK)

#define CAU_XOR_CA_CA5_MASK                      (0xFFFFFFFFU)
#define CAU_XOR_CA_CA5_SHIFT                     (0U)
/*! CA5 - CA5 */
#define CAU_XOR_CA_CA5(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_XOR_CA_CA5_SHIFT)) & CAU_XOR_CA_CA5_MASK)

#define CAU_XOR_CA_CA6_MASK                      (0xFFFFFFFFU)
#define CAU_XOR_CA_CA6_SHIFT                     (0U)
/*! CA6 - CA6 */
#define CAU_XOR_CA_CA6(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_XOR_CA_CA6_SHIFT)) & CAU_XOR_CA_CA6_MASK)

#define CAU_XOR_CA_CA7_MASK                      (0xFFFFFFFFU)
#define CAU_XOR_CA_CA7_SHIFT                     (0U)
/*! CA7 - CA7 */
#define CAU_XOR_CA_CA7(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_XOR_CA_CA7_SHIFT)) & CAU_XOR_CA_CA7_MASK)

#define CAU_XOR_CA_CA8_MASK                      (0xFFFFFFFFU)
#define CAU_XOR_CA_CA8_SHIFT                     (0U)
/*! CA8 - CA8 */
#define CAU_XOR_CA_CA8(x)                        (((uint32_t)(((uint32_t)(x)) << CAU_XOR_CA_CA8_SHIFT)) & CAU_XOR_CA_CA8_MASK)
/*! @} */

/*! @name ROTL_CASR - Status register - Rotate Left command */
/*! @{ */

#define CAU_ROTL_CASR_IC_MASK                    (0x1U)
#define CAU_ROTL_CASR_IC_SHIFT                   (0U)
/*! IC
 *  0b0..No illegal commands issued
 *  0b1..Illegal command issued
 */
#define CAU_ROTL_CASR_IC(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_ROTL_CASR_IC_SHIFT)) & CAU_ROTL_CASR_IC_MASK)

#define CAU_ROTL_CASR_DPE_MASK                   (0x2U)
#define CAU_ROTL_CASR_DPE_SHIFT                  (1U)
/*! DPE
 *  0b0..No error detected
 *  0b1..DES key parity error detected
 */
#define CAU_ROTL_CASR_DPE(x)                     (((uint32_t)(((uint32_t)(x)) << CAU_ROTL_CASR_DPE_SHIFT)) & CAU_ROTL_CASR_DPE_MASK)

#define CAU_ROTL_CASR_VER_MASK                   (0xF0000000U)
#define CAU_ROTL_CASR_VER_SHIFT                  (28U)
/*! VER - CAU version
 *  0b0001..Initial CAU version
 *  0b0010..Second version, added support for SHA-256 algorithm.(This is the value on this device)
 */
#define CAU_ROTL_CASR_VER(x)                     (((uint32_t)(((uint32_t)(x)) << CAU_ROTL_CASR_VER_SHIFT)) & CAU_ROTL_CASR_VER_MASK)
/*! @} */

/*! @name ROTL_CAA - Accumulator register - Rotate Left command */
/*! @{ */

#define CAU_ROTL_CAA_ACC_MASK                    (0xFFFFFFFFU)
#define CAU_ROTL_CAA_ACC_SHIFT                   (0U)
/*! ACC - ACC */
#define CAU_ROTL_CAA_ACC(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_ROTL_CAA_ACC_SHIFT)) & CAU_ROTL_CAA_ACC_MASK)
/*! @} */

/*! @name ROTL_CA - General Purpose Register 0 - Rotate Left command..General Purpose Register 8 - Rotate Left command */
/*! @{ */

#define CAU_ROTL_CA_CA0_MASK                     (0xFFFFFFFFU)
#define CAU_ROTL_CA_CA0_SHIFT                    (0U)
/*! CA0 - CA0 */
#define CAU_ROTL_CA_CA0(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_ROTL_CA_CA0_SHIFT)) & CAU_ROTL_CA_CA0_MASK)

#define CAU_ROTL_CA_CA1_MASK                     (0xFFFFFFFFU)
#define CAU_ROTL_CA_CA1_SHIFT                    (0U)
/*! CA1 - CA1 */
#define CAU_ROTL_CA_CA1(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_ROTL_CA_CA1_SHIFT)) & CAU_ROTL_CA_CA1_MASK)

#define CAU_ROTL_CA_CA2_MASK                     (0xFFFFFFFFU)
#define CAU_ROTL_CA_CA2_SHIFT                    (0U)
/*! CA2 - CA2 */
#define CAU_ROTL_CA_CA2(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_ROTL_CA_CA2_SHIFT)) & CAU_ROTL_CA_CA2_MASK)

#define CAU_ROTL_CA_CA3_MASK                     (0xFFFFFFFFU)
#define CAU_ROTL_CA_CA3_SHIFT                    (0U)
/*! CA3 - CA3 */
#define CAU_ROTL_CA_CA3(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_ROTL_CA_CA3_SHIFT)) & CAU_ROTL_CA_CA3_MASK)

#define CAU_ROTL_CA_CA4_MASK                     (0xFFFFFFFFU)
#define CAU_ROTL_CA_CA4_SHIFT                    (0U)
/*! CA4 - CA4 */
#define CAU_ROTL_CA_CA4(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_ROTL_CA_CA4_SHIFT)) & CAU_ROTL_CA_CA4_MASK)

#define CAU_ROTL_CA_CA5_MASK                     (0xFFFFFFFFU)
#define CAU_ROTL_CA_CA5_SHIFT                    (0U)
/*! CA5 - CA5 */
#define CAU_ROTL_CA_CA5(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_ROTL_CA_CA5_SHIFT)) & CAU_ROTL_CA_CA5_MASK)

#define CAU_ROTL_CA_CA6_MASK                     (0xFFFFFFFFU)
#define CAU_ROTL_CA_CA6_SHIFT                    (0U)
/*! CA6 - CA6 */
#define CAU_ROTL_CA_CA6(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_ROTL_CA_CA6_SHIFT)) & CAU_ROTL_CA_CA6_MASK)

#define CAU_ROTL_CA_CA7_MASK                     (0xFFFFFFFFU)
#define CAU_ROTL_CA_CA7_SHIFT                    (0U)
/*! CA7 - CA7 */
#define CAU_ROTL_CA_CA7(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_ROTL_CA_CA7_SHIFT)) & CAU_ROTL_CA_CA7_MASK)

#define CAU_ROTL_CA_CA8_MASK                     (0xFFFFFFFFU)
#define CAU_ROTL_CA_CA8_SHIFT                    (0U)
/*! CA8 - CA8 */
#define CAU_ROTL_CA_CA8(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_ROTL_CA_CA8_SHIFT)) & CAU_ROTL_CA_CA8_MASK)
/*! @} */

/*! @name AESC_CASR - Status register - AES Column Operation command */
/*! @{ */

#define CAU_AESC_CASR_IC_MASK                    (0x1U)
#define CAU_AESC_CASR_IC_SHIFT                   (0U)
/*! IC
 *  0b0..No illegal commands issued
 *  0b1..Illegal command issued
 */
#define CAU_AESC_CASR_IC(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_AESC_CASR_IC_SHIFT)) & CAU_AESC_CASR_IC_MASK)

#define CAU_AESC_CASR_DPE_MASK                   (0x2U)
#define CAU_AESC_CASR_DPE_SHIFT                  (1U)
/*! DPE
 *  0b0..No error detected
 *  0b1..DES key parity error detected
 */
#define CAU_AESC_CASR_DPE(x)                     (((uint32_t)(((uint32_t)(x)) << CAU_AESC_CASR_DPE_SHIFT)) & CAU_AESC_CASR_DPE_MASK)

#define CAU_AESC_CASR_VER_MASK                   (0xF0000000U)
#define CAU_AESC_CASR_VER_SHIFT                  (28U)
/*! VER - CAU version
 *  0b0001..Initial CAU version
 *  0b0010..Second version, added support for SHA-256 algorithm.(This is the value on this device)
 */
#define CAU_AESC_CASR_VER(x)                     (((uint32_t)(((uint32_t)(x)) << CAU_AESC_CASR_VER_SHIFT)) & CAU_AESC_CASR_VER_MASK)
/*! @} */

/*! @name AESC_CAA - Accumulator register - AES Column Operation command */
/*! @{ */

#define CAU_AESC_CAA_ACC_MASK                    (0xFFFFFFFFU)
#define CAU_AESC_CAA_ACC_SHIFT                   (0U)
/*! ACC - ACC */
#define CAU_AESC_CAA_ACC(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_AESC_CAA_ACC_SHIFT)) & CAU_AESC_CAA_ACC_MASK)
/*! @} */

/*! @name AESC_CA - General Purpose Register 0 - AES Column Operation command..General Purpose Register 8 - AES Column Operation command */
/*! @{ */

#define CAU_AESC_CA_CA0_MASK                     (0xFFFFFFFFU)
#define CAU_AESC_CA_CA0_SHIFT                    (0U)
/*! CA0 - CA0 */
#define CAU_AESC_CA_CA0(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_AESC_CA_CA0_SHIFT)) & CAU_AESC_CA_CA0_MASK)

#define CAU_AESC_CA_CA1_MASK                     (0xFFFFFFFFU)
#define CAU_AESC_CA_CA1_SHIFT                    (0U)
/*! CA1 - CA1 */
#define CAU_AESC_CA_CA1(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_AESC_CA_CA1_SHIFT)) & CAU_AESC_CA_CA1_MASK)

#define CAU_AESC_CA_CA2_MASK                     (0xFFFFFFFFU)
#define CAU_AESC_CA_CA2_SHIFT                    (0U)
/*! CA2 - CA2 */
#define CAU_AESC_CA_CA2(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_AESC_CA_CA2_SHIFT)) & CAU_AESC_CA_CA2_MASK)

#define CAU_AESC_CA_CA3_MASK                     (0xFFFFFFFFU)
#define CAU_AESC_CA_CA3_SHIFT                    (0U)
/*! CA3 - CA3 */
#define CAU_AESC_CA_CA3(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_AESC_CA_CA3_SHIFT)) & CAU_AESC_CA_CA3_MASK)

#define CAU_AESC_CA_CA4_MASK                     (0xFFFFFFFFU)
#define CAU_AESC_CA_CA4_SHIFT                    (0U)
/*! CA4 - CA4 */
#define CAU_AESC_CA_CA4(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_AESC_CA_CA4_SHIFT)) & CAU_AESC_CA_CA4_MASK)

#define CAU_AESC_CA_CA5_MASK                     (0xFFFFFFFFU)
#define CAU_AESC_CA_CA5_SHIFT                    (0U)
/*! CA5 - CA5 */
#define CAU_AESC_CA_CA5(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_AESC_CA_CA5_SHIFT)) & CAU_AESC_CA_CA5_MASK)

#define CAU_AESC_CA_CA6_MASK                     (0xFFFFFFFFU)
#define CAU_AESC_CA_CA6_SHIFT                    (0U)
/*! CA6 - CA6 */
#define CAU_AESC_CA_CA6(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_AESC_CA_CA6_SHIFT)) & CAU_AESC_CA_CA6_MASK)

#define CAU_AESC_CA_CA7_MASK                     (0xFFFFFFFFU)
#define CAU_AESC_CA_CA7_SHIFT                    (0U)
/*! CA7 - CA7 */
#define CAU_AESC_CA_CA7(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_AESC_CA_CA7_SHIFT)) & CAU_AESC_CA_CA7_MASK)

#define CAU_AESC_CA_CA8_MASK                     (0xFFFFFFFFU)
#define CAU_AESC_CA_CA8_SHIFT                    (0U)
/*! CA8 - CA8 */
#define CAU_AESC_CA_CA8(x)                       (((uint32_t)(((uint32_t)(x)) << CAU_AESC_CA_CA8_SHIFT)) & CAU_AESC_CA_CA8_MASK)
/*! @} */

/*! @name AESIC_CASR - Status register - AES Inverse Column Operation command */
/*! @{ */

#define CAU_AESIC_CASR_IC_MASK                   (0x1U)
#define CAU_AESIC_CASR_IC_SHIFT                  (0U)
/*! IC
 *  0b0..No illegal commands issued
 *  0b1..Illegal command issued
 */
#define CAU_AESIC_CASR_IC(x)                     (((uint32_t)(((uint32_t)(x)) << CAU_AESIC_CASR_IC_SHIFT)) & CAU_AESIC_CASR_IC_MASK)

#define CAU_AESIC_CASR_DPE_MASK                  (0x2U)
#define CAU_AESIC_CASR_DPE_SHIFT                 (1U)
/*! DPE
 *  0b0..No error detected
 *  0b1..DES key parity error detected
 */
#define CAU_AESIC_CASR_DPE(x)                    (((uint32_t)(((uint32_t)(x)) << CAU_AESIC_CASR_DPE_SHIFT)) & CAU_AESIC_CASR_DPE_MASK)

#define CAU_AESIC_CASR_VER_MASK                  (0xF0000000U)
#define CAU_AESIC_CASR_VER_SHIFT                 (28U)
/*! VER - CAU version
 *  0b0001..Initial CAU version
 *  0b0010..Second version, added support for SHA-256 algorithm.(This is the value on this device)
 */
#define CAU_AESIC_CASR_VER(x)                    (((uint32_t)(((uint32_t)(x)) << CAU_AESIC_CASR_VER_SHIFT)) & CAU_AESIC_CASR_VER_MASK)
/*! @} */

/*! @name AESIC_CAA - Accumulator register - AES Inverse Column Operation command */
/*! @{ */

#define CAU_AESIC_CAA_ACC_MASK                   (0xFFFFFFFFU)
#define CAU_AESIC_CAA_ACC_SHIFT                  (0U)
/*! ACC - ACC */
#define CAU_AESIC_CAA_ACC(x)                     (((uint32_t)(((uint32_t)(x)) << CAU_AESIC_CAA_ACC_SHIFT)) & CAU_AESIC_CAA_ACC_MASK)
/*! @} */

/*! @name AESIC_CA - General Purpose Register 0 - AES Inverse Column Operation command..General Purpose Register 8 - AES Inverse Column Operation command */
/*! @{ */

#define CAU_AESIC_CA_CA0_MASK                    (0xFFFFFFFFU)
#define CAU_AESIC_CA_CA0_SHIFT                   (0U)
/*! CA0 - CA0 */
#define CAU_AESIC_CA_CA0(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_AESIC_CA_CA0_SHIFT)) & CAU_AESIC_CA_CA0_MASK)

#define CAU_AESIC_CA_CA1_MASK                    (0xFFFFFFFFU)
#define CAU_AESIC_CA_CA1_SHIFT                   (0U)
/*! CA1 - CA1 */
#define CAU_AESIC_CA_CA1(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_AESIC_CA_CA1_SHIFT)) & CAU_AESIC_CA_CA1_MASK)

#define CAU_AESIC_CA_CA2_MASK                    (0xFFFFFFFFU)
#define CAU_AESIC_CA_CA2_SHIFT                   (0U)
/*! CA2 - CA2 */
#define CAU_AESIC_CA_CA2(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_AESIC_CA_CA2_SHIFT)) & CAU_AESIC_CA_CA2_MASK)

#define CAU_AESIC_CA_CA3_MASK                    (0xFFFFFFFFU)
#define CAU_AESIC_CA_CA3_SHIFT                   (0U)
/*! CA3 - CA3 */
#define CAU_AESIC_CA_CA3(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_AESIC_CA_CA3_SHIFT)) & CAU_AESIC_CA_CA3_MASK)

#define CAU_AESIC_CA_CA4_MASK                    (0xFFFFFFFFU)
#define CAU_AESIC_CA_CA4_SHIFT                   (0U)
/*! CA4 - CA4 */
#define CAU_AESIC_CA_CA4(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_AESIC_CA_CA4_SHIFT)) & CAU_AESIC_CA_CA4_MASK)

#define CAU_AESIC_CA_CA5_MASK                    (0xFFFFFFFFU)
#define CAU_AESIC_CA_CA5_SHIFT                   (0U)
/*! CA5 - CA5 */
#define CAU_AESIC_CA_CA5(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_AESIC_CA_CA5_SHIFT)) & CAU_AESIC_CA_CA5_MASK)

#define CAU_AESIC_CA_CA6_MASK                    (0xFFFFFFFFU)
#define CAU_AESIC_CA_CA6_SHIFT                   (0U)
/*! CA6 - CA6 */
#define CAU_AESIC_CA_CA6(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_AESIC_CA_CA6_SHIFT)) & CAU_AESIC_CA_CA6_MASK)

#define CAU_AESIC_CA_CA7_MASK                    (0xFFFFFFFFU)
#define CAU_AESIC_CA_CA7_SHIFT                   (0U)
/*! CA7 - CA7 */
#define CAU_AESIC_CA_CA7(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_AESIC_CA_CA7_SHIFT)) & CAU_AESIC_CA_CA7_MASK)

#define CAU_AESIC_CA_CA8_MASK                    (0xFFFFFFFFU)
#define CAU_AESIC_CA_CA8_SHIFT                   (0U)
/*! CA8 - CA8 */
#define CAU_AESIC_CA_CA8(x)                      (((uint32_t)(((uint32_t)(x)) << CAU_AESIC_CA_CA8_SHIFT)) & CAU_AESIC_CA_CA8_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CAU_Register_Masks */


/*!
 * @}
 */ /* end of group CAU_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_CAU_H_ */

