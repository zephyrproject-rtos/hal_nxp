#
# 2023-11-03 - Created by Sendrato.com
# SPDX-License-Identifier: Apache-2.0
#

zephyr_include_directories(
    interface
    config
    host
)

zephyr_library_sources(
    config/controller_config.c
)

zephyr_library_import(
    k32_libBleController
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib_ble_controller.a
)

if ((CONFIG_CODE_DATA_RELOCATION) AND ("${MCUX_DEVICE}" STREQUAL "QN9090"))
    zephyr_code_relocate(FILES config/controller_config.c LOCATION SRAM1_BSS)
    zephyr_code_relocate(FILES ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib_ble_controller.a LOCATION SRAM1_BSS)
endif()