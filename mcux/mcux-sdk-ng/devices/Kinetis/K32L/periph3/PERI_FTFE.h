/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
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
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FTFE.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FTFE
 *
 * CMSIS Peripheral Access Layer for FTFE
 */

#if !defined(PERI_FTFE_H_)
#define PERI_FTFE_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
       uint8_t RESERVED_0[1];
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
  __I  uint8_t FOPT3;                              /**< Flash Option Registers, offset: 0x10 */
  __I  uint8_t FOPT2;                              /**< Flash Option Registers, offset: 0x11 */
  __I  uint8_t FOPT1;                              /**< Flash Option Registers, offset: 0x12 */
  __I  uint8_t FOPT0;                              /**< Flash Option Registers, offset: 0x13 */
       uint8_t RESERVED_1[4];
  __IO uint8_t FPROTH3;                            /**< Primary Program Flash Protection Registers, offset: 0x18 */
  __IO uint8_t FPROTH2;                            /**< Primary Program Flash Protection Registers, offset: 0x19 */
  __IO uint8_t FPROTH1;                            /**< Primary Program Flash Protection Registers, offset: 0x1A */
  __IO uint8_t FPROTH0;                            /**< Primary Program Flash Protection Registers, offset: 0x1B */
  __IO uint8_t FPROTL3;                            /**< Primary Program Flash Protection Registers, offset: 0x1C */
  __IO uint8_t FPROTL2;                            /**< Primary Program Flash Protection Registers, offset: 0x1D */
  __IO uint8_t FPROTL1;                            /**< Primary Program Flash Protection Registers, offset: 0x1E */
  __IO uint8_t FPROTL0;                            /**< Primary Program Flash Protection Registers, offset: 0x1F */
       uint8_t RESERVED_2[4];
  __IO uint8_t FPROTSL;                            /**< Secondary Program Flash Protection Registers, offset: 0x24 */
  __IO uint8_t FPROTSH;                            /**< Secondary Program Flash Protection Registers, offset: 0x25 */
       uint8_t RESERVED_3[6];
  __I  uint8_t FACSS;                              /**< Primary Flash Access Segment Size Register, offset: 0x2C */
  __I  uint8_t FACSN;                              /**< Primary Flash Access Segment Number Register, offset: 0x2D */
  __I  uint8_t FACSSS;                             /**< Secondary Flash Access Segment Size Register, offset: 0x2E */
  __I  uint8_t FACSNS;                             /**< Secondary Flash Access Segment Number Register, offset: 0x2F */
  __I  uint8_t XACCH3;                             /**< Primary Execute-only Access Registers, offset: 0x30 */
  __I  uint8_t XACCH2;                             /**< Primary Execute-only Access Registers, offset: 0x31 */
  __I  uint8_t XACCH1;                             /**< Primary Execute-only Access Registers, offset: 0x32 */
  __I  uint8_t XACCH0;                             /**< Primary Execute-only Access Registers, offset: 0x33 */
  __I  uint8_t XACCL3;                             /**< Primary Execute-only Access Registers, offset: 0x34 */
  __I  uint8_t XACCL2;                             /**< Primary Execute-only Access Registers, offset: 0x35 */
  __I  uint8_t XACCL1;                             /**< Primary Execute-only Access Registers, offset: 0x36 */
  __I  uint8_t XACCL0;                             /**< Primary Execute-only Access Registers, offset: 0x37 */
  __I  uint8_t SACCH3;                             /**< Primary Supervisor-only Access Registers, offset: 0x38 */
  __I  uint8_t SACCH2;                             /**< Primary Supervisor-only Access Registers, offset: 0x39 */
  __I  uint8_t SACCH1;                             /**< Primary Supervisor-only Access Registers, offset: 0x3A */
  __I  uint8_t SACCH0;                             /**< Primary Supervisor-only Access Registers, offset: 0x3B */
  __I  uint8_t SACCL3;                             /**< Primary Supervisor-only Access Registers, offset: 0x3C */
  __I  uint8_t SACCL2;                             /**< Primary Supervisor-only Access Registers, offset: 0x3D */
  __I  uint8_t SACCL1;                             /**< Primary Supervisor-only Access Registers, offset: 0x3E */
  __I  uint8_t SACCL0;                             /**< Primary Supervisor-only Access Registers, offset: 0x3F */
       uint8_t RESERVED_4[4];
  __I  uint8_t XACCSL;                             /**< Secondary Execute-only Access Registers, offset: 0x44 */
  __I  uint8_t XACCSH;                             /**< Secondary Execute-only Access Registers, offset: 0x45 */
       uint8_t RESERVED_5[6];
  __I  uint8_t SACCSL;                             /**< Secondary Supervisor-only Access Registers, offset: 0x4C */
  __I  uint8_t SACCSH;                             /**< Secondary Supervisor-only Access Registers, offset: 0x4D */
       uint8_t RESERVED_6[4];
  __I  uint8_t FSTDBYCTL;                          /**< Flash Standby Control Register, offset: 0x52 */
  __IO uint8_t FSTDBY;                             /**< Flash Standby Register, offset: 0x53 */
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
/*! RDCOLERR - Flash Read Collision Error Flag
 *  0b0..No collision error detected
 *  0b1..Collision error detected
 */
