# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

set(BLE_LIBS_PATH       ${ZEPHYR_HAL_NXP_MODULE_DIR}/zephyr/blobs/mcxw23)
set(BLELIBOS_PATH       ${BLE_LIBS_PATH}/libble_ll_os.a)
set(BLELIBUTILS_PATH    ${BLE_LIBS_PATH}/libble_ll_utils_os.a)

zephyr_blobs_verify(FILES
                        ${BLELIBOS_PATH}
                        ${BLELIBUTILS_PATH}
                   )

add_library(ble_lib_os STATIC IMPORTED GLOBAL)
add_library(ble_lib_utils STATIC IMPORTED GLOBAL)

set_target_properties(ble_lib_os PROPERTIES IMPORTED_LOCATION ${BLELIBOS_PATH})
set_target_properties(ble_lib_utils PROPERTIES IMPORTED_LOCATION ${BLELIBUTILS_PATH})

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE ble_lib_os ble_lib_utils)

zephyr_compile_definitions(gUseHciTransportDownward_d=1)
zephyr_compile_definitions(BLE=1)
zephyr_compile_definitions(SUPPORT_MASTER_CONNECTION=1)
zephyr_compile_definitions(SUPPORT_SLAVE_CONNECTION=1)
zephyr_compile_definitions(OSA_USED=1U)

zephyr_include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/interface/snps_controller/sdk_integration
    ${CMAKE_CURRENT_LIST_DIR}/interface/snps_controller/ble_controller
    ${CMAKE_CURRENT_LIST_DIR}/interface/snps_controller/shrd_utils
)

zephyr_library_sources(
    ${CMAKE_CURRENT_LIST_DIR}/src/snps/sdk_integration/ble_controller.c
    ${CMAKE_CURRENT_LIST_DIR}/src/snps/sdk_integration/os_interface.c
)
