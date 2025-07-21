/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_INPUTMUX_CONNECTIONS_
#define _FSL_INPUTMUX_CONNECTIONS_

#include "PERI_INPUTMUX_MAIN.h"
#include "PERI_INPUTMUX_AON.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.inputmux_connections"
#endif

/*! @name Driver version */
/*@{*/
/*! @brief INPUTMUX_CONNECTION driver version 2.0.0. */
#define FSL_INPUTMUX_CONNECTION_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

#define INPUTMUX_GpioPortPinToPintsel(port, pin) ((pin) + (PINTSEL_PMUX_ID << PMUX_SHIFT))

typedef void INPUTMUX_Type;

/* Driver compatibility definitions. */
#define AON__INPUTMUX      ((INPUTMUX_Type *)AON__INPUTMUX1_BASE)
#if __CORTEX_M == (33U) /* Building on the main core */
#define INPUTMUX           ((INPUTMUX_Type *)INPUTMUX0_BASE)
#define INPUTMUX_BASE_PTRS { INPUTMUX0, AON__INPUTMUX1 }
#else
#define INPUTMUX_BASE_PTRS { (INPUTMUX_Type *)0u, AON__INPUTMUX1 }
#endif

/*!
 * @addtogroup inputmux_driver
 * @{
 */

/*!
 * @name Input multiplexing connections
 * @{
 */

/*! @brief Periphinmux IDs */
#if __CORTEX_M == (33U) /* Building on the main core */

#define CTIMER0CAPn_REG  0x20U
#define CTIMER1CAPn_REG  0x40U
#define CTIMER2CAPn_REG  0x60U
#define ADC0_TRIGn_REG   0x280U
#define AOI0_MUXn_REG    0x440U
#define EXT_TRIGn_REG    0x4C0U
#define CTIMER0TRIG_REG  0x30U
#define CTIMER1TRIG_REG  0x50U
#define TIMER2TRIG_REG   0x70U
#define FREQMEAS_REF_REG 0x180U
#define FREQMEAS_TAR_REG 0x184U
#define CMP0_TRIG_REG    0x260U
#define LPI2C0_TRIG_REG  0x5A0U
#define LPI2C1_TRIG_REG  0x5C0U
#define LPSPI0_TRIG_REG  0x5E0U
#define LPSPI1_TRIG_REG  0x600U
#define LPUART0_REG      0x620U
#define LPUART1_REG      0x640U

#endif /* Building on the main core */

#define QTMR0_TMRn_REG                   0x1A0U
#define SOC_GLUE_XOR0_INn_REG            0x1B0U
#define QTMR1_TMRn_REG                   0x1C0U
#define ACMP0_TRIGn_REG                  0x260U
#define LPADC0_TRIGn_REG                 0x280U
#define AON_TRIG_OUTn_REG                0x4C0U
#define SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG 0x1B8U
#define SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG 0x1BCU
#define LC_ROT_SOC_LOGIC_IN_REG          0x1D0U
#define LCSENSE_SEQ_PTRIG_GLUE_IN_REG    0x1D4U
#define LCSENSE_SEQ_TICKS_GLUE_IN_REG    0x1D8U
#define CMP0_SAMPLE_REG                  0x4E0U
#define CMP0_RR_TRIG_REG                 0x4E4U
#define LPI2C0_TRIG_REG                  0x5A0U
#define LPUART0_REG                      0x620U


#define PMUX_SHIFT 20U

typedef enum _inputmux_index_t
{
#if __CORTEX_M == (33U) /* Building on the main core */

    kINPUTMUX_INDEX_CTIMER0CAP0      = 0U,
    kINPUTMUX_INDEX_CTIMER0CAP1      = 1U,
    kINPUTMUX_INDEX_CTIMER0CAP2      = 2U,
    kINPUTMUX_INDEX_CTIMER0CAP3      = 3U,
    kINPUTMUX_INDEX_CTIMER1CAP0      = 0U,
    kINPUTMUX_INDEX_CTIMER1CAP1      = 1U,
    kINPUTMUX_INDEX_CTIMER1CAP2      = 2U,
    kINPUTMUX_INDEX_CTIMER1CAP3      = 3U,
    kINPUTMUX_INDEX_CTIMER2CAP0      = 0U,
    kINPUTMUX_INDEX_CTIMER2CAP1      = 1U,
    kINPUTMUX_INDEX_CTIMER2CAP2      = 2U,
    kINPUTMUX_INDEX_CTIMER2CAP3      = 3U,
    kINPUTMUX_INDEX_ADC0_TRIG0       = 0U,
    kINPUTMUX_INDEX_ADC0_TRIG1       = 1U,
    kINPUTMUX_INDEX_ADC0_TRIG2       = 2U,
    kINPUTMUX_INDEX_ADC0_TRIG3       = 3U,
    kINPUTMUX_INDEX_AOI0_MUX0        = 0U,
    kINPUTMUX_INDEX_AOI0_MUX1        = 1U,
    kINPUTMUX_INDEX_AOI0_MUX2        = 2U,
    kINPUTMUX_INDEX_AOI0_MUX3        = 3U,
    kINPUTMUX_INDEX_AOI0_MUX4        = 4U,
    kINPUTMUX_INDEX_AOI0_MUX5        = 5U,
    kINPUTMUX_INDEX_AOI0_MUX6        = 6U,
    kINPUTMUX_INDEX_AOI0_MUX7        = 7U,
    kINPUTMUX_INDEX_AOI0_MUX8        = 8U,
    kINPUTMUX_INDEX_AOI0_MUX9        = 9U,
    kINPUTMUX_INDEX_AOI0_MUX10       = 10U,
    kINPUTMUX_INDEX_AOI0_MUX11       = 11U,
    kINPUTMUX_INDEX_AOI0_MUX12       = 12U,
    kINPUTMUX_INDEX_AOI0_MUX13       = 13U,
    kINPUTMUX_INDEX_AOI0_MUX14       = 14U,
    kINPUTMUX_INDEX_AOI0_MUX15       = 15U,
    kINPUTMUX_INDEX_EXT_TRIG0        = 0U,
    kINPUTMUX_INDEX_EXT_TRIG1        = 1U,
    kINPUTMUX_INDEX_EXT_TRIG2        = 2U,
    kINPUTMUX_INDEX_EXT_TRIG3        = 3U,
    kINPUTMUX_INDEX_EXT_TRIG4        = 4U,
    kINPUTMUX_INDEX_EXT_TRIG5        = 5U,
    kINPUTMUX_INDEX_EXT_TRIG6        = 6U,
    kINPUTMUX_INDEX_EXT_TRIG7        = 7U,
    kINPUTMUX_INDEX_CTIMER0TRIG      = 0U,
    kINPUTMUX_INDEX_CTIMER1TRIG      = 0U,
    kINPUTMUX_INDEX_TIMER2TRIG       = 0U,
    kINPUTMUX_INDEX_FREQMEAS_REF     = 0U,
    kINPUTMUX_INDEX_FREQMEAS_TAR     = 0U,
    kINPUTMUX_INDEX_CMP0_TRIG        = 0U,
    kINPUTMUX_INDEX_LPI2C0_TRIG      = 0U,
    kINPUTMUX_INDEX_LPI2C1_TRIG      = 0U,
    kINPUTMUX_INDEX_LPSPI0_TRIG      = 0U,
    kINPUTMUX_INDEX_LPSPI1_TRIG      = 0U,
    kINPUTMUX_INDEX_LPUART0          = 0U,
    kINPUTMUX_INDEX_LPUART1          = 0U,

#endif /* Building on the main core */

    kINPUTMUXAON_INDEX_QTMR0_TMR0       = 0U,
    kINPUTMUXAON_INDEX_QTMR0_TMR1       = 1U,
    kINPUTMUXAON_INDEX_QTMR0_TMR2       = 2U,
    kINPUTMUXAON_INDEX_QTMR0_TMR3       = 3U,
    kINPUTMUXAON_INDEX_SOC_GLUE_XOR0_IN0 = 0U,
    kINPUTMUXAON_INDEX_SOC_GLUE_XOR0_IN1 = 1U,
    kINPUTMUXAON_INDEX_QTMR1_TMR0       = 0U,
    kINPUTMUXAON_INDEX_QTMR1_TMR1       = 1U,
    kINPUTMUXAON_INDEX_QTMR1_TMR2       = 2U,
    kINPUTMUXAON_INDEX_QTMR1_TMR3       = 3U,
    kINPUTMUXAON_INDEX_ACMP0_TRIG0      = 0U,
    kINPUTMUXAON_INDEX_ACMP0_TRIG1      = 1U,
    kINPUTMUXAON_INDEX_ACMP0_TRIG2      = 2U,
    kINPUTMUXAON_INDEX_ACMP0_TRIG3      = 3U,
    kINPUTMUXAON_INDEX_LPADC0_TRIG0     = 0U,
    kINPUTMUXAON_INDEX_LPADC0_TRIG1     = 1U,
    kINPUTMUXAON_INDEX_LPADC0_TRIG2     = 2U,
    kINPUTMUXAON_INDEX_LPADC0_TRIG3     = 3U,
    kINPUTMUXAON_INDEX_AON_TRIG_OUT0    = 0U,
    kINPUTMUXAON_INDEX_AON_TRIG_OUT1    = 1U,
    kINPUTMUXAON_INDEX_SOC_GLUE_CMPPADS_PCTRL_XOR_IN0 = 0U,
    kINPUTMUXAON_INDEX_SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0 = 0U,
    kINPUTMUXAON_INDEX_LC_ROT_SOC_LOGIC_IN = 0U,
    kINPUTMUXAON_INDEX_LCSENSE_SEQ_PTRIG_GLUE_IN = 0U,
    kINPUTMUXAON_INDEX_LCSENSE_SEQ_TICKS_GLUE_IN = 0U,
    kINPUTMUXAON_INDEX_CMP0_SAMPLE      = 0U,
    kINPUTMUXAON_INDEX_CMP0_RR_TRIG     = 0U,
    kINPUTMUXAON_INDEX_LPI2C0_TRIG      = 0U,
    kINPUTMUXAON_INDEX_LPUART0          = 0U,

} inputmux_index_t;

