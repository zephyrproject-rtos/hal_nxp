/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_SIUL2_H_
#define FSL_SIUL2_H_

#include "fsl_common.h"

/*!
 * @addtogroup siul2
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief SIUL2 driver version. */
#define FSL_SIUL2_DRIVER_VERSION (MAKE_VERSION(2, 0, 3))

/*! @brief SIUL2 module maximum number of input signal on a pin */
#define FEATURE_SIUL2_MAX_NUMBER_OF_INPUT (16U)

#ifndef FEATURE_ADC_INTERLEAVE_MAX_MUX_MODE
#define FEATURE_ADC_INTERLEAVE_MAX_MUX_MODE \
    (2U) /*!< Some pins have two ADC interleave config, such as GPIO45 can be muxed as ADC0_S8 & ADC2_S8. */
#endif
#define DCM_DCMRWF4_ADC_INTERLEAVE_MASK (uint32_t)0x00001FFFUL /*!< Mask all adc interleave bits, some bit may not exist on some parts. */

#define SIUL2_PORT_WRITE8(address, value)  ((*(volatile uint8_t *)(address)) = (value))
#define SIUL2_PORT_WRITE32(address, value) ((*(volatile uint32_t *)(address)) = (value))

#define SIUL2_PORT_READ32(address) (*(volatile uint32_t *)(address))
#define SIUL2_PORT_READ8(address)  (*(volatile uint8_t *)(address))

#define SIUL2_GPDO_ADDR(base, pin) ((uint32_t)base + (uint32_t)0x1300UL + (((pin) & ~3UL) | (~((pin)&3UL) & 3UL)))
#define SIUL2_GPDI_ADDR(base, pin) ((uint32_t)base + (uint32_t)0x1500UL + (((pin) & ~3UL) | (~((pin)&3UL) & 3UL)))

#define SIUL2_PGPDO_REG_16_31(base, x) (*((volatile uint16_t *)((uint32_t)(&(base->PGPDO[0])) + ((x) << 2U))))
#define SIUL2_PGPDO_REG_0_15(base, x)  (*((volatile uint16_t *)((uint32_t)(&(base->PGPDO[1])) + ((x) << 2U))))

/*! @} */
/*!
 * @brief Type of a port levels representation.
 */
typedef uint8_t siul2_port_pins_Level_t;

/*!
 * @brief Internal resistor pull feature selection
 */
typedef enum siul2_port_pull_config
{
    kPORT_INTERNAL_PULL_DOWN_ENABLED = 0U, /*!< internal pull-down resistor is enabled.     */
    kPORT_INTERNAL_PULL_UP_ENABLED   = 1U, /*!< internal pull-up resistor is enabled.       */
    kPORT_INTERNAL_PULL_NOT_ENABLED  = 2U  /*!< internal pull-down/up resistor is disabled. */
} siul2_port_pull_config_t;

/*!
 * @brief Configures the Pin output muxing selection
 */
typedef enum siul2_port_mux
{
    kPORT_MUX_AS_GPIO       = 0U,  /*!< corresponding pin is configured as GPIO */
    kPORT_MUX_ALT1          = 1U,  /*!< chip-specific                           */
    kPORT_MUX_ALT2          = 2U,  /*!< chip-specific                           */
    kPORT_MUX_ALT3          = 3U,  /*!< chip-specific                           */
    kPORT_MUX_ALT4          = 4U,  /*!< chip-specific                           */
    kPORT_MUX_ALT5          = 5U,  /*!< chip-specific                           */
    kPORT_MUX_ALT6          = 6U,  /*!< chip-specific                           */
    kPORT_MUX_ALT7          = 7U,  /*!< chip-specific                           */
    kPORT_MUX_ALT8          = 8U,  /*!< chip-specific                           */
    kPORT_MUX_ALT9          = 9U,  /*!< chip-specific                           */
    kPORT_MUX_ALT10         = 10U, /*!< chip-specific                           */
    kPORT_MUX_ALT11         = 11U, /*!< chip-specific                           */
    kPORT_MUX_ALT12         = 12U, /*!< chip-specific                           */
    kPORT_MUX_ALT13         = 13U, /*!< chip-specific                           */
    kPORT_MUX_ALT14         = 14U, /*!< chip-specific                           */
    kPORT_MUX_ALT15         = 15U, /*!< chip-specific                           */
    kPORT_MUX_NOT_AVAILABLE = 16U  /*!< chip-specific                           */
} siul2_port_mux_t;

