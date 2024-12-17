/** @file mlan_sdio.c
 *
 *  @brief This file provides mlan driver for SDIO
 *
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include <mlan_sdio_api.h>
#include <osa.h>
#include <fsl_common.h>
#include <fsl_gpio.h>
#include <zephyr/sd/sdio.h>

#include <zephyr/drivers/gpio.h>

#define SDIO_CMD_TIMEOUT 2000

const struct device *sdhc_dev = DEVICE_DT_GET(DT_BUS(DT_COMPAT_GET_ANY_STATUS_OKAY(nxp_wifi)));

static struct sd_card wm_g_sd;
static struct sdio_func g_sdio_funcs[8];

int sdio_drv_creg_read(int addr, int fn, uint32_t *resp)
{
    struct sdio_func *func = &g_sdio_funcs[fn];

    if (sdio_read_byte(func, addr, (uint8_t *)resp) != 0)
    {
        return 0;
    }

    return 1;
}

int sdio_drv_creg_write(int addr, int fn, uint8_t data, uint32_t *resp)
{
    struct sdio_func *func = &g_sdio_funcs[fn];

    if (sdio_rw_byte(func, addr, data, (uint8_t *)resp) != 0)
    {
        return 0;
    }

    return 1;
}

int sdio_drv_read(uint32_t addr, uint32_t fn, uint32_t bcnt, uint32_t bsize, uint8_t *buf, uint32_t *resp)
{
    struct sdio_func *func = &g_sdio_funcs[fn];

    if (sdio_read_addr(func, addr, buf, bcnt * bsize) != 0)
    {
        return 0;
    }

    return 1;
}

int sdio_drv_write(uint32_t addr, uint32_t fn, uint32_t bcnt, uint32_t bsize, uint8_t *buf, uint32_t *resp)
{
    struct sdio_func *func = &g_sdio_funcs[fn];

    if (sdio_write_addr(func, addr, buf, bcnt * bsize) != 0)
    {
        return 0;
    }

    return 1;
}

extern void handle_cdint(int error);

void sdio_irq_handler(const struct device *dev, int reason, const void *user_data)
{
    if (reason == SDHC_INT_SDIO)
    {
        sdhc_disable_interrupt(sdhc_dev, SDHC_INT_SDIO);
        handle_cdint(0);
    }
}

void sdio_enable_interrupt(void)
{
    sdhc_enable_interrupt(sdhc_dev, (sdhc_interrupt_cb_t)sdio_irq_handler, SDHC_INT_SDIO, NULL);
    return;
}

struct wifi_gpio_config
{
#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), pdn_gpios)
    const struct gpio_dt_spec pdn;
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), wl_rst_gpios)
    const struct gpio_dt_spec wl_rst;
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), bt_rst_gpios)
    const struct gpio_dt_spec bt_rst;
#endif
};

static const struct wifi_gpio_config wifi_gpio = {
#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), pdn_gpios)
    .pdn = GPIO_DT_SPEC_GET(DT_NODELABEL(wifi), pdn_gpios),
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), wl_rst_gpios)
    .wl_rst = GPIO_DT_SPEC_GET(DT_NODELABEL(wifi), wl_rst_gpios),
#endif
#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), bt_rst_gpios)
    .bt_rst = GPIO_DT_SPEC_GET(DT_NODELABEL(wifi), bt_rst_gpios),
#endif
};

void BOARD_WIFI_BT_Enable(bool enable)
{
    if (enable)
    {
#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), pdn_gpios)
        gpio_pin_set_dt(&wifi_gpio.pdn, 1);
        k_msleep(100);
#endif

#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), wl_rst_gpios)
        gpio_pin_set_dt(&wifi_gpio.wl_rst, 1);
#endif

#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), bt_rst_gpios)
        gpio_pin_set_dt(&wifi_gpio.bt_rst, 1);
#endif

        k_msleep(100);
    }
    else
    {
#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), wl_rst_gpios)
        gpio_pin_set_dt(&wifi_gpio.wl_rst, 0);
#endif

#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), bt_rst_gpios)
        gpio_pin_set_dt(&wifi_gpio.bt_rst, 0);
#endif

        k_msleep(10);

#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), pdn_gpios)
        gpio_pin_set_dt(&wifi_gpio.pdn, 0);
#endif

        k_msleep(100);
    }
}

static void sdio_controller_init(void)
{
    (void)memset(&wm_g_sd, 0, sizeof(struct sd_card));

#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), wl_rst_gpios)
    if (gpio_pin_configure_dt(&wifi_gpio.wl_rst, GPIO_OUTPUT) < 0)
    {
        sdio_e("Failed to configure WiFi reset pin");
    }
#endif

#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), pdn_gpios)
    if (gpio_pin_configure_dt(&wifi_gpio.pdn, GPIO_OUTPUT) < 0)
    {
        sdio_e("Failed to configure power down pin");
    }
#endif

#if DT_NODE_HAS_PROP(DT_NODELABEL(wifi), bt_rst_gpios)
    if (gpio_pin_configure_dt(&wifi_gpio.bt_rst, GPIO_OUTPUT) < 0)
    {
        sdio_e("Failed to configure BT reset pin");
    }
#endif

    BOARD_WIFI_BT_Enable(false);
}

static int sdio_card_init(void)
{
    int ret = WM_SUCCESS;
    uint32_t resp;

    BOARD_WIFI_BT_Enable(true);

    if (!device_is_ready(sdhc_dev))
    {
        sdio_e("SD controller not ready");
        return -EIO;
    }

    if (!sdhc_card_present(sdhc_dev))
    {
        sdio_e("SDIO card not present");
        return -EIO;
    }

    ret = sd_init(sdhc_dev, &wm_g_sd);
    if (ret)
    {
        return ret;
    }

    memcpy(&g_sdio_funcs[0], &wm_g_sd.func0, sizeof(struct sdio_func));
    (void)sdio_drv_creg_read(0x0, 0, &resp);

    sdio_d("Card Version - (0x%x)", resp & 0xff);
    /* Init SDIO functions */
    sdio_init_func(&wm_g_sd, &g_sdio_funcs[1], SDIO_FUNC_NUM_1);
    sdio_init_func(&wm_g_sd, &g_sdio_funcs[2], SDIO_FUNC_NUM_2);

    /* Mask interrupts in card */
    (void)sdio_drv_creg_write(0x4, 0, 0x3, &resp);
    /* Enable IO in card */
    (void)sdio_drv_creg_write(0x2, 0, 0x2, &resp);

    (void)sdio_set_block_size(&g_sdio_funcs[0], 256);
    (void)sdio_set_block_size(&g_sdio_funcs[1], 256);
    (void)sdio_set_block_size(&g_sdio_funcs[2], 256);

    return ret;
}

int sdio_drv_init(void (*cd_int)(int))
{
    sdio_controller_init();

    if (sdio_card_init() != WM_SUCCESS)
    {
        sdio_e("Card initialization failed");
        return -WM_FAIL;
    }
    else
    {
        sdio_d("Card initialization successful");
    }

    return WM_SUCCESS;
}

void sdio_drv_deinit(void)
{
    // SDIO_Deinit(&wm_g_sd);
}
