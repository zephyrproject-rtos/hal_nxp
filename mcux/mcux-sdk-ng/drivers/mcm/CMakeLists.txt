# Copyright 2024-2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.mcm)
    mcux_component_version(2.2.1)

    mcux_add_source(SOURCES fsl_mcm.h)

    mcux_add_include(INCLUDES .)

endif()
