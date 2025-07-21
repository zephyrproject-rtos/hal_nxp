/*
** ###################################################################
**     Processors:          MIMXRT1011CAE4A
**                          MIMXRT1011DAE5A
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FLEXRAM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2019-02-14)
**         Initial version.
**     - rev. 1.0 (2019-08-01)
**         Rev.0 Header GA
**     - rev. 1.1 (2019-08-06)
**         Update header files to align with IMXRT1010RM Rev.B.
**     - rev. 1.2 (2021-08-10)
**         Update header files to align with IMXRT1010RM Rev.1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FLEXRAM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FLEXRAM
 *
 * CMSIS Peripheral Access Layer for FLEXRAM
 */

#if !defined(PERI_FLEXRAM_H_)
#define PERI_FLEXRAM_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1011CAE4A) || defined(CPU_MIMXRT1011DAE5A))
#include "MIMXRT1011_COMMON.h"
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
  __IO uint32_t OCRAM_MAGIC_ADDR;                  /**< OCRAM Magic Address Register, offset: 0x4 */
  __IO uint32_t DTCM_MAGIC_ADDR;                   /**< DTCM Magic Address Register, offset: 0x8 */
  __IO uint32_t ITCM_MAGIC_ADDR;                   /**< ITCM Magic Address Register, offset: 0xC */
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

/*! @name OCRAM_MAGIC_ADDR - OCRAM Magic Address Register */
/*! @{ */

#define FLEXRAM_OCRAM_MAGIC_ADDR_OCRAM_WR_RD_SEL_MASK (0x1U)
#define FLEXRAM_OCRAM_MAGIC_ADDR_OCRAM_WR_RD_SEL_SHIFT (0U)
/*! OCRAM_WR_RD_SEL - OCRAM Write Read Select
 *  0b0..When OCRAM read access hits magic address, it will generate interrupt.
 *  0b1..When OCRAM write access hits magic address, it will generate interrupt.
 */
#define FLEXRAM_OCRAM_MAGIC_ADDR_OCRAM_WR_RD_SEL(x) (((uint32_t)(((uint32_t)(x)) << FLEXRAM_OCRAM_MAGIC_ADDR_OCRAM_WR_RD_SEL_SHIFT)) & FLEXRAM_OCRAM_MAGIC_ADDR_OCRAM_WR_RD_SEL_MASK)

#define FLEXRAM_OCRAM_MAGIC_ADDR_OCRAM_MAGIC_ADDR_MASK (0x1FFFEU)
#define FLEXRAM_OCRAM_MAGIC_ADDR_OCRAM_MAGIC_ADDR_SHIFT (1U)
/*! OCRAM_MAGIC_ADDR - OCRAM Magic Address */
#define FLEXRAM_OCRAM_MAGIC_ADDR_OCRAM_MAGIC_ADDR(x) (((uint32_t)(((uint32_t)(x)) << FLEXRAM_OCRAM_MAGIC_ADDR_OCRAM_MAGIC_ADDR_SHIFT)) & FLEXRAM_OCRAM_MAGIC_ADDR_OCRAM_MAGIC_ADDR_MASK)

#define FLEXRAM_OCRAM_MAGIC_ADDR_Reserved_MASK   (0xFFFE0000U)
#define FLEXRAM_OCRAM_MAGIC_ADDR_Reserved_SHIFT  (17U)
/*! Reserved - Reserved */
#define FLEXRAM_OCRAM_MAGIC_ADDR_Reserved(x)     (((uint32_t)(((uint32_t)(x)) << FLEXRAM_OCRAM_MAGIC_ADDR_Reserved_SHIFT)) & FLEXRAM_OCRAM_MAGIC_ADDR_Reserved_MASK)
/*! @} */

/*! @name DTCM_MAGIC_ADDR - DTCM Magic Address Register */
/*! @{ */

#define FLEXRAM_DTCM_MAGIC_ADDR_DTCM_WR_RD_SEL_MASK (0x1U)
#define FLEXRAM_DTCM_MAGIC_ADDR_DTCM_WR_RD_SEL_SHIFT (0U)
/*! DTCM_WR_RD_SEL - DTCM Write Read Select
 *  0b0..When DTCM read access hits magic address, it will generate interrupt.
 *  0b1..When DTCM write access hits magic address, it will generate interrupt.
 */
#define FLEXRAM_DTCM_MAGIC_ADDR_DTCM_WR_RD_SEL(x) (((uint32_t)(((uint32_t)(x)) << FLEXRAM_DTCM_MAGIC_ADDR_DTCM_WR_RD_SEL_SHIFT)) & FLEXRAM_DTCM_MAGIC_ADDR_DTCM_WR_RD_SEL_MASK)

