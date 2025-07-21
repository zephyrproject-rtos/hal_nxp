/*
** ###################################################################
**     Processors:          MKE14Z128VLH7
**                          MKE14Z128VLL7
**                          MKE14Z256VLH7
**                          MKE14Z256VLL7
**                          MKE15Z128VLH7
**                          MKE15Z128VLL7
**                          MKE15Z256VLH7
**                          MKE15Z256VLL7
**
**     Version:             rev. 7.0, 2024-10-29
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
**     - rev. 1.0 (2015-08-19)
**         Initial version.
**     - rev. 2.0 (2015-09-22)
**         Based on rev0final RDP, add PCC/TRGMUX.
**     - rev. 3.0 (2015-12-29)
**         Align LPFLL register names.
**     - rev. 4.0 (2016-02-19)
**         Based on rev1final RDP.
**     - rev. 5.0 (2016-08-02)
**         Based on rev1.x RDP.
**     - rev. 6.0 (2016-09-20)
**         Based on rev2 RDP.
**     - rev. 7.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FTFE.h
 * @version 7.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FTFE
 *
 * CMSIS Peripheral Access Layer for FTFE
 */

#if !defined(PERI_FTFE_H_)
#define PERI_FTFE_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE14Z128VLH7) || defined(CPU_MKE14Z128VLL7) || defined(CPU_MKE14Z256VLH7) || defined(CPU_MKE14Z256VLL7))
#include "MKE14Z7_COMMON.h"
#elif (defined(CPU_MKE15Z128VLH7) || defined(CPU_MKE15Z128VLL7) || defined(CPU_MKE15Z256VLH7) || defined(CPU_MKE15Z256VLL7))
#include "MKE15Z7_COMMON.h"
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
       uint8_t RESERVED_0[2];
  __IO uint8_t FEPROT;                             /**< EEPROM Protection Register, offset: 0x16 */
  __IO uint8_t FDPROT;                             /**< Data Flash Protection Register, offset: 0x17 */
  __I  uint8_t XACCH3;                             /**< Execute-only Access Registers, offset: 0x18 */
  __I  uint8_t XACCH2;                             /**< Execute-only Access Registers, offset: 0x19 */
  __I  uint8_t XACCH1;                             /**< Execute-only Access Registers, offset: 0x1A */
  __I  uint8_t XACCH0;                             /**< Execute-only Access Registers, offset: 0x1B */
  __I  uint8_t XACCL3;                             /**< Execute-only Access Registers, offset: 0x1C */
  __I  uint8_t XACCL2;                             /**< Execute-only Access Registers, offset: 0x1D */
  __I  uint8_t XACCL1;                             /**< Execute-only Access Registers, offset: 0x1E */
  __I  uint8_t XACCL0;                             /**< Execute-only Access Registers, offset: 0x1F */
  __I  uint8_t SACCH3;                             /**< Supervisor-only Access Registers, offset: 0x20 */
  __I  uint8_t SACCH2;                             /**< Supervisor-only Access Registers, offset: 0x21 */
  __I  uint8_t SACCH1;                             /**< Supervisor-only Access Registers, offset: 0x22 */
  __I  uint8_t SACCH0;                             /**< Supervisor-only Access Registers, offset: 0x23 */
  __I  uint8_t SACCL3;                             /**< Supervisor-only Access Registers, offset: 0x24 */
  __I  uint8_t SACCL2;                             /**< Supervisor-only Access Registers, offset: 0x25 */
  __I  uint8_t SACCL1;                             /**< Supervisor-only Access Registers, offset: 0x26 */
  __I  uint8_t SACCL0;                             /**< Supervisor-only Access Registers, offset: 0x27 */
  __I  uint8_t FACSS;                              /**< Flash Access Segment Size Register, offset: 0x28 */
       uint8_t RESERVED_1[2];
  __I  uint8_t FACSN;                              /**< Flash Access Segment Number Register, offset: 0x2B */
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
 *  0b0..FTFE command or EEPROM file system operation in progress
 *  0b1..FTFE command or EEPROM file system operation has completed
 */
