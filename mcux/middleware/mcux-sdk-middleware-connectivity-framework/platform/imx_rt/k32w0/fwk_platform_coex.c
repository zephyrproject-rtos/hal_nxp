/* -------------------------------------------------------------------------- */
/*                           Copyright 2022-2023 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

#include "fsl_os_abstraction.h"
#include "fwk_otw.h"

#ifndef K32W0_RCP_BINARY_H_FILE
#define K32W0_RCP_BINARY_H_FILE "rcp_name.bin.h"
#endif

#include K32W0_RCP_BINARY_H_FILE

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static bool isOtControllerUp = false;

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitControllers(uint8_t controllersMask)
{
    (void)controllersMask;

    eOtwStatus otwStatus;
    int        ret = 0;

    do
    {
        /*  initialize controller if not done */
        if (isOtControllerUp)
            break;

        otwStatus = Otw_FirmwareDownload(ot_rcp, sizeof(ot_rcp), false);
        if (otwStatus != E_OTW_OK && otwStatus != E_OTW_FIRMWARE_UPDATE_NOT_REQUIRED)
        {
            ret = -1;
            break;
        }
        otwStatus = Otw_Reset();
        if (otwStatus != E_OTW_OK)
        {
            ret = -1;
            break;
        }
        isOtControllerUp = true;

    } while (false);

    assert(ret == 0);

    return ret;
}
/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */