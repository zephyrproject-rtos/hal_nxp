/*  Copyright 2026 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*! \file wlan_test_csi.h
 *  \brief CSI (Channel State Information) asynchronous processing APIs
 *
 *  This file provides APIs for asynchronous CSI data processing to prevent
 *  blocking of time-sensitive tasks (e.g., IMU, SDIO). The implementation
 *  uses a dedicated processing task and message queue to decouple CSI data
 *  reception from processing.
 *
 */

#ifndef __WLAN_TEST_CSI_H__
#define __WLAN_TEST_CSI_H__

#if CONFIG_CSI

#ifndef CONFIG_CSI_PROCESS_PRI
#define CONFIG_CSI_PROCESS_PRI OSA_PRIORITY_LOW
#endif

#ifndef CONFIG_WIFI_CSI_PROCESS_STACK_SIZE
#define CONFIG_WIFI_CSI_PROCESS_STACK_SIZE (1024)
#endif

/* Debug configuration - enables statistics tracking and verbose logging */
#ifndef CONFIG_CSI_DEBUG
#define CONFIG_CSI_DEBUG 0
#endif

/** CSI message structure for queue communication */
typedef struct {
    void *data_ptr;      /** Pointer to CSI data buffer */
    t_u16 data_len;      /** Length of CSI data in bytes */
} csi_msg_t;

#if CONFIG_CSI_DEBUG
/** CSI processing statistics (debug mode only) */
typedef struct {
    uint32_t processed_packets;       /** Total CSI packets processed */
    uint32_t fast_consume_count;      /** Fast consume */
    uint32_t enqueue_drop_count;      /** Packets dropped due to enqueue failuer */
    uint32_t processing_errors;       /** Processing error count */
    uint32_t max_queue_usage;         /** Peak queue occupancy (max messages) */
} csi_user_stats;
#endif

/**
 * @brief CSI processing task lifecycle states
 *
 * State machine for managing task creation/destruction:
 * IDLE -> CREATING -> RUNNING -> DESTROYING -> IDLE
 *
 * This prevents:
 * - Duplicate task creation (CREATING/RUNNING states block new create)
 * - Duplicate task destruction (DESTROYING state blocks new destroy)
 * - Destroy before create completes (CREATING state blocks destroy)
 */
typedef enum {
    CSI_TASK_STATE_IDLE,        /** No task exists - safe to create */
    CSI_TASK_STATE_CREATING,    /** Task creation in progress */
    CSI_TASK_STATE_RUNNING,     /** Task is running normally */
    CSI_TASK_STATE_DESTROYING   /** Task destruction in progress */
} csi_task_state_t;

int csi_data_recv_user(void *buffer, size_t data_len);

int csi_create_process_task(void);

int csi_destroy_process_task(void);

int csi_data_recv_user(void *buffer, size_t data_len);

#endif /* CONFIG_CSI */

#endif /* WLAN_TEST_CSI_H */
