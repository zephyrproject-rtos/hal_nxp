# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_config.arm.core.fpu.no_fpu)
    mcux_add_iar_configuration(
        AS "--fpu=none"
        CC "--fpu=none"
        CX "--fpu=none"
        LD "--fpu=none"
    )

    mcux_add_mdk_configuration(
        AS "-mfpu=none"
        CC "-mfpu=none"
        CX "-mfpu=none"
        LD "--fpu=SoftVFP"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mfloat-abi=soft"
        CC "-mfloat-abi=soft"
        CX "-mfloat-abi=soft"
        LD "-mfloat-abi=soft"
    )
endif()