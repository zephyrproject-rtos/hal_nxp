/** @file mlan_misc.c
 *
 *  @brief  This file provides Miscellaneous functions for MLAN module
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
#include <mlan_fw.h>

/* Always keep this include at the end of all include files */
#include <mlan_remap_mem_operations.h>

#if !CONFIG_MLAN_WMSDK
/********************************************************
                Local Variables
********************************************************/

/********************************************************
                Global Variables
********************************************************/
#if defined(STA_SUPPORT) && defined(UAP_SUPPORT)
extern mlan_operations *mlan_ops[];
#endif
extern t_u8 ac_to_tid[4][2];

/********************************************************
                Local Functions
********************************************************/

/** Custom IE auto index and mask */
#define MLAN_CUSTOM_IE_AUTO_IDX_MASK 0xffff
/** Custom IE mask for delete operation */
#define MLAN_CUSTOM_IE_DELETE_MASK 0
/** Custom IE header size */
#define MLAN_CUSTOM_IE_HDR_SIZE (sizeof(custom_ie) - MAX_IE_SIZE)

/**
 *  @brief Check if current custom IE index is used on other interfaces.
 *
 *  @param pmpriv   A pointer to mlan_private structure
 *  @param idx		index to check for in use
 *
 *  @return		MLAN_STATUS_SUCCESS --unused, otherwise used.
 */
static mlan_status wlan_is_custom_ie_index_unused(IN pmlan_private pmpriv, IN t_u16 idx)
{
    t_u8 i                  = 0;
    pmlan_adapter pmadapter = pmpriv->adapter;
    pmlan_private priv;
    ENTER();

    for (i = 0; i < pmadapter->priv_num; i++)
    {
        priv = pmadapter->priv[i];
        /* Check for other interfaces only */
        if (priv && priv->bss_index != pmpriv->bss_index)
        {
            if (priv->mgmt_ie[idx].mgmt_subtype_mask && priv->mgmt_ie[idx].ie_length)
            {
                /* used entry found */
                LEAVE();
                return MLAN_STATUS_FAILURE;
            }
        }
    }
    LEAVE();
    return MLAN_STATUS_SUCCESS;
}

/**
 *  @brief Get the custom IE index
 *
 *  @param pmpriv       A pointer to mlan_private structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *  @param mask	mask value for which the index to be returned
 *  @param ie_data	a pointer to custom_ie structure
 *  @param idx		will hold the computed index
 *
 *  @return		MLAN_STATUS_SUCCESS --success, otherwise fail
 */
static mlan_status wlan_custom_ioctl_get_autoidx(
    IN pmlan_private pmpriv, IN pmlan_ioctl_req pioctl_req, IN t_u16 mask, IN custom_ie *ie_data, OUT t_u16 *idx)
{
    t_u16 index = 0, insert = MFALSE;
    mlan_status ret = MLAN_STATUS_SUCCESS;

    ENTER();
    /* Determine the index where the IE needs to be inserted */
    while (!insert)
    {
        while (index < pmpriv->adapter->max_mgmt_ie_index)
        {
            if (pmpriv->mgmt_ie[index].mgmt_subtype_mask == MLAN_CUSTOM_IE_AUTO_IDX_MASK)
            {
                index++;
                continue;
            }
            if (pmpriv->mgmt_ie[index].mgmt_subtype_mask == mask)
            {
                /* Duplicate IE should be avoided */
                if (pmpriv->mgmt_ie[index].ie_length)
                {
                    if (!__memcmp(pmpriv->adapter, pmpriv->mgmt_ie[index].ie_buffer, ie_data->ie_buffer,
                                  pmpriv->mgmt_ie[index].ie_length))
                    {
                        PRINTM(MERROR, "IE with the same mask exists at index %d\n", index);
                        *idx = MLAN_CUSTOM_IE_AUTO_IDX_MASK;
                        goto done;
                    }
                }
                /* Check if enough space is available */
                if (pmpriv->mgmt_ie[index].ie_length + ie_data->ie_length > MAX_IE_SIZE)
                {
                    index++;
                    continue;
                }
                insert = MTRUE;
                break;
            }
            index++;
        }
        if (!insert)
        {
            for (index = 0; index < pmpriv->adapter->max_mgmt_ie_index; index++)
            {
                if (pmpriv->mgmt_ie[index].ie_length == 0)
                {
                    /*
                     * Check if this index is in use by other interface
                     * If yes, move ahead to next index
                     */
                    if (MLAN_STATUS_SUCCESS == wlan_is_custom_ie_index_unused(pmpriv, index))
                    {
                        insert = MTRUE;
                        break;
                    }
                    else
                    {
                        PRINTM(MINFO, "Skipping IE index %d in use.\n", index);
                    }
                }
            }
        }
        if (index == pmpriv->adapter->max_mgmt_ie_index && !insert)
        {
            PRINTM(MERROR, "Failed to Set the IE buffer\n");
            if (pioctl_req)
                pioctl_req->status_code = MLAN_ERROR_IOCTL_FAIL;
            ret = MLAN_STATUS_FAILURE;
            goto done;
        }
    }

    *idx = index;
done:
    LEAVE();
    return ret;
}

/**
 *  @brief Delete custom IE
 *
 *  @param pmpriv       A pointer to mlan_private structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *  @param ie_data	a pointer to custom_ie structure
 *  @param idx		index supplied
 *
 *  @return		MLAN_STATUS_SUCCESS --success, otherwise fail
 */

static mlan_status wlan_custom_ioctl_auto_delete(IN pmlan_private pmpriv,
                                                 IN pmlan_ioctl_req pioctl_req,
                                                 IN custom_ie *ie_data,
                                                 IN t_u16 idx)
{
    mlan_status ret         = MLAN_STATUS_SUCCESS;
    pmlan_adapter pmadapter = pmpriv->adapter;
    t_u16 index = 0, insert                   = MFALSE, del_len;
    t_u8 del_ie[MAX_IE_SIZE], ie[MAX_IE_SIZE] = {0x0};
    t_s32 cnt, tmp_len                        = 0;
    t_u8 *tmp_ie;

    ENTER();
    (void)__memset(pmpriv->adapter, del_ie, 0, MAX_IE_SIZE);
    (void)__memcpy(pmpriv->adapter, del_ie, ie_data->ie_buffer, MIN(MAX_IE_SIZE, ie_data->ie_length));
    del_len = MIN(MAX_IE_SIZE, ie_data->ie_length);

    for (index = 0; index < pmadapter->max_mgmt_ie_index; index++)
    {
        if (MLAN_CUSTOM_IE_AUTO_IDX_MASK != idx)
            index = idx;
        tmp_ie  = pmpriv->mgmt_ie[index].ie_buffer;
        tmp_len = pmpriv->mgmt_ie[index].ie_length;
        cnt     = 0;
        while (tmp_len)
        {
            if (!__memcmp(pmpriv->adapter, tmp_ie, del_ie, del_len))
            {
                (void)__memcpy(pmpriv->adapter, ie, pmpriv->mgmt_ie[index].ie_buffer, cnt);
                if (pmpriv->mgmt_ie[index].ie_length > (cnt + del_len))
                    (void)__memcpy(pmpriv->adapter, &ie[cnt],
                                   &pmpriv->mgmt_ie[index].ie_buffer[MIN((MAX_IE_SIZE - 1), (cnt + del_len))],
                                   (pmpriv->mgmt_ie[index].ie_length - (cnt + del_len)));
                (void)__memset(pmpriv->adapter, &pmpriv->mgmt_ie[index].ie_buffer, 0,
                               sizeof(pmpriv->mgmt_ie[index].ie_buffer));
                (void)__memcpy(pmpriv->adapter, &pmpriv->mgmt_ie[index].ie_buffer, ie,
                               pmpriv->mgmt_ie[index].ie_length - del_len);
                pmpriv->mgmt_ie[index].ie_length -= del_len;
                insert  = MTRUE;
                tmp_ie  = pmpriv->mgmt_ie[index].ie_buffer;
                tmp_len = pmpriv->mgmt_ie[index].ie_length;
                cnt     = 0;
                continue;
            }
            tmp_ie++;
            tmp_len--;
            cnt++;
        }
        if (MLAN_CUSTOM_IE_AUTO_IDX_MASK != idx)
            break;
    }
    if (index == pmadapter->max_mgmt_ie_index && !insert)
    {
        PRINTM(MERROR, "Failed to Clear IE buffer\n");
        if (pioctl_req)
            pioctl_req->status_code = MLAN_ERROR_IOCTL_FAIL;
        ret = MLAN_STATUS_FAILURE;
    }
    LEAVE();
    return ret;
}

/********************************************************
                Global Functions
********************************************************/

/**
 *  @brief send host cmd
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_PENDING --success, otherwise fail
 */
mlan_status wlan_misc_ioctl_host_cmd(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    mlan_status ret        = MLAN_STATUS_SUCCESS;
    mlan_private *pmpriv   = pmadapter->priv[pioctl_req->bss_index];
    mlan_ds_misc_cfg *misc = MNULL;

    ENTER();

    misc = (mlan_ds_misc_cfg *)pioctl_req->pbuf;

    /* Send request to firmware */
    ret = wlan_prepare_cmd(pmpriv, 0, 0, 0, (t_void *)pioctl_req, (t_void *)&misc->param.hostcmd);
    if (ret == MLAN_STATUS_SUCCESS)
        ret = MLAN_STATUS_PENDING;

    LEAVE();
    return ret;
}

/**
 *  @brief Send function init/shutdown command to firmware
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_PENDING --success, otherwise fail
 */
mlan_status wlan_misc_ioctl_init_shutdown(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    mlan_private *pmpriv       = pmadapter->priv[pioctl_req->bss_index];
    mlan_status ret            = MLAN_STATUS_SUCCESS;
    mlan_ds_misc_cfg *misc_cfg = MNULL;
    t_u16 cmd;

    ENTER();

    misc_cfg = (mlan_ds_misc_cfg *)pioctl_req->pbuf;
    if (misc_cfg->param.func_init_shutdown == MLAN_FUNC_INIT)
        cmd = HostCmd_CMD_FUNC_INIT;
    else if (misc_cfg->param.func_init_shutdown == MLAN_FUNC_SHUTDOWN)
        cmd = HostCmd_CMD_FUNC_SHUTDOWN;
    else
    {
        PRINTM(MERROR, "Unsupported parameter\n");
        pioctl_req->status_code = MLAN_ERROR_INVALID_PARAMETER;
        ret                     = MLAN_STATUS_FAILURE;
        goto exit;
    }

    /* Send command to firmware */
    ret = wlan_prepare_cmd(pmpriv, cmd, HostCmd_ACT_GEN_SET, 0, (t_void *)pioctl_req, MNULL);

    if (ret == MLAN_STATUS_SUCCESS)
        ret = MLAN_STATUS_PENDING;

exit:
    LEAVE();
    return ret;
}

/**
 *  @brief Get debug information
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_SUCCESS --success
 */
