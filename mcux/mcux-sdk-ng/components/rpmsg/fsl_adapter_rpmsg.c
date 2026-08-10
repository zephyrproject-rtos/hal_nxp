/*
 * Copyright 2020, 2022-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "rpmsg_lite.h"
#include "fsl_common.h"
#include "fsl_component_generic_list.h"
#include "fsl_adapter_rpmsg.h"
#include "mcmgr.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Weak function. */
#if defined(__GNUC__)
#define __WEAK_FUNC __attribute__((weak))
#elif defined(__ICCARM__)
#define __WEAK_FUNC __weak
#elif defined(__CC_ARM) || defined(__ARMCC_VERSION)
#define __WEAK_FUNC __attribute__((weak))
#elif defined(__DSC__) || defined(__CW__)
#define __WEAK_FUNC __attribute__((weak))
#endif

typedef struct _hal_rpmsg_rx_state
{
    rpmsg_rx_callback_t callback;
    void *param;
} hal_rpmsg_rx_state_t;

/*! @brief rpmsg state structure. */
typedef struct _hal_rpmsg_state
{
    uint8_t local_addr;
    uint8_t remote_addr;
    volatile uint8_t rpmsg_lite_peer_ept_is_ready;
#if defined(RL_USE_STATIC_API) && (RL_USE_STATIC_API == 1)
    struct rpmsg_lite_ept_static_context endpoint;
#endif
    struct rpmsg_lite_endpoint *pEndpoint;
    hal_rpmsg_rx_state_t rx;
} hal_rpmsg_state_t;

typedef struct _hal_rpmsg_peer_ept_state
{
    list_element_t link;
    hal_rpmsg_state_t *rpmsgHandle;
} hal_rpmsg_peer_ept_state;

/* MCMGR event latch state used by the COREUP/READY handshake.
 *
 * Primary sends COREUP pings while waiting for secondary to call
 * rpmsg_lite_remote_init() and fire APP_RPMSG_READY_EVENT_DATA.
 * Using a struct (rather than a bare uint16_t) prevents COREUP or
 * EP_READY events from accidentally clearing the READY latch.
 *
 * Note: the secondary (role==1) does NOT wait for COREUP before calling
 * rpmsg_lite_remote_init(); it fires READY on its own.  The COREUP ping
 * from primary is therefore advisory on platforms where the secondary is
 * compiled from source (RT1160, RT1170, etc.) and completely ignored by
 * prebuilt NBU images (KW43) which use the old protocol.
 */
typedef struct _rpmsg_mcmgr_event_ctx
{
    volatile uint16_t last_event;
    volatile uint8_t  ready_seen;
    volatile uint8_t  coreup_seen;
} rpmsg_mcmgr_event_ctx_t;

static rpmsg_mcmgr_event_ctx_t s_mcmgrEventCtx = {0};

#ifndef RPMSG_GLOBAL_VARIABLE_ALLOC
#if (defined(HAL_RPMSG_SELECT_ROLE) && (HAL_RPMSG_SELECT_ROLE == 0U))
#ifndef SH_MEM_TOTAL_SIZE
#define SH_MEM_TOTAL_SIZE                                                                               \
    (2U * RL_BUFFER_COUNT * (RL_WORD_ALIGN_UP(RL_BUFFER_PAYLOAD_SIZE + sizeof(struct rpmsg_std_hdr))) + \
     RL_VRING_OVERHEAD)
#endif                  /* SH_MEM_TOTAL_SIZE */
#if defined(__ICCARM__) /* IAR Workbench */
#pragma location = "rpmsg_sh_mem_section"
static char rpmsg_lite_base[SH_MEM_TOTAL_SIZE];
#elif defined(__CC_ARM) || defined(__ARMCC_VERSION) /* Keil MDK */
static char rpmsg_lite_base[SH_MEM_TOTAL_SIZE] __attribute__((section("rpmsg_sh_mem_section")));
#elif defined(__GNUC__)
static char rpmsg_lite_base[SH_MEM_TOTAL_SIZE] __attribute__((section(".noinit.$rpmsg_sh_mem")));
#else
#error "RPMsg: Please provide your definition of rpmsg_lite_base[]!"
#endif
#endif /* HAL_RPMSG_SELECT_ROLE */

