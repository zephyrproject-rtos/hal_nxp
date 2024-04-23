/** @file wps_os.c
 *
 *  @brief This file contains timer and socket read functions
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#if defined(__arm__) && !defined(__ARMCC_VERSION)
#include <sys/types.h>
#endif
#include <wmtypes.h>
#include <ctype.h>
#include "wifi_nxp_wps.h"
#include <lwip/sys.h>
#include <lwip/inet.h>
#include <wm_os.h>
#include "wps_msg.h"

#include "wps_mem.h"
#include "wps_def.h"
#include "wps_l2.h"
#include "wps_eapol.h"
#include "wps_os.h"
#include "wps_wlan.h"

#ifdef CONFIG_WPA2_ENTP
void wpa2_session_complete();
void wpa2_session_clean();
#endif

/********************************************************
        Local Variables
********************************************************/
WPS_LOOP_S wps_loop;
extern struct wps_thread_t wps;
extern u8 auto_go;
extern u8 p2p_scan_on;
/********************************************************
        Global Variables
********************************************************/
/** WPS global */
extern WPS_DATA wps_global;
/** IE buffer index */
extern short ie_index;
/** IE buffer index */
extern short ap_assocresp_ie_index;


/** Global pwps information */
extern PWPS_INFO gpwps_info;

/********************************************************
        Local Functions
********************************************************/
/**
 *  @brief Free structure used in main loop function
 *
 *  @return         None
 */
static void wps_main_loop_free(void)
{
    struct wps_timeout_s *timeout, *prev;

    ENTER();

    timeout = wps_loop.timeout;
    while (timeout != NULL)
    {
        prev    = timeout;
        timeout = timeout->next;
        wps_mem_free(prev);
    }
    wps_mem_free(wps_loop.readers);

    LEAVE();
}

/********************************************************
        Global Functions
********************************************************/

/**
 *  @brief Process main loop initialization
 *
 *  @param wps_s    A pointer to global WPS structure
 *  @return         WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_loop_init(WPS_DATA *wps_s)
{
    ENTER();

    /* clear data structure for main processing loop */
    (void)memset(&wps_loop, 0, sizeof(wps_loop));

    /* Initial and hook l2 callback function */
    wps_s->l2 = wps_l2_init(wps_s->ifname, ETH_P_EAPOL, wps_rx_eapol);

    if (wps_s->l2 == NULL)
    {
        wps_d("Init l2 return NULL !\n");
        LEAVE();
        return WPS_STATUS_FAIL;
    }

    if (wps_s->l2 && wps_l2_get_mac(wps_s->l2, wps_s->my_mac_addr))
    {
        wps_d("Failed to get own L2 address\n");
        LEAVE();
        return WPS_STATUS_FAIL;
    }

    wps_d("Own MAC address: " MACSTR, MAC2STR(wps_s->my_mac_addr));

    LEAVE();
    return WPS_STATUS_SUCCESS;
}

/**
 *  @brief Process interface deinit
 *
 *  @param wps_s        A pointer to global WPS structure
 *  @return             None
 */
void wps_intf_deinit(WPS_DATA *wps_s)
{
    ENTER();

    if (wps_s == NULL)
    {
        LEAVE();
        return;
    }

    wps_l2_deinit(wps_s->l2);

    LEAVE();
}

/**
 *  @brief Process main loop free
 *
 *  @param wps_s        A pointer to global WPS structure
 *  @return             None
 */
void wps_loop_deinit(WPS_DATA *wps_s)
{
    ENTER();

    if (wps_s == NULL)
    {
        LEAVE();
        return;
    }

    wps_main_loop_free();

    LEAVE();
}

/**
 *  @brief Disable main loop
 *
 *  @return         None
 */
void wps_main_loop_shutdown(void)
{
    ENTER();
    wps_loop.terminate = WPS_SET;
    LEAVE();
}

/**
 *  @brief Enable main loop
 *
 *  @return         None
 */
void wps_main_loop_enable(void)
{
    ENTER();
    wps_loop.terminate = WPS_CANCEL;
    LEAVE();
}

/**
 *  @brief Check main loop status
 *
 *  @return         true or false
 */
bool is_wps_main_loop_running(void)
{
    if (wps_loop.terminate == WPS_CANCEL)
        return true;
    else
        return false;
}

/**
 *  @brief Register a time-out handler to main loop timer function
 *
 *  @param secs             Time-out value in seconds
 *  @param usecs            Time-out value in micro-seconds
 *  @param handler          A function pointer of time-out handler
 *  @param callback_data    Private data for callback
 *  @return         WPS_STATUS_SUCCESS--success, otherwise--fail
 */