mlan_status wlan_get_info_debug_info(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    pmlan_private pmpriv = pmadapter->priv[pioctl_req->bss_index];
    mlan_status ret      = MLAN_STATUS_SUCCESS;
    mlan_ds_get_info *info;
    t_u8 *ptid;

    ENTER();

    info = (mlan_ds_get_info *)pioctl_req->pbuf;

    if (pioctl_req->action == MLAN_ACT_SET)
    {
        pmadapter->max_tx_buf_size  = (t_u16)info->param.debug_info.max_tx_buf_size;
        pmadapter->tx_buf_size      = (t_u16)info->param.debug_info.tx_buf_size;
        pmadapter->curr_tx_buf_size = (t_u16)info->param.debug_info.curr_tx_buf_size;
        pmadapter->ps_mode          = info->param.debug_info.ps_mode;
        pmadapter->ps_state         = info->param.debug_info.ps_state;
#ifdef STA_SUPPORT
        pmadapter->is_deep_sleep = info->param.debug_info.is_deep_sleep;
#endif /* STA_SUPPORT */
        pmadapter->pm_wakeup_card_req  = info->param.debug_info.pm_wakeup_card_req;
        pmadapter->pm_wakeup_fw_try    = info->param.debug_info.pm_wakeup_fw_try;
        pmadapter->is_hs_configured    = info->param.debug_info.is_hs_configured;
        pmadapter->hs_activated        = info->param.debug_info.hs_activated;
        pmadapter->pps_uapsd_mode      = info->param.debug_info.pps_uapsd_mode;
        pmadapter->sleep_period.period = info->param.debug_info.sleep_pd;
        pmpriv->wmm_qosinfo            = info->param.debug_info.qos_cfg;
        pmadapter->tx_lock_flag        = info->param.debug_info.tx_lock_flag;
        pmpriv->port_open              = info->param.debug_info.port_open;
        pmadapter->scan_processing     = info->param.debug_info.scan_processing;

        pmadapter->dbg.num_cmd_host_to_card_failure = info->param.debug_info.num_cmd_host_to_card_failure;
        pmadapter->dbg.num_cmd_sleep_cfm_host_to_card_failure =
            info->param.debug_info.num_cmd_sleep_cfm_host_to_card_failure;
        pmadapter->dbg.num_tx_host_to_card_failure     = info->param.debug_info.num_tx_host_to_card_failure;
        pmadapter->dbg.num_cmdevt_card_to_host_failure = info->param.debug_info.num_cmdevt_card_to_host_failure;
        pmadapter->dbg.num_rx_card_to_host_failure     = info->param.debug_info.num_rx_card_to_host_failure;
        pmadapter->dbg.num_int_read_failure            = info->param.debug_info.num_int_read_failure;
        pmadapter->dbg.last_int_status                 = info->param.debug_info.last_int_status;
        pmadapter->dbg.num_event_deauth                = info->param.debug_info.num_event_deauth;
        pmadapter->dbg.num_event_disassoc              = info->param.debug_info.num_event_disassoc;
        pmadapter->dbg.num_event_link_lost             = info->param.debug_info.num_event_link_lost;
        pmadapter->dbg.num_cmd_deauth                  = info->param.debug_info.num_cmd_deauth;
        pmadapter->dbg.num_cmd_assoc_success           = info->param.debug_info.num_cmd_assoc_success;
        pmadapter->dbg.num_cmd_assoc_failure           = info->param.debug_info.num_cmd_assoc_failure;
        pmadapter->dbg.num_tx_timeout                  = info->param.debug_info.num_tx_timeout;
        pmadapter->dbg.num_cmd_timeout                 = info->param.debug_info.num_cmd_timeout;
        pmadapter->dbg.timeout_cmd_id                  = info->param.debug_info.timeout_cmd_id;
        pmadapter->dbg.timeout_cmd_act                 = info->param.debug_info.timeout_cmd_act;
        (void)__memcpy(pmadapter, pmadapter->dbg.last_cmd_id, info->param.debug_info.last_cmd_id,
                       sizeof(pmadapter->dbg.last_cmd_id));
        (void)__memcpy(pmadapter, pmadapter->dbg.last_cmd_act, info->param.debug_info.last_cmd_act,
                       sizeof(pmadapter->dbg.last_cmd_act));
        pmadapter->dbg.last_cmd_index = info->param.debug_info.last_cmd_index;
        (void)__memcpy(pmadapter, pmadapter->dbg.last_cmd_resp_id, info->param.debug_info.last_cmd_resp_id,
                       sizeof(pmadapter->dbg.last_cmd_resp_id));
        pmadapter->dbg.last_cmd_resp_index = info->param.debug_info.last_cmd_resp_index;
        (void)__memcpy(pmadapter, pmadapter->dbg.last_event, info->param.debug_info.last_event,
                       sizeof(pmadapter->dbg.last_event));
        pmadapter->dbg.last_event_index = info->param.debug_info.last_event_index;

        pmadapter->data_sent         = info->param.debug_info.data_sent;
        pmadapter->cmd_sent          = info->param.debug_info.cmd_sent;
        pmadapter->mp_rd_bitmap      = info->param.debug_info.mp_rd_bitmap;
        pmadapter->mp_wr_bitmap      = info->param.debug_info.mp_wr_bitmap;
        pmadapter->curr_rd_port      = info->param.debug_info.curr_rd_port;
        pmadapter->curr_wr_port      = info->param.debug_info.curr_wr_port;
        pmadapter->cmd_resp_received = info->param.debug_info.cmd_resp_received;
#ifdef UAP_SUPPORT
        pmadapter->pending_bridge_pkts = info->param.debug_info.num_bridge_pkts;
        pmpriv->num_drop_pkts          = info->param.debug_info.num_drop_pkts;
#endif
    }
    else
    { /* MLAN_ACT_GET */
        ptid                                    = ac_to_tid[WMM_AC_BK];
        info->param.debug_info.wmm_ac_bk        = pmpriv->wmm.packets_out[ptid[0]] + pmpriv->wmm.packets_out[ptid[1]];
        ptid                                    = ac_to_tid[WMM_AC_BE];
        info->param.debug_info.wmm_ac_be        = pmpriv->wmm.packets_out[ptid[0]] + pmpriv->wmm.packets_out[ptid[1]];
        ptid                                    = ac_to_tid[WMM_AC_VI];
        info->param.debug_info.wmm_ac_vi        = pmpriv->wmm.packets_out[ptid[0]] + pmpriv->wmm.packets_out[ptid[1]];
        ptid                                    = ac_to_tid[WMM_AC_VO];
        info->param.debug_info.wmm_ac_vo        = pmpriv->wmm.packets_out[ptid[0]] + pmpriv->wmm.packets_out[ptid[1]];
        info->param.debug_info.max_tx_buf_size  = (t_u32)pmadapter->max_tx_buf_size;
        info->param.debug_info.tx_buf_size      = (t_u32)pmadapter->tx_buf_size;
        info->param.debug_info.curr_tx_buf_size = (t_u32)pmadapter->curr_tx_buf_size;
        info->param.debug_info.rx_tbl_num       = wlan_get_rxreorder_tbl(pmpriv, info->param.debug_info.rx_tbl);
        info->param.debug_info.tx_tbl_num       = wlan_get_txbastream_tbl(pmpriv, info->param.debug_info.tx_tbl);
        info->param.debug_info.ps_mode          = pmadapter->ps_mode;
        info->param.debug_info.ps_state         = pmadapter->ps_state;
#ifdef STA_SUPPORT
        info->param.debug_info.is_deep_sleep = pmadapter->is_deep_sleep;
#endif /* STA_SUPPORT */
        info->param.debug_info.pm_wakeup_card_req = pmadapter->pm_wakeup_card_req;
        info->param.debug_info.pm_wakeup_fw_try   = pmadapter->pm_wakeup_fw_try;
        info->param.debug_info.is_hs_configured   = pmadapter->is_hs_configured;
        info->param.debug_info.hs_activated       = pmadapter->hs_activated;
        info->param.debug_info.pps_uapsd_mode     = pmadapter->pps_uapsd_mode;
        info->param.debug_info.sleep_pd           = pmadapter->sleep_period.period;
        info->param.debug_info.qos_cfg            = pmpriv->wmm_qosinfo;
        info->param.debug_info.tx_lock_flag       = pmadapter->tx_lock_flag;
        info->param.debug_info.port_open          = pmpriv->port_open;
        info->param.debug_info.scan_processing    = pmadapter->scan_processing;

        info->param.debug_info.num_cmd_host_to_card_failure = pmadapter->dbg.num_cmd_host_to_card_failure;
        info->param.debug_info.num_cmd_sleep_cfm_host_to_card_failure =
            pmadapter->dbg.num_cmd_sleep_cfm_host_to_card_failure;
        info->param.debug_info.num_tx_host_to_card_failure     = pmadapter->dbg.num_tx_host_to_card_failure;
        info->param.debug_info.num_cmdevt_card_to_host_failure = pmadapter->dbg.num_cmdevt_card_to_host_failure;
        info->param.debug_info.num_rx_card_to_host_failure     = pmadapter->dbg.num_rx_card_to_host_failure;
        info->param.debug_info.num_int_read_failure            = pmadapter->dbg.num_int_read_failure;
        info->param.debug_info.last_int_status                 = pmadapter->dbg.last_int_status;
        info->param.debug_info.num_event_deauth                = pmadapter->dbg.num_event_deauth;
        info->param.debug_info.num_event_disassoc              = pmadapter->dbg.num_event_disassoc;
        info->param.debug_info.num_event_link_lost             = pmadapter->dbg.num_event_link_lost;
        info->param.debug_info.num_cmd_deauth                  = pmadapter->dbg.num_cmd_deauth;
        info->param.debug_info.num_cmd_assoc_success           = pmadapter->dbg.num_cmd_assoc_success;
        info->param.debug_info.num_cmd_assoc_failure           = pmadapter->dbg.num_cmd_assoc_failure;
        info->param.debug_info.num_tx_timeout                  = pmadapter->dbg.num_tx_timeout;
        info->param.debug_info.num_cmd_timeout                 = pmadapter->dbg.num_cmd_timeout;
        info->param.debug_info.timeout_cmd_id                  = pmadapter->dbg.timeout_cmd_id;
        info->param.debug_info.timeout_cmd_act                 = pmadapter->dbg.timeout_cmd_act;
        (void)__memcpy(pmadapter, info->param.debug_info.last_cmd_id, pmadapter->dbg.last_cmd_id,
                       sizeof(pmadapter->dbg.last_cmd_id));
        (void)__memcpy(pmadapter, info->param.debug_info.last_cmd_act, pmadapter->dbg.last_cmd_act,
                       sizeof(pmadapter->dbg.last_cmd_act));
        info->param.debug_info.last_cmd_index = pmadapter->dbg.last_cmd_index;
        (void)__memcpy(pmadapter, info->param.debug_info.last_cmd_resp_id, pmadapter->dbg.last_cmd_resp_id,
                       sizeof(pmadapter->dbg.last_cmd_resp_id));
        info->param.debug_info.last_cmd_resp_index = pmadapter->dbg.last_cmd_resp_index;
        (void)__memcpy(pmadapter, info->param.debug_info.last_event, pmadapter->dbg.last_event,
                       sizeof(pmadapter->dbg.last_event));
        info->param.debug_info.last_event_index = pmadapter->dbg.last_event_index;

        info->param.debug_info.mp_rd_bitmap      = pmadapter->mp_rd_bitmap;
        info->param.debug_info.mp_wr_bitmap      = pmadapter->mp_wr_bitmap;
        info->param.debug_info.curr_rd_port      = pmadapter->curr_rd_port;
        info->param.debug_info.curr_wr_port      = pmadapter->curr_wr_port;
        info->param.debug_info.data_sent         = pmadapter->data_sent;
        info->param.debug_info.cmd_sent          = pmadapter->cmd_sent;
        info->param.debug_info.cmd_resp_received = pmadapter->cmd_resp_received;
        info->param.debug_info.tx_pkts_queued =
            util_scalar_read(pmadapter->pmoal_handle, &pmpriv->wmm.tx_pkts_queued, MNULL, MNULL);
#ifdef UAP_SUPPORT
        info->param.debug_info.num_bridge_pkts = pmadapter->pending_bridge_pkts;
        info->param.debug_info.num_drop_pkts   = pmpriv->num_drop_pkts;
#endif
    }

    pioctl_req->data_read_written = sizeof(mlan_debug_info) + MLAN_SUB_COMMAND_SIZE;

    LEAVE();
    return ret;
}

/**
 *  @brief This function wakes up the card.
 *
 *  @param pmadapter		A pointer to mlan_adapter structure
 *
 *  @return			MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
mlan_status wlan_pm_wakeup_card(IN pmlan_adapter pmadapter)
{
    mlan_status ret     = MLAN_STATUS_SUCCESS;
    pmlan_callbacks pcb = &pmadapter->callbacks;

    ENTER();
    PRINTM(MEVENT, "Wakeup device...\n");
    ret = pcb->moal_write_reg(pmadapter->pmoal_handle, HOST_TO_CARD_EVENT_REG, HOST_POWER_UP);
    LEAVE();
    return ret;
}

/**
 *  @brief This function resets the PM setting of the card.
 *
 *  @param pmadapter		A pointer to mlan_adapter structure
 *
 *  @return			MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
mlan_status wlan_pm_reset_card(IN pmlan_adapter pmadapter)
{
    mlan_status ret     = MLAN_STATUS_SUCCESS;
    pmlan_callbacks pcb = &pmadapter->callbacks;

    ENTER();

    ret = pcb->moal_write_reg(pmadapter->pmoal_handle, HOST_TO_CARD_EVENT_REG, 0);

    LEAVE();
    return ret;
}

/**
 *  @brief Set/Get HS configuration
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_SUCCESS/MLAN_STATUS_PENDING --success, otherwise fail
 */
mlan_status wlan_pm_ioctl_hscfg(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    mlan_private *pmpriv = pmadapter->priv[pioctl_req->bss_index];
    mlan_ds_pm_cfg *pm   = MNULL;
    mlan_status status   = MLAN_STATUS_SUCCESS;
    t_u32 prev_cond      = 0;

    ENTER();

    pm = (mlan_ds_pm_cfg *)pioctl_req->pbuf;

    switch (pioctl_req->action)
    {
        case MLAN_ACT_SET:
#ifdef STA_SUPPORT
            if (pmadapter->pps_uapsd_mode)
            {
                PRINTM(MINFO, "Host Sleep IOCTL is blocked in UAPSD/PPS mode\n");
                pioctl_req->status_code = MLAN_ERROR_IOCTL_INVALID;
                status                  = MLAN_STATUS_FAILURE;
                break;
            }
#endif /* STA_SUPPORT */
            if (pm->param.hs_cfg.is_invoke_hostcmd == MTRUE)
            {
                if (pm->param.hs_cfg.conditions == HOST_SLEEP_CFG_CANCEL)
                {
                    if (pmadapter->is_hs_configured == MFALSE)
                    {
                        /* Already cancelled */
                        break;
                    }
                    /* Save previous condition */
                    prev_cond                    = pmadapter->hs_cfg.conditions;
                    pmadapter->hs_cfg.conditions = pm->param.hs_cfg.conditions;
                }
                else if (pmadapter->hs_cfg.conditions == HOST_SLEEP_CFG_CANCEL)
                {
                    /* Return failure if no parameters for HS enable */
                    pioctl_req->status_code = MLAN_ERROR_INVALID_PARAMETER;
                    status                  = MLAN_STATUS_FAILURE;
                    break;
                }
                status = wlan_prepare_cmd(pmpriv, HostCmd_CMD_802_11_HS_CFG_ENH, HostCmd_ACT_GEN_SET, 0,
                                          (t_void *)pioctl_req, (t_void *)(&pmadapter->hs_cfg));
                if (status == MLAN_STATUS_SUCCESS)
                    status = MLAN_STATUS_PENDING;
                if (pm->param.hs_cfg.conditions == HOST_SLEEP_CFG_CANCEL)
                {
                    /* Restore previous condition */
                    pmadapter->hs_cfg.conditions = prev_cond;
                }
            }
            else
            {
                pmadapter->hs_cfg.conditions = pm->param.hs_cfg.conditions;
                pmadapter->hs_cfg.gpio       = (t_u8)pm->param.hs_cfg.gpio;
                pmadapter->hs_cfg.gap        = (t_u8)pm->param.hs_cfg.gap;
            }
            break;
        case MLAN_ACT_GET:
            pm->param.hs_cfg.conditions = pmadapter->hs_cfg.conditions;
            pm->param.hs_cfg.gpio       = pmadapter->hs_cfg.gpio;
            pm->param.hs_cfg.gap        = pmadapter->hs_cfg.gap;
            break;
        default:
            pioctl_req->status_code = MLAN_ERROR_IOCTL_INVALID;
            status                  = MLAN_STATUS_FAILURE;
            break;
    }

    LEAVE();
    return status;
}
#endif /* CONFIG_MLAN_WMSDK */

