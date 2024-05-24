/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_adapter_rfcommon.h"
#include "fsl_adapter_rpmsg.h"
#include "fsl_adapter_rfimu.h"
#if defined(IMU_GDMA_ENABLE) && (IMU_GDMA_ENABLE == 1)
#include "fsl_gdma.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#if defined(configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY)
#ifndef IMU_ISR_PRIORITY
#define IMU_ISR_PRIORITY (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY)
#endif
#else
#ifndef IMU_ISR_PRIORITY
#define IMU_ISR_PRIORITY (2U)
#endif
#endif

#ifndef IMU_LINK_WAIT_DELAY_MS
#define IMU_LINK_WAIT_DELAY_MS 1U
#endif

#ifndef RPMSG_ALLOC_FAILED_DELAY_MS
#define RPMSG_ALLOC_FAILED_DELAY_MS 1U
#endif

#ifndef RPMSG_ALLOC_RETRY_COUNT
#define RPMSG_ALLOC_RETRY_COUNT 10U
#endif

#if defined(CPU2)
#define os_InterruptMaskClear(irq_num) DisableIRQ((IRQn_Type)irq_num)
#define os_InterruptMaskSet(irq_num)   EnableIRQ((IRQn_Type)irq_num)
#define os_ClearPendingISR(irq_num)    NVIC_ClearPendingIRQ((IRQn_Type)irq_num)
#else
#define os_InterruptMaskClear(irq_num) DisableIRQ(irq_num)
#define os_InterruptMaskSet(irq_num)   EnableIRQ(irq_num)
#define os_ClearPendingISR(irq_num)    NVIC_ClearPendingIRQ(irq_num)
#endif

#if defined(IMU_GDMA_ENABLE) && (IMU_GDMA_ENABLE == 1)
#define HAL_GDMA            GDMA
#define HAL_GDMA_CH         0
#define HAL_GDMA_IRQn       GDMA_IRQn
#define HAL_GDMA_DONE_EVENT (1U << 0U)
#define GDMA_ISR_PRIORITY   IMU_ISR_PRIORITY
#define HAL_IMU_MEMCPY      HAL_ImuGdmaCopyData
#else
#define HAL_IMU_MEMCPY memcpy
#endif

/*******************************************************************************
 * Declaration
 ******************************************************************************/
#ifdef __ZEPHYR__
const uint8_t gUseRtos_c = 1;
#endif

/*! IMU handle instance for each IMU link */
static hal_imu_handle_t imuHandleCh[kIMU_LinkMax];

/*! IMU interrput callback for each IMU link */
static imu_irq_callback_t imuIrqCallback[kIMU_LinkMax];

/*! IMU message sequence number */
static uint8_t seq_num = 0;

/*! IMU initializtion flag
    bit 0: flag for IMU link #0
    bit 1: flag for IMU link #1
*/
static uint8_t imu_init_flag = 0;

/*! RPMSG initializtion flag
 */
static uint8_t rpmsg_init_flag = 0;

/*! imu task created flag
 */
static uint8_t imu_task_flag = 0;

#ifndef CPU2
/*! Sleep flag address between CPU1 and CPU3 or CPU2 and CPU3 */
#define IMU_SLEEP_FLAG13 0x4138248C
#define IMU_SLEEP_FLAG23 0x443CFE88
#define IMU_SLEEP_FLAG_ADDR(imuLinkId) \
    (((imuLinkId) == kIMU_LinkCpu1Cpu3) ? ((uint32_t *)IMU_SLEEP_FLAG13) : ((uint32_t *)IMU_SLEEP_FLAG23))
#endif

/*! wait imu task lock
 */
#if (defined(USE_RTOS) && (USE_RTOS > 0U))
#ifdef __ZEPHYR__
struct k_mutex imu_task_lock;
#else
static OSA_MUTEX_HANDLE_DEFINE(imu_task_lock);
#endif
#endif
/*******************************************************************************
 * Code
 ******************************************************************************/
#if defined(CPU2)
extern IMU_Msg_Wrapper_short_t __attribute__((aligned(4))) SQRAM_CPU12_MBOX;
extern IMU_Msg_Wrapper_long_t __attribute__((aligned(4))) SQRAM_CPU23_MBOX;
volatile static IMU_Msg_Wrapper_short_t *imuMsgQ12 = &SQRAM_CPU12_MBOX;
volatile static IMU_Msg_Wrapper_long_t *imuMsgQ23  = &SQRAM_CPU23_MBOX;
__attribute__((section(".smu_cpu23_txq"))) volatile static uint8_t __attribute__((aligned(4)))
rpmsgTxBuf23[RPMSG_TXQ23_BUFSIZE][RPMSG_TXQ23_BUFLENGTH];

static void HAL_ImuMain(void *argv);
static OSA_TASK_HANDLE_DEFINE(ImuTaskHandle);
static OSA_TASK_DEFINE(HAL_ImuMain, IMU_TASK_PRIORITY, 1, IMU_TASK_STACK_SIZE, 0);
OSA_EVENT_HANDLE_DEFINE(ImuQFlagsRef);
#else
__attribute__((section(".smu_cpu13_mbox"))) static volatile IMU_Msg_Wrapper_long_t __attribute__((aligned(4)))
SQRAM_CPU13_MBOX;
__attribute__((section(".smu_cpu23_mbox"))) static volatile IMU_Msg_Wrapper_long_t __attribute__((aligned(4)))
SQRAM_CPU23_MBOX;
static volatile IMU_Msg_Wrapper_long_t *imuMsgQ13 = &SQRAM_CPU13_MBOX;
static volatile IMU_Msg_Wrapper_long_t *imuMsgQ23 = &SQRAM_CPU23_MBOX;
__attribute__((section(".smu_cpu31_txq"))) static volatile uint8_t __attribute__((aligned(4)))
rpmsgTxBuf13[RPMSG_TXQ13_BUFSIZE][RPMSG_TXQ13_BUFLENGTH];
__attribute__((section(".smu_cpu32_txq"))) static volatile uint8_t __attribute__((aligned(4)))
rpmsgTxBuf23[RPMSG_TXQ23_BUFSIZE][RPMSG_TXQ23_BUFLENGTH];

/* seperate CPU2 to CPU3 and CPU1 to CPU3 IMU RX tasks */
#ifdef __ZEPHYR__
static void HAL_ImuMainCpu13(void *argv1, void *argv2, void *argv3);
static void HAL_ImuMainCpu23(void *argv1, void *argv2, void *argv3);

K_THREAD_STACK_DEFINE(ImuTaskStackCpu13, IMU_TASK_STACK_SIZE);
K_THREAD_STACK_DEFINE(ImuTaskStackCpu23, IMU_TASK_STACK_SIZE);

k_tid_t ImuTaskCpu13;
k_tid_t ImuTaskCpu23;

K_EVENT_DEFINE(ImuQ13FlagsRef);
K_EVENT_DEFINE(ImuQ23FlagsRef);

struct k_thread ImuTaskHandleCpu13;
struct k_thread ImuTaskHandleCpu23;
#else
static void HAL_ImuMainCpu13(void *argv);
static void HAL_ImuMainCpu23(void *argv);

static OSA_TASK_HANDLE_DEFINE(ImuTaskHandleCpu13);
static OSA_TASK_HANDLE_DEFINE(ImuTaskHandleCpu23);
static OSA_TASK_DEFINE(HAL_ImuMainCpu13, IMU_TASK_PRIORITY, 1, IMU_TASK_STACK_SIZE, 0);
static OSA_TASK_DEFINE(HAL_ImuMainCpu23, IMU_TASK_PRIORITY, 1, IMU_TASK_STACK_SIZE, 0);
OSA_EVENT_HANDLE_DEFINE(ImuQ13FlagsRef);
OSA_EVENT_HANDLE_DEFINE(ImuQ23FlagsRef);
#endif /* __ZEPHYR__ */
#endif

#ifdef __ZEPHYR__
struct k_event rpmsgQFlagsRef;
#else
OSA_EVENT_HANDLE_DEFINE(rpmsgQFlagsRef);
#endif /* __ZEPHYR__ */

#if defined(IMU_GDMA_ENABLE) && (IMU_GDMA_ENABLE == 1)
static gdma_handle_t gdmaHandle;
OSA_SEMAPHORE_HANDLE_DEFINE(gdmaSemHandle);
OSA_EVENT_HANDLE_DEFINE(gdmaFlagsRef);
#endif

/**************Internal helper functions***********************/
/// \cond
#if defined(IMU_GDMA_ENABLE) && (IMU_GDMA_ENABLE == 1)
static void HAL_GdmaCallback(gdma_handle_t *handle, void *userData, uint32_t interrupts)
{
    if (0UL != (interrupts & kGDMA_TransferDoneFlag))
    {
        (void)OSA_EventSet((osa_event_handle_t)gdmaFlagsRef, HAL_GDMA_DONE_EVENT);
    }
}

static void HAL_InitGdma(void)
{
    if (gdmaHandle.callback)
        return;

    GDMA_Init(HAL_GDMA);
    GDMA_CreateHandle(&gdmaHandle, HAL_GDMA, HAL_GDMA_CH);
    GDMA_SetCallback(&gdmaHandle, HAL_GdmaCallback, NULL);
    OSA_SemaphoreCreate(gdmaSemHandle, 1U);
    (void)OSA_EventCreate(gdmaFlagsRef, 1U);
    NVIC_SetPriority(GDMA_IRQn, GDMA_ISR_PRIORITY);
}

void HAL_ImuGdmaCopyData(void *destAddr, void *srcAddr, uint32_t len)
{
    uint32_t Events;
    gdma_channel_xfer_config_t xferConfig = {0};

    xferConfig.srcAddr        = (uint32_t)srcAddr;
    xferConfig.destAddr       = (uint32_t)destAddr;
    xferConfig.linkListAddr   = 0; /* Don't use LLI */
    xferConfig.ahbProt        = kGDMA_ProtPrevilegedMode;
    xferConfig.srcBurstSize   = kGDMA_BurstSize16;
    xferConfig.destBurstSize  = kGDMA_BurstSize16;
    xferConfig.srcWidth       = kGDMA_TransferWidth1Byte;
    xferConfig.destWidth      = kGDMA_TransferWidth1Byte;
    xferConfig.srcAddrInc     = true;
    xferConfig.destAddrInc    = true;
    xferConfig.transferLen    = len;
    xferConfig.enableLinkList = false;

    if (KOSA_StatusSuccess == OSA_SemaphoreWait(gdmaSemHandle, osaWaitForever_c))
    {
        GDMA_SubmitTransfer(&gdmaHandle, &xferConfig);
        GDMA_StartTransfer(&gdmaHandle);
        /* Wait for GMDA transfer done. */
        (void)OSA_EventWait((osa_event_handle_t)gdmaFlagsRef, HAL_GDMA_DONE_EVENT, 0, osaWaitForever_c, &Events);
        OSA_SemaphorePost(gdmaSemHandle);
    }
}
#endif

