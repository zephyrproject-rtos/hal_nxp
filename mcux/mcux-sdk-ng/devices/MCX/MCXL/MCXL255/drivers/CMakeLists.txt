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

# if (CONFIG_MCUX_COMPONENT_driver.ipmq)
#     mcux_add_source( SOURCES fsl_ipmq.c fsl_ipmq.h )
#     mcux_add_include( INCLUDES . )
# endif()

if (CONFIG_MCUX_COMPONENT_driver.power)
    mcux_add_source( SOURCES fsl_power.c fsl_power.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.reset)
    mcux_add_source( SOURCES fsl_reset.c fsl_reset.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.trdc_soc)
    mcux_add_source( SOURCES fsl_trdc_soc.h )
    mcux_add_include( INCLUDES . )
endif()

