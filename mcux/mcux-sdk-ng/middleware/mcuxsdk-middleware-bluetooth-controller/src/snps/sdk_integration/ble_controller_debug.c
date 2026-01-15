/* Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "bsp.h"
#include "ble_controller.h"
#include "fsl_iocon.h"
#include "fsl_gpio.h"

#ifdef BLECONTROLLER_ENABLE_WARNINGS
#include "fsl_debug_console.h"
#endif

#ifdef BLECONTROLLER_ENABLE_WARNINGS
#define SEVERITY_HIGH 1
#define SEVERITY_LOW  0
#ifndef BLECONTROLLER_WARNINGS_SEVERITY
#define BLECONTROLLER_WARNINGS_SEVERITY SEVERITY_LOW
#endif /* BLECONTROLLER_WARNINGS_SEVERITY */
typedef struct
{
    const char *ptr_func_name;
    int line;
} warning_location_t;

#define BLECONTROLLER_WARNINGS_MEM_SIZE_BITS 2
static warning_location_t blecontroller_warning_locations[1 << BLECONTROLLER_WARNINGS_MEM_SIZE_BITS];
static uint8_t blecontroller_warning_count;
void bsp_warning(const char *ptr_func_name, const int line, uint8_t severity)
{
    if (severity < BLECONTROLLER_WARNINGS_SEVERITY)
    {
        return;
    }

    blecontroller_warning_locations[blecontroller_warning_count++ & ((1 << BLECONTROLLER_WARNINGS_MEM_SIZE_BITS) - 1)] =
        (warning_location_t){.ptr_func_name = ptr_func_name, .line = line};
    PRINTF("LL warning:%s:%d\r\n", ptr_func_name, line);
}
#endif /* BLECONTROLLER_ENABLE_WARNINGS */

typedef struct
{
    void (*bsp_evnt_not)(EvntNotiState enable);
    void (*bsp_debug_gpio_set)(Debug_GPIO_t gpio);
    void (*bsp_debug_gpio_clear)(Debug_GPIO_t gpio);
    void (*bsp_debug_gpio_toggle)(Debug_GPIO_t gpio);
    void (*bsp_set_phy_clbr_state)(PhyClbrState state);
} gpio_debug_functions_t;

static uint8_t gpio_map[Debug_GPIO_num];
typedef struct
{
    uint16_t controller_gpio;
    uint8_t board_gpio;
} controller_board_gpio_map_t;

#ifndef BLECONTROLLER_GPIO_MAP
#define BLECONTROLLER_GPIO_MAP {\
    {DBG_IO_SCHDLR_HNDL_NXT_TRACE,10},\
    {DBG_IO_LLWCC_CMN_HG_ISR,13},\
    {DBG_IO_SCHDLR_EXEC_EVNT_TRACE,14},\
    {DBG_IO_SCHDLR_HNDL_MISSED_EVNT,15}\
}
#endif

#ifndef LL_DBG_GPIO_FOR_RADIO_ACTIVITY
#define LL_DBG_GPIO_FOR_RADIO_ACTIVITY 16
#endif

static const controller_board_gpio_map_t controller_board_gpio_map[] = BLECONTROLLER_GPIO_MAP;

static void bsp_gpio_pulse(int pin)
{
    volatile uint8_t j;
    GPIO->NOT[0] = 1U << pin;
    for (j = 0; j < 2; j++)
    {
    }
    GPIO->NOT[0] = 1U << pin;
}

static void bsp_gpio_pulses(int pin, uint8_t nb)
{
    for (int i = 0; i < nb; i++)
    {
        bsp_gpio_pulse(pin);
    }
}

static void bsp_evnt_not_impl(EvntNotiState enable)
{
    (void)bsp_gpio_pulses;
#ifdef LL_DBG_GPIO_FOR_RADIO_ACTIVITY
    if (enable == EVNT_START)
    {
        GPIO->SET[0] = 1U << LL_DBG_GPIO_FOR_RADIO_ACTIVITY;
    }
    else if (enable == EVNT_END)
    {
        GPIO->CLR[0] = 1U << LL_DBG_GPIO_FOR_RADIO_ACTIVITY;
    }
    else
    {
#define NB_PULSES_ON_RADIO_ERROR 5
        bsp_gpio_pulses(LL_DBG_GPIO_FOR_RADIO_ACTIVITY, NB_PULSES_ON_RADIO_ERROR);
    }
#endif
}

static void bsp_debug_gpio_set_impl(Debug_GPIO_t gpio)
{
    if (gpio_map[gpio] != Debug_GPIO_num)
        GPIO->SET[0] = 1U << gpio_map[gpio];
}

static void bsp_debug_gpio_clear_impl(Debug_GPIO_t gpio)
{
    if (gpio_map[gpio] != Debug_GPIO_num)
        GPIO->CLR[0] = 1U << gpio_map[gpio];
}