#define FTFE_FSTAT_RDCOLERR(x)                   (((uint8_t)(((uint8_t)(x)) << FTFE_FSTAT_RDCOLERR_SHIFT)) & FTFE_FSTAT_RDCOLERR_MASK)

#define FTFE_FSTAT_CCIF_MASK                     (0x80U)
#define FTFE_FSTAT_CCIF_SHIFT                    (7U)
/*! CCIF - Command Complete Interrupt Flag
 *  0b0..Flash command in progress
 *  0b1..Flash command has completed
 */
#define FTFE_FSTAT_CCIF(x)                       (((uint8_t)(((uint8_t)(x)) << FTFE_FSTAT_CCIF_SHIFT)) & FTFE_FSTAT_CCIF_MASK)
/*! @} */

/*! @name FCNFG - Flash Configuration Register */
/*! @{ */

#define FTFE_FCNFG_RAMRDY_MASK                   (0x2U)
#define FTFE_FCNFG_RAMRDY_SHIFT                  (1U)
/*! RAMRDY - RAM Ready
 *  0b0..Programming acceleration RAM is not available
 *  0b1..Programming acceleration RAM is available
 */
#define FTFE_FCNFG_RAMRDY(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCNFG_RAMRDY_SHIFT)) & FTFE_FCNFG_RAMRDY_MASK)

#define FTFE_FCNFG_CRCRDY_MASK                   (0x4U)
#define FTFE_FCNFG_CRCRDY_SHIFT                  (2U)
/*! CRCRDY - CRC Ready
 *  0b0..Programming acceleration RAM is not available for CRC operations
 *  0b1..Programming acceleration RAM is available for CRC operations
 */
#define FTFE_FCNFG_CRCRDY(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FCNFG_CRCRDY_SHIFT)) & FTFE_FCNFG_CRCRDY_MASK)

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
 *  0b1..Request to: (1) run the Erase All Blocks command, (2) verify the erased state, (3) program the security
 *       byte in the Flash Configuration Field to the unsecure state, and (4) release MCU security by setting the
 *       FSEC[SEC] field to the unsecure state.
 */
#define FTFE_FCNFG_ERSAREQ(x)                    (((uint8_t)(((uint8_t)(x)) << FTFE_FCNFG_ERSAREQ_SHIFT)) & FTFE_FCNFG_ERSAREQ_MASK)

