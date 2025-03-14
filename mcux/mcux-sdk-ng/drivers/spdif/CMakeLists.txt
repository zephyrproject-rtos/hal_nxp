# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.spdif_edma)
    mcux_component_version(2.0.8)

    mcux_add_source(SOURCES fsl_spdif_edma.h fsl_spdif_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.spdif)
    mcux_component_version(2.0.7)

    mcux_add_source(SOURCES fsl_spdif.h fsl_spdif.c)

    mcux_add_include(INCLUDES .)

endif()
