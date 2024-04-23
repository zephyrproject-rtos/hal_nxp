# Add set(CONFIG_USE_middleware_wifi_cli true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_middleware_wifi AND CONFIG_USE_middleware_wifi_wifidriver AND CONFIG_USE_middleware_lwip_apps_lwiperf AND CONFIG_USE_utility_debug_console)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/cli/cli.c
  ${CMAKE_CURRENT_LIST_DIR}/cli/cli_mem_simple.c
  ${CMAKE_CURRENT_LIST_DIR}/cli/cli_utils.c
  ${CMAKE_CURRENT_LIST_DIR}/cli/wifi_shell.c
  ${CMAKE_CURRENT_LIST_DIR}/nw_utils/wifi_ping.c
  ${CMAKE_CURRENT_LIST_DIR}/nw_utils/iperf.c
  ${CMAKE_CURRENT_LIST_DIR}/nw_utils/init_enet.c
  ${CMAKE_CURRENT_LIST_DIR}/nw_utils/telnet/telnet_server.c
  ${CMAKE_CURRENT_LIST_DIR}/wlcmgr/wlan_basic_cli.c
  ${CMAKE_CURRENT_LIST_DIR}/wlcmgr/wlan_enhanced_tests.c
  ${CMAKE_CURRENT_LIST_DIR}/wlcmgr/wlan_tests.c
  ${CMAKE_CURRENT_LIST_DIR}/wlcmgr/wlan_test_mode_tests.c
  ${CMAKE_CURRENT_LIST_DIR}/dhcpd/dhcp-server-cli.c
  ${CMAKE_CURRENT_LIST_DIR}/port/os/os_cli.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/cli
  ${CMAKE_CURRENT_LIST_DIR}/incl
  ${CMAKE_CURRENT_LIST_DIR}/incl/wlcmgr
  ${CMAKE_CURRENT_LIST_DIR}/nw_utils
  ${CMAKE_CURRENT_LIST_DIR}/nw_utils/telnet
)

else()

message(SEND_ERROR "middleware_wifi_cli dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
