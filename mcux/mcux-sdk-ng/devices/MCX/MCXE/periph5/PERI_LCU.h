/*
** ###################################################################
**     Processors:          MCXE315MLF
**                          MCXE315MPA
**                          MCXE316MLF
**                          MCXE316MPA
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LCU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_LCU.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for LCU
 *
 * CMSIS Peripheral Access Layer for LCU
 */

#if !defined(PERI_LCU_H_)
#define PERI_LCU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE315MLF) || defined(CPU_MCXE315MPA))
#include "MCXE315_COMMON.h"
#elif (defined(CPU_MCXE316MLF) || defined(CPU_MCXE316MPA))
#include "MCXE316_COMMON.h"
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
   -- LCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCU_Peripheral_Access_Layer LCU Peripheral Access Layer
 * @{
 */

/** LCU - Size of Registers Arrays */
#define LCU_LC_LUTCTRL_COUNT                      4u
#define LCU_LC_FILT_COUNT                         4u
#define LCU_LC_COUNT                              3u
#define LCU_SEL_COUNT                             12u

/** LCU - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x40 */
    __IO uint32_t LUTCTRL[LCU_LC_LUTCTRL_COUNT];     /**< LC 0 Output 0 LUT Control..LC 2 Output 3 LUT Control, array offset: 0x0, array step: index*0x40, index2*0x4 */
    __IO uint32_t FILT[LCU_LC_FILT_COUNT];           /**< LC 0 Output 0 Filter..LC 2 Output 3 Filter, array offset: 0x10, array step: index*0x40, index2*0x4 */
    __IO uint32_t INTDMAEN;                          /**< LC 0 Interrupt and DMA Enable..LC 2 Interrupt and DMA Enable, array offset: 0x20, array step: 0x40 */
    __IO uint32_t STS;                               /**< LC 0 Status..LC 2 Status, array offset: 0x24, array step: 0x40 */
    __IO uint32_t OUTPOL;                            /**< LC 0 Output Polarity Control..LC 2 Output Polarity Control, array offset: 0x28, array step: 0x40 */
    __IO uint32_t FFILT;                             /**< LC 0 Force Filter..LC 2 Force Filter, array offset: 0x2C, array step: 0x40 */
    __IO uint32_t FCTRL;                             /**< LC 0 Force Control..LC 2 Force Control, array offset: 0x30, array step: 0x40 */
    __IO uint32_t SCTRL;                             /**< LC 0 Sync Control..LC 2 Sync Control, array offset: 0x34, array step: 0x40 */
         uint8_t RESERVED_0[8];
  } LC[LCU_LC_COUNT];
       uint8_t RESERVED_0[320];
  __IO uint32_t MUXSEL[LCU_SEL_COUNT];             /**< Mux Select, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_1[80];
  __IO uint32_t CFG;                               /**< Configuration, offset: 0x280 */
  __IO uint32_t SWEN;                              /**< Software Override Enable, offset: 0x284 */
  __IO uint32_t SWVALUE;                           /**< Software Override Value, offset: 0x288 */
  __IO uint32_t OUTEN;                             /**< Output Enable, offset: 0x28C */
  __I  uint32_t LCIN;                              /**< Logic Inputs, offset: 0x290 */
  __I  uint32_t SWOUT;                             /**< Overridden Inputs, offset: 0x294 */
  __I  uint32_t LCOUT;                             /**< Logic Outputs, offset: 0x298 */
  __I  uint32_t FORCEOUT;                          /**< Forced Outputs, offset: 0x29C */
  __IO uint32_t FORCESTS;                          /**< Force Status, offset: 0x2A0 */
       uint8_t RESERVED_2[4];
  __IO uint32_t DBGEN;                             /**< Debug Mode Enable, offset: 0x2A8 */
} LCU_Type;

/* ----------------------------------------------------------------------------
   -- LCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCU_Register_Masks LCU Register Masks
 * @{
 */

/*! @name LUTCTRL - LC 0 Output 0 LUT Control..LC 2 Output 3 LUT Control */
/*! @{ */

