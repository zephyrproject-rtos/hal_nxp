/*
 * Copyright 2021-2026 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fsl_common.h"
#include "fwk_config.h"
#include "fwk_platform_ics.h"
#include "fwk_platform.h"
#include "FunctionLib.h"
#include "fsl_adapter_rpmsg.h"
#include "fsl_os_abstraction.h"
#include "fwk_debug.h"

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
#include "fwk_workq.h"
#endif

#if defined(NBU_VERSION_DBG) && (NBU_VERSION_DBG == 1)
#include "fsl_debug_console.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

#if defined(USE_RTOS) && (USE_RTOS > 0)
#define ICS_EVT_AUTO_CLEAR 1U
#else
/* In bare-metal, we manually clear event flags to avoid altering the "haveToRun" property of the waiting task
 * this is specific to OSA BM implementation */
#define ICS_EVT_AUTO_CLEAR 0U
#endif

/* Event flags */
#define ICS_EVT_NBU_API_IND (1U << 0U)
#define ICS_EVT_NBU_INF_IND (1U << 1U)

/* NBU indication wait timeout in milliseconds */
#define MAX_WAIT_NBU_IND_MS 1000U

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
#ifndef PLATFORM_ICS_RX_QUEUE_SIZE
#define PLATFORM_ICS_RX_QUEUE_SIZE (10U)
#endif
#endif

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
typedef struct
{
    uint32_t len;
    uint8_t *data;
} ics_rx_data_t;
#endif

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */
static int                       PLATFORM_WaitForIcsEvent(uint32_t event_mask, uint32_t timeout_ms);
static hal_rpmsg_return_status_t PLATFORM_FwkSrv_RxCallBack(void *param, uint8_t *data, uint32_t len);
static bool                      FwkSrv_MsgTypeInExpectedSet(uint8_t msg_type);

extern PLATFORM_FroDebugCallback_t pfPlatformDebugCallback;
PLATFORM_FroDebugCallback_t        pfPlatformDebugCallback = (void *)0;

static void PLATFORM_RxNbuInitDoneService(uint8_t *data, uint32_t len);
static void PLATFORM_RxNbuVersionIndicationService(uint8_t *data, uint32_t len);
static void PLATFORM_RxNbuApiIndicationService(uint8_t *data, uint32_t len);
static void PLATFORM_RxNbuMemFullIndicationService(uint8_t *data, uint32_t len);
static void PLATFORM_RxHostSetLowPowerConstraintService(uint8_t *data, uint32_t len);
static void PLATFORM_RxHostReleaseLowPowerConstraintService(uint8_t *data, uint32_t len);
static void PLATFORM_RxFroNotificationService(uint8_t *data, uint32_t len);
static void PLATFORM_RxFwkSrvNbuIssueIndicationService(uint8_t *data, uint32_t len);
static void PLATFORM_RxNbuSecurityEventIndicationService(uint8_t *data, uint32_t len);
static void PLATFORM_RxNbuRequestRngSeedService(uint8_t *data, uint32_t len);
static void PLATFORM_RxNbuRequestTemperature(uint8_t *data, uint32_t len);
static void PLATFORM_RxFwkSrvNbuEventIndicationService(uint8_t *data, uint32_t len);

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
static void PLATFORM_IcsRxWorkHandler(fwk_work_t *work);
#endif

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */

static RPMSG_HANDLE_DEFINE(fwkRpmsgHandle);
static const hal_rpmsg_config_t fwkRpmsgConfig = {
    .local_addr  = 110,
    .remote_addr = 100,
    .callback    = PLATFORM_FwkSrv_RxCallBack,
    .param       = NULL,
};

/* flag notifying of NBU Infor reception from CM3 */
static NbuInfo_t     g_nbu_info      = {0};
static volatile bool g_nbu_init_done = false;

static volatile bool                 m_nbu_api_rpmsg_status;
static volatile uint32_t             m_nbu_api_return_param_len;
static uint8_t                       m_nbu_api_return_param[NBU_API_MAX_RETURN_PARAM_LENGTH];
static nbu_memory_error_callback_t   nbu_mem_error_callback           = (nbu_memory_error_callback_t)NULL;
static nbu_issue_callback_t          nbu_issue_callback               = (nbu_issue_callback_t)NULL;
static nbu_event_callback_t          nbu_event_callback               = (nbu_event_callback_t)NULL;
static nbu_security_event_callback_t nbu_security_event_callback      = (nbu_security_event_callback_t)NULL;
static nbu_temp_req_event_callback_t nbu_request_temperature_callback = (nbu_temp_req_event_callback_t)NULL;

