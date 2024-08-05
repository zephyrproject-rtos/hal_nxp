/** @file mlan_init.c
 *
 *  @brief  This file provides initialization for FW and HW
 *
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/********************************************************
Change log:
    10/13/2008: initial version
********************************************************/

#include <mlan_api.h>

/* Additional WMSDK header files */
#include <wmerrno.h>
#include <osa.h>
#include "fsl_common.h"

/* Always keep this include at the end of all include files */
#include <mlan_remap_mem_operations.h>
/********************************************************
        Global Variables
********************************************************/

#define BOARD_SDMMC_DATA_BUFFER_ALIGN_SIZE 32

//_IOBUFS_ALIGNED(SDIO_DMA_ALIGNMENT)
#if defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177)
static t_u8 mp_regs_buffer[MAX_MP_REGS + DMA_ALIGNMENT];
#elif defined(SD8801)
SDK_ALIGN(uint8_t mp_regs_buffer[MAX_MP_REGS], BOARD_SDMMC_DATA_BUFFER_ALIGN_SIZE);
#endif

/* We are allocating BSS list globally as we need heap for other purposes */
SDK_ALIGN(BSSDescriptor_t BSS_List[MRVDRV_MAX_BSSID_LIST], 32);

#if CONFIG_SCAN_CHANNEL_GAP

#if !CONFIG_5GHz_SUPPORT
static ChanStatistics_t Chan_Stats[14];
#else
static ChanStatistics_t Chan_Stats[48];
#endif

#endif

/********************************************************
        Local Functions
********************************************************/

#if !CONFIG_MLAN_WMSDK
/**
 *  @brief This function adds a BSS priority table
 *
 *  @param priv		A pointer to mlan_private structure
 *
 *  @return		MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
static mlan_status wlan_add_bsspriotbl(pmlan_private priv)
{
    pmlan_adapter pmadapter     = priv->adapter;
    mlan_bssprio_node *pbssprio = MNULL;
    mlan_status status          = MLAN_STATUS_SUCCESS;

    ENTER();

    if ((status = pmadapter->callbacks.moal_malloc(pmadapter->pmoal_handle, sizeof(mlan_bssprio_node), MLAN_MEM_DEF,
                                                   (t_u8 **)&pbssprio)))
    {
        PRINTM(MERROR, "Failed to allocate bsspriotbl\n");
        LEAVE();
        return status;
    }

    pbssprio->priv = priv;

    util_init_list((pmlan_linked_list)pbssprio);

    if (!pmadapter->bssprio_tbl[priv->bss_priority].bssprio_cur)
        pmadapter->bssprio_tbl[priv->bss_priority].bssprio_cur = pbssprio;

    util_enqueue_list_tail(pmadapter->pmoal_handle, &pmadapter->bssprio_tbl[priv->bss_priority].bssprio_head,
                           (pmlan_linked_list)pbssprio, pmadapter->callbacks.moal_spin_lock,
                           pmadapter->callbacks.moal_spin_unlock);

    LEAVE();
    return status;
}

/**
 *  @brief This function deletes the BSS priority table
 *
 *  @param priv		A pointer to mlan_private structure
 *
 *  @return		N/A
 */
static t_void wlan_delete_bsspriotbl(pmlan_private priv)
{
    int i;
    pmlan_adapter pmadapter          = priv->adapter;
    mlan_bssprio_node *pbssprio_node = MNULL, *ptmp_node = MNULL, **ppcur = MNULL;
    pmlan_list_head phead;

    ENTER();

    for (i = 0; i < pmadapter->priv_num; ++i)
    {
        phead = &pmadapter->bssprio_tbl[i].bssprio_head;
        ppcur = &pmadapter->bssprio_tbl[i].bssprio_cur;
        PRINTM(MINFO, "Delete BSS priority table, index = %d, i = %d, phead = %p, pcur = %p\n", priv->bss_index, i,
               phead, *ppcur);
        if (*ppcur)
        {
            pbssprio_node =
                (mlan_bssprio_node *)util_peek_list(pmadapter->pmoal_handle, phead, pmadapter->callbacks.moal_spin_lock,
                                                    pmadapter->callbacks.moal_spin_unlock);
            while (pbssprio_node && ((pmlan_list_head)pbssprio_node != phead))
            {
                ptmp_node = pbssprio_node->pnext;
                if (pbssprio_node->priv == priv)
                {
                    PRINTM(MINFO, "Delete node, pnode = %p, pnext = %p\n", pbssprio_node, ptmp_node);
                    util_unlink_list(pmadapter->pmoal_handle, phead, (pmlan_linked_list)pbssprio_node,
                                     pmadapter->callbacks.moal_spin_lock, pmadapter->callbacks.moal_spin_unlock);
                    pmadapter->callbacks.moal_mfree(pmadapter->pmoal_handle, (t_u8 *)pbssprio_node);
                }
                pbssprio_node = ptmp_node;
            }
            *ppcur = (mlan_bssprio_node *)phead;
        }
    }

    LEAVE();
}
#endif /* CONFIG_MLAN_WMSDK */
/********************************************************
        Global Functions
********************************************************/

/**
 *  @brief This function allocates buffer for the members of adapter
 *  		structure like command buffer and BSSID list.
 *
 *  @param pmadapter A pointer to mlan_adapter structure
 *
 *  @return        MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
mlan_status wlan_allocate_adapter(pmlan_adapter pmadapter)
{
#if !CONFIG_MLAN_WMSDK
    mlan_status ret = MLAN_STATUS_SUCCESS;
#ifdef STA_SUPPORT
    BSSDescriptor_t *ptemp_scan_table = MNULL;
#endif

    ENTER();

#ifdef STA_SUPPORT
    /* Allocate buffer to store the BSSID list */
    buf_size = sizeof(BSSDescriptor_t) * MRVDRV_MAX_BSSID_LIST;
    ret = pmadapter->callbacks.moal_malloc(pmadapter->pmoal_handle, buf_size, MLAN_MEM_DEF, (t_u8 **)&ptemp_scan_table);
    if (ret != MLAN_STATUS_SUCCESS || !ptemp_scan_table)
    {
        PRINTM(MERROR, "Failed to allocate scan table\n");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }
    pmadapter->pscan_table             = ptemp_scan_table;
    pmadapter->blacklist_bss.num_bssid = 0;
    memset(MNULL, pmadapter->blacklist_bss.bssids, 0x0, sizeof(pmadapter->blacklist_bss.bssids));
    ret = pmadapter->callbacks.moal_malloc(pmadapter->pmoal_handle, DEFAULT_SCAN_BEACON_BUFFER, MLAN_MEM_DEF,
                                           (t_u8 **)&pmadapter->bcn_buf);
    if (ret != MLAN_STATUS_SUCCESS || !pmadapter->bcn_buf)
    {
        PRINTM(MERROR, "Failed to allocate bcn buf\n");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }
    pmadapter->bcn_buf_size = DEFAULT_SCAN_BEACON_BUFFER;
