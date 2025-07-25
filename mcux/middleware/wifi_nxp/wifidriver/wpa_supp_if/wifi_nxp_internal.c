/** @file wifi_nxp_internal.c
 *
 * @brief This file provides Core Wi-Fi definition for wpa supplicant rtos driver.
 *
 * Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdlib.h>
#include <string.h>
#include <osa.h>
#include <wm_net.h>
#include <wifi.h>
#include <wifi_nxp.h>
#include <wifi-internal.h>
#include <wifi-debug.h>

#if CONFIG_WPA_SUPP

#include <rtos_wpa_supp_if.h>
#include "supp_main.h"

void wifi_survey_result_get(struct wifi_message *msg)
{
    nxp_wifi_trigger_op_t *wifi_survey_params = (nxp_wifi_trigger_op_t *)msg->data;

#if CONFIG_WPA_SUPP_AP
    wm_wifi.hostapd_op = false;

    if (wifi_survey_params->hostapd)
    {
        wm_wifi.hostapd_op = true;
    }
#endif

    wifi_nxp_survey_res_get();
    OSA_MemoryFree(wifi_survey_params);
}

/* Event handlers*/
void wifi_scan_start(struct wifi_message *msg)
{
    struct wifi_nxp_ctx_rtos *wifi_if_ctx_rtos = (struct wifi_nxp_ctx_rtos *)wm_wifi.if_priv;

    if (!wifi_if_ctx_rtos || !wm_wifi.supp_if_callbk_fns)
       return;

    if (wifi_if_ctx_rtos->scan_in_progress)
    {
        if (msg->reason == WIFI_EVENT_REASON_SUCCESS)
        {
            if (wm_wifi.supp_if_callbk_fns->scan_start_callbk_fn)
            {
                wm_wifi.supp_if_callbk_fns->scan_start_callbk_fn(wm_wifi.if_priv);
            }
        }
    }
}

void wifi_scan_done(struct wifi_message *msg)
{
    struct wifi_nxp_ctx_rtos *wifi_if_ctx_rtos = NULL;

#if CONFIG_WPA_SUPP_AP
    if (wm_wifi.hostapd_op)
    {
        wifi_if_ctx_rtos = (struct wifi_nxp_ctx_rtos *)wm_wifi.hapd_if_priv;

        wm_wifi.hostapd_op = false;
    }
    else
#endif
    {
        wifi_if_ctx_rtos = (struct wifi_nxp_ctx_rtos *)wm_wifi.if_priv;
    }

    if (!wifi_if_ctx_rtos || !wm_wifi.supp_if_callbk_fns)
       return;

    if (msg->reason == WIFI_EVENT_REASON_FAILURE)
    {
        if (wm_wifi.supp_if_callbk_fns->scan_done_callbk_fn)
        {
            wm_wifi.supp_if_callbk_fns->scan_done_callbk_fn(wm_wifi.if_priv, 1, 0);
        }
    }

    if (msg->reason == WIFI_EVENT_REASON_SUCCESS)
    {
        if (wm_wifi.supp_if_callbk_fns->scan_done_callbk_fn)
        {
#if CONFIG_WPA_SUPP_AP
            if (wifi_if_ctx_rtos->hostapd)
            {
                wm_wifi.supp_if_callbk_fns->scan_done_callbk_fn(wm_wifi.hapd_if_priv, 0, wm_wifi.external_scan);
            }
            else
#endif
            {
                wm_wifi.supp_if_callbk_fns->scan_done_callbk_fn(wm_wifi.if_priv, 0, wm_wifi.external_scan);
            }
        }
    }

    wm_wifi.external_scan = false;
}

