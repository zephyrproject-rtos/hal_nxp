/*
** ###################################################################
**     Processors:          MCXE246VLH
**                          MCXE246VLL
**                          MCXE246VLQ
**
**     Version:             rev. 1.0, 2025-02-21
**     Build:               b250424
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LMEM
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
 * @file PERI_LMEM.h
 * @version 1.0
 * @date 2025-02-21
 * @brief CMSIS Peripheral Access Layer for LMEM
 *
 * CMSIS Peripheral Access Layer for LMEM
 */

#if !defined(PERI_LMEM_H_)
#define PERI_LMEM_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE246VLH) || defined(CPU_MCXE246VLL) || defined(CPU_MCXE246VLQ))
#include "MCXE246_COMMON.h"
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
   -- LMEM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LMEM_Peripheral_Access_Layer LMEM Peripheral Access Layer
 * @{
 */

/** LMEM - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCCCR;                             /**< Cache control register, offset: 0x0 */
  __IO uint32_t PCCLCR;                            /**< Cache line control register, offset: 0x4 */
  __IO uint32_t PCCSAR;                            /**< Cache search address register, offset: 0x8 */
  __IO uint32_t PCCCVR;                            /**< Cache read/write value register, offset: 0xC */
       uint8_t RESERVED_0[16];
  __IO uint32_t PCCRMR;                            /**< Cache regions mode register, offset: 0x20 */
} LMEM_Type;

/* ----------------------------------------------------------------------------
   -- LMEM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LMEM_Register_Masks LMEM Register Masks
 * @{
 */

/*! @name PCCCR - Cache control register */
/*! @{ */

#define LMEM_PCCCR_ENCACHE_MASK                  (0x1U)
#define LMEM_PCCCR_ENCACHE_SHIFT                 (0U)
/*! ENCACHE - Cache enable
 *  0b0..Cache disabled
 *  0b1..Cache enabled
 */
#define LMEM_PCCCR_ENCACHE(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_ENCACHE_SHIFT)) & LMEM_PCCCR_ENCACHE_MASK)

#define LMEM_PCCCR_PCCR2_MASK                    (0x4U)
#define LMEM_PCCCR_PCCR2_SHIFT                   (2U)
/*! PCCR2 - Forces all cacheable spaces to write through */
#define LMEM_PCCCR_PCCR2(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_PCCR2_SHIFT)) & LMEM_PCCCR_PCCR2_MASK)

#define LMEM_PCCCR_PCCR3_MASK                    (0x8U)
#define LMEM_PCCCR_PCCR3_SHIFT                   (3U)
/*! PCCR3 - Forces no allocation on cache misses (must also have PCCR2 asserted) */
#define LMEM_PCCCR_PCCR3(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_PCCR3_SHIFT)) & LMEM_PCCCR_PCCR3_MASK)

#define LMEM_PCCCR_INVW0_MASK                    (0x1000000U)
#define LMEM_PCCCR_INVW0_SHIFT                   (24U)
/*! INVW0 - Invalidate Way 0
 *  0b0..No operation
 *  0b1..When setting the GO bit, invalidate all lines in way 0.
 */
#define LMEM_PCCCR_INVW0(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_INVW0_SHIFT)) & LMEM_PCCCR_INVW0_MASK)

#define LMEM_PCCCR_PUSHW0_MASK                   (0x2000000U)
#define LMEM_PCCCR_PUSHW0_SHIFT                  (25U)
/*! PUSHW0 - Push Way 0
 *  0b0..No operation
 *  0b1..When setting the GO bit, push all modified lines in way 0
 */
#define LMEM_PCCCR_PUSHW0(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_PUSHW0_SHIFT)) & LMEM_PCCCR_PUSHW0_MASK)

#define LMEM_PCCCR_INVW1_MASK                    (0x4000000U)
#define LMEM_PCCCR_INVW1_SHIFT                   (26U)
/*! INVW1 - Invalidate Way 1
 *  0b0..No operation
 *  0b1..When setting the GO bit, invalidate all lines in way 1
 */
