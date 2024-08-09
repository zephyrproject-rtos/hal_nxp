zephyr_include_directories(include)

zephyr_library_sources(
  src/Clock_Ip_Cfg.c
)

zephyr_library_sources_ifdef(CONFIG_MBOX_NXP_S32_MRU src/Mru_Ip_Cfg.c)
zephyr_library_sources_ifdef(CONFIG_ETH_NXP_S32_NETC src/Netc_Eth_Ip_Cfg.c)
