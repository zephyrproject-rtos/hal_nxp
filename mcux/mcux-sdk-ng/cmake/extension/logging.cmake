# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
include_guard(GLOBAL)
set(LOG_LEVEL "INFO")

# log level mapping
# log     message
#   status STATUS
#   debug  DEBUG
#   warn   WARNING
#   error  SEND_ERROR
#   fatal  FATAL_ERROR
#   trace  TRACE
#   notice NOTICE
list(APPEND SUPPORTED_WRAPPED_LOG_LEVELS "STATUS" "DEBUG" "WARN" "ERROR" "FATAL" "TRACE" "NOTICE")

function(log_debug message_text)
    if (ARGC EQUAL 3)
        message(DEBUG "DEBUG: ${message_text}, load from CMakefile: ${ARGV1}, line: ${ARGV2}")
    elseif(ARGC EQUAL 2)
        message(DEBUG "DEBUG: ${message_text}, load from CMakefile: ${ARGV1}")
    elseif(ARGC EQUAL 1)
        message(DEBUG "DEBUG: ${message_text}")
    else ()
        message(SEND_ERROR "Wrong number of arguments in log_debug")
    endif()
endfunction()

function(log_status message_text)
    if (ARGC EQUAL 3)
        message(STATUS "${message_text}, load from CMakefile: ${ARGV1}, line: ${ARGV2}")
    elseif(ARGC EQUAL 2)
        message(STATUS "${message_text}, load from CMakefile: ${ARGV1}")
    elseif(ARGC EQUAL 1)
        message(STATUS "${message_text}")
    else ()
        message(SEND_ERROR "Wrong number of arguments in log_status")
    endif()
endfunction()

function(log_warn message_text)
    if (ARGC EQUAL 3)
        message(WARNING "WARNING: ${message_text}, load from CMakefile: ${ARGV1}, line: ${ARGV2}")
    elseif(ARGC EQUAL 2)
        message(WARNING "WARNING: ${message_text}, load from CMakefile: ${ARGV1}")
    elseif(ARGC EQUAL 1)
        message(WARNING "WARNING: ${message_text}")
    else ()
        message(SEND_ERROR "Wrong number of arguments in log_warn")
    endif()
endfunction()

function(log_error message_text)
    if (ARGC EQUAL 3)
        message(SEND_ERROR "ERROR: ${message_text}, load from CMakefile: ${ARGV1}, line: ${ARGV2}")
    elseif(ARGC EQUAL 2)
        message(SEND_ERROR "ERROR: ${message_text}, load from CMakefile: ${ARGV1}")
    elseif(ARGC EQUAL 1)
        message(SEND_ERROR "ERROR: ${message_text}")
    else ()
        message(SEND_ERROR "Wrong number of arguments in log_error")
    endif()
endfunction()

function(log_fatal message_text)
    if (ARGC EQUAL 3)
        message(FATAL_ERROR "FATAL_ERROR: ${message_text}, load from CMakefile: ${ARGV1}, line: ${ARGV2}")
    elseif(ARGC EQUAL 2)
        message(FATAL_ERROR "FATAL_ERROR: ${message_text}, load from CMakefile: ${ARGV1}")
    elseif(ARGC EQUAL 1)
        message(FATAL_ERROR "FATAL_ERROR: ${message_text}")
    else ()
        message(SEND_ERROR "Wrong number of arguments in log_fatal")
    endif()
endfunction()

function(log_trace message_text)
    if (ARGC EQUAL 3)
        message(TRACE "TRACE: ${message_text}, load from CMakefile: ${ARGV1}, line: ${ARGV2}")
    elseif(ARGC EQUAL 2)
        message(TRACE "TRACE: ${message_text}, load from CMakefile: ${ARGV1}")
    elseif(ARGC EQUAL 1)
        message(TRACE "TRACE: ${message_text}")
    else ()
        message(SEND_ERROR "Wrong number of arguments in log_trace")
    endif()
endfunction()

function(log_notice message_text)
    if (ARGC EQUAL 3)
        message(NOTICE "NOTICE: ${message_text}, load from CMakefile: ${ARGV1}, line: ${ARGV2}")
    elseif(ARGC EQUAL 2)
        message(NOTICE "NOTICE: ${message_text}, load from CMakefile: ${ARGV1}")
    elseif(ARGC EQUAL 1)
        message(NOTICE "NOTICE: ${message_text}")
    else ()
        message(SEND_ERROR "Wrong number of arguments in log_notice")
    endif()
endfunction()
