# Copyright 2024 NXP
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause


if (CONFIG_MCUX_COMPONENT_driver.upowerlib)
    mcux_component_version(2.0.0)
    mcux_add_source( SOURCES upower_soc_defs.h pmic_model.h upmu.h upower_api.c upower_api.h 
                              upower_defs.h upwr_pmic_defs.h  )
    mcux_add_include( INCLUDES . )
endif()
