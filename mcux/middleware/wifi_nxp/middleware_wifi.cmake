# Add set(CONFIG_USE_middleware_wifi true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_middleware_freertos-kernel AND CONFIG_USE_utility_debug_console AND CONFIG_USE_middleware_wifi_wifidriver AND CONFIG_USE_middleware_wifi_template AND CONFIG_USE_middleware_lwip)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/dhcpd/dhcp-server-main.c
  ${CMAKE_CURRENT_LIST_DIR}/dhcpd/dhcp-server.c
  ${CMAKE_CURRENT_LIST_DIR}/dhcpd/dns-server.c
  ${CMAKE_CURRENT_LIST_DIR}/port/net/net.c
  ${CMAKE_CURRENT_LIST_DIR}/port/net/wifi_netif.c
  ${CMAKE_CURRENT_LIST_DIR}/wlcmgr/wlan.c
  ${CMAKE_CURRENT_LIST_DIR}/wlcmgr/wlan_txpwrlimit_cfg.c
  ${CMAKE_CURRENT_LIST_DIR}/port/net/hooks/lwip_default_hooks.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/dhcpd
  ${CMAKE_CURRENT_LIST_DIR}/incl
  ${CMAKE_CURRENT_LIST_DIR}/incl/port/net
  ${CMAKE_CURRENT_LIST_DIR}/port/net
  ${CMAKE_CURRENT_LIST_DIR}/incl/port/net/hooks
)

else()

message(SEND_ERROR "middleware_wifi dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