#define FTFE_FSTAT_CCIF(x)                       (((uint8_t)(((uint8_t)(x)) << FTFE_FSTAT_CCIF_SHIFT)) & FTFE_FSTAT_CCIF_MASK)
/*! @} */

/*! @name FCNFG - Flash Configuration Register */
/*! @{ */

#define FTFE_FCNFG_EEERDY_MASK                   (0x1U)
#define FTFE_FCNFG_EEERDY_SHIFT                  (0U)
/*! EEERDY
 *  0b0..FlexRAM is not available for EEPROM operation
 *  0b1..FlexRAM is available for EEPROM operations where: reads from the FlexRAM return data previously written
 *       to the FlexRAM in EEPROM mode and writes launch an EEPROM operation to store the written data in the
 *       FlexRAM and EEPROM backup
 */
#define FTFE_FCNFG_EEERDY(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCNFG_EEERDY_SHIFT)) & FTFE_FCNFG_EEERDY_MASK)

#define FTFE_FCNFG_RAMRDY_MASK                   (0x2U)
#define FTFE_FCNFG_RAMRDY_SHIFT                  (1U)
/*! RAMRDY - RAM Ready
 *  0b0..FlexRAM is not available for traditional RAM access
 *  0b1..FlexRAM is available as traditional RAM only; writes to the FlexRAM do not trigger EEPROM operations
 */
#define FTFE_FCNFG_RAMRDY(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCNFG_RAMRDY_SHIFT)) & FTFE_FCNFG_RAMRDY_MASK)

#define FTFE_FCNFG_PFLSH_MASK                    (0x4U)
#define FTFE_FCNFG_PFLSH_SHIFT                   (2U)
/*! PFLSH - FTFE configuration
 *  0b0..FTFE configuration supports one program flash block and one FlexNVM block
 *  0b1..Reserved
 */
#define FTFE_FCNFG_PFLSH(x)                      (((uint8_t)(((uint8_t)(x)) << FTFE_FCNFG_PFLSH_SHIFT)) & FTFE_FCNFG_PFLSH_MASK)

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
 *  0b1..Request to: run the Erase All Blocks command, verify the erased state, program the security byte in the
 *       Flash Configuration Field to the unsecure state, and release MCU security by setting the FSEC[SEC] field to
 *       the unsecure state
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
#define FTFE_FCCOB3_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB3_CCOBn_SHIFT)) & FTFE_FCCOB3_CCOBn_MASK)
/*! @} */

/*! @name FCCOB2 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB2_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB2_CCOBn_SHIFT                  (0U)
#define FTFE_FCCOB2_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB2_CCOBn_SHIFT)) & FTFE_FCCOB2_CCOBn_MASK)
/*! @} */

/*! @name FCCOB1 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB1_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB1_CCOBn_SHIFT                  (0U)
#define FTFE_FCCOB1_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB1_CCOBn_SHIFT)) & FTFE_FCCOB1_CCOBn_MASK)
/*! @} */

/*! @name FCCOB0 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB0_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB0_CCOBn_SHIFT                  (0U)
#define FTFE_FCCOB0_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB0_CCOBn_SHIFT)) & FTFE_FCCOB0_CCOBn_MASK)
/*! @} */

/*! @name FCCOB7 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB7_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB7_CCOBn_SHIFT                  (0U)
#define FTFE_FCCOB7_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB7_CCOBn_SHIFT)) & FTFE_FCCOB7_CCOBn_MASK)
/*! @} */

/*! @name FCCOB6 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB6_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB6_CCOBn_SHIFT                  (0U)
#define FTFE_FCCOB6_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB6_CCOBn_SHIFT)) & FTFE_FCCOB6_CCOBn_MASK)
/*! @} */

