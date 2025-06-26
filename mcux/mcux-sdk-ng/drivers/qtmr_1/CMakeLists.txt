# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.qtmr_1)
    mcux_component_version(2.2.2)

    mcux_add_source(SOURCES fsl_qtmr.c fsl_qtmr.h)

    mcux_add_include(INCLUDES .)

endif()