/**
 *  @brief This function allocates a mlan_buffer.
 *
 *  @param pmadapter Pointer to mlan_adapter
 *  @param data_len   Data length
 *  @param head_room  head_room reserved in mlan_buffer
 *  @param malloc_flag  flag to user moal_malloc
 *  @return           mlan_buffer pointer or MNULL
 */
pmlan_buffer wlan_alloc_mlan_buffer(mlan_adapter *pmadapter, t_u32 data_len, t_u32 head_room, t_u32 malloc_flag)
{
    mlan_status ret    = MLAN_STATUS_SUCCESS;
    pmlan_buffer pmbuf = MNULL;
    t_u32 buf_size     = 0;
    /* t_u8 *tmp_buf = MNULL; */
    pmlan_callbacks pcb = &pmadapter->callbacks;

    ENTER();

    /* make sure that the data length is at least SDIO block size */
    data_len = ALIGN_SZ(data_len, MLAN_SDIO_BLOCK_SIZE);

    /* head_room is not implemented for malloc mlan buffer */
    if (malloc_flag == MTRUE)
    {
        buf_size = sizeof(mlan_buffer) + data_len + DMA_ALIGNMENT;
        ret =
            pcb->moal_malloc(pmadapter->pmoal_handle, buf_size, MLAN_MEM_DEF | MLAN_MEM_DMA, (t_u8 **)(void **)&pmbuf);
        if ((ret != MLAN_STATUS_SUCCESS) || (pmbuf == MNULL))
        {
            pmbuf = MNULL;
            goto exit;
        }
        (void)__memset(pmadapter, pmbuf, 0, sizeof(mlan_buffer));

        pmbuf->pdesc = MNULL;
        /* Align address */
        pmbuf->pbuf        = (t_u8 *)ALIGN_ADDR((t_u8 *)pmbuf + sizeof(mlan_buffer), DMA_ALIGNMENT);
        pmbuf->data_offset = 0;
        pmbuf->data_len    = data_len;
        pmbuf->flags |= MLAN_BUF_FLAG_MALLOC_BUF;
    }
#if !CONFIG_MLAN_WMSDK
    else
    {
        /* use moal_alloc_mlan_buffer, head_room supported */
        ret = pcb->moal_alloc_mlan_buffer(pmadapter->pmoal_handle, data_len + DMA_ALIGNMENT + head_room, &pmbuf);
        if ((ret != MLAN_STATUS_SUCCESS) || !pmbuf)
        {
            PRINTM(MERROR, "Failed to allocate 'mlan_buffer'\n");
            goto exit;
        }
        pmbuf->data_offset = head_room;
        tmp_buf            = (t_u8 *)ALIGN_ADDR(pmbuf->pbuf + pmbuf->data_offset, DMA_ALIGNMENT);
        pmbuf->data_offset += (t_u32)(tmp_buf - (pmbuf->pbuf + pmbuf->data_offset));
        pmbuf->data_len = data_len;
        pmbuf->flags    = 0;
    }
#endif /* CONFIG_MLAN_WMSDK */
exit:
    LEAVE();
    return pmbuf;
}

/**
 *  @brief This function frees a mlan_buffer.
 *
 *  @param pmadapter  Pointer to mlan_adapter
 *  @param pmbuf      Pointer to mlan_buffer
 *
 *  @return           N/A
 */
t_void wlan_free_mlan_buffer(mlan_adapter *pmadapter, pmlan_buffer pmbuf)
{
#if !CONFIG_MLAN_WMSDK
    pmlan_callbacks pcb = &pmadapter->callbacks;
    ENTER();

    if (pcb && pmbuf)
    {
        if (pmbuf->flags & MLAN_BUF_FLAG_MALLOC_BUF)
            pcb->moal_mfree(pmadapter->pmoal_handle, (t_u8 *)pmbuf);
        else
            pcb->moal_free_mlan_buffer(pmadapter->pmoal_handle, pmbuf);
    }

    LEAVE();
#endif /* CONFIG_MLAN_WMSDK */
    return;
}

#if !CONFIG_MLAN_WMSDK
/**
 *  @brief Delay function implementation
 *
 *  @param pmadapter        A pointer to mlan_adapter structure
 *  @param delay            Delay value
 *  @param u                Units of delay (sec, msec or usec)
 *
 *  @return                 N/A
 */
t_void wlan_delay_func(mlan_adapter *pmadapter, t_u32 delay, t_delay_unit u)
{
    t_u32 now_tv_sec, now_tv_usec;
    t_u32 upto_tv_sec, upto_tv_usec;
    pmlan_callbacks pcb = &pmadapter->callbacks;

    ENTER();

    if (pcb->moal_udelay)
    {
        if (u == SEC)
        {
            delay *= 1000000;
        }
        else if (u == MSEC)
        {
            delay *= 1000;
        }
        pcb->moal_udelay(pmadapter->pmoal_handle, delay);
    }
    else
    {
        pcb->moal_get_system_time(pmadapter->pmoal_handle, &upto_tv_sec, &upto_tv_usec);

        switch (u)
        {
            case SEC:
                upto_tv_sec += delay;
                break;
            case MSEC:
                delay *= 1000;
            case USEC:
                upto_tv_sec += (delay / 1000000);
                upto_tv_usec += (delay % 1000000);
                break;
        }

        do
        {
            pcb->moal_get_system_time(pmadapter->pmoal_handle, &now_tv_sec, &now_tv_usec);
            if (now_tv_sec > upto_tv_sec)
            {
                LEAVE();
                return;
            }

            if ((now_tv_sec == upto_tv_sec) && (now_tv_usec >= upto_tv_usec))
            {
                LEAVE();
                return;
            }
        } while (MTRUE);
    }

    LEAVE();
    return;
}

#if defined(STA_SUPPORT) && defined(UAP_SUPPORT)
/**
 *  @brief Set/Get BSS role
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_SUCCESS --success, MLAN_STATUS_PENDING --pending
 */
mlan_status wlan_bss_ioctl_bss_role(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    mlan_private *pmpriv = pmadapter->priv[pioctl_req->bss_index];
    mlan_ds_bss *bss     = MNULL;
    mlan_status ret      = MLAN_STATUS_SUCCESS;
    HostCmd_DS_VERSION_EXT dummy;
#if defined(WIFI_DIRECT_SUPPORT)
    t_u8 bss_mode;
#endif
    t_u8 i, global_band = 0;
    int j;

    ENTER();

    bss = (mlan_ds_bss *)pioctl_req->pbuf;
    if (pioctl_req->action == MLAN_ACT_GET)
    {
        bss->param.bss_role = GET_BSS_ROLE(pmpriv);
    }
    else
    {
        /** Switch BSS role */
        wlan_free_priv(pmpriv);

        pmpriv->bss_role = bss->param.bss_role;
        if (pmpriv->bss_type == MLAN_BSS_TYPE_UAP)
            pmpriv->bss_type = MLAN_BSS_TYPE_STA;
        else if (pmpriv->bss_type == MLAN_BSS_TYPE_STA)
            pmpriv->bss_type = MLAN_BSS_TYPE_UAP;

        /* Initialize private structures */
        wlan_init_priv(pmpriv);

        /* Initialize function table */
        for (j = 0; mlan_ops[j]; j++)
        {
            if (mlan_ops[j]->bss_role == GET_BSS_ROLE(pmpriv))
            {
                (void)__memcpy(pmadapter, &pmpriv->ops, mlan_ops[j], sizeof(mlan_operations));
            }
        }

        for (i = 0; i < pmadapter->priv_num; i++)
        {
            if (pmadapter->priv[i] && GET_BSS_ROLE(pmadapter->priv[i]) == MLAN_BSS_ROLE_STA)
                global_band |= pmadapter->priv[i]->config_bands;
        }

        if (global_band != pmadapter->config_bands)
        {
            if (wlan_set_regiontable(pmpriv, (t_u8)pmadapter->region_code, global_band | pmadapter->adhoc_start_band))
            {
                pioctl_req->status_code = MLAN_ERROR_IOCTL_FAIL;
                LEAVE();
                return MLAN_STATUS_FAILURE;
            }

            if (wlan_11d_set_universaltable(pmpriv, global_band | pmadapter->adhoc_start_band))
            {
                pioctl_req->status_code = MLAN_ERROR_IOCTL_FAIL;
                LEAVE();
                return MLAN_STATUS_FAILURE;
            }
            pmadapter->config_bands = global_band;
        }

        /* Issue commands to initialize firmware */
#if defined(WIFI_DIRECT_SUPPORT)
        if (GET_BSS_ROLE(pmpriv) == MLAN_BSS_ROLE_STA)
            bss_mode = BSS_MODE_WIFIDIRECT_CLIENT;
        else
            bss_mode = BSS_MODE_WIFIDIRECT_GO;
        wlan_prepare_cmd(pmpriv, HostCmd_CMD_SET_BSS_MODE, HostCmd_ACT_GEN_SET, 0, MNULL, &bss_mode);
#endif
        pmpriv->ops.init_cmd(pmpriv, MFALSE);

        /* Issue dummy Get command to complete the ioctl */
        (void)__memset(pmadapter, &dummy, 0, sizeof(HostCmd_DS_VERSION_EXT));
        wlan_prepare_cmd(pmpriv, HostCmd_CMD_VERSION_EXT, HostCmd_ACT_GEN_GET, 0, (t_void *)pioctl_req,
                         (t_void *)&dummy);
        ret = MLAN_STATUS_PENDING;
    }

    LEAVE();
    return ret;
}
#endif

/**
 *  @brief Set the custom IE
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *  @param send_ioctl	Flag to indicate if ioctl should be sent with cmd
 *                      (MTRUE if from moal/user, MFALSE if internal)
 *
 *  @return		MLAN_STATUS_PENDING --success, otherwise fail
 */
mlan_status wlan_misc_ioctl_custom_ie_list(IN pmlan_adapter pmadapter,
                                           IN pmlan_ioctl_req pioctl_req,
                                           IN t_bool send_ioctl)
{
    mlan_private *pmpriv   = pmadapter->priv[pioctl_req->bss_index];
    mlan_status ret        = MLAN_STATUS_SUCCESS;
    mlan_ds_misc_cfg *misc = (mlan_ds_misc_cfg *)pioctl_req->pbuf;
    custom_ie *ie_data     = MNULL;
    t_u16 cmd_action       = 0, index, mask, i, len, app_data_len, ioctl_len;
    t_u8 *tmp_ie;

    ENTER();

    if ((misc->param.cust_ie.len == 0) || (misc->param.cust_ie.len == sizeof(t_u16)))
    {
        pioctl_req->action = MLAN_ACT_GET;
        /* Get the IE */
        cmd_action = HostCmd_ACT_GEN_GET;
    }
    else
    {
        /* ioctl_len : ioctl length from application, start with
           misc->param.cust_ie.len and reach upto 0 */
        ioctl_len = misc->param.cust_ie.len;

        /* app_data_len : length from application, start with 0 and reach upto
           ioctl_len */
        app_data_len            = sizeof(MrvlIEtypesHeader_t);
        misc->param.cust_ie.len = 0;

        while (ioctl_len > 0)
        {
            ie_data = (custom_ie *)(((t_u8 *)&misc->param.cust_ie) + app_data_len);
            ioctl_len -= (ie_data->ie_length + MLAN_CUSTOM_IE_HDR_SIZE);
            app_data_len += (ie_data->ie_length + MLAN_CUSTOM_IE_HDR_SIZE);

            index = ie_data->ie_index;
            mask  = ie_data->mgmt_subtype_mask;
            if (MLAN_CUSTOM_IE_AUTO_IDX_MASK == index)
            {     /* Need to be
                     Autohandled */
                if (mask == MLAN_CUSTOM_IE_DELETE_MASK)
                { /* Automatic
                     Deletion */
                    ret = wlan_custom_ioctl_auto_delete(pmpriv, pioctl_req, ie_data, index);
                    /* if IE to delete is not found, return error */
                    if (ret == MLAN_STATUS_FAILURE)
                    {
                        goto done;
                    }
                    (void)__memset(pmadapter, ie_data, 0, sizeof(custom_ie) * MAX_MGMT_IE_INDEX_TO_FW);
                    len = 0;
                    for (i = 0; i < pmadapter->max_mgmt_ie_index; i++)
                    {
                        (void)__memcpy(pmadapter, (t_u8 *)ie_data + len, &i, sizeof(ie_data->ie_index));
                        len += sizeof(ie_data->ie_index);
                        (void)__memcpy(pmadapter, (t_u8 *)ie_data + len, &pmpriv->mgmt_ie[i].mgmt_subtype_mask,
                                       sizeof(ie_data->mgmt_subtype_mask));
                        len += sizeof(ie_data->mgmt_subtype_mask);
                        (void)__memcpy(pmadapter, (t_u8 *)ie_data + len, &pmpriv->mgmt_ie[i].ie_length,
                                       sizeof(ie_data->ie_length));
                        len += sizeof(ie_data->ie_length);
                        if (pmpriv->mgmt_ie[i].ie_length)
                        {
                            (void)__memcpy(pmadapter, (t_u8 *)ie_data + len, &pmpriv->mgmt_ie[i].ie_buffer,
                                           pmpriv->mgmt_ie[i].ie_length);
                            len += pmpriv->mgmt_ie[i].ie_length;
                        }
                    }
                    misc->param.cust_ie.len += len;
                    pioctl_req->action = MLAN_ACT_SET;
                    cmd_action         = HostCmd_ACT_GEN_SET;
                }
                else
                { /* Automatic Addition */
                    if (MLAN_STATUS_FAILURE == wlan_custom_ioctl_get_autoidx(pmpriv, pioctl_req, mask, ie_data, &index))
                    {
                        PRINTM(MERROR, "Failed to Set the IE buffer\n");
                        ret = MLAN_STATUS_FAILURE;
                        goto done;
                    }
                    if (MLAN_CUSTOM_IE_AUTO_IDX_MASK == index)
                    {
                        ret = MLAN_STATUS_SUCCESS;
                        goto done;
                    }
                    tmp_ie = (t_u8 *)&pmpriv->mgmt_ie[index].ie_buffer;
                    (void)__memcpy(pmadapter, tmp_ie + pmpriv->mgmt_ie[index].ie_length, &ie_data->ie_buffer,
                                   ie_data->ie_length);
                    pmpriv->mgmt_ie[index].ie_length += ie_data->ie_length;
                    pmpriv->mgmt_ie[index].ie_index          = index;
                    pmpriv->mgmt_ie[index].mgmt_subtype_mask = mask;

                    pioctl_req->action = MLAN_ACT_SET;
                    cmd_action         = HostCmd_ACT_GEN_SET;
                    ie_data->ie_index  = index;
                    ie_data->ie_length = pmpriv->mgmt_ie[index].ie_length;
                    (void)__memcpy(pmadapter, &ie_data->ie_buffer, &pmpriv->mgmt_ie[index].ie_buffer,
                                   pmpriv->mgmt_ie[index].ie_length);
                    misc->param.cust_ie.len += pmpriv->mgmt_ie[index].ie_length + MLAN_CUSTOM_IE_HDR_SIZE;
                }
            }
            else
            {
                if (index >= pmadapter->max_mgmt_ie_index)
                {
                    PRINTM(MERROR, "Invalid custom IE index %d\n", index);
                    ret = MLAN_STATUS_FAILURE;
                    goto done;
                }
                /* Set/Clear the IE and save it */
                if (ie_data->mgmt_subtype_mask == MLAN_CUSTOM_IE_DELETE_MASK && ie_data->ie_length)
                {
                    PRINTM(MINFO, "Clear the IE buffer\n");
                    ret = wlan_custom_ioctl_auto_delete(pmpriv, pioctl_req, ie_data, index);
                    /* if IE to delete is not found, return error */
                    if (ret == MLAN_STATUS_FAILURE)
                    {
                        goto done;
                    }
                    (void)__memset(pmadapter, ie_data, 0, sizeof(custom_ie) * MAX_MGMT_IE_INDEX_TO_FW);
                    (void)__memcpy(pmadapter, (t_u8 *)ie_data, &pmpriv->mgmt_ie[index],
                                   pmpriv->mgmt_ie[index].ie_length + MLAN_CUSTOM_IE_HDR_SIZE);
                }
                else
                {
                    /*
                     * Check if this index is being used on any other
                     * interfaces. If yes, then the request needs to be rejected.
                     */
                    ret = wlan_is_custom_ie_index_unused(pmpriv, index);
                    if (ret == MLAN_STATUS_FAILURE)
                    {
                        PRINTM(MERROR, "IE index is used by other interface.\n");
                        PRINTM(MERROR, "Set or delete on index %d is not allowed.\n", index);
                        pioctl_req->status_code = MLAN_ERROR_IOCTL_FAIL;
                        goto done;
                    }
                    PRINTM(MINFO, "Set the IE buffer\n");
                    if (ie_data->mgmt_subtype_mask == MLAN_CUSTOM_IE_DELETE_MASK)
                        ie_data->ie_length = 0;
                    else
                    {
                        if ((pmpriv->mgmt_ie[index].ie_length == ie_data->ie_length) &&
                            !__memcmp(pmpriv->adapter, pmpriv->mgmt_ie[index].ie_buffer, ie_data->ie_buffer,
                                      pmpriv->mgmt_ie[index].ie_length))
                        {
                            PRINTM(MIOCTL, "same customer ie already configured!\n");
                            goto done;
                        }
                    }
                    (void)__memset(pmadapter, &pmpriv->mgmt_ie[index], 0, sizeof(custom_ie));
                    (void)__memcpy(pmadapter, &pmpriv->mgmt_ie[index], ie_data, sizeof(custom_ie));
                }

                misc->param.cust_ie.len += pmpriv->mgmt_ie[index].ie_length + MLAN_CUSTOM_IE_HDR_SIZE;
                pioctl_req->action = MLAN_ACT_SET;
                cmd_action         = HostCmd_ACT_GEN_SET;
            }
        }
    }

    /* Send command to firmware */
    if (GET_BSS_ROLE(pmpriv) == MLAN_BSS_ROLE_STA)
    {
        ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_MGMT_IE_LIST, cmd_action, 0,
                               (send_ioctl) ? (t_void *)pioctl_req : MNULL, &misc->param.cust_ie);
    }