extern uint32_t rpmsg_sh_mem_start[];
extern uint32_t rpmsg_sh_mem_end[];
#else

#if (defined(HAL_RPMSG_SELECT_ROLE) && (HAL_RPMSG_SELECT_ROLE == 0U))
#ifndef SH_MEM_TOTAL_SIZE
#define SH_MEM_TOTAL_SIZE (6144U)
#endif /* SH_MEM_TOTAL_SIZE */
extern char *rpmsg_lite_base;
#endif /* HAL_RPMSG_SELECT_ROLE */

extern uint32_t rpmsg_sh_mem_start[];
extern uint32_t rpmsg_sh_mem_end[];
#endif /* RPMSG_GLOBAL_VARIABLE_ALLOC */

#define RPMSG_LITE_LINK_ID (0U)

#define APP_RPMSG_COREUP_EVENT_DATA   (0U)
#define APP_RPMSG_READY_EVENT_DATA    (1U)
#define APP_RPMSG_EP_READY_EVENT_DATA (2U)

#ifndef RPMSG_REMOTE_READY_RETRY_COUNT
#define RPMSG_REMOTE_READY_RETRY_COUNT 10000000U
#endif

/* Delay (ms) inserted after rpmsg_lite_master_init() returns and before
 * s_rpmsgEptCount is set to 0 (which gates HAL_RpmsgInit).  On IMU/wireless
 * boards (NBU ~64 MHz) the remote needs time to process the link-up kick,
 * exit rpmsg_lite_is_link_up(), complete HAL_RpmsgMcmgrRemoteInit(), and
 * call HAL_RpmsgInit() to register its endpoint before primary fires
 * EP_READY and sends.  Default 0 = no-op on standard boards.  Override
 * per-board via reconfig.cmake: -DRPMSG_MASTER_INIT_DELAY_MS=5 */
#ifndef RPMSG_MASTER_INIT_DELAY_MS
#define RPMSG_MASTER_INIT_DELAY_MS 0U
#endif

static int32_t s_rpmsgEptCount                    = -1;
static uint8_t s_peerRpmsgEptCount                = 0U;
static struct rpmsg_lite_instance *s_rpmsgContext = NULL;
#if defined(RL_USE_STATIC_API) && (RL_USE_STATIC_API == 1)
static struct rpmsg_lite_instance s_context = {0};
#endif
static uint8_t s_rpmsg_init_global                               = 0U;
static list_label_t s_rpmsgEpList                                = {0};
static volatile uint8_t s_rpmsgPeerEptData[MAX_EP_COUNT]         = {0};
static hal_rpmsg_peer_ept_state s_rpmsgPeerEptStat[MAX_EP_COUNT] = {0};
/*******************************************************************************
 * Code
 ******************************************************************************/
/*
 * This function is used for periodic check if the rpmsg endpoint is ready, and will be called in rpmsg send..
 * RPMsg_EpReadyTimeDelay is a weak function, so it could be re-implemented by
 * upper layer.
 */
__WEAK_FUNC void RPMsg_EpReadyTimeDelay(uint32_t ms);
__WEAK_FUNC void RPMsg_EpReadyTimeDelay(uint32_t ms)
{
    /* Reserved*/
}
#if 0  /* Reserved API */
static uint16_t rpmsg_lite_recv_ack_flag;

void rpmsg_ack_init(void)
{
    rpmsg_lite_recv_ack_flag = 0U;
    (void)MCMGR_RegisterEvent(kMCMGR_RemoteApplicationEvent, RPMsgPeerReadyEventHandler,
                              (void *)&rpmsg_lite_recv_ack_flag);
}

void rpmsg_recv_ack(void)
{
    (void)MCMGR_TriggerEvent(kMCMGR_Core0, kMCMGR_RemoteApplicationEvent, 1U);
}

