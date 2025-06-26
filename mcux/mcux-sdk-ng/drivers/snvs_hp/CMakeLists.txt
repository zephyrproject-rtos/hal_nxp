# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.snvs_hp)
    mcux_component_version(2.3.2)

    mcux_add_source(SOURCES fsl_snvs_hp.c fsl_snvs_hp.h)

    mcux_add_include(INCLUDES .)

endif()
