# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_driver.smartcard_emvsim)
    mcux_component_version(2.3.0)

    mcux_add_source(
        SOURCES
        fsl_smartcard.h
        fsl_smartcard_emvsim.h
        fsl_smartcard_emvsim.c
    )

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.smartcard_phy_emvsim)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_smartcard_phy.h fsl_smartcard_phy_emvsim.c)

    mcux_add_include(INCLUDES .)

    mcux_add_configuration(CC -DUSING_PHY_EMVSIM)

endif()

if(CONFIG_MCUX_COMPONENT_driver.smartcard_phy_gpio)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_smartcard_phy.h fsl_smartcard_phy_gpio.c)

    mcux_add_include(INCLUDES .)

    mcux_add_configuration(CC -DUSING_PHY_GPIO)

endif()

if(CONFIG_MCUX_COMPONENT_driver.smartcard_phy_tda8035)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_smartcard_phy.h fsl_smartcard_phy_tda8035.c)

    mcux_add_include(INCLUDES .)

    mcux_add_configuration(CC -DUSING_PHY_TDA8035)

endif()

if(CONFIG_MCUX_COMPONENT_driver.smartcard_phy_usim)
    mcux_component_version(2.3.0)

    mcux_add_source(SOURCES fsl_smartcard_phy.h fsl_smartcard_phy_usim.c)

    mcux_add_include(INCLUDES .)

    mcux_add_configuration(CC -DUSING_PHY_EMVSIM)

endif()

if(CONFIG_MCUX_COMPONENT_driver.smartcard_uart)
    mcux_component_version(2.3.0)

    mcux_add_source(
        SOURCES
        fsl_smartcard.h
        fsl_smartcard_uart.h
        fsl_smartcard_uart.c
    )

    mcux_add_include(INCLUDES .)

endif()

if(CONFIG_MCUX_COMPONENT_driver.smartcard_usim)
    mcux_component_version(2.3.0)

    mcux_add_source(
        SOURCES
        fsl_smartcard.h
        fsl_smartcard_usim.h
        fsl_smartcard_usim.c
    )

    mcux_add_include(INCLUDES .)

endif()
