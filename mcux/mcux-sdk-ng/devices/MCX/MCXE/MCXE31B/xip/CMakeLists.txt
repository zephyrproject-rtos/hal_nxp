# Copyright 2026 NXP
#
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_device.boot_header)
    mcux_add_source(
        SOURCES boot_header.c
                boot_header.h
    )

    mcux_add_include(
        INCLUDES .
    )

    mcux_add_configuration(
        CC "-DBOOT_HEADER_ENABLE=1"
        CX "-DBOOT_HEADER_ENABLE=1"
    )
endif()