#endif
#endif /* CONFIG_MLAN_WMSDK */
    (void)__memset(MNULL, &BSS_List, 0x00, sizeof(BSS_List));

    pmadapter->pscan_table = BSS_List;
#if CONFIG_SCAN_CHANNEL_GAP

#if !CONFIG_5GHz_SUPPORT
    pmadapter->num_in_chan_stats = 14;
#else
    pmadapter->num_in_chan_stats = 48;
#endif
    pmadapter->pchan_stats = Chan_Stats;
#endif

#if !CONFIG_MLAN_WMSDK
    /* Allocate command buffer */
    ret = wlan_alloc_cmd_buffer(pmadapter);
    if (ret != MLAN_STATUS_SUCCESS)
    {
        PRINTM(MERROR, "Failed to allocate command buffer\n");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }

    ret = pmadapter->callbacks.moal_malloc(pmadapter->pmoal_handle, MAX_MP_REGS + DMA_ALIGNMENT,
                                           MLAN_MEM_DEF | MLAN_MEM_DMA, (t_u8 **)&pmadapter->mp_regs_buf);
    if (ret != MLAN_STATUS_SUCCESS || !pmadapter->mp_regs_buf)
    {
        PRINTM(MERROR, "Failed to allocate mp_regs_buf\n");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }
    pmadapter->mp_regs = (t_u8 *)ALIGN_ADDR(pmadapter->mp_regs_buf, DMA_ALIGNMENT);
#endif /* CONFIG_MLAN_WMSDK */
       /* wmsdk: Use a statically allocated DMA aligned buffer */
#if defined(SD8801)
    pmadapter->mp_regs = mp_regs_buffer;
#elif defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177)
    pmadapter->mp_regs = (t_u8 *)ALIGN_ADDR(mp_regs_buffer, DMA_ALIGNMENT);
// mp_regs_buffer;
#endif

#if !CONFIG_MLAN_WMSDK
#if defined(SDIO_MULTI_PORT_TX_AGGR) || defined(SDIO_MULTI_PORT_RX_AGGR)
    ret = wlan_alloc_sdio_mpa_buffers(pmadapter, SDIO_MP_TX_AGGR_DEF_BUF_SIZE, SDIO_MP_RX_AGGR_DEF_BUF_SIZE);
    if (ret != MLAN_STATUS_SUCCESS)
    {
        PRINTM(MERROR, "Failed to allocate sdio mp-a buffers\n");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }
#endif

    pmadapter->psleep_cfm = wlan_alloc_mlan_buffer(pmadapter, sizeof(opt_sleep_confirm_buffer), 0, MTRUE);

    LEAVE();
#endif /* CONFIG_MLAN_WMSDK */
    return MLAN_STATUS_SUCCESS;
}

void wlan_clear_scan_bss(void)
{
#if CONFIG_WPA_SUPP
    BSSDescriptor_t *bss_entry = NULL;
    int i;

    for (i = 0; i < mlan_adap->num_in_scan_table; i++)
    {
        bss_entry = &mlan_adap->pscan_table[i];
        if (bss_entry && bss_entry->ies != NULL)
        {
            OSA_MemoryFree(bss_entry->ies);
        }
    }
#endif
    (void)__memset(MNULL, &BSS_List, 0x00, sizeof(BSS_List));
}

/**
 *  @brief This function initializes the private structure
 *  		and sets default values to the members of mlan_private.
 *
 *  @param priv    A pointer to mlan_private structure
 *
 *  @return        MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
mlan_status wlan_init_priv(pmlan_private priv)
{
    t_u32 i;
    /* pmlan_adapter pmadapter = priv->adapter; */
    mlan_status ret = MLAN_STATUS_SUCCESS;

    ENTER();

    priv->media_connected = MFALSE;
    (void)__memset(pmadapter, priv->curr_addr, 0xff, MLAN_MAC_ADDR_LENGTH);

#ifdef STA_SUPPORT
    priv->pkt_tx_ctrl = 0;
    priv->bss_mode    = MLAN_BSS_MODE_INFRA;

    priv->data_rate         = 0; /* Initially indicate the rate as auto */
    priv->data_rate_index   = (t_s8)-1;
    priv->is_data_rate_auto = MTRUE;
    priv->bcn_avg_factor    = DEFAULT_BCN_AVG_FACTOR;
    priv->data_avg_factor   = DEFAULT_DATA_AVG_FACTOR;

    priv->sec_info.wep_status          = Wlan802_11WEPDisabled;
    priv->sec_info.authentication_mode = MLAN_AUTH_MODE_AUTO;
    priv->sec_info.encryption_mode     = MLAN_ENCRYPTION_MODE_NONE;
    for (i = 0; i < sizeof(priv->wep_key) / sizeof(priv->wep_key[0]); i++)
    {
        (void)__memset(pmadapter, &priv->wep_key[i], 0, sizeof(mrvl_wep_key_t));
    }
    priv->wep_key_curr_index = 0;
    priv->ewpa_query         = MFALSE;
    priv->adhoc_aes_enabled  = MFALSE;
    priv->curr_pkt_filter =
#if CONFIG_11AC
        HostCmd_ACT_MAC_STATIC_DYNAMIC_BW_ENABLE |
#endif
        HostCmd_ACT_MAC_RTS_CTS_ENABLE | HostCmd_ACT_MAC_RX_ON | HostCmd_ACT_MAC_TX_ON |
        HostCmd_ACT_MAC_ETHERNETII_ENABLE;

#if !CONFIG_MLAN_WMSDK
    priv->beacon_period       = MLAN_BEACON_INTERVAL;
    priv->pattempted_bss_desc = MNULL;
#endif /* CONFIG_MLAN_WMSDK */
#if CONFIG_GTK_REKEY_OFFLOAD
    (void)__memset(pmadapter, &priv->gtk_rekey, 0, sizeof(priv->gtk_rekey));
#endif
    (void)__memset(pmadapter, &priv->curr_bss_params, 0, sizeof(priv->curr_bss_params));
    priv->listen_interval = MLAN_DEFAULT_LISTEN_INTERVAL;
#if !CONFIG_MLAN_WMSDK
    (void)__memset(pmadapter, &priv->assoc_rsp_buf, 0, sizeof(priv->assoc_rsp_buf));
    priv->assoc_rsp_size = 0;
#endif /* CONFIG_MLAN_WMSDK */
    wlan_11d_priv_init(priv);
    wlan_11h_priv_init(priv);

#if defined(UAP_SUPPORT)
    priv->uap_bss_started = MFALSE;
    (void)__memset(pmadapter, &priv->uap_state_chan_cb, 0, sizeof(priv->uap_state_chan_cb));
