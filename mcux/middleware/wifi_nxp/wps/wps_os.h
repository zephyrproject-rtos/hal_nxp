/** @file wps_os.h
 *
 *  @brief This file contains definition for timer and socket read functions
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _WPS_OS_H_
#define _WPS_OS_H_

#include "wps_def.h"
#include "wps_l2.h"

#include "wifi_nxp_wps.h"
#include <wm_os.h>
#include <wm_net.h>

/* Data structure definition for main loop */
struct wps_sock_s
{
    /** socket no */
    int sock;
    /** private data for callback */
    void *callback_data;
    /** handler */
    void (*handler)(int sock, void *sock_ctx);
};

struct wps_timeout_s
{
    /** next pointer */
    struct wps_timeout_s *next;
    /** time */
    struct timeval time;
    /** private data for callback */
    void *callback_data;
    /** timeout handler */
    void (*handler)(void *timeout_ctx);
};

typedef struct wps_loop_s
{
    /** terminate */
    int terminate;
    /** max socket number */
    int max_sock;
    /** read count */
    int reader_count;
    /** read socket */
    struct wps_sock_s *readers;
    /** timeout */
    struct wps_timeout_s *timeout;
} WPS_LOOP_S;

struct wps_thread_t
{
    int initialized;
    os_queue_t cmd_queue;
    os_queue_t data_queue;
    os_queue_pool_t cmd_queue_data;
    os_queue_pool_t data_queue_data;
    int (*cb)(enum wps_event event, void *data, uint16_t len);
};

#ifndef timer_cmp
#define timer_cmp(a, b) (((a)->tv_sec == (b)->tv_sec) ? ((a)->tv_usec < (b)->tv_usec) : ((a)->tv_sec < (b)->tv_sec))
#endif
#ifndef timersub
#define timersub(a, b, result)                           \
    do                                                   \
    {                                                    \
        (result)->tv_sec  = (a)->tv_sec - (b)->tv_sec;   \
        (result)->tv_usec = (a)->tv_usec - (b)->tv_usec; \
        if ((result)->tv_usec < 0)                       \
        {                                                \
            --(result)->tv_sec;                          \
            (result)->tv_usec += 1000000;                \
        }                                                \
    } while (0)
#endif

/**
 *  @brief Process interface deinit
 *
 *  @param wps_s        A pointer to global WPS structure
 *  @return             None
 */
void wps_intf_deinit(WPS_DATA *wps_s);

/**
 *  @brief Process main loop initialization
 *
 *  @param wps_s    A pointer to global WPS structure
 *  @return         WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_loop_init(WPS_DATA *wps_s);

/**
 *  @brief Process main loop free
 *
 *  @param wps_s        A pointer to global WPS structure
 *  @return             None
 */
void wps_loop_deinit(WPS_DATA *wps_s);

/**
 *  @brief Register the signal handler to Linux kernel
 *
 *  @return         WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_set_signal_handler(void);

/**
 *  @brief Main loop procedure for socket read and timer functions
 *
 *  @return             None
 */
void wps_main_loop_proc(void);

/**
 *  @brief Disable main loop
 *
 *  @return         None
 */
void wps_main_loop_shutdown(void);

/**
 *  @brief Enable main loop
 *
 *  @return         None
 */
void wps_main_loop_enable(void);

/**
 *  @brief Check main loop status
 *
 *  @return         true or false
 */
bool is_wps_main_loop_running(void);
/**
 *  @brief Register a time-out handler to main loop timer function
 *
 *  @param secs             Time-out value in seconds
 *  @param usecs            Time-out value in micro-seconds
 *  @param handler          A function pointer of time-out handler
 *  @param callback_data    Private data for callback
 *  @return         WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_start_timer(unsigned int secs, unsigned int usecs, void (*handler)(void *user_data), void *callback_data);

/**
 *  @brief Cancel time-out handler to main loop timer function
 *
 *  @param handler          Time-out handler to be canceled
 *  @param callback_data    Private data for callback
 *  @return         Number of timer being removed
 */
int wps_cancel_timer(void (*handler)(void *timeout_ctx), void *callback_data);
void wps_peer_event_receive();
#endif /* _WPS_OS_H_ */
