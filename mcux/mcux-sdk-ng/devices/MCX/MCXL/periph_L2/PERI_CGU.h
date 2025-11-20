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
**     Version:             rev. 1.0, 2025-06-13
**     Build:               b250901
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
**     - rev. 1.0 (2025-06-13)
**         Generated based on Rev1 DraftH.
**
** ###################################################################
*/

/*!
 * @file PERI_CGU.h
 * @version 1.0
 * @date 2025-06-13
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
  __IO uint32_t PER_CLK_CONFIG;                    /**< Peripheral Clock Configuration, offset: 0x4 */
  __IO uint32_t CLOCK_DIV;                         /**< Clock Divider, offset: 0x8 */
  __IO uint32_t PER_CLK_EN;                        /**< Peripheral Clock Enable, offset: 0xC */
  __IO uint32_t RST_SUB_BLK;                       /**< Reset Subsystem Blocks, offset: 0x10 */
       uint8_t RESERVED_0[48];
  __IO uint32_t ACMP_CLK;                          /**< ACMP Clock, offset: 0x44 */
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
 *  0b00..Option based on the selected FRO, if FRO10M is used then the clock will be 10.0 MHz and if FRO2M is used then the clock will be 2.0 MHz.
 *  0b01..Option based on the selected FRO, if FRO10M is used then the clock will be 5.0 MHz and if FRO2M is used then the clock will be 1.0 MHz.
 *  0b10..Option based on the selected FRO, if FRO10M is used then the clock will be 2.5 MHz and if FRO2M is used then the clock will be 0.5 MHz.
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
/*! XTAL32_OUT_EN - XTAL32K[1] Output Enable
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

/*! @name PER_CLK_CONFIG - Peripheral Clock Configuration */
/*! @{ */

#define CGU_PER_CLK_CONFIG_COM_GRP_SEL_MASK      (0x3U)
#define CGU_PER_CLK_CONFIG_COM_GRP_SEL_SHIFT     (0U)
/*! COM_GRP_SEL - Communication Group Select
 *  0b00..Option based on the selected FRO, if FRO10M is used then the clock will be 10.0 MHz and if FRO2M is used then the clock will be 2.0 MHz.
 *  0b01..Option based on the selected FRO, if FRO10M is used then the clock will be 5.0 MHz and if FRO2M is used then the clock will be 1.0 MHz.
 *  0b10..Option based on the selected FRO, if FRO10M is used then the clock will be 2.5 MHz and if FRO2M is used then the clock will be 0.5 MHz.
 *  0b11..32 kHz
 */
#define CGU_PER_CLK_CONFIG_COM_GRP_SEL(x)        (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_COM_GRP_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_COM_GRP_SEL_MASK)

#define CGU_PER_CLK_CONFIG_TMR_GRP_SEL_MASK      (0xCU)
#define CGU_PER_CLK_CONFIG_TMR_GRP_SEL_SHIFT     (2U)
/*! TMR_GRP_SEL - Timer Group Select
 *  0b00..Option based on the selected FRO, if FRO10M is used then the clock will be 10.0 MHz and if FRO2M is used then the clock will be 2.0 MHz.
 *  0b01..Option based on the selected FRO, if FRO10M is used then the clock will be 5.0 MHz and if FRO2M is used then the clock will be 1.0 MHz.
 *  0b10..Option based on the selected FRO, if FRO10M is used then the clock will be 2.5 MHz and if FRO2M is used then the clock will be 0.5 MHz.
 *  0b11..32 kHz
 */
#define CGU_PER_CLK_CONFIG_TMR_GRP_SEL(x)        (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_TMR_GRP_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_TMR_GRP_SEL_MASK)

#define CGU_PER_CLK_CONFIG_LPTMR_GRP_SEL_MASK    (0x30U)
#define CGU_PER_CLK_CONFIG_LPTMR_GRP_SEL_SHIFT   (4U)
/*! LPTMR_GRP_SEL - Low-Power Timer Group Select
 *  0b00..AON_TIMER_CLK
 *  0b01..FRO16K
 *  0b10..clk_16k
 *  0b11..Reserved
 */
#define CGU_PER_CLK_CONFIG_LPTMR_GRP_SEL(x)      (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_LPTMR_GRP_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_LPTMR_GRP_SEL_MASK)

#define CGU_PER_CLK_CONFIG_KPP_CLK_SEL_MASK      (0x40U)
#define CGU_PER_CLK_CONFIG_KPP_CLK_SEL_SHIFT     (6U)
/*! KPP_CLK_SEL - KPP Clock Select
 *  0b0..Xtal 32 kHz.
 *  0b1..FRO16K
 */