static void HAL_ImuSetCpuReadyFlag(uint8_t cpuId)
{
}

bool HAL_ImuGetCpuReadyFlag(uint8_t cpuId)
{
    return TRUE;
}

/*!
 * @brief
 * Create a new rpmsg endpoint, which can be used
 * for communication.
 *
 * @param handle            RPMsg instance
 * @param addr              source endpoint address
 *
 * @return       RL_NULL if not found, node pointer containing the ept on success
 *
 */
static hal_rpmsg_handle_t HAL_RpmsgGetEndpointFromAddr(hal_imu_handle_t *imuHandle, uint32_t addr)
{
    LIST_ELEM_st *cur;
    hal_rpmsg_state_t *pEnd;

    assert(NULL != imuHandle);

    list_for_each(cur, &imuHandle->eptList)
    {
        pEnd = (hal_rpmsg_state_t *)cur;
        if (pEnd->local_addr == addr)
        {
            return pEnd;
        }
    }

    return NULL;
}

static hal_rpmsg_handle_t HAL_RpmsgCreateEndpoint(hal_rpmsg_handle_t handle)
{
    hal_imu_handle_t *imuHandle;
    hal_rpmsg_state_t *rpmsgHandle;
    assert(NULL != handle);

    rpmsgHandle = (hal_rpmsg_state_t *)handle;
    imuHandle   = &imuHandleCh[rpmsgHandle->imuLink];
    // env_lock_mutex(rpmsgHandle->lock);
    {
        if (NULL == HAL_RpmsgGetEndpointFromAddr(imuHandle, rpmsgHandle->local_addr))
        {
            LIST_addTail(&imuHandle->eptList, &rpmsgHandle->eptLink);
            // env_unlock_mutex(rpmsgHandle->lock);
            return rpmsgHandle;
        }
    }
    // env_unlock_mutex(rpmsgHandle->lock);
    return NULL;
}

static hal_rpmsg_status_t HAL_RpmsgDestroyEndpoint(hal_rpmsg_handle_t handle)
{
    hal_imu_handle_t *imuHandle;
    hal_rpmsg_state_t *rpmsgHandle;
    assert(NULL != handle);

    rpmsgHandle = (hal_rpmsg_state_t *)handle;
    imuHandle   = &imuHandleCh[rpmsgHandle->imuLink];

    // env_lock_mutex(rpmsgHandle->lock);
    {
        rpmsgHandle = HAL_RpmsgGetEndpointFromAddr(imuHandle, rpmsgHandle->local_addr);

        if (NULL == rpmsgHandle)
        {
            // env_unlock_mutex(rpmsgHandle->lock);
            return kStatus_HAL_RpmsgError;
        }
        LIST_remove(&imuHandle->eptList, &rpmsgHandle->eptLink);
    }
    // env_unlock_mutex(rpmsgHandle->lock);
    return kStatus_HAL_RpmsgSuccess;
}

static uint8_t *HAL_ImuGetWlanTxBuf(hal_imu_handle_t *imuHandle)
{
    uint32_t wlanTxBuf;
    IMU_WLAN_TXQ_CTRL_st *wlanTxqCtl;

    assert(NULL != imuHandle);
    wlanTxqCtl = &imuHandle->wlanTxqCtl;

    if (IS_WLAN_TXBQ_EMPTY(wlanTxqCtl))
    {
        return NULL;
    }
    else
    {
        wlanTxBuf = wlanTxqCtl->txBufQue[wlanTxqCtl->readIndex & IMU_TXQ_ENTRY_MASK];
        INCR_WLAN_TXBQ_RD_INDEX(wlanTxqCtl, 1U);
        return (uint8_t *)wlanTxBuf;
    }
}

static hal_rpmsg_status_t HAL_ImuPutWlanTxBuf(hal_imu_handle_t *imuHandle, uint8_t *txBuf)
{
    hal_rpmsg_status_t state = kStatus_HAL_RpmsgSuccess;
    IMU_WLAN_TXQ_CTRL_st *wlanTxqCtl;

    assert(NULL != imuHandle);
    wlanTxqCtl = &imuHandle->wlanTxqCtl;

    if (IS_WLAN_TXBQ_FULL(wlanTxqCtl))
    {
        state = kStatus_HAL_RpmsgError;
    }
    else
    {
        wlanTxqCtl->txBufQue[wlanTxqCtl->writeIndex & IMU_TXQ_ENTRY_MASK] = (uint32_t)txBuf;
        INCR_WLAN_TXBQ_WR_INDEX(wlanTxqCtl, 1U);
    }

    return state;
}

static uint8_t *HAL_RpmsgGetTxBuf(hal_imu_handle_t *imuHandle)
{
    uint8_t *rpmsgTxBuf = NULL;
    RPMSG_TXQ_CTRL_st *rpmsgTxqCtl;
    OSA_SR_ALLOC();

    assert(NULL != imuHandle);
    rpmsgTxqCtl = &imuHandle->rpmsgTxqCtl;

    OSA_ENTER_CRITICAL();

    do
    {
        if (imuHandle->imuLink == (uint8_t)kIMU_LinkCpu2Cpu3)
        {
            if (IS_RPMSG_TXBQ23_EMPTY(rpmsgTxqCtl))
            {
                break;
            }
            else
            {
                rpmsgTxBuf = (uint8_t *)(rpmsgTxqCtl->txBufQue[rpmsgTxqCtl->readIndex & RPMSG_TXQ23_ENTRY_MASK]);
                INCR_RPMSG_TXBQ23_RD_INDEX(rpmsgTxqCtl, 1U);
            }
        }
        else
        {
            if (IS_RPMSG_TXBQ13_EMPTY(rpmsgTxqCtl))
            {
                break;
            }
            else
            {
                rpmsgTxBuf = (uint8_t *)(rpmsgTxqCtl->txBufQue[rpmsgTxqCtl->readIndex & RPMSG_TXQ13_ENTRY_MASK]);
                INCR_RPMSG_TXBQ13_RD_INDEX(rpmsgTxqCtl, 1U);
            }
        }
    } while (false);

    OSA_EXIT_CRITICAL();

    return rpmsgTxBuf;
}

static hal_rpmsg_status_t HAL_RpmsgPutTxBuf(hal_imu_handle_t *imuHandle, uint8_t *txBuf)
{
    hal_rpmsg_status_t state = kStatus_HAL_RpmsgSuccess;
    RPMSG_TXQ_CTRL_st *rpmsgTxqCtl;
    OSA_SR_ALLOC();

    assert(NULL != imuHandle);
    rpmsgTxqCtl = &imuHandle->rpmsgTxqCtl;

    OSA_ENTER_CRITICAL();

    if (imuHandle->imuLink == (uint8_t)kIMU_LinkCpu2Cpu3)
    {
        if (IS_RPMSG_TXBQ23_FULL(rpmsgTxqCtl))
        {
            state = kStatus_HAL_RpmsgError;
        }
        else
        {
            rpmsgTxqCtl->txBufQue[rpmsgTxqCtl->writeIndex & RPMSG_TXQ23_ENTRY_MASK] = (uint32_t)txBuf;
            INCR_RPMSG_TXBQ23_WR_INDEX(rpmsgTxqCtl, 1U);
        }
    }
    else
    {
        if (IS_RPMSG_TXBQ13_FULL(rpmsgTxqCtl))
        {
            state = kStatus_HAL_RpmsgError;
        }
        else
        {
            rpmsgTxqCtl->txBufQue[rpmsgTxqCtl->writeIndex & RPMSG_TXQ13_ENTRY_MASK] = (uint32_t)txBuf;
            INCR_RPMSG_TXBQ13_WR_INDEX(rpmsgTxqCtl, 1U);
        }
    }

    OSA_EXIT_CRITICAL();

    return state;
}

hal_rpmsg_status_t HAL_ImuLinkIsUp(uint8_t imuLink)
{
    hal_imu_handle_t *imuHandle;

    assert((uint8_t)kIMU_LinkMax > imuLink);
    imuHandle = &imuHandleCh[imuLink];

    if ((uint8_t)IMU_INITIALIZED == imuHandle->imuSyncState)
    {
        return kStatus_HAL_RpmsgSuccess;
    }
    else
    {
        return kStatus_HAL_RpmsgError;
    }
}

void HAL_ImuResetWlanTxq(uint8_t imuLink)
{
    hal_imu_handle_t *imuHandle = NULL;

    imuHandle                        = &imuHandleCh[imuLink];
    imuHandle->wlanTxqCtl.writeIndex = 0;
    imuHandle->wlanTxqCtl.readIndex  = 0;
}

