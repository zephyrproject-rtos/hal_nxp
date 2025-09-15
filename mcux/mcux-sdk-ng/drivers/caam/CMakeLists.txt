# Copyright 2024-2025 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.caam)
    mcux_component_version(2.4.0)

    mcux_add_source(SOURCES fsl_caam.c fsl_caam.h)

    mcux_add_include(INCLUDES .)

    mcux_add_macro("-DCRYPTO_USE_DRIVER_CAAM -DCACHE_MODE_WRITE_THROUGH=1")

endif()
