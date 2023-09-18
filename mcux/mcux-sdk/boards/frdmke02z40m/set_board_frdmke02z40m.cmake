include_guard(GLOBAL)


if (CONFIG_USE_BOARD_Project_Template_frdmke02z40m)
# Add set(CONFIG_USE_BOARD_Project_Template_frdmke02z40m true) in config.cmake to use this component

message("BOARD_Project_Template_frdmke02z40m component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_BOARD STREQUAL frdmke02z40m) AND CONFIG_USE_component_uart_adapter AND (CONFIG_DEVICE_ID STREQUAL MKE02Z16xxx4 OR CONFIG_DEVICE_ID STREQUAL MKE02Z32xxx4 OR CONFIG_DEVICE_ID STREQUAL MKE02Z64xxx4) AND CONFIG_USE_device_MKE02Z4_startup AND CONFIG_USE_driver_common AND CONFIG_USE_driver_gpio_1 AND CONFIG_USE_driver_port_ke02 AND CONFIG_USE_driver_uart AND ((CONFIG_USE_component_serial_manager AND CONFIG_USE_utility_assert AND CONFIG_USE_utility_debug_console) OR (CONFIG_USE_utility_assert_lite AND CONFIG_USE_utility_debug_console_lite)))

add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/board.h "" BOARD_Project_Template_frdmke02z40m)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/board.c "" BOARD_Project_Template_frdmke02z40m)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/clock_config.h ${CMAKE_CURRENT_LIST_DIR}/project_template/. BOARD_Project_Template_frdmke02z40m)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/clock_config.c "" BOARD_Project_Template_frdmke02z40m)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/pin_mux.h ${CMAKE_CURRENT_LIST_DIR}/project_template/. BOARD_Project_Template_frdmke02z40m)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/pin_mux.c "" BOARD_Project_Template_frdmke02z40m)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/peripherals.h ${CMAKE_CURRENT_LIST_DIR}/project_template/. BOARD_Project_Template_frdmke02z40m)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/peripherals.c "" BOARD_Project_Template_frdmke02z40m)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/project_template/.
)

else()

message(SEND_ERROR "BOARD_Project_Template_frdmke02z40m dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()

