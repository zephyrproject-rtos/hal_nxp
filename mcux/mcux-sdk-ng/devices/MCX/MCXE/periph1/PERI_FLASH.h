/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FLASH
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
 * @file PERI_FLASH.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for FLASH
 *
 * CMSIS Peripheral Access Layer for FLASH
 */

#if !defined(PERI_FLASH_H_)
#define PERI_FLASH_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
   -- FLASH Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_Peripheral_Access_Layer FLASH Peripheral Access Layer
 * @{
 */

/** FLASH - Size of Registers Arrays */
#define FLASH_UM_COUNT                            9u
#define FLASH_DATA_COUNT                          32u

/** FLASH - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration, offset: 0x0 */
  __IO uint32_t MCRS;                              /**< Module Configuration Status, offset: 0x4 */
  __I  uint32_t MCRE;                              /**< Extended Module Configuration, offset: 0x8 */
  __IO uint32_t CTL;                               /**< Module Control, offset: 0xC */
  __IO uint32_t ADR;                               /**< Address, offset: 0x10 */
  __I  uint32_t PEADR;                             /**< Program and Erase Address, offset: 0x14 */
       uint8_t RESERVED_0[56];
  __I  uint32_t SPELOCK;                           /**< Sector Program and Erase Hardware Lock, offset: 0x50 */
  __I  uint32_t SSPELOCK;                          /**< Super Sector Program and Erase Hardware Lock, offset: 0x54 */
       uint8_t RESERVED_1[24];
  __I  uint32_t XSPELOCK;                          /**< Express Sector Program and Erase Hardware Lock, offset: 0x70 */
  __I  uint32_t XSSPELOCK;                         /**< Express Super Sector Program and Erase Hardware Lock, offset: 0x74 */
       uint8_t RESERVED_2[24];
  __IO uint32_t TMD;                               /**< Test Mode Disable Password Check, offset: 0x90 */
  __IO uint32_t UT0;                               /**< UTest 0, offset: 0x94 */
  __IO uint32_t UM[FLASH_UM_COUNT];                /**< UMISRn, array offset: 0x98, array step: 0x4 */
  __IO uint32_t UM9;                               /**< UMISR9, offset: 0xBC */
       uint8_t RESERVED_3[16];
  __IO uint32_t UD0;                               /**< UTest Data 0, offset: 0xD0 */
  __IO uint32_t UD1;                               /**< UTest Data 1, offset: 0xD4 */
  __IO uint32_t UD2;                               /**< UTest Data 2, offset: 0xD8 */
  __IO uint32_t UD3;                               /**< UTest Data 3, offset: 0xDC */
  __IO uint32_t UD4;                               /**< UTest Data 4, offset: 0xE0 */
  __IO uint32_t UD5;                               /**< UTest Data 5, offset: 0xE4 */
  __IO uint32_t UA0;                               /**< UTest Address 0, offset: 0xE8 */
  __IO uint32_t UA1;                               /**< UTest Address 1, offset: 0xEC */
  __IO uint32_t XMCR;                              /**< Express Module Configuration, offset: 0xF0 */
  __I  uint32_t XPEADR;                            /**< Express Program Address, offset: 0xF4 */
       uint8_t RESERVED_4[8];
  __IO uint32_t DATA[FLASH_DATA_COUNT];            /**< Program Data, array offset: 0x100, array step: 0x4 */
} FLASH_Type;

/* ----------------------------------------------------------------------------
   -- FLASH Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_Register_Masks FLASH Register Masks
 * @{
 */

/*! @name MCR - Module Configuration */
/*! @{ */

#define FLASH_MCR_EHV_MASK                       (0x1U)
#define FLASH_MCR_EHV_SHIFT                      (0U)
/*! EHV - Enable High Voltage
 *  0b0..Flash memory is not enabled to perform a high voltage operation.
 *  0b1..Flash memory is enabled to perform a high voltage operation.
 */
#define FLASH_MCR_EHV(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_MCR_EHV_SHIFT)) & FLASH_MCR_EHV_MASK)

#define FLASH_MCR_ERS_MASK                       (0x10U)
#define FLASH_MCR_ERS_SHIFT                      (4U)
/*! ERS - Erase
 *  0b0..Flash memory not executing an erase sequence
 *  0b1..Flash memory executing an erase sequence
 */
#define FLASH_MCR_ERS(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_MCR_ERS_SHIFT)) & FLASH_MCR_ERS_MASK)

#define FLASH_MCR_ESS_MASK                       (0x20U)
#define FLASH_MCR_ESS_SHIFT                      (5U)
/*! ESS - Erase Size Select
 *  0b0..Flash memory erase is on a sector
 *  0b1..Flash memory erase is on a block
 */
#define FLASH_MCR_ESS(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_MCR_ESS_SHIFT)) & FLASH_MCR_ESS_MASK)

#define FLASH_MCR_PGM_MASK                       (0x100U)
#define FLASH_MCR_PGM_SHIFT                      (8U)
/*! PGM - Program
 *  0b0..Flash memory not executing a program sequence
 *  0b1..Flash memory executing a program sequence
 */
#define FLASH_MCR_PGM(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_MCR_PGM_SHIFT)) & FLASH_MCR_PGM_MASK)

#define FLASH_MCR_WDIE_MASK                      (0x1000U)
#define FLASH_MCR_WDIE_SHIFT                     (12U)
/*! WDIE - Watch Dog Interrupt Enable
 *  0b0..Watchdog interrupt not enabled
 *  0b1..Watchdog interrupt enabled
 */
#define FLASH_MCR_WDIE(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_MCR_WDIE_SHIFT)) & FLASH_MCR_WDIE_MASK)

#define FLASH_MCR_PECIE_MASK                     (0x8000U)
#define FLASH_MCR_PECIE_SHIFT                    (15U)
/*! PECIE - Program/Erase Complete Interrupt Enable
 *  0b0..Interrupt request not generated when MCRS[DONE] is 1
 *  0b1..Interrupt request generated when MCRS[DONE] is 1
 */