#endif
#if defined(UAP_SUPPORT)
    priv->num_drop_pkts = 0;
#endif

#if !CONFIG_MLAN_WMSDK
#if defined(STA_SUPPORT)
    priv->adhoc_state_prev = ADHOC_IDLE;
    (void)__memset(pmadapter, &priv->adhoc_last_start_ssid, 0, sizeof(priv->adhoc_last_start_ssid));
#endif
    priv->adhoc_channel      = DEFAULT_AD_HOC_CHANNEL;
    priv->atim_window        = 0;
    priv->adhoc_state        = ADHOC_IDLE;
    priv->tx_power_level     = 0;
    priv->max_tx_power_level = 0;
    priv->min_tx_power_level = 0;
    priv->tx_rate            = 0;
#ifdef SD8801
    priv->rxpd_htinfo = 0;
#else
    priv->rxpd_rate_info = 0;
#endif
    priv->rxpd_rate      = 0;
    priv->rate_bitmap    = 0;
    priv->data_rssi_last = 0;
    priv->data_rssi_avg  = 0;
    priv->data_nf_avg    = 0;
    priv->data_nf_last   = 0;
    priv->bcn_rssi_last  = 0;
    priv->bcn_rssi_avg   = 0;
    priv->bcn_nf_avg     = 0;
    priv->bcn_nf_last    = 0;

    priv->sec_info.ewpa_enabled = MFALSE;
    priv->sec_info.wpa_enabled  = MFALSE;
    priv->sec_info.wpa2_enabled = MFALSE;
    (void)__memset(pmadapter, &priv->wpa_ie, 0, sizeof(priv->wpa_ie));
    (void)__memset(pmadapter, &priv->aes_key, 0, sizeof(priv->aes_key));
    priv->wpa_ie_len            = 0;
    priv->sec_info.wapi_enabled = MFALSE;
    priv->wapi_ie_len           = 0;
    priv->sec_info.wapi_key_on  = MFALSE;

    (void)__memset(pmadapter, &priv->wps, 0, sizeof(priv->wps));
    (void)__memset(pmadapter, &priv->gen_ie_buf, 0, sizeof(priv->gen_ie_buf));
    priv->gen_ie_buf_len = 0;
#endif /* CONFIG_MLAN_WMSDK */
    priv->wpa_is_gtk_set = MFALSE;
#endif /* STA_SUPPORT */

#ifdef RW610
    priv->tx_bf_cap = DEFAULT_11N_TX_BF_CAP;
#else
    priv->tx_bf_cap = 0;
#endif
    priv->wmm_required = MTRUE;
    priv->wmm_enabled  = MFALSE;
    priv->wmm_qosinfo  = 0;
#ifdef STA_SUPPORT
#if !CONFIG_MLAN_WMSDK
    priv->pcurr_bcn_buf = MNULL;
    priv->curr_bcn_size = 0;
#endif /* CONFIG_MLAN_WMSDK */
#endif /* STA_SUPPORT */
    priv->pmfcfg.mfpc = 0;
    priv->pmfcfg.mfpr = 0;

#if CONFIG_11K
    priv->enable_host_11k = (t_u8)MFALSE;
#endif
#if CONFIG_11K_OFFLOAD
    priv->enable_11k = (t_u8)MFALSE;
#endif
#if CONFIG_11K
    priv->neighbor_rep_token    = (t_u8)1U;
    priv->rrm_mgmt_bitmap_index = -1;
#endif
#if CONFIG_11V
    priv->bss_trans_query_token = (t_u8)1U;
#endif
    for (i = 0; i < MAX_NUM_TID; i++)
    {
        priv->addba_reject[i] = ADDBA_RSP_STATUS_ACCEPT;
    }
    priv->max_amsdu = 0;

    priv->scan_block = MFALSE;

    if (GET_BSS_ROLE(priv) == (unsigned)MLAN_BSS_ROLE_STA)
    {
        priv->port_ctrl_mode = MTRUE;
    }
    else
    {
        priv->port_ctrl_mode = MFALSE;
    }
    priv->port_open = MFALSE;
#if CONFIG_ROAMING
    priv->roaming_enabled = MFALSE;
#endif
#if !CONFIG_MLAN_WMSDK
    if (!ret)
    {
        ret = wlan_add_bsspriotbl(priv);
    }
#endif /* CONFIG_MLAN_WMSDK */

#ifdef UAP_SUPPORT
    priv->uap_bss_started = MFALSE;
    priv->uap_host_based  = MFALSE;
#endif

#if CONFIG_WPA_SUPP
    reset_ie_index();
    priv->default_scan_ies_len = 0;
    priv->probe_req_index      = -1;
#if CONFIG_WPA_SUPP_WPS
    priv->wps.wps_mgmt_bitmap_index = -1;
#endif
#if CONFIG_WPA_SUPP_AP
    priv->beacon_vendor_index = -1;
    priv->beacon_index        = 0;
    priv->proberesp_index     = 1;
    priv->assocresp_index     = 2;
    priv->beacon_wps_index    = 3;
#endif
#endif
#if CONFIG_TCP_ACK_ENH
    priv->enable_tcp_ack_enh = MTRUE;
#endif

#if CONFIG_WPA_SUPP_DPP
    priv->is_dpp_connect = MFALSE;
#endif

    LEAVE();
    return ret;
}

/**
 *  @brief This function initializes the adapter structure
 *  		and sets default values to the members of adapter.
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *
 *  @return		N/A
 */
