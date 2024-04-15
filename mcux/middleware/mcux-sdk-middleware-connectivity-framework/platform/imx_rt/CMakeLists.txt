list(APPEND SOURCES
    fwk_platform_hdlc.c
    fwk_platform_ot.c
    configs/fwk_lfs_config.c
)

list(APPEND LINK_LIBRARIES)
list(APPEND COMPILE_PRIVATE_DEFINITIONS)

##Check if the k32w0 transceiver is enabled
string(FIND ${CONNFWK_TRANSCEIVER} "k32w0" outString)
if (${outString} GREATER_EQUAL 0)
   if (NOT CONNFWK_OTW)
       message(FATAL_ERROR "CONNFWK_OTW must be set to ON when k32w0 transceiver is supported")
   endif()
   if (CONNFWK_TRANSCEIVER_BIN_PATH)
       get_filename_component(CONNFWK_TRANSCEIVER_BIN_PATH "${CONNFWK_TRANSCEIVER_BIN_PATH}" ABSOLUTE)
       list(APPEND COMPILE_PRIVATE_DEFINITIONS
           -DK32W0_RCP_BINARY_H_FILE="${CONNFWK_TRANSCEIVER_BIN_PATH}"
       )
   else ()
       message(FATAL_ERROR "CONNFWK_TRANSCEIVER_BIN_PATH option missing. Example -DCONNFWK_TRANSCEIVER_BIN_PATH=~/Desktop/imx_rt/ot-nxp/build_k32w061/rcp_only_uart_flow_control/bin/ot-rcp.elf.bin.h")
   endif()
   list(APPEND LINK_LIBRARIES
       connfwk-OTW
   )
endif()

#Build the correct coex files depending of the transceiver chosen

if(${CONNFWK_TRANSCEIVER} STREQUAL "")
else()
if(${CONNFWK_TRANSCEIVER} STREQUAL "k32w0")
    list(APPEND SOURCES
        k32w0/fwk_platform_coex.c
    )
elseif(${CONNFWK_TRANSCEIVER} STREQUAL "iwx12")
    list(APPEND SOURCES
        iw612/fwk_platform_coex.c
    )
endif()

add_library(connfwk-platform-${CONNFWK_PLATFORM_FAMILY} ${SOURCES})

# Making those includes PUBLIC will share them to the other targets linking this lib
target_include_directories(connfwk-platform-${CONNFWK_PLATFORM_FAMILY}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_SOURCE_DIR}
        configs
)

target_compile_definitions(connfwk-platform-${CONNFWK_PLATFORM_FAMILY} PRIVATE ${COMPILE_PRIVATE_DEFINITIONS})

# Get common configs from the connfwk-config interface
target_link_libraries(connfwk-platform-${CONNFWK_PLATFORM_FAMILY}
    PRIVATE
        connfwk-config
        ${LINK_LIBRARIES}
        ${CONNFWK_MCUX_SDK_LIB}
)

#Some framework config files are required by SDK component: example littlefs
target_link_libraries(connfwk-config INTERFACE connfwk-platform-${CONNFWK_PLATFORM_FAMILY})
endif()
