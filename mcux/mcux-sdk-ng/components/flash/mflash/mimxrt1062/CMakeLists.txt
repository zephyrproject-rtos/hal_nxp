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
            ./mimxrt1062
        BOARDS evkbmimxrt1060
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
            ./mimxrt1062/mflash_drv.c
            ./mimxrt1062/mflash_drv.h
        BOARDS evkbmimxrt1060
    )

    mcux_add_macro(
        "-DMFLASH_FILE_BASEADDR=7340032"
    )
endif()