#define LCU_LUTCTRL_LUTCTRL_MASK                 (0xFFFFU)
#define LCU_LUTCTRL_LUTCTRL_SHIFT                (0U)
/*! LUTCTRL - LUT Control */
#define LCU_LUTCTRL_LUTCTRL(x)                   (((uint32_t)(((uint32_t)(x)) << LCU_LUTCTRL_LUTCTRL_SHIFT)) & LCU_LUTCTRL_LUTCTRL_MASK)
/*! @} */

/* The count of LCU_LUTCTRL */
#define LCU_LUTCTRL_COUNT                        (3U)

/* The count of LCU_LUTCTRL */
#define LCU_LUTCTRL_COUNT2                       (4U)

/*! @name FILT - LC 0 Output 0 Filter..LC 2 Output 3 Filter */
/*! @{ */

#define LCU_FILT_LUT_FALL_FILT_MASK              (0xFFFFU)
#define LCU_FILT_LUT_FALL_FILT_SHIFT             (0U)
/*! LUT_FALL_FILT - Fall Filter
 *  0b0000000000000000..Bypass filter
 *  *..Filter threshold
 */
#define LCU_FILT_LUT_FALL_FILT(x)                (((uint32_t)(((uint32_t)(x)) << LCU_FILT_LUT_FALL_FILT_SHIFT)) & LCU_FILT_LUT_FALL_FILT_MASK)

#define LCU_FILT_LUT_RISE_FILT_MASK              (0xFFFF0000U)
#define LCU_FILT_LUT_RISE_FILT_SHIFT             (16U)
/*! LUT_RISE_FILT - Rise Filter
 *  0b0000000000000000..Bypass filter
 *  *..Filter threshold
 */
#define LCU_FILT_LUT_RISE_FILT(x)                (((uint32_t)(((uint32_t)(x)) << LCU_FILT_LUT_RISE_FILT_SHIFT)) & LCU_FILT_LUT_RISE_FILT_MASK)
/*! @} */

/* The count of LCU_FILT */
#define LCU_FILT_COUNT                           (3U)

/* The count of LCU_FILT */
#define LCU_FILT_COUNT2                          (4U)

/*! @name INTDMAEN - LC 0 Interrupt and DMA Enable..LC 2 Interrupt and DMA Enable */
/*! @{ */

#define LCU_INTDMAEN_LUT_INT_EN_MASK             (0xFU)
#define LCU_INTDMAEN_LUT_INT_EN_SHIFT            (0U)
/*! LUT_INT_EN - LUT Interrupt Enable */
#define LCU_INTDMAEN_LUT_INT_EN(x)               (((uint32_t)(((uint32_t)(x)) << LCU_INTDMAEN_LUT_INT_EN_SHIFT)) & LCU_INTDMAEN_LUT_INT_EN_MASK)

#define LCU_INTDMAEN_LUT_DMA_EN_MASK             (0xF00U)
#define LCU_INTDMAEN_LUT_DMA_EN_SHIFT            (8U)
/*! LUT_DMA_EN - LUT DMA Enable */
#define LCU_INTDMAEN_LUT_DMA_EN(x)               (((uint32_t)(((uint32_t)(x)) << LCU_INTDMAEN_LUT_DMA_EN_SHIFT)) & LCU_INTDMAEN_LUT_DMA_EN_MASK)

#define LCU_INTDMAEN_FORCE_INT_EN_MASK           (0xF0000U)
#define LCU_INTDMAEN_FORCE_INT_EN_SHIFT          (16U)
/*! FORCE_INT_EN - Force Interrupt Enable */
#define LCU_INTDMAEN_FORCE_INT_EN(x)             (((uint32_t)(((uint32_t)(x)) << LCU_INTDMAEN_FORCE_INT_EN_SHIFT)) & LCU_INTDMAEN_FORCE_INT_EN_MASK)

#define LCU_INTDMAEN_FORCE_DMA_EN_MASK           (0xF000000U)
#define LCU_INTDMAEN_FORCE_DMA_EN_SHIFT          (24U)
/*! FORCE_DMA_EN - Force DMA Enable */
#define LCU_INTDMAEN_FORCE_DMA_EN(x)             (((uint32_t)(((uint32_t)(x)) << LCU_INTDMAEN_FORCE_DMA_EN_SHIFT)) & LCU_INTDMAEN_FORCE_DMA_EN_MASK)
/*! @} */

