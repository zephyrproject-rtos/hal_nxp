# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_config.arm.core.fpu.fpv5_dp)
    mcux_add_iar_configuration(
        AS "--fpu=VFPv5_d16"
        CC "--fpu=VFPv5_d16"
        CX "--fpu=VFPv5_d16"
        LD "--fpu=VFPv5_d16"
    )

    mcux_add_mdk_configuration(
        AS "-mfpu=fpv5-d16"
        CC "-mfpu=fpv5-d16"
        CX "-mfpu=fpv5-d16"
        LD "--fpu=FPv5_D16"
    )

    mcux_add_armgcc_mcux_configuration(
        AS "-mfloat-abi=hard -mfpu=fpv5-d16 -mthumb"
        CC "-mfloat-abi=hard -mfpu=fpv5-d16 -mthumb"
        CX "-mfloat-abi=hard -mfpu=fpv5-d16 -mthumb"
        LD "-mfpu=fpv5-d16 -mfloat-abi=hard"
    )
endif()
