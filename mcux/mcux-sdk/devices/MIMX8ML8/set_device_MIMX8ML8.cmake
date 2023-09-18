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


if (CONFIG_USE_utilities_misc_utilities)
# Add set(CONFIG_USE_utilities_misc_utilities true) in config.cmake to use this component

message("utilities_misc_utilities component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_TOOLCHAIN STREQUAL armgcc)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/../../utilities/misc_utilities/fsl_sbrk.c
      ${CMAKE_CURRENT_LIST_DIR}/../../utilities/misc_utilities/fsl_syscall_stub.c
  )
endif()

if(CONFIG_CORE STREQUAL cm7f AND (CONFIG_TOOLCHAIN STREQUAL armgcc OR CONFIG_TOOLCHAIN STREQUAL mcux))
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/../../utilities/misc_utilities/fsl_memcpy.S
  )
endif()


endif()


if (CONFIG_USE_driver_phy-common)
# Add set(CONFIG_USE_driver_phy-common true) in config.cmake to use this component

message("driver_phy-common component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/phy/.
)


endif()


if (CONFIG_USE_driver_srtm)
# Add set(CONFIG_USE_driver_srtm true) in config.cmake to use this component

message("driver_srtm component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/srtm/srtm/srtm_channel.c
  ${CMAKE_CURRENT_LIST_DIR}/../../components/srtm/srtm/srtm_dispatcher.c
  ${CMAKE_CURRENT_LIST_DIR}/../../components/srtm/srtm/srtm_message.c
  ${CMAKE_CURRENT_LIST_DIR}/../../components/srtm/srtm/srtm_peercore.c
  ${CMAKE_CURRENT_LIST_DIR}/../../components/srtm/srtm/srtm_service.c
  ${CMAKE_CURRENT_LIST_DIR}/../../components/srtm/port/srtm_message_pool.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/srtm/include
  ${CMAKE_CURRENT_LIST_DIR}/../../components/srtm/srtm
  ${CMAKE_CURRENT_LIST_DIR}/../../components/srtm/port
)


endif()


if (CONFIG_USE_DEVICES_Project_Template_MIMX8ML8)
# Add set(CONFIG_USE_DEVICES_Project_Template_MIMX8ML8 true) in config.cmake to use this component

message("DEVICES_Project_Template_MIMX8ML8 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_device_MIMX8ML8_CMSIS AND CONFIG_USE_device_MIMX8ML8_startup AND CONFIG_USE_driver_audiomix AND CONFIG_USE_driver_clock AND CONFIG_USE_driver_common AND CONFIG_USE_driver_iuart AND CONFIG_USE_driver_rdc AND ((CONFIG_USE_utility_assert AND CONFIG_USE_utility_debug_console) OR (CONFIG_USE_utility_assert_lite AND CONFIG_USE_utility_debug_console_lite)))

add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/board.h "" DEVICES_Project_Template_MIMX8ML8.MIMX8ML8)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/board.c "" DEVICES_Project_Template_MIMX8ML8.MIMX8ML8)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/clock_config.h "" DEVICES_Project_Template_MIMX8ML8.MIMX8ML8)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/clock_config.c "" DEVICES_Project_Template_MIMX8ML8.MIMX8ML8)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/pin_mux.h "" DEVICES_Project_Template_MIMX8ML8.MIMX8ML8)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/pin_mux.c "" DEVICES_Project_Template_MIMX8ML8.MIMX8ML8)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/peripherals.h "" DEVICES_Project_Template_MIMX8ML8.MIMX8ML8)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/peripherals.c "" DEVICES_Project_Template_MIMX8ML8.MIMX8ML8)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/project_template/.
)

else()

