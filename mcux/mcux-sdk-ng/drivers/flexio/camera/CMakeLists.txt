# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.flexio_camera_edma)
    mcux_component_version(2.1.3)

    mcux_add_source(SOURCES fsl_flexio_camera_edma.c fsl_flexio_camera_edma.h)

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.flexio_camera)
    mcux_component_version(2.1.3)

    mcux_add_source(SOURCES fsl_flexio_camera.c fsl_flexio_camera.h)

    mcux_add_include(INCLUDES .)

endif()
