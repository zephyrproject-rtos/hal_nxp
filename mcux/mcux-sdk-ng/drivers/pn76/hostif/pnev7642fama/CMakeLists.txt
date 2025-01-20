# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.pn76_pnev7642fama_hostif)
    mcux_component_version(2.1.2)

    mcux_add_source(SOURCES fsl_hostif.h fsl_hostif.c)

    mcux_add_include(INCLUDES .)

endif()
