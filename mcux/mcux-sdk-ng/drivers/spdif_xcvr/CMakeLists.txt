# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.spdif_xcvr)
    mcux_component_version(1.0.0)

    mcux_add_source(SOURCES fsl_spdif.h fsl_spdif.c)

    mcux_add_include(INCLUDES .)

endif()
