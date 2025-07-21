# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexio_a-format)
    mcux_component_version(1.0.0)

    mcux_add_source(SOURCES fsl_flexio_a-format.c fsl_flexio_a-format.h)

    mcux_add_include(INCLUDES .)

endif()
