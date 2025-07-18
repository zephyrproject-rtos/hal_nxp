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
**         CMSIS Peripheral Access Layer for FTFC
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
 * @file PERI_FTFC.h
 * @version 1.0
 * @date 2025-02-21
 * @brief CMSIS Peripheral Access Layer for FTFC
 *
 * CMSIS Peripheral Access Layer for FTFC
 */

#if !defined(PERI_FTFC_H_)
#define PERI_FTFC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- FTFC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFC_Peripheral_Access_Layer FTFC Peripheral Access Layer
 * @{
 */

/** FTFC - Register Layout Typedef */
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
       uint8_t RESERVED_1[20];
  __I  uint8_t FCSESTAT;                           /**< Flash CSEc Status Register, offset: 0x2C */
       uint8_t RESERVED_2[1];
  __IO uint8_t FERSTAT;                            /**< Flash Error Status Register, offset: 0x2E */
  __IO uint8_t FERCNFG;                            /**< Flash Error Configuration Register, offset: 0x2F */
} FTFC_Type;

/* ----------------------------------------------------------------------------
   -- FTFC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFC_Register_Masks FTFC Register Masks
 * @{
 */

/*! @name FSTAT - Flash Status Register */
/*! @{ */

#define FTFC_FSTAT_MGSTAT0_MASK                  (0x1U)
#define FTFC_FSTAT_MGSTAT0_SHIFT                 (0U)
/*! MGSTAT0 - Memory Controller Command Completion Status Flag */
#define FTFC_FSTAT_MGSTAT0(x)                    (((uint8_t)(((uint8_t)(x)) << FTFC_FSTAT_MGSTAT0_SHIFT)) & FTFC_FSTAT_MGSTAT0_MASK)

#define FTFC_FSTAT_FPVIOL_MASK                   (0x10U)
#define FTFC_FSTAT_FPVIOL_SHIFT                  (4U)
/*! FPVIOL - Flash Protection Violation Flag
 *  0b0..No protection violation detected
 *  0b1..Protection violation detected
 */
#define FTFC_FSTAT_FPVIOL(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FSTAT_FPVIOL_SHIFT)) & FTFC_FSTAT_FPVIOL_MASK)

#define FTFC_FSTAT_ACCERR_MASK                   (0x20U)
#define FTFC_FSTAT_ACCERR_SHIFT                  (5U)
/*! ACCERR - Flash Access Error Flag
 *  0b0..No access error detected
 *  0b1..Access error detected
 */
#define FTFC_FSTAT_ACCERR(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FSTAT_ACCERR_SHIFT)) & FTFC_FSTAT_ACCERR_MASK)

#define FTFC_FSTAT_RDCOLERR_MASK                 (0x40U)
#define FTFC_FSTAT_RDCOLERR_SHIFT                (6U)
/*! RDCOLERR - FTFC Read Collision Error Flag
 *  0b0..No collision error detected
 *  0b1..Collision error detected
 */
#define FTFC_FSTAT_RDCOLERR(x)                   (((uint8_t)(((uint8_t)(x)) << FTFC_FSTAT_RDCOLERR_SHIFT)) & FTFC_FSTAT_RDCOLERR_MASK)

#define FTFC_FSTAT_CCIF_MASK                     (0x80U)
#define FTFC_FSTAT_CCIF_SHIFT                    (7U)
/*! CCIF - Command Complete Interrupt Flag
 *  0b0..FTFC command or emulated EEPROM file system operation in progress
 *  0b1..FTFC command or emulated EEPROM file system operation has completed
 */
#define FTFC_FSTAT_CCIF(x)                       (((uint8_t)(((uint8_t)(x)) << FTFC_FSTAT_CCIF_SHIFT)) & FTFC_FSTAT_CCIF_MASK)
/*! @} */

/*! @name FCNFG - Flash Configuration Register */
/*! @{ */