#define FLASH_MCR_PECIE(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_MCR_PECIE_SHIFT)) & FLASH_MCR_PECIE_MASK)

#define FLASH_MCR_PEID_MASK                      (0xFF0000U)
#define FLASH_MCR_PEID_SHIFT                     (16U)
/*! PEID - Program and Erase Master/Domain ID */
#define FLASH_MCR_PEID(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_MCR_PEID_SHIFT)) & FLASH_MCR_PEID_MASK)
/*! @} */

/*! @name MCRS - Module Configuration Status */
/*! @{ */

#define FLASH_MCRS_RE_MASK                       (0x1U)
#define FLASH_MCRS_RE_SHIFT                      (0U)
/*! RE - Reset Error
 *  0b0..Reset occurred without errors
 *  0b1..Reset error encountered
 */
#define FLASH_MCRS_RE(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_RE_SHIFT)) & FLASH_MCRS_RE_MASK)

#define FLASH_MCRS_TSPELOCK_MASK                 (0x100U)
#define FLASH_MCRS_TSPELOCK_SHIFT                (8U)
/*! TSPELOCK - UTest NVM Program and Erase Lock
 *  0b0..Corresponding sector not locked, and may be programmed or erased
 *  0b1..Corresponding sector protected from the program and erase sequences
 */
#define FLASH_MCRS_TSPELOCK(x)                   (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_TSPELOCK_SHIFT)) & FLASH_MCRS_TSPELOCK_MASK)

#define FLASH_MCRS_EPEG_MASK                     (0x200U)
#define FLASH_MCRS_EPEG_SHIFT                    (9U)
/*! EPEG - ECC Enabled Program/Erase Good
 *  0b0..Program or erase operation did not require ECC Enabled verifies.
 *  0b1..Program or erase operation required ECC Enabled verifies to pass.
 */
#define FLASH_MCRS_EPEG(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_EPEG_SHIFT)) & FLASH_MCRS_EPEG_MASK)

#define FLASH_MCRS_WDI_MASK                      (0x1000U)
#define FLASH_MCRS_WDI_SHIFT                     (12U)
/*! WDI - Watch Dog Interrupt
 *  0b0..Normal Operation, Watchdog Timer has not expired.
 *  0b1..Program Watchdog Timer has expired.
 */
#define FLASH_MCRS_WDI(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_WDI_SHIFT)) & FLASH_MCRS_WDI_MASK)

#define FLASH_MCRS_PEG_MASK                      (0x4000U)
#define FLASH_MCRS_PEG_SHIFT                     (14U)
/*! PEG - Program/Erase Good
 *  0b0..Program or erase operation failed
 *  0b1..Program or erase operation successful
 */
#define FLASH_MCRS_PEG(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_PEG_SHIFT)) & FLASH_MCRS_PEG_MASK)

#define FLASH_MCRS_DONE_MASK                     (0x8000U)
#define FLASH_MCRS_DONE_SHIFT                    (15U)
/*! DONE - State Machine Status
 *  0b0..Performing a high voltage operation
 *  0b1..Not executing a high voltage operation
 */
#define FLASH_MCRS_DONE(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_DONE_SHIFT)) & FLASH_MCRS_DONE_MASK)

#define FLASH_MCRS_PES_MASK                      (0x10000U)
#define FLASH_MCRS_PES_SHIFT                     (16U)
/*! PES - Program and Erase Sequence Error
 *  0b0..Program and erase sequence errors do not exist
 *  0b1..Previous program or erase sequence encountered an error
 */
#define FLASH_MCRS_PES(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_PES_SHIFT)) & FLASH_MCRS_PES_MASK)

#define FLASH_MCRS_PEP_MASK                      (0x20000U)
#define FLASH_MCRS_PEP_SHIFT                     (17U)
/*! PEP - Program and Erase Protection Error
 *  0b0..Program and erase protection errors do not exist
 *  0b1..Previous program or erase protection error encountered
 */
#define FLASH_MCRS_PEP(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_PEP_SHIFT)) & FLASH_MCRS_PEP_MASK)

#define FLASH_MCRS_RWE_MASK                      (0x100000U)
#define FLASH_MCRS_RWE_SHIFT                     (20U)
/*! RWE - Read-While-Write Event Error
 *  0b0..Reads occur normally
 *  0b1..RWW error occurred during a previous read
 */
#define FLASH_MCRS_RWE(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_RWE_SHIFT)) & FLASH_MCRS_RWE_MASK)

#define FLASH_MCRS_RRE_MASK                      (0x1000000U)
#define FLASH_MCRS_RRE_SHIFT                     (24U)
/*! RRE - Read Reference Error
 *  0b0..Reads occur without reference issues
 *  0b1..Previous read may be corrupted because of read reference being out of range
 */
#define FLASH_MCRS_RRE(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_RRE_SHIFT)) & FLASH_MCRS_RRE_MASK)

#define FLASH_MCRS_RVE_MASK                      (0x2000000U)
#define FLASH_MCRS_RVE_SHIFT                     (25U)
/*! RVE - Read Voltage Error
 *  0b0..Reads are occurring without voltage issues
 *  0b1..A previous read may have been corrupted due to read voltage being out of range
 */
#define FLASH_MCRS_RVE(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_RVE_SHIFT)) & FLASH_MCRS_RVE_MASK)

#define FLASH_MCRS_EEE_MASK                      (0x10000000U)
#define FLASH_MCRS_EEE_SHIFT                     (28U)
/*! EEE - EDC after ECC Error
 *  0b0..Reads are occurring without EDC after ECC mismatches
 *  0b1..Previous read may be corrupted based on ECC calculation errors
 */
#define FLASH_MCRS_EEE(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_EEE_SHIFT)) & FLASH_MCRS_EEE_MASK)

