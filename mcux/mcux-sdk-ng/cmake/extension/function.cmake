# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
function(mcux_add_source)
  set(single_value BASE_PATH CONFIG PREINCLUDE EXCLUDE SCOPE)
  set(multi_value SOURCES PREINCLUDE_TYPE ${MCUX_SOURCE_CONDITION})
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  # The default scope for source is private
  if(__SCOPE)
    set(source_scope ${__SCOPE})
    if(NOT "PRIVATE PUBLIC INTERFACE" MATCHES ${__SCOPE})
      log_fatal("${CMAKE_CURRENT_LIST_FILE}: Error while adding ${__SOURCES}, SCOPE ${__SCOPE} is invalid, it should be PRIVATE, PUBLIC or INTERFACE")
    endif ()
  else()
    set(source_scope PRIVATE)
  endif()

  foreach(item ${__SOURCES})
    foreach(cond ${MCUX_SOURCE_CONDITION})
      if(__${cond})

        list(FIND MCUX_SOURCE_CONDITION ${cond} INDEX)

        if(${INDEX} GREATER -1)

          list(GET CMAKE_CONDITION ${INDEX} _cmake_cond)

          if(_cmake_cond IN_LIST LIST_CMAKE_CONDITION)
            set(condition_meet 0)
            foreach(cmake_condition_item ${${_cmake_cond}})
              if(cmake_condition_item IN_LIST __${cond})
                set(condition_meet 1)
              endif()
            endforeach()
            if(NOT condition_meet)
              return()
            endif()
          elseif(NOT ${${_cmake_cond}} IN_LIST __${cond})
            return()
          endif()
        endif()

      endif()

    endforeach()

    if(__BASE_PATH)
      set(source_abs_path ${__BASE_PATH}/${item})
    else()
      set(source_abs_path ${CMAKE_CURRENT_LIST_DIR}/${item})
    endif()

    file(TO_CMAKE_PATH ${source_abs_path} source_abs_path)
    get_filename_component(source_abs_path ${source_abs_path} ABSOLUTE)

    # get the file name from source_abs_path
    get_filename_component(file ${source_abs_path} NAME)
    # get directory from source_abs_path
    get_filename_component(directory ${source_abs_path} DIRECTORY)

    set(files "")
    # check if the file_name follow the pattern *.* and **
    string(REGEX MATCH "\\*\\..*" match "${file}")
    if (match)
      file(GLOB files "${directory}/${file}")
    else ()
      string(REGEX MATCH "\\*\\*" match "${file}")
      if (match)
        file(GLOB_RECURSE files "${directory}/*")
      else ()
        # add source_abs_path to list file
        list(APPEND files "${source_abs_path}")
      endif ()
    endif ()
    foreach(source_abs_path ${files})
        # process config files, project customized config files have higher priority
        # over component default config files
        get_filename_component(BASE_NAME ${item} NAME)
        mcux_get_property(ADDED_DEFAULT_CONFIG_FILE ADDED_DEFAULT_CONFIG_FILE_${BASE_NAME})
        mcux_get_property(ADDED_CUSTOM_CONFIG_FILE ADDED_CUSTOM_CONFIG_FILE_${BASE_NAME})

        if(__CONFIG) # component config file
          if(ADDED_DEFAULT_CONFIG_FILE)
            log_error(
              "Config file ${source_abs_path} has already been defined by in other component."
            )
            return()
          elseif(ADDED_CUSTOM_CONFIG_FILE)
            log_debug("Source ${source_abs_path} has already been added, skip it." ${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE})
            continue()
          else()
            # check whether this source has been added, which means example customized one has been loaded befored
            get_property(
              SOURCE_FILES
              TARGET ${MCUX_SDK_PROJECT_NAME}
              PROPERTY SOURCES)
            
            if (SOURCE_FILES) # SOURCE_FILES might be empty
              # get NAME of each SOURCE_FILES
              foreach(SOURCE_FILE ${SOURCE_FILES})
                get_filename_component(SOURCE_FILE_NAME ${SOURCE_FILE} NAME)
                list(APPEND SOURCE_FILE_NAME_LIST ${SOURCE_FILE_NAME})
              endforeach()

              list(FIND SOURCE_FILE_NAME_LIST ${BASE_NAME} INDEX)

              if(${INDEX} GREATER -1)
                # TODO, log might be wrong in file and line
                log_debug("Source ${source_abs_path} has already been added, skip it." ${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE})
                list(GET SOURCE_FILES ${INDEX} customized_config_source_path)
                mcux_set_property(ADDED_CUSTOM_CONFIG_FILE_${BASE_NAME} ${customized_config_source_path})

                # if the component config file is header and its include has been added, need to remove it.
                mcux_get_property(ADDED_DEFAULT_CONFIG_FILE_INCLUDE_PATH ADDED_DEFAULT_CONFIG_FILE_INCLUDE_PATH_${BASE_NAME})
                if (ADDED_DEFAULT_CONFIG_FILE_INCLUDE_PATH)
                  get_property(
                    INCLUDE_PATH
                    TARGET ${MCUX_SDK_PROJECT_NAME}
                    PROPERTY INCLUDE_DIRECTORIES)
                  list(REMOVE_ITEM INCLUDE_PATH ${ADDED_DEFAULT_CONFIG_FILE_INCLUDE_PATH})
                  set_property(TARGET ${MCUX_SDK_PROJECT_NAME}
                              PROPERTY INCLUDE_DIRECTORIES ${INCLUDE_PATH})
                endif()
                continue()
              else()
                mcux_set_property(ADDED_DEFAULT_CONFIG_FILE_${BASE_NAME} ${source_abs_path})
              endif()
            else()
              mcux_set_property(ADDED_DEFAULT_CONFIG_FILE_${BASE_NAME} ${source_abs_path})
            endif()

          endif()
        elseif(ADDED_DEFAULT_CONFIG_FILE) # example config and the component config has been added
          # remove the added default config file from component
          log_status("Will use custom config file ${source_abs_path} from project")
          get_property(
            SOURCE_FILES
            TARGET ${MCUX_SDK_PROJECT_NAME}
            PROPERTY SOURCES)

          list(REMOVE_ITEM SOURCE_FILES ${ADDED_DEFAULT_CONFIG_FILE})
          set_property(TARGET ${MCUX_SDK_PROJECT_NAME} PROPERTY SOURCES
                                                                ${SOURCE_FILES})
          # if the component config file is header and its include has been added, need to remove it.
          mcux_get_property(ADDED_DEFAULT_CONFIG_FILE_INCLUDE_PATH ADDED_DEFAULT_CONFIG_FILE_INCLUDE_PATH_${BASE_NAME})
          if (ADDED_DEFAULT_CONFIG_FILE_INCLUDE_PATH)
            get_property(
              INCLUDE_PATH
              TARGET ${MCUX_SDK_PROJECT_NAME}
              PROPERTY INCLUDE_DIRECTORIES)
            list(REMOVE_ITEM INCLUDE_PATH ${ADDED_DEFAULT_CONFIG_FILE_INCLUDE_PATH})
            set_property(TARGET ${MCUX_SDK_PROJECT_NAME}
                        PROPERTY INCLUDE_DIRECTORIES ${INCLUDE_PATH})
          endif()      
          mcux_set_property(ADDED_CUSTOM_CONFIG_FILE_${BASE_NAME} ${source_abs_path})
        endif()

        if (__PREINCLUDE)
          set(pre_flag "")
          if(${CONFIG_TOOLCHAIN} STREQUAL "iar")
            set(pre_flag "--preinclude ${source_abs_path}")
            set(as_pre_flag "-P ${source_abs_path}")
          elseif(${CONFIG_TOOLCHAIN} STREQUAL "armgcc")
            set(pre_flag "-include ${source_abs_path}")
          elseif(${CONFIG_TOOLCHAIN} STREQUAL "zephyr")
            set(pre_flag "-include ${source_abs_path}")            
          elseif(${CONFIG_TOOLCHAIN} STREQUAL "mdk")
            set(pre_flag "-include ${source_abs_path}")
          elseif(${CONFIG_TOOLCHAIN} STREQUAL "xtensa")
            set(pre_flag "-include ${source_abs_path}")
          elseif(${CONFIG_TOOLCHAIN} STREQUAL "codewarrior")
            set(pre_flag "-include ${source_abs_path}")
          elseif(${CONFIG_TOOLCHAIN} STREQUAL "riscvllvm")
            set(pre_flag "-include ${source_abs_path}")
          endif()
          if (pre_flag)
            if(__PREINCLUDE_TYPE)
              if("c_include" IN_LIST __PREINCLUDE_TYPE)
                mcux_append_single_compiler_flags_variable("CC" "${pre_flag}")
              endif()
              if("cpp_include" IN_LIST __PREINCLUDE_TYPE)
                mcux_append_single_compiler_flags_variable("CX" "${pre_flag}")
              endif()
            else()
              mcux_append_single_compiler_flags_variable("CC" "${pre_flag}")
              mcux_append_single_compiler_flags_variable("CX" "${pre_flag}")
            endif()
          endif()
          if(${CONFIG_TOOLCHAIN} STREQUAL "codewarrior")
          # don't set preinclude file for codewarrior assembler, otherwise build failed
          ### MWASM5~1.EXE Assembler:
          #      In: RTE_Components.h
          #    From: ..\devices\DSC\MC56F83xxx\MC56F83789\codewarrior\MC56F83xxx_init.asm
          # -----------------------------------------------------------------------------
          #       1: #define CONFIG_DBI_USE_MIPI_PANEL 0
          #   Error: ^
          #   Unrecognized mnemonic: CONFIG_DBI_USE_MIPI_PANE
          elseif (as_pre_flag)
            if(__PREINCLUDE_TYPE)
               if("asm_include" IN_LIST __PREINCLUDE_TYPE)
                 mcux_append_single_compiler_flags_variable("AS" "${as_pre_flag}")
               endif()
            else()
              mcux_append_single_compiler_flags_variable("AS" "${as_pre_flag}")
            endif()
          else ()
            if(__PREINCLUDE_TYPE)
              if("asm_include" IN_LIST __PREINCLUDE_TYPE)
                mcux_append_single_compiler_flags_variable("AS" "${pre_flag}")
              endif()
            else()
              mcux_append_single_compiler_flags_variable("AS" "${pre_flag}")
            endif()
          endif ()
        endif()

        if (NOT __EXCLUDE)
          target_sources(${MCUX_SDK_PROJECT_NAME} ${source_scope} ${source_abs_path})
          log_debug("Add source ${source_abs_path} into project"
                    ${CMAKE_CURRENT_LIST_FILE})
        else()
          mcux_set_property(MCUX_EXCLUDE_FILE_LIST ${source_abs_path} APPEND)
        endif ()

        # need to go through remove source list and remove the source from
        # TO_BE_REMOVED_SOURCES
        mcux_get_property(REMOVE_SOURCES TO_BE_REMOVED_SOURCES)
        # get MCUX_SDK_PROJECT_NAME sources
        get_property(
          SOURCE_FILES
          TARGET ${MCUX_SDK_PROJECT_NAME}
          PROPERTY SOURCES)
        # remove all sources in remove list from SOURCE_FILES
        foreach(source ${REMOVE_SOURCES})
          list(FIND SOURCE_FILES ${source} INDEX)
          if(${INDEX} GREATER -1)
            list(REMOVE_ITEM SOURCE_FILES ${source})
            # remove the source from remove sources, project shall not have
            # duplicated sources
            list(REMOVE_ITEM REMOVE_SOURCES ${source})
            set_property(TARGET ${MCUX_SDK_PROJECT_NAME} PROPERTY SOURCES
                                                                  ${SOURCE_FILES})
            log_debug(
              "Remove source ${source} from project because it is in the TO_BE_REMOVED_SOURCES list"
            )
          endif()
        endforeach()

        # update TO_BE_REMOVED_SOURCES
        if(REMOVE_SOURCES)
          mcux_set_property(TO_BE_REMOVED_SOURCES ${REMOVE_SOURCES})
        else()
          mcux_clear_property(TO_BE_REMOVED_SOURCES)
        endif()
  
    endforeach()
  
  endforeach()
