/** @file mlan_txrx.c
 *
 *  @brief  This file provides the handling of TX/RX in MLAN
 *
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*************************************************************
Change Log:
    05/11/2009: initial version
************************************************************/
#include <mlan_api.h>

/* Additional WMSDK header files */
#include <wmerrno.h>
#include <osa.h>
#if CONFIG_WIFI_PKT_FWD
#include <wm_net.h>
#if defined(RW610)
#include "wifi-imu.h"
#else
#include "wifi-sdio.h"
#endif
#endif
/* Always keep this include at the end of all include files */
#include <mlan_remap_mem_operations.h>
/********************************************************
                Local Variables
********************************************************/

/********************************************************
                Global Variables
********************************************************/

/********************************************************
                Local Functions
********************************************************/

/********************************************************
                Global Functions
********************************************************/
/**
 *   @brief This function processes the received buffer
 *
 *   @param pmadapter A pointer to mlan_adapter
 *   @param pmbuf     A pointer to the received buffer
 *
 *   @return        MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
mlan_status wlan_handle_rx_packet(pmlan_adapter pmadapter, pmlan_buffer pmbuf)
{
    mlan_status ret    = MLAN_STATUS_SUCCESS;
    pmlan_private priv = wlan_get_priv(pmadapter, MLAN_BSS_ROLE_ANY);
    RxPD *prx_pd;
#ifdef DEBUG_LEVEL1
    t_u32 sec, usec;
#endif

    ENTER();

    prx_pd = (RxPD *)(void *)(pmbuf->pbuf + pmbuf->data_offset);
    /* Get the BSS number from RxPD, get corresponding priv */
    priv = wlan_get_priv_by_id(pmadapter, prx_pd->bss_num & BSS_NUM_MASK, prx_pd->bss_type);
    if (priv == MNULL)
    {
        priv = wlan_get_priv(pmadapter, MLAN_BSS_ROLE_ANY);
    }
    pmbuf->bss_index = priv->bss_index;
    PRINTM_GET_SYS_TIME(MDATA, &sec, &usec);
    PRINTM_NETINTF(MDATA, priv);
    /* PRINTM(MDATA, "%lu.%06lu : Data <= FW\n", sec, usec); */
    ret = priv->ops.process_rx_packet(pmadapter, pmbuf);

    LEAVE();
    return ret;
}

#if CONFIG_WIFI_PKT_FWD
/**
 *  @brief This function processes received packet and forwards it
 *  		to kernel/upper layer or send back to firmware
 *
 *  @param priv A pointer to mlan_private
 *  @param pmbuf     A pointer to mlan_buffer which includes the received packet
 *
 *  @return 	   MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
mlan_status wlan_process_uap_rx_packet(mlan_private *priv, pmlan_buffer pmbuf)
{
    mlan_status ret = MLAN_STATUS_SUCCESS;
    pmlan_adapter pmadapter = priv->adapter;
    RxPacketHdr_t *prx_pkt = (RxPacketHdr_t *)pmbuf->pdesc;
    RxPD *prx_pd = (RxPD *)(void *)(pmbuf->pbuf + pmbuf->data_offset);

    /* Don't do packet forwarding in disconnected state */
    if (priv->media_connected == MFALSE)
        goto upload;

    if (prx_pkt->eth803_hdr.dest_addr[0] & 0x01)
    {
        /* Allocate new buffer here, to avoid the conflict between
         * driver handling and TCP/IP stack handling */
        void *pkt = (void *)gen_tx_pkt_from_data(priv->bss_type,
                net_stack_buffer_get_payload(pmbuf->lwip_pbuf), prx_pd->rx_pkt_length);
        if (pkt == NULL)
        {
            /* Allocate TX buffer failed, directly upload the packet to TCP/IP stack */
            goto upload;
        }

        net_wifi_packet_send(WLAN_BSS_TYPE_UAP, pkt);
        net_stack_buffer_free(pkt);
    }
    else
    {
        if (wlan_11n_get_txbastream_tbl(priv, prx_pkt->eth803_hdr.dest_addr))
        {
            int iret = net_wifi_packet_send(WLAN_BSS_TYPE_UAP, pmbuf->lwip_pbuf);
            if (iret != WM_SUCCESS)
            {
                ret = MLAN_STATUS_FAILURE;
            }
            net_stack_buffer_free(pmbuf->lwip_pbuf);
#if !(CONFIG_TX_RX_ZERO_COPY) && !(FSL_USDHC_ENABLE_SCATTER_GATHER_TRANSFER)
#if !CONFIG_MEM_POOLS
            /* Free RxPD */
            OSA_MemoryFree(pmbuf->pbuf);
            OSA_MemoryFree(pmbuf);
#else
            OSA_MemoryPoolFree(buf_128_MemoryPool, pmbuf->pbuf);
            OSA_MemoryPoolFree(buf_128_MemoryPool, pmbuf);
#endif
#endif
            return ret;
        }
    }

upload:
    ret = pmadapter->callbacks.moal_recv_packet(pmadapter->pmoal_handle, pmbuf);
    if (ret == MLAN_STATUS_FAILURE)
    {
        pmbuf->status_code = (t_u32)MLAN_ERROR_PKT_INVALID;
        PRINTM(MERROR, "uAP Rx Error: moal_recv_packet returned error\n");
    }

    if (ret != MLAN_STATUS_PENDING)
    {
        wlan_free_mlan_buffer(pmadapter, pmbuf);
    }

    LEAVE();
    return ret;
}
#endif
