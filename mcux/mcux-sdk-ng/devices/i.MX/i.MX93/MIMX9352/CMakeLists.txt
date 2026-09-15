# Copyright 2024, 2026 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/i.MX/i.MX93/MIMX9352/drivers)

#### core specific device header/startup
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/i.MX/i.MX93/MIMX9352/${core_id})


#### i.MX shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/i.MX/shared.cmake)