void wifi_process_remain_on_channel(struct wifi_message *msg)
{
    struct wifi_nxp_ctx_rtos *wifi_if_ctx_rtos = (struct wifi_nxp_ctx_rtos *)wm_wifi.if_priv;

    if (!wifi_if_ctx_rtos || !wm_wifi.supp_if_callbk_fns)
       return;

    if (wifi_if_ctx_rtos->supp_called_remain_on_chan == true)
    {
        if ((msg->reason == WIFI_EVENT_REASON_SUCCESS) &&
            (wm_wifi.supp_if_callbk_fns->remain_on_channel_callbk_fn != NULL))
        {
            if (*(t_u8 *)(msg->data) == true)
            {
                wm_wifi.supp_if_callbk_fns->remain_on_channel_callbk_fn(wifi_if_ctx_rtos, 1);
            }
            else
            {
                wm_wifi.supp_if_callbk_fns->remain_on_channel_callbk_fn(wifi_if_ctx_rtos, 0);
            }
        }
        wifi_if_ctx_rtos->supp_called_remain_on_chan = false;
    }
    if (msg->data)
    {
        OSA_MemoryFree(msg->data);
        msg->data = NULL;
    }
}

void wifi_process_mgmt_tx_status(struct wifi_message *msg)
{
    nxp_wifi_event_mlme_t *resp = &wm_wifi.mgmt_resp;
    resp->frame.frame_len       = 0;

    if (msg->reason == WIFI_EVENT_REASON_SUCCESS)
    {
        if (wm_wifi.supp_if_callbk_fns->mgmt_tx_status_callbk_fn)
        {
            if ((t_u32)(msg->data) == MLAN_BSS_TYPE_UAP)
            {
                wm_wifi.supp_if_callbk_fns->mgmt_tx_status_callbk_fn(wm_wifi.hapd_if_priv, resp, resp->frame.frame_len);
            }
            else
            {
                wm_wifi.supp_if_callbk_fns->mgmt_tx_status_callbk_fn(wm_wifi.if_priv, resp, resp->frame.frame_len);
            }
        }
    }
    else
    {
#if CONFIG_ROAMING
        wlan_subscribe_rssi_low_event();
#endif
    }
}

int wifi_setup_ht_cap(t_u16 *ht_capab, t_u8 *pmcs_set, t_u8 *a_mpdu_params, t_u8 band)
{
    mlan_adapter *pmadapter = (mlan_adapter *)mlan_adap;
    t_u32 usr_dot_11n_dev_cap;
    int rx_mcs_supp;
    t_u8 mcs_set[NUM_MCS_FIELD];

    ENTER();

    *ht_capab = HT_CAP_INFO_DSSS_CCK40MHZ;

    *a_mpdu_params = 3;

#if CONFIG_5GHz_SUPPORT
    if (band == BAND_5GHZ)
    {
        usr_dot_11n_dev_cap = pmadapter->usr_dot_11n_dev_cap_a;
    }
    else
#endif
    {
        usr_dot_11n_dev_cap = pmadapter->usr_dot_11n_dev_cap_bg;
    }

    if (ISSUPP_RXLDPC(usr_dot_11n_dev_cap))
    {
        *ht_capab |= HT_CAP_INFO_LDPC_CODING_CAP;
    }
    if (ISSUPP_CHANWIDTH40(usr_dot_11n_dev_cap))
    {
        *ht_capab |= HT_CAP_INFO_SUPP_CHANNEL_WIDTH_SET;
    }
    else
    {
        *ht_capab &= ~(HT_CAP_INFO_DSSS_CCK40MHZ);
    }
    if ((usr_dot_11n_dev_cap >> 20) & 0x03) /* Delayed ACK supported */
    {
        *ht_capab |= HT_CAP_INFO_DELAYED_BA;
    }
    if (ISSUPP_GREENFIELD(usr_dot_11n_dev_cap))
    {
        *ht_capab |= HT_CAP_INFO_GREEN_FIELD;
    }
    if (ISSUPP_SHORTGI20(usr_dot_11n_dev_cap))
    {
        *ht_capab |= HT_CAP_INFO_SHORT_GI20MHZ;
    }
    if (ISSUPP_SHORTGI40(usr_dot_11n_dev_cap))
    {
        *ht_capab |= HT_CAP_INFO_SHORT_GI40MHZ;
    }
    if (ISSUPP_TXSTBC(usr_dot_11n_dev_cap))
    {
        *ht_capab |= HT_CAP_INFO_TX_STBC;
    }
    if (ISSUPP_RXSTBC(usr_dot_11n_dev_cap))
    {
        *ht_capab |= HT_CAP_INFO_RX_STBC_1;
    }
    if (ISSUPP_MIMOPS(usr_dot_11n_dev_cap))
    {
        *ht_capab |= HT_CAP_INFO_SMPS_STATIC;
    }
    else
    {
        *ht_capab |= HT_CAP_INFO_SMPS_DISABLED;
    }
    if (ISSUPP_MAXAMSDU(usr_dot_11n_dev_cap))
    {
        *ht_capab |= HT_CAP_INFO_MAX_AMSDU_SIZE;
    }
    if (ISENABLED_40MHZ_INTOLARENT(usr_dot_11n_dev_cap))
    {
        *ht_capab |= HT_CAP_INFO_40MHZ_INTOLERANT;
    }

    rx_mcs_supp = GET_RXMCSSUPP(pmadapter->usr_dev_mcs_support);
    /* Set MCS for 1x1/2x2 */
    memset((t_u8 *)mcs_set, 0xff, rx_mcs_supp);
    /* Clear all the other values */
    memset((t_u8 *)&mcs_set[rx_mcs_supp], 0, NUM_MCS_FIELD - rx_mcs_supp);
    /* Set MCS32 with 40MHz support */
    if (ISSUPP_CHANWIDTH40(usr_dot_11n_dev_cap))
        SETHT_MCS32(mcs_set);

    memcpy(pmcs_set, mcs_set, NUM_MCS_FIELD);

    LEAVE();

    return WM_SUCCESS;
}