static const FwkSrv_LowPowerConstraintCallbacks_t *pLowPowerConstraintCallbacks =
    (const FwkSrv_LowPowerConstraintCallbacks_t *)NULL;

/* Array of pointer of function used in PLATFORM_FwkSrv_RxCallBack() */
static void (*PLATFORM_RxCallbackService[(uint8_t)gFwkSrvNbu2HostLast_c - (uint8_t)gFwkSrvNbu2HostFirst_c - 1U])(
    uint8_t *data, uint32_t len) = {
    PLATFORM_RxNbuInitDoneService,
    PLATFORM_RxNbuVersionIndicationService,
    PLATFORM_RxNbuApiIndicationService,
    PLATFORM_RxNbuMemFullIndicationService,
    PLATFORM_RxHostSetLowPowerConstraintService,
    PLATFORM_RxHostReleaseLowPowerConstraintService,
    PLATFORM_RxFroNotificationService,
    PLATFORM_RxFwkSrvNbuIssueIndicationService,
    PLATFORM_RxNbuSecurityEventIndicationService,
    PLATFORM_RxNbuRequestRngSeedService,
    PLATFORM_RxNbuRequestTemperature,
    PLATFORM_RxFwkSrvNbuEventIndicationService,
};

static OSA_EVENT_HANDLE_DEFINE(icsEvent);
static OSA_MUTEX_HANDLE_DEFINE(nbuApiMutex);
static OSA_MUTEX_HANDLE_DEFINE(nbuInfoMutex);

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
static OSA_MSGQ_HANDLE_DEFINE(icsMsgQueue, PLATFORM_ICS_RX_QUEUE_SIZE, sizeof(ics_rx_data_t));
static fwk_work_t ics_work = {.handler = PLATFORM_IcsRxWorkHandler};
#endif

static nbu_seed_request_event_callback_t nbu_seed_req_callback = (nbu_seed_request_event_callback_t)NULL;

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_FwkSrvInit(void)
{
    int result = 0;

    static bool_t      mFwkSrvInit  = FALSE;
    hal_rpmsg_config_t rpmsg_config = fwkRpmsgConfig;
    osa_status_t       osa_status;

    uint32_t irqMask = DisableGlobalIRQ();

    do
    {
        if (mFwkSrvInit == TRUE)
        {
            result = 1;
            break;
        }

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
        result = WORKQ_InitSysWorkQ();
        if (result < 0)
        {
            break;
        }

        /* We are using the OS message queue since it allows to allocate the memory safely (statically or during init)
         * and then copy ics_rx_data content in ISR context without allocating memory dynamically
         * This works with the workqueue only if we don't block when calling OSA_MsgQGet() */
        osa_status = OSA_MsgQCreate(icsMsgQueue, PLATFORM_ICS_RX_QUEUE_SIZE, sizeof(ics_rx_data_t));
        if (osa_status != KOSA_StatusSuccess)
        {
            assert(false);
            result = -3;
            break;
        }
#endif

        osa_status = OSA_EventCreate(icsEvent, ICS_EVT_AUTO_CLEAR);
        if (osa_status != KOSA_StatusSuccess)
        {
            assert(false);
            result = -4;
            break;
        }

        osa_status = OSA_MutexCreate(nbuApiMutex);
        if (osa_status != KOSA_StatusSuccess)
        {
            assert(false);
            result = -5;
            break;
        }

        osa_status = OSA_MutexCreate(nbuInfoMutex);
        if (osa_status != KOSA_StatusSuccess)
        {
            assert(false);
            result = -6;
            break;
        }

        if (kStatus_HAL_RpmsgSuccess != HAL_RpmsgInit((hal_rpmsg_handle_t)fwkRpmsgHandle, &rpmsg_config))
        {
            result = -2;
            break;
        }

        /* Flag initialization on module */
        mFwkSrvInit = TRUE;
    } while (false);
    EnableGlobalIRQ(irqMask);

    return result;
}

