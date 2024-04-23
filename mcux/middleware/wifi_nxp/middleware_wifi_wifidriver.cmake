# Add set(CONFIG_USE_middleware_wifi_wifidriver true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_middleware_freertos-kernel AND CONFIG_USE_utility_debug_console AND CONFIG_USE_middleware_wifi_template AND ((CONFIG_USE_middleware_wifi_imu AND CONFIG_USE_middleware_wifi_common_files)))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_11ac.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_11ax.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_11d.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_11h.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_11n.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_11n_aggr.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_11n_rxreorder.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_11v.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_action.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_11k.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_mbo.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_api.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_cfp.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_cmdevt.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_glue.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_init.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_join.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_misc.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_scan.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_shim.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_sta_cmd.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_sta_cmdresp.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_sta_event.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_sta_ioctl.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_sta_rx.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_txrx.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_uap_cmdevent.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_uap_ioctl.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/mlan_wmm.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/wifi-debug.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/wifi-mem.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/wifi-uap.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/wifi.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/wifi_pwrmgr.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/wpa_supp_if/wifi_nxp.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/wpa_supp_if/rtos_wpa_supp_if.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/wpa_supp_if/wifi_nxp_internal.c
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/wifi-wps.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/incl
  ${CMAKE_CURRENT_LIST_DIR}/incl/wlcmgr
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/incl
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/wpa_supp_if
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/wpa_supp_if/incl
  ${CMAKE_CURRENT_LIST_DIR}/certs
  ${CMAKE_CURRENT_LIST_DIR}/firmware_dnld
  ${CMAKE_CURRENT_LIST_DIR}/sdio_nxp_abs
  ${CMAKE_CURRENT_LIST_DIR}/sdio_nxp_abs/incl
)

else()

message(SEND_ERROR "middleware_wifi_wifidriver dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
