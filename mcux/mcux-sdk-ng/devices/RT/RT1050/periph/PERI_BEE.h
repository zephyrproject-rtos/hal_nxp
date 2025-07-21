/*
** ###################################################################
**     Processors:          MIMXRT1051CVJ5B
**                          MIMXRT1051CVL5B
**                          MIMXRT1051DVJ6B
**                          MIMXRT1051DVL6B
**                          MIMXRT1052CVJ5B
**                          MIMXRT1052CVL5B
**                          MIMXRT1052DVJ6B
**                          MIMXRT1052DVL6B
**                          MIMXRT105SDVL6B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BEE
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-01-10)
**         Initial version.
**     - rev. 1.0 (2018-09-21)
**         Update interrupt vector table and dma request source.
**         Update register BEE_ADDR_OFFSET1's bitfield name to ADDR_OFFSET1.
**         Split GPIO_COMBINED_IRQS to GPIO_COMBINED_LOW_IRQS and GPIO_COMBINED_HIGH_IRQS.
**     - rev. 1.1 (2018-11-16)
**         Update header files to align with IMXRT1050RM Rev.1.
**     - rev. 1.2 (2018-11-27)
**         Update header files to align with IMXRT1050RM Rev.2.1.
**     - rev. 1.3 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.4 (2021-08-10)
**         Update header files to align with IMXRT1050RM Rev.5.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_BEE.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BEE
 *
 * CMSIS Peripheral Access Layer for BEE
 */

#if !defined(PERI_BEE_H_)
#define PERI_BEE_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1051CVJ5B) || defined(CPU_MIMXRT1051CVL5B) || defined(CPU_MIMXRT1051DVJ6B) || defined(CPU_MIMXRT1051DVL6B))
#include "MIMXRT1051_COMMON.h"
#elif (defined(CPU_MIMXRT1052CVJ5B) || defined(CPU_MIMXRT1052CVL5B) || defined(CPU_MIMXRT1052DVJ6B) || defined(CPU_MIMXRT1052DVL6B))
#include "MIMXRT1052_COMMON.h"
#elif (defined(CPU_MIMXRT105SDVL6B))
#include "MIMXRT105S_COMMON.h"
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
   -- BEE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BEE_Peripheral_Access_Layer BEE Peripheral Access Layer
 * @{
 */

/** BEE - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Control Register, offset: 0x0 */
  __IO uint32_t ADDR_OFFSET0;                      /**< Offset region 0 Register, offset: 0x4 */
  __IO uint32_t ADDR_OFFSET1;                      /**< Offset region 1 Register, offset: 0x8 */
  __IO uint32_t AES_KEY0_W0;                       /**< AES Key 0 Register, offset: 0xC */
  __IO uint32_t AES_KEY0_W1;                       /**< AES Key 1 Register, offset: 0x10 */
  __IO uint32_t AES_KEY0_W2;                       /**< AES Key 2 Register, offset: 0x14 */
  __IO uint32_t AES_KEY0_W3;                       /**< AES Key 3 Register, offset: 0x18 */
  __IO uint32_t STATUS;                            /**< Status Register, offset: 0x1C */
  __O  uint32_t CTR_NONCE0_W0;                     /**< NONCE00 Register, offset: 0x20 */
  __O  uint32_t CTR_NONCE0_W1;                     /**< NONCE01 Register, offset: 0x24 */
  __O  uint32_t CTR_NONCE0_W2;                     /**< NONCE02 Register, offset: 0x28 */
  __O  uint32_t CTR_NONCE0_W3;                     /**< NONCE03 Register, offset: 0x2C */
  __O  uint32_t CTR_NONCE1_W0;                     /**< NONCE10 Register, offset: 0x30 */
  __O  uint32_t CTR_NONCE1_W1;                     /**< NONCE11 Register, offset: 0x34 */
  __O  uint32_t CTR_NONCE1_W2;                     /**< NONCE12 Register, offset: 0x38 */
  __O  uint32_t CTR_NONCE1_W3;                     /**< NONCE13 Register, offset: 0x3C */
  __IO uint32_t REGION1_TOP;                       /**< Region1 Top Address Register, offset: 0x40 */
  __IO uint32_t REGION1_BOT;                       /**< Region1 Bottom Address Register, offset: 0x44 */
} BEE_Type;

