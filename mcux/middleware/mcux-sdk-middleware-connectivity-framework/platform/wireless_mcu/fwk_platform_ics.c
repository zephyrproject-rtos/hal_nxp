/*
 * Copyright 2021-2025 NXP
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
#include "fsl_adapter_rpmsg.h"

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
#include "fwk_workq.h"
#include "fsl_component_generic_list.h"
#include "fsl_component_mem_manager.h"
#include "fwk_hal_macros.h"
#endif

#if defined(NBU_VERSION_DBG) && (NBU_VERSION_DBG == 1)
#include "fsl_debug_console.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

/* Number of loops we spin waiting for NBU processor to respond */
#define MAX_WAIT_NBU_RESPONSE_LOOPS 10000U

/* API wait loop counter */
#define MAX_WAIT_NBU_API_RESPONSE_LOOPS 100000000U

/* -------------------------------------------------------------------------- */
/*                                Private types                               */
/* -------------------------------------------------------------------------- */

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
typedef struct
{
    list_element_t node;
    uint32_t       len;
    uint8_t       *data;
} rx_data_t;

typedef struct
{
    fwk_work_t   work;
    list_label_t pending;
} rx_work_t;
#endif

typedef struct
{
    uint16_t freq;
    int16_t  ppm_mean;
    int16_t  ppm;
    uint16_t fro_trim;
} fro_data_t;

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */
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

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
static void PLATFORM_RxWorkHandler(fwk_work_t *work);
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
static volatile bool g_nbu_info_resp_received = false;
static NbuInfo_t    *g_nbu_info_p             = (NbuInfo_t *)NULL;
static volatile bool g_nbu_init_done          = false;

static uint32_t                      m_nbu_api_dbg_max_wait_loop = 0; /* maximum loop counter logged */
static volatile bool                 m_nbu_api_ind_received;
static volatile bool                 m_nbu_api_rpmsg_status;
static volatile uint32_t             m_nbu_api_return_param_len;
static uint8_t                       m_nbu_api_return_param[NBU_API_MAX_RETURN_PARAM_LENGTH];
static nbu_memory_error_callback_t   nbu_mem_error_callback           = (nbu_memory_error_callback_t)NULL;
static nbu_issue_callback_t          nbu_issue_callback               = (nbu_issue_callback_t)NULL;
static nbu_security_event_callback_t nbu_security_event_callback      = (nbu_security_event_callback_t)NULL;
static nbu_temp_req_event_callback_t nbu_request_temperature_callback = (nbu_temp_req_event_callback_t)NULL;

static const FwkSrv_LowPowerConstraintCallbacks_t *pLowPowerConstraintCallbacks =
    (const FwkSrv_LowPowerConstraintCallbacks_t *)NULL;

/* Array of pointer of function used in PLATFORM_FwkSrv_RxCallBack() */
static void (*PLATFORM_RxCallbackService[gFwkSrvNbu2HostLast_c - gFwkSrvNbu2HostFirst_c - 1U])(uint8_t *data,
                                                                                               uint32_t len) = {
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
};

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
static rx_work_t rx_work = {
    .work.handler = PLATFORM_RxWorkHandler,
};
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

    uint32_t irqMask = DisableGlobalIRQ();

    do
    {
        if (mFwkSrvInit == TRUE)
        {
            result = 1;
            break;
        }

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
        LIST_Init(&rx_work.pending, 0U);
        (void)WORKQ_InitSysWorkQ();
#endif

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
                memcpy(&buf[1], (uint8_t *)msg, msg_lg);
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
    int st = -1;

    do
    {
        uint32_t cnt;

        g_nbu_info_resp_received = false;

        /* Need a storage supplied by the caller to copy result from RPMSG memory */
        if (nbu_info_p == NULL)
        {
            break;
        }
        g_nbu_info_p = nbu_info_p;
        st           = PLATFORM_FwkSrvSendPacket(gFwkSrvNbuVersionRequest_c, (void *)NULL, 0);
        if (0 != st)
        {
            break;
        }
        /* Wait for NBU / CM3 to answer but not forever */
        st = -10; /*default status in case NBU does not respond */
        for (cnt = MAX_WAIT_NBU_RESPONSE_LOOPS * 10U; cnt > 0U; cnt--)
        {
            if (g_nbu_info_resp_received)
            {
                /* NBU response received */
                st = 0;
                break;
            }
        }
    } while (false);
    /* The Rx Call back has already filled the structure the global pointer can
     be cleared. Should the indication arrive late - becasue of a breakpoint in
     the CM3 for instance, the callback would simply drop the indication  */
    g_nbu_info_p = NULL;
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
    else
    {
        /* MISRA compliance */
    }

    if (chip_rev != 0xFFu)
    {
        ret = PLATFORM_FwkSrvSendPacket(gFwkSrvHostChipRevision_c, (void *)&chip_rev, 1);
    }

    return ret;
}

