/** @file fwdnld_sdio.c
 *
 *  @brief  This file provides interface abstraction APIs for SDIO
 *
 *  Copyright 2023-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include <string.h>
#include <osa.h>
#include "fwdnld_intf_abs.h"
#include "fwdnld_sdio.h"
#include "mlan_sdio_defs.h"
#include <mlan_sdio_api.h>
#include "sdio.h"

fwdnld_intf_t sdio_intf_g;
fwdnld_sdio_intf_specific sdio_intf_specific_g;

/*
 * FW dnld blocksize set 0x110 to 0 and 0x111 to 0x01 => 0x100 => 256
 * Note this only applies to the blockmode we use 256 bytes
 * as block because MLAN_SDIO_BLOCK_SIZE = 256
 */
static fwdnld_intf_ret_t wlan_set_fw_dnld_size(void)
{

    uint32_t resp;

    bool rv = sdio_drv_creg_write(FN1_BLOCK_SIZE_0, 0, 0, &resp);
    if (rv == false)
    {
        return FWDNLD_INTF_FAIL;
    }

    rv = sdio_drv_creg_write(FN1_BLOCK_SIZE_1, 0, 1, &resp);
    if (rv == false)
    {
        return FWDNLD_INTF_FAIL;
    }

    return FWDNLD_INTF_SUCCESS;
}

static void wlan_card_fw_status(t_u16 *dat)
{
    uint32_t resp = 0;

    (void)sdio_drv_creg_read(CARD_FW_STATUS0_REG, 1, &resp);
    *dat = (t_u16)(resp & 0xffU);
    (void)sdio_drv_creg_read(CARD_FW_STATUS1_REG, 1, &resp);
    *dat |= (t_u16)((resp & 0xffU) << 8);
}

static bool wlan_sdio_check_fw_status(t_u32 card_poll)
{
    t_u16 dat = 0U;
    t_u32 i   = 0U;

    for (i = 0; i < card_poll; i++)
    {
        (void)wlan_card_fw_status(&dat);
        if (dat == FIRMWARE_READY)
        {
            sdio_io_d("Firmware Ready");
            return true;
        }
        OSA_TimeDelay(5U);
    }
    return false;
}

#if CONFIG_WIFI_IND_DNLD

/**  @brief This function disables the host interrupts mask.
 *
 *  @param pmadapter    A pointer to mlan_adapter structure
 *  @param mask         the interrupt mask
 *  @return             MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
static int32_t wlan_sdio_disable_host_int_mask()
{
    uint32_t host_int_mask = 0;
    uint32_t resp;

    (void)sdio_drv_creg_read(HOST_INT_MASK_REG, 1, &host_int_mask);

    /* Update with the mask and write back to the register */
    host_int_mask &= ~HIM_DISABLE;

    (void)sdio_drv_creg_write(HOST_INT_MASK_REG, 1, host_int_mask, &resp);

    return FWDNLD_INTF_SUCCESS;
}

/**
 *  @brief This function probes the driver
 *
 *  @param pmadapter  A pointer to mlan_adapter structure
 *  @return           MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
static int32_t wlan_sdio_probe()
{
    int32_t ret            = FWDNLD_INTF_SUCCESS;
    uint32_t sdio_ireg     = 0;
    uint32_t host_int_mask = 0;
    uint32_t resp;

    /*
     * Read the HOST_INT_STATUS_REG for ACK the first interrupt got
     * from the bootloader. If we don't do this we get a interrupt
     * as soon as we register the irq.
     */
    (void)sdio_drv_creg_read(HOST_INT_STATUS_REG, 1, &sdio_ireg);

    (void)sdio_drv_creg_read(HOST_INT_MASK_REG, 1, &host_int_mask);

    /* Update with the mask and write back to the register */
    host_int_mask &= ~HIM_DISABLE;

    (void)sdio_drv_creg_write(HOST_INT_MASK_REG, 1, host_int_mask, &resp);

    /* Get SDIO ioport */
    ret = sdio_ioport_init();

    return ret;
}