int PLATFORM_FwkSrvSendPacket(eFwkSrvMsgType msg_type, void *msg, uint16_t msg_lg)
{
    uint8_t *buf    = NULL;
    int      result = 0;
    uint32_t sz     = ((uint32_t)msg_lg + 1U);

    if (PLATFORM_IsNbuStarted() == 0)
    {
        /* If NBU is not started at all do not go further */
        result = -4;
    }
    else
    {
        /* Make sure remote CPU is awake */
        PLATFORM_RemoteActiveReq();
        do
        {
            buf = HAL_RpmsgAllocTxBuffer((hal_rpmsg_handle_t)fwkRpmsgHandle, sz);

            if (NULL == buf)
            {
                result = -1;
                break;
            }

            buf[0] = (uint8_t)msg_type;

            if (msg != NULL && msg_lg != 0U)
            {
                FLib_MemCpy(&buf[1], (uint8_t *)msg, msg_lg);
            }

            if (kStatus_HAL_RpmsgSuccess != HAL_RpmsgNoCopySend((hal_rpmsg_handle_t)fwkRpmsgHandle, buf, (uint32_t)sz))
            {
                result = -2;
                break;
            }
        } while (false);

        /* Release wake up to other CPU */
        PLATFORM_RemoteActiveRel();
    }

    return result;
}

/* Returns negative value if info is not available, 0 otherwise */
int PLATFORM_GetNbuInfo(NbuInfo_t *nbu_info_p)
{
    int          st = -1;
    osa_status_t mutex_status;

    /* Since the GetNBUInfo request waits for a receive event, we can only
     * perform one request at a time, otherwise we can't determine if the first
     * received response is for this request or for another one.
     * So, using a mutex to ensure only one request is active at a time. */
    mutex_status = OSA_MutexLock(nbuInfoMutex, osaWaitForever_c);

    do
    {
        if (mutex_status != KOSA_StatusSuccess)
        {
            st = -2;
            break;
        }
        /* Verify the destination pointer given by the caller is valid */
        if (nbu_info_p == NULL)
        {
            break;
        }

        if (!(FLib_MemCmpToVal(&g_nbu_info, 0U, sizeof(NbuInfo_t))))
        {
            /* g_nbu_info is already populated, no need to request it again */
            st = 0;
            break;
        }

        st = PLATFORM_FwkSrvSendPacket(gFwkSrvNbuVersionRequest_c, (void *)NULL, 0);
        if (0 != st)
        {
            break;
        }

        /* Wait for NBU to answer but not forever */
        if (PLATFORM_WaitForIcsEvent(ICS_EVT_NBU_INF_IND, MAX_WAIT_NBU_IND_MS) == 0)
        {
            st = 0;
        }
        else
        {
            /* default status in case NBU does not respond */
            st = -10;
        }
    } while (false);
    if (st == 0)
    {
        /* Copy the NBU info to the caller's buffer */
        FLib_MemCpy(nbu_info_p, &g_nbu_info, sizeof(NbuInfo_t));
    }

    if (mutex_status == KOSA_StatusSuccess)
    {
        /* Unlock only if lock was successful */
        (void)OSA_MutexUnlock(nbuInfoMutex);
    }

    assert(st == 0);
    return st;
}

int PLATFORM_SendChipRevision(void)
{
    uint8_t chip_rev_reg = Chip_GetVersion();
    uint8_t chip_rev     = 0xFF;
    int     ret          = -3;

    if (chip_rev_reg == DEVICE_REVISION_A0)
    {
        chip_rev = 0u;
    }
    else if (chip_rev_reg == DEVICE_REVISION_A1)
    {
        chip_rev = 1u;
    }
    else if (chip_rev_reg == DEVICE_REVISION_A2)
    {
        chip_rev = 2u;
    }
#if defined(DEVICE_REVISION_A2_1)
    else if (chip_rev_reg == DEVICE_REVISION_A2_1)
    {
        chip_rev = 21u;
    }
#endif
    else
    {
        /* MISRA compliance */
    }

    if (chip_rev != 0xFFu)
    {
        ret = PLATFORM_FwkSrvSendPacket(gFwkSrvHostChipRevision_c, (void *)&chip_rev, 1);
    }

    PWR_DBG_LOG("chip rev sent:%d", chip_rev);

    return ret;
}

