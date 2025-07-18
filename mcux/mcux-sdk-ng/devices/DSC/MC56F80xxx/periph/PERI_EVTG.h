/*
** ###################################################################
**     Processors:          MC56F80623VLC
**                          MC56F80626VLF
**                          MC56F80643VLC
**                          MC56F80646VLF
**                          MC56F80648VLH
**                          MC56F80723VLC
**                          MC56F80726VLF
**                          MC56F80733VFM
**                          MC56F80736VLF
**                          MC56F80738VLH
**                          MC56F80743VFM
**                          MC56F80743VLC
**                          MC56F80746MLF
**                          MC56F80746VLF
**                          MC56F80748MLH
**                          MC56F80748VLH
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for EVTG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2022-01-12)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_EVTG.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for EVTG
 *
 * CMSIS Peripheral Access Layer for EVTG
 */

#if !defined(PERI_EVTG_H_)
#define PERI_EVTG_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F80623VLC))
#include "MC56F80623_COMMON.h"
#elif (defined(CPU_MC56F80626VLF))
#include "MC56F80626_COMMON.h"
#elif (defined(CPU_MC56F80643VLC))
#include "MC56F80643_COMMON.h"
#elif (defined(CPU_MC56F80646VLF))
#include "MC56F80646_COMMON.h"
#elif (defined(CPU_MC56F80648VLH))
#include "MC56F80648_COMMON.h"
#elif (defined(CPU_MC56F80723VLC))
#include "MC56F80723_COMMON.h"
#elif (defined(CPU_MC56F80726VLF))
#include "MC56F80726_COMMON.h"
#elif (defined(CPU_MC56F80733VFM))
#include "MC56F80733_COMMON.h"
#elif (defined(CPU_MC56F80736VLF))
#include "MC56F80736_COMMON.h"
#elif (defined(CPU_MC56F80738VLH))
#include "MC56F80738_COMMON.h"
#elif (defined(CPU_MC56F80743VFM) || defined(CPU_MC56F80743VLC))
#include "MC56F80743_COMMON.h"
#elif (defined(CPU_MC56F80746MLF) || defined(CPU_MC56F80746VLF))
#include "MC56F80746_COMMON.h"
#elif (defined(CPU_MC56F80748MLH) || defined(CPU_MC56F80748VLH))
#include "MC56F80748_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- EVTG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EVTG_Peripheral_Access_Layer EVTG Peripheral Access Layer
 * @{
 */

/** EVTG - Size of Registers Arrays */
#define EVTG_EVTG_INST_COUNT                      4u

/** EVTG - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x8 */
    __IO uint16_t EVTG_AOI0_BFT01;                   /**< AOI0 Boolean Function Term 0 and 1 Configuration Register, array offset: 0x0, array step: 0x8 */
    __IO uint16_t EVTG_AOI0_BFT23;                   /**< AOI0 Boolean Function Term 2 and 3 Configuration Register, array offset: 0x1, array step: 0x8 */
    __IO uint16_t EVTG_AOI1_BFT01;                   /**< AOI1 Boolean Function Term 0 and 1 Configuration Register, array offset: 0x2, array step: 0x8 */
    __IO uint16_t EVTG_AOI1_BFT23;                   /**< AOI1 Boolean Function Term 2 and 3 Configuration Register, array offset: 0x3, array step: 0x8 */
         uint16_t RESERVED_0[1];
    __IO uint16_t EVTG_CTRL;                         /**< Control/Status Register, array offset: 0x5, array step: 0x8 */
    __IO uint16_t EVTG_AOI0_FILT;                    /**< AOI0 Output Filter Register, array offset: 0x6, array step: 0x8 */
    __IO uint16_t EVTG_AOI1_FILT;                    /**< AOI1 Output Filter Register, array offset: 0x7, array step: 0x8 */
  } EVTG_INST[EVTG_EVTG_INST_COUNT];
} EVTG_Type;

/* ----------------------------------------------------------------------------
   -- EVTG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EVTG_Register_Masks EVTG Register Masks
 * @{
 */

/*! @name EVTG_AOI0_BFT01 - AOI0 Boolean Function Term 0 and 1 Configuration Register */
/*! @{ */

