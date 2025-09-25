# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/MCX/MCXL/MCXL255/drivers/romapi)

if (CONFIG_MCUX_COMPONENT_driver.clock)
    mcux_add_source( SOURCES fsl_clock.c fsl_clock.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.edma_soc)
    mcux_add_source( SOURCES fsl_edma_soc.c fsl_edma_soc.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.inputmux_connections)
    mcux_add_source( SOURCES fsl_inputmux_connections.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.advc)
    mcux_component_version(2.0.1)
    mcux_add_source( SOURCES fsl_advc.c fsl_advc.h )
    mcux_add_include( INCLUDES . )
    mcux_add_library(
        BASE_PATH ${SdkRootDirPath}/${device_root}
        CORES cm33
        LIBS "MCX/MCXL/MCXL255/drivers/advc_cm33.lib"
        TOOLCHAINS iar armgcc
    )
    mcux_add_library(
        BASE_PATH ${SdkRootDirPath}/${device_root}
        CORES cm0p
        LIBS "MCX/MCXL/MCXL255/drivers/advc_cm0p.lib"
        TOOLCHAINS iar armgcc
    )
endif()

if (CONFIG_MCUX_COMPONENT_driver.power)
    mcux_add_source( SOURCES fsl_power.c fsl_power.h )
    mcux_add_include( INCLUDES . )
    mcux_component_version(2.1.0)
endif()

if (CONFIG_MCUX_COMPONENT_driver.reset)
    mcux_add_source( SOURCES fsl_reset.c fsl_reset.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.trdc_soc)
    mcux_add_source( SOURCES fsl_trdc_soc.h )
    mcux_add_include( INCLUDES . )
endif()

