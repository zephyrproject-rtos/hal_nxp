/* -------------------------------------------------------------------------- */
/*                        Copyright 2021-2023, 2025 NXP                       */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

/* Get BOARD_LL_32MHz_WAKEUP_ADVANCE_HSLOT if defined in board.h for 32MHz settings
 * BOARD_FRO32K_PPM_TARGET and BOARD_FRO32K_FILTER_SIZE for fro32k calibration settings */
#include "board_platform.h"

#include "fsl_common.h"
#include "fsl_adapter_rpmsg.h"
#include "fwk_config.h"
#include "fwk_platform_ble.h"
#include "fwk_platform.h"
#include "fwk_platform_ics.h"
#include "FunctionLib.h"
#include "RNG_Interface.h"
#include "fwk_debug.h"
#include "controller_api.h"

#if defined(gPlatformUseHwParameter_d) && (gPlatformUseHwParameter_d > 0)
#include "HWParameter.h"
#endif

#ifdef SERIAL_BTSNOOP
#include "sbtsnoop.h"
#endif

#if defined(BOARD_FRO32K_PPM_TARGET) || defined(BOARD_FRO32K_FILTER_SIZE) || \
    defined(BOARD_FRO32K_MAX_CALIBRATION_INTERVAL_MS) || defined(BOARD_FRO32K_TRIG_SAMPLE_NUMBER)
#include "fwk_sfc.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */
#define PLATFORM_BLE_BD_ADDR_RAND_PART_SIZE 3U
#define PLATFORM_BLE_BD_ADDR_OUI_PART_SIZE  3U
#define PLATFORM_BLE_BD_ADDR_FULL_SIZE      6U

#ifndef PLATFORM_BLE_HCI_TIMEOUT_MS
#define PLATFORM_BLE_HCI_TIMEOUT_MS 200U
#endif

#define mBoardUidSize_c 16

#ifndef BD_ADDR_OUI
#define BD_ADDR_OUI 0x37U, 0x60U, 0x00U
#endif

#define HciCommand(opCodeGroup, opCodeCommand) \
    (((uint16_t)(opCodeGroup) & (uint16_t)0x3FU) << (uint16_t)SHIFT10) | (uint16_t)((opCodeCommand)&0x3FFU)

#define BT_USER_BD 254

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

/*!
 * \brief Default calibration settings for the FRO32K, can be overriden in board.h with BOARD_FRO32K_PPM_TARGET
 *        and BOARD_FRO32K_FILTER_SIZE
 */
#define PLATFORM_DEFAULT_FRO32K_PPM_TARGET                  200U
#define PLATFORM_DEFAULT_FRO32K_FILTER_SIZE                 128U
#define PLATFORM_DEFAULT_FRO32K_MAX_CALIBRATION_INTERVAL_MS 1000U
#define PLATFORM_DEFAULT_FRO32K_TRIG_SAMPLE_NUMBER          3U

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */
static const uint8_t gBD_ADDR_OUI_c[PLATFORM_BLE_BD_ADDR_OUI_PART_SIZE] = {BD_ADDR_OUI};

/* RPMSG related variables */

/* Define hci serial manager handle*/
static RPMSG_HANDLE_DEFINE(hciRpmsgHandle);

/*hci rpmsg configuration*/
static const hal_rpmsg_config_t hciRpmsgConfig = {
    .local_addr  = 40,
    .remote_addr = 30,
};

static void (*hci_rx_callback)(uint8_t packetType, uint8_t *data, uint16_t len);

#if defined(BOARD_FRO32K_PPM_TARGET) || defined(BOARD_FRO32K_FILTER_SIZE) || \
    defined(BOARD_FRO32K_MAX_CALIBRATION_INTERVAL_MS) || defined(BOARD_FRO32K_TRIG_SAMPLE_NUMBER)
static const sfc_config_t sfcConfig = {
#ifdef BOARD_FRO32K_PPM_TARGET
    .ppmTarget = BOARD_FRO32K_PPM_TARGET,
#else
    .ppmTarget                = PLATFORM_DEFAULT_FRO32K_PPM_TARGET,
#endif /* BOARD_FRO32K_PPM_TARGET */
#ifdef BOARD_FRO32K_FILTER_SIZE
    .filterSize = BOARD_FRO32K_FILTER_SIZE,
#else
    .filterSize               = PLATFORM_DEFAULT_FRO32K_FILTER_SIZE,
#endif /* BOARD_FRO32K_FILTER_SIZE */
#ifdef BOARD_FRO32K_MAX_CALIBRATION_INTERVAL_MS
    .maxCalibrationIntervalMs = BOARD_FRO32K_MAX_CALIBRATION_INTERVAL_MS,
#else
    .maxCalibrationIntervalMs = PLATFORM_DEFAULT_FRO32K_MAX_CALIBRATION_INTERVAL_MS,
#endif /* BOARD_FRO32K_MAX_CALIBRATION_INTERVAL_MS */
#ifdef BOARD_FRO32K_TRIG_SAMPLE_NUMBER
    .trigSampleNumber = BOARD_FRO32K_TRIG_SAMPLE_NUMBER
#else
    .trigSampleNumber         = PLATFORM_DEFAULT_FRO32K_TRIG_SAMPLE_NUMBER,
#endif /* BOARD_FRO32K_TRIG_SAMPLE_NUMBER */
};
#endif /* BOARD_FRO32K_PPM_TARGET || BOARD_FRO32K_FILTER_SIZE ||  BOARD_FRO32K_MAX_CALIBRATION_INTERVAL_MS || \
          BOARD_FRO32K_TRIG_SAMPLE_NUMBER */

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

