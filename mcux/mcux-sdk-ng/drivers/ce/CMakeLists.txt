# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.ce)
    mcux_component_version(2.1.1)

    mcux_add_source(
        SOURCES
        fsl_ce.h
        fsl_ce.c
        fsl_ce_basic.c
        fsl_ce_basic.h
        fsl_ce_cmd.c
        fsl_ce_cmd.h
        fsl_ce_cmsis.c
        fsl_ce_cmsis.h
        fsl_ce_if.h
        fsl_ce_matrix.c
        fsl_ce_matrix.h
        fsl_ce_transform.c
        fsl_ce_transform.h
        firmware/ce_kw47_mcxw72.txt
    )

    mcux_add_include(INCLUDES . firmware)

endif()
