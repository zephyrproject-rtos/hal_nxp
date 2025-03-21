# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.iap)
    mcux_component_version(2.0.7)

    mcux_add_source(SOURCES fsl_iap.h fsl_iap.c)

    mcux_add_include(INCLUDES .)

endif()
