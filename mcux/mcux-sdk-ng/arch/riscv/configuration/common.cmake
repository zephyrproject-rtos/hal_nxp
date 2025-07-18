# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

mcux_add_cmakelists(${SdkRootDirPath}/arch/riscv/headers)

if(CONFIG_MCUX_PRJSEG_config.ezhv.shared)
    mcux_add_riscvllvm_configuration(
        CC "-Wall -MP -fno-common -ffunction-sections -fdata-sections -fno-builtin -std=gnu99"
        CX "-Wall -MP -fno-common -ffunction-sections -fdata-sections -fno-builtin -fno-rtti -fno-exceptions"
        LD "-Wall -fno-common -ffunction-sections -fdata-sections -fno-builtin -Xlinker --gc-sections -Xlinker -static -Xlinker -Map=output.map -Wl,--print-memory-usage"
        LIB "-lm -lc -lnosys"
    )
endif()