#define FLASH_MCRS_AEE_MASK                      (0x20000000U)
#define FLASH_MCRS_AEE_SHIFT                     (29U)
/*! AEE - Address Encode Error
 *  0b0..Reads are occurring without address encode mismatches
 *  0b1..Previous read may be corrupted based on address encode mismatch
 */
#define FLASH_MCRS_AEE(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_AEE_SHIFT)) & FLASH_MCRS_AEE_MASK)

#define FLASH_MCRS_SBC_MASK                      (0x40000000U)
#define FLASH_MCRS_SBC_SHIFT                     (30U)
/*! SBC - Single Bit Correction
 *  0b0..Reads occurring without corrections
 *  0b1..Single bit correction occurred during a previous read
 */
#define FLASH_MCRS_SBC(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_SBC_SHIFT)) & FLASH_MCRS_SBC_MASK)

#define FLASH_MCRS_EER_MASK                      (0x80000000U)
#define FLASH_MCRS_EER_SHIFT                     (31U)
/*! EER - ECC Event Error
 *  0b0..Reads occurring normally
 *  0b1..ECC error occurred during a previous read
 */
#define FLASH_MCRS_EER(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_MCRS_EER_SHIFT)) & FLASH_MCRS_EER_MASK)
/*! @} */

/*! @name MCRE - Extended Module Configuration */
/*! @{ */

#define FLASH_MCRE_n256K_MASK                    (0xC0U)
#define FLASH_MCRE_n256K_SHIFT                   (6U)
/*! n256K - Number of 256 KB Blocks
 *  0b00..Zero 256 KB blocks
 *  0b01..One 256 KB block
 *  0b10..Two 256 KB blocks
 *  0b11..Four 256 KB blocks
 */
#define FLASH_MCRE_n256K(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_MCRE_n256K_SHIFT)) & FLASH_MCRE_n256K_MASK)

#define FLASH_MCRE_n512K_MASK                    (0xC000U)
#define FLASH_MCRE_n512K_SHIFT                   (14U)
/*! n512K - Number of 512 KB Blocks
 *  0b00..Zero 512 KB blocks
 *  0b01..One 512 KB block
 *  0b10..Two 512 KB blocks
 *  0b11..Four 512 KB blocks
 */
#define FLASH_MCRE_n512K(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_MCRE_n512K_SHIFT)) & FLASH_MCRE_n512K_MASK)

#define FLASH_MCRE_n1M_MASK                      (0xE00000U)
#define FLASH_MCRE_n1M_SHIFT                     (21U)
/*! n1M - Number of 1 MB Blocks
 *  0b000..Zero 1 MB blocks
 *  0b001..One 1 MB block
 *  0b010..Two 1 MB blocks
 *  0b011..Three 1 MB blocks
 *  0b100..Four 1 MB blocks
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define FLASH_MCRE_n1M(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_MCRE_n1M_SHIFT)) & FLASH_MCRE_n1M_MASK)
/*! @} */

/*! @name CTL - Module Control */
/*! @{ */

#define FLASH_CTL_RWSC_MASK                      (0x1F00U)
#define FLASH_CTL_RWSC_SHIFT                     (8U)
/*! RWSC - Wait State Control
 *  0b00000..Reserved
 *  0b00001..One additional wait state is added.
 *  0b00010..Two additional wait states are added.
 *  0b00011..Three additional wait states are added.
 *  0b00100..Four additional wait states are added.
 *  0b00101..Five additional wait states are added.
 *  0b00110..Six additional wait states are added.
 *  0b00111..Seven additional wait states are added.
 *  0b01000..Eight additional wait states are added.
 *  0b01001..Reserved
 *  0b11111..Reserved
 */
#define FLASH_CTL_RWSC(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_CTL_RWSC_SHIFT)) & FLASH_CTL_RWSC_MASK)

#define FLASH_CTL_RWSL_MASK                      (0x8000U)
#define FLASH_CTL_RWSL_SHIFT                     (15U)
/*! RWSL - Read Wait State Lock
 *  0b0..RWSC not locked and available for writing
 *  0b1..RWSC locked and unavailable for writing
 */
#define FLASH_CTL_RWSL(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_CTL_RWSL_SHIFT)) & FLASH_CTL_RWSL_MASK)
/*! @} */

/*! @name ADR - Address */
/*! @{ */

#define FLASH_ADR_ADDR_MASK                      (0x7FFFEU)
#define FLASH_ADR_ADDR_SHIFT                     (1U)
/*! ADDR - Address */
#define FLASH_ADR_ADDR(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_ADR_ADDR_SHIFT)) & FLASH_ADR_ADDR_MASK)

#define FLASH_ADR_A0_MASK                        (0x80000U)
#define FLASH_ADR_A0_SHIFT                       (19U)
/*! A0 - Address Region 0
 *  0b0..Address captured or to be accessed is not from region 0
 *  0b1..Address captured or to be accessed is from region 0
 */
#define FLASH_ADR_A0(x)                          (((uint32_t)(((uint32_t)(x)) << FLASH_ADR_A0_SHIFT)) & FLASH_ADR_A0_MASK)

#define FLASH_ADR_A1_MASK                        (0x100000U)
#define FLASH_ADR_A1_SHIFT                       (20U)
/*! A1 - Address Region 1
 *  0b0..Address captured or to be accessed is not from region 1
 *  0b1..Address captured or to be accessed is from region 1
 */
#define FLASH_ADR_A1(x)                          (((uint32_t)(((uint32_t)(x)) << FLASH_ADR_A1_SHIFT)) & FLASH_ADR_A1_MASK)

#define FLASH_ADR_A2_MASK                        (0x200000U)
#define FLASH_ADR_A2_SHIFT                       (21U)
/*! A2 - Address Region 2
 *  0b0..Address captured or to be accessed is not from region 2
 *  0b1..Address captured or to be accessed is from region 2
 */