bool_t PLATFORM_NbuApiReq(uint8_t *api_return, uint16_t api_id, const uint8_t *fmt, uint32_t *tab, uint32_t nb_returns)
{
    bool         rpmsg_status = true;
    bool         nbu_received = false;
    bool         nbu_rpmsg_status;
    osa_status_t mutex_status;

    /* Since the NBU API request waits for a receive event, we can only
     * perform one request at a time, otherwise we can't determine if the first
     * received response is for this request or for another one.
     * So, using a mutex to ensure only one request is active at a time. */
    mutex_status = OSA_MutexLock(nbuApiMutex, osaWaitForever_c);

    do
    {
        if (mutex_status != KOSA_StatusSuccess)
        {
            rpmsg_status = false;
            break;
        }

        /* Make sure remote CPU is awake */
        PLATFORM_RemoteActiveReq();

        /* build the message payload */
        uint8_t data[2 + NBU_API_MAX_PARAM_LENGTH];

        /* start with API identifier */
        data[0U] = (uint8_t)(api_id & 0xFFU);
        data[1U] = (uint8_t)((api_id >> 8U) & 0xFFU);

        uint16_t data_len = 2U;
        uint32_t param;
        uint32_t j = 0U;

        for (uint32_t i = 0U; fmt[i] != 0U; i++)
        {
            if ((data_len + (uint16_t)fmt[i]) > NBU_API_MAX_PARAM_LENGTH)
            {
                /* too many arguments */
                rpmsg_status = false;
                break;
            }
            else
            {
                switch (fmt[i])
                {
                    case 1U:
                        param = tab[j];
                        j++;
                        if ((((int32_t)param < INT8_MIN) || ((int32_t)param > INT8_MAX)) && (param > 0xFFU))
                        {
                            rpmsg_status = false;
                        }
                        else
                        {
                            data[data_len++] = (uint8_t)param;
                        }
                        break;

                    case 2U:
                        param = tab[j];
                        j++;
                        if ((((int32_t)param < INT16_MIN) || ((int32_t)param > INT16_MAX)) && (param > 0xFFFFU))
                        {
                            rpmsg_status = false;
                        }
                        else
                        {
                            data[data_len++] = (uint8_t)(param & 0xFFU);
                            data[data_len++] = (uint8_t)((param >> 8U) & 0xFFU);
                        }
                        break;

                    case 4U:
                        param = tab[j];
                        j++;
                        data[data_len++] = (uint8_t)(param & 0xFFU);
                        data[data_len++] = (uint8_t)((param >> 8U) & 0xFFU);
                        data[data_len++] = (uint8_t)((param >> 16U) & 0xFFU);
                        data[data_len++] = (uint8_t)((param >> 24U) & 0xFFU);
                        break;

                    default:
                        rpmsg_status = false;
                        break;
                }
            }
        }

        if (!rpmsg_status)
        {
            break;
        }

        /* send to NBU */
        if (0 != PLATFORM_FwkSrvSendPacket(gFwkSrvNbuApiRequest_c, (void *)&data, data_len))
        {
            rpmsg_status = false;
            break;
        }

        nbu_received = (PLATFORM_WaitForIcsEvent(ICS_EVT_NBU_API_IND, MAX_WAIT_NBU_IND_MS) == 0);

        assert(m_nbu_api_rpmsg_status);
        nbu_rpmsg_status = m_nbu_api_rpmsg_status;

        rpmsg_status = nbu_received && nbu_rpmsg_status;

        /* API executed */
        assert(m_nbu_api_return_param_len == nb_returns);
        FLib_MemCpy(api_return, (void *)&m_nbu_api_return_param[0], m_nbu_api_return_param_len);

        /* Release wake up to other CPU */
        PLATFORM_RemoteActiveRel();
    } while (0U != 0U);

    if (mutex_status == KOSA_StatusSuccess)
    {
        /* Unlock only if lock was successful */
        (void)OSA_MutexUnlock(nbuApiMutex);
    }

    /* return rmpsg status, API status in *api_status */
    assert(rpmsg_status);
    return rpmsg_status;
}

void PLATFORM_RegisterNbuMemErrorCallback(nbu_memory_error_callback_t cb)
{
    nbu_mem_error_callback = cb;
}

void PLATFORM_FwkSrvRegisterLowPowerCallbacks(const FwkSrv_LowPowerConstraintCallbacks_t *callbacks)
{
    pLowPowerConstraintCallbacks = callbacks;
}

void PLATFORM_FwkSrvSetRfSfcConfig(void *config, uint16_t size)
{
    assert(config != NULL);

    (void)PLATFORM_FwkSrvSendPacket(gFwkSrvNbuSetRfSfcConfig_c, config, size);
}

void PLATFORM_EnableFroNotification(int8_t enable)
{
    (void)PLATFORM_FwkSrvSendPacket(gFwkSrvFroEnableNotification_c, (void *)&enable, (uint16_t)sizeof(enable));
}

void PLATFORM_RegisterFroNotificationCallback(PLATFORM_FroDebugCallback_t cb)
{
    pfPlatformDebugCallback = cb;
}

void PLATFORM_RegisterNbuIssueCb(nbu_issue_callback_t cb)
{
    nbu_issue_callback = cb;
}

void PLATFORM_RegisterNbuEventCb(nbu_event_callback_t cb)
{
    nbu_event_callback = cb;
}

void PLATFORM_RegisterSecurityEventCb(nbu_security_event_callback_t cb)
{
    nbu_security_event_callback = cb;
}

void PLATFORM_RegisterNbuTemperatureRequestEventCb(nbu_temp_req_event_callback_t cb)
{
#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
    nbu_request_temperature_callback = cb;
#else
    /* NBU temperature request handling is only supported when gPlatformIcsUseWorkqueueRxProcessing_d is enabled */
    cb = NULL;
    (void)cb;
#endif
}

void PLATFORM_RegisterReceivedSeedRequest(nbu_seed_request_event_callback_t cb)
{
    nbu_seed_req_callback = cb;
}