static hal_rpmsg_status_t HAL_ImuSendMsgBlockingCommon(
    hal_imu_handle_t *imuHandle, uint8_t type, uint8_t subtype, uint8_t *data, uint32_t length, bool lockTxFifo)
{
    IMU_Msg_t *imuMsg;
    IMU_Msg_t localImuMsg;
    OSA_SR_ALLOC();
    int32_t ret = 0;

    assert(NULL != imuHandle);
    assert(IMU_PAYLOAD_SIZE >= length);

    (void)memset((void *)&localImuMsg, 0, sizeof(IMU_Msg_t));

    localImuMsg.Hdr.type     = type;
    localImuMsg.Hdr.sub_type = subtype;
    localImuMsg.Hdr.seq_num  = seq_num & (uint8_t)0xff;

    switch ((imu_msg_type_t)type)
    {
        case IMU_MSG_CONTROL:
            if (((uint8_t)IMU_MSG_CONTROL_TX_BUF_ADDR == subtype) ||
                ((uint8_t)IMU_MSG_CONTROL_FREE_RX_BUF == subtype) ||
                ((uint8_t)IMU_MSG_CONTROL_CMD_BUF_ADDR == subtype) || ((uint8_t)IMU_MSG_CONTROL_EVT_ACK == subtype) ||
                ((uint8_t)IMU_MSG_CONTROL_COMMAND_RSP_ACK == subtype) ||
                ((uint8_t)IMU_MSG_CONTROL_RPMSG_EPT_QUIRY == subtype) ||
                ((uint8_t)IMU_MSG_CONTROL_RPMSG_EPT_QUIRY_RSP == subtype) ||
                ((uint8_t)IMU_MSG_CONTROL_RPMSG_BUF_FREE == subtype) ||
                ((uint8_t)IMU_MSG_CONTROL_EVT_DUMP == subtype) || ((uint8_t)IMU_MSG_CONTROL_ERROR == subtype))
            {
                (void)memcpy((void *)&localImuMsg.PayloadPtr[0], data, length << 2U);
                localImuMsg.Hdr.length = (uint8_t)length;
            }
            break;
        case IMU_MSG_COMMAND:
            if (imuHandle->cmd_buffer_available)
            {
                localImuMsg.Hdr.length    = 1;
                localImuMsg.PayloadPtr[0] = (uint32_t)imuHandle->cmd_buffer;
            }
            else
            {
                return kStatus_HAL_RpmsgError;
            }
            break;
        case IMU_MSG_TX_DATA:
            localImuMsg.Hdr.length    = 1;
            localImuMsg.PayloadPtr[0] = (uint32_t)data;
            break;
        case IMU_MSG_MULTI_TX_DATA:
            (void)memcpy((void *)&localImuMsg.PayloadPtr[0], imuHandle->imuMsgBuf, (imuHandle->imuMsgBufIdx) << 2U);
            localImuMsg.Hdr.length  = imuHandle->imuMsgBufIdx;
            imuHandle->imuMsgBufIdx = 0;
            break;
        case IMU_MSG_RPMSG:
            (void)memcpy((void *)&localImuMsg.PayloadPtr[0], data, length << 2U);
            localImuMsg.Hdr.length = length;
            break;
        default:
            // Do nothing for the commands without expansion.
            break;
    }

    /* Added at 02/18/2022, in case second task overwriting imuMsg*/
    while (IMU_TX_FIFO_ALMOST_FULL((imu_link_t)imuHandle->imuLink))
    {
    }

    OSA_ENTER_CRITICAL();
    imuMsg = (IMU_Msg_t *)&((IMU_MSG_SND_Q(imuHandle->imuLink))[IMU_WR_PTR(imuHandle->imuLink)]);
    (void)memcpy(imuMsg, &localImuMsg, sizeof(IMU_Hdr_t) + ((uint32_t)localImuMsg.Hdr.length << 2U));
    ret = IMU_SendMsgPtrBlocking((imu_link_t)imuHandle->imuLink, (uint32_t)imuMsg, lockTxFifo);
    OSA_EXIT_CRITICAL();

    if (0 == ret)
    {
        return kStatus_HAL_RpmsgSuccess;
    }
    else
    {
        return kStatus_HAL_RpmsgError;
    }
}

static hal_rpmsg_status_t HAL_ImuSendMsgBlocking(
    hal_imu_handle_t *imuHandle, uint8_t type, uint8_t subtype, uint8_t *data, uint32_t length)
{
    return HAL_ImuSendMsgBlockingCommon(imuHandle, type, subtype, data, length, FALSE);
}

static hal_rpmsg_status_t HAL_ImuSendSync(hal_imu_handle_t *imuHandle)
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    OSA_SR_ALLOC();
    assert(NULL != imuHandle);

    *IMU_MSG_CUR_MAGIC_P(imuHandle->imuLink) = IMU_SYNC_MAGIC_PATTERN;
    while (IMU_SYNC_MAGIC_PATTERN != (*IMU_MSG_CUR_MAGIC_P((imu_link_t)imuHandle->imuLink)))
    {
    }

    OSA_ENTER_CRITICAL();
    if (((uint8_t)IMU_UNINITIALIZED == imuHandle->imuSyncState) &&
        (IMU_SYNC_MAGIC_PATTERN == (*IMU_MSG_PEER_MAGIC_P(imuHandle->imuLink))))
    {
        if (kStatus_HAL_RpmsgSuccess ==
            HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_CONTROL, (uint8_t)IMU_MSG_CONTROL_SYNC, NULL, 0))
        {
            imuHandle->imuSyncState = (uint8_t)IMU_INITIALIZING;
            seq_num++;
        }
        else
        {
            rpmsgStatus = kStatus_HAL_RpmsgError;
        }
    }
    OSA_EXIT_CRITICAL();

    return rpmsgStatus;
}

static hal_rpmsg_status_t HAL_ImuSendRpmsgEptQuiry(hal_imu_handle_t *imuHandle, uint32_t addr)
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    OSA_SR_ALLOC();
    assert(NULL != imuHandle);

    if (kStatus_HAL_RpmsgError == HAL_ImuLinkIsUp(imuHandle->imuLink))
    {
        return kStatus_HAL_RpmsgError;
    }

    OSA_ENTER_CRITICAL();
    if (kStatus_HAL_RpmsgSuccess == HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_CONTROL,
                                                           (uint8_t)IMU_MSG_CONTROL_RPMSG_EPT_QUIRY, (uint8_t *)&addr,
                                                           1))
    {
        seq_num++;
    }
    else
    {
        rpmsgStatus = kStatus_HAL_RpmsgError;
    }
    OSA_EXIT_CRITICAL();

    return rpmsgStatus;
}

static hal_rpmsg_status_t HAL_ImuSendRpmsgEptQuiryRsp(hal_imu_handle_t *imuHandle, uint32_t addr, bool found)
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    uint32_t quiryRsp[2];
    OSA_SR_ALLOC();

    assert(NULL != imuHandle);

    if (kStatus_HAL_RpmsgError == HAL_ImuLinkIsUp(imuHandle->imuLink))
    {
        return kStatus_HAL_RpmsgError;
    }

    OSA_ENTER_CRITICAL();
    quiryRsp[0] = addr;
    if (TRUE == found)
    {
        quiryRsp[1] = 1;
    }
    else
    {
        quiryRsp[1] = 0;
    }

    if (kStatus_HAL_RpmsgSuccess == HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_CONTROL,
                                                           (uint8_t)IMU_MSG_CONTROL_RPMSG_EPT_QUIRY_RSP,
                                                           (uint8_t *)&quiryRsp[0], 2))
    {
        seq_num++;
    }
    else
    {
        rpmsgStatus = kStatus_HAL_RpmsgError;
    }
    OSA_EXIT_CRITICAL();

    return rpmsgStatus;
}

static hal_rpmsg_status_t HAL_ImuSendRpmsgFreeBuf(hal_imu_handle_t *imuHandle, uint8_t *buf)
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    OSA_SR_ALLOC();
    assert(NULL != imuHandle);

    if (kStatus_HAL_RpmsgError == HAL_ImuLinkIsUp(imuHandle->imuLink))
    {
        return kStatus_HAL_RpmsgError;
    }

    OSA_ENTER_CRITICAL();
    if (kStatus_HAL_RpmsgSuccess ==
        HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_CONTROL, (uint8_t)IMU_MSG_CONTROL_RPMSG_BUF_FREE, buf, 1U))
    {
        seq_num++;
    }
    else
    {
        rpmsgStatus = kStatus_HAL_RpmsgError;
    }
    OSA_EXIT_CRITICAL();

    return rpmsgStatus;
}

static hal_rpmsg_status_t HAL_ImuSendEventAck(hal_imu_handle_t *imuHandle, uint8_t *rxBuf, uint8_t length)
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    OSA_SR_ALLOC();
    assert(NULL != imuHandle);

    if (kStatus_HAL_RpmsgError == HAL_ImuLinkIsUp(imuHandle->imuLink))
    {
        return kStatus_HAL_RpmsgError;
    }

    OSA_ENTER_CRITICAL();
    if (kStatus_HAL_RpmsgSuccess ==
        HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_CONTROL, (uint8_t)IMU_MSG_CONTROL_EVT_ACK, rxBuf, length))
    {
        seq_num++;
    }
    else
    {
        rpmsgStatus = kStatus_HAL_RpmsgError;
    }
    OSA_EXIT_CRITICAL();

    return rpmsgStatus;
}

hal_rpmsg_status_t HAL_ImuSendEventDumpAck(imu_link_t link, uint8_t *rxBuf, uint8_t length)
{
    hal_imu_handle_t *imuHandle;
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    OSA_SR_ALLOC();

    assert(kIMU_LinkMax > link);
    imuHandle = &imuHandleCh[link];

    if (kStatus_HAL_RpmsgError == HAL_ImuLinkIsUp(imuHandle->imuLink))
    {
        return kStatus_HAL_RpmsgError;
    }

    OSA_ENTER_CRITICAL();
    if (kStatus_HAL_RpmsgSuccess ==
        HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_CONTROL, (uint8_t)IMU_MSG_CONTROL_EVT_DUMP, rxBuf, length))
    {
        seq_num++;
    }
    else
    {
        rpmsgStatus = kStatus_HAL_RpmsgError;
    }

    OSA_EXIT_CRITICAL();

    return rpmsgStatus;
}

static hal_rpmsg_status_t HAL_ImuSendCommandRspAck(hal_imu_handle_t *imuHandle, uint8_t *rxBuf, uint8_t length)
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    OSA_SR_ALLOC();
    assert(NULL != imuHandle);

    if (kStatus_HAL_RpmsgError == HAL_ImuLinkIsUp(imuHandle->imuLink))
    {
        return kStatus_HAL_RpmsgError;
    }

    OSA_ENTER_CRITICAL();
    if (kStatus_HAL_RpmsgSuccess == HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_CONTROL,
                                                           (uint8_t)IMU_MSG_CONTROL_COMMAND_RSP_ACK, rxBuf, length))
    {
        seq_num++;
    }
    else
    {
        rpmsgStatus = kStatus_HAL_RpmsgError;
    }
    OSA_EXIT_CRITICAL();

    return rpmsgStatus;
}

static hal_rpmsg_status_t HAL_ImuFreeRxBuf(hal_imu_handle_t *imuHandle, uint8_t *rxBuf, uint8_t length)
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    OSA_SR_ALLOC();
    assert(NULL != imuHandle);

    if (kStatus_HAL_RpmsgError == HAL_ImuLinkIsUp(imuHandle->imuLink))
    {
        return kStatus_HAL_RpmsgError;
    }

    OSA_ENTER_CRITICAL();
    if (kStatus_HAL_RpmsgSuccess == HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_CONTROL,
                                                           (uint8_t)IMU_MSG_CONTROL_FREE_RX_BUF, rxBuf, length))
    {
        seq_num++;
    }
    else
    {
        rpmsgStatus = kStatus_HAL_RpmsgError;
    }
    OSA_EXIT_CRITICAL();

    return rpmsgStatus;
}

hal_rpmsg_status_t HAL_ImuSendCommand(uint8_t imuLink, uint8_t *cmdBuf, uint32_t length)
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    hal_imu_handle_t *imuHandle;
    OSA_SR_ALLOC();

    assert((uint8_t)kIMU_LinkMax > imuLink);
    imuHandle = &imuHandleCh[imuLink];

    if (kStatus_HAL_RpmsgError == HAL_ImuLinkIsUp(imuHandle->imuLink) || FALSE == imuHandle->cmd_buffer_available)
    {
        return kStatus_HAL_RpmsgError;
    }

    if (length != 0U)
    {
        // To be DMAed
        (void)HAL_IMU_MEMCPY((void *)imuHandle->cmd_buffer, cmdBuf, length);
    }
    else
    {
        return kStatus_HAL_RpmsgError;
    }

    OSA_ENTER_CRITICAL();
    if (kStatus_HAL_RpmsgSuccess == HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_COMMAND, 0U, NULL, 0))
    {
        seq_num++;
        imuHandle->cmd_buffer_available = FALSE;
    }
    else
    {
        rpmsgStatus = kStatus_HAL_RpmsgError;
    }
    OSA_EXIT_CRITICAL();

    return rpmsgStatus;
}

hal_rpmsg_status_t HAL_ImuSendTxData(uint8_t imuLink, uint8_t *txBuf, uint32_t length)
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    hal_imu_handle_t *imuHandle;
    uint8_t *wlan_tx_buf;
    OSA_SR_ALLOC();

    assert((uint8_t)kIMU_LinkMax > imuLink);
    imuHandle = &imuHandleCh[imuLink];

    if (kStatus_HAL_RpmsgError == HAL_ImuLinkIsUp(imuHandle->imuLink))
    {
        return kStatus_HAL_RpmsgError;
    }

    wlan_tx_buf = HAL_ImuGetWlanTxBuf(imuHandle);
    if ((wlan_tx_buf != NULL) && (length != 0U))
    {
        // To be DMAed
        (void)HAL_IMU_MEMCPY(wlan_tx_buf, txBuf, length);
    }
    else
    {
        return kStatus_HAL_RpmsgError;
    }

    OSA_ENTER_CRITICAL();
    if (kStatus_HAL_RpmsgSuccess == HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_TX_DATA, 0U, wlan_tx_buf, 1U))
    {
        seq_num++;
    }
    else
    {
        (void)HAL_ImuPutWlanTxBuf(imuHandle, wlan_tx_buf);
        rpmsgStatus = kStatus_HAL_RpmsgError;
    }
    OSA_EXIT_CRITICAL();

    return rpmsgStatus;
}

hal_rpmsg_status_t HAL_ImuAddWlanTxPacket(uint8_t imuLink, uint8_t *txBuf, uint32_t length)
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    hal_imu_handle_t *imuHandle;
    uint8_t *wlan_tx_buf;

    assert((uint8_t)kIMU_LinkMax > imuLink);
    assert(NULL != txBuf);
    assert(0U != length);
    imuHandle = &imuHandleCh[imuLink];

    if (imuHandle->imuMsgBufIdx > IMU_PAYLOAD_SIZE - 1U)
    {
        return kStatus_HAL_RpmsgError;
    }

    wlan_tx_buf = HAL_ImuGetWlanTxBuf(imuHandle);

    if (NULL == wlan_tx_buf)
    {
        return kStatus_HAL_RpmsgError;
    }

    // To be DMAed
    (void)HAL_IMU_MEMCPY(wlan_tx_buf, txBuf, length);

    imuHandle->imuMsgBuf[imuHandle->imuMsgBufIdx] = (uint32_t)wlan_tx_buf;
    imuHandle->imuMsgBufIdx++;

    return rpmsgStatus;
}

hal_rpmsg_status_t HAL_ImuAddWlanTxPacketExt(uint8_t imuLink,
                                             uint8_t *txBuf,
                                             uint32_t length,
                                             void (*cb)(void *destAddr, void *srcAddr, uint32_t len))
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    hal_imu_handle_t *imuHandle;
    uint8_t *wlan_tx_buf;

    assert((uint8_t)kIMU_LinkMax > imuLink);
    assert(NULL != txBuf);
    assert(0U != length);
    imuHandle = &imuHandleCh[imuLink];

    if (imuHandle->imuMsgBufIdx > IMU_PAYLOAD_SIZE - 1U)
    {
        return kStatus_HAL_RpmsgError;
    }

    wlan_tx_buf = HAL_ImuGetWlanTxBuf(imuHandle);

    if (NULL == wlan_tx_buf)
    {
        return kStatus_HAL_RpmsgError;
    }

    // To be DMAed
    cb(wlan_tx_buf, txBuf, length);

    imuHandle->imuMsgBuf[imuHandle->imuMsgBufIdx] = (uint32_t)wlan_tx_buf;
    imuHandle->imuMsgBufIdx++;

    return rpmsgStatus;
}

hal_rpmsg_status_t HAL_ImuSendMultiTxData(uint8_t imuLink)
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    hal_imu_handle_t *imuHandle;
    OSA_SR_ALLOC();

    assert((uint8_t)kIMU_LinkMax > imuLink);
    imuHandle = &imuHandleCh[imuLink];

    if (kStatus_HAL_RpmsgError == HAL_ImuLinkIsUp(imuHandle->imuLink))
    {
        return kStatus_HAL_RpmsgError;
    }

    OSA_ENTER_CRITICAL();
    if (kStatus_HAL_RpmsgSuccess == HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_MULTI_TX_DATA, 0U, NULL, 0U))
    {
        seq_num++;
        imuHandle->imuMsgBufIdx = 0;
    }
    else
    {
        rpmsgStatus = kStatus_HAL_RpmsgError;
    }
    OSA_EXIT_CRITICAL();

    return rpmsgStatus;
}

static hal_rpmsg_status_t HAL_ImuSendSyncAck(hal_imu_handle_t *imuHandle)
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    OSA_SR_ALLOC();
    assert(NULL != imuHandle);

    OSA_ENTER_CRITICAL();
    if (kStatus_HAL_RpmsgSuccess ==
        HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_CONTROL, (uint8_t)IMU_MSG_CONTROL_SYNC_ACK, NULL, 0U))
    {
        seq_num++;
    }
    else
    {
        rpmsgStatus = kStatus_HAL_RpmsgError;
    }
    OSA_EXIT_CRITICAL();

    return rpmsgStatus;
}

static hal_rpmsg_status_t HAL_ImuSendUnlock(hal_imu_handle_t *imuHandle)
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    OSA_SR_ALLOC();
    assert(NULL != imuHandle);

    if (kStatus_HAL_RpmsgError == HAL_ImuLinkIsUp(imuHandle->imuLink))
    {
        return kStatus_HAL_RpmsgError;
    }

    OSA_ENTER_CRITICAL();
    if (kStatus_HAL_RpmsgSuccess ==
        HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_CONTROL, (uint8_t)IMU_MSG_CONTROL_ACK_FOR_UNLOCK, NULL, 0U))
    {
        seq_num++;
    }
    else
    {
        rpmsgStatus = kStatus_HAL_RpmsgError;
    }
    OSA_EXIT_CRITICAL();

    return rpmsgStatus;
}

hal_rpmsg_status_t HAL_ImuReturnAllTxBuf(imu_link_t link)
{
    hal_imu_handle_t *imuHandle;
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    uint8_t txBufCnt;
    uint8_t *wlan_tx_buf;
    OSA_SR_ALLOC();

    assert(kIMU_LinkMax > link);
    imuHandle = &imuHandleCh[link];

    txBufCnt = 0;
    while (TRUE)
    {
        wlan_tx_buf = HAL_ImuGetWlanTxBuf(imuHandle);
        if (NULL == wlan_tx_buf) /*! all Tx buffers are consumed */
        {
            break;
        }

        imuHandle->imuMsgBuf[txBufCnt] = (uint32_t)wlan_tx_buf;
        txBufCnt++;

        if (IMU_PAYLOAD_SIZE == txBufCnt)
        {
            OSA_ENTER_CRITICAL();
            if (kStatus_HAL_RpmsgSuccess !=
                HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_CONTROL, (uint8_t)IMU_MSG_CONTROL_TX_BUF_ADDR,
                                       (uint8_t *)&imuHandle->imuMsgBuf[0], (uint32_t)IMU_PAYLOAD_SIZE))
            {
                OSA_EXIT_CRITICAL();
                return kStatus_HAL_RpmsgError;
            }
            else
            {
                seq_num++;
            }
            txBufCnt = 0;
            OSA_EXIT_CRITICAL();
        }
    }

    if (txBufCnt != 0U)
    {
        OSA_ENTER_CRITICAL();
        if (kStatus_HAL_RpmsgSuccess != HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_CONTROL,
                                                               (uint8_t)IMU_MSG_CONTROL_TX_BUF_ADDR,
                                                               (uint8_t *)&imuHandle->imuMsgBuf[0], txBufCnt))
        {
            OSA_EXIT_CRITICAL();
            return kStatus_HAL_RpmsgError;
        }
        else
        {
            seq_num++;
        }
        OSA_EXIT_CRITICAL();
    }

    return rpmsgStatus;
}

static hal_rpmsg_status_t HAL_ImuSendShutdown(hal_imu_handle_t *imuHandle)
{
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    OSA_SR_ALLOC();
    assert(NULL != imuHandle);

    if (kStatus_HAL_RpmsgError == HAL_ImuLinkIsUp(imuHandle->imuLink))
    {
        return kStatus_HAL_RpmsgError;
    }

    OSA_ENTER_CRITICAL();
    if (kStatus_HAL_RpmsgSuccess ==
        HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_CONTROL, (uint8_t)IMU_MSG_CONTROL_SHUTDOWN, NULL, 0U))
    {
        seq_num++;
    }
    else
    {
        rpmsgStatus = kStatus_HAL_RpmsgError;
    }
    OSA_EXIT_CRITICAL();

    return rpmsgStatus;
}