#define FTFE_FCNFG_RDCOLLIE_MASK                 (0x40U)
#define FTFE_FCNFG_RDCOLLIE_SHIFT                (6U)
/*! RDCOLLIE - Read Collision Error Interrupt Enable
 *  0b0..Read collision error interrupt disabled
 *  0b1..Read collision error interrupt enabled. An interrupt request is generated whenever a flash read collision
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
 *  0b10..MCU security status is unsecure (The standard shipping condition of the flash module is unsecure.)
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

/*! @name FOPT3 - Flash Option Registers */
/*! @{ */

#define FTFE_FOPT3_OPT_MASK                      (0xFFU)
#define FTFE_FOPT3_OPT_SHIFT                     (0U)
/*! OPT - Nonvolatile Option */
#define FTFE_FOPT3_OPT(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_FOPT3_OPT_SHIFT)) & FTFE_FOPT3_OPT_MASK)
/*! @} */

/*! @name FOPT2 - Flash Option Registers */
/*! @{ */

#define FTFE_FOPT2_OPT_MASK                      (0xFFU)
#define FTFE_FOPT2_OPT_SHIFT                     (0U)
/*! OPT - Nonvolatile Option */
#define FTFE_FOPT2_OPT(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_FOPT2_OPT_SHIFT)) & FTFE_FOPT2_OPT_MASK)
/*! @} */

/*! @name FOPT1 - Flash Option Registers */
/*! @{ */

#define FTFE_FOPT1_OPT_MASK                      (0xFFU)
#define FTFE_FOPT1_OPT_SHIFT                     (0U)
/*! OPT - Nonvolatile Option */
#define FTFE_FOPT1_OPT(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_FOPT1_OPT_SHIFT)) & FTFE_FOPT1_OPT_MASK)
/*! @} */

/*! @name FOPT0 - Flash Option Registers */
/*! @{ */

#define FTFE_FOPT0_OPT_MASK                      (0xFFU)
#define FTFE_FOPT0_OPT_SHIFT                     (0U)
/*! OPT - Nonvolatile Option */
#define FTFE_FOPT0_OPT(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_FOPT0_OPT_SHIFT)) & FTFE_FOPT0_OPT_MASK)
/*! @} */

/*! @name FPROTH3 - Primary Program Flash Protection Registers */
/*! @{ */

#define FTFE_FPROTH3_PROT_MASK                   (0xFFU)
#define FTFE_FPROTH3_PROT_SHIFT                  (0U)
/*! PROT - Primary Program Flash Region Protect */
#define FTFE_FPROTH3_PROT(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FPROTH3_PROT_SHIFT)) & FTFE_FPROTH3_PROT_MASK)
/*! @} */

/*! @name FPROTH2 - Primary Program Flash Protection Registers */
/*! @{ */

#define FTFE_FPROTH2_PROT_MASK                   (0xFFU)
#define FTFE_FPROTH2_PROT_SHIFT                  (0U)
/*! PROT - Primary Program Flash Region Protect */
#define FTFE_FPROTH2_PROT(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FPROTH2_PROT_SHIFT)) & FTFE_FPROTH2_PROT_MASK)
/*! @} */

/*! @name FPROTH1 - Primary Program Flash Protection Registers */
/*! @{ */

#define FTFE_FPROTH1_PROT_MASK                   (0xFFU)
#define FTFE_FPROTH1_PROT_SHIFT                  (0U)
/*! PROT - Primary Program Flash Region Protect */
#define FTFE_FPROTH1_PROT(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FPROTH1_PROT_SHIFT)) & FTFE_FPROTH1_PROT_MASK)
/*! @} */

/*! @name FPROTH0 - Primary Program Flash Protection Registers */
/*! @{ */

#define FTFE_FPROTH0_PROT_MASK                   (0xFFU)
#define FTFE_FPROTH0_PROT_SHIFT                  (0U)
/*! PROT - Primary Program Flash Region Protect */
#define FTFE_FPROTH0_PROT(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FPROTH0_PROT_SHIFT)) & FTFE_FPROTH0_PROT_MASK)
/*! @} */

/*! @name FPROTL3 - Primary Program Flash Protection Registers */
/*! @{ */

