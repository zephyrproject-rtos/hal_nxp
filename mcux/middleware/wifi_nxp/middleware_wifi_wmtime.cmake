# Add set(CONFIG_USE_middleware_wifi_wmtime true) in config.cmake to use this component

include_guard(GLOBAL)
message("${CMAKE_CURRENT_LIST_FILE} component is included.")

if(CONFIG_USE_middleware_wifi AND CONFIG_USE_middleware_wifi_wifidriver)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/wmtime/wmtime.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/wmtime
  ${CMAKE_CURRENT_LIST_DIR}/incl
)

else()

message(SEND_ERROR "middleware_wifi_wmtime dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()
