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
**         CMSIS Peripheral Access Layer for SIUL2
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
 * @file PERI_SIUL2.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for SIUL2
 *
 * CMSIS Peripheral Access Layer for SIUL2
 */

#if !defined(PERI_SIUL2_H_)
#define PERI_SIUL2_H_                            /**< Symbol preventing repeated inclusion */

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

/* ----------------------------------------------------------------------------
   -- SIUL2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIUL2_Peripheral_Access_Layer SIUL2 Peripheral Access Layer
 * @{
 */

/** SIUL2 - Size of Registers Arrays */
#define SIUL2_IFMCR_COUNT                         32u
#define SIUL2_MSCR_COUNT                          145u
#define SIUL2_IMCR_COUNT                          400u
#define SIUL2_GPDO_COUNT                          148u
#define SIUL2_GPDI_COUNT                          148u
#define SIUL2_PGPDO_COUNT                         10u
#define SIUL2_PGPDI_COUNT                         10u
#define SIUL2_MPGPDO_COUNT                        10u

/** SIUL2 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __I  uint32_t MIDR1;                             /**< SIUL2 MCU ID Register #1, offset: 0x4 */
  __I  uint32_t MIDR2;                             /**< SIUL2 MCU ID Register #2, offset: 0x8 */
       uint8_t RESERVED_1[4];
  __IO uint32_t DISR0;                             /**< SIUL2 DMA/Interrupt Status Flag 0, offset: 0x10 */
       uint8_t RESERVED_2[4];
  __IO uint32_t DIRER0;                            /**< SIUL2 DMA/Interrupt Request Enable 0, offset: 0x18 */
       uint8_t RESERVED_3[4];
  __IO uint32_t DIRSR0;                            /**< SIUL2 DMA/Interrupt Request Select 0, offset: 0x20 */
       uint8_t RESERVED_4[4];
  __IO uint32_t IREER0;                            /**< SIUL2 Interrupt Rising-Edge Event Enable 0, offset: 0x28 */
       uint8_t RESERVED_5[4];
  __IO uint32_t IFEER0;                            /**< SIUL2 Interrupt Falling-Edge Event Enable 0, offset: 0x30 */
       uint8_t RESERVED_6[4];
  __IO uint32_t IFER0;                             /**< SIUL2 Interrupt Filter Enable 0, offset: 0x38 */
       uint8_t RESERVED_7[4];
  __IO uint32_t IFMCR[SIUL2_IFMCR_COUNT];          /**< SIUL2 Interrupt Filter Maximum Counter, array offset: 0x40, array step: 0x4 */
  __IO uint32_t IFCPR;                             /**< SIUL2 Interrupt Filter Clock Prescaler, offset: 0xC0 */
       uint8_t RESERVED_8[60];
  __IO uint32_t MUX0_EMIOS_EN1;                    /**< MUX0 EMIOS ENABLE 1, offset: 0x100 */
  __IO uint32_t MUX0_MISC_EN;                      /**< MUX0 MISC ENABLE, offset: 0x104 */
  __IO uint32_t MUX1_EMIOS_EN;                     /**< MUX1 EMIOS ENABLE, offset: 0x108 */
  __IO uint32_t MUX1_MISC_EN;                      /**< MUX1 MISC ENABLE, offset: 0x10C */
       uint8_t RESERVED_9[240];
  __I  uint32_t MIDR3;                             /**< SIUL2 MCU ID Register #3, offset: 0x200 */
  __I  uint32_t MIDR4;                             /**< SIUL2 MCU ID Register #4, offset: 0x204 */
       uint8_t RESERVED_10[56];
  __IO uint32_t MSCR[SIUL2_MSCR_COUNT];            /**< SIUL2 Multiplexed Signal Configuration Register, array offset: 0x240, array step: 0x4, valid indices: [0-17, 32-37, 40-49, 64-81, 96-113, 128-131, 134-141, 143-144] */
       uint8_t RESERVED_11[1468];
  __IO uint32_t IMCR[SIUL2_IMCR_COUNT];            /**< SIUL2 Input Multiplexed Signal Configuration, array offset: 0xA40, array step: 0x4, valid indices: [0-2, 16-71, 80-103, 148-149, 152-167, 184-190, 211-254, 343-366, 371-378, 399] */
       uint8_t RESERVED_12[640];
  __IO uint8_t GPDO[SIUL2_GPDO_COUNT];             /**< SIUL2 GPIO Pad Data Output, array offset: 0x1300, array step: 0x1, valid indices: [0-15, 18-19, 32-35, 38-47, 50-51, 64-79, 82-83, 96-111, 114-115, 128-133, 136-140, 142-143, 147] */
       uint8_t RESERVED_13[364];
  __I  uint8_t GPDI[SIUL2_GPDI_COUNT];             /**< SIUL2 GPIO Pad Data Input, array offset: 0x1500, array step: 0x1, valid indices: [0-15, 18-19, 32-35, 38-47, 50-51, 64-79, 82-83, 96-111, 114-115, 128-133, 136-140, 142-143, 147] */
       uint8_t RESERVED_14[364];
  __IO uint16_t PGPDO[SIUL2_PGPDO_COUNT];          /**< SIUL2 Parallel GPIO Pad Data Out, array offset: 0x1700, array step: 0x2 */
       uint8_t RESERVED_15[44];
  __I  uint16_t PGPDI[SIUL2_PGPDI_COUNT];          /**< SIUL2 Parallel GPIO Pad Data In, array offset: 0x1740, array step: 0x2 */
       uint8_t RESERVED_16[44];
  __IO uint32_t MPGPDO[SIUL2_MPGPDO_COUNT];        /**< SIUL2 Masked Parallel GPIO Pad Data Out, array offset: 0x1780, array step: 0x4 */
} SIUL2_Type;

/* ----------------------------------------------------------------------------
   -- SIUL2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIUL2_Register_Masks SIUL2 Register Masks
 * @{
 */

/*! @name MIDR1 - SIUL2 MCU ID Register #1 */
/*! @{ */

#define SIUL2_MIDR1_MINOR_MASK_MASK              (0xFU)
#define SIUL2_MIDR1_MINOR_MASK_SHIFT             (0U)
/*! MINOR_MASK - Minor Mask Revision */
#define SIUL2_MIDR1_MINOR_MASK(x)                (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR1_MINOR_MASK_SHIFT)) & SIUL2_MIDR1_MINOR_MASK_MASK)

#define SIUL2_MIDR1_MAJOR_MASK_MASK              (0xF0U)
#define SIUL2_MIDR1_MAJOR_MASK_SHIFT             (4U)
/*! MAJOR_MASK - Major Mask Revision */
#define SIUL2_MIDR1_MAJOR_MASK(x)                (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR1_MAJOR_MASK_SHIFT)) & SIUL2_MIDR1_MAJOR_MASK_MASK)

#define SIUL2_MIDR1_PART_NO_MASK                 (0x3FF0000U)
#define SIUL2_MIDR1_PART_NO_SHIFT                (16U)
/*! PART_NO - MCU Part Number */
#define SIUL2_MIDR1_PART_NO(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR1_PART_NO_SHIFT)) & SIUL2_MIDR1_PART_NO_MASK)

#define SIUL2_MIDR1_PRODUCT_LINE_LETTER_MASK     (0xFC000000U)
#define SIUL2_MIDR1_PRODUCT_LINE_LETTER_SHIFT    (26U)
/*! PRODUCT_LINE_LETTER - Product Line Letter */
#define SIUL2_MIDR1_PRODUCT_LINE_LETTER(x)       (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR1_PRODUCT_LINE_LETTER_SHIFT)) & SIUL2_MIDR1_PRODUCT_LINE_LETTER_MASK)
/*! @} */

/*! @name MIDR2 - SIUL2 MCU ID Register #2 */
/*! @{ */

#define SIUL2_MIDR2_FLASH_SIZE_CODE_MASK         (0xFFU)
#define SIUL2_MIDR2_FLASH_SIZE_CODE_SHIFT        (0U)
/*! FLASH_SIZE_CODE - Flash Size Code
 *  0b00000010..512kB
 *  0b00000100..1MB
 *  0b00001000..2.00MB
 *  0b00001100..3.00MB
 *  0b00010000..4.00MB
 *  0b00011000..6.00MB
 *  0b00100000..8.00MB
 */
#define SIUL2_MIDR2_FLASH_SIZE_CODE(x)           (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR2_FLASH_SIZE_CODE_SHIFT)) & SIUL2_MIDR2_FLASH_SIZE_CODE_MASK)

#define SIUL2_MIDR2_FLASH_SIZE_DATA_MASK         (0xF00U)
#define SIUL2_MIDR2_FLASH_SIZE_DATA_SHIFT        (8U)
/*! FLASH_SIZE_DATA - Flash Size Data
 *  0b0000..64KB
 *  0b0001..128KB
 *  0b0010..256KB
 */
#define SIUL2_MIDR2_FLASH_SIZE_DATA(x)           (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR2_FLASH_SIZE_DATA_SHIFT)) & SIUL2_MIDR2_FLASH_SIZE_DATA_MASK)

#define SIUL2_MIDR2_FLASH_DATA_MASK              (0x3000U)
#define SIUL2_MIDR2_FLASH_DATA_SHIFT             (12U)
/*! FLASH_DATA - Flash Data
 *  0b10..Monolithic
 */
#define SIUL2_MIDR2_FLASH_DATA(x)                (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR2_FLASH_DATA_SHIFT)) & SIUL2_MIDR2_FLASH_DATA_MASK)

#define SIUL2_MIDR2_FLASH_CODE_MASK              (0xC000U)
#define SIUL2_MIDR2_FLASH_CODE_SHIFT             (14U)
/*! FLASH_CODE - Flash Code
 *  0b10..Monolithic
 */
#define SIUL2_MIDR2_FLASH_CODE(x)                (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR2_FLASH_CODE_SHIFT)) & SIUL2_MIDR2_FLASH_CODE_MASK)

#define SIUL2_MIDR2_FREQUENCY_MASK               (0xF0000U)
#define SIUL2_MIDR2_FREQUENCY_SHIFT              (16U)
/*! FREQUENCY - Frequency
 *  0b0011..120 MHz
 *  0b0100..160 MHz
 *  0b0101..240 MHz
 */
#define SIUL2_MIDR2_FREQUENCY(x)                 (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR2_FREQUENCY_SHIFT)) & SIUL2_MIDR2_FREQUENCY_MASK)

#define SIUL2_MIDR2_PACKAGE_MASK                 (0x3F00000U)
#define SIUL2_MIDR2_PACKAGE_SHIFT                (20U)
/*! PACKAGE - Package
 *  0b000011..257-MAPBGA
 *  0b100010..100-MAXQFP
 *  0b100101..172-MAXQFP
 */
#define SIUL2_MIDR2_PACKAGE(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR2_PACKAGE_SHIFT)) & SIUL2_MIDR2_PACKAGE_MASK)

#define SIUL2_MIDR2_TEMPERATURE_MASK             (0x1C000000U)
#define SIUL2_MIDR2_TEMPERATURE_SHIFT            (26U)
/*! TEMPERATURE - Temperature
 *  0b100..M = 125C
 */
#define SIUL2_MIDR2_TEMPERATURE(x)               (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR2_TEMPERATURE_SHIFT)) & SIUL2_MIDR2_TEMPERATURE_MASK)

#define SIUL2_MIDR2_TECHNOLOGY_MASK              (0xE0000000U)
#define SIUL2_MIDR2_TECHNOLOGY_SHIFT             (29U)
/*! TECHNOLOGY - Technology
 *  0b001..C40EFS3
 */
#define SIUL2_MIDR2_TECHNOLOGY(x)                (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR2_TECHNOLOGY_SHIFT)) & SIUL2_MIDR2_TECHNOLOGY_MASK)
/*! @} */

/*! @name DISR0 - SIUL2 DMA/Interrupt Status Flag 0 */
/*! @{ */

#define SIUL2_DISR0_EIF0_MASK                    (0x1U)
#define SIUL2_DISR0_EIF0_SHIFT                   (0U)
/*! EIF0 - External Interrupt Status Flag 0
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER0 and IFEER0 has occurred.
 */
#define SIUL2_DISR0_EIF0(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF0_SHIFT)) & SIUL2_DISR0_EIF0_MASK)

#define SIUL2_DISR0_EIF1_MASK                    (0x2U)
#define SIUL2_DISR0_EIF1_SHIFT                   (1U)
/*! EIF1 - External Interrupt Status Flag 1
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER1 and IFEER1 has occurred.
 */
#define SIUL2_DISR0_EIF1(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF1_SHIFT)) & SIUL2_DISR0_EIF1_MASK)

#define SIUL2_DISR0_EIF2_MASK                    (0x4U)
#define SIUL2_DISR0_EIF2_SHIFT                   (2U)
/*! EIF2 - External Interrupt Status Flag 2
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER2 and IFEER2 has occurred.
 */
#define SIUL2_DISR0_EIF2(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF2_SHIFT)) & SIUL2_DISR0_EIF2_MASK)

#define SIUL2_DISR0_EIF3_MASK                    (0x8U)
#define SIUL2_DISR0_EIF3_SHIFT                   (3U)
/*! EIF3 - External Interrupt Status Flag 3
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER3 and IFEER3 has occurred.
 */
#define SIUL2_DISR0_EIF3(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF3_SHIFT)) & SIUL2_DISR0_EIF3_MASK)

#define SIUL2_DISR0_EIF4_MASK                    (0x10U)
#define SIUL2_DISR0_EIF4_SHIFT                   (4U)
/*! EIF4 - External Interrupt Status Flag 4
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER4 and IFEER4 has occurred.
 */
#define SIUL2_DISR0_EIF4(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF4_SHIFT)) & SIUL2_DISR0_EIF4_MASK)

#define SIUL2_DISR0_EIF5_MASK                    (0x20U)
#define SIUL2_DISR0_EIF5_SHIFT                   (5U)
/*! EIF5 - External Interrupt Status Flag 5
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER5 and IFEER5 has occurred.
 */
#define SIUL2_DISR0_EIF5(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF5_SHIFT)) & SIUL2_DISR0_EIF5_MASK)

#define SIUL2_DISR0_EIF6_MASK                    (0x40U)
#define SIUL2_DISR0_EIF6_SHIFT                   (6U)
/*! EIF6 - External Interrupt Status Flag 6
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER6 and IFEER6 has occurred.
 */
#define SIUL2_DISR0_EIF6(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF6_SHIFT)) & SIUL2_DISR0_EIF6_MASK)

#define SIUL2_DISR0_EIF7_MASK                    (0x80U)
#define SIUL2_DISR0_EIF7_SHIFT                   (7U)
/*! EIF7 - External Interrupt Status Flag 7
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER7 and IFEER7 has occurred.
 */
#define SIUL2_DISR0_EIF7(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF7_SHIFT)) & SIUL2_DISR0_EIF7_MASK)

#define SIUL2_DISR0_EIF8_MASK                    (0x100U)
#define SIUL2_DISR0_EIF8_SHIFT                   (8U)
/*! EIF8 - External Interrupt Status Flag 8
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER8 and IFEER8 has occurred.
 */
#define SIUL2_DISR0_EIF8(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF8_SHIFT)) & SIUL2_DISR0_EIF8_MASK)

#define SIUL2_DISR0_EIF9_MASK                    (0x200U)
#define SIUL2_DISR0_EIF9_SHIFT                   (9U)
/*! EIF9 - External Interrupt Status Flag 9
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER9 and IFEER9 has occurred.
 */
#define SIUL2_DISR0_EIF9(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF9_SHIFT)) & SIUL2_DISR0_EIF9_MASK)

#define SIUL2_DISR0_EIF10_MASK                   (0x400U)
#define SIUL2_DISR0_EIF10_SHIFT                  (10U)
/*! EIF10 - External Interrupt Status Flag 10
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER10 and IFEER10 has occurred.
 */
#define SIUL2_DISR0_EIF10(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF10_SHIFT)) & SIUL2_DISR0_EIF10_MASK)

#define SIUL2_DISR0_EIF11_MASK                   (0x800U)
#define SIUL2_DISR0_EIF11_SHIFT                  (11U)
/*! EIF11 - External Interrupt Status Flag 11
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER11 and IFEER11 has occurred.
 */
#define SIUL2_DISR0_EIF11(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF11_SHIFT)) & SIUL2_DISR0_EIF11_MASK)

