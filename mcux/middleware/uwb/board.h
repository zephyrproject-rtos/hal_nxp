/*
 * Copyright 2026 NXP
 * SPDX-License-Identifier: Apache-2.0
 */

/** This file is to enable se_mw code to be built on zephyr
 *  All undefined references which need to be updated in se_mw
 *  can be added here as dummy implementation
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include "uwb_nxp_host.h"
#include "cmsis_gcc.h"
#if !defined(__ZEPHYR__)
#include <fsl_common.h>
#include <fsl_gpio.h>
#include <clock_config.h>
#endif /** __ZEPHYR__ */

#if defined(__ZEPHYR__)
#define sm_sleep k_msleep
#endif

#endif /* _BOARD_H_ */
