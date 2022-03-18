#Description: driver_cmsis_lpc_gpio; user_visible: True
include_guard(GLOBAL)
message("driver_cmsis_lpc_gpio component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/fsl_gpio_cmsis.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)


include(CMSIS_Driver_Include_GPIO)
include(driver_lpc_gpio)
include(driver_pint)
