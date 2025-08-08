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
**         CMSIS Peripheral Access Layer for MC_CGM
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
 * @file PERI_MC_CGM.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for MC_CGM
 *
 * CMSIS Peripheral Access Layer for MC_CGM
 */

#if !defined(PERI_MC_CGM_H_)
#define PERI_MC_CGM_H_                           /**< Symbol preventing repeated inclusion */

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
   -- MC_CGM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MC_CGM_Peripheral_Access_Layer MC_CGM Peripheral Access Layer
 * @{
 */

/** MC_CGM - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCFS_SDUR;                         /**< PCFS Step Duration, offset: 0x0 */
       uint8_t RESERVED_0[84];
  __IO uint32_t PCFS_DIVC8;                        /**< PCFS Divider Change 8 Register, offset: 0x58 */
  __IO uint32_t PCFS_DIVE8;                        /**< PCFS Divider End 8 Register, offset: 0x5C */
  __IO uint32_t PCFS_DIVS8;                        /**< PCFS Divider Start 8 Register, offset: 0x60 */
       uint8_t RESERVED_1[668];
  __IO uint32_t MUX_0_CSC;                         /**< Clock Mux 0 Select Control Register, offset: 0x300 */
  __I  uint32_t MUX_0_CSS;                         /**< Clock Mux 0 Select Status Register, offset: 0x304 */
  __IO uint32_t MUX_0_DC_0;                        /**< Clock Mux 0 Divider 0 Control Register, offset: 0x308 */
  __IO uint32_t MUX_0_DC_1;                        /**< Clock Mux 0 Divider 1 Control Register, offset: 0x30C */
  __IO uint32_t MUX_0_DC_2;                        /**< Clock Mux 0 Divider 2 Control Register, offset: 0x310 */
  __IO uint32_t MUX_0_DC_3;                        /**< Clock Mux 0 Divider 3 Control Register, offset: 0x314 */
  __IO uint32_t MUX_0_DC_4;                        /**< Clock Mux 0 Divider 4 Control Register, offset: 0x318 */
       uint8_t RESERVED_2[24];
  __IO uint32_t MUX_0_DIV_TRIG_CTRL;               /**< Clock Mux 0 Divider Trigger Control Register, offset: 0x334 */
  __IO uint32_t MUX_0_DIV_TRIG;                    /**< Clock Mux 0 Divider Trigger Register, offset: 0x338 */
  __I  uint32_t MUX_0_DIV_UPD_STAT;                /**< Clock Mux 0 Divider Update Status Register, offset: 0x33C */
  __IO uint32_t MUX_1_CSC;                         /**< Clock Mux 1 Select Control Register, offset: 0x340 */
  __I  uint32_t MUX_1_CSS;                         /**< Clock Mux 1 Select Status Register, offset: 0x344 */
  __IO uint32_t MUX_1_DC_0;                        /**< Clock Mux 1 Divider 0 Control Register, offset: 0x348 */
       uint8_t RESERVED_3[48];
  __I  uint32_t MUX_1_DIV_UPD_STAT;                /**< Clock Mux 1 Divider Update Status Register, offset: 0x37C */
       uint8_t RESERVED_4[64];
  __IO uint32_t MUX_3_CSC;                         /**< Clock Mux 3 Select Control Register, offset: 0x3C0 */
  __I  uint32_t MUX_3_CSS;                         /**< Clock Mux 3 Select Status Register, offset: 0x3C4 */
  __IO uint32_t MUX_3_DC_0;                        /**< Clock Mux 3 Divider 0 Control Register, offset: 0x3C8 */
       uint8_t RESERVED_5[48];
  __I  uint32_t MUX_3_DIV_UPD_STAT;                /**< Clock Mux 3 Divider Update Status Register, offset: 0x3FC */
       uint8_t RESERVED_6[64];
  __IO uint32_t MUX_5_CSC;                         /**< Clock Mux 5 Select Control Register, offset: 0x440 */
  __I  uint32_t MUX_5_CSS;                         /**< Clock Mux 5 Select Status Register, offset: 0x444 */
  __IO uint32_t MUX_5_DC_0;                        /**< Clock Mux 5 Divider 0 Control Register, offset: 0x448 */
       uint8_t RESERVED_7[48];
  __I  uint32_t MUX_5_DIV_UPD_STAT;                /**< Clock Mux 5 Divider Update Status Register, offset: 0x47C */
  __IO uint32_t MUX_6_CSC;                         /**< Clock Mux 6 Select Control Register, offset: 0x480 */
  __I  uint32_t MUX_6_CSS;                         /**< Clock Mux 6 Select Status Register, offset: 0x484 */
  __IO uint32_t MUX_6_DC_0;                        /**< Clock Mux 6 Divider 0 Control Register, offset: 0x488 */
       uint8_t RESERVED_8[48];
  __I  uint32_t MUX_6_DIV_UPD_STAT;                /**< Clock Mux 6 Divider Update Status Register, offset: 0x4BC */
       uint8_t RESERVED_9[256];
  __IO uint32_t MUX_11_CSC;                        /**< Clock Mux 11 Select Control Register, offset: 0x5C0 */
  __I  uint32_t MUX_11_CSS;                        /**< Clock Mux 11 Select Status Register, offset: 0x5C4 */
  __IO uint32_t MUX_11_DC_0;                       /**< Clock Mux 11 Divider 0 Control Register, offset: 0x5C8 */
       uint8_t RESERVED_10[48];
  __I  uint32_t MUX_11_DIV_UPD_STAT;               /**< Clock Mux 11 Divider Update Status Register, offset: 0x5FC */
} MC_CGM_Type;

/* ----------------------------------------------------------------------------
   -- MC_CGM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MC_CGM_Register_Masks MC_CGM Register Masks
 * @{
 */

/*! @name PCFS_SDUR - PCFS Step Duration */
/*! @{ */

#define MC_CGM_PCFS_SDUR_SDUR_MASK               (0xFFFFU)
#define MC_CGM_PCFS_SDUR_SDUR_SHIFT              (0U)
/*! SDUR - Step duration */
#define MC_CGM_PCFS_SDUR_SDUR(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_SDUR_SDUR_SHIFT)) & MC_CGM_PCFS_SDUR_SDUR_MASK)
/*! @} */

