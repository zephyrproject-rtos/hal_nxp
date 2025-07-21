/*
** ###################################################################
**     Processors:          MKE12Z512VLH9
**                          MKE12Z512VLL9
**                          MKE13Z512VLH9
**                          MKE13Z512VLL9
**                          MKE17Z512VLH9
**                          MKE17Z512VLL9
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FTFE
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-03-01)
**         Initial version.
**     - rev. 2.0 (2023-10-08)
**         Based on Rev.1 RM.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FTFE.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FTFE
 *
 * CMSIS Peripheral Access Layer for FTFE
 */

#if !defined(PERI_FTFE_H_)
#define PERI_FTFE_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE12Z512VLH9) || defined(CPU_MKE12Z512VLL9))
#include "MKE12Z9_COMMON.h"
#elif (defined(CPU_MKE13Z512VLH9) || defined(CPU_MKE13Z512VLL9))
#include "MKE13Z9_COMMON.h"
#elif (defined(CPU_MKE17Z512VLH9) || defined(CPU_MKE17Z512VLL9))
#include "MKE17Z9_COMMON.h"
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
   -- FTFE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFE_Peripheral_Access_Layer FTFE Peripheral Access Layer
 * @{
 */

/** FTFE - Register Layout Typedef */
typedef struct {
  __IO uint8_t FSTAT;                              /**< Flash Status Register, offset: 0x0 */
  __IO uint8_t FCNFG;                              /**< Flash Configuration Register, offset: 0x1 */
  __I  uint8_t FSEC;                               /**< Flash Security Register, offset: 0x2 */
  __I  uint8_t FOPT;                               /**< Flash Option Register, offset: 0x3 */
  __IO uint8_t FCCOB3;                             /**< Flash Common Command Object Registers, offset: 0x4 */
  __IO uint8_t FCCOB2;                             /**< Flash Common Command Object Registers, offset: 0x5 */
  __IO uint8_t FCCOB1;                             /**< Flash Common Command Object Registers, offset: 0x6 */
  __IO uint8_t FCCOB0;                             /**< Flash Common Command Object Registers, offset: 0x7 */
  __IO uint8_t FCCOB7;                             /**< Flash Common Command Object Registers, offset: 0x8 */
  __IO uint8_t FCCOB6;                             /**< Flash Common Command Object Registers, offset: 0x9 */
  __IO uint8_t FCCOB5;                             /**< Flash Common Command Object Registers, offset: 0xA */
  __IO uint8_t FCCOB4;                             /**< Flash Common Command Object Registers, offset: 0xB */
  __IO uint8_t FCCOBB;                             /**< Flash Common Command Object Registers, offset: 0xC */
  __IO uint8_t FCCOBA;                             /**< Flash Common Command Object Registers, offset: 0xD */
  __IO uint8_t FCCOB9;                             /**< Flash Common Command Object Registers, offset: 0xE */
  __IO uint8_t FCCOB8;                             /**< Flash Common Command Object Registers, offset: 0xF */
  __IO uint8_t FPROT3;                             /**< Program Flash Protection Registers, offset: 0x10 */
  __IO uint8_t FPROT2;                             /**< Program Flash Protection Registers, offset: 0x11 */
  __IO uint8_t FPROT1;                             /**< Program Flash Protection Registers, offset: 0x12 */
  __IO uint8_t FPROT0;                             /**< Program Flash Protection Registers, offset: 0x13 */
       uint8_t RESERVED_0[26];
  __IO uint8_t FERSTAT;                            /**< Flash Error Status Register, offset: 0x2E */
  __IO uint8_t FERCNFG;                            /**< Flash Error Configuration Register, offset: 0x2F */
} FTFE_Type;

/* ----------------------------------------------------------------------------
   -- FTFE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFE_Register_Masks FTFE Register Masks
 * @{
 */

/*! @name FSTAT - Flash Status Register */
/*! @{ */

#define FTFE_FSTAT_MGSTAT0_MASK                  (0x1U)
#define FTFE_FSTAT_MGSTAT0_SHIFT                 (0U)
/*! MGSTAT0 - Memory Controller Command Completion Status Flag */
#define FTFE_FSTAT_MGSTAT0(x)                    (((uint8_t)(((uint8_t)(x)) << FTFE_FSTAT_MGSTAT0_SHIFT)) & FTFE_FSTAT_MGSTAT0_MASK)

#define FTFE_FSTAT_FPVIOL_MASK                   (0x10U)
#define FTFE_FSTAT_FPVIOL_SHIFT                  (4U)
/*! FPVIOL - Flash Protection Violation Flag
 *  0b0..No protection violation detected
 *  0b1..Protection violation detected
 */
#define FTFE_FSTAT_FPVIOL(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FSTAT_FPVIOL_SHIFT)) & FTFE_FSTAT_FPVIOL_MASK)

#define FTFE_FSTAT_ACCERR_MASK                   (0x20U)
#define FTFE_FSTAT_ACCERR_SHIFT                  (5U)
/*! ACCERR - Flash Access Error Flag
 *  0b0..No access error detected
 *  0b1..Access error detected
 */
#define FTFE_FSTAT_ACCERR(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FSTAT_ACCERR_SHIFT)) & FTFE_FSTAT_ACCERR_MASK)

#define FTFE_FSTAT_RDCOLERR_MASK                 (0x40U)
#define FTFE_FSTAT_RDCOLERR_SHIFT                (6U)
/*! RDCOLERR - FTFE Read Collision Error Flag
 *  0b0..No collision error detected
 *  0b1..Collision error detected
 */
#define FTFE_FSTAT_RDCOLERR(x)                   (((uint8_t)(((uint8_t)(x)) << FTFE_FSTAT_RDCOLERR_SHIFT)) & FTFE_FSTAT_RDCOLERR_MASK)

#define FTFE_FSTAT_CCIF_MASK                     (0x80U)
#define FTFE_FSTAT_CCIF_SHIFT                    (7U)
/*! CCIF - Command Complete Interrupt Flag
 *  0b0..FTFE command in progress
 *  0b1..FTFE command has completed
 */
#define FTFE_FSTAT_CCIF(x)                       (((uint8_t)(((uint8_t)(x)) << FTFE_FSTAT_CCIF_SHIFT)) & FTFE_FSTAT_CCIF_MASK)
/*! @} */

/*! @name FCNFG - Flash Configuration Register */
/*! @{ */

#define FTFE_FCNFG_EEERDY_MASK                   (0x1U)
#define FTFE_FCNFG_EEERDY_SHIFT                  (0U)
/*! EEERDY - EEERDY
 *  0b0..See RAMRDY for availability of programming acceleration RAM
 *  0b1..Reserved
 */
#define FTFE_FCNFG_EEERDY(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCNFG_EEERDY_SHIFT)) & FTFE_FCNFG_EEERDY_MASK)

#define FTFE_FCNFG_RAMRDY_MASK                   (0x2U)
#define FTFE_FCNFG_RAMRDY_SHIFT                  (1U)
/*! RAMRDY - RAM Ready
 *  0b0..Programming acceleration RAM is not available
 *  0b1..Programming acceleration RAM is available
 */
#define FTFE_FCNFG_RAMRDY(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCNFG_RAMRDY_SHIFT)) & FTFE_FCNFG_RAMRDY_MASK)

#define FTFE_FCNFG_PFLSH_MASK                    (0x4U)
#define FTFE_FCNFG_PFLSH_SHIFT                   (2U)
/*! PFLSH - This bit is reserved and always has the value 0. */
#define FTFE_FCNFG_PFLSH(x)                      (((uint8_t)(((uint8_t)(x)) << FTFE_FCNFG_PFLSH_SHIFT)) & FTFE_FCNFG_PFLSH_MASK)

#define FTFE_FCNFG_SWAP_MASK                     (0x8U)
#define FTFE_FCNFG_SWAP_SHIFT                    (3U)
/*! SWAP - Swap
 *  0b0..Program flash 0 block is located at relative address 0x0000
 *  0b1..Program flash 1 block is located at relative address 0x0000
 */
#define FTFE_FCNFG_SWAP(x)                       (((uint8_t)(((uint8_t)(x)) << FTFE_FCNFG_SWAP_SHIFT)) & FTFE_FCNFG_SWAP_MASK)

#define FTFE_FCNFG_ERSSUSP_MASK                  (0x10U)
#define FTFE_FCNFG_ERSSUSP_SHIFT                 (4U)
/*! ERSSUSP - Erase Suspend
 *  0b0..No suspend requested
 *  0b1..Suspend the current Erase Flash Sector command execution
 */
#define FTFE_FCNFG_ERSSUSP(x)                    (((uint8_t)(((uint8_t)(x)) << FTFE_FCNFG_ERSSUSP_SHIFT)) & FTFE_FCNFG_ERSSUSP_MASK)

#define FTFE_FCNFG_ERSAREQ_MASK                  (0x20U)
#define FTFE_FCNFG_ERSAREQ_SHIFT                 (5U)
/*! ERSAREQ - Erase All Request
 *  0b0..No request or request complete
 *  0b1..Request to: 1) run the Erase All Blocks command, 2) verify the erased state, 3) program the security byte
 *       in the Flash Configuration Field to the unsecure state, and 4) release MCU security by setting the
 *       FSEC[SEC] field to the unsecure state
 */
#define FTFE_FCNFG_ERSAREQ(x)                    (((uint8_t)(((uint8_t)(x)) << FTFE_FCNFG_ERSAREQ_SHIFT)) & FTFE_FCNFG_ERSAREQ_MASK)

#define FTFE_FCNFG_RDCOLLIE_MASK                 (0x40U)
#define FTFE_FCNFG_RDCOLLIE_SHIFT                (6U)
/*! RDCOLLIE - Read Collision Error Interrupt Enable
 *  0b0..Read collision error interrupt disabled
 *  0b1..Read collision error interrupt enabled. An interrupt request is generated whenever an FTFE read collision
 *       error is detected (see the description of FSTAT[RDCOLERR]).
 */
#define FTFE_FCNFG_RDCOLLIE(x)                   (((uint8_t)(((uint8_t)(x)) << FTFE_FCNFG_RDCOLLIE_SHIFT)) & FTFE_FCNFG_RDCOLLIE_MASK)

#define FTFE_FCNFG_CCIE_MASK                     (0x80U)
#define FTFE_FCNFG_CCIE_SHIFT                    (7U)
/*! CCIE - Command Complete Interrupt Enable
 *  0b0..Command complete interrupt disabled
 *  0b1..Command complete interrupt enabled. An interrupt request is generated whenever the FSTAT[CCIF] flag is set.
 */
#define FTFE_FCNFG_CCIE(x)                       (((uint8_t)(((uint8_t)(x)) << FTFE_FCNFG_CCIE_SHIFT)) & FTFE_FCNFG_CCIE_MASK)
/*! @} */

/*! @name FSEC - Flash Security Register */
/*! @{ */

#define FTFE_FSEC_SEC_MASK                       (0x3U)
#define FTFE_FSEC_SEC_SHIFT                      (0U)
/*! SEC - Flash Security
 *  0b00..MCU security status is secure
 *  0b01..MCU security status is secure
 *  0b10..MCU security status is unsecure (The standard shipping condition of the FTFE is unsecure.)
 *  0b11..MCU security status is secure
 */
#define FTFE_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x)) << FTFE_FSEC_SEC_SHIFT)) & FTFE_FSEC_SEC_MASK)

#define FTFE_FSEC_FSLACC_MASK                    (0xCU)
#define FTFE_FSEC_FSLACC_SHIFT                   (2U)
/*! FSLACC - Factory Security Level Access Code
 *  0b00..Factory access granted
 *  0b01..Factory access denied
 *  0b10..Factory access denied
 *  0b11..Factory access granted
 */
#define FTFE_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x)) << FTFE_FSEC_FSLACC_SHIFT)) & FTFE_FSEC_FSLACC_MASK)

#define FTFE_FSEC_MEEN_MASK                      (0x30U)
#define FTFE_FSEC_MEEN_SHIFT                     (4U)
/*! MEEN - Mass Erase Enable Bits
 *  0b00..Mass erase is enabled
 *  0b01..Mass erase is enabled
 *  0b10..Mass erase is disabled
 *  0b11..Mass erase is enabled
 */
#define FTFE_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_FSEC_MEEN_SHIFT)) & FTFE_FSEC_MEEN_MASK)

#define FTFE_FSEC_KEYEN_MASK                     (0xC0U)
#define FTFE_FSEC_KEYEN_SHIFT                    (6U)
/*! KEYEN - Backdoor Key Security Enable
 *  0b00..Backdoor key access disabled
 *  0b01..Backdoor key access disabled (preferred KEYEN state to disable backdoor key access)
 *  0b10..Backdoor key access enabled
 *  0b11..Backdoor key access disabled
 */
#define FTFE_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x)) << FTFE_FSEC_KEYEN_SHIFT)) & FTFE_FSEC_KEYEN_MASK)
/*! @} */

/*! @name FOPT - Flash Option Register */
/*! @{ */

#define FTFE_FOPT_OPT_MASK                       (0xFFU)
#define FTFE_FOPT_OPT_SHIFT                      (0U)
/*! OPT - Nonvolatile Option */
#define FTFE_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x)) << FTFE_FOPT_OPT_SHIFT)) & FTFE_FOPT_OPT_MASK)
/*! @} */

/*! @name FCCOB3 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB3_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB3_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFE_FCCOB3_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB3_CCOBn_SHIFT)) & FTFE_FCCOB3_CCOBn_MASK)
/*! @} */

/*! @name FCCOB2 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB2_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB2_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFE_FCCOB2_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB2_CCOBn_SHIFT)) & FTFE_FCCOB2_CCOBn_MASK)
/*! @} */

/*! @name FCCOB1 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB1_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB1_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFE_FCCOB1_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB1_CCOBn_SHIFT)) & FTFE_FCCOB1_CCOBn_MASK)
/*! @} */

/*! @name FCCOB0 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB0_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB0_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFE_FCCOB0_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB0_CCOBn_SHIFT)) & FTFE_FCCOB0_CCOBn_MASK)
/*! @} */

/*! @name FCCOB7 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB7_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB7_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFE_FCCOB7_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB7_CCOBn_SHIFT)) & FTFE_FCCOB7_CCOBn_MASK)
/*! @} */

/*! @name FCCOB6 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB6_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB6_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFE_FCCOB6_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB6_CCOBn_SHIFT)) & FTFE_FCCOB6_CCOBn_MASK)
/*! @} */

/*! @name FCCOB5 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB5_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB5_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFE_FCCOB5_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB5_CCOBn_SHIFT)) & FTFE_FCCOB5_CCOBn_MASK)
/*! @} */

/*! @name FCCOB4 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB4_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB4_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFE_FCCOB4_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB4_CCOBn_SHIFT)) & FTFE_FCCOB4_CCOBn_MASK)
/*! @} */

/*! @name FCCOBB - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOBB_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOBB_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFE_FCCOBB_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOBB_CCOBn_SHIFT)) & FTFE_FCCOBB_CCOBn_MASK)
/*! @} */

/*! @name FCCOBA - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOBA_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOBA_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFE_FCCOBA_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOBA_CCOBn_SHIFT)) & FTFE_FCCOBA_CCOBn_MASK)
/*! @} */

/*! @name FCCOB9 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB9_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB9_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFE_FCCOB9_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB9_CCOBn_SHIFT)) & FTFE_FCCOB9_CCOBn_MASK)
/*! @} */

/*! @name FCCOB8 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB8_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB8_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFE_FCCOB8_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB8_CCOBn_SHIFT)) & FTFE_FCCOB8_CCOBn_MASK)
/*! @} */

/*! @name FPROT3 - Program Flash Protection Registers */
/*! @{ */

#define FTFE_FPROT3_PROT_MASK                    (0xFFU)
#define FTFE_FPROT3_PROT_SHIFT                   (0U)
/*! PROT - Program Flash Region Protect
 *  0b00000000..Program flash region is protected.
 *  0b00000001..Program flash region is not protected
 */
#define FTFE_FPROT3_PROT(x)                      (((uint8_t)(((uint8_t)(x)) << FTFE_FPROT3_PROT_SHIFT)) & FTFE_FPROT3_PROT_MASK)
/*! @} */

/*! @name FPROT2 - Program Flash Protection Registers */
/*! @{ */

#define FTFE_FPROT2_PROT_MASK                    (0xFFU)
#define FTFE_FPROT2_PROT_SHIFT                   (0U)
/*! PROT - Program Flash Region Protect
 *  0b00000000..Program flash region is protected.
 *  0b00000001..Program flash region is not protected
 */
#define FTFE_FPROT2_PROT(x)                      (((uint8_t)(((uint8_t)(x)) << FTFE_FPROT2_PROT_SHIFT)) & FTFE_FPROT2_PROT_MASK)
/*! @} */

/*! @name FPROT1 - Program Flash Protection Registers */
/*! @{ */

#define FTFE_FPROT1_PROT_MASK                    (0xFFU)
#define FTFE_FPROT1_PROT_SHIFT                   (0U)
/*! PROT - Program Flash Region Protect
 *  0b00000000..Program flash region is protected.
 *  0b00000001..Program flash region is not protected
 */
#define FTFE_FPROT1_PROT(x)                      (((uint8_t)(((uint8_t)(x)) << FTFE_FPROT1_PROT_SHIFT)) & FTFE_FPROT1_PROT_MASK)
/*! @} */

/*! @name FPROT0 - Program Flash Protection Registers */
/*! @{ */

#define FTFE_FPROT0_PROT_MASK                    (0xFFU)
#define FTFE_FPROT0_PROT_SHIFT                   (0U)
/*! PROT - Program Flash Region Protect
 *  0b00000000..Program flash region is protected.
 *  0b00000001..Program flash region is not protected
 */
#define FTFE_FPROT0_PROT(x)                      (((uint8_t)(((uint8_t)(x)) << FTFE_FPROT0_PROT_SHIFT)) & FTFE_FPROT0_PROT_MASK)
/*! @} */

/*! @name FERSTAT - Flash Error Status Register */
/*! @{ */

#define FTFE_FERSTAT_DFDIF_MASK                  (0x2U)
#define FTFE_FERSTAT_DFDIF_SHIFT                 (1U)
/*! DFDIF - Double Bit Fault Detect Interrupt Flag
 *  0b0..Double bit fault not detected during a valid flash read access from the platform flash controller
 *  0b1..Double bit fault detected (or FERCNFG[FDFD] is set) during a valid flash read access from the platform flash controller
 */
#define FTFE_FERSTAT_DFDIF(x)                    (((uint8_t)(((uint8_t)(x)) << FTFE_FERSTAT_DFDIF_SHIFT)) & FTFE_FERSTAT_DFDIF_MASK)
/*! @} */

/*! @name FERCNFG - Flash Error Configuration Register */
/*! @{ */

#define FTFE_FERCNFG_DFDIE_MASK                  (0x2U)
#define FTFE_FERCNFG_DFDIE_SHIFT                 (1U)
/*! DFDIE - Double Bit Fault Detect Interrupt Enable
 *  0b0..Double bit fault detect interrupt disabled
 *  0b1..Double bit fault detect interrupt enabled. An interrupt request is generated whenever the FERSTAT[DFDIF] flag is set.
 */
#define FTFE_FERCNFG_DFDIE(x)                    (((uint8_t)(((uint8_t)(x)) << FTFE_FERCNFG_DFDIE_SHIFT)) & FTFE_FERCNFG_DFDIE_MASK)

#define FTFE_FERCNFG_FDFD_MASK                   (0x20U)
#define FTFE_FERCNFG_FDFD_SHIFT                  (5U)
/*! FDFD - Force Double Bit Fault Detect
 *  0b0..FERSTAT[DFDIF] sets only if a double bit fault is detected during read access from the platform flash controller
 *  0b1..FERSTAT[DFDIF] sets during any valid flash read access from the platform flash controller. An interrupt
 *       request is generated if the DFDIE bit is set.
 */
#define FTFE_FERCNFG_FDFD(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FERCNFG_FDFD_SHIFT)) & FTFE_FERCNFG_FDFD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FTFE_Register_Masks */


/*!
 * @}
 */ /* end of group FTFE_Peripheral_Access_Layer */


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


#endif  /* PERI_FTFE_H_ */