#define EVTG_EVTG_AOI0_BFT01_PT1_DC_MASK         (0x3U)
#define EVTG_EVTG_AOI0_BFT01_PT1_DC_SHIFT        (0U)
/*! PT1_DC - Product term 1, D input configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT01_PT1_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT1_DC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT1_DC_MASK)

#define EVTG_EVTG_AOI0_BFT01_PT1_CC_MASK         (0xCU)
#define EVTG_EVTG_AOI0_BFT01_PT1_CC_SHIFT        (2U)
/*! PT1_CC - Product term 1, C input configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT01_PT1_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT1_CC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT1_CC_MASK)

#define EVTG_EVTG_AOI0_BFT01_PT1_BC_MASK         (0x30U)
#define EVTG_EVTG_AOI0_BFT01_PT1_BC_SHIFT        (4U)
/*! PT1_BC - Product term 1, B input configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT01_PT1_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT1_BC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT1_BC_MASK)

#define EVTG_EVTG_AOI0_BFT01_PT1_AC_MASK         (0xC0U)
#define EVTG_EVTG_AOI0_BFT01_PT1_AC_SHIFT        (6U)
/*! PT1_AC - Product term 1, A input configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT01_PT1_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT1_AC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT1_AC_MASK)

#define EVTG_EVTG_AOI0_BFT01_PT0_DC_MASK         (0x300U)
#define EVTG_EVTG_AOI0_BFT01_PT0_DC_SHIFT        (8U)
/*! PT0_DC - Product term 0, D input configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT01_PT0_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT0_DC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT0_DC_MASK)

#define EVTG_EVTG_AOI0_BFT01_PT0_CC_MASK         (0xC00U)
#define EVTG_EVTG_AOI0_BFT01_PT0_CC_SHIFT        (10U)
/*! PT0_CC - Product term 0, C input configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT01_PT0_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT0_CC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT0_CC_MASK)

#define EVTG_EVTG_AOI0_BFT01_PT0_BC_MASK         (0x3000U)
#define EVTG_EVTG_AOI0_BFT01_PT0_BC_SHIFT        (12U)
/*! PT0_BC - Product term 0, B input configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT01_PT0_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT0_BC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT0_BC_MASK)

#define EVTG_EVTG_AOI0_BFT01_PT0_AC_MASK         (0xC000U)
#define EVTG_EVTG_AOI0_BFT01_PT0_AC_SHIFT        (14U)
/*! PT0_AC - Product term 0, A input configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT01_PT0_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT0_AC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT0_AC_MASK)
/*! @} */

/* The count of EVTG_EVTG_AOI0_BFT01 */
#define EVTG_EVTG_AOI0_BFT01_COUNT               (4U)

/*! @name EVTG_AOI0_BFT23 - AOI0 Boolean Function Term 2 and 3 Configuration Register */
/*! @{ */

#define EVTG_EVTG_AOI0_BFT23_PT3_DC_MASK         (0x3U)
#define EVTG_EVTG_AOI0_BFT23_PT3_DC_SHIFT        (0U)
/*! PT3_DC - Product term 3, D input configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT23_PT3_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT3_DC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT3_DC_MASK)

#define EVTG_EVTG_AOI0_BFT23_PT3_CC_MASK         (0xCU)
#define EVTG_EVTG_AOI0_BFT23_PT3_CC_SHIFT        (2U)
/*! PT3_CC - Product term 3, C input configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT23_PT3_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT3_CC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT3_CC_MASK)

#define EVTG_EVTG_AOI0_BFT23_PT3_BC_MASK         (0x30U)
#define EVTG_EVTG_AOI0_BFT23_PT3_BC_SHIFT        (4U)
/*! PT3_BC - Product term 3, B input configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT23_PT3_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT3_BC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT3_BC_MASK)

#define EVTG_EVTG_AOI0_BFT23_PT3_AC_MASK         (0xC0U)
#define EVTG_EVTG_AOI0_BFT23_PT3_AC_SHIFT        (6U)
/*! PT3_AC - Product term 3, A input configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT23_PT3_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT3_AC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT3_AC_MASK)

#define EVTG_EVTG_AOI0_BFT23_PT2_DC_MASK         (0x300U)
#define EVTG_EVTG_AOI0_BFT23_PT2_DC_SHIFT        (8U)
/*! PT2_DC - Product term 2, D input configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT23_PT2_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT2_DC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT2_DC_MASK)

#define EVTG_EVTG_AOI0_BFT23_PT2_CC_MASK         (0xC00U)
#define EVTG_EVTG_AOI0_BFT23_PT2_CC_SHIFT        (10U)
/*! PT2_CC - Product term 2, C input configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT23_PT2_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT2_CC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT2_CC_MASK)

#define EVTG_EVTG_AOI0_BFT23_PT2_BC_MASK         (0x3000U)
#define EVTG_EVTG_AOI0_BFT23_PT2_BC_SHIFT        (12U)
/*! PT2_BC - Product term 2, B input configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT23_PT2_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT2_BC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT2_BC_MASK)

#define EVTG_EVTG_AOI0_BFT23_PT2_AC_MASK         (0xC000U)
#define EVTG_EVTG_AOI0_BFT23_PT2_AC_SHIFT        (14U)
/*! PT2_AC - Product term 2, A input configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_AOI0_BFT23_PT2_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT2_AC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT2_AC_MASK)
/*! @} */

