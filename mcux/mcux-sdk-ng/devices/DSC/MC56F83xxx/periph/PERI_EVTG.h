/*
** ###################################################################
**     Processors:          MC56F83663VLH
**                          MC56F83683VLH
**                          MC56F83686VLK
**                          MC56F83689VLL
**                          MC56F83763AVLH
**                          MC56F83763VLH
**                          MC56F83766VLK
**                          MC56F83769AVLL
**                          MC56F83769VLL
**                          MC56F83783AVLH
**                          MC56F83783VLH
**                          MC56F83786VLK
**                          MC56F83789AVLL
**                          MC56F83789VLL
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
**     - rev. 0.1 (2019-09-23)
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

#if (defined(CPU_MC56F83663VLH))
#include "MC56F83663_COMMON.h"
#elif (defined(CPU_MC56F83683VLH))
#include "MC56F83683_COMMON.h"
#elif (defined(CPU_MC56F83686VLK))
#include "MC56F83686_COMMON.h"
#elif (defined(CPU_MC56F83689VLL))
#include "MC56F83689_COMMON.h"
#elif (defined(CPU_MC56F83763AVLH) || defined(CPU_MC56F83763VLH))
#include "MC56F83763_COMMON.h"
#elif (defined(CPU_MC56F83766VLK))
#include "MC56F83766_COMMON.h"
#elif (defined(CPU_MC56F83769AVLL) || defined(CPU_MC56F83769VLL))
#include "MC56F83769_COMMON.h"
#elif (defined(CPU_MC56F83783AVLH) || defined(CPU_MC56F83783VLH))
#include "MC56F83783_COMMON.h"
#elif (defined(CPU_MC56F83786VLK))
#include "MC56F83786_COMMON.h"
#elif (defined(CPU_MC56F83789AVLL) || defined(CPU_MC56F83789VLL))
#include "MC56F83789_COMMON.h"
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
    __IO uint16_t EVTG_AOI0_FILT;                    /**< AOI0 Input Filter Register, array offset: 0x6, array step: 0x8 */
    __IO uint16_t EVTG_AOI1_FILT;                    /**< AOI1 Input Filter Register, array offset: 0x7, array step: 0x8 */
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
/*! PT1_DC - Product term 1, D input configuration */
#define EVTG_EVTG_AOI0_BFT01_PT1_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT1_DC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT1_DC_MASK)

#define EVTG_EVTG_AOI0_BFT01_PT1_CC_MASK         (0xCU)
#define EVTG_EVTG_AOI0_BFT01_PT1_CC_SHIFT        (2U)
/*! PT1_CC - Product term 1, C input configuration */
#define EVTG_EVTG_AOI0_BFT01_PT1_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT1_CC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT1_CC_MASK)

#define EVTG_EVTG_AOI0_BFT01_PT1_BC_MASK         (0x30U)
#define EVTG_EVTG_AOI0_BFT01_PT1_BC_SHIFT        (4U)
/*! PT1_BC - Product term 1, B input configuration */
#define EVTG_EVTG_AOI0_BFT01_PT1_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT1_BC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT1_BC_MASK)

#define EVTG_EVTG_AOI0_BFT01_PT1_AC_MASK         (0xC0U)
#define EVTG_EVTG_AOI0_BFT01_PT1_AC_SHIFT        (6U)
/*! PT1_AC - Product term 1, A input configuration */
#define EVTG_EVTG_AOI0_BFT01_PT1_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT1_AC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT1_AC_MASK)

#define EVTG_EVTG_AOI0_BFT01_PT0_DC_MASK         (0x300U)
#define EVTG_EVTG_AOI0_BFT01_PT0_DC_SHIFT        (8U)
/*! PT0_DC - Product term 0, D input configuration */
#define EVTG_EVTG_AOI0_BFT01_PT0_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT0_DC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT0_DC_MASK)