#define FTFC_FCNFG_EEERDY_MASK                   (0x1U)
#define FTFC_FCNFG_EEERDY_SHIFT                  (0U)
/*! EEERDY - EEERDY
 *  0b0..FlexRAM is not available for emulated EEPROM operation
 *  0b1..FlexRAM is available for EEPROM operations where: (1) reads from the FlexRAM return data previously
 *       written to the FlexRAM in emulated EEPROM mode and (2) writes launch an EEPROM operation to store the written
 *       data in the FlexRAM and EEPROM backup.
 */
#define FTFC_FCNFG_EEERDY(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCNFG_EEERDY_SHIFT)) & FTFC_FCNFG_EEERDY_MASK)

#define FTFC_FCNFG_RAMRDY_MASK                   (0x2U)
#define FTFC_FCNFG_RAMRDY_SHIFT                  (1U)
/*! RAMRDY - RAM Ready
 *  0b0..FlexRAM is not available for traditional RAM access
 *  0b1..FlexRAM is available as traditional RAM only; writes to the FlexRAM do not trigger EEPROM operations
 */
#define FTFC_FCNFG_RAMRDY(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCNFG_RAMRDY_SHIFT)) & FTFC_FCNFG_RAMRDY_MASK)

#define FTFC_FCNFG_ERSSUSP_MASK                  (0x10U)
#define FTFC_FCNFG_ERSSUSP_SHIFT                 (4U)
/*! ERSSUSP - Erase Suspend
 *  0b0..No suspend requested
 *  0b1..Suspend the current Erase Flash Sector command execution
 */
#define FTFC_FCNFG_ERSSUSP(x)                    (((uint8_t)(((uint8_t)(x)) << FTFC_FCNFG_ERSSUSP_SHIFT)) & FTFC_FCNFG_ERSSUSP_MASK)

#define FTFC_FCNFG_ERSAREQ_MASK                  (0x20U)
#define FTFC_FCNFG_ERSAREQ_SHIFT                 (5U)
/*! ERSAREQ - Erase All Request
 *  0b0..No request or request complete
 *  0b1..Request to: (1) run the Erase All Blocks command, (2) verify the erased state, (3) program the security
 *       byte in the Flash Configuration Field to the unsecure state, and (4) release MCU security by setting the
 *       FSEC[SEC] field to the unsecure state.
 */
#define FTFC_FCNFG_ERSAREQ(x)                    (((uint8_t)(((uint8_t)(x)) << FTFC_FCNFG_ERSAREQ_SHIFT)) & FTFC_FCNFG_ERSAREQ_MASK)

#define FTFC_FCNFG_RDCOLLIE_MASK                 (0x40U)
#define FTFC_FCNFG_RDCOLLIE_SHIFT                (6U)
/*! RDCOLLIE - Read Collision Error Interrupt Enable
 *  0b0..Read collision error interrupt disabled
 *  0b1..Read collision error interrupt enabled. An interrupt request is generated whenever an FTFC read collision
 *       error is detected (see the description of FSTAT[RDCOLERR]).
 */
#define FTFC_FCNFG_RDCOLLIE(x)                   (((uint8_t)(((uint8_t)(x)) << FTFC_FCNFG_RDCOLLIE_SHIFT)) & FTFC_FCNFG_RDCOLLIE_MASK)

#define FTFC_FCNFG_CCIE_MASK                     (0x80U)
#define FTFC_FCNFG_CCIE_SHIFT                    (7U)
/*! CCIE - Command Complete Interrupt Enable
 *  0b0..Command complete interrupt disabled
 *  0b1..Command complete interrupt enabled. An interrupt request is generated whenever the FSTAT[CCIF] flag is set.
 */
#define FTFC_FCNFG_CCIE(x)                       (((uint8_t)(((uint8_t)(x)) << FTFC_FCNFG_CCIE_SHIFT)) & FTFC_FCNFG_CCIE_MASK)
/*! @} */

/*! @name FSEC - Flash Security Register */
/*! @{ */

#define FTFC_FSEC_SEC_MASK                       (0x3U)
#define FTFC_FSEC_SEC_SHIFT                      (0U)
/*! SEC - Flash Security
 *  0b00..MCU security status is secure
 *  0b01..MCU security status is secure
 *  0b10..MCU security status is unsecure (The standard shipping condition of the FTFC is unsecure.)
 *  0b11..MCU security status is secure
 */