/* ----------------------------------------------------------------------------
   -- BEE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BEE_Register_Masks BEE Register Masks
 * @{
 */

/*! @name CTRL - Control Register */
/*! @{ */

#define BEE_CTRL_BEE_ENABLE_MASK                 (0x1U)
#define BEE_CTRL_BEE_ENABLE_SHIFT                (0U)
/*! BEE_ENABLE
 *  0b0..Disable BEE
 *  0b1..Enable BEE
 */
#define BEE_CTRL_BEE_ENABLE(x)                   (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_BEE_ENABLE_SHIFT)) & BEE_CTRL_BEE_ENABLE_MASK)

#define BEE_CTRL_CTRL_CLK_EN_MASK                (0x2U)
#define BEE_CTRL_CTRL_CLK_EN_SHIFT               (1U)
#define BEE_CTRL_CTRL_CLK_EN(x)                  (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_CTRL_CLK_EN_SHIFT)) & BEE_CTRL_CTRL_CLK_EN_MASK)

#define BEE_CTRL_CTRL_SFTRST_N_MASK              (0x4U)
#define BEE_CTRL_CTRL_SFTRST_N_SHIFT             (2U)
#define BEE_CTRL_CTRL_SFTRST_N(x)                (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_CTRL_SFTRST_N_SHIFT)) & BEE_CTRL_CTRL_SFTRST_N_MASK)

#define BEE_CTRL_KEY_VALID_MASK                  (0x10U)
#define BEE_CTRL_KEY_VALID_SHIFT                 (4U)
#define BEE_CTRL_KEY_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_KEY_VALID_SHIFT)) & BEE_CTRL_KEY_VALID_MASK)

#define BEE_CTRL_KEY_REGION_SEL_MASK             (0x20U)
#define BEE_CTRL_KEY_REGION_SEL_SHIFT            (5U)
/*! KEY_REGION_SEL
 *  0b0..Load AES key for region0
 *  0b1..Load AES key for region1
 */
#define BEE_CTRL_KEY_REGION_SEL(x)               (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_KEY_REGION_SEL_SHIFT)) & BEE_CTRL_KEY_REGION_SEL_MASK)

#define BEE_CTRL_AC_PROT_EN_MASK                 (0x40U)
#define BEE_CTRL_AC_PROT_EN_SHIFT                (6U)
#define BEE_CTRL_AC_PROT_EN(x)                   (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_AC_PROT_EN_SHIFT)) & BEE_CTRL_AC_PROT_EN_MASK)

#define BEE_CTRL_LITTLE_ENDIAN_MASK              (0x80U)
#define BEE_CTRL_LITTLE_ENDIAN_SHIFT             (7U)
/*! LITTLE_ENDIAN
 *  0b0..The input and output data of the AES core is swapped as below: {B15,B14,B13,B12,B11,B10,B9,B8,
 *       B7,B6,B5,B4,B3,B2,B1,B0} swap to {B0,B1,B2,B3,B4,B5,B6,B7, B8,B9,B10,B11,B12,B13,B14,B15}, where B0~B15 refers to
 *       Byte0 to Byte15.
 *  0b1..The input and output data of AES core is not swapped.
 */
#define BEE_CTRL_LITTLE_ENDIAN(x)                (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_LITTLE_ENDIAN_SHIFT)) & BEE_CTRL_LITTLE_ENDIAN_MASK)

