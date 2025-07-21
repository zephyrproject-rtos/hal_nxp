# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.osa_template_config)

	mcux_add_source(
		SOURCES config/fsl_os_abstraction_config.h
        CONFIG TRUE
	)
	
    mcux_add_include(
        INCLUDES config
        TARGET_FILES fsl_os_abstraction_config.h
    )
endif()

if (CONFIG_MCUX_PRJSEG_component.osa_interface.osa_macro_used)

    mcux_add_configuration(
        AS "-DOSA_USED"
        CC "-DOSA_USED"
        CX "-DOSA_USED"
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.osa_bm)

    mcux_add_source(
        SOURCES fsl_os_abstraction_bm.h
                fsl_os_abstraction_bm.c
                fsl_os_abstraction.h
    )

    mcux_add_include(
        INCLUDES .
    )
	
    mcux_add_configuration(
        AS "-DUSE_RTOS=0"
        CC "-DUSE_RTOS=0"
        CX "-DUSE_RTOS=0"
    )


endif()
if (CONFIG_MCUX_COMPONENT_component.osa_free_rtos)

    mcux_add_source(
        SOURCES fsl_os_abstraction_free_rtos.h
                fsl_os_abstraction_free_rtos.c
                fsl_os_abstraction.h
    )

    mcux_add_include(
        INCLUDES .
    )
	
    mcux_add_configuration(
        AS "-DUSE_RTOS=1"
        CC "-DUSE_RTOS=1"
        CX "-DUSE_RTOS=1"
    )

endif()

if (CONFIG_MCUX_COMPONENT_component.osa_zephyr)

    mcux_add_source(
        SOURCES fsl_os_abstraction_zephyr.h
                fsl_os_abstraction_zephyr.c
                fsl_os_abstraction.h
    )

    mcux_add_include(
        INCLUDES .
    )
	
    mcux_add_configuration(
        AS "-DUSE_RTOS=1"
        CC "-DUSE_RTOS=1"
        CX "-DUSE_RTOS=1"
    )

endif()

if (CONFIG_MCUX_COMPONENT_component.osa_threadx)

    mcux_add_source(
        SOURCES fsl_os_abstraction_threadx.h
                fsl_os_abstraction_threadx.c
                fsl_os_abstraction.h
    )

    mcux_add_include(
        INCLUDES .
    )
	
    mcux_add_configuration(
        AS "-DUSE_RTOS=1"
        CC "-DUSE_RTOS=1"
        CX "-DUSE_RTOS=1"
    )

endif()

if (CONFIG_MCUX_PRJSEG_component.osa_interface.generated_config)
endif ()