void rpmsg_wait_ack(void)
{
    while (1U != rpmsg_lite_recv_ack_flag)
        ;
}
#endif /* Reserved API */

static int32_t rpmsg_ept_read_cb(void *payload, uint32_t payload_len, uint32_t src, void *priv)
{
    hal_rpmsg_state_t *rpmsgHandle;

    rpmsgHandle = (hal_rpmsg_state_t *)priv;
    assert(NULL != rpmsgHandle->rx.callback);

    return rpmsgHandle->rx.callback(rpmsgHandle->rx.param, payload, payload_len);
}

static void RPMsgPeerReadyEventHandler(mcmgr_core_t coreNum, uint16_t eventData, void *context)
{
    rpmsg_mcmgr_event_ctx_t *ctx = (rpmsg_mcmgr_event_ctx_t *)context;
    list_element_handle_t list_element;
    hal_rpmsg_peer_ept_state *rpmsgPeerEptState;
    uint8_t address = 0U;

    (void)coreNum;

    /* Capture last event for debug. */
    ctx->last_event = eventData;

    /* Latch READY and COREUP events separately so they cannot overwrite each
     * other (a COREUP ping arriving while we wait for READY must not clear the
     * READY latch, and vice versa). */
    if (eventData == APP_RPMSG_READY_EVENT_DATA)
    {
        ctx->ready_seen = 1U;
        return;
    }

    if (eventData == APP_RPMSG_COREUP_EVENT_DATA)
    {
        ctx->coreup_seen = 1U;
        return;
    }

    /* EP_READY: record peer endpoint address and mark handle ready. */
    if ((eventData & 0xff00U) == (APP_RPMSG_EP_READY_EVENT_DATA << 0x8U))
    {
        address = (uint8_t)(eventData & 0xffU);
        if (s_peerRpmsgEptCount < MAX_EP_COUNT)
        {
            s_rpmsgPeerEptData[s_peerRpmsgEptCount++] = address;
        }
    }

    list_element = LIST_GetHead(&s_rpmsgEpList);
    while (NULL != list_element)
    {
        rpmsgPeerEptState = (hal_rpmsg_peer_ept_state *)(void *)list_element;

        if ((rpmsgPeerEptState->rpmsgHandle != NULL) && (rpmsgPeerEptState->rpmsgHandle->remote_addr == address))
        {
            rpmsgPeerEptState->rpmsgHandle->rpmsg_lite_peer_ept_is_ready = 1U;
        }
        list_element = LIST_GetNext(list_element);
    }
}