#ifdef UAP_SUPPORT
    else if (GET_BSS_ROLE(pmpriv) == MLAN_BSS_ROLE_UAP)
    {
        ret =
            wlan_prepare_cmd(pmpriv, HOST_CMD_APCMD_SYS_CONFIGURE, cmd_action, 0,
                             (send_ioctl) ? (t_void *)pioctl_req : MNULL, (send_ioctl) ? MNULL : &misc->param.cust_ie);
    }
#endif
    if (ret == MLAN_STATUS_SUCCESS)
        ret = MLAN_STATUS_PENDING;
done:
    LEAVE();
    return ret;
}
#endif /* CONFIG_MLAN_WMSDK */

/**
 *  @brief This function will check if station list is empty
 *
 *  @param priv    A pointer to mlan_private
 *
 *  @return	   MFALSE/MTRUE
 */
t_u8 wlan_is_station_list_empty(mlan_private *priv)
{
    ENTER();
    if (!(util_peek_list(priv->adapter->pmoal_handle, &priv->sta_list, priv->adapter->callbacks.moal_spin_lock,
                         priv->adapter->callbacks.moal_spin_unlock)))
    {
        LEAVE();
        return MTRUE;
    }
    LEAVE();
    return MFALSE;
}

/**
 *  @brief This function will return the pointer to station entry in station list
 *  		table which matches the give mac address
 *
 *  @param priv    A pointer to mlan_private
 *  @param mac     mac address to find in station list table
 *
 *  @return	   A pointer to structure sta_node
 */
sta_node *wlan_get_station_entry(mlan_private *priv, t_u8 *mac)
{
    sta_node *sta_ptr;

    ENTER();

    if (!mac)
    {
        LEAVE();
        return MNULL;
    }
    if (!(sta_ptr = (sta_node *)util_peek_list(priv->adapter->pmoal_handle, &priv->sta_list,
                                               priv->adapter->callbacks.moal_spin_lock,
                                               priv->adapter->callbacks.moal_spin_unlock)))
    {
        LEAVE();
        return MNULL;
    }
    while (sta_ptr != (sta_node *)&priv->sta_list)
    {
        if (!__memcmp(priv->adapter, sta_ptr->mac_addr, mac, MLAN_MAC_ADDR_LENGTH))
        {
            LEAVE();
            return sta_ptr;
        }
        sta_ptr = sta_ptr->pnext;
    }
    LEAVE();
    return MNULL;
}

/**
 *  @brief This function will add a pointer to station entry in station list
 *  		table with the give mac address, if it does not exist already
 *
 *  @param priv    A pointer to mlan_private
 *  @param mac     mac address to find in station list table
 *
 *  @return	   A pointer to structure sta_node
 */
sta_node *wlan_add_station_entry(mlan_private *priv, t_u8 *mac)
{
    sta_node *sta_ptr       = MNULL;
    mlan_adapter *pmadapter = priv->adapter;

    ENTER();
    pmadapter->callbacks.moal_spin_lock(pmadapter->pmoal_handle, priv->wmm.ra_list_spinlock);

    sta_ptr = wlan_get_station_entry(priv, mac);
    if (sta_ptr)
        goto done;
    if (priv->adapter->callbacks.moal_malloc(priv->adapter->pmoal_handle, sizeof(sta_node), MLAN_MEM_DEF,
                                             (t_u8 **)&sta_ptr))
    {
        PRINTM(MERROR, "Failed to allocate memory for station node\n");
        LEAVE();
        return MNULL;
    }
    (void)__memset(priv->adapter, sta_ptr, 0, sizeof(sta_node));
    (void)__memcpy(priv->adapter, sta_ptr->mac_addr, mac, MLAN_MAC_ADDR_LENGTH);
    util_enqueue_list_tail(priv->adapter->pmoal_handle, &priv->sta_list, (pmlan_linked_list)sta_ptr,
                           priv->adapter->callbacks.moal_spin_lock, priv->adapter->callbacks.moal_spin_unlock);
done:
    pmadapter->callbacks.moal_spin_unlock(pmadapter->pmoal_handle, priv->wmm.ra_list_spinlock);
    LEAVE();
    return sta_ptr;
}

/**
 *  @brief This function will delete a station entry from station list
 *
 *
 *  @param priv    A pointer to mlan_private
 *  @param mac     station's mac address
 *
 *  @return	   N/A
 */
t_void wlan_delete_station_entry(mlan_private *priv, t_u8 *mac)
{
    sta_node *sta_ptr       = MNULL;
    mlan_adapter *pmadapter = priv->adapter;
    ENTER();
    pmadapter->callbacks.moal_spin_lock(pmadapter->pmoal_handle, priv->wmm.ra_list_spinlock);
    if ((sta_ptr = wlan_get_station_entry(priv, mac)))
    {
        util_unlink_list(priv->adapter->pmoal_handle, &priv->sta_list, (pmlan_linked_list)sta_ptr,
                         priv->adapter->callbacks.moal_spin_lock, priv->adapter->callbacks.moal_spin_unlock);
        priv->adapter->callbacks.moal_mfree(priv->adapter->pmoal_handle, (t_u8 *)sta_ptr);
    }
    pmadapter->callbacks.moal_spin_unlock(pmadapter->pmoal_handle, priv->wmm.ra_list_spinlock);
    LEAVE();
    return;
}

/**
 *  @brief Clean up wapi station list
 *
 *  @param priv  Pointer to the mlan_private driver data struct
 *
 *  @return      N/A
 */
t_void wlan_delete_station_list(pmlan_private priv)
{
    sta_node *sta_ptr;

    ENTER();
    while ((sta_ptr = (sta_node *)util_dequeue_list(priv->adapter->pmoal_handle, &priv->sta_list,
                                                    priv->adapter->callbacks.moal_spin_lock,
                                                    priv->adapter->callbacks.moal_spin_unlock)))
    {
        priv->adapter->callbacks.moal_mfree(priv->adapter->pmoal_handle, (t_u8 *)sta_ptr);
    }
    LEAVE();
    return;
}

#if !CONFIG_MLAN_WMSDK
/**
 *  @brief Get extended version information
 *
 *  @param pmadapter    A pointer to mlan_adapter structure
 *  @param pioctl_req   A pointer to ioctl request buffer
 *
 *  @return             MLAN_STATUS_PENDING --success, otherwise fail
 */
mlan_status wlan_get_info_ver_ext(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    pmlan_private pmpriv    = pmadapter->priv[pioctl_req->bss_index];
    mlan_ds_get_info *pinfo = (mlan_ds_get_info *)pioctl_req->pbuf;
    mlan_status ret         = MLAN_STATUS_SUCCESS;

    ENTER();

    /* Send request to firmware */
    ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_VERSION_EXT, HostCmd_ACT_GEN_GET, 0, (t_void *)pioctl_req,
                           &pinfo->param.ver_ext.version_str_sel);

    if (ret == MLAN_STATUS_SUCCESS)
        ret = MLAN_STATUS_PENDING;

    LEAVE();
    return ret;
}

#ifdef DEBUG_LEVEL1
/**
 *  @brief Set driver debug bit masks in order to enhance performance
 *
 *  @param pmadapter    A pointer to mlan_adapter structure
 *  @param pioctl_req   A pointer to ioctl request buffer
 *
 *  @return             MLAN_STATUS_PENDING --success, otherwise fail
 */
mlan_status wlan_set_drvdbg(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    mlan_ds_misc_cfg *misc = (mlan_ds_misc_cfg *)pioctl_req->pbuf;
    mlan_status ret        = MLAN_STATUS_SUCCESS;

    ENTER();

    /* Set driver debug bit masks */
    drvdbg = misc->param.drvdbg;

    LEAVE();
    return ret;
}
#endif

/**
 *  @brief Rx mgmt frame forward register
 *
 *  @param pmadapter    A pointer to mlan_adapter structure
 *  @param pioctl_req   A pointer to ioctl request buffer
 *
 *  @return             MLAN_STATUS_PENDING --success, otherwise fail
 */
mlan_status wlan_reg_rx_mgmt_ind(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    pmlan_private pmpriv   = pmadapter->priv[pioctl_req->bss_index - 1];
    mlan_ds_misc_cfg *misc = (mlan_ds_misc_cfg *)pioctl_req->pbuf;
    mlan_status ret        = MLAN_STATUS_SUCCESS;

    ENTER();

    /* Set passthru mask for mgmt frame */
    pmpriv->mgmt_frame_passthru_mask = misc->param.mgmt_subtype_mask;

    /* Send request to firmware */
    ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_RX_MGMT_IND, pioctl_req->action, 0, (t_void *)pioctl_req,
                           &misc->param.mgmt_subtype_mask);

    if (ret == MLAN_STATUS_SUCCESS)
        ret = MLAN_STATUS_PENDING;

    LEAVE();
    return ret;
}
#endif /* CONFIG_MLAN_WMSDK */

#if CONFIG_P2P
extern void wifi_wfd_event(bool peer_event, bool action_frame, void *data);
#define ZERO_BUF_LEN 8
#endif

