/*
** ###################################################################
**     Processors:          MCXE315MLF
**                          MCXE315MPA
**                          MCXE316MLF
**                          MCXE316MPA
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250513
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MSCM
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
 * @file PERI_MSCM.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for MSCM
 *
 * CMSIS Peripheral Access Layer for MSCM
 */

#if !defined(PERI_MSCM_H_)
#define PERI_MSCM_H_                             /**< Symbol preventing repeated inclusion */

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
   -- MSCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Peripheral_Access_Layer MSCM Peripheral Access Layer
 * @{
 */

/** MSCM - Size of Registers Arrays */
#define MSCM_CP_COUNT                             1u
#define MSCM_IRSPRC_COUNT                         240u

/** MSCM - Register Layout Typedef */
typedef struct {
  __I  uint32_t CPXTYPE;                           /**< Processor X Type, offset: 0x0 */
  __I  uint32_t CPXNUM;                            /**< Processor X Number, offset: 0x4 */
  __I  uint32_t CPXREV;                            /**< Processor X Revision, offset: 0x8 */
  __I  uint32_t CPXCFG0;                           /**< Processor X Configuration 0, offset: 0xC */
  __I  uint32_t CPXCFG1;                           /**< Processor X Configuration 1, offset: 0x10 */
  __I  uint32_t CPXCFG2;                           /**< Processor X Configuration 2, offset: 0x14 */
  __I  uint32_t CPXCFG3;                           /**< Processor x Configuration 3, offset: 0x18 */
       uint8_t RESERVED_0[4];
  struct {                                         /* offset: 0x20, array step: 0x1C */
    __I  uint32_t TYPE;                              /**< Processor 0 Type, array offset: 0x20, array step: 0x1C */
    __I  uint32_t NUM;                               /**< Processor 0 Number, array offset: 0x24, array step: 0x1C */
    __I  uint32_t COUNT;                             /**< Processor 0 Count, array offset: 0x28, array step: 0x1C */
    __I  uint32_t CFG0;                              /**< Processor 0 Configuration 0, array offset: 0x2C, array step: 0x1C */
    __I  uint32_t CFG1;                              /**< Processor 0 Configuration 1, array offset: 0x30, array step: 0x1C */
    __I  uint32_t CFG2;                              /**< Processor 0 Configuration 2, array offset: 0x34, array step: 0x1C */
    __I  uint32_t CFG3;                              /**< Processor 0 Configuration 3, array offset: 0x38, array step: 0x1C */
  } CP[MSCM_CP_COUNT];
       uint8_t RESERVED_1[452];
  __IO uint32_t IRCP0ISR0;                         /**< Interrupt Router CP0 Interrupt Status, offset: 0x200 */
  __IO uint32_t IRCP0IGR0;                         /**< Interrupt Router CP0 Interrupt Generation, offset: 0x204 */
  __IO uint32_t IRCP0ISR1;                         /**< Interrupt Router CP0 Interrupt Status, offset: 0x208 */
  __IO uint32_t IRCP0IGR1;                         /**< Interrupt Router CP0 Interrupt Generation, offset: 0x20C */
  __IO uint32_t IRCP0ISR2;                         /**< Interrupt Router CP0 Interrupt Status, offset: 0x210 */
  __IO uint32_t IRCP0IGR2;                         /**< Interrupt Router CP0 Interrupt Generation, offset: 0x214 */
  __IO uint32_t IRCP0ISR3;                         /**< Interrupt Router CP0 Interrupt Status, offset: 0x218 */
  __IO uint32_t IRCP0IGR3;                         /**< Interrupt Router CP0 Interrupt Generation, offset: 0x21C */
  __IO uint32_t IRCP1ISR0;                         /**< Interrupt Router CP1 Interrupt Status, offset: 0x220 */
  __IO uint32_t IRCP1IGR0;                         /**< Interrupt Router CP1 Interrupt Generation, offset: 0x224 */
  __IO uint32_t IRCP1ISR1;                         /**< Interrupt Router CP1 Interrupt Status, offset: 0x228 */
  __IO uint32_t IRCP1IGR1;                         /**< Interrupt Router CP1 Interrupt Generation, offset: 0x22C */
  __IO uint32_t IRCP1ISR2;                         /**< Interrupt Router CP1 Interrupt Status, offset: 0x230 */
  __IO uint32_t IRCP1IGR2;                         /**< Interrupt Router CP1 Interrupt Generation, offset: 0x234 */
  __IO uint32_t IRCP1ISR3;                         /**< Interrupt Router CP1 Interrupt Status, offset: 0x238 */
  __IO uint32_t IRCP1IGR3;                         /**< Interrupt Router CP1 Interrupt Generation, offset: 0x23C */
       uint8_t RESERVED_2[448];
  __IO uint32_t IRCPCFG;                           /**< Interrupt Router Configuration, offset: 0x400 */
       uint8_t RESERVED_3[252];
  __IO uint32_t XN_CTRL;                           /**< Memory Execution Control, offset: 0x500 */
       uint8_t RESERVED_4[252];
  __IO uint32_t ENEDC;                             /**< Enable Interconnect Error Detection, offset: 0x600 */
       uint8_t RESERVED_5[252];
  __IO uint32_t IAHBCFGREG;                        /**< AHB Gasket Configuration, offset: 0x700 */
       uint8_t RESERVED_6[380];
  __IO uint16_t IRSPRC[MSCM_IRSPRC_COUNT];         /**< Interrupt Router Shared Peripheral Routing Control, array offset: 0x880, array step: 0x2 */
} MSCM_Type;

/* ----------------------------------------------------------------------------
   -- MSCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Register_Masks MSCM Register Masks
 * @{
 */

/*! @name CPXTYPE - Processor X Type */
/*! @{ */

#define MSCM_CPXTYPE_PERSONALITY_MASK            (0xFFFFFFFFU)
#define MSCM_CPXTYPE_PERSONALITY_SHIFT           (0U)
/*! PERSONALITY - Personality of CPx */
#define MSCM_CPXTYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CPXTYPE_PERSONALITY_SHIFT)) & MSCM_CPXTYPE_PERSONALITY_MASK)
/*! @} */

/*! @name CPXNUM - Processor X Number */
/*! @{ */

#define MSCM_CPXNUM_CPN_MASK                     (0x3U)
#define MSCM_CPXNUM_CPN_SHIFT                    (0U)
/*! CPN - Processor Number
 *  0b00..Cortex-M7 core 0
 *  0b01..Cortex-M7 core 1
 */
#define MSCM_CPXNUM_CPN(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CPXNUM_CPN_SHIFT)) & MSCM_CPXNUM_CPN_MASK)
/*! @} */

/*! @name CPXREV - Processor X Revision */
/*! @{ */

#define MSCM_CPXREV_RYPZ_MASK                    (0xFFU)
#define MSCM_CPXREV_RYPZ_SHIFT                   (0U)
/*! RYPZ - Processor Revision */
#define MSCM_CPXREV_RYPZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXREV_RYPZ_SHIFT)) & MSCM_CPXREV_RYPZ_MASK)
/*! @} */

/*! @name CPXCFG0 - Processor X Configuration 0 */
/*! @{ */

#define MSCM_CPXCFG0_DCWY_MASK                   (0xFFU)
#define MSCM_CPXCFG0_DCWY_SHIFT                  (0U)
/*! DCWY - L1 Data Cache Ways */
#define MSCM_CPXCFG0_DCWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_DCWY_SHIFT)) & MSCM_CPXCFG0_DCWY_MASK)

#define MSCM_CPXCFG0_DCSZ_MASK                   (0xFF00U)
#define MSCM_CPXCFG0_DCSZ_SHIFT                  (8U)
/*! DCSZ - L1 Data Cache Size */
#define MSCM_CPXCFG0_DCSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_DCSZ_SHIFT)) & MSCM_CPXCFG0_DCSZ_MASK)

#define MSCM_CPXCFG0_ICWY_MASK                   (0xFF0000U)
#define MSCM_CPXCFG0_ICWY_SHIFT                  (16U)
/*! ICWY - L1 Instruction Cache Ways */
#define MSCM_CPXCFG0_ICWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_ICWY_SHIFT)) & MSCM_CPXCFG0_ICWY_MASK)

#define MSCM_CPXCFG0_ICSZ_MASK                   (0xFF000000U)
#define MSCM_CPXCFG0_ICSZ_SHIFT                  (24U)
/*! ICSZ - Level 1 Instruction Cache Size */
#define MSCM_CPXCFG0_ICSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_ICSZ_SHIFT)) & MSCM_CPXCFG0_ICSZ_MASK)
/*! @} */

/*! @name CPXCFG1 - Processor X Configuration 1 */
/*! @{ */

#define MSCM_CPXCFG1_L2WY_MASK                   (0xFF0000U)
#define MSCM_CPXCFG1_L2WY_SHIFT                  (16U)
/*! L2WY - L2 Cache Ways */
#define MSCM_CPXCFG1_L2WY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG1_L2WY_SHIFT)) & MSCM_CPXCFG1_L2WY_MASK)

#define MSCM_CPXCFG1_L2SZ_MASK                   (0xFF000000U)
#define MSCM_CPXCFG1_L2SZ_SHIFT                  (24U)
/*! L2SZ - L2 Cache Size */
#define MSCM_CPXCFG1_L2SZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG1_L2SZ_SHIFT)) & MSCM_CPXCFG1_L2SZ_MASK)
/*! @} */

/*! @name CPXCFG2 - Processor X Configuration 2 */
/*! @{ */

#define MSCM_CPXCFG2_ITCMSZ_MASK                 (0xFF0000U)
#define MSCM_CPXCFG2_ITCMSZ_SHIFT                (16U)
/*! ITCMSZ - Instruction Tightly Coupled Memory Size */
#define MSCM_CPXCFG2_ITCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG2_ITCMSZ_SHIFT)) & MSCM_CPXCFG2_ITCMSZ_MASK)

#define MSCM_CPXCFG2_DTCMSZ_MASK                 (0xFF000000U)
#define MSCM_CPXCFG2_DTCMSZ_SHIFT                (24U)
/*! DTCMSZ - Tightly Coupled Data Memory Size */
#define MSCM_CPXCFG2_DTCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG2_DTCMSZ_SHIFT)) & MSCM_CPXCFG2_DTCMSZ_MASK)
/*! @} */

/*! @name CPXCFG3 - Processor x Configuration 3 */
/*! @{ */

#define MSCM_CPXCFG3_FPU_MASK                    (0x1U)
#define MSCM_CPXCFG3_FPU_SHIFT                   (0U)
/*! FPU - Floating Point Unit
 *  0b0..Not provided
 *  0b1..Provided
 */
#define MSCM_CPXCFG3_FPU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_FPU_SHIFT)) & MSCM_CPXCFG3_FPU_MASK)

#define MSCM_CPXCFG3_SIMD_MASK                   (0x2U)
#define MSCM_CPXCFG3_SIMD_SHIFT                  (1U)
/*! SIMD - SIMD/NEON Instruction Support
 *  0b0..Not included
 *  0b1..Included
 */
#define MSCM_CPXCFG3_SIMD(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_SIMD_SHIFT)) & MSCM_CPXCFG3_SIMD_MASK)

#define MSCM_CPXCFG3_MMU_MASK                    (0x4U)
#define MSCM_CPXCFG3_MMU_SHIFT                   (2U)
/*! MMU - Memory Management Unit
 *  0b0..Not supported
 *  0b1..Supported
 */
#define MSCM_CPXCFG3_MMU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_MMU_SHIFT)) & MSCM_CPXCFG3_MMU_MASK)

#define MSCM_CPXCFG3_CMP_MASK                    (0x8U)
#define MSCM_CPXCFG3_CMP_SHIFT                   (3U)
/*! CMP - Core Memory Protection Unit
 *  0b0..Not included
 *  0b1..Included
 */
#define MSCM_CPXCFG3_CMP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_CMP_SHIFT)) & MSCM_CPXCFG3_CMP_MASK)

#define MSCM_CPXCFG3_CPY_MASK                    (0x10U)
#define MSCM_CPXCFG3_CPY_SHIFT                   (4U)
/*! CPY - Cryptography
 *  0b0..Not supported
 *  0b1..Supported
 */
#define MSCM_CPXCFG3_CPY(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_CPY_SHIFT)) & MSCM_CPXCFG3_CPY_MASK)
/*! @} */

/*! @name TYPE - Processor 0 Type */
/*! @{ */

#define MSCM_TYPE_PERSONALITY_MASK               (0xFFFFFFFFU)
#define MSCM_TYPE_PERSONALITY_SHIFT              (0U)
/*! PERSONALITY - Processor Personality */
#define MSCM_TYPE_PERSONALITY(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_TYPE_PERSONALITY_SHIFT)) & MSCM_TYPE_PERSONALITY_MASK)
/*! @} */

/* The count of MSCM_TYPE */
#define MSCM_TYPE_COUNT                          (1U)

/*! @name NUM - Processor 0 Number */
/*! @{ */

#define MSCM_NUM_CPN_MASK                        (0x3U)
#define MSCM_NUM_CPN_SHIFT                       (0U)
/*! CPN - Processor Number */
#define MSCM_NUM_CPN(x)                          (((uint32_t)(((uint32_t)(x)) << MSCM_NUM_CPN_SHIFT)) & MSCM_NUM_CPN_MASK)
/*! @} */

/* The count of MSCM_NUM */
#define MSCM_NUM_COUNT                           (1U)

/*! @name COUNT - Processor 0 Count */
/*! @{ */

#define MSCM_COUNT_RYPZ_MASK                     (0xFFU)
#define MSCM_COUNT_RYPZ_SHIFT                    (0U)
/*! RYPZ - Processor Revision */
#define MSCM_COUNT_RYPZ(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_COUNT_RYPZ_SHIFT)) & MSCM_COUNT_RYPZ_MASK)
/*! @} */

/* The count of MSCM_COUNT */
#define MSCM_COUNT_COUNT                         (1U)

/*! @name CFG0 - Processor 0 Configuration 0 */
/*! @{ */

#define MSCM_CFG0_DCWY_MASK                      (0xFFU)
#define MSCM_CFG0_DCWY_SHIFT                     (0U)
/*! DCWY - L1 Data Cache Ways */
#define MSCM_CFG0_DCWY(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_CFG0_DCWY_SHIFT)) & MSCM_CFG0_DCWY_MASK)

#define MSCM_CFG0_DCSZ_MASK                      (0xFF00U)
#define MSCM_CFG0_DCSZ_SHIFT                     (8U)
/*! DCSZ - L1 Data Cache Size */
#define MSCM_CFG0_DCSZ(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_CFG0_DCSZ_SHIFT)) & MSCM_CFG0_DCSZ_MASK)

#define MSCM_CFG0_ICWY_MASK                      (0xFF0000U)
#define MSCM_CFG0_ICWY_SHIFT                     (16U)
/*! ICWY - L1 Instruction Cache Ways */
#define MSCM_CFG0_ICWY(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_CFG0_ICWY_SHIFT)) & MSCM_CFG0_ICWY_MASK)

#define MSCM_CFG0_ICSZ_MASK                      (0xFF000000U)
#define MSCM_CFG0_ICSZ_SHIFT                     (24U)
/*! ICSZ - Level 1 Instruction Cache Size */
#define MSCM_CFG0_ICSZ(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_CFG0_ICSZ_SHIFT)) & MSCM_CFG0_ICSZ_MASK)
/*! @} */

/* The count of MSCM_CFG0 */
#define MSCM_CFG0_COUNT                          (1U)

/*! @name CFG1 - Processor 0 Configuration 1 */
/*! @{ */

#define MSCM_CFG1_L2WY_MASK                      (0xFF0000U)
#define MSCM_CFG1_L2WY_SHIFT                     (16U)
/*! L2WY - L2 Cache Ways */
#define MSCM_CFG1_L2WY(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_CFG1_L2WY_SHIFT)) & MSCM_CFG1_L2WY_MASK)

#define MSCM_CFG1_L2SZ_MASK                      (0xFF000000U)
#define MSCM_CFG1_L2SZ_SHIFT                     (24U)
/*! L2SZ - L2 Cache Size */
#define MSCM_CFG1_L2SZ(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_CFG1_L2SZ_SHIFT)) & MSCM_CFG1_L2SZ_MASK)
/*! @} */

/* The count of MSCM_CFG1 */
#define MSCM_CFG1_COUNT                          (1U)

/*! @name CFG2 - Processor 0 Configuration 2 */
/*! @{ */

#define MSCM_CFG2_ITCMSZ_MASK                    (0xFF0000U)
#define MSCM_CFG2_ITCMSZ_SHIFT                   (16U)
/*! ITCMSZ - Instruction Tightly Coupled Memory Size */
#define MSCM_CFG2_ITCMSZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CFG2_ITCMSZ_SHIFT)) & MSCM_CFG2_ITCMSZ_MASK)

#define MSCM_CFG2_DTCMSZ_MASK                    (0xFF000000U)
#define MSCM_CFG2_DTCMSZ_SHIFT                   (24U)
/*! DTCMSZ - Tightly Coupled Data Memory Size */
#define MSCM_CFG2_DTCMSZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CFG2_DTCMSZ_SHIFT)) & MSCM_CFG2_DTCMSZ_MASK)
/*! @} */

/* The count of MSCM_CFG2 */
#define MSCM_CFG2_COUNT                          (1U)

/*! @name CFG3 - Processor 0 Configuration 3 */
/*! @{ */

#define MSCM_CFG3_FPU_MASK                       (0x1U)
#define MSCM_CFG3_FPU_SHIFT                      (0U)
/*! FPU - Floating Point Unit
 *  0b0..Not provided
 *  0b1..Provided
 */
#define MSCM_CFG3_FPU(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_CFG3_FPU_SHIFT)) & MSCM_CFG3_FPU_MASK)

#define MSCM_CFG3_SIMD_MASK                      (0x2U)
#define MSCM_CFG3_SIMD_SHIFT                     (1U)
/*! SIMD - SIMD/NEON Instruction Support
 *  0b0..Not included
 *  0b1..Included
 */
#define MSCM_CFG3_SIMD(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_CFG3_SIMD_SHIFT)) & MSCM_CFG3_SIMD_MASK)

#define MSCM_CFG3_MMU_MASK                       (0x4U)
#define MSCM_CFG3_MMU_SHIFT                      (2U)
/*! MMU - Memory Management Unit
 *  0b0..Not supported
 *  0b1..Supported
 */
#define MSCM_CFG3_MMU(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_CFG3_MMU_SHIFT)) & MSCM_CFG3_MMU_MASK)

#define MSCM_CFG3_CMP_MASK                       (0x8U)
#define MSCM_CFG3_CMP_SHIFT                      (3U)
/*! CMP - Core Memory Protection Unit
 *  0b0..Not included
 *  0b1..Included
 */
#define MSCM_CFG3_CMP(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_CFG3_CMP_SHIFT)) & MSCM_CFG3_CMP_MASK)

#define MSCM_CFG3_CPY_MASK                       (0x10U)
#define MSCM_CFG3_CPY_SHIFT                      (4U)
/*! CPY - Cryptography
 *  0b0..Not supported
 *  0b1..Supported
 */
#define MSCM_CFG3_CPY(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_CFG3_CPY_SHIFT)) & MSCM_CFG3_CPY_MASK)
/*! @} */

/* The count of MSCM_CFG3 */
#define MSCM_CFG3_COUNT                          (1U)

/*! @name IRCP0ISR0 - Interrupt Router CP0 Interrupt Status */
/*! @{ */

#define MSCM_IRCP0ISR0_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP0ISR0_CP0_INT_SHIFT             (0U)
/*! CP0_INT - CP0-to-CPn Interrupt
 *  0b0..No interrupt asserted to CPn
 *  0b1..Interrupt to CPn asserted
 */
#define MSCM_IRCP0ISR0_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR0_CP0_INT_SHIFT)) & MSCM_IRCP0ISR0_CP0_INT_MASK)
/*! @} */

/*! @name IRCP0IGR0 - Interrupt Router CP0 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP0IGR0_INT_EN_MASK               (0x1U)
#define MSCM_IRCP0IGR0_INT_EN_SHIFT              (0U)
/*! INT_EN - Interrupt Enable */
#define MSCM_IRCP0IGR0_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0IGR0_INT_EN_SHIFT)) & MSCM_IRCP0IGR0_INT_EN_MASK)
/*! @} */

/*! @name IRCP0ISR1 - Interrupt Router CP0 Interrupt Status */
/*! @{ */

#define MSCM_IRCP0ISR1_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP0ISR1_CP0_INT_SHIFT             (0U)
/*! CP0_INT - CP0-to-CPn Interrupt
 *  0b0..No interrupt asserted to CPn
 *  0b1..Interrupt to CPn asserted
 */
#define MSCM_IRCP0ISR1_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR1_CP0_INT_SHIFT)) & MSCM_IRCP0ISR1_CP0_INT_MASK)
/*! @} */

/*! @name IRCP0IGR1 - Interrupt Router CP0 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP0IGR1_INT_EN_MASK               (0x1U)
#define MSCM_IRCP0IGR1_INT_EN_SHIFT              (0U)
/*! INT_EN - Interrupt Enable */
#define MSCM_IRCP0IGR1_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0IGR1_INT_EN_SHIFT)) & MSCM_IRCP0IGR1_INT_EN_MASK)
/*! @} */

/*! @name IRCP0ISR2 - Interrupt Router CP0 Interrupt Status */
/*! @{ */

#define MSCM_IRCP0ISR2_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP0ISR2_CP0_INT_SHIFT             (0U)
/*! CP0_INT - CP0-to-CPn Interrupt
 *  0b0..No interrupt asserted to CPn
 *  0b1..Interrupt to CPn asserted
 */
#define MSCM_IRCP0ISR2_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR2_CP0_INT_SHIFT)) & MSCM_IRCP0ISR2_CP0_INT_MASK)
/*! @} */

/*! @name IRCP0IGR2 - Interrupt Router CP0 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP0IGR2_INT_EN_MASK               (0x1U)
#define MSCM_IRCP0IGR2_INT_EN_SHIFT              (0U)
/*! INT_EN - Interrupt Enable */
#define MSCM_IRCP0IGR2_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0IGR2_INT_EN_SHIFT)) & MSCM_IRCP0IGR2_INT_EN_MASK)
/*! @} */

/*! @name IRCP0ISR3 - Interrupt Router CP0 Interrupt Status */
/*! @{ */

#define MSCM_IRCP0ISR3_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP0ISR3_CP0_INT_SHIFT             (0U)
/*! CP0_INT - CP0-to-CPn Interrupt
 *  0b0..No interrupt asserted to CPn
 *  0b1..Interrupt to CPn asserted
 */
#define MSCM_IRCP0ISR3_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR3_CP0_INT_SHIFT)) & MSCM_IRCP0ISR3_CP0_INT_MASK)
/*! @} */

/*! @name IRCP0IGR3 - Interrupt Router CP0 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP0IGR3_INT_EN_MASK               (0x1U)
#define MSCM_IRCP0IGR3_INT_EN_SHIFT              (0U)
/*! INT_EN - Interrupt Enable */
#define MSCM_IRCP0IGR3_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0IGR3_INT_EN_SHIFT)) & MSCM_IRCP0IGR3_INT_EN_MASK)
/*! @} */

/*! @name IRCP1ISR0 - Interrupt Router CP1 Interrupt Status */
/*! @{ */

#define MSCM_IRCP1ISR0_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP1ISR0_CP0_INT_SHIFT             (0U)
/*! CP0_INT - CP0-to-CPn Interrupt
 *  0b0..No interrupt asserted to CPn
 *  0b1..Interrupt to CPn asserted
 */
#define MSCM_IRCP1ISR0_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR0_CP0_INT_SHIFT)) & MSCM_IRCP1ISR0_CP0_INT_MASK)
/*! @} */

/*! @name IRCP1IGR0 - Interrupt Router CP1 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP1IGR0_INT_EN_MASK               (0x1U)
#define MSCM_IRCP1IGR0_INT_EN_SHIFT              (0U)
/*! INT_EN - Interrupt Enable */
#define MSCM_IRCP1IGR0_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1IGR0_INT_EN_SHIFT)) & MSCM_IRCP1IGR0_INT_EN_MASK)
/*! @} */

/*! @name IRCP1ISR1 - Interrupt Router CP1 Interrupt Status */
/*! @{ */

#define MSCM_IRCP1ISR1_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP1ISR1_CP0_INT_SHIFT             (0U)
/*! CP0_INT - CP0-to-CPn Interrupt
 *  0b0..No interrupt asserted to CPn
 *  0b1..Interrupt to CPn asserted
 */
#define MSCM_IRCP1ISR1_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR1_CP0_INT_SHIFT)) & MSCM_IRCP1ISR1_CP0_INT_MASK)
/*! @} */

/*! @name IRCP1IGR1 - Interrupt Router CP1 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP1IGR1_INT_EN_MASK               (0x1U)
#define MSCM_IRCP1IGR1_INT_EN_SHIFT              (0U)
/*! INT_EN - Interrupt Enable */
#define MSCM_IRCP1IGR1_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1IGR1_INT_EN_SHIFT)) & MSCM_IRCP1IGR1_INT_EN_MASK)
/*! @} */

/*! @name IRCP1ISR2 - Interrupt Router CP1 Interrupt Status */
/*! @{ */

#define MSCM_IRCP1ISR2_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP1ISR2_CP0_INT_SHIFT             (0U)
/*! CP0_INT - CP0-to-CPn Interrupt
 *  0b0..No interrupt asserted to CPn
 *  0b1..Interrupt to CPn asserted
 */
#define MSCM_IRCP1ISR2_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR2_CP0_INT_SHIFT)) & MSCM_IRCP1ISR2_CP0_INT_MASK)
/*! @} */

/*! @name IRCP1IGR2 - Interrupt Router CP1 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP1IGR2_INT_EN_MASK               (0x1U)
#define MSCM_IRCP1IGR2_INT_EN_SHIFT              (0U)
/*! INT_EN - Interrupt Enable */
#define MSCM_IRCP1IGR2_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1IGR2_INT_EN_SHIFT)) & MSCM_IRCP1IGR2_INT_EN_MASK)
/*! @} */

/*! @name IRCP1ISR3 - Interrupt Router CP1 Interrupt Status */
/*! @{ */

#define MSCM_IRCP1ISR3_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP1ISR3_CP0_INT_SHIFT             (0U)
/*! CP0_INT - CP0-to-CPn Interrupt
 *  0b0..No interrupt asserted to CPn
 *  0b1..Interrupt to CPn asserted
 */
#define MSCM_IRCP1ISR3_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR3_CP0_INT_SHIFT)) & MSCM_IRCP1ISR3_CP0_INT_MASK)
/*! @} */

/*! @name IRCP1IGR3 - Interrupt Router CP1 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP1IGR3_INT_EN_MASK               (0x1U)
#define MSCM_IRCP1IGR3_INT_EN_SHIFT              (0U)
/*! INT_EN - Interrupt Enable */
#define MSCM_IRCP1IGR3_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1IGR3_INT_EN_SHIFT)) & MSCM_IRCP1IGR3_INT_EN_MASK)
/*! @} */

/*! @name IRCPCFG - Interrupt Router Configuration */
/*! @{ */

#define MSCM_IRCPCFG_CP0_TR_MASK                 (0x1U)
#define MSCM_IRCPCFG_CP0_TR_SHIFT                (0U)
/*! CP0_TR - CP0 as Trusted Core
 *  0b0..Not trusted
 *  0b1..Trusted
 */
#define MSCM_IRCPCFG_CP0_TR(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_IRCPCFG_CP0_TR_SHIFT)) & MSCM_IRCPCFG_CP0_TR_MASK)

#define MSCM_IRCPCFG_LOCK_MASK                   (0x80000000U)
#define MSCM_IRCPCFG_LOCK_SHIFT                  (31U)
/*! LOCK - Lock
 *  0b0..Register can be written by any privileged write
 *  0b1..Register is locked (read-only) until the next reset
 */
#define MSCM_IRCPCFG_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_IRCPCFG_LOCK_SHIFT)) & MSCM_IRCPCFG_LOCK_MASK)
/*! @} */

/*! @name XN_CTRL - Memory Execution Control */
/*! @{ */

#define MSCM_XN_CTRL_SRAM0_XN_MASK               (0x1U)
#define MSCM_XN_CTRL_SRAM0_XN_SHIFT              (0U)
/*! SRAM0_XN - SRAM 0 Controller Access Execution Control
 *  0b0..Allowed
 *  0b1..Not allowed
 */
#define MSCM_XN_CTRL_SRAM0_XN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_SRAM0_XN_SHIFT)) & MSCM_XN_CTRL_SRAM0_XN_MASK)

#define MSCM_XN_CTRL_SRAM1_XN_MASK               (0x2U)
#define MSCM_XN_CTRL_SRAM1_XN_SHIFT              (1U)
/*! SRAM1_XN - SRAM 1 Controller Access Execution Control
 *  0b0..Allowed
 *  0b1..Not allowed
 */
#define MSCM_XN_CTRL_SRAM1_XN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_SRAM1_XN_SHIFT)) & MSCM_XN_CTRL_SRAM1_XN_MASK)

#define MSCM_XN_CTRL_ITCM0_XN_MASK               (0x100U)
#define MSCM_XN_CTRL_ITCM0_XN_SHIFT              (8U)
/*! ITCM0_XN - ITCM Core 0 Direct Access Execution Control
 *  0b0..Allowed
 *  0b1..Disabled
 */
#define MSCM_XN_CTRL_ITCM0_XN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_ITCM0_XN_SHIFT)) & MSCM_XN_CTRL_ITCM0_XN_MASK)

#define MSCM_XN_CTRL_ITCM1_XN_MASK               (0x200U)
#define MSCM_XN_CTRL_ITCM1_XN_SHIFT              (9U)
/*! ITCM1_XN - ITCM Core 1 Direct Access Execution Control
 *  0b0..Allowed
 *  0b1..Disabled
 */
#define MSCM_XN_CTRL_ITCM1_XN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_ITCM1_XN_SHIFT)) & MSCM_XN_CTRL_ITCM1_XN_MASK)

#define MSCM_XN_CTRL_ITCM0_BK_XN_MASK            (0x1000U)
#define MSCM_XN_CTRL_ITCM0_BK_XN_SHIFT           (12U)
/*! ITCM0_BK_XN - ITCM Core 0 Backdoor Access Execution Control
 *  0b0..Allowed
 *  0b1..Disabled
 */
#define MSCM_XN_CTRL_ITCM0_BK_XN(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_ITCM0_BK_XN_SHIFT)) & MSCM_XN_CTRL_ITCM0_BK_XN_MASK)

#define MSCM_XN_CTRL_ITCM1_BK_XN_MASK            (0x2000U)
#define MSCM_XN_CTRL_ITCM1_BK_XN_SHIFT           (13U)
/*! ITCM1_BK_XN - ITCM Core 1 Backdoor Access Execution Control
 *  0b0..Allowed
 *  0b1..Disabled
 */
#define MSCM_XN_CTRL_ITCM1_BK_XN(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_ITCM1_BK_XN_SHIFT)) & MSCM_XN_CTRL_ITCM1_BK_XN_MASK)

#define MSCM_XN_CTRL_DTCM0_XN_MASK               (0x10000U)
#define MSCM_XN_CTRL_DTCM0_XN_SHIFT              (16U)
/*! DTCM0_XN - DTCM Core 0 Direct Access Execution Control
 *  0b0..Allowed
 *  0b1..Disabled
 */
#define MSCM_XN_CTRL_DTCM0_XN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_DTCM0_XN_SHIFT)) & MSCM_XN_CTRL_DTCM0_XN_MASK)

#define MSCM_XN_CTRL_DTCM1_XN_MASK               (0x20000U)
#define MSCM_XN_CTRL_DTCM1_XN_SHIFT              (17U)
/*! DTCM1_XN - DTCM Core 1 Direct Access Execution Control
 *  0b0..Allowed
 *  0b1..Disabled
 */
#define MSCM_XN_CTRL_DTCM1_XN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_DTCM1_XN_SHIFT)) & MSCM_XN_CTRL_DTCM1_XN_MASK)

#define MSCM_XN_CTRL_DTCM0_BK_XN_MASK            (0x100000U)
#define MSCM_XN_CTRL_DTCM0_BK_XN_SHIFT           (20U)
/*! DTCM0_BK_XN - DTCM Core 0 Backdoor Access Execution Control
 *  0b0..Allowed
 *  0b1..Disabled
 */
#define MSCM_XN_CTRL_DTCM0_BK_XN(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_DTCM0_BK_XN_SHIFT)) & MSCM_XN_CTRL_DTCM0_BK_XN_MASK)

#define MSCM_XN_CTRL_DTCM1_BK_XN_MASK            (0x200000U)
#define MSCM_XN_CTRL_DTCM1_BK_XN_SHIFT           (21U)
/*! DTCM1_BK_XN - DTCM Core 1 Backdoor Access Execution Control
 *  0b0..Allowed
 *  0b1..Disabled
 */
#define MSCM_XN_CTRL_DTCM1_BK_XN(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_DTCM1_BK_XN_SHIFT)) & MSCM_XN_CTRL_DTCM1_BK_XN_MASK)

#define MSCM_XN_CTRL_SLK_MASK                    (0x40000000U)
#define MSCM_XN_CTRL_SLK_SHIFT                   (30U)
/*! SLK - Soft Lock
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_XN_CTRL_SLK(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_SLK_SHIFT)) & MSCM_XN_CTRL_SLK_MASK)

#define MSCM_XN_CTRL_HLK_MASK                    (0x80000000U)
#define MSCM_XN_CTRL_HLK_SHIFT                   (31U)
/*! HLK - Hard Lock
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_XN_CTRL_HLK(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_HLK_SHIFT)) & MSCM_XN_CTRL_HLK_MASK)
/*! @} */

/*! @name ENEDC - Enable Interconnect Error Detection */
/*! @{ */

#define MSCM_ENEDC_EN_RD_CM7_0_AHBM_MASK         (0x1U)
#define MSCM_ENEDC_EN_RD_CM7_0_AHBM_SHIFT        (0U)
/*! EN_RD_CM7_0_AHBM - Enable Read Data Check Cortex-M7_0_AHBM
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_RD_CM7_0_AHBM(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_RD_CM7_0_AHBM_SHIFT)) & MSCM_ENEDC_EN_RD_CM7_0_AHBM_MASK)

#define MSCM_ENEDC_EN_RD_CM7_0_AHBP_MASK         (0x2U)
#define MSCM_ENEDC_EN_RD_CM7_0_AHBP_SHIFT        (1U)
/*! EN_RD_CM7_0_AHBP - Enable Read Data Check Cortex-M7_0_AHBP
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_RD_CM7_0_AHBP(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_RD_CM7_0_AHBP_SHIFT)) & MSCM_ENEDC_EN_RD_CM7_0_AHBP_MASK)

#define MSCM_ENEDC_EN_RD_EDMA_MASK               (0x4U)
#define MSCM_ENEDC_EN_RD_EDMA_SHIFT              (2U)
/*! EN_RD_EDMA - Enable Read Data Check eDMA
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_RD_EDMA(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_RD_EDMA_SHIFT)) & MSCM_ENEDC_EN_RD_EDMA_MASK)

#define MSCM_ENEDC_EN_RD_HSE_MASK                (0x10U)
#define MSCM_ENEDC_EN_RD_HSE_SHIFT               (4U)
/*! EN_RD_HSE - Enable Read Data Check HSE
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_RD_HSE(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_RD_HSE_SHIFT)) & MSCM_ENEDC_EN_RD_HSE_MASK)

#define MSCM_ENEDC_EN_RD_EMAC_MASK               (0x20U)
#define MSCM_ENEDC_EN_RD_EMAC_SHIFT              (5U)
/*! EN_RD_EMAC - Enable Read Data Check EMAC
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_RD_EMAC(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_RD_EMAC_SHIFT)) & MSCM_ENEDC_EN_RD_EMAC_MASK)

#define MSCM_ENEDC_EN_RD_CM7_1_AHBM_MASK         (0x40U)
#define MSCM_ENEDC_EN_RD_CM7_1_AHBM_SHIFT        (6U)
/*! EN_RD_CM7_1_AHBM - Enable Read Data Check Cortex-M7_1_AHBM
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_RD_CM7_1_AHBM(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_RD_CM7_1_AHBM_SHIFT)) & MSCM_ENEDC_EN_RD_CM7_1_AHBM_MASK)

#define MSCM_ENEDC_EN_RD_CM7_1_AHBP_MASK         (0x80U)
#define MSCM_ENEDC_EN_RD_CM7_1_AHBP_SHIFT        (7U)
/*! EN_RD_CM7_1_AHBP - Enable Read Data Check Cortex-M7_1_AHBP
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_RD_CM7_1_AHBP(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_RD_CM7_1_AHBP_SHIFT)) & MSCM_ENEDC_EN_RD_CM7_1_AHBP_MASK)

#define MSCM_ENEDC_EN_RD_TCM_MASK                (0x100U)
#define MSCM_ENEDC_EN_RD_TCM_SHIFT               (8U)
/*! EN_RD_TCM - Enable Read Data Check TCM
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_RD_TCM(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_RD_TCM_SHIFT)) & MSCM_ENEDC_EN_RD_TCM_MASK)

#define MSCM_ENEDC_EN_ADD_PFLASH_PORT0_MASK      (0x200U)
#define MSCM_ENEDC_EN_ADD_PFLASH_PORT0_SHIFT     (9U)
/*! EN_ADD_PFLASH_PORT0 - Enable Address Check P_FLASH_PORT0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_ADD_PFLASH_PORT0(x)        (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_ADD_PFLASH_PORT0_SHIFT)) & MSCM_ENEDC_EN_ADD_PFLASH_PORT0_MASK)

#define MSCM_ENEDC_EN_ADD_PFLASH_PORT1_MASK      (0x400U)
#define MSCM_ENEDC_EN_ADD_PFLASH_PORT1_SHIFT     (10U)
/*! EN_ADD_PFLASH_PORT1 - Enable Address Check P_FLASH_PORT1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_ADD_PFLASH_PORT1(x)        (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_ADD_PFLASH_PORT1_SHIFT)) & MSCM_ENEDC_EN_ADD_PFLASH_PORT1_MASK)

#define MSCM_ENEDC_EN_ADD_PFLASH_PORT2_MASK      (0x800U)
#define MSCM_ENEDC_EN_ADD_PFLASH_PORT2_SHIFT     (11U)
/*! EN_ADD_PFLASH_PORT2 - Enable Address Check P_FLASH_PORT2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_ADD_PFLASH_PORT2(x)        (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_ADD_PFLASH_PORT2_SHIFT)) & MSCM_ENEDC_EN_ADD_PFLASH_PORT2_MASK)

#define MSCM_ENEDC_EN_WR_PRAM0_MASK              (0x1000U)
#define MSCM_ENEDC_EN_WR_PRAM0_SHIFT             (12U)
/*! EN_WR_PRAM0 - Enable Write Data Check PRAM0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_WR_PRAM0(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_WR_PRAM0_SHIFT)) & MSCM_ENEDC_EN_WR_PRAM0_MASK)

#define MSCM_ENEDC_EN_ADD_PRAM0_MASK             (0x2000U)
#define MSCM_ENEDC_EN_ADD_PRAM0_SHIFT            (13U)
/*! EN_ADD_PRAM0 - Enable Address Check PRAM0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_ADD_PRAM0(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_ADD_PRAM0_SHIFT)) & MSCM_ENEDC_EN_ADD_PRAM0_MASK)

#define MSCM_ENEDC_EN_WR_PRAM1_MASK              (0x4000U)
#define MSCM_ENEDC_EN_WR_PRAM1_SHIFT             (14U)
/*! EN_WR_PRAM1 - Enable Write Data Check PRAM1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_WR_PRAM1(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_WR_PRAM1_SHIFT)) & MSCM_ENEDC_EN_WR_PRAM1_MASK)

#define MSCM_ENEDC_EN_ADD_PRAM1_MASK             (0x8000U)
#define MSCM_ENEDC_EN_ADD_PRAM1_SHIFT            (15U)
/*! EN_ADD_PRAM1 - Enable Address Check PRAM1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_ADD_PRAM1(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_ADD_PRAM1_SHIFT)) & MSCM_ENEDC_EN_ADD_PRAM1_MASK)

#define MSCM_ENEDC_EN_WR_TCM_MASK                (0x10000U)
#define MSCM_ENEDC_EN_WR_TCM_SHIFT               (16U)
/*! EN_WR_TCM - Enable Write Data Check TCM
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_WR_TCM(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_WR_TCM_SHIFT)) & MSCM_ENEDC_EN_WR_TCM_MASK)

#define MSCM_ENEDC_EN_ADD_TCM_MASK               (0x20000U)
#define MSCM_ENEDC_EN_ADD_TCM_SHIFT              (17U)
/*! EN_ADD_TCM - Enable Address Check TCM
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_ADD_TCM(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_ADD_TCM_SHIFT)) & MSCM_ENEDC_EN_ADD_TCM_MASK)

#define MSCM_ENEDC_EN_ADD_QSPI_MASK              (0x80000U)
#define MSCM_ENEDC_EN_ADD_QSPI_SHIFT             (19U)
/*! EN_ADD_QSPI - Enable Address Check QuadSPI
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_ADD_QSPI(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_ADD_QSPI_SHIFT)) & MSCM_ENEDC_EN_ADD_QSPI_MASK)

#define MSCM_ENEDC_EN_WR_AIPS0_MASK              (0x100000U)
#define MSCM_ENEDC_EN_WR_AIPS0_SHIFT             (20U)
/*! EN_WR_AIPS0 - Enable Write Data Check AIPS0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_WR_AIPS0(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_WR_AIPS0_SHIFT)) & MSCM_ENEDC_EN_WR_AIPS0_MASK)

#define MSCM_ENEDC_EN_ADD_AIPS0_MASK             (0x200000U)
#define MSCM_ENEDC_EN_ADD_AIPS0_SHIFT            (21U)
/*! EN_ADD_AIPS0 - Enable Address Check AIPS0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_ADD_AIPS0(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_ADD_AIPS0_SHIFT)) & MSCM_ENEDC_EN_ADD_AIPS0_MASK)

#define MSCM_ENEDC_EN_WR_AIPS1_MASK              (0x400000U)
#define MSCM_ENEDC_EN_WR_AIPS1_SHIFT             (22U)
/*! EN_WR_AIPS1 - Enable Write Data Check AIPS1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_WR_AIPS1(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_WR_AIPS1_SHIFT)) & MSCM_ENEDC_EN_WR_AIPS1_MASK)

#define MSCM_ENEDC_EN_ADD_AIPS1_MASK             (0x800000U)
#define MSCM_ENEDC_EN_ADD_AIPS1_SHIFT            (23U)
/*! EN_ADD_AIPS1 - Enable Address Check AIPS1
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_ADD_AIPS1(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_ADD_AIPS1_SHIFT)) & MSCM_ENEDC_EN_ADD_AIPS1_MASK)

#define MSCM_ENEDC_EN_WR_AIPS2_MASK              (0x1000000U)
#define MSCM_ENEDC_EN_WR_AIPS2_SHIFT             (24U)
/*! EN_WR_AIPS2 - Enable Write Data Check AIPS2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_WR_AIPS2(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_WR_AIPS2_SHIFT)) & MSCM_ENEDC_EN_WR_AIPS2_MASK)

#define MSCM_ENEDC_EN_ADD_AIPS2_MASK             (0x2000000U)
#define MSCM_ENEDC_EN_ADD_AIPS2_SHIFT            (25U)
/*! EN_ADD_AIPS2 - Enable Address Check AIPS2
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_ADD_AIPS2(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_ADD_AIPS2_SHIFT)) & MSCM_ENEDC_EN_ADD_AIPS2_MASK)

#define MSCM_ENEDC_EN_WR_CM7_0_TCM_MASK          (0x4000000U)
#define MSCM_ENEDC_EN_WR_CM7_0_TCM_SHIFT         (26U)
/*! EN_WR_CM7_0_TCM - Enable Write Data Check Cortex-M7_0_TCM
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_WR_CM7_0_TCM(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_WR_CM7_0_TCM_SHIFT)) & MSCM_ENEDC_EN_WR_CM7_0_TCM_MASK)

#define MSCM_ENEDC_EN_ADD_CM7_0_TCM_MASK         (0x8000000U)
#define MSCM_ENEDC_EN_ADD_CM7_0_TCM_SHIFT        (27U)
/*! EN_ADD_CM7_0_TCM - Enable Address Check Cortex-M7_0_TCM
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_ADD_CM7_0_TCM(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_ADD_CM7_0_TCM_SHIFT)) & MSCM_ENEDC_EN_ADD_CM7_0_TCM_MASK)

#define MSCM_ENEDC_EN_WR_CM7_1_TCM_MASK          (0x10000000U)
#define MSCM_ENEDC_EN_WR_CM7_1_TCM_SHIFT         (28U)
/*! EN_WR_CM7_1_TCM - Enable Write Data Check Cortex-M7_1_TCM
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_WR_CM7_1_TCM(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_WR_CM7_1_TCM_SHIFT)) & MSCM_ENEDC_EN_WR_CM7_1_TCM_MASK)

#define MSCM_ENEDC_EN_ADD_CM7_1_TCM_MASK         (0x20000000U)
#define MSCM_ENEDC_EN_ADD_CM7_1_TCM_SHIFT        (29U)
/*! EN_ADD_CM7_1_TCM - Enable Address Check Cortex-M7_1_TCM
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_ADD_CM7_1_TCM(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_ADD_CM7_1_TCM_SHIFT)) & MSCM_ENEDC_EN_ADD_CM7_1_TCM_MASK)

#define MSCM_ENEDC_EN_ADD_DMA_S0_MASK            (0x40000000U)
#define MSCM_ENEDC_EN_ADD_DMA_S0_SHIFT           (30U)
/*! EN_ADD_DMA_S0 - Enable DMA AXBS S0 Port
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_ADD_DMA_S0(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_ADD_DMA_S0_SHIFT)) & MSCM_ENEDC_EN_ADD_DMA_S0_MASK)

#define MSCM_ENEDC_EN_ADD_DMA_S1_MASK            (0x80000000U)
#define MSCM_ENEDC_EN_ADD_DMA_S1_SHIFT           (31U)
/*! EN_ADD_DMA_S1 - Enable DMA AXBS S1 Port
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MSCM_ENEDC_EN_ADD_DMA_S1(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EN_ADD_DMA_S1_SHIFT)) & MSCM_ENEDC_EN_ADD_DMA_S1_MASK)
/*! @} */

/*! @name IAHBCFGREG - AHB Gasket Configuration */
/*! @{ */

#define MSCM_IAHBCFGREG_EMAC_DIS_WR_OPT_MASK     (0x1U)
#define MSCM_IAHBCFGREG_EMAC_DIS_WR_OPT_SHIFT    (0U)
/*! EMAC_DIS_WR_OPT
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define MSCM_IAHBCFGREG_EMAC_DIS_WR_OPT(x)       (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_EMAC_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_EMAC_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_DMA_AXBS_S0_DIS_WR_OPT_MASK (0x10U)
#define MSCM_IAHBCFGREG_DMA_AXBS_S0_DIS_WR_OPT_SHIFT (4U)
/*! DMA_AXBS_S0_DIS_WR_OPT
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define MSCM_IAHBCFGREG_DMA_AXBS_S0_DIS_WR_OPT(x) (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_DMA_AXBS_S0_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_DMA_AXBS_S0_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_DMA_AXBS_S1_DIS_WR_OPT_MASK (0x100U)
#define MSCM_IAHBCFGREG_DMA_AXBS_S1_DIS_WR_OPT_SHIFT (8U)
/*! DMA_AXBS_S1_DIS_WR_OPT
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define MSCM_IAHBCFGREG_DMA_AXBS_S1_DIS_WR_OPT(x) (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_DMA_AXBS_S1_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_DMA_AXBS_S1_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_HSE_DIS_WR_OPT_MASK      (0x1000U)
#define MSCM_IAHBCFGREG_HSE_DIS_WR_OPT_SHIFT     (12U)
/*! HSE_DIS_WR_OPT
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define MSCM_IAHBCFGREG_HSE_DIS_WR_OPT(x)        (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_HSE_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_HSE_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_TCM_DIS_WR_OPT_MASK      (0x10000U)
#define MSCM_IAHBCFGREG_TCM_DIS_WR_OPT_SHIFT     (16U)
/*! TCM_DIS_WR_OPT
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define MSCM_IAHBCFGREG_TCM_DIS_WR_OPT(x)        (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_TCM_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_TCM_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_QSPI_DIS_WR_OPT_MASK     (0x100000U)
#define MSCM_IAHBCFGREG_QSPI_DIS_WR_OPT_SHIFT    (20U)
/*! QSPI_DIS_WR_OPT
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define MSCM_IAHBCFGREG_QSPI_DIS_WR_OPT(x)       (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_QSPI_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_QSPI_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_AIPS1_DIS_WR_OPT_MASK    (0x1000000U)
#define MSCM_IAHBCFGREG_AIPS1_DIS_WR_OPT_SHIFT   (24U)
/*! AIPS1_DIS_WR_OPT
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define MSCM_IAHBCFGREG_AIPS1_DIS_WR_OPT(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_AIPS1_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_AIPS1_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_AIPS2_DIS_WR_OPT_MASK    (0x10000000U)
#define MSCM_IAHBCFGREG_AIPS2_DIS_WR_OPT_SHIFT   (28U)
/*! AIPS2_DIS_WR_OPT
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define MSCM_IAHBCFGREG_AIPS2_DIS_WR_OPT(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_AIPS2_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_AIPS2_DIS_WR_OPT_MASK)
/*! @} */

/*! @name IRSPRC - Interrupt Router Shared Peripheral Routing Control */
/*! @{ */

#define MSCM_IRSPRC_M7_0_MASK                    (0x1U)
#define MSCM_IRSPRC_M7_0_SHIFT                   (0U)
/*! M7_0 - Enable Cortex-M7_0 Interrupt Steering
 *  0b0..Routing disabled
 *  0b1..Routing enabled
 */
#define MSCM_IRSPRC_M7_0(x)                      (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_M7_0_SHIFT)) & MSCM_IRSPRC_M7_0_MASK)

#define MSCM_IRSPRC_LOCK_MASK                    (0x8000U)
#define MSCM_IRSPRC_LOCK_SHIFT                   (15U)
/*! LOCK - Lock
 *  0b0..Writes to IRSPRCn allowed
 *  0b1..Writes to IRSPRCn ignored
 */
#define MSCM_IRSPRC_LOCK(x)                      (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_LOCK_SHIFT)) & MSCM_IRSPRC_LOCK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MSCM_Register_Masks */


/*!
 * @}
 */ /* end of group MSCM_Peripheral_Access_Layer */


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


#endif  /* PERI_MSCM_H_ */