#define EVTG_EVTG_AOI0_BFT01_PT0_CC_MASK         (0xC00U)
#define EVTG_EVTG_AOI0_BFT01_PT0_CC_SHIFT        (10U)
/*! PT0_CC - Product term 0, C input configuration */
#define EVTG_EVTG_AOI0_BFT01_PT0_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT0_CC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT0_CC_MASK)

#define EVTG_EVTG_AOI0_BFT01_PT0_BC_MASK         (0x3000U)
#define EVTG_EVTG_AOI0_BFT01_PT0_BC_SHIFT        (12U)
/*! PT0_BC - Product term 0, B input configuration */
#define EVTG_EVTG_AOI0_BFT01_PT0_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT0_BC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT0_BC_MASK)

#define EVTG_EVTG_AOI0_BFT01_PT0_AC_MASK         (0xC000U)
#define EVTG_EVTG_AOI0_BFT01_PT0_AC_SHIFT        (14U)
/*! PT0_AC - Product term 0, A input configuration */
#define EVTG_EVTG_AOI0_BFT01_PT0_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT01_PT0_AC_SHIFT)) & EVTG_EVTG_AOI0_BFT01_PT0_AC_MASK)
/*! @} */

/* The count of EVTG_EVTG_AOI0_BFT01 */
#define EVTG_EVTG_AOI0_BFT01_COUNT               (4U)

/*! @name EVTG_AOI0_BFT23 - AOI0 Boolean Function Term 2 and 3 Configuration Register */
/*! @{ */

#define EVTG_EVTG_AOI0_BFT23_PT3_DC_MASK         (0x3U)
#define EVTG_EVTG_AOI0_BFT23_PT3_DC_SHIFT        (0U)
/*! PT3_DC - Product term 3, D input configuration */
#define EVTG_EVTG_AOI0_BFT23_PT3_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT3_DC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT3_DC_MASK)

#define EVTG_EVTG_AOI0_BFT23_PT3_CC_MASK         (0xCU)
#define EVTG_EVTG_AOI0_BFT23_PT3_CC_SHIFT        (2U)
/*! PT3_CC - Product term 3, C input configuration */
#define EVTG_EVTG_AOI0_BFT23_PT3_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT3_CC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT3_CC_MASK)

#define EVTG_EVTG_AOI0_BFT23_PT3_BC_MASK         (0x30U)
#define EVTG_EVTG_AOI0_BFT23_PT3_BC_SHIFT        (4U)
/*! PT3_BC - Product term 3, B input configuration */
#define EVTG_EVTG_AOI0_BFT23_PT3_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT3_BC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT3_BC_MASK)

#define EVTG_EVTG_AOI0_BFT23_PT3_AC_MASK         (0xC0U)
#define EVTG_EVTG_AOI0_BFT23_PT3_AC_SHIFT        (6U)
/*! PT3_AC - Product term 3, A input configuration */
#define EVTG_EVTG_AOI0_BFT23_PT3_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT3_AC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT3_AC_MASK)

#define EVTG_EVTG_AOI0_BFT23_PT2_DC_MASK         (0x300U)
#define EVTG_EVTG_AOI0_BFT23_PT2_DC_SHIFT        (8U)
/*! PT2_DC - Product term 2, D input configuration */
#define EVTG_EVTG_AOI0_BFT23_PT2_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT2_DC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT2_DC_MASK)

#define EVTG_EVTG_AOI0_BFT23_PT2_CC_MASK         (0xC00U)
#define EVTG_EVTG_AOI0_BFT23_PT2_CC_SHIFT        (10U)
/*! PT2_CC - Product term 2, C input configuration */
#define EVTG_EVTG_AOI0_BFT23_PT2_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT2_CC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT2_CC_MASK)

#define EVTG_EVTG_AOI0_BFT23_PT2_BC_MASK         (0x3000U)
#define EVTG_EVTG_AOI0_BFT23_PT2_BC_SHIFT        (12U)
/*! PT2_BC - Product term 2, B input configuration */
#define EVTG_EVTG_AOI0_BFT23_PT2_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT2_BC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT2_BC_MASK)

