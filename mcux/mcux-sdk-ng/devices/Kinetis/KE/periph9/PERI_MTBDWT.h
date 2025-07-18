/*
** ###################################################################
**     Processors:          MKE12Z512VLH9
**                          MKE12Z512VLL9
**                          MKE13Z512VLH9
**                          MKE13Z512VLL9
**                          MKE17Z512VLH9
**                          MKE17Z512VLL9
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MTBDWT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-03-01)
**         Initial version.
**     - rev. 2.0 (2023-10-08)
**         Based on Rev.1 RM.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MTBDWT.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MTBDWT
 *
 * CMSIS Peripheral Access Layer for MTBDWT
 */

#if !defined(PERI_MTBDWT_H_)
#define PERI_MTBDWT_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE12Z512VLH9) || defined(CPU_MKE12Z512VLL9))
#include "MKE12Z9_COMMON.h"
#elif (defined(CPU_MKE13Z512VLH9) || defined(CPU_MKE13Z512VLL9))
#include "MKE13Z9_COMMON.h"
#elif (defined(CPU_MKE17Z512VLH9) || defined(CPU_MKE17Z512VLL9))
#include "MKE17Z9_COMMON.h"
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
   -- MTBDWT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTBDWT_Peripheral_Access_Layer MTBDWT Peripheral Access Layer
 * @{
 */

/** MTBDWT - Size of Registers Arrays */
#define MTBDWT_PERIPHID_COUNT                     8u
#define MTBDWT_COMPID_COUNT                       4u

/** MTBDWT - Register Layout Typedef */
typedef struct {
  __I  uint32_t CTRL;                              /**< DWT Control Register, offset: 0x0 */
       uint8_t RESERVED_0[28];
  __IO uint32_t COMP0;                             /**< DWT Comparator Register, offset: 0x20 */
  __IO uint32_t MASK0;                             /**< DWT Comparator Mask Register, offset: 0x24 */
  __IO uint32_t FCT0;                              /**< DWT Comparator Function Register 0, offset: 0x28 */
       uint8_t RESERVED_1[4];
  __IO uint32_t COMP1;                             /**< DWT Comparator Register, offset: 0x30 */
  __IO uint32_t MASK1;                             /**< DWT Comparator Mask Register, offset: 0x34 */
  __IO uint32_t FCT1;                              /**< DWT Comparator Function Register 1, offset: 0x38 */
       uint8_t RESERVED_2[452];
  __IO uint32_t TBCTRL;                            /**< DWT Trace Buffer Control Register, offset: 0x200 */
       uint8_t RESERVED_3[3524];
  __I  uint32_t DEVICECFG;                         /**< Device Configuration Register, offset: 0xFC8 */
  __I  uint32_t DEVICETYPID;                       /**< Device Type Identifier Register, offset: 0xFCC */
  __I  uint32_t PERIPHID[MTBDWT_PERIPHID_COUNT];   /**< Peripheral ID Register, array offset: 0xFD0, array step: 0x4 */
  __I  uint32_t COMPID[MTBDWT_COMPID_COUNT];       /**< Component ID Register, array offset: 0xFF0, array step: 0x4 */
} MTBDWT_Type;

/* ----------------------------------------------------------------------------
   -- MTBDWT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTBDWT_Register_Masks MTBDWT Register Masks
 * @{
 */

/*! @name CTRL - DWT Control Register */
/*! @{ */

#define MTBDWT_CTRL_DWTCFGCTRL_MASK              (0xFFFFFFFU)
#define MTBDWT_CTRL_DWTCFGCTRL_SHIFT             (0U)
/*! DWTCFGCTRL - DWT configuration controls */
#define MTBDWT_CTRL_DWTCFGCTRL(x)                (((uint32_t)(((uint32_t)(x)) << MTBDWT_CTRL_DWTCFGCTRL_SHIFT)) & MTBDWT_CTRL_DWTCFGCTRL_MASK)

#define MTBDWT_CTRL_NUMCMP_MASK                  (0xF0000000U)
#define MTBDWT_CTRL_NUMCMP_SHIFT                 (28U)
/*! NUMCMP - Number of comparators */
#define MTBDWT_CTRL_NUMCMP(x)                    (((uint32_t)(((uint32_t)(x)) << MTBDWT_CTRL_NUMCMP_SHIFT)) & MTBDWT_CTRL_NUMCMP_MASK)
/*! @} */

/*! @name COMP0 - DWT Comparator Register */
/*! @{ */

#define MTBDWT_COMP0_COMP_MASK                   (0xFFFFFFFFU)
#define MTBDWT_COMP0_COMP_SHIFT                  (0U)
/*! COMP - Reference value for comparison */
#define MTBDWT_COMP0_COMP(x)                     (((uint32_t)(((uint32_t)(x)) << MTBDWT_COMP0_COMP_SHIFT)) & MTBDWT_COMP0_COMP_MASK)
/*! @} */

/*! @name MASK0 - DWT Comparator Mask Register */
/*! @{ */

#define MTBDWT_MASK0_MASK_MASK                   (0x1FU)
#define MTBDWT_MASK0_MASK_SHIFT                  (0U)
/*! MASK - MASK */
#define MTBDWT_MASK0_MASK(x)                     (((uint32_t)(((uint32_t)(x)) << MTBDWT_MASK0_MASK_SHIFT)) & MTBDWT_MASK0_MASK_MASK)
/*! @} */

/*! @name FCT0 - DWT Comparator Function Register 0 */
/*! @{ */

#define MTBDWT_FCT0_FUNCTION_MASK                (0xFU)
#define MTBDWT_FCT0_FUNCTION_SHIFT               (0U)
/*! FUNCTION - Function
 *  0b0000..Disabled.
 *  0b0001-0b0011..Reserved. Any attempts to use this value results in UNPREDICTABLE behavior.
 *  0b0100..Instruction fetch.
 *  0b0101..Data operand read.
 *  0b0110..Data operand write.
 *  0b0111..Data operand (read + write).
 *  0b1000-0b1111..Reserved. Any attempts to use this value results in UNPREDICTABLE behavior.
 */
#define MTBDWT_FCT0_FUNCTION(x)                  (((uint32_t)(((uint32_t)(x)) << MTBDWT_FCT0_FUNCTION_SHIFT)) & MTBDWT_FCT0_FUNCTION_MASK)

#define MTBDWT_FCT0_DATAVMATCH_MASK              (0x100U)
#define MTBDWT_FCT0_DATAVMATCH_SHIFT             (8U)
/*! DATAVMATCH - Data Value Match
 *  0b0..Perform address comparison.
 *  0b1..Perform data value comparison.
 */
#define MTBDWT_FCT0_DATAVMATCH(x)                (((uint32_t)(((uint32_t)(x)) << MTBDWT_FCT0_DATAVMATCH_SHIFT)) & MTBDWT_FCT0_DATAVMATCH_MASK)

#define MTBDWT_FCT0_DATAVSIZE_MASK               (0xC00U)
#define MTBDWT_FCT0_DATAVSIZE_SHIFT              (10U)
/*! DATAVSIZE - Data Value Size
 *  0b00..Byte.
 *  0b01..Halfword.
 *  0b10..Word.
 *  0b11..Reserved. Any attempts to use this value results in UNPREDICTABLE behavior.
 */
#define MTBDWT_FCT0_DATAVSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << MTBDWT_FCT0_DATAVSIZE_SHIFT)) & MTBDWT_FCT0_DATAVSIZE_MASK)

#define MTBDWT_FCT0_DATAVADDR0_MASK              (0xF000U)
#define MTBDWT_FCT0_DATAVADDR0_SHIFT             (12U)
/*! DATAVADDR0 - Data Value Address 0 */
#define MTBDWT_FCT0_DATAVADDR0(x)                (((uint32_t)(((uint32_t)(x)) << MTBDWT_FCT0_DATAVADDR0_SHIFT)) & MTBDWT_FCT0_DATAVADDR0_MASK)

#define MTBDWT_FCT0_MATCHED_MASK                 (0x1000000U)
#define MTBDWT_FCT0_MATCHED_SHIFT                (24U)
/*! MATCHED - Comparator match
 *  0b0..No match.
 *  0b1..Match occurred.
 */
#define MTBDWT_FCT0_MATCHED(x)                   (((uint32_t)(((uint32_t)(x)) << MTBDWT_FCT0_MATCHED_SHIFT)) & MTBDWT_FCT0_MATCHED_MASK)
/*! @} */

/*! @name COMP1 - DWT Comparator Register */
/*! @{ */

#define MTBDWT_COMP1_COMP_MASK                   (0xFFFFFFFFU)
#define MTBDWT_COMP1_COMP_SHIFT                  (0U)
/*! COMP - Reference value for comparison */
#define MTBDWT_COMP1_COMP(x)                     (((uint32_t)(((uint32_t)(x)) << MTBDWT_COMP1_COMP_SHIFT)) & MTBDWT_COMP1_COMP_MASK)
/*! @} */

/*! @name MASK1 - DWT Comparator Mask Register */
/*! @{ */

#define MTBDWT_MASK1_MASK_MASK                   (0x1FU)
#define MTBDWT_MASK1_MASK_SHIFT                  (0U)
/*! MASK - MASK */
#define MTBDWT_MASK1_MASK(x)                     (((uint32_t)(((uint32_t)(x)) << MTBDWT_MASK1_MASK_SHIFT)) & MTBDWT_MASK1_MASK_MASK)
/*! @} */

/*! @name FCT1 - DWT Comparator Function Register 1 */
/*! @{ */

#define MTBDWT_FCT1_FUNCTION_MASK                (0xFU)
#define MTBDWT_FCT1_FUNCTION_SHIFT               (0U)
/*! FUNCTION - Function
 *  0b0000..Disabled.
 *  0b0001-0b0011..Reserved. Any attempts to use this value results in UNPREDICTABLE behavior.
 *  0b0100..Instruction fetch.
 *  0b0101..Data operand read.
 *  0b0110..Data operand write.
 *  0b0111..Data operand (read + write).
 *  0b1000-0b1111..Reserved. Any attempts to use this value results in UNPREDICTABLE behavior.
 */
#define MTBDWT_FCT1_FUNCTION(x)                  (((uint32_t)(((uint32_t)(x)) << MTBDWT_FCT1_FUNCTION_SHIFT)) & MTBDWT_FCT1_FUNCTION_MASK)

#define MTBDWT_FCT1_MATCHED_MASK                 (0x1000000U)
#define MTBDWT_FCT1_MATCHED_SHIFT                (24U)
/*! MATCHED - Comparator match
 *  0b0..No match.
 *  0b1..Match occurred.
 */
#define MTBDWT_FCT1_MATCHED(x)                   (((uint32_t)(((uint32_t)(x)) << MTBDWT_FCT1_MATCHED_SHIFT)) & MTBDWT_FCT1_MATCHED_MASK)
/*! @} */

/*! @name TBCTRL - DWT Trace Buffer Control Register */
/*! @{ */

#define MTBDWT_TBCTRL_ACOMP0_MASK                (0x1U)
#define MTBDWT_TBCTRL_ACOMP0_SHIFT               (0U)
/*! ACOMP0 - Action based on Comparator 0 match
 *  0b0..Trigger TSTOP based on the assertion of FCT0[MATCHED].
 *  0b1..Trigger TSTART based on the assertion of FCT0[MATCHED].
 */
#define MTBDWT_TBCTRL_ACOMP0(x)                  (((uint32_t)(((uint32_t)(x)) << MTBDWT_TBCTRL_ACOMP0_SHIFT)) & MTBDWT_TBCTRL_ACOMP0_MASK)

#define MTBDWT_TBCTRL_ACOMP1_MASK                (0x2U)
#define MTBDWT_TBCTRL_ACOMP1_SHIFT               (1U)
/*! ACOMP1 - Action based on Comparator 1 match
 *  0b0..Trigger TSTOP based on the assertion of FCT1[MATCHED].
 *  0b1..Trigger TSTART based on the assertion of FCT1[MATCHED].
 */
#define MTBDWT_TBCTRL_ACOMP1(x)                  (((uint32_t)(((uint32_t)(x)) << MTBDWT_TBCTRL_ACOMP1_SHIFT)) & MTBDWT_TBCTRL_ACOMP1_MASK)

#define MTBDWT_TBCTRL_NUMCOMP_MASK               (0xF0000000U)
#define MTBDWT_TBCTRL_NUMCOMP_SHIFT              (28U)
/*! NUMCOMP - Number of Comparators */
#define MTBDWT_TBCTRL_NUMCOMP(x)                 (((uint32_t)(((uint32_t)(x)) << MTBDWT_TBCTRL_NUMCOMP_SHIFT)) & MTBDWT_TBCTRL_NUMCOMP_MASK)
/*! @} */

/*! @name DEVICECFG - Device Configuration Register */
/*! @{ */

#define MTBDWT_DEVICECFG_DEVICECFG_MASK          (0xFFFFFFFFU)
#define MTBDWT_DEVICECFG_DEVICECFG_SHIFT         (0U)
/*! DEVICECFG - DEVICECFG */
#define MTBDWT_DEVICECFG_DEVICECFG(x)            (((uint32_t)(((uint32_t)(x)) << MTBDWT_DEVICECFG_DEVICECFG_SHIFT)) & MTBDWT_DEVICECFG_DEVICECFG_MASK)
/*! @} */

/*! @name DEVICETYPID - Device Type Identifier Register */
/*! @{ */

#define MTBDWT_DEVICETYPID_DEVICETYPID_MASK      (0xFFFFFFFFU)
#define MTBDWT_DEVICETYPID_DEVICETYPID_SHIFT     (0U)
/*! DEVICETYPID - DEVICETYPID */
#define MTBDWT_DEVICETYPID_DEVICETYPID(x)        (((uint32_t)(((uint32_t)(x)) << MTBDWT_DEVICETYPID_DEVICETYPID_SHIFT)) & MTBDWT_DEVICETYPID_DEVICETYPID_MASK)
/*! @} */

/*! @name PERIPHID - Peripheral ID Register */
/*! @{ */

#define MTBDWT_PERIPHID_PERIPHID_MASK            (0xFFFFFFFFU)
#define MTBDWT_PERIPHID_PERIPHID_SHIFT           (0U)
/*! PERIPHID - PERIPHID */
#define MTBDWT_PERIPHID_PERIPHID(x)              (((uint32_t)(((uint32_t)(x)) << MTBDWT_PERIPHID_PERIPHID_SHIFT)) & MTBDWT_PERIPHID_PERIPHID_MASK)
/*! @} */

/*! @name COMPID - Component ID Register */
/*! @{ */

#define MTBDWT_COMPID_COMPID_MASK                (0xFFFFFFFFU)
#define MTBDWT_COMPID_COMPID_SHIFT               (0U)
/*! COMPID - Component ID */
#define MTBDWT_COMPID_COMPID(x)                  (((uint32_t)(((uint32_t)(x)) << MTBDWT_COMPID_COMPID_SHIFT)) & MTBDWT_COMPID_COMPID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MTBDWT_Register_Masks */


/*!
 * @}
 */ /* end of group MTBDWT_Peripheral_Access_Layer */


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


#endif  /* PERI_MTBDWT_H_ */