int32_t wlan_reset_fw()
{
    t_u32 tries = 0;
    int32_t ret = FWDNLD_INTF_SUCCESS;
    bool rv;
    uint32_t resp = 1;

    //	wlan_pm_sdio_wakeup_card(pmadapter, MFALSE);

    rv = sdio_drv_creg_write(HOST_TO_CARD_EVENT_REG, 1, HOST_POWER_UP, &resp);
    if (rv == false)
    {
        return FWDNLD_INTF_FAIL;
    }

    /** wait SOC fully wake up */
    for (tries = 0; tries < MAX_POLL_TRIES; ++tries)
    {
        rv = sdio_drv_creg_write(CARD_FW_RESET_REG, 1, 0xba, &resp);
        if (rv == true)
        {
            (void)sdio_drv_creg_read(CARD_FW_RESET_REG, 1, &resp);

            if (resp == 0xba)
            {
                sdio_io_d("FW wake up");
                break;
            }
        }
        OSA_TimeDelay(5U);
    }
    /* Write register to notify FW */
    rv = sdio_drv_creg_write(CARD_FW_RESET_REG, 1, CARD_FW_RESET_VAL, &resp);
    if (rv == false)
    {
        sdio_io_d("Failed to write register.");
        ret = FWDNLD_INTF_FAIL;
        goto done;
    }
#if defined(SD8978) || defined(SD8987) || defined(SD9177) || defined(IW610)
    (void)sdio_drv_creg_read(HOST_TO_CARD_EVENT_REG, 1, &resp);
    rv = sdio_drv_creg_write(HOST_TO_CARD_EVENT_REG, 1, resp | 0x10, &resp);
    if (rv == false)
    {
        sdio_io_e("Failed to write register.");
        ret = FWDNLD_INTF_FAIL;
        goto done;
    }
#endif
    /* Poll register around 100 ms */
    for (tries = 0; tries < MAX_POLL_TRIES; ++tries)
    {
        (void)sdio_drv_creg_read(CARD_FW_RESET_REG, 1, &resp);
        if (resp == 0)
        {
            /* FW is ready */
            sdio_io_d("FW is ready");
            break;
        }
        OSA_TimeDelay(5U);
    }

    if (resp)
    {
        sdio_io_e("Failed to poll FW reset register %X=0x%x", CARD_FW_RESET_REG, resp);
        ret = FWDNLD_INTF_FAIL;
        goto done;
    }
    sdio_io_d("FW Reset success");
    ret = wlan_sdio_probe();
done:
    return ret;
}
#endif

static fwdnld_intf_ret_t sdio_prep_for_fwdnld(fwdnld_intf_t *intf, void *settings)
{
    /* set fw download block size */
    return wlan_set_fw_dnld_size();
}

static fwdnld_intf_ret_t sdio_post_fwdnld_check_conn_ready(fwdnld_intf_t *intf, void *settings)
{
    if (wlan_sdio_check_fw_status(1000) != true)
    {
        sdio_io_e("SDIO - FW Ready Registers not set");
        return FWDNLD_INTF_FAIL;
    }
    else
    {
        sdio_io_d("WLAN FW download Successful");
        return FWDNLD_INTF_SUCCESS;
    }
}

#if (CONFIG_WIFI_IND_DNLD)
static fwdnld_intf_ret_t sdio_fwdnld_check_reload(fwdnld_intf_t *intf, uint8_t fw_reload)
{
    t_u32 poll_num = 10;
    int32_t ret;

    /* Check if firmware is already running */
    ret = wlan_sdio_check_fw_status(poll_num);
    if (ret == true)
    {
        if (fw_reload == FW_RELOAD_SDIO_INBAND_RESET)
        {
            sdio_io_d("Try reset fw in mlan");
            ret = wlan_reset_fw();
            if (ret == FWDNLD_INTF_FAIL)
            {
                sdio_io_e("FW reset failure!");
                return FWDNLD_INTF_FAIL;
            }
        }
        else
        {
            PRINTF("WLAN FW already running! Skip FW download\r\n");
            PRINTF("FW download skipped because fly wire is not connected from MCU to Wi-Fi SoC\r\n");
            return FWDNLD_INTF_SKIP;
        }
    }
    else if (fw_reload == FW_RELOAD_NO_EMULATION)
    {
        ret = wlan_sdio_disable_host_int_mask();
    }

    return FWDNLD_INTF_SUCCESS;
}
#endif

