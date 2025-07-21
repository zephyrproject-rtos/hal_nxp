# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.endat2p2)
    mcux_component_version(1.0.1)

    mcux_add_source(SOURCES fsl_endat2p2.c fsl_endat2p2.h)

    mcux_add_include(INCLUDES .)

endif()
