/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GPMI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_GPMI.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPMI
 *
 * CMSIS Peripheral Access Layer for GPMI
 */

#if !defined(PERI_GPMI_H_)
#define PERI_GPMI_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- GPMI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPMI_Peripheral_Access_Layer GPMI Peripheral Access Layer
 * @{
 */

/** GPMI - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL0;                             /**< GPMI Control Register 0 Description, offset: 0x0 */
  __IO uint32_t CTRL0_SET;                         /**< GPMI Control Register 0 Description, offset: 0x4 */
  __IO uint32_t CTRL0_CLR;                         /**< GPMI Control Register 0 Description, offset: 0x8 */
  __IO uint32_t CTRL0_TOG;                         /**< GPMI Control Register 0 Description, offset: 0xC */
  __IO uint32_t COMPARE;                           /**< GPMI Compare Register Description, offset: 0x10 */
       uint8_t RESERVED_0[12];
  __IO uint32_t ECCCTRL;                           /**< GPMI Integrated ECC Control Register Description, offset: 0x20 */
  __IO uint32_t ECCCTRL_SET;                       /**< GPMI Integrated ECC Control Register Description, offset: 0x24 */
  __IO uint32_t ECCCTRL_CLR;                       /**< GPMI Integrated ECC Control Register Description, offset: 0x28 */
  __IO uint32_t ECCCTRL_TOG;                       /**< GPMI Integrated ECC Control Register Description, offset: 0x2C */
  __IO uint32_t ECCCOUNT;                          /**< GPMI Integrated ECC Transfer Count Register Description, offset: 0x30 */
       uint8_t RESERVED_1[12];
  __IO uint32_t PAYLOAD;                           /**< GPMI Payload Address Register Description, offset: 0x40 */
       uint8_t RESERVED_2[12];
  __IO uint32_t AUXILIARY;                         /**< GPMI Auxiliary Address Register Description, offset: 0x50 */
       uint8_t RESERVED_3[12];
  __IO uint32_t CTRL1;                             /**< GPMI Control Register 1 Description, offset: 0x60 */
  __IO uint32_t CTRL1_SET;                         /**< GPMI Control Register 1 Description, offset: 0x64 */
  __IO uint32_t CTRL1_CLR;                         /**< GPMI Control Register 1 Description, offset: 0x68 */
  __IO uint32_t CTRL1_TOG;                         /**< GPMI Control Register 1 Description, offset: 0x6C */
  __IO uint32_t TIMING0;                           /**< GPMI Timing Register 0 Description, offset: 0x70 */
       uint8_t RESERVED_4[12];
  __IO uint32_t TIMING1;                           /**< GPMI Timing Register 1 Description, offset: 0x80 */
       uint8_t RESERVED_5[12];
  __IO uint32_t TIMING2;                           /**< GPMI Timing Register 2 Description, offset: 0x90 */
       uint8_t RESERVED_6[12];
  __IO uint32_t DATA;                              /**< GPMI DMA Data Transfer Register Description, offset: 0xA0 */
       uint8_t RESERVED_7[12];
  __I  uint32_t STAT;                              /**< GPMI Status Register Description, offset: 0xB0 */
       uint8_t RESERVED_8[12];
  __I  uint32_t DEBUGr;                            /**< GPMI Debug Information Register Description, offset: 0xC0, 'r' suffix has been added to avoid clash with DEBUG symbolic constant */
       uint8_t RESERVED_9[12];
  __I  uint32_t VERSION;                           /**< GPMI Version Register Description, offset: 0xD0 */
       uint8_t RESERVED_10[12];
  __IO uint32_t DEBUG2;                            /**< GPMI Debug2 Information Register Description, offset: 0xE0 */
       uint8_t RESERVED_11[12];
  __I  uint32_t DEBUG3;                            /**< GPMI Debug3 Information Register Description, offset: 0xF0 */
       uint8_t RESERVED_12[12];
  __IO uint32_t READ_DDR_DLL_CTRL;                 /**< GPMI Double Rate Read DLL Control Register Description, offset: 0x100 */
       uint8_t RESERVED_13[12];
  __IO uint32_t WRITE_DDR_DLL_CTRL;                /**< GPMI Double Rate Write DLL Control Register Description, offset: 0x110 */
       uint8_t RESERVED_14[12];
  __I  uint32_t READ_DDR_DLL_STS;                  /**< GPMI Double Rate Read DLL Status Register Description, offset: 0x120 */
       uint8_t RESERVED_15[12];
  __I  uint32_t WRITE_DDR_DLL_STS;                 /**< GPMI Double Rate Write DLL Status Register Description, offset: 0x130 */
} GPMI_Type;

/* ----------------------------------------------------------------------------
   -- GPMI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPMI_Register_Masks GPMI Register Masks
 * @{
 */

/*! @name CTRL0 - GPMI Control Register 0 Description */
/*! @{ */

#define GPMI_CTRL0_XFER_COUNT_MASK               (0xFFFFU)
#define GPMI_CTRL0_XFER_COUNT_SHIFT              (0U)
#define GPMI_CTRL0_XFER_COUNT(x)                 (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_XFER_COUNT_SHIFT)) & GPMI_CTRL0_XFER_COUNT_MASK)

#define GPMI_CTRL0_ADDRESS_INCREMENT_MASK        (0x10000U)
#define GPMI_CTRL0_ADDRESS_INCREMENT_SHIFT       (16U)
/*! ADDRESS_INCREMENT
 *  0b0..Address does not increment.
 *  0b1..Increment address.
 */
#define GPMI_CTRL0_ADDRESS_INCREMENT(x)          (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_ADDRESS_INCREMENT_SHIFT)) & GPMI_CTRL0_ADDRESS_INCREMENT_MASK)

#define GPMI_CTRL0_ADDRESS_MASK                  (0xE0000U)
#define GPMI_CTRL0_ADDRESS_SHIFT                 (17U)
#define GPMI_CTRL0_ADDRESS(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_ADDRESS_SHIFT)) & GPMI_CTRL0_ADDRESS_MASK)

#define GPMI_CTRL0_CS_MASK                       (0x700000U)
#define GPMI_CTRL0_CS_SHIFT                      (20U)
#define GPMI_CTRL0_CS(x)                         (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_CS_SHIFT)) & GPMI_CTRL0_CS_MASK)

#define GPMI_CTRL0_WORD_LENGTH_MASK              (0x800000U)
#define GPMI_CTRL0_WORD_LENGTH_SHIFT             (23U)
/*! WORD_LENGTH
 *  0b0..Reserved.
 *  0b1..8-bit Data Bus mode.
 */
#define GPMI_CTRL0_WORD_LENGTH(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_WORD_LENGTH_SHIFT)) & GPMI_CTRL0_WORD_LENGTH_MASK)

#define GPMI_CTRL0_COMMAND_MODE_MASK             (0x3000000U)
#define GPMI_CTRL0_COMMAND_MODE_SHIFT            (24U)
/*! COMMAND_MODE
 *  0b00..Write mode.
 *  0b01..Read Mode.
 *  0b10..Read and Compare Mode (setting sense flop).
 *  0b11..Wait for Ready.
 */
#define GPMI_CTRL0_COMMAND_MODE(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_COMMAND_MODE_SHIFT)) & GPMI_CTRL0_COMMAND_MODE_MASK)

#define GPMI_CTRL0_UDMA_MASK                     (0x4000000U)
#define GPMI_CTRL0_UDMA_SHIFT                    (26U)
/*! UDMA
 *  0b0..Use ATA-PIO mode on the external bus.
 *  0b1..Use ATA-Ultra DMA mode on the external bus.
 */
#define GPMI_CTRL0_UDMA(x)                       (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_UDMA_SHIFT)) & GPMI_CTRL0_UDMA_MASK)

#define GPMI_CTRL0_LOCK_CS_MASK                  (0x8000000U)
#define GPMI_CTRL0_LOCK_CS_SHIFT                 (27U)
#define GPMI_CTRL0_LOCK_CS(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_LOCK_CS_SHIFT)) & GPMI_CTRL0_LOCK_CS_MASK)

#define GPMI_CTRL0_DEV_IRQ_EN_MASK               (0x10000000U)
#define GPMI_CTRL0_DEV_IRQ_EN_SHIFT              (28U)
#define GPMI_CTRL0_DEV_IRQ_EN(x)                 (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_DEV_IRQ_EN_SHIFT)) & GPMI_CTRL0_DEV_IRQ_EN_MASK)

#define GPMI_CTRL0_RUN_MASK                      (0x20000000U)
#define GPMI_CTRL0_RUN_SHIFT                     (29U)
#define GPMI_CTRL0_RUN(x)                        (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_RUN_SHIFT)) & GPMI_CTRL0_RUN_MASK)

#define GPMI_CTRL0_CLKGATE_MASK                  (0x40000000U)
#define GPMI_CTRL0_CLKGATE_SHIFT                 (30U)
#define GPMI_CTRL0_CLKGATE(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_CLKGATE_SHIFT)) & GPMI_CTRL0_CLKGATE_MASK)

#define GPMI_CTRL0_SFTRST_MASK                   (0x80000000U)
#define GPMI_CTRL0_SFTRST_SHIFT                  (31U)
#define GPMI_CTRL0_SFTRST(x)                     (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_SFTRST_SHIFT)) & GPMI_CTRL0_SFTRST_MASK)
/*! @} */

/*! @name CTRL0_SET - GPMI Control Register 0 Description */
/*! @{ */

#define GPMI_CTRL0_SET_XFER_COUNT_MASK           (0xFFFFU)
#define GPMI_CTRL0_SET_XFER_COUNT_SHIFT          (0U)
#define GPMI_CTRL0_SET_XFER_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_SET_XFER_COUNT_SHIFT)) & GPMI_CTRL0_SET_XFER_COUNT_MASK)

#define GPMI_CTRL0_SET_ADDRESS_INCREMENT_MASK    (0x10000U)
#define GPMI_CTRL0_SET_ADDRESS_INCREMENT_SHIFT   (16U)
/*! ADDRESS_INCREMENT
 *  0b0..Address does not increment.
 *  0b1..Increment address.
 */
#define GPMI_CTRL0_SET_ADDRESS_INCREMENT(x)      (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_SET_ADDRESS_INCREMENT_SHIFT)) & GPMI_CTRL0_SET_ADDRESS_INCREMENT_MASK)

#define GPMI_CTRL0_SET_ADDRESS_MASK              (0xE0000U)
#define GPMI_CTRL0_SET_ADDRESS_SHIFT             (17U)
#define GPMI_CTRL0_SET_ADDRESS(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_SET_ADDRESS_SHIFT)) & GPMI_CTRL0_SET_ADDRESS_MASK)

#define GPMI_CTRL0_SET_CS_MASK                   (0x700000U)
#define GPMI_CTRL0_SET_CS_SHIFT                  (20U)
#define GPMI_CTRL0_SET_CS(x)                     (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_SET_CS_SHIFT)) & GPMI_CTRL0_SET_CS_MASK)

#define GPMI_CTRL0_SET_WORD_LENGTH_MASK          (0x800000U)
#define GPMI_CTRL0_SET_WORD_LENGTH_SHIFT         (23U)
/*! WORD_LENGTH
 *  0b0..Reserved.
 *  0b1..8-bit Data Bus mode.
 */
#define GPMI_CTRL0_SET_WORD_LENGTH(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_SET_WORD_LENGTH_SHIFT)) & GPMI_CTRL0_SET_WORD_LENGTH_MASK)

#define GPMI_CTRL0_SET_COMMAND_MODE_MASK         (0x3000000U)
#define GPMI_CTRL0_SET_COMMAND_MODE_SHIFT        (24U)
/*! COMMAND_MODE
 *  0b00..Write mode.
 *  0b01..Read Mode.
 *  0b10..Read and Compare Mode (setting sense flop).
 *  0b11..Wait for Ready.
 */
#define GPMI_CTRL0_SET_COMMAND_MODE(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_SET_COMMAND_MODE_SHIFT)) & GPMI_CTRL0_SET_COMMAND_MODE_MASK)

#define GPMI_CTRL0_SET_UDMA_MASK                 (0x4000000U)
#define GPMI_CTRL0_SET_UDMA_SHIFT                (26U)
/*! UDMA
 *  0b0..Use ATA-PIO mode on the external bus.
 *  0b1..Use ATA-Ultra DMA mode on the external bus.
 */
#define GPMI_CTRL0_SET_UDMA(x)                   (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_SET_UDMA_SHIFT)) & GPMI_CTRL0_SET_UDMA_MASK)

#define GPMI_CTRL0_SET_LOCK_CS_MASK              (0x8000000U)
#define GPMI_CTRL0_SET_LOCK_CS_SHIFT             (27U)
#define GPMI_CTRL0_SET_LOCK_CS(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_SET_LOCK_CS_SHIFT)) & GPMI_CTRL0_SET_LOCK_CS_MASK)

#define GPMI_CTRL0_SET_DEV_IRQ_EN_MASK           (0x10000000U)
#define GPMI_CTRL0_SET_DEV_IRQ_EN_SHIFT          (28U)
#define GPMI_CTRL0_SET_DEV_IRQ_EN(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_SET_DEV_IRQ_EN_SHIFT)) & GPMI_CTRL0_SET_DEV_IRQ_EN_MASK)

#define GPMI_CTRL0_SET_RUN_MASK                  (0x20000000U)
#define GPMI_CTRL0_SET_RUN_SHIFT                 (29U)
#define GPMI_CTRL0_SET_RUN(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_SET_RUN_SHIFT)) & GPMI_CTRL0_SET_RUN_MASK)

#define GPMI_CTRL0_SET_CLKGATE_MASK              (0x40000000U)
#define GPMI_CTRL0_SET_CLKGATE_SHIFT             (30U)
#define GPMI_CTRL0_SET_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_SET_CLKGATE_SHIFT)) & GPMI_CTRL0_SET_CLKGATE_MASK)

#define GPMI_CTRL0_SET_SFTRST_MASK               (0x80000000U)
#define GPMI_CTRL0_SET_SFTRST_SHIFT              (31U)
#define GPMI_CTRL0_SET_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_SET_SFTRST_SHIFT)) & GPMI_CTRL0_SET_SFTRST_MASK)
/*! @} */

/*! @name CTRL0_CLR - GPMI Control Register 0 Description */
/*! @{ */

#define GPMI_CTRL0_CLR_XFER_COUNT_MASK           (0xFFFFU)
#define GPMI_CTRL0_CLR_XFER_COUNT_SHIFT          (0U)
#define GPMI_CTRL0_CLR_XFER_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_CLR_XFER_COUNT_SHIFT)) & GPMI_CTRL0_CLR_XFER_COUNT_MASK)

#define GPMI_CTRL0_CLR_ADDRESS_INCREMENT_MASK    (0x10000U)
#define GPMI_CTRL0_CLR_ADDRESS_INCREMENT_SHIFT   (16U)
/*! ADDRESS_INCREMENT
 *  0b0..Address does not increment.
 *  0b1..Increment address.
 */
#define GPMI_CTRL0_CLR_ADDRESS_INCREMENT(x)      (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_CLR_ADDRESS_INCREMENT_SHIFT)) & GPMI_CTRL0_CLR_ADDRESS_INCREMENT_MASK)

