/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AHB_SRAMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_AHB_SRAMC.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for AHB_SRAMC
 *
 * CMSIS Peripheral Access Layer for AHB_SRAMC
 */

#if !defined(PERI_AHB_SRAMC_H_)
#define PERI_AHB_SRAMC_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- AHB_SRAMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHB_SRAMC_Peripheral_Access_Layer AHB_SRAMC Peripheral Access Layer
 * @{
 */

/** AHB_SRAMC - Size of Registers Arrays */
#define AHB_SRAMC_CFG0_CS_COUNT                   2u

/** AHB_SRAMC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __IO uint32_t MCR;                               /**< Module Control Register, offset: 0x4 */
  __IO uint32_t LR;                                /**< Lock Register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  struct {                                         /* offset: 0x10, array step: 0x8 */
    __IO uint32_t CFG0_CS;                           /**< Configure Register 0, array offset: 0x10, array step: 0x8 */
    __IO uint32_t CFG1_CS;                           /**< Configure Register 1, array offset: 0x14, array step: 0x8 */
  } CFG0_CS[AHB_SRAMC_CFG0_CS_COUNT];
} AHB_SRAMC_Type;

/* ----------------------------------------------------------------------------
   -- AHB_SRAMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHB_SRAMC_Register_Masks AHB_SRAMC Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define AHB_SRAMC_VERID_FEATURE_MASK             (0xFFFFU)
#define AHB_SRAMC_VERID_FEATURE_SHIFT            (0U)
/*! FEATURE - Feature Specification Number */
#define AHB_SRAMC_VERID_FEATURE(x)               (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_VERID_FEATURE_SHIFT)) & AHB_SRAMC_VERID_FEATURE_MASK)

#define AHB_SRAMC_VERID_MINOR_MASK               (0xFF0000U)
#define AHB_SRAMC_VERID_MINOR_SHIFT              (16U)
/*! MINOR - Minor Version Number */
#define AHB_SRAMC_VERID_MINOR(x)                 (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_VERID_MINOR_SHIFT)) & AHB_SRAMC_VERID_MINOR_MASK)

#define AHB_SRAMC_VERID_MAJOR_MASK               (0xFF000000U)
#define AHB_SRAMC_VERID_MAJOR_SHIFT              (24U)
/*! MAJOR - Major Version Number */
#define AHB_SRAMC_VERID_MAJOR(x)                 (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_VERID_MAJOR_SHIFT)) & AHB_SRAMC_VERID_MAJOR_MASK)
/*! @} */

/*! @name MCR - Module Control Register */
/*! @{ */

#define AHB_SRAMC_MCR_PS_MASK                    (0x1U)
#define AHB_SRAMC_MCR_PS_SHIFT                   (0U)
/*! PS - Port Size
 *  0b0..8bit
 *  0b1..16bit
 */
#define AHB_SRAMC_MCR_PS(x)                      (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_MCR_PS_SHIFT)) & AHB_SRAMC_MCR_PS_MASK)

#define AHB_SRAMC_MCR_AM_MASK                    (0x2U)
#define AHB_SRAMC_MCR_AM_SHIFT                   (1U)
/*! AM - Address Mode
 *  0b0..Address/Data MUX mode (ADMUX)
 *  0b1..Address/Data non-MUX mode (Non-ADMUX)
 */
#define AHB_SRAMC_MCR_AM(x)                      (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_MCR_AM_SHIFT)) & AHB_SRAMC_MCR_AM_MASK)

#define AHB_SRAMC_MCR_ADVP_MASK                  (0x4U)
#define AHB_SRAMC_MCR_ADVP_SHIFT                 (2U)
/*! ADVP - ADV# polarity
 *  0b0..ADV# is active low.
 *  0b1..ADV# is active high.
 */
#define AHB_SRAMC_MCR_ADVP(x)                    (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_MCR_ADVP_SHIFT)) & AHB_SRAMC_MCR_ADVP_MASK)

#define AHB_SRAMC_MCR_BTOEN_MASK                 (0x8000U)
#define AHB_SRAMC_MCR_BTOEN_SHIFT                (15U)
/*! BTOEN - AHB Bus Timeout Enable
 *  0b0..AHB bus timeout counter is not enabled.
 *  0b1..AHB bus timeout counter is enabled.
 */
#define AHB_SRAMC_MCR_BTOEN(x)                   (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_MCR_BTOEN_SHIFT)) & AHB_SRAMC_MCR_BTOEN_MASK)

#define AHB_SRAMC_MCR_BTO_MASK                   (0xFF0000U)
#define AHB_SRAMC_MCR_BTO_SHIFT                  (16U)
/*! BTO - AHB Bus Timeout Wait Cycle */
#define AHB_SRAMC_MCR_BTO(x)                     (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_MCR_BTO_SHIFT)) & AHB_SRAMC_MCR_BTO_MASK)