/*!
 * \brief Configure max TX power in dBm for BLE
 *
 * \param[in] max_tx_power Desired max TX power in dBm
 */
static void PLATFORM_SetBleMaxTxPower(int8_t max_tx_power);

#ifdef BOARD_LL_32MHz_WAKEUP_ADVANCE_HSLOT
/*!
 * \brief Send to the NBU the value of BOARD_LL_32MHz_WAKEUP_ADVANCE_HSLOT to be setted on its side
 *
 */
static void PLATFORM_SendWakeupDelay(uint8_t wakeupDelayToBeSendToNbu);
#endif

/*!
 * \brief Generate new BD address
 *
 * \param[in] Provide pointer to buffer location when the BD address should be stored
 *
 */
static void PLATFORM_GenerateNewBDAddr(uint8_t *bleDeviceAddress);

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitBle(void)
{
    int status = 0;

    do
    {
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

#if defined(BOARD_FRO32K_PPM_TARGET) || defined(BOARD_FRO32K_FILTER_SIZE) || \
    defined(BOARD_FRO32K_MAX_CALIBRATION_INTERVAL_MS) || defined(BOARD_FRO32K_TRIG_SAMPLE_NUMBER)
        PLATFORM_FwkSrvSetRfSfcConfig((void *)&sfcConfig, (uint16_t)sizeof(sfc_config_t));
#endif

        /* Send chip revision (A0 or A1) to NBU */
        status = PLATFORM_SendChipRevision();
        CHECK_AND_RAISE_ERROR(status, -6);

#ifdef BOARD_LL_32MHz_WAKEUP_ADVANCE_HSLOT
        PLATFORM_SendWakeupDelay(BOARD_LL_32MHz_WAKEUP_ADVANCE_HSLOT);
#endif

        /* Update 32MHz trim value with the one stored in HW parameters */
        PLATFORM_LoadHwParams();

        PLATFORM_SetBleMaxTxPower(gAppMaxTxPowerDbm_c);
        /* Initialize log handle for second core */
        BOARD_DBGCONFIGINITNBU(TRUE);
        // DBG_LOG_DUMP();

    } while (false);

    /* Error callback set by PLATFORM_RegisterBleErrorCallback() */
    if ((status != 0) && (pfPlatformErrorCallback != NULL))
    {
        pfPlatformErrorCallback(PLATFORM_INIT_BLE_ID, status);
    }

    return status;
}

