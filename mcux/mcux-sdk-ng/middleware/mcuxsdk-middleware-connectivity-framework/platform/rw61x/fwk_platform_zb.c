/*!
 * Copyright 2024 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * \file fwk_platform_zb.c
 * \brief PLATFORM abstraction implementation for Zigbee
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stdbool.h>

#include "fwk_platform_zb.h"
#include "fwk_platform_ble.h"
#include "fwk_platform_ot.h"
#include "fwk_platform_coex.h"
#include "fsl_adapter_imu.h"
#include "fsl_os_abstraction.h"
#ifndef __ZEPHYR__
#include "RNG_Interface.h"
#include "PDM.h"
#include "FunctionLib.h"
#endif // __ZEPHYR__

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#ifndef PLATFORM_ZB_MAC_IMUMC_LOCAL_ADDR
#define PLATFORM_ZB_MAC_IMUMC_LOCAL_ADDR 12U
#endif

#ifndef PLATFORM_ZB_MAC_IMUMC_REMOTE_ADDR
#define PLATFORM_ZB_MAC_IMUMC_REMOTE_ADDR 22U
#endif

#ifndef PLATFORM_ZB_IMUMC_ALLOC_FAILED_DELAY_MS
#define PLATFORM_ZB_IMUMC_ALLOC_FAILED_DELAY_MS 2U
#endif

#ifndef PLATFORM_ZB_IMUMC_LINK_READY_CHECK_RETRY
#define PLATFORM_ZB_IMUMC_LINK_READY_CHECK_RETRY 100
#endif

#ifndef PLATFORM_ZB_IMUMC_LINK_READY_DELAY_MS
#define PLATFORM_ZB_IMUMC_LINK_READY_DELAY_MS 100U
#endif

#ifndef IEEE802_15_4_ADDR_OUI
#define IEEE802_15_4_ADDR_OUI 0xDAU, 0x95U, 0xC0U
#endif

#define MAC_ADDR_OUI_PART_SIZE 3U

#define EUI_64_SZ (64U / 8U)

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Initialize Zigbee MAC or PHY IMUMC channel
 *
 * \param[in] imumcHandle MAC or PHY IMUMC handle
 * \param[in] imumcConfig MAC or PHY IMUMC config
 * \return int return status: >=0 for success, <0 for errors
 */
static int PLATFORM_InitZbImumc(hal_imumc_handle_t imumcHandle, hal_imumc_config_t imumcConfig);

/*!
 * \brief Send Zigbee message to either MAC or PHY
 *
 * \param[in] imumcHandle MAC or PHY IMUMC handle
 * \param[in] msg pointer to the message to send
 * \param[in] len size of the message buffer
 * \return int return status: >=0 for success, <0 for errors
 */
static int PLATFORM_SendZbMessage(hal_imumc_handle_t imumcHandle, uint8_t *msg, uint32_t len);

/*!
 * \brief IMUMC Rx callback used to receive Zigbee MAC and PHY messages from Controller
 *        This callback is used for both MAC and PHY links, so we use the "param" input
 *        to get the remote addr of the link
 *
 * \param[in] param remote_addr of the link
 * \param[in] data pointer to data buffer
 * \param[in] len size of the data
 * \return hal_imumc_return_status_t tells IMUMC to free or hold the buffer
 */
static hal_imumc_return_status_t PLATFORM_ZbImumcRxCallback(void *param, uint8_t *data, uint32_t len);

/*!
 * \brief Checks if the IMU link is ready - used before sending a message
 *
 * \return true link is ready
 * \return false link is not ready yet
 */
static bool PLATFORM_IsZbLinkReady(void);

/*!
 * \brief Generates an extended address (64bits) for the MAC
 *
 * \param[in] eui64_address pointer to a 8 bytes array
 */
static void PLATFORM_GenerateEui64Addr(uint8_t *eui64_address);

/* -------------------------------------------------------------------------- */
/*                             External prototypes                            */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Sends a MAC platform request to get the IEEE 64bits address from OTP
 *        memory.
 *
 * \param[out] eui64_address pointer to a 8 bytes buffer to write the address to
 */
