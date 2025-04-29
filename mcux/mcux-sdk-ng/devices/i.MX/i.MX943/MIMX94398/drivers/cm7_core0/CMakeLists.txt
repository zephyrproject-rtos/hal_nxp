# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause
if (CONFIG_MCUX_COMPONENT_driver.irqsteer_1_soc.cm7_core0)
    mcux_component_version(1.0.0)
    mcux_add_source(
            SOURCES fsl_irqsteer_soc.h fsl_irqsteer_soc.c )
    mcux_add_include(
            INCLUDES . )
endif()
