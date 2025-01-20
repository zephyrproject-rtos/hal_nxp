# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.tmu_3)
    mcux_component_version(2.1.0)

    mcux_add_source(SOURCES fsl_tmu.c fsl_tmu.h)

    mcux_add_include(INCLUDES .)

endif()
