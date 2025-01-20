# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.mflash_onchip)
    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        INCLUDES 
            .
            ./frdmk64f
    )
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        SOURCES 
            mflash_common.h
            mflash_file.c
            mflash_file.h
            ./frdmk64f/mflash_drv.c
            ./frdmk64f/mflash_drv.h
    )

    mcux_add_macro(
        "-DMFLASH_FILE_BASEADDR=983040"
    )
endif()