/* The count of LCU_INTDMAEN */
#define LCU_INTDMAEN_COUNT                       (3U)

/*! @name STS - LC 0 Status..LC 2 Status */
/*! @{ */

#define LCU_STS_LUT_STS_MASK                     (0xFU)
#define LCU_STS_LUT_STS_SHIFT                    (0U)
/*! LUT_STS - LUT Event */
#define LCU_STS_LUT_STS(x)                       (((uint32_t)(((uint32_t)(x)) << LCU_STS_LUT_STS_SHIFT)) & LCU_STS_LUT_STS_MASK)

#define LCU_STS_FORCESTS_MASK                    (0xF00U)
#define LCU_STS_FORCESTS_SHIFT                   (8U)
/*! FORCESTS - Force Event */
#define LCU_STS_FORCESTS(x)                      (((uint32_t)(((uint32_t)(x)) << LCU_STS_FORCESTS_SHIFT)) & LCU_STS_FORCESTS_MASK)
/*! @} */

/* The count of LCU_STS */
#define LCU_STS_COUNT                            (3U)

/*! @name OUTPOL - LC 0 Output Polarity Control..LC 2 Output Polarity Control */
/*! @{ */

#define LCU_OUTPOL_OUTPOL_MASK                   (0xFU)
#define LCU_OUTPOL_OUTPOL_SHIFT                  (0U)
/*! OUTPOL - Output Polarity */
#define LCU_OUTPOL_OUTPOL(x)                     (((uint32_t)(((uint32_t)(x)) << LCU_OUTPOL_OUTPOL_SHIFT)) & LCU_OUTPOL_OUTPOL_MASK)
/*! @} */

/* The count of LCU_OUTPOL */
#define LCU_OUTPOL_COUNT                         (3U)

/*! @name FFILT - LC 0 Force Filter..LC 2 Force Filter */
/*! @{ */

#define LCU_FFILT_FORCE_FILT_MASK                (0xFFU)
#define LCU_FFILT_FORCE_FILT_SHIFT               (0U)
/*! FORCE_FILT - Force Filter
 *  0b00000000..Bypass filter
 *  *..Filter threshold
 */
#define LCU_FFILT_FORCE_FILT(x)                  (((uint32_t)(((uint32_t)(x)) << LCU_FFILT_FORCE_FILT_SHIFT)) & LCU_FFILT_FORCE_FILT_MASK)

#define LCU_FFILT_FORCE_POL_MASK                 (0x70000U)
#define LCU_FFILT_FORCE_POL_SHIFT                (16U)
/*! FORCE_POL - Force Input Polarity */
#define LCU_FFILT_FORCE_POL(x)                   (((uint32_t)(((uint32_t)(x)) << LCU_FFILT_FORCE_POL_SHIFT)) & LCU_FFILT_FORCE_POL_MASK)

#define LCU_FFILT_COMB_EN_MASK                   (0x7000000U)
#define LCU_FFILT_COMB_EN_SHIFT                  (24U)
/*! COMB_EN - Combinational Force Path (CFP) Enable */
#define LCU_FFILT_COMB_EN(x)                     (((uint32_t)(((uint32_t)(x)) << LCU_FFILT_COMB_EN_SHIFT)) & LCU_FFILT_COMB_EN_MASK)

#define LCU_FFILT_COMB_FORCE_MASK                (0xF0000000U)
#define LCU_FFILT_COMB_FORCE_SHIFT               (28U)
/*! COMB_FORCE - Combined Sensed Force Input */
#define LCU_FFILT_COMB_FORCE(x)                  (((uint32_t)(((uint32_t)(x)) << LCU_FFILT_COMB_FORCE_SHIFT)) & LCU_FFILT_COMB_FORCE_MASK)
/*! @} */

/* The count of LCU_FFILT */
#define LCU_FFILT_COUNT                          (3U)