#define FTFC_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x)) << FTFC_FSEC_SEC_SHIFT)) & FTFC_FSEC_SEC_MASK)

#define FTFC_FSEC_FSLACC_MASK                    (0xCU)
#define FTFC_FSEC_FSLACC_SHIFT                   (2U)
/*! FSLACC - Factory Failure Analysis Access Code
 *  0b00..Factory access granted
 *  0b01..Factory access denied
 *  0b10..Factory access denied
 *  0b11..Factory access granted
 */
#define FTFC_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x)) << FTFC_FSEC_FSLACC_SHIFT)) & FTFC_FSEC_FSLACC_MASK)

#define FTFC_FSEC_MEEN_MASK                      (0x30U)
#define FTFC_FSEC_MEEN_SHIFT                     (4U)
/*! MEEN - Mass Erase Enable Bits
 *  0b00..Mass erase is enabled
 *  0b01..Mass erase is enabled
 *  0b10..Mass erase is disabled
 *  0b11..Mass erase is enabled
 */
#define FTFC_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x)) << FTFC_FSEC_MEEN_SHIFT)) & FTFC_FSEC_MEEN_MASK)

#define FTFC_FSEC_KEYEN_MASK                     (0xC0U)
#define FTFC_FSEC_KEYEN_SHIFT                    (6U)
/*! KEYEN - Backdoor Key Security Enable
 *  0b00..Backdoor key access disabled
 *  0b01..Backdoor key access disabled (preferred KEYEN state to disable backdoor key access)
 *  0b10..Backdoor key access enabled
 *  0b11..Backdoor key access disabled
 */
#define FTFC_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x)) << FTFC_FSEC_KEYEN_SHIFT)) & FTFC_FSEC_KEYEN_MASK)
/*! @} */

/*! @name FOPT - Flash Option Register */
/*! @{ */

#define FTFC_FOPT_OPT_MASK                       (0xFFU)
#define FTFC_FOPT_OPT_SHIFT                      (0U)
/*! OPT - Nonvolatile Option */
#define FTFC_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x)) << FTFC_FOPT_OPT_SHIFT)) & FTFC_FOPT_OPT_MASK)
/*! @} */

/*! @name FCCOB3 - Flash Common Command Object Registers */
/*! @{ */

#define FTFC_FCCOB3_CCOBn_MASK                   (0xFFU)
#define FTFC_FCCOB3_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFC_FCCOB3_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCCOB3_CCOBn_SHIFT)) & FTFC_FCCOB3_CCOBn_MASK)
/*! @} */

/*! @name FCCOB2 - Flash Common Command Object Registers */
/*! @{ */

#define FTFC_FCCOB2_CCOBn_MASK                   (0xFFU)
#define FTFC_FCCOB2_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFC_FCCOB2_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCCOB2_CCOBn_SHIFT)) & FTFC_FCCOB2_CCOBn_MASK)
/*! @} */

/*! @name FCCOB1 - Flash Common Command Object Registers */
/*! @{ */

#define FTFC_FCCOB1_CCOBn_MASK                   (0xFFU)
#define FTFC_FCCOB1_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFC_FCCOB1_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCCOB1_CCOBn_SHIFT)) & FTFC_FCCOB1_CCOBn_MASK)
/*! @} */

/*! @name FCCOB0 - Flash Common Command Object Registers */
/*! @{ */

#define FTFC_FCCOB0_CCOBn_MASK                   (0xFFU)
#define FTFC_FCCOB0_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFC_FCCOB0_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCCOB0_CCOBn_SHIFT)) & FTFC_FCCOB0_CCOBn_MASK)
/*! @} */

/*! @name FCCOB7 - Flash Common Command Object Registers */
/*! @{ */

