# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

mcux_add_riscvllvm_configuration(
    TARGETS debug
    CC "-g -O0"
    CX "-g -O0"
    LD "-g"
)

mcux_add_riscvllvm_configuration(
    TARGETS release
    CC "-Os"
    CX "-Os"
)

if (CONFIG_MCUX_PRJSEG_module.board.suite)
    mcux_add_riscvllvm_linker_script(
        TARGETS debug release
        BASE_PATH ${SdkRootDirPath}
        LINKER devices/${soc_portfolio}/${soc_series}/${device}/llvm/${device}xxxx_ezhv_ram.ld
    )
endif()