/**
 *   @brief This function processes the 802.11 mgmt Frame
 *
 *   @param priv      A pointer to mlan_private
 *   @param payload   A pointer to the received buffer
 *   @param payload_len Length of the received buffer
 *
 *   @return        MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
mlan_status wlan_process_802dot11_mgmt_pkt(IN mlan_private *priv, IN t_u8 *payload, IN t_u32 payload_len, RxPD *rxpd)
{
    mlan_status ret                   = MLAN_STATUS_SUCCESS;
    wlan_802_11_header *pieee_pkt_hdr = MNULL;
    t_u16 sub_type                    = 0;
#if CONFIG_P2P
    pmlan_adapter pmadapter = priv->adapter;
    pmlan_callbacks pcb     = &pmadapter->callbacks;
    t_u8 *event_buf         = MNULL;
    mlan_event_p2p *pevent  = MNULL;
    t_u8 unicast            = 0;
    t_u8 zero_buf[8]        = {0, 0, 0, 0, 0, 0, 0, 0};
#endif
    ENTER();
#if CONFIG_P2P
    if (payload_len > (MAX_EVENT_SIZE - sizeof(mlan_event_p2p)))
    {
        PRINTM(MERROR, "Dropping large mgmt frame,len =%d\n", payload_len);
        LEAVE();
        return ret;
    }
#endif
    /* Check packet type-subtype and compare with mgmt_passthru_mask If event
       is needed to host, just eventify it */
    pieee_pkt_hdr = (wlan_802_11_header *)payload;
    sub_type      = IEEE80211_GET_FC_MGMT_FRAME_SUBTYPE(pieee_pkt_hdr->frm_ctl);
    if ((((1 << sub_type) & priv->mgmt_frame_passthru_mask) == 0) && (sub_type != SUBTYPE_ACTION))
    {
        PRINTM(MINFO, "Dropping mgmt frame for subtype %d.\n", sub_type);
        LEAVE();
        return ret;
    }
    switch (sub_type)
    {
        case SUBTYPE_ACTION:
            ret = wlan_process_mgmt_action(payload, payload_len, rxpd);
            if (ret == MLAN_STATUS_SUCCESS)
            {
                return ret;
            }
            break;
        case SUBTYPE_ASSOC_REQUEST:
        case SUBTYPE_REASSOC_REQUEST:
        case SUBTYPE_DISASSOC:
        case SUBTYPE_DEAUTH:
        case SUBTYPE_AUTH:
        case SUBTYPE_PROBE_RESP:
#if CONFIG_P2P
            unicast = MTRUE;
#endif
            break;
        default:
            PRINTM(MINFO, "Unexpected pkt subtype \n");
            break;
    }
#if CONFIG_P2P
    if (unicast == MTRUE)
    {
        if (__memcmp(pmadapter, pieee_pkt_hdr->addr1, priv->curr_p2p_addr, MLAN_MAC_ADDR_LENGTH))
        {
            PRINTM(MINFO, "Dropping mgmt frame for others: type=%d %02x:%02x:%02x:%02x:%02x:%02x\n", sub_type,
                   pieee_pkt_hdr->addr1[0], pieee_pkt_hdr->addr1[1], pieee_pkt_hdr->addr1[2], pieee_pkt_hdr->addr1[3],
                   pieee_pkt_hdr->addr1[4], pieee_pkt_hdr->addr1[5]);
            LEAVE();
            return ret;
        }
    }
    /* Allocate memory for event buffer */
    ret = pcb->moal_malloc(pmadapter->pmoal_handle, MAX_P2P_EVENT_SIZE, MLAN_MEM_DEF, &event_buf);
    if ((ret != MLAN_STATUS_SUCCESS) || !event_buf)
    {
        PRINTM(MERROR, "Could not allocate buffer for event buf\n");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }
    pevent = (pmlan_event_p2p)event_buf;
    pevent->event_len =
        payload_len - sizeof(wlan_802_11_header) + sizeof(pevent->event_len) + ZERO_BUF_LEN + MLAN_MAC_ADDR_LENGTH;
    pevent->event_len = wlan_cpu_to_le32(pevent->event_len);
    (void)__memcpy(pmadapter, (t_u8 *)pevent->event_buf, (t_u8 *)&pevent->event_len, sizeof(pevent->event_len));
    (void)__memcpy(pmadapter, (t_u8 *)pevent->event_buf + sizeof(pevent->event_len), (t_u8 *)zero_buf, ZERO_BUF_LEN);
    (void)__memcpy(pmadapter, (t_u8 *)pevent->event_buf + sizeof(pevent->event_len) + ZERO_BUF_LEN,
                   (t_u8 *)pieee_pkt_hdr->addr2, MLAN_MAC_ADDR_LENGTH);
    (void)__memcpy(pmadapter,
                   (t_u8 *)(pevent->event_buf + sizeof(pevent->event_len) + ZERO_BUF_LEN + MLAN_MAC_ADDR_LENGTH),
                   payload + sizeof(wlan_802_11_header), payload_len - sizeof(wlan_802_11_header));

    wifi_wfd_event(false, true, (void *)pevent);
    /* wlan_recv_event(priv, MLAN_EVENT_ID_DRV_MGMT_FRAME, pevent);
    if (event_buf)
        pcb->moal_mfree(pmadapter->pmoal_handle, event_buf);*/
#endif /* CONFIG_P2P */
    LEAVE();
    return ret;
}

mlan_status wlan_bypass_802dot11_mgmt_pkt(void *data)
{
    RxPD *rxpd                        = (RxPD *)data;
    wlan_mgmt_pkt *pmgmt_pkt_hdr      = NULL;
    t_u16 sub_type                    = 0;
    wlan_802_11_header *pieee_pkt_hdr = MNULL;
    t_u8 category                     = 0;
    mlan_private *priv                = mlan_adap->priv[0];
    mlan_status ret                   = MLAN_STATUS_SUCCESS;

    pmgmt_pkt_hdr = (wlan_mgmt_pkt *)((t_u8 *)rxpd + rxpd->rx_pkt_offset);
    pieee_pkt_hdr = (wlan_802_11_header *)&pmgmt_pkt_hdr->wlan_header;
    sub_type      = IEEE80211_GET_FC_MGMT_FRAME_SUBTYPE(pieee_pkt_hdr->frm_ctl);
    // coverity[overrun-local:SUPPRESS]
    category = *((t_u8 *)pieee_pkt_hdr + sizeof(wlan_802_11_header));

    if ((pmgmt_pkt_hdr->wlan_header.frm_ctl & IEEE80211_FC_MGMT_FRAME_TYPE_MASK) == 0)
    {
        if ((((1 << sub_type) & priv->mgmt_frame_passthru_mask) == 0) && (sub_type != SUBTYPE_ACTION))
        {
            PRINTM(MINFO, "Dropping mgmt frame for subtype %d.\n", sub_type);
            LEAVE();
            return ret;
        }

        if (sub_type == SUBTYPE_ACTION)
        {
            if (category == IEEE_MGMT_ACTION_CATEGORY_BLOCK_ACK)
            {
                PRINTM(MINFO, "Dropping mgmt frame for category %d.\n", category);
                LEAVE();
                return ret;
            }
        }
    }

    ret = MLAN_STATUS_FAILURE;
    return ret;
}

#if !CONFIG_MLAN_WMSDK
/**
 *  @brief Set hotspot enable/disable
 *
 *  @param pmadapter    A pointer to mlan_adapter structure
 *  @param pioctl_req   A pointer to ioctl request buffer
 *
 *  @return             MLAN_STATUS_PENDING --success, otherwise fail
 */
mlan_status wlan_misc_hotspot_cfg(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    pmlan_private pmpriv   = pmadapter->priv[pioctl_req->bss_index];
    mlan_ds_misc_cfg *misc = (mlan_ds_misc_cfg *)pioctl_req->pbuf;
    mlan_status ret        = MLAN_STATUS_SUCCESS;

    ENTER();

    if (MLAN_ACT_GET == pioctl_req->action)
        misc->param.hotspot_cfg = pmpriv->hotspot_cfg;
    else if (MLAN_ACT_SET == pioctl_req->action)
        pmpriv->hotspot_cfg = misc->param.hotspot_cfg;

    LEAVE();
    return ret;
}
#endif /* CONFIG_MLAN_WMSDK */

/**
 *  @brief Add Extended Capabilities IE
 *
 *  @param pmpriv             A pointer to mlan_private structure
 *  @param pptlv_out          A pointer to TLV to fill in
 *  @param BSSDescriptor      A poiter to bss descriptor
 *  @return                   N/A
 */
void wlan_add_ext_capa_info_ie(IN mlan_private *pmpriv, IN BSSDescriptor_t *pbss_desc, OUT t_u8 **pptlv_out)
{
    MrvlIETypes_ExtCap_t *pext_cap = MNULL;

    ENTER();

    pext_cap = (MrvlIETypes_ExtCap_t *)(void *)*pptlv_out;
    (void)__memset(pmpriv->adapter, pext_cap, 0, sizeof(MrvlIETypes_ExtCap_t));
    pext_cap->header.type = wlan_cpu_to_le16(EXT_CAPABILITY);
    pext_cap->header.len  = wlan_cpu_to_le16(sizeof(ExtCap_t));
    if ((((t_u8)(pmpriv->hotspot_cfg >> 8)) & HOTSPOT_ENABLE_INTERWORKING_IND) != 0U)
    {
        pext_cap->ext_cap.Interworking = 1;
    }
    if ((((t_u8)(pmpriv->hotspot_cfg >> 8)) & HOTSPOT_ENABLE_TDLS_IND) != 0U)
    {
        pext_cap->ext_cap.TDLSSupport = 1;
    }

#if (CONFIG_WNM_PS)
    if ((((mlan_private *)mlan_adap->priv[0])->wnm_set == true) && (pbss_desc != MNULL) &&
        (pbss_desc->pext_cap->ext_cap.WNM_Sleep == true))
    {
        pext_cap->ext_cap.WNM_Sleep = 1;
    }
    else
    {
        pext_cap->ext_cap.WNM_Sleep = 0;
    }
#endif
#if CONFIG_11AX
#if CONFIG_MULTI_BSSID_SUPPORT
    if (pbss_desc && pbss_desc->multi_bssid_ap)
        SET_EXTCAP_MULTI_BSSID(pext_cap->ext_cap);
#endif
    if (wlan_check_11ax_twt_supported(pmpriv, pbss_desc))
        SET_EXTCAP_TWT_REQ(pext_cap->ext_cap);
#endif
#if CONFIG_11V
    pext_cap->ext_cap.BSS_Transition = 1;
#endif
#if CONFIG_11MC
    pext_cap->ext_cap.FTMI          = 1;
    pext_cap->ext_cap.CivicLocation = 1;
#endif

    *pptlv_out += sizeof(MrvlIETypes_ExtCap_t);

    LEAVE();
}

#if !CONFIG_MLAN_WMSDK
/**
 *  @brief Get OTP user data
 *
 *  @param pmadapter    A pointer to mlan_adapter structure
 *  @param pioctl_req   A pointer to ioctl request buffer
 *
 *  @return             MLAN_STATUS_PENDING --success, otherwise fail
 */
mlan_status wlan_misc_otp_user_data(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    pmlan_private pmpriv   = pmadapter->priv[pioctl_req->bss_index];
    mlan_ds_misc_cfg *misc = (mlan_ds_misc_cfg *)pioctl_req->pbuf;
    mlan_status ret        = MLAN_STATUS_FAILURE;

    ENTER();

    if (misc->param.otp_user_data.user_data_length > MAX_OTP_USER_DATA_LEN)
    {
        PRINTM(MERROR, "Invalid OTP user data length\n");
        pioctl_req->status_code = MLAN_ERROR_INVALID_PARAMETER;
        LEAVE();
        return ret;
    }

    ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_OTP_READ_USER_DATA, HostCmd_ACT_GEN_GET, 0, (t_void *)pioctl_req,
                           &misc->param.otp_user_data);

    if (ret == MLAN_STATUS_SUCCESS)
        ret = MLAN_STATUS_PENDING;

    LEAVE();
    return ret;
}

/**
 *  @brief This function will search for the specific ie
 *
 *
 *  @param priv    A pointer to mlan_private
 *  @param ie_buf  A pointer to ie_buf
 *  @param ie_len  total ie length
 *  @param id      ie's id
 *
 *  @return	       ie's poiner or MNULL
 */
t_u8 *wlan_get_specific_ie(pmlan_private priv, t_u8 *ie_buf, t_u8 ie_len, IEEEtypes_ElementId_e id)
{
    t_u32 bytes_left   = ie_len;
    t_u8 *pcurrent_ptr = ie_buf;
    t_u16 total_ie_len;
    t_u8 *ie_ptr = MNULL;
    IEEEtypes_ElementId_e element_id;
    t_u8 element_len;

    ENTER();

    DBG_HEXDUMP(MCMD_D, "ie", ie_buf, ie_len);
    while (bytes_left >= 2)
    {
        element_id   = (IEEEtypes_ElementId_e)(*((t_u8 *)pcurrent_ptr));
        element_len  = *((t_u8 *)pcurrent_ptr + 1);
        total_ie_len = element_len + sizeof(IEEEtypes_Header_t);
        if (bytes_left < total_ie_len)
        {
            PRINTM(MERROR,
                   "InterpretIE: Error in processing IE, "
                   "bytes left < IE length\n");
            break;
        }
        if (element_id == id)
        {
            PRINTM(MCMND, "Find IE: id=%d\n", id);
            DBG_HEXDUMP(MCMND, "IE", pcurrent_ptr, total_ie_len);
            ie_ptr = pcurrent_ptr;
            break;
        }
        pcurrent_ptr += element_len + 2;
        /* Need to account for IE ID and IE Len */
        bytes_left -= (element_len + 2);
    }

    LEAVE();

    return ie_ptr;
}

/**
 *  @brief Get pm info
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		        MLAN_STATUS_SUCCESS --success
 */
mlan_status wlan_get_pm_info(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    mlan_status ret        = MLAN_STATUS_SUCCESS;
    mlan_ds_pm_cfg *pm_cfg = MNULL;
    pmlan_callbacks pcb    = &pmadapter->callbacks;

    ENTER();

    pm_cfg                                   = (mlan_ds_pm_cfg *)pioctl_req->pbuf;
    pm_cfg->param.ps_info.is_suspend_allowed = MTRUE;
    if (util_peek_list(pmadapter->pmoal_handle, &pmadapter->cmd_pending_q, pcb->moal_spin_lock,
                       pcb->moal_spin_unlock) ||
        pmadapter->curr_cmd || !wlan_bypass_tx_list_empty(pmadapter) || !wlan_wmm_lists_empty(pmadapter) ||
        pmadapter->sdio_ireg)
    {
        pm_cfg->param.ps_info.is_suspend_allowed = MFALSE;
        PRINTM(MIOCTL, "PM: cmd_pending_q=%p,curr_cmd=%p,wmm_list_empty=%d, by_pass=%d sdio_ireg=0x%x\n",
               util_peek_list(pmadapter->pmoal_handle, &pmadapter->cmd_pending_q, pcb->moal_spin_lock,
                              pcb->moal_spin_unlock),
               pmadapter->curr_cmd, wlan_wmm_lists_empty(pmadapter), wlan_bypass_tx_list_empty(pmadapter),
               pmadapter->sdio_ireg);
    }
    LEAVE();
    return ret;
}

