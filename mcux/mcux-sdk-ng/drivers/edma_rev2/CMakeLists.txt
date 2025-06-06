# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.edma_rev2)
    mcux_component_version(2.4.4)

    mcux_add_source(SOURCES fsl_edma_rev2.h fsl_edma_rev2.c)

    mcux_add_include(INCLUDES .)

endif()