#define SIUL2_DISR0_EIF12_MASK                   (0x1000U)
#define SIUL2_DISR0_EIF12_SHIFT                  (12U)
/*! EIF12 - External Interrupt Status Flag 12
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER12 and IFEER12 has occurred.
 */
#define SIUL2_DISR0_EIF12(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF12_SHIFT)) & SIUL2_DISR0_EIF12_MASK)

#define SIUL2_DISR0_EIF13_MASK                   (0x2000U)
#define SIUL2_DISR0_EIF13_SHIFT                  (13U)
/*! EIF13 - External Interrupt Status Flag 13
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER13 and IFEER13 has occurred.
 */
#define SIUL2_DISR0_EIF13(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF13_SHIFT)) & SIUL2_DISR0_EIF13_MASK)

#define SIUL2_DISR0_EIF14_MASK                   (0x4000U)
#define SIUL2_DISR0_EIF14_SHIFT                  (14U)
/*! EIF14 - External Interrupt Status Flag 14
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER14 and IFEER14 has occurred.
 */
#define SIUL2_DISR0_EIF14(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF14_SHIFT)) & SIUL2_DISR0_EIF14_MASK)

#define SIUL2_DISR0_EIF15_MASK                   (0x8000U)
#define SIUL2_DISR0_EIF15_SHIFT                  (15U)
/*! EIF15 - External Interrupt Status Flag 15
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER15 and IFEER15 has occurred.
 */
#define SIUL2_DISR0_EIF15(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF15_SHIFT)) & SIUL2_DISR0_EIF15_MASK)

#define SIUL2_DISR0_EIF16_MASK                   (0x10000U)
#define SIUL2_DISR0_EIF16_SHIFT                  (16U)
/*! EIF16 - External Interrupt Status Flag 16
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER16 and IFEER16 has occurred.
 */
#define SIUL2_DISR0_EIF16(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF16_SHIFT)) & SIUL2_DISR0_EIF16_MASK)

#define SIUL2_DISR0_EIF17_MASK                   (0x20000U)
#define SIUL2_DISR0_EIF17_SHIFT                  (17U)
/*! EIF17 - External Interrupt Status Flag 17
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER17 and IFEER17 has occurred.
 */
#define SIUL2_DISR0_EIF17(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF17_SHIFT)) & SIUL2_DISR0_EIF17_MASK)

#define SIUL2_DISR0_EIF18_MASK                   (0x40000U)
#define SIUL2_DISR0_EIF18_SHIFT                  (18U)
/*! EIF18 - External Interrupt Status Flag 18
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER18 and IFEER18 has occurred.
 */
#define SIUL2_DISR0_EIF18(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF18_SHIFT)) & SIUL2_DISR0_EIF18_MASK)

#define SIUL2_DISR0_EIF19_MASK                   (0x80000U)
#define SIUL2_DISR0_EIF19_SHIFT                  (19U)
/*! EIF19 - External Interrupt Status Flag 19
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER19 and IFEER19 has occurred.
 */
#define SIUL2_DISR0_EIF19(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF19_SHIFT)) & SIUL2_DISR0_EIF19_MASK)

#define SIUL2_DISR0_EIF20_MASK                   (0x100000U)
#define SIUL2_DISR0_EIF20_SHIFT                  (20U)
/*! EIF20 - External Interrupt Status Flag 20
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER20 and IFEER20 has occurred.
 */
#define SIUL2_DISR0_EIF20(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF20_SHIFT)) & SIUL2_DISR0_EIF20_MASK)

#define SIUL2_DISR0_EIF21_MASK                   (0x200000U)
#define SIUL2_DISR0_EIF21_SHIFT                  (21U)
/*! EIF21 - External Interrupt Status Flag 21
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER21 and IFEER21 has occurred.
 */
#define SIUL2_DISR0_EIF21(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF21_SHIFT)) & SIUL2_DISR0_EIF21_MASK)

#define SIUL2_DISR0_EIF22_MASK                   (0x400000U)
#define SIUL2_DISR0_EIF22_SHIFT                  (22U)
/*! EIF22 - External Interrupt Status Flag 22
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER22 and IFEER22 has occurred.
 */
#define SIUL2_DISR0_EIF22(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF22_SHIFT)) & SIUL2_DISR0_EIF22_MASK)

#define SIUL2_DISR0_EIF23_MASK                   (0x800000U)
#define SIUL2_DISR0_EIF23_SHIFT                  (23U)
/*! EIF23 - External Interrupt Status Flag 23
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER23 and IFEER23 has occurred.
 */
#define SIUL2_DISR0_EIF23(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF23_SHIFT)) & SIUL2_DISR0_EIF23_MASK)

#define SIUL2_DISR0_EIF24_MASK                   (0x1000000U)
#define SIUL2_DISR0_EIF24_SHIFT                  (24U)
/*! EIF24 - External Interrupt Status Flag 24
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER24 and IFEER24 has occurred.
 */
#define SIUL2_DISR0_EIF24(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF24_SHIFT)) & SIUL2_DISR0_EIF24_MASK)

#define SIUL2_DISR0_EIF25_MASK                   (0x2000000U)
#define SIUL2_DISR0_EIF25_SHIFT                  (25U)
/*! EIF25 - External Interrupt Status Flag 25
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER25 and IFEER25 has occurred.
 */
#define SIUL2_DISR0_EIF25(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF25_SHIFT)) & SIUL2_DISR0_EIF25_MASK)

#define SIUL2_DISR0_EIF26_MASK                   (0x4000000U)
#define SIUL2_DISR0_EIF26_SHIFT                  (26U)
/*! EIF26 - External Interrupt Status Flag 26
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER26 and IFEER26 has occurred.
 */
#define SIUL2_DISR0_EIF26(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF26_SHIFT)) & SIUL2_DISR0_EIF26_MASK)

#define SIUL2_DISR0_EIF27_MASK                   (0x8000000U)
#define SIUL2_DISR0_EIF27_SHIFT                  (27U)
/*! EIF27 - External Interrupt Status Flag 27
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER27 and IFEER27 has occurred.
 */
#define SIUL2_DISR0_EIF27(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF27_SHIFT)) & SIUL2_DISR0_EIF27_MASK)

#define SIUL2_DISR0_EIF28_MASK                   (0x10000000U)
#define SIUL2_DISR0_EIF28_SHIFT                  (28U)
/*! EIF28 - External Interrupt Status Flag 28
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER28 and IFEER28 has occurred.
 */
#define SIUL2_DISR0_EIF28(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF28_SHIFT)) & SIUL2_DISR0_EIF28_MASK)

#define SIUL2_DISR0_EIF29_MASK                   (0x20000000U)
#define SIUL2_DISR0_EIF29_SHIFT                  (29U)
/*! EIF29 - External Interrupt Status Flag 29
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER29 and IFEER29 has occurred.
 */
#define SIUL2_DISR0_EIF29(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF29_SHIFT)) & SIUL2_DISR0_EIF29_MASK)

#define SIUL2_DISR0_EIF30_MASK                   (0x40000000U)
#define SIUL2_DISR0_EIF30_SHIFT                  (30U)
/*! EIF30 - External Interrupt Status Flag 30
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER30 and IFEER30 has occurred.
 */
#define SIUL2_DISR0_EIF30(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF30_SHIFT)) & SIUL2_DISR0_EIF30_MASK)

#define SIUL2_DISR0_EIF31_MASK                   (0x80000000U)
#define SIUL2_DISR0_EIF31_SHIFT                  (31U)
/*! EIF31 - External Interrupt Status Flag 31
 *  0b0..No interrupt event has occurred on the pad.
 *  0b1..An interrupt event as defined by IREER31 and IFEER31 has occurred.
 */
#define SIUL2_DISR0_EIF31(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_DISR0_EIF31_SHIFT)) & SIUL2_DISR0_EIF31_MASK)
/*! @} */

/*! @name DIRER0 - SIUL2 DMA/Interrupt Request Enable 0 */
/*! @{ */

#define SIUL2_DIRER0_EIRE0_MASK                  (0x1U)
#define SIUL2_DIRER0_EIRE0_SHIFT                 (0U)
/*! EIRE0 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE0(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE0_SHIFT)) & SIUL2_DIRER0_EIRE0_MASK)

#define SIUL2_DIRER0_EIRE1_MASK                  (0x2U)
#define SIUL2_DIRER0_EIRE1_SHIFT                 (1U)
/*! EIRE1 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE1(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE1_SHIFT)) & SIUL2_DIRER0_EIRE1_MASK)

#define SIUL2_DIRER0_EIRE2_MASK                  (0x4U)
#define SIUL2_DIRER0_EIRE2_SHIFT                 (2U)
/*! EIRE2 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE2(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE2_SHIFT)) & SIUL2_DIRER0_EIRE2_MASK)

#define SIUL2_DIRER0_EIRE3_MASK                  (0x8U)
#define SIUL2_DIRER0_EIRE3_SHIFT                 (3U)
/*! EIRE3 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE3(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE3_SHIFT)) & SIUL2_DIRER0_EIRE3_MASK)

#define SIUL2_DIRER0_EIRE4_MASK                  (0x10U)
#define SIUL2_DIRER0_EIRE4_SHIFT                 (4U)
/*! EIRE4 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE4(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE4_SHIFT)) & SIUL2_DIRER0_EIRE4_MASK)

#define SIUL2_DIRER0_EIRE5_MASK                  (0x20U)
#define SIUL2_DIRER0_EIRE5_SHIFT                 (5U)
/*! EIRE5 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE5(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE5_SHIFT)) & SIUL2_DIRER0_EIRE5_MASK)

#define SIUL2_DIRER0_EIRE6_MASK                  (0x40U)
#define SIUL2_DIRER0_EIRE6_SHIFT                 (6U)
/*! EIRE6 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE6(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE6_SHIFT)) & SIUL2_DIRER0_EIRE6_MASK)

#define SIUL2_DIRER0_EIRE7_MASK                  (0x80U)
#define SIUL2_DIRER0_EIRE7_SHIFT                 (7U)
/*! EIRE7 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE7(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE7_SHIFT)) & SIUL2_DIRER0_EIRE7_MASK)

#define SIUL2_DIRER0_EIRE8_MASK                  (0x100U)
#define SIUL2_DIRER0_EIRE8_SHIFT                 (8U)
/*! EIRE8 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE8(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE8_SHIFT)) & SIUL2_DIRER0_EIRE8_MASK)

#define SIUL2_DIRER0_EIRE9_MASK                  (0x200U)
#define SIUL2_DIRER0_EIRE9_SHIFT                 (9U)
/*! EIRE9 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE9(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE9_SHIFT)) & SIUL2_DIRER0_EIRE9_MASK)

#define SIUL2_DIRER0_EIRE10_MASK                 (0x400U)
#define SIUL2_DIRER0_EIRE10_SHIFT                (10U)
/*! EIRE10 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE10(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE10_SHIFT)) & SIUL2_DIRER0_EIRE10_MASK)

#define SIUL2_DIRER0_EIRE11_MASK                 (0x800U)
#define SIUL2_DIRER0_EIRE11_SHIFT                (11U)
/*! EIRE11 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE11(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE11_SHIFT)) & SIUL2_DIRER0_EIRE11_MASK)

#define SIUL2_DIRER0_EIRE12_MASK                 (0x1000U)
#define SIUL2_DIRER0_EIRE12_SHIFT                (12U)
/*! EIRE12 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE12(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE12_SHIFT)) & SIUL2_DIRER0_EIRE12_MASK)

#define SIUL2_DIRER0_EIRE13_MASK                 (0x2000U)
#define SIUL2_DIRER0_EIRE13_SHIFT                (13U)
/*! EIRE13 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE13(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE13_SHIFT)) & SIUL2_DIRER0_EIRE13_MASK)

#define SIUL2_DIRER0_EIRE14_MASK                 (0x4000U)
#define SIUL2_DIRER0_EIRE14_SHIFT                (14U)
/*! EIRE14 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE14(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE14_SHIFT)) & SIUL2_DIRER0_EIRE14_MASK)

#define SIUL2_DIRER0_EIRE15_MASK                 (0x8000U)
#define SIUL2_DIRER0_EIRE15_SHIFT                (15U)
/*! EIRE15 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE15(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE15_SHIFT)) & SIUL2_DIRER0_EIRE15_MASK)

#define SIUL2_DIRER0_EIRE16_MASK                 (0x10000U)
#define SIUL2_DIRER0_EIRE16_SHIFT                (16U)
/*! EIRE16 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE16(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE16_SHIFT)) & SIUL2_DIRER0_EIRE16_MASK)

#define SIUL2_DIRER0_EIRE17_MASK                 (0x20000U)
#define SIUL2_DIRER0_EIRE17_SHIFT                (17U)
/*! EIRE17 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE17(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE17_SHIFT)) & SIUL2_DIRER0_EIRE17_MASK)

#define SIUL2_DIRER0_EIRE18_MASK                 (0x40000U)
#define SIUL2_DIRER0_EIRE18_SHIFT                (18U)
/*! EIRE18 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE18(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE18_SHIFT)) & SIUL2_DIRER0_EIRE18_MASK)

#define SIUL2_DIRER0_EIRE19_MASK                 (0x80000U)
#define SIUL2_DIRER0_EIRE19_SHIFT                (19U)
/*! EIRE19 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE19(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE19_SHIFT)) & SIUL2_DIRER0_EIRE19_MASK)

#define SIUL2_DIRER0_EIRE20_MASK                 (0x100000U)
#define SIUL2_DIRER0_EIRE20_SHIFT                (20U)
/*! EIRE20 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE20(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE20_SHIFT)) & SIUL2_DIRER0_EIRE20_MASK)

#define SIUL2_DIRER0_EIRE21_MASK                 (0x200000U)
#define SIUL2_DIRER0_EIRE21_SHIFT                (21U)
/*! EIRE21 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE21(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE21_SHIFT)) & SIUL2_DIRER0_EIRE21_MASK)

#define SIUL2_DIRER0_EIRE22_MASK                 (0x400000U)
#define SIUL2_DIRER0_EIRE22_SHIFT                (22U)
/*! EIRE22 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE22(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE22_SHIFT)) & SIUL2_DIRER0_EIRE22_MASK)

#define SIUL2_DIRER0_EIRE23_MASK                 (0x800000U)
#define SIUL2_DIRER0_EIRE23_SHIFT                (23U)
/*! EIRE23 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE23(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE23_SHIFT)) & SIUL2_DIRER0_EIRE23_MASK)

#define SIUL2_DIRER0_EIRE24_MASK                 (0x1000000U)
#define SIUL2_DIRER0_EIRE24_SHIFT                (24U)
/*! EIRE24 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE24(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE24_SHIFT)) & SIUL2_DIRER0_EIRE24_MASK)

#define SIUL2_DIRER0_EIRE25_MASK                 (0x2000000U)
#define SIUL2_DIRER0_EIRE25_SHIFT                (25U)
/*! EIRE25 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE25(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE25_SHIFT)) & SIUL2_DIRER0_EIRE25_MASK)

#define SIUL2_DIRER0_EIRE26_MASK                 (0x4000000U)
#define SIUL2_DIRER0_EIRE26_SHIFT                (26U)
/*! EIRE26 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE26(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE26_SHIFT)) & SIUL2_DIRER0_EIRE26_MASK)

#define SIUL2_DIRER0_EIRE27_MASK                 (0x8000000U)
#define SIUL2_DIRER0_EIRE27_SHIFT                (27U)
/*! EIRE27 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE27(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE27_SHIFT)) & SIUL2_DIRER0_EIRE27_MASK)

#define SIUL2_DIRER0_EIRE28_MASK                 (0x10000000U)
#define SIUL2_DIRER0_EIRE28_SHIFT                (28U)
/*! EIRE28 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE28(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE28_SHIFT)) & SIUL2_DIRER0_EIRE28_MASK)

#define SIUL2_DIRER0_EIRE29_MASK                 (0x20000000U)
#define SIUL2_DIRER0_EIRE29_SHIFT                (29U)
/*! EIRE29 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE29(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE29_SHIFT)) & SIUL2_DIRER0_EIRE29_MASK)

#define SIUL2_DIRER0_EIRE30_MASK                 (0x40000000U)
#define SIUL2_DIRER0_EIRE30_SHIFT                (30U)
/*! EIRE30 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE30(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE30_SHIFT)) & SIUL2_DIRER0_EIRE30_MASK)

#define SIUL2_DIRER0_EIRE31_MASK                 (0x80000000U)
#define SIUL2_DIRER0_EIRE31_SHIFT                (31U)
/*! EIRE31 - External Interrupt Request Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_DIRER0_EIRE31(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRER0_EIRE31_SHIFT)) & SIUL2_DIRER0_EIRE31_MASK)
/*! @} */