#define GPMI_CTRL0_CLR_ADDRESS_MASK              (0xE0000U)
#define GPMI_CTRL0_CLR_ADDRESS_SHIFT             (17U)
#define GPMI_CTRL0_CLR_ADDRESS(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_CLR_ADDRESS_SHIFT)) & GPMI_CTRL0_CLR_ADDRESS_MASK)

#define GPMI_CTRL0_CLR_CS_MASK                   (0x700000U)
#define GPMI_CTRL0_CLR_CS_SHIFT                  (20U)
#define GPMI_CTRL0_CLR_CS(x)                     (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_CLR_CS_SHIFT)) & GPMI_CTRL0_CLR_CS_MASK)

#define GPMI_CTRL0_CLR_WORD_LENGTH_MASK          (0x800000U)
#define GPMI_CTRL0_CLR_WORD_LENGTH_SHIFT         (23U)
/*! WORD_LENGTH
 *  0b0..Reserved.
 *  0b1..8-bit Data Bus mode.
 */
#define GPMI_CTRL0_CLR_WORD_LENGTH(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_CLR_WORD_LENGTH_SHIFT)) & GPMI_CTRL0_CLR_WORD_LENGTH_MASK)

#define GPMI_CTRL0_CLR_COMMAND_MODE_MASK         (0x3000000U)
#define GPMI_CTRL0_CLR_COMMAND_MODE_SHIFT        (24U)
/*! COMMAND_MODE
 *  0b00..Write mode.
 *  0b01..Read Mode.
 *  0b10..Read and Compare Mode (setting sense flop).
 *  0b11..Wait for Ready.
 */
#define GPMI_CTRL0_CLR_COMMAND_MODE(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_CLR_COMMAND_MODE_SHIFT)) & GPMI_CTRL0_CLR_COMMAND_MODE_MASK)

#define GPMI_CTRL0_CLR_UDMA_MASK                 (0x4000000U)
#define GPMI_CTRL0_CLR_UDMA_SHIFT                (26U)
/*! UDMA
 *  0b0..Use ATA-PIO mode on the external bus.
 *  0b1..Use ATA-Ultra DMA mode on the external bus.
 */
#define GPMI_CTRL0_CLR_UDMA(x)                   (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_CLR_UDMA_SHIFT)) & GPMI_CTRL0_CLR_UDMA_MASK)

#define GPMI_CTRL0_CLR_LOCK_CS_MASK              (0x8000000U)
#define GPMI_CTRL0_CLR_LOCK_CS_SHIFT             (27U)
#define GPMI_CTRL0_CLR_LOCK_CS(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_CLR_LOCK_CS_SHIFT)) & GPMI_CTRL0_CLR_LOCK_CS_MASK)

#define GPMI_CTRL0_CLR_DEV_IRQ_EN_MASK           (0x10000000U)
#define GPMI_CTRL0_CLR_DEV_IRQ_EN_SHIFT          (28U)
#define GPMI_CTRL0_CLR_DEV_IRQ_EN(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_CLR_DEV_IRQ_EN_SHIFT)) & GPMI_CTRL0_CLR_DEV_IRQ_EN_MASK)

#define GPMI_CTRL0_CLR_RUN_MASK                  (0x20000000U)
#define GPMI_CTRL0_CLR_RUN_SHIFT                 (29U)
#define GPMI_CTRL0_CLR_RUN(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_CLR_RUN_SHIFT)) & GPMI_CTRL0_CLR_RUN_MASK)

#define GPMI_CTRL0_CLR_CLKGATE_MASK              (0x40000000U)
#define GPMI_CTRL0_CLR_CLKGATE_SHIFT             (30U)
#define GPMI_CTRL0_CLR_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_CLR_CLKGATE_SHIFT)) & GPMI_CTRL0_CLR_CLKGATE_MASK)

#define GPMI_CTRL0_CLR_SFTRST_MASK               (0x80000000U)
#define GPMI_CTRL0_CLR_SFTRST_SHIFT              (31U)
#define GPMI_CTRL0_CLR_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_CLR_SFTRST_SHIFT)) & GPMI_CTRL0_CLR_SFTRST_MASK)
/*! @} */

/*! @name CTRL0_TOG - GPMI Control Register 0 Description */
/*! @{ */

#define GPMI_CTRL0_TOG_XFER_COUNT_MASK           (0xFFFFU)
#define GPMI_CTRL0_TOG_XFER_COUNT_SHIFT          (0U)
#define GPMI_CTRL0_TOG_XFER_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_TOG_XFER_COUNT_SHIFT)) & GPMI_CTRL0_TOG_XFER_COUNT_MASK)

#define GPMI_CTRL0_TOG_ADDRESS_INCREMENT_MASK    (0x10000U)
#define GPMI_CTRL0_TOG_ADDRESS_INCREMENT_SHIFT   (16U)
/*! ADDRESS_INCREMENT
 *  0b0..Address does not increment.
 *  0b1..Increment address.
 */
#define GPMI_CTRL0_TOG_ADDRESS_INCREMENT(x)      (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_TOG_ADDRESS_INCREMENT_SHIFT)) & GPMI_CTRL0_TOG_ADDRESS_INCREMENT_MASK)

#define GPMI_CTRL0_TOG_ADDRESS_MASK              (0xE0000U)
#define GPMI_CTRL0_TOG_ADDRESS_SHIFT             (17U)
#define GPMI_CTRL0_TOG_ADDRESS(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_TOG_ADDRESS_SHIFT)) & GPMI_CTRL0_TOG_ADDRESS_MASK)

#define GPMI_CTRL0_TOG_CS_MASK                   (0x700000U)
#define GPMI_CTRL0_TOG_CS_SHIFT                  (20U)
#define GPMI_CTRL0_TOG_CS(x)                     (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_TOG_CS_SHIFT)) & GPMI_CTRL0_TOG_CS_MASK)

#define GPMI_CTRL0_TOG_WORD_LENGTH_MASK          (0x800000U)
#define GPMI_CTRL0_TOG_WORD_LENGTH_SHIFT         (23U)
/*! WORD_LENGTH
 *  0b0..Reserved.
 *  0b1..8-bit Data Bus mode.
 */
#define GPMI_CTRL0_TOG_WORD_LENGTH(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_TOG_WORD_LENGTH_SHIFT)) & GPMI_CTRL0_TOG_WORD_LENGTH_MASK)

#define GPMI_CTRL0_TOG_COMMAND_MODE_MASK         (0x3000000U)
#define GPMI_CTRL0_TOG_COMMAND_MODE_SHIFT        (24U)
/*! COMMAND_MODE
 *  0b00..Write mode.
 *  0b01..Read Mode.
 *  0b10..Read and Compare Mode (setting sense flop).
 *  0b11..Wait for Ready.
 */
#define GPMI_CTRL0_TOG_COMMAND_MODE(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_TOG_COMMAND_MODE_SHIFT)) & GPMI_CTRL0_TOG_COMMAND_MODE_MASK)

#define GPMI_CTRL0_TOG_UDMA_MASK                 (0x4000000U)
#define GPMI_CTRL0_TOG_UDMA_SHIFT                (26U)
/*! UDMA
 *  0b0..Use ATA-PIO mode on the external bus.
 *  0b1..Use ATA-Ultra DMA mode on the external bus.
 */
#define GPMI_CTRL0_TOG_UDMA(x)                   (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_TOG_UDMA_SHIFT)) & GPMI_CTRL0_TOG_UDMA_MASK)

#define GPMI_CTRL0_TOG_LOCK_CS_MASK              (0x8000000U)
#define GPMI_CTRL0_TOG_LOCK_CS_SHIFT             (27U)
#define GPMI_CTRL0_TOG_LOCK_CS(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_TOG_LOCK_CS_SHIFT)) & GPMI_CTRL0_TOG_LOCK_CS_MASK)

#define GPMI_CTRL0_TOG_DEV_IRQ_EN_MASK           (0x10000000U)
#define GPMI_CTRL0_TOG_DEV_IRQ_EN_SHIFT          (28U)
#define GPMI_CTRL0_TOG_DEV_IRQ_EN(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_TOG_DEV_IRQ_EN_SHIFT)) & GPMI_CTRL0_TOG_DEV_IRQ_EN_MASK)

#define GPMI_CTRL0_TOG_RUN_MASK                  (0x20000000U)
#define GPMI_CTRL0_TOG_RUN_SHIFT                 (29U)
#define GPMI_CTRL0_TOG_RUN(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_TOG_RUN_SHIFT)) & GPMI_CTRL0_TOG_RUN_MASK)

#define GPMI_CTRL0_TOG_CLKGATE_MASK              (0x40000000U)
#define GPMI_CTRL0_TOG_CLKGATE_SHIFT             (30U)
#define GPMI_CTRL0_TOG_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_TOG_CLKGATE_SHIFT)) & GPMI_CTRL0_TOG_CLKGATE_MASK)

#define GPMI_CTRL0_TOG_SFTRST_MASK               (0x80000000U)
#define GPMI_CTRL0_TOG_SFTRST_SHIFT              (31U)
#define GPMI_CTRL0_TOG_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL0_TOG_SFTRST_SHIFT)) & GPMI_CTRL0_TOG_SFTRST_MASK)
/*! @} */

/*! @name COMPARE - GPMI Compare Register Description */
/*! @{ */

#define GPMI_COMPARE_REFERENCE_MASK              (0xFFFFU)
#define GPMI_COMPARE_REFERENCE_SHIFT             (0U)
#define GPMI_COMPARE_REFERENCE(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_COMPARE_REFERENCE_SHIFT)) & GPMI_COMPARE_REFERENCE_MASK)

#define GPMI_COMPARE_MASK_MASK                   (0xFFFF0000U)
#define GPMI_COMPARE_MASK_SHIFT                  (16U)
#define GPMI_COMPARE_MASK(x)                     (((uint32_t)(((uint32_t)(x)) << GPMI_COMPARE_MASK_SHIFT)) & GPMI_COMPARE_MASK_MASK)
/*! @} */

/*! @name ECCCTRL - GPMI Integrated ECC Control Register Description */
/*! @{ */

#define GPMI_ECCCTRL_BUFFER_MASK_MASK            (0x1FFU)
#define GPMI_ECCCTRL_BUFFER_MASK_SHIFT           (0U)
#define GPMI_ECCCTRL_BUFFER_MASK(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_BUFFER_MASK_SHIFT)) & GPMI_ECCCTRL_BUFFER_MASK_MASK)

#define GPMI_ECCCTRL_RANDOMIZER_TYPE_MASK        (0x600U)
#define GPMI_ECCCTRL_RANDOMIZER_TYPE_SHIFT       (9U)
/*! RANDOMIZER_TYPE
 *  0b00..Type 0
 *  0b01..Type 1
 */
#define GPMI_ECCCTRL_RANDOMIZER_TYPE(x)          (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_RANDOMIZER_TYPE_SHIFT)) & GPMI_ECCCTRL_RANDOMIZER_TYPE_MASK)

#define GPMI_ECCCTRL_RANDOMIZER_ENABLE_MASK      (0x800U)
#define GPMI_ECCCTRL_RANDOMIZER_ENABLE_SHIFT     (11U)
/*! RANDOMIZER_ENABLE
 *  0b0..disable
 *  0b1..enable
 */
#define GPMI_ECCCTRL_RANDOMIZER_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_RANDOMIZER_ENABLE_SHIFT)) & GPMI_ECCCTRL_RANDOMIZER_ENABLE_MASK)

#define GPMI_ECCCTRL_ENABLE_ECC_MASK             (0x1000U)
#define GPMI_ECCCTRL_ENABLE_ECC_SHIFT            (12U)
#define GPMI_ECCCTRL_ENABLE_ECC(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_ENABLE_ECC_SHIFT)) & GPMI_ECCCTRL_ENABLE_ECC_MASK)

#define GPMI_ECCCTRL_ECC_CMD_MASK                (0x6000U)
#define GPMI_ECCCTRL_ECC_CMD_SHIFT               (13U)
#define GPMI_ECCCTRL_ECC_CMD(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_ECC_CMD_SHIFT)) & GPMI_ECCCTRL_ECC_CMD_MASK)

#define GPMI_ECCCTRL_RSVD2_MASK                  (0x8000U)
#define GPMI_ECCCTRL_RSVD2_SHIFT                 (15U)
#define GPMI_ECCCTRL_RSVD2(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_RSVD2_SHIFT)) & GPMI_ECCCTRL_RSVD2_MASK)

#define GPMI_ECCCTRL_HANDLE_MASK                 (0xFFFF0000U)
#define GPMI_ECCCTRL_HANDLE_SHIFT                (16U)
#define GPMI_ECCCTRL_HANDLE(x)                   (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_HANDLE_SHIFT)) & GPMI_ECCCTRL_HANDLE_MASK)
/*! @} */

/*! @name ECCCTRL_SET - GPMI Integrated ECC Control Register Description */
/*! @{ */

#define GPMI_ECCCTRL_SET_BUFFER_MASK_MASK        (0x1FFU)
#define GPMI_ECCCTRL_SET_BUFFER_MASK_SHIFT       (0U)
#define GPMI_ECCCTRL_SET_BUFFER_MASK(x)          (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_SET_BUFFER_MASK_SHIFT)) & GPMI_ECCCTRL_SET_BUFFER_MASK_MASK)

#define GPMI_ECCCTRL_SET_RANDOMIZER_TYPE_MASK    (0x600U)
#define GPMI_ECCCTRL_SET_RANDOMIZER_TYPE_SHIFT   (9U)
/*! RANDOMIZER_TYPE
 *  0b00..Type 0
 *  0b01..Type 1
 */
#define GPMI_ECCCTRL_SET_RANDOMIZER_TYPE(x)      (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_SET_RANDOMIZER_TYPE_SHIFT)) & GPMI_ECCCTRL_SET_RANDOMIZER_TYPE_MASK)

#define GPMI_ECCCTRL_SET_RANDOMIZER_ENABLE_MASK  (0x800U)
#define GPMI_ECCCTRL_SET_RANDOMIZER_ENABLE_SHIFT (11U)
/*! RANDOMIZER_ENABLE
 *  0b0..disable
 *  0b1..enable
 */
#define GPMI_ECCCTRL_SET_RANDOMIZER_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_SET_RANDOMIZER_ENABLE_SHIFT)) & GPMI_ECCCTRL_SET_RANDOMIZER_ENABLE_MASK)

#define GPMI_ECCCTRL_SET_ENABLE_ECC_MASK         (0x1000U)
#define GPMI_ECCCTRL_SET_ENABLE_ECC_SHIFT        (12U)
#define GPMI_ECCCTRL_SET_ENABLE_ECC(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_SET_ENABLE_ECC_SHIFT)) & GPMI_ECCCTRL_SET_ENABLE_ECC_MASK)

#define GPMI_ECCCTRL_SET_ECC_CMD_MASK            (0x6000U)
#define GPMI_ECCCTRL_SET_ECC_CMD_SHIFT           (13U)
#define GPMI_ECCCTRL_SET_ECC_CMD(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_SET_ECC_CMD_SHIFT)) & GPMI_ECCCTRL_SET_ECC_CMD_MASK)