endfunction()

macro(_mcux_add_specific_include type)
  foreach(item ${__INCLUDES})
    foreach(cond ${MCUX_SOURCE_CONDITION})
      if(__${cond})

        list(FIND MCUX_SOURCE_CONDITION ${cond} INDEX)

        if(${INDEX} GREATER -1)

          list(GET CMAKE_CONDITION ${INDEX} _cmake_cond)

          if(_cmake_cond IN_LIST LIST_CMAKE_CONDITION)
            set(condition_meet 0)
            foreach(cmake_condition_item ${${_cmake_cond}})
              if(cmake_condition_item IN_LIST __${cond})
                set(condition_meet 1)
              endif()
            endforeach()
            if(NOT condition_meet)
              return()
            endif()
          elseif(NOT ${${_cmake_cond}} IN_LIST __${cond})
            return()
          endif()
        endif()

      endif()
    endforeach()

    if(__BASE_PATH)
      set(include_abs_path ${__BASE_PATH}/${item})
    else()
      set(include_abs_path ${CMAKE_CURRENT_LIST_DIR}/${item})
    endif()

    file(TO_CMAKE_PATH ${include_abs_path} include_abs_path)
    get_filename_component(include_abs_path ${include_abs_path} ABSOLUTE)

    if(__TARGET_FILES)
      foreach(each_target_file ${__TARGET_FILES})
        log_debug("Found config file ${each_target_file}"
                ${CMAKE_CURRENT_LIST_FILE})

        get_filename_component(BASE_NAME ${each_target_file} NAME)

        mcux_get_property(ADDED_CUSTOM_CONFIG_FILE ADDED_CUSTOM_CONFIG_FILE_${BASE_NAME})
        if (ADDED_CUSTOM_CONFIG_FILE)
          log_debug("Already added custom config file ${ADDED_CUSTOM_CONFIG_FILE}, skip ${each_target_file}.")
          return()
        endif()

        mcux_get_property(ADDED_DEFAULT_CONFIG_FILE_INCLUDE_PATH ADDED_DEFAULT_CONFIG_FILE_INCLUDE_PATH_${BASE_NAME})
        if(ADDED_DEFAULT_CONFIG_FILE_INCLUDE_PATH)
          log_error(
                  "Config file include ${include_abs_path} has already been defined by in other component."
          )
          return()
        endif()

        mcux_get_property(ADDED_DEFAULT_CONFIG_FILE ADDED_DEFAULT_CONFIG_FILE_${BASE_NAME})

        # check whether this source has been added, which means example customized one has been loaded befored
        get_property(
                SOURCE_FILES
                TARGET ${MCUX_SDK_PROJECT_NAME}
                PROPERTY SOURCES)

        if (SOURCE_FILES) # SOURCE_FILES might be empty
          # get NAME of each SOURCE_FILES
          foreach(SOURCE_FILE ${SOURCE_FILES})
            get_filename_component(SOURCE_FILE_NAME ${SOURCE_FILE} NAME)
            list(APPEND SOURCE_FILE_NAME_LIST ${SOURCE_FILE_NAME})
          endforeach()

          list(FIND SOURCE_FILE_NAME_LIST ${BASE_NAME} INDEX)

          if(${INDEX} GREATER -1 AND NOT ADDED_DEFAULT_CONFIG_FILE)
            # TODO, log might be wrong in file and line
            log_debug("Source ${BASE_NAME} has already been added, skip it." ${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE})
            list(GET SOURCE_FILES ${INDEX} customized_config_source_path)
            mcux_set_property(ADDED_CUSTOM_CONFIG_FILE_${BASE_NAME} ${customized_config_source_path})
            return()
          else()
            mcux_set_property(ADDED_DEFAULT_CONFIG_FILE_INCLUDE_PATH_${BASE_NAME} ${include_abs_path})
          endif()
        else()
          mcux_set_property(ADDED_DEFAULT_CONFIG_FILE_INCLUDE_PATH_${BASE_NAME} ${include_abs_path})
        endif()
      endforeach ()
    endif()

    if(${type} STREQUAL AS)
      target_include_directories(
        ${MCUX_SDK_PROJECT_NAME}
        PUBLIC $<$<COMPILE_LANGUAGE:ASM>:${include_abs_path}>)
    elseif(${type} STREQUAL CC)
      target_include_directories(
        ${MCUX_SDK_PROJECT_NAME}
        PUBLIC $<$<COMPILE_LANGUAGE:C>:${include_abs_path}>)
    elseif(${type} STREQUAL CX)
      target_include_directories(
        ${MCUX_SDK_PROJECT_NAME}
        PUBLIC $<$<COMPILE_LANGUAGE:CXX>:${include_abs_path}>)
    else()
      target_include_directories(${MCUX_SDK_PROJECT_NAME}
                                 PUBLIC "${include_abs_path}")
    endif()
    log_debug("Add include ${include_abs_path} into project"
              ${CMAKE_CURRENT_LIST_FILE})

    # need to go through remove include list and remove the include from
    # TO_BE_REMOVED_INCLUDES
    mcux_get_property(REMOVE_INCLUDES TO_BE_REMOVED_INCLUDES)
    # get MCUX_SDK_PROJECT_NAME includes
    get_property(
      INCLUDES
      TARGET ${MCUX_SDK_PROJECT_NAME}
      PROPERTY INCLUDE_DIRECTORIES)
    # remove all includes in remove list from INCLUDES
    foreach(include ${REMOVE_INCLUDES})
      list(FIND INCLUDES ${include} INDEX)
      if(${INDEX} GREATER -1)
        list(REMOVE_ITEM INCLUDES ${include})
        # remove the include from remove includes, project shall not have
        # duplicated includes
        list(REMOVE_ITEM REMOVE_INCLUDES ${include})
        set_property(TARGET ${MCUX_SDK_PROJECT_NAME}
                     PROPERTY INCLUDE_DIRECTORIES ${INCLUDES})
        log_debug(
          "Remove include ${include} from project because it is in the TO_BE_REMOVED_INCLUDES list"
        )
      endif()
    endforeach()

    # update TO_BE_REMOVED_INCLUDES
    if(REMOVE_INCLUDES)
      mcux_set_property(TO_BE_REMOVED_INCLUDES ${REMOVE_INCLUDES})
    else()
      mcux_clear_property(TO_BE_REMOVED_INCLUDES)
    endif()
  endforeach()
endmacro()

function(mcux_add_include)
  set(single_value BASE_PATH CONFIG)
  set(multi_value INCLUDES TARGET_FILES ${MCUX_SOURCE_CONDITION} SYS_SEARCH_PATH SYS_PATH_RECURSIVELY)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})
  if(__INCLUDES)
    _mcux_add_specific_include(ALL)
  endif()
endfunction()

function(mcux_add_codewarrior_sys_include)
  set(multi_value TARGETS SYS_SEARCH_PATH SYS_PATH_RECURSIVELY)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
          ${ARGN})
  set(match_target false)
  if(__TARGETS)
    foreach(item ${__TARGETS})
      if(${item} STREQUAL ${CMAKE_BUILD_TYPE})
        set(match_target true)
      endif()
    endforeach()
  else()
    set(match_target true)
  endif()

  if(NOT ${match_target})
    return()
  endif()

  if(__SYS_SEARCH_PATH)
    foreach(item ${__SYS_SEARCH_PATH})
      mcux_append_single_compiler_flags_variable(CC "-I- -i ${item}")
    endforeach()
  endif ()
  if(__SYS_PATH_RECURSIVELY)
    foreach(item ${__SYS_PATH_RECURSIVELY})
      mcux_append_single_compiler_flags_variable(CC "-I- -ir ${item}")
    endforeach()
  endif ()
endfunction()

function(mcux_add_asm_include)
  set(single_value BASE_PATH CONFIG)
  set(multi_value INCLUDES TARGET_FILES ${MCUX_SOURCE_CONDITION})
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(__INCLUDES)
    _mcux_add_specific_include(AS)
  endif()
endfunction()

function(mcux_add_c_include)
  set(single_value BASE_PATH CONFIG)
  set(multi_value INCLUDES TARGET_FILES ${MCUX_SOURCE_CONDITION})
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(__INCLUDES)
    _mcux_add_specific_include(CC)
  endif()
endfunction()

function(mcux_add_cpp_include)
  set(single_value BASE_PATH CONFIG)
  set(multi_value INCLUDES TARGET_FILES ${MCUX_SOURCE_CONDITION})
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(__INCLUDES)
    _mcux_add_specific_include(CX)
  endif()
endfunction()

function(mcux_set_variable name value)
  string(LENGTH "${value}" length)
  if(${length} EQUAL 0)
    set(value "")
  elseif(${value} STREQUAL '')
    set(value "")
  endif()

  mcux_get_property(defined_varible VARIABLE_FROM_CMAKE)

  if(defined_varible)
    foreach(item ${defined_varible})
      string(FIND "${item}" "${name}=" index)
      if(${index} GREATER -1)
        string(REGEX REPLACE "${name}=" "" preset_value ${item})
        if (NOT ${preset_value} STREQUAL ${value})
          log_error("Variable '${name}' has already been set in previous cmake file with value '${preset_value}'. Here try to reset it to different value '${value}'. You can run with '--log-level=debug' to see in which cmake the '${name}' is firstly defined and update its definition based on needs." ${CMAKE_CURRENT_LIST_FILE})
        endif()
      endif()
    endforeach()
  endif()

  mcux_set_property(VARIABLE_FROM_CMAKE "${name}=${value}" APPEND)

  if(${name} STREQUAL board)
    # for west cmd to find cached variable
    set(CACHED_BOARD
        ${value}
        CACHE STRING "Selected ${name}: ${value}")
  endif()

  if(${name} STREQUAL device)
    # for west cmd to find cached variable
    set(CACHED_DEVICE
        ${value}
        CACHE STRING "Selected ${name}: ${value}")
  endif()

  set(${name} ${value} CACHE STRING "The variable ${name}: ${value}" FORCE)

  log_debug("Variable ${name} is set to ${value}" ${CMAKE_CURRENT_LIST_FILE})

endfunction()

function(mcux_set_list name value)
  if(NOT value)
    set(value "")
  elseif(${value} STREQUAL '')
    set(value "")
  endif()

  string(REPLACE " " ";" value ${value})

  set(${name} ${value} PARENT_SCOPE)

  log_debug("List ${name} is set to ${value}" ${CMAKE_CURRENT_LIST_FILE})
endfunction()

function(post_build_process)

endfunction()

