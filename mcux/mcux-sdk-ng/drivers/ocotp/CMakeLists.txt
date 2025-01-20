# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.ocotp)
    mcux_component_version(2.1.4)

    mcux_add_source(SOURCES fsl_ocotp.h fsl_ocotp.c)

    mcux_add_include(INCLUDES .)

endif()
