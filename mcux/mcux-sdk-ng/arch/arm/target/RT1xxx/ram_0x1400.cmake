# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_PRJSEG_module.board.suite)
    
    mcux_add_iar_linker_script(
        TARGETS ram_0x1400_debug ram_0x1400_release
        BASE_PATH ${SdkRootDirPath}
        LINKER ${project_board_port_path}/linker/${CONFIG_MCUX_TOOLCHAIN_LINKER_DEVICE_PREFIX}_ram_0x1400.icf
    )

    mcux_add_mdk_linker_script(
        TARGETS ram_0x1400_debug ram_0x1400_release
        BASE_PATH ${SdkRootDirPath}
        LINKER ${project_board_port_path}/linker/${CONFIG_MCUX_TOOLCHAIN_LINKER_DEVICE_PREFIX}_ram_0x1400.scf
    )
    
endif()