# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.ltc_dpa)
    mcux_component_version(2.0.8)

    mcux_add_source(SOURCES fsl_ltc_dpa.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.ltc_edma)
    mcux_component_version(2.0.16)

    mcux_add_source(SOURCES fsl_ltc_edma.h fsl_ltc_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.ltc)
    mcux_component_version(2.0.17)

    mcux_add_source(SOURCES fsl_ltc.h fsl_ltc.c)

    mcux_add_include(INCLUDES .)

endif()
