# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.qspi_mcxe247)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES socs/mcxe247/fsl_qspi_soc.c socs/mcxe247/fsl_qspi_soc.h)

    mcux_add_include(INCLUDES ./socs/mcxe247)

endif()

if(CONFIG_MCUX_COMPONENT_driver.qspi_mcxe31b)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES socs/mcxe31b/fsl_qspi_soc.c socs/mcxe31b/fsl_qspi_soc.h)

    mcux_add_include(INCLUDES ./socs/mcxe31b)

endif()

if(CONFIG_MCUX_COMPONENT_driver.qspi_edma)
    mcux_component_version(2.2.4)

    mcux_add_source(SOURCES fsl_qspi_edma.h fsl_qspi_edma.c)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.qspi)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_qspi.h fsl_qspi.c)

    mcux_add_include(INCLUDES .)

endif()