#define LMEM_PCCCR_INVW1(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_INVW1_SHIFT)) & LMEM_PCCCR_INVW1_MASK)

#define LMEM_PCCCR_PUSHW1_MASK                   (0x8000000U)
#define LMEM_PCCCR_PUSHW1_SHIFT                  (27U)
/*! PUSHW1 - Push Way 1
 *  0b0..No operation
 *  0b1..When setting the GO bit, push all modified lines in way 1
 */
#define LMEM_PCCCR_PUSHW1(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_PUSHW1_SHIFT)) & LMEM_PCCCR_PUSHW1_MASK)

#define LMEM_PCCCR_GO_MASK                       (0x80000000U)
#define LMEM_PCCCR_GO_SHIFT                      (31U)
/*! GO - Initiate Cache Command
 *  0b0..Write: no effect. Read: no cache command active.
 *  0b1..Write: initiate command indicated by bits 27-24. Read: cache command active.
 */
#define LMEM_PCCCR_GO(x)                         (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_GO_SHIFT)) & LMEM_PCCCR_GO_MASK)
/*! @} */

/*! @name PCCLCR - Cache line control register */
/*! @{ */

#define LMEM_PCCLCR_LGO_MASK                     (0x1U)
#define LMEM_PCCLCR_LGO_SHIFT                    (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect. Read: no line command active.
 *  0b1..Write: initiate line command indicated by bits 27-24. Read: line command active.
 */
#define LMEM_PCCLCR_LGO(x)                       (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_LGO_SHIFT)) & LMEM_PCCLCR_LGO_MASK)

#define LMEM_PCCLCR_CACHEADDR_MASK               (0x3FFCU)
#define LMEM_PCCLCR_CACHEADDR_SHIFT              (2U)
/*! CACHEADDR - Cache address */
#define LMEM_PCCLCR_CACHEADDR(x)                 (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_CACHEADDR_SHIFT)) & LMEM_PCCLCR_CACHEADDR_MASK)

#define LMEM_PCCLCR_WSEL_MASK                    (0x4000U)
#define LMEM_PCCLCR_WSEL_SHIFT                   (14U)
/*! WSEL - Way select
 *  0b0..Way 0
 *  0b1..Way 1
 */
#define LMEM_PCCLCR_WSEL(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_WSEL_SHIFT)) & LMEM_PCCLCR_WSEL_MASK)

#define LMEM_PCCLCR_TDSEL_MASK                   (0x10000U)
#define LMEM_PCCLCR_TDSEL_SHIFT                  (16U)
/*! TDSEL - Tag/Data Select
 *  0b0..Data
 *  0b1..Tag
 */
#define LMEM_PCCLCR_TDSEL(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_TDSEL_SHIFT)) & LMEM_PCCLCR_TDSEL_MASK)

#define LMEM_PCCLCR_LCIVB_MASK                   (0x100000U)
#define LMEM_PCCLCR_LCIVB_SHIFT                  (20U)
/*! LCIVB - Line Command Initial Valid Bit */
#define LMEM_PCCLCR_LCIVB(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_LCIVB_SHIFT)) & LMEM_PCCLCR_LCIVB_MASK)

#define LMEM_PCCLCR_LCIMB_MASK                   (0x200000U)
#define LMEM_PCCLCR_LCIMB_SHIFT                  (21U)
/*! LCIMB - Line Command Initial Modified Bit */
#define LMEM_PCCLCR_LCIMB(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_LCIMB_SHIFT)) & LMEM_PCCLCR_LCIMB_MASK)

#define LMEM_PCCLCR_LCWAY_MASK                   (0x400000U)
#define LMEM_PCCLCR_LCWAY_SHIFT                  (22U)
/*! LCWAY - Line Command Way */
#define LMEM_PCCLCR_LCWAY(x)                     (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_LCWAY_SHIFT)) & LMEM_PCCLCR_LCWAY_MASK)

