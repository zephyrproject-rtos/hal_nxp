/** @file wlan_test_csi.c
 *
 *  @brief This file implements asynchronous CSI (Channel State Information) data
 *  processing to prevent blocking of time-sensitive tasks.
 *
 *  The implementation uses a dedicated processing task and message queue
 *  to decouple CSI data reception from processing.
 *
 *  Architecture:
 *    WiFi Driver Task -> Message Queue -> CSI Processing Task
 *    (fast callback)     (decoupling)     (actual processing)
 *
 *
 *  Copyright 2026 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include "osa.h"
#include "wlan.h"
#include "wifi.h"
#include "wlan_test_csi.h"
#include "wmlog.h"

#if CONFIG_CSI

/* HALT signal for graceful task shutdown
 *
 * Design rationale:
 * - Cannot use NULL (driver might legitimately pass NULL data_ptr)
 * - Use address of a static variable as unique sentinel value
 * - This is guaranteed to be a valid address but never a CSI data buffer
 * - More portable than hardcoded magic number (works on any architecture)
 */
static const char csi_halt_sentinel = 0;
#define CSI_HALT_SIGNAL ((void *)&csi_halt_sentinel)

#define w_csi_e(...) wmlog_e("wifi_csi", ##__VA_ARGS__)
#define w_csi_w(...) wmlog_w("wifi_csi", ##__VA_ARGS__)

#if CONFIG_CSI_DEBUG
#define w_csi_d(...) wmlog("wifi_csi", ##__VA_ARGS__)
#else
#define w_csi_d(...)
#endif

/* Message queue size matches driver buffer size for 1:1 mapping */
#define CSI_MSG_QUEUE_SIZE CONFIG_MAX_CSI_LOCAL_BUF

static void csi_process_task(void *arg);
static OSA_TASK_HANDLE_DEFINE(csi_process_task_handle);
static OSA_TASK_DEFINE(csi_process_task, CONFIG_CSI_PROCESS_PRI, 1, CONFIG_WIFI_CSI_PROCESS_STACK_SIZE, 0);

static OSA_MSGQ_HANDLE_DEFINE(csi_msg_queue, CSI_MSG_QUEUE_SIZE, sizeof(csi_msg_t));

static volatile csi_task_state_t csi_task_state = CSI_TASK_STATE_IDLE;

static uint32_t last_failed_count = 0;

#if CONFIG_CSI_DEBUG
static csi_user_stats wlan_csi_stat;
#endif

/**
 * @brief Enqueue CSI data for asynchronous processing
 *
 * This function is called from the WiFi driver task context (via callback).
 * It quickly enqueues the data pointer to the message queue and returns,
 * allowing the driver task to continue without blocking.
 *
 * The actual CSI data processing is performed by the dedicated csi_process_task()
 * in a separate task context, preventing blocking of time-sensitive operations
 * (IMU, SDIO) in the WiFi driver task.
 *
 * @param[in] buffer Pointer to CSI data buffer in driver's local buffer
 * @param[in] data_len Length of CSI data in bytes
 *
 * @return WM_SUCCESS if data successfully enqueued
 * @return -WM_FAIL if message queue is full (data will be dropped)
 */
int csi_data_recv_user(void *buffer, size_t data_len)
{
    csi_msg_t msg;
    int ret;

    /* Construct message with data pointer (not copying data itself) */
    msg.data_ptr = buffer;
    msg.data_len = (t_u16)data_len;

    /* Try to enqueue message - non-blocking operation */
    ret = OSA_MsgQPut((osa_msgq_handle_t)csi_msg_queue, &msg);
    if (ret != KOSA_StatusSuccess)
    {
#if CONFIG_CSI_DEBUG
            wlan_csi_stat.enqueue_drop_count++;
#endif
        return -WM_FAIL;
    }

#if CONFIG_CSI_DEBUG
    /* Track peak queue usage for performance analysis */
    t_u32 msg_count = OSA_MsgQAvailableMsgs((osa_msgq_handle_t)csi_msg_queue);
    if (msg_count > wlan_csi_stat.max_queue_usage)
    {
        wlan_csi_stat.max_queue_usage = msg_count;
    }
#endif

    return WM_SUCCESS;
}

/**
 * @brief Rapidly drain messages from queue to free queue buffer space
 *
 * This internal function is called when message queue overflow is detected,
 * indicating that the driver buffer is filling faster than the processing
 * task can consume. It quickly drains a specified number of messages from
 * the queue without full processing.
 *
 * NOTE: This is a demo implementation for fast processing CSI data.
 *       Users can define their own implementation based on specific requirements.
 *
 * @param[in] target_count Number of messages to consume from queue
 *
 * @return Number of messages actually consumed (may be less if queue empties)
 *
 */
static int fast_consume_queue(int target_count)
{
    csi_msg_t msg;
    int consumed = 0;

    w_csi_d(" Fast consume: target=%d messages\r\n", target_count);

    /** Rapidly consume messages without full processing */
    while (consumed < target_count)
    {
        if (OSA_MsgQGet((osa_msgq_handle_t)csi_msg_queue, &msg, 0) != KOSA_StatusSuccess)
        {
            break;
        }
#if CONFIG_CSI_DEBUG
        wlan_csi_stat.fast_consume_count++;
#endif
        /** Skip processing, just consume to make room */
        consumed++;
    }

    return consumed;
}