#define GPMI_ECCCTRL_SET_RSVD2_MASK              (0x8000U)
#define GPMI_ECCCTRL_SET_RSVD2_SHIFT             (15U)
#define GPMI_ECCCTRL_SET_RSVD2(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_SET_RSVD2_SHIFT)) & GPMI_ECCCTRL_SET_RSVD2_MASK)

#define GPMI_ECCCTRL_SET_HANDLE_MASK             (0xFFFF0000U)
#define GPMI_ECCCTRL_SET_HANDLE_SHIFT            (16U)
#define GPMI_ECCCTRL_SET_HANDLE(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_SET_HANDLE_SHIFT)) & GPMI_ECCCTRL_SET_HANDLE_MASK)
/*! @} */

/*! @name ECCCTRL_CLR - GPMI Integrated ECC Control Register Description */
/*! @{ */

#define GPMI_ECCCTRL_CLR_BUFFER_MASK_MASK        (0x1FFU)
#define GPMI_ECCCTRL_CLR_BUFFER_MASK_SHIFT       (0U)
#define GPMI_ECCCTRL_CLR_BUFFER_MASK(x)          (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_CLR_BUFFER_MASK_SHIFT)) & GPMI_ECCCTRL_CLR_BUFFER_MASK_MASK)

#define GPMI_ECCCTRL_CLR_RANDOMIZER_TYPE_MASK    (0x600U)
#define GPMI_ECCCTRL_CLR_RANDOMIZER_TYPE_SHIFT   (9U)
/*! RANDOMIZER_TYPE
 *  0b00..Type 0
 *  0b01..Type 1
 */
#define GPMI_ECCCTRL_CLR_RANDOMIZER_TYPE(x)      (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_CLR_RANDOMIZER_TYPE_SHIFT)) & GPMI_ECCCTRL_CLR_RANDOMIZER_TYPE_MASK)

#define GPMI_ECCCTRL_CLR_RANDOMIZER_ENABLE_MASK  (0x800U)
#define GPMI_ECCCTRL_CLR_RANDOMIZER_ENABLE_SHIFT (11U)
/*! RANDOMIZER_ENABLE
 *  0b0..disable
 *  0b1..enable
 */
#define GPMI_ECCCTRL_CLR_RANDOMIZER_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_CLR_RANDOMIZER_ENABLE_SHIFT)) & GPMI_ECCCTRL_CLR_RANDOMIZER_ENABLE_MASK)

#define GPMI_ECCCTRL_CLR_ENABLE_ECC_MASK         (0x1000U)
#define GPMI_ECCCTRL_CLR_ENABLE_ECC_SHIFT        (12U)
#define GPMI_ECCCTRL_CLR_ENABLE_ECC(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_CLR_ENABLE_ECC_SHIFT)) & GPMI_ECCCTRL_CLR_ENABLE_ECC_MASK)

#define GPMI_ECCCTRL_CLR_ECC_CMD_MASK            (0x6000U)
#define GPMI_ECCCTRL_CLR_ECC_CMD_SHIFT           (13U)
#define GPMI_ECCCTRL_CLR_ECC_CMD(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_CLR_ECC_CMD_SHIFT)) & GPMI_ECCCTRL_CLR_ECC_CMD_MASK)

#define GPMI_ECCCTRL_CLR_RSVD2_MASK              (0x8000U)
#define GPMI_ECCCTRL_CLR_RSVD2_SHIFT             (15U)
#define GPMI_ECCCTRL_CLR_RSVD2(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_CLR_RSVD2_SHIFT)) & GPMI_ECCCTRL_CLR_RSVD2_MASK)

#define GPMI_ECCCTRL_CLR_HANDLE_MASK             (0xFFFF0000U)
#define GPMI_ECCCTRL_CLR_HANDLE_SHIFT            (16U)
#define GPMI_ECCCTRL_CLR_HANDLE(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_CLR_HANDLE_SHIFT)) & GPMI_ECCCTRL_CLR_HANDLE_MASK)
/*! @} */

/*! @name ECCCTRL_TOG - GPMI Integrated ECC Control Register Description */
/*! @{ */

#define GPMI_ECCCTRL_TOG_BUFFER_MASK_MASK        (0x1FFU)
#define GPMI_ECCCTRL_TOG_BUFFER_MASK_SHIFT       (0U)
#define GPMI_ECCCTRL_TOG_BUFFER_MASK(x)          (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_TOG_BUFFER_MASK_SHIFT)) & GPMI_ECCCTRL_TOG_BUFFER_MASK_MASK)

#define GPMI_ECCCTRL_TOG_RANDOMIZER_TYPE_MASK    (0x600U)
#define GPMI_ECCCTRL_TOG_RANDOMIZER_TYPE_SHIFT   (9U)
/*! RANDOMIZER_TYPE
 *  0b00..Type 0
 *  0b01..Type 1
 */
#define GPMI_ECCCTRL_TOG_RANDOMIZER_TYPE(x)      (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_TOG_RANDOMIZER_TYPE_SHIFT)) & GPMI_ECCCTRL_TOG_RANDOMIZER_TYPE_MASK)

#define GPMI_ECCCTRL_TOG_RANDOMIZER_ENABLE_MASK  (0x800U)
#define GPMI_ECCCTRL_TOG_RANDOMIZER_ENABLE_SHIFT (11U)
/*! RANDOMIZER_ENABLE
 *  0b0..disable
 *  0b1..enable
 */
#define GPMI_ECCCTRL_TOG_RANDOMIZER_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_TOG_RANDOMIZER_ENABLE_SHIFT)) & GPMI_ECCCTRL_TOG_RANDOMIZER_ENABLE_MASK)

#define GPMI_ECCCTRL_TOG_ENABLE_ECC_MASK         (0x1000U)
#define GPMI_ECCCTRL_TOG_ENABLE_ECC_SHIFT        (12U)
#define GPMI_ECCCTRL_TOG_ENABLE_ECC(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_TOG_ENABLE_ECC_SHIFT)) & GPMI_ECCCTRL_TOG_ENABLE_ECC_MASK)

#define GPMI_ECCCTRL_TOG_ECC_CMD_MASK            (0x6000U)
#define GPMI_ECCCTRL_TOG_ECC_CMD_SHIFT           (13U)
#define GPMI_ECCCTRL_TOG_ECC_CMD(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_TOG_ECC_CMD_SHIFT)) & GPMI_ECCCTRL_TOG_ECC_CMD_MASK)

#define GPMI_ECCCTRL_TOG_RSVD2_MASK              (0x8000U)
#define GPMI_ECCCTRL_TOG_RSVD2_SHIFT             (15U)
#define GPMI_ECCCTRL_TOG_RSVD2(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_TOG_RSVD2_SHIFT)) & GPMI_ECCCTRL_TOG_RSVD2_MASK)

#define GPMI_ECCCTRL_TOG_HANDLE_MASK             (0xFFFF0000U)
#define GPMI_ECCCTRL_TOG_HANDLE_SHIFT            (16U)
#define GPMI_ECCCTRL_TOG_HANDLE(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCTRL_TOG_HANDLE_SHIFT)) & GPMI_ECCCTRL_TOG_HANDLE_MASK)
/*! @} */

/*! @name ECCCOUNT - GPMI Integrated ECC Transfer Count Register Description */
/*! @{ */

#define GPMI_ECCCOUNT_COUNT_MASK                 (0xFFFFU)
#define GPMI_ECCCOUNT_COUNT_SHIFT                (0U)
#define GPMI_ECCCOUNT_COUNT(x)                   (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCOUNT_COUNT_SHIFT)) & GPMI_ECCCOUNT_COUNT_MASK)

#define GPMI_ECCCOUNT_RANDOMIZER_PAGE_MASK       (0xFF0000U)
#define GPMI_ECCCOUNT_RANDOMIZER_PAGE_SHIFT      (16U)
#define GPMI_ECCCOUNT_RANDOMIZER_PAGE(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_ECCCOUNT_RANDOMIZER_PAGE_SHIFT)) & GPMI_ECCCOUNT_RANDOMIZER_PAGE_MASK)
/*! @} */

/*! @name PAYLOAD - GPMI Payload Address Register Description */
/*! @{ */

#define GPMI_PAYLOAD_RSVD0_MASK                  (0x3U)
#define GPMI_PAYLOAD_RSVD0_SHIFT                 (0U)
#define GPMI_PAYLOAD_RSVD0(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_PAYLOAD_RSVD0_SHIFT)) & GPMI_PAYLOAD_RSVD0_MASK)

#define GPMI_PAYLOAD_ADDRESS_MASK                (0xFFFFFFFCU)
#define GPMI_PAYLOAD_ADDRESS_SHIFT               (2U)
#define GPMI_PAYLOAD_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_PAYLOAD_ADDRESS_SHIFT)) & GPMI_PAYLOAD_ADDRESS_MASK)
/*! @} */

/*! @name AUXILIARY - GPMI Auxiliary Address Register Description */
/*! @{ */

#define GPMI_AUXILIARY_RSVD0_MASK                (0x3U)
#define GPMI_AUXILIARY_RSVD0_SHIFT               (0U)
#define GPMI_AUXILIARY_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_AUXILIARY_RSVD0_SHIFT)) & GPMI_AUXILIARY_RSVD0_MASK)

#define GPMI_AUXILIARY_ADDRESS_MASK              (0xFFFFFFFCU)
#define GPMI_AUXILIARY_ADDRESS_SHIFT             (2U)
#define GPMI_AUXILIARY_ADDRESS(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_AUXILIARY_ADDRESS_SHIFT)) & GPMI_AUXILIARY_ADDRESS_MASK)
/*! @} */

/*! @name CTRL1 - GPMI Control Register 1 Description */
/*! @{ */

#define GPMI_CTRL1_GPMI_MODE_MASK                (0x1U)
#define GPMI_CTRL1_GPMI_MODE_SHIFT               (0U)
/*! GPMI_MODE
 *  0b0..NAND mode.
 *  0b1..ATA mode.
 */
#define GPMI_CTRL1_GPMI_MODE(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_GPMI_MODE_SHIFT)) & GPMI_CTRL1_GPMI_MODE_MASK)

#define GPMI_CTRL1_CAMERA_MODE_MASK              (0x2U)
#define GPMI_CTRL1_CAMERA_MODE_SHIFT             (1U)
#define GPMI_CTRL1_CAMERA_MODE(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CAMERA_MODE_SHIFT)) & GPMI_CTRL1_CAMERA_MODE_MASK)

#define GPMI_CTRL1_ATA_IRQRDY_POLARITY_MASK      (0x4U)
#define GPMI_CTRL1_ATA_IRQRDY_POLARITY_SHIFT     (2U)
/*! ATA_IRQRDY_POLARITY
 *  0b0..External RDY_BUSY[1] and RDY_BUSY[0] pins are ready when low and busy when high.
 *  0b1..External RDY_BUSY[1] and RDY_BUSY[0] pins are ready when high and busy when low.
 */
#define GPMI_CTRL1_ATA_IRQRDY_POLARITY(x)        (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_ATA_IRQRDY_POLARITY_SHIFT)) & GPMI_CTRL1_ATA_IRQRDY_POLARITY_MASK)

#define GPMI_CTRL1_DEV_RESET_MASK                (0x8U)
#define GPMI_CTRL1_DEV_RESET_SHIFT               (3U)
/*! DEV_RESET
 *  0b0..NANDF_WP_B pin is held low (asserted).
 *  0b1..NANDF_WP_B pin is held high (de-asserted).
 */
#define GPMI_CTRL1_DEV_RESET(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_DEV_RESET_SHIFT)) & GPMI_CTRL1_DEV_RESET_MASK)

#define GPMI_CTRL1_ABORT_WAIT_FOR_READY_CHANNEL_MASK (0x70U)
#define GPMI_CTRL1_ABORT_WAIT_FOR_READY_CHANNEL_SHIFT (4U)
#define GPMI_CTRL1_ABORT_WAIT_FOR_READY_CHANNEL(x) (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_ABORT_WAIT_FOR_READY_CHANNEL_SHIFT)) & GPMI_CTRL1_ABORT_WAIT_FOR_READY_CHANNEL_MASK)

#define GPMI_CTRL1_ABORT_WAIT_REQUEST_MASK       (0x80U)
#define GPMI_CTRL1_ABORT_WAIT_REQUEST_SHIFT      (7U)
#define GPMI_CTRL1_ABORT_WAIT_REQUEST(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_ABORT_WAIT_REQUEST_SHIFT)) & GPMI_CTRL1_ABORT_WAIT_REQUEST_MASK)

#define GPMI_CTRL1_BURST_EN_MASK                 (0x100U)
#define GPMI_CTRL1_BURST_EN_SHIFT                (8U)
#define GPMI_CTRL1_BURST_EN(x)                   (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_BURST_EN_SHIFT)) & GPMI_CTRL1_BURST_EN_MASK)

#define GPMI_CTRL1_TIMEOUT_IRQ_MASK              (0x200U)
#define GPMI_CTRL1_TIMEOUT_IRQ_SHIFT             (9U)
#define GPMI_CTRL1_TIMEOUT_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TIMEOUT_IRQ_SHIFT)) & GPMI_CTRL1_TIMEOUT_IRQ_MASK)

#define GPMI_CTRL1_DEV_IRQ_MASK                  (0x400U)
#define GPMI_CTRL1_DEV_IRQ_SHIFT                 (10U)
#define GPMI_CTRL1_DEV_IRQ(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_DEV_IRQ_SHIFT)) & GPMI_CTRL1_DEV_IRQ_MASK)

#define GPMI_CTRL1_DMA2ECC_MODE_MASK             (0x800U)
#define GPMI_CTRL1_DMA2ECC_MODE_SHIFT            (11U)
#define GPMI_CTRL1_DMA2ECC_MODE(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_DMA2ECC_MODE_SHIFT)) & GPMI_CTRL1_DMA2ECC_MODE_MASK)

#define GPMI_CTRL1_RDN_DELAY_MASK                (0xF000U)
#define GPMI_CTRL1_RDN_DELAY_SHIFT               (12U)
#define GPMI_CTRL1_RDN_DELAY(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_RDN_DELAY_SHIFT)) & GPMI_CTRL1_RDN_DELAY_MASK)

#define GPMI_CTRL1_HALF_PERIOD_MASK              (0x10000U)
#define GPMI_CTRL1_HALF_PERIOD_SHIFT             (16U)
#define GPMI_CTRL1_HALF_PERIOD(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_HALF_PERIOD_SHIFT)) & GPMI_CTRL1_HALF_PERIOD_MASK)

#define GPMI_CTRL1_DLL_ENABLE_MASK               (0x20000U)
#define GPMI_CTRL1_DLL_ENABLE_SHIFT              (17U)
#define GPMI_CTRL1_DLL_ENABLE(x)                 (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_DLL_ENABLE_SHIFT)) & GPMI_CTRL1_DLL_ENABLE_MASK)

#define GPMI_CTRL1_BCH_MODE_MASK                 (0x40000U)
#define GPMI_CTRL1_BCH_MODE_SHIFT                (18U)
#define GPMI_CTRL1_BCH_MODE(x)                   (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_BCH_MODE_SHIFT)) & GPMI_CTRL1_BCH_MODE_MASK)

#define GPMI_CTRL1_GANGED_RDYBUSY_MASK           (0x80000U)
#define GPMI_CTRL1_GANGED_RDYBUSY_SHIFT          (19U)
#define GPMI_CTRL1_GANGED_RDYBUSY(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_GANGED_RDYBUSY_SHIFT)) & GPMI_CTRL1_GANGED_RDYBUSY_MASK)

