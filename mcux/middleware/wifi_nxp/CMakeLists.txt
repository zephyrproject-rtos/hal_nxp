# SPDX-License-Identifier: Apache-2.0
# Copyright 2022-2024 NXP

# define part number for this driver

# Legacy MCUX SDK code is in mcux/mcux-sdk.
# MCUX SDK NG code is in mcux/mcux-sdk-ng.
# Use the right code by checking whether the platform is not supported by MCUX SDK NG.
if(DEFINED CONFIG_SOC_SDKNG_UNSUPPORTED)
    set(MCUX_SDK_DIR ${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk)
else()
    set(MCUX_SDK_DIR ${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk-ng)
endif()

if(CONFIG_NXP_WIFI_CSI_AMI OR CONFIG_NXP_WIFI_WLS)
add_library(libcsi STATIC IMPORTED)
if(CONFIG_NXP_LIBCSI_CM33)
    set_target_properties(libcsi PROPERTIES IMPORTED_LOCATION ${ZEPHYR_HAL_NXP_MODULE_DIR}/zephyr/blobs/libcsi/cm33/libcsi.a)
elseif(CONFIG_NXP_LIBCSI_CM7_20M)
    set_target_properties(libcsi PROPERTIES IMPORTED_LOCATION ${ZEPHYR_HAL_NXP_MODULE_DIR}/zephyr/blobs/libcsi/cm7/cm7f_sta_20_only/libcsi.a)
else()
    set_target_properties(libcsi PROPERTIES IMPORTED_LOCATION ${ZEPHYR_HAL_NXP_MODULE_DIR}/zephyr/blobs/libcsi/cm7/cm7f/libcsi.a)
endif()
target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libcsi/incl)
zephyr_include_directories(
    libcsi/incl
)
target_link_libraries(app PRIVATE libcsi)
endif()

zephyr_compile_definitions_ifdef(CONFIG_NXP_88W8987
    SD8987
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW416
    SD8978
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW61X
    SD9177
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_88W8801
    SD8801
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW610
    IW610
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_RW610
    RW610
    WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_WW_rw610.h"
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x08
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x08
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_88W8987_AW_CM358_USD
    WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_WW.h"
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x09
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x0C
    WIFI_BT_USE_USD_INTERFACE
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_88W8987_AW_CM358MA_M2
    WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_WW.h"
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x09
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x0C
    WIFI_BT_USE_M2_INTERFACE
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_88W8987_MURATA_1ZM_USD
    WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_1ZM_WW.h"
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x06
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x06
    WIFI_BT_USE_USD_INTERFACE
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_88W8987_MURATA_1ZM_M2
    WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_1ZM_WW.h"
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x06
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x06
    WIFI_BT_USE_M2_INTERFACE
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW416_AW_AM457_USD
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x09
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x0C
    WIFI_BT_USE_USD_INTERFACE
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW416_AW_AM457MA_M2
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x09
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x0C
    WIFI_BT_USE_M2_INTERFACE
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW416_AW_AM510_USD
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x09
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x0C
    WIFI_BT_USE_USD_INTERFACE
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW416_AW_AM510MA_M2
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x09
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x0C
    WIFI_BT_USE_M2_INTERFACE
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW416_MURATA_1XK_USD
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x00
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x0C
    WIFI_BT_USE_USD_INTERFACE
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW416_MURATA_1XK_M2
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x00
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x0C
    WIFI_BT_USE_M2_INTERFACE
    WIFI_IW416_BOARD_MURATA_1XK_M2
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW416_REGION_EU
    WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_1XK_EU.h"
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW416_REGION_CA
	 WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_1XK_CA.h"
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW416_REGION_WW
	 WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_1XK_WW.h"
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW416_REGION_US
	 WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_1XK_US.h"
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW416_REGION_JP
	 WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_1XK_JP.h"
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW416_REGION_CA
	 WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_1XK_CA.h"
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW612_MURATA_2EL_USD
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x0A
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x0A
    WIFI_BT_USE_USD_INTERFACE
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW612_MURATA_2EL_M2
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x0A
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x0A
    WIFI_BT_USE_M2_INTERFACE
    WIFI_IW612_BOARD_MURATA_2EL_M2
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW611_MURATA_2DL_USD
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x0A
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x0A
    WIFI_BT_USE_USD_INTERFACE
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW611_MURATA_2DL_M2
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x0A
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x0A
    WIFI_BT_USE_M2_INTERFACE
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW61X_REGION_US
	 WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_2EL_US_RU_Tx_power.h"
)
zephyr_compile_definitions_ifdef(CONFIG_NXP_IW61X_REGION_JP
	 WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_2EL_JP_RU_Tx_power.h"
)
zephyr_compile_definitions_ifdef(CONFIG_NXP_IW61X_REGION_CA
	 WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_2EL_CA_RU_Tx_power.h"
)
zephyr_compile_definitions_ifdef(CONFIG_NXP_IW61X_REGION_EU
	 WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_2EL_EU_RU_Tx_power.h"
)
zephyr_compile_definitions_ifdef(CONFIG_NXP_IW61X_REGION_WW
	 WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_2EL_WW.h"
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_88W8801_AW_NM191_USD
    WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_WW.h"
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x1B
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_88W8801_AW_NM191MA_M2
    WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_WW.h"
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x1B
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_88W8801_MURATA_2DS_USD
    WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_2DS_WW.h"
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x0E
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_88W8801_MURATA_2DS_M2
    WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_2DS_WW.h"
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x0E
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW610_MURATA_2LL_M2
    WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_2LL.h"
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x0A
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x0A
    WIFI_BT_USE_M2_INTERFACE
    WIFI_IW610_BOARD_MURATA_2LL_M2
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_IW610_RD_USD
    WIFI_BT_TX_PWR_LIMITS="wlan_txpwrlimit_cfg_murata_2LL.h"
    CONFIG_NXP_WIFI_ED_OFFSET_2G=0x0A
    CONFIG_NXP_WIFI_ED_OFFSET_5G=0x0A
    WIFI_BT_USE_USD_INTERFACE
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_WIFI_BT_USE_USD_INTERFACE
    WIFI_BT_USE_USD_INTERFACE
)

zephyr_compile_definitions_ifdef(CONFIG_NXP_WIFI_BT_USE_M2_INTERFACE
    WIFI_BT_USE_M2_INTERFACE
)

zephyr_library_compile_definitions(
    FSL_OSA_TASK_ENABLE=1
    CONFIG_FSL_RTOS_ZEPHYR=1
    CONFIG_OSA_DEBUG_ASSERT_ENABLED=1
)

# mcux-sdk and mcux-sdk-ng share the wifi_nxp, the lists and osa is
# included in another way. Need add condition here.
if (CONFIG_HAS_MCUX OR CONFIG_HAS_IMX_HAL OR CONFIG_HAS_NXP_S32_HAL)
  if(DEFINED CONFIG_SOC_SDKNG_UNSUPPORTED)
    zephyr_library_sources(${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk/utilities/misc_utilities/fsl_memcpy.S)
  else()
    zephyr_library_sources(${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk-ng/components/misc_utilities/fsl_memcpy.S)
  endif()
endif()

if(DEFINED CONFIG_SOC_SDKNG_UNSUPPORTED)
  zephyr_library_sources(${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk/components/lists/fsl_component_generic_list.c)
  zephyr_library_sources(${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk/components/osa/fsl_os_abstraction_zephyr.c)
else()
  zephyr_library_sources(${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk-ng/components/osa/fsl_os_abstraction_zephyr.c)
  zephyr_include_directories(${MCUX_SDK_DIR}/components/osa/config)
endif()

zephyr_include_directories(
    incl
    incl/wifidriver
    incl/wlcmgr
    incl/port/osa
    incl/port/net/zephyr
    port/osa
    port/net/zephyr
    sdio_nxp_abs/incl
    firmware_dnld
    fwdnld_intf_abs
    wifidriver
    wifidriver/incl
    wifi_bt_firmware
    wifi_bt_firmware/8987
    wifi_bt_firmware/IW416
    wifi_bt_firmware/nw61x
    wifi_bt_firmware/8801
    wifi_bt_firmware/iw610
    cli
    ${MCUX_SDK_DIR}/components/osa/
    ${MCUX_SDK_DIR}/components/lists/
    ${MCUX_SDK_DIR}/components/wifi_bt_module/AzureWave/tx_pwr_limits/
    ${MCUX_SDK_DIR}/components/wifi_bt_module/Murata/tx_pwr_limits/
)

# OS abstraction layer source
zephyr_library_sources(
    port/osa/osa.c
    port/osa/osa_zephyr.c
)
# net stack abstraction layer source
zephyr_library_sources(port/net/zephyr/net.c)

file(GLOB WIFI_SRC ./wifidriver/*.c)
list(FILTER WIFI_SRC EXCLUDE REGEX ".*imu.c$")
list(FILTER WIFI_SRC EXCLUDE REGEX ".*sdio.c$")
list(FILTER WIFI_SRC EXCLUDE REGEX ".*firmware_dnld.c$")
list(FILTER WIFI_SRC EXCLUDE REGEX ".*uap.*.c$")

zephyr_library_sources_ifdef(CONFIG_NXP_WIFI_SOFTAP_SUPPORT
    wifidriver/wifi-uap.c
    wifidriver/mlan_uap_ioctl.c
    wifidriver/mlan_uap_cmdevent.c
)

zephyr_library_sources_ifdef(CONFIG_NXP_RW610
    wifidriver/wifi-imu.c
)

zephyr_library_sources_ifdef(CONFIG_SDIO_STACK
    wifidriver/sdio.c
    sdio_nxp_abs/fwdnld_sdio.c
    sdio_nxp_abs/mlan_sdio.c
    wifidriver/wifi-sdio.c
    firmware_dnld/firmware_dnld.c
    fwdnld_intf_abs/fwdnld_intf_abs.c
)

zephyr_library_sources(${WIFI_SRC})

file(GLOB WLCMGR_SRC ./wlcmgr/*.c)

zephyr_library_sources(${WLCMGR_SRC})

# nxp wifi shell
zephyr_library_sources(cli/wifi_shell.c)
zephyr_library_sources(cli/cli_utils.c)

# macros for wpa_supplicant
if(CONFIG_WIFI_NM_WPA_SUPPLICANT)
zephyr_include_directories(
    certs
    wifidriver/wpa_supp_if/incl
)

zephyr_library_include_directories(wifidriver/wpa_supp_if wifidriver/wpa_supp_if/incl)
file(GLOB WIFI_SUPP_SRC ./wifidriver/wpa_supp_if/*.c)
zephyr_library_sources(${WIFI_SUPP_SRC})
endif()

zephyr_include_directories_ifdef(CONFIG_WIFI_NM_WPA_SUPPLICANT_CRYPTO_ALT
    incl/port/mbedtls
)

zephyr_library_compile_definitions_ifdef(CONFIG_WIFI_NM_HOSTAPD_AP
    HOSTAPD
)

if(CONFIG_CODE_DATA_RELOCATION)

if(CONFIG_NXP_RW610)
    set(QUICK_ACCESS_CODE_AREA RAM_TEXT)
    set(QUICK_ACCESS_CODE_AREA_2 RAM_TEXT)
else()
    set(QUICK_ACCESS_CODE_AREA ITCM_TEXT)
    set(QUICK_ACCESS_CODE_AREA_2 DTCM_TEXT)
endif()

if(CONFIG_NXP_WIFI_FW_DEBUG)
if (CONFIG_BOARD MATCHES rw612)
    set(drv_folder rdrw612bga)
endif()
if (CONFIG_BOARD MATCHES mimxrt1060_evk)
if (CONFIG_BOARD_REVISION STREQUAL C)
    set(drv_folder evkcmimxrt1060)
endif()
endif()

zephyr_code_relocate(FILES
                     ${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk-ng/drivers/flexspi/fsl_flexspi.c
                     ${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk-ng/components/flash/mflash/${drv_folder}/mflash_drv.c
                     LOCATION ${QUICK_ACCESS_CODE_AREA_2} NOKEEP)
endif()

if(CONFIG_SPEED_OPTIMIZATIONS OR CONFIG_SIZE_OPTIMIZATIONS)
# critical path code relocated to SRAM
zephyr_code_relocate(FILES port/osa/osa.c
                     FILTER ".*\\.OSA_RWLockReadLock|.*\\.OSA_RWLockReadUnlock"
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)

string(JOIN "" NXP_PORT_NET_FILTER
       ".*\\.deliver_packet_above|"
       ".*\\.gen_pkt_from_data|"
       ".*\\.gen_tx_pkt_from_data|"
       ".*\\.gen_pkt_from_data_for_zerocopy|"
       ".*\\.process_data_packet|"
       ".*\\.handle_data_packet|"
       ".*\\.handle_amsdu_data_packet|"
       ".*\\.handle_deliver_packet_above|"
       ".*\\.nxp_wifi_internal_tx|"
       ".*\\.net_wifi_packet_send|"
       ".*\\.net_stack_buffer_copy_partial|"
       ".*\\.net_tx_zerocopy_process_cb"
)

zephyr_code_relocate(FILES port/net/zephyr/net.c
                     FILTER "${NXP_PORT_NET_FILTER}"
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)

string(JOIN "" NXP_WIFIDRIVER_WIFI_FILTER
       ".*\\.wifi_core_task|"
       ".*\\.wifi_low_level_input|"
       ".*\\.wifi_tx_card_awake_lock|"
       ".*\\.wifi_tx_card_awake_unlock|"
       ".*\\.wifi_wmm_get_pkt_prio|"
       ".*\\.wifi_txbuf_available|"
       ".*\\.wifi_xmit_pkts|"
       ".*\\.wifi_xmit_ralist_pkts|"
       ".*\\.wifi_xmit_wmm_ac_pkts_enh|"
       ".*\\.wlan_process_bypass_txq|"
       ".*\\.notify_wifi_driver_tx_event|"
       ".*\\.send_wifi_driver_tx_data_event|"
       ".*\\.send_wifi_driver_bypass_data_event|"
       ".*\\.wifi_drv_tx_task|"
       ".*\\.wifi_add_to_bypassq|"
       ".*\\.wifi_low_level_output|"
       ".*\\.wifi_get_outbuf"
)

zephyr_code_relocate(FILES wifidriver/wifi.c
                     FILTER "${NXP_WIFIDRIVER_WIFI_FILTER}"
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)

string(JOIN "" NXP_WIFIDRIVER_RXREORDER_FILTER
       ".*\\.wlan_11n_dispatch_amsdu_pkt|"
       ".*\\.wlan_11n_dispatch_pkt|"
       ".*\\.mlan_11n_rxreorder_timer_restart|"
       ".*\\.wlan_11n_dispatch_pkt_until_start_win|"
       ".*\\.wlan_11n_scan_and_dispatch|"
       ".*\\.wlan_11n_get_rxreorder_tbl|"
       ".*\\.mlan_11n_rxreorder_pkt"
)

zephyr_code_relocate(FILES wifidriver/mlan_11n_rxreorder.c
                     FILTER "${NXP_WIFIDRIVER_RXREORDER_FILTER}"
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)

string(JOIN "" NXP_WIFIDRIVER_MLAN_WMM_FILTER
       ".*\\.wlan_wmm_get_ralist_node|"
       ".*\\.wifi_wmm_da_to_ra|"
       ".*\\.wifi_wmm_is_tx_pause|"
       ".*\\.wifi_wmm_get_alter_buf_from_txqueue|"
       ".*\\.wifi_wmm_get_outbuf_enh|"
       ".*\\.wlan_wmm_get_queue_raptr_enh|"
       ".*\\.wlan_wmm_add_buf_txqueue_enh|"
       ".*\\.wifi_wmm_buf_get|"
       ".*\\.wifi_wmm_buf_put|"
       ".*\\.wlan_ralist_pkts_free_enh|"
       ".*\\.wlan_ralist_free_enh|"
       ".*\\.wlan_ralist_alloc_enh|"
       ".*\\.wlan_ralist_add_enh|"
       ".*\\.wlan_get_bypass_lock|"
       ".*\\.wlan_put_bypass_lock|"
       ".*\\.wlan_add_buf_bypass_txq|"
       ".*\\.wlan_bypass_txq_empty"
)

zephyr_code_relocate(FILES wifidriver/mlan_wmm.c
                     FILTER "${NXP_WIFIDRIVER_MLAN_WMM_FILTER}"
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)

string(JOIN "" NXP_WIFIDRIVER_MLAN_GLUE_FILTER
       ".*\\.wrapper_moal_semaphore_get|"
       ".*\\.wrapper_moal_semaphore_put|"
       ".*\\.wrapper_deliver_amsdu_subframe|"
       ".*\\.wrapper_wlan_handle_rx_packet|"
       ".*\\.wrapper_moal_recv_packet"
)

zephyr_code_relocate(FILES wifidriver/mlan_glue.c
                     FILTER "${NXP_WIFIDRIVER_MLAN_GLUE_FILTER}"
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)

zephyr_code_relocate(FILES
                     wifidriver/mlan_11n_aggr.c
                     wifidriver/mlan_txrx.c
                     wifidriver/mlan_sta_rx.c
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)

if(CONFIG_SDIO_STACK)
string(JOIN "" NXP_WIFIDRIVER_WIFI_SDIO_FILTER
       ".*\\.wifi_sdio_lock|"
       ".*\\.wifi_sdio_unlock|"
       ".*\\.process_pkt_hdrs|"
       ".*\\.process_pkt_hdrs_flags|"
       ".*\\.wlan_read_rcv_packet|"
       ".*\\.wlan_get_wr_port_data|"
       ".*\\.wifi_tx_data|"
       ".*\\.wlan_xmit_wmm_pkt|"
       ".*\\.wlan_flush_wmm_pkt|"
       ".*\\.wlan_xmit_pkt|"
       ".*\\.wlan_interrupt|"
       ".*\\.wlan_get_rd_port|"
       ".*\\._handle_sdio_packet_read|"
       ".*\\.handle_sdio_cmd_read|"
       ".*\\.handle_sdio_packet_read|"
       ".*\\.wlan_process_int_status|"
       ".*\\.handle_cdint"
)

zephyr_code_relocate(FILES wifidriver/wifi-sdio.c
                     FILTER "${NXP_WIFIDRIVER_WIFI_SDIO_FILTER}"
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)

zephyr_code_relocate(FILES
                     sdio_nxp_abs/mlan_sdio.c
                     ${ZEPHYR_BASE}/subsys/sd/sdio.c
                     ${ZEPHYR_BASE}/drivers/sdhc/imx_usdhc.c
                     ${MCUX_SDK_DIR}/drivers/usdhc/fsl_usdhc.c
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)

zephyr_code_relocate(FILES ${ZEPHYR_BASE}/drivers/wifi/nxp/nxp_wifi_drv.c
                     FILTER ".*\\.nxp_wifi_send|.*\\.nxp_wifi_recv"
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)
endif()

if(CONFIG_NXP_RW610)
string(JOIN "" NXP_WIFIDRIVER_WIFI_IMU_FILTER
       ".*\\.wifi_send_fw_data|"
       ".*\\.wifi_imu_lock|"
       ".*\\.wifi_imu_unlock|"
       ".*\\.process_pkt_hdrs|"
       ".*\\.process_pkt_hdrs_flags|"
       ".*\\.wlan_xmit_pkt|"
       ".*\\.wlan_xmit_bypass_pkt|"
       ".*\\.wlan_xmit_wmm_pkt|"
       ".*\\.wlan_flush_wmm_pkt|"
       ".*\\.imumc_rxpkt_handler"
)

zephyr_code_relocate(FILES wifidriver/wifi-imu.c
                     FILTER "${NXP_WIFIDRIVER_WIFI_IMU_FILTER}"
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)

zephyr_code_relocate(FILES
                     ${MCUX_SDK_DIR}/drivers/imu/fsl_imu.c
                     ${MCUX_SDK_DIR}/components/imu_adapter/fsl_adapter_imu.c
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)
endif()

string(JOIN "" NXP_OSA_ABS_ZEPHYR_FILTER
       ".*\\.OSA_MemoryAllocate|"
       ".*\\.OSA_MemoryFree|"
       ".*\\.OSA_EnterCritical|"
       ".*\\.OSA_ExitCritical|"
       ".*\\.OSA_InterruptEnable|"
       ".*\\.OSA_InterruptDisable|"
       ".*\\.OSA_EnableIRQGlobal|"
       ".*\\.OSA_DisableIRQGlobal|"
       ".*\\.OSA_TimeDelay|"
       ".*\\.OSA_TaskYield|"
       ".*\\.OSA_TaskGetCurrentHandle|"
       ".*\\.OSA_MutexLock|"
       ".*\\.OSA_MutexUnlock|"
       ".*\\.OSA_EventSet|"
       ".*\\.OSA_EventWait|"
       ".*\\.OSA_MsgQPut|"
       ".*\\.OSA_MsgQGet|"
       ".*\\.OSA_SemaphoreWait|"
       ".*\\.OSA_SemaphorePost|"
       ".*\\.OSA_TaskNotifyGet|"
       ".*\\.OSA_TaskNotifyPost"
)

zephyr_code_relocate(FILES ${MCUX_SDK_DIR}/components/osa/fsl_os_abstraction_zephyr.c
                     FILTER "${NXP_OSA_ABS_ZEPHYR_FILTER}"
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)

if(DEFINED CONFIG_SOC_SDKNG_UNSUPPORTED)
zephyr_code_relocate(FILES
                     ${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk/utilities/misc_utilities/fsl_memcpy.S
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)
else()
zephyr_code_relocate(FILES
                     ${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk-ng/components/misc_utilities/fsl_memcpy.S
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)
endif()

file(GLOB ZPERF_SRC ${ZEPHYR_BASE}/subsys/net/lib/zperf/*.c)
zephyr_code_relocate(FILES ${ZPERF_SRC} LOCATION ${QUICK_ACCESS_CODE_AREA_2} NOKEEP)

zephyr_code_relocate(FILES
                     ${ZEPHYR_BASE}/subsys/net/ip/ipv6_fragment.c
                     ${ZEPHYR_BASE}/subsys/net/ip/ipv4_fragment.c
                     LOCATION RAM_TEXT NOKEEP)

zephyr_code_relocate(FILES
                     ${ZEPHYR_BASE}/subsys/net/ip/connection.c
                     ${ZEPHYR_BASE}/subsys/net/ip/packet_socket.c
                     ${ZEPHYR_BASE}/subsys/net/ip/utils.c
                     ${ZEPHYR_BASE}/subsys/net/lib/sockets/sockets_inet.c
                     ${ZEPHYR_BASE}/subsys/net/lib/sockets/sockets.c
                     ${ZEPHYR_BASE}/subsys/net/ip/ipv4.c
                     ${ZEPHYR_BASE}/subsys/net/ip/ipv6.c
                     ${ZEPHYR_BASE}/subsys/net/ip/net_context.c
                     ${ZEPHYR_BASE}/subsys/net/ip/net_core.c
                     ${ZEPHYR_BASE}/subsys/net/ip/net_if.c
                     ${ZEPHYR_BASE}/subsys/net/ip/net_pkt.c
                     ${ZEPHYR_BASE}/subsys/net/ip/net_tc.c
                     ${ZEPHYR_BASE}/subsys/net/ip/tcp.c
                     ${ZEPHYR_BASE}/subsys/net/ip/udp.c
                     ${ZEPHYR_BASE}/subsys/net/l2/ethernet/ethernet.c
                     ${ZEPHYR_BASE}/lib/net_buf/buf.c
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)

zephyr_code_relocate(FILES
                     ${ZEPHYR_BASE}/kernel/mem_slab.c
                     ${ZEPHYR_BASE}/kernel/mempool.c
                     ${ZEPHYR_BASE}/kernel/msg_q.c
                     ${ZEPHYR_BASE}/kernel/mutex.c
                     ${ZEPHYR_BASE}/kernel/queue.c
                     ${ZEPHYR_BASE}/kernel/sched.c
                     ${ZEPHYR_BASE}/kernel/sem.c
                     ${ZEPHYR_BASE}/kernel/thread.c
                     ${ZEPHYR_BASE}/kernel/work.c
                     LOCATION ${QUICK_ACCESS_CODE_AREA} NOKEEP)

zephyr_code_relocate(FILES
                     ${ZEPHYR_BASE}/lib/net_buf/buf_simple.c
                     ${ZEPHYR_BASE}/subsys/net/lib/sockets/sockets_service.c
                     LOCATION ${QUICK_ACCESS_CODE_AREA_2} NOKEEP)
endif()
endif()

zephyr_library_link_libraries_ifdef(CONFIG_MBEDTLS mbedTLS)
zephyr_library_link_libraries_ifdef(CONFIG_WIFI_NM_WPA_SUPPLICANT hostap)