#define BEE_CTRL_SECURITY_LEVEL_R0_MASK          (0x300U)
#define BEE_CTRL_SECURITY_LEVEL_R0_SHIFT         (8U)
#define BEE_CTRL_SECURITY_LEVEL_R0(x)            (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_SECURITY_LEVEL_R0_SHIFT)) & BEE_CTRL_SECURITY_LEVEL_R0_MASK)

#define BEE_CTRL_CTRL_AES_MODE_R0_MASK           (0x400U)
#define BEE_CTRL_CTRL_AES_MODE_R0_SHIFT          (10U)
/*! CTRL_AES_MODE_R0
 *  0b0..ECB
 *  0b1..CTR
 */
#define BEE_CTRL_CTRL_AES_MODE_R0(x)             (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_CTRL_AES_MODE_R0_SHIFT)) & BEE_CTRL_CTRL_AES_MODE_R0_MASK)

#define BEE_CTRL_SECURITY_LEVEL_R1_MASK          (0x3000U)
#define BEE_CTRL_SECURITY_LEVEL_R1_SHIFT         (12U)
#define BEE_CTRL_SECURITY_LEVEL_R1(x)            (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_SECURITY_LEVEL_R1_SHIFT)) & BEE_CTRL_SECURITY_LEVEL_R1_MASK)

#define BEE_CTRL_CTRL_AES_MODE_R1_MASK           (0x4000U)
#define BEE_CTRL_CTRL_AES_MODE_R1_SHIFT          (14U)
/*! CTRL_AES_MODE_R1
 *  0b0..ECB
 *  0b1..CTR
 */
#define BEE_CTRL_CTRL_AES_MODE_R1(x)             (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_CTRL_AES_MODE_R1_SHIFT)) & BEE_CTRL_CTRL_AES_MODE_R1_MASK)

#define BEE_CTRL_BEE_ENABLE_LOCK_MASK            (0x10000U)
#define BEE_CTRL_BEE_ENABLE_LOCK_SHIFT           (16U)
#define BEE_CTRL_BEE_ENABLE_LOCK(x)              (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_BEE_ENABLE_LOCK_SHIFT)) & BEE_CTRL_BEE_ENABLE_LOCK_MASK)

#define BEE_CTRL_CTRL_CLK_EN_LOCK_MASK           (0x20000U)
#define BEE_CTRL_CTRL_CLK_EN_LOCK_SHIFT          (17U)
#define BEE_CTRL_CTRL_CLK_EN_LOCK(x)             (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_CTRL_CLK_EN_LOCK_SHIFT)) & BEE_CTRL_CTRL_CLK_EN_LOCK_MASK)

#define BEE_CTRL_CTRL_SFTRST_N_LOCK_MASK         (0x40000U)
#define BEE_CTRL_CTRL_SFTRST_N_LOCK_SHIFT        (18U)
#define BEE_CTRL_CTRL_SFTRST_N_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_CTRL_SFTRST_N_LOCK_SHIFT)) & BEE_CTRL_CTRL_SFTRST_N_LOCK_MASK)

#define BEE_CTRL_REGION1_ADDR_LOCK_MASK          (0x80000U)
#define BEE_CTRL_REGION1_ADDR_LOCK_SHIFT         (19U)
#define BEE_CTRL_REGION1_ADDR_LOCK(x)            (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_REGION1_ADDR_LOCK_SHIFT)) & BEE_CTRL_REGION1_ADDR_LOCK_MASK)

#define BEE_CTRL_KEY_VALID_LOCK_MASK             (0x100000U)
#define BEE_CTRL_KEY_VALID_LOCK_SHIFT            (20U)
#define BEE_CTRL_KEY_VALID_LOCK(x)               (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_KEY_VALID_LOCK_SHIFT)) & BEE_CTRL_KEY_VALID_LOCK_MASK)