/*! @name DIRSR0 - SIUL2 DMA/Interrupt Request Select 0 */
/*! @{ */

#define SIUL2_DIRSR0_DIRSR0_MASK                 (0x1U)
#define SIUL2_DIRSR0_DIRSR0_SHIFT                (0U)
/*! DIRSR0 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR0(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR0_SHIFT)) & SIUL2_DIRSR0_DIRSR0_MASK)

#define SIUL2_DIRSR0_DIRSR1_MASK                 (0x2U)
#define SIUL2_DIRSR0_DIRSR1_SHIFT                (1U)
/*! DIRSR1 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR1(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR1_SHIFT)) & SIUL2_DIRSR0_DIRSR1_MASK)

#define SIUL2_DIRSR0_DIRSR2_MASK                 (0x4U)
#define SIUL2_DIRSR0_DIRSR2_SHIFT                (2U)
/*! DIRSR2 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR2(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR2_SHIFT)) & SIUL2_DIRSR0_DIRSR2_MASK)

#define SIUL2_DIRSR0_DIRSR3_MASK                 (0x8U)
#define SIUL2_DIRSR0_DIRSR3_SHIFT                (3U)
/*! DIRSR3 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR3(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR3_SHIFT)) & SIUL2_DIRSR0_DIRSR3_MASK)

#define SIUL2_DIRSR0_DIRSR4_MASK                 (0x10U)
#define SIUL2_DIRSR0_DIRSR4_SHIFT                (4U)
/*! DIRSR4 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR4(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR4_SHIFT)) & SIUL2_DIRSR0_DIRSR4_MASK)

#define SIUL2_DIRSR0_DIRSR5_MASK                 (0x20U)
#define SIUL2_DIRSR0_DIRSR5_SHIFT                (5U)
/*! DIRSR5 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR5(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR5_SHIFT)) & SIUL2_DIRSR0_DIRSR5_MASK)

#define SIUL2_DIRSR0_DIRSR6_MASK                 (0x40U)
#define SIUL2_DIRSR0_DIRSR6_SHIFT                (6U)
/*! DIRSR6 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR6(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR6_SHIFT)) & SIUL2_DIRSR0_DIRSR6_MASK)

#define SIUL2_DIRSR0_DIRSR7_MASK                 (0x80U)
#define SIUL2_DIRSR0_DIRSR7_SHIFT                (7U)
/*! DIRSR7 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR7(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR7_SHIFT)) & SIUL2_DIRSR0_DIRSR7_MASK)

#define SIUL2_DIRSR0_DIRSR8_MASK                 (0x100U)
#define SIUL2_DIRSR0_DIRSR8_SHIFT                (8U)
/*! DIRSR8 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR8(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR8_SHIFT)) & SIUL2_DIRSR0_DIRSR8_MASK)

#define SIUL2_DIRSR0_DIRSR9_MASK                 (0x200U)
#define SIUL2_DIRSR0_DIRSR9_SHIFT                (9U)
/*! DIRSR9 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR9(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR9_SHIFT)) & SIUL2_DIRSR0_DIRSR9_MASK)

#define SIUL2_DIRSR0_DIRSR10_MASK                (0x400U)
#define SIUL2_DIRSR0_DIRSR10_SHIFT               (10U)
/*! DIRSR10 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR10(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR10_SHIFT)) & SIUL2_DIRSR0_DIRSR10_MASK)

#define SIUL2_DIRSR0_DIRSR11_MASK                (0x800U)
#define SIUL2_DIRSR0_DIRSR11_SHIFT               (11U)
/*! DIRSR11 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR11(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR11_SHIFT)) & SIUL2_DIRSR0_DIRSR11_MASK)

#define SIUL2_DIRSR0_DIRSR12_MASK                (0x1000U)
#define SIUL2_DIRSR0_DIRSR12_SHIFT               (12U)
/*! DIRSR12 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR12(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR12_SHIFT)) & SIUL2_DIRSR0_DIRSR12_MASK)

#define SIUL2_DIRSR0_DIRSR13_MASK                (0x2000U)
#define SIUL2_DIRSR0_DIRSR13_SHIFT               (13U)
/*! DIRSR13 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR13(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR13_SHIFT)) & SIUL2_DIRSR0_DIRSR13_MASK)

#define SIUL2_DIRSR0_DIRSR14_MASK                (0x4000U)
#define SIUL2_DIRSR0_DIRSR14_SHIFT               (14U)
/*! DIRSR14 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR14(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR14_SHIFT)) & SIUL2_DIRSR0_DIRSR14_MASK)

#define SIUL2_DIRSR0_DIRSR15_MASK                (0x8000U)
#define SIUL2_DIRSR0_DIRSR15_SHIFT               (15U)
/*! DIRSR15 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..DMA request
 */
#define SIUL2_DIRSR0_DIRSR15(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR15_SHIFT)) & SIUL2_DIRSR0_DIRSR15_MASK)

#define SIUL2_DIRSR0_DIRSR16_MASK                (0x10000U)
#define SIUL2_DIRSR0_DIRSR16_SHIFT               (16U)
/*! DIRSR16 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR16(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR16_SHIFT)) & SIUL2_DIRSR0_DIRSR16_MASK)

#define SIUL2_DIRSR0_DIRSR17_MASK                (0x20000U)
#define SIUL2_DIRSR0_DIRSR17_SHIFT               (17U)
/*! DIRSR17 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR17(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR17_SHIFT)) & SIUL2_DIRSR0_DIRSR17_MASK)

#define SIUL2_DIRSR0_DIRSR18_MASK                (0x40000U)
#define SIUL2_DIRSR0_DIRSR18_SHIFT               (18U)
/*! DIRSR18 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR18(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR18_SHIFT)) & SIUL2_DIRSR0_DIRSR18_MASK)

#define SIUL2_DIRSR0_DIRSR19_MASK                (0x80000U)
#define SIUL2_DIRSR0_DIRSR19_SHIFT               (19U)
/*! DIRSR19 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR19(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR19_SHIFT)) & SIUL2_DIRSR0_DIRSR19_MASK)

#define SIUL2_DIRSR0_DIRSR20_MASK                (0x100000U)
#define SIUL2_DIRSR0_DIRSR20_SHIFT               (20U)
/*! DIRSR20 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR20(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR20_SHIFT)) & SIUL2_DIRSR0_DIRSR20_MASK)

#define SIUL2_DIRSR0_DIRSR21_MASK                (0x200000U)
#define SIUL2_DIRSR0_DIRSR21_SHIFT               (21U)
/*! DIRSR21 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR21(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR21_SHIFT)) & SIUL2_DIRSR0_DIRSR21_MASK)

#define SIUL2_DIRSR0_DIRSR22_MASK                (0x400000U)
#define SIUL2_DIRSR0_DIRSR22_SHIFT               (22U)
/*! DIRSR22 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR22(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR22_SHIFT)) & SIUL2_DIRSR0_DIRSR22_MASK)

#define SIUL2_DIRSR0_DIRSR23_MASK                (0x800000U)
#define SIUL2_DIRSR0_DIRSR23_SHIFT               (23U)
/*! DIRSR23 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR23(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR23_SHIFT)) & SIUL2_DIRSR0_DIRSR23_MASK)

#define SIUL2_DIRSR0_DIRSR24_MASK                (0x1000000U)
#define SIUL2_DIRSR0_DIRSR24_SHIFT               (24U)
/*! DIRSR24 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR24(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR24_SHIFT)) & SIUL2_DIRSR0_DIRSR24_MASK)

#define SIUL2_DIRSR0_DIRSR25_MASK                (0x2000000U)
#define SIUL2_DIRSR0_DIRSR25_SHIFT               (25U)
/*! DIRSR25 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR25(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR25_SHIFT)) & SIUL2_DIRSR0_DIRSR25_MASK)

#define SIUL2_DIRSR0_DIRSR26_MASK                (0x4000000U)
#define SIUL2_DIRSR0_DIRSR26_SHIFT               (26U)
/*! DIRSR26 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR26(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR26_SHIFT)) & SIUL2_DIRSR0_DIRSR26_MASK)

#define SIUL2_DIRSR0_DIRSR27_MASK                (0x8000000U)
#define SIUL2_DIRSR0_DIRSR27_SHIFT               (27U)
/*! DIRSR27 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR27(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR27_SHIFT)) & SIUL2_DIRSR0_DIRSR27_MASK)

#define SIUL2_DIRSR0_DIRSR28_MASK                (0x10000000U)
#define SIUL2_DIRSR0_DIRSR28_SHIFT               (28U)
/*! DIRSR28 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR28(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR28_SHIFT)) & SIUL2_DIRSR0_DIRSR28_MASK)

#define SIUL2_DIRSR0_DIRSR29_MASK                (0x20000000U)
#define SIUL2_DIRSR0_DIRSR29_SHIFT               (29U)
/*! DIRSR29 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR29(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR29_SHIFT)) & SIUL2_DIRSR0_DIRSR29_MASK)

#define SIUL2_DIRSR0_DIRSR30_MASK                (0x40000000U)
#define SIUL2_DIRSR0_DIRSR30_SHIFT               (30U)
/*! DIRSR30 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR30(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR30_SHIFT)) & SIUL2_DIRSR0_DIRSR30_MASK)

#define SIUL2_DIRSR0_DIRSR31_MASK                (0x80000000U)
#define SIUL2_DIRSR0_DIRSR31_SHIFT               (31U)
/*! DIRSR31 - DMA/Interrupt Request Select Register
 *  0b0..Interrupt request
 *  0b1..Reserved
 */
#define SIUL2_DIRSR0_DIRSR31(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_DIRSR0_DIRSR31_SHIFT)) & SIUL2_DIRSR0_DIRSR31_MASK)
/*! @} */

/*! @name IREER0 - SIUL2 Interrupt Rising-Edge Event Enable 0 */
/*! @{ */

#define SIUL2_IREER0_IREE0_MASK                  (0x1U)
#define SIUL2_IREER0_IREE0_SHIFT                 (0U)
/*! IREE0 - Enables rising-edge events to set DISR0[EIF0].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE0(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE0_SHIFT)) & SIUL2_IREER0_IREE0_MASK)

#define SIUL2_IREER0_IREE1_MASK                  (0x2U)
#define SIUL2_IREER0_IREE1_SHIFT                 (1U)
/*! IREE1 - Enables rising-edge events to set DISR0[EIF1].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE1(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE1_SHIFT)) & SIUL2_IREER0_IREE1_MASK)

#define SIUL2_IREER0_IREE2_MASK                  (0x4U)
#define SIUL2_IREER0_IREE2_SHIFT                 (2U)
/*! IREE2 - Enables rising-edge events to set DISR0[EIF2].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE2(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE2_SHIFT)) & SIUL2_IREER0_IREE2_MASK)

#define SIUL2_IREER0_IREE3_MASK                  (0x8U)
#define SIUL2_IREER0_IREE3_SHIFT                 (3U)
/*! IREE3 - Enables rising-edge events to set DISR0[EIF3].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE3(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE3_SHIFT)) & SIUL2_IREER0_IREE3_MASK)

#define SIUL2_IREER0_IREE4_MASK                  (0x10U)
#define SIUL2_IREER0_IREE4_SHIFT                 (4U)
/*! IREE4 - Enables rising-edge events to set DISR0[EIF4].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE4(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE4_SHIFT)) & SIUL2_IREER0_IREE4_MASK)

#define SIUL2_IREER0_IREE5_MASK                  (0x20U)
#define SIUL2_IREER0_IREE5_SHIFT                 (5U)
/*! IREE5 - Enables rising-edge events to set DISR0[EIF5].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE5(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE5_SHIFT)) & SIUL2_IREER0_IREE5_MASK)

#define SIUL2_IREER0_IREE6_MASK                  (0x40U)
#define SIUL2_IREER0_IREE6_SHIFT                 (6U)
/*! IREE6 - Enables rising-edge events to set DISR0[EIF6].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE6(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE6_SHIFT)) & SIUL2_IREER0_IREE6_MASK)

#define SIUL2_IREER0_IREE7_MASK                  (0x80U)
#define SIUL2_IREER0_IREE7_SHIFT                 (7U)
/*! IREE7 - Enables rising-edge events to set DISR0[EIF7].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE7(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE7_SHIFT)) & SIUL2_IREER0_IREE7_MASK)

#define SIUL2_IREER0_IREE8_MASK                  (0x100U)
#define SIUL2_IREER0_IREE8_SHIFT                 (8U)
/*! IREE8 - Enables rising-edge events to set DISR0[EIF8].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE8(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE8_SHIFT)) & SIUL2_IREER0_IREE8_MASK)

#define SIUL2_IREER0_IREE9_MASK                  (0x200U)
#define SIUL2_IREER0_IREE9_SHIFT                 (9U)
/*! IREE9 - Enables rising-edge events to set DISR0[EIF9].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE9(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE9_SHIFT)) & SIUL2_IREER0_IREE9_MASK)

#define SIUL2_IREER0_IREE10_MASK                 (0x400U)
#define SIUL2_IREER0_IREE10_SHIFT                (10U)
/*! IREE10 - Enables rising-edge events to set DISR0[EIF10].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE10(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE10_SHIFT)) & SIUL2_IREER0_IREE10_MASK)

#define SIUL2_IREER0_IREE11_MASK                 (0x800U)
#define SIUL2_IREER0_IREE11_SHIFT                (11U)
/*! IREE11 - Enables rising-edge events to set DISR0[EIF11].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE11(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE11_SHIFT)) & SIUL2_IREER0_IREE11_MASK)

#define SIUL2_IREER0_IREE12_MASK                 (0x1000U)
#define SIUL2_IREER0_IREE12_SHIFT                (12U)
/*! IREE12 - Enables rising-edge events to set DISR0[EIF12].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE12(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE12_SHIFT)) & SIUL2_IREER0_IREE12_MASK)

#define SIUL2_IREER0_IREE13_MASK                 (0x2000U)
#define SIUL2_IREER0_IREE13_SHIFT                (13U)
/*! IREE13 - Enables rising-edge events to set DISR0[EIF13].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE13(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE13_SHIFT)) & SIUL2_IREER0_IREE13_MASK)

#define SIUL2_IREER0_IREE14_MASK                 (0x4000U)
#define SIUL2_IREER0_IREE14_SHIFT                (14U)
/*! IREE14 - Enables rising-edge events to set DISR0[EIF14].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE14(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE14_SHIFT)) & SIUL2_IREER0_IREE14_MASK)

#define SIUL2_IREER0_IREE15_MASK                 (0x8000U)
#define SIUL2_IREER0_IREE15_SHIFT                (15U)
/*! IREE15 - Enables rising-edge events to set DISR0[EIF15].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE15(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE15_SHIFT)) & SIUL2_IREER0_IREE15_MASK)

#define SIUL2_IREER0_IREE16_MASK                 (0x10000U)
#define SIUL2_IREER0_IREE16_SHIFT                (16U)
/*! IREE16 - Enables rising-edge events to set DISR0[EIF16].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE16(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE16_SHIFT)) & SIUL2_IREER0_IREE16_MASK)

#define SIUL2_IREER0_IREE17_MASK                 (0x20000U)
#define SIUL2_IREER0_IREE17_SHIFT                (17U)
/*! IREE17 - Enables rising-edge events to set DISR0[EIF17].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE17(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE17_SHIFT)) & SIUL2_IREER0_IREE17_MASK)

#define SIUL2_IREER0_IREE18_MASK                 (0x40000U)
#define SIUL2_IREER0_IREE18_SHIFT                (18U)
/*! IREE18 - Enables rising-edge events to set DISR0[EIF18].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE18(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE18_SHIFT)) & SIUL2_IREER0_IREE18_MASK)

#define SIUL2_IREER0_IREE19_MASK                 (0x80000U)
#define SIUL2_IREER0_IREE19_SHIFT                (19U)
/*! IREE19 - Enables rising-edge events to set DISR0[EIF19].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE19(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE19_SHIFT)) & SIUL2_IREER0_IREE19_MASK)

#define SIUL2_IREER0_IREE20_MASK                 (0x100000U)
#define SIUL2_IREER0_IREE20_SHIFT                (20U)
/*! IREE20 - Enables rising-edge events to set DISR0[EIF20].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE20(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE20_SHIFT)) & SIUL2_IREER0_IREE20_MASK)

#define SIUL2_IREER0_IREE21_MASK                 (0x200000U)
#define SIUL2_IREER0_IREE21_SHIFT                (21U)
/*! IREE21 - Enables rising-edge events to set DISR0[EIF21].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE21(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE21_SHIFT)) & SIUL2_IREER0_IREE21_MASK)

#define SIUL2_IREER0_IREE22_MASK                 (0x400000U)
#define SIUL2_IREER0_IREE22_SHIFT                (22U)
/*! IREE22 - Enables rising-edge events to set DISR0[EIF22].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE22(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE22_SHIFT)) & SIUL2_IREER0_IREE22_MASK)

#define SIUL2_IREER0_IREE23_MASK                 (0x800000U)
#define SIUL2_IREER0_IREE23_SHIFT                (23U)
/*! IREE23 - Enables rising-edge events to set DISR0[EIF23].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE23(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE23_SHIFT)) & SIUL2_IREER0_IREE23_MASK)

#define SIUL2_IREER0_IREE24_MASK                 (0x1000000U)
#define SIUL2_IREER0_IREE24_SHIFT                (24U)
/*! IREE24 - Enables rising-edge events to set DISR0[EIF24].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE24(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE24_SHIFT)) & SIUL2_IREER0_IREE24_MASK)

#define SIUL2_IREER0_IREE25_MASK                 (0x2000000U)
#define SIUL2_IREER0_IREE25_SHIFT                (25U)
/*! IREE25 - Enables rising-edge events to set DISR0[EIF25].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE25(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE25_SHIFT)) & SIUL2_IREER0_IREE25_MASK)

#define SIUL2_IREER0_IREE26_MASK                 (0x4000000U)
#define SIUL2_IREER0_IREE26_SHIFT                (26U)
/*! IREE26 - Enables rising-edge events to set DISR0[EIF26].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE26(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE26_SHIFT)) & SIUL2_IREER0_IREE26_MASK)

#define SIUL2_IREER0_IREE27_MASK                 (0x8000000U)
#define SIUL2_IREER0_IREE27_SHIFT                (27U)
/*! IREE27 - Enables rising-edge events to set DISR0[EIF27].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE27(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE27_SHIFT)) & SIUL2_IREER0_IREE27_MASK)

#define SIUL2_IREER0_IREE28_MASK                 (0x10000000U)
#define SIUL2_IREER0_IREE28_SHIFT                (28U)
/*! IREE28 - Enables rising-edge events to set DISR0[EIF28].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE28(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE28_SHIFT)) & SIUL2_IREER0_IREE28_MASK)

#define SIUL2_IREER0_IREE29_MASK                 (0x20000000U)
#define SIUL2_IREER0_IREE29_SHIFT                (29U)
/*! IREE29 - Enables rising-edge events to set DISR0[EIF29].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE29(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE29_SHIFT)) & SIUL2_IREER0_IREE29_MASK)

#define SIUL2_IREER0_IREE30_MASK                 (0x40000000U)
#define SIUL2_IREER0_IREE30_SHIFT                (30U)
/*! IREE30 - Enables rising-edge events to set DISR0[EIF30].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE30(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE30_SHIFT)) & SIUL2_IREER0_IREE30_MASK)

#define SIUL2_IREER0_IREE31_MASK                 (0x80000000U)
#define SIUL2_IREER0_IREE31_SHIFT                (31U)
/*! IREE31 - Enables rising-edge events to set DISR0[EIF31].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IREER0_IREE31(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IREER0_IREE31_SHIFT)) & SIUL2_IREER0_IREE31_MASK)
/*! @} */