int PLATFORM_SendNBUXtal32MTrim(uint8_t trim)
{
    return PLATFORM_FwkSrvSendPacket(gFwkSrvXtal32MTrimIndication_c, &trim, (uint16_t)sizeof(trim));
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */

static int PLATFORM_WaitForIcsEvent(uint32_t event_mask, uint32_t timeout_ms)
{
    int               ret   = 0;
    osa_event_flags_t flags = 0U;

#if defined(USE_RTOS) && (USE_RTOS > 0)
    (void)OSA_EventWait(icsEvent, event_mask, 1U, timeout_ms, &flags);
#else
    uint64_t start = PLATFORM_GetTimeStamp();

    /* On bare-metal, OSA_EventWait is non-blocking, so we need to poll in a loop
     * and we handle the timeout manually using timestamps */
    do
    {
#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
        /* On bare-metal systems, we need to call the work handler to process any pending messages because
         * we don't have preemptive OS */
        PLATFORM_IcsRxWorkHandler((fwk_work_t *)NULL);
#endif
    } while ((OSA_EventWait(icsEvent, event_mask, 1U, osaWaitForever_c, &flags) != KOSA_StatusSuccess) &&
             PLATFORM_IsTimeoutExpired(start, (uint64_t)timeout_ms * 1000ULL) == false);
#endif

    if ((flags & event_mask) != event_mask)
    {
        ret = -1;
    }
#if !defined(USE_RTOS) || (USE_RTOS == 0)
    else
    {
        /* In bare-metal, we manually manage flag clearing */
        (void)OSA_EventClear(icsEvent, flags);
    }
#endif

    return ret;
}

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
static void PLATFORM_IcsRxWorkHandler(fwk_work_t *work)
{
    ics_rx_data_t ics_rx_data;
    osa_status_t  status;
    (void)work;

    /* Check if there is any message in the queue
     * Important: do not set a blocking time to prevent blocking the system workqueue */
    status = OSA_MsgQGet(icsMsgQueue, (void *)&ics_rx_data, 0);

    PLATFORM_RemoteActiveReq();

    while (status == KOSA_StatusSuccess)
    {
        if ((ics_rx_data.data != NULL) && (ics_rx_data.len > 0U) && FwkSrv_MsgTypeInExpectedSet(ics_rx_data.data[0]))
        {
            uint8_t msg_type = ics_rx_data.data[0];
            PLATFORM_RxCallbackService[msg_type - 1U](ics_rx_data.data, ics_rx_data.len);

            /* Release the buffer from shared memory */
            (void)HAL_RpmsgFreeRxBuffer(fwkRpmsgHandle, ics_rx_data.data);
        }

        /* Continue until the queue is empty */
        status = OSA_MsgQGet(icsMsgQueue, (void *)&ics_rx_data, 0);
    }

    PLATFORM_RemoteActiveRel();
}
#endif

static hal_rpmsg_return_status_t PLATFORM_FwkSrv_RxCallBack(void *param, uint8_t *data, uint32_t len)
{
    hal_rpmsg_return_status_t res = kStatus_HAL_RL_RELEASE;
    uint8_t                   msg_type;
    msg_type = data[0];

    if (FwkSrv_MsgTypeInExpectedSet(msg_type))
    {
#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
        bool process_now = false;

        ics_rx_data_t ics_rx_data = {.len = len, .data = data};

        /* Submit to workqueue first, to make sure no errors occur, we push the message to the queue after.
         * If pushing to the queue fails, the work will be executed but won't do anything, so this is safe.
         * Since we are in ISR context, the workqueue thread can't execute until we exit from ISR, so this is safe
         * to do before pushing to the message queue. */
        if (WORKQ_Submit(&ics_work) < 0)
        {
            /* Process message immediately but assert as this is not a desired path */
            process_now = true;
            assert(false);
        }
        else
        {
            osa_status_t status = OSA_MsgQPut(icsMsgQueue, (void *)&ics_rx_data);
            if (status == KOSA_StatusSuccess)
            {
                /* Submission to workqueue and message queue succeeded, hold the rpmsg buffer in shared memory */
                res = kStatus_HAL_RL_HOLD;
            }
            else
            {
                /* Process message immediately but assert as this is not a desired path */
                process_now = true;
                assert(false);
            }
        }

        if (process_now == true)
#endif
        {
            /* some messages must be serviced in the ISR */
            PLATFORM_RxCallbackService[msg_type - 1U](data, len);
        }
    }
    (void)param;

    return res;
}

static void PLATFORM_RxNbuVersionIndicationService(uint8_t *data, uint32_t len)
{
    FLib_MemCpy(&g_nbu_info, &data[1], sizeof(NbuInfo_t));

#if defined(NBU_VERSION_DBG) && (NBU_VERSION_DBG == 1)
    PRINTF("NBU v%d.%d.%d\r\n", g_nbu_info.versionNumber[0], g_nbu_info.versionNumber[1], g_nbu_info.versionNumber[2]);
    PRINTF("NBU SHA %02x%02x%02x%02x\r\n", g_nbu_info.repo_digest[0], g_nbu_info.repo_digest[1],
           g_nbu_info.repo_digest[2], g_nbu_info.repo_digest[3]);
#endif
    /* no longer required to hold since copy is done in allocated pointer */

    /* Notify waiting task that NBU information has been received */
    (void)OSA_EventSet(icsEvent, ICS_EVT_NBU_INF_IND);

    NOT_USED(len);
}

static void PLATFORM_RxNbuInitDoneService(uint8_t *data, uint32_t len)
{
    g_nbu_init_done = true;
#if defined(NBU_VERSION_DBG) && (NBU_VERSION_DBG == 1)
    PRINTF("NBU Init Done\r\n");
#endif
    NOT_USED(data);
    NOT_USED(len);
}

static void PLATFORM_RxNbuMemFullIndicationService(uint8_t *data, uint32_t len)
{
    if (nbu_mem_error_callback != NULL)
    {
        NbuDbgMemInfo_t memInfo;
        FLib_MemCpy(&memInfo, &data[1], sizeof(NbuDbgMemInfo_t));
        (*nbu_mem_error_callback)((void *)&memInfo);
    }
    NOT_USED(len);
}

static void PLATFORM_RxNbuApiIndicationService(uint8_t *data, uint32_t len)
{
    /* NBU API response received, most of the case 6 bytes */
    assert(len >= 6U && len <= (uint32_t)(2U + NBU_API_MAX_RETURN_PARAM_LENGTH));
    m_nbu_api_rpmsg_status = (data[1] == 0U) ? false : true;

    m_nbu_api_return_param_len = len - 2U;
    FLib_MemCpy((void *)&m_nbu_api_return_param[0U], &data[2U], m_nbu_api_return_param_len);

    /* Notify waiting task that NBU API indication has been received */
    (void)OSA_EventSet(icsEvent, ICS_EVT_NBU_API_IND);
}

static void PLATFORM_RxHostSetLowPowerConstraintService(uint8_t *data, uint32_t len)
{
    if (pLowPowerConstraintCallbacks != NULL)
    {
        if (pLowPowerConstraintCallbacks->fwkSrvSetLowPowerConstraint != NULL)
        {
            (void)pLowPowerConstraintCallbacks->fwkSrvSetLowPowerConstraint((int32_t)(data[1]));
        }
    }
    NOT_USED(len);
}

static void PLATFORM_RxHostReleaseLowPowerConstraintService(uint8_t *data, uint32_t len)
{
    if (pLowPowerConstraintCallbacks != NULL)
    {
        if (pLowPowerConstraintCallbacks->fwkSrvReleaseLowPowerConstraint != NULL)
        {
            (void)pLowPowerConstraintCallbacks->fwkSrvReleaseLowPowerConstraint((int32_t)(data[1]));
        }
    }
    NOT_USED(len);
}

static void PLATFORM_RxFroNotificationService(uint8_t *data, uint32_t len)
{
    assert(len >= sizeof(FroInfo_t) + 1U);
    FroInfo_t fro_notif_data;

    FLib_MemCpy((void *)&fro_notif_data, (void *)&data[1], sizeof(FroInfo_t));
    pfPlatformDebugCallback(fro_notif_data.freq, fro_notif_data.ppm_mean, fro_notif_data.ppm, fro_notif_data.fro_trim);
}

static void PLATFORM_RxFwkSrvNbuIssueIndicationService(uint8_t *data, uint32_t len)
{
    if (nbu_issue_callback != NULL)
    {
        (*nbu_issue_callback)();
    }
    NOT_USED(data);
    NOT_USED(len);
}

static void PLATFORM_RxFwkSrvNbuEventIndicationService(uint8_t *data, uint32_t len)
{
    NbuEvent_t *event;

    if ((data != NULL) && (nbu_event_callback != NULL))
    {
        /* Validate packet size: msg_type + sizeof(NbuEvent_t) */
        if (len == ((uint32_t)sizeof(NbuEvent_t) + 1U))
        {
            event = (NbuEvent_t *)(void *)&data[1];
            (*nbu_event_callback)(event);
        }
        else
        {
            assert(false);
        }
    }
}

static void PLATFORM_RxNbuSecurityEventIndicationService(uint8_t *data, uint32_t len)
{
    if (nbu_security_event_callback != NULL)
    {
        uint32_t securityEventBitmask;
        FLib_MemCpy(&securityEventBitmask, &data[1], sizeof(uint32_t));
        (*nbu_security_event_callback)(securityEventBitmask);
    }
    NOT_USED(len);
}

static void PLATFORM_RxNbuRequestRngSeedService(uint8_t *data, uint32_t len)
{
    if (nbu_seed_req_callback != NULL)
    {
        (void)nbu_seed_req_callback();
    }
    NOT_USED(data);
    NOT_USED(len);
}

static void PLATFORM_RxNbuRequestTemperature(uint8_t *data, uint32_t len)
{
    uint32_t periodic_interval = 0UL;

    if (nbu_request_temperature_callback != NULL)
    {
        assert(len == (sizeof(uint32_t) + 1UL));
        /* Data corresponds to the periodic measurement interval requested by NBU (in Ms) */
        FLib_MemCpy((void *)&periodic_interval, (void *)&data[1], sizeof(uint32_t));
        (*nbu_request_temperature_callback)(periodic_interval);
    }
    (void)len;
    (void)data;
}

static bool FwkSrv_MsgTypeInExpectedSet(uint8_t msg_type)
{
    return (msg_type > (uint8_t)gFwkSrvNbu2HostFirst_c && msg_type < (uint8_t)gFwkSrvNbu2HostLast_c);
}