#define FLEXRAM_DTCM_MAGIC_ADDR_DTCM_MAGIC_ADDR_MASK (0x1FFFEU)
#define FLEXRAM_DTCM_MAGIC_ADDR_DTCM_MAGIC_ADDR_SHIFT (1U)
/*! DTCM_MAGIC_ADDR - DTCM Magic Address */
#define FLEXRAM_DTCM_MAGIC_ADDR_DTCM_MAGIC_ADDR(x) (((uint32_t)(((uint32_t)(x)) << FLEXRAM_DTCM_MAGIC_ADDR_DTCM_MAGIC_ADDR_SHIFT)) & FLEXRAM_DTCM_MAGIC_ADDR_DTCM_MAGIC_ADDR_MASK)

#define FLEXRAM_DTCM_MAGIC_ADDR_Reserved_MASK    (0xFFFE0000U)
#define FLEXRAM_DTCM_MAGIC_ADDR_Reserved_SHIFT   (17U)
/*! Reserved - Reserved */
#define FLEXRAM_DTCM_MAGIC_ADDR_Reserved(x)      (((uint32_t)(((uint32_t)(x)) << FLEXRAM_DTCM_MAGIC_ADDR_Reserved_SHIFT)) & FLEXRAM_DTCM_MAGIC_ADDR_Reserved_MASK)
/*! @} */

/*! @name ITCM_MAGIC_ADDR - ITCM Magic Address Register */
/*! @{ */

#define FLEXRAM_ITCM_MAGIC_ADDR_ITCM_WR_RD_SEL_MASK (0x1U)
#define FLEXRAM_ITCM_MAGIC_ADDR_ITCM_WR_RD_SEL_SHIFT (0U)
/*! ITCM_WR_RD_SEL - ITCM Write Read Select
 *  0b0..When ITCM read access hits magic address, it will generate interrupt.
 *  0b1..When ITCM write access hits magic address, it will generate interrupt.
 */
#define FLEXRAM_ITCM_MAGIC_ADDR_ITCM_WR_RD_SEL(x) (((uint32_t)(((uint32_t)(x)) << FLEXRAM_ITCM_MAGIC_ADDR_ITCM_WR_RD_SEL_SHIFT)) & FLEXRAM_ITCM_MAGIC_ADDR_ITCM_WR_RD_SEL_MASK)

#define FLEXRAM_ITCM_MAGIC_ADDR_ITCM_MAGIC_ADDR_MASK (0x1FFFEU)
#define FLEXRAM_ITCM_MAGIC_ADDR_ITCM_MAGIC_ADDR_SHIFT (1U)
/*! ITCM_MAGIC_ADDR - ITCM Magic Address */
#define FLEXRAM_ITCM_MAGIC_ADDR_ITCM_MAGIC_ADDR(x) (((uint32_t)(((uint32_t)(x)) << FLEXRAM_ITCM_MAGIC_ADDR_ITCM_MAGIC_ADDR_SHIFT)) & FLEXRAM_ITCM_MAGIC_ADDR_ITCM_MAGIC_ADDR_MASK)

#define FLEXRAM_ITCM_MAGIC_ADDR_Reserved_MASK    (0xFFFE0000U)
#define FLEXRAM_ITCM_MAGIC_ADDR_Reserved_SHIFT   (17U)
/*! Reserved - Reserved */
#define FLEXRAM_ITCM_MAGIC_ADDR_Reserved(x)      (((uint32_t)(((uint32_t)(x)) << FLEXRAM_ITCM_MAGIC_ADDR_Reserved_SHIFT)) & FLEXRAM_ITCM_MAGIC_ADDR_Reserved_MASK)
/*! @} */

/*! @name INT_STATUS - Interrupt Status Register */
/*! @{ */

#define FLEXRAM_INT_STATUS_ITCM_MAM_STATUS_MASK  (0x1U)
#define FLEXRAM_INT_STATUS_ITCM_MAM_STATUS_SHIFT (0U)
/*! ITCM_MAM_STATUS - ITCM Magic Address Match Status
 *  0b0..ITCM did not access magic address.
 *  0b1..ITCM accessed magic address.
 */
#define FLEXRAM_INT_STATUS_ITCM_MAM_STATUS(x)    (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STATUS_ITCM_MAM_STATUS_SHIFT)) & FLEXRAM_INT_STATUS_ITCM_MAM_STATUS_MASK)

#define FLEXRAM_INT_STATUS_DTCM_MAM_STATUS_MASK  (0x2U)
#define FLEXRAM_INT_STATUS_DTCM_MAM_STATUS_SHIFT (1U)
/*! DTCM_MAM_STATUS - DTCM Magic Address Match Status
 *  0b0..DTCM did not access magic address.
 *  0b1..DTCM accessed magic address.
 */
