# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_config.device_core.define)
    mcux_add_configuration(
        AS "-DCPU_${CONFIG_MCUX_HW_DEVICE_PART}${core_id_suffix_name} -D${device}${core_id_suffix_name}_SERIES"
        CC "-DCPU_${CONFIG_MCUX_HW_DEVICE_PART}${core_id_suffix_name} -D${device}${core_id_suffix_name}_SERIES"
        CX "-DCPU_${CONFIG_MCUX_HW_DEVICE_PART}${core_id_suffix_name} -D${device}${core_id_suffix_name}_SERIES"
    )
endif()
