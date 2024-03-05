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


endif()


if (CONFIG_USE_DEVICES_Project_Template_LPC804)
# Add set(CONFIG_USE_DEVICES_Project_Template_LPC804 true) in config.cmake to use this component

message("DEVICES_Project_Template_LPC804 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_miniusart_adapter AND (CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_device_LPC804_startup AND CONFIG_USE_driver_clock AND CONFIG_USE_driver_common AND CONFIG_USE_driver_lpc_gpio AND CONFIG_USE_driver_lpc_iocon_lite AND CONFIG_USE_driver_lpc_miniusart AND CONFIG_USE_driver_power_no_lib AND CONFIG_USE_driver_rom_api AND CONFIG_USE_driver_swm AND CONFIG_USE_utility_assert_lite AND CONFIG_USE_utility_debug_console_lite)

add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/clock_config.h "" DEVICES_Project_Template_LPC804.LPC804)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/clock_config.c "" DEVICES_Project_Template_LPC804.LPC804)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/pin_mux.h "" DEVICES_Project_Template_LPC804.LPC804)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/pin_mux.c "" DEVICES_Project_Template_LPC804.LPC804)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/peripherals.h "" DEVICES_Project_Template_LPC804.LPC804)
add_config_file(${CMAKE_CURRENT_LIST_DIR}/project_template/peripherals.c "" DEVICES_Project_Template_LPC804.LPC804)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/project_template/.
)

else()

