# Copyright 2024, 2026 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

#### device specific drivers
mcux_add_cmakelists(${SdkRootDirPath}/${device_root}/i.MX/i.MX8MM/MIMX8MM6/drivers)
mcux_add_cmakelists(${SdkRootDirPath}/devices/i.MX/i.MX8MM/${device}/${core_id})

#### i.MX shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/i.MX/shared.cmake)