#define GPMI_CTRL1_TIMEOUT_IRQ_EN_MASK           (0x100000U)
#define GPMI_CTRL1_TIMEOUT_IRQ_EN_SHIFT          (20U)
#define GPMI_CTRL1_TIMEOUT_IRQ_EN(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TIMEOUT_IRQ_EN_SHIFT)) & GPMI_CTRL1_TIMEOUT_IRQ_EN_MASK)

#define GPMI_CTRL1_TEST_TRIGGER_MASK             (0x200000U)
#define GPMI_CTRL1_TEST_TRIGGER_SHIFT            (21U)
/*! TEST_TRIGGER
 *  0b0..Disable
 *  0b1..Enable
 */
#define GPMI_CTRL1_TEST_TRIGGER(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TEST_TRIGGER_SHIFT)) & GPMI_CTRL1_TEST_TRIGGER_MASK)

#define GPMI_CTRL1_WRN_DLY_SEL_MASK              (0xC00000U)
#define GPMI_CTRL1_WRN_DLY_SEL_SHIFT             (22U)
#define GPMI_CTRL1_WRN_DLY_SEL(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_WRN_DLY_SEL_SHIFT)) & GPMI_CTRL1_WRN_DLY_SEL_MASK)

#define GPMI_CTRL1_DECOUPLE_CS_MASK              (0x1000000U)
#define GPMI_CTRL1_DECOUPLE_CS_SHIFT             (24U)
#define GPMI_CTRL1_DECOUPLE_CS(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_DECOUPLE_CS_SHIFT)) & GPMI_CTRL1_DECOUPLE_CS_MASK)

#define GPMI_CTRL1_SSYNCMODE_MASK                (0x2000000U)
#define GPMI_CTRL1_SSYNCMODE_SHIFT               (25U)
#define GPMI_CTRL1_SSYNCMODE(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SSYNCMODE_SHIFT)) & GPMI_CTRL1_SSYNCMODE_MASK)

#define GPMI_CTRL1_UPDATE_CS_MASK                (0x4000000U)
#define GPMI_CTRL1_UPDATE_CS_SHIFT               (26U)
#define GPMI_CTRL1_UPDATE_CS(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_UPDATE_CS_SHIFT)) & GPMI_CTRL1_UPDATE_CS_MASK)

#define GPMI_CTRL1_GPMI_CLK_DIV2_EN_MASK         (0x8000000U)
#define GPMI_CTRL1_GPMI_CLK_DIV2_EN_SHIFT        (27U)
/*! GPMI_CLK_DIV2_EN
 *  0b0..internal factor-2 clock divider is disabled
 *  0b1..internal factor-2 clock divider is enabled.
 */
#define GPMI_CTRL1_GPMI_CLK_DIV2_EN(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_GPMI_CLK_DIV2_EN_SHIFT)) & GPMI_CTRL1_GPMI_CLK_DIV2_EN_MASK)

#define GPMI_CTRL1_TOGGLE_MODE_MASK              (0x10000000U)
#define GPMI_CTRL1_TOGGLE_MODE_SHIFT             (28U)
#define GPMI_CTRL1_TOGGLE_MODE(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOGGLE_MODE_SHIFT)) & GPMI_CTRL1_TOGGLE_MODE_MASK)

#define GPMI_CTRL1_WRITE_CLK_STOP_MASK           (0x20000000U)
#define GPMI_CTRL1_WRITE_CLK_STOP_SHIFT          (29U)
#define GPMI_CTRL1_WRITE_CLK_STOP(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_WRITE_CLK_STOP_SHIFT)) & GPMI_CTRL1_WRITE_CLK_STOP_MASK)

#define GPMI_CTRL1_SSYNC_CLK_STOP_MASK           (0x40000000U)
#define GPMI_CTRL1_SSYNC_CLK_STOP_SHIFT          (30U)
#define GPMI_CTRL1_SSYNC_CLK_STOP(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SSYNC_CLK_STOP_SHIFT)) & GPMI_CTRL1_SSYNC_CLK_STOP_MASK)

#define GPMI_CTRL1_DEV_CLK_STOP_MASK             (0x80000000U)
#define GPMI_CTRL1_DEV_CLK_STOP_SHIFT            (31U)
#define GPMI_CTRL1_DEV_CLK_STOP(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_DEV_CLK_STOP_SHIFT)) & GPMI_CTRL1_DEV_CLK_STOP_MASK)
/*! @} */

/*! @name CTRL1_SET - GPMI Control Register 1 Description */
/*! @{ */

#define GPMI_CTRL1_SET_GPMI_MODE_MASK            (0x1U)
#define GPMI_CTRL1_SET_GPMI_MODE_SHIFT           (0U)
/*! GPMI_MODE
 *  0b0..NAND mode.
 *  0b1..ATA mode.
 */
#define GPMI_CTRL1_SET_GPMI_MODE(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_GPMI_MODE_SHIFT)) & GPMI_CTRL1_SET_GPMI_MODE_MASK)

#define GPMI_CTRL1_SET_CAMERA_MODE_MASK          (0x2U)
#define GPMI_CTRL1_SET_CAMERA_MODE_SHIFT         (1U)
#define GPMI_CTRL1_SET_CAMERA_MODE(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_CAMERA_MODE_SHIFT)) & GPMI_CTRL1_SET_CAMERA_MODE_MASK)

#define GPMI_CTRL1_SET_ATA_IRQRDY_POLARITY_MASK  (0x4U)
#define GPMI_CTRL1_SET_ATA_IRQRDY_POLARITY_SHIFT (2U)
/*! ATA_IRQRDY_POLARITY
 *  0b0..External RDY_BUSY[1] and RDY_BUSY[0] pins are ready when low and busy when high.
 *  0b1..External RDY_BUSY[1] and RDY_BUSY[0] pins are ready when high and busy when low.
 */
#define GPMI_CTRL1_SET_ATA_IRQRDY_POLARITY(x)    (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_ATA_IRQRDY_POLARITY_SHIFT)) & GPMI_CTRL1_SET_ATA_IRQRDY_POLARITY_MASK)

#define GPMI_CTRL1_SET_DEV_RESET_MASK            (0x8U)
#define GPMI_CTRL1_SET_DEV_RESET_SHIFT           (3U)
/*! DEV_RESET
 *  0b0..NANDF_WP_B pin is held low (asserted).
 *  0b1..NANDF_WP_B pin is held high (de-asserted).
 */
#define GPMI_CTRL1_SET_DEV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_DEV_RESET_SHIFT)) & GPMI_CTRL1_SET_DEV_RESET_MASK)

#define GPMI_CTRL1_SET_ABORT_WAIT_FOR_READY_CHANNEL_MASK (0x70U)
#define GPMI_CTRL1_SET_ABORT_WAIT_FOR_READY_CHANNEL_SHIFT (4U)
#define GPMI_CTRL1_SET_ABORT_WAIT_FOR_READY_CHANNEL(x) (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_ABORT_WAIT_FOR_READY_CHANNEL_SHIFT)) & GPMI_CTRL1_SET_ABORT_WAIT_FOR_READY_CHANNEL_MASK)

#define GPMI_CTRL1_SET_ABORT_WAIT_REQUEST_MASK   (0x80U)
#define GPMI_CTRL1_SET_ABORT_WAIT_REQUEST_SHIFT  (7U)
#define GPMI_CTRL1_SET_ABORT_WAIT_REQUEST(x)     (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_ABORT_WAIT_REQUEST_SHIFT)) & GPMI_CTRL1_SET_ABORT_WAIT_REQUEST_MASK)

#define GPMI_CTRL1_SET_BURST_EN_MASK             (0x100U)
#define GPMI_CTRL1_SET_BURST_EN_SHIFT            (8U)
#define GPMI_CTRL1_SET_BURST_EN(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_BURST_EN_SHIFT)) & GPMI_CTRL1_SET_BURST_EN_MASK)

#define GPMI_CTRL1_SET_TIMEOUT_IRQ_MASK          (0x200U)
#define GPMI_CTRL1_SET_TIMEOUT_IRQ_SHIFT         (9U)
#define GPMI_CTRL1_SET_TIMEOUT_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_TIMEOUT_IRQ_SHIFT)) & GPMI_CTRL1_SET_TIMEOUT_IRQ_MASK)

#define GPMI_CTRL1_SET_DEV_IRQ_MASK              (0x400U)
#define GPMI_CTRL1_SET_DEV_IRQ_SHIFT             (10U)
#define GPMI_CTRL1_SET_DEV_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_DEV_IRQ_SHIFT)) & GPMI_CTRL1_SET_DEV_IRQ_MASK)

#define GPMI_CTRL1_SET_DMA2ECC_MODE_MASK         (0x800U)
#define GPMI_CTRL1_SET_DMA2ECC_MODE_SHIFT        (11U)
#define GPMI_CTRL1_SET_DMA2ECC_MODE(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_DMA2ECC_MODE_SHIFT)) & GPMI_CTRL1_SET_DMA2ECC_MODE_MASK)

#define GPMI_CTRL1_SET_RDN_DELAY_MASK            (0xF000U)
#define GPMI_CTRL1_SET_RDN_DELAY_SHIFT           (12U)
#define GPMI_CTRL1_SET_RDN_DELAY(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_RDN_DELAY_SHIFT)) & GPMI_CTRL1_SET_RDN_DELAY_MASK)

#define GPMI_CTRL1_SET_HALF_PERIOD_MASK          (0x10000U)
#define GPMI_CTRL1_SET_HALF_PERIOD_SHIFT         (16U)
#define GPMI_CTRL1_SET_HALF_PERIOD(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_HALF_PERIOD_SHIFT)) & GPMI_CTRL1_SET_HALF_PERIOD_MASK)

#define GPMI_CTRL1_SET_DLL_ENABLE_MASK           (0x20000U)
#define GPMI_CTRL1_SET_DLL_ENABLE_SHIFT          (17U)
#define GPMI_CTRL1_SET_DLL_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_DLL_ENABLE_SHIFT)) & GPMI_CTRL1_SET_DLL_ENABLE_MASK)

#define GPMI_CTRL1_SET_BCH_MODE_MASK             (0x40000U)
#define GPMI_CTRL1_SET_BCH_MODE_SHIFT            (18U)
#define GPMI_CTRL1_SET_BCH_MODE(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_BCH_MODE_SHIFT)) & GPMI_CTRL1_SET_BCH_MODE_MASK)

#define GPMI_CTRL1_SET_GANGED_RDYBUSY_MASK       (0x80000U)
#define GPMI_CTRL1_SET_GANGED_RDYBUSY_SHIFT      (19U)
#define GPMI_CTRL1_SET_GANGED_RDYBUSY(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_GANGED_RDYBUSY_SHIFT)) & GPMI_CTRL1_SET_GANGED_RDYBUSY_MASK)

#define GPMI_CTRL1_SET_TIMEOUT_IRQ_EN_MASK       (0x100000U)
#define GPMI_CTRL1_SET_TIMEOUT_IRQ_EN_SHIFT      (20U)
#define GPMI_CTRL1_SET_TIMEOUT_IRQ_EN(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_TIMEOUT_IRQ_EN_SHIFT)) & GPMI_CTRL1_SET_TIMEOUT_IRQ_EN_MASK)

#define GPMI_CTRL1_SET_TEST_TRIGGER_MASK         (0x200000U)
#define GPMI_CTRL1_SET_TEST_TRIGGER_SHIFT        (21U)
/*! TEST_TRIGGER
 *  0b0..Disable
 *  0b1..Enable
 */
#define GPMI_CTRL1_SET_TEST_TRIGGER(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_TEST_TRIGGER_SHIFT)) & GPMI_CTRL1_SET_TEST_TRIGGER_MASK)

#define GPMI_CTRL1_SET_WRN_DLY_SEL_MASK          (0xC00000U)
#define GPMI_CTRL1_SET_WRN_DLY_SEL_SHIFT         (22U)
#define GPMI_CTRL1_SET_WRN_DLY_SEL(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_WRN_DLY_SEL_SHIFT)) & GPMI_CTRL1_SET_WRN_DLY_SEL_MASK)

#define GPMI_CTRL1_SET_DECOUPLE_CS_MASK          (0x1000000U)
#define GPMI_CTRL1_SET_DECOUPLE_CS_SHIFT         (24U)
#define GPMI_CTRL1_SET_DECOUPLE_CS(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_DECOUPLE_CS_SHIFT)) & GPMI_CTRL1_SET_DECOUPLE_CS_MASK)

#define GPMI_CTRL1_SET_SSYNCMODE_MASK            (0x2000000U)
#define GPMI_CTRL1_SET_SSYNCMODE_SHIFT           (25U)
#define GPMI_CTRL1_SET_SSYNCMODE(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_SSYNCMODE_SHIFT)) & GPMI_CTRL1_SET_SSYNCMODE_MASK)

#define GPMI_CTRL1_SET_UPDATE_CS_MASK            (0x4000000U)
#define GPMI_CTRL1_SET_UPDATE_CS_SHIFT           (26U)
#define GPMI_CTRL1_SET_UPDATE_CS(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_UPDATE_CS_SHIFT)) & GPMI_CTRL1_SET_UPDATE_CS_MASK)

#define GPMI_CTRL1_SET_GPMI_CLK_DIV2_EN_MASK     (0x8000000U)
#define GPMI_CTRL1_SET_GPMI_CLK_DIV2_EN_SHIFT    (27U)
/*! GPMI_CLK_DIV2_EN
 *  0b0..internal factor-2 clock divider is disabled
 *  0b1..internal factor-2 clock divider is enabled.
 */
#define GPMI_CTRL1_SET_GPMI_CLK_DIV2_EN(x)       (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_GPMI_CLK_DIV2_EN_SHIFT)) & GPMI_CTRL1_SET_GPMI_CLK_DIV2_EN_MASK)

#define GPMI_CTRL1_SET_TOGGLE_MODE_MASK          (0x10000000U)
#define GPMI_CTRL1_SET_TOGGLE_MODE_SHIFT         (28U)
#define GPMI_CTRL1_SET_TOGGLE_MODE(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_TOGGLE_MODE_SHIFT)) & GPMI_CTRL1_SET_TOGGLE_MODE_MASK)

#define GPMI_CTRL1_SET_WRITE_CLK_STOP_MASK       (0x20000000U)
#define GPMI_CTRL1_SET_WRITE_CLK_STOP_SHIFT      (29U)
#define GPMI_CTRL1_SET_WRITE_CLK_STOP(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_WRITE_CLK_STOP_SHIFT)) & GPMI_CTRL1_SET_WRITE_CLK_STOP_MASK)

#define GPMI_CTRL1_SET_SSYNC_CLK_STOP_MASK       (0x40000000U)
#define GPMI_CTRL1_SET_SSYNC_CLK_STOP_SHIFT      (30U)
#define GPMI_CTRL1_SET_SSYNC_CLK_STOP(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_SSYNC_CLK_STOP_SHIFT)) & GPMI_CTRL1_SET_SSYNC_CLK_STOP_MASK)

