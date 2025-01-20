# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.pmc0)
    mcux_component_version(2.1.1)

    mcux_add_source(SOURCES fsl_pmc0.h)

    mcux_add_include(INCLUDES .)

endif()
