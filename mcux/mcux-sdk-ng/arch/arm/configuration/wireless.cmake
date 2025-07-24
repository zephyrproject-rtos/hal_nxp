# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_config.wireless.shared)
    mcux_add_iar_configuration(
            AS "-M\"<>\" -w+ -s -j"
            CC "--diag_suppress=Pa082,Pa050 --endian=little -e --use_c++_inline --silent"
            CX "--diag_suppress=Pa082,Pa050 --endian=little -e --c++ --silent"
    )

    mcux_add_mdk_configuration(
            CC "-std=c99 -fshort-enums -fshort-wchar -ffunction-sections -fno-common -fdata-sections -fno-builtin -mthumb -fno-rtti"
            CX "-std=c++11 -fshort-enums -fshort-wchar -fno-common -ffunction-sections -fdata-sections -fno-builtin -mthumb -fno-rtti -fno-exceptions"
            LD "--remove --entry=Reset_Handler --map --xref --callgraph --symbols --info=sizes,totals,unused,veneers --strict --diag_suppress=6314"
    )

    mcux_add_armgcc_configuration(
            AS "-mthumb"
            CC "--specs=nano.specs -Wall -fno-common -ffunction-sections -fdata-sections -fno-builtin -mthumb -mapcs -std=gnu99"
            CX "--specs=nano.specs -Wall -fno-common -ffunction-sections -fdata-sections -fno-builtin -mthumb -mapcs -fno-rtti -fno-exceptions"
            LD "--specs=nosys.specs -Wall -fno-common -ffunction-sections -fdata-sections -fno-builtin -mthumb -mapcs -Wl,--gc-sections -Wl,-static -Wl,--print-memory-usage"
            LIB "-lm -lc -lgcc -lnosys"
    )

    mcux_add_mcux_configuration(
            CC "-c -fno-common -ffunction-sections -fdata-sections -fno-builtin -std=gnu99"
            CX "-c -fno-common -ffunction-sections -fdata-sections -fno-builtin -fno-rtti -std=gnu++11 -fno-exceptions"
            LD "--specs=nano.specs -fno-common -ffunction-sections -fdata-sections -fno-builtin -nostdlib -Xlinker -no-warn-rwx-segments"
    )

    include(${SdkRootDirPath}/arch/arm/configuration/common.cmake)
endif()