static void wifi_setup_channel_flag(void *channels, int num_chan, region_chan_t *region, t_u8 band)
{
    int i;
    int set_idx                             = 0;
    int get_idx                             = 0;
    const chan_freq_power_t *pchans_get     = region->pcfp;
    struct wifi_nxp_event_channel *pchans_set = (struct wifi_nxp_event_channel *)channels;

    for (i = 0; i < MAX(num_chan, region->num_cfp); i++)
    {
        if (set_idx >= num_chan)
            break;

        if (get_idx >= region->num_cfp)
        {
            pchans_set[set_idx].wifi_nxp_flags |= WIFI_NXP_CHAN_FLAG_FREQUENCY_DISABLED;

            set_idx++;
        }
        else
        {
            pchans_set[set_idx].center_frequency = pchans_get[get_idx].freq;
            pchans_set[set_idx].ch_valid = 1;
            pchans_set[set_idx].wifi_nxp_max_power = pchans_get[get_idx].max_tx_power;
            pchans_set[set_idx].wifi_nxp_flags &= (~WIFI_NXP_CHAN_FLAG_FREQUENCY_DISABLED);

            if (band == BAND_2GHZ)
            {
                pchans_set[set_idx].wifi_nxp_flags |= WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_NO_80MHZ;
            }

            pchans_set[set_idx].wifi_nxp_flags |= WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_NO_160MHZ;

            /* set passive scan or radar detect flag */
            if (pchans_get[get_idx].passive_scan_or_radar_detect == MTRUE)
            {
                pchans_set[set_idx].wifi_nxp_flags |= WIFI_NXP_CHAN_FLAG_FREQUENCY_ATTR_RADAR;
                pchans_set[set_idx].wifi_nxp_flags |= WIFI_NXP_CHAN_DFS_VALID;
            }

            set_idx++;
            get_idx++;
        }
    }
}

void wifi_setup_channel_info(void *channels, int num_channels, t_u8 band)
{
    mlan_adapter *pmadapter = (mlan_adapter *)mlan_adap;
    region_chan_t *region   = NULL;

    if (band == BAND_2GHZ)
    {
        if (pmadapter->region_channel[0].valid)
            region = &pmadapter->region_channel[0];
        else if (pmadapter->universal_channel[0].valid)
            region = &pmadapter->universal_channel[0];
        else
            return;

        wifi_setup_channel_flag(channels, num_channels, region, band);
    }
    else if (band == BAND_5GHZ)
    {
        if (pmadapter->region_channel[1].valid)
            region = &pmadapter->region_channel[1];
        else if (pmadapter->universal_channel[1].valid)
            region = &pmadapter->universal_channel[1];
        else
            return;

        wifi_setup_channel_flag(channels, num_channels, region, band);
    }
    else
    {
        wuap_e("wifi_setup_channel_info unsupported band %d", band);
    }
}

