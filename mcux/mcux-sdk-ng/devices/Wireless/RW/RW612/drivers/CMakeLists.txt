# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_driver.clock)
    mcux_component_version(2.3.2)
    mcux_add_source( SOURCES fsl_clock.c fsl_clock.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.i2s_bridge)
    mcux_component_version(2.0.0)
    mcux_add_source( SOURCES fsl_i2s_bridge.c fsl_i2s_bridge.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.inputmux_connections)
    mcux_component_version(2.0.1)
    mcux_add_source( SOURCES fsl_inputmux_connections.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.io_mux)
    mcux_component_version(2.2.2)
    mcux_add_source( SOURCES fsl_io_mux.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.iped_rw61x)
    mcux_component_version(1.0.1)
    mcux_add_source( SOURCES fsl_iped.c fsl_iped.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.memory)
    mcux_component_version(2.0.0)
    mcux_add_source( SOURCES fsl_memory.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.ocotp_rw61x)
    mcux_component_version(2.2.3)
    mcux_add_source( SOURCES fsl_ocotp.c fsl_ocotp.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.power)
    mcux_component_version(2.5.3)
    mcux_add_source( SOURCES fsl_power.c fsl_power.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.reset)
    mcux_component_version(2.1.1)
    mcux_add_source( SOURCES fsl_reset.c fsl_reset.h )
    mcux_add_include( INCLUDES . )
endif()

if (CONFIG_MCUX_COMPONENT_driver.romapi)
    mcux_component_version(3.0.0)
    mcux_add_source( SOURCES ./romapi/bootloader/fsl_romapi.c
                             ./romapi/bootloader/fsl_romapi.h 
                             ./romapi/flexspi/fsl_romapi_flexspi.c
                             ./romapi/flexspi/fsl_romapi_flexspi.h
                             ./romapi/iap/fsl_kb_api.h
                             ./romapi/iap/fsl_romapi_iap.c
                             ./romapi/iap/fsl_romapi_iap.h
                             ./romapi/iap/fsl_sbloader_v3.h
                             ./romapi/nboot/fsl_romapi_nboot.c
                             ./romapi/nboot/fsl_romapi_nboot.h
                             ./romapi/otp/fsl_romapi_otp.c
                             ./romapi/otp/fsl_romapi_otp.h)
    mcux_add_include( INCLUDES ./romapi/bootloader
                               ./romapi/flexspi
                               ./romapi/iap
                               ./romapi/nboot
                               ./romapi/otp)
endif()