#define FLASH_ADR_A2(x)                          (((uint32_t)(((uint32_t)(x)) << FLASH_ADR_A2_SHIFT)) & FLASH_ADR_A2_MASK)

#define FLASH_ADR_A3_MASK                        (0x400000U)
#define FLASH_ADR_A3_SHIFT                       (22U)
/*! A3 - Address Region 3
 *  0b0..Address captured or to be accessed is not from region 3
 *  0b1..Address captured or to be accessed is from region 3
 */
#define FLASH_ADR_A3(x)                          (((uint32_t)(((uint32_t)(x)) << FLASH_ADR_A3_SHIFT)) & FLASH_ADR_A3_MASK)

#define FLASH_ADR_A4_MASK                        (0x800000U)
#define FLASH_ADR_A4_SHIFT                       (23U)
/*! A4 - Address Region 4
 *  0b0..Address captured or to be accessed is not from region 4
 *  0b1..Address captured or to be accessed is from region 4
 */
#define FLASH_ADR_A4(x)                          (((uint32_t)(((uint32_t)(x)) << FLASH_ADR_A4_SHIFT)) & FLASH_ADR_A4_MASK)

#define FLASH_ADR_A5_MASK                        (0x1000000U)
#define FLASH_ADR_A5_SHIFT                       (24U)
/*! A5 - Address Region 5
 *  0b0..Address captured or to be accessed is not from region 5
 *  0b1..Address captured or to be accessed is from region 5
 */
#define FLASH_ADR_A5(x)                          (((uint32_t)(((uint32_t)(x)) << FLASH_ADR_A5_SHIFT)) & FLASH_ADR_A5_MASK)

#define FLASH_ADR_SAD_MASK                       (0x80000000U)
#define FLASH_ADR_SAD_SHIFT                      (31U)
/*! SAD - UTest NVM Address
 *  0b0..Address captured or to be accessed is from the main array space
 *  0b1..Address captured or to be accessed is from the UTest NVM array space
 */
#define FLASH_ADR_SAD(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_ADR_SAD_SHIFT)) & FLASH_ADR_SAD_MASK)
/*! @} */

/*! @name PEADR - Program and Erase Address */
/*! @{ */

#define FLASH_PEADR_PEADDR_MASK                  (0x7FFE0U)
#define FLASH_PEADR_PEADDR_SHIFT                 (5U)
/*! PEADDR - Program and Erase Address */
#define FLASH_PEADR_PEADDR(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_PEADR_PEADDR_SHIFT)) & FLASH_PEADR_PEADDR_MASK)

#define FLASH_PEADR_PEA0_MASK                    (0x80000U)
#define FLASH_PEADR_PEA0_SHIFT                   (19U)
/*! PEA0 - Program and Erase Address Region 0
 *  0b0..Address accessed is not from region 0
 *  0b1..Address accessed is from region 0
 */
#define FLASH_PEADR_PEA0(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_PEADR_PEA0_SHIFT)) & FLASH_PEADR_PEA0_MASK)

#define FLASH_PEADR_PEA1_MASK                    (0x100000U)
#define FLASH_PEADR_PEA1_SHIFT                   (20U)
/*! PEA1 - Program and Erase Address Region 1
 *  0b0..Address accessed is not from region 1
 *  0b1..Address accessed is from region 1
 */
#define FLASH_PEADR_PEA1(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_PEADR_PEA1_SHIFT)) & FLASH_PEADR_PEA1_MASK)

#define FLASH_PEADR_PEA2_MASK                    (0x200000U)
#define FLASH_PEADR_PEA2_SHIFT                   (21U)
/*! PEA2 - Program and Erase Address Region 2
 *  0b0..Address accessed is not from region 2
 *  0b1..Address accessed is from region 2
 */
#define FLASH_PEADR_PEA2(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_PEADR_PEA2_SHIFT)) & FLASH_PEADR_PEA2_MASK)

#define FLASH_PEADR_PEA3_MASK                    (0x400000U)
#define FLASH_PEADR_PEA3_SHIFT                   (22U)
/*! PEA3 - Program and Erase Address Region 3
 *  0b0..Address accessed is not from region 3
 *  0b1..Address accessed is from region 3
 */
#define FLASH_PEADR_PEA3(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_PEADR_PEA3_SHIFT)) & FLASH_PEADR_PEA3_MASK)

#define FLASH_PEADR_PEA4_MASK                    (0x800000U)
#define FLASH_PEADR_PEA4_SHIFT                   (23U)
/*! PEA4 - Program and Erase Address Region 4
 *  0b0..Address accessed is not from region 4
 *  0b1..Adrress accessed is from region 4
 */
#define FLASH_PEADR_PEA4(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_PEADR_PEA4_SHIFT)) & FLASH_PEADR_PEA4_MASK)

#define FLASH_PEADR_PEA5_MASK                    (0x1000000U)
#define FLASH_PEADR_PEA5_SHIFT                   (24U)
/*! PEA5 - Program and Erase Address Region 5
 *  0b0..Address accessed is not from region 5
 *  0b1..Address accessed is from region 5
 */
#define FLASH_PEADR_PEA5(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_PEADR_PEA5_SHIFT)) & FLASH_PEADR_PEA5_MASK)

#define FLASH_PEADR_PEASAD_MASK                  (0x80000000U)
#define FLASH_PEADR_PEASAD_SHIFT                 (31U)
/*! PEASAD - UTest NVM Program and Erase Address
 *  0b0..Address accessed is from the main array space
 *  0b1..Address accessed is from the UTest NVM array space
 */
#define FLASH_PEADR_PEASAD(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_PEADR_PEASAD_SHIFT)) & FLASH_PEADR_PEASAD_MASK)
/*! @} */

/*! @name SPELOCK - Sector Program and Erase Hardware Lock */
/*! @{ */

