/*
** ###################################################################
**     Processors:          MCXE315MLF
**                          MCXE315MPA
**                          MCXE316MLF
**                          MCXE316MPA
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VIRT_WRAPPER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_VIRT_WRAPPER.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for VIRT_WRAPPER
 *
 * CMSIS Peripheral Access Layer for VIRT_WRAPPER
 */

#if !defined(PERI_VIRT_WRAPPER_H_)
#define PERI_VIRT_WRAPPER_H_                     /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE315MLF) || defined(CPU_MCXE315MPA))
#include "MCXE315_COMMON.h"
#elif (defined(CPU_MCXE316MLF) || defined(CPU_MCXE316MPA))
#include "MCXE316_COMMON.h"
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
/*!
 * @brief VIRT_WRAPPER PAC mapping slot.
 */
typedef enum _virt_wrapper_slot
{
    kVIRT_WRAPPER_PDAC0  = 0x3U, /*!< Map to PDAC0 address. */
    kVIRT_WRAPPER_PDAC1  = 0x0U, /*!< Map to PDAC1 address. */
} virt_wrapper_slot_t;
/*!
 * @brief SIUL2 virtual address mapping.
 *
 * @param siul2_addr SIUL2 peripheral address.
 * @param slot VIRT_WRAPPER slot.
 *
 * @return SIUL2 virtual address.
 */
#define SIUL2_VIRT_ADDR(siul2_addr, slot) (((uint32_t)(siul2_addr) == 0x40290000U) ? (((slot) == kVIRT_WRAPPER_PDAC1) ? 0x40298000U : (uint32_t)(siul2_addr)) : (uint32_t)(siul2_addr))


/* ----------------------------------------------------------------------------
   -- VIRT_WRAPPER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIRT_WRAPPER_Peripheral_Access_Layer VIRT_WRAPPER Peripheral Access Layer
 * @{
 */

/** VIRT_WRAPPER - Size of Registers Arrays */
#define VIRT_WRAPPER_REG_C_COUNT                  1u
#define VIRT_WRAPPER_REG_D_COUNT                  1u

/** VIRT_WRAPPER - Register Layout Typedef */
typedef struct {
  __IO uint32_t REG_A0;                            /**< Parameter_n Register, offset: 0x0 */
  __IO uint32_t REG_A1;                            /**< Parameter_n Register, offset: 0x4 */
  __IO uint32_t REG_A2;                            /**< Parameter_n Register, offset: 0x8 */
  __IO uint32_t REG_A3;                            /**< Parameter_n Register, offset: 0xC */
  __IO uint32_t REG_A4;                            /**< Parameter_n Register, offset: 0x10 */
  __IO uint32_t REG_A5;                            /**< Parameter_n Register, offset: 0x14 */
  __IO uint32_t REG_A6;                            /**< Parameter_n Register, offset: 0x18 */
  __IO uint32_t REG_A7;                            /**< Parameter_n Register, offset: 0x1C */
  __IO uint32_t REG_A8;                            /**< Parameter_n Register, offset: 0x20 */
  __IO uint32_t REG_A9;                            /**< Parameter_n Register, offset: 0x24 */
       uint8_t RESERVED_0[88];
  __IO uint32_t REG_B0;                            /**< Parameter_n Register, offset: 0x80 */
  __IO uint32_t REG_B1;                            /**< Parameter_n Register, offset: 0x84 */
  __IO uint32_t REG_B2;                            /**< Parameter_n Register, offset: 0x88 */
  __IO uint32_t REG_B3;                            /**< Parameter_n Register, offset: 0x8C */
  __IO uint32_t REG_B4;                            /**< Parameter_n Register, offset: 0x90 */
  __IO uint32_t REG_B5;                            /**< Parameter_n Register, offset: 0x94 */
  __IO uint32_t REG_B6;                            /**< Parameter_n Register, offset: 0x98 */
       uint8_t RESERVED_1[8];
  __IO uint32_t REG_B9;                            /**< Parameter_n Register, offset: 0xA4 */
  __IO uint32_t REG_B10;                           /**< Parameter_n Register, offset: 0xA8 */
  __IO uint32_t REG_B11;                           /**< Parameter_n Register, offset: 0xAC */
       uint8_t RESERVED_2[4];
  __IO uint32_t REG_B13;                           /**< Parameter_n Register, offset: 0xB4 */
  __IO uint32_t REG_B14;                           /**< Parameter_n Register, offset: 0xB8 */
  __IO uint32_t REG_B15;                           /**< Parameter_n Register, offset: 0xBC */
       uint8_t RESERVED_3[20];
  __IO uint32_t REG_B21;                           /**< Parameter_n Register, offset: 0xD4 */
  __IO uint32_t REG_B22;                           /**< Parameter_n Register, offset: 0xD8 */
  __IO uint32_t REG_B23;                           /**< Parameter_n Register, offset: 0xDC */
  __IO uint32_t REG_B24;                           /**< Parameter_n Register, offset: 0xE0 */
       uint8_t RESERVED_4[28];
  __IO uint32_t REG_C[VIRT_WRAPPER_REG_C_COUNT];   /**< Parameter_n Register, array offset: 0x100, array step: 0x4 */
  __IO uint32_t REG_D[VIRT_WRAPPER_REG_D_COUNT];   /**< Parameter_n Register, array offset: 0x104, array step: 0x4 */
} VIRT_WRAPPER_Type;

/* ----------------------------------------------------------------------------
   -- VIRT_WRAPPER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIRT_WRAPPER_Register_Masks VIRT_WRAPPER Register Masks
 * @{
 */