/**
 *  @brief Get hs wakeup reason
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		        MLAN_STATUS_SUCCESS --success
 */
mlan_status wlan_get_hs_wakeup_reason(pmlan_adapter pmadapter, pmlan_ioctl_req pioctl_req)
{
    pmlan_private pmpriv   = pmadapter->priv[pioctl_req->bss_index];
    pmlan_ds_pm_cfg pm_cfg = MNULL;
    mlan_status ret        = MLAN_STATUS_FAILURE;

    ENTER();

    pm_cfg = (mlan_ds_pm_cfg *)pioctl_req->pbuf;

    /* Send command to firmware */
    ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_HS_WAKEUP_REASON, HostCmd_ACT_GEN_GET, 0, (t_void *)pioctl_req,
                           &pm_cfg->param.wakeup_reason);

    if (ret == MLAN_STATUS_SUCCESS)
        ret = MLAN_STATUS_PENDING;

    LEAVE();
    return ret;
}

/**
 *  @brief Set/Get radio status
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_SUCCESS --success, otherwise fail
 */
mlan_status wlan_radio_ioctl_radio_ctl(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    mlan_status ret              = MLAN_STATUS_SUCCESS;
    mlan_ds_radio_cfg *radio_cfg = MNULL;
    t_u16 cmd_action             = 0;
    mlan_private *pmpriv         = pmadapter->priv[pioctl_req->bss_index];

    ENTER();

    radio_cfg = (mlan_ds_radio_cfg *)pioctl_req->pbuf;
    if (pioctl_req->action == MLAN_ACT_SET)
    {
        if (pmadapter->radio_on == radio_cfg->param.radio_on_off)
        {
            ret = MLAN_STATUS_SUCCESS;
            goto exit;
        }
        else
        {
            if (pmpriv->media_connected == MTRUE)
            {
                ret = MLAN_STATUS_FAILURE;
                goto exit;
            }
            cmd_action = HostCmd_ACT_GEN_SET;
        }
    }
    else
        cmd_action = HostCmd_ACT_GEN_GET;

    /* Send request to firmware */
    ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_802_11_RADIO_CONTROL, cmd_action, 0, (t_void *)pioctl_req,
                           &radio_cfg->param.radio_on_off);

    if (ret == MLAN_STATUS_SUCCESS)
        ret = MLAN_STATUS_PENDING;

exit:
    LEAVE();
    return ret;
}

/**
 *  @brief Set/Get antenna configuration
 *
 *  @param pmadapter    A pointer to mlan_adapter structure
 *  @param pioctl_req   A pointer to ioctl request buffer
 *
 *  @return     MLAN_STATUS_PENDING --success, otherwise fail
 */
mlan_status wlan_radio_ioctl_ant_cfg(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    mlan_status ret              = MLAN_STATUS_SUCCESS;
    mlan_private *pmpriv         = pmadapter->priv[pioctl_req->bss_index];
    mlan_ds_radio_cfg *radio_cfg = MNULL;
    t_u16 cmd_action             = 0;
    t_u16 *ant_cfg;

    ENTER();

    radio_cfg = (mlan_ds_radio_cfg *)pioctl_req->pbuf;

    if (pioctl_req->action == MLAN_ACT_SET)
    {
        /* User input validation */
        if ((!radio_cfg->param.antenna || radio_cfg->param.antenna & ~RF_ANTENNA_MASK(pmadapter->number_of_antenna)) &&
            (radio_cfg->param.antenna != RF_ANTENNA_AUTO || pmadapter->number_of_antenna <= 1))
        {
            PRINTM(MERROR, "Invalid antenna setting\n");
            pioctl_req->status_code = MLAN_ERROR_INVALID_PARAMETER;
            ret                     = MLAN_STATUS_FAILURE;
            goto exit;
        }
        cmd_action = HostCmd_ACT_GEN_SET;
    }
    else
        cmd_action = HostCmd_ACT_GEN_GET;

    /* Cast it to t_u16, antenna mode for command HostCmd_CMD_802_11_RF_ANTENNA
       requires 2 bytes */
    ant_cfg = (t_u16 *)&radio_cfg->param.antenna;

    /* Send request to firmware */
    ret =
        wlan_prepare_cmd(pmpriv, HostCmd_CMD_802_11_RF_ANTENNA, cmd_action, 0, (t_void *)pioctl_req, (t_void *)ant_cfg);

    if (ret == MLAN_STATUS_SUCCESS)
        ret = MLAN_STATUS_PENDING;

exit:
    LEAVE();
    return ret;
}

/**
 *  @brief Get rate value
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_SUCCESS/MLAN_STATUS_PENDING --success, otherwise fail
 */
static mlan_status wlan_rate_ioctl_get_rate_value(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    mlan_ds_rate *rate   = MNULL;
    mlan_status ret      = MLAN_STATUS_SUCCESS;
    mlan_private *pmpriv = pmadapter->priv[pioctl_req->bss_index];

    ENTER();

    rate                              = (mlan_ds_rate *)pioctl_req->pbuf;
    rate->param.rate_cfg.is_rate_auto = pmpriv->is_data_rate_auto;
    pioctl_req->data_read_written     = sizeof(mlan_rate_cfg_t) + MLAN_SUB_COMMAND_SIZE;

    /* If not connected, set rate to the lowest in each band */
    if (pmpriv->media_connected != MTRUE)
    {
        if (pmpriv->config_bands & (BAND_B | BAND_G))
        {
            /* Return the lowest supported rate for BG band */
            rate->param.rate_cfg.rate = SupportedRates_BG[0] & 0x7f;
        }
        else if (pmpriv->config_bands & (BAND_A | BAND_B))
        {
            /* Return the lowest supported rate for A band */
            rate->param.rate_cfg.rate = SupportedRates_BG[0] & 0x7f;
        }
        else if (pmpriv->config_bands & BAND_A)
        {
            /* Return the lowest supported rate for A band */
            rate->param.rate_cfg.rate = SupportedRates_A[0] & 0x7f;
        }
        else if (pmpriv->config_bands & BAND_G)
        {
            /* Return the lowest supported rate for G band */
            rate->param.rate_cfg.rate = SupportedRates_G[0] & 0x7f;
        }
        else if (pmpriv->config_bands & BAND_B)
        {
            /* Return the lowest supported rate for B band */
            rate->param.rate_cfg.rate = SupportedRates_B[0] & 0x7f;
        }
        else if (pmpriv->config_bands & BAND_GN)
        {
            /* Return the lowest supported rate for N band */
            rate->param.rate_cfg.rate = SupportedRates_N[0] & 0x7f;
        }
        else
        {
            PRINTM(MMSG, "Invalid Band 0x%x\n", pmpriv->config_bands);
        }
    }
    else
    {
        /* Send request to firmware */
        ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_802_11_TX_RATE_QUERY, HostCmd_ACT_GEN_GET, 0, (t_void *)pioctl_req,
                               MNULL);
        if (ret == MLAN_STATUS_SUCCESS)
            ret = MLAN_STATUS_PENDING;
    }

    LEAVE();
    return ret;
}

/**
 *  @brief Set rate value
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_PENDING --success, otherwise fail
 */
static mlan_status wlan_rate_ioctl_set_rate_value(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    mlan_ds_rate *ds_rate = MNULL;
    WLAN_802_11_RATES rates;
    t_u8 *rate     = MNULL;
    int rate_index = 0;
    t_u16 bitmap_rates[MAX_BITMAP_RATES_SIZE];
    t_u32 i              = 0;
    mlan_status ret      = MLAN_STATUS_SUCCESS;
    mlan_private *pmpriv = pmadapter->priv[pioctl_req->bss_index];

    ENTER();

    ds_rate = (mlan_ds_rate *)pioctl_req->pbuf;

    if (ds_rate->param.rate_cfg.is_rate_auto)
    {
        (void)__memset(pmadapter, bitmap_rates, 0, sizeof(bitmap_rates));
        /* Support all HR/DSSS rates */
        bitmap_rates[0] = 0x000F;
        /* Support all OFDM rates */
        bitmap_rates[1] = 0x00FF;
        /* Support all HT-MCSs rate */
        for (i = 0; i < NELEMENTS(pmpriv->bitmap_rates) - 3; i++)
            bitmap_rates[i + 2] = 0xFFFF;
        bitmap_rates[9] = 0x3FFF;
    }
    else
    {
        (void)__memset(pmadapter, rates, 0, sizeof(rates));
        wlan_get_active_data_rates(
            pmpriv, pmpriv->bss_mode,
            (pmpriv->bss_mode == MLAN_BSS_MODE_INFRA) ? pmpriv->config_bands : pmadapter->adhoc_start_band, rates);
        rate = rates;
        for (i = 0; (rate[i] && i < WLAN_SUPPORTED_RATES); i++)
        {
            PRINTM(MINFO, "Rate=0x%X  Wanted=0x%X\n", rate[i], ds_rate->param.rate_cfg.rate);
            if ((rate[i] & 0x7f) == (ds_rate->param.rate_cfg.rate & 0x7f))
                break;
        }
        if (!rate[i] || (i == WLAN_SUPPORTED_RATES))
        {
            PRINTM(MERROR,
                   "The fixed data rate 0x%X is out "
                   "of range\n",
                   ds_rate->param.rate_cfg.rate);
            pioctl_req->status_code = MLAN_ERROR_INVALID_PARAMETER;
            ret                     = MLAN_STATUS_FAILURE;
            goto exit;
        }
        (void)__memset(pmadapter, bitmap_rates, 0, sizeof(bitmap_rates));

        rate_index = wlan_data_rate_to_index(pmadapter, ds_rate->param.rate_cfg.rate);

        /* Only allow b/g rates to be set */
        if (rate_index >= MLAN_RATE_INDEX_HRDSSS0 && rate_index <= MLAN_RATE_INDEX_HRDSSS3)
            bitmap_rates[0] = 1 << rate_index;
        else
        {
            rate_index -= 1; /* There is a 0x00 in the table */
            if (rate_index >= MLAN_RATE_INDEX_OFDM0 && rate_index <= MLAN_RATE_INDEX_OFDM7)
                bitmap_rates[1] = 1 << (rate_index - MLAN_RATE_INDEX_OFDM0);
        }
    }

    /* Send request to firmware */
    ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_TX_RATE_CFG, HostCmd_ACT_GEN_SET, 0, (t_void *)pioctl_req, bitmap_rates);
    if (ret == MLAN_STATUS_SUCCESS)
        ret = MLAN_STATUS_PENDING;

exit:
    LEAVE();
    return ret;
}
#endif /* CONFIG_MLAN_WMSDK */

/**
 *  @brief Get rate index
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_PENDING --success, otherwise fail
 */
static mlan_status wlan_rate_ioctl_get_rate_index(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    mlan_status ret      = MLAN_STATUS_SUCCESS;
    mlan_private *pmpriv = pmadapter->priv[pioctl_req->bss_index];

    ENTER();

    /* Send request to firmware */
    ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_TX_RATE_CFG, HostCmd_ACT_GEN_GET, 0, (t_void *)pioctl_req, MNULL);

    if (ret == MLAN_STATUS_SUCCESS)
    {
        ret = MLAN_STATUS_PENDING;
    }

    LEAVE();
    return ret;
}

/**
 *  @brief Set rate index
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_PENDING --success, otherwise fail
 */
