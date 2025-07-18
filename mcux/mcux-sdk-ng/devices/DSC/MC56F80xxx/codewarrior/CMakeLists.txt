# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### device common startup
if(CONFIG_MCUX_COMPONENT_device.startup_common)
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/codewarrior
        SOURCES Cpu.h
                Flash_config.c
                Flash_config.h
                ${soc_series}_init.asm
        TOOLCHAINS codewarrior
        CONFIG true
    )

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/codewarrior INCLUDES .)
endif()