/*! @name REG_A0 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A0_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A0_PAD_0_SHIFT          (0U)
/*! PAD_0 - PAD_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A0_PAD_1_SHIFT          (2U)
/*! PAD_1 - PAD_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A0_PAD_2_SHIFT          (4U)
/*! PAD_2 - PAD_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A0_PAD_3_SHIFT          (6U)
/*! PAD_3 - PAD_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_4_MASK           (0x300U)
#define VIRT_WRAPPER_REG_A0_PAD_4_SHIFT          (8U)
/*! PAD_4 - PAD_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_4(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_5_MASK           (0xC00U)
#define VIRT_WRAPPER_REG_A0_PAD_5_SHIFT          (10U)
/*! PAD_5 - PAD_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_5(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_6_MASK           (0x3000U)
#define VIRT_WRAPPER_REG_A0_PAD_6_SHIFT          (12U)
/*! PAD_6 - PAD_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_6(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_7_MASK           (0xC000U)
#define VIRT_WRAPPER_REG_A0_PAD_7_SHIFT          (14U)
/*! PAD_7 - PAD_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_7(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A0_PAD_8_SHIFT          (16U)
/*! PAD_8 - PAD_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A0_PAD_9_SHIFT          (18U)
/*! PAD_9 - PAD_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A0_PAD_10_SHIFT         (20U)
/*! PAD_10 - PAD_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A0_PAD_11_SHIFT         (22U)
/*! PAD_11 - PAD_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A0_PAD_12_SHIFT         (24U)
/*! PAD_12 - PAD_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A0_PAD_13_SHIFT         (26U)
/*! PAD_13 - PAD_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_14_MASK          (0x30000000U)
#define VIRT_WRAPPER_REG_A0_PAD_14_SHIFT         (28U)
/*! PAD_14 - PAD_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_14(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A0_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A0_PAD_15_SHIFT         (30U)
/*! PAD_15 - PAD_15
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A0_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A0_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A0_PAD_15_MASK)
/*! @} */

/*! @name REG_A1 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A1_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A1_PAD_0_SHIFT          (0U)
/*! PAD_0 - PAD_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A1_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A1_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A1_PAD_1_SHIFT          (2U)
/*! PAD_1 - PAD_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A1_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A1_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A1_PAD_1_MASK)
/*! @} */

/*! @name REG_A2 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A2_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A2_PAD_0_SHIFT          (0U)
/*! PAD_0 - PAD_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A2_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A2_PAD_1_SHIFT          (2U)
/*! PAD_1 - PAD_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A2_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A2_PAD_2_SHIFT          (4U)
/*! PAD_2 - PAD_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A2_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A2_PAD_3_SHIFT          (6U)
/*! PAD_3 - PAD_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A2_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_4_MASK           (0x300U)
#define VIRT_WRAPPER_REG_A2_PAD_4_SHIFT          (8U)
/*! PAD_4 - PAD_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A2_PAD_4(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_5_MASK           (0xC00U)
#define VIRT_WRAPPER_REG_A2_PAD_5_SHIFT          (10U)
/*! PAD_5 - PAD_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A2_PAD_5(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A2_PAD_8_SHIFT          (16U)
/*! PAD_8 - PAD_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A2_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A2_PAD_9_SHIFT          (18U)
/*! PAD_9 - PAD_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A2_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A2_PAD_10_SHIFT         (20U)
/*! PAD_10 - PAD_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A2_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A2_PAD_11_SHIFT         (22U)
/*! PAD_11 - PAD_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A2_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A2_PAD_12_SHIFT         (24U)
/*! PAD_12 - PAD_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A2_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A2_PAD_13_SHIFT         (26U)
/*! PAD_13 - PAD_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A2_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_14_MASK          (0x30000000U)
#define VIRT_WRAPPER_REG_A2_PAD_14_SHIFT         (28U)
/*! PAD_14 - PAD_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A2_PAD_14(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A2_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A2_PAD_15_SHIFT         (30U)
/*! PAD_15 - PAD_15
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A2_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A2_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A2_PAD_15_MASK)
/*! @} */

/*! @name REG_A3 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A3_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A3_PAD_0_SHIFT          (0U)
/*! PAD_0 - PAD_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A3_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A3_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A3_PAD_1_SHIFT          (2U)
/*! PAD_1 - PAD_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A3_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A3_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A3_PAD_1_MASK)
/*! @} */

/*! @name REG_A4 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A4_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A4_PAD_0_SHIFT          (0U)
/*! PAD_0 - PAD_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A4_PAD_1_SHIFT          (2U)
/*! PAD_1 - PAD_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A4_PAD_2_SHIFT          (4U)
/*! PAD_2 - PAD_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A4_PAD_3_SHIFT          (6U)
/*! PAD_3 - PAD_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_4_MASK           (0x300U)
#define VIRT_WRAPPER_REG_A4_PAD_4_SHIFT          (8U)
/*! PAD_4 - PAD_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_4(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_5_MASK           (0xC00U)
#define VIRT_WRAPPER_REG_A4_PAD_5_SHIFT          (10U)
/*! PAD_5 - PAD_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_5(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_6_MASK           (0x3000U)
#define VIRT_WRAPPER_REG_A4_PAD_6_SHIFT          (12U)
/*! PAD_6 - PAD_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_6(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_7_MASK           (0xC000U)
#define VIRT_WRAPPER_REG_A4_PAD_7_SHIFT          (14U)
/*! PAD_7 - PAD_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_7(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A4_PAD_8_SHIFT          (16U)
/*! PAD_8 - PAD_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A4_PAD_9_SHIFT          (18U)
/*! PAD_9 - PAD_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A4_PAD_10_SHIFT         (20U)
/*! PAD_10 - PAD_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A4_PAD_11_SHIFT         (22U)
/*! PAD_11 - PAD_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A4_PAD_12_SHIFT         (24U)
/*! PAD_12 - PAD_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A4_PAD_13_SHIFT         (26U)
/*! PAD_13 - PAD_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_14_MASK          (0x30000000U)
#define VIRT_WRAPPER_REG_A4_PAD_14_SHIFT         (28U)
/*! PAD_14 - PAD_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_14(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A4_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A4_PAD_15_SHIFT         (30U)
/*! PAD_15 - PAD_15
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A4_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A4_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A4_PAD_15_MASK)
/*! @} */