static fwdnld_intf_ret_t sdio_interface_send(fwdnld_intf_t *intf,
                                             const uint8_t *buffer,
                                             uint32_t transfer_len,
                                             uint32_t *len)
{
    uint32_t tx_blocks = 0, txlen = 0, buflen = 0, offset = 0;
    uint32_t outbuf_len;
    uint8_t *loutbuf = NULL;
    uint32_t resp;
    uint32_t tries        = 0, ioport;
    fwdnld_intf_ret_t ret = FWDNLD_INTF_SUCCESS;

    loutbuf    = GET_INTF_OUTBUF(intf);
    outbuf_len = GET_INTF_OUTBUFLEN(intf);
    (void)memset(loutbuf, 0, outbuf_len);
    *len = 0;

    do
    {
        /* Read CARD_STATUS_REG (0X30) FN =1 */
        for (tries = 0; tries < MAX_POLL_TRIES; tries++)
        {
            if (wlan_card_status(DN_LD_CARD_RDY | CARD_IO_READY) == true)
            {
                *len = wlan_card_read_f1_base_regs();
            }
            else
            {
                sdio_io_e("Error in wlan_card_status()");
                break;
            }

            // (void)PRINTF("len %d =>\r\n", *len);
            if (*len != 0U)
            {
                break;
            }
            else if (offset > 0)
            {
                return FWDNLD_INTF_SUCCESS;
            }
            else
            { /* Do Nothing */
            }
        }

        if (*len == 0U)
        {
            if (offset > 0)
            {
                return FWDNLD_INTF_SUCCESS;
            }
            sdio_io_e("Card timeout %s:%d", __func__, __LINE__);
            return FWDNLD_INTF_FAIL;
        }
        else if (*len > outbuf_len)
        {
            sdio_io_e("FW Download Failure. Invalid len");
            return FWDNLD_INTF_FAIL;
        }
        else
        { /* Do Nothing */
        }

        txlen = *len;

        /* Set blocksize to transfer - checking for last block */
        if (transfer_len < txlen)
        {
            txlen = transfer_len;
            *len  = txlen;
        }

        ioport = GET_INTF_SDIO_IOPORT(intf);
        (void)memcpy((void *)loutbuf, (const void *)(buffer + offset), txlen);
        calculate_sdio_write_params(txlen, (unsigned int *)&tx_blocks, (unsigned int *)&buflen);
        (void)sdio_drv_write(ioport, 1, tx_blocks, buflen, (uint8_t *)loutbuf, &resp);

        if (*len <= transfer_len)
        {
            transfer_len -= *len;
            offset += *len;
        }
        else
        {
            ret = FWDNLD_INTF_FAIL;
            break;
        }
        *len = 0;

    } while (transfer_len > 0);

    return ret;
}

fwdnld_intf_t *sdio_init_interface(void *settings)
{
    int32_t ret;
    ret = sdio_init();
    if (ret != 0)
    {
        return NULL;
    }
    sdio_intf_g.intf_s.fwdnld_intf_send        = sdio_interface_send;
    sdio_intf_g.intf_s.fwdnld_intf_prepare     = sdio_prep_for_fwdnld;
    sdio_intf_g.intf_s.fwdnld_intf_check_ready = sdio_post_fwdnld_check_conn_ready;
#if (CONFIG_WIFI_IND_DNLD)
    sdio_intf_g.intf_s.fwdnld_intf_check_reload = sdio_fwdnld_check_reload;
#endif
    sdio_intf_g.intf_s.outbuf        = wifi_get_sdio_outbuf(&sdio_intf_g.intf_s.outbuf_len);
    sdio_intf_g.intf_s.intf_specific = &sdio_intf_specific_g;

    ret = sdio_ioport_init();
    if (ret != 0)
    {
        return NULL;
    }
    sdio_intf_specific_g.ioport = wifi_get_sdio_ioport();
    return &sdio_intf_g;
}
