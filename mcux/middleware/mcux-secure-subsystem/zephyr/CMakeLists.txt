#-------------------------------------------------------------------------------
# Copyright 2024-2026 NXP
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------
set(MCUX_SECURE_SUBSYSTEM_PATH ${CMAKE_CURRENT_LIST_DIR}/../)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

if(CONFIG_MCUX_SECURE_SUBSYSTEM)
	add_subdirectory(${MCUX_SECURE_SUBSYSTEM_PATH}/cmake secure-subsystem)
	target_link_libraries(app PUBLIC McuxSecureSubSystem)
	zephyr_include_directories("$<TARGET_PROPERTY:McuxSecureSubSystem,INTERFACE_INCLUDE_DIRECTORIES>")
endif()