#define EVTG_EVTG_AOI0_BFT23_PT2_AC_MASK         (0xC000U)
#define EVTG_EVTG_AOI0_BFT23_PT2_AC_SHIFT        (14U)
/*! PT2_AC - Product term 2, A input configuration */
#define EVTG_EVTG_AOI0_BFT23_PT2_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_BFT23_PT2_AC_SHIFT)) & EVTG_EVTG_AOI0_BFT23_PT2_AC_MASK)
/*! @} */

/* The count of EVTG_EVTG_AOI0_BFT23 */
#define EVTG_EVTG_AOI0_BFT23_COUNT               (4U)

/*! @name EVTG_AOI1_BFT01 - AOI1 Boolean Function Term 0 and 1 Configuration Register */
/*! @{ */

#define EVTG_EVTG_AOI1_BFT01_PT1_DC_MASK         (0x3U)
#define EVTG_EVTG_AOI1_BFT01_PT1_DC_SHIFT        (0U)
/*! PT1_DC - Product term 1, D input configuration */
#define EVTG_EVTG_AOI1_BFT01_PT1_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT1_DC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT1_DC_MASK)

#define EVTG_EVTG_AOI1_BFT01_PT1_CC_MASK         (0xCU)
#define EVTG_EVTG_AOI1_BFT01_PT1_CC_SHIFT        (2U)
/*! PT1_CC - Product term 1, C input configuration */
#define EVTG_EVTG_AOI1_BFT01_PT1_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT1_CC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT1_CC_MASK)

#define EVTG_EVTG_AOI1_BFT01_PT1_BC_MASK         (0x30U)
#define EVTG_EVTG_AOI1_BFT01_PT1_BC_SHIFT        (4U)
/*! PT1_BC - Product term 1, B input configuration */
#define EVTG_EVTG_AOI1_BFT01_PT1_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT1_BC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT1_BC_MASK)

#define EVTG_EVTG_AOI1_BFT01_PT1_AC_MASK         (0xC0U)
#define EVTG_EVTG_AOI1_BFT01_PT1_AC_SHIFT        (6U)
/*! PT1_AC - Product term 1, A input configuration */
#define EVTG_EVTG_AOI1_BFT01_PT1_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT1_AC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT1_AC_MASK)

#define EVTG_EVTG_AOI1_BFT01_PT0_DC_MASK         (0x300U)
#define EVTG_EVTG_AOI1_BFT01_PT0_DC_SHIFT        (8U)
/*! PT0_DC - Product term 0, D input configuration */
#define EVTG_EVTG_AOI1_BFT01_PT0_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT0_DC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT0_DC_MASK)

#define EVTG_EVTG_AOI1_BFT01_PT0_CC_MASK         (0xC00U)
#define EVTG_EVTG_AOI1_BFT01_PT0_CC_SHIFT        (10U)
/*! PT0_CC - Product term 0, C input configuration */
#define EVTG_EVTG_AOI1_BFT01_PT0_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT0_CC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT0_CC_MASK)

#define EVTG_EVTG_AOI1_BFT01_PT0_BC_MASK         (0x3000U)
#define EVTG_EVTG_AOI1_BFT01_PT0_BC_SHIFT        (12U)
/*! PT0_BC - Product term 0, B input configuration */
#define EVTG_EVTG_AOI1_BFT01_PT0_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT0_BC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT0_BC_MASK)

#define EVTG_EVTG_AOI1_BFT01_PT0_AC_MASK         (0xC000U)
#define EVTG_EVTG_AOI1_BFT01_PT0_AC_SHIFT        (14U)
/*! PT0_AC - Product term 0, A input configuration */
#define EVTG_EVTG_AOI1_BFT01_PT0_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT01_PT0_AC_SHIFT)) & EVTG_EVTG_AOI1_BFT01_PT0_AC_MASK)
/*! @} */

/* The count of EVTG_EVTG_AOI1_BFT01 */
#define EVTG_EVTG_AOI1_BFT01_COUNT               (4U)

