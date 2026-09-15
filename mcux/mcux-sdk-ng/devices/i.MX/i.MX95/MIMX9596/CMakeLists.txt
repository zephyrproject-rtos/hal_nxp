# Copyright 2024, 2026 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### device specific drivers
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/i.MX/i.MX95/MIMX9596/drivers)
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/i.MX/i.MX95/MIMX9596/${core_id})

#### i.MX shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/i.MX/shared.cmake)