#define FLEXRAM_INT_STATUS_DTCM_MAM_STATUS(x)    (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STATUS_DTCM_MAM_STATUS_SHIFT)) & FLEXRAM_INT_STATUS_DTCM_MAM_STATUS_MASK)

#define FLEXRAM_INT_STATUS_OCRAM_MAM_STATUS_MASK (0x4U)
#define FLEXRAM_INT_STATUS_OCRAM_MAM_STATUS_SHIFT (2U)
/*! OCRAM_MAM_STATUS - OCRAM Magic Address Match Status
 *  0b0..OCRAM did not access magic address.
 *  0b1..OCRAM accessed magic address.
 */
#define FLEXRAM_INT_STATUS_OCRAM_MAM_STATUS(x)   (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STATUS_OCRAM_MAM_STATUS_SHIFT)) & FLEXRAM_INT_STATUS_OCRAM_MAM_STATUS_MASK)

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

#define FLEXRAM_INT_STAT_EN_ITCM_MAM_STAT_EN_MASK (0x1U)
#define FLEXRAM_INT_STAT_EN_ITCM_MAM_STAT_EN_SHIFT (0U)
/*! ITCM_MAM_STAT_EN - ITCM Magic Address Match Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define FLEXRAM_INT_STAT_EN_ITCM_MAM_STAT_EN(x)  (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STAT_EN_ITCM_MAM_STAT_EN_SHIFT)) & FLEXRAM_INT_STAT_EN_ITCM_MAM_STAT_EN_MASK)

#define FLEXRAM_INT_STAT_EN_DTCM_MAM_STAT_EN_MASK (0x2U)
#define FLEXRAM_INT_STAT_EN_DTCM_MAM_STAT_EN_SHIFT (1U)
/*! DTCM_MAM_STAT_EN - DTCM Magic Address Match Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define FLEXRAM_INT_STAT_EN_DTCM_MAM_STAT_EN(x)  (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STAT_EN_DTCM_MAM_STAT_EN_SHIFT)) & FLEXRAM_INT_STAT_EN_DTCM_MAM_STAT_EN_MASK)

#define FLEXRAM_INT_STAT_EN_OCRAM_MAM_STAT_EN_MASK (0x4U)
#define FLEXRAM_INT_STAT_EN_OCRAM_MAM_STAT_EN_SHIFT (2U)
/*! OCRAM_MAM_STAT_EN - OCRAM Magic Address Match Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define FLEXRAM_INT_STAT_EN_OCRAM_MAM_STAT_EN(x) (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_STAT_EN_OCRAM_MAM_STAT_EN_SHIFT)) & FLEXRAM_INT_STAT_EN_OCRAM_MAM_STAT_EN_MASK)

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

#define FLEXRAM_INT_SIG_EN_ITCM_MAM_SIG_EN_MASK  (0x1U)
#define FLEXRAM_INT_SIG_EN_ITCM_MAM_SIG_EN_SHIFT (0U)
/*! ITCM_MAM_SIG_EN - ITCM Magic Address Match Interrupt Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define FLEXRAM_INT_SIG_EN_ITCM_MAM_SIG_EN(x)    (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_SIG_EN_ITCM_MAM_SIG_EN_SHIFT)) & FLEXRAM_INT_SIG_EN_ITCM_MAM_SIG_EN_MASK)

#define FLEXRAM_INT_SIG_EN_DTCM_MAM_SIG_EN_MASK  (0x2U)
#define FLEXRAM_INT_SIG_EN_DTCM_MAM_SIG_EN_SHIFT (1U)
/*! DTCM_MAM_SIG_EN - DTCM Magic Address Match Interrupt Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define FLEXRAM_INT_SIG_EN_DTCM_MAM_SIG_EN(x)    (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_SIG_EN_DTCM_MAM_SIG_EN_SHIFT)) & FLEXRAM_INT_SIG_EN_DTCM_MAM_SIG_EN_MASK)

#define FLEXRAM_INT_SIG_EN_OCRAM_MAM_SIG_EN_MASK (0x4U)
#define FLEXRAM_INT_SIG_EN_OCRAM_MAM_SIG_EN_SHIFT (2U)
/*! OCRAM_MAM_SIG_EN - OCRAM Magic Address Match Interrupt Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define FLEXRAM_INT_SIG_EN_OCRAM_MAM_SIG_EN(x)   (((uint32_t)(((uint32_t)(x)) << FLEXRAM_INT_SIG_EN_OCRAM_MAM_SIG_EN_SHIFT)) & FLEXRAM_INT_SIG_EN_OCRAM_MAM_SIG_EN_MASK)

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


#endif  /* PERI_FLEXRAM_H_ */

