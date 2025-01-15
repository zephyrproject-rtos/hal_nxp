#Description: device_startup; user_visible: False
include_guard(GLOBAL)
message("device_startup component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/gcc/startup_MCXW727C_cm33_core1.S
)
include(device_system_MCXN947_cm33_core0)

if(CONFIG_CORE_ID STREQUAL cm33_core1)
  target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
      ${CMAKE_CURRENT_LIST_DIR}/gcc/startup_MCXW727C_cm33_core1.S
  )
  include(device_system_MCXN947_cm33_core1)
endif()
