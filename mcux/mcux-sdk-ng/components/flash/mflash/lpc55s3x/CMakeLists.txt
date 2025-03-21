# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.mflash_onchip)
    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        INCLUDES 
            .
            ./lpc55s3x
    )
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        SOURCES 
            mflash_common.h
            mflash_file.c
            mflash_file.h
            ./lpc55s3x/mflash_drv.c
            ./lpc55s3x/mflash_drv.h
    )

    mcux_add_macro(
        "-DMFLASH_FILE_BASEADDR=131072 -DMFLASH_ON_CHIP=1"
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.mflash_offchip)
    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        INCLUDES 
            .
            ./lpc55s3x_flexspi
    )
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        SOURCES 
            mflash_common.h
            mflash_file.c
            mflash_file.h
            ./lpc55s3x_flexspi/mflash_drv.c
            ./lpc55s3x_flexspi/mflash_drv.h
    )

    mcux_add_configuration(
        CC "-DMFLASH_FILE_BASEADDR=134217728 -DMFLASH_OFF_CHIP=1"
    )
endif()
