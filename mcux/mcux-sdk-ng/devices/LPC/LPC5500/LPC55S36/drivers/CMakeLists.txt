# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_driver.clock)
    mcux_component_version(2.3.3)
    mcux_add_source( SOURCES fsl_clock.c fsl_clock.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.fro_calib)
    mcux_component_version(2.0.0)
    mcux_add_source( SOURCES fsl_fro_calib.h )
    mcux_add_library(
        LIBS ../iar/iar_lib_fro_calib.a
        TOOLCHAINS iar)
    mcux_add_library(
        LIBS ../arm/keil_lib_fro_calib.lib
        TOOLCHAINS mdk)
    mcux_add_library(
        LIBS ../gcc/libfro_calib_hardabi.a
        TOOLCHAINS armgcc)
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.inputmux_connections)
    mcux_component_version(2.0.0)
    mcux_add_source( SOURCES fsl_inputmux_connections.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.power)
    mcux_component_version(2.0.1)
    mcux_add_source( SOURCES fsl_power.c fsl_power.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.reset)
    mcux_component_version(2.4.0)
    mcux_add_source( SOURCES fsl_reset.c fsl_reset.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.romapi_flash)
    mcux_component_version(2.0.0)
    mcux_add_source(
        SOURCES 
            ./romapi/flash/src/fsl_flash.c
            ./romapi/flash/fsl_efuse.h
            ./romapi/flash/fsl_flash_ffr.h
            ./romapi/flash/fsl_flash.h
            ./romapi/flash/fsl_flexspi_nor_flash.h)
    mcux_add_include( INCLUDES ./romapi/flash )
endif()

if (CONFIG_MCUX_COMPONENT_driver.romapi_mem_interface)
    mcux_component_version(2.0.0)
    mcux_add_source(
        SOURCES 
            ./romapi/mem_interface/src/fsl_mem_interface.c
            ./romapi/mem_interface/fsl_mem_interface.h
            ./romapi/mem_interface/fsl_sbloader_v3.h
            ./romapi/mem_interface/fsl_sbloader.h)
    mcux_add_include( INCLUDES ./romapi/mem_interface )
endif()

if (CONFIG_MCUX_COMPONENT_driver.romapi_nboot)
    mcux_component_version(2.0.0)
    mcux_add_source(
        SOURCES 
            ./romapi/nboot/src/fsl_nboot.c
            ./romapi/nboot/fsl_nboot_hal.h
            ./romapi/nboot/fsl_nboot.h)
    mcux_add_include( INCLUDES ./romapi/nboot )
endif()

if (CONFIG_MCUX_COMPONENT_driver.romapi_runbootloader)
    mcux_component_version(2.0.0)
    mcux_add_source(
        SOURCES 
            ./romapi/runbootloader/src/fsl_runbootloader.c
            ./romapi/runbootloader/fsl_runbootloader.h)
    mcux_add_include( INCLUDES ./romapi/runbootloader )
endif()

if (CONFIG_MCUX_COMPONENT_driver.romapi)
    mcux_component_version(2.0.0)
    mcux_add_source(
        SOURCES
            ./romapi/flash/fsl_efuse.h
            ./romapi/flash/fsl_flash.h
            ./romapi/flash/fsl_flash_ffr.h
            ./romapi/flash/fsl_flexspi_nor_flash.h
            ./romapi/flash/src/fsl_flash.c
            ./romapi/mem_interface/fsl_mem_interface.h
            ./romapi/mem_interface/fsl_sbloader.h
            ./romapi/mem_interface/fsl_sbloader_v3.h
            ./romapi/mem_interface/src/fsl_mem_interface.c
            ./romapi/nboot/fsl_nboot.h
            ./romapi/nboot/fsl_nboot_hal.h
            ./romapi/nboot/src/fsl_nboot.c
            ./romapi/runbootloader/fsl_runbootloader.h
            ./romapi/runbootloader/src/fsl_runbootloader.c
    )

    mcux_add_include(
        INCLUDES ./romapi/mem_interface
                 ./romapi/flash
                 ./romapi/nboot
                 ./romapi/runbootloader
    )
endif()
