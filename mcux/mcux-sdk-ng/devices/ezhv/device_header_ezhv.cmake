# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_device.CMSIS)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${device} SOURCES fsl_device_registers.h
    "${CONFIG_MCUX_HW_DEVICE_CORE}.h" "${CONFIG_MCUX_HW_DEVICE_CORE}_features.h" "${CONFIG_MCUX_HW_DEVICE_CORE}_COMMON.h" "../${soc_periph}/*.h" CORE_IDS ezhv)

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${soc_periph} INCLUDES .)
    mcux_add_include(BASE_PATH ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${device} INCLUDES .)
endif()

if(CONFIG_MCUX_COMPONENT_device.system)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${device} SOURCES system_${device}_ezhv.c CORE_IDS ezhv)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${device} SOURCES system_${device}_ezhv.h CORE_IDS ezhv)

    mcux_add_include(BASE_PATH ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${device} INCLUDES .)
endif()

if(CONFIG_MCUX_COMPONENT_device.startup)
    mcux_add_source(BASE_PATH ${SdkRootDirPath}/devices/${soc_portfolio}/${soc_series}/${device}
        SOURCES llvm/startup_${device}_ezhv.S TOOLCHAINS riscvllvm CORE_IDS ezhv CONFIG true)
endif()