#define FLASH_SPELOCK_SPELOCK_MASK               (0xFFFFFFFFU)
#define FLASH_SPELOCK_SPELOCK_SHIFT              (0U)
/*! SPELOCK - Sector Program and Erase Lock [31:0] */
#define FLASH_SPELOCK_SPELOCK(x)                 (((uint32_t)(((uint32_t)(x)) << FLASH_SPELOCK_SPELOCK_SHIFT)) & FLASH_SPELOCK_SPELOCK_MASK)
/*! @} */

/*! @name SSPELOCK - Super Sector Program and Erase Hardware Lock */
/*! @{ */

#define FLASH_SSPELOCK_SSPELOCK_MASK             (0xFFFU)
#define FLASH_SSPELOCK_SSPELOCK_SHIFT            (0U)
/*! SSPELOCK - Super Sector Program and Erase Lock [11:0] */
#define FLASH_SSPELOCK_SSPELOCK(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_SSPELOCK_SSPELOCK_SHIFT)) & FLASH_SSPELOCK_SSPELOCK_MASK)
/*! @} */

/*! @name XSPELOCK - Express Sector Program and Erase Hardware Lock */
/*! @{ */

#define FLASH_XSPELOCK_XSPELOCK_MASK             (0xFFFFFFFFU)
#define FLASH_XSPELOCK_XSPELOCK_SHIFT            (0U)
/*! XSPELOCK - Express Sector Program and Erase Lock [31:0] */
#define FLASH_XSPELOCK_XSPELOCK(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_XSPELOCK_XSPELOCK_SHIFT)) & FLASH_XSPELOCK_XSPELOCK_MASK)
/*! @} */

/*! @name XSSPELOCK - Express Super Sector Program and Erase Hardware Lock */
/*! @{ */

#define FLASH_XSSPELOCK_XSSPELOCK_MASK           (0xFFFU)
#define FLASH_XSSPELOCK_XSSPELOCK_SHIFT          (0U)
/*! XSSPELOCK - Express Super Sector Program and Erase Lock [11:0] */
#define FLASH_XSSPELOCK_XSSPELOCK(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_XSSPELOCK_XSSPELOCK_SHIFT)) & FLASH_XSSPELOCK_XSSPELOCK_MASK)
/*! @} */

/*! @name TMD - Test Mode Disable Password Check */
/*! @{ */

#define FLASH_TMD_PWD_MASK                       (0xFFFFFFFFU)
#define FLASH_TMD_PWD_SHIFT                      (0U)
/*! PWD - Password Challenge */
#define FLASH_TMD_PWD(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_TMD_PWD_SHIFT)) & FLASH_TMD_PWD_MASK)
/*! @} */

/*! @name UT0 - UTest 0 */
/*! @{ */

#define FLASH_UT0_AID_MASK                       (0x1U)
#define FLASH_UT0_AID_SHIFT                      (0U)
/*! AID - Array Integrity Done
 *  0b0..Array integrity check ongoing
 *  0b1..Array integrity check complete
 */
#define FLASH_UT0_AID(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_UT0_AID_SHIFT)) & FLASH_UT0_AID_MASK)

#define FLASH_UT0_AIE_MASK                       (0x2U)
#define FLASH_UT0_AIE_SHIFT                      (1U)
/*! AIE - Array Integrity Enable
 *  0b0..Array integrity checks not enabled
 *  0b1..Array integrity checks enabled
 */
#define FLASH_UT0_AIE(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_UT0_AIE_SHIFT)) & FLASH_UT0_AIE_MASK)

#define FLASH_UT0_AIS_MASK                       (0x4U)
#define FLASH_UT0_AIS_SHIFT                      (2U)
/*! AIS - Array Integrity Sequence
 *  0b0..Array integrity sequence is proprietary sequence
 *  0b1..Array integrity sequence is sequential
 */
#define FLASH_UT0_AIS(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_UT0_AIS_SHIFT)) & FLASH_UT0_AIS_MASK)

#define FLASH_UT0_MRV_MASK                       (0x10U)
#define FLASH_UT0_MRV_SHIFT                      (4U)
/*! MRV - Margin Read Value
 *  0b0..Zero's margin reads are requested.
 *  0b1..One's margin reads are requested.
 */
#define FLASH_UT0_MRV(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_UT0_MRV_SHIFT)) & FLASH_UT0_MRV_MASK)

#define FLASH_UT0_MRE_MASK                       (0x20U)
#define FLASH_UT0_MRE_SHIFT                      (5U)
/*! MRE - Margin Read Enable
 *  0b0..Margin reads are not enabled.
 *  0b1..Margin reads are enabled.
 */
#define FLASH_UT0_MRE(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_UT0_MRE_SHIFT)) & FLASH_UT0_MRE_MASK)

#define FLASH_UT0_AISUS_MASK                     (0x40U)
#define FLASH_UT0_AISUS_SHIFT                    (6U)
/*! AISUS - Array Integrity Suspend
 *  0b0..Array integrity sequence not suspended.
 *  0b1..Array integrity sequence is suspended.
 */
#define FLASH_UT0_AISUS(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_UT0_AISUS_SHIFT)) & FLASH_UT0_AISUS_MASK)

#define FLASH_UT0_AIBPE_MASK                     (0x100U)
#define FLASH_UT0_AIBPE_SHIFT                    (8U)
/*! AIBPE - Array Integrity Break Point Enable
 *  0b0..Array integrity breakpoints disabled
 *  0b1..Array integrity breakpoints enabled during array integrity checks
 */
#define FLASH_UT0_AIBPE(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_UT0_AIBPE_SHIFT)) & FLASH_UT0_AIBPE_MASK)

#define FLASH_UT0_NAIBP_MASK                     (0x200U)
#define FLASH_UT0_NAIBP_SHIFT                    (9U)
/*! NAIBP - Next Array Integrity Break Point
 *  0b0..Array integrity state machine is not currently at a breakpoint
 *  0b1..Array integrity state machine is at a breakpoint
 */
#define FLASH_UT0_NAIBP(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_UT0_NAIBP_SHIFT)) & FLASH_UT0_NAIBP_MASK)