static hal_rpmsg_status_t HAL_ImuCtrlHandler(hal_imu_handle_t *imuHandle, IMU_Msg_t *data, uint32_t len)
{
    imu_ctrl_msg_subtype_t imuControlType;
    IMU_Msg_t *pImuMsg             = data;
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    hal_rpmsg_state_t *rpmsgHandle;
    OSA_SR_ALLOC();
    LIST_ELEM_st *cur;
    uint8_t eptQuiryRspAck;

    assert(NULL != imuHandle);
    imuControlType = (imu_ctrl_msg_subtype_t)pImuMsg->Hdr.sub_type;
    OSA_ENTER_CRITICAL();

    switch (imuControlType)
    {
        case IMU_MSG_CONTROL_ACK_FOR_UNLOCK:
            IMU_UNLOCK_TX_FIFO(imuHandle->imuLink);
            break;
        case IMU_MSG_CONTROL_SYNC:
            (void)HAL_ImuSendSyncAck(imuHandle);
            if ((uint8_t)kIMU_LinkCpu2Cpu3 == imuHandle->imuLink)
            {
                imuHandle->imuSyncState = (uint8_t)IMU_INITIALIZED;
            }
            (void)HAL_ImuSendSyncAck(imuHandle);
            imuHandle->imuSyncState = (uint8_t)IMU_INITIALIZED;
            break;
        case IMU_MSG_CONTROL_SYNC_ACK:
            imuHandle->imuSyncState = (uint8_t)IMU_INITIALIZED;
            break;
        case IMU_MSG_CONTROL_CMD_BUF_ADDR:
            imuHandle->cmd_buffer           = (uint32_t *)pImuMsg->PayloadPtr[0];
            imuHandle->cmd_buffer_available = TRUE;
            if ((uint8_t)IMU_INITIALIZED != imuHandle->imuSyncState)
            {
                imuHandle->imuSyncState = (uint8_t)IMU_INITIALIZED;
            }
            break;
        case IMU_MSG_CONTROL_TX_BUF_ADDR:
            for (uint8_t i = 0; i < pImuMsg->Hdr.length; i++)
            {
                (void)HAL_ImuPutWlanTxBuf(imuHandle, (uint8_t *)pImuMsg->PayloadPtr[i]);
            }
            break;
        case IMU_MSG_CONTROL_ERROR:
            break;
        case IMU_MSG_CONTROL_SHUTDOWN:
            imuHandle->imuSyncState = (uint8_t)IMU_UNINITIALIZED;
            IMU_ClearPendingInterrupts((imu_link_t)imuHandle->imuLink, IMU_MSG_FIFO_CNTL_MSG_RDY_INT_CLR_MASK);
            IMU_ClearPendingInterrupts((imu_link_t)imuHandle->imuLink, IMU_MSG_FIFO_CNTL_SP_AV_INT_CLR_MASK);
            (void)os_InterruptMaskClear(IMULINKID_TO_IRQID((imu_link_t)imuHandle->imuLink));
            IMU_Deinit((imu_link_t)imuHandle->imuLink);
            *IMU_MSG_CUR_MAGIC_P(imuHandle->imuLink) = 0;
            imuHandle->wlanTxqCtl.writeIndex         = 0;
            imuHandle->wlanTxqCtl.readIndex          = 0;
            break;
        case IMU_MSG_CONTROL_RPMSG_EPT_QUIRY:
        {
            hal_rpmsg_state_t *rpmsgHandle = HAL_RpmsgGetEndpointFromAddr(imuHandle, pImuMsg->PayloadPtr[0]);
            if (rpmsgHandle != NULL)
            {
                /* The remote CPU is sending an endpoint query so it implies the rpmsg link is ready */
                rpmsgHandle->eptLinkIsReady = TRUE;
                /* Confirm the local endpoint is ready too */
                rpmsgStatus = HAL_ImuSendRpmsgEptQuiryRsp(imuHandle, pImuMsg->PayloadPtr[0], TRUE);
                /* Make sure to unblock the task calling HAL_RpmsgInit */
#ifdef __ZEPHYR__
                k_event_set(&rpmsgQFlagsRef, RPMSG_EVENT_ENDPOINT_QUERY_RSP << imuHandle->imuLink);
#else
                (void)OSA_EventSet((osa_event_handle_t)rpmsgQFlagsRef,
                                   RPMSG_EVENT_ENDPOINT_QUERY_RSP << imuHandle->imuLink);
#endif
            }
            else
            {
                /* Local endpoint doesn't exist yet, the remote CPU needs to wait until the local CPU initializes
                 * the targeted endpoint, a new query will be sent then to update the link status on both sides */
                rpmsgStatus = HAL_ImuSendRpmsgEptQuiryRsp(imuHandle, pImuMsg->PayloadPtr[0], FALSE);
            }
        }
        break;
        case IMU_MSG_CONTROL_RPMSG_EPT_QUIRY_RSP:
            eptQuiryRspAck = 0;
            list_for_each(cur, &imuHandle->eptList)
            {
                rpmsgHandle = (hal_rpmsg_state_t *)cur;
                if (rpmsgHandle->remote_addr == pImuMsg->PayloadPtr[0])
                {
                    if (pImuMsg->PayloadPtr[1] != 0U)
                    {
                        eptQuiryRspAck              = 1;
                        rpmsgHandle->eptLinkIsReady = TRUE;
                    }
                    else
                    {
                        rpmsgHandle->eptLinkIsReady = FALSE;
                    }
                }
            }

            if (eptQuiryRspAck != 0U)
            {
                /* Make sure to unblock the task calling HAL_RpmsgInit */
#ifdef __ZEPHYR__
                k_event_set(&rpmsgQFlagsRef, RPMSG_EVENT_ENDPOINT_QUERY_RSP << imuHandle->imuLink);
#else
                (void)OSA_EventSet((osa_event_handle_t)rpmsgQFlagsRef,
                                   RPMSG_EVENT_ENDPOINT_QUERY_RSP << imuHandle->imuLink);
#endif
            }
            break;
        case IMU_MSG_CONTROL_RPMSG_BUF_FREE:
            (void)HAL_RpmsgPutTxBuf(imuHandle, (uint8_t *)pImuMsg->PayloadPtr[0]);
            break;
        default:
            // Do nothing for the commands without header expansion.
            break;
    }

    OSA_EXIT_CRITICAL();
    return rpmsgStatus;
}

hal_rpmsg_status_t HAL_ImuReceive(uint8_t imuLink)
{
    IMU_Msg_t *pMsg = NULL, localImuMsg;
    IMU_Msg_t localImuMsgRx;

    hal_imu_handle_t *imuHandle = NULL;
    imu_msg_type_t msg_type     = IMU_MSG_MAX;
    bool isUnlockMsgReqd        = FALSE;
    hal_rpmsg_state_t *ept;
    struct rpmsg_std_msg *rpmsg_msg;
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;

    assert((uint8_t)kIMU_LinkMax > imuLink);
    imuHandle = &imuHandleCh[imuLink];

    while (TRUE)
    {
        if (IMU_RX_FIFO_EMPTY((imu_link_t)imuHandle->imuLink))
        {
            IMU_ClearPendingInterrupts((imu_link_t)imuHandle->imuLink, IMU_MSG_FIFO_CNTL_MSG_RDY_INT_CLR_MASK);
            os_ClearPendingISR(IMULINKID_TO_IRQID((imu_link_t)imuHandle->imuLink));
#ifndef CPU2
            *IMU_SLEEP_FLAG_ADDR(imuHandle->imuLink) |= (uint32_t)(1 << 0U);
#endif
            break;
        }
        else
        {
#ifndef CPU2
            *IMU_SLEEP_FLAG_ADDR(imuHandle->imuLink) &= (uint32_t)(~(1 << 0U));
#endif

            /* Message buffer pMsg should be consumed (or copied for later
             * processing) in handler before call for next READ_ICC_MESSAGE
             * comes here again.
             * Otherwise other CPU may use same pMsg for next write,
             * when FIFO is almost full
             */
            pMsg = (IMU_Msg_t *)IMU_RD_MSG(imuHandle->imuLink);
            if ((pMsg != NULL) && (IMU_RX_FIFO_LOCKED(imuHandle->imuLink)))
            {
                isUnlockMsgReqd = TRUE;
            }
        }

        /* release CPU access here because message processing may take time */
        if (pMsg != NULL)
        {
            (void)memcpy((uint8_t *)&localImuMsg, (uint8_t *)pMsg, sizeof(IMU_Msg_t));
            pMsg     = &localImuMsg;
            msg_type = (imu_msg_type_t)pMsg->Hdr.type;

            switch (msg_type)
            {
                case IMU_MSG_CONTROL:
                    rpmsgStatus = HAL_ImuCtrlHandler(imuHandle, pMsg, pMsg->Hdr.length);
                    if (imuHandle->imuHandler[IMU_MSG_CONTROL] != NULL)
                    {
                        rpmsgStatus = imuHandle->imuHandler[IMU_MSG_CONTROL]((IMU_Msg_t *)pMsg, pMsg->Hdr.length);
                    }
                    break;
                case IMU_MSG_COMMAND_RESPONSE:
                    if (imuHandle->imuHandler[IMU_MSG_COMMAND_RESPONSE] != NULL)
                    {
                        rpmsgStatus =
                            imuHandle->imuHandler[IMU_MSG_COMMAND_RESPONSE]((IMU_Msg_t *)pMsg, pMsg->Hdr.length);
                    }
                    assert(kStatus_HAL_RpmsgSuccess == rpmsgStatus);
                    rpmsgStatus = HAL_ImuSendCommandRspAck(imuHandle, (uint8_t *)&pMsg->PayloadPtr[0], 1);
                    imuHandle->cmd_buffer_available = TRUE;
                    break;

                case IMU_MSG_EVENT:
                    if (imuHandle->imuHandler[IMU_MSG_EVENT] != NULL)
                    {
                        rpmsgStatus = imuHandle->imuHandler[IMU_MSG_EVENT]((IMU_Msg_t *)pMsg, pMsg->Hdr.length);
                    }
                    assert(kStatus_HAL_RpmsgSuccess == rpmsgStatus);
                    rpmsgStatus = HAL_ImuSendEventAck(imuHandle, (uint8_t *)&pMsg->PayloadPtr[0], 1);
                    break;

                case IMU_MSG_RX_DATA:
                case IMU_MSG_MULTI_RX_DATA:
                    (void)memcpy((uint8_t *)&localImuMsgRx, (uint8_t *)pMsg, sizeof(IMU_Msg_t));
                    if (imuHandle->imuHandler[IMU_MSG_RX_DATA] != NULL)
                    {
                        rpmsgStatus = imuHandle->imuHandler[IMU_MSG_RX_DATA]((IMU_Msg_t *)pMsg, pMsg->Hdr.length);
                    }
                    pMsg        = &localImuMsgRx;
                    rpmsgStatus = HAL_ImuFreeRxBuf(imuHandle, (uint8_t *)&pMsg->PayloadPtr[0], pMsg->Hdr.length);
                    break;
                case IMU_MSG_RPMSG:
                    rpmsg_msg = (struct rpmsg_std_msg *)&pMsg->PayloadPtr[0];
                    ept       = (hal_rpmsg_state_t *)HAL_RpmsgGetEndpointFromAddr(imuHandle, rpmsg_msg->hdr.dst);
                    if (NULL != ept)
                    {
                        if (ept->rx.callback != NULL)
                        {
                            rpmsgStatus = (hal_rpmsg_status_t)ept->rx.callback(
                                ept->rx.param, (uint8_t *)rpmsg_msg->data, rpmsg_msg->hdr.len);
                        }
                    }
                    if ((hal_rpmsg_return_status_t)rpmsgStatus == kStatus_HAL_RL_RELEASE)
                    {
                        rpmsgStatus = HAL_ImuSendRpmsgFreeBuf(imuHandle, (uint8_t *)&rpmsg_msg->data);
                    }
                    break;

                default:
                    // Do nothing for the commands without expansion.
                    break;
            }

            assert(kStatus_HAL_RpmsgSuccess == rpmsgStatus);
        }
    }

    if (isUnlockMsgReqd)
    {
        (void)HAL_ImuSendUnlock(imuHandle);
    }

    (void)os_InterruptMaskSet(IMULINKID_TO_IRQID((imu_link_t)imuHandle->imuLink));
    return (hal_rpmsg_status_t)rpmsgStatus;
}