/*! @name PCFS_DIVC8 - PCFS Divider Change 8 Register */
/*! @{ */

#define MC_CGM_PCFS_DIVC8_RATE_MASK              (0xFFU)
#define MC_CGM_PCFS_DIVC8_RATE_SHIFT             (0U)
/*! RATE - Divider change rate */
#define MC_CGM_PCFS_DIVC8_RATE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC8_RATE_SHIFT)) & MC_CGM_PCFS_DIVC8_RATE_MASK)

#define MC_CGM_PCFS_DIVC8_INIT_MASK              (0xFFFF0000U)
#define MC_CGM_PCFS_DIVC8_INIT_SHIFT             (16U)
/*! INIT - Divider change initial value */
#define MC_CGM_PCFS_DIVC8_INIT(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVC8_INIT_SHIFT)) & MC_CGM_PCFS_DIVC8_INIT_MASK)
/*! @} */

/*! @name PCFS_DIVE8 - PCFS Divider End 8 Register */
/*! @{ */

#define MC_CGM_PCFS_DIVE8_DIVE_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVE8_DIVE_SHIFT             (0U)
/*! DIVE - Divider end value */
#define MC_CGM_PCFS_DIVE8_DIVE(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVE8_DIVE_SHIFT)) & MC_CGM_PCFS_DIVE8_DIVE_MASK)
/*! @} */

/*! @name PCFS_DIVS8 - PCFS Divider Start 8 Register */
/*! @{ */

#define MC_CGM_PCFS_DIVS8_DIVS_MASK              (0xFFFFFU)
#define MC_CGM_PCFS_DIVS8_DIVS_SHIFT             (0U)
/*! DIVS - Divider start value */
#define MC_CGM_PCFS_DIVS8_DIVS(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_PCFS_DIVS8_DIVS_SHIFT)) & MC_CGM_PCFS_DIVS8_DIVS_MASK)
/*! @} */

/*! @name MUX_0_CSC - Clock Mux 0 Select Control Register */
/*! @{ */

#define MC_CGM_MUX_0_CSC_RAMPUP_MASK             (0x1U)
#define MC_CGM_MUX_0_CSC_RAMPUP_SHIFT            (0U)
/*! RAMPUP - PCFS ramp-up */
#define MC_CGM_MUX_0_CSC_RAMPUP(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_CSC_RAMPUP_SHIFT)) & MC_CGM_MUX_0_CSC_RAMPUP_MASK)

#define MC_CGM_MUX_0_CSC_RAMPDOWN_MASK           (0x2U)
#define MC_CGM_MUX_0_CSC_RAMPDOWN_SHIFT          (1U)
/*! RAMPDOWN - PCFS ramp-down */
#define MC_CGM_MUX_0_CSC_RAMPDOWN(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_CSC_RAMPDOWN_SHIFT)) & MC_CGM_MUX_0_CSC_RAMPDOWN_MASK)

#define MC_CGM_MUX_0_CSC_CLK_SW_MASK             (0x4U)
#define MC_CGM_MUX_0_CSC_CLK_SW_SHIFT            (2U)
/*! CLK_SW - Clock switch */
#define MC_CGM_MUX_0_CSC_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_CSC_CLK_SW_SHIFT)) & MC_CGM_MUX_0_CSC_CLK_SW_MASK)

#define MC_CGM_MUX_0_CSC_SAFE_SW_MASK            (0x8U)
#define MC_CGM_MUX_0_CSC_SAFE_SW_SHIFT           (3U)
/*! SAFE_SW - Safe clock request */
#define MC_CGM_MUX_0_CSC_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_CSC_SAFE_SW_SHIFT)) & MC_CGM_MUX_0_CSC_SAFE_SW_MASK)

#define MC_CGM_MUX_0_CSC_SELCTL_MASK             (0xF000000U)
#define MC_CGM_MUX_0_CSC_SELCTL_SHIFT            (24U)
/*! SELCTL - Clock source selection control
 *  0b0000..FIRC
 *  0b1000..PLL_PHI0_CLK
 */
#define MC_CGM_MUX_0_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_CSC_SELCTL_SHIFT)) & MC_CGM_MUX_0_CSC_SELCTL_MASK)
/*! @} */

/*! @name MUX_0_CSS - Clock Mux 0 Select Status Register */
/*! @{ */

#define MC_CGM_MUX_0_CSS_RAMPUP_MASK             (0x1U)
#define MC_CGM_MUX_0_CSS_RAMPUP_SHIFT            (0U)
/*! RAMPUP - PCFS ramp-up
 *  0b0..No ramp-up operation was requested.
 *  0b1..Ramp-up operation was requested.
 */
#define MC_CGM_MUX_0_CSS_RAMPUP(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_CSS_RAMPUP_SHIFT)) & MC_CGM_MUX_0_CSS_RAMPUP_MASK)

#define MC_CGM_MUX_0_CSS_RAMPDOWN_MASK           (0x2U)
#define MC_CGM_MUX_0_CSS_RAMPDOWN_SHIFT          (1U)
/*! RAMPDOWN - PCFS ramp-down
 *  0b0..No ramp-down operation was requested.
 *  0b1..Ramp-down operation was requested.
 */
#define MC_CGM_MUX_0_CSS_RAMPDOWN(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_CSS_RAMPDOWN_SHIFT)) & MC_CGM_MUX_0_CSS_RAMPDOWN_MASK)

#define MC_CGM_MUX_0_CSS_CLK_SW_MASK             (0x4U)
#define MC_CGM_MUX_0_CSS_CLK_SW_SHIFT            (2U)
/*! CLK_SW - Clock switch
 *  0b0..No clock switch operation was requested.
 *  0b1..Clock switch operation was requested.
 */
#define MC_CGM_MUX_0_CSS_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_CSS_CLK_SW_SHIFT)) & MC_CGM_MUX_0_CSS_CLK_SW_MASK)