#if (defined(HAL_RPMSG_SELECT_ROLE) && (HAL_RPMSG_SELECT_ROLE == 0U))
static hal_rpmsg_status_t HAL_RpmsgMcmgrMasterInit(void)
{
    volatile uint32_t timeout = RPMSG_REMOTE_READY_RETRY_COUNT;

    if (0 > s_rpmsgEptCount)
    {
        if (0U == s_rpmsg_init_global)
        {
            s_rpmsg_init_global = 1U;
            LIST_Init((&s_rpmsgEpList), 0);
            (void)MCMGR_RegisterEvent(kMCMGR_RemoteApplicationEvent, RPMsgPeerReadyEventHandler,
                                      (void *)&s_mcmgrEventCtx);
            (void)MCMGR_Init();
            if (MCMGR_StartCore(kMCMGR_Core1, (void *)(char *)REMOTE_CORE_BOOT_ADDRESS, 2, kMCMGR_Start_Asynchronous) !=
                kStatus_MCMGR_Success)
            {
                return kStatus_HAL_RpmsgError;
            }
        }

        /* Wait for secondary to call rpmsg_lite_remote_init() and fire READY.
         * Send periodic COREUP pings so that on fast cores (CM7 @ 600 MHz) the
         * effective wait window is seconds rather than ~50 ms.
         * On kw43 the prebuilt NBU ignores the COREUP pings and fires READY on
         * its own; the ping is therefore harmless on all platforms. */
        s_mcmgrEventCtx.ready_seen = 0U;
        while (0U == s_mcmgrEventCtx.ready_seen)
        {
            volatile uint32_t ping_wait;
            if (--timeout == 0u)
            {
                return kStatus_HAL_RpmsgTimeout;
            }
            (void)MCMGR_TriggerEvent(kMCMGR_Core1, kMCMGR_RemoteApplicationEvent, APP_RPMSG_COREUP_EVENT_DATA);
            /* Wait up to ~100 000 iterations for READY before re-pinging. */
            ping_wait = 100000U;
            while ((0U == s_mcmgrEventCtx.ready_seen) && (--ping_wait != 0u))
            {
            }
        }

        /* Remote ISR is live -- master_init virtqueue kick goes to live ISR. */
#if defined(RL_USE_STATIC_API) && (RL_USE_STATIC_API == 1)
        s_rpmsgContext = rpmsg_lite_master_init((void *)rpmsg_lite_base, SH_MEM_TOTAL_SIZE, RPMSG_LITE_LINK_ID,
                                                RL_NO_FLAGS, &s_context);
#else
        s_rpmsgContext =
            rpmsg_lite_master_init((void *)rpmsg_lite_base, SH_MEM_TOTAL_SIZE, RPMSG_LITE_LINK_ID, RL_NO_FLAGS);
#endif
        if (RL_NULL == s_rpmsgContext)
        {
            return kStatus_HAL_RpmsgError;
        }

#if (RPMSG_MASTER_INIT_DELAY_MS > 0U)
        env_sleep_msec(RPMSG_MASTER_INIT_DELAY_MS);
#endif

        s_rpmsgEptCount = 0;
    }

    return kStatus_HAL_RpmsgSuccess;
}
static hal_rpmsg_status_t HAL_RpmsgMasterInit(hal_rpmsg_handle_t handle, hal_rpmsg_config_t *config)
{
    hal_rpmsg_state_t *rpmsgHandle;
    rpmsgHandle = (hal_rpmsg_state_t *)handle;

    rpmsgHandle->local_addr  = config->local_addr;
    rpmsgHandle->remote_addr = config->remote_addr;

    rpmsgHandle->rx.callback = NULL;
    rpmsgHandle->rx.param    = NULL;
#if defined(RL_USE_STATIC_API) && (RL_USE_STATIC_API == 1)
    rpmsgHandle->pEndpoint = rpmsg_lite_create_ept(s_rpmsgContext, rpmsgHandle->local_addr, rpmsg_ept_read_cb,
                                                   rpmsgHandle, &rpmsgHandle->endpoint);
#else
    rpmsgHandle->pEndpoint =
        rpmsg_lite_create_ept(s_rpmsgContext, rpmsgHandle->local_addr, rpmsg_ept_read_cb, rpmsgHandle);
#endif
    if (RL_NULL == rpmsgHandle->pEndpoint)
    {
        return kStatus_HAL_RpmsgError;
    }

    return kStatus_HAL_RpmsgSuccess;
}
#endif /* HAL_RPMSG_SELECT_ROLE */