#define FTFE_FPROTL3_PROT_MASK                   (0xFFU)
#define FTFE_FPROTL3_PROT_SHIFT                  (0U)
/*! PROT - Primary Program Flash Region Protect */
#define FTFE_FPROTL3_PROT(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FPROTL3_PROT_SHIFT)) & FTFE_FPROTL3_PROT_MASK)
/*! @} */

/*! @name FPROTL2 - Primary Program Flash Protection Registers */
/*! @{ */

#define FTFE_FPROTL2_PROT_MASK                   (0xFFU)
#define FTFE_FPROTL2_PROT_SHIFT                  (0U)
/*! PROT - Primary Program Flash Region Protect */
#define FTFE_FPROTL2_PROT(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FPROTL2_PROT_SHIFT)) & FTFE_FPROTL2_PROT_MASK)
/*! @} */

/*! @name FPROTL1 - Primary Program Flash Protection Registers */
/*! @{ */

#define FTFE_FPROTL1_PROT_MASK                   (0xFFU)
#define FTFE_FPROTL1_PROT_SHIFT                  (0U)
/*! PROT - Primary Program Flash Region Protect */
#define FTFE_FPROTL1_PROT(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FPROTL1_PROT_SHIFT)) & FTFE_FPROTL1_PROT_MASK)
/*! @} */

/*! @name FPROTL0 - Primary Program Flash Protection Registers */
/*! @{ */

#define FTFE_FPROTL0_PROT_MASK                   (0xFFU)
#define FTFE_FPROTL0_PROT_SHIFT                  (0U)
/*! PROT - Primary Program Flash Region Protect */
#define FTFE_FPROTL0_PROT(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FPROTL0_PROT_SHIFT)) & FTFE_FPROTL0_PROT_MASK)
/*! @} */

/*! @name FPROTSL - Secondary Program Flash Protection Registers */
/*! @{ */

#define FTFE_FPROTSL_PROTS_MASK                  (0xFFU)
#define FTFE_FPROTSL_PROTS_SHIFT                 (0U)
/*! PROTS - Secondary Program Flash Region Protect */
#define FTFE_FPROTSL_PROTS(x)                    (((uint8_t)(((uint8_t)(x)) << FTFE_FPROTSL_PROTS_SHIFT)) & FTFE_FPROTSL_PROTS_MASK)
/*! @} */

/*! @name FPROTSH - Secondary Program Flash Protection Registers */
/*! @{ */

#define FTFE_FPROTSH_PROTS_MASK                  (0xFFU)
#define FTFE_FPROTSH_PROTS_SHIFT                 (0U)
/*! PROTS - Secondary Program Flash Region Protect */
#define FTFE_FPROTSH_PROTS(x)                    (((uint8_t)(((uint8_t)(x)) << FTFE_FPROTSH_PROTS_SHIFT)) & FTFE_FPROTSH_PROTS_MASK)
/*! @} */

/*! @name FACSS - Primary Flash Access Segment Size Register */
/*! @{ */

#define FTFE_FACSS_SGSIZE_MASK                   (0xFFU)
#define FTFE_FACSS_SGSIZE_SHIFT                  (0U)
/*! SGSIZE - Segment Size */
#define FTFE_FACSS_SGSIZE(x)                     (((uint8_t)(((uint8_t)(x)) << FTFE_FACSS_SGSIZE_SHIFT)) & FTFE_FACSS_SGSIZE_MASK)
/*! @} */

/*! @name FACSN - Primary Flash Access Segment Number Register */
/*! @{ */

#define FTFE_FACSN_NUMSG_MASK                    (0xFFU)
#define FTFE_FACSN_NUMSG_SHIFT                   (0U)
/*! NUMSG - Number of Segments Indicator
 *  0b00110000..Primary Program flash memory is divided into 48 segments (768 Kbytes, 1.5 Mbytes)
 *  0b01000000..Primary Program flash memory is divided into 64 segments (512 Kbytes, 1 Mbyte, 2 Mbytes)
 */