#define BEE_CTRL_KEY_REGION_SEL_LOCK_MASK        (0x200000U)
#define BEE_CTRL_KEY_REGION_SEL_LOCK_SHIFT       (21U)
#define BEE_CTRL_KEY_REGION_SEL_LOCK(x)          (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_KEY_REGION_SEL_LOCK_SHIFT)) & BEE_CTRL_KEY_REGION_SEL_LOCK_MASK)

#define BEE_CTRL_AC_PROT_EN_LOCK_MASK            (0x400000U)
#define BEE_CTRL_AC_PROT_EN_LOCK_SHIFT           (22U)
#define BEE_CTRL_AC_PROT_EN_LOCK(x)              (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_AC_PROT_EN_LOCK_SHIFT)) & BEE_CTRL_AC_PROT_EN_LOCK_MASK)

#define BEE_CTRL_LITTLE_ENDIAN_LOCK_MASK         (0x800000U)
#define BEE_CTRL_LITTLE_ENDIAN_LOCK_SHIFT        (23U)
#define BEE_CTRL_LITTLE_ENDIAN_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_LITTLE_ENDIAN_LOCK_SHIFT)) & BEE_CTRL_LITTLE_ENDIAN_LOCK_MASK)

#define BEE_CTRL_SECURITY_LEVEL_R0_LOCK_MASK     (0x3000000U)
#define BEE_CTRL_SECURITY_LEVEL_R0_LOCK_SHIFT    (24U)
#define BEE_CTRL_SECURITY_LEVEL_R0_LOCK(x)       (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_SECURITY_LEVEL_R0_LOCK_SHIFT)) & BEE_CTRL_SECURITY_LEVEL_R0_LOCK_MASK)

#define BEE_CTRL_CTRL_AES_MODE_R0_LOCK_MASK      (0x4000000U)
#define BEE_CTRL_CTRL_AES_MODE_R0_LOCK_SHIFT     (26U)
#define BEE_CTRL_CTRL_AES_MODE_R0_LOCK(x)        (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_CTRL_AES_MODE_R0_LOCK_SHIFT)) & BEE_CTRL_CTRL_AES_MODE_R0_LOCK_MASK)

#define BEE_CTRL_REGION0_KEY_LOCK_MASK           (0x8000000U)
#define BEE_CTRL_REGION0_KEY_LOCK_SHIFT          (27U)
#define BEE_CTRL_REGION0_KEY_LOCK(x)             (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_REGION0_KEY_LOCK_SHIFT)) & BEE_CTRL_REGION0_KEY_LOCK_MASK)

#define BEE_CTRL_SECURITY_LEVEL_R1_LOCK_MASK     (0x30000000U)
#define BEE_CTRL_SECURITY_LEVEL_R1_LOCK_SHIFT    (28U)
#define BEE_CTRL_SECURITY_LEVEL_R1_LOCK(x)       (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_SECURITY_LEVEL_R1_LOCK_SHIFT)) & BEE_CTRL_SECURITY_LEVEL_R1_LOCK_MASK)

#define BEE_CTRL_CTRL_AES_MODE_R1_LOCK_MASK      (0x40000000U)
#define BEE_CTRL_CTRL_AES_MODE_R1_LOCK_SHIFT     (30U)
#define BEE_CTRL_CTRL_AES_MODE_R1_LOCK(x)        (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_CTRL_AES_MODE_R1_LOCK_SHIFT)) & BEE_CTRL_CTRL_AES_MODE_R1_LOCK_MASK)

#define BEE_CTRL_REGION1_KEY_LOCK_MASK           (0x80000000U)
#define BEE_CTRL_REGION1_KEY_LOCK_SHIFT          (31U)
#define BEE_CTRL_REGION1_KEY_LOCK(x)             (((uint32_t)(((uint32_t)(x)) << BEE_CTRL_REGION1_KEY_LOCK_SHIFT)) & BEE_CTRL_REGION1_KEY_LOCK_MASK)
/*! @} */

/*! @name ADDR_OFFSET0 - Offset region 0 Register */
/*! @{ */