#if CONFIG_11AC
int wifi_setup_vht_cap(t_u32 *vht_capab, t_u8 *vht_mcs_set, t_u8 band)
{
    mlan_adapter *pmadapter = (mlan_adapter *)mlan_adap;
    t_u16 vht_tx_mcs, vht_rx_mcs;

    ENTER();

    *vht_capab = pmadapter->usr_dot_11ac_dev_cap_a;

    *vht_capab &= ~DEFALUT_11AC_CAP_BEAMFORMING_RESET_MASK;
#if defined(RW610) || defined(IW610)
    *vht_capab &= ~DEFALUT_11AC_CAP_SHORTGI_80MHZ_RESET_MASK;
#endif

    if ((GET_VHTCAP_MAXMPDULEN(*vht_capab)) != 0U)
    {
        RESET_11ACMAXMPDULEN(*vht_capab);
    }
    else
    {
        /** Do Nothing */
    }

    vht_tx_mcs = pmadapter->usr_dot_11ac_mcs_support >> 16;
    vht_rx_mcs = pmadapter->usr_dot_11ac_mcs_support & 0xffff;

    memcpy(&vht_mcs_set[0], &vht_rx_mcs, sizeof(t_u16));

    memcpy(&vht_mcs_set[4], &vht_tx_mcs, sizeof(t_u16));

    LEAVE();

    return WM_SUCCESS;
}
#endif

#if CONFIG_11AX
/*
===============
11AX CAP for uAP
===============
Note: bits not mentioned below are set to 0.

5G
===
HE MAC Cap:
Bit0:  1  (+HTC HE Support)
Bit25: 1  (OM Control Support. But uAP does not support
           Tx OM received from the STA, as it does not support UL OFDMA)

HE PHY Cap:
Bit1-7: 0x2 (Supported Channel Width Set.
             Note it would be changed after 80+80 MHz is supported)
Bit8-11: 0x3 (Punctured Preamble Rx.
              Note: it would be changed after 80+80 MHz is supported)
Bit12: 0x0 (Device Class)
Bit13: 0x1 (LDPC coding in Payload)
Bit17: 0x1 (NDP with 4xHE-LTF+3.2usGI)
Bit18: 0x1 (STBC Tx <= 80 MHz)
Bit19: 0x1 (STBC Rx <= 80 MHz)
Bit20: 0x1 (Doppler Tx)
Bit21: 0x1 (Doppler Rx)
Bit24-25: 0x1 (DCM Max Constellation Tx)
Bit27-28: 0x1 (DCM Max Constellation Rx)
Bit31: 0x1 (SU Beamformer)
Bit32: 0x1 (SU BeamFormee)
Bit34-36: 0x7 (Beamformee STS <= 80 MHz)
Bit40-42: 0x1 (Number of Sounding Dimentions <= 80 MHz)
Bit53: 0x1 (Partial Bandwidth Extended Range)
Bit55: 0x1 (PPE Threshold Present.
            Note: PPE threshold may have some changes later)
Bit58: 0x1 (HE SU PPDU and HE MU PPDU with 4xHE-LTF+0.8usGI)
Bit59-61: 0x1 (Max Nc)
Bit64: 0x1 (HE ER SU PPDU with 4xHE-LTF+0.8usGI)
Bit75: 0x1 (Rx 1024-QAM Support < 242-tone RU)
*/