/* The count of EVTG_EVTG_AOI0_BFT23 */
#define EVTG_EVTG_AOI0_BFT23_COUNT               (4U)

/*! @name EVTG_AOI1_BFT01 - AOI1 Boolean Function Term 0 and 1 Configuration Register */
/*! @{ */

#define EVTG_EVTG_AOI1_BFT01_PT1_DC_MASK         (0x3U)
#define EVTG_EVTG_AOI1_BFT01_PT1_DC_SHIFT        (0U)
/*! PT1_DC - Product term 1, D input configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT01_PT1_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT1_DC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT1_DC_MASK)

#define EVTG_EVTG_AOI1_BFT01_PT1_CC_MASK         (0xCU)
#define EVTG_EVTG_AOI1_BFT01_PT1_CC_SHIFT        (2U)
/*! PT1_CC - Product term 1, C input configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT01_PT1_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT1_CC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT1_CC_MASK)

#define EVTG_EVTG_AOI1_BFT01_PT1_BC_MASK         (0x30U)
#define EVTG_EVTG_AOI1_BFT01_PT1_BC_SHIFT        (4U)
/*! PT1_BC - Product term 1, B input configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT01_PT1_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT1_BC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT1_BC_MASK)

#define EVTG_EVTG_AOI1_BFT01_PT1_AC_MASK         (0xC0U)
#define EVTG_EVTG_AOI1_BFT01_PT1_AC_SHIFT        (6U)
/*! PT1_AC - Product term 1, A input configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT01_PT1_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT1_AC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT1_AC_MASK)

#define EVTG_EVTG_AOI1_BFT01_PT0_DC_MASK         (0x300U)
#define EVTG_EVTG_AOI1_BFT01_PT0_DC_SHIFT        (8U)
/*! PT0_DC - Product term 0, D input configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT01_PT0_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT0_DC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT0_DC_MASK)

#define EVTG_EVTG_AOI1_BFT01_PT0_CC_MASK         (0xC00U)
#define EVTG_EVTG_AOI1_BFT01_PT0_CC_SHIFT        (10U)
/*! PT0_CC - Product term 0, C input configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT01_PT0_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT0_CC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT0_CC_MASK)

#define EVTG_EVTG_AOI1_BFT01_PT0_BC_MASK         (0x3000U)
#define EVTG_EVTG_AOI1_BFT01_PT0_BC_SHIFT        (12U)
/*! PT0_BC - Product term 0, B input configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT01_PT0_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT0_BC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT0_BC_MASK)

#define EVTG_EVTG_AOI1_BFT01_PT0_AC_MASK         (0xC000U)
#define EVTG_EVTG_AOI1_BFT01_PT0_AC_SHIFT        (14U)
/*! PT0_AC - Product term 0, A input configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT01_PT0_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT0_AC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT0_AC_MASK)
/*! @} */

/* The count of EVTG_EVTG_AOI1_BFT01 */
#define EVTG_EVTG_AOI1_BFT01_COUNT               (4U)

/*! @name EVTG_AOI1_BFT23 - AOI1 Boolean Function Term 2 and 3 Configuration Register */
/*! @{ */

