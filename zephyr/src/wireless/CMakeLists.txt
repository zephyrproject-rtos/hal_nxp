if(CONFIG_NXP_MONOLITHIC_WIFI OR CONFIG_BT_H4_NXP_CTLR)
  set(hal_blobs_dir ${ZEPHYR_HAL_NXP_MODULE_DIR}/zephyr/blobs)
  set(wifi_bt_binary_blobs_list)
  set(binary_blobs_list)
  set(output_includes_list)

  if(CONFIG_WIFI_NXP)
    if(CONFIG_NXP_IW61X)
      list(APPEND output_includes_list ${ZEPHYR_BINARY_DIR}/include/generated/nw61x_wifi_fw.bin.se.inc)
      set(wifi_binary_blob_name sduart_nw61x.bin.se)
      zephyr_library_sources(${CMAKE_CURRENT_LIST_DIR}/nw61x/nw61x_cpu1.c)
      set_source_files_properties(
		${CMAKE_CURRENT_LIST_DIR}/nw61x/nw61x_cpu1.c
		PROPERTIES OBJECT_DEPENDS ${ZEPHYR_BINARY_DIR}/include/generated/nw61x_wifi_fw.bin.se.inc
		)
      list(APPEND wifi_bt_binary_blobs_list ${hal_blobs_dir}/nw61x/${wifi_binary_blob_name})
    elseif(CONFIG_NXP_88W8987)
      list(APPEND output_includes_list ${ZEPHYR_BINARY_DIR}/include/generated/8987_wifi_fw.bin.inc)
      set(wifi_binary_blob_name sd8987_wlan.bin)
      zephyr_library_sources(${CMAKE_CURRENT_LIST_DIR}/8987/8987_cpu1.c)
      set_source_files_properties(
		${CMAKE_CURRENT_LIST_DIR}/8987/8987_cpu1.c
		PROPERTIES OBJECT_DEPENDS ${ZEPHYR_BINARY_DIR}/include/generated/8987_wifi_fw.bin.inc
		)
      list(APPEND wifi_bt_binary_blobs_list ${hal_blobs_dir}/8987/${wifi_binary_blob_name})
    elseif(CONFIG_NXP_IW416)
      list(APPEND output_includes_list ${ZEPHYR_BINARY_DIR}/include/generated/iw416_wifi_fw.bin.inc)
      set(wifi_binary_blob_name sduartIW416_wlan_bt.bin)
      zephyr_library_sources(${CMAKE_CURRENT_LIST_DIR}/IW416/IW416_cpu1.c)
      set_source_files_properties(
		${CMAKE_CURRENT_LIST_DIR}/IW416/IW416_cpu1.c
		PROPERTIES OBJECT_DEPENDS ${ZEPHYR_BINARY_DIR}/include/generated/iw416_wifi_fw.bin.inc
		)
      list(APPEND wifi_bt_binary_blobs_list ${hal_blobs_dir}/IW416/${wifi_binary_blob_name})
    elseif(CONFIG_NXP_88W8801)
      list(APPEND output_includes_list ${ZEPHYR_BINARY_DIR}/include/generated/8801_wifi_fw.bin.inc)
      set(wifi_binary_blob_name sd8801_wlan.bin)
      zephyr_library_sources(${CMAKE_CURRENT_LIST_DIR}/8801/8801_cpu1.c)
      set_source_files_properties(
		${CMAKE_CURRENT_LIST_DIR}/8801/8801_cpu1.c
		PROPERTIES OBJECT_DEPENDS ${ZEPHYR_BINARY_DIR}/include/generated/8801_wifi_fw.bin.inc
		)
      list(APPEND wifi_bt_binary_blobs_list ${hal_blobs_dir}/8801/${wifi_binary_blob_name})
    elseif(CONFIG_NXP_IW610)
      list(APPEND output_includes_list ${ZEPHYR_BINARY_DIR}/include/generated/iw610_wifi_fw.bin.se.inc)
      set(wifi_binary_blob_name sd_iw610.bin.se)
      zephyr_library_sources(${CMAKE_CURRENT_LIST_DIR}/IW610/IW610_cpu1.c)
      set_source_files_properties(
		${CMAKE_CURRENT_LIST_DIR}/IW610/IW610_cpu1.c
		PROPERTIES OBJECT_DEPENDS ${ZEPHYR_BINARY_DIR}/include/generated/iw610_wifi_fw.bin.se.inc
		)
      list(APPEND wifi_bt_binary_blobs_list ${hal_blobs_dir}/IW610/${wifi_binary_blob_name})
    else()
      message(FATAL_ERROR "Couldn't determine soc revision")
    endif()
  endif()

  if (CONFIG_BT_H4_NXP_CTLR)
    if(CONFIG_BT_NXP_NW612)
      list(APPEND output_includes_list ${ZEPHYR_BINARY_DIR}/include/generated/nw61x_bt_fw.bin.inc)
      set(bt_binary_blob_name uart_nw61x.bin.se)
      zephyr_library_sources(${CMAKE_CURRENT_LIST_DIR}/nw61x/nw61x_cpu2.c)
      set_source_files_properties(
		${CMAKE_CURRENT_LIST_DIR}/nw61x/nw61x_cpu2.c
		PROPERTIES OBJECT_DEPENDS ${ZEPHYR_BINARY_DIR}/include/generated/nw61x_bt_fw.bin.inc
		)
      list(APPEND wifi_bt_binary_blobs_list ${hal_blobs_dir}/nw61x/${bt_binary_blob_name})
    elseif(CONFIG_BT_NXP_IW416)
      list(APPEND output_includes_list ${ZEPHYR_BINARY_DIR}/include/generated/iw416_bt_fw.bin.inc)
      set(bt_binary_blob_name uartIW416_bt.bin)
      zephyr_library_sources(${CMAKE_CURRENT_LIST_DIR}/IW416/IW416_cpu2.c)
      set_source_files_properties(
		${CMAKE_CURRENT_LIST_DIR}/IW416/IW416_cpu2.c
		PROPERTIES OBJECT_DEPENDS ${ZEPHYR_BINARY_DIR}/include/generated/iw416_bt_fw.bin.inc
		)
      list(APPEND wifi_bt_binary_blobs_list ${hal_blobs_dir}/IW416/${bt_binary_blob_name})
    elseif(CONFIG_BT_NXP_IW610)
      list(APPEND output_includes_list ${ZEPHYR_BINARY_DIR}/include/generated/iw610_bt_fw.bin.inc)
      set(bt_binary_blob_name uart_iw610_bt.bin.se)
      zephyr_library_sources(${CMAKE_CURRENT_LIST_DIR}/IW610/IW610_cpu2.c)
      set_source_files_properties(
		${CMAKE_CURRENT_LIST_DIR}/IW610/IW610_cpu2.c
		PROPERTIES OBJECT_DEPENDS ${ZEPHYR_BINARY_DIR}/include/generated/iw610_bt_fw.bin.inc
		)
      list(APPEND wifi_bt_binary_blobs_list ${hal_blobs_dir}/IW610/${bt_binary_blob_name})
    else()
      message(FATAL_ERROR "Unsupported controller. Please select a BT conntroller, refer to ./driver/bluetooth/hci/Kconfig.nxp")
    endif()
  endif()

  if(NOT CONFIG_BUILD_ONLY_NO_BLOBS)
    list(LENGTH wifi_bt_binary_blobs_list count)
    math(EXPR count "${count}-1")
    foreach(i RANGE ${count})
      list(GET wifi_bt_binary_blobs_list ${i} wifi_bt_binary_blob)
      if(EXISTS ${wifi_bt_binary_blob})
        set(binary_blob ${wifi_bt_binary_blob})
      else()
        message(FATAL_ERROR "Couldn't find wifi/bt firmware ! ${wifi_bt_binary_blob}")
      endif()

      list(APPEND binary_blobs_list ${binary_blob})
    endforeach()

    list(LENGTH binary_blobs_list count)
    math(EXPR count "${count}-1")
    foreach(i RANGE ${count})
      list(GET binary_blobs_list ${i} binary_blob)
      list(GET output_includes_list ${i} output_include)
      zephyr_blobs_verify(FILES ${binary_blob})
      message(STATUS " generate include of binary blob: ${binary_blob}")
      generate_inc_file_for_target(${ZEPHYR_CURRENT_LIBRARY} ${binary_blob} ${output_include})
    endforeach()
  endif()

endif()
