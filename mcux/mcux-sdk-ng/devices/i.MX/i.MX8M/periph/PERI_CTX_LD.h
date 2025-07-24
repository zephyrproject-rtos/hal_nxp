/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CTX_LD
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CTX_LD.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CTX_LD
 *
 * CMSIS Peripheral Access Layer for CTX_LD
 */

#if !defined(PERI_CTX_LD_H_)
#define PERI_CTX_LD_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- CTX_LD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CTX_LD_Peripheral_Access_Layer CTX_LD Peripheral Access Layer
 * @{
 */

/** CTX_LD - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< Control status register for Context Loader., offset: 0x0 */
    __IO uint32_t SET;                               /**< Control status register for Context Loader., offset: 0x4 */
    __IO uint32_t CLR;                               /**< Control status register for Context Loader., offset: 0x8 */
    __IO uint32_t TOG;                               /**< Control status register for Context Loader., offset: 0xC */
  } CTRL_STATUS;
  __IO uint32_t DB_BASE_ADDR;                      /**< DRAM addr for double buffered register fetch., offset: 0x10 */
  __IO uint32_t DB_COUNT;                          /**< Double buffer register count, offset: 0x14 */
  __IO uint32_t SB_BASE_ADDR;                      /**< DRAM addr for single buffered registers., offset: 0x18 */
  __IO uint32_t SB_COUNT;                          /**< Single buffer register count, offset: 0x1C */
  __I  uint32_t AHB_ERR_ADDR;                      /**< AHB address with error response., offset: 0x20 */
} CTX_LD_Type;

/* ----------------------------------------------------------------------------
   -- CTX_LD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CTX_LD_Register_Masks CTX_LD Register Masks
 * @{
 */

/*! @name CTRL_STATUS - Control status register for Context Loader. */
/*! @{ */

#define CTX_LD_CTRL_STATUS_ENABLE_MASK           (0x1U)
#define CTX_LD_CTRL_STATUS_ENABLE_SHIFT          (0U)
/*! ENABLE - Enable/Busy */
#define CTX_LD_CTRL_STATUS_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_ENABLE_SHIFT)) & CTX_LD_CTRL_STATUS_ENABLE_MASK)

#define CTX_LD_CTRL_STATUS_ARB_SEL_MASK          (0x2U)
#define CTX_LD_CTRL_STATUS_ARB_SEL_SHIFT         (1U)
/*! ARB_SEL - Arbitration select */
#define CTX_LD_CTRL_STATUS_ARB_SEL(x)            (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_ARB_SEL_SHIFT)) & CTX_LD_CTRL_STATUS_ARB_SEL_MASK)

#define CTX_LD_CTRL_STATUS_RD_ERR_EN_MASK        (0x4U)
#define CTX_LD_CTRL_STATUS_RD_ERR_EN_SHIFT       (2U)
/*! RD_ERR_EN - AXI read error IRQ enable */
#define CTX_LD_CTRL_STATUS_RD_ERR_EN(x)          (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_RD_ERR_EN_SHIFT)) & CTX_LD_CTRL_STATUS_RD_ERR_EN_MASK)

#define CTX_LD_CTRL_STATUS_DB_COMP_EN_MASK       (0x8U)
#define CTX_LD_CTRL_STATUS_DB_COMP_EN_SHIFT      (3U)
/*! DB_COMP_EN - Double buffer region loading complete IRQ enable */
#define CTX_LD_CTRL_STATUS_DB_COMP_EN(x)         (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_DB_COMP_EN_SHIFT)) & CTX_LD_CTRL_STATUS_DB_COMP_EN_MASK)

#define CTX_LD_CTRL_STATUS_SB_HP_COMP_EN_MASK    (0x10U)
#define CTX_LD_CTRL_STATUS_SB_HP_COMP_EN_SHIFT   (4U)
/*! SB_HP_COMP_EN - Single buffer high priority region loading complete IRQ enable */
#define CTX_LD_CTRL_STATUS_SB_HP_COMP_EN(x)      (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_SB_HP_COMP_EN_SHIFT)) & CTX_LD_CTRL_STATUS_SB_HP_COMP_EN_MASK)

#define CTX_LD_CTRL_STATUS_SB_LP_COMP_EN_MASK    (0x20U)
#define CTX_LD_CTRL_STATUS_SB_LP_COMP_EN_SHIFT   (5U)
/*! SB_LP_COMP_EN - Single buffer low priority region loading complete IRQ enable */
#define CTX_LD_CTRL_STATUS_SB_LP_COMP_EN(x)      (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_SB_LP_COMP_EN_SHIFT)) & CTX_LD_CTRL_STATUS_SB_LP_COMP_EN_MASK)