bool_t PLATFORM_NbuApiReq(uint8_t *api_return, uint16_t api_id, const uint8_t *fmt, uint32_t *tab, uint32_t nb_returns)
{
    bool rpmsg_status = true;
    bool nbu_rpmsg_status;

    /* Make sure remote CPU is awake */
    PLATFORM_RemoteActiveReq();

    do
    {
        /* build the message payload */
        uint8_t data[2 + NBU_API_MAX_PARAM_LENGTH];

        /* start with API identifier */
        data[0U] = (uint8_t)api_id;
        data[1U] = (uint8_t)(api_id >> 8U) & 0xffU;

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
                            data[data_len++] = (uint8_t)param;
                            data[data_len++] = (uint8_t)(param >> 8U);
                        }
                        break;

                    case 4U:
                        param = tab[j];
                        j++;
                        data[data_len++] = (uint8_t)param;
                        data[data_len++] = (uint8_t)(param >> 8U);
                        data[data_len++] = (uint8_t)(param >> 16U);
                        data[data_len++] = (uint8_t)(param >> 24U);
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
        m_nbu_api_ind_received = false;
        if (0 != PLATFORM_FwkSrvSendPacket(gFwkSrvNbuApiRequest_c, (void *)&data, data_len))
        {
            rpmsg_status = false;
            break;
        }

        /* Wait for NBU / CM3 to answer but not forever */
        uint32_t cnt          = 0;
        bool     nbu_received = m_nbu_api_ind_received;

        while ((!m_nbu_api_ind_received) && (cnt < MAX_WAIT_NBU_API_RESPONSE_LOOPS))
        {
            // wait loop
            cnt++;
            assert(cnt != MAX_WAIT_NBU_API_RESPONSE_LOOPS);
        }
        if (m_nbu_api_dbg_max_wait_loop < cnt)
        {
            // log for debug purpose
            m_nbu_api_dbg_max_wait_loop = cnt;
        }

        assert(m_nbu_api_rpmsg_status);
        nbu_rpmsg_status = m_nbu_api_rpmsg_status;

        nbu_received = m_nbu_api_ind_received;
        rpmsg_status = nbu_received && nbu_rpmsg_status;

        /* API executed */
        assert(m_nbu_api_return_param_len == nb_returns);
        memcpy(api_return, (void *)&m_nbu_api_return_param[0], m_nbu_api_return_param_len);
    } while (0U != 0U);

    /* Release wake up to other CPU */
    PLATFORM_RemoteActiveRel();

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