message(SEND_ERROR "DEVICES_Project_Template_MIMX8ML8.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_device_MIMX8ML8_CMSIS)
# Add set(CONFIG_USE_device_MIMX8ML8_CMSIS true) in config.cmake to use this component

message("device_MIMX8ML8_CMSIS component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_CMSIS_Include_core_cm AND (CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ))

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/./.
)

else()

message(SEND_ERROR "device_MIMX8ML8_CMSIS.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_RTE_Device)
# Add set(CONFIG_USE_RTE_Device true) in config.cmake to use this component

message("RTE_Device component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ))

add_config_file(${CMAKE_CURRENT_LIST_DIR}/template/RTE_Device.h "" RTE_Device.MIMX8ML8)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/template/.
)

else()

message(SEND_ERROR "RTE_Device.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_clock)
# Add set(CONFIG_USE_driver_clock true) in config.cmake to use this component

message("driver_clock component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/drivers/fsl_clock.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_clock.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_audiomix)
# Add set(CONFIG_USE_driver_audiomix true) in config.cmake to use this component

message("driver_audiomix component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/drivers/fsl_audiomix.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_audiomix.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_enet)
# Add set(CONFIG_USE_driver_enet true) in config.cmake to use this component

message("driver_enet component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_memory AND (CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/enet/fsl_enet.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/enet/.
)

else()

message(SEND_ERROR "driver_enet.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_sdma)
# Add set(CONFIG_USE_driver_sdma true) in config.cmake to use this component

message("driver_sdma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_memory AND (CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sdma/fsl_sdma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sdma/.
)

else()

message(SEND_ERROR "driver_sdma.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_cache_armv7_m7)
# Add set(CONFIG_USE_driver_cache_armv7_m7 true) in config.cmake to use this component

message("driver_cache_armv7_m7 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_CORE STREQUAL cm7f) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/cache/armv7-m7/fsl_cache.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/cache/armv7-m7/.
)

else()

message(SEND_ERROR "driver_cache_armv7_m7.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ecspi_sdma)
# Add set(CONFIG_USE_driver_ecspi_sdma true) in config.cmake to use this component

message("driver_ecspi_sdma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_sdma AND CONFIG_USE_driver_ecspi)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ecspi/fsl_ecspi_sdma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ecspi/.
)

else()

message(SEND_ERROR "driver_ecspi_sdma.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_iuart_sdma)
# Add set(CONFIG_USE_driver_iuart_sdma true) in config.cmake to use this component

message("driver_iuart_sdma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_sdma AND CONFIG_USE_driver_iuart)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/iuart/fsl_uart_sdma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/iuart/.
)

else()

message(SEND_ERROR "driver_iuart_sdma.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_sai_sdma)
# Add set(CONFIG_USE_driver_sai_sdma true) in config.cmake to use this component

message("driver_sai_sdma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_sdma AND CONFIG_USE_driver_sai)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sai/fsl_sai_sdma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sai/.
)

else()

message(SEND_ERROR "driver_sai_sdma.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_serial_manager_uart)
# Add set(CONFIG_USE_component_serial_manager_uart true) in config.cmake to use this component

message("component_serial_manager_uart component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_iuart_adapter AND CONFIG_USE_component_serial_manager AND (CONFIG_USE_driver_iuart))

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

message(SEND_ERROR "component_serial_manager_uart.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_utility_debug_console_lite)
# Add set(CONFIG_USE_utility_debug_console_lite true) in config.cmake to use this component

message("utility_debug_console_lite component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_iuart_adapter AND (CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/str/fsl_str.c
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/debug_console_lite/fsl_debug_console.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/str
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/debug_console_lite
)

else()

message(SEND_ERROR "utility_debug_console_lite.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_iomuxc)
# Add set(CONFIG_USE_driver_iomuxc true) in config.cmake to use this component

message("driver_iomuxc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ))

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_iomuxc.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_memory)
# Add set(CONFIG_USE_driver_memory true) in config.cmake to use this component

message("driver_memory component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ))

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_memory.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_device_MIMX8ML8_system)
# Add set(CONFIG_USE_device_MIMX8ML8_system true) in config.cmake to use this component

message("device_MIMX8ML8_system component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_device_MIMX8ML8_CMSIS)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/./system_MIMX8ML8_cm7.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/./.
)

else()

message(SEND_ERROR "device_MIMX8ML8_system.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_device_MIMX8ML8_startup)
# Add set(CONFIG_USE_device_MIMX8ML8_startup true) in config.cmake to use this component

message("device_MIMX8ML8_startup component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_device_MIMX8ML8_system)

if(CONFIG_TOOLCHAIN STREQUAL armgcc)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/./gcc/startup_MIMX8ML8_cm7.S
  )
endif()

if(CONFIG_TOOLCHAIN STREQUAL mcux)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/./mcuxpresso/startup_MIMX8ML8_cm7.c
      ${CMAKE_CURRENT_LIST_DIR}/./mcuxpresso/startup_MIMX8ML8_cm7.cpp
  )
endif()

else()

message(SEND_ERROR "device_MIMX8ML8_startup.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_utility_assert)
# Add set(CONFIG_USE_utility_assert true) in config.cmake to use this component

message("utility_assert component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_utility_debug_console)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/assert/fsl_assert.c
)

else()

message(SEND_ERROR "utility_assert.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_utility_assert_lite)
# Add set(CONFIG_USE_utility_assert_lite true) in config.cmake to use this component

message("utility_assert_lite component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_utility_debug_console_lite)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/assert/fsl_assert.c
)

else()

message(SEND_ERROR "utility_assert_lite.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "utility_str.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "utility_debug_console.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_cmsis_ecspi)
# Add set(CONFIG_USE_driver_cmsis_ecspi true) in config.cmake to use this component

message("driver_cmsis_ecspi component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_ecspi AND CONFIG_USE_CMSIS_Driver_Include_SPI AND CONFIG_USE_RTE_Device)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/ecspi/fsl_ecspi_cmsis.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/ecspi/.
)

else()

message(SEND_ERROR "driver_cmsis_ecspi.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_cmsis_enet)
# Add set(CONFIG_USE_driver_cmsis_enet true) in config.cmake to use this component

message("driver_cmsis_enet component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_enet AND CONFIG_USE_CMSIS_Driver_Include_Ethernet_MAC AND CONFIG_USE_CMSIS_Driver_Include_Ethernet_PHY AND CONFIG_USE_CMSIS_Driver_Include_Ethernet AND CONFIG_USE_RTE_Device AND CONFIG_USE_driver_phy-common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/enet/fsl_enet_cmsis.c
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/enet/fsl_enet_phy_cmsis.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/enet/.
)

else()

message(SEND_ERROR "driver_cmsis_enet.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_cmsis_ii2c)
# Add set(CONFIG_USE_driver_cmsis_ii2c true) in config.cmake to use this component

message("driver_cmsis_ii2c component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_ii2c AND CONFIG_USE_CMSIS_Driver_Include_I2C AND CONFIG_USE_RTE_Device)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/ii2c/fsl_i2c_cmsis.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/ii2c/.
)

else()

message(SEND_ERROR "driver_cmsis_ii2c.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_cmsis_iuart)
# Add set(CONFIG_USE_driver_cmsis_iuart true) in config.cmake to use this component

message("driver_cmsis_iuart component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_iuart AND CONFIG_USE_CMSIS_Driver_Include_USART AND CONFIG_USE_RTE_Device)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/iuart/fsl_uart_cmsis.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../cmsis_drivers/iuart/.
)

else()

message(SEND_ERROR "driver_cmsis_iuart.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_codec)
# Add set(CONFIG_USE_driver_codec true) in config.cmake to use this component

message("driver_codec component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_USE_component_wm8960_adapter OR CONFIG_USE_component_codec_adapters))

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

message(SEND_ERROR "driver_codec.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_codec_adapters)
# Add set(CONFIG_USE_component_codec_adapters true) in config.cmake to use this component

message("component_codec_adapters component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_USE_driver_codec AND CONFIG_USE_component_wm8960_adapter))

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

message(SEND_ERROR "component_codec_adapters.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "component_wm8960_adapter.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_codec_i2c)
# Add set(CONFIG_USE_component_codec_i2c true) in config.cmake to use this component

message("component_codec_i2c component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_USE_component_ii2c_adapter))

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

message(SEND_ERROR "component_codec_i2c.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_ii2c_adapter)
# Add set(CONFIG_USE_component_ii2c_adapter true) in config.cmake to use this component

message("component_ii2c_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_ii2c)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/i2c/fsl_adapter_ii2c.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/i2c/.
)

else()

message(SEND_ERROR "component_ii2c_adapter.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "component_lists.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "driver_phy-device-rtl8211f.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_serial_manager)
# Add set(CONFIG_USE_component_serial_manager true) in config.cmake to use this component

message("component_serial_manager component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_lists AND (CONFIG_USE_component_serial_manager_uart OR CONFIG_USE_component_serial_manager_virtual OR CONFIG_USE_component_serial_manager_swo))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/fsl_component_serial_manager.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/serial_manager/.
)

else()

message(SEND_ERROR "component_serial_manager.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "component_serial_manager_virtual.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_serial_manager_swo)
# Add set(CONFIG_USE_component_serial_manager_swo true) in config.cmake to use this component

message("component_serial_manager_swo component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_CORE STREQUAL cm7f) AND CONFIG_USE_driver_common AND CONFIG_USE_component_serial_manager)

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

message(SEND_ERROR "component_serial_manager_swo.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_silicon_id_imx8)
# Add set(CONFIG_USE_component_silicon_id_imx8 true) in config.cmake to use this component

message("component_silicon_id_imx8 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_component_silicon_id)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/silicon_id/socs/imx8/fsl_silicon_id_soc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/silicon_id/socs/imx8/..
)

else()

message(SEND_ERROR "component_silicon_id_imx8.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_silicon_id)
# Add set(CONFIG_USE_component_silicon_id true) in config.cmake to use this component

message("component_silicon_id component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_USE_driver_common AND CONFIG_USE_component_silicon_id_imx8))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/silicon_id/fsl_silicon_id.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/silicon_id/.
)

else()

message(SEND_ERROR "component_silicon_id.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_srtm_freertos)
# Add set(CONFIG_USE_driver_srtm_freertos true) in config.cmake to use this component

message("driver_srtm_freertos component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_srtm)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/srtm/port/srtm_heap_freertos.c
  ${CMAKE_CURRENT_LIST_DIR}/../../components/srtm/port/srtm_mutex_freertos.c
  ${CMAKE_CURRENT_LIST_DIR}/../../components/srtm/port/srtm_sem_freertos.c
)

else()

message(SEND_ERROR "driver_srtm_freertos.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_iuart_adapter)
# Add set(CONFIG_USE_component_iuart_adapter true) in config.cmake to use this component

message("component_iuart_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_iuart)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/uart/fsl_adapter_iuart.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/uart/.
)

else()

message(SEND_ERROR "component_iuart_adapter.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "driver_wm8960.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_common)
# Add set(CONFIG_USE_driver_common true) in config.cmake to use this component

message("driver_common component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_clock AND CONFIG_USE_device_MIMX8ML8_CMSIS)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/common/fsl_common.c
)

if(CONFIG_CORE STREQUAL cm7f)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/../../drivers/common/fsl_common_arm.c
  )
endif()

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/common/.
)

else()

message(SEND_ERROR "driver_common.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_easrc)
# Add set(CONFIG_USE_driver_easrc true) in config.cmake to use this component

message("driver_easrc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/easrc/fsl_asrc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/easrc/.
)

else()

message(SEND_ERROR "driver_easrc.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_easrc_sdma)
# Add set(CONFIG_USE_driver_easrc_sdma true) in config.cmake to use this component

message("driver_easrc_sdma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_easrc AND CONFIG_USE_driver_sdma AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/easrc/fsl_asrc_sdma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/easrc/.
)

else()

message(SEND_ERROR "driver_easrc_sdma.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ecspi)
# Add set(CONFIG_USE_driver_ecspi true) in config.cmake to use this component

message("driver_ecspi component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ecspi/fsl_ecspi.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ecspi/.
)

else()

message(SEND_ERROR "driver_ecspi.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ecspi_freertos)
# Add set(CONFIG_USE_driver_ecspi_freertos true) in config.cmake to use this component

message("driver_ecspi_freertos component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_ecspi AND CONFIG_USE_middleware_freertos-kernel)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ecspi/fsl_ecspi_freertos.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ecspi/.
)

else()

message(SEND_ERROR "driver_ecspi_freertos.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_flexcan)
# Add set(CONFIG_USE_driver_flexcan true) in config.cmake to use this component

message("driver_flexcan component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexcan/fsl_flexcan.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/flexcan/.
)

else()

message(SEND_ERROR "driver_flexcan.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_gpc_2)
# Add set(CONFIG_USE_driver_gpc_2 true) in config.cmake to use this component

message("driver_gpc_2 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/gpc_2/fsl_gpc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/gpc_2/.
)

else()

message(SEND_ERROR "driver_gpc_2.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_gpt)
# Add set(CONFIG_USE_driver_gpt true) in config.cmake to use this component

message("driver_gpt component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/gpt/fsl_gpt.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/gpt/.
)

else()

message(SEND_ERROR "driver_gpt.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_igpio)
# Add set(CONFIG_USE_driver_igpio true) in config.cmake to use this component

message("driver_igpio component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/igpio/fsl_gpio.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/igpio/.
)

else()

message(SEND_ERROR "driver_igpio.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ii2c)
# Add set(CONFIG_USE_driver_ii2c true) in config.cmake to use this component

message("driver_ii2c component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ii2c/fsl_i2c.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ii2c/.
)

else()

message(SEND_ERROR "driver_ii2c.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ii2c_freertos)
# Add set(CONFIG_USE_driver_ii2c_freertos true) in config.cmake to use this component

message("driver_ii2c_freertos component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_ii2c AND CONFIG_USE_middleware_freertos-kernel)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ii2c/fsl_i2c_freertos.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ii2c/.
)

else()

message(SEND_ERROR "driver_ii2c_freertos.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ipwm)
# Add set(CONFIG_USE_driver_ipwm true) in config.cmake to use this component

message("driver_ipwm component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ipwm/fsl_pwm.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ipwm/.
)

else()

message(SEND_ERROR "driver_ipwm.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_iuart)
# Add set(CONFIG_USE_driver_iuart true) in config.cmake to use this component

message("driver_iuart component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/iuart/fsl_uart.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/iuart/.
)

else()

message(SEND_ERROR "driver_iuart.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_iuart_freertos)
# Add set(CONFIG_USE_driver_iuart_freertos true) in config.cmake to use this component

message("driver_iuart_freertos component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_iuart AND CONFIG_USE_middleware_freertos-kernel)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/iuart/fsl_uart_freertos.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/iuart/.
)

else()

message(SEND_ERROR "driver_iuart_freertos.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_mu)
# Add set(CONFIG_USE_driver_mu true) in config.cmake to use this component

message("driver_mu component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mu/fsl_mu.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mu/.
)

else()

message(SEND_ERROR "driver_mu.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_pdm)
# Add set(CONFIG_USE_driver_pdm true) in config.cmake to use this component

message("driver_pdm component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pdm/fsl_pdm.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pdm/.
)

else()

message(SEND_ERROR "driver_pdm.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_pdm_sdma)
# Add set(CONFIG_USE_driver_pdm_sdma true) in config.cmake to use this component

message("driver_pdm_sdma component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_pdm AND (CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pdm/fsl_pdm_sdma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pdm/.
)

else()

message(SEND_ERROR "driver_pdm_sdma.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_rdc)
# Add set(CONFIG_USE_driver_rdc true) in config.cmake to use this component

message("driver_rdc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/rdc/fsl_rdc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/rdc/.
)

else()

message(SEND_ERROR "driver_rdc.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_rdc_sema42)
# Add set(CONFIG_USE_driver_rdc_sema42 true) in config.cmake to use this component

message("driver_rdc_sema42 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/rdc_sema42/fsl_rdc_sema42.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/rdc_sema42/.
)

else()

message(SEND_ERROR "driver_rdc_sema42.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_sai)
# Add set(CONFIG_USE_driver_sai true) in config.cmake to use this component

message("driver_sai component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sai/fsl_sai.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sai/.
)

else()

message(SEND_ERROR "driver_sai.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_sema4)
# Add set(CONFIG_USE_driver_sema4 true) in config.cmake to use this component

message("driver_sema4 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sema4/fsl_sema4.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/sema4/.
)

else()

message(SEND_ERROR "driver_sema4.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_tmu_2)
# Add set(CONFIG_USE_driver_tmu_2 true) in config.cmake to use this component

message("driver_tmu_2 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/tmu_2/fsl_tmu.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/tmu_2/.
)

else()

message(SEND_ERROR "driver_tmu_2.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_wdog01)
# Add set(CONFIG_USE_driver_wdog01 true) in config.cmake to use this component

message("driver_wdog01 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxLZ OR CONFIG_DEVICE_ID STREQUAL MIMX8ML8xxxKZ) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/wdog01/fsl_wdog.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/wdog01/.
)

else()

message(SEND_ERROR "driver_wdog01.MIMX8ML8 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()

