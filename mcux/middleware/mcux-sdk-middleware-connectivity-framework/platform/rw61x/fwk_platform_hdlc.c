/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2024 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

#include "fwk_platform_coex.h"
#include "fwk_platform_ble.h"
#include "fwk_platform_hdlc.h"
#include "fwk_platform_ot.h"
#include "fsl_adapter_rfimu.h"
#include "fsl_adapter_rpmsg.h"
#include "fsl_os_abstraction.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#ifndef PLATFORM_HDLC_RPMSG_LOCAL_ADDR
#define PLATFORM_HDLC_RPMSG_LOCAL_ADDR 10
#endif

#ifndef PLATFORM_HDLC_RPMSG_REMOTE_ADDR
#define PLATFORM_HDLC_RPMSG_REMOTE_ADDR 20
#endif

#ifndef PLATFORM_HDLC_RPMSG_ALLOC_FAILED_DELAY_MS
#define PLATFORM_HDLC_RPMSG_ALLOC_FAILED_DELAY_MS 2U
#endif

#ifndef PLATFORM_HDLC_RPMSG_LINK_READY_CHECK_RETRY
#define PLATFORM_HDLC_RPMSG_LINK_READY_CHECK_RETRY 100
#endif

#ifndef PLATFORM_HDLC_RPMSG_LINK_READY_DELAY_MS
#define PLATFORM_HDLC_RPMSG_LINK_READY_DELAY_MS 100
#endif

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Initialize HDLC RPMSG channel
 *
 * \return int return status: >=0 for success, <0 for errors
 */
static int PLATFORM_InitHdlcRpmsg(void);

/*!
 * \brief Terminate HDLC RPMSG channel
 *
 * \return int return status: >=0 for success, <0 for errors
 */
static int PLATFORM_TerminateHdlcRpmsg(void);

/*!
 * \brief RPMSG Rx callback used to receive HDLC messages from Controller
 *
 * \param[in] param Usually NULL
 * \param[in] data pointer to data buffer
 * \param[in] len size of the data
 * \return hal_rpmsg_return_status_t tells RPMSG to free or hold the buffer
 */
static hal_rpmsg_return_status_t PLATFORM_HdlcRpmsgRxCallback(void *param, uint8_t *data, uint32_t len);

/*!
 * \brief Checks if the IMU link is ready - used before sending a message
 *
 * \return true link is ready
 * \return false link is not ready yet
 */
static bool PLATFORM_IsHdlcLinkReady(void);

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static platform_hdlc_rx_callback_t hdlcRxCallback;
static void *                      callbackParam = NULL;

static RPMSG_HANDLE_DEFINE(hdlcRpmsgHandle);
static const hal_rpmsg_config_t hdlcRpmsgConfig = {
    .local_addr  = PLATFORM_HDLC_RPMSG_LOCAL_ADDR,
    .remote_addr = PLATFORM_HDLC_RPMSG_REMOTE_ADDR,
    .imuLink     = kIMU_LinkCpu2Cpu3,
    .callback    = PLATFORM_HdlcRpmsgRxCallback,
    .param       = NULL,
};

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitHdlcInterface(platform_hdlc_rx_callback_t callback, void *param)
{
    int ret = 0;

    hdlcRxCallback = callback;
    callbackParam  = param;

    do
    {
        /* RPMSG/IMU requires 15.4 controller to be started */
        if (PLATFORM_InitOt() != 0)
        {
            ret = -1;
            break;
        }

        /* Init RPMSG interface */
        if (PLATFORM_InitHdlcRpmsg() != 0)
        {
            ret = -2;
            break;
        }
    } while (false);

    if (ret != 0)
    {
        hdlcRxCallback = NULL;
        callbackParam  = NULL;
    }

    return ret;
}

int PLATFORM_TerminateHdlcInterface(void)
{
    int ret = 0;

    do
    {
        /* Make sure the controller is awake */
        ret = PLATFORM_RequestBleWakeUp();
        if (ret != 0)
        {
            ret = -1;
            break;
        }

        if (HAL_ImuDeinit(kIMU_LinkCpu2Cpu3, 0) != kStatus_HAL_RpmsgSuccess)
        {
            ret = -2;
            break;
        }

        if (PLATFORM_TerminateHdlcRpmsg() != 0)
        {
            ret = -3;
            break;
        }

        if (PLATFORM_TerminateControllers((uint32_t)conn802_15_4_c) != 0)
        {
            ret = -4;
            break;
        }

        /* Release the wake up request now */
        ret = PLATFORM_ReleaseBleWakeUp();
        if (ret != 0)
        {
            ret = -5;
            break;
        }
    } while (false);

    return ret;
}