/*! @name REG_A5 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A5_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A5_PAD_0_SHIFT          (0U)
/*! PAD_0 - PAD_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A5_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A5_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A5_PAD_1_SHIFT          (2U)
/*! PAD_1 - PAD_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A5_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A5_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A5_PAD_1_MASK)
/*! @} */

/*! @name REG_A6 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A6_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A6_PAD_0_SHIFT          (0U)
/*! PAD_0 - PAD_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A6_PAD_1_SHIFT          (2U)
/*! PAD_1 - PAD_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A6_PAD_2_SHIFT          (4U)
/*! PAD_2 - PAD_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A6_PAD_3_SHIFT          (6U)
/*! PAD_3 - PAD_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_4_MASK           (0x300U)
#define VIRT_WRAPPER_REG_A6_PAD_4_SHIFT          (8U)
/*! PAD_4 - PAD_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_4(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_5_MASK           (0xC00U)
#define VIRT_WRAPPER_REG_A6_PAD_5_SHIFT          (10U)
/*! PAD_5 - PAD_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_5(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_6_MASK           (0x3000U)
#define VIRT_WRAPPER_REG_A6_PAD_6_SHIFT          (12U)
/*! PAD_6 - PAD_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_6(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_7_MASK           (0xC000U)
#define VIRT_WRAPPER_REG_A6_PAD_7_SHIFT          (14U)
/*! PAD_7 - PAD_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_7(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A6_PAD_8_SHIFT          (16U)
/*! PAD_8 - PAD_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A6_PAD_9_SHIFT          (18U)
/*! PAD_9 - PAD_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A6_PAD_10_SHIFT         (20U)
/*! PAD_10 - PAD_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A6_PAD_11_SHIFT         (22U)
/*! PAD_11 - PAD_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A6_PAD_12_SHIFT         (24U)
/*! PAD_12 - PAD_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A6_PAD_13_SHIFT         (26U)
/*! PAD_13 - PAD_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_14_MASK          (0x30000000U)
#define VIRT_WRAPPER_REG_A6_PAD_14_SHIFT         (28U)
/*! PAD_14 - PAD_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_14(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A6_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A6_PAD_15_SHIFT         (30U)
/*! PAD_15 - PAD_15
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A6_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A6_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A6_PAD_15_MASK)
/*! @} */

/*! @name REG_A7 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A7_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A7_PAD_0_SHIFT          (0U)
/*! PAD_0 - PAD_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A7_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A7_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A7_PAD_1_SHIFT          (2U)
/*! PAD_1 - PAD_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A7_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A7_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A7_PAD_1_MASK)
/*! @} */

/*! @name REG_A8 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A8_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A8_PAD_0_SHIFT          (0U)
/*! PAD_0 - PAD_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A8_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_1_MASK           (0xCU)
#define VIRT_WRAPPER_REG_A8_PAD_1_SHIFT          (2U)
/*! PAD_1 - PAD_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A8_PAD_1(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_2_MASK           (0x30U)
#define VIRT_WRAPPER_REG_A8_PAD_2_SHIFT          (4U)
/*! PAD_2 - PAD_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A8_PAD_2(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_3_MASK           (0xC0U)
#define VIRT_WRAPPER_REG_A8_PAD_3_SHIFT          (6U)
/*! PAD_3 - PAD_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A8_PAD_3(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_6_MASK           (0x3000U)
#define VIRT_WRAPPER_REG_A8_PAD_6_SHIFT          (12U)
/*! PAD_6 - PAD_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A8_PAD_6(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_7_MASK           (0xC000U)
#define VIRT_WRAPPER_REG_A8_PAD_7_SHIFT          (14U)
/*! PAD_7 - PAD_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A8_PAD_7(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_8_MASK           (0x30000U)
#define VIRT_WRAPPER_REG_A8_PAD_8_SHIFT          (16U)
/*! PAD_8 - PAD_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A8_PAD_8(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_9_MASK           (0xC0000U)
#define VIRT_WRAPPER_REG_A8_PAD_9_SHIFT          (18U)
/*! PAD_9 - PAD_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A8_PAD_9(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_10_MASK          (0x300000U)
#define VIRT_WRAPPER_REG_A8_PAD_10_SHIFT         (20U)
/*! PAD_10 - PAD_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A8_PAD_10(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_11_MASK          (0xC00000U)
#define VIRT_WRAPPER_REG_A8_PAD_11_SHIFT         (22U)
/*! PAD_11 - PAD_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A8_PAD_11(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_12_MASK          (0x3000000U)
#define VIRT_WRAPPER_REG_A8_PAD_12_SHIFT         (24U)
/*! PAD_12 - PAD_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A8_PAD_12(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_13_MASK          (0xC000000U)
#define VIRT_WRAPPER_REG_A8_PAD_13_SHIFT         (26U)
/*! PAD_13 - PAD_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A8_PAD_13(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A8_PAD_15_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_A8_PAD_15_SHIFT         (30U)
/*! PAD_15 - PAD_15
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A8_PAD_15(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A8_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A8_PAD_15_MASK)
/*! @} */

/*! @name REG_A9 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A9_PAD_0_MASK           (0x3U)
#define VIRT_WRAPPER_REG_A9_PAD_0_SHIFT          (0U)
/*! PAD_0 - PAD_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_A9_PAD_0(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A9_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A9_PAD_0_MASK)
/*! @} */