#define UAP_HE_MAC_CAP0_MASK  0x04
#define UAP_HE_MAC_CAP1_MASK  0x00
#define UAP_HE_MAC_CAP2_MASK  0x10
#define UAP_HE_MAC_CAP3_MASK  0x02
#define UAP_HE_MAC_CAP4_MASK  0x00
#define UAP_HE_MAC_CAP5_MASK  0x00
#define UAP_HE_PHY_CAP0_MASK  0x04
#define UAP_HE_PHY_CAP1_MASK  0x23
#define UAP_HE_PHY_CAP2_MASK  0x3E
#define UAP_HE_PHY_CAP3_MASK  0x89
#define UAP_HE_PHY_CAP4_MASK  0x1D
#define UAP_HE_PHY_CAP5_MASK  0x01
#define UAP_HE_PHY_CAP6_MASK  0xA0
#define UAP_HE_PHY_CAP7_MASK  0x0C
#define UAP_HE_PHY_CAP8_MASK  0x01
#define UAP_HE_PHY_CAP9_MASK  0x08
#define UAP_HE_PHY_CAP10_MASK 0x00

/*
2G
===
HE MAC Cap:
Bit0:   1  (+HTC HE Support)
Bit25: 1  (OM Control Support. Note: uAP does not support
        Tx OM received from the STA, as it does not support UL OFDMA)

HE PHY Cap:
Bit1-7: 0x1 (Supported Channel Width Set)
Bit8-11: 0x0 (Punctured Preamble Rx)
Bit12: 0x0 (Device Class)
Bit13: 0x1 (LDPC coding in Payload)
Bit17: 0x1 (NDP with 4xLTF+3.2usGI)
Bit18: 0x1 (STBC Tx <= 80 MHz)
Bit19: 0x1 (STBC Rx <= 80 MHz)
Bit20: 0x1 (Doppler Tx)
Bit21: 0x1 (Doppler Rx)
Bit24-25: 0x1 (DCM Max Constellation Tx)
Bit27-28: 0x1 (DCM Max Constellation Rx)
Bit31: 0x1 (SU Beamformer)
Bit32: 0x1 (SU BeamFormee)
Bit34-36: 0x7 (Beamformee STS <= 80 MHz)
Bit40-42: 0x1 (Number of Sounding Dimentions <= 80 MHz)
Bit53: 0x1 (Partial Bandwidth Extended Range)
Bit55: 0x1 (PPE Threshold Present.
            Note: PPE threshold may have some changes later)
Bit58: 0x1 (HE SU PPDU and HE MU PPDU with 4xHE-LTF+0.8usGI)
Bit59-61: 0x1 (Max Nc)
Bit64: 0x1 (HE ER SU PPDU with 4xHE-LTF+0.8usGI)
Bit75: 0x1 (Rx 1024-QAM Support < 242-tone RU)
*/
#define UAP_HE_2G_MAC_CAP0_MASK  0x04
#define UAP_HE_2G_MAC_CAP1_MASK  0x00
#define UAP_HE_2G_MAC_CAP2_MASK  0x10
#define UAP_HE_2G_MAC_CAP3_MASK  0x02
#define UAP_HE_2G_MAC_CAP4_MASK  0x00
#define UAP_HE_2G_MAC_CAP5_MASK  0x00
#define UAP_HE_2G_PHY_CAP0_MASK  0x02
#define UAP_HE_2G_PHY_CAP1_MASK  0x20
#define UAP_HE_2G_PHY_CAP2_MASK  0x3E
#define UAP_HE_2G_PHY_CAP3_MASK  0x89
#define UAP_HE_2G_PHY_CAP4_MASK  0x1D
#define UAP_HE_2G_PHY_CAP5_MASK  0x01
#define UAP_HE_2G_PHY_CAP6_MASK  0xA0
#define UAP_HE_2G_PHY_CAP7_MASK  0x0C
#define UAP_HE_2G_PHY_CAP8_MASK  0x01
#define UAP_HE_2G_PHY_CAP9_MASK  0x08
#define UAP_HE_2G_PHY_CAP10_MASK 0x00

/**
 *  @brief update 11ax ie for AP mode *
 *  @param band     channel band
 *  @hecap_ie       a pointer to mlan_ds_11ax_he_capa
 *
 *  @return         0--success, otherwise failure
 */
