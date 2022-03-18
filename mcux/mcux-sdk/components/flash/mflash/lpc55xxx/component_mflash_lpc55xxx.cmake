#Description: mflash lpc55xxx; user_visible: True
include_guard(GLOBAL)
message("component_mflash_lpc55xxx component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/mflash_drv.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)


include(component_mflash_common)
include(driver_iap1)
