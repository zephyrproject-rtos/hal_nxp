# Copyright 2026 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.mflash_offchip)
    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        INCLUDES
            .
            ./frdmimxrt700
        BOARDS frdmimxrt700
    )
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        SOURCES
            mflash_common.h
            mflash_file.c
            mflash_file.h
            ./frdmimxrt700/mflash_drv.c
            ./frdmimxrt700/mflash_drv.h
        BOARDS frdmimxrt700
    )

    mcux_add_macro(
        "-DMFLASH_FILE_BASEADDR=7340032"
    )
endif()
