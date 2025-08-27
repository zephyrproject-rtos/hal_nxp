/*!
 * Copyright 2021-2023, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"
#include "fsl_adapter_rpmsg.h"
#include "fwk_platform.h"
#include "fwk_platform_ics.h"
#include "fwk_platform_ot.h"

/* Check if __st is negative,  if true, apply 4 bits shit and add new __error_code,
    assert in debug and break
   Shall be called in a do while(0) bracket */
#define CHECK_AND_RAISE_ERROR(__st, __error_code)                                                  \
    {                                                                                              \
        if ((__st) < 0)                                                                            \
        {                                                                                          \
            assert(0);                                                                             \
            (__st) = -(int)((uint32_t)(((uint32_t)(-(__st)) << 4) | (uint32_t)(-(__error_code)))); \
            break;                                                                                 \
        }                                                                                          \
    }

/* Raise error with status update , shift previous status by 4 bits and OR with new error code.
 * the returned status will be negative */
#define RAISE_ERROR(__st, __error_code) -(int)((uint32_t)(((uint32_t)(__st) << 4) | (uint32_t)(__error_code)));

int PLATFORM_InitOT(void)
{
    int status = 0;

    do
    {
#if USE_NBU
        /* Init NBU domain and configure RFMC module
         * CM3 is still in reset and will be released by MCMGR_StartCore during RPMSG init */
        status = PLATFORM_InitNbu();
        CHECK_AND_RAISE_ERROR(status, -2);

        /* Init of the multicore*/
        status = PLATFORM_InitMulticore();
        CHECK_AND_RAISE_ERROR(status, -3);

        /* Initialize PLatform Service intercore channel
         *  Used to retrieve NBU version information but not retricted to this sole use.
         */
        status = PLATFORM_FwkSrvInit();
        CHECK_AND_RAISE_ERROR(status, -5);
#endif

#if USE_NBU && !NBU_15_4_ONLY
        /* Send chip revision (A0 or A1) to NBU */
        status = PLATFORM_SendChipRevision();
        CHECK_AND_RAISE_ERROR(status, -6);
#endif
    } while (false);

    return status;
}
