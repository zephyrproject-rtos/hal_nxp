# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.dcdc_1)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_dcdc.c fsl_dcdc.h)

    mcux_add_include(INCLUDES .)

endif()