/*! @brief INPUTMUX connections type */
typedef enum _inputmux_connection_t
{
#if __CORTEX_M == (33U) /* Building on the main core */

    /*!< CTIMER0CAPn: Capture select register for CTIMER0 inputs */
    kINPUTMUX_CtInp0ToCTIMER0CAPn                  = 1U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp0 input is selected */
    kINPUTMUX_CtInp1ToCTIMER0CAPn                  = 2U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp1 input is selected */
    kINPUTMUX_CtInp2ToCTIMER0CAPn                  = 3U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp2 input is selected */
    kINPUTMUX_CtInp3ToCTIMER0CAPn                  = 4U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp3 input is selected */
    kINPUTMUX_CtInp4ToCTIMER0CAPn                  = 5U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp4 input is selected */
    kINPUTMUX_CtInp5ToCTIMER0CAPn                  = 6U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp5 input is selected */
    kINPUTMUX_CtInp6ToCTIMER0CAPn                  = 7U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp6 input is selected */
    kINPUTMUX_CtInp7ToCTIMER0CAPn                  = 8U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp7 input is selected */
    kINPUTMUX_CtInp8ToCTIMER0CAPn                  = 9U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp8 input is selected */
    kINPUTMUX_CtInp9ToCTIMER0CAPn                  = 10U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp9 input is selected */
    kINPUTMUX_CtInp10ToCTIMER0CAPn                 = 11U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp10 input is selected */
    kINPUTMUX_CtInp11ToCTIMER0CAPn                 = 12U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp11 input is selected */
    kINPUTMUX_CtInp12ToCTIMER0CAPn                 = 13U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp12 input is selected */
    kINPUTMUX_CtInp13ToCTIMER0CAPn                 = 14U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp13 input is selected */
    kINPUTMUX_CtInp14ToCTIMER0CAPn                 = 15U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp14 input is selected */
    kINPUTMUX_CtInp15ToCTIMER0CAPn                 = 16U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp15 input is selected */
    kINPUTMUX_CtInp16ToCTIMER0CAPn                 = 17U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp16 input is selected */
    kINPUTMUX_CtInp17ToCTIMER0CAPn                 = 18U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp17 input is selected */
    kINPUTMUX_CtInp18ToCTIMER0CAPn                 = 19U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp18 input is selected */
    kINPUTMUX_CtInp19ToCTIMER0CAPn                 = 20U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ct_inp19 input is selected */
    kINPUTMUX_Aoi0Out0ToCTIMER0CAPn                = 22U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToCTIMER0CAPn                = 23U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToCTIMER0CAPn                = 24U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToCTIMER0CAPn                = 25U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Adc0Tcomp0ToCTIMER0CAPn              = 26U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[0] */
    kINPUTMUX_Adc0Tcomp1ToCTIMER0CAPn              = 27U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[1] */
    kINPUTMUX_Adc0Tcomp2ToCTIMER0CAPn              = 28U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[2] */
    kINPUTMUX_Adc0Tcomp3ToCTIMER0CAPn              = 29U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[3] input is selected */
    kINPUTMUX_Cmp0OutToCTIMER0CAPn                 = 30U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< cmp0_out is selected */
    kINPUTMUX_Ctimer1Mat1ToCTIMER0CAPn             = 33U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat2ToCTIMER0CAPn             = 34U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToCTIMER0CAPn             = 35U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat1ToCTIMER0CAPn             = 36U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat2ToCTIMER0CAPn             = 37U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToCTIMER0CAPn             = 38U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Lpi2c0CeopToCTIMER0CAPn              = 48U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpi2c0 controller end of packet input is selected */
    kINPUTMUX_Lpi2c0TeopToCTIMER0CAPn              = 49U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpi2c0 target end of packet input is selected */
    kINPUTMUX_Lpi2c1CeopToCTIMER0CAPn              = 50U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpi2c1 controller end of packet input is selected */
    kINPUTMUX_Lpi2c1TeopToCTIMER0CAPn              = 51U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpi2c1 target end of packet input is selected */
    kINPUTMUX_Lpspi0EofToCTIMER0CAPn               = 52U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpspi0 end of frame input is selected */
    kINPUTMUX_Lpspi0RdwToCTIMER0CAPn               = 53U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpspi0 received data word input is selected */
    kINPUTMUX_Lpspi1EofToCTIMER0CAPn               = 54U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpspi1 end of frame input is selected */
    kINPUTMUX_Lpspi1RdwToCTIMER0CAPn               = 55U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpspi1 received data word input is selected */
    kINPUTMUX_Lpuart0RdwToCTIMER0CAPn              = 56U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 received data word input is selected */
    kINPUTMUX_Lpuart0TdwToCTIMER0CAPn              = 57U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word input is selected */
    kINPUTMUX_Lpuart0RliToCTIMER0CAPn              = 58U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle input is selected */
    kINPUTMUX_Lpuart1RdwToCTIMER0CAPn              = 59U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 received data word input is selected */
    kINPUTMUX_Lpuart1TdwToCTIMER0CAPn              = 60U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 transmitted data word input is selected */
    kINPUTMUX_Lpuart1RliToCTIMER0CAPn              = 61U + (CTIMER0CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 receive line idle input is selected */

    /*!< CTIMER1CAPn: Capture select register for CTIMER1 inputs */
    kINPUTMUX_CtInp0ToCTIMER1CAPn                  = 1U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp0 input is selected */
    kINPUTMUX_CtInp1ToCTIMER1CAPn                  = 2U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp1 input is selected */
    kINPUTMUX_CtInp2ToCTIMER1CAPn                  = 3U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp2 input is selected */
    kINPUTMUX_CtInp3ToCTIMER1CAPn                  = 4U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp3 input is selected */
    kINPUTMUX_CtInp5ToCTIMER1CAPn                  = 6U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp5 input is selected */
    kINPUTMUX_CtInp6ToCTIMER1CAPn                  = 7U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp6 input is selected */
    kINPUTMUX_CtInp7ToCTIMER1CAPn                  = 8U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp7 input is selected */
    kINPUTMUX_CtInp8ToCTIMER1CAPn                  = 9U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp8 input is selected */
    kINPUTMUX_CtInp9ToCTIMER1CAPn                  = 10U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp9 input is selected */
    kINPUTMUX_CtInp10ToCTIMER1CAPn                 = 11U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp10 input is selected */
    kINPUTMUX_CtInp11ToCTIMER1CAPn                 = 12U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp11 input is selected */
    kINPUTMUX_CtInp12ToCTIMER1CAPn                 = 13U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp12 input is selected */
    kINPUTMUX_CtInp13ToCTIMER1CAPn                 = 14U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp13 input is selected */
    kINPUTMUX_CtInp14ToCTIMER1CAPn                 = 15U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp14 input is selected */
    kINPUTMUX_CtInp15ToCTIMER1CAPn                 = 16U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp15 input is selected */
    kINPUTMUX_CtInp16ToCTIMER1CAPn                 = 17U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp16 input is selected */
    kINPUTMUX_CtInp17ToCTIMER1CAPn                 = 18U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp17 input is selected */
    kINPUTMUX_CtInp18ToCTIMER1CAPn                 = 19U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp18 input is selected */
    kINPUTMUX_CtInp19ToCTIMER1CAPn                 = 20U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ct_inp19 input is selected */
    kINPUTMUX_Aoi0Out0ToCTIMER1CAPn                = 22U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToCTIMER1CAPn                = 23U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToCTIMER1CAPn                = 24U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToCTIMER1CAPn                = 25U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Adc0Tcomp0ToCTIMER1CAPn              = 26U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[0] */
    kINPUTMUX_Adc0Tcomp1ToCTIMER1CAPn              = 27U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[1] */
    kINPUTMUX_Adc0Tcomp2ToCTIMER1CAPn              = 28U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[2] */
    kINPUTMUX_Adc0Tcomp3ToCTIMER1CAPn              = 29U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[3] input is selected */
    kINPUTMUX_Cmp0OutToCTIMER1CAPn                 = 30U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< cmp0_out is selected */
    kINPUTMUX_Ctimer0Mat1ToCTIMER1CAPn             = 33U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer0Mat2ToCTIMER1CAPn             = 34U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToCTIMER1CAPn             = 35U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat1ToCTIMER1CAPn             = 36U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat2ToCTIMER1CAPn             = 37U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToCTIMER1CAPn             = 38U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Lpi2c0CeopToCTIMER1CAPn              = 48U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpi2c0 controller end of packet input is selected */
    kINPUTMUX_Lpi2c0TeopToCTIMER1CAPn              = 49U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpi2c0 target end of packet input is selected */
    kINPUTMUX_Lpi2c1CeopToCTIMER1CAPn              = 50U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpi2c1 controller end of packet input is selected */
    kINPUTMUX_Lpi2c1TeopToCTIMER1CAPn              = 51U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpi2c1 target end of packet input is selected */
    kINPUTMUX_Lpspi0EofToCTIMER1CAPn               = 52U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpspi0 end of frame input is selected */
    kINPUTMUX_Lpspi0RdwToCTIMER1CAPn               = 53U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpspi0 received data word input is selected */
    kINPUTMUX_Lpspi1EofToCTIMER1CAPn               = 54U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpspi1 end of frame input is selected */
    kINPUTMUX_Lpspi1RdwToCTIMER1CAPn               = 55U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpspi1 received data word input is selected */
    kINPUTMUX_Lpuart0RdwToCTIMER1CAPn              = 56U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 received data word input is selected */
    kINPUTMUX_Lpuart0TdwToCTIMER1CAPn              = 57U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word input is selected */
    kINPUTMUX_Lpuart0RliToCTIMER1CAPn              = 58U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle input is selected */
    kINPUTMUX_Lpuart1RdwToCTIMER1CAPn              = 59U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 received data word input is selected */
    kINPUTMUX_Lpuart1TdwToCTIMER1CAPn              = 60U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 transmitted data word input is selected */
    kINPUTMUX_Lpuart1RliToCTIMER1CAPn              = 61U + (CTIMER1CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 receive line idle input is selected */

    /*!< CTIMER2CAPn: Capture select register for CTIMER2 inputs */
    kINPUTMUX_CtInp0ToCTIMER2CAPn                  = 1U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp0 input is selected */
    kINPUTMUX_CtInp1ToCTIMER2CAPn                  = 2U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp1 input is selected */
    kINPUTMUX_CtInp2ToCTIMER2CAPn                  = 3U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp2 input is selected */
    kINPUTMUX_CtInp3ToCTIMER2CAPn                  = 4U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp3 input is selected */
    kINPUTMUX_CtInp5ToCTIMER2CAPn                  = 6U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp5 input is selected */
    kINPUTMUX_CtInp6ToCTIMER2CAPn                  = 7U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp6 input is selected */
    kINPUTMUX_CtInp7ToCTIMER2CAPn                  = 8U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp7 input is selected */
    kINPUTMUX_CtInp8ToCTIMER2CAPn                  = 9U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp8 input is selected */
    kINPUTMUX_CtInp9ToCTIMER2CAPn                  = 10U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp9 input is selected */
    kINPUTMUX_CtInp10ToCTIMER2CAPn                 = 11U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp10 input is selected */
    kINPUTMUX_CtInp11ToCTIMER2CAPn                 = 12U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp11 input is selected */
    kINPUTMUX_CtInp12ToCTIMER2CAPn                 = 13U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp12 input is selected */
    kINPUTMUX_CtInp13ToCTIMER2CAPn                 = 14U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp13 input is selected */
    kINPUTMUX_CtInp14ToCTIMER2CAPn                 = 15U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp14 input is selected */
    kINPUTMUX_CtInp15ToCTIMER2CAPn                 = 16U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp15 input is selected */
    kINPUTMUX_CtInp16ToCTIMER2CAPn                 = 17U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp16 input is selected */
    kINPUTMUX_CtInp17ToCTIMER2CAPn                 = 18U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp17 input is selected */
    kINPUTMUX_CtInp18ToCTIMER2CAPn                 = 19U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp18 input is selected */
    kINPUTMUX_CtInp19ToCTIMER2CAPn                 = 20U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ct_inp19 input is selected */
    kINPUTMUX_Aoi0Out0ToCTIMER2CAPn                = 22U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToCTIMER2CAPn                = 23U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToCTIMER2CAPn                = 24U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToCTIMER2CAPn                = 25U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Adc0Tcomp0ToCTIMER2CAPn              = 26U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[0] */
    kINPUTMUX_Adc0Tcomp1ToCTIMER2CAPn              = 27U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[1] */
    kINPUTMUX_Adc0Tcomp2ToCTIMER2CAPn              = 28U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[2] */
    kINPUTMUX_Adc0Tcomp3ToCTIMER2CAPn              = 29U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[3] input is selected */
    kINPUTMUX_Cmp0OutToCTIMER2CAPn                 = 30U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< cmp0_out is selected */
    kINPUTMUX_Ctimer0Mat1ToCTIMER2CAPn             = 33U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer0Mat2ToCTIMER2CAPn             = 34U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToCTIMER2CAPn             = 35U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat1ToCTIMER2CAPn             = 36U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat2ToCTIMER2CAPn             = 37U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToCTIMER2CAPn             = 38U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Lpi2c0CeopToCTIMER2CAPn              = 48U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpi2c0 controller end of packet input is selected */
    kINPUTMUX_Lpi2c0TeopToCTIMER2CAPn              = 49U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpi2c0 target end of packet input is selected */
    kINPUTMUX_Lpi2c1CeopToCTIMER2CAPn              = 50U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpi2c1 controller end of packet input is selected */
    kINPUTMUX_Lpi2c1TeopToCTIMER2CAPn              = 51U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpi2c1 target end of packet input is selected */
    kINPUTMUX_Lpspi0EofToCTIMER2CAPn               = 52U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpspi0 end of frame input is selected */
    kINPUTMUX_Lpspi0RdwToCTIMER2CAPn               = 53U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpspi0 received data word input is selected */
    kINPUTMUX_Lpspi1EofToCTIMER2CAPn               = 54U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpspi1 end of frame input is selected */
    kINPUTMUX_Lpspi1RdwToCTIMER2CAPn               = 55U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpspi1 received data word input is selected */
    kINPUTMUX_Lpuart0RdwToCTIMER2CAPn              = 56U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 received data word input is selected */
    kINPUTMUX_Lpuart0TdwToCTIMER2CAPn              = 57U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word input is selected */
    kINPUTMUX_Lpuart0RliToCTIMER2CAPn              = 58U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle input is selected */
    kINPUTMUX_Lpuart1RdwToCTIMER2CAPn              = 59U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 received data word input is selected */
    kINPUTMUX_Lpuart1TdwToCTIMER2CAPn              = 60U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 transmitted data word input is selected */
    kINPUTMUX_Lpuart1RliToCTIMER2CAPn              = 61U + (CTIMER2CAPn_REG << PMUX_SHIFT),  /*!< lpuart1 receive line idle input is selected */

    /*!< ADC0_TRIGn: ADC Trigger Input Connections */
    kINPUTMUX_ArmTxevToAdc0Trign                   = 1U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToAdc0Trign                  = 2U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToAdc0Trign                  = 3U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToAdc0Trign                  = 4U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToAdc0Trign                  = 5U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToAdc0Trign                   = 6U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat0ToAdc0Trign               = 9U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< ctimer0_mat0 input is selected */
    kINPUTMUX_Ctimer0Mat1ToAdc0Trign               = 10U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat0ToAdc0Trign               = 11U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< ctimer1_mat0 input is selected */
    kINPUTMUX_Ctimer1Mat1ToAdc0Trign               = 12U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat0ToAdc0Trign               = 13U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< ctimer2_mat0 input is selected */
    kINPUTMUX_Ctimer2Mat1ToAdc0Trign               = 14U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Gpio1Pet0ToAdc0Trign                 = 27U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToAdc0Trign                 = 28U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToAdc0Trign                 = 29U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToAdc0Trign                       = 31U + (ADC0_TRIGn_REG << PMUX_SHIFT),  /*!< wuu */

    /*!< AOI0_MUXn: AOI0 Trigger Input Connections */
    kINPUTMUX_Adc0Tcomp0ToAoi0Muxn                 = 1U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[0] input is selected */
    kINPUTMUX_Adc0Tcomp1ToAoi0Muxn                 = 2U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[1] input is selected */
    kINPUTMUX_Adc0Tcomp2ToAoi0Muxn                 = 3U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[2] input is selected */
    kINPUTMUX_Adc0Tcomp3ToAoi0Muxn                 = 4U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< adc0_tcomp[3] input is selected */
    kINPUTMUX_Cmp0OutToAoi0Muxn                    = 5U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat0ToAoi0Muxn                = 8U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< ctimer0_mat0 input is selected */
    kINPUTMUX_Ctimer0Mat1ToAoi0Muxn                = 9U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer0Mat2ToAoi0Muxn                = 10U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToAoi0Muxn                = 11U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat0ToAoi0Muxn                = 12U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< ctimer1_mat0 input is selected */
    kINPUTMUX_Ctimer1Mat1ToAoi0Muxn                = 13U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat2ToAoi0Muxn                = 14U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToAoi0Muxn                = 15U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat0ToAoi0Muxn                = 16U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< ctimer2_mat0 input is selected */
    kINPUTMUX_Ctimer2Mat1ToAoi0Muxn                = 17U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat2ToAoi0Muxn                = 18U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToAoi0Muxn                = 19U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToAoi0Muxn                    = 35U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToAoi0Muxn                    = 36U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToAoi0Muxn                    = 37U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToAoi0Muxn                    = 38U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToAoi0Muxn                    = 39U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToAoi0Muxn                    = 40U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToAoi0Muxn                    = 41U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToAoi0Muxn                    = 42U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToAoi0Muxn                    = 43U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToAoi0Muxn                    = 44U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToAoi0Muxn                   = 45U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToAoi0Muxn                   = 46U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio1Pet0ToAoi0Muxn                  = 48U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToAoi0Muxn                  = 49U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToAoi0Muxn                  = 50U + (AOI0_MUXn_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */

    /*!< EXT_TRIGn: EXT Trigger Connections */
    kINPUTMUX_ArmTxevToExtTrign                    = 1U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToExtTrign                   = 2U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToExtTrign                   = 3U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToExtTrign                   = 4U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToExtTrign                   = 5U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToExtTrign                    = 6U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Lpuart0ToExtTrign                    = 9U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< lpuart0 input is selected */
    kINPUTMUX_Lpuart1ToExtTrign                    = 10U + (EXT_TRIGn_REG << PMUX_SHIFT),  /*!< lpuart1 input is selected */

    /*!< CTIMER0TRIG: Trigger register for CTIMER0 */
    kINPUTMUX_CtInp0ToCTIMER0TRIG                  = 1U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp0 input is selected */
    kINPUTMUX_CtInp1ToCTIMER0TRIG                  = 2U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp1 input is selected */
    kINPUTMUX_CtInp2ToCTIMER0TRIG                  = 3U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp2 input is selected */
    kINPUTMUX_CtInp3ToCTIMER0TRIG                  = 4U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp3 input is selected */
    kINPUTMUX_CtInp4ToCTIMER0TRIG                  = 5U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp4 input is selected */
    kINPUTMUX_CtInp5ToCTIMER0TRIG                  = 6U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp5 input is selected */
    kINPUTMUX_CtInp6ToCTIMER0TRIG                  = 7U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp6 input is selected */
    kINPUTMUX_CtInp7ToCTIMER0TRIG                  = 8U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp7 input is selected */
    kINPUTMUX_CtInp8ToCTIMER0TRIG                  = 9U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp8 input is selected */
    kINPUTMUX_CtInp9ToCTIMER0TRIG                  = 10U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp9 input is selected */
    kINPUTMUX_CtInp10ToCTIMER0TRIG                 = 11U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp10 input is selected */
    kINPUTMUX_CtInp11ToCTIMER0TRIG                 = 12U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp11 input is selected */
    kINPUTMUX_CtInp12ToCTIMER0TRIG                 = 13U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp12 input is selected */
    kINPUTMUX_CtInp13ToCTIMER0TRIG                 = 14U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp13 input is selected */
    kINPUTMUX_CtInp14ToCTIMER0TRIG                 = 15U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp14 input is selected */
    kINPUTMUX_CtInp15ToCTIMER0TRIG                 = 16U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp15 input is selected */
    kINPUTMUX_CtInp16ToCTIMER0TRIG                 = 17U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp16 input is selected */
    kINPUTMUX_CtInp17ToCTIMER0TRIG                 = 18U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp17 input is selected */
    kINPUTMUX_CtInp18ToCTIMER0TRIG                 = 19U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp18 input is selected */
    kINPUTMUX_CtInp19ToCTIMER0TRIG                 = 20U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ct_inp19 input is selected */
    kINPUTMUX_Aoi0Out0ToCTIMER0TRIG                = 22U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToCTIMER0TRIG                = 23U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToCTIMER0TRIG                = 24U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToCTIMER0TRIG                = 25U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Adc0Tcomp0ToCTIMER0TRIG              = 26U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[0] */
    kINPUTMUX_Adc0Tcomp1ToCTIMER0TRIG              = 27U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[1] */
    kINPUTMUX_Adc0Tcomp2ToCTIMER0TRIG              = 28U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[2] */
    kINPUTMUX_Adc0Tcomp3ToCTIMER0TRIG              = 29U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[3] input is selected */
    kINPUTMUX_Cmp0OutToCTIMER0TRIG                 = 30U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out is selected */
    kINPUTMUX_Ctimer1Mat1ToCTIMER0TRIG             = 33U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat2ToCTIMER0TRIG             = 34U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToCTIMER0TRIG             = 35U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat1ToCTIMER0TRIG             = 36U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat2ToCTIMER0TRIG             = 37U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToCTIMER0TRIG             = 38U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Lpi2c0CeopToCTIMER0TRIG              = 48U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpi2c0 controller end of packet input is selected */
    kINPUTMUX_Lpi2c0TeopToCTIMER0TRIG              = 49U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpi2c0 target end of packet input is selected */
    kINPUTMUX_Lpi2c1CeopToCTIMER0TRIG              = 50U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpi2c1 controller end of packet input is selected */
    kINPUTMUX_Lpi2c1TeopToCTIMER0TRIG              = 51U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpi2c1 target end of packet input is selected */
    kINPUTMUX_Lpspi0EofToCTIMER0TRIG               = 52U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpspi0 end of frame input is selected */
    kINPUTMUX_Lpspi0RdwToCTIMER0TRIG               = 53U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpspi0 received data word input is selected */
    kINPUTMUX_Lpspi1EofToCTIMER0TRIG               = 54U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpspi1 end of frame input is selected */
    kINPUTMUX_Lpspi1RdwToCTIMER0TRIG               = 55U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpspi1 received data word input is selected */
    kINPUTMUX_Lpuart0RdwToCTIMER0TRIG              = 56U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 received data word input is selected */
    kINPUTMUX_Lpuart0TdwToCTIMER0TRIG              = 57U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word input is selected */
    kINPUTMUX_Lpuart0RliToCTIMER0TRIG              = 58U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle input is selected */
    kINPUTMUX_Lpuart1RdwToCTIMER0TRIG              = 59U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 received data word input is selected */
    kINPUTMUX_Lpuart1TdwToCTIMER0TRIG              = 60U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 transmitted data word input is selected */
    kINPUTMUX_Lpuart1RliToCTIMER0TRIG              = 61U + (CTIMER0TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 receive line idle input is selected */

    /*!< CTIMER1TRIG: Trigger register for CTIMER1 */
    kINPUTMUX_CtInp0ToCTIMER1TRIG                  = 1U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp0 input is selected */
    kINPUTMUX_CtInp1ToCTIMER1TRIG                  = 2U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp1 input is selected */
    kINPUTMUX_CtInp2ToCTIMER1TRIG                  = 3U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp2 input is selected */
    kINPUTMUX_CtInp3ToCTIMER1TRIG                  = 4U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp3 input is selected */
    kINPUTMUX_CtInp5ToCTIMER1TRIG                  = 6U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp5 input is selected */
    kINPUTMUX_CtInp6ToCTIMER1TRIG                  = 7U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp6 input is selected */
    kINPUTMUX_CtInp7ToCTIMER1TRIG                  = 8U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp7 input is selected */
    kINPUTMUX_CtInp8ToCTIMER1TRIG                  = 9U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp8 input is selected */
    kINPUTMUX_CtInp9ToCTIMER1TRIG                  = 10U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp9 input is selected */
    kINPUTMUX_CtInp10ToCTIMER1TRIG                 = 11U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp10 input is selected */
    kINPUTMUX_CtInp11ToCTIMER1TRIG                 = 12U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp11 input is selected */
    kINPUTMUX_CtInp12ToCTIMER1TRIG                 = 13U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp12 input is selected */
    kINPUTMUX_CtInp13ToCTIMER1TRIG                 = 14U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp13 input is selected */
    kINPUTMUX_CtInp14ToCTIMER1TRIG                 = 15U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp14 input is selected */
    kINPUTMUX_CtInp15ToCTIMER1TRIG                 = 16U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp15 input is selected */
    kINPUTMUX_CtInp16ToCTIMER1TRIG                 = 17U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp16 input is selected */
    kINPUTMUX_CtInp17ToCTIMER1TRIG                 = 18U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp17 input is selected */
    kINPUTMUX_CtInp18ToCTIMER1TRIG                 = 19U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp18 input is selected */
    kINPUTMUX_CtInp19ToCTIMER1TRIG                 = 20U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ct_inp19 input is selected */
    kINPUTMUX_Aoi0Out0ToCTIMER1TRIG                = 22U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToCTIMER1TRIG                = 23U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToCTIMER1TRIG                = 24U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToCTIMER1TRIG                = 25U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Adc0Tcomp0ToCTIMER1TRIG              = 26U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[0] */
    kINPUTMUX_Adc0Tcomp1ToCTIMER1TRIG              = 27U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[1] */
    kINPUTMUX_Adc0Tcomp2ToCTIMER1TRIG              = 28U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[2] */
    kINPUTMUX_Adc0Tcomp3ToCTIMER1TRIG              = 29U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[3] input is selected */
    kINPUTMUX_Cmp0OutToCTIMER1TRIG                 = 30U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out is selected */
    kINPUTMUX_Ctimer0Mat1ToCTIMER1TRIG             = 33U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer0Mat2ToCTIMER1TRIG             = 34U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToCTIMER1TRIG             = 35U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat1ToCTIMER1TRIG             = 36U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat2ToCTIMER1TRIG             = 37U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToCTIMER1TRIG             = 38U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_Lpi2c0CeopToCTIMER1TRIG              = 48U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpi2c0 controller end of packet input is selected */
    kINPUTMUX_Lpi2c0TeopToCTIMER1TRIG              = 49U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpi2c0 target end of packet input is selected */
    kINPUTMUX_Lpi2c1CeopToCTIMER1TRIG              = 50U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpi2c1 controller end of packet input is selected */
    kINPUTMUX_Lpi2c1TeopToCTIMER1TRIG              = 51U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpi2c1 target end of packet input is selected */
    kINPUTMUX_Lpspi0EofToCTIMER1TRIG               = 52U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpspi0 end of frame input is selected */
    kINPUTMUX_Lpspi0RdwToCTIMER1TRIG               = 53U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpspi0 received data word input is selected */
    kINPUTMUX_Lpspi1EofToCTIMER1TRIG               = 54U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpspi1 end of frame input is selected */
    kINPUTMUX_Lpspi1RdwToCTIMER1TRIG               = 55U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpspi1 received data word input is selected */
    kINPUTMUX_Lpuart0RdwToCTIMER1TRIG              = 56U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 received data word input is selected */
    kINPUTMUX_Lpuart0TdwToCTIMER1TRIG              = 57U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word input is selected */
    kINPUTMUX_Lpuart0RliToCTIMER1TRIG              = 58U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle input is selected */
    kINPUTMUX_Lpuart1RdwToCTIMER1TRIG              = 59U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 received data word input is selected */
    kINPUTMUX_Lpuart1TdwToCTIMER1TRIG              = 60U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 transmitted data word input is selected */
    kINPUTMUX_Lpuart1RliToCTIMER1TRIG              = 61U + (CTIMER1TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 receive line idle input is selected */

    /*!< TIMER2TRIG: Trigger register for CTIMER2 inputs */
    kINPUTMUX_CtInp0ToTIMER2TRIG                   = 1U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp0 input is selected */
    kINPUTMUX_CtInp1ToTIMER2TRIG                   = 2U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp1 input is selected */
    kINPUTMUX_CtInp2ToTIMER2TRIG                   = 3U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp2 input is selected */
    kINPUTMUX_CtInp3ToTIMER2TRIG                   = 4U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp3 input is selected */
    kINPUTMUX_CtInp5ToTIMER2TRIG                   = 6U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp5 input is selected */
    kINPUTMUX_CtInp6ToTIMER2TRIG                   = 7U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp6 input is selected */
    kINPUTMUX_CtInp7ToTIMER2TRIG                   = 8U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp7 input is selected */
    kINPUTMUX_CtInp8ToTIMER2TRIG                   = 9U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp8 input is selected */
    kINPUTMUX_CtInp9ToTIMER2TRIG                   = 10U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp9 input is selected */
    kINPUTMUX_CtInp10ToTIMER2TRIG                  = 11U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp10 input is selected */
    kINPUTMUX_CtInp11ToTIMER2TRIG                  = 12U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp11 input is selected */
    kINPUTMUX_CtInp12ToTIMER2TRIG                  = 13U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp12 input is selected */
    kINPUTMUX_CtInp13ToTIMER2TRIG                  = 14U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp13 input is selected */
    kINPUTMUX_CtInp14ToTIMER2TRIG                  = 15U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp14 input is selected */
    kINPUTMUX_CtInp15ToTIMER2TRIG                  = 16U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp15 input is selected */
    kINPUTMUX_CtInp16ToTIMER2TRIG                  = 17U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp16 input is selected */
    kINPUTMUX_CtInp17ToTIMER2TRIG                  = 18U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp17 input is selected */
    kINPUTMUX_CtInp18ToTIMER2TRIG                  = 19U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp18 input is selected */
    kINPUTMUX_CtInp19ToTIMER2TRIG                  = 20U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ct_inp19 input is selected */
    kINPUTMUX_Aoi0Out0ToTIMER2TRIG                 = 22U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToTIMER2TRIG                 = 23U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToTIMER2TRIG                 = 24U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToTIMER2TRIG                 = 25U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Adc0Tcomp0ToTIMER2TRIG               = 26U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[0] */
    kINPUTMUX_Adc0Tcomp1ToTIMER2TRIG               = 27U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[1] */
    kINPUTMUX_Adc0Tcomp2ToTIMER2TRIG               = 28U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[2] */
    kINPUTMUX_Adc0Tcomp3ToTIMER2TRIG               = 29U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< adc0_tcomp[3] input is selected */
    kINPUTMUX_Cmp0OutToTIMER2TRIG                  = 30U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out is selected */
    kINPUTMUX_Ctimer0Mat1ToTIMER2TRIG              = 33U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer0Mat2ToTIMER2TRIG              = 34U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToTIMER2TRIG              = 35U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat1ToTIMER2TRIG              = 36U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat2ToTIMER2TRIG              = 37U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToTIMER2TRIG              = 38U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Lpi2c0CeopToTIMER2TRIG               = 48U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpi2c0 controller end of packet input is selected */
    kINPUTMUX_Lpi2c0TeopToTIMER2TRIG               = 49U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpi2c0 target end of packet input is selected */
    kINPUTMUX_Lpi2c1CeopToTIMER2TRIG               = 50U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpi2c1 controller end of packet input is selected */
    kINPUTMUX_Lpi2c1TeopToTIMER2TRIG               = 51U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpi2c1 target end of packet input is selected */
    kINPUTMUX_Lpspi0EofToTIMER2TRIG                = 52U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpspi0 end of frame input is selected */
    kINPUTMUX_Lpspi0RdwToTIMER2TRIG                = 53U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpspi0 received data word input is selected */
    kINPUTMUX_Lpspi1EofToTIMER2TRIG                = 54U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpspi1 end of frame input is selected */
    kINPUTMUX_Lpspi1RdwToTIMER2TRIG                = 55U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpspi1 received data word input is selected */
    kINPUTMUX_Lpuart0RdwToTIMER2TRIG               = 56U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 received data word input is selected */
    kINPUTMUX_Lpuart0TdwToTIMER2TRIG               = 57U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word input is selected */
    kINPUTMUX_Lpuart0RliToTIMER2TRIG               = 58U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle input is selected */
    kINPUTMUX_Lpuart1RdwToTIMER2TRIG               = 59U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 received data word input is selected */
    kINPUTMUX_Lpuart1TdwToTIMER2TRIG               = 60U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 transmitted data word input is selected */
    kINPUTMUX_Lpuart1RliToTIMER2TRIG               = 61U + (TIMER2TRIG_REG << PMUX_SHIFT),  /*!< lpuart1 receive line idle input is selected */

    /*!< FREQMEAS_REF: Selection for frequency measurement reference clock */
    kINPUTMUX_Fro12mToFreqmeasRef                  = 2U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< fro12m input is selected */
    kINPUTMUX_FroHfDivToFreqmeasRef                = 3U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< fro_hf_div input is selected */
    kINPUTMUX_Xtal32k2ToFreqmeasRef                = 4U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< xtal32k[2] input is selected */
    kINPUTMUX_Clk16k0ToFreqmeasRef                 = 5U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< clk_16k[0] input is selected */
    kINPUTMUX_SlowClkToFreqmeasRef                 = 6U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< slow_clk input is selected */
    kINPUTMUX_FreqmeClkIn0ToFreqmeasRef            = 7U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< freqme_clk_in0 input is selected */
    kINPUTMUX_FreqmeClkIn1IToFreqmeasRef           = 8U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< freqme_clk_in1 input is selected input is selected */
    kINPUTMUX_Aoi0Out0ToFreqmeasRef                = 9U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFreqmeasRef                = 10U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< aoi0_out1 */
    kINPUTMUX_ScgFircClkTestToFreqmeasRef          = 17U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< scg_firc_clk_test */
    kINPUTMUX_FirstFailClkInToFreqmeasRef          = 18U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< first_fail_clk_in */
    kINPUTMUX_ClkIomuxIppScgIppDoScgClkoutToFreqmeasRef = 19U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< clk__iomux__ipp__scg__ipp_do_scg_clkout */
    kINPUTMUX_MtrBistHeartbeatToFreqmeasRef        = 20U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< mtr_bist_heartbeat */
    kINPUTMUX_AonAdvcVdd1p0TestSfaToFreqmeasRef    = 21U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< aon_advc_vdd1p0_test_sfa */
    kINPUTMUX_AonAdvcVddTestSfaToFreqmeasRef       = 22U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< aon_advc_vdd_test_sfa */
    kINPUTMUX_AonAdvcPmcDelayCellOutSfaToFreqmeasRef = 23U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< aon_advc_pmc_delay_cell_out_sfa */
    kINPUTMUX_AonAdvcPmcExpTmrOutSfaToFreqmeasRef  = 24U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< aon_advc_pmc_exp_tmr_out_sfa */
    kINPUTMUX_AonAdvcFro16kClkoutSfaToFreqmeasRef  = 25U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< aon_advc_fro16k_clkout_sfa */
    kINPUTMUX_AonAdvcAonCpuClkToFreqmeasRef        = 26U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< aon_advc_aon_cpu_clk */
    kINPUTMUX_RtcAonTstDigOutToFreqmeasRef         = 27U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< rtc_aon_tst_dig_out */
    kINPUTMUX_Fro10mCndipToFreqmeasRef             = 28U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< fro_10m clock (no divider in path) */
    kINPUTMUX_FroHfNdipToFreqmeasRef               = 29U + (FREQMEAS_REF_REG << PMUX_SHIFT),  /*!< fro_hf (no divider in path) */

    /*!< FREQMEAS_TAR: Selection for frequency measurement target clock */
    kINPUTMUX_Fro12mToFreqmeasTar                  = 2U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< fro12m input is selected */
    kINPUTMUX_FroHfDivToFreqmeasTar                = 3U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< fro_hf_div input is selected */
    kINPUTMUX_Xtal32k2ToFreqmeasTar                = 4U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< xtal32k[2] input is selected */
    kINPUTMUX_Clk16k0ToFreqmeasTar                 = 5U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< clk_16k[0] input is selected */
    kINPUTMUX_SlowClkToFreqmeasTar                 = 6U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< slow_clk input is selected */
    kINPUTMUX_FreqmeClkIn0ToFreqmeasTar            = 7U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< freqme_clk_in0 input is selected */
    kINPUTMUX_FreqmeClkIn1IToFreqmeasTar           = 8U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< freqme_clk_in1 input is selected input is selected */
    kINPUTMUX_Aoi0Out0ToFreqmeasTar                = 9U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToFreqmeasTar                = 10U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< aoi0_out1 */
    kINPUTMUX_FirstFailClkInToFreqmeasTar          = 18U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< first_fail_clk_in */
    kINPUTMUX_ClkIomuxIppScgIppDoScgClkoutToFreqmeasTar = 19U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< clk__iomux__ipp__scg__ipp_do_scg_clkout */
    kINPUTMUX_MtrBistHeartbeatToFreqmeasTar        = 20U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< mtr_bist_heartbeat */
    kINPUTMUX_AonAdvcVdd1p0TestSfaToFreqmeasTar    = 21U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< aon_advc_vdd1p0_test_sfa */
    kINPUTMUX_AonAdvcVddTestSfaToFreqmeasTar       = 22U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< aon_advc_vdd_test_sfa */
    kINPUTMUX_AonAdvcPmcDelayCellOutSfaToFreqmeasTar = 23U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< aon_advc_pmc_delay_cell_out_sfa */
    kINPUTMUX_AonAdvcPmcExpTmrOutSfaToFreqmeasTar  = 24U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< aon_advc_pmc_exp_tmr_out_sfa */
    kINPUTMUX_AonAdvcFro16kClkoutSfaToFreqmeasTar  = 25U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< aon_advc_fro16k_clkout_sfa */
    kINPUTMUX_AonAdvcAonCpuClkToFreqmeasTar        = 26U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< aon_advc_aon_cpu_clk */
    kINPUTMUX_RtcAonTstDigOutToFreqmeasTar         = 27U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< rtc_aon_tst_dig_out */
    kINPUTMUX_Fro10mCndipToFreqmeasTar             = 28U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< fro_10m clock (no divider in path) */
    kINPUTMUX_FroHfNdipToFreqmeasTar               = 29U + (FREQMEAS_TAR_REG << PMUX_SHIFT),  /*!< fro_hf (no divider in path) */

    /*!< CMP0_TRIG: CMP0 Input Connections */
    kINPUTMUX_ArmTxevToCmp0Trig                    = 1U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< arm_txev input is selected */
    kINPUTMUX_Aoi0Out0ToCmp0Trig                   = 2U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToCmp0Trig                   = 3U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToCmp0Trig                   = 4U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToCmp0Trig                   = 5U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Ctimer0Mat0ToCmp0Trig                = 8U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat0 input is selected */
    kINPUTMUX_Ctimer0Mat2ToCmp0Trig                = 9U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat0ToCmp0Trig                = 10U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat0 */
    kINPUTMUX_Ctimer1Mat2ToCmp0Trig                = 11U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat0ToCmp0Trig                = 12U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat0 input is selected */
    kINPUTMUX_Ctimer2Mat2ToCmp0Trig                = 13U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Gpio1Pet0ToCmp0Trig                  = 26U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToCmp0Trig                  = 27U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToCmp0Trig                  = 28U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToCmp0Trig                        = 30U + (CMP0_TRIG_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< LPI2C0_TRIG: LPI2C0 Trigger Input Connections */
    kINPUTMUX_ArmTxevToLpi2c0Trig                  = 1U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< arm_txev */
    kINPUTMUX_Aoi0Out0ToLpi2c0Trig                 = 2U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLpi2c0Trig                 = 3U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLpi2c0Trig                 = 4U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLpi2c0Trig                 = 5U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLpi2c0Trig                  = 6U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat0ToLpi2c0Trig              = 9U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat0 input is selected */
    kINPUTMUX_Ctimer0Mat1ToLpi2c0Trig              = 10U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat0ToLpi2c0Trig              = 11U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat0 input is selected */
    kINPUTMUX_Ctimer1Mat1ToLpi2c0Trig              = 12U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat0ToLpi2c0Trig              = 13U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat0 input is selected */
    kINPUTMUX_Ctimer2Mat1ToLpi2c0Trig              = 14U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_TrigIn0ToLpi2c0Trig                  = 17U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLpi2c0Trig                  = 18U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLpi2c0Trig                  = 19U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLpi2c0Trig                  = 20U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLpi2c0Trig                  = 21U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLpi2c0Trig                  = 22U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLpi2c0Trig                  = 23U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLpi2c0Trig                  = 24U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_Gpio1Pet0ToLpi2c0Trig                = 26U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio1Pet0ToLpi2c0Trig27              = 27U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLpi2c0Trig                = 28U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLpi2c0Trig                      = 30U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< LPI2C1_TRIG: LPI2C1 Trigger Input Connections */
    kINPUTMUX_ArmTxevToLpi2c1Trig                  = 1U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< arm_txev */
    kINPUTMUX_Aoi0Out0ToLpi2c1Trig                 = 2U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLpi2c1Trig                 = 3U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLpi2c1Trig                 = 4U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLpi2c1Trig                 = 5U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLpi2c1Trig                  = 6U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat0ToLpi2c1Trig              = 9U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat0 input is selected */
    kINPUTMUX_Ctimer0Mat1ToLpi2c1Trig              = 10U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat0ToLpi2c1Trig              = 11U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat0 input is selected */
    kINPUTMUX_Ctimer1Mat1ToLpi2c1Trig              = 12U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat0ToLpi2c1Trig              = 13U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat0 input is selected */
    kINPUTMUX_Ctimer2Mat1ToLpi2c1Trig              = 14U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_TrigIn0ToLpi2c1Trig                  = 17U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLpi2c1Trig                  = 18U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLpi2c1Trig                  = 19U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLpi2c1Trig                  = 20U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLpi2c1Trig                  = 21U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLpi2c1Trig                  = 22U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLpi2c1Trig                  = 23U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLpi2c1Trig                  = 24U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_Gpio1Pet0ToLpi2c1Trig                = 26U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLpi2c1Trig                = 27U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLpi2c1Trig                = 28U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLpi2c1Trig                      = 30U + (LPI2C1_TRIG_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< LPSPI0_TRIG: LPSPI0 Trigger Input Connections */
    kINPUTMUX_ArmTxevToLpspi0Trig                  = 1U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< arm_txev */
    kINPUTMUX_Aoi0Out0ToLpspi0Trig                 = 2U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLpspi0Trig                 = 3U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLpspi0Trig                 = 4U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLpspi0Trig                 = 5U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLpspi0Trig                  = 6U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat1ToLpspi0Trig              = 9U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer0Mat2ToLpspi0Trig              = 10U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat1ToLpspi0Trig              = 11U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat2ToLpspi0Trig              = 12U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat1ToLpspi0Trig              = 13U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat2ToLpspi0Trig              = 14U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_TrigIn0ToLpspi0Trig                  = 17U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLpspi0Trig                  = 18U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLpspi0Trig                  = 19U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLpspi0Trig                  = 20U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLpspi0Trig                  = 21U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLpspi0Trig                  = 22U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLpspi0Trig                  = 23U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLpspi0Trig                  = 24U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_Gpio1Pet0ToLpspi0Trig                = 26U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLpspi0Trig                = 27U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLpspi0Trig                = 28U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLpspi0Trig                      = 30U + (LPSPI0_TRIG_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< LPSPI1_TRIG: LPSPI1 Trigger Input Connections */
    kINPUTMUX_ArmTxevToLpspi1Trig                  = 1U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< arm_txev */
    kINPUTMUX_Aoi0Out0ToLpspi1Trig                 = 2U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLpspi1Trig                 = 3U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLpspi1Trig                 = 4U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLpspi1Trig                 = 5U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLpspi1Trig                  = 6U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat1ToLpspi1Trig              = 9U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat1 input is selected */
    kINPUTMUX_Ctimer0Mat2ToLpspi1Trig              = 10U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat1ToLpspi1Trig              = 11U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat1 input is selected */
    kINPUTMUX_Ctimer1Mat2ToLpspi1Trig              = 12U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat1ToLpspi1Trig              = 13U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat1 input is selected */
    kINPUTMUX_Ctimer2Mat2ToLpspi1Trig              = 14U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_TrigIn0ToLpspi1Trig                  = 17U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLpspi1Trig                  = 18U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLpspi1Trig                  = 19U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLpspi1Trig                  = 20U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLpspi1Trig                  = 21U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLpspi1Trig                  = 22U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLpspi1Trig                  = 23U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLpspi1Trig                  = 24U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_Gpio1Pet0ToLpspi1Trig                = 26U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLpspi1Trig                = 27U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLpspi1Trig                = 28U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuToLpspi1Trig                      = 30U + (LPSPI1_TRIG_REG << PMUX_SHIFT),  /*!< wuu input is selected */

    /*!< LPUART0: LPUART0 Trigger Input Connections */
    kINPUTMUX_ArmTxevToLPUART0                     = 1U + (LPUART0_REG << PMUX_SHIFT),  /*!< arm_txev */
    kINPUTMUX_Aoi0Out0ToLPUART0                    = 2U + (LPUART0_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLPUART0                    = 3U + (LPUART0_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLPUART0                    = 4U + (LPUART0_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLPUART0                    = 5U + (LPUART0_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLPUART0                     = 6U + (LPUART0_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToLPUART0                 = 9U + (LPUART0_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToLPUART0                 = 10U + (LPUART0_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToLPUART0                 = 11U + (LPUART0_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToLPUART0                 = 12U + (LPUART0_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToLPUART0                 = 13U + (LPUART0_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToLPUART0                 = 14U + (LPUART0_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToLPUART0                     = 17U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLPUART0                     = 18U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLPUART0                     = 19U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLPUART0                     = 20U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLPUART0                     = 21U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLPUART0                     = 22U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLPUART0                     = 23U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLPUART0                     = 24U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToLPUART0                     = 25U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToLPUART0                     = 26U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToLPUART0                    = 27U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToLPUART0                    = 28U + (LPUART0_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio1Pet0ToLPUART0                   = 30U + (LPUART0_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLPUART0                   = 31U + (LPUART0_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLPUART0                   = 32U + (LPUART0_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuSToLPUART0                        = 34U + (LPUART0_REG << PMUX_SHIFT),  /*!< wuu selected */

    /*!< LPUART1: LPUART1 Trigger Input Connections */
    kINPUTMUX_ArmTxevToLPUART1                     = 1U + (LPUART1_REG << PMUX_SHIFT),  /*!< arm_txev */
    kINPUTMUX_Aoi0Out0ToLPUART1                    = 2U + (LPUART1_REG << PMUX_SHIFT),  /*!< aoi0_out0 input is selected */
    kINPUTMUX_Aoi0Out1ToLPUART1                    = 3U + (LPUART1_REG << PMUX_SHIFT),  /*!< aoi0_out1 input is selected */
    kINPUTMUX_Aoi0Out2ToLPUART1                    = 4U + (LPUART1_REG << PMUX_SHIFT),  /*!< aoi0_out2 input is selected */
    kINPUTMUX_Aoi0Out3ToLPUART1                    = 5U + (LPUART1_REG << PMUX_SHIFT),  /*!< aoi0_out3 input is selected */
    kINPUTMUX_Cmp0OutToLPUART1                     = 6U + (LPUART1_REG << PMUX_SHIFT),  /*!< cmp0_out input is selected */
    kINPUTMUX_Ctimer0Mat2ToLPUART1                 = 9U + (LPUART1_REG << PMUX_SHIFT),  /*!< ctimer0_mat2 input is selected */
    kINPUTMUX_Ctimer0Mat3ToLPUART1                 = 10U + (LPUART1_REG << PMUX_SHIFT),  /*!< ctimer0_mat3 input is selected */
    kINPUTMUX_Ctimer1Mat2ToLPUART1                 = 11U + (LPUART1_REG << PMUX_SHIFT),  /*!< ctimer1_mat2 input is selected */
    kINPUTMUX_Ctimer1Mat3ToLPUART1                 = 12U + (LPUART1_REG << PMUX_SHIFT),  /*!< ctimer1_mat3 input is selected */
    kINPUTMUX_Ctimer2Mat2ToLPUART1                 = 13U + (LPUART1_REG << PMUX_SHIFT),  /*!< ctimer2_mat2 input is selected */
    kINPUTMUX_Ctimer2Mat3ToLPUART1                 = 14U + (LPUART1_REG << PMUX_SHIFT),  /*!< ctimer2_mat3 input is selected */
    kINPUTMUX_TrigIn0ToLPUART1                     = 17U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in0 input is selected */
    kINPUTMUX_TrigIn1ToLPUART1                     = 18U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in1 input is selected */
    kINPUTMUX_TrigIn2ToLPUART1                     = 19U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in2 input is selected */
    kINPUTMUX_TrigIn3ToLPUART1                     = 20U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in3 input is selected */
    kINPUTMUX_TrigIn4ToLPUART1                     = 21U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in4 input is selected */
    kINPUTMUX_TrigIn5ToLPUART1                     = 22U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in5 input is selected */
    kINPUTMUX_TrigIn6ToLPUART1                     = 23U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in6 input is selected */
    kINPUTMUX_TrigIn7ToLPUART1                     = 24U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in7 input is selected */
    kINPUTMUX_TrigIn8ToLPUART1                     = 25U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in8 input is selected */
    kINPUTMUX_TrigIn9ToLPUART1                     = 26U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in9 input is selected */
    kINPUTMUX_TrigIn10ToLPUART1                    = 27U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in10 input is selected */
    kINPUTMUX_TrigIn11ToLPUART1                    = 28U + (LPUART1_REG << PMUX_SHIFT),  /*!< trig_in11 input is selected */
    kINPUTMUX_Gpio1Pet0ToLPUART1                   = 30U + (LPUART1_REG << PMUX_SHIFT),  /*!< gpio1 pin event trig 0 input is selected */
    kINPUTMUX_Gpio2Pet0ToLPUART1                   = 31U + (LPUART1_REG << PMUX_SHIFT),  /*!< gpio2 pin event trig 0 input is selected */
    kINPUTMUX_Gpio3Pet0ToLPUART1                   = 32U + (LPUART1_REG << PMUX_SHIFT),  /*!< gpio3 pin event trig 0 input is selected */
    kINPUTMUX_WuuSToLPUART1                        = 34U + (LPUART1_REG << PMUX_SHIFT),  /*!< wuu selected */



#endif /* Building on the main core */
    /*!< QTMR0_TMRn: QTMR0 Input Connections */
    kINPUTMUXAON_AonTrigIn0ToQtmr0Tmrn                = 1U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in0 input is selected */
    kINPUTMUXAON_AonTrigIn1ToQtmr0Tmrn                = 2U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in1 input is selected */
    kINPUTMUXAON_AonTrigIn2ToQtmr0Tmrn                = 3U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in2 input is selected */
    kINPUTMUXAON_AonTrigIn3ToQtmr0Tmrn                = 4U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in3 input is selected */
    kINPUTMUXAON_AonTrigIn4ToQtmr0Tmrn                = 5U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in4 input is selected */
    kINPUTMUXAON_AonTrigIn5ToQtmr0Tmrn                = 6U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in5 input is selected */
    kINPUTMUXAON_AonTrigIn6ToQtmr0Tmrn                = 7U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in6 input is selected */
    kINPUTMUXAON_AonTrigIn7ToQtmr0Tmrn                = 8U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in7 input is selected */
    kINPUTMUXAON_Cm33TeToQtmr0Tmrn                    = 9U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToQtmr0Tmrn           = 10U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToQtmr0Tmrn           = 11U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToQtmr0Tmrn           = 12U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToQtmr0Tmrn           = 13U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */
    kINPUTMUXAON_Cmp0OutToQtmr0Tmrn                   = 14U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< cmp0_out is selected */
    kINPUTMUXAON_Lpi2c0CeopToQtmr0Tmrn                = 16U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lpi2c0 controller end of packet is selected */
    kINPUTMUXAON_Lpi2c0TeopToQtmr0Tmrn                = 17U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lpi2c0 target end of packet is selected */
    kINPUTMUXAON_Lpuart0RdwToQtmr0Tmrn                = 20U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lpuart0 received data word is selected */
    kINPUTMUXAON_Lpuart0TdwToQtmr0Tmrn                = 21U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word is selected */
    kINPUTMUXAON_Lpuart0RliToQtmr0Tmrn                = 22U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle is selected */
    kINPUTMUXAON_LpadcTriggerOut0ToQtmr0Tmrn          = 26U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[0] is selected */
    kINPUTMUXAON_LpadcTriggerOut1ToQtmr0Tmrn          = 27U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[1] is selected */
    kINPUTMUXAON_LpadcTriggerOut2ToQtmr0Tmrn          = 28U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[2] is selected */
    kINPUTMUXAON_LpadcTriggerOut3ToQtmr0Tmrn          = 29U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[3] is selected */
    kINPUTMUXAON_Lptmr0OToQtmr0Tmrn                   = 30U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lptmr0 output is selected */
    kINPUTMUXAON_LcRotSocLogicOut1ToQtmr0Tmrn         = 32U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out1 is selected */
    kINPUTMUXAON_LcRotSocLogicOut2ToQtmr0Tmrn         = 33U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out2 is selected */
    kINPUTMUXAON_LcRotSocLogicOut3ToQtmr0Tmrn         = 34U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out3 is selected */
    kINPUTMUXAON_LcRotSocLogicOut4ToQtmr0Tmrn         = 35U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out4 is selected */
    kINPUTMUXAON_Qtmr0Tmr0DirToQtmr0Tmrn              = 36U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr1DirToQtmr0Tmrn              = 37U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr2DirToQtmr0Tmrn              = 38U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr3DirToQtmr0Tmrn              = 39U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr0DirToQtmr0Tmrn              = 40U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr1DirToQtmr0Tmrn              = 41U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr2DirToQtmr0Tmrn              = 42U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr3DirToQtmr0Tmrn              = 43U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_dir is selected */
    kINPUTMUXAON_Acmp0RacoToQtmr0Tmrn                 = 44U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< acmp0 raw analog comparator output */
    kINPUTMUXAON_Acmp0AonCoutToQtmr0Tmrn              = 45U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< acmp0_aon_cout is selected */
    kINPUTMUXAON_Logic0ToQtmr0Tmrn                    = 46U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< logic_0 is selected */
    kINPUTMUXAON_Logic1ToQtmr0Tmrn                    = 47U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< logic_1 is selected */
    kINPUTMUXAON_WuuOToQtmr0Tmrn                      = 48U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< wuu output is selected */
    kINPUTMUXAON_GpioApet0ToQtmr0Tmrn                 = 49U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< gpio (aon) pin event trig 0 input is selected */
    kINPUTMUXAON_SocGlueXor0OutToQtmr0Tmrn            = 51U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< soc_glue_xor0_out is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToQtmr0Tmrn           = 53U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToQtmr0Tmrn           = 54U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToQtmr0Tmrn           = 55U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToQtmr0Tmrn           = 56U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_LcsenseSequencerPrimaryTriggerGlueOutToQtmr0Tmrn = 57U + (QTMR0_TMRn_REG << PMUX_SHIFT),  /*!< lcsense_sequencer_primary_trigger_glue_out is selected */

    /*!< SOC_GLUE_XOR0_INn: SOC_GLUE_XOR0 trigger input connections */
    kINPUTMUXAON_AonTrigIn0ToSocGlueXor0Inn           = 1U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< aon_trig_in0 input is selected */
    kINPUTMUXAON_AonTrigIn1ToSocGlueXor0Inn           = 2U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< aon_trig_in1 input is selected */
    kINPUTMUXAON_AonTrigIn2ToSocGlueXor0Inn           = 3U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< aon_trig_in2 input is selected */
    kINPUTMUXAON_AonTrigIn3ToSocGlueXor0Inn           = 4U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< aon_trig_in3 input is selected */
    kINPUTMUXAON_AonTrigIn4ToSocGlueXor0Inn           = 5U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< aon_trig_in4 input is selected */
    kINPUTMUXAON_AonTrigIn5ToSocGlueXor0Inn           = 6U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< aon_trig_in5 input is selected */
    kINPUTMUXAON_AonTrigIn6ToSocGlueXor0Inn           = 7U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< aon_trig_in6 input is selected */
    kINPUTMUXAON_AonTrigIn7ToSocGlueXor0Inn           = 8U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< aon_trig_in7 input is selected */
    kINPUTMUXAON_Cm33TeToSocGlueXor0Inn               = 9U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToSocGlueXor0Inn      = 10U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToSocGlueXor0Inn      = 11U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToSocGlueXor0Inn      = 12U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToSocGlueXor0Inn      = 13U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */
    kINPUTMUXAON_Cmp0OutToSocGlueXor0Inn              = 14U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< cmp0_out is selected */
    kINPUTMUXAON_Lpi2c0CeopToSocGlueXor0Inn           = 16U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lpi2c0 controller end of packet is selected */
    kINPUTMUXAON_Lpi2c0TeopToSocGlueXor0Inn           = 17U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lpi2c0 target end of packet is selected */
    kINPUTMUXAON_Lpuart0RdwToSocGlueXor0Inn           = 20U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lpuart0 received data word is selected */
    kINPUTMUXAON_Lpuart0TdwToSocGlueXor0Inn           = 21U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word is selected */
    kINPUTMUXAON_Lpuart0RliToSocGlueXor0Inn           = 22U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle is selected */
    kINPUTMUXAON_LpadcTriggerOut0ToSocGlueXor0Inn     = 26U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[0] is selected */
    kINPUTMUXAON_LpadcTriggerOut1ToSocGlueXor0Inn     = 27U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[1] is selected */
    kINPUTMUXAON_LpadcTriggerOut2ToSocGlueXor0Inn     = 28U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[2] is selected */
    kINPUTMUXAON_LpadcTriggerOut3ToSocGlueXor0Inn     = 29U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[3] is selected */
    kINPUTMUXAON_Lptmr0OToSocGlueXor0Inn              = 30U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lptmr0 output is selected */
    kINPUTMUXAON_LcRotSocLogicOut1ToSocGlueXor0Inn    = 32U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out1 is selected */
    kINPUTMUXAON_LcRotSocLogicOut2ToSocGlueXor0Inn    = 33U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out2 is selected */
    kINPUTMUXAON_LcRotSocLogicOut3ToSocGlueXor0Inn    = 34U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out3 is selected */
    kINPUTMUXAON_LcRotSocLogicOut4ToSocGlueXor0Inn    = 35U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out4 is selected */
    kINPUTMUXAON_Qtmr0Tmr0DirToSocGlueXor0Inn         = 36U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr1DirToSocGlueXor0Inn         = 37U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr2DirToSocGlueXor0Inn         = 38U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr3DirToSocGlueXor0Inn         = 39U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr0DirToSocGlueXor0Inn         = 40U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr1DirToSocGlueXor0Inn         = 41U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr2DirToSocGlueXor0Inn         = 42U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr3DirToSocGlueXor0Inn         = 43U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_dir is selected */
    kINPUTMUXAON_Acmp0RacoToSocGlueXor0Inn            = 44U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< acmp0 raw analog comparator output */
    kINPUTMUXAON_Acmp0AonCoutToSocGlueXor0Inn         = 45U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< acmp0_aon_cout is selected */
    kINPUTMUXAON_Logic0ToSocGlueXor0Inn               = 46U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< logic_0 is selected */
    kINPUTMUXAON_Logic1ToSocGlueXor0Inn               = 47U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< logic_1 is selected */
    kINPUTMUXAON_WuuOToSocGlueXor0Inn                 = 48U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< wuu output is selected */
    kINPUTMUXAON_GpioApet0ToSocGlueXor0Inn            = 49U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< gpio (aon) pin event trig 0 input is selected */
    kINPUTMUXAON_SocGlueXor0OutToSocGlueXor0Inn       = 51U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< soc_glue_xor0_out is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToSocGlueXor0Inn      = 53U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToSocGlueXor0Inn      = 54U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToSocGlueXor0Inn      = 55U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToSocGlueXor0Inn      = 56U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_LcsenseSequencerPrimaryTriggerGlueOutToSocGlueXor0Inn = 57U + (SOC_GLUE_XOR0_INn_REG << PMUX_SHIFT),  /*!< lcsense_sequencer_primary_trigger_glue_out is selected */

    /*!< QTMR1_TMRn: QTMR1 Input Connections */
    kINPUTMUXAON_AonTrigIn0ToQtmr1Tmrn                = 1U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in0 input is selected */
    kINPUTMUXAON_AonTrigIn1ToQtmr1Tmrn                = 2U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in1 input is selected */
    kINPUTMUXAON_AonTrigIn2ToQtmr1Tmrn                = 3U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in2 input is selected */
    kINPUTMUXAON_AonTrigIn3ToQtmr1Tmrn                = 4U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in3 input is selected */
    kINPUTMUXAON_AonTrigIn4ToQtmr1Tmrn                = 5U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in4 input is selected */
    kINPUTMUXAON_AonTrigIn5ToQtmr1Tmrn                = 6U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in5 input is selected */
    kINPUTMUXAON_AonTrigIn6ToQtmr1Tmrn                = 7U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in6 input is selected */
    kINPUTMUXAON_AonTrigIn7ToQtmr1Tmrn                = 8U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< aon_trig_in7 input is selected */
    kINPUTMUXAON_Cm33TeToQtmr1Tmrn                    = 9U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToQtmr1Tmrn           = 10U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToQtmr1Tmrn           = 11U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToQtmr1Tmrn           = 12U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToQtmr1Tmrn           = 13U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */
    kINPUTMUXAON_Cmp0OutToQtmr1Tmrn                   = 14U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< cmp0_out is selected */
    kINPUTMUXAON_Lpi2c0CeopToQtmr1Tmrn                = 16U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lpi2c0 controller end of packet is selected */
    kINPUTMUXAON_Lpi2c0TeopToQtmr1Tmrn                = 17U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lpi2c0 target end of packet is selected */
    kINPUTMUXAON_Lpuart0RdwToQtmr1Tmrn                = 20U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lpuart0 received data word is selected */
    kINPUTMUXAON_Lpuart0TdwToQtmr1Tmrn                = 21U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word is selected */
    kINPUTMUXAON_Lpuart0RliToQtmr1Tmrn                = 22U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle is selected */
    kINPUTMUXAON_LpadcTriggerOut0ToQtmr1Tmrn          = 26U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[0] is selected */
    kINPUTMUXAON_LpadcTriggerOut1ToQtmr1Tmrn          = 27U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[1] is selected */
    kINPUTMUXAON_LpadcTriggerOut2ToQtmr1Tmrn          = 28U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[2] is selected */
    kINPUTMUXAON_LpadcTriggerOut3ToQtmr1Tmrn          = 29U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[3] is selected */
    kINPUTMUXAON_Lptmr0OToQtmr1Tmrn                   = 30U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lptmr0 output is selected */
    kINPUTMUXAON_LcRotSocLogicOut1ToQtmr1Tmrn         = 32U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out1 is selected */
    kINPUTMUXAON_LcRotSocLogicOut2ToQtmr1Tmrn         = 33U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out2 is selected */
    kINPUTMUXAON_LcRotSocLogicOut3ToQtmr1Tmrn         = 34U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out3 is selected */
    kINPUTMUXAON_LcRotSocLogicOut4ToQtmr1Tmrn         = 35U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out4 is selected */
    kINPUTMUXAON_Qtmr0Tmr0DirToQtmr1Tmrn              = 36U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr1DirToQtmr1Tmrn              = 37U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr2DirToQtmr1Tmrn              = 38U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr3DirToQtmr1Tmrn              = 39U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr0DirToQtmr1Tmrn              = 40U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr1DirToQtmr1Tmrn              = 41U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr2DirToQtmr1Tmrn              = 42U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr3DirToQtmr1Tmrn              = 43U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_dir is selected */
    kINPUTMUXAON_Acmp0RacoToQtmr1Tmrn                 = 44U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< acmp0 raw analog comparator output */
    kINPUTMUXAON_Acmp0AonCoutToQtmr1Tmrn              = 45U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< acmp0_aon_cout is selected */
    kINPUTMUXAON_Logic0ToQtmr1Tmrn                    = 46U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< logic_0 is selected */
    kINPUTMUXAON_Logic1ToQtmr1Tmrn                    = 47U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< logic_1 is selected */
    kINPUTMUXAON_WuuOToQtmr1Tmrn                      = 48U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< wuu output is selected */
    kINPUTMUXAON_GpioApet0ToQtmr1Tmrn                 = 49U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< gpio (aon) pin event trig 0 input is selected */
    kINPUTMUXAON_SocGlueXor0OutToQtmr1Tmrn            = 51U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< soc_glue_xor0_out is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToQtmr1Tmrn           = 53U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToQtmr1Tmrn           = 54U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToQtmr1Tmrn           = 55U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToQtmr1Tmrn           = 56U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_LcsenseSequencerPrimaryTriggerGlueOutToQtmr1Tmrn = 57U + (QTMR1_TMRn_REG << PMUX_SHIFT),  /*!< lcsense_sequencer_primary_trigger_glue_out is selected */

    /*!< ACMP0_TRIGn: ACMP0 Input Connections */
    kINPUTMUXAON_AonTrigIn0ToAcmp0Trign               = 1U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in0 input is selected */
    kINPUTMUXAON_AonTrigIn1ToAcmp0Trign               = 2U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in1 input is selected */
    kINPUTMUXAON_AonTrigIn2ToAcmp0Trign               = 3U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in2 input is selected */
    kINPUTMUXAON_AonTrigIn3ToAcmp0Trign               = 4U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in3 input is selected */
    kINPUTMUXAON_AonTrigIn4ToAcmp0Trign               = 5U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in4 input is selected */
    kINPUTMUXAON_AonTrigIn5ToAcmp0Trign               = 6U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in5 input is selected */
    kINPUTMUXAON_AonTrigIn6ToAcmp0Trign               = 7U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in6 input is selected */
    kINPUTMUXAON_AonTrigIn7ToAcmp0Trign               = 8U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in7 input is selected */
    kINPUTMUXAON_Cm33TeToAcmp0Trign                   = 9U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToAcmp0Trign          = 12U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToAcmp0Trign          = 13U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToAcmp0Trign          = 14U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToAcmp0Trign          = 15U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_Lptmr0OToAcmp0Trign                  = 16U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< lptmr0 output is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToAcmp0Trign          = 18U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToAcmp0Trign          = 19U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToAcmp0Trign          = 20U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToAcmp0Trign          = 21U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */
    kINPUTMUXAON_WuuToAcmp0Trign                      = 23U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< wuu is selected */
    kINPUTMUXAON_GpioApet0ToAcmp0Trign                = 24U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< gpio (aon) pin event trig 0 is selected */
    kINPUTMUXAON_LpadcTriggerOut0ToAcmp0Trign         = 26U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[0] is selected */
    kINPUTMUXAON_LpadcTriggerOut1ToAcmp0Trign         = 27U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[1] is selected */
    kINPUTMUXAON_LpadcTriggerOut2ToAcmp0Trign         = 28U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[2] is selected */
    kINPUTMUXAON_LpadcTriggerOut3ToAcmp0Trign         = 29U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[3] is selected */
    kINPUTMUXAON_Acmp0RacoToAcmp0Trign                = 30U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< acmp0 raw analog comparator output */
    kINPUTMUXAON_Acmp0AonCoutToAcmp0Trign             = 31U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< acmp0_aon_cout is selected */
    kINPUTMUXAON_SocGlueXor0OutToAcmp0Trign           = 34U + (ACMP0_TRIGn_REG << PMUX_SHIFT),  /*!< soc_glue_xor0_out is selected */

    /*!< LPADC0_TRIGn: LPADC trigger input connections */
    kINPUTMUXAON_AonTrigIn0ToLpadc0Trign              = 1U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in0 is selected */
    kINPUTMUXAON_AonTrigIn1ToLpadc0Trign              = 2U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in1 is selected */
    kINPUTMUXAON_AonTrigIn2ToLpadc0Trign              = 3U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in2 is selected */
    kINPUTMUXAON_AonTrigIn03ToLpadc0Trign             = 4U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in03 is selected */
    kINPUTMUXAON_AonTrigIn04ToLpadc0Trign             = 5U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in04 is selected */
    kINPUTMUXAON_AonTrigIn5ToLpadc0Trign              = 6U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in5 is selected */
    kINPUTMUXAON_AonTrigIn6ToLpadc0Trign              = 7U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in6 is selected */
    kINPUTMUXAON_AonTrigIn7ToLpadc0Trign              = 8U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< aon_trig_in7 is selected */
    kINPUTMUXAON_Cm33TeToLpadc0Trign                  = 9U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_LpcmpOutToLpadc0Trign                = 10U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< lpcmp_out is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToLpadc0Trign         = 12U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToLpadc0Trign         = 13U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToLpadc0Trign         = 14U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToLpadc0Trign         = 15U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_Lptmr0OToLpadc0Trign                 = 16U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< lptmr0 output is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToLpadc0Trign         = 18U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToLpadc0Trign         = 19U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToLpadc0Trign         = 20U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToLpadc0Trign         = 21U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */
    kINPUTMUXAON_WuuToLpadc0Trign                     = 23U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< wuu is selected */
    kINPUTMUXAON_GpioApet0ToLpadc0Trign               = 24U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< gpio (aon) pin event trig 0 is selected */
    kINPUTMUXAON_Acmp0RacoToLpadc0Trign               = 25U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< acmp0 raw analog comparator output */
    kINPUTMUXAON_Acmp0AonCoutToLpadc0Trign            = 26U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< acmp0_aon_cout is selected */
    kINPUTMUXAON_SocGlueXor0OutToLpadc0Trign          = 29U + (LPADC0_TRIGn_REG << PMUX_SHIFT),  /*!< soc_glue_xor0_out is selected */

    /*!< AON_TRIG_OUTn: AON Trigger Output Connections */
    kINPUTMUXAON_Cm33TeToAonTrigOutn                  = 1U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_AonLpuart0IToAonTrigOutn             = 2U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< aon_lpuart0 (ipp_do_lpuart_txd) is selected */
    kINPUTMUXAON_LpadcTriggerOut0ToAonTrigOutn        = 8U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[0] is selected */
    kINPUTMUXAON_LpadcTriggerOut1ToAonTrigOutn        = 9U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[1] is selected */
    kINPUTMUXAON_LpadcTriggerOut2ToAonTrigOutn        = 10U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[2] is selected */
    kINPUTMUXAON_ParkedOutIntvertedToAonTrigOutn      = 11U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< parked_out_intverted is selected */
    kINPUTMUXAON_AonLptmr0OToAonTrigOutn              = 12U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< aon_lptmr0 output is selected */
    kINPUTMUXAON_Lpcomp0OutToAonTrigOutn              = 14U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< lpcomp0_out is selected */
    kINPUTMUXAON_Acmp0RacoToAonTrigOutn               = 16U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< acmp0 raw analog comparator output */
    kINPUTMUXAON_Acmp0AonCoutToAonTrigOutn            = 17U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< acmp0_aon_cout is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToAonTrigOutn         = 20U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToAonTrigOutn         = 21U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToAonTrigOutn         = 22U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToAonTrigOutn         = 23U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToAonTrigOutn         = 24U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToAonTrigOutn         = 25U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToAonTrigOutn         = 26U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToAonTrigOutn         = 27U + (AON_TRIG_OUTn_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */

    /*!< SOC_GLUE_CMPPADS_PCTRL_XOR_IN0: SOC_GLUE_CMPPADS_PCTRL_XOR_IN0 trigger input connections */
    kINPUTMUXAON_AonTrigIn0ToSocGlueCmppadsPctrlXorIn0 = 1U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in0 input is selected */
    kINPUTMUXAON_AonTrigIn1ToSocGlueCmppadsPctrlXorIn0 = 2U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in1 input is selected */
    kINPUTMUXAON_AonTrigIn2ToSocGlueCmppadsPctrlXorIn0 = 3U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in2 input is selected */
    kINPUTMUXAON_AonTrigIn3ToSocGlueCmppadsPctrlXorIn0 = 4U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in3 input is selected */
    kINPUTMUXAON_AonTrigIn4ToSocGlueCmppadsPctrlXorIn0 = 5U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in4 input is selected */
    kINPUTMUXAON_AonTrigIn5ToSocGlueCmppadsPctrlXorIn0 = 6U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in5 input is selected */
    kINPUTMUXAON_AonTrigIn6ToSocGlueCmppadsPctrlXorIn0 = 7U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in6 input is selected */
    kINPUTMUXAON_AonTrigIn7ToSocGlueCmppadsPctrlXorIn0 = 8U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in7 input is selected */
    kINPUTMUXAON_Cm33TeToSocGlueCmppadsPctrlXorIn0    = 9U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToSocGlueCmppadsPctrlXorIn0 = 10U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToSocGlueCmppadsPctrlXorIn0 = 11U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToSocGlueCmppadsPctrlXorIn0 = 12U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToSocGlueCmppadsPctrlXorIn0 = 13U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */
    kINPUTMUXAON_Cmp0OutToSocGlueCmppadsPctrlXorIn0   = 14U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< cmp0_out is selected */
    kINPUTMUXAON_Lpi2c0CeopToSocGlueCmppadsPctrlXorIn0 = 16U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpi2c0 controller end of packet is selected */
    kINPUTMUXAON_Lpi2c0TeopToSocGlueCmppadsPctrlXorIn0 = 17U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpi2c0 target end of packet is selected */
    kINPUTMUXAON_Lpuart0RdwToSocGlueCmppadsPctrlXorIn0 = 20U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpuart0 received data word is selected */
    kINPUTMUXAON_Lpuart0TdwToSocGlueCmppadsPctrlXorIn0 = 21U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word is selected */
    kINPUTMUXAON_Lpuart0RliToSocGlueCmppadsPctrlXorIn0 = 22U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle is selected */
    kINPUTMUXAON_LpadcTriggerOut0ToSocGlueCmppadsPctrlXorIn0 = 26U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[0] is selected */
    kINPUTMUXAON_LpadcTriggerOut1ToSocGlueCmppadsPctrlXorIn0 = 27U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[1] is selected */
    kINPUTMUXAON_LpadcTriggerOut2ToSocGlueCmppadsPctrlXorIn0 = 28U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[2] is selected */
    kINPUTMUXAON_LpadcTriggerOut3ToSocGlueCmppadsPctrlXorIn0 = 29U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[3] is selected */
    kINPUTMUXAON_Lptmr0OToSocGlueCmppadsPctrlXorIn0   = 30U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lptmr0 output is selected */
    kINPUTMUXAON_LcRotSocLogicOut1ToSocGlueCmppadsPctrlXorIn0 = 32U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out1 is selected */
    kINPUTMUXAON_LcRotSocLogicOut2ToSocGlueCmppadsPctrlXorIn0 = 33U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out2 is selected */
    kINPUTMUXAON_LcRotSocLogicOut3ToSocGlueCmppadsPctrlXorIn0 = 34U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out3 is selected */
    kINPUTMUXAON_LcRotSocLogicOut4ToSocGlueCmppadsPctrlXorIn0 = 35U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out4 is selected */
    kINPUTMUXAON_Qtmr0Tmr0DirToSocGlueCmppadsPctrlXorIn0 = 36U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr1DirToSocGlueCmppadsPctrlXorIn0 = 37U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr2DirToSocGlueCmppadsPctrlXorIn0 = 38U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr3DirToSocGlueCmppadsPctrlXorIn0 = 39U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr0DirToSocGlueCmppadsPctrlXorIn0 = 40U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr1DirToSocGlueCmppadsPctrlXorIn0 = 41U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr2DirToSocGlueCmppadsPctrlXorIn0 = 42U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr3DirToSocGlueCmppadsPctrlXorIn0 = 43U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_dir is selected */
    kINPUTMUXAON_Acmp0RacoToSocGlueCmppadsPctrlXorIn0 = 44U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< acmp0 raw analog comparator output */
    kINPUTMUXAON_Acmp0AonCoutToSocGlueCmppadsPctrlXorIn0 = 45U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< acmp0_aon_cout is selected */
    kINPUTMUXAON_Logic0ToSocGlueCmppadsPctrlXorIn0    = 46U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< logic_0 is selected */
    kINPUTMUXAON_Logic1ToSocGlueCmppadsPctrlXorIn0    = 47U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< logic_1 is selected */
    kINPUTMUXAON_WuuOToSocGlueCmppadsPctrlXorIn0      = 48U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< wuu output is selected */
    kINPUTMUXAON_GpioApet0ToSocGlueCmppadsPctrlXorIn0 = 49U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< gpio (aon) pin event trig 0 input is selected */
    kINPUTMUXAON_SocGlueXor0OutToSocGlueCmppadsPctrlXorIn0 = 51U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< soc_glue_xor0_out is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToSocGlueCmppadsPctrlXorIn0 = 53U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToSocGlueCmppadsPctrlXorIn0 = 54U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToSocGlueCmppadsPctrlXorIn0 = 55U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToSocGlueCmppadsPctrlXorIn0 = 56U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_LcsenseSequencerPrimaryTriggerGlueOutToSocGlueCmppadsPctrlXorIn0 = 57U + (SOC_GLUE_CMPPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lcsense_sequencer_primary_trigger_glue_out is selected */

    /*!< SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0: SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0 trigger input connections */
    kINPUTMUXAON_AonTrigIn0ToSocGlueCtrlpadsPctrlXorIn0 = 1U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in0 input is selected */
    kINPUTMUXAON_AonTrigIn1ToSocGlueCtrlpadsPctrlXorIn0 = 2U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in1 input is selected */
    kINPUTMUXAON_AonTrigIn2ToSocGlueCtrlpadsPctrlXorIn0 = 3U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in2 input is selected */
    kINPUTMUXAON_AonTrigIn3ToSocGlueCtrlpadsPctrlXorIn0 = 4U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in3 input is selected */
    kINPUTMUXAON_AonTrigIn4ToSocGlueCtrlpadsPctrlXorIn0 = 5U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in4 input is selected */
    kINPUTMUXAON_AonTrigIn5ToSocGlueCtrlpadsPctrlXorIn0 = 6U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in5 input is selected */
    kINPUTMUXAON_AonTrigIn6ToSocGlueCtrlpadsPctrlXorIn0 = 7U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in6 input is selected */
    kINPUTMUXAON_AonTrigIn7ToSocGlueCtrlpadsPctrlXorIn0 = 8U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< aon_trig_in7 input is selected */
    kINPUTMUXAON_Cm33TeToSocGlueCtrlpadsPctrlXorIn0   = 9U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToSocGlueCtrlpadsPctrlXorIn0 = 10U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToSocGlueCtrlpadsPctrlXorIn0 = 11U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToSocGlueCtrlpadsPctrlXorIn0 = 12U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToSocGlueCtrlpadsPctrlXorIn0 = 13U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */
    kINPUTMUXAON_Cmp0OutToSocGlueCtrlpadsPctrlXorIn0  = 14U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< cmp0_out is selected */
    kINPUTMUXAON_Lpi2c0CeopToSocGlueCtrlpadsPctrlXorIn0 = 16U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpi2c0 controller end of packet is selected */
    kINPUTMUXAON_Lpi2c0TeopToSocGlueCtrlpadsPctrlXorIn0 = 17U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpi2c0 target end of packet is selected */
    kINPUTMUXAON_Lpuart0RdwToSocGlueCtrlpadsPctrlXorIn0 = 20U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpuart0 received data word is selected */
    kINPUTMUXAON_Lpuart0TdwToSocGlueCtrlpadsPctrlXorIn0 = 21U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word is selected */
    kINPUTMUXAON_Lpuart0RliToSocGlueCtrlpadsPctrlXorIn0 = 22U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle is selected */
    kINPUTMUXAON_LpadcTriggerOut0ToSocGlueCtrlpadsPctrlXorIn0 = 26U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[0] is selected */
    kINPUTMUXAON_LpadcTriggerOut1ToSocGlueCtrlpadsPctrlXorIn0 = 27U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[1] is selected */
    kINPUTMUXAON_LpadcTriggerOut2ToSocGlueCtrlpadsPctrlXorIn0 = 28U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[2] is selected */
    kINPUTMUXAON_LpadcTriggerOut3ToSocGlueCtrlpadsPctrlXorIn0 = 29U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[3] is selected */
    kINPUTMUXAON_Lptmr0OToSocGlueCtrlpadsPctrlXorIn0  = 30U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lptmr0 output is selected */
    kINPUTMUXAON_LcRotSocLogicOut1ToSocGlueCtrlpadsPctrlXorIn0 = 32U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out1 is selected */
    kINPUTMUXAON_LcRotSocLogicOut2ToSocGlueCtrlpadsPctrlXorIn0 = 33U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out2 is selected */
    kINPUTMUXAON_LcRotSocLogicOut3ToSocGlueCtrlpadsPctrlXorIn0 = 34U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out3 is selected */
    kINPUTMUXAON_LcRotSocLogicOut4ToSocGlueCtrlpadsPctrlXorIn0 = 35U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out4 is selected */
    kINPUTMUXAON_Qtmr0Tmr0DirToSocGlueCtrlpadsPctrlXorIn0 = 36U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr1DirToSocGlueCtrlpadsPctrlXorIn0 = 37U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr2DirToSocGlueCtrlpadsPctrlXorIn0 = 38U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr3DirToSocGlueCtrlpadsPctrlXorIn0 = 39U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr0DirToSocGlueCtrlpadsPctrlXorIn0 = 40U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr1DirToSocGlueCtrlpadsPctrlXorIn0 = 41U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr2DirToSocGlueCtrlpadsPctrlXorIn0 = 42U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr3DirToSocGlueCtrlpadsPctrlXorIn0 = 43U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_dir is selected */
    kINPUTMUXAON_Acmp0RacoToSocGlueCtrlpadsPctrlXorIn0 = 44U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< acmp0 raw analog comparator output */
    kINPUTMUXAON_Acmp0AonCoutToSocGlueCtrlpadsPctrlXorIn0 = 45U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< acmp0_aon_cout is selected */
    kINPUTMUXAON_Logic0ToSocGlueCtrlpadsPctrlXorIn0   = 46U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< logic_0 is selected */
    kINPUTMUXAON_Logic1ToSocGlueCtrlpadsPctrlXorIn0   = 47U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< logic_1 is selected */
    kINPUTMUXAON_WuuOToSocGlueCtrlpadsPctrlXorIn0     = 48U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< wuu output is selected */
    kINPUTMUXAON_GpioApet0ToSocGlueCtrlpadsPctrlXorIn0 = 49U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< gpio (aon) pin event trig 0 input is selected */
    kINPUTMUXAON_SocGlueXor0OutToSocGlueCtrlpadsPctrlXorIn0 = 51U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< soc_glue_xor0_out is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToSocGlueCtrlpadsPctrlXorIn0 = 53U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToSocGlueCtrlpadsPctrlXorIn0 = 54U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToSocGlueCtrlpadsPctrlXorIn0 = 55U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToSocGlueCtrlpadsPctrlXorIn0 = 56U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_LcsenseSequencerPrimaryTriggerGlueOutToSocGlueCtrlpadsPctrlXorIn0 = 57U + (SOC_GLUE_CTRLPADS_PCTRL_XOR_IN0_REG << PMUX_SHIFT),  /*!< lcsense_sequencer_primary_trigger_glue_out is selected */

    /*!< LC_ROT_SOC_LOGIC_IN: LC_ROT_SOC_LOGIC_IN trigger input connections */
    kINPUTMUXAON_AonTrigIn0ToLcRotSocLogicIn          = 1U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in0 input is selected */
    kINPUTMUXAON_AonTrigIn1ToLcRotSocLogicIn          = 2U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in1 input is selected */
    kINPUTMUXAON_AonTrigIn2ToLcRotSocLogicIn          = 3U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in2 input is selected */
    kINPUTMUXAON_AonTrigIn3ToLcRotSocLogicIn          = 4U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in3 input is selected */
    kINPUTMUXAON_AonTrigIn4ToLcRotSocLogicIn          = 5U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in4 input is selected */
    kINPUTMUXAON_AonTrigIn5ToLcRotSocLogicIn          = 6U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in5 input is selected */
    kINPUTMUXAON_AonTrigIn6ToLcRotSocLogicIn          = 7U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in6 input is selected */
    kINPUTMUXAON_AonTrigIn7ToLcRotSocLogicIn          = 8U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in7 input is selected */
    kINPUTMUXAON_Cm33TeToLcRotSocLogicIn              = 9U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToLcRotSocLogicIn     = 10U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToLcRotSocLogicIn     = 11U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToLcRotSocLogicIn     = 12U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToLcRotSocLogicIn     = 13U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */
    kINPUTMUXAON_Cmp0OutToLcRotSocLogicIn             = 14U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< cmp0_out is selected */
    kINPUTMUXAON_Lpi2c0CeopToLcRotSocLogicIn          = 16U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lpi2c0 controller end of packet is selected */
    kINPUTMUXAON_Lpi2c0TeopToLcRotSocLogicIn          = 17U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lpi2c0 target end of packet is selected */
    kINPUTMUXAON_Lpuart0RdwToLcRotSocLogicIn          = 20U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lpuart0 received data word is selected */
    kINPUTMUXAON_Lpuart0TdwToLcRotSocLogicIn          = 21U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word is selected */
    kINPUTMUXAON_Lpuart0RliToLcRotSocLogicIn          = 22U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle is selected */
    kINPUTMUXAON_LpadcTriggerOut0ToLcRotSocLogicIn    = 26U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[0] is selected */
    kINPUTMUXAON_LpadcTriggerOut1ToLcRotSocLogicIn    = 27U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[1] is selected */
    kINPUTMUXAON_LpadcTriggerOut2ToLcRotSocLogicIn    = 28U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[2] is selected */
    kINPUTMUXAON_LpadcTriggerOut3ToLcRotSocLogicIn    = 29U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[3] is selected */
    kINPUTMUXAON_Lptmr0OToLcRotSocLogicIn             = 30U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lptmr0 output is selected */
    kINPUTMUXAON_LcRotSocLogicOut1ToLcRotSocLogicIn   = 32U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out1 is selected */
    kINPUTMUXAON_LcRotSocLogicOut2ToLcRotSocLogicIn   = 33U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out2 is selected */
    kINPUTMUXAON_LcRotSocLogicOut3ToLcRotSocLogicIn   = 34U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out3 is selected */
    kINPUTMUXAON_LcRotSocLogicOut4ToLcRotSocLogicIn   = 35U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out4 is selected */
    kINPUTMUXAON_Qtmr0Tmr0DirToLcRotSocLogicIn        = 36U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr1DirToLcRotSocLogicIn        = 37U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr2DirToLcRotSocLogicIn        = 38U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr3DirToLcRotSocLogicIn        = 39U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr0DirToLcRotSocLogicIn        = 40U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr1DirToLcRotSocLogicIn        = 41U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr2DirToLcRotSocLogicIn        = 42U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr3DirToLcRotSocLogicIn        = 43U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_dir is selected */
    kINPUTMUXAON_Acmp0RacoToLcRotSocLogicIn           = 44U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< acmp0 raw analog comparator output */
    kINPUTMUXAON_Acmp0AonCoutToLcRotSocLogicIn        = 45U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< acmp0_aon_cout is selected */
    kINPUTMUXAON_Logic0ToLcRotSocLogicIn              = 46U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< logic_0 is selected */
    kINPUTMUXAON_Logic1ToLcRotSocLogicIn              = 47U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< logic_1 is selected */
    kINPUTMUXAON_WuuOToLcRotSocLogicIn                = 48U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< wuu output is selected */
    kINPUTMUXAON_GpioApet0ToLcRotSocLogicIn           = 49U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< gpio (aon) pin event trig 0 input is selected */
    kINPUTMUXAON_SocGlueXor0OutToLcRotSocLogicIn      = 51U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< soc_glue_xor0_out is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToLcRotSocLogicIn     = 53U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToLcRotSocLogicIn     = 54U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToLcRotSocLogicIn     = 55U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToLcRotSocLogicIn     = 56U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_LcsenseSequencerPrimaryTriggerGlueOutToLcRotSocLogicIn = 57U + (LC_ROT_SOC_LOGIC_IN_REG << PMUX_SHIFT),  /*!< lcsense_sequencer_primary_trigger_glue_out is selected */

    /*!< LCSENSE_SEQ_PTRIG_GLUE_IN: LCSENSE_SEQ_PTRIG_GLUE_IN trigger input connections */
    kINPUTMUXAON_AonTrigIn0ToLcsenseSeqPtrigGlueIn    = 1U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in0 input is selected */
    kINPUTMUXAON_AonTrigIn1ToLcsenseSeqPtrigGlueIn    = 2U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in1 input is selected */
    kINPUTMUXAON_AonTrigIn2ToLcsenseSeqPtrigGlueIn    = 3U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in2 input is selected */
    kINPUTMUXAON_AonTrigIn3ToLcsenseSeqPtrigGlueIn    = 4U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in3 input is selected */
    kINPUTMUXAON_AonTrigIn4ToLcsenseSeqPtrigGlueIn    = 5U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in4 input is selected */
    kINPUTMUXAON_AonTrigIn5ToLcsenseSeqPtrigGlueIn    = 6U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in5 input is selected */
    kINPUTMUXAON_AonTrigIn6ToLcsenseSeqPtrigGlueIn    = 7U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in6 input is selected */
    kINPUTMUXAON_AonTrigIn7ToLcsenseSeqPtrigGlueIn    = 8U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in7 input is selected */
    kINPUTMUXAON_Cm33TeToLcsenseSeqPtrigGlueIn        = 9U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToLcsenseSeqPtrigGlueIn = 10U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToLcsenseSeqPtrigGlueIn = 11U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToLcsenseSeqPtrigGlueIn = 12U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToLcsenseSeqPtrigGlueIn = 13U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */
    kINPUTMUXAON_Cmp0OutToLcsenseSeqPtrigGlueIn       = 14U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< cmp0_out is selected */
    kINPUTMUXAON_Lpi2c0CeopToLcsenseSeqPtrigGlueIn    = 16U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpi2c0 controller end of packet is selected */
    kINPUTMUXAON_Lpi2c0TeopToLcsenseSeqPtrigGlueIn    = 17U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpi2c0 target end of packet is selected */
    kINPUTMUXAON_Lpuart0RdwToLcsenseSeqPtrigGlueIn    = 20U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpuart0 received data word is selected */
    kINPUTMUXAON_Lpuart0TdwToLcsenseSeqPtrigGlueIn    = 21U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word is selected */
    kINPUTMUXAON_Lpuart0RliToLcsenseSeqPtrigGlueIn    = 22U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle is selected */
    kINPUTMUXAON_LpadcTriggerOut0ToLcsenseSeqPtrigGlueIn = 26U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[0] is selected */
    kINPUTMUXAON_LpadcTriggerOut1ToLcsenseSeqPtrigGlueIn = 27U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[1] is selected */
    kINPUTMUXAON_LpadcTriggerOut2ToLcsenseSeqPtrigGlueIn = 28U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[2] is selected */
    kINPUTMUXAON_LpadcTriggerOut3ToLcsenseSeqPtrigGlueIn = 29U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[3] is selected */
    kINPUTMUXAON_Lptmr0OToLcsenseSeqPtrigGlueIn       = 30U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lptmr0 output is selected */
    kINPUTMUXAON_LcRotSocLogicOut1ToLcsenseSeqPtrigGlueIn = 32U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out1 is selected */
    kINPUTMUXAON_LcRotSocLogicOut2ToLcsenseSeqPtrigGlueIn = 33U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out2 is selected */
    kINPUTMUXAON_LcRotSocLogicOut3ToLcsenseSeqPtrigGlueIn = 34U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out3 is selected */
    kINPUTMUXAON_LcRotSocLogicOut4ToLcsenseSeqPtrigGlueIn = 35U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out4 is selected */
    kINPUTMUXAON_Qtmr0Tmr0DirToLcsenseSeqPtrigGlueIn  = 36U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr1DirToLcsenseSeqPtrigGlueIn  = 37U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr2DirToLcsenseSeqPtrigGlueIn  = 38U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr3DirToLcsenseSeqPtrigGlueIn  = 39U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr0DirToLcsenseSeqPtrigGlueIn  = 40U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr1DirToLcsenseSeqPtrigGlueIn  = 41U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr2DirToLcsenseSeqPtrigGlueIn  = 42U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr3DirToLcsenseSeqPtrigGlueIn  = 43U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_dir is selected */
    kINPUTMUXAON_Acmp0RacoToLcsenseSeqPtrigGlueIn     = 44U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< acmp0 raw analog comparator output */
    kINPUTMUXAON_Acmp0AonCoutToLcsenseSeqPtrigGlueIn  = 45U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< acmp0_aon_cout is selected */
    kINPUTMUXAON_Logic0ToLcsenseSeqPtrigGlueIn        = 46U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< logic_0 is selected */
    kINPUTMUXAON_Logic1ToLcsenseSeqPtrigGlueIn        = 47U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< logic_1 is selected */
    kINPUTMUXAON_WuuOToLcsenseSeqPtrigGlueIn          = 48U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< wuu output is selected */
    kINPUTMUXAON_GpioApet0ToLcsenseSeqPtrigGlueIn     = 49U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< gpio (aon) pin event trig 0 input is selected */
    kINPUTMUXAON_SocGlueXor0OutToLcsenseSeqPtrigGlueIn = 51U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< soc_glue_xor0_out is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToLcsenseSeqPtrigGlueIn = 53U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToLcsenseSeqPtrigGlueIn = 54U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToLcsenseSeqPtrigGlueIn = 55U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToLcsenseSeqPtrigGlueIn = 56U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_LcsenseSequencerPrimaryTriggerGlueOutToLcsenseSeqPtrigGlueIn = 57U + (LCSENSE_SEQ_PTRIG_GLUE_IN_REG << PMUX_SHIFT),  /*!< lcsense_sequencer_primary_trigger_glue_out is selected */

    /*!< LCSENSE_SEQ_TICKS_GLUE_IN: LCSENSE_SEQ_TICKS_GLUE_IN trigger input connections */
    kINPUTMUXAON_AonTrigIn0ToLcsenseSeqTicksGlueIn    = 1U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in0 input is selected */
    kINPUTMUXAON_AonTrigIn1ToLcsenseSeqTicksGlueIn    = 2U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in1 input is selected */
    kINPUTMUXAON_AonTrigIn2ToLcsenseSeqTicksGlueIn    = 3U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in2 input is selected */
    kINPUTMUXAON_AonTrigIn3ToLcsenseSeqTicksGlueIn    = 4U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in3 input is selected */
    kINPUTMUXAON_AonTrigIn4ToLcsenseSeqTicksGlueIn    = 5U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in4 input is selected */
    kINPUTMUXAON_AonTrigIn5ToLcsenseSeqTicksGlueIn    = 6U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in5 input is selected */
    kINPUTMUXAON_AonTrigIn6ToLcsenseSeqTicksGlueIn    = 7U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in6 input is selected */
    kINPUTMUXAON_AonTrigIn7ToLcsenseSeqTicksGlueIn    = 8U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< aon_trig_in7 input is selected */
    kINPUTMUXAON_Cm33TeToLcsenseSeqTicksGlueIn        = 9U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToLcsenseSeqTicksGlueIn = 10U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToLcsenseSeqTicksGlueIn = 11U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToLcsenseSeqTicksGlueIn = 12U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToLcsenseSeqTicksGlueIn = 13U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */
    kINPUTMUXAON_Cmp0OutToLcsenseSeqTicksGlueIn       = 14U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< cmp0_out is selected */
    kINPUTMUXAON_Lpi2c0CeopToLcsenseSeqTicksGlueIn    = 16U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpi2c0 controller end of packet is selected */
    kINPUTMUXAON_Lpi2c0TeopToLcsenseSeqTicksGlueIn    = 17U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpi2c0 target end of packet is selected */
    kINPUTMUXAON_Lpuart0RdwToLcsenseSeqTicksGlueIn    = 20U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpuart0 received data word is selected */
    kINPUTMUXAON_Lpuart0TdwToLcsenseSeqTicksGlueIn    = 21U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpuart0 transmitted data word is selected */
    kINPUTMUXAON_Lpuart0RliToLcsenseSeqTicksGlueIn    = 22U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpuart0 receive line idle is selected */
    kINPUTMUXAON_LpadcTriggerOut0ToLcsenseSeqTicksGlueIn = 26U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[0] is selected */
    kINPUTMUXAON_LpadcTriggerOut1ToLcsenseSeqTicksGlueIn = 27U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[1] is selected */
    kINPUTMUXAON_LpadcTriggerOut2ToLcsenseSeqTicksGlueIn = 28U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[2] is selected */
    kINPUTMUXAON_LpadcTriggerOut3ToLcsenseSeqTicksGlueIn = 29U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[3] is selected */
    kINPUTMUXAON_Lptmr0OToLcsenseSeqTicksGlueIn       = 30U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lptmr0 output is selected */
    kINPUTMUXAON_LcRotSocLogicOut1ToLcsenseSeqTicksGlueIn = 32U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out1 is selected */
    kINPUTMUXAON_LcRotSocLogicOut2ToLcsenseSeqTicksGlueIn = 33U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out2 is selected */
    kINPUTMUXAON_LcRotSocLogicOut3ToLcsenseSeqTicksGlueIn = 34U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out3 is selected */
    kINPUTMUXAON_LcRotSocLogicOut4ToLcsenseSeqTicksGlueIn = 35U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lc_rot_soc_logic_out4 is selected */
    kINPUTMUXAON_Qtmr0Tmr0DirToLcsenseSeqTicksGlueIn  = 36U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr1DirToLcsenseSeqTicksGlueIn  = 37U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr2DirToLcsenseSeqTicksGlueIn  = 38U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr0Tmr3DirToLcsenseSeqTicksGlueIn  = 39U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr0DirToLcsenseSeqTicksGlueIn  = 40U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr1DirToLcsenseSeqTicksGlueIn  = 41U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr2DirToLcsenseSeqTicksGlueIn  = 42U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_dir is selected */
    kINPUTMUXAON_Qtmr1Tmr3DirToLcsenseSeqTicksGlueIn  = 43U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_dir is selected */
    kINPUTMUXAON_Acmp0RacoToLcsenseSeqTicksGlueIn     = 44U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< acmp0 raw analog comparator output */
    kINPUTMUXAON_Acmp0AonCoutToLcsenseSeqTicksGlueIn  = 45U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< acmp0_aon_cout is selected */
    kINPUTMUXAON_Logic0ToLcsenseSeqTicksGlueIn        = 46U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< logic_0 is selected */
    kINPUTMUXAON_Logic1ToLcsenseSeqTicksGlueIn        = 47U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< logic_1 is selected */
    kINPUTMUXAON_WuuOToLcsenseSeqTicksGlueIn          = 48U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< wuu output is selected */
    kINPUTMUXAON_GpioApet0ToLcsenseSeqTicksGlueIn     = 49U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< gpio (aon) pin event trig 0 input is selected */
    kINPUTMUXAON_SocGlueXor0OutToLcsenseSeqTicksGlueIn = 51U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< soc_glue_xor0_out is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToLcsenseSeqTicksGlueIn = 53U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToLcsenseSeqTicksGlueIn = 54U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToLcsenseSeqTicksGlueIn = 55U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToLcsenseSeqTicksGlueIn = 56U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_LcsenseSequencerPrimaryTriggerGlueOutToLcsenseSeqTicksGlueIn = 57U + (LCSENSE_SEQ_TICKS_GLUE_IN_REG << PMUX_SHIFT),  /*!< lcsense_sequencer_primary_trigger_glue_out is selected */

    /*!< CMP0_SAMPLE: ACMP0 SAMPLE trigger input connections */
    kINPUTMUXAON_AonTrigIn0ToCmp0Sample               = 1U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< aon_trig_in0 input is selected */
    kINPUTMUXAON_AonTrigIn1ToCmp0Sample               = 2U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< aon_trig_in1 input is selected */
    kINPUTMUXAON_AonTrigIn2ToCmp0Sample               = 3U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< aon_trig_in2 input is selected */
    kINPUTMUXAON_AonTrigIn3ToCmp0Sample               = 4U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< aon_trig_in3 input is selected */
    kINPUTMUXAON_AonTrigIn4ToCmp0Sample               = 5U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< aon_trig_in4 input is selected */
    kINPUTMUXAON_AonTrigIn5ToCmp0Sample               = 6U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< aon_trig_in5 input is selected */
    kINPUTMUXAON_AonTrigIn6ToCmp0Sample               = 7U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< aon_trig_in6 input is selected */
    kINPUTMUXAON_AonTrigIn7ToCmp0Sample               = 8U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< aon_trig_in7 input is selected */
    kINPUTMUXAON_Cm33TeToCmp0Sample                   = 9U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_LpcmpOutToCmp0Sample                 = 10U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< lpcmp_out is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToCmp0Sample          = 12U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToCmp0Sample          = 13U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToCmp0Sample          = 14U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToCmp0Sample          = 15U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_Lptmr0OToCmp0Sample                  = 16U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< lptmr0 output is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToCmp0Sample          = 18U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToCmp0Sample          = 19U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToCmp0Sample          = 20U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToCmp0Sample          = 21U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */
    kINPUTMUXAON_WuuToCmp0Sample                      = 23U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< wuu is selected */
    kINPUTMUXAON_GpioApet0ToCmp0Sample                = 24U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< gpio (aon) pin event trig 0 is selected */
    kINPUTMUXAON_LpadcTriggerOut0ToCmp0Sample         = 26U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[0] is selected */
    kINPUTMUXAON_LpadcTriggerOut1ToCmp0Sample         = 27U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[1] is selected */
    kINPUTMUXAON_LpadcTriggerOut2ToCmp0Sample         = 28U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[2] is selected */
    kINPUTMUXAON_LpadcTriggerOut3ToCmp0Sample         = 29U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[3] is selected */
    kINPUTMUXAON_SocGlueXor0OutToCmp0Sample           = 34U + (CMP0_SAMPLE_REG << PMUX_SHIFT),  /*!< soc_glue_xor0_out is selected */

    /*!< CMP0_RR_TRIG: ACMP0 RR trigger input connections */
    kINPUTMUXAON_AonTrigIn0ToCmp0RrTrig               = 1U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in0 input is selected */
    kINPUTMUXAON_AonTrigIn1ToCmp0RrTrig               = 2U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in1 input is selected */
    kINPUTMUXAON_AonTrigIn2ToCmp0RrTrig               = 3U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in2 input is selected */
    kINPUTMUXAON_AonTrigIn3ToCmp0RrTrig               = 4U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in3 input is selected */
    kINPUTMUXAON_AonTrigIn4ToCmp0RrTrig               = 5U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in4 input is selected */
    kINPUTMUXAON_AonTrigIn5ToCmp0RrTrig               = 6U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in5 input is selected */
    kINPUTMUXAON_AonTrigIn6ToCmp0RrTrig               = 7U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in6 input is selected */
    kINPUTMUXAON_AonTrigIn7ToCmp0RrTrig               = 8U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in7 input is selected */
    kINPUTMUXAON_Cm33TeToCmp0RrTrig                   = 9U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_LpcmpOutToCmp0RrTrig                 = 10U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< lpcmp_out is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToCmp0RrTrig          = 12U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToCmp0RrTrig          = 13U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToCmp0RrTrig          = 14U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToCmp0RrTrig          = 15U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_Lptmr0OToCmp0RrTrig                  = 16U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< lptmr0 output is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToCmp0RrTrig          = 18U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToCmp0RrTrig          = 19U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToCmp0RrTrig          = 20U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToCmp0RrTrig          = 21U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */
    kINPUTMUXAON_WuuToCmp0RrTrig                      = 23U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< wuu is selected */
    kINPUTMUXAON_GpioApet0ToCmp0RrTrig                = 24U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< gpio (aon) pin event trig 0 is selected */
    kINPUTMUXAON_LpadcTriggerOut0ToCmp0RrTrig         = 26U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[0] is selected */
    kINPUTMUXAON_LpadcTriggerOut1ToCmp0RrTrig         = 27U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[1] is selected */
    kINPUTMUXAON_LpadcTriggerOut2ToCmp0RrTrig         = 28U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[2] is selected */
    kINPUTMUXAON_LpadcTriggerOut3ToCmp0RrTrig         = 29U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[3] is selected */
    kINPUTMUXAON_SocGlueXor0OutToCmp0RrTrig           = 34U + (CMP0_RR_TRIG_REG << PMUX_SHIFT),  /*!< soc_glue_xor0_out is selected */

    /*!< LPI2C0_TRIG: LPI2C0 trigger input connections */
    kINPUTMUXAON_AonTrigIn0ToLpi2c0Trig               = 1U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in0 input is selected */
    kINPUTMUXAON_AonTrigIn1ToLpi2c0Trig               = 2U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in1 input is selected */
    kINPUTMUXAON_AonTrigIn2ToLpi2c0Trig               = 3U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in2 input is selected */
    kINPUTMUXAON_AonTrigIn3ToLpi2c0Trig               = 4U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in3 input is selected */
    kINPUTMUXAON_AonTrigIn4ToLpi2c0Trig               = 5U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in4 input is selected */
    kINPUTMUXAON_AonTrigIn5ToLpi2c0Trig               = 6U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in5 input is selected */
    kINPUTMUXAON_AonTrigIn6ToLpi2c0Trig               = 7U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in6 input is selected */
    kINPUTMUXAON_AonTrigIn7ToLpi2c0Trig               = 8U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< aon_trig_in7 input is selected */
    kINPUTMUXAON_Cm33TeToLpi2c0Trig                   = 9U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_LpcmpOutToLpi2c0Trig                 = 10U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< lpcmp_out is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToLpi2c0Trig          = 12U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToLpi2c0Trig          = 13U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToLpi2c0Trig          = 14U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToLpi2c0Trig          = 15U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_Lptmr0OToLpi2c0Trig                  = 16U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< lptmr0 output is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToLpi2c0Trig          = 18U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToLpi2c0Trig          = 19U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToLpi2c0Trig          = 20U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToLpi2c0Trig          = 21U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */
    kINPUTMUXAON_WuuToLpi2c0Trig                      = 23U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< wuu is selected */
    kINPUTMUXAON_GpioApet0ToLpi2c0Trig                = 24U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< gpio (aon) pin event trig 0 is selected */
    kINPUTMUXAON_LpadcTriggerOut0ToLpi2c0Trig         = 26U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[0] is selected */
    kINPUTMUXAON_LpadcTriggerOut1ToLpi2c0Trig         = 27U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[1] is selected */
    kINPUTMUXAON_LpadcTriggerOut2ToLpi2c0Trig         = 28U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[2] is selected */
    kINPUTMUXAON_LpadcTriggerOut3ToLpi2c0Trig         = 29U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[3] is selected */
    kINPUTMUXAON_Acmp0RacoToLpi2c0Trig                = 30U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< acmp0 raw analog comparator output */
    kINPUTMUXAON_Acmp0AonCoutToLpi2c0Trig             = 31U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< acmp0_aon_cout is selected */
    kINPUTMUXAON_SocGlueXor0OutToLpi2c0Trig           = 34U + (LPI2C0_TRIG_REG << PMUX_SHIFT),  /*!< soc_glue_xor0_out is selected */

    /*!< LPUART0: LPUART0 trigger input connections */
    kINPUTMUXAON_AonTrigIn0ToLPUART0                  = 1U + (LPUART0_REG << PMUX_SHIFT),  /*!< aon_trig_in0 input is selected */
    kINPUTMUXAON_AonTrigIn1ToLPUART0                  = 2U + (LPUART0_REG << PMUX_SHIFT),  /*!< aon_trig_in1 input is selected */
    kINPUTMUXAON_AonTrigIn2ToLPUART0                  = 3U + (LPUART0_REG << PMUX_SHIFT),  /*!< aon_trig_in2 input is selected */
    kINPUTMUXAON_AonTrigIn3ToLPUART0                  = 4U + (LPUART0_REG << PMUX_SHIFT),  /*!< aon_trig_in3 input is selected */
    kINPUTMUXAON_AonTrigIn4ToLPUART0                  = 5U + (LPUART0_REG << PMUX_SHIFT),  /*!< aon_trig_in4 input is selected */
    kINPUTMUXAON_AonTrigIn5ToLPUART0                  = 6U + (LPUART0_REG << PMUX_SHIFT),  /*!< aon_trig_in5 input is selected */
    kINPUTMUXAON_AonTrigIn6ToLPUART0                  = 7U + (LPUART0_REG << PMUX_SHIFT),  /*!< aon_trig_in6 input is selected */
    kINPUTMUXAON_AonTrigIn7ToLPUART0                  = 8U + (LPUART0_REG << PMUX_SHIFT),  /*!< aon_trig_in7 input is selected */
    kINPUTMUXAON_Cm33TeToLPUART0                      = 9U + (LPUART0_REG << PMUX_SHIFT),  /*!< cm33 transmit event is selected */
    kINPUTMUXAON_LpcmpOutToLPUART0                    = 10U + (LPUART0_REG << PMUX_SHIFT),  /*!< lpcmp_out is selected */
    kINPUTMUXAON_Qtmr0Tmr0OutputToLPUART0             = 12U + (LPUART0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr0_output is selected */
    kINPUTMUXAON_Qtmr0Tmr1OutputToLPUART0             = 13U + (LPUART0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr1_output is selected */
    kINPUTMUXAON_Qtmr0Tmr2OutputToLPUART0             = 14U + (LPUART0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr2_output is selected */
    kINPUTMUXAON_Qtmr0Tmr3OutputToLPUART0             = 15U + (LPUART0_REG << PMUX_SHIFT),  /*!< qtmr0_tmr3_output is selected */
    kINPUTMUXAON_Lptmr0OToLPUART0                     = 16U + (LPUART0_REG << PMUX_SHIFT),  /*!< lptmr0 output is selected */
    kINPUTMUXAON_Qtmr1Tmr0OutputToLPUART0             = 18U + (LPUART0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr0_output is selected */
    kINPUTMUXAON_Qtmr1Tmr1OutputToLPUART0             = 19U + (LPUART0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr1_output is selected */
    kINPUTMUXAON_Qtmr1Tmr2OutputToLPUART0             = 20U + (LPUART0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr2_output is selected */
    kINPUTMUXAON_Qtmr1Tmr3OutputToLPUART0             = 21U + (LPUART0_REG << PMUX_SHIFT),  /*!< qtmr1_tmr3_output is selected */
    kINPUTMUXAON_WuuToLPUART0                         = 23U + (LPUART0_REG << PMUX_SHIFT),  /*!< wuu is selected */
    kINPUTMUXAON_GpioApet0ToLPUART0                   = 24U + (LPUART0_REG << PMUX_SHIFT),  /*!< gpio (aon) pin event trig 0 is selected */
    kINPUTMUXAON_LpadcTriggerOut0ToLPUART0            = 26U + (LPUART0_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[0] is selected */
    kINPUTMUXAON_LpadcTriggerOut1ToLPUART0            = 27U + (LPUART0_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[1] is selected */
    kINPUTMUXAON_LpadcTriggerOut2ToLPUART0            = 28U + (LPUART0_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[2] is selected */
    kINPUTMUXAON_LpadcTriggerOut3ToLPUART0            = 29U + (LPUART0_REG << PMUX_SHIFT),  /*!< lpadc_trigger_out[3] is selected */
    kINPUTMUXAON_Acmp0RacoToLPUART0                   = 30U + (LPUART0_REG << PMUX_SHIFT),  /*!< acmp0 raw analog comparator output */
    kINPUTMUXAON_Acmp0AonCoutToLPUART0                = 31U + (LPUART0_REG << PMUX_SHIFT),  /*!< acmp0_aon_cout is selected */
    kINPUTMUXAON_SocGlueXor0OutToLPUART0              = 34U + (LPUART0_REG << PMUX_SHIFT),  /*!< soc_glue_xor0_out is selected */

} inputmux_connection_t;

/*@}*/

/*@}*/

#endif /* _FSL_INPUTMUX_CONNECTIONS_ */