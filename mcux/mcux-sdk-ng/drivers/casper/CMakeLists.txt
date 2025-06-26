# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.casper)
    mcux_component_version(2.2.4)

    mcux_add_source(SOURCES fsl_casper.h fsl_casper.c)

    mcux_add_include(INCLUDES .)

endif()
