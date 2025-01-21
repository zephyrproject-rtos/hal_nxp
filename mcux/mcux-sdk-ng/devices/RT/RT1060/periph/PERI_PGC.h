/*
** ###################################################################
**     Processors:          MIMXRT1061CVJ5A
**                          MIMXRT1061CVJ5B
**                          MIMXRT1061CVL5A
**                          MIMXRT1061CVL5B
**                          MIMXRT1061DVJ6A
**                          MIMXRT1061DVJ6B
**                          MIMXRT1061DVL6A
**                          MIMXRT1061DVL6B
**                          MIMXRT1061XVN5B
**                          MIMXRT1062CVJ5A
**                          MIMXRT1062CVJ5B
**                          MIMXRT1062CVL5A
**                          MIMXRT1062CVL5B
**                          MIMXRT1062DVJ6A
**                          MIMXRT1062DVJ6B
**                          MIMXRT1062DVL6A
**                          MIMXRT1062DVL6B
**                          MIMXRT1062DVN6B
**                          MIMXRT1062XVN5B
**                          MIMXRT106ADVL6A
**                          MIMXRT106CDVL6A
**                          MIMXRT106FDVL6A
**                          MIMXRT106LDVL6A
**                          MIMXRT106SDVL6A
**
**     Version:             rev. 1.4, 2022-03-25
**     Build:               b240705
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PGC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-01-10)
**         Initial version.
**     - rev. 1.0 (2018-11-16)
**         Update header files to align with IMXRT1060RM Rev.0.
**     - rev. 1.1 (2018-11-27)
**         Update header files to align with IMXRT1060RM Rev.1.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1060RM Rev.3.
**     - rev. 1.4 (2022-03-25)
**         Add RT1060X device
**
** ###################################################################
*/

/*!
 * @file PGC.h
 * @version 1.4
 * @date 2022-03-25
 * @brief CMSIS Peripheral Access Layer for PGC
 *
 * CMSIS Peripheral Access Layer for PGC
 */

#if !defined(PGC_H_)
#define PGC_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1061CVJ5A) || defined(CPU_MIMXRT1061CVJ5B) || defined(CPU_MIMXRT1061CVL5A) || defined(CPU_MIMXRT1061CVL5B) || defined(CPU_MIMXRT1061DVJ6A) || defined(CPU_MIMXRT1061DVJ6B) || defined(CPU_MIMXRT1061DVL6A) || defined(CPU_MIMXRT1061DVL6B) || defined(CPU_MIMXRT1061XVN5B))
#include "MIMXRT1061_COMMON.h"
#elif (defined(CPU_MIMXRT1062CVJ5A) || defined(CPU_MIMXRT1062CVJ5B) || defined(CPU_MIMXRT1062CVL5A) || defined(CPU_MIMXRT1062CVL5B) || defined(CPU_MIMXRT1062DVJ6A) || defined(CPU_MIMXRT1062DVJ6B) || defined(CPU_MIMXRT1062DVL6A) || defined(CPU_MIMXRT1062DVL6B) || defined(CPU_MIMXRT1062DVN6B) || defined(CPU_MIMXRT1062XVN5B))
#include "MIMXRT1062_COMMON.h"
#elif (defined(CPU_MIMXRT106ADVL6A))
#include "MIMXRT106A_COMMON.h"
#elif (defined(CPU_MIMXRT106CDVL6A))
#include "MIMXRT106C_COMMON.h"
#elif (defined(CPU_MIMXRT106FDVL6A))
#include "MIMXRT106F_COMMON.h"
#elif (defined(CPU_MIMXRT106LDVL6A))
#include "MIMXRT106L_COMMON.h"
#elif (defined(CPU_MIMXRT106SDVL6A))
#include "MIMXRT106S_COMMON.h"
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
   -- PGC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PGC_Peripheral_Access_Layer PGC Peripheral Access Layer
 * @{
 */

/** PGC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[544];
  __IO uint32_t MEGA_CTRL;                         /**< PGC Mega Control Register, offset: 0x220 */
  __IO uint32_t MEGA_PUPSCR;                       /**< PGC Mega Power Up Sequence Control Register, offset: 0x224 */
  __IO uint32_t MEGA_PDNSCR;                       /**< PGC Mega Pull Down Sequence Control Register, offset: 0x228 */
  __IO uint32_t MEGA_SR;                           /**< PGC Mega Power Gating Controller Status Register, offset: 0x22C */
       uint8_t RESERVED_1[112];
  __IO uint32_t CPU_CTRL;                          /**< PGC CPU Control Register, offset: 0x2A0 */
  __IO uint32_t CPU_PUPSCR;                        /**< PGC CPU Power Up Sequence Control Register, offset: 0x2A4 */
  __IO uint32_t CPU_PDNSCR;                        /**< PGC CPU Pull Down Sequence Control Register, offset: 0x2A8 */
  __IO uint32_t CPU_SR;                            /**< PGC CPU Power Gating Controller Status Register, offset: 0x2AC */
} PGC_Type;

/* ----------------------------------------------------------------------------
   -- PGC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PGC_Register_Masks PGC Register Masks
 * @{
 */

/*! @name MEGA_CTRL - PGC Mega Control Register */
/*! @{ */

#define PGC_MEGA_CTRL_PCR_MASK                   (0x1U)
#define PGC_MEGA_CTRL_PCR_SHIFT                  (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define PGC_MEGA_CTRL_PCR(x)                     (((uint32_t)(((uint32_t)(x)) << PGC_MEGA_CTRL_PCR_SHIFT)) & PGC_MEGA_CTRL_PCR_MASK)
/*! @} */