extern void MAC_PLATFORM_GetIeee802_15_4Addr(uint8_t *eui64_address);

/* -------------------------------------------------------------------------- */
/*                               Private memory                               */
/* -------------------------------------------------------------------------- */

static platform_zb_rx_callback_t zbMacRxCallback;
static void                     *zbMacCallbackParam = NULL;

static IMUMC_HANDLE_DEFINE(zbMacImumcHandle);
static const hal_imumc_config_t zbMacImumcConfig = {
    .local_addr  = PLATFORM_ZB_MAC_IMUMC_LOCAL_ADDR,
    .remote_addr = PLATFORM_ZB_MAC_IMUMC_REMOTE_ADDR,
    .imuLink     = (uint8_t)kIMU_LinkCpu2Cpu3,
    .callback    = &PLATFORM_ZbImumcRxCallback,
    .param       = (void *)PLATFORM_ZB_MAC_IMUMC_REMOTE_ADDR,
};

static const uint8_t gIeee802_15_4_ADDR_OUI_c[MAC_ADDR_OUI_PART_SIZE] = {IEEE802_15_4_ADDR_OUI};

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitZigbee(void)
{
    int ret = 0;

    /* Initialize 15.4 controller */
    ret = PLATFORM_InitOt();

    return ret;
}

int PLATFORM_InitZbMacInterface(platform_zb_rx_callback_t callback, void *param)
{
    int ret = 0;

    zbMacRxCallback    = callback;
    zbMacCallbackParam = param;

    do
    {
        /* IMUMC requires 15.4 controller to be started */
        if (PLATFORM_InitOt() != 0)
        {
            ret = -1;
            break;
        }

        /* Init IMUMC interface */
        if (PLATFORM_InitZbImumc((hal_imumc_handle_t)zbMacImumcHandle, zbMacImumcConfig) != 0)
        {
            ret = -2;
            break;
        }
    } while (false);

    if (ret != 0)
    {
        zbMacRxCallback    = NULL;
        zbMacCallbackParam = NULL;
    }

    return ret;
}

int PLATFORM_TerminateZbMacInterface(void)
{
    /* NOT IMPLEMENTED */
    return 0;
}

int PLATFORM_ResetZbMacInterface(void)
{
    /* NOT IMPLEMENTED */
    return 0;
}

int PLATFORM_SendZbMacMessage(uint8_t *msg, uint32_t len)
{
    return PLATFORM_SendZbMessage((hal_imumc_handle_t)zbMacImumcHandle, msg, len);
}

int PLATFORM_InitZbPhyInterface(platform_zb_rx_callback_t callback, void *param)
{
    /* MISRA rule 11.1 forbids cast of function pointer to any other type so avoid (void)callback */
    if (callback != NULL)
    {
        ; /* intentionally */
    }
    (void)param;

    /* NOT IMPLEMENTED */
    return 0;
}

int PLATFORM_TerminateZbPhyInterface(void)
{
    /* NOT IMPLEMENTED */
    return 0;
}

int PLATFORM_ResetZbPhyInterface(void)
{
    /* NOT IMPLEMENTED */
    return 0;
}

int PLATFORM_SendZbPhyMessage(uint8_t *msg, uint32_t len)
{
    /* NOT IMPLEMENTED */
    return 0;
}