#define CTX_LD_CTRL_STATUS_DB_PEND_SB_REC_EN_MASK (0x40U)
#define CTX_LD_CTRL_STATUS_DB_PEND_SB_REC_EN_SHIFT (6U)
/*! DB_PEND_SB_REC_EN - Double/single region overlap interrupt enable */
#define CTX_LD_CTRL_STATUS_DB_PEND_SB_REC_EN(x)  (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_DB_PEND_SB_REC_EN_SHIFT)) & CTX_LD_CTRL_STATUS_DB_PEND_SB_REC_EN_MASK)

#define CTX_LD_CTRL_STATUS_SB_PEND_DISP_ACTIVE_EN_MASK (0x80U)
#define CTX_LD_CTRL_STATUS_SB_PEND_DISP_ACTIVE_EN_SHIFT (7U)
/*! SB_PEND_DISP_ACTIVE_EN - Single/active region overlap interrupt enable. */
#define CTX_LD_CTRL_STATUS_SB_PEND_DISP_ACTIVE_EN(x) (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_SB_PEND_DISP_ACTIVE_EN_SHIFT)) & CTX_LD_CTRL_STATUS_SB_PEND_DISP_ACTIVE_EN_MASK)

#define CTX_LD_CTRL_STATUS_AHB_ERR_EN_MASK       (0x100U)
#define CTX_LD_CTRL_STATUS_AHB_ERR_EN_SHIFT      (8U)
/*! AHB_ERR_EN - AHB error IRQ enable */
#define CTX_LD_CTRL_STATUS_AHB_ERR_EN(x)         (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_AHB_ERR_EN_SHIFT)) & CTX_LD_CTRL_STATUS_AHB_ERR_EN_MASK)

#define CTX_LD_CTRL_STATUS_RD_ERR_MASK           (0x10000U)
#define CTX_LD_CTRL_STATUS_RD_ERR_SHIFT          (16U)
/*! RD_ERR - AXI read error */
#define CTX_LD_CTRL_STATUS_RD_ERR(x)             (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_RD_ERR_SHIFT)) & CTX_LD_CTRL_STATUS_RD_ERR_MASK)

#define CTX_LD_CTRL_STATUS_DB_COMP_MASK          (0x20000U)
#define CTX_LD_CTRL_STATUS_DB_COMP_SHIFT         (17U)
/*! DB_COMP - Double buffer region loading complete */
#define CTX_LD_CTRL_STATUS_DB_COMP(x)            (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_DB_COMP_SHIFT)) & CTX_LD_CTRL_STATUS_DB_COMP_MASK)

#define CTX_LD_CTRL_STATUS_SB_HP_COMP_MASK       (0x40000U)
#define CTX_LD_CTRL_STATUS_SB_HP_COMP_SHIFT      (18U)
/*! SB_HP_COMP - Single buffer high priority region loading complete */
#define CTX_LD_CTRL_STATUS_SB_HP_COMP(x)         (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_SB_HP_COMP_SHIFT)) & CTX_LD_CTRL_STATUS_SB_HP_COMP_MASK)

#define CTX_LD_CTRL_STATUS_SB_LP_COMP_MASK       (0x80000U)
#define CTX_LD_CTRL_STATUS_SB_LP_COMP_SHIFT      (19U)
/*! SB_LP_COMP - Single buffer low priority region loading complete IRQ enable */
#define CTX_LD_CTRL_STATUS_SB_LP_COMP(x)         (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_SB_LP_COMP_SHIFT)) & CTX_LD_CTRL_STATUS_SB_LP_COMP_MASK)

#define CTX_LD_CTRL_STATUS_DB_PEND_SB_REC_MASK   (0x100000U)
#define CTX_LD_CTRL_STATUS_DB_PEND_SB_REC_SHIFT  (20U)
/*! DB_PEND_SB_REC - Double/single region overlap */
#define CTX_LD_CTRL_STATUS_DB_PEND_SB_REC(x)     (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_DB_PEND_SB_REC_SHIFT)) & CTX_LD_CTRL_STATUS_DB_PEND_SB_REC_MASK)

#define CTX_LD_CTRL_STATUS_SB_PEND_DISP_ACTIVE_MASK (0x200000U)
#define CTX_LD_CTRL_STATUS_SB_PEND_DISP_ACTIVE_SHIFT (21U)
/*! SB_PEND_DISP_ACTIVE - Single/active region overlap */
#define CTX_LD_CTRL_STATUS_SB_PEND_DISP_ACTIVE(x) (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_SB_PEND_DISP_ACTIVE_SHIFT)) & CTX_LD_CTRL_STATUS_SB_PEND_DISP_ACTIVE_MASK)