#define FTFE_FACSN_NUMSG(x)                      (((uint8_t)(((uint8_t)(x)) << FTFE_FACSN_NUMSG_SHIFT)) & FTFE_FACSN_NUMSG_MASK)
/*! @} */

/*! @name FACSSS - Secondary Flash Access Segment Size Register */
/*! @{ */

#define FTFE_FACSSS_SGSIZE_S_MASK                (0xFFU)
#define FTFE_FACSSS_SGSIZE_S_SHIFT               (0U)
/*! SGSIZE_S - Segment Size */
#define FTFE_FACSSS_SGSIZE_S(x)                  (((uint8_t)(((uint8_t)(x)) << FTFE_FACSSS_SGSIZE_S_SHIFT)) & FTFE_FACSSS_SGSIZE_S_MASK)
/*! @} */

/*! @name FACSNS - Secondary Flash Access Segment Number Register */
/*! @{ */

#define FTFE_FACSNS_NUMSG_S_MASK                 (0xFFU)
#define FTFE_FACSNS_NUMSG_S_SHIFT                (0U)
/*! NUMSG_S - Number of Segments Indicator
 *  0b00010000..Secondary Program flash memory is divided into 16 segments
 */
#define FTFE_FACSNS_NUMSG_S(x)                   (((uint8_t)(((uint8_t)(x)) << FTFE_FACSNS_NUMSG_S_SHIFT)) & FTFE_FACSNS_NUMSG_S_MASK)
/*! @} */

/*! @name XACCH3 - Primary Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCH3_XA_MASK                      (0xFFU)
#define FTFE_XACCH3_XA_SHIFT                     (0U)
/*! XA - Execute-only access control */
#define FTFE_XACCH3_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCH3_XA_SHIFT)) & FTFE_XACCH3_XA_MASK)
/*! @} */

/*! @name XACCH2 - Primary Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCH2_XA_MASK                      (0xFFU)
#define FTFE_XACCH2_XA_SHIFT                     (0U)
/*! XA - Execute-only access control */
#define FTFE_XACCH2_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCH2_XA_SHIFT)) & FTFE_XACCH2_XA_MASK)
/*! @} */

/*! @name XACCH1 - Primary Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCH1_XA_MASK                      (0xFFU)
#define FTFE_XACCH1_XA_SHIFT                     (0U)
/*! XA - Execute-only access control */
#define FTFE_XACCH1_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCH1_XA_SHIFT)) & FTFE_XACCH1_XA_MASK)
/*! @} */

/*! @name XACCH0 - Primary Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCH0_XA_MASK                      (0xFFU)
#define FTFE_XACCH0_XA_SHIFT                     (0U)
/*! XA - Execute-only access control */
#define FTFE_XACCH0_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCH0_XA_SHIFT)) & FTFE_XACCH0_XA_MASK)
/*! @} */

/*! @name XACCL3 - Primary Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCL3_XA_MASK                      (0xFFU)
#define FTFE_XACCL3_XA_SHIFT                     (0U)
/*! XA - Execute-only access control */
#define FTFE_XACCL3_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCL3_XA_SHIFT)) & FTFE_XACCL3_XA_MASK)
/*! @} */

/*! @name XACCL2 - Primary Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCL2_XA_MASK                      (0xFFU)
#define FTFE_XACCL2_XA_SHIFT                     (0U)
/*! XA - Execute-only access control */
#define FTFE_XACCL2_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCL2_XA_SHIFT)) & FTFE_XACCL2_XA_MASK)
/*! @} */

/*! @name XACCL1 - Primary Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCL1_XA_MASK                      (0xFFU)
#define FTFE_XACCL1_XA_SHIFT                     (0U)
/*! XA - Execute-only access control */
#define FTFE_XACCL1_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCL1_XA_SHIFT)) & FTFE_XACCL1_XA_MASK)
/*! @} */

