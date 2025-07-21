# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_driver.flexio_qspi_smartdma)
    mcux_component_version(2.0.1)

    mcux_add_source(
        SOURCES
            fsl_flexio_qspi_smartdma.c
            fsl_flexio_qspi_smartdma.h
    )

    mcux_add_include(
        INCLUDES .
    )

endif()

if (CONFIG_MCUX_COMPONENT_driver.flexio_qspi_edma)
    mcux_component_version(2.0.0)

    mcux_add_source(
        SOURCES
            fsl_flexio_qspi_edma.c
            fsl_flexio_qspi_edma.h
    )

    mcux_add_include(
        INCLUDES .
    )

endif()

if (CONFIG_MCUX_COMPONENT_driver.flexio_qspi)
    mcux_component_version(2.0.0)

    mcux_add_source(
        SOURCES
            fsl_flexio_qspi.c
            fsl_flexio_qspi.h
    )

    mcux_add_include(
        INCLUDES .
    )

endif()