#if defined(CPU2)
static void HAL_ImuMain(void *argv)
{
    uint32_t Events = 0;
    uint32_t imuLinkId;

    while (TRUE)
    {
#if (defined(USE_RTOS) && (USE_RTOS > 0U))
        (void)HAL_ImuPutTaskLock();
#endif
        (void)OSA_EventWait((osa_event_handle_t)ImuQFlagsRef, IMU_EVENT_TRIGGERS, 0, osaWaitForever_c, &Events);
        if (Events == 0U)
        {
            if (gUseRtos_c == 0U)
            {
                break;
            }
            else
            {
                continue;
            }
        }
#if (defined(USE_RTOS) && (USE_RTOS > 0U))
        (void)HAL_ImuGetTaskLock();
#endif
        /*! Check for all IMU links event/ISR has occured
         *  Only MSG ready events considered
         */
        for (imuLinkId = 0; imuLinkId < (uint32_t)kIMU_LinkMax; imuLinkId++)
        {
            if ((Events & (1U << imuLinkId)) != 0U)
            {
                (void)HAL_ImuReceive((uint8_t)imuLinkId);
            }
        }
        if (gUseRtos_c == 0U)
        {
            break;
        }
    }
}
#else

static void HAL_ImuMainCpu13(void *argv
#ifdef __ZEPHYR__
                             ,
                             void *argv2,
                             void *argv3
#endif
)
{
    uint32_t Events = 0;

    while (TRUE)
    {
#if (defined(USE_RTOS) && (USE_RTOS > 0U))
        (void)HAL_ImuPutTaskLock();
#endif

#ifdef __ZEPHYR__
        Events = k_event_wait(&ImuQ13FlagsRef, IMU_EVENT_TRIGGERS, 0, K_FOREVER);
        k_event_clear(&ImuQ13FlagsRef, (1U << kIMU_LinkCpu1Cpu3));
#else
        (void)OSA_EventWait((osa_event_handle_t)ImuQ13FlagsRef, IMU_EVENT_TRIGGERS, 0, osaWaitForever_c, &Events);
#endif

        if (Events == 0U)
        {
            if (gUseRtos_c == 0U)
            {
                break;
            }
            else
            {
                continue;
            }
        }
#if (defined(USE_RTOS) && (USE_RTOS > 0U))
        (void)HAL_ImuGetTaskLock();
#endif
        /*! Check for CPU1 to CPU3 IMU links event/ISR has occured
         *  Only MSG ready events considered
         */
        (void)HAL_ImuReceive(kIMU_LinkCpu1Cpu3);

        if (gUseRtos_c == 0U)
        {
            break;
        }
    }
}

static void HAL_ImuMainCpu23(void *argv
#ifdef __ZEPHYR__
                             ,
                             void *argv2,
                             void *argv3
#endif
)
{
    uint32_t Events = 0;

    while (TRUE)
    {
#if 0
        HAL_ImuPutTaskLock();
#endif

#ifdef __ZEPHYR__
        Events = k_event_wait(&ImuQ23FlagsRef, IMU_EVENT_TRIGGERS, 0, K_FOREVER);
        k_event_clear(&ImuQ23FlagsRef, (1U << kIMU_LinkCpu2Cpu3));
#else
        (void)OSA_EventWait((osa_event_handle_t)ImuQ23FlagsRef, IMU_EVENT_TRIGGERS, 0, osaWaitForever_c, &Events);
#endif

        if (Events == 0U)
        {
            if (gUseRtos_c == 0U)
            {
                break;
            }
            else
            {
                continue;
            }
        }
#if 0
        HAL_ImuGetTaskLock();
#endif
        /*! Check for CPU2 to CPU3 IMU links event/ISR has occured
         *  Only MSG ready events considered
         */

        (void)HAL_ImuReceive(kIMU_LinkCpu2Cpu3);

        if (gUseRtos_c == 0U)
        {
            break;
        }
    }
}
#endif

static void HAL_ImuTaskInit(uint8_t link)
{
#if defined(CPU2)
    (void)link;

    if (((imu_init_flag & ((1U << (uint8_t)kIMU_LinkMax) - 1U)) == 0U) && imu_task_flag == 0U)
    {
        (void)OSA_TaskCreate((osa_task_handle_t)ImuTaskHandle, OSA_TASK(HAL_ImuMain), NULL);
        (void)OSA_EventCreate((osa_event_handle_t)ImuQFlagsRef, 1U);
        imu_task_flag = 1;
    }
#else
    if (link == kIMU_LinkCpu1Cpu3 && (imu_task_flag & (1U << link)) == 0)
    {
#ifdef __ZEPHYR__
        ImuTaskCpu13 = k_thread_create(&ImuTaskHandleCpu13, ImuTaskStackCpu13, K_THREAD_STACK_SIZEOF(ImuTaskStackCpu13),
                                       HAL_ImuMainCpu13, NULL, NULL, NULL, IMU_TASK_PRIORITY, 0, K_NO_WAIT);
        k_thread_name_set(ImuTaskCpu13, "HAL_ImuMainCpu13");
#else
        (void)OSA_TaskCreate((osa_task_handle_t)ImuTaskHandleCpu13, OSA_TASK(HAL_ImuMainCpu13), NULL);
        (void)OSA_EventCreate((osa_event_handle_t)ImuQ13FlagsRef, 1U);
#endif
        imu_task_flag |= (1U << link);
    }
    else if (link == kIMU_LinkCpu2Cpu3 && (imu_task_flag & (1U << link)) == 0)
    {
#ifdef __ZEPHYR__
        ImuTaskCpu23 = k_thread_create(&ImuTaskHandleCpu23, ImuTaskStackCpu23, K_THREAD_STACK_SIZEOF(ImuTaskStackCpu23),
                                       HAL_ImuMainCpu23, NULL, NULL, NULL, IMU_TASK_PRIORITY, 0, K_NO_WAIT);
        k_thread_name_set(ImuTaskCpu23, "HAL_ImuMainCpu23");
#else
        (void)OSA_TaskCreate((osa_task_handle_t)ImuTaskHandleCpu23, OSA_TASK(HAL_ImuMainCpu23), NULL);
        (void)OSA_EventCreate((osa_event_handle_t)ImuQ23FlagsRef, 1U);
#endif
        imu_task_flag |= (1U << link);
    }
    else
    {
        ; /* No necessary actions. */
    }
#endif
}

static void HAL_ImuTaskDeinit(uint8_t link)
{
#if defined(CPU2)
    (void)link;

    if (imu_init_flag == 0U && imu_task_flag != 0U)
    {
        (void)OSA_EventDestroy((osa_event_handle_t)ImuQFlagsRef);
        (void)OSA_TaskDestroy(ImuTaskHandle);
        imu_task_flag = 0;
    }
#else
    if (link == kIMU_LinkCpu1Cpu3 && (imu_task_flag & (1U << link)) != 0)
    {
#ifndef __ZEPHYR__
        (void)OSA_EventDestroy((osa_event_handle_t)ImuQ13FlagsRef);
        (void)OSA_TaskDestroy(ImuTaskHandleCpu13);
#endif
        imu_task_flag &= ~(1U << link);
    }
    else if (link == kIMU_LinkCpu2Cpu3 && (imu_task_flag & (1U << link)) != 0)
    {
#ifndef __ZEPHYR__
        (void)OSA_EventDestroy((osa_event_handle_t)ImuQ23FlagsRef);
        (void)OSA_TaskDestroy(ImuTaskHandleCpu23);
#endif
        imu_task_flag &= ~(1U << link);
    }
    else
    {
        ; /* No necessary actions. */
    }
#endif
}

hal_rpmsg_status_t HAL_ImuInit(imu_link_t link)
{
    hal_imu_handle_t *imuHandle;
    hal_rpmsg_status_t state = kStatus_HAL_RpmsgSuccess;
    uint8_t i;
    OSA_SR_ALLOC();

    assert(kIMU_LinkMax > link);
    imuHandle          = &imuHandleCh[link];
    imuHandle->imuLink = (uint8_t)link;
    OSA_ENTER_CRITICAL();

#if defined(IMU_GDMA_ENABLE) && (IMU_GDMA_ENABLE == 1)
    if (0U == imu_init_flag)
    {
        HAL_InitGdma();
    }
#endif

    /*! IMU and its interrupt are initialized once for each IMU link */
    if ((imu_init_flag & (1U << imuHandle->imuLink)) == 0U)
    {
        HAL_ImuTaskInit(imuHandle->imuLink);

        if (IMU_Init(link) != (int)kStatus_HAL_RpmsgSuccess)
        {
            return kStatus_HAL_RpmsgError;
        }
        IMU_ClearPendingInterrupts(link, IMU_MSG_FIFO_CNTL_MSG_RDY_INT_CLR_MASK);
        os_ClearPendingISR(IMULINKID_TO_IRQID(link));
        /* Interrupt must be maskable by FreeRTOS critical section */
        NVIC_SetPriority(IMULINKID_TO_IRQID(link), IMU_ISR_PRIORITY);
        (void)os_InterruptMaskSet(IMULINKID_TO_IRQID(link));
#if defined(CPU2)
        if (kIMU_LinkCpu2Cpu3 == link)
        {
            for (i = 0; i < RPMSG_TXQ23_BUFSIZE; i++)
            {
                (void)HAL_RpmsgPutTxBuf(imuHandle, (uint8_t *)rpmsgTxBuf23[i]);
            }
        }
#else
        imuHandle->wlanTxqCtl.writeIndex  = 0;
        imuHandle->wlanTxqCtl.readIndex   = 0;
        imuHandle->imuMsgBufIdx           = 0;
        imuHandle->rpmsgTxqCtl.writeIndex = 0;
        imuHandle->rpmsgTxqCtl.readIndex  = 0;
        if (kIMU_LinkCpu1Cpu3 == link)
        {
            for (i = 0; i < RPMSG_TXQ13_BUFSIZE; i++)
            {
                (void)HAL_RpmsgPutTxBuf(imuHandle, (uint8_t *)rpmsgTxBuf13[i]);
            }
        }
        else if (kIMU_LinkCpu2Cpu3 == link)
        {
            for (i = 0; i < RPMSG_TXQ23_BUFSIZE; i++)
            {
                (void)HAL_RpmsgPutTxBuf(imuHandle, (uint8_t *)rpmsgTxBuf23[i]);
            }
        }
        else
        {
            ; /* No necessary actions. */
        }
#endif
        LIST_init(&imuHandle->eptList);
        imu_init_flag |= (1U << imuHandle->imuLink);
    }

    /*! Could be moved out from rpmsg_init() */
    if (imu_init_flag == ((1U << kIMU_LinkMax) - 1U)) /*! All IMU links are initalized */
    {
        HAL_ImuSetCpuReadyFlag(1U /*! Set CPU1 state */);
    }

    if ((uint8_t)IMU_UNINITIALIZED == imuHandle->imuSyncState)
    {
        state = HAL_ImuSendSync(imuHandle);
    }

    OSA_EXIT_CRITICAL();
    (void)state;
    return kStatus_HAL_RpmsgSuccess;
}

