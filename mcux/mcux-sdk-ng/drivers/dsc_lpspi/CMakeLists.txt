# Copyright 2026 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dsc_lpspi)
    mcux_component_version(2.0.1)

    mcux_add_source(SOURCES fsl_lpspi.c fsl_lpspi.h)

    mcux_add_include(INCLUDES .)

endif()