#define EVTG_EVTG_AOI1_BFT23_PT3_DC_MASK         (0x3U)
#define EVTG_EVTG_AOI1_BFT23_PT3_DC_SHIFT        (0U)
/*! PT3_DC - Product term 3, D input configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT23_PT3_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT3_DC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT3_DC_MASK)

#define EVTG_EVTG_AOI1_BFT23_PT3_CC_MASK         (0xCU)
#define EVTG_EVTG_AOI1_BFT23_PT3_CC_SHIFT        (2U)
/*! PT3_CC - Product term 3, C input configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT23_PT3_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT3_CC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT3_CC_MASK)

#define EVTG_EVTG_AOI1_BFT23_PT3_BC_MASK         (0x30U)
#define EVTG_EVTG_AOI1_BFT23_PT3_BC_SHIFT        (4U)
/*! PT3_BC - Product term 3, B input configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT23_PT3_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT3_BC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT3_BC_MASK)

#define EVTG_EVTG_AOI1_BFT23_PT3_AC_MASK         (0xC0U)
#define EVTG_EVTG_AOI1_BFT23_PT3_AC_SHIFT        (6U)
/*! PT3_AC - Product term 3, A input configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT23_PT3_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT3_AC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT3_AC_MASK)

#define EVTG_EVTG_AOI1_BFT23_PT2_DC_MASK         (0x300U)
#define EVTG_EVTG_AOI1_BFT23_PT2_DC_SHIFT        (8U)
/*! PT2_DC - Product term 2, D input configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT23_PT2_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT2_DC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT2_DC_MASK)

#define EVTG_EVTG_AOI1_BFT23_PT2_CC_MASK         (0xC00U)
#define EVTG_EVTG_AOI1_BFT23_PT2_CC_SHIFT        (10U)
/*! PT2_CC - Product term 2, C input configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT23_PT2_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT2_CC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT2_CC_MASK)

#define EVTG_EVTG_AOI1_BFT23_PT2_BC_MASK         (0x3000U)
#define EVTG_EVTG_AOI1_BFT23_PT2_BC_SHIFT        (12U)
/*! PT2_BC - Product term 2, B input configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT23_PT2_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT2_BC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT2_BC_MASK)

#define EVTG_EVTG_AOI1_BFT23_PT2_AC_MASK         (0xC000U)
#define EVTG_EVTG_AOI1_BFT23_PT2_AC_SHIFT        (14U)
/*! PT2_AC - Product term 2, A input configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define EVTG_EVTG_AOI1_BFT23_PT2_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT2_AC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT2_AC_MASK)
/*! @} */

/* The count of EVTG_EVTG_AOI1_BFT23 */
#define EVTG_EVTG_AOI1_BFT23_COUNT               (4U)

/*! @name EVTG_CTRL - Control/Status Register */
/*! @{ */

#define EVTG_EVTG_CTRL_FF_INIT_MASK              (0x1U)
#define EVTG_EVTG_CTRL_FF_INIT_SHIFT             (0U)
/*! FF_INIT - Configure flip-flop initial value
 *  0b0..Configure the positive output of flip-flop as "0"
 *  0b1..Configure the positive output of flip-flop as "1"
 */
#define EVTG_EVTG_CTRL_FF_INIT(x)                (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_CTRL_FF_INIT_SHIFT)) & EVTG_EVTG_CTRL_FF_INIT_MASK)

#define EVTG_EVTG_CTRL_INIT_EN_MASK              (0x2U)
#define EVTG_EVTG_CTRL_INIT_EN_SHIFT             (1U)
/*! INIT_EN - Flip-flop initial output enable control
 *  0b0..Write 0 doesn't generate enable pulse
 *  0b1..Write 1 will generate enable pulse
 */
#define EVTG_EVTG_CTRL_INIT_EN(x)                (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_CTRL_INIT_EN_SHIFT)) & EVTG_EVTG_CTRL_INIT_EN_MASK)

#define EVTG_EVTG_CTRL_MODE_SEL_MASK             (0x1CU)
#define EVTG_EVTG_CTRL_MODE_SEL_SHIFT            (2U)
/*! MODE_SEL - Flip-Flop mode configure
 *  0b000..Bypass mode(Default)
 *  0b001..RS trigger mode
 *  0b010..T-FF mode
 *  0b011..D-FF mode
 *  0b100..JK-FF mode
 *  0b101..Latch mode
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define EVTG_EVTG_CTRL_MODE_SEL(x)               (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_CTRL_MODE_SEL_SHIFT)) & EVTG_EVTG_CTRL_MODE_SEL_MASK)

#define EVTG_EVTG_CTRL_FB_OVRD_MASK              (0xC0U)
#define EVTG_EVTG_CTRL_FB_OVRD_SHIFT             (6U)
/*! FB_OVRD - EVTG output feedback override control
 *  0b00..replace An
 *  0b01..replace Bn
 *  0b10..replace Cn
 *  0b11..replace Dn
 */
#define EVTG_EVTG_CTRL_FB_OVRD(x)                (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_CTRL_FB_OVRD_SHIFT)) & EVTG_EVTG_CTRL_FB_OVRD_MASK)

