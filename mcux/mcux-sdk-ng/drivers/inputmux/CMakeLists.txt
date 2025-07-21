# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.inputmux)
    mcux_component_version(2.0.9)

    mcux_add_source(SOURCES fsl_inputmux.h fsl_inputmux.c)

    mcux_add_include(INCLUDES .)

endif()