#define FTFC_FCCOB7_CCOBn_MASK                   (0xFFU)
#define FTFC_FCCOB7_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFC_FCCOB7_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCCOB7_CCOBn_SHIFT)) & FTFC_FCCOB7_CCOBn_MASK)
/*! @} */

/*! @name FCCOB6 - Flash Common Command Object Registers */
/*! @{ */

#define FTFC_FCCOB6_CCOBn_MASK                   (0xFFU)
#define FTFC_FCCOB6_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFC_FCCOB6_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCCOB6_CCOBn_SHIFT)) & FTFC_FCCOB6_CCOBn_MASK)
/*! @} */

/*! @name FCCOB5 - Flash Common Command Object Registers */
/*! @{ */

#define FTFC_FCCOB5_CCOBn_MASK                   (0xFFU)
#define FTFC_FCCOB5_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFC_FCCOB5_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCCOB5_CCOBn_SHIFT)) & FTFC_FCCOB5_CCOBn_MASK)
/*! @} */

/*! @name FCCOB4 - Flash Common Command Object Registers */
/*! @{ */

#define FTFC_FCCOB4_CCOBn_MASK                   (0xFFU)
#define FTFC_FCCOB4_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFC_FCCOB4_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCCOB4_CCOBn_SHIFT)) & FTFC_FCCOB4_CCOBn_MASK)
/*! @} */

/*! @name FCCOBB - Flash Common Command Object Registers */
/*! @{ */

#define FTFC_FCCOBB_CCOBn_MASK                   (0xFFU)
#define FTFC_FCCOBB_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFC_FCCOBB_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCCOBB_CCOBn_SHIFT)) & FTFC_FCCOBB_CCOBn_MASK)
/*! @} */

/*! @name FCCOBA - Flash Common Command Object Registers */
/*! @{ */

#define FTFC_FCCOBA_CCOBn_MASK                   (0xFFU)
#define FTFC_FCCOBA_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFC_FCCOBA_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCCOBA_CCOBn_SHIFT)) & FTFC_FCCOBA_CCOBn_MASK)
/*! @} */

/*! @name FCCOB9 - Flash Common Command Object Registers */
/*! @{ */

#define FTFC_FCCOB9_CCOBn_MASK                   (0xFFU)
#define FTFC_FCCOB9_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFC_FCCOB9_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCCOB9_CCOBn_SHIFT)) & FTFC_FCCOB9_CCOBn_MASK)
/*! @} */

/*! @name FCCOB8 - Flash Common Command Object Registers */
/*! @{ */

#define FTFC_FCCOB8_CCOBn_MASK                   (0xFFU)
#define FTFC_FCCOB8_CCOBn_SHIFT                  (0U)
/*! CCOBn - CCOBn */
#define FTFC_FCCOB8_CCOBn(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCCOB8_CCOBn_SHIFT)) & FTFC_FCCOB8_CCOBn_MASK)
/*! @} */

/*! @name FPROT3 - Program Flash Protection Registers */
/*! @{ */

#define FTFC_FPROT3_PROT_MASK                    (0xFFU)
#define FTFC_FPROT3_PROT_SHIFT                   (0U)
/*! PROT - Program Flash Region Protect */
#define FTFC_FPROT3_PROT(x)                      (((uint8_t)(((uint8_t)(x)) << FTFC_FPROT3_PROT_SHIFT)) & FTFC_FPROT3_PROT_MASK)
/*! @} */

/*! @name FPROT2 - Program Flash Protection Registers */
/*! @{ */

#define FTFC_FPROT2_PROT_MASK                    (0xFFU)
#define FTFC_FPROT2_PROT_SHIFT                   (0U)
/*! PROT - Program Flash Region Protect */
#define FTFC_FPROT2_PROT(x)                      (((uint8_t)(((uint8_t)(x)) << FTFC_FPROT2_PROT_SHIFT)) & FTFC_FPROT2_PROT_MASK)
/*! @} */

/*! @name FPROT1 - Program Flash Protection Registers */
/*! @{ */

