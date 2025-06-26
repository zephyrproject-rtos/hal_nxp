# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.easrc_sdma)
    mcux_component_version(2.0.3)

    mcux_add_source(SOURCES fsl_asrc_sdma.h fsl_asrc_sdma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.easrc)
    mcux_component_version(2.0.6)

    mcux_add_source(
        SOURCES
        fsl_asrc.h
        fsl_asrc_firmware.h
        fsl_asrc.c
    )

    mcux_add_include(INCLUDES .)

endif()
