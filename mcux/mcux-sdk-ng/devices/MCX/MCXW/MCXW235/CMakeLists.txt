# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
include(${SdkRootDirPath}/devices/arm/device_header_cstartup.cmake)
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/MCX/MCXW/MCXW236/drivers)

#### MCX shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/MCX/shared.cmake)

if(CONFIG_MCUX_COMPONENT_driver.trng)
    #### MCX shared defines
    mcux_add_configuration(
        CC "-DTRNG0=TRNG -DTRNG0_IRQn=TRNG_IRQn"
    )
endif()

mcux_add_linker_symbol(
    SYMBOLS
        "MCXW235=1"
)
