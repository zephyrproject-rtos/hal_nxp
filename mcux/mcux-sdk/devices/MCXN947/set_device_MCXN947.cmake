include_guard(GLOBAL)


if (CONFIG_USE_middleware_baremetal)
# Add set(CONFIG_USE_middleware_baremetal true) in config.cmake to use this component

message("middleware_baremetal component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSDK_OS_BAREMETAL
  )

endif()


endif()


if (CONFIG_USE_utility_incbin)
# Add set(CONFIG_USE_utility_incbin true) in config.cmake to use this component

message("utility_incbin component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_TOOLCHAIN STREQUAL armgcc)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/../../utilities/misc_utilities/fsl_incbin.S
  )
endif()


endif()


if (CONFIG_USE_utilities_misc_utilities)
# Add set(CONFIG_USE_utilities_misc_utilities true) in config.cmake to use this component

message("utilities_misc_utilities component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_TOOLCHAIN STREQUAL armgcc)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/../../utilities/misc_utilities/fsl_sbrk.c
      ${CMAKE_CURRENT_LIST_DIR}/../../utilities/misc_utilities/fsl_syscall_stub.c
  )
endif()

if((CONFIG_TOOLCHAIN STREQUAL armgcc OR CONFIG_TOOLCHAIN STREQUAL mcux) AND CONFIG_CORE STREQUAL cm33)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/../../utilities/misc_utilities/fsl_memcpy.S
  )
endif()


endif()


if (CONFIG_USE_utilities_unity)
# Add set(CONFIG_USE_utilities_unity true) in config.cmake to use this component

message("utilities_unity component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_TOOLCHAIN STREQUAL mcux)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/../../utilities/unity/linkscripts/main_text.ldt
  )
endif()

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/unity/unity.c
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/unity/gcov_support.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/unity/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  if(CONFIG_TOOLCHAIN STREQUAL mcux)
    target_compile_options(${MCUX_SDK_PROJECT_NAME} PUBLIC
    )
  endif()

endif()


endif()


if (CONFIG_USE_driver_rtt_template)
# Add set(CONFIG_USE_driver_rtt_template true) in config.cmake to use this component

message("driver_rtt_template component is included from ${CMAKE_CURRENT_LIST_FILE}.")

add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../components/rtt/template/SEGGER_RTT_Conf.h ${CMAKE_CURRENT_LIST_DIR}/../../components/rtt/template driver_rtt_template.MCXN947)


endif()


if (CONFIG_USE_component_wifi_bt_module_tx_pwr_limits)
# Add set(CONFIG_USE_component_wifi_bt_module_tx_pwr_limits true) in config.cmake to use this component

message("component_wifi_bt_module_tx_pwr_limits component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/wifi_bt_module/AzureWave/tx_pwr_limits
  ${CMAKE_CURRENT_LIST_DIR}/../../components/wifi_bt_module/Murata/tx_pwr_limits
  ${CMAKE_CURRENT_LIST_DIR}/../../components/wifi_bt_module/u-blox/tx_pwr_limits
)


endif()


if (CONFIG_USE_component_wifi_bt_module_config)
# Add set(CONFIG_USE_component_wifi_bt_module_config true) in config.cmake to use this component

message("component_wifi_bt_module_config component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/wifi_bt_module/incl
)


endif()


if (CONFIG_USE_driver_phy-common)
# Add set(CONFIG_USE_driver_phy-common true) in config.cmake to use this component

message("driver_phy-common component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/.
)


endif()


if (CONFIG_USE_driver_pf3000)
# Add set(CONFIG_USE_driver_pf3000 true) in config.cmake to use this component

message("driver_pf3000 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/pf3000/fsl_pf3000.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/pf3000/.
)


endif()


if (CONFIG_USE_driver_pf1550)
# Add set(CONFIG_USE_driver_pf1550 true) in config.cmake to use this component

message("driver_pf1550 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/pf1550/fsl_pf1550.c
  ${CMAKE_CURRENT_LIST_DIR}/../../components/pf1550/fsl_pf1550_charger.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/pf1550/.
)


endif()


if (CONFIG_USE_driver_p3t1755)
# Add set(CONFIG_USE_driver_p3t1755 true) in config.cmake to use this component

message("driver_p3t1755 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/p3t1755/fsl_p3t1755.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/p3t1755/.
)


endif()


if (CONFIG_USE_driver_mx25r_flash)
# Add set(CONFIG_USE_driver_mx25r_flash true) in config.cmake to use this component

message("driver_mx25r_flash component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/mx25r_flash/mx25r_flash.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/mx25r_flash/.
)


endif()


if (CONFIG_USE_component_mflash_common)
# Add set(CONFIG_USE_component_mflash_common true) in config.cmake to use this component

message("component_mflash_common component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/mflash/.
)


endif()


if (CONFIG_USE_driver_nand_flash-common)
# Add set(CONFIG_USE_driver_nand_flash-common true) in config.cmake to use this component

message("driver_nand_flash-common component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/nand/.
)


endif()


if (CONFIG_USE_driver_nor_flash-common)
# Add set(CONFIG_USE_driver_nor_flash-common true) in config.cmake to use this component

message("driver_nor_flash-common component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/nor/.
)


endif()


if (CONFIG_USE_DEVICES_Project_Template_MCXN947)
# Add set(CONFIG_USE_DEVICES_Project_Template_MCXN947 true) in config.cmake to use this component

message("DEVICES_Project_Template_MCXN947 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_lpuart_adapter AND (CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_device_MCXN947_startup AND CONFIG_USE_driver_clock AND CONFIG_USE_driver_common AND CONFIG_USE_driver_gpio AND CONFIG_USE_driver_lpuart AND CONFIG_USE_driver_port AND CONFIG_USE_driver_mcx_spc AND CONFIG_USE_driver_reset AND ((CONFIG_USE_component_serial_manager AND CONFIG_USE_driver_lpflexcomm AND CONFIG_USE_utility_assert AND CONFIG_USE_utility_debug_console) OR (CONFIG_USE_utility_assert_lite AND CONFIG_USE_utility_debug_console_lite)))

add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/board.h "" DEVICES_Project_Template_MCXN947.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/board.c "" DEVICES_Project_Template_MCXN947.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/clock_config.h "" DEVICES_Project_Template_MCXN947.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/clock_config.c "" DEVICES_Project_Template_MCXN947.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/pin_mux.h "" DEVICES_Project_Template_MCXN947.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/pin_mux.c "" DEVICES_Project_Template_MCXN947.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/peripherals.h "" DEVICES_Project_Template_MCXN947.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/peripherals.c "" DEVICES_Project_Template_MCXN947.MCXN947)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/project_template/.
)

else()

message(SEND_ERROR "DEVICES_Project_Template_MCXN947.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_device_MCXN947_startup)
# Add set(CONFIG_USE_device_MCXN947_startup true) in config.cmake to use this component

message("device_MCXN947_startup component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_device_MCXN947_system)

if(CONFIG_TOOLCHAIN STREQUAL armgcc AND CONFIG_CORE STREQUAL cm33 AND CONFIG_CORE_ID STREQUAL cm33_core0)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/./gcc/startup_MCXN947_cm33_core0.S
  )
endif()

if(CONFIG_TOOLCHAIN STREQUAL armgcc AND CONFIG_CORE STREQUAL cm33 AND CONFIG_CORE_ID STREQUAL cm33_core1)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/./gcc/startup_MCXN947_cm33_core1.S
  )
endif()

if(CONFIG_TOOLCHAIN STREQUAL mcux AND CONFIG_CORE STREQUAL cm33 AND CONFIG_CORE_ID STREQUAL cm33_core0)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/./mcuxpresso/startup_mcxn947_cm33_core0.c
      ${CMAKE_CURRENT_LIST_DIR}/./mcuxpresso/startup_mcxn947_cm33_core0.cpp
  )
endif()

if(CONFIG_TOOLCHAIN STREQUAL mcux AND CONFIG_CORE STREQUAL cm33 AND CONFIG_CORE_ID STREQUAL cm33_core1)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/./mcuxpresso/startup_mcxn947_cm33_core1.c
      ${CMAKE_CURRENT_LIST_DIR}/./mcuxpresso/startup_mcxn947_cm33_core1.cpp
  )
endif()

if(CONFIG_TOOLCHAIN STREQUAL mcux)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/./mcuxpresso/boot_multicore_slave.c
  )
endif()

if(CONFIG_TOOLCHAIN STREQUAL mcux)
target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/./mcuxpresso
)
endif()

else()

message(SEND_ERROR "device_MCXN947_startup.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_device_MCXN947_system)
# Add set(CONFIG_USE_device_MCXN947_system true) in config.cmake to use this component

message("device_MCXN947_system component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_device_MCXN947_CMSIS)

if(CONFIG_CORE STREQUAL cm33 AND CONFIG_CORE_ID STREQUAL cm33_core0)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/./system_MCXN947_cm33_core0.c
  )
endif()

if(CONFIG_CORE STREQUAL cm33 AND CONFIG_CORE_ID STREQUAL cm33_core1)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/./system_MCXN947_cm33_core1.c
  )
endif()

if(CONFIG_CORE STREQUAL cm33)
target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/./.
)
endif()

else()