#if (defined(HAL_RPMSG_SELECT_ROLE) && (HAL_RPMSG_SELECT_ROLE == 1U))
static hal_rpmsg_status_t HAL_RpmsgMcmgrRemoteInit(void)
{
    uint32_t startupData;
    mcmgr_status_t status;
    volatile uint32_t timeout;

    if (0 > s_rpmsgEptCount)
    {
        if (0U == s_rpmsg_init_global)
        {
            LIST_Init((&s_rpmsgEpList), 0);
            s_rpmsg_init_global = 1U;
            (void)MCMGR_RegisterEvent(kMCMGR_RemoteApplicationEvent, RPMsgPeerReadyEventHandler,
                                      (void *)&s_mcmgrEventCtx);
            (void)MCMGR_Init();
            do
            {
                status = MCMGR_GetStartupData(kMCMGR_Core0, &startupData);
            } while (status != kStatus_MCMGR_Success);
        }

        /* Wait for a COREUP ping from primary before rpmsg_lite_remote_init()
         * and the subsequent READY trigger.  Primary sends COREUP only after
         * it has cleared its ready_seen latch and is actively waiting, so our
         * READY can never be lost on an init/deinit/reinit cycle (the lost-
         * READY race that otherwise deadlocks both cores on fast SoCs).
         * Bounded wait: if no COREUP arrives we fall back to firing READY
         * anyway, degrading to legacy behaviour rather than hanging.  This
         * path is only compiled for source-built secondaries; the prebuilt
         * NBU (kw43) uses its own firmware and is unaffected. */
        timeout = RPMSG_REMOTE_READY_RETRY_COUNT;
        while ((0U == s_mcmgrEventCtx.coreup_seen) && (--timeout != 0u))
        {
        }
        s_mcmgrEventCtx.coreup_seen = 0U;

#if defined(RL_USE_STATIC_API) && (RL_USE_STATIC_API == 1)
        s_rpmsgContext =
            rpmsg_lite_remote_init((void *)(char *)rpmsg_sh_mem_start, RPMSG_LITE_LINK_ID, RL_NO_FLAGS, &s_context);
#else
        s_rpmsgContext = rpmsg_lite_remote_init((void *)(char *)rpmsg_sh_mem_start, RPMSG_LITE_LINK_ID, RL_NO_FLAGS);
#endif
        if (RL_NULL == s_rpmsgContext)
        {
            return kStatus_HAL_RpmsgError;
        }

        /* Trigger event notify master */
        (void)MCMGR_TriggerEvent(kMCMGR_Core0, kMCMGR_RemoteApplicationEvent, APP_RPMSG_READY_EVENT_DATA);
        do
        {
        } while (RL_TRUE != rpmsg_lite_is_link_up(s_rpmsgContext));

        /* rpmsg initialized */
        s_rpmsgEptCount = 0;
    }
    return kStatus_HAL_RpmsgSuccess;
}
static hal_rpmsg_status_t HAL_RpmsgRemoteInit(hal_rpmsg_handle_t handle, hal_rpmsg_config_t *config)
{
    hal_rpmsg_state_t *rpmsgHandle;

    rpmsgHandle = (hal_rpmsg_state_t *)handle;

    /* Set local/remote addr */
    rpmsgHandle->local_addr  = config->local_addr;
    rpmsgHandle->remote_addr = config->remote_addr;

    rpmsgHandle->rx.callback = NULL;
    rpmsgHandle->rx.param    = NULL;
#if defined(RL_USE_STATIC_API) && (RL_USE_STATIC_API == 1)
    rpmsgHandle->pEndpoint = rpmsg_lite_create_ept(s_rpmsgContext, rpmsgHandle->local_addr, rpmsg_ept_read_cb,
                                                   rpmsgHandle, &rpmsgHandle->endpoint);
#else
    rpmsgHandle->pEndpoint =
        rpmsg_lite_create_ept(s_rpmsgContext, rpmsgHandle->local_addr, rpmsg_ept_read_cb, rpmsgHandle);
#endif

    if (RL_NULL == rpmsgHandle->pEndpoint)
    {
        return kStatus_HAL_RpmsgError;
    }

    return kStatus_HAL_RpmsgSuccess;
}
#endif /* HAL_RPMSG_SELECT_ROLE */

