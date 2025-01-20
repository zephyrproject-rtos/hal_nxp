# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.enc)
    mcux_component_version(2.2.1)

    mcux_add_source(SOURCES fsl_enc.c fsl_enc.h)

    mcux_add_include(INCLUDES .)

endif()
