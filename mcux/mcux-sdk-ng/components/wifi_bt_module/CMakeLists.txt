# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.wifi_bt_module.tx_pwr_limits)
    mcux_add_source(
        SOURCES AzureWave/tx_pwr_limits/wlan_txpwrlimit_cfg_WW.h
                AzureWave/tx_pwr_limits/wlan_txpwrlimit_cfg_WW_rw610.h
                Murata/tx_pwr_limits/wlan_txpwrlimit_cfg_murata_1XK_WW.h
                Murata/tx_pwr_limits/wlan_txpwrlimit_cfg_murata_1ZM_WW.h
                Murata/tx_pwr_limits/wlan_txpwrlimit_cfg_murata_2DS_WW.h
                Murata/tx_pwr_limits/wlan_txpwrlimit_cfg_murata_2EL_WW.h
                Murata/tx_pwr_limits/wlan_txpwrlimit_cfg_murata_NH_FCC.h
                u-blox/tx_pwr_limits/wlan_txpwrlimit_cfg_jody_w5_WW.h
    )
    mcux_add_include(
        INCLUDES AzureWave/tx_pwr_limits
                 Murata/tx_pwr_limits u-blox/tx_pwr_limits
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.wifi_bt_module.config)
    mcux_add_source(
        SOURCES incl/wifi_bt_module_config.h
    )
    mcux_add_include(
        INCLUDES incl
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.wifi_bt_module.board_rw61x)
    mcux_add_macro(
        "-DWIFI_BOARD_RW610"
    )
endif()
