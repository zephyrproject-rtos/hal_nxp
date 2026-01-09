/* -------------------------------------------------------------------------- */
/*                        Copyright 2021-2023, 2025 NXP                       */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#ifndef __ZEPHYR__
/* Get BOARD_LL_32MHz_WAKEUP_ADVANCE_HSLOT if defined in board.h for 32MHz settings
 * BOARD_FRO32K_PPM_TARGET and BOARD_FRO32K_FILTER_SIZE for fro32k calibration settings */
#include "FunctionLib.h"
#include "board_platform.h"
#include "fwk_debug.h"
#include "RNG_Interface.h"
#include "controller_api.h"
#endif

#include "fwk_hal_macros.h"
#include "fsl_common.h"
#include "fsl_adapter_rpmsg.h"
#include "fwk_config.h"
#include "fwk_platform_ble.h"
#include "fwk_platform.h"
#include "fwk_platform_ics.h"

#if defined(gPlatformUseHwParameter_d) && (gPlatformUseHwParameter_d > 0)
#include "HWParameter.h"
#endif

#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
#include "fwk_workq.h"
#include "fsl_os_abstraction.h"
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
#ifdef __ZEPHYR__
#define DBG_LOG_DUMP(...)
#define BOARD_DBGCONFIGINITNBU(...)
#define FLib_MemCpy memcpy
#endif

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

/* 30 bit max value : timestamp is originally a 32bit integer counting quarter microseconds,
 * thence the loss of 2 bits when converted to microseconds.
 */
#define PLATFORM_BLE_TIMESTAMP_MAX 0x3fffffffUL        /* 30 bit max value : 0x3fffffffUL */
#define PLATFORM_BLE_SLOT_MAX      0x7fffffffUL        /* 31 bit max value :  */
#define PLATFORM_BLE_SLOT_USEC     625U                /* BLE slot is 625 usec */
#define PLATFORM_TSTMR_MASK        0xFFFFFFFFFFFFFFULL /* 56 bit max value */

#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
#ifndef PLATFORM_HCI_RX_QUEUE_SIZE
#define PLATFORM_HCI_RX_QUEUE_SIZE 10
#endif
#endif

/* -------------------------------------------------------------------------- */
/*                          Private type definitions                          */
/* -------------------------------------------------------------------------- */
#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
typedef struct
{
    uint32_t len;
    uint8_t *data;
} hci_rx_data_t;
#endif

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

#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
/*!
 * \brief Processes the HCI received data from the workqueue
 *
 * \param[in] work pointer to the work item
 */
static void PLATFORM_HciRxWorkHandler(fwk_work_t *work);
#endif

/*!
 * \brief Configure max TX power in dBm for BLE
 *
 * \param[in] max_tx_power Desired max TX power in dBm
 */
STATIC void PLATFORM_SetBleMaxTxPower(int8_t max_tx_power);

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
STATIC void PLATFORM_GenerateNewBDAddr(uint8_t *bleDeviceAddress);

/*!
 * \brief Compute time elapsed since ll_ts (timestamp from Rx PDU descriptor) and time retrieved by core#0
 *         by means of Controller_GetTimestampEx API
 * \param[in]  ll_ts initial timestamp value (usec unit)
 * \param[in]  ll_slot_cnt BLE slot counter (625usec) value returned by Controller_GetTimestampEx
 * \param[in]  ll_slot_offset_usec microsecond offset in slot returned by Controller_GetTimestampEx.
 *             must be in the range [0..624].
 * \return number of microseconds elapsed between ll_ts and moment when Controller_GetTimestampEx was queried.
 */
STATIC uint32_t PLATFORM_ComputeTimeDiffFromBleSlotAndSlotOffset(uint32_t ll_ts,
                                                                 uint32_t ll_slot_cnt,
                                                                 uint16_t ll_slot_offset_usec);

/*!
 * \brief Compute TSTMR ticks elapsed between call to Controller_GetTimestampEx and now.
 *
 * \param[in]  tstmr0 timestamp value returned by NBU when it treated the request from Controller_GetTimestampEx.
 *
 * \return number of microseconds elapsed between tstmr0 and now.
 */
STATIC uint32_t PLATFORM_ComputeTimeDiffNbu2HostTstmr(uint64_t tstmr0);

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */
#ifndef __ZEPHYR__
STATIC const uint8_t gBD_ADDR_OUI_c[PLATFORM_BLE_BD_ADDR_OUI_PART_SIZE] = {BD_ADDR_OUI};
#endif

static bool is_initialized = false;

/* RPMSG related variables */

/* Define hci serial manager handle*/
static RPMSG_HANDLE_DEFINE(hciRpmsgHandle);

