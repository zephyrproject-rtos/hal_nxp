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
**     Version:             rev. 1.0, 2024-10-13
**     Build:               b241128
**
**     Abstract:
**         CMSIS Peripheral Access Layer for REGFILE
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-10-13)
**         Rev. 1, 2024-10-13
**
** ###################################################################
*/

/*!
 * @file REGFILE.h
 * @version 1.0
 * @date 2024-10-13
 * @brief CMSIS Peripheral Access Layer for REGFILE
 *
 * CMSIS Peripheral Access Layer for REGFILE
 */

#if !defined(REGFILE_H_)
#define REGFILE_H_                               /**< Symbol preventing repeated inclusion */

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
   -- REGFILE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup REGFILE_Peripheral_Access_Layer REGFILE Peripheral Access Layer
 * @{
 */

/** REGFILE - Size of Registers Arrays */
#define REGFILE_REG_COUNT                         8u

/** REGFILE - Register Layout Typedef */
typedef struct {
  __IO uint32_t REG[REGFILE_REG_COUNT];            /**< Register File Register 0..Register File Register 7, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[224];
  __IO uint32_t WAR;                               /**< Write Access Register, offset: 0x100, available only on: REGFILE1 (missing on REGFILE0) */
  __IO uint32_t RAR;                               /**< Read Access Register, offset: 0x104, available only on: REGFILE1 (missing on REGFILE0) */
} REGFILE_Type;

/* ----------------------------------------------------------------------------
   -- REGFILE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup REGFILE_Register_Masks REGFILE Register Masks
 * @{
 */

/*! @name REG - Register File Register 0..Register File Register 7 */
/*! @{ */

#define REGFILE_REG_REG_MASK                     (0xFFFFFFFFU)
#define REGFILE_REG_REG_SHIFT                    (0U)
/*! REG - Register File */
#define REGFILE_REG_REG(x)                       (((uint32_t)(((uint32_t)(x)) << REGFILE_REG_REG_SHIFT)) & REGFILE_REG_REG_MASK)
/*! @} */

/*! @name WAR - Write Access Register */
/*! @{ */

#define REGFILE_WAR_WAR0_MASK                    (0x1U)
#define REGFILE_WAR_WAR0_SHIFT                   (0U)
/*! WAR0 - REG0 Register Write Access
 *  0b0..Not allow to write to the REGn register and WARn field until next reset.
 *  0b1..Allow to write to the REGn register and WAR0 field.
 */
#define REGFILE_WAR_WAR0(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_WAR_WAR0_SHIFT)) & REGFILE_WAR_WAR0_MASK)

#define REGFILE_WAR_WAR1_MASK                    (0x2U)
#define REGFILE_WAR_WAR1_SHIFT                   (1U)
/*! WAR1 - REG1 Register Write Access
 *  0b0..Not allow to write to the REGn register and WARn field until next reset.
 *  0b1..Allow to write to the REGn register and WAR1 field.
 */
#define REGFILE_WAR_WAR1(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_WAR_WAR1_SHIFT)) & REGFILE_WAR_WAR1_MASK)

#define REGFILE_WAR_WAR2_MASK                    (0x4U)
#define REGFILE_WAR_WAR2_SHIFT                   (2U)
/*! WAR2 - REG2 Register Write Access
 *  0b0..Not allow to write to the REGn register and WARn field until next reset.
 *  0b1..Allow to write to the REGn register and WAR2 field.
 */
#define REGFILE_WAR_WAR2(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_WAR_WAR2_SHIFT)) & REGFILE_WAR_WAR2_MASK)

#define REGFILE_WAR_WAR3_MASK                    (0x8U)
#define REGFILE_WAR_WAR3_SHIFT                   (3U)
/*! WAR3 - REG3 Register Write Access
 *  0b0..Not allow to write to the REGn register and WARn field until next reset.
 *  0b1..Allow to write to the REGn register and WAR3 field.
 */
#define REGFILE_WAR_WAR3(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_WAR_WAR3_SHIFT)) & REGFILE_WAR_WAR3_MASK)

#define REGFILE_WAR_WAR4_MASK                    (0x10U)
#define REGFILE_WAR_WAR4_SHIFT                   (4U)
/*! WAR4 - REG4 Register Write Access
 *  0b0..Not allow to write to the REGn register and WARn field until next reset.
 *  0b1..Allow to write to the REGn register and WAR4 field.
 */
#define REGFILE_WAR_WAR4(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_WAR_WAR4_SHIFT)) & REGFILE_WAR_WAR4_MASK)

#define REGFILE_WAR_WAR5_MASK                    (0x20U)
#define REGFILE_WAR_WAR5_SHIFT                   (5U)
/*! WAR5 - REG5 Register Write Access
 *  0b0..Not allow to write to the REGn register and WARn field until next reset.
 *  0b1..Allow to write to the REGn register and WAR5 field.
 */
#define REGFILE_WAR_WAR5(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_WAR_WAR5_SHIFT)) & REGFILE_WAR_WAR5_MASK)

#define REGFILE_WAR_WAR6_MASK                    (0x40U)
#define REGFILE_WAR_WAR6_SHIFT                   (6U)
/*! WAR6 - REG6 Register Write Access
 *  0b0..Not allow to write to the REGn register and WARn field until next reset.
 *  0b1..Allow to write to the REGn register and WAR6 field.
 */
#define REGFILE_WAR_WAR6(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_WAR_WAR6_SHIFT)) & REGFILE_WAR_WAR6_MASK)

#define REGFILE_WAR_WAR7_MASK                    (0x80U)
#define REGFILE_WAR_WAR7_SHIFT                   (7U)
/*! WAR7 - REG7 Register Write Access
 *  0b0..Not allow to write to the REGn register and WARn field until next reset.
 *  0b1..Allow to write to the REGn register and WAR7 field.
 */
#define REGFILE_WAR_WAR7(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_WAR_WAR7_SHIFT)) & REGFILE_WAR_WAR7_MASK)
/*! @} */

/*! @name RAR - Read Access Register */
/*! @{ */

#define REGFILE_RAR_RAR0_MASK                    (0x1U)
#define REGFILE_RAR_RAR0_SHIFT                   (0U)
/*! RAR0 - REG0 Register Read Access
 *  0b0..Not allow to read the REGn register until next reset. Reading corresponding REGn register returns all 0.
 *  0b1..Allow to read the REGn register.
 */
#define REGFILE_RAR_RAR0(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_RAR_RAR0_SHIFT)) & REGFILE_RAR_RAR0_MASK)

#define REGFILE_RAR_RAR1_MASK                    (0x2U)
#define REGFILE_RAR_RAR1_SHIFT                   (1U)
/*! RAR1 - REG1 Register Read Access
 *  0b0..Not allow to read the REGn register until next reset. Reading corresponding REGn register returns all 0.
 *  0b1..Allow to read the REGn register.
 */
#define REGFILE_RAR_RAR1(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_RAR_RAR1_SHIFT)) & REGFILE_RAR_RAR1_MASK)

#define REGFILE_RAR_RAR2_MASK                    (0x4U)
#define REGFILE_RAR_RAR2_SHIFT                   (2U)
/*! RAR2 - REG2 Register Read Access
 *  0b0..Not allow to read the REGn register until next reset. Reading corresponding REGn register returns all 0.
 *  0b1..Allow to read the REGn register.
 */
#define REGFILE_RAR_RAR2(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_RAR_RAR2_SHIFT)) & REGFILE_RAR_RAR2_MASK)

#define REGFILE_RAR_RAR3_MASK                    (0x8U)
#define REGFILE_RAR_RAR3_SHIFT                   (3U)
/*! RAR3 - REG3 Register Read Access
 *  0b0..Not allow to read the REGn register until next reset. Reading corresponding REGn register returns all 0.
 *  0b1..Allow to read the REGn register.
 */
#define REGFILE_RAR_RAR3(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_RAR_RAR3_SHIFT)) & REGFILE_RAR_RAR3_MASK)

#define REGFILE_RAR_RAR4_MASK                    (0x10U)
#define REGFILE_RAR_RAR4_SHIFT                   (4U)
/*! RAR4 - REG4 Register Read Access
 *  0b0..Not allow to read the REGn register until next reset. Reading corresponding REGn register returns all 0.
 *  0b1..Allow to read the REGn register.
 */
#define REGFILE_RAR_RAR4(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_RAR_RAR4_SHIFT)) & REGFILE_RAR_RAR4_MASK)

#define REGFILE_RAR_RAR5_MASK                    (0x20U)
#define REGFILE_RAR_RAR5_SHIFT                   (5U)
/*! RAR5 - REG5 Register Read Access
 *  0b0..Not allow to read the REGn register until next reset. Reading corresponding REGn register returns all 0.
 *  0b1..Allow to read the REGn register.
 */
#define REGFILE_RAR_RAR5(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_RAR_RAR5_SHIFT)) & REGFILE_RAR_RAR5_MASK)

#define REGFILE_RAR_RAR6_MASK                    (0x40U)
#define REGFILE_RAR_RAR6_SHIFT                   (6U)
/*! RAR6 - REG6 Register Read Access
 *  0b0..Not allow to read the REGn register until next reset. Reading corresponding REGn register returns all 0.
 *  0b1..Allow to read the REGn register.
 */
#define REGFILE_RAR_RAR6(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_RAR_RAR6_SHIFT)) & REGFILE_RAR_RAR6_MASK)

#define REGFILE_RAR_RAR7_MASK                    (0x80U)
#define REGFILE_RAR_RAR7_SHIFT                   (7U)
/*! RAR7 - REG7 Register Read Access
 *  0b0..Not allow to read the REGn register until next reset. Reading corresponding REGn register returns all 0.
 *  0b1..Allow to read the REGn register.
 */
#define REGFILE_RAR_RAR7(x)                      (((uint32_t)(((uint32_t)(x)) << REGFILE_RAR_RAR7_SHIFT)) & REGFILE_RAR_RAR7_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group REGFILE_Register_Masks */


/*!
 * @}
 */ /* end of group REGFILE_Peripheral_Access_Layer */


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


#endif  /* REGFILE_H_ */

