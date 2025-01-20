# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.ci_pi)
    mcux_component_version(2.0.2)

    mcux_add_source(SOURCES fsl_ci_pi.c fsl_ci_pi.h)

    mcux_add_include(INCLUDES .)

endif()