#define FLASH_UT0_EIE_MASK                       (0x1000U)
#define FLASH_UT0_EIE_SHIFT                      (12U)
/*! EIE - ECC Data Input Enable
 *  0b0..ECC data input is disabled
 *  0b1..Data read is from UD0[EDATA] and UD2[EDATAC]
 */
#define FLASH_UT0_EIE(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_UT0_EIE_SHIFT)) & FLASH_UT0_EIE_MASK)

#define FLASH_UT0_EDIE_MASK                      (0x2000U)
#define FLASH_UT0_EDIE_SHIFT                     (13U)
/*! EDIE - EDC after ECC Data Input Enable
 *  0b0..EDC after ECC data input is disabled
 *  0b1..Data read is from UD3[EDDATA] and UD5[EDDATAC]
 */
#define FLASH_UT0_EDIE(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_UT0_EDIE_SHIFT)) & FLASH_UT0_EDIE_MASK)

#define FLASH_UT0_AEIE_MASK                      (0x4000U)
#define FLASH_UT0_AEIE_SHIFT                     (14U)
/*! AEIE - Address Encode Invert Enable
 *  0b0..Address encode invert is disabled
 *  0b1..Address encode values are inverted based on UA0[AEI]
 */
#define FLASH_UT0_AEIE(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_UT0_AEIE_SHIFT)) & FLASH_UT0_AEIE_MASK)

#define FLASH_UT0_RRIE_MASK                      (0x8000U)
#define FLASH_UT0_RRIE_SHIFT                     (15U)
/*! RRIE - Read Reference Input Enable
 *  0b0..Read reference input disabled
 *  0b1..Read reference input enabled
 */
#define FLASH_UT0_RRIE(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_UT0_RRIE_SHIFT)) & FLASH_UT0_RRIE_MASK)

#define FLASH_UT0_SBCE_MASK                      (0x40000000U)
#define FLASH_UT0_SBCE_SHIFT                     (30U)
/*! SBCE - Single Bit Correction Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define FLASH_UT0_SBCE(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_UT0_SBCE_SHIFT)) & FLASH_UT0_SBCE_MASK)

#define FLASH_UT0_UTE_MASK                       (0x80000000U)
#define FLASH_UT0_UTE_SHIFT                      (31U)
/*! UTE - UTest Enable
 *  0b0..U-Test mode is not enabled.
 *  0b1..U-Test mode is enabled.
 */
#define FLASH_UT0_UTE(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_UT0_UTE_SHIFT)) & FLASH_UT0_UTE_MASK)
/*! @} */

/*! @name UM - UMISRn */
/*! @{ */

#define FLASH_UM_MISR_MASK                       (0xFFFFFFFFU)
#define FLASH_UM_MISR_SHIFT                      (0U)
/*! MISR - MISR[31:0] */
#define FLASH_UM_MISR(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_UM_MISR_SHIFT)) & FLASH_UM_MISR_MASK)
/*! @} */

/*! @name UM9 - UMISR9 */
/*! @{ */

#define FLASH_UM9_MISR_MASK                      (0x1U)
#define FLASH_UM9_MISR_SHIFT                     (0U)
/*! MISR - MISR[288] */
#define FLASH_UM9_MISR(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_UM9_MISR_SHIFT)) & FLASH_UM9_MISR_MASK)
/*! @} */

/*! @name UD0 - UTest Data 0 */
/*! @{ */

#define FLASH_UD0_EDATA_MASK                     (0xFFFFFFFFU)
#define FLASH_UD0_EDATA_SHIFT                    (0U)
/*! EDATA - ECC Data [31:0] */
#define FLASH_UD0_EDATA(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_UD0_EDATA_SHIFT)) & FLASH_UD0_EDATA_MASK)
/*! @} */

/*! @name UD1 - UTest Data 1 */
/*! @{ */

#define FLASH_UD1_EDATA_MASK                     (0xFFFFFFFFU)
#define FLASH_UD1_EDATA_SHIFT                    (0U)
/*! EDATA - ECC Data [63:32] */
#define FLASH_UD1_EDATA(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_UD1_EDATA_SHIFT)) & FLASH_UD1_EDATA_MASK)
/*! @} */

/*! @name UD2 - UTest Data 2 */
/*! @{ */

#define FLASH_UD2_EDATAC_MASK                    (0xFFU)
#define FLASH_UD2_EDATAC_SHIFT                   (0U)
/*! EDATAC - ECC Data Check Bits [7:0] */
#define FLASH_UD2_EDATAC(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_UD2_EDATAC_SHIFT)) & FLASH_UD2_EDATAC_MASK)

#define FLASH_UD2_ED0_MASK                       (0x1000000U)
#define FLASH_UD2_ED0_SHIFT                      (24U)
/*! ED0 - ECC Logic Check Double Word 0 */
#define FLASH_UD2_ED0(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_UD2_ED0_SHIFT)) & FLASH_UD2_ED0_MASK)

#define FLASH_UD2_ED1_MASK                       (0x2000000U)
#define FLASH_UD2_ED1_SHIFT                      (25U)
/*! ED1 - ECC Logic Check Double Word 1 */
#define FLASH_UD2_ED1(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_UD2_ED1_SHIFT)) & FLASH_UD2_ED1_MASK)

#define FLASH_UD2_ED2_MASK                       (0x4000000U)
#define FLASH_UD2_ED2_SHIFT                      (26U)
/*! ED2 - ECC Logic Check Double Word 2 */
#define FLASH_UD2_ED2(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_UD2_ED2_SHIFT)) & FLASH_UD2_ED2_MASK)

#define FLASH_UD2_ED3_MASK                       (0x8000000U)
#define FLASH_UD2_ED3_SHIFT                      (27U)
/*! ED3 - ECC Logic Check Double Word 3 */
#define FLASH_UD2_ED3(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_UD2_ED3_SHIFT)) & FLASH_UD2_ED3_MASK)
/*! @} */

