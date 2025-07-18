# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.edma)
    mcux_component_version(2.4.5)

    mcux_add_source(SOURCES fsl_edma.h fsl_edma.c)

    mcux_add_include(INCLUDES .)

endif()