/*! @name EVTG_AOI1_BFT23 - AOI1 Boolean Function Term 2 and 3 Configuration Register */
/*! @{ */

#define EVTG_EVTG_AOI1_BFT23_PT3_DC_MASK         (0x3U)
#define EVTG_EVTG_AOI1_BFT23_PT3_DC_SHIFT        (0U)
/*! PT3_DC - Product term 3, D input configuration */
#define EVTG_EVTG_AOI1_BFT23_PT3_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT3_DC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT3_DC_MASK)

#define EVTG_EVTG_AOI1_BFT23_PT3_CC_MASK         (0xCU)
#define EVTG_EVTG_AOI1_BFT23_PT3_CC_SHIFT        (2U)
/*! PT3_CC - Product term 3, C input configuration */
#define EVTG_EVTG_AOI1_BFT23_PT3_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT3_CC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT3_CC_MASK)

#define EVTG_EVTG_AOI1_BFT23_PT3_BC_MASK         (0x30U)
#define EVTG_EVTG_AOI1_BFT23_PT3_BC_SHIFT        (4U)
/*! PT3_BC - Product term 3, B input configuration */
#define EVTG_EVTG_AOI1_BFT23_PT3_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT3_BC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT3_BC_MASK)

#define EVTG_EVTG_AOI1_BFT23_PT3_AC_MASK         (0xC0U)
#define EVTG_EVTG_AOI1_BFT23_PT3_AC_SHIFT        (6U)
/*! PT3_AC - Product term 3, A input configuration */
#define EVTG_EVTG_AOI1_BFT23_PT3_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT3_AC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT3_AC_MASK)

#define EVTG_EVTG_AOI1_BFT23_PT2_DC_MASK         (0x300U)
#define EVTG_EVTG_AOI1_BFT23_PT2_DC_SHIFT        (8U)
/*! PT2_DC - Product term 2, D input configuration */
#define EVTG_EVTG_AOI1_BFT23_PT2_DC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT2_DC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT2_DC_MASK)

#define EVTG_EVTG_AOI1_BFT23_PT2_CC_MASK         (0xC00U)
#define EVTG_EVTG_AOI1_BFT23_PT2_CC_SHIFT        (10U)
/*! PT2_CC - Product term 2, C input configuration */
#define EVTG_EVTG_AOI1_BFT23_PT2_CC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT2_CC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT2_CC_MASK)

#define EVTG_EVTG_AOI1_BFT23_PT2_BC_MASK         (0x3000U)
#define EVTG_EVTG_AOI1_BFT23_PT2_BC_SHIFT        (12U)
/*! PT2_BC - Product term 2, B input configuration */
#define EVTG_EVTG_AOI1_BFT23_PT2_BC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT2_BC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT2_BC_MASK)

#define EVTG_EVTG_AOI1_BFT23_PT2_AC_MASK         (0xC000U)
#define EVTG_EVTG_AOI1_BFT23_PT2_AC_SHIFT        (14U)
/*! PT2_AC - Product term 2, A input configuration */
#define EVTG_EVTG_AOI1_BFT23_PT2_AC(x)           (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_BFT23_PT2_AC_SHIFT)) & EVTG_EVTG_AOI1_BFT23_PT2_AC_MASK)
/*! @} */

/* The count of EVTG_EVTG_AOI1_BFT23 */
#define EVTG_EVTG_AOI1_BFT23_COUNT               (4U)

/*! @name EVTG_CTRL - Control/Status Register */
/*! @{ */

#define EVTG_EVTG_CTRL_FF_INIT_MASK              (0x1U)
#define EVTG_EVTG_CTRL_FF_INIT_SHIFT             (0U)
/*! FF_INIT - Configure flip-flop initial value */
#define EVTG_EVTG_CTRL_FF_INIT(x)                (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_CTRL_FF_INIT_SHIFT)) & EVTG_EVTG_CTRL_FF_INIT_MASK)

