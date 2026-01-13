#
# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#

# Include other Multicore Components
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/mcmgr OPTIONAL)
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/rpmsg-lite OPTIONAL)
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/erpc/mcux OPTIONAL)
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/remoteproc OPTIONAL)
