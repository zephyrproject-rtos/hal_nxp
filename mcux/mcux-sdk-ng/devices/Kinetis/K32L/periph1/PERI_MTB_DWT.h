/*
** ###################################################################
**     Processors:          K32L2A31VLH1A
**                          K32L2A31VLL1A
**                          K32L2A41VLH1A
**                          K32L2A41VLL1A
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MTB_DWT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-30)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MTB_DWT.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MTB_DWT
 *
 * CMSIS Peripheral Access Layer for MTB_DWT
 */

#if !defined(PERI_MTB_DWT_H_)
#define PERI_MTB_DWT_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L2A31VLH1A) || defined(CPU_K32L2A31VLL1A))
#include "K32L2A31A_COMMON.h"
#elif (defined(CPU_K32L2A41VLH1A) || defined(CPU_K32L2A41VLL1A))
#include "K32L2A41A_COMMON.h"
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
   -- MTB_DWT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTB_DWT_Peripheral_Access_Layer MTB_DWT Peripheral Access Layer
 * @{
 */

/** MTB_DWT - Size of Registers Arrays */
#define MTB_DWT_COMPARATOR_COUNT                  2u
#define MTB_DWT_COMPID_COUNT                      4u

/** MTB_DWT - Register Layout Typedef */
typedef struct {
  __I  uint32_t CTRL;                              /**< MTB DWT Control Register, offset: 0x0 */
       uint8_t RESERVED_0[28];
  struct {                                         /* offset: 0x20, array step: 0x10 */
    __IO uint32_t COMP;                              /**< MTB_DWT Comparator Register, array offset: 0x20, array step: 0x10 */
    __IO uint32_t MASK;                              /**< MTB_DWT Comparator Mask Register, array offset: 0x24, array step: 0x10 */
    __IO uint32_t FCT;                               /**< MTB_DWT Comparator Function Register 0..MTB_DWT Comparator Function Register 1, array offset: 0x28, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } COMPARATOR[MTB_DWT_COMPARATOR_COUNT];
       uint8_t RESERVED_1[448];
  __IO uint32_t TBCTRL;                            /**< MTB_DWT Trace Buffer Control Register, offset: 0x200 */
       uint8_t RESERVED_2[3524];
  __I  uint32_t DEVICECFG;                         /**< Device Configuration Register, offset: 0xFC8 */
  __I  uint32_t DEVICETYPID;                       /**< Device Type Identifier Register, offset: 0xFCC */
  __I  uint32_t PERIPHID4;                         /**< Peripheral ID Register, offset: 0xFD0 */
  __I  uint32_t PERIPHID5;                         /**< Peripheral ID Register, offset: 0xFD4 */
  __I  uint32_t PERIPHID6;                         /**< Peripheral ID Register, offset: 0xFD8 */
  __I  uint32_t PERIPHID7;                         /**< Peripheral ID Register, offset: 0xFDC */
  __I  uint32_t PERIPHID0;                         /**< Peripheral ID Register, offset: 0xFE0 */
  __I  uint32_t PERIPHID1;                         /**< Peripheral ID Register, offset: 0xFE4 */
  __I  uint32_t PERIPHID2;                         /**< Peripheral ID Register, offset: 0xFE8 */
  __I  uint32_t PERIPHID3;                         /**< Peripheral ID Register, offset: 0xFEC */
  __I  uint32_t COMPID[MTB_DWT_COMPID_COUNT];      /**< Component ID Register, array offset: 0xFF0, array step: 0x4 */
} MTB_DWT_Type;

/* ----------------------------------------------------------------------------
   -- MTB_DWT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTB_DWT_Register_Masks MTB_DWT Register Masks
 * @{
 */

/*! @name CTRL - MTB DWT Control Register */
/*! @{ */

#define MTB_DWT_CTRL_DWTCFGCTRL_MASK             (0xFFFFFFFU)
#define MTB_DWT_CTRL_DWTCFGCTRL_SHIFT            (0U)
/*! DWTCFGCTRL - DWT configuration controls */
#define MTB_DWT_CTRL_DWTCFGCTRL(x)               (((uint32_t)(((uint32_t)(x)) << MTB_DWT_CTRL_DWTCFGCTRL_SHIFT)) & MTB_DWT_CTRL_DWTCFGCTRL_MASK)

#define MTB_DWT_CTRL_NUMCMP_MASK                 (0xF0000000U)
#define MTB_DWT_CTRL_NUMCMP_SHIFT                (28U)
/*! NUMCMP - Number of comparators */
#define MTB_DWT_CTRL_NUMCMP(x)                   (((uint32_t)(((uint32_t)(x)) << MTB_DWT_CTRL_NUMCMP_SHIFT)) & MTB_DWT_CTRL_NUMCMP_MASK)
/*! @} */

/*! @name COMP - MTB_DWT Comparator Register */
/*! @{ */

#define MTB_DWT_COMP_COMP_MASK                   (0xFFFFFFFFU)
#define MTB_DWT_COMP_COMP_SHIFT                  (0U)
/*! COMP - Reference value for comparison */
#define MTB_DWT_COMP_COMP(x)                     (((uint32_t)(((uint32_t)(x)) << MTB_DWT_COMP_COMP_SHIFT)) & MTB_DWT_COMP_COMP_MASK)
/*! @} */

/* The count of MTB_DWT_COMP */
#define MTB_DWT_COMP_COUNT                       (2U)

/*! @name MASK - MTB_DWT Comparator Mask Register */
/*! @{ */

#define MTB_DWT_MASK_MASK_MASK                   (0x1FU)
#define MTB_DWT_MASK_MASK_SHIFT                  (0U)
/*! MASK - MASK */
#define MTB_DWT_MASK_MASK(x)                     (((uint32_t)(((uint32_t)(x)) << MTB_DWT_MASK_MASK_SHIFT)) & MTB_DWT_MASK_MASK_MASK)
/*! @} */

/* The count of MTB_DWT_MASK */
#define MTB_DWT_MASK_COUNT                       (2U)

/*! @name FCT - MTB_DWT Comparator Function Register 0..MTB_DWT Comparator Function Register 1 */
/*! @{ */

#define MTB_DWT_FCT_FUNCTION_MASK                (0xFU)
#define MTB_DWT_FCT_FUNCTION_SHIFT               (0U)
/*! FUNCTION - Function
 *  0b0000..Disabled.
 *  0b0100..Instruction fetch.
 *  0b0101..Data operand read.
 *  0b0110..Data operand write.
 *  0b0111..Data operand (read + write).
 */
#define MTB_DWT_FCT_FUNCTION(x)                  (((uint32_t)(((uint32_t)(x)) << MTB_DWT_FCT_FUNCTION_SHIFT)) & MTB_DWT_FCT_FUNCTION_MASK)

#define MTB_DWT_FCT_DATAVMATCH_MASK              (0x100U)
#define MTB_DWT_FCT_DATAVMATCH_SHIFT             (8U)
/*! DATAVMATCH - Data Value Match
 *  0b0..Perform address comparison.
 *  0b1..Perform data value comparison.
 */
#define MTB_DWT_FCT_DATAVMATCH(x)                (((uint32_t)(((uint32_t)(x)) << MTB_DWT_FCT_DATAVMATCH_SHIFT)) & MTB_DWT_FCT_DATAVMATCH_MASK)

#define MTB_DWT_FCT_DATAVSIZE_MASK               (0xC00U)
#define MTB_DWT_FCT_DATAVSIZE_SHIFT              (10U)
/*! DATAVSIZE - Data Value Size
 *  0b00..Byte.
 *  0b01..Halfword.
 *  0b10..Word.
 *  0b11..Reserved. Any attempts to use this value results in UNPREDICTABLE behavior.
 */
#define MTB_DWT_FCT_DATAVSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << MTB_DWT_FCT_DATAVSIZE_SHIFT)) & MTB_DWT_FCT_DATAVSIZE_MASK)

#define MTB_DWT_FCT_DATAVADDR0_MASK              (0xF000U)
#define MTB_DWT_FCT_DATAVADDR0_SHIFT             (12U)
/*! DATAVADDR0 - Data Value Address 0 */
#define MTB_DWT_FCT_DATAVADDR0(x)                (((uint32_t)(((uint32_t)(x)) << MTB_DWT_FCT_DATAVADDR0_SHIFT)) & MTB_DWT_FCT_DATAVADDR0_MASK)

#define MTB_DWT_FCT_MATCHED_MASK                 (0x1000000U)
#define MTB_DWT_FCT_MATCHED_SHIFT                (24U)
/*! MATCHED - Comparator match
 *  0b0..No match.
 *  0b1..Match occurred.
 */
#define MTB_DWT_FCT_MATCHED(x)                   (((uint32_t)(((uint32_t)(x)) << MTB_DWT_FCT_MATCHED_SHIFT)) & MTB_DWT_FCT_MATCHED_MASK)
/*! @} */

/* The count of MTB_DWT_FCT */
#define MTB_DWT_FCT_COUNT                        (2U)

/*! @name TBCTRL - MTB_DWT Trace Buffer Control Register */
/*! @{ */

#define MTB_DWT_TBCTRL_ACOMP0_MASK               (0x1U)
#define MTB_DWT_TBCTRL_ACOMP0_SHIFT              (0U)
/*! ACOMP0 - Action based on Comparator 0 match
 *  0b0..Trigger TSTOP based on the assertion of MTBDWT_FCT0[MATCHED].
 *  0b1..Trigger TSTART based on the assertion of MTBDWT_FCT0[MATCHED].
 */
#define MTB_DWT_TBCTRL_ACOMP0(x)                 (((uint32_t)(((uint32_t)(x)) << MTB_DWT_TBCTRL_ACOMP0_SHIFT)) & MTB_DWT_TBCTRL_ACOMP0_MASK)

#define MTB_DWT_TBCTRL_ACOMP1_MASK               (0x2U)
#define MTB_DWT_TBCTRL_ACOMP1_SHIFT              (1U)
/*! ACOMP1 - Action based on Comparator 1 match
 *  0b0..Trigger TSTOP based on the assertion of MTBDWT_FCT1[MATCHED].
 *  0b1..Trigger TSTART based on the assertion of MTBDWT_FCT1[MATCHED].
 */
#define MTB_DWT_TBCTRL_ACOMP1(x)                 (((uint32_t)(((uint32_t)(x)) << MTB_DWT_TBCTRL_ACOMP1_SHIFT)) & MTB_DWT_TBCTRL_ACOMP1_MASK)

#define MTB_DWT_TBCTRL_NUMCOMP_MASK              (0xF0000000U)
#define MTB_DWT_TBCTRL_NUMCOMP_SHIFT             (28U)
/*! NUMCOMP - Number of Comparators */
#define MTB_DWT_TBCTRL_NUMCOMP(x)                (((uint32_t)(((uint32_t)(x)) << MTB_DWT_TBCTRL_NUMCOMP_SHIFT)) & MTB_DWT_TBCTRL_NUMCOMP_MASK)
/*! @} */

/*! @name DEVICECFG - Device Configuration Register */
/*! @{ */

#define MTB_DWT_DEVICECFG_DEVICECFG_MASK         (0xFFFFFFFFU)
#define MTB_DWT_DEVICECFG_DEVICECFG_SHIFT        (0U)
/*! DEVICECFG - DEVICECFG */
#define MTB_DWT_DEVICECFG_DEVICECFG(x)           (((uint32_t)(((uint32_t)(x)) << MTB_DWT_DEVICECFG_DEVICECFG_SHIFT)) & MTB_DWT_DEVICECFG_DEVICECFG_MASK)
/*! @} */

/*! @name DEVICETYPID - Device Type Identifier Register */
/*! @{ */

#define MTB_DWT_DEVICETYPID_DEVICETYPID_MASK     (0xFFFFFFFFU)
#define MTB_DWT_DEVICETYPID_DEVICETYPID_SHIFT    (0U)
/*! DEVICETYPID - DEVICETYPID */
#define MTB_DWT_DEVICETYPID_DEVICETYPID(x)       (((uint32_t)(((uint32_t)(x)) << MTB_DWT_DEVICETYPID_DEVICETYPID_SHIFT)) & MTB_DWT_DEVICETYPID_DEVICETYPID_MASK)
/*! @} */

/*! @name PERIPHID4 - Peripheral ID Register */
/*! @{ */

#define MTB_DWT_PERIPHID4_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_DWT_PERIPHID4_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_DWT_PERIPHID4_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_DWT_PERIPHID4_PERIPHID_SHIFT)) & MTB_DWT_PERIPHID4_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID5 - Peripheral ID Register */
/*! @{ */

#define MTB_DWT_PERIPHID5_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_DWT_PERIPHID5_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_DWT_PERIPHID5_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_DWT_PERIPHID5_PERIPHID_SHIFT)) & MTB_DWT_PERIPHID5_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID6 - Peripheral ID Register */
/*! @{ */

#define MTB_DWT_PERIPHID6_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_DWT_PERIPHID6_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_DWT_PERIPHID6_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_DWT_PERIPHID6_PERIPHID_SHIFT)) & MTB_DWT_PERIPHID6_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID7 - Peripheral ID Register */
/*! @{ */

#define MTB_DWT_PERIPHID7_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_DWT_PERIPHID7_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_DWT_PERIPHID7_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_DWT_PERIPHID7_PERIPHID_SHIFT)) & MTB_DWT_PERIPHID7_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID0 - Peripheral ID Register */
/*! @{ */

#define MTB_DWT_PERIPHID0_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_DWT_PERIPHID0_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_DWT_PERIPHID0_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_DWT_PERIPHID0_PERIPHID_SHIFT)) & MTB_DWT_PERIPHID0_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID1 - Peripheral ID Register */
/*! @{ */

#define MTB_DWT_PERIPHID1_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_DWT_PERIPHID1_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_DWT_PERIPHID1_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_DWT_PERIPHID1_PERIPHID_SHIFT)) & MTB_DWT_PERIPHID1_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID2 - Peripheral ID Register */
/*! @{ */

#define MTB_DWT_PERIPHID2_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_DWT_PERIPHID2_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_DWT_PERIPHID2_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_DWT_PERIPHID2_PERIPHID_SHIFT)) & MTB_DWT_PERIPHID2_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID3 - Peripheral ID Register */
/*! @{ */

#define MTB_DWT_PERIPHID3_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_DWT_PERIPHID3_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_DWT_PERIPHID3_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_DWT_PERIPHID3_PERIPHID_SHIFT)) & MTB_DWT_PERIPHID3_PERIPHID_MASK)
/*! @} */

/*! @name COMPID - Component ID Register */
/*! @{ */

#define MTB_DWT_COMPID_COMPID_MASK               (0xFFFFFFFFU)
#define MTB_DWT_COMPID_COMPID_SHIFT              (0U)
/*! COMPID - Component ID */
#define MTB_DWT_COMPID_COMPID(x)                 (((uint32_t)(((uint32_t)(x)) << MTB_DWT_COMPID_COMPID_SHIFT)) & MTB_DWT_COMPID_COMPID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MTB_DWT_Register_Masks */


/*!
 * @}
 */ /* end of group MTB_DWT_Peripheral_Access_Layer */


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


#endif  /* PERI_MTB_DWT_H_ */

