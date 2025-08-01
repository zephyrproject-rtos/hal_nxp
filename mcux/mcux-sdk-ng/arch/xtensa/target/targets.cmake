# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

mcux_add_xtensa_configuration(
    TARGETS debug
    AS "-g"
    CC "-O0 -g"
    CX "-O0 -g"
)

mcux_add_xtensa_configuration(
    TARGETS release
    CC "-Os"
    CX "-Os"
)