static void bsp_debug_gpio_toggle_impl(Debug_GPIO_t gpio)
{
    if (gpio_map[gpio] != Debug_GPIO_num)
        GPIO->NOT[0] = 1U << gpio_map[gpio];
}

static void bsp_set_phy_clbr_state_impl(PhyClbrState state)
{
}

static void bsp_evnt_not_dummy(EvntNotiState enable)
{
}

static void bsp_debug_gpio_dummy(Debug_GPIO_t gpio)
{
}

static void bsp_set_phy_clbr_state_dummy(PhyClbrState state)
{
}

static const gpio_debug_functions_t gpio_debug_functions_dummy = {
    .bsp_evnt_not           = bsp_evnt_not_dummy,
    .bsp_debug_gpio_set     = bsp_debug_gpio_dummy,
    .bsp_debug_gpio_clear   = bsp_debug_gpio_dummy,
    .bsp_debug_gpio_toggle  = bsp_debug_gpio_dummy,
    .bsp_set_phy_clbr_state = bsp_set_phy_clbr_state_dummy};

static const gpio_debug_functions_t gpio_debug_functions = {.bsp_evnt_not           = bsp_evnt_not_impl,
                                                            .bsp_debug_gpio_set     = bsp_debug_gpio_set_impl,
                                                            .bsp_debug_gpio_clear   = bsp_debug_gpio_clear_impl,
                                                            .bsp_debug_gpio_toggle  = bsp_debug_gpio_toggle_impl,
                                                            .bsp_set_phy_clbr_state = bsp_set_phy_clbr_state_impl};

/*
 * Dummy / impl functions are used to avoid wasting time in checking an 'enabled' flag
 * The default implementation is a dummy one (NOP). When gpio debugging is enabled
 * the implementation is swapped to the actual one driving the pins.
 */
static const gpio_debug_functions_t *gpio_debug_functions_p = &gpio_debug_functions_dummy;

void bsp_evnt_not(EvntNotiState enable)
{
    gpio_debug_functions_p->bsp_evnt_not(enable);
}

void bsp_debug_gpio_set(Debug_GPIO_t gpio)
{
    gpio_debug_functions_p->bsp_debug_gpio_set(gpio);
}

void bsp_debug_gpio_clear(Debug_GPIO_t gpio)
{
    gpio_debug_functions_p->bsp_debug_gpio_clear(gpio);
}

void bsp_debug_gpio_toggle(Debug_GPIO_t gpio)
{
    gpio_debug_functions_p->bsp_debug_gpio_toggle(gpio);
}

void bsp_set_phy_clbr_state(PhyClbrState state)
{
    gpio_debug_functions_p->bsp_set_phy_clbr_state(state);
}

blec_result_t BLEController_EnableGPIODebugging(void)
{
    blec_result_t ret               = kBLEC_Success;
    uint32_t pinmux_pin_conf        = (IOCON_FUNC0 | IOCON_MODE_PULLDOWN | IOCON_SLEW_STANDARD |
                                IOCON_DIGITAL_EN);
    gpio_pin_config_t gpio_pin_conf = {.pinDirection = kGPIO_DigitalOutput, .outputLogic = 0U};

    /*
     * Initialize the gpio mapping to an invalid value.
     * By default controller_gpios don't toggle any board gpio.
     * This is overriden by BLECONTROLLER_GPIO_MAP to selectively
     * enable controller gpios and map them to board gpios
     */
    memset(gpio_map, Debug_GPIO_num, sizeof(gpio_map));
    for (int i = 0; i < sizeof(controller_board_gpio_map) / sizeof(controller_board_gpio_map[0]); i++)
    {
        const controller_board_gpio_map_t *entry = &controller_board_gpio_map[i];
        gpio_map[entry->controller_gpio]         = entry->board_gpio;
        GPIO_PinInit(GPIO, 0, entry->board_gpio, &gpio_pin_conf);
        IOCON_PinMuxSet(IOCON, 0, entry->board_gpio, pinmux_pin_conf);
    }

#ifdef LL_DBG_GPIO_FOR_RADIO_ACTIVITY
    GPIO_PinInit(GPIO, 0, LL_DBG_GPIO_FOR_RADIO_ACTIVITY, &gpio_pin_conf);
    IOCON_PinMuxSet(IOCON, 0, LL_DBG_GPIO_FOR_RADIO_ACTIVITY, pinmux_pin_conf);
#endif

    gpio_debug_functions_p = &gpio_debug_functions;
    return ret;
}

blec_result_t BLEController_DisableGPIODebugging(void)
{
    blec_result_t ret      = kBLEC_Success;
    gpio_debug_functions_p = &gpio_debug_functions_dummy;
    return ret;
}
