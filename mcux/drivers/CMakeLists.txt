#
# Copyright (c) 2018, NXP
#
# SPDX-License-Identifier: Apache-2.0
#

if("${CONFIG_SOC_SERIES}" STREQUAL "rt6xx")
  add_subdirectory(imxrt6xx)
# using a different directory for i.MX8 to avoid conflict with i.MX RT
elseif("${CONFIG_SOC}" STREQUAL "mimx8mm6")
  add_subdirectory(imx8)
elseif("${CONFIG_SOC_FAMILY}" STREQUAL "nxp_imx")
  add_subdirectory(imx)
elseif("${CONFIG_SOC_FAMILY}" STREQUAL "nxp_kinetis")
  add_subdirectory(kinetis)
elseif("${CONFIG_SOC_FAMILY}" STREQUAL "nxp_lpc")
  add_subdirectory(lpc)
endif()