#define GPMI_CTRL1_SET_DEV_CLK_STOP_MASK         (0x80000000U)
#define GPMI_CTRL1_SET_DEV_CLK_STOP_SHIFT        (31U)
#define GPMI_CTRL1_SET_DEV_CLK_STOP(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_SET_DEV_CLK_STOP_SHIFT)) & GPMI_CTRL1_SET_DEV_CLK_STOP_MASK)
/*! @} */

/*! @name CTRL1_CLR - GPMI Control Register 1 Description */
/*! @{ */

#define GPMI_CTRL1_CLR_GPMI_MODE_MASK            (0x1U)
#define GPMI_CTRL1_CLR_GPMI_MODE_SHIFT           (0U)
/*! GPMI_MODE
 *  0b0..NAND mode.
 *  0b1..ATA mode.
 */
#define GPMI_CTRL1_CLR_GPMI_MODE(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_GPMI_MODE_SHIFT)) & GPMI_CTRL1_CLR_GPMI_MODE_MASK)

#define GPMI_CTRL1_CLR_CAMERA_MODE_MASK          (0x2U)
#define GPMI_CTRL1_CLR_CAMERA_MODE_SHIFT         (1U)
#define GPMI_CTRL1_CLR_CAMERA_MODE(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_CAMERA_MODE_SHIFT)) & GPMI_CTRL1_CLR_CAMERA_MODE_MASK)

#define GPMI_CTRL1_CLR_ATA_IRQRDY_POLARITY_MASK  (0x4U)
#define GPMI_CTRL1_CLR_ATA_IRQRDY_POLARITY_SHIFT (2U)
/*! ATA_IRQRDY_POLARITY
 *  0b0..External RDY_BUSY[1] and RDY_BUSY[0] pins are ready when low and busy when high.
 *  0b1..External RDY_BUSY[1] and RDY_BUSY[0] pins are ready when high and busy when low.
 */
#define GPMI_CTRL1_CLR_ATA_IRQRDY_POLARITY(x)    (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_ATA_IRQRDY_POLARITY_SHIFT)) & GPMI_CTRL1_CLR_ATA_IRQRDY_POLARITY_MASK)

#define GPMI_CTRL1_CLR_DEV_RESET_MASK            (0x8U)
#define GPMI_CTRL1_CLR_DEV_RESET_SHIFT           (3U)
/*! DEV_RESET
 *  0b0..NANDF_WP_B pin is held low (asserted).
 *  0b1..NANDF_WP_B pin is held high (de-asserted).
 */
#define GPMI_CTRL1_CLR_DEV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_DEV_RESET_SHIFT)) & GPMI_CTRL1_CLR_DEV_RESET_MASK)

#define GPMI_CTRL1_CLR_ABORT_WAIT_FOR_READY_CHANNEL_MASK (0x70U)
#define GPMI_CTRL1_CLR_ABORT_WAIT_FOR_READY_CHANNEL_SHIFT (4U)
#define GPMI_CTRL1_CLR_ABORT_WAIT_FOR_READY_CHANNEL(x) (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_ABORT_WAIT_FOR_READY_CHANNEL_SHIFT)) & GPMI_CTRL1_CLR_ABORT_WAIT_FOR_READY_CHANNEL_MASK)

#define GPMI_CTRL1_CLR_ABORT_WAIT_REQUEST_MASK   (0x80U)
#define GPMI_CTRL1_CLR_ABORT_WAIT_REQUEST_SHIFT  (7U)
#define GPMI_CTRL1_CLR_ABORT_WAIT_REQUEST(x)     (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_ABORT_WAIT_REQUEST_SHIFT)) & GPMI_CTRL1_CLR_ABORT_WAIT_REQUEST_MASK)

#define GPMI_CTRL1_CLR_BURST_EN_MASK             (0x100U)
#define GPMI_CTRL1_CLR_BURST_EN_SHIFT            (8U)
#define GPMI_CTRL1_CLR_BURST_EN(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_BURST_EN_SHIFT)) & GPMI_CTRL1_CLR_BURST_EN_MASK)

#define GPMI_CTRL1_CLR_TIMEOUT_IRQ_MASK          (0x200U)
#define GPMI_CTRL1_CLR_TIMEOUT_IRQ_SHIFT         (9U)
#define GPMI_CTRL1_CLR_TIMEOUT_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_TIMEOUT_IRQ_SHIFT)) & GPMI_CTRL1_CLR_TIMEOUT_IRQ_MASK)

#define GPMI_CTRL1_CLR_DEV_IRQ_MASK              (0x400U)
#define GPMI_CTRL1_CLR_DEV_IRQ_SHIFT             (10U)
#define GPMI_CTRL1_CLR_DEV_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_DEV_IRQ_SHIFT)) & GPMI_CTRL1_CLR_DEV_IRQ_MASK)

#define GPMI_CTRL1_CLR_DMA2ECC_MODE_MASK         (0x800U)
#define GPMI_CTRL1_CLR_DMA2ECC_MODE_SHIFT        (11U)
#define GPMI_CTRL1_CLR_DMA2ECC_MODE(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_DMA2ECC_MODE_SHIFT)) & GPMI_CTRL1_CLR_DMA2ECC_MODE_MASK)

#define GPMI_CTRL1_CLR_RDN_DELAY_MASK            (0xF000U)
#define GPMI_CTRL1_CLR_RDN_DELAY_SHIFT           (12U)
#define GPMI_CTRL1_CLR_RDN_DELAY(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_RDN_DELAY_SHIFT)) & GPMI_CTRL1_CLR_RDN_DELAY_MASK)

#define GPMI_CTRL1_CLR_HALF_PERIOD_MASK          (0x10000U)
#define GPMI_CTRL1_CLR_HALF_PERIOD_SHIFT         (16U)
#define GPMI_CTRL1_CLR_HALF_PERIOD(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_HALF_PERIOD_SHIFT)) & GPMI_CTRL1_CLR_HALF_PERIOD_MASK)

#define GPMI_CTRL1_CLR_DLL_ENABLE_MASK           (0x20000U)
#define GPMI_CTRL1_CLR_DLL_ENABLE_SHIFT          (17U)
#define GPMI_CTRL1_CLR_DLL_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_DLL_ENABLE_SHIFT)) & GPMI_CTRL1_CLR_DLL_ENABLE_MASK)

#define GPMI_CTRL1_CLR_BCH_MODE_MASK             (0x40000U)
#define GPMI_CTRL1_CLR_BCH_MODE_SHIFT            (18U)
#define GPMI_CTRL1_CLR_BCH_MODE(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_BCH_MODE_SHIFT)) & GPMI_CTRL1_CLR_BCH_MODE_MASK)

#define GPMI_CTRL1_CLR_GANGED_RDYBUSY_MASK       (0x80000U)
#define GPMI_CTRL1_CLR_GANGED_RDYBUSY_SHIFT      (19U)
#define GPMI_CTRL1_CLR_GANGED_RDYBUSY(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_GANGED_RDYBUSY_SHIFT)) & GPMI_CTRL1_CLR_GANGED_RDYBUSY_MASK)

#define GPMI_CTRL1_CLR_TIMEOUT_IRQ_EN_MASK       (0x100000U)
#define GPMI_CTRL1_CLR_TIMEOUT_IRQ_EN_SHIFT      (20U)
#define GPMI_CTRL1_CLR_TIMEOUT_IRQ_EN(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_TIMEOUT_IRQ_EN_SHIFT)) & GPMI_CTRL1_CLR_TIMEOUT_IRQ_EN_MASK)

#define GPMI_CTRL1_CLR_TEST_TRIGGER_MASK         (0x200000U)
#define GPMI_CTRL1_CLR_TEST_TRIGGER_SHIFT        (21U)
/*! TEST_TRIGGER
 *  0b0..Disable
 *  0b1..Enable
 */
#define GPMI_CTRL1_CLR_TEST_TRIGGER(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_TEST_TRIGGER_SHIFT)) & GPMI_CTRL1_CLR_TEST_TRIGGER_MASK)

#define GPMI_CTRL1_CLR_WRN_DLY_SEL_MASK          (0xC00000U)
#define GPMI_CTRL1_CLR_WRN_DLY_SEL_SHIFT         (22U)
#define GPMI_CTRL1_CLR_WRN_DLY_SEL(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_WRN_DLY_SEL_SHIFT)) & GPMI_CTRL1_CLR_WRN_DLY_SEL_MASK)

#define GPMI_CTRL1_CLR_DECOUPLE_CS_MASK          (0x1000000U)
#define GPMI_CTRL1_CLR_DECOUPLE_CS_SHIFT         (24U)
#define GPMI_CTRL1_CLR_DECOUPLE_CS(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_DECOUPLE_CS_SHIFT)) & GPMI_CTRL1_CLR_DECOUPLE_CS_MASK)

#define GPMI_CTRL1_CLR_SSYNCMODE_MASK            (0x2000000U)
#define GPMI_CTRL1_CLR_SSYNCMODE_SHIFT           (25U)
#define GPMI_CTRL1_CLR_SSYNCMODE(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_SSYNCMODE_SHIFT)) & GPMI_CTRL1_CLR_SSYNCMODE_MASK)

#define GPMI_CTRL1_CLR_UPDATE_CS_MASK            (0x4000000U)
#define GPMI_CTRL1_CLR_UPDATE_CS_SHIFT           (26U)
#define GPMI_CTRL1_CLR_UPDATE_CS(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_UPDATE_CS_SHIFT)) & GPMI_CTRL1_CLR_UPDATE_CS_MASK)

#define GPMI_CTRL1_CLR_GPMI_CLK_DIV2_EN_MASK     (0x8000000U)
#define GPMI_CTRL1_CLR_GPMI_CLK_DIV2_EN_SHIFT    (27U)
/*! GPMI_CLK_DIV2_EN
 *  0b0..internal factor-2 clock divider is disabled
 *  0b1..internal factor-2 clock divider is enabled.
 */
#define GPMI_CTRL1_CLR_GPMI_CLK_DIV2_EN(x)       (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_GPMI_CLK_DIV2_EN_SHIFT)) & GPMI_CTRL1_CLR_GPMI_CLK_DIV2_EN_MASK)

#define GPMI_CTRL1_CLR_TOGGLE_MODE_MASK          (0x10000000U)
#define GPMI_CTRL1_CLR_TOGGLE_MODE_SHIFT         (28U)
#define GPMI_CTRL1_CLR_TOGGLE_MODE(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_TOGGLE_MODE_SHIFT)) & GPMI_CTRL1_CLR_TOGGLE_MODE_MASK)

#define GPMI_CTRL1_CLR_WRITE_CLK_STOP_MASK       (0x20000000U)
#define GPMI_CTRL1_CLR_WRITE_CLK_STOP_SHIFT      (29U)
#define GPMI_CTRL1_CLR_WRITE_CLK_STOP(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_WRITE_CLK_STOP_SHIFT)) & GPMI_CTRL1_CLR_WRITE_CLK_STOP_MASK)

#define GPMI_CTRL1_CLR_SSYNC_CLK_STOP_MASK       (0x40000000U)
#define GPMI_CTRL1_CLR_SSYNC_CLK_STOP_SHIFT      (30U)
#define GPMI_CTRL1_CLR_SSYNC_CLK_STOP(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_SSYNC_CLK_STOP_SHIFT)) & GPMI_CTRL1_CLR_SSYNC_CLK_STOP_MASK)

#define GPMI_CTRL1_CLR_DEV_CLK_STOP_MASK         (0x80000000U)
#define GPMI_CTRL1_CLR_DEV_CLK_STOP_SHIFT        (31U)
#define GPMI_CTRL1_CLR_DEV_CLK_STOP(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_CLR_DEV_CLK_STOP_SHIFT)) & GPMI_CTRL1_CLR_DEV_CLK_STOP_MASK)
/*! @} */

/*! @name CTRL1_TOG - GPMI Control Register 1 Description */
/*! @{ */

#define GPMI_CTRL1_TOG_GPMI_MODE_MASK            (0x1U)
#define GPMI_CTRL1_TOG_GPMI_MODE_SHIFT           (0U)
/*! GPMI_MODE
 *  0b0..NAND mode.
 *  0b1..ATA mode.
 */
#define GPMI_CTRL1_TOG_GPMI_MODE(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_GPMI_MODE_SHIFT)) & GPMI_CTRL1_TOG_GPMI_MODE_MASK)

#define GPMI_CTRL1_TOG_CAMERA_MODE_MASK          (0x2U)
#define GPMI_CTRL1_TOG_CAMERA_MODE_SHIFT         (1U)
#define GPMI_CTRL1_TOG_CAMERA_MODE(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_CAMERA_MODE_SHIFT)) & GPMI_CTRL1_TOG_CAMERA_MODE_MASK)

#define GPMI_CTRL1_TOG_ATA_IRQRDY_POLARITY_MASK  (0x4U)
#define GPMI_CTRL1_TOG_ATA_IRQRDY_POLARITY_SHIFT (2U)
/*! ATA_IRQRDY_POLARITY
 *  0b0..External RDY_BUSY[1] and RDY_BUSY[0] pins are ready when low and busy when high.
 *  0b1..External RDY_BUSY[1] and RDY_BUSY[0] pins are ready when high and busy when low.
 */
#define GPMI_CTRL1_TOG_ATA_IRQRDY_POLARITY(x)    (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_ATA_IRQRDY_POLARITY_SHIFT)) & GPMI_CTRL1_TOG_ATA_IRQRDY_POLARITY_MASK)

#define GPMI_CTRL1_TOG_DEV_RESET_MASK            (0x8U)
#define GPMI_CTRL1_TOG_DEV_RESET_SHIFT           (3U)
/*! DEV_RESET
 *  0b0..NANDF_WP_B pin is held low (asserted).
 *  0b1..NANDF_WP_B pin is held high (de-asserted).
 */
#define GPMI_CTRL1_TOG_DEV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_DEV_RESET_SHIFT)) & GPMI_CTRL1_TOG_DEV_RESET_MASK)

#define GPMI_CTRL1_TOG_ABORT_WAIT_FOR_READY_CHANNEL_MASK (0x70U)
#define GPMI_CTRL1_TOG_ABORT_WAIT_FOR_READY_CHANNEL_SHIFT (4U)
#define GPMI_CTRL1_TOG_ABORT_WAIT_FOR_READY_CHANNEL(x) (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_ABORT_WAIT_FOR_READY_CHANNEL_SHIFT)) & GPMI_CTRL1_TOG_ABORT_WAIT_FOR_READY_CHANNEL_MASK)

#define GPMI_CTRL1_TOG_ABORT_WAIT_REQUEST_MASK   (0x80U)
#define GPMI_CTRL1_TOG_ABORT_WAIT_REQUEST_SHIFT  (7U)
#define GPMI_CTRL1_TOG_ABORT_WAIT_REQUEST(x)     (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_ABORT_WAIT_REQUEST_SHIFT)) & GPMI_CTRL1_TOG_ABORT_WAIT_REQUEST_MASK)

#define GPMI_CTRL1_TOG_BURST_EN_MASK             (0x100U)
#define GPMI_CTRL1_TOG_BURST_EN_SHIFT            (8U)
#define GPMI_CTRL1_TOG_BURST_EN(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_BURST_EN_SHIFT)) & GPMI_CTRL1_TOG_BURST_EN_MASK)

