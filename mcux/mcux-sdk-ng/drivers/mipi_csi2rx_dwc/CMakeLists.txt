# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.mipi_csi2rx_dwc)
    mcux_component_version(2.0.0)

    mcux_add_source(
        SOURCES
        fsl_dwc_mipi_csi2rx.c
        fsl_dwc_mipi_csi2rx.h
        fsl_dwc_mipi_dphy.c
        fsl_dwc_mipi_dphy.h
    )

    mcux_add_include(INCLUDES .)

endif()