hal_rpmsg_status_t HAL_RpmsgMcmgrInit(void)
{
    hal_rpmsg_status_t state = kStatus_HAL_RpmsgError;

#if (defined(HAL_RPMSG_SELECT_ROLE) && (HAL_RPMSG_SELECT_ROLE == 0U))
    state = HAL_RpmsgMcmgrMasterInit();
#elif (defined(HAL_RPMSG_SELECT_ROLE) && (HAL_RPMSG_SELECT_ROLE == 1U))
    state = HAL_RpmsgMcmgrRemoteInit();
#endif /* HAL_RPMSG_SELECT_ROLE */

    return state;
}
hal_rpmsg_status_t HAL_RpmsgInit(hal_rpmsg_handle_t handle, hal_rpmsg_config_t *config)
{
    hal_rpmsg_status_t state;
    hal_rpmsg_state_t *rpmsgHandle;
    uint8_t count = 0;
    uint8_t i;

    assert(HAL_RPMSG_HANDLE_SIZE >= sizeof(hal_rpmsg_state_t));
    assert(NULL != handle);
    rpmsgHandle = (hal_rpmsg_state_t *)handle;

    /* Ensure HAL_RpmsgMcmgrInit has been called */
    if (s_rpmsgEptCount < 0)
    {
        return kStatus_HAL_RpmsgError;
    }

    /* Reset peer-endpoint-ready flag so the spin-wait in HAL_RpmsgSendTimeout
     * always waits for the fresh EP_READY event on every init/deinit cycle.
     * Without this the flag left over from a previous cycle would make the
     * sender proceed before the peer has actually re-created its endpoint. */
    rpmsgHandle->rpmsg_lite_peer_ept_is_ready = 0U;

#if (defined(HAL_RPMSG_SELECT_ROLE) && (HAL_RPMSG_SELECT_ROLE == 0U))
    state = HAL_RpmsgMasterInit(handle, config);
#elif (defined(HAL_RPMSG_SELECT_ROLE) && (HAL_RPMSG_SELECT_ROLE == 1U))
    state = HAL_RpmsgRemoteInit(handle, config);
#endif /* HAL_RPMSG_SELECT_ROLE */
    rpmsgHandle->rx.callback = config->callback;
    rpmsgHandle->rx.param    = config->param;

    /* Send peer endpoint ready to peer device */
#if (defined(HAL_RPMSG_SELECT_ROLE) && (HAL_RPMSG_SELECT_ROLE == 0U))
    (void)MCMGR_TriggerEvent(kMCMGR_Core1, kMCMGR_RemoteApplicationEvent,
                             APP_RPMSG_EP_READY_EVENT_DATA << 0x8U | config->local_addr);
#else
    (void)MCMGR_TriggerEvent(kMCMGR_Core0, kMCMGR_RemoteApplicationEvent,
                             APP_RPMSG_EP_READY_EVENT_DATA << 0x8U | config->local_addr);
#endif

    /* Find an available slot in s_rpmsgPeerEptStat */
    for (i = 0U; i < MAX_EP_COUNT; i++)
    {
        if (s_rpmsgPeerEptStat[i].rpmsgHandle == NULL)
        {
            s_rpmsgPeerEptStat[i].rpmsgHandle = rpmsgHandle;
            (void)LIST_AddTail(&s_rpmsgEpList, (list_element_handle_t)&s_rpmsgPeerEptStat[i]);
            s_rpmsgEptCount++;
            break;
        }
    }

    if (i == MAX_EP_COUNT)
    {
        return kStatus_HAL_RpmsgError;
    }

    while (count < s_peerRpmsgEptCount)
    {
        if (rpmsgHandle->remote_addr == s_rpmsgPeerEptData[count++])
        {
            rpmsgHandle->rpmsg_lite_peer_ept_is_ready = 1U;
        }
    }

    return state;
}