#define BEE_ADDR_OFFSET0_ADDR_OFFSET0_MASK       (0xFFFFU)
#define BEE_ADDR_OFFSET0_ADDR_OFFSET0_SHIFT      (0U)
#define BEE_ADDR_OFFSET0_ADDR_OFFSET0(x)         (((uint32_t)(((uint32_t)(x)) << BEE_ADDR_OFFSET0_ADDR_OFFSET0_SHIFT)) & BEE_ADDR_OFFSET0_ADDR_OFFSET0_MASK)

#define BEE_ADDR_OFFSET0_ADDR_OFFSET0_LOCK_MASK  (0xFFFF0000U)
#define BEE_ADDR_OFFSET0_ADDR_OFFSET0_LOCK_SHIFT (16U)
#define BEE_ADDR_OFFSET0_ADDR_OFFSET0_LOCK(x)    (((uint32_t)(((uint32_t)(x)) << BEE_ADDR_OFFSET0_ADDR_OFFSET0_LOCK_SHIFT)) & BEE_ADDR_OFFSET0_ADDR_OFFSET0_LOCK_MASK)
/*! @} */

/*! @name ADDR_OFFSET1 - Offset region 1 Register */
/*! @{ */

#define BEE_ADDR_OFFSET1_ADDR_OFFSET1_MASK       (0xFFFFU)
#define BEE_ADDR_OFFSET1_ADDR_OFFSET1_SHIFT      (0U)
#define BEE_ADDR_OFFSET1_ADDR_OFFSET1(x)         (((uint32_t)(((uint32_t)(x)) << BEE_ADDR_OFFSET1_ADDR_OFFSET1_SHIFT)) & BEE_ADDR_OFFSET1_ADDR_OFFSET1_MASK)

#define BEE_ADDR_OFFSET1_ADDR_OFFSET1_LOCK_MASK  (0xFFFF0000U)
#define BEE_ADDR_OFFSET1_ADDR_OFFSET1_LOCK_SHIFT (16U)
#define BEE_ADDR_OFFSET1_ADDR_OFFSET1_LOCK(x)    (((uint32_t)(((uint32_t)(x)) << BEE_ADDR_OFFSET1_ADDR_OFFSET1_LOCK_SHIFT)) & BEE_ADDR_OFFSET1_ADDR_OFFSET1_LOCK_MASK)
/*! @} */

/*! @name AES_KEY0_W0 - AES Key 0 Register */
/*! @{ */

#define BEE_AES_KEY0_W0_KEY0_MASK                (0xFFFFFFFFU)
#define BEE_AES_KEY0_W0_KEY0_SHIFT               (0U)
/*! KEY0 - AES 128 key from software */
#define BEE_AES_KEY0_W0_KEY0(x)                  (((uint32_t)(((uint32_t)(x)) << BEE_AES_KEY0_W0_KEY0_SHIFT)) & BEE_AES_KEY0_W0_KEY0_MASK)
/*! @} */

/*! @name AES_KEY0_W1 - AES Key 1 Register */
/*! @{ */

#define BEE_AES_KEY0_W1_KEY1_MASK                (0xFFFFFFFFU)
#define BEE_AES_KEY0_W1_KEY1_SHIFT               (0U)
/*! KEY1 - AES 128 key from software */
#define BEE_AES_KEY0_W1_KEY1(x)                  (((uint32_t)(((uint32_t)(x)) << BEE_AES_KEY0_W1_KEY1_SHIFT)) & BEE_AES_KEY0_W1_KEY1_MASK)
/*! @} */

/*! @name AES_KEY0_W2 - AES Key 2 Register */
/*! @{ */