/*! @name REG_B0 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B0_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B0_INMUX_0_SHIFT        (0U)
/*! INMUX_0 - INMUX_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B0_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B0_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B0_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B0_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B0_INMUX_1_SHIFT        (2U)
/*! INMUX_1 - INMUX_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B0_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B0_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B0_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B0_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B0_INMUX_2_SHIFT        (4U)
/*! INMUX_2 - INMUX_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B0_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B0_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B0_INMUX_2_MASK)
/*! @} */

/*! @name REG_B1 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B1_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B1_INMUX_0_SHIFT        (0U)
/*! INMUX_0 - INMUX_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B1_INMUX_1_SHIFT        (2U)
/*! INMUX_1 - INMUX_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B1_INMUX_2_SHIFT        (4U)
/*! INMUX_2 - INMUX_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B1_INMUX_3_SHIFT        (6U)
/*! INMUX_3 - INMUX_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B1_INMUX_4_SHIFT        (8U)
/*! INMUX_4 - INMUX_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B1_INMUX_5_SHIFT        (10U)
/*! INMUX_5 - INMUX_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_6_MASK         (0x3000U)
#define VIRT_WRAPPER_REG_B1_INMUX_6_SHIFT        (12U)
/*! INMUX_6 - INMUX_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_6(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_7_MASK         (0xC000U)
#define VIRT_WRAPPER_REG_B1_INMUX_7_SHIFT        (14U)
/*! INMUX_7 - INMUX_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_7(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_8_MASK         (0x30000U)
#define VIRT_WRAPPER_REG_B1_INMUX_8_SHIFT        (16U)
/*! INMUX_8 - INMUX_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_8(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_9_MASK         (0xC0000U)
#define VIRT_WRAPPER_REG_B1_INMUX_9_SHIFT        (18U)
/*! INMUX_9 - INMUX_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_9(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_10_MASK        (0x300000U)
#define VIRT_WRAPPER_REG_B1_INMUX_10_SHIFT       (20U)
/*! INMUX_10 - INMUX_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_10(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_11_MASK        (0xC00000U)
#define VIRT_WRAPPER_REG_B1_INMUX_11_SHIFT       (22U)
/*! INMUX_11 - INMUX_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_11(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_12_MASK        (0x3000000U)
#define VIRT_WRAPPER_REG_B1_INMUX_12_SHIFT       (24U)
/*! INMUX_12 - INMUX_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_12(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_13_MASK        (0xC000000U)
#define VIRT_WRAPPER_REG_B1_INMUX_13_SHIFT       (26U)
/*! INMUX_13 - INMUX_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_13(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_14_MASK        (0x30000000U)
#define VIRT_WRAPPER_REG_B1_INMUX_14_SHIFT       (28U)
/*! INMUX_14 - INMUX_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_14(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B1_INMUX_15_MASK        (0xC0000000U)
#define VIRT_WRAPPER_REG_B1_INMUX_15_SHIFT       (30U)
/*! INMUX_15 - INMUX_15
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B1_INMUX_15(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B1_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B1_INMUX_15_MASK)
/*! @} */

/*! @name REG_B2 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B2_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B2_INMUX_0_SHIFT        (0U)
/*! INMUX_0 - INMUX_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B2_INMUX_1_SHIFT        (2U)
/*! INMUX_1 - INMUX_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B2_INMUX_2_SHIFT        (4U)
/*! INMUX_2 - INMUX_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B2_INMUX_3_SHIFT        (6U)
/*! INMUX_3 - INMUX_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B2_INMUX_4_SHIFT        (8U)
/*! INMUX_4 - INMUX_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B2_INMUX_5_SHIFT        (10U)
/*! INMUX_5 - INMUX_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_6_MASK         (0x3000U)
#define VIRT_WRAPPER_REG_B2_INMUX_6_SHIFT        (12U)
/*! INMUX_6 - INMUX_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_6(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_7_MASK         (0xC000U)
#define VIRT_WRAPPER_REG_B2_INMUX_7_SHIFT        (14U)
/*! INMUX_7 - INMUX_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_7(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_8_MASK         (0x30000U)
#define VIRT_WRAPPER_REG_B2_INMUX_8_SHIFT        (16U)
/*! INMUX_8 - INMUX_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_8(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_9_MASK         (0xC0000U)
#define VIRT_WRAPPER_REG_B2_INMUX_9_SHIFT        (18U)
/*! INMUX_9 - INMUX_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_9(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_10_MASK        (0x300000U)
#define VIRT_WRAPPER_REG_B2_INMUX_10_SHIFT       (20U)
/*! INMUX_10 - INMUX_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_10(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_11_MASK        (0xC00000U)
#define VIRT_WRAPPER_REG_B2_INMUX_11_SHIFT       (22U)
/*! INMUX_11 - INMUX_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_11(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_12_MASK        (0x3000000U)
#define VIRT_WRAPPER_REG_B2_INMUX_12_SHIFT       (24U)
/*! INMUX_12 - INMUX_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_12(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_13_MASK        (0xC000000U)
#define VIRT_WRAPPER_REG_B2_INMUX_13_SHIFT       (26U)
/*! INMUX_13 - INMUX_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_13(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_14_MASK        (0x30000000U)
#define VIRT_WRAPPER_REG_B2_INMUX_14_SHIFT       (28U)
/*! INMUX_14 - INMUX_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_14(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B2_INMUX_15_MASK        (0xC0000000U)
#define VIRT_WRAPPER_REG_B2_INMUX_15_SHIFT       (30U)
/*! INMUX_15 - INMUX_15
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B2_INMUX_15(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B2_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B2_INMUX_15_MASK)
/*! @} */