hal_rpmsg_status_t HAL_RpmsgDeinit(hal_rpmsg_handle_t handle)
{
    hal_rpmsg_state_t *rpmsgHandle;
    uint8_t i;

    rpmsgHandle = (hal_rpmsg_state_t *)handle;

    if (s_rpmsgEptCount > 0)
    {
        (void)rpmsg_lite_destroy_ept(s_rpmsgContext, rpmsgHandle->pEndpoint);
        /* Remove this endpoint's peer-state entry from the event list so the
         * ISR handler does not walk stale pointers after deinit.
         * Zero the link field so the struct is clean when reused by the
         * next LIST_AddTail call (stale next/prev pointers corrupt the list). */
        for (i = 0U; i < MAX_EP_COUNT; i++)
        {
            if (s_rpmsgPeerEptStat[i].rpmsgHandle == rpmsgHandle)
            {
                (void)LIST_RemoveElement((list_element_handle_t)&s_rpmsgPeerEptStat[i]);
                (void)memset(&s_rpmsgPeerEptStat[i].link, 0, sizeof(s_rpmsgPeerEptStat[i].link));
                s_rpmsgPeerEptStat[i].rpmsgHandle = NULL;
                s_rpmsgEptCount--;
                break;
            }
        }
    }

    if (0 == s_rpmsgEptCount)
    {
        s_rpmsgEptCount             = -1;
        s_peerRpmsgEptCount         = 0U;
        /* Reset COREUP/READY handshake state so the next McmgrInit cycle
         * re-runs the READY wait cleanly. */
        s_mcmgrEventCtx.ready_seen  = 0U;
        s_mcmgrEventCtx.coreup_seen = 0U;
        (void)memset((void *)s_rpmsgPeerEptData, 0, sizeof(s_rpmsgPeerEptData));
        (void)rpmsg_lite_deinit(s_rpmsgContext);
        s_rpmsgContext = NULL;
        for (i = 0U; i < MAX_EP_COUNT; i++)
        {
            s_rpmsgPeerEptStat[i].rpmsgHandle = NULL;
        }
    }

    return kStatus_HAL_RpmsgSuccess;
}

hal_rpmsg_status_t HAL_RpmsgSendTimeout(hal_rpmsg_handle_t handle, uint8_t *data, uint32_t length, uint32_t timeout)
{
    hal_rpmsg_state_t *rpmsgHandle;
    hal_rpmsg_status_t status = kStatus_HAL_RpmsgSuccess;

#if defined(HDI_MODE) && (HDI_MODE == 1)
    uint32_t primask;
#endif

    int32_t rpmsgStatus;
    volatile uint32_t epTimeout = RPMSG_REMOTE_READY_RETRY_COUNT;
    assert(NULL != data);

    rpmsgHandle = (hal_rpmsg_state_t *)handle;
    /* loop check peer device rpmsg endpoint is ready */
    while ((0 == rpmsgHandle->rpmsg_lite_peer_ept_is_ready) && (--epTimeout != 0u))
    {
    }
    if (epTimeout == 0u)
    {
        return kStatus_HAL_RpmsgTimeout;
    }

#if defined(HDI_MODE) && (HDI_MODE == 1)
    /* In HDI mode this function can be called from ISR therefore,
     * we need to disable interrupt when this configuration is enabled */
    primask = DisableGlobalIRQ();
#endif

    do
    {
        if (RL_TRUE != rpmsg_lite_is_link_up(s_rpmsgContext))
        {
            status = kStatus_HAL_RpmsgError;
            break;
        }
        rpmsgStatus = rpmsg_lite_send(s_rpmsgContext, rpmsgHandle->pEndpoint, rpmsgHandle->remote_addr, (char *)data,
                                      length, timeout);
        if (RL_SUCCESS != rpmsgStatus)
        {
            if (RL_ERR_NO_MEM == rpmsgStatus)
            {
                status = kStatus_HAL_RpmsgTimeout;
            }
            else
            {
                status = kStatus_HAL_RpmsgError;
            }
            break;
        }
    } while (false);

#if defined(HDI_MODE) && (HDI_MODE == 1)
    EnableGlobalIRQ(primask);
#endif

    return status;
}
hal_rpmsg_status_t HAL_RpmsgSend(hal_rpmsg_handle_t handle, uint8_t *data, uint32_t length)
{
    return HAL_RpmsgSendTimeout(handle, data, length, RPMSG_WAITFOREVER);
}

void *HAL_RpmsgAllocTxBuffer(hal_rpmsg_handle_t handle, uint32_t size)
{
    return HAL_RpmsgAllocTxBufferTimeout(handle, size, RPMSG_WAITFOREVER);
}

