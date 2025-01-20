# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_PRJSEG_config.riscv.core.ezhv)
    mcux_add_riscvllvm_configuration(
        AS "-mcpu=zv2116 -mabi=ilp32"
        CC "-mcpu=zv2116 -mabi=ilp32 -falign-functions=4"
        CX "-mcpu=zv2116 -mabi=ilp32 -falign-functions=4"
        LD "-mcpu=zv2116 -mabi=ilp32 -falign-functions=4"
    )

    mcux_add_configuration(
        CC "-DCPU_${CONFIG_MCUX_HW_DEVICE_PART}${core_id_suffix_name}"
    )
endif()
