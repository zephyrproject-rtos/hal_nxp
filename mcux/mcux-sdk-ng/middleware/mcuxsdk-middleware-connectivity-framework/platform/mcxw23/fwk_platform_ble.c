/*!
 * Copyright 2024-2026 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * \file fwk_platform_ble.c
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

#include "fsl_common.h"
#include "fwk_platform.h"
#include "fwk_platform_ble.h"
#include "ble_controller.h"

#ifdef SERIAL_BTSNOOP
#include "sbtsnoop.h"
#endif

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

#if defined(gUseHciTransportDownward_d) && (gUseHciTransportDownward_d > 0)
static blec_result_t PLATFORM_HciRxCallback(blec_hciPacketType_t packetType, void *pPacket, uint16_t packetSize);
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#if gAppMaxTxPowerDbm_c > 6
/* MCXW23 limits TX power to a maximum of 6 dBm */
#undef gAppMaxTxPowerDbm_c
#define gAppMaxTxPowerDbm_c 6
#endif

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static void (*hci_rx_callback)(uint8_t packetType, uint8_t *data, uint16_t len);
static bool initialized = false;

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitBle(void)
{
    int ret = 0;

    do
    {
        if (initialized == true)
        {
            ret = 1;
            break;
        }

        /* Initialize the controller only when this flag is set, otherwise it means it
         * will be initialized by upper layers */
#if defined(gUseHciTransportDownward_d) && (gUseHciTransportDownward_d > 0)
        if (kBLEC_Success != BLEController_Init(PLATFORM_HciRxCallback, gAppMaxTxPowerDbm_c, NULL))
        {
            ret = -1;
            break;
        }
#else
        uint8_t bdAddr[6];

        PLATFORM_GetBDAddr(bdAddr);
        (void)BLEController_WriteBdAddr(bdAddr);
#endif

        initialized = true;
    } while (false);

    return ret;
}

int PLATFORM_SendHciMessage(uint8_t *msg, uint32_t len)
{
    return PLATFORM_SendHciMessageAlt(msg[0], &msg[1], len - 1U);
}

int PLATFORM_SendHciMessageAlt(uint8_t packetType, uint8_t *msg, uint32_t len)
{
    int ret = 0;

#ifdef SERIAL_BTSNOOP
    sbtsnoop_write_hci_pkt(packetType, 0U, msg, len);
#endif

    if (BLEController_ProcessHciPacket((blec_hciPacketType_t)packetType, msg, len) != kBLEC_Success)
    {
        ret = -1;
    }

    return ret;
}

int PLATFORM_StartHci(void)
{
    /* not implemented for this platform */
    return 0;
}

int PLATFORM_SetHciRxCallback(void (*callback)(uint8_t packetType, uint8_t *data, uint16_t len))
{
    hci_rx_callback = callback;
    return 0;
}

int PLATFORM_GetRadioIdleDuration32K(void)
{
    blec_result_t status;
    int           ret;
    uint32_t      remainingTimeUs  = 0U;
    uint32_t      remainingTime32k = 0U;

    do
    {
        status = BLEController_GetRemainingTimeForNextEvent(&remainingTimeUs);
        if (status != kBLEC_Success)
        {
            ret = -2;
            break;
        }

        if (remainingTimeUs == UINT32_MAX)
        {
            ret = PLATFORM_RADIO_IDLE_FOREVER;
            break;
        }

        remainingTime32k = USEC_TO_COUNT(remainingTimeUs, 32768U);
        if (remainingTime32k > INT32_MAX)
        {
            ret = PLATFORM_RADIO_IDLE_FOREVER;
        }
        else
        {
            ret = (int)remainingTime32k;
        }
    } while (0);

    return ret;
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

#if defined(gUseHciTransportDownward_d) && (gUseHciTransportDownward_d > 0)
static blec_result_t PLATFORM_HciRxCallback(blec_hciPacketType_t packetType, void *pPacket, uint16_t packetSize)
{
    if (hci_rx_callback != NULL)
    {
#ifdef SERIAL_BTSNOOP
        sbtsnoop_write_hci_pkt(packetType, 1U, pPacket, packetSize);
#endif
        hci_rx_callback((uint8_t)packetType, (uint8_t *)pPacket, packetSize);
    }

    return kBLEC_Success;
}
#endif
