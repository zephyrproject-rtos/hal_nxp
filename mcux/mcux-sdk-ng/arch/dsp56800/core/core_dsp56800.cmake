# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_PRJSEG_config.codewarrior.core.dsp56800)
    mcux_add_codewarrior_configuration(
        CC "-DCPU_${CONFIG_MCUX_HW_DEVICE_PART}"
        CX "-DCPU_${CONFIG_MCUX_HW_DEVICE_PART}"
    )
endif()