#define MC_CGM_MUX_0_CSS_SAFE_SW_MASK            (0x8U)
#define MC_CGM_MUX_0_CSS_SAFE_SW_SHIFT           (3U)
/*! SAFE_SW - Safe clock request
 *  0b0..No safe clock switch operation was requested.
 *  0b1..Safe clock switch operation was requested.
 */
#define MC_CGM_MUX_0_CSS_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_CSS_SAFE_SW_SHIFT)) & MC_CGM_MUX_0_CSS_SAFE_SW_MASK)

#define MC_CGM_MUX_0_CSS_SWIP_MASK               (0x10000U)
#define MC_CGM_MUX_0_CSS_SWIP_SHIFT              (16U)
/*! SWIP - Switch in progress
 *  0b0..Clock source switching is complete.
 *  0b1..Clock source switching is in progress.
 */
#define MC_CGM_MUX_0_CSS_SWIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_CSS_SWIP_SHIFT)) & MC_CGM_MUX_0_CSS_SWIP_MASK)

#define MC_CGM_MUX_0_CSS_SWTRG_MASK              (0xE0000U)
#define MC_CGM_MUX_0_CSS_SWTRG_SHIFT             (17U)
/*! SWTRG - Switch trigger cause
 *  0b000..
 *  0b001..Switch after request succeeded.
 *  0b010..Switch after the request failed because of an inactive target clock and the current clock is FIRC.
 *  0b011..Switch after the request failed because of an inactive current clock and the current clock is FIRC.
 *  0b100..Switch to FIRC because of a safe clock request or reset succeeded.
 *  0b101..Switch to FIRC because of a safe clock request or reset succeeded, but the previous current clock source was inactive.
 *  0b110..
 *  0b111..
 */
#define MC_CGM_MUX_0_CSS_SWTRG(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_CSS_SWTRG_SHIFT)) & MC_CGM_MUX_0_CSS_SWTRG_MASK)

#define MC_CGM_MUX_0_CSS_SELSTAT_MASK            (0xF000000U)
#define MC_CGM_MUX_0_CSS_SELSTAT_SHIFT           (24U)
/*! SELSTAT - Clock source selection status
 *  0b0000..FIRC
 *  0b1000..PLL_PHI0_CLK
 */
#define MC_CGM_MUX_0_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_CSS_SELSTAT_SHIFT)) & MC_CGM_MUX_0_CSS_SELSTAT_MASK)
/*! @} */

/*! @name MUX_0_DC_0 - Clock Mux 0 Divider 0 Control Register */
/*! @{ */

#define MC_CGM_MUX_0_DC_0_DIV_MASK               (0x70000U)
#define MC_CGM_MUX_0_DC_0_DIV_SHIFT              (16U)
/*! DIV - Division value */
#define MC_CGM_MUX_0_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_DC_0_DIV_SHIFT)) & MC_CGM_MUX_0_DC_0_DIV_MASK)

#define MC_CGM_MUX_0_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_MUX_0_DC_0_DE_SHIFT               (31U)
/*! DE - Divider enable
 *  0b0..Unused
 *  0b1..Divider is enabled.
 */
#define MC_CGM_MUX_0_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_DC_0_DE_SHIFT)) & MC_CGM_MUX_0_DC_0_DE_MASK)
/*! @} */

/*! @name MUX_0_DC_1 - Clock Mux 0 Divider 1 Control Register */
/*! @{ */

#define MC_CGM_MUX_0_DC_1_DIV_MASK               (0x70000U)
#define MC_CGM_MUX_0_DC_1_DIV_SHIFT              (16U)
/*! DIV - Division value */
#define MC_CGM_MUX_0_DC_1_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_DC_1_DIV_SHIFT)) & MC_CGM_MUX_0_DC_1_DIV_MASK)

#define MC_CGM_MUX_0_DC_1_DE_MASK                (0x80000000U)
#define MC_CGM_MUX_0_DC_1_DE_SHIFT               (31U)
/*! DE - Divider enable
 *  0b0..Unused
 *  0b1..Divider is enabled.
 */
#define MC_CGM_MUX_0_DC_1_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_DC_1_DE_SHIFT)) & MC_CGM_MUX_0_DC_1_DE_MASK)
/*! @} */

/*! @name MUX_0_DC_2 - Clock Mux 0 Divider 2 Control Register */
/*! @{ */

#define MC_CGM_MUX_0_DC_2_DIV_MASK               (0xF0000U)
#define MC_CGM_MUX_0_DC_2_DIV_SHIFT              (16U)
/*! DIV - Division value */
#define MC_CGM_MUX_0_DC_2_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_DC_2_DIV_SHIFT)) & MC_CGM_MUX_0_DC_2_DIV_MASK)

#define MC_CGM_MUX_0_DC_2_DE_MASK                (0x80000000U)
#define MC_CGM_MUX_0_DC_2_DE_SHIFT               (31U)
/*! DE - Divider enable
 *  0b0..Unused
 *  0b1..Divider is enabled.
 */
#define MC_CGM_MUX_0_DC_2_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_DC_2_DE_SHIFT)) & MC_CGM_MUX_0_DC_2_DE_MASK)
/*! @} */

/*! @name MUX_0_DC_3 - Clock Mux 0 Divider 3 Control Register */
/*! @{ */

#define MC_CGM_MUX_0_DC_3_DIV_MASK               (0x70000U)
#define MC_CGM_MUX_0_DC_3_DIV_SHIFT              (16U)
/*! DIV - Division value */
#define MC_CGM_MUX_0_DC_3_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_DC_3_DIV_SHIFT)) & MC_CGM_MUX_0_DC_3_DIV_MASK)

#define MC_CGM_MUX_0_DC_3_DE_MASK                (0x80000000U)
#define MC_CGM_MUX_0_DC_3_DE_SHIFT               (31U)
/*! DE - Divider enable
 *  0b0..Unused
 *  0b1..Divider is enabled.
 */
#define MC_CGM_MUX_0_DC_3_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_DC_3_DE_SHIFT)) & MC_CGM_MUX_0_DC_3_DE_MASK)
/*! @} */

/*! @name MUX_0_DC_4 - Clock Mux 0 Divider 4 Control Register */
/*! @{ */