hal_rpmsg_status_t HAL_ImuDeinit(imu_link_t link, uint32_t flag)
{
    hal_imu_handle_t *imuHandle;
    hal_rpmsg_status_t state = kStatus_HAL_RpmsgSuccess;
    OSA_SR_ALLOC();

    assert(kIMU_LinkMax > link);
    imuHandle = &imuHandleCh[link];
    OSA_ENTER_CRITICAL();

    if ((flag & (1U << 0U)) == 0U)
    {
        (void)HAL_ImuReturnAllTxBuf(link);
        state = HAL_ImuSendShutdown(imuHandle);
        if (kStatus_HAL_RpmsgError == state)
        {
            OSA_EXIT_CRITICAL();
            return kStatus_HAL_RpmsgError;
        }
    }

    IMU_ClearPendingInterrupts((imu_link_t)imuHandle->imuLink, IMU_MSG_FIFO_CNTL_MSG_RDY_INT_CLR_MASK);
    IMU_ClearPendingInterrupts((imu_link_t)imuHandle->imuLink, IMU_MSG_FIFO_CNTL_SP_AV_INT_CLR_MASK);
    (void)os_InterruptMaskClear(IMULINKID_TO_IRQID((imu_link_t)imuHandle->imuLink));
    IMU_Deinit((imu_link_t)imuHandle->imuLink);
    imuHandle->imuSyncState                  = (uint8_t)IMU_UNINITIALIZED;
    *IMU_MSG_CUR_MAGIC_P(imuHandle->imuLink) = 0;
    imu_init_flag &= ~(1U << imuHandle->imuLink);
    imuHandle->wlanTxqCtl.writeIndex         = 0;
    imuHandle->wlanTxqCtl.readIndex          = 0;
    imuHandle->imuMsgBufIdx                  = 0;
    imuHandle->cmd_buffer                    = NULL;
    imuHandle->cmd_buffer_available          = 0;
    imuHandle->cmd_response_buffer_available = 0;

    if ((flag & (1U << 0U)) == 0U)
    {
        while (*IMU_MSG_PEER_MAGIC_P((imu_link_t)imuHandle->imuLink) != 0)
        {
        }
    }

    if ((flag & (1U << 1U)) == 0U)
    {
        HAL_ImuTaskDeinit(imuHandle->imuLink);
    }

    OSA_EXIT_CRITICAL();
    return kStatus_HAL_RpmsgSuccess;
}

hal_rpmsg_status_t HAL_RpmsgInit(hal_rpmsg_handle_t handle, hal_rpmsg_config_t *config)
{
    hal_rpmsg_status_t state = kStatus_HAL_RpmsgSuccess;
    hal_rpmsg_state_t *rpmsgHandle;
    hal_imu_handle_t *imuHandle;
    uint32_t Events;
    OSA_SR_ALLOC();

    assert(HAL_RPMSG_HANDLE_SIZE >= sizeof(hal_rpmsg_state_t));
    assert(NULL != handle);
    assert(NULL != config);
    assert((uint8_t)kIMU_LinkMax > config->imuLink);
    rpmsgHandle = (hal_rpmsg_state_t *)handle;

    OSA_ENTER_CRITICAL();

    if (rpmsg_init_flag == 0U)
    {
#ifdef __ZEPHYR__
        k_event_init(&rpmsgQFlagsRef);
#else
        (void)OSA_EventCreate((osa_event_handle_t)rpmsgQFlagsRef, 1U);
#endif
        rpmsg_init_flag = 1U;
    }

    state = HAL_ImuInit((imu_link_t)config->imuLink);
    if (kStatus_HAL_RpmsgError == state)
    {
        OSA_EXIT_CRITICAL();
        return kStatus_HAL_RpmsgError;
    }

    rpmsgHandle->imuLink        = config->imuLink;
    rpmsgHandle->local_addr     = config->local_addr;
    rpmsgHandle->remote_addr    = config->remote_addr;
    rpmsgHandle->rx.callback    = config->callback;
    rpmsgHandle->rx.param       = config->param;
    rpmsgHandle->eptLinkIsReady = FALSE;
    LIST_elemInit(&rpmsgHandle->eptLink);

    if (NULL == HAL_RpmsgCreateEndpoint(rpmsgHandle))
    {
        OSA_EXIT_CRITICAL();
        return kStatus_HAL_RpmsgError;
    }

    imuHandle = &imuHandleCh[rpmsgHandle->imuLink];

    OSA_EXIT_CRITICAL();

    while (kStatus_HAL_RpmsgError == HAL_ImuLinkIsUp(imuHandle->imuLink))
    {
#if defined(USE_RTOS) && (USE_RTOS == 1)
        OSA_TimeDelay(IMU_LINK_WAIT_DELAY_MS);
#else
        (void)HAL_ImuReceive(rpmsgHandle->imuLink);
#endif
    }

    while (FALSE == rpmsgHandle->eptLinkIsReady)
    {
        OSA_ENTER_CRITICAL();

        state = HAL_ImuSendRpmsgEptQuiry(imuHandle, rpmsgHandle->remote_addr);

        OSA_EXIT_CRITICAL();

#if defined(USE_RTOS) && (USE_RTOS == 1U)
#ifdef __ZEPHYR__
        Events = k_event_wait(&rpmsgQFlagsRef, RPMSG_EVENT_ENDPOINT_QUERY_RSP << imuHandle->imuLink, 0, K_FOREVER);
        k_event_clear(&rpmsgQFlagsRef, RPMSG_EVENT_ENDPOINT_QUERY_RSP << imuHandle->imuLink);
#else
        (void)OSA_EventWait((osa_event_handle_t)rpmsgQFlagsRef, RPMSG_EVENT_ENDPOINT_QUERY_RSP << imuHandle->imuLink, 0,
                            osaWaitForever_c, &Events);
#endif
#else
        while (TRUE) /* Wait for RPMSG_EVENT_ENDPOINT_QUERY_RSP */
        {
            (void)HAL_ImuReceive(rpmsgHandle->imuLink);
            (void)OSA_EventWait((osa_event_handle_t)rpmsgQFlagsRef,
                                RPMSG_EVENT_ENDPOINT_QUERY_RSP << imuHandle->imuLink, 0, osaWaitForever_c, &Events);
            if (Events != 0U)
            {
                break;
            }
        }
#endif
    }

    return state;
}

hal_rpmsg_status_t HAL_RpmsgDeinit(hal_rpmsg_handle_t handle)
{
    hal_rpmsg_state_t *rpmsgHandle;
    hal_rpmsg_status_t state = kStatus_HAL_RpmsgSuccess;
    OSA_SR_ALLOC();

    assert(NULL != handle);
    rpmsgHandle = (hal_rpmsg_state_t *)handle;
    OSA_ENTER_CRITICAL();
    state = HAL_RpmsgDestroyEndpoint(rpmsgHandle);

    OSA_EXIT_CRITICAL();

    return state;
}

hal_rpmsg_status_t HAL_RpmsgSend(hal_rpmsg_handle_t handle, uint8_t *data, uint32_t length)
{
    hal_rpmsg_status_t state = kStatus_HAL_RpmsgSuccess;
    hal_rpmsg_state_t *rpmsgHandle;
    hal_imu_handle_t *imuHandle;
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    OSA_SR_ALLOC();
    uint8_t *rpmsg_tx_buf;
    struct rpmsg_std_msg localRpmsg;

    assert(HAL_RPMSG_HANDLE_SIZE >= sizeof(hal_rpmsg_state_t));
    assert(NULL != handle);
    assert(NULL != data);

    rpmsgHandle = (hal_rpmsg_state_t *)handle;
    imuHandle   = &imuHandleCh[rpmsgHandle->imuLink];

    assert(kStatus_HAL_RpmsgSuccess == HAL_ImuLinkIsUp(imuHandle->imuLink));
    assert(rpmsgHandle->eptLinkIsReady == TRUE);

    if (rpmsgHandle->imuLink == (uint8_t)kIMU_LinkCpu2Cpu3)
    {
        assert(RPMSG_TXQ23_BUFLENGTH >= length);
    }
    else
    {
        assert(RPMSG_TXQ13_BUFLENGTH >= length);
    }

    rpmsg_tx_buf = HAL_RpmsgAllocTxBuffer(handle, length);

    if (NULL == rpmsg_tx_buf)
    {
        return kStatus_HAL_RpmsgError;
    }
    else
    {
        OSA_ENTER_CRITICAL();

        // To be DMAed
        (void)HAL_IMU_MEMCPY(rpmsg_tx_buf, data, length);
        localRpmsg.hdr.src   = rpmsgHandle->local_addr;
        localRpmsg.hdr.dst   = rpmsgHandle->remote_addr;
        localRpmsg.hdr.len   = (uint16_t)length;
        localRpmsg.hdr.flags = 0;
        localRpmsg.data      = (uint32_t)rpmsg_tx_buf;

        if (kStatus_HAL_RpmsgSuccess == HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_RPMSG, 0U,
                                                               (uint8_t *)&localRpmsg,
                                                               (3U + sizeof(struct rpmsg_std_msg)) >> 2U))
        {
            seq_num++;
        }
        else
        {
            (void)HAL_RpmsgPutTxBuf(imuHandle, rpmsg_tx_buf);
            rpmsgStatus = kStatus_HAL_RpmsgError;
        }

        OSA_EXIT_CRITICAL();
    }

    (void)state;
    return rpmsgStatus;
}

hal_rpmsg_status_t HAL_RpmsgNoCopySend(hal_rpmsg_handle_t handle, uint8_t *data, uint32_t length)
{
    hal_rpmsg_status_t state = kStatus_HAL_RpmsgSuccess;
    hal_rpmsg_state_t *rpmsgHandle;
    hal_imu_handle_t *imuHandle;
    hal_rpmsg_status_t rpmsgStatus = kStatus_HAL_RpmsgSuccess;
    OSA_SR_ALLOC();

    struct rpmsg_std_msg localRpmsg;

    assert(HAL_RPMSG_HANDLE_SIZE >= sizeof(hal_rpmsg_state_t));
    assert(NULL != handle);
    assert(NULL != data);

    rpmsgHandle = (hal_rpmsg_state_t *)handle;
    imuHandle   = &imuHandleCh[rpmsgHandle->imuLink];

    assert(kStatus_HAL_RpmsgSuccess == HAL_ImuLinkIsUp(imuHandle->imuLink));
    assert(rpmsgHandle->eptLinkIsReady == TRUE);

    OSA_ENTER_CRITICAL();

    localRpmsg.hdr.src   = rpmsgHandle->local_addr;
    localRpmsg.hdr.dst   = rpmsgHandle->remote_addr;
    localRpmsg.hdr.len   = (uint16_t)length;
    localRpmsg.hdr.flags = 0;
    localRpmsg.data      = (uint32_t)data;

    if (kStatus_HAL_RpmsgSuccess == HAL_ImuSendMsgBlocking(imuHandle, (uint8_t)IMU_MSG_RPMSG, 0U,
                                                           (uint8_t *)&localRpmsg,
                                                           (3U + sizeof(struct rpmsg_std_msg)) >> 2U))
    {
        seq_num++;
    }
    else
    {
        rpmsgStatus = kStatus_HAL_RpmsgError;
    }

    OSA_EXIT_CRITICAL();
    (void)state;
    return rpmsgStatus;
}

hal_rpmsg_status_t HAL_ImuInstallCallback(uint8_t imuLink, imu_callback_t callback, uint8_t type)
{
    hal_imu_handle_t *imuHandle;

    assert((uint8_t)kIMU_LinkMax > imuLink);
    assert((uint8_t)IMU_MSG_MAX > type);
    imuHandle                   = &imuHandleCh[imuLink];
    imuHandle->imuHandler[type] = callback;

    return kStatus_HAL_RpmsgSuccess;
}

hal_rpmsg_status_t HAL_ImuInstallIrqCallback(uint8_t imuLink, imu_irq_callback_t callback)
{
    assert((uint8_t)kIMU_LinkMax > imuLink);

    imuIrqCallback[imuLink] = callback;

    return kStatus_HAL_RpmsgSuccess;
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

void HAL_RpmsgSetEvent(uint32_t Event)
{
#if defined(CPU2)
    (void)OSA_EventSet((osa_event_handle_t)ImuQFlagsRef, Event);
#else
    if ((Event & (1U << kIMU_LinkCpu1Cpu3)) != 0U)
    {
#ifdef __ZEPHYR__
        k_event_post(&ImuQ13FlagsRef, Event);
#else
        (void)OSA_EventSet((osa_event_handle_t)ImuQ13FlagsRef, Event);
#endif
    }
    else
    {
#ifdef __ZEPHYR__
        k_event_post(&ImuQ23FlagsRef, Event);
#else
        (void)OSA_EventSet((osa_event_handle_t)ImuQ23FlagsRef, Event);
#endif
    }
#endif
}

#if defined(CPU2)
void CPU1_TO_CPU2_MSG_RDY_IMU_INT_IRQHandler(void)
{
    uint32_t irq_num = IMULINKID_TO_IRQID(kIMU_LinkCpu1Cpu2);

    /* Mask IMU ICU interrupt */
    (void)os_InterruptMaskClear(irq_num);

    if (!IMU_RX_FIFO_EMPTY(kIMU_LinkCpu1Cpu2))
    {
        HAL_RpmsgSetEvent(1U << (uint8_t)kIMU_LinkCpu1Cpu2);
    }
    else
    {
        IMU_ClearPendingInterrupts(kIMU_LinkCpu1Cpu2, IMU_MSG_FIFO_CNTL_MSG_RDY_INT_CLR_MASK);
        (void)os_InterruptMaskSet(irq_num);
    }
}

void CPU3_TO_CPU2_MSG_RDY_IMU_INT_IRQHandler(void)
{
    uint32_t irq_num = IMULINKID_TO_IRQID(kIMU_LinkCpu2Cpu3);

    /* Mask IMU ICU interrupt */
    (void)os_InterruptMaskClear(irq_num);

    if (!IMU_RX_FIFO_EMPTY(kIMU_LinkCpu2Cpu3))
    {
        HAL_RpmsgSetEvent(1U << (uint8_t)kIMU_LinkCpu2Cpu3);
    }
    else
    {
        IMU_ClearPendingInterrupts(kIMU_LinkCpu2Cpu3, IMU_MSG_FIFO_CNTL_MSG_RDY_INT_CLR_MASK);
        (void)os_InterruptMaskSet(irq_num);
    }
}
#else

void WL_MCI_WAKEUP0_DriverIRQHandler(void)
{
    IRQn_Type irq_num;
#if defined(CPU2)
    irq_num = IRQ_IMU_CPU32;
#else
    irq_num = IRQ_IMU_CPU13;
#endif

    /* Mask IMU ICU interrupt */
    (void)os_InterruptMaskClear(irq_num);

    if (!IMU_RX_FIFO_EMPTY(kIMU_LinkCpu1Cpu3))
    {
        HAL_RpmsgSetEvent(1U << (uint8_t)kIMU_LinkCpu1Cpu3);
    }
    else
    {
        IMU_ClearPendingInterrupts(kIMU_LinkCpu1Cpu3, IMU_MSG_FIFO_CNTL_MSG_RDY_INT_CLR_MASK);
        (void)os_InterruptMaskSet(irq_num);
    }
}

void BLE_MCI_WAKEUP0_DriverIRQHandler(void)
{
    IRQn_Type irq_num;
#if defined(CPU2)
    irq_num = IRQ_IMU_CPU12;
#else
    irq_num = IRQ_IMU_CPU23;
#endif

    /* Mask IMU ICU interrupt */
    (void)os_InterruptMaskClear(irq_num);

    if (!IMU_RX_FIFO_EMPTY(kIMU_LinkCpu2Cpu3))
    {
        HAL_RpmsgSetEvent(1U << (uint8_t)kIMU_LinkCpu2Cpu3);
    }
    else
    {
        if (imuIrqCallback[kIMU_LinkCpu2Cpu3] != NULL)
        {
            imuIrqCallback[kIMU_LinkCpu2Cpu3]();
        }

        IMU_ClearPendingInterrupts(kIMU_LinkCpu2Cpu3, IMU_MSG_FIFO_CNTL_MSG_RDY_INT_CLR_MASK);
        (void)os_InterruptMaskSet(irq_num);
    }
}
#endif

void *HAL_RpmsgAllocTxBuffer(hal_rpmsg_handle_t handle, uint32_t size)
{
    hal_rpmsg_state_t *rpmsgHandle;
    hal_imu_handle_t *imuHandle;
    uint32_t retry = RPMSG_ALLOC_RETRY_COUNT;
    void *buf      = NULL;

    rpmsgHandle = (hal_rpmsg_state_t *)handle;

    if (rpmsgHandle->imuLink == (uint8_t)kIMU_LinkCpu2Cpu3)
    {
        assert(RPMSG_TXQ23_BUFLENGTH >= size);
    }
    else
    {
        assert(RPMSG_TXQ13_BUFLENGTH >= size);
    }

    assert(NULL != handle);

    imuHandle = &imuHandleCh[rpmsgHandle->imuLink];

    buf = HAL_RpmsgGetTxBuf(imuHandle);

    while ((buf == NULL) && (retry != 0U))
    {
        /* Sleep current thread, then try to allocate again */
        OSA_TimeDelay(RPMSG_ALLOC_FAILED_DELAY_MS);
        buf = HAL_RpmsgGetTxBuf(imuHandle);
        retry--;
    }

    return buf;
}

hal_rpmsg_status_t HAL_RpmsgFreeRxBuffer(hal_rpmsg_handle_t handle, uint8_t *data)
{
    hal_rpmsg_state_t *rpmsgHandle;
    hal_imu_handle_t *imuHandle;

    assert(NULL != handle);

    rpmsgHandle = (hal_rpmsg_state_t *)handle;
    imuHandle   = &imuHandleCh[rpmsgHandle->imuLink];

    return HAL_ImuSendRpmsgFreeBuf(imuHandle, data);
}

bool HAL_ImuIsTxBufQueueEmpty(uint8_t imuLink)
{
    hal_imu_handle_t *imuHandle;
    IMU_WLAN_TXQ_CTRL_st *wlanTxqCtl;

    assert((uint8_t)kIMU_LinkMax > imuLink);

    imuHandle  = &imuHandleCh[imuLink];
    wlanTxqCtl = &imuHandle->wlanTxqCtl;

    return (IS_WLAN_TXBQ_EMPTY(wlanTxqCtl));
}

#if (defined(USE_RTOS) && (USE_RTOS > 0U))
hal_rpmsg_status_t HAL_ImuCreateTaskLock(void)
{
#ifdef __ZEPHYR__
    k_mutex_init(&imu_task_lock);
#else
    osa_status_t status;

    if ((*(uint32_t *)(osa_mutex_handle_t)imu_task_lock) == 0)
    {
        status = OSA_MutexCreate((osa_mutex_handle_t)imu_task_lock);
        if (status == KOSA_StatusError)
        {
            return kStatus_HAL_RpmsgError;
        }
    }
#endif
    return kStatus_HAL_RpmsgSuccess;
}

void HAL_ImuDeleteTaskLock(void)
{
#ifndef __ZEPHYR__
    if ((*(uint32_t *)(osa_mutex_handle_t)imu_task_lock) != 0)
    {
        (void)OSA_MutexDestroy((osa_mutex_handle_t)imu_task_lock);
        (*(uint32_t *)(osa_mutex_handle_t)imu_task_lock) = 0;
    }
#endif
}

hal_rpmsg_status_t HAL_ImuGetTaskLock(void)
{
#ifdef __ZEPHYR__
    int ret = k_mutex_lock(&imu_task_lock, K_FOREVER);

    return (ret == 0) ? kStatus_HAL_RpmsgSuccess : kStatus_HAL_RpmsgError;
#else
    osa_status_t status;

    if ((*(uint32_t *)(osa_mutex_handle_t)imu_task_lock) == 0)
    {
        return kStatus_HAL_RpmsgSuccess;
    }

    status = OSA_MutexLock((osa_mutex_handle_t)imu_task_lock, osaWaitForever_c);
    return status == KOSA_StatusSuccess ? kStatus_HAL_RpmsgSuccess : kStatus_HAL_RpmsgError;
#endif
}

hal_rpmsg_status_t HAL_ImuPutTaskLock(void)
{
#ifdef __ZEPHYR__
    int ret = k_mutex_unlock(&imu_task_lock);

    return (ret == 0) ? kStatus_HAL_RpmsgSuccess : kStatus_HAL_RpmsgError;
#else

    osa_status_t status;

    if ((*(uint32_t *)(osa_mutex_handle_t)imu_task_lock) == 0)
    {
        return kStatus_HAL_RpmsgSuccess;
    }

    status = OSA_MutexUnlock((osa_mutex_handle_t)imu_task_lock);
    return status == KOSA_StatusSuccess ? kStatus_HAL_RpmsgSuccess : kStatus_HAL_RpmsgError;
#endif
}
#endif
