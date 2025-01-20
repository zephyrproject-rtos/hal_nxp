# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.snvs_lp)
    mcux_component_version(2.4.6)

    mcux_add_source(SOURCES fsl_snvs_lp.c fsl_snvs_lp.h)

    mcux_add_include(INCLUDES .)

endif()
