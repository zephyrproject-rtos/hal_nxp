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
#include <mlan_sdio_defs.h>
#include <osa.h>
#include <zephyr/sd/sdio.h>

#define SDIO_CMD_TIMEOUT 2000

const struct device *sdhc_dev = DEVICE_DT_GET(DT_BUS(DT_COMPAT_GET_ANY_STATUS_OKAY(nxp_wifi)));

static struct sd_card wm_g_sd;
static struct sdio_func g_sdio_funcs[8];

int sdio_drv_creg_read(int addr, int fn, uint32_t *resp)
{
    struct sdio_func *func = &g_sdio_funcs[fn];
    uint8_t read_val = 0;

    if (sdio_read_byte(func, addr, &read_val) != 0)
    {
        return 0;
    }

    *resp = read_val;

    return 1;
}

int sdio_drv_creg_write(int addr, int fn, uint8_t data, uint32_t *resp)
{
    struct sdio_func *func = &g_sdio_funcs[fn];
    uint8_t read_val = 0;

    if (sdio_rw_byte(func, addr, data, &read_val) != 0)
    {
        return 0;
    }

    *resp = read_val;

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
    uint32_t sd_retry = 0;
    uint32_t sd_status = 0;

retry:
    if (sdio_write_addr(func, addr, buf, bcnt * bsize) != 0)
    {
        /* issue abort cmd52 command through Fn0 */
        (void)sdio_drv_creg_write(IO_ABORT, 0, 0x01, &sd_status);
        /* issue terminate CMD53 */
        (void)sdio_drv_creg_write(HOST_TO_CARD_EVENT_REG, 1, HOST_TERM_CMD53, &sd_status);

        if (sd_retry < MAX_WRITE_IOMEM_RETRY)
        {
            sd_retry++;
            goto retry;
        }
        return 0;
    }

    return 1;
}

#if CONFIG_TX_RX_ZERO_COPY
static void *sg_to_net_buf(void *sg_list)
{
    sg_dma_list_t *head = (sg_dma_list_t *)sg_list;
    sg_dma_list_t *node = head;
    sg_dma_list_t *next = NULL;

    while (node != NULL)
    {
        next = node->dataList;

        node->buf.data = (uint8_t *)(void *)node->dataAddr;
        node->buf.len = node->dataSize;
        if (next != NULL)
        {
            node->buf.frags = &next->buf;
        }
        else
        {
            node->buf.frags = NULL;
        }

        node = next;
    }

    return (void *)&head->buf;
}

static int sdio_drv_request_sg(uint32_t reg_addr,
                               uint32_t func,
                               uint32_t blocks,
                               uint32_t block_size,
                               void *buf,
                               int direction)
{
    int ret;
    struct sdhc_command cmd = {0};
    struct sdhc_data data = {0};

    ret = k_mutex_lock(&wm_g_sd.lock, K_MSEC(CONFIG_SD_DATA_TIMEOUT));
    if (ret)
    {
        sdio_e("cannot get card lock");
        return -1;
    }

    cmd.opcode = SDIO_RW_EXTENDED;
    cmd.arg = (func << SDIO_CMD_ARG_FUNC_NUM_SHIFT) |
        ((reg_addr & SDIO_CMD_ARG_REG_ADDR_MASK) << SDIO_CMD_ARG_REG_ADDR_SHIFT);
    cmd.arg |= (direction == SDIO_IO_WRITE) ? BIT(SDIO_CMD_ARG_RW_SHIFT) : 0;
    cmd.arg |= BIT(SDIO_EXTEND_CMD_ARG_OP_CODE_SHIFT);
    cmd.response_type = (SD_RSP_TYPE_R5 | SD_SPI_RSP_TYPE_R5);
    cmd.timeout_ms = CONFIG_SD_CMD_TIMEOUT;
    cmd.arg |= BIT(SDIO_EXTEND_CMD_ARG_BLK_SHIFT) | blocks;

    data.block_size = block_size;
    data.blocks = blocks;
    data.data = buf;
    data.timeout_ms = CONFIG_SD_DATA_TIMEOUT;
    data.is_sg_data = true;

    ret = sdhc_request(sdhc_dev, &cmd, &data);
    (void)k_mutex_unlock(&wm_g_sd.lock);
    return ret;
}

int sdio_drv_read_sg(uint32_t addr, uint32_t fn, uint32_t bcnt, uint32_t bsize, void *sg_list)
{
    struct net_buf *buf;

    buf = sg_to_net_buf(sg_list);
    if (!buf)
    {
        return 0;
    }

    if (sdio_drv_request_sg(addr, fn, bcnt, bsize, (void *)buf, SDIO_IO_READ) != 0)
    {
        return 0;
    }

    return 1;
}

int sdio_drv_write_sg(uint32_t addr, uint32_t fn, uint32_t bcnt, uint32_t bsize, void *sg_list)
{
    uint32_t sd_retry = 0;
    uint32_t sd_status = 0;
    struct net_buf *buf;

    buf = sg_to_net_buf(sg_list);
    if (!buf)
    {
        return 0;
    }

retry:
    if (sdio_drv_request_sg(addr, fn, bcnt, bsize, (void *)buf, SDIO_IO_WRITE) != 0)
    {
        /* issue abort cmd52 command through Fn0 */
        (void)sdio_drv_creg_write(IO_ABORT, 0, 0x01, &sd_status);
        /* issue terminate CMD53 */
        (void)sdio_drv_creg_write(HOST_TO_CARD_EVENT_REG, 1, HOST_TERM_CMD53, &sd_status);

        if (sd_retry < MAX_WRITE_IOMEM_RETRY)
        {
            sd_retry++;
            goto retry;
        }
        return 0;
    }

    return 1;
}
#endif

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

void sdio_disable_interrupt(void)
{
    sdhc_disable_interrupt(sdhc_dev, SDHC_INT_SDIO);
    return;
}

static void sdio_controller_init(void)
{
    (void)memset(&wm_g_sd, 0, sizeof(struct sd_card));
}

static int sdio_card_init(void)
{
    int ret = WM_SUCCESS;
    uint32_t resp;

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

#if defined(IW610)
    (void)sdio_set_block_size(&g_sdio_funcs[0], 1);
#else
    (void)sdio_set_block_size(&g_sdio_funcs[0], 256);
#endif
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