/**
 * @brief Detect queue overflow
 *
 * This function monitors driver callback failures as a signal that the message
 * queue has overflowed (become full).
 *
 * NOTE: If overflow occurs frequently, users should consider:
 *       1. Optimize CSI data processing to reduce processing time
 *       2. Increase CSI buffer count (CONFIG_MAX_CSI_LOCAL_BUF) to handle bursts
 *          (Note: This will increase memory footprint)
 *
 * @return cnt The count of queue overflow.
 *
 */
static int check_queue_overflow(void)
{
    t_u32 callback_failed_cnt = 0;
    wifi_get_csi_buff_status(NULL, NULL, NULL, &callback_failed_cnt);

    int cnt = callback_failed_cnt - last_failed_count;
    last_failed_count = callback_failed_cnt;

    return cnt;
}

/**
 * @brief User-defined CSI data processing callback
 *
 * This function is called by the CSI processing task to handle each CSI data packet.
 * It serves as the application-level processing point where custom CSI analysis,
 * logging, or forwarding can be implemented.
 *
 * Current Implementation:
 * - Prints notification message
 * - Dumps CSI data in hexadecimal format for debugging
 *
 * Customization Examples:
 * Users can modify this function to implement:
 * - Channel estimation and analysis
 * - CSI data filtering or preprocessing
 * - Data forwarding to external systems or cloud
 * - Real-time signal quality monitoring
 * - Statistical analysis and trending
 *
 * @param[in] buffer    Pointer to CSI data buffer
 * @param[in] data_len  Length of CSI data in bytes
 *
 * @return None
 *
 */
static void csi_user_process(void *buffer, size_t data_len)
{
    PRINTF("CSI user callback: Event CSI data\r\n");
    dump_hex(buffer, data_len);

#if CONFIG_CSI_DEBUG
    wlan_csi_stat.processed_packets++;
#endif
}

/**
 * @brief Main CSI data processing task
 *
 * This task runs in a separate context from the WiFi driver task,
 * continuously processing CSI data messages from the queue.
 *
 * @param[in] arg Unused (reserved for future use)
 *
 */
static void csi_process_task(void *arg)
{
    csi_msg_t msg;

    w_csi_d("CSI task started (pri=%d, stack=%d)\r\n",
            CONFIG_CSI_PROCESS_PRI, CONFIG_WIFI_CSI_PROCESS_STACK_SIZE);

    csi_task_state = CSI_TASK_STATE_RUNNING;

    while (csi_task_state == CSI_TASK_STATE_RUNNING)
    {
        OSA_MsgQGet((osa_msgq_handle_t)csi_msg_queue, &msg, osaWaitForever_c);

        /* Check for HALT signal */
        if (msg.data_ptr == CSI_HALT_SIGNAL)
        {
            w_csi_d("Received HALT signal\r\n");
            break;
        }

        /* Skip NULL data pointers (safety check) */
        if (msg.data_ptr == NULL)
        {
            w_csi_w("Warning: received NULL data_ptr, skipping\r\n");
            continue;
        }

        /**
         * Queue overflow detection and recovery
         *
         * Overflow occurs when: CSI data arrives faster than processing speed
         * Common causes: Slow csi_user_process(), low task priority, high CSI rate
         *
         * If overflow occurs frequently, apply optimizations:
         * 1. Optimize csi_user_process() (remove prints, simplify logic)
         * 2. Increase task priority (CONFIG_CSI_PROCESS_PRI)
         * 3. Increase buffer size (CONFIG_MAX_CSI_LOCAL_BUF)
         * 4. Set appropriate CSI filter conditions
         */
        while (check_queue_overflow() > 0)
        {
            t_u32 queue_size = OSA_MsgQAvailableMsgs((osa_msgq_handle_t)csi_msg_queue);
            if (queue_size > 0)
            {
                w_csi_d("Overflow: consuming %u msgs\r\n", queue_size);
                fast_consume_queue(queue_size);
            }
        }

        csi_user_process(msg.data_ptr, msg.data_len);
    }

#if CONFIG_CSI_DEBUG
    double csi_total_packets = wlan_csi_stat.processed_packets +
        wlan_csi_stat.fast_consume_count + wlan_csi_stat.enqueue_drop_count;

    double processed_rate = (double)wlan_csi_stat.processed_packets / csi_total_packets;
    double fast_consume_rate = (double)wlan_csi_stat.fast_consume_count / csi_total_packets;
    double enqueue_drop_rate = (double)wlan_csi_stat.enqueue_drop_count / csi_total_packets;
    w_csi_d("  === Final Statistics ===\r\n");
    w_csi_d("  Porcessed packets: %u, rate(%.2f%%)\r\n", wlan_csi_stat.processed_packets,
        processed_rate * 100);
    w_csi_d("  Fast consume: %u, rate(%.2f%%)\r\n", wlan_csi_stat.fast_consume_count,
        fast_consume_rate * 100);
    w_csi_d("  Enqueue drops: %u, rate(%.2f%%)\r\n", wlan_csi_stat.enqueue_drop_count,
        enqueue_drop_rate * 100);
    w_csi_d("  Max queue usage: %u/%u\r\n", wlan_csi_stat.max_queue_usage, CSI_MSG_QUEUE_SIZE);
    w_csi_d("===========================\r\n\r\n");
#endif

    w_csi_d(" Processing task exiting\r\n");
    OSA_TaskDestroy((osa_task_handle_t)csi_process_task_handle);
}


/**
 * @brief Create and start CSI processing task
 *
 * @return WM_SUCCESS if all initialization successful
 * @return -WM_FAIL if message queue or task creation fails
 *
 */
int csi_create_process_task(void)
{
    int ret = WM_SUCCESS;

    if (csi_task_state != CSI_TASK_STATE_IDLE)
    {
        const char *state_str[] = {
            [CSI_TASK_STATE_IDLE]       = "IDLE",
            [CSI_TASK_STATE_CREATING]   = "CREATING",
            [CSI_TASK_STATE_RUNNING]    = "RUNNING",
            [CSI_TASK_STATE_DESTROYING] = "DESTROYING"
        };

        (void)state_str;
        w_csi_w(" Task already exists (state: %s), skipping create\r\n",
                state_str[csi_task_state]);
        return WM_SUCCESS;  /* Not an error - task already ready */
    }

    csi_task_state = CSI_TASK_STATE_CREATING;

    /** Create message queue */
    ret = OSA_MsgQCreate((osa_msgq_handle_t)csi_msg_queue,
                        CSI_MSG_QUEUE_SIZE,
                        sizeof(csi_msg_t));
    if (ret != WM_SUCCESS)
    {
        w_csi_e(" Failed to create message queue\r\n");
        csi_task_state = CSI_TASK_STATE_IDLE;
        return -WM_FAIL;
    }

#if CONFIG_CSI_DEBUG
    memset(&wlan_csi_stat, 0, sizeof(wlan_csi_stat));
#endif

    /** Create processing task */
    ret = OSA_TaskCreate((osa_task_handle_t)csi_process_task_handle,
                        OSA_TASK(csi_process_task),
                        NULL);
    if (ret != WM_SUCCESS)
    {
        w_csi_e(" Failed to create processing task\r\n");
        OSA_MsgQDestroy((osa_msgq_handle_t)csi_msg_queue);
        csi_task_state = CSI_TASK_STATE_IDLE;
        return -WM_FAIL;
    }

    return WM_SUCCESS;
}

/**
 * @brief Stop and destroy CSI processing task
 *
 * CRITICAL: Caller MUST unregister CSI callback BEFORE calling this
 *
 * Correct sequence:
 * 1. wlan_unregister_csi_user_callback() <- First
 * 2. csi_destroy_process_task()          <- Second
 *
 * @return WM_SUCCESS on successful cleanup
 *
 */
int csi_destroy_process_task(void)
{
    if (csi_task_state != CSI_TASK_STATE_RUNNING)
    {
#if CONFIG_CSI_DEBUG
        const char *state_str[] = {
            [CSI_TASK_STATE_IDLE]       = "IDLE (no task exists)",
            [CSI_TASK_STATE_CREATING]   = "CREATING (wait for creation to complete)",
            [CSI_TASK_STATE_RUNNING]    = "RUNNING",
            [CSI_TASK_STATE_DESTROYING] = "DESTROYING (already in progress)"
        };

        w_csi_d(" Cannot destroy task (state: %s), skipping\r\n",
                state_str[csi_task_state]);
#endif
        return WM_SUCCESS;
    }

    csi_task_state = CSI_TASK_STATE_DESTROYING;

    /* Send HALT message and wait for task to self-destruct */
    csi_msg_t halt_msg = {CSI_HALT_SIGNAL, 0};
    OSA_MsgQPut((osa_msgq_handle_t)csi_msg_queue, &halt_msg);
    OSA_TimeDelay(100);

    /* Drain remaining messages if any (prevents queue access race) */
    t_u32 remaining_msgs = OSA_MsgQAvailableMsgs((osa_msgq_handle_t)csi_msg_queue);
    if (remaining_msgs > 0)
    {
        w_csi_w(" Warning: %u messages still in queue, draining...\r\n", remaining_msgs);

        csi_msg_t msg;
        t_u32 drained = 0;
        while (OSA_MsgQGet((osa_msgq_handle_t)csi_msg_queue, &msg, 0) == KOSA_StatusSuccess)
        {
            drained++;
        }

        w_csi_w(" Drained %u messages\r\n", drained);
    }

    /* Destroy queue after task is fully destroyed */
    OSA_MsgQDestroy((osa_msgq_handle_t)csi_msg_queue);
    csi_task_state = CSI_TASK_STATE_IDLE;

    w_csi_d(" Processing task and queue destroyed\r\n");
    return WM_SUCCESS;
}

#endif