int PLATFORM_ResetHdlcInterface(void)
{
    int ret = 0;

    /* Init RPMSG interface */
    if (PLATFORM_InitHdlcRpmsg() != 0)
    {
        ret = -1;
    }

    return ret;
}

int PLATFORM_SendHdlcMessage(uint8_t *msg, uint32_t len)
{
    hal_rpmsg_status_t rpmsgStatus;
    int                ret                = 0;
    int                hdlcLinkReadyRetry = 0;
    uint32_t           remainingBytes     = len;
    uint8_t *          pMsg               = msg;
    uint8_t *          pRpmsgBuffer       = NULL;

    do
    {
        /* Make sure the link is ready before sending a message */
        while (PLATFORM_IsHdlcLinkReady() == false)
        {
            if (hdlcLinkReadyRetry >= PLATFORM_HDLC_RPMSG_LINK_READY_CHECK_RETRY)
            {
                ret = -1;
                break;
            }
            hdlcLinkReadyRetry++;
            OSA_TimeDelay(PLATFORM_HDLC_RPMSG_LINK_READY_DELAY_MS);
        }

        if (ret != 0)
        {
            break;
        }

        (void)PLATFORM_RequestBleWakeUp();

        /* Send HDLC Packet through RPMSG channel
         * If the size if larger than the maximum RPMSG buffer size, we have to send chunks of the packet */
        while (remainingBytes > 0)
        {
            uint32_t sizeToSend;

            if (remainingBytes > RPMSG_TXQ23_BUFLENGTH)
            {
                sizeToSend = RPMSG_TXQ23_BUFLENGTH;
            }
            else
            {
                sizeToSend = remainingBytes;
            }

            /* Allocate a RPMSG buffer in shared memory */
            pRpmsgBuffer = HAL_RpmsgAllocTxBuffer(hdlcRpmsgHandle, sizeToSend);
            assert(pRpmsgBuffer != NULL);

            /* Copy the message to the RPMSG buffer */
            (void)memcpy(pRpmsgBuffer, pMsg, sizeToSend);

            /* Send the message without any copy as it's already stored in the shared memory */
            rpmsgStatus = HAL_RpmsgNoCopySend(hdlcRpmsgHandle, pRpmsgBuffer, sizeToSend);
            if (rpmsgStatus != kStatus_HAL_RpmsgSuccess)
            {
                /* An error here means the IMU link is not ready yet, we can assert here as it shouldn't happen
                 * because we wait for the IMU link to be ready in PLATFORM_InitHdlcRpmsg() */
                assert(0);
                ret = -1;
                break;
            }

            pMsg += sizeToSend;
            remainingBytes -= sizeToSend;
        }

        (void)PLATFORM_ReleaseBleWakeUp();

    } while (false);

    return ret;
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

static int PLATFORM_InitHdlcRpmsg(void)
{
    hal_rpmsg_status_t rpmsgStatus;
    int                ret = 0;

    do
    {
        /* Init RPMSG/IMU Channel */
        rpmsgStatus = HAL_RpmsgInit((hal_rpmsg_handle_t)hdlcRpmsgHandle, (hal_rpmsg_config_t *)&hdlcRpmsgConfig);
        if (rpmsgStatus != kStatus_HAL_RpmsgSuccess)
        {
            ret = -1;
            break;
        }
    } while (false);

    return ret;
}

static int PLATFORM_TerminateHdlcRpmsg(void)
{
    hal_rpmsg_status_t rpmsgStatus;
    int                ret = 0;

    rpmsgStatus = HAL_RpmsgDeinit((hal_rpmsg_handle_t)hdlcRpmsgHandle);
    if (rpmsgStatus != kStatus_HAL_RpmsgSuccess)
    {
        ret = -1;
    }

    return ret;
}

static hal_rpmsg_return_status_t PLATFORM_HdlcRpmsgRxCallback(void *param, uint8_t *data, uint32_t len)
{
    (void)PLATFORM_HandleControllerPowerState();

    if (hdlcRxCallback != NULL)
    {
        hdlcRxCallback(data, len, callbackParam);
    }

    return kStatus_HAL_RL_RELEASE;
}

static bool PLATFORM_IsHdlcLinkReady(void)
{
    return (HAL_ImuLinkIsUp(hdlcRpmsgConfig.imuLink) == kStatus_HAL_RpmsgSuccess);
}