/*! @name MEGA_PUPSCR - PGC Mega Power Up Sequence Control Register */
/*! @{ */

#define PGC_MEGA_PUPSCR_SW_MASK                  (0x3FU)
#define PGC_MEGA_PUPSCR_SW_SHIFT                 (0U)
#define PGC_MEGA_PUPSCR_SW(x)                    (((uint32_t)(((uint32_t)(x)) << PGC_MEGA_PUPSCR_SW_SHIFT)) & PGC_MEGA_PUPSCR_SW_MASK)

#define PGC_MEGA_PUPSCR_SW2ISO_MASK              (0x3F00U)
#define PGC_MEGA_PUPSCR_SW2ISO_SHIFT             (8U)
#define PGC_MEGA_PUPSCR_SW2ISO(x)                (((uint32_t)(((uint32_t)(x)) << PGC_MEGA_PUPSCR_SW2ISO_SHIFT)) & PGC_MEGA_PUPSCR_SW2ISO_MASK)
/*! @} */

/*! @name MEGA_PDNSCR - PGC Mega Pull Down Sequence Control Register */
/*! @{ */

#define PGC_MEGA_PDNSCR_ISO_MASK                 (0x3FU)
#define PGC_MEGA_PDNSCR_ISO_SHIFT                (0U)
#define PGC_MEGA_PDNSCR_ISO(x)                   (((uint32_t)(((uint32_t)(x)) << PGC_MEGA_PDNSCR_ISO_SHIFT)) & PGC_MEGA_PDNSCR_ISO_MASK)

#define PGC_MEGA_PDNSCR_ISO2SW_MASK              (0x3F00U)
#define PGC_MEGA_PDNSCR_ISO2SW_SHIFT             (8U)
#define PGC_MEGA_PDNSCR_ISO2SW(x)                (((uint32_t)(((uint32_t)(x)) << PGC_MEGA_PDNSCR_ISO2SW_SHIFT)) & PGC_MEGA_PDNSCR_ISO2SW_MASK)
/*! @} */

/*! @name MEGA_SR - PGC Mega Power Gating Controller Status Register */
/*! @{ */

#define PGC_MEGA_SR_PSR_MASK                     (0x1U)
#define PGC_MEGA_SR_PSR_SHIFT                    (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define PGC_MEGA_SR_PSR(x)                       (((uint32_t)(((uint32_t)(x)) << PGC_MEGA_SR_PSR_SHIFT)) & PGC_MEGA_SR_PSR_MASK)
/*! @} */

/*! @name CPU_CTRL - PGC CPU Control Register */
/*! @{ */

#define PGC_CPU_CTRL_PCR_MASK                    (0x1U)
#define PGC_CPU_CTRL_PCR_SHIFT                   (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define PGC_CPU_CTRL_PCR(x)                      (((uint32_t)(((uint32_t)(x)) << PGC_CPU_CTRL_PCR_SHIFT)) & PGC_CPU_CTRL_PCR_MASK)
/*! @} */

/*! @name CPU_PUPSCR - PGC CPU Power Up Sequence Control Register */
/*! @{ */

#define PGC_CPU_PUPSCR_SW_MASK                   (0x3FU)
#define PGC_CPU_PUPSCR_SW_SHIFT                  (0U)
#define PGC_CPU_PUPSCR_SW(x)                     (((uint32_t)(((uint32_t)(x)) << PGC_CPU_PUPSCR_SW_SHIFT)) & PGC_CPU_PUPSCR_SW_MASK)

#define PGC_CPU_PUPSCR_SW2ISO_MASK               (0x3F00U)
#define PGC_CPU_PUPSCR_SW2ISO_SHIFT              (8U)
#define PGC_CPU_PUPSCR_SW2ISO(x)                 (((uint32_t)(((uint32_t)(x)) << PGC_CPU_PUPSCR_SW2ISO_SHIFT)) & PGC_CPU_PUPSCR_SW2ISO_MASK)
/*! @} */

/*! @name CPU_PDNSCR - PGC CPU Pull Down Sequence Control Register */
/*! @{ */

#define PGC_CPU_PDNSCR_ISO_MASK                  (0x3FU)
#define PGC_CPU_PDNSCR_ISO_SHIFT                 (0U)
#define PGC_CPU_PDNSCR_ISO(x)                    (((uint32_t)(((uint32_t)(x)) << PGC_CPU_PDNSCR_ISO_SHIFT)) & PGC_CPU_PDNSCR_ISO_MASK)

#define PGC_CPU_PDNSCR_ISO2SW_MASK               (0x3F00U)
#define PGC_CPU_PDNSCR_ISO2SW_SHIFT              (8U)
#define PGC_CPU_PDNSCR_ISO2SW(x)                 (((uint32_t)(((uint32_t)(x)) << PGC_CPU_PDNSCR_ISO2SW_SHIFT)) & PGC_CPU_PDNSCR_ISO2SW_MASK)
/*! @} */

/*! @name CPU_SR - PGC CPU Power Gating Controller Status Register */
/*! @{ */

#define PGC_CPU_SR_PSR_MASK                      (0x1U)
#define PGC_CPU_SR_PSR_SHIFT                     (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define PGC_CPU_SR_PSR(x)                        (((uint32_t)(((uint32_t)(x)) << PGC_CPU_SR_PSR_SHIFT)) & PGC_CPU_SR_PSR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PGC_Register_Masks */


/*!
 * @}
 */ /* end of group PGC_Peripheral_Access_Layer */


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


#endif  /* PGC_H_ */

