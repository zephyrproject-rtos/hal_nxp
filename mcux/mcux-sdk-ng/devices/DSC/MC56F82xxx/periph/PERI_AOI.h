/*
** ###################################################################
**     Processors:          MC56F82313VLC
**                          MC56F82316VLF
**                          MC56F82323VFM
**                          MC56F82623VLC
**                          MC56F82643VLC
**                          MC56F82646VLF
**                          MC56F82723VFM
**                          MC56F82723VLC
**                          MC56F82726VLF
**                          MC56F82728VLH
**                          MC56F82733MFM
**                          MC56F82733VFM
**                          MC56F82733VLC
**                          MC56F82736VLF
**                          MC56F82738VLH
**                          MC56F82743VFM
**                          MC56F82743VLC
**                          MC56F82746MLF
**                          MC56F82746VLF
**                          MC56F82748MLH
**                          MC56F82748VLH
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AOI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2020-12-11)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_AOI.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AOI
 *
 * CMSIS Peripheral Access Layer for AOI
 */

#if !defined(PERI_AOI_H_)
#define PERI_AOI_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F82313VLC))
#include "MC56F82313_COMMON.h"
#elif (defined(CPU_MC56F82316VLF))
#include "MC56F82316_COMMON.h"
#elif (defined(CPU_MC56F82323VFM))
#include "MC56F82323_COMMON.h"
#elif (defined(CPU_MC56F82623VLC))
#include "MC56F82623_COMMON.h"
#elif (defined(CPU_MC56F82643VLC))
#include "MC56F82643_COMMON.h"
#elif (defined(CPU_MC56F82646VLF))
#include "MC56F82646_COMMON.h"
#elif (defined(CPU_MC56F82723VFM) || defined(CPU_MC56F82723VLC))
#include "MC56F82723_COMMON.h"
#elif (defined(CPU_MC56F82726VLF))
#include "MC56F82726_COMMON.h"
#elif (defined(CPU_MC56F82728VLH))
#include "MC56F82728_COMMON.h"
#elif (defined(CPU_MC56F82733MFM) || defined(CPU_MC56F82733VFM) || defined(CPU_MC56F82733VLC))
#include "MC56F82733_COMMON.h"
#elif (defined(CPU_MC56F82736VLF))
#include "MC56F82736_COMMON.h"
#elif (defined(CPU_MC56F82738VLH))
#include "MC56F82738_COMMON.h"
#elif (defined(CPU_MC56F82743VFM) || defined(CPU_MC56F82743VLC))
#include "MC56F82743_COMMON.h"
#elif (defined(CPU_MC56F82746MLF) || defined(CPU_MC56F82746VLF))
#include "MC56F82746_COMMON.h"
#elif (defined(CPU_MC56F82748MLH) || defined(CPU_MC56F82748VLH))
#include "MC56F82748_COMMON.h"
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
   -- AOI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AOI_Peripheral_Access_Layer AOI Peripheral Access Layer
 * @{
 */

/** AOI - Size of Registers Arrays */
#define AOI_BFCRT_COUNT                           4u

/** AOI - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x2 */
    __IO uint16_t BFCRT01;                           /**< Boolean Function Term 0 and 1 Configuration Register for EVENTn, array offset: 0x0, array step: 0x2 */
    __IO uint16_t BFCRT23;                           /**< Boolean Function Term 2 and 3 Configuration Register for EVENTn, array offset: 0x1, array step: 0x2 */
  } BFCRT[AOI_BFCRT_COUNT];
} AOI_Type;

/* ----------------------------------------------------------------------------
   -- AOI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AOI_Register_Masks AOI Register Masks
 * @{
 */

/*! @name BFCRT01 - Boolean Function Term 0 and 1 Configuration Register for EVENTn */
/*! @{ */

#define AOI_BFCRT01_PT1_DC_MASK                  (0x3U)
#define AOI_BFCRT01_PT1_DC_SHIFT                 (0U)
/*! PT1_DC - Product term 1, D input configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define AOI_BFCRT01_PT1_DC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT1_DC_SHIFT)) & AOI_BFCRT01_PT1_DC_MASK)

#define AOI_BFCRT01_PT1_CC_MASK                  (0xCU)
#define AOI_BFCRT01_PT1_CC_SHIFT                 (2U)
/*! PT1_CC - Product term 1, C input configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define AOI_BFCRT01_PT1_CC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT1_CC_SHIFT)) & AOI_BFCRT01_PT1_CC_MASK)

#define AOI_BFCRT01_PT1_BC_MASK                  (0x30U)
#define AOI_BFCRT01_PT1_BC_SHIFT                 (4U)
/*! PT1_BC - Product term 1, B input configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define AOI_BFCRT01_PT1_BC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT1_BC_SHIFT)) & AOI_BFCRT01_PT1_BC_MASK)

#define AOI_BFCRT01_PT1_AC_MASK                  (0xC0U)
#define AOI_BFCRT01_PT1_AC_SHIFT                 (6U)
/*! PT1_AC - Product term 1, A input configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define AOI_BFCRT01_PT1_AC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT1_AC_SHIFT)) & AOI_BFCRT01_PT1_AC_MASK)

#define AOI_BFCRT01_PT0_DC_MASK                  (0x300U)
#define AOI_BFCRT01_PT0_DC_SHIFT                 (8U)
/*! PT0_DC - Product term 0, D input configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define AOI_BFCRT01_PT0_DC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT0_DC_SHIFT)) & AOI_BFCRT01_PT0_DC_MASK)

#define AOI_BFCRT01_PT0_CC_MASK                  (0xC00U)
#define AOI_BFCRT01_PT0_CC_SHIFT                 (10U)
/*! PT0_CC - Product term 0, C input configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define AOI_BFCRT01_PT0_CC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT0_CC_SHIFT)) & AOI_BFCRT01_PT0_CC_MASK)

#define AOI_BFCRT01_PT0_BC_MASK                  (0x3000U)
#define AOI_BFCRT01_PT0_BC_SHIFT                 (12U)
/*! PT0_BC - Product term 0, B input configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define AOI_BFCRT01_PT0_BC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT0_BC_SHIFT)) & AOI_BFCRT01_PT0_BC_MASK)

#define AOI_BFCRT01_PT0_AC_MASK                  (0xC000U)
#define AOI_BFCRT01_PT0_AC_SHIFT                 (14U)
/*! PT0_AC - Product term 0, A input configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define AOI_BFCRT01_PT0_AC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT01_PT0_AC_SHIFT)) & AOI_BFCRT01_PT0_AC_MASK)
/*! @} */

