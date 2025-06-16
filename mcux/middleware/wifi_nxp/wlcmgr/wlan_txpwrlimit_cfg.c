/** @file wlan_txpwrlimit_cfg.c
 *
 *  @brief  This file provides WLAN World Wide Safe Mode Tx Power Limit APIs.
 *
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <wlan.h>
#include <wifi.h>
#ifdef RW610
#include "fsl_ocotp.h"
#endif

#if defined(IW610)
#define IW610_PACKAGE_TYPE_CSP 0
#define IW610_PACKAGE_TYPE_QFN 1
#endif

#if defined(WIFI_BT_TX_PWR_LIMITS_OVERRIDE)
#include WIFI_BT_TX_PWR_LIMITS_OVERRIDE
#elif defined(WIFI_BT_TX_PWR_LIMITS)
#include WIFI_BT_TX_PWR_LIMITS
#else
#error "Region tx power config not defined"
#endif

#if (CONFIG_COMPRESS_TX_PWTBL || ((CONFIG_COMPRESS_RU_TX_PWTBL) && (CONFIG_11AX)))
#if defined(RW610) || defined(IW610)
typedef struct _rg_power_info
{
    t_u8 *rg_power_table;
    t_u16 rg_len;
} rg_power_info;
#endif
#endif

#if ((CONFIG_COMPRESS_RU_TX_PWTBL) && (CONFIG_11AX))
#if defined(RW610) || defined(IW610)
typedef struct _ru_power_cfg
{
    t_u16 region_code;
    rg_power_info power_info;
} ru_power_cfg;

/* All type boards ru txpwr data is same, */
ru_power_cfg ru_power_cfg_info[] = {
    {0x00, .power_info = {(t_u8 *)rutxpowerlimit_cfg_set_WW, sizeof(rutxpowerlimit_cfg_set_WW)}},
    {0x10, .power_info = {(t_u8 *)rutxpowerlimit_cfg_set_US, sizeof(rutxpowerlimit_cfg_set_US)}},
    {0x30, .power_info = {(t_u8 *)rutxpowerlimit_cfg_set_EU, sizeof(rutxpowerlimit_cfg_set_EU)}},
    {0x50, .power_info = {(t_u8 *)rutxpowerlimit_cfg_set_CN, sizeof(rutxpowerlimit_cfg_set_CN)}},
    {0xFF, .power_info = {(t_u8 *)rutxpowerlimit_cfg_set_JP, sizeof(rutxpowerlimit_cfg_set_JP)}},
};

int wlan_set_ru_power_cfg(t_u16 region_code)
{
    int i  = 0;
    int rv = -WM_FAIL;

    for (i = 0; i < sizeof(ru_power_cfg_info) / sizeof(ru_power_cfg); i++)
    {
        if (region_code == ru_power_cfg_info[i].region_code)
        {
            rv = wlan_set_11ax_rutxpowerlimit(ru_power_cfg_info[i].power_info.rg_power_table,
                                              ru_power_cfg_info[i].power_info.rg_len);

            return rv;
        }
    }

    /* Set default world wide ru txpwr if ru_power_cfg_info does not have a corresponding region_code temporarily */
    wlcm_d("power_info of region_code %d not available, use default world wide ru txpwr by default.", region_code);

    rv = wlan_set_11ax_rutxpowerlimit(ru_power_cfg_info[0].power_info.rg_power_table,
                                      ru_power_cfg_info[0].power_info.rg_len);

    return rv;
}
#endif
#endif

#if (CONFIG_COMPRESS_TX_PWTBL)
#if defined(RW610) || defined(IW610)
#define MAX_SOC_OTP_LINE 64
#define OTP_PKG_TAG      0x15D
#define PKG_TYPE_MAX     3

typedef struct _rg_power_cfg
{
    t_u16 region_code;
    rg_power_info power_info[PKG_TYPE_MAX];
} rg_power_cfg;

#if defined(RW610)
/* For CSP board, we didn't get tx_power_table data, so use bga data temporary
 * And maybe no BGA or QFN data for avaliable region, use other type data
 */