#define MC_CGM_MUX_0_DC_4_DIV_MASK               (0x70000U)
#define MC_CGM_MUX_0_DC_4_DIV_SHIFT              (16U)
/*! DIV - Division value */
#define MC_CGM_MUX_0_DC_4_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_DC_4_DIV_SHIFT)) & MC_CGM_MUX_0_DC_4_DIV_MASK)

#define MC_CGM_MUX_0_DC_4_DE_MASK                (0x80000000U)
#define MC_CGM_MUX_0_DC_4_DE_SHIFT               (31U)
/*! DE - Divider enable
 *  0b0..Unused
 *  0b1..Divider is enabled.
 */
#define MC_CGM_MUX_0_DC_4_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_DC_4_DE_SHIFT)) & MC_CGM_MUX_0_DC_4_DE_MASK)
/*! @} */

/*! @name MUX_0_DIV_TRIG_CTRL - Clock Mux 0 Divider Trigger Control Register */
/*! @{ */

#define MC_CGM_MUX_0_DIV_TRIG_CTRL_TCTL_MASK     (0x1U)
#define MC_CGM_MUX_0_DIV_TRIG_CTRL_TCTL_SHIFT    (0U)
/*! TCTL - Trigger control
 *  0b0..Immediate divider update
 *  0b1..Common trigger divider update
 */
#define MC_CGM_MUX_0_DIV_TRIG_CTRL_TCTL(x)       (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_DIV_TRIG_CTRL_TCTL_SHIFT)) & MC_CGM_MUX_0_DIV_TRIG_CTRL_TCTL_MASK)

#define MC_CGM_MUX_0_DIV_TRIG_CTRL_HHEN_MASK     (0x80000000U)
#define MC_CGM_MUX_0_DIV_TRIG_CTRL_HHEN_SHIFT    (31U)
/*! HHEN - Halt handshake enable
 *  0b0..No halt handshake protocol is initiated.
 *  0b1..Halt handshake protocol is initiated.
 */
#define MC_CGM_MUX_0_DIV_TRIG_CTRL_HHEN(x)       (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_DIV_TRIG_CTRL_HHEN_SHIFT)) & MC_CGM_MUX_0_DIV_TRIG_CTRL_HHEN_MASK)
/*! @} */

/*! @name MUX_0_DIV_TRIG - Clock Mux 0 Divider Trigger Register */
/*! @{ */

#define MC_CGM_MUX_0_DIV_TRIG_TRIGGER_MASK       (0xFFFFFFFFU)
#define MC_CGM_MUX_0_DIV_TRIG_TRIGGER_SHIFT      (0U)
/*! TRIGGER - Trigger for divider update */
#define MC_CGM_MUX_0_DIV_TRIG_TRIGGER(x)         (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_DIV_TRIG_TRIGGER_SHIFT)) & MC_CGM_MUX_0_DIV_TRIG_TRIGGER_MASK)
/*! @} */

/*! @name MUX_0_DIV_UPD_STAT - Clock Mux 0 Divider Update Status Register */
/*! @{ */

#define MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
/*! DIV_STAT - Divider status for clock mux 0
 *  0b0..No divider configuration update is pending.
 *  0b1..Divider configuration update on at least one divider associated with this multiplexer is pending.
 */
#define MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name MUX_1_CSC - Clock Mux 1 Select Control Register */
/*! @{ */

#define MC_CGM_MUX_1_CSC_CLK_SW_MASK             (0x4U)
#define MC_CGM_MUX_1_CSC_CLK_SW_SHIFT            (2U)
/*! CLK_SW - Clock switch */
#define MC_CGM_MUX_1_CSC_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_1_CSC_CLK_SW_SHIFT)) & MC_CGM_MUX_1_CSC_CLK_SW_MASK)

#define MC_CGM_MUX_1_CSC_SAFE_SW_MASK            (0x8U)
#define MC_CGM_MUX_1_CSC_SAFE_SW_SHIFT           (3U)
/*! SAFE_SW - Safe clock request */
#define MC_CGM_MUX_1_CSC_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_1_CSC_SAFE_SW_SHIFT)) & MC_CGM_MUX_1_CSC_SAFE_SW_MASK)

#define MC_CGM_MUX_1_CSC_SELCTL_MASK             (0x1F000000U)
#define MC_CGM_MUX_1_CSC_SELCTL_SHIFT            (24U)
/*! SELCTL - Clock source selection control
 *  0b00000..FIRC
 *  0b00010..FXOSC
 *  0b10110..AIPS_PLAT_CLK
 */
#define MC_CGM_MUX_1_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_1_CSC_SELCTL_SHIFT)) & MC_CGM_MUX_1_CSC_SELCTL_MASK)
/*! @} */

/*! @name MUX_1_CSS - Clock Mux 1 Select Status Register */
/*! @{ */

#define MC_CGM_MUX_1_CSS_CLK_SW_MASK             (0x4U)
#define MC_CGM_MUX_1_CSS_CLK_SW_SHIFT            (2U)
/*! CLK_SW - Clock switch
 *  0b0..No clock switch operation was requested.
 *  0b1..Clock switch operation was requested.
 */
#define MC_CGM_MUX_1_CSS_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_1_CSS_CLK_SW_SHIFT)) & MC_CGM_MUX_1_CSS_CLK_SW_MASK)

#define MC_CGM_MUX_1_CSS_SAFE_SW_MASK            (0x8U)
#define MC_CGM_MUX_1_CSS_SAFE_SW_SHIFT           (3U)
/*! SAFE_SW - Safe clock request
 *  0b0..No safe clock switch operation was requested.
 *  0b1..Safe clock switch operation was requested.
 */
#define MC_CGM_MUX_1_CSS_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_1_CSS_SAFE_SW_SHIFT)) & MC_CGM_MUX_1_CSS_SAFE_SW_MASK)

#define MC_CGM_MUX_1_CSS_SWIP_MASK               (0x10000U)
#define MC_CGM_MUX_1_CSS_SWIP_SHIFT              (16U)
/*! SWIP - Switch in progress
 *  0b0..Clock source switching is complete.
 *  0b1..Clock source switching is in progress.
 */
#define MC_CGM_MUX_1_CSS_SWIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_1_CSS_SWIP_SHIFT)) & MC_CGM_MUX_1_CSS_SWIP_MASK)

#define MC_CGM_MUX_1_CSS_SWTRG_MASK              (0xE0000U)
#define MC_CGM_MUX_1_CSS_SWTRG_SHIFT             (17U)
/*! SWTRG - Switch trigger cause
 *  0b000..
 *  0b001..Switch after request succeeded.
 *  0b010..Switch after the request failed because of an inactive target clock and the current clock is FIRC.
 *  0b011..Switch after the request failed because of an inactive current clock and the current clock is FIRC.
 *  0b100..Switch to FIRC because of a safe clock request or reset succeeded.
 *  0b101..Switch to FIRC because of a safe clock request or reset succeeded, but the previous current clock source was inactive.
 *  0b110..
 *  0b111..
 */
#define MC_CGM_MUX_1_CSS_SWTRG(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_1_CSS_SWTRG_SHIFT)) & MC_CGM_MUX_1_CSS_SWTRG_MASK)

#define MC_CGM_MUX_1_CSS_SELSTAT_MASK            (0x1F000000U)
#define MC_CGM_MUX_1_CSS_SELSTAT_SHIFT           (24U)
/*! SELSTAT - Clock source selection status
 *  0b00000..FIRC
 *  0b00010..FXOSC
 *  0b10110..AIPS_PLAT_CLK
 */
#define MC_CGM_MUX_1_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_1_CSS_SELSTAT_SHIFT)) & MC_CGM_MUX_1_CSS_SELSTAT_MASK)
/*! @} */

/*! @name MUX_1_DC_0 - Clock Mux 1 Divider 0 Control Register */
/*! @{ */

#define MC_CGM_MUX_1_DC_0_DIV_MASK               (0x10000U)
#define MC_CGM_MUX_1_DC_0_DIV_SHIFT              (16U)
/*! DIV - Division value */
#define MC_CGM_MUX_1_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_1_DC_0_DIV_SHIFT)) & MC_CGM_MUX_1_DC_0_DIV_MASK)

#define MC_CGM_MUX_1_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_MUX_1_DC_0_DE_SHIFT               (31U)
/*! DE - Divider enable
 *  0b0..Divider is disabled.
 *  0b1..Divider is enabled.
 */
#define MC_CGM_MUX_1_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_1_DC_0_DE_SHIFT)) & MC_CGM_MUX_1_DC_0_DE_MASK)
/*! @} */

/*! @name MUX_1_DIV_UPD_STAT - Clock Mux 1 Divider Update Status Register */
/*! @{ */

#define MC_CGM_MUX_1_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_MUX_1_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
/*! DIV_STAT - Divider status for clock mux 1
 *  0b0..No divider configuration update is pending.
 *  0b1..Divider configuration update on at least one divider associated with this multiplexer is pending.
 */
#define MC_CGM_MUX_1_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_1_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_MUX_1_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name MUX_3_CSC - Clock Mux 3 Select Control Register */
/*! @{ */

#define MC_CGM_MUX_3_CSC_CLK_SW_MASK             (0x4U)
#define MC_CGM_MUX_3_CSC_CLK_SW_SHIFT            (2U)
/*! CLK_SW - Clock switch */
#define MC_CGM_MUX_3_CSC_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_3_CSC_CLK_SW_SHIFT)) & MC_CGM_MUX_3_CSC_CLK_SW_MASK)

#define MC_CGM_MUX_3_CSC_SAFE_SW_MASK            (0x8U)
#define MC_CGM_MUX_3_CSC_SAFE_SW_SHIFT           (3U)
/*! SAFE_SW - Safe clock request */
#define MC_CGM_MUX_3_CSC_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_3_CSC_SAFE_SW_SHIFT)) & MC_CGM_MUX_3_CSC_SAFE_SW_MASK)

#define MC_CGM_MUX_3_CSC_SELCTL_MASK             (0x1F000000U)
#define MC_CGM_MUX_3_CSC_SELCTL_SHIFT            (24U)
/*! SELCTL - Clock source selection control
 *  0b00000..FIRC
 *  0b00010..FXOSC
 *  0b10110..AIPS_PLAT_CLK
 */
#define MC_CGM_MUX_3_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_3_CSC_SELCTL_SHIFT)) & MC_CGM_MUX_3_CSC_SELCTL_MASK)
/*! @} */

/*! @name MUX_3_CSS - Clock Mux 3 Select Status Register */
/*! @{ */

#define MC_CGM_MUX_3_CSS_CLK_SW_MASK             (0x4U)
#define MC_CGM_MUX_3_CSS_CLK_SW_SHIFT            (2U)
/*! CLK_SW - Clock switch
 *  0b0..No clock switch operation was requested.
 *  0b1..Clock switch operation was requested.
 */
#define MC_CGM_MUX_3_CSS_CLK_SW(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_3_CSS_CLK_SW_SHIFT)) & MC_CGM_MUX_3_CSS_CLK_SW_MASK)

#define MC_CGM_MUX_3_CSS_SAFE_SW_MASK            (0x8U)
#define MC_CGM_MUX_3_CSS_SAFE_SW_SHIFT           (3U)
/*! SAFE_SW - Safe clock request
 *  0b0..No safe clock switch operation was requested.
 *  0b1..Safe clock switch operation was requested.
 */
#define MC_CGM_MUX_3_CSS_SAFE_SW(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_3_CSS_SAFE_SW_SHIFT)) & MC_CGM_MUX_3_CSS_SAFE_SW_MASK)

#define MC_CGM_MUX_3_CSS_SWIP_MASK               (0x10000U)
#define MC_CGM_MUX_3_CSS_SWIP_SHIFT              (16U)
/*! SWIP - Switch in progress
 *  0b0..Clock source switching is complete.
 *  0b1..Clock source switching is in progress.
 */
#define MC_CGM_MUX_3_CSS_SWIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_3_CSS_SWIP_SHIFT)) & MC_CGM_MUX_3_CSS_SWIP_MASK)

#define MC_CGM_MUX_3_CSS_SWTRG_MASK              (0xE0000U)
#define MC_CGM_MUX_3_CSS_SWTRG_SHIFT             (17U)
/*! SWTRG - Switch trigger cause
 *  0b000..
 *  0b001..Switch after request succeeded.
 *  0b010..Switch after the request failed because of an inactive target clock and the current clock is FIRC.
 *  0b011..Switch after the request failed because of an inactive current clock and the current clock is FIRC.
 *  0b100..Switch to FIRC because of a safe clock request or reset succeeded.
 *  0b101..Switch to FIRC because of a safe clock request or reset succeeded, but the previous current clock source was inactive.
 *  0b110..
 *  0b111..
 */
#define MC_CGM_MUX_3_CSS_SWTRG(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_3_CSS_SWTRG_SHIFT)) & MC_CGM_MUX_3_CSS_SWTRG_MASK)

#define MC_CGM_MUX_3_CSS_SELSTAT_MASK            (0x1F000000U)
#define MC_CGM_MUX_3_CSS_SELSTAT_SHIFT           (24U)
/*! SELSTAT - Clock source selection status
 *  0b00000..FIRC
 *  0b00010..FXOSC
 *  0b10110..AIPS_PLAT_CLK
 */
#define MC_CGM_MUX_3_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_3_CSS_SELSTAT_SHIFT)) & MC_CGM_MUX_3_CSS_SELSTAT_MASK)
/*! @} */

/*! @name MUX_3_DC_0 - Clock Mux 3 Divider 0 Control Register */
/*! @{ */

#define MC_CGM_MUX_3_DC_0_DIV_MASK               (0x30000U)
#define MC_CGM_MUX_3_DC_0_DIV_SHIFT              (16U)
/*! DIV - Division value */
#define MC_CGM_MUX_3_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_3_DC_0_DIV_SHIFT)) & MC_CGM_MUX_3_DC_0_DIV_MASK)

#define MC_CGM_MUX_3_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_MUX_3_DC_0_DE_SHIFT               (31U)
/*! DE - Divider enable
 *  0b0..Divider is disabled.
 *  0b1..Divider is enabled.
 */
#define MC_CGM_MUX_3_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_3_DC_0_DE_SHIFT)) & MC_CGM_MUX_3_DC_0_DE_MASK)
/*! @} */

/*! @name MUX_3_DIV_UPD_STAT - Clock Mux 3 Divider Update Status Register */
/*! @{ */

#define MC_CGM_MUX_3_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_MUX_3_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
/*! DIV_STAT - Divider status for clock mux 3
 *  0b0..No divider configuration update is pending.
 *  0b1..Divider configuration update on at least one divider associated with this multiplexer is pending.
 */
#define MC_CGM_MUX_3_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_3_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_MUX_3_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name MUX_5_CSC - Clock Mux 5 Select Control Register */
/*! @{ */

#define MC_CGM_MUX_5_CSC_CG_MASK                 (0x4U)
#define MC_CGM_MUX_5_CSC_CG_SHIFT                (2U)
/*! CG - Clock gate */
#define MC_CGM_MUX_5_CSC_CG(x)                   (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_5_CSC_CG_SHIFT)) & MC_CGM_MUX_5_CSC_CG_MASK)

#define MC_CGM_MUX_5_CSC_FCG_MASK                (0x8U)
#define MC_CGM_MUX_5_CSC_FCG_SHIFT               (3U)
/*! FCG - Force clock gate */
#define MC_CGM_MUX_5_CSC_FCG(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_5_CSC_FCG_SHIFT)) & MC_CGM_MUX_5_CSC_FCG_MASK)

#define MC_CGM_MUX_5_CSC_SELCTL_MASK             (0x3F000000U)
#define MC_CGM_MUX_5_CSC_SELCTL_SHIFT            (24U)
/*! SELCTL - Clock source selection control
 *  0b000000..FIRC
 *  0b000001..SIRC
 *  0b000010..FXOSC
 *  0b010111..AIPS_SLOW_CLK
 *  0b110010..Reserved
 */
#define MC_CGM_MUX_5_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_5_CSC_SELCTL_SHIFT)) & MC_CGM_MUX_5_CSC_SELCTL_MASK)
/*! @} */

/*! @name MUX_5_CSS - Clock Mux 5 Select Status Register */
/*! @{ */

#define MC_CGM_MUX_5_CSS_GRIP_MASK               (0x10000U)
#define MC_CGM_MUX_5_CSS_GRIP_SHIFT              (16U)
/*! GRIP - Gating request is in progress.
 *  0b0..Clock source gating or ungating has completed.
 *  0b1..Clock source gating or ungating is in progress.
 */
#define MC_CGM_MUX_5_CSS_GRIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_5_CSS_GRIP_SHIFT)) & MC_CGM_MUX_5_CSS_GRIP_MASK)

#define MC_CGM_MUX_5_CSS_CS_MASK                 (0x20000U)
#define MC_CGM_MUX_5_CSS_CS_SHIFT                (17U)
/*! CS - Clock status
 *  0b0..Clock is gated to logic-0 at output of clock mux
 *  0b1..Clock mux is transparent. Active clock pulses at input of clock mux results in same number of pulses at its output
 */
#define MC_CGM_MUX_5_CSS_CS(x)                   (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_5_CSS_CS_SHIFT)) & MC_CGM_MUX_5_CSS_CS_MASK)

#define MC_CGM_MUX_5_CSS_SELSTAT_MASK            (0x3F000000U)
#define MC_CGM_MUX_5_CSS_SELSTAT_SHIFT           (24U)
/*! SELSTAT - Clock source selection status
 *  0b000000..FIRC
 *  0b000001..SIRC
 *  0b000010..FXOSC
 *  0b010111..AIPS_SLOW_CLK
 *  0b110010..Reserved
 */
#define MC_CGM_MUX_5_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_5_CSS_SELSTAT_SHIFT)) & MC_CGM_MUX_5_CSS_SELSTAT_MASK)
/*! @} */

/*! @name MUX_5_DC_0 - Clock Mux 5 Divider 0 Control Register */
/*! @{ */

#define MC_CGM_MUX_5_DC_0_DIV_MASK               (0x70000U)
#define MC_CGM_MUX_5_DC_0_DIV_SHIFT              (16U)
/*! DIV - Division value */
#define MC_CGM_MUX_5_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_5_DC_0_DIV_SHIFT)) & MC_CGM_MUX_5_DC_0_DIV_MASK)

#define MC_CGM_MUX_5_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_MUX_5_DC_0_DE_SHIFT               (31U)
/*! DE - Divider enable
 *  0b0..Divider is disabled.
 *  0b1..Divider is enabled.
 */
#define MC_CGM_MUX_5_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_5_DC_0_DE_SHIFT)) & MC_CGM_MUX_5_DC_0_DE_MASK)
/*! @} */

/*! @name MUX_5_DIV_UPD_STAT - Clock Mux 5 Divider Update Status Register */
/*! @{ */

#define MC_CGM_MUX_5_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_MUX_5_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
/*! DIV_STAT - Divider status for clock mux 5
 *  0b0..No divider configuration update is pending.
 *  0b1..Divider configuration update on at least one divider associated with this multiplexer is pending.
 */
#define MC_CGM_MUX_5_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_5_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_MUX_5_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name MUX_6_CSC - Clock Mux 6 Select Control Register */
/*! @{ */

#define MC_CGM_MUX_6_CSC_CG_MASK                 (0x4U)
#define MC_CGM_MUX_6_CSC_CG_SHIFT                (2U)
/*! CG - Clock gate */
#define MC_CGM_MUX_6_CSC_CG(x)                   (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_6_CSC_CG_SHIFT)) & MC_CGM_MUX_6_CSC_CG_MASK)

#define MC_CGM_MUX_6_CSC_FCG_MASK                (0x8U)
#define MC_CGM_MUX_6_CSC_FCG_SHIFT               (3U)
/*! FCG - Force clock gate */
#define MC_CGM_MUX_6_CSC_FCG(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_6_CSC_FCG_SHIFT)) & MC_CGM_MUX_6_CSC_FCG_MASK)

#define MC_CGM_MUX_6_CSC_SELCTL_MASK             (0x3F000000U)
#define MC_CGM_MUX_6_CSC_SELCTL_SHIFT            (24U)
/*! SELCTL - Clock source selection control
 *  0b000000..FIRC
 *  0b000001..SIRC
 *  0b000010..FXOSC
 *  0b001000..PLL_PHI0_CLK
 *  0b001001..PLL_PHI1_CLK
 *  0b010000..CORE_CLK
 *  0b010011..HSE_CLK
 *  0b010110..AIPS_PLAT_CLK
 *  0b010111..AIPS_SLOW_CLK
 *  0b011010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 */
#define MC_CGM_MUX_6_CSC_SELCTL(x)               (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_6_CSC_SELCTL_SHIFT)) & MC_CGM_MUX_6_CSC_SELCTL_MASK)
/*! @} */

/*! @name MUX_6_CSS - Clock Mux 6 Select Status Register */
/*! @{ */

#define MC_CGM_MUX_6_CSS_GRIP_MASK               (0x10000U)
#define MC_CGM_MUX_6_CSS_GRIP_SHIFT              (16U)
/*! GRIP - Gating request is in progress.
 *  0b0..Clock source gating or ungating has completed.
 *  0b1..Clock source gating or ungating is in progress.
 */
#define MC_CGM_MUX_6_CSS_GRIP(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_6_CSS_GRIP_SHIFT)) & MC_CGM_MUX_6_CSS_GRIP_MASK)

#define MC_CGM_MUX_6_CSS_CS_MASK                 (0x20000U)
#define MC_CGM_MUX_6_CSS_CS_SHIFT                (17U)
/*! CS - Clock status
 *  0b0..Clock is gated to logic-0 at output of clock mux
 *  0b1..Clock mux is transparent. Active clock pulses at input of clock mux results in same number of pulses at its output
 */
#define MC_CGM_MUX_6_CSS_CS(x)                   (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_6_CSS_CS_SHIFT)) & MC_CGM_MUX_6_CSS_CS_MASK)

#define MC_CGM_MUX_6_CSS_SELSTAT_MASK            (0x3F000000U)
#define MC_CGM_MUX_6_CSS_SELSTAT_SHIFT           (24U)
/*! SELSTAT - Clock source selection status
 *  0b000000..FIRC
 *  0b000001..SIRC
 *  0b000010..FXOSC
 *  0b001000..PLL_PHI0_CLK
 *  0b001001..PLL_PHI1_CLK
 *  0b010000..CORE_CLK
 *  0b010011..HSE_CLK
 *  0b010110..AIPS_PLAT_CLK
 *  0b010111..AIPS_SLOW_CLK
 *  0b011010..Reserved
 *  0b110011..Reserved
 *  0b110100..Reserved
 *  0b110101..Reserved
 *  0b111000..Reserved
 *  0b111001..Reserved
 *  0b111010..Reserved
 *  0b111011..Reserved
 *  0b111100..Reserved
 *  0b111101..Reserved
 */
#define MC_CGM_MUX_6_CSS_SELSTAT(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_6_CSS_SELSTAT_SHIFT)) & MC_CGM_MUX_6_CSS_SELSTAT_MASK)
/*! @} */

/*! @name MUX_6_DC_0 - Clock Mux 6 Divider 0 Control Register */
/*! @{ */

#define MC_CGM_MUX_6_DC_0_DIV_MASK               (0x3F0000U)
#define MC_CGM_MUX_6_DC_0_DIV_SHIFT              (16U)
/*! DIV - Division value */
#define MC_CGM_MUX_6_DC_0_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_6_DC_0_DIV_SHIFT)) & MC_CGM_MUX_6_DC_0_DIV_MASK)

#define MC_CGM_MUX_6_DC_0_DE_MASK                (0x80000000U)
#define MC_CGM_MUX_6_DC_0_DE_SHIFT               (31U)
/*! DE - Divider enable
 *  0b0..Divider is disabled.
 *  0b1..Divider is enabled.
 */
