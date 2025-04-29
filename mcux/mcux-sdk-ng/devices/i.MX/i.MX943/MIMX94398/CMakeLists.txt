# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

#### device spepcific drivers
mcux_add_cmakelists(${SdkRootDirPath}/devices/i.MX/i.MX943/${device}/drivers)
mcux_add_cmakelists(${SdkRootDirPath}/devices/i.MX/i.MX943/${device}/${core_id})

#### i.MX shared drivers/components/middlewares, project segments
include(${SdkRootDirPath}/devices/i.MX/shared.cmake)