#define CTX_LD_CTRL_STATUS_AHB_ERR_MASK          (0x400000U)
#define CTX_LD_CTRL_STATUS_AHB_ERR_SHIFT         (22U)
/*! AHB_ERR - AHB error */
#define CTX_LD_CTRL_STATUS_AHB_ERR(x)            (((uint32_t)(((uint32_t)(x)) << CTX_LD_CTRL_STATUS_AHB_ERR_SHIFT)) & CTX_LD_CTRL_STATUS_AHB_ERR_MASK)
/*! @} */

/*! @name DB_BASE_ADDR - DRAM addr for double buffered register fetch. */
/*! @{ */

#define CTX_LD_DB_BASE_ADDR_DB_BASE_ADDR_MASK    (0xFFFFFFFFU)
#define CTX_LD_DB_BASE_ADDR_DB_BASE_ADDR_SHIFT   (0U)
/*! DB_BASE_ADDR - Double buffered registers base address. */
#define CTX_LD_DB_BASE_ADDR_DB_BASE_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << CTX_LD_DB_BASE_ADDR_DB_BASE_ADDR_SHIFT)) & CTX_LD_DB_BASE_ADDR_DB_BASE_ADDR_MASK)
/*! @} */

/*! @name DB_COUNT - Double buffer register count */
/*! @{ */

#define CTX_LD_DB_COUNT_DB_COUNT_MASK            (0xFFFFU)
#define CTX_LD_DB_COUNT_DB_COUNT_SHIFT           (0U)
/*! DB_COUNT - Double buffered region fetch count */
#define CTX_LD_DB_COUNT_DB_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << CTX_LD_DB_COUNT_DB_COUNT_SHIFT)) & CTX_LD_DB_COUNT_DB_COUNT_MASK)
/*! @} */

/*! @name SB_BASE_ADDR - DRAM addr for single buffered registers. */
/*! @{ */

#define CTX_LD_SB_BASE_ADDR_SB_BASE_ADDR_MASK    (0xFFFFFFFFU)
#define CTX_LD_SB_BASE_ADDR_SB_BASE_ADDR_SHIFT   (0U)
/*! SB_BASE_ADDR - Single buffered register base address. */
#define CTX_LD_SB_BASE_ADDR_SB_BASE_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << CTX_LD_SB_BASE_ADDR_SB_BASE_ADDR_SHIFT)) & CTX_LD_SB_BASE_ADDR_SB_BASE_ADDR_MASK)
/*! @} */

/*! @name SB_COUNT - Single buffer register count */
/*! @{ */

#define CTX_LD_SB_COUNT_HP_COUNT_MASK            (0xFFFFU)
#define CTX_LD_SB_COUNT_HP_COUNT_SHIFT           (0U)
/*! HP_COUNT - Single buffered high priority region fetch count */
#define CTX_LD_SB_COUNT_HP_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << CTX_LD_SB_COUNT_HP_COUNT_SHIFT)) & CTX_LD_SB_COUNT_HP_COUNT_MASK)

#define CTX_LD_SB_COUNT_LP_COUNT_MASK            (0xFFFF0000U)
#define CTX_LD_SB_COUNT_LP_COUNT_SHIFT           (16U)
/*! LP_COUNT - Single buffered low priority region fetch count */
#define CTX_LD_SB_COUNT_LP_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << CTX_LD_SB_COUNT_LP_COUNT_SHIFT)) & CTX_LD_SB_COUNT_LP_COUNT_MASK)
/*! @} */

/*! @name AHB_ERR_ADDR - AHB address with error response. */
/*! @{ */

#define CTX_LD_AHB_ERR_ADDR_AHB_ERR_ADDR_MASK    (0xFFFFFFFFU)
#define CTX_LD_AHB_ERR_ADDR_AHB_ERR_ADDR_SHIFT   (0U)
/*! AHB_ERR_ADDR - AHB error address. */
#define CTX_LD_AHB_ERR_ADDR_AHB_ERR_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << CTX_LD_AHB_ERR_ADDR_AHB_ERR_ADDR_SHIFT)) & CTX_LD_AHB_ERR_ADDR_AHB_ERR_ADDR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CTX_LD_Register_Masks */


/*!
 * @}
 */ /* end of group CTX_LD_Peripheral_Access_Layer */


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


#endif  /* PERI_CTX_LD_H_ */

