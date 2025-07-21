# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.isi)
    mcux_component_version(2.0.3)

    mcux_add_source(SOURCES fsl_isi.c fsl_isi.h)

    mcux_add_include(INCLUDES .)

endif()
