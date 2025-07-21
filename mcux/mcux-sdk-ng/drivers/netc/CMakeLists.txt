# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.netc_rt1180)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES socs/imxrt1180/fsl_netc_soc.c socs/imxrt1180/fsl_netc_soc.h)

    mcux_add_include(INCLUDES ./socs/imxrt1180)

endif()

if(CONFIG_MCUX_COMPONENT_driver.netc_imx95)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES socs/imx95/fsl_netc_soc.c socs/imx95/fsl_netc_soc.h)

    mcux_add_include(INCLUDES ./socs/imx95)

endif()

if(CONFIG_MCUX_COMPONENT_driver.netc_imx943)
    mcux_component_version(2.0.0)

    mcux_add_source(SOURCES socs/imx943/fsl_netc_soc.c socs/imx943/fsl_netc_soc.h)

    mcux_add_include(INCLUDES ./socs/imx943)

endif()

if(CONFIG_MCUX_COMPONENT_driver.netc)
    mcux_component_version(2.9.0)

    mcux_add_source(
        SOURCES
        fsl_netc.h
        fsl_netc_ierb.h
        fsl_netc_ierb.c
        fsl_netc_timer.h
        fsl_netc_timer.c
        fsl_netc_mdio.h
        fsl_netc_mdio.c
        fsl_netc_endpoint.h
        fsl_netc_endpoint.c
        netc_hw/fsl_netc_hw.h
        netc_hw/fsl_netc_hw.c
        netc_hw/fsl_netc_hw_port.c
        netc_hw/fsl_netc_hw_port.h
        netc_hw/fsl_netc_hw_si.c
        netc_hw/fsl_netc_hw_si.h
        netc_hw/fsl_netc_hw_enetc.c
        netc_hw/fsl_netc_hw_enetc.h
    )

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.netc_switch)
    mcux_component_version(2.8.1)

    mcux_add_source(
        SOURCES
        fsl_netc_switch.h
        fsl_netc_tag.h
        fsl_netc_switch.c
    )

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.netc_phywrapper)
    mcux_component_version(2.8.1)

    mcux_add_source(
        SOURCES
        fsl_netc_phy_wrapper.h
        fsl_netc_phy_wrapper.c
    )

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.netc_msg)
    mcux_component_version(2.8.1)

    mcux_add_source(
        SOURCES
        fsl_netc_msg.h
        fsl_netc_msg.c
    )

    mcux_add_include(INCLUDES .)

endif()
