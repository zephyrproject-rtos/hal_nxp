# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.mflash_onchip)
    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        INCLUDES
            .
            ./mcxw71
    )
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        SOURCES
            mflash_common.h
            mflash_file.c
            mflash_file.h
            ./mcxw71/mflash_drv.c
            ./mcxw71/mflash_drv.h
    )

    mcux_add_macro(
        "-DMFLASH_FILE_BASEADDR=0x00700000"
    )
endif()