int wps_start_timer(unsigned int secs, unsigned int usecs, void (*handler)(void *user_data), void *callback_data)
{
    struct wps_timeout_s *timeout, *tmp, *prev;

    ENTER();

    timeout = (struct wps_timeout_s *)wps_mem_malloc(sizeof(*timeout));
    if (timeout == NULL)
        return WPS_STATUS_FAIL;

    timeout->time.tv_sec  = os_ticks_to_msec(os_ticks_get()) / 1000;
    timeout->time.tv_usec = (os_ticks_to_msec(os_ticks_get()) % 1000) * 1000;
    timeout->time.tv_sec += secs;
    timeout->time.tv_usec += usecs;
    while (timeout->time.tv_usec >= 1000000)
    {
        timeout->time.tv_sec++;
        timeout->time.tv_usec -= 1000000;
    }

    timeout->callback_data = callback_data;
    timeout->handler       = handler;
    timeout->next          = NULL;

    if (wps_loop.timeout == NULL)
    {
        wps_loop.timeout = timeout;
        LEAVE();
        return WPS_STATUS_SUCCESS;
    }

    prev = NULL;
    tmp  = wps_loop.timeout;
    while (tmp != NULL)
    {
        if (timer_cmp(&timeout->time, &tmp->time))
            break;
        prev = tmp;
        tmp  = tmp->next;
    }

    if (prev == NULL)
    {
        timeout->next    = wps_loop.timeout;
        wps_loop.timeout = timeout;
    }
    else
    {
        timeout->next = prev->next;
        prev->next    = timeout;
    }

    LEAVE();
    return WPS_STATUS_SUCCESS;
}

/**
 *  @brief Cancel time-out handler to main loop timer function
 *
 *  @param handler          Time-out handler to be canceled
 *  @param callback_data    Private data for callback
 *  @return         Number of timer being removed
 */
int wps_cancel_timer(void (*handler)(void *timeout_ctx), void *callback_data)
{
    struct wps_timeout_s *timeout, *prev, *next;
    int removed = 0;

    ENTER();

    prev    = NULL;
    timeout = wps_loop.timeout;
    while (timeout != NULL)
    {
        next = timeout->next;

        if ((timeout->handler == handler) && (timeout->callback_data == callback_data))
        {
            if (prev == NULL)
                wps_loop.timeout = next;
            else
                prev->next = next;
            wps_mem_free(timeout);
            removed++;
        }
        else
            prev = timeout;

        timeout = next;
    }

    LEAVE();
    return removed;
}

/**
 *  @brief Main loop procedure for socket read and timer functions
 *
 *  @return             None
 */
void wps_main_loop_proc(void)
{
    struct timeval tv, now;
    struct wps_msg msg;
    int ret;

    ENTER();

    while (!wps_loop.terminate)
    {
        /* Issue was observed with TX timer handler where
         * wps_txTimer_handler() was calling retransmit_last_tx_pkt()
         * and staring timer again indefinitely. So we have disabled
         * timer processing for wpa2_ent.
         */
        if (gpwps_info->prov_session == PROV_WPS_SESSION_ATTEMPT)
        {
            if (wps_loop.timeout)
            {
                now.tv_sec  = os_ticks_to_msec(os_ticks_get()) / 1000;
                now.tv_usec = (os_ticks_to_msec(os_ticks_get()) % 1000) * 1000;

                if (timer_cmp(&now, &wps_loop.timeout->time))
                    timersub(&wps_loop.timeout->time, &now, &tv);
                else
                    tv.tv_sec = tv.tv_usec = 0;
            }

            /* check if some registered timeouts have occurred */
            if (wps_loop.timeout)
            {
                struct wps_timeout_s *tmp;

                now.tv_sec  = os_ticks_to_msec(os_ticks_get()) / 1000;
                now.tv_usec = (os_ticks_to_msec(os_ticks_get()) % 1000) * 1000;

                if (!timer_cmp(&now, &wps_loop.timeout->time))
                {
                    tmp              = wps_loop.timeout;
                    wps_loop.timeout = wps_loop.timeout->next;
                    tmp->handler(tmp->callback_data);
                    wps_mem_free(tmp);
                }
            }
        }

        ret = os_queue_recv(
            &wps.data_queue, &msg,
            (gpwps_info->prov_session == PROV_WPS_SESSION_ATTEMPT) ? os_msec_to_ticks(50) : os_msec_to_ticks(500));
        if (ret == WM_SUCCESS)
        {
            if ((gpwps_info->wps_session) || (gpwps_info->prov_session == PROV_ENTP_SESSION_ATTEMPT))
            {
                if ((msg.new_msg_type > gpwps_info->last_recv_wps_msg) ||
                    ((gpwps_info->prov_session == PROV_WPS_SESSION_ATTEMPT) &&
                     (msg.new_msg_type < gpwps_info->eap_msg_sent)) ||
                    ((gpwps_info->prov_session == PROV_ENTP_SESSION_ATTEMPT) && (msg.new_msg_type == WPS_EAP_TLS_MSG)))
                {
                    wps_l2_receive(msg.mac, msg.buffer, msg.len);
                }
                else
                {
                    wps_d(
                        "msg.new_msg_type:%d\r\n"
                        "gpwps_info->last_recv_wps_msg:%d\r\n",
                        msg.new_msg_type, gpwps_info->last_recv_wps_msg);
                }
            }
            wps_mem_free(msg.buffer);
        }
    }
#ifdef CONFIG_WPA2_ENTP
    if (gpwps_info->prov_session == PROV_ENTP_SESSION_ATTEMPT)
    {
        wpa2_session_complete();
        wpa2_session_clean();
    }
#endif
    /*Drain queue.*/
    while (os_queue_get_msgs_waiting(&wps.data_queue))
    {
        (void)memset(&msg, 0, sizeof(struct wps_msg));
        ret = os_queue_recv(&wps.data_queue, &msg, os_msec_to_ticks(0));
        if (ret == WM_SUCCESS)
        {
            if (msg.buffer)
                wps_mem_free(msg.buffer);
        }
    }

    LEAVE();
}
