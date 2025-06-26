/** @file wifi_nxp.h
 *
 * @brief This file provides Core Wi-Fi definition for wpa supplicant RTOS driver.
 *
 * Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __WIFI_NXP_H__
#define __WIFI_NXP_H__

#include <stdio.h>
#include <wm_net.h>
#if CONFIG_WPA_SUPP
#include <drivers/driver_zephyr.h>

typedef struct zep_wpa_supp_dev_callbk_fns rtos_wpa_supp_dev_callbk_fns;

#if CONFIG_WPA_SUPP_AP
typedef struct zep_hostapd_dev_callbk_fns rtos_hostapd_dev_callbk_fns;
#endif

typedef struct zep_wpa_supp_dev_ops rtos_wpa_supp_dev_ops;

struct wifi_nxp_ctx_rtos
{
    const struct netif *iface_ctx;
    void *supp_drv_if_ctx;

    void *hapd_drv_if_ctx;
    unsigned int bss_type;

    bool scan_in_progress;
    uint64_t scan_start_tsf;
    uint8_t scan_start_tsf_bssid[ETH_ALEN];

    unsigned int assoc_freq;
    uint8_t attempt_bssid[ETH_ALEN];
    uint8_t assoc_bssid[ETH_ALEN];
    bool associated;
    bool uap_started;
    bool hostapd;
    rtos_wpa_supp_dev_callbk_fns supp_callbk_fns;
    bool supp_called_remain_on_chan;
    unsigned int remain_on_channel_freq;
    unsigned int remain_on_channel_duration;
    bool remain_on_chan_is_canceled;
#if CONFIG_WPA_SUPP_AP
    rtos_hostapd_dev_callbk_fns hostapd_callbk_fns;
#endif
    int mgmt_tx_status;
    uint8_t *last_mgmt_tx_data;
    size_t last_mgmt_tx_data_len;
    bool ft_roaming;
    struct wpa_driver_set_key_params *key_params;
};

int wifi_supp_init(void);
void wifi_supp_deinit(void);
int monitor_start(void);
void monitor_stop(void);
void wifi_scan_start(struct wifi_message *msg);
void wifi_scan_done(struct wifi_message *msg);
void wifi_process_remain_on_channel(struct wifi_message *msg);
void wifi_process_mgmt_tx_status(struct wifi_message *msg);
void wifi_scan_result_get(struct wifi_message *msg);
void wifi_survey_result_get(struct wifi_message *msg);

#endif /* CONFIG_WPA_SUPP */

#endif /* __WIFI_NXP_H__ */