/*!
 * @brief Configures the Pin filter enable
 */
typedef enum siul2_port_input_filter
{
    kPORT_INPUT_FILTER_DISABLED      = 0U, /*!< IFE OFF*/
    kPORT_INPUT_FILTER_ENABLED       = 1U, /*!< IFE ON*/
    kPORT_INPUT_FILTER_NOT_AVAILABLE = 2U  /*!< IFE NOT AVAILABLE*/
} siul2_port_input_filter_t;

/*!
 * @brief Configures the Pad keep enable
 */
typedef enum port_pull_keep
{
    kPORT_PULL_KEEP_DISABLED      = 0U, /*!< PKE OFF*/
    kPORT_PULL_KEEP_ENABLED       = 1U, /*!< PKE ON*/
    kPORT_PULL_KEEP_NOT_AVAILABLE = 2U  /*!< PKE NOT AVAILABLE*/
} siul2_port_pull_keep_t;

/*!
 * @brief Configures signal invert for the pin
 */
typedef enum siul2_port_invert
{
    kPORT_INVERT_DISABLED      = 0U, /*!< INV OFF*/
    kPORT_INVERT_ENABLED       = 1U, /*!< INV ON*/
    kPORT_INVERT_NOT_AVAILABLE = 2U  /*!< INV NOT AVAILABLE*/
} siul2_port_invert_t;

/*!
 * @brief Configures the output buffer enable
 */
typedef enum siul2_port_output_buffer
{
    kPORT_OUTPUT_BUFFER_DISABLED      = 0U, /*!< Output buffer disabled */
    kPORT_OUTPUT_BUFFER_ENABLED       = 1U, /*!< Output buffer enabled  */
    kPORT_OUTPUT_BUFFER_NOT_AVAILABLE = 2U  /*!< Output buffer not available  */
} siul2_port_output_buffer_t;

/*!
 * @brief Configures the Input Buffer Enable field.
 */
typedef enum siul2_port_input_buffer
{
    kPORT_INPUT_BUFFER_DISABLED      = 0U, /*!< Input buffer disabled */
    kPORT_INPUT_BUFFER_ENABLED       = 1U, /*!< Input buffer enabled  */
    kPORT_INPUT_BUFFER_NOT_AVAILABLE = 2U  /*!< Input buffer not available */
} siul2_port_input_buffer_t;

/*!
 * @brief Configures the Pin input muxing selection
 */
typedef enum
{
    kPORT_INPUT_MUX_ALT0    = 0U,  /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT1    = 1U,  /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT2    = 2U,  /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT3    = 3U,  /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT4    = 4U,  /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT5    = 5U,  /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT6    = 6U,  /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT7    = 7U,  /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT8    = 8U,  /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT9    = 9U,  /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT10   = 10U, /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT11   = 11U, /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT12   = 12U, /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT13   = 13U, /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT14   = 14U, /*!< Chip-specific     */
    kPORT_INPUT_MUX_ALT15   = 15U, /*!< Chip-specific     */
    kPORT_INPUT_MUX_NO_INIT = 16U  /*!< No initialization */
} siul2_port_inputmux_t;

/*!
 * @brief Configures the Safe Mode Control.
 */
typedef enum siul2_port_safe_mode
{
    kPORT_SAFE_MODE_DISABLED = 0U,      /*!< To drive pad in hi-z state using OBE = 0, when FCCU in fault state.
                                         *   The OBE will be driven by IP/SIUL when FCCU leaves the fault state. */
    kPORT_SAFE_MODE_ENABLED       = 1U, /*!< No effect on IP/SIUL driven OBE value */
    kPORT_SAFE_MODE_NOT_AVAILABLE = 2U  /*!< Not available  */
} siul2_port_safe_mode_t;