message(SEND_ERROR "DEVICES_Project_Template_LPC804.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_device_LPC804_startup)
# Add set(CONFIG_USE_device_LPC804_startup true) in config.cmake to use this component

message("device_LPC804_startup component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_device_LPC804_system)

if(CONFIG_TOOLCHAIN STREQUAL armgcc)
  add_config_file(${CMAKE_CURRENT_LIST_DIR}/./gcc/startup_LPC804.S "" device_LPC804_startup.LPC804)
endif()

if(CONFIG_TOOLCHAIN STREQUAL mcux)
  add_config_file(${CMAKE_CURRENT_LIST_DIR}/./mcuxpresso/startup_lpc804.c "" device_LPC804_startup.LPC804)
  add_config_file(${CMAKE_CURRENT_LIST_DIR}/./mcuxpresso/startup_lpc804.cpp "" device_LPC804_startup.LPC804)
endif()

else()

message(SEND_ERROR "device_LPC804_startup.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_device_LPC804_CMSIS)
# Add set(CONFIG_USE_device_LPC804_CMSIS true) in config.cmake to use this component

message("device_LPC804_CMSIS component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_CMSIS_Include_core_cm AND (CONFIG_DEVICE_ID STREQUAL LPC804))

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/./.
)

else()

message(SEND_ERROR "device_LPC804_CMSIS.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_clock)
# Add set(CONFIG_USE_driver_clock true) in config.cmake to use this component

message("driver_clock component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_rom_api AND CONFIG_USE_driver_power_no_lib AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/drivers/fsl_clock.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_clock.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_utility_debug_console_lite)
# Add set(CONFIG_USE_utility_debug_console_lite true) in config.cmake to use this component

message("utility_debug_console_lite component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_component_miniusart_adapter AND (CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/str/fsl_str.c
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/debug_console_lite/fsl_debug_console.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/str
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/debug_console_lite
)

else()

message(SEND_ERROR "utility_debug_console_lite.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_rom_api)
# Add set(CONFIG_USE_driver_rom_api true) in config.cmake to use this component

message("driver_rom_api component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_DEVICE_ID STREQUAL LPC804))

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_rom_api.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_swm_connections)
# Add set(CONFIG_USE_driver_swm_connections true) in config.cmake to use this component

message("driver_swm_connections component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_DEVICE_ID STREQUAL LPC804))

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_swm_connections.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_syscon_connections)
# Add set(CONFIG_USE_driver_syscon_connections true) in config.cmake to use this component

message("driver_syscon_connections component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_DEVICE_ID STREQUAL LPC804))

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_syscon_connections.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_power_no_lib)
# Add set(CONFIG_USE_driver_power_no_lib true) in config.cmake to use this component

message("driver_power_no_lib component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_DEVICE_ID STREQUAL LPC804))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/drivers/fsl_power.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_power_no_lib.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_common)
# Add set(CONFIG_USE_driver_common true) in config.cmake to use this component

message("driver_common component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_reset AND CONFIG_USE_driver_clock AND CONFIG_USE_device_LPC804_CMSIS)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/common/fsl_common.c
)

if(CONFIG_CORE STREQUAL cm0p)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/../../drivers/common/fsl_common_arm.c
  )
endif()

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/common/.
)

else()

message(SEND_ERROR "driver_common.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_device_LPC804_system)
# Add set(CONFIG_USE_device_LPC804_system true) in config.cmake to use this component

message("device_LPC804_system component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_device_LPC804_CMSIS)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/./system_LPC804.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/./.
)

else()

message(SEND_ERROR "device_LPC804_system.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_utility_assert_lite)
# Add set(CONFIG_USE_utility_assert_lite true) in config.cmake to use this component

message("utility_assert_lite component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_utility_debug_console_lite AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/assert/fsl_assert.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../utilities/assert/.
)

else()

message(SEND_ERROR "utility_assert_lite.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_lpc_crc_adapter)
# Add set(CONFIG_USE_component_lpc_crc_adapter true) in config.cmake to use this component

message("component_lpc_crc_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_lpc_crc)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/crc/fsl_adapter_lpc_crc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/crc/.
)

else()

message(SEND_ERROR "component_lpc_crc_adapter.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "component_software_crc_adapter.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_lpc_i2c_adapter)
# Add set(CONFIG_USE_component_lpc_i2c_adapter true) in config.cmake to use this component

message("component_lpc_i2c_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_lpc_i2c)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/i2c/fsl_adapter_lpc_i2c.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/i2c/.
)

else()

message(SEND_ERROR "component_lpc_i2c_adapter.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "component_lists.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "component_mem_manager.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "component_mem_manager_light.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "component_panic.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "component_pwm_ctimer_adapter.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "component_reset_adapter.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "component_software_rng_adapter.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "component_ctimer_adapter.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

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

message(SEND_ERROR "component_mrt_adapter.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_timer_manager)
# Add set(CONFIG_USE_component_timer_manager true) in config.cmake to use this component

message("component_timer_manager component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_component_lists AND (CONFIG_USE_component_ctimer_adapter OR CONFIG_USE_component_mrt_adapter))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/timer_manager/fsl_component_timer_manager.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/timer_manager/.
)

else()

message(SEND_ERROR "component_timer_manager.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_component_miniusart_adapter)
# Add set(CONFIG_USE_component_miniusart_adapter true) in config.cmake to use this component

message("component_miniusart_adapter component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND CONFIG_USE_driver_lpc_miniusart)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../components/uart/fsl_adapter_miniusart.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../components/uart/.
)

else()

message(SEND_ERROR "component_miniusart_adapter.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_capt)
# Add set(CONFIG_USE_driver_capt true) in config.cmake to use this component

message("driver_capt component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/capt/fsl_capt.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/capt/.
)

else()

message(SEND_ERROR "driver_capt.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpc_crc)
# Add set(CONFIG_USE_driver_lpc_crc true) in config.cmake to use this component

message("driver_lpc_crc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_crc/fsl_crc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_crc/.
)

else()

message(SEND_ERROR "driver_lpc_crc.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_ctimer)
# Add set(CONFIG_USE_driver_ctimer true) in config.cmake to use this component

message("driver_ctimer component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ctimer/fsl_ctimer.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/ctimer/.
)

else()

message(SEND_ERROR "driver_ctimer.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_iap)
# Add set(CONFIG_USE_driver_iap true) in config.cmake to use this component

message("driver_iap component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/iap/fsl_iap.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/iap/.
)

else()

message(SEND_ERROR "driver_iap.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpc_acomp)
# Add set(CONFIG_USE_driver_lpc_acomp true) in config.cmake to use this component

message("driver_lpc_acomp component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_acomp/fsl_acomp.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_acomp/.
)

else()

message(SEND_ERROR "driver_lpc_acomp.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpc_adc)
# Add set(CONFIG_USE_driver_lpc_adc true) in config.cmake to use this component

message("driver_lpc_adc component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_adc/fsl_adc.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_adc/.
)

else()

message(SEND_ERROR "driver_lpc_adc.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpc_dac)
# Add set(CONFIG_USE_driver_lpc_dac true) in config.cmake to use this component

message("driver_lpc_dac component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_dac/fsl_dac.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_dac/.
)

else()

message(SEND_ERROR "driver_lpc_dac.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpc_gpio)
# Add set(CONFIG_USE_driver_lpc_gpio true) in config.cmake to use this component

message("driver_lpc_gpio component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_gpio/fsl_gpio.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_gpio/.
)

else()

message(SEND_ERROR "driver_lpc_gpio.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpc_i2c)
# Add set(CONFIG_USE_driver_lpc_i2c true) in config.cmake to use this component

message("driver_lpc_i2c component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_DEVICE_ID STREQUAL LPC804))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_i2c/fsl_i2c.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_i2c/.
)

else()

message(SEND_ERROR "driver_lpc_i2c.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpc_iocon_lite)
# Add set(CONFIG_USE_driver_lpc_iocon_lite true) in config.cmake to use this component

message("driver_lpc_iocon_lite component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_iocon_lite/.
)

else()

message(SEND_ERROR "driver_lpc_iocon_lite.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpc_minispi)
# Add set(CONFIG_USE_driver_lpc_minispi true) in config.cmake to use this component

message("driver_lpc_minispi component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_minispi/fsl_spi.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_minispi/.
)

else()

message(SEND_ERROR "driver_lpc_minispi.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_lpc_miniusart)
# Add set(CONFIG_USE_driver_lpc_miniusart true) in config.cmake to use this component

message("driver_lpc_miniusart component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_miniusart/fsl_usart.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/lpc_miniusart/.
)

else()

message(SEND_ERROR "driver_lpc_miniusart.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_mrt)
# Add set(CONFIG_USE_driver_mrt true) in config.cmake to use this component

message("driver_mrt component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mrt/fsl_mrt.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/mrt/.
)

else()

message(SEND_ERROR "driver_mrt.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_pint)
# Add set(CONFIG_USE_driver_pint true) in config.cmake to use this component

message("driver_pint component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pint/fsl_pint.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/pint/.
)

else()

message(SEND_ERROR "driver_pint.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_plu)
# Add set(CONFIG_USE_driver_plu true) in config.cmake to use this component

message("driver_plu component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/plu/fsl_plu.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/plu/.
)

else()

message(SEND_ERROR "driver_plu.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_reset)
# Add set(CONFIG_USE_driver_reset true) in config.cmake to use this component

message("driver_reset component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if(CONFIG_USE_driver_common AND (CONFIG_DEVICE_ID STREQUAL LPC804))

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/drivers/fsl_reset.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/drivers/.
)

else()

message(SEND_ERROR "driver_reset.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_swm)
# Add set(CONFIG_USE_driver_swm true) in config.cmake to use this component

message("driver_swm component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common AND CONFIG_USE_driver_swm_connections)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/swm/fsl_swm.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/swm/.
)

else()

message(SEND_ERROR "driver_swm.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_syscon)
# Add set(CONFIG_USE_driver_syscon true) in config.cmake to use this component

message("driver_syscon component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common AND CONFIG_USE_driver_syscon_connections)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/syscon/fsl_syscon.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/syscon/.
)

else()

message(SEND_ERROR "driver_syscon.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_wkt)
# Add set(CONFIG_USE_driver_wkt true) in config.cmake to use this component

message("driver_wkt component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/wkt/fsl_wkt.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/wkt/.
)

else()

message(SEND_ERROR "driver_wkt.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()


if (CONFIG_USE_driver_wwdt)
# Add set(CONFIG_USE_driver_wwdt true) in config.cmake to use this component

message("driver_wwdt component is included from ${CMAKE_CURRENT_LIST_FILE}.")

if((CONFIG_DEVICE_ID STREQUAL LPC804) AND CONFIG_USE_driver_common)

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/wwdt/fsl_wwdt.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/../../drivers/wwdt/.
)

else()

message(SEND_ERROR "driver_wwdt.LPC804 dependency does not meet, please check ${CMAKE_CURRENT_LIST_FILE}.")

endif()

endif()

