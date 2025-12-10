zephyr_include_directories(include)

zephyr_library_sources_ifdef(CONFIG_CLOCK_CONTROL_NXP_S32
  src/Clock_Ip_Cfg.c
)