t_void wlan_init_adapter(pmlan_adapter pmadapter)
{
#if !CONFIG_MLAN_WMSDK
    opt_sleep_confirm_buffer *sleep_cfm_buf = MNULL;

    ENTER();

    sleep_cfm_buf = (opt_sleep_confirm_buffer *)(pmadapter->psleep_cfm->pbuf + pmadapter->psleep_cfm->data_offset);
#endif /* CONFIG_MLAN_WMSDK */
#ifdef WIFI_CALIB_CMD_SUPPORT
    if (pmadapter->init_para.wifi_calib_mode == MLAN_INIT_PARA_DISABLED)
    {
        pmadapter->wifi_calib_mode = MFALSE;
    }
    else
    {
        pmadapter->wifi_calib_mode = pmadapter->init_para.wifi_calib_mode;
    }
#endif
#if !CONFIG_MLAN_WMSDK
    pmadapter->int_mode = pmadapter->init_para.int_mode;
    pmadapter->gpio_pin = pmadapter->init_para.gpio_pin;

#if defined(STA_SUPPORT)
    pmadapter->pwarm_reset_ioctl_req = MNULL;
#endif
    pmadapter->cmd_sent  = MFALSE;
    pmadapter->data_sent = MTRUE;
#endif /* CONFIG_MLAN_WMSDK */
    pmadapter->mp_rd_bitmap = 0;

    /*
     * wmsdk: fixme: Originally mp_wr_bitmap was set to 0. We have changed
     * it only for legacy reason. Please check it and restore on high
     * priority.
     */
    pmadapter->mp_wr_bitmap = 0;
#ifndef RW610
#if defined(SD8801)
    pmadapter->curr_rd_port = 1;
    pmadapter->curr_wr_port = 1;
#elif defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177)
    pmadapter->curr_rd_port      = 0;
    pmadapter->curr_wr_port      = 0;
#endif
    pmadapter->mp_data_port_mask = DATA_PORT_MASK;
#endif

#if !CONFIG_MLAN_WMSDK
#ifdef SDIO_MULTI_PORT_TX_AGGR
    pmadapter->mpa_tx.buf_len    = 0;
    pmadapter->mpa_tx.pkt_cnt    = 0;
    pmadapter->mpa_tx.start_port = 0;

    if (!pmadapter->init_para.mpa_tx_cfg)
    {
        pmadapter->mpa_tx.enabled = MFALSE;
    }
    else if (pmadapter->init_para.mpa_tx_cfg == MLAN_INIT_PARA_DISABLED)
    {
        pmadapter->mpa_tx.enabled = MFALSE;
    }
    else
    {
        pmadapter->mpa_tx.enabled = MTRUE;
    }
    pmadapter->mpa_tx.pkt_aggr_limit = SDIO_MP_AGGR_DEF_PKT_LIMIT;
#endif /* SDIO_MULTI_PORT_TX_AGGR */

#ifdef SDIO_MULTI_PORT_RX_AGGR
    pmadapter->mpa_rx.buf_len    = 0;
    pmadapter->mpa_rx.pkt_cnt    = 0;
    pmadapter->mpa_rx.start_port = 0;

    if (!pmadapter->init_para.mpa_rx_cfg)
    {
        pmadapter->mpa_rx.enabled = MFALSE;
    }
    else if (pmadapter->init_para.mpa_rx_cfg == MLAN_INIT_PARA_DISABLED)
    {
        pmadapter->mpa_rx.enabled = MFALSE;
    }
    else
    {
        pmadapter->mpa_rx.enabled = MTRUE;
    }
    pmadapter->mpa_rx.pkt_aggr_limit = SDIO_MP_AGGR_DEF_PKT_LIMIT;
#endif /* SDIO_MULTI_PORT_RX_AGGR */

    pmadapter->cmd_resp_received = MFALSE;
    pmadapter->event_received    = MFALSE;
    pmadapter->data_received     = MFALSE;

    pmadapter->cmd_timer_is_set = MFALSE;

    /* PnP and power profile */
    pmadapter->surprise_removed = MFALSE;

    /* Status variables */
    pmadapter->hw_status = WlanHardwareStatusInitializing;

    if (!pmadapter->init_para.ps_mode)
    {
        pmadapter->ps_mode = DEFAULT_PS_MODE;
    }
    else if (pmadapter->init_para.ps_mode == MLAN_INIT_PARA_DISABLED)
    {
        pmadapter->ps_mode = Wlan802_11PowerModeCAM;
    }
    else
    {
        pmadapter->ps_mode = Wlan802_11PowerModePSP;
    }
    pmadapter->ps_state       = PS_STATE_AWAKE;
    pmadapter->need_to_wakeup = MFALSE;

#endif /* CONFIG_MLAN_WMSDK */
#ifdef STA_SUPPORT
    /* Scan type */
    pmadapter->scan_type = MLAN_SCAN_TYPE_ACTIVE;
    /* Scan mode */
    pmadapter->scan_mode = HostCmd_BSS_MODE_ANY;
    /* Scan time */
    pmadapter->specific_scan_time = MRVDRV_SPECIFIC_SCAN_CHAN_TIME;
    pmadapter->active_scan_time   = MRVDRV_ACTIVE_SCAN_CHAN_TIME;
    pmadapter->passive_scan_time  = MRVDRV_PASSIVE_SCAN_CHAN_TIME;

    pmadapter->num_in_scan_table = 0;

    pmadapter->ecsa_enable = MFALSE;

    /* fixme: enable this later when required */
#if !CONFIG_MLAN_WMSDK
    (void)__memset(pmadapter, pmadapter->pscan_table, 0, (sizeof(BSSDescriptor_t) * MRVDRV_MAX_BSSID_LIST));
#endif /* CONFIG_MLAN_WMSDK */
#if CONFIG_EXT_SCAN_SUPPORT
    pmadapter->ext_scan = 1;
#endif
    pmadapter->scan_probes = DEFAULT_PROBES;

#if CONFIG_SCAN_WITH_RSSIFILTER
    pmadapter->rssi_threshold = 0;
#endif

    /* fixme: enable this later when required */
#if !CONFIG_MLAN_WMSDK
    (void)__memset(pmadapter, pmadapter->bcn_buf, 0, pmadapter->bcn_buf_size);
    pmadapter->pbcn_buf_end = pmadapter->bcn_buf;

    pmadapter->radio_on = RADIO_ON;
#endif                                    /* CONFIG_MLAN_WMSDK */
    pmadapter->multiple_dtim         = MRVDRV_DEFAULT_MULTIPLE_DTIM;
    pmadapter->local_listen_interval = 0; /* default value in firmware
                                             will be used */
#endif                                    /* STA_SUPPORT */

#if !CONFIG_MLAN_WMSDK
    pmadapter->is_deep_sleep = MFALSE;
    pmadapter->idle_time     = DEEP_SLEEP_IDLE_TIME;
    if (!pmadapter->init_para.auto_ds)
    {
        pmadapter->init_auto_ds = DEFAULT_AUTO_DS_MODE;
    }
    else if (pmadapter->init_para.auto_ds == MLAN_INIT_PARA_DISABLED)
    {
        pmadapter->init_auto_ds = MFALSE;
    }
    else
    {
        pmadapter->init_auto_ds = MTRUE;
    }

    pmadapter->delay_null_pkt = MFALSE;
#endif /* CONFIG_MLAN_WMSDK */
    pmadapter->delay_to_ps       = DELAY_TO_PS_DEFAULT;
    pmadapter->enhanced_ps_mode  = PS_MODE_AUTO;
    pmadapter->bcn_miss_time_out = DEFAULT_BCN_MISS_TIMEOUT;

#if CONFIG_WMM_UAPSD
    pmadapter->gen_null_pkt   = MFALSE; /* Disable NULL Pkt generation-default */
    pmadapter->pps_uapsd_mode = MFALSE; /* Disable pps/uapsd mode -default */
#endif
#if CONFIG_HOST_SLEEP
    pmadapter->is_hs_configured          = MFALSE;
    pmadapter->mgmt_filter[0].action     = 0;      /* discard and not wakeup host */
    pmadapter->mgmt_filter[0].type       = 0xff;   /* management frames */
    pmadapter->mgmt_filter[0].frame_mask = 0x1400; /* Frame-Mask bits :
                                                      : Bit 0 - Association Request
                                                      : Bit 1 - Association Response
                                                      : Bit 2 - Re-Association Request
                                                      : Bit 3 - Re-Association Response
                                                      : Bit 4 - Probe Request
                                                      : Bit 5 - Probe Response
                                                      : Bit 8 - Beacon Frames
                                                      : Bit 10 - Disassociation
                                                      : Bit 11 - Authentication
                                                      : Bit 12 - Deauthentication
                                                      : Bit 13 - Action Frames
                                                   */
#endif

#if !CONFIG_MLAN_WMSDK
    pmadapter->delay_null_pkt = MFALSE;

    pmadapter->pm_wakeup_card_req = MFALSE;

    pmadapter->pm_wakeup_fw_try = MFALSE;

    if (!pmadapter->init_para.max_tx_buf)
    {
        pmadapter->max_tx_buf_size = MLAN_TX_DATA_BUF_SIZE_2K;
    }
    else
    {
        pmadapter->max_tx_buf_size = (t_u16)pmadapter->init_para.max_tx_buf;
    }
    pmadapter->tx_buf_size      = MLAN_TX_DATA_BUF_SIZE_2K;
    pmadapter->curr_tx_buf_size = MLAN_TX_DATA_BUF_SIZE_2K;

    pmadapter->is_hs_configured  = MFALSE;
    pmadapter->hs_cfg.conditions = HOST_SLEEP_DEF_COND;
    pmadapter->hs_cfg.gpio       = HOST_SLEEP_DEF_GPIO;
    pmadapter->hs_cfg.gap        = HOST_SLEEP_DEF_GAP;
    pmadapter->hs_activated      = MFALSE;
    (void)__memset(pmadapter, pmadapter->event_body, 0, sizeof(pmadapter->event_body));
#endif /* CONFIG_MLAN_WMSDK */
    pmadapter->hw_dot_11n_dev_cap     = 0;
    pmadapter->hw_dev_mcs_support     = 0;
    pmadapter->usr_dot_11n_dev_cap_bg = 0;
    pmadapter->usr_dot_11n_dev_cap_a  = 0;
    pmadapter->usr_dev_mcs_support    = 0;
#ifdef STA_SUPPORT
    pmadapter->chan_bandwidth    = 0;
    pmadapter->adhoc_11n_enabled = MFALSE;
#endif /* STA_SUPPORT */

    pmadapter->hw_dot_11ac_dev_cap       = 0;
    pmadapter->hw_dot_11ac_mcs_support   = 0;
    pmadapter->usr_dot_11ac_opermode_bw  = 0;
    pmadapter->usr_dot_11ac_opermode_nss = 0;
#ifdef CONFIG_WIFI_NM_WPA_SUPPLICANT
    pmadapter->usr_dot_11n_enable = MTRUE;
    pmadapter->usr_dot_11ac_enable = MTRUE;
    pmadapter->usr_dot_11ax_enable = MTRUE;
#else
#if CONFIG_WIFI_CAPA
    pmadapter->usr_dot_11n_enable = MFALSE;
#if CONFIG_11AC
    pmadapter->usr_dot_11ac_enable = MFALSE;
#endif
#if CONFIG_11AX
    pmadapter->usr_dot_11ax_enable = MFALSE;
#endif
#endif
#endif
    /* Initialize 802.11d */
    wlan_11d_init(pmadapter);
    wlan_11h_init(pmadapter);

    wlan_wmm_init(pmadapter);
    wlan_init_wmm_param(pmadapter);
#if !CONFIG_MLAN_WMSDK
    if (pmadapter->psleep_cfm)
    {
        pmadapter->psleep_cfm->buf_type = MLAN_BUF_TYPE_CMD;
        pmadapter->psleep_cfm->data_len = sizeof(OPT_Confirm_Sleep);
        (void)__memset(pmadapter, &sleep_cfm_buf->ps_cfm_sleep, 0, sizeof(OPT_Confirm_Sleep));
        sleep_cfm_buf->ps_cfm_sleep.command             = wlan_cpu_to_le16(HostCmd_CMD_802_11_PS_MODE_ENH);
        sleep_cfm_buf->ps_cfm_sleep.size                = wlan_cpu_to_le16(sizeof(OPT_Confirm_Sleep));
        sleep_cfm_buf->ps_cfm_sleep.result              = 0;
        sleep_cfm_buf->ps_cfm_sleep.action              = wlan_cpu_to_le16(SLEEP_CONFIRM);
        sleep_cfm_buf->ps_cfm_sleep.sleep_cfm.resp_ctrl = wlan_cpu_to_le16(RESP_NEEDED);
    }
#endif
#if CONFIG_WMM_UAPSD
    (void)__memset(pmadapter, &pmadapter->sleep_params, 0, sizeof(pmadapter->sleep_params));
    (void)__memset(pmadapter, &pmadapter->sleep_period, 0, sizeof(pmadapter->sleep_period));

    pmadapter->tx_lock_flag = MFALSE;
#endif /* CONFIG_WMM_UAPSD */
    pmadapter->null_pkt_interval = 0;
    pmadapter->fw_bands          = 0U;
    pmadapter->config_bands      = 0U;
    pmadapter->adhoc_start_band  = 0U;
    /* pmadapter->pscan_channels = MNULL; */
    pmadapter->fw_release_number = 0;
    pmadapter->fw_cap_info       = 0;
#if !CONFIG_MLAN_WMSDK
    (void)__memset(pmadapter, &pmadapter->upld_buf, 0, sizeof(pmadapter->upld_buf));
    pmadapter->upld_len           = 0;
    pmadapter->event_cause        = 0;
    pmadapter->pmlan_buffer_event = MNULL;
#endif /* CONFIG_MLAN_WMSDK */
    (void)__memset(pmadapter, &pmadapter->region_channel, 0, sizeof(pmadapter->region_channel));
    pmadapter->region_code = MRVDRV_DEFAULT_REGION_CODE;
    (void)__memcpy(pmadapter, pmadapter->country_code, MRVDRV_DEFAULT_COUNTRY_CODE, COUNTRY_CODE_LEN);
    pmadapter->adhoc_awake_period = 0;
    pmadapter->ps_state           = PS_STATE_AWAKE;
#if !CONFIG_MLAN_WMSDK
#ifdef STA_SUPPORT
    (void)__memset(pmadapter, &pmadapter->arp_filter, 0, sizeof(pmadapter->arp_filter));
    pmadapter->arp_filter_size = 0;
#endif /* STA_SUPPORT */
    pmadapter->skip_dfs = MFALSE;

    LEAVE();
#endif /* CONFIG_MLAN_WMSDK */
    return;
}