#define LMEM_PCCLCR_LCMD_MASK                    (0x3000000U)
#define LMEM_PCCLCR_LCMD_SHIFT                   (24U)
/*! LCMD - Line Command
 *  0b00..Search and read or write
 *  0b01..Invalidate
 *  0b10..Push
 *  0b11..Clear
 */
#define LMEM_PCCLCR_LCMD(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_LCMD_SHIFT)) & LMEM_PCCLCR_LCMD_MASK)

#define LMEM_PCCLCR_LADSEL_MASK                  (0x4000000U)
#define LMEM_PCCLCR_LADSEL_SHIFT                 (26U)
/*! LADSEL - Line Address Select
 *  0b0..Cache address
 *  0b1..Physical address
 */
#define LMEM_PCCLCR_LADSEL(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_LADSEL_SHIFT)) & LMEM_PCCLCR_LADSEL_MASK)

#define LMEM_PCCLCR_LACC_MASK                    (0x8000000U)
#define LMEM_PCCLCR_LACC_SHIFT                   (27U)
/*! LACC - Line access type
 *  0b0..Read
 *  0b1..Write
 */
#define LMEM_PCCLCR_LACC(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCLCR_LACC_SHIFT)) & LMEM_PCCLCR_LACC_MASK)
/*! @} */

/*! @name PCCSAR - Cache search address register */
/*! @{ */

#define LMEM_PCCSAR_LGO_MASK                     (0x1U)
#define LMEM_PCCSAR_LGO_SHIFT                    (0U)
/*! LGO - Initiate Cache Line Command
 *  0b0..Write: no effect. Read: no line command active.
 *  0b1..Write: initiate line command indicated by bits CLCR[27:24]. Read: line command active.
 */
#define LMEM_PCCSAR_LGO(x)                       (((uint32_t)(((uint32_t)(x)) << LMEM_PCCSAR_LGO_SHIFT)) & LMEM_PCCSAR_LGO_MASK)

#define LMEM_PCCSAR_PHYADDR_MASK                 (0xFFFFFFFCU)
#define LMEM_PCCSAR_PHYADDR_SHIFT                (2U)
/*! PHYADDR - Physical Address */
#define LMEM_PCCSAR_PHYADDR(x)                   (((uint32_t)(((uint32_t)(x)) << LMEM_PCCSAR_PHYADDR_SHIFT)) & LMEM_PCCSAR_PHYADDR_MASK)
/*! @} */

/*! @name PCCCVR - Cache read/write value register */
/*! @{ */

#define LMEM_PCCCVR_DATA_MASK                    (0xFFFFFFFFU)
#define LMEM_PCCCVR_DATA_SHIFT                   (0U)
/*! DATA - Cache read/write Data */
#define LMEM_PCCCVR_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCVR_DATA_SHIFT)) & LMEM_PCCCVR_DATA_MASK)
/*! @} */

/*! @name PCCRMR - Cache regions mode register */
/*! @{ */