function(mcux_convert_binary)
  set(single_value BINARY TARGET)
  set(multi_value TOOLCHAINS EXTRA_ARGS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(__TOOLCHAINS)
    foreach(tool ${__TOOLCHAINS})
      if(${CONFIG_TOOLCHAIN} STREQUAL ${tool})
        set(binary_name ${__BINARY})
        break()
      endif()
    endforeach()
  else()
    set(binary_name ${__BINARY})
  endif()

  if(NOT binary_name)
    return()
  endif()
  
  if(__TARGET)
    set(target_name ${__TARGET})
  else()
    set(target_name ${MCUX_SDK_PROJECT_NAME})
  endif()

  # Library can not be converted to binary file, only convert executable
  get_target_property(TARGET_TYPE ${target_name} TYPE)
  if(NOT TARGET_TYPE STREQUAL "EXECUTABLE")
    log_warn("${target_name} is library type, can't be converted to binary file by mcux_convert_binary" ${CMAKE_CURRENT_LIST_FILE})
    return()
  endif()

  # Get the absolute folder path
  get_filename_component(FILE_PATH ${binary_name} DIRECTORY)
  file(MAKE_DIRECTORY ${FILE_PATH})

  log_debug("Convert to binary file ${binary_name}")

  # Get file extension name and set proper OBJDUMP_BIN_CMD
  get_filename_component(FILE_EXT ${binary_name} EXT)
  if(${FILE_EXT} STREQUAL ".srec")
    if (${CONFIG_TOOLCHAIN} STREQUAL "armgcc")
      set(OBJDUMP_BIN_CMD "-Osrec")
    elseif (${CONFIG_TOOLCHAIN} STREQUAL "iar")
        set(OBJDUMP_BIN_CMD "--srec")
    elseif (${CONFIG_TOOLCHAIN} STREQUAL "mdk")
      set(OBJDUMP_BIN_CMD "--m32combined")
    elseif (${CONFIG_TOOLCHAIN} STREQUAL "codewarrior")
      set(OBJDUMP_BIN_CMD "-srec")
    endif ()
  endif()
  if (${CONFIG_TOOLCHAIN} STREQUAL "codewarrior")
    if(NOT __EXTRA_ARGS)
      set(__EXTRA_ARGS -gap-fill 0xff -flash-start-x 0x20000)
    endif()
    target_link_options(${target_name} PRIVATE ${OBJDUMP_BIN_CMD} ${__EXTRA_ARGS})
    return()
  else()
    if(__EXTRA_ARGS)
      string(REPLACE " " ";" extra_args "${__EXTRA_ARGS}")
    else()
      set(extra_args)
    endif()
  endif()

  get_target_property(IMAGE_FILE_NAME ${target_name} OUTPUT_NAME)
  if (${IMAGE_FILE_NAME} STREQUAL "IMAGE_FILE_NAME-NOTFOUND")
     set(IMAGE_FILE_NAME ${target_name})
  endif()
  add_custom_command(
    TARGET ${target_name}
    POST_BUILD
    COMMAND
      ${CMAKE_OBJCOPY} ${OBJDUMP_BIN_CMD} ${extra_args}
      ${CMAKE_CURRENT_BINARY_DIR}/${IMAGE_FILE_NAME}${CMAKE_EXECUTABLE_SUFFIX}
      ${OBJDUMP_OUT_CMD} ${binary_name})

  get_target_property(clean_files ${target_name}
                      ADDITIONAL_CLEAN_FILES)
  list(APPEND clean_files ${binary_name})

  set_target_properties(${target_name}
                        PROPERTIES ADDITIONAL_CLEAN_FILES "${clean_files}")
endfunction()

function(get_target_source_in_sub_folders directory folder_terminator file_name)
  set(GET_TARGET_SOURCE_IN_SUB_FOLDERS_OUTPUT " ")
  string(REPLACE "/" ";" directory_list ${directory})
  list(REMOVE_ITEM directory_list "")
  list(REMOVE_ITEM directory_list ".")
  list(REVERSE directory_list)
  set(sub_directory ${directory})
  foreach(path_item ${directory_list})
    if(NOT ${path_item} STREQUAL ${folder_terminator})
      cmake_path(APPEND this_sub_directory ${sub_directory} ${file_name})
      cmake_path(GET sub_directory PARENT_PATH sub_directory)
      if(EXISTS ${this_sub_directory})
        get_filename_component(this_sub_directory "${this_sub_directory}"
                               ABSOLUTE)
        list(APPEND file_list ${this_sub_directory})
      endif()
    else()
      break()
    endif()
  endforeach()

  list(REVERSE file_list)
  set(GET_TARGET_SOURCE_IN_SUB_FOLDERS_OUTPUT
      ${file_list}
      PARENT_SCOPE)
endfunction()

function(mcux_set_property property value)
  cmake_parse_arguments(_ "APPEND" "" "" ${ARGN})
  if(__APPEND)
    set_property(
      TARGET mcux_build_properties
      APPEND
      PROPERTY ${property} ${value})
  else()
    set_property(TARGET mcux_build_properties PROPERTY ${property} ${value})
  endif()
endfunction()

function(mcux_clear_property property)
  set_property(TARGET mcux_build_properties PROPERTY ${property} "")
endfunction()

function(mcux_get_property var property)
  cmake_parse_arguments(_ "GENERATOR_EXPRESSION" "" "" ${ARGN})
  if(__GENERATOR_EXPRESSION)
    set(val "$<TARGET_PROPERTY:mcux_build_properties,${property}>")
  else()
    get_property(
      val
      TARGET mcux_build_properties
      PROPERTY ${property})
  endif()
  set(${var}
      ${val}
      PARENT_SCOPE)
endfunction()

function(_mcux_add_ld_library __LIB)
   _mcux_set_libs(SCOPE PRIVATE LIBS ${__LIB})
endfunction()

function(_mcux_add_configuration TYPE CONFIGS)
  _mcux_pre_process_configuration(CONFIGS ${CONFIGS})
  set(FILTERED_CONFIGS ${CONFIGS})

  # get to be removed compiler flag from to_ber_removed_config_property target
  mcux_get_property(_TO_BE_REMOVED_FLAGS INTERFACE_${TYPE}_TO_BE_REMOVED_FLAGS)

  # if _TO_BE_REMOVED_FLAGS is not empty and remove INTERFACE_${TYPE}_FLAGS item
  # from it
  if(_TO_BE_REMOVED_FLAGS)
    foreach(item ${CONFIGS})
      # check whether items in CONFIGS are in _FLAGS
      list(FIND _TO_BE_REMOVED_FLAGS ${item} index)
      if(${index} GREATER -1)
        # remove item from FILTERED_CONFIGS
        list(REMOVE_ITEM FILTERED_CONFIGS ${item})
        log_debug("Flag ${item} has been set to be removed in previous cmake")
      else()
        # add item into FILTERED_CONFIGS
        if(NOT ${item} IN_LIST FILTERED_CONFIGS)
          list(APPEND FILTERED_CONFIGS ${item})
        endif()
      endif()
    endforeach()
  endif()

  # add item in FILTERED_CONFIGS into CMAKE_${TYPE}_FLAGS
  if(FILTERED_CONFIGS)
    foreach(item ${FILTERED_CONFIGS})
      mcux_append_single_compiler_flags_variable(${TYPE} "${item}")
    endforeach()
  endif()

  # turn list FILTERED_CONFIGS into string string(REPLACE ";" " "
  # FILTERED_CONFIGS ${FILTERED_CONFIGS})
  log_debug("Add ${TYPE} flags ${FILTERED_CONFIGS}" ${CMAKE_CURRENT_LIST_FILE})
endfunction()

# convert string to list, for specific flag, such as -Xlinker --defsym=__heap_size__=0x2000,
# should be regarded as a whole flag to add or remove
function(_mcux_pre_process_configuration CONFIG_VAR CONFIGS)
  set(flag_prefix_list "-Xlinker" "--config_def" "--predefine")
  string(REPLACE " " ";" CONFIGS ${CONFIGS})
  set(tmp_list)
  list(LENGTH CONFIGS list_size)
  math(EXPR list_size "${list_size} - 1")
  set(find_prefix false)
  set(tmp_flag)
  foreach(index RANGE ${list_size})
    list(GET CONFIGS ${index} item)
    if (NOT item)
      continue()
    endif ()
    if(${item} IN_LIST flag_prefix_list)
      set(tmp_flag ${item})
      set(find_prefix true)
    elseif(${find_prefix} STREQUAL true)
      list(APPEND tmp_list "${tmp_flag} ${item}")
      set(find_prefix false)
      set(tmp_flag '')
    else()
      list(APPEND tmp_list ${item})
    endif()
  endforeach()

  # refine the compiler flag to make them buildable for compilers on both windows and linux
  # for example --keep=*(*ezhv_code) can build pass for armclang windows, but fail for armclang linux. --keep=*"("*ezhv_code")" work for both. So --keep=*(*ezhv_code) will be updated to --keep=*"("*ezhv_code")"
  set(updated_flags)
  foreach(item ${tmp_list})
    if (${item} MATCHES "--keep=.*\\(.*\\)")
      string(REPLACE "(" "\"(\"" item ${item})
      string(REPLACE ")" "\")\"" item ${item})
    endif()
    list(APPEND updated_flags ${item})
  endforeach()

  set(${CONFIG_VAR} ${updated_flags} PARENT_SCOPE)
endfunction()

function(mcux_add_configuration)
  set(single_value AS CC CX LD)
  set(multi_value TARGETS LIB TOOLCHAINS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  set(match_toolchain false)
  if(__TOOLCHAINS)
    foreach(tool ${__TOOLCHAINS})
      if(${CONFIG_TOOLCHAIN} STREQUAL ${tool})
        set(match_toolchain true)
        break()
      endif()
    endforeach()
  else ()
    set(match_toolchain true)
  endif()
  if(NOT ${match_toolchain})
    return()
  endif()

  if(__TARGETS)
    foreach(item ${__TARGETS})
      if(${item} STREQUAL ${CMAKE_BUILD_TYPE})
        if(__AS)
          _mcux_add_configuration(AS ${__AS})
        endif()
        if(__CC)
          _mcux_add_configuration(CC ${__CC})
        endif()
        if(__CX)
          _mcux_add_configuration(CX ${__CX})
        endif()
        if(__LD)
          _mcux_add_configuration(LD ${__LD})
        endif()
        if(__LIB)
          _mcux_add_ld_library(${__LIB})
        endif()
      endif()
    endforeach()
  else()
    if(__AS)
      _mcux_add_configuration(AS ${__AS})
    endif()
    if(__CC)
      _mcux_add_configuration(CC ${__CC})
    endif()
    if(__CX)
      _mcux_add_configuration(CX ${__CX})
    endif()
    if(__LD)
      _mcux_add_configuration(LD ${__LD})
    endif()
    if(__LIB)
      _mcux_add_ld_library(${__LIB})
    endif()
  endif()

endfunction()

function(mcux_add_armgcc_configuration)
  set(single_value AS CC CX LD)
  set(multi_value TARGETS LIB)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "armgcc")
    log_debug("Process armgcc flags" ${CMAKE_CURRENT_LIST_FILE})
    mcux_add_configuration(
      TARGETS
      ${__TARGETS}
      AS
      ${__AS}
      CC
      ${__CC}
      CX
      ${__CX}
      LD
      ${__LD}
      LIB
      ${__LIB})
  endif()

endfunction()

function(mcux_add_iar_configuration)
  set(single_value AS CC CX LD)
  set(multi_value TARGETS LIB)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "iar")
    log_debug("Process iar flags" ${CMAKE_CURRENT_LIST_FILE})
    mcux_add_configuration(
      TARGETS
      ${__TARGETS}
      AS
      ${__AS}
      CC
      ${__CC}
      CX
      ${__CX}
      LD
      ${__LD}
      LIB
      ${__LIB})
  endif()

endfunction()

function(mcux_add_mdk_configuration)
  set(single_value AS CC CX LD)
  set(multi_value TARGETS LIB)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "mdk")
    log_debug("Process mdk flags" ${CMAKE_CURRENT_LIST_FILE})
    mcux_add_configuration(
      TARGETS
      ${__TARGETS}
      AS
      ${__AS}
      CC
      ${__CC}
      CX
      ${__CX}
      LD
      ${__LD}
      LIB
      ${__LIB})
  endif()

