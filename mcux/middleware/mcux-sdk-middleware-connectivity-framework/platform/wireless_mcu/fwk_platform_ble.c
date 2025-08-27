/* -------------------------------------------------------------------------- */
/*                        Copyright 2021-2023, 2025 NXP                       */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include "fsl_common.h"
#include "fsl_adapter_rpmsg.h"
#include "fwk_config.h"
#include "fwk_platform_ble.h"
#include "fwk_platform.h"
#include "fwk_platform_ics.h"
#ifdef SERIAL_BTSNOOP
#include "sbtsnoop.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */
#ifndef PLATFORM_BLE_HCI_TIMEOUT_MS
#define PLATFORM_BLE_HCI_TIMEOUT_MS 200U
#endif

/* Check if __st is negative,  if true, apply 4 bits shift and add new __error_code,
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

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */
/* RPMSG related variables */

/* Define hci serial manager handle*/
static RPMSG_HANDLE_DEFINE(hciRpmsgHandle);

/*hci rpmsg configuration*/
static const hal_rpmsg_config_t hciRpmsgConfig = {
    .local_addr  = 40,
    .remote_addr = 30,
};

static void (*hci_rx_callback)(uint8_t packetType, uint8_t *data, uint16_t len);

static bool is_initialized = false;
/* -------------------------------------------------------------------------- */
/*                         Public memory declarations                        */
/* -------------------------------------------------------------------------- */
extern PLATFORM_ErrorCallback_t pfPlatformErrorCallback;

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Init HCI link with BLE controller
 *
 */
static int PLATFORM_InitHciLink(void);

/*!
 * \brief RPMSG Rx callback used to receive HCI messages from Controller
 *
 * \param[in] param Usually NULL
 * \param[in] data pointer to data buffer
 * \param[in] len size of the data
 * \return hal_rpmsg_return_status_t tells RPMSG to free or hold the buffer
 */
static hal_rpmsg_return_status_t PLATFORM_HciRpmsgRxCallback(void *param, uint8_t *data, uint32_t len);

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitBle(void)
{
    int status = 0;

    do
    {
        if (is_initialized)
        {
            status = 1;
            break;
        }
        /* When waking up from deep power down mode (following Deep power down reset), it is necessary to release IO
         * isolations. this is usually done in Low power initialization but it is necessay also
         * to be done if the Application does not support low power */
        (void)PLATFORM_ClearIoIsolationFromLowPower();

        /* Init NBU domain and configure RFMC module
         * CM3 is still in reset and will be released by MCMGR_StartCore during RPMSG init */
        status = PLATFORM_InitNbu();
        CHECK_AND_RAISE_ERROR(status, -2);

        /* Init of the multicore*/
        status = PLATFORM_InitMulticore();
        CHECK_AND_RAISE_ERROR(status, -3);

        /* Init HCI link with NBU */
        status = PLATFORM_InitHciLink();
        CHECK_AND_RAISE_ERROR(status, -4);

        /* Initialize PLatform Service intercore channel
         *  Used to retrieve NBU version information but not retricted to this sole use.
         */
        status = PLATFORM_FwkSrvInit();
        CHECK_AND_RAISE_ERROR(status, -5);

        /* Send chip revision (A0 or A1) to NBU */
        status = PLATFORM_SendChipRevision();
        CHECK_AND_RAISE_ERROR(status, -6);

        is_initialized = true;
    } while (false);

    /* Error callback set by PLATFORM_RegisterBleErrorCallback() */
    if ((status < 0) && (pfPlatformErrorCallback != NULL))
    {
        pfPlatformErrorCallback(PLATFORM_INIT_BLE_ID, status);
    }

    return status;
}

int PLATFORM_SetHciRxCallback(void (*callback)(uint8_t packetType, uint8_t *data, uint16_t len))
{
    int ret = 0;

    hci_rx_callback = callback;

    return ret;
}

int PLATFORM_SendHciMessage(uint8_t *msg, uint32_t len)
{
    int status = 0;
    do
    {
        /* Wake up controller before sending the message */
        PLATFORM_RemoteActiveReq();

        /* Send HCI Packet through RPMSG channel */
        status = (int)HAL_RpmsgSendTimeout(hciRpmsgHandle, msg, len, PLATFORM_BLE_HCI_TIMEOUT_MS);
        if (status != 0)
        {
            status = RAISE_ERROR(status, 1);
            break;
        }

#ifdef SERIAL_BTSNOOP
        uint16_t lg = (uint16_t)len - 1U;
        if (lg > 0U)
        {
            sbtsnoop_write_hci_pkt(msg[0U], 0U, &msg[1], lg);
        }
#endif

    } while (false);

    /* Release wake up request */
    PLATFORM_RemoteActiveRel();

    /* Error callback set by PLATFORM_RegisterBleErrorCallback() */
    if ((status != 0) && (pfPlatformErrorCallback != NULL))
    {
        pfPlatformErrorCallback(PLATFORM_SEND_HCI_MESSAGE_ID, status);
    }

    return status;
}

int PLATFORM_TerminateBle(void)
{
    return 0;
}

int PLATFORM_StartHci(void)
{
    return 0;
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

static int PLATFORM_InitHciLink(void)
{
    int                status = 0;
    hal_rpmsg_config_t hci_rpmsg_config;
    hal_rpmsg_status_t hci_rpmsg_status;

    hci_rpmsg_config = hciRpmsgConfig;

    hci_rpmsg_status = HAL_RpmsgInit((hal_rpmsg_handle_t)hciRpmsgHandle, &hci_rpmsg_config);
    if (hci_rpmsg_status != kStatus_HAL_RpmsgSuccess)
    {
        assert(0);
        status = RAISE_ERROR(hci_rpmsg_status, 1);
    }
    /* Set RX Callback */
    else
    {
        hci_rpmsg_status =
            HAL_RpmsgInstallRxCallback((hal_rpmsg_handle_t)hciRpmsgHandle, PLATFORM_HciRpmsgRxCallback, NULL);
        if (hci_rpmsg_status != kStatus_HAL_RpmsgSuccess)
        {
            assert(0);
            status = RAISE_ERROR(hci_rpmsg_status, 2);
        }
    }
    return status;
}

static hal_rpmsg_return_status_t PLATFORM_HciRpmsgRxCallback(void *param, uint8_t *data, uint32_t len)
{
    /* len shall be strictly positive as message shall not be empty */
    assert((len > 0u) && (len <= (uint16_t)UINT16_MAX));

    if ((len > 0u) && (len <= (uint16_t)UINT16_MAX) && (hci_rx_callback != NULL))
    {
        PLATFORM_RemoteActiveReq();

        hci_rx_callback(data[0], &data[1], (uint16_t)(len - 1U));

#ifdef SERIAL_BTSNOOP
        sbtsnoop_write_hci_pkt(data[0U], 1U, &data[1], (uint16_t)(len - 1U));
#endif

        PLATFORM_RemoteActiveRel();
    }
    (void)param;

    return kStatus_HAL_RL_RELEASE;
}
