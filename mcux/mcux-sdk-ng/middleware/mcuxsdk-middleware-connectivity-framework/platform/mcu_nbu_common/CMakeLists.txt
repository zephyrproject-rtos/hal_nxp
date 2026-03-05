# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.framework.platform)

    mcux_add_source(SOURCES
        fwk_platform_mcu_nbu_common.c
        fwk_platform_mcu_nbu_common.h
        DEVICE_IDS ${KW45_FAMILY} ${KW47_FAMILY} ${MCXW71_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY} "KW43B43ZC7xxxA_NBU" "KW45B41Z83xxxA_NBU" 
    )
    mcux_add_include(INCLUDES
            .
    )
endif()