/*! @name XACCL0 - Primary Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCL0_XA_MASK                      (0xFFU)
#define FTFE_XACCL0_XA_SHIFT                     (0U)
/*! XA - Execute-only access control */
#define FTFE_XACCL0_XA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_XACCL0_XA_SHIFT)) & FTFE_XACCL0_XA_MASK)
/*! @} */

/*! @name SACCH3 - Primary Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCH3_SA_MASK                      (0xFFU)
#define FTFE_SACCH3_SA_SHIFT                     (0U)
/*! SA - Primary Supervisor-only access control */
#define FTFE_SACCH3_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCH3_SA_SHIFT)) & FTFE_SACCH3_SA_MASK)
/*! @} */

/*! @name SACCH2 - Primary Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCH2_SA_MASK                      (0xFFU)
#define FTFE_SACCH2_SA_SHIFT                     (0U)
/*! SA - Primary Supervisor-only access control */
#define FTFE_SACCH2_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCH2_SA_SHIFT)) & FTFE_SACCH2_SA_MASK)
/*! @} */

/*! @name SACCH1 - Primary Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCH1_SA_MASK                      (0xFFU)
#define FTFE_SACCH1_SA_SHIFT                     (0U)
/*! SA - Primary Supervisor-only access control */
#define FTFE_SACCH1_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCH1_SA_SHIFT)) & FTFE_SACCH1_SA_MASK)
/*! @} */

/*! @name SACCH0 - Primary Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCH0_SA_MASK                      (0xFFU)
#define FTFE_SACCH0_SA_SHIFT                     (0U)
/*! SA - Primary Supervisor-only access control */
#define FTFE_SACCH0_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCH0_SA_SHIFT)) & FTFE_SACCH0_SA_MASK)
/*! @} */

/*! @name SACCL3 - Primary Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCL3_SA_MASK                      (0xFFU)
#define FTFE_SACCL3_SA_SHIFT                     (0U)
/*! SA - Primary Supervisor-only access control */
#define FTFE_SACCL3_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCL3_SA_SHIFT)) & FTFE_SACCL3_SA_MASK)
/*! @} */

/*! @name SACCL2 - Primary Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCL2_SA_MASK                      (0xFFU)
#define FTFE_SACCL2_SA_SHIFT                     (0U)
/*! SA - Primary Supervisor-only access control */
#define FTFE_SACCL2_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCL2_SA_SHIFT)) & FTFE_SACCL2_SA_MASK)
/*! @} */

/*! @name SACCL1 - Primary Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCL1_SA_MASK                      (0xFFU)
#define FTFE_SACCL1_SA_SHIFT                     (0U)
/*! SA - Primary Supervisor-only access control */
#define FTFE_SACCL1_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCL1_SA_SHIFT)) & FTFE_SACCL1_SA_MASK)
/*! @} */

/*! @name SACCL0 - Primary Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCL0_SA_MASK                      (0xFFU)
#define FTFE_SACCL0_SA_SHIFT                     (0U)
/*! SA - Primary Supervisor-only access control */
#define FTFE_SACCL0_SA(x)                        (((uint8_t)(((uint8_t)(x)) << FTFE_SACCL0_SA_SHIFT)) & FTFE_SACCL0_SA_MASK)
/*! @} */

/*! @name XACCSL - Secondary Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCSL_XA_S_MASK                    (0xFFU)
#define FTFE_XACCSL_XA_S_SHIFT                   (0U)
/*! XA_S - Execute-only access control */
#define FTFE_XACCSL_XA_S(x)                      (((uint8_t)(((uint8_t)(x)) << FTFE_XACCSL_XA_S_SHIFT)) & FTFE_XACCSL_XA_S_MASK)
/*! @} */

/*! @name XACCSH - Secondary Execute-only Access Registers */
/*! @{ */

#define FTFE_XACCSH_XA_S_MASK                    (0xFFU)
#define FTFE_XACCSH_XA_S_SHIFT                   (0U)
/*! XA_S - Execute-only access control */
#define FTFE_XACCSH_XA_S(x)                      (((uint8_t)(((uint8_t)(x)) << FTFE_XACCSH_XA_S_SHIFT)) & FTFE_XACCSH_XA_S_MASK)
/*! @} */