#if defined(gPlatformIcsUseWorkqueueRxProcessing_d) && (gPlatformIcsUseWorkqueueRxProcessing_d > 0)
static void PLATFORM_RxWorkHandler(fwk_work_t *work)
{
    list_element_t *node;
    rx_data_t      *rx_data;
    (void)work;

    node = LIST_RemoveHead(&rx_work.pending);

    while (node != NULL)
    {
        rx_data = CONTAINER_OF(node, rx_data_t, node);
        PLATFORM_RxCallbackService[rx_data->data[0] - 1U](rx_data->data, rx_data->len);
        (void)MEM_BufferFree(rx_data);
        node = LIST_RemoveHead(&rx_work.pending);
    }
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
        do
        {
            if ((msg_type != (uint8_t)gFwkSrvNbuVersionIndication_c) &&
                (msg_type != (uint8_t)gFwkSrvNbuApiIndication_c))
            {
                rx_data_t *rx_data = MEM_BufferAlloc(sizeof(rx_data_t) + len);

                if (rx_data == NULL)
                {
                    /* allocation failed - process in the ISR to avoid losing the data
                     * TODO: use the error callback mechanism to forward the error to the application */
                    process_now = true;
                    break;
                }

                rx_data->data = (uint8_t *)rx_data + sizeof(rx_data_t);
                rx_data->len  = len;
                (void)memcpy(rx_data->data, data, len);
                (void)LIST_AddTail(&rx_work.pending, &rx_data->node);
                if (WORKQ_Submit(&rx_work.work) < 0)
                {
                    process_now = true;
                    break;
                }
            }
            else
            {
                process_now = true;
                break;
            }
        } while (false);

        if (process_now == true)
#endif
        {
            /* some messages must be serviced in the ISR */
            PLATFORM_RxCallbackService[msg_type - 1U](data, len);
        }
    }
    return res;
}

static void PLATFORM_RxNbuVersionIndicationService(uint8_t *data, uint32_t len)
{
    if (g_nbu_info_p != NULL)
    {
        g_nbu_info_resp_received = true;
        memcpy(g_nbu_info_p, &data[1], sizeof(NbuInfo_t));

#if defined(NBU_VERSION_DBG) && (NBU_VERSION_DBG == 1)
        PRINTF("NBU v%d.%d.%d\r\n", g_nbu_info_p->versionNumber[0], g_nbu_info_p->versionNumber[1],
               g_nbu_info_p->versionNumber[2]);
        PRINTF("NBU SHA %02x%02x%02x%02x\r\n", g_nbu_info_p->repo_digest[0], g_nbu_info_p->repo_digest[1],
               g_nbu_info_p->repo_digest[2], g_nbu_info_p->repo_digest[3]);
#endif
        /* no longer required to hold since copy is done in allocated pointer */
    }
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
        memcpy(&memInfo, &data[1], sizeof(NbuDbgMemInfo_t));
        (*nbu_mem_error_callback)((void *)&memInfo);
    }
    NOT_USED(len);
}

static void PLATFORM_RxNbuApiIndicationService(uint8_t *data, uint32_t len)
{
    /* NBU API response received, most of the case 6 bytes */
    assert(len >= 6U && len <= (uint32_t)(2U + NBU_API_MAX_RETURN_PARAM_LENGTH));
    m_nbu_api_ind_received = true;
    m_nbu_api_rpmsg_status = (data[1] == 0U) ? false : true;

    m_nbu_api_return_param_len = len - 2U;
    memcpy((void *)&m_nbu_api_return_param[0U], &data[2U], m_nbu_api_return_param_len);
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
    assert(len >= sizeof(fro_data_t) + 1U);
    fro_data_t fro_notif_data;

    if (len >= (sizeof(fro_data_t) + 1U))
    {
        memcpy((void *)&fro_notif_data, (void *)&data[1], sizeof(fro_data_t));
        pfPlatformDebugCallback(fro_notif_data.freq, fro_notif_data.ppm_mean, fro_notif_data.ppm,
                                fro_notif_data.fro_trim);
    }
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

static void PLATFORM_RxNbuSecurityEventIndicationService(uint8_t *data, uint32_t len)
{
    if (nbu_security_event_callback != NULL)
    {
        uint32_t securityEventBitmask;
        memcpy(&securityEventBitmask, &data[1], sizeof(uint32_t));
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
    uint32_t periodic_interval = 0;

    if (nbu_request_temperature_callback != NULL)
    {
        assert(len == (sizeof(uint32_t) + 1));

        /* Data corresponds to the periodic measurement interval requested by NBU (in Ms) */
        memcpy((void *)&periodic_interval, (void *)&data[1], sizeof(uint32_t));
        (*nbu_request_temperature_callback)(periodic_interval);
    }
    (void)len;
    (void)data;
}

static bool FwkSrv_MsgTypeInExpectedSet(uint8_t msg_type)
{
    return (msg_type > (uint8_t)gFwkSrvNbu2HostFirst_c && msg_type < (uint8_t)gFwkSrvNbu2HostLast_c);
}