/**
 *  @brief This function intializes the lock variables and
 *  the list heads.
 *
 *  @param pmadapter  A pointer to a mlan_adapter structure
 *
 *  @return           MLAN_STATUS_SUCCESS -- on success,
 *                    otherwise MLAN_STATUS_FAILURE
 *
 */
mlan_status wlan_init_lock_list(IN pmlan_adapter pmadapter)
{
    mlan_status ret    = MLAN_STATUS_SUCCESS;
    pmlan_private priv = MNULL;
    /* pmlan_callbacks pcb = &pmadapter->callbacks; */
    t_u8 i = 0;
    t_u8 j = 0;

    ENTER();
#if !CONFIG_MLAN_WMSDK
    if (pcb->moal_init_lock(pmadapter->pmoal_handle, &pmadapter->pmlan_lock) != MLAN_STATUS_SUCCESS)
    {
        ret = MLAN_STATUS_FAILURE;
        goto error;
    }
    if (pcb->moal_init_lock(pmadapter->pmoal_handle, &pmadapter->pint_lock) != MLAN_STATUS_SUCCESS)
    {
        ret = MLAN_STATUS_FAILURE;
        goto error;
    }
    if (pcb->moal_init_lock(pmadapter->pmoal_handle, &pmadapter->pmain_proc_lock) != MLAN_STATUS_SUCCESS)
    {
        ret = MLAN_STATUS_FAILURE;
        goto error;
    }
    if (pcb->moal_init_lock(pmadapter->pmoal_handle, &pmadapter->pmlan_cmd_lock) != MLAN_STATUS_SUCCESS)
    {
        ret = MLAN_STATUS_FAILURE;
        goto error;
    }
    for (i = 0; i < pmadapter->priv_num; i++)
    {
        if (pmadapter->priv[i])
        {
            priv = pmadapter->priv[i];
            if (pcb->moal_init_lock(pmadapter->pmoal_handle, &priv->rx_pkt_lock) != MLAN_STATUS_SUCCESS)
            {
                ret = MLAN_STATUS_FAILURE;
                goto error;
            }
            if (pcb->moal_init_lock(pmadapter->pmoal_handle, &priv->wmm.ra_list_spinlock) != MLAN_STATUS_SUCCESS)
            {
                ret = MLAN_STATUS_FAILURE;
                goto error;
            }
#ifdef STA_SUPPORT
            if (pcb->moal_init_lock(pmadapter->pmoal_handle, &priv->curr_bcn_buf_lock) != MLAN_STATUS_SUCCESS)
            {
                ret = MLAN_STATUS_FAILURE;
                goto error;
            }
#endif
        }
    }

    /* Initialize bypass_txq */
    util_init_list_head((t_void *)pmadapter->pmoal_handle, &pmadapter->bypass_txq, MTRUE,
                        pmadapter->callbacks.moal_init_lock);
    /* Initialize cmd_free_q */
    util_init_list_head((t_void *)pmadapter->pmoal_handle, &pmadapter->cmd_free_q, MTRUE,
                        pmadapter->callbacks.moal_init_lock);
    /* Initialize cmd_pending_q */
    util_init_list_head((t_void *)pmadapter->pmoal_handle, &pmadapter->cmd_pending_q, MTRUE,
                        pmadapter->callbacks.moal_init_lock);
    /* Initialize scan_pending_q */
    util_init_list_head((t_void *)pmadapter->pmoal_handle, &pmadapter->scan_pending_q, MTRUE,
                        pmadapter->callbacks.moal_init_lock);

    for (i = 0; i < pmadapter->priv_num; ++i)
    {
        util_init_list_head((t_void *)pmadapter->pmoal_handle, &pmadapter->bssprio_tbl[i].bssprio_head, MTRUE,
                            pmadapter->callbacks.moal_init_lock);
        pmadapter->bssprio_tbl[i].bssprio_cur = MNULL;
    }
#endif /* CONFIG_MLAN_WMSDK */
    for (i = 0; i < pmadapter->priv_num; i++)
    {
        if (pmadapter->priv[i] != NULL)
        {
            priv = pmadapter->priv[i];
            for (j = 0; j < MAX_NUM_TID; ++j)
            {
                util_init_list_head((t_void *)pmadapter->pmoal_handle, &priv->wmm.tid_tbl_ptr[j].ra_list, MTRUE,
                                    priv->adapter->callbacks.moal_init_lock);
            }

#if CONFIG_WMM
            /* wmm enhanced reuses 4 ac xmit queues */
            for (j = 0; j < MAX_AC_QUEUES; ++j)
            {
                if (priv->adapter->callbacks.moal_init_semaphore(pmadapter->pmoal_handle, "ra_list_sem",
                                                                 &priv->wmm.tid_tbl_ptr[j].ra_list.plock) !=
                    MLAN_STATUS_SUCCESS)
                {
                    wifi_e("Create ra_list_sem failed");
                    ret = MLAN_STATUS_FAILURE;
                    goto done;
                }
#if CONFIG_WMM_DEBUG
                util_init_list_head((t_void *)pmadapter->pmoal_handle, &priv->wmm.hist_ra[j], MFALSE, MNULL);
#endif
            }
#endif

            ret = (mlan_status)OSA_MutexCreate((osa_mutex_handle_t)priv->tx_ba_stream_tbl_lock);
            if (ret != MLAN_STATUS_SUCCESS)
            {
                wifi_e("Create Tx BA tbl sem failed");
                ret = MLAN_STATUS_FAILURE;
                goto done;
            }

            util_init_list_head((t_void *)pmadapter->pmoal_handle, &priv->tx_ba_stream_tbl_ptr, MTRUE,
                                pmadapter->callbacks.moal_init_lock);

            ret = (mlan_status)OSA_SemaphoreCreateBinary((osa_semaphore_handle_t)priv->rx_reorder_tbl_lock);
            if (ret != MLAN_STATUS_SUCCESS)
            {
                wifi_e("Create Rx Reorder tbl lock failed");
                ret = MLAN_STATUS_FAILURE;
                goto done;
            }
            OSA_SemaphorePost((osa_semaphore_handle_t)priv->rx_reorder_tbl_lock);
            util_init_list_head((t_void *)pmadapter->pmoal_handle, &priv->rx_reorder_tbl_ptr, MTRUE,
                                pmadapter->callbacks.moal_init_lock);

            util_scalar_init((t_void *)pmadapter->pmoal_handle, &priv->wmm.tx_pkts_queued, 0,
                             priv->wmm.ra_list_spinlock, pmadapter->callbacks.moal_init_lock);
            util_scalar_init((t_void *)pmadapter->pmoal_handle, &priv->wmm.highest_queued_prio, HIGH_PRIO_TID,
                             priv->wmm.ra_list_spinlock, pmadapter->callbacks.moal_init_lock);
            util_init_list_head((t_void *)pmadapter->pmoal_handle, &priv->sta_list, MTRUE,
                                pmadapter->callbacks.moal_init_lock);
        }
    }

done:
    /* error: */
    if (ret != MLAN_STATUS_SUCCESS)
    {
        for (i = 0; i < pmadapter->priv_num; i++)
        {
            priv = pmadapter->priv[i];
#if CONFIG_WMM
            for (j = 0; j < MAX_AC_QUEUES; ++j)
            {
                if ((uint32_t *)(*(uint32_t *)priv->wmm.tid_tbl_ptr[j].ra_list.plock) != NULL)
                    priv->adapter->callbacks.moal_free_semaphore(
                        pmadapter->pmoal_handle, &priv->wmm.tid_tbl_ptr[j].ra_list.plock);
            }
#endif
            if ((uint32_t *)(*(uint32_t *)priv->tx_ba_stream_tbl_lock) != NULL)
                OSA_MutexDestroy((osa_mutex_handle_t)priv->tx_ba_stream_tbl_lock);
            if ((uint32_t *)(*(uint32_t *)priv->rx_reorder_tbl_lock) != NULL)
                OSA_SemaphoreDestroy((osa_semaphore_handle_t)priv->rx_reorder_tbl_lock);
        }
    }
    LEAVE();
    return ret;
}

