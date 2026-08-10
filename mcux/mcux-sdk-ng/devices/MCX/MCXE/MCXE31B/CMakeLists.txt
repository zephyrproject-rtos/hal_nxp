# Copyright 2024, 2026 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
include(${SdkRootDirPath}/devices/arm/device_header_cstartup.cmake)
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/MCX/MCXE/MCXE31B/drivers)

#### Boot header (IVT)
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/MCX/MCXE/MCXE31B/xip)

#### MCX shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/MCX/shared.cmake)