static void wifi_uap_update_11ax_ie(t_u8 band, mlan_ds_11ax_he_capa *hecap_ie)
{
    if (band == BAND_5GHZ
#ifdef ENABLE_802_116E
        || band == BAND_6GHZ
#endif
    )
    {
        hecap_ie->he_mac_cap[0] &= UAP_HE_MAC_CAP0_MASK;
        hecap_ie->he_mac_cap[1] &= UAP_HE_MAC_CAP1_MASK;
        hecap_ie->he_mac_cap[2] &= UAP_HE_MAC_CAP2_MASK;
        hecap_ie->he_mac_cap[3] &= UAP_HE_MAC_CAP3_MASK;
        hecap_ie->he_mac_cap[4] &= UAP_HE_MAC_CAP4_MASK;
        hecap_ie->he_mac_cap[5] &= UAP_HE_MAC_CAP5_MASK;
        hecap_ie->he_phy_cap[0] &= UAP_HE_PHY_CAP0_MASK;
        hecap_ie->he_phy_cap[1] &= UAP_HE_PHY_CAP1_MASK;
        hecap_ie->he_phy_cap[2] &= UAP_HE_PHY_CAP2_MASK;
        hecap_ie->he_phy_cap[3] &= UAP_HE_PHY_CAP3_MASK;
        hecap_ie->he_phy_cap[4] &= UAP_HE_PHY_CAP4_MASK;
        hecap_ie->he_phy_cap[5] &= UAP_HE_PHY_CAP5_MASK;
        hecap_ie->he_phy_cap[6] &= UAP_HE_PHY_CAP6_MASK;
        hecap_ie->he_phy_cap[7] &= UAP_HE_PHY_CAP7_MASK;
        hecap_ie->he_phy_cap[8] &= UAP_HE_PHY_CAP8_MASK;
        hecap_ie->he_phy_cap[9] &= UAP_HE_PHY_CAP9_MASK;
        hecap_ie->he_phy_cap[10] &= UAP_HE_PHY_CAP10_MASK;
    }
    else
    {
        hecap_ie->he_mac_cap[0] &= UAP_HE_2G_MAC_CAP0_MASK;
        hecap_ie->he_mac_cap[1] &= UAP_HE_2G_MAC_CAP1_MASK;
        hecap_ie->he_mac_cap[2] &= UAP_HE_2G_MAC_CAP2_MASK;
        hecap_ie->he_mac_cap[3] &= UAP_HE_2G_MAC_CAP3_MASK;
        hecap_ie->he_mac_cap[4] &= UAP_HE_2G_MAC_CAP4_MASK;
        hecap_ie->he_mac_cap[5] &= UAP_HE_2G_MAC_CAP5_MASK;
        hecap_ie->he_phy_cap[0] &= UAP_HE_2G_PHY_CAP0_MASK;
        hecap_ie->he_phy_cap[1] &= UAP_HE_2G_PHY_CAP1_MASK;
        hecap_ie->he_phy_cap[2] &= UAP_HE_2G_PHY_CAP2_MASK;
        hecap_ie->he_phy_cap[3] &= UAP_HE_2G_PHY_CAP3_MASK;
        hecap_ie->he_phy_cap[4] &= UAP_HE_2G_PHY_CAP4_MASK;
        hecap_ie->he_phy_cap[5] &= UAP_HE_2G_PHY_CAP5_MASK;
        hecap_ie->he_phy_cap[6] &= UAP_HE_2G_PHY_CAP6_MASK;
        hecap_ie->he_phy_cap[7] &= UAP_HE_2G_PHY_CAP7_MASK;
        hecap_ie->he_phy_cap[8] &= UAP_HE_2G_PHY_CAP8_MASK;
        hecap_ie->he_phy_cap[9] &= UAP_HE_2G_PHY_CAP9_MASK;
        hecap_ie->he_phy_cap[10] &= UAP_HE_2G_PHY_CAP10_MASK;
    }
    return;
}

