# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.wireless_imu_adapter)
    mcux_add_source(
        SOURCES fsl_adapter_imu_common.h
                fsl_adapter_imu.h
                fsl_adapter_imu.c
    )
    mcux_add_include(
        INCLUDES ./
    )
endif()