#define GPMI_CTRL1_TOG_TIMEOUT_IRQ_MASK          (0x200U)
#define GPMI_CTRL1_TOG_TIMEOUT_IRQ_SHIFT         (9U)
#define GPMI_CTRL1_TOG_TIMEOUT_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_TIMEOUT_IRQ_SHIFT)) & GPMI_CTRL1_TOG_TIMEOUT_IRQ_MASK)

#define GPMI_CTRL1_TOG_DEV_IRQ_MASK              (0x400U)
#define GPMI_CTRL1_TOG_DEV_IRQ_SHIFT             (10U)
#define GPMI_CTRL1_TOG_DEV_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_DEV_IRQ_SHIFT)) & GPMI_CTRL1_TOG_DEV_IRQ_MASK)

#define GPMI_CTRL1_TOG_DMA2ECC_MODE_MASK         (0x800U)
#define GPMI_CTRL1_TOG_DMA2ECC_MODE_SHIFT        (11U)
#define GPMI_CTRL1_TOG_DMA2ECC_MODE(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_DMA2ECC_MODE_SHIFT)) & GPMI_CTRL1_TOG_DMA2ECC_MODE_MASK)

#define GPMI_CTRL1_TOG_RDN_DELAY_MASK            (0xF000U)
#define GPMI_CTRL1_TOG_RDN_DELAY_SHIFT           (12U)
#define GPMI_CTRL1_TOG_RDN_DELAY(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_RDN_DELAY_SHIFT)) & GPMI_CTRL1_TOG_RDN_DELAY_MASK)

#define GPMI_CTRL1_TOG_HALF_PERIOD_MASK          (0x10000U)
#define GPMI_CTRL1_TOG_HALF_PERIOD_SHIFT         (16U)
#define GPMI_CTRL1_TOG_HALF_PERIOD(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_HALF_PERIOD_SHIFT)) & GPMI_CTRL1_TOG_HALF_PERIOD_MASK)

#define GPMI_CTRL1_TOG_DLL_ENABLE_MASK           (0x20000U)
#define GPMI_CTRL1_TOG_DLL_ENABLE_SHIFT          (17U)
#define GPMI_CTRL1_TOG_DLL_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_DLL_ENABLE_SHIFT)) & GPMI_CTRL1_TOG_DLL_ENABLE_MASK)

#define GPMI_CTRL1_TOG_BCH_MODE_MASK             (0x40000U)
#define GPMI_CTRL1_TOG_BCH_MODE_SHIFT            (18U)
#define GPMI_CTRL1_TOG_BCH_MODE(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_BCH_MODE_SHIFT)) & GPMI_CTRL1_TOG_BCH_MODE_MASK)

#define GPMI_CTRL1_TOG_GANGED_RDYBUSY_MASK       (0x80000U)
#define GPMI_CTRL1_TOG_GANGED_RDYBUSY_SHIFT      (19U)
#define GPMI_CTRL1_TOG_GANGED_RDYBUSY(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_GANGED_RDYBUSY_SHIFT)) & GPMI_CTRL1_TOG_GANGED_RDYBUSY_MASK)

#define GPMI_CTRL1_TOG_TIMEOUT_IRQ_EN_MASK       (0x100000U)
#define GPMI_CTRL1_TOG_TIMEOUT_IRQ_EN_SHIFT      (20U)
#define GPMI_CTRL1_TOG_TIMEOUT_IRQ_EN(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_TIMEOUT_IRQ_EN_SHIFT)) & GPMI_CTRL1_TOG_TIMEOUT_IRQ_EN_MASK)

#define GPMI_CTRL1_TOG_TEST_TRIGGER_MASK         (0x200000U)
#define GPMI_CTRL1_TOG_TEST_TRIGGER_SHIFT        (21U)
/*! TEST_TRIGGER
 *  0b0..Disable
 *  0b1..Enable
 */
#define GPMI_CTRL1_TOG_TEST_TRIGGER(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_TEST_TRIGGER_SHIFT)) & GPMI_CTRL1_TOG_TEST_TRIGGER_MASK)

#define GPMI_CTRL1_TOG_WRN_DLY_SEL_MASK          (0xC00000U)
#define GPMI_CTRL1_TOG_WRN_DLY_SEL_SHIFT         (22U)
#define GPMI_CTRL1_TOG_WRN_DLY_SEL(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_WRN_DLY_SEL_SHIFT)) & GPMI_CTRL1_TOG_WRN_DLY_SEL_MASK)

#define GPMI_CTRL1_TOG_DECOUPLE_CS_MASK          (0x1000000U)
#define GPMI_CTRL1_TOG_DECOUPLE_CS_SHIFT         (24U)
#define GPMI_CTRL1_TOG_DECOUPLE_CS(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_DECOUPLE_CS_SHIFT)) & GPMI_CTRL1_TOG_DECOUPLE_CS_MASK)

#define GPMI_CTRL1_TOG_SSYNCMODE_MASK            (0x2000000U)
#define GPMI_CTRL1_TOG_SSYNCMODE_SHIFT           (25U)
#define GPMI_CTRL1_TOG_SSYNCMODE(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_SSYNCMODE_SHIFT)) & GPMI_CTRL1_TOG_SSYNCMODE_MASK)

#define GPMI_CTRL1_TOG_UPDATE_CS_MASK            (0x4000000U)
#define GPMI_CTRL1_TOG_UPDATE_CS_SHIFT           (26U)
#define GPMI_CTRL1_TOG_UPDATE_CS(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_UPDATE_CS_SHIFT)) & GPMI_CTRL1_TOG_UPDATE_CS_MASK)

#define GPMI_CTRL1_TOG_GPMI_CLK_DIV2_EN_MASK     (0x8000000U)
#define GPMI_CTRL1_TOG_GPMI_CLK_DIV2_EN_SHIFT    (27U)
/*! GPMI_CLK_DIV2_EN
 *  0b0..internal factor-2 clock divider is disabled
 *  0b1..internal factor-2 clock divider is enabled.
 */
#define GPMI_CTRL1_TOG_GPMI_CLK_DIV2_EN(x)       (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_GPMI_CLK_DIV2_EN_SHIFT)) & GPMI_CTRL1_TOG_GPMI_CLK_DIV2_EN_MASK)

#define GPMI_CTRL1_TOG_TOGGLE_MODE_MASK          (0x10000000U)
#define GPMI_CTRL1_TOG_TOGGLE_MODE_SHIFT         (28U)
#define GPMI_CTRL1_TOG_TOGGLE_MODE(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_TOGGLE_MODE_SHIFT)) & GPMI_CTRL1_TOG_TOGGLE_MODE_MASK)

#define GPMI_CTRL1_TOG_WRITE_CLK_STOP_MASK       (0x20000000U)
#define GPMI_CTRL1_TOG_WRITE_CLK_STOP_SHIFT      (29U)
#define GPMI_CTRL1_TOG_WRITE_CLK_STOP(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_WRITE_CLK_STOP_SHIFT)) & GPMI_CTRL1_TOG_WRITE_CLK_STOP_MASK)

#define GPMI_CTRL1_TOG_SSYNC_CLK_STOP_MASK       (0x40000000U)
#define GPMI_CTRL1_TOG_SSYNC_CLK_STOP_SHIFT      (30U)
#define GPMI_CTRL1_TOG_SSYNC_CLK_STOP(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_SSYNC_CLK_STOP_SHIFT)) & GPMI_CTRL1_TOG_SSYNC_CLK_STOP_MASK)

#define GPMI_CTRL1_TOG_DEV_CLK_STOP_MASK         (0x80000000U)
#define GPMI_CTRL1_TOG_DEV_CLK_STOP_SHIFT        (31U)
#define GPMI_CTRL1_TOG_DEV_CLK_STOP(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_CTRL1_TOG_DEV_CLK_STOP_SHIFT)) & GPMI_CTRL1_TOG_DEV_CLK_STOP_MASK)
/*! @} */

/*! @name TIMING0 - GPMI Timing Register 0 Description */
/*! @{ */

#define GPMI_TIMING0_DATA_SETUP_MASK             (0xFFU)
#define GPMI_TIMING0_DATA_SETUP_SHIFT            (0U)
#define GPMI_TIMING0_DATA_SETUP(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING0_DATA_SETUP_SHIFT)) & GPMI_TIMING0_DATA_SETUP_MASK)

#define GPMI_TIMING0_DATA_HOLD_MASK              (0xFF00U)
#define GPMI_TIMING0_DATA_HOLD_SHIFT             (8U)
#define GPMI_TIMING0_DATA_HOLD(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING0_DATA_HOLD_SHIFT)) & GPMI_TIMING0_DATA_HOLD_MASK)

#define GPMI_TIMING0_ADDRESS_SETUP_MASK          (0xFF0000U)
#define GPMI_TIMING0_ADDRESS_SETUP_SHIFT         (16U)
#define GPMI_TIMING0_ADDRESS_SETUP(x)            (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING0_ADDRESS_SETUP_SHIFT)) & GPMI_TIMING0_ADDRESS_SETUP_MASK)

#define GPMI_TIMING0_RSVD1_MASK                  (0xFF000000U)
#define GPMI_TIMING0_RSVD1_SHIFT                 (24U)
#define GPMI_TIMING0_RSVD1(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING0_RSVD1_SHIFT)) & GPMI_TIMING0_RSVD1_MASK)
/*! @} */

/*! @name TIMING1 - GPMI Timing Register 1 Description */
/*! @{ */

#define GPMI_TIMING1_RSVD1_MASK                  (0xFFFFU)
#define GPMI_TIMING1_RSVD1_SHIFT                 (0U)
#define GPMI_TIMING1_RSVD1(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING1_RSVD1_SHIFT)) & GPMI_TIMING1_RSVD1_MASK)

#define GPMI_TIMING1_DEVICE_BUSY_TIMEOUT_MASK    (0xFFFF0000U)
#define GPMI_TIMING1_DEVICE_BUSY_TIMEOUT_SHIFT   (16U)
#define GPMI_TIMING1_DEVICE_BUSY_TIMEOUT(x)      (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING1_DEVICE_BUSY_TIMEOUT_SHIFT)) & GPMI_TIMING1_DEVICE_BUSY_TIMEOUT_MASK)
/*! @} */

/*! @name TIMING2 - GPMI Timing Register 2 Description */
/*! @{ */

#define GPMI_TIMING2_DATA_PAUSE_MASK             (0xFU)
#define GPMI_TIMING2_DATA_PAUSE_SHIFT            (0U)
#define GPMI_TIMING2_DATA_PAUSE(x)               (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING2_DATA_PAUSE_SHIFT)) & GPMI_TIMING2_DATA_PAUSE_MASK)

#define GPMI_TIMING2_CMDADD_PAUSE_MASK           (0xF0U)
#define GPMI_TIMING2_CMDADD_PAUSE_SHIFT          (4U)
#define GPMI_TIMING2_CMDADD_PAUSE(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING2_CMDADD_PAUSE_SHIFT)) & GPMI_TIMING2_CMDADD_PAUSE_MASK)

#define GPMI_TIMING2_POSTAMBLE_DELAY_MASK        (0xF00U)
#define GPMI_TIMING2_POSTAMBLE_DELAY_SHIFT       (8U)
#define GPMI_TIMING2_POSTAMBLE_DELAY(x)          (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING2_POSTAMBLE_DELAY_SHIFT)) & GPMI_TIMING2_POSTAMBLE_DELAY_MASK)

#define GPMI_TIMING2_PREAMBLE_DELAY_MASK         (0xF000U)
#define GPMI_TIMING2_PREAMBLE_DELAY_SHIFT        (12U)
#define GPMI_TIMING2_PREAMBLE_DELAY(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING2_PREAMBLE_DELAY_SHIFT)) & GPMI_TIMING2_PREAMBLE_DELAY_MASK)

#define GPMI_TIMING2_CE_DELAY_MASK               (0x1F0000U)
#define GPMI_TIMING2_CE_DELAY_SHIFT              (16U)
#define GPMI_TIMING2_CE_DELAY(x)                 (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING2_CE_DELAY_SHIFT)) & GPMI_TIMING2_CE_DELAY_MASK)

#define GPMI_TIMING2_RSVD0_MASK                  (0xE00000U)
#define GPMI_TIMING2_RSVD0_SHIFT                 (21U)
#define GPMI_TIMING2_RSVD0(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING2_RSVD0_SHIFT)) & GPMI_TIMING2_RSVD0_MASK)

#define GPMI_TIMING2_READ_LATENCY_MASK           (0x7000000U)
#define GPMI_TIMING2_READ_LATENCY_SHIFT          (24U)
/*! READ_LATENCY
 *  0b000..READ LATENCY is 0
 *  0b001..READ LATENCY is 1
 *  0b010..READ LATENCY is 2
 *  0b011..READ LATENCY is 3
 *  0b100..READ LATENCY is 4
 *  0b101..READ LATENCY is 5
 */
#define GPMI_TIMING2_READ_LATENCY(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING2_READ_LATENCY_SHIFT)) & GPMI_TIMING2_READ_LATENCY_MASK)

#define GPMI_TIMING2_TCR_MASK                    (0x18000000U)
#define GPMI_TIMING2_TCR_SHIFT                   (27U)
#define GPMI_TIMING2_TCR(x)                      (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING2_TCR_SHIFT)) & GPMI_TIMING2_TCR_MASK)

#define GPMI_TIMING2_TRPSTH_MASK                 (0xE0000000U)
#define GPMI_TIMING2_TRPSTH_SHIFT                (29U)
#define GPMI_TIMING2_TRPSTH(x)                   (((uint32_t)(((uint32_t)(x)) << GPMI_TIMING2_TRPSTH_SHIFT)) & GPMI_TIMING2_TRPSTH_MASK)
/*! @} */

/*! @name DATA - GPMI DMA Data Transfer Register Description */
/*! @{ */

#define GPMI_DATA_DATA_MASK                      (0xFFFFFFFFU)
#define GPMI_DATA_DATA_SHIFT                     (0U)
#define GPMI_DATA_DATA(x)                        (((uint32_t)(((uint32_t)(x)) << GPMI_DATA_DATA_SHIFT)) & GPMI_DATA_DATA_MASK)
/*! @} */

/*! @name STAT - GPMI Status Register Description */
/*! @{ */

#define GPMI_STAT_PRESENT_MASK                   (0x1U)
#define GPMI_STAT_PRESENT_SHIFT                  (0U)
/*! PRESENT
 *  0b0..GPMI is not present in this product.
 *  0b1..GPMI is present is in this product.
 */
#define GPMI_STAT_PRESENT(x)                     (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_PRESENT_SHIFT)) & GPMI_STAT_PRESENT_MASK)

#define GPMI_STAT_FIFO_FULL_MASK                 (0x2U)
#define GPMI_STAT_FIFO_FULL_SHIFT                (1U)
/*! FIFO_FULL
 *  0b0..FIFO is not full.
 *  0b1..FIFO is full.
 */
#define GPMI_STAT_FIFO_FULL(x)                   (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_FIFO_FULL_SHIFT)) & GPMI_STAT_FIFO_FULL_MASK)

#define GPMI_STAT_FIFO_EMPTY_MASK                (0x4U)
#define GPMI_STAT_FIFO_EMPTY_SHIFT               (2U)
/*! FIFO_EMPTY
 *  0b0..FIFO is not empty.
 *  0b1..FIFO is empty.
 */
