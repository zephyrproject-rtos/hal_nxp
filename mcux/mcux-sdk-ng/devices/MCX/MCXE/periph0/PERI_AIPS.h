/*
** ###################################################################
**     Processors:          MCXE247VLL
**                          MCXE247VLQ
**
**     Version:             rev. 1.0, 2025-02-21
**     Build:               b250417
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AIPS
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
 * @file PERI_AIPS.h
 * @version 1.0
 * @date 2025-02-21
 * @brief CMSIS Peripheral Access Layer for AIPS
 *
 * CMSIS Peripheral Access Layer for AIPS
 */

#if !defined(PERI_AIPS_H_)
#define PERI_AIPS_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE247VLL) || defined(CPU_MCXE247VLQ))
#include "MCXE247_COMMON.h"
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
   -- AIPS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AIPS_Peripheral_Access_Layer AIPS Peripheral Access Layer
 * @{
 */

/** AIPS - Register Layout Typedef */
typedef struct {
  __IO uint32_t MPRA;                              /**< Master Privilege Register A, offset: 0x0 */
       uint8_t RESERVED_0[28];
  __IO uint32_t PACRA;                             /**< Peripheral Access Control Register, offset: 0x20 */
  __IO uint32_t PACRB;                             /**< Peripheral Access Control Register, offset: 0x24 */
       uint8_t RESERVED_1[4];
  __IO uint32_t PACRD;                             /**< Peripheral Access Control Register, offset: 0x2C */
       uint8_t RESERVED_2[16];
  __IO uint32_t OPACRA;                            /**< Off-Platform Peripheral Access Control Register, offset: 0x40 */
  __IO uint32_t OPACRB;                            /**< Off-Platform Peripheral Access Control Register, offset: 0x44 */
  __IO uint32_t OPACRC;                            /**< Off-Platform Peripheral Access Control Register, offset: 0x48 */
  __IO uint32_t OPACRD;                            /**< Off-Platform Peripheral Access Control Register, offset: 0x4C */
  __IO uint32_t OPACRE;                            /**< Off-Platform Peripheral Access Control Register, offset: 0x50 */
  __IO uint32_t OPACRF;                            /**< Off-Platform Peripheral Access Control Register, offset: 0x54 */
  __IO uint32_t OPACRG;                            /**< Off-Platform Peripheral Access Control Register, offset: 0x58 */
  __IO uint32_t OPACRH;                            /**< Off-Platform Peripheral Access Control Register, offset: 0x5C */
  __IO uint32_t OPACRI;                            /**< Off-Platform Peripheral Access Control Register, offset: 0x60 */
  __IO uint32_t OPACRJ;                            /**< Off-Platform Peripheral Access Control Register, offset: 0x64 */
  __IO uint32_t OPACRK;                            /**< Off-Platform Peripheral Access Control Register, offset: 0x68 */
  __IO uint32_t OPACRL;                            /**< Off-Platform Peripheral Access Control Register, offset: 0x6C */
} AIPS_Type;

/* ----------------------------------------------------------------------------
   -- AIPS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AIPS_Register_Masks AIPS Register Masks
 * @{
 */

/*! @name MPRA - Master Privilege Register A */
/*! @{ */

#define AIPS_MPRA_MPL3_MASK                      (0x10000U)
#define AIPS_MPRA_MPL3_SHIFT                     (16U)
/*! MPL3 - Master 3 Privilege Level
 *  0b0..Accesses from this master are forced to user-mode.
 *  0b1..Accesses from this master are not forced to user-mode.
 */
#define AIPS_MPRA_MPL3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_MPRA_MPL3_SHIFT)) & AIPS_MPRA_MPL3_MASK)

#define AIPS_MPRA_MTW3_MASK                      (0x20000U)
#define AIPS_MPRA_MTW3_SHIFT                     (17U)
/*! MTW3 - Master 3 Trusted For Writes
 *  0b0..This master is not trusted for write accesses.
 *  0b1..This master is trusted for write accesses.
 */
#define AIPS_MPRA_MTW3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_MPRA_MTW3_SHIFT)) & AIPS_MPRA_MTW3_MASK)

#define AIPS_MPRA_MTR3_MASK                      (0x40000U)
#define AIPS_MPRA_MTR3_SHIFT                     (18U)
/*! MTR3 - Master 3 Trusted For Read
 *  0b0..This master is not trusted for read accesses.
 *  0b1..This master is trusted for read accesses.
 */
#define AIPS_MPRA_MTR3(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_MPRA_MTR3_SHIFT)) & AIPS_MPRA_MTR3_MASK)

#define AIPS_MPRA_MPL2_MASK                      (0x100000U)
#define AIPS_MPRA_MPL2_SHIFT                     (20U)
/*! MPL2 - Master 2 Privilege Level
 *  0b0..Accesses from this master are forced to user-mode.
 *  0b1..Accesses from this master are not forced to user-mode.
 */
#define AIPS_MPRA_MPL2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_MPRA_MPL2_SHIFT)) & AIPS_MPRA_MPL2_MASK)

#define AIPS_MPRA_MTW2_MASK                      (0x200000U)
#define AIPS_MPRA_MTW2_SHIFT                     (21U)
/*! MTW2 - Master 2 Trusted For Writes
 *  0b0..This master is not trusted for write accesses.
 *  0b1..This master is trusted for write accesses.
 */
#define AIPS_MPRA_MTW2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_MPRA_MTW2_SHIFT)) & AIPS_MPRA_MTW2_MASK)

#define AIPS_MPRA_MTR2_MASK                      (0x400000U)
#define AIPS_MPRA_MTR2_SHIFT                     (22U)
/*! MTR2 - Master 2 Trusted For Read
 *  0b0..This master is not trusted for read accesses.
 *  0b1..This master is trusted for read accesses.
 */
#define AIPS_MPRA_MTR2(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_MPRA_MTR2_SHIFT)) & AIPS_MPRA_MTR2_MASK)

#define AIPS_MPRA_MPL1_MASK                      (0x1000000U)
#define AIPS_MPRA_MPL1_SHIFT                     (24U)
/*! MPL1 - Master 1 Privilege Level
 *  0b0..Accesses from this master are forced to user-mode.
 *  0b1..Accesses from this master are not forced to user-mode.
 */
#define AIPS_MPRA_MPL1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_MPRA_MPL1_SHIFT)) & AIPS_MPRA_MPL1_MASK)

#define AIPS_MPRA_MTW1_MASK                      (0x2000000U)
#define AIPS_MPRA_MTW1_SHIFT                     (25U)
/*! MTW1 - Master 1 Trusted for Writes
 *  0b0..This master is not trusted for write accesses.
 *  0b1..This master is trusted for write accesses.
 */
#define AIPS_MPRA_MTW1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_MPRA_MTW1_SHIFT)) & AIPS_MPRA_MTW1_MASK)

#define AIPS_MPRA_MTR1_MASK                      (0x4000000U)
#define AIPS_MPRA_MTR1_SHIFT                     (26U)
/*! MTR1 - Master 1 Trusted for Read
 *  0b0..This master is not trusted for read accesses.
 *  0b1..This master is trusted for read accesses.
 */
#define AIPS_MPRA_MTR1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_MPRA_MTR1_SHIFT)) & AIPS_MPRA_MTR1_MASK)

#define AIPS_MPRA_MPL0_MASK                      (0x10000000U)
#define AIPS_MPRA_MPL0_SHIFT                     (28U)
/*! MPL0 - Master 0 Privilege Level
 *  0b0..Accesses from this master are forced to user-mode.
 *  0b1..Accesses from this master are not forced to user-mode.
 */
#define AIPS_MPRA_MPL0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_MPRA_MPL0_SHIFT)) & AIPS_MPRA_MPL0_MASK)

#define AIPS_MPRA_MTW0_MASK                      (0x20000000U)
#define AIPS_MPRA_MTW0_SHIFT                     (29U)
/*! MTW0 - Master 0 Trusted For Writes
 *  0b0..This master is not trusted for write accesses.
 *  0b1..This master is trusted for write accesses.
 */
#define AIPS_MPRA_MTW0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_MPRA_MTW0_SHIFT)) & AIPS_MPRA_MTW0_MASK)

#define AIPS_MPRA_MTR0_MASK                      (0x40000000U)
#define AIPS_MPRA_MTR0_SHIFT                     (30U)
/*! MTR0 - Master 0 Trusted For Read
 *  0b0..This master is not trusted for read accesses.
 *  0b1..This master is trusted for read accesses.
 */
#define AIPS_MPRA_MTR0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_MPRA_MTR0_SHIFT)) & AIPS_MPRA_MTR0_MASK)
/*! @} */

/*! @name PACRA - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRA_TP1_MASK                      (0x1000000U)
#define AIPS_PACRA_TP1_SHIFT                     (24U)
/*! TP1 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_PACRA_TP1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_TP1_SHIFT)) & AIPS_PACRA_TP1_MASK)

#define AIPS_PACRA_WP1_MASK                      (0x2000000U)
#define AIPS_PACRA_WP1_SHIFT                     (25U)
/*! WP1 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_PACRA_WP1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_WP1_SHIFT)) & AIPS_PACRA_WP1_MASK)

#define AIPS_PACRA_SP1_MASK                      (0x4000000U)
#define AIPS_PACRA_SP1_SHIFT                     (26U)
/*! SP1 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_PACRA_SP1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_SP1_SHIFT)) & AIPS_PACRA_SP1_MASK)

#define AIPS_PACRA_TP0_MASK                      (0x10000000U)
#define AIPS_PACRA_TP0_SHIFT                     (28U)
/*! TP0 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_PACRA_TP0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_TP0_SHIFT)) & AIPS_PACRA_TP0_MASK)

#define AIPS_PACRA_WP0_MASK                      (0x20000000U)
#define AIPS_PACRA_WP0_SHIFT                     (29U)
/*! WP0 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_PACRA_WP0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_WP0_SHIFT)) & AIPS_PACRA_WP0_MASK)

#define AIPS_PACRA_SP0_MASK                      (0x40000000U)
#define AIPS_PACRA_SP0_SHIFT                     (30U)
/*! SP0 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_PACRA_SP0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRA_SP0_SHIFT)) & AIPS_PACRA_SP0_MASK)
/*! @} */

/*! @name PACRB - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRB_TP5_MASK                      (0x100U)
#define AIPS_PACRB_TP5_SHIFT                     (8U)
/*! TP5 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_PACRB_TP5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_TP5_SHIFT)) & AIPS_PACRB_TP5_MASK)

#define AIPS_PACRB_WP5_MASK                      (0x200U)
#define AIPS_PACRB_WP5_SHIFT                     (9U)
/*! WP5 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_PACRB_WP5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_WP5_SHIFT)) & AIPS_PACRB_WP5_MASK)

#define AIPS_PACRB_SP5_MASK                      (0x400U)
#define AIPS_PACRB_SP5_SHIFT                     (10U)
/*! SP5 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_PACRB_SP5(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_SP5_SHIFT)) & AIPS_PACRB_SP5_MASK)

#define AIPS_PACRB_TP1_MASK                      (0x1000000U)
#define AIPS_PACRB_TP1_SHIFT                     (24U)
/*! TP1 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_PACRB_TP1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_TP1_SHIFT)) & AIPS_PACRB_TP1_MASK)

#define AIPS_PACRB_WP1_MASK                      (0x2000000U)
#define AIPS_PACRB_WP1_SHIFT                     (25U)
/*! WP1 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_PACRB_WP1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_WP1_SHIFT)) & AIPS_PACRB_WP1_MASK)

#define AIPS_PACRB_SP1_MASK                      (0x4000000U)
#define AIPS_PACRB_SP1_SHIFT                     (26U)
/*! SP1 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_PACRB_SP1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_SP1_SHIFT)) & AIPS_PACRB_SP1_MASK)

#define AIPS_PACRB_TP0_MASK                      (0x10000000U)
#define AIPS_PACRB_TP0_SHIFT                     (28U)
/*! TP0 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_PACRB_TP0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_TP0_SHIFT)) & AIPS_PACRB_TP0_MASK)

#define AIPS_PACRB_WP0_MASK                      (0x20000000U)
#define AIPS_PACRB_WP0_SHIFT                     (29U)
/*! WP0 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_PACRB_WP0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_WP0_SHIFT)) & AIPS_PACRB_WP0_MASK)

#define AIPS_PACRB_SP0_MASK                      (0x40000000U)
#define AIPS_PACRB_SP0_SHIFT                     (30U)
/*! SP0 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_PACRB_SP0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRB_SP0_SHIFT)) & AIPS_PACRB_SP0_MASK)
/*! @} */

/*! @name PACRD - Peripheral Access Control Register */
/*! @{ */

#define AIPS_PACRD_TP1_MASK                      (0x1000000U)
#define AIPS_PACRD_TP1_SHIFT                     (24U)
/*! TP1 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_PACRD_TP1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRD_TP1_SHIFT)) & AIPS_PACRD_TP1_MASK)

#define AIPS_PACRD_WP1_MASK                      (0x2000000U)
#define AIPS_PACRD_WP1_SHIFT                     (25U)
/*! WP1 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_PACRD_WP1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRD_WP1_SHIFT)) & AIPS_PACRD_WP1_MASK)

#define AIPS_PACRD_SP1_MASK                      (0x4000000U)
#define AIPS_PACRD_SP1_SHIFT                     (26U)
/*! SP1 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_PACRD_SP1(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRD_SP1_SHIFT)) & AIPS_PACRD_SP1_MASK)

#define AIPS_PACRD_TP0_MASK                      (0x10000000U)
#define AIPS_PACRD_TP0_SHIFT                     (28U)
/*! TP0 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_PACRD_TP0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRD_TP0_SHIFT)) & AIPS_PACRD_TP0_MASK)

#define AIPS_PACRD_WP0_MASK                      (0x20000000U)
#define AIPS_PACRD_WP0_SHIFT                     (29U)
/*! WP0 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_PACRD_WP0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRD_WP0_SHIFT)) & AIPS_PACRD_WP0_MASK)

#define AIPS_PACRD_SP0_MASK                      (0x40000000U)
#define AIPS_PACRD_SP0_SHIFT                     (30U)
/*! SP0 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_PACRD_SP0(x)                        (((uint32_t)(((uint32_t)(x)) << AIPS_PACRD_SP0_SHIFT)) & AIPS_PACRD_SP0_MASK)
/*! @} */

/*! @name OPACRA - Off-Platform Peripheral Access Control Register */
/*! @{ */

#define AIPS_OPACRA_TP7_MASK                     (0x1U)
#define AIPS_OPACRA_TP7_SHIFT                    (0U)
/*! TP7 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRA_TP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_TP7_SHIFT)) & AIPS_OPACRA_TP7_MASK)

#define AIPS_OPACRA_WP7_MASK                     (0x2U)
#define AIPS_OPACRA_WP7_SHIFT                    (1U)
/*! WP7 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRA_WP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_WP7_SHIFT)) & AIPS_OPACRA_WP7_MASK)

#define AIPS_OPACRA_SP7_MASK                     (0x4U)
#define AIPS_OPACRA_SP7_SHIFT                    (2U)
/*! SP7 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRA_SP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_SP7_SHIFT)) & AIPS_OPACRA_SP7_MASK)

#define AIPS_OPACRA_TP6_MASK                     (0x10U)
#define AIPS_OPACRA_TP6_SHIFT                    (4U)
/*! TP6 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRA_TP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_TP6_SHIFT)) & AIPS_OPACRA_TP6_MASK)

#define AIPS_OPACRA_WP6_MASK                     (0x20U)
#define AIPS_OPACRA_WP6_SHIFT                    (5U)
/*! WP6 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRA_WP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_WP6_SHIFT)) & AIPS_OPACRA_WP6_MASK)

#define AIPS_OPACRA_SP6_MASK                     (0x40U)
#define AIPS_OPACRA_SP6_SHIFT                    (6U)
/*! SP6 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRA_SP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_SP6_SHIFT)) & AIPS_OPACRA_SP6_MASK)

#define AIPS_OPACRA_TP5_MASK                     (0x100U)
#define AIPS_OPACRA_TP5_SHIFT                    (8U)
/*! TP5 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRA_TP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_TP5_SHIFT)) & AIPS_OPACRA_TP5_MASK)

#define AIPS_OPACRA_WP5_MASK                     (0x200U)
#define AIPS_OPACRA_WP5_SHIFT                    (9U)
/*! WP5 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRA_WP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_WP5_SHIFT)) & AIPS_OPACRA_WP5_MASK)

#define AIPS_OPACRA_SP5_MASK                     (0x400U)
#define AIPS_OPACRA_SP5_SHIFT                    (10U)
/*! SP5 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRA_SP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_SP5_SHIFT)) & AIPS_OPACRA_SP5_MASK)

#define AIPS_OPACRA_TP4_MASK                     (0x1000U)
#define AIPS_OPACRA_TP4_SHIFT                    (12U)
/*! TP4 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRA_TP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_TP4_SHIFT)) & AIPS_OPACRA_TP4_MASK)

#define AIPS_OPACRA_WP4_MASK                     (0x2000U)
#define AIPS_OPACRA_WP4_SHIFT                    (13U)
/*! WP4 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRA_WP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_WP4_SHIFT)) & AIPS_OPACRA_WP4_MASK)

#define AIPS_OPACRA_SP4_MASK                     (0x4000U)
#define AIPS_OPACRA_SP4_SHIFT                    (14U)
/*! SP4 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRA_SP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_SP4_SHIFT)) & AIPS_OPACRA_SP4_MASK)

#define AIPS_OPACRA_TP1_MASK                     (0x1000000U)
#define AIPS_OPACRA_TP1_SHIFT                    (24U)
/*! TP1 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRA_TP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_TP1_SHIFT)) & AIPS_OPACRA_TP1_MASK)

#define AIPS_OPACRA_WP1_MASK                     (0x2000000U)
#define AIPS_OPACRA_WP1_SHIFT                    (25U)
/*! WP1 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRA_WP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_WP1_SHIFT)) & AIPS_OPACRA_WP1_MASK)

#define AIPS_OPACRA_SP1_MASK                     (0x4000000U)
#define AIPS_OPACRA_SP1_SHIFT                    (26U)
/*! SP1 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRA_SP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_SP1_SHIFT)) & AIPS_OPACRA_SP1_MASK)

#define AIPS_OPACRA_TP0_MASK                     (0x10000000U)
#define AIPS_OPACRA_TP0_SHIFT                    (28U)
/*! TP0 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRA_TP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_TP0_SHIFT)) & AIPS_OPACRA_TP0_MASK)

#define AIPS_OPACRA_WP0_MASK                     (0x20000000U)
#define AIPS_OPACRA_WP0_SHIFT                    (29U)
/*! WP0 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRA_WP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_WP0_SHIFT)) & AIPS_OPACRA_WP0_MASK)

#define AIPS_OPACRA_SP0_MASK                     (0x40000000U)
#define AIPS_OPACRA_SP0_SHIFT                    (30U)
/*! SP0 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRA_SP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRA_SP0_SHIFT)) & AIPS_OPACRA_SP0_MASK)
/*! @} */

/*! @name OPACRB - Off-Platform Peripheral Access Control Register */
/*! @{ */

#define AIPS_OPACRB_TP6_MASK                     (0x10U)
#define AIPS_OPACRB_TP6_SHIFT                    (4U)
/*! TP6 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRB_TP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRB_TP6_SHIFT)) & AIPS_OPACRB_TP6_MASK)

#define AIPS_OPACRB_WP6_MASK                     (0x20U)
#define AIPS_OPACRB_WP6_SHIFT                    (5U)
/*! WP6 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRB_WP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRB_WP6_SHIFT)) & AIPS_OPACRB_WP6_MASK)

#define AIPS_OPACRB_SP6_MASK                     (0x40U)
#define AIPS_OPACRB_SP6_SHIFT                    (6U)
/*! SP6 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRB_SP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRB_SP6_SHIFT)) & AIPS_OPACRB_SP6_MASK)

#define AIPS_OPACRB_TP5_MASK                     (0x100U)
#define AIPS_OPACRB_TP5_SHIFT                    (8U)
/*! TP5 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRB_TP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRB_TP5_SHIFT)) & AIPS_OPACRB_TP5_MASK)

#define AIPS_OPACRB_WP5_MASK                     (0x200U)
#define AIPS_OPACRB_WP5_SHIFT                    (9U)
/*! WP5 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRB_WP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRB_WP5_SHIFT)) & AIPS_OPACRB_WP5_MASK)

#define AIPS_OPACRB_SP5_MASK                     (0x400U)
#define AIPS_OPACRB_SP5_SHIFT                    (10U)
/*! SP5 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRB_SP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRB_SP5_SHIFT)) & AIPS_OPACRB_SP5_MASK)

#define AIPS_OPACRB_TP4_MASK                     (0x1000U)
#define AIPS_OPACRB_TP4_SHIFT                    (12U)
/*! TP4 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRB_TP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRB_TP4_SHIFT)) & AIPS_OPACRB_TP4_MASK)

#define AIPS_OPACRB_WP4_MASK                     (0x2000U)
#define AIPS_OPACRB_WP4_SHIFT                    (13U)
/*! WP4 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRB_WP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRB_WP4_SHIFT)) & AIPS_OPACRB_WP4_MASK)

#define AIPS_OPACRB_SP4_MASK                     (0x4000U)
#define AIPS_OPACRB_SP4_SHIFT                    (14U)
/*! SP4 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRB_SP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRB_SP4_SHIFT)) & AIPS_OPACRB_SP4_MASK)

#define AIPS_OPACRB_TP3_MASK                     (0x10000U)
#define AIPS_OPACRB_TP3_SHIFT                    (16U)
/*! TP3 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRB_TP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRB_TP3_SHIFT)) & AIPS_OPACRB_TP3_MASK)

#define AIPS_OPACRB_WP3_MASK                     (0x20000U)
#define AIPS_OPACRB_WP3_SHIFT                    (17U)
/*! WP3 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRB_WP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRB_WP3_SHIFT)) & AIPS_OPACRB_WP3_MASK)

#define AIPS_OPACRB_SP3_MASK                     (0x40000U)
#define AIPS_OPACRB_SP3_SHIFT                    (18U)
/*! SP3 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRB_SP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRB_SP3_SHIFT)) & AIPS_OPACRB_SP3_MASK)
/*! @} */

/*! @name OPACRC - Off-Platform Peripheral Access Control Register */
/*! @{ */

#define AIPS_OPACRC_TP7_MASK                     (0x1U)
#define AIPS_OPACRC_TP7_SHIFT                    (0U)
/*! TP7 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRC_TP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRC_TP7_SHIFT)) & AIPS_OPACRC_TP7_MASK)

#define AIPS_OPACRC_WP7_MASK                     (0x2U)
#define AIPS_OPACRC_WP7_SHIFT                    (1U)
/*! WP7 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRC_WP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRC_WP7_SHIFT)) & AIPS_OPACRC_WP7_MASK)

#define AIPS_OPACRC_SP7_MASK                     (0x4U)
#define AIPS_OPACRC_SP7_SHIFT                    (2U)
/*! SP7 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRC_SP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRC_SP7_SHIFT)) & AIPS_OPACRC_SP7_MASK)

#define AIPS_OPACRC_TP6_MASK                     (0x10U)
#define AIPS_OPACRC_TP6_SHIFT                    (4U)
/*! TP6 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRC_TP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRC_TP6_SHIFT)) & AIPS_OPACRC_TP6_MASK)

#define AIPS_OPACRC_WP6_MASK                     (0x20U)
#define AIPS_OPACRC_WP6_SHIFT                    (5U)
/*! WP6 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRC_WP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRC_WP6_SHIFT)) & AIPS_OPACRC_WP6_MASK)

#define AIPS_OPACRC_SP6_MASK                     (0x40U)
#define AIPS_OPACRC_SP6_SHIFT                    (6U)
/*! SP6 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRC_SP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRC_SP6_SHIFT)) & AIPS_OPACRC_SP6_MASK)

#define AIPS_OPACRC_TP2_MASK                     (0x100000U)
#define AIPS_OPACRC_TP2_SHIFT                    (20U)
/*! TP2 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRC_TP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRC_TP2_SHIFT)) & AIPS_OPACRC_TP2_MASK)

#define AIPS_OPACRC_WP2_MASK                     (0x200000U)
#define AIPS_OPACRC_WP2_SHIFT                    (21U)
/*! WP2 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRC_WP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRC_WP2_SHIFT)) & AIPS_OPACRC_WP2_MASK)

#define AIPS_OPACRC_SP2_MASK                     (0x400000U)
#define AIPS_OPACRC_SP2_SHIFT                    (22U)
/*! SP2 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRC_SP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRC_SP2_SHIFT)) & AIPS_OPACRC_SP2_MASK)

#define AIPS_OPACRC_TP1_MASK                     (0x1000000U)
#define AIPS_OPACRC_TP1_SHIFT                    (24U)
/*! TP1 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRC_TP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRC_TP1_SHIFT)) & AIPS_OPACRC_TP1_MASK)

#define AIPS_OPACRC_WP1_MASK                     (0x2000000U)
#define AIPS_OPACRC_WP1_SHIFT                    (25U)
/*! WP1 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRC_WP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRC_WP1_SHIFT)) & AIPS_OPACRC_WP1_MASK)

#define AIPS_OPACRC_SP1_MASK                     (0x4000000U)
#define AIPS_OPACRC_SP1_SHIFT                    (26U)
/*! SP1 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRC_SP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRC_SP1_SHIFT)) & AIPS_OPACRC_SP1_MASK)
/*! @} */

/*! @name OPACRD - Off-Platform Peripheral Access Control Register */
/*! @{ */

#define AIPS_OPACRD_TP5_MASK                     (0x100U)
#define AIPS_OPACRD_TP5_SHIFT                    (8U)
/*! TP5 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRD_TP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_TP5_SHIFT)) & AIPS_OPACRD_TP5_MASK)

#define AIPS_OPACRD_WP5_MASK                     (0x200U)
#define AIPS_OPACRD_WP5_SHIFT                    (9U)
/*! WP5 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRD_WP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_WP5_SHIFT)) & AIPS_OPACRD_WP5_MASK)

#define AIPS_OPACRD_SP5_MASK                     (0x400U)
#define AIPS_OPACRD_SP5_SHIFT                    (10U)
/*! SP5 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRD_SP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_SP5_SHIFT)) & AIPS_OPACRD_SP5_MASK)

#define AIPS_OPACRD_TP3_MASK                     (0x10000U)
#define AIPS_OPACRD_TP3_SHIFT                    (16U)
/*! TP3 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRD_TP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_TP3_SHIFT)) & AIPS_OPACRD_TP3_MASK)

#define AIPS_OPACRD_WP3_MASK                     (0x20000U)
#define AIPS_OPACRD_WP3_SHIFT                    (17U)
/*! WP3 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRD_WP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_WP3_SHIFT)) & AIPS_OPACRD_WP3_MASK)

#define AIPS_OPACRD_SP3_MASK                     (0x40000U)
#define AIPS_OPACRD_SP3_SHIFT                    (18U)
/*! SP3 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRD_SP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_SP3_SHIFT)) & AIPS_OPACRD_SP3_MASK)

#define AIPS_OPACRD_TP2_MASK                     (0x100000U)
#define AIPS_OPACRD_TP2_SHIFT                    (20U)
/*! TP2 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRD_TP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_TP2_SHIFT)) & AIPS_OPACRD_TP2_MASK)

#define AIPS_OPACRD_WP2_MASK                     (0x200000U)
#define AIPS_OPACRD_WP2_SHIFT                    (21U)
/*! WP2 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRD_WP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_WP2_SHIFT)) & AIPS_OPACRD_WP2_MASK)

#define AIPS_OPACRD_SP2_MASK                     (0x400000U)
#define AIPS_OPACRD_SP2_SHIFT                    (22U)
/*! SP2 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRD_SP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_SP2_SHIFT)) & AIPS_OPACRD_SP2_MASK)

#define AIPS_OPACRD_TP1_MASK                     (0x1000000U)
#define AIPS_OPACRD_TP1_SHIFT                    (24U)
/*! TP1 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRD_TP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_TP1_SHIFT)) & AIPS_OPACRD_TP1_MASK)

#define AIPS_OPACRD_WP1_MASK                     (0x2000000U)
#define AIPS_OPACRD_WP1_SHIFT                    (25U)
/*! WP1 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRD_WP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_WP1_SHIFT)) & AIPS_OPACRD_WP1_MASK)

#define AIPS_OPACRD_SP1_MASK                     (0x4000000U)
#define AIPS_OPACRD_SP1_SHIFT                    (26U)
/*! SP1 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRD_SP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_SP1_SHIFT)) & AIPS_OPACRD_SP1_MASK)

#define AIPS_OPACRD_TP0_MASK                     (0x10000000U)
#define AIPS_OPACRD_TP0_SHIFT                    (28U)
/*! TP0 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRD_TP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_TP0_SHIFT)) & AIPS_OPACRD_TP0_MASK)

#define AIPS_OPACRD_WP0_MASK                     (0x20000000U)
#define AIPS_OPACRD_WP0_SHIFT                    (29U)
/*! WP0 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRD_WP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_WP0_SHIFT)) & AIPS_OPACRD_WP0_MASK)

#define AIPS_OPACRD_SP0_MASK                     (0x40000000U)
#define AIPS_OPACRD_SP0_SHIFT                    (30U)
/*! SP0 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRD_SP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRD_SP0_SHIFT)) & AIPS_OPACRD_SP0_MASK)
/*! @} */

/*! @name OPACRE - Off-Platform Peripheral Access Control Register */
/*! @{ */

#define AIPS_OPACRE_TP6_MASK                     (0x10U)
#define AIPS_OPACRE_TP6_SHIFT                    (4U)
/*! TP6 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRE_TP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRE_TP6_SHIFT)) & AIPS_OPACRE_TP6_MASK)

#define AIPS_OPACRE_WP6_MASK                     (0x20U)
#define AIPS_OPACRE_WP6_SHIFT                    (5U)
/*! WP6 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRE_WP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRE_WP6_SHIFT)) & AIPS_OPACRE_WP6_MASK)

#define AIPS_OPACRE_SP6_MASK                     (0x40U)
#define AIPS_OPACRE_SP6_SHIFT                    (6U)
/*! SP6 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRE_SP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRE_SP6_SHIFT)) & AIPS_OPACRE_SP6_MASK)

#define AIPS_OPACRE_TP0_MASK                     (0x10000000U)
#define AIPS_OPACRE_TP0_SHIFT                    (28U)
/*! TP0 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRE_TP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRE_TP0_SHIFT)) & AIPS_OPACRE_TP0_MASK)

#define AIPS_OPACRE_WP0_MASK                     (0x20000000U)
#define AIPS_OPACRE_WP0_SHIFT                    (29U)
/*! WP0 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRE_WP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRE_WP0_SHIFT)) & AIPS_OPACRE_WP0_MASK)

#define AIPS_OPACRE_SP0_MASK                     (0x40000000U)
#define AIPS_OPACRE_SP0_SHIFT                    (30U)
/*! SP0 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRE_SP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRE_SP0_SHIFT)) & AIPS_OPACRE_SP0_MASK)
/*! @} */

/*! @name OPACRF - Off-Platform Peripheral Access Control Register */
/*! @{ */

#define AIPS_OPACRF_TP5_MASK                     (0x100U)
#define AIPS_OPACRF_TP5_SHIFT                    (8U)
/*! TP5 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRF_TP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_TP5_SHIFT)) & AIPS_OPACRF_TP5_MASK)

#define AIPS_OPACRF_WP5_MASK                     (0x200U)
#define AIPS_OPACRF_WP5_SHIFT                    (9U)
/*! WP5 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRF_WP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_WP5_SHIFT)) & AIPS_OPACRF_WP5_MASK)

#define AIPS_OPACRF_SP5_MASK                     (0x400U)
#define AIPS_OPACRF_SP5_SHIFT                    (10U)
/*! SP5 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRF_SP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_SP5_SHIFT)) & AIPS_OPACRF_SP5_MASK)

#define AIPS_OPACRF_TP4_MASK                     (0x1000U)
#define AIPS_OPACRF_TP4_SHIFT                    (12U)
/*! TP4 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRF_TP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_TP4_SHIFT)) & AIPS_OPACRF_TP4_MASK)

#define AIPS_OPACRF_WP4_MASK                     (0x2000U)
#define AIPS_OPACRF_WP4_SHIFT                    (13U)
/*! WP4 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRF_WP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_WP4_SHIFT)) & AIPS_OPACRF_WP4_MASK)

#define AIPS_OPACRF_SP4_MASK                     (0x4000U)
#define AIPS_OPACRF_SP4_SHIFT                    (14U)
/*! SP4 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRF_SP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_SP4_SHIFT)) & AIPS_OPACRF_SP4_MASK)

#define AIPS_OPACRF_TP3_MASK                     (0x10000U)
#define AIPS_OPACRF_TP3_SHIFT                    (16U)
/*! TP3 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRF_TP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_TP3_SHIFT)) & AIPS_OPACRF_TP3_MASK)

#define AIPS_OPACRF_WP3_MASK                     (0x20000U)
#define AIPS_OPACRF_WP3_SHIFT                    (17U)
/*! WP3 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRF_WP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_WP3_SHIFT)) & AIPS_OPACRF_WP3_MASK)

#define AIPS_OPACRF_SP3_MASK                     (0x40000U)
#define AIPS_OPACRF_SP3_SHIFT                    (18U)
/*! SP3 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRF_SP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_SP3_SHIFT)) & AIPS_OPACRF_SP3_MASK)

#define AIPS_OPACRF_TP2_MASK                     (0x100000U)
#define AIPS_OPACRF_TP2_SHIFT                    (20U)
/*! TP2 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRF_TP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_TP2_SHIFT)) & AIPS_OPACRF_TP2_MASK)

#define AIPS_OPACRF_WP2_MASK                     (0x200000U)
#define AIPS_OPACRF_WP2_SHIFT                    (21U)
/*! WP2 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRF_WP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_WP2_SHIFT)) & AIPS_OPACRF_WP2_MASK)

#define AIPS_OPACRF_SP2_MASK                     (0x400000U)
#define AIPS_OPACRF_SP2_SHIFT                    (22U)
/*! SP2 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRF_SP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_SP2_SHIFT)) & AIPS_OPACRF_SP2_MASK)

#define AIPS_OPACRF_TP1_MASK                     (0x1000000U)
#define AIPS_OPACRF_TP1_SHIFT                    (24U)
/*! TP1 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRF_TP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_TP1_SHIFT)) & AIPS_OPACRF_TP1_MASK)

#define AIPS_OPACRF_WP1_MASK                     (0x2000000U)
#define AIPS_OPACRF_WP1_SHIFT                    (25U)
/*! WP1 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRF_WP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_WP1_SHIFT)) & AIPS_OPACRF_WP1_MASK)

#define AIPS_OPACRF_SP1_MASK                     (0x4000000U)
#define AIPS_OPACRF_SP1_SHIFT                    (26U)
/*! SP1 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRF_SP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_SP1_SHIFT)) & AIPS_OPACRF_SP1_MASK)

#define AIPS_OPACRF_TP0_MASK                     (0x10000000U)
#define AIPS_OPACRF_TP0_SHIFT                    (28U)
/*! TP0 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRF_TP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_TP0_SHIFT)) & AIPS_OPACRF_TP0_MASK)

#define AIPS_OPACRF_WP0_MASK                     (0x20000000U)
#define AIPS_OPACRF_WP0_SHIFT                    (29U)
/*! WP0 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRF_WP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_WP0_SHIFT)) & AIPS_OPACRF_WP0_MASK)

#define AIPS_OPACRF_SP0_MASK                     (0x40000000U)
#define AIPS_OPACRF_SP0_SHIFT                    (30U)
/*! SP0 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRF_SP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRF_SP0_SHIFT)) & AIPS_OPACRF_SP0_MASK)
/*! @} */

/*! @name OPACRG - Off-Platform Peripheral Access Control Register */
/*! @{ */

#define AIPS_OPACRG_TP5_MASK                     (0x100U)
#define AIPS_OPACRG_TP5_SHIFT                    (8U)
/*! TP5 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRG_TP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRG_TP5_SHIFT)) & AIPS_OPACRG_TP5_MASK)

#define AIPS_OPACRG_WP5_MASK                     (0x200U)
#define AIPS_OPACRG_WP5_SHIFT                    (9U)
/*! WP5 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRG_WP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRG_WP5_SHIFT)) & AIPS_OPACRG_WP5_MASK)

#define AIPS_OPACRG_SP5_MASK                     (0x400U)
#define AIPS_OPACRG_SP5_SHIFT                    (10U)
/*! SP5 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRG_SP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRG_SP5_SHIFT)) & AIPS_OPACRG_SP5_MASK)

#define AIPS_OPACRG_TP4_MASK                     (0x1000U)
#define AIPS_OPACRG_TP4_SHIFT                    (12U)
/*! TP4 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRG_TP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRG_TP4_SHIFT)) & AIPS_OPACRG_TP4_MASK)

#define AIPS_OPACRG_WP4_MASK                     (0x2000U)
#define AIPS_OPACRG_WP4_SHIFT                    (13U)
/*! WP4 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRG_WP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRG_WP4_SHIFT)) & AIPS_OPACRG_WP4_MASK)

#define AIPS_OPACRG_SP4_MASK                     (0x4000U)
#define AIPS_OPACRG_SP4_SHIFT                    (14U)
/*! SP4 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRG_SP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRG_SP4_SHIFT)) & AIPS_OPACRG_SP4_MASK)

#define AIPS_OPACRG_TP2_MASK                     (0x100000U)
#define AIPS_OPACRG_TP2_SHIFT                    (20U)
/*! TP2 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRG_TP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRG_TP2_SHIFT)) & AIPS_OPACRG_TP2_MASK)

#define AIPS_OPACRG_WP2_MASK                     (0x200000U)
#define AIPS_OPACRG_WP2_SHIFT                    (21U)
/*! WP2 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRG_WP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRG_WP2_SHIFT)) & AIPS_OPACRG_WP2_MASK)

#define AIPS_OPACRG_SP2_MASK                     (0x400000U)
#define AIPS_OPACRG_SP2_SHIFT                    (22U)
/*! SP2 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRG_SP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRG_SP2_SHIFT)) & AIPS_OPACRG_SP2_MASK)
/*! @} */

/*! @name OPACRH - Off-Platform Peripheral Access Control Register */
/*! @{ */

#define AIPS_OPACRH_TP2_MASK                     (0x100000U)
#define AIPS_OPACRH_TP2_SHIFT                    (20U)
/*! TP2 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRH_TP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRH_TP2_SHIFT)) & AIPS_OPACRH_TP2_MASK)

#define AIPS_OPACRH_WP2_MASK                     (0x200000U)
#define AIPS_OPACRH_WP2_SHIFT                    (21U)
/*! WP2 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRH_WP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRH_WP2_SHIFT)) & AIPS_OPACRH_WP2_MASK)

#define AIPS_OPACRH_SP2_MASK                     (0x400000U)
#define AIPS_OPACRH_SP2_SHIFT                    (22U)
/*! SP2 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRH_SP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRH_SP2_SHIFT)) & AIPS_OPACRH_SP2_MASK)
/*! @} */

/*! @name OPACRI - Off-Platform Peripheral Access Control Register */
/*! @{ */

#define AIPS_OPACRI_TP7_MASK                     (0x1U)
#define AIPS_OPACRI_TP7_SHIFT                    (0U)
/*! TP7 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRI_TP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_TP7_SHIFT)) & AIPS_OPACRI_TP7_MASK)

#define AIPS_OPACRI_WP7_MASK                     (0x2U)
#define AIPS_OPACRI_WP7_SHIFT                    (1U)
/*! WP7 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRI_WP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_WP7_SHIFT)) & AIPS_OPACRI_WP7_MASK)

#define AIPS_OPACRI_SP7_MASK                     (0x4U)
#define AIPS_OPACRI_SP7_SHIFT                    (2U)
/*! SP7 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRI_SP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_SP7_SHIFT)) & AIPS_OPACRI_SP7_MASK)

#define AIPS_OPACRI_TP6_MASK                     (0x10U)
#define AIPS_OPACRI_TP6_SHIFT                    (4U)
/*! TP6 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRI_TP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_TP6_SHIFT)) & AIPS_OPACRI_TP6_MASK)

#define AIPS_OPACRI_WP6_MASK                     (0x20U)
#define AIPS_OPACRI_WP6_SHIFT                    (5U)
/*! WP6 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRI_WP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_WP6_SHIFT)) & AIPS_OPACRI_WP6_MASK)

#define AIPS_OPACRI_SP6_MASK                     (0x40U)
#define AIPS_OPACRI_SP6_SHIFT                    (6U)
/*! SP6 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRI_SP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_SP6_SHIFT)) & AIPS_OPACRI_SP6_MASK)

#define AIPS_OPACRI_TP5_MASK                     (0x100U)
#define AIPS_OPACRI_TP5_SHIFT                    (8U)
/*! TP5 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRI_TP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_TP5_SHIFT)) & AIPS_OPACRI_TP5_MASK)

#define AIPS_OPACRI_WP5_MASK                     (0x200U)
#define AIPS_OPACRI_WP5_SHIFT                    (9U)
/*! WP5 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRI_WP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_WP5_SHIFT)) & AIPS_OPACRI_WP5_MASK)

#define AIPS_OPACRI_SP5_MASK                     (0x400U)
#define AIPS_OPACRI_SP5_SHIFT                    (10U)
/*! SP5 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRI_SP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_SP5_SHIFT)) & AIPS_OPACRI_SP5_MASK)

#define AIPS_OPACRI_TP4_MASK                     (0x1000U)
#define AIPS_OPACRI_TP4_SHIFT                    (12U)
/*! TP4 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRI_TP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_TP4_SHIFT)) & AIPS_OPACRI_TP4_MASK)

#define AIPS_OPACRI_WP4_MASK                     (0x2000U)
#define AIPS_OPACRI_WP4_SHIFT                    (13U)
/*! WP4 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRI_WP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_WP4_SHIFT)) & AIPS_OPACRI_WP4_MASK)

#define AIPS_OPACRI_SP4_MASK                     (0x4000U)
#define AIPS_OPACRI_SP4_SHIFT                    (14U)
/*! SP4 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRI_SP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_SP4_SHIFT)) & AIPS_OPACRI_SP4_MASK)

#define AIPS_OPACRI_TP3_MASK                     (0x10000U)
#define AIPS_OPACRI_TP3_SHIFT                    (16U)
/*! TP3 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRI_TP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_TP3_SHIFT)) & AIPS_OPACRI_TP3_MASK)

#define AIPS_OPACRI_WP3_MASK                     (0x20000U)
#define AIPS_OPACRI_WP3_SHIFT                    (17U)
/*! WP3 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRI_WP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_WP3_SHIFT)) & AIPS_OPACRI_WP3_MASK)

#define AIPS_OPACRI_SP3_MASK                     (0x40000U)
#define AIPS_OPACRI_SP3_SHIFT                    (18U)
/*! SP3 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRI_SP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_SP3_SHIFT)) & AIPS_OPACRI_SP3_MASK)

#define AIPS_OPACRI_TP1_MASK                     (0x1000000U)
#define AIPS_OPACRI_TP1_SHIFT                    (24U)
/*! TP1 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRI_TP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_TP1_SHIFT)) & AIPS_OPACRI_TP1_MASK)

#define AIPS_OPACRI_WP1_MASK                     (0x2000000U)
#define AIPS_OPACRI_WP1_SHIFT                    (25U)
/*! WP1 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRI_WP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_WP1_SHIFT)) & AIPS_OPACRI_WP1_MASK)

#define AIPS_OPACRI_SP1_MASK                     (0x4000000U)
#define AIPS_OPACRI_SP1_SHIFT                    (26U)
/*! SP1 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRI_SP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRI_SP1_SHIFT)) & AIPS_OPACRI_SP1_MASK)
/*! @} */

/*! @name OPACRJ - Off-Platform Peripheral Access Control Register */
/*! @{ */

#define AIPS_OPACRJ_TP7_MASK                     (0x1U)
#define AIPS_OPACRJ_TP7_SHIFT                    (0U)
/*! TP7 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRJ_TP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_TP7_SHIFT)) & AIPS_OPACRJ_TP7_MASK)

#define AIPS_OPACRJ_WP7_MASK                     (0x2U)
#define AIPS_OPACRJ_WP7_SHIFT                    (1U)
/*! WP7 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRJ_WP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_WP7_SHIFT)) & AIPS_OPACRJ_WP7_MASK)

#define AIPS_OPACRJ_SP7_MASK                     (0x4U)
#define AIPS_OPACRJ_SP7_SHIFT                    (2U)
/*! SP7 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRJ_SP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_SP7_SHIFT)) & AIPS_OPACRJ_SP7_MASK)

#define AIPS_OPACRJ_TP6_MASK                     (0x10U)
#define AIPS_OPACRJ_TP6_SHIFT                    (4U)
/*! TP6 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRJ_TP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_TP6_SHIFT)) & AIPS_OPACRJ_TP6_MASK)

#define AIPS_OPACRJ_WP6_MASK                     (0x20U)
#define AIPS_OPACRJ_WP6_SHIFT                    (5U)
/*! WP6 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRJ_WP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_WP6_SHIFT)) & AIPS_OPACRJ_WP6_MASK)

#define AIPS_OPACRJ_SP6_MASK                     (0x40U)
#define AIPS_OPACRJ_SP6_SHIFT                    (6U)
/*! SP6 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRJ_SP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_SP6_SHIFT)) & AIPS_OPACRJ_SP6_MASK)

#define AIPS_OPACRJ_TP4_MASK                     (0x1000U)
#define AIPS_OPACRJ_TP4_SHIFT                    (12U)
/*! TP4 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRJ_TP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_TP4_SHIFT)) & AIPS_OPACRJ_TP4_MASK)

#define AIPS_OPACRJ_WP4_MASK                     (0x2000U)
#define AIPS_OPACRJ_WP4_SHIFT                    (13U)
/*! WP4 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRJ_WP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_WP4_SHIFT)) & AIPS_OPACRJ_WP4_MASK)

#define AIPS_OPACRJ_SP4_MASK                     (0x4000U)
#define AIPS_OPACRJ_SP4_SHIFT                    (14U)
/*! SP4 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRJ_SP4(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_SP4_SHIFT)) & AIPS_OPACRJ_SP4_MASK)

#define AIPS_OPACRJ_TP3_MASK                     (0x10000U)
#define AIPS_OPACRJ_TP3_SHIFT                    (16U)
/*! TP3 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRJ_TP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_TP3_SHIFT)) & AIPS_OPACRJ_TP3_MASK)

#define AIPS_OPACRJ_WP3_MASK                     (0x20000U)
#define AIPS_OPACRJ_WP3_SHIFT                    (17U)
/*! WP3 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRJ_WP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_WP3_SHIFT)) & AIPS_OPACRJ_WP3_MASK)

#define AIPS_OPACRJ_SP3_MASK                     (0x40000U)
#define AIPS_OPACRJ_SP3_SHIFT                    (18U)
/*! SP3 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRJ_SP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_SP3_SHIFT)) & AIPS_OPACRJ_SP3_MASK)

#define AIPS_OPACRJ_TP2_MASK                     (0x100000U)
#define AIPS_OPACRJ_TP2_SHIFT                    (20U)
/*! TP2 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRJ_TP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_TP2_SHIFT)) & AIPS_OPACRJ_TP2_MASK)

#define AIPS_OPACRJ_WP2_MASK                     (0x200000U)
#define AIPS_OPACRJ_WP2_SHIFT                    (21U)
/*! WP2 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRJ_WP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_WP2_SHIFT)) & AIPS_OPACRJ_WP2_MASK)

#define AIPS_OPACRJ_SP2_MASK                     (0x400000U)
#define AIPS_OPACRJ_SP2_SHIFT                    (22U)
/*! SP2 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRJ_SP2(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRJ_SP2_SHIFT)) & AIPS_OPACRJ_SP2_MASK)
/*! @} */

/*! @name OPACRK - Off-Platform Peripheral Access Control Register */
/*! @{ */

#define AIPS_OPACRK_TP6_MASK                     (0x10U)
#define AIPS_OPACRK_TP6_SHIFT                    (4U)
/*! TP6 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRK_TP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRK_TP6_SHIFT)) & AIPS_OPACRK_TP6_MASK)

#define AIPS_OPACRK_WP6_MASK                     (0x20U)
#define AIPS_OPACRK_WP6_SHIFT                    (5U)
/*! WP6 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRK_WP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRK_WP6_SHIFT)) & AIPS_OPACRK_WP6_MASK)

#define AIPS_OPACRK_SP6_MASK                     (0x40U)
#define AIPS_OPACRK_SP6_SHIFT                    (6U)
/*! SP6 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRK_SP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRK_SP6_SHIFT)) & AIPS_OPACRK_SP6_MASK)

#define AIPS_OPACRK_TP3_MASK                     (0x10000U)
#define AIPS_OPACRK_TP3_SHIFT                    (16U)
/*! TP3 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRK_TP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRK_TP3_SHIFT)) & AIPS_OPACRK_TP3_MASK)

#define AIPS_OPACRK_WP3_MASK                     (0x20000U)
#define AIPS_OPACRK_WP3_SHIFT                    (17U)
/*! WP3 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRK_WP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRK_WP3_SHIFT)) & AIPS_OPACRK_WP3_MASK)

#define AIPS_OPACRK_SP3_MASK                     (0x40000U)
#define AIPS_OPACRK_SP3_SHIFT                    (18U)
/*! SP3 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRK_SP3(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRK_SP3_SHIFT)) & AIPS_OPACRK_SP3_MASK)

#define AIPS_OPACRK_TP1_MASK                     (0x1000000U)
#define AIPS_OPACRK_TP1_SHIFT                    (24U)
/*! TP1 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRK_TP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRK_TP1_SHIFT)) & AIPS_OPACRK_TP1_MASK)

#define AIPS_OPACRK_WP1_MASK                     (0x2000000U)
#define AIPS_OPACRK_WP1_SHIFT                    (25U)
/*! WP1 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRK_WP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRK_WP1_SHIFT)) & AIPS_OPACRK_WP1_MASK)

#define AIPS_OPACRK_SP1_MASK                     (0x4000000U)
#define AIPS_OPACRK_SP1_SHIFT                    (26U)
/*! SP1 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRK_SP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRK_SP1_SHIFT)) & AIPS_OPACRK_SP1_MASK)

#define AIPS_OPACRK_TP0_MASK                     (0x10000000U)
#define AIPS_OPACRK_TP0_SHIFT                    (28U)
/*! TP0 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRK_TP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRK_TP0_SHIFT)) & AIPS_OPACRK_TP0_MASK)

#define AIPS_OPACRK_WP0_MASK                     (0x20000000U)
#define AIPS_OPACRK_WP0_SHIFT                    (29U)
/*! WP0 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRK_WP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRK_WP0_SHIFT)) & AIPS_OPACRK_WP0_MASK)

#define AIPS_OPACRK_SP0_MASK                     (0x40000000U)
#define AIPS_OPACRK_SP0_SHIFT                    (30U)
/*! SP0 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRK_SP0(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRK_SP0_SHIFT)) & AIPS_OPACRK_SP0_MASK)
/*! @} */

/*! @name OPACRL - Off-Platform Peripheral Access Control Register */
/*! @{ */

#define AIPS_OPACRL_TP7_MASK                     (0x1U)
#define AIPS_OPACRL_TP7_SHIFT                    (0U)
/*! TP7 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRL_TP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRL_TP7_SHIFT)) & AIPS_OPACRL_TP7_MASK)

#define AIPS_OPACRL_WP7_MASK                     (0x2U)
#define AIPS_OPACRL_WP7_SHIFT                    (1U)
/*! WP7 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRL_WP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRL_WP7_SHIFT)) & AIPS_OPACRL_WP7_MASK)

#define AIPS_OPACRL_SP7_MASK                     (0x4U)
#define AIPS_OPACRL_SP7_SHIFT                    (2U)
/*! SP7 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRL_SP7(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRL_SP7_SHIFT)) & AIPS_OPACRL_SP7_MASK)

#define AIPS_OPACRL_TP6_MASK                     (0x10U)
#define AIPS_OPACRL_TP6_SHIFT                    (4U)
/*! TP6 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRL_TP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRL_TP6_SHIFT)) & AIPS_OPACRL_TP6_MASK)

#define AIPS_OPACRL_WP6_MASK                     (0x20U)
#define AIPS_OPACRL_WP6_SHIFT                    (5U)
/*! WP6 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRL_WP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRL_WP6_SHIFT)) & AIPS_OPACRL_WP6_MASK)

#define AIPS_OPACRL_SP6_MASK                     (0x40U)
#define AIPS_OPACRL_SP6_SHIFT                    (6U)
/*! SP6 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRL_SP6(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRL_SP6_SHIFT)) & AIPS_OPACRL_SP6_MASK)

#define AIPS_OPACRL_TP5_MASK                     (0x100U)
#define AIPS_OPACRL_TP5_SHIFT                    (8U)
/*! TP5 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRL_TP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRL_TP5_SHIFT)) & AIPS_OPACRL_TP5_MASK)

#define AIPS_OPACRL_WP5_MASK                     (0x200U)
#define AIPS_OPACRL_WP5_SHIFT                    (9U)
/*! WP5 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRL_WP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRL_WP5_SHIFT)) & AIPS_OPACRL_WP5_MASK)

#define AIPS_OPACRL_SP5_MASK                     (0x400U)
#define AIPS_OPACRL_SP5_SHIFT                    (10U)
/*! SP5 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRL_SP5(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRL_SP5_SHIFT)) & AIPS_OPACRL_SP5_MASK)

#define AIPS_OPACRL_TP1_MASK                     (0x1000000U)
#define AIPS_OPACRL_TP1_SHIFT                    (24U)
/*! TP1 - Trusted Protect
 *  0b0..Accesses from an untrusted master are allowed.
 *  0b1..Accesses from an untrusted master are not allowed.
 */
#define AIPS_OPACRL_TP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRL_TP1_SHIFT)) & AIPS_OPACRL_TP1_MASK)

#define AIPS_OPACRL_WP1_MASK                     (0x2000000U)
#define AIPS_OPACRL_WP1_SHIFT                    (25U)
/*! WP1 - Write Protect
 *  0b0..This peripheral allows write accesses.
 *  0b1..This peripheral is write protected.
 */
#define AIPS_OPACRL_WP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRL_WP1_SHIFT)) & AIPS_OPACRL_WP1_MASK)

#define AIPS_OPACRL_SP1_MASK                     (0x4000000U)
#define AIPS_OPACRL_SP1_SHIFT                    (26U)
/*! SP1 - Supervisor Protect
 *  0b0..This peripheral does not require supervisor privilege level for accesses.
 *  0b1..This peripheral requires supervisor privilege level for accesses.
 */
#define AIPS_OPACRL_SP1(x)                       (((uint32_t)(((uint32_t)(x)) << AIPS_OPACRL_SP1_SHIFT)) & AIPS_OPACRL_SP1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AIPS_Register_Masks */


/*!
 * @}
 */ /* end of group AIPS_Peripheral_Access_Layer */


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


#endif  /* PERI_AIPS_H_ */

