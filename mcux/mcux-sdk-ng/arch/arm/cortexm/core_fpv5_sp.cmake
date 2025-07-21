# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_config.arm.core.fpu.fpv5_sp)
    mcux_add_iar_configuration(
        AS "--fpu=VFPv5_sp"
        CC "--fpu=VFPv5_sp"
        CX "--fpu=VFPv5_sp"
        LD "--fpu=VFPv5_sp"
    )

    mcux_add_mdk_configuration(
        AS "-mfpu=fpv5-sp-d16"
        CC "-mfpu=fpv5-sp-d16"
        CX "-mfpu=fpv5-sp-d16"
        LD "--fpu=FPv5-SP"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mfloat-abi=hard -mfpu=fpv5-sp-d16"
        CC "-mfloat-abi=hard -mfpu=fpv5-sp-d16"
        CX "-mfloat-abi=hard -mfpu=fpv5-sp-d16"
        LD "-mfpu=fpv5-sp-d16 -mfloat-abi=hard"
    )
endif()