/*!
 * @brief Configures the slew rate control.
 */
typedef enum siul2__port_slew_rate
{
    kPORT_SLEW_RATE_FASTEST       = 0U, /*!< Fmax=133 MHz(at 1.8V), 100 MHz (at 3.3V), apply for SIUL2_0/1  */
    kPORT_SLEW_RATE_SLOWEST       = 1U, /*!< Fmax=83 MHz (at 1.8V), 63 MHz (at 3.3V), apply for SIUL2_0/1   */
    kPORT_SLEW_RATE_NOT_AVAILABLE = 2U  /*!< Not available   */
} siul2_port_slew_rate_t;

/*!
 * @brief Configures the drive strength.
 */
typedef enum siul2_port_drive_strength
{
    kPORT_DRIVE_STRENTGTH_DISABLED      = 0U, /*!< Disables DSE. */
    kPORT_DRIVE_STRENTGTH_ENABLED       = 1U, /*!< Enables DSE.*/
    kPORT_DRIVE_STRENTGTH_NOT_AVAILABLE = 2U  /*!< Not available.*/
} siul2_port_drive_strength_t;

/*!
 * @brief Configures port direction.
 */
typedef enum siul2_port_direction
{
    kPORT_IN     = 0U, /**< @brief Sets port pin as input. */
    kPORT_OUT    = 1U, /**< @brief Sets port pin as output. */
    kPORT_IN_OUT = 2U, /**< @brief Sets port pin as bidirectional. */
    kPORT_HI_Z   = 3U  /**< @brief Sets port pin as high_z. */
} siul2_port_direction_t;

/*!
 * @brief Configures adc interleave mux mode.
 * Note! Not all are supported for a given part, please refer to IOMUX table for supported interleaves. 
 */