#define GPMI_STAT_FIFO_EMPTY(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_FIFO_EMPTY_SHIFT)) & GPMI_STAT_FIFO_EMPTY_MASK)

#define GPMI_STAT_INVALID_BUFFER_MASK_MASK       (0x8U)
#define GPMI_STAT_INVALID_BUFFER_MASK_SHIFT      (3U)
/*! INVALID_BUFFER_MASK
 *  0b0..ECC Buffer Mask is not invalid.
 *  0b1..ECC Buffer Mask is invalid.
 */
#define GPMI_STAT_INVALID_BUFFER_MASK(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_INVALID_BUFFER_MASK_SHIFT)) & GPMI_STAT_INVALID_BUFFER_MASK_MASK)

#define GPMI_STAT_ATA_IRQ_MASK                   (0x10U)
#define GPMI_STAT_ATA_IRQ_SHIFT                  (4U)
#define GPMI_STAT_ATA_IRQ(x)                     (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_ATA_IRQ_SHIFT)) & GPMI_STAT_ATA_IRQ_MASK)

#define GPMI_STAT_RSVD1_MASK                     (0xE0U)
#define GPMI_STAT_RSVD1_SHIFT                    (5U)
#define GPMI_STAT_RSVD1(x)                       (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_RSVD1_SHIFT)) & GPMI_STAT_RSVD1_MASK)

#define GPMI_STAT_DEV0_ERROR_MASK                (0x100U)
#define GPMI_STAT_DEV0_ERROR_SHIFT               (8U)
/*! DEV0_ERROR
 *  0b0..No error condition present on ATA/NAND Device accessed by DMA channel 0.
 *  0b1..An Error has occurred on ATA/NAND Device accessed by
 */
#define GPMI_STAT_DEV0_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_DEV0_ERROR_SHIFT)) & GPMI_STAT_DEV0_ERROR_MASK)

#define GPMI_STAT_DEV1_ERROR_MASK                (0x200U)
#define GPMI_STAT_DEV1_ERROR_SHIFT               (9U)
/*! DEV1_ERROR
 *  0b0..No error condition present on ATA/NAND Device accessed by DMA channel 1.
 *  0b1..An Error has occurred on ATA/NAND Device accessed by
 */
#define GPMI_STAT_DEV1_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_DEV1_ERROR_SHIFT)) & GPMI_STAT_DEV1_ERROR_MASK)

#define GPMI_STAT_DEV2_ERROR_MASK                (0x400U)
#define GPMI_STAT_DEV2_ERROR_SHIFT               (10U)
/*! DEV2_ERROR
 *  0b0..No error condition present on ATA/NAND Device accessed by DMA channel 2.
 *  0b1..An Error has occurred on ATA/NAND Device accessed by
 */
#define GPMI_STAT_DEV2_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_DEV2_ERROR_SHIFT)) & GPMI_STAT_DEV2_ERROR_MASK)

#define GPMI_STAT_DEV3_ERROR_MASK                (0x800U)
#define GPMI_STAT_DEV3_ERROR_SHIFT               (11U)
/*! DEV3_ERROR
 *  0b0..No error condition present on ATA/NAND Device accessed by DMA channel 3.
 *  0b1..An Error has occurred on ATA/NAND Device accessed by
 */
#define GPMI_STAT_DEV3_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_DEV3_ERROR_SHIFT)) & GPMI_STAT_DEV3_ERROR_MASK)

#define GPMI_STAT_DEV4_ERROR_MASK                (0x1000U)
#define GPMI_STAT_DEV4_ERROR_SHIFT               (12U)
/*! DEV4_ERROR
 *  0b0..No error condition present on ATA/NAND Device accessed by DMA channel 4.
 *  0b1..An Error has occurred on ATA/NAND Device accessed by
 */
#define GPMI_STAT_DEV4_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_DEV4_ERROR_SHIFT)) & GPMI_STAT_DEV4_ERROR_MASK)

#define GPMI_STAT_DEV5_ERROR_MASK                (0x2000U)
#define GPMI_STAT_DEV5_ERROR_SHIFT               (13U)
/*! DEV5_ERROR
 *  0b0..No error condition present on ATA/NAND Device accessed by DMA channel 5.
 *  0b1..An Error has occurred on ATA/NAND Device accessed by
 */
#define GPMI_STAT_DEV5_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_DEV5_ERROR_SHIFT)) & GPMI_STAT_DEV5_ERROR_MASK)

#define GPMI_STAT_DEV6_ERROR_MASK                (0x4000U)
#define GPMI_STAT_DEV6_ERROR_SHIFT               (14U)
/*! DEV6_ERROR
 *  0b0..No error condition present on ATA/NAND Device accessed by DMA channel 6.
 *  0b1..An Error has occurred on ATA/NAND Device accessed by
 */
#define GPMI_STAT_DEV6_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_DEV6_ERROR_SHIFT)) & GPMI_STAT_DEV6_ERROR_MASK)

#define GPMI_STAT_DEV7_ERROR_MASK                (0x8000U)
#define GPMI_STAT_DEV7_ERROR_SHIFT               (15U)
/*! DEV7_ERROR
 *  0b0..No error condition present on ATA/NAND Device accessed by DMA channel 7.
 *  0b1..An Error has occurred on ATA/NAND Device accessed by
 */
#define GPMI_STAT_DEV7_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_DEV7_ERROR_SHIFT)) & GPMI_STAT_DEV7_ERROR_MASK)

#define GPMI_STAT_RDY_TIMEOUT_MASK               (0xFF0000U)
#define GPMI_STAT_RDY_TIMEOUT_SHIFT              (16U)
#define GPMI_STAT_RDY_TIMEOUT(x)                 (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_RDY_TIMEOUT_SHIFT)) & GPMI_STAT_RDY_TIMEOUT_MASK)

#define GPMI_STAT_READY_BUSY_MASK                (0xFF000000U)
#define GPMI_STAT_READY_BUSY_SHIFT               (24U)
#define GPMI_STAT_READY_BUSY(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_STAT_READY_BUSY_SHIFT)) & GPMI_STAT_READY_BUSY_MASK)
/*! @} */

/*! @name DEBUG - GPMI Debug Information Register Description */
/*! @{ */

#define GPMI_DEBUG_CMD_END_MASK                  (0xFFU)
#define GPMI_DEBUG_CMD_END_SHIFT                 (0U)
#define GPMI_DEBUG_CMD_END(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG_CMD_END_SHIFT)) & GPMI_DEBUG_CMD_END_MASK)

#define GPMI_DEBUG_DMAREQ_MASK                   (0xFF00U)
#define GPMI_DEBUG_DMAREQ_SHIFT                  (8U)
#define GPMI_DEBUG_DMAREQ(x)                     (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG_DMAREQ_SHIFT)) & GPMI_DEBUG_DMAREQ_MASK)

#define GPMI_DEBUG_DMA_SENSE_MASK                (0xFF0000U)
#define GPMI_DEBUG_DMA_SENSE_SHIFT               (16U)
#define GPMI_DEBUG_DMA_SENSE(x)                  (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG_DMA_SENSE_SHIFT)) & GPMI_DEBUG_DMA_SENSE_MASK)

#define GPMI_DEBUG_WAIT_FOR_READY_END_MASK       (0xFF000000U)
#define GPMI_DEBUG_WAIT_FOR_READY_END_SHIFT      (24U)
#define GPMI_DEBUG_WAIT_FOR_READY_END(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG_WAIT_FOR_READY_END_SHIFT)) & GPMI_DEBUG_WAIT_FOR_READY_END_MASK)
/*! @} */

/*! @name VERSION - GPMI Version Register Description */
/*! @{ */

#define GPMI_VERSION_STEP_MASK                   (0xFFFFU)
#define GPMI_VERSION_STEP_SHIFT                  (0U)
#define GPMI_VERSION_STEP(x)                     (((uint32_t)(((uint32_t)(x)) << GPMI_VERSION_STEP_SHIFT)) & GPMI_VERSION_STEP_MASK)

#define GPMI_VERSION_MINOR_MASK                  (0xFF0000U)
#define GPMI_VERSION_MINOR_SHIFT                 (16U)
#define GPMI_VERSION_MINOR(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_VERSION_MINOR_SHIFT)) & GPMI_VERSION_MINOR_MASK)

#define GPMI_VERSION_MAJOR_MASK                  (0xFF000000U)
#define GPMI_VERSION_MAJOR_SHIFT                 (24U)
#define GPMI_VERSION_MAJOR(x)                    (((uint32_t)(((uint32_t)(x)) << GPMI_VERSION_MAJOR_SHIFT)) & GPMI_VERSION_MAJOR_MASK)
/*! @} */

/*! @name DEBUG2 - GPMI Debug2 Information Register Description */
/*! @{ */

#define GPMI_DEBUG2_RDN_TAP_MASK                 (0x3FU)
#define GPMI_DEBUG2_RDN_TAP_SHIFT                (0U)
#define GPMI_DEBUG2_RDN_TAP(x)                   (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG2_RDN_TAP_SHIFT)) & GPMI_DEBUG2_RDN_TAP_MASK)

#define GPMI_DEBUG2_UPDATE_WINDOW_MASK           (0x40U)
#define GPMI_DEBUG2_UPDATE_WINDOW_SHIFT          (6U)
#define GPMI_DEBUG2_UPDATE_WINDOW(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG2_UPDATE_WINDOW_SHIFT)) & GPMI_DEBUG2_UPDATE_WINDOW_MASK)

#define GPMI_DEBUG2_VIEW_DELAYED_RDN_MASK        (0x80U)
#define GPMI_DEBUG2_VIEW_DELAYED_RDN_SHIFT       (7U)
#define GPMI_DEBUG2_VIEW_DELAYED_RDN(x)          (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG2_VIEW_DELAYED_RDN_SHIFT)) & GPMI_DEBUG2_VIEW_DELAYED_RDN_MASK)

#define GPMI_DEBUG2_SYND2GPMI_READY_MASK         (0x100U)
#define GPMI_DEBUG2_SYND2GPMI_READY_SHIFT        (8U)
#define GPMI_DEBUG2_SYND2GPMI_READY(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG2_SYND2GPMI_READY_SHIFT)) & GPMI_DEBUG2_SYND2GPMI_READY_MASK)

#define GPMI_DEBUG2_SYND2GPMI_VALID_MASK         (0x200U)
#define GPMI_DEBUG2_SYND2GPMI_VALID_SHIFT        (9U)
#define GPMI_DEBUG2_SYND2GPMI_VALID(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG2_SYND2GPMI_VALID_SHIFT)) & GPMI_DEBUG2_SYND2GPMI_VALID_MASK)

#define GPMI_DEBUG2_GPMI2SYND_READY_MASK         (0x400U)
#define GPMI_DEBUG2_GPMI2SYND_READY_SHIFT        (10U)
#define GPMI_DEBUG2_GPMI2SYND_READY(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG2_GPMI2SYND_READY_SHIFT)) & GPMI_DEBUG2_GPMI2SYND_READY_MASK)

#define GPMI_DEBUG2_GPMI2SYND_VALID_MASK         (0x800U)
#define GPMI_DEBUG2_GPMI2SYND_VALID_SHIFT        (11U)
#define GPMI_DEBUG2_GPMI2SYND_VALID(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG2_GPMI2SYND_VALID_SHIFT)) & GPMI_DEBUG2_GPMI2SYND_VALID_MASK)

#define GPMI_DEBUG2_SYND2GPMI_BE_MASK            (0xF000U)
#define GPMI_DEBUG2_SYND2GPMI_BE_SHIFT           (12U)
#define GPMI_DEBUG2_SYND2GPMI_BE(x)              (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG2_SYND2GPMI_BE_SHIFT)) & GPMI_DEBUG2_SYND2GPMI_BE_MASK)

#define GPMI_DEBUG2_MAIN_STATE_MASK              (0xF0000U)
#define GPMI_DEBUG2_MAIN_STATE_SHIFT             (16U)
#define GPMI_DEBUG2_MAIN_STATE(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG2_MAIN_STATE_SHIFT)) & GPMI_DEBUG2_MAIN_STATE_MASK)

#define GPMI_DEBUG2_PIN_STATE_MASK               (0x700000U)
#define GPMI_DEBUG2_PIN_STATE_SHIFT              (20U)
#define GPMI_DEBUG2_PIN_STATE(x)                 (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG2_PIN_STATE_SHIFT)) & GPMI_DEBUG2_PIN_STATE_MASK)

#define GPMI_DEBUG2_BUSY_MASK                    (0x800000U)
#define GPMI_DEBUG2_BUSY_SHIFT                   (23U)
#define GPMI_DEBUG2_BUSY(x)                      (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG2_BUSY_SHIFT)) & GPMI_DEBUG2_BUSY_MASK)

#define GPMI_DEBUG2_UDMA_STATE_MASK              (0xF000000U)
#define GPMI_DEBUG2_UDMA_STATE_SHIFT             (24U)
#define GPMI_DEBUG2_UDMA_STATE(x)                (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG2_UDMA_STATE_SHIFT)) & GPMI_DEBUG2_UDMA_STATE_MASK)

#define GPMI_DEBUG2_RSVD1_MASK                   (0xF0000000U)
#define GPMI_DEBUG2_RSVD1_SHIFT                  (28U)
#define GPMI_DEBUG2_RSVD1(x)                     (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG2_RSVD1_SHIFT)) & GPMI_DEBUG2_RSVD1_MASK)
/*! @} */

/*! @name DEBUG3 - GPMI Debug3 Information Register Description */
/*! @{ */

#define GPMI_DEBUG3_DEV_WORD_CNTR_MASK           (0xFFFFU)
#define GPMI_DEBUG3_DEV_WORD_CNTR_SHIFT          (0U)
#define GPMI_DEBUG3_DEV_WORD_CNTR(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG3_DEV_WORD_CNTR_SHIFT)) & GPMI_DEBUG3_DEV_WORD_CNTR_MASK)

#define GPMI_DEBUG3_APB_WORD_CNTR_MASK           (0xFFFF0000U)
#define GPMI_DEBUG3_APB_WORD_CNTR_SHIFT          (16U)
#define GPMI_DEBUG3_APB_WORD_CNTR(x)             (((uint32_t)(((uint32_t)(x)) << GPMI_DEBUG3_APB_WORD_CNTR_SHIFT)) & GPMI_DEBUG3_APB_WORD_CNTR_MASK)
/*! @} */

/*! @name READ_DDR_DLL_CTRL - GPMI Double Rate Read DLL Control Register Description */
/*! @{ */

#define GPMI_READ_DDR_DLL_CTRL_ENABLE_MASK       (0x1U)
#define GPMI_READ_DDR_DLL_CTRL_ENABLE_SHIFT      (0U)
#define GPMI_READ_DDR_DLL_CTRL_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_CTRL_ENABLE_SHIFT)) & GPMI_READ_DDR_DLL_CTRL_ENABLE_MASK)

#define GPMI_READ_DDR_DLL_CTRL_RESET_MASK        (0x2U)
#define GPMI_READ_DDR_DLL_CTRL_RESET_SHIFT       (1U)
#define GPMI_READ_DDR_DLL_CTRL_RESET(x)          (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_CTRL_RESET_SHIFT)) & GPMI_READ_DDR_DLL_CTRL_RESET_MASK)