/*! @name FCCOB5 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB5_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB5_CCOBn_SHIFT                  (0U)
#define FTFE_FCCOB5_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB5_CCOBn_SHIFT)) & FTFE_FCCOB5_CCOBn_MASK)
/*! @} */

/*! @name FCCOB4 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB4_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB4_CCOBn_SHIFT                  (0U)
#define FTFE_FCCOB4_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB4_CCOBn_SHIFT)) & FTFE_FCCOB4_CCOBn_MASK)
/*! @} */

/*! @name FCCOBB - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOBB_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOBB_CCOBn_SHIFT                  (0U)
#define FTFE_FCCOBB_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOBB_CCOBn_SHIFT)) & FTFE_FCCOBB_CCOBn_MASK)
/*! @} */

/*! @name FCCOBA - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOBA_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOBA_CCOBn_SHIFT                  (0U)
#define FTFE_FCCOBA_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOBA_CCOBn_SHIFT)) & FTFE_FCCOBA_CCOBn_MASK)
/*! @} */

/*! @name FCCOB9 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB9_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB9_CCOBn_SHIFT                  (0U)
#define FTFE_FCCOB9_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCCOB9_CCOBn_SHIFT)) & FTFE_FCCOB9_CCOBn_MASK)
/*! @} */

/*! @name FCCOB8 - Flash Common Command Object Registers */
/*! @{ */

#define FTFE_FCCOB8_CCOBn_MASK                   (0xFFU)
#define FTFE_FCCOB8_CCOBn_SHIFT                  (0U)
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

/*! @name FEPROT - EEPROM Protection Register */
/*! @{ */

#define FTFE_FEPROT_EPROT_MASK                   (0xFFU)
#define FTFE_FEPROT_EPROT_SHIFT                  (0U)
/*! EPROT - EEPROM Region Protect
 *  0b00000000..EEPROM region is protected
 *  0b00000001..EEPROM region is not protected
 */
#define FTFE_FEPROT_EPROT(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FEPROT_EPROT_SHIFT)) & FTFE_FEPROT_EPROT_MASK)
/*! @} */

/*! @name FDPROT - Data Flash Protection Register */
/*! @{ */

#define FTFE_FDPROT_DPROT_MASK                   (0xFFU)
#define FTFE_FDPROT_DPROT_SHIFT                  (0U)
/*! DPROT - Data Flash Region Protect
 *  0b00000000..Data Flash region is protected
 *  0b00000001..Data Flash region is not protected
 */
#define FTFE_FDPROT_DPROT(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FDPROT_DPROT_SHIFT)) & FTFE_FDPROT_DPROT_MASK)
/*! @} */

/*! @name XACCH3 - Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCH3_XA_MASK                      (0xFFU)
#define FTFE_XACCH3_XA_SHIFT                     (0U)
/*! XA - Execute-only access control
 *  0b00000000..Associated segment is accessible in execute mode only (as an instruction fetch)
 *  0b00000001..Associated segment is accessible as data or in execute mode
 */
#define FTFE_XACCH3_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCH3_XA_SHIFT)) & FTFE_XACCH3_XA_MASK)
/*! @} */

/*! @name XACCH2 - Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCH2_XA_MASK                      (0xFFU)
#define FTFE_XACCH2_XA_SHIFT                     (0U)
/*! XA - Execute-only access control
 *  0b00000000..Associated segment is accessible in execute mode only (as an instruction fetch)
 *  0b00000001..Associated segment is accessible as data or in execute mode
 */
#define FTFE_XACCH2_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCH2_XA_SHIFT)) & FTFE_XACCH2_XA_MASK)
/*! @} */

/*! @name XACCH1 - Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCH1_XA_MASK                      (0xFFU)
#define FTFE_XACCH1_XA_SHIFT                     (0U)
/*! XA - Execute-only access control
 *  0b00000000..Associated segment is accessible in execute mode only (as an instruction fetch)
 *  0b00000001..Associated segment is accessible as data or in execute mode
 */
