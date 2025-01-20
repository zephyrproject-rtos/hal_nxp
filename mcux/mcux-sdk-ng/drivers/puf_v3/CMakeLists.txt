# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.puf_v3)
    mcux_component_version(2.0.3)

    mcux_add_source(SOURCES fsl_puf_v3.h fsl_puf_v3.c)

    mcux_add_include(INCLUDES .)

endif()
