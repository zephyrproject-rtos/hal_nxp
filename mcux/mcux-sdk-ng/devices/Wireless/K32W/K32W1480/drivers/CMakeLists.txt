# Copyright 2024-2025 NXP
#  
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_driver.clock)
    mcux_component_version(2.2.2)

    mcux_add_source( SOURCES fsl_clock.c fsl_clock.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.romapi_soc)
    mcux_component_version(1.2.0)

    mcux_add_source(
        SOURCES
            romapi/fsl_flash_api.h
            romapi/fsl_kb_api.h
            romapi/fsl_lpspi_flash.h
            romapi/fsl_nboot.h
            romapi/fsl_romapi.c
    )

    mcux_add_include(
        INCLUDES ./romapi
    )
endif()
