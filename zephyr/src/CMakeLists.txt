add_subdirectory_ifdef(CONFIG_SOC_SERIES_RW6XX rw61x)

if (CONFIG_NXP_MONOLITHIC_WIFI OR CONFIG_BT_H4_NXP_CTLR)
  add_subdirectory(wireless)
endif()