#if !CONFIG_MLAN_WMSDK
/**
 *  @brief This function releases the lock variables
 *
 *  @param pmadapter  A pointer to a mlan_adapter structure
 *
 *  @return           None
 *
 */
t_void wlan_free_lock_list(IN pmlan_adapter pmadapter)
{
    pmlan_private priv  = MNULL;
    pmlan_callbacks pcb = &pmadapter->callbacks;
    t_s32 i             = 0;
    t_s32 j             = 0;

    ENTER();

    if (pmadapter->pmlan_lock)
        pcb->moal_free_lock(pmadapter->pmoal_handle, pmadapter->pmlan_lock);
    if (pmadapter->pint_lock)
        pcb->moal_free_lock(pmadapter->pmoal_handle, pmadapter->pint_lock);
    if (pmadapter->pmain_proc_lock)
        pcb->moal_free_lock(pmadapter->pmoal_handle, pmadapter->pmain_proc_lock);
    if (pmadapter->pmlan_cmd_lock)
        pcb->moal_free_lock(pmadapter->pmoal_handle, pmadapter->pmlan_cmd_lock);

    for (i = 0; i < pmadapter->priv_num; i++)
    {
        if (pmadapter->priv[i])
        {
            priv = pmadapter->priv[i];
            if (priv->rx_pkt_lock)
                pcb->moal_free_lock(pmadapter->pmoal_handle, priv->rx_pkt_lock);
            if (priv->wmm.ra_list_spinlock)
                pcb->moal_free_lock(pmadapter->pmoal_handle, priv->wmm.ra_list_spinlock);
#ifdef STA_SUPPORT
            if (priv->curr_bcn_buf_lock)
                pcb->moal_free_lock(pmadapter->pmoal_handle, priv->curr_bcn_buf_lock);
#endif
        }
    }

    /* Free lists */
    util_free_list_head((t_void *)pmadapter->pmoal_handle, &pmadapter->bypass_txq, pmadapter->callbacks.moal_free_lock);
    util_free_list_head((t_void *)pmadapter->pmoal_handle, &pmadapter->cmd_free_q, pmadapter->callbacks.moal_free_lock);

    util_free_list_head((t_void *)pmadapter->pmoal_handle, &pmadapter->cmd_pending_q,
                        pmadapter->callbacks.moal_free_lock);

    util_free_list_head((t_void *)pmadapter->pmoal_handle, &pmadapter->scan_pending_q,
                        pmadapter->callbacks.moal_free_lock);

    for (i = 0; i < pmadapter->priv_num; i++)
        util_free_list_head((t_void *)pmadapter->pmoal_handle, &pmadapter->bssprio_tbl[i].bssprio_head,
                            pcb->moal_free_lock);

    for (i = 0; i < pmadapter->priv_num; i++)
    {
        if (pmadapter->priv[i])
        {
            priv = pmadapter->priv[i];
            util_free_list_head((t_void *)pmadapter->pmoal_handle, &priv->sta_list,
                                priv->adapter->callbacks.moal_free_lock);

            for (j = 0; j < MAX_NUM_TID; ++j)
                util_free_list_head((t_void *)priv->adapter->pmoal_handle, &priv->wmm.tid_tbl_ptr[j].ra_list,
                                    priv->adapter->callbacks.moal_free_lock);
            util_free_list_head((t_void *)priv->adapter->pmoal_handle, &priv->tx_ba_stream_tbl_ptr,
                                priv->adapter->callbacks.moal_free_lock);
            util_free_list_head((t_void *)priv->adapter->pmoal_handle, &priv->rx_reorder_tbl_ptr,
                                priv->adapter->callbacks.moal_free_lock);
            util_scalar_free((t_void *)priv->adapter->pmoal_handle, &priv->wmm.tx_pkts_queued,
                             priv->adapter->callbacks.moal_free_lock);
            util_scalar_free((t_void *)priv->adapter->pmoal_handle, &priv->wmm.highest_queued_prio,
                             priv->adapter->callbacks.moal_free_lock);
        }
    }

    LEAVE();
    return;
}

