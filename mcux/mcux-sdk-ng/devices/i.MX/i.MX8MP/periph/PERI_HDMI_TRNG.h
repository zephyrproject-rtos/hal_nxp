/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for HDMI_TRNG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_HDMI_TRNG.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for HDMI_TRNG
 *
 * CMSIS Peripheral Access Layer for HDMI_TRNG
 */

#if !defined(PERI_HDMI_TRNG_H_)
#define PERI_HDMI_TRNG_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- HDMI_TRNG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HDMI_TRNG_Peripheral_Access_Layer HDMI_TRNG Peripheral Access Layer
 * @{
 */

/** HDMI_TRNG - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< This register causes the DWC_trng to execute one of a number of actions., offset: 0x0 */
  __I  uint32_t STAT;                              /**< The NONCE_MODE field indicates that the engine is currently waiting for the host to load a nonce through the SEEDx registers., offset: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SMODE;                             /**< This register is used to enable or disable certain mission-mode run-time features within the core., offset: 0xC */
  __IO uint32_t IE;                                /**< This register is used to enable or disable interrupts within the DWC_trng., offset: 0x10 */
  __IO uint32_t ISTAT;                             /**< This register allows the user to monitor the interrupt and/or status contributions of the DWC_trng., offset: 0x14 */
  __I  uint32_t COREKIT_REL;                       /**< Contains the coreKit release information., offset: 0x18 */
  __I  uint32_t FEATURES;                          /**< Contains the build-time parameter enumerations., offset: 0x1C */
  __I  uint32_t RAND0;                             /**< The RAND0 register is part of the RANDx register set which are used by the host to read the newly generated random number., offset: 0x20 */
  __I  uint32_t RAND1;                             /**< The RAND1 register is part of the RANDx register set which are used by the host to read the newly generated random number., offset: 0x24 */
  __I  uint32_t RAND2;                             /**< The RAND2 register is part of the RANDx register set which are used by the host to read the newly generated random number., offset: 0x28 */
  __I  uint32_t RAND3;                             /**< The RAND3 register is part of the RANDx register set which are used by the host to read the newly generated random number., offset: 0x2C */
  __I  uint32_t RAND4;                             /**< The RAND4 register is part of the RANDx register set which are used by the host to read the newly generated random number., offset: 0x30 */
  __I  uint32_t RAND5;                             /**< The RAND5 register is part of the RANDx register set which are used by the host to read the newly generated random number., offset: 0x34 */
  __I  uint32_t RAND6;                             /**< The RAND6 register is part of the RANDx register set which are used by the host to read the newly generated random number., offset: 0x38 */
  __I  uint32_t RAND7;                             /**< The RAND7 register is part of the RANDx register set which are used by the host to read the newly generated random number., offset: 0x3C */
  __I  uint32_t SEED0;                             /**< The SEED0 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng., offset: 0x40 */
  __I  uint32_t SEED1;                             /**< The SEED1 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng., offset: 0x44 */
  __I  uint32_t SEED2;                             /**< The SEED2 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng., offset: 0x48 */
  __I  uint32_t SEED3;                             /**< The SEED3 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng., offset: 0x4C */
  __I  uint32_t SEED4;                             /**< The SEED4 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng., offset: 0x50 */
  __I  uint32_t SEED5;                             /**< The SEED5 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng., offset: 0x54 */
  __I  uint32_t SEED6;                             /**< The SEED6 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng., offset: 0x58 */
  __I  uint32_t SEED7;                             /**< The SEED7 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng., offset: 0x5C */
  __IO uint32_t AUTO_RQSTS;                        /**< This register allows the DWC_trng to generate a reseed reminder alarm after a specified number of random numbers have been requested by the host., offset: 0x60 */
  __IO uint32_t AUTO_AGE;                          /**< This register allows the DWC_trng to generate a reseed reminder alarm after a specified number of random numbers have been requested by the host., offset: 0x64 */
  __I  uint32_t BUILD_CONFIG;                      /**< Contains the build-time parameter enumerations., offset: 0x68 */
} HDMI_TRNG_Type;

/* ----------------------------------------------------------------------------
   -- HDMI_TRNG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HDMI_TRNG_Register_Masks HDMI_TRNG Register Masks
 * @{
 */

/*! @name CTRL - This register causes the DWC_trng to execute one of a number of actions. */
/*! @{ */

#define HDMI_TRNG_CTRL_CMD_MASK                  (0x7U)
#define HDMI_TRNG_CTRL_CMD_SHIFT                 (0U)
/*! CMD - Execute a command.
 *  0b000..Execute a NOP
 *  0b001..Generate a random number
 *  0b010..Execute a random reseed
 *  0b011..Execute a nonce reseed
 */