/*! @name REG_B3 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B3_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B3_INMUX_0_SHIFT        (0U)
/*! INMUX_0 - INMUX_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B3_INMUX_1_SHIFT        (2U)
/*! INMUX_1 - INMUX_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B3_INMUX_2_SHIFT        (4U)
/*! INMUX_2 - INMUX_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B3_INMUX_3_SHIFT        (6U)
/*! INMUX_3 - INMUX_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B3_INMUX_4_SHIFT        (8U)
/*! INMUX_4 - INMUX_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B3_INMUX_5_SHIFT        (10U)
/*! INMUX_5 - INMUX_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_6_MASK         (0x3000U)
#define VIRT_WRAPPER_REG_B3_INMUX_6_SHIFT        (12U)
/*! INMUX_6 - INMUX_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_6(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_7_MASK         (0xC000U)
#define VIRT_WRAPPER_REG_B3_INMUX_7_SHIFT        (14U)
/*! INMUX_7 - INMUX_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_7(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_8_MASK         (0x30000U)
#define VIRT_WRAPPER_REG_B3_INMUX_8_SHIFT        (16U)
/*! INMUX_8 - INMUX_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_8(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_9_MASK         (0xC0000U)
#define VIRT_WRAPPER_REG_B3_INMUX_9_SHIFT        (18U)
/*! INMUX_9 - INMUX_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_9(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_10_MASK        (0x300000U)
#define VIRT_WRAPPER_REG_B3_INMUX_10_SHIFT       (20U)
/*! INMUX_10 - INMUX_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_10(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_11_MASK        (0xC00000U)
#define VIRT_WRAPPER_REG_B3_INMUX_11_SHIFT       (22U)
/*! INMUX_11 - INMUX_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_11(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_12_MASK        (0x3000000U)
#define VIRT_WRAPPER_REG_B3_INMUX_12_SHIFT       (24U)
/*! INMUX_12 - INMUX_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_12(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_13_MASK        (0xC000000U)
#define VIRT_WRAPPER_REG_B3_INMUX_13_SHIFT       (26U)
/*! INMUX_13 - INMUX_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_13(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_14_MASK        (0x30000000U)
#define VIRT_WRAPPER_REG_B3_INMUX_14_SHIFT       (28U)
/*! INMUX_14 - INMUX_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_14(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B3_INMUX_15_MASK        (0xC0000000U)
#define VIRT_WRAPPER_REG_B3_INMUX_15_SHIFT       (30U)
/*! INMUX_15 - INMUX_15
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B3_INMUX_15(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B3_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B3_INMUX_15_MASK)
/*! @} */

/*! @name REG_B4 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B4_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B4_INMUX_0_SHIFT        (0U)
/*! INMUX_0 - INMUX_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B4_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B4_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B4_INMUX_1_SHIFT        (2U)
/*! INMUX_1 - INMUX_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B4_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B4_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B4_INMUX_2_SHIFT        (4U)
/*! INMUX_2 - INMUX_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B4_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B4_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B4_INMUX_3_SHIFT        (6U)
/*! INMUX_3 - INMUX_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B4_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B4_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B4_INMUX_4_SHIFT        (8U)
/*! INMUX_4 - INMUX_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B4_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B4_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B4_INMUX_5_SHIFT        (10U)
/*! INMUX_5 - INMUX_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B4_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B4_INMUX_6_MASK         (0x3000U)
#define VIRT_WRAPPER_REG_B4_INMUX_6_SHIFT        (12U)
/*! INMUX_6 - INMUX_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B4_INMUX_6(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B4_INMUX_7_MASK         (0xC000U)
#define VIRT_WRAPPER_REG_B4_INMUX_7_SHIFT        (14U)
/*! INMUX_7 - INMUX_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B4_INMUX_7(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B4_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B4_INMUX_7_MASK)
/*! @} */

/*! @name REG_B5 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B5_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B5_INMUX_0_SHIFT        (0U)
/*! INMUX_0 - INMUX_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B5_INMUX_1_SHIFT        (2U)
/*! INMUX_1 - INMUX_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B5_INMUX_2_SHIFT        (4U)
/*! INMUX_2 - INMUX_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B5_INMUX_3_SHIFT        (6U)
/*! INMUX_3 - INMUX_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B5_INMUX_4_SHIFT        (8U)
/*! INMUX_4 - INMUX_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B5_INMUX_5_SHIFT        (10U)
/*! INMUX_5 - INMUX_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_6_MASK         (0x3000U)
#define VIRT_WRAPPER_REG_B5_INMUX_6_SHIFT        (12U)
/*! INMUX_6 - INMUX_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_6(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_7_MASK         (0xC000U)
#define VIRT_WRAPPER_REG_B5_INMUX_7_SHIFT        (14U)
/*! INMUX_7 - INMUX_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_7(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_8_MASK         (0x30000U)
#define VIRT_WRAPPER_REG_B5_INMUX_8_SHIFT        (16U)
/*! INMUX_8 - INMUX_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_8(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_9_MASK         (0xC0000U)
#define VIRT_WRAPPER_REG_B5_INMUX_9_SHIFT        (18U)
/*! INMUX_9 - INMUX_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_9(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_10_MASK        (0x300000U)
#define VIRT_WRAPPER_REG_B5_INMUX_10_SHIFT       (20U)
/*! INMUX_10 - INMUX_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_10(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_11_MASK        (0xC00000U)
#define VIRT_WRAPPER_REG_B5_INMUX_11_SHIFT       (22U)
/*! INMUX_11 - INMUX_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_11(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_12_MASK        (0x3000000U)
#define VIRT_WRAPPER_REG_B5_INMUX_12_SHIFT       (24U)
/*! INMUX_12 - INMUX_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_12(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_13_MASK        (0xC000000U)
#define VIRT_WRAPPER_REG_B5_INMUX_13_SHIFT       (26U)
/*! INMUX_13 - INMUX_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_13(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_14_MASK        (0x30000000U)
#define VIRT_WRAPPER_REG_B5_INMUX_14_SHIFT       (28U)
/*! INMUX_14 - INMUX_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_14(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B5_INMUX_15_MASK        (0xC0000000U)
#define VIRT_WRAPPER_REG_B5_INMUX_15_SHIFT       (30U)
/*! INMUX_15 - INMUX_15
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B5_INMUX_15(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B5_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B5_INMUX_15_MASK)
/*! @} */

