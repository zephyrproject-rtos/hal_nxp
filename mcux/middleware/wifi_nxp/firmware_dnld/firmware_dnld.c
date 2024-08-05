/** @file firmware_load.c
 *
 *  @brief  This file provides firmware download related API
 *
 *  Copyright 2021-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#if (CONFIG_XZ_DECOMPRESSION)
#include <xz.h>
#include <decompress.h>
#endif /* CONFIG_XZ_DECOMPRESSION */

#include <wmlog.h>
/* Additional WMSDK header files */
#include "type_decls.h"
#include "firmware_dnld.h"
#include "fwdnld_intf_abs.h"

static const uint8_t *conn_fw;

/* remove this after mlan integration complete */
enum
{
    FWDNLD_STATUS_FAILURE = 0xffffffff,
    FWDNLD_STATUS_SUCCESS = 0,
    FWDNLD_STATUS_SKIP,
    FWDNLD_CARD_NOT_DETECTED = 3,
    FWDNLD_STATUS_FW_DNLD_FAILED,
    FWDNLD_STATUS_FW_NOT_DETECTED = 5,
    FWDNLD_STATUS_FW_NOT_READY,
    FWDNLD_STATUS_FW_XZ_FAILED,
    FWDNLD_CARD_CMD_TIMEOUT
};

static int32_t conn_download_normal_fw(const t_u8 *connfw_dl, t_u32 firmwarelen, fwdnld_intf_t *intf)
{
    t_u32 offset        = 0;
    int32_t ret         = FWDNLD_STATUS_FAILURE;
    t_u32 remaining_len = firmwarelen;
    uint32_t len        = 0;

    if (firmwarelen <= 0)
    {
        return ret;
    }

    if (intf->intf_s.fwdnld_intf_send)
    {
        ret = intf->intf_s.fwdnld_intf_send(intf, (const void *)(connfw_dl + offset), remaining_len, &len);
    }

    return ret;
}

#if (CONFIG_XZ_DECOMPRESSION)
int32_t conn_download_decomp_fw(t_u8 *wlanfw_xz, t_u32 firmwarelen, t_u32 ioport)
{
    t_u32 tx_blocks = 0, txlen = 0, buflen = 0;
    t_u16 len    = 0;
    t_u32 offset = 0;
    t_u32 tries  = 0;
    uint32_t resp;
    uint32_t outbuf_len;
    uint8_t *loutbuf = NULL :

        loutbuf = wifi_get_sdio_outbuf(&outbuf_len);
    (void)memset(loutbuf, 0, outbuf_len);

#define SBUF_SIZE 2048
    int ret;
    struct xz_buf stream;
    uint32_t retlen, readlen = 0;
#if !CONFIG_MEM_POOLS
    t_u8 *sbuf = (t_u8 *)OSA_MemoryAllocate(SBUF_SIZE);
#else
    t_u8 *sbuf = (t_u8 *)OSA_MemoryPoolAllocate(buf_2048_MemoryPool);
#endif
    if (sbuf == NULL)
    {
        fwdnld_io_e("Allocation failed");
        return FWDNLD_STATUS_FAILURE;
    }

    xz_uncompress_init(&stream, sbuf, loutbuf);

    do
    {
        /* Read CARD_STATUS_REG (0X30) FN =1 */
        for (tries = 0; tries < MAX_POLL_TRIES; tries++)
        {
            if (wlan_card_status(DN_LD_CARD_RDY | CARD_IO_READY) == true)
            {
                len = wlan_card_read_f1_base_regs();
            }
            else
            {
                fwdnld_io_e("Error in wlan_card_status()");
                break;
            }

            if (len)
                break;
        }

        if (!len)
        {
            fwdnld_io_e("Card timeout %s:%d", __func__, __LINE__);
            break;
        }
        else if (len > WLAN_UPLD_SIZE)
        {
            fwdnld_io_e("FW Download Failure. Invalid len");
            xz_uncompress_end();
#if !CONFIG_MEM_POOLS
            OSA_MemoryFree(sbuf);
#else
            OSA_MemoryPoolFree(buf_2048_MemoryPool, sbuf);
#endif
            return FWDNLD_STATUS_FW_DNLD_FAILED;
        }

        txlen = len;

        do
        {
            if (stream.in_pos == stream.in_size)
            {
                readlen = MIN(SBUF_SIZE, firmwarelen);
                (void)memcpy((void *)sbuf, (const void *)(wlanfw_xz + offset), readlen);
                offset += readlen;
                firmwarelen -= readlen;
            }
            ret = xz_uncompress_stream(&stream, sbuf, readlen, loutbuf, txlen, &retlen);

            if (ret == XZ_STREAM_END)
            {
                txlen = retlen;
                break;
            }
            else if (ret != XZ_OK)
            {
                fwdnld_io_e("Decompression failed:%d", ret);
                break;
            }
        } while (retlen == 0);

        calculate_sdio_write_params(txlen, &tx_blocks, &buflen);

        sdio_drv_write(ioport, 1, tx_blocks, buflen, (t_u8 *)loutbuf, &resp);

        if (ret == XZ_STREAM_END)
        {
            fwdnld_io_d("Decompression successful");
            break;
        }
        else if (ret != XZ_OK)
        {
            fwdnld_io_e("Exit:%d", ret);
            break;
        }
        len = 0;
    } while (1);

    xz_uncompress_end();
#if !CONFIG_MEM_POOLS
    OSA_MemoryFree(sbuf);
#else
    OSA_MemoryPoolFree(buf_2048_MemoryPool, sbuf);
#endif

    if (ret == XZ_OK || ret == XZ_STREAM_END)
        return FWDNLD_STATUS_SUCCESS;
    else
        return FWDNLD_STATUS_FW_XZ_FAILED;
}