message(SEND_ERROR "device_MCXN947_system.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_device_MCXN947_CMSIS)
# Add set(CONFIG_USE_device_MCXN947_CMSIS true) in config.cmake to use this component

message("device_MCXN947_CMSIS component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_CMSIS_Include_core_cm AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

if(CONFIG_CORE STREQUAL cm33)
target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/./.
)
endif()

else()

message(SEND_ERROR "device_MCXN947_CMSIS.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_RTE_Device)
# Add set(CONFIG_USE_RTE_Device true) in config.cmake to use this component

message("RTE_Device component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_edma4)

add_config_file(${CMAKE_CURRENT_LIST_DIR}/template/RTE_Device.h "" RTE_Device.MCXN947)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/template/.
)

else()

message(SEND_ERROR "RTE_Device.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_serial_manager_uart)
# Add set(CONFIG_USE_component_serial_manager_uart true) in config.cmake to use this component

message("component_serial_manager_uart component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_lpuart_adapter AND CONFIG_USE_component_serial_manager AND (CONFIG_USE_driver_lpuart))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/fsl_component_serial_port_uart.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSERIAL_PORT_TYPE_UART=1
  )

endif()

else()

message(SEND_ERROR "component_serial_manager_uart.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_utility_debug_console_lite)
# Add set(CONFIG_USE_utility_debug_console_lite true) in config.cmake to use this component

message("utility_debug_console_lite component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_lpuart_adapter AND (CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/str/fsl_str.c
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/debug_console_lite/fsl_debug_console.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/str
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/debug_console_lite
)

else()

message(SEND_ERROR "utility_debug_console_lite.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_clock)
# Add set(CONFIG_USE_driver_clock true) in config.cmake to use this component

message("driver_clock component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_mcx_spc AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/drivers/fsl_clock.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_clock.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_edma4)
# Add set(CONFIG_USE_driver_edma4 true) in config.cmake to use this component

message("driver_edma4 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_edma_soc AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/edma4/fsl_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/edma4/.
)

else()

message(SEND_ERROR "driver_edma4.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_edma_soc)
# Add set(CONFIG_USE_driver_edma_soc true) in config.cmake to use this component

message("driver_edma_soc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_edma4 AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/drivers/fsl_edma_soc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_edma_soc.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flexio_mculcd_edma)
# Add set(CONFIG_USE_driver_flexio_mculcd_edma true) in config.cmake to use this component

message("driver_flexio_mculcd_edma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_edma4 AND CONFIG_USE_driver_flexio_mculcd AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/mculcd/fsl_flexio_mculcd_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/mculcd/.
)

else()

message(SEND_ERROR "driver_flexio_mculcd_edma.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flexio_mculcd_smartdma)
# Add set(CONFIG_USE_driver_flexio_mculcd_smartdma true) in config.cmake to use this component

message("driver_flexio_mculcd_smartdma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_lpc_smartdma AND CONFIG_USE_driver_flexio_mculcd)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/mculcd/fsl_flexio_mculcd_smartdma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/mculcd/.
)

else()

message(SEND_ERROR "driver_flexio_mculcd_smartdma.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_trdc_1)
# Add set(CONFIG_USE_driver_trdc_1 true) in config.cmake to use this component

message("driver_trdc_1 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_trdc_soc AND (CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/trdc_1/fsl_trdc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/trdc_1/.
)

else()

message(SEND_ERROR "driver_trdc_1.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_utility_notifier)
# Add set(CONFIG_USE_utility_notifier true) in config.cmake to use this component

message("utility_notifier component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/notifier/fsl_notifier.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/notifier/.
)

else()

message(SEND_ERROR "utility_notifier.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_inputmux_connections)
# Add set(CONFIG_USE_driver_inputmux_connections true) in config.cmake to use this component

message("driver_inputmux_connections component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_inputmux_connections.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_power)
# Add set(CONFIG_USE_driver_power true) in config.cmake to use this component

message("driver_power component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/drivers/fsl_power.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_power.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_common)
# Add set(CONFIG_USE_driver_common true) in config.cmake to use this component

message("driver_common component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_reset AND CONFIG_USE_driver_clock AND CONFIG_USE_device_MCXN947_CMSIS)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/common/fsl_common.c
)

if(CONFIG_CORE STREQUAL cm33)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/../../drivers/common/fsl_common_arm.c
  )
endif()

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/common/.
)

else()

message(SEND_ERROR "driver_common.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_utility_assert)
# Add set(CONFIG_USE_utility_assert true) in config.cmake to use this component

message("utility_assert component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_utility_debug_console AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/assert/fsl_assert.c
)

else()

message(SEND_ERROR "utility_assert.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_utility_assert_lite)
# Add set(CONFIG_USE_utility_assert_lite true) in config.cmake to use this component

message("utility_assert_lite component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_utility_debug_console_lite AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/assert/fsl_assert.c
)

else()

message(SEND_ERROR "utility_assert_lite.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_utility_str)
# Add set(CONFIG_USE_utility_str true) in config.cmake to use this component

message("utility_str component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/str/fsl_str.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/str
)

else()

message(SEND_ERROR "utility_str.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_utility_debug_console)
# Add set(CONFIG_USE_utility_debug_console true) in config.cmake to use this component

message("utility_debug_console component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_serial_manager AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/str/fsl_str.c
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/debug_console/fsl_debug_console.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/str
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/debug_console
)

else()

message(SEND_ERROR "utility_debug_console.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_rtt)
# Add set(CONFIG_USE_driver_rtt true) in config.cmake to use this component

message("driver_rtt component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_rtt_template)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/rtt/RTT/SEGGER_RTT.c
  ${CMAKE_CURRENT_LIST_DIR}/../../components/rtt/RTT/SEGGER_RTT_printf.c
)

if((CONFIG_TOOLCHAIN STREQUAL armgcc OR CONFIG_TOOLCHAIN STREQUAL mcux))
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/../../components/rtt/Syscalls/SEGGER_RTT_Syscalls_GCC.c
  )
endif()

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/rtt/RTT
)

else()

message(SEND_ERROR "driver_rtt.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_sinc)
# Add set(CONFIG_USE_driver_sinc true) in config.cmake to use this component

message("driver_sinc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sinc/fsl_sinc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sinc/.
)

else()

message(SEND_ERROR "driver_sinc.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_tdet)
# Add set(CONFIG_USE_driver_tdet true) in config.cmake to use this component

message("driver_tdet component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/tdet/fsl_tdet.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/tdet/.
)

else()

message(SEND_ERROR "driver_tdet.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_gdet)
# Add set(CONFIG_USE_driver_gdet true) in config.cmake to use this component

message("driver_gdet component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/gdet/fsl_gdet.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/gdet/.
)

else()

message(SEND_ERROR "driver_gdet.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_wwdt)
# Add set(CONFIG_USE_driver_wwdt true) in config.cmake to use this component

message("driver_wwdt component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/wwdt/fsl_wwdt.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/wwdt/.
)

else()

message(SEND_ERROR "driver_wwdt.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_wuu)
# Add set(CONFIG_USE_driver_wuu true) in config.cmake to use this component

message("driver_wuu component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/wuu/fsl_wuu.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/wuu/.
)

else()

message(SEND_ERROR "driver_wuu.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_vref_1)
# Add set(CONFIG_USE_driver_vref_1 true) in config.cmake to use this component

message("driver_vref_1 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/vref_1/fsl_vref.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/vref_1/.
)

else()

message(SEND_ERROR "driver_vref_1.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_utick)
# Add set(CONFIG_USE_driver_utick true) in config.cmake to use this component

message("driver_utick component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/utick/fsl_utick.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/utick/.
)

else()

message(SEND_ERROR "driver_utick.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_usdhc)
# Add set(CONFIG_USE_driver_usdhc true) in config.cmake to use this component

message("driver_usdhc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/usdhc/fsl_usdhc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/usdhc/.
)

else()

message(SEND_ERROR "driver_usdhc.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_tsi_v6)
# Add set(CONFIG_USE_driver_tsi_v6 true) in config.cmake to use this component

message("driver_tsi_v6 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/tsi/tsi_v6/fsl_tsi_v6.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/tsi/tsi_v6/.
)

else()

message(SEND_ERROR "driver_tsi_v6.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_syspm)
# Add set(CONFIG_USE_driver_syspm true) in config.cmake to use this component

message("driver_syspm component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/syspm/fsl_syspm.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/syspm/.
)

else()

message(SEND_ERROR "driver_syspm.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_smartcard_phy_emvsim)
# Add set(CONFIG_USE_driver_smartcard_phy_emvsim true) in config.cmake to use this component

message("driver_smartcard_phy_emvsim component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_smartcard_emvsim AND (CONFIG_DEVICE_ID STREQUAL MCXN947) AND ((CONFIG_BOARD STREQUAL mcxn9xxevk OR CONFIG_BOARD STREQUAL frdmmcxn947)) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/smartcard/fsl_smartcard_phy_emvsim.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/smartcard/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DUSING_PHY_EMVSIM
  )

endif()

else()

message(SEND_ERROR "driver_smartcard_phy_emvsim.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_smartcard_emvsim)
# Add set(CONFIG_USE_driver_smartcard_emvsim true) in config.cmake to use this component

message("driver_smartcard_emvsim component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND ((CONFIG_BOARD STREQUAL mcxn9xxevk OR CONFIG_BOARD STREQUAL frdmmcxn947)) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/smartcard/fsl_smartcard_emvsim.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/smartcard/.
)

else()

message(SEND_ERROR "driver_smartcard_emvsim.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_sctimer)
# Add set(CONFIG_USE_driver_sctimer true) in config.cmake to use this component

message("driver_sctimer component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sctimer/fsl_sctimer.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sctimer/.
)

else()

message(SEND_ERROR "driver_sctimer.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_sai)
# Add set(CONFIG_USE_driver_sai true) in config.cmake to use this component

message("driver_sai component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sai/fsl_sai.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sai/.
)

else()

message(SEND_ERROR "driver_sai.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_sai_edma)
# Add set(CONFIG_USE_driver_sai_edma true) in config.cmake to use this component

message("driver_sai_edma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_sai AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sai/fsl_sai_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sai/.
)

else()

message(SEND_ERROR "driver_sai_edma.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_reset)
# Add set(CONFIG_USE_driver_reset true) in config.cmake to use this component

message("driver_reset component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/drivers/fsl_reset.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_reset.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_pwm)
# Add set(CONFIG_USE_driver_pwm true) in config.cmake to use this component

message("driver_pwm component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pwm/fsl_pwm.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pwm/.
)

else()

message(SEND_ERROR "driver_pwm.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_puf_v3)
# Add set(CONFIG_USE_driver_puf_v3 true) in config.cmake to use this component

message("driver_puf_v3 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/puf_v3/fsl_puf_v3.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/puf_v3/.
)

else()

message(SEND_ERROR "driver_puf_v3.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_powerquad)
# Add set(CONFIG_USE_driver_powerquad true) in config.cmake to use this component

message("driver_powerquad component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/powerquad/fsl_powerquad_data.c
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/powerquad/fsl_powerquad_basic.c
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/powerquad/fsl_powerquad_math.c
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/powerquad/fsl_powerquad_matrix.c
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/powerquad/fsl_powerquad_filter.c
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/powerquad/fsl_powerquad_transform.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/powerquad/.
)

else()

message(SEND_ERROR "driver_powerquad.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_powerquad_cmsis)
# Add set(CONFIG_USE_driver_powerquad_cmsis true) in config.cmake to use this component

message("driver_powerquad_cmsis component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_powerquad AND CONFIG_USE_CMSIS_DSP_Include)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/powerquad/fsl_powerquad_cmsis.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/powerquad/.
)

else()

message(SEND_ERROR "driver_powerquad_cmsis.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_port)
# Add set(CONFIG_USE_driver_port true) in config.cmake to use this component

message("driver_port component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/port/.
)

else()

message(SEND_ERROR "driver_port.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_plu)
# Add set(CONFIG_USE_driver_plu true) in config.cmake to use this component

message("driver_plu component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/plu/fsl_plu.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/plu/.
)

else()

message(SEND_ERROR "driver_plu.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_pint)
# Add set(CONFIG_USE_driver_pint true) in config.cmake to use this component

message("driver_pint component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pint/fsl_pint.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pint/.
)

else()

message(SEND_ERROR "driver_pint.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_pdm)
# Add set(CONFIG_USE_driver_pdm true) in config.cmake to use this component

message("driver_pdm component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pdm/fsl_pdm.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pdm/.
)

else()

message(SEND_ERROR "driver_pdm.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_pdm_edma)
# Add set(CONFIG_USE_driver_pdm_edma true) in config.cmake to use this component

message("driver_pdm_edma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_pdm AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pdm/fsl_pdm_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pdm/.
)

else()

message(SEND_ERROR "driver_pdm_edma.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ostimer)
# Add set(CONFIG_USE_driver_ostimer true) in config.cmake to use this component

message("driver_ostimer component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ostimer/fsl_ostimer.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ostimer/.
)

else()

message(SEND_ERROR "driver_ostimer.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_opamp)
# Add set(CONFIG_USE_driver_opamp true) in config.cmake to use this component

message("driver_opamp component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/opamp/fsl_opamp.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/opamp/.
)

else()

message(SEND_ERROR "driver_opamp.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_mrt)
# Add set(CONFIG_USE_driver_mrt true) in config.cmake to use this component

message("driver_mrt component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mrt/fsl_mrt.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mrt/.
)

else()

message(SEND_ERROR "driver_mrt.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_mcx_vbat)
# Add set(CONFIG_USE_driver_mcx_vbat true) in config.cmake to use this component

message("driver_mcx_vbat component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_vbat/fsl_vbat.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_vbat/.
)

else()

message(SEND_ERROR "driver_mcx_vbat.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_mcx_spc)
# Add set(CONFIG_USE_driver_mcx_spc true) in config.cmake to use this component

message("driver_mcx_spc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_spc/fsl_spc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_spc/.
)

else()

message(SEND_ERROR "driver_mcx_spc.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flashiap)
# Add set(CONFIG_USE_driver_flashiap true) in config.cmake to use this component

message("driver_flashiap component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_romapi/flash/src/fsl_flash.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_romapi/flash
)

else()

message(SEND_ERROR "driver_flashiap.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_mem_interface)
# Add set(CONFIG_USE_driver_mem_interface true) in config.cmake to use this component

message("driver_mem_interface component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_romapi/mem_interface/src/fsl_mem_interface.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_romapi/mem_interface
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_romapi/flash
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_romapi/nboot
)

else()

message(SEND_ERROR "driver_mem_interface.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_runbootloader)
# Add set(CONFIG_USE_driver_runbootloader true) in config.cmake to use this component

message("driver_runbootloader component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_romapi/nboot/src/fsl_nboot.c
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_romapi/runbootloader/src/fsl_runbootloader.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_romapi/mem_interface
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_romapi/flash
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_romapi/nboot
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_romapi/runbootloader
)

else()

message(SEND_ERROR "driver_runbootloader.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_mcx_enet)
# Add set(CONFIG_USE_driver_mcx_enet true) in config.cmake to use this component

message("driver_mcx_enet component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_enet/fsl_enet.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_enet/.
)

else()

message(SEND_ERROR "driver_mcx_enet.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_mcx_cmc)
# Add set(CONFIG_USE_driver_mcx_cmc true) in config.cmake to use this component

message("driver_mcx_cmc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_cmc/fsl_cmc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mcx_cmc/.
)

else()

message(SEND_ERROR "driver_mcx_cmc.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_mailbox)
# Add set(CONFIG_USE_driver_mailbox true) in config.cmake to use this component

message("driver_mailbox component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mailbox/.
)

else()

message(SEND_ERROR "driver_mailbox.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_cmsis_lpuart)
# Add set(CONFIG_USE_driver_cmsis_lpuart true) in config.cmake to use this component

message("driver_cmsis_lpuart component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_lpuart AND CONFIG_USE_CMSIS_Driver_Include_USART AND CONFIG_USE_RTE_Device)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/lpuart/fsl_lpuart_cmsis.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/lpuart/.
)

else()

message(SEND_ERROR "driver_cmsis_lpuart.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lptmr)
# Add set(CONFIG_USE_driver_lptmr true) in config.cmake to use this component

message("driver_lptmr component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lptmr/fsl_lptmr.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lptmr/.
)

else()

message(SEND_ERROR "driver_lptmr.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_cmsis_lpspi)
# Add set(CONFIG_USE_driver_cmsis_lpspi true) in config.cmake to use this component

message("driver_cmsis_lpspi component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_lpspi AND CONFIG_USE_CMSIS_Driver_Include_SPI AND CONFIG_USE_RTE_Device)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/lpspi/fsl_lpspi_cmsis.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/lpspi/.
)

else()

message(SEND_ERROR "driver_cmsis_lpspi.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_cmsis_lpi2c)
# Add set(CONFIG_USE_driver_cmsis_lpi2c true) in config.cmake to use this component

message("driver_cmsis_lpi2c component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_lpi2c AND CONFIG_USE_CMSIS_Driver_Include_I2C AND CONFIG_USE_RTE_Device)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/lpi2c/fsl_lpi2c_cmsis.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/lpi2c/.
)

else()

message(SEND_ERROR "driver_cmsis_lpi2c.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpuart)
# Add set(CONFIG_USE_driver_lpuart true) in config.cmake to use this component

message("driver_lpuart component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common AND CONFIG_USE_driver_lpflexcomm)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/lpuart/fsl_lpuart.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/lpuart/.
)

else()

message(SEND_ERROR "driver_lpuart.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpuart_edma)
# Add set(CONFIG_USE_driver_lpuart_edma true) in config.cmake to use this component

message("driver_lpuart_edma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common AND CONFIG_USE_driver_lpflexcomm)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/lpuart/fsl_lpuart_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/lpuart/.
)

else()

message(SEND_ERROR "driver_lpuart_edma.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpspi)
# Add set(CONFIG_USE_driver_lpspi true) in config.cmake to use this component

message("driver_lpspi component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common AND CONFIG_USE_driver_lpflexcomm)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/lpspi/fsl_lpspi.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/lpspi/.
)

else()

message(SEND_ERROR "driver_lpspi.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpspi_edma)
# Add set(CONFIG_USE_driver_lpspi_edma true) in config.cmake to use this component

message("driver_lpspi_edma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common AND CONFIG_USE_driver_lpflexcomm)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/lpspi/fsl_lpspi_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/lpspi/.
)

else()

message(SEND_ERROR "driver_lpspi_edma.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpi2c)
# Add set(CONFIG_USE_driver_lpi2c true) in config.cmake to use this component

message("driver_lpi2c component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common AND CONFIG_USE_driver_lpflexcomm)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/lpi2c/fsl_lpi2c.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/lpi2c/.
)

else()

message(SEND_ERROR "driver_lpi2c.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpi2c_edma)
# Add set(CONFIG_USE_driver_lpi2c_edma true) in config.cmake to use this component

message("driver_lpi2c_edma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common AND CONFIG_USE_driver_lpflexcomm)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/lpi2c/fsl_lpi2c_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/lpi2c/.
)

else()

message(SEND_ERROR "driver_lpi2c_edma.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpflexcomm_lpuart_freertos)
# Add set(CONFIG_USE_driver_lpflexcomm_lpuart_freertos true) in config.cmake to use this component

message("driver_lpflexcomm_lpuart_freertos component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_lpflexcomm AND CONFIG_USE_driver_lpuart AND CONFIG_USE_middleware_freertos-kernel)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/fsl_lpuart_freertos.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/.
)

else()

message(SEND_ERROR "driver_lpflexcomm_lpuart_freertos.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpflexcomm_lpspi_freertos)
# Add set(CONFIG_USE_driver_lpflexcomm_lpspi_freertos true) in config.cmake to use this component

message("driver_lpflexcomm_lpspi_freertos component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_lpflexcomm AND CONFIG_USE_driver_lpspi AND CONFIG_USE_middleware_freertos-kernel)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/fsl_lpspi_freertos.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/.
)

else()

message(SEND_ERROR "driver_lpflexcomm_lpspi_freertos.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpflexcomm_lpi2c_freertos)
# Add set(CONFIG_USE_driver_lpflexcomm_lpi2c_freertos true) in config.cmake to use this component

message("driver_lpflexcomm_lpi2c_freertos component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_lpflexcomm AND CONFIG_USE_driver_lpi2c AND CONFIG_USE_middleware_freertos-kernel)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/fsl_lpi2c_freertos.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/.
)

else()

message(SEND_ERROR "driver_lpflexcomm_lpi2c_freertos.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpflexcomm)
# Add set(CONFIG_USE_driver_lpflexcomm true) in config.cmake to use this component

message("driver_lpflexcomm component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/fsl_lpflexcomm.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpflexcomm/.
)

else()

message(SEND_ERROR "driver_lpflexcomm.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpcmp)
# Add set(CONFIG_USE_driver_lpcmp true) in config.cmake to use this component

message("driver_lpcmp component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpcmp/fsl_lpcmp.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpcmp/.
)

else()

message(SEND_ERROR "driver_lpcmp.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpc_freqme)
# Add set(CONFIG_USE_driver_lpc_freqme true) in config.cmake to use this component

message("driver_lpc_freqme component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_freqme/fsl_freqme.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_freqme/.
)

else()

message(SEND_ERROR "driver_lpc_freqme.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpadc)
# Add set(CONFIG_USE_driver_lpadc true) in config.cmake to use this component

message("driver_lpadc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpadc/fsl_lpadc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpadc/.
)

else()

message(SEND_ERROR "driver_lpadc.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_itrc)
# Add set(CONFIG_USE_driver_itrc true) in config.cmake to use this component

message("driver_itrc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/itrc/fsl_itrc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/itrc/.
)

else()

message(SEND_ERROR "driver_itrc.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_irtc)
# Add set(CONFIG_USE_driver_irtc true) in config.cmake to use this component

message("driver_irtc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/irtc/fsl_irtc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/irtc/.
)

else()

message(SEND_ERROR "driver_irtc.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_intm)
# Add set(CONFIG_USE_driver_intm true) in config.cmake to use this component

message("driver_intm component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/intm/fsl_intm.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/intm/.
)

else()

message(SEND_ERROR "driver_intm.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_inputmux)
# Add set(CONFIG_USE_driver_inputmux true) in config.cmake to use this component

message("driver_inputmux component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common AND CONFIG_USE_driver_inputmux_connections)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/inputmux/fsl_inputmux.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/inputmux/.
)

else()

message(SEND_ERROR "driver_inputmux.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_i3c_edma)
# Add set(CONFIG_USE_driver_i3c_edma true) in config.cmake to use this component

message("driver_i3c_edma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_i3c AND CONFIG_USE_driver_edma4)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/i3c/fsl_i3c_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/i3c/.
)

else()

message(SEND_ERROR "driver_i3c_edma.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_i3c)
# Add set(CONFIG_USE_driver_i3c true) in config.cmake to use this component

message("driver_i3c component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/i3c/fsl_i3c.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/i3c/.
)

else()

message(SEND_ERROR "driver_i3c.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_gpio)
# Add set(CONFIG_USE_driver_gpio true) in config.cmake to use this component

message("driver_gpio component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/gpio/fsl_gpio.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/gpio/.
)

else()

message(SEND_ERROR "driver_gpio.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flexspi_dma3)
# Add set(CONFIG_USE_driver_flexspi_dma3 true) in config.cmake to use this component

message("driver_flexspi_dma3 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_flexspi)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexspi/flexspi_dma3/fsl_flexspi_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexspi/flexspi_dma3/.
)

else()

message(SEND_ERROR "driver_flexspi_dma3.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flexspi)
# Add set(CONFIG_USE_driver_flexspi true) in config.cmake to use this component

message("driver_flexspi component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexspi/fsl_flexspi.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexspi/.
)

else()

message(SEND_ERROR "driver_flexspi.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flexio_uart)
# Add set(CONFIG_USE_driver_flexio_uart true) in config.cmake to use this component

message("driver_flexio_uart component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_flexio)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/uart/fsl_flexio_uart.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/uart/.
)

else()

message(SEND_ERROR "driver_flexio_uart.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flexio_uart_edma)
# Add set(CONFIG_USE_driver_flexio_uart_edma true) in config.cmake to use this component

message("driver_flexio_uart_edma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_flexio_uart AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/uart/fsl_flexio_uart_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/uart/.
)

else()

message(SEND_ERROR "driver_flexio_uart_edma.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flexio_spi)
# Add set(CONFIG_USE_driver_flexio_spi true) in config.cmake to use this component

message("driver_flexio_spi component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_flexio)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/spi/fsl_flexio_spi.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/spi/.
)

else()

message(SEND_ERROR "driver_flexio_spi.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flexio_spi_edma)
# Add set(CONFIG_USE_driver_flexio_spi_edma true) in config.cmake to use this component

message("driver_flexio_spi_edma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_flexio_spi AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/spi/fsl_flexio_spi_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/spi/.
)

else()

message(SEND_ERROR "driver_flexio_spi_edma.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flexio_mculcd)
# Add set(CONFIG_USE_driver_flexio_mculcd true) in config.cmake to use this component

message("driver_flexio_mculcd component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_flexio AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/mculcd/fsl_flexio_mculcd.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/mculcd/.
)

else()

message(SEND_ERROR "driver_flexio_mculcd.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flexio_i2c_master)
# Add set(CONFIG_USE_driver_flexio_i2c_master true) in config.cmake to use this component

message("driver_flexio_i2c_master component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_flexio)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/i2c/fsl_flexio_i2c_master.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/i2c/.
)

else()

message(SEND_ERROR "driver_flexio_i2c_master.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flexio)
# Add set(CONFIG_USE_driver_flexio true) in config.cmake to use this component

message("driver_flexio component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/fsl_flexio.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexio/.
)

else()

message(SEND_ERROR "driver_flexio.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flexcan)
# Add set(CONFIG_USE_driver_flexcan true) in config.cmake to use this component

message("driver_flexcan component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexcan/fsl_flexcan.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexcan/.
)

else()

message(SEND_ERROR "driver_flexcan.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flexcan_edma)
# Add set(CONFIG_USE_driver_flexcan_edma true) in config.cmake to use this component

message("driver_flexcan_edma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_flexcan AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexcan/fsl_flexcan_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexcan/.
)

else()

message(SEND_ERROR "driver_flexcan_edma.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ewm)
# Add set(CONFIG_USE_driver_ewm true) in config.cmake to use this component

message("driver_ewm component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ewm/fsl_ewm.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ewm/.
)

else()

message(SEND_ERROR "driver_ewm.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_evtg)
# Add set(CONFIG_USE_driver_evtg true) in config.cmake to use this component

message("driver_evtg component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/evtg/fsl_evtg.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/evtg/.
)

else()

message(SEND_ERROR "driver_evtg.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_erm)
# Add set(CONFIG_USE_driver_erm true) in config.cmake to use this component

message("driver_erm component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/erm/fsl_erm.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/erm/.
)

else()

message(SEND_ERROR "driver_erm.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_enc)
# Add set(CONFIG_USE_driver_enc true) in config.cmake to use this component

message("driver_enc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/enc/fsl_enc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/enc/.
)

else()

message(SEND_ERROR "driver_enc.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_eim)
# Add set(CONFIG_USE_driver_eim true) in config.cmake to use this component

message("driver_eim component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/eim/fsl_eim.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/eim/.
)

else()

message(SEND_ERROR "driver_eim.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_dac_1)
# Add set(CONFIG_USE_driver_dac_1 true) in config.cmake to use this component

message("driver_dac_1 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/dac_1/fsl_dac.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/dac_1/.
)

else()

message(SEND_ERROR "driver_dac_1.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_dac14)
# Add set(CONFIG_USE_driver_dac14 true) in config.cmake to use this component

message("driver_dac14 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/dac14/fsl_dac14.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/dac14/.
)

else()

message(SEND_ERROR "driver_dac14.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ctimer)
# Add set(CONFIG_USE_driver_ctimer true) in config.cmake to use this component

message("driver_ctimer component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ctimer/fsl_ctimer.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ctimer/.
)

else()

message(SEND_ERROR "driver_ctimer.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_crc)
# Add set(CONFIG_USE_driver_crc true) in config.cmake to use this component

message("driver_crc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/crc/fsl_crc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/crc/.
)

else()

message(SEND_ERROR "driver_crc.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_cdog)
# Add set(CONFIG_USE_driver_cdog true) in config.cmake to use this component

message("driver_cdog component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/cdog/fsl_cdog.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/cdog/.
)

else()

message(SEND_ERROR "driver_cdog.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_cache_lpcac)
# Add set(CONFIG_USE_driver_cache_lpcac true) in config.cmake to use this component

message("driver_cache_lpcac component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/cache/lpcac_n4a_mcxn/fsl_cache_lpcac.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/cache/lpcac_n4a_mcxn/.
)

else()

message(SEND_ERROR "driver_cache_lpcac.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_cache_cache64)
# Add set(CONFIG_USE_driver_cache_cache64 true) in config.cmake to use this component

message("driver_cache_cache64 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/cache/cache64/fsl_cache.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/cache/cache64/.
)

else()

message(SEND_ERROR "driver_cache_cache64.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpc_smartdma)
# Add set(CONFIG_USE_driver_lpc_smartdma true) in config.cmake to use this component

message("driver_lpc_smartdma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/smartdma/fsl_smartdma.c
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/smartdma/fsl_smartdma_rt500.c
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/smartdma/fsl_smartdma_mcxn.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/smartdma/.
)

else()

message(SEND_ERROR "driver_lpc_smartdma.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_trdc_soc)
# Add set(CONFIG_USE_driver_trdc_soc true) in config.cmake to use this component

message("driver_trdc_soc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_trdc_soc.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_camera-receiver-common)
# Add set(CONFIG_USE_driver_camera-receiver-common true) in config.cmake to use this component

message("driver_camera-receiver-common component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_video-common AND CONFIG_USE_driver_camera-common)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/video/camera/receiver/.
)

else()

message(SEND_ERROR "driver_camera-receiver-common.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_camera-device-common)
# Add set(CONFIG_USE_driver_camera-device-common true) in config.cmake to use this component

message("driver_camera-device-common component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_camera-common AND CONFIG_USE_driver_common)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/video/camera/device/.
)

else()

message(SEND_ERROR "driver_camera-device-common.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_camera-device-sccb)
# Add set(CONFIG_USE_driver_camera-device-sccb true) in config.cmake to use this component

message("driver_camera-device-sccb component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_USE_driver_lpi2c))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/video/camera/device/sccb/fsl_sccb.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/video/camera/device/sccb/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSDK_I2C_BASED_COMPONENT_USED=1
  )

endif()

else()

message(SEND_ERROR "driver_camera-device-sccb.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_camera-device-ov7670)
# Add set(CONFIG_USE_driver_camera-device-ov7670 true) in config.cmake to use this component

message("driver_camera-device-ov7670 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_video-common AND CONFIG_USE_driver_camera-common AND CONFIG_USE_driver_camera-device-common AND CONFIG_USE_driver_camera-device-sccb)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/video/camera/device/ov7670/fsl_ov7670.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/video/camera/device/ov7670/.
)

else()

message(SEND_ERROR "driver_camera-device-ov7670.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_camera-common)
# Add set(CONFIG_USE_driver_camera-common true) in config.cmake to use this component

message("driver_camera-common component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_video-common)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/video/camera/.
)

else()

message(SEND_ERROR "driver_camera-common.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_video-common)
# Add set(CONFIG_USE_driver_video-common true) in config.cmake to use this component

message("driver_video-common component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/video/fsl_video_common.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/video/.
)

else()

message(SEND_ERROR "driver_video-common.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_dbi)
# Add set(CONFIG_USE_driver_dbi true) in config.cmake to use this component

message("driver_dbi component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/video/display/dbi/.
)

else()

message(SEND_ERROR "driver_dbi.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_dbi_flexio_edma)
# Add set(CONFIG_USE_driver_dbi_flexio_edma true) in config.cmake to use this component

message("driver_dbi_flexio_edma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_dbi AND CONFIG_USE_driver_flexio_mculcd AND CONFIG_USE_driver_flexio_mculcd_edma)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/video/display/dbi/flexio/fsl_dbi_flexio_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/video/display/dbi/flexio/.
)

else()

message(SEND_ERROR "driver_dbi_flexio_edma.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_dbi_flexio_smartdma)
# Add set(CONFIG_USE_driver_dbi_flexio_smartdma true) in config.cmake to use this component

message("driver_dbi_flexio_smartdma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_dbi AND CONFIG_USE_driver_flexio_mculcd AND CONFIG_USE_driver_flexio_mculcd_smartdma)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/video/display/dbi/flexio/fsl_dbi_flexio_smartdma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/video/display/dbi/flexio/.
)

else()

message(SEND_ERROR "driver_dbi_flexio_smartdma.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_lpuart_adapter)
# Add set(CONFIG_USE_component_lpuart_adapter true) in config.cmake to use this component

message("component_lpuart_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_lpuart)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/uart/fsl_adapter_lpuart.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/uart/.
)

else()

message(SEND_ERROR "component_lpuart_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_lpuart_dma_adapter)
# Add set(CONFIG_USE_component_lpuart_dma_adapter true) in config.cmake to use this component

message("component_lpuart_dma_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_lpuart_adapter AND CONFIG_USE_component_timer_manager AND (CONFIG_USE_driver_lpuart_edma))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/uart/fsl_adapter_lpuart.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/uart/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DHAL_UART_DMA_ENABLE=1
  )

endif()

else()

message(SEND_ERROR "component_lpuart_dma_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_timer_manager)
# Add set(CONFIG_USE_component_timer_manager true) in config.cmake to use this component

message("component_timer_manager component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_lists AND (CONFIG_USE_component_ctimer_adapter OR CONFIG_USE_component_lptmr_adapter OR CONFIG_USE_component_mrt_adapter OR CONFIG_USE_component_ostimer_adapter))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/timer_manager/fsl_component_timer_manager.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/timer_manager/.
)

else()

message(SEND_ERROR "component_timer_manager.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_ctimer_adapter)
# Add set(CONFIG_USE_component_ctimer_adapter true) in config.cmake to use this component

message("component_ctimer_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_ctimer)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/timer/fsl_adapter_ctimer.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/timer/.
)

else()

message(SEND_ERROR "component_ctimer_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_lptmr_adapter)
# Add set(CONFIG_USE_component_lptmr_adapter true) in config.cmake to use this component

message("component_lptmr_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_lptmr)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/timer/fsl_adapter_lptmr.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/timer/.
)

else()

message(SEND_ERROR "component_lptmr_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_mrt_adapter)
# Add set(CONFIG_USE_component_mrt_adapter true) in config.cmake to use this component

message("component_mrt_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_mrt)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/timer/fsl_adapter_mrt.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/timer/.
)

else()

message(SEND_ERROR "component_mrt_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_ostimer_adapter)
# Add set(CONFIG_USE_component_ostimer_adapter true) in config.cmake to use this component

message("component_ostimer_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_ostimer)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/timer/fsl_adapter_ostimer.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/timer/.
)

else()

message(SEND_ERROR "component_ostimer_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_st7796s)
# Add set(CONFIG_USE_driver_st7796s true) in config.cmake to use this component

message("driver_st7796s component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_dbi)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/st7796s/fsl_st7796s.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/st7796s/.
)

else()

message(SEND_ERROR "driver_st7796s.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ssd1963)
# Add set(CONFIG_USE_driver_ssd1963 true) in config.cmake to use this component

message("driver_ssd1963 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_dbi)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/ssd1963/fsl_ssd1963.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/ssd1963/.
)

else()

message(SEND_ERROR "driver_ssd1963.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_lpspi_adapter)
# Add set(CONFIG_USE_component_lpspi_adapter true) in config.cmake to use this component

message("component_lpspi_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_lpspi)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/spi/fsl_adapter_lpspi.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/spi/.
)

else()

message(SEND_ERROR "component_lpspi_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_silicon_id)
# Add set(CONFIG_USE_component_silicon_id true) in config.cmake to use this component

message("component_silicon_id component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_USE_driver_flashiap AND (CONFIG_DEVICE_ID STREQUAL MCXN947)))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/silicon_id/fsl_silicon_id.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/silicon_id/.
)

else()

message(SEND_ERROR "component_silicon_id.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_utility_shell)
# Add set(CONFIG_USE_utility_shell true) in config.cmake to use this component

message("utility_shell component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_utility_str AND CONFIG_USE_component_lists AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/shell/fsl_shell.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/shell/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DDEBUG_CONSOLE_RX_ENABLE=0
  )

endif()

else()

message(SEND_ERROR "utility_shell.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_serial_manager)
# Add set(CONFIG_USE_component_serial_manager true) in config.cmake to use this component

message("component_serial_manager component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_lists AND (CONFIG_USE_component_serial_manager_uart OR CONFIG_USE_component_serial_manager_usb_cdc OR CONFIG_USE_component_serial_manager_virtual OR CONFIG_USE_component_serial_manager_swo OR CONFIG_USE_component_serial_manager_spi))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/fsl_component_serial_manager.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/.
)

else()

message(SEND_ERROR "component_serial_manager.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_serial_manager_spi)
# Add set(CONFIG_USE_component_serial_manager_spi true) in config.cmake to use this component

message("component_serial_manager_spi component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_serial_manager AND ((CONFIG_USE_driver_lpspi AND CONFIG_USE_component_lpspi_adapter)))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/fsl_component_serial_port_spi.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSERIAL_PORT_TYPE_SPI=1
    -DSERIAL_PORT_TYPE_SPI_MASTER=1
    -DSERIAL_PORT_TYPE_SPI_SLAVE=1
    -DSERIAL_MANAGER_NON_BLOCKING_MODE=1
  )

endif()

else()

message(SEND_ERROR "component_serial_manager_spi.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_serial_manager_usb_cdc)
# Add set(CONFIG_USE_component_serial_manager_usb_cdc true) in config.cmake to use this component

message("component_serial_manager_usb_cdc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_serial_manager AND CONFIG_USE_middleware_usb_device_cdc_external AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/fsl_component_serial_port_usb.c
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/usb_cdc_adapter/usb_device_descriptor.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/.
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/usb_cdc_adapter
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSERIAL_PORT_TYPE_USBCDC=1
    -DDEBUG_CONSOLE_TRANSFER_NON_BLOCKING
    -DUSB_DEVICE_CONFIG_CDC_ACM=1
  )

endif()

else()

message(SEND_ERROR "component_serial_manager_usb_cdc.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_serial_manager_virtual)
# Add set(CONFIG_USE_component_serial_manager_virtual true) in config.cmake to use this component

message("component_serial_manager_virtual component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_serial_manager AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/fsl_component_serial_port_virtual.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSERIAL_PORT_TYPE_VIRTUAL=1
    -DDEBUG_CONSOLE_TRANSFER_NON_BLOCKING
  )

endif()

else()

message(SEND_ERROR "component_serial_manager_virtual.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_serial_manager_swo)
# Add set(CONFIG_USE_component_serial_manager_swo true) in config.cmake to use this component

message("component_serial_manager_swo component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_CORE STREQUAL cm33) AND CONFIG_USE_driver_common AND CONFIG_USE_component_serial_manager)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/fsl_component_serial_port_swo.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSERIAL_PORT_TYPE_SWO=1
  )

endif()

else()

message(SEND_ERROR "component_serial_manager_swo.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_software_rng_adapter)
# Add set(CONFIG_USE_component_software_rng_adapter true) in config.cmake to use this component

message("component_software_rng_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/rng/fsl_adapter_software_rng.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/rng/.
)

else()

message(SEND_ERROR "component_software_rng_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_reset_adapter)
# Add set(CONFIG_USE_component_reset_adapter true) in config.cmake to use this component

message("component_reset_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/reset/fsl_adapter_reset.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/reset/.
)

else()

message(SEND_ERROR "component_reset_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_pwm_ctimer_adapter)
# Add set(CONFIG_USE_component_pwm_ctimer_adapter true) in config.cmake to use this component

message("component_pwm_ctimer_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_ctimer)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/pwm/fsl_adapter_pwm_ctimer.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/pwm/.
)

else()

message(SEND_ERROR "component_pwm_ctimer_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_phy-device-rtl8211f)
# Add set(CONFIG_USE_driver_phy-device-rtl8211f true) in config.cmake to use this component

message("driver_phy-device-rtl8211f component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_phy-common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phyrtl8211f/fsl_phyrtl8211f.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phyrtl8211f/.
)

else()

message(SEND_ERROR "driver_phy-device-rtl8211f.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_phy-device-ksz8081)
# Add set(CONFIG_USE_driver_phy-device-ksz8081 true) in config.cmake to use this component

message("driver_phy-device-ksz8081 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_phy-common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phyksz8081/fsl_phyksz8081.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phyksz8081/.
)

else()

message(SEND_ERROR "driver_phy-device-ksz8081.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_phy-device-dp83848)
# Add set(CONFIG_USE_driver_phy-device-dp83848 true) in config.cmake to use this component

message("driver_phy-device-dp83848 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_phy-common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phydp83848/fsl_phydp83848.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phydp83848/.
)

else()

message(SEND_ERROR "driver_phy-device-dp83848.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_phy-device-ksz8041)
# Add set(CONFIG_USE_driver_phy-device-ksz8041 true) in config.cmake to use this component

message("driver_phy-device-ksz8041 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_phy-common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phyksz8041/fsl_phyksz8041.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phyksz8041/.
)

else()

message(SEND_ERROR "driver_phy-device-ksz8041.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_phy-device-ar8031)
# Add set(CONFIG_USE_driver_phy-device-ar8031 true) in config.cmake to use this component

message("driver_phy-device-ar8031 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_phy-common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phyar8031/fsl_phyar8031.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phyar8031/.
)

else()

message(SEND_ERROR "driver_phy-device-ar8031.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_phy-device-lan8720a)
# Add set(CONFIG_USE_driver_phy-device-lan8720a true) in config.cmake to use this component

message("driver_phy-device-lan8720a component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_phy-common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phylan8720a/fsl_phylan8720a.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phylan8720a/.
)

else()

message(SEND_ERROR "driver_phy-device-lan8720a.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_phy-device-vsc8541)
# Add set(CONFIG_USE_driver_phy-device-vsc8541 true) in config.cmake to use this component

message("driver_phy-device-vsc8541 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_phy-common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phyvsc8541/fsl_phyvsc8541.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phyvsc8541/.
)

else()

message(SEND_ERROR "driver_phy-device-vsc8541.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_phy-device-rtl8201)
# Add set(CONFIG_USE_driver_phy-device-rtl8201 true) in config.cmake to use this component

message("driver_phy-device-rtl8201 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_phy-common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phyrtl8201/fsl_phyrtl8201.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phyrtl8201/.
)

else()

message(SEND_ERROR "driver_phy-device-rtl8201.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_phy-device-lan8741)
# Add set(CONFIG_USE_driver_phy-device-lan8741 true) in config.cmake to use this component

message("driver_phy-device-lan8741 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_phy-common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phylan8741/fsl_phylan8741.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/device/phylan8741/.
)

else()

message(SEND_ERROR "driver_phy-device-lan8741.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_panic)
# Add set(CONFIG_USE_component_panic true) in config.cmake to use this component

message("component_panic component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/panic/fsl_component_panic.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/panic/.
)

else()

message(SEND_ERROR "component_panic.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_mma8652fc)
# Add set(CONFIG_USE_driver_mma8652fc true) in config.cmake to use this component

message("driver_mma8652fc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/mma8652fc/fsl_mma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/mma8652fc/.
)

else()

message(SEND_ERROR "driver_mma8652fc.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_mma8451q)
# Add set(CONFIG_USE_driver_mma8451q true) in config.cmake to use this component

message("driver_mma8451q component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/mma8451q/fsl_mma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/mma8451q/.
)

else()

message(SEND_ERROR "driver_mma8451q.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_mem_manager)
# Add set(CONFIG_USE_component_mem_manager true) in config.cmake to use this component

message("component_mem_manager component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_lists)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/mem_manager/fsl_component_mem_manager.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/mem_manager/.
)

else()

message(SEND_ERROR "component_mem_manager.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_mem_manager_light)
# Add set(CONFIG_USE_component_mem_manager_light true) in config.cmake to use this component

message("component_mem_manager_light component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_lists)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/mem_manager/fsl_component_mem_manager_light.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/mem_manager/.
)

else()

message(SEND_ERROR "component_mem_manager_light.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_log)
# Add set(CONFIG_USE_component_log true) in config.cmake to use this component

message("component_log component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_utility_str)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/log/fsl_component_log.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/log/.
)

else()

message(SEND_ERROR "component_log.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_log_backend_debugconsole)
# Add set(CONFIG_USE_component_log_backend_debugconsole true) in config.cmake to use this component

message("component_log_backend_debugconsole component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_log AND CONFIG_USE_utility_debug_console)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/log/fsl_component_log_backend_debugconsole.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/log/.
)

else()

message(SEND_ERROR "component_log_backend_debugconsole.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_log_backend_debugconsole_lite)
# Add set(CONFIG_USE_component_log_backend_debugconsole_lite true) in config.cmake to use this component

message("component_log_backend_debugconsole_lite component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_log AND CONFIG_USE_utility_debug_console_lite)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/log/fsl_component_log_backend_debugconsole.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/log/.
)

else()

message(SEND_ERROR "component_log_backend_debugconsole_lite.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_log_backend_ringbuffer)
# Add set(CONFIG_USE_component_log_backend_ringbuffer true) in config.cmake to use this component

message("component_log_backend_ringbuffer component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_log)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/log/fsl_component_log_backend_ringbuffer.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/log/.
)

else()

message(SEND_ERROR "component_log_backend_ringbuffer.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_lists)
# Add set(CONFIG_USE_component_lists true) in config.cmake to use this component

message("component_lists component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/lists/fsl_component_generic_list.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/lists/.
)

else()

message(SEND_ERROR "component_lists.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_led)
# Add set(CONFIG_USE_component_led true) in config.cmake to use this component

message("component_led component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_timer_manager AND (CONFIG_USE_component_gpio_adapter))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/led/fsl_component_led.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/led/.
)

else()

message(SEND_ERROR "component_led.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ili9341)
# Add set(CONFIG_USE_driver_ili9341 true) in config.cmake to use this component

message("driver_ili9341 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/ili9341/fsl_ili9341.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/ili9341/.
)

else()

message(SEND_ERROR "driver_ili9341.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_i3c_bus)
# Add set(CONFIG_USE_component_i3c_bus true) in config.cmake to use this component

message("component_i3c_bus component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_lists)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/i3c_bus/fsl_component_i3c.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/i3c_bus/.
)

else()

message(SEND_ERROR "component_i3c_bus.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_i3c_bus_adapter)
# Add set(CONFIG_USE_component_i3c_bus_adapter true) in config.cmake to use this component

message("component_i3c_bus_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_i3c AND CONFIG_USE_component_i3c_bus)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/i3c_bus/fsl_component_i3c_adapter.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/i3c_bus/.
)

else()

message(SEND_ERROR "component_i3c_bus_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_lpi2c_adapter)
# Add set(CONFIG_USE_component_lpi2c_adapter true) in config.cmake to use this component

message("component_lpi2c_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_lpi2c)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/i2c/fsl_adapter_lpi2c.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/i2c/.
)

else()

message(SEND_ERROR "component_lpi2c_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_i3c_adapter)
# Add set(CONFIG_USE_component_i3c_adapter true) in config.cmake to use this component

message("component_i3c_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_i3c)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/i2c/fsl_adapter_i3c.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/i2c/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSDK_I3C_BASED_COMPONENT_USED=1
  )

endif()

else()

message(SEND_ERROR "component_i3c_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_gpio_adapter)
# Add set(CONFIG_USE_component_gpio_adapter true) in config.cmake to use this component

message("component_gpio_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_gpio AND (CONFIG_USE_driver_port))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/gpio/fsl_adapter_gpio.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/gpio/.
)

else()

message(SEND_ERROR "component_gpio_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_fxos8700cq)
# Add set(CONFIG_USE_driver_fxos8700cq true) in config.cmake to use this component

message("driver_fxos8700cq component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/fxos8700cq/fsl_fxos.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/fxos8700cq/.
)

else()

message(SEND_ERROR "driver_fxos8700cq.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ft6x06)
# Add set(CONFIG_USE_driver_ft6x06 true) in config.cmake to use this component

message("driver_ft6x06 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_CMSIS_Driver_Include_I2C)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/ft6x06/fsl_ft6x06.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/ft6x06/.
)

else()

message(SEND_ERROR "driver_ft6x06.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_gt911)
# Add set(CONFIG_USE_driver_gt911 true) in config.cmake to use this component

message("driver_gt911 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/gt911/fsl_gt911.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/gt911/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSDK_I2C_BASED_COMPONENT_USED=1
  )

endif()

else()

message(SEND_ERROR "driver_gt911.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ft5406_rt)
# Add set(CONFIG_USE_driver_ft5406_rt true) in config.cmake to use this component

message("driver_ft5406_rt component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_lpi2c)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/ft5406_rt/fsl_ft5406_rt.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/ft5406_rt/.
)

else()

message(SEND_ERROR "driver_ft5406_rt.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ft5406)
# Add set(CONFIG_USE_driver_ft5406 true) in config.cmake to use this component

message("driver_ft5406 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/ft5406/fsl_ft5406.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/ft5406/.
)

else()

message(SEND_ERROR "driver_ft5406.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_mflash_file)
# Add set(CONFIG_USE_component_mflash_file true) in config.cmake to use this component

message("component_mflash_file component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_mflash_mcxnx4x_onchip OR CONFIG_USE_component_mflash_mcxnx4x_onchip_fmu OR CONFIG_USE_component_mflash_mcxnx4x_flexspi)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/mflash/mflash_file.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/mflash/.
)

else()

message(SEND_ERROR "component_mflash_file.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_mflash_dummy)
# Add set(CONFIG_USE_component_mflash_dummy true) in config.cmake to use this component

message("component_mflash_dummy component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_mflash_file)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/mflash/mflash_dummy.c
)

else()

message(SEND_ERROR "component_mflash_dummy.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_mflash_mcxnx4x_onchip)
# Add set(CONFIG_USE_component_mflash_mcxnx4x_onchip true) in config.cmake to use this component

message("component_mflash_mcxnx4x_onchip component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_mflash_common AND (CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_flashiap)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/mflash/mcxnx4x/mflash_drv.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/mflash/mcxnx4x/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DMFLASH_FILE_BASEADDR=131072
  )

endif()

else()

message(SEND_ERROR "component_mflash_mcxnx4x_onchip.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_mflash_mcxnx4x_onchip_fmu)
# Add set(CONFIG_USE_component_mflash_mcxnx4x_onchip_fmu true) in config.cmake to use this component

message("component_mflash_mcxnx4x_onchip_fmu component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_mflash_common AND (CONFIG_DEVICE_ID STREQUAL MCXN947))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/mflash/mcxnx4x_fmu/mflash_drv.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/mflash/mcxnx4x_fmu/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DMFLASH_FILE_BASEADDR=131072
  )

endif()

else()

message(SEND_ERROR "component_mflash_mcxnx4x_onchip_fmu.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_mflash_mcxnx4x_flexspi)
# Add set(CONFIG_USE_component_mflash_mcxnx4x_flexspi true) in config.cmake to use this component

message("component_mflash_mcxnx4x_flexspi component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_mflash_common AND (CONFIG_DEVICE_ID STREQUAL MCXN947) AND CONFIG_USE_driver_flashiap AND CONFIG_USE_driver_cache_cache64)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/mflash/mcxnx4x_flexspi/mflash_drv.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/mflash/mcxnx4x_flexspi/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DMFLASH_FILE_BASEADDR=134217728
  )

endif()

else()

message(SEND_ERROR "component_mflash_mcxnx4x_flexspi.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_nand_flash-controller-flexspi)
# Add set(CONFIG_USE_driver_nand_flash-controller-flexspi true) in config.cmake to use this component

message("driver_nand_flash-controller-flexspi component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_nand_flash-common AND CONFIG_USE_driver_flexspi)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/nand/flexspi/fsl_flexspi_nand_flash.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/nand/flexspi/.
)

else()

message(SEND_ERROR "driver_nand_flash-controller-flexspi.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_nor_flash-controller-flexspi)
# Add set(CONFIG_USE_driver_nor_flash-controller-flexspi true) in config.cmake to use this component

message("driver_nor_flash-controller-flexspi component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_nor_flash-common AND CONFIG_USE_driver_flexspi)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/nor/flexspi/fsl_flexspi_nor_flash.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/nor/flexspi/.
)

else()

message(SEND_ERROR "driver_nor_flash-controller-flexspi.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_nor_flash-controller-lpspi)
# Add set(CONFIG_USE_driver_nor_flash-controller-lpspi true) in config.cmake to use this component

message("driver_nor_flash-controller-lpspi component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_nor_flash-common AND CONFIG_USE_driver_lpspi)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/nor/lpspi/fsl_lpspi_nor_flash.c
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/nor/lpspi/fsl_lpspi_mem_adapter.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/flash/nor/lpspi/.
)

else()

message(SEND_ERROR "driver_nor_flash-controller-lpspi.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_crc_adapter)
# Add set(CONFIG_USE_component_crc_adapter true) in config.cmake to use this component

message("component_crc_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_crc)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/crc/fsl_adapter_crc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/crc/.
)

else()

message(SEND_ERROR "component_crc_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_software_crc_adapter)
# Add set(CONFIG_USE_component_software_crc_adapter true) in config.cmake to use this component

message("component_software_crc_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/crc/fsl_adapter_software_crc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/crc/.
)

else()

message(SEND_ERROR "component_software_crc_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_wm8960)
# Add set(CONFIG_USE_driver_wm8960 true) in config.cmake to use this component

message("driver_wm8960 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_codec_i2c)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/wm8960/fsl_wm8960.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/wm8960/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSDK_I2C_BASED_COMPONENT_USED=1
    -DBOARD_USE_CODEC=1
    -DCODEC_WM8960_ENABLE
  )

endif()

else()

message(SEND_ERROR "driver_wm8960.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_wm8904)
# Add set(CONFIG_USE_driver_wm8904 true) in config.cmake to use this component

message("driver_wm8904 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_codec_i2c)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/wm8904/fsl_wm8904.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/wm8904/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSDK_I2C_BASED_COMPONENT_USED=1
    -DBOARD_USE_CODEC=1
    -DCODEC_WM8904_ENABLE
  )

endif()

else()

message(SEND_ERROR "driver_wm8904.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_sgtl5000)
# Add set(CONFIG_USE_driver_sgtl5000 true) in config.cmake to use this component

message("driver_sgtl5000 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_codec_i2c)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/sgtl5000/fsl_sgtl5000.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/sgtl5000/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSDK_I2C_BASED_COMPONENT_USED=1
    -DBOARD_USE_CODEC=1
    -DCODEC_SGTL5000_ENABLE
  )

endif()

else()

message(SEND_ERROR "driver_sgtl5000.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_codec_i2c)
# Add set(CONFIG_USE_component_codec_i2c true) in config.cmake to use this component

message("component_codec_i2c component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_USE_component_lpi2c_adapter OR CONFIG_USE_component_i3c_adapter))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/i2c/fsl_codec_i2c.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/i2c/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSDK_I2C_BASED_COMPONENT_USED=1
  )

endif()

else()

message(SEND_ERROR "component_codec_i2c.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_dialog7212)
# Add set(CONFIG_USE_driver_dialog7212 true) in config.cmake to use this component

message("driver_dialog7212 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_codec_i2c)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/da7212/fsl_dialog7212.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/da7212/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSDK_I2C_BASED_COMPONENT_USED=1
    -DBOARD_USE_CODEC=1
    -DCODEC_DA7212_ENABLE
  )

endif()

else()

message(SEND_ERROR "driver_dialog7212.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_cs42888)
# Add set(CONFIG_USE_driver_cs42888 true) in config.cmake to use this component

message("driver_cs42888 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_codec_i2c)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/cs42888/fsl_cs42888.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/cs42888/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSDK_I2C_BASED_COMPONENT_USED=1
    -DCODEC_CS42888_ENABLE
  )

endif()

else()

message(SEND_ERROR "driver_cs42888.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_codec)
# Add set(CONFIG_USE_driver_codec true) in config.cmake to use this component

message("driver_codec component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_USE_component_wm8904_adapter OR CONFIG_USE_component_wm8960_adapter OR CONFIG_USE_component_sgtl_adapter OR CONFIG_USE_component_da7212_adapter OR CONFIG_USE_component_cs42888_adapter OR CONFIG_USE_component_codec_adapters))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/fsl_codec_common.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/.
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DSDK_I2C_BASED_COMPONENT_USED=1
  )

endif()

else()

message(SEND_ERROR "driver_codec.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_codec_adapters)
# Add set(CONFIG_USE_component_codec_adapters true) in config.cmake to use this component

message("component_codec_adapters component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_USE_driver_codec AND CONFIG_USE_component_wm8904_adapter) OR (CONFIG_USE_driver_codec AND CONFIG_USE_component_wm8960_adapter) OR (CONFIG_USE_driver_codec AND CONFIG_USE_component_sgtl_adapter) OR (CONFIG_USE_driver_codec AND CONFIG_USE_component_da7212_adapter) OR (CONFIG_USE_driver_codec AND CONFIG_USE_component_cs42888_adapter))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port/fsl_codec_adapter.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port
)

if(CONFIG_USE_COMPONENT_CONFIGURATION)
  message("===>Import configuration from ${CMAKE_CURRENT_LIST_FILE}")

  target_compile_definitions(${MCUX_SDK_PROJECT_NAME} PUBLIC
    -DCODEC_MULTI_ADAPTERS=1
  )

endif()

else()

message(SEND_ERROR "component_codec_adapters.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_wm8904_adapter)
# Add set(CONFIG_USE_component_wm8904_adapter true) in config.cmake to use this component

message("component_wm8904_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_wm8904 AND CONFIG_USE_driver_codec)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port/wm8904/fsl_codec_wm8904_adapter.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port/wm8904
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port
)

else()

message(SEND_ERROR "component_wm8904_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_wm8960_adapter)
# Add set(CONFIG_USE_component_wm8960_adapter true) in config.cmake to use this component

message("component_wm8960_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_wm8960 AND CONFIG_USE_driver_codec)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port/wm8960/fsl_codec_wm8960_adapter.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port/wm8960
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port
)

else()

message(SEND_ERROR "component_wm8960_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_cs42888_adapter)
# Add set(CONFIG_USE_component_cs42888_adapter true) in config.cmake to use this component

message("component_cs42888_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_cs42888 AND CONFIG_USE_driver_codec)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port/cs42888/fsl_codec_cs42888_adapter.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port/cs42888
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port
)

else()

message(SEND_ERROR "component_cs42888_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_sgtl_adapter)
# Add set(CONFIG_USE_component_sgtl_adapter true) in config.cmake to use this component

message("component_sgtl_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_sgtl5000 AND CONFIG_USE_driver_codec)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port/sgtl5000/fsl_codec_sgtl_adapter.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port/sgtl5000
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port
)

else()

message(SEND_ERROR "component_sgtl_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_da7212_adapter)
# Add set(CONFIG_USE_component_da7212_adapter true) in config.cmake to use this component

message("component_da7212_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_dialog7212 AND CONFIG_USE_driver_codec)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port/da7212/fsl_codec_da7212_adapter.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port/da7212
  ${CMAKE_CURRENT_LIST_DIR}/../../components/codec/port
)

else()

message(SEND_ERROR "component_da7212_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_button)
# Add set(CONFIG_USE_component_button true) in config.cmake to use this component

message("component_button component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_timer_manager AND (CONFIG_USE_component_gpio_adapter))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/button/fsl_component_button.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/button/.
)

else()

message(SEND_ERROR "component_button.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_audio_sai_edma_adapter)
# Add set(CONFIG_USE_component_audio_sai_edma_adapter true) in config.cmake to use this component

message("component_audio_sai_edma_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_sai_edma)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/audio/fsl_adapter_sai.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/audio/.
)

else()

message(SEND_ERROR "component_audio_sai_edma_adapter.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_BOARD_Project_Template_mcxn9xxevk_a8974)
# Add set(CONFIG_USE_BOARD_Project_Template_mcxn9xxevk_a8974 true) in config.cmake to use this component

message("BOARD_Project_Template_mcxn9xxevk_a8974 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_gpio_adapter AND CONFIG_USE_component_lists AND CONFIG_USE_component_lpi2c_adapter AND CONFIG_USE_component_lpuart_adapter AND CONFIG_USE_component_mrt_adapter AND CONFIG_USE_component_serial_manager AND CONFIG_USE_component_serial_manager_uart AND CONFIG_USE_device_MCXN947_CMSIS AND CONFIG_USE_device_MCXN947_startup AND CONFIG_USE_driver_clock AND CONFIG_USE_driver_common AND CONFIG_USE_driver_gpio AND CONFIG_USE_driver_inputmux AND CONFIG_USE_driver_lpi2c AND CONFIG_USE_driver_lpuart AND CONFIG_USE_driver_pint AND CONFIG_USE_driver_port AND CONFIG_USE_utility_assert AND CONFIG_USE_utility_debug_console)

add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/mcxn9xxevk_a8974/project_template/board.c "" BOARD_Project_Template_mcxn9xxevk_a8974.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/mcxn9xxevk_a8974/project_template/board.h "" BOARD_Project_Template_mcxn9xxevk_a8974.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/mcxn9xxevk_a8974/project_template/clock_config.c "" BOARD_Project_Template_mcxn9xxevk_a8974.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/mcxn9xxevk_a8974/project_template/clock_config.h "" BOARD_Project_Template_mcxn9xxevk_a8974.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/mcxn9xxevk_a8974/project_template/pin_mux.c "" BOARD_Project_Template_mcxn9xxevk_a8974.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/mcxn9xxevk_a8974/project_template/pin_mux.h "" BOARD_Project_Template_mcxn9xxevk_a8974.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/mcxn9xxevk_a8974/project_template/peripherals.c "" BOARD_Project_Template_mcxn9xxevk_a8974.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/mcxn9xxevk_a8974/project_template/peripherals.h "" BOARD_Project_Template_mcxn9xxevk_a8974.MCXN947)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../boards/mcxn9xxevk_a8974/project_template/.
)

else()

message(SEND_ERROR "BOARD_Project_Template_mcxn9xxevk_a8974.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_BOARD_Project_Template_frdmmcxn947_a8974)
# Add set(CONFIG_USE_BOARD_Project_Template_frdmmcxn947_a8974 true) in config.cmake to use this component

message("BOARD_Project_Template_frdmmcxn947_a8974 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_gpio_adapter AND CONFIG_USE_component_lists AND CONFIG_USE_component_lpi2c_adapter AND CONFIG_USE_component_lpuart_adapter AND CONFIG_USE_component_mrt_adapter AND CONFIG_USE_component_serial_manager AND CONFIG_USE_component_serial_manager_uart AND CONFIG_USE_device_MCXN947_CMSIS AND CONFIG_USE_device_MCXN947_startup AND CONFIG_USE_driver_clock AND CONFIG_USE_driver_common AND CONFIG_USE_driver_gpio AND CONFIG_USE_driver_inputmux AND CONFIG_USE_driver_lpi2c AND CONFIG_USE_driver_lpuart AND CONFIG_USE_driver_pint AND CONFIG_USE_driver_port AND CONFIG_USE_utility_assert AND CONFIG_USE_utility_debug_console)

add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/frdmmcxn947_a8974/project_template/board.c "" BOARD_Project_Template_frdmmcxn947_a8974.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/frdmmcxn947_a8974/project_template/board.h "" BOARD_Project_Template_frdmmcxn947_a8974.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/frdmmcxn947_a8974/project_template/clock_config.c "" BOARD_Project_Template_frdmmcxn947_a8974.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/frdmmcxn947_a8974/project_template/clock_config.h "" BOARD_Project_Template_frdmmcxn947_a8974.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/frdmmcxn947_a8974/project_template/pin_mux.c "" BOARD_Project_Template_frdmmcxn947_a8974.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/frdmmcxn947_a8974/project_template/pin_mux.h "" BOARD_Project_Template_frdmmcxn947_a8974.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/frdmmcxn947_a8974/project_template/peripherals.c "" BOARD_Project_Template_frdmmcxn947_a8974.MCXN947)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/../../boards/frdmmcxn947_a8974/project_template/peripherals.h "" BOARD_Project_Template_frdmmcxn947_a8974.MCXN947)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../boards/frdmmcxn947_a8974/project_template/.
)

else()

message(SEND_ERROR "BOARD_Project_Template_frdmmcxn947_a8974.MCXN947 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()

