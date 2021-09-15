if(CONFIG_IEEE802154_MCR20A)
  zephyr_include_directories(mcr20a)
endif()

if(CONFIG_ETH_MCUX)
  zephyr_include_directories(phyksz8081)
endif()

if(CONFIG_USE_PMIC_PCA9420)
  zephyr_include_directories(pca9420)
endif()

zephyr_library_sources_ifdef(CONFIG_ETH_MCUX phyksz8081/fsl_phy.c)

zephyr_library_sources_ifdef(CONFIG_SDMMC_USDHC_PMIC_1_8_VOL 
                             pca9420/fsl_pca9420.c)