#define HDMI_TRNG_CTRL_CMD(x)                    (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_CTRL_CMD_SHIFT)) & HDMI_TRNG_CTRL_CMD_MASK)
/*! @} */

/*! @name STAT - The NONCE_MODE field indicates that the engine is currently waiting for the host to load a nonce through the SEEDx registers. */
/*! @{ */

#define HDMI_TRNG_STAT_NONCE_MODE_MASK           (0x4U)
#define HDMI_TRNG_STAT_NONCE_MODE_SHIFT          (2U)
/*! NONCE_MODE - Current state of NONCE mode.
 *  0b0..Nonce mode disabled
 *  0b1..Nonce mode enabled
 */
#define HDMI_TRNG_STAT_NONCE_MODE(x)             (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_STAT_NONCE_MODE_SHIFT)) & HDMI_TRNG_STAT_NONCE_MODE_MASK)

#define HDMI_TRNG_STAT_R256_MASK                 (0x8U)
#define HDMI_TRNG_STAT_R256_SHIFT                (3U)
/*! R256 - Reflects state of MODE. */
#define HDMI_TRNG_STAT_R256(x)                   (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_STAT_R256_SHIFT)) & HDMI_TRNG_STAT_R256_MASK)

#define HDMI_TRNG_STAT_MISSION_MODE_MASK         (0x100U)
#define HDMI_TRNG_STAT_MISSION_MODE_SHIFT        (8U)
/*! MISSION_MODE - Reflects state of SMODE. */
#define HDMI_TRNG_STAT_MISSION_MODE(x)           (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_STAT_MISSION_MODE_SHIFT)) & HDMI_TRNG_STAT_MISSION_MODE_MASK)

#define HDMI_TRNG_STAT_SEEDED_MASK               (0x200U)
#define HDMI_TRNG_STAT_SEEDED_SHIFT              (9U)
/*! SEEDED - Current SEEDED state.
 *  0b0..PRNG core is not seeded
 *  0b1..PRNG core is seeded
 */
#define HDMI_TRNG_STAT_SEEDED(x)                 (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_STAT_SEEDED_SHIFT)) & HDMI_TRNG_STAT_SEEDED_MASK)

#define HDMI_TRNG_STAT_LAST_RESEED_MASK          (0x70000U)
#define HDMI_TRNG_STAT_LAST_RESEED_SHIFT         (16U)
/*! LAST_RESEED - Action which loaded current seed.
 *  0b000..Reseeded by host random reseed command
 *  0b011..Reseeded by nonce
 *  0b100..Reseeded by <b>I_reseed</b> driven to 1 or internal auto-reseed
 *  0b111..Unseeded (zeroized state)
 */
#define HDMI_TRNG_STAT_LAST_RESEED(x)            (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_STAT_LAST_RESEED_SHIFT)) & HDMI_TRNG_STAT_LAST_RESEED_MASK)

#define HDMI_TRNG_STAT_SRVC_RQST_MASK            (0x8000000U)
#define HDMI_TRNG_STAT_SRVC_RQST_SHIFT           (27U)
/*! SRVC_RQST - Current state of unacknowledged request indicator.
 *  0b0..No unacknowledged service request
 *  0b1..Unacknowledged service request
 */
#define HDMI_TRNG_STAT_SRVC_RQST(x)              (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_STAT_SRVC_RQST_SHIFT)) & HDMI_TRNG_STAT_SRVC_RQST_MASK)

#define HDMI_TRNG_STAT_RAND_GENERATING_MASK      (0x40000000U)
#define HDMI_TRNG_STAT_RAND_GENERATING_SHIFT     (30U)
/*! RAND_GENERATING - Current state of random number generation operations.
 *  0b0..No random number generation process in progress
 *  0b1..Random number generation process in progress
 */
#define HDMI_TRNG_STAT_RAND_GENERATING(x)        (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_STAT_RAND_GENERATING_SHIFT)) & HDMI_TRNG_STAT_RAND_GENERATING_MASK)

#define HDMI_TRNG_STAT_RAND_RESEEDING_MASK       (0x80000000U)
#define HDMI_TRNG_STAT_RAND_RESEEDING_SHIFT      (31U)
/*! RAND_RESEEDING - Current state of random seed generation operations.
 *  0b0..No random reseed generation process in progress
 *  0b1..Random reseed generation process in progress
 */
#define HDMI_TRNG_STAT_RAND_RESEEDING(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_STAT_RAND_RESEEDING_SHIFT)) & HDMI_TRNG_STAT_RAND_RESEEDING_MASK)
/*! @} */

