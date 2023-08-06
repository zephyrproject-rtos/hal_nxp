if(CONFIG_HAS_MCUX OR CONFIG_HAS_IMX_HAL OR CONFIG_HAS_NXP_S32_HAL)
  zephyr_library()
endif()

if(CONFIG_HAS_NXP_S32_HAL)
  add_subdirectory(s32)
else()
  add_subdirectory_ifdef(
    CONFIG_HAS_MCUX
    mcux
    )

  add_subdirectory_ifdef(
    CONFIG_HAS_IMX_HAL
    imx
    )
endif()