endfunction()

function(mcux_add_mcux_configuration)
  set(single_value AS CC CX LD)
  set(multi_value TARGETS LIB)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "mcux")
    log_debug("Process mcux flags" ${CMAKE_CURRENT_LIST_FILE})
    mcux_add_configuration(
      TARGETS
      ${__TARGETS}
      AS
      ${__AS}
      CC
      ${__CC}
      CX
      ${__CX}
      LD
      ${__LD}
      LIB
      ${__LIB})
  endif()

endfunction()

function(mcux_add_armgcc_mcux_configuration)
  set(single_value AS CC CX LD)
  set(multi_value TARGETS LIB)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if((${CONFIG_TOOLCHAIN} STREQUAL "armgcc") OR (${CONFIG_TOOLCHAIN} STREQUAL
                                                 "mcux"))
    log_debug("Process armgcc mcux flags" ${CMAKE_CURRENT_LIST_FILE})
    mcux_add_configuration(
      TARGETS
      ${__TARGETS}
      AS
      ${__AS}
      CC
      ${__CC}
      CX
      ${__CX}
      LD
      ${__LD}
      LIB
      ${__LIB})
  endif()

endfunction()

function(mcux_add_xtensa_configuration)
  set(single_value AS CC CX LD)
  set(multi_value TARGETS LIB)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "xtensa")
    log_debug("Process xtensa flags" ${CMAKE_CURRENT_LIST_FILE})
    mcux_add_configuration(
      TARGETS
      ${__TARGETS}
      AS
      ${__AS}
      CC
      ${__CC}
      CX
      ${__CX}
      LD
      ${__LD}
      LIB
      ${__LIB})
  endif()

endfunction()

function(mcux_add_codewarrior_configuration)
  set(single_value AS CC CX LD)
  set(multi_value TARGETS LIB)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
          ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "codewarrior")
    log_debug("Process codewarrior flags" ${CMAKE_CURRENT_LIST_FILE})
    mcux_add_configuration(
            TARGETS
            ${__TARGETS}
            AS
            ${__AS}
            CC
            ${__CC}
            CX
            ${__CX}
            LD
            ${__LD}
            LIB
            ${__LIB})
  endif()

endfunction()

function(mcux_add_riscvllvm_configuration)
  set(single_value AS CC CX LD)
  set(multi_value TARGETS LIB)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "riscvllvm")
    log_debug("Process riscvllvm flags" ${CMAKE_CURRENT_LIST_FILE})
    mcux_add_configuration(
      TARGETS
      ${__TARGETS}
      AS
      ${__AS}
      CC
      ${__CC}
      CX
      ${__CX}
      LD
      ${__LD}
      LIB
      ${__LIB})
  endif()

endfunction()


function(_mcux_add_linker_script)
  set(single_value LINKER BASE_PATH TOOLCHAIN)
  set(multi_value TARGETS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  set(match_target false)
  if(__TARGETS)
    foreach(item ${__TARGETS})
      if(${item} STREQUAL ${CMAKE_BUILD_TYPE})
        set(match_target true)
      endif()
    endforeach()
  else()
    set(match_target true)
  endif()

  if(NOT ${match_target})
    return()
  endif()

  if(__BASE_PATH)
    set(linker_path ${__BASE_PATH}/${__LINKER})
  else()
    set(linker_path ${CMAKE_CURRENT_LIST_DIR}/${__LINKER})
  endif()

  get_filename_component(linker_path ${linker_path} ABSOLUTE)

  if(${CONFIG_TOOLCHAIN} STREQUAL "iar")
    set(ld_cmd "--config ${linker_path}")
  elseif(${CONFIG_TOOLCHAIN} STREQUAL "armgcc")
    set(ld_cmd "-T ${linker_path}")
  elseif(${CONFIG_TOOLCHAIN} STREQUAL "mdk")
    set(ld_cmd "--scatter ${linker_path}")
  elseif(${CONFIG_TOOLCHAIN} STREQUAL "codewarrior")
    set(ld_cmd "${linker_path}")
  elseif(${CONFIG_TOOLCHAIN} STREQUAL "riscvllvm")
    set(ld_cmd "-T ${linker_path} -static")
  endif()

  mcux_get_property(TO_BE_REMOVED_LD_FLAGS INTERFACE_LD_TO_BE_REMOVED_FLAGS)

  if(TO_BE_REMOVED_LD_FLAGS)
    string(FIND "${TO_BE_REMOVED_LD_FLAGS}" "${ld_cmd}" index)
    if(${index} GREATER -1)
      log_debug("Linker flag ${ld_cmd} has been set to be removed, do not add it.")
    else()
      mcux_append_single_compiler_flags_variable("LD" "${ld_cmd}")
      mcux_set_property(${MCUX_SDK_PROJECT_NAME}_LINKER_PATH ${linker_path})
      log_debug("Add linker flag ${ld_cmd} to LD flags" ${CMAKE_CURRENT_LIST_FILE})
    endif()
  else()
    mcux_append_single_compiler_flags_variable("LD" "${ld_cmd}")
    log_debug("Add linker flag ${ld_cmd} to LD flags" ${CMAKE_CURRENT_LIST_FILE})
    mcux_set_property(${MCUX_SDK_PROJECT_NAME}_LINKER_PATH ${linker_path})
  endif()

endfunction()

function(mcux_add_armgcc_linker_script)
  set(single_value LINKER BASE_PATH)
  set(multi_value TARGETS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "armgcc")
    _mcux_add_linker_script(TARGETS ${__TARGETS} BASE_PATH ${__BASE_PATH}
                            LINKER ${__LINKER})
  endif()
endfunction()

function(mcux_add_iar_linker_script)
  set(single_value LINKER BASE_PATH)
  set(multi_value TARGETS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "iar")
    _mcux_add_linker_script(TARGETS ${__TARGETS} BASE_PATH ${__BASE_PATH}
                            LINKER ${__LINKER})
  endif()
endfunction()

function(mcux_add_mdk_linker_script)
  set(single_value LINKER BASE_PATH)
  set(multi_value TARGETS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "mdk")
    _mcux_add_linker_script(TARGETS ${__TARGETS} BASE_PATH ${__BASE_PATH}
                            LINKER ${__LINKER})
  endif()
endfunction()

function(mcux_add_codewarrior_linker_script)
  set(single_value LINKER BASE_PATH)
  set(multi_value TARGETS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
          ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "codewarrior")
    _mcux_add_linker_script(TARGETS ${__TARGETS} BASE_PATH ${__BASE_PATH}
            LINKER ${__LINKER})
  endif()
endfunction()

function(mcux_add_riscvllvm_linker_script)
  set(single_value LINKER BASE_PATH)
  set(multi_value TARGETS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "riscvllvm")
    _mcux_add_linker_script(TARGETS ${__TARGETS} BASE_PATH ${__BASE_PATH}
                            LINKER ${__LINKER})
  endif()
endfunction()

function(mcux_add_cmakelists path)
  set(add_cmakelist 0)
  set(cmakelist_path ${path}/CMakeLists.txt)
  file(RELATIVE_PATH relative_path ${SdkRootDirPath} ${path})

  string(FIND ${relative_path} "../" sdk_path_index)
  if(${sdk_path_index} GREATER -1)
    string(REGEX REPLACE "^([.][.]/)+" "custom/" relative_path ${relative_path})
  endif()

  if(ARGC EQUAL 1)
    set(add_cmakelist 1)
    get_filename_component(binary_path "${APPLICATION_BINARY_DIR}/${relative_path}" ABSOLUTE)
  elseif(ARGC EQUAL 2)
    string(TOUPPER ${ARGV1} ARGV1)
    if(${ARGV1} STREQUAL OPTIONAL)
      if(EXISTS ${cmakelist_path})
        set(add_cmakelist 1)
        get_filename_component(binary_path "${APPLICATION_BINARY_DIR}/${relative_path}" ABSOLUTE)
      else()
        log_debug("No CMakeLists.txt in ${path}" ${CMAKE_CURRENT_LIST_FILE})
      endif()
    else()
      # If the second argument is not OPTIONAL, treat it as binary_path
      set(add_cmakelist 1)
      set(binary_path ${ARGV1})
    endif()
  elseif(ARGC EQUAL 3)
    set(binary_path ${ARGV2})
    string(TOUPPER ${ARGV1} ARGV1)
    if(${ARGV1} STREQUAL OPTIONAL)
      if(EXISTS ${cmakelist_path})
        set(add_cmakelist 1)
      else()
        log_debug("No CMakeLists.txt in ${path}" ${CMAKE_CURRENT_LIST_FILE})
      endif()
    else()
      log_fatal(
        "Wrong argument in mcux_add_cmakelists, second argument only supports OPTIONAL"
        ${CMAKE_CURRENT_LIST_FILE})
    endif()
  else()
    log_fatal(
      "Wrong number of arguments in mcux_add_cmakelists, expected 1, 2, or 3 arguments"
      ${CMAKE_CURRENT_LIST_FILE})
  endif()

  if(${add_cmakelist} EQUAL 1)
    if(NOT EXISTS ${cmakelist_path})
      log_error("No CMakeLists.txt in ${path}" ${CMAKE_CURRENT_LIST_FILE})
    else()
      log_debug("Include CMakeLists.txt from ${path}"
                ${CMAKE_CURRENT_LIST_FILE})
      get_property(ADDED_SUBDIRS GLOBAL PROPERTY ADDED_SUBDIRS)
      get_filename_component(path "${path}" REALPATH)
      list(FIND ADDED_SUBDIRS ${path} SUBDIR_FOUND)
      if(SUBDIR_FOUND EQUAL -1)
        add_subdirectory(${path} ${binary_path})
        set_property(GLOBAL APPEND PROPERTY ADDED_SUBDIRS ${path})
      endif()
    endif()
  endif()
endfunction()

function(mcux_load_project_ide_data)
  set(IDE_yml_list)
  if(NOT DEFINED core_id)
    foreach(f
            ${SdkRootDirPath}/devices/IDE.yml
            ${SdkRootDirPath}/devices/${soc_portfolio}/IDE.yml
            ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/IDE.yml
            ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device}/IDE.yml)
      if(EXISTS ${f})
        list(APPEND IDE_yml_list ${f})
      endif()
    endforeach()

    if (DEFINED board)
      foreach(f
            ${SdkRootDirPath}/examples/IDE.yml
            ${SdkRootDirPath}/examples/_boards/IDE.yml
            ${SdkRootDirPath}/${board_root}/${board}/IDE.yml)
        if(EXISTS ${f})
          list(APPEND IDE_yml_list ${f})
        endif()
      endforeach()
    endif()
  else()
    foreach(f
            ${SdkRootDirPath}/devices/IDE.yml
            ${SdkRootDirPath}/devices/${soc_portfolio}/IDE.yml
            ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/IDE.yml
            ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device}/IDE.yml
            ${SdkRootDirPath}/${device_root}/${soc_portfolio}/${soc_series}/${device}/${core_id}/IDE.yml)
      if(EXISTS ${f})
        list(APPEND IDE_yml_list ${f})
      endif()
    endforeach()

    if (DEFINED board)
      foreach(f
            ${SdkRootDirPath}/examples/IDE.yml
            ${SdkRootDirPath}/examples/_boards/IDE.yml
            ${SdkRootDirPath}/${board_root}/${board}/IDE.yml
            ${SdkRootDirPath}/${board_root}/${board}/${core_id}/IDE.yml)
        if(EXISTS ${f})
          list(APPEND IDE_yml_list ${f})
        endif()
      endforeach()
    endif()
  endif()

  if (DEFINED project_board_port_path OR DEFINED project_device_port_path)
    get_target_source_in_sub_folders(${APPLICATION_SOURCE_DIR} ${EXAMPLE_FOLDER} "IDE.yml")
    list(APPEND IDE_yml_list ${GET_TARGET_SOURCE_IN_SUB_FOLDERS_OUTPUT})

    get_target_source_in_sub_folders(${full_project_port_path} "${board_device_folder}" "IDE.yml")
    list(APPEND IDE_yml_list ${GET_TARGET_SOURCE_IN_SUB_FOLDERS_OUTPUT})
  else()
    if (EXISTS ${APPLICATION_SOURCE_DIR}/IDE.yml)
      list(APPEND IDE_yml_list ${APPLICATION_SOURCE_DIR}/IDE.yml)
    endif()
  endif()

  foreach(f ${IDE_yml_list})
    mcux_load_ide_data(${f})
  endforeach()
