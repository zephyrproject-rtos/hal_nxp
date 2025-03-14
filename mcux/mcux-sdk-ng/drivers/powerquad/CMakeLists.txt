# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.powerquad)
    mcux_component_version(2.2.0)

    mcux_add_source(
        SOURCES
        fsl_powerquad_data.h
        fsl_powerquad_data.c
        fsl_powerquad.h
        fsl_powerquad_basic.c
        fsl_powerquad_math.c
        fsl_powerquad_matrix.c
        fsl_powerquad_filter.c
        fsl_powerquad_transform.c
    )

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.powerquad_cmsis)
    mcux_component_version(2.0.4)

    mcux_add_source(SOURCES fsl_powerquad.h fsl_powerquad_cmsis.c)

    mcux_add_include(INCLUDES .)

endif()
