/** @file  includes.h
 * @brief This file contains definition for include files
 *
 * Copyright 2003-2020 NXP
 */

#ifndef INCLUDES_H
#define INCLUDES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#ifdef __linux__
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif /* __linux__ */

#include <wm_os.h>

#include "../wmcrypto_mem.h"
#include "type_def.h"
#include "common.h"
//#include "wmstdio.h"

#ifdef DBG_PRINT_FUNC
/** ENTER */
#define ENTER() wmprintf("Enter: %s, %s:%i\r\n", __FUNCTION__, __FILE__, __LINE__)
/** LEAVE */
#define LEAVE() wmprintf("Leave: %s, %s:%i\r\n", __FUNCTION__, __FILE__, __LINE__)
#else
/** ENTER */
#define ENTER()
/** LEAVE */
#define LEAVE()
#endif

#endif /* INCLUDES_H */