/*! @name FCTRL - LC 0 Force Control..LC 2 Force Control */
/*! @{ */

#define LCU_FCTRL_FORCE_SENSE0_MASK              (0xFU)
#define LCU_FCTRL_FORCE_SENSE0_SHIFT             (0U)
/*! FORCE_SENSE0 - Force Input Sensitivity */
#define LCU_FCTRL_FORCE_SENSE0(x)                (((uint32_t)(((uint32_t)(x)) << LCU_FCTRL_FORCE_SENSE0_SHIFT)) & LCU_FCTRL_FORCE_SENSE0_MASK)

#define LCU_FCTRL_FORCE_MODE0_MASK               (0x30U)
#define LCU_FCTRL_FORCE_MODE0_SHIFT              (4U)
/*! FORCE_MODE0 - Force Clearing Mode
 *  0b00..Deassertion
 *  0b01..Rising sync after deassertion
 *  0b10..Writing 1 after deassertion
 *  0b11..Rising sync after writing 1 and deassertion
 */
#define LCU_FCTRL_FORCE_MODE0(x)                 (((uint32_t)(((uint32_t)(x)) << LCU_FCTRL_FORCE_MODE0_SHIFT)) & LCU_FCTRL_FORCE_MODE0_MASK)

#define LCU_FCTRL_SYNC_SEL0_MASK                 (0xC0U)
#define LCU_FCTRL_SYNC_SEL0_SHIFT                (6U)
/*! SYNC_SEL0 - Sync Select
 *  0b00..Sync input 0
 *  0b01..Sync input 1
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define LCU_FCTRL_SYNC_SEL0(x)                   (((uint32_t)(((uint32_t)(x)) << LCU_FCTRL_SYNC_SEL0_SHIFT)) & LCU_FCTRL_SYNC_SEL0_MASK)

#define LCU_FCTRL_FORCE_SENSE1_MASK              (0xF00U)
#define LCU_FCTRL_FORCE_SENSE1_SHIFT             (8U)
/*! FORCE_SENSE1 - Force Input Sensitivity */
#define LCU_FCTRL_FORCE_SENSE1(x)                (((uint32_t)(((uint32_t)(x)) << LCU_FCTRL_FORCE_SENSE1_SHIFT)) & LCU_FCTRL_FORCE_SENSE1_MASK)

#define LCU_FCTRL_FORCE_MODE1_MASK               (0x3000U)
#define LCU_FCTRL_FORCE_MODE1_SHIFT              (12U)
/*! FORCE_MODE1 - Force Clearing Mode
 *  0b00..Deassertion
 *  0b01..Rising sync after deassertion
 *  0b10..Writing 1 after deassertion
 *  0b11..Rising sync after writing 1 and deassertion
 */
#define LCU_FCTRL_FORCE_MODE1(x)                 (((uint32_t)(((uint32_t)(x)) << LCU_FCTRL_FORCE_MODE1_SHIFT)) & LCU_FCTRL_FORCE_MODE1_MASK)

#define LCU_FCTRL_SYNC_SEL1_MASK                 (0xC000U)
#define LCU_FCTRL_SYNC_SEL1_SHIFT                (14U)
/*! SYNC_SEL1 - Sync Select
 *  0b00..Sync input 0
 *  0b01..Sync input 1
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define LCU_FCTRL_SYNC_SEL1(x)                   (((uint32_t)(((uint32_t)(x)) << LCU_FCTRL_SYNC_SEL1_SHIFT)) & LCU_FCTRL_SYNC_SEL1_MASK)

#define LCU_FCTRL_FORCE_SENSE2_MASK              (0xF0000U)
#define LCU_FCTRL_FORCE_SENSE2_SHIFT             (16U)
/*! FORCE_SENSE2 - Force Input Sensitivity */
#define LCU_FCTRL_FORCE_SENSE2(x)                (((uint32_t)(((uint32_t)(x)) << LCU_FCTRL_FORCE_SENSE2_SHIFT)) & LCU_FCTRL_FORCE_SENSE2_MASK)