rg_power_cfg rg_power_cfg_info[] = {
    {0x00, .power_info[RW610_PACKAGE_TYPE_QFN] = {(t_u8 *)rg_rw610_WW, sizeof(rg_rw610_WW)},
     .power_info[RW610_PACKAGE_TYPE_CSP] = {(t_u8 *)rg_rw610_WW, sizeof(rg_rw610_WW)},
     .power_info[RW610_PACKAGE_TYPE_BGA] = {(t_u8 *)rg_rw610_WW, sizeof(rg_rw610_WW)}},
    {0x10, .power_info[RW610_PACKAGE_TYPE_QFN] = {(t_u8 *)rg_rw610_qfn, sizeof(rg_rw610_qfn)},
     .power_info[RW610_PACKAGE_TYPE_CSP] = {(t_u8 *)rg_rw610_csp, sizeof(rg_rw610_csp)},
     .power_info[RW610_PACKAGE_TYPE_BGA] = {(t_u8 *)rg_rw610_bga, sizeof(rg_rw610_bga)}},
    {0x30, .power_info[RW610_PACKAGE_TYPE_QFN] = {(t_u8 *)rg_rw610_EU, sizeof(rg_rw610_EU)},
     .power_info[RW610_PACKAGE_TYPE_CSP] = {(t_u8 *)rg_rw610_EU, sizeof(rg_rw610_EU)},
     .power_info[RW610_PACKAGE_TYPE_BGA] = {(t_u8 *)rg_rw610_EU, sizeof(rg_rw610_EU)}},
    {0x50, .power_info[RW610_PACKAGE_TYPE_QFN] = {(t_u8 *)rg_rw610_CN, sizeof(rg_rw610_CN)},
     .power_info[RW610_PACKAGE_TYPE_CSP] = {(t_u8 *)rg_rw610_CN, sizeof(rg_rw610_CN)},
     .power_info[RW610_PACKAGE_TYPE_BGA] = {(t_u8 *)rg_rw610_CN, sizeof(rg_rw610_CN)}},
    {0xFF, .power_info[RW610_PACKAGE_TYPE_QFN] = {(t_u8 *)rg_rw610_JP, sizeof(rg_rw610_JP)},
     .power_info[RW610_PACKAGE_TYPE_CSP] = {(t_u8 *)rg_rw610_JP, sizeof(rg_rw610_JP)},
     .power_info[RW610_PACKAGE_TYPE_BGA] = {(t_u8 *)rg_rw610_JP, sizeof(rg_rw610_JP)}},
};
#endif /* RW610 */

#if defined(IW610)
rg_power_cfg rg_power_cfg_info[] = {
    {0x10, .power_info[IW610_PACKAGE_TYPE_CSP] = {(t_u8 *)rg_table_US_csp, sizeof(rg_table_US_csp)},
    },
    {0x20, .power_info[IW610_PACKAGE_TYPE_CSP] = {(t_u8 *)rg_table_CA_csp, sizeof(rg_table_CA_csp)},
    },
    {0x30, .power_info[IW610_PACKAGE_TYPE_CSP] = {(t_u8 *)rg_table_EU_csp, sizeof(rg_table_EU_csp)},
    },
    {0xFF, .power_info[IW610_PACKAGE_TYPE_CSP] = {(t_u8 *)rg_table_JP_csp, sizeof(rg_table_JP_csp)},
    },
};
#endif /* IW610 */

int wlan_set_rg_power_cfg(t_u16 region_code)
{
    int i               = 0;
    uint32_t board_type = 0;
    int rv              = WM_SUCCESS;

    board_type = wifi_get_board_type();
    (void)PRINTF("board_type: %d, board_type mapping: \r\n", board_type);

#if defined(RW610)
    (void)PRINTF("0----QFN\r\n");
    (void)PRINTF("1----CSP\r\n");
    (void)PRINTF("2----BGA\r\n");
#endif /* RW610 */

#if defined(IW610)
    (void)PRINTF("0----CSP\r\n");
    (void)PRINTF("1----QFN\r\n");
#endif /* IW610 */

    if(board_type >= PKG_TYPE_MAX)
     {
        (void)PRINTF("board_type error\r\n");
        return -WM_FAIL;
     }

    for (i = 0; i < sizeof(rg_power_cfg_info) / sizeof(rg_power_cfg); i++)
    {
        if (region_code == rg_power_cfg_info[i].region_code)
        {
            rv = wlan_set_region_power_cfg(rg_power_cfg_info[i].power_info[board_type].rg_power_table,
                                           rg_power_cfg_info[i].power_info[board_type].rg_len);

            return rv;
        }
    }

    /* Set default world wide power table if rg_power_cfg_info does not have a corresponding region_code temporarily */
    wlcm_d("power_info of region_code %d not available, use default world wide power table by default.", region_code);

    rv = wlan_set_region_power_cfg(rg_power_cfg_info[0].power_info[board_type].rg_power_table,
                                   rg_power_cfg_info[0].power_info[board_type].rg_len);

    return rv;
}
#else
typedef struct _rg_power_cfg
{
    t_u16 region_code;
    t_u8 *rg_power_table;
    t_u16 rg_len;
} rg_power_cfg;