void *HAL_RpmsgAllocTxBufferTimeout(hal_rpmsg_handle_t handle, uint32_t size, uint32_t timeout)
{
    void *buf = NULL;
#if defined(HDI_MODE) && (HDI_MODE == 1)
    /* In HDI mode this function can be called from ISR therefore,
     * we need to disable interrupt when this configuration is enabled */
    uint32_t primask;
    primask = DisableGlobalIRQ();
#endif
    buf = rpmsg_lite_alloc_tx_buffer(s_rpmsgContext, &size, timeout);
#if defined(HDI_MODE) && (HDI_MODE == 1)
    EnableGlobalIRQ(primask);
#endif
    return buf;
}

hal_rpmsg_status_t HAL_RpmsgFreeRxBuffer(hal_rpmsg_handle_t handle, uint8_t *data)
{
    hal_rpmsg_status_t status = kStatus_HAL_RpmsgSuccess;
#if defined(HDI_MODE) && (HDI_MODE == 1)
    /* In HDI mode this function can be called from ISR therefore,
     * we need to disable interrupt when this configuration is enabled */
    uint32_t primask;
    primask = DisableGlobalIRQ();
#endif
    if (RL_SUCCESS != rpmsg_lite_release_rx_buffer(s_rpmsgContext, data))
    {
        status = kStatus_HAL_RpmsgError;
    }
#if defined(HDI_MODE) && (HDI_MODE == 1)
    EnableGlobalIRQ(primask);
#endif
    return status;
}

hal_rpmsg_status_t HAL_RpmsgNoCopySend(hal_rpmsg_handle_t handle, uint8_t *data, uint32_t length)
{
    hal_rpmsg_state_t *rpmsgHandle;
    hal_rpmsg_status_t status = kStatus_HAL_RpmsgSuccess;
#if defined(HDI_MODE) && (HDI_MODE == 1)
    uint32_t primask;
#endif
    rpmsgHandle                 = (hal_rpmsg_state_t *)handle;
    volatile uint32_t epTimeout = RPMSG_REMOTE_READY_RETRY_COUNT;

    /* loop check peer device rpmsg endpoint is ready */
    while ((0 == rpmsgHandle->rpmsg_lite_peer_ept_is_ready) && (--epTimeout != 0u))
    {
    }

    if (epTimeout == 0u)
    {
        return kStatus_HAL_RpmsgTimeout;
    }

#if defined(HDI_MODE) && (HDI_MODE == 1)
    /* In HDI mode this function can be called from ISR therefore,
     * we need to disable interrupt when this configuration is enabled */
    primask = DisableGlobalIRQ();
#endif
    assert(NULL != data);

    do
    {
        if (RL_TRUE != rpmsg_lite_is_link_up(s_rpmsgContext))
        {
            status = kStatus_HAL_RpmsgError;
            break;
        }

        if (RL_SUCCESS != rpmsg_lite_send_nocopy(s_rpmsgContext, rpmsgHandle->pEndpoint, rpmsgHandle->remote_addr,
                                                 (char *)data, length))
        {
            status = kStatus_HAL_RpmsgError;
            break;
        }
    } while (false);

#if defined(HDI_MODE) && (HDI_MODE == 1)
    EnableGlobalIRQ(primask);
#endif

    return status;
}
hal_rpmsg_status_t HAL_RpmsgInstallRxCallback(hal_rpmsg_handle_t handle, rpmsg_rx_callback_t callback, void *param)
{
    hal_rpmsg_state_t *rpmsgHandle;

    rpmsgHandle = (hal_rpmsg_state_t *)handle;

    rpmsgHandle->rx.callback = callback;
    rpmsgHandle->rx.param    = param;

    return kStatus_HAL_RpmsgSuccess;
}

hal_rpmsg_status_t HAL_RpmsgEnterLowpower(hal_rpmsg_handle_t handle)
{
    return kStatus_HAL_RpmsgError;
}

hal_rpmsg_status_t HAL_RpmsgExitLowpower(hal_rpmsg_handle_t handle)
{
    return kStatus_HAL_RpmsgError;
}

uint32_t HAL_RpmsgAllBufferConsumed(void)
{
    return rpmsg_lite_are_all_buffers_consumed(s_rpmsgContext);
}