/*! @name UD3 - UTest Data 3 */
/*! @{ */

#define FLASH_UD3_EDDATA_MASK                    (0xFFFFFFFFU)
#define FLASH_UD3_EDDATA_SHIFT                   (0U)
/*! EDDATA - EDC After ECC Data [31:0] */
#define FLASH_UD3_EDDATA(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_UD3_EDDATA_SHIFT)) & FLASH_UD3_EDDATA_MASK)
/*! @} */

/*! @name UD4 - UTest Data 4 */
/*! @{ */

#define FLASH_UD4_EDDATA_MASK                    (0xFFFFFFFFU)
#define FLASH_UD4_EDDATA_SHIFT                   (0U)
/*! EDDATA - EDC After ECC Data [63:31] */
#define FLASH_UD4_EDDATA(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_UD4_EDDATA_SHIFT)) & FLASH_UD4_EDDATA_MASK)
/*! @} */

/*! @name UD5 - UTest Data 5 */
/*! @{ */

#define FLASH_UD5_EDDATAC_MASK                   (0xFFU)
#define FLASH_UD5_EDDATAC_SHIFT                  (0U)
/*! EDDATAC - EDC After ECC Data Check Bits [7:0] */
#define FLASH_UD5_EDDATAC(x)                     (((uint32_t)(((uint32_t)(x)) << FLASH_UD5_EDDATAC_SHIFT)) & FLASH_UD5_EDDATAC_MASK)

#define FLASH_UD5_EDD0_MASK                      (0x1000000U)
#define FLASH_UD5_EDD0_SHIFT                     (24U)
/*! EDD0 - EDC After ECC Logic Check Double Word 0 */
#define FLASH_UD5_EDD0(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_UD5_EDD0_SHIFT)) & FLASH_UD5_EDD0_MASK)

#define FLASH_UD5_EDD1_MASK                      (0x2000000U)
#define FLASH_UD5_EDD1_SHIFT                     (25U)
/*! EDD1 - EDC After ECC Logic Check Double Word 1 */
#define FLASH_UD5_EDD1(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_UD5_EDD1_SHIFT)) & FLASH_UD5_EDD1_MASK)

#define FLASH_UD5_EDD2_MASK                      (0x4000000U)
#define FLASH_UD5_EDD2_SHIFT                     (26U)
/*! EDD2 - EDC after ECC Logic Check Double Word 2 */
#define FLASH_UD5_EDD2(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_UD5_EDD2_SHIFT)) & FLASH_UD5_EDD2_MASK)

#define FLASH_UD5_EDD3_MASK                      (0x8000000U)
#define FLASH_UD5_EDD3_SHIFT                     (27U)
/*! EDD3 - EDC After ECC Logic Check Double Word 3 */
#define FLASH_UD5_EDD3(x)                        (((uint32_t)(((uint32_t)(x)) << FLASH_UD5_EDD3_SHIFT)) & FLASH_UD5_EDD3_MASK)
/*! @} */

/*! @name UA0 - UTest Address 0 */
/*! @{ */

#define FLASH_UA0_AEI_MASK                       (0xFFFFFFFFU)
#define FLASH_UA0_AEI_SHIFT                      (0U)
/*! AEI - Address Encode Invert [31:0] */
#define FLASH_UA0_AEI(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_UA0_AEI_SHIFT)) & FLASH_UA0_AEI_MASK)
/*! @} */

/*! @name UA1 - UTest Address 1 */
/*! @{ */

#define FLASH_UA1_AEI_MASK                       (0xFFFFFU)
#define FLASH_UA1_AEI_SHIFT                      (0U)
/*! AEI - Address Encode Invert [51:32] */
#define FLASH_UA1_AEI(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_UA1_AEI_SHIFT)) & FLASH_UA1_AEI_MASK)
/*! @} */

/*! @name XMCR - Express Module Configuration */
/*! @{ */

#define FLASH_XMCR_XEHV_MASK                     (0x1U)
#define FLASH_XMCR_XEHV_SHIFT                    (0U)
/*! XEHV - Express Enable High Voltage
 *  0b0..Flash memory is not enabled to perform an express high voltage operation.
 *  0b1..Flash memory is enabled to perform an express high voltage operation.
 */
#define FLASH_XMCR_XEHV(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_XMCR_XEHV_SHIFT)) & FLASH_XMCR_XEHV_MASK)

#define FLASH_XMCR_XPGM_MASK                     (0x100U)
#define FLASH_XMCR_XPGM_SHIFT                    (8U)
/*! XPGM - Express Program
 *  0b0..Flash memory not executing an express program sequence
 *  0b1..Flash memory executing an express program sequence
 */
#define FLASH_XMCR_XPGM(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_XMCR_XPGM_SHIFT)) & FLASH_XMCR_XPGM_MASK)

#define FLASH_XMCR_XEPEG_MASK                    (0x200U)
#define FLASH_XMCR_XEPEG_SHIFT                   (9U)
/*! XEPEG - Express ECC Enabled Program Good
 *  0b0..Program operation did not require ECC-enabled verifies
 *  0b1..Program operation required ECC-enabled verifies to pass
 */
#define FLASH_XMCR_XEPEG(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_XMCR_XEPEG_SHIFT)) & FLASH_XMCR_XEPEG_MASK)

#define FLASH_XMCR_XWDIE_MASK                    (0x800U)
#define FLASH_XMCR_XWDIE_SHIFT                   (11U)
/*! XWDIE - Express Watch Dog Interrupt Enable
 *  0b0..Express watchdog interrupt disabled
 *  0b1..Express watchdog interrupt enabled
 */
#define FLASH_XMCR_XWDIE(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_XMCR_XWDIE_SHIFT)) & FLASH_XMCR_XWDIE_MASK)

