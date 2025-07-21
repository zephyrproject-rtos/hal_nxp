/*
** ###################################################################
**     Processors:          MCXL253VDF_cm0plus
**                          MCXL253VDF_cm33
**                          MCXL253VLL_cm0plus
**                          MCXL253VLL_cm33
**                          MCXL254VDF_cm0plus
**                          MCXL254VDF_cm33
**                          MCXL254VLL_cm0plus
**                          MCXL254VLL_cm33
**                          MCXL255VDF_cm0plus
**                          MCXL255VDF_cm33
**                          MCXL255VLL_cm0plus
**                          MCXL255VLL_cm33
**
**     Version:             rev. 1.0, 2023-01-09
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CGU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-09)
**         Generated based on Rev1 DraftI.
**
** ###################################################################
*/

/*!
 * @file PERI_CGU.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for CGU
 *
 * CMSIS Peripheral Access Layer for CGU
 */

#if !defined(PERI_CGU_H_)
#define PERI_CGU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXL253VDF_cm0plus) || defined(CPU_MCXL253VLL_cm0plus))
#include "MCXL253_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL253VDF_cm33) || defined(CPU_MCXL253VLL_cm33))
#include "MCXL253_cm33_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm0plus) || defined(CPU_MCXL254VLL_cm0plus))
#include "MCXL254_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm33) || defined(CPU_MCXL254VLL_cm33))
#include "MCXL254_cm33_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm0plus) || defined(CPU_MCXL255VLL_cm0plus))
#include "MCXL255_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm33) || defined(CPU_MCXL255VLL_cm33))
#include "MCXL255_cm33_COMMON.h"
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
   -- CGU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CGU_Peripheral_Access_Layer CGU Peripheral Access Layer
 * @{
 */

/** CGU - Register Layout Typedef */
typedef struct {
  __IO uint32_t CLK_CONFIG;                        /**< AON Clock Configuration, offset: 0x0 */
  __IO uint32_t PER_CLK_CONFIG;                    /**< Peripheral Clock Enable, offset: 0x4 */
  __IO uint32_t CLOCK_DIV;                         /**< Clock Divider, offset: 0x8 */
  __IO uint32_t PER_CLK_EN;                        /**< Peripheral Clock Enable, offset: 0xC */
  __IO uint32_t RST_SUB_BLK;                       /**< Reset Subsystem Blocks, offset: 0x10 */
       uint8_t RESERVED_0[28];
  __IO uint32_t FRO10M_CONFIG;                     /**< FRO10M Configuration, offset: 0x30 */
  __IO uint32_t FRO10M_TRIM;                       /**< FRO10M Trim, offset: 0x34 */
       uint8_t RESERVED_1[4];
  __IO uint32_t FRO2M_CONFIG;                      /**< FRO2M Configuration, offset: 0x3C */
  __IO uint32_t FRO2M_TRIM;                        /**< FRO2M_TRIM, offset: 0x40 */
  __IO uint32_t ACMP_CLK_DIV;                      /**< ACMP Clock Divider, offset: 0x44 */
  __IO uint32_t INT;                               /**< Interrupt Flag, offset: 0x48 */
} CGU_Type;

/* ----------------------------------------------------------------------------
   -- CGU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CGU_Register_Masks CGU Register Masks
 * @{
 */

/*! @name CLK_CONFIG - AON Clock Configuration */
/*! @{ */

#define CGU_CLK_CONFIG_FRO10M_EN_MASK            (0x1U)
#define CGU_CLK_CONFIG_FRO10M_EN_SHIFT           (0U)
/*! FRO10M_EN - FRO10M Power Clock Enable
 *  0b0..Disable
 *  0b1..Enable the clock.
 */
#define CGU_CLK_CONFIG_FRO10M_EN(x)              (((uint32_t)(((uint32_t)(x)) << CGU_CLK_CONFIG_FRO10M_EN_SHIFT)) & CGU_CLK_CONFIG_FRO10M_EN_MASK)

#define CGU_CLK_CONFIG_SEL_MODE_MASK             (0x2U)
#define CGU_CLK_CONFIG_SEL_MODE_SHIFT            (1U)
/*! SEL_MODE - Select Mode.
 *  0b0..10 MHz
 *  0b1..2 MHz
 */
#define CGU_CLK_CONFIG_SEL_MODE(x)               (((uint32_t)(((uint32_t)(x)) << CGU_CLK_CONFIG_SEL_MODE_SHIFT)) & CGU_CLK_CONFIG_SEL_MODE_MASK)

#define CGU_CLK_CONFIG_ROOT_CLK_SEL_MASK         (0xCU)
#define CGU_CLK_CONFIG_ROOT_CLK_SEL_SHIFT        (2U)
/*! ROOT_CLK_SEL - Root Clock Select
 *  0b00..Option between 10.0 MHz or 2.0 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        10.0 MHz and if FRO2M is used then the clock will be 2.0 MHz.
 *  0b01..Option between 5.0 MHz or 1.0 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        5.0 MHz and if FRO2M is used then the clock will be 1.0 MHz.
 *  0b10..Option between 2.5 MHz or 0.5 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        2.5 MHz and if FRO2M is used then the clock will be 0.5 MHz.
 *  0b11..32 kHz
 */
#define CGU_CLK_CONFIG_ROOT_CLK_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CGU_CLK_CONFIG_ROOT_CLK_SEL_SHIFT)) & CGU_CLK_CONFIG_ROOT_CLK_SEL_MASK)

#define CGU_CLK_CONFIG_ROOT_AUX_CLK_SEL_MASK     (0x10U)
#define CGU_CLK_CONFIG_ROOT_AUX_CLK_SEL_SHIFT    (4U)
/*! ROOT_AUX_CLK_SEL - Root AUX Clock Select
 *  0b0..32 kHz
 *  0b1..aon_aux_clk
 */
#define CGU_CLK_CONFIG_ROOT_AUX_CLK_SEL(x)       (((uint32_t)(((uint32_t)(x)) << CGU_CLK_CONFIG_ROOT_AUX_CLK_SEL_SHIFT)) & CGU_CLK_CONFIG_ROOT_AUX_CLK_SEL_MASK)

#define CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_MASK      (0x20U)
#define CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_SHIFT     (5U)
/*! ROOT_AUX_CLK_EN - Root AUX Clock Enable */
#define CGU_CLK_CONFIG_ROOT_AUX_CLK_EN(x)        (((uint32_t)(((uint32_t)(x)) << CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_SHIFT)) & CGU_CLK_CONFIG_ROOT_AUX_CLK_EN_MASK)

#define CGU_CLK_CONFIG_XTAL32_OUT_EN_MASK        (0x40U)
#define CGU_CLK_CONFIG_XTAL32_OUT_EN_SHIFT       (6U)
/*! XTAL32_OUT_EN - XTAL32 Output Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_CLK_CONFIG_XTAL32_OUT_EN(x)          (((uint32_t)(((uint32_t)(x)) << CGU_CLK_CONFIG_XTAL32_OUT_EN_SHIFT)) & CGU_CLK_CONFIG_XTAL32_OUT_EN_MASK)

#define CGU_CLK_CONFIG_SRAM_CG_OVERRIDE_MASK     (0x80U)
#define CGU_CLK_CONFIG_SRAM_CG_OVERRIDE_SHIFT    (7U)
/*! SRAM_CG_OVERRIDE - SRAM Clock Gating Override
 *  0b0..No override of the clock gating feature
 *  0b1..Clock gating feature is overridden, SRAM clock always enabled.
 */
#define CGU_CLK_CONFIG_SRAM_CG_OVERRIDE(x)       (((uint32_t)(((uint32_t)(x)) << CGU_CLK_CONFIG_SRAM_CG_OVERRIDE_SHIFT)) & CGU_CLK_CONFIG_SRAM_CG_OVERRIDE_MASK)

#define CGU_CLK_CONFIG_FRO2M_EN_MASK             (0x100U)
#define CGU_CLK_CONFIG_FRO2M_EN_SHIFT            (8U)
/*! FRO2M_EN - FRO2M Enable
 *  0b0..Disable
 *  0b1..Enable the clock.
 */
#define CGU_CLK_CONFIG_FRO2M_EN(x)               (((uint32_t)(((uint32_t)(x)) << CGU_CLK_CONFIG_FRO2M_EN_SHIFT)) & CGU_CLK_CONFIG_FRO2M_EN_MASK)
/*! @} */

/*! @name PER_CLK_CONFIG - Peripheral Clock Enable */
/*! @{ */

#define CGU_PER_CLK_CONFIG_COM_GRP_SEL_MASK      (0x3U)
#define CGU_PER_CLK_CONFIG_COM_GRP_SEL_SHIFT     (0U)
/*! COM_GRP_SEL - Comparator Group Select
 *  0b00..Option between 10.0 MHz or 2.0 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        10.0 MHz and if FRO2M is used then the clock will be 2.0 MHz.
 *  0b01..Option between 5.0 MHz or 1.0 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        5.0 MHz and if FRO2M is used then the clock will be 1.0 MHz.
 *  0b10..Option between 2.5 MHz or 0.5 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        2.5 MHz and if FRO2M is used then the clock will be 0.5 MHz.
 *  0b11..32 kHz
 */
#define CGU_PER_CLK_CONFIG_COM_GRP_SEL(x)        (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_COM_GRP_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_COM_GRP_SEL_MASK)

#define CGU_PER_CLK_CONFIG_TMR_GRP_SEL_MASK      (0xCU)
#define CGU_PER_CLK_CONFIG_TMR_GRP_SEL_SHIFT     (2U)
/*! TMR_GRP_SEL - Timer Group Select
 *  0b00..Option between 10.0 MHz or 2.0 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        10.0 MHz and if FRO2M is used then the clock will be 2.0 MHz.
 *  0b01..Option between 5.0 MHz or 1.0 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        5.0 MHz and if FRO2M is used then the clock will be 1.0 MHz.
 *  0b10..Option between 2.5 MHz or 0.5 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        2.5 MHz and if FRO2M is used then the clock will be 0.5 MHz.
 *  0b11..32 kHz
 */
#define CGU_PER_CLK_CONFIG_TMR_GRP_SEL(x)        (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_TMR_GRP_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_TMR_GRP_SEL_MASK)

#define CGU_PER_CLK_CONFIG_LPTMR_GRP_SEL_MASK    (0x30U)
#define CGU_PER_CLK_CONFIG_LPTMR_GRP_SEL_SHIFT   (4U)
/*! LPTMR_GRP_SEL - Low-Power Timer Group Select
 *  0b00..aon_timer_clk
 *  0b01..fro16K
 *  0b10..16K_clk
 *  0b11..Empty
 */
#define CGU_PER_CLK_CONFIG_LPTMR_GRP_SEL(x)      (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_LPTMR_GRP_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_LPTMR_GRP_SEL_MASK)

#define CGU_PER_CLK_CONFIG_KPP_CLK_SEL_MASK      (0x40U)
#define CGU_PER_CLK_CONFIG_KPP_CLK_SEL_SHIFT     (6U)
/*! KPP_CLK_SEL - KPP Clock Select
 *  0b0..Xtal 32 kHz.
 *  0b1..fro16K
 */
#define CGU_PER_CLK_CONFIG_KPP_CLK_SEL(x)        (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_KPP_CLK_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_KPP_CLK_SEL_MASK)

#define CGU_PER_CLK_CONFIG_AON_SYS_CLK_SEL_MASK  (0x180U)
#define CGU_PER_CLK_CONFIG_AON_SYS_CLK_SEL_SHIFT (7U)
/*! AON_SYS_CLK_SEL - AON System Clock Select
 *  0b00..Option between 10.0 MHz or 2.0 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        10.0 MHz and if FRO2M is used then the clock will be 2.0 MHz.
 *  0b01..Option between 5.0 MHz or 1.0 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        5.0 MHz and if FRO2M is used then clock will be 1.0 MHz.
 *  0b10..Option between 2.5 MHz or 0.5 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        2.5 MHz and if FRO2M is used then the clock will be 0.5 MHz.
 *  0b11..Empty
 */
#define CGU_PER_CLK_CONFIG_AON_SYS_CLK_SEL(x)    (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_AON_SYS_CLK_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_AON_SYS_CLK_SEL_MASK)

#define CGU_PER_CLK_CONFIG_LPADC_CLK_SEL_MASK    (0xE00U)
#define CGU_PER_CLK_CONFIG_LPADC_CLK_SEL_SHIFT   (9U)
/*! LPADC_CLK_SEL - LPADC Clock Select
 *  0b000..Option between 10.0 MHz or 2.0 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *         10.0 MHz and if FRO2M is used then the clock will be 2.0 MHz.
 *  0b001..Option between 5.0 MHz or 1.0 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *         5.0 MHz and if FRO2M is used then the clock will be 1.0 MHz.
 *  0b010..Option between 2.5 MHz or 0.5 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *         2.5 MHz and if FRO2M is used then the clock will be 0.5 MHz.
 *  0b011..Option between 32 kHz clock (from RTC) or aon_aux_clk based on the selected FRO, if FRO10M is used then
 *         clock will be aon_aux_clk and if FRO2M is used then clock will be aon_aux_clk.
 *  0b100..XTAL 32 K
 *  0b101..FRO16K
 *  0b110..Empty
 *  0b111..Empty
 */
#define CGU_PER_CLK_CONFIG_LPADC_CLK_SEL(x)      (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_LPADC_CLK_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_LPADC_CLK_SEL_MASK)

#define CGU_PER_CLK_CONFIG_LCD_CLK_SEL_MASK      (0x1000U)
#define CGU_PER_CLK_CONFIG_LCD_CLK_SEL_SHIFT     (12U)
/*! LCD_CLK_SEL - LCD Clock Select
 *  0b0..clk_16K
 *  0b1..fro16K
 */
#define CGU_PER_CLK_CONFIG_LCD_CLK_SEL(x)        (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_LCD_CLK_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_LCD_CLK_SEL_MASK)

#define CGU_PER_CLK_CONFIG_ACMP0_CLK_SEL_MASK    (0x6000U)
#define CGU_PER_CLK_CONFIG_ACMP0_CLK_SEL_SHIFT   (13U)
/*! ACMP0_CLK_SEL - ACMP0 clock mux select
 *  0b00..Option between 10.0 MHz or 2.0 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        10.0 MHz and if FRO2M is used then the clock will be 2.0 MHz.
 *  0b01..Option between 5.0 MHz or 1.0 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        5.0 MHz and if FRO2M is used then the clock will be 1.0 MHz.
 *  0b10..Option between 2.5 MHz or 0.5 MHz based on the selected FRO, if FRO10M is used then the clock will be
 *        2.5 MHz and if FRO2M is used then the clock will be 0.5 MHz.
 *  0b11..fro16K
 */
#define CGU_PER_CLK_CONFIG_ACMP0_CLK_SEL(x)      (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_ACMP0_CLK_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_ACMP0_CLK_SEL_MASK)
/*! @} */

/*! @name CLOCK_DIV - Clock Divider */
/*! @{ */

#define CGU_CLOCK_DIV_CLK_DIV_EN_MASK            (0x1U)
#define CGU_CLOCK_DIV_CLK_DIV_EN_SHIFT           (0U)
/*! CLK_DIV_EN - Clock Divider Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_CLOCK_DIV_CLK_DIV_EN(x)              (((uint32_t)(((uint32_t)(x)) << CGU_CLOCK_DIV_CLK_DIV_EN_SHIFT)) & CGU_CLOCK_DIV_CLK_DIV_EN_MASK)

#define CGU_CLOCK_DIV_COM_GRP_CLK_EN_MASK        (0x2U)
#define CGU_CLOCK_DIV_COM_GRP_CLK_EN_SHIFT       (1U)
/*! COM_GRP_CLK_EN - Comparator Group Clock Divider Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_CLOCK_DIV_COM_GRP_CLK_EN(x)          (((uint32_t)(((uint32_t)(x)) << CGU_CLOCK_DIV_COM_GRP_CLK_EN_SHIFT)) & CGU_CLOCK_DIV_COM_GRP_CLK_EN_MASK)

#define CGU_CLOCK_DIV_SYS_CLK_DIV_EN_MASK        (0x4U)
#define CGU_CLOCK_DIV_SYS_CLK_DIV_EN_SHIFT       (2U)
/*! SYS_CLK_DIV_EN - SysTic Clock Divider Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_CLOCK_DIV_SYS_CLK_DIV_EN(x)          (((uint32_t)(((uint32_t)(x)) << CGU_CLOCK_DIV_SYS_CLK_DIV_EN_SHIFT)) & CGU_CLOCK_DIV_SYS_CLK_DIV_EN_MASK)

#define CGU_CLOCK_DIV_AONCPU_CLK_DIV_MASK        (0x38U)
#define CGU_CLOCK_DIV_AONCPU_CLK_DIV_SHIFT       (3U)
/*! AONCPU_CLK_DIV - AON CPU Clock Divider */
#define CGU_CLOCK_DIV_AONCPU_CLK_DIV(x)          (((uint32_t)(((uint32_t)(x)) << CGU_CLOCK_DIV_AONCPU_CLK_DIV_SHIFT)) & CGU_CLOCK_DIV_AONCPU_CLK_DIV_MASK)

#define CGU_CLOCK_DIV_COM_GRP_CLK_DIV_MASK       (0x1C0U)
#define CGU_CLOCK_DIV_COM_GRP_CLK_DIV_SHIFT      (6U)
/*! COM_GRP_CLK_DIV - Comparator Group Clock Divider */
#define CGU_CLOCK_DIV_COM_GRP_CLK_DIV(x)         (((uint32_t)(((uint32_t)(x)) << CGU_CLOCK_DIV_COM_GRP_CLK_DIV_SHIFT)) & CGU_CLOCK_DIV_COM_GRP_CLK_DIV_MASK)

#define CGU_CLOCK_DIV_AON_SYS_CLK_DIV_MASK       (0xE00U)
#define CGU_CLOCK_DIV_AON_SYS_CLK_DIV_SHIFT      (9U)
/*! AON_SYS_CLK_DIV - AON SysTic Clock Divider */
#define CGU_CLOCK_DIV_AON_SYS_CLK_DIV(x)         (((uint32_t)(((uint32_t)(x)) << CGU_CLOCK_DIV_AON_SYS_CLK_DIV_SHIFT)) & CGU_CLOCK_DIV_AON_SYS_CLK_DIV_MASK)
/*! @} */

/*! @name PER_CLK_EN - Peripheral Clock Enable */
/*! @{ */

#define CGU_PER_CLK_EN_UART_CLK_MASK             (0x1U)
#define CGU_PER_CLK_EN_UART_CLK_SHIFT            (0U)
/*! UART_CLK - UART Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_UART_CLK(x)               (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_UART_CLK_SHIFT)) & CGU_PER_CLK_EN_UART_CLK_MASK)

#define CGU_PER_CLK_EN_I2C_CLK_MASK              (0x2U)
#define CGU_PER_CLK_EN_I2C_CLK_SHIFT             (1U)
/*! I2C_CLK - I2C Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_I2C_CLK(x)                (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_I2C_CLK_SHIFT)) & CGU_PER_CLK_EN_I2C_CLK_MASK)

#define CGU_PER_CLK_EN_APB_CLK_MASK              (0x4U)
#define CGU_PER_CLK_EN_APB_CLK_SHIFT             (2U)
/*! APB_CLK - APB Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_APB_CLK(x)                (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_APB_CLK_SHIFT)) & CGU_PER_CLK_EN_APB_CLK_MASK)

#define CGU_PER_CLK_EN_STP_ALL_CLK_MASK          (0x8U)
#define CGU_PER_CLK_EN_STP_ALL_CLK_SHIFT         (3U)
/*! STP_ALL_CLK - Stop All Clocks.
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_STP_ALL_CLK(x)            (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_STP_ALL_CLK_SHIFT)) & CGU_PER_CLK_EN_STP_ALL_CLK_MASK)

#define CGU_PER_CLK_EN_SLEEP_OVRD_MASK           (0x10U)
#define CGU_PER_CLK_EN_SLEEP_OVRD_SHIFT          (4U)
/*! SLEEP_OVRD - Sleeping Override
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_SLEEP_OVRD(x)             (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_SLEEP_OVRD_SHIFT)) & CGU_PER_CLK_EN_SLEEP_OVRD_MASK)

#define CGU_PER_CLK_EN_PORT_CLK_EN_MASK          (0x20U)
#define CGU_PER_CLK_EN_PORT_CLK_EN_SHIFT         (5U)
/*! PORT_CLK_EN - Port Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_PORT_CLK_EN(x)            (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_PORT_CLK_EN_SHIFT)) & CGU_PER_CLK_EN_PORT_CLK_EN_MASK)

#define CGU_PER_CLK_EN_GPIO_CLK_EN_MASK          (0x40U)
#define CGU_PER_CLK_EN_GPIO_CLK_EN_SHIFT         (6U)
/*! GPIO_CLK_EN - GPIO Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_GPIO_CLK_EN(x)            (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_GPIO_CLK_EN_SHIFT)) & CGU_PER_CLK_EN_GPIO_CLK_EN_MASK)

#define CGU_PER_CLK_EN_QTMR0_CLK_EN_MASK         (0x80U)
#define CGU_PER_CLK_EN_QTMR0_CLK_EN_SHIFT        (7U)
/*! QTMR0_CLK_EN - Qtimer0 Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_QTMR0_CLK_EN(x)           (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_QTMR0_CLK_EN_SHIFT)) & CGU_PER_CLK_EN_QTMR0_CLK_EN_MASK)

#define CGU_PER_CLK_EN_LPTMR_CLK_EN_MASK         (0x200U)
#define CGU_PER_CLK_EN_LPTMR_CLK_EN_SHIFT        (9U)
/*! LPTMR_CLK_EN - LPTMR Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_LPTMR_CLK_EN(x)           (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_LPTMR_CLK_EN_SHIFT)) & CGU_PER_CLK_EN_LPTMR_CLK_EN_MASK)

#define CGU_PER_CLK_EN_KPP_CLK_EN_MASK           (0x400U)
#define CGU_PER_CLK_EN_KPP_CLK_EN_SHIFT          (10U)
/*! KPP_CLK_EN - KPP Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_KPP_CLK_EN(x)             (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_KPP_CLK_EN_SHIFT)) & CGU_PER_CLK_EN_KPP_CLK_EN_MASK)

#define CGU_PER_CLK_EN_LPADC_CLK_EN_MASK         (0x800U)
#define CGU_PER_CLK_EN_LPADC_CLK_EN_SHIFT        (11U)
/*! LPADC_CLK_EN - LPADC Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_LPADC_CLK_EN(x)           (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_LPADC_CLK_EN_SHIFT)) & CGU_PER_CLK_EN_LPADC_CLK_EN_MASK)

#define CGU_PER_CLK_EN_SYS_CLK_EN_MASK           (0x1000U)
#define CGU_PER_CLK_EN_SYS_CLK_EN_SHIFT          (12U)
/*! SYS_CLK_EN - SysTic Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_SYS_CLK_EN(x)             (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_SYS_CLK_EN_SHIFT)) & CGU_PER_CLK_EN_SYS_CLK_EN_MASK)

#define CGU_PER_CLK_EN_COMP_CLK_EN_MASK          (0x2000U)
#define CGU_PER_CLK_EN_COMP_CLK_EN_SHIFT         (13U)
/*! COMP_CLK_EN - Comparator Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_COMP_CLK_EN(x)            (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_COMP_CLK_EN_SHIFT)) & CGU_PER_CLK_EN_COMP_CLK_EN_MASK)

#define CGU_PER_CLK_EN_LCD_CLK_EN_MASK           (0x4000U)
#define CGU_PER_CLK_EN_LCD_CLK_EN_SHIFT          (14U)
/*! LCD_CLK_EN - LCD Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_LCD_CLK_EN(x)             (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_LCD_CLK_EN_SHIFT)) & CGU_PER_CLK_EN_LCD_CLK_EN_MASK)

#define CGU_PER_CLK_EN_ADVC2P0_CLK_EN_MASK       (0x8000U)
#define CGU_PER_CLK_EN_ADVC2P0_CLK_EN_SHIFT      (15U)
/*! ADVC2P0_CLK_EN - ADVC2P0 Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_ADVC2P0_CLK_EN(x)         (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_ADVC2P0_CLK_EN_SHIFT)) & CGU_PER_CLK_EN_ADVC2P0_CLK_EN_MASK)
/*! @} */

/*! @name RST_SUB_BLK - Reset Subsystem Blocks */
/*! @{ */

#define CGU_RST_SUB_BLK_UART_RST_N_MASK          (0x1U)
#define CGU_RST_SUB_BLK_UART_RST_N_SHIFT         (0U)
/*! UART_RST_N - UART Reset N */
#define CGU_RST_SUB_BLK_UART_RST_N(x)            (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_UART_RST_N_SHIFT)) & CGU_RST_SUB_BLK_UART_RST_N_MASK)

#define CGU_RST_SUB_BLK_I2C_RST_N_MASK           (0x2U)
#define CGU_RST_SUB_BLK_I2C_RST_N_SHIFT          (1U)
/*! I2C_RST_N - I2C Software Reset N */
#define CGU_RST_SUB_BLK_I2C_RST_N(x)             (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_I2C_RST_N_SHIFT)) & CGU_RST_SUB_BLK_I2C_RST_N_MASK)

#define CGU_RST_SUB_BLK_CAL_RST_N_MASK           (0x4U)
#define CGU_RST_SUB_BLK_CAL_RST_N_SHIFT          (2U)
/*! CAL_RST_N - Calibration Software Reset N */
#define CGU_RST_SUB_BLK_CAL_RST_N(x)             (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_CAL_RST_N_SHIFT)) & CGU_RST_SUB_BLK_CAL_RST_N_MASK)

#define CGU_RST_SUB_BLK_CPU_SW_RST_N_MASK        (0x8U)
#define CGU_RST_SUB_BLK_CPU_SW_RST_N_SHIFT       (3U)
/*! CPU_SW_RST_N - CPU Software Reset N */
#define CGU_RST_SUB_BLK_CPU_SW_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_CPU_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_CPU_SW_RST_N_MASK)

#define CGU_RST_SUB_BLK_CM0P_RST_REL_MASK        (0x10U)
#define CGU_RST_SUB_BLK_CM0P_RST_REL_SHIFT       (4U)
/*! CM0P_RST_REL - CMOP_RST_REL
 *  0b0..Keep CM0+ at reset state.
 *  0b1..Release CM0+ at reset
 */
#define CGU_RST_SUB_BLK_CM0P_RST_REL(x)          (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_CM0P_RST_REL_SHIFT)) & CGU_RST_SUB_BLK_CM0P_RST_REL_MASK)

#define CGU_RST_SUB_BLK_QTMR0_SW_RST_N_MASK      (0x20U)
#define CGU_RST_SUB_BLK_QTMR0_SW_RST_N_SHIFT     (5U)
/*! QTMR0_SW_RST_N - Qtimer0 Software Reset N */
#define CGU_RST_SUB_BLK_QTMR0_SW_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_QTMR0_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_QTMR0_SW_RST_N_MASK)

#define CGU_RST_SUB_BLK_LPTMR_SW_RST_N_MASK      (0x80U)
#define CGU_RST_SUB_BLK_LPTMR_SW_RST_N_SHIFT     (7U)
/*! LPTMR_SW_RST_N - LP Timer Software Reset N */
#define CGU_RST_SUB_BLK_LPTMR_SW_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_LPTMR_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_LPTMR_SW_RST_N_MASK)

#define CGU_RST_SUB_BLK_KPP_SW_RST_N_MASK        (0x100U)
#define CGU_RST_SUB_BLK_KPP_SW_RST_N_SHIFT       (8U)
/*! KPP_SW_RST_N - KPP Timer Software Reset N */
#define CGU_RST_SUB_BLK_KPP_SW_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_KPP_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_KPP_SW_RST_N_MASK)

#define CGU_RST_SUB_BLK_LPADC_SW_RST_N_MASK      (0x200U)
#define CGU_RST_SUB_BLK_LPADC_SW_RST_N_SHIFT     (9U)
/*! LPADC_SW_RST_N - LPADC Timer Software Reset N */
#define CGU_RST_SUB_BLK_LPADC_SW_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_LPADC_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_LPADC_SW_RST_N_MASK)

#define CGU_RST_SUB_BLK_LCD_SW_RST_N_MASK        (0x400U)
#define CGU_RST_SUB_BLK_LCD_SW_RST_N_SHIFT       (10U)
/*! LCD_SW_RST_N - LCD Software Reset N */
#define CGU_RST_SUB_BLK_LCD_SW_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_LCD_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_LCD_SW_RST_N_MASK)

#define CGU_RST_SUB_BLK_EN_RST_SEC_DET_MASK      (0x800U)
#define CGU_RST_SUB_BLK_EN_RST_SEC_DET_SHIFT     (11U)
/*! EN_RST_SEC_DET - Enable Reset Security Detect. */
#define CGU_RST_SUB_BLK_EN_RST_SEC_DET(x)        (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_EN_RST_SEC_DET_SHIFT)) & CGU_RST_SUB_BLK_EN_RST_SEC_DET_MASK)

#define CGU_RST_SUB_BLK_ACMP_SW_RST_N_MASK       (0x1000U)
#define CGU_RST_SUB_BLK_ACMP_SW_RST_N_SHIFT      (12U)
/*! ACMP_SW_RST_N - ACMP Software Reset N */
#define CGU_RST_SUB_BLK_ACMP_SW_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_ACMP_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_ACMP_SW_RST_N_MASK)

#define CGU_RST_SUB_BLK_ADVC2P0_SW_RST_N_MASK    (0x2000U)
#define CGU_RST_SUB_BLK_ADVC2P0_SW_RST_N_SHIFT   (13U)
/*! ADVC2P0_SW_RST_N - ADVC2P0 Software Reset N */
#define CGU_RST_SUB_BLK_ADVC2P0_SW_RST_N(x)      (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_ADVC2P0_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_ADVC2P0_SW_RST_N_MASK)
/*! @} */

/*! @name FRO10M_CONFIG - FRO10M Configuration */
/*! @{ */

#define CGU_FRO10M_CONFIG_TRIM_CCO_LV_MASK       (0x3FU)
#define CGU_FRO10M_CONFIG_TRIM_CCO_LV_SHIFT      (0U)
/*! TRIM_CCO_LV - TRIM CCO Coarse Calibrate */
#define CGU_FRO10M_CONFIG_TRIM_CCO_LV(x)         (((uint32_t)(((uint32_t)(x)) << CGU_FRO10M_CONFIG_TRIM_CCO_LV_SHIFT)) & CGU_FRO10M_CONFIG_TRIM_CCO_LV_MASK)

#define CGU_FRO10M_CONFIG_TRIM_CLK_LV_MASK       (0xFC0U)
#define CGU_FRO10M_CONFIG_TRIM_CLK_LV_SHIFT      (6U)
/*! TRIM_CLK_LV - TRIM CCO Fine Calibrate */
#define CGU_FRO10M_CONFIG_TRIM_CLK_LV(x)         (((uint32_t)(((uint32_t)(x)) << CGU_FRO10M_CONFIG_TRIM_CLK_LV_SHIFT)) & CGU_FRO10M_CONFIG_TRIM_CLK_LV_MASK)
/*! @} */

/*! @name FRO10M_TRIM - FRO10M Trim */
/*! @{ */

#define CGU_FRO10M_TRIM_TRIM_TC_LV_MASK          (0x1FU)
#define CGU_FRO10M_TRIM_TRIM_TC_LV_SHIFT         (0U)
/*! TRIM_TC_LV - TRIM_TC_LV */
#define CGU_FRO10M_TRIM_TRIM_TC_LV(x)            (((uint32_t)(((uint32_t)(x)) << CGU_FRO10M_TRIM_TRIM_TC_LV_SHIFT)) & CGU_FRO10M_TRIM_TRIM_TC_LV_MASK)

#define CGU_FRO10M_TRIM_TRIM_FVCH_LV_MASK        (0x3E0U)
#define CGU_FRO10M_TRIM_TRIM_FVCH_LV_SHIFT       (5U)
/*! TRIM_FVCH_LV - TRIM_FVCH_LV */
#define CGU_FRO10M_TRIM_TRIM_FVCH_LV(x)          (((uint32_t)(((uint32_t)(x)) << CGU_FRO10M_TRIM_TRIM_FVCH_LV_SHIFT)) & CGU_FRO10M_TRIM_TRIM_FVCH_LV_MASK)
/*! @} */

/*! @name FRO2M_CONFIG - FRO2M Configuration */
/*! @{ */

#define CGU_FRO2M_CONFIG_TRIM_COA_LV_MASK        (0x3FU)
#define CGU_FRO2M_CONFIG_TRIM_COA_LV_SHIFT       (0U)
/*! TRIM_COA_LV - TRIM Bus Coarse Calibrate */
#define CGU_FRO2M_CONFIG_TRIM_COA_LV(x)          (((uint32_t)(((uint32_t)(x)) << CGU_FRO2M_CONFIG_TRIM_COA_LV_SHIFT)) & CGU_FRO2M_CONFIG_TRIM_COA_LV_MASK)

#define CGU_FRO2M_CONFIG_TRIM_FINE_LV_MASK       (0xFC0U)
#define CGU_FRO2M_CONFIG_TRIM_FINE_LV_SHIFT      (6U)
/*! TRIM_FINE_LV - TRIM Fine Calibrate */
#define CGU_FRO2M_CONFIG_TRIM_FINE_LV(x)         (((uint32_t)(((uint32_t)(x)) << CGU_FRO2M_CONFIG_TRIM_FINE_LV_SHIFT)) & CGU_FRO2M_CONFIG_TRIM_FINE_LV_MASK)
/*! @} */

/*! @name FRO2M_TRIM - FRO2M_TRIM */
/*! @{ */

#define CGU_FRO2M_TRIM_TRIM_TC_LV_MASK           (0x1FU)
#define CGU_FRO2M_TRIM_TRIM_TC_LV_SHIFT          (0U)
/*! TRIM_TC_LV - Trim Bus to Calibrate Fraquency. */
#define CGU_FRO2M_TRIM_TRIM_TC_LV(x)             (((uint32_t)(((uint32_t)(x)) << CGU_FRO2M_TRIM_TRIM_TC_LV_SHIFT)) & CGU_FRO2M_TRIM_TRIM_TC_LV_MASK)

#define CGU_FRO2M_TRIM_TRIM_FVCH_LV_MASK         (0x3E0U)
#define CGU_FRO2M_TRIM_TRIM_FVCH_LV_SHIFT        (5U)
/*! TRIM_FVCH_LV - Trim Bus to Calibrate Voltage. */
#define CGU_FRO2M_TRIM_TRIM_FVCH_LV(x)           (((uint32_t)(((uint32_t)(x)) << CGU_FRO2M_TRIM_TRIM_FVCH_LV_SHIFT)) & CGU_FRO2M_TRIM_TRIM_FVCH_LV_MASK)

#define CGU_FRO2M_TRIM_TEST_EN_LV_MASK           (0x400U)
#define CGU_FRO2M_TRIM_TEST_EN_LV_SHIFT          (10U)
/*! TEST_EN_LV - TEST_EN_LV */
#define CGU_FRO2M_TRIM_TEST_EN_LV(x)             (((uint32_t)(((uint32_t)(x)) << CGU_FRO2M_TRIM_TEST_EN_LV_SHIFT)) & CGU_FRO2M_TRIM_TEST_EN_LV_MASK)

#define CGU_FRO2M_TRIM_EN_CKO_DIV16_LV_MASK      (0x800U)
#define CGU_FRO2M_TRIM_EN_CKO_DIV16_LV_SHIFT     (11U)
/*! EN_CKO_DIV16_LV - Test pin for BACEs test IDD */
#define CGU_FRO2M_TRIM_EN_CKO_DIV16_LV(x)        (((uint32_t)(((uint32_t)(x)) << CGU_FRO2M_TRIM_EN_CKO_DIV16_LV_SHIFT)) & CGU_FRO2M_TRIM_EN_CKO_DIV16_LV_MASK)
/*! @} */

/*! @name ACMP_CLK_DIV - ACMP Clock Divider */
/*! @{ */

#define CGU_ACMP_CLK_DIV_ACMP0_CLK_EN_MASK       (0x1U)
#define CGU_ACMP_CLK_DIV_ACMP0_CLK_EN_SHIFT      (0U)
/*! ACMP0_CLK_EN - ACMP0 Clock Enable */
#define CGU_ACMP_CLK_DIV_ACMP0_CLK_EN(x)         (((uint32_t)(((uint32_t)(x)) << CGU_ACMP_CLK_DIV_ACMP0_CLK_EN_SHIFT)) & CGU_ACMP_CLK_DIV_ACMP0_CLK_EN_MASK)

#define CGU_ACMP_CLK_DIV_ACMP1_CLK_EN_MASK       (0x2U)
#define CGU_ACMP_CLK_DIV_ACMP1_CLK_EN_SHIFT      (1U)
/*! ACMP1_CLK_EN - ACMP1 Clock Enable */
#define CGU_ACMP_CLK_DIV_ACMP1_CLK_EN(x)         (((uint32_t)(((uint32_t)(x)) << CGU_ACMP_CLK_DIV_ACMP1_CLK_EN_SHIFT)) & CGU_ACMP_CLK_DIV_ACMP1_CLK_EN_MASK)

#define CGU_ACMP_CLK_DIV_ACMP_CLK0_DIV_EN_MASK   (0x4U)
#define CGU_ACMP_CLK_DIV_ACMP_CLK0_DIV_EN_SHIFT  (2U)
/*! ACMP_CLK0_DIV_EN - ACMP Clock 0 Divider Enable */
#define CGU_ACMP_CLK_DIV_ACMP_CLK0_DIV_EN(x)     (((uint32_t)(((uint32_t)(x)) << CGU_ACMP_CLK_DIV_ACMP_CLK0_DIV_EN_SHIFT)) & CGU_ACMP_CLK_DIV_ACMP_CLK0_DIV_EN_MASK)

#define CGU_ACMP_CLK_DIV_ACMP_CLK1_DIV_EN_MASK   (0x8U)
#define CGU_ACMP_CLK_DIV_ACMP_CLK1_DIV_EN_SHIFT  (3U)
/*! ACMP_CLK1_DIV_EN - ACMP Clock 1 Divider Enable */
#define CGU_ACMP_CLK_DIV_ACMP_CLK1_DIV_EN(x)     (((uint32_t)(((uint32_t)(x)) << CGU_ACMP_CLK_DIV_ACMP_CLK1_DIV_EN_SHIFT)) & CGU_ACMP_CLK_DIV_ACMP_CLK1_DIV_EN_MASK)

#define CGU_ACMP_CLK_DIV_AON_ACMP_CLK0_DIV_MASK  (0xF0U)
#define CGU_ACMP_CLK_DIV_AON_ACMP_CLK0_DIV_SHIFT (4U)
/*! AON_ACMP_CLK0_DIV - ACMP Clock 0 Divider Enable */
#define CGU_ACMP_CLK_DIV_AON_ACMP_CLK0_DIV(x)    (((uint32_t)(((uint32_t)(x)) << CGU_ACMP_CLK_DIV_AON_ACMP_CLK0_DIV_SHIFT)) & CGU_ACMP_CLK_DIV_AON_ACMP_CLK0_DIV_MASK)

#define CGU_ACMP_CLK_DIV_AON_ACMP_CLK1_DIV_MASK  (0xF00U)
#define CGU_ACMP_CLK_DIV_AON_ACMP_CLK1_DIV_SHIFT (8U)
/*! AON_ACMP_CLK1_DIV - ACMP Clock 1 Divider Enable */
#define CGU_ACMP_CLK_DIV_AON_ACMP_CLK1_DIV(x)    (((uint32_t)(((uint32_t)(x)) << CGU_ACMP_CLK_DIV_AON_ACMP_CLK1_DIV_SHIFT)) & CGU_ACMP_CLK_DIV_AON_ACMP_CLK1_DIV_MASK)
/*! @} */

/*! @name INT - Interrupt Flag */
/*! @{ */

#define CGU_INT_AUTO_CAL_VAL_MASK                (0x1U)
#define CGU_INT_AUTO_CAL_VAL_SHIFT               (0U)
/*! AUTO_CAL_VAL - Auto Calibration Valid Enable Interrupt. */
#define CGU_INT_AUTO_CAL_VAL(x)                  (((uint32_t)(((uint32_t)(x)) << CGU_INT_AUTO_CAL_VAL_SHIFT)) & CGU_INT_AUTO_CAL_VAL_MASK)

#define CGU_INT_AUTO_CAL_NOT_VAL_MASK            (0x2U)
#define CGU_INT_AUTO_CAL_NOT_VAL_SHIFT           (1U)
/*! AUTO_CAL_NOT_VAL - Auto Calibration Not Valid Enable Interrupt. */
#define CGU_INT_AUTO_CAL_NOT_VAL(x)              (((uint32_t)(((uint32_t)(x)) << CGU_INT_AUTO_CAL_NOT_VAL_SHIFT)) & CGU_INT_AUTO_CAL_NOT_VAL_MASK)

#define CGU_INT_SEC_RST_IE_MASK                  (0x4U)
#define CGU_INT_SEC_RST_IE_SHIFT                 (2U)
/*! SEC_RST_IE - Security Reset Interrupt */
#define CGU_INT_SEC_RST_IE(x)                    (((uint32_t)(((uint32_t)(x)) << CGU_INT_SEC_RST_IE_SHIFT)) & CGU_INT_SEC_RST_IE_MASK)

#define CGU_INT_AUTO_CAL_VAL_IF_MASK             (0x100U)
#define CGU_INT_AUTO_CAL_VAL_IF_SHIFT            (8U)
/*! AUTO_CAL_VAL_IF - Auto Calibration Valid Interrupt Flag
 *  0b0..Read
 *  0b1..Writing 1 to clears this flag. Writing 0 does nothing
 */
#define CGU_INT_AUTO_CAL_VAL_IF(x)               (((uint32_t)(((uint32_t)(x)) << CGU_INT_AUTO_CAL_VAL_IF_SHIFT)) & CGU_INT_AUTO_CAL_VAL_IF_MASK)

#define CGU_INT_AUTO_CAL_NOT_VAL_IF_MASK         (0x200U)
#define CGU_INT_AUTO_CAL_NOT_VAL_IF_SHIFT        (9U)
/*! AUTO_CAL_NOT_VAL_IF - Auto Calibration Not Valid Enable Interrupt Flag
 *  0b0..Read
 *  0b1..Writing 1 clears this flag. Writing 0 does nothing.
 */
#define CGU_INT_AUTO_CAL_NOT_VAL_IF(x)           (((uint32_t)(((uint32_t)(x)) << CGU_INT_AUTO_CAL_NOT_VAL_IF_SHIFT)) & CGU_INT_AUTO_CAL_NOT_VAL_IF_MASK)

#define CGU_INT_SEC_RST_IF_MASK                  (0x400U)
#define CGU_INT_SEC_RST_IF_SHIFT                 (10U)
/*! SEC_RST_IF - Security Reset Interrupt Flag
 *  0b0..Read
 *  0b1..Writing 1 clears this flag. Writing 0 does nothing.
 */
#define CGU_INT_SEC_RST_IF(x)                    (((uint32_t)(((uint32_t)(x)) << CGU_INT_SEC_RST_IF_SHIFT)) & CGU_INT_SEC_RST_IF_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CGU_Register_Masks */


/*!
 * @}
 */ /* end of group CGU_Peripheral_Access_Layer */


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


#endif  /* PERI_CGU_H_ */