#define BEE_AES_KEY0_W2_KEY2_MASK                (0xFFFFFFFFU)
#define BEE_AES_KEY0_W2_KEY2_SHIFT               (0U)
/*! KEY2 - AES 128 key from software */
#define BEE_AES_KEY0_W2_KEY2(x)                  (((uint32_t)(((uint32_t)(x)) << BEE_AES_KEY0_W2_KEY2_SHIFT)) & BEE_AES_KEY0_W2_KEY2_MASK)
/*! @} */

/*! @name AES_KEY0_W3 - AES Key 3 Register */
/*! @{ */

#define BEE_AES_KEY0_W3_KEY3_MASK                (0xFFFFFFFFU)
#define BEE_AES_KEY0_W3_KEY3_SHIFT               (0U)
/*! KEY3 - AES 128 key from software */
#define BEE_AES_KEY0_W3_KEY3(x)                  (((uint32_t)(((uint32_t)(x)) << BEE_AES_KEY0_W3_KEY3_SHIFT)) & BEE_AES_KEY0_W3_KEY3_MASK)
/*! @} */

/*! @name STATUS - Status Register */
/*! @{ */

#define BEE_STATUS_IRQ_VEC_MASK                  (0xFFU)
#define BEE_STATUS_IRQ_VEC_SHIFT                 (0U)
#define BEE_STATUS_IRQ_VEC(x)                    (((uint32_t)(((uint32_t)(x)) << BEE_STATUS_IRQ_VEC_SHIFT)) & BEE_STATUS_IRQ_VEC_MASK)

#define BEE_STATUS_BEE_IDLE_MASK                 (0x100U)
#define BEE_STATUS_BEE_IDLE_SHIFT                (8U)
#define BEE_STATUS_BEE_IDLE(x)                   (((uint32_t)(((uint32_t)(x)) << BEE_STATUS_BEE_IDLE_SHIFT)) & BEE_STATUS_BEE_IDLE_MASK)
/*! @} */

/*! @name CTR_NONCE0_W0 - NONCE00 Register */
/*! @{ */

#define BEE_CTR_NONCE0_W0_NONCE00_MASK           (0xFFFFFFFFU)
#define BEE_CTR_NONCE0_W0_NONCE00_SHIFT          (0U)
#define BEE_CTR_NONCE0_W0_NONCE00(x)             (((uint32_t)(((uint32_t)(x)) << BEE_CTR_NONCE0_W0_NONCE00_SHIFT)) & BEE_CTR_NONCE0_W0_NONCE00_MASK)
/*! @} */

/*! @name CTR_NONCE0_W1 - NONCE01 Register */
/*! @{ */

#define BEE_CTR_NONCE0_W1_NONCE01_MASK           (0xFFFFFFFFU)
#define BEE_CTR_NONCE0_W1_NONCE01_SHIFT          (0U)
#define BEE_CTR_NONCE0_W1_NONCE01(x)             (((uint32_t)(((uint32_t)(x)) << BEE_CTR_NONCE0_W1_NONCE01_SHIFT)) & BEE_CTR_NONCE0_W1_NONCE01_MASK)
/*! @} */

/*! @name CTR_NONCE0_W2 - NONCE02 Register */
/*! @{ */

#define BEE_CTR_NONCE0_W2_NONCE02_MASK           (0xFFFFFFFFU)
#define BEE_CTR_NONCE0_W2_NONCE02_SHIFT          (0U)
#define BEE_CTR_NONCE0_W2_NONCE02(x)             (((uint32_t)(((uint32_t)(x)) << BEE_CTR_NONCE0_W2_NONCE02_SHIFT)) & BEE_CTR_NONCE0_W2_NONCE02_MASK)
/*! @} */

/*! @name CTR_NONCE0_W3 - NONCE03 Register */
/*! @{ */

#define BEE_CTR_NONCE0_W3_NONCE03_MASK           (0xFFFFFFFFU)
#define BEE_CTR_NONCE0_W3_NONCE03_SHIFT          (0U)
#define BEE_CTR_NONCE0_W3_NONCE03(x)             (((uint32_t)(((uint32_t)(x)) << BEE_CTR_NONCE0_W3_NONCE03_SHIFT)) & BEE_CTR_NONCE0_W3_NONCE03_MASK)
/*! @} */