void PLATFORM_GetIeee802_15_4Addr(uint8_t *eui64_address)
{
#ifndef __ZEPHYR__
    uint16_t len = 0U;

    memset((void *)eui64_address, 0xFF, EUI_64_SZ);

    /* Get request to MAC firmware to retrieve the address from OTP memory
     * If all 0xFF is returned, fall back to a randomly generated address */
    MAC_PLATFORM_GetIeee802_15_4Addr(eui64_address);

    if (FLib_MemCmpToVal((const void *)eui64_address, 0xFFU, EUI_64_SZ) == TRUE)
    {

        if (PDM_bDoesDataExist(PDM_ID_ZPSMAC_EXTADDR, &len) == true)
        {
            assert(len == EUI_64_SZ);
            (void)PDM_eReadDataFromRecord(PDM_ID_ZPSMAC_EXTADDR, eui64_address, EUI_64_SZ, &len);
        }
        else
        {
            PLATFORM_GenerateEui64Addr(eui64_address);

            (void)PDM_eSaveRecordData(PDM_ID_ZPSMAC_EXTADDR, eui64_address, EUI_64_SZ);
        }
    }
#endif // __ZEPHYR__
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

static int PLATFORM_InitZbImumc(hal_imumc_handle_t imumcHandle, hal_imumc_config_t imumcConfig)
{
    hal_imumc_status_t imumcStatus;
    int                ret = 0;

    do
    {
        /* Init IMUMC Channel */
        imumcStatus = HAL_ImumcInit(imumcHandle, &imumcConfig);
        if (imumcStatus != kStatus_HAL_ImumcSuccess)
        {
            ret = -1;
            break;
        }
    } while (false);

    return ret;
}

static int PLATFORM_SendZbMessage(hal_imumc_handle_t imumcHandle, uint8_t *msg, uint32_t len)
{
    hal_imumc_status_t imumcStatus;
    int                ret            = 0;
    int                linkReadyRetry = 0;

    do
    {
        /* Make sure the link is ready before sending a message */
        while (PLATFORM_IsZbLinkReady() == false)
        {
            if (linkReadyRetry >= PLATFORM_ZB_IMUMC_LINK_READY_CHECK_RETRY)
            {
                ret = -1;
                break;
            }
            linkReadyRetry++;
            OSA_TimeDelay(PLATFORM_ZB_IMUMC_LINK_READY_DELAY_MS);
        }

        if (ret != 0)
        {
            break;
        }

        (void)PLATFORM_RequestBleWakeUp();

        imumcStatus = HAL_ImumcSend(imumcHandle, msg, len);
        if (imumcStatus != kStatus_HAL_ImumcSuccess)
        {
            /* An error here means the IMU link is not ready yet, we can assert here as it shouldn't happen
             * because we wait for the IMU link to be ready in PLATFORM_InitZbImumc() */
            assert(0);
            ret = -2;
            break;
        }

        (void)PLATFORM_ReleaseBleWakeUp();

    } while (false);

    return ret;
}

static hal_imumc_return_status_t PLATFORM_ZbImumcRxCallback(void *param, uint8_t *data, uint32_t len)
{
    /* MISRA rule 11.6 requires cast to non void pointer before cast to arithmetic type */
    uint32_t remoteAddr = (uint32_t)(uint32_t *)param;

    /* notify power controller the remote cpu is awake */
    (void)PLATFORM_HandleControllerPowerState();

    if (remoteAddr == PLATFORM_ZB_MAC_IMUMC_REMOTE_ADDR)
    {
        /* this is a MAC message */
        if (zbMacRxCallback != NULL)
        {
            zbMacRxCallback(data, len, zbMacCallbackParam);
        }
    }
    else
    {
        /* this must not happen */
        assert(0);
        __NOP();
    }

    return kStatus_HAL_RL_RELEASE;
}

static bool PLATFORM_IsZbLinkReady(void)
{
    return (HAL_ImuLinkIsUp(zbMacImumcConfig.imuLink) == kStatus_HAL_ImumcSuccess);
}

static void PLATFORM_GenerateEui64Addr(uint8_t *eui64_address)
{
#ifndef __ZEPHYR__
    uint8_t macAddr[EUI_64_SZ - MAC_ADDR_OUI_PART_SIZE] = {0U};

    int16_t num;

    num = RNG_GetPseudoRandomData(macAddr, EUI_64_SZ - MAC_ADDR_OUI_PART_SIZE, NULL);
    assert(num == (EUI_64_SZ - MAC_ADDR_OUI_PART_SIZE));
    (void)num;

    /* Set 3 LSB from mac address */
    memcpy((void *)eui64_address, (const void *)macAddr, EUI_64_SZ - MAC_ADDR_OUI_PART_SIZE);

    /* Set 3 MSB from OUI */
    memcpy((void *)&eui64_address[EUI_64_SZ - MAC_ADDR_OUI_PART_SIZE], (const void *)gIeee802_15_4_ADDR_OUI_c,
           MAC_ADDR_OUI_PART_SIZE);
#endif // __ZEPHYR__
}