typedef enum siul2_adc_interleaves
{
    kMUX_MODE_NOT_AVAILABLE = (uint32_t)0x00000000UL, /*!< Adc Interleave not available. */
    kMUX_MODE_EN_ADC1_S18_1 = (uint32_t)0x00000001UL, /*!< Set bit ADC1_S18 to 1 */
    kMUX_MODE_EN_ADC0_S8_1  = (uint32_t)0x00000002UL, /*!< Set bit ADC0_S8 to 1 */
    kMUX_MODE_EN_ADC0_S9_1  = (uint32_t)0x00000004UL, /*!< Set bit ADC0_S9 to 1 */
    kMUX_MODE_EN_ADC1_S14_1 = (uint32_t)0x00000008UL, /*!< Set bit ADC1_S14 to 1 */
    kMUX_MODE_EN_ADC1_S15_1 = (uint32_t)0x00000010UL, /*!< Set bit ADC1_S15 to 1 */
    kMUX_MODE_EN_ADC1_S22_1 = (uint32_t)0x00000020UL, /*!< Set bit ADC1_S22 to 1 */
    kMUX_MODE_EN_ADC1_S23_1 = (uint32_t)0x00000040UL, /*!< Set bit ADC1_S23 to 1 */
    kMUX_MODE_EN_ADC0_S12_1 = (uint32_t)0x00000080UL, /*!< Set bit ADC0_S12 to 1 */
    kMUX_MODE_EN_ADC0_S13_1 = (uint32_t)0x00000100UL, /*!< Set bit ADC0_S13 to 1 */
    kMUX_MODE_EN_ADC2_S8_1  = (uint32_t)0x00000200UL, /*!< Set bit ADC2_S8 to 1 */
    kMUX_MODE_EN_ADC2_S9_1  = (uint32_t)0x00000400UL, /*!< Set bit ADC2_S9 to 1 */
    kMUX_MODE_EN_ADC0_S14_1 = (uint32_t)0x00000800UL, /*!< Set bit ADC0_S14 to 1 */
    kMUX_MODE_EN_ADC0_S17_1 = (uint32_t)0x00001000UL, /*!< Set bit ADC0_S17 to 1 */

    kMUX_MODE_EN_ADC1_S18_0 =
        (uint32_t)0x0000FFFEUL, /*!< With bits 15-0, only clear ADC1_S18 bit, the other bits set to 1  */
    kMUX_MODE_EN_ADC0_S8_0 =
        (uint32_t)0x0000FFFDUL, /*!< With bits 15-0, only clear ADC0_S8 bit, the other bits set to 1  */
    kMUX_MODE_EN_ADC0_S9_0 =
        (uint32_t)0x0000FFFBUL, /*!< With bits 15-0, only clear ADC0_S9 bit, the other bits set to 1  */
    kMUX_MODE_EN_ADC1_S14_0 =
        (uint32_t)0x0000FFF7UL, /*!< With bits 15-0, only clear ADC1_S14 bit, the other bits set to 1 */
    kMUX_MODE_EN_ADC1_S15_0 =
        (uint32_t)0x0000FFEFUL, /*!< With bits 15-0, only clear ADC1_S15 bit, the other bits set to 1 */
    kMUX_MODE_EN_ADC1_S22_0 =
        (uint32_t)0x0000FFDFUL, /*!< With bits 15-0, only clear ADC1_S22 bit, the other bits set to 1 */
    kMUX_MODE_EN_ADC1_S23_0 =
        (uint32_t)0x0000FFBFUL, /*!< With bits 15-0, only clear ADC1_S23 bit, the other bits set to 1 */
    kMUX_MODE_EN_ADC0_S12_0 =
        (uint32_t)0x0000FF7FUL, /*!< With bits 15-0, only clear ADC0_S12 bit, the other bits set to 1 */
    kMUX_MODE_EN_ADC0_S13_0 =
        (uint32_t)0x0000FEFFUL, /*!< With bits 15-0, only clear ADC0_S13 bit, the other bits set to 1 */  
    kMUX_MODE_EN_ADC2_S8_0 =
        (uint32_t)0x0000FDFFUL, /*!< With bits 15-0, only clear ADC2_S8 bit, the other bits set to 1  */
    kMUX_MODE_EN_ADC2_S9_0 =
        (uint32_t)0x0000FBFFUL, /*!< With bits 15-0, only clear ADC2_S9 bit, the other bits set to 1  */
    kMUX_MODE_EN_ADC0_S14_0 =
        (uint32_t)0x0000F7FFUL, /*!< With bits 15-0, only clear ADC0_S14 bit, the other bits set to 1 */
    kMUX_MODE_EN_ADC0_S17_0 =
        (uint32_t)0x0000EFFFUL, /*!< With bits 15-0, only clear ADC0_S17 bit, the other bits set to 1 */

} siul2_adc_interleaves_t;

/*!
 * @brief Defines the converter configuration
 *
 * This structure is used to configure the pins
 */
typedef struct siul2_pin_settings
{
    SIUL2_Type *base;                          /*!< The main SIUL2 base pointer.                               */
    uint32_t pinPortIdx;                       /*!< Port pin number.                                           */
    siul2_port_pull_config_t pullConfig;       /*!< Internal resistor pull feature selection.                  */
    siul2_port_mux_t mux;                      /*!< Pin output muxing selection.                               */
    siul2_port_safe_mode_t safeMode;           /*!< Configures the Safe Mode Control, apply for SIUL2_0/1      */
    siul2_port_slew_rate_t slewRateCtrlSel;    /*!< Configures the Slew Rate Control field.                    */
    siul2_port_drive_strength_t driveStrength; /*!< Configures DSE                                             */
    siul2_port_input_filter_t inputFilter;     /*!< Configures IFE                                             */
    siul2_port_pull_keep_t pullKeep;           /*!< Configures PKE                                             */
    siul2_port_invert_t invert;                /*!< Configures IFE                                             */
    siul2_port_output_buffer_t outputBuffer;   /*!< Configures the Output Buffer Enable.                       */
    siul2_port_input_buffer_t inputBuffer;     /*!< Configures the Input Buffer Enable.                        */
    siul2_adc_interleaves_t
        adcInterleaves[FEATURE_ADC_INTERLEAVE_MAX_MUX_MODE];           /*!< Configures the adc interleave mux modes. */
    siul2_port_inputmux_t inputMux[FEATURE_SIUL2_MAX_NUMBER_OF_INPUT]; /*!< Configures the input muxing */
    uint32_t inputMuxReg[FEATURE_SIUL2_MAX_NUMBER_OF_INPUT];
    /*!< Configures the input muxing register. For the pins controlled by both SIUL2_0
     * and SIUL2_1 instances, refer the note for PINS_DRV_SetInputBuffer function      */
    siul2_port_pins_Level_t initValue; /*!< Initial value                                              */
} siul2_pin_settings_t;