/*! @name SACCSL - Secondary Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCSL_SA_S_MASK                    (0xFFU)
#define FTFE_SACCSL_SA_S_SHIFT                   (0U)
/*! SA_S - Secondary Supervisor-only access control */
#define FTFE_SACCSL_SA_S(x)                      (((uint8_t)(((uint8_t)(x)) << FTFE_SACCSL_SA_S_SHIFT)) & FTFE_SACCSL_SA_S_MASK)
/*! @} */

/*! @name SACCSH - Secondary Supervisor-only Access Registers */
/*! @{ */

#define FTFE_SACCSH_SA_S_MASK                    (0xFFU)
#define FTFE_SACCSH_SA_S_SHIFT                   (0U)
/*! SA_S - Secondary Supervisor-only access control */
#define FTFE_SACCSH_SA_S(x)                      (((uint8_t)(((uint8_t)(x)) << FTFE_SACCSH_SA_S_SHIFT)) & FTFE_SACCSH_SA_S_MASK)
/*! @} */

/*! @name FSTDBYCTL - Flash Standby Control Register */
/*! @{ */

#define FTFE_FSTDBYCTL_STDBYDIS_MASK             (0x1U)
#define FTFE_FSTDBYCTL_STDBYDIS_SHIFT            (0U)
/*! STDBYDIS - Standy Mode Disable
 *  0b0..Standby mode enabled for flash blocks selected by STDBYx
 *  0b1..Standby mode disabled (STDBYx ignored)
 */
#define FTFE_FSTDBYCTL_STDBYDIS(x)               (((uint8_t)(((uint8_t)(x)) << FTFE_FSTDBYCTL_STDBYDIS_SHIFT)) & FTFE_FSTDBYCTL_STDBYDIS_MASK)
/*! @} */

/*! @name FSTDBY - Flash Standby Register */
/*! @{ */

#define FTFE_FSTDBY_STDBY0_MASK                  (0x1U)
#define FTFE_FSTDBY_STDBY0_SHIFT                 (0U)
/*! STDBY0 - Standy Mode for Flash Block 0
 *  0b0..Standby mode not enabled for flash block 0
 *  0b1..If STDBYDIS is clear, standby mode is enabled for flash block 0 (when SWAP=0/1, flash block 1/0 is the inactive block)
 */
#define FTFE_FSTDBY_STDBY0(x)                    (((uint8_t)(((uint8_t)(x)) << FTFE_FSTDBY_STDBY0_SHIFT)) & FTFE_FSTDBY_STDBY0_MASK)

#define FTFE_FSTDBY_STDBY1_MASK                  (0x2U)
#define FTFE_FSTDBY_STDBY1_SHIFT                 (1U)
/*! STDBY1 - Standy Mode for Flash Block 1
 *  0b0..Standby mode not enabled for flash block 1
 *  0b1..If STDBYDIS is clear, standby mode is enabled for flash block 1 (when SWAP=0/1, flash block 1/0 is the inactive block)
 */
#define FTFE_FSTDBY_STDBY1(x)                    (((uint8_t)(((uint8_t)(x)) << FTFE_FSTDBY_STDBY1_SHIFT)) & FTFE_FSTDBY_STDBY1_MASK)

#define FTFE_FSTDBY_STDBY2_MASK                  (0x4U)
#define FTFE_FSTDBY_STDBY2_SHIFT                 (2U)
/*! STDBY2 - Standy Mode for Flash Block 2
 *  0b0..Standby mode not enabled for flash block 2
 *  0b1..If STDBYDIS is clear, standby mode is enabled for flash block 2
 */
#define FTFE_FSTDBY_STDBY2(x)                    (((uint8_t)(((uint8_t)(x)) << FTFE_FSTDBY_STDBY2_SHIFT)) & FTFE_FSTDBY_STDBY2_MASK)
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

