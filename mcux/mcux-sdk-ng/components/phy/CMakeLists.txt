# Copyright 2024-2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_MCUX_COMPONENT_component.eth_phy_common)
    mcux_add_include(
        INCLUDES
            .
    )

    mcux_add_source(
        SOURCES
            fsl_phy.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.phyrtl8211f)
    mcux_add_include(
        INCLUDES
            ./device/phyrtl8211f
    )

    mcux_add_source(
        SOURCES
            ./device/phyrtl8211f/fsl_phyrtl8211f.c
            ./device/phyrtl8211f/fsl_phyrtl8211f.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.phyaqr113c)
    mcux_add_include(
        INCLUDES
            ./device/phyaqr113c
    )

    mcux_add_source(
        SOURCES
            ./device/phyaqr113c/fsl_phyaqr113c.c
            ./device/phyaqr113c/fsl_phyaqr113c.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.phyksz8081)
    mcux_add_include(
        INCLUDES
            ./device/phyksz8081
    )

    mcux_add_source(
        SOURCES
            ./device/phyksz8081/fsl_phyksz8081.c
            ./device/phyksz8081/fsl_phyksz8081.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.phydp8384x)
    mcux_add_include(
        INCLUDES
            ./device/phydp8384x
    )

    mcux_add_source(
        SOURCES
            ./device/phydp8384x/fsl_phydp8384x.c
            ./device/phydp8384x/fsl_phydp8384x.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.phygpy215)
    mcux_add_include(
        INCLUDES
            ./device/phygpy215
    )

    mcux_add_source(
        SOURCES
            ./device/phygpy215/fsl_phygpy215.c
            ./device/phygpy215/fsl_phygpy215.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.phyksz8041)
    mcux_add_include(
        INCLUDES
            ./device/phyksz8041
    )

    mcux_add_source(
        SOURCES
            ./device/phyksz8041/fsl_phyksz8041.c
            ./device/phyksz8041/fsl_phyksz8041.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.phyar8031)
    mcux_add_include(
        INCLUDES
            ./device/phyar8031
    )

    mcux_add_source(
        SOURCES
            ./device/phyar8031/fsl_phyar8031.c
            ./device/phyar8031/fsl_phyar8031.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.phylan8720a)
    mcux_add_include(
        INCLUDES
            ./device/phylan8720a
    )

    mcux_add_source(
        SOURCES
            ./device/phylan8720a/fsl_phylan8720a.c
            ./device/phylan8720a/fsl_phylan8720a.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.phyvsc8541)
    mcux_add_include(
        INCLUDES
            ./device/phyvsc8541
    )

    mcux_add_source(
        SOURCES
            ./device/phyvsc8541/fsl_phyvsc8541.c
            ./device/phyvsc8541/fsl_phyvsc8541.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.phyrtl8201)
    mcux_add_include(
        INCLUDES
            ./device/phyrtl8201
    )

    mcux_add_source(
        SOURCES
            ./device/phyrtl8201/fsl_phyrtl8201.c
            ./device/phyrtl8201/fsl_phyrtl8201.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.phylan8741)
    mcux_add_include(
        INCLUDES
            ./device/phylan8741
    )

    mcux_add_source(
        SOURCES
            ./device/phylan8741/fsl_phylan8741.c
            ./device/phylan8741/fsl_phylan8741.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.phytja1100)
    mcux_add_include(
        INCLUDES
            ./device/phytja1100
    )

    mcux_add_source(
        SOURCES
            ./device/phytja1100/fsl_phytja1100.c
            ./device/phytja1100/fsl_phytja1100.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.phytja1120)
    mcux_add_include(
        INCLUDES
            ./device/phytja1120
    )

    mcux_add_source(
        SOURCES
            ./device/phytja1120/fsl_phytja1120.c
            ./device/phytja1120/fsl_phytja1120.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_component.phyyt8521)
    mcux_add_include(
        INCLUDES
            ./device/phyyt8521
    )

    mcux_add_source(
        SOURCES
            ./device/phyyt8521/fsl_phyyt8521.c
            ./device/phyyt8521/fsl_phyyt8521.h
    )
endif()