#define CGU_PER_CLK_CONFIG_KPP_CLK_SEL(x)        (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_KPP_CLK_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_KPP_CLK_SEL_MASK)

#define CGU_PER_CLK_CONFIG_AON_SYS_CLK_SEL_MASK  (0x180U)
#define CGU_PER_CLK_CONFIG_AON_SYS_CLK_SEL_SHIFT (7U)
/*! AON_SYS_CLK_SEL - AON SysTick Clock Select
 *  0b00..Option based on the selected FRO, if FRO10M is used then the clock will be 10.0 MHz and if FRO2M is used then the clock will be 2.0 MHz.
 *  0b01..Option based on the selected FRO, if FRO10M is used then the clock will be 5.0 MHz and if FRO2M is used then clock will be 1.0 MHz.
 *  0b10..Option based on the selected FRO, if FRO10M is used then the clock will be 2.5 MHz and if FRO2M is used then the clock will be 0.5 MHz.
 *  0b11..Reserved
 */
#define CGU_PER_CLK_CONFIG_AON_SYS_CLK_SEL(x)    (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_AON_SYS_CLK_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_AON_SYS_CLK_SEL_MASK)

#define CGU_PER_CLK_CONFIG_LPADC_CLK_SEL_MASK    (0xE00U)
#define CGU_PER_CLK_CONFIG_LPADC_CLK_SEL_SHIFT   (9U)
/*! LPADC_CLK_SEL - LPADC Clock Select
 *  0b000..Option based on the selected FRO, if FRO10M is used then the clock will be 10.0 MHz and if FRO2M is used then the clock will be 2.0 MHz.
 *  0b001..Option based on the selected FRO, if FRO10M is used then the clock will be 5.0 MHz and if FRO2M is used then the clock will be 1.0 MHz.
 *  0b010..Option based on the selected FRO, if FRO10M is used then the clock will be 2.5 MHz and if FRO2M is used then the clock will be 0.5 MHz.
 *  0b011..Option based on the selected FRO, if FRO10M is used then clock will be aon_aux_clk and if FRO2M is used then clock will be aon_aux_clk.
 *  0b100..XTAL32K
 *  0b101..FRO16K
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define CGU_PER_CLK_CONFIG_LPADC_CLK_SEL(x)      (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_LPADC_CLK_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_LPADC_CLK_SEL_MASK)

#define CGU_PER_CLK_CONFIG_LCD_CLK_SEL_MASK      (0x1000U)
#define CGU_PER_CLK_CONFIG_LCD_CLK_SEL_SHIFT     (12U)
/*! LCD_CLK_SEL - LCD Clock Select
 *  0b0..clk_16k[1]
 *  0b1..FRO16K
 */
#define CGU_PER_CLK_CONFIG_LCD_CLK_SEL(x)        (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_CONFIG_LCD_CLK_SEL_SHIFT)) & CGU_PER_CLK_CONFIG_LCD_CLK_SEL_MASK)

#define CGU_PER_CLK_CONFIG_ACMP0_CLK_SEL_MASK    (0x6000U)
#define CGU_PER_CLK_CONFIG_ACMP0_CLK_SEL_SHIFT   (13U)
/*! ACMP0_CLK_SEL - ACMP0 clock mux select
 *  0b00..Option based on the selected FRO, if FRO10M is used then the clock will be 10.0 MHz and if FRO2M is used then the clock will be 2.0 MHz.
 *  0b01..Option based on the selected FRO, if FRO10M is used then the clock will be 5.0 MHz and if FRO2M is used then the clock will be 1.0 MHz.
 *  0b10..Option based on the selected FRO, if FRO10M is used then the clock will be 2.5 MHz and if FRO2M is used then the clock will be 0.5 MHz.
 *  0b11..FRO16K
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
/*! COM_GRP_CLK_EN - Communication Group Clock Divider Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_CLOCK_DIV_COM_GRP_CLK_EN(x)          (((uint32_t)(((uint32_t)(x)) << CGU_CLOCK_DIV_COM_GRP_CLK_EN_SHIFT)) & CGU_CLOCK_DIV_COM_GRP_CLK_EN_MASK)

#define CGU_CLOCK_DIV_SYS_CLK_DIV_EN_MASK        (0x4U)
#define CGU_CLOCK_DIV_SYS_CLK_DIV_EN_SHIFT       (2U)
/*! SYS_CLK_DIV_EN - SysTick Clock Divider Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_CLOCK_DIV_SYS_CLK_DIV_EN(x)          (((uint32_t)(((uint32_t)(x)) << CGU_CLOCK_DIV_SYS_CLK_DIV_EN_SHIFT)) & CGU_CLOCK_DIV_SYS_CLK_DIV_EN_MASK)

#define CGU_CLOCK_DIV_AON_CPU_CLK_DIV_MASK       (0x38U)
#define CGU_CLOCK_DIV_AON_CPU_CLK_DIV_SHIFT      (3U)
/*! AON_CPU_CLK_DIV - AON CPU Clock Divider */
#define CGU_CLOCK_DIV_AON_CPU_CLK_DIV(x)         (((uint32_t)(((uint32_t)(x)) << CGU_CLOCK_DIV_AON_CPU_CLK_DIV_SHIFT)) & CGU_CLOCK_DIV_AON_CPU_CLK_DIV_MASK)

#define CGU_CLOCK_DIV_COM_GRP_CLK_DIV_MASK       (0x1C0U)
#define CGU_CLOCK_DIV_COM_GRP_CLK_DIV_SHIFT      (6U)
/*! COM_GRP_CLK_DIV - Communication Group Clock Divider */
#define CGU_CLOCK_DIV_COM_GRP_CLK_DIV(x)         (((uint32_t)(((uint32_t)(x)) << CGU_CLOCK_DIV_COM_GRP_CLK_DIV_SHIFT)) & CGU_CLOCK_DIV_COM_GRP_CLK_DIV_MASK)

#define CGU_CLOCK_DIV_AON_SYS_CLK_DIV_MASK       (0xE00U)
#define CGU_CLOCK_DIV_AON_SYS_CLK_DIV_SHIFT      (9U)
/*! AON_SYS_CLK_DIV - AON SysTick Clock Divider */
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
/*! QTMR0_CLK_EN - QTimer0 Clock Enable
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
/*! SYS_CLK_EN - SysTick Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_PER_CLK_EN_SYS_CLK_EN(x)             (((uint32_t)(((uint32_t)(x)) << CGU_PER_CLK_EN_SYS_CLK_EN_SHIFT)) & CGU_PER_CLK_EN_SYS_CLK_EN_MASK)

#define CGU_PER_CLK_EN_COMP_CLK_EN_MASK          (0x2000U)
#define CGU_PER_CLK_EN_COMP_CLK_EN_SHIFT         (13U)
/*! COMP_CLK_EN - Communication Clock Enable
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
/*! UART_RST_N - UART Reset
 *  0b0..Enable
 *  0b1..Disable
 */
#define CGU_RST_SUB_BLK_UART_RST_N(x)            (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_UART_RST_N_SHIFT)) & CGU_RST_SUB_BLK_UART_RST_N_MASK)

#define CGU_RST_SUB_BLK_I2C_RST_N_MASK           (0x2U)
#define CGU_RST_SUB_BLK_I2C_RST_N_SHIFT          (1U)
/*! I2C_RST_N - I2C Software Reset
 *  0b0..Enable
 *  0b1..Disable
 */
#define CGU_RST_SUB_BLK_I2C_RST_N(x)             (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_I2C_RST_N_SHIFT)) & CGU_RST_SUB_BLK_I2C_RST_N_MASK)

#define CGU_RST_SUB_BLK_CAL_RST_N_MASK           (0x4U)
#define CGU_RST_SUB_BLK_CAL_RST_N_SHIFT          (2U)
/*! CAL_RST_N - Calibration Software Reset
 *  0b0..Enable
 *  0b1..Disable
 */
#define CGU_RST_SUB_BLK_CAL_RST_N(x)             (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_CAL_RST_N_SHIFT)) & CGU_RST_SUB_BLK_CAL_RST_N_MASK)

#define CGU_RST_SUB_BLK_CPU_SW_RST_N_MASK        (0x8U)
#define CGU_RST_SUB_BLK_CPU_SW_RST_N_SHIFT       (3U)
/*! CPU_SW_RST_N - CPU Software Reset
 *  0b0..Enable
 *  0b1..Disable
 */
#define CGU_RST_SUB_BLK_CPU_SW_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_CPU_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_CPU_SW_RST_N_MASK)

#define CGU_RST_SUB_BLK_CM0P_RST_REL_MASK        (0x10U)
#define CGU_RST_SUB_BLK_CM0P_RST_REL_SHIFT       (4U)
/*! CM0P_RST_REL - CM0P_RST_REL
 *  0b0..Keep CM0+ at reset state.
 *  0b1..Release CM0+ at reset
 */
#define CGU_RST_SUB_BLK_CM0P_RST_REL(x)          (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_CM0P_RST_REL_SHIFT)) & CGU_RST_SUB_BLK_CM0P_RST_REL_MASK)

#define CGU_RST_SUB_BLK_QTMR0_SW_RST_N_MASK      (0x20U)
#define CGU_RST_SUB_BLK_QTMR0_SW_RST_N_SHIFT     (5U)
/*! QTMR0_SW_RST_N - Qtimer0 Software Reset
 *  0b0..Enable
 *  0b1..Disable
 */
#define CGU_RST_SUB_BLK_QTMR0_SW_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_QTMR0_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_QTMR0_SW_RST_N_MASK)

#define CGU_RST_SUB_BLK_LPTMR_SW_RST_N_MASK      (0x80U)
#define CGU_RST_SUB_BLK_LPTMR_SW_RST_N_SHIFT     (7U)
/*! LPTMR_SW_RST_N - LP Timer Software Reset
 *  0b0..Enable
 *  0b1..Disable
 */
#define CGU_RST_SUB_BLK_LPTMR_SW_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_LPTMR_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_LPTMR_SW_RST_N_MASK)

#define CGU_RST_SUB_BLK_KPP_SW_RST_N_MASK        (0x100U)
#define CGU_RST_SUB_BLK_KPP_SW_RST_N_SHIFT       (8U)
/*! KPP_SW_RST_N - KPP Timer Software Reset
 *  0b0..Enable
 *  0b1..Disable
 */
#define CGU_RST_SUB_BLK_KPP_SW_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_KPP_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_KPP_SW_RST_N_MASK)

#define CGU_RST_SUB_BLK_LPADC_SW_RST_N_MASK      (0x200U)
#define CGU_RST_SUB_BLK_LPADC_SW_RST_N_SHIFT     (9U)
/*! LPADC_SW_RST_N - LPADC Timer Software Reset
 *  0b0..Enable
 *  0b1..Disable
 */
#define CGU_RST_SUB_BLK_LPADC_SW_RST_N(x)        (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_LPADC_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_LPADC_SW_RST_N_MASK)

#define CGU_RST_SUB_BLK_LCD_SW_RST_N_MASK        (0x400U)
#define CGU_RST_SUB_BLK_LCD_SW_RST_N_SHIFT       (10U)
/*! LCD_SW_RST_N - LCD Software Reset
 *  0b0..Enable
 *  0b1..Disable
 */
#define CGU_RST_SUB_BLK_LCD_SW_RST_N(x)          (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_LCD_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_LCD_SW_RST_N_MASK)

#define CGU_RST_SUB_BLK_EN_RST_SEC_DET_MASK      (0x800U)
#define CGU_RST_SUB_BLK_EN_RST_SEC_DET_SHIFT     (11U)
/*! EN_RST_SEC_DET - Enable Reset Security Detect.
 *  0b0..Enable
 *  0b1..Disable
 */
#define CGU_RST_SUB_BLK_EN_RST_SEC_DET(x)        (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_EN_RST_SEC_DET_SHIFT)) & CGU_RST_SUB_BLK_EN_RST_SEC_DET_MASK)

#define CGU_RST_SUB_BLK_ACMP_SW_RST_N_MASK       (0x1000U)
#define CGU_RST_SUB_BLK_ACMP_SW_RST_N_SHIFT      (12U)
/*! ACMP_SW_RST_N - ACMP Software Reset
 *  0b0..Enable
 *  0b1..Disable
 */
#define CGU_RST_SUB_BLK_ACMP_SW_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_ACMP_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_ACMP_SW_RST_N_MASK)

#define CGU_RST_SUB_BLK_ADVC2P0_SW_RST_N_MASK    (0x2000U)
#define CGU_RST_SUB_BLK_ADVC2P0_SW_RST_N_SHIFT   (13U)
/*! ADVC2P0_SW_RST_N - ADVC2P0 Software Reset
 *  0b0..Enable
 *  0b1..Disable
 */
#define CGU_RST_SUB_BLK_ADVC2P0_SW_RST_N(x)      (((uint32_t)(((uint32_t)(x)) << CGU_RST_SUB_BLK_ADVC2P0_SW_RST_N_SHIFT)) & CGU_RST_SUB_BLK_ADVC2P0_SW_RST_N_MASK)
/*! @} */

/*! @name ACMP_CLK - ACMP Clock */
/*! @{ */

#define CGU_ACMP_CLK_ACMP0_CLK_EN_MASK           (0x1U)
#define CGU_ACMP_CLK_ACMP0_CLK_EN_SHIFT          (0U)
/*! ACMP0_CLK_EN - ACMP0 Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_ACMP_CLK_ACMP0_CLK_EN(x)             (((uint32_t)(((uint32_t)(x)) << CGU_ACMP_CLK_ACMP0_CLK_EN_SHIFT)) & CGU_ACMP_CLK_ACMP0_CLK_EN_MASK)

#define CGU_ACMP_CLK_ACMP1_CLK_EN_MASK           (0x2U)
#define CGU_ACMP_CLK_ACMP1_CLK_EN_SHIFT          (1U)
/*! ACMP1_CLK_EN - ACMP1 Clock Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_ACMP_CLK_ACMP1_CLK_EN(x)             (((uint32_t)(((uint32_t)(x)) << CGU_ACMP_CLK_ACMP1_CLK_EN_SHIFT)) & CGU_ACMP_CLK_ACMP1_CLK_EN_MASK)

#define CGU_ACMP_CLK_ACMP_CLK0_DIV_EN_MASK       (0x4U)
#define CGU_ACMP_CLK_ACMP_CLK0_DIV_EN_SHIFT      (2U)
/*! ACMP_CLK0_DIV_EN - ACMP Clock 0 Divider Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_ACMP_CLK_ACMP_CLK0_DIV_EN(x)         (((uint32_t)(((uint32_t)(x)) << CGU_ACMP_CLK_ACMP_CLK0_DIV_EN_SHIFT)) & CGU_ACMP_CLK_ACMP_CLK0_DIV_EN_MASK)

#define CGU_ACMP_CLK_ACMP_CLK1_DIV_EN_MASK       (0x8U)
#define CGU_ACMP_CLK_ACMP_CLK1_DIV_EN_SHIFT      (3U)
/*! ACMP_CLK1_DIV_EN - ACMP Clock 1 Divider Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define CGU_ACMP_CLK_ACMP_CLK1_DIV_EN(x)         (((uint32_t)(((uint32_t)(x)) << CGU_ACMP_CLK_ACMP_CLK1_DIV_EN_SHIFT)) & CGU_ACMP_CLK_ACMP_CLK1_DIV_EN_MASK)

#define CGU_ACMP_CLK_AON_ACMP_CLK0_DIV_MASK      (0xF0U)
#define CGU_ACMP_CLK_AON_ACMP_CLK0_DIV_SHIFT     (4U)
/*! AON_ACMP_CLK0_DIV - ACMP Clock 0 Divider Control
 *  0b0000..Divide by 1
 *  0b0001..Divide by 2
 *  0b0010..Divide by 3
 *  0b0011..Divide by 4
 *  0b0100..Divide by 5
 *  0b0101..Divide by 6
 *  0b0110..Divide by 7
 *  0b0111..Divide by 8
 *  0b1000..Divide by 9
 *  0b1001..Divide by 10
 *  0b1010..Divide by 11
 *  0b1011..Divide by 12
 *  0b1100..Divide by 13
 *  0b1101..Divide by 14
 *  0b1110..Divide by 15
 *  0b1111..Divide by 16
 */
#define CGU_ACMP_CLK_AON_ACMP_CLK0_DIV(x)        (((uint32_t)(((uint32_t)(x)) << CGU_ACMP_CLK_AON_ACMP_CLK0_DIV_SHIFT)) & CGU_ACMP_CLK_AON_ACMP_CLK0_DIV_MASK)

#define CGU_ACMP_CLK_AON_ACMP_CLK1_DIV_MASK      (0xF00U)
#define CGU_ACMP_CLK_AON_ACMP_CLK1_DIV_SHIFT     (8U)
/*! AON_ACMP_CLK1_DIV - ACMP Clock 1 Divider Control
 *  0b0000..Divide by 1
 *  0b0001..Divide by 2
 *  0b0010..Divide by 3
 *  0b0011..Divide by 4
 *  0b0100..Divide by 5
 *  0b0101..Divide by 6
 *  0b0110..Divide by 7
 *  0b0111..Divide by 8
 *  0b1000..Divide by 9
 *  0b1001..Divide by 10
 *  0b1010..Divide by 11
 *  0b1011..Divide by 12
 *  0b1100..Divide by 13
 *  0b1101..Divide by 14
 *  0b1110..Divide by 15
 *  0b1111..Divide by 16
 */
#define CGU_ACMP_CLK_AON_ACMP_CLK1_DIV(x)        (((uint32_t)(((uint32_t)(x)) << CGU_ACMP_CLK_AON_ACMP_CLK1_DIV_SHIFT)) & CGU_ACMP_CLK_AON_ACMP_CLK1_DIV_MASK)
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
/*! SEC_RST_IE - Security Reset Interrupt Enable */
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

