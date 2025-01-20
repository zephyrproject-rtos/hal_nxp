# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.mipi_csi2rx)
    mcux_component_version(2.0.4)

    mcux_add_source(SOURCES fsl_mipi_csi2rx.c fsl_mipi_csi2rx.h)

    mcux_add_include(INCLUDES .)

endif()