endfunction()

function(mcux_load_ide_data yml)
  file(TO_CMAKE_PATH ${yml} yml)
  log_debug("Load IDE data: ${yml}" ${CMAKE_CURRENT_LIST_FILE})
  if(EXISTS ${yml})
    mcux_set_property(INTERFACE_IDE_YML_LIST ${yml} APPEND)
  elseif(EXISTS ${CMAKE_CURRENT_LIST_DIR}/${yml})
    mcux_set_property(INTERFACE_IDE_YML_LIST ${CMAKE_CURRENT_LIST_DIR}/${yml}
                      APPEND)
  endif()
endfunction()

function(mcux_remove_armgcc_configuration)
  set(single_value AS CC CX LD)
  set(multi_value TARGETS LIB)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "armgcc")
    mcux_remove_configuration(
      TARGETS
      ${__TARGETS}
      AS
      ${__AS}
      CC
      ${__CC}
      CX
      ${__CX}
      LD
      ${__LD}
      LIB
      ${__LIB})
  endif()

endfunction()

function(mcux_remove_mdk_configuration)
  set(single_value AS CC CX LD)
  set(multi_value TARGETS LIB)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "mdk")
    mcux_remove_configuration(
      TARGETS
      ${__TARGETS}
      AS
      ${__AS}
      CC
      ${__CC}
      CX
      ${__CX}
      LD
      ${__LD}
      LIB
      ${__LIB})
  endif()

endfunction()

function(mcux_remove_iar_configuration)
  set(single_value AS CC CX LD)
  set(multi_value TARGETS LIB)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "iar")
    mcux_remove_configuration(
      TARGETS
      ${__TARGETS}
      AS
      ${__AS}
      CC
      ${__CC}
      CX
      ${__CX}
      LD
      ${__LD})
  endif()

endfunction()

