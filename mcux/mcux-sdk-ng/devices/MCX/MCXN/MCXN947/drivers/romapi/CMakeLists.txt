if (CONFIG_MCUX_COMPONENT_driver.romapi)
    mcux_component_version(2.0.0)
    mcux_add_source(
        SOURCES
            ./flash/fsl_efuse.h
            ./flash/fsl_flash.h
            ./flash/fsl_flash_ffr.h
            ./flash/fsl_flexspi_nor_flash.h
            ./flash/src/fsl_flash.c
            ./mem_interface/fsl_mem_interface.h
            ./mem_interface/fsl_sbloader.h
            ./mem_interface/fsl_sbloader_v3.h
            ./mem_interface/src/fsl_mem_interface.c
            ./nboot/fsl_nboot.h
            ./nboot/fsl_nboot_hal.h
            ./nboot/src/fsl_nboot.c
            ./runbootloader/fsl_runbootloader.h
            ./runbootloader/src/fsl_runbootloader.c
    )

    mcux_add_include(
        INCLUDES ./mem_interface
                 ./flash
                 ./nboot
                 ./runbootloader
    )

endif()

if (CONFIG_MCUX_COMPONENT_driver.mem_interface)
    mcux_component_version(2.0.0)
    mcux_add_source(
        SOURCES
            ./mem_interface/src/fsl_mem_interface.c
            ./mem_interface/fsl_mem_interface.h
            ./mem_interface/fsl_sbloader.h
            ./mem_interface/fsl_sbloader_v3.h
            ./flash/fsl_flash.h
            ./flash/fsl_flash_ffr.h
            ./flash/fsl_flexspi_nor_flash.h
            ./nboot/fsl_nboot.h
            ./nboot/fsl_nboot_hal.h
    )

    mcux_add_include(
        INCLUDES ./mem_interface
                 ./flash
                 ./nboot
    )

endif()

if (CONFIG_MCUX_COMPONENT_driver.romapi_nboot)
    mcux_component_version(2.0.0)
    mcux_add_source(
        SOURCES 
            ./nboot/src/fsl_nboot.c
            ./nboot/fsl_nboot_hal.h
            ./nboot/fsl_nboot.h)
    mcux_add_include( INCLUDES ./nboot )
endif()

if (CONFIG_MCUX_COMPONENT_driver.runbootloader)
    mcux_component_version(2.0.0)
    mcux_add_source(
        SOURCES
            ./mem_interface/fsl_mem_interface.h
            ./mem_interface/fsl_sbloader.h
            ./mem_interface/fsl_sbloader_v3.h
            ./flash/fsl_flash.h
            ./flash/fsl_flash_ffr.h
            ./flash/fsl_flexspi_nor_flash.h
            ./nboot/src/fsl_nboot.c
            ./nboot/fsl_nboot.h
            ./nboot/fsl_nboot_hal.h
            ./runbootloader/fsl_runbootloader.h
            ./runbootloader/src/fsl_runbootloader.c
    )

    mcux_add_include(
        INCLUDES ./mem_interface
                 ./flash
                 ./nboot
                 ./runbootloader
    )

endif()

if (CONFIG_MCUX_COMPONENT_driver.romapi_flashiap)
    mcux_component_version(2.0.0)
    mcux_add_source(
        SOURCES
            ./flash/src/fsl_flash.c
            ./flash/fsl_flash.h
            ./flash/fsl_efuse.h
            ./flash/fsl_flash_ffr.h
            ./flash/fsl_flexspi_nor_flash.h
    )

    mcux_add_include(
        INCLUDES ./flash
    )

endif()
