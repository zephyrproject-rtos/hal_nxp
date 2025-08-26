/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2024, 2025 NXP                    */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

#include "fwk_platform_coex.h"
#include "fsl_loader.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */
#ifndef gPlatformMonolithicApp_d
#define gPlatformMonolithicApp_d 0
#endif

#if (defined gPlatformMonolithicApp_d && (gPlatformMonolithicApp_d != 0))
#define WIFI_LD_TARGET LOAD_WIFI_FIRMWARE
#ifndef WIFI_FW_ADDRESS
extern const uint32_t fw_cpu1[];
#define WIFI_FW_ADDRESS ((uint32_t)&fw_cpu1[0])
#endif
#define BLE_LD_TARGET LOAD_BLE_FIRMWARE
#ifndef BLE_FW_ADDRESS
extern const uint32_t fw_cpu2_ble[];
#define BLE_FW_ADDRESS ((uint32_t)&fw_cpu2_ble[0])
#endif
#define COMBO_LD_TARGET LOAD_15D4_FIRMWARE
#ifndef COMBO_FW_ADDRESS
extern const uint32_t fw_cpu2_combo[];
#define COMBO_FW_ADDRESS ((uint32_t)&fw_cpu2_combo[0])
#endif
#else
#define WIFI_FW_ADDRESS  0U
#define WIFI_LD_TARGET   LOAD_WIFI_FIRMWARE
#define BLE_FW_ADDRESS   0U
#define BLE_LD_TARGET    LOAD_BLE_FIRMWARE
#define COMBO_FW_ADDRESS 0U
#define COMBO_LD_TARGET  LOAD_15D4_FIRMWARE
#endif

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static uint8_t runningControllers = 0U;

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitControllers(uint8_t controllersMask)
{
    int     ret       = 0;
    uint8_t protocols = controllersMask & connAll_c;
    do
    {
        /* Wifi controller runs on CPU1 */
        if (((protocols & connWlan_c) != 0U) && ((runningControllers & connWlan_c) == 0U))
        {
            if (sb3_fw_reset(WIFI_LD_TARGET, 1, WIFI_FW_ADDRESS) != kStatus_Success)
            {
                ret = -1;
                break;
            }
            runningControllers |= connWlan_c;
        }
        /* BLE/15.4 share the same core (CPU2) so check if there's as least one of those required */
        if (((controllersMask & (connBle_c | conn802_15_4_c)) != 0U) &&
            ((runningControllers & (connBle_c | conn802_15_4_c)) == 0U))
        {
            if (((controllersMask & connBle_c) != 0U) && ((controllersMask & conn802_15_4_c) == 0U))
            {
                /* BLE only */
                if (sb3_fw_reset(BLE_LD_TARGET, 1, BLE_FW_ADDRESS) != kStatus_Success)
                {
                    ret = -2;
                    break;
                }
                runningControllers |= connBle_c;
            }
            else
            {
                /* BLE/15.4 combo */
                if (sb3_fw_reset(COMBO_LD_TARGET, 1, COMBO_FW_ADDRESS) != kStatus_Success)
                {
                    ret = -3;
                    break;
                }
                runningControllers |= connBle_c | conn802_15_4_c;
            }
        }
    } while (false);

    return ret;
}

int PLATFORM_TerminateControllers(uint8_t controllersMask)
{
    uint8_t protocols = controllersMask & connAll_c;

    if (((protocols & connWlan_c) != 0U) && ((runningControllers & connWlan_c) != 0U))
    {
        /* Power off CPU1 */
        power_off_device(LOAD_WIFI_FIRMWARE);
        runningControllers &= ~connWlan_c;
    }

    /* BLE/15.4 share the same core (CPU2) */
    if (((protocols & (connBle_c | conn802_15_4_c)) != 0U) &&
        ((runningControllers & (connBle_c | conn802_15_4_c)) != 0U))
    {
        /* Power off CPU2 */
        power_off_device(LOAD_BLE_FIRMWARE);
        runningControllers &= ~(connBle_c | conn802_15_4_c);
    }

    return 0;
}

uint8_t PLATFORM_GetRunningControllers(void)
{
    return runningControllers;
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */
