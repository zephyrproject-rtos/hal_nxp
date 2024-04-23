/*
 *  Copyright 2008-2023 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*! \file wlan_11d.h
 * \brief WLAN module 11d API
 */

#ifndef __WLAN_11D_H__
#define __WLAN_11D_H__

#include <wifi.h>

/** Enable 11D support in WLAN Driver.
 *
 * \note This API should be called after WLAN is initialized
 * but before starting uAP or making any connection attempts on station
 * interface.
 *
 * \param[in] state 1: enable, 0: disable
 *
 * \return -WM_FAIL if operation was failed.
 * \return WM_SUCCESS if operation was successful.
 */
static inline int wlan_enable_11d(int state)
{
    if (state)
        return wifi_enable_11d_support();
    else
        return wifi_disable_11d_support();
}

/** Enable 11D support in WLAN Driver for uap interface.
 *
 * \note This API should be called after WLAN is initialized
 * but before starting uAP or making any connection attempts on station
 * interface.
 *
 * \param[in] state 1: enable, 0: disable
 *
 * \return -WM_FAIL if operation was failed.
 * \return WM_SUCCESS if operation was successful.
 */
static inline int wlan_enable_uap_11d(int state)
{
    if (state)
        return wifi_enable_uap_11d_support();
    else
        return wifi_disable_uap_11d_support();
}

#endif /* __WLAN_11D_H__ */
