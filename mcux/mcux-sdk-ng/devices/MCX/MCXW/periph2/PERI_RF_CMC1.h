/*
** ###################################################################
**     Processors:          MCXW716AMFPA
**                          MCXW716AMFTA
**                          MCXW716CMFPA
**                          MCXW716CMFTA
**
**     Version:             rev. 1.0, 2024-03-21
**     Build:               b240705
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RF_CMC1
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-21)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file RF_CMC1.h
 * @version 1.0
 * @date 2024-03-21
 * @brief CMSIS Peripheral Access Layer for RF_CMC1
 *
 * CMSIS Peripheral Access Layer for RF_CMC1
 */

#if !defined(RF_CMC1_H_)
#define RF_CMC1_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW716AMFPA) || defined(CPU_MCXW716AMFTA))
#include "MCXW716A_COMMON.h"
#elif (defined(CPU_MCXW716CMFPA) || defined(CPU_MCXW716CMFTA))
#include "MCXW716C_COMMON.h"
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
   -- RF_CMC1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RF_CMC1_Peripheral_Access_Layer RF_CMC1 Peripheral Access Layer
 * @{
 */

/** RF_CMC1 - Register Layout Typedef */
typedef struct {
  __IO uint32_t RADIO_LP;                          /**< Radio Low Power Control Register, offset: 0x0 */
  __IO uint32_t SOC_LP;                            /**< SOC Low Power Control and Status Register, offset: 0x4 */
  __IO uint32_t IRQ_CTRL;                          /**< Interrupt Control Register, offset: 0x8 */
  __IO uint32_t TPM2_CFG;                          /**< TPM2 Configuration Register, offset: 0xC */
  __IO uint32_t RADIO_TRIM;                        /**< Radio Trim Register, offset: 0x10 */
  __IO uint32_t RAM_PWR;                           /**< RAM Power Control register, offset: 0x14 */
} RF_CMC1_Type;

/* ----------------------------------------------------------------------------
   -- RF_CMC1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RF_CMC1_Register_Masks RF_CMC1 Register Masks
 * @{
 */

/*! @name RADIO_LP - Radio Low Power Control Register */
/*! @{ */

#define RF_CMC1_RADIO_LP_SLEEP_EN_MASK           (0x1U)
#define RF_CMC1_RADIO_LP_SLEEP_EN_SHIFT          (0U)
/*! SLEEP_EN - Sleep Enable */
#define RF_CMC1_RADIO_LP_SLEEP_EN(x)             (((uint32_t)(((uint32_t)(x)) << RF_CMC1_RADIO_LP_SLEEP_EN_SHIFT)) & RF_CMC1_RADIO_LP_SLEEP_EN_MASK)

#define RF_CMC1_RADIO_LP_BLE_WKUP_MASK           (0x2U)
#define RF_CMC1_RADIO_LP_BLE_WKUP_SHIFT          (1U)
/*! BLE_WKUP - Bluetooth Wakeup */
#define RF_CMC1_RADIO_LP_BLE_WKUP(x)             (((uint32_t)(((uint32_t)(x)) << RF_CMC1_RADIO_LP_BLE_WKUP_SHIFT)) & RF_CMC1_RADIO_LP_BLE_WKUP_MASK)

#define RF_CMC1_RADIO_LP_CK_MASK                 (0xCU)
#define RF_CMC1_RADIO_LP_CK_SHIFT                (2U)
/*! CK - Clock Control
 *  0b00..Normal configuration. When NBU CPU executes WFI and SLEEP_EN=1 (or if NBU CPU reset is asserted), and a
 *        sleep request from RFMC (LP_ENTER) NBU, MAN or WOR is asserted, the flash is put in low power, the
 *        sleep_rdy to RFMC asserts and the FRO will be disabled.
 *  0b01..Configuration where NBU, FRO and flash are not used. When NBU CPU reset is asserted, or NBU CPU executes
 *        WFI and SLEEP_EN=1, the flash will be placed in low power, the FRO disabled, the sleep_rdy to RFMC will
 *        assert and the NBU CM3 and AHB clocks will be gated off. The RF_CMC and NBU CPU will be without a clock
 *        until the next reset, but low power requests (RFMC LP_ENTER, MAN or WOR) will by accepted by RFMC since
 *        RF_CMC's sleep_rdy output will remain asserted.
 *  0b10..Configuration where NBU CPU is not used but FRO and flash can still be used. When NBU CPU reset is
 *        asserted, or NBU CPU executes WFI and SLEEP_EN=1, the clock to the NBU CPU will be gated. When RFMC
 *        (LP_ENTER), MAN or WOR request sleep, the flash is put in low power, the sleep_rdy to RFMC asserts and the FRO will
 *        be disabled as in configuration 00.
 */
#define RF_CMC1_RADIO_LP_CK(x)                   (((uint32_t)(((uint32_t)(x)) << RF_CMC1_RADIO_LP_CK_SHIFT)) & RF_CMC1_RADIO_LP_CK_MASK)
/*! @} */

/*! @name SOC_LP - SOC Low Power Control and Status Register */
/*! @{ */

#define RF_CMC1_SOC_LP_BUS_REQ_MASK              (0x1U)
#define RF_CMC1_SOC_LP_BUS_REQ_SHIFT             (0U)
/*! BUS_REQ - Bus Access Request */
#define RF_CMC1_SOC_LP_BUS_REQ(x)                (((uint32_t)(((uint32_t)(x)) << RF_CMC1_SOC_LP_BUS_REQ_SHIFT)) & RF_CMC1_SOC_LP_BUS_REQ_MASK)

#define RF_CMC1_SOC_LP_BUS_AWAKE_MASK            (0x10U)
#define RF_CMC1_SOC_LP_BUS_AWAKE_SHIFT           (4U)
/*! BUS_AWAKE - Bus Awake */
#define RF_CMC1_SOC_LP_BUS_AWAKE(x)              (((uint32_t)(((uint32_t)(x)) << RF_CMC1_SOC_LP_BUS_AWAKE_SHIFT)) & RF_CMC1_SOC_LP_BUS_AWAKE_MASK)
/*! @} */

/*! @name IRQ_CTRL - Interrupt Control Register */
/*! @{ */

#define RF_CMC1_IRQ_CTRL_RDY_FLAG_MASK           (0x1U)
#define RF_CMC1_IRQ_CTRL_RDY_FLAG_SHIFT          (0U)
/*! RDY_FLAG - XTAL Ready Flag */
#define RF_CMC1_IRQ_CTRL_RDY_FLAG(x)             (((uint32_t)(((uint32_t)(x)) << RF_CMC1_IRQ_CTRL_RDY_FLAG_SHIFT)) & RF_CMC1_IRQ_CTRL_RDY_FLAG_MASK)

#define RF_CMC1_IRQ_CTRL_RDY_IE_MASK             (0x10U)
#define RF_CMC1_IRQ_CTRL_RDY_IE_SHIFT            (4U)
/*! RDY_IE - XTAL Ready Interrupt Enable */
#define RF_CMC1_IRQ_CTRL_RDY_IE(x)               (((uint32_t)(((uint32_t)(x)) << RF_CMC1_IRQ_CTRL_RDY_IE_SHIFT)) & RF_CMC1_IRQ_CTRL_RDY_IE_MASK)

#define RF_CMC1_IRQ_CTRL_XTAL_RDY_MASK           (0x100U)
#define RF_CMC1_IRQ_CTRL_XTAL_RDY_SHIFT          (8U)
/*! XTAL_RDY - XTAL Ready */
#define RF_CMC1_IRQ_CTRL_XTAL_RDY(x)             (((uint32_t)(((uint32_t)(x)) << RF_CMC1_IRQ_CTRL_XTAL_RDY_SHIFT)) & RF_CMC1_IRQ_CTRL_XTAL_RDY_MASK)
/*! @} */

/*! @name TPM2_CFG - TPM2 Configuration Register */
/*! @{ */

#define RF_CMC1_TPM2_CFG_CH0_MUX_SEL_MASK        (0x1U)
#define RF_CMC1_TPM2_CFG_CH0_MUX_SEL_SHIFT       (0U)
/*! CH0_MUX_SEL - Channel0 Input Mux Select
 *  0b0..TPM2_CH0 pin
 *  0b1..tof_timestamp_trig signal from radio
 */
#define RF_CMC1_TPM2_CFG_CH0_MUX_SEL(x)          (((uint32_t)(((uint32_t)(x)) << RF_CMC1_TPM2_CFG_CH0_MUX_SEL_SHIFT)) & RF_CMC1_TPM2_CFG_CH0_MUX_SEL_MASK)

#define RF_CMC1_TPM2_CFG_CH1_MUX_SEL_MASK        (0xF0U)
#define RF_CMC1_TPM2_CFG_CH1_MUX_SEL_SHIFT       (4U)
/*! CH1_MUX_SEL - Channel1 Input Mux Select
 *  0b0000..TPM2_CH1 pin
 *  0b0001..dtest[0] signal from radio
 *  0b0010..dtest[1] signal from radio
 *  0b0011..dtest[2] signal from radio
 *  0b0100..dtest[3] signal from radio
 *  0b0101..dtest[4] signal from radio
 *  0b0110..dtest[5] signal from radio
 *  0b0111..dtest[6] signal from radio
 *  0b1000..dtest[7] signal from radio
 *  0b1001..dtest[8] signal from radio
 *  0b1010..dtest[9] signal from radio
 *  0b1011..dtest[10] signal from radio
 *  0b1100..dtest[11] signal from radio
 *  0b1101..dtest[12] signal from radio
 *  0b1110..dtest[13] signal from radio
 *  0b1111..Reserved
 */
#define RF_CMC1_TPM2_CFG_CH1_MUX_SEL(x)          (((uint32_t)(((uint32_t)(x)) << RF_CMC1_TPM2_CFG_CH1_MUX_SEL_SHIFT)) & RF_CMC1_TPM2_CFG_CH1_MUX_SEL_MASK)

#define RF_CMC1_TPM2_CFG_CGC_MASK                (0x100U)
#define RF_CMC1_TPM2_CFG_CGC_SHIFT               (8U)
/*! CGC - Clock Gate Control
 *  0b0..TPM2 clock disabled
 *  0b1..TPM2 clock enabled
 */
#define RF_CMC1_TPM2_CFG_CGC(x)                  (((uint32_t)(((uint32_t)(x)) << RF_CMC1_TPM2_CFG_CGC_SHIFT)) & RF_CMC1_TPM2_CFG_CGC_MASK)

#define RF_CMC1_TPM2_CFG_CLK_MUX_SEL_MASK        (0xC00U)
#define RF_CMC1_TPM2_CFG_CLK_MUX_SEL_SHIFT       (10U)
/*! CLK_MUX_SEL - Clock Mux Select
 *  0b00..No clock
 *  0b01..Core Clock
 *  0b10..Radio Oscillator
 *  0b11..Reserved
 */
#define RF_CMC1_TPM2_CFG_CLK_MUX_SEL(x)          (((uint32_t)(((uint32_t)(x)) << RF_CMC1_TPM2_CFG_CLK_MUX_SEL_SHIFT)) & RF_CMC1_TPM2_CFG_CLK_MUX_SEL_MASK)
/*! @} */

/*! @name RADIO_TRIM - Radio Trim Register */
/*! @{ */

#define RF_CMC1_RADIO_TRIM_BG_TRIM_MASK          (0x7U)
#define RF_CMC1_RADIO_TRIM_BG_TRIM_SHIFT         (0U)
/*! BG_TRIM - Bandgap Trim
 *  0b000..787mV
 *  0b001..794mV
 *  0b010..800mV
 *  0b011..806mV
 *  0b100..812mV
 *  0b101..819mV
 *  0b110..825mV
 *  0b111..831mV
 */
#define RF_CMC1_RADIO_TRIM_BG_TRIM(x)            (((uint32_t)(((uint32_t)(x)) << RF_CMC1_RADIO_TRIM_BG_TRIM_SHIFT)) & RF_CMC1_RADIO_TRIM_BG_TRIM_MASK)

#define RF_CMC1_RADIO_TRIM_CM3_PHANTOM_MASK      (0x70U)
#define RF_CMC1_RADIO_TRIM_CM3_PHANTOM_SHIFT     (4U)
/*! CM3_PHANTOM - CM3 Phantom
 *  0b010..CM3 disabled. The RF_CMC will hold the CM3 in reset
 *  0b111..CM3 enabled.
 */
#define RF_CMC1_RADIO_TRIM_CM3_PHANTOM(x)        (((uint32_t)(((uint32_t)(x)) << RF_CMC1_RADIO_TRIM_CM3_PHANTOM_SHIFT)) & RF_CMC1_RADIO_TRIM_CM3_PHANTOM_MASK)
/*! @} */

/*! @name RAM_PWR - RAM Power Control register */
/*! @{ */

#define RF_CMC1_RAM_PWR_SD_EN_MASK               (0x7FFU)
#define RF_CMC1_RAM_PWR_SD_EN_SHIFT              (0U)
/*! SD_EN - Shut Down Enable */
#define RF_CMC1_RAM_PWR_SD_EN(x)                 (((uint32_t)(((uint32_t)(x)) << RF_CMC1_RAM_PWR_SD_EN_SHIFT)) & RF_CMC1_RAM_PWR_SD_EN_MASK)

#define RF_CMC1_RAM_PWR_DS_EN_MASK               (0x7FF0000U)
#define RF_CMC1_RAM_PWR_DS_EN_SHIFT              (16U)
/*! DS_EN - Deep Sleep Enable */
#define RF_CMC1_RAM_PWR_DS_EN(x)                 (((uint32_t)(((uint32_t)(x)) << RF_CMC1_RAM_PWR_DS_EN_SHIFT)) & RF_CMC1_RAM_PWR_DS_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RF_CMC1_Register_Masks */


/*!
 * @}
 */ /* end of group RF_CMC1_Peripheral_Access_Layer */


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


#endif  /* RF_CMC1_H_ */

