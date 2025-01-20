# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_config.device_core.define)
    mcux_add_configuration(
        AS "-DCPU_${CONFIG_MCUX_HW_DEVICE_PART}${core_id_suffix_name}"
        CC "-DCPU_${CONFIG_MCUX_HW_DEVICE_PART}${core_id_suffix_name}"
        CX "-DCPU_${CONFIG_MCUX_HW_DEVICE_PART}${core_id_suffix_name}"
    )
endif()