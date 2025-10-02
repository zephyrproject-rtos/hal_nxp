/*!
 * Copyright 2024-2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * \file fwk_platform_ble.c
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fwk_platform_ble.h"
#include "ble_controller.h"
#include "fsl_rom_api.h"

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
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static void (*hci_rx_callback)(uint8_t packetType, uint8_t *data, uint16_t len);
static bool is_initialized = false;

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitBle(void)
{
    int ret = 0;

    do
    {
        if (is_initialized)
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
        }
#else
        uint8_t bdAddr[6];

        PLATFORM_GetBDAddr(bdAddr);
        (void)BLEController_WriteBdAddr(bdAddr);
#endif
        is_initialized = true;
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
    return 0;
}

int PLATFORM_SetHciRxCallback(void (*callback)(uint8_t packetType, uint8_t *data, uint16_t len))
{
    int ret = 0;
    hci_rx_callback = callback;
    (void)hci_rx_callback;
    return ret;
}

bool PLATFORM_CheckNextBleConnectivityActivity(void)
{
    return true;
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
