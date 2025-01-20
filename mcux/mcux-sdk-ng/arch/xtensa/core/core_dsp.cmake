# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_PRJSEG_config.xtensa.core.dsp)
    mcux_add_xtensa_configuration(
        AS "--xtensa-core=${XTENSA_CORE} --xtensa-system=${XTENSA_SYSTEM}"
        CC "--xtensa-core=${XTENSA_CORE} --xtensa-system=${XTENSA_SYSTEM}"
        CX "--xtensa-core=${XTENSA_CORE} --xtensa-system=${XTENSA_SYSTEM}"
        LD "--xtensa-core=${XTENSA_CORE} --xtensa-system=${XTENSA_SYSTEM}"
    )

    mcux_add_configuration(
        CC "-DCPU_${CONFIG_MCUX_HW_DEVICE_PART}${core_id_suffix_name}"
        CX "-DCPU_${CONFIG_MCUX_HW_DEVICE_PART}${core_id_suffix_name}"
    )
endif()