#define GPMI_READ_DDR_DLL_CTRL_SLV_FORCE_UPD_MASK (0x4U)
#define GPMI_READ_DDR_DLL_CTRL_SLV_FORCE_UPD_SHIFT (2U)
#define GPMI_READ_DDR_DLL_CTRL_SLV_FORCE_UPD(x)  (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_CTRL_SLV_FORCE_UPD_SHIFT)) & GPMI_READ_DDR_DLL_CTRL_SLV_FORCE_UPD_MASK)

#define GPMI_READ_DDR_DLL_CTRL_SLV_DLY_TARGET_MASK (0x78U)
#define GPMI_READ_DDR_DLL_CTRL_SLV_DLY_TARGET_SHIFT (3U)
#define GPMI_READ_DDR_DLL_CTRL_SLV_DLY_TARGET(x) (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_CTRL_SLV_DLY_TARGET_SHIFT)) & GPMI_READ_DDR_DLL_CTRL_SLV_DLY_TARGET_MASK)

#define GPMI_READ_DDR_DLL_CTRL_GATE_UPDATE_MASK  (0x80U)
#define GPMI_READ_DDR_DLL_CTRL_GATE_UPDATE_SHIFT (7U)
#define GPMI_READ_DDR_DLL_CTRL_GATE_UPDATE(x)    (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_CTRL_GATE_UPDATE_SHIFT)) & GPMI_READ_DDR_DLL_CTRL_GATE_UPDATE_MASK)

#define GPMI_READ_DDR_DLL_CTRL_REFCLK_ON_MASK    (0x100U)
#define GPMI_READ_DDR_DLL_CTRL_REFCLK_ON_SHIFT   (8U)
#define GPMI_READ_DDR_DLL_CTRL_REFCLK_ON(x)      (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_CTRL_REFCLK_ON_SHIFT)) & GPMI_READ_DDR_DLL_CTRL_REFCLK_ON_MASK)

#define GPMI_READ_DDR_DLL_CTRL_SLV_OVERRIDE_MASK (0x200U)
#define GPMI_READ_DDR_DLL_CTRL_SLV_OVERRIDE_SHIFT (9U)
#define GPMI_READ_DDR_DLL_CTRL_SLV_OVERRIDE(x)   (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_CTRL_SLV_OVERRIDE_SHIFT)) & GPMI_READ_DDR_DLL_CTRL_SLV_OVERRIDE_MASK)

#define GPMI_READ_DDR_DLL_CTRL_SLV_OVERRIDE_VAL_MASK (0x3FC00U)
#define GPMI_READ_DDR_DLL_CTRL_SLV_OVERRIDE_VAL_SHIFT (10U)
#define GPMI_READ_DDR_DLL_CTRL_SLV_OVERRIDE_VAL(x) (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_CTRL_SLV_OVERRIDE_VAL_SHIFT)) & GPMI_READ_DDR_DLL_CTRL_SLV_OVERRIDE_VAL_MASK)

#define GPMI_READ_DDR_DLL_CTRL_RSVD1_MASK        (0xC0000U)
#define GPMI_READ_DDR_DLL_CTRL_RSVD1_SHIFT       (18U)
#define GPMI_READ_DDR_DLL_CTRL_RSVD1(x)          (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_CTRL_RSVD1_SHIFT)) & GPMI_READ_DDR_DLL_CTRL_RSVD1_MASK)

#define GPMI_READ_DDR_DLL_CTRL_SLV_UPDATE_INT_MASK (0xFF00000U)
#define GPMI_READ_DDR_DLL_CTRL_SLV_UPDATE_INT_SHIFT (20U)
#define GPMI_READ_DDR_DLL_CTRL_SLV_UPDATE_INT(x) (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_CTRL_SLV_UPDATE_INT_SHIFT)) & GPMI_READ_DDR_DLL_CTRL_SLV_UPDATE_INT_MASK)

#define GPMI_READ_DDR_DLL_CTRL_REF_UPDATE_INT_MASK (0xF0000000U)
#define GPMI_READ_DDR_DLL_CTRL_REF_UPDATE_INT_SHIFT (28U)
#define GPMI_READ_DDR_DLL_CTRL_REF_UPDATE_INT(x) (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_CTRL_REF_UPDATE_INT_SHIFT)) & GPMI_READ_DDR_DLL_CTRL_REF_UPDATE_INT_MASK)
/*! @} */

/*! @name WRITE_DDR_DLL_CTRL - GPMI Double Rate Write DLL Control Register Description */
/*! @{ */

#define GPMI_WRITE_DDR_DLL_CTRL_ENABLE_MASK      (0x1U)
#define GPMI_WRITE_DDR_DLL_CTRL_ENABLE_SHIFT     (0U)
#define GPMI_WRITE_DDR_DLL_CTRL_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_CTRL_ENABLE_SHIFT)) & GPMI_WRITE_DDR_DLL_CTRL_ENABLE_MASK)

#define GPMI_WRITE_DDR_DLL_CTRL_RESET_MASK       (0x2U)
#define GPMI_WRITE_DDR_DLL_CTRL_RESET_SHIFT      (1U)
#define GPMI_WRITE_DDR_DLL_CTRL_RESET(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_CTRL_RESET_SHIFT)) & GPMI_WRITE_DDR_DLL_CTRL_RESET_MASK)

#define GPMI_WRITE_DDR_DLL_CTRL_SLV_FORCE_UPD_MASK (0x4U)
#define GPMI_WRITE_DDR_DLL_CTRL_SLV_FORCE_UPD_SHIFT (2U)
#define GPMI_WRITE_DDR_DLL_CTRL_SLV_FORCE_UPD(x) (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_CTRL_SLV_FORCE_UPD_SHIFT)) & GPMI_WRITE_DDR_DLL_CTRL_SLV_FORCE_UPD_MASK)

#define GPMI_WRITE_DDR_DLL_CTRL_SLV_DLY_TARGET_MASK (0x78U)
#define GPMI_WRITE_DDR_DLL_CTRL_SLV_DLY_TARGET_SHIFT (3U)
#define GPMI_WRITE_DDR_DLL_CTRL_SLV_DLY_TARGET(x) (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_CTRL_SLV_DLY_TARGET_SHIFT)) & GPMI_WRITE_DDR_DLL_CTRL_SLV_DLY_TARGET_MASK)

#define GPMI_WRITE_DDR_DLL_CTRL_GATE_UPDATE_MASK (0x80U)
#define GPMI_WRITE_DDR_DLL_CTRL_GATE_UPDATE_SHIFT (7U)
#define GPMI_WRITE_DDR_DLL_CTRL_GATE_UPDATE(x)   (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_CTRL_GATE_UPDATE_SHIFT)) & GPMI_WRITE_DDR_DLL_CTRL_GATE_UPDATE_MASK)

#define GPMI_WRITE_DDR_DLL_CTRL_REFCLK_ON_MASK   (0x100U)
#define GPMI_WRITE_DDR_DLL_CTRL_REFCLK_ON_SHIFT  (8U)
#define GPMI_WRITE_DDR_DLL_CTRL_REFCLK_ON(x)     (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_CTRL_REFCLK_ON_SHIFT)) & GPMI_WRITE_DDR_DLL_CTRL_REFCLK_ON_MASK)

#define GPMI_WRITE_DDR_DLL_CTRL_SLV_OVERRIDE_MASK (0x200U)
#define GPMI_WRITE_DDR_DLL_CTRL_SLV_OVERRIDE_SHIFT (9U)
#define GPMI_WRITE_DDR_DLL_CTRL_SLV_OVERRIDE(x)  (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_CTRL_SLV_OVERRIDE_SHIFT)) & GPMI_WRITE_DDR_DLL_CTRL_SLV_OVERRIDE_MASK)

#define GPMI_WRITE_DDR_DLL_CTRL_SLV_OVERRIDE_VAL_MASK (0x3FC00U)
#define GPMI_WRITE_DDR_DLL_CTRL_SLV_OVERRIDE_VAL_SHIFT (10U)
#define GPMI_WRITE_DDR_DLL_CTRL_SLV_OVERRIDE_VAL(x) (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_CTRL_SLV_OVERRIDE_VAL_SHIFT)) & GPMI_WRITE_DDR_DLL_CTRL_SLV_OVERRIDE_VAL_MASK)

#define GPMI_WRITE_DDR_DLL_CTRL_RSVD1_MASK       (0xC0000U)
#define GPMI_WRITE_DDR_DLL_CTRL_RSVD1_SHIFT      (18U)
#define GPMI_WRITE_DDR_DLL_CTRL_RSVD1(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_CTRL_RSVD1_SHIFT)) & GPMI_WRITE_DDR_DLL_CTRL_RSVD1_MASK)

#define GPMI_WRITE_DDR_DLL_CTRL_SLV_UPDATE_INT_MASK (0xFF00000U)
#define GPMI_WRITE_DDR_DLL_CTRL_SLV_UPDATE_INT_SHIFT (20U)
#define GPMI_WRITE_DDR_DLL_CTRL_SLV_UPDATE_INT(x) (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_CTRL_SLV_UPDATE_INT_SHIFT)) & GPMI_WRITE_DDR_DLL_CTRL_SLV_UPDATE_INT_MASK)

#define GPMI_WRITE_DDR_DLL_CTRL_REF_UPDATE_INT_MASK (0xF0000000U)
#define GPMI_WRITE_DDR_DLL_CTRL_REF_UPDATE_INT_SHIFT (28U)
#define GPMI_WRITE_DDR_DLL_CTRL_REF_UPDATE_INT(x) (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_CTRL_REF_UPDATE_INT_SHIFT)) & GPMI_WRITE_DDR_DLL_CTRL_REF_UPDATE_INT_MASK)
/*! @} */

/*! @name READ_DDR_DLL_STS - GPMI Double Rate Read DLL Status Register Description */
/*! @{ */

#define GPMI_READ_DDR_DLL_STS_SLV_LOCK_MASK      (0x1U)
#define GPMI_READ_DDR_DLL_STS_SLV_LOCK_SHIFT     (0U)
#define GPMI_READ_DDR_DLL_STS_SLV_LOCK(x)        (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_STS_SLV_LOCK_SHIFT)) & GPMI_READ_DDR_DLL_STS_SLV_LOCK_MASK)

#define GPMI_READ_DDR_DLL_STS_SLV_SEL_MASK       (0x1FEU)
#define GPMI_READ_DDR_DLL_STS_SLV_SEL_SHIFT      (1U)
#define GPMI_READ_DDR_DLL_STS_SLV_SEL(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_STS_SLV_SEL_SHIFT)) & GPMI_READ_DDR_DLL_STS_SLV_SEL_MASK)

#define GPMI_READ_DDR_DLL_STS_RSVD0_MASK         (0xFE00U)
#define GPMI_READ_DDR_DLL_STS_RSVD0_SHIFT        (9U)
#define GPMI_READ_DDR_DLL_STS_RSVD0(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_STS_RSVD0_SHIFT)) & GPMI_READ_DDR_DLL_STS_RSVD0_MASK)

#define GPMI_READ_DDR_DLL_STS_REF_LOCK_MASK      (0x10000U)
#define GPMI_READ_DDR_DLL_STS_REF_LOCK_SHIFT     (16U)
#define GPMI_READ_DDR_DLL_STS_REF_LOCK(x)        (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_STS_REF_LOCK_SHIFT)) & GPMI_READ_DDR_DLL_STS_REF_LOCK_MASK)

#define GPMI_READ_DDR_DLL_STS_REF_SEL_MASK       (0x1FE0000U)
#define GPMI_READ_DDR_DLL_STS_REF_SEL_SHIFT      (17U)
#define GPMI_READ_DDR_DLL_STS_REF_SEL(x)         (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_STS_REF_SEL_SHIFT)) & GPMI_READ_DDR_DLL_STS_REF_SEL_MASK)

#define GPMI_READ_DDR_DLL_STS_RSVD1_MASK         (0xFE000000U)
#define GPMI_READ_DDR_DLL_STS_RSVD1_SHIFT        (25U)
#define GPMI_READ_DDR_DLL_STS_RSVD1(x)           (((uint32_t)(((uint32_t)(x)) << GPMI_READ_DDR_DLL_STS_RSVD1_SHIFT)) & GPMI_READ_DDR_DLL_STS_RSVD1_MASK)
/*! @} */

/*! @name WRITE_DDR_DLL_STS - GPMI Double Rate Write DLL Status Register Description */
/*! @{ */

#define GPMI_WRITE_DDR_DLL_STS_SLV_LOCK_MASK     (0x1U)
#define GPMI_WRITE_DDR_DLL_STS_SLV_LOCK_SHIFT    (0U)
#define GPMI_WRITE_DDR_DLL_STS_SLV_LOCK(x)       (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_STS_SLV_LOCK_SHIFT)) & GPMI_WRITE_DDR_DLL_STS_SLV_LOCK_MASK)

#define GPMI_WRITE_DDR_DLL_STS_SLV_SEL_MASK      (0x1FEU)
#define GPMI_WRITE_DDR_DLL_STS_SLV_SEL_SHIFT     (1U)
#define GPMI_WRITE_DDR_DLL_STS_SLV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_STS_SLV_SEL_SHIFT)) & GPMI_WRITE_DDR_DLL_STS_SLV_SEL_MASK)

#define GPMI_WRITE_DDR_DLL_STS_RSVD0_MASK        (0xFE00U)
#define GPMI_WRITE_DDR_DLL_STS_RSVD0_SHIFT       (9U)
#define GPMI_WRITE_DDR_DLL_STS_RSVD0(x)          (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_STS_RSVD0_SHIFT)) & GPMI_WRITE_DDR_DLL_STS_RSVD0_MASK)

#define GPMI_WRITE_DDR_DLL_STS_REF_LOCK_MASK     (0x10000U)
#define GPMI_WRITE_DDR_DLL_STS_REF_LOCK_SHIFT    (16U)
#define GPMI_WRITE_DDR_DLL_STS_REF_LOCK(x)       (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_STS_REF_LOCK_SHIFT)) & GPMI_WRITE_DDR_DLL_STS_REF_LOCK_MASK)

#define GPMI_WRITE_DDR_DLL_STS_REF_SEL_MASK      (0x1FE0000U)
#define GPMI_WRITE_DDR_DLL_STS_REF_SEL_SHIFT     (17U)
#define GPMI_WRITE_DDR_DLL_STS_REF_SEL(x)        (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_STS_REF_SEL_SHIFT)) & GPMI_WRITE_DDR_DLL_STS_REF_SEL_MASK)

#define GPMI_WRITE_DDR_DLL_STS_RSVD1_MASK        (0xFE000000U)
#define GPMI_WRITE_DDR_DLL_STS_RSVD1_SHIFT       (25U)
#define GPMI_WRITE_DDR_DLL_STS_RSVD1(x)          (((uint32_t)(((uint32_t)(x)) << GPMI_WRITE_DDR_DLL_STS_RSVD1_SHIFT)) & GPMI_WRITE_DDR_DLL_STS_RSVD1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPMI_Register_Masks */


/*!
 * @}
 */ /* end of group GPMI_Peripheral_Access_Layer */


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


#endif  /* PERI_GPMI_H_ */