#define LMEM_PCCRMR_R15_MASK                     (0x3U)
#define LMEM_PCCRMR_R15_SHIFT                    (0U)
/*! R15 - Region 15 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R15(x)                       (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R15_SHIFT)) & LMEM_PCCRMR_R15_MASK)

#define LMEM_PCCRMR_R14_MASK                     (0xCU)
#define LMEM_PCCRMR_R14_SHIFT                    (2U)
/*! R14 - Region 14 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R14(x)                       (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R14_SHIFT)) & LMEM_PCCRMR_R14_MASK)

#define LMEM_PCCRMR_R13_MASK                     (0x30U)
#define LMEM_PCCRMR_R13_SHIFT                    (4U)
/*! R13 - Region 13 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R13(x)                       (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R13_SHIFT)) & LMEM_PCCRMR_R13_MASK)

#define LMEM_PCCRMR_R12_MASK                     (0xC0U)
#define LMEM_PCCRMR_R12_SHIFT                    (6U)
/*! R12 - Region 12 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R12(x)                       (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R12_SHIFT)) & LMEM_PCCRMR_R12_MASK)

#define LMEM_PCCRMR_R11_MASK                     (0x300U)
#define LMEM_PCCRMR_R11_SHIFT                    (8U)
/*! R11 - Region 11 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R11(x)                       (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R11_SHIFT)) & LMEM_PCCRMR_R11_MASK)

#define LMEM_PCCRMR_R10_MASK                     (0xC00U)
#define LMEM_PCCRMR_R10_SHIFT                    (10U)
/*! R10 - Region 10 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R10(x)                       (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R10_SHIFT)) & LMEM_PCCRMR_R10_MASK)

#define LMEM_PCCRMR_R9_MASK                      (0x3000U)
#define LMEM_PCCRMR_R9_SHIFT                     (12U)
/*! R9 - Region 9 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R9(x)                        (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R9_SHIFT)) & LMEM_PCCRMR_R9_MASK)

#define LMEM_PCCRMR_R8_MASK                      (0xC000U)
#define LMEM_PCCRMR_R8_SHIFT                     (14U)
/*! R8 - Region 8 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R8(x)                        (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R8_SHIFT)) & LMEM_PCCRMR_R8_MASK)

#define LMEM_PCCRMR_R7_MASK                      (0x30000U)
#define LMEM_PCCRMR_R7_SHIFT                     (16U)
/*! R7 - Region 7 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R7(x)                        (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R7_SHIFT)) & LMEM_PCCRMR_R7_MASK)

#define LMEM_PCCRMR_R6_MASK                      (0xC0000U)
#define LMEM_PCCRMR_R6_SHIFT                     (18U)
/*! R6 - Region 6 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R6(x)                        (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R6_SHIFT)) & LMEM_PCCRMR_R6_MASK)

#define LMEM_PCCRMR_R5_MASK                      (0x300000U)
#define LMEM_PCCRMR_R5_SHIFT                     (20U)
/*! R5 - Region 5 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R5(x)                        (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R5_SHIFT)) & LMEM_PCCRMR_R5_MASK)

#define LMEM_PCCRMR_R4_MASK                      (0xC00000U)
#define LMEM_PCCRMR_R4_SHIFT                     (22U)
/*! R4 - Region 4 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R4(x)                        (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R4_SHIFT)) & LMEM_PCCRMR_R4_MASK)

#define LMEM_PCCRMR_R3_MASK                      (0x3000000U)
#define LMEM_PCCRMR_R3_SHIFT                     (24U)
/*! R3 - Region 3 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R3(x)                        (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R3_SHIFT)) & LMEM_PCCRMR_R3_MASK)

#define LMEM_PCCRMR_R2_MASK                      (0xC000000U)
#define LMEM_PCCRMR_R2_SHIFT                     (26U)
/*! R2 - Region 2 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R2(x)                        (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R2_SHIFT)) & LMEM_PCCRMR_R2_MASK)

#define LMEM_PCCRMR_R1_MASK                      (0x30000000U)
#define LMEM_PCCRMR_R1_SHIFT                     (28U)
/*! R1 - Region 1 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R1(x)                        (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R1_SHIFT)) & LMEM_PCCRMR_R1_MASK)

#define LMEM_PCCRMR_R0_MASK                      (0xC0000000U)
#define LMEM_PCCRMR_R0_SHIFT                     (30U)
/*! R0 - Region 0 mode
 *  0b00..Non-cacheable
 *  0b01..Non-cacheable
 *  0b10..Write-through
 *  0b11..Write-back
 */
#define LMEM_PCCRMR_R0(x)                        (((uint32_t)(((uint32_t)(x)) << LMEM_PCCRMR_R0_SHIFT)) & LMEM_PCCRMR_R0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LMEM_Register_Masks */


/*!
 * @}
 */ /* end of group LMEM_Peripheral_Access_Layer */


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


#endif  /* PERI_LMEM_H_ */

