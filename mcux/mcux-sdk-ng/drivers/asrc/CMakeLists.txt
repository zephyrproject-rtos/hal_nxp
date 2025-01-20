# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.asrc_edma)
    mcux_component_version(2.2.0)

    mcux_add_source(SOURCES fsl_asrc_edma.h fsl_asrc_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.asrc)
    mcux_component_version(2.1.3)

    mcux_add_source(SOURCES fsl_asrc.h fsl_asrc.c)

    mcux_add_include(INCLUDES .)

endif()