/*hci rpmsg configuration*/
static const hal_rpmsg_config_t hciRpmsgConfig = {
    .local_addr  = 40,
    .remote_addr = 30,
    .callback    = PLATFORM_HciRpmsgRxCallback,
};

static void (*hci_rx_callback)(uint8_t packetType, uint8_t *data, uint16_t len);

#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
static OSA_MSGQ_HANDLE_DEFINE(hciMsgQueue, PLATFORM_HCI_RX_QUEUE_SIZE, sizeof(hci_rx_data_t));
static fwk_work_t hci_work = {.handler = PLATFORM_HciRxWorkHandler};
#endif

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
         * isolation. this is usually done in Low power initialization but it is necessary also
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
         *  Used to retrieve NBU version information but not restricted to this sole use.
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
    hci_rx_callback = callback;
    return 0;
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

int PLATFORM_SendHciMessageAlt(uint8_t packetType, uint8_t *msg, uint32_t len)
{
    /* not implemented */
    assert(0);
    return -1;
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

uint64_t PLATFORM_GetDeltaTimeStamp(uint32_t controllerTimestamp)
{
    uint64_t delta = 0ULL;

    do
    {
        uint64_t tstmr0         = 0ULL; /* TSTMR timestamp at which NBU returned HSLOT and quarter microsec */
        uint32_t ll_timing_slot = 0UL;  /* NBU HSLOT counter converted to count of slots */
        uint16_t ll_timing_us   = 0U;
        uint32_t tstmr_delta_us;
        uint32_t ll_time_diff;

        /* coverity[assume] controllerTimestamp <= PLATFORM_BLE_TIMESTAMP_MAX */
        /* controllerTimestamp is guaranteed to be < 2^30 by design */
        if (controllerTimestamp > PLATFORM_BLE_TIMESTAMP_MAX)
        {
            break;
        }
#ifndef __ZEPHYR__
        if (Controller_GetTimestampEx(&ll_timing_slot, &ll_timing_us, &tstmr0) != KOSA_StatusSuccess)
        {
            break;
        }
#endif
        /* Sanitize returned timestamp value, although not really useful since overflow would happen after 2284 years */
        tstmr0 &= PLATFORM_TSTMR_MASK;

        /* Controller_GetTimestampEx returns slot counter after conversion from half-slot, so a number smaller than
         * 2^31. Likewise number of microseconds is bounded by 625.
         * In order to have an arithmetic compatible with NBU, convert usec back to quarter usec and slots to half-slots.
         */
        ll_time_diff =
            PLATFORM_ComputeTimeDiffFromBleSlotAndSlotOffset(controllerTimestamp, ll_timing_slot, ll_timing_us);
        if (ll_time_diff == UINT32_MAX)
        {
            delta = 0ULL;
            break;
        }

        /* Time differences are only ever computed over relatively small numbers that fit in a 32 bit variable
         */
        tstmr_delta_us = PLATFORM_ComputeTimeDiffNbu2HostTstmr(tstmr0);
        if (tstmr_delta_us == UINT32_MAX)
        {
            delta = 0ULL;
            break;
        }
        delta = (uint64_t)tstmr_delta_us + (uint64_t)ll_time_diff;
    } while (false);
    /* if delta time difference is 0 it points out an error */
    return delta;
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

    do
    {
#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
        osa_status_t osa_status;
        status = WORKQ_InitSysWorkQ();
        if (status < 0)
        {
            assert(0);
            break;
        }

        /* We are using the OS message queue since it allows to allocate the memory safely (statically or during init)
         * and then copy hci_rx_data content in ISR context without allocating memory dynamically
         * This works with the workqueue only if we don't block when calling OSA_MsgQGet() */
        osa_status = OSA_MsgQCreate(hciMsgQueue, PLATFORM_HCI_RX_QUEUE_SIZE, sizeof(hci_rx_data_t));
        if (osa_status != KOSA_StatusSuccess)
        {
            assert(0);
            status = RAISE_ERROR(osa_status, 3);
            break;
        }
#endif

        hci_rpmsg_status = HAL_RpmsgInit((hal_rpmsg_handle_t)hciRpmsgHandle, &hci_rpmsg_config);
        if (hci_rpmsg_status != kStatus_HAL_RpmsgSuccess)
        {
            assert(0);
            status = RAISE_ERROR(hci_rpmsg_status, 1);
            break;
        }

    } while (false);

    return status;
}

static hal_rpmsg_return_status_t PLATFORM_HciRpmsgRxCallback(void *param, uint8_t *data, uint32_t len)
{
    hal_rpmsg_return_status_t ret = kStatus_HAL_RL_RELEASE;

    /* len shall be strictly positive as message shall not be empty */
    assert((len > 0U) && (len <= (uint16_t)UINT16_MAX));

    (void)param;

    if ((len > 0U) && (len <= (uint16_t)UINT16_MAX) && (hci_rx_callback != NULL))
    {
#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
        hci_rx_data_t hci_rx_data = {.len = len, .data = data};

        /* Submit to workqueue first, to make sure no errors occur, we push the message to the queue after.
         * If pushing to the queue fails, the work will be executed but won't do anything, so this is safe.
         * Since we are in ISR context, the workqueue thread can't execute until we exit from ISR, so this is safe
         * to do before pushing to the message queue. */
        if (WORKQ_Submit(&hci_work) < 0)
        {
            assert(0);
        }
        else
        {
            osa_status_t status = OSA_MsgQPut(hciMsgQueue, (void *)&hci_rx_data);
            if (status == KOSA_StatusSuccess)
            {
                /* Submission to workqueue and message queue succeeded, hold the rpmsg buffer in shared memory */
                ret = kStatus_HAL_RL_HOLD;
            }
            else
            {
                assert(0);
            }
        }
#else
        PLATFORM_RemoteActiveReq();

        hci_rx_callback(data[0], &data[1], (uint16_t)(len - 1U));

#ifdef SERIAL_BTSNOOP
        sbtsnoop_write_hci_pkt(data[0U], 1U, &data[1], (uint16_t)(len - 1U));
#endif

        PLATFORM_RemoteActiveRel();
#endif
    }

    return ret;
}

#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
static void PLATFORM_HciRxWorkHandler(fwk_work_t *work)
{
    hci_rx_data_t hci_rx_data;
    osa_status_t  status;
    (void)work;

    /* Check if there is any message in the queue
     * Important: do not set a blocking time to prevent blocking the system workqueue */
    status = OSA_MsgQGet(hciMsgQueue, (void *)&hci_rx_data, 0);

    PLATFORM_RemoteActiveReq();

    while (status == KOSA_StatusSuccess)
    {
        if ((hci_rx_data.data != NULL) && (hci_rx_data.len > 0U) && (hci_rx_data.len <= (uint16_t)UINT16_MAX) &&
            (hci_rx_callback != NULL))
        {
            hci_rx_callback(hci_rx_data.data[0], &hci_rx_data.data[1], (uint16_t)(hci_rx_data.len - 1U));

#ifdef SERIAL_BTSNOOP
            sbtsnoop_write_hci_pkt(hci_rx_data.data[0U], 1U, &hci_rx_data.data[1], (uint16_t)(hci_rx_data.len - 1U));
#endif

            /* Release the buffer from shared memory */
            (void)HAL_RpmsgFreeRxBuffer(hciRpmsgHandle, hci_rx_data.data);
        }

        /* Continue until the queue is empty */
        status = OSA_MsgQGet(hciMsgQueue, (void *)&hci_rx_data, 0);
    }

    PLATFORM_RemoteActiveRel();
}
#endif

STATIC void PLATFORM_SetBleMaxTxPower(int8_t max_tx_power)
{
#if !defined(LATENCY_TESTS) && !defined(__ZEPHYR__)
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

STATIC void PLATFORM_GenerateNewBDAddr(uint8_t *bleDeviceAddress)
{
#ifndef __ZEPHYR__
    uint8_t macAddr[PLATFORM_BLE_BD_ADDR_RAND_PART_SIZE] = {0U};

#if defined(gPlatformUseUniqueDeviceIdForBdAddr_d) && (gPlatformUseUniqueDeviceIdForBdAddr_d == 1)
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
        /* Set 3 LSB from mac address */
        FLib_MemCpy((void *)bleDeviceAddress, (const void *)macAddr, PLATFORM_BLE_BD_ADDR_RAND_PART_SIZE);

        /* Set 3 MSB from OUI */
        FLib_MemCpy((void *)&bleDeviceAddress[PLATFORM_BLE_BD_ADDR_RAND_PART_SIZE], (const void *)gBD_ADDR_OUI_c,
                    PLATFORM_BLE_BD_ADDR_OUI_PART_SIZE);
    }
    else
#elif defined(gPlatformUseUniqueDeviceIdForBdAddr_d) && (gPlatformUseUniqueDeviceIdForBdAddr_d == 2)
    if (FLib_MemCmpToVal((const void *)IFR_BLE_BD_ADDR, 0xFFU, PLATFORM_BLE_BD_ADDR_FULL_SIZE) == false)
    {
        /* Copy BLE BD address from dedicated IFR0 section */
        FLib_MemCpy((void *)bleDeviceAddress, (const void *)IFR_BLE_BD_ADDR, PLATFORM_BLE_BD_ADDR_FULL_SIZE);
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

        /* Set 3 LSB from mac address */
        FLib_MemCpy((void *)bleDeviceAddress, (const void *)macAddr, PLATFORM_BLE_BD_ADDR_RAND_PART_SIZE);

        /* Set 3 MSB from OUI */
        FLib_MemCpy((void *)&bleDeviceAddress[PLATFORM_BLE_BD_ADDR_RAND_PART_SIZE], (const void *)gBD_ADDR_OUI_c,
                    PLATFORM_BLE_BD_ADDR_OUI_PART_SIZE);
    }
#endif
}

/*!
 * \brief Compute TSTMR ticks elapsed between call to Controller_GetTimestampEx and now.
 *
 * \param[in]  tstmr0 timestamp value returned by NBU when it treated the request from Controller_GetTimestampEx.
 *
 * \return number of microseconds elapsed between tstmr0 and now.
 */
STATIC uint32_t PLATFORM_ComputeTimeDiffNbu2HostTstmr(uint64_t tstmr0)
{
    uint64_t tstmr_delta_us, now;

    /* Get current TSTMR value */
    now = PLATFORM_GetTimeStamp();
    /* Compute difference with timestamp reported by NBU when queried by Controller_GetTimestampEx */
    tstmr_delta_us = PLATFORM_GetTimeStampDeltaUs(tstmr0, now);

    /* Disregard large values because between the time reported by the call to Controller_GetTimestampEx
     * and the moment it gets treated, only a small delay can have elapsed. */
    if (tstmr_delta_us > UINT32_MAX)
    {
        tstmr_delta_us = UINT32_MAX;
    }

    tstmr_delta_us &= 0xffffffffULL;
    return (uint32_t)tstmr_delta_us;
}

/*!
 * \brief Compute time elapsed since ll_ts (timestamp from Rx PDU descriptor) and time retrieved by core#0
 *         by means of Controller_GetTimestampEx API
 * \param[in]  ll_ts initial timestamp value (usec unit)
 * \param[in]  ll_slot_cnt BLE slot counter (625usec) value returned by Controller_GetTimestampEx
 * \param[in]  ll_slot_offset_usec microsecond offset in slot returned by Controller_GetTimestampEx.
 *             must be in the range [0..624].
 * \return number of microseconds elapsed between ll_ts and moment when Controller_GetTimestampEx was queried.
 */
STATIC uint32_t PLATFORM_ComputeTimeDiffFromBleSlotAndSlotOffset(uint32_t ll_ts,
                                                                 uint32_t ll_slot_cnt,
                                                                 uint16_t ll_slot_offset_usec)
{
    /* Controller_GetTimestampEx returns slot counter after conversion from half-slot, so a number smaller than
     * 2^31. Likewise number of microseconds is bounded by 625.
     * In order to have an arithmetic compatible with NBU, convert usec back to quarter usec and slots to half-slots.
     */
    uint64_t tmp;
    uint32_t time_diff;
    uint32_t curr_ll_ts;
    uint32_t ll_timing_qus;

    /* Sanitize all parameters */
    if ((ll_slot_offset_usec >= PLATFORM_BLE_SLOT_USEC) || (ll_slot_cnt > PLATFORM_BLE_SLOT_MAX) ||
        (ll_ts > PLATFORM_BLE_TIMESTAMP_MAX))
    {
        time_diff = ~0UL; /* Return max value to indicate error */
    }
    else
    {
        /* coverity[assume] ll_slot_cnt <= PLATFORM_BLE_SLOT_MAX  */
        ll_slot_cnt &= PLATFORM_BLE_SLOT_MAX;

        /* Convert offset to quarter microseconds */
        ll_timing_qus = 4U * (uint32_t)ll_slot_offset_usec;

        /* Compute total time in quarter microseconds */
        tmp = (uint64_t)ll_slot_cnt * 2500ULL; /* 625us * 4 */
        tmp += (uint64_t)(ll_timing_qus);
        /* tmp number of quarter microseconds is in the range [0..0x4e200000000], which fits in 41 bits */
        /* Convert back to usec */
        tmp >>= 2;
        /* mask out upper 34 MSB bits */
        tmp &= (uint64_t)PLATFORM_BLE_TIMESTAMP_MAX;

        curr_ll_ts = (uint32_t)tmp;

        /* Compute time difference, handling wraparound */
        if (ll_ts <= curr_ll_ts)
        {
            /* coverity[overflow:FALSE] */
            /* the condition (ll_ts <= curr_ll_ts) guarantees that this expression remains positive */
            time_diff = (curr_ll_ts - ll_ts);
        }
        else
        {
            /* wrap occurred */
            uint64_t extended_diff = (uint64_t)PLATFORM_BLE_TIMESTAMP_MAX + 1ULL + curr_ll_ts - ll_ts;
            time_diff              = (uint32_t)extended_diff;
        }
    }
    /* coverity[return_overflow:FALSE] */
    return time_diff;
}