/*! @name SMODE - This register is used to enable or disable certain mission-mode run-time features within the core. */
/*! @{ */

#define HDMI_TRNG_SMODE_NONCE_MODE_MASK          (0x4U)
#define HDMI_TRNG_SMODE_NONCE_MODE_SHIFT         (2U)
/*! NONCE_MODE - Sets the reseed mode to nonce or random.
 *  0b0..Disable nonce mode
 *  0b1..Enable nonce mode
 */
#define HDMI_TRNG_SMODE_NONCE_MODE(x)            (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_SMODE_NONCE_MODE_SHIFT)) & HDMI_TRNG_SMODE_NONCE_MODE_MASK)

#define HDMI_TRNG_SMODE_MISSION_MODE_MASK        (0x100U)
#define HDMI_TRNG_SMODE_MISSION_MODE_SHIFT       (8U)
/*! MISSION_MODE - Sets the operating mode to TEST or MISSION.
 *  0b0..Test mode (access to internal state and test fields)
 *  0b1..Mission mode (no access to internal state)
 */
#define HDMI_TRNG_SMODE_MISSION_MODE(x)          (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_SMODE_MISSION_MODE_SHIFT)) & HDMI_TRNG_SMODE_MISSION_MODE_MASK)

#define HDMI_TRNG_SMODE_MAX_REJECTS_MASK         (0xFF0000U)
#define HDMI_TRNG_SMODE_MAX_REJECTS_SHIFT        (16U)
/*! MAX_REJECTS - Maximum number of consecutive bit rejections before issuing ring tweak. */
#define HDMI_TRNG_SMODE_MAX_REJECTS(x)           (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_SMODE_MAX_REJECTS_SHIFT)) & HDMI_TRNG_SMODE_MAX_REJECTS_MASK)
/*! @} */

/*! @name IE - This register is used to enable or disable interrupts within the DWC_trng. */
/*! @{ */

#define HDMI_TRNG_IE_RAND_RDY_EN_MASK            (0x1U)
#define HDMI_TRNG_IE_RAND_RDY_EN_SHIFT           (0U)
/*! RAND_RDY_EN - Include or exclude RAND_RDY interrupt contribution.
 *  0b0..Disable <b>RAND_RDY</b> interrupt contribution
 *  0b1..Enable <b>RAND_RDY</b> interrupt contribution
 */
#define HDMI_TRNG_IE_RAND_RDY_EN(x)              (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_IE_RAND_RDY_EN_SHIFT)) & HDMI_TRNG_IE_RAND_RDY_EN_MASK)

#define HDMI_TRNG_IE_SEED_DONE_EN_MASK           (0x2U)
#define HDMI_TRNG_IE_SEED_DONE_EN_SHIFT          (1U)
/*! SEED_DONE_EN - Include or exclude SEED_DONE interrupt contribution.
 *  0b0..Disable <b>SEED_DONE</b> interrupt contribution
 *  0b1..Enable <b>SEED_DONE</b> interrupt contribution
 */
#define HDMI_TRNG_IE_SEED_DONE_EN(x)             (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_IE_SEED_DONE_EN_SHIFT)) & HDMI_TRNG_IE_SEED_DONE_EN_MASK)

#define HDMI_TRNG_IE_AGE_ALARM_EN_MASK           (0x4U)
#define HDMI_TRNG_IE_AGE_ALARM_EN_SHIFT          (2U)
/*! AGE_ALARM_EN - Include or exclude AGE_ALARM interrupt contribution.
 *  0b0..Disable <b>AGE_ALARM</b> interrupt contribution
 *  0b1..Enable <b>AGE_ALARM</b> interrupt contribution
 */
#define HDMI_TRNG_IE_AGE_ALARM_EN(x)             (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_IE_AGE_ALARM_EN_SHIFT)) & HDMI_TRNG_IE_AGE_ALARM_EN_MASK)

#define HDMI_TRNG_IE_RQST_ALARM_EN_MASK          (0x8U)
#define HDMI_TRNG_IE_RQST_ALARM_EN_SHIFT         (3U)
/*! RQST_ALARM_EN - Include or exclude RQST_ALARM interrupt contribution.
 *  0b0..Disable <b>RQST_ALARM</b> interrupt contribution
 *  0b1..Enable <b>RQST_ALARM</b> interrupt contribution
 */
#define HDMI_TRNG_IE_RQST_ALARM_EN(x)            (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_IE_RQST_ALARM_EN_SHIFT)) & HDMI_TRNG_IE_RQST_ALARM_EN_MASK)