/*! @name IFEER0 - SIUL2 Interrupt Falling-Edge Event Enable 0 */
/*! @{ */

#define SIUL2_IFEER0_IFEE0_MASK                  (0x1U)
#define SIUL2_IFEER0_IFEE0_SHIFT                 (0U)
/*! IFEE0 - Enables falling-edge events to set DISR0[EIF0].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE0(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE0_SHIFT)) & SIUL2_IFEER0_IFEE0_MASK)

#define SIUL2_IFEER0_IFEE1_MASK                  (0x2U)
#define SIUL2_IFEER0_IFEE1_SHIFT                 (1U)
/*! IFEE1 - Enables falling-edge events to set DISR0[EIF1].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE1(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE1_SHIFT)) & SIUL2_IFEER0_IFEE1_MASK)

#define SIUL2_IFEER0_IFEE2_MASK                  (0x4U)
#define SIUL2_IFEER0_IFEE2_SHIFT                 (2U)
/*! IFEE2 - Enables falling-edge events to set DISR0[EIF2].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE2(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE2_SHIFT)) & SIUL2_IFEER0_IFEE2_MASK)

#define SIUL2_IFEER0_IFEE3_MASK                  (0x8U)
#define SIUL2_IFEER0_IFEE3_SHIFT                 (3U)
/*! IFEE3 - Enables falling-edge events to set DISR0[EIF3].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE3(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE3_SHIFT)) & SIUL2_IFEER0_IFEE3_MASK)

#define SIUL2_IFEER0_IFEE4_MASK                  (0x10U)
#define SIUL2_IFEER0_IFEE4_SHIFT                 (4U)
/*! IFEE4 - Enables falling-edge events to set DISR0[EIF4].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE4(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE4_SHIFT)) & SIUL2_IFEER0_IFEE4_MASK)

#define SIUL2_IFEER0_IFEE5_MASK                  (0x20U)
#define SIUL2_IFEER0_IFEE5_SHIFT                 (5U)
/*! IFEE5 - Enables falling-edge events to set DISR0[EIF5].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE5(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE5_SHIFT)) & SIUL2_IFEER0_IFEE5_MASK)

#define SIUL2_IFEER0_IFEE6_MASK                  (0x40U)
#define SIUL2_IFEER0_IFEE6_SHIFT                 (6U)
/*! IFEE6 - Enables falling-edge events to set DISR0[EIF6].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE6(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE6_SHIFT)) & SIUL2_IFEER0_IFEE6_MASK)

#define SIUL2_IFEER0_IFEE7_MASK                  (0x80U)
#define SIUL2_IFEER0_IFEE7_SHIFT                 (7U)
/*! IFEE7 - Enables falling-edge events to set DISR0[EIF7].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE7(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE7_SHIFT)) & SIUL2_IFEER0_IFEE7_MASK)

#define SIUL2_IFEER0_IFEE8_MASK                  (0x100U)
#define SIUL2_IFEER0_IFEE8_SHIFT                 (8U)
/*! IFEE8 - Enables falling-edge events to set DISR0[EIF8].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE8(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE8_SHIFT)) & SIUL2_IFEER0_IFEE8_MASK)

#define SIUL2_IFEER0_IFEE9_MASK                  (0x200U)
#define SIUL2_IFEER0_IFEE9_SHIFT                 (9U)
/*! IFEE9 - Enables falling-edge events to set DISR0[EIF9].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE9(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE9_SHIFT)) & SIUL2_IFEER0_IFEE9_MASK)

#define SIUL2_IFEER0_IFEE10_MASK                 (0x400U)
#define SIUL2_IFEER0_IFEE10_SHIFT                (10U)
/*! IFEE10 - Enables falling-edge events to set DISR0[EIF10].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE10(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE10_SHIFT)) & SIUL2_IFEER0_IFEE10_MASK)

#define SIUL2_IFEER0_IFEE11_MASK                 (0x800U)
#define SIUL2_IFEER0_IFEE11_SHIFT                (11U)
/*! IFEE11 - Enables falling-edge events to set DISR0[EIF11].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE11(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE11_SHIFT)) & SIUL2_IFEER0_IFEE11_MASK)

#define SIUL2_IFEER0_IFEE12_MASK                 (0x1000U)
#define SIUL2_IFEER0_IFEE12_SHIFT                (12U)
/*! IFEE12 - Enables falling-edge events to set DISR0[EIF12].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE12(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE12_SHIFT)) & SIUL2_IFEER0_IFEE12_MASK)

#define SIUL2_IFEER0_IFEE13_MASK                 (0x2000U)
#define SIUL2_IFEER0_IFEE13_SHIFT                (13U)
/*! IFEE13 - Enables falling-edge events to set DISR0[EIF13].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE13(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE13_SHIFT)) & SIUL2_IFEER0_IFEE13_MASK)

#define SIUL2_IFEER0_IFEE14_MASK                 (0x4000U)
#define SIUL2_IFEER0_IFEE14_SHIFT                (14U)
/*! IFEE14 - Enables falling-edge events to set DISR0[EIF14].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE14(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE14_SHIFT)) & SIUL2_IFEER0_IFEE14_MASK)

#define SIUL2_IFEER0_IFEE15_MASK                 (0x8000U)
#define SIUL2_IFEER0_IFEE15_SHIFT                (15U)
/*! IFEE15 - Enables falling-edge events to set DISR0[EIF15].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE15(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE15_SHIFT)) & SIUL2_IFEER0_IFEE15_MASK)

#define SIUL2_IFEER0_IFEE16_MASK                 (0x10000U)
#define SIUL2_IFEER0_IFEE16_SHIFT                (16U)
/*! IFEE16 - Enables falling-edge events to set DISR0[EIF16].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE16(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE16_SHIFT)) & SIUL2_IFEER0_IFEE16_MASK)

#define SIUL2_IFEER0_IFEE17_MASK                 (0x20000U)
#define SIUL2_IFEER0_IFEE17_SHIFT                (17U)
/*! IFEE17 - Enables falling-edge events to set DISR0[EIF17].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE17(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE17_SHIFT)) & SIUL2_IFEER0_IFEE17_MASK)

#define SIUL2_IFEER0_IFEE18_MASK                 (0x40000U)
#define SIUL2_IFEER0_IFEE18_SHIFT                (18U)
/*! IFEE18 - Enables falling-edge events to set DISR0[EIF18].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE18(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE18_SHIFT)) & SIUL2_IFEER0_IFEE18_MASK)

#define SIUL2_IFEER0_IFEE19_MASK                 (0x80000U)
#define SIUL2_IFEER0_IFEE19_SHIFT                (19U)
/*! IFEE19 - Enables falling-edge events to set DISR0[EIF19].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE19(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE19_SHIFT)) & SIUL2_IFEER0_IFEE19_MASK)

#define SIUL2_IFEER0_IFEE20_MASK                 (0x100000U)
#define SIUL2_IFEER0_IFEE20_SHIFT                (20U)
/*! IFEE20 - Enables falling-edge events to set DISR0[EIF20].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE20(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE20_SHIFT)) & SIUL2_IFEER0_IFEE20_MASK)

#define SIUL2_IFEER0_IFEE21_MASK                 (0x200000U)
#define SIUL2_IFEER0_IFEE21_SHIFT                (21U)
/*! IFEE21 - Enables falling-edge events to set DISR0[EIF21].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE21(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE21_SHIFT)) & SIUL2_IFEER0_IFEE21_MASK)

#define SIUL2_IFEER0_IFEE22_MASK                 (0x400000U)
#define SIUL2_IFEER0_IFEE22_SHIFT                (22U)
/*! IFEE22 - Enables falling-edge events to set DISR0[EIF22].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE22(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE22_SHIFT)) & SIUL2_IFEER0_IFEE22_MASK)

#define SIUL2_IFEER0_IFEE23_MASK                 (0x800000U)
#define SIUL2_IFEER0_IFEE23_SHIFT                (23U)
/*! IFEE23 - Enables falling-edge events to set DISR0[EIF23].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE23(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE23_SHIFT)) & SIUL2_IFEER0_IFEE23_MASK)

#define SIUL2_IFEER0_IFEE24_MASK                 (0x1000000U)
#define SIUL2_IFEER0_IFEE24_SHIFT                (24U)
/*! IFEE24 - Enables falling-edge events to set DISR0[EIF24].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE24(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE24_SHIFT)) & SIUL2_IFEER0_IFEE24_MASK)

#define SIUL2_IFEER0_IFEE25_MASK                 (0x2000000U)
#define SIUL2_IFEER0_IFEE25_SHIFT                (25U)
/*! IFEE25 - Enables falling-edge events to set DISR0[EIF25].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE25(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE25_SHIFT)) & SIUL2_IFEER0_IFEE25_MASK)

#define SIUL2_IFEER0_IFEE26_MASK                 (0x4000000U)
#define SIUL2_IFEER0_IFEE26_SHIFT                (26U)
/*! IFEE26 - Enables falling-edge events to set DISR0[EIF26].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE26(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE26_SHIFT)) & SIUL2_IFEER0_IFEE26_MASK)

#define SIUL2_IFEER0_IFEE27_MASK                 (0x8000000U)
#define SIUL2_IFEER0_IFEE27_SHIFT                (27U)
/*! IFEE27 - Enables falling-edge events to set DISR0[EIF27].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE27(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE27_SHIFT)) & SIUL2_IFEER0_IFEE27_MASK)

#define SIUL2_IFEER0_IFEE28_MASK                 (0x10000000U)
#define SIUL2_IFEER0_IFEE28_SHIFT                (28U)
/*! IFEE28 - Enables falling-edge events to set DISR0[EIF28].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE28(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE28_SHIFT)) & SIUL2_IFEER0_IFEE28_MASK)

#define SIUL2_IFEER0_IFEE29_MASK                 (0x20000000U)
#define SIUL2_IFEER0_IFEE29_SHIFT                (29U)
/*! IFEE29 - Enables falling-edge events to set DISR0[EIF29].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE29(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE29_SHIFT)) & SIUL2_IFEER0_IFEE29_MASK)

#define SIUL2_IFEER0_IFEE30_MASK                 (0x40000000U)
#define SIUL2_IFEER0_IFEE30_SHIFT                (30U)
/*! IFEE30 - Enables falling-edge events to set DISR0[EIF30].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE30(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE30_SHIFT)) & SIUL2_IFEER0_IFEE30_MASK)

#define SIUL2_IFEER0_IFEE31_MASK                 (0x80000000U)
#define SIUL2_IFEER0_IFEE31_SHIFT                (31U)
/*! IFEE31 - Enables falling-edge events to set DISR0[EIF31].
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFEER0_IFEE31(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_IFEER0_IFEE31_SHIFT)) & SIUL2_IFEER0_IFEE31_MASK)
/*! @} */

/*! @name IFER0 - SIUL2 Interrupt Filter Enable 0 */
/*! @{ */

