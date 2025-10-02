# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.tpm)
    mcux_component_version(2.4.1)

    mcux_add_source(SOURCES fsl_tpm.c fsl_tpm.h)

    mcux_add_include(INCLUDES .)

endif()