#define HDMI_TRNG_IE_LFSR_LOCKUP_EN_MASK         (0x10U)
#define HDMI_TRNG_IE_LFSR_LOCKUP_EN_SHIFT        (4U)
/*! LFSR_LOCKUP_EN - Include or exclude LFSR_LOCKUP interrupt contribution.
 *  0b0..Disable <b>LFSR_LOCKUP</b> interrupt contribution
 *  0b1..Enable <b>LFSR_LOCKUP</b> interrupt contribution
 */
#define HDMI_TRNG_IE_LFSR_LOCKUP_EN(x)           (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_IE_LFSR_LOCKUP_EN_SHIFT)) & HDMI_TRNG_IE_LFSR_LOCKUP_EN_MASK)

#define HDMI_TRNG_IE_GLBL_EN_MASK                (0x80000000U)
#define HDMI_TRNG_IE_GLBL_EN_SHIFT               (31U)
/*! GLBL_EN - Global interrupt enable.
 *  0b0..Globally disable interrupts
 *  0b1..Globally enable interrupts
 */
#define HDMI_TRNG_IE_GLBL_EN(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_IE_GLBL_EN_SHIFT)) & HDMI_TRNG_IE_GLBL_EN_MASK)
/*! @} */

/*! @name ISTAT - This register allows the user to monitor the interrupt and/or status contributions of the DWC_trng. */
/*! @{ */

#define HDMI_TRNG_ISTAT_RAND_RDY_MASK            (0x1U)
#define HDMI_TRNG_ISTAT_RAND_RDY_SHIFT           (0U)
/*! RAND_RDY - Status and acknowledgment (clearing) of RAND_RDY indicator.
 *  0b0..NOP
 *  0b0..No unacknowledged RAND_RDY indicator
 *  0b1..Acknowledge RAND_RDY indicator
 *  0b1..Unacknowledged RAND_RDY indicator
 */
#define HDMI_TRNG_ISTAT_RAND_RDY(x)              (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_ISTAT_RAND_RDY_SHIFT)) & HDMI_TRNG_ISTAT_RAND_RDY_MASK)

#define HDMI_TRNG_ISTAT_SEED_DONE_MASK           (0x2U)
#define HDMI_TRNG_ISTAT_SEED_DONE_SHIFT          (1U)
/*! SEED_DONE - Status and acknowledgment (clearing) of SEED_DONE indicator.
 *  0b0..NOP
 *  0b0..No unacknowledged SEED_DONE indicator
 *  0b1..Acknowledge SEED_DONE indicator
 *  0b1..Unacknowledged SEED_DONE indicator
 */
#define HDMI_TRNG_ISTAT_SEED_DONE(x)             (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_ISTAT_SEED_DONE_SHIFT)) & HDMI_TRNG_ISTAT_SEED_DONE_MASK)

#define HDMI_TRNG_ISTAT_AGE_ALARM_MASK           (0x4U)
#define HDMI_TRNG_ISTAT_AGE_ALARM_SHIFT          (2U)
/*! AGE_ALARM - Status and acknowledgment (clearing) of AGE_ALARM indicator.
 *  0b0..NOP
 *  0b0..No unacknowledged AGE_ALARM indicator
 *  0b1..Acknowledge AGE_ALARM indicator
 *  0b1..Unacknowledged AGE_ALARM indicator
 */
#define HDMI_TRNG_ISTAT_AGE_ALARM(x)             (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_ISTAT_AGE_ALARM_SHIFT)) & HDMI_TRNG_ISTAT_AGE_ALARM_MASK)

#define HDMI_TRNG_ISTAT_RQST_ALARM_MASK          (0x8U)
#define HDMI_TRNG_ISTAT_RQST_ALARM_SHIFT         (3U)
/*! RQST_ALARM - Status and acknowledgment (clearing) of RQST_ALARM indicator.
 *  0b0..NOP
 *  0b0..No unacknowledged RQST_ALARM indicator
 *  0b1..Acknowledge RQST_ALARM indicator
 *  0b1..Unacknowledged RQST_ALARM indicator
 */
#define HDMI_TRNG_ISTAT_RQST_ALARM(x)            (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_ISTAT_RQST_ALARM_SHIFT)) & HDMI_TRNG_ISTAT_RQST_ALARM_MASK)

#define HDMI_TRNG_ISTAT_LFSR_LOCKUP_MASK         (0x10U)
#define HDMI_TRNG_ISTAT_LFSR_LOCKUP_SHIFT        (4U)
/*! LFSR_LOCKUP - Status and acknowledgment (clearing) of LFSR_LOCKUP indicator.
 *  0b0..NOP
 *  0b0..No unacknowledged LFSR_LOCKUP indicator
 *  0b1..Acknowledge LFSR_LOCKUP indicator
 *  0b1..Unacknowledged LFSR_LOCKUP indicator
 */
#define HDMI_TRNG_ISTAT_LFSR_LOCKUP(x)           (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_ISTAT_LFSR_LOCKUP_SHIFT)) & HDMI_TRNG_ISTAT_LFSR_LOCKUP_MASK)
/*! @} */

/*! @name COREKIT_REL - Contains the coreKit release information. */
/*! @{ */

#define HDMI_TRNG_COREKIT_REL_REL_NUM_MASK       (0xFFFFU)
#define HDMI_TRNG_COREKIT_REL_REL_NUM_SHIFT      (0U)
/*! REL_NUM - Indicates the coreKit release version in pseudo-BCD. */
#define HDMI_TRNG_COREKIT_REL_REL_NUM(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_COREKIT_REL_REL_NUM_SHIFT)) & HDMI_TRNG_COREKIT_REL_REL_NUM_MASK)

#define HDMI_TRNG_COREKIT_REL_EXT_VER_MASK       (0xFF0000U)
#define HDMI_TRNG_COREKIT_REL_EXT_VER_SHIFT      (16U)
/*! EXT_VER - Indicates the coreKit release extension version number. */
#define HDMI_TRNG_COREKIT_REL_EXT_VER(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_COREKIT_REL_EXT_VER_SHIFT)) & HDMI_TRNG_COREKIT_REL_EXT_VER_MASK)

#define HDMI_TRNG_COREKIT_REL_EXT_ENUM_MASK      (0xF0000000U)
#define HDMI_TRNG_COREKIT_REL_EXT_ENUM_SHIFT     (28U)
/*! EXT_ENUM - Indicates the coreKit release extension type.
 *  0b0000..GA release
 *  0b0001..LCA release
 *  0b0010..EA release
 *  0b0011..LP release
 *  0b0100..LPC release
 *  0b0101..SOW release
 */
#define HDMI_TRNG_COREKIT_REL_EXT_ENUM(x)        (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_COREKIT_REL_EXT_ENUM_SHIFT)) & HDMI_TRNG_COREKIT_REL_EXT_ENUM_MASK)
/*! @} */

/*! @name FEATURES - Contains the build-time parameter enumerations. */
/*! @{ */

#define HDMI_TRNG_FEATURES_MAX_RAND_LENGTH_MASK  (0x3U)
#define HDMI_TRNG_FEATURES_MAX_RAND_LENGTH_SHIFT (0U)
/*! MAX_RAND_LENGTH - Maximum length of the PRNG RANDx register set.
 *  0b00..PRNG set up for 128-bit maximum
 *  0b01..PRNG set up for 256-bit maximum
 */
#define HDMI_TRNG_FEATURES_MAX_RAND_LENGTH(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_FEATURES_MAX_RAND_LENGTH_SHIFT)) & HDMI_TRNG_FEATURES_MAX_RAND_LENGTH_MASK)

#define HDMI_TRNG_FEATURES_RAND_SEED_AVAIL_MASK  (0x4U)
#define HDMI_TRNG_FEATURES_RAND_SEED_AVAIL_SHIFT (2U)
/*! RAND_SEED_AVAIL - Indicates the ring-oscillator sub-section is present.
 *  0b0..No ring-oscillator seed generator present
 *  0b1..Ring-oscillator seed generator present
 */
#define HDMI_TRNG_FEATURES_RAND_SEED_AVAIL(x)    (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_FEATURES_RAND_SEED_AVAIL_SHIFT)) & HDMI_TRNG_FEATURES_RAND_SEED_AVAIL_MASK)

#define HDMI_TRNG_FEATURES_MISSION_MODE_RESET_STATE_MASK (0x8U)
#define HDMI_TRNG_FEATURES_MISSION_MODE_RESET_STATE_SHIFT (3U)
/*! MISSION_MODE_RESET_STATE - Indicates state of SMODE.
 *  0b0..Resets to TEST_MODE
 *  0b1..Resets to MISSION_MODE
 */
#define HDMI_TRNG_FEATURES_MISSION_MODE_RESET_STATE(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_FEATURES_MISSION_MODE_RESET_STATE_SHIFT)) & HDMI_TRNG_FEATURES_MISSION_MODE_RESET_STATE_MASK)

#define HDMI_TRNG_FEATURES_DIAG_LEVEL_MASK       (0x70U)
#define HDMI_TRNG_FEATURES_DIAG_LEVEL_SHIFT      (4U)
/*! DIAG_LEVEL - Level of diagnostic support provided. */
#define HDMI_TRNG_FEATURES_DIAG_LEVEL(x)         (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_FEATURES_DIAG_LEVEL_SHIFT)) & HDMI_TRNG_FEATURES_DIAG_LEVEL_MASK)
/*! @} */

/*! @name RAND0 - The RAND0 register is part of the RANDx register set which are used by the host to read the newly generated random number. */
/*! @{ */

#define HDMI_TRNG_RAND0_RAND_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_RAND0_RAND_SHIFT               (0U)
/*! RAND - Random data word 0. */
#define HDMI_TRNG_RAND0_RAND(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_RAND0_RAND_SHIFT)) & HDMI_TRNG_RAND0_RAND_MASK)
/*! @} */

/*! @name RAND1 - The RAND1 register is part of the RANDx register set which are used by the host to read the newly generated random number. */
/*! @{ */

#define HDMI_TRNG_RAND1_RAND_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_RAND1_RAND_SHIFT               (0U)
/*! RAND - Random data word 1. */
#define HDMI_TRNG_RAND1_RAND(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_RAND1_RAND_SHIFT)) & HDMI_TRNG_RAND1_RAND_MASK)
/*! @} */

/*! @name RAND2 - The RAND2 register is part of the RANDx register set which are used by the host to read the newly generated random number. */
/*! @{ */

#define HDMI_TRNG_RAND2_RAND_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_RAND2_RAND_SHIFT               (0U)
/*! RAND - Random data word 2. */
#define HDMI_TRNG_RAND2_RAND(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_RAND2_RAND_SHIFT)) & HDMI_TRNG_RAND2_RAND_MASK)
/*! @} */

/*! @name RAND3 - The RAND3 register is part of the RANDx register set which are used by the host to read the newly generated random number. */
/*! @{ */

#define HDMI_TRNG_RAND3_RAND_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_RAND3_RAND_SHIFT               (0U)
/*! RAND - Random data word 3. */
#define HDMI_TRNG_RAND3_RAND(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_RAND3_RAND_SHIFT)) & HDMI_TRNG_RAND3_RAND_MASK)
/*! @} */

/*! @name RAND4 - The RAND4 register is part of the RANDx register set which are used by the host to read the newly generated random number. */
/*! @{ */

#define HDMI_TRNG_RAND4_RAND_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_RAND4_RAND_SHIFT               (0U)
/*! RAND - Random data word 4. */
#define HDMI_TRNG_RAND4_RAND(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_RAND4_RAND_SHIFT)) & HDMI_TRNG_RAND4_RAND_MASK)
/*! @} */

/*! @name RAND5 - The RAND5 register is part of the RANDx register set which are used by the host to read the newly generated random number. */
/*! @{ */

#define HDMI_TRNG_RAND5_RAND_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_RAND5_RAND_SHIFT               (0U)
/*! RAND - Random data word 5. */
#define HDMI_TRNG_RAND5_RAND(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_RAND5_RAND_SHIFT)) & HDMI_TRNG_RAND5_RAND_MASK)
/*! @} */

/*! @name RAND6 - The RAND6 register is part of the RANDx register set which are used by the host to read the newly generated random number. */
/*! @{ */

#define HDMI_TRNG_RAND6_RAND_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_RAND6_RAND_SHIFT               (0U)
/*! RAND - Random data word 6. */
#define HDMI_TRNG_RAND6_RAND(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_RAND6_RAND_SHIFT)) & HDMI_TRNG_RAND6_RAND_MASK)
/*! @} */

/*! @name RAND7 - The RAND7 register is part of the RANDx register set which are used by the host to read the newly generated random number. */
/*! @{ */

#define HDMI_TRNG_RAND7_RAND_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_RAND7_RAND_SHIFT               (0U)
/*! RAND - Random data word 7. */
#define HDMI_TRNG_RAND7_RAND(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_RAND7_RAND_SHIFT)) & HDMI_TRNG_RAND7_RAND_MASK)
/*! @} */

/*! @name SEED0 - The SEED0 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng. */
/*! @{ */

#define HDMI_TRNG_SEED0_SEED_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_SEED0_SEED_SHIFT               (0U)
/*! SEED - Seed data word 0. */
#define HDMI_TRNG_SEED0_SEED(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_SEED0_SEED_SHIFT)) & HDMI_TRNG_SEED0_SEED_MASK)
/*! @} */

/*! @name SEED1 - The SEED1 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng. */
/*! @{ */

#define HDMI_TRNG_SEED1_SEED_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_SEED1_SEED_SHIFT               (0U)
/*! SEED - Seed data word 1. */
#define HDMI_TRNG_SEED1_SEED(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_SEED1_SEED_SHIFT)) & HDMI_TRNG_SEED1_SEED_MASK)
/*! @} */

/*! @name SEED2 - The SEED2 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng. */
/*! @{ */

#define HDMI_TRNG_SEED2_SEED_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_SEED2_SEED_SHIFT               (0U)
/*! SEED - Seed data word 2. */
#define HDMI_TRNG_SEED2_SEED(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_SEED2_SEED_SHIFT)) & HDMI_TRNG_SEED2_SEED_MASK)
/*! @} */

/*! @name SEED3 - The SEED3 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng. */
/*! @{ */

#define HDMI_TRNG_SEED3_SEED_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_SEED3_SEED_SHIFT               (0U)
/*! SEED - Seed data word 3. */
#define HDMI_TRNG_SEED3_SEED(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_SEED3_SEED_SHIFT)) & HDMI_TRNG_SEED3_SEED_MASK)
/*! @} */

/*! @name SEED4 - The SEED4 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng. */
/*! @{ */

#define HDMI_TRNG_SEED4_SEED_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_SEED4_SEED_SHIFT               (0U)
/*! SEED - Seed data word 4. */
#define HDMI_TRNG_SEED4_SEED(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_SEED4_SEED_SHIFT)) & HDMI_TRNG_SEED4_SEED_MASK)
/*! @} */

/*! @name SEED5 - The SEED5 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng. */
/*! @{ */

#define HDMI_TRNG_SEED5_SEED_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_SEED5_SEED_SHIFT               (0U)
/*! SEED - Seed data word 5. */
#define HDMI_TRNG_SEED5_SEED(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_SEED5_SEED_SHIFT)) & HDMI_TRNG_SEED5_SEED_MASK)
/*! @} */

/*! @name SEED6 - The SEED6 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng. */
/*! @{ */

#define HDMI_TRNG_SEED6_SEED_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_SEED6_SEED_SHIFT               (0U)
/*! SEED - Seed data word 6. */
#define HDMI_TRNG_SEED6_SEED(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_SEED6_SEED_SHIFT)) & HDMI_TRNG_SEED6_SEED_MASK)
/*! @} */

/*! @name SEED7 - The SEED7 register is part of the SEEDx register set which are used to load a host generated nonce seed into the DWC_trng. */
/*! @{ */

#define HDMI_TRNG_SEED7_SEED_MASK                (0xFFFFFFFFU)
#define HDMI_TRNG_SEED7_SEED_SHIFT               (0U)
/*! SEED - Seed data word 7. */
#define HDMI_TRNG_SEED7_SEED(x)                  (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_SEED7_SEED_SHIFT)) & HDMI_TRNG_SEED7_SEED_MASK)
/*! @} */

/*! @name AUTO_RQSTS - This register allows the DWC_trng to generate a reseed reminder alarm after a specified number of random numbers have been requested by the host. */
/*! @{ */

#define HDMI_TRNG_AUTO_RQSTS_RQSTS_MASK          (0xFFFFU)
#define HDMI_TRNG_AUTO_RQSTS_RQSTS_SHIFT         (0U)
/*! RQSTS - 0 = disable the AUTO_RQSTS alarm feature other = reload value for internal AUTO_RQSTS counter */
#define HDMI_TRNG_AUTO_RQSTS_RQSTS(x)            (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_AUTO_RQSTS_RQSTS_SHIFT)) & HDMI_TRNG_AUTO_RQSTS_RQSTS_MASK)
/*! @} */

/*! @name AUTO_AGE - This register allows the DWC_trng to generate a reseed reminder alarm after a specified number of random numbers have been requested by the host. */
/*! @{ */

#define HDMI_TRNG_AUTO_AGE_AGE_MASK              (0xFFFFU)
#define HDMI_TRNG_AUTO_AGE_AGE_SHIFT             (0U)
/*! AGE - 0 = disable the AUTO_AGE alarm feature other = reload value for internal AUTO_AGE counter */
#define HDMI_TRNG_AUTO_AGE_AGE(x)                (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_AUTO_AGE_AGE_SHIFT)) & HDMI_TRNG_AUTO_AGE_AGE_MASK)
/*! @} */

/*! @name BUILD_CONFIG - Contains the build-time parameter enumerations. */
/*! @{ */

#define HDMI_TRNG_BUILD_CONFIG_CORE_TYPE_MASK    (0x3U)
#define HDMI_TRNG_BUILD_CONFIG_CORE_TYPE_SHIFT   (0U)
/*! CORE_TYPE - Configured I/O style (license controlled).
 *  0b00..5-Wire control/status I/O
 *  0b01..ESM nonce I/O
 *  0b10..ESM nonce I/O with multi-ESM support
 */