/*! @brief PORT definition */
typedef enum _siul2_port_num
{
    kSIUL2_PTA = 0U, /*!< PTA. */
    kSIUL2_PTB = 1U, /*!< PTB. */
    kSIUL2_PTC = 2U, /*!< PTC. */
    kSIUL2_PTD = 3U, /*!< PTD. */
    kSIUL2_PTE = 4U, /*!< PTE. */
    kSIUL2_PTF = 5U, /*!< PTF. */
    kSIUL2_PTG = 6U, /*!< PTG. */
} siul2_port_num_t;

typedef struct siul2_filter_config
{
    uint8_t preScaler : 4; /*!< Interrupt Filter clock prescaler setting, 0-15. */
    uint8_t maxCount : 4;  /*!< Interrupt Filter Maximum Counter, 0-15. */
} siul2_filter_config_t;

typedef enum siul2_interrupt_config
{
    kSIUL2_InterruptStatusFlagDisabled = 0U, /*!< Interrupt status flag is disabled. */
    kSIUL2_InterruptRisingEdge         = 0x1U,
    kSIUL2_InterruptFallingEdge        = 0x2U,
    kSIUL2_InterruptBothEdge           = 0x3U,
} siul2_interrupt_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initialize pin.
 *
 * @param config the pin's setting @ref siul2_pin_settings_t.
 */
void SIUL2_PinInit(const siul2_pin_settings_t *config);

/*!
 * @brief Set the pin Input Buffer.
 *
 * @param base SIUL2 peripheral base pointer
 * @param pin pin number, 0, 1...511, see RM for available pins
 * @param enable Enable output buffer
 * @param inputMuxReg Pin muxing register slot selection
 * @param inputMux Pin muxing slot selection
 */
void SIUL2_SetPinInputBuffer(SIUL2_Type *base, uint32_t pin, bool enable, uint32_t inputMuxReg, siul2_port_inputmux_t inputMux);

/*!
 * @brief Set the pin Output Buffer.
 *
 * @param base SIUL2 peripheral base pointer
 * @param pin pin number, 0, 1...511, see RM for available pins
 * @param enable Enable output buffer
 * @param mux Pin muxing slot selection
 */
void SIUL2_SetPinOutputBuffer(SIUL2_Type *base, uint32_t pin, bool enable, siul2_port_mux_t mux);

/*!
 * @brief Configures the pin pull select.
 *
 * This function configures the internal resistor.
 *
 * @param base SIUL2 peripheral base pointer
 * @param pin pin number, 0, 1...511, see RM for available pins
 * @param pullConfig The pull configuration
 */
void SIUL2_SetPinPullSel(SIUL2_Type *base, uint32_t pin, siul2_port_pull_config_t pullConfig);

/*!
 * @brief Set the pin direction.
 *
 * @param base SIUL2 peripheral base pointer
 * @param pin pin number, 0, 1...511, see RM for available pins.
 * @param direction pin direction.
 */
void SIUL2_SetPinDirection(SIUL2_Type *base, uint32_t pin, siul2_port_direction_t direction);

/*!
 * @brief Sets the output level of the multiple GPIO pins to the logic 1.
 *
 * @param base SIUL2 peripheral base pointer
 * @param port GPIO PORT number, see "siul2_port_num_t".
 * @param pins ORed GPIO pins in a port.
 */