#define SIUL2_IFER0_IFE0_MASK                    (0x1U)
#define SIUL2_IFER0_IFE0_SHIFT                   (0U)
/*! IFE0 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE0(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE0_SHIFT)) & SIUL2_IFER0_IFE0_MASK)

#define SIUL2_IFER0_IFE1_MASK                    (0x2U)
#define SIUL2_IFER0_IFE1_SHIFT                   (1U)
/*! IFE1 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE1(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE1_SHIFT)) & SIUL2_IFER0_IFE1_MASK)

#define SIUL2_IFER0_IFE2_MASK                    (0x4U)
#define SIUL2_IFER0_IFE2_SHIFT                   (2U)
/*! IFE2 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE2(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE2_SHIFT)) & SIUL2_IFER0_IFE2_MASK)

#define SIUL2_IFER0_IFE3_MASK                    (0x8U)
#define SIUL2_IFER0_IFE3_SHIFT                   (3U)
/*! IFE3 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE3(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE3_SHIFT)) & SIUL2_IFER0_IFE3_MASK)

#define SIUL2_IFER0_IFE4_MASK                    (0x10U)
#define SIUL2_IFER0_IFE4_SHIFT                   (4U)
/*! IFE4 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE4(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE4_SHIFT)) & SIUL2_IFER0_IFE4_MASK)

#define SIUL2_IFER0_IFE5_MASK                    (0x20U)
#define SIUL2_IFER0_IFE5_SHIFT                   (5U)
/*! IFE5 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE5(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE5_SHIFT)) & SIUL2_IFER0_IFE5_MASK)

#define SIUL2_IFER0_IFE6_MASK                    (0x40U)
#define SIUL2_IFER0_IFE6_SHIFT                   (6U)
/*! IFE6 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE6(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE6_SHIFT)) & SIUL2_IFER0_IFE6_MASK)

#define SIUL2_IFER0_IFE7_MASK                    (0x80U)
#define SIUL2_IFER0_IFE7_SHIFT                   (7U)
/*! IFE7 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE7(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE7_SHIFT)) & SIUL2_IFER0_IFE7_MASK)

#define SIUL2_IFER0_IFE8_MASK                    (0x100U)
#define SIUL2_IFER0_IFE8_SHIFT                   (8U)
/*! IFE8 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE8(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE8_SHIFT)) & SIUL2_IFER0_IFE8_MASK)

#define SIUL2_IFER0_IFE9_MASK                    (0x200U)
#define SIUL2_IFER0_IFE9_SHIFT                   (9U)
/*! IFE9 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE9(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE9_SHIFT)) & SIUL2_IFER0_IFE9_MASK)

#define SIUL2_IFER0_IFE10_MASK                   (0x400U)
#define SIUL2_IFER0_IFE10_SHIFT                  (10U)
/*! IFE10 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE10(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE10_SHIFT)) & SIUL2_IFER0_IFE10_MASK)

#define SIUL2_IFER0_IFE11_MASK                   (0x800U)
#define SIUL2_IFER0_IFE11_SHIFT                  (11U)
/*! IFE11 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE11(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE11_SHIFT)) & SIUL2_IFER0_IFE11_MASK)

#define SIUL2_IFER0_IFE12_MASK                   (0x1000U)
#define SIUL2_IFER0_IFE12_SHIFT                  (12U)
/*! IFE12 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE12(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE12_SHIFT)) & SIUL2_IFER0_IFE12_MASK)

#define SIUL2_IFER0_IFE13_MASK                   (0x2000U)
#define SIUL2_IFER0_IFE13_SHIFT                  (13U)
/*! IFE13 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE13(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE13_SHIFT)) & SIUL2_IFER0_IFE13_MASK)

#define SIUL2_IFER0_IFE14_MASK                   (0x4000U)
#define SIUL2_IFER0_IFE14_SHIFT                  (14U)
/*! IFE14 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE14(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE14_SHIFT)) & SIUL2_IFER0_IFE14_MASK)

#define SIUL2_IFER0_IFE15_MASK                   (0x8000U)
#define SIUL2_IFER0_IFE15_SHIFT                  (15U)
/*! IFE15 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE15(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE15_SHIFT)) & SIUL2_IFER0_IFE15_MASK)

#define SIUL2_IFER0_IFE16_MASK                   (0x10000U)
#define SIUL2_IFER0_IFE16_SHIFT                  (16U)
/*! IFE16 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE16(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE16_SHIFT)) & SIUL2_IFER0_IFE16_MASK)

#define SIUL2_IFER0_IFE17_MASK                   (0x20000U)
#define SIUL2_IFER0_IFE17_SHIFT                  (17U)
/*! IFE17 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE17(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE17_SHIFT)) & SIUL2_IFER0_IFE17_MASK)

#define SIUL2_IFER0_IFE18_MASK                   (0x40000U)
#define SIUL2_IFER0_IFE18_SHIFT                  (18U)
/*! IFE18 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE18(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE18_SHIFT)) & SIUL2_IFER0_IFE18_MASK)

#define SIUL2_IFER0_IFE19_MASK                   (0x80000U)
#define SIUL2_IFER0_IFE19_SHIFT                  (19U)
/*! IFE19 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE19(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE19_SHIFT)) & SIUL2_IFER0_IFE19_MASK)

#define SIUL2_IFER0_IFE20_MASK                   (0x100000U)
#define SIUL2_IFER0_IFE20_SHIFT                  (20U)
/*! IFE20 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE20(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE20_SHIFT)) & SIUL2_IFER0_IFE20_MASK)

#define SIUL2_IFER0_IFE21_MASK                   (0x200000U)
#define SIUL2_IFER0_IFE21_SHIFT                  (21U)
/*! IFE21 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE21(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE21_SHIFT)) & SIUL2_IFER0_IFE21_MASK)

#define SIUL2_IFER0_IFE22_MASK                   (0x400000U)
#define SIUL2_IFER0_IFE22_SHIFT                  (22U)
/*! IFE22 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE22(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE22_SHIFT)) & SIUL2_IFER0_IFE22_MASK)

#define SIUL2_IFER0_IFE23_MASK                   (0x800000U)
#define SIUL2_IFER0_IFE23_SHIFT                  (23U)
/*! IFE23 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE23(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE23_SHIFT)) & SIUL2_IFER0_IFE23_MASK)

#define SIUL2_IFER0_IFE24_MASK                   (0x1000000U)
#define SIUL2_IFER0_IFE24_SHIFT                  (24U)
/*! IFE24 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE24(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE24_SHIFT)) & SIUL2_IFER0_IFE24_MASK)

#define SIUL2_IFER0_IFE25_MASK                   (0x2000000U)
#define SIUL2_IFER0_IFE25_SHIFT                  (25U)
/*! IFE25 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE25(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE25_SHIFT)) & SIUL2_IFER0_IFE25_MASK)

#define SIUL2_IFER0_IFE26_MASK                   (0x4000000U)
#define SIUL2_IFER0_IFE26_SHIFT                  (26U)
/*! IFE26 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE26(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE26_SHIFT)) & SIUL2_IFER0_IFE26_MASK)

#define SIUL2_IFER0_IFE27_MASK                   (0x8000000U)
#define SIUL2_IFER0_IFE27_SHIFT                  (27U)
/*! IFE27 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE27(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE27_SHIFT)) & SIUL2_IFER0_IFE27_MASK)

#define SIUL2_IFER0_IFE28_MASK                   (0x10000000U)
#define SIUL2_IFER0_IFE28_SHIFT                  (28U)
/*! IFE28 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE28(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE28_SHIFT)) & SIUL2_IFER0_IFE28_MASK)

#define SIUL2_IFER0_IFE29_MASK                   (0x20000000U)
#define SIUL2_IFER0_IFE29_SHIFT                  (29U)
/*! IFE29 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE29(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE29_SHIFT)) & SIUL2_IFER0_IFE29_MASK)

#define SIUL2_IFER0_IFE30_MASK                   (0x40000000U)
#define SIUL2_IFER0_IFE30_SHIFT                  (30U)
/*! IFE30 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE30(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE30_SHIFT)) & SIUL2_IFER0_IFE30_MASK)

#define SIUL2_IFER0_IFE31_MASK                   (0x80000000U)
#define SIUL2_IFER0_IFE31_SHIFT                  (31U)
/*! IFE31 - Enables digital glitch filter on the interrupt pad input.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_IFER0_IFE31(x)                     (((uint32_t)(((uint32_t)(x)) << SIUL2_IFER0_IFE31_SHIFT)) & SIUL2_IFER0_IFE31_MASK)
/*! @} */

/*! @name IFMCR - SIUL2 Interrupt Filter Maximum Counter */
/*! @{ */

#define SIUL2_IFMCR_MAXCNT_MASK                  (0xFU)
#define SIUL2_IFMCR_MAXCNT_SHIFT                 (0U)
/*! MAXCNT - Maximum Interrupt Filter Counter setting */
#define SIUL2_IFMCR_MAXCNT(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_IFMCR_MAXCNT_SHIFT)) & SIUL2_IFMCR_MAXCNT_MASK)
/*! @} */

/*! @name IFCPR - SIUL2 Interrupt Filter Clock Prescaler */
/*! @{ */

#define SIUL2_IFCPR_IFCP_MASK                    (0xFU)
#define SIUL2_IFCPR_IFCP_SHIFT                   (0U)
/*! IFCP - Interrupt Filter Clock Prescaler setting */
#define SIUL2_IFCPR_IFCP(x)                      (((uint32_t)(((uint32_t)(x)) << SIUL2_IFCPR_IFCP_SHIFT)) & SIUL2_IFCPR_IFCP_MASK)
/*! @} */

