#Description: LTC EDMA Driver; user_visible: True
include_guard(GLOBAL)
message("driver_ltc_edma component is included.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/fsl_ltc_edma.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/.
)


include(driver_edma_MCIMX7U5)
include(driver_ltc)