#define FTFC_FPROT1_PROT_MASK                    (0xFFU)
#define FTFC_FPROT1_PROT_SHIFT                   (0U)
/*! PROT - Program Flash Region Protect */
#define FTFC_FPROT1_PROT(x)                      (((uint8_t)(((uint8_t)(x)) << FTFC_FPROT1_PROT_SHIFT)) & FTFC_FPROT1_PROT_MASK)
/*! @} */

/*! @name FPROT0 - Program Flash Protection Registers */
/*! @{ */

#define FTFC_FPROT0_PROT_MASK                    (0xFFU)
#define FTFC_FPROT0_PROT_SHIFT                   (0U)
/*! PROT - Program Flash Region Protect */
#define FTFC_FPROT0_PROT(x)                      (((uint8_t)(((uint8_t)(x)) << FTFC_FPROT0_PROT_SHIFT)) & FTFC_FPROT0_PROT_MASK)
/*! @} */

/*! @name FEPROT - EEPROM Protection Register */
/*! @{ */

#define FTFC_FEPROT_EPROT_MASK                   (0xFFU)
#define FTFC_FEPROT_EPROT_SHIFT                  (0U)
/*! EPROT - EEPROM Region Protect
 *  0b00000000..EEPROM region is protected
 *  0b00000001..EEPROM region is not protected
 */
#define FTFC_FEPROT_EPROT(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FEPROT_EPROT_SHIFT)) & FTFC_FEPROT_EPROT_MASK)
/*! @} */

/*! @name FDPROT - Data Flash Protection Register */
/*! @{ */

#define FTFC_FDPROT_DPROT_MASK                   (0xFFU)
#define FTFC_FDPROT_DPROT_SHIFT                  (0U)
/*! DPROT - Data Flash Region Protect
 *  0b00000000..Data Flash region is protected
 *  0b00000001..Data Flash region is not protected
 */
#define FTFC_FDPROT_DPROT(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FDPROT_DPROT_SHIFT)) & FTFC_FDPROT_DPROT_MASK)
/*! @} */

/*! @name FCSESTAT - Flash CSEc Status Register */
/*! @{ */

#define FTFC_FCSESTAT_BSY_MASK                   (0x1U)
#define FTFC_FCSESTAT_BSY_SHIFT                  (0U)
/*! BSY - Busy
 *  0b0..CSEc command processing has completed
 *  0b1..CSEc command processing is in progress
 */
#define FTFC_FCSESTAT_BSY(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCSESTAT_BSY_SHIFT)) & FTFC_FCSESTAT_BSY_MASK)

#define FTFC_FCSESTAT_SB_MASK                    (0x2U)
#define FTFC_FCSESTAT_SB_SHIFT                   (1U)
/*! SB - Secure Boot
 *  0b0..Secure boot not activated
 *  0b1..Secure boot is activated
 */
#define FTFC_FCSESTAT_SB(x)                      (((uint8_t)(((uint8_t)(x)) << FTFC_FCSESTAT_SB_SHIFT)) & FTFC_FCSESTAT_SB_MASK)

#define FTFC_FCSESTAT_BIN_MASK                   (0x4U)
#define FTFC_FCSESTAT_BIN_SHIFT                  (2U)
/*! BIN - Secure Boot Initialization
 *  0b0..Secure boot personalization not completed.
 *  0b1..Secure boot personalization has completed
 */
#define FTFC_FCSESTAT_BIN(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCSESTAT_BIN_SHIFT)) & FTFC_FCSESTAT_BIN_MASK)

#define FTFC_FCSESTAT_BFN_MASK                   (0x8U)
#define FTFC_FCSESTAT_BFN_SHIFT                  (3U)
/*! BFN - Secure Boot Finished
 *  0b0..Secure Boot is not finished.
 *  0b1..Secure Boot has finished
 */
#define FTFC_FCSESTAT_BFN(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCSESTAT_BFN_SHIFT)) & FTFC_FCSESTAT_BFN_MASK)

#define FTFC_FCSESTAT_BOK_MASK                   (0x10U)
#define FTFC_FCSESTAT_BOK_SHIFT                  (4U)
/*! BOK - Secure Boot OK
 *  0b0..Secure boot is not complete, or secure boot failure
 *  0b1..Secure boot was successful.
 */