#define LCU_FCTRL_FORCE_MODE2_MASK               (0x300000U)
#define LCU_FCTRL_FORCE_MODE2_SHIFT              (20U)
/*! FORCE_MODE2 - Force Clearing Mode
 *  0b00..Deassertion
 *  0b01..Rising sync after deassertion
 *  0b10..Writing 1 after deassertion
 *  0b11..Rising sync after writing 1 and deassertion
 */
#define LCU_FCTRL_FORCE_MODE2(x)                 (((uint32_t)(((uint32_t)(x)) << LCU_FCTRL_FORCE_MODE2_SHIFT)) & LCU_FCTRL_FORCE_MODE2_MASK)

#define LCU_FCTRL_SYNC_SEL2_MASK                 (0xC00000U)
#define LCU_FCTRL_SYNC_SEL2_SHIFT                (22U)
/*! SYNC_SEL2 - Sync Select
 *  0b00..Sync input 0
 *  0b01..Sync input 1
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define LCU_FCTRL_SYNC_SEL2(x)                   (((uint32_t)(((uint32_t)(x)) << LCU_FCTRL_SYNC_SEL2_SHIFT)) & LCU_FCTRL_SYNC_SEL2_MASK)

#define LCU_FCTRL_FORCE_SENSE3_MASK              (0xF000000U)
#define LCU_FCTRL_FORCE_SENSE3_SHIFT             (24U)
/*! FORCE_SENSE3 - Force Input Sensitivity */
#define LCU_FCTRL_FORCE_SENSE3(x)                (((uint32_t)(((uint32_t)(x)) << LCU_FCTRL_FORCE_SENSE3_SHIFT)) & LCU_FCTRL_FORCE_SENSE3_MASK)

#define LCU_FCTRL_FORCE_MODE3_MASK               (0x30000000U)
#define LCU_FCTRL_FORCE_MODE3_SHIFT              (28U)
/*! FORCE_MODE3 - Force Clearing Mode
 *  0b00..Deassertion
 *  0b01..Rising sync after deassertion
 *  0b10..Writing 1 after deassertion
 *  0b11..Rising sync after writing 1 and deassertion
 */
#define LCU_FCTRL_FORCE_MODE3(x)                 (((uint32_t)(((uint32_t)(x)) << LCU_FCTRL_FORCE_MODE3_SHIFT)) & LCU_FCTRL_FORCE_MODE3_MASK)

#define LCU_FCTRL_SYNC_SEL3_MASK                 (0xC0000000U)
#define LCU_FCTRL_SYNC_SEL3_SHIFT                (30U)
/*! SYNC_SEL3 - Sync Select
 *  0b00..Sync input 0
 *  0b01..Sync input 1
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define LCU_FCTRL_SYNC_SEL3(x)                   (((uint32_t)(((uint32_t)(x)) << LCU_FCTRL_SYNC_SEL3_SHIFT)) & LCU_FCTRL_SYNC_SEL3_MASK)
/*! @} */

/* The count of LCU_FCTRL */
#define LCU_FCTRL_COUNT                          (3U)

/*! @name SCTRL - LC 0 Sync Control..LC 2 Sync Control */
/*! @{ */

#define LCU_SCTRL_SW_MODE_MASK                   (0xFU)
#define LCU_SCTRL_SW_MODE_SHIFT                  (0U)
/*! SW_MODE - Software Sync Mode */
#define LCU_SCTRL_SW_MODE(x)                     (((uint32_t)(((uint32_t)(x)) << LCU_SCTRL_SW_MODE_SHIFT)) & LCU_SCTRL_SW_MODE_MASK)

#define LCU_SCTRL_SW_SYNC_SEL_MASK               (0x100U)
#define LCU_SCTRL_SW_SYNC_SEL_SHIFT              (8U)
/*! SW_SYNC_SEL - Software Sync Select
 *  0b0..Sync input 0
 *  0b1..Sync input 1
 */
#define LCU_SCTRL_SW_SYNC_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << LCU_SCTRL_SW_SYNC_SEL_SHIFT)) & LCU_SCTRL_SW_SYNC_SEL_MASK)
/*! @} */