/*! @name CTR_NONCE1_W0 - NONCE10 Register */
/*! @{ */

#define BEE_CTR_NONCE1_W0_NONCE10_MASK           (0xFFFFFFFFU)
#define BEE_CTR_NONCE1_W0_NONCE10_SHIFT          (0U)
#define BEE_CTR_NONCE1_W0_NONCE10(x)             (((uint32_t)(((uint32_t)(x)) << BEE_CTR_NONCE1_W0_NONCE10_SHIFT)) & BEE_CTR_NONCE1_W0_NONCE10_MASK)
/*! @} */

/*! @name CTR_NONCE1_W1 - NONCE11 Register */
/*! @{ */

#define BEE_CTR_NONCE1_W1_NONCE11_MASK           (0xFFFFFFFFU)
#define BEE_CTR_NONCE1_W1_NONCE11_SHIFT          (0U)
#define BEE_CTR_NONCE1_W1_NONCE11(x)             (((uint32_t)(((uint32_t)(x)) << BEE_CTR_NONCE1_W1_NONCE11_SHIFT)) & BEE_CTR_NONCE1_W1_NONCE11_MASK)
/*! @} */

/*! @name CTR_NONCE1_W2 - NONCE12 Register */
/*! @{ */

#define BEE_CTR_NONCE1_W2_NONCE12_MASK           (0xFFFFFFFFU)
#define BEE_CTR_NONCE1_W2_NONCE12_SHIFT          (0U)
#define BEE_CTR_NONCE1_W2_NONCE12(x)             (((uint32_t)(((uint32_t)(x)) << BEE_CTR_NONCE1_W2_NONCE12_SHIFT)) & BEE_CTR_NONCE1_W2_NONCE12_MASK)
/*! @} */

/*! @name CTR_NONCE1_W3 - NONCE13 Register */
/*! @{ */

#define BEE_CTR_NONCE1_W3_NONCE13_MASK           (0xFFFFFFFFU)
#define BEE_CTR_NONCE1_W3_NONCE13_SHIFT          (0U)
#define BEE_CTR_NONCE1_W3_NONCE13(x)             (((uint32_t)(((uint32_t)(x)) << BEE_CTR_NONCE1_W3_NONCE13_SHIFT)) & BEE_CTR_NONCE1_W3_NONCE13_MASK)
/*! @} */

/*! @name REGION1_TOP - Region1 Top Address Register */
/*! @{ */

#define BEE_REGION1_TOP_REGION1_TOP_MASK         (0xFFFFFFFFU)
#define BEE_REGION1_TOP_REGION1_TOP_SHIFT        (0U)
/*! REGION1_TOP - Address upper limit of region1 */
#define BEE_REGION1_TOP_REGION1_TOP(x)           (((uint32_t)(((uint32_t)(x)) << BEE_REGION1_TOP_REGION1_TOP_SHIFT)) & BEE_REGION1_TOP_REGION1_TOP_MASK)
/*! @} */

/*! @name REGION1_BOT - Region1 Bottom Address Register */
/*! @{ */

#define BEE_REGION1_BOT_REGION1_BOT_MASK         (0xFFFFFFFFU)
#define BEE_REGION1_BOT_REGION1_BOT_SHIFT        (0U)
/*! REGION1_BOT - Address lower limit of region1 */
#define BEE_REGION1_BOT_REGION1_BOT(x)           (((uint32_t)(((uint32_t)(x)) << BEE_REGION1_BOT_REGION1_BOT_SHIFT)) & BEE_REGION1_BOT_REGION1_BOT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BEE_Register_Masks */


/*!
 * @}
 */ /* end of group BEE_Peripheral_Access_Layer */


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


#endif  /* PERI_BEE_H_ */