/*! @name MUX0_EMIOS_EN1 - MUX0 EMIOS ENABLE 1 */
/*! @{ */

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG16_EN_MASK  (0x1U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG16_EN_SHIFT (0U)
/*! EMIOSFLG16_EN - EMIOS0 Output Flag 16 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG16_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG16_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG16_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG17_EN_MASK  (0x2U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG17_EN_SHIFT (1U)
/*! EMIOSFLG17_EN - EMIOS0 Output Flag 17 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG17_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG17_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG17_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG18_EN_MASK  (0x4U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG18_EN_SHIFT (2U)
/*! EMIOSFLG18_EN - EMIOS0 Output Flag 18 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG18_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG18_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG18_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG19_EN_MASK  (0x8U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG19_EN_SHIFT (3U)
/*! EMIOSFLG19_EN - EMIOS0 Output Flag 19 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG19_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG19_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG19_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG20_EN_MASK  (0x10U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG20_EN_SHIFT (4U)
/*! EMIOSFLG20_EN - EMIOS0 Output Flag 20 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG20_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG20_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG20_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG21_EN_MASK  (0x20U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG21_EN_SHIFT (5U)
/*! EMIOSFLG21_EN - EMIOS0 Output Flag 21 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG21_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG21_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG21_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG22_EN_MASK  (0x40U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG22_EN_SHIFT (6U)
/*! EMIOSFLG22_EN - EMIOS0 Output Flag 22 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG22_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG22_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG22_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG23_EN_MASK  (0x80U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG23_EN_SHIFT (7U)
/*! EMIOSFLG23_EN - EMIOS0 Output Flag 23 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG23_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG23_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG23_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG0_EN_MASK   (0x10000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG0_EN_SHIFT  (16U)
/*! EMIOSFLG0_EN - EMIOS0 Output Flag 0 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG0_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG0_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG0_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG1_EN_MASK   (0x20000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG1_EN_SHIFT  (17U)
/*! EMIOSFLG1_EN - EMIOS0 Output Flag 1 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG1_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG1_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG1_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG2_EN_MASK   (0x40000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG2_EN_SHIFT  (18U)
/*! EMIOSFLG2_EN - EMIOS0 Output Flag 2 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG2_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG2_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG2_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG3_EN_MASK   (0x80000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG3_EN_SHIFT  (19U)
/*! EMIOSFLG3_EN - EMIOS0 Output Flag 3 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG3_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG3_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG3_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG4_EN_MASK   (0x100000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG4_EN_SHIFT  (20U)
/*! EMIOSFLG4_EN - EMIOS0 Output Flag 4 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG4_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG4_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG4_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG5_EN_MASK   (0x200000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG5_EN_SHIFT  (21U)
/*! EMIOSFLG5_EN - EMIOS0 Output Flag 5 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG5_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG5_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG5_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG6_EN_MASK   (0x400000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG6_EN_SHIFT  (22U)
/*! EMIOSFLG6_EN - EMIOS0 Output Flag 6 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG6_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG6_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG6_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG7_EN_MASK   (0x800000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG7_EN_SHIFT  (23U)
/*! EMIOSFLG7_EN - EMIOS0 Output Flag 7 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG7_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG7_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG7_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG8_EN_MASK   (0x1000000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG8_EN_SHIFT  (24U)
/*! EMIOSFLG8_EN - EMIOS0 Output Flag 8 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG8_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG8_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG8_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG9_EN_MASK   (0x2000000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG9_EN_SHIFT  (25U)
/*! EMIOSFLG9_EN - EMIOS0 Output Flag 9 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG9_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG9_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG9_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG10_EN_MASK  (0x4000000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG10_EN_SHIFT (26U)
/*! EMIOSFLG10_EN - EMIOS0 Output Flag 10 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG10_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG10_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG10_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG11_EN_MASK  (0x8000000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG11_EN_SHIFT (27U)
/*! EMIOSFLG11_EN - EMIOS0 Output Flag 11 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG11_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG11_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG11_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG12_EN_MASK  (0x10000000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG12_EN_SHIFT (28U)
/*! EMIOSFLG12_EN - EMIOS0 Output Flag 12 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG12_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG12_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG12_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG13_EN_MASK  (0x20000000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG13_EN_SHIFT (29U)
/*! EMIOSFLG13_EN - EMIOS0 Output Flag 13 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG13_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG13_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG13_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG14_EN_MASK  (0x40000000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG14_EN_SHIFT (30U)
/*! EMIOSFLG14_EN - EMIOS0 Output Flag 14 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG14_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG14_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG14_EN_MASK)

#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG15_EN_MASK  (0x80000000U)
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG15_EN_SHIFT (31U)
/*! EMIOSFLG15_EN - EMIOS0 Output Flag 15 Monitor Enable */
#define SIUL2_MUX0_EMIOS_EN1_EMIOSFLG15_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_EMIOS_EN1_EMIOSFLG15_EN_SHIFT)) & SIUL2_MUX0_EMIOS_EN1_EMIOSFLG15_EN_MASK)
/*! @} */

/*! @name MUX0_MISC_EN - MUX0 MISC ENABLE */
/*! @{ */

#define SIUL2_MUX0_MISC_EN_ADC0EOC_EN_MASK       (0x1U)
#define SIUL2_MUX0_MISC_EN_ADC0EOC_EN_SHIFT      (0U)
/*! ADC0EOC_EN - ADC0 End of Conversion Trigger Monitor */
#define SIUL2_MUX0_MISC_EN_ADC0EOC_EN(x)         (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_ADC0EOC_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_ADC0EOC_EN_MASK)

#define SIUL2_MUX0_MISC_EN_ADC1EOC_EN_MASK       (0x2U)
#define SIUL2_MUX0_MISC_EN_ADC1EOC_EN_SHIFT      (1U)
/*! ADC1EOC_EN - ADC1 End of Conversion Trigger Monitor */
#define SIUL2_MUX0_MISC_EN_ADC1EOC_EN(x)         (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_ADC1EOC_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_ADC1EOC_EN_MASK)

#define SIUL2_MUX0_MISC_EN_LPUART0TRG_EN_MASK    (0x100U)
#define SIUL2_MUX0_MISC_EN_LPUART0TRG_EN_SHIFT   (8U)
/*! LPUART0TRG_EN - LPUART0 Output Trigger Monitor Enable */
#define SIUL2_MUX0_MISC_EN_LPUART0TRG_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_LPUART0TRG_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_LPUART0TRG_EN_MASK)

#define SIUL2_MUX0_MISC_EN_LPUART1TRG_EN_MASK    (0x200U)
#define SIUL2_MUX0_MISC_EN_LPUART1TRG_EN_SHIFT   (9U)
/*! LPUART1TRG_EN - LPUART1 Output Trigger Monitor Enable */
#define SIUL2_MUX0_MISC_EN_LPUART1TRG_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_LPUART1TRG_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_LPUART1TRG_EN_MASK)

#define SIUL2_MUX0_MISC_EN_LPUART2TRG_EN_MASK    (0x400U)
#define SIUL2_MUX0_MISC_EN_LPUART2TRG_EN_SHIFT   (10U)
/*! LPUART2TRG_EN - LPUART2 Output Trigger Monitor Enable */
#define SIUL2_MUX0_MISC_EN_LPUART2TRG_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_LPUART2TRG_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_LPUART2TRG_EN_MASK)

#define SIUL2_MUX0_MISC_EN_LPUART3TRG_EN_MASK    (0x800U)
#define SIUL2_MUX0_MISC_EN_LPUART3TRG_EN_SHIFT   (11U)
/*! LPUART3TRG_EN - LPUART3 Output Trigger Monitor Enable */
#define SIUL2_MUX0_MISC_EN_LPUART3TRG_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_LPUART3TRG_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_LPUART3TRG_EN_MASK)

#define SIUL2_MUX0_MISC_EN_BCTUFIFO0DMA_EN_MASK  (0x10000U)
#define SIUL2_MUX0_MISC_EN_BCTUFIFO0DMA_EN_SHIFT (16U)
/*! BCTUFIFO0DMA_EN - BCTU FIFO0 DMA Request Monitor Enable */
#define SIUL2_MUX0_MISC_EN_BCTUFIFO0DMA_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_BCTUFIFO0DMA_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_BCTUFIFO0DMA_EN_MASK)

#define SIUL2_MUX0_MISC_EN_BCTUFIFO1DMA_EN_MASK  (0x20000U)
#define SIUL2_MUX0_MISC_EN_BCTUFIFO1DMA_EN_SHIFT (17U)
/*! BCTUFIFO1DMA_EN - BCTU FIFO1 DMA Request Monitor Enable */
#define SIUL2_MUX0_MISC_EN_BCTUFIFO1DMA_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_BCTUFIFO1DMA_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_BCTUFIFO1DMA_EN_MASK)

#define SIUL2_MUX0_MISC_EN_BCTUADC0DMA_EN_MASK   (0x40000U)
#define SIUL2_MUX0_MISC_EN_BCTUADC0DMA_EN_SHIFT  (18U)
/*! BCTUADC0DMA_EN - BCTU ADC0DR DMA Request Monitor Enable */
#define SIUL2_MUX0_MISC_EN_BCTUADC0DMA_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_BCTUADC0DMA_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_BCTUADC0DMA_EN_MASK)

#define SIUL2_MUX0_MISC_EN_BCTUADC1DMA_EN_MASK   (0x80000U)
#define SIUL2_MUX0_MISC_EN_BCTUADC1DMA_EN_SHIFT  (19U)
/*! BCTUADC1DMA_EN - BCTU ADC1DR DMA Request Monitor Enable */
#define SIUL2_MUX0_MISC_EN_BCTUADC1DMA_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_BCTUADC1DMA_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_BCTUADC1DMA_EN_MASK)

#define SIUL2_MUX0_MISC_EN_BCTUADC2DMA_EN_MASK   (0x100000U)
#define SIUL2_MUX0_MISC_EN_BCTUADC2DMA_EN_SHIFT  (20U)
/*! BCTUADC2DMA_EN - BCTU ADC2DR DMA Request Monitor Enable */
#define SIUL2_MUX0_MISC_EN_BCTUADC2DMA_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_BCTUADC2DMA_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_BCTUADC2DMA_EN_MASK)

#define SIUL2_MUX0_MISC_EN_BCTUFIFO0INT_EN_MASK  (0x200000U)
#define SIUL2_MUX0_MISC_EN_BCTUFIFO0INT_EN_SHIFT (21U)
/*! BCTUFIFO0INT_EN - BCTU FIFO0 Interrupt Request Monitor Enable */
#define SIUL2_MUX0_MISC_EN_BCTUFIFO0INT_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_BCTUFIFO0INT_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_BCTUFIFO0INT_EN_MASK)

#define SIUL2_MUX0_MISC_EN_BCTUFIFO1INT_EN_MASK  (0x400000U)
#define SIUL2_MUX0_MISC_EN_BCTUFIFO1INT_EN_SHIFT (22U)
/*! BCTUFIFO1INT_EN - BCTU FIFO0 Interrupt Request Monitor Enable */
#define SIUL2_MUX0_MISC_EN_BCTUFIFO1INT_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_BCTUFIFO1INT_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_BCTUFIFO1INT_EN_MASK)

#define SIUL2_MUX0_MISC_EN_BCTULISTINT_EN_MASK   (0x800000U)
#define SIUL2_MUX0_MISC_EN_BCTULISTINT_EN_SHIFT  (23U)
/*! BCTULISTINT_EN - BCTU Conversion List Interrupt Request Enable */
#define SIUL2_MUX0_MISC_EN_BCTULISTINT_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_BCTULISTINT_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_BCTULISTINT_EN_MASK)

#define SIUL2_MUX0_MISC_EN_BCTUADC0INT_EN_MASK   (0x1000000U)
#define SIUL2_MUX0_MISC_EN_BCTUADC0INT_EN_SHIFT  (24U)
/*! BCTUADC0INT_EN - BCTU ADC0DR Interrupt Request Monitor Enable */
#define SIUL2_MUX0_MISC_EN_BCTUADC0INT_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_BCTUADC0INT_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_BCTUADC0INT_EN_MASK)

#define SIUL2_MUX0_MISC_EN_BCTUADC1INT_EN_MASK   (0x2000000U)
#define SIUL2_MUX0_MISC_EN_BCTUADC1INT_EN_SHIFT  (25U)
/*! BCTUADC1INT_EN - BCTU ADC1DR Interrupt Request Monitor Enable */
#define SIUL2_MUX0_MISC_EN_BCTUADC1INT_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_BCTUADC1INT_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_BCTUADC1INT_EN_MASK)

#define SIUL2_MUX0_MISC_EN_BCTUADC2INT_EN_MASK   (0x4000000U)
#define SIUL2_MUX0_MISC_EN_BCTUADC2INT_EN_SHIFT  (26U)
/*! BCTUADC2INT_EN - BCTU ADC2DR Interrupt Request Monitor Enable */
#define SIUL2_MUX0_MISC_EN_BCTUADC2INT_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX0_MISC_EN_BCTUADC2INT_EN_SHIFT)) & SIUL2_MUX0_MISC_EN_BCTUADC2INT_EN_MASK)
/*! @} */

/*! @name MUX1_EMIOS_EN - MUX1 EMIOS ENABLE */
/*! @{ */

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG16_EN_MASK   (0x1U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG16_EN_SHIFT  (0U)
/*! EMIOSFLG16_EN - EMIOS0 Output Flag 16 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG16_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG16_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG16_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG17_EN_MASK   (0x2U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG17_EN_SHIFT  (1U)
/*! EMIOSFLG17_EN - EMIOS0 Output Flag 17 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG17_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG17_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG17_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG18_EN_MASK   (0x4U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG18_EN_SHIFT  (2U)
/*! EMIOSFLG18_EN - EMIOS0 Output Flag 18 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG18_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG18_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG18_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG19_EN_MASK   (0x8U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG19_EN_SHIFT  (3U)
/*! EMIOSFLG19_EN - EMIOS0 Output Flag 19 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG19_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG19_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG19_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG20_EN_MASK   (0x10U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG20_EN_SHIFT  (4U)
/*! EMIOSFLG20_EN - EMIOS0 Output Flag 20 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG20_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG20_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG20_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG21_EN_MASK   (0x20U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG21_EN_SHIFT  (5U)
/*! EMIOSFLG21_EN - EMIOS0 Output Flag 21 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG21_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG21_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG21_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG22_EN_MASK   (0x40U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG22_EN_SHIFT  (6U)
/*! EMIOSFLG22_EN - EMIOS0 Output Flag 22 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG22_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG22_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG22_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG23_EN_MASK   (0x80U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG23_EN_SHIFT  (7U)
/*! EMIOSFLG23_EN - EMIOS0 Output Flag 23 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG23_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG23_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG23_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG0_EN_MASK    (0x10000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG0_EN_SHIFT   (16U)
/*! EMIOSFLG0_EN - EMIOS0 Output Flag 0 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG0_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG0_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG0_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG1_EN_MASK    (0x20000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG1_EN_SHIFT   (17U)
/*! EMIOSFLG1_EN - EMIOS0 Output Flag 1 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG1_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG1_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG1_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG2_EN_MASK    (0x40000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG2_EN_SHIFT   (18U)
/*! EMIOSFLG2_EN - EMIOS0 Output Flag 2 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG2_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG2_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG2_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG3_EN_MASK    (0x80000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG3_EN_SHIFT   (19U)
/*! EMIOSFLG3_EN - EMIOS0 Output Flag 3 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG3_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG3_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG3_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG4_EN_MASK    (0x100000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG4_EN_SHIFT   (20U)
/*! EMIOSFLG4_EN - EMIOS0 Output Flag 4 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG4_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG4_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG4_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG5_EN_MASK    (0x200000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG5_EN_SHIFT   (21U)
/*! EMIOSFLG5_EN - EMIOS0 Output Flag 5 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG5_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG5_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG5_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG6_EN_MASK    (0x400000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG6_EN_SHIFT   (22U)
/*! EMIOSFLG6_EN - EMIOS0 Output Flag 6 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG6_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG6_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG6_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG7_EN_MASK    (0x800000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG7_EN_SHIFT   (23U)
/*! EMIOSFLG7_EN - EMIOS0 Output Flag 7 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG7_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG7_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG7_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG8_EN_MASK    (0x1000000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG8_EN_SHIFT   (24U)
/*! EMIOSFLG8_EN - EMIOS0 Output Flag 8 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG8_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG8_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG8_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG9_EN_MASK    (0x2000000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG9_EN_SHIFT   (25U)
/*! EMIOSFLG9_EN - EMIOS0 Output Flag 9 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG9_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG9_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG9_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG10_EN_MASK   (0x4000000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG10_EN_SHIFT  (26U)
/*! EMIOSFLG10_EN - EMIOS0 Output Flag 10 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG10_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG10_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG10_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG11_EN_MASK   (0x8000000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG11_EN_SHIFT  (27U)
/*! EMIOSFLG11_EN - EMIOS0 Output Flag 11 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG11_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG11_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG11_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG12_EN_MASK   (0x10000000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG12_EN_SHIFT  (28U)
/*! EMIOSFLG12_EN - EMIOS0 Output Flag 12 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG12_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG12_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG12_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG13_EN_MASK   (0x20000000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG13_EN_SHIFT  (29U)
/*! EMIOSFLG13_EN - EMIOS0 Output Flag 13 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG13_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG13_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG13_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG14_EN_MASK   (0x40000000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG14_EN_SHIFT  (30U)
/*! EMIOSFLG14_EN - EMIOS0 Output Flag 14 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG14_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG14_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG14_EN_MASK)

#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG15_EN_MASK   (0x80000000U)
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG15_EN_SHIFT  (31U)
/*! EMIOSFLG15_EN - EMIOS0 Output Flag 15 Monitor Enable */
#define SIUL2_MUX1_EMIOS_EN_EMIOSFLG15_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_EMIOS_EN_EMIOSFLG15_EN_SHIFT)) & SIUL2_MUX1_EMIOS_EN_EMIOSFLG15_EN_MASK)
/*! @} */

/*! @name MUX1_MISC_EN - MUX1 MISC ENABLE */
/*! @{ */

#define SIUL2_MUX1_MISC_EN_ADC0EOC_EN_MASK       (0x1U)
#define SIUL2_MUX1_MISC_EN_ADC0EOC_EN_SHIFT      (0U)
/*! ADC0EOC_EN - ADC0 End of Conversion Trigger Monitor */
#define SIUL2_MUX1_MISC_EN_ADC0EOC_EN(x)         (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_ADC0EOC_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_ADC0EOC_EN_MASK)

#define SIUL2_MUX1_MISC_EN_ADC1EOC_EN_MASK       (0x2U)
#define SIUL2_MUX1_MISC_EN_ADC1EOC_EN_SHIFT      (1U)
/*! ADC1EOC_EN - ADC1 End of Conversion Trigger Monitor */
#define SIUL2_MUX1_MISC_EN_ADC1EOC_EN(x)         (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_ADC1EOC_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_ADC1EOC_EN_MASK)

#define SIUL2_MUX1_MISC_EN_LPUART0TRG_EN_MASK    (0x100U)
#define SIUL2_MUX1_MISC_EN_LPUART0TRG_EN_SHIFT   (8U)
/*! LPUART0TRG_EN - LPUART0 Output Trigger Monitor Enable */
#define SIUL2_MUX1_MISC_EN_LPUART0TRG_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_LPUART0TRG_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_LPUART0TRG_EN_MASK)

#define SIUL2_MUX1_MISC_EN_LPUART1TRG_EN_MASK    (0x200U)
#define SIUL2_MUX1_MISC_EN_LPUART1TRG_EN_SHIFT   (9U)
/*! LPUART1TRG_EN - LPUART1 Output Trigger Monitor Enable */
#define SIUL2_MUX1_MISC_EN_LPUART1TRG_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_LPUART1TRG_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_LPUART1TRG_EN_MASK)

#define SIUL2_MUX1_MISC_EN_LPUART2TRG_EN_MASK    (0x400U)
#define SIUL2_MUX1_MISC_EN_LPUART2TRG_EN_SHIFT   (10U)
/*! LPUART2TRG_EN - LPUART2 Output Trigger Monitor Enable */
#define SIUL2_MUX1_MISC_EN_LPUART2TRG_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_LPUART2TRG_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_LPUART2TRG_EN_MASK)

#define SIUL2_MUX1_MISC_EN_LPUART3TRG_EN_MASK    (0x800U)
#define SIUL2_MUX1_MISC_EN_LPUART3TRG_EN_SHIFT   (11U)
/*! LPUART3TRG_EN - LPUART3 Output Trigger Monitor Enable */
#define SIUL2_MUX1_MISC_EN_LPUART3TRG_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_LPUART3TRG_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_LPUART3TRG_EN_MASK)

#define SIUL2_MUX1_MISC_EN_BCTUFIFO0DMA_EN_MASK  (0x10000U)
#define SIUL2_MUX1_MISC_EN_BCTUFIFO0DMA_EN_SHIFT (16U)
/*! BCTUFIFO0DMA_EN - BCTU FIFO0 DMA Request Monitor Enable */
#define SIUL2_MUX1_MISC_EN_BCTUFIFO0DMA_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_BCTUFIFO0DMA_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_BCTUFIFO0DMA_EN_MASK)

#define SIUL2_MUX1_MISC_EN_BCTUFIFO1DMA_EN_MASK  (0x20000U)
#define SIUL2_MUX1_MISC_EN_BCTUFIFO1DMA_EN_SHIFT (17U)
/*! BCTUFIFO1DMA_EN - BCTU FIFO1 DMA Request Monitor Enable */
#define SIUL2_MUX1_MISC_EN_BCTUFIFO1DMA_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_BCTUFIFO1DMA_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_BCTUFIFO1DMA_EN_MASK)

#define SIUL2_MUX1_MISC_EN_BCTUADC0DMA_EN_MASK   (0x40000U)
#define SIUL2_MUX1_MISC_EN_BCTUADC0DMA_EN_SHIFT  (18U)
/*! BCTUADC0DMA_EN - BCTU ADC0DR DMA Request Monitor Enable */
#define SIUL2_MUX1_MISC_EN_BCTUADC0DMA_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_BCTUADC0DMA_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_BCTUADC0DMA_EN_MASK)

#define SIUL2_MUX1_MISC_EN_BCTUADC1DMA_EN_MASK   (0x80000U)
#define SIUL2_MUX1_MISC_EN_BCTUADC1DMA_EN_SHIFT  (19U)
/*! BCTUADC1DMA_EN - BCTU ADC1DR DMA Request Monitor Enable */
#define SIUL2_MUX1_MISC_EN_BCTUADC1DMA_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_BCTUADC1DMA_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_BCTUADC1DMA_EN_MASK)

#define SIUL2_MUX1_MISC_EN_BCTUFIFO0INT_EN_MASK  (0x200000U)
#define SIUL2_MUX1_MISC_EN_BCTUFIFO0INT_EN_SHIFT (21U)
/*! BCTUFIFO0INT_EN - BCTU FIFO0 Interrupt Request Monitor Enable */
#define SIUL2_MUX1_MISC_EN_BCTUFIFO0INT_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_BCTUFIFO0INT_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_BCTUFIFO0INT_EN_MASK)

#define SIUL2_MUX1_MISC_EN_BCTUFIFO1INT_EN_MASK  (0x400000U)
#define SIUL2_MUX1_MISC_EN_BCTUFIFO1INT_EN_SHIFT (22U)
/*! BCTUFIFO1INT_EN - BCTU FIFO0 Interrupt Request Monitor Enable */
#define SIUL2_MUX1_MISC_EN_BCTUFIFO1INT_EN(x)    (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_BCTUFIFO1INT_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_BCTUFIFO1INT_EN_MASK)

#define SIUL2_MUX1_MISC_EN_BCTULISTINT_EN_MASK   (0x800000U)
#define SIUL2_MUX1_MISC_EN_BCTULISTINT_EN_SHIFT  (23U)
/*! BCTULISTINT_EN - BCTU Conversion List Interrupt Request Enable */
#define SIUL2_MUX1_MISC_EN_BCTULISTINT_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_BCTULISTINT_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_BCTULISTINT_EN_MASK)

#define SIUL2_MUX1_MISC_EN_BCTUADC0INT_EN_MASK   (0x1000000U)
#define SIUL2_MUX1_MISC_EN_BCTUADC0INT_EN_SHIFT  (24U)
/*! BCTUADC0INT_EN - BCTU ADC0DR Interrupt Request Monitor Enable */
#define SIUL2_MUX1_MISC_EN_BCTUADC0INT_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_BCTUADC0INT_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_BCTUADC0INT_EN_MASK)

#define SIUL2_MUX1_MISC_EN_BCTUADC1INT_EN_MASK   (0x2000000U)
#define SIUL2_MUX1_MISC_EN_BCTUADC1INT_EN_SHIFT  (25U)
/*! BCTUADC1INT_EN - BCTU ADC1DR Interrupt Request Monitor Enable */
#define SIUL2_MUX1_MISC_EN_BCTUADC1INT_EN(x)     (((uint32_t)(((uint32_t)(x)) << SIUL2_MUX1_MISC_EN_BCTUADC1INT_EN_SHIFT)) & SIUL2_MUX1_MISC_EN_BCTUADC1INT_EN_MASK)
/*! @} */

/*! @name MIDR3 - SIUL2 MCU ID Register #3 */
/*! @{ */

#define SIUL2_MIDR3_SYS_RAM_SIZE_MASK            (0x3FU)
#define SIUL2_MIDR3_SYS_RAM_SIZE_SHIFT           (0U)
/*! SYS_RAM_SIZE - System RAM Size
 *  0b000010..128kB
 *  0b000011..192kB
 *  0b000100..256kB
 *  0b000110..512kB
 */
#define SIUL2_MIDR3_SYS_RAM_SIZE(x)              (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR3_SYS_RAM_SIZE_SHIFT)) & SIUL2_MIDR3_SYS_RAM_SIZE_MASK)

#define SIUL2_MIDR3_PART_NO_SUF_MASK             (0xFC00U)
#define SIUL2_MIDR3_PART_NO_SUF_SHIFT            (10U)
/*! PART_NO_SUF - Part Number Suffix
 *  0b000000..None
 */
#define SIUL2_MIDR3_PART_NO_SUF(x)               (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR3_PART_NO_SUF_SHIFT)) & SIUL2_MIDR3_PART_NO_SUF_MASK)

#define SIUL2_MIDR3_PROD_FAM_NO_MASK             (0x3FF0000U)
#define SIUL2_MIDR3_PROD_FAM_NO_SHIFT            (16U)
/*! PROD_FAM_NO - Product Family Number
 *  0b0000100000..32
 */
#define SIUL2_MIDR3_PROD_FAM_NO(x)               (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR3_PROD_FAM_NO_SHIFT)) & SIUL2_MIDR3_PROD_FAM_NO_MASK)

#define SIUL2_MIDR3_PROD_FAM_LET_MASK            (0xFC000000U)
#define SIUL2_MIDR3_PROD_FAM_LET_SHIFT           (26U)
/*! PROD_FAM_LET - Product Family Letter
 *  0b010011..S
 */
#define SIUL2_MIDR3_PROD_FAM_LET(x)              (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR3_PROD_FAM_LET_SHIFT)) & SIUL2_MIDR3_PROD_FAM_LET_MASK)
/*! @} */

/*! @name MIDR4 - SIUL2 MCU ID Register #4 */
/*! @{ */

#define SIUL2_MIDR4_CORE_PLAT_FET_MASK           (0x7U)
#define SIUL2_MIDR4_CORE_PLAT_FET_SHIFT          (0U)
/*! CORE_PLAT_FET - Core Platform Options Feature
 *  0b000..Single core
 *  0b001..Dual core
 *  0b010..1x lock-step core
 *  0b011..1x lock-step core + 1 perf. core
 *  0b100..Triple core
 */
#define SIUL2_MIDR4_CORE_PLAT_FET(x)             (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR4_CORE_PLAT_FET_SHIFT)) & SIUL2_MIDR4_CORE_PLAT_FET_MASK)

#define SIUL2_MIDR4_EMAC_FET_MASK                (0x18U)
#define SIUL2_MIDR4_EMAC_FET_SHIFT               (3U)
/*! EMAC_FET - Ethernet Feature
 *  0b00..No Ethernet
 *  0b01..Ethernet present
 */
#define SIUL2_MIDR4_EMAC_FET(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR4_EMAC_FET_SHIFT)) & SIUL2_MIDR4_EMAC_FET_MASK)

#define SIUL2_MIDR4_SEC_FET_MASK                 (0x60U)
#define SIUL2_MIDR4_SEC_FET_SHIFT                (5U)
/*! SEC_FET - Security Feature
 *  0b01..HSE-B
 */
#define SIUL2_MIDR4_SEC_FET(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MIDR4_SEC_FET_SHIFT)) & SIUL2_MIDR4_SEC_FET_MASK)
/*! @} */

/*! @name MSCR - SIUL2 Multiplexed Signal Configuration Register */
/*! @{ */

#define SIUL2_MSCR_SSS_MASK                      (0xFU)
#define SIUL2_MSCR_SSS_SHIFT                     (0U)
/*! SSS - Source Signal Select */
#define SIUL2_MSCR_SSS(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_SSS_SHIFT)) & SIUL2_MSCR_SSS_MASK)

#define SIUL2_MSCR_SMC_MASK                      (0x20U)
#define SIUL2_MSCR_SMC_SHIFT                     (5U)
/*! SMC - Safe Mode Control
 *  0b0..Disable (The output buffer returns to its previous state when the chip leaves Safe mode.)
 *  0b1..Don't disable
 */
#define SIUL2_MSCR_SMC(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_SMC_SHIFT)) & SIUL2_MSCR_SMC_MASK)

#define SIUL2_MSCR_IFE_MASK                      (0x40U)
#define SIUL2_MSCR_IFE_SHIFT                     (6U)
/*! IFE - IFE
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_MSCR_IFE(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_IFE_SHIFT)) & SIUL2_MSCR_IFE_MASK)

#define SIUL2_MSCR_DSE_MASK                      (0x100U)
#define SIUL2_MSCR_DSE_SHIFT                     (8U)
/*! DSE - DSE
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_MSCR_DSE(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_DSE_SHIFT)) & SIUL2_MSCR_DSE_MASK)

#define SIUL2_MSCR_PUS_MASK                      (0x800U)
#define SIUL2_MSCR_PUS_SHIFT                     (11U)
/*! PUS - Pull Select
 *  0b0..Pull down
 *  0b1..Pull up
 */
#define SIUL2_MSCR_PUS(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_PUS_SHIFT)) & SIUL2_MSCR_PUS_MASK)

#define SIUL2_MSCR_PUE_MASK                      (0x2000U)
#define SIUL2_MSCR_PUE_SHIFT                     (13U)
/*! PUE - Pull Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_MSCR_PUE(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_PUE_SHIFT)) & SIUL2_MSCR_PUE_MASK)

#define SIUL2_MSCR_SRC_MASK                      (0x4000U)
#define SIUL2_MSCR_SRC_SHIFT                     (14U)
/*! SRC - Slew Rate Control
 *  0b0..Fastest setting
 *  0b1..Slowest setting
 */
#define SIUL2_MSCR_SRC(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_SRC_SHIFT)) & SIUL2_MSCR_SRC_MASK)

#define SIUL2_MSCR_PKE_MASK                      (0x10000U)
#define SIUL2_MSCR_PKE_SHIFT                     (16U)
/*! PKE - Pad keeping enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_MSCR_PKE(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_PKE_SHIFT)) & SIUL2_MSCR_PKE_MASK)

#define SIUL2_MSCR_INV_MASK                      (0x20000U)
#define SIUL2_MSCR_INV_SHIFT                     (17U)
/*! INV - Invert
 *  0b0..Don't invert
 *  0b1..Invert
 */
#define SIUL2_MSCR_INV(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_INV_SHIFT)) & SIUL2_MSCR_INV_MASK)

#define SIUL2_MSCR_IBE_MASK                      (0x80000U)
#define SIUL2_MSCR_IBE_SHIFT                     (19U)
/*! IBE - Input Buffer Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SIUL2_MSCR_IBE(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_IBE_SHIFT)) & SIUL2_MSCR_IBE_MASK)

#define SIUL2_MSCR_OBE_MASK                      (0x200000U)
#define SIUL2_MSCR_OBE_SHIFT                     (21U)
/*! OBE - GPIO Output Buffer Enable
 *  0b0..Output driver disabled
 *  0b1..Output driver enabled
 */
#define SIUL2_MSCR_OBE(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_MSCR_OBE_SHIFT)) & SIUL2_MSCR_OBE_MASK)
/*! @} */

/*! @name IMCR - SIUL2 Input Multiplexed Signal Configuration */
/*! @{ */

#define SIUL2_IMCR_SSS_MASK                      (0xFU)
#define SIUL2_IMCR_SSS_SHIFT                     (0U)
/*! SSS - Source Signal Select */
#define SIUL2_IMCR_SSS(x)                        (((uint32_t)(((uint32_t)(x)) << SIUL2_IMCR_SSS_SHIFT)) & SIUL2_IMCR_SSS_MASK)
/*! @} */

/*! @name GPDO - SIUL2 GPIO Pad Data Output */
/*! @{ */

#define SIUL2_GPDO_PDO_n_MASK                    (0x1U)
#define SIUL2_GPDO_PDO_n_SHIFT                   (0U)
/*! PDO_n - Pad Data Out
 *  0b0..Pad Data Out Low
 *  0b1..Pad Data Out High
 */
#define SIUL2_GPDO_PDO_n(x)                      (((uint8_t)(((uint8_t)(x)) << SIUL2_GPDO_PDO_n_SHIFT)) & SIUL2_GPDO_PDO_n_MASK)
/*! @} */

/*! @name GPDI - SIUL2 GPIO Pad Data Input */
/*! @{ */

#define SIUL2_GPDI_PDI_n_MASK                    (0x1U)
#define SIUL2_GPDI_PDI_n_SHIFT                   (0U)
/*! PDI_n - Pad Data In
 *  0b0..Pad Data In Low
 *  0b1..Pad Data In High
 */
#define SIUL2_GPDI_PDI_n(x)                      (((uint8_t)(((uint8_t)(x)) << SIUL2_GPDI_PDI_n_SHIFT)) & SIUL2_GPDI_PDI_n_MASK)
/*! @} */

/*! @name PGPDO - SIUL2 Parallel GPIO Pad Data Out */
/*! @{ */

#define SIUL2_PGPDO_PPDO0_MASK                   (0x1U)
#define SIUL2_PGPDO_PPDO0_SHIFT                  (0U)
/*! PPDO0 - Parallel Pad Data Out 0
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO0(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO0_SHIFT)) & SIUL2_PGPDO_PPDO0_MASK)

#define SIUL2_PGPDO_PPDO1_MASK                   (0x2U)
#define SIUL2_PGPDO_PPDO1_SHIFT                  (1U)
/*! PPDO1 - Parallel Pad Data Out 1
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO1(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO1_SHIFT)) & SIUL2_PGPDO_PPDO1_MASK)

#define SIUL2_PGPDO_PPDO2_MASK                   (0x4U)
#define SIUL2_PGPDO_PPDO2_SHIFT                  (2U)
/*! PPDO2 - Parallel Pad Data Out 2
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO2(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO2_SHIFT)) & SIUL2_PGPDO_PPDO2_MASK)

#define SIUL2_PGPDO_PPDO3_MASK                   (0x8U)
#define SIUL2_PGPDO_PPDO3_SHIFT                  (3U)
/*! PPDO3 - Parallel Pad Data Out 3
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO3(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO3_SHIFT)) & SIUL2_PGPDO_PPDO3_MASK)

#define SIUL2_PGPDO_PPDO4_MASK                   (0x10U)
#define SIUL2_PGPDO_PPDO4_SHIFT                  (4U)
/*! PPDO4 - Parallel Pad Data Out 4
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO4(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO4_SHIFT)) & SIUL2_PGPDO_PPDO4_MASK)

#define SIUL2_PGPDO_PPDO5_MASK                   (0x20U)
#define SIUL2_PGPDO_PPDO5_SHIFT                  (5U)
/*! PPDO5 - Parallel Pad Data Out 5
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO5(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO5_SHIFT)) & SIUL2_PGPDO_PPDO5_MASK)

#define SIUL2_PGPDO_PPDO6_MASK                   (0x40U)
#define SIUL2_PGPDO_PPDO6_SHIFT                  (6U)
/*! PPDO6 - Parallel Pad Data Out 6
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO6(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO6_SHIFT)) & SIUL2_PGPDO_PPDO6_MASK)

#define SIUL2_PGPDO_PPDO7_MASK                   (0x80U)
#define SIUL2_PGPDO_PPDO7_SHIFT                  (7U)
/*! PPDO7 - Parallel Pad Data Out 7
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO7(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO7_SHIFT)) & SIUL2_PGPDO_PPDO7_MASK)

#define SIUL2_PGPDO_PPDO8_MASK                   (0x100U)
#define SIUL2_PGPDO_PPDO8_SHIFT                  (8U)
/*! PPDO8 - Parallel Pad Data Out 8
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO8(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO8_SHIFT)) & SIUL2_PGPDO_PPDO8_MASK)

#define SIUL2_PGPDO_PPDO9_MASK                   (0x200U)
#define SIUL2_PGPDO_PPDO9_SHIFT                  (9U)
/*! PPDO9 - Parallel Pad Data Out 9
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO9(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO9_SHIFT)) & SIUL2_PGPDO_PPDO9_MASK)

#define SIUL2_PGPDO_PPDO10_MASK                  (0x400U)
#define SIUL2_PGPDO_PPDO10_SHIFT                 (10U)
/*! PPDO10 - Parallel Pad Data Out 10
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO10(x)                    (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO10_SHIFT)) & SIUL2_PGPDO_PPDO10_MASK)

#define SIUL2_PGPDO_PPDO11_MASK                  (0x800U)
#define SIUL2_PGPDO_PPDO11_SHIFT                 (11U)
/*! PPDO11 - Parallel Pad Data Out 11
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO11(x)                    (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO11_SHIFT)) & SIUL2_PGPDO_PPDO11_MASK)

#define SIUL2_PGPDO_PPDO12_MASK                  (0x1000U)
#define SIUL2_PGPDO_PPDO12_SHIFT                 (12U)
/*! PPDO12 - Parallel Pad Data Out 12
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO12(x)                    (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO12_SHIFT)) & SIUL2_PGPDO_PPDO12_MASK)

#define SIUL2_PGPDO_PPDO13_MASK                  (0x2000U)
#define SIUL2_PGPDO_PPDO13_SHIFT                 (13U)
/*! PPDO13 - Parallel Pad Data Out 13
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO13(x)                    (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO13_SHIFT)) & SIUL2_PGPDO_PPDO13_MASK)

#define SIUL2_PGPDO_PPDO14_MASK                  (0x4000U)
#define SIUL2_PGPDO_PPDO14_SHIFT                 (14U)
/*! PPDO14 - Parallel Pad Data Out 14
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO14(x)                    (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO14_SHIFT)) & SIUL2_PGPDO_PPDO14_MASK)

#define SIUL2_PGPDO_PPDO15_MASK                  (0x8000U)
#define SIUL2_PGPDO_PPDO15_SHIFT                 (15U)
/*! PPDO15 - Parallel Pad Data Out 15
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDO_PPDO15(x)                    (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDO_PPDO15_SHIFT)) & SIUL2_PGPDO_PPDO15_MASK)
/*! @} */

/*! @name PGPDI - SIUL2 Parallel GPIO Pad Data In */
/*! @{ */

#define SIUL2_PGPDI_PPDI0_MASK                   (0x1U)
#define SIUL2_PGPDI_PPDI0_SHIFT                  (0U)
/*! PPDI0 - Parallel Pad Data In 0
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI0(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI0_SHIFT)) & SIUL2_PGPDI_PPDI0_MASK)

#define SIUL2_PGPDI_PPDI1_MASK                   (0x2U)
#define SIUL2_PGPDI_PPDI1_SHIFT                  (1U)
/*! PPDI1 - Parallel Pad Data In 1
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI1(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI1_SHIFT)) & SIUL2_PGPDI_PPDI1_MASK)

#define SIUL2_PGPDI_PPDI2_MASK                   (0x4U)
#define SIUL2_PGPDI_PPDI2_SHIFT                  (2U)
/*! PPDI2 - Parallel Pad Data In 2
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI2(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI2_SHIFT)) & SIUL2_PGPDI_PPDI2_MASK)

#define SIUL2_PGPDI_PPDI3_MASK                   (0x8U)
#define SIUL2_PGPDI_PPDI3_SHIFT                  (3U)
/*! PPDI3 - Parallel Pad Data In 3
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI3(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI3_SHIFT)) & SIUL2_PGPDI_PPDI3_MASK)

#define SIUL2_PGPDI_PPDI4_MASK                   (0x10U)
#define SIUL2_PGPDI_PPDI4_SHIFT                  (4U)
/*! PPDI4 - Parallel Pad Data In 4
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI4(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI4_SHIFT)) & SIUL2_PGPDI_PPDI4_MASK)

#define SIUL2_PGPDI_PPDI5_MASK                   (0x20U)
#define SIUL2_PGPDI_PPDI5_SHIFT                  (5U)
/*! PPDI5 - Parallel Pad Data In 5
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI5(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI5_SHIFT)) & SIUL2_PGPDI_PPDI5_MASK)

#define SIUL2_PGPDI_PPDI6_MASK                   (0x40U)
#define SIUL2_PGPDI_PPDI6_SHIFT                  (6U)
/*! PPDI6 - Parallel Pad Data In 6
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI6(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI6_SHIFT)) & SIUL2_PGPDI_PPDI6_MASK)

#define SIUL2_PGPDI_PPDI7_MASK                   (0x80U)
#define SIUL2_PGPDI_PPDI7_SHIFT                  (7U)
/*! PPDI7 - Parallel Pad Data In 7
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI7(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI7_SHIFT)) & SIUL2_PGPDI_PPDI7_MASK)

#define SIUL2_PGPDI_PPDI8_MASK                   (0x100U)
#define SIUL2_PGPDI_PPDI8_SHIFT                  (8U)
/*! PPDI8 - Parallel Pad Data In 8
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI8(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI8_SHIFT)) & SIUL2_PGPDI_PPDI8_MASK)

#define SIUL2_PGPDI_PPDI9_MASK                   (0x200U)
#define SIUL2_PGPDI_PPDI9_SHIFT                  (9U)
/*! PPDI9 - Parallel Pad Data In 9
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI9(x)                     (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI9_SHIFT)) & SIUL2_PGPDI_PPDI9_MASK)

#define SIUL2_PGPDI_PPDI10_MASK                  (0x400U)
#define SIUL2_PGPDI_PPDI10_SHIFT                 (10U)
/*! PPDI10 - Parallel Pad Data In 10
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI10(x)                    (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI10_SHIFT)) & SIUL2_PGPDI_PPDI10_MASK)

#define SIUL2_PGPDI_PPDI11_MASK                  (0x800U)
#define SIUL2_PGPDI_PPDI11_SHIFT                 (11U)
/*! PPDI11 - Parallel Pad Data In 11
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI11(x)                    (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI11_SHIFT)) & SIUL2_PGPDI_PPDI11_MASK)

#define SIUL2_PGPDI_PPDI12_MASK                  (0x1000U)
#define SIUL2_PGPDI_PPDI12_SHIFT                 (12U)
/*! PPDI12 - Parallel Pad Data In 12
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI12(x)                    (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI12_SHIFT)) & SIUL2_PGPDI_PPDI12_MASK)

#define SIUL2_PGPDI_PPDI13_MASK                  (0x2000U)
#define SIUL2_PGPDI_PPDI13_SHIFT                 (13U)
/*! PPDI13 - Parallel Pad Data In 13
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI13(x)                    (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI13_SHIFT)) & SIUL2_PGPDI_PPDI13_MASK)

#define SIUL2_PGPDI_PPDI14_MASK                  (0x4000U)
#define SIUL2_PGPDI_PPDI14_SHIFT                 (14U)
/*! PPDI14 - Parallel Pad Data In 14
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI14(x)                    (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI14_SHIFT)) & SIUL2_PGPDI_PPDI14_MASK)

#define SIUL2_PGPDI_PPDI15_MASK                  (0x8000U)
#define SIUL2_PGPDI_PPDI15_SHIFT                 (15U)
/*! PPDI15 - Parallel Pad Data In 15
 *  0b0..Logic low
 *  0b1..Logic high
 */
#define SIUL2_PGPDI_PPDI15(x)                    (((uint16_t)(((uint16_t)(x)) << SIUL2_PGPDI_PPDI15_SHIFT)) & SIUL2_PGPDI_PPDI15_MASK)
/*! @} */

/*! @name MPGPDO - SIUL2 Masked Parallel GPIO Pad Data Out */
/*! @{ */

#define SIUL2_MPGPDO_MPPDO0_MASK                 (0x1U)
#define SIUL2_MPGPDO_MPPDO0_SHIFT                (0U)
/*! MPPDO0 - Masked Parallel Pad Data Out 0 */
#define SIUL2_MPGPDO_MPPDO0(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO0_SHIFT)) & SIUL2_MPGPDO_MPPDO0_MASK)

#define SIUL2_MPGPDO_MPPDO1_MASK                 (0x2U)
#define SIUL2_MPGPDO_MPPDO1_SHIFT                (1U)
/*! MPPDO1 - Masked Parallel Pad Data Out 1 */
#define SIUL2_MPGPDO_MPPDO1(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO1_SHIFT)) & SIUL2_MPGPDO_MPPDO1_MASK)

#define SIUL2_MPGPDO_MPPDO2_MASK                 (0x4U)
#define SIUL2_MPGPDO_MPPDO2_SHIFT                (2U)
/*! MPPDO2 - Masked Parallel Pad Data Out 2 */
#define SIUL2_MPGPDO_MPPDO2(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO2_SHIFT)) & SIUL2_MPGPDO_MPPDO2_MASK)

#define SIUL2_MPGPDO_MPPDO3_MASK                 (0x8U)
#define SIUL2_MPGPDO_MPPDO3_SHIFT                (3U)
/*! MPPDO3 - Masked Parallel Pad Data Out 3 */
#define SIUL2_MPGPDO_MPPDO3(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO3_SHIFT)) & SIUL2_MPGPDO_MPPDO3_MASK)

#define SIUL2_MPGPDO_MPPDO4_MASK                 (0x10U)
#define SIUL2_MPGPDO_MPPDO4_SHIFT                (4U)
/*! MPPDO4 - Masked Parallel Pad Data Out 4 */
#define SIUL2_MPGPDO_MPPDO4(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO4_SHIFT)) & SIUL2_MPGPDO_MPPDO4_MASK)

#define SIUL2_MPGPDO_MPPDO5_MASK                 (0x20U)
#define SIUL2_MPGPDO_MPPDO5_SHIFT                (5U)
/*! MPPDO5 - Masked Parallel Pad Data Out 5 */
#define SIUL2_MPGPDO_MPPDO5(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO5_SHIFT)) & SIUL2_MPGPDO_MPPDO5_MASK)

#define SIUL2_MPGPDO_MPPDO6_MASK                 (0x40U)
#define SIUL2_MPGPDO_MPPDO6_SHIFT                (6U)
/*! MPPDO6 - Masked Parallel Pad Data Out 6 */
#define SIUL2_MPGPDO_MPPDO6(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO6_SHIFT)) & SIUL2_MPGPDO_MPPDO6_MASK)

#define SIUL2_MPGPDO_MPPDO7_MASK                 (0x80U)
#define SIUL2_MPGPDO_MPPDO7_SHIFT                (7U)
/*! MPPDO7 - Masked Parallel Pad Data Out 7 */
#define SIUL2_MPGPDO_MPPDO7(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO7_SHIFT)) & SIUL2_MPGPDO_MPPDO7_MASK)

#define SIUL2_MPGPDO_MPPDO8_MASK                 (0x100U)
#define SIUL2_MPGPDO_MPPDO8_SHIFT                (8U)
/*! MPPDO8 - Masked Parallel Pad Data Out 8 */
#define SIUL2_MPGPDO_MPPDO8(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO8_SHIFT)) & SIUL2_MPGPDO_MPPDO8_MASK)

#define SIUL2_MPGPDO_MPPDO9_MASK                 (0x200U)
#define SIUL2_MPGPDO_MPPDO9_SHIFT                (9U)
/*! MPPDO9 - Masked Parallel Pad Data Out 9 */
#define SIUL2_MPGPDO_MPPDO9(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO9_SHIFT)) & SIUL2_MPGPDO_MPPDO9_MASK)

#define SIUL2_MPGPDO_MPPDO10_MASK                (0x400U)
#define SIUL2_MPGPDO_MPPDO10_SHIFT               (10U)
/*! MPPDO10 - Masked Parallel Pad Data Out 10 */
#define SIUL2_MPGPDO_MPPDO10(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO10_SHIFT)) & SIUL2_MPGPDO_MPPDO10_MASK)

#define SIUL2_MPGPDO_MPPDO11_MASK                (0x800U)
#define SIUL2_MPGPDO_MPPDO11_SHIFT               (11U)
/*! MPPDO11 - Masked Parallel Pad Data Out 11 */
#define SIUL2_MPGPDO_MPPDO11(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO11_SHIFT)) & SIUL2_MPGPDO_MPPDO11_MASK)

#define SIUL2_MPGPDO_MPPDO12_MASK                (0x1000U)
#define SIUL2_MPGPDO_MPPDO12_SHIFT               (12U)
/*! MPPDO12 - Masked Parallel Pad Data Out 12 */
#define SIUL2_MPGPDO_MPPDO12(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO12_SHIFT)) & SIUL2_MPGPDO_MPPDO12_MASK)

#define SIUL2_MPGPDO_MPPDO13_MASK                (0x2000U)
#define SIUL2_MPGPDO_MPPDO13_SHIFT               (13U)
/*! MPPDO13 - Masked Parallel Pad Data Out 13 */
#define SIUL2_MPGPDO_MPPDO13(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO13_SHIFT)) & SIUL2_MPGPDO_MPPDO13_MASK)

#define SIUL2_MPGPDO_MPPDO14_MASK                (0x4000U)
#define SIUL2_MPGPDO_MPPDO14_SHIFT               (14U)
/*! MPPDO14 - Masked Parallel Pad Data Out 14 */
#define SIUL2_MPGPDO_MPPDO14(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO14_SHIFT)) & SIUL2_MPGPDO_MPPDO14_MASK)

#define SIUL2_MPGPDO_MPPDO15_MASK                (0x8000U)
#define SIUL2_MPGPDO_MPPDO15_SHIFT               (15U)
/*! MPPDO15 - Masked Parallel Pad Data Out 15 */
#define SIUL2_MPGPDO_MPPDO15(x)                  (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MPPDO15_SHIFT)) & SIUL2_MPGPDO_MPPDO15_MASK)

#define SIUL2_MPGPDO_MASK0_MASK                  (0x10000U)
#define SIUL2_MPGPDO_MASK0_SHIFT                 (16U)
/*! MASK0 - Mask Field 0
 *  0b0..MPPDO0 is ignored
 *  0b1..MPPDO0 is written
 */
#define SIUL2_MPGPDO_MASK0(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK0_SHIFT)) & SIUL2_MPGPDO_MASK0_MASK)

#define SIUL2_MPGPDO_MASK1_MASK                  (0x20000U)
#define SIUL2_MPGPDO_MASK1_SHIFT                 (17U)
/*! MASK1 - Mask Field 1
 *  0b0..MPPDO1 is ignored
 *  0b1..MPPDO1 is written
 */
#define SIUL2_MPGPDO_MASK1(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK1_SHIFT)) & SIUL2_MPGPDO_MASK1_MASK)

#define SIUL2_MPGPDO_MASK2_MASK                  (0x40000U)
#define SIUL2_MPGPDO_MASK2_SHIFT                 (18U)
/*! MASK2 - Mask Field 2
 *  0b0..MPPDO2 is ignored
 *  0b1..MPPDO2 is written
 */
#define SIUL2_MPGPDO_MASK2(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK2_SHIFT)) & SIUL2_MPGPDO_MASK2_MASK)

#define SIUL2_MPGPDO_MASK3_MASK                  (0x80000U)
#define SIUL2_MPGPDO_MASK3_SHIFT                 (19U)
/*! MASK3 - Mask Field 3
 *  0b0..MPPDO3 is ignored
 *  0b1..MPPDO3 is written
 */
#define SIUL2_MPGPDO_MASK3(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK3_SHIFT)) & SIUL2_MPGPDO_MASK3_MASK)

#define SIUL2_MPGPDO_MASK4_MASK                  (0x100000U)
#define SIUL2_MPGPDO_MASK4_SHIFT                 (20U)
/*! MASK4 - Mask Field 4
 *  0b0..MPPDO4 is ignored
 *  0b1..MPPDO4 is written
 */
#define SIUL2_MPGPDO_MASK4(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK4_SHIFT)) & SIUL2_MPGPDO_MASK4_MASK)

#define SIUL2_MPGPDO_MASK5_MASK                  (0x200000U)
#define SIUL2_MPGPDO_MASK5_SHIFT                 (21U)
/*! MASK5 - Mask Field 5
 *  0b0..MPPDO5 is ignored
 *  0b1..MPPDO5 is written
 */
#define SIUL2_MPGPDO_MASK5(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK5_SHIFT)) & SIUL2_MPGPDO_MASK5_MASK)

#define SIUL2_MPGPDO_MASK6_MASK                  (0x400000U)
#define SIUL2_MPGPDO_MASK6_SHIFT                 (22U)
/*! MASK6 - Mask Field 6
 *  0b0..MPPDO6 is ignored
 *  0b1..MPPDO6 is written
 */
#define SIUL2_MPGPDO_MASK6(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK6_SHIFT)) & SIUL2_MPGPDO_MASK6_MASK)

#define SIUL2_MPGPDO_MASK7_MASK                  (0x800000U)
#define SIUL2_MPGPDO_MASK7_SHIFT                 (23U)
/*! MASK7 - Mask Field 7
 *  0b0..MPPDO7 is ignored
 *  0b1..MPPDO7 is written
 */
#define SIUL2_MPGPDO_MASK7(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK7_SHIFT)) & SIUL2_MPGPDO_MASK7_MASK)

#define SIUL2_MPGPDO_MASK8_MASK                  (0x1000000U)
#define SIUL2_MPGPDO_MASK8_SHIFT                 (24U)
/*! MASK8 - Mask Field 8
 *  0b0..MPPDO8 is ignored
 *  0b1..MPPDO8 is written
 */
#define SIUL2_MPGPDO_MASK8(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK8_SHIFT)) & SIUL2_MPGPDO_MASK8_MASK)

#define SIUL2_MPGPDO_MASK9_MASK                  (0x2000000U)
#define SIUL2_MPGPDO_MASK9_SHIFT                 (25U)
/*! MASK9 - Mask Field 9
 *  0b0..MPPDO9 is ignored
 *  0b1..MPPDO9 is written
 */
#define SIUL2_MPGPDO_MASK9(x)                    (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK9_SHIFT)) & SIUL2_MPGPDO_MASK9_MASK)

#define SIUL2_MPGPDO_MASK10_MASK                 (0x4000000U)
#define SIUL2_MPGPDO_MASK10_SHIFT                (26U)
/*! MASK10 - Mask Field 10
 *  0b0..MPPDO10 is ignored
 *  0b1..MPPDO10 is written
 */
#define SIUL2_MPGPDO_MASK10(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK10_SHIFT)) & SIUL2_MPGPDO_MASK10_MASK)

#define SIUL2_MPGPDO_MASK11_MASK                 (0x8000000U)
#define SIUL2_MPGPDO_MASK11_SHIFT                (27U)
/*! MASK11 - Mask Field 11
 *  0b0..MPPDO11 is ignored
 *  0b1..MPPDO11 is written
 */
#define SIUL2_MPGPDO_MASK11(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK11_SHIFT)) & SIUL2_MPGPDO_MASK11_MASK)

#define SIUL2_MPGPDO_MASK12_MASK                 (0x10000000U)
#define SIUL2_MPGPDO_MASK12_SHIFT                (28U)
/*! MASK12 - Mask Field 12
 *  0b0..MPPDO12 is ignored
 *  0b1..MPPDO12 is written
 */
#define SIUL2_MPGPDO_MASK12(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK12_SHIFT)) & SIUL2_MPGPDO_MASK12_MASK)

#define SIUL2_MPGPDO_MASK13_MASK                 (0x20000000U)
#define SIUL2_MPGPDO_MASK13_SHIFT                (29U)
/*! MASK13 - Mask Field 13
 *  0b0..MPPDO13 is ignored
 *  0b1..MPPDO13 is written
 */
#define SIUL2_MPGPDO_MASK13(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK13_SHIFT)) & SIUL2_MPGPDO_MASK13_MASK)

#define SIUL2_MPGPDO_MASK14_MASK                 (0x40000000U)
#define SIUL2_MPGPDO_MASK14_SHIFT                (30U)
/*! MASK14 - Mask Field 14
 *  0b0..MPPDO14 is ignored
 *  0b1..MPPDO14 is written
 */
#define SIUL2_MPGPDO_MASK14(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK14_SHIFT)) & SIUL2_MPGPDO_MASK14_MASK)

#define SIUL2_MPGPDO_MASK15_MASK                 (0x80000000U)
#define SIUL2_MPGPDO_MASK15_SHIFT                (31U)
/*! MASK15 - Mask Field 15
 *  0b0..MPPDO15 is ignored
 *  0b1..MPPDO15 is written
 */
#define SIUL2_MPGPDO_MASK15(x)                   (((uint32_t)(((uint32_t)(x)) << SIUL2_MPGPDO_MASK15_SHIFT)) & SIUL2_MPGPDO_MASK15_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SIUL2_Register_Masks */


/*!
 * @}
 */ /* end of group SIUL2_Peripheral_Access_Layer */


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


#endif  /* PERI_SIUL2_H_ */

