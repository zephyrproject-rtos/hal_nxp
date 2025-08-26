/*!
 * Copyright 2021-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "board_platform.h"
#include "fsl_common.h"
#include "fsl_adapter_rpmsg.h"
#include "pin_mux.h"
#include "fwk_platform.h"
#include "fwk_platform_ics.h"
#include "fwk_platform_ot.h"
#include "SecLib.h"
#include "RNG_Interface.h"
#include "HWParameter.h"
#include "FunctionLib.h"

/* Default IEE EIU64 OUI */
#ifndef IEEE802_15_4_ADDR_OUI
#define IEEE802_15_4_ADDR_OUI 0x37U, 0x60U, 0x00U
#endif

static const uint8_t gIeee802_15_4_ADDR_OUI_c[MAC_ADDR_OUI_PART_SIZE] = {IEEE802_15_4_ADDR_OUI};

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
        status = PLATFORM_InitTimerManager();
        CHECK_AND_RAISE_ERROR(status, -1);

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

        /* Update 32MHz trim value with the one stored in HW parameters */
        PLATFORM_LoadHwParams();

#if !defined(gBoardUseFro32k_d) || (gBoardUseFro32k_d == 0)
        /* Make sure OSC32k is ready and select it as clock source */
        status = PLATFORM_SwitchToOsc32k();
        CHECK_AND_RAISE_ERROR(status, -7);
#endif
    } while (false);

    return status;
}

static void PLATFORM_GenerateNewEui64Addr(uint8_t *eui64_address)
{
    uint8_t macAddr[EUI_64_SZ - MAC_ADDR_OUI_PART_SIZE] = {0U};
#if (gPlatformUseUniqueDeviceIdFor15_4Addr_d != 0)
    uint32_t uid_lsb = RADIO_CTRL->UID_LSB;
    if (uid_lsb != 0U)
    {
        for (int i = 0; i < sizeof(uint32_t); i++)
        {
            macAddr[i] = (uint8_t)uid_lsb & 0xFFU;
            uid_lsb >>= 8;
        }
        macAddr[4] = (uint8_t)(RADIO_CTRL->UID_MSB) & 0xFFU;
    }
    else
#endif
    {
        uint8_t ret;
        int16_t num;

        ret = RNG_Init();
        assert(ret == 0);
        (void)ret;
#ifndef FWK_RNG_DEPRECATED_API
        num = RNG_GetPseudoRandomData(macAddr, EUI_64_SZ - MAC_ADDR_OUI_PART_SIZE, NULL);
#else
        RNG_SetPseudoRandomNoSeed(NULL);
        num = RNG_GetPseudoRandomNo(macAddr, EUI_64_SZ - MAC_ADDR_OUI_PART_SIZE, NULL);
#endif
        assert(num == (EUI_64_SZ - MAC_ADDR_OUI_PART_SIZE));
        (void)num;
    }
    /* Set 3 LSB from mac address */
    FLib_MemCpy((void *)eui64_address, (const void *)macAddr, EUI_64_SZ - MAC_ADDR_OUI_PART_SIZE);

    /* Set 3 MSB from OUI */
    FLib_MemCpy((void *)&eui64_address[EUI_64_SZ - MAC_ADDR_OUI_PART_SIZE], (const void *)gIeee802_15_4_ADDR_OUI_c,
                MAC_ADDR_OUI_PART_SIZE);
}

void PLATFORM_GetIeee802_15_4Addr(uint8_t *eui64_address)
{
    hardwareParameters_t *pHWParams = NULL;
    uint32_t              status;

    status = NV_ReadHWParameters(&pHWParams);

    /* FLib_MemCmpToVal mandatory to make sure IEEE 802.15.4 MAC address is valid
     * because return status of NV_ReadHWParameters is 1 only at 1st read attempt */
    if ((status == 0U) && (FLib_MemCmpToVal((const void *)pHWParams->ieee_802_15_4_address, 0xFFU, EUI_64_SZ) == FALSE))
    {
        uint32_t regPrimask;

        regPrimask = DisableGlobalIRQ();
        FLib_MemCpy((void *)eui64_address, (const void *)pHWParams->ieee_802_15_4_address, EUI_64_SZ);
        EnableGlobalIRQ(regPrimask);
    }
    else
    {
        uint32_t regPrimask;

        /* User can decide to use the device unique address or a random generated address with
         * gPlatformUseUniqueDeviceIdForBdAddr_d */
        PLATFORM_GenerateNewEui64Addr(eui64_address);

        regPrimask = DisableGlobalIRQ();
        FLib_MemCpy((void *)pHWParams->ieee_802_15_4_address, (void *)eui64_address, EUI_64_SZ);

        (void)NV_WriteHWParameters();
        EnableGlobalIRQ(regPrimask);
    }
}
