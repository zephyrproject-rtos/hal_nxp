/** @file sigma_agent.h
 *
 *  @brief  This file provides the support for Sigma Agent utility for Wi-F
 *          certification.
 */
/*
 *  Copyright 2023-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _SIGMA_AGENT_H_
#define _SIGMA_AGENT_H_

#include <wmlog.h>

#define sigma_e(...) wmlog_e("iperf", ##__VA_ARGS__)
#define sigma_w(...) wmlog_w("iperf", ##__VA_ARGS__)

/** Register the Network Utility CLI command iperf.
 *
 *  \note This function can only be called by the application after \ref
 *  wlan_init() called.
 *
 *  \return WM_SUCCESS if the CLI commands are registered
 *  \return -WM_FAIL otherwise (for example if this function
 *          was called while the CLI commands were already registered)
 */
int sigma_agent_init(void);

/** Unregister Network Utility CLI command iperf.
 *
 *  \return WM_SUCCESS if the CLI commands are unregistered
 *  \return -WM_FAIL otherwise
 */
int sigma_agent_deinit(void);

#endif /*_SIGMA_AGENT_H_ */
