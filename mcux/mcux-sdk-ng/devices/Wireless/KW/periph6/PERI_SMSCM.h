/*
** ###################################################################
**     Processors:          KW47B42Z83AFTA_cm33_core0
**                          KW47B42Z83AFTA_cm33_core1
**                          KW47B42Z96AFTA_cm33_core0
**                          KW47B42Z96AFTA_cm33_core1
**                          KW47B42Z97AFTA_cm33_core0
**                          KW47B42Z97AFTA_cm33_core1
**                          KW47B42ZB2AFTA_cm33_core0
**                          KW47B42ZB2AFTA_cm33_core1
**                          KW47B42ZB3AFTA_cm33_core0
**                          KW47B42ZB3AFTA_cm33_core1
**                          KW47B42ZB6AFTA_cm33_core0
**                          KW47B42ZB6AFTA_cm33_core1
**                          KW47B42ZB7AFTA_cm33_core0
**                          KW47B42ZB7AFTA_cm33_core1
**                          KW47Z42082AFTA
**                          KW47Z42092AFTA
**                          KW47Z420B2AFTA
**                          KW47Z420B3AFTA
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250522
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SMSCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-10-13)
**         Rev. 1, 2024-10-13
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SMSCM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SMSCM
 *
 * CMSIS Peripheral Access Layer for SMSCM
 */

#if !defined(PERI_SMSCM_H_)
#define PERI_SMSCM_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW47B42Z83AFTA_cm33_core0))
#include "KW47B42Z83_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z83AFTA_cm33_core1))
#include "KW47B42Z83_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42Z96AFTA_cm33_core0))
#include "KW47B42Z96_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z96AFTA_cm33_core1))
#include "KW47B42Z96_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42Z97AFTA_cm33_core0))
#include "KW47B42Z97_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z97AFTA_cm33_core1))
#include "KW47B42Z97_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB2AFTA_cm33_core0))
#include "KW47B42ZB2_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB2AFTA_cm33_core1))
#include "KW47B42ZB2_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB3AFTA_cm33_core0))
#include "KW47B42ZB3_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB3AFTA_cm33_core1))
#include "KW47B42ZB3_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB6AFTA_cm33_core0))
#include "KW47B42ZB6_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB6AFTA_cm33_core1))
#include "KW47B42ZB6_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB7AFTA_cm33_core0))
#include "KW47B42ZB7_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB7AFTA_cm33_core1))
#include "KW47B42ZB7_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47Z42082AFTA))
#include "KW47Z42082_COMMON.h"
#elif (defined(CPU_KW47Z42092AFTA))
#include "KW47Z42092_COMMON.h"
#elif (defined(CPU_KW47Z420B2AFTA))
#include "KW47Z420B2_COMMON.h"
#elif (defined(CPU_KW47Z420B3AFTA))
#include "KW47Z420B3_COMMON.h"
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
   -- SMSCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMSCM_Peripheral_Access_Layer SMSCM Peripheral Access Layer
 * @{
 */

/** SMSCM - Register Layout Typedef */
typedef struct {
  __IO uint32_t DBGEN;                             /**< Debug Enable, offset: 0x0 */
  __IO uint32_t DBGEN_B;                           /**< Debug Enable Complement, offset: 0x4 */
  __IO uint32_t DBGEN_LOCK;                        /**< Debug Enable Lock, offset: 0x8 */
       uint8_t RESERVED_0[20];
  __IO uint32_t DBG_AUTH_BEACON;                   /**< Debug Authentication Beacon, offset: 0x20 */
       uint8_t RESERVED_1[12];
  __I  uint32_t LIFECYCLE;                         /**< Lifecycle Fuse Word, offset: 0x30 */
  __I  uint32_t LIFECYCLE_B;                       /**< Lifecycle Fuse Word Complement, offset: 0x34 */
       uint8_t RESERVED_2[8];
  __IO uint32_t ROM_LOCKOUT;                       /**< ROM Lockout Register, offset: 0x40 */
       uint8_t RESERVED_3[188];
  __IO uint32_t SCTR;                              /**< Security Counter Register, offset: 0x100 */
  __O  uint32_t SCTRP1;                            /**< Security Counter Plus 1 Register, offset: 0x104 */
       uint8_t RESERVED_4[4];
  __O  uint32_t SCTRM1;                            /**< Security Counter Minus 1 Register, offset: 0x10C */
       uint8_t RESERVED_5[4];
  __O  uint32_t SCTRPX;                            /**< Security Counter Plus X Register, offset: 0x114 */
       uint8_t RESERVED_6[4];
  __O  uint32_t SCTRMX;                            /**< Security Counter Minus X Register, offset: 0x11C */
       uint8_t RESERVED_7[736];
  __IO uint32_t OCMDR0;                            /**< On-Chip Memory Descriptor Register, offset: 0x400 */
       uint8_t RESERVED_8[4];
  __IO uint32_t OCMDR2;                            /**< On-Chip Memory Descriptor Register, offset: 0x408 */
  __IO uint32_t OCMDR3;                            /**< On-Chip Memory Descriptor Register, offset: 0x40C */
       uint8_t RESERVED_9[4];
  __IO uint32_t OCMDR5;                            /**< On-Chip Memory Descriptor Register, offset: 0x414 */
       uint8_t RESERVED_10[104];
  __IO uint32_t OCMECR;                            /**< On-Chip Memory ECC Control Register, offset: 0x480 */
       uint8_t RESERVED_11[4];
  __IO uint32_t OCMEIR;                            /**< On-Chip Memory ECC Interrupt Register, offset: 0x488 */
       uint8_t RESERVED_12[4];
  __I  uint32_t OCMFAR;                            /**< On-Chip Memory Fault Address Register, offset: 0x490 */
  __I  uint32_t OCMFTR;                            /**< On-Chip Memory Fault Attribute Register, offset: 0x494 */
  __I  uint32_t OCMFDRH;                           /**< On-Chip Memory ECC Fault Data High Register, offset: 0x498 */
  __I  uint32_t OCMFDRL;                           /**< On-Chip Memory ECC Fault Data Low Register, offset: 0x49C */
       uint8_t RESERVED_13[1888];
  __IO uint32_t CPCR;                              /**< Core Platform Control Register, offset: 0xC00 */
} SMSCM_Type;

/* ----------------------------------------------------------------------------
   -- SMSCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMSCM_Register_Masks SMSCM Register Masks
 * @{
 */

/*! @name DBGEN - Debug Enable */
/*! @{ */

#define SMSCM_DBGEN_DBGEN_MASK                   (0x7U)
#define SMSCM_DBGEN_DBGEN_SHIFT                  (0U)
/*! DBGEN - Invasive Debug Enable (DFF3 bitfield)
 *  0b000..Invasive Debug Disabled.
 *  0b010..Invasive Debug Enabled.
 *  0b010..W2S - Enable Invasive Debug.
 *  0b101..W5C - Disable Invasive Debug.
 */
#define SMSCM_DBGEN_DBGEN(x)                     (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_DBGEN_SHIFT)) & SMSCM_DBGEN_DBGEN_MASK)

#define SMSCM_DBGEN_SPIDEN_MASK                  (0x70U)
#define SMSCM_DBGEN_SPIDEN_SHIFT                 (4U)
/*! SPIDEN - Secure Invasive Debug Enable (DFF3 bitfield)
 *  0b000..Secure Invasive Debug Disabled.
 *  0b010..Secure Invasive Debug Enabled.
 *  0b010..W2S - Enable Secure Invasive Debug.
 *  0b101..W5C - Disable Secure Invasive Debug.
 */
#define SMSCM_DBGEN_SPIDEN(x)                    (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_SPIDEN_SHIFT)) & SMSCM_DBGEN_SPIDEN_MASK)

#define SMSCM_DBGEN_NIDEN_MASK                   (0x700U)
#define SMSCM_DBGEN_NIDEN_SHIFT                  (8U)
/*! NIDEN - Non-Invasive Debug Enable (DFF3 bitfield)
 *  0b000..Non-Invasive Debug Disabled.
 *  0b010..Non-Invasive Debug Enabled.
 *  0b010..W2S - Enable Non-Invasive Debug.
 *  0b101..W5C - Disable Non-Invasive Debug.
 */
#define SMSCM_DBGEN_NIDEN(x)                     (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_NIDEN_SHIFT)) & SMSCM_DBGEN_NIDEN_MASK)

#define SMSCM_DBGEN_SPNIDEN_MASK                 (0x7000U)
#define SMSCM_DBGEN_SPNIDEN_SHIFT                (12U)
/*! SPNIDEN - Secure Non-Invasive Debug Enable (DFF3 bitfield)
 *  0b000..Secure Non-Invasive Debug Disabled.
 *  0b010..Secure Non-Invasive Debug Enabled.
 *  0b010..W2S - Enable Secure Non-Invasive Debug.
 *  0b101..W5C - Disable Secure Non-Invasive Debug.
 */
#define SMSCM_DBGEN_SPNIDEN(x)                   (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_SPNIDEN_SHIFT)) & SMSCM_DBGEN_SPNIDEN_MASK)

#define SMSCM_DBGEN_ALTDBGEN_MASK                (0x70000U)
#define SMSCM_DBGEN_ALTDBGEN_SHIFT               (16U)
/*! ALTDBGEN - Alternate Invasive Debug Enable (DFF3 bitfield)
 *  0b000..Alternate Invasive Debug Disabled.
 *  0b010..Alternate Invasive Debug Enabled.
 *  0b010..W2S - Enable Alternate Invasive Debug.
 *  0b101..W5C - Disable Alternate Invasive Debug.
 */
#define SMSCM_DBGEN_ALTDBGEN(x)                  (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_ALTDBGEN_SHIFT)) & SMSCM_DBGEN_ALTDBGEN_MASK)

#define SMSCM_DBGEN_ALTEN_MASK                   (0x700000U)
#define SMSCM_DBGEN_ALTEN_SHIFT                  (20U)
/*! ALTEN - Alternate Enable (DFF3 bitfield)
 *  0b000..Alternate Disabled.
 *  0b010..Alternate Enabled.
 *  0b010..W2S - Enable Alternate.
 *  0b101..W5C - Disable Alternate.
 */
#define SMSCM_DBGEN_ALTEN(x)                     (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_ALTEN_SHIFT)) & SMSCM_DBGEN_ALTEN_MASK)
/*! @} */

/*! @name DBGEN_B - Debug Enable Complement */
/*! @{ */

#define SMSCM_DBGEN_B_DBGEN_B_MASK               (0x7U)
#define SMSCM_DBGEN_B_DBGEN_B_SHIFT              (0U)
/*! DBGEN_B - Invasive Debug Enable Complement (DFF3 bitfield)
 *  0b000..Invasive Debug Enabled.
 *  0b010..Invasive Debug Disabled.
 *  0b010..W2S - Disable Invasive Debug.
 *  0b101..W5C - Enable Invasive Debug.
 */
#define SMSCM_DBGEN_B_DBGEN_B(x)                 (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_B_DBGEN_B_SHIFT)) & SMSCM_DBGEN_B_DBGEN_B_MASK)

#define SMSCM_DBGEN_B_SPIDEN_B_MASK              (0x70U)
#define SMSCM_DBGEN_B_SPIDEN_B_SHIFT             (4U)
/*! SPIDEN_B - Secure Invasive Debug Enable - Complement (DFF3 bitfield)
 *  0b000..Secure Invasive Debug Enabled.
 *  0b010..Secure Invasive Debug Disabled.
 *  0b010..W2S - Disable Secure Invasive Debug.
 *  0b101..W5C - Enable Secure Invasive Debug.
 */
#define SMSCM_DBGEN_B_SPIDEN_B(x)                (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_B_SPIDEN_B_SHIFT)) & SMSCM_DBGEN_B_SPIDEN_B_MASK)

#define SMSCM_DBGEN_B_NIDEN_B_MASK               (0x700U)
#define SMSCM_DBGEN_B_NIDEN_B_SHIFT              (8U)
/*! NIDEN_B - Non-Invasive Debug Enable Complement (DFF3 bitfield)
 *  0b000..Non-Invasive Debug Enabled.
 *  0b010..Non-Invasive Debug Disabled.
 *  0b010..W2S - Disable Non-Invasive Debug.
 *  0b101..W5C - Enable Non-Invasive Debug.
 */
#define SMSCM_DBGEN_B_NIDEN_B(x)                 (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_B_NIDEN_B_SHIFT)) & SMSCM_DBGEN_B_NIDEN_B_MASK)

#define SMSCM_DBGEN_B_SPNIDEN_B_MASK             (0x7000U)
#define SMSCM_DBGEN_B_SPNIDEN_B_SHIFT            (12U)
/*! SPNIDEN_B - Secure Non-Invasive Debug Enable Complement (DFF3 bitfield)
 *  0b000..Secure Non-Invasive Debug Enabled.
 *  0b010..Secure Non-Invasive Debug Disabled.
 *  0b010..W2S - Disable Secure Non-Invasive Debug.
 *  0b101..W5C - Enable Secure Non-Invasive Debug.
 */
#define SMSCM_DBGEN_B_SPNIDEN_B(x)               (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_B_SPNIDEN_B_SHIFT)) & SMSCM_DBGEN_B_SPNIDEN_B_MASK)

#define SMSCM_DBGEN_B_ALTDBGEN_B_MASK            (0x70000U)
#define SMSCM_DBGEN_B_ALTDBGEN_B_SHIFT           (16U)
/*! ALTDBGEN_B - Alternate Invasive Debug Enable Complement (DFF3 bitfield)
 *  0b000..Alternate Invasive Debug Enabled.
 *  0b010..Alternate Invasive Debug Disabled.
 *  0b010..W2S - Alternate Disable Invasive Debug.
 *  0b101..W5C - Alternate Enable Invasive Debug.
 */
#define SMSCM_DBGEN_B_ALTDBGEN_B(x)              (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_B_ALTDBGEN_B_SHIFT)) & SMSCM_DBGEN_B_ALTDBGEN_B_MASK)

#define SMSCM_DBGEN_B_ALTEN_B_MASK               (0x700000U)
#define SMSCM_DBGEN_B_ALTEN_B_SHIFT              (20U)
/*! ALTEN_B - Alternate Enable Complement (DFF3 bitfield)
 *  0b000..Alternrate Enabled.
 *  0b010..Alternate Disabled.
 *  0b010..W2S - Disable Alternate.
 *  0b101..W5C - Enable Alternate.
 */
#define SMSCM_DBGEN_B_ALTEN_B(x)                 (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_B_ALTEN_B_SHIFT)) & SMSCM_DBGEN_B_ALTEN_B_MASK)
/*! @} */

/*! @name DBGEN_LOCK - Debug Enable Lock */
/*! @{ */

#define SMSCM_DBGEN_LOCK_LOCK_MASK               (0x7U)
#define SMSCM_DBGEN_LOCK_LOCK_SHIFT              (0U)
/*! LOCK - Lock (DFF3 bitfield)
 *  0b000..DBGEN[SPNIDEN,NIDEN,SPIDEN,DBGEN], DBGEN_B[SPNIDEN_B,NIDEN_B,SPIDEN_B,DBGEN_B], and DBGEN_LOCK[LOCK] unlocked.
 *  0b010..DBGEN[SPNIDEN,NIDEN,SPIDEN,DBGEN], DBGEN_B[SPNIDEN_B,NIDEN_B,SPIDEN_B,DBGEN_B], and DBGEN_LOCK[LOCK] locked.
 *  0b010, 0b000, 0b001, 0b011, 0b100, 0b111..Lock DBGEN[SPNIDEN,NIDEN,SPIDEN,DBGEN], DBGEN_B[SPNIDEN_B,NIDEN_B,SPIDEN_B,DBGEN_B], and DBGEN_LOCK[LOCK].
 *  0b101..When DBGEN_LOCK[LOCK] is locked, DBGEN_LOCK[LOCK] cannot be unlocked with a write of 101b to this
 *         field. When DBGEN_LOCK[LOCK] is unlocked, a write of 101b to this field, DBGEN_LOCK[LOCK] remains unlocked
 *         and the DBGEN[DBGEN, SPIDEN, NIDEN, SPNIDEN],DBGEN_B[DBGEN_B, SPIDEN_B, NIDEN_B, SPNIDEN_B] fields remain
 *         writeable.
 */
#define SMSCM_DBGEN_LOCK_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_LOCK_LOCK_SHIFT)) & SMSCM_DBGEN_LOCK_LOCK_MASK)

#define SMSCM_DBGEN_LOCK_ALT_DBGEN_LOCK_MASK     (0x70000U)
#define SMSCM_DBGEN_LOCK_ALT_DBGEN_LOCK_SHIFT    (16U)
/*! ALT_DBGEN_LOCK - Alternate Lock (DFF3 bitfield)
 *  0b000..ALT_DBGEN, ALT_DBGEN_B, ALT_DBGEN_LOCK unlocked.
 *  0b010..ALT_DBGEN, ALT_DBGEN_B, ALT_DBGEN_LOCK locked.
 *  0b010, 0b000, 0b001, 0b011, 0b100, 0b111..Lock DBGEN[ALTDBGEN], DBGEN_B[ALTDBGEN_B, and DBGEN_LOCK[ALT_DBGEN_LOCK].
 *  0b101..When ALT_DBGEN_LOCK is locked, ALT_DBGEN_LOCK cannot be unlocked with a write of 101b to this field.
 *         When ALT_DBGEN_LOCK is unlocked, a write of 101b to this field, ALT_DBGEN_LOCK remains unlocked and
 *         DBGEN/DBGEN_B remains writeable.
 */
#define SMSCM_DBGEN_LOCK_ALT_DBGEN_LOCK(x)       (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_LOCK_ALT_DBGEN_LOCK_SHIFT)) & SMSCM_DBGEN_LOCK_ALT_DBGEN_LOCK_MASK)

#define SMSCM_DBGEN_LOCK_ALT_EN_LOCK_MASK        (0x700000U)
#define SMSCM_DBGEN_LOCK_ALT_EN_LOCK_SHIFT       (20U)
/*! ALT_EN_LOCK - Alternate Lock (DFF3 bitfield)
 *  0b000..ALTEN, ALTEN_B, ALT_EN_LOCK unlocked.
 *  0b010..ALTEN, ALTEN_B, ALT_EN_LOCK locked.
 *  0b010, 0b000, 0b001, 0b011, 0b100, 0b111..Lock DBGEN[ALTEN], DBGEN_B[ALTEN_B, and DBGEN_LOCK[ALT_EN_LOCK].
 *  0b101..f When ALT_EN_LOCK is locked, ALT_EN_LOCK cannot be unlocked with a write of 101b to this field. When
 *         ALT_EN_LOCK is unlocked, a write of 101b to this field, ALT_EN_LOCK remains unlocked and ALTEN/ALTEN_B
 *         remains writeable.
 */
#define SMSCM_DBGEN_LOCK_ALT_EN_LOCK(x)          (((uint32_t)(((uint32_t)(x)) << SMSCM_DBGEN_LOCK_ALT_EN_LOCK_SHIFT)) & SMSCM_DBGEN_LOCK_ALT_EN_LOCK_MASK)
/*! @} */

/*! @name DBG_AUTH_BEACON - Debug Authentication Beacon */
/*! @{ */

#define SMSCM_DBG_AUTH_BEACON_AUTH_BEACON_MASK   (0xFFFFU)
#define SMSCM_DBG_AUTH_BEACON_AUTH_BEACON_SHIFT  (0U)
/*! AUTH_BEACON - Authentication Beacon */
#define SMSCM_DBG_AUTH_BEACON_AUTH_BEACON(x)     (((uint32_t)(((uint32_t)(x)) << SMSCM_DBG_AUTH_BEACON_AUTH_BEACON_SHIFT)) & SMSCM_DBG_AUTH_BEACON_AUTH_BEACON_MASK)

#define SMSCM_DBG_AUTH_BEACON_CREDENTIAL_BEACON_MASK (0xFFFF0000U)
#define SMSCM_DBG_AUTH_BEACON_CREDENTIAL_BEACON_SHIFT (16U)
/*! CREDENTIAL_BEACON - Credential Beacon */
#define SMSCM_DBG_AUTH_BEACON_CREDENTIAL_BEACON(x) (((uint32_t)(((uint32_t)(x)) << SMSCM_DBG_AUTH_BEACON_CREDENTIAL_BEACON_SHIFT)) & SMSCM_DBG_AUTH_BEACON_CREDENTIAL_BEACON_MASK)
/*! @} */

/*! @name LIFECYCLE - Lifecycle Fuse Word */
/*! @{ */

#define SMSCM_LIFECYCLE_CLC_MASK                 (0xFFU)
#define SMSCM_LIFECYCLE_CLC_SHIFT                (0U)
/*! CLC - Converged Lifecycle
 *  0b00000000..BLANK
 *  0b00000001..NXP Fab
 *  0b00000011..NXP Provisioned
 *  0b00000111..OEM Open
 *  0b00001111..OEM Secure World Closed
 *  0b00011111..OEM Closed
 *  0b00111111..OEM Return
 *  0b01111111..NXP Return
 *  0b10011111..OEM Locked
 *  0b11xxxxxx..BRICK
 */
#define SMSCM_LIFECYCLE_CLC(x)                   (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_CLC_SHIFT)) & SMSCM_LIFECYCLE_CLC_MASK)

#define SMSCM_LIFECYCLE_DBG_EN_LOCK_MASK         (0x100U)
#define SMSCM_LIFECYCLE_DBG_EN_LOCK_SHIFT        (8U)
/*! DBG_EN_LOCK - Debug Enable Lock
 *  0b0..The debug access control registers remain open when jumping to customer code.
 *  0b1..The debug access control registers are write-locked before jumping to customer code.
 */
#define SMSCM_LIFECYCLE_DBG_EN_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_DBG_EN_LOCK_SHIFT)) & SMSCM_LIFECYCLE_DBG_EN_LOCK_MASK)

#define SMSCM_LIFECYCLE_DBG_AUTH_DIS_MASK        (0x200U)
#define SMSCM_LIFECYCLE_DBG_AUTH_DIS_SHIFT       (9U)
/*! DBG_AUTH_DIS - Debug Authentication Disabled
 *  0b0..Debug Authentication enabled.
 *  0b1..Debug Authentication disabled.
 */
#define SMSCM_LIFECYCLE_DBG_AUTH_DIS(x)          (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_DBG_AUTH_DIS_SHIFT)) & SMSCM_LIFECYCLE_DBG_AUTH_DIS_MASK)

#define SMSCM_LIFECYCLE_TZM_EN_MASK              (0x400U)
#define SMSCM_LIFECYCLE_TZM_EN_SHIFT             (10U)
/*! TZM_EN - Trust Zone Mode Enable
 *  0b0..TZ-M is disabled by default, can be enabled by software.
 *  0b1..TZ-M is enabled.
 */
#define SMSCM_LIFECYCLE_TZM_EN(x)                (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_TZM_EN_SHIFT)) & SMSCM_LIFECYCLE_TZM_EN_MASK)

#define SMSCM_LIFECYCLE_DICE_EN_MASK             (0x800U)
#define SMSCM_LIFECYCLE_DICE_EN_SHIFT            (11U)
/*! DICE_EN - DICE Enable
 *  0b0..DICE is disabled by default.
 *  0b1..DICE is enabled.
 */
#define SMSCM_LIFECYCLE_DICE_EN(x)               (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_DICE_EN_SHIFT)) & SMSCM_LIFECYCLE_DICE_EN_MASK)

#define SMSCM_LIFECYCLE_SERIAL_DIS_MASK          (0x4000U)
#define SMSCM_LIFECYCLE_SERIAL_DIS_SHIFT         (14U)
/*! SERIAL_DIS - Serial Download Disabled
 *  0b0..Serial download path is enabled.
 *  0b1..Serial download path is disabled.
 */
#define SMSCM_LIFECYCLE_SERIAL_DIS(x)            (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_SERIAL_DIS_SHIFT)) & SMSCM_LIFECYCLE_SERIAL_DIS_MASK)

#define SMSCM_LIFECYCLE_WAKEUP_DIS_MASK          (0x8000U)
#define SMSCM_LIFECYCLE_WAKEUP_DIS_SHIFT         (15U)
/*! WAKEUP_DIS - Wakeup Disabled
 *  0b0..Boot-ROM LP wakup is enabled.
 *  0b1..Boot-ROM LP wakup is disabled.
 */
#define SMSCM_LIFECYCLE_WAKEUP_DIS(x)            (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_WAKEUP_DIS_SHIFT)) & SMSCM_LIFECYCLE_WAKEUP_DIS_MASK)

#define SMSCM_LIFECYCLE_CTRK_REVOKE_MASK         (0xF0000U)
#define SMSCM_LIFECYCLE_CTRK_REVOKE_SHIFT        (16U)
/*! CTRK_REVOKE - Revocation indicator from OEM Firmware Authentication Public Key */
#define SMSCM_LIFECYCLE_CTRK_REVOKE(x)           (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_CTRK_REVOKE_SHIFT)) & SMSCM_LIFECYCLE_CTRK_REVOKE_MASK)

#define SMSCM_LIFECYCLE_SWD_ID_MASK              (0xF0000000U)
#define SMSCM_LIFECYCLE_SWD_ID_SHIFT             (28U)
/*! SWD_ID - Serial Wire Debug Instance ID */
#define SMSCM_LIFECYCLE_SWD_ID(x)                (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_SWD_ID_SHIFT)) & SMSCM_LIFECYCLE_SWD_ID_MASK)
/*! @} */

/*! @name LIFECYCLE_B - Lifecycle Fuse Word Complement */
/*! @{ */

#define SMSCM_LIFECYCLE_B_CLC_B_MASK             (0xFFU)
#define SMSCM_LIFECYCLE_B_CLC_B_SHIFT            (0U)
/*! CLC_B - Converged Lifecycle Complement
 *  0b00xxxxxx..BRICK
 *  0b01100000..OEM Locked
 *  0b10000000..NXP Return
 *  0b11000000..OEM Return
 *  0b11100000..OEM Closed
 *  0b11110000..OEM Secure World Closed
 *  0b11111000..OEM Open
 *  0b11111100..NXP Provisioned
 *  0b11111110..NXP Fab
 *  0b11111111..BLANK
 */
#define SMSCM_LIFECYCLE_B_CLC_B(x)               (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_B_CLC_B_SHIFT)) & SMSCM_LIFECYCLE_B_CLC_B_MASK)

#define SMSCM_LIFECYCLE_B_DBG_EN_LOCK_B_MASK     (0x100U)
#define SMSCM_LIFECYCLE_B_DBG_EN_LOCK_B_SHIFT    (8U)
/*! DBG_EN_LOCK_B - Debug Enable Lock Complement
 *  0b0..The debug access control registers are write-locked before jumping to customer code.
 *  0b1..The debug access control registers remain open when jumping to customer code.
 */
#define SMSCM_LIFECYCLE_B_DBG_EN_LOCK_B(x)       (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_B_DBG_EN_LOCK_B_SHIFT)) & SMSCM_LIFECYCLE_B_DBG_EN_LOCK_B_MASK)

#define SMSCM_LIFECYCLE_B_DBG_AUTH_DIS_B_MASK    (0x200U)
#define SMSCM_LIFECYCLE_B_DBG_AUTH_DIS_B_SHIFT   (9U)
/*! DBG_AUTH_DIS_B - Debug Authentication Disabled Complement
 *  0b0..Debug Authentication disabled.
 *  0b1..Debug Authentication enabled.
 */
#define SMSCM_LIFECYCLE_B_DBG_AUTH_DIS_B(x)      (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_B_DBG_AUTH_DIS_B_SHIFT)) & SMSCM_LIFECYCLE_B_DBG_AUTH_DIS_B_MASK)

#define SMSCM_LIFECYCLE_B_TZM_EN_B_MASK          (0x400U)
#define SMSCM_LIFECYCLE_B_TZM_EN_B_SHIFT         (10U)
/*! TZM_EN_B - Trust Zone Mode Enable Complement
 *  0b0..TZ-M is enabled.
 *  0b1..TZ-M is disabled by default, can be enabled by software.
 */
#define SMSCM_LIFECYCLE_B_TZM_EN_B(x)            (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_B_TZM_EN_B_SHIFT)) & SMSCM_LIFECYCLE_B_TZM_EN_B_MASK)

#define SMSCM_LIFECYCLE_B_DICE_EN_B_MASK         (0x800U)
#define SMSCM_LIFECYCLE_B_DICE_EN_B_SHIFT        (11U)
/*! DICE_EN_B - DICE Enable Complement
 *  0b0..DICE is enabled.
 *  0b1..DICE is disabled by default.
 */
#define SMSCM_LIFECYCLE_B_DICE_EN_B(x)           (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_B_DICE_EN_B_SHIFT)) & SMSCM_LIFECYCLE_B_DICE_EN_B_MASK)

#define SMSCM_LIFECYCLE_B_SERIAL_DIS_B_MASK      (0x4000U)
#define SMSCM_LIFECYCLE_B_SERIAL_DIS_B_SHIFT     (14U)
/*! SERIAL_DIS_B - Serial Download Disabled Complement
 *  0b0..Serial download path is disabled.
 *  0b1..Serial download path is enabled.
 */
#define SMSCM_LIFECYCLE_B_SERIAL_DIS_B(x)        (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_B_SERIAL_DIS_B_SHIFT)) & SMSCM_LIFECYCLE_B_SERIAL_DIS_B_MASK)

#define SMSCM_LIFECYCLE_B_WAKEUP_DIS_B_MASK      (0x8000U)
#define SMSCM_LIFECYCLE_B_WAKEUP_DIS_B_SHIFT     (15U)
/*! WAKEUP_DIS_B - Wakeup Disabled Complement
 *  0b0..Boot-ROM LP wakup is disabled.
 *  0b1..Boot-ROM LP wakup is enabled.
 */
#define SMSCM_LIFECYCLE_B_WAKEUP_DIS_B(x)        (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_B_WAKEUP_DIS_B_SHIFT)) & SMSCM_LIFECYCLE_B_WAKEUP_DIS_B_MASK)

#define SMSCM_LIFECYCLE_B_CTRK_REVOKE_B_MASK     (0xF0000U)
#define SMSCM_LIFECYCLE_B_CTRK_REVOKE_B_SHIFT    (16U)
/*! CTRK_REVOKE_B - Revocation indicator from OEM Firmware Authentication Public Key Complement */
#define SMSCM_LIFECYCLE_B_CTRK_REVOKE_B(x)       (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_B_CTRK_REVOKE_B_SHIFT)) & SMSCM_LIFECYCLE_B_CTRK_REVOKE_B_MASK)

#define SMSCM_LIFECYCLE_B_SWD_ID_B_MASK          (0xF0000000U)
#define SMSCM_LIFECYCLE_B_SWD_ID_B_SHIFT         (28U)
/*! SWD_ID_B - Serial Wire Debug Instance ID Complement */
#define SMSCM_LIFECYCLE_B_SWD_ID_B(x)            (((uint32_t)(((uint32_t)(x)) << SMSCM_LIFECYCLE_B_SWD_ID_B_SHIFT)) & SMSCM_LIFECYCLE_B_SWD_ID_B_MASK)
/*! @} */

/*! @name ROM_LOCKOUT - ROM Lockout Register */
/*! @{ */

#define SMSCM_ROM_LOCKOUT_ROMWA_MASK             (0x3FFFF0U)
#define SMSCM_ROM_LOCKOUT_ROMWA_SHIFT            (4U)
/*! ROMWA - ROM Watermark Address */
#define SMSCM_ROM_LOCKOUT_ROMWA(x)               (((uint32_t)(((uint32_t)(x)) << SMSCM_ROM_LOCKOUT_ROMWA_SHIFT)) & SMSCM_ROM_LOCKOUT_ROMWA_MASK)

#define SMSCM_ROM_LOCKOUT_REGLOCK_MASK           (0xE0000000U)
#define SMSCM_ROM_LOCKOUT_REGLOCK_SHIFT          (29U)
/*! REGLOCK - ROM_LOCKOUT Register Lock (DFF3 bitfield)
 *  0b000..ROM_LOCKOUT unlocked.
 *  0b010..ROM_LOCKOUT locked.
 *  0b010, 0b000, 0b001, 0b011, 0b100, 0b111..Lock ROM_LOCKOUT register.
 *  0b101..Writing this value has no effect.
 */
#define SMSCM_ROM_LOCKOUT_REGLOCK(x)             (((uint32_t)(((uint32_t)(x)) << SMSCM_ROM_LOCKOUT_REGLOCK_SHIFT)) & SMSCM_ROM_LOCKOUT_REGLOCK_MASK)
/*! @} */

/*! @name SCTR - Security Counter Register */
/*! @{ */

#define SMSCM_SCTR_DATA32_MASK                   (0xFFFFFFFFU)
#define SMSCM_SCTR_DATA32_SHIFT                  (0U)
/*! DATA32 - Data, 32 bits */
#define SMSCM_SCTR_DATA32(x)                     (((uint32_t)(((uint32_t)(x)) << SMSCM_SCTR_DATA32_SHIFT)) & SMSCM_SCTR_DATA32_MASK)
/*! @} */

/*! @name SCTRP1 - Security Counter Plus 1 Register */
/*! @{ */

#define SMSCM_SCTRP1_DONTCARE32_MASK             (0xFFFFFFFFU)
#define SMSCM_SCTRP1_DONTCARE32_SHIFT            (0U)
/*! DONTCARE32 - Don't Care Data, 32 bits */
#define SMSCM_SCTRP1_DONTCARE32(x)               (((uint32_t)(((uint32_t)(x)) << SMSCM_SCTRP1_DONTCARE32_SHIFT)) & SMSCM_SCTRP1_DONTCARE32_MASK)
/*! @} */

/*! @name SCTRM1 - Security Counter Minus 1 Register */
/*! @{ */

#define SMSCM_SCTRM1_DONTCARE32_MASK             (0xFFFFFFFFU)
#define SMSCM_SCTRM1_DONTCARE32_SHIFT            (0U)
/*! DONTCARE32 - Don't Care Data, 32 bits */
#define SMSCM_SCTRM1_DONTCARE32(x)               (((uint32_t)(((uint32_t)(x)) << SMSCM_SCTRM1_DONTCARE32_SHIFT)) & SMSCM_SCTRM1_DONTCARE32_MASK)
/*! @} */

/*! @name SCTRPX - Security Counter Plus X Register */
/*! @{ */

#define SMSCM_SCTRPX_DATA32_MASK                 (0xFFFFFFFFU)
#define SMSCM_SCTRPX_DATA32_SHIFT                (0U)
/*! DATA32 - Data, 32 bits */
#define SMSCM_SCTRPX_DATA32(x)                   (((uint32_t)(((uint32_t)(x)) << SMSCM_SCTRPX_DATA32_SHIFT)) & SMSCM_SCTRPX_DATA32_MASK)
/*! @} */

/*! @name SCTRMX - Security Counter Minus X Register */
/*! @{ */

#define SMSCM_SCTRMX_DATA32_MASK                 (0xFFFFFFFFU)
#define SMSCM_SCTRMX_DATA32_SHIFT                (0U)
/*! DATA32 - Data, 32 bits */
#define SMSCM_SCTRMX_DATA32(x)                   (((uint32_t)(((uint32_t)(x)) << SMSCM_SCTRMX_DATA32_SHIFT)) & SMSCM_SCTRMX_DATA32_MASK)
/*! @} */

/*! @name OCMDR0 - On-Chip Memory Descriptor Register */
/*! @{ */

#define SMSCM_OCMDR0_OCMCF0_MASK                 (0xFU)
#define SMSCM_OCMDR0_OCMCF0_SHIFT                (0U)
/*! OCMCF0 - OCMEM Control Field 0 */
#define SMSCM_OCMDR0_OCMCF0(x)                   (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMDR0_OCMCF0_SHIFT)) & SMSCM_OCMDR0_OCMCF0_MASK)

#define SMSCM_OCMDR0_OCMCF1_MASK                 (0xF0U)
#define SMSCM_OCMDR0_OCMCF1_SHIFT                (4U)
/*! OCMCF1 - OCMEM Control Field 1 */
#define SMSCM_OCMDR0_OCMCF1(x)                   (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMDR0_OCMCF1_SHIFT)) & SMSCM_OCMDR0_OCMCF1_MASK)

#define SMSCM_OCMDR0_OCMCF2_MASK                 (0xF00U)
#define SMSCM_OCMDR0_OCMCF2_SHIFT                (8U)
/*! OCMCF2 - OCMEM Control Field 2 */
#define SMSCM_OCMDR0_OCMCF2(x)                   (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMDR0_OCMCF2_SHIFT)) & SMSCM_OCMDR0_OCMCF2_MASK)

#define SMSCM_OCMDR0_RO_MASK                     (0x10000U)
#define SMSCM_OCMDR0_RO_SHIFT                    (16U)
/*! RO - Read-Only
 *  0b0..Writes to the OCMDRn[11:0] are allowed
 *  0b1..Writes to the OCMDRn[11:0] are ignored
 */
#define SMSCM_OCMDR0_RO(x)                       (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMDR0_RO_SHIFT)) & SMSCM_OCMDR0_RO_MASK)
/*! @} */

/*! @name OCMDR2 - On-Chip Memory Descriptor Register */
/*! @{ */

#define SMSCM_OCMDR2_OCMCF0_MASK                 (0xFU)
#define SMSCM_OCMDR2_OCMCF0_SHIFT                (0U)
/*! OCMCF0 - OCMEM Control Field 0 */
#define SMSCM_OCMDR2_OCMCF0(x)                   (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMDR2_OCMCF0_SHIFT)) & SMSCM_OCMDR2_OCMCF0_MASK)

#define SMSCM_OCMDR2_RO_MASK                     (0x10000U)
#define SMSCM_OCMDR2_RO_SHIFT                    (16U)
/*! RO - Read-Only
 *  0b0..Writes to the OCMDRn[11:0] are allowed
 *  0b1..Writes to the OCMDRn[11:0] are ignored
 */
#define SMSCM_OCMDR2_RO(x)                       (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMDR2_RO_SHIFT)) & SMSCM_OCMDR2_RO_MASK)
/*! @} */

/*! @name OCMDR3 - On-Chip Memory Descriptor Register */
/*! @{ */

#define SMSCM_OCMDR3_OCMCF0_MASK                 (0xFU)
#define SMSCM_OCMDR3_OCMCF0_SHIFT                (0U)
/*! OCMCF0 - OCMEM Control Field 0 */
#define SMSCM_OCMDR3_OCMCF0(x)                   (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMDR3_OCMCF0_SHIFT)) & SMSCM_OCMDR3_OCMCF0_MASK)

#define SMSCM_OCMDR3_RO_MASK                     (0x10000U)
#define SMSCM_OCMDR3_RO_SHIFT                    (16U)
/*! RO - Read-Only
 *  0b0..Writes to the OCMDRn[11:0] are allowed
 *  0b1..Writes to the OCMDRn[11:0] are ignored
 */
#define SMSCM_OCMDR3_RO(x)                       (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMDR3_RO_SHIFT)) & SMSCM_OCMDR3_RO_MASK)
/*! @} */

/*! @name OCMDR5 - On-Chip Memory Descriptor Register */
/*! @{ */

#define SMSCM_OCMDR5_OCMCF0_MASK                 (0xFU)
#define SMSCM_OCMDR5_OCMCF0_SHIFT                (0U)
/*! OCMCF0 - OCMEM Control Field 0 */
#define SMSCM_OCMDR5_OCMCF0(x)                   (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMDR5_OCMCF0_SHIFT)) & SMSCM_OCMDR5_OCMCF0_MASK)

#define SMSCM_OCMDR5_RO_MASK                     (0x10000U)
#define SMSCM_OCMDR5_RO_SHIFT                    (16U)
/*! RO - Read-Only
 *  0b0..Writes to the OCMDRn[11:0] are allowed
 *  0b1..Writes to the OCMDRn[11:0] are ignored
 */
#define SMSCM_OCMDR5_RO(x)                       (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMDR5_RO_SHIFT)) & SMSCM_OCMDR5_RO_MASK)
/*! @} */

/*! @name OCMECR - On-Chip Memory ECC Control Register */
/*! @{ */

#define SMSCM_OCMECR_ENCR_MASK                   (0x1U)
#define SMSCM_OCMECR_ENCR_SHIFT                  (0U)
/*! ENCR - Enable RAM ECC Non-correctable Reporting
 *  0b0..Non-correctable reporting disabled
 *  0b1..Non-correctable reporting enabled
 */
#define SMSCM_OCMECR_ENCR(x)                     (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMECR_ENCR_SHIFT)) & SMSCM_OCMECR_ENCR_MASK)

#define SMSCM_OCMECR_E1BR_MASK                   (0x100U)
#define SMSCM_OCMECR_E1BR_SHIFT                  (8U)
/*! E1BR - Enable RAM ECC 1 Bit Reporting
 *  0b0..1-bit reporting disabled
 *  0b1..1-bit reporting enabled
 */
#define SMSCM_OCMECR_E1BR(x)                     (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMECR_E1BR_SHIFT)) & SMSCM_OCMECR_E1BR_MASK)
/*! @} */

/*! @name OCMEIR - On-Chip Memory ECC Interrupt Register */
/*! @{ */

#define SMSCM_OCMEIR_ENCERRN_MASK                (0xFFU)
#define SMSCM_OCMEIR_ENCERRN_SHIFT               (0U)
/*! ENCERRN - ECC Non-correctable Error OCRAMn */
#define SMSCM_OCMEIR_ENCERRN(x)                  (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMEIR_ENCERRN_SHIFT)) & SMSCM_OCMEIR_ENCERRN_MASK)

#define SMSCM_OCMEIR_E1BERRN_MASK                (0xFF00U)
#define SMSCM_OCMEIR_E1BERRN_SHIFT               (8U)
/*! E1BERRN - ECC 1-bit Error OCRAMn */
#define SMSCM_OCMEIR_E1BERRN(x)                  (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMEIR_E1BERRN_SHIFT)) & SMSCM_OCMEIR_E1BERRN_MASK)

#define SMSCM_OCMEIR_EELOC_MASK                  (0xF000000U)
#define SMSCM_OCMEIR_EELOC_SHIFT                 (24U)
/*! EELOC - ECC Error Location
 *  0b0000..non-correctable on OCRAM0
 *  0b0001..non-correctable on OCRAM1
 *  0b0010..non-correctable on OCRAM2
 *  0b0011..non-correctable on OCRAM3
 *  0b0100..non-correctable on OCRAM4
 *  0b0101..non-correctable on OCRAM5
 *  0b0110..non-correctable on OCRAM6
 *  0b0111..non-correctable on OCRAM7
 *  0b1000..1-bit correctable on OCRAM0
 *  0b1001..1-bit correctable on OCRAM1
 *  0b1010..1-bit correctable on OCRAM2
 *  0b1011..1-bit correctable on OCRAM3
 *  0b1100..1-bit correctable on OCRAM4
 *  0b1101..1-bit correctable on OCRAM5
 *  0b1110..1-bit correctable on OCRAM6
 *  0b1111..1-bit correctable on OCRAM7
 */
#define SMSCM_OCMEIR_EELOC(x)                    (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMEIR_EELOC_SHIFT)) & SMSCM_OCMEIR_EELOC_MASK)

#define SMSCM_OCMEIR_VALID_MASK                  (0x80000000U)
#define SMSCM_OCMEIR_VALID_SHIFT                 (31U)
/*! VALID - Valid ECC Error Location field
 *  0b0..ECC Error Location field is not valid
 *  0b1..ECC Error Location field is valid
 */
#define SMSCM_OCMEIR_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMEIR_VALID_SHIFT)) & SMSCM_OCMEIR_VALID_MASK)
/*! @} */

/*! @name OCMFAR - On-Chip Memory Fault Address Register */
/*! @{ */

#define SMSCM_OCMFAR_EFADD_MASK                  (0xFFFFFFFFU)
#define SMSCM_OCMFAR_EFADD_SHIFT                 (0U)
/*! EFADD - ECC Fault Address */
#define SMSCM_OCMFAR_EFADD(x)                    (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMFAR_EFADD_SHIFT)) & SMSCM_OCMFAR_EFADD_MASK)
/*! @} */

/*! @name OCMFTR - On-Chip Memory Fault Attribute Register */
/*! @{ */

#define SMSCM_OCMFTR_EFPRT_MASK                  (0xFU)
#define SMSCM_OCMFTR_EFPRT_SHIFT                 (0U)
/*! EFPRT - On-Chip Memory ECC Fault Protection */
#define SMSCM_OCMFTR_EFPRT(x)                    (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMFTR_EFPRT_SHIFT)) & SMSCM_OCMFTR_EFPRT_MASK)

#define SMSCM_OCMFTR_EFMS_MASK                   (0x70U)
#define SMSCM_OCMFTR_EFMS_SHIFT                  (4U)
/*! EFMS - On-Chip Memory ECC Fault Master Size
 *  0b000..8-bit size
 *  0b001..16-bit size
 *  0b010..32-bit size
 *  0b011..64-bit size
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define SMSCM_OCMFTR_EFMS(x)                     (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMFTR_EFMS_SHIFT)) & SMSCM_OCMFTR_EFMS_MASK)

#define SMSCM_OCMFTR_EFW_MASK                    (0x80U)
#define SMSCM_OCMFTR_EFW_SHIFT                   (7U)
/*! EFW - On-Chip Memory ECC Fault Write
 *  0b0..Last captured ECC event was not a write bus cycle
 *  0b1..Last captured ECC event was a write bus cycle
 */
#define SMSCM_OCMFTR_EFW(x)                      (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMFTR_EFW_SHIFT)) & SMSCM_OCMFTR_EFW_MASK)

#define SMSCM_OCMFTR_EFMST_MASK                  (0xFF00U)
#define SMSCM_OCMFTR_EFMST_SHIFT                 (8U)
/*! EFMST - On-Chip Memory ECC Fault Master Number */
#define SMSCM_OCMFTR_EFMST(x)                    (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMFTR_EFMST_SHIFT)) & SMSCM_OCMFTR_EFMST_MASK)

#define SMSCM_OCMFTR_EFSYN_MASK                  (0xFF0000U)
#define SMSCM_OCMFTR_EFSYN_SHIFT                 (16U)
/*! EFSYN - On-Chip Memory ECC Fault Syndrome */
#define SMSCM_OCMFTR_EFSYN(x)                    (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMFTR_EFSYN_SHIFT)) & SMSCM_OCMFTR_EFSYN_MASK)
/*! @} */

/*! @name OCMFDRH - On-Chip Memory ECC Fault Data High Register */
/*! @{ */

#define SMSCM_OCMFDRH_EFDH_MASK                  (0xFFFFFFFFU)
#define SMSCM_OCMFDRH_EFDH_SHIFT                 (0U)
/*! EFDH - On-Chip Memory ECC Fault Data High */
#define SMSCM_OCMFDRH_EFDH(x)                    (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMFDRH_EFDH_SHIFT)) & SMSCM_OCMFDRH_EFDH_MASK)
/*! @} */

/*! @name OCMFDRL - On-Chip Memory ECC Fault Data Low Register */
/*! @{ */

#define SMSCM_OCMFDRL_EFDL_MASK                  (0xFFFFFFFFU)
#define SMSCM_OCMFDRL_EFDL_SHIFT                 (0U)
/*! EFDL - On-Chip Memory ECC Fault Data Low */
#define SMSCM_OCMFDRL_EFDL(x)                    (((uint32_t)(((uint32_t)(x)) << SMSCM_OCMFDRL_EFDL_SHIFT)) & SMSCM_OCMFDRL_EFDL_MASK)
/*! @} */

/*! @name CPCR - Core Platform Control Register */
/*! @{ */

#define SMSCM_CPCR_AXBS0_RREN_MASK               (0x1U)
#define SMSCM_CPCR_AXBS0_RREN_SHIFT              (0U)
/*! AXBS0_RREN - AXBS0 Round Robin Enable
 *  0b0..AXBS0 in fixed priority arbitration mode at reset.
 *  0b1..AXBS0 in round robin arbitration mode at reset.
 */
#define SMSCM_CPCR_AXBS0_RREN(x)                 (((uint32_t)(((uint32_t)(x)) << SMSCM_CPCR_AXBS0_RREN_SHIFT)) & SMSCM_CPCR_AXBS0_RREN_MASK)

#define SMSCM_CPCR_AXBS1_RREN_MASK               (0x2U)
#define SMSCM_CPCR_AXBS1_RREN_SHIFT              (1U)
/*! AXBS1_RREN - AXBS1 Round Robin Enable
 *  0b0..AXBS1 in fixed priority arbitration mode at reset.
 *  0b1..AXBS1 in round robin arbitration mode at reset.
 */
#define SMSCM_CPCR_AXBS1_RREN(x)                 (((uint32_t)(((uint32_t)(x)) << SMSCM_CPCR_AXBS1_RREN_SHIFT)) & SMSCM_CPCR_AXBS1_RREN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SMSCM_Register_Masks */


/*!
 * @}
 */ /* end of group SMSCM_Peripheral_Access_Layer */


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


#endif  /* PERI_SMSCM_H_ */

