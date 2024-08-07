#Description: Flash Driver; user_visible: True
include_guard(GLOBAL)
message("driver_flash_k4 component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/fsl_k4_flash.c
    ${CMAKE_CURRENT_LIST_DIR}/fsl_k4_controller.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)

include(driver_common)
