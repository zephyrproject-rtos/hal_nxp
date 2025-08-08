# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.mflash_offchip)
    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        INCLUDES 
            .
    )
    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        INCLUDES 
            ./frdmimxrt1186
        BOARDS frdmimxrt1186
    )
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        SOURCES 
            mflash_common.h
            mflash_file.c
            mflash_file.h
    )
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        SOURCES 
            ./frdmimxrt1186/mflash_drv.c
            ./frdmimxrt1186/mflash_drv.h
        BOARDS frdmimxrt1186
    )

    mcux_add_macro(
        "-DMFLASH_FILE_BASEADDR=14221312"
    )
endif()