#define EVTG_EVTG_CTRL_SYNC_CTRL_MASK            (0xF00U)
#define EVTG_EVTG_CTRL_SYNC_CTRL_SHIFT           (8U)
/*! SYNC_CTRL - Four EVTG inputs synchronous with bus clk
 *  0b0xxx..EVTG input "Dn" will not be synced.
 *  0b1xxx..EVTG input "Dn" will be synced by two bus clk cycles.
 *  0bx0xx..EVTG input "Cn" will not be synced.
 *  0bx1xx..EVTG input "Cn" will be synced by two bus clk cycles.
 *  0bxx0x..EVTG input "Bn" will not be synced.
 *  0bxx1x..EVTG input "Bn" will be synced by two bus clk cycles.
 *  0bxxx0..EVTG input "An" will not be synced.
 *  0bxxx1..EVTG input "An" will be synced by two bus clk cycles.
 */
#define EVTG_EVTG_CTRL_SYNC_CTRL(x)              (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_CTRL_SYNC_CTRL_SHIFT)) & EVTG_EVTG_CTRL_SYNC_CTRL_MASK)

#define EVTG_EVTG_CTRL_FORCE_BYPASS_MASK         (0x3000U)
#define EVTG_EVTG_CTRL_FORCE_BYPASS_SHIFT        (12U)
/*! FORCE_BYPASS - Force Bypass Control
 *  0b0x..Will not force the bypass
 *  0b1x..Whatever "MODE_SEL" is, will force bypass Flip-Flop and route the AOI_1(Filter_1) value directly to EVTG_OUTB
 *  0bx0..Will not force the bypass
 *  0bx1..Whatever "MODE_SEL" is, will force bypass Flip-Flop and route the AOI_0(Filter_0) value directly to EVTG_OUTA
 */
#define EVTG_EVTG_CTRL_FORCE_BYPASS(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_CTRL_FORCE_BYPASS_SHIFT)) & EVTG_EVTG_CTRL_FORCE_BYPASS_MASK)
/*! @} */

/* The count of EVTG_EVTG_CTRL */
#define EVTG_EVTG_CTRL_COUNT                     (4U)

/*! @name EVTG_AOI0_FILT - AOI0 Output Filter Register */
/*! @{ */

#define EVTG_EVTG_AOI0_FILT_FILT_PER_MASK        (0xFFU)
#define EVTG_EVTG_AOI0_FILT_FILT_PER_SHIFT       (0U)
/*! FILT_PER - Output Filter Sample Period */
#define EVTG_EVTG_AOI0_FILT_FILT_PER(x)          (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_FILT_FILT_PER_SHIFT)) & EVTG_EVTG_AOI0_FILT_FILT_PER_MASK)

#define EVTG_EVTG_AOI0_FILT_FILT_CNT_MASK        (0x700U)
#define EVTG_EVTG_AOI0_FILT_FILT_CNT_SHIFT       (8U)
/*! FILT_CNT - Output Filter Sample Count */
#define EVTG_EVTG_AOI0_FILT_FILT_CNT(x)          (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_FILT_FILT_CNT_SHIFT)) & EVTG_EVTG_AOI0_FILT_FILT_CNT_MASK)
/*! @} */

/* The count of EVTG_EVTG_AOI0_FILT */
#define EVTG_EVTG_AOI0_FILT_COUNT                (4U)

/*! @name EVTG_AOI1_FILT - AOI1 Output Filter Register */
/*! @{ */

#define EVTG_EVTG_AOI1_FILT_FILT_PER_MASK        (0xFFU)
#define EVTG_EVTG_AOI1_FILT_FILT_PER_SHIFT       (0U)
/*! FILT_PER - Output Filter Sample Period */
#define EVTG_EVTG_AOI1_FILT_FILT_PER(x)          (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_FILT_FILT_PER_SHIFT)) & EVTG_EVTG_AOI1_FILT_FILT_PER_MASK)

#define EVTG_EVTG_AOI1_FILT_FILT_CNT_MASK        (0x700U)
#define EVTG_EVTG_AOI1_FILT_FILT_CNT_SHIFT       (8U)
/*! FILT_CNT - Output Filter Sample Count */
#define EVTG_EVTG_AOI1_FILT_FILT_CNT(x)          (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_FILT_FILT_CNT_SHIFT)) & EVTG_EVTG_AOI1_FILT_FILT_CNT_MASK)
/*! @} */

/* The count of EVTG_EVTG_AOI1_FILT */
#define EVTG_EVTG_AOI1_FILT_COUNT                (4U)


/*!
 * @}
 */ /* end of group EVTG_Register_Masks */


/*!
 * @}
 */ /* end of group EVTG_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_EVTG_H_ */