rg_power_cfg rg_power_cfg_FC[] = {
    {
        0x00,
        (t_u8 *)rg_table_fc,
        sizeof(rg_table_fc),
    },
};

int wlan_set_rg_power_cfg(t_u16 region_code)
{
    int i  = 0;
    int rv = WM_SUCCESS;

    for (i = 0; i < sizeof(rg_power_cfg_FC) / sizeof(rg_power_cfg); i++)
    {
        if (region_code == rg_power_cfg_FC[i].region_code)
        {
            rv = wlan_set_region_power_cfg(rg_power_cfg_FC[i].rg_power_table, rg_power_cfg_FC[i].rg_len);
            if (rv != WM_SUCCESS)
                (void)PRINTF("Unable to set compressed TX power table configuration\r\n");
            return rv;
        }
    }

    return -WM_FAIL;
}
#endif /* RW610 and IW610 */
#endif /* CONFIG_COMPRESS_TX_PWTBL */

#if CONFIG_COMPRESS_TX_PWTBL || ((CONFIG_COMPRESS_RU_TX_PWTBL) && (CONFIG_11AX))
int wlan_set_wwsm_txpwrlimit()
{
    int rv = WM_SUCCESS;
#if defined(RW610) || defined(IW610)
    unsigned int region_code = 0;
#endif
#ifdef WLAN_REGION_CODE
    rv = wlan_set_country_code(WLAN_REGION_CODE);
    if (rv != WM_SUCCESS)
    {
        (void)PRINTF("Unable to set country code\r\n");
        return -WM_FAIL;
    }
#endif
#if defined(RW610)
    ARG_UNUSED(tx_pwrlimit_2g_cfg);
#if CONFIG_5GHz_SUPPORT
    ARG_UNUSED(tx_pwrlimit_5g_cfg);
#endif
#endif
#if defined(RW610) || defined(IW610)
    ARG_UNUSED(chanlist_2g_cfg);
#if CONFIG_5GHz_SUPPORT
    ARG_UNUSED(chanlist_5g_cfg);
#endif
#endif
#if !defined RW610 && !defined IW610
    rv = wlan_set_chanlist(&chanlist_2g_cfg);
    if (rv != WM_SUCCESS)
    {
        (void)PRINTF("Unable to set 2G chanlist configuration\r\n");
        return -WM_FAIL;
    }
#if CONFIG_5GHz_SUPPORT
    rv = wlan_set_chanlist(&chanlist_5g_cfg);
    if (rv != WM_SUCCESS)
    {
        (void)PRINTF("Unable to set 5G chanlist configuration\r\n");
        return -WM_FAIL;
    }
#endif
#endif

#if defined(RW610) || defined(IW610)
    wlan_get_region_code(&region_code);
#if CONFIG_COMPRESS_TX_PWTBL
    rv = wlan_set_rg_power_cfg(region_code);
    if (rv != WM_SUCCESS)
    {
        (void)PRINTF("Unable to set compressed TX power table configuration\r\n");
        return -WM_FAIL;
    }
#endif

#if (CONFIG_COMPRESS_RU_TX_PWTBL) && (CONFIG_11AX)
    rv = wlan_set_ru_power_cfg(region_code);
    if (rv != WM_SUCCESS)
    {
        return -WM_FAIL;
    }
#endif

    rv = wifi_create_dnld_countryinfo();
    if (rv != WM_SUCCESS)
    {
        return -WM_FAIL;
    }
#else
    rv = wlan_set_region_power_cfg(rg_table_fc, rg_table_fc_len);
    if (rv != WM_SUCCESS)
    {
        return -WM_FAIL;
    }
#endif /* RW610 and IW610 */

#if !defined RW610 && !defined IW610
#if CONFIG_11AX
#if CONFIG_COMPRESS_RU_TX_PWTBL
    rv = wlan_set_11ax_rutxpowerlimit(rutxpowerlimit_cfg_set, sizeof(rutxpowerlimit_cfg_set));
    if (rv != WM_SUCCESS)
    {
        (void)PRINTF("Unable to set RU TX PWR Limit configuration\r\n");
        return -WM_FAIL;
    }
#else
    rv = wlan_set_11ax_rutxpowerlimit_legacy(&rutxpowerlimit_2g_cfg_set);
    if (rv != WM_SUCCESS)
    {
        (void)PRINTF("Unable to set 2G RU TX PWR Limit configuration\r\n");
        return -WM_FAIL;
    }
#if CONFIG_5GHz_SUPPORT
    else
    {
        rv = wlan_set_11ax_rutxpowerlimit_legacy(&rutxpowerlimit_5g_cfg_set);
        if (rv != WM_SUCCESS)
        {
            (void)PRINTF("Unable to set 5G RU TX PWR Limit configuration\r\n");
            return -WM_FAIL;
        }
    }
#endif
#endif /* CONFIG_COMPRESS_RU_TX_PWTBL */
#endif /* CONFIG_11AX */
#endif /* RW610 and IW610 */

    return rv;
}
#else
int wlan_set_wwsm_txpwrlimit(void)
{
    int rv = WM_SUCCESS;
#ifdef WLAN_REGION_CODE
    rv     = wlan_set_country_code(WLAN_REGION_CODE);
    if (rv != WM_SUCCESS)
    {
        (void)PRINTF("Unable to set country code\r\n");
        return -WM_FAIL;
    }
#endif
    rv = wlan_set_chanlist_and_txpwrlimit(&chanlist_2g_cfg, &tx_pwrlimit_2g_cfg);
    if (rv != WM_SUCCESS)
    {
        (void)PRINTF("Unable to set 2G TX PWR Limit configuration\r\n");
        return -WM_FAIL;
    }
#if CONFIG_5GHz_SUPPORT
    rv = wlan_set_chanlist_and_txpwrlimit(&chanlist_5g_cfg, &tx_pwrlimit_5g_cfg);
    if (rv != WM_SUCCESS)
    {
        (void)PRINTF("Unable to set 5G TX PWR Limit configuration\r\n");
        return -WM_FAIL;
    }
#endif

#if !defined RW610 && !defined IW610
#if CONFIG_11AX
#if CONFIG_COMPRESS_RU_TX_PWTBL
    rv = wlan_set_11ax_rutxpowerlimit(rutxpowerlimit_cfg_set, sizeof(rutxpowerlimit_cfg_set));
    if (rv != WM_SUCCESS)
    {
        (void)PRINTF("Unable to set RU TX PWR Limit configuration\r\n");
        return -WM_FAIL;
    }
#else
    rv = wlan_set_11ax_rutxpowerlimit_legacy(&rutxpowerlimit_2g_cfg_set);
    if (rv != WM_SUCCESS)
    {
        (void)PRINTF("Unable to set 2G RU TX PWR Limit configuration\r\n");
        return -WM_FAIL;
    }
#if CONFIG_5GHz_SUPPORT
    else
    {
        rv = wlan_set_11ax_rutxpowerlimit_legacy(&rutxpowerlimit_5g_cfg_set);
        if (rv != WM_SUCCESS)
        {
            (void)PRINTF("Unable to set 5G RU TX PWR Limit configuration\r\n");
            return -WM_FAIL;
        }
    }
#endif
#endif /* CONFIG_COMPRESS_RU_TX_PWTBL */
#endif /* CONFIG_11AX */
#endif /* RW610 and IW610*/

    return rv;
}
#endif /* CONFIG_COMPRESS_TX_PWTBL */

#if !defined RW610 && !defined IW610
const char *wlan_get_wlan_region_code(void)
{
#ifdef WLAN_REGION_CODE
    return WLAN_REGION_CODE;
#else
#error "Please define WLAN_REGION_CODE in Region tx power config file"
#endif
}
#endif