void PLATFORM_SetHciRxCallback(void (*callback)(uint8_t packetType, uint8_t *data, uint16_t len))
{
    hci_rx_callback = callback;
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

void PLATFORM_GetBDAddr(uint8_t *bleDeviceAddress)
{
#if defined(gPlatformUseHwParameter_d) && (gPlatformUseHwParameter_d > 0)
    hardwareParameters_t *pHWParams = NULL;
    uint32_t              status;

    status = NV_ReadHWParameters(&pHWParams);

    /* FLib_MemCmpToVal mandatory to make sure BLE mac address is valid
     * because return status of NV_ReadHWParameters is 1 only at 1st read attempt */
    if ((status == gHWParameterSuccess_c) &&
        (FLib_MemCmpToVal((const void *)pHWParams->bluetooth_address, 0xFFU, PLATFORM_BLE_BD_ADDR_FULL_SIZE) == FALSE))
    {
        uint32_t regPrimask;

        regPrimask = DisableGlobalIRQ();
        FLib_MemCpy((void *)bleDeviceAddress, (const void *)pHWParams->bluetooth_address,
                    PLATFORM_BLE_BD_ADDR_FULL_SIZE);
        EnableGlobalIRQ(regPrimask);
    }
    else
    {
        uint32_t regPrimask;

        /* User can decide to use the device unique address or a random generated address with
         * gPlatformUseUniqueDeviceIdForBdAddr_d */
        PLATFORM_GenerateNewBDAddr(bleDeviceAddress);

        regPrimask = DisableGlobalIRQ();
        FLib_MemCpy((void *)pHWParams->bluetooth_address, (void *)bleDeviceAddress, PLATFORM_BLE_BD_ADDR_FULL_SIZE);

        (void)NV_WriteHWParameters();
        EnableGlobalIRQ(regPrimask);
    }
#else
    PLATFORM_GenerateNewBDAddr(bleDeviceAddress);
#endif
}

int32_t PLATFORM_EnableBleSecureKeyManagement(void)
{
    int32_t ret = 0;

    ret = PLATFORM_FwkSrvSendPacket(gFwkSrvNbuSecureModeRequest_c, NULL, 0U);

    return ret;
}

bool PLATFORM_CheckNextBleConnectivityActivity(void)
{
    DBG_LOG_DUMP();
    return true;
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

static void PLATFORM_SetBleMaxTxPower(int8_t max_tx_power)
{
#ifndef LATENCY_TESTS
    uint8_t ldo_ana_trim;

    if (max_tx_power == 0)
    {
        ldo_ana_trim = 3U;
    }
    else if (max_tx_power == 7)
    {
        ldo_ana_trim = 9U;
    }
    else
    {
        if (max_tx_power != 10)
        {
            // set to 10dBm if setting is invalid
            assert(false);
            max_tx_power = 10;
        }
        ldo_ana_trim = 15U;
    }
    /* configure max tx power in controller */
    (void)Controller_SetMaxTxPower(max_tx_power, ldo_ana_trim);
#else
    (void)max_tx_power;
#endif
}

#ifdef BOARD_LL_32MHz_WAKEUP_ADVANCE_HSLOT
static void PLATFORM_SendWakeupDelay(uint8_t wakeupDelayToBeSendToNbu)
{
    (void)PLATFORM_FwkSrvSendPacket(gFwkSrvNbuWakeupDelayLpoCycle_c, &wakeupDelayToBeSendToNbu,
                                    (uint16_t)sizeof(wakeupDelayToBeSendToNbu));
}
#endif

static void PLATFORM_GenerateNewBDAddr(uint8_t *bleDeviceAddress)
{
    uint8_t macAddr[PLATFORM_BLE_BD_ADDR_RAND_PART_SIZE] = {0U};

#if (gPlatformUseUniqueDeviceIdForBdAddr_d != 0)
    /* First need to activate the radio clock */
    PLATFORM_RemoteActiveReq();
    uint32_t uid_lsb = RADIO_CTRL->UID_LSB;
    PLATFORM_RemoteActiveRel();

    /* The UID is read out as 0 if clock is uninitalized.
     * Even when initialized UID may have been left as 0xffffffff */
    if ((uid_lsb != 0U) && (uid_lsb != UINT32_MAX))
    {
        for (int i = 0; i < PLATFORM_BLE_BD_ADDR_RAND_PART_SIZE; i++)
        {
            macAddr[i] = (uint8_t)uid_lsb & 0xffU;
            uid_lsb >>= 8;
        }
    }
    else
#endif
    {
        int ret;

        ret = RNG_Init();
        assert(ret == 0);
        (void)ret;

#ifndef FWK_RNG_DEPRECATED_API
        int num;
        num = RNG_GetPseudoRandomData(macAddr, PLATFORM_BLE_BD_ADDR_RAND_PART_SIZE, NULL);
#else
        int16_t num;
        RNG_SetPseudoRandomNoSeed(NULL);
        num = RNG_GetPseudoRandomNo(macAddr, PLATFORM_BLE_BD_ADDR_RAND_PART_SIZE, NULL);
#endif
        assert(num == PLATFORM_BLE_BD_ADDR_RAND_PART_SIZE);
        (void)num;
    }
    /* Set 3 LSB from mac address */
    FLib_MemCpy((void *)bleDeviceAddress, (const void *)macAddr, PLATFORM_BLE_BD_ADDR_RAND_PART_SIZE);

    /* Set 3 MSB from OUI */
    FLib_MemCpy((void *)&bleDeviceAddress[PLATFORM_BLE_BD_ADDR_RAND_PART_SIZE], (const void *)gBD_ADDR_OUI_c,
                PLATFORM_BLE_BD_ADDR_OUI_PART_SIZE);
}

uint64_t PLATFORM_GetDeltaTimeStamp(uint32_t controllerTimestamp)
{
    uint64_t delta = 0ULL, tstmr0 = 0ULL, ble_native_timestamp = 0ULL;

    do
    {
        uint32_t ll_timing_slot = 0U;
        uint16_t ll_timing_us   = 0U;
        uint64_t tstmr_delta_us, now;
        if (Controller_GetTimestampEx(&ll_timing_slot, &ll_timing_us, &tstmr0) != KOSA_StatusSuccess)
        {
            break;
        }
        ble_native_timestamp = (uint64_t)(ll_timing_slot)*625ULL + (uint64_t)(ll_timing_us);
        now                  = PLATFORM_GetTimeStamp();
        tstmr_delta_us       = PLATFORM_GetTimeStampDeltaUs(tstmr0, now);
        if (tstmr_delta_us > UINT32_MAX)
        {
            /* would denote of an error */
            break;
        }
        if (ble_native_timestamp < controllerTimestamp)
        {
            break;
        }
        delta = (ble_native_timestamp - controllerTimestamp);
        delta += tstmr_delta_us;
    } while (false);

    return delta;
}