#define MC_CGM_MUX_6_DC_0_DE(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_6_DC_0_DE_SHIFT)) & MC_CGM_MUX_6_DC_0_DE_MASK)
/*! @} */

/*! @name MUX_6_DIV_UPD_STAT - Clock Mux 6 Divider Update Status Register */
/*! @{ */

#define MC_CGM_MUX_6_DIV_UPD_STAT_DIV_STAT_MASK  (0x1U)
#define MC_CGM_MUX_6_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
/*! DIV_STAT - Divider status for clock mux 6
 *  0b0..No divider configuration update is pending.
 *  0b1..Divider configuration update on at least one divider associated with this multiplexer is pending.
 */
#define MC_CGM_MUX_6_DIV_UPD_STAT_DIV_STAT(x)    (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_6_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_MUX_6_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */

/*! @name MUX_11_CSC - Clock Mux 11 Select Control Register */
/*! @{ */

#define MC_CGM_MUX_11_CSC_CG_MASK                (0x4U)
#define MC_CGM_MUX_11_CSC_CG_SHIFT               (2U)
/*! CG - Clock gate */
#define MC_CGM_MUX_11_CSC_CG(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_11_CSC_CG_SHIFT)) & MC_CGM_MUX_11_CSC_CG_MASK)

#define MC_CGM_MUX_11_CSC_FCG_MASK               (0x8U)
#define MC_CGM_MUX_11_CSC_FCG_SHIFT              (3U)
/*! FCG - Force clock gate */
#define MC_CGM_MUX_11_CSC_FCG(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_11_CSC_FCG_SHIFT)) & MC_CGM_MUX_11_CSC_FCG_MASK)

#define MC_CGM_MUX_11_CSC_SELCTL_MASK            (0xF000000U)
#define MC_CGM_MUX_11_CSC_SELCTL_SHIFT           (24U)
/*! SELCTL - Clock source selection control
 *  0b0000..FIRC
 *  0b0010..FXOSC
 *  0b1000..PLL_PHI0_CLK
 *  0b1001..PLL_PHI1_CLK
 */
#define MC_CGM_MUX_11_CSC_SELCTL(x)              (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_11_CSC_SELCTL_SHIFT)) & MC_CGM_MUX_11_CSC_SELCTL_MASK)
/*! @} */

/*! @name MUX_11_CSS - Clock Mux 11 Select Status Register */
/*! @{ */

#define MC_CGM_MUX_11_CSS_GRIP_MASK              (0x10000U)
#define MC_CGM_MUX_11_CSS_GRIP_SHIFT             (16U)
/*! GRIP - Gating request is in progress.
 *  0b0..Clock source gating or ungating has completed.
 *  0b1..Clock source gating or ungating is in progress.
 */
#define MC_CGM_MUX_11_CSS_GRIP(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_11_CSS_GRIP_SHIFT)) & MC_CGM_MUX_11_CSS_GRIP_MASK)

#define MC_CGM_MUX_11_CSS_CS_MASK                (0x20000U)
#define MC_CGM_MUX_11_CSS_CS_SHIFT               (17U)
/*! CS - Clock status
 *  0b0..Clock is gated to logic-0 at output of clock mux
 *  0b1..Clock mux is transparent. Active clock pulses at input of clock mux results in same number of pulses at its output
 */
#define MC_CGM_MUX_11_CSS_CS(x)                  (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_11_CSS_CS_SHIFT)) & MC_CGM_MUX_11_CSS_CS_MASK)

#define MC_CGM_MUX_11_CSS_SELSTAT_MASK           (0xF000000U)
#define MC_CGM_MUX_11_CSS_SELSTAT_SHIFT          (24U)
/*! SELSTAT - Clock source selection status
 *  0b0000..FIRC
 *  0b0010..FXOSC
 *  0b1000..PLL_PHI0_CLK
 *  0b1001..PLL_PHI1_CLK
 */
#define MC_CGM_MUX_11_CSS_SELSTAT(x)             (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_11_CSS_SELSTAT_SHIFT)) & MC_CGM_MUX_11_CSS_SELSTAT_MASK)
/*! @} */

/*! @name MUX_11_DC_0 - Clock Mux 11 Divider 0 Control Register */
/*! @{ */

#define MC_CGM_MUX_11_DC_0_DIV_MASK              (0x70000U)
#define MC_CGM_MUX_11_DC_0_DIV_SHIFT             (16U)
/*! DIV - Division value */
#define MC_CGM_MUX_11_DC_0_DIV(x)                (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_11_DC_0_DIV_SHIFT)) & MC_CGM_MUX_11_DC_0_DIV_MASK)

#define MC_CGM_MUX_11_DC_0_DE_MASK               (0x80000000U)
#define MC_CGM_MUX_11_DC_0_DE_SHIFT              (31U)
/*! DE - Divider enable
 *  0b0..Divider is disabled.
 *  0b1..Divider is enabled.
 */
#define MC_CGM_MUX_11_DC_0_DE(x)                 (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_11_DC_0_DE_SHIFT)) & MC_CGM_MUX_11_DC_0_DE_MASK)
/*! @} */

/*! @name MUX_11_DIV_UPD_STAT - Clock Mux 11 Divider Update Status Register */
/*! @{ */

#define MC_CGM_MUX_11_DIV_UPD_STAT_DIV_STAT_MASK (0x1U)
#define MC_CGM_MUX_11_DIV_UPD_STAT_DIV_STAT_SHIFT (0U)
/*! DIV_STAT - Divider status for clock mux 11
 *  0b0..No divider configuration update is pending.
 *  0b1..Divider configuration update on at least one divider associated with this multiplexer is pending.
 */
#define MC_CGM_MUX_11_DIV_UPD_STAT_DIV_STAT(x)   (((uint32_t)(((uint32_t)(x)) << MC_CGM_MUX_11_DIV_UPD_STAT_DIV_STAT_SHIFT)) & MC_CGM_MUX_11_DIV_UPD_STAT_DIV_STAT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MC_CGM_Register_Masks */


/*!
 * @}
 */ /* end of group MC_CGM_Peripheral_Access_Layer */


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


#endif  /* PERI_MC_CGM_H_ */

