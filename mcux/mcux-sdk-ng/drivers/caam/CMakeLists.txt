# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.caam)
    mcux_component_version(2.3.2)

    mcux_add_source(SOURCES fsl_caam.c fsl_caam.h)

    mcux_add_include(INCLUDES .)

    mcux_add_configuration(CC "-DCRYPTO_USE_DRIVER_CAAM -DCACHE_MODE_WRITE_THROUGH=1")

endif()
