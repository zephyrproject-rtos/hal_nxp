/** @file wlan_features.c
 *
 *  @brief  This file provides WLAN Features API
 *
 *  Copyright 2021-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <wlan.h>
#include <cli_utils.h>
#include <string.h>
#include <wm_net.h> /* for net_inet_aton */
#include <wifi.h>

#if CONFIG_WIFI_FEATURES

#ifdef ENABLE_OFFLOAD
static void test_wlan_ns_offload(int argc, char **argv)
{
    int ret = -WM_FAIL;
    ret     = wlan_set_ipv6_ns_offload();
    if (ret == WM_SUCCESS)
    {
        (void)PRINTF("Enabled  wlan IPv6 NS offload feature");
    }
    else
    {
        (void)PRINTF("Failed to enabled wlan auto arp offload, error: %d", ret);
    }
}

static void test_wlan_auto_arp(int argc, char **argv)
{
    int ret = -WM_FAIL;
    ret     = wlan_set_auto_arp();
    if (ret == WM_SUCCESS)
        (void)PRINTF("Enabled  wlan auto arp offload feature\r\n");
    else
        (void)PRINTF("Failed to enabled wlan auto arp offload, error: %d\r\n", ret);
}
#if (CONFIG_HOST_SLEEP && CONFIG_MEF_CFG)
static void dump_wlan_add_packet_filter()
{
    (void)PRINTF("Usage:\r\n");
    (void)PRINTF("For wowlan Add packet filter\r\n");
    (void)PRINTF("wowlan magic filter:\r\n");
    (void)PRINTF("wlan_add_packet_filter 1:\r\n");
    (void)PRINTF("wowlan User defined pattren packet filter:\r\n");
    (void)PRINTF("wlan_add_packet_filter 0 <number of patterns> <ptn_len> <pkt_offset> <ptn> ........:\r\n");
    (void)PRINTF(
        "For 2 number of patterns Usage \r\nwlan_add_packet_filter 0 2 6 0 0xff 0xff 0xff 0xff 0xff 0xff 4 20 192 168 "
        "10 1\r\n");
    (void)PRINTF("wowlan User defined pattren and magic packet filter:\r\n");
    (void)PRINTF("wlan_add_packet_filter 1 <number of patterns> <ptn_len> <pkt_offset> <ptn> ........:\r\n");
    (void)PRINTF(
        "For 2 number of patterns Usage \r\nwlan_add_packet_filter 1 2 6 0 0xff 0xff 0xff 0xff 0xff 0xff 4 20 192 168 "
        "10 1\r\n");
}
static void test_wlan_add_packet_filter(int argc, char **argv)
{
    int ret = -WM_FAIL;
    t_u8 i = 0, j = 0, k = 0;
    wlan_wowlan_ptn_cfg_t wowlan_ptn_cfg;
    if (argc < 2)
    {
        (void)PRINTF("Usage: %s <0/1>\r\n", argv[0]);
        (void)PRINTF("Error: Specify 1 to magic filter\r\n");
        dump_wlan_add_packet_filter();
        return;
    }
    if (argc > 3 && atoi(argv[2]) != argc - 3)
    {
        (void)PRINTF("Usage: %s 0/1 <patterns number> <ptn_len> <pkt_offset> <ptn> ...........\r\n", argv[0]);
        dump_wlan_add_packet_filter();
        return;
    }
    (void)memset(&wowlan_ptn_cfg, 0, sizeof(wlan_wowlan_ptn_cfg_t));
    wowlan_ptn_cfg.enable = atoi(argv[1]);
    if (argc > 2)
    {
        wowlan_ptn_cfg.n_patterns = atoi(argv[2]);
        for (i = 0, k = 0; (i + 3 < argc) && k < MAX_NUM_FILTERS; k++)
        {
            wowlan_ptn_cfg.patterns[k].pattern_len = atoi(argv[i + 3]);
            i++;
            wowlan_ptn_cfg.patterns[k].pkt_offset = atoi(argv[i + 3]);
            i++;
            for (j = 0; j < wowlan_ptn_cfg.patterns[k].pattern_len; j++)
                wowlan_ptn_cfg.patterns[k].pattern[j] = atoi(argv[j + i + 3]);
            i = +j;
            (void)memset(wowlan_ptn_cfg.patterns[k].mask, 0x3f, 6);
        }
    }
    ret = wlan_wowlan_cfg_ptn_match(&wowlan_ptn_cfg);
    if (ret == WM_SUCCESS)
        (void)PRINTF("Enabled pkt filter offload feature");
    else
        (void)PRINTF("Failed to enabled magic pkt filter offload, error: %d", ret);
}
#endif /* CONFIG_HOST_SLEEP && CONFIG_MEF_CFG */
#endif

static struct cli_command features[] = {
    {"enable-ns-offload", NULL, test_wlan_ns_offload},
    {"wlan-auto-arp", NULL, test_wlan_auto_arp},
#if (CONFIG_HOST_SLEEP && CONFIG_MEF_CFG)
    {"wlan-add-packet-filter", "0/1 <patterns number> <ptn_len> <pkt_offset> <ptn> ...........",
     test_wlan_add_packet_filter},
#endif
};

/* Register our commands with the MTF. */
int wlan_features_cli_init(void)
{
    int i;

    for (i = 0; i < sizeof(features) / sizeof(struct cli_command); i++)
    {
        if (cli_register_command(&features[i]) != 0)
        {
            return WLAN_ERROR_ACTION;
        }
    }

    return WLAN_ERROR_NONE;
}

int wlan_features_cli_deinit(void)
{
    int i;

    for (i = 0; i < sizeof(features) / sizeof(struct cli_command); i++)
    {
        if (cli_unregister_command(&features[i]) != 0)
        {
            return WLAN_ERROR_ACTION;
        }
    }

    return WLAN_ERROR_NONE;
}
#endif
