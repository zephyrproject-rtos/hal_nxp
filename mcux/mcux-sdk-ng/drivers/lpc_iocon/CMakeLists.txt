# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.lpc_iocon)
    mcux_component_version(2.2.0)

    mcux_add_source(SOURCES fsl_iocon.h)

    mcux_add_include(INCLUDES .)

endif()