#define AHB_SRAMC_MCR_CG_DIS_MASK                (0x40000000U)
#define AHB_SRAMC_MCR_CG_DIS_SHIFT               (30U)
/*! CG_DIS - Clock Gating Disable
 *  0b0..Internal clock gating is enabled, that means the function clock is off when no access.
 *  0b1..Internal clock gating is disabled, that means the function clock is always on.
 */
#define AHB_SRAMC_MCR_CG_DIS(x)                  (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_MCR_CG_DIS_SHIFT)) & AHB_SRAMC_MCR_CG_DIS_MASK)

#define AHB_SRAMC_MCR_SW_RST_MASK                (0x80000000U)
#define AHB_SRAMC_MCR_SW_RST_SHIFT               (31U)
/*! SW_RST - Software Reset
 *  0b0..No reset.
 *  0b1..Assert reset.
 */
#define AHB_SRAMC_MCR_SW_RST(x)                  (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_MCR_SW_RST_SHIFT)) & AHB_SRAMC_MCR_SW_RST_MASK)
/*! @} */

/*! @name LR - Lock Register */
/*! @{ */

#define AHB_SRAMC_LR_LOCK_MASK                   (0x1U)
#define AHB_SRAMC_LR_LOCK_SHIFT                  (0U)
/*! LOCK - Lock Registers
 *  0b0..All the SRAMC registers are allowed to write.
 *  0b1..All the SRAMC registers are not allowed to write except Lock register.
 */
#define AHB_SRAMC_LR_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_LR_LOCK_SHIFT)) & AHB_SRAMC_LR_LOCK_MASK)
/*! @} */

/*! @name CFG0_CS - Configure Register 0 */
/*! @{ */

#define AHB_SRAMC_CFG0_CS_WM_EN_MASK             (0x1U)
#define AHB_SRAMC_CFG0_CS_WM_EN_SHIFT            (0U)
/*! WM_EN - Wait Mode Enable
 *  0b0..SRAM access does not need to monitor wait pin.
 *  0b1..SRAM access need to monitor wait pin.
 */
#define AHB_SRAMC_CFG0_CS_WM_EN(x)               (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_CFG0_CS_WM_EN_SHIFT)) & AHB_SRAMC_CFG0_CS_WM_EN_MASK)

#define AHB_SRAMC_CFG0_CS_WM_SEL_MASK            (0xEU)
#define AHB_SRAMC_CFG0_CS_WM_SEL_SHIFT           (1U)
/*! WM_SEL - Wait Mode Selection
 *  0b000..Wait signal is determined by level of wait pin.
 *  0b001..Wait signal is determined by both conditions of wait pin level and internal wait counter. Quits wait state when both of them exit waiting.
 *  0b010..Wait signal is determined by any condition of wait pin level and internal wait counter. Quits wait state when any of them exits waiting.
 *  0b011..Reserved
 *  0b100..Wait signal is determined by edge of wait pin.
 *  0b101..Wait signal is determined by both conditions of wait pin edge and internal wait counter. Quits wait state when both of them exit waiting.
 *  0b110..Wait signal is determined by any condition of wait pin edge and internal wait counter. Quits wait state when any of them exits waiting.
 *  0b111..Reserved
 */
#define AHB_SRAMC_CFG0_CS_WM_SEL(x)              (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_CFG0_CS_WM_SEL_SHIFT)) & AHB_SRAMC_CFG0_CS_WM_SEL_MASK)

#define AHB_SRAMC_CFG0_CS_WP_MUX_MASK            (0x30U)
#define AHB_SRAMC_CFG0_CS_WP_MUX_SHIFT           (4U)
/*! WP_MUX - Wait Pin Mux
 *  0b00..Wait pin 0 is selected.
 *  0b01..Wait pin 1 is selected.
 *  0b10..Wait pin 2 is selected.
 *  0b11..Wait pin 3 is selected.
 */
#define AHB_SRAMC_CFG0_CS_WP_MUX(x)              (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_CFG0_CS_WP_MUX_SHIFT)) & AHB_SRAMC_CFG0_CS_WP_MUX_MASK)

#define AHB_SRAMC_CFG0_CS_WP_POL_MASK            (0x40U)
#define AHB_SRAMC_CFG0_CS_WP_POL_SHIFT           (6U)
/*! WP_POL - Wait Polarity
 *  0b0..Wait pin is low active.
 *  0b1..Wait pin is high active.
 */
#define AHB_SRAMC_CFG0_CS_WP_POL(x)              (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_CFG0_CS_WP_POL_SHIFT)) & AHB_SRAMC_CFG0_CS_WP_POL_MASK)