#endif /* CONFIG_XZ_DECOMPRESSION */

/*
 * Download firmware to the card through SDIO.
 * The firmware is stored in Flash.
 * in param intf returned from the interface init
 */
int32_t firmware_download(const uint8_t *fw_start_addr, const size_t size, void *interface, uint8_t fw_reload)
{
    t_u32 firmwarelen;
    int32_t ret         = FWDNLD_STATUS_SUCCESS;
    fwdnld_intf_t *intf = (fwdnld_intf_t *)interface;

    if (size == 0)
    {
        return ret;
    }

    if (intf->intf_s.fwdnld_intf_prepare)
    {
        ret = intf->intf_s.fwdnld_intf_prepare(intf, NULL);
        if (ret != FWDNLD_STATUS_SUCCESS)
        {
            return ret;
        }
    }

#if (CONFIG_WIFI_IND_DNLD)
    if ((fw_reload != 0) && (intf->intf_s.fwdnld_intf_check_reload))
    {
        ret = intf->intf_s.fwdnld_intf_check_reload(intf, fw_reload);
        if (ret != FWDNLD_STATUS_SUCCESS)
        {
            return ret;
        }
    }
#endif

    conn_fw = fw_start_addr;

    fwdnld_io_d("Start copying connectivity firmware from 0x%x", (t_u32)conn_fw);

    firmwarelen = size;
    /*Making this section as #if 00 for now, as the decopress and
     * verification of compression etc funcitons are not present*/
#if (CONFIG_XZ_DECOMPRESSION)
    t_u8 buffer[6];

    (void)memcpy((void *)buffer, (const void *)conn_fw, sizeof(buffer));

    /* See if image is XZ compressed or not */
    if (verify_xz_header(buffer) == WM_SUCCESS)
    {
        fwdnld_io_d(
            "XZ Compressed image found, start decompression,"
            " len: %d",
            firmwarelen);
        ret = conn_download_decomp_fw(conn_fw, firmwarelen, ioport_g);
    }
    else
#endif /* CONFIG_XZ_DECOMPRESSION */
    {
        fwdnld_io_d(
            "Un-compressed image found, start download,"
            " len: %d",
            firmwarelen);
        ret = conn_download_normal_fw(conn_fw, firmwarelen, intf);
    }

    if (ret != FWDNLD_STATUS_SUCCESS)
    {
        return FWDNLD_STATUS_FAILURE;
    }
    if (intf->intf_s.fwdnld_intf_check_ready)
    {
        return intf->intf_s.fwdnld_intf_check_ready(intf, NULL);
    }
    return ret;
}
