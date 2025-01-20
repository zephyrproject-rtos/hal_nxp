# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.iap1)
    mcux_component_version(2.1.5)

    mcux_add_source(
        SOURCES
        fsl_iap.h
        fsl_iap.c
        fsl_iap_ffr.h
        fsl_iap_kbp.h
        fsl_iap_skboot_authenticate.h
    )

    mcux_add_include(INCLUDES .)

endif()