static mlan_status wlan_rate_ioctl_set_rate_index(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    t_s32 rate_index;
    mlan_rate_format rate_format;
#if (CONFIG_11AC) || (CONFIG_11AX)
    t_u32 nss;
#endif
    t_u32 i;
    mlan_ds_rate *ds_rate = MNULL;
    mlan_status ret       = MLAN_STATUS_FAILURE;
    mlan_private *pmpriv  = pmadapter->priv[pioctl_req->bss_index];
    t_u16 bitmap_rates[MAX_BITMAP_RATES_SIZE];
    t_u16 shift_index = 1U;
#ifdef STREAM_2X2
#if 0
    int tx_mcs_supp = GET_TXMCSSUPP(pmpriv->usr_dev_mcs_support);
#endif
#endif

    ENTER();

    ds_rate = (mlan_ds_rate *)(void *)pioctl_req->pbuf;

    rate_format = ds_rate->param.rate_cfg.rate_format;
#if (CONFIG_11AC) || (CONFIG_11AX)
    nss = ds_rate->param.rate_cfg.nss;
#endif
    rate_index = (t_s32)ds_rate->param.rate_cfg.rate;

    if (ds_rate->param.rate_cfg.is_rate_auto == MTRUE)
    {
        (void)__memset(pmadapter, bitmap_rates, 0, sizeof(bitmap_rates));
        /* Rates talbe [0]: HR/DSSS;[1]: OFDM; [2..9] HT; */
        /* Support all HR/DSSS rates */
        bitmap_rates[0] = 0x000F;
        /* Support all OFDM rates */
        bitmap_rates[1] = 0x00FF;
        /* Support all HT-MCSs rate */
        for (i = 2; i < 9U; i++)
        {
            bitmap_rates[i] = 0xFFFF;
        }
        bitmap_rates[9] = 0x3FFF;
#if CONFIG_11AC
        /* [10..17] VHT */
#ifdef RW610
        /* RW610 only supports VHT MCS0 ~ MCS8*/
        bitmap_rates[10] = 0x01FF; /* 9 Bits valid */
        /* RW610 only supports 1 NSS*/
        bitmap_rates[11] = 0x0;
#else
        /* Support all VHT-MCSs rate for NSS 1 and 2 */
        for (i = 10; i < 12; i++)
        {
            bitmap_rates[i] = 0x03FF; /* 10 Bits valid */
        }
#endif
        /* Set to 0 as default value for all other NSSs */
        for (i = 12; i < NELEMENTS(bitmap_rates); i++)
        {
            bitmap_rates[i] = 0x0;
        }
#endif
#if CONFIG_11AX
        /* [18..25] HE */
#ifdef RW610
        /* RW610 only supports HE MCS0 ~ MCS9*/
        bitmap_rates[18] = 0x03FF; /* 10 Bits valid */
        /* RW610 only supports 1 NSS*/
        bitmap_rates[19] = 0x0;
#else
        /* Support all HE-MCSs rate for NSS1 and 2 */
        for (i = 18; i < 20; i++)
            bitmap_rates[i] = 0x0FFF;
#endif
        for (i = 20; i < NELEMENTS(bitmap_rates); i++)
            bitmap_rates[i] = 0x0;
#endif
    }
    else
    {
        PRINTM(MINFO, "Rate index is %d\n", rate_index);

#ifdef STREAM_2X2
#if 0
        if ((rate_format == MLAN_RATE_FORMAT_HT) &&
            (rate_index > MLAN_RATE_INDEX_MCS7 && rate_index <= MLAN_RATE_INDEX_MCS15) && (tx_mcs_supp < 2))
        {
            PRINTM(MERROR, "HW don't support 2x2, rate_index=%d hw_mcs_supp=0x%x\n", rate_index,
                   pmpriv->usr_dev_mcs_support);
            pioctl_req->status_code = MLAN_ERROR_INVALID_PARAMETER;
            LEAVE();
            return MLAN_STATUS_FAILURE;
        }
#endif
#endif

        (void)__memset(pmadapter, bitmap_rates, 0, sizeof(bitmap_rates));
        if (rate_format == MLAN_RATE_FORMAT_LG)
        {
            /* Bitmap of HR/DSSS rates */
            if (rate_index <= MLAN_RATE_INDEX_HRDSSS3)
            {
                bitmap_rates[0] = (shift_index << rate_index);
                ret             = MLAN_STATUS_SUCCESS;
                /* Bitmap of OFDM rates */
            }
            else if (rate_index <= MLAN_RATE_INDEX_OFDM7)
            {
                bitmap_rates[1] = (shift_index << (rate_index - MLAN_RATE_INDEX_OFDM0));
                ret             = MLAN_STATUS_SUCCESS;
            }
            else
            {
                /*Do Nothing*/
            }
        }
        else if (rate_format == MLAN_RATE_FORMAT_HT)
        {
            if (rate_index <= MLAN_RATE_INDEX_MCS32)
            {
#ifdef SD8801
                rate_index -= MLAN_RATE_INDEX_MCS0;
#endif
                bitmap_rates[2 + (rate_index / 16)] = (shift_index << (rate_index % 16));
                ret                                 = MLAN_STATUS_SUCCESS;
            }
        }
        else
        {
            /*DO Nothing*/
        }

#if CONFIG_11AC
        if (rate_format == MLAN_RATE_FORMAT_VHT)
        {
            if ((rate_index <= MLAN_RATE_INDEX_MCS9) && (MLAN_RATE_NSS1 <= nss) && (nss <= MLAN_RATE_NSS2))
            {
                bitmap_rates[10 + nss - MLAN_RATE_NSS1] = (shift_index << rate_index);
                ret                                     = MLAN_STATUS_SUCCESS;
            }
        }
#endif
#if CONFIG_11AX
        if (rate_format == MLAN_RATE_FORMAT_HE)
        {
            if (IS_FW_SUPPORT_11AX(pmadapter))
            {
                if ((rate_index <= MLAN_RATE_INDEX_MCS11) && (MLAN_RATE_NSS1 <= nss) && (nss <= MLAN_RATE_NSS2))
                {
                    bitmap_rates[18 + nss - MLAN_RATE_NSS1] = (1 << rate_index);
                    ret                                     = MLAN_STATUS_SUCCESS;
                }
            }
            else
            {
                PRINTM(MERROR, "Error! Fw doesn't support 11AX\n");
                LEAVE();
                return MLAN_STATUS_FAILURE;
            }
        }
#endif
        if (ret == MLAN_STATUS_FAILURE)
        {
            PRINTM(MERROR, "Invalid MCS index=%d. \n", rate_index);
            pioctl_req->status_code = MLAN_ERROR_INVALID_PARAMETER;
            LEAVE();
            return MLAN_STATUS_FAILURE;
        }
    }

    PRINTM(MINFO,
           "RateBitmap=%04x%04x%04x%04x%04x%04x%04x%04x"
           "%04x%04x%04x%04x%04x%04x%04x%04x%04x%04x, "
           "IsRateAuto=%d, DataRate=%d\n",
           bitmap_rates[17], bitmap_rates[16], bitmap_rates[15], bitmap_rates[14], bitmap_rates[13], bitmap_rates[12],
           bitmap_rates[11], bitmap_rates[10], bitmap_rates[9], bitmap_rates[8], bitmap_rates[7], bitmap_rates[6],
           bitmap_rates[5], bitmap_rates[4], bitmap_rates[3], bitmap_rates[2], bitmap_rates[1], bitmap_rates[0],
           pmpriv->is_data_rate_auto, pmpriv->data_rate);

    /* Send request to firmware */
#if CONFIG_AUTO_NULL_TX
    if (ds_rate->auto_null_fixrate_enable == 1)
    {
        ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_TX_RATE_CFG, HostCmd_ACT_SPC_AUTO_SET, 0, (t_void *)pioctl_req,
                               bitmap_rates);
        ds_rate->auto_null_fixrate_enable = 0xff;
    }
    else if (ds_rate->auto_null_fixrate_enable == 0)
    {
        ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_TX_RATE_CFG, HostCmd_ACT_SPC_AUTO_NOSET, 0, (t_void *)pioctl_req,
                               bitmap_rates);
        ds_rate->auto_null_fixrate_enable = 0xff;
    }
    else
#endif
        ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_TX_RATE_CFG, HostCmd_ACT_GEN_SET, 0, (t_void *)pioctl_req,
                               (t_void *)bitmap_rates);

    if (ret == MLAN_STATUS_SUCCESS)
    {
        ret = MLAN_STATUS_PENDING;
    }

    LEAVE();
    return ret;
}

/**
 *  @brief Rate configuration command handler
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_SUCCESS/MLAN_STATUS_PENDING --success, otherwise fail
 */
mlan_status wlan_rate_ioctl_cfg(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
#if !CONFIG_MLAN_WMSDK
    mlan_ds_rate *rate = MNULL;
#endif /* CONFIG_MLAN_WMSDK */
    mlan_status status = MLAN_STATUS_SUCCESS;

    ENTER();

#if !CONFIG_MLAN_WMSDK
    rate = (mlan_ds_rate *)pioctl_req->pbuf;
    if (rate->param.rate_cfg.rate_type == MLAN_RATE_VALUE)
    {
        if (pioctl_req->action == MLAN_ACT_GET)
        {
            status = wlan_rate_ioctl_get_rate_value(pmadapter, pioctl_req);
        }
        else
        {
            status = wlan_rate_ioctl_set_rate_value(pmadapter, pioctl_req);
        }
    }
    else
    {
#endif /* CONFIG_MLAN_WMSDK */
        if (pioctl_req->action == MLAN_ACT_GET)
        {
            status = wlan_rate_ioctl_get_rate_index(pmadapter, pioctl_req);
        }
        else
        {
            status = wlan_rate_ioctl_set_rate_index(pmadapter, pioctl_req);
        }
#if !CONFIG_MLAN_WMSDK
    }
#endif /* CONFIG_MLAN_WMSDK */

    LEAVE();
    return status;
}

/**
 *  @brief This function prepares command of rf_antenna.
 *
 *  @param pmpriv   A pointer to mlan_private structure
 *  @param cmd      A pointer to HostCmd_DS_COMMAND structure
 *  @param cmd_action   The action: GET or SET
 *  @param pdata_buf    A pointer to data buffer
 *
 *  @return         MLAN_STATUS_SUCCESS
 */
mlan_status wlan_cmd_802_11_rf_antenna(IN pmlan_private pmpriv,
                                       IN HostCmd_DS_COMMAND *cmd,
                                       IN t_u16 cmd_action,
                                       IN t_void *pdata_buf)
{
    HostCmd_DS_802_11_RF_ANTENNA *pantenna = &cmd->params.antenna;
#ifdef STREAM_2X2
    mlan_ds_ant_cfg *ant_cfg = (mlan_ds_ant_cfg *)pdata_buf;
#else
    mlan_ds_ant_cfg_1x1 *ant_cfg_1x1 = (mlan_ds_ant_cfg_1x1 *)pdata_buf;
#endif

    ENTER();
    cmd->command = wlan_cpu_to_le16(HostCmd_CMD_802_11_RF_ANTENNA);
    cmd->size    = wlan_cpu_to_le16(sizeof(HostCmd_DS_802_11_RF_ANTENNA) + S_DS_GEN);

    if (cmd_action == HostCmd_ACT_GEN_SET)
    {
#ifdef STREAM_2X2
        pantenna->action_tx       = wlan_cpu_to_le16(HostCmd_ACT_SET_TX);
        pantenna->tx_antenna_mode = wlan_cpu_to_le16((t_u16)ant_cfg->tx_antenna);
        pantenna->action_rx       = wlan_cpu_to_le16(HostCmd_ACT_SET_RX);
        pantenna->rx_antenna_mode = wlan_cpu_to_le16((t_u16)ant_cfg->rx_antenna);
#else
        pantenna->action        = wlan_cpu_to_le16(HostCmd_ACT_SET_BOTH);
        pantenna->antenna_mode  = wlan_cpu_to_le16((t_u16)ant_cfg_1x1->antenna);
        pantenna->evaluate_time = wlan_cpu_to_le16((t_u16)ant_cfg_1x1->evaluate_time);
#ifdef RW610
        pantenna->evaluate_mode = wlan_cpu_to_le16((t_u8)ant_cfg_1x1->evaluate_mode);
#endif
#endif
    }
    else
    {
#ifdef STREAM_2X2
        pantenna->action_tx = wlan_cpu_to_le16(HostCmd_ACT_GET_TX);
        pantenna->action_rx = wlan_cpu_to_le16(HostCmd_ACT_GET_RX);
#else
        pantenna->action        = wlan_cpu_to_le16(HostCmd_ACT_GET_BOTH);
#endif
    }

    LEAVE();
    return MLAN_STATUS_SUCCESS;
}

#if CONFIG_NET_MONITOR
mlan_status wlan_cmd_802_11_net_monitor(IN pmlan_private pmpriv,
                                        IN HostCmd_DS_COMMAND *cmd,
                                        IN t_u16 cmd_action,
                                        IN t_void *pdata_buf)
{
    HostCmd_DS_802_11_NET_MONITOR *net_mon = &cmd->params.net_mon;
    wifi_net_monitor_t *monitor            = (wifi_net_monitor_t *)pdata_buf;
    ENTER();

    (void)__memset(pmpriv->adapter, net_mon, 0x00, sizeof(HostCmd_DS_802_11_NET_MONITOR));

    cmd->command = wlan_cpu_to_le16(HostCmd_CMD_802_11_NET_MONITOR);
    cmd->size    = wlan_cpu_to_le16(sizeof(HostCmd_DS_802_11_NET_MONITOR) + S_DS_GEN);

    if (cmd_action == HostCmd_ACT_GEN_SET)
    {
        net_mon->action                                         = wlan_cpu_to_le16(HostCmd_ACT_GEN_SET);
        net_mon->monitor_activity                               = wlan_cpu_to_le16(monitor->monitor_activity);
        net_mon->filter_flags                                   = wlan_cpu_to_le16(monitor->filter_flags);
        net_mon->monitor_channel.header.type                    = TLV_TYPE_UAP_CHAN_BAND_CONFIG;
        net_mon->monitor_channel.header.len                     = 2;
        net_mon->monitor_channel.chan_band_param[0].radio_type  = (t_u8)monitor->radio_type;
        net_mon->monitor_channel.chan_band_param[0].chan_number = (t_u8)monitor->chan_number;

        net_mon->monitor_filter.header.type = TLV_TYPE_UAP_STA_MAC_ADDR_FILTER;
        net_mon->monitor_filter.header.len  = MLAN_MAC_ADDR_LENGTH * monitor->filter_num + sizeof(t_u8);
        net_mon->monitor_filter.filter_num  = (t_u8)monitor->filter_num;
        __memcpy(priv->adapter, (t_u8 *)net_mon->monitor_filter.mac_list, (t_u8 *)monitor->mac_addr,
                 MAX_MONIT_MAC_FILTER_NUM * MLAN_MAC_ADDR_LENGTH);
    }
    else
    {
        net_mon->action = wlan_cpu_to_le16(HostCmd_ACT_GEN_GET);
    }
    LEAVE();
    return MLAN_STATUS_SUCCESS;
}
#endif

#if !CONFIG_MLAN_WMSDK
/**
 *  @brief This function handles the command response of rf_antenna
 *
 *  @param pmpriv       A pointer to mlan_private structure
 *  @param resp         A pointer to HostCmd_DS_COMMAND
 *  @param pioctl_buf   A pointer to mlan_ioctl_req structure
 *
 *  @return             MLAN_STATUS_SUCCESS
 */
mlan_status wlan_ret_802_11_rf_antenna(IN pmlan_private pmpriv,
                                       IN HostCmd_DS_COMMAND *resp,
                                       IN mlan_ioctl_req *pioctl_buf)
{
    HostCmd_DS_802_11_RF_ANTENNA *pantenna = &resp->params.antenna;
    t_u16 ant_mode                         = wlan_le16_to_cpu(pantenna->antenna_mode);
    mlan_ds_radio_cfg *radio               = MNULL;

    ENTER();

    PRINTM(MINFO, "RF_ANT_RESP: action = 0x%x, Mode = 0x%04x\n", wlan_le16_to_cpu(pantenna->action), ant_mode);

    if (pioctl_buf)
    {
        radio                = (mlan_ds_radio_cfg *)pioctl_buf->pbuf;
        radio->param.antenna = ant_mode;
    }

    LEAVE();
    return MLAN_STATUS_SUCCESS;
}

