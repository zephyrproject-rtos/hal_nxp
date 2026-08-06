/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FWK_CONFIG_ZEPHYR_H_
#define FWK_CONFIG_ZEPHYR_H_

/*
 * Zephyr-specific framework configuration overrides.
 *
 * This file is included at the top of fwk_config.h under an #ifdef __ZEPHYR__
 * guard, so it is compiled only for Zephyr builds. Because every flag in
 * fwk_config.h is #ifndef-protected, any value defined here takes precedence
 * over the default MCUXpresso SDK value.
 *
 * These overrides used to be maintained on the Zephyr side, in
 * modules/hal_nxp/mcux/mcux-sdk-ng/middleware/connectivity_framework.cmake.
 * They are centralized here to avoid dual maintenance between the framework
 * and the Zephyr integration.
 */

/* On Zephyr the ICS RX processing does not use the framework system workqueue */
#ifndef gPlatformIcsUseWorkqueueRxProcessing_d
#define gPlatformIcsUseWorkqueueRxProcessing_d 0
#endif

/* On Zephyr the Timer Manager is not used; Zephyr provides its own timer services */
#ifndef gPlatformUseTimerManager_d
#define gPlatformUseTimerManager_d 0
#endif

/* On Zephyr the framework HW parameter storage is not used */
#ifndef gPlatformUseHwParameter_d
#define gPlatformUseHwParameter_d 0
#endif

/* On Zephyr the NBU GPIO PORT D debug access is not enabled by the framework */
#ifndef gPlatformNbuDebugGpioDAccessEnabled_d
#define gPlatformNbuDebugGpioDAccessEnabled_d 0
#endif

/* On Zephyr the SFC config is not sent to the NBU at init by the framework */
#ifndef gPlatformSetSfcConfigAtInit_d
#define gPlatformSetSfcConfigAtInit_d 0
#endif

/* On Zephyr the wake up delay is not sent to the NBU at init by the framework */
#ifndef gPlatformSetWakeUpDelayAtInit_d
#define gPlatformSetWakeUpDelayAtInit_d 0
#endif

#endif /* FWK_CONFIG_ZEPHYR_H_ */