void SIUL2_PortSet(SIUL2_Type *base, siul2_port_num_t port, uint32_t pins);

/*!
 * @brief Sets the output level of the multiple GPIO pins to the logic 1.
 *
 * @param base SIUL2 peripheral base pointer
 * @param port GPIO PORT number, see "siul2_port_num_t".
 * @param pins GPIO pins to be configured.
 * @param mask ORed bits of which pins will be masked.
 */
void SIUL2_PortMaskWrite(SIUL2_Type *base, siul2_port_num_t port, uint32_t pins, uint32_t mask);

/*!
 * @brief Sets the output level of the multiple GPIO pins to the logic 0.
 *
 * @param base SIUL2 peripheral base pointer
 * @param port GPIO PORT number, see "siul2_port_num_t".
 * @param pins GPIO pin number macro
 */
void SIUL2_PortClear(SIUL2_Type *base, siul2_port_num_t port, uint32_t pins);

/*!
 * @brief Toggle the output level of the multiple GPIO pins.
 *
 * @param base SIUL2 peripheral base pointer
 * @param port GPIO PORT number, see "siul2_port_num_t".
 * @param pins GPIO pin number macro
 */
void SIUL2_PortToggle(SIUL2_Type *base, siul2_port_num_t port, uint32_t pins);

/*!
 * @brief Set the pin output.
 *
 * @param base SIUL2 peripheral base pointer
 * @param port GPIO PORT number, see "siul2_port_num_t".
 * @param pin GPIO pin number
 * @param output Output value, 0 or 1.
 */
static inline void SIUL2_PortPinWrite(SIUL2_Type *base, siul2_port_num_t port, uint32_t pin, uint8_t output)
{
    assert(pin < 32U); /* Check pin number is valid. */

    uint32_t pinIndex = (uint32_t)port * 32U + pin;

    SIUL2_PORT_WRITE8(SIUL2_GPDO_ADDR(base, pinIndex), output);
}

/*!
 * @brief Get the pin input.
 *
 * @param base SIUL2 peripheral base pointer
 * @param port GPIO PORT number, see "siul2_port_num_t".
 * @param pin GPIO pin number
 */
inline static uint32_t SIUL2_PortPinRead(SIUL2_Type *base, siul2_port_num_t port, uint8_t pin)
{
    assert(pin < 32U); /* Check pin number is valid. */

    uint32_t pinIndex = (uint32_t)port * 32U + pin;
    return SIUL2_PORT_READ8(SIUL2_GPDI_ADDR(base, pinIndex));
}


/*!
 * @brief Set the pin output.
 *
 * @param base SIUL2 peripheral base pointer
 * @param pin GPIO pin number
 * @param output Output value, 0 or 1.
 */
static inline void SIUL2_PinWrite(SIUL2_Type *base, uint32_t pin, uint8_t output)
{
    SIUL2_PORT_WRITE8(SIUL2_GPDO_ADDR(base, pin), output);
}

/*!
 * @brief Get the pin input.
 *
 * @param base SIUL2 peripheral base pointer
 * @param pin GPIO pin number
 */
inline static uint32_t SIUL2_PinRead(SIUL2_Type *base, uint8_t pin)
{
    return SIUL2_PORT_READ8(SIUL2_GPDI_ADDR(base, pin));
}

/*!
 * @brief Set the Glitch filter prescaler.
 *
 * @param base SIUL2 peripheral base pointer
 * @param div Glitch filter prescaler 0...15. Prescaled Filter Clock period is internal oscillator period x (div + 1).
 */
inline static void SIUL2_SetGlitchFilterPrescaler(SIUL2_Type *base, uint8_t div)
{
    base->IFCPR = SIUL2_IFCPR_IFCP(div);
}

/*!
 * @brief Set Glitch filter max count.
 *
 * @param base SIUL2 peripheral base pointer
 * @param req which interrupt/DMA request to set, 0...31
 * @param filterCount Maximum filter count 0...15, < 0 disable filterCount.
 */
inline static void SIUL2_SetGlitchFilterMaxCount(SIUL2_Type *base, uint32_t req, int8_t filterCount)
{
    if (filterCount >= 0) /* Enable and config filter*/
    {
        base->IFER0 |= 1U << req;
        base->IFMCR[req] = filterCount;
    }
    else
    {
        base->IFER0 &= ~(1U << req);
    }
}

/*!
 * @brief Setup Interupt configuration.
 *
 * @param base SIUL2 peripheral base pointer
 * @param req which interrupt/DMA request to set, 0...31
 * @param config the configuration structure.
 */
void SIUL2_SetDmaInterruptConfig(SIUL2_Type *base, uint32_t req, siul2_interrupt_config_t config);

/*!
 * @brief Enable external interrupt.
 *
 * @param base SIUL2 peripheral base pointer
 * @param req which interrupt/DMA request to set, 0...31
 * @param config interrupt configuration, @ref siul2_interrupt_config_t
 * @param filterCount Maximum filter count 0...15, < 0 disable filterCount.
 */
void SIUL2_EnableExtInterrupt(SIUL2_Type *base, uint32_t req, siul2_interrupt_config_t config, int8_t filterCount);

/*!
 * @brief Enable external DMA request.
 *
 * @param base SIUL2 peripheral base pointer
 * @param req which interrupt/DMA request to set, 0...31
 * @param config interrupt configuration, @ref siul2_interrupt_config_t
 * @param filterCount Maximum filter count 0...15, < 0 disable filterCount.
 */
void SIUL2_EnableExtDma(SIUL2_Type *base, uint32_t req, siul2_interrupt_config_t config, int8_t filterCount);

/*!
 * @brief Disable external DMA and interrupt.
 *
 * @param base SIUL2 peripheral base pointer
 * @param req which interrupt/DMA request to set, 0...31
 */
inline static void SIUL2_DisableExtDmaAndInterrupt(SIUL2_Type *base, uint32_t req)
{
    base->DIRER0 &= ~(1U << req); /* Disable Int/DMA request. */
}

/*!
 * @brief Disable mutliple external DMA and interrupts.
 *
 * @param base SIUL2 peripheral base pointer
 * @param mask bit mask of external DMA or interupt requests
 */
inline static void SIUL2_DisableExtDmaAndInterrupts(SIUL2_Type *base, uint32_t mask)
{
    base->DIRER0 &= ~mask; /* Disable Int/DMA requests. */
}

/*!
 * @brief Enable mutliple external interrupts.
 *
 * @param base SIUL2 peripheral base pointer
 * @param mask bit mask ofinterrupt requests
 * @param config interrupt configuration, @ref siul2_interrupt_config_t
 * @param filterCount Maximum filter count 0...15, < 0 disable filterCount.
 */
void SIUL2_EnableExtInterrupts(SIUL2_Type *base, uint32_t mask, siul2_interrupt_config_t config, int8_t filterCount);

/*!
 * @brief Enable mutliple external DMA requests.
 *
 * @param base SIUL2 peripheral base pointer
 * @param mask bit mask of DMA requests
 * @param config interrupt configuration, @ref siul2_interrupt_config_t
 * @param filterCount Maximum filter count 0...15, < 0 disable filterCount.
 */
void SIUL2_EnableExtDmaRequests(SIUL2_Type *base, uint32_t mask, siul2_interrupt_config_t config, int8_t filterCount);

/*!
 * @brief Get the external DMA/interrupt status flag.
 *
 * @param base SIUL2 peripheral base pointer
 * @return the status flags
 */
inline static uint32_t SIUL2_GetExtDmaInterruptStatusFlags(SIUL2_Type *base)
{
    return base->DISR0;
}

/*!
 * @brief Clear the external DMA/interrupt status flags.
 *
 * @param base SIUL2 peripheral base pointer
 * @param mask the status flags bit mask
 */
inline static void SIUL2_ClearExtDmaInterruptStatusFlags(SIUL2_Type *base, uint32_t mask)
{
    base->DISR0 |= mask;
}
#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_GPIO_H_*/
