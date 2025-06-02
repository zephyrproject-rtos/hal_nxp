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

#include "fsl_power.h"
#include "fsl_adapter_imu.h"
#include "fsl_os_abstraction.h"

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#ifndef PLATFORM_HDLC_IMUMC_LOCAL_ADDR
#define PLATFORM_HDLC_IMUMC_LOCAL_ADDR 10
#endif

#ifndef PLATFORM_HDLC_IMUMC_REMOTE_ADDR
#define PLATFORM_HDLC_IMUMC_REMOTE_ADDR 20
#endif

#ifndef PLATFORM_HDLC_IMUMC_ALLOC_FAILED_DELAY_MS
#define PLATFORM_HDLC_IMUMC_ALLOC_FAILED_DELAY_MS 2U
#endif

#ifndef PLATFORM_HDLC_IMUMC_LINK_READY_CHECK_RETRY
#define PLATFORM_HDLC_IMUMC_LINK_READY_CHECK_RETRY 100
#endif

#ifndef PLATFORM_HDLC_IMUMC_LINK_READY_DELAY_MS
#define PLATFORM_HDLC_IMUMC_LINK_READY_DELAY_MS 100
#endif

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Initialize HDLC IMUMC channel
 *
 * \return int return status: >=0 for success, <0 for errors
 */
static int PLATFORM_InitHdlcImumc(void);

/*!
 * \brief Terminate HDLC IMUMC channel
 *
 * \return int return status: >=0 for success, <0 for errors
 */
static int PLATFORM_TerminateHdlcImumc(void);

/*!
 * \brief IMUMC Rx callback used to receive HDLC messages from Controller
 *
 * \param[in] param Usually NULL
 * \param[in] data pointer to data buffer
 * \param[in] len size of the data
 * \return hal_imumc_return_status_t tells IMUMC to free or hold the buffer
 */
static hal_imumc_return_status_t PLATFORM_HdlcImumcRxCallback(void *param, uint8_t *data, uint32_t len);

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
static void                       *callbackParam = NULL;

static IMUMC_HANDLE_DEFINE(hdlcImumcHandle);
static const hal_imumc_config_t hdlcImumcConfig = {
    .local_addr  = PLATFORM_HDLC_IMUMC_LOCAL_ADDR,
    .remote_addr = PLATFORM_HDLC_IMUMC_REMOTE_ADDR,
    .imuLink     = (uint8_t)kIMU_LinkCpu2Cpu3,
    .callback    = &PLATFORM_HdlcImumcRxCallback,
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
        /* IMUMC requires 15.4 controller to be started */
        if (PLATFORM_InitOt() != 0)
        {
            ret = -1;
            break;
        }

        /* Init IMUMC interface */
        if (PLATFORM_InitHdlcImumc() != 0)
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
        if (PLATFORM_TerminateControllers(conn802_15_4_c) != 0)
        {
            ret = -1;
            break;
        }

        if (HAL_ImuDeinit(kIMU_LinkCpu2Cpu3, 1) != kStatus_HAL_ImumcSuccess)
        {
            ret = -2;
            break;
        }

        if (PLATFORM_TerminateHdlcImumc() != 0)
        {
            ret = -3;
            break;
        }
    } while (false);

    return ret;
}

int PLATFORM_ResetHdlcInterface(void)
{
    int ret = 0;

    /* Init IMUMC interface */
    if (PLATFORM_InitHdlcImumc() != 0)
    {
        ret = -1;
    }

    return ret;
}

int PLATFORM_SendHdlcMessage(uint8_t *msg, uint32_t len)
{
    hal_imumc_status_t imumcStatus;
    int                ret                = 0;
    int                hdlcLinkReadyRetry = 0;
    uint32_t           remainingBytes     = len;
    uint8_t           *pMsg               = msg;
    uint8_t           *pImumcBuffer       = NULL;

    do
    {
        /* Make sure the link is ready before sending a message */
        while (PLATFORM_IsHdlcLinkReady() == false)
        {
            if (hdlcLinkReadyRetry >= PLATFORM_HDLC_IMUMC_LINK_READY_CHECK_RETRY)
            {
                ret = -1;
                break;
            }
            hdlcLinkReadyRetry++;
            OSA_TimeDelay(PLATFORM_HDLC_IMUMC_LINK_READY_DELAY_MS);
        }

        if (ret != 0)
        {
            break;
        }

        (void)PLATFORM_RequestBleWakeUp();

        /* Send HDLC Packet through IMUMC channel
         * If the size if larger than the maximum IMUMC buffer size, we have to send chunks of the packet */
        while (remainingBytes > 0u)
        {
            uint32_t sizeToSend;

            if (remainingBytes > IMUMC_TXQ23_BUFLENGTH)
            {
                sizeToSend = IMUMC_TXQ23_BUFLENGTH;
            }
            else
            {
                sizeToSend = remainingBytes;
            }

            /* Allocate a IMUMC buffer in shared memory */
            pImumcBuffer = HAL_ImumcAllocTxBuffer(hdlcImumcHandle, sizeToSend);
            assert(pImumcBuffer != NULL);

            /* Copy the message to the IMUMC buffer */
            (void)memcpy(pImumcBuffer, pMsg, sizeToSend);

            /* Send the message without any copy as it's already stored in the shared memory */
            imumcStatus = HAL_ImumcNoCopySend(hdlcImumcHandle, pImumcBuffer, sizeToSend);
            if (imumcStatus != kStatus_HAL_ImumcSuccess)
            {
                /* An error here means the IMU link is not ready yet, we can assert here as it shouldn't happen
                 * because we wait for the IMU link to be ready in PLATFORM_InitHdlcImumc() */
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

static int PLATFORM_InitHdlcImumc(void)
{
    hal_imumc_status_t imumcStatus;
    hal_imumc_config_t imumcConfig;
    int                ret = 0;

    imumcConfig = hdlcImumcConfig;
    do
    {
        /* Init IMUMC Channel */
        imumcStatus = HAL_ImumcInit((hal_imumc_handle_t)hdlcImumcHandle, &imumcConfig);
        if (imumcStatus != kStatus_HAL_ImumcSuccess)
        {
            ret = -1;
            break;
        }
    } while (false);

    return ret;
}

static int PLATFORM_TerminateHdlcImumc(void)
{
    hal_imumc_status_t imumcStatus;
    int                ret = 0;

    imumcStatus = HAL_ImumcDeinit((hal_imumc_handle_t)hdlcImumcHandle);
    if (imumcStatus != kStatus_HAL_ImumcSuccess)
    {
        ret = -1;
    }

    return ret;
}

static hal_imumc_return_status_t PLATFORM_HdlcImumcRxCallback(void *param, uint8_t *data, uint32_t len)
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
    return (HAL_ImuLinkIsUp(hdlcImumcConfig.imuLink) == kStatus_HAL_ImumcSuccess);
}