#define EVTG_EVTG_CTRL_INIT_EN_MASK              (0x2U)
#define EVTG_EVTG_CTRL_INIT_EN_SHIFT             (1U)
/*! INIT_EN - Flip-flop initial output enable control */
#define EVTG_EVTG_CTRL_INIT_EN(x)                (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_CTRL_INIT_EN_SHIFT)) & EVTG_EVTG_CTRL_INIT_EN_MASK)

#define EVTG_EVTG_CTRL_MODE_SEL_MASK             (0x1CU)
#define EVTG_EVTG_CTRL_MODE_SEL_SHIFT            (2U)
/*! MODE_SEL - Flip-Flop mode configure */
#define EVTG_EVTG_CTRL_MODE_SEL(x)               (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_CTRL_MODE_SEL_SHIFT)) & EVTG_EVTG_CTRL_MODE_SEL_MASK)

#define EVTG_EVTG_CTRL_FB_OVRD_MASK              (0xC0U)
#define EVTG_EVTG_CTRL_FB_OVRD_SHIFT             (6U)
/*! FB_OVRD - EVTG output feedback override control */
#define EVTG_EVTG_CTRL_FB_OVRD(x)                (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_CTRL_FB_OVRD_SHIFT)) & EVTG_EVTG_CTRL_FB_OVRD_MASK)

#define EVTG_EVTG_CTRL_SYNC_CTRL_MASK            (0xF00U)
#define EVTG_EVTG_CTRL_SYNC_CTRL_SHIFT           (8U)
/*! SYNC_CTRL - Four EVTG inputs synchronous with bus clk */
#define EVTG_EVTG_CTRL_SYNC_CTRL(x)              (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_CTRL_SYNC_CTRL_SHIFT)) & EVTG_EVTG_CTRL_SYNC_CTRL_MASK)
/*! @} */

/* The count of EVTG_EVTG_CTRL */
#define EVTG_EVTG_CTRL_COUNT                     (4U)

/*! @name EVTG_AOI0_FILT - AOI0 Input Filter Register */
/*! @{ */

#define EVTG_EVTG_AOI0_FILT_FILT_PER_MASK        (0xFFU)
#define EVTG_EVTG_AOI0_FILT_FILT_PER_SHIFT       (0U)
/*! FILT_PER - Input Filter Sample Period */
#define EVTG_EVTG_AOI0_FILT_FILT_PER(x)          (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_FILT_FILT_PER_SHIFT)) & EVTG_EVTG_AOI0_FILT_FILT_PER_MASK)

#define EVTG_EVTG_AOI0_FILT_FILT_CNT_MASK        (0x700U)
#define EVTG_EVTG_AOI0_FILT_FILT_CNT_SHIFT       (8U)
/*! FILT_CNT - Input Filter Sample Count */
#define EVTG_EVTG_AOI0_FILT_FILT_CNT(x)          (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI0_FILT_FILT_CNT_SHIFT)) & EVTG_EVTG_AOI0_FILT_FILT_CNT_MASK)
/*! @} */

/* The count of EVTG_EVTG_AOI0_FILT */
#define EVTG_EVTG_AOI0_FILT_COUNT                (4U)

/*! @name EVTG_AOI1_FILT - AOI1 Input Filter Register */
/*! @{ */

#define EVTG_EVTG_AOI1_FILT_FILT_PER_MASK        (0xFFU)
#define EVTG_EVTG_AOI1_FILT_FILT_PER_SHIFT       (0U)
/*! FILT_PER - Input Filter Sample Period */
#define EVTG_EVTG_AOI1_FILT_FILT_PER(x)          (((uint16_t)(((uint16_t)(x)) << EVTG_EVTG_AOI1_FILT_FILT_PER_SHIFT)) & EVTG_EVTG_AOI1_FILT_FILT_PER_MASK)

#define EVTG_EVTG_AOI1_FILT_FILT_CNT_MASK        (0x700U)
#define EVTG_EVTG_AOI1_FILT_FILT_CNT_SHIFT       (8U)
/*! FILT_CNT - Input Filter Sample Count */
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