/*! @name REG_B6 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B6_INMUX_0_MASK         (0x3U)
#define VIRT_WRAPPER_REG_B6_INMUX_0_SHIFT        (0U)
/*! INMUX_0 - INMUX_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B6_INMUX_0(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B6_INMUX_1_MASK         (0xCU)
#define VIRT_WRAPPER_REG_B6_INMUX_1_SHIFT        (2U)
/*! INMUX_1 - INMUX_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B6_INMUX_1(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B6_INMUX_2_MASK         (0x30U)
#define VIRT_WRAPPER_REG_B6_INMUX_2_SHIFT        (4U)
/*! INMUX_2 - INMUX_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B6_INMUX_2(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B6_INMUX_3_MASK         (0xC0U)
#define VIRT_WRAPPER_REG_B6_INMUX_3_SHIFT        (6U)
/*! INMUX_3 - INMUX_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B6_INMUX_3(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B6_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B6_INMUX_4_SHIFT        (8U)
/*! INMUX_4 - INMUX_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B6_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B6_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B6_INMUX_5_SHIFT        (10U)
/*! INMUX_5 - INMUX_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B6_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B6_INMUX_6_MASK         (0x3000U)
#define VIRT_WRAPPER_REG_B6_INMUX_6_SHIFT        (12U)
/*! INMUX_6 - INMUX_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B6_INMUX_6(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B6_INMUX_7_MASK         (0xC000U)
#define VIRT_WRAPPER_REG_B6_INMUX_7_SHIFT        (14U)
/*! INMUX_7 - INMUX_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B6_INMUX_7(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B6_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B6_INMUX_7_MASK)
/*! @} */

/*! @name REG_B9 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B9_INMUX_4_MASK         (0x300U)
#define VIRT_WRAPPER_REG_B9_INMUX_4_SHIFT        (8U)
/*! INMUX_4 - INMUX_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B9_INMUX_4(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_5_MASK         (0xC00U)
#define VIRT_WRAPPER_REG_B9_INMUX_5_SHIFT        (10U)
/*! INMUX_5 - INMUX_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B9_INMUX_5(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_8_MASK         (0x30000U)
#define VIRT_WRAPPER_REG_B9_INMUX_8_SHIFT        (16U)
/*! INMUX_8 - INMUX_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B9_INMUX_8(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_9_MASK         (0xC0000U)
#define VIRT_WRAPPER_REG_B9_INMUX_9_SHIFT        (18U)
/*! INMUX_9 - INMUX_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B9_INMUX_9(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_10_MASK        (0x300000U)
#define VIRT_WRAPPER_REG_B9_INMUX_10_SHIFT       (20U)
/*! INMUX_10 - INMUX_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B9_INMUX_10(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_11_MASK        (0xC00000U)
#define VIRT_WRAPPER_REG_B9_INMUX_11_SHIFT       (22U)
/*! INMUX_11 - INMUX_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B9_INMUX_11(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_12_MASK        (0x3000000U)
#define VIRT_WRAPPER_REG_B9_INMUX_12_SHIFT       (24U)
/*! INMUX_12 - INMUX_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B9_INMUX_12(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_13_MASK        (0xC000000U)
#define VIRT_WRAPPER_REG_B9_INMUX_13_SHIFT       (26U)
/*! INMUX_13 - INMUX_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B9_INMUX_13(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_14_MASK        (0x30000000U)
#define VIRT_WRAPPER_REG_B9_INMUX_14_SHIFT       (28U)
/*! INMUX_14 - INMUX_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B9_INMUX_14(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B9_INMUX_15_MASK        (0xC0000000U)
#define VIRT_WRAPPER_REG_B9_INMUX_15_SHIFT       (30U)
/*! INMUX_15 - INMUX_15
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B9_INMUX_15(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B9_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B9_INMUX_15_MASK)
/*! @} */

/*! @name REG_B10 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B10_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B10_INMUX_0_SHIFT       (0U)
/*! INMUX_0 - INMUX_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B10_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B10_INMUX_1_SHIFT       (2U)
/*! INMUX_1 - INMUX_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B10_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B10_INMUX_2_SHIFT       (4U)
/*! INMUX_2 - INMUX_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B10_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B10_INMUX_3_SHIFT       (6U)
/*! INMUX_3 - INMUX_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B10_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B10_INMUX_4_SHIFT       (8U)
/*! INMUX_4 - INMUX_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B10_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B10_INMUX_5_SHIFT       (10U)
/*! INMUX_5 - INMUX_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B10_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B10_INMUX_6_SHIFT       (12U)
/*! INMUX_6 - INMUX_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B10_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B10_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B10_INMUX_7_SHIFT       (14U)
/*! INMUX_7 - INMUX_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B10_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B10_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B10_INMUX_7_MASK)
/*! @} */

/*! @name REG_B11 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B11_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B11_INMUX_8_SHIFT       (16U)
/*! INMUX_8 - INMUX_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B11_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B11_INMUX_9_SHIFT       (18U)
/*! INMUX_9 - INMUX_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B11_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B11_INMUX_10_SHIFT      (20U)
/*! INMUX_10 - INMUX_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B11_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B11_INMUX_11_SHIFT      (22U)
/*! INMUX_11 - INMUX_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B11_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B11_INMUX_12_SHIFT      (24U)
/*! INMUX_12 - INMUX_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B11_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B11_INMUX_13_SHIFT      (26U)
/*! INMUX_13 - INMUX_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B11_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B11_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B11_INMUX_14_SHIFT      (28U)
/*! INMUX_14 - INMUX_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B11_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B11_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B11_INMUX_14_MASK)
/*! @} */