/* The count of LCU_SCTRL */
#define LCU_SCTRL_COUNT                          (3U)

/*! @name MUXSEL - Mux Select */
/*! @{ */

#define LCU_MUXSEL_MUXSEL_MASK                   (0xFFU)
#define LCU_MUXSEL_MUXSEL_SHIFT                  (0U)
/*! MUXSEL - Mux Select
 *  0b00000000..Logic 0
 *  0b00000001-0b00001100..LU_IN0 to LU_IN11
 *  0b00001101-0b00011000..LU_OUT0 to LU_OUT11
 */
#define LCU_MUXSEL_MUXSEL(x)                     (((uint32_t)(((uint32_t)(x)) << LCU_MUXSEL_MUXSEL_SHIFT)) & LCU_MUXSEL_MUXSEL_MASK)
/*! @} */

/* The count of LCU_MUXSEL */
#define LCU_MUXSEL_COUNT                         (12U)

/*! @name CFG - Configuration */
/*! @{ */

#define LCU_CFG_WP_MASK                          (0x1U)
#define LCU_CFG_WP_SHIFT                         (0U)
/*! WP - Write Protect
 *  0b0..No effect
 *  0b1..Turn on write protection
 */
#define LCU_CFG_WP(x)                            (((uint32_t)(((uint32_t)(x)) << LCU_CFG_WP_SHIFT)) & LCU_CFG_WP_MASK)

#define LCU_CFG_INCL_MUXES_MASK                  (0x80U)
#define LCU_CFG_INCL_MUXES_SHIFT                 (7U)
/*! INCL_MUXES - Input Muxing
 *  0b0..Not supported
 *  0b1..Supported
 */
#define LCU_CFG_INCL_MUXES(x)                    (((uint32_t)(((uint32_t)(x)) << LCU_CFG_INCL_MUXES_SHIFT)) & LCU_CFG_INCL_MUXES_MASK)

#define LCU_CFG_NUM_SYNCS_MASK                   (0xFF00U)
#define LCU_CFG_NUM_SYNCS_SHIFT                  (8U)
/*! NUM_SYNCS - Sync Inputs */
#define LCU_CFG_NUM_SYNCS(x)                     (((uint32_t)(((uint32_t)(x)) << LCU_CFG_NUM_SYNCS_SHIFT)) & LCU_CFG_NUM_SYNCS_MASK)

#define LCU_CFG_NUM_FORCES_MASK                  (0xFF0000U)
#define LCU_CFG_NUM_FORCES_SHIFT                 (16U)
/*! NUM_FORCES - Force Inputs */
#define LCU_CFG_NUM_FORCES(x)                    (((uint32_t)(((uint32_t)(x)) << LCU_CFG_NUM_FORCES_SHIFT)) & LCU_CFG_NUM_FORCES_MASK)

#define LCU_CFG_NUM_LOGIC_CELLS_MASK             (0xFF000000U)
#define LCU_CFG_NUM_LOGIC_CELLS_SHIFT            (24U)
/*! NUM_LOGIC_CELLS - LCs */
#define LCU_CFG_NUM_LOGIC_CELLS(x)               (((uint32_t)(((uint32_t)(x)) << LCU_CFG_NUM_LOGIC_CELLS_SHIFT)) & LCU_CFG_NUM_LOGIC_CELLS_MASK)
/*! @} */

/*! @name SWEN - Software Override Enable */
/*! @{ */

#define LCU_SWEN_SWEN_MASK                       (0xFFFU)
#define LCU_SWEN_SWEN_SHIFT                      (0U)
/*! SWEN - Software Override Enable */
#define LCU_SWEN_SWEN(x)                         (((uint32_t)(((uint32_t)(x)) << LCU_SWEN_SWEN_SHIFT)) & LCU_SWEN_SWEN_MASK)
/*! @} */

/*! @name SWVALUE - Software Override Value */
/*! @{ */

