# Add set(CONFIG_USE_middleware_wifi_wps true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_middleware_wifi AND CONFIG_USE_middleware_wifi_wifidriver AND CONFIG_USE_middleware_wifi_wmtime AND CONFIG_USE_middleware_wifi_wmcrypto)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/wps/wps_eapol.c
  ${CMAKE_CURRENT_LIST_DIR}/wps/wps_l2.c
  ${CMAKE_CURRENT_LIST_DIR}/wps/wps_main.c
  ${CMAKE_CURRENT_LIST_DIR}/wps/wps_mem.c
  ${CMAKE_CURRENT_LIST_DIR}/wps/wps_msg.c
  ${CMAKE_CURRENT_LIST_DIR}/wps/wps_os.c
  ${CMAKE_CURRENT_LIST_DIR}/wps/wps_start.c
  ${CMAKE_CURRENT_LIST_DIR}/wps/wps_state.c
  ${CMAKE_CURRENT_LIST_DIR}/wps/wps_wlan.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/wps
  ${CMAKE_CURRENT_LIST_DIR}/incl/wps
)

else()

message(SEND_ERROR "middleware_wifi_wps dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
