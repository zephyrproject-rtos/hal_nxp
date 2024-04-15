/* -------------------------------------------------------------------------- */
/*                           Copyright 2022-2023 NXP                               */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include <stdint.h>
#include "fwk_platform_coex.h"
#include "fsl_adapter_gpio.h"
#include "fsl_common.h"
#include "wifi-decl.h"
#include "sduart_nw61x_se.h"
#include "firmware_dnld.h"
#include "fwdnld_intf_abs.h"
#include "fsl_os_abstraction.h"
#include "fwk_platform.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */
#ifndef PLATFORM_CONFIG_DEFAULT_RESET_DELAY_MS
// Default delay after R̅E̅S̅E̅T̅ assertion, in miliseconds.
#define PLATFORM_CONFIG_DEFAULT_RESET_DELAY_MS 200
#endif

#ifndef PLATFORM_RESET_PIN_PORT
#define PLATFORM_RESET_PIN_PORT 3
#endif

#ifndef PLATFORM_RESET_PIN_NUM
#define PLATFORM_RESET_PIN_NUM 9
#endif

#ifndef PLATFORM_RESET_PIN_LVL_ON
#define PLATFORM_RESET_PIN_LVL_ON 1U
#endif

#ifndef PLATFORM_RESET_PIN_LVL_OFF
#define PLATFORM_RESET_PIN_LVL_OFF 0U
#endif

/* Weak function. */
#if defined(__GNUC__)
#define __WEAK_FUNC __attribute__((weak))
#elif defined(__ICCARM__)
#define __WEAK_FUNC __weak
#elif defined(__CC_ARM) || defined(__ARMCC_VERSION)
#define __WEAK_FUNC __attribute__((weak))
#endif

#define PLATFORM_IOEXP_I2C_ADDR_7BIT            0x20U
#define PLATFORM_IOEXP_CONFIGURATION_REG        0x03U
#define PLATFORM_IOEXP_CONFIGURATION_SPI_ENABLE 0xFEU

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static GPIO_HANDLE_DEFINE(otGpioResetHandle);

static const hal_gpio_pin_config_t resetPinConfig = {
    .direction = kHAL_GpioDirectionOut,
    .level     = PLATFORM_RESET_PIN_LVL_OFF,
    .port      = PLATFORM_RESET_PIN_PORT,
    .pin       = PLATFORM_RESET_PIN_NUM,
};

static bool isOtControllerUp = false;

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

static int PLATFORM_ResetController(void);

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

extern int wlan_init(const uint8_t *fw_start_addr, const size_t size);

int PLATFORM_InitControllers(uint8_t controllersMask)
{
    (void)controllersMask;

    hal_gpio_status_t status;
    int               ret = 0;

    /*  initialize controller if not done */
    if (isOtControllerUp == false)
    {
        do
        {
            /* Init the reset output gpio */
            status = HAL_GpioInit((hal_gpio_handle_t)otGpioResetHandle, (hal_gpio_pin_config_t *)&resetPinConfig);
            if (status != kStatus_HAL_GpioSuccess)
            {
                ret = -1;
                break;
            }
            (void)status;

            /* Reset RCP chip. */
            if (PLATFORM_ResetController() != 0)
            {
                ret = -2;
                break;
            }

            /* check if Wi-Fi is supported */
            if ((controllersMask & connWlan_c) != 0)
            {
                ret = wlan_init(wlan_fw_bin, wlan_fw_bin_len);
                assert(WM_SUCCESS == ret);
            }
            else
            {
                /* Download firmware */
                fwdnld_intf_t *intf;
                intf = fwdnld_intf_init(FWDNLD_INTF_SDIO, NULL);
                ret  = firmware_download(wlan_fw_bin, wlan_fw_bin_len, intf, 0);
                assert(WM_SUCCESS == ret);
            }

            /* Waiting for the RCP chip starts up */
            OSA_TimeDelay(PLATFORM_CONFIG_DEFAULT_RESET_DELAY_MS);

            if ((controllersMask & conn802_15_4_c) != 0)
            {
                /* Configure IO_Expander to enable SPI interface through M.2 connector */
                PLATFORM_IOEXP_I2C_program(PLATFORM_IOEXP_I2C_ADDR_7BIT, PLATFORM_IOEXP_CONFIGURATION_REG,
                                           PLATFORM_IOEXP_CONFIGURATION_SPI_ENABLE);
            }

            isOtControllerUp = true;
        } while (false);
    }

    return ret;
}

/*
 * Empty wlan function that could be redefined if Wi-Fi is supported
 */
__WEAK_FUNC int wlan_init(const uint8_t *fw_start_addr, const size_t size)
{
    return WM_SUCCESS;
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */
static int PLATFORM_ResetController(void)
{
    hal_gpio_status_t status;
    int               ret = 0;

    do
    {
        // Set Reset pin to low level.
        status = HAL_GpioSetOutput((hal_gpio_handle_t)otGpioResetHandle, PLATFORM_RESET_PIN_LVL_OFF);
        if (status != kStatus_HAL_GpioSuccess)
        {
            ret = -1;
            break;
        }

        OSA_TimeDelay(PLATFORM_CONFIG_DEFAULT_RESET_DELAY_MS);

        // Set Reset pin to high level.
        status = HAL_GpioSetOutput((hal_gpio_handle_t)otGpioResetHandle, PLATFORM_RESET_PIN_LVL_ON);
        if (status != kStatus_HAL_GpioSuccess)
        {
            ret = -2;
            break;
        }
    } while (false);

    return ret;
}