#define LCU_SWVALUE_SWVALUE_MASK                 (0xFFFU)
#define LCU_SWVALUE_SWVALUE_SHIFT                (0U)
/*! SWVALUE - Software Override Value */
#define LCU_SWVALUE_SWVALUE(x)                   (((uint32_t)(((uint32_t)(x)) << LCU_SWVALUE_SWVALUE_SHIFT)) & LCU_SWVALUE_SWVALUE_MASK)
/*! @} */

/*! @name OUTEN - Output Enable */
/*! @{ */

#define LCU_OUTEN_OUTEN_MASK                     (0xFFFU)
#define LCU_OUTEN_OUTEN_SHIFT                    (0U)
/*! OUTEN - Output Enables */
#define LCU_OUTEN_OUTEN(x)                       (((uint32_t)(((uint32_t)(x)) << LCU_OUTEN_OUTEN_SHIFT)) & LCU_OUTEN_OUTEN_MASK)
/*! @} */

/*! @name LCIN - Logic Inputs */
/*! @{ */

#define LCU_LCIN_LC_INPUTS_MASK                  (0xFFFU)
#define LCU_LCIN_LC_INPUTS_SHIFT                 (0U)
/*! LC_INPUTS - Logic Inputs */
#define LCU_LCIN_LC_INPUTS(x)                    (((uint32_t)(((uint32_t)(x)) << LCU_LCIN_LC_INPUTS_SHIFT)) & LCU_LCIN_LC_INPUTS_MASK)
/*! @} */

/*! @name SWOUT - Overridden Inputs */
/*! @{ */

#define LCU_SWOUT_SWOUT_MASK                     (0xFFFU)
#define LCU_SWOUT_SWOUT_SHIFT                    (0U)
/*! SWOUT - Overridden Inputs */
#define LCU_SWOUT_SWOUT(x)                       (((uint32_t)(((uint32_t)(x)) << LCU_SWOUT_SWOUT_SHIFT)) & LCU_SWOUT_SWOUT_MASK)
/*! @} */

/*! @name LCOUT - Logic Outputs */
/*! @{ */

#define LCU_LCOUT_LCOUT_MASK                     (0xFFFU)
#define LCU_LCOUT_LCOUT_SHIFT                    (0U)
/*! LCOUT - Logic Outputs */
#define LCU_LCOUT_LCOUT(x)                       (((uint32_t)(((uint32_t)(x)) << LCU_LCOUT_LCOUT_SHIFT)) & LCU_LCOUT_LCOUT_MASK)
/*! @} */

/*! @name FORCEOUT - Forced Outputs */
/*! @{ */

#define LCU_FORCEOUT_FORCEOUT_MASK               (0xFFFU)
#define LCU_FORCEOUT_FORCEOUT_SHIFT              (0U)
/*! FORCEOUT - Forced Outputs */
#define LCU_FORCEOUT_FORCEOUT(x)                 (((uint32_t)(((uint32_t)(x)) << LCU_FORCEOUT_FORCEOUT_SHIFT)) & LCU_FORCEOUT_FORCEOUT_MASK)
/*! @} */

/*! @name FORCESTS - Force Status */
/*! @{ */

#define LCU_FORCESTS_FORCESTS_MASK               (0xFFFU)
#define LCU_FORCESTS_FORCESTS_SHIFT              (0U)
/*! FORCESTS - Force Status */
#define LCU_FORCESTS_FORCESTS(x)                 (((uint32_t)(((uint32_t)(x)) << LCU_FORCESTS_FORCESTS_SHIFT)) & LCU_FORCESTS_FORCESTS_MASK)
/*! @} */

/*! @name DBGEN - Debug Mode Enable */
/*! @{ */

#define LCU_DBGEN_DBGEN_MASK                     (0xFFFU)
#define LCU_DBGEN_DBGEN_SHIFT                    (0U)
/*! DBGEN - Debug Mode Enable */
#define LCU_DBGEN_DBGEN(x)                       (((uint32_t)(((uint32_t)(x)) << LCU_DBGEN_DBGEN_SHIFT)) & LCU_DBGEN_DBGEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LCU_Register_Masks */


/*!
 * @}
 */ /* end of group LCU_Peripheral_Access_Layer */


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


#endif  /* PERI_LCU_H_ */

