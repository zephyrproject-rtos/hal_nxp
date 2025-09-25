# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.mflash_onchip)
    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        INCLUDES
            .
            ./mcxe3x
    )
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        SOURCES
            mflash_common.h
            mflash_file.c
            mflash_file.h
            ./mcxe3x/mflash_drv.c
            ./mcxe3x/mflash_drv.h
    )
# default mflash_file address 0x100000
    mcux_add_macro(
        "-DMFLASH_FILE_BASEADDR=1048576"
    )
endif()
