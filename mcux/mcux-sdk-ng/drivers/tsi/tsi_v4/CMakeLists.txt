# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.tsi_v4)
    mcux_component_version(2.1.3)

    mcux_add_source(SOURCES fsl_tsi_v4.h fsl_tsi_v4.c)

    mcux_add_include(INCLUDES .)

endif()