#define FLASH_XMCR_XWDI_MASK                     (0x1000U)
#define FLASH_XMCR_XWDI_SHIFT                    (12U)
/*! XWDI - Express Watch Dog Interrupt
 *  0b0..Normal Operation, Watchdog Timer has not expired.
 *  0b1..Express Program Watchdog Timer has expired.
 */
#define FLASH_XMCR_XWDI(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_XMCR_XWDI_SHIFT)) & FLASH_XMCR_XWDI_MASK)

#define FLASH_XMCR_XDOK_MASK                     (0x2000U)
#define FLASH_XMCR_XDOK_SHIFT                    (13U)
/*! XDOK - Express Data OK
 *  0b0..Flash memory not ready to accept writes to the DATA registers
 *  0b1..Writes to DATA registers allowed
 */
#define FLASH_XMCR_XDOK(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_XMCR_XDOK_SHIFT)) & FLASH_XMCR_XDOK_MASK)

#define FLASH_XMCR_XPEG_MASK                     (0x4000U)
#define FLASH_XMCR_XPEG_SHIFT                    (14U)
/*! XPEG - Express Program Good
 *  0b0..Program operation failed
 *  0b1..Program operation successful
 */
#define FLASH_XMCR_XPEG(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_XMCR_XPEG_SHIFT)) & FLASH_XMCR_XPEG_MASK)

#define FLASH_XMCR_XDONE_MASK                    (0x8000U)
#define FLASH_XMCR_XDONE_SHIFT                   (15U)
/*! XDONE - Express State Machine Status
 *  0b0..Executing an express program operation
 *  0b1..Not executing an express program operation
 */
#define FLASH_XMCR_XDONE(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_XMCR_XDONE_SHIFT)) & FLASH_XMCR_XDONE_MASK)

#define FLASH_XMCR_XPEID_MASK                    (0xFF0000U)
#define FLASH_XMCR_XPEID_SHIFT                   (16U)
/*! XPEID - Express Program Master/Domain ID */
#define FLASH_XMCR_XPEID(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_XMCR_XPEID_SHIFT)) & FLASH_XMCR_XPEID_MASK)
/*! @} */

/*! @name XPEADR - Express Program Address */
/*! @{ */

#define FLASH_XPEADR_XPEADDR_MASK                (0x7FFE0U)
#define FLASH_XPEADR_XPEADDR_SHIFT               (5U)
/*! XPEADDR - Express Program Address */
#define FLASH_XPEADR_XPEADDR(x)                  (((uint32_t)(((uint32_t)(x)) << FLASH_XPEADR_XPEADDR_SHIFT)) & FLASH_XPEADR_XPEADDR_MASK)

#define FLASH_XPEADR_XPEA0_MASK                  (0x80000U)
#define FLASH_XPEADR_XPEA0_SHIFT                 (19U)
/*! XPEA0 - Express Program Address Region 0
 *  0b0..Address accessed is not from region 0
 *  0b1..Address accessed is from region 0
 */
#define FLASH_XPEADR_XPEA0(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_XPEADR_XPEA0_SHIFT)) & FLASH_XPEADR_XPEA0_MASK)

#define FLASH_XPEADR_XPEA1_MASK                  (0x100000U)
#define FLASH_XPEADR_XPEA1_SHIFT                 (20U)
/*! XPEA1 - Express Program Address Region 1
 *  0b0..Address accessed is not from region 1
 *  0b1..Address accessed is from region 1
 */
#define FLASH_XPEADR_XPEA1(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_XPEADR_XPEA1_SHIFT)) & FLASH_XPEADR_XPEA1_MASK)

#define FLASH_XPEADR_XPEA2_MASK                  (0x200000U)
#define FLASH_XPEADR_XPEA2_SHIFT                 (21U)
/*! XPEA2 - Express Program Address Region 2
 *  0b0..Address accessed is not from region 2
 *  0b1..Address accessed is from region 2
 */
#define FLASH_XPEADR_XPEA2(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_XPEADR_XPEA2_SHIFT)) & FLASH_XPEADR_XPEA2_MASK)

#define FLASH_XPEADR_XPEA3_MASK                  (0x400000U)
#define FLASH_XPEADR_XPEA3_SHIFT                 (22U)
/*! XPEA3 - Express Program Address Region 3
 *  0b0..Address accessed is not from region 3
 *  0b1..Address accessed is from region 3
 */
#define FLASH_XPEADR_XPEA3(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_XPEADR_XPEA3_SHIFT)) & FLASH_XPEADR_XPEA3_MASK)

#define FLASH_XPEADR_XPEA4_MASK                  (0x800000U)
#define FLASH_XPEADR_XPEA4_SHIFT                 (23U)
/*! XPEA4 - Express Program Address Region 4
 *  0b0..Address accessed is not from region 4
 *  0b1..Address accessed is from region 4
 */
#define FLASH_XPEADR_XPEA4(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_XPEADR_XPEA4_SHIFT)) & FLASH_XPEADR_XPEA4_MASK)

#define FLASH_XPEADR_XPEA5_MASK                  (0x1000000U)
#define FLASH_XPEADR_XPEA5_SHIFT                 (24U)
/*! XPEA5 - Express Program Address Region 5
 *  0b0..Address accessed is not from region 5
 *  0b1..Address accessed is from region 5
 */
#define FLASH_XPEADR_XPEA5(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_XPEADR_XPEA5_SHIFT)) & FLASH_XPEADR_XPEA5_MASK)
/*! @} */

/*! @name DATA - Program Data */
/*! @{ */

#define FLASH_DATA_PDATA_MASK                    (0xFFFFFFFFU)
#define FLASH_DATA_PDATA_SHIFT                   (0U)
/*! PDATA - Program Data */
#define FLASH_DATA_PDATA(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_DATA_PDATA_SHIFT)) & FLASH_DATA_PDATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FLASH_Register_Masks */


/*!
 * @}
 */ /* end of group FLASH_Peripheral_Access_Layer */


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


#endif  /* PERI_FLASH_H_ */

