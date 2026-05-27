# Copyright 2024, 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.sdhc)
    mcux_component_version(2.1.14)

    mcux_add_source(SOURCES fsl_sdhc.h fsl_sdhc.c)

    mcux_add_include(INCLUDES .)

endif()