/*! @name REG_B13 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B13_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B13_INMUX_3_SHIFT       (6U)
/*! INMUX_3 - INMUX_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B13_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B13_INMUX_4_SHIFT       (8U)
/*! INMUX_4 - INMUX_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B13_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B13_INMUX_5_SHIFT       (10U)
/*! INMUX_5 - INMUX_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B13_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B13_INMUX_6_SHIFT       (12U)
/*! INMUX_6 - INMUX_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B13_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B13_INMUX_7_SHIFT       (14U)
/*! INMUX_7 - INMUX_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B13_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B13_INMUX_8_SHIFT       (16U)
/*! INMUX_8 - INMUX_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B13_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B13_INMUX_9_SHIFT       (18U)
/*! INMUX_9 - INMUX_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B13_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B13_INMUX_10_SHIFT      (20U)
/*! INMUX_10 - INMUX_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B13_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B13_INMUX_11_SHIFT      (22U)
/*! INMUX_11 - INMUX_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B13_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B13_INMUX_12_SHIFT      (24U)
/*! INMUX_12 - INMUX_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B13_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B13_INMUX_13_SHIFT      (26U)
/*! INMUX_13 - INMUX_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B13_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B13_INMUX_14_SHIFT      (28U)
/*! INMUX_14 - INMUX_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B13_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B13_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B13_INMUX_15_SHIFT      (30U)
/*! INMUX_15 - INMUX_15
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B13_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B13_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B13_INMUX_15_MASK)
/*! @} */

/*! @name REG_B14 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B14_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B14_INMUX_0_SHIFT       (0U)
/*! INMUX_0 - INMUX_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B14_INMUX_1_SHIFT       (2U)
/*! INMUX_1 - INMUX_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B14_INMUX_2_SHIFT       (4U)
/*! INMUX_2 - INMUX_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B14_INMUX_3_SHIFT       (6U)
/*! INMUX_3 - INMUX_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B14_INMUX_4_SHIFT       (8U)
/*! INMUX_4 - INMUX_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B14_INMUX_5_SHIFT       (10U)
/*! INMUX_5 - INMUX_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B14_INMUX_6_SHIFT       (12U)
/*! INMUX_6 - INMUX_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B14_INMUX_7_SHIFT       (14U)
/*! INMUX_7 - INMUX_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B14_INMUX_8_SHIFT       (16U)
/*! INMUX_8 - INMUX_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B14_INMUX_9_SHIFT       (18U)
/*! INMUX_9 - INMUX_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B14_INMUX_10_SHIFT      (20U)
/*! INMUX_10 - INMUX_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B14_INMUX_11_SHIFT      (22U)
/*! INMUX_11 - INMUX_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B14_INMUX_12_SHIFT      (24U)
/*! INMUX_12 - INMUX_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B14_INMUX_13_SHIFT      (26U)
/*! INMUX_13 - INMUX_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B14_INMUX_14_SHIFT      (28U)
/*! INMUX_14 - INMUX_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B14_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B14_INMUX_15_SHIFT      (30U)
/*! INMUX_15 - INMUX_15
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B14_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B14_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B14_INMUX_15_MASK)
/*! @} */

/*! @name REG_B15 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B15_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B15_INMUX_0_SHIFT       (0U)
/*! INMUX_0 - INMUX_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B15_INMUX_1_SHIFT       (2U)
/*! INMUX_1 - INMUX_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B15_INMUX_2_SHIFT       (4U)
/*! INMUX_2 - INMUX_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B15_INMUX_3_SHIFT       (6U)
/*! INMUX_3 - INMUX_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B15_INMUX_4_SHIFT       (8U)
/*! INMUX_4 - INMUX_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B15_INMUX_5_SHIFT       (10U)
/*! INMUX_5 - INMUX_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B15_INMUX_6_SHIFT       (12U)
/*! INMUX_6 - INMUX_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B15_INMUX_7_SHIFT       (14U)
/*! INMUX_7 - INMUX_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B15_INMUX_8_SHIFT       (16U)
/*! INMUX_8 - INMUX_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B15_INMUX_9_SHIFT       (18U)
/*! INMUX_9 - INMUX_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B15_INMUX_10_SHIFT      (20U)
/*! INMUX_10 - INMUX_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B15_INMUX_11_SHIFT      (22U)
/*! INMUX_11 - INMUX_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B15_INMUX_12_SHIFT      (24U)
/*! INMUX_12 - INMUX_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B15_INMUX_13_SHIFT      (26U)
/*! INMUX_13 - INMUX_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B15_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B15_INMUX_14_SHIFT      (28U)
/*! INMUX_14 - INMUX_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B15_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B15_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B15_INMUX_14_MASK)
/*! @} */

/*! @name REG_B21 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B21_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B21_INMUX_7_SHIFT       (14U)
/*! INMUX_7 - INMUX_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B21_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B21_INMUX_8_SHIFT       (16U)
/*! INMUX_8 - INMUX_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B21_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B21_INMUX_9_SHIFT       (18U)
/*! INMUX_9 - INMUX_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B21_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B21_INMUX_10_SHIFT      (20U)
/*! INMUX_10 - INMUX_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B21_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B21_INMUX_11_SHIFT      (22U)
/*! INMUX_11 - INMUX_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B21_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B21_INMUX_12_SHIFT      (24U)
/*! INMUX_12 - INMUX_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B21_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B21_INMUX_13_SHIFT      (26U)
/*! INMUX_13 - INMUX_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B21_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B21_INMUX_14_SHIFT      (28U)
/*! INMUX_14 - INMUX_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B21_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B21_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B21_INMUX_15_SHIFT      (30U)
/*! INMUX_15 - INMUX_15
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B21_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B21_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B21_INMUX_15_MASK)
/*! @} */

