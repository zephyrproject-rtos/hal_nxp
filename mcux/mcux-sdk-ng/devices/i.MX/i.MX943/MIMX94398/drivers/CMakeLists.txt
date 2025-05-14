# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

#### device core spepcific drivers
mcux_add_cmakelists(${SdkRootDirPath}/devices/i.MX/i.MX943/${device}/drivers/${core_id})

if (CONFIG_MCUX_COMPONENT_driver.elec_spec)
    mcux_component_version(1.0.0)
    mcux_add_source( SOURCES fsl_elec_spec.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.reset)
    mcux_component_version(1.0.0)
    mcux_add_source( SOURCES fsl_reset.c fsl_reset.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.trdc_soc)
    mcux_component_version(1.0.0)
    mcux_add_source( SOURCES fsl_trdc_soc.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.clock)
    mcux_component_version(1.0.0)
    mcux_add_source( SOURCES fsl_clock.c fsl_clock.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.edma_soc)
    mcux_component_version(1.0.0)
    mcux_add_source( SOURCES fsl_edma_soc.c fsl_edma_soc.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.iomuxc)
    mcux_component_version(1.0.0)
    mcux_add_source( SOURCES fsl_iomuxc.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.supply)
    mcux_component_version(1.0.0)
    mcux_add_source( SOURCES fsl_supply.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.cpu)
    mcux_component_version(1.0.0)
    mcux_add_source( SOURCES fsl_cpu.c fsl_cpu.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.memory)
    mcux_component_version(1.0.0)
    mcux_add_source( SOURCES fsl_memory.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.power)
    mcux_component_version(1.0.0)
    mcux_add_source( SOURCES fsl_power.h fsl_power.c )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.ccm)
    mcux_component_version(1.0.0)
    mcux_add_source( SOURCES fsl_ccm.c fsl_ccm.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.src1)
    mcux_component_version(1.0.0)
    mcux_add_source( SOURCES fsl_src.c fsl_src.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.fro)
    mcux_component_version(1.0.0)
    mcux_add_source( SOURCES fsl_fro.c fsl_fro.h )
    mcux_add_include( INCLUDES . )
endif()
