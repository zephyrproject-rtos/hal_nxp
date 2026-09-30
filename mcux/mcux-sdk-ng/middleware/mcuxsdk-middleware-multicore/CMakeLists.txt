#
# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#

# Include other Multicore Components
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/mcmgr OPTIONAL)
# rpmsg-lite sources are provided by the standalone Zephyr module.
# ZEPHYR_RPMSG_LITE_MODULE_DIR is set automatically by west when the
# rpmsg-lite project is present in west.yml (path: modules/lib/rpmsg-lite).
if(DEFINED ZEPHYR_RPMSG_LITE_MODULE_DIR)
    mcux_add_cmakelists(${ZEPHYR_RPMSG_LITE_MODULE_DIR} OPTIONAL)
else()
    message(STATUS "rpmsg-lite: ZEPHYR_RPMSG_LITE_MODULE_DIR not defined; "
            "rpmsg-lite component skipped. Add rpmsg-lite to west.yml.")
endif()
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/erpc/mcux OPTIONAL)
mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/remoteproc OPTIONAL)