/* The count of AOI_BFCRT01 */
#define AOI_BFCRT01_COUNT                        (4U)

/*! @name BFCRT23 - Boolean Function Term 2 and 3 Configuration Register for EVENTn */
/*! @{ */

#define AOI_BFCRT23_PT3_DC_MASK                  (0x3U)
#define AOI_BFCRT23_PT3_DC_SHIFT                 (0U)
/*! PT3_DC - Product term 3, D input configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define AOI_BFCRT23_PT3_DC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT3_DC_SHIFT)) & AOI_BFCRT23_PT3_DC_MASK)

#define AOI_BFCRT23_PT3_CC_MASK                  (0xCU)
#define AOI_BFCRT23_PT3_CC_SHIFT                 (2U)
/*! PT3_CC - Product term 3, C input configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define AOI_BFCRT23_PT3_CC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT3_CC_SHIFT)) & AOI_BFCRT23_PT3_CC_MASK)

#define AOI_BFCRT23_PT3_BC_MASK                  (0x30U)
#define AOI_BFCRT23_PT3_BC_SHIFT                 (4U)
/*! PT3_BC - Product term 3, B input configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define AOI_BFCRT23_PT3_BC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT3_BC_SHIFT)) & AOI_BFCRT23_PT3_BC_MASK)

#define AOI_BFCRT23_PT3_AC_MASK                  (0xC0U)
#define AOI_BFCRT23_PT3_AC_SHIFT                 (6U)
/*! PT3_AC - Product term 3, A input configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define AOI_BFCRT23_PT3_AC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT3_AC_SHIFT)) & AOI_BFCRT23_PT3_AC_MASK)

#define AOI_BFCRT23_PT2_DC_MASK                  (0x300U)
#define AOI_BFCRT23_PT2_DC_SHIFT                 (8U)
/*! PT2_DC - Product term 2, D input configuration
 *  0b00..Force the D input in this product term to a logical zero
 *  0b01..Pass the D input in this product term
 *  0b10..Complement the D input in this product term
 *  0b11..Force the D input in this product term to a logical one
 */
#define AOI_BFCRT23_PT2_DC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT2_DC_SHIFT)) & AOI_BFCRT23_PT2_DC_MASK)

#define AOI_BFCRT23_PT2_CC_MASK                  (0xC00U)
#define AOI_BFCRT23_PT2_CC_SHIFT                 (10U)
/*! PT2_CC - Product term 2, C input configuration
 *  0b00..Force the C input in this product term to a logical zero
 *  0b01..Pass the C input in this product term
 *  0b10..Complement the C input in this product term
 *  0b11..Force the C input in this product term to a logical one
 */
#define AOI_BFCRT23_PT2_CC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT2_CC_SHIFT)) & AOI_BFCRT23_PT2_CC_MASK)

#define AOI_BFCRT23_PT2_BC_MASK                  (0x3000U)
#define AOI_BFCRT23_PT2_BC_SHIFT                 (12U)
/*! PT2_BC - Product term 2, B input configuration
 *  0b00..Force the B input in this product term to a logical zero
 *  0b01..Pass the B input in this product term
 *  0b10..Complement the B input in this product term
 *  0b11..Force the B input in this product term to a logical one
 */
#define AOI_BFCRT23_PT2_BC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT2_BC_SHIFT)) & AOI_BFCRT23_PT2_BC_MASK)

#define AOI_BFCRT23_PT2_AC_MASK                  (0xC000U)
#define AOI_BFCRT23_PT2_AC_SHIFT                 (14U)
/*! PT2_AC - Product term 2, A input configuration
 *  0b00..Force the A input in this product term to a logical zero
 *  0b01..Pass the A input in this product term
 *  0b10..Complement the A input in this product term
 *  0b11..Force the A input in this product term to a logical one
 */
#define AOI_BFCRT23_PT2_AC(x)                    (((uint16_t)(((uint16_t)(x)) << AOI_BFCRT23_PT2_AC_SHIFT)) & AOI_BFCRT23_PT2_AC_MASK)
/*! @} */

/* The count of AOI_BFCRT23 */
#define AOI_BFCRT23_COUNT                        (4U)


/*!
 * @}
 */ /* end of group AOI_Register_Masks */


/*!
 * @}
 */ /* end of group AOI_Peripheral_Access_Layer */


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


#endif  /* PERI_AOI_H_ */