/*! @name REG_B22 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B22_INMUX_0_MASK        (0x3U)
#define VIRT_WRAPPER_REG_B22_INMUX_0_SHIFT       (0U)
/*! INMUX_0 - INMUX_0
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_0(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_1_MASK        (0xCU)
#define VIRT_WRAPPER_REG_B22_INMUX_1_SHIFT       (2U)
/*! INMUX_1 - INMUX_1
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_1(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_2_MASK        (0x30U)
#define VIRT_WRAPPER_REG_B22_INMUX_2_SHIFT       (4U)
/*! INMUX_2 - INMUX_2
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_2(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B22_INMUX_3_SHIFT       (6U)
/*! INMUX_3 - INMUX_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B22_INMUX_4_SHIFT       (8U)
/*! INMUX_4 - INMUX_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B22_INMUX_5_SHIFT       (10U)
/*! INMUX_5 - INMUX_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B22_INMUX_6_SHIFT       (12U)
/*! INMUX_6 - INMUX_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B22_INMUX_7_SHIFT       (14U)
/*! INMUX_7 - INMUX_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B22_INMUX_8_SHIFT       (16U)
/*! INMUX_8 - INMUX_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B22_INMUX_9_SHIFT       (18U)
/*! INMUX_9 - INMUX_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B22_INMUX_10_SHIFT      (20U)
/*! INMUX_10 - INMUX_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_11_MASK       (0xC00000U)
#define VIRT_WRAPPER_REG_B22_INMUX_11_SHIFT      (22U)
/*! INMUX_11 - INMUX_11
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_11(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_12_MASK       (0x3000000U)
#define VIRT_WRAPPER_REG_B22_INMUX_12_SHIFT      (24U)
/*! INMUX_12 - INMUX_12
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_12(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_13_MASK       (0xC000000U)
#define VIRT_WRAPPER_REG_B22_INMUX_13_SHIFT      (26U)
/*! INMUX_13 - INMUX_13
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_13(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B22_INMUX_14_MASK       (0x30000000U)
#define VIRT_WRAPPER_REG_B22_INMUX_14_SHIFT      (28U)
/*! INMUX_14 - INMUX_14
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B22_INMUX_14(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B22_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B22_INMUX_14_MASK)
/*! @} */

/*! @name REG_B23 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B23_INMUX_3_MASK        (0xC0U)
#define VIRT_WRAPPER_REG_B23_INMUX_3_SHIFT       (6U)
/*! INMUX_3 - INMUX_3
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B23_INMUX_3(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_4_MASK        (0x300U)
#define VIRT_WRAPPER_REG_B23_INMUX_4_SHIFT       (8U)
/*! INMUX_4 - INMUX_4
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B23_INMUX_4(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_5_MASK        (0xC00U)
#define VIRT_WRAPPER_REG_B23_INMUX_5_SHIFT       (10U)
/*! INMUX_5 - INMUX_5
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B23_INMUX_5(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_6_MASK        (0x3000U)
#define VIRT_WRAPPER_REG_B23_INMUX_6_SHIFT       (12U)
/*! INMUX_6 - INMUX_6
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B23_INMUX_6(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_7_MASK        (0xC000U)
#define VIRT_WRAPPER_REG_B23_INMUX_7_SHIFT       (14U)
/*! INMUX_7 - INMUX_7
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B23_INMUX_7(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_8_MASK        (0x30000U)
#define VIRT_WRAPPER_REG_B23_INMUX_8_SHIFT       (16U)
/*! INMUX_8 - INMUX_8
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B23_INMUX_8(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_9_MASK        (0xC0000U)
#define VIRT_WRAPPER_REG_B23_INMUX_9_SHIFT       (18U)
/*! INMUX_9 - INMUX_9
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B23_INMUX_9(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B23_INMUX_10_MASK       (0x300000U)
#define VIRT_WRAPPER_REG_B23_INMUX_10_SHIFT      (20U)
/*! INMUX_10 - INMUX_10
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B23_INMUX_10(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B23_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B23_INMUX_10_MASK)
/*! @} */

/*! @name REG_B24 - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B24_INMUX_15_MASK       (0xC0000000U)
#define VIRT_WRAPPER_REG_B24_INMUX_15_SHIFT      (30U)
/*! INMUX_15 - INMUX_15
 *  0b00..SIUL2_VIRTWRAPPER_PDAC1
 *  0b11..SIUL2_VIRTWRAPPER_PDAC0
 */
#define VIRT_WRAPPER_REG_B24_INMUX_15(x)         (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B24_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B24_INMUX_15_MASK)
/*! @} */

/*! @name REG_C - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_C_INTC_CTRL_MASK        (0x3U)
#define VIRT_WRAPPER_REG_C_INTC_CTRL_SHIFT       (0U)
/*! INTC_CTRL - Interrupt register control */
#define VIRT_WRAPPER_REG_C_INTC_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_C_INTC_CTRL_SHIFT)) & VIRT_WRAPPER_REG_C_INTC_CTRL_MASK)
/*! @} */

/*! @name REG_D - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_D_REG_GCR_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_D_REG_GCR_SHIFT         (30U)
/*! REG_GCR - GCR Register Of REG_PROT */
#define VIRT_WRAPPER_REG_D_REG_GCR(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_D_REG_GCR_SHIFT)) & VIRT_WRAPPER_REG_D_REG_GCR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VIRT_WRAPPER_Register_Masks */


/*!
 * @}
 */ /* end of group VIRT_WRAPPER_Peripheral_Access_Layer */


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


#endif  /* PERI_VIRT_WRAPPER_H_ */