#define FTFE_XACCH1_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCH1_XA_SHIFT)) & FTFE_XACCH1_XA_MASK)
/*! @} */

/*! @name XACCH0 - Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCH0_XA_MASK                      (0xFFU)
#define FTFE_XACCH0_XA_SHIFT                     (0U)
/*! XA - Execute-only access control
 *  0b00000000..Associated segment is accessible in execute mode only (as an instruction fetch)
 *  0b00000001..Associated segment is accessible as data or in execute mode
 */
#define FTFE_XACCH0_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCH0_XA_SHIFT)) & FTFE_XACCH0_XA_MASK)
/*! @} */

/*! @name XACCL3 - Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCL3_XA_MASK                      (0xFFU)
#define FTFE_XACCL3_XA_SHIFT                     (0U)
/*! XA - Execute-only access control
 *  0b00000000..Associated segment is accessible in execute mode only (as an instruction fetch)
 *  0b00000001..Associated segment is accessible as data or in execute mode
 */
#define FTFE_XACCL3_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCL3_XA_SHIFT)) & FTFE_XACCL3_XA_MASK)
/*! @} */

/*! @name XACCL2 - Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCL2_XA_MASK                      (0xFFU)
#define FTFE_XACCL2_XA_SHIFT                     (0U)
/*! XA - Execute-only access control
 *  0b00000000..Associated segment is accessible in execute mode only (as an instruction fetch)
 *  0b00000001..Associated segment is accessible as data or in execute mode
 */
#define FTFE_XACCL2_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCL2_XA_SHIFT)) & FTFE_XACCL2_XA_MASK)
/*! @} */

/*! @name XACCL1 - Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCL1_XA_MASK                      (0xFFU)
#define FTFE_XACCL1_XA_SHIFT                     (0U)
/*! XA - Execute-only access control
 *  0b00000000..Associated segment is accessible in execute mode only (as an instruction fetch)
 *  0b00000001..Associated segment is accessible as data or in execute mode
 */
#define FTFE_XACCL1_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCL1_XA_SHIFT)) & FTFE_XACCL1_XA_MASK)
/*! @} */

/*! @name XACCL0 - Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCL0_XA_MASK                      (0xFFU)
#define FTFE_XACCL0_XA_SHIFT                     (0U)
/*! XA - Execute-only access control
 *  0b00000000..Associated segment is accessible in execute mode only (as an instruction fetch)
 *  0b00000001..Associated segment is accessible as data or in execute mode
 */
#define FTFE_XACCL0_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCL0_XA_SHIFT)) & FTFE_XACCL0_XA_MASK)
/*! @} */

/*! @name SACCH3 - Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCH3_SA_MASK                      (0xFFU)
#define FTFE_SACCH3_SA_SHIFT                     (0U)
/*! SA - Supervisor-only access control
 *  0b00000000..Associated segment is accessible in supervisor mode only
 *  0b00000001..Associated segment is accessible in user or supervisor mode
 */
#define FTFE_SACCH3_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCH3_SA_SHIFT)) & FTFE_SACCH3_SA_MASK)
/*! @} */

/*! @name SACCH2 - Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCH2_SA_MASK                      (0xFFU)
#define FTFE_SACCH2_SA_SHIFT                     (0U)
/*! SA - Supervisor-only access control
 *  0b00000000..Associated segment is accessible in supervisor mode only
 *  0b00000001..Associated segment is accessible in user or supervisor mode
 */
#define FTFE_SACCH2_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCH2_SA_SHIFT)) & FTFE_SACCH2_SA_MASK)
/*! @} */

/*! @name SACCH1 - Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCH1_SA_MASK                      (0xFFU)
#define FTFE_SACCH1_SA_SHIFT                     (0U)
/*! SA - Supervisor-only access control
 *  0b00000000..Associated segment is accessible in supervisor mode only
 *  0b00000001..Associated segment is accessible in user or supervisor mode
 */