/**
 *  @brief This function intializes the timers
 *
 *  @param pmadapter  A pointer to a mlan_adapter structure
 *
 *  @return           MLAN_STATUS_SUCCESS -- on success,
 *                    otherwise MLAN_STATUS_FAILURE
 *
 */
mlan_status wlan_init_timer(IN pmlan_adapter pmadapter)
{
    mlan_status ret     = MLAN_STATUS_SUCCESS;
    pmlan_callbacks pcb = &pmadapter->callbacks;

    ENTER();

    if (pcb->moal_init_timer(pmadapter->pmoal_handle, &pmadapter->pmlan_cmd_timer, wlan_cmd_timeout_func, pmadapter) !=
        MLAN_STATUS_SUCCESS)
    {
        ret = MLAN_STATUS_FAILURE;
        goto error;
    }
error:
    LEAVE();
    return ret;
}

/**
 *  @brief This function releases the timers
 *
 *  @param pmadapter  A pointer to a mlan_adapter structure
 *
 *  @return           None
 *
 */
t_void wlan_free_timer(IN pmlan_adapter pmadapter)
{
    pmlan_callbacks pcb = &pmadapter->callbacks;

    ENTER();

    if (pmadapter->pmlan_cmd_timer)
        pcb->moal_free_timer(pmadapter->pmoal_handle, &pmadapter->pmlan_cmd_timer);

    LEAVE();
    return;
}
#endif /* CONFIG_MLAN_WMSDK */
/**
 *  @brief  This function initializes firmware
 *
 *  @param pmadapter		A pointer to mlan_adapter
 *
 *  @return		MLAN_STATUS_SUCCESS, MLAN_STATUS_PENDING or MLAN_STATUS_FAILURE
 */
