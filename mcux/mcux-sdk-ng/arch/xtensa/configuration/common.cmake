# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_PRJSEG_config.syslib.xos)
    mcux_add_xtensa_configuration(
        LIB "-lxos"
    )
endif()

if(CONFIG_MCUX_PRJSEG_config.syslib.math)
    mcux_add_xtensa_configuration(
        LIB "-lm"
    )
endif()

if(CONFIG_MCUX_PRJSEG_config.xtensa.shared)
    mcux_add_xtensa_configuration(
        CC "-Wall -fsigned-char -Wno-unused -Wno-missing-braces -fmessage-length=0 -std=gnu99"
        CX "-Wall -fsigned-char -Wno-unused -Wno-missing-braces -fmessage-length=0 -std=c++11"
    )
endif()
