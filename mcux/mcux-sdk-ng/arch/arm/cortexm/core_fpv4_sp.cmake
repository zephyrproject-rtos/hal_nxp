# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_config.arm.core.fpu.fpv4_sp)
    mcux_add_iar_configuration(
        AS "--fpu=VFPv4_sp"
        CC "--fpu=VFPv4_sp"
        CX "--fpu=VFPv4_sp"
        LD "--fpu=VFPv4_sp"
    )

    mcux_add_mdk_configuration(
        AS "-mfpu=fpv4-sp-d16"
        CC "-mfpu=fpv4-sp-d16"
        CX "-mfpu=fpv4-sp-d16"
        LD "--fpu=FPv4-SP"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mfloat-abi=hard -mfpu=fpv4-sp-d16"
        CC "-mfloat-abi=hard -mfpu=fpv4-sp-d16"
        CX "-mfloat-abi=hard -mfpu=fpv4-sp-d16"
        LD "-mfpu=fpv4-sp-d16 -mfloat-abi=hard"
    )
endif()
