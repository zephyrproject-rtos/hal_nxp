#Description: mflash lpc54xxx; user_visible: True
include_guard(GLOBAL)
message("component_mflash_lpc54xxx component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/mflash_drv.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)


include(driver_spifi)
include(component_mflash_common)