#define FTFE_SACCH1_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCH1_SA_SHIFT)) & FTFE_SACCH1_SA_MASK)
/*! @} */

/*! @name SACCH0 - Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCH0_SA_MASK                      (0xFFU)
#define FTFE_SACCH0_SA_SHIFT                     (0U)
/*! SA - Supervisor-only access control
 *  0b00000000..Associated segment is accessible in supervisor mode only
 *  0b00000001..Associated segment is accessible in user or supervisor mode
 */
#define FTFE_SACCH0_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCH0_SA_SHIFT)) & FTFE_SACCH0_SA_MASK)
/*! @} */

/*! @name SACCL3 - Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCL3_SA_MASK                      (0xFFU)
#define FTFE_SACCL3_SA_SHIFT                     (0U)
/*! SA - Supervisor-only access control
 *  0b00000000..Associated segment is accessible in supervisor mode only
 *  0b00000001..Associated segment is accessible in user or supervisor mode
 */
#define FTFE_SACCL3_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCL3_SA_SHIFT)) & FTFE_SACCL3_SA_MASK)
/*! @} */

/*! @name SACCL2 - Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCL2_SA_MASK                      (0xFFU)
#define FTFE_SACCL2_SA_SHIFT                     (0U)
/*! SA - Supervisor-only access control
 *  0b00000000..Associated segment is accessible in supervisor mode only
 *  0b00000001..Associated segment is accessible in user or supervisor mode
 */
#define FTFE_SACCL2_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCL2_SA_SHIFT)) & FTFE_SACCL2_SA_MASK)
/*! @} */

/*! @name SACCL1 - Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCL1_SA_MASK                      (0xFFU)
#define FTFE_SACCL1_SA_SHIFT                     (0U)
/*! SA - Supervisor-only access control
 *  0b00000000..Associated segment is accessible in supervisor mode only
 *  0b00000001..Associated segment is accessible in user or supervisor mode
 */
#define FTFE_SACCL1_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCL1_SA_SHIFT)) & FTFE_SACCL1_SA_MASK)
/*! @} */

/*! @name SACCL0 - Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCL0_SA_MASK                      (0xFFU)
#define FTFE_SACCL0_SA_SHIFT                     (0U)
/*! SA - Supervisor-only access control
 *  0b00000000..Associated segment is accessible in supervisor mode only
 *  0b00000001..Associated segment is accessible in user or supervisor mode
 */
#define FTFE_SACCL0_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCL0_SA_SHIFT)) & FTFE_SACCL0_SA_MASK)
/*! @} */

/*! @name FACSS - Flash Access Segment Size Register */
/*! @{ */

#define FTFE_FACSS_SGSIZE_MASK                   (0xFFU)
#define FTFE_FACSS_SGSIZE_SHIFT                  (0U)
/*! SGSIZE - Segment Size */
#define FTFE_FACSS_SGSIZE(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FACSS_SGSIZE_SHIFT)) & FTFE_FACSS_SGSIZE_MASK)
/*! @} */

/*! @name FACSN - Flash Access Segment Number Register */
/*! @{ */

#define FTFE_FACSN_NUMSG_MASK                    (0xFFU)
#define FTFE_FACSN_NUMSG_SHIFT                   (0U)
/*! NUMSG - Number of Segments Indicator
 *  0b00110000..Program flash memory is divided into 48 segments (768 Kbytes, 1.5 Mbytes)
 *  0b01000000..Program flash memory is divided into 64 segments (256 Kbytes, 512 Kbytes, 1 Mbyte, 2 Mbytes)
 */
#define FTFE_FACSN_NUMSG(x)                      (((uint8_t)(((uint8_t)(x)) << FTFE_FACSN_NUMSG_SHIFT)) & FTFE_FACSN_NUMSG_MASK)
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

