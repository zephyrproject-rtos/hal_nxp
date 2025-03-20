/*
** ###################################################################
**     Processors:          MIMXRT1064CVJ5A
**                          MIMXRT1064CVJ5B
**                          MIMXRT1064CVL5A
**                          MIMXRT1064CVL5B
**                          MIMXRT1064DVJ6A
**                          MIMXRT1064DVJ6B
**                          MIMXRT1064DVL6A
**                          MIMXRT1064DVL6B
**
**     Version:             rev. 1.3, 2021-08-10
**     Build:               b240705
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FLEXRAM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2018-06-22)
**         Initial version.
**     - rev. 1.0 (2018-11-16)
**         Update header files to align with IMXRT1064RM Rev.0.
**     - rev. 1.1 (2018-11-27)
**         Update header files to align with IMXRT1064RM Rev.0.1.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1064RM Rev.2.
**
** ###################################################################
*/

/*!
 * @file FLEXRAM.h
 * @version 1.3
 * @date 2021-08-10
 * @brief CMSIS Peripheral Access Layer for FLEXRAM
 *
 * CMSIS Peripheral Access Layer for FLEXRAM
 */

#if !defined(FLEXRAM_H_)
#define FLEXRAM_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1064CVJ5A) || defined(CPU_MIMXRT1064CVJ5B) || defined(CPU_MIMXRT1064CVL5A) || defined(CPU_MIMXRT1064CVL5B) || defined(CPU_MIMXRT1064DVJ6A) || defined(CPU_MIMXRT1064DVJ6B) || defined(CPU_MIMXRT1064DVL6A) || defined(CPU_MIMXRT1064DVL6B))
#include "MIMXRT1064_COMMON.h"
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
   -- FLEXRAM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXRAM_Peripheral_Access_Layer FLEXRAM Peripheral Access Layer
 * @{
 */

/** FLEXRAM - Register Layout Typedef */
typedef struct {
  __IO uint32_t TCM_CTRL;                          /**< TCM CRTL Register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t INT_STATUS;                        /**< Interrupt Status Register, offset: 0x10 */
  __IO uint32_t INT_STAT_EN;                       /**< Interrupt Status Enable Register, offset: 0x14 */
  __IO uint32_t INT_SIG_EN;                        /**< Interrupt Enable Register, offset: 0x18 */
} FLEXRAM_Type;

/* ----------------------------------------------------------------------------
   -- FLEXRAM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXRAM_Register_Masks FLEXRAM Register Masks
 * @{
 */

/*! @name TCM_CTRL - TCM CRTL Register */
/*! @{ */

#define FLEXRAM_TCM_CTRL_TCM_WWAIT_EN_MASK       (0x1U)
#define FLEXRAM_TCM_CTRL_TCM_WWAIT_EN_SHIFT      (0U)
/*! TCM_WWAIT_EN - TCM Write Wait Mode Enable
 *  0b0..TCM write fast mode: Write RAM accesses are expected to be finished in 1-cycle.
 *  0b1..TCM write wait mode: Write RAM accesses are expected to be finished in 2-cycles.
 */
#define FLEXRAM_TCM_CTRL_TCM_WWAIT_EN(x)         (((uint32_t)(((uint32_t)(x)) << FLEXRAM_TCM_CTRL_TCM_WWAIT_EN_SHIFT)) & FLEXRAM_TCM_CTRL_TCM_WWAIT_EN_MASK)

#define FLEXRAM_TCM_CTRL_TCM_RWAIT_EN_MASK       (0x2U)
#define FLEXRAM_TCM_CTRL_TCM_RWAIT_EN_SHIFT      (1U)
/*! TCM_RWAIT_EN - TCM Read Wait Mode Enable
 *  0b0..TCM read fast mode: Read RAM accesses are expected to be finished in 1-cycle.
 *  0b1..TCM read wait mode: Read RAM accesses are expected to be finished in 2-cycles.
 */
#define FLEXRAM_TCM_CTRL_TCM_RWAIT_EN(x)         (((uint32_t)(((uint32_t)(x)) << FLEXRAM_TCM_CTRL_TCM_RWAIT_EN_SHIFT)) & FLEXRAM_TCM_CTRL_TCM_RWAIT_EN_MASK)

#define FLEXRAM_TCM_CTRL_FORCE_CLK_ON_MASK       (0x4U)
#define FLEXRAM_TCM_CTRL_FORCE_CLK_ON_SHIFT      (2U)
/*! FORCE_CLK_ON - Force RAM Clock Always On */
#define FLEXRAM_TCM_CTRL_FORCE_CLK_ON(x)         (((uint32_t)(((uint32_t)(x)) << FLEXRAM_TCM_CTRL_FORCE_CLK_ON_SHIFT)) & FLEXRAM_TCM_CTRL_FORCE_CLK_ON_MASK)

#define FLEXRAM_TCM_CTRL_Reserved_MASK           (0xFFFFFFF8U)
#define FLEXRAM_TCM_CTRL_Reserved_SHIFT          (3U)
/*! Reserved - Reserved */
#define FLEXRAM_TCM_CTRL_Reserved(x)             (((uint32_t)(((uint32_t)(x)) << FLEXRAM_TCM_CTRL_Reserved_SHIFT)) & FLEXRAM_TCM_CTRL_Reserved_MASK)
/*! @} */

/*! @name INT_STATUS - Interrupt Status Register */
/*! @{ */

#define FLEXRAM_INT_STATUS_Reserved0_MASK        (0x1U)
#define FLEXRAM_INT_STATUS_Reserved0_SHIFT       (0U)
/*! Reserved0 - Reserved */
#define FLEXRAM_INT_STATUS_Reserved0(x)          (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STATUS_Reserved0_SHIFT)) & FLEXRAM_INT_STATUS_Reserved0_MASK)

#define FLEXRAM_INT_STATUS_Reserved1_MASK        (0x2U)
#define FLEXRAM_INT_STATUS_Reserved1_SHIFT       (1U)
/*! Reserved1 - Reserved */
#define FLEXRAM_INT_STATUS_Reserved1(x)          (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STATUS_Reserved1_SHIFT)) & FLEXRAM_INT_STATUS_Reserved1_MASK)

#define FLEXRAM_INT_STATUS_Reserved2_MASK        (0x4U)
#define FLEXRAM_INT_STATUS_Reserved2_SHIFT       (2U)
/*! Reserved2 - Reserved */
#define FLEXRAM_INT_STATUS_Reserved2(x)          (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STATUS_Reserved2_SHIFT)) & FLEXRAM_INT_STATUS_Reserved2_MASK)

#define FLEXRAM_INT_STATUS_ITCM_ERR_STATUS_MASK  (0x8U)
#define FLEXRAM_INT_STATUS_ITCM_ERR_STATUS_SHIFT (3U)
/*! ITCM_ERR_STATUS - ITCM Access Error Status
 *  0b0..ITCM access error does not happen
 *  0b1..ITCM access error happens.
 */
#define FLEXRAM_INT_STATUS_ITCM_ERR_STATUS(x)    (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STATUS_ITCM_ERR_STATUS_SHIFT)) & FLEXRAM_INT_STATUS_ITCM_ERR_STATUS_MASK)

#define FLEXRAM_INT_STATUS_DTCM_ERR_STATUS_MASK  (0x10U)
#define FLEXRAM_INT_STATUS_DTCM_ERR_STATUS_SHIFT (4U)
/*! DTCM_ERR_STATUS - DTCM Access Error Status
 *  0b0..DTCM access error does not happen
 *  0b1..DTCM access error happens.
 */
#define FLEXRAM_INT_STATUS_DTCM_ERR_STATUS(x)    (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STATUS_DTCM_ERR_STATUS_SHIFT)) & FLEXRAM_INT_STATUS_DTCM_ERR_STATUS_MASK)

#define FLEXRAM_INT_STATUS_OCRAM_ERR_STATUS_MASK (0x20U)
#define FLEXRAM_INT_STATUS_OCRAM_ERR_STATUS_SHIFT (5U)
/*! OCRAM_ERR_STATUS - OCRAM Access Error Status
 *  0b0..OCRAM access error does not happen
 *  0b1..OCRAM access error happens.
 */
#define FLEXRAM_INT_STATUS_OCRAM_ERR_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STATUS_OCRAM_ERR_STATUS_SHIFT)) & FLEXRAM_INT_STATUS_OCRAM_ERR_STATUS_MASK)

#define FLEXRAM_INT_STATUS_Reserved_MASK         (0xFFFFFFC0U)
#define FLEXRAM_INT_STATUS_Reserved_SHIFT        (6U)
/*! Reserved - Reserved */
#define FLEXRAM_INT_STATUS_Reserved(x)           (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STATUS_Reserved_SHIFT)) & FLEXRAM_INT_STATUS_Reserved_MASK)
/*! @} */

/*! @name INT_STAT_EN - Interrupt Status Enable Register */
/*! @{ */

#define FLEXRAM_INT_STAT_EN_Reserved0_MASK       (0x1U)
#define FLEXRAM_INT_STAT_EN_Reserved0_SHIFT      (0U)
/*! Reserved0 - Reserved */
#define FLEXRAM_INT_STAT_EN_Reserved0(x)         (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STAT_EN_Reserved0_SHIFT)) & FLEXRAM_INT_STAT_EN_Reserved0_MASK)

#define FLEXRAM_INT_STAT_EN_Reserved1_MASK       (0x2U)
#define FLEXRAM_INT_STAT_EN_Reserved1_SHIFT      (1U)
/*! Reserved1 - Reserved */
#define FLEXRAM_INT_STAT_EN_Reserved1(x)         (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STAT_EN_Reserved1_SHIFT)) & FLEXRAM_INT_STAT_EN_Reserved1_MASK)

#define FLEXRAM_INT_STAT_EN_Reserved2_MASK       (0x4U)
#define FLEXRAM_INT_STAT_EN_Reserved2_SHIFT      (2U)
/*! Reserved2 - Reserved */
#define FLEXRAM_INT_STAT_EN_Reserved2(x)         (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STAT_EN_Reserved2_SHIFT)) & FLEXRAM_INT_STAT_EN_Reserved2_MASK)

#define FLEXRAM_INT_STAT_EN_ITCM_ERR_STAT_EN_MASK (0x8U)
#define FLEXRAM_INT_STAT_EN_ITCM_ERR_STAT_EN_SHIFT (3U)
/*! ITCM_ERR_STAT_EN - ITCM Access Error Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define FLEXRAM_INT_STAT_EN_ITCM_ERR_STAT_EN(x)  (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STAT_EN_ITCM_ERR_STAT_EN_SHIFT)) & FLEXRAM_INT_STAT_EN_ITCM_ERR_STAT_EN_MASK)

#define FLEXRAM_INT_STAT_EN_DTCM_ERR_STAT_EN_MASK (0x10U)
#define FLEXRAM_INT_STAT_EN_DTCM_ERR_STAT_EN_SHIFT (4U)
/*! DTCM_ERR_STAT_EN - DTCM Access Error Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define FLEXRAM_INT_STAT_EN_DTCM_ERR_STAT_EN(x)  (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STAT_EN_DTCM_ERR_STAT_EN_SHIFT)) & FLEXRAM_INT_STAT_EN_DTCM_ERR_STAT_EN_MASK)

#define FLEXRAM_INT_STAT_EN_OCRAM_ERR_STAT_EN_MASK (0x20U)
#define FLEXRAM_INT_STAT_EN_OCRAM_ERR_STAT_EN_SHIFT (5U)
/*! OCRAM_ERR_STAT_EN - OCRAM Access Error Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define FLEXRAM_INT_STAT_EN_OCRAM_ERR_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STAT_EN_OCRAM_ERR_STAT_EN_SHIFT)) & FLEXRAM_INT_STAT_EN_OCRAM_ERR_STAT_EN_MASK)

#define FLEXRAM_INT_STAT_EN_Reserved_MASK        (0xFFFFFFC0U)
#define FLEXRAM_INT_STAT_EN_Reserved_SHIFT       (6U)
/*! Reserved - Reserved */
#define FLEXRAM_INT_STAT_EN_Reserved(x)          (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STAT_EN_Reserved_SHIFT)) & FLEXRAM_INT_STAT_EN_Reserved_MASK)
/*! @} */

/*! @name INT_SIG_EN - Interrupt Enable Register */
/*! @{ */

#define FLEXRAM_INT_SIG_EN_Reserved0_MASK        (0x1U)
#define FLEXRAM_INT_SIG_EN_Reserved0_SHIFT       (0U)
/*! Reserved0 - Reserved */
#define FLEXRAM_INT_SIG_EN_Reserved0(x)          (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_SIG_EN_Reserved0_SHIFT)) & FLEXRAM_INT_SIG_EN_Reserved0_MASK)

#define FLEXRAM_INT_SIG_EN_Reserved1_MASK        (0x2U)
#define FLEXRAM_INT_SIG_EN_Reserved1_SHIFT       (1U)
/*! Reserved1 - Reserved */
#define FLEXRAM_INT_SIG_EN_Reserved1(x)          (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_SIG_EN_Reserved1_SHIFT)) & FLEXRAM_INT_SIG_EN_Reserved1_MASK)

#define FLEXRAM_INT_SIG_EN_Reserved2_MASK        (0x4U)
#define FLEXRAM_INT_SIG_EN_Reserved2_SHIFT       (2U)
/*! Reserved2 - Reserved */
#define FLEXRAM_INT_SIG_EN_Reserved2(x)          (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_SIG_EN_Reserved2_SHIFT)) & FLEXRAM_INT_SIG_EN_Reserved2_MASK)

#define FLEXRAM_INT_SIG_EN_ITCM_ERR_SIG_EN_MASK  (0x8U)
#define FLEXRAM_INT_SIG_EN_ITCM_ERR_SIG_EN_SHIFT (3U)
/*! ITCM_ERR_SIG_EN - ITCM Access Error Interrupt Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define FLEXRAM_INT_SIG_EN_ITCM_ERR_SIG_EN(x)    (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_SIG_EN_ITCM_ERR_SIG_EN_SHIFT)) & FLEXRAM_INT_SIG_EN_ITCM_ERR_SIG_EN_MASK)

#define FLEXRAM_INT_SIG_EN_DTCM_ERR_SIG_EN_MASK  (0x10U)
#define FLEXRAM_INT_SIG_EN_DTCM_ERR_SIG_EN_SHIFT (4U)
/*! DTCM_ERR_SIG_EN - DTCM Access Error Interrupt Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define FLEXRAM_INT_SIG_EN_DTCM_ERR_SIG_EN(x)    (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_SIG_EN_DTCM_ERR_SIG_EN_SHIFT)) & FLEXRAM_INT_SIG_EN_DTCM_ERR_SIG_EN_MASK)

#define FLEXRAM_INT_SIG_EN_OCRAM_ERR_SIG_EN_MASK (0x20U)
#define FLEXRAM_INT_SIG_EN_OCRAM_ERR_SIG_EN_SHIFT (5U)
/*! OCRAM_ERR_SIG_EN - OCRAM Access Error Interrupt Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define FLEXRAM_INT_SIG_EN_OCRAM_ERR_SIG_EN(x)   (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_SIG_EN_OCRAM_ERR_SIG_EN_SHIFT)) & FLEXRAM_INT_SIG_EN_OCRAM_ERR_SIG_EN_MASK)

#define FLEXRAM_INT_SIG_EN_Reserved_MASK         (0xFFFFFFC0U)
#define FLEXRAM_INT_SIG_EN_Reserved_SHIFT        (6U)
/*! Reserved - Reserved */
#define FLEXRAM_INT_SIG_EN_Reserved(x)           (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_SIG_EN_Reserved_SHIFT)) & FLEXRAM_INT_SIG_EN_Reserved_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FLEXRAM_Register_Masks */


/*!
 * @}
 */ /* end of group FLEXRAM_Peripheral_Access_Layer */


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


#endif  /* FLEXRAM_H_ */