#ifdef WIFI_DIRECT_SUPPORT
/**
 *  @brief Set/Get wifi_direct_mode
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_SUCCESS --success, otherwise fail
 */
mlan_status wlan_bss_ioctl_wifi_direct_mode(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    mlan_status ret  = MLAN_STATUS_SUCCESS;
    mlan_ds_bss *bss = MNULL;

    t_u16 cmd_action     = 0;
    mlan_private *pmpriv = pmadapter->priv[pioctl_req->bss_index];

    ENTER();

    bss = (mlan_ds_bss *)pioctl_req->pbuf;

    if (pioctl_req->action == MLAN_ACT_SET)
        cmd_action = HostCmd_ACT_GEN_SET;
    else
        cmd_action = HostCmd_ACT_GEN_GET;

    /* Send request to firmware */
    ret = wlan_prepare_cmd(pmpriv, HOST_CMD_WIFI_DIRECT_MODE_CONFIG, cmd_action, 0, (t_void *)pioctl_req,
                           &bss->param.wfd_mode);

    if (ret == MLAN_STATUS_SUCCESS)
        ret = MLAN_STATUS_PENDING;

    LEAVE();
    return ret;
}

/**
 *  @brief Set/Get remain on channel setting
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_SUCCESS --success, otherwise fail
 */
mlan_status wlan_radio_ioctl_remain_chan_cfg(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    mlan_status ret              = MLAN_STATUS_SUCCESS;
    mlan_ds_radio_cfg *radio_cfg = MNULL;
    t_u16 cmd_action             = 0;
    mlan_private *pmpriv         = pmadapter->priv[pioctl_req->bss_index];

    ENTER();

    radio_cfg = (mlan_ds_radio_cfg *)pioctl_req->pbuf;
    if (pioctl_req->action == MLAN_ACT_SET)
        cmd_action = HostCmd_ACT_GEN_SET;
    else
        cmd_action = HostCmd_ACT_GEN_GET;

    /* Send request to firmware */
    ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_802_11_REMAIN_ON_CHANNEL, cmd_action, 0, (t_void *)pioctl_req,
                           &radio_cfg->param.remain_chan);

    if (ret == MLAN_STATUS_SUCCESS)
        ret = MLAN_STATUS_PENDING;

    LEAVE();
    return ret;
}
#endif

#endif /* CONFIG_MLAN_WMSDK */

#ifdef WLAN_LOW_POWER_ENABLE
/**
 *  @brief Set/Get Low Power Mode
 *
 *  @param pmadapter    A pointer to mlan_adapter structure
 *  @param pioctl_req   A pointer to ioctl request buffer
 *
 *  @return             MLAN_STATUS_SUCCESS
 */
mlan_status wlan_misc_ioctl_low_pwr_mode(IN pmlan_adapter pmadapter, IN pmlan_ioctl_req pioctl_req)
{
    mlan_status ret        = MLAN_STATUS_SUCCESS;
    mlan_ds_misc_cfg *misc = MNULL;
    mlan_private *pmpriv   = pmadapter->priv[pioctl_req->bss_index];

    ENTER();

    misc = (mlan_ds_misc_cfg *)pioctl_req->pbuf;

    /* Send request to firmware */
    ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_LOW_POWER_MODE, HostCmd_ACT_GEN_SET, 0, (t_void *)pioctl_req,
                           &misc->param.low_pwr_mode);

    if (ret == MLAN_STATUS_SUCCESS)
        ret = MLAN_STATUS_PENDING;

    LEAVE();
    return ret;
}
#endif // WLAN_LOW_POWER_ENABLE

#if CONFIG_WIFI_CLOCKSYNC
/**
 *  @brief Set/Get GPIO TSF Latch config
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_SUCCESS --success, otherwise fail
 */
mlan_status wlan_misc_gpio_tsf_latch_config(pmlan_adapter pmadapter, pmlan_ioctl_req pioctl_req)
{
    mlan_status ret            = MLAN_STATUS_SUCCESS;
    mlan_ds_misc_cfg *misc_cfg = MNULL;
    t_u16 cmd_action           = 0;
    mlan_private *pmpriv       = pmadapter->priv[pioctl_req->bss_index];

    ENTER();

    misc_cfg = (mlan_ds_misc_cfg *)pioctl_req->pbuf;
    if (pioctl_req->action == MLAN_ACT_SET)
        cmd_action = HostCmd_ACT_GEN_SET;
    else
        cmd_action = HostCmd_ACT_GEN_GET;

    /* Send request to firmware */
    ret = wlan_prepare_cmd(pmpriv, HostCmd_GPIO_TSF_LATCH_PARAM_CONFIG, cmd_action, 0, (t_void *)pioctl_req,
                           &misc_cfg->param.gpio_tsf_latch_config);

    LEAVE();
    return ret;
}

/**
 *  @brief Get TSF info
 *
 *  @param pmadapter	A pointer to mlan_adapter structure
 *  @param pioctl_req	A pointer to ioctl request buffer
 *
 *  @return		MLAN_STATUS_SUCCESS --success, otherwise fail
 */
mlan_status wlan_misc_get_tsf_info(pmlan_adapter pmadapter, pmlan_ioctl_req pioctl_req)
{
    mlan_status ret            = MLAN_STATUS_SUCCESS;
    mlan_ds_misc_cfg *misc_cfg = MNULL;
    t_u16 cmd_action           = 0;
    mlan_private *pmpriv       = pmadapter->priv[pioctl_req->bss_index];

    ENTER();

    misc_cfg   = (mlan_ds_misc_cfg *)pioctl_req->pbuf;
    cmd_action = HostCmd_ACT_GEN_GET;

    /* Send request to firmware */
    ret = wlan_prepare_cmd(pmpriv, HostCmd_GPIO_TSF_LATCH_PARAM_CONFIG, cmd_action, 0, (t_void *)pioctl_req,
                           &misc_cfg->param.tsf_info);

    LEAVE();
    return ret;
}
#endif /* CONFIG_WIFI_CLOCKSYNC */

#if CONFIG_ECSA
/**
 *  @brief Get non-global operating class
 *
 *  @param pmadapter    A pointer to mlan_adapter structure
 *  @param pioctl_req   Pointer to the IOCTL request buffer
 *
 *  @return             MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
mlan_status wlan_misc_ioctl_oper_class(pmlan_adapter pmadapter, mlan_ioctl_req *pioctl_req)
{
    pmlan_private pmpriv   = pmadapter->priv[pioctl_req->bss_index];
    mlan_ds_misc_cfg *misc = MNULL;
    t_u8 channel, bandwidth, oper_class = 0;
    mlan_status ret = MLAN_STATUS_SUCCESS;

    ENTER();

    misc    = (mlan_ds_misc_cfg *)pioctl_req->pbuf;
    channel = misc->param.bw_chan_oper.channel;
    switch (misc->param.bw_chan_oper.bandwidth)
    {
        case 20:
            bandwidth = BW_20MHZ;
            break;
        case 40:
            bandwidth = BW_40MHZ;
            break;
        case 80:
            bandwidth = BW_80MHZ;
            break;
        default:
            bandwidth = BW_20MHZ;
            break;
    }

    if (pioctl_req->action == MLAN_ACT_GET)
    {
        ret                                 = wlan_get_curr_oper_class(pmpriv, channel, bandwidth, &oper_class);
        misc->param.bw_chan_oper.oper_class = oper_class;
    }
    else
    {
        PRINTM(MERROR, "Unsupported cmd_action\n");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }

    LEAVE();
    return ret;
}

/**
 *  @brief Check operating class validation
 *
 *  @param pmadapter    A pointer to mlan_adapter structure
 *  @param pioctl_req   Pointer to the IOCTL request buffer
 *
 *  @return             MLAN_STATUS_SUCCESS or MLAN_STATUS_FAILURE
 */
mlan_status wlan_misc_ioctl_operclass_validation(pmlan_adapter pmadapter, mlan_ioctl_req *pioctl_req)
{
    pmlan_private pmpriv   = pmadapter->priv[pioctl_req->bss_index];
    mlan_ds_misc_cfg *misc = MNULL;
    t_u8 channel, oper_class;
    mlan_status ret = MLAN_STATUS_SUCCESS;

    ENTER();

    misc       = (mlan_ds_misc_cfg *)pioctl_req->pbuf;
    channel    = misc->param.bw_chan_oper.channel;
    oper_class = misc->param.bw_chan_oper.oper_class;
    if (pioctl_req->action == MLAN_ACT_GET)
    {
        ret = wlan_check_operclass_validation(pmpriv, channel, oper_class);
    }
    else
    {
        PRINTM(MERROR, "Unsupported cmd_action\n");
        LEAVE();
        return MLAN_STATUS_FAILURE;
    }

    LEAVE();
    return ret;
}
#endif

#if CONFIG_RF_TEST_MODE
/**
 *  @brief RF Test Mode config
 *
 *  @param pmadapter   A pointer to mlan_adapter structure
 *  @param pioctl_req  A pointer to ioctl request buffer
 *
 *  @return        MLAN_STATUS_PENDING --success, otherwise fail
 */
mlan_status wlan_misc_ioctl_rf_test_cfg(pmlan_adapter pmadapter, pmlan_ioctl_req pioctl_req)
{
    mlan_private *pmpriv    = MNULL;
    mlan_ds_misc_cfg *pmisc = MNULL;
    mlan_status ret         = MLAN_STATUS_FAILURE;
    t_u16 cmd_action        = 0;

    ENTER();

    if (!pioctl_req)
        goto done;

    pmpriv = pmadapter->priv[pioctl_req->bss_index];
    pmisc  = (mlan_ds_misc_cfg *)pioctl_req->pbuf;

    switch (pmisc->sub_command)
    {
        case MLAN_OID_MISC_RF_TEST_GENERIC:
            if (pioctl_req->action == MLAN_ACT_SET)
                cmd_action = HostCmd_ACT_GEN_SET;
            else
                cmd_action = HostCmd_ACT_GEN_GET;
            ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_MFG_COMMAND, cmd_action, 0, (t_void *)pioctl_req,
                                   &(pmisc->param.mfg_generic_cfg));
            break;
        case MLAN_OID_MISC_RF_TEST_TX_CONT:
            if (pioctl_req->action == MLAN_ACT_SET)
                cmd_action = HostCmd_ACT_GEN_SET;
            else
            {
                PRINTM(MERROR, "Unsupported cmd_action\n");
                ret = MLAN_STATUS_FAILURE;
                goto done;
            }
            ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_MFG_COMMAND, cmd_action, 0, (t_void *)pioctl_req,
                                   &(pmisc->param.mfg_tx_cont));
            break;
        case MLAN_OID_MISC_RF_TEST_TX_FRAME:
            if (pioctl_req->action == MLAN_ACT_SET)
                cmd_action = HostCmd_ACT_GEN_SET;
            else
            {
                PRINTM(MERROR, "Unsupported cmd_action\n");
                ret = MLAN_STATUS_FAILURE;
                goto done;
            }
            ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_MFG_COMMAND, cmd_action, 0, (t_void *)pioctl_req,
                                   &(pmisc->param.mfg_tx_frame2));
            break;
        case MLAN_OID_MISC_RF_TEST_CONFIG_TRIGGER_FRAME:
            if (pioctl_req->action == MLAN_ACT_SET)
                cmd_action = HostCmd_ACT_GEN_SET;
            else
            {
                PRINTM(MERROR, "Unsupported cmd_action\n");
                ret = MLAN_STATUS_FAILURE;
                goto done;
            }
            ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_MFG_COMMAND, cmd_action, 0, (t_void *)pioctl_req,
                                   &(pmisc->param.mfg_tx_trigger_config));
            break;

        case MLAN_OID_MISC_RF_TEST_HE_POWER:
            if (pioctl_req->action == MLAN_ACT_SET)
                cmd_action = HostCmd_ACT_GEN_SET;
            else
            {
                PRINTM(MERROR, "Unsupported cmd_action\n");
                ret = MLAN_STATUS_FAILURE;
                goto done;
            }
            ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_MFG_COMMAND, cmd_action, 0, (t_void *)pioctl_req,
                                   &(pmisc->param.mfg_he_power));
            break;
    }

    if (ret == MLAN_STATUS_SUCCESS)
        ret = MLAN_STATUS_PENDING;
done:
    LEAVE();
    return ret;
}
#endif

#if (CONFIG_WIFI_IND_RESET) && (CONFIG_WIFI_IND_DNLD)
/**
 *  @brief Configure GPIO independent reset
 *
 *  @param pmadapter    A pointer to mlan_adapter structure
 *  @param pioctl_req   A pointer to ioctl request buffer
 *
 *  @return             MLAN_STATUS_PENDING --success, otherwise fail
 */
mlan_status wlan_misc_ioctl_ind_rst_cfg(pmlan_adapter pmadapter, pmlan_ioctl_req pioctl_req)
{
    mlan_private *pmpriv   = pmadapter->priv[pioctl_req->bss_index];
    mlan_ds_misc_cfg *misc = (mlan_ds_misc_cfg *)pioctl_req->pbuf;
    mlan_status ret        = MLAN_STATUS_SUCCESS;
    t_u16 cmd_action       = 0;

    ENTER();

    if (pioctl_req->action == MLAN_ACT_GET)
        cmd_action = HostCmd_ACT_GEN_GET;
    else
        cmd_action = HostCmd_ACT_GEN_SET;

    /* Send request to firmware */
    ret = wlan_prepare_cmd(pmpriv, HostCmd_CMD_INDEPENDENT_RESET_CFG, cmd_action, 0, (t_void *)pioctl_req,
                           (t_void *)&misc->param.ind_rst_cfg);

    LEAVE();
    return ret;
}
#endif
