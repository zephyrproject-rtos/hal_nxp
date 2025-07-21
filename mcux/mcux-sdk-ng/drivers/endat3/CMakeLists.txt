# Copyright 2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.endat3)
    mcux_component_version(1.0.0)

    mcux_add_source(SOURCES fsl_endat3.h fsl_endat3.c endat3_mem_defs.h)

    mcux_add_include(INCLUDES .)

endif()