#define AHB_SRAMC_CFG0_CS_CES_MASK               (0xF00U)
#define AHB_SRAMC_CFG0_CS_CES_SHIFT              (8U)
/*! CES - CE setup time */
#define AHB_SRAMC_CFG0_CS_CES(x)                 (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_CFG0_CS_CES_SHIFT)) & AHB_SRAMC_CFG0_CS_CES_MASK)

#define AHB_SRAMC_CFG0_CS_CEH_MASK               (0xF000U)
#define AHB_SRAMC_CFG0_CS_CEH_SHIFT              (12U)
/*! CEH - CE hold time */
#define AHB_SRAMC_CFG0_CS_CEH(x)                 (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_CFG0_CS_CEH_SHIFT)) & AHB_SRAMC_CFG0_CS_CEH_MASK)

#define AHB_SRAMC_CFG0_CS_AS_MASK                (0xF0000U)
#define AHB_SRAMC_CFG0_CS_AS_SHIFT               (16U)
/*! AS - Address setup time */
#define AHB_SRAMC_CFG0_CS_AS(x)                  (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_CFG0_CS_AS_SHIFT)) & AHB_SRAMC_CFG0_CS_AS_MASK)

#define AHB_SRAMC_CFG0_CS_AH_MASK                (0xF00000U)
#define AHB_SRAMC_CFG0_CS_AH_SHIFT               (20U)
/*! AH - Address hold time */
#define AHB_SRAMC_CFG0_CS_AH(x)                  (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_CFG0_CS_AH_SHIFT)) & AHB_SRAMC_CFG0_CS_AH_MASK)

#define AHB_SRAMC_CFG0_CS_TA_MASK                (0xF000000U)
#define AHB_SRAMC_CFG0_CS_TA_SHIFT               (24U)
/*! TA - Turnaround time */
#define AHB_SRAMC_CFG0_CS_TA(x)                  (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_CFG0_CS_TA_SHIFT)) & AHB_SRAMC_CFG0_CS_TA_MASK)

#define AHB_SRAMC_CFG0_CS_PRE_MASK               (0x30000000U)
#define AHB_SRAMC_CFG0_CS_PRE_SHIFT              (28U)
/*! PRE - Prescaler timer
 *  0b00..Time granularity is 1 clock cycle.
 *  0b01..Time granularity is 2 clock cycles.
 *  0b10..Time granularity is 3 clock cycles.
 *  0b11..Time granularity is 4 clock cycles.
 */
#define AHB_SRAMC_CFG0_CS_PRE(x)                 (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_CFG0_CS_PRE_SHIFT)) & AHB_SRAMC_CFG0_CS_PRE_MASK)
/*! @} */

/*! @name CFG1_CS - Configure Register 1 */
/*! @{ */

#define AHB_SRAMC_CFG1_CS_WEL_MASK               (0xFFU)
#define AHB_SRAMC_CFG1_CS_WEL_SHIFT              (0U)
/*! WEL - WE low time */
#define AHB_SRAMC_CFG1_CS_WEL(x)                 (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_CFG1_CS_WEL_SHIFT)) & AHB_SRAMC_CFG1_CS_WEL_MASK)

#define AHB_SRAMC_CFG1_CS_WEH_MASK               (0xFF00U)
#define AHB_SRAMC_CFG1_CS_WEH_SHIFT              (8U)
/*! WEH - WE high time */
#define AHB_SRAMC_CFG1_CS_WEH(x)                 (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_CFG1_CS_WEH_SHIFT)) & AHB_SRAMC_CFG1_CS_WEH_MASK)

#define AHB_SRAMC_CFG1_CS_REL_MASK               (0xFF0000U)
#define AHB_SRAMC_CFG1_CS_REL_SHIFT              (16U)
/*! REL - RE low time */
#define AHB_SRAMC_CFG1_CS_REL(x)                 (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_CFG1_CS_REL_SHIFT)) & AHB_SRAMC_CFG1_CS_REL_MASK)

#define AHB_SRAMC_CFG1_CS_REH_MASK               (0xFF000000U)
#define AHB_SRAMC_CFG1_CS_REH_SHIFT              (24U)
/*! REH - RE high time */
#define AHB_SRAMC_CFG1_CS_REH(x)                 (((uint32_t)(((uint32_t)(x)) << AHB_SRAMC_CFG1_CS_REH_SHIFT)) & AHB_SRAMC_CFG1_CS_REH_MASK)
/*! @} */

/* The count of AHB_SRAMC_CFG1_CS */
#define AHB_SRAMC_CFG1_CS_COUNT                  (2U)


/*!
 * @}
 */ /* end of group AHB_SRAMC_Register_Masks */


/*!
 * @}
 */ /* end of group AHB_SRAMC_Peripheral_Access_Layer */


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


#endif  /* PERI_AHB_SRAMC_H_ */