mlan_status wlan_init_fw(IN pmlan_adapter pmadapter)
{
    mlan_status ret    = MLAN_STATUS_SUCCESS;
    pmlan_private priv = MNULL;
    t_u8 i             = 0;

    ENTER();

    /* Initialize adapter structure */
    wlan_init_adapter(pmadapter);

    for (i = 0; i < pmadapter->priv_num; i++)
    {
        if (pmadapter->priv[i] != NULL)
        {
            priv = pmadapter->priv[i];

            /* Initialize private structure */
            if ((ret = wlan_init_priv(priv)) != MLAN_STATUS_SUCCESS)
            {
                ret = MLAN_STATUS_FAILURE;
                goto done;
            }
        }
    }
#ifdef WIFI_CALIB_CMD_SUPPORT
    if (pmadapter->wifi_calib_mode != MTRUE)
    {
#endif
        /* Issue firmware initialize commands for first BSS, for other
           interfaces it will be called after getting the last init command
           response of previous interface */
#if !CONFIG_MLAN_WMSDK
        priv = wlan_get_priv(pmadapter, MLAN_BSS_ROLE_ANY);
        ret  = priv->ops.init_cmd(priv, MTRUE);
        if (ret == MLAN_STATUS_FAILURE)
            goto done;
#ifdef WIFI_CALIB_CMD_SUPPORT
    }
#endif

    if (util_peek_list(pmadapter->pmoal_handle, &pmadapter->cmd_pending_q, pmadapter->callbacks.moal_spin_lock,
                       pmadapter->callbacks.moal_spin_unlock))
    {
        /* Send the first command in queue and return */
        if (mlan_main_process(pmadapter) == MLAN_STATUS_FAILURE)
            ret = MLAN_STATUS_FAILURE;
        else
            ret = MLAN_STATUS_PENDING;
    }
    else
    {
        pmadapter->hw_status = WlanHardwareStatusReady;
    }
#endif /* CONFIG_MLAN_WMSDK */
done:
    LEAVE();
    return ret;
}

/**
 *  @brief This function frees the structure of adapter
 *
 *  @param pmadapter      A pointer to mlan_adapter structure
 *
 *  @return             N/A
 */
t_void wlan_free_adapter(pmlan_adapter pmadapter)
{
    ENTER();

    if (!pmadapter)
    {
        PRINTM(MERROR, "The adapter is NULL\n");
        LEAVE();
        return;
    }

#if !CONFIG_MLAN_WMSDK
    wlan_cancel_all_pending_cmd(pmadapter);
    /* Free command buffer */
    PRINTM(MINFO, "Free Command buffer\n");
    wlan_free_cmd_buffer(pmadapter);

    if (pmadapter->cmd_timer_is_set)
    {
        /* Cancel command timeout timer */
        pcb->moal_stop_timer(pmadapter->pmoal_handle, pmadapter->pmlan_cmd_timer);
        pmadapter->cmd_timer_is_set = MFALSE;
    }
#ifdef STA_SUPPORT
    PRINTM(MINFO, "Free ScanTable\n");
    if (pmadapter->pscan_table)
    {
        pcb->moal_mfree(pmadapter->pmoal_handle, (t_u8 *)pmadapter->pscan_table);
        pmadapter->pscan_table = MNULL;
    }
    if (pmadapter->bcn_buf)
    {
        pcb->moal_mfree(pmadapter->pmoal_handle, (t_u8 *)pmadapter->bcn_buf);
        pmadapter->bcn_buf = MNULL;
    }
#endif

    wlan_11h_cleanup(pmadapter);

    if (pmadapter->mp_regs_buf)
    {
        pcb->moal_mfree(pmadapter->pmoal_handle, (t_u8 *)pmadapter->mp_regs_buf);
        pmadapter->mp_regs_buf = MNULL;
        pmadapter->mp_regs     = MNULL;
    }
#if defined(SDIO_MULTI_PORT_TX_AGGR) || defined(SDIO_MULTI_PORT_RX_AGGR)
    wlan_free_sdio_mpa_buffers(pmadapter);
#endif
    wlan_free_mlan_buffer(pmadapter, pmadapter->psleep_cfm);
    pmadapter->psleep_cfm = MNULL;
#endif /* CONFIG_MLAN_WMSDK */

    LEAVE();
    return;
}

#if !CONFIG_MLAN_WMSDK
/**
 *  @brief This function frees the structure of priv
 *
 *  @param pmpriv  A pointer to mlan_private structure
 *
 *  @return        N/A
 */
t_void wlan_free_priv(mlan_private *pmpriv)
{
    ENTER();
    wlan_clean_txrx(pmpriv);
    wlan_delete_bsspriotbl(pmpriv);

#ifdef STA_SUPPORT
    wlan_free_curr_bcn(pmpriv);
#endif /* STA_SUPPORT */

    wlan_delete_station_list(pmpriv);
    LEAVE();
}

/**
 *  @brief The cmdresp handler calls this function for init_fw_complete callback
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *
 *  @return		MLAN_STATUS_SUCCESS
 *                      	The firmware initialization callback succeeded.
 */
mlan_status wlan_init_fw_complete(IN pmlan_adapter pmadapter)
{
    mlan_status status  = MLAN_STATUS_SUCCESS;
    mlan_status ret     = MLAN_STATUS_SUCCESS;
    pmlan_callbacks pcb = &pmadapter->callbacks;

    ENTER();

    /* Check if hardware is ready */
    if (pmadapter->hw_status != WlanHardwareStatusReady)
        status = MLAN_STATUS_FAILURE;

    /* Invoke callback */
    ret = pcb->moal_init_fw_complete(pmadapter->pmoal_handle, status);
    LEAVE();
    return ret;
}

/**
 *  @brief The cmdresp handler calls this function for shutdown_fw_complete callback
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *
 *  @return		MLAN_STATUS_SUCCESS
 *                      	The firmware shutdown callback succeeded.
 */
mlan_status wlan_shutdown_fw_complete(IN pmlan_adapter pmadapter)
{
    pmlan_callbacks pcb = &pmadapter->callbacks;
    mlan_status status  = MLAN_STATUS_SUCCESS;
    mlan_status ret     = MLAN_STATUS_SUCCESS;

    ENTER();
    pmadapter->hw_status = WlanHardwareStatusNotReady;
    /* Invoke callback */
    ret = pcb->moal_shutdown_fw_complete(pmadapter->pmoal_handle, status);
    LEAVE();
    return ret;
}
#endif /* CONFIG_MLAN_WMSDK */
