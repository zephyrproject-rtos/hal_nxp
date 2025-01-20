# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.tsi_v5)
    mcux_component_version(2.6.0)

    mcux_add_source(SOURCES fsl_tsi_v5.h fsl_tsi_v5.c)

    mcux_add_include(INCLUDES .)

endif()
