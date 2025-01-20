# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.cic_irb)
    mcux_component_version(1.0.0)

    mcux_add_source(
        SOURCES
        fsl_cic_irb.h
        fsl_cic_irb_private.h
        fsl_cic_irb.c
        fsl_cic_irb_rc5.c
        fsl_cic_irb_rc6.c
        fsl_cic_irb_sirc.c
        fsl_cic_irb_rcmm.c
    )

    mcux_add_include(INCLUDES .)

endif()
