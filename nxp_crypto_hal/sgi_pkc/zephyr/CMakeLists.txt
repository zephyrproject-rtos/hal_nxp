#---------------------------------------------
# Copyright 2026 NXP.
# SPDX-License-Identifier: BSD-3-Clause
#---------------------------------------------

# Set base path for the SGI PKC component
set(SGI_PKC_BASE ${CMAKE_CURRENT_LIST_DIR}/../)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

if(CONFIG_SGI_PKC AND NOT CONFIG_BUILD_WITH_TFM)
    add_subdirectory(
    ${CMAKE_CURRENT_LIST_DIR}/../cmake
    ${CMAKE_CURRENT_BINARY_DIR}/sgi_pkc_cmake
    )
    target_link_libraries(app PUBLIC McuxSgiPkc)
    zephyr_include_directories("$<TARGET_PROPERTY:McuxSgiPkc,INTERFACE_INCLUDE_DIRECTORIES>")
endif() ## SGI_PKC