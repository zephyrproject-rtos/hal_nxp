if(CONFIG_MCUX OR CONFIG_HAS_IMX_HAL)
  zephyr_library()
endif()

add_subdirectory_ifdef(
  CONFIG_MCUX
  mcux
  )

add_subdirectory_ifdef(
  CONFIG_HAS_IMX_HAL
  imx
  )