#define FTFC_FCSESTAT_BOK(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCSESTAT_BOK_SHIFT)) & FTFC_FCSESTAT_BOK_MASK)

#define FTFC_FCSESTAT_RIN_MASK                   (0x20U)
#define FTFC_FCSESTAT_RIN_SHIFT                  (5U)
/*! RIN - Random Number Generator Initialized
 *  0b0..Random number generator is not initialized.
 *  0b1..Random number generator is initialized.
 */
#define FTFC_FCSESTAT_RIN(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCSESTAT_RIN_SHIFT)) & FTFC_FCSESTAT_RIN_MASK)

#define FTFC_FCSESTAT_EDB_MASK                   (0x40U)
#define FTFC_FCSESTAT_EDB_SHIFT                  (6U)
/*! EDB - External Debug
 *  0b0..External debugger not attached
 *  0b1..External debugger is attached
 */
#define FTFC_FCSESTAT_EDB(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCSESTAT_EDB_SHIFT)) & FTFC_FCSESTAT_EDB_MASK)

#define FTFC_FCSESTAT_IDB_MASK                   (0x80U)
#define FTFC_FCSESTAT_IDB_SHIFT                  (7U)
/*! IDB - Internal Debug
 *  0b0..Internal debug functions are disabled
 *  0b1..Internal debugger functions are enabled
 */
#define FTFC_FCSESTAT_IDB(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FCSESTAT_IDB_SHIFT)) & FTFC_FCSESTAT_IDB_MASK)
/*! @} */

/*! @name FERSTAT - Flash Error Status Register */
/*! @{ */

#define FTFC_FERSTAT_DFDIF_MASK                  (0x2U)
#define FTFC_FERSTAT_DFDIF_SHIFT                 (1U)
/*! DFDIF - Double Bit Fault Detect Interrupt Flag
 *  0b0..Double bit fault not detected during a valid flash read access from the platform flash controller
 *  0b1..Double bit fault detected (or FERCNFG[FDFD] is set) during a valid flash read access from the platform flash controller
 */
#define FTFC_FERSTAT_DFDIF(x)                    (((uint8_t)(((uint8_t)(x)) << FTFC_FERSTAT_DFDIF_SHIFT)) & FTFC_FERSTAT_DFDIF_MASK)
/*! @} */

/*! @name FERCNFG - Flash Error Configuration Register */
/*! @{ */

#define FTFC_FERCNFG_DFDIE_MASK                  (0x2U)
#define FTFC_FERCNFG_DFDIE_SHIFT                 (1U)
/*! DFDIE - Double Bit Fault Detect Interrupt Enable
 *  0b0..Double bit fault detect interrupt disabled
 *  0b1..Double bit fault detect interrupt enabled. An interrupt request is generated whenever the FERSTAT[DFDIF] flag is set.
 */
#define FTFC_FERCNFG_DFDIE(x)                    (((uint8_t)(((uint8_t)(x)) << FTFC_FERCNFG_DFDIE_SHIFT)) & FTFC_FERCNFG_DFDIE_MASK)

#define FTFC_FERCNFG_FDFD_MASK                   (0x20U)
#define FTFC_FERCNFG_FDFD_SHIFT                  (5U)
/*! FDFD - Force Double Bit Fault Detect
 *  0b0..FERSTAT[DFDIF] sets only if a double bit fault is detected during read access from the platform flash controller
 *  0b1..FERSTAT[DFDIF] sets during any valid flash read access from the platform flash controller. An interrupt
 *       request is generated if the DFDIE bit is set.
 */
#define FTFC_FERCNFG_FDFD(x)                     (((uint8_t)(((uint8_t)(x)) << FTFC_FERCNFG_FDFD_SHIFT)) & FTFC_FERCNFG_FDFD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FTFC_Register_Masks */


/*!
 * @}
 */ /* end of group FTFC_Peripheral_Access_Layer */


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


#endif  /* PERI_FTFC_H_ */