#define HDMI_TRNG_BUILD_CONFIG_CORE_TYPE(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_BUILD_CONFIG_CORE_TYPE_SHIFT)) & HDMI_TRNG_BUILD_CONFIG_CORE_TYPE_MASK)

#define HDMI_TRNG_BUILD_CONFIG_MAX_PRNG_LEN_MASK (0x4U)
#define HDMI_TRNG_BUILD_CONFIG_MAX_PRNG_LEN_SHIFT (2U)
/*! MAX_PRNG_LEN - Maximum length of the PRNG RANDx register set.
 *  0b0..PRNG set up for 128-bit maximum
 *  0b1..PRNG set up for 256-bit maximum
 */
#define HDMI_TRNG_BUILD_CONFIG_MAX_PRNG_LEN(x)   (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_BUILD_CONFIG_MAX_PRNG_LEN_SHIFT)) & HDMI_TRNG_BUILD_CONFIG_MAX_PRNG_LEN_MASK)

#define HDMI_TRNG_BUILD_CONFIG_PRNG_LEN_AFTER_RST_MASK (0x8U)
#define HDMI_TRNG_BUILD_CONFIG_PRNG_LEN_AFTER_RST_SHIFT (3U)
/*! PRNG_LEN_AFTER_RST - State of MODE.
 *  0b0..PRNG length set to 128-bit after reset
 *  0b1..PRNG length set to 256-bit after reset
 */
#define HDMI_TRNG_BUILD_CONFIG_PRNG_LEN_AFTER_RST(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_BUILD_CONFIG_PRNG_LEN_AFTER_RST_SHIFT)) & HDMI_TRNG_BUILD_CONFIG_PRNG_LEN_AFTER_RST_MASK)

#define HDMI_TRNG_BUILD_CONFIG_MODE_AFTER_RST_MASK (0x10U)
#define HDMI_TRNG_BUILD_CONFIG_MODE_AFTER_RST_SHIFT (4U)
/*! MODE_AFTER_RST - Indicates state of SMODE.
 *  0b0..Resets to TEST_MODE
 *  0b1..Resets to MISSION_MODE
 */
#define HDMI_TRNG_BUILD_CONFIG_MODE_AFTER_RST(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_BUILD_CONFIG_MODE_AFTER_RST_SHIFT)) & HDMI_TRNG_BUILD_CONFIG_MODE_AFTER_RST_MASK)

#define HDMI_TRNG_BUILD_CONFIG_AUTO_RESEED_LOOPBACK_MASK (0x20U)
#define HDMI_TRNG_BUILD_CONFIG_AUTO_RESEED_LOOPBACK_SHIFT (5U)
/*! AUTO_RESEED_LOOPBACK - Indicates auto-reseed configuration setting.
 *  0b0..No auto-reseed loopback
 *  0b1..Auto-reseed loopback present
 */
#define HDMI_TRNG_BUILD_CONFIG_AUTO_RESEED_LOOPBACK(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_BUILD_CONFIG_AUTO_RESEED_LOOPBACK_SHIFT)) & HDMI_TRNG_BUILD_CONFIG_AUTO_RESEED_LOOPBACK_MASK)

#define HDMI_TRNG_BUILD_CONFIG_DIAGNOSTIC_LEVEL_MASK (0x700U)
#define HDMI_TRNG_BUILD_CONFIG_DIAGNOSTIC_LEVEL_SHIFT (8U)
/*! DIAGNOSTIC_LEVEL - Level of diagnostic support provided. */
#define HDMI_TRNG_BUILD_CONFIG_DIAGNOSTIC_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_BUILD_CONFIG_DIAGNOSTIC_LEVEL_SHIFT)) & HDMI_TRNG_BUILD_CONFIG_DIAGNOSTIC_LEVEL_MASK)

#define HDMI_TRNG_BUILD_CONFIG_ESM_PORTS_MASK    (0xF000U)
#define HDMI_TRNG_BUILD_CONFIG_ESM_PORTS_SHIFT   (12U)
/*! ESM_PORTS - Indicates number of ESM arbitration ports available minus 1. */
#define HDMI_TRNG_BUILD_CONFIG_ESM_PORTS(x)      (((uint32_t)(((uint32_t)(x)) << HDMI_TRNG_BUILD_CONFIG_ESM_PORTS_SHIFT)) & HDMI_TRNG_BUILD_CONFIG_ESM_PORTS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group HDMI_TRNG_Register_Masks */


/*!
 * @}
 */ /* end of group HDMI_TRNG_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_HDMI_TRNG_H_ */