/**
 *  @brief Sets up the CFG802.11 specific HE capability fields *  with default
 * values
 *
 *  @param priv         A pointer to moal private structure
 *  @param iftype_data  A pointer to ieee80211_sband_iftype_data structure
 *
 *  @return             N/A
 */
int wifi_setup_he_cap(nxp_wifi_he_capabilities *he_cap, t_u8 band)
{
    mlan_private *priv = (mlan_private *)mlan_adap->priv[0];
    mlan_fw_info fw_info;
    t_u8 extra_mcs_size           = 0;
    int ppe_threshold_len         = 0;
    mlan_ds_11ax_he_capa *phe_cap = NULL;
    t_u8 hw_hecap_len             = 0;

    memset(&fw_info, 0, sizeof(mlan_fw_info));

    wifi_request_get_fw_info(priv, &fw_info);

#if CONFIG_5GHz_SUPPORT
    if (band == BAND_5GHZ)
    {
        phe_cap      = (mlan_ds_11ax_he_capa *)fw_info.hw_he_cap;
        hw_hecap_len = fw_info.hw_hecap_len;
        wifi_uap_update_11ax_ie(BAND_5GHZ, phe_cap);
    }
    else
#endif
#ifdef ENABLE_802_116E
        if (band == BAND_6GHZ)
    {
        phe_cap      = (mlan_ds_11ax_he_capa *)fw_info.hw_he_cap;
        hw_hecap_len = fw_info.hw_hecap_len;
        wifi_uap_update_11ax_ie(BAND_6GHZ, phe_cap);
    }
    else
#endif
    {
        phe_cap      = (mlan_ds_11ax_he_capa *)fw_info.hw_2g_he_cap;
        hw_hecap_len = fw_info.hw_2g_hecap_len;
        wifi_uap_update_11ax_ie(BAND_2GHZ, phe_cap);
    }

    if (!hw_hecap_len)
        return -WM_FAIL;

    he_cap->he_supported = 1;
    memcpy(he_cap->mac_cap, phe_cap->he_mac_cap, sizeof(phe_cap->he_mac_cap));
    memcpy(he_cap->phy_cap, phe_cap->he_phy_cap, sizeof(phe_cap->he_phy_cap));
    memset(&he_cap->mcs, 0xff, WIFI_HE_MAX_MCS_CAPAB_SIZE);
    memcpy(&he_cap->mcs, phe_cap->he_txrx_mcs_support, sizeof(phe_cap->he_txrx_mcs_support));

    // Support 160Mhz
    if (phe_cap->he_phy_cap[0] & MBIT(3))
        extra_mcs_size += 4;

    // Support 80+80
    if (phe_cap->he_phy_cap[0] & MBIT(4))
        extra_mcs_size += 4;
    if (extra_mcs_size)
        memcpy((t_u8 *)&he_cap->mcs + sizeof(phe_cap->he_txrx_mcs_support), phe_cap->val, extra_mcs_size);

#define HE_CAP_FIX_SIZE 22
    // Support PPE threshold
    ppe_threshold_len = phe_cap->len - HE_CAP_FIX_SIZE - extra_mcs_size;
    if (phe_cap->he_phy_cap[6] & MBIT(7) && ppe_threshold_len)
    {
        memcpy(he_cap->ppet, &phe_cap->val[extra_mcs_size], ppe_threshold_len);
    }
    else
    {
        he_cap->phy_cap[6] &= ~MBIT(7);
        wifi_d("Clear PPE threshold 0x%x\r\n", he_cap->phy_cap[7]);
    }
#ifdef ENABLE_802_116E
    if (band->band == BAND_6GHZ)
        iftype_data->he_6ghz_capa.capa = fw_info.hw_he_6g_cap;
#endif
    LEAVE();

    return WM_SUCCESS;
}
#endif

int wifi_get_bandwidth()
{
#if UAP_SUPPORT
    return wifi_uap_get_bandwidth();
#else
    return BANDWIDTH_20MHZ;
#endif
}
#endif /* CONFIG_WPA_SUPP */
