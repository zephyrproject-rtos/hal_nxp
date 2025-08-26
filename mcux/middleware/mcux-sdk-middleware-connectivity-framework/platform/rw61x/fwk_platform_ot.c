/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2023 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

#include "fwk_platform_ot.h"
#include "fwk_platform_coex.h"
#include "fwk_platform_ble.h"
#include "fwk_platform_hdlc.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static bool initialized = false;

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitOt(void)
{
    int ret = 0;

    do
    {
        if (initialized == true)
        {
            break;
        }

        /* Initialize the 802.15.4 controller */
        if (PLATFORM_InitControllers(conn802_15_4_c) != 0)
        {
            ret = -1;
            break;
        }

        /* Initialize the BLE Controller as it is part of the same combo firmware */
        if (PLATFORM_InitBle() != 0)
        {
            ret = -2;
            break;
        }

        /* Setup HCI link and make sure it is ready
         * Used for low power control of the BLE/15.4 firmware */
        if (PLATFORM_StartHci() != 0)
        {
            ret = -3;
            break;
        }

        initialized = true;
    } while (false);

    return ret;
}

int PLATFORM_TerminateOt(void)
{
    int ret = 0;

    do
    {
        if (PLATFORM_TerminateHdlcInterface() != 0)
        {
            ret = -1;
            break;
        }

        if (PLATFORM_TerminateBle() != 0)
        {
            ret = -2;
            break;
        }

    } while (false);

    return ret;
}

int PLATFORM_ResetOt(void)
{
    int ret = 0;

    initialized = false;

    do
    {
        if (PLATFORM_TerminateOt() != 0)
        {
            ret = -1;
            break;
        }

        if (PLATFORM_InitOt() != 0)
        {
            ret = -2;
            break;
        }

        if (PLATFORM_ResetHdlcInterface() != 0)
        {
            ret = -3;
            break;
        }

    } while (false);

    return ret;
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */
