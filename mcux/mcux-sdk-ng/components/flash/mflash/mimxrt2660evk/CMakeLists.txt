# Copyright 2026 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.mflash_offchip)
    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        INCLUDES
            .
            ./mimxrt2660evk
    )
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/components/flash/mflash
        SOURCES
            mflash_common.h
            mflash_file.c
            mflash_file.h
            ./mimxrt2660evk/mflash_drv.c
            ./mimxrt2660evk/mflash_drv.h
    )

    mcux_add_macro(
        # 0xD90000 (13.56 MB) -- aligned with the convention used by the
        # mimxrt1170evkb / mimxrt1180 / frdmimxrt1186 mflash ports, so a
        # littlefs image written on one of those boards has a stable offset
        # when migrated to / OTA-pushed to RT2660 EVK.
        "-DMFLASH_FILE_BASEADDR=14221312"
    )
endif()
