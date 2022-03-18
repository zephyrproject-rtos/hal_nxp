#Description: Driver dbi_flexio_smartdma; user_visible: True
include_guard(GLOBAL)
message("driver_dbi_flexio_smartdma component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/fsl_dbi_flexio_smartdma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)


include(driver_flexio_mculcd_smartdma)
include(driver_dbi)
