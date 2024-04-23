# Add set(CONFIG_USE_middleware_wifi_imu true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_middleware_wifi_common_files AND CONFIG_USE_component_wireless_imu_adapter AND CONFIG_USE_component_osa_free_rtos AND CONFIG_USE_driver_imu)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver/wifi-imu.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/wifidriver
)

else()

message(SEND_ERROR "middleware_wifi_imu dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
