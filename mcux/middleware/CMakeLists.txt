if(CONFIG_NET_L2_OPENTHREAD OR CONFIG_NXP_NBU)
    if(CONFIG_SOC_SERIES_MCXW7XX)
        if(CONFIG_IEEE802154)
            zephyr_include_directories(
                ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-ieee_802.15.4/ieee_802_15_4/phy/interface
            )

            zephyr_library_sources(
                ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-ieee_802.15.4/ieee_802_15_4/phy/source/PhyTime.c
                ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-ieee_802.15.4/ieee_802_15_4/phy/source/SerialDevice/Phy.c
            )
            zephyr_compile_definitions(USE_NBU=1)
            zephyr_compile_definitions(MEM_USE_ZEPHYR=1U)
        endif()

        if(CONFIG_NXP_IEEE802154_MAC)
            zephyr_include_directories(
                ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-ieee_802.15.4/ieee_802_15_4/phy/interface
                ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-ieee_802.15.4/ieee_802_15_4/mac/interface
            )

            zephyr_library_sources(
                ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-ieee_802.15.4/ieee_802_15_4/mac/source/App/mac_intf_rpmsg.c
                ${CMAKE_CURRENT_LIST_DIR}/mcux-sdk-middleware-ieee_802.15.4/ieee_802_15_4/phy/source/SerialDevice/Phy.c
            )
            zephyr_compile_definitions(USE_NBU=1)
        endif()
    endif()
endif()

if(CONFIG_ENTROPY_NXP_ELE_TRNG)
    zephyr_include_directories(
        ${CMAKE_CURRENT_LIST_DIR}/mcux-secure-subsystem/inc
        ${CMAKE_CURRENT_LIST_DIR}/mcux-secure-subsystem/inc/elemu
        ${CMAKE_CURRENT_LIST_DIR}/mcux-secure-subsystem/port/kw45_k4w1
    )
    zephyr_compile_definitions(SSS_CONFIG_FILE=\"fsl_sss_config_elemu.h\")
    zephyr_compile_definitions(SSCP_CONFIG_FILE=\"fsl_sscp_config_elemu.h\")

    zephyr_library_sources(
        ${CMAKE_CURRENT_LIST_DIR}/mcux-secure-subsystem/port/kw45_k4w1/sss_init.c
        ${CMAKE_CURRENT_LIST_DIR}/mcux-secure-subsystem/src/sscp/fsl_sss_sscp.c
        ${CMAKE_CURRENT_LIST_DIR}/mcux-secure-subsystem/src/sscp/fsl_sscp_mu.c
    )
endif()
