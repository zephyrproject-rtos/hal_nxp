# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

mcux_add_cmakelists(${SdkRootDirPath}/arch/arm/CMSIS OPTIONAL)

if (CONFIG_MCUX_PRJSEG_config.arm.shared)
        # Create map file
        mcux_add_armgcc_configuration(
                LD "-Xlinker -Map=output.map"
        )

        mcux_add_iar_configuration(
                LD "--map output.map"
        )

        mcux_add_mdk_configuration(
                LD "--list output.map"
        )
endif()