function(mcux_remove_configuration)
  set(single_value AS CC CX LD)
  set(multi_value TARGETS LIB TOOLCHAINS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  set(match_toolchain false)
  if(__TOOLCHAINS)
    foreach(tool ${__TOOLCHAINS})
      if(${CONFIG_TOOLCHAIN} STREQUAL ${tool})
        set(match_toolchain true)
        break()
      endif()
    endforeach()
  else ()
    set(match_toolchain true)
  endif()
  if(NOT ${match_toolchain})
    return()
  endif()

  if(__TARGETS)
    foreach(item ${__TARGETS})
      if(${item} STREQUAL ${CMAKE_BUILD_TYPE})
        if(__AS)
          _mcux_remove_configuration(AS ${__AS})
        endif()
        if(__CC)
          _mcux_remove_configuration(CC ${__CC})
        endif()
        if(__CX)
          _mcux_remove_configuration(CX ${__CX})
        endif()
        if(__LD)
          _mcux_remove_configuration(LD ${__LD})
        endif()
      endif()
    endforeach()
  else()
    if(__AS)
      _mcux_remove_configuration(AS ${__AS})
    endif()
    if(__CC)
      _mcux_remove_configuration(CC ${__CC})
    endif()
    if(__CX)
      _mcux_remove_configuration(CX ${__CX})
    endif()
    if(__LD)
      _mcux_remove_configuration(LD ${__LD})
    endif()
  endif()

endfunction()

function(_mcux_remove_configuration TYPE CONFIGS)
  if(TYPE STREQUAL "AS")
    set(_FLAGS ${CMAKE_ASM_FLAGS})
    set(CMAKE_ASM_FLAGS
        ""
        CACHE STRING "The Assembly compiler flags" FORCE)
  elseif(TYPE STREQUAL "CC")
    set(_FLAGS ${CMAKE_C_FLAGS})
    set(CMAKE_C_FLAGS
        ""
        CACHE STRING "The C compiler flags" FORCE)
  elseif(TYPE STREQUAL "CX")
    set(_FLAGS ${CMAKE_CXX_FLAGS})
    set(CMAKE_CXX_FLAGS
        ""
        CACHE STRING "The C++ compiler flags" FORCE)
  elseif(TYPE STREQUAL "LD")
    set(_FLAGS ${CMAKE_EXE_LINKER_FLAGS})
    set(CMAKE_EXE_LINKER_FLAGS
        ""
        CACHE STRING "The Linker flags" FORCE)
  endif()

  # convert _FLAGS to list
  _mcux_pre_process_configuration(_FLAGS ${_FLAGS})
  _mcux_pre_process_configuration(CONFIGS ${CONFIGS})

  if(_FLAGS)
    foreach(item ${_FLAGS})
      # clear property to prevent log about duplication, because all flags will be reset after removing the specific flag.
      string(REGEX MATCH "^-D([A-Za-z0-9_\\(\\)]+)=?(.*)?" _match "${item}")
      if(NOT "${_match}" STREQUAL "")
        mcux_clear_property(MCUX_${TYPE}_MACRO_${CMAKE_MATCH_1})
      endif()
    endforeach()
  endif()

  foreach(item ${CONFIGS})
    # add item into target INTERFACE_${TYPE}_TO_BE_REMOVED_FLAGS
    mcux_set_property(INTERFACE_${TYPE}_TO_BE_REMOVED_FLAGS ${item} APPEND)

    # check whether items in CONFIGS are in _FLAGS
    list(FIND _FLAGS ${item} index)
    if(${index} GREATER -1)
      list(REMOVE_ITEM _FLAGS ${item})
      # message that item has been removed
      log_debug(
        "Remove ${TYPE} flag ${item} because it is has been set to be removed in previous cmake"
      )
    endif()
  endforeach()

  if(_FLAGS)
    foreach(item ${_FLAGS})
      mcux_append_single_compiler_flags_variable(${TYPE} "${item}")
    endforeach()
  endif()

endfunction()

function(_mcux_remove_linker_script)
  set(single_value LINKER BASE_PATH)
  set(multi_value TARGETS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  set(match_target false)
  if(__TARGETS)
    foreach(item ${__TARGETS})
      if(${item} STREQUAL ${CMAKE_BUILD_TYPE})
        set(match_target true)
      endif()
    endforeach()
  else()
    set(match_target true)
  endif()

  if(NOT ${match_target})
    return()
  endif()

  # In cmake, linker is just a flag,
  if(__BASE_PATH)
    set(linker_path ${__BASE_PATH}/${__LINKER})
  else()
    set(linker_path ${CMAKE_CURRENT_LIST_DIR}/${__LINKER})
  endif()

  get_filename_component(linker_path ${linker_path} ABSOLUTE)

  if(${CONFIG_TOOLCHAIN} STREQUAL "iar")
    set(ld_cmd "--config ${linker_path}")
  elseif(${CONFIG_TOOLCHAIN} STREQUAL "armgcc")
    set(ld_cmd "-T ${linker_path}")
  elseif(${CONFIG_TOOLCHAIN} STREQUAL "mdk")
    set(ld_cmd "--scatter ${linker_path}")
  elseif(${CONFIG_TOOLCHAIN} STREQUAL "codewarrior")
    set(ld_cmd "${linker_path}")
  endif()

  mcux_set_property(INTERFACE_LD_TO_BE_REMOVED_FLAGS ${ld_cmd} APPEND)
  log_debug("Add linker flag ${ld_cmd} into TO_BE_REMOVED_FLAGS list"
            ${CMAKE_CURRENT_LIST_LINE})

  set(_LD_FLAGS ${CMAKE_EXE_LINKER_FLAGS})

  if(_LD_FLAGS)
    string(FIND "${_LD_FLAGS}" "${ld_cmd}" index)
    if(${index} GREATER -1)
      string(REPLACE ${ld_cmd} "" _LD_FLAGS ${_LD_FLAGS})
      set(CMAKE_EXE_LINKER_FLAGS
          ${_LD_FLAGS}
          CACHE STRING "The Linker flags" FORCE)
      log_debug("Remove linker flag ${ld_cmd}" ${CMAKE_CURRENT_LIST_LINE})
    endif()
  endif()
endfunction()

function(mcux_remove_iar_linker_script)
  set(single_value LINKER BASE_PATH)
  set(multi_value TARGETS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "iar")
    _mcux_remove_linker_script(TARGETS ${__TARGETS} BASE_PATH ${__BASE_PATH}
                               LINKER ${__LINKER})
  endif()

endfunction()

function(mcux_remove_mdk_linker_script)
  set(single_value LINKER BASE_PATH)
  set(multi_value TARGETS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "mdk")
    _mcux_remove_linker_script(TARGETS ${__TARGETS} BASE_PATH ${__BASE_PATH}
                               LINKER ${__LINKER})
  endif()
endfunction()

function(mcux_remove_armgcc_linker_script)
  set(single_value LINKER BASE_PATH)
  set(multi_value TARGETS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "armgcc")
    _mcux_remove_linker_script(TARGETS ${__TARGETS} BASE_PATH ${__BASE_PATH}
                               LINKER ${__LINKER})
  endif()

endfunction()

function(mcux_remove_mcux_linker_script)
  set(single_value LINKER BASE_PATH)
  set(multi_value TARGETS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "mcux")
    _mcux_remove_linker_script(TARGETS ${__TARGETS} BASE_PATH ${__BASE_PATH}
                               LINKER ${__LINKER})
  endif()
endfunction()

function(mcux_remove_codewarrior_linker_script)
  set(single_value LINKER BASE_PATH)
  set(multi_value TARGETS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
          ${ARGN})

  if(${CONFIG_TOOLCHAIN} STREQUAL "codewarrior")
    _mcux_remove_linker_script(TARGETS ${__TARGETS} BASE_PATH ${__BASE_PATH}
            LINKER ${__LINKER})
  endif()
endfunction()

function(mcux_project_remove_source)
  set(single_value BASE_PATH)
  set(multi_value SOURCES)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  # remove sources
  foreach(item ${__SOURCES})
    if(__BASE_PATH)
      set(source_abs_path ${__BASE_PATH}/${item})
    else()
      set(source_abs_path ${CMAKE_CURRENT_LIST_DIR}/${item})
    endif()

    file(TO_CMAKE_PATH ${source_abs_path} source_abs_path)
    get_filename_component(source_abs_path ${source_abs_path} ABSOLUTE)

    get_property(
      SOURCE_FILES
      TARGET ${MCUX_SDK_PROJECT_NAME}
      PROPERTY SOURCES)

    # if source_abs_path is in SOURCE_FILES, remove it from SOURCE_FILES
    list(FIND SOURCE_FILES ${source_abs_path} index)
    if(${index} GREATER -1)
      list(REMOVE_ITEM SOURCE_FILES ${source_abs_path})
      set_property(TARGET ${MCUX_SDK_PROJECT_NAME} PROPERTY SOURCES
                                                            ${SOURCE_FILES})
      log_debug("Remove source ${source_abs_path}" ${CMAKE_CURRENT_LIST_FILE})
    else()
      # put source_abs_path into TO_BE_REMOVED_SOURCES target
      mcux_set_property(TO_BE_REMOVED_SOURCES ${source_abs_path} APPEND)
      log_debug(
        "Add source ${source_abs_path} into TO_BE_REMOVED_SOURCES which means this source will not been added into project"
        ${CMAKE_CURRENT_LIST_FILE})
    endif()

  endforeach()

endfunction()

function(mcux_project_remove_include)
  set(single_value BASE_PATH)
  set(multi_value INCLUDES)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
                        ${ARGN})

  # remove includes
  foreach(item ${__INCLUDES})
    set(include_abs_path "")

    if(__BASE_PATH)
      set(include_abs_path ${__BASE_PATH}/${item})
    else()
      set(include_abs_path ${CMAKE_CURRENT_LIST_DIR}/${item})
    endif()

    file(TO_CMAKE_PATH ${include_abs_path} include_abs_path)
    get_filename_component(include_abs_path ${include_abs_path} ABSOLUTE)

    get_property(
      INCLUDES
      TARGET ${MCUX_SDK_PROJECT_NAME}
      PROPERTY INCLUDE_DIRECTORIES)

    # if include_abs_path is in INCLUDES, remove it from INCLUDES
    list(FIND INCLUDES ${include_abs_path} index)
    if(${index} GREATER -1)
      list(REMOVE_ITEM INCLUDES ${include_abs_path})
      set_property(TARGET ${MCUX_SDK_PROJECT_NAME} PROPERTY INCLUDE_DIRECTORIES
                                                            ${INCLUDES})
      log_debug("Remove include ${include_abs_path}" ${CMAKE_CURRENT_LIST_FILE})
    else()
      # put include_abs_path into TO_BE_REMOVED_INCLUDES target
      mcux_set_property(TO_BE_REMOVED_INCLUDES ${include_abs_path} APPEND)
      log_debug(
        "Add include ${include_abs_path} into TO_BE_REMOVED_INCLUDES which means this include will not be added into project"
        ${CMAKE_CURRENT_LIST_FILE})
    endif()

  endforeach()

endfunction()

function(mcux_load_all_dotcmakes_in_directory directory)
  _mcux_load_all_cmakes_in_directory(${directory} ".cmake")
endfunction()

function(mcux_load_all_cmakelists_in_directory directory)
  _mcux_load_all_cmakes_in_directory(${directory} "cmakelists")
endfunction()

# mcux_load_all_cmakelists_in_directory will load all cmakelists recursively in
# the directory
function(_mcux_load_all_cmakes_in_directory directory cmake_type)
  # initialize stack to store directory
  set(directories ${directory})

  # loop until stack is empty
  while(directories)
    # pop the top directory
    list(GET directories 0 current_directory)
    list(REMOVE_AT directories 0)

    # get the absolute path of the current directory
    get_filename_component(absolute_directory ${current_directory} ABSOLUTE)

    # get all files and subdirectories in the current directory
    file(
      GLOB children
      RELATIVE ${absolute_directory}
      ${absolute_directory}/*)

    foreach(child ${children})
      # if the child is a directory, push it to the stack
      if(IS_DIRECTORY ${absolute_directory}/${child})
        list(APPEND directories ${absolute_directory}/${child})
        # if the child is a CMakeLists.txt file, include it. Note case
        # insensitive.
      else()
        string(TOLOWER "${child}" lowercase_child)
        # For cmakelists.txt
        if((${lowercase_child} STREQUAL "cmakelists.txt")
           AND (${cmake_type} STREQUAL "cmakelists"))
          log_debug("Include CMakeLists.txt from ${absolute_directory}"
                    ${CMAKE_CURRENT_LIST_FILE})
          mcux_add_cmakelists(${absolute_directory})
        elseif(${cmake_type} STREQUAL ".cmake")
          # For CMake
          string(REGEX MATCH ".*\.cmake" matched_str ${lowercase_child})
          if(NOT "${matched_str}" STREQUAL "")
            log_debug("Include ${absolute_directory}/${child}"
                      ${CMAKE_CURRENT_LIST_FILE})
            include(${absolute_directory}/${child})
          endif()
        endif()
      endif()
    endforeach()
  endwhile()
endfunction()

# Parsing sysbuild config with domain prefix. For example, if you set
# -Dfreertos_hello_core_id=cm4 for sub project in cmd, core_id=cm4 will be set
# only for freertos_hello project
function(mcux_load_sysbuild_config)
  get_property(
    sysbuild_variable_names
    TARGET sysbuild_cache
    PROPERTY "SYSBUILD_CACHE:VARIABLES")
  zephyr_get(SYSBUILD_MAIN_APP)
  zephyr_get(SYSBUILD_NAME)

  # Get varaiable from sysbuild config Note: This is not same as zephyr, in
  # zephyr, sysbuild config and  project config are in different scope However,
  # it requires developer to provide individual Kconfig for each project. I
  # think we can use variable from kconfig.sysbuild directly in project
  # CMakeLists.txt
  if(EXISTS ${CMAKE_BINARY_DIR}/../.config)
    file(STRINGS ${CMAKE_BINARY_DIR}/../.config cache_strings)

    foreach(str ${cache_strings})
      string(REGEX MATCH "(^([^=]*))=(.*$)" _match "${str}")
      if(NOT "${_match}" STREQUAL "")
        string(LENGTH "${CMAKE_MATCH_1}=" variable_identifier_length)
        set(CONFIG_NAME ${CMAKE_MATCH_1})
        string(SUBSTRING "${str}" ${variable_identifier_length} -1
                         variable_value)
        if(NOT "${variable_value}" STREQUAL "")
          string(REGEX REPLACE "\"" "" variable_value "${variable_value}")
          set(${CONFIG_NAME}
              ${variable_value}
              PARENT_SCOPE)
          log_debug(
            "${SYSBUILD_NAME} set variable: ${CONFIG_NAME} => {${variable_value}"
          )
        endif()
      endif()
    endforeach()
  endif()

  foreach(name ${sysbuild_variable_names})
    # For main app, all variables are valid, for other apps, only those with
    # prefix is valid
    if(SYSBUILD_MAIN_APP)
      get_property(
        ${name}
        TARGET sysbuild_cache
        PROPERTY ${name})

      set(${name}
          ${${name}}
          PARENT_SCOPE)

      log_debug("${SYSBUILD_NAME} set variable: ${name} => ${${name}}")
    elseif("${name}" MATCHES "^${SYSBUILD_NAME}_")

      string(REGEX REPLACE "^${SYSBUILD_NAME}_" "" org_name ${name})

      get_property(
        ${org_name}
        TARGET sysbuild_cache
        PROPERTY ${name})

      set(${org_name}
          ${${org_name}}
          PARENT_SCOPE)
      log_debug("${SYSBUILD_NAME} set variable: ${org_name} => ${${org_name}}")
    endif()
  endforeach()
endfunction()

function(mcux_append_single_compiler_flags_variable type flag)
  if(${flag} IN_LIST ${CONFIG_TOOLCHAIN}_${type}_IGNORE_LIST)
    return()
  endif()

  if(type STREQUAL "AS")
    set(lang_type "ASM")
  elseif(type STREQUAL "CC")
    set(lang_type "C")
  elseif(type STREQUAL "CX")
    set(lang_type "CXX")
  elseif(type STREQUAL "LD")
    set(lang_type "EXE_LINKER")
  else()
    return()
  endif()

  # Handle macro definition, use the latest one if found duplicated macro with different value
 string(REGEX MATCH "^-D([A-Za-z0-9_\\(\\)]+)=?(.*)?" _match "${flag}")
 if(NOT "${_match}" STREQUAL "")
   if(((NOT CMAKE_MATCH_2) AND (NOT "${CMAKE_MATCH_2}" STREQUAL 0)) OR CMAKE_MATCH_2 STREQUAL "")
     set(MACRO_VALUE "UNDEFINED_MACRO_VALUE")
   else()
     set(MACRO_VALUE ${CMAKE_MATCH_2})
   endif ()
   mcux_get_property(saved_macro_value MCUX_${type}_MACRO_${CMAKE_MATCH_1})
   if(saved_macro_value OR ("${saved_macro_value}" STREQUAL 0))
     log_debug("${type} MACRO ${flag} has duplication definition"
             ${CMAKE_CURRENT_LIST_FILE})
     # use later one to overwrite the first one if found duplicated macro with different value
     if(NOT saved_macro_value STREQUAL MACRO_VALUE)
       if ("${saved_macro_value}" STREQUAL "UNDEFINED_MACRO_VALUE")
         string(REPLACE "-D${CMAKE_MATCH_1}" "${flag}" CMAKE_${lang_type}_FLAGS "${CMAKE_${lang_type}_FLAGS}")
         set(log_value "")
       else()
         string(REPLACE "-D${CMAKE_MATCH_1}=${saved_macro_value}" "${flag}" CMAKE_${lang_type}_FLAGS "${CMAKE_${lang_type}_FLAGS}")
         set(log_value "=${saved_macro_value}")
       endif()
       set(CMAKE_${lang_type}_FLAGS  "${CMAKE_${lang_type}_FLAGS}" CACHE STRING "" FORCE)
       log_notice("Found duplication ${type} macro definition, use ${flag} to override previous -D${CMAKE_MATCH_1}${log_value}"
               ${CMAKE_CURRENT_LIST_FILE})
       # update property with the new value
       mcux_set_property(MCUX_${type}_MACRO_${CMAKE_MATCH_1} ${MACRO_VALUE})
       return()
     elseif(MACRO_VALUE STREQUAL "UNDEFINED_MACRO_VALUE" OR saved_macro_value STREQUAL MACRO_VALUE)
       # for duplicated macro with no value, like -DA -DA, or with same value, like -DC=3 -DC=3,just ignore it
       return()
     endif()
   else()
     mcux_set_property(MCUX_${type}_MACRO_${CMAKE_MATCH_1} ${MACRO_VALUE})
   endif()
 endif()
  set(CMAKE_${lang_type}_FLAGS  "${CMAKE_${lang_type}_FLAGS} ${flag}" CACHE STRING "" FORCE)
endfunction()

#########################
# Macro add/remove function
#########################

# Preprocess macro variable, -D FOO => -DFOO, FOO => -DFOO
macro(_mcux_preprocess_macro origin_macros)
  set(updated_macros)
  STRING(REPLACE " " ";" output_list "${${origin_macros}}")
  foreach(_macro ${output_list})
    string(REGEX MATCH "^-D" is_prefix "${_macro}")
    if (${_macro} STREQUAL "-D")
      continue()
    elseif("${is_prefix}" STREQUAL "-D")
      list(APPEND updated_macros "${_macro}")
    else()
      list(APPEND updated_macros "-D${_macro}")
    endif()
  endforeach()
  list(REMOVE_DUPLICATES updated_macros)
  list(JOIN updated_macros " " _updated_macros)
  set(${origin_macros} ${_updated_macros})
  unset(updated_macros)
endmacro()

function(mcux_add_macro)
  set(single_value AS CC CX)
  set(multi_value TARGETS TOOLCHAINS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
          ${ARGN})

  set(param_list "CC" "CX" "AS" "TARGETS" "TOOLCHAINS")
  list(LENGTH ARGN arg_length)
  if(NOT ${arg_length} EQUAL 0)
    if(${arg_length}  GREATER 1)
      list(GET ARGN 0 first_element)
      # if the first element is params, should not be reagrded as macro
      if(NOT first_element IN_LIST param_list)
        string(JOIN " " macros "${ARGN}")
      endif()
    else()
      set(macros "${ARGN}")
    endif()
  endif()

  set(match_target false)
  if(__TARGETS)
    foreach(item ${__TARGETS})
      if(${item} STREQUAL ${CMAKE_BUILD_TYPE})
        set(match_target true)
      endif()
    endforeach()
  else()
    set(match_target true)
  endif()

  if(NOT ${match_target})
    return()
  endif()

  set(match_toolchain false)
  if(__TOOLCHAINS)
    foreach(tool ${__TOOLCHAINS})
      if(${CONFIG_TOOLCHAIN} STREQUAL ${tool})
        set(match_toolchain true)
        break()
      endif()
    endforeach()
  else ()
    set(match_toolchain true)
  endif()
  if(NOT ${match_toolchain})
    return()
  endif()

  if(__AS)
    _mcux_preprocess_macro(__AS)
    _mcux_add_configuration(AS ${__AS})
  endif()
  if(__CC)
    _mcux_preprocess_macro(__CC)
    _mcux_add_configuration(CC ${__CC})
  endif()
  if(__CX)
    _mcux_preprocess_macro(__CX)
    _mcux_add_configuration(CX ${__CX})
  endif()

  if(macros)
    _mcux_preprocess_macro(macros)
    _mcux_add_configuration(AS ${macros})
    _mcux_add_configuration(CC ${macros})
    _mcux_add_configuration(CX ${macros})
  endif()
endfunction()

function(mcux_remove_macro)
  set(single_value AS CC CX)
  set(multi_value TARGETS TOOLCHAINS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
          ${ARGN})

  set(param_list "CC" "CX" "AS" "TARGETS" "TOOLCHAINS")
  list(LENGTH ARGN arg_length)
  if(NOT ${arg_length} EQUAL 0)
    if(${arg_length}  GREATER 1)
      list(GET ARGN 0 first_element)
      if(NOT first_element IN_LIST param_list)
        string(JOIN " " macros "${ARGN}")
      endif()
    else()
      set(macros "${ARGN}")
    endif()
  endif()

  set(match_target false)
  if(__TARGETS)
    foreach(item ${__TARGETS})
      if(${item} STREQUAL ${CMAKE_BUILD_TYPE})
        set(match_target true)
      endif()
    endforeach()
  else()
    set(match_target true)
  endif()

  if(NOT ${match_target})
    return()
  endif()

  set(match_toolchain false)
  if(__TOOLCHAINS)
    foreach(tool ${__TOOLCHAINS})
      if(${CONFIG_TOOLCHAIN} STREQUAL ${tool})
        set(match_toolchain true)
        break()
      endif()
    endforeach()
  else ()
    set(match_toolchain true)
  endif()
  if(NOT ${match_toolchain})
    return()
  endif()

  if(__AS)
    _mcux_preprocess_macro(__AS)
    _mcux_remove_configuration(AS ${__AS})
  endif()
  if(__CC)
    _mcux_preprocess_macro(__CC)
    _mcux_remove_configuration(CC ${__CC})
  endif()
  if(__CX)
    _mcux_preprocess_macro(__CX)
    _mcux_remove_configuration(CX ${__CX})
  endif()

  if(macros)
    _mcux_preprocess_macro(macros)
    _mcux_remove_configuration(AS ${macros})
    _mcux_remove_configuration(CC ${macros})
    _mcux_remove_configuration(CX ${macros})
  endif()
endfunction()

#############################
# Library add/remove function
#############################
function(mcux_add_library)
  set(single_value BASE_PATH SCOPE EXCLUDE HIDDEN GENERATED)
  set(multi_value LIBS ${MCUX_SOURCE_CONDITION} TARGETS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
          ${ARGN})

  # The default scope for library is private
  if(__SCOPE)
    set(lib_scope ${__SCOPE})
    if(NOT "PRIVATE PUBLIC INTERFACE" MATCHES ${__SCOPE})
      log_fatal("${CMAKE_CURRENT_LIST_FILE}: Error while adding ${__LIBS}, SCOPE ${__SCOPE} is invalid, it should be PRIVATE, PUBLIC or INTERFACE")
    endif ()
  else()
    set(lib_scope PRIVATE)
  endif()
  # judge condition
  set(match_target false)
  if(__TARGETS)
    foreach(item ${__TARGETS})
      if(${item} STREQUAL ${CMAKE_BUILD_TYPE})
        set(match_target true)
      endif()
    endforeach()
  else()
    set(match_target true)
  endif()

  if (NOT ${match_target})
    return()
  endif()

  foreach(cond ${MCUX_SOURCE_CONDITION})
    if(__${cond})

      list(FIND MCUX_SOURCE_CONDITION ${cond} INDEX)

      if(${INDEX} GREATER -1)

        list(GET CMAKE_CONDITION ${INDEX} _cmake_cond)

        if(_cmake_cond IN_LIST LIST_CMAKE_CONDITION)
          set(condition_meet 0)
          foreach(cmake_condition_item ${${_cmake_cond}})
            if(cmake_condition_item IN_LIST __${cond})
              set(condition_meet 1)
            endif()
          endforeach()
          if(NOT condition_meet)
            return()
          endif()
        elseif(NOT ${${_cmake_cond}} IN_LIST __${cond})
          return()
        endif()
      endif()
    endif()
  endforeach()
  # handle wildcard
  set(files "")
  foreach(item ${__LIBS})
    if(__BASE_PATH)
      set(lib_abs_path ${__BASE_PATH}/${item})
    else()
      set(lib_abs_path ${CMAKE_CURRENT_LIST_DIR}/${item})
    endif()
    # get the file name from lib_abs_path
    get_filename_component(file ${lib_abs_path} NAME)
    # get directory from lib_abs_path
    get_filename_component(directory ${lib_abs_path} DIRECTORY)
    # check if the file_name follow the pattern *.* and **
    string(REGEX MATCH "\\*\\..*" match "${file}")
    if (match)
      file(GLOB tmp_files "${directory}/${file}")
      list(APPEND files "${tmp_files}")
    else ()
      # add source_abs_path to list file
      list(APPEND files "${lib_abs_path}")
    endif ()
  endforeach()
  list(LENGTH files file_length)
  if(NOT ${file_length}  GREATER 0)
    log_error("No library found, please check parameter LIBS: ${__LIBS}" ${CMAKE_CURRENT_LIST_FILE})
    return()
  endif()
  # transfer to cmake path
  set(all_libs)
  foreach(item ${files})
    file(TO_CMAKE_PATH ${item} lib_cmake_path)
    get_filename_component(lib_cmake_path ${lib_cmake_path} ABSOLUTE)
    list(APPEND all_libs ${lib_cmake_path})
  endforeach()

  _mcux_set_libs(SCOPE ${lib_scope} LIBS ${all_libs})
  # handle removed libraries
  foreach(item ${files})
    mcux_get_property(REMOVE_LIBS TO_BE_REMOVED_LIBS)
    # get MCUX_SDK_PROJECT_NAME libs
    get_property(
            LIB_FILES
            TARGET ${MCUX_SDK_PROJECT_NAME}
            PROPERTY LINK_LIBRARIES)
    # remove all libs in remove list from LIB_FILES
    foreach(lib ${REMOVE_LIBS})
      list(FIND LIB_FILES ${lib} INDEX)
      if(${INDEX} GREATER -1)
        list(REMOVE_ITEM LIB_FILES ${lib})
        # remove the source from remove sources, project shall not have
        # duplicated sources
        list(REMOVE_ITEM REMOVE_LIBS ${lib})
        set_property(TARGET ${MCUX_SDK_PROJECT_NAME} PROPERTY LINK_LIBRARIES
                ${LIB_FILES})
        log_debug(
                "Remove lib ${lib} from project because it is in the TO_BE_REMOVED_LIBS list"
        )
      endif()
    endforeach()

    # update TO_BE_REMOVED_LIBS
    if(REMOVE_LIBS)
      mcux_set_property(TO_BE_REMOVED_LIBS ${REMOVE_LIBS})
    else()
      mcux_clear_property(TO_BE_REMOVED_LIBS)
    endif()

  endforeach()
endfunction()

function(_mcux_set_libs)
  set(single_value SCOPE)
  set(multi_value LIBS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
          ${ARGN})
  set(NEED_WRAP_TOOLCHAINS "armgcc" "xtensa")
  get_property(
          LIB_FILES
          TARGET ${MCUX_SDK_PROJECT_NAME}
          PROPERTY LINK_LIBRARIES)

  foreach(item ${LIB_FILES})
    string(REGEX MATCH "::@.*|-Wl,--start-group|-Wl,--end-group" match "${item}")
    if (match)
     continue()
    else ()
      list(APPEND already_added_libs ${item})
    endif ()
  endforeach()
  # add new libs to already_added_libs
  list(APPEND already_added_libs ${__LIBS})
  # reset link libraries
  set_property(TARGET ${MCUX_SDK_PROJECT_NAME} PROPERTY LINK_LIBRARIES "")
  if(${CONFIG_TOOLCHAIN} IN_LIST NEED_WRAP_TOOLCHAINS)
    target_link_libraries(${MCUX_SDK_PROJECT_NAME} ${__SCOPE} -Wl,--start-group)
  endif()
  target_link_libraries(${MCUX_SDK_PROJECT_NAME} ${__SCOPE} ${already_added_libs})
  if(${CONFIG_TOOLCHAIN} IN_LIST NEED_WRAP_TOOLCHAINS)
    target_link_libraries(${MCUX_SDK_PROJECT_NAME} ${__SCOPE} -Wl,--end-group)
  endif()
endfunction()

function(mcux_remove_library)
  set(single_value BASE_PATH)
  set(multi_value LIBS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
          ${ARGN})
  # remove sources
  foreach(item ${__LIBS})
    if(__BASE_PATH)
      set(lib_abs_path ${__BASE_PATH}/${item})
    else()
      set(lib_abs_path ${CMAKE_CURRENT_LIST_DIR}/${item})
    endif()

    file(TO_CMAKE_PATH ${lib_abs_path} lib_abs_path)
    get_filename_component(lib_abs_path ${lib_abs_path} ABSOLUTE)

    get_property(
            LIB_FILES
            TARGET ${MCUX_SDK_PROJECT_NAME}
            PROPERTY LINK_LIBRARIES)

    # if source_abs_path is in SOURCE_FILES, remove it from SOURCE_FILES
    list(FIND LIB_FILES ${lib_abs_path} index)
    if(${index} GREATER -1)
      list(REMOVE_ITEM LIB_FILES ${lib_abs_path})
      set_property(TARGET ${MCUX_SDK_PROJECT_NAME} PROPERTY LINK_LIBRARIES
              ${LIB_FILES})
      log_debug("Remove lib ${lib_abs_path}" ${CMAKE_CURRENT_LIST_FILE})
    else()
      # put lib_abs_path into TO_BE_REMOVED_LIBS target
      mcux_set_property(TO_BE_REMOVED_LIBS ${lib_abs_path} APPEND)
      log_debug(
              "Add lib ${lib_abs_path} into TO_BE_REMOVED_LIBS which means this lib will not been added into project"
              ${CMAKE_CURRENT_LIST_FILE})
    endif()

  endforeach()
endfunction()

##############################
# PRE/POST build function
##############################
# Note:
# 1.For Ninja and Make generator, the PRE_BUILD behaves the same as PRE_LINK
# 2.The default behavior is POST_BUILD if no BUILD_EVENT set
function(mcux_add_custom_command)
  set(single_value BUILD_EVENT WORKING_DIRECTORY)
  set(multi_value TARGETS TOOLCHAINS BYPRODUCTS BUILD_COMMAND)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
          ${ARGN})
  set(match_target false)
  if(__TARGETS)
    foreach(item ${__TARGETS})
      if(${item} STREQUAL ${CMAKE_BUILD_TYPE})
        set(match_target true)
      endif()
    endforeach()
  else()
    set(match_target true)
  endif()

  if(NOT ${match_target})
    return()
  endif()

  set(match_toolchain false)
  if(__TOOLCHAINS)
    foreach(tool ${__TOOLCHAINS})
      if(${CONFIG_TOOLCHAIN} STREQUAL ${tool})
        set(match_toolchain true)
        break()
      endif()
    endforeach()
  else ()
    set(match_toolchain true)
  endif()
  if(NOT ${match_toolchain})
    return()
  endif()

  if(__BUILD_EVENT)
    set(EVENT ${__BUILD_EVENT})
  else()
    set(EVENT POST_BUILD})
  endif()

  if(__BUILD_COMMAND)
    if(${EVENT} STREQUAL "PRE_COMPILE")
      # set a target name which is specific to this command
      string(REPLACE ";" " " build_cmd_str "${__BUILD_COMMAND}")
      string(MD5 MD5_HASH ${build_cmd_str})
      set(custom_target PRE_COMPILE_CMD_TARGET_${MD5_HASH})
      # create a custom target to execute the command
      add_custom_target(${custom_target} BYPRODUCTS ${__BYPRODUCTS}
              COMMAND ${__BUILD_COMMAND}
              COMMENT "Pre-compile command: ${build_cmd_str}"
              WORKING_DIRECTORY ${__WORKING_DIRECTORY})
      # make sure the command execute before ${MCUX_SDK_PROJECT_NAME} is built
      add_dependencies(${MCUX_SDK_PROJECT_NAME} ${custom_target})
      log_debug(
              "Add ${EVENT} custom command: ${__BUILD_COMMAND}"
              ${CMAKE_CURRENT_LIST_FILE})
    else()
      add_custom_command(
              TARGET ${MCUX_SDK_PROJECT_NAME}
              ${EVENT}
              COMMAND ${__BUILD_COMMAND}
              WORKING_DIRECTORY ${__WORKING_DIRECTORY}
      )
      log_debug(
              "Add ${EVENT} custom command: ${__BUILD_COMMAND}"
              ${CMAKE_CURRENT_LIST_FILE})
    endif()
  endif()
endfunction()

##############################
# Add/remove linker symbol function
##############################
function(mcux_add_linker_symbol)
  set(multi_value TARGETS SYMBOLS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
          ${ARGN})
  set(match_target false)
  if(__TARGETS)
    foreach(item ${__TARGETS})
      if(${item} STREQUAL ${CMAKE_BUILD_TYPE})
        set(match_target true)
      endif()
    endforeach()
  else()
    set(match_target true)
  endif()

  if(NOT ${match_target})
    return()
  endif()

  if(__SYMBOLS)
    string(REPLACE " " ";" __SYMBOLS "${__SYMBOLS}")
    foreach(item ${__SYMBOLS})
      if(${CONFIG_TOOLCHAIN} STREQUAL "iar")
        set(ld_flag "--config_def=${item}")
      elseif(${CONFIG_TOOLCHAIN} STREQUAL "armgcc")
        set(ld_flag "-Xlinker --defsym=${item}")
      elseif(${CONFIG_TOOLCHAIN} STREQUAL "zephyr")
        set(ld_flag "-Xlinker --defsym=${item}")
      elseif(${CONFIG_TOOLCHAIN} STREQUAL "mdk")
        set(ld_flag "--predefine=\"-D${item}\"")
      else()
        log_fatal("mcux_add_linker_symbol: Error while adding ${item}, unknown toolchain: ${CONFIG_TOOLCHAIN}")
      endif()
      _mcux_add_configuration(LD ${ld_flag})
    endforeach()
  endif ()
endfunction()

function(mcux_remove_linker_symbol)
  set(single_value SYMBOLS)
  set(multi_value TARGETS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
          ${ARGN})
  set(match_target false)
  if(__TARGETS)
    foreach(item ${__TARGETS})
      if(${item} STREQUAL ${CMAKE_BUILD_TYPE})
        set(match_target true)
      endif()
    endforeach()
  else()
    set(match_target true)
  endif()

  if(NOT ${match_target})
    return()
  endif()

  if(__SYMBOLS)
    string(REPLACE " " ";" __SYMBOLS "${__SYMBOLS}")
    foreach(item ${__SYMBOLS})
      if(${CONFIG_TOOLCHAIN} STREQUAL "iar")
        set(ld_flag "--config_def=${item}")
      elseif(${CONFIG_TOOLCHAIN} STREQUAL "armgcc")
        set(ld_flag "-Xlinker --defsym=${item}")
      elseif(${CONFIG_TOOLCHAIN} STREQUAL "zephyr")
        set(ld_flag "-Xlinker --defsym=${item}")
      elseif(${CONFIG_TOOLCHAIN} STREQUAL "mdk")
        set(ld_flag "--predefine=\"-D${item}\"")
      else()
        log_fatal("mcux_add_linker_symbol: Error while removing ${item}, unknown toolchain: ${CONFIG_TOOLCHAIN}")
      endif()
      _mcux_remove_configuration(LD ${ld_flag})
    endforeach()
  endif ()
endfunction()

function(remove_defined_linker)
  if(${CONFIG_TOOLCHAIN} STREQUAL "iar")
    set(ld_pattern "--config .+\\.icf")
  elseif(${CONFIG_TOOLCHAIN} STREQUAL "armgcc")
    set(ld_pattern "-T .+\\.ld")
  elseif(${CONFIG_TOOLCHAIN} STREQUAL "mdk")
    set(ld_pattern "--scatter .+\\.ld")
  endif()

  set(linker_flag_str ${CMAKE_EXE_LINKER_FLAGS})

  string(REGEX MATCH "${ld_pattern}" match "${linker_flag_str}")
  if (match)
    string(REGEX REPLACE ${match} "" linker_flag_str ${linker_flag_str})
    set(CMAKE_EXE_LINKER_FLAGS  "${linker_flag_str}" CACHE STRING "" FORCE)
    log_debug("Remove linker flag ${match}" ${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE})
  else ()
    log_warn("Linker flag is not found" ${CMAKE_CURRENT_LIST_FILE} ${CMAKE_CURRENT_LIST_LINE})
  endif ()
endfunction()

# Usage:
#   mcux_string(<mode> <out-var> <input> ...)
#
# Mcux string function extension.
# This function extends the CMake string function by providing additional
# manipulation arguments to CMake string.
#
# SANITIZE: Ensure that the output string does not contain any special
#           characters. Special characters, such as -, +, =, $, etc. are
#           converted to underscores '_'.
#
# SANITIZE TOUPPER: Ensure that the output string does not contain any special
#                   characters. Special characters, such as -, +, =, $, etc. are
#                   converted to underscores '_'.
#                   The sanitized string will be returned in UPPER case.
#
# returns the updated string
function(mcux_string)
  set(options SANITIZE TOUPPER)
  cmake_parse_arguments(MCUX_STRING "${options}" "" "" ${ARGN})

  if (NOT MCUX_STRING_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Function mcux_string() called without a return variable")
  endif()

  list(GET MCUX_STRING_UNPARSED_ARGUMENTS 0 return_arg)
  list(REMOVE_AT MCUX_STRING_UNPARSED_ARGUMENTS 0)

  list(JOIN MCUX_STRING_UNPARSED_ARGUMENTS "" work_string)

  if(MCUX_STRING_SANITIZE)
    string(REGEX REPLACE "[^a-zA-Z0-9_]" "_" work_string ${work_string})
  endif()

  if(MCUX_STRING_TOUPPER)
    string(TOUPPER ${work_string} work_string)
  endif()

  set(${return_arg} ${work_string} PARENT_SCOPE)
endfunction()

# This function do nothing, it just to tell sdk generator the component's version
function(mcux_component_version)
endfunction()

# wrap linked libraries with -Wl,--start-group and -Wl,--end-group to prevent build issue
# caused by linker order
function(reset_app_link_order)
  set(multi_value LIBS)
  cmake_parse_arguments(_ "${options}" "${single_value}" "${multi_value}"
          ${ARGN})
  set(NEED_WRAP_TOOLCHAINS "armgcc" "xtensa")

  get_property(
          SDK_LIB_FILES
          TARGET McuxSDK
          PROPERTY LINK_LIBRARIES)
  if(__LIBS)
    list(APPEND SDK_LIB_FILES ${__LIBS})
  endif()
  list(APPEND already_added_libs "McuxSDK")
  foreach(item ${SDK_LIB_FILES})
    string(REGEX MATCH "::@.*|-Wl,--start-group|-Wl,--end-group" match "${item}")
    if (match)
      continue()
    else ()
      list(APPEND already_added_libs ${item})
    endif ()
  endforeach()
  list(REMOVE_DUPLICATES already_added_libs)
  # clear link libraries before reordering
  set_property(TARGET app PROPERTY LINK_LIBRARIES "")
  # reset link libraries
  if(${CONFIG_TOOLCHAIN} IN_LIST NEED_WRAP_TOOLCHAINS)
    target_link_libraries(app PRIVATE -Wl,--start-group)
  endif()
  target_link_libraries(app PRIVATE ${already_added_libs})

  if(${CONFIG_TOOLCHAIN} IN_LIST NEED_WRAP_TOOLCHAINS)
    target_link_libraries(app PRIVATE -Wl,--end-group)
  endif()

  # Workaround:
  # Without the statement below, there are two errors:
  # missing --end-group
  # undefined reference to `_exit'
  if(${CONFIG_TOOLCHAIN} STREQUAL "armgcc")
    target_link_libraries(app PRIVATE -Wl,--start-group)
    target_link_libraries(app PRIVATE "-lm")
    target_link_libraries(app PRIVATE "-lc")
    target_link_libraries(app PRIVATE "-lgcc")
    target_link_libraries(app PRIVATE "-lnosys")
    target_link_libraries(app PRIVATE -Wl,--end-group)
  endif()
endfunction()

# Usage
#   _get_subfolder_file(<output-var> <directory> <pattern> <level>)
#
# get designated file path from subfolder with designed deepth level
function(_get_subfolder_file OUTPUT_VAR CURRENT_DIR PATTERN LEVEL)
  set(current_level 1) 
  set(dir_queue "${CURRENT_DIR}")

  while( dir_queue AND (${current_level} LESS_EQUAL ${LEVEL}))
    list(LENGTH dir_queue queue_length)

    math(EXPR end_index "${queue_length} - 1")
    foreach(index RANGE ${end_index})
      list(GET dir_queue ${index} dir)
      file(GLOB children RELATIVE "${dir}" "${dir}/*/")

      foreach(child ${children})
        if(IS_DIRECTORY "${dir}/${child}")
          list(APPEND dir_queue "${dir}/${child}")
        endif ()
      endforeach()

    endforeach()

    math(EXPR end_index "${queue_length} - 1")
    foreach(index RANGE ${end_index})
      list(REMOVE_AT dir_queue 0)
    endforeach ()


    math(EXPR current_level "${current_level} + 1")
  endwhile()

  foreach (dir ${dir_queue})
    if(EXISTS ${dir}/${PATTERN})
      set(${OUTPUT_VAR} ${dir}/${PATTERN} PARENT_SCOPE)
      break()
    endif ()
  endforeach ()

endfunction()